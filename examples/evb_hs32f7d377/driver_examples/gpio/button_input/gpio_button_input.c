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
/*! \brief BUTTON instance used by CPU1 in this example */
#define EXAMPLE_BUTTON_INSTANCE_CPU1 (0U)
/*! \brief GPIO used by CPU1 to control the BUTTON in this example */
#define EXAMPLE_BUTTON_GPIO_CPU1 (BOARD_GPIO_BUTTON0)
/*! \brief XINT used by CPU1 to catch button input in this example */
#define EXAMPLE_BUTTON_XIN_CPU1 (kGPIO_XINT1)
/*! \brief XINT interrupt number used by CPU1 to catch button input */
#define EXAMPLE_BUTTON_IRQ_CPU1 (XINT1_IRQn)
/*! \brief XINT interrupt handler used by CPU1 to catch button input */
#define EXAMPLE_BUTTON_IRQHandler_CPU1 XINT1_Handler

/*! \brief BUTTON instance used by CPU2 in this example */
#define EXAMPLE_BUTTON_INSTANCE_CPU2 (1U)
/*! \brief GPIO used by CPU2 to control the BUTTON in this example */
#define EXAMPLE_BUTTON_GPIO_CPU2 (BOARD_GPIO_BUTTON1)
/*! \brief XINT used by CPU2 to catch button input in this example*/
#define EXAMPLE_BUTTON_XIN_CPU2 (kGPIO_XINT2)
/*! \brief XINT interrupt number used by CPU2 to catch button input */
#define EXAMPLE_BUTTON_IRQ_CPU2 (XINT2_IRQn)
/*! \brief XINT interrupt handler used by CPU2 to catch button input */
#define EXAMPLE_BUTTON_IRQHandler_CPU2 XINT2_Handler


#if defined(BOARD_USE_CPU1)
/*! \brief GPIO used to control the BUTTON in this example */
#define EXAMPLE_BUTTON_GPIO EXAMPLE_BUTTON_GPIO_CPU1
/*! \brief XINT used to catch button input in this example*/
#define EXAMPLE_BUTTON_XIN EXAMPLE_BUTTON_XIN_CPU1
/*! \brief XINT interrupt number used to catch button input */
#define EXAMPLE_BUTTON_IRQ EXAMPLE_BUTTON_IRQ_CPU1
/*! \brief XINT interrupt handler used to catch button input */
#define EXAMPLE_BUTTON_IRQHandler EXAMPLE_BUTTON_IRQHandler_CPU1
#else
/*! \brief GPIO used to control the BUTTON in this example */
#define EXAMPLE_BUTTON_GPIO       EXAMPLE_BUTTON_GPIO_CPU2
/*! \brief XINT used to catch button input in this example*/
#define EXAMPLE_BUTTON_XIN        EXAMPLE_BUTTON_XIN_CPU2
/*! \brief XINT interrupt number used to catch button input */
#define EXAMPLE_BUTTON_IRQ        EXAMPLE_BUTTON_IRQ_CPU2
/*! \brief XINT interrupt handler used to catch button input */
#define EXAMPLE_BUTTON_IRQHandler EXAMPLE_BUTTON_IRQHandler_CPU2
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * \brief Button input interrupt handler
 */
void EXAMPLE_BUTTON_IRQHandler(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! \brief The variable show whether the button is pressed */
static volatile bool s_buttonPressed = false;

/*******************************************************************************
 * Codes
 ******************************************************************************/
int main(void)
{
    /* Board initialization */
    BOARD_init();

    /* Pinmux configuration and Pad configuration */
#if defined(BOARD_USE_CPU1)
    BOARD_buttonPinConfig(EXAMPLE_BUTTON_INSTANCE_CPU1);
    /* Configure button GPIO as input */
    GPIO_setDirectionMode(EXAMPLE_BUTTON_GPIO_CPU1, kGPIO_DIR_INPUT);
    /* Configure Qualification mode to bypass noises */
    GPIO_setQualificationMode(EXAMPLE_BUTTON_GPIO_CPU1, kGPIO_QUAL_6SAMPLE);
    GPIO_setQualificationPeriod(EXAMPLE_BUTTON_GPIO_CPU1, 100000U);
    /* Configure button GPIO to trigger the selected interrupt */
    GPIO_setInterruptPin(EXAMPLE_BUTTON_GPIO_CPU1, EXAMPLE_BUTTON_XIN_CPU1);
#endif
#if BOARD_CONFIG_CPU2
    BOARD_buttonPinConfig(EXAMPLE_BUTTON_INSTANCE_CPU2);
    /* Configure button GPIO as input */
    GPIO_setDirectionMode(EXAMPLE_BUTTON_GPIO_CPU2, kGPIO_DIR_INPUT);
    /* Configure Qualification mode to bypass noises */
    GPIO_setQualificationMode(EXAMPLE_BUTTON_GPIO_CPU2, kGPIO_QUAL_6SAMPLE);
    GPIO_setQualificationPeriod(EXAMPLE_BUTTON_GPIO_CPU2, 100000U);
    /* Configure button GPIO to trigger the selected interrupt */
    GPIO_setInterruptPin(EXAMPLE_BUTTON_GPIO_CPU2, EXAMPLE_BUTTON_XIN_CPU2);
    /* Assign button GPIO to CPU2 */
    GPIO_setMasterCore(EXAMPLE_BUTTON_GPIO_CPU2, kGPIO_CORE_CPU2);
#endif

    /* Configure the trigger type of the selected interrupt */
    GPIO_setInterruptType(EXAMPLE_BUTTON_XIN, (BOARD_GPIO_BUTTON_ACTIVE_POLARITY == kBOARD_GPIO_ACTIVE_LOW)
                                                  ? kGPIO_INT_TYPE_FALLING_EDGE
                                                  : kGPIO_INT_TYPE_RISING_EDGE);

    /* Enable the selected interrupt */
    GPIO_enableInterrupt(EXAMPLE_BUTTON_XIN);
    NVIC_EnableIRQ(EXAMPLE_BUTTON_IRQ);

    /* Print the example banner */
    PRINTF("\r\n");
    PRINTF("GPIO Button Input Example:\r\n");
    PRINTF("\tPress the button, a string will be printed here\r\n");
    PRINTF("Please press the button:\r\n");

    while (1)
    {
        if (s_buttonPressed)
        {
            PRINTF("\tBUTTON is pressed\r\n");
            s_buttonPressed = false;
        }
    }
}

void EXAMPLE_BUTTON_IRQHandler(void)
{
    s_buttonPressed = true;
    GPIO_clearInterruptFlag(EXAMPLE_BUTTON_XIN);
    ISR_EXIT_BARRIER();
}
