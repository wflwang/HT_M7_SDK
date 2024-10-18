/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_ecap.h
 * \brief SDK ECAP driver header file
 * \version 1.0.0
 */

#ifndef HTE_ECAP_H
#define HTE_ECAP_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_common.h"

/*!
 * \addtogroup DRV_HTE_ECAP ECAP Driver
 *
 * \brief SDK ECAP driver
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! \brief eCAP minimum and maximum values */
#define ECAP_MAX_PRESCALER_VALUE 32U /*!< Maximum Pre-scaler value */

/*!
 * \brief Values that can be passed to ECAP_enableInterrupt(),
 * ECAP_disableInterrupt(), ECAP_clearInterrupt() and ECAP_forceInterrupt() as
 * the intFlags parameter and returned by ECAP_getInterruptSource().
 */
#define ECAP_ISR_SOURCE_CAPTURE_EVENT_1  0x2U  /*!< Event 1 ISR source */
#define ECAP_ISR_SOURCE_CAPTURE_EVENT_2  0x4U  /*!< Event 2 ISR source */
#define ECAP_ISR_SOURCE_CAPTURE_EVENT_3  0x8U  /*!< Event 3 ISR source */
#define ECAP_ISR_SOURCE_CAPTURE_EVENT_4  0x10U /*!< Event 4 ISR source */
#define ECAP_ISR_SOURCE_COUNTER_OVERFLOW 0x20U /*!< Counter overflow ISR source */
#define ECAP_ISR_SOURCE_COUNTER_PERIOD   0x40U /*!< Counter equals period ISR source */
#define ECAP_ISR_SOURCE_COUNTER_COMPARE  0x80U /*!< Counter equals compare ISR source */

/*!
 * \brief Values that can be passed to ECAP_setEmulationMode() as the
 * \e mode parameter.
 */
typedef enum
{
    kECAP_EMULATION_STOP        = 0x0U, /*!< TSCTR is stopped on emulation suspension */
    kECAP_EMULATION_RUN_TO_ZERO = 0x1U, /*!< TSCTR runs until 0 before stopping on emulation suspension */
    kECAP_EMULATION_FREE_RUN    = 0x2U  /*!< TSCTR is not affected by emulation suspension */
} ECAP_EmulationMode_t;

/*!
 * \brief Values that can be passed to ECAP_setCaptureMode() as the
 * \e mode parameter.
 */
typedef enum
{
    kECAP_CONTINUOUS_CAPTURE_MODE = 0U, /*!< eCAP operates in continuous capture mode */
    kECAP_ONE_SHOT_CAPTURE_MODE   = 1U  /*!< eCAP operates in one shot capture mode */
} ECAP_CaptureMode_t;

/*!
 * \brief Values that can be passed to ECAP_setEventPolarity(),ECAP_setCaptureMode(),
 * ECAP_enableCounterResetOnEvent(),ECAP_disableCounterResetOnEvent(),
 * ECAP_getEventTimeStamp(),ECAP_setDMASource() as the \e event parameter.
 */
typedef enum
{
    kECAP_EVENT_1 = 0U, /*!< eCAP event 1 */
    kECAP_EVENT_2 = 1U, /*!< eCAP event 2 */
    kECAP_EVENT_3 = 2U, /*!< eCAP event 3 */
    kECAP_EVENT_4 = 3U  /*!< eCAP event 4 */
} ECAP_Events_t;

/*!
 * Values that can be passed to ECAP_setSyncOutMode() as the \e mode
 * parameter.
 */
typedef enum
{
    kECAP_SYNC_OUT_SYNCI       = 0x00U, /*!< sync out on the sync in signal and software force */
    kECAP_SYNC_OUT_COUNTER_PRD = 0x40U, /*!< sync out on counter equals period */
    kECAP_SYNC_OUT_DISABLED    = 0x80U  /*!< Disable sync out signal */
} ECAP_SyncOutMode_t;

/*!
 * Values that can be passed to ECAP_setAPWMPolarity() as the \e polarity
 * parameter.
 */
typedef enum
{
    kECAP_APWM_ACTIVE_HIGH = 0x000U, /*!< APWM is active high */
    kECAP_APWM_ACTIVE_LOW  = 0x400U  /*!< APWM is active low */
} ECAP_APWMPolarity_t;

/*!
 * Values that can be passed to ECAP_setEventPolarity() as the \e polarity
 * parameter.
 */
typedef enum
{
    kECAP_EVNT_RISING_EDGE  = 0U, /*!< Rising edge polarity */
    kECAP_EVNT_FALLING_EDGE = 1U  /*!< Falling edge polarity */
} ECAP_EventPolarity_t;

/*!
 * Values that can be passed to ECAP_selectECAPInput() as the \e input
 * parameter.
 */
