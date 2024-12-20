/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*
 * 
 * \file mcan_ex7_external_trx.c
 * 
 * \brief MCAN transmit and recive Example
 * 
 *  This example shows the MCAN transmit and recive functionality. The normal
 *  mode is entered. The sent message should be received by another node.
 *  Use the last address of memory for Rx buffer.
 * 
 *  \b Hardware \b Required \n
 *   - A HT32F7D377 board with CAN transceiver
 * 
 *  \b External \b Connections \n
 *   Both nodes should communicate through CAN FD capable transceivers.
 *
 *  \b Watch \b Variables \n
 *   - error - Checks if there is an error that occurred when the data was
 *             sent or recived.
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
#define MCAN_STD_ID_FILT_START_ADDR     (0x0U)
#define MCAN_STD_ID_FILTER_NUM          (1U)
#define MCAN_EXT_ID_FILT_START_ADDR     (0x14U)
#define MCAN_EXT_ID_FILTER_NUM          (1U)
#define MCAN_TX_BUFF_START_ADDR         (0x80U)
#define MCAN_TX_BUFF_SIZE               (10U)
#define MCAN_FIFO_1_START_ADDR          (0xc0U)
#define MCAN_FIFO_1_NUM                 (10U)
#define MCAN_TX_EVENT_START_ADDR        (0x100U)
#define MCAN_TX_EVENT_SIZE              (10U)
#define MCAN_EXT_ID_AND_MASK            (0x1FFFFFFFU)
#define MCAN_RX_BUFF_START_ADDR         (948U)
#define MCAN_FIFO_0_START_ADDR          (548U)
#define MCAN_FIFO_0_NUM                 (5U)
#define MCAN_MSG_INT                    (0x81200)

/* send device base */
//#define MCAN_S_BASE      MCANA_BASE
//#define MCAN_S_BASE      MCANB_BASE
#define MCAN_S_BASE      MCANC_BASE


/* recive device base */
//#define MCAN_R_BASE      MCANA_BASE
#define MCAN_R_BASE      MCANB_BASE
//#define MCAN_R_BASE      MCANC_BASE


/*  TX PIN & RX PIN select */
#if (MCAN_S_BASE == MCANA_BASE)

#define MCAN_S_RXPIN 129
#define MCAN_S_RXCFG GPIO_129_MCANA_RX    /* "pinConfig" for MCAN RX */

#define MCAN_S_TXPIN 128
#define MCAN_S_TXCFG GPIO_128_MCANA_TX    /* "pinConfig" for MCAN TX */

#elif(MCAN_S_BASE == MCANB_BASE)

#define MCAN_S_RXPIN 73
#define MCAN_S_RXCFG GPIO_73_MCANB_RX     /* "pinConfig" for MCAN RX */

#define MCAN_S_TXPIN 72
#define MCAN_S_TXCFG GPIO_72_MCANB_TX     /* "pinConfig" for MCAN TX */


#elif(MCAN_S_BASE == MCANC_BASE)

#define MCAN_S_RXPIN 75
#define MCAN_S_RXCFG GPIO_75_MCANC_RX     /* "pinConfig" for MCAN RX */

#define MCAN_S_TXPIN 74
#define MCAN_S_TXCFG GPIO_74_MCANC_TX     /* "pinConfig" for MCAN TX */

#endif


#if (MCAN_R_BASE == MCANA_BASE)

#define MCAN_R_RXPIN 129
#define MCAN_R_RXCFG GPIO_129_MCANA_RX    /* "pinConfig" for MCAN RX */

#define MCAN_R_TXPIN 128
#define MCAN_R_TXCFG GPIO_128_MCANA_TX    /* "pinConfig" for MCAN TX */

#elif(MCAN_R_BASE == MCANB_BASE)

#define MCAN_R_RXPIN 73
#define MCAN_R_RXCFG GPIO_73_MCANB_RX     /* "pinConfig" for MCAN RX */

#define MCAN_R_TXPIN 72
#define MCAN_R_TXCFG GPIO_72_MCANB_TX     /* "pinConfig" for MCAN TX */


#elif(MCAN_R_BASE == MCANC_BASE)

