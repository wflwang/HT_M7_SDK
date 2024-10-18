/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
 
/*
 * 
 * \file mcan_ex3_mask_filter_receive.c
 * 
 * \brief MCAN External Reception (with mask filter) into RX-FIFO1
 * 
 *  This example demonstrates Receiving, with mask filter configuration.
 *  The transmitting node could be a CAN FD capable controller or a
 *  CAN bus analysis tool capable of transmitting CAN FD frames.
 *  Bits 0, 1 & 3 of the identifier are masked. So these bits can have any
 *  value. This is achieved by using stdFiltelem.sfid1 = 00000001111 and
 *  stdFiltelem.sfid2 (mask 0 for X ) = 11111110100, which means any message
 *  with an ID of 0b0000000X1XX are received and stored into the FIFO.
 *  i.e. Following STD IDs are received: 0x004, 0x005, 0x006, 0x007, 
 *  0x00C, 0x00D, 0x00E, 0x00F. All other IDs are not received.
 *  Classic bit-mask filter is used.
 *  This example may be used in conjunction with mcan_ex6_transmit.
 * 
 *  The transmit and receive pins of the MCAN module should be connected to a
 *  CAN Transceiver. Nominal Bit Rate of 500 kbps and Data bit rate of 1 Mbps
 *  is used.
 * 
 * 
 *  \b Hardware \b Required \n
 *   - A HS32F7D377 board with CAN transceiver
 * 
 *  \b External \b Connections \n
 *   Both nodes should communicate through CAN FD capable transceivers.
 * 
 *  \b Watch \b Variables \n
 *   - rxMsg
 * 
 * 
 */


/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "board.h"
#include "hte_sysctrl.h"
#include "hte_mcan.h"
#include "hte_pinmux.h"


#ifdef HTE_DEVICE_HS32F7D377_CPU1
#include "hte_cpu1_ipc_com.h"
#else
#include "hte_cpu2_ipc_com.h"
#endif


/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define NUM_OF_MSG                    (1U)
#define MCAN_STD_ID_FILT_START_ADDR   (0U)
#define MCAN_STD_ID_FILTER_NUM        (1U)
#define MCAN_FIFO_0_START_ADDR        (548U)
#define MCAN_FIFO_0_NUM               (NUM_OF_MSG)
#define MCAN_FIFO_0_WATERMARK         (NUM_OF_MSG)
#define MCAN_FIFO_1_START_ADDR        (748U)
#define MCAN_FIFO_1_NUM               (NUM_OF_MSG)
#define MCAN_FIFO_1_WATERMARK         (NUM_OF_MSG)
#define MCAN_RX_BUFF_START_ADDR       (948U)
#define MCAN_RX_FIFO0_ELEM_SIZE      (MCAN_ELEM_SIZE_64Bytes)
#define MCAN_RX_FIFO1_ELEM_SIZE      (MCAN_ELEM_SIZE_64Bytes)


#ifdef HTE_DEVICE_HS32F7D377_CPU1
#define MCAN_BASE      MCANA_BASE
//#define MCAN_BASE      MCANB_BASE
//#define MCAN_BASE      MCANC_BASE
#else
//#define MCAN_BASE      MCANA_BASE
#define MCAN_BASE      MCANB_BASE
//#define MCAN_BASE      MCANC_BASE
#endif

#if (MCAN_BASE == MCANA_BASE)

#define MCAN_RXPIN 129
#define MCAN_RXCFG GPIO_129_MCANA_RX    /* "pinConfig" for MCAN RX */

#define MCAN_TXPIN 128
#define MCAN_TXCFG GPIO_128_MCANA_TX    /* "pinConfig" for MCAN TX */

#elif(MCAN_BASE == MCANB_BASE)

#define MCAN_RXPIN 73
#define MCAN_RXCFG GPIO_73_MCANB_RX     /* "pinConfig" for MCAN RX */

#define MCAN_TXPIN 72
#define MCAN_TXCFG GPIO_72_MCANB_TX     /* "pinConfig" for MCAN TX */


#elif(MCAN_BASE == MCANC_BASE)

#define MCAN_RXPIN 75
#define MCAN_RXCFG GPIO_75_MCANC_RX     /* "pinConfig" for MCAN RX */

#define MCAN_TXPIN 74
#define MCAN_TXCFG GPIO_31_MCANC_TX     /* "pinConfig" for MCAN TX */

