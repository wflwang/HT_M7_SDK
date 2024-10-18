/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
 
/*
 * 
 * \file eqep_ex2_pos_speed.c
 * 
 * 
 * \brief Position and Speed Measurement Using eQEP
 * 
 *  This example provides position and speed measurement using the
 *  capture unit and speed measurement using unit time out of the eQEP module.
 *  ePWM1 and a GPIO are configured to generate simulated eQEP signals. The
 *  ePWM module will interrupt once every period and call the position/speed
 *  calculation function. This example uses the IQMath library to simplify
 *  high-precision calculations.
 * 
 *  In addition to the main example file, the following files must be included
 *  in this project:
 *  - \b eqep_ex2_calculation.c - contains position/speed calculation function
 *  - \b eqep_ex2_calculation.h - includes initialization values for
 *                                position/speed structure
 * 
 *  The configuration for this example is as follows
 *  - Maximum speed is configured to 6000rpm (baseRPM)
 *  - Minimum speed is assumed at 10rpm for capture pre-scalar selection
 *  - Pole pair is configured to 2 (polePairs)
 *  - Encoder resolution is configured to 4000 counts/revolution (mechScaler)
 *  - Which means: 4000 / 4 = 1000 line/revolution quadrature encoder
 *    (simulated by ePWM1)
 *  - ePWM1 (simulating QEP encoder signals) is configured for a 5kHz frequency
 *    or 300 rpm (= 4 * 5000 cnts/sec * 60 sec/min) / 4000 cnts/rev)
 * 
 *  \b SPEEDRPM_FR: High Speed Measurement is obtained by counting the QEP
 *  input pulses for 10ms (unit timer set to 100Hz).
 * 
 *  \b SPEEDRPM_FR = (Position Delta / 10ms) * 60 rpm
 * 
 *  \b SPEEDRPM_PR: Low Speed Measurement is obtained by measuring time period
 *  of QEP edges. Time measurement is averaged over 64 edges for better results
 *  and the capture unit performs the time measurement using pre-scaled SYSCLK.
 * 
 *  Note that the pre-scaler for capture unit clock is selected such that the
 *  capture timer does not overflow at the required minimum frequency. This
 *  example runs indefinitely until the user stops it.
 * 
 *  For more information about the position/speed calculation see the comments
 *  at the beginning of eqep_ex2_calculation.c and the XLS file provided with
 *  the project, eqep_ex2_calculation.xls.
 * 
 *  \b External \b Connections \n
 *  - Connect GPIO20/eQEP1A to GPIO0/ePWM1A (simulates eQEP Phase A signal)
 *  - Connect GPIO21/eQEP1B to GPIO1/ePWM1B (simulates eQEP Phase B signal)
 *  - Connect GPIO23/eQEP1I to GPIO2 (simulates eQEP Index Signal)
 * 
 *  \b Watch \b Variables \n
 *   - \b posSpeed.speedRPMFR - Speed meas. in rpm using QEP position counter
 *   - \b posSpeed.speedRPMPR - Speed meas. in rpm using capture unit
 *   - \b posSpeed.thetaMech  - Motor mechanical angle (Q15)
 *   - \b posSpeed.thetaElec  - Motor electrical angle (Q15)
 * 
 * 
 */



/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "board.h"
#include "hte_gpio.h"
#include "hte_pinmux.h"
#include "hte_epwm.h"
#include "hte_eqep.h"
#include "hte_sysctrl.h"
#include "eqep_ex2_calculation.h"

#ifdef HTE_DEVICE_HS32F7D377_CPU1
#include "hte_cpu1_ipc_com.h"
#else
#include "hte_cpu2_ipc_com.h"
#endif



/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define TB_CLK    PLL_CLKOUT                /* Time base clock is PLL_CLKOUT */
#define PWM_CLK   5000                      /* We want to output at 5 kHz */
                                            /* (300 rpm) */
#define PRD_VAL   (TB_CLK / (PWM_CLK * 2))  /* Calculate value period value */
                                            /* for up-down count mode */

/* .9999 / 4000 converted to IQ26 fixed point format */
#define MECH_SCALER     16776
/* 2 pole pairs in this example */
#define POLE_PAIRS      2
/* Angular offset between encoder and Phase A */
#define CAL_ANGLE       0
/* See Equation 5 in eqep_ex2_calculation.c */
#define SPEED_SCALER    ((((uint64_t)32 * PLL_CLKOUT / 64) * 60) / (24000000))
/* Base/max rpm is 6000rpm */
#define BASE_RPM        6000


