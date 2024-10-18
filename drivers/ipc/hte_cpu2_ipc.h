/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_cpu2_ipc.h
 * \brief SDK CPU2 IPC driver header file
 * \version 1.0.0
 */

#ifndef HTE_CPU2_IPC_H
#define HTE_CPU2_IPC_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_common.h"

/*!
 * \addtogroup DRV_HTE_CPU2_IPC CPU2 IPC Driver
 *
 * \brief SDK CPU2 IPC driver
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! \brief index for IPC channel */
typedef enum
{
    kHAL_IPC0 = 0x00, /*!< ipc0 index */
    kHAL_IPC1,        /*!< ipc1 index */
    kHAL_IPC2,        /*!< ipc2 index */
    kHAL_IPC3,        /*!< ipc3 index */
    kHAL_IPC4,        /*!< ipc4 index */
    kHAL_IPC5,        /*!< ipc5 index */
    kHAL_IPC6,        /*!< ipc6 index */
    kHAL_IPC7,        /*!< ipc7 index */
    kHAL_IPC8,        /*!< ipc8 index */
    kHAL_IPC9,        /*!< ipc9 index */
    kHAL_IPC10,       /*!< ipc10 index */
    kHAL_IPC11,       /*!< ipc11 index */
    kHAL_IPC12,       /*!< ipc12 index */
    kHAL_IPC13,       /*!< ipc13 index */
    kHAL_IPC14,       /*!< ipc14 index */
    kHAL_IPC15,       /*!< ipc15 index */
    kHAL_IPC16,       /*!< ipc16 index */
    kHAL_IPC17,       /*!< ipc17 index */
    kHAL_IPC18,       /*!< ipc18 index */
    kHAL_IPC19,       /*!< ipc19 index */
    kHAL_IPC20,       /*!< ipc20 index */
    kHAL_IPC21,       /*!< ipc21 index */
    kHAL_IPC22,       /*!< ipc22 index */
    kHAL_IPC23,       /*!< ipc23 index */
    kHAL_IPC24,       /*!< ipc24 index */
    kHAL_IPC25,       /*!< ipc25 index */
    kHAL_IPC26,       /*!< ipc26 index */
    kHAL_IPC27,       /*!< ipc27 index */
    kHAL_IPC28,       /*!< ipc28 index */
    kHAL_IPC29,       /*!< ipc29 index */
    kHAL_IPC30,       /*!< ipc30 index */
    kHAL_IPC31,       /*!< ipc31 index */
    kHAL_IPCMAX,      /*!< ipc max index */
} IPC_Id_t;

/*! \brief ipc boot mode */
typedef enum
{
    kIPC_BOOT_MODE1 = 0x00, /*!< ipc boot mode1 index */
    kIPC_BOOT_MODE2,        /*!< ipc boot mode2 index */
    kIPC_BOOT_MODE3,        /*!< ipc boot mode3 index */
    kIPC_BOOT_MODE4,        /*!< ipc boot mode4 index */
    kIPC_BOOT_MODE5,        /*!< ipc boot mode5 index */
} IPC_BootMode_t;

/*! \brief index for IPC INT channel */
typedef enum
{
    kHAL_IPC_INT0 = 0x00, /*!< ipc int0 index */
    kHAL_IPC_INT1,        /*!< ipc int1 index */
    kHAL_IPC_INT2,        /*!< ipc int2 index */
    kHAL_IPC_INT3,        /*!< ipc int3 index */
    kHAL_IPC_INTMAX,      /*!< ipc int max index */
} IPC_IntId_t;

/*! \brief type definition for IPC callback  */
typedef void (*IPC_Callback_t)();

/*! \brief type definition for ipc interrupt callback  */
typedef struct
{
    IPC_Callback_t func[kHAL_IPC_INTMAX]; /*!< ipc int call back function */
} IPC_Int_Callback_t;

/*******************************************************************************
 * APIs
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Local core acknowledges Remote to Local IPC Flag.
 *
 * \details This function will allow the Local core system to acknowledge/clear the IPC
 *          flag set by the Remote core system.
 *
 * \param[in] ipcNum is the IPC index.
 *
 */
static inline void IPC_ackFlagRtoL(IPC_Id_t ipcNum)
{
    IPC_REGS_CPU2->IPCACK = (0x1UL << ipcNum);
}

/*!
 * \brief Get IPC flag status
 *
 * \details This function Get IPC flag status from remote to loacal.
 *
 * \return Return IPC all status.
 *
 */
static inline uint32_t IPC_getFlagStatusRtoL(void)
{
    return IPC_REGS_CPU2->IPCSTS;
}

/*!
 * \brief Determines whether the given Remote to Local IPC flags are busy or not.
 *
 * \details This function Allows the caller to determine whether the designated Remote to Local
 *          IPC flags are pending
 *
 * \param[in] ipcNum is the IPC index.
 * \return Return \b true if the any of the designated IPC flags are busy
 *
 */
static inline bool IPC_isFlagBusyRtoL(IPC_Id_t ipcNum)
{
    return ((IPC_REGS_CPU2->IPCSTS & (0x1UL << ipcNum)) != 0U);
}

/*!
 * \brief Local core sets Local to Remote IPC Flag
 *
 * \details This function will allow the Local core system to set the designated IPC
 *           flags to send to the Remote core system.
 *
 * \param[in] ipcNum is the IPC index.
 *
 */
static inline void IPC_setFlagLtoR(IPC_Id_t ipcNum)
{
    IPC_REGS_CPU2->IPCSET = (0x1UL << ipcNum);
}

/*!
 * \brief Local core clears Local to Remote IPC Flag
 *
 * \details This function will allow the Local core system to clear the designated IPC
 *           flags sent to the Remote core system.
 *
 * \param[in] ipcNum is the IPC index.
 *
 */
