/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*
 * 
 * \file sdfm_ex3_pwm_sync_cpuread.c
 * 
 * \brief SDFM PWM Sync Example
 * 
 *  In this example, SDFM filter data is read by CPU in SDFM ISR routine. The
 *  SDFM configuration is shown below:
 *      - SDFM1 is used in this example. For using SDFM2, few modifications
 *        would be needed in the example.
 *      - MODE0 Input control mode selected
 *      - Comparator settings
 *          - Sinc3 filter selected
 *          - OSR = 32
 *          - hlt = 0x7FFF (Higher threshold setting)
 *          - llt  = 0x0000(Lower threshold setting)
 *   -  Data filter settings
 *       - All the 4 filter modules enabled
 *       - Sinc3 filter selected
 *       - OSR = 256
 *       - All the 4 filters are synchronized by using PWM
 *        (Master Filter enable bit)
 *       - Filter output represented in 16 bit format
 *       - In order to convert 25 bit Data filter
 *         into 16 bit format user needs to right shift by 10 bits for
 *         Sinc3 filter with OSR = 256
 *   - Interrupt module settings for SDFM filter
 *       - All the 4 higher threshold comparator interrupts disabled
 *       - All the 4 lower threshold comparator interrupts disabled
 *       - All the 4 modulator failure interrupts disabled
 *       - All the 4 filter will generate interrupt when a new filter data
 *         is available
 * 
 *  \b External \b Connections \n
 *    - SDFM_PIN_MUX_OPTION1 Connect Sigma-Delta streams to
 *      (SDx-D1, SDx-C1 to SDx-D4,SDx-C4) on GPIO16-GPIO31
 *    - SDFM_PIN_MUX_OPTION2 Connect Sigma-Delta streams to
 *      (SDx-D1, SDx-C1 to SDx-D4,SDx-C4) on GPIO48-GPIO63
 * 
 *  \b Watch \b Variables \n
 *  -  \b filter1Result - Output of filter 1
 *  -  \b filter2Result - Output of filter 2
 *  -  \b filter3Result - Output of filter 3
 *  -  \b filter4Result - Output of filter 4
 * 
 * 
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "board.h"
#include "hte_gpio.h"
#include "hte_pinmux.h"
#include "hte_sdfm.h"
#include "hte_epwm.h"
#include "hte_sysctrl.h"


#ifdef HTE_DEVICE_HS32F7D377_CPU1
#include "hte_cpu1_ipc_com.h"
#else
#include "hte_cpu2_ipc_com.h"
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#ifdef HTE_DEVICE_HS32F7D377_CPU1
#define mySDFM_BASE0              SDFM1
#define myEPWM_BASE0              EPWM11
#else
#define mySDFM_BASE0              SDFM2
#define myEPWM_BASE0              EPWM12
#endif

#define MAX_SAMPLES               1024
#define SDFM_PIN_MUX_OPTION1      1
#define SDFM_PIN_MUX_OPTION2      2
#define EPWM_TIMER_TBPRD          10000  /* ePWM Period register */
#define SDFM_INT_MASK             0x0000F000U

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void configureSDFMPins(uint16_t sdfmPinOption);
void setPinConfig1(void);
void setPinConfig2(void);
void sdfmISR(SDFM_REGS_Type *base);
void sdfmInterruptConfig(void);
void sdfmInit(void);
void initEPWM(EPWM_REGS_Type *epwmInstance);

/*******************************************************************************
 * Variables
 ******************************************************************************/
EPWM_REGS_Type *epwmInstance = myEPWM_BASE0;                           
AT_NONCACHEABLE_DATA_SECTION(int16_t filter1Result[MAX_SAMPLES]);
AT_NONCACHEABLE_DATA_SECTION(int16_t filter2Result[MAX_SAMPLES]);
AT_NONCACHEABLE_DATA_SECTION(int16_t filter3Result[MAX_SAMPLES]);
AT_NONCACHEABLE_DATA_SECTION(int16_t filter4Result[MAX_SAMPLES]);



/*******************************************************************************
 * Codes
 ******************************************************************************/
void main(void)
{
    uint16_t  pinMuxOption;


    BOARD_init();

#ifdef HTE_DEVICE_HS32F7D377_CPU1
    IPC_comInit();
#endif

    pinMuxOption = SDFM_PIN_MUX_OPTION2;

    /* Configure GPIO pins as SDFM pins */
    configureSDFMPins(pinMuxOption);
    sdfmInterruptConfig();
    sdfmInit();
    
    while(1);
}