typedef enum
{
    kECAP_INPUT_INPUTXBAR1                     = 0,   /*!< GPIO Input Crossbar output signal-1 */
    kECAP_INPUT_INPUTXBAR2                     = 1,   /*!< GPIO Input Crossbar output signal-2 */
    kECAP_INPUT_INPUTXBAR3                     = 2,   /*!< GPIO Input Crossbar output signal-3 */
    kECAP_INPUT_INPUTXBAR4                     = 3,   /*!< GPIO Input Crossbar output signal-4 */
    kECAP_INPUT_INPUTXBAR5                     = 4,   /*!< GPIO Input Crossbar output signal-5 */
    kECAP_INPUT_INPUTXBAR6                     = 5,   /*!< GPIO Input Crossbar output signal-6 */
    kECAP_INPUT_INPUTXBAR7                     = 6,   /*!< GPIO Input Crossbar output signal-7 */
    kECAP_INPUT_INPUTXBAR8                     = 7,   /*!< GPIO Input Crossbar output signal-8 */
    kECAP_INPUT_INPUTXBAR9                     = 8,   /*!< GPIO Input Crossbar output signal-9 */
    kECAP_INPUT_INPUTXBAR10                    = 9,   /*!< GPIO Input Crossbar output signal-10 */
    kECAP_INPUT_INPUTXBAR11                    = 10,  /*!< GPIO Input Crossbar output signal-11 */
    kECAP_INPUT_INPUTXBAR12                    = 11,  /*!< GPIO Input Crossbar output signal-12 */
    kECAP_INPUT_INPUTXBAR13                    = 12,  /*!< GPIO Input Crossbar output signal-13 */
    kECAP_INPUT_INPUTXBAR14                    = 13,  /*!< GPIO Input Crossbar output signal-14 */
    kECAP_INPUT_INPUTXBAR15                    = 14,  /*!< GPIO Input Crossbar output signal-15 */
    kECAP_INPUT_INPUTXBAR16                    = 15,  /*!< GPIO Input Crossbar output signal-16 */
    kECAP_INPUT_CANA_INT0                      = 20,  /*!< CANA INT0 Input */
    kECAP_INPUT_CANB_INT0                      = 21,  /*!< CANB INT0 Input */
    kECAP_INPUT_CANC_INT0                      = 22,  /*!< CANC INT0 Input */
    kECAP_INPUT_PWMXBAR1                       = 24,  /*!< PWM Xbar Output-1 */
    kECAP_INPUT_PWMXBAR2                       = 25,  /*!< PWM Xbar Output-2 */
    kECAP_INPUT_PWMXBAR3                       = 26,  /*!< PWM Xbar Output-3 */
    kECAP_INPUT_PWMXBAR4                       = 27,  /*!< PWM Xbar Output-4 */
    kECAP_INPUT_PWMXBAR5                       = 28,  /*!< PWM Xbar Output-5 */
    kECAP_INPUT_PWMXBAR6                       = 29,  /*!< PWM Xbar Output-6 */
    kECAP_INPUT_PWMXBAR7                       = 30,  /*!< PWM Xbar Output-7 */
    kECAP_INPUT_PWMXBAR8                       = 31,  /*!< PWM Xbar Output-8 */
    kECAP_INPUT_ADC_D_EVENT1                   = 32,  /*!< ADCD Event1 */
    kECAP_INPUT_ADC_D_EVENT2                   = 33,  /*!< ADCD Event2 */
    kECAP_INPUT_ADC_D_EVENT3                   = 34,  /*!< ADCD Event3 */
    kECAP_INPUT_ADC_D_EVENT4                   = 35,  /*!< ADCD Event4 */
    kECAP_INPUT_ADC_C_EVENT1                   = 36,  /*!< ADCC Event1 */
    kECAP_INPUT_ADC_C_EVENT2                   = 37,  /*!< ADCC Event2 */
    kECAP_INPUT_ADC_C_EVENT3                   = 38,  /*!< ADCC Event3 */
    kECAP_INPUT_ADC_C_EVENT4                   = 39,  /*!< ADCC Event4 */
    kECAP_INPUT_ADC_B_EVENT1                   = 40,  /*!< ADCB Event1 */
    kECAP_INPUT_ADC_B_EVENT2                   = 41,  /*!< ADCB Event2 */
    kECAP_INPUT_ADC_B_EVENT3                   = 42,  /*!< ADCB Event3 */
    kECAP_INPUT_ADC_B_EVENT4                   = 43,  /*!< ADCB Event4 */
    kECAP_INPUT_ADC_A_EVENT1                   = 44,  /*!< ADCA Event1 */
    kECAP_INPUT_ADC_A_EVENT2                   = 45,  /*!< ADCA Event2 */
    kECAP_INPUT_ADC_A_EVENT3                   = 46,  /*!< ADCA Event3 */
    kECAP_INPUT_ADC_A_EVENT4                   = 47,  /*!< ADCA Event4 */
    kECAP_INPUT_SDFM2_FLT1_COMPARE_LOW         = 60,  /*!< SDFM-2 Filter-1 Compare Low Trip */
    kECAP_INPUT_SDFM2_FLT2_COMPARE_LOW         = 61,  /*!< SDFM-2 Filter-2 Compare Low Trip */
    kECAP_INPUT_SDFM2_FLT3_COMPARE_LOW         = 62,  /*!< SDFM-2 Filter-3 Compare Low Trip */
    kECAP_INPUT_SDFM2_FLT4_COMPARE_LOW         = 63,  /*!< SDFM-2 Filter-4 Compare Low Trip */
    kECAP_INPUT_SDFM1_FLT1_COMPARE_LOW         = 64,  /*!< SDFM-1 Filter-1 Compare Low Trip */
    kECAP_INPUT_SDFM1_FLT2_COMPARE_LOW         = 65,  /*!< SDFM-1 Filter-2 Compare Low Trip */
    kECAP_INPUT_SDFM1_FLT3_COMPARE_LOW         = 66,  /*!< SDFM-1 Filter-3 Compare Low Trip */
    kECAP_INPUT_SDFM1_FLT4_COMPARE_LOW         = 67,  /*!< SDFM-1 Filter-4 Compare Low Trip */
    kECAP_INPUT_SDFM2_FLT1_COMPARE_HIGH        = 76,  /*!< SDFM-2 Filter-1 Compare High Trip */
    kECAP_INPUT_SDFM2_FLT2_COMPARE_HIGH        = 77,  /*!< SDFM-2 Filter-2 Compare High Trip */
    kECAP_INPUT_SDFM2_FLT3_COMPARE_HIGH        = 78,  /*!< SDFM-2 Filter-3 Compare High Trip */
    kECAP_INPUT_SDFM2_FLT4_COMPARE_HIGH        = 79,  /*!< SDFM-2 Filter-4 Compare High Trip */
    kECAP_INPUT_SDFM1_FLT1_COMPARE_HIGH        = 80,  /*!< SDFM-1 Filter-1 Compare High Trip */
    kECAP_INPUT_SDFM1_FLT2_COMPARE_HIGH        = 81,  /*!< SDFM-1 Filter-2 Compare High Trip */
    kECAP_INPUT_SDFM1_FLT3_COMPARE_HIGH        = 82,  /*!< SDFM-1 Filter-3 Compare High Trip */
    kECAP_INPUT_SDFM1_FLT4_COMPARE_HIGH        = 83,  /*!< SDFM-1 Filter-4 Compare High Trip */
    kECAP_INPUT_SDFM2_FLT1_COMPARE_HIGH_OR_LOW = 84,  /*!< SDFM-2 Filter-1 Compare High Trip or Low Trip */
    kECAP_INPUT_SDFM2_FLT2_COMPARE_HIGH_OR_LOW = 85,  /*!< SDFM-2 Filter-2 Compare High Trip or Low Trip */
    kECAP_INPUT_SDFM2_FLT3_COMPARE_HIGH_OR_LOW = 86,  /*!< SDFM-2 Filter-3 Compare High Trip or Low Trip */
    kECAP_INPUT_SDFM2_FLT4_COMPARE_HIGH_OR_LOW = 87,  /*!< SDFM-2 Filter-4 Compare High Trip or Low Trip */
    kECAP_INPUT_SDFM1_FLT1_COMPARE_HIGH_OR_LOW = 88,  /*!< SDFM-1 Filter-1 Compare High Trip or Low Trip */
    kECAP_INPUT_SDFM1_FLT2_COMPARE_HIGH_OR_LOW = 89,  /*!< SDFM-1 Filter-2 Compare High Trip or Low Trip */
    kECAP_INPUT_SDFM1_FLT3_COMPARE_HIGH_OR_LOW = 90,  /*!< SDFM-1 Filter-3 Compare High Trip or Low Trip */
    kECAP_INPUT_SDFM1_FLT4_COMPARE_HIGH_OR_LOW = 91,  /*!< SDFM-1 Filter-4 Compare High Trip or Low Trip */
    kECAP_INPUT_CMPSS1_CTRIP_LOW               = 96,  /*!< Compare Subsystem-1 Low Trip */
    kECAP_INPUT_CMPSS2_CTRIP_LOW               = 97,  /*!< Compare Subsystem-2 Low Trip */
    kECAP_INPUT_CMPSS3_CTRIP_LOW               = 98,  /*!< Compare Subsystem-3 Low Trip */
    kECAP_INPUT_CMPSS4_CTRIP_LOW               = 99,  /*!< Compare Subsystem-4 Low Trip */
    kECAP_INPUT_CMPSS5_CTRIP_LOW               = 100, /*!< Compare Subsystem-5 Low Trip */
    kECAP_INPUT_CMPSS6_CTRIP_LOW               = 101, /*!< Compare Subsystem-6 Low Trip */
    kECAP_INPUT_CMPSS7_CTRIP_LOW               = 102, /*!< Compare Subsystem-7 Low Trip */
    kECAP_INPUT_CMPSS8_CTRIP_LOW               = 103, /*!< Compare Subsystem-8 Low Trip */
    kECAP_INPUT_CMPSS1_CTRIP_HIGH              = 108, /*!< Compare Subsystem-1 High Trip */
    kECAP_INPUT_CMPSS2_CTRIP_HIGH              = 109, /*!< Compare Subsystem-2 High Trip */
    kECAP_INPUT_CMPSS3_CTRIP_HIGH              = 110, /*!< Compare Subsystem-3 High Trip */
    kECAP_INPUT_CMPSS4_CTRIP_HIGH              = 111, /*!< Compare Subsystem-4 High Trip */
    kECAP_INPUT_CMPSS5_CTRIP_HIGH              = 112, /*!< Compare Subsystem-5 High Trip */
    kECAP_INPUT_CMPSS6_CTRIP_HIGH              = 113, /*!< Compare Subsystem-6 High Trip */
    kECAP_INPUT_CMPSS7_CTRIP_HIGH              = 114, /*!< Compare Subsystem-7 High Trip */
    kECAP_INPUT_CMPSS8_CTRIP_HIGH              = 115, /*!< Compare Subsystem-8 High Trip */
    kECAP_INPUT_CMPSS1_CTRIP_HIGH_OR_LOW       = 120, /*!< Compare Subsystem-1 High Trip or Low Trip */
    kECAP_INPUT_CMPSS2_CTRIP_HIGH_OR_LOW       = 121, /*!< Compare Subsystem-2 High Trip or Low Trip */
    kECAP_INPUT_CMPSS3_CTRIP_HIGH_OR_LOW       = 122, /*!< Compare Subsystem-3 High Trip or Low Trip */
    kECAP_INPUT_CMPSS4_CTRIP_HIGH_OR_LOW       = 123, /*!< Compare Subsystem-4 High Trip or Low Trip */
    kECAP_INPUT_CMPSS5_CTRIP_HIGH_OR_LOW       = 124, /*!< Compare Subsystem-5 High Trip or Low Trip */
    kECAP_INPUT_CMPSS6_CTRIP_HIGH_OR_LOW       = 125, /*!< Compare Subsystem-6 High Trip or Low Trip */
    kECAP_INPUT_CMPSS7_CTRIP_HIGH_OR_LOW       = 126, /*!< Compare Subsystem-7 High Trip or Low Trip */
    kECAP_INPUT_CMPSS8_CTRIP_HIGH_OR_LOW       = 127, /*!< Compare Subsystem-8 High Trip or Low Trip */
} ECAP_InputCaptureSignals_t;

