/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*
 * 
 * \file sdfm_ex1_filter_sync_cpuread.c
 * 
 * \brief SDFM Filter sync CPU Example.
 * 
 *  In this example, SDFM filter data is read by CPU in SDFM ISR routine. The
 *  SDFM configuration is shown below:
 *   -  SDFM used in this example - SDFM1
 *   -  Input control mode selected - MODE0
 *   -  Comparator settings
 *        - Sinc3 filter selected
 *        - OSR = 32
 *        - HLT = 0x7FFF (Higher threshold setting)
 *        - LLT  = 0x0000(Lower threshold setting)
 *   -  Data filter settings
 *       - All the 4 filter modules enabled
 *       - Sinc3 filter selected
 *       - OSR = 128
 *       - All the 4 filters are synchronized by using MFE
 *        (Master Filter enable bit)
 *       - Filter output represented in 16 bit format
 *       - In order to convert 25 bit Data filter
 *         into 16 bit format user needs to right shift by 7 bits for
 *         Sinc3 filter with OSR = 128
 *   - Interrupt module settings for SDFM filter
 *       - All the 4 higher threshold comparator interrupts disabled
 *       - All the 4 lower threshold comparator interrupts disabled
 *       - All the 4 modulator failure interrupts disabled
 *       - All the 4 filter will generate interrupt when a new filter data
 *         is available.
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
#else
#define mySDFM_BASE0              SDFM2
#endif

#define MAX_SAMPLES               1024
#define SDFM_PIN_MUX_OPTION1      1
#define SDFM_PIN_MUX_OPTION2      2

#define SDFM_FILTER_ENABLE 0x2U

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void configureSDFMPins(uint16_t);
void setPinConfig1(void);
void setPinConfig2(void);
void sdfmISR(SDFM_REGS_Type *base);
void sdfmInterruptConfig(void);
void sdfmInit(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/
uint16_t peripheralNumber;
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

    /* Wait for an interrupt */
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
     * Input Control Unit
     *
     * Configure Input Control Unit: Modulator Clock rate = Modulator data rate
     */
    SDFM_setupModulatorClock(mySDFM_BASE0, kSDFM_FILTER_1,
                             kSDFM_MODULATOR_CLK_EQUAL_DATA_RATE);

    SDFM_setupModulatorClock(mySDFM_BASE0, kSDFM_FILTER_2,
                             kSDFM_MODULATOR_CLK_EQUAL_DATA_RATE);

    SDFM_setupModulatorClock(mySDFM_BASE0, kSDFM_FILTER_3,
                             kSDFM_MODULATOR_CLK_EQUAL_DATA_RATE);

    SDFM_setupModulatorClock(mySDFM_BASE0, kSDFM_FILTER_4,
                             kSDFM_MODULATOR_CLK_EQUAL_DATA_RATE);

    /* Comparator Unit - over and under value threshold settings */
    hlt = 0x7FFF;
    llt = 0x0000;

    /*
     * Configure Comparator Unit's comparator filter type and comparator's
     * OSR value, higher threshold, lower threshold
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
     * Data Filter Unit
     *
     * Configure Data Filter Unit - filter type, OSR value and
     * enable / disable data filter
     */
    SDFM_configDataFilter(mySDFM_BASE0, ((uint16_t)kSDFM_FILTER_1 | (uint16_t)kSDFM_FILTER_SINC_3 |
           SDFM_SET_OSR(128)), (kSDFM_DATA_FORMAT_16_BIT | SDFM_FILTER_ENABLE |
           SDFM_SHIFT_VALUE(0x0007)));

    SDFM_configDataFilter(mySDFM_BASE0, ((uint16_t)kSDFM_FILTER_2 | (uint16_t)kSDFM_FILTER_SINC_3 |
           SDFM_SET_OSR(128)), (kSDFM_DATA_FORMAT_16_BIT | SDFM_FILTER_ENABLE |
           SDFM_SHIFT_VALUE(0x0007)));

    SDFM_configDataFilter(mySDFM_BASE0, ((uint16_t)kSDFM_FILTER_3 | (uint16_t)kSDFM_FILTER_SINC_3 |
           SDFM_SET_OSR(128)), (kSDFM_DATA_FORMAT_16_BIT | SDFM_FILTER_ENABLE |
           SDFM_SHIFT_VALUE(0x0007)));

    SDFM_configDataFilter(mySDFM_BASE0, ((uint16_t)kSDFM_FILTER_4 | (uint16_t)kSDFM_FILTER_SINC_3 |
           SDFM_SET_OSR(128)), (kSDFM_DATA_FORMAT_16_BIT | SDFM_FILTER_ENABLE |
           SDFM_SHIFT_VALUE(0x0007)));

    /*
     * Enable Master filter bit: Unless this bit is set none of the filter modules
     * can be enabled. All the filter modules are synchronized when master filter
     * bit is enabled after individual filter modules are enabled.
     */
    SDFM_enableMasterFilter(mySDFM_BASE0);

    /*
     * PWM11.CMPC, PWM11.CMPD, PWM12.CMPC and PWM12.CMPD signals cannot synchronize
     * the filters. This option is not being used in this example.
     */
    SDFM_disableExternalReset(mySDFM_BASE0, kSDFM_FILTER_1);
    SDFM_disableExternalReset(mySDFM_BASE0, kSDFM_FILTER_2);
    SDFM_disableExternalReset(mySDFM_BASE0, kSDFM_FILTER_3);
    SDFM_disableExternalReset(mySDFM_BASE0, kSDFM_FILTER_4);

    /*
     * Enable interrupts
     *
     * Following SDFM interrupts can be enabled / disabled using this function.
     * Enable / disable comparator high threshold
     * Enable / disable comparator low threshold
     * Enable / disable modulator clock failure
     * Enable / disable data filter acknowledge
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

    /*
     * Enable master interrupt so that any of the filter interrupts can trigger
     * by SDFM interrupt to CPU
     */
    SDFM_enableMasterInterrupt(mySDFM_BASE0);

}


