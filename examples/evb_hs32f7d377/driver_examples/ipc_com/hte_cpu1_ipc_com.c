/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include "clock_config.h"
#include "hte_cpu1_ipc.h"
#include "hte_cpu1_ipc_com.h"
#include "hte_sysctrl.h"

void cpu1_ipc_com_irq_handler(void)
{
    uint32_t      cmd, addr, dat;
    uint32_t      regVal;
    volatile bool flag = false;
//    SYSTEM_Clock_t clkParam;

    //MSG_INFO("IPC ch0 intr occurs\r\n");

    while (flag == false)
    {
        flag = IPC_readCommand(kHAL_IPC0, &cmd, &addr, &dat);
    }

    if (cmd == IPC_COM_WRITE)
    {
        //MSG_INFO("WRITE REG 0x%x, VAL 0x%x \r\n", addr, dat);
        *(uint32_t *)addr = dat;
        IPC_sendResponse(IPC_COM_DONE);
        IPC_ackFlagRtoL(kHAL_IPC0);
    }
    else if (cmd == IPC_COM_READ)
    {
        //MSG_INFO("READ REG 0x%x\r\n", addr);
        regVal = *(uint32_t *)addr;
        IPC_sendResponse(regVal);
        IPC_ackFlagRtoL(kHAL_IPC0);
    }
    else if (cmd == IPC_COM_CLK_PARAM)
    {
        // MSG_INFO("READ REG 0x%x\r\n", addr);
        /*
                                  clkParam.xtalClkIn = BOARD_getXtalClkIn();
                                  clkParam.sysClk = BOARD_getSysclk();
                                  clkParam.sysPclk = BOARD_getSysPclk();
                                  clkParam.periphClk = BOARD_getPeripheralClk();
                                  clkParam.auxClkIn = BOARD_getAuxClkIn();
                                  clkParam.auxPllRawClk = BOARD_getAuxRawClk();
                                  clkParam.auxPllClk = BOARD_getAuxClk();

                                  memcpy((uint32_t *)CPU1TOCPU2_MSGRAM_BASE, (uint32_t *)&clkParam, sizeof(clkParam)/4);
        */
        BOARD_clockInfStore();
        IPC_sendResponse(CPU1TOCPU2_MSGRAM_BASE);
        IPC_ackFlagRtoL(kHAL_IPC0);
    }
    else
    {
        //MSG_INFO("BAD IPC cmd!\r\n");
    }
}

void IPC_comInit(void)
{
    IPC_registerCallback(kHAL_IPC_INT0, cpu1_ipc_com_irq_handler, 0x02);
//    SYSCTRL_initMsgram();
    while (SYSCTRL_getMsgramInitDone() == false)
        ;
}
