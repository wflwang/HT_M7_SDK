/*
 * Copyright 2023 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_i2c.c
 * \brief SDK I2C driver source file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "hte_i2c.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* No Definitions */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * \brief Interrupt sub-Routine which handle the interrupt flags master mode with interrupt.
 *
 * \details This function handles the interrupt flags master mode with interrupt.
 *
 * \param[in] hi2c is the pointer to a I2C_HandleTypeDef structure that contains
 *                the configuration information for the specified I2C.
 *
 * \return status of function
 */
static I2C_Status_t I2C_masterIsrIT(struct __I2C_Handle_t *hi2c);

/*!
 * \brief Interrupt sub-Routine which handle the interrupt flags slave mode with interrupt.
 *
 * \details This function handles the interrupt flags slave mode with interrupt.
 *
 * \param[in] hi2c is the pointer to a I2C_HandleTypeDef structure that contains
 *                the configuration information for the specified I2C.
 *
 * \return status of function
 */
static I2C_Status_t I2C_slaveIsrIT(struct __I2C_Handle_t *hi2c);

/*!
 * \brief Transfer completed callback
 *
 * \details This function is called when the transfer is finish.
 *
 * \param[in] hi2c is the pointer to a I2C_HandleTypeDef structure that contains
 *                the configuration information for the specified I2C.
 * \param[in] status indicates the status of the transfer
 *
 */
__WEAK void I2C_itCpltCallback(I2C_Handle_t *hi2c, I2C_Status_t status);


/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! \brief Array of I2C transfer handle */
static I2C_Handle_t s_hi2c[kI2C_INDEX_MAX];

/*******************************************************************************
 * Codes
 ******************************************************************************/

I2C_Handle_t *I2C_getHandle(I2C_Index_t index)
{
    return s_hi2c + index;
}

#if defined(I2CA)
void I2CA_DriverHandler(void)
{
    if (s_hi2c[kI2C_INDEX_A].xferISR != NULL)
    {
        s_hi2c[kI2C_INDEX_A].xferISR(&s_hi2c[kI2C_INDEX_A]);
    }
    ISR_EXIT_BARRIER();
}
#endif

#if defined(I2CB)
void I2CB_DriverHandler(void)
{
    if (s_hi2c[kI2C_INDEX_B].xferISR != NULL)
    {
        s_hi2c[kI2C_INDEX_B].xferISR(&s_hi2c[kI2C_INDEX_B]);
    }
    ISR_EXIT_BARRIER();
}
#endif

__WEAK void I2C_itCpltCallback(I2C_Handle_t *hi2c, I2C_Status_t status)
{
    UNUSED(hi2c);
    UNUSED(status);
}

I2C_Status_t I2C_registerCallback(I2C_Handle_t *hi2c, pI2C_Callback_t pCallback)
{
    assert(hi2c != NULL);

    if (pCallback == NULL || hi2c->state != kI2C_READY)
    {
        return kSTATUS_I2C_ERROR;
    }
    hi2c->itCpltCallback = pCallback;
    return kSTATUS_I2C_OK;
}

I2C_Status_t I2C_unRegisterCallback(I2C_Handle_t *hi2c)
{
    assert(hi2c != NULL);

    if (hi2c->state != kI2C_READY)
    {
        return kSTATUS_I2C_ERROR;
    }
    hi2c->itCpltCallback = I2C_itCpltCallback;
    return kSTATUS_I2C_OK;
}

I2C_Status_t I2C_initMaster(I2C_Handle_t *hi2c)
{
    assert(hi2c != NULL);

    hi2c->state = kI2C_BUSY;

    /* Disable the selected I2C peripheral */
    I2C_disableModule(hi2c->instance);

    /* Configure I2C */
    hi2c->instance->IC_CON =
        (I2C_IC_CON_IC_SLAVE_DISABLE_Set(1U) | I2C_IC_CON_MASTER_MODE_Set(1U) |
         I2C_IC_CON_IC_10BITADDR_MASTER_Set(hi2c->init.addrMode) | I2C_IC_CON_SPEED_Set(hi2c->init.speedMode) |
         I2C_IC_CON_IC_RESTART_EN_Set(1U) | I2C_IC_CON_BUS_CLEAR_FEATURE_CTRL_Set(1U));
    if (hi2c->init.addrMode)
    {
        hi2c->instance->IC_TAR |= I2C_IC_TAR_IC_10BITADDR_MASTER_Set(1U);
    }
    else
    {
        hi2c->instance->IC_TAR &= ~(I2C_IC_TAR_IC_10BITADDR_MASTER_Set(1U));
    }
    I2C_setOwnAddress(hi2c->instance, hi2c->init.slaveAddr);
    I2C_setTargetAddress(hi2c->instance, hi2c->targetAddr);

    if (hi2c->init.speedMode == kI2C_STANDARD_SPEED_MODE)
    {
        hi2c->instance->IC_SS_SCL_HCNT = I2C_IC_SS_SCL_HCNT_IC_SS_SCL_HCNT_Set(hi2c->init.hcnt); //
        hi2c->instance->IC_SS_SCL_LCNT = I2C_IC_SS_SCL_LCNT_IC_SS_SCL_LCNT_Set(hi2c->init.lcnt); //
    }
    else if (hi2c->init.speedMode == kI2C_FAST_OR_FAST_PLUS_SPEED_MODE)
    {
        hi2c->instance->IC_FS_SCL_HCNT = I2C_IC_FS_SCL_HCNT_IC_FS_SCL_HCNT_Set(hi2c->init.hcnt); //
        hi2c->instance->IC_FS_SCL_LCNT = I2C_IC_FS_SCL_LCNT_IC_FS_SCL_LCNT_Set(hi2c->init.lcnt); //
    }
    hi2c->instance->IC_SDA_HOLD = I2C_IC_SDA_HOLD_IC_SDA_TX_HOLD_Set(hi2c->init.sdaTxHold) |
                                  I2C_IC_SDA_HOLD_IC_SDA_RX_HOLD_Set(hi2c->init.sdaRxHold);

    hi2c->instance->IC_SDA_SETUP = I2C_IC_SDA_SETUP_SDA_SETUP_Set(hi2c->init.sdaSetup);
    hi2c->instance->IC_SCL_STUCK_AT_LOW_TIMEOUT =
        I2C_IC_SCL_STUCK_AT_LOW_TIMEOUT_IC_SCL_STUCK_LOW_TIMEOUT_Set(hi2c->init.sclTimeout);

    if (hi2c->init.noSdaRecovery)
    {
        hi2c->instance->IC_ENABLE &= ~(I2C_IC_ENABLE_SDA_STUCK_RECOVERY_ENABLE_Set(1U));
    }
    else
    {
        hi2c->instance->IC_SDA_STUCK_AT_LOW_TIMEOUT =
            I2C_IC_SDA_STUCK_AT_LOW_TIMEOUT_IC_SDA_STUCK_LOW_TIMEOUT_Set(hi2c->init.sdaTimeout);
        hi2c->instance->IC_ENABLE |= I2C_IC_ENABLE_SDA_STUCK_RECOVERY_ENABLE_Set(1U);
    }

    I2C_disableInterrupt(hi2c->instance, 0xFFFF);
    hi2c->instance->IC_SMBUS_INTR_MASK = 0;

    /* Init the I2C IT Callback settings */
    hi2c->itCpltCallback = I2C_itCpltCallback;

    /* Enable the selected I2C peripheral */
    I2C_enableModule(hi2c->instance);

    hi2c->state = kI2C_READY;
    hi2c->errorCode = kI2C_NO_ABRT;
    return kSTATUS_I2C_OK;
}