#define MCAN_R_RXPIN 75
#define MCAN_R_RXCFG GPIO_75_MCANC_RX     /* "pinConfig" for MCAN RX */

#define MCAN_R_TXPIN 74
#define MCAN_R_TXCFG GPIO_74_MCANC_TX     /* "pinConfig" for MCAN TX */

#endif


/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void MCAN_pinMux(void);
bool MCAN_setPclkEnable(void);
static bool MCAN_check(MCAN_TxBufElement_t *txMsg,MCAN_RxBufElement_t *rxMsg);
static void MCAN_send(MCAN_Type *base,MCAN_TxBufElement_t *txMsg);
static void MCAN_recive(MCAN_Type *base,MCAN_RxBufElement_t *rxMsg);
static void MCANConfig(MCAN_Type* base);
static void MCAN_Run(void);


/*******************************************************************************
 * Variables
 ******************************************************************************/
volatile uint16_t monEn = 0x0;
volatile unsigned long msgCount = 0;
volatile unsigned long error = 0;
MCAN_Type *canbase[3] = {MCANA,MCANB,MCANC};


/*******************************************************************************
 * Codes
 ******************************************************************************/
void main(void)
{
    /* Initialize device clock and peripherals */
    BOARD_init();

#ifdef HTE_DEVICE_HS32F7D377_CPU1
    IPC_comInit();
#endif
    canbase[0] = MCANA;
    
    MCAN_Run();

    /* Stop Application. */
    while(1);
}

static void MCAN_Run(void)
{
    MCAN_TxBufElement_t    txMsg = {0};
    MCAN_RxBufElement_t    rxMsg = {0};
    
    /* Initialize message to transmit. */
    txMsg.id       = ((uint32_t)(4)) << 18U; /* Identifier Value. */
    txMsg.rtr      = 0U; /* Transmit data frame. */
    txMsg.xtd      = 0U; /* 11-bit standard identifier. */
    txMsg.esi      = 0U; /* ESI bit in CAN FD format depends only on error */
                         /* passive flag. */
    txMsg.dlc      = 4U; /* CAN + CAN FD: transmit frame has 0-8 data bytes. */
    txMsg.brs      = 1U; /* CAN FD frames transmitted with bit rate */
                         /* switching. */
    txMsg.fdf      = 1U; /* Frame transmitted in CAN FD format. */
    txMsg.efc      = 1U; /* Store Tx events. */
    txMsg.mm       = 0xAAU; /* Message Marker. */

    /* Data bytes. */
    txMsg.data[0]  = 0x12;
    txMsg.data[1]  = 0x34;
    txMsg.data[2]  = 0x56;
    txMsg.data[3]  = 0x78;
    
    /* Configure GPIO */
    MCAN_pinMux();
    
    /* Set clock */
    MCAN_setPclkEnable();

    /* Configure MCAN send device & recive device. */
    MCANConfig((MCAN_Type *)MCAN_S_BASE);
    MCANConfig((MCAN_Type *)MCAN_R_BASE);
    DELAY(5000);
    MCAN_send((MCAN_Type *)MCAN_S_BASE,&txMsg);
    PRINTF("send id:0x%lx dlc:0x%lx\r\n", txMsg.id >> 18, txMsg.dlc);
    MCAN_recive((MCAN_Type *)MCAN_R_BASE,&rxMsg);
    PRINTF("receive id:0x%lx dlc:0x%lx\r\n", rxMsg.id >> 18, rxMsg.dlc);
    /* 
     * Check that received data matches sent data.
     * Device will halt here during debug if data doesn't match.
     */
    if(MCAN_check(&txMsg,&rxMsg))
    {
        /*
         * Device will halt here if transmitted and received data are
         * not same.
         */
        while(1);
    }
    else
    {
        /* Increment message count if message is received. */
        msgCount++;
    }
    
    while(1);
}

