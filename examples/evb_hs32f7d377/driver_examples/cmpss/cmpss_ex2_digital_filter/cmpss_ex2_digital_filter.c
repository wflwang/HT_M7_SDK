/*
 * Copyright 2023 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file cmpss_ex1_asynch.c
 * \brief SDK source file example
 * \version 1.0.0
 */
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "board.h"
#include "hte_cmpss.h"
#include "hte_gpio.h"
#include "hte_pinmux.h"
#include "hte_sysctrl.h"
#include "hte_xbar.h"
#include "hte_xbarmux.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*!< CMPSS1 base */
#define myCMPSS1_BASE CMPSS1

/*!< CMPSS1 base */
#define myCMPSS2_BASE CMPSS2

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
void PinMux_init()
{
#if defined(BOARD_USE_CPU1)
    /* for compss 1 high */
    GPIO_setPinConfig(GPIO_9_OUTPUTXBAR6);

    /* for compss 1 low */
    GPIO_setPinConfig(GPIO_30_OUTPUTXBAR7);
#endif

#if defined(BOARD_CONFIG_CPU2)
    /* for compss 2 high */
    GPIO_setPinConfig(GPIO_24_OUTPUTXBAR1);

    /* for compss 2 low */
    GPIO_setPinConfig(GPIO_25_OUTPUTXBAR2);
#endif
}

void OUTPUTXBAR_init()
{
#if defined(BOARD_USE_CPU1)
    /* for compss 1 high*/
    XBAR_setOutputLatchMode(OUTPUT_XBAR, kXBAR_OUTPUT6, false);
    XBAR_invertOutputSignal(OUTPUT_XBAR, kXBAR_OUTPUT6, false);
    XBAR_setOutputMuxConfig(OUTPUT_XBAR, kXBAR_OUTPUT6, XBAR_OUT_MUX00_CMPSS1_CTRIPOUTH);
    XBAR_enableOutputMux(OUTPUT_XBAR, kXBAR_OUTPUT6, kXBAR_MUX00);

    /* for compss 1 low*/
    XBAR_setOutputLatchMode(OUTPUT_XBAR, kXBAR_OUTPUT7, false);
    XBAR_invertOutputSignal(OUTPUT_XBAR, kXBAR_OUTPUT7, false);
    XBAR_setOutputMuxConfig(OUTPUT_XBAR, kXBAR_OUTPUT7, XBAR_OUT_MUX01_CMPSS1_CTRIPOUTL);
    XBAR_enableOutputMux(OUTPUT_XBAR, kXBAR_OUTPUT7, kXBAR_MUX01);
#endif

#if defined(BOARD_CONFIG_CPU2)
    /* for compss 2 high*/
    XBAR_setOutputLatchMode(OUTPUT_XBAR, kXBAR_OUTPUT1, false);
    XBAR_invertOutputSignal(OUTPUT_XBAR, kXBAR_OUTPUT1, false);
    XBAR_setOutputMuxConfig(OUTPUT_XBAR, kXBAR_OUTPUT1, XBAR_OUT_MUX02_CMPSS2_CTRIPOUTH);
    XBAR_enableOutputMux(OUTPUT_XBAR, kXBAR_OUTPUT1, kXBAR_MUX02);

    /* for compss 2 low*/
    XBAR_setOutputLatchMode(OUTPUT_XBAR, kXBAR_OUTPUT2, false);
    XBAR_invertOutputSignal(OUTPUT_XBAR, kXBAR_OUTPUT2, false);
    XBAR_setOutputMuxConfig(OUTPUT_XBAR, kXBAR_OUTPUT2, XBAR_OUT_MUX03_CMPSS2_CTRIPOUTL);
    XBAR_enableOutputMux(OUTPUT_XBAR, kXBAR_OUTPUT2, kXBAR_MUX03);
#endif
}

