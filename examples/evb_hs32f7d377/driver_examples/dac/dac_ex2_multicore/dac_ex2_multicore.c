/*
 * Copyright 2023 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*!
 * \file dac_ex2_multicore.c
 * \brief DAC test file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "board.h"
#include "hte_sysctrl.h"
#include "hte_dac.h"
#include "hte_gpio.h"
#include "hte_xbar.h"
#include "hte_pinmux.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define DACA_OUTPUT_VALUE       1024U
#define DACB_OUTPUT_VALUE       2048U
#define DACC_OUTPUT_VALUE       3072U

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/* No Prototypes */

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*******************************************************************************
 * Codes
 ******************************************************************************/
#if defined(BOARD_USE_CPU1)
static void initDACA()
{
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_DACA);
    
    DAC_setReferenceVoltage(DACA, DAC_REF_VDAC);
    DAC_setLoadMode(DACA, DAC_LOAD_SYSCLK);
    DAC_setShadowValue(DACA, DACA_OUTPUT_VALUE);
    DAC_enableOutput(DACA);
}
#endif

#if defined(BOARD_USE_CPU2)
static void initDACB()
{
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_DACB);
    
    DAC_setReferenceVoltage(DACB, DAC_REF_VDAC);
    DAC_setLoadMode(DACB, DAC_LOAD_SYSCLK);
    DAC_setShadowValue(DACB, DACB_OUTPUT_VALUE);    
    DAC_enableOutput(DACB);
}

static void initDACC()
{
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_DACC);
    
    DAC_setReferenceVoltage(DACC, DAC_REF_VDAC);
    DAC_setLoadMode(DACC, DAC_LOAD_SYSCLK);
    DAC_setShadowValue(DACC, DACC_OUTPUT_VALUE);
    DAC_enableOutput(DACC);
}
#endif

int main(void)
{
    BOARD_init();
        
#if defined(BOARD_CONFIG_CPU2)   
    SYSCTRL_selectCPUForPeripheral(kSYSCTL_PERIPH_CPUSEL_DACB, kSYSCTRL_CPUSEL_CPU2);
    SYSCTRL_selectCPUForPeripheral(kSYSCTL_PERIPH_CPUSEL_DACC, kSYSCTRL_CPUSEL_CPU2);
#endif

#if defined(BOARD_USE_CPU1)
    /* GPIO2: OUTPUT XBAR1 - ECAP1.OUT */
    initDACA();
#endif
#if defined(BOARD_USE_CPU2)
    /* GPIO2: OUTPUT XBAR1 - ECAP1.OUT */
    initDACB();
    initDACC();
#endif

    for (;;)
    {
    }
    
}
