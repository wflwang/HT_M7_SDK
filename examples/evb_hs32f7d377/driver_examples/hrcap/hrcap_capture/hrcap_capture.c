/*
 * Copyright 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*!
 * \file hrcap_capture.c
 * \brief HRCAP example file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "board.h"
#include "hte_ecap.h"
#include "hte_epwm.h"
#include "hte_gpio.h"
#include "hte_hrcap.h"
#include "hte_hrpwm.h"
#include "hte_sysctrl.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! \brief ECAP used by CPU1 in this example */
#define EXAMPLE_ECAP_CPU1 (ECAP1)
/*! \brief HRCAP used by CPU1 in this example */
#define EXAMPLE_HRCAP_CPU1 (HRCAP1)
/*! \brief ECAP used by CPU2 in this example */
#define EXAMPLE_ECAP_CPU2 (ECAP2)
/*! \brief HRCAP used by CPU2 in this example */
#define EXAMPLE_HRCAP_CPU2 (HRCAP2)
/*! \brief EPWM used by CPU1 in this example */
#define EXAMPLE_EPWM_CPU1 (EPWM7)
/*! \brief HRPWM used by CPU1 in this example */
#define EXAMPLE_HRPWM_CPU1 (HREPWM7)
/*! \brief EPWM used by CPU2 in this example */
#define EXAMPLE_EPWM_CPU2 (EPWM8)
/*! \brief HRPWM used by CPU2 in this example */
#define EXAMPLE_HRPWM_CPU2 (HREPWM8)
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
/*! \brief HRCAP used in this example */
#define EXAMPLE_HRCAP (EXAMPLE_HRCAP_CPU1)
/*! \brief EPWM used in this example */
#define EXAMPLE_EPWM (EXAMPLE_EPWM_CPU1)
/*! \brief HRPWM used in this example */
#define EXAMPLE_HRPWM (EXAMPLE_HRPWM_CPU1)
/*! \brief INPUTXBAR used in this example */
#define EXAMPLE_INPUTXBAR (EXAMPLE_INPUTXBAR_CPU1)
/*! \brief GPIO used to control the LED in this example */
#define EXAMPLE_LED_GPIO (EXAMPLE_LED_GPIO_CPU1)
#elif defined(BOARD_USE_CPU2)
/*! \brief ECAP used in this example */
#define EXAMPLE_ECAP      (EXAMPLE_ECAP_CPU2)
/*! \brief HRCAP used in this example */
#define EXAMPLE_HRCAP     (EXAMPLE_HRCAP_CPU2)
/*! \brief EPWM used in this example */
#define EXAMPLE_EPWM      (EXAMPLE_EPWM_CPU2)
/*! \brief HRPWM used in this example */
#define EXAMPLE_HRPWM     (EXAMPLE_HRPWM_CPU2)
/*! \brief INPUTXBAR used in this example */
#define EXAMPLE_INPUTXBAR (EXAMPLE_INPUTXBAR_CPU2)
/*! \brief GPIO used to control the LED in this example */
#define EXAMPLE_LED_GPIO  (EXAMPLE_LED_GPIO_CPU2)
#endif

/*! \brief EPWM timer period count configuration */
#define EPWM_TIMER_TBPRD (2999U)
/*! \brief EPWM counter compare A configuration */
#define EPWM_CMPA_VALUE (999U)
/*! \brief EPWM counter compare B configuration */
#define EPWM_CMPB_VALUE  (EPWM_TIMER_TBPRD - EPWM_CMPA_VALUE)

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/* No Prototypes */

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! \brief Time stamp count of events */
uint32_t capCount[4];
/*! \brief Time stamp in ns of events */
double   absTime[4];
/*! \brief Time stamp after calibration in ns of events */
double   absTimeAfterHr[4];
/*! \brief Calibration value in ns of events */
double   fractionalTime[4];
/*! \brief Ontime in ns of captured signal */
double   onTime1 = 0, onTime2 = 0;
/*! \brief Offtime in ns of captured signal */
double   offTime1 = 0, offTime2 = 0;
/*! \brief Period in ns of captured signal */
double   period1 = 0, period2 = 0;
/*! \brief Upper 32-bit value of HRCAP capdata */
uint32_t hrcap_capdataH[4];
/*! \brief Lower 32-bit value of HRCAP capdata */
uint32_t hrcap_capdataL[4];
/*! \brief Upper 32-bit value of HRCAP calidata */
uint32_t hrcap_calidataH[4];
/*! \brief Lower 32-bit value of HRCAP calidata */
uint32_t hrcap_calidataL[4];
/*! \brief Number of 1 or 0 in HRCAP capdata value */
uint8_t  hrcap_capCount[4];
/*! \brief Number of 1 in HRCAP calidata value */
uint8_t  hrcap_caliCount[4];

/*******************************************************************************
 * Codes
 ******************************************************************************/