static bool MCAN_check(MCAN_TxBufElement_t *txMsg,MCAN_RxBufElement_t *rxMsg)
{
    /*
     * Check that received data matches sent data.
     * Device will halt here during debug if data doesn't match.
     */
    if((txMsg->data[0] != rxMsg->data[0]) ||
       (txMsg->data[1] != rxMsg->data[1]) ||
       (txMsg->data[2] != rxMsg->data[2]) ||
       (txMsg->data[3] != rxMsg->data[3]))
    {
        /* Check fail! */
        return 1;
    }
    else
    {
        /* Check sucess! */
        return 0;
    }
}


static void MCAN_send(MCAN_Type *base,MCAN_TxBufElement_t *txMsg)
{
    /* Write Tx Message to the Message RAM. */
    MCAN_writeMsgRam((MCAN_Type *)base, kMCAN_MEM_TYPE_BUF, 1U, txMsg);

    /* Enable Transmission interrupt. */
    MCAN_txBufTransIntrEnable((MCAN_Type *)base, 1U,1U);

    /* Add request for transmission. */
    MCAN_txBufAddReq((MCAN_Type *)base, 1U);
}

static void MCAN_recive(MCAN_Type *base,MCAN_RxBufElement_t *rxMsg)
{
    MCAN_RxNewDataStatus_t newData = {0};
  
    /* Get the New Data Status. */
    while((newData.statusLow == 0) && (newData.statusHigh == 0))
    {
        MCAN_getNewDataStatus((MCAN_Type *)base, &newData);
    }
 
    /* Read Message RAM. */
    MCAN_readMsgRam((MCAN_Type *)base, kMCAN_MEM_TYPE_BUF, 0U, kMCAN_RX_FIFO_NUM_1,
                    rxMsg);
}