/*!
 * \brief Values that can be passed to ECAP_setSyncInPulseSource() as the \e mode
 * parameter.
 */
typedef enum
{
    kECAP_SYNC_IN_PULSE_SRC_DISABLE         = 0x0,  /*!< Disable Sync-in */
    kECAP_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM1   = 0x1,  /*!< Sync-in source is EPWM1 sync-out signal */
    kECAP_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM2   = 0x2,  /*!< Sync-in source is EPWM2 sync-out signal */
    kECAP_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM3   = 0x3,  /*!< Sync-in source is EPWM3 sync-out signal */
    kECAP_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM4   = 0x4,  /*!< Sync-in source is EPWM4 sync-out signal */
    kECAP_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM5   = 0x5,  /*!< Sync-in source is EPWM5 sync-out signal */
    kECAP_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM6   = 0x6,  /*!< Sync-in source is EPWM6 sync-out signal */
    kECAP_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM7   = 0x7,  /*!< Sync-in source is EPWM7 sync-out signal */
    kECAP_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM8   = 0x8,  /*!< Sync-in source is EPWM8 sync-out signal */
    kECAP_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM9   = 0x9,  /*!< Sync-in source is EPWM9 sync-out signal */
    kECAP_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM10  = 0xA,  /*!< Sync-in source is EPWM10 sync-out signal */
    kECAP_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM11  = 0xB,  /*!< Sync-in source is EPWM11 sync-out signal */
    kECAP_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM12  = 0xC,  /*!< Sync-in source is EPWM12 sync-out signal */
    kECAP_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP1   = 0x11, /*!< Sync-in source is ECAP1 sync-out signal */
    kECAP_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP2   = 0x12, /*!< Sync-in source is ECAP2 sync-out signal */
    kECAP_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP3   = 0x13, /*!< Sync-in source is ECAP3 sync-out signal */
    kECAP_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP4   = 0x14, /*!< Sync-in source is ECAP4 sync-out signal */
    kECAP_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP5   = 0x15, /*!< Sync-in source is ECAP5 sync-out signal */
    kECAP_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP6   = 0x16, /*!< Sync-in source is ECAP6 sync-out signal */
    kECAP_SYNC_IN_PULSE_SRC_INPUTXBAR_OUT5  = 0x18, /*!< Sync-in source is Input XBAR out5 signal */
    kECAP_SYNC_IN_PULSE_SRC_INPUTXBAR_OUT6  = 0x19, /*!< Sync-in source is Input XBAR out6 signal */
} ECAP_SyncInPulseSource_t;

