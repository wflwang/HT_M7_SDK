/*
 * Copyright 2023 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*!
 * \file smbus_twoBoards_alert.c
 * \brief SMBUS example file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "board.h"
#include "hte_gpio.h"
#include "hte_smbus.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! \brief SMBUS own address */
#define SMBUS_ADDRESS 0x51
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/* No Prototypes */

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! \brief Pointer to SMBUS handle */
SMBUS_Handle_t *psmbusHandle;
/*! \brief SMBUS RX buffer */
uint8_t         buff[32];

/*******************************************************************************
 * Codes
 ******************************************************************************/
#if !defined(BOARD_CONFIG_CPU2)
static void Error_Handler(void)
{
    while (1)
    {
        GPIO_togglePin(BOARD_GPIO_LED0);
        DELAY(100000);
    }
}
#endif

int main(void)
{
    /* Board initialization */
    BOARD_init();

#if defined(BOARD_CONFIG_CPU2)
    /* Pinmux configuration and Pad configuration */
    BOARD_ledPinConfig(0U);
    /* Configure LED GPIO as output */
    GPIO_setDirectionMode(BOARD_GPIO_LED0, kGPIO_DIR_OUTPUT);

    BOARD_pmbusPinConfig(PMBUSA);
    /* Assign PMBUSA to CPU2 */
    BOARD_pmbusAssign2CPU2(PMBUSA);
    /* Assign LED GPIO to CPU2 */
    GPIO_setMasterCore(BOARD_GPIO_LED0, kGPIO_CORE_CPU2);
#else

    GPIO_writePin(BOARD_GPIO_LED0, 1);
    BOARD_pmbusClockEnable(PMBUSA);

    /* Configure the I2C peripheral */
    psmbusHandle                          = SMBUS_getHandle();
    psmbusHandle->hi2c.instance           = PMBUSA;
    psmbusHandle->hi2c.init.addrMode      = kI2C_ADDR_MODE_7BITS;
    psmbusHandle->hi2c.init.speedMode     = kI2C_STANDARD_SPEED_MODE;
    psmbusHandle->hi2c.init.hcnt          = I2C_STANDARD_HCNT;
    psmbusHandle->hi2c.init.lcnt          = I2C_STANDARD_LCNT;
    psmbusHandle->hi2c.init.sdaRxHold     = 0x0;
    psmbusHandle->hi2c.init.sdaTxHold     = 0x0;
    psmbusHandle->hi2c.init.sdaSetup      = 0x64;
    psmbusHandle->hi2c.init.noSdaRecovery = false;
    psmbusHandle->hi2c.init.sdaTimeout    = 0xFFFFFFFF;
    psmbusHandle->hi2c.init.sclTimeout    = 0xFFFFFFFF;
    psmbusHandle->hi2c.init.slaveAddr     = SMBUS_ADDRESS;
    psmbusHandle->mext                    = SMBUS_MEXT;
    psmbusHandle->sext                    = SMBUS_SEXT;

#ifdef MASTER_BOARD

    psmbusHandle->hi2c.mode       = kI2C_MASTER_MODE;
    psmbusHandle->hi2c.targetAddr = SMBUS_ALERT_RESPONSE_ADDR;
    if (SMBUS_initMaster(psmbusHandle) != kSTATUS_I2C_OK)
    {
        /* Processing Error */
        Error_Handler();
    }

    while (!SMBUS_isAlertAsserted(psmbusHandle))
        ;
    /* Turn LED2 on: Received alert signal */
    GPIO_writePin(BOARD_GPIO_LED0, 0);
    DELAY(10000);
    while (SMBUS_isAlertAsserted(psmbusHandle))
    {
        if (SMBUS_masterReceiveByte(psmbusHandle, buff, 10000) != kSTATUS_I2C_OK)
        {
            Error_Handler();
        }
        DELAY(50);
    }
    /* Turn LED2 off: Received slave address */
    GPIO_writePin(BOARD_GPIO_LED0, 1);
    DELAY(10000);
#else

    psmbusHandle->hi2c.mode = kI2C_SLAVE_MODE;
    if (SMBUS_initSlave(psmbusHandle) != kSTATUS_I2C_OK)
    {
        /* Processing Error */
        Error_Handler();
    }

    SMBUS_assertAlert(psmbusHandle);

    if (SMBUS_isAlertAsserted(psmbusHandle))
    {
        /* Turn LED2 on: successfully asserted alert */
        GPIO_writePin(BOARD_GPIO_LED0, 0);
        DELAY(10000);
    }
    else
    {
        /* Processing Error */
        Error_Handler();
    }
    while (SMBUS_isAlertAsserted(psmbusHandle))
        ;
    /* Turn LED2 off: alert response address is received and slave address is sent*/
    GPIO_writePin(BOARD_GPIO_LED0, 1);
    DELAY(10000);

#endif /* MASTER_BOARD */
#endif
    /* Infinite loop */
    while (1)
    {
    }
}