I2C_Status_t I2C_initSlave(I2C_Handle_t *hi2c)
{
    assert(hi2c != NULL);

    hi2c->state = kI2C_BUSY;

    /* Disable the selected I2C peripheral */
    I2C_disableModule(hi2c->instance);

    /* Configure I2C */
    I2C_setOwnAddress(hi2c->instance, hi2c->init.slaveAddr);
    hi2c->instance->IC_CON =
        (I2C_IC_CON_IC_10BITADDR_SLAVE_Set(hi2c->init.addrMode) | I2C_IC_CON_SPEED_Set(hi2c->init.speedMode) |
         I2C_IC_CON_IC_RESTART_EN_Set(1U) | I2C_IC_CON_BUS_CLEAR_FEATURE_CTRL_Set(1U));

    hi2c->instance->IC_SDA_HOLD = I2C_IC_SDA_HOLD_IC_SDA_TX_HOLD_Set(hi2c->init.sdaTxHold) |
                                  I2C_IC_SDA_HOLD_IC_SDA_RX_HOLD_Set(hi2c->init.sdaRxHold);

    hi2c->instance->IC_SDA_SETUP = I2C_IC_SDA_SETUP_SDA_SETUP_Set(hi2c->init.sdaSetup);
    hi2c->instance->IC_SCL_STUCK_AT_LOW_TIMEOUT =
        I2C_IC_SCL_STUCK_AT_LOW_TIMEOUT_IC_SCL_STUCK_LOW_TIMEOUT_Set(hi2c->init.sclTimeout);
    I2C_disableInterrupt(hi2c->instance, 0xFFFF);
    hi2c->instance->IC_SMBUS_INTR_MASK = 0;

    /* Init the I2C Callback settings */
    hi2c->itCpltCallback = I2C_itCpltCallback;

    /* Enable the selected I2C peripheral */
    I2C_enableModule(hi2c->instance);

    hi2c->state = kI2C_READY;
    hi2c->errorCode = kI2C_NO_ABRT;
    return kSTATUS_I2C_OK;
}

void I2C_setMode(I2C_Handle_t *hi2c, I2C_Mode_t mode)
{
    assert(hi2c != NULL);

    /* Disable the selected I2C peripheral */
    I2C_disableModule(hi2c->instance);

    /* Configure I2C mode*/
    hi2c->instance->IC_CON =
        (hi2c->instance->IC_CON & ~(I2C_IC_CON_IC_SLAVE_DISABLE_Msk | I2C_IC_CON_MASTER_MODE_Msk)) |
        I2C_IC_CON_IC_SLAVE_DISABLE_Set(mode) | I2C_IC_CON_MASTER_MODE_Set(mode);

    /* Enable the selected I2C peripheral */
    I2C_enableModule(hi2c->instance);
}

static I2C_Status_t I2C_masterIsrIT(struct __I2C_Handle_t *hi2c)
{
    uint32_t itFlags = I2C_getInterruptStatus(hi2c->instance);
    if (itFlags & kI2C_TX_ABRT)
    {
        /* Set corresponding Error Code */
        hi2c->errorCode = (I2C_TxAbortSource_t)(I2C_getTXABRTSource(hi2c->instance) & 0x3DFFF);
        /* Clear Abort Flag */
        I2C_clrAbrt(hi2c->instance);
        if (hi2c->errorCode != kI2C_NO_ABRT)
        {
            I2C_disableInterrupt(hi2c->instance, kI2C_TX_ABRT);
            /* Call I2C complete function */
            hi2c->itCpltCallback(hi2c, kSTATUS_I2C_ERROR);
        }
    }
    else if (itFlags & kI2C_STOP_DETECTED)
    {
        I2C_disableInterrupt(hi2c->instance, kI2C_TX_EMPTY | kI2C_RX_FULL | kI2C_STOP_DETECTED);
        /* Call I2C complete function */
        hi2c->state = kI2C_READY;
        hi2c->itCpltCallback(hi2c, kSTATUS_I2C_OK);
    }
    else if (itFlags & kI2C_TX_EMPTY)
    {
        if (hi2c->xferSize > 1)
        {
            /* Write data to Tx FIFO */
            I2C_putData(hi2c->instance, *(hi2c->pBuffPtr));

            /* Increment Buffer pointer */
            hi2c->pBuffPtr++;
            hi2c->xferSize--;
        }
        else if (hi2c->xferSize == 1)
        {
            /* Write data to Tx FIFO and generate STOP */
            I2C_putData(hi2c->instance, (*(hi2c->pBuffPtr) | kI2C_STOP_CMD));
            hi2c->xferSize--;
        }
    }
    else if (itFlags & kI2C_RX_FULL)
    {
        /* Read data from RX FIFO */
        *(hi2c->pBuffPtr) = I2C_getData(hi2c->instance);

        /* Increment Buffer pointer */
        hi2c->pBuffPtr++;
        hi2c->xferSize--;

        if (hi2c->xferSize == 1)
        {
            /* Generate Read request and STOP */
            I2C_putData(hi2c->instance, kI2C_READ_CMD | kI2C_STOP_CMD);
        }
        else if (hi2c->xferSize > 1)
        {
            /* Generate Read request */
            I2C_putData(hi2c->instance, kI2C_READ_CMD);
        }
    }
    return kSTATUS_I2C_OK;
}

