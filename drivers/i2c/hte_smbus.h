/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_smbus.h
 * \brief SDK SMBUS driver source file
 * \version 1.0.0
 */

#ifndef HTE_SMBUS_H
#define HTE_SMBUS_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_common.h"
#include "hte_i2c.h"
#include "hte_sysctrl.h"

/*!
 * \addtogroup DRV_HTE_SMBUS SMBUS Driver
 *
 * \brief SDK SMBUS driver
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! \brief Check whether the specified SMBUS flag is set or not */
#define SMBUS_GET_FLAG(__HANDLE__, __FLAG__) \
    (((((__HANDLE__)->hi2c.instance->IC_SMBUS_RAW_INTR_STAT) & (__FLAG__)) == (__FLAG__)) ? 1 : 0)

#define SMBUS_HOST_ADDR           0x8  /*!< SMBUS Host address */
#define SMBUS_ALERT_RESPONSE_ADDR 0xC  /*!< SMBUS Alert Response Address */
#define SMBUS_DEVICE_DEFAULT_ADDR 0x61 /*!< SMBUS Device Default Address */

#define SMBUS_MEXT        0x16E360 /*!< Default value of Master extend SMBus clock timeout */
#define SMBUS_SEXT        0x393870 /*!< Default value of Slave Clock Extend timeout */
#define SMBUS_SCL_TIMEOUT 0x393870 /*!< Default value of SCL stuck at low timeout */
#define SMBUS_SDA_TIMEOUT 0x393870 /*!< Default value of SCL stuck at low timeout */

/*! \brief SMBUS handle Structure definition */
typedef struct __SMBUS_Handle_t
{
    I2C_Handle_t hi2c;       /*!< I2C handle structure */
    uint32_t     mext;       /*!< Master extend SMBus clock timeout */
    uint32_t     sext;       /*!< Slave Clock Extend timeout in one transfer */
    void (*smbusCallback)(struct __SMBUS_Handle_t *hsmbus); /*!< SMBUS callback function */
} SMBUS_Handle_t;

/*! \brief SMBUS interrupt identification ID */
typedef enum
{
    kSMBUS_SLV_CLOCK_EXTND_TIMEOUT = 0x1U,   /*!< Slave Clock Extend Timeout */
    kSMBUS_MST_CLOCK_EXTND_TIMEOUT = 0x2U,   /*!< Master Clock Extend Timeout */
    kSMBUS_QUICK_CMD_DET           = 0x4U,   /*!< Quick Command */
    kSMBUS_HOST_NOTIFY_MST_DET     = 0x8U,   /*!< Notify ARP Master ARP command */
    kSMBUS_ARP_PREPARE_CMD_DET     = 0x10U,  /*!< Prepare to ARP command */
    kSMBUS_ARP_RST_CMD_DET         = 0x20U,  /*!< General or Directed Reset ARP command */
    kSMBUS_ARP_GET_UDID_CMD_DET    = 0x40U,  /*!< Get UDID ARP command */
    kSMBUS_ARP_ASSGN_ADDR_CMD_DET  = 0x80U,  /*!< Assign Address ARP command */
    kSMBUS_SLV_RX_PEC_NACK         = 0x100U, /*!< NACK has been sent due to PEC mismatch while working as ARP slave*/
    kSMBUS_SUSPEND_DET             = 0x200U, /*!< SMBUS System Suspend */
    kSMBUS_ALERT_DET               = 0x400U, /*!< SMBUS Alert */
} SMBUS_InterruptIdentification_t;

/*! \brief SMBUS ARP command code */
typedef enum
{
    kSMBUS_PREPARE_TO_ARP       = 0x1, /*!< Prepare to ARP */
    kSMBUS_RESET_DEVICE_GENERAL = 0x2, /*!< Reset Device (general) */
    kSMBUS_GET_UDID_GENERAL     = 0x3, /*!< Get UDID (general) */
    kSMBUS_ASSIGN_ADDRESS       = 0x4, /*!< Assign Address */
} SMBUS_ARPCommand_t;

/*! \brief SMBUS Callback pointer definition */
typedef void (*pSMBUS_Callback_t)(SMBUS_Handle_t *hsmbus);

