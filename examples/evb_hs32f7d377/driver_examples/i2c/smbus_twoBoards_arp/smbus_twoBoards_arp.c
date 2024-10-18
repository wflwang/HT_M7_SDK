/*
 * Copyright 2023 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*!
 * \file smbus_twoBoards_arp.c
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
/*! \brief Address to be assigned to slave */
uint8_t         assignAddr = 0x12;

/*******************************************************************************
 * Codes
 ******************************************************************************/

static void Error_Handler(void)
{
    while (1)
    {
        GPIO_togglePin(BOARD_GPIO_LED0);
        DELAY(100000);
    }
}

int main(void)
{
    /* Board initialization */
    BOARD_init();

    /* Pinmux configuration and Pad configuration */
    BOARD_ledPinConfig(0U);
    BOARD_ledPinConfig(1U);
    BOARD_ledPinConfig(2U);
    /* Configure LED GPIO as output */
    GPIO_setDirectionMode(BOARD_GPIO_LED0, kGPIO_DIR_OUTPUT);
    GPIO_setDirectionMode(BOARD_GPIO_LED1, kGPIO_DIR_OUTPUT);
    GPIO_setDirectionMode(BOARD_GPIO_LED2, kGPIO_DIR_OUTPUT);
    GPIO_writePin(BOARD_GPIO_LED0, 1);
    GPIO_writePin(BOARD_GPIO_LED1, 1);
    GPIO_writePin(BOARD_GPIO_LED2, 1);

    BOARD_pmbusPinConfig(PMBUSA);

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
    psmbusHandle->hi2c.targetAddr = SMBUS_DEVICE_DEFAULT_ADDR;
    if (SMBUS_initMaster(psmbusHandle) != kSTATUS_I2C_OK)
    {
        /* Processing Error */
        Error_Handler();
    }
    SMBUS_masterARPInit(psmbusHandle);
    if (SMBUS_resetDevice(psmbusHandle, 0, 10000) != kSTATUS_I2C_OK)
    {
        /* Processing Error */
        Error_Handler();
    }
    if (SMBUS_prepareToARP(psmbusHandle, 10000) != kSTATUS_I2C_OK)
    {
        /* Processing Error */
        Error_Handler();
    }
    /* Turn LED2 on: sent prepare to ARP command successfully */
    GPIO_writePin(BOARD_GPIO_LED0, 0);
    DELAY(10000);

    if (SMBUS_getUDID(psmbusHandle, 0, 10000) != kSTATUS_I2C_OK)
    {
        /* Processing Error */
        Error_Handler();
    }
    /* Turn LED3 on: sent GET UDID command successfully */
    GPIO_writePin(BOARD_GPIO_LED1, 0);
    DELAY(10000);

    if (SMBUS_assignAddr(psmbusHandle, assignAddr, 10000) != kSTATUS_I2C_OK)
    {
        /* Processing Error */
        Error_Handler();
    }
    /* Turn LED4 on: sent Assign Address command successfully */
    GPIO_writePin(BOARD_GPIO_LED2, 0);
    DELAY(10000);
#else

    psmbusHandle->hi2c.mode = kI2C_SLAVE_MODE;
    if (SMBUS_initSlave(psmbusHandle) != kSTATUS_I2C_OK)
    {
        /* Processing Error */
        Error_Handler();
    }

    SMBUS_slaveEnableARP(psmbusHandle, 0);

    /* Wait for ARP RESET command if this slave already resolved address */
    while (SMBUS_isAddrResolved(psmbusHandle) || SMBUS_isAddrValid(psmbusHandle))
        ;
    while (!SMBUS_isAddrResolved(psmbusHandle))
        ;
    if (SMBUS_getResolvedAddr(psmbusHandle) != assignAddr >> 1)
    {
        Error_Handler();
    }
    /* Turn LED2 on: received valid address */
    GPIO_writePin(BOARD_GPIO_LED0, 0);
    DELAY(10000);

#endif /* MASTER_BOARD */
    /* Infinite loop */
    while (1)
    {
    }
}