/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_uart.c
 * \brief SDK UART driver source file
 * \version 1.0.0
 */
#define UART_RETRY_TIMES 0x3ffffff
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_uart.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* No Definitions */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * \brief Register user callback function and an ISR function to a specified UART for non-blocking transfer
 *
 * \details This function registers user callback function and ISR function for non-blocking transfer which uses IRQ.
 The relative IRQ will be enabled in the NVIC and the priority will be configured at the same time

 * \param[in] base UART base address
 * \param[in] callback UART user callback
 * \param[in] priority IRQ priority
 * \param[in] isr UART ISR function
 *
 * \retval kSTATUS_SUCCESS Success to the operation
 * \retval kSTATUS_FAIL Register to a UART which has been registered already. Need to call \ref
 UART_unregisterCallback() before the re-registration
 */
static status_t UART_registerCallbackAndISR(UART_Type *base, UART_Callback_t callback, uint32_t priority,
                                            UART_ISR_t isr);

/*!
 * \brief common handler for UART IRQ
 *
 * \details This function reads the UART interrupt identification ID, and handle each interrupt separately
 *
 * \param[in] base UART base address
 * \param[in] handle UART transfer handle
 */
static void UART_handleIRQ(UART_Type *base, UART_Handle_t *handle);

/*!
 * \brief handler for UART TX empty IRQ
 *
 * \details This function handles the interrupt when the Transmit Holding Register is empty or the TX FIFO is below the
 * threshold
 *
 * \param[in] base UART base address
 * \param[in] handle UART transfer handle
 */
static void UART_handleTxEmptyIRQ(UART_Type *base, UART_Handle_t *handle);

/*!
 * \brief handler for UART RX data IRQ
 *
 * \details This function handles the interrupt when data is available in the Receive Buffer Register or the RX FIFO is
 * reached the threshold
 *
 * \param[in] base UART base address
 * \param[in] handle UART transfer handle
 */
static void UART_handleRxDataIRQ(UART_Type *base, UART_Handle_t *handle);

/*!
 * \brief handler for UART line error IRQ
 *
 * \details This function handles the interrupt when a line error is detected during receiving
 *
 * \param[in] base UART base address
 * \param[in] handle UART transfer handle
 */
static void UART_handleLineIRQ(UART_Type *base, UART_Handle_t *handle);

/*!
 * \brief common handler for UART IRQ at RS485 Full-Duplex Mode
 *
 * \details This function reads the UART interrupt identification ID, and handle each interrupt separately
 *
 * \param[in] base UART base address
 * \param[in] handle UART transfer handle
 */
static void UART_RS485FD_handleIRQ(UART_Type *base, UART_Handle_t *handle);

/*!
 * \brief handler for UART TX empty IRQ at RS485 Full-Duplex Mode
 *
 * \details This function handles the interrupt when the Transmit Holding Register is empty or the TX FIFO is below the
 * threshold. This function enables or disables the DE signal according to the transmit state
 *
 * \param[in] base UART base address
 * \param[in] handle UART transfer handle
 */
static void UART_RS485FD_handleTxEmptyIRQ(UART_Type *base, UART_Handle_t *handle);

/*!
 * \brief handler for UART RX data IRQ at RS485 Full-Duplex Mode
 *
 * \details This function handles the interrupt when data is available in the Receive Buffer Register or the RX FIFO is
 * reached the threshold. This function enables or disables the RE signal according to the receive state
 *
 * \param[in] base UART base address
 * \param[in] handle UART transfer handle
 */
static void UART_RS485FD_handleRxDataIRQ(UART_Type *base, UART_Handle_t *handle);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! \brief Array of UART peripheral base address */
UART_Type * const s_uartBases[] = UART_BASES;
/*! \brief Array of UART IRQ number */
const IRQn_Type s_uartIRQ[] = UART_IRQS;
/*! \brief Array of UART transfer handle */
UART_Handle_t s_uartHandle[ARRAY_SIZE(s_uartBases)];
/*! \brief Array of UART transfer ISR */
UART_ISR_t s_uartISR[ARRAY_SIZE(s_uartBases)] = { NULL };

/*******************************************************************************
 * Codes
 ******************************************************************************/
