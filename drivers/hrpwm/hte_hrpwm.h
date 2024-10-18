/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*!
 * \file hte_hrpwm.h
 * \brief SDK HRPWM driver header file
 * \version 1.0.0
 */
#ifndef HTE_HRPWM_H
#define HTE_HRPWM_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_common.h"
#include "hte_epwm.h"

/*!
 *
 * \brief SDK HRPWM driver
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * \brief HRCAL Update Mode Enumeration
 */
typedef enum
{
    HRCAL_COUNTER_MODE = 0x0,               /*!< Update triggered by a counter reaching a certain value. */
    HRCAL_PWMSYNCPER_MODE = 0x1,            /*!< Update synchronized with a PWM sync pulse. */
    HRCAL_SOFTWARE_MODE = 0x2               /*!< Update controlled directly by software commands. */
} HRCAL_UpdataMode;

/*!
 * \brief HRCAL Accumulator Bit Width Selection Enumeration
 */
typedef enum
{
    HRCAL_SELECT_0_TO_7_BITS = 0x0,         /*!< Accumulator bit width 0-7 bits. */
    HRCAL_SELECT_1_TO_8_BITS = 0x1,         /*!< Accumulator bit width 1-8 bits. */
    HRCAL_SELECT_2_TO_9_BITS = 0x2,         /*!< Accumulator bit width 2-9 bits. */
    HRCAL_SELECT_3_TO_10_BITS = 0x3,        /*!< Accumulator bit width 3-10 bits. */
    HRCAL_SELECT_4_TO_11_BITS = 0x4,        /*!< Accumulator bit width 4-11 bits. */
    HRCAL_SELECT_5_TO_12_BITS = 0x5,        /*!< Accumulator bit width 5-12 bits. */
    HRCAL_SELECT_6_TO_13_BITS = 0x6,        /*!< Accumulator bit width 6-13 bits. */
    HRCAL_SELECT_7_TO_14_BITS = 0x7,        /*!< Accumulator bit width 7-14 bits. */
    HRCAL_SELECT_8_TO_15_BITS = 0x8         /*!< Accumulator bit width 8-15 bits. */
} HRCAL_BitsWidth;

/*!
 * \brief HRCAL Data Storage Number Enumeration
 */
typedef enum
{
    HRCAL_STORAGE_4_DATA = 0x0,             /*!< Storage capacity for 4 calibration datasets. */
    HRCAL_STORAGE_8_DATA = 0x1,             /*!< Storage capacity for 8 calibration datasets. */
    HRCAL_STORAGE_16_DATA = 0x2,            /*!< Storage capacity for 16 calibration datasets. */
    HRCAL_STORAGE_32_DATA = 0x3             /*!< Storage capacity for 32 calibration datasets. */
} HRCAL_StorageNumber;

/*!
 *
 * Values that can be passed to HRPWM_setMEPEdgeSelect(),
 * HRPWM_setMEPControlMode(), HRPWM_setCounterCompareShadowLoadEvent()
 * as the \e channel parameter.
 *
 */
typedef enum
{
    HRPWM_CHANNEL_A = 0, /*!< HRPWM A */ 
    HRPWM_CHANNEL_B = 8  /*!< HRPWM B */ 
} HRPWM_Channel;

/*!
 *
 * Values that can be passed to HRPWM_setMEPEdgeSelect() as the \e mepEdgeMode
 * parameter.
 *
 */
typedef enum
{  
    HRPWM_MEP_CTRL_DISABLE = 0,                 /*!< HRPWM is disabled */   
    HRPWM_MEP_CTRL_RISING_EDGE = 5,             /*!< MEP controls rising edge */   
    HRPWM_MEP_CTRL_FALLING_EDGE = 6,            /*!< MEP controls falling edge */ 
    HRPWM_MEP_CTRL_RISING_AND_FALLING_EDGE = 7  /*!< MEP controls both rising and falling edge */
} HRPWM_MEPEdgeMode;

/*!
 *
 * Values that can be passed to HRPWM_setHRMEPCtrlMode() as the \e
 * parameter.
 *
 */
typedef enum
{    
    HRPWM_MEP_DUTY_PERIOD_CTRL = 0, /*!< CMPAHR/CMPBHR or TBPRDHR controls MEP edge */   
    HRPWM_MEP_PHASE_CTRL = 1        /*!< TBPHSHR controls MEP edge */
} HRPWM_MEPCtrlMode;

/*!
 *
 * Values that can be passed to HRPWM_setCounterCompareShadowLoadEvent(),
 * HRPWM_setRisingEdgeDelayLoadMode() and HRPWM_setFallingEdgeDelayLoadMode
 * as the \e loadEvent parameter.
 *
 */
typedef enum
{  
    HRPWM_LOAD_ON_CNTR_ZERO = 0,        /*!< load when counter equals zero */
    HRPWM_LOAD_ON_CNTR_PERIOD = 1,      /*!< load when counter equals period */  
    HRPWM_LOAD_ON_CNTR_ZERO_PERIOD = 2, /*!< load when counter equals zero or period */
} HRPWM_LoadMode;

/*!
 *
 * Values that can be passed to HRPWM_setChannelBOutputPath() as the \e
 * outputOnB parameter.
 *
 */
typedef enum
{
    HRPWM_OUTPUT_ON_B_NORMAL = 0, /*!<< ePWMxB output is normal. */
    HRPWM_OUTPUT_ON_B_INV_A  = 1  /*!<< ePWMxB output is inverted 
                                        version of ePWMxA signal */
} HRPWM_ChannelBOutput;

/*!
 *
 * Values that can be passed to HRPWM_setSyncPulseSource() as the \e
 * syncPulseSource parameter.
 *
 */
typedef enum
{  
    HRPWM_PWMSYNC_SOURCE_PERIOD = 0,        /*!< Counter equals Period */  
    HRPWM_PWMSYNC_SOURCE_ZERO = 1,          /*!< Counter equals zero */  
    HRPWM_PWMSYNC_SOURCE_COMPC_UP = 4,      /*!< Counter equals COMPC when counting up */   
    HRPWM_PWMSYNC_SOURCE_COMPC_DOWN = 5,    /*!< Counter equals COMPC when counting down */   
    HRPWM_PWMSYNC_SOURCE_COMPD_UP = 6,      /*!< Counter equals COMPD when counting up */   
    HRPWM_PWMSYNC_SOURCE_COMPD_DOWN = 7     /*!< Counter equals COMPD when counting down */
} HRPWM_SyncPulseSource;

/*!
 *
 * Values that can be passed to HRPWM_setCounterCompareValue() as the \e
 * compModule parameter.
 *
 */
typedef enum
{
    HRPWM_COUNTER_COMPARE_A = 0, /*!<< counter compare A */
    HRPWM_COUNTER_COMPARE_B = 4  /*!<< counter compare B */
} HRPWM_CounterCompareModule;

/*!
 *
 * Values that can be passed to HRPWM_setDeadbandMEPEdgeSelect() as the \e
 * mepDBEdge.
 *
 */
typedef enum
{ 
    HRPWM_DB_MEP_CTRL_DISABLE = 0,  /*!< HRPWM is disabled */  
    HRPWM_DB_MEP_CTRL_RED = 1,      /*!< MEP controls Rising Edge Delay */   
    HRPWM_DB_MEP_CTRL_FED = 2,      /*!< MEP controls Falling Edge Delay */   
    HRPWM_DB_MEP_CTRL_RED_FED = 3   /*!< MEP controls both Falling and Rising edge delay */
} HRPWM_MEPDeadBandEdgeMode;

