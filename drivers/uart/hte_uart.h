/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_uart.h
 * \brief SDK UART driver header file
 * \version 1.0.0
 */

#ifndef HTE_UART_H
#define HTE_UART_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_common.h"

/*!
 * \addtogroup DRV_HTE_UART UART Driver
 *
 * \brief SDK UART driver
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! \brief UART driver version */
#define UART_DRIVER_VERSION MAKE_VERSION('V', 1U, 0U, 0U)

/*! \brief UART retry times for blocking operations, 0 for waiting infinitely */
#ifndef UART_RETRY_TIMES
#define UART_RETRY_TIMES (0U)
#endif

/*! \brief The max value of UART divisor */
#define UART_DIVISOR_MAX (0xFFFFU)

/*! \brief The max percentage of UART Baud rate deviation */
#define UART_BAUDRATE_DEVIATION_PERCENT_MAX (2U) /* 2% */

/*! \brief UART status codes */
enum
{
    kSTATUS_UART_DIVISOR_OVERRANGE    = MAKE_STATUS(kSTATUSGROUP_UART, 0U), /*!< Divisor is out of the accepted range */
    kSTATUS_UART_UNSUPPORTED_BAUDRATE = MAKE_STATUS(kSTATUSGROUP_UART, 1U), /*!< The baud rate is not supported */
    kSTATUS_UART_BUSY                 = MAKE_STATUS(kSTATUSGROUP_UART, 2U), /*!< UART is busy, and not configurable */
    kSTATUS_UART_OVERRUN_ERROR        = MAKE_STATUS(kSTATUSGROUP_UART, 3U), /*!< Receiver overrun error */
    kSTATUS_UART_PARITY_ERROR         = MAKE_STATUS(kSTATUSGROUP_UART, 4U), /*!< Parity error */
    kSTATUS_UART_FRAMING_ERROR        = MAKE_STATUS(kSTATUSGROUP_UART, 5U), /*!< Framing error */
    kSTATUS_UART_BREAK_DETECTED       = MAKE_STATUS(kSTATUSGROUP_UART, 6U), /*!< Break detected */
    kSTATUS_UART_RX_TIMEOUT           = MAKE_STATUS(kSTATUSGROUP_UART, 7U), /*!< Timeout during receiving a byte */
    kSTATUS_UART_TX_BUSY              = MAKE_STATUS(kSTATUSGROUP_UART, 8U), /*!< UART transmitter is busy */
    kSTATUS_UART_TX_IDLE              = MAKE_STATUS(kSTATUSGROUP_UART, 9U), /*!< UART transmitter is idle */
    kSTATUS_UART_RX_BUSY              = MAKE_STATUS(kSTATUSGROUP_UART, 10U), /*!< UART receiver is busy */
    kSTATUS_UART_RX_IDLE              = MAKE_STATUS(kSTATUSGROUP_UART, 11U), /*!< UART receiver is idle */
    kSTATUS_UART_MODEM_IRQ            = MAKE_STATUS(kSTATUSGROUP_UART, 12U), /*!< MODEM IRQ is detected */
};

/*! \brief Mask for all UART interrupts */
#define UART_IRQ_ALL \
    (UART_IER_ERBFI_Msk | UART_IER_ETBEI_Msk | UART_IER_ELSI_Msk | UART_IER_EDSSI_Msk | UART_IER_PTIME_Msk)

/*! \brief Mask for all UART line errors */
#define UART_LINE_ERRORS (UART_LSR_OE_Msk | UART_LSR_PE_Msk | UART_LSR_FE_Msk | UART_LSR_BI_Msk)

/*! \brief UART interrupt identification */
typedef enum
{
    kUART_IRQ_MODEM_STATUS           = 0x0U, /*!< Modem status interrupt */
    kUART_IRQ_NO_PENDING             = 0x1U, /*!< No interrupt pending */
    kUART_IRQ_TRANSMIT_HOLDING_EMPTY = 0x2U, /*!< Transmit holding register empty interrupt */
    kUART_IRQ_RECEIVE_DATA_AVAILABLE = 0x4U, /*!< Received data available */
    kUART_IRQ_RECEIVER_LINE_STATUS   = 0x6U, /*!< Receiver line status interrupt */
    kUART_IRQ_BUSY_DETECT            = 0x7U, /*!< Busy detected */
    kUART_IRQ_TIMEOUT                = 0xCU, /*!< Character timeout */
} UART_InterruptIdentification_t;

/*! \brief UART RX FIFO trigger level */
typedef enum
{
    kUART_RX_FIFO_NOT_EMPTY =
        0x0U, /*!< RX received data available interrupt trigger when one char at least is in the RX FIFO */
    kUART_RX_FIFO_ONE_QUARTER =
        0x1U, /*!< RX received data available interrupt trigger when a quarter of the RX FIFO is full */
    kUART_RX_FIFO_HALF     = 0x2U, /*!< RX received data available interrupt trigger when half of the RX FIFO is full */
    kUART_RX_FIFO_TWO_LESS = 0x3U  /*!< RX received data available interrupt trigger when two more are short of full */
} UART_RxTrigLevel_t;

/*! \brief UART TX FIFO trigger level */
typedef enum
{
    kUART_TX_FIFO_EMPTY    = 0x0U, /*!< TX THRE interrupt trigger when the TX FIFO is empty */
    kUART_TX_FIFO_TWO_CHAR = 0x1U, /*!< TX THRE interrupt trigger when no more than two bytes left in the TX FIFO */
    kUART_TX_FIFO_ONE_QUARTER =
        0x2U,                 /*!< TX THRE interrupt trigger when data count is less than one quarter of the TX FIFO */
    kUART_TX_FIFO_HALF = 0x3U /*!< TX THRE interrupt trigger when data count is less than half of the TX FIFO */
} UART_TxTrigLevel_t;

/*! \brief UART word length in bits */
typedef enum
{
    kUART_DATA_LENGTH_5BITS = 0x0U, /*!< 5bits per word */
    kUART_DATA_LENGTH_6BITS = 0x1U, /*!< 6bits per word */
    kUART_DATA_LENGTH_7BITS = 0x2U, /*!< 7bits per word */
    kUART_DATA_LENGTH_8BITS = 0x3U  /*!< 8bits per word */
} UART_DataLength_t;

