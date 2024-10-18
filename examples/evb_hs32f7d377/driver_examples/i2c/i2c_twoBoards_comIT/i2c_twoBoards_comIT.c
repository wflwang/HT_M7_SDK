/*
 * Copyright 2023 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*!
 * \file i2c_twoBoards_comIT.c
 * \brief I2C example file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "board.h"
#include "hte_gpio.h"
#include "hte_i2c.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! \brief I2C used by CPU1 in this example */
#define EXAMPLE_I2C_CPU1     (I2CA)
#define EXAMPLE_I2C_IDX_CPU1 (kI2C_INDEX_A)
/*! \brief I2C used by CPU2 in this example */
#define EXAMPLE_I2C_CPU2     (I2CB)
#define EXAMPLE_I2C_IDX_CPU2 (kI2C_INDEX_B)

/*! \brief I2C used in this example */
#if defined(BOARD_USE_CPU1)
#define EXAMPLE_I2C     EXAMPLE_I2C_CPU1
#define EXAMPLE_I2C_IDX EXAMPLE_I2C_IDX_CPU1
#elif defined(BOARD_USE_CPU2)
#define EXAMPLE_I2C     EXAMPLE_I2C_CPU2
#define EXAMPLE_I2C_IDX EXAMPLE_I2C_IDX_CPU2
#endif

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
#define aTxBuffer        aTxBuffer1
#define aRxBuffer        aRxBuffer1
#else
#define EXAMPLE_LED_GPIO EXAMPLE_LED_GPIO_CPU2
#define aTxBuffer        aTxBuffer2
#define aRxBuffer        aRxBuffer2
#endif


/*! \brief Size of Transmission buffer */
#define TXBUFFERSIZE (ARRAY_SIZE(aTxBuffer) - 1)
/*! \brief Size of Reception buffer */
#define RXBUFFERSIZE TXBUFFERSIZE
/*! \brief I2C target address */
#define I2C_TARGET_ADDRESS 0x51
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/* No Prototypes */

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! \brief Pointer to I2C handle */
I2C_Handle_t *pi2cHandle;
/*! \brief Buffer used by CPU1 for transmission */
uint8_t aTxBuffer1[] = " ****I2C TwoBoards communication based on IT running on CPU1**** ";
/*! \brief Buffer used by CPU2 for transmission */
uint8_t aTxBuffer2[] = " ****I2C TwoBoards communication based on IT running on CPU2**** ";
/*! \brief Buffer used by CPU1 for reception */
uint8_t aRxBuffer1[RXBUFFERSIZE];
/*! \brief Buffer used by CPU2 for reception */
uint8_t aRxBuffer2[RXBUFFERSIZE];

/*******************************************************************************
 * Codes
 ******************************************************************************/

static void Error_Handler(void)
{
    while (1)
    {
        GPIO_togglePin(EXAMPLE_LED_GPIO);
        DELAY(100000);
    }
}

static uint16_t Buffercmp(uint8_t *pBuffer1, uint8_t *pBuffer2, uint16_t BufferLength)
{
    while (BufferLength--)
    {
        if ((*pBuffer1) != *pBuffer2)
        {
            return BufferLength;
        }
        pBuffer1++;
        pBuffer2++;
    }

    return 0;
}