/*!
 *
 * Values that can be passed to HRPWM_lockRegisters() as the \e registerGroup
 * parameter.
 *
 */
typedef enum
{
    HRPWM_REGISTER_GROUP_HRPWM = 0x1,           /*!<< HRPWM register group */
    HRPWM_REGISTER_GROUP_GLOBAL_LOAD = 0x2,     /*!<< Global load register group */
    HRPWM_REGISTER_GROUP_TRIP_ZONE = 0x4,       /*!<< Trip zone register group */
    HRPWM_REGISTER_GROUP_TRIP_ZONE_CLEAR = 0x8, /*!<< Trip zone clear group */
    HRPWM_REGISTER_GROUP_DIGITAL_COMPARE = 0x10 /*!<< Digital compare group */
} HRPWM_LockRegisterGroup;

/*!
 *
 * Functions APIs shared with ePWM module
 *
 */

/*!
 * Time Base Sub Module related APIs 
 */
#define HRPWM_setTimeBaseCounter                 EPWM_setTimeBaseCounter            /*!<< HRPWM function name */
#define HRPWM_setCountModeAfterSync              EPWM_setCountModeAfterSync         /*!<< HRPWM function name */
#define HRPWM_setClockPrescaler                  EPWM_setClockPrescaler             /*!<< HRPWM function name */
#define HRPWM_swForceSyncPulse                   EPWM_forceSyncPulse                /*!<< HRPWM function name */
#define HRPWM_setSyncOutPulseMode                EPWM_setSyncOutPulseMode           /*!<< HRPWM function name */
#define HRPWM_setPeriodLoadMode                  EPWM_setPeriodLoadMode             /*!<< HRPWM function name */
#define HRPWM_setTimeBaseCounterMode             EPWM_setTimeBaseCounterMode        /*!<< HRPWM function name */
#define HRPWM_selectPeriodLoadEvent              EPWM_selectPeriodLoadEvent         /*!<< HRPWM function name */
#define HRPWM_enableOneShotSync                  EPWM_enableOneShotSync             /*!<< HRPWM function name */
#define HRPWM_disableOneShotSync                 EPWM_disableOneShotSync            /*!<< HRPWM function name */
#define HRPWM_startOneShotSync                   EPWM_startOneShotSync              /*!<< HRPWM function name */
#define HRPWM_getTimeBaseCounterOverflowStatus                                \
                                          EPWM_getTimeBaseCounterOverflowStatus     /*!<< HRPWM function name */
#define HRPWM_clearTimeBaseCounterOverflowEvent                               \
                                         EPWM_clearTimeBaseCounterOverflowEvent     /*!<< HRPWM function name */
#define HRPWM_getSyncStatus                      EPWM_getSyncStatus                 /*!<< HRPWM function name */
#define HRPWM_clearSyncEvent                     EPWM_clearSyncEvent                /*!<< HRPWM function name */
#define HRPWM_getTimeBaseCounterDirection     EPWM_getTimeBaseCounterDirection      /*!<< HRPWM function name */
#define HRPWM_setupEPWMLinks                     EPWM_setupEPWMLinks                /*!<< HRPWM function name */
#define HRPWM_setCounterCompareShadowLoadMode                                 \
                                           EPWM_setCounterCompareShadowLoadMode     /*!<< HRPWM function name */
#define HRPWM_disableCounterCompareShadowLoadMode                             \
                                       EPWM_disableCounterCompareShadowLoadMode     /*!<< HRPWM function name */
#define HRPWM_getCounterCompareShadowStatus                                   \
                                            EPWM_getCounterCompareShadowStatus      /*!<< HRPWM function name */

/*! 
 * Action Qualifier module related APIs  
 */
#define HRPWM_setActionQualifierShadowLoadMode                                \
                                       EPWM_setActionQualifierShadowLoadMode        /*!<< HRPWM function name */
#define HRPWM_disableActionQualifierShadowLoadMode                            \
                                      EPWM_disableActionQualifierShadowLoadMode     /*!<< HRPWM function name */
#define HRPWM_setActionQualifierT1TriggerSource                               \
                                        EPWM_setActionQualifierT1TriggerSource      /*!<< HRPWM function name */
#define HRPWM_setActionQualifierT2TriggerSource                               \
                                        EPWM_setActionQualifierT2TriggerSource      /*!<< HRPWM function name */
#define HRPWM_setActionQualifierAction           EPWM_setActionQualifierAction      /*!<< HRPWM function name */
#define HRPWM_setActionQualifierContSWForceShadowMode                         \
                                  EPWM_setActionQualifierContSWForceShadowMode      /*!<< HRPWM function name */
#define HRPWM_setActionQualifierContSWForceAction                             \
                                  EPWM_setActionQualifierContSWForceAction          /*!<< HRPWM function name */
/*! 
 * HRPWM_setActionQualifierSwAction is kept for compatibility,
 * use HRPWM_setActionQualifierSWAction 
 */
#define HRPWM_setActionQualifierSwAction        EPWM_setActionQualifierSwAction     /*!<< HRPWM function name */
#define HRPWM_setActionQualifierSWAction        EPWM_setActionQualifierSWAction     /*!<< HRPWM function name */

/*! 
 * HRPWM_forceActionQualifierSwAction is kept for compatibility,
 * use HRPWM_forceActionQualifierSWAction 
 */
#define HRPWM_forceActionQualifierSwAction    EPWM_forceActionQualifierSwAction     /*!<< HRPWM function name */
#define HRPWM_forceActionQualifierSWAction    EPWM_forceActionQualifierSWAction     /*!<< HRPWM function name */

/*! 
 * Dead Band Module related APIs 
 */
#define HRPWM_setDeadBandOutputSwapMode          EPWM_setDeadBandOutputSwapMode     /*!<< HRPWM function name */
#define HRPWM_setDeadBandDelayMode               EPWM_setDeadBandDelayMode          /*!<< HRPWM function name */
#define HRPWM_setDeadBandDelayPolarity           EPWM_setDeadBandDelayPolarity      /*!<< HRPWM function name */
#define HRPWM_setRisingEdgeDeadBandDelayInput                                 \
                                         EPWM_setRisingEdgeDeadBandDelayInput       /*!<< HRPWM function name */
#define HRPWM_setFallingEdgeDeadBandDelayInput                                \
                                         EPWM_setFallingEdgeDeadBandDelayInput      /*!<< HRPWM function name */
#define HRPWM_setDeadBandControlShadowLoadMode                                \
                                         EPWM_setDeadBandControlShadowLoadMode      /*!<< HRPWM function name */
#define HRPWM_disableDeadBandControlShadowLoadMode                            \
                                      EPWM_disableDeadBandControlShadowLoadMode     /*!<< HRPWM function name */
#define HRPWM_setRisingEdgeDelayCountShadowLoadMode                           \
                                   EPWM_setRisingEdgeDelayCountShadowLoadMode       /*!<< HRPWM function name */
#define HRPWM_disableRisingEdgeDelayCountShadowLoadMode                       \
                                 EPWM_disableRisingEdgeDelayCountShadowLoadMode     /*!<< HRPWM function name */
#define HRPWM_setFallingEdgeDelayCountShadowLoadMode                          \
                                   EPWM_setFallingEdgeDelayCountShadowLoadMode      /*!<< HRPWM function name */
#define HRPWM_disableFallingEdgeDelayCountShadowLoadMode                      \
                                EPWM_disableFallingEdgeDelayCountShadowLoadMode     /*!<< HRPWM function name */
