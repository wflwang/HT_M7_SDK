/*
 * Copyright 2023 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
//###########################################################################
//
// FILE:   hrpwm_ex1_up_aq.c
//
// TITLE:  Configure desired EPWM frequency & duty
//
//! \addtogroup driver_example_list
//! <h1> EPWM Configure Signal </h1>
//!
//!
//
//###########################################################################
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "board.h"
#include "hte_epwm.h"
#include "hte_sysctrl.h"
#include "hte_hrpwm.h"
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
static void initEPWM8()
{
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_EPWM8);

    EPWM_setCounterCompareValue(EPWM8, EPWM_COUNTER_COMPARE_B, 200U);
    EPWM_setCounterCompareValue(EPWM8, EPWM_COUNTER_COMPARE_A, 99U);
    
    EPWM_setActionQualifierAction(EPWM8, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    EPWM_setActionQualifierAction(EPWM8, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    EPWM_setActionQualifierAction(EPWM8, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    EPWM_setActionQualifierAction(EPWM8, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);

    EPWM_setClockPrescaler(EPWM8, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);
    EPWM_setTimeBasePeriod(EPWM8, 299);
    EPWM_setTimeBaseCounterMode(EPWM8, EPWM_COUNTER_MODE_UP); // 0: up, 1: down, 2, up-down, 3:freeze-counter(reset)              
}
    
int main(void)
{
    BOARD_init();
    
    /* GPIO20: EPWM11A, GPIO21: EPWM11B */
    BOARD_epwmPinConfig(EPWM8);

    /* Disable the ePWM TBCLK peripheral */
    SYSCTRL_disablePeripheral(kSYSCTL_PERIPH_CLK_TBCLKSYNC);    
    
    /* Infinite the ePWM configuration */
    initEPWM8();
   
    HRCAL_setUpdataMode(HRCAL, HRCAL_COUNTER_MODE);
    HRCAL_setCounterPeriod(HRCAL, 1499999999);
    HRCAL_selectAccumulatorBitWidth(HRCAL, HRCAL_SELECT_7_TO_14_BITS);

    HRCAL_enableStepValueAdjustment(HRCAL);
    HRCAL_setDataStorageNumber(HRCAL, HRCAL_STORAGE_32_DATA);
    HRCAL_setThresholdValue(HRCAL, 2);

    HRCAL_enableCalibrationInt(HRCAL);
    HRCAL_enableCalibration(HRCAL);

    HRCAL_waitCalibrationCompelet(HRCAL);
    HRPWM_disableAutoConversion(HREPWM8);
    HRPWM_setMEPEdgeSelect(HREPWM8, HRPWM_CHANNEL_A, HRPWM_MEP_CTRL_RISING_EDGE);
    HRPWM_setRisingEdgeDelay(HREPWM8, HRPWM_CHANNEL_A, 0);

    /* Enable the ePWM TBCLK peripheral */
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_TBCLKSYNC); 
            
    /* Infinite loop */
    while (1)
    {
    }
    
}