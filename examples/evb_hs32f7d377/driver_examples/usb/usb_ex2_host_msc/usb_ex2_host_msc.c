/*
 * Copyright 2023 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*!
 * \file usb_ex2_host_host_msc.c
 * \brief Example of SDK debug console
 * \version 1.0.0
 */
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "board.h"
#include "hte_gpio.h"
#include "hte_pinmux.h"
#include "hte_sysctrl.h"
#include "usb_host.h"
#include "usbh_core.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! \brief USB clk ~48Mhz */
#define USB_CLK_48MHZ (0x02DC6C00UL)

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
void USBD_setIomux(void)
{
#if defined(HTE_DEVICE_HS32F7D377_CPU1)
    GPIO_setPinConfig(GPIO_43_USBA_DP);
    GPIO_setPinConfig(GPIO_42_USBA_DM);

    GPIO_setDriverStrength(42, kGPIO_DRV_STR_29P5MA);
    GPIO_setDriverStrength(43, kGPIO_DRV_STR_29P5MA);
#endif
}
int main(void)
{
    /* Board initialization */
    BOARD_init();

    /* Pinmux configuration and Pad configuration */
#if defined(BOARD_USE_CPU1)
    SYSCTRL_selectCPUForPeripheral(kSYSCTL_PERIPH_CPUSEL_USB, kSYSCTRL_CPUSEL_CPU1); // select USB to CPU1 or CPU2
#endif

    USBD_setIomux();

    if (BOARD_getAuxClk() != USB_CLK_48MHZ)
    {
        /* Aux Clock must be 48MHz */
        PRINTF("Aux Clock = %d Hz \r\n", (int)BOARD_getAuxClk());
    }

    USB_HOST_init();

    while (1)
    {
        USB_HOST_process();
    }
}
