/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*
 * 
 * \file sdfm_ex4_type1_filter_fifo_cpuread.c
 * 
 * \brief SDFM Type 1 Filter FIFO Example.
 * 
 *  This example configures SDFM1 filter in type 1 to demonstrate data read
 *  through CPU in FIFO & non-FIFO mode. Data filter is configured in mode 0
 *  to select SINC3 filter with OSR of 256. Filter output is configured
 *  for 16-bit format and data shift of 10 is used.
 * 
 *  This example demonstrates the FIFO usage if enabled. FIFO length is set
 *  at 16 and data ready interrupt is configured to be triggered when FIFO is
 *  full. In this example, SDFM filter data is read by CPU in SDFM Data Ready
 *  ISR routine.
 * 
 *  \b External \b Connections \n
 *    - SDFM_PIN_MUX_OPTION1 Connect Sigma-Delta streams(SD1-D1, SD1-C1) to
 *      (GPIO16, GPIO17)
 *    - SDFM_PIN_MUX_OPTION2 Connect Sigma-Delta streams(SD1-D1, SD1-C1) to
 *      (GPIO48, GPIO49)
 * 
 *  \b Watch \b Variables \n
 *  -  \b filter1Result - Output of filter 1
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
#define FIFO_INT_NUM              16U
#define SDFM_FILTER_ENABLE        0x2U

/*
 * Macro to enable FIFO mode. Make it zero to disable
 * FIFO mode.
 */
#define ENABLE_FIFO               1

//
// Macro for pin-mux options
//
#define SDFM_PIN_MUX_OPTION1      1
#define SDFM_PIN_MUX_OPTION2      2


/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void configureSDFMPins(uint16_t);
void setPinConfig1(void);
void setPinConfig2(void);
void sdfmFIFOISR(SDFM_REGS_Type *base);
void sdfmERRISR(SDFM_REGS_Type *base);
void sdfmInterruptConfig(void);
void sdfmInit(void);


/*******************************************************************************
 * Variables
 ******************************************************************************/
AT_NONCACHEABLE_DATA_SECTION(int16_t filter1Result[MAX_SAMPLES]);


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

    /*
     * Data Filter Unit
     *
     * Configure Data Filter Unit - filter type, OSR value and
     * enable / disable data filter
     */
    SDFM_configDataFilter(mySDFM_BASE0, ((uint16_t)kSDFM_FILTER_1 | (uint16_t)kSDFM_FILTER_SINC_3 |
           SDFM_SET_OSR(256)), (kSDFM_DATA_FORMAT_16_BIT | SDFM_FILTER_ENABLE |
           SDFM_SHIFT_VALUE(0x000A)));

#if (ENABLE_FIFO)
        /* Set data ready interrupt source as fifo interrupt */
        SDFM_setDataReadyInterruptSource(mySDFM_BASE0, kSDFM_FILTER_1,
                                         kSDFM_DATA_READY_SOURCE_FIFO);

        /* Enable FIFO and set the FIFO interrupt level */
        SDFM_enableFIFOBuffer(mySDFM_BASE0, kSDFM_FILTER_1);

        SDFM_setFIFOInterruptLevel(mySDFM_BASE0, kSDFM_FILTER_1, FIFO_INT_NUM);

        SDFM_enableInterrupt(mySDFM_BASE0, kSDFM_FILTER_1,
                         (SDFM_FIFO_INTERRUPT | SDFM_FIFO_OVERFLOW_INTERRUPT));
#else
        /* Set data ready interrupt source as fifo interrupt */
        SDFM_setDataReadyInterruptSource(mySDFM_BASE0, SDFM_FILTER_1,
                                         SDFM_DATA_READY_SOURCE_DIRECT);

        SDFM_enableInterrupt(mySDFM_BASE0, SDFM_FILTER_1,
                             SDFM_DATA_FILTER_ACKNOWLEDGE_INTERRUPT);
#endif


    /*
     * Enable Master filter bit: Unless this bit is set none of the filter
     * modules can be enabled. All the filter modules are synchronized when
     * master filter bit is enabled after individual filter modules are enabled.
     */
    SDFM_enableMasterFilter(mySDFM_BASE0);

    /*
     * PWM11.CMPC, PWM11.CMPD, PWM12.CMPC and PWM12.CMPD signals cannot
     * synchronize the filters. This option is not being used in this example.
     */
    SDFM_disableExternalReset(mySDFM_BASE0, kSDFM_FILTER_1);

    /* Enable modulator failure interrupt, disable threshold interrupts */
    SDFM_enableInterrupt(mySDFM_BASE0, kSDFM_FILTER_1,
                         SDFM_MODULATOR_FAILURE_INTERRUPT);

    SDFM_disableInterrupt(mySDFM_BASE0, kSDFM_FILTER_1,
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
     * Interrupts that are used in this example are different for ERR_INT and DR_INT.
     * DR_INT proprity level should set higher than ERR_INT
     */
    SDFM_registerCallback(mySDFM_BASE0,kSDFM_INT,sdfmERRISR,6);
    SDFM_registerCallback(mySDFM_BASE0,kSDFM_DR_INT1,sdfmFIFOISR,5);
}



/* sdfmERRISR - SDFM Error ISR */
void sdfmERRISR(SDFM_REGS_Type *base)
{
    /* Clear SDFM flag register (SDIFLG) */
    SDFM_clearInterruptFlag(base, SDFM_MASTER_INTERRUPT_FLAG |
                            0xFFFF);
}


/* sdfmFIFOISR - SDFM FIFO ISR */
void sdfmFIFOISR(SDFM_REGS_Type *base)
{
    uint16_t i;
    static uint16_t loopCounter1 = 0;

    SDFM_setOutputDataFormat(base, kSDFM_FILTER_1,
                             kSDFM_DATA_FORMAT_16_BIT);

    /* Read SDFM flag register (SDIFLG) */
    if(loopCounter1 >= MAX_SAMPLES)
    {
        while(1);
    }
    else if(SDFM_getFIFOISRStatus(base, kSDFM_FILTER_1) == 0x1U)
    {
        for(i = 0; i < FIFO_INT_NUM; i++)
        {
            filter1Result[loopCounter1++] =
                         (int16_t)(SDFM_getFIFOData(base,
                                                    kSDFM_FILTER_1) >> 16U);
        }

    }
    else if(SDFM_getNewFilterDataStatus(base, kSDFM_FILTER_1) == 0x1U)
    {
        filter1Result[loopCounter1++] =
               (int16_t)(SDFM_getFilterData(base, kSDFM_FILTER_1) >> 16U);
    }

    /* Clear SDFM flag register (SDIFLG) */
    SDFM_clearInterruptFlag(base, SDFM_MASTER_INTERRUPT_FLAG |
                            SDFM_FILTER_1_FIFO_INTERRUPT_FLAG      |
                            SDFM_FILTER_1_NEW_DATA_FLAG            |
                            SDFM_FILTER_1_FIFO_OVERFLOW_FLAG);
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
                GPIO_setDirectionMode(pin, kGPIO_DIR_INPUT);
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
                GPIO_setDirectionMode(pin, kGPIO_DIR_INPUT);
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