/*******************************************************************************
 * APIs
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief  Handles SMBUS Communication Timeout.
 *
 * \details This function handles SMBUS Communication Timeout. It waits
 *                until a flag is no longer in the specified status.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \param[in] flag specifies the SMBUS flag to check.
 * \param[in] status is the actual Flag status (0 or 1).
 * \param[in] timeout is timeout duration
 * \param[in] tickStart is tick start value
 *
 * \return status of function
 */
static inline I2C_Status_t SMBUS_waitOnFlag(SMBUS_Handle_t *hsmbus, uint32_t flag, uint32_t status, uint32_t timeout,
                                            uint32_t tickStart)
{
    uint32_t time;
    while (SMBUS_GET_FLAG(hsmbus, flag) == status)
    {
        if (timeout != I2C_MAX_DELAY)
        {
            time = BOARD_getTick();
            if (((time - tickStart) > timeout) || (timeout == 0U))
            {
                hsmbus->hi2c.state = kI2C_READY;
                return kSTATUS_I2C_ERROR;
            }
        }
    }
    return kSTATUS_I2C_OK;
}

/*!
 * \brief  Get the pointer to the SMBUS_Handle_t structure defined in the driver
 *
 * \details This function gets the pointer to the SMBUS_Handle_t structure defined in the driver
 *
 * \return status of function
 */
SMBUS_Handle_t *SMBUS_getHandle();

/*!
 * \brief  Register a User SMBUS Callback
 *
 * \details This function registers a User SMBUS Callback
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \param[in] pCallback is the pointer to the Callback function
 *
 * \return status of function
 */
I2C_Status_t SMBUS_registerCallback(SMBUS_Handle_t *hsmbus, pSMBUS_Callback_t pCallback);

/*!
 * \brief  Unregister a User SMBUS Callback
 *
 * \details This function unregisters a User SMBUS Callback
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \return status of function
 */
I2C_Status_t SMBUS_unregisterCallback(SMBUS_Handle_t *hsmbus);

/*!
 * \brief  Initializes the SMBUS Master.
 *
 * \details This function initializes the SMBUS in master mode.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \return status of function
 */
I2C_Status_t SMBUS_initMaster(SMBUS_Handle_t *hsmbus);

/*!
 * \brief  Initializes the SMBUS Slave.
 *
 * \details This function initializes the SMBUS in slave mode.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 *
 * \return status of function
 */
I2C_Status_t SMBUS_initSlave(SMBUS_Handle_t *hsmbus);

/*!
 * \brief  Transmits Quick command in master mode.
 *
 * \details This function transmits Quick command in master mode.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \param[in] cmd is Read or Write command.
 * \param[in] timeout is timeout duration.
 *
 * \return status of function
 */
I2C_Status_t SMBUS_masterQuickCommand(SMBUS_Handle_t *hsmbus, I2C_Cmd_t cmd, uint32_t timeout);

/*!
 * \brief  Config SMBUS master to perform a Quick command or not.
 *
 * \details This function configs SMBUS master to perform a Quick command or not.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \param[in] sel = 1 means enabling programming of QUICK-CMD transmission, while
 * sel = 0 means disabling programming of QUICK-CMD transmission
 */
void SMBUS_configQuickCommand(SMBUS_Handle_t *hsmbus, uint8_t sel);

/*!
 * \brief  Config SMBUS slave to only receive Quick commands.
 *
 * \details This function configs SMBUS slave to only receive Quick commands.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 *
 * \return status of function
 */
I2C_Status_t SMBUS_slaveEnableQuickCommand(SMBUS_Handle_t *hsmbus);

/*!
 * \brief  Disable SMBUS slave to receive Quick commands.
 *
 * \details This function disables SMBUS slave to receive Quick commands.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 *
 * \return status of function
 */
I2C_Status_t SMBUS_slaveDisableQuickCommand(SMBUS_Handle_t *hsmbus);

/*!
 * \brief  Get the R/W bit of the Quick command received.
 *
 * \details This function gets the R/W bit of the Quick command received.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \return 1 means SMBUS QUICK CMD Read/write is set to 1, while 0 means
 *         SMBUS QUICK CMD Read/write is set to 0.
 */
bool SMBUS_getQuickCmd(SMBUS_Handle_t *hsmbus);

/*!
 * \brief  Send byte protocol transfer in master mode.
 *
 * \details This function transmits data with Send byte protocol in master mode.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \param[in] buff is the pointer to data to be sent
 * \param[in] timeout is timeout duration.
 *
 * \return status of function
 */