static I2C_Status_t I2C_slaveIsrIT(struct __I2C_Handle_t *hi2c)
{
    uint32_t itFlags = I2C_getInterruptStatus(hi2c->instance);
    if (itFlags & kI2C_TX_ABRT)
    {
        /* Set corresponding Error Code */
        hi2c->errorCode = (I2C_TxAbortSource_t)(I2C_getTXABRTSource(hi2c->instance) & 0x3DFFF);
        /* Clear Abort Flag */
        I2C_clrAbrt(hi2c->instance);
        if (hi2c->errorCode != kI2C_NO_ABRT)
        {
            I2C_disableInterrupt(hi2c->instance, kI2C_TX_ABRT);
            /* Call I2C complete function */
            hi2c->itCpltCallback(hi2c, kSTATUS_I2C_ERROR);
        }
    }
    else if (itFlags & kI2C_READ_REQUEST)
    {
        /* Clear Read Request Flag */
        I2C_clrRdReq(hi2c->instance);
        I2C_disableInterrupt(hi2c->instance, kI2C_READ_REQUEST);
        I2C_enableInterrupt(hi2c->instance, kI2C_TX_EMPTY);
    }
    else if (itFlags & kI2C_TX_EMPTY)
    {
        if (hi2c->xferSize == 0)
        {
            I2C_disableInterrupt(hi2c->instance, kI2C_TX_EMPTY);
            hi2c->state = kI2C_READY;
            /* Call I2C complete function */
            hi2c->itCpltCallback(hi2c, kSTATUS_I2C_OK);
        }
        else
        {
            /* Write data to Tx FIFO */
            I2C_putData(hi2c->instance, (uint32_t)(*(hi2c->pBuffPtr)));
            /* Increment Buffer pointer */
            hi2c->pBuffPtr++;
            hi2c->xferSize--;
        }
    }
    else if (itFlags & kI2C_RX_FULL)
    {
        /* Read data from RX FIFO */
        *(hi2c->pBuffPtr) = I2C_getData(hi2c->instance);
        /* Increment Buffer pointer */
        hi2c->pBuffPtr++;
        hi2c->xferSize--;

        if (hi2c->xferSize == 0)
        {
            I2C_disableInterrupt(hi2c->instance, kI2C_RX_FULL);
            hi2c->state = kI2C_READY;
            /* Call I2C complete function */
            hi2c->itCpltCallback(hi2c, kSTATUS_I2C_OK);
        }
    }
    return kSTATUS_I2C_OK;
}

I2C_Status_t I2C_masterTransmit(I2C_Handle_t *hi2c, uint8_t *buff, uint16_t dataSize, uint32_t timeout)
{
    uint32_t tickstart;
    assert(hi2c != NULL);

    if (hi2c->state == kI2C_BUSY)
    {
        return kSTATUS_I2C_BUSY;
    }
    if (buff == NULL || dataSize == 0U)
    {
        return kSTATUS_I2C_ERROR_INVALID_PARAM;
    }

    /* Init tickstart for timeout management */
    tickstart = BOARD_getTick();
    I2C_disableModule(hi2c->instance);
    I2C_setTargetAddress(hi2c->instance, hi2c->targetAddr);
    I2C_enableModule(hi2c->instance);

    hi2c->state    = kI2C_BUSY;
    hi2c->errorCode = kI2C_NO_ABRT;

    /* Prepare transfer parameters */
    hi2c->pBuffPtr = buff;
    hi2c->xferSize = dataSize;
    hi2c->xferISR  = NULL;

    for (int i = 0; i < dataSize; i++)
    {
        /* Wait until TX_EMPTY flag is set */
        if (I2C_waitOnFlag(hi2c, kI2C_TX_EMPTY, 0, timeout, tickstart) != kSTATUS_I2C_OK)
        {
            return kSTATUS_I2C_TIMEOUT;
        }
        if (i == dataSize - 1)
        {
            /* Write data to Tx FIFO and generate STOP */
            I2C_putData(hi2c->instance, *buff | kI2C_STOP_CMD);
            /* Wait until STOP_DETECTED flag is set */
            if (I2C_waitOnFlag(hi2c, kI2C_STOP_DETECTED, 0, timeout, tickstart) != kSTATUS_I2C_OK)
            {
                return kSTATUS_I2C_ERROR;
            }
            /* Check if an error is detected */
            if (I2C_IC_RAW_INTR_STAT_TX_ABRT_Get(hi2c->instance->IC_RAW_INTR_STAT))
            {
                hi2c->state    = kI2C_READY;
                hi2c->errorCode = (I2C_TxAbortSource_t)(I2C_getTXABRTSource(hi2c->instance) & 0x3DFFF);
                I2C_clrAbrt(hi2c->instance);
                return kSTATUS_I2C_ERROR;
            }
            break;
        }
        /* Write data to Tx FIFO */
        I2C_putData(hi2c->instance, *buff);
        /* Increment Buffer pointer */
        buff++;
    }

    hi2c->state = kI2C_READY;
    return kSTATUS_I2C_OK;
}