#define HRPWM_setDeadBandCounterClock            EPWM_setDeadBandCounterClock       /*!<< HRPWM function name */
#define HRPWM_setRisingEdgeDelayCount            EPWM_setRisingEdgeDelayCount       /*!<< HRPWM function name */
#define HRPWM_setFallingEdgeDelayCount           EPWM_setFallingEdgeDelayCount      /*!<< HRPWM function name */

/*! 
 * Chopper module related APIs 
 */
#define HRPWM_enableChopper                      EPWM_enableChopper                 /*!<< HRPWM function name */
#define HRPWM_disableChopper                     EPWM_disableChopper                /*!<< HRPWM function name */
#define HRPWM_setChopperDutyCycle                EPWM_setChopperDutyCycle           /*!<< HRPWM function name */
#define HRPWM_setChopperFreq                     EPWM_setChopperFreq                /*!<< HRPWM function name */
#define HRPWM_setChopperFirstPulseWidt           EPWM_setChopperFirstPulseWidth     /*!<< HRPWM function name */

/*! 
 * Trip Zone module related APIs 
 */
#define HRPWM_enableTripZoneSignals              EPWM_enableTripZoneSignals         /*!<< HRPWM function name */
#define HRPWM_disableTripZoneSignals             EPWM_disableTripZoneSignals        /*!<< HRPWM function name */
#define HRPWM_setTripZoneDigitalCompareEventCondition                         \
                                   EPWM_setTripZoneDigitalCompareEventCondition     /*!<< HRPWM function name */
#define HRPWM_enableTripZoneAdvAction             EPWM_enableTripZoneAdvAction      /*!<< HRPWM function name */
#define HRPWM_disableTripZoneAdvAction            EPWM_disableTripZoneAdvAction     /*!<< HRPWM function name */
#define HRPWM_setTripZoneAction                   EPWM_setTripZoneAction            /*!<< HRPWM function name */
#define HRPWM_setTripZoneAdvAction                EPWM_setTripZoneAdvAction         /*!<< HRPWM function name */
#define HRPWM_setTripZoneAdvDigitalCompareActionA                             \
                                   EPWM_setTripZoneAdvDigitalCompareActionA         /*!<< HRPWM function name */
#define HRPWM_setTripZoneAdvDigitalCompareActionB                             \
                                   EPWM_setTripZoneAdvDigitalCompareActionB         /*!<< HRPWM function name */
#define HRPWM_enableTripZoneInterrupt           EPWM_enableTripZoneInterrupt        /*!<< HRPWM function name */
#define HRPWM_disableTripZoneInterrupt          EPWM_disableTripZoneInterrupt       /*!<< HRPWM function name */

/*! 
 * HRPWM_getTripZoneInterruptStatus API define is obsolete please use
 * HRPWM_getTripZoneFlagStatus going forward. 
 */
#define HRPWM_getTripZoneInterruptStatus        EPWM_getTripZoneFlagStatus          /*!<< HRPWM function name */
#define HRPWM_getTripZoneFlagStatus             EPWM_getTripZoneFlagStatus          /*!<< HRPWM function name */

/*!
 * HRPWM_getCycleByCycleTripZoneInterruptStatus API define is obsolete
 * please use HRPWM_getCycleByCycleTripZoneFlagStatus going forward. 
 */
#define HRPWM_getCycleByCycleTripZoneInterruptStatus                          \
                                   HRPWM_getCycleByCycleTripZoneFlagStatus          /*!<< HRPWM function name */
#define HRPWM_getCycleByCycleTripZoneFlagStatus                               \
                                   EPWM_getCycleByCycleTripZoneFlagStatus           /*!<< HRPWM function name */

/*!
 * HRPWM_getOneShotTripZoneInterruptStatus is obsolete please use
 * HRPWM_getOneShotTripZoneFlagStatus going forward.
 */
#define HRPWM_getOneShotTripZoneInterruptStatus                               \
                                   HRPWM_getOneShotTripZoneFlagStatus               /*!<< HRPWM function name */
#define HRPWM_getOneShotTripZoneFlagStatus                                    \
                                   EPWM_getOneShotTripZoneFlagStatus                /*!<< HRPWM function name */
#define HRPWM_selectCycleByCycleTripZoneClearEvent                            \
                                   EPWM_selectCycleByCycleTripZoneClearEvent        /*!<< HRPWM function name */

/*!
 * HRPWM_clearTripZoneInterruptFlag is obsolete please use
 * HRPWM_clearTripZoneFlag going forward.
 */
#define HRPWM_clearTripZoneInterruptFlag        HRPWM_clearTripZoneFlag             /*!<< HRPWM function name */
#define HRPWM_clearTripZoneFlag                 EPWM_clearTripZoneFlag              /*!<< HRPWM function name */

/*!
 * HRPWM_clearCycleByCycleTripZoneInterruptFlag is obsolete please use
 * HRPWM_clearCycleByCycleTripZoneFlag going forward.
 */
#define HRPWM_clearCycleByCycleTripZoneInterruptFlag                          \
                                   HRPWM_clearCycleByCycleTripZoneFlag              /*!<< HRPWM function name */
#define HRPWM_clearCycleByCycleTripZoneFlag                                   \
                                   EPWM_clearCycleByCycleTripZoneFlag               /*!<< HRPWM function name */

/*!
 * HRPWM_clearOneShotTripZoneInterruptFlag is obsolete please use
 * HRPWM_clearOneShotTripZoneFlag going forward.
 */
#define HRPWM_clearOneShotTripZoneInterruptFlag                               \
                                   HRPWM_clearOneShotTripZoneFlag                   /*!<< HRPWM function name */
#define HRPWM_clearOneShotTripZoneFlag                                        \
                                   EPWM_clearOneShotTripZoneFlag                    /*!<< HRPWM function name */
#define HRPWM_forceTripZoneEvent                  EPWM_forceTripZoneEvent           /*!<< HRPWM function name */

/*!
 * Event Trigger related APIs
 */
#define HRPWM_enableInterrupt                     EPWM_enableInterrupt              /*!<< HRPWM function name */
#define HRPWM_disableInterrupt                    EPWM_disableInterrupt             /*!<< HRPWM function name */
#define HRPWM_setInterruptSource                  EPWM_setInterruptSource           /*!<< HRPWM function name */
#define HRPWM_setInterruptEventCount              EPWM_setInterruptEventCount       /*!<< HRPWM function name */
#define HRPWM_getEventTriggerInterruptStatus                                  \
                                           EPWM_getEventTriggerInterruptStatus      /*!<< HRPWM function name */
#define HRPWM_clearEventTriggerInterruptFlag                                  \
                                           EPWM_clearEventTriggerInterruptFlag      /*!<< HRPWM function name */
#define HRPWM_enableInterruptEventCountInit                                   \
                                           EPWM_enableInterruptEventCountInit       /*!<< HRPWM function name */
#define HRPWM_disableInterruptEventCountInit                                  \
                                            EPWM_disableInterruptEventCountInit     /*!<< HRPWM function name */
#define HRPWM_forceInterruptEventCountInit                                    \
                                              EPWM_forceInterruptEventCountInit     /*!<< HRPWM function name */
#define HRPWM_setInterruptEventCountInitValue                                 \
                                           EPWM_setInterruptEventCountInitValue     /*!<< HRPWM function name */