uint32_t UART_getInstance(UART_Type *base)
{
    uint32_t instance = 0U;
    for (; instance < ARRAY_SIZE(s_uartBases); instance++)
    {
        if (base == s_uartBases[instance])
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_uartBases));
    return instance;
}

void UART_getDefaultConfig(UART_Config_t *config)
{
    assert(config);

    /* Assign default configurations */
    config->baudRate    = 115200U;
    config->dataLength  = kUART_DATA_LENGTH_8BITS;
    config->stopBit     = kUART_STOP_BIT_1;
    config->parityType  = kUART_PARITY_NONE;
    config->enableFIFO  = true;
    config->txFIFOLevel = kUART_TX_FIFO_EMPTY;
    config->rxFIFOLevel = kUART_RX_FIFO_NOT_EMPTY;
}

status_t UART_init(UART_Type *base, UART_Config_t *config, uint32_t freqInHz)
{
    assert(base);
    assert(config);

    status_t status;

    /* Check if the UART is busy or not. When a serial transfer is under processing, the UART cannot be configured
     */
    if (UART_isBusy(base))
    {
        return kSTATUS_UART_BUSY;
    }

    /* Configure the UART baud rate */
    status = UART_setBaudRate(base, freqInHz, config->baudRate);
    if (status != kSTATUS_SUCCESS)
    {
        return status;
    }

    /* Configure the UART mode */
    uint32_t lcrVal = UART_LCR_DLS_Set(config->dataLength) | UART_LCR_STOP_Set(config->stopBit);
    switch (config->parityType)
    {
        default:
        case kUART_PARITY_NONE:
            /* Do nothing */
            break;
        case kUART_PARITY_ODD:
            lcrVal |= UART_LCR_PEN_Set(1U);
            break;
        case kUART_PARITY_EVEN:
            lcrVal |= UART_LCR_PEN_Set(1U) | UART_LCR_EPS_Set(1U);
            break;
        case kUART_PARITY_STICK_ONE:
            lcrVal |= UART_LCR_PEN_Set(1U) | UART_LCR_SP_Set(1U);
            break;
        case kUART_PARITY_STICK_ZERO:
            lcrVal |= UART_LCR_PEN_Set(1U) | UART_LCR_EPS_Set(1U) | UART_LCR_SP_Set(1U);
            break;
    }
    base->LCR = lcrVal;

    /* Disable the test mode */
    UART_disableFIFOAccess(base);
    UART_disableLoopback(base);
    UART_haltTransmit(base, false);

    /* Configure the UART FIFOs */
    if (config->enableFIFO)
    {
        /* Please DO NOT use Read-Modify-Write(RMW) on FCR which is a Write-Only(WO) register and shares the same
         * address with IIR. Using RMW on FCR will cause IIR values written in to FCR */
        base->FCR = UART_FCR_FIFOE_Msk | UART_FCR_TET_Set(config->txFIFOLevel) | UART_FCR_RT_Set(config->rxFIFOLevel) |
                    UART_FCR_XFIFOR_Msk | UART_FCR_RFIFOR_Msk;
    }
    else
    {
        base->FCR = 0U;
    }

    return kSTATUS_SUCCESS;
}

status_t UART_deinit(UART_Type *base)
{
    assert(base);

    /* Return an error to inform there is a transmission under processing */
    if (UART_isBusy(base))
    {
        return kSTATUS_UART_BUSY;
    }

    /* Clean the divisor to put UART into the inactive state */
    base->LCR |= UART_LCR_DLAB_Msk;
    base->DLL  = 0U;
    base->DLH  = 0U;
    base->LCR &= ~UART_LCR_DLAB_Msk;

    /* Read to clear all pending status */
    (void)UART_getInterruptIdentification(base);
    (void)UART_getLineStatus(base);
    (void)UART_getUartStatus(base);

    return kSTATUS_SUCCESS;
}

