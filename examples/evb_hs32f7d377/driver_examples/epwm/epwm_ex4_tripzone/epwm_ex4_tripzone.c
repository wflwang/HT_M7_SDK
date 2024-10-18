/*
 * Copyright 2023 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*!
 * \file epwm_ex4_tripzone.c
 * \brief EPWM test file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "board.h"
#include "hte_sysctrl.h"
#include "hte_epwm.h"
#include "hte_gpio.h"
#include "hte_xbar.h"
#include "hte_pinmux.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define EPWM_TIMER_TBPRD      12000U
#define EPWM_CMPA_VALUE       3000U
#define EPWM_CMPB_VALUE       (EPWM_TIMER_TBPRD - EPWM_CMPA_VALUE)


#define EXAMPLE_EPWM_CPU1 EPWM12
#define EXAMPLE_EPWM_CPU2 EPWM11

#if defined(BOARD_USE_CPU1)
#define EXAMPLE_EPWM EXAMPLE_EPWM_CPU1
#elif defined(BOARD_USE_CPU2)
#define EXAMPLE_EPWM EXAMPLE_EPWM_CPU2
#endif

#define DECREASE_FREQUENCY 0
#define INCREASE_FREQUENCY 1
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
void EPWM_init()
{
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_EPWM12);
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_EPWM11);
    
    EPWM_setTimeBasePeriod(EXAMPLE_EPWM, EPWM_TIMER_TBPRD);
    EPWM_setTimeBaseCounterMode(EXAMPLE_EPWM, EPWM_COUNTER_MODE_UP); // 0, up

    EPWM_setCounterCompareValue(EXAMPLE_EPWM, EPWM_COUNTER_COMPARE_A, EPWM_CMPA_VALUE);
    EPWM_setCounterCompareValue(EXAMPLE_EPWM, EPWM_COUNTER_COMPARE_B, EPWM_CMPB_VALUE);

    // Set actions
    EPWM_setActionQualifierAction(EXAMPLE_EPWM, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    EPWM_setActionQualifierAction(EXAMPLE_EPWM, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(EXAMPLE_EPWM, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    EPWM_setActionQualifierAction(EXAMPLE_EPWM, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
}

int main(void)
{
    BOARD_init();
#if defined(BOARD_USE_CPU1)
    /* GPIO2: OUTPUT XBAR1 - ECAP1.OUT */
    BOARD_epwmPinConfig(EPWM12);
    
    GPIO_setPinConfig(GPIO_0_GPIO0);
    GPIO_setDirectionMode(0, kGPIO_DIR_INPUT);
    GPIO_setQualificationMode(0, kGPIO_QUAL_ASYNC);
    XBAR_setInputPin(INPUT_XBAR, kXBAR_INPUT1, 0);
#endif
    
#if defined(BOARD_CONFIG_CPU2)
    BOARD_epwmPinConfig(EPWM11);
    BOARD_epwmAssign2CPU2(EPWM11);
#endif

    /* Disable the ePWM TBCLK peripheral */
    SYSCTRL_disablePeripheral(kSYSCTL_PERIPH_CLK_TBCLKSYNC);  
    
    EPWM_init();
   
    /* Enable the ePWM TBCLK peripheral */
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_TBCLKSYNC); 

    EPWM_enableTripZoneSignals(EXAMPLE_EPWM_CPU1, EPWM_TZ_SIGNAL_CBC1);
    EPWM_setTripZoneAction(EXAMPLE_EPWM_CPU1, EPWM_TZ_ACTION_EVENT_TZA, EPWM_TZ_ACTION_HIGH);

    for (;;)
    {
    }
    
}