#define HRPWM_getInterruptEventCount            EPWM_getInterruptEventCount         /*!<< HRPWM function name */
#define HRPWM_forceEventTriggerInterrupt        EPWM_forceEventTriggerInterrupt     /*!<< HRPWM function name */

/*!
 * ADC SOC configuration related APIs
 */
#define HRPWM_enableADCTrigger                  EPWM_enableADCTrigger               /*!<< HRPWM function name */
#define HRPWM_disableADCTrigger                 EPWM_disableADCTrigger              /*!<< HRPWM function name */
#define HRPWM_setADCTriggerSource               EPWM_setADCTriggerSource            /*!<< HRPWM function name */
#define HRPWM_setADCTriggerEventPrescale        EPWM_setADCTriggerEventPrescale     /*!<< HRPWM function name */
#define HRPWM_getADCTriggerFlagStatus           EPWM_getADCTriggerFlagStatus        /*!<< HRPWM function name */
#define HRPWM_clearADCTriggerFlag               EPWM_clearADCTriggerFlag            /*!<< HRPWM function name */
#define HRPWM_enableADCTriggerEventCountInit                                  \
                                          EPWM_enableADCTriggerEventCountInit       /*!<< HRPWM function name */
#define HRPWM_disableADCTriggerEventCountInit                                 \
                                          EPWM_disableADCTriggerEventCountInit      /*!<< HRPWM function name */
#define HRPWM_forceADCTriggerEventCountInit                                   \
                                          EPWM_forceADCTriggerEventCountInit        /*!<< HRPWM function name */
#define HRPWM_setADCTriggerEventCountInitValue                                \
                                         EPWM_setADCTriggerEventCountInitValue      /*!<< HRPWM function name */
#define HRPWM_getADCTriggerEventCount             EPWM_getADCTriggerEventCount      /*!<< HRPWM function name */
#define HRPWM_forceADCTrigger                     EPWM_forceADCTrigger              /*!<< HRPWM function name */

/*!
 * Digital Compare Module related APIs
 */
#define HRPWM_selectDigitalCompareTripInput                                   \
                                            EPWM_selectDigitalCompareTripInput      /*!<< HRPWM function name */
#define HRPWM_enableDigitalCompareBlankingWindow                              \
                                   EPWM_enableDigitalCompareBlankingWindow          /*!<< HRPWM function name */
#define HRPWM_disableDigitalCompareBlankingWindow                             \
                                   EPWM_disableDigitalCompareBlankingWindow         /*!<< HRPWM function name */
#define HRPWM_enableDigitalCompareWindowInverseMode                           \
                                   EPWM_enableDigitalCompareWindowInverseMode       /*!<< HRPWM function name */
#define HRPWM_disableDigitalCompareWindowInverseMode                          \
                                   EPWM_disableDigitalCompareWindowInverseMode      /*!<< HRPWM function name */
#define HRPWM_setDigitalCompareBlankingEvent                                  \
                                        EPWM_setDigitalCompareBlankingEvent         /*!<< HRPWM function name */
#define HRPWM_setDigitalCompareFilterInput                                    \
                                        EPWM_setDigitalCompareFilterInput           /*!<< HRPWM function name */
#define HRPWM_setDigitalCompareWindowOffset                                   \
                                        EPWM_setDigitalCompareWindowOffset          /*!<< HRPWM function name */
#define HRPWM_setDigitalCompareWindowLength                                   \
                                         EPWM_setDigitalCompareWindowLength         /*!<< HRPWM function name */
#define HRPWM_getDigitalCompareBlankingWindowOffsetCount                      \
                               EPWM_getDigitalCompareBlankingWindowOffsetCount      /*!<< HRPWM function name */
#define HRPWM_getDigitalCompareBlankingWindowLengthCount                      \
                               EPWM_getDigitalCompareBlankingWindowLengthCount      /*!<< HRPWM function name */
#define HRPWM_setDigitalCompareEventSource                                    \
                                            EPWM_setDigitalCompareEventSource       /*!<< HRPWM function name */
#define HRPWM_setDigitalCompareEventSyncMode                                  \
                                           EPWM_setDigitalCompareEventSyncMode      /*!<< HRPWM function name */
#define HRPWM_enableDigitalCompareADCTrigger                                  \
                                           EPWM_enableDigitalCompareADCTrigger      /*!<< HRPWM function name */
#define HRPWM_disableDigitalCompareADCTrigger                                 \
                                          EPWM_disableDigitalCompareADCTrigger      /*!<< HRPWM function name */
#define HRPWM_enableDigitalCompareSyncEvent                                   \
                                            EPWM_enableDigitalCompareSyncEvent      /*!<< HRPWM function name */
#define HRPWM_disableDigitalCompareSyncEvent                                  \
                                           EPWM_disableDigitalCompareSyncEvent      /*!<< HRPWM function name */
#define HRPWM_enableDigitalCompareCounterCapture                              \
                                EPWM_enableDigitalCompareCounterCapture             /*!<< HRPWM function name */
#define HRPWM_disableDigitalCompareCounterCapture                             \
                                EPWM_disableDigitalCompareCounterCapture            /*!<< HRPWM function name */
#define HRPWM_setDigitalCompareCounterShadowMode                              \
                                EPWM_setDigitalCompareCounterShadowMode             /*!<< HRPWM function name */
#define HRPWM_getDigitalCompareCaptureStatus                                  \
                                 EPWM_getDigitalCompareCaptureStatus                /*!<< HRPWM function name */
#define HRPWM_getDigitalCompareCaptureCount                                   \
                                 EPWM_getDigitalCompareCaptureCount                 /*!<< HRPWM function name */
#define HRPWM_enableDigitalCompareTripCombinationInput                        \
                                EPWM_enableDigitalCompareTripCombinationInput       /*!<< HRPWM function name */
#define HRPWM_disableDigitalCompareTripCombinationInput                       \
                                EPWM_disableDigitalCompareTripCombinationInput      /*!<< HRPWM function name */

/*!
 * Valley switching related APIs
 */
#define HRPWM_enableValleyCapture             EPWM_enableValleyCapture              /*!<< HRPWM function name */
#define HRPWM_disableValleyCapture            EPWM_disableValleyCapture             /*!<< HRPWM function name */
#define HRPWM_startValleyCapture              EPWM_startValleyCapture               /*!<< HRPWM function name */
#define HRPWM_setValleyTriggerSource          EPWM_setValleyTriggerSource           /*!<< HRPWM function name */
#define HRPWM_setValleyTriggerEdgeCounts      EPWM_setValleyTriggerEdgeCounts       /*!<< HRPWM function name */
#define HRPWM_enableValleyHWDelay             EPWM_enableValleyHWDelay              /*!<< HRPWM function name */
#define HRPWM_disableValleyHWDelay            EPWM_disableValleyHWDelay             /*!<< HRPWM function name */
#define HRPWM_setValleySWDelayValue           EPWM_setValleySWDelayValue            /*!<< HRPWM function name */
#define HRPWM_setValleyDelayDivider           EPWM_setValleyDelayDivider            /*!<< HRPWM function name */
#define HRPWM_getValleyEdgeStatus             EPWM_getValleyEdgeStatus              /*!<< HRPWM function name */
#define HRPWM_getValleyCount                  EPWM_getValleyCount                   /*!<< HRPWM function name */
#define HRPWM_getValleyHWDelay                EPWM_getValleyHWDelay                 /*!<< HRPWM function name */

/*!
 * Global Load feature related APIs
 */
