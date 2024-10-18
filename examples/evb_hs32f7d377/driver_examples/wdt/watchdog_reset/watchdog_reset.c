/*
 * Copyright 2023 Watech Electronics
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
#include "hte_wdt.h"

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
static WDT_Cfg_t wdt_cfg = { WDT_ENABLE, WDT_RPL_256PCLKS, WDT_PERIOD_6_5SEC, INT_RMOD };

/*******************************************************************************
 * Codes
 ******************************************************************************/
void WDT_DriverHandler(void)
{
    NVIC_DisableIRQ(WDT_IRQn);

    PRINTF("wdt occur!,disable int wait for reset\r\n");
    ISR_EXIT_BARRIER();
}

int main(void)
{
    /* Board initialization */
    BOARD_init();
    char key = 'N';

    PRINTF("PUT y to enter wdt test\r\n");

    while ((key != 'y') && (key != 'Y'))
    {
        SCANF("%c", &key);
    }
    /* wdt initialization */
    WDT_init(&wdt_cfg);

    /* Print the example banner */
    PRINTF("\r\n");
    PRINTF("WDT Example:\r\n");
    PRINTF("WAIT 6.5s enter to interrupt, then 6.5s reset to boorom......\r\n");


    while (1)
        ;
}
