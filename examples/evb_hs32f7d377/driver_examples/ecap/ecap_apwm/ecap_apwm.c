/*
 * Copyright 2023 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*!
 * \file ecap_apwm.c
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
#define EXAMPLE_ECAP_CPU1 (ECAP1)
/*! \brief ECAP used by CPU2 in this example */
#define EXAMPLE_ECAP_CPU2 (ECAP2)

#if defined(BOARD_USE_CPU1)
/*! \brief ECAP used in this example */
#define EXAMPLE_ECAP (EXAMPLE_ECAP_CPU1)
#elif defined(BOARD_USE_CPU2)
/*! \brief ECAP used in this example */
#define EXAMPLE_ECAP (EXAMPLE_ECAP_CPU2)
#endif

/*! \brief ECAP APWM direction */
#define DECREASE_FREQUENCY (0)
#define INCREASE_FREQUENCY (1)
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/* No Prototypes */

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! \brief Current ECAP APWM direction */
uint16_t          direction;
/*! \brief Current time stamp count of EVENT1 */
volatile uint32_t cap1Count;
/*******************************************************************************
 * Codes
 ******************************************************************************/
void ECAP_init()
{
    /* Stops Time stamp counter */
    ECAP_stopCounter(EXAMPLE_ECAP);
    /* Sets eCAP in APWM mode */
    ECAP_enableAPWMMode(EXAMPLE_ECAP);
    /* Set eCAP APWM period */
    ECAP_setAPWMPeriod(EXAMPLE_ECAP, 20000U);
    /* Set eCAP APWM on or off time count */
    ECAP_setAPWMCompare(EXAMPLE_ECAP, 10000U);
    /* Set eCAP APWM polarity */
    ECAP_setAPWMPolarity(EXAMPLE_ECAP, kECAP_APWM_ACTIVE_HIGH);
    /* Sets a phase shift value count */
    ECAP_setPhaseShiftCount(EXAMPLE_ECAP, 0U);
    /* Disable counter loading with phase shift value */
    ECAP_disableLoadCounter(EXAMPLE_ECAP);
    /* Configures Sync out signal mode */
    ECAP_setSyncOutMode(EXAMPLE_ECAP, kECAP_SYNC_OUT_SYNCI);
    /* Configures emulation mode */
    ECAP_setEmulationMode(EXAMPLE_ECAP, kECAP_EMULATION_STOP);
    /* Set up the source for sync-in pulse */
    ECAP_setSyncInPulseSource(EXAMPLE_ECAP, kECAP_SYNC_IN_PULSE_SRC_DISABLE);
    /* Starts Time stamp counter */
    ECAP_startCounter(EXAMPLE_ECAP);
}

int main(void)
{
    /* Board initialization */
    BOARD_init();

    /* Pinmux configuration, Pad configuration and XBAR configuration */
#if defined(BOARD_USE_CPU1)
    BOARD_ecapPinConfig(EXAMPLE_ECAP_CPU1);
#endif
#if defined(BOARD_CONFIG_CPU2)
    BOARD_ecapPinConfig(EXAMPLE_ECAP_CPU2);
    BOARD_ecapAssign2CPU2(EXAMPLE_ECAP_CPU2);
#endif

    /* Peripheral clock configuration */
    BOARD_ecapClockEnable(EXAMPLE_ECAP);
    ECAP_init();
    for (;;)
    {
        /* Set the duty cycle to 50% */
        ECAP_setAPWMShadowCompare(EXAMPLE_ECAP, (ECAP_getEventTimeStamp(EXAMPLE_ECAP, kECAP_EVENT_1) >> 1U));

        cap1Count = ECAP_getEventTimeStamp(EXAMPLE_ECAP, kECAP_EVENT_1);

        /* Vary frequency */
        if (cap1Count >= 20000000U)
        {
            direction = INCREASE_FREQUENCY;
        }
        else if (cap1Count <= 10000000U)
        {
            direction = DECREASE_FREQUENCY;
        }

        if (direction == INCREASE_FREQUENCY)
        {
            ECAP_setAPWMShadowPeriod(EXAMPLE_ECAP, (cap1Count - 500000U));
        }
        else
        {
            ECAP_setAPWMShadowPeriod(EXAMPLE_ECAP, (cap1Count + 500000U));
        }
    }
}