status_t UART_setBaudRate(UART_Type *base, uint32_t freqInHz, uint32_t baudRate)
{
    assert(base);
    assert(freqInHz > 0U);
    assert(baudRate > 0U);

    /*
     * Calculate the divisor:
     *     DIVISOR = Serial Clock Frequency / (16 x Baud Rate)
     * The frequency is multiplied by 10 to handle the rounding.
     */
    uint32_t divisor = (((freqInHz * 10U) / (baudRate << 4U)) + 5U) / 10U;
    /* Check if the divisor is over the max range */
    if ((divisor > UART_DIVISOR_MAX) || (divisor == 0U))
    {
        return kSTATUS_UART_DIVISOR_OVERRANGE;
    }
    /*
     * Check if the baudrate deviation is over the max percentage:
     *     Percentage ERROR = | Baud Rate - Calculated Baud Rate | / Baud Rate x 100
     */
    uint32_t calcBaudRate = ((freqInHz * 10U / (divisor << 4U)) + 5U) / 10U;
    uint32_t baudRateDiff = (calcBaudRate > baudRate) ? (calcBaudRate - baudRate) : (baudRate - calcBaudRate);
    if ((baudRateDiff * 100U) > (baudRate * UART_BAUDRATE_DEVIATION_PERCENT_MAX))
    {
        return kSTATUS_UART_UNSUPPORTED_BAUDRATE;
    }

    /* Check the busy state before update the divisor */
    if (UART_isBusy(base))
    {
        return kSTATUS_UART_BUSY;
    }

    /* Enable the divisor latch registers */
    base->LCR |= UART_LCR_DLAB_Msk;

    /* Write the divisor into the registers */
    base->DLL = UART_DLL_DLL_Set(divisor);
    base->DLH = UART_DLH_DLH_Set(divisor >> 8U);

    /* Disable the divisor latch registers to make sure the divisor cannot be
     * modified unexpectedly */
    base->LCR &= ~UART_LCR_DLAB_Msk;

    return kSTATUS_SUCCESS;
}

status_t UART_writeDataBlocking(UART_Type *base, const uint8_t *data, size_t length)
{
    assert(base);
    assert(data);

    const uint8_t *dataBuf  = data;
    uint32_t       dataLeft = length;

#if defined(UART_RETRY_TIMES) && UART_RETRY_TIMES
    uint32_t retryTimes;
#endif

    while (dataLeft > 0U)
    {
#if defined(UART_RETRY_TIMES) && UART_RETRY_TIMES
        retryTimes = UART_RETRY_TIMES;
#endif
        /* Wait a space available in the TX FIFO or the Transmit Holding Register */
        while (UART_isSpaceAvailable(base) == false)
        {
#if defined(UART_RETRY_TIMES) && UART_RETRY_TIMES
            if (retryTimes-- == 0U)
            {
                return kSTATUS_TIMEOUT;
            }
#endif
        }

        /* Put one byte into the transfer FIFO */
        base->THR = *dataBuf;
        dataBuf++;
        dataLeft--;
    }

    /* Wait the transfer register is empty which indicates the transfer is completed */
#if defined(UART_RETRY_TIMES) && UART_RETRY_TIMES
    retryTimes = UART_RETRY_TIMES;
#endif
    while (UART_isTransmitRegisterEmpty(base) == false)
    {
#if defined(UART_RETRY_TIMES) && UART_RETRY_TIMES
        if (retryTimes-- == 0U)
        {
            return kSTATUS_TIMEOUT;
        }
#endif
    }

    return kSTATUS_SUCCESS;
}

