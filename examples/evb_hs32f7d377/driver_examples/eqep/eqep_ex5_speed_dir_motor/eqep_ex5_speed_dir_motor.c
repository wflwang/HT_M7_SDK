/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*
 *
 * \file eqep_ex5_speed_dir_motor.c
 *
 * \brief Motor encoder speed and direction measurement using eQEP
 *        via unit timeout interrupt
 *
 * This example can be used to sense the speed and direction of motor
 * using eQEP in quadrature encoder mode. ePWM1A is configured to simulate
 * motor encoder signals with frequency of 5 kHz on both A and B pins with 90
 * degree phase shift (so as to run this example without motor).
 * EQEP unit timeout is set which will generate an interrupt every
 *  \b UNIT_PERIOD microseconds and speed calculation occurs continuously
 *  based on the direction of motor
 *
 * The configuration for this example is as follows
 * - PWM frequency is specified as 5000Hz
 * - UNIT_PERIOD is specified as 10000 us
 * - Simulated quadrature signal frequency is 20000Hz (4 * 5000)
 * - Encoder holes assumed as 1000
 * - Thus Simulated motor speed is 300rpm (5000 * (60 / 1000))
 *
 * \b freq : Simulated quadrature signal frequency measured by counting
 * the external input pulses for UNIT_PERIOD (unit timer set to 10 ms).
 * \b speed : Measure motor speed in rpm
 * \b dir : Indicates clockwise (1) or anticlockwise (-1)
 *
 * \b External \b Connections (if motor encoder signals are simulated
 * by ePWM) \n
 * - Connect GPIO20/eQEP1A to GPIO0/ePWM1A
 * - Connect GPIO21/eQEP1B to GPIO1/ePWM1B
 * With motor \n
 * - Comment in "MOTOR" in includes
 * - Connect GPIO20/eQEP1A to encoder A output
 * - Connect GPIO21/eQEP1B to encoder B output
 *
 * \b Watch \b Variables \n
 * - \b freq : Simulated motor frequency measurement is obtained by counting
 * the external input pulses for UNIT_PERIOD (unit timer set to 10 ms).
 * - \b speed : Measure motor speed in rpm
 * - \b dir : Indicates clockwise (1) or anticlockwise (-1)
 * - \b pass - If measured qudrature frequency matches with i.e. input
 *             quadrature frequency (4 * PWM frequency) then pass = 1
 *             else fail = 1 (** only when "MOTOR" is commented out)
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

#ifdef HTE_DEVICE_HS32F7D377_CPU1
#include "hte_cpu1_ipc_com.h"
#else
#include "hte_cpu2_ipc_com.h"
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define TB_CLK    PLL_CLKOUT               /* Time base clock is PLL_CLKOUT */
#define PWM_CLK   5000                     /* We want to output at 5 kHz */
#define PRD_VAL   (TB_CLK / (PWM_CLK * 2))  /* Calculate value period value */
                                           /* for up-down count mode */
#define UNIT_PERIOD  10000U /* Specify the period in microseconds */
/* Uncomment if motor is available for interfacing */
//#define MOTOR

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void initEQEP(void);
void initEPWM(void);
void epwm1Pinmux(void);
void eqep1Pinmux(void);
void INT_myEQEP1_ISR(EQEP_REGS_Type *base);

/*******************************************************************************
 * Variables
 ******************************************************************************/
uint32_t oldcount = 0;  /* stores the previous position counter value */
int32_t freq = 0;   /* measured quadrature signal frequency of motor using eQEP */
float speed = 0.0f;       /* measured speed of motor in rpm */
int32_t dir = 0;       /* direction of rotation of motor */
uint32_t count = 0;     /* just to make sure measured frequency gets saturated */
uint32_t pass = 0, fail = 0; /* test pass or fail indicator */

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

   EQEP_registerCallback(EQEP1 , INT_myEQEP1_ISR, 5); 
    
    
#ifndef MOTOR

    /* Disable the ePWM TBCLK peripheral */
    SYSCTRL_disablePeripheral(kSYSCTL_PERIPH_CLK_TBCLKSYNC);
    
    /* Setup ePWM1 to generate a 5 kHz signal to be an input to the eQEP */
    initEPWM();    

    /* Enable the ePWM TBCLK peripheral */
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_TBCLKSYNC); 

#endif



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
#ifndef HTE_DEVICE_HS32F7D377_CPU1    
    IPC_com_selectCPUForPeripheral((IPC_SYSCTRL_PeripheralCpusel_t)(kIPC_SYSCTRL_PERIPH_CPUSEL_EQEP1 ),kIPC_SYSCTRL_CPUSEL_CPU2);
