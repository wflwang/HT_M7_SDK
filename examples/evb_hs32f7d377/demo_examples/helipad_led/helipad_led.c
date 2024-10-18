/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*!
 * \file helipad.c
 * \brief Example of SDK debug console
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "board.h"
#include "hte_gpio.h"
#include "hte_pinmux.h"

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
    uint32_t pin[2], pinConfig[2];

    /* Board initialization */
    BOARD_init();

    /* Init GPIO */
    pin[0]       = 28;
    pinConfig[0] = GPIO_28_GPIO28;
    pin[1]       = 31;
    pinConfig[1] = GPIO_31_GPIO31;

    for (uint8_t i = 0; i < 2; i++)
    {
        GPIO_setPinConfig(pinConfig[i]);
        GPIO_setQualificationMode(pin[i], kGPIO_QUAL_ASYNC);
        GPIO_setDirectionMode(pin[i], kGPIO_DIR_OUTPUT);
        GPIO_setPadConfig(pin[i], kGPIO_PADCONFIG_STD);
    }

    while (1)
    {
        GPIO_writePin(pin[0], 1);
        GPIO_writePin(pin[1], 0);
        DELAY(1000000);
        GPIO_writePin(pin[0], 0);
        GPIO_writePin(pin[1], 1);
        DELAY(1000000);
    }
}
