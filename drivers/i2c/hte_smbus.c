/*
 * Copyright 2023 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_smbus.c
 * \brief SDK SMBUS driver source file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_smbus.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* No Definitions */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * \brief Compute the CRC value of a data buffer
 *
 * \details Compute the 8-bit CRC value of an 8-bit data buffer
 *         starting with base->CRC_INIT as initialization value.
 *
 * \param[in] data pointer to the input data buffer
 * \param[in] length input data buffer length (number of bytes)
 *
 * \return CRC
 */
static uint8_t SMBUS_crc8Calculate(const uint8_t *data, uint32_t length);

/*!
 * \brief SMBUS callback function which handles the interrupt flags master mode with interrupt
 *
 * \details This function handles the interrupt flags master mode with interrupt
 *
 * \param[in] hsmbus is the pointer to a SMBUS_Handle_t structure that contains
 *                the configuration information for the specified SMBUS.
 *
 */
void SMBUS_callback(SMBUS_Handle_t *hsmbus);
/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! \brief SMBUS transfer handle */
static SMBUS_Handle_t   s_hsmbus;
/*! \brief SMBUS ARP buffer */
static uint8_t          s_arpBuff[32];
/*******************************************************************************
 * Codes
 ******************************************************************************/
SMBUS_Handle_t *SMBUS_getHandle()
{
    return &s_hsmbus;
}

#if defined(PMBUSA)
void PMBUSA_DriverHandler()
{
    if (s_hsmbus.smbusCallback != NULL)
    {
        s_hsmbus.smbusCallback(&s_hsmbus);
    }
    ISR_EXIT_BARRIER();
}
#endif
static uint8_t SMBUS_crc8Calculate(const uint8_t *data, uint32_t length)
{
    uint8_t crc = 0;
    while (length--)
    {
        crc ^= *data++;
        for (int i = 0; i < 8; i++)
        {
            if (crc & 0x80)
            {
                crc = (crc << 1) ^ 0x07;
            }
            else
            {
                crc <<= 1;
            }
        }
    }
    return crc;
}

__WEAK void SMBUS_callback(SMBUS_Handle_t *hsmbus)
{
    UNUSED(hsmbus);
}

I2C_Status_t SMBUS_registerCallback(SMBUS_Handle_t *hsmbus, pSMBUS_Callback_t pCallback)
{
    if (pCallback == NULL)
    {
        return kSTATUS_I2C_ERROR;
    }
    hsmbus->smbusCallback = pCallback;
    return kSTATUS_I2C_OK;
}

I2C_Status_t SMBUS_unregisterCallback(SMBUS_Handle_t *hsmbus)
{
    hsmbus->smbusCallback = SMBUS_callback;
    return kSTATUS_I2C_OK;
}