I2C_Status_t SMBUS_masterSendByte(SMBUS_Handle_t *hsmbus, uint8_t *buff, uint32_t timeout);

/*!
 * \brief  Handle Send byte protocol received in slave mode.
 *
 * \details This function handles Send byte protocol received in slave mode.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \param[in] buff is the pointer to data to be received
 * \param[in] timeout is timeout duration.
 *
 * \return status of function
 */
I2C_Status_t SMBUS_slaveHandleSendByte(SMBUS_Handle_t *hsmbus, uint8_t *buff, uint32_t timeout);

/*!
 * \brief  Receive byte protocol transfer in master mode.
 *
 * \details This function transfers data with Receive byte protocol in master mode.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \param[in] buff is the pointer to data to be received
 * \param[in] timeout is timeout duration.
 *
 * \return status of function
 */
I2C_Status_t SMBUS_masterReceiveByte(SMBUS_Handle_t *hsmbus, uint8_t *buff, uint32_t timeout);

/*!
 * \brief  Handle Receive byte protocol received in slave mode.
 *
 * \details This function handles Receive byte protocol received in slave mode.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \param[in] buff is the pointer to data to be sent
 * \param[in] timeout is timeout duration.
 *
 * \return status of function
 */
I2C_Status_t SMBUS_slaveHandleReceiveByte(SMBUS_Handle_t *hsmbus, uint8_t *buff, uint32_t timeout);

/*!
 * \brief  Write byte protocol transfer in master mode.
 *
 * \details This function transmits data with Write byte protocol in master mode.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \param[in] command_code is is protocol command code
 * \param[in] buff is the poointer of data to be sent
 * \param[in] timeout is timeout duration.
 *
 * \return status of function
 */
I2C_Status_t SMBUS_masterWriteByte(SMBUS_Handle_t *hsmbus, uint8_t command_code, uint8_t *buff, uint32_t timeout);

/*!
 * \brief  Handle Write byte protocol received in slave mode.
 *
 * \details This function handles Write byte protocol received in slave mode.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \param[in] buff is the pointer to data to be received
 * \param[in] timeout is timeout duration.
 *
 * \return status of function
 */
I2C_Status_t SMBUS_slaveHandleWriteByte(SMBUS_Handle_t *hsmbus, uint8_t *buff, uint32_t timeout);

/*!
 * \brief  Write word protocol transfer in master mode.
 *
 * \details This function transmits data with Write word protocol in master mode.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \param[in] command_code is is protocol command code
 * \param[in] buff is the pointer to data to be sent
 * \param[in] timeout is timeout duration.
 *
 * \return status of function
 */
I2C_Status_t SMBUS_masterWriteWord(SMBUS_Handle_t *hsmbus, uint8_t command_code, uint8_t *buff, uint32_t timeout);

/*!
 * \brief  Handle Write word protocol received in slave mode.
 *
 * \details This function handles Write word protocol received in slave mode.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \param[in] buff is the pointer to data to be received
 * \param[in] timeout is timeout duration.
 *
 * \return status of function
 */
I2C_Status_t SMBUS_slaveHandleWriteWord(SMBUS_Handle_t *hsmbus, uint8_t *buff, uint32_t timeout);

/*!
 * \brief  Read byte protocol transfer in master mode.
 *
 * \details This function transfers data with Read byte protocol in master mode.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \param[in] command_code is protocol command code
 * \param[in] buff is the pointer to data to be received
 * \param[in] timeout is timeout duration.
 *
 * \return status of function
 */
I2C_Status_t SMBUS_masterReadByte(SMBUS_Handle_t *hsmbus, uint8_t command_code, uint8_t *buff, uint32_t timeout);

/*!
 * \brief  Handle Read byte protocol received in slave mode.
 *
 * \details This function handles Read byte protocol received in slave mode.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \param[in] send_data is the pointer to data to be sent
 * \param[in] recv_data is the pointer to data to be received
 * \param[in] timeout is timeout duration.
 *
 * \return status of function
 */
I2C_Status_t SMBUS_slaveHandleReadByte(SMBUS_Handle_t *hsmbus, uint8_t *send_data, uint8_t *recv_data,
                                       uint32_t timeout);