void sdfmInit(void)
{
    uint16_t  hlt, llt;

#ifdef HTE_DEVICE_HS32F7D377_CPU1
    if(mySDFM_BASE0 == SDFM1)
    {
        SYSCTRL_selectCPUForPeripheral(kSYSCTL_PERIPH_CPUSEL_SDFM1,kSYSCTRL_CPUSEL_CPU1);     
    } 
    else
    {
        SYSCTRL_selectCPUForPeripheral(kSYSCTL_PERIPH_CPUSEL_SDFM2,kSYSCTRL_CPUSEL_CPU1);           
    }
#else
    
    if(mySDFM_BASE0 == SDFM1)
    {
        IPC_com_selectCPUForPeripheral(kIPC_SYSCTRL_PERIPH_CPUSEL_SDFM1,kIPC_SYSCTRL_CPUSEL_CPU2);   
    } 
    else
    {
        IPC_com_selectCPUForPeripheral(kIPC_SYSCTRL_PERIPH_CPUSEL_SDFM2,kIPC_SYSCTRL_CPUSEL_CPU2);   
    }
#endif

    if(mySDFM_BASE0 == SDFM1)
    {
        SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_SDFM1);
    }
    else
    {
        SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_SDFM2);  
    }
    
    /*
     * Input Control Module:
     * Configure Modulator Clock rate = Modulator data rate
     */
    SDFM_setupModulatorClock(mySDFM_BASE0, kSDFM_FILTER_1,
                             kSDFM_MODULATOR_CLK_EQUAL_DATA_RATE);

    SDFM_setupModulatorClock(mySDFM_BASE0, kSDFM_FILTER_2,
                             kSDFM_MODULATOR_CLK_EQUAL_DATA_RATE);

    SDFM_setupModulatorClock(mySDFM_BASE0, kSDFM_FILTER_3,
                             kSDFM_MODULATOR_CLK_EQUAL_DATA_RATE);

    SDFM_setupModulatorClock(mySDFM_BASE0, kSDFM_FILTER_4,
                             kSDFM_MODULATOR_CLK_EQUAL_DATA_RATE);

    /* Comparator Module */
    hlt = 0x7fff;    /* Over value threshold settings */
    llt = 0x0000;    /* Under value threshold settings */

    /*
     * Configure Comparator module's comparator filter type and comparator's OSR
     * value, higher threshold, lower threshold
     */
    SDFM_configComparator(mySDFM_BASE0,
        ((uint16_t)kSDFM_FILTER_1 | (uint16_t)kSDFM_FILTER_SINC_3 | SDFM_SET_OSR(32)),
        (SDFM_GET_LOW_THRESHOLD(llt) | SDFM_GET_HIGH_THRESHOLD(hlt)), 0);
    SDFM_configComparator(mySDFM_BASE0,
        ((uint16_t)kSDFM_FILTER_2 | (uint16_t)kSDFM_FILTER_SINC_3 | SDFM_SET_OSR(32)),
        (SDFM_GET_LOW_THRESHOLD(llt) | SDFM_GET_HIGH_THRESHOLD(hlt)), 0);
    SDFM_configComparator(mySDFM_BASE0,
        ((uint16_t)kSDFM_FILTER_3 | (uint16_t)kSDFM_FILTER_SINC_3 | SDFM_SET_OSR(32)),
        (SDFM_GET_LOW_THRESHOLD(llt) | SDFM_GET_HIGH_THRESHOLD(hlt)), 0);
    SDFM_configComparator(mySDFM_BASE0,
        ((uint16_t)kSDFM_FILTER_4 | (uint16_t)kSDFM_FILTER_SINC_3 | SDFM_SET_OSR(32)),
        (SDFM_GET_LOW_THRESHOLD(llt) | SDFM_GET_HIGH_THRESHOLD(hlt)), 0);
    
    /*
     * Data filter Module
     *
     * Configure Data filter modules filter type, OSR value and
     * enable / disable data filter
     */
    SDFM_configDataFilter(mySDFM_BASE0, ((uint16_t)kSDFM_FILTER_1 | (uint16_t)kSDFM_FILTER_SINC_3 |
           SDFM_SET_OSR(256)), (kSDFM_DATA_FORMAT_16_BIT | SDFM_FILTER_ENABLE |
           SDFM_SHIFT_VALUE(0x000A)));

    SDFM_configDataFilter(mySDFM_BASE0, ((uint16_t)kSDFM_FILTER_2 | (uint16_t)kSDFM_FILTER_SINC_3 |
           SDFM_SET_OSR(256)), (kSDFM_DATA_FORMAT_16_BIT | SDFM_FILTER_ENABLE |
           SDFM_SHIFT_VALUE(0x000A)));

    SDFM_configDataFilter(mySDFM_BASE0, ((uint16_t)kSDFM_FILTER_3 | (uint16_t)kSDFM_FILTER_SINC_3 |
           SDFM_SET_OSR(256)), (kSDFM_DATA_FORMAT_16_BIT | SDFM_FILTER_ENABLE |
           SDFM_SHIFT_VALUE(0x000A)));

    SDFM_configDataFilter(mySDFM_BASE0, ((uint16_t)kSDFM_FILTER_4 | (uint16_t)kSDFM_FILTER_SINC_3 |
           SDFM_SET_OSR(256)), (kSDFM_DATA_FORMAT_16_BIT | SDFM_FILTER_ENABLE |
           SDFM_SHIFT_VALUE(0x000A)));

    /*
     * Enable Master filter bit: Unless this bit is set none of the filter modules
     * can be enabled. All the filter modules are synchronized when master filter
     * bit is enabled after individual filter modules are enabled.
     */
    SDFM_enableMasterFilter(mySDFM_BASE0);

    /*
     * PWM11.CMPC, PWM11.CMPD signals can synchronize SDFM1 filters and
     * PWM12.CMPC and PWM12.CMPD signals can synchronize SDFM2 filters. This
     * option is being used in this example for SDFM1.
     */