/*******************************************************************************
 * APIs
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Checks eCAP base address.
 *
 * \details This function determines if an eCAP module base address is valid.
 *
 * \param[in] base specifies the eCAP module base address.
 *
 * \return true if the base address is valid, false if the base address is invalid.
 */
static inline bool ECAP_isBaseValid(ECAP_Type *base)
{
    return ((base == ECAP1) || (base == ECAP2) || (base == ECAP3) || (base == ECAP4) || (base == ECAP5) ||
            (base == ECAP6));
}

/*!
 * \brief Sets the input prescaler.
 *
 * \details This function divides the ECAP input scaler. The pre scale value is
 * doubled inside the module. For example a preScalerValue of 5 will divide
 * the scaler by 10. Use a value of 1 to divide the pre scaler by 1.
 * The preScalerValue should be less than ECAP_MAX_PRESCALER_VALUE.
 *
 * \param[in] base is the base address of the ECAP module.
 * \param[in] preScalerValue is the pre scaler value for ECAP input
 *
 */
static inline void ECAP_setEventPrescaler(ECAP_Type *base, uint16_t preScalerValue)
{
    assert(ECAP_isBaseValid(base));
    assert(preScalerValue < ECAP_MAX_PRESCALER_VALUE);

    /* Write to PRESCALE bit */
    base->ECCTL1 = ((base->ECCTL1) & (~ECAP_ECCTL1_PRESCALE_Msk)) | (preScalerValue << ECAP_ECCTL1_PRESCALE_Pos);
}

/*!
 * \brief Sets the Capture event polarity.
 *
 * \details This function sets the polarity of a given event. The value of event
 * is between kECAP_EVENT_1 and kECAP_EVENT_4 inclusive corresponding to
 * the four available events.For each event the polarity value determines the
 * edge on which the capture is activated. For a rising edge use a polarity
 * value of kECAP_EVNT_RISING_EDGE and for a falling edge use a polarity of
 * kECAP_EVNT_FALLING_EDGE.
 *
 * \param[in] base is the base address of the ECAP module.
 * \param[in] event is the event number.
 * \param[in] polarity is the polarity of the event.
 *
 */
static inline void ECAP_setEventPolarity(ECAP_Type *base, ECAP_Events_t event, ECAP_EventPolarity_t polarity)
{
    uint16_t shift;

    assert(ECAP_isBaseValid(base));

    shift = ((uint16_t)event) << 1U;

    /* Write to CAP1POL, CAP2POL, CAP3POL or CAP4POL */
    base->ECCTL1 = ((base->ECCTL1) & ~(1U << shift)) | ((uint16_t)polarity << shift);
}

/*!
 * \brief Sets the capture mode.
 *
 * \details This function sets the eCAP module to a continuous or one-shot mode.
 *
 * \param[in] base is the base address of the ECAP module.
 * \param[in] mode is the capture mode.
 * \param[in] event is the event number at which the counter stops or wraps.
 *
 */
static inline void ECAP_setCaptureMode(ECAP_Type *base, ECAP_CaptureMode_t mode, ECAP_Events_t event)
{
    assert(ECAP_isBaseValid(base));

    /* Write to CONT/ONESHT */
    base->ECCTL2 = ((base->ECCTL2) & (~ECAP_ECCTL2_CONT_ONESHT_Msk)) | (uint16_t)mode;

    /* Write to STOP_WRAP */
    base->ECCTL2 = ((base->ECCTL2) & (~ECAP_ECCTL2_STOP_WRAP_Msk)) | (((uint16_t)event) << ECAP_ECCTL2_STOP_WRAP_Pos);
}

/*!
 * \brief Re-arms the eCAP module.
 *
 * \details This function re-arms the eCAP module.
 *
 * \param[in] base is the base address of the ECAP module.
 *
 */
static inline void ECAP_reArm(ECAP_Type *base)
{
    assert(ECAP_isBaseValid(base));

    /* Write to RE-ARM bit */
    base->ECCTL2 |= ECAP_ECCTL2_REARM_Set(1);
}

/*!
 * \brief Enables interrupt source.
 *
 * \details This function sets and enables eCAP interrupt source. The following are
 * valid interrupt sources.
 *  - ECAP_ISR_SOURCE_CAPTURE_EVENT_1 - Event 1 generates interrupt
 *  - ECAP_ISR_SOURCE_CAPTURE_EVENT_2 - Event 2 generates interrupt
 *  - ECAP_ISR_SOURCE_CAPTURE_EVENT_3 - Event 3 generates interrupt
 *  - ECAP_ISR_SOURCE_CAPTURE_EVENT_4 - Event 4 generates interrupt
 *  - ECAP_ISR_SOURCE_COUNTER_OVERFLOW - Counter overflow generates interrupt
 *  - ECAP_ISR_SOURCE_COUNTER_PERIOD   - Counter equal period generates
 *                                       interrupt
 *  - ECAP_ISR_SOURCE_COUNTER_COMPARE  - Counter equal compare generates
 *                                       interrupt
 *
 * \param[in] base is the base address of the ECAP module.
 * \param[in] intFlags is the interrupt source to be enabled.
 */
static inline void ECAP_enableInterrupt(ECAP_Type *base, uint16_t intFlags)
{
    assert(ECAP_isBaseValid(base));
    assert((intFlags &
            ~(ECAP_ISR_SOURCE_CAPTURE_EVENT_1 | ECAP_ISR_SOURCE_CAPTURE_EVENT_2 | ECAP_ISR_SOURCE_CAPTURE_EVENT_3 |
              ECAP_ISR_SOURCE_CAPTURE_EVENT_4 | ECAP_ISR_SOURCE_COUNTER_OVERFLOW | ECAP_ISR_SOURCE_COUNTER_PERIOD |
              ECAP_ISR_SOURCE_COUNTER_COMPARE)) == 0U);

    /* Set bits in ECEINT register */
    base->ECEINT |= intFlags;
}

