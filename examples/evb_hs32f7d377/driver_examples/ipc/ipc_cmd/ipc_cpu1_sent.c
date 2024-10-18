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
#include "hte_cpu1_ipc.h"
#include "hte_sysctrl.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define IPC_TEST_INDEX (3U)
#define IPC_TEST_CMD   (0x5A)

#define IPC_MSG_LENTH (0x100)

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/* No Prototypes */

/*******************************************************************************
 * Variables
 ******************************************************************************/
/* No Variables */

/*******************************************************************************
 * Codes
 ******************************************************************************/
void MEMSET_inc_u32(uint32_t *buf, uint32_t len)
{
    uint32_t i = 0;
    while (0 != len--)
    {
        buf[i] = (uint32_t)i;
        i++;
    }
}

int main(void)
{
    volatile bool     remote_flag  = false;
    volatile uint32_t remote_reply = 0x0;
    char              key          = 'N';

    /* Board initialization */
    BOARD_init();

    PRINTF("PUT y to enter ipc sent\r\n");

    while (key != 'y')
    {
        SCANF("%c", &key);
    }

    PRINTF("\r\nStart ipc sent\r\n");

    /*INIT MSGRAM*/
    SYSCTRL_initMsgram();
    while (SYSCTRL_getMsgramInitDone() == false)
        ;
    // delay_ms(500);

    MEMSET_inc_u32((uint32_t *)CPU1TOCPU2_MSGRAM_BASE, IPC_MSG_LENTH / 4);

    if (IPC_sendCommand((IPC_Id_t)IPC_TEST_INDEX, (uint32_t)IPC_TEST_CMD, CPU1TOCPU2_MSGRAM_BASE, IPC_MSG_LENTH / 4) ==
        false)
    {
        PRINTF("IPC CPU SEND FAIL!\r\n");
    }

    PRINTF("IPC CPU SEND CMD %d\r\n", IPC_TEST_CMD);

    /*get remote flag have been set*/
    while (remote_flag == false)
    {
        remote_flag = IPC_isFlagBusyLtoR((IPC_Id_t)IPC_TEST_INDEX);
    }
    /*wait remote ok reply*/
    IPC_waitForAck((IPC_Id_t)IPC_TEST_INDEX);

    remote_reply = IPC_getResponse();

    PRINTF("IPC CPU SEND GET REPLY CMD %ld\r\n", remote_reply);

    if (remote_reply == (IPC_TEST_CMD + 1)) // src should not be changed
    {
        PRINTF("IPC CMD check OK!\r\n");
    }
    else
    {
        PRINTF("DMA DATA check FAIL!\r\n");
    }

    while (1)
        ;
}
