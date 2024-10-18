/*
 * Copyright 2023 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*!
 * \file hello_world.c
 * \brief Example of SDK debug console
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "board.h"
#include "clock_config.h"
#include "hte_dma.h"
#include "hte_sysctrl.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* No Definitions */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/* No Prototypes */

/*******************************************************************************
 * Variables
 ******************************************************************************/
static volatile uint8_t dmaCH1IntFlag  = 0;
static uint32_t         dmaTestSrcAddr = DTCM_BASE + 0x10000;
static uint32_t         dmaTestDstAddr = DTCM_BASE + 0x14000;
static uint32_t         dmaTestDatLen  = 0x1000;

/*******************************************************************************
 * Codes
 ******************************************************************************/
void DMA_Ch1IrqCallback(DMA_Index_t index)
{
    dmaCH1IntFlag = 1;
    DMA_clearIntEndFlag(index);
    PRINTF("dma ch1 intr occurs\r\n");
}

static void MEMSET_inc_u8(uint8_t *buf, uint32_t len_u8)
{
    uint32_t i = 0;
    while (0 != len_u8--)
    {
        buf[i] = (uint8_t)i;
        i++;
    }
}

static void MEMSET_u8(uint8_t *addr, uint8_t pattern, uint32_t u8_size)
{
    uint32_t i;

    for (i = 0; i < u8_size; i++)
    {
        addr[i] = pattern;
    }

    return;
}

static bool MEMORY_cmp_u8(uint8_t *dst, uint8_t *src, uint32_t u8_size)
{
    uint32_t i;
    bool     ret = true;

    for (i = 0; i < u8_size; i++)
    {
        if (dst[i] != src[i])
        {
            PRINTF("-E-: [dest_0x%lx]:0x%lx,  [src_0x%lx]:0x%lx \r\n", (uint32_t)&dst[i], (uint32_t)dst[i],
                   (uint32_t)&src[i], (uint32_t)src[i]);
            // ASSERT(FALSE);
            PRINTF("FORCE stop memory check!!!\r\n");
            ret = false;
            return ret;
        }
    }
    return ret;
}

int main(void)
{
    uint32_t       src, dst, len;
    DMA_DataSize_t dataSize;
    uint32_t       transSize;

    /* Board initialization */
    BOARD_init();

    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_DMA);

    /* dma initialization */
    DMA_registerCallback(kDMA_CH1_INT, DMA_Ch1IrqCallback, 0x04);

    src = (uint32_t)dmaTestSrcAddr;
    dst = (uint32_t)dmaTestDstAddr;
    len = (uint32_t)dmaTestDatLen;

    /* Print the example banner */
    PRINTF("\r\n");
    PRINTF("DMA Example:\r\n");
    PRINTF("Copy DTCM data from src 0x%lx to dst 0x%lx......\r\n", src, dst);

    MEMSET_inc_u8((uint8_t *)src, len);
    MEMSET_u8((uint8_t *)dst, 0x0, len);
    //
    // configure DMA CH transfer config
    //
    DMA_configWrap(kDMA_INDEX_CH1, 0x10000, 0, 0x10000, 0);

    dataSize  = kDMA_DATASIZE_32BIT;
    transSize = len / 8;
    DMA_setDataSize(kDMA_INDEX_CH1, dataSize);
    DMA_configBurst(kDMA_INDEX_CH1, 2U, 4, 4);
    DMA_configTransfer(kDMA_INDEX_CH1, transSize, 4, 4);

    //
    // configure DMA CH
    //
    DMA_clearStatusFlag(kDMA_INDEX_CH1);

    DMA_configAddresses(kDMA_INDEX_CH1, (const void *)dst, (const void *)src);
    DMA_configMode(kDMA_INDEX_CH1, kDMA_MODE_ONESHOT);
    DMA_configTrigger(kDMA_INDEX_CH1, kDMA_TRIGGER_SOFTWARE);

    DMA_disableBegInterrupt(kDMA_INDEX_CH1);
    DMA_enableEndInterrupt(kDMA_INDEX_CH1);


    DMA_enableTrigger(kDMA_INDEX_CH1);
    DMA_startChannel(kDMA_INDEX_CH1);
    // triggle dma ch1
    DMA_forceTrigger(kDMA_INDEX_CH1);

    while (dmaCH1IntFlag == 0)
        ;

    dmaCH1IntFlag = 0;

    if (false == MEMORY_cmp_u8((uint8_t *)dst, (uint8_t *)src, len)) // src should not be changed
    {
        PRINTF("DMA DATA check FAIL!\r\n");
    }
    else
    {
        PRINTF("DMA DATA check OK!\r\n");
    }

    while (1)
        ;
}