/*!
 * \brief Disables interrupt source.
 *
 * \details This function clears and disables eCAP interrupt source. The following are
 * valid interrupt sources.
 *  - ECAP_ISR_SOURCE_CAPTURE_EVENT_1   - Event 1 generates interrupt
 *  - ECAP_ISR_SOURCE_CAPTURE_EVENT_2   - Event 2 generates interrupt
 *  - ECAP_ISR_SOURCE_CAPTURE_EVENT_3   - Event 3 generates interrupt
 *  - ECAP_ISR_SOURCE_CAPTURE_EVENT_4   - Event 4 generates interrupt
 *  - ECAP_ISR_SOURCE_COUNTER_OVERFLOW  - Counter overflow generates interrupt
 *  - ECAP_ISR_SOURCE_COUNTER_PERIOD    - Counter equal period generates
 *                                        interrupt
 *  - ECAP_ISR_SOURCE_COUNTER_COMPARE   - Counter equal compare generates
 *                                        interrupt
 *
 * \param[in] base is the base address of the ECAP module.
 * \param[in] intFlags is the interrupt source to be disabled.
 *
 */
static inline void ECAP_disableInterrupt(ECAP_Type *base, uint16_t intFlags)
{
    assert(ECAP_isBaseValid(base));
    assert((intFlags &
            ~(ECAP_ISR_SOURCE_CAPTURE_EVENT_1 | ECAP_ISR_SOURCE_CAPTURE_EVENT_2 | ECAP_ISR_SOURCE_CAPTURE_EVENT_3 |
              ECAP_ISR_SOURCE_CAPTURE_EVENT_4 | ECAP_ISR_SOURCE_COUNTER_OVERFLOW | ECAP_ISR_SOURCE_COUNTER_PERIOD |
              ECAP_ISR_SOURCE_COUNTER_COMPARE)) == 0U);

    /* Clear bits in ECEINT register */
    base->ECEINT &= ~intFlags;
}

/*!
 * \brief Returns the interrupt flag.
 *
 * \details This function returns the eCAP interrupt flag. The following are valid
 * interrupt sources corresponding to the eCAP interrupt flag.
 *
 * \note - User can check if a combination of various interrupts have occurred
 *         by ORing the above return values.
 * \param[in] base is the base address of the ECAP module.
 *
 * \return Returns the eCAP interrupt that has occurred. The following are
 *  valid return values.
 *  - ECAP_ISR_SOURCE_CAPTURE_EVENT_1   - Event 1 generates interrupt
 *  - ECAP_ISR_SOURCE_CAPTURE_EVENT_2   - Event 2 generates interrupt
 *  - ECAP_ISR_SOURCE_CAPTURE_EVENT_3   - Event 3 generates interrupt
 *  - ECAP_ISR_SOURCE_CAPTURE_EVENT_4   - Event 4 generates interrupt
 *  - ECAP_ISR_SOURCE_COUNTER_OVERFLOW  - Counter overflow generates interrupt
 *  - ECAP_ISR_SOURCE_COUNTER_PERIOD    - Counter equal period generates
 *                                        interrupt
 *  - ECAP_ISR_SOURCE_COUNTER_COMPARE   - Counter equal compare generates
 *                                        interrupt
 *
 */
static inline uint16_t ECAP_getInterruptSource(ECAP_Type *base)
{
    assert(ECAP_isBaseValid(base));

    /* Return contents of ECFLG register */
    return (base->ECFLG & 0xFEU);
}

/*!
 * \brief Returns the Global interrupt flag.
 *
 * \param[in] base is the base address of the ECAP module.
 *
 * \return true if there is a global eCAP interrupt.
 * \return false if there is no global eCAP interrupt.
 *
 */
static inline bool ECAP_getGlobalInterruptStatus(ECAP_Type *base)
{
    assert(ECAP_isBaseValid(base));

    /* Return contents of Global interrupt bit */
    return ((base->ECFLG & 0x1U) == 0x1U);
}

/*!
 * \brief Clears interrupt flag.
 *
 * \details This function clears eCAP interrupt flags. The following are valid
 * interrupt sources.
 *  - ECAP_ISR_SOURCE_CAPTURE_EVENT_1 - Event 1 generates interrupt
 *  - ECAP_ISR_SOURCE_CAPTURE_EVENT_2 - Event 2 generates interrupt
 *  - ECAP_ISR_SOURCE_CAPTURE_EVENT_3 - Event 3 generates interrupt
 *  - ECAP_ISR_SOURCE_CAPTURE_EVENT_4 - Event 4 generates interrupt
 *  - ECAP_ISR_SOURCE_COUNTER_OVERFLOW - Counter overflow generates interrupt
 *  - ECAP_ISR_SOURCE_COUNTER_PERIOD   - Counter equal period generates
 *                                       interrupt
 *  - ECAP_ISR_SOURCE_COUNTER_COMPARE  - Counter equal compare generates
 *                                       interrupt
 *
 * \param[in] base is the base address of the ECAP module.
 * \param[in] intFlags is the interrupt source.
 *
 *
 */
static inline void ECAP_clearInterrupt(ECAP_Type *base, uint16_t intFlags)
{
    assert(ECAP_isBaseValid(base));
    assert((intFlags &
            ~(ECAP_ISR_SOURCE_CAPTURE_EVENT_1 | ECAP_ISR_SOURCE_CAPTURE_EVENT_2 | ECAP_ISR_SOURCE_CAPTURE_EVENT_3 |
              ECAP_ISR_SOURCE_CAPTURE_EVENT_4 | ECAP_ISR_SOURCE_COUNTER_OVERFLOW | ECAP_ISR_SOURCE_COUNTER_PERIOD |
              ECAP_ISR_SOURCE_COUNTER_COMPARE)) == 0U);

    /* Write to ECCLR register */
    base->ECCLR = intFlags;
}

/*!
 * \brief Clears global interrupt flag
 *
 * \details This function clears the global interrupt bit.
 *
 * \param[in] base is the base address of the ECAP module.
 *
 */
static inline void ECAP_clearGlobalInterrupt(ECAP_Type *base)
{
    assert(ECAP_isBaseValid(base));

    /* Write to INT bit */
    base->ECCLR = ECAP_ECCLR_INT_FLAG_CLR_Set(1);
}

/*!
 *
 * \brief Forces interrupt source.
 *
 * \details This function forces and enables eCAP interrupt source. The following are
 * valid interrupt sources.
 *  - ECAP_ISR_SOURCE_CAPTURE_EVENT_1 - Event 1 generates interrupt
 *  - ECAP_ISR_SOURCE_CAPTURE_EVENT_2 - Event 2 generates interrupt
 *  - ECAP_ISR_SOURCE_CAPTURE_EVENT_3 - Event 3 generates interrupt
 *  - ECAP_ISR_SOURCE_CAPTURE_EVENT_4 - Event 4 generates interrupt
 *  - ECAP_ISR_SOURCE_COUNTER_OVERFLOW - Counter overflow generates interrupt
 *  - ECAP_ISR_SOURCE_COUNTER_PERIOD   - Counter equal period generates
 *                                       interrupt
 *  - ECAP_ISR_SOURCE_COUNTER_COMPARE  - Counter equal compare generates
 *                                       interrupt
 *
 * \param[in] base is the base address of the ECAP module.
 * \param[in] intFlags is the interrupt source.
 *
 *
 */
