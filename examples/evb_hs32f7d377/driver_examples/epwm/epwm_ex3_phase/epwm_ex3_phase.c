/*
 * Copyright 2023 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
//###########################################################################
//
// FILE:   epwm_ex3_phase.c
//
// TITLE:  Configure desired EPWM frequency & duty
//
//! \addtogroup driver_example_list
//! <h1> EPWM Configure Signal </h1>
//!
//!
//! During the test, monitor ePWM11, ePWM12 outputs
//! on an oscilloscope.
//!
//
//###########################################################################
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
#define EPWM_TIMER_PHASE        3000U

#define EPWM11_CMPA_VALUE       6000U
#define EPWM11_CMPB_VALUE       (EPWM_TIMER_TBPRD - EPWM11_CMPA_VALUE)
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
static void initEPWM11()
{
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_EPWM11);

    EPWM_setCounterCompareValue(EPWM11, EPWM_COUNTER_COMPARE_B, EPWM11_CMPB_VALUE);
    EPWM_setCounterCompareValue(EPWM11, EPWM_COUNTER_COMPARE_A, EPWM11_CMPA_VALUE);

    EPWM_setActionQualifierAction(EPWM11, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, 
                                    EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    EPWM_setActionQualifierAction(EPWM11, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, 
                                    EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(EPWM11, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, 
                                    EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    EPWM_setActionQualifierAction(EPWM11, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, 
                                    EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);

    EPWM_setTimeBasePeriod(EPWM11, EPWM_TIMER_TBPRD);
    EPWM_setTimeBaseCounterMode(EPWM11, EPWM_COUNTER_MODE_UP);
}

static void initEPWM12()
{
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_EPWM12);
    
    EPWM_setCounterCompareValue(EPWM12, EPWM_COUNTER_COMPARE_B, EPWM12_CMPB_VALUE);
    EPWM_setCounterCompareValue(EPWM12, EPWM_COUNTER_COMPARE_A, EPWM12_CMPA_VALUE);

    EPWM_setActionQualifierAction(EPWM12, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, 
                                    EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    EPWM_setActionQualifierAction(EPWM12, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, 
                                    EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(EPWM12, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, 
                                    EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    EPWM_setActionQualifierAction(EPWM12, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, 
                                    EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    
    EPWM_setTimeBasePeriod(EPWM12, EPWM_TIMER_TBPRD);
    EPWM_setTimeBaseCounterMode(EPWM12, EPWM_COUNTER_MODE_UP);  
}
    
int main(void)
{
    BOARD_init();
    
    /* GPIO20: EPWM11A, GPIO21: EPWM11B */
    BOARD_epwmPinConfig(EPWM11);

    /* GPIO22: EPWM12A, GPIO23: EPWM12B */
    BOARD_epwmPinConfig(EPWM12);

    /* Disable the ePWM TBCLK peripheral */
    SYSCTRL_disablePeripheral(kSYSCTL_PERIPH_CLK_TBCLKSYNC);
    
    /* Infinite the ePWM configuration */
    initEPWM11();
    initEPWM12();    
   
    EPWM_enableSyncOutPulseSource(EPWM11, EPWM_SYNC_OUT_PULSE_ON_CNTR_ZERO);
    EPWM_setSyncInPulseSource(EPWM12, EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM11);

    EPWM_enablePhaseShiftLoad(EPWM12);
    EPWM_setPhaseShift(EPWM12, EPWM_TIMER_PHASE);

    /* Enable the ePWM TBCLK peripheral */
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_TBCLKSYNC); 
            
    /* Infinite loop */
    while (1)
    {
    }
    
}