/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void initEQEP(void);
void initEPWM(void);
void epwm1Pinmux(void);
void eqep1Pinmux(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/
PosSpeed_Object posSpeed =
{
    0, 0, 0, 0,     /* Initialize outputs to zero */
    MECH_SCALER,    /* mechScaler */
    POLE_PAIRS,     /* polePairs */
    CAL_ANGLE,      /* calAngle */
    SPEED_SCALER,   /* speedScaler */
    0,              /* Initialize output to zero */
    BASE_RPM,       /* baseRPM */
    0, 0, 0, 0      /* Initialize outputs to zero */
};

uint16_t interruptCount = 0;
uint32_t count =0;  /* counter to check measurement gets saturated */
uint32_t pass=0, fail =0; /* Pass or fail indicator */

/*******************************************************************************
 * Codes
 ******************************************************************************/
void main(void)
{
    BOARD_init();

#ifdef HTE_DEVICE_HS32F7D377_CPU1
    IPC_comInit();
#endif

    /* GPIO0: EPWM1A, GPIO1: EPWM1B */
    epwm1Pinmux();
    
    /* GPIO20: EQEP1_A, GPIO21: EQEP1_B, GPIO22: EQEP1_STROBE, GPIO23: EQEP1_INDEX */    
    eqep1Pinmux();

    /* Disable the ePWM TBCLK peripheral */
    SYSCTRL_disablePeripheral(kSYSCTL_PERIPH_CLK_TBCLKSYNC);
    
    /* Infinite the eQEP configuration */
    initEQEP();

    /* Infinite the ePWM configuration */
    initEPWM();    

    /* Set interrupt priority and enable the interrupt */
    NVIC_SetPriority(EPWM1_IRQn, 5);
    NVIC_EnableIRQ(EPWM1_IRQn);

    /* Enable the ePWM TBCLK peripheral */
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_TBCLKSYNC); 

    /* Loop indefinitely */
    while(1)
    {
        DELAY(1000000);
        PRINTF("pass %ld  fail %ld \r\n", pass, fail);
    }
}



void initEQEP(void)
{
 	/* myEQEP0 initialization */
	EQEP_SourceSelect_t source_myEQEP1 =
	{
		kEQEP_SOURCE_DEVICE_PIN, 		/* eQEPA source */
		kEQEP_SOURCE_DEVICE_PIN,		/* eQEPB source */
		kEQEP_SOURCE_DEVICE_PIN,  	    /* eQEP Index source  */
	};
 
#ifndef HTE_DEVICE_HS32F7D377_CPU1    
    IPC_com_selectCPUForPeripheral((IPC_SYSCTRL_PeripheralCpusel_t)(kIPC_SYSCTRL_PERIPH_CPUSEL_EQEP1 ),kIPC_SYSCTRL_CPUSEL_CPU2);
#endif
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_EQEP1); 
    
	/* Selects the source for eQEPA/B/I signals */
	EQEP_selectSource(EQEP1, source_myEQEP1);
	/* Set the strobe input source of the eQEP module. */
	EQEP_setStrobeSource(EQEP1,kEQEP_STROBE_FROM_GPIO);
	/* Sets the polarity of the eQEP module's input signals. */
	EQEP_setInputPolarity(EQEP1,false,false,false,false);
	/* Configures eQEP module's quadrature decoder unit. */
	EQEP_setDecoderConfig(EQEP1, (EQEP_CONFIG_QUADRATURE | EQEP_CONFIG_1X_RESOLUTION | EQEP_CONFIG_NO_SWAP | EQEP_CONFIG_IGATE_DISABLE));
	/* Set the emulation mode of the eQEP module. */
	EQEP_setEmulationMode(EQEP1,kEQEP_EMULATIONMODE_RUNFREE);
	/* Configures eQEP module position counter unit. */
	EQEP_setPositionCounterConfig(EQEP1,kEQEP_POSITION_RESET_IDX,4294967295U);
	/* Sets the current encoder position. */
	EQEP_setPosition(EQEP1,0U);
	/* Enables the eQEP module unit timer. */
	EQEP_enableUnitTimer(EQEP1,3000000U);
	/* Disables the eQEP module watchdog timer. */
	EQEP_disableWatchdog(EQEP1);
	/* Configures the quadrature modes in which the position count can be latched. */
	EQEP_setLatchMode(EQEP1,(EQEP_LATCH_UNIT_TIME_OUT|EQEP_LATCH_RISING_STROBE|EQEP_LATCH_RISING_INDEX));
	/* Set the quadrature mode adapter (QMA) module mode. */
	EQEP_setQMAModuleMode(EQEP1,kEQEP_QMA_MODE_BYPASS);
	/* Disable Direction Change During Index */
	EQEP_disableDirectionChangeDuringIndex(EQEP1);
	/* Configures the mode in which the position counter is initialized. */
	EQEP_setPositionInitMode(EQEP1,(EQEP_INIT_DO_NOTHING));
	/* Sets the software initialization of the encoder position counter. */
	EQEP_setSWPositionInit(EQEP1,true);
	/* Sets the init value for the encoder position counter. */
	EQEP_setInitialPosition(EQEP1,0U);
	/* Enables the eQEP module. */
	EQEP_enableModule(EQEP1);
	/* Configures eQEP module edge-capture unit. */
	EQEP_setCaptureConfig(EQEP1,kEQEP_CAPTURE_CLK_DIV_64,kEQEP_UNIT_POS_EVNT_DIV_32);
	/* Enables the eQEP module edge-capture unit. */
	EQEP_enableCapture(EQEP1);   
}




