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

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/* No Prototypes */

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! \brief UART example banner string */
const uint8_t s_uartExampleString[] = "\r\n"
                                      "UART RS485 Half Duplex Polling Example:\r\n"
                                      "\tDevice will send each received character back\r\n"
                                      "Please input:";

/*******************************************************************************
 * Codes
 ******************************************************************************/
int main(void)
{
    uint8_t ch = 0;

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

    /* Send the example banner */
    (void)UART_RS485HD_writeDataBlocking(EXAMPLE_UART, s_uartExampleString, sizeof(s_uartExampleString));

    while (1)
    {
        (void)UART_RS485HD_readDataBlocking(EXAMPLE_UART, &ch, sizeof(ch));
        (void)UART_RS485HD_writeDataBlocking(EXAMPLE_UART, &ch, sizeof(ch));
    }
}