I2C_Status_t SMBUS_initMaster(SMBUS_Handle_t *hsmbus)
{
    assert(hsmbus->hi2c.instance);

    /* Disable the selected SMBUS peripheral */
    I2C_disableModule(hsmbus->hi2c.instance);

    /* Configure SMBUS */
    hsmbus->hi2c.instance->IC_CON = (I2C_IC_CON_IC_SLAVE_DISABLE_Set(1U) | I2C_IC_CON_MASTER_MODE_Set(1U) |
                                     I2C_IC_CON_IC_10BITADDR_MASTER_Set(hsmbus->hi2c.init.addrMode) |
                                     I2C_IC_CON_SPEED_Set(hsmbus->hi2c.init.speedMode) |
                                     I2C_IC_CON_IC_RESTART_EN_Set(1U) | I2C_IC_CON_BUS_CLEAR_FEATURE_CTRL_Set(1U));

    hsmbus->hi2c.instance->IC_TAR = I2C_IC_TAR_IC_10BITADDR_MASTER_Set(hsmbus->hi2c.init.addrMode);

    I2C_setOwnAddress(hsmbus->hi2c.instance, hsmbus->hi2c.init.slaveAddr);
    I2C_setTargetAddress(hsmbus->hi2c.instance, hsmbus->hi2c.targetAddr);

    if (hsmbus->hi2c.init.speedMode == kI2C_STANDARD_SPEED_MODE)
    {
        hsmbus->hi2c.instance->IC_SS_SCL_HCNT = I2C_IC_SS_SCL_HCNT_IC_SS_SCL_HCNT_Set(hsmbus->hi2c.init.hcnt); //
        hsmbus->hi2c.instance->IC_SS_SCL_LCNT = I2C_IC_SS_SCL_LCNT_IC_SS_SCL_LCNT_Set(hsmbus->hi2c.init.hcnt); //
    }
    else if (hsmbus->hi2c.init.speedMode == kI2C_FAST_OR_FAST_PLUS_SPEED_MODE)
    {
        hsmbus->hi2c.instance->IC_FS_SCL_HCNT = I2C_IC_FS_SCL_HCNT_IC_FS_SCL_HCNT_Set(hsmbus->hi2c.init.hcnt); //
        hsmbus->hi2c.instance->IC_FS_SCL_LCNT = I2C_IC_FS_SCL_LCNT_IC_FS_SCL_LCNT_Set(hsmbus->hi2c.init.hcnt); //
    }

    hsmbus->hi2c.instance->IC_SDA_HOLD = I2C_IC_SDA_HOLD_IC_SDA_TX_HOLD_Set(hsmbus->hi2c.init.sdaTxHold) |
                                         I2C_IC_SDA_HOLD_IC_SDA_RX_HOLD_Set(hsmbus->hi2c.init.sdaRxHold);
    hsmbus->hi2c.instance->IC_SDA_SETUP = I2C_IC_SDA_SETUP_SDA_SETUP_Set(hsmbus->hi2c.init.sdaSetup);
    hsmbus->hi2c.instance->IC_SCL_STUCK_AT_LOW_TIMEOUT =
        I2C_IC_SCL_STUCK_AT_LOW_TIMEOUT_IC_SCL_STUCK_LOW_TIMEOUT_Set(hsmbus->hi2c.init.sclTimeout);
    hsmbus->hi2c.instance->IC_SMBUS_CLK_LOW_MEXT =
        I2C_IC_SMBUS_CLK_LOW_MEXT_SMBUS_CLK_LOW_MEXT_TIMEOUT_Set(hsmbus->mext);
    hsmbus->hi2c.instance->IC_SMBUS_CLK_LOW_SEXT =
        I2C_IC_SMBUS_CLK_LOW_SEXT_SMBUS_CLK_LOW_SEXT_TIMEOUT_Set(hsmbus->sext);

    if (hsmbus->hi2c.init.noSdaRecovery)
    {
        hsmbus->hi2c.instance->IC_ENABLE &= ~(I2C_IC_ENABLE_SDA_STUCK_RECOVERY_ENABLE_Set(1U));
    }
    else
    {
        hsmbus->hi2c.instance->IC_SDA_STUCK_AT_LOW_TIMEOUT =
            I2C_IC_SDA_STUCK_AT_LOW_TIMEOUT_IC_SDA_STUCK_LOW_TIMEOUT_Set(hsmbus->hi2c.init.sdaTimeout);
        hsmbus->hi2c.instance->IC_ENABLE |= I2C_IC_ENABLE_SDA_STUCK_RECOVERY_ENABLE_Set(1U);
    }

    /* Init the SMBUS Callback settings */
    hsmbus->smbusCallback = SMBUS_callback;

    I2C_disableInterrupt(hsmbus->hi2c.instance, 0xFFFF);
    SMBUS_disableInterrupt(hsmbus, 0xFFF);

    /* Enable the selected SMBUS peripheral */
    I2C_enableModule(hsmbus->hi2c.instance);
    hsmbus->hi2c.state = kI2C_READY;

    return kSTATUS_I2C_OK;
}