/*! \brief UART stop bit */
typedef enum
{
    kUART_STOP_BIT_1 = 0x0U, /*!< One stop bit per word */
    kUART_STOP_BIT_2 = 0x1U  /*!< Two stop bits per word */
} UART_StopBit_t;

/*! \brief UART parity type */
typedef enum
{
    kUART_PARITY_NONE       = 0x0U, /*!< No parity */
    kUART_PARITY_ODD        = 0x1U, /*!< Odd parity */
    kUART_PARITY_EVEN       = 0x2U, /*!< Even parity */
    kUART_PARITY_STICK_ONE  = 0x3U, /*!< Stick parity bit to 1 */
    kUART_PARITY_STICK_ZERO = 0x4U  /*!< Stick parity bit to 0 */
} UART_Parity_t;

/*! \brief Structure type for UART configuration */
typedef struct
{
    uint32_t baudRate; /*!< Baud rate */

    UART_DataLength_t dataLength; /*!< Data bits per word */
    UART_Parity_t     parityType; /*!< Type of parity check */
    UART_StopBit_t    stopBit;    /*!< Stop bits per word */

    bool               enableFIFO;  /*!< Enable FIFO */
    UART_TxTrigLevel_t txFIFOLevel; /*!< The TX FIFO empty trigger level, takes effect when \ref enableFIFO is true */
    UART_RxTrigLevel_t rxFIFOLevel; /*!< The RX FIFO full trigger level, takes effect when \ref enableFIFO is true */
} UART_Config_t;

/*! \brief RS485 transfer mode */
typedef enum
{
    kUART_RS485_MODE_FULL_DUPLEX    = 0x0U, /*!< Full duplex mode */
    kUART_RS485_MODE_HALF_DUPLEX_SW = 0x1U, /*!< Software-controlled half duplex mode */
    kUART_RS485_MODE_HALF_DUPLEX_HW = 0x2U  /*!< Hardware-controlled half duplex mode */
} UART_RS485_Mode_t;

/*! \brief Structure type for UART RS485 configuration */
typedef struct
{
    UART_Config_t config; /*!< UART configuration */

    uint8_t assertTime;   /*!< DE assert time(from DE activation to the beginning of the start bit) in UART serial clock
                             cycles */
    uint8_t deassertTime; /*!< DE de-assert time(from the end of the last stop bit to DE de-activation) in UART serial
                             clock cycles */
    uint16_t DE2RE;       /*!< Wait serial clock cycles before switching to transmit from receive */
    uint16_t RE2DE;       /*!< Wait serial clock cycles before switching to receive from transmit */
} UART_RS485_Config_t;

/*! \brief UART transmit state */
typedef enum
{
    kUART_TX_IDLE = 0U, /*!< UART TX is idle */
    kUART_TX_BUSY = 1U, /*!< UART TX is busy */
} UART_TxState_t;

/*! \brief UART receive state */
typedef enum
{
    kUART_RX_IDLE = 0U, /*!< UART RX is idle */
    kUART_RX_BUSY = 1U, /*!< UART RX is busy */
} UART_RxState_t;

/*! \brief Forward declaration for UART transfer handle */
typedef struct UART_Handle UART_Handle_t;

/*!
 * \brief Type definition for the UART transfer callback
 *
 * \param[in] base UART base address
 * \param[in] handle UART transfer handle
 * \param[in] status UART transfer status
                     - kSTATUS_UART_BUSY
                     - kSTATUS_UART_OVERRUN_ERROR
                     - kSTATUS_UART_PARITY_ERROR
                     - kSTATUS_UART_FRAMING_ERROR
                     - kSTATUS_UART_BREAK_DETECTED
                     - kSTATUS_UART_RX_TIMEOUT
                     - kSTATUS_UART_TX_IDLE
                     - kSTATUS_UART_RX_IDLE
                     - kSTATUS_UART_MODEM_IRQ
 */
typedef void (*UART_Callback_t)(UART_Type *base, UART_Handle_t *handle, status_t status);

/*!
 * \brief Type definition for the UART interrupt service function
 *
 * \param[in] base UART base address
 * \param[in] handle UART transfer handle
 */
typedef void (*UART_ISR_t)(UART_Type *base, UART_Handle_t *handle);

/*! \brief Type definition for UART transfer handle */
struct UART_Handle
{
    volatile UART_TxState_t txState;     /*!< TX state */
    const uint8_t * volatile txData;     /*!< Address of remaining data to transmit */
    size_t          txDataSize;          /*!< Size of the data to transmit */
    volatile size_t txRemainingDataSize; /*!< Size of the remaining data to transmit */

    volatile UART_RxState_t rxState;     /*!< RX state*/
    uint8_t * volatile rxDataBuf;        /*!< Address of remaining data to receive */
    size_t          rxDataSize;          /*!< Size of the data to receive */
    volatile size_t rxRemainingDataSize; /*!< Size of the remaining data to receive */

    UART_Callback_t callback; /*!< Transfer callback function */
};

/*******************************************************************************
 * APIs
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \name UART Low-level APIs
 *
 * @{
 */

/*!
 * \brief Enable the UART interrupt
 *
 * \details This function enables the UART interrupt
 *
 * \param[in] base UART base address
 * \param[in] mask The interrupts to enable. Logical ORed of UART IER mask
 */
static inline void UART_enableInterrupt(UART_Type *base, uint32_t mask)
{
    assert(base);
    base->IER |= (mask & UART_IRQ_ALL);
}

/*!
 * \brief Disable the UART interrupt
 *
 * \details This function disables the UART interrupt
 *
 * \param[in] base UART base address
 * \param[in] mask The interrupts to disable. Logical ORed of UART IER mask
 */
static inline void UART_disableInterrupt(UART_Type *base, uint32_t mask)
{
    assert(base);
    base->IER &= ~(mask & UART_IRQ_ALL);
}

/*!
 * \brief  Get the UART interrupt identification ID
 *
 * \details This function read and returns the UART interrupt  identification ID
 *
 * \param[in] base UART base address
 *
 * \retval Interrupt identification ID
 */