status_t UART_readDataBlocking(UART_Type *base, uint8_t *data, size_t length)
{
    assert(base);
    assert(data);

    status_t status = kSTATUS_SUCCESS;

    uint8_t *dataAddr = data;
    uint32_t dataLeft = length;

    while (dataLeft > 0U)
    {
#if defined(UART_RETRY_TIMES) && UART_RETRY_TIMES
        uint32_t retryTimes = UART_RETRY_TIMES;
#endif
        /* Wait the receive data is ready */
        uint32_t lineStatus;
        do
        {
            lineStatus = UART_getLineStatus(base);
#if defined(UART_RETRY_TIMES) && UART_RETRY_TIMES
            if (retryTimes-- == 0U)
            {
                return kSTATUS_TIMEOUT;
            }
#endif
        } while ((lineStatus & (UART_LSR_DR_Msk | UART_LINE_ERRORS)) == 0U);

        /* Check the line errors */
        if (lineStatus & UART_LSR_OE_Msk)
        {
            status = kSTATUS_UART_OVERRUN_ERROR;
        }
        /* Check the Break before Parity Error and Frame Error, due to these errors will be triggered too when a break
         * is received */
        else if (lineStatus & UART_LSR_BI_Msk)
        {
            status = kSTATUS_UART_BREAK_DETECTED;
        }
        else if (lineStatus & UART_LSR_PE_Msk)
        {
            status = kSTATUS_UART_PARITY_ERROR;
        }
        else if (lineStatus & UART_LSR_FE_Msk)
        {
            status = kSTATUS_UART_FRAMING_ERROR;
        }
        else
        {
            /* Receive one byte successfully, read it from the receive buffer */
            *dataAddr = (uint8_t)base->RBR;
            dataAddr++;
            dataLeft--;

            status = kSTATUS_SUCCESS;
        }

        if (status != kSTATUS_SUCCESS)
        {
            break;
        }
    }

    return status;
}

status_t UART_writeDataNonBlocking(UART_Type *base, const uint8_t *data, size_t length)
{
    assert(base);
    assert(data);

    /* Get the handle */
    UART_Handle_t *handle = &s_uartHandle[UART_getInstance(base)];

    if (handle->txState == kUART_TX_IDLE)
    {
        handle->txData              = data;
        handle->txDataSize          = length;
        handle->txRemainingDataSize = length;
        handle->txState             = kUART_TX_BUSY;

        if (UART_isFIFOEnabled(base))
        {
            /* Enable programmable transmit holding register empty interrupt, which will be triggered when the FIFO
             * level is below the trigger level */
            ATOMIC_SET_BITS(base->IER, UART_IER_PTIME_Msk | UART_IER_ETBEI_Msk);
        }
        else
        {
            /* Enable transmit empty interrupt if FIFO is disabled */
            ATOMIC_SET_BITS(base->IER, UART_IER_ETBEI_Msk);
        }

        return kSTATUS_SUCCESS;
    }
    else
    {
        return kSTATUS_UART_TX_BUSY;
    }
}

status_t UART_readDataNonBlocking(UART_Type *base, uint8_t *data, size_t length)
{
    assert(base);
    assert(data);

    /* Get the handle */
    UART_Handle_t *handle = &s_uartHandle[UART_getInstance(base)];

    if (handle->rxState == kUART_RX_IDLE)
    {
        handle->rxDataBuf           = data;
        handle->rxDataSize          = length;
        handle->rxRemainingDataSize = length;
        handle->rxState             = kUART_RX_BUSY;

        /* Enable receive data available interrupt and receiver line status interrupt */
        ATOMIC_SET_BITS(base->IER, UART_IER_ERBFI_Msk | UART_IER_ELSI_Msk);

        return kSTATUS_SUCCESS;
    }
    else
    {
        return kSTATUS_UART_RX_BUSY;
    }
}

void UART_abortWriteDataNonBlocking(UART_Type *base)
{
    assert(base);

    /* Get the instance */
    uint32_t instance = UART_getInstance(base);
    /* Get the handle */
    UART_Handle_t *handle = &s_uartHandle[instance];

    if (handle->txState == kUART_TX_BUSY)
    {
        ATOMIC_CLEAR_BITS(base->IER, UART_IER_PTIME_Msk | UART_IER_ETBEI_Msk);

        handle->txDataSize          = 0U;
        handle->txRemainingDataSize = 0U;
        handle->txState             = kUART_TX_IDLE;
    }
}

void UART_abortReadDataNonBlocking(UART_Type *base)
{
    assert(base);

    /* Get the instance */
    uint32_t instance = UART_getInstance(base);
    /* Get the handle */
    UART_Handle_t *handle = &s_uartHandle[instance];

    if (handle->rxState == kUART_RX_BUSY)
    {
        /* Disable RX interrupt. */
        ATOMIC_CLEAR_BITS(base->IER, UART_IER_ERBFI_Msk | UART_IER_ELSI_Msk);

        handle->rxDataSize          = 0U;
        handle->rxRemainingDataSize = 0U;
        handle->rxState             = kUART_RX_IDLE;
    }
}

