/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
 
/*
 * 
 * \file mcan_ex2_receive.c
 * 
 * \brief MCAN receive using Rx Buffer
 * 
 *  This example demonstrates the MCAN receive function. Communication is done
 *  between two CAN nodes. The transmitting node could be another MCU or a
 *  CAN bus analysis tool capable of transmitting CAN FD frames. The transmit
 *  and receive pins of the MCAN module should be connected to a CAN
 *  transceiver. Nominal Bit Rate of 500 kbps & Data bit rate of 1 Mbps is used
 * 
 *  Only Standard frame with message ID 0x4 is received.
 * 
 *  If another HT32 MCU is used as the transmitter, mcan_ex6_transmit.c can be
 *  run on it for the transmit function.
 * 
 *  \b Hardware \b Required \n
 *   - A HT32F7D377 board with CAN transceiver
 * 
 *  \b External \b Connections \n
 *    Both nodes should communicate through CAN FD capable transceivers.
 * 
 *   - MCAN is on DEVICE_GPIO_PIN_CANRXA (MCANRXA)
 *   - and DEVICE_GPIO_PIN_CANTXA (MCANTXA)
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
//#include "hte_uart.h"

#ifdef HTE_DEVICE_HS32F7D377_CPU1
#include "hte_cpu1_ipc_com.h"
#else
#include "hte_cpu2_ipc_com.h"
#endif

#include "decodeCan.h"

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

#ifdef HTE_DEVICE_HS32F7D377_CPU1
//#define MCAN_BASE      MCANA_BASE
#define MCAN_BASE      MCANB_BASE
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

//#define MCAN_TXPIN 72
//#define MCAN_TXCFG GPIO_72_MCANB_TX     /* "pinConfig" for MCAN TX */

#define MCAN_TXPIN 38
#define MCAN_TXCFG GPIO_38_MCANB_TX     /* "pinConfig" for MCAN TX */

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

/*******************************************************************************
 * Variables
 ******************************************************************************/
int32_t     error = 0;
MCAN_RxBufElement_t rxMsg[1], rxMsg1;
MCAN_RxFIFOStatus_t RxFS;
int32_t loopCnt = 0U;


/*******************************************************************************
 * Codes
 ******************************************************************************/
void main()
{
    int i = 0;
    uint32_t dataBytes = 8; //64;
    MCAN_RxNewDataStatus_t newData;
    MCAN_TxBufElement_t    txMsg = {0};
    newData.statusLow = 0;

    /*Initialize device clock and peripherals */
    BOARD_init();
    //(void)UART_registerCallback(BOARD_DEBUG_CONSOLE_BASE, UART_userCallback, 0U);

#ifdef HTE_DEVICE_HS32F7D377_CPU1
    IPC_comInit();
#endif

    MCAN_pinMux();
    MCAN_setPclkEnable();
    txMsg.id = 0;
    txMsg.rtr      = 0U; /* Transmit data frame. */
    txMsg.xtd      = 0U; /* 11-bit standard identifier. */
    txMsg.esi      = 0U; /* ESI bit in CAN FD format depends only on error */
                         /* passive flag. */
    txMsg.dlc      = 8U; /* CAN + CAN FD: transmit frame has 0-8 data bytes. */
    txMsg.brs      = 0U; /* CAN FD frames transmitted with bit rate */
                         /* switching. */
    txMsg.fdf      = 0U; /* Frame transmitted in CAN FD format. */
    txMsg.efc      = 0U; /* Store Tx events. */
    txMsg.mm       = 0xAAU; /* Message Marker. */
    
    /*Initialize message to receive */
    rxMsg[loopCnt].id = 0U;
    rxMsg[loopCnt].rtr = 0U;
    rxMsg[loopCnt].xtd = 0U;
    rxMsg[loopCnt].esi = 0U;
    rxMsg[loopCnt].rxts = 0U;   /*  Rx Timestamp */
    rxMsg[loopCnt].dlc = 0U;
    rxMsg[loopCnt].brs = 0U;
    rxMsg[loopCnt].fdf = 0U;
    rxMsg[loopCnt].fidx = 0U;   /*  Filter Index */
                                /*(of matching Rx acceptance filter element) */
    rxMsg[loopCnt].anmf = 0U;   /*  Accepted Non-matching Frame */

    for(i = 0; i < dataBytes; i++)  /*  Initialize receive buffer to 0 */
    {
        rxMsg[loopCnt].data[i]  = 0;
    }

    /*Configure the MCAN Module. */
    MCANConfig();
    RxFS.num = 1;

    while(1){
        /*Get the New Data Status. */
        //while((newData.statusLow == 0) && (newData.statusHigh == 0))
        while(!RxFS.fillLvl)
        //while(!newData.statusLow)
        {
            //MCAN_getNewDataStatus((MCAN_Type *)MCAN_BASE, &newData);
            MCAN_getRxFIFOStatus((MCAN_Type *)MCAN_BASE, &RxFS);
        }

        //MCAN_readMsgRam((MCAN_Type *)MCAN_BASE, kMCAN_MEM_TYPE_BUF, 0U,0, &rxMsg1);
        //memmove(&rxMsg1,0,sizeof(rxMsg1));
        MCAN_readMsgRam((MCAN_Type *)MCAN_BASE, kMCAN_MEM_TYPE_FIFO, 0U,kMCAN_RX_FIFO_NUM_1, &rxMsg1);
				RxFS.fillLvl = 0;
        rxMsg[loopCnt] = rxMsg1;
				newData.statusLow = 0;
				newData.statusHigh = 0;
        MCAN_clearNewDataStatus((MCAN_Type *)MCAN_BASE, &newData);
        MCAN_writeRxFIFOAck((MCAN_Type *)MCAN_BASE, kMCAN_RX_FIFO_NUM_1,RxFS.getIdx);

        //DELAY(100000);
    
        //PRINTF("receive id:0x%lx dlc:0x%lx\r\n",rxMsg[0].id>>18,rxMsg[0].dlc);
        /* Enable Transmission interrupt. */
        //memcpy(txMsg,rxMsg[loopCnt],sizeof(txMsg));
        txMsg.id = backCanStandID(rxMsg[loopCnt].id);
		//printf("id1:0x%x",txMsg.id);
        //txMsg.id = rxMsg[loopCnt].id;	//((rxMsg[loopCnt].id<<4)&0xf0)|((rxMsg[loopCnt].id>>4)&0xf);
        memcpy(txMsg.data,rxMsg[loopCnt].data,sizeof(txMsg.data));
        decodeInst(txMsg.data);
        MCAN_writeMsgRam((MCAN_Type *)MCAN_BASE, kMCAN_MEM_TYPE_BUF, 1U, &txMsg);
        /* Add request for transmission. */
        MCAN_txBufAddReq((MCAN_Type *)MCAN_BASE, 1U);
        /* Wait till all the messages are transmitted. */
        while(MCAN_getTxBufReqPend((MCAN_Type *)MCAN_BASE))
        {
        }
    }
    
    while(1);
}


