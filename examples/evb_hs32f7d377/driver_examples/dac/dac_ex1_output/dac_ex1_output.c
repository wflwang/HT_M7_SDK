/*
 * Copyright 2023 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*******************************************************************************
//
// FILE:   dac_ex1_output
//
// TITLE:  Buffered DAC Enable Output Example.
//
//! \addtogroup driver_example_list
//! <h1> Buffered DAC Enable </h1>
//!
//! This example generates a voltage on the buffered DAC output,
//! DACOUTA/ADCINA0, DACOUTB/ADCINA1, DACOUTC/ADCINB1, and uses the default DAC
//! reference setting of VDAC.
//!
//! \b External \b Connections \n
//!  - When the DAC reference is set to VDAC, an external reference voltage
//!    must be applied to the VDAC pin. This can be accomplished by connecting a
//!    jumper wire from 2.5V to ADCINB0.
//!
//! \b Watch \b Variables \n
//!  - None.
//!
 ******************************************************************************/
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "board.h"
#include "hte_dac.h"
#include "hte_sysctrl.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Size of Transmission buffer */
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
static void initDACA()
{
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_DACA);
    
    DAC_setReferenceVoltage(DACA, DAC_REF_VDAC);
    DAC_setLoadMode(DACA, DAC_LOAD_SYSCLK);
    DAC_setShadowValue(DACA, DACA_OUTPUT_VALUE);
    DAC_enableOutput(DACA);
}

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
    
int main(void)
{
    BOARD_init();
    
    /* Infinite the DACx configuration */
    initDACA();    
    initDACB();    
    initDACC();    
       
    /* Infinite loop */
    while (1)
    {
    }
    
}