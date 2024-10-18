/*
 * Copyright 2023 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*!
 * \file ecap_apwm_phase_shift.c
 * \brief ECAP example file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "board.h"
#include "hte_ecap.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! \brief ECAP used by CPU1 in this example */
#define EXAMPLE_ECAP0_CPU1 (ECAP1)
#define EXAMPLE_ECAP1_CPU1 (ECAP2)

/*! \brief ECAP used by CPU2 in this example */
#define EXAMPLE_ECAP0_CPU2 (ECAP3)
#define EXAMPLE_ECAP1_CPU2 (ECAP4)

/*! \brief The source for sync-in pulse used by CPU1 in this example */
#define EXAMPLE_SYNC_IN_PULSE_SRC_CPU1 (kECAP_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP1)
/*! \brief The source for sync-in pulse used by CPU2 in this example */
#define EXAMPLE_SYNC_IN_PULSE_SRC_CPU2 (kECAP_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP3)

/*! \brief The phase shift value count used by CPU1 in this example */
#define EXAMPLE_PHASE_SHIFT_CPU1 (6000)
/*! \brief The phase shift value count used by CPU2 in this example */
#define EXAMPLE_PHASE_SHIFT_CPU2 (10000)
#if defined(BOARD_USE_CPU1)
/*! \brief ECAP used in this example */
#define EXAMPLE_ECAP0 (EXAMPLE_ECAP0_CPU1)
#define EXAMPLE_ECAP1 (EXAMPLE_ECAP1_CPU1)

/*! \brief The source for sync-in pulse used in this example */
#define EXAMPLE_SYNC_IN_PULSE_SRC (EXAMPLE_SYNC_IN_PULSE_SRC_CPU1)
/*! \brief The phase shift value count used in this example */
#define EXAMPLE_PHASE_SHIFT (EXAMPLE_PHASE_SHIFT_CPU1)
#elif defined(BOARD_USE_CPU2)
/*! \brief ECAP used in this example */
#define EXAMPLE_ECAP0             (EXAMPLE_ECAP0_CPU2)
#define EXAMPLE_ECAP1             (EXAMPLE_ECAP1_CPU2)
/*! \brief The source for sync-in pulse used in this example */
#define EXAMPLE_SYNC_IN_PULSE_SRC (EXAMPLE_SYNC_IN_PULSE_SRC_CPU2)
/*! \brief The phase shift value count used in this example */
#define EXAMPLE_PHASE_SHIFT       (EXAMPLE_PHASE_SHIFT_CPU2)
#endif

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
void myECAP0_init()
{
    /* Stops Time stamp counter */
    ECAP_stopCounter(EXAMPLE_ECAP0);
    /* Sets eCAP in APWM mode */
    ECAP_enableAPWMMode(EXAMPLE_ECAP0);
    /* Set eCAP APWM period */
    ECAP_setAPWMPeriod(EXAMPLE_ECAP0, 20000U);
    /* Set eCAP APWM on or off time count */
    ECAP_setAPWMCompare(EXAMPLE_ECAP0, 10000U);
    /* Set eCAP APWM polarity */
    ECAP_setAPWMPolarity(EXAMPLE_ECAP0, kECAP_APWM_ACTIVE_HIGH);
    /* Sets a phase shift value count */
    ECAP_setPhaseShiftCount(EXAMPLE_ECAP0, 0U);
    /* Disable counter loading with phase shift value */
    ECAP_disableLoadCounter(EXAMPLE_ECAP0);
    /* Configures Sync out signal mode */
    ECAP_setSyncOutMode(EXAMPLE_ECAP0, kECAP_SYNC_OUT_COUNTER_PRD);
    /* Configures emulation mode */
    ECAP_setEmulationMode(EXAMPLE_ECAP0, kECAP_EMULATION_STOP);
    /* Set up the source for sync-in pulse */
    ECAP_setSyncInPulseSource(EXAMPLE_ECAP0, kECAP_SYNC_IN_PULSE_SRC_DISABLE);
    /* Starts Time stamp counter */
    ECAP_startCounter(EXAMPLE_ECAP0);
}

void myECAP1_init()
{
    /* Stops Time stamp counter */
    ECAP_stopCounter(EXAMPLE_ECAP1);
    /* Sets eCAP in APWM mode */
    ECAP_enableAPWMMode(EXAMPLE_ECAP1);
    /* Set eCAP APWM period */
    ECAP_setAPWMPeriod(EXAMPLE_ECAP1, 20000U);
    /* Set eCAP APWM on or off time count */
    ECAP_setAPWMCompare(EXAMPLE_ECAP1, 10000U);
    /* Set eCAP APWM polarity */
    ECAP_setAPWMPolarity(EXAMPLE_ECAP1, kECAP_APWM_ACTIVE_HIGH);
    /* Sets a phase shift value count */
    ECAP_setPhaseShiftCount(EXAMPLE_ECAP1, EXAMPLE_PHASE_SHIFT);
    /* Disable counter loading with phase shift value */
    ECAP_enableLoadCounter(EXAMPLE_ECAP1);
    /* Configures Sync out signal mode */
    ECAP_setSyncOutMode(EXAMPLE_ECAP1, kECAP_SYNC_OUT_SYNCI);
    /* Configures emulation mode */
    ECAP_setEmulationMode(EXAMPLE_ECAP1, kECAP_EMULATION_STOP);
    /* Set up the source for sync-in pulse */
    ECAP_setSyncInPulseSource(EXAMPLE_ECAP1, EXAMPLE_SYNC_IN_PULSE_SRC);
    /* Starts Time stamp counter */
    ECAP_startCounter(EXAMPLE_ECAP1);
}

void ECAP_init()
{
    myECAP0_init();
    myECAP1_init();
}

int main(void)
{
    /* Board initialization */
    BOARD_init();

    /* Pinmux configuration, Pad configuration and XBAR configuration*/
#if defined(BOARD_USE_CPU1)
    BOARD_ecapPinConfig(EXAMPLE_ECAP0_CPU1);
    BOARD_ecapPinConfig(EXAMPLE_ECAP1_CPU1);
#endif
#if defined(BOARD_CONFIG_CPU2)
    BOARD_ecapPinConfig(EXAMPLE_ECAP0_CPU2);
    BOARD_ecapPinConfig(EXAMPLE_ECAP1_CPU2);
    BOARD_ecapAssign2CPU2(EXAMPLE_ECAP0_CPU2);
    BOARD_ecapAssign2CPU2(EXAMPLE_ECAP1_CPU2);
#endif

    /* Peripheral clock configuration */
    BOARD_ecapClockEnable(EXAMPLE_ECAP0);
    BOARD_ecapClockEnable(EXAMPLE_ECAP1);

    ECAP_init();

    /* Infinite loop */
    while (1)
    {
    }
}