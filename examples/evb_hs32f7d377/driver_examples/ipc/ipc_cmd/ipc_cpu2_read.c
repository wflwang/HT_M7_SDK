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
#include "hte_cpu2_ipc.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define IPC_TEST_INDEX     (3U)
#define IPC_TEST_INT_INDEX (3U)

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/* No Prototypes */

/*******************************************************************************
 * Variables
 ******************************************************************************/
static volatile uint8_t ipcIntFlag = 0;

/*******************************************************************************
 * Codes
 ******************************************************************************/
void IPC_irq_handler(void)
{
    ipcIntFlag = 1;
    PRINTF("IPC ch3 intr occurs\r\n");
}

bool MEMORY_check_inc_u32(uint32_t *buf, uint32_t len)
{
    uint32_t i;
    bool     ret = true;

    for (i = 0; i < len; i++)
    {
        if ((uint32_t)i != buf[i])
        {
            PRINTF("ERR: [0x%lx]: value_0x%lx, should be_0x%lx\r\n", (uint32_t)&buf[i], (uint32_t)buf[i], (uint32_t)i);
            PRINTF("FORCE stop memory inc check!!!\r\n");
            ret = false;
            return ret;
        }
    }
    return ret;
}

int main(void)
{
    volatile bool flag = false;
    uint32_t      cmd, addr, dat;
    /* Board initialization */
    BOARD_init();

    PRINTF("WAIT CPU1 SENT IPC\r\n");

    IPC_registerCallback((IPC_IntId_t)IPC_TEST_INT_INDEX, IPC_irq_handler, 0x06);

    while (ipcIntFlag == 0)
        ;
    IPC_unregisterCallback((IPC_IntId_t)IPC_TEST_INT_INDEX);

    while (flag == false)
    {
        flag = IPC_readCommand((IPC_Id_t)IPC_TEST_INDEX, &cmd, &addr, &dat);
    }

    if (MEMORY_check_inc_u32((uint32_t *)addr, dat))
    {
        IPC_sendResponse(cmd + 1);
        PRINTF("IPC CPU READ OK! cmd is %ld\r\n", cmd);

        IPC_ackFlagRtoL((IPC_Id_t)IPC_TEST_INDEX);
    }
    else
    {
        IPC_sendResponse(cmd + 2);
        PRINTF("IPC CPU READ FAIL! \r\n");
        IPC_ackFlagRtoL((IPC_Id_t)IPC_TEST_INDEX);
    }

    while (1)
        ;
}