I2C_Status_t I2C_masterTransmitNostop(I2C_Handle_t *hi2c, uint8_t *buff, uint16_t dataSize, uint32_t timeout)
{
    uint32_t tickstart;
    assert(hi2c != NULL);

    if (hi2c->state == kI2C_BUSY)
    {
        return kSTATUS_I2C_BUSY;
    }

    if (buff == NULL || dataSize == 0U)
    {
        return kSTATUS_I2C_ERROR_INVALID_PARAM;
    }

    /* Init tickstart for timeout management*/
    tickstart = BOARD_getTick();

    I2C_disableModule(hi2c->instance);
    I2C_setTargetAddress(hi2c->instance, hi2c->targetAddr);
    I2C_enableModule(hi2c->instance);


    hi2c->state    = kI2C_BUSY;
    hi2c->errorCode = kI2C_NO_ABRT;

    /* Prepare transfer parameters */
    hi2c->pBuffPtr = buff;
    hi2c->xferSize = dataSize;
    hi2c->xferISR  = NULL;

    for (int i = 0; i < dataSize; i++)
    {
        /* Wait until TX_EMPTY flag is set */
        if (I2C_waitOnFlag(hi2c, kI2C_TX_EMPTY, 0, timeout, tickstart) != kSTATUS_I2C_OK)
        {
            return kSTATUS_I2C_TIMEOUT;
        }
        /* Write data to Tx FIFO */
        I2C_putData(hi2c->instance, *buff);
        /* Increment Buffer pointer */
        buff++;
    }
    /* Wait until TX_EMPTY flag is set */
    if (I2C_waitOnFlag(hi2c, kI2C_TX_EMPTY, 0, timeout, tickstart) != kSTATUS_I2C_OK)
    {
        return kSTATUS_I2C_TIMEOUT;
    }

    hi2c->state = kI2C_READY;

    /* Check if an error is detected */
    if (I2C_IC_RAW_INTR_STAT_TX_ABRT_Get(hi2c->instance->IC_RAW_INTR_STAT))
    {
        hi2c->errorCode = (I2C_TxAbortSource_t)(I2C_getTXABRTSource(hi2c->instance) & 0x3DFFF);
        I2C_clrAbrt(hi2c->instance);
        return kSTATUS_I2C_ERROR;
    }
    else
    {
        return kSTATUS_I2C_OK;
    }
}

I2C_Status_t I2C_masterReceive(I2C_Handle_t *hi2c, uint8_t *buff, uint16_t dataSize, uint32_t timeout)
{
    uint32_t tickstart;
    assert(hi2c != NULL);

    if (hi2c->state == kI2C_BUSY)
    {
        return kSTATUS_I2C_BUSY;
    }

    /* Init tickstart for timeout management */
    tickstart = BOARD_getTick();

    I2C_disableModule(hi2c->instance);
    I2C_setTargetAddress(hi2c->instance, hi2c->targetAddr);
    I2C_enableModule(hi2c->instance);

    hi2c->state    = kI2C_BUSY;
    hi2c->errorCode = kI2C_NO_ABRT;

    /* Prepare transfer parameters */
    hi2c->pBuffPtr = buff;
    hi2c->xferSize = dataSize;
    hi2c->xferISR  = NULL;

    for (int i = 0; i < dataSize; i++)
    {
        if (i == dataSize - 1)
        {
            /* Generate Read request and STOP */
            I2C_putData(hi2c->instance, kI2C_READ_CMD | kI2C_STOP_CMD);
            /* Wait until RX_FULL flag is set */
            if (I2C_waitOnFlag(hi2c, kI2C_RX_FULL, 0, timeout, tickstart) != kSTATUS_I2C_OK)
            {
                return kSTATUS_I2C_ERROR;
            }
            /* Read data from RX FIFO */
            *buff = I2C_getData(hi2c->instance);
            break;
        }

        /* Generate Read request */
        I2C_putData(hi2c->instance, kI2C_READ_CMD);

        /* Wait until RX_FULL flag is set */
        if (I2C_waitOnFlag(hi2c, kI2C_RX_FULL, 0, timeout, tickstart) != kSTATUS_I2C_OK)
        {
            return kSTATUS_I2C_ERROR;
        }
        /* Read data from RX FIFO */
        *buff = I2C_getData(hi2c->instance);
        /* Increment Buffer pointer */
        buff++;
    }

    hi2c->state = kI2C_READY;
    return kSTATUS_I2C_OK;
}

I2C_Status_t I2C_masterReceiveNostop(I2C_Handle_t *hi2c, uint8_t *buff, uint16_t dataSize, uint32_t timeout)
{
    uint32_t tickstart;
    assert(hi2c != NULL);

    if (hi2c->state == kI2C_BUSY)
    {
        return kSTATUS_I2C_BUSY;
    }
    /* Init tickstart for timeout management */
    tickstart = BOARD_getTick();

    I2C_disableModule(hi2c->instance);
    I2C_setTargetAddress(hi2c->instance, hi2c->targetAddr);
    I2C_enableModule(hi2c->instance);

    hi2c->state    = kI2C_BUSY;
    hi2c->errorCode = kI2C_NO_ABRT;

    /* Prepare transfer parameters */
    hi2c->pBuffPtr = buff;
    hi2c->xferSize = dataSize;
    hi2c->xferISR  = NULL;

    for (int i = 0; i < dataSize; i++)
    {
        /* Generate Read request */
        I2C_putData(hi2c->instance, kI2C_READ_CMD);
        /* Wait until RX_FULL flag is set */
        if (I2C_waitOnFlag(hi2c, kI2C_RX_FULL, 0, timeout, tickstart) != kSTATUS_I2C_OK)
        {
            return kSTATUS_I2C_TIMEOUT;
        }
        /* Read data from RX FIFO */
        *buff = I2C_getData(hi2c->instance);
        /* Increment Buffer pointer */
        buff++;
    }

    hi2c->state = kI2C_READY;

    return kSTATUS_I2C_OK;
}