#ifdef HTE_DEVICE_HS32F7D377_CPU1    
    SDFM_setPWMSyncSource(mySDFM_BASE0, kSDFM_FILTER_1,kSDFM_SYNC_PWM11_CMPCD);
    SDFM_enableWaitForSync(mySDFM_BASE0, kSDFM_FILTER_1);
    SDFM_setPWMSyncSource(mySDFM_BASE0, kSDFM_FILTER_2,kSDFM_SYNC_PWM11_CMPCD);
    SDFM_enableWaitForSync(mySDFM_BASE0, kSDFM_FILTER_2);
    SDFM_setPWMSyncSource(mySDFM_BASE0, kSDFM_FILTER_3,kSDFM_SYNC_PWM11_CMPCD);
    SDFM_enableWaitForSync(mySDFM_BASE0, kSDFM_FILTER_3);
    SDFM_setPWMSyncSource(mySDFM_BASE0, kSDFM_FILTER_4,kSDFM_SYNC_PWM11_CMPCD);
    SDFM_enableWaitForSync(mySDFM_BASE0, kSDFM_FILTER_4);
#else
    SDFM_setPWMSyncSource(mySDFM_BASE0, kSDFM_FILTER_1,kSDFM_SYNC_PWM12_CMPCD);
    SDFM_enableWaitForSync(mySDFM_BASE0, kSDFM_FILTER_1);
    SDFM_setPWMSyncSource(mySDFM_BASE0, kSDFM_FILTER_2,kSDFM_SYNC_PWM12_CMPCD);
    SDFM_enableWaitForSync(mySDFM_BASE0, kSDFM_FILTER_2);
    SDFM_setPWMSyncSource(mySDFM_BASE0, kSDFM_FILTER_3,kSDFM_SYNC_PWM12_CMPCD);
    SDFM_enableWaitForSync(mySDFM_BASE0, kSDFM_FILTER_3);
    SDFM_setPWMSyncSource(mySDFM_BASE0, kSDFM_FILTER_4,kSDFM_SYNC_PWM12_CMPCD);
    SDFM_enableWaitForSync(mySDFM_BASE0, kSDFM_FILTER_4);
