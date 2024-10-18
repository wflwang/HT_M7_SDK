/*
 * Copyright 2023 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*******************************************************************************
//
// FILE:   epwm_ex1_up_aq
//
// TITLE:  Action Qualifier Module - Using up count.
//
//! \addtogroup driver_example_list
//! <h1> EPWM Action Qualifier (epwm_up_aq)</h1>
//!
//! This example configures ePWM10, ePWM11, ePWM12 to produce an
//! waveform with independent modulation on EPWMxA and
//! EPWMxB.
//!
//! The TB counter is in up count mode for this example.
//!
//! View the EPWM10A/B(GPI18 & GPIO19), EPWM11A/B(GPIO20 & GPIO21)
//! and EPWM12A/B(GPIO22 & GPIO23) waveforms via an oscilloscope.
//!
 ******************************************************************************/
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

#define EPWM10_CMPA_VALUE       3000U
#define EPWM10_CMPB_VALUE       (EPWM_TIMER_TBPRD - EPWM10_CMPA_VALUE)
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
static void initEPWM10()
{
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_EPWM10);

    EPWM_setCounterCompareValue(EPWM10, EPWM_COUNTER_COMPARE_B, EPWM10_CMPB_VALUE);
    EPWM_setCounterCompareValue(EPWM10, EPWM_COUNTER_COMPARE_A, EPWM10_CMPA_VALUE);

    EPWM_setActionQualifierAction(EPWM10, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    EPWM_setActionQualifierAction(EPWM10, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(EPWM10, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    EPWM_setActionQualifierAction(EPWM10, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);

    EPWM_setTimeBasePeriod(EPWM10, EPWM_TIMER_TBPRD);
    EPWM_setTimeBaseCounterMode(EPWM10, EPWM_COUNTER_MODE_UP);
}

static void initEPWM11()
{
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_EPWM11);

    EPWM_setCounterCompareValue(EPWM11, EPWM_COUNTER_COMPARE_B, EPWM11_CMPB_VALUE);
    EPWM_setCounterCompareValue(EPWM11, EPWM_COUNTER_COMPARE_A, EPWM11_CMPA_VALUE);

    EPWM_setActionQualifierAction(EPWM11, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    EPWM_setActionQualifierAction(EPWM11, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(EPWM11, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    EPWM_setActionQualifierAction(EPWM11, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);

    EPWM_setTimeBasePeriod(EPWM11, EPWM_TIMER_TBPRD);
    EPWM_setTimeBaseCounterMode(EPWM11, EPWM_COUNTER_MODE_UP);
}

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
#if defined(BOARD_USE_CPU1)
    /* GPIO18: EPWM10A, GPIO19: EPWM10B */
    BOARD_epwmPinConfig(EPWM10);
    /* GPIO20: EPWM11A, GPIO21: EPWM11B */
    BOARD_epwmPinConfig(EPWM11);
    /* GPIO22: EPWM12A, GPIO23: EPWM12B */
    BOARD_epwmPinConfig(EPWM12);
#endif
    /* Disable the ePWM TBCLK peripheral */
    SYSCTRL_disablePeripheral(kSYSCTL_PERIPH_CLK_TBCLKSYNC); 
    
#if defined(BOARD_CONFIG_CPU2)
    BOARD_epwmPinConfig(EPWM11);
    BOARD_epwmAssign2CPU2(EPWM11);
#endif   
   
    /* Infinite the ePWM configuration */
    initEPWM10();    
    initEPWM11();  
    initEPWM12();    

    /* Enable the ePWM TBCLK peripheral */
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_TBCLKSYNC); 
    
    /* Infinite loop */
    while (1)
    {
                DELAY(1000000);
        PRINTF("test done \r\n");
    }

}