I2C_Status_t I2C_slaveTransmit(I2C_Handle_t *hi2c, uint8_t *buff, uint16_t dataSize, uint32_t timeout)
{
    uint32_t tickstart;
    assert(hi2c != NULL);

    if (hi2c->state == kI2C_BUSY)
    {
        return kSTATUS_I2C_BUSY;
    }

    if (buff == NULL || dataSize == 0U)
    {
        return kSTATUS_I2C_ERROR_INVALID_PARAM;
    }

    /* Init tickstart for timeout management */
    tickstart = BOARD_getTick();

    hi2c->state    = kI2C_BUSY;
    hi2c->errorCode = kI2C_NO_ABRT;

    /* Prepare transfer parameters */
    hi2c->pBuffPtr = buff;
    hi2c->xferSize = dataSize;
    hi2c->xferISR  = NULL;

    /* Wait until READ_REQUEST flag is set */
    if (I2C_waitOnFlag(hi2c, kI2C_READ_REQUEST, 0, timeout, tickstart) != kSTATUS_I2C_OK)
    {
        return kSTATUS_I2C_TIMEOUT;
    }

    if (I2C_IC_RAW_INTR_STAT_TX_ABRT_Get(hi2c->instance->IC_RAW_INTR_STAT) == 1)
    {
        I2C_clrAbrt(hi2c->instance);
    }
    for (int i = 0; i < dataSize; i++)
    {
        /* Wait until TX_EMPTY flag is set */
        if (I2C_waitOnFlag(hi2c, kI2C_TX_EMPTY, 0, timeout, tickstart) != kSTATUS_I2C_OK)
        {
            return kSTATUS_I2C_TIMEOUT;
        }
        /* Write data to Tx FIFO */
        I2C_putData(hi2c->instance, *buff);
        /* Increment Buffer pointer */
        buff++;
    }
    /* Wait until TX_EMPTY flag is set */
    if (I2C_waitOnFlag(hi2c, kI2C_TX_EMPTY, 0, timeout, tickstart) != kSTATUS_I2C_OK)
    {
        return kSTATUS_I2C_TIMEOUT;
    }
    I2C_clrRdReq(hi2c->instance);
    hi2c->state = kI2C_READY;
    return kSTATUS_I2C_OK;
}


I2C_Status_t I2C_slaveReceive(I2C_Handle_t *hi2c, uint8_t *buff, uint16_t dataSize, uint32_t timeout)
{
    uint32_t tickstart;
    assert(hi2c != NULL);

    if (hi2c->state == kI2C_BUSY)
    {
        return kSTATUS_I2C_BUSY;
    }

    /* Init tickstart for timeout management */
    tickstart      = BOARD_getTick();

    hi2c->state    = kI2C_BUSY;
    hi2c->errorCode = kI2C_NO_ABRT;

    /* Prepare transfer parameters */
    hi2c->pBuffPtr = buff;
    hi2c->xferSize = dataSize;
    hi2c->xferISR  = NULL;

    for (int i = 0; i < hi2c->xferSize; i++)
    {
        /* Wait until RX_FULL flag is set */
        if (I2C_waitOnFlag(hi2c, kI2C_RX_FULL, 0, timeout, tickstart) != kSTATUS_I2C_OK)
        {
            return kSTATUS_I2C_ERROR;
        }
        /* Read data from RX FIFO */
        *hi2c->pBuffPtr = I2C_getData(hi2c->instance);
        /* Increment Buffer pointer */
        hi2c->pBuffPtr++;
    }

    hi2c->state = kI2C_READY;
    return kSTATUS_I2C_OK;
}

I2C_Status_t I2C_masterTransmitSeq(I2C_Handle_t *hi2c, uint8_t *buff, uint16_t dataSize, uint32_t timeout,
                                   I2C_XferOption_t xferOption)
{
    uint32_t tickstart;
    assert(hi2c != NULL);

    if (hi2c->state == kI2C_BUSY)
    {
        return kSTATUS_I2C_BUSY;
    }

    if (buff == NULL || dataSize == 0U)
    {
        return kSTATUS_I2C_ERROR_INVALID_PARAM;
    }

    /* Init tickstart for timeout management */
    tickstart = BOARD_getTick();
    I2C_disableModule(hi2c->instance);
    I2C_setTargetAddress(hi2c->instance, hi2c->targetAddr);
    I2C_enableModule(hi2c->instance);


    hi2c->state    = kI2C_BUSY;
    hi2c->errorCode = kI2C_NO_ABRT;

    /* Prepare transfer parameters */
    hi2c->pBuffPtr = buff;
    hi2c->xferSize = dataSize;
    hi2c->xferISR  = NULL;

    /* Generate RESTART and write data to Tx FIFO */
    I2C_putData(hi2c->instance, *buff | kI2C_RESTART_CMD);
    /* Increment Buffer pointer */
    buff++;

    for (int i = 1; i < dataSize; i++)
    {
        /* Wait until TX_EMPTY flag is set */
        if (I2C_waitOnFlag(hi2c, kI2C_TX_EMPTY, 0, timeout, tickstart) != kSTATUS_I2C_OK)
        {
            return kSTATUS_I2C_TIMEOUT;
        }

        if (i == dataSize - 1 && xferOption == kI2C_OTHER_AND_LAST_FRAME)
        {
            /* Write data to Tx FIFO and generate STOP */
            I2C_putData(hi2c->instance, *buff | kI2C_STOP_CMD);
            /* Wait until STOP_DETECTED flag is set */
            if (I2C_waitOnFlag(hi2c, kI2C_STOP_DETECTED, 0, timeout, tickstart) != kSTATUS_I2C_OK)
            {
                return kSTATUS_I2C_TIMEOUT;
            }
            break;
        }
        /* Write data to Tx FIFO */
        I2C_putData(hi2c->instance, *buff);
        /* Increment Buffer pointer */
        buff++;
    }
    hi2c->state = kI2C_READY;

    /* Check if an error is detected */
    if (I2C_IC_RAW_INTR_STAT_TX_ABRT_Get(hi2c->instance->IC_RAW_INTR_STAT))
    {
        hi2c->errorCode = (I2C_TxAbortSource_t)I2C_getTXABRTSource(hi2c->instance);
        I2C_clrAbrt(hi2c->instance);
        return kSTATUS_I2C_ERROR;
    }
    else
    {
        return kSTATUS_I2C_OK;
    }
}