/*!
 * \brief  Read word protocol transfer in master mode.
 *
 * \details This function transfers data with Read word protocol in master mode.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \param[in] command_code is protocol command code
 * \param[in] buff is the pointer to data to be received
 * \param[in] timeout is timeout duration.
 *
 * \return status of function
 */
I2C_Status_t SMBUS_masterReadWord(SMBUS_Handle_t *hsmbus, uint8_t command_code, uint8_t *buff, uint32_t timeout);

/*!
 * \brief  Handle Read word protocol received in slave mode.
 *
 * \details This function handles Read word protocol received in slave mode.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \param[in] send_data is the pointer to data to be sent
 * \param[in] recv_data is the pointer to data to be received
 * \param[in] timeout is timeout duration.
 *
 * \return status of function
 */
I2C_Status_t SMBUS_slaveHandleReadWord(SMBUS_Handle_t *hsmbus, uint8_t *send_data, uint8_t *recv_data,
                                       uint32_t timeout);

/*!
 * \brief  Process call protocol transfer in master mode.
 *
 * \details This function transfers data with Process call protocol in master mode.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \param[in] command_code is protocol command code
 * \param[in] send_data is the pointer to data to be sent
 * \param[in] recv_data is the pointer to data to be received
 * \param[in] timeout is timeout duration.
 *
 * \return status of function
 */
I2C_Status_t SMBUS_masterProcessCall(SMBUS_Handle_t *hsmbus, uint8_t command_code, uint8_t *send_data,
                                     uint8_t *recv_data, uint32_t timeout);

/*!
 * \brief  Handle Process call protocol received in slave mode.
 *
 * \details This function handles Process call protocol received in slave mode.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \param[in] send_data is the pointer to data to be sent
 * \param[in] recv_data is the pointer to data to be received
 * \param[in] timeout is timeout duration.
 *
 * \return status of function
 */
I2C_Status_t SMBUS_slaveHandleProcessCall(SMBUS_Handle_t *hsmbus, uint8_t *send_data, uint8_t *recv_data,
                                          uint32_t timeout);

/*!
 * \brief  Block write protocol transfer in master mode.
 *
 * \details This function transmits data with Block write protocol in master mode.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \param[in] command_code is protocol command code
 * \param[in] buff is the pointer to data to be sent
 * \param[in] count is the number of data to be sent
 * \param[in] timeout is timeout duration.
 *
 * \return status of function
 */
I2C_Status_t SMBUS_masterBlockWrite(SMBUS_Handle_t *hsmbus, uint8_t command_code, uint8_t *buff, uint8_t count,
                                    uint32_t timeout);

/*!
 * \brief  Handle Block write protocol received in slave mode.
 *
 * \details This function handles Block write protocol received in slave mode.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \param[in] buff is the pointer to data to be received
 * \param[in] timeout is timeout duration.
 *
 * \return status of function
 */
I2C_Status_t SMBUS_slaveHandleBlockWrite(SMBUS_Handle_t *hsmbus, uint8_t *buff, uint32_t timeout);

/*!
 * \brief  Block read protocol transfer in master mode.
 *
 * \details This function transmits data with Block read protocol in master mode.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \param[in] command_code is protocol command code
 * \param[in] buff is the pointer to data to be received
 * \param[in] timeout is timeout duration.
 *
 * \return status of function
 */
I2C_Status_t SMBUS_masterBlockRead(SMBUS_Handle_t *hsmbus, uint8_t command_code, uint8_t *buff, uint32_t timeout);

/*!
 * \brief  Handle Block read protocol received in slave mode.
 *
 * \details This function handles Block read protocol received in slave mode.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \param[in] send_data is the pointer to data to be sent
 * \param[in] send_count is the number of data to be sent
 * \param[in] recv_data is the pointer to data to be received
 * \param[in] timeout is timeout duration.
 *
 * \return status of function
 */
I2C_Status_t SMBUS_slaveHandleBlockRead(SMBUS_Handle_t *hsmbus, uint8_t *send_data, uint8_t send_count,
                                        uint8_t *recv_data, uint32_t timeout);

