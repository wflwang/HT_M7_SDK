/*
 * Copyright 2023 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_pmbus.c
 * \brief SDK PMBUS driver source file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "hte_pmbus.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* No Definitions */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * \brief PMBUS callback function which handles the interrupt flags master mode with interrupt
 *
 * \details This function handles the interrupt flags master mode with interrupt
 *
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 *
 */
void PMBUS_callback(SMBUS_Handle_t *hsmbus);


/*******************************************************************************
 * Variables
 ******************************************************************************/
/* No Variables */

/*******************************************************************************
 * Codes
 ******************************************************************************/

I2C_Status_t PMBUS_initMaster(PMBUS_Handle_t *hpmbus)
{
    return SMBUS_initMaster(hpmbus->hsmbus);
}

I2C_Status_t PMBUS_initSlave(PMBUS_Handle_t *hpmbus)
{
    return SMBUS_initSlave(hpmbus->hsmbus);
}

__WEAK void PMBUS_callback(SMBUS_Handle_t *hsmbus)
{
    UNUSED(hsmbus);
}

I2C_Status_t PMBUS_registerCallback(PMBUS_Handle_t *hpmbus, pSMBUS_Callback_t pCallback)
{
    if (pCallback == NULL)
    {
        return kSTATUS_I2C_ERROR;
    }
    hpmbus->pmbusCallback            = pCallback;
    SMBUS_getHandle()->smbusCallback = pCallback;
    return kSTATUS_I2C_OK;
}

I2C_Status_t PMBUS_unregisterCallback(PMBUS_Handle_t *hpmbus)
{
    hpmbus->pmbusCallback            = PMBUS_callback;
    SMBUS_getHandle()->smbusCallback = PMBUS_callback;
    return kSTATUS_I2C_OK;
}
I2C_Status_t PMBUS_masterGroupCommand(PMBUS_Handle_t *hpmbus, uint8_t *addr, uint32_t device_num, uint8_t *command_code,
                                      uint8_t *data, uint32_t data_num, uint32_t timeout)
{
    hpmbus->hsmbus->hi2c.targetAddr = *addr;
    addr++;
    /* Send command code */
    if (I2C_masterTransmitNostop(&hpmbus->hsmbus->hi2c, command_code, 1, timeout) != kSTATUS_I2C_OK)
    {
        return kSTATUS_I2C_ERROR;
    }

    /* Send data bytes */
    if (device_num == 1)
    {
        if (I2C_masterTransmit(&hpmbus->hsmbus->hi2c, data, data_num, timeout) != kSTATUS_I2C_OK)
        {
            return kSTATUS_I2C_ERROR;
        }
    }
    else
    {
        if (I2C_masterTransmitNostop(&hpmbus->hsmbus->hi2c, data, data_num, timeout) != kSTATUS_I2C_OK)
        {
            return kSTATUS_I2C_ERROR;
        }
    }
    command_code++;
    data += data_num;
    for (int i = 1; i < device_num; i++)
    {
        hpmbus->hsmbus->hi2c.targetAddr = *addr;
        addr++;
        if (i == device_num - 1)
        {
            /* When all devices have received their information, the master sends a STOP condition */
            if (I2C_masterTransmitSeq(&hpmbus->hsmbus->hi2c, command_code, 1, timeout, kI2C_OTHER_FRAME) !=
                    kSTATUS_I2C_OK ||
                I2C_masterTransmit(&hpmbus->hsmbus->hi2c, data, data_num, timeout) != kSTATUS_I2C_OK)
            {
                return kSTATUS_I2C_ERROR;
            }
            break;
        }
        /* Uses REPEATED START to separate commands for each device */
        if (I2C_masterTransmitSeq(&hpmbus->hsmbus->hi2c, command_code, 1, timeout, kI2C_OTHER_FRAME) !=
                kSTATUS_I2C_OK ||
            I2C_masterTransmitNostop(&hpmbus->hsmbus->hi2c, data, data_num, timeout) != kSTATUS_I2C_OK)
        {
            return kSTATUS_I2C_ERROR;
        }
        command_code++;
        data += data_num;
    }

    return kSTATUS_I2C_OK;
}

I2C_Status_t PMBUS_slaveHandleGroupCommand(PMBUS_Handle_t *hpmbus, uint32_t data_num, uint8_t *buff, uint32_t timeout)
{
    return I2C_slaveReceive(&hpmbus->hsmbus->hi2c, buff, data_num, timeout);
}

