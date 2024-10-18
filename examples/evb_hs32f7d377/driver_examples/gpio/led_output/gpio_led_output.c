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
#include "hte_gpio.h"
#include "hte_pinmux.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! \brief LED instance used by CPU1 in this example */
#define EXAMPLE_LED_INSTANCE_CPU1 (1U)
/*! \brief GPIO used by CPU1 to control the LED in this example */
#define EXAMPLE_LED_GPIO_CPU1 (BOARD_GPIO_LED1)
/*! \brief LED instance used by CPU2 in this example */
#define EXAMPLE_LED_INSTANCE_CPU2 (2U)
/*! \brief GPIO used by CPU2 to control the LED in this example */
#define EXAMPLE_LED_GPIO_CPU2 (BOARD_GPIO_LED2)

/*! \brief GPIO used to control the LED in this example */
#if defined(BOARD_USE_CPU1)
#define EXAMPLE_LED_GPIO EXAMPLE_LED_GPIO_CPU1
#else
#define EXAMPLE_LED_GPIO EXAMPLE_LED_GPIO_CPU2
#endif

/*! \brief Example code uses toggle register to toggle the led */
#define EXAMPLE_LED_GPIO_USE_TOGGLE (0U)

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
    /* Board initialization */
    BOARD_init();

    /* Pinmux configuration and Pad configuration */
#if defined(BOARD_USE_CPU1)
    BOARD_ledPinConfig(EXAMPLE_LED_INSTANCE_CPU1);
    /* Configure LED GPIO as output */
    GPIO_setDirectionMode(EXAMPLE_LED_GPIO_CPU1, kGPIO_DIR_OUTPUT);
#endif
#if BOARD_CONFIG_CPU2
    BOARD_ledPinConfig(EXAMPLE_LED_INSTANCE_CPU2);
    /* Configure LED GPIO as output */
    GPIO_setDirectionMode(EXAMPLE_LED_GPIO_CPU2, kGPIO_DIR_OUTPUT);
    /* Assign LED GPIO to CPU2 */
    GPIO_setMasterCore(EXAMPLE_LED_GPIO_CPU2, kGPIO_CORE_CPU2);
#endif

    /* Print the example banner */
    PRINTF("\r\n");
    PRINTF("GPIO LED Output Example:\r\n");
    PRINTF("\tLED starts blinking......\r\n");

    while (1)
    {
#if EXAMPLE_LED_GPIO_USE_TOGGLE
        GPIO_togglePin(EXAMPLE_LED_GPIO);
#else
        uint32_t data = GPIO_readPin(EXAMPLE_LED_GPIO);
        GPIO_writePin(EXAMPLE_LED_GPIO, !data);
#endif
        /* Delay 1s */
        DELAY(1000000);
    }
}