#define HRPWM_enableGlobalLoad                EPWM_enableGlobalLoad                 /*!<< HRPWM function name */
#define HRPWM_disableGlobalLoad               EPWM_disableGlobalLoad                /*!<< HRPWM function name */
#define HRPWM_setGlobalLoadTrigger            EPWM_setGlobalLoadTrigger             /*!<< HRPWM function name */
#define HRPWM_setGlobalLoadEventPrescale      EPWM_setGlobalLoadEventPrescale       /*!<< HRPWM function name */
#define HRPWM_getGlobalLoadEventCount         EPWM_getGlobalLoadEventCount          /*!<< HRPWM function name */
#define HRPWM_disableGlobalLoadOneShotMode    EPWM_disableGlobalLoadOneShotMode     /*!<< HRPWM function name */
#define HRPWM_enableGlobalLoadOneShotMode     EPWM_enableGlobalLoadOneShotMode      /*!<< HRPWM function name */
#define HRPWM_setGlobalLoadOneShotLatch       EPWM_setGlobalLoadOneShotLatch        /*!<< HRPWM function name */
#define HRPWM_forceGlobalLoadOneShotEvent     EPWM_forceGlobalLoadOneShotEvent      /*!<< HRPWM function name */
#define HRPWM_enableGlobalLoadRegisters       EPWM_enableGlobalLoadRegisters        /*!<< HRPWM function name */
#define HRPWM_disableGlobalLoadRegisters      EPWM_disableGlobalLoadRegisters       /*!<< HRPWM function name */
#define HRPWM_setEmulationMode                EPWM_setEmulationMode                 /*!<< HRPWM function name */

/*******************************************************************************
 * APIs
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*!
 *
 * \brief
 * Checks HRPWM base address.
 *
 * \param base specifies the HRPWM module base address.
 *
 * This function determines if an HRPWM module base address is valid.
 *
 * \return Returns \b true if the base address is valid and \b false
 * otherwise.
 *
 */
static inline bool HRPWM_isBaseValid(HRPWM_REGS_Type *base)
{
    return((base == HREPWM1) || (base == HREPWM2) ||
           (base == HREPWM3) || (base == HREPWM4) ||
           (base == HREPWM5) || (base == HREPWM6) ||
           (base == HREPWM7) || (base == HREPWM8));
}

/*!
 * \brief Validate HRCAL Base Address
 *
 * \details Verifies the validity of the provided HRCAL base address.
 *
 * \param[in] base Pointer to the HRCAL peripheral base address to validate.
 *
 * \return Returns true if the base address is valid, false otherwise.
 *
 * \note This function is crucial for preventing dereferencing of invalid pointers.
 *
 * \warning Proceeding with operations on an invalid base address.
 */
static inline bool HRCAL_isBaseValid(HRCAL_Type *base)
{
    return(base == HRCAL);
}

/*!
 * \brief Enable HRCAL Calibration Interrupt
 *
 * \details Activates the interrupt generation feature.
 *
 * \param[in] base Pointer to the HRCAL peripheral register base address.
 *
 * \note Enabling this interrupt allows the system to respond promptly.
 *
 * \warning Ensure an ISR (Interrupt Service Routine) is implemented.
 */
static inline void
HRCAL_enableCalibrationInt(HRCAL_Type *base)
{
    /* Check the arguments */
    assert(HRCAL_isBaseValid(base));

    base->HRCALINT |= HRCAL_HRCALINT_CALEREN_Set(1);
}

/*!
 * \brief Enable HRCAL Calibration
 *
 * \details Initiates the High Resolution Calibration (HRCAL) process.
 *
 * \param[in] base Pointer to the HRCAL peripheral register base address.
 *
 * \note Before enabling, ensure all necessary configurations.
 *
 * \warning Enabling calibration when the system is not properly configured.
 */
static inline void
HRCAL_enableCalibration(HRCAL_Type *base)
{
    /* Check the arguments */
    assert(HRCAL_isBaseValid(base));

    base->HRCALCFG |= HRCAL_HRCALCFG_HRCALEN_Set(1);
}

/*!
 * \brief Set HRCAL Update Mode
 *
 * \details Configures the mode for updating calibration parameters.
 *
 * \param[in] base Pointer to the HRCAL peripheral register base address.
 * \param[in] mode An enumerated value from `HRCAL_UpdataMode` specifying the update strategy. 
 * Options may include immediate, on-demand, periodic, or others, as supported by the device.
 *
 * \note The update mode influences system responsiveness and efficiency.
 *
 * \warning Incorrectly configuring the update mode can lead to inefficiencies.
 */
static inline void
HRCAL_setUpdataMode(HRCAL_Type *base, HRCAL_UpdataMode mode)
{
    /* Check the arguments */
    assert(HRCAL_isBaseValid(base));

    base->HRCALCFG = (base->HRCALCFG & ~HRCAL_HRCALCFG_UPMODE_Msk) |
                        HRCAL_HRCALCFG_UPMODE_Set(mode);
}

/*!
 * \brief Select HRCAL Accumulator Bit Width
 *
 * \details Chooses the bit width of the accumulator bitwidth.
 *
 * \param[in] base Pointer to the HRCAL peripheral register base address.
 * \param[in] width An enumerated value from `HRCAL_BitsWidth` specifying the accumulator's bit width. 
 * Options may include 8-bit, 16-bit, 32-bit, etc., based on the device's capabilities.
 *
 * \note Wider bit widths increase precision but may also increase computational demands and memory usage.
 *
 * \warning The selected bit width must be compatible with the device's hardware capabilities.
 */
static inline void
HRCAL_selectAccumulatorBitWidth(HRCAL_Type *base, HRCAL_BitsWidth width)
{
    /* Check the arguments */
    assert(HRCAL_isBaseValid(base));

    base->HRCALCFG = (base->HRCALCFG & ~HRCAL_HRCALCFG_ACCSEL_Msk) | 
                        HRCAL_HRCALCFG_ACCSEL_Set(width);
}

/*!
 * \brief Set HRCAL Counter Period
 *
 * \details Configures the period of the internal counter.
 *
 * \param[in] base Pointer to the HRCAL peripheral register base address.
 * \param[in] period A 32-bit value defining the new counter period in clock 
 * cycles or units as defined by the device documentation.
 *
 * \note Adjusting the counter period can influence calibration speed.
 *
 * \warning Setting counter period can disrupt the calibration process.
 */
static inline void
HRCAL_setCounterPeriod(HRCAL_Type *base, uint32_t period)
{
    /* Check the arguments */
    assert(HRCAL_isBaseValid(base));

    base->HRCALCTRPRD = (base->HRCALCTRPRD & ~HRCAL_HRCALCTRPRD_CTRPRD_Msk) | 
                            HRCAL_HRCALCTRPRD_CTRPRD_Set(period);
}

/*!
 * \brief Enable HRCAL Step Value Adjustment
 *
 * \details Activates the feature that allows automatic adjustment.
 *
 * \param[in] base Pointer to the HRCAL peripheral register base address.
 *
 * \note Enabling this feature can dynamically adapt the calibration process.
 *
 * \warning Automatically adjusting step values may not be suitable.
 */
static inline void
HRCAL_enableStepValueAdjustment(HRCAL_Type *base)
{
    /* Check the arguments */
    assert(HRCAL_isBaseValid(base));

    base->HRCALSTEPCFG |= HRCAL_HRCALSTEPCFG_STEPMODE_Set(1);
}