/* This function will configure MCAN module. */
static void MCANConfig(void)
{
    MCAN_RevisionId_t revId = {0};
    MCAN_InitParams_t initParams = {0};
    MCAN_ConfigParams_t configParams = {0};
    MCAN_MsgRAMConfigParams_t    msgRAMConfigParams = {0};
    MCAN_StdMsgIDFilterElement_t stdFiltelem = {0};
    MCAN_StdMsgIDFilterElement_t stdFiltelem1[2];
    MCAN_BitTimingParams_t       bitTimes = {0};

    /*Initialize MCAN Init parameters. */
    initParams.fdMode            = 0U;   //0x1U; /* FD operation enabled. */
    initParams.brsEnable         = 0U;   //0x1U; /* Bit rate switching for */
                                         /*transmissions enabled. */
    initParams.txpEnable         = 0x0U; /* Transmit pause disabled. */
    initParams.efbi              = 0x0U; /* Edge filtering disabled. */
    initParams.pxhddisable       = 0x0U; /* Protocol exception handling enabled */
    initParams.darEnable         = 0x0U; /* Enable Automatic retransmission of */
                                         /* messages not transmitted successfully */

    initParams.emulationEnable   = 0;   //0x1U; /* Emulation/Debug Suspend is enabled. */
    initParams.tdcEnable         = 0x0U; /* Transmitter Delay Compensation is */
                                         /* enabled. */
    initParams.wdcPreload        = 0xFFU; /* Start value of the Message RAM */
                                          /* Watchdog Counter preload. */

    /*Transmitter Delay Compensation parameters. */
    initParams.tdcConfig.tdcf    = 0xAU;
    initParams.tdcConfig.tdco    = 0x6U;

    /*Initialize MCAN Config parameters. */
    configParams.monEnable         = 0; /* Bus Monitoring Mode is disabled */
    configParams.asmEnable         = 0x0U;  /* Normal CAN operation. */
    configParams.tsPrescalar       = 0xFU;  /* Prescaler Value. */
    configParams.tsSelect          = 0x0U;  /* Timestamp counter value. */
    configParams.timeoutSelect     = kMCAN_TIMEOUT_SELECT_CONT;
    /*Time-out counter source select. */
    configParams.timeoutPreload    = 0xFFFFU; /* Start value of the Timeout */
                                              /* Counter. */
    configParams.timeoutCntEnable  = 0x0U; /* Time-out Counter is disabled. */
    configParams.filterConfig.rrfs = 0x1U; /* Reject all remote frames with */
                                           /* 29-bit extended IDs. */
    configParams.filterConfig.rrfe = 0x1U; /*  -Reject all remote frames with */
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
    msgRAMConfigParams.rxBufStartAddr       = MCAN_RX_BUFF_START_ADDR;
    /* Rx Buffer Start Address. */
    msgRAMConfigParams.rxBufElemSize        = kMCAN_ELEM_SIZE_64BYTES;
    /* Rx Buffer Element Size. */
    msgRAMConfigParams.rxFIFO0ElemSize      = kMCAN_ELEM_SIZE_64BYTES;
    /* Rx FIFO0 Element Size. */
    msgRAMConfigParams.rxFIFO1ElemSize      = kMCAN_ELEM_SIZE_64BYTES;
    /* Rx FIFO1 Element Size. */

    /* Initialize Rx Buffer Configuration parameters. */
    stdFiltelem.sfid2              = 0x00;  //0; //0; //0x1fffffff;    //0x0U; /* Standard Filter ID 2. */
    stdFiltelem.sfid1              = 0x02; //0x4U; /* Standard Filter ID 1. */
    stdFiltelem.sfec               = 2; //7; //0x7U; /* Store into Rx Buffer */
    stdFiltelem.sft                = 2; //0x0U; /* Range filter from SFID1 to SFID2 */

    //stdFiltelem1[0].sfid2              = 0; //0; //0x1fffffff;    //0x0U; /* Standard Filter ID 2. */
    //stdFiltelem1[0].sfid1              = 0x1; //0x4U; /* Standard Filter ID 1. */
    //stdFiltelem1[0].sfec               = 7; //0x7U; /* Store into Rx Buffer */
    //stdFiltelem1[0].sft                = 0x0U; /* Range filter from SFID1 to SFID2 */
    //stdFiltelem1[1].sfid2              = 0; //0; //0x1fffffff;    //0x0U; /* Standard Filter ID 2. */
    //stdFiltelem1[1].sfid1              = 0x2; //0x4U; /* Standard Filter ID 1. */
    //stdFiltelem1[1].sfec               = 7; //0x7U; /* Store into Rx Buffer */
    //stdFiltelem1[1].sft                = 0x0U; /* Range filter from SFID1 to SFID2 */
    /* Initialize bit timings */
    bitTimes.nomRatePrescalar   = 14U; /* Nominal Baud Rate Pre-scaler. */
    bitTimes.nomTimeSeg1        = 8U;  /* Nominal Time segment before SP */
    bitTimes.nomTimeSeg2        = 9U;  /* Nominal Time segment after SP */
    bitTimes.nomSynchJumpWidth  = 3U;  /* Nominal SJW */
    bitTimes.dataRatePrescalar  = 14U; /* Data Baud Rate Pre-scaler. */
    bitTimes.dataTimeSeg1       = 8;   //3U;  /* Data Time segment before SP */
    bitTimes.dataTimeSeg2       = 9;    //4U;  /* Data Time segment after SP */
    bitTimes.dataSynchJumpWidth = 3;    //2U;  /* Data SJW */
    
    /* Get MCANSS Revision ID. */
    MCAN_getRevisionId((MCAN_Type *)(MCAN_Type *)MCAN_BASE, &revId);

    /* Put MCAN in SW initialization mode. */
    MCAN_setOpMode((MCAN_Type *)MCAN_BASE, kMCAN_OPERATION_MODE_SW_INIT);

    /* Wait till MCAN is not initialized. */
    while (kMCAN_OPERATION_MODE_SW_INIT != MCAN_getOpMode((MCAN_Type *)MCAN_BASE));

    /* Initialize MCAN module. */
    MCAN_init((MCAN_Type *)MCAN_BASE, &initParams);

    /* Configure MCAN module. */
    MCAN_config((MCAN_Type *)MCAN_BASE, &configParams);

    /* Configure Bit timings. */
    MCAN_setBitTime((MCAN_Type *)MCAN_BASE, &bitTimes);

    /* Configure Message RAM Sections */
    MCAN_msgRAMConfig((MCAN_Type *)MCAN_BASE, &msgRAMConfigParams);

    /* Configure Standard ID filter element */
    MCAN_addStdMsgIDFilter((MCAN_Type *)MCAN_BASE, 0U, &stdFiltelem);
    //MCAN_addStdMsgIDFilter((MCAN_Type *)MCAN_BASE, 0U, &stdFiltelem1[0]);
    //MCAN_addStdMsgIDFilter((MCAN_Type *)MCAN_BASE, 0U, &stdFiltelem1[1]);

    /* Take MCAN out of the SW initialization mode */
    MCAN_setOpMode((MCAN_Type *)MCAN_BASE, kMCAN_OPERATION_MODE_NORMAL);

    while (kMCAN_OPERATION_MODE_NORMAL != MCAN_getOpMode((MCAN_Type *)MCAN_BASE));
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

