/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*
 *
 * \file eqep_ex3_test_epwm_xbar.c
 *
 * \brief ePWM frequency Measurement Using eQEP via xbar connection
 *
 * This example will calculate the frequency of an PWM signal using the eQEP
 * module.  ePWM1A is configured to generate this input signal with a
 * frequency of 5 kHz. This ePWM signal is connected to input of eQEP using
 * Input CrossBar and EPWM XBAR. ePWM module will interrupt once every period
 * and call the frequency calculation function. This example uses the IQMath
 * library to simplify high-precision calculations.
 *
 * In addition to the main example file, the following files must be included
 * in this project:
 * - \b eqep_ex3_calculation.c - contains frequency calculation function
 * - \b eqep_ex3_calculation.h - includes initialization values for frequency
 *                               structure
 *
 * The configuration for this example is as follows
 * - Maximum frequency is configured to 10KHz (baseFreq)
 * - Minimum frequency is assumed at 50Hz for capture pre-scalar selection
 * - GPIO0 is connected to output of INPUT_XBAR1
 * - INPUT_XBAR1 is connected to  output of PWMXBAR at TRIP4
 * - eQEPA source is configured as PWMXBAR.1 output (TRIP4)
 *
 * \b SPEED_FR: High Frequency Measurement is obtained by counting the
 * external input pulses for 10ms (unit timer set to 100Hz).
 * \f[ SPEED\_FR = \frac{Count\ Delta}{10ms} \f]
 *
 * \b SPEED_PR: Low Frequency Measurement is obtained by measuring time
 * period of input edges. Time measurement is averaged over 64 edges for
 * better results and the capture unit performs the time measurement using
 * pre-scaled SYSCLK.
 *
 * Note that the pre-scaler for capture unit clock is selected such that the
 * capture timer does not overflow at the required minimum frequency. This
 * example runs indefinitely until the user stops it.
 *
 * \b Watch \b Variables \n
 * - \b freq.freqHzFR - Frequency measurement using position counter/unit
 *   time out
 * - \b freq.freqHzPR - Frequency measurement using capture unit
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
#include "hte_xbar.h"
#include "hte_xbarmux.h"
#include "hte_sysctrl.h"
#include "eqep_ex3_calculation.h"

#ifdef HTE_DEVICE_HS32F7D377_CPU1
#include "hte_cpu1_ipc_com.h"
#else
#include "hte_cpu2_ipc_com.h"
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define TB_CLK    PLL_CLKOUT       /* Time base clock is SYSCLK/2 */
#define PWM_CLK   5000                      /* We want to output at 5 kHz */
#define PRD_VAL   (TB_CLK / (PWM_CLK * 2))  /* Calculate value period value */
                                            /* for up-down count mode */
#define BASE_FREQ       10000  /* Base/max frequency is 10 kHz */
/* See Equation 5 in eqep_ex1_calculation.c */
#define FREQ_SCALER_PR  (((PLL_CLKOUT / 128) * 8) / (2 * BASE_FREQ))
/* See Equation 2 in eqep_ex1_calculation.c */
#define FREQ_SCALER_FR  ((BASE_FREQ * 2) / 100)


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
FreqCal_Object freq =
{
    FREQ_SCALER_PR,  /* freqScalerPR */
    FREQ_SCALER_FR,  /* freqScalerFR */
    BASE_FREQ,       /* baseFreq */
    0, 0, 0, 0, 0    /* Initialize outputs to zero */
};
EQEP_SourceSelect_t source1 =
{
 kEQEP_SOURCE_EPWMXBAR1, /* eQEPA as PWMXBAR1 */
 kEQEP_SOURCE_DEVICE_PIN, /* eQEPB as device pin */
 kEQEP_SOURCE_DEVICE_PIN  /* eQEP Index as device pin */
};
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

    /* Infinite the eQEP configuration */
    initEQEP();

    /*
     * Configures ePWM1A output (GPIO0) as input to ePWM XBAR using ZInput XBAR
     * And then routs this signal to PWMXBAR.1
     */