/*!
 * \brief Set HRCAL Data Storage Number
 *
 * \details Specifies the number of calibration data sets.
 *
 * \param[in] base Pointer to the HRCAL peripheral register base address.
 * \param[in] number An enumerated value from `HRCAL_StorageNumber`.
 *
 * \note Selecting the storage number trades offk.
 *
 * \warning Exceeding the device's supported storage capacity may lead to
 *  undefined behavior or data corruption.
 */
static inline void
HRCAL_setDataStorageNumber(HRCAL_Type *base, HRCAL_StorageNumber number)
{
    /* Check the arguments */
    assert(HRCAL_isBaseValid(base));

    base->HRCALSTORECFG = (base->HRCALSTORECFG & ~HRCAL_HRCALSTORECFG_STOREMODE_Msk) | 
                            HRCAL_HRCALSTORECFG_STOREMODE_Set(number);
}

/*!
 * \brief Set HRCAL Threshold Value
 *
 * \details Configures the threshold value used by the High Resolution Calibration (HRCAL) module.
 *
 * \param[in] base Pointer to the HRCAL peripheral register base address.
 * \param[in] thresh A 16-bit value specifying the new threshold. .
 *
 * \note The threshold value influences the calibration's sensitivity to changes.
 *
 * \warning Incorrectly setting the threshold can degrade calibration performance.
 */
static inline void
HRCAL_setThresholdValue(HRCAL_Type *base, uint16_t thresh)
{
    /* Check the arguments */
    assert(HRCAL_isBaseValid(base));

    base->HRCALSTORECFG = (base->HRCALSTORECFG & ~HRCAL_HRCALSTORECFG_THRESH_Msk) | 
                            HRCAL_HRCALSTORECFG_THRESH_Set(thresh);
}

/*!
 * \brief Get HRCAL Calibration MEP Step Information
 *
 * \details Retrieves the step count or progress of the Most Efficient Point (MEP) 
 * calibration process within the High Resolution Calibration (HRCAL) module.
 *
 * \param[in] base Pointer to the HRCAL peripheral register base address.
 *
 * \return A 32-bit value representing the current step of the MEP calibration.
 *
 * \note This function can be used to monitor the real-time progress.
 *
 * \warning The interpretation of the returned value depends on the specific device documentation.
 */
static inline uint32_t
HRCAL_getCalibrationMEPStep(HRCAL_Type *base)
{
    /* Check the arguments */
    assert(HRCAL_isBaseValid(base));

    /* Read from TBPRD:TBPRDHR bit */
    return HRCAL_HRMSTEP_HRMSTEP_Get(base->HRMSTEP);
}

/*!
 * \brief Retrieve HRCAL Calibration Error Status
 *
 * \details Reads and returns the error status flags indicating any issues
 *  encountered during the most recent High Resolution Calibration (HRCAL) process.
 *
 * \param[in] base Pointer to the HRCAL peripheral register base address.
 *
 * \return A 32-bit value representing the error status. Bit fields correspond to 
 * specific error conditions.
 *
 * \note After a calibration attempt, this function helps diagnose if the process 
 * completed successfully or if errors were detected.
 *
 * \warning Ignoring error statuses may lead to incorrect system behavior.
 */
static inline uint32_t
HRCAL_getCalibrationErrorStatus(HRCAL_Type *base)
{
    /* Check the arguments */
    assert(HRCAL_isBaseValid(base));

    /* Read from TBPRD:TBPRDHR bit */
    return HRCAL_HRCALINT_CALERSTS_Get(base->HRCALINT);
}

/*!
 * \brief Wait for HRCAL Calibration to Complete
 *
 * \details Blocks execution until the High Resolution Calibration 
 * (HRCAL) module finishes its current calibration cycle.
 *
 * \param[in] base Pointer to the HRCAL peripheral register base address.
 *
 * \note This function is typically used in contexts where subsequent 
 * operations depend on a completed calibration.
 *
 * \warning Avoid calling this function in time-critical code paths due to 
 * its blocking nature; consider using interrupts or polling in those scenarios.
 */
static inline void
HRCAL_waitCalibrationCompelet(HRCAL_Type *base)
{
    /* Check the arguments */
    assert(HRCAL_isBaseValid(base));

    /* Read from TBPRD:TBPRDHR bit */
    while(HRCAL_HRCALSTORECFG_LOCKSTS_Get(base->HRCALSTORECFG) == 0);
}

/*!
 *
 * Sets the consolidated phase shift value in high resolution mode.
 *
 * \param base is the base address of the EPWM module.
 * \param channel is the channel of epwm.
 * \param phaseCount is the consolidated phase shift count value.
 *
 * This function sets the consolidated phase shift value, that is, both TBPHS
 * and TBPHSHR values are configured together.
 *
 * Call EPWM_enablePhaseShiftLoad & HRPWM_enableHRPhaseShiftLoad() functions
 * to enable loading of the phaseCount in high resolution mode.
 *
 * \b Note: phaseCount is a 24-bit value.
 * \b Note: For configuring TBPHS = 0x3C, TBPHSHR = 0x2;
 *          phaseCount = 0x3C02
 *
 */
static inline void
HRPWM_setPhaseShift(HRPWM_REGS_Type *base, HRPWM_Channel channel, uint32_t phaseCount)
{
    /* Check the arguments */
    assert(HRPWM_isBaseValid(base));
    assert(phaseCount < 0x1000000U);

    if (channel == HRPWM_CHANNEL_A)
    {
        /* Write to TBPHSHRA bits */
        base->TBPHSHR = (base->TBPHSHR & ~HRPWM_REGS_TBPHSHR_TBPHSHRA_Msk) |
                            HRPWM_REGS_TBPHSHR_TBPHSHRA_Set(phaseCount);
    }
    else if (channel == HRPWM_CHANNEL_B)
    {
        /* Write to TBPHSHRB bits */
        base->TBPHSHR = (base->TBPHSHR & ~HRPWM_REGS_TBPHSHR_TBPHSHRB_Msk) |
                            HRPWM_REGS_TBPHSHR_TBPHSHRB_Set(phaseCount);
    }
}

/*!
 *
 * Sets the consolidated period of time base counter used in HR mode.
 *
 * \param base is the base address of the EPWM module.
 * \param periodCount is the consolidated period count value.
 *
 * This function sets the consolidated period of time base counter value
 * (TBPRD:TBPRDHR) required in high resolution mode.
 *
 * User should map the desired period or frequency of the waveform into
 * the correct periodCount.
 *
 * \b Note: periodCount is a 24 bit value.
 * \b Note: For configuring TBPRD = 0x3C, TBPRDHR = 0xA;
 *          periodCount = 0x3C0A
 *
 */
static inline void
HRPWM_setTimeBasePeriod(HRPWM_REGS_Type *base, uint32_t periodCount)
{
    /* Check the arguments */
    assert(HRPWM_isBaseValid(base));
    assert(periodCount < 0x1000000U);

    /* Write to TBPRD:TBPRDHR bits */
    base->TBPRD = (base->TBPRD & ~HRPWM_REGS_TBPRD_TBPRDHR_Msk) |
                    HRPWM_REGS_TBPRD_TBPRDHR_Set(periodCount);
}

/*!
 *
 * Gets the consolidated time base period count used in HR mode
 *
 * \param base is the base address of the EPWM module.
 *
 * This function gets the consolidated time base period(TBPRD:TBPRDHR) value
 * used in high resolution mode.
 *
 * \return The consolidated time base period count value.
 *
 */