/*!
 * \brief  Block write block read protocol transfer in master mode.
 *
 * \details This function transmits data with Block write block read protocol in master mode.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \param[in] command_code is protocol command code
 * \param[in] send_data is the pointer to data to be sent
 * \param[in] send_count is the number of data to be sent
 * \param[in] recv_data is the pointer to data to be received
 * \param[in] timeout is timeout duration.
 *
 * \return status of function
 */
I2C_Status_t SMBUS_masterBlockWriteBlockReadProcessCall(SMBUS_Handle_t *hsmbus, uint8_t command_code,
                                                        uint8_t *send_data, uint8_t send_count, uint8_t *recv_data,
                                                        uint32_t timeout);

/*!
 * \brief  Handle Block write block read protocol received in slave mode.
 *
 * \details This function handles Block write block read protocol received in slave mode.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \param[in] send_data is the pointer to data to be sent
 * \param[in] send_count is the number of data to be sent
 * \param[in] recv_data is the pointer to data to be received
 * \param[in] timeout is timeout duration.
 *
 * \return status of function
 */
I2C_Status_t SMBUS_slaveHandleBlockWriteBlockReadProcessCall(SMBUS_Handle_t *hsmbus, uint8_t *send_data,
                                                             uint8_t send_count, uint8_t *recv_data, uint32_t timeout);

/*!
 * \brief  Host notify protocol transfer in master mode.
 *
 * \details This function transmits data with Host notify protocol in master mode.
 *  It is used when a SMBus device, which is normally a target, becomes a controller for this
 * transaction in order to communicate with the SMBus Host (which acts as a target for
 * this transaction).
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \param[in] devAddr is the alerting device's address
 * \param[in] buff is the pointer to data to be received
 * \param[in] timeout is timeout duration.
 *
 * \return status of function
 */
I2C_Status_t SMBUS_masterHostNotifyProtocol(SMBUS_Handle_t *hsmbus, uint8_t devAddr, uint8_t *buff, uint32_t timeout);

/*!
 * \brief  Handle Host notify protocol received in slave mode.
 *
 * \details This function handles Host notify protocol received in slave mode.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \param[in] buff is the pointer to data to be sent
 * \param[in] timeout is timeout duration.
 *
 * \return status of function
 */
I2C_Status_t SMBUS_slaveHandleHostNotifyProtocol(SMBUS_Handle_t *hsmbus, uint8_t *buff, uint32_t timeout);

/*!
 * \brief  Enable the SMBUS interrupt.
 *
 * \details This function enable the SMBUS interrupt.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \param[in] intFlags is flag of interrupt
 */
void         SMBUS_enableInterrupt(SMBUS_Handle_t *hsmbus, uint32_t intFlags);

/*!
 * \brief  Disable the SMBUS interrupt.
 *
 * \details This function disable the SMBUS interrupt.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \param[in] intFlags is flag of interrupt
 */
void         SMBUS_disableInterrupt(SMBUS_Handle_t *hsmbus, uint32_t intFlags);

/*!
 * \brief  Clear the SMBUS interrupt.
 *
 * \details This function clears the SMBUS interrupt.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \param[in] intFlags is flag of interrupt
 */
void         SMBUS_clearInterrupt(SMBUS_Handle_t *hsmbus, uint32_t intFlags);

/*!
 * \brief  Gets the current SMBUS interrupt status.
 *
 * \details This function gets the current SMBUS interrupt status.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 *
 * \return current SMBUS interrupt status
 */
uint32_t     SMBUS_getInterruptStatus(SMBUS_Handle_t *hsmbus);

/*!
 * \brief  Slave initates the Alert signal to indicate SMBus Host
 *
 * \details This function initates the Alert signal to indicate SMBus Host
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 */
void         SMBUS_assertAlert(SMBUS_Handle_t *hsmbus);

/*!
 * \brief  Host/Master initates the SMBUS system to enter Suspend Mode.
 *
 * \details This function initates the SMBUS system to enter Suspend Mode.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 */
void         SMBUS_assertSuspend(SMBUS_Handle_t *hsmbus);

/*!
 * \brief  Host/Master de-asserts the SMBUS system to enter Suspend Mode.
 *
 * \details This function de-asserts the SMBUS system to enter Suspend Mode.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 */
void         SMBUS_deassertSuspend(SMBUS_Handle_t *hsmbus);

/*!
 * \brief  Gets the status of the SMBus Suspend signal
 *
 * \details This function gets the status of the SMBus Suspend signal
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \return 1 means SMBUS System is in Suspended mode, while 0 means SMBUS
 *          System is not in Suspended mode.
 */
