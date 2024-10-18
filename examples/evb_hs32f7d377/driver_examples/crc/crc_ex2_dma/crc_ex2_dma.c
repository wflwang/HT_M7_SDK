/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*
 * 
 * \file crc_ex2_dma.c
 * 
 * 
 * \brief CRC Use Dma Example
 * 
 * This example shows the CRC functionality by dma.
 * 
 * \b External \b Connections \n
 *   - None.
 *
 * \version 1.0.0
 * 
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "board.h"
#include "hte_sysctrl.h"
#include "hte_crc.h"
#include "hte_dma.h"
#ifdef HTE_DEVICE_HS32F7D377_CPU1
#include "hte_cpu1_ipc_com.h"
#else
#include "hte_cpu2_ipc_com.h"
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/
//#define CRC_32
//#define CRC_24
//#define CRC_16
//#define CRC_8
#define CRC_7

#define DATA_SIZE 1 /* MAX supported size  = 256 * 4 = 1kB */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void dataInit(void);
void CRC_config(void);
void CRC_start(void);


/*******************************************************************************
 * Variables
 ******************************************************************************/
static uint32_t hdr_result;
static uint32_t seed;
static volatile uint8_t dmacrcdone = 0;

CRC_InitParams_t initPara;

uint32_t data[DATA_SIZE] = {0};

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
    dataInit();
    
    CRC_config();

    CRC_start();
    
    /* Stop Application. */
    while(1)
    {
        DELAY(1000000);
        PRINTF("test done\r\n");
    }
}


void dataInit(void)
{
    uint32_t tseed;
    uint32_t i;


    /* Initialize the random number generator */
    tseed = 0x55aa55aa;
    srand(tseed);
    srand(rand());

    seed  =  rand();
    seed = (uint32_t)(seed <<16) | rand();       /* Initialize with seed */

    /* Initialize the Data_Buffer with 32 bit random data */
    for(i = 0; i < DATA_SIZE; i++)
    {
        data[i] = rand();
        data[i] = (data[i] << 16) | rand();
    }
}


void CRC_config(void)
{
    /** crc source config **/
    initPara.initValue       = 0xffffffff;//seed;
    
    #ifdef CRC_32
    initPara.poly            = 0x04C11DB7;
    initPara.polySize        = kCRC_POLY32_SIZE;
    #endif

    #ifdef CRC_24
    initPara.poly            = 0x5D6DCB;
    initPara.polySize        = kCRC_POLY24_SIZE;
    #endif

    #ifdef CRC_16
    initPara.poly            = 0x8005;
    initPara.polySize        = kCRC_POLY16_SIZE;
    #endif

    #ifdef CRC_8
    initPara.poly            = 07;
    initPara.polySize        = kCRC_POLY8_SIZE;
    #endif

    #ifdef CRC_7
    initPara.poly            = 0x09;
    initPara.polySize        = kCRC_POLY7_SIZE;
    #endif
    
    initPara.revInput        = kCRC_REVINPUT_FORMAT_UNDEFINED;
    /*dma mode should set it val inverse*/
    initPara.revByte         = kCRC_BYTE_REVERSE_ENABLE; 
    initPara.revOut          = kCRC_OUT_REVERSE_DISABLE;
    initPara.inputDataFormat = kCRC_INPUT_FORMAT_WORD;
}


void crcDmaDoneIsr(DMA_Index_t index)
{
    dmacrcdone = 1;
    DMA_clearIntEndFlag(index);
}

void crcDmaconfig(DMA_Index_t channel,uint32_t *data,uint32_t datalen)
{
    int32_t *dma1SrcAddr, *dma1DestAddr;
    DMA_Index_t ch = (DMA_Index_t)channel;
    uint16_t rstsize;
    uint32_t transize;

    dmacrcdone = 0;
    
    transize = datalen/32;
    rstsize = datalen%32;

    DMA_registerCallback((DMA_IntSrc_t)ch,crcDmaDoneIsr,5);

    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_DMA);
    
    DMA_initialize();

    dma1SrcAddr = (int32_t *)data;

    dma1DestAddr = (int32_t *)&(CRC->CRC_DR);

    DMA_configAddresses(ch, dma1DestAddr, dma1SrcAddr);

    if(transize>0)
    {
        DMA_configBurst(ch, 32, 4, 0);
        DMA_configTransfer(ch, transize, 4, 0);
    }
    else
    {
        DMA_configBurst(ch, rstsize, 4, 0);
        DMA_configTransfer(ch, 1, 4, 0);
    }
    
    DMA_configTrigger(ch, kDMA_TRIGGER_SOFTWARE);

    DMA_configMode(ch, kDMA_MODE_ONESHOT);
    DMA_setDataSize(ch, kDMA_DATASIZE_32BIT);
    DMA_enableTrigger(ch);
    DMA_disableOverRunInterrupt(ch);
    DMA_disableBegInterrupt(ch);
    DMA_enableEndInterrupt(ch);
    DMA_clearStatusFlag(ch);

    /* Start DMA channels */
    DMA_startChannel(ch);
}



void CRC_start(void)
{

#ifdef HTE_DEVICE_HS32F7D377_CPU1
    SYSCTRL_enableCRC();
#else
    IPC_com_SYSCTRL_enableCRC();
#endif

    /**init hardware CRC and software CRC**/
    crcDmaconfig(kDMA_INDEX_CH1,data, DATA_SIZE);
    CRC_init(CRC, &initPara);

    /**calculte**/
    DMA_forceTrigger(kDMA_INDEX_CH1);
    while(dmacrcdone == 0);  
    
    hdr_result = CRC->CRC_RR;

    PRINTF("result is 0x%lx \r\n", hdr_result);
}