static inline void IPC_clearFlagLtoR(IPC_Id_t ipcNum)
{
    IPC_REGS_CPU2->IPCCLR = (0x1UL << ipcNum);
}

/*!
 * \brief Get flag stauts
 *
 * \details This function Get flag stauts from local to remote.
 *
 * \return Return \b true if the any of the designated IPC flags are busy
 *
 */
static inline uint32_t IPC_getFlagStatusLtoR(void)
{
    return IPC_REGS_CPU2->IPCFLG;
}

/*!
 * \brief Determines whether the given Local to Remote IPC flags are busy or not.
 *
 * \details This function Allows the caller to determine whether the designated Local to Remote
 *          IPC flags are pending
 *
 * \param[in] ipcNum is the IPC index.
 * \return Return \b true if the any of the designated IPC flags are busy
 *
 */
static inline bool IPC_isFlagBusyLtoR(IPC_Id_t ipcNum)
{
    return ((IPC_REGS_CPU2->IPCFLG & (0x1UL << ipcNum)) != 0U);
}

/*!
 * \brief Wait for the remote core to send a flag
 *
 * \details This function to wait for the Remote to Local flag to be send by
 *         the remote core.
 *
 * \param[in] ipcNum is the IPC index.
 *
 */
static inline void IPC_waitForFlag(IPC_Id_t ipcNum)
{
    while ((IPC_REGS_CPU2->IPCSTS & (0x1UL << ipcNum)) == 0U)
    {
    }
}

/*!
 * \brief Wait for the IPC flag to be acknowledged
 *
 * \details This function to wait for the IPC flag to be acknowledged by the
 *           remote core.
 *
 * \param[in] ipcNum is the IPC index.
 *
 */
static inline void IPC_waitForAck(IPC_Id_t ipcNum)
{
    while ((IPC_REGS_CPU2->IPCFLG & (0x1UL << ipcNum)) != 0U)
    {
    }
}

/*!
 * \brief Reads the timestamp counter value.
 *
 * \details  Allows the caller to read the IPC timestamp counter value.
 *
 * \return Return 64-bit counter value.
 *
 */
static inline uint64_t IPC_getCounter(void)
{
    //
    // Get the Counter High and Low values. Read to the Counter low register
    // saves the value of Counter High register.
    //
    uint32_t ctrL = IPC_REGS_CPU2->IPCCOUNTERL;
    uint32_t ctrH = IPC_REGS_CPU2->IPCCOUNTERH;

    //
    // Return the 64-bit value of the counter
    //
    return (((uint64_t)ctrH << 32) | ((uint64_t)ctrL));
}

/*!
 * \brief Sends the response to the command sent by remote core.
 *
 * \details This function send a response to the command previously sent by the
 *          remote core
 *
 * \param[in] data is the 32-bit value of the response to be sent
 *
 */
static inline void IPC_sendResponse(uint32_t data)
{
    IPC_REGS_CPU2->IPCLOCALREPLY = data;
}

/*!
 * \brief Reads the response from the remote core.
 *
 * \details This function read the response sent by the remote core to the
 *          command previously sent by the local core
 *
 * \return the 32-bit value of the response.
 *
 */
static inline uint32_t IPC_getResponse(void)
{
    return (IPC_REGS_CPU2->IPCREMOTEREPLY);
}

/*!
 * \brief Get boot mode
 *
 * \details This function get boot mode to send from local to remote
 *
 * \return Return boot mode value.
 *
 */
static inline uint32_t IPC_getBootMode(void)
{
    return IPC_REGS_CPU2->IPCBOOTMODE;
}

/*!
 * \brief Set boot status
 *
 * \details This function set boot status from remote.
 *
 * \param[in] status is boot status value
 *
 */
static inline void IPC_setBootStatus(uint32_t status)
{
    IPC_REGS_CPU2->IPCBOOTSTS = status;
}

/*!
 * \brief Sends a command to the Remote core
 *
 * \details This function send a command to the remote core.
 *
 * \param[in] index specifies the IPC index.
 * \param[in] command is the ipc command value.
 * \param[in] addr specifies ipc data addr.
 * \param[in] data specifies ipc data value, usually use for data length.

 * \return Return \b true if the cmd send success.
 *
 */
extern bool IPC_sendCommand(IPC_Id_t index, uint32_t command, uint32_t addr, uint32_t data);

/*!
 * \brief Read a command to the Remote core
 *
 * \details This function read a command to the remote core.
 *
 * \param[in] index specifies the IPC index.
 * \param[in] command is the ipc command value.
 * \param[in] addr specifies ipc data addr.
 * \param[in] data specifies ipc data value, usually use for data length.

 * \return Return \b true if the cmd read success.
 *
 */
extern bool IPC_readCommand(IPC_Id_t index, uint32_t *command, uint32_t *addr, uint32_t *data);

/*!
 * \brief register IPC int callback function
 *
 * \details this function is register IPC int callback function.
 *
 *
 * \param[in] intsrc is the index of the ipc module.
 * \param[in] func is the function of the ipc int callback.
 * \param[in] priority is the function of the ipc int priority.
 * \return Returns the register status.
 *
 */
extern status_t IPC_registerCallback(IPC_IntId_t intsrc, IPC_Callback_t func, uint32_t priority);

/*!
 * \brief unregister IPC int callback function
 *
 * \details this function is unregister IPC int callback function.
 *
 *
 * \param[in] intsrc is the index of the ipc module.
 * \return Returns the register status.
 *
 */
extern status_t IPC_unregisterCallback(IPC_IntId_t intsrc);

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */ /* end of DRV_HTE_CPU2_IPC */

#endif /* HTE_CPU2_IPC_H */