static inline UART_InterruptIdentification_t UART_getInterruptIdentification(UART_Type *base)
{
    assert(base);
    return (UART_InterruptIdentification_t)UART_IIR_IID_Get(base->IIR);
}

/*!
 * \brief Check whether FIFO is enabled
 *
 * \details This function returns a flag indicating whether the FIFO is enabled
 *
 * \param[in] base UART base address
 *
 * \return Return the flag of the FIFO status
 *         - True: FIFO is enabled
 *         - False: FIFO is disabled
 */
static inline bool UART_isFIFOEnabled(UART_Type *base)
{
    assert(base);
    return ((base->IIR & UART_IIR_FIFOSE_Msk) != 0U);
}

/*!
 * \brief Get current UART TX FIFO level
 *
 * \details This function returns the currently TX FIFO level, which indicates the byte count of the data in the TX FIFO
 *
 * \param[in] base UART base address
 *
 * \return The byte count of the data in the TX FIFO
 */
static inline uint32_t UART_getTxFIFOLevel(UART_Type *base)
{
    assert(base);
    return UART_TFL_TFL_Get(base->TFL);
}

/*!
 * \brief Get current UART RX FIFO level
 *
 * \details This function returns the currently RX FIFO level, which indicates the byte count of the data in the RX FIFO
 *
 * \param[in] base UART base address
 *
 * \return The byte count of the data in the RX FIFO
 */
static inline uint32_t UART_getRxFIFOLevel(UART_Type *base)
{
    assert(base);
    return UART_RFL_RFL_Get(base->RFL);
}

/*!
 * \brief Start to transmit a break
 *
 * \details This function causes a break to be transmitted to the receiving device
 *
 * \param[in] base UART base address
 * \param[in] enable start or stop the break
 *                   - true: start
 *                   - false: stop
 */
static inline void UART_setBreak(UART_Type *base, bool enable)
{
    assert(base);
    if (enable)
    {
        base->LCR |= UART_LCR_BC_Msk;
    }
    else
    {
        base->LCR &= ~UART_LCR_BC_Msk;
    }
}

/*!
 * \brief Get the UART line status
 *
 * \details This function returns the UART line status
 *
 * \param[in] base UART base address
 *
 * \return The line status
 */
static inline uint32_t UART_getLineStatus(UART_Type *base)
{
    assert(base);
    return base->LSR;
}

/*!
 * \brief Check whether data byte is received
 *
 * \details This function returns a flag indicating whether there is at least one byte in the RX buff or RX FIFO
 *
 * \param[in] base UART base address
 *
 * \return The flag of the received data status
 *         - True: One byte at least is received
 *         - False: No data is received
 */
static inline bool UART_isDataAvailable(UART_Type *base)
{
    assert(base);
    return ((base->LSR & UART_LSR_DR_Msk) != 0U);
}

/*!
 * \brief Check if the Transmit Holding Register or TX FIFO is empty
 *
 * \details This function returns a flag indicating whether the Transmit Holding Register or TX FIFO is empty
 *
 * \param[in] base UART base address
 *
 * \return Return the status of the Transmit Holding Register
 *         - True: Empty
 *         - False: Not Empty
 */
static inline bool UART_isTransmitHoldingEmpty(UART_Type *base)
{
    assert(base);
    return ((base->LSR & UART_LSR_THRE_Msk) != 0U);
}

/*!
 * \brief Check if the Transmitter Shift Register is empty
 *
 * \details This function returns a flag indicating whether the Transmitter Shift Register is empty.
 *
 * \param[in] base UART base address
 *
 * \return Return the flag of the Transmit Shift Register status
 *         - True: Empty
 *         - False: Not Empty
 */
static inline bool UART_isTransmitRegisterEmpty(UART_Type *base)
{
    assert(base);
    return ((base->LSR & UART_LSR_TEMT_Msk) != 0U);
}

/*!
 * \brief Check whether there is any space in the Transmit Holding Register or TX FIFO
 *
 * \details This function returns a flag indicating whether there is any space in the Transmit Holding Register or TX
 * FIFO
 *
 * \param[in] base UART base address
 *
 * \return The flag of the space status
 *         - True: One byte space at least is available
 *         - False: No space left
 */
static inline bool UART_isSpaceAvailable(UART_Type *base)
{
    assert(base);
    if (UART_isFIFOEnabled(base))  
    {
        return (UART_getTxFIFOLevel(base) < HTE_FEATURE_UART_FIFO_MAX_LEVEL);
    }
    else
    {
        return UART_isTransmitHoldingEmpty(base);
    }
}

/*!
 * \brief Get the UART modem status
 *
 * \details This function returns the UART modem status
 *
 * \param[in] base UART base address
 *
 * \return The modem status
 */
static inline uint32_t UART_getModemStatus(UART_Type *base)
{
    assert(base);
    return base->MSR;
}

/*!
 * \brief Get the UART status
 *
 * \details This function returns the UART status
 *
 * \param[in] base UART base address
 *
 * \return The UART status
 */
static inline uint32_t UART_getUartStatus(UART_Type *base)
{
    assert(base);
    return base->USR;
}

/*!
 * \brief Check if the UART is busy.
 *
 * \details This function returns a flag indicating whether or not the UART FIFO is busy
 *
 * \param[in] base UART base address
 *
 * \return The flag of the UART state
 *         - True: UART is busy
 *         - False: UART is idle or inactive
 */
static inline bool UART_isBusy(UART_Type *base)
{
    assert(base);
    return ((base->USR & UART_USR_BUSY_Msk) != 0U);
}

/*!
 * \brief Set the UART RS485 transfer mode
 *
 * \details This function sets the UART RS485 transfer mode. For the details of each mode, please refer the device's
 * \<\<Technical Reference Manual\>\>
 *
 * \param[in] base UART base address
 * \param[in] mode UART RS485 mode
 */
static inline void UART_setRS485Mode(UART_Type *base, UART_RS485_Mode_t mode)
{
    assert(base);
    base->TCR = (base->TCR & (~UART_TCR_XFER_MODE_Msk)) | UART_TCR_XFER_MODE_Set(mode);
}