void CMPSS1_config(void)
{
#if defined(BOARD_USE_CPU1)
    /*  Set compss 1 to CPU1 */
    SYSCTRL_selectCPUForPeripheral((kSYSCTL_PERIPH_CPUSEL_CMPSS1), kSYSCTRL_CPUSEL_CPU1);

    /* Reset compss 1 */
    SYSCTRL_resetPeripheral(kSYSCTL_PERIPH_RES_CMPSS1);

    /*  Enbale compss 1 Clock */
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_CMPSS1);

    /* Sets the configuration for the high comparator. */
    CMPSS_configHighComparator(myCMPSS1_BASE, (CMPSS_INSRC_DAC));

    /* Sets the configuration for the high comparator. */
    CMPSS_configLowComparator(myCMPSS1_BASE, (CMPSS_INSRC_DAC));

    /* Sets the configuration for the internal comparator DACs. */
    CMPSS_configDAC(myCMPSS1_BASE, (CMPSS_DACVAL_SYSCLK | CMPSS_DACREF_VDDA | CMPSS_DACSRC_SHDW));

    /* Sets the value of the internal DAC of the high comparator. */
    CMPSS_setDACValueHigh(myCMPSS1_BASE, 2048U);

    /* Sets the value of the internal DAC of the low comparator. */
    CMPSS_setDACValueLow(myCMPSS1_BASE, 1024U);

    //  Configures the digital filter of the high comparator. */
    CMPSS_configFilterHigh(myCMPSS1_BASE, 0x3FF, 32, 31);

    /* Configures the digital filter of the low comparator. */
    CMPSS_configFilterLow(myCMPSS1_BASE, 0x3FF, 32, 31);

    /* Initialize the filter logic and start filtering */
    CMPSS_initFilterHigh(myCMPSS1_BASE);

    /* Sets the output signal configuration for the high comparator. */
    CMPSS_configOutputsHigh(myCMPSS1_BASE, (CMPSS_TRIP_FILTER | CMPSS_TRIPOUT_FILTER));

    /* Sets the output signal configuration for the low comparator. */
    CMPSS_configOutputsLow(myCMPSS1_BASE, (CMPSS_TRIP_FILTER | CMPSS_TRIPOUT_FILTER));

    /* Enables the CMPSS module. */
    CMPSS_enableModule(myCMPSS1_BASE);
#endif
}

void CMPSS2_config(void)
{
#if defined(BOARD_CONFIG_CPU2)
    /*  Set CMPSS1 to CPU1 */
    SYSCTRL_selectCPUForPeripheral((kSYSCTL_PERIPH_CPUSEL_CMPSS2), kSYSCTRL_CPUSEL_CPU2);

    /* Reset CMPSS2 */
    SYSCTRL_resetPeripheral(kSYSCTL_PERIPH_RES_CMPSS2);
#endif

#if defined(BOARD_USE_CPU2)

    /*  Enbale CMPSS2 Clock */
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_CMPSS2);

    /* Sets the configuration for the high comparator. */
    CMPSS_configHighComparator(myCMPSS2_BASE, (CMPSS_INSRC_DAC));

    /* Sets the configuration for the high comparator. */
    CMPSS_configLowComparator(myCMPSS2_BASE, (CMPSS_INSRC_DAC));

    /* Sets the configuration for the internal comparator DACs. */
    CMPSS_configDAC(myCMPSS2_BASE, (CMPSS_DACVAL_SYSCLK | CMPSS_DACREF_VDDA | CMPSS_DACSRC_SHDW));

    /* Sets the value of the internal DAC of the high comparator. */
    CMPSS_setDACValueHigh(myCMPSS2_BASE, 2048U);

    /* Sets the value of the internal DAC of the low comparator. */
    CMPSS_setDACValueLow(myCMPSS2_BASE, 1024U);

    //  Configures the digital filter of the high comparator. */
    CMPSS_configFilterHigh(myCMPSS2_BASE, 0x3FF, 32, 31);

    /* Configures the digital filter of the low comparator. */
    CMPSS_configFilterLow(myCMPSS2_BASE, 0x3FF, 32, 31);

    /* Initialize the filter logic and start filtering */
    CMPSS_initFilterHigh(myCMPSS1_BASE);

    /* Sets the output signal configuration for the high comparator. */
    CMPSS_configOutputsHigh(myCMPSS2_BASE, (CMPSS_TRIP_FILTER | CMPSS_TRIPOUT_FILTER));

    /* Sets the output signal configuration for the low comparator. */
    CMPSS_configOutputsLow(myCMPSS2_BASE, (CMPSS_TRIP_FILTER | CMPSS_TRIPOUT_FILTER));

    /* Enables the CMPSS module. */
    CMPSS_enableModule(myCMPSS2_BASE);
#endif
}

int main(void)
{
    BOARD_init();

    PinMux_init();

    CMPSS1_config();

    CMPSS2_config();

    OUTPUTXBAR_init();

    /* Infinite loop */
    while (1)
    {
    }
}