status_t UART_registerCallback(UART_Type *base, UART_Callback_t callback, uint32_t priority)
{
    return UART_registerCallbackAndISR(base, callback, priority, UART_handleIRQ);
}

status_t UART_unregisterCallback(UART_Type *base)
{
    assert(base);

    /* Get the instance */
    uint32_t instance = UART_getInstance(base);
    /* Get the handle */
    UART_Handle_t *handle = &s_uartHandle[instance];

    /* UART instance hasn't been registered, return failure */
    if ((s_uartISR[instance] == NULL) || (handle->callback == NULL))
    {
        return kSTATUS_FAIL;
    }
    /* There is still a transfer undergoing, return an error */
    if (handle->txState == kUART_TX_BUSY)
    {
        return kSTATUS_UART_TX_BUSY;
    }
    if (handle->rxState == kUART_RX_BUSY)
    {
        return kSTATUS_UART_RX_BUSY;
    }

    /* Clear the handler */
    memset(handle, 0, sizeof(*handle));

    /* Disable the interrupt and restore interrupt priority */
    NVIC_DisableIRQ(s_uartIRQ[instance]);
    NVIC_SetPriority(s_uartIRQ[instance], 0U);

    /* Clear the interrupt service and handle */
    s_uartISR[instance] = NULL;

    return kSTATUS_SUCCESS;
}

void UART_RS485_getDefaultConfig(UART_RS485_Config_t *config)
{
    assert(config);

    UART_getDefaultConfig(&config->config);
    /* Assign default configurations */
    /* One bit cycle */
    config->assertTime   = 1U;
    config->deassertTime = 1U;
    /* One byte cycle for default configuration(8N1) */
    config->DE2RE = 10U;
    config->RE2DE = 10U;
}

status_t UART_RS485HD_init(UART_Type *base, UART_RS485_Config_t *config, uint32_t freqInHz)
{
    status_t status = UART_init(base, &config->config, freqInHz);
    if (status != kSTATUS_SUCCESS)
    {
        return status;
    }

    base->DET =
        UART_DET_DE_ASSERTION_TIME_Set(config->assertTime) | UART_DET_DE_DE_ASSERTION_TIME_Set(config->deassertTime);
    base->TAT = UART_TAT_RE_TO_DE_Set(config->RE2DE) | UART_TAT_DE_TO_RE_Set(config->DE2RE);
    /*
     * Use the RS485 Hardware-Controlled Half Duplex Mode
     * DE and RE polarities are required to be active high in this mode
     * Enable the RS485 Mode
     */
    base->TCR = UART_TCR_XFER_MODE_Set(kUART_RS485_MODE_HALF_DUPLEX_HW) | UART_TCR_DE_POL_Set(1U) |
                UART_TCR_RE_POL_Set(1U) | UART_TCR_RS485_EN_Msk;
    /* Enable the DE and RE, so they will be managed by the hardware in this mode */
    UART_setDE(base, true);
    UART_setRE(base, true);

    return kSTATUS_SUCCESS;
}

status_t UART_RS485HD_deinit(UART_Type *base)
{
    status_t status = UART_deinit(base);
    if (status != kSTATUS_SUCCESS)
    {
        return status;
    }

    /* Disable the DE and RE */
    UART_setDE(base, false);
    UART_setRE(base, false);
    /* Disable RS485 mode */
    base->TCR &= ~UART_TCR_RS485_EN_Msk;

    return kSTATUS_SUCCESS;
}