#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void MCAN_pinMux(void);
bool MCAN_setPclkEnable(void);
static void MCANConfig(void);
static void MCAN_Run(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/
int32_t     error = 0;
MCAN_RxBufElement_t rxMsg[NUM_OF_MSG], rxMsg1;
MCAN_RxFIFOStatus_t RxFS;
int32_t loopCnt = 0U;


/*******************************************************************************
 * Codes
 ******************************************************************************/
void main()
{
  
    /* Initialize device clock and peripherals */
    BOARD_init();

#ifdef HTE_DEVICE_HS32F7D377_CPU1
    IPC_comInit();
#endif

    MCAN_Run();

    /* Stop Application. */
    while(1);

}


static void MCAN_Run(void)
{
    int i = 0;
    uint32_t dataBytes = 64;

    /*
     * Initialize receive data structure
     * (not to be confused with RX Buffer inside the MCAN module)
     */
    rxMsg[loopCnt].id = 0U;
    rxMsg[loopCnt].rtr = 0U;
    rxMsg[loopCnt].xtd = 0U;
    rxMsg[loopCnt].esi = 0U;
    rxMsg[loopCnt].rxts = 0U;
    rxMsg[loopCnt].dlc = 0U;
    rxMsg[loopCnt].brs = 0U;
    rxMsg[loopCnt].fdf = 0U;
    rxMsg[loopCnt].fidx = 0U;
    rxMsg[loopCnt].anmf = 0U;
    for(i = 0; i < dataBytes; i++)
    {
        rxMsg[loopCnt].data[i]  = 0;
    }

    /* Configure GPIO */
    MCAN_pinMux();
    
    /* Set clock */
    MCAN_setPclkEnable();  
    
    /* Configure the MCAN Module. */
    MCANConfig();
  
    /* Get the New Data Status of FIFO 1. */
    RxFS.num = 1;
    while(!RxFS.fillLvl)
    {
        MCAN_getRxFIFOStatus((MCAN_Type *)MCAN_BASE, &RxFS);
    }

    MCAN_readMsgRam((MCAN_Type *)MCAN_BASE, kMCAN_MEM_TYPE_FIFO, 0U,
                        kMCAN_RX_FIFO_NUM_1, &rxMsg1);

    rxMsg[loopCnt] = rxMsg1;
    RxFS.num = kMCAN_RX_FIFO_NUM_1;

    MCAN_writeRxFIFOAck((MCAN_Type *)MCAN_BASE, kMCAN_RX_FIFO_NUM_1,
                        RxFS.getIdx);

    DELAY(100000);

    PRINTF("receive id:0x%lx dlc:0x%lx \r\n", rxMsg[0].id >> 18, rxMsg[0].dlc);
}


static void MCANConfig(void)
{
    MCAN_InitParams_t initParams;
    MCAN_MsgRAMConfigParams_t    msgRAMConfigParams;
    MCAN_StdMsgIDFilterElement_t stdFiltelem;
    MCAN_BitTimingParams_t       bitTimes;

    /* Initialize MCAN Init parameters. */
    initParams.fdMode            = 0x1U; /* FD operation enabled. */
    initParams.brsEnable         = 0x1U; /* Bit rate switching enabled. */

    /* Initialize Message RAM Sections Configuration Parameters */
    msgRAMConfigParams.flssa                = MCAN_STD_ID_FILT_START_ADDR;
    /* Standard ID Filter List Start Address (0). */
    msgRAMConfigParams.lss                  = MCAN_STD_ID_FILTER_NUM;
    /* Standard ID Filter List Size (1). */
    msgRAMConfigParams.rxFIFO1startAddr     = MCAN_FIFO_1_START_ADDR;
    /* Rx FIFO1 Start Address (748U). */
    msgRAMConfigParams.rxFIFO1size          = MCAN_FIFO_1_NUM;
    /* Number of Rx FIFO elements (1). */
    msgRAMConfigParams.rxFIFO1waterMark     = MCAN_FIFO_1_WATERMARK;
    /* Level for Rx FIFO 1 watermark interrupt (1). */
    msgRAMConfigParams.rxFIFO1OpMode        = 0U;
    /* FIFO blocking mode. */
    msgRAMConfigParams.rxFIFO1ElemSize      = kMCAN_ELEM_SIZE_64BYTES;
    /* Rx FIFO1 Element Size. RBDS field of MCAN_RXESC Register */

    /* Initialize Rx Buffer Filter element Configuration parameters. */
    stdFiltelem.sfid2              = 0x7F4U; /* Standard ID Filter Mask. */
    /* A 0 in any bit-position indicates "don't care" */
    stdFiltelem.sfid1              = 0x00FU; /* Standard ID Filter */
    stdFiltelem.sfec               = 0x6U; /* Store into FIFO 1. */
    stdFiltelem.sft                = 0x2U; /* SFID1 = filter; SFID2 = mask */

    /* Initialize bit timings. */
    bitTimes.nomRatePrescalar   = 14U; /* Nominal Baud Rate Pre-scaler. */
    bitTimes.nomTimeSeg1        = 8U; /* Nominal Time segment before SP */
    bitTimes.nomTimeSeg2        = 9U; /* Nominal Time segment after SP */
    bitTimes.nomSynchJumpWidth  = 3U; /* Nominal SJW */
    bitTimes.dataRatePrescalar  = 14U; /* Data Baud Rate Pre-scaler. */
    bitTimes.dataTimeSeg1       = 3U; /* Data Time segment before SP */
    bitTimes.dataTimeSeg2       = 4U; /* Data Time segment after SP */
    bitTimes.dataSynchJumpWidth = 3U; /* Data SJW */
    
    /* Put MCAN in SW initialization mode. */
    MCAN_setOpMode((MCAN_Type *)MCAN_BASE, kMCAN_OPERATION_MODE_SW_INIT);

    /* Wait till MCAN is not initialized. */
    while (kMCAN_OPERATION_MODE_SW_INIT != MCAN_getOpMode((MCAN_Type *)MCAN_BASE))
    {}

    /* Initialize MCAN module. */
    MCAN_init((MCAN_Type *)MCAN_BASE, &initParams);

    /* Configure Bit timings. */
    MCAN_setBitTime((MCAN_Type *)MCAN_BASE, &bitTimes);

    /* Configure Message RAM Sections */
    MCAN_msgRAMConfig((MCAN_Type *)MCAN_BASE, &msgRAMConfigParams);

    /* Configure Standard ID filter element */
    MCAN_addStdMsgIDFilter((MCAN_Type *)MCAN_BASE, 0U, &stdFiltelem);

    /* Take MCAN out of the SW initialization mode */
    MCAN_setOpMode((MCAN_Type *)MCAN_BASE, kMCAN_OPERATION_MODE_NORMAL);

    while (kMCAN_OPERATION_MODE_NORMAL != MCAN_getOpMode((MCAN_Type *)MCAN_BASE))
    {

    }
}

void MCAN_pinMux(void)
{
#ifdef HTE_DEVICE_HS32F7D377_CPU1
    /* Configuring the GPIOs for MCAN. */
    GPIO_setPinConfig(MCAN_TXCFG);
    GPIO_setPinConfig(MCAN_RXCFG);
    GPIO_setMasterCore(MCAN_TXPIN, kGPIO_CORE_CPU1);
    GPIO_setMasterCore(MCAN_RXPIN, kGPIO_CORE_CPU1);
#else
     /* Configuring the GPIOs for MCAN. */
    IPC_com_GPIO_setPinConfig(MCAN_TXCFG);
    IPC_com_GPIO_setPinConfig(MCAN_RXCFG);
    IPC_com_GPIO_setMasterCore(MCAN_TXPIN, kGPIO_CORE_CPU2);
    IPC_com_GPIO_setMasterCore(MCAN_RXPIN, kGPIO_CORE_CPU2);   
    
#endif
}

bool MCAN_setPclkEnable(void)
{
#ifdef HTE_DEVICE_HS32F7D377_CPU1
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_MCANA);
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_MCANB);
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_MCANC);
    return MCAN_MsgRamInit();