I2C_Status_t I2C_masterReceiveSeq(I2C_Handle_t *hi2c, uint8_t *buff, uint16_t dataSize, uint32_t timeout,
                                  I2C_XferOption_t xferOption)
{
    uint32_t tickstart;
    assert(hi2c != NULL);

    if (hi2c->state == kI2C_BUSY)
    {
        return kSTATUS_I2C_BUSY;
    }
    /* Init tickstart for timeout management */
    tickstart      = BOARD_getTick();
    hi2c->state    = kI2C_BUSY;
    hi2c->errorCode = kI2C_NO_ABRT;

    /* Prepare transfer parameters */
    hi2c->pBuffPtr = buff;
    hi2c->xferSize = dataSize;
    hi2c->xferISR  = NULL;

    I2C_disableModule(hi2c->instance);
    I2C_setTargetAddress(hi2c->instance, hi2c->targetAddr);
    I2C_enableModule(hi2c->instance);

    /* Generate RESTART and READ */
    I2C_putData(hi2c->instance, kI2C_READ_CMD | kI2C_RESTART_CMD);

    /* Wait until RX_FULL flag is set */
    if (I2C_waitOnFlag(hi2c, kI2C_RX_FULL, 0, timeout, tickstart) != kSTATUS_I2C_OK)
    {
        return kSTATUS_I2C_TIMEOUT;
    }
    /* Read data from RX FIFO */
    *buff = I2C_getData(hi2c->instance);
    /* Increment Buffer pointer */
    buff++;
    for (int i = 1; i < dataSize; i++)
    {
        if ((i == dataSize - 1) && xferOption == kI2C_OTHER_AND_LAST_FRAME)
        {
            /* Generate READ and STOP */
            I2C_putData(hi2c->instance, kI2C_READ_CMD | kI2C_STOP_CMD);
            /* Wait until RX_FULL flag is set */
            if (I2C_waitOnFlag(hi2c, kI2C_RX_FULL, 0, timeout, tickstart) != kSTATUS_I2C_OK)
            {
                return kSTATUS_I2C_TIMEOUT;
            }
            /* Read data from RX FIFO */
            *buff = I2C_getData(hi2c->instance);
            break;
        }
        /* Generate READ */
        I2C_putData(hi2c->instance, kI2C_READ_CMD);
        if (I2C_waitOnFlag(hi2c, kI2C_RX_FULL, 0, timeout, tickstart) != kSTATUS_I2C_OK)
        {
            return kSTATUS_I2C_TIMEOUT;
        }
        /* Read data from RX FIFO */
        *buff = I2C_getData(hi2c->instance);
        /* Increment Buffer pointer */
        buff++;
    }

    hi2c->state = kI2C_READY;

    return kSTATUS_I2C_OK;
}


I2C_Status_t I2C_masterTransmitIT(I2C_Handle_t *hi2c, uint8_t *buff, uint16_t dataSize)
{
    assert(hi2c != NULL);

    if (hi2c->state == kI2C_BUSY)
    {
        return kSTATUS_I2C_BUSY;
    }

    if (buff == NULL || dataSize == 0)
    {
        return kSTATUS_I2C_ERROR_INVALID_PARAM;
    }

    I2C_disableModule(hi2c->instance);
    I2C_setTargetAddress(hi2c->instance, hi2c->targetAddr);
    I2C_enableModule(hi2c->instance);

    hi2c->state    = kI2C_BUSY;
    hi2c->errorCode = kI2C_NO_ABRT;

    /* Prepare transfer parameters */
    hi2c->pBuffPtr = buff;
    hi2c->xferSize = dataSize;
    hi2c->xferISR  = I2C_masterIsrIT;

    if (hi2c->xferSize == 1)
    {
        /* Write data to Tx FIFO and generate STOP */
        I2C_putData(hi2c->instance, *(hi2c->pBuffPtr) | kI2C_STOP_CMD);
        hi2c->xferSize--;
    }
    else if (hi2c->xferSize > 1)
    {
        /* Write data to Tx FIFO */
        I2C_putData(hi2c->instance, *(hi2c->pBuffPtr));
        hi2c->xferSize--;
        hi2c->pBuffPtr++;
    }

    I2C_enableInterrupt(hi2c->instance, kI2C_TX_EMPTY | kI2C_STOP_DETECTED | kI2C_TX_ABRT);
    return kSTATUS_I2C_OK;
}

I2C_Status_t I2C_masterReceiveIT(I2C_Handle_t *hi2c, uint8_t *buff, uint16_t dataSize)
{
    assert(hi2c != NULL);

    if (hi2c->state == kI2C_BUSY)
    {
        return kSTATUS_I2C_BUSY;
    }
    I2C_disableModule(hi2c->instance);
    I2C_setTargetAddress(hi2c->instance, hi2c->targetAddr);
    I2C_enableModule(hi2c->instance);

    hi2c->state    = kI2C_BUSY;
    hi2c->errorCode = kI2C_NO_ABRT;

    /* Prepare transfer parameters */
    hi2c->pBuffPtr = buff;
    hi2c->xferSize = dataSize;
    hi2c->xferISR  = I2C_masterIsrIT;

    I2C_enableInterrupt(hi2c->instance, kI2C_RX_FULL | kI2C_STOP_DETECTED | kI2C_TX_ABRT);
    if (hi2c->xferSize == 1)
    {
        /* Generate READ and STOP*/
        I2C_putData(hi2c->instance, kI2C_READ_CMD | kI2C_STOP_CMD);
    }
    else if (hi2c->xferSize > 1)
    {
        /* Generate READ */
        I2C_putData(hi2c->instance, kI2C_READ_CMD);
    }
    return kSTATUS_I2C_OK;
}

I2C_Status_t I2C_slaveTransmitIT(I2C_Handle_t *hi2c, uint8_t *buff, uint16_t dataSize)
{
    assert(hi2c != NULL);

    if (hi2c->state == kI2C_BUSY)
    {
        return kSTATUS_I2C_BUSY;
    }

    hi2c->state    = kI2C_BUSY;
    hi2c->errorCode = kI2C_NO_ABRT;

    /* Prepare transfer parameters */
    hi2c->pBuffPtr = buff;
    hi2c->xferSize = dataSize;
    hi2c->xferISR  = I2C_slaveIsrIT;

    I2C_enableInterrupt(hi2c->instance, kI2C_READ_REQUEST | kI2C_TX_ABRT);
    return kSTATUS_I2C_OK;
}