/* This function will configure MCAN module. */
static void MCANConfig(MCAN_Type *base)
{
    MCAN_RevisionId_t revId = {0};
    MCAN_InitParams_t initParams = {0};
    MCAN_ConfigParams_t configParams = {0};
    MCAN_MsgRAMConfigParams_t    msgRAMConfigParams = {0};
    MCAN_StdMsgIDFilterElement_t stdFiltelem = {0};
    MCAN_BitTimingParams_t       bitTimes = {0};

    /* Initialize MCAN Init parameters. */
    initParams.fdMode            = 0x1U; /* FD operation enabled. */
    initParams.brsEnable         = 0x1U; /* Bit rate switching for */
                                         /* transmissions enabled. */
    initParams.txpEnable         = 0x0U; /* Transmit pause disabled. */
    initParams.efbi              = 0x0U; /* Edge filtering disabled. */
    initParams.pxhddisable       = 0x0U; /* Protocol exception handling enabled */
    initParams.darEnable         = 0x1U; /* Enable Automatic retransmission of */
                                       /* messages not transmitted successfully */

    initParams.emulationEnable   = 0x1U; /* Emulation/Debug Suspend is enabled. */
    initParams.tdcEnable         = 0x0U; /* Transmitter Delay Compensation is */
                                         /* enabled. */
    initParams.wdcPreload        = 0xFFU; /* Start value of the Message RAM */
                                          /* Watchdog Counter preload. */

    /* Transmitter Delay Compensation parameters. */
    initParams.tdcConfig.tdcf    = 0xAU;
    initParams.tdcConfig.tdco    = 0x6U;

    /* Initialize MCAN Config parameters. */
    configParams.monEnable         = monEn; /* Bus Monitoring Mode is disabled */
    configParams.asmEnable         = 0x0U;  /* Normal CAN operation. */
    configParams.tsPrescalar       = 0xFU;  /* Prescaler Value. */
    configParams.tsSelect          = 0x0U;  /* Timestamp counter value. */
    configParams.timeoutSelect     = kMCAN_TIMEOUT_SELECT_CONT;
    /* Time-out counter source select. */
    configParams.timeoutPreload    = 0xFFFFU; /* Start value of the Timeout */
                                              /* Counter. */
    configParams.timeoutCntEnable  = 0x0U; /* Time-out Counter is disabled. */
    configParams.filterConfig.rrfs = 0x1U; /* Reject all remote frames with */
                                           /* 29-bit extended IDs. */
    configParams.filterConfig.rrfe = 0x1U; /* Reject all remote frames with */
                                           /* 11-bit standard IDs. */
    configParams.filterConfig.anfe = 0x1U; /* Accept in Rx FIFO 1. */
    configParams.filterConfig.anfs = 0x1U; /* Accept in Rx FIFO 1. */

    /* Initialize Message RAM Sections Configuration Parameters. */
    msgRAMConfigParams.flssa                = MCAN_STD_ID_FILT_START_ADDR;
    /* Standard ID Filter List Start Address. */
    msgRAMConfigParams.lss                  = MCAN_STD_ID_FILTER_NUM;
    /* List Size: Standard ID. */
    msgRAMConfigParams.flesa                = MCAN_EXT_ID_FILT_START_ADDR;
    /* Extended ID Filter List Start Address. */
    msgRAMConfigParams.lse                  = MCAN_EXT_ID_FILTER_NUM;
    /* List Size: Extended ID. */
    msgRAMConfigParams.txStartAddr          = MCAN_TX_BUFF_START_ADDR;
    /* Tx Buffers Start Address. */
    msgRAMConfigParams.txBufNum             = MCAN_TX_BUFF_SIZE;
    /* Number of Dedicated Transmit Buffers. */
    msgRAMConfigParams.txFIFOSize           = 0U; /* No Tx FIFO/Queue. */
    msgRAMConfigParams.txBufMode            = 0U; /* Tx FIFO operation */
    msgRAMConfigParams.txBufElemSize        = kMCAN_ELEM_SIZE_64BYTES;
    /* Tx Buffer Element Size. */
    msgRAMConfigParams.txEventFIFOStartAddr = MCAN_TX_EVENT_START_ADDR;
    /* Tx Event FIFO Start Address. */
    msgRAMConfigParams.txEventFIFOSize      = MCAN_TX_BUFF_SIZE;
    /* Event FIFO Size. */
    msgRAMConfigParams.txEventFIFOWaterMark = 3U;
    /* Level for Tx Event FIFO watermark interrupt. */
    msgRAMConfigParams.rxFIFO0startAddr     = MCAN_FIFO_0_START_ADDR;
    /* Rx FIFO0 Start Address. */
    msgRAMConfigParams.rxFIFO0size          = MCAN_FIFO_0_NUM;
    /* Number of Rx FIFO elements. */
    msgRAMConfigParams.rxFIFO0waterMark     = 3U; /* Rx FIFO0 Watermark. */
    msgRAMConfigParams.rxFIFO0OpMode        = 0U; /* FIFO blocking mode. */
    msgRAMConfigParams.rxFIFO1startAddr     = MCAN_FIFO_1_START_ADDR;
    /* Rx FIFO1 Start Address. */
    msgRAMConfigParams.rxFIFO1size          = MCAN_FIFO_1_NUM;
    /* Number of Rx FIFO elements. */
    msgRAMConfigParams.rxFIFO1waterMark     = 3U; /* Level for Rx FIFO 1 */
                                                  /* watermark interrupt. */
    msgRAMConfigParams.rxFIFO1OpMode        = 0U; /* FIFO blocking mode. */
    /* Rx Buffer Start Address. */
    msgRAMConfigParams.rxBufStartAddr       = MCAN_RX_BUFF_START_ADDR;
    /* Rx Buffer Element Size. */
    msgRAMConfigParams.rxBufElemSize        = kMCAN_ELEM_SIZE_64BYTES;
    /* Rx FIFO0 Element Size. */
    msgRAMConfigParams.rxFIFO0ElemSize      = kMCAN_ELEM_SIZE_64BYTES;
    /* Rx FIFO1 Element Size. */
    msgRAMConfigParams.rxFIFO1ElemSize      = kMCAN_ELEM_SIZE_64BYTES;


    /* Initialize Rx Buffer Configuration parameters. */
    stdFiltelem.sfid2              = 0x0U; /* Standard Filter ID 2. */
    stdFiltelem.sfid1              = 0x4U; /* Standard Filter ID 1. */
    stdFiltelem.sfec               = 0x7U; /* Store into Rx Buffer */
    stdFiltelem.sft                = 0x0U; /* Range filter from SFID1 to SFID2 */

    /* Initialize bit timings */
    bitTimes.nomRatePrescalar   = 14U; /* Nominal Baud Rate Pre-scaler. */
    bitTimes.nomTimeSeg1        = 3U; /* Nominal Time segment before SP */
    bitTimes.nomTimeSeg2        = 9U; /* Nominal Time segment after SP */
    bitTimes.nomSynchJumpWidth  = 8U; /* Nominal SJW */
    bitTimes.dataRatePrescalar  = 14U; /* Data Baud Rate Pre-scaler. */
    bitTimes.dataTimeSeg1       = 2U; /* Data Time segment before SP */
    bitTimes.dataTimeSeg2       = 4U; /* Data Time segment after SP */
    bitTimes.dataSynchJumpWidth = 3U; /* Data SJW */
    
    /* Get MCANSS Revision ID. */
    MCAN_getRevisionId((MCAN_Type *)base, &revId);

    /* Put MCAN in SW initialization mode. */
    MCAN_setOpMode((MCAN_Type *)base, kMCAN_OPERATION_MODE_SW_INIT);

    /* Wait till MCAN is not initialized. */
    while (kMCAN_OPERATION_MODE_SW_INIT != MCAN_getOpMode((MCAN_Type *)base));

    /* Initialize MCAN module. */
    MCAN_init((MCAN_Type *)base, &initParams);

    /* Configure MCAN module. */
    MCAN_config((MCAN_Type *)base, &configParams);

    /* Configure Bit timings. */
    MCAN_setBitTime((MCAN_Type *)base, &bitTimes);

    /* Set Extended ID Mask. */
    MCAN_setExtIDAndMask((MCAN_Type *)base, MCAN_EXT_ID_AND_MASK);

    /* Configure Message RAM Sections */
    MCAN_msgRAMConfig((MCAN_Type *)base, &msgRAMConfigParams);

    /* Configure Standard ID filter element */
    MCAN_addStdMsgIDFilter((MCAN_Type *)base, 0U, &stdFiltelem);

    /* Enable internal loopback mode */
//    MCAN_lpbkModeEnable((MCAN_Type *)base, MCAN_LPBK_MODE_EXTERNAL, true);
    
    /* Take MCAN out of the SW initialization mode */
    MCAN_setOpMode((MCAN_Type *)base, kMCAN_OPERATION_MODE_NORMAL);

    while (kMCAN_OPERATION_MODE_NORMAL != MCAN_getOpMode((MCAN_Type *)base));
}

