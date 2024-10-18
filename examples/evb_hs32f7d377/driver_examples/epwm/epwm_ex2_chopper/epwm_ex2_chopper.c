/*
 * Copyright 2023 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
//#############################################################################
//
// FILE:   epwm_ex2_chopper.c
//
// TITLE:  ePWM Using Chopper Submodule.
//
//! \addtogroup driver_example_list
//! <h1>ePWM Chopper</h1>
//!
//! This example configures ePWM12 as follows
//!  - ePWM12 with Chopper enabled
//!    One-Shot Pulse disabled
//!
//
//#############################################################################
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "board.h"
#include "hte_epwm.h"
#include "hte_sysctrl.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Size of Transmission buffer */
#define EPWM_TIMER_TBPRD        12000U

#define EPWM12_CMPA_VALUE       9000U
#define EPWM12_CMPB_VALUE       (EPWM_TIMER_TBPRD - EPWM12_CMPA_VALUE)
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

static void initEPWM12()
{
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_EPWM12);
    
    EPWM_setCounterCompareValue(EPWM12, EPWM_COUNTER_COMPARE_B, EPWM12_CMPB_VALUE);
    EPWM_setCounterCompareValue(EPWM12, EPWM_COUNTER_COMPARE_A, EPWM12_CMPA_VALUE);

    EPWM_setActionQualifierAction(EPWM12, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    EPWM_setActionQualifierAction(EPWM12, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(EPWM12, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    EPWM_setActionQualifierAction(EPWM12, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    
    EPWM_setTimeBasePeriod(EPWM12, EPWM_TIMER_TBPRD);
    EPWM_setTimeBaseCounterMode(EPWM12, EPWM_COUNTER_MODE_UP);  
}
    
int main(void)
{
    BOARD_init();
    /* GPIO22: EPWM12A, GPIO23: EPWM12B */
    BOARD_epwmPinConfig(EPWM12);

    /* Disable the ePWM TBCLK peripheral */
    SYSCTRL_disablePeripheral(kSYSCTL_PERIPH_CLK_TBCLKSYNC);    
    
    /* Infinite the ePWM configuration */
    initEPWM12();    
   
    /* Enable the ePWM TBCLK peripheral */
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_TBCLKSYNC); 
        
    EPWM_setChopperMode(EPWM12, 0);
    EPWM_setChopperDutyCycle(EPWM12, 3);
    EPWM_setChopperFreq(EPWM12, 3);
    EPWM_setChopperFirstPulseWidth(EPWM12, 3);
    EPWM_enableChopper(EPWM12);
    
    /* Infinite loop */
    while (1)
    {
    }
}