/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_cpu2_ipc.c
 * \brief SDK CPU2 IPC driver source file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_cpu2_ipc.h"

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
static IPC_Int_Callback_t s_ipcISR = { 0 }; /*!<ipc int callback function */
/*! \brief Array of IPC IRQ number */
static const IRQn_Type s_ipcIRQ[] = IPC_IRQS; /*!<ipc int req num */

/*******************************************************************************
 * Codes
 ******************************************************************************/
bool IPC_sendCommand(IPC_Id_t index, uint32_t command, uint32_t addr, uint32_t data)
{
    bool ret = false;

    if ((IPC_REGS_CPU2->IPCFLG & (0x1UL << index)) == 0x0UL)
    {
        ret                        = true;
        IPC_REGS_CPU2->IPCSENDCOM  = command;
        IPC_REGS_CPU2->IPCSENDDATA = data;
        IPC_REGS_CPU2->IPCSENDADDR = addr;
        IPC_REGS_CPU2->IPCSET      = (0x1UL << index);
    }

    return ret;
}

/*************************************************
 * Function: ipc_read_command
 * Description: this function is read remote cmd.
 *
 * Input(s):
 *
 * Output(s):
 *
 * Return:
 *
 * History
 * Date:       Version:     Author:        Description:
 * 2022.1.03	 1.0         hang            First create
 *************************************************/
bool IPC_readCommand(IPC_Id_t index, uint32_t *command, uint32_t *addr, uint32_t *data)
{
    bool ret = false;

    if ((IPC_REGS_CPU2->IPCSTS & (0x1UL << index)) != 0x0UL)
    {
        ret      = true;
        *command = IPC_REGS_CPU2->IPCRECVCOM;
        *data    = IPC_REGS_CPU2->IPCRECVDATA;
        *addr    = IPC_REGS_CPU2->IPCRECVADDR;
    }

    return ret;
}

status_t IPC_registerCallback(IPC_IntId_t intsrc, IPC_Callback_t func, uint32_t priority)
{
    assert(intsrc < kHAL_IPC_INTMAX);
    assert(func);

    if (s_ipcISR.func[intsrc] != NULL)
    {
        /* IPC ISR callback has been registered already, return failure */
        return kSTATUS_FAIL;
    }

    /* Enable the driver interrupt service */
    s_ipcISR.func[intsrc] = func;

    /* Set interrupt priority and enable the interrupt */
    NVIC_SetPriority(s_ipcIRQ[intsrc], priority);
    NVIC_EnableIRQ(s_ipcIRQ[intsrc]);

    return kSTATUS_SUCCESS;
}

status_t IPC_unregisterCallback(IPC_IntId_t intsrc)
{
    assert(intsrc < kHAL_IPC_INTMAX);

    if (s_ipcISR.func[intsrc] == NULL)
    {
        /* IPC instance hasn't been registered, return failure */
        return kSTATUS_INVALID_ARGUMENT;
    }

    /* Restore interrupt priority and disable the interrupt */
    NVIC_SetPriority(s_ipcIRQ[intsrc], 0U);
    NVIC_DisableIRQ(s_ipcIRQ[intsrc]);

    /* Clear the interrupt service and handle */
    s_ipcISR.func[intsrc] = NULL;

    return kSTATUS_SUCCESS;
}

/*!
 * \brief call the user callback function
 *
 * \details This function call the registered user callback function
 *
 * \param[in] intsrc the IPC INT index
 */
void IPC_handlerIRQ(IPC_IntId_t intsrc)
{
    if (s_ipcISR.func[intsrc] != NULL)
    {
        s_ipcISR.func[intsrc]();
    }
}

/*!
 * \brief call the ipc0 callback function
 *
 * \details This function call the registered ipc0 callback function
 *
 */
void IPC_INT0_DriverHandler(void)
{
    IPC_handlerIRQ(kHAL_IPC_INT0);
    ISR_EXIT_BARRIER();
}

/*!
 * \brief call the ipc1 callback function
 *
 * \details This function call the registered ipc1 callback function
 *
 */
void IPC_INT1_DriverHandler(void)
{
    IPC_handlerIRQ(kHAL_IPC_INT1);
    ISR_EXIT_BARRIER();
}

/*!
 * \brief call the ipc2 callback function
 *
 * \details This function call the registered ipc2 callback function
 *
 */
void IPC_INT2_DriverHandler(void)
{
    IPC_handlerIRQ(kHAL_IPC_INT2);
    ISR_EXIT_BARRIER();
}

/*!
 * \brief call the ipc3 callback function
 *
 * \details This function call the registered ipc3 callback function
 *
 */
void IPC_INT3_DriverHandler(void)
{
    IPC_handlerIRQ(kHAL_IPC_INT3);
    ISR_EXIT_BARRIER();
}