I2C_Status_t SMBUS_initSlave(SMBUS_Handle_t *hsmbus)
{
    assert(hsmbus->hi2c.instance);

    /* Disable the selected SMBUS peripheral */
    I2C_disableModule(hsmbus->hi2c.instance);

    /* Configure SMBUS */
    hsmbus->hi2c.instance->IC_SAR =
        (hsmbus->hi2c.instance->IC_SAR & (~I2C_IC_SAR_IC_SAR_Msk)) | I2C_IC_SAR_IC_SAR_Set(hsmbus->hi2c.init.slaveAddr);
    hsmbus->hi2c.instance->IC_CON = (I2C_IC_CON_IC_10BITADDR_SLAVE_Set(hsmbus->hi2c.init.addrMode) |
                                     I2C_IC_CON_SPEED_Set(hsmbus->hi2c.init.speedMode) |
                                     I2C_IC_CON_IC_RESTART_EN_Set(1U) | I2C_IC_CON_BUS_CLEAR_FEATURE_CTRL_Set(1U));

    hsmbus->hi2c.instance->IC_SDA_HOLD = I2C_IC_SDA_HOLD_IC_SDA_TX_HOLD_Set(hsmbus->hi2c.init.sdaTxHold) |
                                         I2C_IC_SDA_HOLD_IC_SDA_RX_HOLD_Set(hsmbus->hi2c.init.sdaRxHold);
    hsmbus->hi2c.instance->IC_SDA_SETUP = I2C_IC_SDA_SETUP_SDA_SETUP_Set(hsmbus->hi2c.init.sdaSetup);
    hsmbus->hi2c.instance->IC_SCL_STUCK_AT_LOW_TIMEOUT =
        I2C_IC_SCL_STUCK_AT_LOW_TIMEOUT_IC_SCL_STUCK_LOW_TIMEOUT_Set(hsmbus->hi2c.init.sclTimeout);
    hsmbus->hi2c.instance->IC_SMBUS_CLK_LOW_MEXT =
        I2C_IC_SMBUS_CLK_LOW_MEXT_SMBUS_CLK_LOW_MEXT_TIMEOUT_Set(hsmbus->mext);
    hsmbus->hi2c.instance->IC_SMBUS_CLK_LOW_SEXT =
        I2C_IC_SMBUS_CLK_LOW_SEXT_SMBUS_CLK_LOW_SEXT_TIMEOUT_Set(hsmbus->sext);

    /* Init the SMBUS Callback settings */
    hsmbus->smbusCallback = SMBUS_callback;
    I2C_disableInterrupt(hsmbus->hi2c.instance, 0xFFFF);
    SMBUS_disableInterrupt(hsmbus, 0xFFF);

    /* Enable the selected I2C peripheral */
    I2C_enableModule(hsmbus->hi2c.instance);
    hsmbus->hi2c.state = kI2C_READY;

    return kSTATUS_I2C_OK;
}

void SMBUS_configQuickCommand(SMBUS_Handle_t *hsmbus, uint8_t sel)
{
    I2C_disableModule(hsmbus->hi2c.instance);
    hsmbus->hi2c.instance->IC_TAR =
        (hsmbus->hi2c.instance->IC_TAR & ~(I2C_IC_TAR_SPECIAL_Msk | I2C_IC_TAR_SMBUS_QUICK_CMD_Msk)) |
        I2C_IC_TAR_SPECIAL_Set(sel) | I2C_IC_TAR_SMBUS_QUICK_CMD_Set(sel);
    I2C_enableModule(hsmbus->hi2c.instance);
}

I2C_Status_t SMBUS_masterQuickCommand(SMBUS_Handle_t *hsmbus, I2C_Cmd_t cmd, uint32_t timeout)
{
    uint32_t tickstart;
    if (hsmbus->hi2c.state == kI2C_BUSY)
    {
        return kSTATUS_I2C_BUSY;
    }
    /* Init tickstart for timeout management */
    tickstart = BOARD_getTick();

    /* Enable quick command */
    SMBUS_configQuickCommand(hsmbus, 1);

    /* Generate Write or Read command */
    I2C_putData(hsmbus->hi2c.instance, kI2C_STOP_CMD + cmd);

    /* Wait until STOP_DETECTED flag is set */
    if (I2C_waitOnFlag(&hsmbus->hi2c, kI2C_STOP_DETECTED, 0, timeout, tickstart) != kSTATUS_I2C_OK)
    {
        return kSTATUS_I2C_ERROR;
    }

    return kSTATUS_I2C_OK;
}