static inline void ECAP_forceInterrupt(ECAP_Type *base, uint16_t intFlags)
{
    assert(ECAP_isBaseValid(base));
    assert((intFlags &
            ~(ECAP_ISR_SOURCE_CAPTURE_EVENT_1 | ECAP_ISR_SOURCE_CAPTURE_EVENT_2 | ECAP_ISR_SOURCE_CAPTURE_EVENT_3 |
              ECAP_ISR_SOURCE_CAPTURE_EVENT_4 | ECAP_ISR_SOURCE_COUNTER_OVERFLOW | ECAP_ISR_SOURCE_COUNTER_PERIOD |
              ECAP_ISR_SOURCE_COUNTER_COMPARE)) == 0U);

    /* Write to ECFRC register */
    base->ECFRC = intFlags;
}

/*!
 * \brief Sets eCAP in Capture mode.
 *
 * \details This function sets the eCAP module to operate in Capture mode.
 *
 * \param[in] base is the base address of the ECAP module.
 *
 *
 */
static inline void ECAP_enableCaptureMode(ECAP_Type *base)
{
    assert(ECAP_isBaseValid(base));

    /* Clear CAP/APWM bit */
    base->ECCTL2 &= ~(ECAP_ECCTL2_CAP_APWM_Set(1));
}

/*!
 * \brief Sets eCAP in APWM mode.
 *
 * \details This function sets the eCAP module to operate in APWM mode.
 *
 * \param[in] base is the base address of the ECAP module.
 *
 *
 */
static inline void ECAP_enableAPWMMode(ECAP_Type *base)
{
    assert(ECAP_isBaseValid(base));

    /* Set CAP/APWM bit */
    base->ECCTL2 |= ECAP_ECCTL2_CAP_APWM_Set(1);
}

/*!
 * \brief Enables counter reset on an event.
 *
 * \details This function enables the base timer, TSCTR, to be reset on capture
 * event provided by the variable event. Valid inputs for event are
 * kECAP_EVENT_1 to kECAP_EVENT_4.
 *
 * \param[in] base is the base address of the ECAP module.
 * \param[in] event is the event number the time base gets reset.
 *
 *
 */
static inline void ECAP_enableCounterResetOnEvent(ECAP_Type *base, ECAP_Events_t event)
{
    assert(ECAP_isBaseValid(base));

    /* Set CTRRST1,CTRRST2,CTRRST3 or CTRRST4 bits */
    base->ECCTL1 |= 1U << ((2U * (uint16_t)event) + 1U);
}

/*!
 * \brief Disables counter reset on events.
 *
 * \details This function disables the base timer, TSCTR, from being reset on capture
 * event provided by the variable event. Valid inputs for event are
 * kECAP_EVENT_1 to kECAP_EVENT_4.
 *
 * \param[in] base is the base address of the ECAP module.
 * \param[in] event is the event number the time base gets reset.
 *
 *
 */
static inline void ECAP_disableCounterResetOnEvent(ECAP_Type *base, ECAP_Events_t event)
{
    assert(ECAP_isBaseValid(base));

    /* Clear CTRRST1,CTRRST2,CTRRST3 or CTRRST4 bits */
    base->ECCTL1 &= ~(1U << ((2U * (uint16_t)event) + 1U));
}

/*!
 * \brief Enables time stamp capture.
 *
 * \details This function enables time stamp count to be captured
 *
 * \param[in] base is the base address of the ECAP module.
 *
 *
 */
static inline void ECAP_enableTimeStampCapture(ECAP_Type *base)
{
    assert(ECAP_isBaseValid(base));

    /* Set CAPLDEN bit */
    base->ECCTL1 |= ECAP_ECCTL1_CAPLDEN_Set(1);
}

/*!
 * \brief Disables time stamp capture.
 *
 * \details This function disables time stamp count to be captured
 *
 * \param[in] base is the base address of the ECAP module.
 *
 *
 */
static inline void ECAP_disableTimeStampCapture(ECAP_Type *base)
{
    assert(ECAP_isBaseValid(base));

    /* Clear CAPLDEN bit */
    base->ECCTL1 &= ~(ECAP_ECCTL1_CAPLDEN_Set(1));
}

/*!
 * \brief Sets a phase shift value count.
 *
 * \details This function writes a phase shift value to be loaded into the main time
 * stamp counter.
 *
 * \param[in] base is the base address of the ECAP module.
 * \param[in] shiftCount is the phase shift value.
 *
 *
 */
static inline void ECAP_setPhaseShiftCount(ECAP_Type *base, uint32_t shiftCount)
{
    assert(ECAP_isBaseValid(base));

    /* Write to CTRPHS */
    base->CTRPHS = shiftCount;
}

/*!
 * \brief Set up the source for sync-in pulse.
 *
 * \details This function set the sync out pulse mode.
 * Valid values for mode are:
 *  - kECAP_SYNC_IN_PULSE_SRC_SYNCOUT_EPWMx - sync-in pulse source can be
 *                                           any of the EPWMx sync-out
 *                                           signal
 *  - kECAP_SYNC_IN_PULSE_SRC_SYNCOUT_ECAPx - sync-in pulse source can be
 *                                           selected as any of the ECAPx
 *                                           sync-out signal
 *  - kECAP_SYNC_IN_PULSE_SRC_INPUTXBAR_OUT5-6 - sync-in pulse source can be
 *                                              selected as any of the Input
 *                                              xbar out5-6 signal
 *  - kECAP_SYNC_IN_PULSE_SRC_DISABLE - sync-in pulse is disabled for the
 *                                     ECAP module
 *
 * \param[in] base is the base address of the ECAP module.
 * \param[in] source is the sync-in pulse source.
 *
 *
 */
static inline void ECAP_setSyncInPulseSource(ECAP_Type *base, ECAP_SyncInPulseSource_t source)
{
    assert(ECAP_isBaseValid(base));

    /* Set ECAP Sync-In Source Mode. */
    base->ECAPSYNCINSEL =
        (base->ECAPSYNCINSEL & (~ECAP_ECAPSYNCINSEL_SEL_Msk)) | ((uint16_t)source & ECAP_ECAPSYNCINSEL_SEL_Msk);
}

