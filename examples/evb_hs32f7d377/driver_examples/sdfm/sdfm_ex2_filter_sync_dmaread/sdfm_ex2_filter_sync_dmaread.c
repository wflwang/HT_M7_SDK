/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*
 * 
 * \file sdfm_ex2_filter_sync_dmaread.c
 * 
 * \brief SDFM Filter Sync DMA Example.
 * 
 *  In this example, SDFM filter data is read by DMA. The
 *  SDFM configuration is shown below:
 *   - SDFM1 used in this example. For using SDFM2, few modifications
 *     would be needed in the example.
 *   - MODE0 Input control mode selected
 *   - Comparator settings
 *       - Sinc3 filter selected
 *       - OSR = 32
 *       - hlt = 0x7FFF (Higher threshold setting)
 *       - llt  = 0x0000(Lower threshold setting)
 *   - Data filter settings
 *       - All the 4 filter modules enabled
 *       - Sinc3 filter selected
 *       - OSR = 256
 *       - All the 4 filters are synchronized by using MFE
 *        (Master Filter enable bit)
 *       - Filter output represented in 16 bit format
 *       - In order to convert 25 bit Data filter
 *         into 16 bit format user needs to right shift by 10 bits for
 *         Sinc3 filter with OSR = 256
 *   - Interrupt module settings for SDFM filter
 *       - All the 4 higher threshold comparator interrupts disabled
 *       - All the 4 lower threshold comparator interrupts disabled
 *       - All the 4 modulator failure interrupts disabled
 *       - All the 4 filter will generate interrupt when a new filter
 *         data is available
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
#include "hte_dma.h"
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
#define TRG_OFFSET                  0
#else
#define mySDFM_BASE0              SDFM2
#define TRG_OFFSET                  4
#endif

#define MAX_SAMPLES                               1024
#define SDFM_PIN_MUX_OPTION1                      1
#define SDFM_PIN_MUX_OPTION2                      2


/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void dmaCh1ISR(DMA_Index_t index);
void dmaCh2ISR(DMA_Index_t index);
void dmaCh3ISR(DMA_Index_t index);
void dmaCh4ISR(DMA_Index_t index);
void initializeDMA(void);
void configureDMAChannels(void);
void configureSDFMPins(uint16_t sdfmPinOption);
void setPinConfig1(void);
void setPinConfig2(void);
void sdfmInit(void);


/*******************************************************************************
 * Variables
 ******************************************************************************/
uint16_t peripheralNumber;
AT_NONCACHEABLE_DATA_SECTION(int16_t filter1Result[MAX_SAMPLES]);
AT_NONCACHEABLE_DATA_SECTION(int16_t filter2Result[MAX_SAMPLES]);
AT_NONCACHEABLE_DATA_SECTION(int16_t filter3Result[MAX_SAMPLES]);
AT_NONCACHEABLE_DATA_SECTION(int16_t filter4Result[MAX_SAMPLES]);


/* Pointers for DMA source & destination addresses */
int16_t *dma1SrcAddr, *dma1DestAddr;
int16_t *dma2SrcAddr, *dma2DestAddr;
int16_t *dma3SrcAddr, *dma3DestAddr;
int16_t *dma4SrcAddr, *dma4DestAddr;