I2C_Status_t SMBUS_slaveEnableQuickCommand(SMBUS_Handle_t *hsmbus)
{
    I2C_disableModule(hsmbus->hi2c.instance);
    hsmbus->hi2c.instance->IC_CON |= I2C_IC_CON_SMBUS_SLAVE_QUICK_EN_Set(1U);
    I2C_enableModule(hsmbus->hi2c.instance);
    return kSTATUS_I2C_OK;
}

I2C_Status_t SMBUS_slaveDisableQuickCommand(SMBUS_Handle_t *hsmbus)
{
    I2C_disableModule(hsmbus->hi2c.instance);
    hsmbus->hi2c.instance->IC_CON &= ~I2C_IC_CON_SMBUS_SLAVE_QUICK_EN_Set(1U);
    I2C_enableModule(hsmbus->hi2c.instance);
    return kSTATUS_I2C_OK;
}

bool SMBUS_getQuickCmd(SMBUS_Handle_t *hsmbus)
{
    return I2C_IC_STATUS_SMBUS_QUICK_CMD_BIT_Get(hsmbus->hi2c.instance->IC_STATUS);
}

I2C_Status_t SMBUS_masterSendByte(SMBUS_Handle_t *hsmbus, uint8_t *buff, uint32_t timeout)
{
    return I2C_masterTransmit(&hsmbus->hi2c, buff, 1, timeout);
}

I2C_Status_t SMBUS_slaveHandleSendByte(SMBUS_Handle_t *hsmbus, uint8_t *buff, uint32_t timeout)
{
    return I2C_slaveReceive(&hsmbus->hi2c, buff, 1, timeout);
}

I2C_Status_t SMBUS_masterReceiveByte(SMBUS_Handle_t *hsmbus, uint8_t *buff, uint32_t timeout)
{
    return I2C_masterReceive(&hsmbus->hi2c, buff, 1, timeout);
}

I2C_Status_t SMBUS_slaveHandleReceiveByte(SMBUS_Handle_t *hsmbus, uint8_t *buff, uint32_t timeout)
{
    return I2C_slaveTransmit(&hsmbus->hi2c, buff, 1, timeout);
}

I2C_Status_t SMBUS_masterWriteByte(SMBUS_Handle_t *hsmbus, uint8_t command_code, uint8_t *buff, uint32_t timeout)
{
    uint8_t data[2] = { command_code, *buff };
    return I2C_masterTransmit(&hsmbus->hi2c, data, 2, timeout);
}

I2C_Status_t SMBUS_slaveHandleWriteByte(SMBUS_Handle_t *hsmbus, uint8_t *buff, uint32_t timeout)
{
    return I2C_slaveReceive(&hsmbus->hi2c, buff, 2, timeout);
}

I2C_Status_t SMBUS_masterWriteWord(SMBUS_Handle_t *hsmbus, uint8_t command_code, uint8_t *buff, uint32_t timeout)
{
    uint8_t data[3] = { command_code, *buff, *(buff + 1) };
    return I2C_masterTransmit(&hsmbus->hi2c, data, 3, timeout);
}

I2C_Status_t SMBUS_slaveHandleWriteWord(SMBUS_Handle_t *hsmbus, uint8_t *buff, uint32_t timeout)
{
    return I2C_slaveReceive(&hsmbus->hi2c, buff, 3, timeout);
}

I2C_Status_t SMBUS_masterReadByte(SMBUS_Handle_t *hsmbus, uint8_t command_code, uint8_t *buff, uint32_t timeout)
{
    if (I2C_masterTransmitNostop(&hsmbus->hi2c, &command_code, 1, timeout) == kSTATUS_I2C_OK &&
        I2C_masterReceive(&hsmbus->hi2c, buff, 1, timeout) == kSTATUS_I2C_OK)
    {
        return kSTATUS_I2C_OK;
    }
    return kSTATUS_I2C_ERROR;
}