/*!
 * \brief Enable the UART RS485 mode
 *
 * \details This function enables the UART RS485 mode
 *
 * \param[in] base UART base address
 */
static inline void UART_enableRS485Mode(UART_Type *base)
{
    assert(base);
    base->TCR |= UART_TCR_RS485_EN_Msk;
}

/*!
 * \brief Disable the UART RS485 mode
 *
 * \details This function disables the UART RS485 mode
 *
 * \param[in] base UART base address
 */
static inline void UART_disableRS485Mode(UART_Type *base)
{
    assert(base);
    base->TCR &= ~UART_TCR_RS485_EN_Msk;
}

/*!
 * \brief Control the UART RS485 DE signal
 *
 * \details This function controls the UART RS485 DE signal
 *
 * \param[in] base UART base address
 * \param[in] enable Enable the DE signal
 */
static inline void UART_setDE(UART_Type *base, bool enable)
{
    assert(base);
    base->DE_EN = enable ? 1U : 0U;
}

/*!
 * \brief Control the UART RS485 RE signal
 *
 * \details This function controls the UART RS485 RE signal
 *
 * \param[in] base UART base address
 * \param[in] enable Enable the RE signal
 */
static inline void UART_setRE(UART_Type *base, bool enable)
{
    assert(base);
    base->RE_EN = enable ? 1U : 0U;
}

/*!
 * \brief Write one byte into the Transmit Holding Register without blocking method
 *
 * \details This function writes one char into the Transmit Holding Register, assuming there is enough space left in the
 * TX FIFO or the register
 *
 * \param[in] base UART base address
 * \param[in] data The byte to be transferred
 */
static inline void UART_writeByteNonBlocking(UART_Type *base, uint8_t data)
{
    assert(base);
    base->THR = data;
}

/*!
 * \brief  Read one byte from the Receive Buffer Register without blocking method
 *
 * \details This function reads data from the Receive Buffer Register, assuming data is available in the RX FIFO or the
 * register already
 *
 * \param[in] base UART base address
 *
 * \retval the char which is received
 */
static inline uint8_t UART_readByteNonBlocking(UART_Type *base)
{
    assert(base);
    return (uint8_t)base->RBR;
}

/*!
 * \brief Write data into the Transmit Holding Register without blocking method
 *
 * \details This function writes data bytes into the Transmit Holding Register, assume there is enough space in the TX
 * Holding Register or TX FIFO
 *
 * \param[in] base UART base address
 * \param[in] data The pointer to the data bytes
 * \param[in] length The byte count of the data to transfer
 */
static inline void UART_writeArrayNonBlocking(UART_Type *base, const uint8_t *data, size_t length)
{
    assert(base);
    assert(data);

    for (size_t i = 0; i < length; i++)
    {
        base->THR = data[i];
    }
}

/*!
 * \brief Read data from the Receive Buffer Register without blocking method
 *
 * \details This function reads data bytes from the Receive Buffer Register, assume there are enough data bytes
 * available in RX Buffer Register or RX FIFO
 *
 * \param[in] base UART base address
 * \param[in] data The pointer to the data bytes
 * \param[in] length The byte count of the data to transfer
 */
static inline void UART_readArrayNonBlocking(UART_Type *base, uint8_t *data, size_t length)
{
    assert(base);
    assert(data);

    for (size_t i = 0; i < length; i++)
    {
        data[i] = base->RBR;
    }
}

/*!
 * @}
 */

/*!
 * \name UART High-level APIs
 *
 * @{
 */

/*!
 * \brief Get UART instance using the base address
 *
 * \details This function converts UART base address to UART instance which is an unsigned integer value. 0,1,2,3,...
 * stands for the peripheral with suffix A,B,C,D...
 *
 * \param[in] base UART base address
 *
 * \return The UART instance
 */
uint32_t UART_getInstance(UART_Type *base);

/*!
 * \brief Get UART default configurations
 *
 * \details This function fills the UART configuration variable to a default value. The default is
 *          config->baudRate    = 115200U;
 *          config->dataLength  = kUART_DATA_LENGTH_8BITS;
 *          config->stopBit     = kUART_STOP_BIT_1;
 *          config->parityType  = kUART_PARITY_NONE;
 *          config->txFIFOLevel = kUART_TX_FIFO_EMPTY;
 *          config->rxFIFOLevel = kUART_RX_FIFO_IS_1_CHAR;
 *
 * \param[out] config UART configuration
 */
void UART_getDefaultConfig(UART_Config_t *config);

/*!
 * \brief UART initialization
 *
 * \details Initialize UART with the configuration
 *
 * \param[in] base UART base address
 * \param[in] config UART configuration
 * \param[in] freqInHz UART clock frequency
 *
 * \retval kSTATUS_SUCCESS   Success to initialize UART
 * \retval kSTATUS_UART_BUSY A transmission is under processing
 * \retval kSTATUS_UART_DIVISOR_OVERRANGE Divisor is out of the accepted range
 * \retval kSTATUS_UART_UNSUPPORTED_BAUDRATE The baud rate is not supported
 */
status_t UART_init(UART_Type *base, UART_Config_t *config, uint32_t freqInHz);

/*!
 * \brief UART de-initialization
 *
 * \details De-initialize UART
 *
 * \param[in] base UART base address
 *
 * \retval kSTATUS_SUCCESS Success to de-initialize UART
 * \retval kSTATUS_UART_BUSY A transmission is under processing
 */
status_t UART_deinit(UART_Type *base);

/*!
 * \brief Set the UART baud rate
 *
 * \details This function sets the UART baud rate.
 *
 * \param[in] base UART base address
 * \param[in] freqInHz UART Clock frequency
 * \param[in] baudRate UART baud rate
 *
 * \retval kSTATUS_SUCCESS Success to de-initialize UART
 * \retval kSTATUS_UART_BUSY A transmission is under processing
 * \retval kSTATUS_UART_DIVISOR_OVERRANGE Divisor is out of the accepted range
 * \retval kSTATUS_UART_UNSUPPORTED_BAUDRATE The baud rate is not supported
 */
status_t UART_setBaudRate(UART_Type *base, uint32_t freqInHz, uint32_t baudRate);