/* Variable to update DMA transfer status */
volatile uint16_t dmaDone = 0;


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
    
    /*
     * Interrupts that are used in this example are re-mapped to
     * ISR functions found within this file.
     */
    DMA_registerCallback(kDMA_CH1_INT,dmaCh1ISR,5);
    DMA_registerCallback(kDMA_CH2_INT,dmaCh2ISR,5);    
    DMA_registerCallback(kDMA_CH3_INT,dmaCh3ISR,5);
    DMA_registerCallback(kDMA_CH4_INT,dmaCh4ISR,5);
    
    /* Configure DMA for the transfer */
    initializeDMA();
    configureDMAChannels();

    /* Configure GPIO pins as SDFM pins */
    configureSDFMPins(pinMuxOption);

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

    /* Comparator Module */
    hlt = 0x7FFF;  /* Over value threshold settings */
    llt = 0x0000;  /* Under value threshold settings */

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


    /* config sdfm dma function , set dma source to direct. */
    SDFM_setDataReadyDMASource(mySDFM_BASE0, kSDFM_FILTER_1, kSDFM_DATA_READY_DMA_SOURCE_DIRECT);
    SDFM_enableDMA(mySDFM_BASE0, kSDFM_FILTER_1);
    SDFM_setDataReadyDMASource(mySDFM_BASE0, kSDFM_FILTER_2, kSDFM_DATA_READY_DMA_SOURCE_DIRECT);
    SDFM_enableDMA(mySDFM_BASE0, kSDFM_FILTER_2);
    SDFM_setDataReadyDMASource(mySDFM_BASE0, kSDFM_FILTER_3, kSDFM_DATA_READY_DMA_SOURCE_DIRECT);
    SDFM_enableDMA(mySDFM_BASE0, kSDFM_FILTER_3);
    SDFM_setDataReadyDMASource(mySDFM_BASE0, kSDFM_FILTER_4, kSDFM_DATA_READY_DMA_SOURCE_DIRECT);
    SDFM_enableDMA(mySDFM_BASE0, kSDFM_FILTER_4);

    /*
     * Enable Master filter bit: Unless this bit is set none of the filter
     * modules can be enabled. All the filter modules are synchronized when
     * master filter bit is enabled after individual filter modules are enabled.
     */
    SDFM_enableMasterFilter(mySDFM_BASE0);

    /*
     * PWM11.CMPC, PWM11.CMPD signals can synchronize SDFM1 filters and
     * PWM12.CMPC and PWM12.CMPD signals can synchronize SDFM2 filters. This
     * option is not being used in this example for SDFM1.
     */
    SDFM_disableExternalReset(mySDFM_BASE0, kSDFM_FILTER_1);
    SDFM_disableExternalReset(mySDFM_BASE0, kSDFM_FILTER_2);
    SDFM_disableExternalReset(mySDFM_BASE0, kSDFM_FILTER_3);
    SDFM_disableExternalReset(mySDFM_BASE0, kSDFM_FILTER_4);

    /*
     * Enable interrupts
     *
     * Following SDFM interrupts can be enabled / disabled using this function.
     *    Enable / disable comparator high threshold
     *    Enable / disable comparator low threshold
     *    Enable / disable modulator clock failure
     *    Enable / disable filter acknowledge
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


/* dmaCh1ISR - DMA Channel 1 ISR */
void dmaCh1ISR(DMA_Index_t index)
{
    dmaDone |= 0x0001;
    DMA_clearIntEndFlag(index);
}

/* dmaCh2ISR - DMA Channel 2 ISR */
void dmaCh2ISR(DMA_Index_t index)
{
    dmaDone |= 0x0002;
    DMA_clearIntEndFlag(index);
}

/* dmaCh3ISR - DMA Channel 3 ISR */
void dmaCh3ISR(DMA_Index_t index)
{
    dmaDone |= 0x0004;
    DMA_clearIntEndFlag(index);
}

/* dmaCh4ISR - DMA Channel 4 ISR */
void dmaCh4ISR(DMA_Index_t index)
{
    dmaDone |= 0x0008;
    DMA_clearIntEndFlag(index);
    
}

/* initializeDMA - Initialize DMA through hard reset */
void initializeDMA(void)
{
    /* Perform a hard reset on DMA */
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_DMA);
    DMA_initialize();

    /* Allow DMA to run free on emulation suspend */
    DMA_setEmulationMode(kDMA_EMULATION_FREE_RUN);
}