status_t UART_RS485HD_writeDataNonBlocking(UART_Type *base, const uint8_t *data, size_t length)
{
    assert(base);
    assert(data);

    /* Get the handle */
    UART_Handle_t *handle = &s_uartHandle[UART_getInstance(base)];

    /* TX and RX cannot be started at the same time in Half Duplex Mode */
    if ((handle->txState == kUART_TX_IDLE) && (handle->rxState == kUART_RX_IDLE))
    {
        handle->txData              = data;
        handle->txDataSize          = length;
        handle->txRemainingDataSize = length;
        handle->txState             = kUART_TX_BUSY;

        if (UART_isFIFOEnabled(base))
        {
            /* Enable programmable transmit holding register empty interrupt, which will be triggered when the FIFO
             * level is below the trigger level */
            ATOMIC_SET_BITS(base->IER, UART_IER_PTIME_Msk | UART_IER_ETBEI_Msk);
        }
        else
        {
            /* Enable transmit empty interrupt if FIFO is disabled */
            ATOMIC_SET_BITS(base->IER, UART_IER_ETBEI_Msk);
        }

        return kSTATUS_SUCCESS;
    }
    else
    {
        return (handle->txState == kUART_TX_BUSY) ? kSTATUS_UART_TX_BUSY : kSTATUS_UART_RX_BUSY;
    }
}

status_t UART_RS485HD_readDataNonBlocking(UART_Type *base, uint8_t *data, size_t length)
{
    assert(base);
    assert(data);

    /* Get the handle */
    UART_Handle_t *handle = &s_uartHandle[UART_getInstance(base)];

    /* TX and RX cannot be started at the same time in Half Duplex Mode */
    if ((handle->rxState == kUART_RX_IDLE) && (handle->txState == kUART_TX_IDLE))
    {
        handle->rxDataBuf           = data;
        handle->rxDataSize          = length;
        handle->rxRemainingDataSize = length;
        handle->rxState             = kUART_RX_BUSY;

        /* Enable receive data available interrupt and receiver line status interrupt */
        ATOMIC_SET_BITS(base->IER, UART_IER_ERBFI_Msk | UART_IER_ELSI_Msk);

        return kSTATUS_SUCCESS;
    }
    else
    {
        return (handle->rxState == kUART_RX_BUSY) ? kSTATUS_UART_RX_BUSY : kSTATUS_UART_TX_BUSY;
    }
}

status_t UART_RS485FD_init(UART_Type *base, UART_RS485_Config_t *config, uint32_t freqInHz)
{
    status_t status = UART_init(base, &config->config, freqInHz);
    if (status != kSTATUS_SUCCESS)
    {
        return status;
    }

    base->DET =
        UART_DET_DE_ASSERTION_TIME_Set(config->assertTime) | UART_DET_DE_DE_ASSERTION_TIME_Set(config->deassertTime);
    base->TAT = UART_TAT_RE_TO_DE_Set(config->RE2DE) | UART_TAT_DE_TO_RE_Set(config->DE2RE);
    /* Disable the DE and RE, then they should be managed by software in the RS485 mode 0 */
    UART_setDE(base, false);
    UART_setRE(base, false);
    /*
     * Use the RS485 Software-Controlled Full Duplex Mode
     * DE and RE polarities are fixed to active high
     * Enable the RS485 Mode
     */
    base->TCR = UART_TCR_XFER_MODE_Set(kUART_RS485_MODE_FULL_DUPLEX) | UART_TCR_DE_POL_Set(1U) |
                UART_TCR_RE_POL_Set(1U) | UART_TCR_RS485_EN_Msk;

    return kSTATUS_SUCCESS;
}

status_t UART_RS485FD_registerCallback(UART_Type *base, UART_Callback_t callback, uint32_t priority)
{
    return UART_registerCallbackAndISR(base, callback, priority, UART_RS485FD_handleIRQ);
}

static status_t UART_registerCallbackAndISR(UART_Type *base, UART_Callback_t callback, uint32_t priority,
                                            UART_ISR_t isr)
{
    assert(base);
    assert(callback);

    /* Get the instance */
    uint32_t instance = UART_getInstance(base);
    /* Get the handle */
    UART_Handle_t *handle = &s_uartHandle[instance];

    if ((s_uartISR[instance] != NULL) || (handle->callback != NULL))
    {
        /* UART instance has been registered already, return failure */
        return kSTATUS_FAIL;
    }

    /* Initialize the handle */
    memset(handle, 0, sizeof(*handle));
    handle->txState  = kUART_TX_IDLE;
    handle->rxState  = kUART_RX_IDLE;
    handle->callback = callback;

    /* Enable the driver interrupt service */
    s_uartISR[instance] = isr;

    /* Set interrupt priority and enable the interrupt */
    NVIC_SetPriority(s_uartIRQ[instance], priority);
    NVIC_EnableIRQ(s_uartIRQ[instance]);

    return kSTATUS_SUCCESS;
}