#ifdef HTE_DEVICE_HS32F7D377_CPU1
    XBAR_enableEPWMMux(EPWM_XBAR,kXBAR_TRIP5, kXBAR_MUX01);
    XBAR_setInputPin(INPUT_XBAR, kXBAR_INPUT1, 0);
    XBAR_setEPWMMuxConfig(EPWM_XBAR,kXBAR_TRIP5, XBAR_EPWM_MUX01_INPUTXBAR1);
#endif

    /* Disable the ePWM TBCLK peripheral */
    SYSCTRL_disablePeripheral(kSYSCTL_PERIPH_CLK_TBCLKSYNC);
    
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
 	//myEQEP1 initialization */
	    
	EQEP_SourceSelect_t source_myEQEP1 =
	{
		kEQEP_SOURCE_EPWMXBAR1, 		/* eQEPA source */
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
	EQEP_setDecoderConfig(EQEP1, (EQEP_CONFIG_UP_COUNT | EQEP_CONFIG_2X_RESOLUTION | EQEP_CONFIG_NO_SWAP | EQEP_CONFIG_IGATE_DISABLE));
	/* Set the emulation mode of the eQEP module. */
	EQEP_setEmulationMode(EQEP1,kEQEP_EMULATIONMODE_STOPIMMEDIATELY);
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
	EQEP_setCaptureConfig(EQEP1,kEQEP_CAPTURE_CLK_DIV_128,kEQEP_UNIT_POS_EVNT_DIV_8);
	/* Enables the eQEP module edge-capture unit. */
	EQEP_enableCapture(EQEP1);
}

/* initEPWM - Function to configure ePWM1 to generate a 5 kHz signal. */
void
initEPWM(void)
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
    //  EPWM_setCounterCompareValue(EPWM1, EPWM_COUNTER_COMPARE_B, 0);

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

    /* Configure EPWM1B to be complementary to EPWM1A */
    EPWM_setDeadBandDelayPolarity(EPWM1, EPWM_DB_FED,
                                  EPWM_DB_POLARITY_ACTIVE_LOW);
    EPWM_setDeadBandDelayMode(EPWM1, EPWM_DB_FED, true);
    EPWM_setDeadBandDelayMode(EPWM1, EPWM_DB_RED, true);

    /* Enable interrupt when the counter is equal to 0 */
    EPWM_setInterruptSource(EPWM1, EPWM_INT_TBCTR_ZERO);
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

      
    IPC_com_GPIO_setMasterCore(20, kGPIO_CORE_CPU2);
    IPC_com_GPIO_setMasterCore(21, kGPIO_CORE_CPU2); 
    IPC_com_GPIO_setMasterCore(22, kGPIO_CORE_CPU2);
    IPC_com_GPIO_setMasterCore(23, kGPIO_CORE_CPU2); 

#endif
}


void epwm1Pinmux(void)
{
    #ifdef HTE_DEVICE_HS32F7D377_CPU1
    GPIO_setPinConfig(GPIO_0_EPWM1_A);
    GPIO_setPadConfig(0U, kGPIO_PADCONFIG_STD);
    GPIO_setQualificationMode(0U, kGPIO_QUAL_ASYNC);
    #else
    IPC_com_GPIO_setPinConfig(GPIO_0_EPWM1_A);
    IPC_com_GPIO_setPadConfig(0U, kGPIO_PADCONFIG_STD);
    IPC_com_GPIO_setQualificationMode(0U, kGPIO_QUAL_ASYNC);

    IPC_com_GPIO_setMasterCore(0, kGPIO_CORE_CPU2); 
    #endif
}




/* ePWM1 ISR- interrupts once per ePWM period */
void EPWM1_Handler(void)
{
    /* Checks for events and calculates frequency. */
    FreqCal_calculate(&freq, &count);

    /*
     * Comparing the eQEP measured frequency with the ePWM frequency
     * After count becomes 3 , eQEP measurement gets saturated and
     * classifying pass = 1 if measured frequency is 50 more or
     * less than input
     */
    if (count >= 3){
        if (((freq.freqHzFR - PWM_CLK) < 50) && ((freq.freqHzFR - PWM_CLK) > -50)){
            pass = 1; fail = 0;
          }
        else {
            fail = 1; pass = 0;
          }
    }

    /* Clear interrupt flag and issue ACK */
    EPWM_clearEventTriggerInterruptFlag(EPWM1);
    ISR_EXIT_BARRIER();
}

/*
 * End of File
 */