#endif
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_EQEP1); 
    
	/* Disable, clear all flags and interrupts */
	EQEP_disableInterrupt(EQEP1,
		(EQEP_INT_GLOBAL     		|   
		EQEP_INT_POS_CNT_ERROR		|      
		EQEP_INT_PHASE_ERROR    	| 
		EQEP_INT_DIR_CHANGE    		| 
		EQEP_INT_WATCHDOG          	|   
		EQEP_INT_UNDERFLOW         	|
		EQEP_INT_OVERFLOW        	|
		EQEP_INT_POS_COMP_READY    	|	
		EQEP_INT_POS_COMP_MATCH   	|
		EQEP_INT_STROBE_EVNT_LATCH	| 
		EQEP_INT_INDEX_EVNT_LATCH 	|
		EQEP_INT_UNIT_TIME_OUT   	|
		EQEP_INT_QMA_ERROR));
	EQEP_clearInterruptStatus(EQEP1,
		(EQEP_INT_GLOBAL     		|   
		EQEP_INT_POS_CNT_ERROR		|      
		EQEP_INT_PHASE_ERROR    	| 
		EQEP_INT_DIR_CHANGE    		| 
		EQEP_INT_WATCHDOG          	|   
		EQEP_INT_UNDERFLOW         	|
		EQEP_INT_OVERFLOW        	|
		EQEP_INT_POS_COMP_READY    	|	
		EQEP_INT_POS_COMP_MATCH   	|
		EQEP_INT_STROBE_EVNT_LATCH	| 
		EQEP_INT_INDEX_EVNT_LATCH 	|
		EQEP_INT_UNIT_TIME_OUT   	|
		EQEP_INT_QMA_ERROR));
	EQEP_SourceSelect_t source_myEQEP1 =
	{
		kEQEP_SOURCE_DEVICE_PIN, 		/* eQEPA source */
		kEQEP_SOURCE_DEVICE_PIN,		/* eQEPB source */
		kEQEP_SOURCE_DEVICE_PIN,  	    /* eQEP Index source  */
	};
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
	/* Enables individual eQEP module interrupt sources. */
	EQEP_enableInterrupt(EQEP1,(EQEP_INT_UNIT_TIME_OUT));
	/* Configures the mode in which the position counter is initialized. */
	EQEP_setPositionInitMode(EQEP1,(EQEP_INIT_DO_NOTHING));
	/* Sets the software initialization of the encoder position counter. */
	EQEP_setSWPositionInit(EQEP1,true);
	/* Sets the init value for the encoder position counter. */
	EQEP_setInitialPosition(EQEP1,0U);
	/* Enables the eQEP module. */
	EQEP_enableModule(EQEP1);
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




/* eqep1 ISR- interrupts once per ePWM period */
void INT_myEQEP1_ISR(EQEP_REGS_Type *base)
{
    uint32_t temp = 0, newcount = 0 ;
    
    count++; /* increment count value so to wait for frequency saturation */

    newcount = EQEP_getPositionLatch(EQEP1); /* new position counter value */
    temp = newcount;

   /* Gets direction of rotation of motor */
   dir = EQEP_getDirection(EQEP1);

   /*
    * Calculates the number of position in unit time based on
    * motor's direction of rotation
    */
   if (dir > 0 ){
       if (newcount >= oldcount)
            newcount = newcount - oldcount;
        else
            newcount = (0xFFFFFFFF - oldcount) + newcount;
        }
   else {
        if (newcount <= oldcount)
            newcount = oldcount - newcount;
        else
            newcount = (0xFFFFFFFF - newcount) + oldcount;
        }

   /* Stores the current position count value to oldcount variable */
   oldcount = temp;

   /* Simulated Frequency and speed calculation */
   freq = (newcount * (uint32_t)1000000U)/((uint32_t)UNIT_PERIOD);
   speed = (freq * 60)/4000.0f;

   /*
    * Compares the measured quadrature simulated frequency with input quadrature
    * frequency and if difference is within the measurement resolution
    * (1/10ms = 100Hz) then pass = 1 else fail = 1
    */
#ifndef MOTOR
   if (count >= 2){
        if (((freq - PWM_CLK * 4) < 100) && ((freq - PWM_CLK * 4) > -100)){
            pass = 1; fail = 0;
        }
        else {
            fail = 1; pass = 0;
        }
    }
#endif


   /* Clear interrupt flag and issue ACK */
   EQEP_clearInterruptStatus(EQEP1,EQEP_INT_UNIT_TIME_OUT|EQEP_INT_GLOBAL);
    ISR_EXIT_BARRIER();
 }

/*
 * End of File
 */

