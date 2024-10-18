/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*
 * 
 * \file mcan_ex4_classic_transmit.c
 * 
 * \brief MCAN Classic frames transmission using Tx Buffer
 * 
 *  This simple example shows external communication between the MCAN module
 *  and another CAN node. It shows how to transmit classic CAN frames.
 *  The GPIOs of MCAN should be connected to a CAN Transceiver.
 *  Bit Rate is 500 kbps. Extended Identifier 0x1FFFFF46 is transmitted with
 *  8 data bytes.
 * 
 *  \b Hardware \b Required \n
 *   - A HS32F7D377 board with CAN transceiver
 * 
 *  \b External \b Connections \n
 *   Both nodes should communicate through CAN transceivers.
 * 
 *  \b Watch \b Variables \n
 *   - txMsg
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
#define MCAN_TX_BUFF_START_ADDR       (148U)
#define MCAN_TX_BUFF_SIZE             (NUM_OF_MSG)
#define MCAN_EXT_ID_AND_MASK          (0x1FFFFFFFU)
#define MCAN_TX_BUFF_ELEM_SIZE       (MCAN_ELEM_SIZE_8Bytes)


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
static void MCAN_Run(void);


/*******************************************************************************
 * Variables
 ******************************************************************************/
int32_t     error = 0;
MCAN_TxBufElement_t txMsg[NUM_OF_MSG];
int32_t loopCnt = 0U;

    
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

    MCAN_Run();

    /* Stop Application. */
    while(1);
}



void MCAN_Run(void)
{
    int i = 0;
    uint32_t dataBytes = 8;

    /* Initialize message to transmit. */
    txMsg[loopCnt].id       = ((uint32_t)(0x1fFFFF46)) ;
    txMsg[loopCnt].rtr      = 0U;
    txMsg[loopCnt].xtd      = 0U;   //1U; normal/ext
    txMsg[loopCnt].esi      = 0U;
    txMsg[loopCnt].dlc      = 8U;
    txMsg[loopCnt].brs      = 0U;
    txMsg[loopCnt].fdf      = 0U;
    txMsg[loopCnt].efc      = 1U;
    txMsg[loopCnt].mm       = 0xAAU;
    txMsg[loopCnt].data[i]  = 0x1;
    for(i = 1; i < dataBytes; i++)
    {
        txMsg[loopCnt].data[i]  = txMsg[loopCnt].data[i-1] + 1;
    }
    i = 0;

    /*Configure GPIO */
    MCAN_pinMux();
    
    /*Set clock */
    MCAN_setPclkEnable();
    
    /* Configure the MCAN Module. */
    MCANConfig();

    /* Write message to Message RAM. */
    MCAN_writeMsgRam((MCAN_Type *)MCAN_BASE, kMCAN_MEM_TYPE_BUF, loopCnt,
                     &txMsg[loopCnt]);

    while(1)
    {
        /* Add request for transmission. */
        MCAN_txBufAddReq((MCAN_Type *)MCAN_BASE, 0U);
        
        /* Wait till all the messages are transmitted. */
        while(MCAN_getTxBufReqPend((MCAN_Type *)MCAN_BASE))
        {
        }
    }

}


static void MCANConfig(void)
{   
    MCAN_InitParams_t initParams = {0};
    MCAN_MsgRAMConfigParams_t    msgRAMConfigParams = {0};
    MCAN_BitTimingParams_t       bitTimes = {0};

    /* Initialize MCAN Init parameters. */
    initParams.fdMode            = 0x0U; /* FD operation disabled. */
    initParams.brsEnable         = 0x0U; /* Bit rate switching for */
                                         /* transmissions disabled. */

    /* Initialize Message RAM Sections Configuration Parameters */
    msgRAMConfigParams.txStartAddr          = MCAN_TX_BUFF_START_ADDR;
    /* Tx Buffers Start Address. */
    msgRAMConfigParams.txBufNum             = MCAN_TX_BUFF_SIZE;
    /* Number of Dedicated Transmit Buffers. */
    msgRAMConfigParams.txBufMode            = 0U;
    msgRAMConfigParams.txBufElemSize        = kMCAN_ELEM_SIZE_8BYTES;
    /* Tx Buffer Element Size. */

    /* Initialize bit timings. */
    bitTimes.nomRatePrescalar   = 14U; /* Nominal Baud Rate Pre-scaler. */
    bitTimes.nomTimeSeg1        = 8U; /* Nominal Time segment before SP. */
    bitTimes.nomTimeSeg2        = 9U; /* Nominal Time segment after SP. */
    bitTimes.nomSynchJumpWidth  = 3U; /* Nominal SJW Range. */


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