#else
    uint16_t timeout = 1000;

    IPC_com_selectCPUForPeripheral((IPC_SYSCTRL_PeripheralCpusel_t)(kIPC_SYSCTRL_PERIPH_CPUSEL_MCANA ),kIPC_SYSCTRL_CPUSEL_CPU1);
    IPC_com_selectCPUForPeripheral((IPC_SYSCTRL_PeripheralCpusel_t)(kIPC_SYSCTRL_PERIPH_CPUSEL_MCANB ),kIPC_SYSCTRL_CPUSEL_CPU1);
    IPC_com_selectCPUForPeripheral((IPC_SYSCTRL_PeripheralCpusel_t)(kIPC_SYSCTRL_PERIPH_CPUSEL_MCANC ),kIPC_SYSCTRL_CPUSEL_CPU1);

    IPC_com_SYSCTRL_enablePeripheral(kIPC_SYSCTL_PERIPH_CLK_MCANA);
    IPC_com_SYSCTRL_enablePeripheral(kIPC_SYSCTL_PERIPH_CLK_MCANB);
    IPC_com_SYSCTRL_enablePeripheral(kIPC_SYSCTL_PERIPH_CLK_MCANC);

    IPC_com_SYSCTRL_initCANSram();

    while(timeout--)
    {
        if(IPC_com_SYSCTRL_getCANSramInitDone())
        {
            break;
        }
    }
    IPC_com_selectCPUForPeripheral((IPC_SYSCTRL_PeripheralCpusel_t)(kIPC_SYSCTRL_PERIPH_CPUSEL_MCANA ),kIPC_SYSCTRL_CPUSEL_CPU2);
    IPC_com_selectCPUForPeripheral((IPC_SYSCTRL_PeripheralCpusel_t)(kIPC_SYSCTRL_PERIPH_CPUSEL_MCANB ),kIPC_SYSCTRL_CPUSEL_CPU2);
    IPC_com_selectCPUForPeripheral((IPC_SYSCTRL_PeripheralCpusel_t)(kIPC_SYSCTRL_PERIPH_CPUSEL_MCANC ),kIPC_SYSCTRL_CPUSEL_CPU2);

    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_MCANA);
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_MCANB);
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_MCANC);
    
    return (timeout == 0? false:true);
#endif
}