void MCAN_pinMux(void)
{
#ifdef HTE_DEVICE_HS32F7D377_CPU1
    /* Configuring the GPIOs for MCAN. */
    GPIO_setPinConfig(MCAN_S_TXCFG);
    GPIO_setPinConfig(MCAN_S_RXCFG);
    GPIO_setMasterCore(MCAN_S_TXPIN, kGPIO_CORE_CPU1);
    GPIO_setMasterCore(MCAN_S_RXPIN, kGPIO_CORE_CPU1);
    
    GPIO_setPinConfig(MCAN_R_TXCFG);
    GPIO_setPinConfig(MCAN_R_RXCFG);
    GPIO_setMasterCore(MCAN_R_TXPIN, kGPIO_CORE_CPU1);
    GPIO_setMasterCore(MCAN_R_RXPIN, kGPIO_CORE_CPU1); 
#else
    /* Configuring the GPIOs for MCAN. */
    IPC_com_GPIO_setPinConfig(MCAN_S_TXCFG);
    IPC_com_GPIO_setPinConfig(MCAN_S_RXCFG);
    IPC_com_GPIO_setMasterCore(MCAN_S_TXPIN, kGPIO_CORE_CPU2);
    IPC_com_GPIO_setMasterCore(MCAN_S_RXPIN, kGPIO_CORE_CPU2);   
 
    IPC_com_GPIO_setPinConfig(MCAN_R_TXCFG);
    IPC_com_GPIO_setPinConfig(MCAN_R_RXCFG);
    IPC_com_GPIO_setMasterCore(MCAN_R_TXPIN, kGPIO_CORE_CPU2);
    IPC_com_GPIO_setMasterCore(MCAN_R_RXPIN, kGPIO_CORE_CPU2);       
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