int main(void)
{
    PRINTF("I2C Example:\r\n");
    /* Board initialization */
    BOARD_init();

    /* Pinmux configuration and Pad configuration */
#if defined(BOARD_USE_CPU1)
    BOARD_i2cPinConfig(EXAMPLE_I2C_CPU1);
    BOARD_ledPinConfig(EXAMPLE_LED_INSTANCE_CPU1);
    /* Configure LED GPIO as output */
    GPIO_setDirectionMode(EXAMPLE_LED_GPIO_CPU1, kGPIO_DIR_OUTPUT);
#endif
#if defined(BOARD_CONFIG_CPU2)
    BOARD_i2cPinConfig(EXAMPLE_I2C_CPU2);
    BOARD_i2cAssign2CPU2(EXAMPLE_I2C_CPU2);
    BOARD_ledPinConfig(EXAMPLE_LED_INSTANCE_CPU2);
    /* Configure LED GPIO as output */
    GPIO_setDirectionMode(EXAMPLE_LED_GPIO_CPU2, kGPIO_DIR_OUTPUT);
    /* Assign LED GPIO to CPU2 */
    GPIO_setMasterCore(EXAMPLE_LED_GPIO_CPU2, kGPIO_CORE_CPU2);
#endif

    GPIO_writePin(EXAMPLE_LED_GPIO, 1);

    BOARD_i2cClockEnable(EXAMPLE_I2C);

    NVIC_SetPriority(I2CA_IRQn, 5);
    NVIC_EnableIRQ(I2CA_IRQn);
    NVIC_SetPriority(I2CB_IRQn, 5);
    NVIC_EnableIRQ(I2CB_IRQn);

    /* Configure the I2C peripheral */
    pi2cHandle                     = I2C_getHandle(EXAMPLE_I2C_IDX);
    pi2cHandle->instance           = EXAMPLE_I2C;
    pi2cHandle->init.addrMode      = kI2C_ADDR_MODE_7BITS;
    pi2cHandle->init.speedMode     = kI2C_STANDARD_SPEED_MODE;
    pi2cHandle->init.hcnt          = I2C_STANDARD_HCNT;
    pi2cHandle->init.lcnt          = I2C_STANDARD_LCNT;
    pi2cHandle->init.sdaRxHold     = 0x0;
    pi2cHandle->init.sdaTxHold     = 0x0;
    pi2cHandle->init.sdaSetup      = 0x64;
    pi2cHandle->init.noSdaRecovery = false;
    pi2cHandle->init.sdaTimeout    = 0xFFFFFFFF;
    pi2cHandle->init.sclTimeout    = 0xFFFFFFFF;
    pi2cHandle->init.slaveAddr     = I2C_TARGET_ADDRESS;
#ifdef MASTER_BOARD

    pi2cHandle->mode       = kI2C_MASTER_MODE;
    pi2cHandle->targetAddr = I2C_TARGET_ADDRESS;
    if (I2C_initMaster(pi2cHandle) != kSTATUS_I2C_OK)
    {
        /* Processing Error */
        Error_Handler();
    }

    do
    {
        /* Put I2C peripheral in transmission process */
        if (I2C_masterTransmitIT(pi2cHandle, aTxBuffer, TXBUFFERSIZE) != kSTATUS_I2C_OK)
        {
            /* Processing Error */
            Error_Handler();
        }
        /* Wait for the end of the transfer */
        while (pi2cHandle->state != kI2C_READY)
        {
        }
    } while (pi2cHandle->errorCode != kI2C_NO_ABRT);

    /* Turn LED2 on: Transfer in transmission process is correct */
    GPIO_writePin(EXAMPLE_LED_GPIO, 0);
    DELAY(10000);

    do
    {
        /* Put I2C peripheral in reception process */
        if (I2C_masterReceiveIT(pi2cHandle, aRxBuffer, RXBUFFERSIZE) != kSTATUS_I2C_OK)
        {
            /* Processing Error */
            Error_Handler();
        }

        /* Wait for the end of the transfer */
        while (pi2cHandle->state != kI2C_READY)
        {
        }
    } while (pi2cHandle->errorCode != kI2C_NO_ABRT);

#else

    pi2cHandle->mode = kI2C_SLAVE_MODE;
    if (I2C_initSlave(pi2cHandle) != kSTATUS_I2C_OK)
    {
        /* Processing Error */
        Error_Handler();
    }
    /* The board receives the message and sends it back */

    /* Put I2C peripheral in reception process */
    if (I2C_slaveReceiveIT(pi2cHandle, (uint8_t *)aRxBuffer, RXBUFFERSIZE) != kSTATUS_I2C_OK)
    {
        /* Transfer error in reception process */
        Error_Handler();
    }

    /* Wait for the end of the transfer */
    while (pi2cHandle->state != kI2C_READY)
    {
    }

    /* Turn LED2 on: Transfer in reception process is correct */
    GPIO_writePin(EXAMPLE_LED_GPIO, 0);
    DELAY(10000);

    /* Start the transmission process */
    if (I2C_slaveTransmitIT(pi2cHandle, (uint8_t *)aTxBuffer, TXBUFFERSIZE) != kSTATUS_I2C_OK)
    {
        /* Transfer error in transmission process */
        Error_Handler();
    }

#endif /* MASTER_BOARD */

    /* Turn LED2 off: Transfer is correct */
    GPIO_writePin(EXAMPLE_LED_GPIO, 1);

    /* Compare the sent and received buffers */
    if (Buffercmp((uint8_t *)aTxBuffer, (uint8_t *)aRxBuffer, RXBUFFERSIZE))
    {
        /* Processing Error */
        Error_Handler();
    }
    /* Infinite loop */
    while (1)
    {
    }
}