/*!
 * \brief Enable counter loading with phase shift value.
 *
 * \details This function enables loading of the counter with the value present in the
 * phase shift counter as defined by the ECAP_setPhaseShiftCount() function.
 *
 * \param[in] base is the base address of the ECAP module.
 *
 *
 */
static inline void ECAP_enableLoadCounter(ECAP_Type *base)
{
    assert(ECAP_isBaseValid(base));

    /* Write to SYNCI_EN */
    base->ECCTL2 |= ECAP_ECCTL2_SYNCI_EN_Set(1);
}

/*!
 * \brief Disable counter loading with phase shift value.
 *
 * \details This function disables loading of the counter with the value present in the
 * phase shift counter as defined by the ECAP_setPhaseShiftCount() function.
 *
 * \param[in] base is the base address of the ECAP module.
 *
 *
 */
static inline void ECAP_disableLoadCounter(ECAP_Type *base)
{
    assert(ECAP_isBaseValid(base));

    /* Write to SYNCI_EN */
    base->ECCTL2 &= ~(ECAP_ECCTL2_SYNCI_EN_Set(1));
}

/*!
 * \brief Load time stamp counter
 *
 * \details This function forces the value in the phase shift counter register to be
 * loaded into Time stamp counter register.
 * Make sure to enable loading of Time stamp counter by calling
 * ECAP_enableLoadCounter() function before calling this function.
 *
 * \param[in] base is the base address of the ECAP module.
 *
 *
 */
static inline void ECAP_loadCounter(ECAP_Type *base)
{
    assert(ECAP_isBaseValid(base));

    /* Write to SWSYNC */
    base->ECCTL2 |= ECAP_ECCTL2_SWSYNC_Set(1);
}

/*!
 * \brief Configures Sync out signal mode.
 *
 * \details This function sets the sync out mode. Valid parameters for mode are:
 * - kECAP_SYNC_OUT_SYNCI - Trigger sync out on sync-in event.
 * - kECAP_SYNC_OUT_COUNTER_PRD - Trigger sync out when counter equals period.
 * - kECAP_SYNC_OUT_DISABLED - Disable sync out.
 *
 * \param[in] base is the base address of the ECAP module.
 * \param[in] mode is the sync out mode.
 *
 *
 */
static inline void ECAP_setSyncOutMode(ECAP_Type *base, ECAP_SyncOutMode_t mode)
{
    assert(ECAP_isBaseValid(base));

    /* Write to SYNCO_SEL */
    base->ECCTL2 = (base->ECCTL2 & (~ECAP_ECCTL2_SYNCO_SEL_Msk)) | (uint16_t)mode;
}

/*!
 * \brief Configures Sync out signal extend width.
 *
 * \details This function sets the cycle expand of ecap internal sync signal.
 *
 * \param[in] base is the base address of the ECAP module.
 * \param[in] cycle is the expand of ecap internal sync signal.
 *
 *
 */
static inline void ECAP_setSyncOutExpand(ECAP_Type *base, uint16_t cycle)
{
    assert(ECAP_isBaseValid(base));

    /* Write to SYNCIN_SEL */
    base->ECAPSYNCINSEL =
        (base->ECAPSYNCINSEL & (~ECAP_ECAPSYNCINSEL_SYNC_EXP_NUM_Msk)) | (cycle << ECAP_ECAPSYNCINSEL_SYNC_EXP_NUM_Pos);
}

/*!
 * \brief Stops Time stamp counter.
 *
 * \details This function stops the time stamp counter.
 *
 * \param[in] base is the base address of the ECAP module.
 *
 *
 */
static inline void ECAP_stopCounter(ECAP_Type *base)
{
    assert(ECAP_isBaseValid(base));

    /* Clear TSCTR */
    base->ECCTL2 &= ~(ECAP_ECCTL2_TSCTRSTOP_Set(1));
}

/*!
 * \brief Starts Time stamp counter.
 *
 * \details This function starts the time stamp counter.
 *
 * \param[in] base is the base address of the ECAP module.
 *
 *
 */
static inline void ECAP_startCounter(ECAP_Type *base)
{
    assert(ECAP_isBaseValid(base));

    /* Set TSCTR */
    base->ECCTL2 |= ECAP_ECCTL2_TSCTRSTOP_Set(1);
}

/*!
 * \brief Set eCAP APWM polarity.
 *
 * \details This function sets the polarity of the eCAP in APWM mode. Valid inputs for
 * polarity are:
 * - kECAP_APWM_ACTIVE_HIGH - For active high.
 * - kECAP_APWM_ACTIVE_LOW - For active low.
 *
 * \param[in] base is the base address of the ECAP module.
 * \param[in] polarity is the polarity of APWM
 *
 *
 */
static inline void ECAP_setAPWMPolarity(ECAP_Type *base, ECAP_APWMPolarity_t polarity)
{
    assert(ECAP_isBaseValid(base));

    base->ECCTL2 = (base->ECCTL2 & ~(ECAP_ECCTL2_APWMPOL_Set(1))) | (uint16_t)polarity;
}

/*!
 * \brief Set eCAP APWM period.
 *
 * \details This function sets the period count of the APWM waveform.
 * periodCount takes the actual count which is written to the register. The
 * user is responsible for converting the desired frequency or time into
 * the period count.
 *
 * \param[in] base is the base address of the ECAP module.
 * \param[in] periodCount is the period count for APWM.
 *
 *
 */
static inline void ECAP_setAPWMPeriod(ECAP_Type *base, uint32_t periodCount)
{
    assert(ECAP_isBaseValid(base));

    /* Write to CAP1 */
    base->CAP1 = periodCount;
}

/*!
 * \brief Set eCAP APWM on or off time count.
 *
 * \details This function sets the on or off time count of the APWM waveform depending
 * on the polarity of the output. If the output , as set by
 * ECAP_setAPWMPolarity(), is active high then compareCount determines the on
 * time. If the output is active low then compareCount determines the off
 * time. compareCount takes the actual count which is written to the register.
 * The user is responsible for converting the desired frequency or time into
 * the appropriate count value.
 *
 * \param[in] base is the base address of the ECAP module.
 * \param[in] compareCount is the on or off count for APWM.
 *
 *
 */
static inline void ECAP_setAPWMCompare(ECAP_Type *base, uint32_t compareCount)
{
    assert(ECAP_isBaseValid(base));

    /* Write to CAP2 */
    base->CAP2 = compareCount;
}

