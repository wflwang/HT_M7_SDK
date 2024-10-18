/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_pmbus.h
 * \brief SDK PMBUS driver header file
 * \version 1.0.0
 */

#ifndef HTE_PMBUS_H
#define HTE_PMBUS_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_smbus.h"

/*!
 * \addtogroup DRV_HTE_PMBUS PMBUS Driver
 *
 * \brief SDK PMBUS driver
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! \brief PMBUS handle Structure definition */
typedef struct __PMBUS_Handle_t
{
    SMBUS_Handle_t *hsmbus;                                 /*!< Pointer to SMBUS handle structure */
    void (*pmbusCallback)(struct __SMBUS_Handle_t *hsmbus); /*!< PMBUS callback function */
} PMBUS_Handle_t;

/*******************************************************************************
 * APIs
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief  Register a User PMBUS Callback
 *
 * \details This function registers a User PMBUS Callback
 *
 * \param[in] hpmbus is the pointer to a PMBUS_Handle_t structure that contains
 *                the configuration information for the specified PMBUS.
 * \param[in] pCallback is the pointer to the Callback function
 *
 * \return status of function
 */
I2C_Status_t PMBUS_registerCallback(PMBUS_Handle_t *hpmbus, pSMBUS_Callback_t pCallback);

/*!
 * \brief  Unregister a User PMBUS Callback
 *
 * \details This function unregisters a User PMBUS Callback
 *
 * \param[in] hpmbus is the pointer to a PMBUS_Handle_t structure that contains
 *                the configuration information for the specified PMBUS.
 *
 * \return status of function
 */
I2C_Status_t PMBUS_unregisterCallback(PMBUS_Handle_t *hpmbus);
/*!
 * \brief  Initializes the PMBUS Master.
 *
 * \details This function initializes the PMBUS in master mode.
 *
 * \param[in] hpmbus is the pointer to a PMBUS_Handle_t structure that contains
 *                the configuration information for the specified PMBUS.
 * \return status of function
 */
I2C_Status_t PMBUS_initMaster(PMBUS_Handle_t *hpmbus);

/*!
 * \brief  Initializes the PMBUS Slave.
 *
 * \details This function initializes the PMBUS in slave mode.
 *
 * \param[in] hpmbus is the pointer to a PMBUS_Handle_t structure that contains
 *                the configuration information for the specified PMBUS.
 * \return status of function
 */
I2C_Status_t PMBUS_initSlave(PMBUS_Handle_t *hpmbus);

/*!
 * \brief  Group command protocol transfer in master mode.
 *
 * \details This function transmits data with Group command protocol in master mode.
 *
 * \param[in] hpmbus is the pointer to a PMBUS_Handle_t structure that contains
 *                the configuration information for the specified PMBUS.
 * \param[in] addr is the pointer to target addresses
 * \param[in] device_num is the number of devices
 * \param[in] command_code is protocol command code
 * \param[in] data is the pointer to data to be sent
 * \param[in] data_num is the number of bytes sent to a target device
 * \param[in] timeout is timeout duration.
 *
 * \return status of function
 */
I2C_Status_t PMBUS_masterGroupCommand(PMBUS_Handle_t *hpmbus, uint8_t *addr, uint32_t device_num, uint8_t *command_code,
                                      uint8_t *data, uint32_t data_num, uint32_t timeout);

/*!
 * \brief  Handle group command protocol received in slave mode.
 *
 * \details This function handles group command protocol received in slave mode.
 *
 * \param[in] hpmbus is the pointer to a PMBUS_Handle_t structure that contains
 *                the configuration information for the specified PMBUS.
 * \param[in] data_num is the number of bytes sent to a target device
 * \param[in] buff is the pointer to data to be received
 * \param[in] timeout is timeout duration.
 *
 * \return status of function
 */
I2C_Status_t PMBUS_slaveHandleGroupCommand(PMBUS_Handle_t *hpmbus, uint32_t data_num, uint8_t *buff, uint32_t timeout);

/*!
 * \brief  Extend write byte protocol transfer in master mode.
 *
 * \details This function transmits data with Extend write byte protocol in master mode.
 *
 * \param[in] hpmbus is the pointer to a PMBUS_Handle_t structure that contains
 *                the configuration information for the specified PMBUS.
 * \param[in] command_ext_code is protocol extend command code
 * \param[in] command_code is protocol command code
 * \param[in] data is the pointer to data to be sent
 * \param[in] timeout is timeout duration.
 *
 * \return status of function
 */
I2C_Status_t PMBUS_masterExtendWriteByte(PMBUS_Handle_t *hpmbus, uint8_t command_ext_code, uint8_t command_code,
                                         uint8_t *data, uint32_t timeout);