/*!
 * \brief Transmit data with blocking method
 *
 * \details This function checks if the transfer FIFO have space firstly, then writes data into the FIFO, and wait until
 * the transfer register to be empty which indicates the last byte has been transmitted successfully
 *
 * \param[in] base UART base address
 * \param[in] data The pointer to the data bytes
 * \param[in] length The byte count of the data to transfer
 *
 * \retval kSTATUS_SUCCESS Success to transmit data
 * \retval kSTATUS_TIMEOUT Transaction is timeout, and aborted
 */
status_t UART_writeDataBlocking(UART_Type *base, const uint8_t *data, size_t length);

/*!
 * \brief Receive data with blocking method
 *
 * \details Firstly this function checks if the receive FIFO have bytes received, then reads data from the FIFO, and
 * check if there is any error during the receive operation
 *
 * \param[in] base UART base address
 * \param[in] data The pointer to the data buffer
 * \param[in] length The byte count of the data to receive
 *
 * \retval kSTATUS_SUCCESS Success to receive data
 * \retval kSTATUS_TIMEOUT Transaction is timeout, and aborted
 * \retval kSTATUS_UART_OVERRUN_ERROR Data overrun error
 * \retval kSTATUS_UART_BREAK_DETECTED Break is detected
 * \retval kSTATUS_UART_PARITY_ERROR Parity error
 * \retval kSTATUS_UART_FRAMING_ERROR Framing error
 */
status_t UART_readDataBlocking(UART_Type *base, uint8_t *data, size_t length);

/*!
 * \brief Write data without blocking method
 *
 * \details This function writes data into the FIFO
 *
 * \param[in] base UART base address
 * \param[in] data The pointer to the data buffer
 * \param[in] length The byte count of the data to receive
 *
 * \retval kSTATUS_SUCCESS Success to de-initialize UART
 * \retval kSTATUS_UART_TX_BUSY There is a TX transmission under going already. New transmit cannot be started
 */
status_t UART_writeDataNonBlocking(UART_Type *base, const uint8_t *data, size_t length);

/*!
 * \brief Receive data without blocking method
 *
 * \details Reads data from the FIFO, and check if there is any error during the receive operation
 *
 * \param[in] base UART base address
 * \param[in] data The pointer to the data buffer
 * \param[in] length The byte count of the data to receive
 *
 * \retval kSTATUS_SUCCESS Success to de-initialize UART
 * \retval kSTATUS_UART_RX_BUSY There is a RX transmission under going already. New receive cannot be started
 */
status_t UART_readDataNonBlocking(UART_Type *base, uint8_t *data, size_t length);

/*!
 * \brief Abort the non-blocking(interrupt) data transmitting
 *
 * \details This function aborts the non-blocking data transmitting and disables relative UART interrupts
 *
 * \note The data bytes which have been filled into the FIFO or Transmit Holding Register will still be sent out after
 * This function is called
 *
 * \param[in] base UART base address
 */
void UART_abortWriteDataNonBlocking(UART_Type *base);

/*!
 * \brief Abort the non-blocking(interrupt) data receiving
 *
 * \details This function aborts the non-blocking data receiving and disables relative UART interrupts
 *
 * \note The data bytes which have been received but not read by software will be keep in the FIFO or Transmit Holding
 * Register
 *
 * \param[in] base UART base address
 */
void UART_abortReadDataNonBlocking(UART_Type *base);

/*!
 * \brief Register user callback function to a specified UART for non-blocking transfer
 *
 * \details This function registers user callback function for non-blocking transfer which uses IRQ. The relative IRQ
 * will be enabled in the NVIC and the priority will be configured at the same time
 *
 * \param[in] base UART base address
 * \param[in] callback UART user callback
 * \param[in] priority IRQ priority
 *
 * \retval kSTATUS_SUCCESS Success to the operation
 * \retval kSTATUS_FAIL Register to a UART which has been registered already. Need to call \ref
 UART_unregisterCallback() before the re-registration
 */
status_t UART_registerCallback(UART_Type *base, UART_Callback_t callback, uint32_t priority);

/*!
 * \brief Un-register user callback function to a specified UART for non-blocking transfer
 *
 * \details This function clears the registered user callback function, and disable the relative IRQ in the NVIC
 *
 * \param[in] base UART base address
 *
 * \retval kSTATUS_SUCCESS Success to the operation
 * \retval kSTATUS_FAIL The UART hasn't been registered to a callback
 * \retval kSTATUS_UART_TX_BUSY There is a transmit operation under going, need to wait it completed, or call \ref
 * UART_abortWriteDataNonBlocking() before un-register the callback
 * \retval kSTATUS_UART_RX_BUSY There is a receive operation under going, need to wait it completed, or call \ref
 * UART_abortReadDataNonBlocking() before un-register the callback
 */
status_t UART_unregisterCallback(UART_Type *base);

/*!
 * @}
 */

/*!
 * \name UART RS485 Half Duplex(HD) Mode High-level APIs
 *
 * @{
 */

/*!
 * \brief Get UART default configurations
 *
 * \details This function fills the UART configuration variable to a default value. The default is
 *          config->config.baudRate    = 115200U;
 *          config->config.dataLength  = kUART_DATA_LENGTH_8BITS;
 *          config->config.stopBit     = kUART_STOP_BIT_1;
 *          config->config.parityType  = kUART_PARITY_NONE;
 *          config->config.txFIFOLevel = kUART_TX_FIFO_EMPTY;
 *          config->config.rxFIFOLevel = kUART_RX_FIFO_IS_1_CHAR;
 *          config->assertTime         = 1U;
 *          config->deassertTime       = 1U;
 *          config->DE2RE              = 10U;
 *          config->RE2DE              = 10U;
 *
 * \param[out] config UART configuration
 */
void UART_RS485_getDefaultConfig(UART_RS485_Config_t *config);

/*!
 * \brief UART RS485 Half Duplex Mode initialization
 *
 * \details Initialize UART 485 Half Duplex Mode with the configuration
 *
 * \param[in] base UART base address
 * \param[in] config UART RS485 configuration
 * \param[in] freqInHz UART clock frequency
 *
 * \retval kSTATUS_SUCCESS Success to initialize UART
 * \retval kSTATUS_UART_BUSY A transmission is under processing
 * \retval kSTATUS_UART_DIVISOR_OVERRANGE Divisor is out of the accepted range
 * \retval kSTATUS_UART_UNSUPPORTED_BAUDRATE The baud rate is not supported
 */
