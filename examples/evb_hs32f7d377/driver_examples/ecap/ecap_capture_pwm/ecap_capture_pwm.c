/*
 * Copyright 2023 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*!
 * \file ecap_capture_pwm.c
 * \brief ECAP example file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "board.h"
#include "hte_ecap.h"
#include "hte_epwm.h"
#include "hte_gpio.h"
#include "hte_sysctrl.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! \brief ECAP used by CPU1 in this example */
#define EXAMPLE_ECAP_CPU1 (ECAP1)
/*! \brief ECAP used by CPU2 in this example */
#define EXAMPLE_ECAP_CPU2 (ECAP2)
/*! \brief EPWM used by CPU1 in this example */
#define EXAMPLE_EPWM_CPU1 (EPWM10)
/*! \brief EPWM used by CPU2 in this example */
#define EXAMPLE_EPWM_CPU2 (EPWM11)
/*! \brief INPUTXBAR used by CPU1 in this example */
#define EXAMPLE_INPUTXBAR_CPU1 (kECAP_INPUT_INPUTXBAR7)
/*! \brief INPUTXBAR used by CPU2 in this example */
#define EXAMPLE_INPUTXBAR_CPU2 (kECAP_INPUT_INPUTXBAR8)

/*! \brief LED instance used by CPU1 in this example */
#define EXAMPLE_LED_INSTANCE_CPU1 (1U)
/*! \brief GPIO used by CPU1 to control the LED in this example */
#define EXAMPLE_LED_GPIO_CPU1 (BOARD_GPIO_LED1)
/*! \brief LED instance used by CPU2 in this example */
#define EXAMPLE_LED_INSTANCE_CPU2 (2U)
/*! \brief GPIO used by CPU2 to control the LED in this example */
#define EXAMPLE_LED_GPIO_CPU2 (BOARD_GPIO_LED2)

#if defined(BOARD_USE_CPU1)
/*! \brief ECAP used in this example */
#define EXAMPLE_ECAP (EXAMPLE_ECAP_CPU1)
/*! \brief EPWM used in this example */
#define EXAMPLE_EPWM (EXAMPLE_EPWM_CPU1)
/*! \brief INPUTXBAR used in this example */
#define EXAMPLE_INPUTXBAR (EXAMPLE_INPUTXBAR_CPU1)
/*! \brief GPIO used to control the LED in this example */
#define EXAMPLE_LED_GPIO (EXAMPLE_LED_GPIO_CPU1)
#elif defined(BOARD_USE_CPU2)
/*! \brief ECAP used in this example */
#define EXAMPLE_ECAP      (EXAMPLE_ECAP_CPU2)
/*! \brief EPWM used in this example */
#define EXAMPLE_EPWM      (EXAMPLE_EPWM_CPU2)
/*! \brief INPUTXBAR used in this example */
#define EXAMPLE_INPUTXBAR (EXAMPLE_INPUTXBAR_CPU2)
/*! \brief GPIO used to control the LED in this example */
#define EXAMPLE_LED_GPIO  (EXAMPLE_LED_GPIO_CPU2)
#endif

/*! \brief EPWM timer period count configuration */
#define EPWM_TIMER_TBPRD (12000U)
/*! \brief EPWM counter compare A configuration */
#define EPWM_CMPA_VALUE (3000U)
/*! \brief EPWM counter compare B configuration */
#define EPWM_CMPB_VALUE   (EPWM_TIMER_TBPRD - EPWM_CMPA_VALUE)

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/* No Prototypes */

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! \brief Current time stamp count of EVENT2 */
volatile uint32_t cap2Count;
/*! \brief Current time stamp count of EVENT3 */
volatile uint32_t cap3Count;
/*! \brief Current time stamp count of EVENT4 */
volatile uint32_t cap4Count;
/*******************************************************************************
 * Codes
 ******************************************************************************/