/* Function to configure ePWM1 to generate a 5 kHz signal. */
void initEPWM(void)
{
    #ifndef HTE_DEVICE_HS32F7D377_CPU1 
    IPC_com_selectCPUForPeripheral((IPC_SYSCTRL_PeripheralCpusel_t)(kIPC_SYSCTRL_PERIPH_CPUSEL_EPWM1 ),kIPC_SYSCTRL_CPUSEL_CPU2);
    #endif
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_EPWM1);    
    
    /* Set phase shift to 0 and clear the time base counter */
    EPWM_setPhaseShift(EPWM1, 0);
    EPWM_setTimeBaseCounter(EPWM1, 0);

    /* Disable the shadow load; the load will be immediate instead */
    EPWM_disableCounterCompareShadowLoadMode(EPWM1,
                                             EPWM_COUNTER_COMPARE_A);
    EPWM_disableCounterCompareShadowLoadMode(EPWM1,
                                             EPWM_COUNTER_COMPARE_B);

    /* Set the compare A value to half the period value, compare B to 0 */
    EPWM_setCounterCompareValue(EPWM1, EPWM_COUNTER_COMPARE_A, PRD_VAL/2);
    EPWM_setCounterCompareValue(EPWM1, EPWM_COUNTER_COMPARE_B, 0);

    /*
     * Set action qualifier behavior on compare A events
     * - EPWM1A --> 1 when CTR = CMPA and increasing
     * - EPWM1A --> 0 when CTR = CMPA and decreasing
     */
    EPWM_setActionQualifierAction(EPWM1, EPWM_AQ_OUTPUT_A,
                                  EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    EPWM_setActionQualifierAction(EPWM1, EPWM_AQ_OUTPUT_A,
                                  EPWM_AQ_OUTPUT_LOW,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);

    /*
     * Set action qualifier behavior on compare B events
     * - EPWM1B --> 1 when CTR = PRD and increasing
     * - EPWM1B --> 0 when CTR = 0 and decreasing
     */
    EPWM_setActionQualifierAction(EPWM1, EPWM_AQ_OUTPUT_B,
                                  EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);
    EPWM_setActionQualifierAction(EPWM1, EPWM_AQ_OUTPUT_B,
                                  EPWM_AQ_OUTPUT_LOW,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);

    /* Enable interrupt when the counter is equal to PRD */
    EPWM_setInterruptSource(EPWM1, EPWM_INT_TBCTR_PERIOD);
    EPWM_enableInterrupt(EPWM1);

    /* Interrupt on first event */
    EPWM_setInterruptEventCount(EPWM1, 1);

    /* Set the time base clock prescaler to /1 */
    EPWM_setClockPrescaler(EPWM1, EPWM_CLOCK_DIVIDER_1,
                           EPWM_HSCLOCK_DIVIDER_1);

    /* Set the period value; don't shadow the register */
    EPWM_setPeriodLoadMode(EPWM1, EPWM_PERIOD_DIRECT_LOAD);
    EPWM_setTimeBasePeriod(EPWM1, PRD_VAL);

    /* Put the time base counter into up-down count mode */
    EPWM_setTimeBaseCounterMode(EPWM1, EPWM_COUNTER_MODE_UP_DOWN);


}