#endif

    /* Init EPWMs */
    initEPWM(myEPWM_BASE0);

    /*
     * Enable interrupts
     *
     * Following SDFM interrupts can be enabled / disabled using this function.
     *  Enable / disable comparator high threshold
     *  Enable / disable comparator low threshold
     *  Enable / disable modulator clock failure
     *  Enable / disable filter acknowledge
     */
    SDFM_enableInterrupt(mySDFM_BASE0, kSDFM_FILTER_1,
            (SDFM_MODULATOR_FAILURE_INTERRUPT |
             SDFM_DATA_FILTER_ACKNOWLEDGE_INTERRUPT));

    SDFM_enableInterrupt(mySDFM_BASE0, kSDFM_FILTER_2,
            (SDFM_MODULATOR_FAILURE_INTERRUPT |
             SDFM_DATA_FILTER_ACKNOWLEDGE_INTERRUPT));

    SDFM_enableInterrupt(mySDFM_BASE0, kSDFM_FILTER_3,
            (SDFM_MODULATOR_FAILURE_INTERRUPT |
             SDFM_DATA_FILTER_ACKNOWLEDGE_INTERRUPT));

    SDFM_enableInterrupt(mySDFM_BASE0, kSDFM_FILTER_4,
            (SDFM_MODULATOR_FAILURE_INTERRUPT |
             SDFM_DATA_FILTER_ACKNOWLEDGE_INTERRUPT));

    SDFM_disableInterrupt(mySDFM_BASE0, kSDFM_FILTER_1,
            (SDFM_HIGH_LEVEL_THRESHOLD_INTERRUPT |
             SDFM_LOW_LEVEL_THRESHOLD_INTERRUPT));

    SDFM_disableInterrupt(mySDFM_BASE0, kSDFM_FILTER_2,
            (SDFM_HIGH_LEVEL_THRESHOLD_INTERRUPT |
             SDFM_LOW_LEVEL_THRESHOLD_INTERRUPT));

    SDFM_disableInterrupt(mySDFM_BASE0, kSDFM_FILTER_3,
            (SDFM_HIGH_LEVEL_THRESHOLD_INTERRUPT |
             SDFM_LOW_LEVEL_THRESHOLD_INTERRUPT));

    SDFM_disableInterrupt(mySDFM_BASE0, kSDFM_FILTER_4,
            (SDFM_HIGH_LEVEL_THRESHOLD_INTERRUPT |
             SDFM_LOW_LEVEL_THRESHOLD_INTERRUPT));

    while(epwmInstance->TBCTR < 550);

    /*
     * Enable master interrupt so that any of the filter interrupts can trigger
     * by SDFM interrupt to CPU
     */
    SDFM_enableMasterInterrupt(mySDFM_BASE0);
}

void sdfmInterruptConfig(void)
{
    /*
     * SDFM DR_INT4 to handle all channels isr function.
     */
    SDFM_registerCallback(mySDFM_BASE0,kSDFM_DR_INT4,sdfmISR,5);
}


/* sdfm1ISR - SDFM ISR */
void sdfmISR(SDFM_REGS_Type *base)
{
    static uint16_t loopCounter1 = 0;

    /* Wait for result from all the filters (SDIFLG) */
    while((base->SDIFLG & SDFM_INT_MASK) != SDFM_INT_MASK);

    /* Reset the loop counter */
    if(loopCounter1 >= MAX_SAMPLES)
    {
        loopCounter1 = 0;
    }

    /*
     * Read each SDFM filter output and store it in respective filter
     * result array
     */
    filter1Result[loopCounter1]   = (int16_t)(SDFM_getFilterData(base, kSDFM_FILTER_1) >> 16U);
    filter2Result[loopCounter1]   = (int16_t)(SDFM_getFilterData(base, kSDFM_FILTER_2) >> 16U);
    filter3Result[loopCounter1]   = (int16_t)(SDFM_getFilterData(base, kSDFM_FILTER_3) >> 16U);
    filter4Result[loopCounter1++] = (int16_t)(SDFM_getFilterData(base, kSDFM_FILTER_4) >> 16U);

    /* Clear SDFM flag register */
    SDFM_clearInterruptFlag(mySDFM_BASE0, SDFM_INT_MASK);

}

/* configureSDFMPins - Configure SDFM GPIOs */
void configureSDFMPins(uint16_t sdfmPinOption)
{
    uint16_t pin;

    switch (sdfmPinOption)
    {
        case SDFM_PIN_MUX_OPTION1:
            for(pin = 16; pin <= 31; pin++)
            {
#ifdef HTE_DEVICE_HS32F7D377_CPU1
                GPIO_setMasterCore(pin, kGPIO_CORE_CPU1);
                GPIO_setPadConfig(pin, kGPIO_PADCONFIG_STD);
                GPIO_setQualificationMode(pin, kGPIO_QUAL_ASYNC);
#else
                IPC_com_GPIO_setMasterCore(pin, kGPIO_CORE_CPU2);
                IPC_com_GPIO_setPadConfig(pin, kGPIO_PADCONFIG_STD);
                IPC_com_GPIO_setQualificationMode(pin, kGPIO_QUAL_ASYNC);          
#endif
            }
            setPinConfig1();
            break;

        case SDFM_PIN_MUX_OPTION2:
            for(pin = 48; pin <= 63; pin++)
            {
#ifdef HTE_DEVICE_HS32F7D377_CPU1   
                GPIO_setMasterCore(pin, kGPIO_CORE_CPU1);
                GPIO_setPadConfig(pin, kGPIO_PADCONFIG_STD);
                GPIO_setQualificationMode(pin, kGPIO_QUAL_ASYNC);
#else
                IPC_com_GPIO_setMasterCore(pin, kGPIO_CORE_CPU2);
                IPC_com_GPIO_setPadConfig(pin, kGPIO_PADCONFIG_STD);
                IPC_com_GPIO_setQualificationMode(pin, kGPIO_QUAL_ASYNC);
#endif
            }
            setPinConfig2();
            break;
    }
}