I2C_Status_t SMBUS_slaveHandleReadByte(SMBUS_Handle_t *hsmbus, uint8_t *send_data, uint8_t *recv_data, uint32_t timeout)
{
    if (I2C_slaveReceive(&hsmbus->hi2c, recv_data, 1, timeout) == kSTATUS_I2C_OK &&
        I2C_slaveTransmit(&hsmbus->hi2c, send_data, 1, timeout) == kSTATUS_I2C_OK)
    {
        return kSTATUS_I2C_OK;
    }
    return kSTATUS_I2C_ERROR;
}

I2C_Status_t SMBUS_masterReadWord(SMBUS_Handle_t *hsmbus, uint8_t command_code, uint8_t *buff, uint32_t timeout)
{
    if (I2C_masterTransmitNostop(&hsmbus->hi2c, &command_code, 1, timeout) == kSTATUS_I2C_OK &&
        I2C_masterReceive(&hsmbus->hi2c, buff, 2, timeout) == kSTATUS_I2C_OK)
    {
        return kSTATUS_I2C_OK;
    }
    return kSTATUS_I2C_ERROR;
}

I2C_Status_t SMBUS_slaveHandleReadWord(SMBUS_Handle_t *hsmbus, uint8_t *send_data, uint8_t *recv_data, uint32_t timeout)
{
    if (I2C_slaveReceive(&hsmbus->hi2c, recv_data, 1, timeout) == kSTATUS_I2C_OK &&
        I2C_slaveTransmit(&hsmbus->hi2c, send_data, 2, timeout) == kSTATUS_I2C_OK)
    {
        return kSTATUS_I2C_OK;
    }
    return kSTATUS_I2C_ERROR;
}

I2C_Status_t SMBUS_masterProcessCall(SMBUS_Handle_t *hsmbus, uint8_t command_code, uint8_t *send_data,
                                     uint8_t *recv_data, uint32_t timeout)
{
    uint8_t data[] = { command_code, *send_data, *(send_data + 1) };
    if (I2C_masterTransmitNostop(&hsmbus->hi2c, data, 3, timeout) == kSTATUS_I2C_OK &&
        I2C_masterReceive(&hsmbus->hi2c, recv_data, 2, timeout) == kSTATUS_I2C_OK)
    {
        return kSTATUS_I2C_OK;
    }
    return kSTATUS_I2C_ERROR;
}

I2C_Status_t SMBUS_slaveHandleProcessCall(SMBUS_Handle_t *hsmbus, uint8_t *send_data, uint8_t *recv_data,
                                          uint32_t timeout)
{
    if (I2C_slaveReceive(&hsmbus->hi2c, recv_data, 3, timeout) == kSTATUS_I2C_OK &&
        I2C_slaveTransmit(&hsmbus->hi2c, send_data, 2, timeout) == kSTATUS_I2C_OK)
    {
        return kSTATUS_I2C_OK;
    }
    return kSTATUS_I2C_ERROR;
}

I2C_Status_t SMBUS_masterBlockWrite(SMBUS_Handle_t *hsmbus, uint8_t command_code, uint8_t *buff, uint8_t count,
                                    uint32_t timeout)
{
    assert(count <= 32);
    if (I2C_masterTransmitNostop(&hsmbus->hi2c, &command_code, 1, timeout) == kSTATUS_I2C_OK &&
        I2C_masterTransmitNostop(&hsmbus->hi2c, &count, 1, timeout) == kSTATUS_I2C_OK &&
        I2C_masterTransmit(&hsmbus->hi2c, buff, count, timeout) == kSTATUS_I2C_OK)
    {
        return kSTATUS_I2C_OK;
    }
    return kSTATUS_I2C_ERROR;
}

I2C_Status_t SMBUS_slaveHandleBlockWrite(SMBUS_Handle_t *hsmbus, uint8_t *buff, uint32_t timeout)
{
    if (I2C_slaveReceive(&hsmbus->hi2c, buff, 2, timeout) == kSTATUS_I2C_OK &&
        I2C_slaveReceive(&hsmbus->hi2c, buff + 2, buff[1], timeout) == kSTATUS_I2C_OK)
    {
        return kSTATUS_I2C_OK;
    }
    return kSTATUS_I2C_ERROR;
}