/* configureDMAChannels - Configure DMA channels 1,2,3, and 4 */
void configureDMAChannels(void)
{
    /* Initialize the DMA channel addresses */
    dma1SrcAddr = (int16_t *)&mySDFM_BASE0->SDDATA1 + 1;
    dma1DestAddr = &filter1Result[0];
    dma2SrcAddr = (int16_t *)&mySDFM_BASE0->SDDATA2 + 1;
    dma2DestAddr = &filter2Result[0];
    dma3SrcAddr = (int16_t *)&mySDFM_BASE0->SDDATA3 + 1;
    dma3DestAddr = &filter3Result[0];
    dma4SrcAddr = (int16_t *)&mySDFM_BASE0->SDDATA4 + 1;
    dma4DestAddr = &filter4Result[0];

    DMA_configAddresses(kDMA_INDEX_CH1, dma1DestAddr, dma1SrcAddr);
    DMA_configAddresses(kDMA_INDEX_CH2, dma2DestAddr, dma2SrcAddr);
    DMA_configAddresses(kDMA_INDEX_CH3, dma3DestAddr, dma3SrcAddr);
    DMA_configAddresses(kDMA_INDEX_CH4, dma4DestAddr, dma4SrcAddr);

    /*
     * Set up to use 16-bit data size
     * Pointers are based on 16-bit words
     * Increment by 1 (16 16-bit words)
     */

    /* BURST size = 1 | Source step size = 0 | Dest step size += 2 */
    DMA_configBurst(kDMA_INDEX_CH1, 1, 0, 2);
    DMA_configBurst(kDMA_INDEX_CH2, 1, 0, 2);
    DMA_configBurst(kDMA_INDEX_CH3, 1, 0, 2);
    DMA_configBurst(kDMA_INDEX_CH4, 1, 0, 2);

    /* Transfer size = 0x400 | Source step size = 0 | Dest step size += 2 */
    DMA_configTransfer(kDMA_INDEX_CH1, 0x400, 0, 2);
    DMA_configTransfer(kDMA_INDEX_CH2, 0x400, 0, 2);
    DMA_configTransfer(kDMA_INDEX_CH3, 0x400, 0, 2);
    DMA_configTransfer(kDMA_INDEX_CH4, 0x400, 0, 2);

    /* Configure mode for DMA channels 1-4 */

    /* DMA channel 1 */
    DMA_configTrigger(kDMA_INDEX_CH1, (DMA_Trigger_t)(kDMA_TRIGGER_SDFM1FLT1 + TRG_OFFSET));
    DMA_configMode(kDMA_INDEX_CH1, kDMA_MODE_PERIPH_TRIG);
    DMA_setDataSize(kDMA_INDEX_CH1, kDMA_DATASIZE_16BIT);   
    DMA_enableTrigger(kDMA_INDEX_CH1);   
    DMA_disableOverRunInterrupt(kDMA_INDEX_CH1);
    DMA_disableBegInterrupt(kDMA_INDEX_CH1);
    DMA_enableEndInterrupt(kDMA_INDEX_CH1);
    DMA_clearStatusFlag(kDMA_INDEX_CH1);    

    /* DMA channel 2 */
    DMA_configTrigger(kDMA_INDEX_CH2, (DMA_Trigger_t)(kDMA_TRIGGER_SDFM1FLT2 + TRG_OFFSET));
    DMA_configMode(kDMA_INDEX_CH2, kDMA_MODE_PERIPH_TRIG);
    DMA_setDataSize(kDMA_INDEX_CH2, kDMA_DATASIZE_16BIT);   
    DMA_enableTrigger(kDMA_INDEX_CH2);   
    DMA_disableOverRunInterrupt(kDMA_INDEX_CH2);
    DMA_disableBegInterrupt(kDMA_INDEX_CH2);
    DMA_enableEndInterrupt(kDMA_INDEX_CH2);
    DMA_clearStatusFlag(kDMA_INDEX_CH2); 

    /* DMA channel 3 */
    DMA_configTrigger(kDMA_INDEX_CH3, (DMA_Trigger_t)(kDMA_TRIGGER_SDFM1FLT3 + TRG_OFFSET));
    DMA_configMode(kDMA_INDEX_CH3, kDMA_MODE_PERIPH_TRIG);
    DMA_setDataSize(kDMA_INDEX_CH3, kDMA_DATASIZE_16BIT);   
    DMA_enableTrigger(kDMA_INDEX_CH3);   
    DMA_disableOverRunInterrupt(kDMA_INDEX_CH3);
    DMA_disableBegInterrupt(kDMA_INDEX_CH3);
    DMA_enableEndInterrupt(kDMA_INDEX_CH3);
    DMA_clearStatusFlag(kDMA_INDEX_CH3); 

    /* DMA channel 4 */
    DMA_configTrigger(kDMA_INDEX_CH4, (DMA_Trigger_t)(kDMA_TRIGGER_SDFM1FLT4 + TRG_OFFSET));
    DMA_configMode(kDMA_INDEX_CH4, kDMA_MODE_PERIPH_TRIG);
    DMA_setDataSize(kDMA_INDEX_CH4, kDMA_DATASIZE_16BIT);   
    DMA_enableTrigger(kDMA_INDEX_CH4);   
    DMA_disableOverRunInterrupt(kDMA_INDEX_CH4);
    DMA_disableBegInterrupt(kDMA_INDEX_CH4);
    DMA_enableEndInterrupt(kDMA_INDEX_CH4);
    DMA_clearStatusFlag(kDMA_INDEX_CH4);
    
    /*
     * Start DMA channels
     */
    DMA_startChannel(kDMA_INDEX_CH1);
    DMA_startChannel(kDMA_INDEX_CH2);
    DMA_startChannel(kDMA_INDEX_CH3);
    DMA_startChannel(kDMA_INDEX_CH4);
}

/*
 * End of file
 */