static void Error_Handler(void)
{
    while (1)
    {
        GPIO_togglePin(EXAMPLE_LED_GPIO);
        DELAY(100000);
    }
}

static void EPWM_init()
{
    /* Sets EPWM counter compare B value */
    EPWM_setCounterCompareValue(EXAMPLE_EPWM, EPWM_COUNTER_COMPARE_B, EPWM_CMPB_VALUE);
    /* Sets EPWM counter compare A value */
    EPWM_setCounterCompareValue(EXAMPLE_EPWM, EPWM_COUNTER_COMPARE_A, EPWM_CMPA_VALUE);
    /* Sets up Action qualifier outputs */
    EPWM_setActionQualifierAction(EXAMPLE_EPWM, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    EPWM_setActionQualifierAction(EXAMPLE_EPWM, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(EXAMPLE_EPWM, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    EPWM_setActionQualifierAction(EXAMPLE_EPWM, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    /* Sets the PWM period count */
    EPWM_setTimeBasePeriod(EXAMPLE_EPWM, EPWM_TIMER_TBPRD);
    /* Sets time base counter mode */
    EPWM_setTimeBaseCounterMode(EXAMPLE_EPWM, EPWM_COUNTER_MODE_UP);
}
void ECAP_init()
{
    /* Disables time stamp capture */
    ECAP_disableTimeStampCapture(EXAMPLE_ECAP);
    /* Stops Time stamp counter */
    ECAP_stopCounter(EXAMPLE_ECAP);
    /* Sets eCAP in Capture mode */
    ECAP_enableCaptureMode(EXAMPLE_ECAP);
    /* Sets the capture mode */
    ECAP_setCaptureMode(EXAMPLE_ECAP, kECAP_CONTINUOUS_CAPTURE_MODE, kECAP_EVENT_4);
    /* Sets the Capture event prescaler */
    ECAP_setEventPrescaler(EXAMPLE_ECAP, 0U);
    /* Sets the Capture event1 polarity */
    ECAP_setEventPolarity(EXAMPLE_ECAP, kECAP_EVENT_1, kECAP_EVNT_FALLING_EDGE);
    /* Sets the Capture event2 polarity */
    ECAP_setEventPolarity(EXAMPLE_ECAP, kECAP_EVENT_2, kECAP_EVNT_RISING_EDGE);
    /* Sets the Capture event3 polarity */
    ECAP_setEventPolarity(EXAMPLE_ECAP, kECAP_EVENT_3, kECAP_EVNT_FALLING_EDGE);
    /* Sets the Capture event4 polarity */
    ECAP_setEventPolarity(EXAMPLE_ECAP, kECAP_EVENT_4, kECAP_EVNT_RISING_EDGE);
    /* Configure counter reset on event1 */
    ECAP_enableCounterResetOnEvent(EXAMPLE_ECAP, kECAP_EVENT_1);
    /* Configure counter reset on event2 */
    ECAP_enableCounterResetOnEvent(EXAMPLE_ECAP, kECAP_EVENT_2);
    /* Configure counter reset on event3 */
    ECAP_enableCounterResetOnEvent(EXAMPLE_ECAP, kECAP_EVENT_3);
    /* Configure counter reset on event4 */
    ECAP_enableCounterResetOnEvent(EXAMPLE_ECAP, kECAP_EVENT_4);
    /* Select eCAP input */
    ECAP_selectECAPInput(EXAMPLE_ECAP, EXAMPLE_INPUTXBAR);
    /* Sets a phase shift value count */
    ECAP_setPhaseShiftCount(EXAMPLE_ECAP, 0U);
    /* Enable counter loading with phase shift value */
    ECAP_enableLoadCounter(EXAMPLE_ECAP);
    /* Configures Sync out signal mode */
    ECAP_setSyncOutMode(EXAMPLE_ECAP, kECAP_SYNC_OUT_SYNCI);
    /* Configures emulation mode */
    ECAP_setEmulationMode(EXAMPLE_ECAP, kECAP_EMULATION_STOP);
    /* Set up the source for sync-in pulse */
    ECAP_setSyncInPulseSource(EXAMPLE_ECAP, kECAP_SYNC_IN_PULSE_SRC_DISABLE);
    /* Starts Time stamp counter for EXAMPLE_ECAP */
    ECAP_startCounter(EXAMPLE_ECAP);
    /* Enables time stamp capture for EXAMPLE_ECAP */
    ECAP_enableTimeStampCapture(EXAMPLE_ECAP);
    /* Re-arms the eCAP module for EXAMPLE_ECAP */
    ECAP_reArm(EXAMPLE_ECAP);
}

int main(void)
{
    /* Board initialization */
    BOARD_init();

    /* Pinmux configuration, Pad configuration and XBAR configuration */
#if defined(BOARD_USE_CPU1)
    BOARD_ecapPinConfig(EXAMPLE_ECAP_CPU1);
    BOARD_epwmPinConfig(EXAMPLE_EPWM_CPU1);
    BOARD_ledPinConfig(EXAMPLE_LED_INSTANCE_CPU1);
    /* Configure LED GPIO as output */
    GPIO_setDirectionMode(EXAMPLE_LED_GPIO_CPU1, kGPIO_DIR_OUTPUT);
#endif
#if defined(BOARD_CONFIG_CPU2)
    /* Pinmux configuration and Pad configuration */
    BOARD_ecapPinConfig(EXAMPLE_ECAP_CPU2);
    BOARD_epwmPinConfig(EXAMPLE_EPWM_CPU2);
    BOARD_ecapAssign2CPU2(EXAMPLE_ECAP_CPU2);
    BOARD_epwmAssign2CPU2(EXAMPLE_EPWM_CPU2);
    BOARD_ledPinConfig(EXAMPLE_LED_INSTANCE_CPU2);
    /* Configure LED GPIO as output */
    GPIO_setDirectionMode(EXAMPLE_LED_GPIO_CPU2, kGPIO_DIR_OUTPUT);
    /* Assign LED GPIO to CPU2 */
    GPIO_setMasterCore(EXAMPLE_LED_GPIO_CPU2, kGPIO_CORE_CPU2);
#endif

    /* Peripheral clock configuration */
    BOARD_epwmClockEnable(EXAMPLE_EPWM);
    BOARD_ecapClockEnable(EXAMPLE_ECAP);

    /* Disable the ePWM TBCLK peripheral */
    SYSCTRL_disablePeripheral(kSYSCTL_PERIPH_CLK_TBCLKSYNC);
    EPWM_init();
    /* Enable the ePWM TBCLK peripheral */
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_TBCLKSYNC);
    ECAP_init();

    DELAY(100000);

    cap2Count = ECAP_getEventTimeStamp(EXAMPLE_ECAP, kECAP_EVENT_2);
    cap3Count = ECAP_getEventTimeStamp(EXAMPLE_ECAP, kECAP_EVENT_3);
    cap4Count = ECAP_getEventTimeStamp(EXAMPLE_ECAP, kECAP_EVENT_4);

    /* Compare the period value with the captured count */
    if (cap2Count > ((EPWM_CMPA_VALUE * 2) + 2) || cap2Count < ((EPWM_CMPA_VALUE * 2) - 2))
    {
        Error_Handler();
    }

    if (cap3Count > ((EPWM_CMPB_VALUE * 2) + 2) || cap3Count < ((EPWM_CMPB_VALUE * 2) - 2))
    {
        Error_Handler();
    }

    if (cap4Count > ((EPWM_CMPA_VALUE * 2) + 2) || cap4Count < ((EPWM_CMPA_VALUE * 2) - 2))
    {
        Error_Handler();
    }
    /* Infinite loop */
    while (1)
    {
    }
}