/*!
 * \brief  Handle extend write byte protocol received in slave mode.
 *
 * \details This function handles extend write byte protocol received in slave mode.
 *
 * \param[in] hpmbus is the pointer to a PMBUS_Handle_t structure that contains
 *                the configuration information for the specified PMBUS.
 * \param[in] buff is the pointer to data to be received
 * \param[in] timeout is timeout duration.
 *
 * \return status of function
 */
I2C_Status_t PMBUS_slaveHandleExtendWriteByte(PMBUS_Handle_t *hpmbus, uint8_t *buff, uint32_t timeout);

/*!
 * \brief  Extend write word protocol transfer in master mode.
 *
 * \details This function transmits data with Extend write word protocol in master mode.
 *
 * \param[in] hpmbus is the pointer to a PMBUS_Handle_t structure that contains
 *                the configuration information for the specified PMBUS.
 * \param[in] command_ext_code is protocol extend command code
 * \param[in] command_code is protocol command code
 * \param[in] data is the pointer to data to be sent
 * \param[in] timeout is timeout duration.
 *
 * \return status of function
 */
I2C_Status_t PMBUS_masterExtendWriteWord(PMBUS_Handle_t *hpmbus, uint8_t command_ext_code, uint8_t command_code,
                                         uint8_t *data, uint32_t timeout);

/*!
 * \brief  Handle extend write word protocol received in slave mode.
 *
 * \details This function handles extend write word protocol received in slave mode.
 *
 * \param[in] hpmbus is the pointer to a PMBUS_Handle_t structure that contains
 *                the configuration information for the specified PMBUS.
 * \param[in] buff is the pointer to data to be received
 * \param[in] timeout is timeout duration.
 *
 * \return status of function
 */
I2C_Status_t PMBUS_slaveHandleExtendWriteWord(PMBUS_Handle_t *hpmbus, uint8_t *buff, uint32_t timeout);

/*!
 * \brief  Extend read byte protocol transfer in master mode.
 *
 * \details This function transmits data with Extend read byte protocol in master mode.
 *
 * \param[in] hpmbus is the pointer to a PMBUS_Handle_t structure that contains
 *                the configuration information for the specified PMBUS.
 * \param[in] command_ext_code is protocol extend command code
 * \param[in] command_code is protocol command code
 * \param[in] buff is the pointer to data to be received
 * \param[in] timeout is timeout duration.
 *
 * \return status of function
 */
I2C_Status_t PMBUS_masterExtendReadByte(PMBUS_Handle_t *hpmbus, uint8_t command_ext_code, uint8_t command_code,
                                        uint8_t *buff, uint32_t timeout);

/*!
 * \brief  Handle extend read byte protocol received in slave mode.
 *
 * \details This function handles extend read byte protocol received in slave mode.
 *
 * \param[in] hpmbus is the pointer to a PMBUS_Handle_t structure that contains
 *                the configuration information for the specified PMBUS.
 * \param[in] send_data is the pointer to data to be sent
 * \param[in] recv_data is the pointer to data to be received
 * \param[in] timeout is timeout duration.
 *
 * \return status of function
 */
I2C_Status_t PMBUS_slaveHandleExtendReadByte(PMBUS_Handle_t *hpmbus, uint8_t *send_data, uint8_t *recv_data,
                                             uint32_t timeout);

/*!
 * \brief  Extend read word protocol transfer in master mode.
 *
 * \details This function transmits data with Extend read word protocol in master mode.
 *
 * \param[in] hpmbus is the pointer to a PMBUS_Handle_t structure that contains
 *                the configuration information for the specified PMBUS.
 * \param[in] command_ext_code is protocol extend command code
 * \param[in] command_code is protocol command code
 * \param[in] buff is the pointer to data to be received
 * \param[in] timeout is timeout duration.
 *
 * \return status of function
 */
I2C_Status_t PMBUS_masterExtendReadWord(PMBUS_Handle_t *hpmbus, uint8_t command_ext_code, uint8_t command_code,
                                        uint8_t *buff, uint32_t timeout);

/*!
 * \brief  Handle extend read word protocol received in slave mode.
 *
 * \details This function handles extend read word protocol received in slave mode.
 *
 * \param[in] hpmbus is the pointer to a PMBUS_Handle_t structure that contains
 *                the configuration information for the specified PMBUS.
 * \param[in] send_data is the pointer to data to be sent
 * \param[in] recv_data is the pointer to data to be received
 * \param[in] timeout is timeout duration.
 *
 * \return status of function
 */
I2C_Status_t PMBUS_slaveHandleExtendReadWord(PMBUS_Handle_t *hpmbus, uint8_t *send_data, uint8_t *recv_data,
                                             uint32_t timeout);

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */ /* end of DRV_HTE_PMBUS */

#endif /* HTE_PMBUS_H */