/* setPinConfig1 - sets the pin configuration for pins 16-31 */
void setPinConfig1()
{
#ifdef HTE_DEVICE_HS32F7D377_CPU1  
    GPIO_setPinConfig(GPIO_16_SD1_D1);
    GPIO_setPinConfig(GPIO_17_SD1_C1);
    GPIO_setPinConfig(GPIO_18_SD1_D2);
    GPIO_setPinConfig(GPIO_19_SD1_C2);
    GPIO_setPinConfig(GPIO_20_SD1_D3);
    GPIO_setPinConfig(GPIO_21_SD1_C3);
    GPIO_setPinConfig(GPIO_22_SD1_D4);
    GPIO_setPinConfig(GPIO_23_SD1_C4);
    GPIO_setPinConfig(GPIO_24_SD2_D1);
    GPIO_setPinConfig(GPIO_25_SD2_C1);
    GPIO_setPinConfig(GPIO_26_SD2_D2);
    GPIO_setPinConfig(GPIO_27_SD2_C2);
    GPIO_setPinConfig(GPIO_28_SD2_D3);
    GPIO_setPinConfig(GPIO_29_SD2_C3);
    GPIO_setPinConfig(GPIO_30_SD2_D4);
    GPIO_setPinConfig(GPIO_31_SD2_C4);
#else
    IPC_com_GPIO_setPinConfig(GPIO_16_SD1_D1);
    IPC_com_GPIO_setPinConfig(GPIO_17_SD1_C1);
    IPC_com_GPIO_setPinConfig(GPIO_18_SD1_D2);
    IPC_com_GPIO_setPinConfig(GPIO_19_SD1_C2);
    IPC_com_GPIO_setPinConfig(GPIO_20_SD1_D3);
    IPC_com_GPIO_setPinConfig(GPIO_21_SD1_C3);
    IPC_com_GPIO_setPinConfig(GPIO_22_SD1_D4);
    IPC_com_GPIO_setPinConfig(GPIO_23_SD1_C4);
    IPC_com_GPIO_setPinConfig(GPIO_24_SD2_D1);
    IPC_com_GPIO_setPinConfig(GPIO_25_SD2_C1);
    IPC_com_GPIO_setPinConfig(GPIO_26_SD2_D2);
    IPC_com_GPIO_setPinConfig(GPIO_27_SD2_C2);
    IPC_com_GPIO_setPinConfig(GPIO_28_SD2_D3);
    IPC_com_GPIO_setPinConfig(GPIO_29_SD2_C3);
    IPC_com_GPIO_setPinConfig(GPIO_30_SD2_D4);
    IPC_com_GPIO_setPinConfig(GPIO_31_SD2_C4); 
#endif
}

/*
 * setPinConfig2 - sets the pin configuration for
 * pins 48-63
 */