/*!
 * \brief Load eCAP APWM shadow period.
 *
 * \details This function sets the shadow period count of the APWM waveform.
 * periodCount takes the actual count which is written to the register. The
 * user is responsible for converting the desired frequency or time into
 * the period count.
 *
 * \param[in] base is the base address of the ECAP module.
 * \param[in] periodCount is the shadow period count for APWM.
 *
 */
static inline void ECAP_setAPWMShadowPeriod(ECAP_Type *base, uint32_t periodCount)
{
    assert(ECAP_isBaseValid(base));

    /* Write to CAP3 */
    base->CAP3 = periodCount;
}

/*!
 * \brief Set eCAP APWM shadow on or off time count.
 *
 * \details This function sets the shadow on or off time count of the APWM waveform
 * depending on the polarity of the output. If the output , as set by
 * ECAP_setAPWMPolarity() , is active high then compareCount determines the
 * on time. If the output is active low then compareCount determines the off
 * time. compareCount takes the actual count which is written to the register.
 * The user is responsible for converting the desired frequency or time into
 * the appropriate count value.
 *
 * \param[in] base is the base address of the ECAP module.
 * \param[in] compareCount is the on or off count for APWM.
 *
 *
 */
static inline void ECAP_setAPWMShadowCompare(ECAP_Type *base, uint32_t compareCount)
{
    assert(ECAP_isBaseValid(base));

    /* Write to CAP4 */
    base->CAP4 = compareCount;
}

/*!
 * \brief Returns the time base counter value.
 *
 * \details This function returns the time base counter value.
 *
 * \param base is the base address of the ECAP module.
 *
 * \return time base counter value.
 */
static inline uint32_t ECAP_getTimeBaseCounter(ECAP_Type *base)
{
    assert(ECAP_isBaseValid(base));

    /* Read the Time base counter value */
    return (base->TSCTR);
}

/*!
 * \brief Returns event time stamp.
 *
 * \details This function returns the current time stamp count of the given event.
 * Valid values for event are \b kECAP_EVENT_1 to \b kECAP_EVENT_4.
 *
 * \param[in] base is the base address of the ECAP module.
 * \param[in] event is the event number.
 *
 * \return Event time stamp value or 0 if \e event is invalid.
 *
 */
static inline uint32_t ECAP_getEventTimeStamp(ECAP_Type *base, ECAP_Events_t event)
{
    uint32_t count;

    assert(ECAP_isBaseValid(base));

    switch (event)
    {
        case kECAP_EVENT_1:

            /* Read CAP1 register */
            count = base->CAP1;
            break;
        case kECAP_EVENT_2:

            /* Read CAP2 register */
            count = base->CAP2;
            break;
        case kECAP_EVENT_3:

            /* Read CAP3 register */
            count = base->CAP3;
            break;
        case kECAP_EVENT_4:

            /* Read CAP4 register */
            count = base->CAP4;
            break;
        default:

            /* Invalid event parameter */
            count = 0U;
            break;
    }

    return (count);
}

/*!
 * \brief Select eCAP input.
 *
 * \details This function selects the eCAP input signal.
 *
 * \note Please refer to the ::ECAP_InputCaptureSignals_t Enum for the valid values
 * to be passed to \e input parameter.
 *
 * \param[in] base is the base address of the ECAP module.
 * \param[in] input is the eCAP input signal.
 *
 *
 */
static inline void ECAP_selectECAPInput(ECAP_Type *base, ECAP_InputCaptureSignals_t input)
{
    assert(ECAP_isBaseValid(base));

    /* Write to ECCTL0 */
    base->ECCTL0 = ((base->ECCTL0 & ~ECAP_ECCTL0_INPUTSEL_Msk) | (uint16_t)input);
}

/*!
 * \brief Resets eCAP counters and flags.
 *
 * \details This function resets the main counter (TSCTR register), event filter,
 * modulo counter, capture events and counter overflow flags
 *
 * \param[in] base is the base address of the ECAP module.
 *
 *
 */
static inline void ECAP_resetCounters(ECAP_Type *base)
{
    assert(ECAP_isBaseValid(base));

    /* Write to ECCTL2 */
    base->ECCTL2 |= ECAP_ECCTL2_CTRFILTRESET_Set(1);
}

/*!
 * \brief Sets the eCAP DMA source.
 *
 * \details This function sets the eCAP event source for the DMA trigger.
 * Valid values for \e event are \b kECAP_EVENT_1 to \b kECAP_EVENT_4.
 *
 * \param[in] base is the base address of the ECAP module.
 * \param[in] event is the eCAP event for the DMA
 *
 */
static inline void ECAP_setDMASource(ECAP_Type *base, ECAP_Events_t event)
{
    assert(ECAP_isBaseValid(base));

    /* Write to ECCTL2 */
    base->ECCTL2 = ((base->ECCTL2 & ~ECAP_ECCTL2_DMAEVTSEL_Msk) | ((uint16_t)event << ECAP_ECCTL2_DMAEVTSEL_Pos));
}

/*!
 * \brief Return the Modulo counter status.
 *
 * \details This function returns the modulo counter status, indicating which register
 * gets loaded on the next capture event.
 *
 * \param[in] base is the base address of the ECAP module.
 *
 * \return an \b kECAP_EVENT_n value indicating that CAPn is the
 * register to be loaded on the next event.
 *
 */
static inline ECAP_Events_t ECAP_getModuloCounterStatus(ECAP_Type *base)
{
    uint16_t counterStatusValue;

    assert(ECAP_isBaseValid(base));

    counterStatusValue = ((base->ECCTL2 & ECAP_ECCTL2_MODCNTRSTS_Msk) >> ECAP_ECCTL2_MODCNTRSTS_Pos);

    /* Read MODCNTRSTS bit */
    return ((ECAP_Events_t)(counterStatusValue));
}

/*!
 * \brief Configures emulation mode.
 *
 * \details This function configures the eCAP counter, TSCTR,  to the desired emulation
 * mode when emulation suspension occurs. Valid inputs for mode are:
 * - kECAP_EMULATION_STOP  - Counter is stopped immediately.
 * - kECAP_EMULATION_RUN_TO_ZERO - Counter runs till it reaches 0.
 * - kECAP_EMULATION_FREE_RUN - Counter is not affected.
 *
 * \param[in] base is the base address of the ECAP module.
 * \param[in] mode is the emulation mode.
 *
 *
 */
extern void ECAP_setEmulationMode(ECAP_Type *base, ECAP_EmulationMode_t mode);


#ifdef __cplusplus
}
#endif

/*!
 * @}
 */ /* end of DRV_HTE_ECAP */

#endif /* HTE_ECAP_H */