void sdfmInterruptConfig(void)
{
    /*
     * Interrupts that are used in this example are re-mapped to same
     * ISR functions found within this file.
     */
//    SDFM_registerCallback(mySDFM_BASE0,kSDFM_INT,sdfmISR,5);
//    SDFM_registerCallback(mySDFM_BASE0,kSDFM_DR_INT1,sdfmISR,5);
//    SDFM_registerCallback(mySDFM_BASE0,kSDFM_DR_INT2,sdfmISR,5);
//    SDFM_registerCallback(mySDFM_BASE0,kSDFM_DR_INT3,sdfmISR,5);
    SDFM_registerCallback(mySDFM_BASE0,kSDFM_DR_INT4,sdfmISR,5);
}

/* sdfmISR - SDFM ISR */
void sdfmISR(SDFM_REGS_Type *base)
{
//    volatile uint32_t sdfmReadFlagRegister = 0;
    static uint16_t loopCounter1 = 0;

    SDFM_setOutputDataFormat(base, kSDFM_FILTER_1,
                             kSDFM_DATA_FORMAT_16_BIT);

    SDFM_setOutputDataFormat(base, kSDFM_FILTER_2,
                             kSDFM_DATA_FORMAT_16_BIT);

    SDFM_setOutputDataFormat(base, kSDFM_FILTER_3,
                             kSDFM_DATA_FORMAT_16_BIT);

    SDFM_setOutputDataFormat(base, kSDFM_FILTER_4,
                             kSDFM_DATA_FORMAT_16_BIT);

    /* Read SDFM flag register (SDIFLG) */
//    sdfmReadFlagRegister = base->SDIFLG;

    if(loopCounter1 < MAX_SAMPLES)
    {
        /*
         * Read each SDFM filter output and store it in respective filter
         * result array
         */
        filter1Result[loopCounter1] =
              (int16_t)(SDFM_getFilterData(base, kSDFM_FILTER_1) >> 16U);

        filter2Result[loopCounter1] =
              (int16_t)(SDFM_getFilterData(base, kSDFM_FILTER_2) >> 16U);

        filter3Result[loopCounter1] =
              (int16_t)(SDFM_getFilterData(base, kSDFM_FILTER_3) >> 16U);

        filter4Result[loopCounter1++] =
              (int16_t)(SDFM_getFilterData(base, kSDFM_FILTER_4) >> 16U);

        /* Clear SDFM flag register (SDIFLG) */
        SDFM_clearInterruptFlag(base, SDFM_MASTER_INTERRUPT_FLAG |
                                            0xFFFF);

        /* Read SDFM flag register (SDIFLG) */
//        sdfmReadFlagRegister = base->SDIFLG;
    }
    else
    {
        SDFM_disableInterrupt(mySDFM_BASE0, kSDFM_FILTER_1,
                (SDFM_MODULATOR_FAILURE_INTERRUPT |
                 SDFM_DATA_FILTER_ACKNOWLEDGE_INTERRUPT));

        SDFM_disableInterrupt(mySDFM_BASE0, kSDFM_FILTER_2,
                (SDFM_MODULATOR_FAILURE_INTERRUPT |
                 SDFM_DATA_FILTER_ACKNOWLEDGE_INTERRUPT));

        SDFM_disableInterrupt(mySDFM_BASE0, kSDFM_FILTER_3,
                (SDFM_MODULATOR_FAILURE_INTERRUPT |
                 SDFM_DATA_FILTER_ACKNOWLEDGE_INTERRUPT));

        SDFM_disableInterrupt(mySDFM_BASE0, kSDFM_FILTER_4,
                (SDFM_MODULATOR_FAILURE_INTERRUPT |
                 SDFM_DATA_FILTER_ACKNOWLEDGE_INTERRUPT));
        
        
        SDFM_disableMasterInterrupt(mySDFM_BASE0);
    }

    /* Acknowledge this __interrupt to receive more __interrupts from group 5 */
    ISR_EXIT_BARRIER();
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

/*
 * End of file
 */