I2C_Status_t PMBUS_masterExtendWriteByte(PMBUS_Handle_t *hpmbus, uint8_t command_ext_code, uint8_t command_code,
                                         uint8_t *data, uint32_t timeout)
{
    if (I2C_masterTransmitNostop(&hpmbus->hsmbus->hi2c, &command_ext_code, 1, timeout) == kSTATUS_I2C_OK &&
        I2C_masterTransmitNostop(&hpmbus->hsmbus->hi2c, &command_code, 1, timeout) == kSTATUS_I2C_OK &&
        I2C_masterTransmit(&hpmbus->hsmbus->hi2c, data, 1, timeout) == kSTATUS_I2C_OK)
    {
        return kSTATUS_I2C_OK;
    }
    return kSTATUS_I2C_ERROR;
}

I2C_Status_t PMBUS_slaveHandleExtendWriteByte(PMBUS_Handle_t *hpmbus, uint8_t *buff, uint32_t timeout)
{
    return I2C_slaveReceive(&hpmbus->hsmbus->hi2c, buff, 3, timeout);
}

I2C_Status_t PMBUS_masterExtendWriteWord(PMBUS_Handle_t *hpmbus, uint8_t command_ext_code, uint8_t command_code,
                                         uint8_t *data, uint32_t timeout)
{
    if (I2C_masterTransmitNostop(&hpmbus->hsmbus->hi2c, &command_ext_code, 1, timeout) == kSTATUS_I2C_OK &&
        I2C_masterTransmitNostop(&hpmbus->hsmbus->hi2c, &command_code, 1, timeout) == kSTATUS_I2C_OK &&
        I2C_masterTransmit(&hpmbus->hsmbus->hi2c, data, 2, timeout) == kSTATUS_I2C_OK)
    {
        return kSTATUS_I2C_OK;
    }
    return kSTATUS_I2C_ERROR;
}

I2C_Status_t PMBUS_slaveHandleExtendWriteWord(PMBUS_Handle_t *hpmbus, uint8_t *buff, uint32_t timeout)
{
    return I2C_slaveReceive(&hpmbus->hsmbus->hi2c, buff, 4, timeout);
}

I2C_Status_t PMBUS_masterExtendReadByte(PMBUS_Handle_t *hpmbus, uint8_t command_ext_code, uint8_t command_code,
                                        uint8_t *buff, uint32_t timeout)
{
    if (I2C_masterTransmitNostop(&hpmbus->hsmbus->hi2c, &command_ext_code, 1, timeout) == kSTATUS_I2C_OK &&
        I2C_masterTransmitNostop(&hpmbus->hsmbus->hi2c, &command_code, 1, timeout) == kSTATUS_I2C_OK &&
        I2C_masterReceive(&hpmbus->hsmbus->hi2c, buff, 1, timeout) == kSTATUS_I2C_OK)
    {
        return kSTATUS_I2C_OK;
    }
    return kSTATUS_I2C_ERROR;
}

I2C_Status_t PMBUS_slaveHandleExtendReadByte(PMBUS_Handle_t *hpmbus, uint8_t *send_data, uint8_t *recv_data,
                                             uint32_t timeout)
{
    if (I2C_slaveReceive(&hpmbus->hsmbus->hi2c, recv_data, 2, timeout) == kSTATUS_I2C_OK &&
        I2C_slaveTransmit(&hpmbus->hsmbus->hi2c, send_data, 1, timeout) == kSTATUS_I2C_OK)
    {
        return kSTATUS_I2C_OK;
    }
    return kSTATUS_I2C_ERROR;
}

I2C_Status_t PMBUS_masterExtendReadWord(PMBUS_Handle_t *hpmbus, uint8_t command_ext_code, uint8_t command_code,
                                        uint8_t *buff, uint32_t timeout)
{
    if (I2C_masterTransmitNostop(&hpmbus->hsmbus->hi2c, &command_ext_code, 1, timeout) == kSTATUS_I2C_OK &&
        I2C_masterTransmitNostop(&hpmbus->hsmbus->hi2c, &command_code, 1, timeout) == kSTATUS_I2C_OK &&
        I2C_masterReceive(&hpmbus->hsmbus->hi2c, buff, 2, timeout) == kSTATUS_I2C_OK)
    {
        return kSTATUS_I2C_OK;
    }
    return kSTATUS_I2C_ERROR;
}

I2C_Status_t PMBUS_slaveHandleExtendReadWord(PMBUS_Handle_t *hpmbus, uint8_t *send_data, uint8_t *recv_data,
                                             uint32_t timeout)
{
    if (I2C_slaveReceive(&hpmbus->hsmbus->hi2c, recv_data, 2, timeout) == kSTATUS_I2C_OK &&
        I2C_slaveTransmit(&hpmbus->hsmbus->hi2c, send_data, 2, timeout) == kSTATUS_I2C_OK)
    {
        return kSTATUS_I2C_OK;
    }
    return kSTATUS_I2C_ERROR;
}
