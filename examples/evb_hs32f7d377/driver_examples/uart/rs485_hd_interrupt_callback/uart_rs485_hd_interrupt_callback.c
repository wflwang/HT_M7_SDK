/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*!
 * \file hello_world.c
 * \brief Example of SDK debug console
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "board.h"
#include "hte_uart.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! \brief UART used by CPU1 in this example */
#define EXAMPLE_UART_CPU1 (UARTA)
/*! \brief UART used by CPU2 in this example */
#define EXAMPLE_UART_CPU2 (UARTB)

/*! \brief UART used in this example */
#if defined(BOARD_USE_CPU1)
#define EXAMPLE_UART EXAMPLE_UART_CPU1
#elif defined(BOARD_USE_CPU2)
#define EXAMPLE_UART EXAMPLE_UART_CPU2
#endif

/*! \brief UART baudrate used in this example */
#define EXAMPLE_UART_BAUDRATE (115200U)
/*! \brief Clock of the UART used in this example */
#define EXAMPLE_UART_CLOCK BOARD_DEBUG_CONSOLE_CLOCK
/*! \brief Example transfer length */
#define EXAMPLE_TRANSFER_LENGTH (32U)

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*! \brief Example user callback to handle data transmission */
static void UART_userCallback(UART_Type *base, UART_Handle_t *handle, status_t status);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! \brief UART example banner string */
const uint8_t s_uartExampleString[] = "\r\n"
                                      "UART RS485 Half Duplex Interrupt Callback Example:\r\n"
                                      "\tDevice will send every 32 received characters back\r\n"
                                      "Please input:";
/*! \brief Buffer to store TX data bytes */
static uint8_t s_txBuffer[EXAMPLE_TRANSFER_LENGTH] = { 0 };
/*! \brief TX buffer status */
volatile bool s_txBufferFull = false;
/*! \brief Buffer to store RX data bytes */
static uint8_t s_rxBuffer[EXAMPLE_TRANSFER_LENGTH] = { 0 };
/*! \brief RX buffer status */
volatile bool s_rxBufferFull = false;
/*! \brief Flag to show if there is a transmission under processing */
volatile bool s_transOnGoing = false;

/*******************************************************************************
 * Codes
 ******************************************************************************/
int main(void)
{
    /* Board initialization */
    /*
     * Note: In BOARD_init(), UARTA and UARTB is initialized for debug_console for CPU1 and CPU2.
     *       If the example uses the same UART, UART will be re-initialized in this example.
     */
    BOARD_init();

    /* Pinmux configuration and Pad configuration */
#if defined(BOARD_USE_CPU1)
    BOARD_uartPinConfig(EXAMPLE_UART_CPU1);
#endif
#if defined(BOARD_CONFIG_CPU2)
    BOARD_uartPinConfig(EXAMPLE_UART_CPU2);
    BOARD_uartAssign2CPU2(EXAMPLE_UART_CPU2);
#endif

    /* Peripheral clock configuration */
    BOARD_uartClockEnable(EXAMPLE_UART);

    UART_RS485_Config_t config = { 0 };
    UART_RS485_getDefaultConfig(&config);
    config.config.baudRate = EXAMPLE_UART_BAUDRATE;

    (void)UART_RS485HD_init(EXAMPLE_UART, &config, EXAMPLE_UART_CLOCK);
    (void)UART_RS485HD_registerCallback(EXAMPLE_UART, UART_userCallback, 0U);

    /* Send the example banner */
    (void)UART_RS485HD_writeDataNonBlocking(EXAMPLE_UART, s_uartExampleString, sizeof(s_uartExampleString));
    s_transOnGoing = true;

    while (1)
    {
        if ((!s_transOnGoing) && (!s_rxBufferFull))
        {
            (void)UART_RS485HD_readDataNonBlocking(EXAMPLE_UART, s_rxBuffer, sizeof(s_rxBuffer));
            s_transOnGoing = true;
        }
        if ((s_rxBufferFull) && (!s_txBufferFull))
        {
            memcpy(s_txBuffer, s_rxBuffer, EXAMPLE_TRANSFER_LENGTH);
            s_rxBufferFull = false;
            s_txBufferFull = true;
        }
        if ((!s_transOnGoing) && (s_txBufferFull))
        {
            (void)UART_RS485HD_writeDataNonBlocking(EXAMPLE_UART, s_txBuffer, sizeof(s_txBuffer));
            s_transOnGoing = true;
        }
    }
}

static void UART_userCallback(UART_Type *base, UART_Handle_t *handle, status_t status)
{
    if (status == kSTATUS_UART_RX_IDLE)
    {
        s_transOnGoing = false;
        s_rxBufferFull = true;
    }
    else if (status == kSTATUS_UART_TX_IDLE)
    {
        s_transOnGoing = false;
        s_txBufferFull = false;
    }
}