static inline uint32_t
HRPWM_getTimeBasePeriod(HRPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(HRPWM_isBaseValid(base));

    /* Read from TBPRD:TBPRDHR bit */
    return HRPWM_REGS_TBPRD_TBPRDHR_Get(base->TBPRD);
}

/*!
 *
 * Sets the high resolution edge controlled by MEP (Micro Edge Positioner).
 *
 * \param base is the base address of the EPWM module.
 * \param channel is the channel of epwm.
 * \param mepEdgeMode edge of the PWM that is controlled by MEP (Micro Edge
 *        Positioner).
 *
 * This function sets the edge of the PWM that is controlled by MEP (Micro
 * Edge Positioner). Valid values for the parameters are:
 *  - channel
 *      - HRPWM_CHANNEL_A  - HRPWM A
 *      - HRPWM_CHANNEL_B  - HRPWM B
 *  - mepEdgeMode
 *      - HRPWM_MEP_CTRL_DISABLE                 - HRPWM is disabled
 *      - HRPWM_MEP_CTRL_RISING_EDGE             - MEP (Micro Edge Positioner)
 *                                                 controls rising edge.
 *      - HRPWM_MEP_CTRL_FALLING_EDGE            - MEP (Micro Edge Positioner)
 *                                                 controls falling edge.
 *      - HRPWM_MEP_CTRL_RISING_AND_FALLING_EDGE - MEP (Micro Edge Positioner)
 *                                                 controls both edges.
 */
static inline void
HRPWM_setMEPEdgeSelect(HRPWM_REGS_Type *base, HRPWM_Channel channel,
                       HRPWM_MEPEdgeMode mepEdgeMode)
{
    /* Check the arguments */
    assert(HRPWM_isBaseValid(base));

    /* Set the edge mode */
    base->HRCNFG = (base->HRCNFG & ~(0x3U << (uint16_t)channel)) |
                        ((uint16_t)mepEdgeMode << (uint16_t)channel);
}

/*!
 *
 * Sets the MEP (Micro Edge Positioner) control mode.
 *
 * \param base is the base address of the EPWM module.
 * \param channel is high resolution period module.
 * \param mepCtrlMode is the MEP (Micro Edge Positioner) control mode.
 *
 * This function sets the mode (register type) the MEP (Micro Edge Positioner)
 * will control. Valid values for the parameters are:
 *  - channel
 *      - HRPWM_CHANNEL_A  - HRPWM A
 *      - HRPWM_CHANNEL_B  - HRPWM B
 *  - mepCtrlMode
 *      - HRPWM_MEP_DUTY_PERIOD_CTRL      - MEP (Micro Edge Positioner) is
 *                                          controlled by value of CMPAHR/
 *                                          CMPBHR(depending on the value of
 *                                          channel) or TBPRDHR.
 *      - HRPWM_MEP_PHASE_CTRL            - MEP (Micro Edge Positioner) is
 *                                          controlled by TBPHSHR.
 *
 */
static inline void
HRPWM_setMEPControlMode(HRPWM_REGS_Type *base, HRPWM_Channel channel,
                        HRPWM_MEPCtrlMode mepCtrlMode)
{
    /* Check the arguments */
    assert(HRPWM_isBaseValid(base));

    /* Set the MEP control */
    base->HRCNFG = (base->HRCNFG & ~(0x1U << ((uint16_t)channel + 2U))) |
                        ((uint16_t)mepCtrlMode << ((uint16_t)channel + 2U));
}

/*!
 *
 * Sets the high resolution comparator load mode.
 *
 * \param base is the base address of the EPWM module.
 * \param channel is high resolution period module.
 * \param loadEvent is the MEP (Micro Edge Positioner) control mode.
 *
 * This function sets the shadow load mode of the high resolution comparator.
 * The function sets the COMPA or COMPB register depending on the channel
 * variable.
 * Valid values for the parameters are:
 *  - channel
 *      - HRPWM_CHANNEL_A  - HRPWM A
 *      - HRPWM_CHANNEL_B  - HRPWM B
 *  - loadEvent
 *      - HRPWM_LOAD_ON_CNTR_ZERO         - load when counter equals zero
 *      - HRPWM_LOAD_ON_CNTR_PERIOD       - load when counter equals period
 *      - HRPWM_LOAD_ON_CNTR_ZERO_PERIOD  - load when counter equals zero or
 *                                          period
 */
static inline void
HRPWM_setCounterCompareShadowLoadEvent(HRPWM_REGS_Type *base, HRPWM_Channel channel,
                                       HRPWM_LoadMode loadEvent)
{
    /* Check the arguments */
    assert(HRPWM_isBaseValid(base));

    /* Set the CMPAHR or CMPBHR load mode */
    base->HRCNFG = (base->HRCNFG & ~(0x3U << ((uint16_t)channel + 3U))) |
                        ((uint16_t)loadEvent << ((uint16_t)channel + 3U));
}

/*!
 *
 * Sets the high resolution output swap mode.
 *
 * \param base is the base address of the EPWM module.
 * \param enableOutputSwap is the output swap flag.
 *
 * This function sets the HRPWM output swap mode. If enableOutputSwap is true,
 * ePWMxA signal appears on ePWMxB output and ePWMxB signal appears on ePWMxA
 * output. If it is false ePWMxA and ePWMxB outputs are unchanged.
 *
 */
static inline void
HRPWM_setOutputSwapMode(HRPWM_REGS_Type *base, bool enableOutputSwap)
{
    /* Check the arguments */
    assert(HRPWM_isBaseValid(base));

    /* Set output swap mode */
    if(enableOutputSwap)
    {
        base->HRCNFG |= HRPWM_REGS_HRCNFG_SWAPAB_Set(1);
    }
    else
    {
        base->HRCNFG &= ~HRPWM_REGS_HRCNFG_SWAPAB_Set(1);
    }
}

/*!
 *
 * Sets the high resolution output on ePWMxB
 *
 * \param base is the base address of the EPWM module.
 * \param outputOnB is the output signal on ePWMxB.
 *
 * This function sets the HRPWM output signal on ePWMxB. If outputOnB is
 * HRPWM_OUTPUT_ON_B_INV_A, ePWMxB output is an inverted version of
 * ePWMxA. If outputOnB is HRPWM_OUTPUT_ON_B_NORMAL, ePWMxB output is
 * ePWMxB.
 *
 */
static inline void
HRPWM_setChannelBOutputPath(HRPWM_REGS_Type *base, HRPWM_ChannelBOutput outputOnB)
{
    /* Check the arguments */
    assert(HRPWM_isBaseValid(base));

    /* Set the output on ePWM B */
    base->HRCNFG = (base->HRCNFG & ~HRPWM_REGS_HRCNFG_SELOUTB_Msk) |
                        HRPWM_REGS_HRCNFG_SELOUTB_Set(outputOnB);
}

/*!
 *
 * Enables MEP (Micro Edge Positioner) automatic scale mode.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function enables the MEP (Micro Edge Positioner) to automatically
 * scale HRMSTEP.
 *
 * The SFO library will calculate required MEP steps per coarse steps and
 * feed it to HRMSTEP register. The MEP calibration module will use the value
 * in HRMSTEP to determine appropriate number of MEP steps represented by
 * fractional duty cycle.
 *
 */
static inline void
HRPWM_enableAutoConversion(HRPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(HRPWM_isBaseValid(base));

    /* Enable MEP automatic scale */
    base->HRCNFG |= HRPWM_REGS_HRCNFG_AUTOCONV_Set(1);
}