I2C_Status_t SMBUS_masterBlockRead(SMBUS_Handle_t *hsmbus, uint8_t command_code, uint8_t *buff, uint32_t timeout)
{
    if (I2C_masterTransmitNostop(&hsmbus->hi2c, &command_code, 1, timeout) == kSTATUS_I2C_OK &&
        I2C_masterReceiveNostop(&hsmbus->hi2c, buff, 1, timeout) == kSTATUS_I2C_OK &&
        I2C_masterReceive(&hsmbus->hi2c, buff + 1, buff[0], timeout) == kSTATUS_I2C_OK)
    {
        return kSTATUS_I2C_OK;
    }
    return kSTATUS_I2C_ERROR;
}

I2C_Status_t SMBUS_slaveHandleBlockRead(SMBUS_Handle_t *hsmbus, uint8_t *send_data, uint8_t send_count,
                                        uint8_t *recv_data, uint32_t timeout)
{
    if (I2C_slaveReceive(&hsmbus->hi2c, recv_data, 1, timeout) == kSTATUS_I2C_OK &&
        I2C_slaveTransmit(&hsmbus->hi2c, &send_count, 1, timeout) == kSTATUS_I2C_OK &&
        I2C_slaveTransmit(&hsmbus->hi2c, send_data, send_count, timeout) == kSTATUS_I2C_OK)
    {
        return kSTATUS_I2C_OK;
    }
    return kSTATUS_I2C_ERROR;
}

I2C_Status_t SMBUS_masterBlockWriteBlockReadProcessCall(SMBUS_Handle_t *hsmbus, uint8_t command_code,
                                                        uint8_t *send_data, uint8_t send_count, uint8_t *recv_data,
                                                        uint32_t timeout)
{
    if (I2C_masterTransmitNostop(&hsmbus->hi2c, &command_code, 1, timeout) == kSTATUS_I2C_OK &&
        I2C_masterTransmitNostop(&hsmbus->hi2c, &send_count, 1, timeout) == kSTATUS_I2C_OK &&
        I2C_masterTransmitNostop(&hsmbus->hi2c, send_data, send_count, timeout) == kSTATUS_I2C_OK &&
        I2C_masterReceiveNostop(&hsmbus->hi2c, recv_data, 1, timeout) == kSTATUS_I2C_OK &&
        I2C_masterReceive(&hsmbus->hi2c, recv_data + 1, recv_data[0], timeout) == kSTATUS_I2C_OK)
    {
        return kSTATUS_I2C_OK;
    }
    return kSTATUS_I2C_ERROR;
}

I2C_Status_t SMBUS_slaveHandleBlockWriteBlockReadProcessCall(SMBUS_Handle_t *hsmbus, uint8_t *send_data,
                                                             uint8_t send_count, uint8_t *recv_data, uint32_t timeout)
{
    if (I2C_slaveReceive(&hsmbus->hi2c, recv_data, 2, timeout) == kSTATUS_I2C_OK &&
        I2C_slaveReceive(&hsmbus->hi2c, recv_data + 2, recv_data[1], timeout) == kSTATUS_I2C_OK &&
        I2C_slaveTransmit(&hsmbus->hi2c, &send_count, 1, timeout) == kSTATUS_I2C_OK &&
        I2C_slaveTransmit(&hsmbus->hi2c, send_data, send_count, timeout) == kSTATUS_I2C_OK)
    {
        return kSTATUS_I2C_OK;
    }
    return kSTATUS_I2C_ERROR;
}

I2C_Status_t SMBUS_masterHostNotifyProtocol(SMBUS_Handle_t *hsmbus, uint8_t devAddr, uint8_t *buff, uint32_t timeout)
{
    uint8_t data[3]         = { devAddr, *buff, *(buff + 1) };
    hsmbus->hi2c.targetAddr = SMBUS_HOST_ADDR;
    return I2C_masterTransmit(&hsmbus->hi2c, data, 3, timeout);
}