I2C_Status_t I2C_slaveReceiveIT(I2C_Handle_t *hi2c, uint8_t *buff, uint16_t dataSize)
{
    assert(hi2c != NULL);

    if (hi2c->state == kI2C_BUSY)
    {
        return kSTATUS_I2C_BUSY;
    }
    hi2c->state    = kI2C_BUSY;
    hi2c->errorCode = kI2C_NO_ABRT;

    /* Prepare transfer parameters */
    hi2c->pBuffPtr = buff;
    hi2c->xferSize = dataSize;
    hi2c->xferISR  = I2C_slaveIsrIT;

    I2C_enableInterrupt(hi2c->instance, kI2C_RX_FULL | kI2C_TX_ABRT);
    return kSTATUS_I2C_OK;
}

I2C_Status_t I2C_memWrite(I2C_Handle_t *hi2c, uint32_t memAddr, uint32_t memAddSize, uint8_t *buff, uint32_t dataSize,
                          uint32_t timeout)
{
    uint32_t tickstart;
    assert(hi2c != NULL);

    if (hi2c->state == kI2C_BUSY)
    {
        return kSTATUS_I2C_BUSY;
    }

    /* Init tickstart for timeout management */
    tickstart      = BOARD_getTick();
    hi2c->state    = kI2C_BUSY;
    hi2c->errorCode = kI2C_NO_ABRT;

    /* Prepare transfer parameters */
    hi2c->pBuffPtr = buff;
    hi2c->xferSize = dataSize;
    hi2c->xferISR  = NULL;

    I2C_disableModule(hi2c->instance);
    if (memAddSize == kI2C_MEM_ADDR_SIZE_24BIT)
    {
        I2C_setTargetAddress(hi2c->instance, (hi2c->targetAddr | ((memAddr & 0xff0000) >> 16)));
    }
    else
    {
        I2C_setTargetAddress(hi2c->instance, hi2c->targetAddr);
    }
    I2C_enableModule(hi2c->instance);

    /* Send Memory Address */
    if (memAddSize == kI2C_MEM_ADDR_SIZE_8BIT)
    {
        I2C_putData(hi2c->instance, (uint8_t)memAddr);
    }
    else
    {
        I2C_putData(hi2c->instance, (uint8_t)((memAddr & 0xff00) >> 8));
        I2C_putData(hi2c->instance, (uint8_t)(memAddr & 0x00ff));
    }
    for (int i = 0; i < dataSize; i++)
    {
        /* Wait until TX_EMPTY flag is set */
        if (I2C_waitOnFlag(hi2c, kI2C_TX_EMPTY, 0, timeout, tickstart) != kSTATUS_I2C_OK)
        {
            return kSTATUS_I2C_TIMEOUT;
        }

        if (i == dataSize - 1)
        {
            /* Write data to Tx FIFO and generate STOP */
            I2C_putData(hi2c->instance, *buff | kI2C_STOP_CMD);
            /* Wait until STOP_DETECTED flag is set */
            if (I2C_waitOnFlag(hi2c, kI2C_STOP_DETECTED, 0, timeout, tickstart) != kSTATUS_I2C_OK)
            {
                return kSTATUS_I2C_TIMEOUT;
            }
            break;
        }
        /* Write data to Tx FIFO */
        I2C_putData(hi2c->instance, *buff);
        /* Increment Buffer pointer */
        buff++;
    }
    hi2c->state = kI2C_READY;

    /* Check if an error is detected */
    if (I2C_IC_RAW_INTR_STAT_TX_ABRT_Get(hi2c->instance->IC_RAW_INTR_STAT))
    {
        hi2c->errorCode = (I2C_TxAbortSource_t)(I2C_getTXABRTSource(hi2c->instance) & 0x3DFFF);
        I2C_clrAbrt(hi2c->instance);
        return kSTATUS_I2C_ERROR;
    }
    else
    {
        return kSTATUS_I2C_OK;
    }
}

I2C_Status_t I2C_memRead(I2C_Handle_t *hi2c, uint32_t memAddr, uint32_t memAddSize, uint8_t *buff, uint32_t dataSize,
                         uint32_t timeout)
{
    uint32_t tickstart;
    assert(hi2c != NULL);

    if (hi2c->state == kI2C_BUSY)
    {
        return kSTATUS_I2C_BUSY;
    }

    /* Init tickstart for timeout management */
    tickstart      = BOARD_getTick();
    hi2c->state    = kI2C_BUSY;
    hi2c->errorCode = kI2C_NO_ABRT;

    /* Prepare transfer parameters */
    hi2c->pBuffPtr = buff;
    hi2c->xferSize = dataSize;
    hi2c->xferISR  = NULL;

    I2C_disableModule(hi2c->instance);
    if (memAddSize == kI2C_MEM_ADDR_SIZE_24BIT)
    {
        I2C_setTargetAddress(hi2c->instance, (hi2c->targetAddr | ((memAddr & 0xff0000) >> 16)));
    }
    else
    {
        I2C_setTargetAddress(hi2c->instance, hi2c->targetAddr);
    }
    I2C_enableModule(hi2c->instance);

    /* Send Memory Address */
    if (memAddSize == kI2C_MEM_ADDR_SIZE_8BIT)
    {
        I2C_putData(hi2c->instance, (uint8_t)(memAddr));
    }
    else
    {
        I2C_putData(hi2c->instance, (uint8_t)((memAddr & 0xff00) >> 8));
        I2C_putData(hi2c->instance, (uint8_t)(memAddr & 0x00ff));
    }
    for (int i = 0; i < dataSize - 1; i++)
    {
        /* Generate READ */
        I2C_putData(hi2c->instance, kI2C_READ_CMD);
        /* Wait until RX_FULL flag is set */
        if (I2C_waitOnFlag(hi2c, kI2C_RX_FULL, 0, timeout, tickstart) != kSTATUS_I2C_OK)
        {
            return kSTATUS_I2C_TIMEOUT;
        }
        /* Read data from RX FIFO */
        *buff = I2C_getData(hi2c->instance);
        /* Increment Buffer pointer */
        buff++;
    }
    /* Generate READ and STOP */
    I2C_putData(hi2c->instance, kI2C_READ_CMD | kI2C_STOP_CMD);

    /* Wait until RX_FULL flag is set */
    if (I2C_waitOnFlag(hi2c, kI2C_RX_FULL, 0, timeout, tickstart) != kSTATUS_I2C_OK)
    {
        return kSTATUS_I2C_TIMEOUT;
    }
    /* Read data from RX FIFO */
    *buff = I2C_getData(hi2c->instance);

    hi2c->state = kI2C_READY;
    return kSTATUS_I2C_OK;
}