/*!
 *
 * Disables MEP automatic scale mode.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function disables the MEP (Micro Edge Positioner) from automatically
 * scaling HRMSTEP.
 *
 */
static inline void
HRPWM_disableAutoConversion(HRPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(HRPWM_isBaseValid(base));

    /* Disable MEP automatic scale */
    base->HRCNFG &= ~HRPWM_REGS_HRCNFG_AUTOCONV_Set(1);
}

/*!
 *
 * Set high resolution PWMSYNC source.
 *
 * \param base is the base address of the EPWM module.
 * \param syncPulseSource is the PWMSYNC source.
 *
 * This function sets the high resolution PWMSYNC pulse source.
 * Valid values for syncPulseSource are:
 *  - HRPWM_PWMSYNC_SOURCE_PERIOD      - Counter equals Period.
 *  - HRPWM_PWMSYNC_SOURCE_ZERO        - Counter equals zero.
 *  - HRPWM_PWMSYNC_SOURCE_COMPC_UP    - Counter equals COMPC when
 *                                       counting up.
 *  - HRPWM_PWMSYNC_SOURCE_COMPC_DOWN  - Counter equals COMPC when
 *                                       counting down.
 *  - HRPWM_PWMSYNC_SOURCE_COMPD_UP    - Counter equals COMPD when
 *                                       counting up.
 *  - HRPWM_PWMSYNC_SOURCE_COMPD_DOWN  - Counter equals COMPD when
 *                                       counting down.
 *
 */
static inline void
HRPWM_setSyncPulseSource(HRPWM_REGS_Type *base, HRPWM_SyncPulseSource syncPulseSource)
{
    /* Configuration for sync pulse source equal to HRPWM_PWMSYNC_SOURCE_PERIOD 
        or HRPWM_PWMSYNC_SOURCE_ZERO*/
    if(syncPulseSource < HRPWM_PWMSYNC_SOURCE_COMPC_UP)
    {
        base->HRPCTL = (base->HRPCTL & ~(HRPWM_REGS_HRPCTL_PWMSYNCSELX_Msk | HRPWM_REGS_HRPCTL_PWMSYNCSEL_Msk)) |
                            HRPWM_REGS_HRPCTL_PWMSYNCSEL_Set(syncPulseSource);
    }
    else
    {
        base->HRPCTL = (base->HRPCTL & ~(HRPWM_REGS_HRPCTL_PWMSYNCSELX_Msk | HRPWM_REGS_HRPCTL_PWMSYNCSEL_Msk)) |
                            HRPWM_REGS_HRPCTL_PWMSYNCSELX_Set(syncPulseSource);
    }
}

/*!
 *
 * Sets the consolidated RED count in high resolution mode.
 *
 * \param base is the base address of the EPWM module.
 * \param channel is the channel of the EPWM module.
 * \param redCount is the high resolution RED count.
 *
 * This function sets the consolidated RED (Rising Edge Delay) count
 * (DBRED:DBREDHR) value used in high resolution mode. The value of
 * redCount should be less than 0x200000.
 *
 * \b Note: redCount is a 21 bit value.
 * \b Note: For configuring DBRED = 0x4, DBREDHR = 0x1; value of
 *          redCount = ((0x4 << 7) | 0x1) = 0x201
 *
 */
static inline void
HRPWM_setRisingEdgeDelay(HRPWM_REGS_Type *base, HRPWM_Channel channel, uint32_t redCount)
{
    /* Check the arguments */
    assert(HRPWM_isBaseValid(base));

    //
    // Set the consolidated RED (Rising Edge Delay) count
    //
    if (channel == HRPWM_CHANNEL_A)
    {
        base->RISEEDGEHR = (base->RISEEDGEHR & ~HRPWM_REGS_RISEEDGEHR_RISEHRA_Msk) |
                                HRPWM_REGS_RISEEDGEHR_RISEHRA_Set(redCount);
    } 
    else
    {
        base->RISEEDGEHR = (base->RISEEDGEHR & ~HRPWM_REGS_RISEEDGEHR_RISEHRB_Msk) |
                                HRPWM_REGS_RISEEDGEHR_RISEHRB_Set(redCount);
    }
}

/*!
 *
 * Sets the consolidated FED value in high resolution mode.
 *
 * \param base is the base address of the EPWM module.
 * \param channel is the channel of the EPWM module.
 * \param fedCount is the high resolution FED count.
 *
 * This function sets the consolidated FED (Falling Edge Delay) count
 * (DBFED: DBFEDHR) value used in high resolution mode. The value of fedCount
 * should be less than 0x200000.
 *
 * \b Note: fedCount is a 21 bit value.
 * \b Note: For configuring DBFED = 0x4, DBFEDHR = 0x1; value of
 *          fedCount = ((0x4 << 7) | 0x1) = 0x201
 *
 */
static inline void
HRPWM_setFallingEdgeDelay(HRPWM_REGS_Type *base, HRPWM_Channel channel, uint32_t fedCount)
{
    /* Check the arguments */
    assert(HRPWM_isBaseValid(base));

    //
    // Set the High Resolution FED (Falling Edge Delay) count
    //
    if (channel == HRPWM_CHANNEL_A)
    {
        base->FALLEDGEHR = (base->FALLEDGEHR & ~HRPWM_REGS_FALLEDGEHR_FALLHRA_Msk) |
                                HRPWM_REGS_FALLEDGEHR_FALLHRA_Set(fedCount);
    } 
    else
    {
        base->FALLEDGEHR = (base->FALLEDGEHR & ~HRPWM_REGS_FALLEDGEHR_FALLHRB_Msk) |
                                HRPWM_REGS_FALLEDGEHR_FALLHRB_Set(fedCount);
    } 
}

/*!
 *
 * Set the high resolution Dead Band RED load mode.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function sets the high resolution Rising Edge Delay(RED)Dead Band
 * count load mode.
 * Valid values for loadEvent are:
 *   - HRPWM_LOAD_ON_CNTR_ZERO        - load when counter equals zero.
 *   - HRPWM_LOAD_ON_CNTR_PERIOD      - load when counter equals period
 *   - HRPWM_LOAD_ON_CNTR_ZERO_PERIOD - load when counter equals zero
 *                                             or period.
 */
static inline void
HRPWM_setRisingEdgeDelayLoadMode(HRPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(HRPWM_isBaseValid(base));

    //
    // Set the HRPWM RED load mode
    //
    base->HRCNFG = (base->HRCNFG & ~HRPWM_REGS_HRCNFG_CTLMODEA_Msk) | 
                        HRPWM_REGS_HRCNFG_CTLMODEA_Set(1);
    base->HRCNFG = (base->HRCNFG & ~HRPWM_REGS_HRCNFG_EDGMODEA_Msk) | 
                        HRPWM_REGS_HRCNFG_EDGMODEA_Set(1);                   
}

/*!
 *
 * Lock EALLOW protected register groups
 *
 * \param base is the base address of the EPWM module.
 * \param registerGroup is the EALLOW register groups.
 *
 * This functions locks the EALLOW protected register groups specified by
 * the registerGroup variable.
 *
 *   
 *
 */
static inline void
HRPWM_lockRegisters(HRPWM_REGS_Type *base, HRPWM_LockRegisterGroup registerGroup)
{
    /* Check the arguments */
    assert(HRPWM_isBaseValid(base));

    /* Write the Key to EPWMLOCK register */
    base->EPWMLOCK = (0xA5A50000UL | ((uint32_t)registerGroup));
}

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */

#endif /* HTE_HRPWM_H */