bool         SMBUS_isSuspendAsserted(SMBUS_Handle_t *hsmbus);

/*!
 * \brief  Gets the status of the SMBus Alert signal
 *
 * \details This function gets the status of the SMBus Alert signal
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \return 1 means SMBUS Alert is asserted, while 0 means SMBUS Alert is not asserted.
 */
bool         SMBUS_isAlertAsserted(SMBUS_Handle_t *hsmbus);

/*!
 * \brief  Host/Master ARP initialization.
 *
 * \details This function init parameters for ARP.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 */
void SMBUS_masterARPInit(SMBUS_Handle_t *hsmbus);
/*!
 * \brief  Host/Master transmits Prepare to ARP command.
 *
 * \details This function transmits Prepare to ARP command.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \param[in] timeout is timeout duration.
 *
 * \return status of function
 */
I2C_Status_t SMBUS_prepareToARP(SMBUS_Handle_t *hsmbus, uint32_t timeout);

/*!
 * \brief  Host/Master transmits Reset device command.
 *
 * \details This function transmits Reset device command.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \param[in] target 0 means Reset device (general), forcing all non-PSA, ARP-capable devices to
 * return to their initial state and PSA devices clear their AR flag; 1 means Reset device (directed),
 * targeting a specific device.
 * \param[in] timeout is timeout duration.
 *
 * \return status of function
 */
I2C_Status_t SMBUS_resetDevice(SMBUS_Handle_t *hsmbus, uint8_t target, uint32_t timeout);

/*!
 * \brief  Host/Master transmits Get UDID command.
 *
 * \details This function transmits Get UDID command.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \param[in] target 0 means Get UDID (general), forcing all non-PSA, ARP-capable devices to
 * return to their initial state and PSA devices clear their AR flag; 1 means Get UDID (directed),
 * targeting a specific device.
 * \param[in] timeout is timeout duration.
 *
 * \return status of function
 */
I2C_Status_t SMBUS_getUDID(SMBUS_Handle_t *hsmbus, uint8_t target, uint32_t timeout);

/*!
 * \brief  Host/Master transmits Assign address command.
 *
 * \details This function transmits Assign address command.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \param[in] assignAddr is the address to be assigned to slave.
 * \param[in] timeout is timeout duration.
 *
 * \return status of function
 */
I2C_Status_t SMBUS_assignAddr(SMBUS_Handle_t *hsmbus, uint8_t assignAddr, uint32_t timeout);

/*!
 * \brief  Gets the status of the SMBUS slave address resolution.
 *
 * \details This function gets the status of the SMBUS slave address resolution.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \return 1 means SMBUS slave address is resolved, while 0 means SMBUS slave address is not resolved.
 */
bool SMBUS_isAddrResolved(SMBUS_Handle_t *hsmbus);

/*!
 * \brief  Gets the status of the SMBUS slave address validation.
 *
 * \details This function gets the status of the SMBUS slave address validation.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \return 1 means SMBUS slave address is valid, while 0 means SMBUS slave address is not valid.
 */
bool SMBUS_isAddrValid(SMBUS_Handle_t *hsmbus);

/*!
 * \brief  Gets resolved address.
 *
 * \details This function gets the current slave address if the address is valid.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \return The valid slave address. Note: 0xFF means SMBUS slave address is not valid.
 */
uint8_t SMBUS_getResolvedAddr(SMBUS_Handle_t *hsmbus);
/*!
 * \brief  Enable the SMBUS ARP control
 *
 * \details This function enable the SMBUS ARP control. The Slave mode
 * will decode the Address Resolution Protocol commands and respond to it.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 * \param[in] psa 1 means SMBUS persistent slave address control is enabled; 0 means SMBUS
 * persistent slave address control is disabled.
 */
void SMBUS_slaveEnableARP(SMBUS_Handle_t *hsmbus, uint8_t psa);

/*!
 * \brief  Disable the SMBUS ARP control
 *
 * \details This function disable the SMBUS ARP control.
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 */
void SMBUS_slaveDisableARP(SMBUS_Handle_t *hsmbus);

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */ /* end of DRV_HTE_SMBUS */

#endif /* HTE_SMBUS_H */