void setPinConfig2()
{
#ifdef HTE_DEVICE_HS32F7D377_CPU1
    GPIO_setPinConfig(GPIO_48_SD1_D1);
    GPIO_setPinConfig(GPIO_49_SD1_C1);
    GPIO_setPinConfig(GPIO_50_SD1_D2);
    GPIO_setPinConfig(GPIO_51_SD1_C2);
    GPIO_setPinConfig(GPIO_52_SD1_D3);
    GPIO_setPinConfig(GPIO_53_SD1_C3);
    GPIO_setPinConfig(GPIO_54_SD1_D4);
    GPIO_setPinConfig(GPIO_55_SD1_C4);
    GPIO_setPinConfig(GPIO_56_SD2_D1);
    GPIO_setPinConfig(GPIO_57_SD2_C1);
    GPIO_setPinConfig(GPIO_58_SD2_D2);
    GPIO_setPinConfig(GPIO_59_SD2_C2);
    GPIO_setPinConfig(GPIO_60_SD2_D3);
    GPIO_setPinConfig(GPIO_61_SD2_C3);
    GPIO_setPinConfig(GPIO_62_SD2_D4);
    GPIO_setPinConfig(GPIO_63_SD2_C4);
#else
    IPC_com_GPIO_setPinConfig(GPIO_48_SD1_D1);
    IPC_com_GPIO_setPinConfig(GPIO_49_SD1_C1);
    IPC_com_GPIO_setPinConfig(GPIO_50_SD1_D2);
    IPC_com_GPIO_setPinConfig(GPIO_51_SD1_C2);
    IPC_com_GPIO_setPinConfig(GPIO_52_SD1_D3);
    IPC_com_GPIO_setPinConfig(GPIO_53_SD1_C3);
    IPC_com_GPIO_setPinConfig(GPIO_54_SD1_D4);
    IPC_com_GPIO_setPinConfig(GPIO_55_SD1_C4);
    IPC_com_GPIO_setPinConfig(GPIO_56_SD2_D1);
    IPC_com_GPIO_setPinConfig(GPIO_57_SD2_C1);
    IPC_com_GPIO_setPinConfig(GPIO_58_SD2_D2);
    IPC_com_GPIO_setPinConfig(GPIO_59_SD2_C2);
    IPC_com_GPIO_setPinConfig(GPIO_60_SD2_D3);
    IPC_com_GPIO_setPinConfig(GPIO_61_SD2_C3);
    IPC_com_GPIO_setPinConfig(GPIO_62_SD2_D4);
    IPC_com_GPIO_setPinConfig(GPIO_63_SD2_C4);   
#endif
}

/* initEPWM - Initialize specified EPWM settings */
void initEPWM(EPWM_REGS_Type *epwmInstance)
{
    uint16_t compCVal,compDVal;
    
    compCVal = 200;
    compDVal = 200;

    /* Disable sync(Freeze clock to PWM as well) */
    SYSCTRL_disablePeripheral(kSYSCTL_PERIPH_CLK_TBCLKSYNC);    
    
#ifdef HTE_DEVICE_HS32F7D377_CPU1
    SYSCTRL_selectCPUForPeripheral(kSYSCTL_PERIPH_CPUSEL_EPWM11,kSYSCTRL_CPUSEL_CPU1);
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_EPWM11);
#else
    IPC_com_selectCPUForPeripheral(kIPC_SYSCTRL_PERIPH_CPUSEL_EPWM12,kIPC_SYSCTRL_CPUSEL_CPU2);
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_EPWM12);
#endif
    
    /*
     * Setup TBCLK: Configure timer period = 801 TBCLKs, phase = 0 &
     * clear counter
     */
    EPWM_setTimeBasePeriod(epwmInstance, EPWM_TIMER_TBPRD);
    EPWM_setPhaseShift(epwmInstance, 0U);
    EPWM_setTimeBaseCounter(epwmInstance, 0U);

    /* Set CMPA, CMPB, CMPC & CMPD values */
    EPWM_setCounterCompareValue(epwmInstance, EPWM_COUNTER_COMPARE_C, compCVal);
    EPWM_setCounterCompareValue(epwmInstance, EPWM_COUNTER_COMPARE_D, compDVal);
    EPWM_setCounterCompareValue(epwmInstance, EPWM_COUNTER_COMPARE_A, compCVal);
    EPWM_setCounterCompareValue(epwmInstance, EPWM_COUNTER_COMPARE_B, compDVal);


    /* Setup counter mode */
    EPWM_setTimeBaseCounterMode(epwmInstance, EPWM_COUNTER_MODE_UP);
    EPWM_setClockPrescaler(epwmInstance,
                           EPWM_CLOCK_DIVIDER_1,
                           EPWM_HSCLOCK_DIVIDER_10);

    /*
     * Set actions:
     * Toggle PWMxA on event A, up-count
     * Toggle PWMxB on event A, up-count
     */
    EPWM_setActionQualifierAction(epwmInstance,
                                  EPWM_AQ_OUTPUT_A,
                                  EPWM_AQ_OUTPUT_TOGGLE,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    EPWM_setActionQualifierAction(epwmInstance,
                                  EPWM_AQ_OUTPUT_B,
                                  EPWM_AQ_OUTPUT_TOGGLE,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);

    /* Enable sync and clock to PWM */
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_TBCLKSYNC);
}

/* End of file */