I2C_Status_t SMBUS_slaveHandleHostNotifyProtocol(SMBUS_Handle_t *hsmbus, uint8_t *buff, uint32_t timeout)
{
    I2C_disableModule(hsmbus->hi2c.instance);
    I2C_setOwnAddress(hsmbus->hi2c.instance, SMBUS_HOST_ADDR);
    I2C_enableModule(hsmbus->hi2c.instance);

    return I2C_slaveReceive(&hsmbus->hi2c, buff, 3, timeout);
}

void SMBUS_enableInterrupt(SMBUS_Handle_t *hsmbus, uint32_t intFlags)
{
    hsmbus->hi2c.instance->IC_SMBUS_INTR_MASK = intFlags;
}

void SMBUS_disableInterrupt(SMBUS_Handle_t *hsmbus, uint32_t intFlags)
{
    hsmbus->hi2c.instance->IC_SMBUS_INTR_MASK &= ~intFlags;
}

void SMBUS_clearInterrupt(SMBUS_Handle_t *hsmbus, uint32_t intFlags)
{
    hsmbus->hi2c.instance->IC_CLR_SMBUS_INTR |= intFlags;
}

uint32_t SMBUS_getInterruptStatus(SMBUS_Handle_t *hsmbus)
{
    return (hsmbus->hi2c.instance->IC_SMBUS_INTR_STAT);
}

void SMBUS_assertAlert(SMBUS_Handle_t *hsmbus)
{
    hsmbus->hi2c.instance->IC_ENABLE |= I2C_IC_ENABLE_SMBUS_ALERT_EN_Set(1U);
}

void SMBUS_assertSuspend(SMBUS_Handle_t *hsmbus)
{
    hsmbus->hi2c.instance->IC_ENABLE |= I2C_IC_ENABLE_SMBUS_SUSPEND_EN_Set(1U);
}

void SMBUS_deassertSuspend(SMBUS_Handle_t *hsmbus)
{
    hsmbus->hi2c.instance->IC_ENABLE &= ~I2C_IC_ENABLE_SMBUS_SUSPEND_EN_Set(1U);
}

bool SMBUS_isSuspendAsserted(SMBUS_Handle_t *hsmbus)
{
    return (I2C_IC_STATUS_SMBUS_SUSPEND_STATUS_Get(hsmbus->hi2c.instance->IC_STATUS) == 1);
}

bool SMBUS_isAlertAsserted(SMBUS_Handle_t *hsmbus)
{
    return (I2C_IC_STATUS_SMBUS_ALERT_STATUS_Get(hsmbus->hi2c.instance->IC_STATUS) == 1);
}

void SMBUS_masterARPInit(SMBUS_Handle_t *hsmbus)
{
    hsmbus->hi2c.targetAddr = SMBUS_DEVICE_DEFAULT_ADDR;

    s_arpBuff[0] = 0xC2;
}

I2C_Status_t SMBUS_prepareToARP(SMBUS_Handle_t *hsmbus, uint32_t timeout)
{
    s_arpBuff[1] = kSMBUS_PREPARE_TO_ARP;

    /* Add PEC byte to the end */
    s_arpBuff[2] = SMBUS_crc8Calculate(s_arpBuff, 2);

    if (I2C_masterTransmit(&hsmbus->hi2c, s_arpBuff + 1, 2, timeout) != kSTATUS_I2C_OK)
    {
        return kSTATUS_I2C_ERROR;
    }
    return kSTATUS_I2C_OK;
}

I2C_Status_t SMBUS_resetDevice(SMBUS_Handle_t *hsmbus, uint8_t target, uint32_t timeout)
{
    if (target == 0)
    {
        s_arpBuff[1] = kSMBUS_RESET_DEVICE_GENERAL;
    }
    else
    {
        s_arpBuff[1] = target << 1;
    }

    /* Add PEC byte to the end */
    s_arpBuff[2] = SMBUS_crc8Calculate(s_arpBuff, 2);
    if (I2C_masterTransmit(&hsmbus->hi2c, s_arpBuff + 1, 2, timeout) != kSTATUS_I2C_OK)
    {
        return kSTATUS_I2C_ERROR;
    }
    return kSTATUS_I2C_OK;
}