static void UART_handleIRQ(UART_Type *base, UART_Handle_t *handle)
{
    UART_InterruptIdentification_t irqStatus  = UART_getInterruptIdentification(base);

    switch (irqStatus)
    {
        default:
        case kUART_IRQ_NO_PENDING:
            /* Do nothing */
            break;
        case kUART_IRQ_MODEM_STATUS:
            handle->callback(base, handle, kSTATUS_UART_MODEM_IRQ);
            break;
        case kUART_IRQ_TRANSMIT_HOLDING_EMPTY:
            UART_handleTxEmptyIRQ(base, handle);
            break;
        case kUART_IRQ_RECEIVE_DATA_AVAILABLE:
            UART_handleRxDataIRQ(base, handle);
            break;
        case kUART_IRQ_RECEIVER_LINE_STATUS:
            UART_handleLineIRQ(base, handle);
            break;
        case kUART_IRQ_BUSY_DETECT:
            handle->callback(base, handle, kSTATUS_UART_BUSY);
            /* Dummy read to clear the interrupt */
            (void)UART_isBusy(base);
            break;
        case kUART_IRQ_TIMEOUT:
            handle->callback(base, handle, kSTATUS_UART_RX_TIMEOUT);
            /* Continue to handle the data. The timeout interrupt will be cleared at the same time */
            UART_handleRxDataIRQ(base, handle);
            break;
    }
}

static void UART_handleTxEmptyIRQ(UART_Type *base, UART_Handle_t *handle)
{
    if (handle->txRemainingDataSize > 0U)
    {
        size_t txSpace;

        if (UART_isFIFOEnabled(base))
        {
            txSpace = HTE_FEATURE_UART_FIFO_MAX_LEVEL - UART_getTxFIFOLevel(base);
        }
        else
        {
            txSpace = 1U;
        }

        size_t lengthToTx            = MIN(handle->txRemainingDataSize, txSpace);
        handle->txRemainingDataSize -= lengthToTx;
        if ((handle->txRemainingDataSize == 0U) && UART_isFIFOEnabled(base))
        {
            /* Disable the programmable Transmit Holding Register empty interrupt, and enable Transmit Holding Register
             * empty interrupt. So the next TX empty interrupt will be triggered after the entire data is sent */
            ATOMIC_CLEAR_AND_SET_BITS(base->IER, UART_IER_PTIME_Msk, UART_IER_ETBEI_Msk);
        }
        /* Write data bytes at the end of the branch. So the data transaction cannot be completed before exiting the isr
         * when the data bytes is few. Otherwise, the next TX empty IRQ will be missed */
        UART_writeArrayNonBlocking(base, handle->txData, lengthToTx);
        handle->txData = &handle->txData[lengthToTx];
    }
    else
    {
        /* Transmit is completed*/
        ATOMIC_CLEAR_BITS(base->IER, UART_IER_ETBEI_Msk);
        handle->txState  = kUART_TX_IDLE;
        handle->callback(base, handle, kSTATUS_UART_TX_IDLE);
    }
}

static void UART_handleRxDataIRQ(UART_Type *base, UART_Handle_t *handle)
{
    if (handle->rxRemainingDataSize > 0U)
    {
        size_t rxData;
        if (UART_isFIFOEnabled(base))
        {
            rxData = UART_getRxFIFOLevel(base);
        }
        else
        {
            rxData = 1U;
        }

        size_t lengthToRx = MIN(handle->rxRemainingDataSize, rxData);
        UART_readArrayNonBlocking(base, handle->rxDataBuf, lengthToRx);
        handle->rxDataBuf            = &handle->rxDataBuf[lengthToRx];
        handle->rxRemainingDataSize -= lengthToRx;
    }

    /* Receive is completed*/
    if (handle->rxRemainingDataSize == 0U)
    {
        ATOMIC_CLEAR_BITS(base->IER, UART_IER_ERBFI_Msk | UART_IER_ELSI_Msk);
        handle->rxState  = kUART_RX_IDLE;
        handle->callback(base, handle, kSTATUS_UART_RX_IDLE);
    }
}