status_t UART_RS485HD_init(UART_Type *base, UART_RS485_Config_t *config, uint32_t freqInHz);

/*!
 * \brief  UART RS485 Half Duplex Mode de-initialization
 *
 * \details De-initialize UART RS485 Half Duplex Mode
 *
 * \param[in] base UART base address
 *
 * \retval kSTATUS_SUCCESS Success to de-initialize UART
 * \retval kSTATUS_UART_BUSY A transmission is under processing
 */
status_t UART_RS485HD_deinit(UART_Type *base);

/*!
 * \brief Transmit data with blocking method
 *
 * \details This function checks if the transfer FIFO have space firstly, then writes data into the FIFO, and wait until
 * the transfer register to be empty which indicates the last byte has been transmitted successfully
 *
 * \param[in] base UART base address
 * \param[in] data The pointer to the data bytes
 * \param[in] length The byte count of the data to transfer
 *
 * \retval kSTATUS_SUCCESS Success to transmit data
 * \retval kSTATUS_TIMEOUT Transaction is timeout, and aborted
 */
static inline status_t UART_RS485HD_writeDataBlocking(UART_Type *base, const uint8_t *data, size_t length)
{
    return UART_writeDataBlocking(base, data, length);
}

/*!
 * \brief Receive data with blocking method
 *
 * \details Firstly this function checks if the receive FIFO have bytes received, then reads data from the FIFO, and
 * check if there is any error during the receive operation
 *
 * \param[in] base UART base address
 * \param[in] data The pointer to the data buffer
 * \param[in] length The byte count of the data to receive
 *
 * \retval kSTATUS_SUCCESS Success to receive data
 * \retval kSTATUS_TIMEOUT Transaction is timeout, and aborted
 * \retval kSTATUS_UART_OVERRUN_ERROR Data overrun error
 * \retval kSTATUS_UART_BREAK_DETECTED Break is detected
 * \retval kSTATUS_UART_PARITY_ERROR Parity error
 * \retval kSTATUS_UART_FRAMING_ERROR Framing error
 */
static inline status_t UART_RS485HD_readDataBlocking(UART_Type *base, uint8_t *data, size_t length)
{
    return UART_readDataBlocking(base, data, length);
}

/*!
 * \brief Write data without blocking method
 *
 * \details This function writes data into the FIFO
 *
 * \param[in] base UART base address
 * \param[in] data The pointer to the data buffer
 * \param[in] length The byte count of the data to receive
 *
 * \retval kSTATUS_SUCCESS Success to de-initialize UART
 * \retval kSTATUS_UART_TX_BUSY There is a TX transmission under going already. New transmit cannot be started
 * \retval kSTATUS_UART_RX_BUSY There is a RX transmission under going already. New transmit cannot be started
 */
status_t UART_RS485HD_writeDataNonBlocking(UART_Type *base, const uint8_t *data, size_t length);

/*!
 * \brief Receive data without blocking method
 *
 * \details Reads data from the FIFO, and check if there is any error during the receive operation
 *
 * \param[in] base UART base address
 * \param[in] data The pointer to the data buffer
 * \param[in] length The byte count of the data to receive
 *
 * \retval kSTATUS_SUCCESS Success to de-initialize UART
 * \retval kSTATUS_UART_RX_BUSY There is a RX transmission under going already. New receive cannot be started
 * \retval kSTATUS_UART_TX_BUSY There is a TX transmission under going already. New receive cannot be started
 */
status_t UART_RS485HD_readDataNonBlocking(UART_Type *base, uint8_t *data, size_t length);

/*!
 * \brief Abort the non-blocking(interrupt) data transmitting
 *
 * \details This function aborts the non-blocking data transmitting and disables relative UART interrupts
 *
 * \note The data bytes which have been filled into the FIFO or Transmit Holding Register will still be sent out after
 * This function is called
 *
 * \param[in] base UART base address
 */
static inline void UART_RS485HD_abortWriteDataNonBlocking(UART_Type *base)
{
    UART_abortWriteDataNonBlocking(base);
}

/*!
 * \brief Abort the non-blocking(interrupt) data receiving
 *
 * \details This function aborts the non-blocking data receiving and disables relative UART interrupts
 *
 * \note The data bytes which have been received but not read by software will be keep in the FIFO or Transmit Holding
 * Register
 *
 * \param[in] base UART base address
 */
static inline void UART_RS485HD_abortReadDataNonBlocking(UART_Type *base)
{
    UART_abortReadDataNonBlocking(base);
}

/*!
 * \brief Register user callback function to a specified UART for non-blocking transfer
 *
 * \details This function registers user callback function for non-blocking transfer which uses IRQ. The relative IRQ
 * will be enabled in the NVIC and the priority will be configured at the same time
 *
 * \param[in] base UART base address
 * \param[in] callback UART user callback
 * \param[in] priority IRQ priority
 *
 * \retval kSTATUS_SUCCESS Success to the operation
 * \retval kSTATUS_FAIL Register to a UART which has been registered already. Need to call \ref
 UART_unregisterCallback() before the re-registration
 */
static inline status_t UART_RS485HD_registerCallback(UART_Type *base, UART_Callback_t callback, uint32_t priority)
{
    return UART_registerCallback(base, callback, priority);
}

/*!
 * \brief Un-register user callback function to a specified UART for non-blocking transfer
 *
 * \details This function clears the registered user callback function, and disable the relative IRQ in the NVIC
 *
 * \param[in] base UART base address
 *
 * \retval kSTATUS_SUCCESS Success to the operation
 * \retval kSTATUS_FAIL The UART hasn't been registered to a callback
 * \retval kSTATUS_UART_TX_BUSY There is a transmit operation under going, need to wait it completed, or call \ref
 * UART_abortWriteDataNonBlocking() before un-register the callback
 * \retval kSTATUS_UART_RX_BUSY There is a receive operation under going, need to wait it completed, or call \ref
 * UART_abortReadDataNonBlocking() before un-register the callback
 */
