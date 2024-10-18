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

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* No Definitions */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/* No Prototypes */

/*******************************************************************************
 * Variables
 ******************************************************************************/
/* No Variables */

/*******************************************************************************
 * Codes
 ******************************************************************************/
int main(void)
{
    uint8_t ch = 0;

    /* Board initialization */
    BOARD_init();

    /* Print the example banner */
    PRINTF("\r\n");
    PRINTF("Hello World Example:\r\n");
    PRINTF("\tDevice will send the received characters back\r\n");
    PRINTF("Please input:");

    while (1)
    {
        ch = GETCHAR();
        PUTCHAR(ch);
    }
}