static void UART_handleLineIRQ(UART_Type *base, UART_Handle_t *handle)
{
    uint32_t lineError = UART_getLineStatus(base) & UART_LINE_ERRORS;

    if (lineError & UART_LSR_OE_Msk)
    {
        handle->callback(base, handle, kSTATUS_UART_OVERRUN_ERROR);
    }

    if (lineError & UART_LSR_BI_Msk)
    {
        handle->callback(base, handle, kSTATUS_UART_BREAK_DETECTED);
    }
    else
    {
        /* Break will cause Parity Error and Frame Error, only handle these errors when no Break is detected */
        if (lineError & UART_LSR_PE_Msk)
        {
            handle->callback(base, handle, kSTATUS_UART_PARITY_ERROR);
        }
        if (lineError & UART_LSR_FE_Msk)
        {
            handle->callback(base, handle, kSTATUS_UART_FRAMING_ERROR);
        }
    }
}

static void UART_RS485FD_handleIRQ(UART_Type *base, UART_Handle_t *handle)
{
    UART_InterruptIdentification_t irqStatus = UART_getInterruptIdentification(base);

    switch (irqStatus)
    {
        default:
        case kUART_IRQ_NO_PENDING:
            /* Do nothing */
            break;
        case kUART_IRQ_MODEM_STATUS:
            handle->callback(base, handle, kSTATUS_UART_MODEM_IRQ);
            break;
        case kUART_IRQ_TRANSMIT_HOLDING_EMPTY:
            UART_RS485FD_handleTxEmptyIRQ(base, handle);
            break;
        case kUART_IRQ_RECEIVE_DATA_AVAILABLE:
            UART_RS485FD_handleRxDataIRQ(base, handle);
            break;
        case kUART_IRQ_RECEIVER_LINE_STATUS:
            UART_handleLineIRQ(base, handle);
            break;
        case kUART_IRQ_BUSY_DETECT:
            handle->callback(base, handle, kSTATUS_UART_BUSY);
            /* Dummy read to clear the interrupt */
            (void)UART_isBusy(base);
            break;
        case kUART_IRQ_TIMEOUT:
            handle->callback(base, handle, kSTATUS_UART_RX_TIMEOUT);
            /* Dummy read to clear the interrupt */
            (void)base->RBR;
            break;
    }
}

static void UART_RS485FD_handleTxEmptyIRQ(UART_Type *base, UART_Handle_t *handle)
{
    if (handle->txRemainingDataSize > 0U)
    {
        /* Enable DE */
        UART_setDE(base, true);
    }
    else
    {
        /* Disable DE */
        UART_setDE(base, false);
    }

    UART_handleTxEmptyIRQ(base, handle);
}

static void UART_RS485FD_handleRxDataIRQ(UART_Type *base, UART_Handle_t *handle)
{
    UART_handleRxDataIRQ(base, handle);

    /* Receive is completed*/
    if (handle->rxRemainingDataSize == 0U)
    {
        /* Disable RE */
        UART_setRE(base, false);
    }
}

#if defined(UARTA)
void UARTA_DriverHandler(void)
{
    if (s_uartISR[0] != NULL)
    {
        s_uartISR[0](UARTA, &s_uartHandle[0]);
    }
    ISR_EXIT_BARRIER();
}
#endif

#if defined(UARTB)
void UARTB_DriverHandler(void)
{
    if (s_uartISR[1] != NULL)
    {
        s_uartISR[1](UARTB, &s_uartHandle[1]);
    }
    ISR_EXIT_BARRIER();
}
#endif

#if defined(UARTC)
void UARTC_DriverHandler(void)
{
    if (s_uartISR[2] != NULL)
    {
        s_uartISR[2](UARTC, &s_uartHandle[2]);
    }
    ISR_EXIT_BARRIER();
}
#endif

#if defined(UARTD)
void UARTD_DriverHandler(void)
{
    if (s_uartISR[3] != NULL)
    {
        s_uartISR[3](UARTD, &s_uartHandle[3]);
    }
    ISR_EXIT_BARRIER();
}
#endif