void eqep1Pinmux(void)
{
#ifdef HTE_DEVICE_HS32F7D377_CPU1
    GPIO_setPinConfig(GPIO_20_EQEP1_A);
    GPIO_setPadConfig(20U, kGPIO_PADCONFIG_STD);
    GPIO_setQualificationMode(20U, kGPIO_QUAL_SYNC);
    GPIO_setPinConfig(GPIO_21_EQEP1_B);
    GPIO_setPadConfig(21U, kGPIO_PADCONFIG_STD);
    GPIO_setQualificationMode(21U, kGPIO_QUAL_SYNC);
    GPIO_setPinConfig(GPIO_22_EQEP1_STROBE);
    GPIO_setPadConfig(22U, kGPIO_PADCONFIG_STD);
    GPIO_setQualificationMode(22U, kGPIO_QUAL_SYNC);
    GPIO_setPinConfig(GPIO_23_EQEP1_INDEX);
    GPIO_setPadConfig(23U, kGPIO_PADCONFIG_STD);
    GPIO_setQualificationMode(23U, kGPIO_QUAL_SYNC);
    
    GPIO_setPinConfig(GPIO_2_GPIO2);
    GPIO_setDirectionMode(2, kGPIO_DIR_OUTPUT);
	GPIO_setPadConfig(2, kGPIO_PADCONFIG_STD);
	GPIO_setQualificationMode(2, kGPIO_QUAL_SYNC);
	GPIO_writePin(2, 0);
    
#else
    IPC_com_GPIO_setPinConfig(GPIO_20_EQEP1_A);
    IPC_com_GPIO_setPadConfig(20U, kGPIO_PADCONFIG_STD);
    IPC_com_GPIO_setQualificationMode(20U, kGPIO_QUAL_SYNC);
    IPC_com_GPIO_setPinConfig(GPIO_21_EQEP1_B);
    IPC_com_GPIO_setPadConfig(21U, kGPIO_PADCONFIG_STD);
    IPC_com_GPIO_setQualificationMode(21U, kGPIO_QUAL_SYNC);
    IPC_com_GPIO_setPinConfig(GPIO_22_EQEP1_STROBE);
    IPC_com_GPIO_setPadConfig(22U, kGPIO_PADCONFIG_STD);
    IPC_com_GPIO_setQualificationMode(22U, kGPIO_QUAL_SYNC);
    IPC_com_GPIO_setPinConfig(GPIO_23_EQEP1_INDEX);
    IPC_com_GPIO_setPadConfig(23U, kGPIO_PADCONFIG_STD);
    IPC_com_GPIO_setQualificationMode(23U, kGPIO_QUAL_SYNC);
    IPC_com_GPIO_setPinConfig(GPIO_2_GPIO2);
      
    IPC_com_GPIO_setMasterCore(20, kGPIO_CORE_CPU2);
    IPC_com_GPIO_setMasterCore(21, kGPIO_CORE_CPU2); 
    IPC_com_GPIO_setMasterCore(22, kGPIO_CORE_CPU2);
    IPC_com_GPIO_setMasterCore(23, kGPIO_CORE_CPU2); 
    IPC_com_GPIO_setMasterCore(2, kGPIO_CORE_CPU2); 
#endif
}


void epwm1Pinmux(void)
{
    #ifdef HTE_DEVICE_HS32F7D377_CPU1
    GPIO_setPinConfig(GPIO_0_EPWM1_A);
    GPIO_setPadConfig(0U, kGPIO_PADCONFIG_STD);
    GPIO_setQualificationMode(0U, kGPIO_QUAL_ASYNC);
    GPIO_setPinConfig(GPIO_1_EPWM1_B);
    GPIO_setPadConfig(1U, kGPIO_PADCONFIG_STD);
    GPIO_setQualificationMode(1U, kGPIO_QUAL_ASYNC);
    #else
    IPC_com_GPIO_setPinConfig(GPIO_0_EPWM1_A);
    IPC_com_GPIO_setPadConfig(0U, kGPIO_PADCONFIG_STD);
    IPC_com_GPIO_setQualificationMode(0U, kGPIO_QUAL_ASYNC);
    IPC_com_GPIO_setPinConfig(GPIO_1_EPWM1_B);
    IPC_com_GPIO_setPadConfig(1U, kGPIO_PADCONFIG_STD);
    IPC_com_GPIO_setQualificationMode(1U, kGPIO_QUAL_ASYNC);
    
    IPC_com_GPIO_setMasterCore(0, kGPIO_CORE_CPU2);
    IPC_com_GPIO_setMasterCore(1, kGPIO_CORE_CPU2); 
    #endif
}






/* ePWM1 ISR- interrupts once per ePWM period */
void EPWM1_Handler(void)
{
    uint16_t i;

    /* Position speed and measurement */
    PosSpeed_calculate(&posSpeed, &count);

    /*
     * Comparing the eQEP measured frequency with the ePWM frequency
     * After count becomes 3 , eQEP measurement gets saturated and if
     * measure speed is 5 more or less than input speed then pass = 1
     */
    if (count >= 2){
        if (((posSpeed.speedRPMFR - 300) < 5) &&
             ((posSpeed.speedRPMFR - 300) > -5))
        {
            pass = 1; fail = 0;
        }
        else {
            fail = 1; pass = 0;
        }
       }

    /* Control loop for position control and speed control */
    interruptCount++;
    if(interruptCount == 1000)
    {
        /* Pulse index signal (1 pulse/rev) */
        GPIO_writePin(2, 1);
        for(i = 0; i < 700; i++)
        {
            ;
        }
        GPIO_writePin(2, 0);
    }
    
    /* Clear interrupt flag and issue ACK */
    EPWM_clearEventTriggerInterruptFlag(EPWM1);
    ISR_EXIT_BARRIER();
}