I2C_Status_t SMBUS_getUDID(SMBUS_Handle_t *hsmbus, uint8_t target, uint32_t timeout)
{
    uint8_t command[1];
    /* General operation */
    if (target == 0)
    {
        command[0] = kSMBUS_GET_UDID_GENERAL;
        if (I2C_masterTransmitNostop(&hsmbus->hi2c, command, 1, timeout) != kSTATUS_I2C_OK ||
            I2C_masterReceive(&hsmbus->hi2c, s_arpBuff + 3, 19, timeout) != kSTATUS_I2C_OK || s_arpBuff[3] != 17)
        {
            return kSTATUS_I2C_ERROR;
        }
    }
    /* Directed operation */
    else
    {
        command[0] = (target << 1) + 1;
        if (I2C_masterTransmitNostop(&hsmbus->hi2c, command, 1, timeout) != kSTATUS_I2C_OK ||
            I2C_masterReceive(&hsmbus->hi2c, s_arpBuff + 3, 19, timeout) != kSTATUS_I2C_OK || s_arpBuff[3] != 17)
        {
            return kSTATUS_I2C_ERROR;
        }
    }
    s_arpBuff[1] = command[0];
    s_arpBuff[2] = 0xC3;
    if (SMBUS_crc8Calculate(s_arpBuff, 21) != s_arpBuff[21])
    {
        return kSTATUS_I2C_ERROR;
    }
    return kSTATUS_I2C_OK;
}

I2C_Status_t SMBUS_assignAddr(SMBUS_Handle_t *hsmbus, uint8_t assignAddr, uint32_t timeout)
{
    s_arpBuff[1]  = 0xC2;
    s_arpBuff[2]  = kSMBUS_ASSIGN_ADDRESS;
    s_arpBuff[20] = assignAddr;
    s_arpBuff[21] = SMBUS_crc8Calculate(s_arpBuff + 1, 20);
    return I2C_masterTransmit(&hsmbus->hi2c, s_arpBuff + 2, 20, timeout);
}

bool SMBUS_isAddrResolved(SMBUS_Handle_t *hsmbus)
{
    return (I2C_IC_STATUS_SMBUS_SLAVE_ADDR_RESOLVED_Get(hsmbus->hi2c.instance->IC_STATUS) == 1);
}

bool SMBUS_isAddrValid(SMBUS_Handle_t *hsmbus)
{
    return (I2C_IC_STATUS_SMBUS_SLAVE_ADDR_VALID_Get(hsmbus->hi2c.instance->IC_STATUS) == 1);
}

uint8_t SMBUS_getResolvedAddr(SMBUS_Handle_t *hsmbus)
{
    if (SMBUS_isAddrValid(hsmbus))
    {
        return I2C_getOwnAddress(hsmbus->hi2c.instance);
    }
    else
    {
        return 0xFF;
    }
}

void SMBUS_slaveEnableARP(SMBUS_Handle_t *hsmbus, uint8_t psa)
{
    I2C_disableModule(hsmbus->hi2c.instance);
    hsmbus->hi2c.instance->IC_CON |= I2C_IC_CON_SMBUS_ARP_EN_Set(1U);
    hsmbus->hi2c.instance->IC_CON |= I2C_IC_CON_SMBUS_PERSISTENT_SLV_ADDR_EN_Set(psa);
    I2C_enableModule(hsmbus->hi2c.instance);
}

void SMBUS_slaveDisableARP(SMBUS_Handle_t *hsmbus)
{
    I2C_disableModule(hsmbus->hi2c.instance);
    hsmbus->hi2c.instance->IC_CON &= ~(I2C_IC_CON_SMBUS_ARP_EN_Set(1U));
    hsmbus->hi2c.instance->IC_CON &= ~(I2C_IC_CON_SMBUS_PERSISTENT_SLV_ADDR_EN_Set(1U));
    I2C_enableModule(hsmbus->hi2c.instance);
}