void I2C_enableSdaRecovery(I2C_Handle_t *hi2c)
{
    assert(hi2c != NULL);

    hi2c->instance->IC_ENABLE |= I2C_IC_ENABLE_SDA_STUCK_RECOVERY_ENABLE_Set(1U);
}

void I2C_disableSdaRecovery(I2C_Handle_t *hi2c)
{
    assert(hi2c != NULL);

    hi2c->instance->IC_ENABLE &= ~(I2C_IC_ENABLE_SDA_STUCK_RECOVERY_ENABLE_Set(1U));
}

void I2C_generalCallEnable(I2C_Handle_t *hi2c)
{
    assert(hi2c != NULL);

    I2C_disableModule(hi2c->instance);
    hi2c->instance->IC_TAR &= ~(I2C_IC_TAR_DEVICE_ID_Set(1U));
    hi2c->instance->IC_TAR |= I2C_IC_TAR_SPECIAL_Set(1U);
    I2C_enableModule(hi2c->instance);
}

void I2C_generalCallDisable(I2C_Handle_t *hi2c)
{
    assert(hi2c != NULL);

    I2C_disableModule(hi2c->instance);
    hi2c->instance->IC_TAR &= ~(I2C_IC_TAR_DEVICE_ID_Set(1U));
    hi2c->instance->IC_TAR &= ~(I2C_IC_TAR_SPECIAL_Set(1U));
    I2C_enableModule(hi2c->instance);
}

void I2C_startByteEnable(I2C_Handle_t *hi2c)
{
    assert(hi2c != NULL);

    I2C_disableModule(hi2c->instance);
    hi2c->instance->IC_TAR &= ~(I2C_IC_TAR_DEVICE_ID_Set(1U));
    hi2c->instance->IC_TAR |= I2C_IC_TAR_SPECIAL_Set(1U);
    hi2c->instance->IC_TAR |= I2C_IC_TAR_GC_OR_START_Set(1U);
    I2C_enableModule(hi2c->instance);
}

void I2C_startByteDisable(I2C_Handle_t *hi2c)
{
    assert(hi2c != NULL);

    I2C_disableModule(hi2c->instance);
    hi2c->instance->IC_TAR &= ~(I2C_IC_TAR_DEVICE_ID_Set(1U));
    hi2c->instance->IC_TAR &= ~(I2C_IC_TAR_SPECIAL_Set(1U));
    hi2c->instance->IC_TAR &= ~(I2C_IC_TAR_GC_OR_START_Set(1U));
    I2C_enableModule(hi2c->instance);
}

I2C_Status_t I2C_eepromByteWrite(I2C_Handle_t *hi2c, uint32_t memAddr, uint32_t memAddSize, uint8_t *data,
                                 uint32_t timeout)
{
    assert(hi2c != NULL);

    if (I2C_memWrite(hi2c, memAddr, memAddSize, data, 1U, timeout) != kSTATUS_I2C_OK)
    {
        return kSTATUS_I2C_TIMEOUT;
    }
    DELAY(EEPROM_WRITE_TIME);
    return kSTATUS_I2C_OK;
}

I2C_Status_t I2C_eepromPageWrite(I2C_Handle_t *hi2c, uint32_t memAddr, uint32_t memAddSize, const uint8_t *data,
                                 uint32_t dataLen, uint32_t pageSize, uint32_t timeout)
{
    assert(hi2c != NULL);

    uint32_t rest, count, num1;
    rest  = dataLen % (pageSize);
    count = (dataLen - rest) / (pageSize);
    for (num1 = 0; num1 < count; num1++)
    {
        /* Write one page */
        if (I2C_memWrite(hi2c, memAddr + pageSize * num1, memAddSize, (uint8_t *)(data + pageSize * num1), pageSize,
                         timeout) != kSTATUS_I2C_OK)
        {
            return kSTATUS_I2C_TIMEOUT;
        }
        DELAY(EEPROM_WRITE_TIME);
    }

    /* Write the rest */
    if (rest > 0)
    {
        if (I2C_memWrite(hi2c, memAddr + pageSize * count, memAddSize, (uint8_t *)(data + pageSize * count), rest,
                         timeout) != kSTATUS_I2C_OK)
        {
            return kSTATUS_I2C_TIMEOUT;
        }
        DELAY(EEPROM_WRITE_TIME);
    }
    return kSTATUS_I2C_OK;
}

I2C_Status_t I2C_eepromPageRead(I2C_Handle_t *hi2c, uint32_t memAddr, uint32_t memAddSize, uint8_t *recvData,
                                uint32_t dataLen, uint32_t pageSize, uint32_t timeout)
{
    assert(hi2c != NULL);

    uint32_t rest, count, num1;
    rest  = dataLen % (pageSize);
    count = (dataLen - rest) / (pageSize);
    for (num1 = 0; num1 < count; num1++)
    {
        /* Read one page */
        if (I2C_memRead(hi2c, memAddr + pageSize * num1, memAddSize, (uint8_t *)(recvData + pageSize * num1), pageSize,
                        timeout) != kSTATUS_I2C_OK)
        {
            return kSTATUS_I2C_TIMEOUT;
        }
    }

    /* Read the rest */
    if (rest > 0)
    {
        if (I2C_memRead(hi2c, memAddr + pageSize * count, memAddSize, (uint8_t *)(recvData + pageSize * count), rest,
                        timeout) != kSTATUS_I2C_OK)
        {
            return kSTATUS_I2C_TIMEOUT;
        }
    }
    return kSTATUS_I2C_OK;
}

uint32_t I2C_computeSCLL(uint32_t clk_src_freq_hz, uint32_t low_time_ns)
{
    return MAX(8, (uint32_t)((uint64_t)clk_src_freq_hz * (uint64_t)low_time_ns / 1000000000 - 10));
}

uint32_t I2C_computeSCLH(uint32_t clk_src_freq_hz, uint32_t high_time_ns)
{
    return MAX(6, (uint32_t)((uint64_t)clk_src_freq_hz * (uint64_t)high_time_ns / 1000000000 - 11));
}