static uint32_t countOneBits(uint32_t value)
{
    uint32_t count = 0;
    while (value)
    {
        value &= (value - 1);
        count++;
    }
    return count;
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
    EPWM_setActionQualifierAction(EXAMPLE_EPWM, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    EPWM_setActionQualifierAction(EXAMPLE_EPWM, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    EPWM_setActionQualifierAction(EXAMPLE_EPWM, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    /* Set the time base clock and the high speed time base clock count pre-scaler */
    EPWM_setClockPrescaler(EXAMPLE_EPWM, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);
    /* Sets the PWM period count */
    EPWM_setTimeBasePeriod(EXAMPLE_EPWM, EPWM_TIMER_TBPRD);
    /* Sets time base counter mode */
    EPWM_setTimeBaseCounterMode(EXAMPLE_EPWM, EPWM_COUNTER_MODE_UP);
    /* Sets HRCAL Update Mode */
    HRCAL_setUpdataMode(HRCAL, HRCAL_COUNTER_MODE);
    /* Sets HRCAL Counter Period */
    HRCAL_setCounterPeriod(HRCAL, 1499999999);
    /* Selects HRCAL Accumulator Bit Width */
    HRCAL_selectAccumulatorBitWidth(HRCAL, HRCAL_SELECT_7_TO_14_BITS);
    /* Enables HRCAL Step Value Adjustment */
    HRCAL_enableStepValueAdjustment(HRCAL);
    /* Sets HRCAL Data Storage Number */
    HRCAL_setDataStorageNumber(HRCAL, HRCAL_STORAGE_32_DATA);
    /* Sets HRCAL Threshold Value */
    HRCAL_setThresholdValue(HRCAL, 2);
    /* Enables HRCAL Calibration Interrupt */
    HRCAL_enableCalibrationInt(HRCAL);
    /* Enables HRCAL Calibration Interrupt */
    HRCAL_enableCalibration(HRCAL);
    /* Waits for HRCAL Calibration to Complete */
    HRCAL_waitCalibrationCompelet(HRCAL);
    /* Disables MEP automatic scale mode */
    HRPWM_disableAutoConversion(EXAMPLE_HRPWM);
    /* Sets the high resolution edge controlled by MEP (Micro Edge Positioner) */
    HRPWM_setMEPEdgeSelect(EXAMPLE_HRPWM, HRPWM_CHANNEL_A, HRPWM_MEP_CTRL_RISING_EDGE);
    /* Sets the consolidated RED count in high resolution mode */
    HRPWM_setRisingEdgeDelay(EXAMPLE_HRPWM, HRPWM_CHANNEL_A, 0);

    /* Enable the ePWM TBCLK peripheral */
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_TBCLKSYNC);
}

void ECAP_init()
{
    /* Clear all capture flags and interrupts */
    ECAP_clearInterrupt(EXAMPLE_ECAP, (ECAP_ISR_SOURCE_CAPTURE_EVENT_1 | ECAP_ISR_SOURCE_CAPTURE_EVENT_2 |
                                       ECAP_ISR_SOURCE_CAPTURE_EVENT_3 | ECAP_ISR_SOURCE_CAPTURE_EVENT_4 |
                                       ECAP_ISR_SOURCE_COUNTER_OVERFLOW | ECAP_ISR_SOURCE_COUNTER_PERIOD |
                                       ECAP_ISR_SOURCE_COUNTER_COMPARE));
    /* Disables time stamp capture */
    ECAP_disableTimeStampCapture(EXAMPLE_ECAP);
    /* Stops Time stamp counter */
    ECAP_stopCounter(EXAMPLE_ECAP);
    /* Sets eCAP in Capture mode */
    ECAP_enableCaptureMode(EXAMPLE_ECAP);
    /* Sets the capture mode */
    ECAP_setCaptureMode(EXAMPLE_ECAP, kECAP_ONE_SHOT_CAPTURE_MODE, kECAP_EVENT_4);
    /* Sets the Capture event prescaler */
    ECAP_setEventPrescaler(EXAMPLE_ECAP, 0U);
    /* Sets the Capture event1 polarity */
    ECAP_setEventPolarity(EXAMPLE_ECAP, kECAP_EVENT_1, kECAP_EVNT_RISING_EDGE);
    /* Sets the Capture event2 polarity */
    ECAP_setEventPolarity(EXAMPLE_ECAP, kECAP_EVENT_2, kECAP_EVNT_FALLING_EDGE);
    /* Sets the Capture event3 polarity */
    ECAP_setEventPolarity(EXAMPLE_ECAP, kECAP_EVENT_3, kECAP_EVNT_RISING_EDGE);
    /* Sets the Capture event4 polarity */
    ECAP_setEventPolarity(EXAMPLE_ECAP, kECAP_EVENT_4, kECAP_EVNT_FALLING_EDGE);
    /* Configure counter reset on event1 */
    ECAP_disableCounterResetOnEvent(EXAMPLE_ECAP, kECAP_EVENT_1);
    /* Configure counter reset on event2 */
    ECAP_disableCounterResetOnEvent(EXAMPLE_ECAP, kECAP_EVENT_2);
    /* Configure counter reset on event3 */
    ECAP_disableCounterResetOnEvent(EXAMPLE_ECAP, kECAP_EVENT_3);
    /* Configure counter reset on event4 */
    ECAP_disableCounterResetOnEvent(EXAMPLE_ECAP, kECAP_EVENT_4);
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
    /* Configure in auto calibration mode */
    HRCAP_setCalibrationMode(EXAMPLE_HRCAP, kHRCAP_AUTO);
    /* Start HR calibration */
    HRCAP_enableCalibration(EXAMPLE_HRCAP);
    /* Enable High resolution module */
    HRCAP_enableHighResolution(EXAMPLE_HRCAP);
    /* Re-arms the eCAP module for EXAMPLE_ECAP */
    ECAP_reArm(EXAMPLE_ECAP);
}

int main(void)
{
    /* Board initialization */
    BOARD_init();

    /* Pinmux configuration, Pad configuration and XBAR configuration*/
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

    EPWM_init();
    ECAP_init();

    while (!(ECAP_getInterruptSource(EXAMPLE_ECAP) & ECAP_ISR_SOURCE_CAPTURE_EVENT_1))
        ;
    hrcap_capdataL[0]  = HRCAP_getCapDataL(EXAMPLE_HRCAP);
    hrcap_capdataH[0]  = HRCAP_getCapDataH(EXAMPLE_HRCAP);
    hrcap_calidataH[0] = HRCAP_getCaliDataL(EXAMPLE_HRCAP);
    hrcap_calidataL[0] = HRCAP_getCaliDataH(EXAMPLE_HRCAP);

    while (!(ECAP_getInterruptSource(EXAMPLE_ECAP) & ECAP_ISR_SOURCE_CAPTURE_EVENT_2))
        ;
    hrcap_capdataL[1]  = HRCAP_getCapDataL(EXAMPLE_HRCAP);
    hrcap_capdataH[1]  = HRCAP_getCapDataH(EXAMPLE_HRCAP);
    hrcap_calidataH[1] = HRCAP_getCaliDataL(EXAMPLE_HRCAP);
    hrcap_calidataL[1] = HRCAP_getCaliDataH(EXAMPLE_HRCAP);

    while (!(ECAP_getInterruptSource(EXAMPLE_ECAP) & ECAP_ISR_SOURCE_CAPTURE_EVENT_3))
        ;
    hrcap_capdataL[2]  = HRCAP_getCapDataL(EXAMPLE_HRCAP);
    hrcap_capdataH[2]  = HRCAP_getCapDataH(EXAMPLE_HRCAP);
    hrcap_calidataH[2] = HRCAP_getCaliDataL(EXAMPLE_HRCAP);
    hrcap_calidataL[2] = HRCAP_getCaliDataH(EXAMPLE_HRCAP);

    while (!(ECAP_getInterruptSource(EXAMPLE_ECAP) & ECAP_ISR_SOURCE_CAPTURE_EVENT_4))
        ;
    hrcap_capdataL[3]  = HRCAP_getCapDataL(EXAMPLE_HRCAP);
    hrcap_capdataH[3]  = HRCAP_getCapDataH(EXAMPLE_HRCAP);
    hrcap_calidataH[3] = HRCAP_getCaliDataL(EXAMPLE_HRCAP);
    hrcap_calidataL[3] = HRCAP_getCaliDataH(EXAMPLE_HRCAP);

    capCount[0] = ECAP_getEventTimeStamp(EXAMPLE_ECAP, kECAP_EVENT_1);
    capCount[1] = ECAP_getEventTimeStamp(EXAMPLE_ECAP, kECAP_EVENT_2);
    capCount[2] = ECAP_getEventTimeStamp(EXAMPLE_ECAP, kECAP_EVENT_3);
    capCount[3] = ECAP_getEventTimeStamp(EXAMPLE_ECAP, kECAP_EVENT_4);

    for (int i = 0; i < 4; i++)
    {
        hrcap_caliCount[i] = countOneBits(hrcap_calidataH[i]) + countOneBits(hrcap_calidataL[i]);
        hrcap_capCount[i]  = countOneBits(hrcap_capdataH[i]) + countOneBits(hrcap_capdataL[i]);
        hrcap_capCount[i]  = ((i == 0 || i == 2) ? hrcap_capCount[i] : (64 - hrcap_capCount[i]));
        fractionalTime[i]  = ((double)hrcap_capCount[i] / (BOARD_getSysclk() * hrcap_caliCount[i])) * 1000000000;
        fractionalTime[i]  = (fractionalTime[i] >= 3.3) ? 0 : fractionalTime[i];
        absTime[i]         = capCount[i] / BOARD_getSysclk() * 1000000000;
        absTimeAfterHr[i]  = absTime[i] - fractionalTime[i];
    }

    onTime1  = absTimeAfterHr[1] - absTimeAfterHr[0];
    offTime1 = absTimeAfterHr[2] - absTimeAfterHr[1];
    period1  = absTimeAfterHr[2] - absTimeAfterHr[0];

    onTime2  = absTimeAfterHr[3] - absTimeAfterHr[2];
    offTime2 = absTimeAfterHr[2] - absTimeAfterHr[1];
    period2  = absTimeAfterHr[3] - absTimeAfterHr[1];

    /* Infinite loop */
    while (1)
    {
    }
}