static inline status_t UART_RS485HD_unregisterCallback(UART_Type *base)
{
    return UART_unregisterCallback(base);
}

/*!
 * @}
 */

/*!
 * \name UART RS485 Full Duplex(FD) Mode High-level APIs
 *
 * @{
 */

/*!
 * \brief UART RS485 Full Duplex Mode initialization
 *
 * \details Initialize UART RS485 Full Duplex Mode with the configuration
 *
 * \param[in] base UART base address
 * \param[in] config UART RS485 configuration
 * \param[in] freqInHz UART clock frequency
 *
 * \retval kSTATUS_SUCCESS Success to initialize UART
 * \retval kSTATUS_UART_BUSY A transmission is under processing
 * \retval kSTATUS_UART_DIVISOR_OVERRANGE Divisor is out of the accepted range
 * \retval kSTATUS_UART_UNSUPPORTED_BAUDRATE The baud rate is not supported
 */
status_t UART_RS485FD_init(UART_Type *base, UART_RS485_Config_t *config, uint32_t freqInHz);

/*!
 * \brief  UART RS485 Full Duplex Mode de-initialization
 *
 * \details De-initialize UART RS485 Full Duplex Mode
 *
 * \param[in] base UART base address
 *
 * \retval kSTATUS_SUCCESS Success to de-initialize UART
 * \retval kSTATUS_UART_BUSY A transmission is under processing
 */
static inline status_t UART_RS485FD_deinit(UART_Type *base)
{
    return UART_RS485HD_deinit(base);
}

/*!
 * \brief Transmit data with blocking method
 *
 * \details This function checks if the transfer FIFO have space firstly, then writes data into the FIFO, and wait until
 * the transfer register to be empty which indicates the last byte has been transmitted successfully
 *
 * \param[in] base UART base address
 * \param[in] data The pointer to the data bytes
 * \param[in] length The byte count of the data to transfer
 *
 * \retval kSTATUS_SUCCESS Success to transmit data
 * \retval kSTATUS_TIMEOUT Transaction is timeout, and aborted
 */
static inline status_t UART_RS485FD_writeDataBlocking(UART_Type *base, const uint8_t *data, size_t length)
{
    status_t status;

    UART_setDE(base, true);
    status = UART_writeDataBlocking(base, data, length);
    UART_setDE(base, false);

    return status;
}

/*!
 * \brief Receive data with blocking method
 *
 * \details Firstly this function checks if the receive FIFO have bytes received, then reads data from the FIFO, and
 * check if there is any error during the receive operation
 *
 * \param[in] base UART base address
 * \param[in] data The pointer to the data buffer
 * \param[in] length The byte count of the data to receive
 *
 * \retval kSTATUS_SUCCESS Success to receive data
 * \retval kSTATUS_TIMEOUT Transaction is timeout, and aborted
 * \retval kSTATUS_UART_OVERRUN_ERROR Data overrun error
 * \retval kSTATUS_UART_BREAK_DETECTED Break is detected
 * \retval kSTATUS_UART_PARITY_ERROR Parity error
 * \retval kSTATUS_UART_FRAMING_ERROR Framing error
 */
static inline status_t UART_RS485FD_readDataBlocking(UART_Type *base, uint8_t *data, size_t length)
{
    status_t status;

    UART_setRE(base, true);
    status = UART_readDataBlocking(base, data, length);
    UART_setRE(base, false);

    return status;
}

/*!
 * \brief Write data without blocking method
 *
 * \details This function writes data into the FIFO
 *
 * \param[in] base UART base address
 * \param[in] data The pointer to the data buffer
 * \param[in] length The byte count of the data to receive
 *
 * \retval kSTATUS_SUCCESS Success to de-initialize UART
 * \retval kSTATUS_UART_TX_BUSY There is a TX transmission under going already. New transmit cannot be started
 */
static inline status_t UART_RS485FD_writeDataNonBlocking(UART_Type *base, const uint8_t *data, size_t length)
{
    return UART_writeDataNonBlocking(base, data, length);
}

/*!
 * \brief Receive data without blocking method
 *
 * \details Reads data from the FIFO, and check if there is any error during the receive operation
 *
 * \param[in] base UART base address
 * \param[in] data The pointer to the data buffer
 * \param[in] length The byte count of the data to receive
 *
 * \retval kSTATUS_SUCCESS Success to de-initialize UART
 * \retval kSTATUS_UART_RX_BUSY There is a RX transmission under going already. New receive cannot be started
 */
static inline status_t UART_RS485FD_readDataNonBlocking(UART_Type *base, uint8_t *data, size_t length)
{
    status_t status = UART_readDataNonBlocking(base, data, length);
    /* Enable RE to allow the RX transmission */
    UART_setRE(base, true);
    return status;
}

/*!
 * \brief Abort the non-blocking(interrupt) data transmitting
 *
 * \details This function aborts the non-blocking data transmitting and disables relative UART interrupts
 *
 * \note The data bytes which have been filled into the FIFO or Transmit Holding Register will still be sent out after
 * This function is called
 *
 * \param[in] base UART base address
 */
static inline void UART_RS485FD_abortWriteDataNonBlocking(UART_Type *base)
{
    /* Keep DE enable, otherwise, the data bytes in FIFO or Transmit Holding Register will be stuck and sent out by
     * the next transmit */
    /* UART_setDE(base, false); */
    UART_abortWriteDataNonBlocking(base);
}

/*!
 * \brief Abort the non-blocking(interrupt) data receiving
 *
 * \details This function aborts the non-blocking data receiving and disables relative UART interrupts
 *
 * \note The data bytes which have been received but not read by software will be keep in the FIFO or Transmit Holding
 * Register
 *
 * \param[in] base UART base address
 */
static inline void UART_RS485FD_abortReadDataNonBlocking(UART_Type *base)
{
    /* Disable RE */
    UART_setRE(base, false);
    UART_abortReadDataNonBlocking(base);
}

/*!
 * \brief Register user callback function to a specified UART for non-blocking transfer
 *
 * \details This function registers user callback function for non-blocking transfer which uses IRQ. The relative IRQ
 * will be enabled in the NVIC and the priority will be configured at the same time
 *
 * \param[in] base UART base address
 * \param[in] callback UART user callback
 * \param[in] priority IRQ priority
 *
 * \retval kSTATUS_SUCCESS Success to the operation
 * \retval kSTATUS_FAIL Register to a UART which has been registered already. Need to call \ref
 UART_unregisterCallback() before the re-registration
 */
status_t UART_RS485FD_registerCallback(UART_Type *base, UART_Callback_t callback, uint32_t priority);

/*!
 * \brief Unregister user callback function to a specified UART for non-blocking transfer
 *
 * \details This function clears the registered user callback function, and disable the relative IRQ in the NVIC
 *
 * \param[in] base UART base address
 *
 * \retval kSTATUS_SUCCESS Success to the operation
 * \retval kSTATUS_FAIL The UART hasn't been registered to a callback
 * \retval kSTATUS_UART_TX_BUSY There is a transmit operation under going, need to wait it completed, or call \ref
 * UART_abortWriteDataNonBlocking() before un-register the callback
 * \retval kSTATUS_UART_RX_BUSY There is a receive operation under going, need to wait it completed, or call \ref
 * UART_abortReadDataNonBlocking() before un-register the callback
 */
static inline status_t UART_RS485FD_unregisterCallback(UART_Type *base)
{
    return UART_unregisterCallback(base);
}

/*!
 * @}
 */

/*!
 * \name UART test mode APIs
 *
 * @{
 */

/*!
 * \brief Enable UART LoopBack test mode
 *
 * \details This function enables the UART LoopBack test mode at which the serial data output is looped back to the data
 * input
 *
 * \note This function is only used for test purpose. Please DO NOT enable it for real operations
 *
 * \param[in] base UART base address
 */
static inline void UART_enableLoopback(UART_Type *base)
{
    assert(base);
    base->MCR |= UART_MCR_LOOP_BACK_Msk;
}

/*!
 * \brief Disable UART LoopBack test mode
 *
 * \details This function disables the UART LoopBack test mode, so the serial data output will not be looped back to the
 * data input
 *
 * \param[in] base UART base address
 */
static inline void UART_disableLoopback(UART_Type *base)
{
    assert(base);
    base->MCR &= ~UART_MCR_LOOP_BACK_Msk;
}

/*!
 * \brief Enable UART FIFO access mode
 *
 * \details This function enables UART FIFO access mode which allows software to read the TX FIFO and write the RX FIFO
 *
 * \note This function is only used for test purpose. Please DO NOT enable it for real operations
 *
 * \param[in] base UART base address
 */
static inline void UART_enableFIFOAccess(UART_Type *base)
{
    assert(base);
    base->FAR |= UART_FAR_FAR_Msk;
}

/*!
 * \brief Disable UART FIFO access mode
 *
 * \details This function disables UART FIFO access mode, so software cannot read the TX FIFO and write the RX FIFO
 *
 * \param[in] base UART base address
 */
static inline void UART_disableFIFOAccess(UART_Type *base)
{
    assert(base);
    base->FAR &= ~UART_FAR_FAR_Msk;
}

/*!
 * \brief Read the UART TX FIFO or the Transmit Holding Register
 *
 * \details This function returns the data at the top of the UART TX FIFO. If the FIFO is not enabled, reading gives the
 * data in the Transmit Holding Register
 *
 * \note This function can return valid data only FIFO access mode is enabled by \ref UART_enableFIFOAccess()
 *
 * \param[in] base UART base address
 *
 * \return Return the data at the top of the TX FIFO
 */
static inline uint8_t UART_readTxFIFO(UART_Type *base)
{
    assert(base);
    return UART_TFR_TFR_Get(base->TFR);
}

/*!
 * \brief Write the UART RX FIFO or the Receive Buffer Register
 *
 * \details This function writes a data byte into UART TX FIFO. If the FIFO is not enabled, the data writes into the
 * Receive Buffer Register
 *
 * \note This function can take effect only when FIFO access mode is enabled by \ref UART_enableFIFOAccess()
 *
 * \param[in] base UART base address
 * \param[in] byte The data to be written into TX FIFO
 */
static inline void UART_writeRxFIFO(UART_Type *base, uint8_t byte)
{
    assert(base);
    base->RFW = byte;
}

/*!
 * \brief Write a parity error into the UART RX FIFO or the Receive Buffer Register
 *
 * \details This function writes a parity error into UART TX FIFO. If the FIFO is not enabled, the parity error writes
 * into the Receive Buffer Register
 *
 * \note This function can take effect only when FIFO access mode is enabled by \ref UART_enableFIFOAccess()
 *
 * \param[in] base UART base address
 */
static inline void UART_triggerParityError(UART_Type *base)
{
    assert(base);
    base->RFW |= UART_RFW_RFPE_Msk;
}

/*!
 * \brief Write a frame error into the UART RX FIFO or the Receive Buffer Register
 *
 * \details This function writes a frame error into UART TX FIFO. If the FIFO is not enabled, the frame error writes
 * into the Receive Buffer Register
 *
 * \note This function can take effect only when FIFO access mode is enabled by \ref UART_enableFIFOAccess()
 *
 * \param[in] base UART base address
 */
static inline void UART_triggerFrameError(UART_Type *base)
{
    assert(base);
    base->RFW |= UART_RFW_RFFE_Msk;
}

/*!
 * \brief Halt transmission for test propose
 *
 * \details This function halts transmission for test propose, so that the TX FIFO can be filled by the master.
 *
 * \note This function will have no effect if FIFOs are not enabled.
 *
 * \param[in] base UART base address
 * \param[in] enable Halt or resume the transmission
 *                   - true: Halt
 *                   - false: Resume
 */
static inline void UART_haltTransmit(UART_Type *base, bool enable)
{
    assert(base);
    if (enable)
    {
        base->HTX |= UART_HTX_HTX_Msk;
    }
    else
    {
        base->HTX &= ~UART_HTX_HTX_Msk;
    }
}

/*!
 * @}
 */

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */ /* end of DRV_HTE_UART */

#endif /* HTE_UART_H */
