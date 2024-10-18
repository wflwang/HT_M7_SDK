/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*!
 * \file hte_epwm.h
 * \brief SDK EPWM driver header file
 * \version 1.0.0
 */

#ifndef HTE_EPWM_H
#define HTE_EPWM_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_common.h"

/*!
 * \addtogroup DRV_HTE_EPWM EPWM Driver
 *
 * \brief SDK EPWM driver
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*!
 *  The division ratio of the Enhanced Pulse Width Modulation (EPWM) clock.
 */
typedef enum
{
    SYSCTL_EPWMCLK_DIV_1,           /*!< EPWMCLK = PLLSYSCLK / 1 */
    SYSCTL_EPWMCLK_DIV_2            /*!< EPWMCLK = PLLSYSCLK / 2 */
} sysctl_epwmclk_div_e;

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPWMSYNCOUTEN register
//
//*************************************************************************************************
#define EPWM_SYNCOUTEN_SWEN        0x1U    /*!< EPWMxSYNCO Software Force Enable */
#define EPWM_SYNCOUTEN_ZEROEN      0x2U    /*!< EPWMxSYNCO Zero Count Event Enable */
#define EPWM_SYNCOUTEN_CMPBEN      0x4U    /*!< EPWMxSYNCO Compare B Event Enable */
#define EPWM_SYNCOUTEN_CMPCEN      0x8U    /*!< EPWMxSYNCO Compare C Event Enable */
#define EPWM_SYNCOUTEN_CMPDEN      0x10U   /*!< EPWMxSYNCO Compare D Event Enable */
#define EPWM_SYNCOUTEN_DCAEVT1EN   0x20U   /*!< EPWMxSYNCO Digital Compare A Event 1 Sync Enable */
#define EPWM_SYNCOUTEN_DCBEVT1EN   0x40U   /*!< EPWMxSYNCO Digital Compare B Event 1 Sync Enable */

/*!
 * Values that can be passed to EPWM_enableSyncOutPulseSource() &
 * EPWM_disableSyncOutPulseSource() as the \e mode parameter.
 */
#define EPWM_SYNC_OUT_PULSE_ON_SOFTWARE         EPWM_SYNCOUTEN_SWEN           /*!< Software force generated EPWM sync-out pulse */
#define EPWM_SYNC_OUT_PULSE_ON_CNTR_ZERO        EPWM_SYNCOUTEN_ZEROEN         /*!< Counter zero event generates EPWM sync-out pulse */ 
#define EPWM_SYNC_OUT_PULSE_ON_CNTR_COMPARE_B   EPWM_SYNCOUTEN_CMPBEN         /*!< Counter equal to CMPB event generates EPWM sync-out pulse */ 
#define EPWM_SYNC_OUT_PULSE_ON_CNTR_COMPARE_C   EPWM_SYNCOUTEN_CMPCEN         /*!< Counter equal to CMPC event generates EPWM sync-out pulse */ 
#define EPWM_SYNC_OUT_PULSE_ON_CNTR_COMPARE_D   EPWM_SYNCOUTEN_CMPDEN         /*!< Counter equal to CMPD event generates EPWM sync-out pulse */ 
#define EPWM_SYNC_OUT_PULSE_ON_DCA_EVT1_SYNC    EPWM_SYNCOUTEN_DCAEVT1EN      /*!< DCA Event 1 Sync signal generates EPWM sync-out pulse */ 
#define EPWM_SYNC_OUT_PULSE_ON_DCB_EVT1_SYNC    EPWM_SYNCOUTEN_DCBEVT1EN      /*!< DCB Event 1 Sync signal generates EPWM sync-out pulse */ 
#define EPWM_SYNC_OUT_PULSE_ON_ALL              EPWM_SYNC_OUT_SOURCE_M        /*!< Enable all the above sources */ 

/*!
 * \brief Define to specify mask for source parameter for
 *        EPWM_enableSyncOutPulseSource() & EPWM_disableSyncOutPulseSource()
 */
#define EPWM_SYNC_OUT_SOURCE_M    ((uint16_t)EPWM_SYNCOUTEN_SWEN             |\
                                   (uint16_t)EPWM_SYNCOUTEN_ZEROEN           |\
                                   (uint16_t)EPWM_SYNCOUTEN_CMPBEN           |\
                                   (uint16_t)EPWM_SYNCOUTEN_CMPCEN           |\
                                   (uint16_t)EPWM_SYNCOUTEN_CMPDEN           |\
                                   (uint16_t)EPWM_SYNCOUTEN_DCAEVT1EN        |\
                                   (uint16_t)EPWM_SYNCOUTEN_DCBEVT1EN)


/*!
 * Values that can be passed to EPWM_setEmulationMode() as the
 * \e emulationMode parameter.
 */
typedef enum
{ 
   EPWM_EMULATION_STOP_AFTER_NEXT_TB = 0,       /*!< Stop after next Time Base counter increment or decrement */ 
   EPWM_EMULATION_STOP_AFTER_FULL_CYCLE = 1,    /*!< Stop when counter completes whole cycle */ 
   EPWM_EMULATION_FREE_RUN = 2                  /*!< Free run */
} EPWM_EmulationMode;

/*!
 * Values that can be passed to EPWM_setCountModeAfterSync() as the
 * \e mode parameter.
 */
typedef enum
{
   EPWM_COUNT_MODE_DOWN_AFTER_SYNC = 0, /*!< Count down after sync event */
   EPWM_COUNT_MODE_UP_AFTER_SYNC = 1    /*!< Count up after sync event */
} EPWM_SyncCountMode;

/*!
 * Values that can be passed to EPWM_setClockPrescaler() as the
 * \e prescaler parameter.
 */
typedef enum
{
    EPWM_CLOCK_DIVIDER_1 = 0,     /*!< Divide clock by 1 */
    EPWM_CLOCK_DIVIDER_2 = 1,     /*!< Divide clock by 2 */
    EPWM_CLOCK_DIVIDER_4 = 2,     /*!< Divide clock by 4 */
    EPWM_CLOCK_DIVIDER_8 = 3,     /*!< Divide clock by 8 */
    EPWM_CLOCK_DIVIDER_16 = 4,    /*!< Divide clock by 16 */
    EPWM_CLOCK_DIVIDER_32 = 5,    /*!< Divide clock by 32 */
    EPWM_CLOCK_DIVIDER_64 = 6,    /*!< Divide clock by 64 */
    EPWM_CLOCK_DIVIDER_128 = 7    /*!< Divide clock by 128 */
} EPWM_ClockDivider;

/*!
 * Values that can be passed to EPWM_setClockPrescaler() as the
 * \e highSpeedPrescaler parameter.
 */
typedef enum
{
    EPWM_HSCLOCK_DIVIDER_1 = 0,     /*!< Divide clock by 1 */
    EPWM_HSCLOCK_DIVIDER_2 = 1,     /*!< Divide clock by 2 */
    EPWM_HSCLOCK_DIVIDER_4 = 2,     /*!< Divide clock by 4 */
    EPWM_HSCLOCK_DIVIDER_6 = 3,     /*!< Divide clock by 6 */
    EPWM_HSCLOCK_DIVIDER_8 = 4,     /*!< Divide clock by 8 */
    EPWM_HSCLOCK_DIVIDER_10 = 5,    /*!< Divide clock by 10 */
    EPWM_HSCLOCK_DIVIDER_12 = 6,    /*!< Divide clock by 12 */
    EPWM_HSCLOCK_DIVIDER_14 = 7     /*!< Divide clock by 14 */
} EPWM_HSClockDivider;

/*!
 * Values that can be passed to EPWM_setSyncInPulseSource() as the \e mode
 * parameter.
 */
typedef enum
{
    EPWM_SYNC_IN_PULSE_SRC_DISABLE         = 0x0,       /*!< Disable Sync-in */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM1   = 0x1,       /*!< Sync-in source is EPWM1 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM2   = 0x2,       /*!< Sync-in source is EPWM2 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM3   = 0x3,       /*!< Sync-in source is EPWM3 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM4   = 0x4,       /*!< Sync-in source is EPWM4 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM5   = 0x5,       /*!< Sync-in source is EPWM5 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM6   = 0x6,       /*!< Sync-in source is EPWM6 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM7   = 0x7,       /*!< Sync-in source is EPWM7 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM8   = 0x8,       /*!< Sync-in source is EPWM8 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM9   = 0x9,       /*!< Sync-in source is EPWM9 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM10  = 0xA,       /*!< Sync-in source is EPWM10 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM11  = 0xB,       /*!< Sync-in source is EPWM11 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM12  = 0xC,       /*!< Sync-in source is EPWM12 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM13  = 0xD,       /*!< Sync-in source is EPWM13 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM14  = 0xE,       /*!< Sync-in source is EPWM14 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM15  = 0xF,       /*!< Sync-in source is EPWM15 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM16  = 0x10,      /*!< Sync-in source is EPWM16 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP1   = 0x11,      /*!< Sync-in source is ECAP1 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP2   = 0x12,      /*!< Sync-in source is ECAP2 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP3   = 0x13,      /*!< Sync-in source is ECAP3 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP4   = 0x14,      /*!< Sync-in source is ECAP4 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP5   = 0x15,      /*!< Sync-in source is ECAP5 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP6   = 0x16,      /*!< Sync-in source is ECAP6 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP7  = 0x17,       /*!< Sync-in source is ECAP7 sync-out signal */
    EPWM_SYNC_IN_PULSE_SRC_INPUTXBAR_OUT5 = 0x18,       /*!< Sync-in source is Input XBAR out5 signal */
    EPWM_SYNC_IN_PULSE_SRC_INPUTXBAR_OUT6 = 0x19,       /*!< Sync-in source is Input XBAR out6 signal */
    EPWM_SYNC_IN_PULSE_SRC_ETHERCAT_SYNC0 = 0x1A,       /*!< Sync-in source is Ethercat sync0 signal */
    EPWM_SYNC_IN_PULSE_SRC_ETHERCAT_SYNC1 = 0x1B        /*!< Sync-in source is Ethercat sync1 signal */
} EPWM_SyncInPulseSource;

/*!
 * Values that can be passed to EPWM_setOneShotSyncOutTrigger() as the
 * \e trigger parameter.
 */
typedef enum
{
    EPWM_OSHT_SYNC_OUT_TRIG_SYNC   = 0x0, /*!< Trigger is OSHT sync */
    EPWM_OSHT_SYNC_OUT_TRIG_RELOAD = 0x1  /*!< Trigger is OSHT reload */
} EPWM_OneShotSyncOutTrigger;

/*!
 * Values that can be passed to EPWM_setPeriodLoadMode()  as the
 * \e loadMode parameter.
 */
typedef enum
{
    EPWM_PERIOD_SHADOW_LOAD = 0,    /*!< PWM Period register access is through shadow register */
    EPWM_PERIOD_DIRECT_LOAD = 1     /*!< PWM Period register access is directly */
} EPWM_PeriodLoadMode;

/*!
 * Values that can be passed to EPWM_setTimeBaseCounterMode() as the
 * \e counterMode parameter.
 */
typedef enum
{
    EPWM_COUNTER_MODE_UP = 0,         /*!< Up - count mode */
    EPWM_COUNTER_MODE_DOWN = 1,       /*!< Down - count mode */
    EPWM_COUNTER_MODE_UP_DOWN = 2,    /*!< Up - down - count mode */
    EPWM_COUNTER_MODE_STOP_FREEZE = 3 /*!< Stop - Freeze counter */
} EPWM_TimeBaseCountMode;

/*!
 * Values that can be passed to EPWM_selectPeriodLoadEvent() as the
 * \e shadowLoadMode parameter.
 */
typedef enum
{ 
    EPWM_SHADOW_LOAD_MODE_COUNTER_ZERO = 0,     /*!< Shadow to active load occurs when time base counter reaches 0 */ 
    EPWM_SHADOW_LOAD_MODE_COUNTER_SYNC = 1,     /*!< Shadow to active load occurs when time base counter reaches 0 and a SYNC occurs */ 
    EPWM_SHADOW_LOAD_MODE_SYNC         = 2      /*!< Shadow to active load occurs only when a SYNC occurs */
} EPWM_PeriodShadowLoadMode;

/*!
 * Values that can be returned by the EPWM_getTimeBaseCounterDirection() 
 */
#define EPWM_TIME_BASE_STATUS_COUNT_UP                1U    /*!< Time base counter is counting up */
#define EPWM_TIME_BASE_STATUS_COUNT_DOWN              0U    /*!< Time base counter is counting down */

/*!
 * Values that can be passed to EPWM_setupEPWMLinks() as the \e epwmLink
 * parameter.
 */
typedef enum
{
    EPWM_LINK_WITH_EPWM_1 = 0,   /*!< link current ePWM with ePWM1 */
    EPWM_LINK_WITH_EPWM_2 = 1,   /*!< link current ePWM with ePWM2 */
    EPWM_LINK_WITH_EPWM_3 = 2,   /*!< link current ePWM with ePWM3 */
    EPWM_LINK_WITH_EPWM_4 = 3,   /*!< link current ePWM with ePWM4 */
    EPWM_LINK_WITH_EPWM_5 = 4,   /*!< link current ePWM with ePWM5 */
    EPWM_LINK_WITH_EPWM_6 = 5,   /*!< link current ePWM with ePWM6 */
    EPWM_LINK_WITH_EPWM_7 = 6,   /*!< link current ePWM with ePWM7 */
    EPWM_LINK_WITH_EPWM_8 = 7,   /*!< link current ePWM with ePWM8 */ 
    EPWM_LINK_WITH_EPWM_9 = 8,   /*!< link current ePWM with ePWM9 */
    EPWM_LINK_WITH_EPWM_10 = 9,   /*!< link current ePWM with ePWM10 */
    EPWM_LINK_WITH_EPWM_11 = 10,   /*!< link current ePWM with ePWM11 */
    EPWM_LINK_WITH_EPWM_12 = 11,   /*!< link current ePWM with ePWM12 */
    EPWM_LINK_WITH_EPWM_13 = 12,   /*!< link current ePWM with ePWM13 */
    EPWM_LINK_WITH_EPWM_14 = 13,   /*!< link current ePWM with ePWM14 */
    EPWM_LINK_WITH_EPWM_15 = 14,   /*!< link current ePWM with ePWM15 */
    EPWM_LINK_WITH_EPWM_16 = 15    /*!< link current ePWM with ePWM16 */
} EPWM_CurrentLink;

/*!
 * Values that can be passed to EPWM_setupEPWMLinks() as the \e linkComp
 * parameter.
 */
typedef enum
{
    EPWM_LINK_TBPRD   = 0,  /*!< Link TBPRD:TBPRDHR registers */
    EPWM_LINK_COMP_A  = 4,  /*!< Link COMPA registers */
    EPWM_LINK_COMP_B  = 8,  /*!< Link COMPB registers */
    EPWM_LINK_COMP_C  = 12, /*!< Link COMPC registers */
    EPWM_LINK_COMP_D  = 16, /*!< Link COMPD registers */
    EPWM_LINK_GLDCTL2 = 28  /*!< Link GLDCTL2 registers */
} EPWM_LinkComponent;

/*!
 * Values that can be passed to the EPWM_getCounterCompareShadowStatus(),
 * EPWM_setCounterCompareValue(), EPWM_setCounterCompareShadowLoadMode(),
 * EPWM_disableCounterCompareShadowLoadMode()
 * as the \e compModule parameter.
 */
typedef enum
{
    EPWM_COUNTER_COMPARE_A = 0, /*!< Counter compare A */
    EPWM_COUNTER_COMPARE_B = 4, /*!< Counter compare B */
    EPWM_COUNTER_COMPARE_C = 10, /*!< Counter compare C */
    EPWM_COUNTER_COMPARE_D = 14  /*!< Counter compare D */
} EPWM_CounterCompareModule;

/*!
 * Values that can be passed to EPWM_setCounterCompareShadowLoadMode() as the
 * \e loadMode parameter.
 */
typedef enum
{
    EPWM_COMP_LOAD_ON_CNTR_ZERO = 0,               /*!< Load when counter equals zero */
    EPWM_COMP_LOAD_ON_CNTR_PERIOD = 1,             /*!< Load when counter equals period */
    EPWM_COMP_LOAD_ON_CNTR_ZERO_PERIOD = 2,        /*!< Load when counter equals zero or period */
    EPWM_COMP_LOAD_FREEZE = 3,                     /*!< Freeze shadow to active load */
    EPWM_COMP_LOAD_ON_SYNC_CNTR_ZERO = 4,          /*!< Load on sync or when counter equals zero */
    EPWM_COMP_LOAD_ON_SYNC_CNTR_PERIOD = 5,        /*!< Load on sync or when counter equals period */
    EPWM_COMP_LOAD_ON_SYNC_CNTR_ZERO_PERIOD = 6,   /*!< Load on sync or when counter equals zero or period */
    EPWM_COMP_LOAD_ON_SYNC_ONLY = 8                /*!< Load on sync only */
} EPWM_CounterCompareLoadMode;

/*!
 * Values that can be passed to EPWM_setActionQualifierShadowLoadMode() and
 * EPWM_disableActionQualifierShadowLoadMode() as the \e aqModule parameter.
 */
typedef enum
{
    EPWM_ACTION_QUALIFIER_A = 0, /*!< Action Qualifier A */
    EPWM_ACTION_QUALIFIER_B = 2  /*!< Action Qualifier B */
} EPWM_ActionQualifierModule;

/*!
 * Values that can be passed to EPWM_setActionQualifierShadowLoadMode() as the
 * \e loadMode parameter.
 */
typedef enum
{
    EPWM_AQ_LOAD_ON_CNTR_ZERO = 0,                  /*!< Load when counter equals zero */
    EPWM_AQ_LOAD_ON_CNTR_PERIOD = 1,                /*!< Load when counter equals period */
    EPWM_AQ_LOAD_ON_CNTR_ZERO_PERIOD = 2,           /*!< Load when counter equals zero or period */
    EPWM_AQ_LOAD_FREEZE = 3,                        /*!< Freeze shadow to active load */
    EPWM_AQ_LOAD_ON_SYNC_CNTR_ZERO = 4,             /*!< Load on sync or when counter equals zero */
    EPWM_AQ_LOAD_ON_SYNC_CNTR_PERIOD = 5,           /*!< Load on sync or when counter equals period */
    EPWM_AQ_LOAD_ON_SYNC_CNTR_ZERO_PERIOD = 6,      /*!< Load on sync or when counter equals zero or period */
    EPWM_AQ_LOAD_ON_SYNC_ONLY = 8                   /*!< Load on sync only */
} EPWM_ActionQualifierLoadMode;

/*!
 * Values that can be passed to EPWM_setActionQualifierT1TriggerSource() and
 * EPWM_setActionQualifierT2TriggerSource() as the \e trigger parameter.
 */
typedef enum
{
    EPWM_AQ_TRIGGER_EVENT_TRIG_DCA_1 = 0,      /*!< Digital compare event A 1 */
    EPWM_AQ_TRIGGER_EVENT_TRIG_DCA_2 = 1,      /*!< Digital compare event A 2 */
    EPWM_AQ_TRIGGER_EVENT_TRIG_DCB_1 = 2,      /*!< Digital compare event B 1 */
    EPWM_AQ_TRIGGER_EVENT_TRIG_DCB_2 = 3,      /*!< Digital compare event B 2 */
    EPWM_AQ_TRIGGER_EVENT_TRIG_TZ_1  = 4,      /*!< Trip zone 1 */
    EPWM_AQ_TRIGGER_EVENT_TRIG_TZ_2  = 5,      /*!< Trip zone 2 */
    EPWM_AQ_TRIGGER_EVENT_TRIG_TZ_3  = 6,      /*!< Trip zone 3 */
    EPWM_AQ_TRIGGER_EVENT_TRIG_EPWM_SYNCIN = 7,/*!< ePWM sync */
    EPWM_AQ_TRIGGER_EVENT_TRIG_DC_EVTFILT = 8  /*!< Digital compare filter event */
} EPWM_ActionQualifierTriggerSource;

/*!
 * Values that can be passed to EPWM_setActionQualifierAction() as the \e
 * event parameter.
 */
typedef enum
{
    EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO       = 0,  /*!< Time base counter equals zero */
    EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD     = 2,  /*!< Time base counter equals period */
    EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA    = 4,  /*!< Time base counter up equals COMPA */
    EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA  = 6,  /*!< Time base counter down equals COMPA */
    EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB    = 8,  /*!< Time base counter up equals COMPB */
    EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB  = 10, /*!< Time base counter down equals COMPB */
    EPWM_AQ_OUTPUT_ON_T1_COUNT_UP         = 1,  /*!< T1 event on count up */
    EPWM_AQ_OUTPUT_ON_T1_COUNT_DOWN       = 3,  /*!< T1 event on count down */
    EPWM_AQ_OUTPUT_ON_T2_COUNT_UP         = 5,  /*!< T2 event on count up */
    EPWM_AQ_OUTPUT_ON_T2_COUNT_DOWN       = 7   /*!< T2 event on count down */
} EPWM_ActionQualifierOutputEvent;

/*!
 * Values that can be passed to EPWM_setActionQualifierSWAction(),
 * EPWM_setActionQualifierAction() as the \e outPut parameter.
 */
typedef enum
{
    EPWM_AQ_OUTPUT_NO_CHANGE = 0,  /*!< No change in the output pins */
    EPWM_AQ_OUTPUT_LOW       = 1,  /*!< Set output pins to low */
    EPWM_AQ_OUTPUT_HIGH      = 2,  /*!< Set output pins to High */
    EPWM_AQ_OUTPUT_TOGGLE    = 3   /*!< Toggle the output pins */
} EPWM_ActionQualifierOutput;

/*!
 * Values that can be passed to EPWM_setActionQualifierContSWForceAction()
 * as the \e outPut parameter.
 */
typedef enum
{
    EPWM_AQ_SW_DISABLED         = 0,  /*!< Software forcing disabled */
    EPWM_AQ_SW_OUTPUT_LOW       = 1,  /*!< Set output pins to low */
    EPWM_AQ_SW_OUTPUT_HIGH      = 2   /*!< Set output pins to High */
} EPWM_ActionQualifierSWOutput;

/*!
 * Values that can be passed to EPWM_setActionQualifierActionComplete()
 * as the \e action parameter.
 */
typedef enum
{
    EPWM_AQ_OUTPUT_NO_CHANGE_ZERO = 0x0,                /*!< Time base counter equals zero and no change in the output pins */
    EPWM_AQ_OUTPUT_LOW_ZERO = 0x1,                      /*!< Time base counter equals zero and set output pins to low */
    EPWM_AQ_OUTPUT_HIGH_ZERO = 0x2,                     /*!< Time base counter equals zero and set output pins to high */
    EPWM_AQ_OUTPUT_TOGGLE_ZERO = 0x3,                   /*!< Time base counter equals zero and toggle the output pins */
    EPWM_AQ_OUTPUT_NO_CHANGE_PERIOD = 0x0,              /*!< Time base counter equals period and no change in the output pins */
    EPWM_AQ_OUTPUT_LOW_PERIOD = 0x4,                    /*!< Time base counter equals period and set output pins to low */
    EPWM_AQ_OUTPUT_HIGH_PERIOD = 0x8,                   /*!< Time base counter equals period and set output pins to high */
    EPWM_AQ_OUTPUT_TOGGLE_PERIOD = 0xC,                 /*!< Time base counter equals period and toggle the output pins */
    EPWM_AQ_OUTPUT_NO_CHANGE_UP_CMPA = 0x00,            /*!< Time base counter up equals COMPA and no change in the output pins */
    EPWM_AQ_OUTPUT_LOW_UP_CMPA = 0x10,                  /*!< Time base counter up equals COMPA and set output pins to low */
    EPWM_AQ_OUTPUT_HIGH_UP_CMPA = 0x20,                 /*!< Time base counter up equals COMPA and set output pins to high */
    EPWM_AQ_OUTPUT_TOGGLE_UP_CMPA = 0x30,               /*!< Time base counter up equals COMPA and toggle the output pins */
    EPWM_AQ_OUTPUT_NO_CHANGE_DOWN_CMPA = 0x00,          /*!< Time base counter down equals COMPA and no change in the output pins */
    EPWM_AQ_OUTPUT_LOW_DOWN_CMPA = 0x40,                /*!< Time base counter down equals COMPA and set output pins to low */
    EPWM_AQ_OUTPUT_HIGH_DOWN_CMPA = 0x80,               /*!< Time base counter down equals COMPA and set output pins to high */
    EPWM_AQ_OUTPUT_TOGGLE_DOWN_CMPA = 0xC0,             /*!< Time base counter down equals COMPA and toggle the output pins */
    EPWM_AQ_OUTPUT_NO_CHANGE_UP_CMPB = 0x000,           /*!< Time base counter up equals COMPB and no change in the output pins */
    EPWM_AQ_OUTPUT_LOW_UP_CMPB = 0x100,                 /*!< Time base counter up equals COMPB and set output pins to low */
    EPWM_AQ_OUTPUT_HIGH_UP_CMPB = 0x200,                /*!< Time base counter up equals COMPB and set output pins to high */
    EPWM_AQ_OUTPUT_TOGGLE_UP_CMPB = 0x300,              /*!< Time base counter up equals COMPB and toggle the output pins */
    EPWM_AQ_OUTPUT_NO_CHANGE_DOWN_CMPB = 0x000,         /*!< Time base counter down equals COMPB and no change in the output pins */
    EPWM_AQ_OUTPUT_LOW_DOWN_CMPB = 0x400,               /*!< Time base counter down equals COMPB and set output pins to low */
    EPWM_AQ_OUTPUT_HIGH_DOWN_CMPB = 0x800,              /*!< Time base counter down equals COMPB and set output pins to high */
    EPWM_AQ_OUTPUT_TOGGLE_DOWN_CMPB = 0xC00             /*!< Time base counter down equals COMPB and toggle the output pins */
} EPWM_ActionQualifierEventAction;

/*!
 * Values that can be passed to
 * EPWM_setAdditionalActionQualifierActionComplete()  as the \e action
 * parameter.
 */
typedef enum
{
    EPWM_AQ_OUTPUT_NO_CHANGE_UP_T1 = 0x0,           /*!< T1 event on count up and no change in the output pins */
    EPWM_AQ_OUTPUT_LOW_UP_T1 = 0x1,                 /*!< T1 event on count up and set output pins to low */
    EPWM_AQ_OUTPUT_HIGH_UP_T1 = 0x2,                /*!< T1 event on count up and set output pins to high */
    EPWM_AQ_OUTPUT_TOGGLE_UP_T1 = 0x3,              /*!< T1 event on count up and toggle the output pins */
    EPWM_AQ_OUTPUT_NO_CHANGE_DOWN_T1 = 0x0,         /*!< T1 event on count down and no change in the output pins */
    EPWM_AQ_OUTPUT_LOW_DOWN_T1 = 0x4,               /*!< T1 event on count down and set output pins to low */
    EPWM_AQ_OUTPUT_HIGH_DOWN_T1 = 0x8,              /*!< T1 event on count down and set output pins to high */
    EPWM_AQ_OUTPUT_TOGGLE_DOWN_T1 = 0xC,            /*!< T1 event on count down and toggle the output pins */
    EPWM_AQ_OUTPUT_NO_CHANGE_UP_T2 = 0x00,          /*!< T2 event on count up and no change in the output pins */
    EPWM_AQ_OUTPUT_LOW_UP_T2 = 0x10,                /*!< T2 event on count up and set output pins to low */
    EPWM_AQ_OUTPUT_HIGH_UP_T2 = 0x20,               /*!< T2 event on count up and set output pins to high */
    EPWM_AQ_OUTPUT_TOGGLE_UP_T2 = 0x30,             /*!< T2 event on count up and toggle the output pins */
    EPWM_AQ_OUTPUT_NO_CHANGE_DOWN_T2 = 0x00,        /*!< T2 event on count down and no change in the output pins */
    EPWM_AQ_OUTPUT_LOW_DOWN_T2 = 0x40,              /*!< T2 event on count down and set output pins to low */
    EPWM_AQ_OUTPUT_HIGH_DOWN_T2 = 0x80,             /*!< T2 event on count down and set output pins to high */
    EPWM_AQ_OUTPUT_TOGGLE_DOWN_T2 = 0xC0            /*!< T2 event on count down and toggle the output pins */
} EPWM_AdditionalActionQualifierEventAction;

/*!
 * Values that can be passed to EPWM_forceActionQualifierSWAction(),
 * EPWM_setActionQualifierSWAction(), EPWM_setActionQualifierAction()
 * EPWM_setActionQualifierContSWForceAction() as the \e epwmOutput parameter.
 */
typedef enum
{
    EPWM_AQ_OUTPUT_A = 0, /*!< ePWMxA output */
    EPWM_AQ_OUTPUT_B = 4  /*!< ePWMxB output */
} EPWM_ActionQualifierOutputModule;

/*!
 * Values that can be passed to EPWM_setActionQualifierContSWForceShadowMode()
 * as the \e mode parameter.
 */
typedef enum
{
    EPWM_AQ_SW_SH_LOAD_ON_CNTR_ZERO        = 0,     /*!< Shadow mode load when counter equals zero */
    EPWM_AQ_SW_SH_LOAD_ON_CNTR_PERIOD      = 1,     /*!< Shadow mode load when counter equals period */
    EPWM_AQ_SW_SH_LOAD_ON_CNTR_ZERO_PERIOD = 2,     /*!< Shadow mode load when counter equals zero or period */
    EPWM_AQ_SW_IMMEDIATE_LOAD   = 3                 /*!< No shadow load mode. Immediate mode only. */
} EPWM_ActionQualifierContForce;

/*!
 * Values that can be passed to EPWM_setDeadBandOutputSwapMode()
 * as the \e output parameter.
 */
typedef enum
{
    EPWM_DB_OUTPUT_A = 1, /*!< DB output is ePWMA */
    EPWM_DB_OUTPUT_B = 0  /*!< DB output is ePWMB */
} EPWM_DeadBandOutput;

/*!
 * Values that can be passed to EPWM_setDeadBandDelayPolarity(),
 * EPWM_setDeadBandDelayMode() as the \e delayMode parameter.
 */
typedef enum
{
    EPWM_DB_RED = 1, /*!< DB RED (Rising Edge Delay) mode */
    EPWM_DB_FED = 0  /*!< DB FED (Falling Edge Delay) mode */
} EPWM_DeadBandDelayMode;

/*!
 * Values that can be passed to EPWM_setDeadBandDelayPolarity as the
 * \e polarity parameter.
 */
typedef enum
{
    EPWM_DB_POLARITY_ACTIVE_HIGH = 0, /*!< DB polarity is not inverted */
    EPWM_DB_POLARITY_ACTIVE_LOW  = 1  /*!< DB polarity is inverted */
} EPWM_DeadBandPolarity;

/*!
 * Values that can be passed to EPWM_setRisingEdgeDeadBandDelayInput(),
 * EPWM_setFallingEdgeDeadBandDelayInput() as the input parameter.
 */
#define EPWM_DB_INPUT_EPWMA       0U    /*!< Input signal is ePWMA */
#define EPWM_DB_INPUT_EPWMB       1U    /*!< Input signal is ePWMB */
#define EPWM_DB_INPUT_DB_RED      2U    /*!< Input signal is the output of Rising Edge delay */

/*!
 * Values that can be passed to EPWM_setDeadBandControlShadowLoadMode() as
 * the \e loadMode parameter.
 */
typedef enum
{
    EPWM_DB_LOAD_ON_CNTR_ZERO        = 0,   /*!< Load when counter equals zero */
    EPWM_DB_LOAD_ON_CNTR_PERIOD      = 1,   /*!< Load when counter equals period */
    EPWM_DB_LOAD_ON_CNTR_ZERO_PERIOD = 2,   /*!< Load when counter equals zero or period */
    EPWM_DB_LOAD_FREEZE = 3                 /*!< Freeze shadow to active load */
} EPWM_DeadBandControlLoadMode;

/*!
 * Values that can be passed to EPWM_setRisingEdgeDelayCountShadowLoadMode()
 * as the \e loadMode parameter.
 */
typedef enum
{
    EPWM_RED_LOAD_ON_CNTR_ZERO        = 0,  /*!< Load when counter equals zero */
    EPWM_RED_LOAD_ON_CNTR_PERIOD      = 1,  /*!< Load when counter equals period */
    EPWM_RED_LOAD_ON_CNTR_ZERO_PERIOD = 2,  /*!< Load when counter equals zero or period */
    EPWM_RED_LOAD_FREEZE = 3                /*!< Freeze shadow to active load */
} EPWM_RisingEdgeDelayLoadMode;

/*!
 * Values that can be passed to EPWM_setFallingEdgeDelayCountShadowLoadMode()
 * as the \e loadMode parameter.
 */
typedef enum
{
    EPWM_FED_LOAD_ON_CNTR_ZERO        = 0,  /*!< Load when counter equals zero */
    EPWM_FED_LOAD_ON_CNTR_PERIOD      = 1,  /*!< Load when counter equals period */
    EPWM_FED_LOAD_ON_CNTR_ZERO_PERIOD = 2,  /*!< Load when counter equals zero or period */
    EPWM_FED_LOAD_FREEZE = 3                /*!< Freeze shadow to active load */
} EPWM_FallingEdgeDelayLoadMode;

/*!
 * Values that can be passed to EPWM_setDeadBandCounterClock() as the
 * \e clockMode parameter.
 */
typedef enum
{
    EPWM_DB_COUNTER_CLOCK_FULL_CYCLE = 0,   /*!< Dead band counter runs at TBCLK rate */
    EPWM_DB_COUNTER_CLOCK_HALF_CYCLE = 1    /*!< Dead band counter runs at 2*TBCLK rate */
} EPWM_DeadBandClockMode;

/*!
 * Values that can be passed to EPWM_enableTripZoneSignals() and
 * EPWM_disableTripZoneSignals() as the tzSignal parameter.
 */
#define EPWM_TZ_SIGNAL_CBC1          0x1U       /*!< TZ1 Cycle By Cycle */
#define EPWM_TZ_SIGNAL_CBC2          0x2U       /*!< TZ2 Cycle By Cycle */
#define EPWM_TZ_SIGNAL_CBC3          0x4U       /*!< TZ3 Cycle By Cycle */
#define EPWM_TZ_SIGNAL_CBC4          0x8U       /*!< TZ4 Cycle By Cycle */
#define EPWM_TZ_SIGNAL_CBC5          0x10U      /*!< TZ5 Cycle By Cycle */
#define EPWM_TZ_SIGNAL_CBC6          0x20U      /*!< TZ6 Cycle By Cycle */
#define EPWM_TZ_SIGNAL_DCAEVT2       0x40U      /*!< DCAEVT2 Cycle By Cycle */
#define EPWM_TZ_SIGNAL_DCBEVT2       0x80U      /*!< DCBEVT2 Cycle By Cycle */
#define EPWM_TZ_SIGNAL_OSHT1         0x100U     /*!< One-shot TZ1 */
#define EPWM_TZ_SIGNAL_OSHT2         0x200U     /*!< One-shot TZ2 */
#define EPWM_TZ_SIGNAL_OSHT3         0x400U     /*!< One-shot TZ3 */
#define EPWM_TZ_SIGNAL_OSHT4         0x800U     /*!< One-shot TZ4 */
#define EPWM_TZ_SIGNAL_OSHT5         0x1000U    /*!< One-shot TZ5 */
#define EPWM_TZ_SIGNAL_OSHT6         0x2000U    /*!< One-shot TZ6 */
#define EPWM_TZ_SIGNAL_DCAEVT1       0x4000U    /*!< One-shot DCAEVT1 */
#define EPWM_TZ_SIGNAL_DCBEVT1       0x8000U    /*!< One-shot DCBEVT1 */

/*!
 * Values that can be passed to EPWM_setTripZoneDigitalCompareEventCondition()
 * as the \e dcType parameter.
 */
typedef enum
{
    EPWM_TZ_DC_OUTPUT_A1 = 0, /*!< Digital Compare output 1 A */
    EPWM_TZ_DC_OUTPUT_A2 = 3, /*!< Digital Compare output 2 A */
    EPWM_TZ_DC_OUTPUT_B1 = 6, /*!< Digital Compare output 1 B */
    EPWM_TZ_DC_OUTPUT_B2 = 9  /*!< Digital Compare output 2 B */
} EPWM_TripZoneDigitalCompareOutput;

/*!
 * Values that can be passed to EPWM_setTripZoneDigitalCompareEventCondition()
 * as the \e dcEvent parameter.
 */
typedef enum
{
    EPWM_TZ_EVENT_DC_DISABLED = 0,       /*!< Event is disabled */
    EPWM_TZ_EVENT_DCXH_LOW    = 1,       /*!< Event when DCxH low */
    EPWM_TZ_EVENT_DCXH_HIGH   = 2,       /*!< Event when DCxH high */
    EPWM_TZ_EVENT_DCXL_LOW    = 3,       /*!< Event when DCxL low */
    EPWM_TZ_EVENT_DCXL_HIGH   = 4,       /*!< Event when DCxL high */
    EPWM_TZ_EVENT_DCXL_HIGH_DCXH_LOW = 5 /*!< Event when DCxL high DCxH low */
} EPWM_TripZoneDigitalCompareOutputEvent;

/*!
 * Values that can be passed to EPWM_setTripZoneAction() as the \e tzEvent
 * parameter.
 */
typedef enum
{
    EPWM_TZ_ACTION_EVENT_TZA = 0,     /*!< TZ1 - TZ6, DCAEVT2, DCAEVT1 */
    EPWM_TZ_ACTION_EVENT_TZB = 2,     /*!< TZ1 - TZ6, DCBEVT2, DCBEVT1 */
    EPWM_TZ_ACTION_EVENT_DCAEVT1 = 4, /*!< DCAEVT1 (Digital Compare A event 1) */
    EPWM_TZ_ACTION_EVENT_DCAEVT2 = 6, /*!< DCAEVT2 (Digital Compare A event 2) */
    EPWM_TZ_ACTION_EVENT_DCBEVT1 = 8, /*!< DCBEVT1 (Digital Compare B event 1) */
    EPWM_TZ_ACTION_EVENT_DCBEVT2 = 10 /*!< DCBEVT2 (Digital Compare B event 2) */
} EPWM_TripZoneEvent;

/*!
 * Values that can be passed to EPWM_setTripZoneAction() as the
 * \e tzAction parameter.
 */
typedef enum
{
    EPWM_TZ_ACTION_HIGH_Z  = 0, /*!< High impedance output */
    EPWM_TZ_ACTION_HIGH    = 1, /*!< High voltage state */
    EPWM_TZ_ACTION_LOW     = 2, /*!< Low voltage state */
    EPWM_TZ_ACTION_DISABLE = 3  /*!< Disable action */
} EPWM_TripZoneAction;

/*!
 * Values that can be passed to EPWM_setTripZoneAdvAction() as the
 * \e tzAdvEvent parameter.
 */
typedef enum
{
    EPWM_TZ_ADV_ACTION_EVENT_TZB_D = 9,     /*!< TZ1 - TZ6, DCBEVT2, DCBEVT1 while counting down */
    EPWM_TZ_ADV_ACTION_EVENT_TZB_U = 6,     /*!< TZ1 - TZ6, DCBEVT2, DCBEVT1 while counting up */
    EPWM_TZ_ADV_ACTION_EVENT_TZA_D = 3,     /*!< TZ1 - TZ6, DCAEVT2, DCAEVT1 while counting down */
    EPWM_TZ_ADV_ACTION_EVENT_TZA_U = 0      /*!< TZ1 - TZ6, DCAEVT2, DCAEVT1 while counting up */
} EPWM_TripZoneAdvancedEvent;

/*!
 * Values that can be passed to EPWM_setTripZoneAdvDigitalCompareActionA(),
 * EPWM_setTripZoneAdvDigitalCompareActionB(),EPWM_setTripZoneAdvAction()
 * as the \e tzAdvDCAction parameter.
 */
typedef enum
{
    EPWM_TZ_ADV_ACTION_HIGH_Z  = 0, /*!< High impedance output */
    EPWM_TZ_ADV_ACTION_HIGH    = 1, /*!< High voltage state */
    EPWM_TZ_ADV_ACTION_LOW     = 2, /*!< Low voltage state */
    EPWM_TZ_ADV_ACTION_TOGGLE  = 3, /*!< Toggle the output */
    EPWM_TZ_ADV_ACTION_DISABLE = 7  /*!< Disable action */
} EPWM_TripZoneAdvancedAction;

/*!
 * Values that can be passed to EPWM_setTripZoneAdvDigitalCompareActionA() and
 * EPWM_setTripZoneAdvDigitalCompareActionB() as the \e tzAdvDCEvent
 * parameter.
 */
typedef enum
{
    EPWM_TZ_ADV_ACTION_EVENT_DCxEVT1_U = 0,     /*!< Digital Compare event A/B 1 while counting up */
    EPWM_TZ_ADV_ACTION_EVENT_DCxEVT1_D = 3,     /*!< Digital Compare event A/B 1 while counting down */
    EPWM_TZ_ADV_ACTION_EVENT_DCxEVT2_U = 6,     /*!< Digital Compare event A/B 2 while counting up */
    EPWM_TZ_ADV_ACTION_EVENT_DCxEVT2_D = 9      /*!< Digital Compare event A/B 2 while counting down */
} EPWM_TripZoneAdvDigitalCompareEvent;

/*!
 *  Values that can be passed to EPWM_enableTripZoneInterrupt()and
 * EPWM_disableTripZoneInterrupt() as the tzInterrupt parameter .
 */
#define EPWM_TZ_INTERRUPT_CBC      0x2U         /*!< Trip Zones Cycle By Cycle interrupt */
#define EPWM_TZ_INTERRUPT_OST      0x4U         /*!< Trip Zones One Shot interrupt */
#define EPWM_TZ_INTERRUPT_DCAEVT1  0x8U         /*!< Digital Compare A Event 1 interrupt */
#define EPWM_TZ_INTERRUPT_DCAEVT2  0x10U        /*!< Digital Compare A Event 2 interrupt */
#define EPWM_TZ_INTERRUPT_DCBEVT1  0x20U        /*!< Digital Compare B Event 1 interrupt */
#define EPWM_TZ_INTERRUPT_DCBEVT2  0x40U        /*!< Digital Compare B Event 2 interrupt */

/*!
 * Values that can be returned by EPWM_getTripZoneFlagStatus() .
 */
#define EPWM_TZ_FLAG_CBC      0x2U              /*!< Trip Zones Cycle By Cycle flag */
#define EPWM_TZ_FLAG_OST      0x4U              /*!< Trip Zones One Shot flag */
#define EPWM_TZ_FLAG_DCAEVT1  0x8U              /*!< Digital Compare A Event 1 flag */
#define EPWM_TZ_FLAG_DCAEVT2  0x10U             /*!< Digital Compare A Event 2 flag */
#define EPWM_TZ_FLAG_DCBEVT1  0x20U             /*!< Digital Compare B Event 1 flag */
#define EPWM_TZ_FLAG_DCBEVT2  0x40U             /*!< Digital Compare B Event 2 flag */

/*!
 * Value can be passed to EPWM_clearTripZoneFlag() as the
 * tzInterrupt parameter and returned by EPWM_getTripZoneFlagStatus().
 */
#define EPWM_TZ_INTERRUPT     0x1U              /*!< Trip Zone interrupt */

/*!
 * Values that can be passed to EPWM_clearCycleByCycleTripZoneFlag()
 * as the tzCbcFlag parameter and returned by
 * EPWM_getCycleByCycleTripZoneFlagStatus().
 */
#define EPWM_TZ_CBC_FLAG_1  0x1U                /*!< CBC flag 1 */
#define EPWM_TZ_CBC_FLAG_2  0x2U                /*!< CBC flag 2 */
#define EPWM_TZ_CBC_FLAG_3  0x4U                /*!< CBC flag 3 */
#define EPWM_TZ_CBC_FLAG_4  0x8U                /*!< CBC flag 4 */
#define EPWM_TZ_CBC_FLAG_5  0x10U               /*!< CBC flag 5 */
#define EPWM_TZ_CBC_FLAG_6   0x20U              /*!< CBC flag 6 */
#define EPWM_TZ_CBC_FLAG_DCAEVT2  0x40U         /*!< CBC flag Digital compare event A2 */
#define EPWM_TZ_CBC_FLAG_DCBEVT2  0x80U         /*!< CBC flag Digital compare event B2 */

/*!
 * Values that can be passed to EPWM_clearOneShotTripZoneFlag() as
 * the tzCbcFlag parameter and returned by the
 * EPWM_getOneShotTripZoneFlagStatus().
 */
#define EPWM_TZ_OST_FLAG_OST1  0x1U             /*!< OST flag OST1 */
#define EPWM_TZ_OST_FLAG_OST2  0x2U             /*!< OST flag OST2 */
#define EPWM_TZ_OST_FLAG_OST3  0x4U             /*!< OST flag OST3 */
#define EPWM_TZ_OST_FLAG_OST4  0x8U             /*!< OST flag OST4 */
#define EPWM_TZ_OST_FLAG_OST5  0x10U            /*!< OST flag OST5 */
#define EPWM_TZ_OST_FLAG_OST6  0x20U            /*!< OST flag OST6 */
#define EPWM_TZ_OST_FLAG_DCAEVT1   0x40U        /*!< OST flag Digital compare event A1 */
#define EPWM_TZ_OST_FLAG_DCBEVT1   0x80U        /*!< OST flag Digital compare event B1 */

/*!
 * Values that can be passed to EPWM_selectCycleByCycleTripZoneClearEvent() as
 * the \e clearMode parameter.
 */
typedef enum
{
    EPWM_TZ_CBC_PULSE_CLR_CNTR_ZERO = 0,        /*!< Clear CBC pulse when counter equals zero */
    EPWM_TZ_CBC_PULSE_CLR_CNTR_PERIOD = 1,      /*!< Clear CBC pulse when counter equals period */
    EPWM_TZ_CBC_PULSE_CLR_CNTR_ZERO_PERIOD = 2  /*!< Clear CBC pulse when counter equals zero or period */
} EPWM_CycleByCycleTripZoneClearMode;

/*!
 * Values that can be passed to EPWM_forceTripZoneEvent() as the
 * tzForceEvent parameter.
 */
#define EPWM_TZ_FORCE_EVENT_CBC  0x2U           /*!< Force Cycle By Cycle trip event */
#define EPWM_TZ_FORCE_EVENT_OST  0x4U           /*!< Force a One-Shot Trip Event */
#define EPWM_TZ_FORCE_EVENT_DCAEVT1  0x8U       /*!< ForceDigital Compare Output A Event 1 */
#define EPWM_TZ_FORCE_EVENT_DCAEVT2  0x10U      /*!< ForceDigital Compare Output A Event 2 */
#define EPWM_TZ_FORCE_EVENT_DCBEVT1  0x20U      /*!< ForceDigital Compare Output B Event 1 */
#define EPWM_TZ_FORCE_EVENT_DCBEVT2  0x40U      /*!< ForceDigital Compare Output B Event 2 */

/*!
 * Values that can be passed to EPWM_setInterruptSource() as the
 * interruptSource parameter.
 */
#define EPWM_INT_TBCTR_DISABLED 0U              /*!< Time-base counter is disabled */
#define EPWM_INT_TBCTR_ZERO  1U                 /*!< Time-base counter equal to zero */
#define EPWM_INT_TBCTR_PERIOD  2U               /*!< Time-base counter equal to period */
#define EPWM_INT_TBCTR_ZERO_OR_PERIOD  3U       /*!< Time-base counter equal to zero or period */
#define EPWM_INT_TBCTR_U_CMPA  4U               /*!< time-base counter equal to CMPA when the timer is incrementing */
#define EPWM_INT_TBCTR_U_CMPC  8U               /*!< time-base counter equal to CMPC when the timer is incrementing */
#define EPWM_INT_TBCTR_D_CMPA  5U               /*!< time-base counter equal to CMPA when the timer is decrementing */
#define EPWM_INT_TBCTR_D_CMPC  10U              /*!< time-base counter equal to CMPC when the timer is decrementing */
#define EPWM_INT_TBCTR_U_CMPB  6U               /*!< time-base counter equal to CMPB when the timer is incrementing */
#define EPWM_INT_TBCTR_U_CMPD  12U              /*!< time-base counter equal to CMPD when the timer is incrementing */
#define EPWM_INT_TBCTR_D_CMPB  7U               /*!< time-base counter equal to CMPB when the timer is decrementing */
#define EPWM_INT_TBCTR_D_CMPD  14U              /*!< time-base counter equal to CMPD when the timer is decrementing */

/*!
 * Values that can be passed to EPWM_enableADCTrigger(),
 * EPWM_disableADCTrigger(),EPWM_setADCTriggerSource(),
 * EPWM_setADCTriggerEventPrescale(),EPWM_getADCTriggerFlagStatus(),
 * EPWM_clearADCTriggerFlag(),EPWM_enableADCTriggerEventCountInit(),
 * EPWM_disableADCTriggerEventCountInit(),EPWM_forceADCTriggerEventCountInit(),
 * EPWM_setADCTriggerEventCountInitValue(),EPWM_getADCTriggerEventCount(),
 * EPWM_forceADCTrigger() as the \e adcSOCType parameter
 */
typedef enum
{
    EPWM_SOC_A = 0,  /*!< SOC A */
    EPWM_SOC_B = 1   /*!< SOC B */
} EPWM_ADCStartOfConversionType;

/*!
 * Values that can be passed to EPWM_setADCTriggerSource() as the
 * \e socSource parameter.
 */
typedef enum
{
    EPWM_SOC_DCxEVT1 = 0,                       /*!< Event is based on DCxEVT1 */
    EPWM_SOC_TBCTR_ZERO = 1,                    /*!< Time-base counter equal to zero */
    EPWM_SOC_TBCTR_PERIOD = 2,                  /*!< Time-base counter equal to period */
    EPWM_SOC_TBCTR_ZERO_OR_PERIOD = 3,          /*!< Time-base counter equal to zero or period */
    EPWM_SOC_TBCTR_U_CMPA = 4,                  /*!< Time-base counter equal to CMPA when the timer is incrementing */
    EPWM_SOC_TBCTR_U_CMPC = 8,                  /*!< Time-base counter equal to CMPC when the timer is incrementing */
    EPWM_SOC_TBCTR_D_CMPA = 5,                  /*!< Time-base counter equal to CMPA when the timer is decrementing */
    EPWM_SOC_TBCTR_D_CMPC = 10,                 /*!< Time-base counter equal to CMPC when the timer is decrementing */
    EPWM_SOC_TBCTR_U_CMPB = 6,                  /*!< ime-base counter equal to CMPB when the timer is incrementing */
    EPWM_SOC_TBCTR_U_CMPD = 12,                 /*!< Time-base counter equal to CMPD when the timer is incrementing */
    EPWM_SOC_TBCTR_D_CMPB = 7,                  /*!< Time-base counter equal to CMPB when the timer is decrementing */
    EPWM_SOC_TBCTR_D_CMPD = 14                  /*!< Time-base counter equal to CMPD when the timer is decrementing */
} EPWM_ADCStartOfConversionSource;

/*!
 * Values that can be passed to EPWM_selectDigitalCompareTripInput(),
 * EPWM_enableDigitalCompareTripCombinationInput(),
 * EPWM_disableDigitalCompareTripCombinationInput() as the \e dcType
 * parameter.
 */
typedef enum
{
    EPWM_DC_TYPE_DCAH = 0,  /*!< Digital Compare A High */
    EPWM_DC_TYPE_DCAL = 1,  /*!< Digital Compare A Low */
    EPWM_DC_TYPE_DCBH = 2,  /*!< Digital Compare B High */
    EPWM_DC_TYPE_DCBL = 3   /*!< Digital Compare B Low */
} EPWM_DigitalCompareType;

/*!
 * Values that can be passed to EPWM_selectDigitalCompareTripInput() as the
 * \e tripSource parameter.
 */
typedef enum
{
    EPWM_DC_TRIP_TRIPIN1 = 0,   /*!< Trip 1 */
    EPWM_DC_TRIP_TRIPIN2 = 1,   /*!< Trip 2 */
    EPWM_DC_TRIP_TRIPIN3 = 2,   /*!< Trip 3 */
    EPWM_DC_TRIP_TRIPIN4 = 3,   /*!< Trip 4 */
    EPWM_DC_TRIP_TRIPIN5 = 4,   /*!< Trip 5 */
    EPWM_DC_TRIP_TRIPIN6 = 5,   /*!< Trip 6 */
    EPWM_DC_TRIP_TRIPIN7 = 6,   /*!< Trip 7 */
    EPWM_DC_TRIP_TRIPIN8 = 7,   /*!< Trip 8 */
    EPWM_DC_TRIP_TRIPIN9 = 8,   /*!< Trip 9 */
    EPWM_DC_TRIP_TRIPIN10 = 9,  /*!< Trip 10 */
    EPWM_DC_TRIP_TRIPIN11 = 10, /*!< Trip 11 */
    EPWM_DC_TRIP_TRIPIN12 = 11, /*!< Trip 12 */
    EPWM_DC_TRIP_TRIPIN14 = 13, /*!< Trip 14 */
    EPWM_DC_TRIP_TRIPIN15 = 14, /*!< Trip 15 */
    EPWM_DC_TRIP_COMBINATION = 15 /*!< All Trips (Trip1 - Trip 15) are selected */
} EPWM_DigitalCompareTripInput;

/*!
 * Values that can be passed to EPWM_enableDigitalCompareTripCombinationInput(),
 * EPWM_disableDigitalCompareTripCombinationInput() as the tripInput
 * parameter.
 */
#define EPWM_DC_COMBINATIONAL_TRIPIN1   0x1U        /*!< Combinational Trip 1 input */
#define EPWM_DC_COMBINATIONAL_TRIPIN2   0x2U        /*!< Combinational Trip 2 input */
#define EPWM_DC_COMBINATIONAL_TRIPIN3   0x4U        /*!< Combinational Trip 3 input */
#define EPWM_DC_COMBINATIONAL_TRIPIN4   0x8U        /*!< Combinational Trip 4 input */
#define EPWM_DC_COMBINATIONAL_TRIPIN5   0x10U       /*!< Combinational Trip 5 input */
#define EPWM_DC_COMBINATIONAL_TRIPIN6   0x20U       /*!< Combinational Trip 6 input */
#define EPWM_DC_COMBINATIONAL_TRIPIN7   0x40U       /*!< Combinational Trip 7 input */
#define EPWM_DC_COMBINATIONAL_TRIPIN8   0x80U       /*!< Combinational Trip 8 input */
#define EPWM_DC_COMBINATIONAL_TRIPIN9   0x100U      /*!< Combinational Trip 9 input */
#define EPWM_DC_COMBINATIONAL_TRIPIN10  0x200U      /*!< Combinational Trip 10 input */
#define EPWM_DC_COMBINATIONAL_TRIPIN11  0x400U      /*!< Combinational Trip 11 input */
#define EPWM_DC_COMBINATIONAL_TRIPIN12  0x800U      /*!< Combinational Trip 12 input */
#define EPWM_DC_COMBINATIONAL_TRIPIN14  0x2000U     /*!< Combinational Trip 14 input */
#define EPWM_DC_COMBINATIONAL_TRIPIN15  0x4000U     /*!< Combinational Trip 15 input */

/*!
 * Values that can be passed to EPWM_setDigitalCompareBlankingEvent() as the
 * the \e blankingPulse parameter.
 */
typedef enum
{
    EPWM_DC_WINDOW_START_TBCTR_PERIOD = 0,          /*!< Time base counter equals period */
    EPWM_DC_WINDOW_START_TBCTR_ZERO   = 1,          /*!< Time base counter equals zero */
    EPWM_DC_WINDOW_START_TBCTR_ZERO_PERIOD  = 2     /*!< Time base counter equals zero or period */
} EPWM_DigitalCompareBlankingPulse;

/*!
 * Values that can be passed to EPWM_setDigitalCompareFilterInput()
 * as the \e filterInput parameter.
 */
typedef enum
{
    EPWM_DC_WINDOW_SOURCE_DCAEVT1 = 0, /*!< DC filter signal source is DCAEVT1 */
    EPWM_DC_WINDOW_SOURCE_DCAEVT2 = 1, /*!< DC filter signal source is DCAEVT2 */
    EPWM_DC_WINDOW_SOURCE_DCBEVT1 = 2, /*!< DC filter signal source is DCBEVT1 */
    EPWM_DC_WINDOW_SOURCE_DCBEVT2 = 3  /*!< DC filter signal source is DCBEVT2 */
} EPWM_DigitalCompareFilterInput;

/*!
 * Values that can be assigned to EPWM_setDigitalCompareEventSource(),
 * EPWM_setDigitalCompareEventSyncMode(),EPWM_enableDigitalCompareSyncEvent()
 * EPWM_enableDigitalCompareADCTrigger(),EPWM_disableDigitalCompareSyncEvent()
 * EPWM_disableDigitalCompareADCTrigger() as the \e dcModule parameter.
 */
typedef enum
{
    EPWM_DC_MODULE_A = 0, /*!< Digital Compare Module A */
    EPWM_DC_MODULE_B = 2  /*!< Digital Compare Module B */
} EPWM_DigitalCompareModule;

/*!
 * Values that can be passed to EPWM_setDigitalCompareEventSource(),
 * EPWM_setDigitalCompareEventSyncMode as the \e dcEvent parameter.
 */
typedef enum
{
    EPWM_DC_EVENT_1 = 0, /*!< Digital Compare Event number 1 */
    EPWM_DC_EVENT_2 = 1  /*!< Digital Compare Event number 2 */
} EPWM_DigitalCompareEvent;

/*!
 * Values that can be passed to EPWM_setDigitalCompareEventSource() as the
 * \e dcEventSource parameter.
 */
typedef enum
{
    EPWM_DC_EVENT_SOURCE_ORIG_SIGNAL = 0,   /*!< Signal source is unfiltered (DCAEVT1/2) */
    EPWM_DC_EVENT_SOURCE_FILT_SIGNAL = 1    /*!< Signal source is filtered (DCEVTFILT) */
} EPWM_DigitalCompareEventSource;

/*!
 * Values that can be passed to EPWM_setDigitalCompareEventSyncMode() as the
 * \e syncMode parameter.
 */
typedef enum
{
    EPWM_DC_EVENT_INPUT_SYNCED = 0,         /*!< DC input signal is synced with TBCLK */
    EPWM_DC_EVENT_INPUT_NOT_SYNCED = 1      /*!< DC input signal is not synced with TBCLK */
} EPWM_DigitalCompareSyncMode;

/*!
 * Values that can be passed to EPWM_setDigitalCompareCBCLatchMode() as the
 * \e latchMode parameter.
 */
typedef enum
{
    EPWM_DC_CBC_LATCH_DISABLED = 0x0,       /*!< DC cycle-by-cycle(CBC) latch is disabled */
    EPWM_DC_CBC_LATCH_ENABLED  = 0x1        /*!< DC cycle-by-cycle(CBC) latch is enabled */
} EPWM_DigitalCompareCBCLatchMode;

/*!
 * Values that can be passed to EPWM_selectDigitalCompareCBCLatchClearEvent()
 * as the \e latchMode parameter.
 */
typedef enum
{
    EPWM_DC_CBC_LATCH_CLR_CNTR_ZERO           = 0x0,    /*!< Clear CBC latch when counter equals zero */
    EPWM_DC_CBC_LATCH_CLR_ON_CNTR_PERIOD      = 0x1,    /*!< Clear CBC latch when counter equals period */
    EPWM_DC_CBC_LATCH_CLR_ON_CNTR_ZERO_PERIOD = 0x2     /*!< Clear CBC latch when counter equals zero or period */
} EPWM_DigitalCompareCBCLatchClearEvent;

/*!
 * Values that can be passed to EPWM_setGlobalLoadTrigger() as the
 * \e loadTrigger parameter.
 */
typedef enum
{
    EPWM_GL_LOAD_PULSE_CNTR_ZERO = 0x0,                 /*!< Load when counter is equal to zero */
    EPWM_GL_LOAD_PULSE_CNTR_PERIOD = 0x1,               /*!< Load when counter is equal to period */
    EPWM_GL_LOAD_PULSE_CNTR_ZERO_PERIOD = 0x2,          /*!< Load when counter is equal to zero or period */
    EPWM_GL_LOAD_PULSE_SYNC = 0x3,                      /*!< Load on sync event */
    EPWM_GL_LOAD_PULSE_SYNC_OR_CNTR_ZERO = 0x4,         /*!< Load on sync event or when counter  is equal to zero */
    EPWM_GL_LOAD_PULSE_SYNC_OR_CNTR_PERIOD = 0x5,       /*!< Load on sync event or when counter  is equal to period */
    EPWM_GL_LOAD_PULSE_SYNC_CNTR_ZERO_PERIOD = 0x6,     /*!< Load on sync event or when counter is equal to period or zero */
    EPWM_GL_LOAD_PULSE_GLOBAL_FORCE = 0xF               /*!< Load on global force */
} EPWM_GlobalLoadTrigger;

/*!
 * Values that can be passed to EPWM_enableGlobalLoadRegisters(),
 * EPWM_disableGlobalLoadRegisters() as theloadRegister parameter.
 */
#define EPWM_GL_REGISTER_TBPRD_TBPRDHR   0x1U           /*!< Global load TBPRD:TBPRDHR */
#define EPWM_GL_REGISTER_CMPA_CMPAHR     0x2U           /*!< Global load CMPA:CMPAHR */
#define EPWM_GL_REGISTER_CMPB_CMPBHR     0x4U           /*!< Global load CMPB:CMPBHR */
#define EPWM_GL_REGISTER_CMPC            0x8U           /*!< Global load CMPC */
#define EPWM_GL_REGISTER_CMPD            0x10U          /*!< Global load CMPD */
#define EPWM_GL_REGISTER_DBRED_DBREDHR   0x20U          /*!< Global load DBRED:DBREDHR */
#define EPWM_GL_REGISTER_DBFED_DBFEDHR   0x40U          /*!< Global load DBFED:DBFEDHR */
#define EPWM_GL_REGISTER_DBCTL           0x80U          /*!< Global load DBCTL */
#define EPWM_GL_REGISTER_AQCTLA_AQCTLA2  0x100U         /*!< Global load AQCTLA/A2 */
#define EPWM_GL_REGISTER_AQCTLB_AQCTLB2  0x200U         /*!< Global load AQCTLB/B2 */
#define EPWM_GL_REGISTER_AQCSFRC         0x400U         /*!< Global load AQCSFRC */

/*!
 * Values that can be passed to EPWM_setValleyTriggerSource() as the \e
 * trigger parameter.
 */
typedef enum
{
    EPWM_VALLEY_TRIGGER_EVENT_SOFTWARE = 0U,            /*!< Valley capture trigged by software */
    EPWM_VALLEY_TRIGGER_EVENT_CNTR_ZERO = 1U,           /*!< Valley capture trigged by when counter is equal to zero */
    EPWM_VALLEY_TRIGGER_EVENT_CNTR_PERIOD = 2U,         /*!< Valley capture trigged by when counter is equal period */
    EPWM_VALLEY_TRIGGER_EVENT_CNTR_ZERO_PERIOD = 3U,    /*!< Valley capture trigged when counter is equal to zero or period */
    EPWM_VALLEY_TRIGGER_EVENT_DCAEVT1 = 4U,             /*!< Valley capture trigged by DCAEVT1 (Digital Compare A event 1) */
    EPWM_VALLEY_TRIGGER_EVENT_DCAEVT2 = 5U,             /*!< Valley capture trigged by DCAEVT2 (Digital Compare A event 2) */
    EPWM_VALLEY_TRIGGER_EVENT_DCBEVT1 = 6U,             /*!< Valley capture trigged by DCBEVT1 (Digital Compare B event 1) */
    EPWM_VALLEY_TRIGGER_EVENT_DCBEVT2 = 7U              /*!< Valley capture trigged by DCBEVT2 (Digital Compare B event 2) */
} EPWM_ValleyTriggerSource;

/*!
 * Values that can be passed to EPWM_getValleyCountEdgeStatus() as the \e edge
 * parameter.
 */
typedef enum
{
    EPWM_VALLEY_COUNT_START_EDGE = 0, /*!< Valley count start edge */
    EPWM_VALLEY_COUNT_STOP_EDGE  = 1  /*!< Valley count stop edge */
} EPWM_ValleyCounterEdge;

/*!
 * Values that can be passed to EPWM_setValleyDelayValue() as the \e delayMode
 * parameter.
 */
typedef enum
{
    EPWM_VALLEY_DELAY_MODE_SW_DELAY   = 0U,                     /*!< Delay value equals the offset value defines by software */
    EPWM_VALLEY_DELAY_MODE_VCNT_DELAY_SW_DELAY = 1U,            /*!< Delay value equals the sum of the Hardware counter value and the offset value defines by software*/
    EPWM_VALLEY_DELAY_MODE_VCNT_DELAY_SHIFT_1_SW_DELAY = 2U,    /*!< Delay value equals the the Hardware counter shifted by (1 + the offset value defines by software)*/
    EPWM_VALLEY_DELAY_MODE_VCNT_DELAY_SHIFT_2_SW_DELAY = 3U,    /*!< Delay value equals the the Hardware counter shifted by (2 + the offset value defines by software)*/
    EPWM_VALLEY_DELAY_MODE_VCNT_DELAY_SHIFT_4_SW_DELAY = 4U     /*!< Delay value equals the the Hardware counter shifted by (4 + the offset value defines by software)*/
} EPWM_ValleyDelayMode;

/*!
 * Values that can be passed to EPWM_setDigitalCompareEdgeFilterMode()
 * as the \e edgeMode parameter.
 */
typedef enum
{
    EPWM_DC_EDGEFILT_MODE_RISING  = 0, /*!< Digital Compare Edge filter low
                                        to high edge mode */
    EPWM_DC_EDGEFILT_MODE_FALLING = 1, /*!< Digital Compare Edge filter high
                                        to low edge mode */
    EPWM_DC_EDGEFILT_MODE_BOTH    = 2  /*!< Digital Compare Edge filter both
                                        edges mode */
} EPWM_DigitalCompareEdgeFilterMode;

/*!
 * Values that can be passed to EPWM_setDigitalCompareEdgeFilterEdgeCount()
 * as the \e edgeCount parameter.
 */
typedef enum
{
    EPWM_DC_EDGEFILT_EDGECNT_0  = 0, /*!< Digital Compare Edge filter edge
                                      count = 0 */
    EPWM_DC_EDGEFILT_EDGECNT_1  = 1, /*!< Digital Compare Edge filter edge
                                      count = 1 */
    EPWM_DC_EDGEFILT_EDGECNT_2  = 2, /*!< Digital Compare Edge filter edge
                                      count = 2 */
    EPWM_DC_EDGEFILT_EDGECNT_3  = 3, /*!< Digital Compare Edge filter edge
                                      count = 3 */
    EPWM_DC_EDGEFILT_EDGECNT_4  = 4, /*!< Digital Compare Edge filter edge
                                      count = 4 */
    EPWM_DC_EDGEFILT_EDGECNT_5  = 5, /*!< Digital Compare Edge filter edge
                                      count = 5 */
    EPWM_DC_EDGEFILT_EDGECNT_6  = 6, /*!< Digital Compare Edge filter edge
                                      count = 6 */
    EPWM_DC_EDGEFILT_EDGECNT_7  = 7  /*!< Digital Compare Edge filter edge
                                      count = 7 */
} EPWM_DigitalCompareEdgeFilterEdgeCount;

/*!
 * Values that can be passed to EPWM_lockRegisters() as the \e registerGroup
 * parameter.
 */
typedef enum
{
    EPWM_REGISTER_GROUP_GLOBAL_LOAD = 0x2,     /*!< Global load register group */
    EPWM_REGISTER_GROUP_TRIP_ZONE = 0x4,       /*!< Trip zone register group */
    EPWM_REGISTER_GROUP_TRIP_ZONE_CLEAR = 0x8, /*!< Trip zone clear group */
    EPWM_REGISTER_GROUP_DIGITAL_COMPARE = 0x10 /*!< Digital compare group */
} EPWM_LockRegisterGroup;

/*!
 * Values that can be passed to EPWM_configureSignal() as the
 * \e signalParams parameter.
 */
typedef struct
{
    float                  freqInHz;      /*!< Desired Signal Frequency(in Hz) */
    float                  dutyValA;      /*!< Desired ePWMxA Signal Duty */
    float                  dutyValB;      /*!< Desired ePWMxB Signal Duty */
    bool                   invertSignalB; /*!< Invert ePWMxB Signal if true */
    float                  sysClkInHz;    /*!< SYSCLK Frequency(in Hz) */
    sysctl_epwmclk_div_e   epwmClkDiv;  /*!< EPWM Clock Divider */
    EPWM_TimeBaseCountMode tbCtrMode;   /*!< Time Base Counter Mode */
    EPWM_ClockDivider      tbClkDiv;    /*!< Time Base Counter Clock Divider */
    EPWM_HSClockDivider    tbHSClkDiv;  /*!< Time Base Counter HS Clock Divider */
} EPWM_SignalParams;


/*!
 * Functions APIs shared with HRPWM module
 */

#define EPWM_setSyncPulseSource                 HRPWM_setSyncPulseSource

/*******************************************************************************
 * APIs
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \internal
 * Checks ePWM base address.
 *
 * \param base specifies the ePWM module base address.
 *
 * This function determines if an ePWM module base address is valid.
 *
 * \return Returns \b true if the base address is valid and \b false
 * otherwise.
 */
#ifdef DEBUG
static inline bool EPWM_isBaseValid(EPWM_REGS_Type *base)
{
    return ((base == EPWM1) || (base == EPWM2) || (base == EPWM3) || (base == EPWM4) || (base == EPWM5) ||
            (base == EPWM6) || (base == EPWM7) || (base == EPWM8) || (base == EPWM9) || (base == EPWM10) ||
            (base == EPWM11) || (base == EPWM12));
}
#endif

/*!
 * \brief Time Base Sub Module related APIs
 *          
 * \details Set the time base count
 * 
 * \param base is the base address of the EPWM module.
 * \param count is the time base count value.
 * nction sets the 16 bit counter value of the time base counter.
 *
 *  
 */
static inline void
EPWM_setTimeBaseCounter(EPWM_REGS_Type *base, uint16_t count)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Write to TBCTR register */
    base->TBCTR = count;
}

/*!
 * \brief Set count mode after phase shift sync
 *
 * \param base is the base address of the EPWM module.
 * \param mode is the count mode.
 *
 * This function sets the time base count to count up or down after a new
 * phase value set by the EPWM_setPhaseShift(). The count direction is
 * determined by the variable mode. Valid inputs for mode are:
 *  - EPWM_COUNT_MODE_UP_AFTER_SYNC      - Count up after sync
 *  - EPWM_COUNT_MODE_DOWN_AFTER_SYNC    - Count down after sync
 *
 */
static inline void
EPWM_setCountModeAfterSync(EPWM_REGS_Type *base, EPWM_SyncCountMode mode)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    if(mode == EPWM_COUNT_MODE_UP_AFTER_SYNC)
    {
        /* Set PHSDIR bit */
        base->TBCTL |= EPWM_REGS_TBCTL_PHSDIR_Set(1);
    }
    else
    {
        /* Clear PHSDIR bit */
        base->TBCTL &= ~EPWM_REGS_TBCTL_PHSDIR_Set(1);
    }
}

/*!
 * Set the time base clock and the high speed time base clock count pre-scaler
 *
 * \param base is the base address of the EPWM module.
 * \param prescaler is the time base count pre scale value.
 * \param highSpeedPrescaler is the high speed time base count pre scale
 *        value.
 *
 * This function sets the pre scaler(divider)value for the time base clock
 * counter and the high speed time base clock counter.
 * Valid values for pre-scaler and highSpeedPrescaler are EPWM_CLOCK_DIVIDER_X,
 * where X is 1,2,4,8,16, 32,64 or 128.
 * The actual numerical values for these macros represent values 0,1...7.
 * The equation for the output clock is:
 *   TBCLK = EPWMCLK/(highSpeedPrescaler * pre-scaler)
 *
 * \b Note: EPWMCLK is a scaled version of SYSCLK. At reset EPWMCLK is half
 *          SYSCLK.
 *
 *  
 */
static inline void
EPWM_setClockPrescaler(EPWM_REGS_Type *base, EPWM_ClockDivider prescaler,
                       EPWM_HSClockDivider highSpeedPrescaler)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Write to CLKDIV and HSPCLKDIV bit */
    base->TBCTL = (base->TBCTL & ~(EPWM_REGS_TBCTL_CLKDIV_Msk | EPWM_REGS_TBCTL_HSPCLKDIV_Msk)) |
                    EPWM_REGS_TBCTL_CLKDIV_Set(prescaler) |
                    EPWM_REGS_TBCTL_HSPCLKDIV_Set(highSpeedPrescaler);
}

/*!
 * Force a software sync pulse
 *
 * \param base is the base address of the EPWM module.
 *
 * This function causes a single software initiated sync pulse. Make sure the
 * appropriate mode is selected using EPWM_setupSyncOutputMode() before using
 * this function.
 *
 *  
 */
static inline void
EPWM_forceSyncPulse(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Set SWFSYNC bit */
    base->TBCTL |= EPWM_REGS_TBCTL_SWFSYNC_Set(1);
}

/*!
 * Set up the source for sync-in pulse.
 *
 * \param base is the base address of the EPWM module.
 * \param source is the sync-in pulse source.
 *
 * This function set the sync out pulse mode.
 * Valid values for mode are:
 *  - EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM1-16 - sync-in pulse source can be
 *                                              any of the EPWM1-16 sync-out
 *                                              signal
 *  - EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP1-7 - sync-in pulse source can be
 *                                             selected as any of the ECAP1-16
 *                                             sync-out signal
 *  - EPWM_SYNC_IN_PULSE_SRC_INPUTXBAR_OUT5-6 - sync-in pulse source can be
 *                                              selected as any of the Input
 *                                              xbar out5-6 signal
 *  - EPWM_SYNC_IN_PULSE_SRC_ETHERCAT_SYNC0-1 - sync-in pulse source can be
 *                                              selected as any of the Ethercat
 *                                              sync0-1 signal
 *  - EPWM_SYNC_IN_PULSE_SRC_DISABLE - sync-in pulse is disabled for the
 *                                     EPWM module
 *
 *  
 */
static inline void
EPWM_setSyncInPulseSource(EPWM_REGS_Type *base, EPWM_SyncInPulseSource source)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Set EPWM Sync-In Source Mode. */
    base->EPWMSYNCINSEL = (base->EPWMSYNCINSEL & ~EPWM_REGS_EPWMSYNCINSEL_SEL_Msk) |
                            EPWM_REGS_EPWMSYNCINSEL_SEL_Set(source);
}

/*!
 * Enables sync-out pulse source.
 *
 * \param base is the base address of the EPWM module.
 * \param source is the sync-out pulse source.
 *
 * This function enables the sync-out pulse source.
 * Below valid values for param \b source can be OR'd together to enable
 * multiple sync-out sources:
 * - EPWM_SYNC_OUT_PULSE_ON_SOFTWARE - sync-out pulse is generated by
 *                                     software when EPWM_forceSyncPulse()
 *                                     function is called or by EPWMxSYNCI
 *                                     signal.
 * - EPWM_SYNC_OUT_PULSE_ON_CNTR_ZERO - sync-out pulse is generated when
 *                                      time base counter equals zero.
 * - EPWM_SYNC_OUT_PULSE_ON_CNTR_COMPARE_B - sync-out pulse is generated when
 *                                           time base counter equals compare
 *                                           B value.
 * - EPWM_SYNC_OUT_PULSE_ON_CNTR_COMPARE_C - sync-out pulse is generated when
 *                                           time base counter equals compare
 *                                           C value.
 * - EPWM_SYNC_OUT_PULSE_ON_CNTR_COMPARE_D - sync-out pulse is generated when
 *                                           time base counter equals compare
 *                                           D value.
 * - EPWM_SYNC_OUT_PULSE_ON_DCA_EVT1_SYNC - sync-out pulse is generated by DCA
 *                                          event1 sync signal
 * - EPWM_SYNC_OUT_PULSE_ON_DCB_EVT1_SYNC - sync-out pulse is generated by DCB
 *                                          event1 sync signal
 * - EPWM_SYNC_OUT_PULSE_ON_ALL  - sync-out pulse is generated by all
 *                                 the above sources
 *
 *  
 */
static inline void
EPWM_enableSyncOutPulseSource(EPWM_REGS_Type *base, uint16_t source)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));
    assert(source <= EPWM_SYNC_OUT_SOURCE_M);

    /* Enable selected EPWM Sync-Out Sources. */
    base->EPWMSYNCOUTEN |= (uint16_t)source;
}

/*!
 * Disables sync-out pulse source.
 *
 * \param base is the base address of the EPWM module.
 * \param source is the sync-out pulse source.
 *
 * This function disables the sync-out pulse source.
 * Below valid values for param \b source can be OR'd together to disable
 * multiple sync-out sources:
 *  - EPWM_SYNC_OUT_PULSE_ON_SOFTWARE - disables software as sync-out source
 *
 *  - EPWM_SYNC_OUT_PULSE_ON_CNTR_ZERO - disables counter equal to zero event
 *                                       as sync-out source
 *  - EPWM_SYNC_OUT_PULSE_ON_CNTR_COMPARE_B - disables counter equal to cmpb
 *                                            event as sync-out source
 *  - EPWM_SYNC_OUT_PULSE_ON_CNTR_COMPARE_C - disables counter equal to cmpc
 *                                            event as sync-out source
 *  - EPWM_SYNC_OUT_PULSE_ON_CNTR_COMPARE_D - disables counter equal to cmpd
 *                                            event as sync-out source
 *  - EPWM_SYNC_OUT_PULSE_ON_DCA_EVT1_SYNC - disables DCA event1 sync signal as
 *                                           sync-out source
 *  - EPWM_SYNC_OUT_PULSE_ON_DCB_EVT1_SYNC - disables DCB event1 sync signal as
 *                                           sync-out source
 *  - EPWM_SYNC_OUT_PULSE_ON_ALL - disables all the above sync-out sources
 *
 *  
 */
static inline void
EPWM_disableSyncOutPulseSource(EPWM_REGS_Type *base, uint16_t source)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));
    assert(source <= EPWM_SYNC_OUT_SOURCE_M);

    /* Disable EPWM Sync-Out Sources. */
    base->EPWMSYNCOUTEN &= ~((uint16_t)source);
}

/*!
 * Set up the one-shot sync-out trigger source.
 *
 * \param base is the base address of the EPWM module.
 * \param trigger is the one-shot sync-out signal trigger source.
 *
 * This function sets the one-shot sync-out trigger source.
 * Valid values for param \b trigger are:
 *  - EPWM_OSHT_SYNC_OUT_TRIG_SYNC - Trigger for one-shot sync-out signal is
 *                                    one-shot sync event.
 *  - EPWM_OSHT_SYNC_OUT_TRIG_RELOAD - Trigger for one-shot sync-out signal is
 *                                     one-shot reload event.
 *
 *  
 */
static inline void
EPWM_setOneShotSyncOutTrigger(EPWM_REGS_Type *base,
                              EPWM_OneShotSyncOutTrigger trigger)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Set source for One-Shot Sync-Out Pulse. */
    base->TBCTL3 = (base->TBCTL3 & ~EPWM_REGS_TBCTL3_OSSFRCEN_Msk) |
                    EPWM_REGS_TBCTL3_OSSFRCEN_Set(trigger);
}

/*!
 * Set PWM period load mode.
 *
 * \param base is the base address of the EPWM module.
 * \param loadMode is the PWM period load mode.
 *
 * This function sets the load mode for the PWM period. If loadMode is set to
 * EPWM_PERIOD_SHADOW_LOAD, a write or read to the TBPRD (PWM Period count
 * register) accesses the shadow register. If loadMode is set to
 * EPWM_PERIOD_DIRECT_LOAD, a write or read to the TBPRD register accesses the
 * register directly.
 *
 *  
 */
static inline void
EPWM_setPeriodLoadMode(EPWM_REGS_Type *base, EPWM_PeriodLoadMode loadMode)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    if(loadMode == EPWM_PERIOD_SHADOW_LOAD)
    {
        /* Clear PRDLD */
        base->TBCTL &= ~EPWM_REGS_TBCTL_PRDLD_Set(1);
    }
    else
    {
        /* Set PRDLD */
        base->TBCTL |= EPWM_REGS_TBCTL_PRDLD_Set(1);
    }
}

/*!
 * Enable phase shift load
 *
 * \param base is the base address of the EPWM module.
 *
 * This function enables loading of phase shift when the appropriate sync
 * event occurs.
 *
 *  
 */
static inline void
EPWM_enablePhaseShiftLoad(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Set PHSEN bit */
    base->TBCTL |= EPWM_REGS_TBCTL_PHSEN_Set(1);
}

/*!
 * Disable phase shift load
 *
 * \param base is the base address of the EPWM module.
 *
 * This function disables loading of phase shift.
 *
 *  
 */
static inline void
EPWM_disablePhaseShiftLoad(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Clear PHSEN bit */
    base->TBCTL &= ~EPWM_REGS_TBCTL_PHSEN_Set(0);
}

/*!
 * Set time base counter mode
 *
 * \param base is the base address of the EPWM module.
 * \param counterMode is the time base counter mode.
 *
 * This function sets up the time base counter mode.
 * Valid values for counterMode are:
 *  - EPWM_COUNTER_MODE_UP          - Up - count mode.
 *  - EPWM_COUNTER_MODE_DOWN        - Down - count mode.
 *  - EPWM_COUNTER_MODE_UP_DOWN     - Up - down - count mode.
 *  - EPWM_COUNTER_MODE_STOP_FREEZE - Stop - Freeze counter.
 *
 *  
 */
static inline void
EPWM_setTimeBaseCounterMode(EPWM_REGS_Type *base, EPWM_TimeBaseCountMode counterMode)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Write to CTRMODE bit */
    base->TBCTL = (base->TBCTL & ~EPWM_REGS_TBCTL_CTRMODE_Msk) |
                    EPWM_REGS_TBCTL_CTRMODE_Set(counterMode);
   // MSG("TBCTL: 0x%08x = 0x%08x\r\n", base + EPWM_O_TBCTL, HWREGH(base + EPWM_O_TBCTL));
}

/*!
 * Set shadow to active period load on sync mode
 *
 * \param base is the base address of the EPWM module.
 * \param shadowLoadMode is the shadow to active load mode.
 *
 * This function sets up the shadow to active Period register load mode with
 * respect to a sync event. Valid values for shadowLoadMode are:
 *  - EPWM_SHADOW_LOAD_MODE_COUNTER_ZERO - shadow to active load occurs when
 *                                         time base counter reaches 0.
 *  - EPWM_SHADOW_LOAD_MODE_COUNTER_SYNC - shadow to active load occurs when
 *                                         time base counter reaches 0 and a
 *                                         SYNC occurs.
 *  - EPWM_SHADOW_LOAD_MODE_SYNC         - shadow to active load occurs only
 *                                         when a SYNC occurs.
 *
 *  
 */
static inline void
EPWM_selectPeriodLoadEvent(EPWM_REGS_Type *base,
                           EPWM_PeriodShadowLoadMode shadowLoadMode)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Write to PRDLDSYNC bit */
    base->TBCTL2 = (base->TBCTL2 & ~EPWM_REGS_TBCTL2_PRDLDSYNC_Msk) |
                    EPWM_REGS_TBCTL2_PRDLDSYNC_Set(shadowLoadMode);
}
/*!
 * Enable one shot sync mode
 *
 * \param base is the base address of the EPWM module.
 *
 * This function enables one shot sync mode.
 *
 *  
 */
static inline void
EPWM_enableOneShotSync(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Set OSHTSYNCMODE bit */
    base->TBCTL2 |= EPWM_REGS_TBCTL2_OSHTSYNCMODE_Set(1);
}

/*!
 * Disable one shot sync mode
 *
 * \param base is the base address of the EPWM module.
 *
 * This function disables one shot sync mode.
 *
 *  
 */
static inline void
EPWM_disableOneShotSync(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Clear OSHTSYNCMODE bit */
    base->TBCTL2 &= ~EPWM_REGS_TBCTL2_OSHTSYNCMODE_Set(1);
}

/*!
 * Start one shot sync mode
 *
 * \param base is the base address of the EPWM module.
 *
 * This function propagates a one shot sync pulse.
 *
 */
static inline void
EPWM_startOneShotSync(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Set OSHTSYNC bit */
    base->TBCTL2 |= EPWM_REGS_TBCTL2_OSHTSYNC_Set(1);
}

/*!
 * Returns time base counter value.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function returns the current value of the time base counter.
 *
 * \return returns time base counter value
 */
static inline uint16_t
EPWM_getTimeBaseCounterValue(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Returns TBCTR value */
    return EPWM_REGS_TBCTR_TBCTR_Get(base->TBCTR);
}

/*!
 * Return time base counter maximum status.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function returns the status of the time base max counter.
 *
 * \return Returns true if the counter has reached 0xFFFF.
 *         Returns false if the counter hasn't reached 0xFFFF.
 */
static inline bool
EPWM_getTimeBaseCounterOverflowStatus(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Return true if CTRMAX bit is set, false otherwise */
    return EPWM_REGS_TBSTS_CTRMAX_Get(base->TBSTS);                
}

/*!
 * Clear max time base counter event.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function clears the max time base counter latch event. The latch event
 * occurs when the time base counter reaches its maximum value of 0xFFFF.
 *  
 */
static inline void
EPWM_clearTimeBaseCounterOverflowEvent(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Set CTRMAX bit */
    base->TBSTS |= EPWM_REGS_TBSTS_CTRMAX_Set(1);
}

/*!
 * Return external sync signal status.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function returns the external sync signal status.
 *
 * \return Returns true if if an external sync signal event
 *         Returns false if there is no event.
 */
static inline bool
EPWM_getSyncStatus(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Return true if SYNCI bit is set, false otherwise */
    return EPWM_REGS_TBSTS_SYNCI_Get(base->TBSTS);
}

/*!
 * Clear external sync signal event.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function clears the external sync signal latch event.
 *  
 */
static inline void
EPWM_clearSyncEvent(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Set SYNCI bit */
    base->TBSTS |= EPWM_REGS_TBSTS_SYNCI_Set(1);
}

/*!
 * Return time base counter direction.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function returns the direction of the time base counter.
 *
 * \return returns EPWM_TIME_BASE_STATUS_COUNT_UP if the counter is counting
 *                 up or EPWM_TIME_BASE_STATUS_COUNT_DOWN if the counter is
 *                 counting down.
 */
static inline uint16_t
EPWM_getTimeBaseCounterDirection(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Return CTRDIR bit */
    return EPWM_REGS_TBSTS_CTRDIR_Get(base->TBSTS);
}

/*!
 * Sets the phase shift offset counter value.
 *
 * \param base is the base address of the EPWM module.
 * \param phaseCount is the phase shift count value.
 *
 * This function sets the 16 bit time-base counter phase of the ePWM relative
 * to the time-base that is supplying the synchronization input signal. Call
 * the EPWM_enablePhaseShiftLoad() function to enable loading of the
 * phaseCount phase shift value when a sync event occurs.
 *
 */
static inline void
EPWM_setPhaseShift(EPWM_REGS_Type *base, uint16_t phaseCount)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Write to TBPHS bit */
    base->TBPHS = EPWM_REGS_TBPHS_TBPHS_Set(phaseCount);
}

/*!
 * Sets the PWM period count.
 *
 * \param base is the base address of the EPWM module.
 * \param periodCount is period count value.
 *
 * This function sets the period of the PWM count. The value of periodCount is
 * the value written to the register. User should map the desired period or
 * frequency of the waveform into the correct periodCount.
 * Invoke the function EPWM_selectPeriodLoadEvent() with the appropriate
 * parameter to set the load mode of the Period count. periodCount has a
 * maximum valid value of 0xFFFF
 *
 */
static inline void
EPWM_setTimeBasePeriod(EPWM_REGS_Type *base, uint16_t periodCount)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Write to TBPRD bit */
    base->TBPRD = EPWM_REGS_TBPRD_TBPRD_Set(periodCount);
   // MSG("TBPR: 0x%08x = 0x%08x\r\n", base + EPWM_O_TBPRD, periodCount);
}

/*!
 * Gets the PWM period count.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function gets the period of the PWM count.
 *
 * \return The period count value.
 */
static inline uint16_t
EPWM_getTimeBasePeriod(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Read from TBPRD bit */
    return EPWM_REGS_TBPRD_TBPRD_Get(base->TBPRD);
}

/*!
 * Sets the EPWM links.
 *
 * \param base is the base address of the EPWM module.
 * \param epwmLink is the ePWM instance to link with.
 * \param linkComp is the ePWM component to link.
 *
 * This function links the component defined in linkComp in the current ePWM
 * instance with the linkComp component of the ePWM instance defined by
 * epwmLink. A change (a write) in the value of linkComp component of epwmLink
 * instance, causes a change in the current ePWM linkComp component.
 * For example if the current ePWM is ePWM3 and the values of epwmLink and
 * linkComp are EPWM_LINK_WITH_EPWM_1 and EPWM_LINK_COMP_C respectively,
 * then a write to COMPC register in ePWM1, will result in a simultaneous
 * write to COMPC register in ePWM3.
 * Valid values for epwmLink are:
 *   - EPWM_LINK_WITH_EPWM_1  - link current ePWM with ePWM1
 *   - EPWM_LINK_WITH_EPWM_2  - link current ePWM with ePWM2
 *   - EPWM_LINK_WITH_EPWM_3  - link current ePWM with ePWM3
 *   - EPWM_LINK_WITH_EPWM_4  - link current ePWM with ePWM4
 *   - EPWM_LINK_WITH_EPWM_5  - link current ePWM with ePWM5
 *   - EPWM_LINK_WITH_EPWM_6  - link current ePWM with ePWM6
 *   - EPWM_LINK_WITH_EPWM_7  - link current ePWM with ePWM7
 *   - EPWM_LINK_WITH_EPWM_8  - link current ePWM with ePWM8
 *   - EPWM_LINK_WITH_EPWM_9  - link current ePWM with ePWM9
 *   - EPWM_LINK_WITH_EPWM_10  - link current ePWM with ePWM10
 *   - EPWM_LINK_WITH_EPWM_11  - link current ePWM with ePWM11
 *   - EPWM_LINK_WITH_EPWM_12  - link current ePWM with ePWM12
 *   - EPWM_LINK_WITH_EPWM_13  - link current ePWM with ePWM13
 *   - EPWM_LINK_WITH_EPWM_14  - link current ePWM with ePWM14
 *   - EPWM_LINK_WITH_EPWM_15  - link current ePWM with ePWM15
 *   - EPWM_LINK_WITH_EPWM_16  - link current ePWM with ePWM16
 *
 * Valid values for linkComp are:
 *   - EPWM_LINK_TBPRD   - link TBPRD:TBPRDHR registers
 *   - EPWM_LINK_COMP_A   - link COMPA registers
 *   - EPWM_LINK_COMP_B   - link COMPB registers
 *   - EPWM_LINK_COMP_C   - link COMPC registers
 *   - EPWM_LINK_COMP_D   - link COMPD registers
 *   - EPWM_LINK_GLDCTL2  - link GLDCTL2 registers
 *
 */
static inline void
EPWM_setupEPWMLinks(EPWM_REGS_Type *base, EPWM_CurrentLink epwmLink,
                    EPWM_LinkComponent linkComp)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Configure EPWM links */
    base->EPWMXLINK = (base->EPWMXLINK & ~((uint32_t)0xFU << linkComp)) |
                        ((uint32_t)epwmLink << linkComp);
}

/*!
 * Sets up the Counter Compare shadow load mode
 *
 * \param base is the base address of the EPWM module.
 * \param compModule is the counter compare module.
 * \param loadMode is the shadow to active load mode.
 *
 * This function enables and sets up the counter compare shadow load mode.
 * Valid values for the variables are:
 *  - compModule
 *      - EPWM_COUNTER_COMPARE_A - counter compare A.
 *      - EPWM_COUNTER_COMPARE_B - counter compare B.
 *      - EPWM_COUNTER_COMPARE_C - counter compare C.
 *      - EPWM_COUNTER_COMPARE_D - counter compare D.
 *  - loadMode
 *      - EPWM_COMP_LOAD_ON_CNTR_ZERO - load when counter equals zero
 *      - EPWM_COMP_LOAD_ON_CNTR_PERIOD - load when counter equals period
 *      - EPWM_COMP_LOAD_ON_CNTR_ZERO_PERIOD - load when counter equals
 *                                             zero or period
 *      - EPWM_COMP_LOAD_FREEZE  - Freeze shadow to active load
 *      - EPWM_COMP_LOAD_ON_SYNC_CNTR_ZERO - load when counter equals zero
 *      - EPWM_COMP_LOAD_ON_SYNC_CNTR_PERIOD -load when counter equals period
 *      - EPWM_COMP_LOAD_ON_SYNC_CNTR_ZERO_PERIOD - load when counter equals
 *                                                  zero or period
 *      - EPWM_COMP_LOAD_ON_SYNC_ONLY - load on sync only
 *
 */
static inline void
EPWM_setCounterCompareShadowLoadMode(EPWM_REGS_Type *base,
                                     EPWM_CounterCompareModule compModule,
                                     EPWM_CounterCompareLoadMode loadMode)
{

    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Set the appropriate sync and load mode bits and also enable shadow load mode. 
       Shadow to active load can also be frozen.*/
    switch (compModule)
    {
        case EPWM_COUNTER_COMPARE_A:
            base->CMPCTL = (base->CMPCTL & ~(EPWM_REGS_CMPCTL_LOADAMODE_Msk | 
                                EPWM_REGS_CMPCTL_SHDWAMODE_Msk | 
                                EPWM_REGS_CMPCTL_LOADASYNC_Msk)) | 
                                EPWM_REGS_CMPCTL_LOADASYNC_Set(loadMode >> 2U) |
                                EPWM_REGS_CMPCTL_LOADAMODE_Set(loadMode & 0x3U);
            break;
        case EPWM_COUNTER_COMPARE_B:
            base->CMPCTL = (base->CMPCTL & ~(EPWM_REGS_CMPCTL_LOADBMODE_Msk | 
                                EPWM_REGS_CMPCTL_SHDWBMODE_Msk | 
                                EPWM_REGS_CMPCTL_LOADBSYNC_Msk)) | 
                                EPWM_REGS_CMPCTL_LOADBSYNC_Set(loadMode >> 2U) |
                                EPWM_REGS_CMPCTL_LOADBMODE_Set(loadMode & 0x3U);
            break;
        case EPWM_COUNTER_COMPARE_C:
            base->CMPCTL2 = (base->CMPCTL2 & ~(EPWM_REGS_CMPCTL2_LOADCMODE_Msk | 
                                EPWM_REGS_CMPCTL2_SHDWCMODE_Msk | 
                                EPWM_REGS_CMPCTL2_LOADCSYNC_Msk)) | 
                                EPWM_REGS_CMPCTL2_LOADCSYNC_Set(loadMode >> 2U) |
                                EPWM_REGS_CMPCTL2_LOADCMODE_Set(loadMode & 0x3U);
            break;
        case EPWM_COUNTER_COMPARE_D:
            base->CMPCTL2 = (base->CMPCTL2 & ~(EPWM_REGS_CMPCTL2_LOADDMODE_Msk | 
                                EPWM_REGS_CMPCTL2_SHDWDMODE_Msk | 
                                EPWM_REGS_CMPCTL2_LOADDSYNC_Msk)) | 
                                EPWM_REGS_CMPCTL2_LOADDSYNC_Set(loadMode >> 2U) |
                                EPWM_REGS_CMPCTL2_LOADDMODE_Set(loadMode & 0x3U);
            break;
        default:
            break;
    }
}

/*!
 * Disable Counter Compare shadow load mode
 *
 * \param base is the base address of the EPWM module.
 * \param compModule is the counter compare module.
 *
 * This function disables counter compare shadow load mode.
 * Valid values for the variables are:
 *  - compModule
 *      - EPWM_COUNTER_COMPARE_A - counter compare A.
 *      - EPWM_COUNTER_COMPARE_B - counter compare B.
 *      - EPWM_COUNTER_COMPARE_C - counter compare C.
 *      - EPWM_COUNTER_COMPARE_D - counter compare D.
 *
 */
static inline void
EPWM_disableCounterCompareShadowLoadMode(EPWM_REGS_Type *base,
                                         EPWM_CounterCompareModule compModule)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Disable shadow load mode. */
    switch (compModule)
    {
        case EPWM_COUNTER_COMPARE_A:
            base->CMPCTL |= EPWM_REGS_CMPCTL_SHDWAMODE_Set(1);
            break;
        case EPWM_COUNTER_COMPARE_B:
            base->CMPCTL |= EPWM_REGS_CMPCTL_SHDWBMODE_Set(1);
            break;
        case EPWM_COUNTER_COMPARE_C:
            base->CMPCTL2 |= EPWM_REGS_CMPCTL2_SHDWCMODE_Set(1);
            break;
        case EPWM_COUNTER_COMPARE_D:
            base->CMPCTL2 |= EPWM_REGS_CMPCTL2_SHDWDMODE_Set(1);
            break;
        default:
            break;
    }
}

/*!
 * Set counter compare values.
 *
 * \param base is the base address of the EPWM module.
 * \param compModule is the Counter Compare value module.
 * \param compCount is the counter compare count value.
 *
 * This function sets the counter compare value for counter compare registers.
 * The maximum value for compCount is 0xFFFF.
 * Valid values for compModule are:
 *   - EPWM_COUNTER_COMPARE_A - counter compare A.
 *   - EPWM_COUNTER_COMPARE_B - counter compare B.
 *   - EPWM_COUNTER_COMPARE_C - counter compare C.
 *   - EPWM_COUNTER_COMPARE_D - counter compare D.
 *
 */
static inline void
EPWM_setCounterCompareValue(EPWM_REGS_Type *base, EPWM_CounterCompareModule compModule,
                            uint16_t compCount)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    switch(compModule)
    {
        case EPWM_COUNTER_COMPARE_A:
            base->CMPA = EPWM_REGS_CMPA_CMPA_Set(compCount);
            break;
        case EPWM_COUNTER_COMPARE_B:
            base->CMPB = EPWM_REGS_CMPB_CMPB_Set(compCount);
            break;
        case EPWM_COUNTER_COMPARE_C:
            base->CMPC = EPWM_REGS_CMPC_CMPC_Set(compCount);
            break;
        case EPWM_COUNTER_COMPARE_D:
            base->CMPD = EPWM_REGS_CMPD_CMPD_Set(compCount);
            break;
    }

    return;
}

/*!
 * Get counter compare values.
 *
 * \param base is the base address of the EPWM module.
 * \param compModule is the Counter Compare value module.
 *
 * This function gets the counter compare value for counter compare registers.
 * Valid values for compModule are:
 *   - EPWM_COUNTER_COMPARE_A - counter compare A.
 *   - EPWM_COUNTER_COMPARE_B - counter compare B.
 *   - EPWM_COUNTER_COMPARE_C - counter compare C.
 *   - EPWM_COUNTER_COMPARE_D - counter compare D.
 *
 * \return The counter compare count value.
 */
static inline uint16_t
EPWM_getCounterCompareValue(EPWM_REGS_Type *base, EPWM_CounterCompareModule compModule)
{
    uint32_t compCount;
    
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Read from the counter compare registers. */
    switch(compModule)
    {
        /* Read COMPA or COMPB bits */
        case EPWM_COUNTER_COMPARE_A:
            compCount = EPWM_REGS_CMPA_CMPA_Get(base->CMPA);
            break;
        case EPWM_COUNTER_COMPARE_B:
            compCount = EPWM_REGS_CMPB_CMPB_Get(base->CMPB);        
            break;
        /* Read COMPC or COMPD bits */
        case EPWM_COUNTER_COMPARE_C:
            compCount = EPWM_REGS_CMPC_CMPC_Get(base->CMPC);        
            break;
        case EPWM_COUNTER_COMPARE_D:
            compCount = EPWM_REGS_CMPD_CMPD_Get(base->CMPD);       
            break;
    }

    return(compCount);
}

/*!
 * Return the counter compare shadow register full status.
 *
 * \param base is the base address of the EPWM module.
 * \param compModule is the Counter Compare value module.
 *
 * This function returns the counter Compare shadow register full status flag.
 * Valid values for compModule are:
 *   - EPWM_COUNTER_COMPARE_A - counter compare A.
 *   - EPWM_COUNTER_COMPARE_B - counter compare B.
 *
 * \return Returns true if the shadow register is full.
 *         Returns false if the shadow register is not full.
 */
static inline bool
EPWM_getCounterCompareShadowStatus(EPWM_REGS_Type *base,
                                   EPWM_CounterCompareModule compModule)
{
    bool isFullFlag;
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Check the validity of input. COMPA and COMPB are valid input arguments. */
    assert((compModule == EPWM_COUNTER_COMPARE_A) || (compModule == EPWM_COUNTER_COMPARE_B));

    if (compModule == EPWM_COUNTER_COMPARE_A)
    {
        /* Read the value of SHDWAFULL or SHDWBFULL bit */
        isFullFlag = EPWM_REGS_CMPCTL_SHDWAFULL_Get(base->CMPCTL);
    }
    else
    {
        isFullFlag = EPWM_REGS_CMPCTL_SHDWBFULL_Get(base->CMPCTL);
    }

    return isFullFlag;
}

/*!
 * Sets the Action Qualifier shadow load mode
 *
 * \param base is the base address of the EPWM module.
 * \param aqModule is the Action Qualifier module value.
 * \param loadMode is the shadow to active load mode.
 *
 * This function enables and sets the Action Qualifier shadow load mode.
 * Valid values for the variables are:
 *  - aqModule
 *      - EPWM_ACTION_QUALIFIER_A - Action Qualifier A.
 *      - EPWM_ACTION_QUALIFIER_B - Action Qualifier B.
 *  - loadMode
 *      - EPWM_AQ_LOAD_ON_CNTR_ZERO - load when counter equals zero
 *      - EPWM_AQ_LOAD_ON_CNTR_PERIOD - load when counter equals period
 *      - EPWM_AQ_LOAD_ON_CNTR_ZERO_PERIOD - load when counter equals
 *                                               zero or period
 *      - EPWM_AQ_LOAD_FREEZE  - Freeze shadow to active load
 *      - EPWM_AQ_LOAD_ON_SYNC_CNTR_ZERO - load on sync or when counter
 *                                          equals zero
 *      - EPWM_AQ_LOAD_ON_SYNC_CNTR_PERIOD - load on sync or when counter
 *                                           equals period
 *      - EPWM_AQ_LOAD_ON_SYNC_CNTR_ZERO_PERIOD - load on sync or when
 *                                               counter equals zero or period
 *      - EPWM_AQ_LOAD_ON_SYNC_ONLY - load on sync only
 *
 */
static inline void
EPWM_setActionQualifierShadowLoadMode(EPWM_REGS_Type *base,
                                      EPWM_ActionQualifierModule aqModule,
                                      EPWM_ActionQualifierLoadMode loadMode)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Set the appropriate sync and load mode bits and also enable shadow 
        load mode. Shadow to active load can also be frozen.*/
    if (aqModule == EPWM_ACTION_QUALIFIER_A)
    {
        base->AQCTL = (base->AQCTL & ~(EPWM_REGS_AQCTL_SHDWAQAMODE_Msk | EPWM_REGS_AQCTL_LDAQASYNC_Msk)) |
                        EPWM_REGS_AQCTL_LDAQASYNC_Set(loadMode >> 2U) | 
                        EPWM_REGS_AQCTL_SHDWAQAMODE_Set(loadMode & 0x3U);
    }
    else
    {
        base->AQCTL = (base->AQCTL & ~(EPWM_REGS_AQCTL_SHDWAQBMODE_Msk | EPWM_REGS_AQCTL_LDAQBSYNC_Msk)) |
                        EPWM_REGS_AQCTL_LDAQBSYNC_Set(loadMode >> 2U) | 
                        EPWM_REGS_AQCTL_SHDWAQBMODE_Set(loadMode & 0x3U);

    }
}

/*!
 * Disable Action Qualifier shadow load mode
 *
 * \param base is the base address of the EPWM module.
 * \param aqModule is the Action Qualifier module value.
 *
 * This function disables the Action Qualifier  shadow load mode.
 * Valid values for the variables are:
 *  - aqModule
 *      - EPWM_ACTION_QUALIFIER_A - Action Qualifier A.
 *      - EPWM_ACTION_QUALIFIER_B - Action Qualifier B.
 *
 */
static inline void
EPWM_disableActionQualifierShadowLoadMode(EPWM_REGS_Type *base,
                                          EPWM_ActionQualifierModule aqModule)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    if (aqModule == EPWM_ACTION_QUALIFIER_A)
    {
        /* Disable shadow load mode. Action qualifier is loaded on immediate mode only. */
        base->AQCTL &= ~EPWM_REGS_AQCTL_SHDWAQAMODE_Set(1);
    }
    else
    {
        base->AQCTL &= ~EPWM_REGS_AQCTL_SHDWAQBMODE_Set(1);
    }
}

/*!
 * Set up Action qualifier trigger source for event T1
 *
 * \param base is the base address of the EPWM module.
 * \param trigger sources for Action Qualifier triggers.
 *
 * This function sets up the sources for Action Qualifier event T1.
 * Valid values for trigger are:
 *   - EPWM_AQ_TRIGGER_EVENT_TRIG_DCA_1       - Digital compare event A 1
 *   - EPWM_AQ_TRIGGER_EVENT_TRIG_DCA_2       - Digital compare event A 2
 *   - EPWM_AQ_TRIGGER_EVENT_TRIG_DCB_1       - Digital compare event B 1
 *   - EPWM_AQ_TRIGGER_EVENT_TRIG_DCB_2       - Digital compare event B 2
 *   - EPWM_AQ_TRIGGER_EVENT_TRIG_TZ_1        - Trip zone 1
 *   - EPWM_AQ_TRIGGER_EVENT_TRIG_TZ_2        - Trip zone 2
 *   - EPWM_AQ_TRIGGER_EVENT_TRIG_TZ_3        - Trip zone 3
 *   - EPWM_AQ_TRIGGER_EVENT_TRIG_EPWM_SYNCIN - ePWM sync
 *   - EPWM_AQ_TRIGGER_EVENT_TRIG_DC_EVTFILT  - Digital compare filter event
 *
 */
static inline void
EPWM_setActionQualifierT1TriggerSource(EPWM_REGS_Type *base,
                                     EPWM_ActionQualifierTriggerSource trigger)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Set T1 trigger source */
    base->AQTSRCSEL = (base->AQTSRCSEL & ~EPWM_REGS_AQTSRCSEL_T1SEL_Msk) |
                        EPWM_REGS_AQTSRCSEL_T1SEL_Set(trigger);
}

/*!
 * Set up Action qualifier trigger source for event T2
 *
 * \param base is the base address of the EPWM module.
 * \param trigger sources for Action Qualifier triggers.
 *
 * This function sets up the sources for Action Qualifier event T2.
 * Valid values for trigger are:
 *   - EPWM_AQ_TRIGGER_EVENT_TRIG_DCA_1       - Digital compare event A 1
 *   - EPWM_AQ_TRIGGER_EVENT_TRIG_DCA_2       - Digital compare event A 2
 *   - EPWM_AQ_TRIGGER_EVENT_TRIG_DCB_1       - Digital compare event B 1
 *   - EPWM_AQ_TRIGGER_EVENT_TRIG_DCB_2       - Digital compare event B 2
 *   - EPWM_AQ_TRIGGER_EVENT_TRIG_TZ_1        - Trip zone 1
 *   - EPWM_AQ_TRIGGER_EVENT_TRIG_TZ_2        - Trip zone 2
 *   - EPWM_AQ_TRIGGER_EVENT_TRIG_TZ_3        - Trip zone 3
 *   - EPWM_AQ_TRIGGER_EVENT_TRIG_EPWM_SYNCIN - ePWM sync
 *   - EPWM_AQ_TRIGGER_EVENT_TRIG_DC_EVTFILT  - Digital compare filter event
 *
 */
static inline void
EPWM_setActionQualifierT2TriggerSource(EPWM_REGS_Type *base,
                                      EPWM_ActionQualifierTriggerSource trigger)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Set T2 trigger source */
    base->AQTSRCSEL = (base->AQTSRCSEL & ~EPWM_REGS_AQTSRCSEL_T2SEL_Msk) |
                        EPWM_REGS_AQTSRCSEL_T2SEL_Set(trigger);
}

/*!
 * Set up Action qualifier outputs
 *
 * \param base is the base address of the EPWM module.
 * \param epwmOutput is the ePWM pin type.
 * \param output is the Action Qualifier output.
 * \param event is the event that causes a change in output.
 *
 * This function sets up the Action Qualifier output on ePWM A or ePWMB,
 * depending on the value of epwmOutput, to a value specified by outPut based
 * on the input events - specified by event.
 * The following are valid values for the parameters.
 *   - epwmOutput
 *       - EPWM_AQ_OUTPUT_A          - ePWMxA output
 *       - EPWM_AQ_OUTPUT_B          - ePWMxB output
 *   - output
 *       - EPWM_AQ_OUTPUT_NO_CHANGE  - No change in the output pins
 *       - EPWM_AQ_OUTPUT_LOW        - Set output pins to low
 *       - EPWM_AQ_OUTPUT_HIGH       - Set output pins to High
 *       - EPWM_AQ_OUTPUT_TOGGLE     - Toggle the output pins
 *   - event
 *       - EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO       - Time base counter equals
 *                                                 zero
 *       - EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD     - Time base counter equals
 *                                                 period
 *       - EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA    - Time base counter up equals
 *                                                 COMPA
 *       - EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA  - Time base counter down
 *                                                 equals COMPA
 *       - EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB    - Time base counter up equals
 *                                                 COMPB
 *       - EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB  - Time base counter down
 *                                                 equals COMPB
 *       - EPWM_AQ_OUTPUT_ON_T1_COUNT_UP         - T1 event on count up
 *       - EPWM_AQ_OUTPUT_ON_T1_COUNT_DOWN       - T1 event on count down
 *       - EPWM_AQ_OUTPUT_ON_T2_COUNT_UP         - T2 event on count up
 *       - EPWM_AQ_OUTPUT_ON_T2_COUNT_DOWN       - T2 event on count down
 *
 */
static inline void
EPWM_setActionQualifierAction(EPWM_REGS_Type *base,
                              EPWM_ActionQualifierOutputModule epwmOutput,
                              EPWM_ActionQualifierOutput output,
                              EPWM_ActionQualifierOutputEvent event)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    if (epwmOutput == EPWM_AQ_OUTPUT_A)
    {
        /* If the event occurs on T1 or T2 events */
        if(((uint16_t)event & 0x1U) == 1U)
        {
            /* Write to T1U,T1D,T2U or T2D of AQCTLA2 register */
            base->AQCTLA2 = (base->AQCTLA2 & ~(3U << ((uint16_t)event - 1U))) | 
                                ((uint16_t)output << ((uint16_t)event - 1U));
        }
        else
        {
            /* Write to ZRO,PRD,CAU,CAD,CBU or CBD bits of AQCTLA register */
            base->AQCTLA = (base->AQCTLA & ~(3U << ((uint16_t)event))) | 
                                ((uint16_t)output << ((uint16_t)event));
        }        
    } 
    else
    {    
        /* If the event occurs on T1 or T2 events */
        if(((uint16_t)event & 0x1U) == 1U)
        {
            /* Write to T1U,T1D,T2U or T2D of AQCTLA2 register */
            base->AQCTLB2 = (base->AQCTLB2 & ~(3U << ((uint16_t)event - 1U))) | 
                                ((uint16_t)output << ((uint16_t)event - 1U));
        }
        else
        {
            /* Write to ZRO,PRD,CAU,CAD,CBU or CBD bits of AQCTLA register */
            base->AQCTLB = (base->AQCTLB & ~(3U << ((uint16_t)event))) | 
                                ((uint16_t)output << ((uint16_t)event));
        }                
    }        
}

/*!
 * Set up Action qualifier event outputs
 *
 * \param base is the base address of the EPWM module.
 * \param epwmOutput is the ePWM pin type.
 * \param action is the desired action when the specified event occurs
 *
 * This function sets up the Action Qualifier output on ePWMA or ePWMB,
 * depending on the value of epwmOutput, to a value specified by action.
 * Valid action param values from different time base counter scenarios
 * should be OR'd together to configure complete action for a pwm output.
 * The following are valid values for the parameters.
 *   - epwmOutput
 *       - EPWM_AQ_OUTPUT_A          - ePWMxA output
 *       - EPWM_AQ_OUTPUT_B          - ePWMxB output
 *
 *   - action
 *       - When time base counter equals zero
 *         - EPWM_AQ_OUTPUT_NO_CHANGE_ZERO   - Time base counter equals zero
 *                                             and no change in output pins
 *         - EPWM_AQ_OUTPUT_LOW_ZERO         - Time base counter equals zero
 *                                             and set output pins to low
 *         - EPWM_AQ_OUTPUT_HIGH_ZERO        - Time base counter equals zero
 *                                             and set output pins to high
 *         - EPWM_AQ_OUTPUT_TOGGLE_ZERO      - Time base counter equals zero
 *                                             and toggle the output pins
 *       - When time base counter equals period
 *         - EPWM_AQ_OUTPUT_NO_CHANGE_PERIOD - Time base counter equals period
 *                                             and no change in output pins
 *         - EPWM_AQ_OUTPUT_LOW_PERIOD       - Time base counter equals period
 *                                             and set output pins to low
 *         - EPWM_AQ_OUTPUT_HIGH_PERIOD      - Time base counter equals period
 *                                             and set output pins to high
 *         - EPWM_AQ_OUTPUT_TOGGLE_PERIOD    - Time base counter equals period
 *                                             and toggle the output pins
 *       - When time base counter equals CMPA during up-count
 *         - EPWM_AQ_OUTPUT_NO_CHANGE_UP_CMPA  - Time base counter up equals
 *                                               COMPA and no change in the
 *                                               output pins
 *         - EPWM_AQ_OUTPUT_LOW_UP_CMPA        - Time base counter up equals
 *                                               COMPA and set output pins low
 *         - EPWM_AQ_OUTPUT_HIGH_UP_CMPA       - Time base counter up equals
 *                                               COMPA and set output pins high
 *         - EPWM_AQ_OUTPUT_TOGGLE_UP_CMPA     - Time base counter up equals
 *                                               COMPA and toggle output pins
 *       - When time base counter equals CMPA during down-count
 *         - EPWM_AQ_OUTPUT_NO_CHANGE_DOWN_CMPA - Time base counter down equals
 *                                                COMPA and no change in the
 *                                                output pins
 *         - EPWM_AQ_OUTPUT_LOW_DOWN_CMPA      - Time base counter down equals
 *                                               COMPA and set output pins low
 *         - EPWM_AQ_OUTPUT_HIGH_DOWN_CMPA     - Time base counter down equals
 *                                               COMPA and set output pins high
 *         - EPWM_AQ_OUTPUT_TOGGLE_DOWN_CMPA   - Time base counter down equals
 *                                               COMPA and toggle output pins
 *       - When time base counter equals CMPB during up-count
 *         - EPWM_AQ_OUTPUT_NO_CHANGE_UP_CMPB  - Time base counter up equals
 *                                               COMPB and no change in the
 *                                               output pins
 *         - EPWM_AQ_OUTPUT_LOW_UP_CMPB        - Time base counter up equals
 *                                               COMPB and set output pins low
 *         - EPWM_AQ_OUTPUT_HIGH_UP_CMPB       - Time base counter up equals
 *                                               COMPB and set output pins high
 *         - EPWM_AQ_OUTPUT_TOGGLE_UP_CMPB     - Time base counter up equals
 *                                               COMPB and toggle output pins
 *       - When time base counter equals CMPB during down-count
 *         - EPWM_AQ_OUTPUT_NO_CHANGE_DOWN_CMPB- Time base counter down equals
 *                                               COMPB and no change in the
 *                                               output pins
 *         - EPWM_AQ_OUTPUT_LOW_DOWN_CMPB      - Time base counter down equals
 *                                               COMPB and set output pins low
 *         - EPWM_AQ_OUTPUT_HIGH_DOWN_CMPB     - Time base counter down equals
 *                                               COMPB and set output pins high
 *         - EPWM_AQ_OUTPUT_TOGGLE_DOWN_CMPB   - Time base counter down equals
 *                                               COMPB and toggle output pins
 *
 * \b note:  A logical OR of the valid values should be passed as the action
 *           parameter. Single action should be configured for each time base
 *           counter scenario.
 *
 */
static inline void
EPWM_setActionQualifierActionComplete(EPWM_REGS_Type *base,
                                      EPWM_ActionQualifierOutputModule epwmOutput,
                                      uint16_t action)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    if (epwmOutput == EPWM_AQ_OUTPUT_A) 
    {
        /* Write to ZRO, PRD, CAU, CAD, CBU or CBD bits of AQCTLA register */
        base->AQCTLA = (uint16_t)action;
    }
    if (epwmOutput == EPWM_AQ_OUTPUT_B) 
    {
        /* Write to ZRO, PRD, CAU, CAD, CBU or CBD bits of AQCTLB register */
        base->AQCTLB = (uint16_t)action;
    }
}

/*!
 * Set up Additional action qualifier event outputs
 *
 * \param base is the base address of the EPWM module.
 * \param epwmOutput is the ePWM pin type.
 * \param action is the desired action when the specified event occurs
 *
 * This function sets up the Additional Action Qualifier output on ePWMA or
 * ePWMB depending on the value of epwmOutput, to a value specified by action.
 * Valid action param values from different event scenarios should be OR'd
 * together to configure complete action for a pwm output.
 * The following are valid values for the parameters.
 *   - epwmOutput
 *       - EPWM_AQ_OUTPUT_A          - ePWMxA output
 *       - EPWM_AQ_OUTPUT_B          - ePWMxB output
 *   - action
 *       - When T1 event occurs during up-count
 *         - EPWM_AQ_OUTPUT_NO_CHANGE_UP_T1  - T1 event on count up
 *                                             and no change in output pins
 *         - EPWM_AQ_OUTPUT_LOW_UP_T1        - T1 event on count up
 *                                           and set output pins to low
 *         - EPWM_AQ_OUTPUT_HIGH_UP_T1       - T1 event on count up
 *                                           and set output pins to high
 *         - EPWM_AQ_OUTPUT_TOGGLE_UP_T1     - T1 event on count up
 *                                           and toggle the output pins
 *       - When T1 event occurs during down-count
 *         - EPWM_AQ_OUTPUT_NO_CHANGE_DOWN_T1- T1 event on count down
 *                                           and no change in output pins
 *         - EPWM_AQ_OUTPUT_LOW_DOWN_T1      - T1 event on count down
 *                                           and set output pins to low
 *         - EPWM_AQ_OUTPUT_HIGH_DOWN_T1     - T1 event on count down
 *                                           and set output pins to high
 *         - EPWM_AQ_OUTPUT_TOGGLE_DOWN_T1   - T1 event on count down
 *                                           and toggle the output pins
 *       - When T2 event occurs during up-count
 *         - EPWM_AQ_OUTPUT_NO_CHANGE_UP_T2  - T2 event on count up
 *                                             and no change in output pins
 *         - EPWM_AQ_OUTPUT_LOW_UP_T2        - T2 event on count up
 *                                             and set output pins to low
 *         - EPWM_AQ_OUTPUT_HIGH_UP_T2       - T2 event on count up
 *                                             and set output pins to high
 *         - EPWM_AQ_OUTPUT_TOGGLE_UP_T2     - T2 event on count up
 *                                             and toggle the output pins
 *       - When T2 event occurs during down-count
 *         - EPWM_AQ_OUTPUT_NO_CHANGE_DOWN_T2 - T2 event on count down
 *                                              and no change in output pins
 *         - EPWM_AQ_OUTPUT_LOW_DOWN_T2       - T2 event on count down
 *                                              and set output pins to low
 *         - EPWM_AQ_OUTPUT_HIGH_DOWN_T2      - T2 event on count down
 *                                              and set output pins to high
 *         - EPWM_AQ_OUTPUT_TOGGLE_DOWN_T2    - T2 event on count down
 *                                              and toggle the output pins
 *
 * \b note:  A logical OR of the valid values should be passed as the action
 *           parameter. Single action should be configured for each event
 *           scenario.
 *
 *  
 */
static inline void
EPWM_setAdditionalActionQualifierActionComplete(EPWM_REGS_Type *base,
                               EPWM_ActionQualifierOutputModule epwmOutput,
                               uint16_t action)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    if (epwmOutput == EPWM_AQ_OUTPUT_A)
    {
        /* Write to T1U, T1D, T2U or T2D of AQCTLA2 register */
        base->AQCTLA2 = (uint16_t)action;
    }
    if (epwmOutput == EPWM_AQ_OUTPUT_B)
    {
        /* Write to T1U, T1D, T2U or T2D of AQCTLB2 register */
        base->AQCTLB2 = (uint16_t)action;
    }
}

/*!
 * Sets up Action qualifier continuous software load mode.
 *
 * \param base is the base address of the EPWM module.
 * \param mode is the mode for shadow to active load mode.
 *
 * This function sets up the AQCFRSC register load mode for continuous
 * software force reload mode. The software force actions are determined by
 * the EPWM_setActionQualifierContSWForceAction() function.
 * Valid values for mode are:
 *   - EPWM_AQ_SW_SH_LOAD_ON_CNTR_ZERO        - shadow mode load when counter
 *                                               equals zero
 *   - EPWM_AQ_SW_SH_LOAD_ON_CNTR_PERIOD      - shadow mode load when counter
 *                                               equals period
 *   - EPWM_AQ_SW_SH_LOAD_ON_CNTR_ZERO_PERIOD - shadow mode load when counter
 *                                               equals zero or period
 *   - EPWM_AQ_SW_IMMEDIATE_LOAD               - immediate mode load only
 *
 *  
 */
static inline void
EPWM_setActionQualifierContSWForceShadowMode(EPWM_REGS_Type *base,
                                             EPWM_ActionQualifierContForce mode)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Write to RLDCSF bit */
    base->AQSFRC = (base->AQSFRC & ~EPWM_REGS_AQSFRC_RLDCSF_Msk) | 
                    ((uint16_t)mode << EPWM_REGS_AQSFRC_RLDCSF_Pos);
}

/*!
 * Triggers a continuous software forced event.
 *
 * \param base is the base address of the EPWM module.
 * \param epwmOutput is the ePWM pin type.
 * \param output is the Action Qualifier output.
 *
 * This function triggers a continuous software forced Action Qualifier output
 * on ePWM A or B based on the value of epwmOutput.
 * Valid values for the parameters are:
 *   - epwmOutput
 *       - EPWM_AQ_OUTPUT_A          - ePWMxA output
 *       - EPWM_AQ_OUTPUT_B          - ePWMxB output
 *   - output
 *       - EPWM_AQ_SW_DISABLED       - Software forcing disabled.
 *       - EPWM_AQ_SW_OUTPUT_LOW     - Set output pins to low
 *       - EPWM_AQ_SW_OUTPUT_HIGH    - Set output pins to High
 *  
 */
static inline void
EPWM_setActionQualifierContSWForceAction(EPWM_REGS_Type *base,
                                    EPWM_ActionQualifierOutputModule epwmOutput,
                                    EPWM_ActionQualifierSWOutput output)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Initiate a continuous software forced output */
    if(epwmOutput == EPWM_AQ_OUTPUT_A)
    {
        base->AQCSFRC = (base->AQCSFRC & ~EPWM_REGS_AQCSFRC_CSFA_Msk) | (uint16_t)output;
    }
    else
    {
        base->AQCSFRC = (base->AQCSFRC & ~EPWM_REGS_AQCSFRC_CSFB_Msk) | (uint16_t)output;
    }
}

/*!
 * Set up one time software forced Action qualifier outputs
 *
 * \param base is the base address of the EPWM module.
 * \param epwmOutput is the ePWM pin type.
 * \param output is the Action Qualifier output.
 *
 * This function sets up the one time software forced Action Qualifier output
 * on ePWM A or ePWMB, depending on the value of epwmOutput to a value
 * specified by outPut.
 * The following are valid values for the parameters.
 *   - epwmOutput
 *       - EPWM_AQ_OUTPUT_A          - ePWMxA output
 *       - EPWM_AQ_OUTPUT_B          - ePWMxB output
 *   - output
 *       - EPWM_AQ_OUTPUT_NO_CHANGE  - No change in the output pins
 *       - EPWM_AQ_OUTPUT_LOW        - Set output pins to low
 *       - EPWM_AQ_OUTPUT_HIGH       - Set output pins to High
 *       - EPWM_AQ_OUTPUT_TOGGLE     - Toggle the output pins
 *  
 */
static inline void
EPWM_setActionQualifierSWAction(EPWM_REGS_Type *base,
                                EPWM_ActionQualifierOutputModule epwmOutput,
                                EPWM_ActionQualifierOutput output)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Set the one time software forced action */
   if(epwmOutput == EPWM_AQ_OUTPUT_A)
   {
        base->AQSFRC = (base->AQSFRC & ~EPWM_REGS_AQSFRC_ACTSFA_Msk) | (uint16_t)output;
   }
   else
   {
        base->AQSFRC = (base->AQSFRC & ~EPWM_REGS_AQSFRC_ACTSFA_Msk) | (uint16_t)output;
   }
}

/*!
 * Triggers a one time software forced event on Action qualifier
 *
 * \param base is the base address of the EPWM module.
 * \param epwmOutput is the ePWM pin type.
 *
 * This function triggers a one time software forced Action Qualifier event
 * on ePWM A or B based on the value of epwmOutput.
 * Valid values for epwmOutput are:
 *   - EPWM_AQ_OUTPUT_A          - ePWMxA output
 *   - EPWM_AQ_OUTPUT_B          - ePWMxB output
 *  
 */
static inline void
EPWM_forceActionQualifierSWAction(EPWM_REGS_Type *base,
                                  EPWM_ActionQualifierOutputModule epwmOutput)
{
    /* Check the arguments */
   assert(EPWM_isBaseValid(base));

   /* Initiate a software forced event */
   if(epwmOutput == EPWM_AQ_OUTPUT_A)
   {
       base->AQSFRC = (base->AQSFRC & ~EPWM_REGS_AQSFRC_OTSFA_Msk) | EPWM_REGS_AQSFRC_OTSFA_Set(1);
   }
   else
   {
       base->AQSFRC = (base->AQSFRC & ~EPWM_REGS_AQSFRC_OTSFB_Msk) | EPWM_REGS_AQSFRC_OTSFB_Set(1);
   }
}

/*!
 * Sets Dead Band signal output swap mode.
 *
 * \param base is the base address of the EPWM module.
 * \param output is the ePWM Dead Band output.
 * \param enableSwapMode is the output swap mode.
 *
 * This function sets up the output signal swap mode. For example if the
 * output variable is set to EPWM_DB_OUTPUT_A and enableSwapMode is true, then
 * the ePWM A output gets its signal from the ePWM B signal path. Valid values
 * for the input variables are:
 *  - output
 *      - EPWM_DB_OUTPUT_A   - ePWM output A
 *      - EPWM_DB_OUTPUT_B   - ePWM output B
 *  - enableSwapMode
 *      - true     - the output is swapped
 *      - false    - the output and the signal path are the same.
 *  
 */
static inline void
EPWM_setDeadBandOutputSwapMode(EPWM_REGS_Type *base, EPWM_DeadBandOutput output,
                               bool enableSwapMode)
{
    /* Check the arguments */
   assert(EPWM_isBaseValid(base));

   if (enableSwapMode)
   {
       if (output == EPWM_DB_OUTPUT_B)
       {
            /* Set ePWMB the appropriate outswap bit to swap output */
            base->DBCTL = (base->DBCTL & ~EPWM_REGS_DBCTL_OUTSWAP_Msk) | 
                            EPWM_REGS_DBCTL_OUTSWAP_Set(1);
        } 
        else
        {
            /* Set ePWMA the appropriate outswap bit to swap output */
            base->DBCTL = (base->DBCTL & ~EPWM_REGS_DBCTL_OUTSWAP_Msk) | 
                            EPWM_REGS_DBCTL_OUTSWAP_Set(2);
        }
    }
    else
    {
        /* Clear the appropriate outswap bit to disable output swap */
            base->DBCTL = (base->DBCTL & ~EPWM_REGS_DBCTL_OUTSWAP_Msk) | 
                            EPWM_REGS_DBCTL_OUTSWAP_Set(0);
    }
}

/*!
 * Sets Dead Band signal output mode.
 *
 * \param base is the base address of the EPWM module.
 * \param delayMode is the Dead Band delay type.
 * \param enableDelayMode is the dead band delay mode.
 *
 * This function sets up the dead band delay mode. The delayMode variable
 * determines if the applied delay is Rising Edge or Falling Edge. The
 * enableDelayMode determines if a dead band delay should be applied.
 * Valid values for the variables are:
 *  - delayMode
 *      - EPWM_DB_RED   - Rising Edge delay
 *      - EPWM_DB_FED   - Falling Edge delay
 *  - enableDelayMode
 *      - true     - Falling edge or Rising edge delay is applied.
 *      - false    - Dead Band delay is bypassed.
 *  
 */
static inline void
EPWM_setDeadBandDelayMode(EPWM_REGS_Type *base, EPWM_DeadBandDelayMode delayMode,
                          bool enableDelayMode)
{
    uint16_t mask;

    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    mask = (uint16_t)1U << ((uint16_t)delayMode + EPWM_REGS_DBCTL_OUT_MODE_Pos);
    if(enableDelayMode)
    {
        /* Set the appropriate outmode bit to enable Dead Band delay */
        base->DBCTL |= mask;
    }
    else
    {
        /* Clear the appropriate outswap bit to disable output swap */
        base->DBCTL &= ~mask;
    }
}

/*!
 * Sets Dead Band delay polarity.
 *
 * \param base is the base address of the EPWM module.
 * \param delayMode is the Dead Band delay type.
 * \param polarity is the polarity of the delayed signal.
 *
 * This function sets up the polarity as determined by the variable polarity
 * of the Falling Edge or Rising Edge delay depending on the value of
 * delayMode. Valid values for the variables are:
 *   - delayMode
 *       - EPWM_DB_RED   - Rising Edge delay
 *       - EPWM_DB_FED   - Falling Edge delay
 *   - polarity
 *       - EPWM_DB_POLARITY_ACTIVE_HIGH   - polarity is not inverted.
 *       - EPWM_DB_POLARITY_ACTIVE_LOW    - polarity is inverted.
 *  
 */
static inline void
EPWM_setDeadBandDelayPolarity(EPWM_REGS_Type *base,
                              EPWM_DeadBandDelayMode delayMode,
                              EPWM_DeadBandPolarity polarity)
{
    uint8_t shift;

    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    shift = (uint16_t)((delayMode ^ 0x1U) + 2);
    /* Set the appropriate polsel bits for dead band polarity */
    base->DBCTL = (base->DBCTL & ~(1U << shift)) | 
                        (polarity << shift);
}

/*!
 * Sets Rising Edge Dead Band delay input.
 *
 * \param base is the base address of the EPWM module.
 * \param input is the input signal to the dead band.
 *
 * This function sets up the rising Edge delay input signal.
 * Valid values for input are:
 *     - EPWM_DB_INPUT_EPWMA   - Input signal is ePWMA( Valid for both Falling
 *                                  Edge and Rising Edge)
 *     - EPWM_DB_INPUT_EPWMB   - Input signal is ePWMB( Valid for both Falling
 *                                  Edge and Rising Edge)
 *
 */
static inline void
EPWM_setRisingEdgeDeadBandDelayInput(EPWM_REGS_Type *base, uint16_t input)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));
    assert((input == EPWM_DB_INPUT_EPWMA) || (input == EPWM_DB_INPUT_EPWMB));

    /* Set the Rising Edge Delay input */
    base->DBCTL = (base->DBCTL & ~EPWM_REGS_DBCTL_IN_MODE_Msk) | 
                        EPWM_REGS_DBCTL_IN_MODE_Set(input);
}

/*!
 * Sets Dead Band delay input.
 *
 * \param base is the base address of the EPWM module.
 * \param input is the input signal to the dead band.
 *
 * This function sets up the rising Edge delay input signal.
 * Valid values for input are:
 *   - EPWM_DB_INPUT_EPWMA   - Input signal is ePWMA(Valid for both Falling
 *                                Edge and Rising Edge)
 *   - EPWM_DB_INPUT_EPWMB   - Input signal is ePWMB(Valid for both Falling
 *                                Edge and Rising Edge)
 *   - EPWM_DB_INPUT_DB_RED  - Input signal is the output of Rising
 *                                Edge delay.
 *                               (Valid only for Falling Edge delay)
 *
 */
static inline void
EPWM_setFallingEdgeDeadBandDelayInput(EPWM_REGS_Type *base, uint16_t input)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));
    assert((input == EPWM_DB_INPUT_EPWMA) || (input == EPWM_DB_INPUT_EPWMB) || (input == EPWM_DB_INPUT_DB_RED));

    if(input == EPWM_DB_INPUT_DB_RED)
    {
        /* Set the Falling Edge Delay input */
        base->DBCTL = (base->DBCTL & ~EPWM_REGS_DBCTL_DEDB_MODE_Msk) |
                        EPWM_REGS_DBCTL_DEDB_MODE_Set(1); 
    }
    else
    {
        /* Set the Falling Edge Delay input not enable*/
        base->DBCTL = (base->DBCTL & ~EPWM_REGS_DBCTL_DEDB_MODE_Msk) |
                        EPWM_REGS_DBCTL_DEDB_MODE_Set(0); 

        /* Set the Rising Edge Delay input */
        base->DBCTL = (base->DBCTL & ~EPWM_REGS_DBCTL_IN_MODE_Msk) |
                        EPWM_REGS_DBCTL_IN_MODE_Set(input << 1); 
    }
}

/*!
 * Set the Dead Band control shadow load mode.
 *
 * \param base is the base address of the EPWM module.
 * \param loadMode is the shadow to active load mode.
 *
 * This function enables and sets the Dead Band control register shadow
 * load mode.
 * Valid values for the \e loadMode parameter are:
 *     - EPWM_DB_LOAD_ON_CNTR_ZERO         - load when counter equals zero.
 *     - EPWM_DB_LOAD_ON_CNTR_PERIOD       - load when counter equals period.
 *     - EPWM_DB_LOAD_ON_CNTR_ZERO_PERIOD  - load when counter equals zero or
 *                                            period.
 *     - EPWM_DB_LOAD_FREEZE                - Freeze shadow to active load.
 *
 */
static inline void
EPWM_setDeadBandControlShadowLoadMode(EPWM_REGS_Type *base,
                                      EPWM_DeadBandControlLoadMode loadMode)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Enable the shadow mode and setup the load event */
    base->DBCTL2 = (base->DBCTL2 & ~EPWM_REGS_DBCTL2_LOADDBCTLMODE_Msk) |
                        EPWM_REGS_DBCTL2_SHDWDBCTLMODE_Set(1)           |
                        EPWM_REGS_DBCTL2_LOADDBCTLMODE_Set(loadMode);
}

/*!
 * Disable Dead Band control shadow load mode.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function disables the Dead Band control register shadow
 * load mode.
 *
 */
static inline void
EPWM_disableDeadBandControlShadowLoadMode(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Disable the shadow load mode. Only immediate load mode only. */
    base->DBCTL2 = (base->DBCTL2 & ~EPWM_REGS_DBCTL2_SHDWDBCTLMODE_Msk) |
                        EPWM_REGS_DBCTL2_SHDWDBCTLMODE_Set(0);                                            
}

/*!
 * Set the RED (Rising Edge Delay) shadow load mode.
 *
 * \param base is the base address of the EPWM module.
 * \param loadMode is the shadow to active load event.
 *
 * This function sets the Rising Edge Delay register shadow load mode.
 * Valid values for the \e loadMode parameter are:
 *     - EPWM_RED_LOAD_ON_CNTR_ZERO        - load when counter equals zero.
 *     - EPWM_RED_LOAD_ON_CNTR_PERIOD      - load when counter equals period.
 *     - EPWM_RED_LOAD_ON_CNTR_ZERO_PERIOD - load when counter equals zero or
 *                                           period.
 *     - EPWM_RED_LOAD_FREEZE               - Freeze shadow to active load.
 *
 */
static inline void
EPWM_setRisingEdgeDelayCountShadowLoadMode(EPWM_REGS_Type *base,
                                         EPWM_RisingEdgeDelayLoadMode loadMode)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Enable the shadow mode. Set-up the load mode */
    base->DBCTL = (base->DBCTL & ~EPWM_REGS_DBCTL_LOADREDMODE_Msk) |
                        EPWM_REGS_DBCTL_LOADREDMODE_Set(loadMode)  |
                        EPWM_REGS_DBCTL_SHDWDBREDMODE_Set(1);
}

/*!
 * Disable the RED (Rising Edge Delay) shadow load mode.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function disables the Rising Edge Delay register shadow load mode.
 *
 */
static inline void
EPWM_disableRisingEdgeDelayCountShadowLoadMode(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Disable the shadow mode. */
    base->DBCTL = (base->DBCTL & ~EPWM_REGS_DBCTL_SHDWDBREDMODE_Msk) |
                        EPWM_REGS_DBCTL_SHDWDBREDMODE_Set(0);
}

/*!
 * Set the FED (Falling Edge Delay) shadow load mode.
 *
 * \param base is the base address of the EPWM module.
 * \param loadMode is the shadow to active load event.
 *
 * This function enables and sets the Falling Edge Delay register shadow load
 * mode. Valid values for the \e loadMode parameters are:
 *     - EPWM_FED_LOAD_ON_CNTR_ZERO        - load when counter equals zero.
 *     - EPWM_FED_LOAD_ON_CNTR_PERIOD      - load when counter equals period.
 *     - EPWM_FED_LOAD_ON_CNTR_ZERO_PERIOD - load when counter equals zero or
 *                                            period.
 *     - EPWM_FED_LOAD_FREEZE               - Freeze shadow to active load.
 *
 */
static inline void
EPWM_setFallingEdgeDelayCountShadowLoadMode(EPWM_REGS_Type *base,
                                        EPWM_FallingEdgeDelayLoadMode loadMode)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Enable the shadow mode. Setup the load mode. */
    base->DBCTL = (base->DBCTL & ~EPWM_REGS_DBCTL_LOADFEDMODE_Msk) |
                        EPWM_REGS_DBCTL_SHDWDBFEDMODE_Set(1) |
                        EPWM_REGS_DBCTL_LOADFEDMODE_Set(loadMode);
}

/*!
 * Disables the FED (Falling Edge Delay) shadow load mode.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function disables the Falling Edge Delay register shadow load mode.
 * Valid values for the parameters are:
 *  
 */
static inline void
EPWM_disableFallingEdgeDelayCountShadowLoadMode(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Disable the shadow mode. */
    base->DBCTL = (base->DBCTL & ~EPWM_REGS_DBCTL_SHDWDBFEDMODE_Msk);
}

/*!
 * Sets Dead Band Counter clock rate.
 *
 * \param base is the base address of the EPWM module.
 * \param clockMode is the Dead Band counter clock mode.
 *
 * This function sets up the Dead Band counter clock rate with respect to
 * TBCLK (ePWM time base counter).
 * Valid values for clockMode are:
 *   - EPWM_DB_COUNTER_CLOCK_FULL_CYCLE  -Dead band counter runs at TBCLK
 *                                           (ePWM Time Base Counter) rate.
 *   - EPWM_DB_COUNTER_CLOCK_HALF_CYCLE  -Dead band counter runs at 2*TBCLK
 *                                         (twice ePWM Time Base Counter)rate.
 *
 */
static inline void
EPWM_setDeadBandCounterClock(EPWM_REGS_Type *base,
                             EPWM_DeadBandClockMode clockMode)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Set the DB clock mode */
    base->DBCTL = (base->DBCTL & ~EPWM_REGS_DBCTL_HALFCYCLE_Msk) | \
                        EPWM_REGS_DBCTL_HALFCYCLE_Set(clockMode);
}

/*!
 * Set ePWM RED count
 *
 * \param base is the base address of the EPWM module.
 * \param redCount is the RED(Rising Edge Delay) count.
 *
 * This function sets the RED (Rising Edge Delay) count value.
 * The value of redCount should be less than 0x4000U.
 *
 */
static inline void
EPWM_setRisingEdgeDelayCount(EPWM_REGS_Type *base, uint16_t redCount)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));
    assert(redCount < 0x4000U);

    /* Set the RED (Rising Edge Delay) count */
    base->DBRED = EPWM_REGS_DBRED_DBRED_Set(redCount);
}

/*!
 * Set ePWM FED count
 *
 * \param base is the base address of the EPWM module.
 * \param fedCount is the FED(Falling Edge Delay) count.
 *
 * This function sets the FED (Falling Edge Delay) count value.
 * The value of fedCount should be less than 0x4000U.
 *
 */
static inline void
EPWM_setFallingEdgeDelayCount(EPWM_REGS_Type *base, uint16_t fedCount)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));
    assert(fedCount < 0x4000U);

    /* Set the RED (Rising Edge Delay) count */
    base->DBFED = EPWM_REGS_DBFED_DBFED_Set(fedCount);
}

/*!
 * Enable chopper mode
 *
 * \param base is the base address of the EPWM module.
 *
 * This function enables ePWM chopper module.
 *
 *  
 */
static inline void
EPWM_enableChopper(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Set CHPEN bit. Enable Chopper */
    base->PCCTL |= EPWM_REGS_PCCTL_CHPEN_Set(1);
}

/*!
 * Disable chopper mode
 *
 * \param base is the base address of the EPWM module.
 *
 * This function disables ePWM chopper module.
 *
 */
static inline void
EPWM_disableChopper(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Clear CHPEN bit. Disable Chopper */
    base->PCCTL &= ~EPWM_REGS_PCCTL_CHPEN_Set(1);
}

/*!
 * \brief Configure EPWM Chopper Mode
 *
 * \details Sets the chopper mode for the Enhanced Pulse Width Modulation (EPWM) module.
 *
 * \param[in] base Pointer to the EPWM peripheral register base address.
 * \param[in] mode A 16-bit value representing the chopper mode configuration. 
 *
 * \note The effect of this function depends on the specific implementation.
 *
 * \warning Incorrect configuration may impact system performance or power consumption.
 */
static inline void
EPWM_setChopperMode(EPWM_REGS_Type *base, uint16_t mode)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    base->PCCTL |= EPWM_REGS_PCCTL_CHPMODE_Set(mode);

    return;
}

/*!
 * Set chopper duty cycle.
 *
 * \param base is the base address of the EPWM module.
 * \param dutyCycleCount is the chopping clock duty cycle count.
 *
 * This function sets the chopping clock duty cycle. The value of
 * dutyCycleCount should be less than 7. The dutyCycleCount value is converted
 * to the actual chopper duty cycle value base on the following equation:
 *   chopper duty cycle = (dutyCycleCount + 1) / 8
 *
 */
static inline void
EPWM_setChopperDutyCycle(EPWM_REGS_Type *base, uint16_t dutyCycleCount)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));
    assert(dutyCycleCount < 7U);

    /* Set the chopper duty cycle */
    base->PCCTL = (base->PCCTL & ~EPWM_REGS_PCCTL_CHPDUTY_Msk) |
                        EPWM_REGS_PCCTL_CHPDUTY_Set(dutyCycleCount);
}

/*!
 * Set chopper clock frequency scaler.
 *
 * \param base is the base address of the EPWM module.
 * \param freqDiv is the chopping clock frequency divider.
 *
 * This function sets the scaler for the chopping clock frequency. The value
 * of freqDiv should be less than 8. The chopping clock frequency is altered
 * based on the following equation.
 *   chopper clock frequency = SYSCLKOUT / ( 1 + freqDiv)
 *
 */
static inline void
EPWM_setChopperFreq(EPWM_REGS_Type *base, uint16_t freqDiv)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));
    assert(freqDiv < 8U);

    /* Set the chopper clock */
    base->PCCTL = (base->PCCTL & ~EPWM_REGS_PCCTL_CHPFREQ_Msk) |
                        EPWM_REGS_PCCTL_CHPFREQ_Set(freqDiv);
}

/*!
 * Set chopper clock frequency scaler.
 *
 * \param base is the base address of the EPWM module.
 * \param firstPulseWidth is the width of the first pulse.
 *
 * This function sets the first pulse width of chopper output waveform. The
 * value of firstPulseWidth should be less than 0x10. The value of the first
 * pulse width in seconds is given using the following equation:
 *     first pulse width = 1 / (((firstPulseWidth + 1) * SYSCLKOUT)/8)
 *
 */
static inline void
EPWM_setChopperFirstPulseWidth(EPWM_REGS_Type *base, uint16_t firstPulseWidth)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));
    assert(firstPulseWidth < 16U);

    /* Set the chopper clock */
    base->PCCTL = (base->PCCTL & ~EPWM_REGS_PCCTL_OSHTWTH_Msk) |
                        EPWM_REGS_PCCTL_OSHTWTH_Set(firstPulseWidth);
}

/*!
 * Enables Trip Zone signal.
 *
 * \param base is the base address of the EPWM module.
 * \param tzSignal is the Trip Zone signal.
 *
 * This function enables the Trip Zone signals specified by tzSignal as a
 * source for the Trip Zone module.
 * Valid values for tzSignal are:
 *   - EPWM_TZ_SIGNAL_CBC1       - TZ1 Cycle By Cycle
 *   - EPWM_TZ_SIGNAL_CBC2       - TZ2 Cycle By Cycle
 *   - EPWM_TZ_SIGNAL_CBC3       - TZ3 Cycle By Cycle
 *   - EPWM_TZ_SIGNAL_CBC4       - TZ4 Cycle By Cycle
 *   - EPWM_TZ_SIGNAL_CBC5       - TZ5 Cycle By Cycle
 *   - EPWM_TZ_SIGNAL_CBC6       - TZ6 Cycle By Cycle
 *   - EPWM_TZ_SIGNAL_DCAEVT2    - DCAEVT2 Cycle By Cycle
 *   - EPWM_TZ_SIGNAL_DCBEVT2    - DCBEVT2 Cycle By Cycle
 *   - EPWM_TZ_SIGNAL_OSHT1      - One-shot TZ1
 *   - EPWM_TZ_SIGNAL_OSHT2      - One-shot TZ2
 *   - EPWM_TZ_SIGNAL_OSHT3      - One-shot TZ3
 *   - EPWM_TZ_SIGNAL_OSHT4      - One-shot TZ4
 *   - EPWM_TZ_SIGNAL_OSHT5      - One-shot TZ5
 *   - EPWM_TZ_SIGNAL_OSHT6      - One-shot TZ6
 *   - EPWM_TZ_SIGNAL_DCAEVT1    - One-shot DCAEVT1
 *   - EPWM_TZ_SIGNAL_DCBEVT1    - One-shot DCBEVT1
 *
 * \b note:  A logical OR of the valid values can be passed as the tzSignal
 *           parameter.
 *
 */
static inline void
EPWM_enableTripZoneSignals(EPWM_REGS_Type *base, uint16_t tzSignal)
{
    /* Check the arguments */ assert(EPWM_isBaseValid(base));

    /* Set the trip zone bits */
    base->TZSEL |= tzSignal;
}

/*!
 * Disables Trip Zone signal.
 *
 * \param base is the base address of the EPWM module.
 * \param tzSignal is the Trip Zone signal.
 *
 * This function disables the Trip Zone signal specified by tzSignal as a
 * source for the Trip Zone module.
 * Valid values for tzSignal are:
 *   - EPWM_TZ_SIGNAL_CBC1       - TZ1 Cycle By Cycle
 *   - EPWM_TZ_SIGNAL_CBC2       - TZ2 Cycle By Cycle
 *   - EPWM_TZ_SIGNAL_CBC3       - TZ3 Cycle By Cycle
 *   - EPWM_TZ_SIGNAL_CBC4       - TZ4 Cycle By Cycle
 *   - EPWM_TZ_SIGNAL_CBC5       - TZ5 Cycle By Cycle
 *   - EPWM_TZ_SIGNAL_CBC6       - TZ6 Cycle By Cycle
 *   - EPWM_TZ_SIGNAL_DCAEVT2    - DCAEVT2 Cycle By Cycle
 *   - EPWM_TZ_SIGNAL_DCBEVT2    - DCBEVT2 Cycle By Cycle
 *   - EPWM_TZ_SIGNAL_OSHT1      - One-shot TZ1
 *   - EPWM_TZ_SIGNAL_OSHT2      - One-shot TZ2
 *   - EPWM_TZ_SIGNAL_OSHT3      - One-shot TZ3
 *   - EPWM_TZ_SIGNAL_OSHT4      - One-shot TZ4
 *   - EPWM_TZ_SIGNAL_OSHT5      - One-shot TZ5
 *   - EPWM_TZ_SIGNAL_OSHT6      - One-shot TZ6
 *   - EPWM_TZ_SIGNAL_DCAEVT1    - One-shot DCAEVT1
 *   - EPWM_TZ_SIGNAL_DCBEVT1    - One-shot DCBEVT1
 *
 * \b note:  A logical OR of the valid values can be passed as the tzSignal
 *           parameter.
 *
 */
static inline void
EPWM_disableTripZoneSignals(EPWM_REGS_Type *base, uint16_t tzSignal)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Clear the trip zone bits */
    base->TZSEL &= ~tzSignal;
}

/*!
 * Set Digital compare conditions that cause Trip Zone event.
 *
 * \param base is the base address of the EPWM module.
 * \param dcType is the Digital compare output type.
 * \param dcEvent is the Digital Compare output event.
 *
 * This function sets up the Digital Compare output Trip Zone event sources.
 * The dcType variable specifies the event source to be whether Digital
 * Compare output A or Digital Compare output B. The dcEvent parameter
 * specifies the event that causes Trip Zone.
 * Valid values for the parameters are:
 *  - dcType
 *      - EPWM_TZ_DC_OUTPUT_A1     - Digital Compare output 1 A
 *      - EPWM_TZ_DC_OUTPUT_A2     - Digital Compare output 2 A
 *      - EPWM_TZ_DC_OUTPUT_B1     - Digital Compare output 1 B
 *      - EPWM_TZ_DC_OUTPUT_B2     - Digital Compare output 2 B
 *  - dcEvent
 *      - EPWM_TZ_EVENT_DC_DISABLED         - Event Trigger is disabled
 *      - EPWM_TZ_EVENT_DCXH_LOW            - Trigger event when DCxH low
 *      - EPWM_TZ_EVENT_DCXH_HIGH           - Trigger event when DCxH high
 *      - EPWM_TZ_EVENT_DCXL_LOW            - Trigger event when DCxL low
 *      - EPWM_TZ_EVENT_DCXL_HIGH           - Trigger event when DCxL high
 *      - EPWM_TZ_EVENT_DCXL_HIGH_DCXH_LOW  - Trigger event when DCxL high
 *                                            DCxH low
 *
 *  \note x in DCxH/DCxL represents DCAH/DCAL or DCBH/DCBL
 *
 */
static inline void
EPWM_setTripZoneDigitalCompareEventCondition(EPWM_REGS_Type *base,
                                 EPWM_TripZoneDigitalCompareOutput dcType,
                                 EPWM_TripZoneDigitalCompareOutputEvent dcEvent)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Set Digital Compare Events conditions that cause a Digital Compare trip */
    base->TZDCSEL = (base->TZDCSEL & ~(0x7U << (uint16_t)dcType)) |
                        ((uint16_t)dcEvent << (uint16_t)dcType);
}

/*!
 * Enable advanced Trip Zone event Action.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function enables the advanced actions of the Trip Zone events. The
 * advanced features combine the trip zone events with the direction of the
 * counter.
 *
 */
static inline void
EPWM_enableTripZoneAdvAction(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Enable Advanced feature. Set ETZE bit */
    base->TZCTL2 |= EPWM_REGS_TZCTL2_ETZE_Set(1);
}

/*!
 * Disable advanced Trip Zone event Action.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function disables the advanced actions of the Trip Zone events.
 *
 */
static inline void
EPWM_disableTripZoneAdvAction(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Disable Advanced feature. clear ETZE bit */
    base->TZCTL2 = (base->TZCTL2 & ~EPWM_REGS_TZCTL2_ETZE_Msk) |
                        EPWM_REGS_TZCTL2_ETZE_Set(0);
}

/*!
 * Set Trip Zone Action.
 *
 * \param base is the base address of the EPWM module.
 * \param tzEvent is the Trip Zone event type.
 * \param tzAction is the Trip zone Action.
 *
 * This function sets the Trip Zone Action to be taken when a Trip Zone event
 * occurs.
 * Valid values for the parameters are:
 *  - tzEvent
 *      - EPWM_TZ_ACTION_EVENT_DCBEVT2  - DCBEVT2 (Digital Compare B event 2)
 *      - EPWM_TZ_ACTION_EVENT_DCBEVT1  - DCBEVT1 (Digital Compare B event 1)
 *      - EPWM_TZ_ACTION_EVENT_DCAEVT2  - DCAEVT2 (Digital Compare A event 2)
 *      - EPWM_TZ_ACTION_EVENT_DCAEVT1  - DCAEVT1 (Digital Compare A event 1)
 *      - EPWM_TZ_ACTION_EVENT_TZB      - TZ1 - TZ6, DCBEVT2, DCBEVT1
 *      - EPWM_TZ_ACTION_EVENT_TZA      - TZ1 - TZ6, DCAEVT2, DCAEVT1
 *  - tzAction
 *      - EPWM_TZ_ACTION_HIGH_Z         - high impedance output
 *      - EPWM_TZ_ACTION_HIGH           - high output
 *      - EPWM_TZ_ACTION_LOW            - low low
 *      - EPWM_TZ_ACTION_DISABLE        - disable action
 *
 * \note Disable the advanced Trip Zone event using
 *       EPWM_disableTripZoneAdvAction()  before calling this function.
 * \note This function operates on both ePWMA and ePWMB depending on the
 *       tzEvent parameter.
 *
 */
static inline void
EPWM_setTripZoneAction(EPWM_REGS_Type *base, EPWM_TripZoneEvent tzEvent,
                       EPWM_TripZoneAction tzAction)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Set the Action for Trip Zone events */
    base->TZCTL = (base->TZCTL & ~(0x3U << (uint16_t)tzEvent)) |
                        ((uint16_t)tzAction << (uint16_t)tzEvent);
}

/*!
 * Set Advanced Trip Zone Action.
 *
 * \param base is the base address of the EPWM module.
 * \param tzAdvEvent is the Trip Zone event type.
 * \param tzAdvAction is the Trip zone Action.
 *
 * This function sets the Advanced Trip Zone Action to be taken when an
 * advanced Trip Zone event occurs.
 *
 * Valid values for the parameters are:
 *  - tzAdvEvent
 *      - EPWM_TZ_ADV_ACTION_EVENT_TZB_D  - TZ1 - TZ6, DCBEVT2, DCBEVT1 while
 *                                             counting down
 *      - EPWM_TZ_ADV_ACTION_EVENT_TZB_U  - TZ1 - TZ6, DCBEVT2, DCBEVT1 while
 *                                             counting up
 *      - EPWM_TZ_ADV_ACTION_EVENT_TZA_D  - TZ1 - TZ6, DCAEVT2, DCAEVT1 while
 *                                             counting down
 *      - EPWM_TZ_ADV_ACTION_EVENT_TZA_U  - TZ1 - TZ6, DCAEVT2, DCAEVT1 while
 *                                             counting up
 *  - tzAdvAction
 *      - EPWM_TZ_ADV_ACTION_HIGH_Z    - high impedance output
 *      - EPWM_TZ_ADV_ACTION_HIGH      - high voltage state
 *      - EPWM_TZ_ADV_ACTION_LOW       - low voltage state
 *      - EPWM_TZ_ADV_ACTION_TOGGLE    - Toggle output
 *      - EPWM_TZ_ADV_ACTION_DISABLE   - disable action
 *
 * \note This function enables the advanced Trip Zone event.
 *
 * \note This function operates on both ePWMA and ePWMB depending on the
 *       tzAdvEvent  parameter.
 * \note Advanced Trip Zone events take into consideration the direction of
 *       the counter in addition to Trip Zone events.
 *
 */
static inline void
EPWM_setTripZoneAdvAction(EPWM_REGS_Type *base, EPWM_TripZoneAdvancedEvent tzAdvEvent,
                          EPWM_TripZoneAdvancedAction tzAdvAction)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Set the Advanced Action for Trip Zone events */
    base->TZCTL2 = (base->TZCTL2 & ~(0x7U << (uint16_t)tzAdvEvent)) |
                        ((uint16_t)tzAdvAction << (uint16_t)tzAdvEvent) |
                        EPWM_REGS_TZCTL2_ETZE_Set(1);
}

/*!
 * Set Advanced Digital Compare Trip Zone Action on ePWMA.
 *
 * \param base is the base address of the EPWM module.
 * \param tzAdvDCEvent is the Digital Compare Trip Zone event type.
 * \param tzAdvDCAction is the Digital Compare Trip zone Action.
 *
 * This function sets the Digital Compare (DC) Advanced Trip Zone Action to be
 * taken on ePWMA when an advanced Digital Compare Trip Zone A event occurs.
 * Valid values for the parameters are:
 *  - tzAdvDCEvent
 *      - EPWM_TZ_ADV_ACTION_EVENT_DCxEVT2_D  - Digital Compare event A2 while
 *                                                 counting down
 *      - EPWM_TZ_ADV_ACTION_EVENT_DCxEVT2_U  - Digital Compare event A2 while
 *                                                 counting up
 *      - EPWM_TZ_ADV_ACTION_EVENT_DCxEVT1_D  - Digital Compare event A1 while
 *                                                 counting down
 *      - EPWM_TZ_ADV_ACTION_EVENT_DCxEVT1_U  - Digital Compare event A1 while
 *                                                 counting up
 *  - tzAdvDCAction
 *      - EPWM_TZ_ADV_ACTION_HIGH_Z    - high impedance output
 *      - EPWM_TZ_ADV_ACTION_HIGH      - high voltage state
 *      - EPWM_TZ_ADV_ACTION_LOW       - low voltage state
 *      - EPWM_TZ_ADV_ACTION_TOGGLE    - Toggle output
 *      - EPWM_TZ_ADV_ACTION_DISABLE   - disable action
 *
 * \note This function enables the advanced Trip Zone event.
 *
 * \note Advanced Trip Zone events take into consideration the direction of
 *       the counter in addition to Digital Compare Trip Zone events.
 *
 */
static inline void
EPWM_setTripZoneAdvDigitalCompareActionA(EPWM_REGS_Type *base,
                              EPWM_TripZoneAdvDigitalCompareEvent tzAdvDCEvent,
                              EPWM_TripZoneAdvancedAction tzAdvDCAction)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Set the Advanced Action for Trip Zone events */
    base->TZCTLDCA = (base->TZCTLDCA & ~(0x7U << (uint16_t)tzAdvDCEvent)) |
                        ((uint16_t)tzAdvDCAction << (uint16_t)tzAdvDCEvent);
    base->TZCTL2 |= EPWM_REGS_TZCTL2_ETZE_Set(1);
}

/*!
 * Set Advanced Digital Compare Trip Zone Action on ePWMB.
 *
 * \param base is the base address of the EPWM module.
 * \param tzAdvDCEvent is the Digital Compare Trip Zone event type.
 * \param tzAdvDCAction is the Digital Compare Trip zone Action.
 *
 * This function sets the Digital Compare (DC) Advanced Trip Zone Action to be
 * taken on ePWMB when an advanced Digital Compare Trip Zone B event occurs.
 * Valid values for the parameters are:
 *  - tzAdvDCEvent
 *      - EPWM_TZ_ADV_ACTION_EVENT_DCxEVT2_D  - Digital Compare event B2 while
 *                                                 counting down
 *      - EPWM_TZ_ADV_ACTION_EVENT_DCxEVT2_U  - Digital Compare event B2 while
 *                                                 counting up
 *      - EPWM_TZ_ADV_ACTION_EVENT_DCxEVT1_D  - Digital Compare event B1 while
 *                                                 counting down
 *      - EPWM_TZ_ADV_ACTION_EVENT_DCxEVT1_U  - Digital Compare event B1 while
 *                                                 counting up
 *  - tzAdvDCAction
 *      - EPWM_TZ_ADV_ACTION_HIGH_Z    - high impedance output
 *      - EPWM_TZ_ADV_ACTION_HIGH      - high voltage state
 *      - EPWM_TZ_ADV_ACTION_LOW       - low voltage state
 *      - EPWM_TZ_ADV_ACTION_TOGGLE    - Toggle output
 *      - EPWM_TZ_ADV_ACTION_DISABLE   - disable action
 *
 * \note This function enables the advanced Trip Zone event.
 *
 * \note Advanced Trip Zone events take into consideration the direction of
 *       the counter in addition to Digital Compare Trip Zone events.
 *
 */
static inline void EPWM_setTripZoneAdvDigitalCompareActionB(EPWM_REGS_Type *base,
                            EPWM_TripZoneAdvDigitalCompareEvent tzAdvDCEvent,
                            EPWM_TripZoneAdvancedAction tzAdvDCAction)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Set the Advanced Action for Trip Zone events */
    base->TZCTLDCB = (base->TZCTLDCB & ~(0x7U << (uint16_t)tzAdvDCEvent)) | 
                        ((uint16_t)tzAdvDCAction << (uint16_t)tzAdvDCEvent);
    base->TZCTL2 |= EPWM_REGS_TZCTL2_ETZE_Set(1);
}

/*!
 * Enable Trip Zone interrupts.
 *
 * \param base is the base address of the EPWM module.
 * \param tzInterrupt is the Trip Zone interrupt.
 *
 * This function enables the Trip Zone interrupts.
 * Valid values for tzInterrupt are:
 *   - EPWM_TZ_INTERRUPT_CBC     - Trip Zones Cycle By Cycle interrupt
 *   - EPWM_TZ_INTERRUPT_OST     - Trip Zones One Shot interrupt
 *   - EPWM_TZ_INTERRUPT_DCAEVT1 - Digital Compare A Event 1 interrupt
 *   - EPWM_TZ_INTERRUPT_DCAEVT2 - Digital Compare A Event 2 interrupt
 *   - EPWM_TZ_INTERRUPT_DCBEVT1 - Digital Compare B Event 1 interrupt
 *   - EPWM_TZ_INTERRUPT_DCBEVT2 - Digital Compare B Event 2 interrupt
 *
 * \b note:  A logical OR of the valid values can be passed as the tzInterrupt
 *           parameter.
 *
 */
static inline void
EPWM_enableTripZoneInterrupt(EPWM_REGS_Type *base, uint16_t tzInterrupt)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));
    assert((tzInterrupt > 0U) && (tzInterrupt < 0x80U));

    /* Enable Trip zone interrupts */
    base->TZEINT |= tzInterrupt;
}

/*!
 * Disable Trip Zone interrupts.
 *
 * \param base is the base address of the EPWM module.
 * \param tzInterrupt is the Trip Zone interrupt.
 *
 * This function disables the Trip Zone interrupts.
 * Valid values for tzInterrupt are:
 *   - EPWM_TZ_INTERRUPT_CBC     - Trip Zones Cycle By Cycle interrupt
 *   - EPWM_TZ_INTERRUPT_OST    - Trip Zones One Shot interrupt
 *   - EPWM_TZ_INTERRUPT_DCAEVT1 - Digital Compare A Event 1 interrupt
 *   - EPWM_TZ_INTERRUPT_DCAEVT2 - Digital Compare A Event 2 interrupt
 *   - EPWM_TZ_INTERRUPT_DCBEVT1 - Digital Compare B Event 1 interrupt
 *   - EPWM_TZ_INTERRUPT_DCBEVT2 - Digital Compare B Event 2 interrupt
 *
 * \b note:  A logical OR of the valid values can be passed as the tzInterrupt
 *           parameter.
 *
 */
static inline void
EPWM_disableTripZoneInterrupt(EPWM_REGS_Type *base, uint16_t tzInterrupt)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));
    assert((tzInterrupt > 0U) && (tzInterrupt < 0x80U));

    /* Disable Trip zone interrupts */
    base->TZEINT &= ~tzInterrupt;
}

/*!
 * Gets the Trip Zone status flag
 *
 * \param base is the base address of the EPWM module.
 *
 * This function returns the Trip Zone status flag.
 *
 * \return The function returns the following or the bitwise OR value
 *         of the following values.
 *         - EPWM_TZ_INTERRUPT    - Trip Zone interrupt was generated
 *                                  due to the following TZ events.
 *         - EPWM_TZ_FLAG_CBC     - Trip Zones Cycle By Cycle event status flag
 *         - EPWM_TZ_FLAG_OST     - Trip Zones One Shot event status flag
 *         - EPWM_TZ_FLAG_DCAEVT1 - Digital Compare A Event 1 status flag
 *         - EPWM_TZ_FLAG_DCAEVT2 - Digital Compare A Event 2 status flag
 *         - EPWM_TZ_FLAG_DCBEVT1 - Digital Compare B Event 1 status flag
 *         - EPWM_TZ_FLAG_DCBEVT2 - Digital Compare B Event 2 status flag
 */
static inline uint16_t
EPWM_getTripZoneFlagStatus(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Return the Trip zone flag status */
    return (base->TZFLG & 0x7FU);
}

/*!
 * Gets the Trip Zone Cycle by Cycle flag status
 *
 * \param base is the base address of the EPWM module.
 *
 * This function returns the specific Cycle by Cycle Trip Zone flag
 * status.
 *
 * \return The function returns the following values.
 *           - EPWM_TZ_CBC_FLAG_1     - CBC 1 status flag
 *           - EPWM_TZ_CBC_FLAG_2     - CBC 2 status flag
 *           - EPWM_TZ_CBC_FLAG_3     - CBC 3 status flag
 *           - EPWM_TZ_CBC_FLAG_4     - CBC 4 status flag
 *           - EPWM_TZ_CBC_FLAG_5     - CBC 5 status flag
 *           - EPWM_TZ_CBC_FLAG_6     - CBC 6 status flag
 *           - EPWM_TZ_CBC_FLAG_DCAEVT2  - CBC status flag for Digital compare
 *                                                event A2
 *           - EPWM_TZ_CBC_FLAG_DCBEVT2  - CBC status flag for Digital compare
 *                                                event B2
 */
static inline uint16_t
EPWM_getCycleByCycleTripZoneFlagStatus(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Return the Cycle By Cycle Trip zone flag status */
    return (base->TZCBCFLG & 0xFFU);
}

/*!
 * Gets the Trip Zone One Shot flag status
 *
 * \param base is the base address of the EPWM module.
 *
 * This function returns the specific One Shot Trip Zone flag status.
 *
 * \return The function returns the bitwise OR of the following flags.
 *           - EPWM_TZ_OST_FLAG_OST1     - OST status flag for OST1
 *           - EPWM_TZ_OST_FLAG_OST2     - OST status flag for OST2
 *           - EPWM_TZ_OST_FLAG_OST3     - OST status flag for OST3
 *           - EPWM_TZ_OST_FLAG_OST4     - OST status flag for OST4
 *           - EPWM_TZ_OST_FLAG_OST5     - OST status flag for OST5
 *           - EPWM_TZ_OST_FLAG_OST6     - OST status flag for OST6
 *           - EPWM_TZ_OST_FLAG_DCAEVT1  - OST status flag for Digital
 *                                                 compare event A1
 *           - EPWM_TZ_OST_FLAG_DCBEVT1  - OST status flag for Digital
 *                                                 compare event B1
 */
static inline uint16_t
EPWM_getOneShotTripZoneFlagStatus(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Return the One Shot Trip zone flag status */
    return (base->TZOSTFLG & 0xFFU);
}

/*!
 * Set the Trip Zone CBC pulse clear event.
 *
 * \param base is the base address of the EPWM module.
 * \param clearEvent is the CBC trip zone clear event.
 *
 * This function set the event which automatically clears the
 * CBC (Cycle by Cycle) latch.
 * Valid values for clearEvent are:
 *   - EPWM_TZ_CBC_PULSE_CLR_CNTR_ZERO         - Clear CBC pulse when counter
 *                                                  equals zero
 *   - EPWM_TZ_CBC_PULSE_CLR_CNTR_PERIOD       - Clear CBC pulse when counter
 *                                                  equals period
 *   - EPWM_TZ_CBC_PULSE_CLR_CNTR_ZERO_PERIOD  - Clear CBC pulse when counter
 *                                                  equals zero or period
 */
static inline void
EPWM_selectCycleByCycleTripZoneClearEvent(EPWM_REGS_Type *base,
                                 EPWM_CycleByCycleTripZoneClearMode clearEvent)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Set the Cycle by Cycle Trip Latch mode */
    base->TZCLR = (base->TZCLR & ~EPWM_REGS_TZCLR_CBCPULSE_Msk) |
                    EPWM_REGS_TZCLR_CBCPULSE_Set(clearEvent);
}

/*!
 * Clear Trip Zone flag
 *
 * \param base is the base address of the EPWM module.
 * \param tzFlags is the Trip Zone flags.
 *
 * This function clears the Trip Zone flags
 * Valid values for tzFlags are:
 *   - EPWM_TZ_INTERRUPT    - Global Trip Zone interrupt flag
 *   - EPWM_TZ_FLAG_CBC     - Trip Zones Cycle By Cycle flag
 *   - EPWM_TZ_FLAG_OST     - Trip Zones One Shot flag
 *   - EPWM_TZ_FLAG_DCAEVT1 - Digital Compare A Event 1 flag
 *   - EPWM_TZ_FLAG_DCAEVT2 - Digital Compare A Event 2 flag
 *   - EPWM_TZ_FLAG_DCBEVT1 - Digital Compare B Event 1 flag
 *   - EPWM_TZ_FLAG_DCBEVT2 - Digital Compare B Event 2 flag
 *
 * \b note: A bitwise OR of the valid values can be passed as the tzFlags
 * parameter.
 *
 */
static inline void
EPWM_clearTripZoneFlag(EPWM_REGS_Type *base, uint16_t tzFlags)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));
    assert(tzFlags < 0x80U);

    /* Clear Trip zone event flag */
    base->TZCLR |= tzFlags;
}

/*!
 * Clear the Trip Zone Cycle by Cycle flag.
 *
 * \param base is the base address of the EPWM module.
 * \param tzCBCFlags is the CBC flag to be cleared.
 *
 * This function clears the specific Cycle by Cycle Trip Zone flag.
 * The following are valid values for tzCBCFlags.
 *   - EPWM_TZ_CBC_FLAG_1     - CBC 1 flag
 *   - EPWM_TZ_CBC_FLAG_2     - CBC 2 flag
 *   - EPWM_TZ_CBC_FLAG_3     - CBC 3 flag
 *   - EPWM_TZ_CBC_FLAG_4     - CBC 4 flag
 *   - EPWM_TZ_CBC_FLAG_5     - CBC 5 flag
 *   - EPWM_TZ_CBC_FLAG_6     - CBC 6 flag
 *   - EPWM_TZ_CBC_FLAG_DCAEVT2  - CBC flag Digital compare
 *                                         event A2
 *   - EPWM_TZ_CBC_FLAG_DCBEVT2  - CBC flag Digital compare
 *                                         event B2
 */
static inline void
EPWM_clearCycleByCycleTripZoneFlag(EPWM_REGS_Type *base, uint16_t tzCBCFlags)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));
    assert(tzCBCFlags < 0x800U);

    /* Clear the Cycle By Cycle Trip zone flag */
    base->TZCBCCLR |= tzCBCFlags;
}

/*!
 * Clear the Trip Zone One Shot flag.
 *
 * \param base is the base address of the EPWM module.
 * \param tzOSTFlags is the OST flags to be cleared.
 *
 * This function clears the specific One Shot (OST) Trip Zone flag.
 * The following are valid values for tzOSTFlags.
 *  - EPWM_TZ_OST_FLAG_OST1      - OST flag for OST1
 *  - EPWM_TZ_OST_FLAG_OST2      - OST flag for OST2
 *  - EPWM_TZ_OST_FLAG_OST3      - OST flag for OST3
 *  - EPWM_TZ_OST_FLAG_OST4      - OST flag for OST4
 *  - EPWM_TZ_OST_FLAG_OST5      - OST flag for OST5
 *  - EPWM_TZ_OST_FLAG_OST6      - OST flag for OST6
 *  - EPWM_TZ_OST_FLAG_DCAEVT1   - OST flag for Digital compare event A1
 *  - EPWM_TZ_OST_FLAG_DCBEVT1   - OST flag for Digital compare event B1
 *
 */
static inline void
EPWM_clearOneShotTripZoneFlag(EPWM_REGS_Type *base, uint16_t tzOSTFlags)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));
    assert(tzOSTFlags < 0x800U);

    /* Clear the Cycle By Cycle Trip zone flag */
    base->TZOSTCLR |= tzOSTFlags;
}

/*!
 * Force Trip Zone events.
 *
 * \param base is the base address of the EPWM module.
 * \param tzForceEvent is the forced Trip Zone event.
 *
 * This function forces a Trip Zone event.
 * Valid values for tzForceEvent are:
 *   - EPWM_TZ_FORCE_EVENT_CBC     - Force Trip Zones Cycle By Cycle event
 *   - EPWM_TZ_FORCE_EVENT_OST     - Force Trip Zones One Shot Event
 *   - EPWM_TZ_FORCE_EVENT_DCAEVT1 - Force Digital Compare A Event 1
 *   - EPWM_TZ_FORCE_EVENT_DCAEVT2 - Force Digital Compare A Event 2
 *   - EPWM_TZ_FORCE_EVENT_DCBEVT1 - Force Digital Compare B Event 1
 *   - EPWM_TZ_FORCE_EVENT_DCBEVT2 - Force Digital Compare B Event 2
 *
 */
static inline void
EPWM_forceTripZoneEvent(EPWM_REGS_Type *base, uint16_t tzForceEvent)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));
    assert((tzForceEvent & 0xFF81U) == 0U);

    /* Force a Trip Zone event */
    base->TZFRC |= tzForceEvent;
}

/*!
 * Enable ePWM interrupt.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function enables the ePWM interrupt.
 *
 */
static inline void
EPWM_enableInterrupt(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Enable ePWM interrupt */
    base->ETSEL |= EPWM_REGS_ETSEL_INTEN_Set(1); 
}

/*!
 * disable ePWM interrupt.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function disables the ePWM interrupt.
 *
 */
static inline void
EPWM_disableInterrupt(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Disable ePWM interrupt */
    base->ETSEL &= ~EPWM_REGS_ETSEL_INTEN_Set(1); 
}

/*!
 * Sets the ePWM interrupt source.
 *
 * \param base is the base address of the EPWM module.
 * \param interruptSource is the ePWM interrupt source.
 *
 * This function sets the ePWM interrupt source.
 * Valid values for interruptSource are:
 *   - EPWM_INT_TBCTR_DISABLED       - Time-base counter is disabled
 *   - EPWM_INT_TBCTR_ZERO           - Time-base counter equal to zero
 *   - EPWM_INT_TBCTR_PERIOD         - Time-base counter equal to period
 *   - EPWM_INT_TBCTR_ZERO_OR_PERIOD - Time-base counter equal to zero or
 *                                     period
 *   - EPWM_INT_TBCTR_U_CMPx         - Where x is A,B,C or D
 *                                     Time-base counter equal to CMPA, CMPB,
 *                                     CMPC or CMPD (depending the value of x)
 *                                     when the timer is incrementing
 *   - EPWM_INT_TBCTR_D_CMPx         - Where x is A,B,C or D
 *                                     Time-base counter equal to CMPA, CMPB,
 *                                     CMPC or CMPD (depending the value of x)
 *                                     when the timer is decrementing
 *
 */
static inline void
EPWM_setInterruptSource(EPWM_REGS_Type *base, uint16_t interruptSource)
{
    uint16_t intSource;

    /* Check the arguments */
    assert(EPWM_isBaseValid(base));
    assert(((interruptSource > 0U) && (interruptSource < 9U)) || (interruptSource == 10U) || (interruptSource == 12U) ||
           (interruptSource == 14U));

    if((interruptSource == EPWM_INT_TBCTR_U_CMPC) ||
       (interruptSource == EPWM_INT_TBCTR_U_CMPD) ||
       (interruptSource == EPWM_INT_TBCTR_D_CMPC) ||
       (interruptSource == EPWM_INT_TBCTR_D_CMPD))
    {
        /* Shift the interrupt source by 1 */
        intSource = interruptSource >> 1U;

        /* Enable events based on comp C or comp D */
        base->ETSEL |= EPWM_REGS_ETSEL_INTSELCMP_Set(1);
    }
    else if((interruptSource == EPWM_INT_TBCTR_U_CMPA) ||
            (interruptSource == EPWM_INT_TBCTR_U_CMPB) ||
            (interruptSource == EPWM_INT_TBCTR_D_CMPA) ||
            (interruptSource == EPWM_INT_TBCTR_D_CMPB))
    {
        intSource = interruptSource;

        /* Enable events based on comp A or comp B */
        base->ETSEL &= ~EPWM_REGS_ETSEL_INTSELCMP_Set(1);
    }
    else
    {
        intSource = interruptSource;
    }

    /* Set the interrupt source */
    base->ETSEL = (base->ETSEL & ~EPWM_REGS_ETSEL_INTSEL_Msk) |
                        EPWM_REGS_ETSEL_INTSEL_Set(intSource);
}

/*!
 * Sets the ePWM interrupt event counts.
 *
 * \param base is the base address of the EPWM module.
 * \param eventCount is the event count for interrupt scale
 *
 * This function sets the interrupt event count that determines the number of
 * events that have to occur before an interrupt is issued.
 * Maximum value for eventCount is 15.
 *
 */
static inline void
EPWM_setInterruptEventCount(EPWM_REGS_Type *base, uint16_t eventCount)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));
    assert(eventCount < 16U);

    /* Enable advanced feature of interrupt every up to 15 events */
    base->ETPS |= EPWM_REGS_ETPS_INTPSSEL_Set(1);
    base->ETINTPS = (base->ETINTPS & ~EPWM_REGS_ETINTPS_INTPRD2_Msk) |
                        EPWM_REGS_ETINTPS_INTPRD2_Set(eventCount);
}

/*!
 * Return the interrupt status.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function returns the ePWM interrupt status.
 * \b Note This function doesn't return the Trip Zone status.
 *
 * \return Returns true if ePWM interrupt was generated.
 *         Returns false if no interrupt was generated
 */
static inline bool
EPWM_getEventTriggerInterruptStatus(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Return INT bit of ETFLG register */
    return (((base->ETFLG & 0x1U) == 0x1U) ? true : false);
}

/*!
 * Clear interrupt flag.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function clears the ePWM interrupt flag.
 *
 */
static inline void
EPWM_clearEventTriggerInterruptFlag(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Clear INT bit of ETCLR register */
    base->ETCLR |= EPWM_REGS_ETCLR_ETINT_Set(1);
}

/*!
 * Enable Pre-interrupt count load.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function enables the ePWM interrupt counter to be pre-interrupt loaded
 * with a count value.
 *
 * \note This is valid only for advanced/expanded interrupt mode
 *
 */
static inline void
EPWM_enableInterruptEventCountInit(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Enable interrupt event count initializing/loading */
    base->ETCNTINITCTL |= EPWM_REGS_ETCNTINITCTL_INTINITEN_Set(1);
}

/*!
 * Disable interrupt count load.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function disables the ePWM interrupt counter from being loaded with
 * pre-interrupt count value.
 *
 *  
 */
static inline void
EPWM_disableInterruptEventCountInit(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Disable interrupt event count initializing/loading */
    base->ETCNTINITCTL &= ~EPWM_REGS_ETCNTINITCTL_INTINITEN_Set(1);
}

/*!
 * Force a software pre interrupt event counter load.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function forces the ePWM interrupt counter to be loaded with the
 * contents set by EPWM_setPreInterruptEventCount().
 *
 * \note make sure the EPWM_enablePreInterruptEventCountLoad() function is
 *       is called before invoking this function.
 *
 */
static inline void
EPWM_forceInterruptEventCountInit(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Load the Interrupt Event counter value */
    base->ETCNTINITCTL |= EPWM_REGS_ETCNTINITCTL_INTINITFRC_Set(1);
}

/*!
 * Set interrupt count.
 *
 * \param base is the base address of the EPWM module.
 * \param eventCount is the ePWM interrupt count value.
 *
 * This function sets the ePWM interrupt count. eventCount is the value of the
 * pre-interrupt value that is to be loaded. The maximum value of eventCount
 * is 15.
 *
 */
static inline void
EPWM_setInterruptEventCountInitValue(EPWM_REGS_Type *base, uint16_t eventCount)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));
    assert(eventCount < 16U);

    /* Set the Pre-interrupt event count */
    base->ETCNTINIT = (base->ETCNTINIT & ~EPWM_REGS_ETCNTINIT_INTINIT_Msk) |
                        EPWM_REGS_ETCNTINIT_INTINIT_Set(eventCount & 0xFU);
}

/*!
 * Get the interrupt count.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function returns the ePWM interrupt event count.
 *
 * \return The interrupt event counts that have occurred.
 */
static inline uint16_t
EPWM_getInterruptEventCount(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Return the interrupt event count */
    return (EPWM_REGS_ETINTPS_INTCNT2_Get(base->ETINTPS));
}

/*!
 * Force ePWM interrupt.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function forces an ePWM interrupt.
 *
 */
static inline void
EPWM_forceEventTriggerInterrupt(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Set INT bit of ETFRC register */
    base->ETFRC |= EPWM_REGS_ETFRC_ETINT_Set(1);
}

/*!
 * Enable ADC SOC event.
 *
 * \param base is the base address of the EPWM module.
 * \param adcSOCType is the ADC SOC type.
 *
 * This function enables the ePWM module to trigger an ADC SOC event.
 * Valid values for adcSOCType are:
 *   - EPWM_SOC_A  - SOC A
 *   - EPWM_SOC_B  - SOC B
 *
 */
static inline void
EPWM_enableADCTrigger(EPWM_REGS_Type *base, EPWM_ADCStartOfConversionType adcSOCType)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Enable an SOC */
   if(adcSOCType == EPWM_SOC_A)
   {
        base->ETSEL |= EPWM_REGS_ETSEL_SOCAEN_Set(1);
   }
   else
   {
        base->ETSEL |= EPWM_REGS_ETSEL_SOCBEN_Set(1);
   }
}

/*!
 * Disable ADC SOC event.
 *
 * \param base is the base address of the EPWM module.
 * \param adcSOCType is the ADC SOC type.
 *
 * This function disables the ePWM module from triggering an ADC SOC event.
 * Valid values for adcSOCType are:
 *   - EPWM_SOC_A  - SOC A
 *   - EPWM_SOC_B  - SOC B
 *
 */
static inline void
EPWM_disableADCTrigger(EPWM_REGS_Type *base, EPWM_ADCStartOfConversionType adcSOCType)
{
    /* Check the arguments */
   assert(EPWM_isBaseValid(base));

   /* Disable an SOC */
   if(adcSOCType == EPWM_SOC_A)
   {
        base->ETSEL &= ~EPWM_REGS_ETSEL_SOCAEN_Set(1);
   }
   else
   {
        base->ETSEL &= ~EPWM_REGS_ETSEL_SOCBEN_Set(1);
   }
}

/*!
 * Sets the ePWM SOC source.
 *
 * \param base is the base address of the EPWM module.
 * \param adcSOCType is the ADC SOC type.
 * \param socSource is the SOC source.
 *
 * This function sets the ePWM ADC SOC source.
 * Valid values for socSource are:
 *  - adcSOCType
 *     - EPWM_SOC_A  - SOC A
 *     - EPWM_SOC_B  - SOC B
 *  - socSource
 *     - EPWM_SOC_DCxEVT1              - Event is based on DCxEVT1
 *     - EPWM_SOC_TBCTR_ZERO           - Time-base counter equal to zero
 *     - EPWM_SOC_TBCTR_PERIOD         - Time-base counter equal to period
 *     - EPWM_SOC_TBCTR_ZERO_OR_PERIOD - Time-base counter equal to zero or
 *                                       period
 *     - EPWM_SOC_TBCTR_U_CMPx         - Where x is A,B,C or D
 *                                       Time-base counter equal to CMPA, CMPB,
 *                                       CMPC or CMPD(depending the value of x)
 *                                       when the timer is incrementing
 *     - EPWM_SOC_TBCTR_D_CMPx         - Where x is A,B,C or D
 *                                       Time-base counter equal to CMPA, CMPB,
 *                                       CMPC or CMPD(depending the value of x)
 *                                       when the timer is decrementing
 *
 */
static inline void
EPWM_setADCTriggerSource(EPWM_REGS_Type *base,
                         EPWM_ADCStartOfConversionType adcSOCType,
                         EPWM_ADCStartOfConversionSource socSource)
{
    uint16_t source;

    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    if((socSource == EPWM_SOC_TBCTR_U_CMPC) ||
       (socSource == EPWM_SOC_TBCTR_U_CMPD) ||
       (socSource == EPWM_SOC_TBCTR_D_CMPC) ||
       (socSource == EPWM_SOC_TBCTR_D_CMPD))
    {
        source = (uint16_t)socSource >> 1U;
    }
    else
    {
        source = (uint16_t)socSource;
    }

    if(adcSOCType == EPWM_SOC_A)
    {
        /* Set the SOC source */
        base->ETSEL = (base->ETSEL & ~EPWM_REGS_ETSEL_SOCASEL_Msk) |
                        EPWM_REGS_ETSEL_SOCASEL_Set(source);

        /* Enable the comparator selection */
        if((socSource == EPWM_SOC_TBCTR_U_CMPA) ||
           (socSource == EPWM_SOC_TBCTR_U_CMPB) ||
           (socSource == EPWM_SOC_TBCTR_D_CMPA) ||
           (socSource == EPWM_SOC_TBCTR_D_CMPB))
        {
            /* Enable events based on comp A or comp B */
            base->ETSEL = (base->ETSEL & ~EPWM_REGS_ETSEL_SOCASELCMP_Msk) |
                            EPWM_REGS_ETSEL_SOCASELCMP_Set(0);
        }
        else if((socSource == EPWM_SOC_TBCTR_U_CMPC) ||
                (socSource == EPWM_SOC_TBCTR_U_CMPD) ||
                (socSource == EPWM_SOC_TBCTR_D_CMPC) ||
                (socSource == EPWM_SOC_TBCTR_D_CMPD))
        {
            /* Enable events based on comp C or comp D */
            base->ETSEL = (base->ETSEL & ~EPWM_REGS_ETSEL_SOCASELCMP_Msk) |
                            EPWM_REGS_ETSEL_SOCASELCMP_Set(1);
        }
        else
        {
            /* No action required for the other socSource options */
        }
    }
    else
    {
        /* Enable the comparator selection */
        base->ETSEL = (base->ETSEL & ~EPWM_REGS_ETSEL_SOCBSEL_Msk) |
                        EPWM_REGS_ETSEL_SOCBSEL_Set(source);

        /* Enable the comparator selection */
        if((socSource == EPWM_SOC_TBCTR_U_CMPA) ||
           (socSource == EPWM_SOC_TBCTR_U_CMPB) ||
           (socSource == EPWM_SOC_TBCTR_D_CMPA) ||
           (socSource == EPWM_SOC_TBCTR_D_CMPB))
        {
            /* Enable events based on comp A or comp B */
            base->ETSEL = (base->ETSEL & ~EPWM_REGS_ETSEL_SOCBSELCMP_Msk) |
                            EPWM_REGS_ETSEL_SOCBSELCMP_Set(0);
        }
        else if((socSource == EPWM_SOC_TBCTR_U_CMPC) ||
                (socSource == EPWM_SOC_TBCTR_U_CMPD) ||
                (socSource == EPWM_SOC_TBCTR_D_CMPC) ||
                (socSource == EPWM_SOC_TBCTR_D_CMPD))
        {
            /* Enable events based on comp C or comp D */
            base->ETSEL = (base->ETSEL & ~EPWM_REGS_ETSEL_SOCBSELCMP_Msk) |
                            EPWM_REGS_ETSEL_SOCBSELCMP_Set(1);
        }
        else
        {
            /* No action required for the other socSource options */
        }
    }
}

/*!
 * Sets the ePWM SOC event counts.
 *
 * \param base is the base address of the EPWM module.
 * \param adcSOCType is the ADC SOC type.
 * \param preScaleCount is the event count number.
 *
 * This function sets the SOC event count that determines the number of
 * events that have to occur before an SOC is issued.
 *  Valid values for the parameters are:
 *   - adcSOCType
 *       - EPWM_SOC_A  - SOC A
 *       - EPWM_SOC_B  - SOC B
 *   - preScaleCount
 *        - [1 - 15]  -  Generate SOC pulse every preScaleCount
 *                       up to 15 events.
 *
 * \note A preScaleCount value of 0 disables the prescale.
 *
 */
static inline void
EPWM_setADCTriggerEventPrescale(EPWM_REGS_Type *base,
                                EPWM_ADCStartOfConversionType adcSOCType,
                                uint16_t preScaleCount)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));
    assert(preScaleCount < 16U);

    /* Enable advanced feature of SOC every up to 15 events */
    base->ETPS |= EPWM_REGS_ETPS_SOCPSSEL_Set(1);
    if(adcSOCType == EPWM_SOC_A)
    {
        /* Set the count for SOC A */
        base->ETSOCPS = (base->ETSOCPS & ~EPWM_REGS_ETSOCPS_SOCAPRD2_Msk) |
                            EPWM_REGS_ETSOCPS_SOCAPRD2_Set(preScaleCount);
    }
    else
    {
        /* Set the count for SOC B */
        base->ETSOCPS = (base->ETSOCPS & ~EPWM_REGS_ETSOCPS_SOCBPRD2_Msk) |
                            EPWM_REGS_ETSOCPS_SOCBPRD2_Set(preScaleCount);
    }
}

/*!
 * Return the SOC event status.
 *
 * \param base is the base address of the EPWM module.
 * \param adcSOCType is the ADC SOC type.
 *
 * This function returns the ePWM SOC status.
 * Valid values for adcSOCType are:
 *   - EPWM_SOC_A  - SOC A
 *   - EPWM_SOC_B  - SOC B
 *
 * \return Returns true if the selected adcSOCType SOC was generated.
 *         Returns false if the selected adcSOCType SOC was not generated.
 */
static inline bool
EPWM_getADCTriggerFlagStatus(EPWM_REGS_Type *base,
                             EPWM_ADCStartOfConversionType adcSOCType)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Return the SOC A/ B status */
    return ((((base->ETFLG >> ((uint16_t)adcSOCType + 2U)) & 0x1U) == 0x1U) ? true : false);
}

/*!
 * Clear SOC flag.
 *
 * \param base is the base address of the EPWM module.
 * \param adcSOCType is the ADC SOC type.
 *
 * This function clears the ePWM SOC flag.
 * Valid values for adcSOCType are:
 *   - EPWM_SOC_A  - SOC A
 *   - EPWM_SOC_B  - SOC B
 *
 */
static inline void
EPWM_clearADCTriggerFlag(EPWM_REGS_Type *base,
                         EPWM_ADCStartOfConversionType adcSOCType)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Clear SOC A/B bit of ETCLR register */
    base->ETCLR |= 1U << ((uint16_t)adcSOCType + 2U);
}

/*!
 * Enable Pre-SOC event count load.
 *
 * \param base is the base address of the EPWM module.
 * \param adcSOCType is the ADC SOC type.
 *
 * This function enables the ePWM SOC event counter which is set by the
 * EPWM_setADCTriggerEventCountInitValue() function to be loaded before
 * an SOC event.
 * Valid values for adcSOCType are:
 *   - EPWM_SOC_A  - SOC A
 *   - EPWM_SOC_B  - SOC B
 *
 * \note This is valid only for advanced/expanded SOC mode
 *
 */
static inline void
EPWM_enableADCTriggerEventCountInit(EPWM_REGS_Type *base,
                                    EPWM_ADCStartOfConversionType adcSOCType)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Enable SOC event count initializing/loading */
    base->ETCNTINITCTL |= 1U << ((uint16_t)adcSOCType + 14U);
}

/*!
 * Disable Pre-SOC event count load.
 *
 * \param base is the base address of the EPWM module.
 * \param adcSOCType is the ADC SOC type.
 *
 * This function disables the ePWM SOC event counter from being loaded before
 * an SOC event (only an SOC event causes an increment of the counter value).
 * Valid values for adcSOCType are:
 *   - EPWM_SOC_A  - SOC A
 *   - EPWM_SOC_B  - SOC B
 *
 * \note This is valid only for advanced/expanded SOC mode
 *
 */
static inline void
EPWM_disableADCTriggerEventCountInit(EPWM_REGS_Type *base,
                                     EPWM_ADCStartOfConversionType adcSOCType)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Disable SOC event count initializing/loading */
    base->ETCNTINITCTL &= ~(1U << ((uint16_t)adcSOCType + 14U));
}

/*!
 * Force a software pre SOC event counter load.
 *
 * \param base is the base address of the EPWM module.
 * \param adcSOCType is the ADC SOC type
 *
 * This function forces the ePWM SOC counter to be loaded with the
 * contents set by EPWM_setPreADCStartOfConversionEventCount().
 *
 * \note make sure the EPWM_enableADCTriggerEventCountInit()
 *       function is called before invoking this function.
 *
 */
static inline void
EPWM_forceADCTriggerEventCountInit(EPWM_REGS_Type *base,
                                   EPWM_ADCStartOfConversionType adcSOCType)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Load the Interrupt Event counter value */
    base->ETCNTINITCTL |= 1U << ((uint16_t)adcSOCType + 11U);
}

/*!
 * Set ADC Trigger count values.
 *
 * \param base is the base address of the EPWM module.
 * \param adcSOCType is the ADC SOC type.
 * \param eventCount is the ePWM interrupt count value.
 *
 * This function sets the ePWM ADC Trigger count values.
 * Valid values for adcSOCType are:
 *   - EPWM_SOC_A  - SOC A
 *   - EPWM_SOC_B  - SOC B
 * The eventCount has a maximum value of 15.
 *
 */
static inline void
EPWM_setADCTriggerEventCountInitValue(EPWM_REGS_Type *base,
                                      EPWM_ADCStartOfConversionType adcSOCType,
                                      uint16_t eventCount)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));
    assert(eventCount < 16U);

    /* Set the ADC Trigger event count */
    if(adcSOCType == EPWM_SOC_A)
    {
        base->ETCNTINIT = (base->ETCNTINIT & ~EPWM_REGS_ETCNTINIT_SOCAINIT_Msk) |
                            EPWM_REGS_ETCNTINIT_SOCAINIT_Set(eventCount);
    }
    else
    {
        base->ETCNTINIT = (base->ETCNTINIT & ~EPWM_REGS_ETCNTINIT_SOCBINIT_Msk) |
                            EPWM_REGS_ETCNTINIT_SOCBINIT_Set(eventCount);
    }
}

/*!
 * Get the SOC event count.
 *
 * \param base is the base address of the EPWM module.
 * \param adcSOCType is the ADC SOC type.
 *
 * This function returns the ePWM SOC event count.
 * Valid values for adcSOCType are:
 *   - EPWM_SOC_A  - SOC A
 *   - EPWM_SOC_B  - SOC B
 *
 * \return The SOC event counts that have occurred.
 */
static inline uint16_t
EPWM_getADCTriggerEventCount(EPWM_REGS_Type *base,
                             EPWM_ADCStartOfConversionType adcSOCType)
{
    uint16_t eventCount;

    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Return the SOC event count */
    if(adcSOCType == EPWM_SOC_A)
    {
        eventCount = EPWM_REGS_ETSOCPS_SOCACNT2_Get(base->ETSOCPS);
    }
    else
    {
        eventCount = EPWM_REGS_ETSOCPS_SOCBCNT2_Get(base->ETSOCPS);
    }

    return(eventCount);
}

/*!
 * Force SOC event.
 *
 * \param base is the base address of the EPWM module.
 * \param adcSOCType is the ADC SOC type.
 *
 * This function forces an ePWM SOC event.
 * Valid values for adcSOCType are:
 *   - EPWM_SOC_A  - SOC A
 *   - EPWM_SOC_B  - SOC B
 *
 */
static inline void
EPWM_forceADCTrigger(EPWM_REGS_Type *base, EPWM_ADCStartOfConversionType adcSOCType)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Set SOC A/B bit of ETFRC register */
    base->ETFRC |= 1U << ((uint16_t)adcSOCType + 2U);
}

/*!
 * Set the DC trip input.
 *
 * \param base is the base address of the EPWM module.
 * \param tripSource is the tripSource.
 * \param dcType is the Digital Compare type.
 *
 * This function sets the trip input to the Digital Compare (DC). For a given
 * dcType the function sets the tripSource to be the input to the DC.
 * Valid values for the parameter are:
 *  - tripSource
 *     - EPWM_DC_TRIP_TRIPINx - Trip x,where x ranges from 1 to 15 excluding 13
 *     - EPWM_DC_TRIP_COMBINATION - selects all the Trip signals whose input
 *                                  is enabled by the following function
 *                              EPWM_enableDigitalCompareTripCombinationInput()
 *  - dcType
 *     - EPWM_DC_TYPE_DCAH  - Digital Compare A High
 *     - EPWM_DC_TYPE_DCAL  - Digital Compare A Low
 *     - EPWM_DC_TYPE_DCBH  - Digital Compare B High
 *     - EPWM_DC_TYPE_DCBL  - Digital Compare B Low
 *
 */
static inline void
EPWM_selectDigitalCompareTripInput(EPWM_REGS_Type *base,
                                   EPWM_DigitalCompareTripInput tripSource,
                                   EPWM_DigitalCompareType dcType)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Set the DC trip input */
    base->DCTRIPSEL = (base->DCTRIPSEL & ~(0xFU << ((uint16_t)dcType << 1U))) |
                        ((uint16_t)tripSource << ((uint16_t)dcType << 1U));
}

/*!
 * Enable DC filter blanking window.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function enables the DC filter blanking window.
 *
 */
static inline void
EPWM_enableDigitalCompareBlankingWindow(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Enable DC filter blanking window */
    base->DCFCTL |= EPWM_REGS_DCFCTL_BLANKE_Set(1);
}

/*!
 * Disable DC filter blanking window.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function disables the DC filter blanking window.
 *
 */
static inline void
EPWM_disableDigitalCompareBlankingWindow(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Disable DC filter blanking window */
    base->DCFCTL &= ~EPWM_REGS_DCFCTL_BLANKE_Set(1);
}

/*!
 * Enable Digital Compare Window inverse mode.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function enables the Digital Compare Window inverse mode. This will
 * invert the blanking window.
 *
 */
static inline void
EPWM_enableDigitalCompareWindowInverseMode(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Enable DC window inverse mode. */
    base->DCFCTL |= EPWM_REGS_DCFCTL_BLANKINV_Set(1);
}

/*!
 * Disable Digital Compare Window inverse mode.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function disables the Digital Compare Window inverse mode.
 *
 */
static inline void
EPWM_disableDigitalCompareWindowInverseMode(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Disable DC window inverse mode. */
    base->DCFCTL &= ~EPWM_REGS_DCFCTL_BLANKINV_Set(1);
}

/*!
 * Set the Digital Compare filter blanking pulse.
 *
 * \param base is the base address of the EPWM module.
 * \param blankingPulse is Pulse that starts blanking window.
 *
 * This function sets the input pulse that starts the Digital Compare blanking
 * window.
 * Valid values for blankingPulse are:
 *   - EPWM_DC_WINDOW_START_TBCTR_PERIOD - Time base counter equals period
 *   - EPWM_DC_WINDOW_START_TBCTR_ZERO   - Time base counter equals zero
 *   - EPWM_DC_WINDOW_START_TBCTR_ZERO_PERIOD - Time base counter equals zero
 *                                              or period.
 *
 */
static inline void
EPWM_setDigitalCompareBlankingEvent(EPWM_REGS_Type *base,
                                EPWM_DigitalCompareBlankingPulse blankingPulse)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Set DC blanking event */
    base->DCFCTL = (base->DCFCTL & ~EPWM_REGS_DCFCTL_PULSESEL_Msk) |
                        EPWM_REGS_DCFCTL_PULSESEL_Set(blankingPulse);
}

/*!
 * Set up the Digital Compare filter input.
 *
 * \param base is the base address of the EPWM module.
 * \param filterInput is Digital Compare signal source.
 *
 * This function sets the signal input source that will be filtered by the
 * Digital Compare module.
 * Valid values for filterInput are:
 *   - EPWM_DC_WINDOW_SOURCE_DCAEVT1  - DC filter signal source is DCAEVT1
 *   - EPWM_DC_WINDOW_SOURCE_DCAEVT2  - DC filter signal source is DCAEVT2
 *   - EPWM_DC_WINDOW_SOURCE_DCBEVT1  - DC filter signal source is DCBEVT1
 *   - EPWM_DC_WINDOW_SOURCE_DCBEVT2  - DC filter signal source is DCBEVT2
 *
 */
static inline void
EPWM_setDigitalCompareFilterInput(EPWM_REGS_Type *base,
                                  EPWM_DigitalCompareFilterInput filterInput)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Set the signal source that will be filtered */
    base->DCFCTL = (base->DCFCTL & ~EPWM_REGS_DCFCTL_SRCSEL_Msk) |
                        EPWM_REGS_DCFCTL_SRCSEL_Set(filterInput);
}

/*!
 * Enable Digital Compare Edge Filter.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function enables the Digital Compare Edge filter to generate event
 * after configured number of edges.
 *
 */
static inline void
EPWM_enableDigitalCompareEdgeFilter(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Enable DC Edge Filter */
    base->DCFCTL |= EPWM_REGS_DCFCTL_EDGEFILTSEL_Set(1);
}

/*!
 * Disable Digital Compare Edge Filter.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function disables the Digital Compare Edge filter.
 *
 */
static inline void
EPWM_disableDigitalCompareEdgeFilter(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Disable DC Edge Filter */
    base->DCFCTL &= ~EPWM_REGS_DCFCTL_EDGEFILTSEL_Set(1);
}

/*!
 * Set the Digital Compare Edge Filter Mode.
 *
 * \param base is the base address of the EPWM module.
 * \param edgeMode is Digital Compare Edge filter mode.
 *
 * This function sets the Digital Compare Event filter mode. Valid values
 * for edgeMode are:
 *   - EPWM_DC_EDGEFILT_MODE_RISING  - DC edge filter mode is rising edge
 *   - EPWM_DC_EDGEFILT_MODE_FALLING - DC edge filter mode is falling edge
 *   - EPWM_DC_EDGEFILT_MODE_BOTH    - DC edge filter mode is both edges
 *
 */
static inline void
EPWM_setDigitalCompareEdgeFilterMode(EPWM_REGS_Type *base,
                                     EPWM_DigitalCompareEdgeFilterMode edgeMode)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Set DC Edge filter mode */
    base->DCFCTL = (base->DCFCTL & ~EPWM_REGS_DCFCTL_EDGEMODE_Msk) |
                        EPWM_REGS_DCFCTL_EDGEMODE_Set(edgeMode);
}

/*!
 * Set the Digital Compare Edge Filter Edge Count.
 *
 * \param base is the base address of the EPWM module.
 * \param edgeCount is Digital Compare event filter count
 *
 * This function sets the Digital Compare Event filter Edge Count to generate
 * events. Valid values for edgeCount can be:
 *  - EPWM_DC_EDGEFILT_EDGECNT_0 - No edge is required to generate event
 *  - EPWM_DC_EDGEFILT_EDGECNT_1 - 1 edge is required for event generation
 *  - EPWM_DC_EDGEFILT_EDGECNT_2 - 2 edges are required for event generation
 *  - EPWM_DC_EDGEFILT_EDGECNT_3 - 3 edges are required for event generation
 *  - EPWM_DC_EDGEFILT_EDGECNT_4 - 4 edges are required for event generation
 *  - EPWM_DC_EDGEFILT_EDGECNT_5 - 5 edges are required for event generation
 *  - EPWM_DC_EDGEFILT_EDGECNT_6 - 6 edges are required for event generation
 *  - EPWM_DC_EDGEFILT_EDGECNT_7 - 7 edges are required for event generation
 *
 */
static inline void
EPWM_setDigitalCompareEdgeFilterEdgeCount(EPWM_REGS_Type *base, uint16_t edgeCount)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Set DC Edge filter edge count */
    base->DCFCTL = (base->DCFCTL & ~EPWM_REGS_DCFCTL_EDGECOUNT_Msk) |
                        EPWM_REGS_DCFCTL_EDGECOUNT_Set(edgeCount);
}

/*!
 * Returns the Digital Compare Edge Filter Edge Count.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function returns the configured Digital Compare Edge filter edge
 * count required to generate events. It can return values from 0-7.
 *
 * \return Returns the configured DigitalCompare Edge filter edge count.
 */
static inline uint16_t
EPWM_getDigitalCompareEdgeFilterEdgeCount(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    //* Return configured DC edge filter edge count */
    return EPWM_REGS_DCFCTL_EDGECOUNT_Get(base->DCFCTL);
}

/*!
 * Returns the Digital Compare Edge filter captured edge count status.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function returns the count of edges captured by Digital Compare Edge
 * filter. It can return values from 0-7.
 *
 * \return Returns the count of captured edges
 */
static inline uint16_t
EPWM_getDigitalCompareEdgeFilterEdgeStatus(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Return captured edge count by DC Edge filter */
    return EPWM_REGS_DCFCTL_EDGESTATUS_Get(base->DCFCTL);
}

/*!
 * Set up the Digital Compare filter window offset
 *
 * \param base is the base address of the EPWM module.
 * \param windowOffsetCount is blanking window offset length.
 *
 * This function sets the offset between window start pulse and blanking
 * window in TBCLK count.
 * The function take a 16bit count value for the offset value.
 *
 */
static inline void
EPWM_setDigitalCompareWindowOffset(EPWM_REGS_Type *base, uint16_t windowOffsetCount)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Set the blanking window offset in TBCLK counts */
    base->DCFOFFSET = EPWM_REGS_DCFOFFSET_DCFOFFSET_Set(windowOffsetCount);
}

/*!
 * Set up the Digital Compare filter window length
 *
 * \param base is the base address of the EPWM module.
 * \param windowLengthCount is blanking window length.
 *
 * This function sets up the Digital Compare filter blanking window length in
 * TBCLK count.The function takes a 16bit count value for the window length.
 *
 */
static inline void
EPWM_setDigitalCompareWindowLength(EPWM_REGS_Type *base, uint16_t windowLengthCount)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Set the blanking window length in TBCLK counts */
    base->DCFWINDOW = EPWM_REGS_DCFWINDOW_DCFWINDOW_Set(windowLengthCount);    
}

/*!
 * Return DC filter blanking window offset count.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function returns DC filter blanking window offset count.
 *
 * \return Returns the count of blanking window offset
 */
static inline uint16_t
EPWM_getDigitalCompareBlankingWindowOffsetCount(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Return the Blanking Window Offset count */
    return EPWM_REGS_DCFOFFSETCNT_DCFOFFSETCNT_Get(base->DCFOFFSETCNT);
}

/*!
 * Return DC filter blanking window length count.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function returns DC filter blanking window length count.
 *
 * \return Returns the count of blanking window length
 */
static inline uint16_t
EPWM_getDigitalCompareBlankingWindowLengthCount(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Return the Blanking Window Length count */
    return EPWM_REGS_DCFWINDOWCNT_DCFWINDOW_Get(base->DCFWINDOWCNT);
}

/*!
 * Set up the Digital Compare Event source.
 *
 * \param base is the base address of the EPWM module.
 * \param dcModule is the Digital Compare module.
 * \param dcEvent is the Digital Compare Event number.
 * \param dcEventSource is the - Digital Compare Event source.
 *
 * This function sets up the Digital Compare module Event sources.
 * The following are valid values for the parameters.
 *  - dcModule
 *      - EPWM_DC_MODULE_A  - Digital Compare Module A
 *      - EPWM_DC_MODULE_B  - Digital Compare Module B
 *  - dcEvent
 *      - EPWM_DC_EVENT_1   - Digital Compare Event number 1
 *      - EPWM_DC_EVENT_2   - Digital Compare Event number 2
 *  - dcEventSource
 *      - EPWM_DC_EVENT_SOURCE_FILT_SIGNAL  - signal source is filtered
 *            \note The signal source for this option is DCxEVTy, where the
 *                  value of x is dependent on dcModule and the value of y is
 *                  dependent on dcEvent. Possible signal sources are DCAEVT1,
 *                  DCBEVT1, DCAEVT2 or DCBEVT2 depending on the value of both
 *                  dcModule and dcEvent.
 *      - EPWM_DC_EVENT_SOURCE_ORIG_SIGNAL  - signal source is unfiltered
 *                   The signal source for this option is DCxEVTy.
 *   
 */
static inline void
EPWM_setDigitalCompareEventSource(EPWM_REGS_Type *base,
                                  EPWM_DigitalCompareModule dcModule,
                                  EPWM_DigitalCompareEvent dcEvent,
                                  EPWM_DigitalCompareEventSource dcEventSource)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Set the DC event 1 source source */
    if (dcEvent == EPWM_DC_EVENT_1)
    {
        if (dcModule == EPWM_DC_MODULE_A)
        {
            base->DCACTL = (base->DCACTL & ~EPWM_REGS_DCACTL_EVT1SRCSEL_Msk) |
                                EPWM_REGS_DCACTL_EVT1SRCSEL_Set(dcEventSource);
        }
        else
        {
            base->DCBCTL = (base->DCBCTL & ~EPWM_REGS_DCBCTL_EVT1SRCSEL_Msk) |
                                EPWM_REGS_DCBCTL_EVT1SRCSEL_Set(dcEventSource);
        }
    }
    else
    {
        if (dcModule == EPWM_DC_MODULE_A)
        {
            base->DCACTL = (base->DCACTL & ~EPWM_REGS_DCACTL_EVT2SRCSEL_Msk) |
                                EPWM_REGS_DCACTL_EVT2SRCSEL_Set(dcEventSource);

        }
        else
        {
            base->DCBCTL = (base->DCBCTL & ~EPWM_REGS_DCBCTL_EVT2SRCSEL_Msk) |
                                EPWM_REGS_DCBCTL_EVT2SRCSEL_Set(dcEventSource);

        }
    }
}

/*!
 * Set up the Digital Compare input sync mode.
 *
 * \param base is the base address of the EPWM module.
 * \param dcModule is the Digital Compare module.
 * \param dcEvent is the Digital Compare Event number.
 * \param syncMode is the Digital Compare Event sync mode.
 *
 * This function sets up the Digital Compare module Event sources.
 * The following are valid values for the parameters.
 *  - dcModule
 *      - EPWM_DC_MODULE_A  - Digital Compare Module A
 *      - EPWM_DC_MODULE_B  - Digital Compare Module B
 *  - dcEvent
 *      - EPWM_DC_EVENT_1   - Digital Compare Event number 1
 *      - EPWM_DC_EVENT_2   - Digital Compare Event number 2
 *  - syncMode
 *      - EPWM_DC_EVENT_INPUT_SYNCED      - DC input signal is synced with
 *                                          TBCLK
 *      - EPWM_DC_EVENT_INPUT_NOT SYNCED  - DC input signal is not synced with
 *                                          TBCLK
 *   
 */
static inline void
EPWM_setDigitalCompareEventSyncMode(EPWM_REGS_Type *base,
                                    EPWM_DigitalCompareModule dcModule,
                                    EPWM_DigitalCompareEvent dcEvent,
                                    EPWM_DigitalCompareSyncMode syncMode)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Set the DC event sync mode */
    if(dcEvent == EPWM_DC_EVENT_1)
    {
        if (dcModule == EPWM_DC_MODULE_A) 
        {
            base->DCACTL = (base->DCACTL & ~EPWM_REGS_DCACTL_EVT1FRCSYNCSEL_Msk) |
                                EPWM_REGS_DCACTL_EVT1FRCSYNCSEL_Set(syncMode);
        }
        else
        {
            base->DCBCTL = (base->DCBCTL & ~EPWM_REGS_DCBCTL_EVT1FRCSYNCSEL_Msk) |
                                EPWM_REGS_DCBCTL_EVT1FRCSYNCSEL_Set(syncMode);
        }
    }
    else
    {
        if (dcModule == EPWM_DC_MODULE_A)
        {
            base->DCACTL = (base->DCACTL & ~EPWM_REGS_DCACTL_EVT2FRCSYNCSEL_Msk) |
                                EPWM_REGS_DCACTL_EVT2FRCSYNCSEL_Set(syncMode);
        }
        else
        {
            base->DCBCTL = (base->DCBCTL & ~EPWM_REGS_DCBCTL_EVT2FRCSYNCSEL_Msk) |
                                EPWM_REGS_DCBCTL_EVT2FRCSYNCSEL_Set(syncMode);
        }
    }
}

/*!
 * Enable Digital Compare to generate Start of Conversion.
 *
 * \param base is the base address of the EPWM module.
 * \param dcModule is the Digital Compare module.
 *
 * This function enables the Digital Compare Event 1 to generate Start of
 * Conversion.
 * The following are valid values for the \e dcModule parameter.
 *     - EPWM_DC_MODULE_A  - Digital Compare Module A
 *     - EPWM_DC_MODULE_B  - Digital Compare Module B
 *
 */
static inline void
EPWM_enableDigitalCompareADCTrigger(EPWM_REGS_Type *base,
                                    EPWM_DigitalCompareModule dcModule)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Enable Digital Compare start of conversion generation */
    if (dcModule == EPWM_DC_MODULE_A)
    {
        base->DCACTL |= EPWM_REGS_DCACTL_EVT1SOCE_Set(1);
    }
    else
    {
        base->DCBCTL |= EPWM_REGS_DCBCTL_EVT1SOCE_Set(1);
    }
}

/*!
 * Disable Digital Compare from generating Start of Conversion.
 *
 * \param base is the base address of the EPWM module.
 * \param dcModule is the Digital Compare module.
 *
 * This function disables the Digital Compare Event 1 from generating Start of
 * Conversion.
 * The following are valid values for the \e dcModule parameter.
 *     - EPWM_DC_MODULE_A  - Digital Compare Module A
 *     - EPWM_DC_MODULE_B  - Digital Compare Module B
 *   
 */
static inline void
EPWM_disableDigitalCompareADCTrigger(EPWM_REGS_Type *base,
                                     EPWM_DigitalCompareModule dcModule)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    if (dcModule == EPWM_DC_MODULE_A)
    {
        base->DCACTL &= ~EPWM_REGS_DCACTL_EVT1SOCE_Set(1);
    }
    else
    {
        base->DCBCTL &= ~EPWM_REGS_DCBCTL_EVT1SOCE_Set(1);
    }
}

/*!
 * Enable Digital Compare to generate sync out pulse.
 *
 * \param base is the base address of the EPWM module.
 * \param dcModule is the Digital Compare module.
 *
 * This function enables the Digital Compare Event 1 to generate sync out
 * pulse
 * The following are valid values for the \e dcModule parameter.
 *     - EPWM_DC_MODULE_A  - Digital Compare Module A
 *     - EPWM_DC_MODULE_B  - Digital Compare Module B
 *
 */
static inline void
EPWM_enableDigitalCompareSyncEvent(EPWM_REGS_Type *base,
                                   EPWM_DigitalCompareModule dcModule)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    if (dcModule == EPWM_DC_MODULE_A)
    {
        /* Enable Digital Compare sync out pulse generation */
        base->DCACTL |= EPWM_REGS_DCACTL_EVT1SYNCE_Set(1);
    }
    else
    {
        base->DCBCTL |= EPWM_REGS_DCBCTL_EVT1SYNCE_Set(1);
    }
}

/*!
 * Disable Digital Compare from generating Start of Conversion.
 *
 * \param base is the base address of the EPWM module.
 * \param dcModule is the Digital Compare module.
 *
 * This function disables the Digital Compare Event 1 from generating synch
 * out pulse.
 * The following are valid values for the \e dcModule parameters.
 *     - EPWM_DC_MODULE_A  - Digital Compare Module A
 *     - EPWM_DC_MODULE_B  - Digital Compare Module B
 *
 */
static inline void
EPWM_disableDigitalCompareSyncEvent(EPWM_REGS_Type *base,
                                    EPWM_DigitalCompareModule dcModule)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    if (dcModule == EPWM_DC_MODULE_A)
    {    
        /* Disable Digital Compare sync out pulse generation */
        base->DCACTL &= ~EPWM_REGS_DCACTL_EVT1SYNCE_Set(1);
    }
    else
    {
        base->DCBCTL &= ~EPWM_REGS_DCBCTL_EVT1SYNCE_Set(1);
    }
}

/*!
 * Set up the Digital Compare CBC latch mode.
 *
 * \param base is the base address of the EPWM module.
 * \param dcModule is the Digital Compare module.
 * \param dcEvent is the Digital Compare Event number.
 * \param latchMode is the Digital Compare CBC latch mode.
 *
 * This function sets up the Digital Compare CBC latch mode.
 * The following are valid values for the parameters.
 *  - dcModule
 *      - EPWM_DC_MODULE_A  - Digital Compare Module A
 *      - EPWM_DC_MODULE_B  - Digital Compare Module B
 *  - dcEvent
 *      - EPWM_DC_EVENT_1   - Digital Compare Event number 1
 *      - EPWM_DC_EVENT_2   - Digital Compare Event number 2
 *  - latchMode
 *      - EPWM_DC_CBC_LATCH_DISABLED - DC cycle-by-cycle(CBC) latch is disabled
 *      - EPWM_DC_CBC_LATCH_ENABLED  - DC cycle-by-cycle(CBC) latch is enabled
 *
 */
static inline void
EPWM_setDigitalCompareCBCLatchMode(EPWM_REGS_Type *base,
                                   EPWM_DigitalCompareModule dcModule,
                                   EPWM_DigitalCompareEvent dcEvent,
                                   EPWM_DigitalCompareCBCLatchMode latchMode)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Set the DC CBC Latch Mode */
    if(dcEvent == EPWM_DC_EVENT_1)
    {
        if (dcModule == EPWM_DC_MODULE_A)
        {
            base->DCACTL = (base->DCACTL & ~EPWM_REGS_DCACTL_EVT1LATSEL_Msk) |
                                EPWM_REGS_DCACTL_EVT1LATSEL_Set(latchMode);
        }
        else
        {
            base->DCBCTL = (base->DCBCTL & ~EPWM_REGS_DCBCTL_EVT1LATSEL_Msk) |
                                EPWM_REGS_DCBCTL_EVT1LATSEL_Set(latchMode);
        }
    }
    else
    {
        if (dcModule == EPWM_DC_MODULE_A)
        {
            base->DCACTL = (base->DCACTL & ~EPWM_REGS_DCACTL_EVT2LATSEL_Msk) |
                                EPWM_REGS_DCACTL_EVT2LATSEL_Set(latchMode);
        }
        else
        {
            base->DCBCTL = (base->DCBCTL & ~EPWM_REGS_DCBCTL_EVT2LATSEL_Msk) |
                                EPWM_REGS_DCBCTL_EVT2LATSEL_Set(latchMode);
        }
    }
}

/*!
 * Sets the Digital Compare CBC latch clear event.
 *
 * \param base is the base address of the EPWM module.
 * \param dcModule is the Digital Compare module.
 * \param dcEvent is the Digital Compare Event number.
 * \param clearEvent is the Digital Compare CBC latch clear event.
 *
 * This function sets the Digital Compare CBC latch clear event.
 * The following are valid values for the parameters.
 *  - dcModule
 *      - EPWM_DC_MODULE_A  - Digital Compare Module A
 *      - EPWM_DC_MODULE_B  - Digital Compare Module B
 *  - dcEvent
 *      - EPWM_DC_EVENT_1   - Digital Compare Event number 1
 *      - EPWM_DC_EVENT_2   - Digital Compare Event number 2
 *  - clearEvent
 *      - EPWM_DC_CBC_LATCH_CLR_CNTR_ZERO - DC CBC latch is cleared when
 *                                          counter is zero
 *      - EPWM_DC_CBC_LATCH_CLR_ON_CNTR_PERIOD - DC CBC latch is cleared when
 *                                               counter is equal to period
 *      - EPWM_DC_CBC_LATCH_CLR_ON_CNTR_ZERO_PERIOD - DC CBC latch is cleared
 *                                                    when either counter is
 *                                                    zero or equal to period
 *
 */
static inline void
EPWM_selectDigitalCompareCBCLatchClearEvent(EPWM_REGS_Type *base,
                              EPWM_DigitalCompareModule dcModule,
                              EPWM_DigitalCompareEvent dcEvent,
                              EPWM_DigitalCompareCBCLatchClearEvent clearEvent)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Set the DC CBC Latch Clear Event */
    if(dcEvent == EPWM_DC_EVENT_1)
    {
        if (dcModule == EPWM_DC_MODULE_A)
        {
            base->DCACTL = (base->DCACTL & ~EPWM_REGS_DCACTL_EVT1LATCLRSEL_Msk) |
                                EPWM_REGS_DCACTL_EVT1LATCLRSEL_Set(clearEvent);            
        }
        else
        {
            base->DCBCTL = (base->DCBCTL & ~EPWM_REGS_DCBCTL_EVT1LATCLRSEL_Msk) |
                                EPWM_REGS_DCBCTL_EVT1LATCLRSEL_Set(clearEvent);            
        }
    }
    else
    {
        if (dcModule == EPWM_DC_MODULE_A)
        {
            base->DCACTL = (base->DCACTL & ~EPWM_REGS_DCACTL_EVT2LATCLRSEL_Msk) |
                                EPWM_REGS_DCACTL_EVT2LATCLRSEL_Set(clearEvent);            
        }
        else
        {
            base->DCBCTL = (base->DCBCTL & ~EPWM_REGS_DCBCTL_EVT2LATCLRSEL_Msk) |
                                EPWM_REGS_DCBCTL_EVT2LATCLRSEL_Set(clearEvent);            
        }
    }
}

/*!
 * Gets the Digital Compare CBC latch status
 *
 * \param base is the base address of the EPWM module.
 * \param dcModule is the Digital Compare module.
 * \param dcEvent is the Digital Compare Event number.
 *
 * This function returns the Digital Compare module cycle-by-cycle(CBC) latch
 * status.
 * The following are valid values for the parameters.
 *  - dcModule
 *      - EPWM_DC_MODULE_A  - Digital Compare Module A
 *      - EPWM_DC_MODULE_B  - Digital Compare Module B
 *  - dcEvent
 *      - EPWM_DC_EVENT_1   - Digital Compare Event number 1
 *      - EPWM_DC_EVENT_2   - Digital Compare Event number 2
 *
 * \return Returns Digital Compare CBC latch status.
 * -\b true  - CBC latch is enabled
 * -\b false - CBC latch is disabled
 */
static inline bool
EPWM_getDigitalCompareCBCLatchStatus(EPWM_REGS_Type *base,
                                     EPWM_DigitalCompareModule dcModule,
                                     EPWM_DigitalCompareEvent dcEvent)
{
    uint16_t status;
    
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Get DC CBC Latch Clear Event */
    if(dcEvent == EPWM_DC_EVENT_1)
    {
        if (dcModule == EPWM_DC_MODULE_A)
        {
            status = EPWM_REGS_DCACTL_EVT1LAT_Get(base->DCACTL);
        }
        else
        {
            status = EPWM_REGS_DCBCTL_EVT1LAT_Get(base->DCACTL);
        }
    }
    else
    {
        if (dcModule == EPWM_DC_MODULE_A)
        {
            status = EPWM_REGS_DCACTL_EVT2LAT_Get(base->DCACTL);
        }
        else
        {
            status = EPWM_REGS_DCBCTL_EVT2LAT_Get(base->DCACTL);
        }
    }

    return (status != 0U);
}

/*!
 * Enables the Time Base Counter Capture controller.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function enables the time Base Counter Capture.
 *
 */
static inline void
EPWM_enableDigitalCompareCounterCapture(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Enable Time base counter capture */
    base->DCCAPCTL |= EPWM_REGS_DCCAPCTL_CAPE_Set(1);
}

/*!
 * Disables the Time Base Counter Capture controller.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function disable the time Base Counter Capture.
 *
 */
static inline void
EPWM_disableDigitalCompareCounterCapture(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Disable Time base counter capture */
    base->DCCAPCTL &= ~EPWM_REGS_DCCAPCTL_CAPE_Set(1);
}

/*!
 * Set the Time Base Counter Capture mode.
 *
 * \param base is the base address of the EPWM module.
 * \param enableShadowMode is the shadow read mode flag.
 *
 * This function sets the mode the Time Base Counter value is read from. If
 * enableShadowMode is true, CPU reads of the DCCAP register will return the
 * shadow register contents.If enableShadowMode is false, CPU reads of the
 * DCCAP register will return the active register contents.
 *
 */
static inline void
EPWM_setDigitalCompareCounterShadowMode(EPWM_REGS_Type *base, bool enableShadowMode)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    if (enableShadowMode)
    {
        /* Enable DC counter shadow mode */
        base->DCCAPCTL &= ~EPWM_REGS_DCCAPCTL_SHDWMODE_Set(1);
   }
   else
   {
      /* Disable DC counter shadow mode */
       base->DCCAPCTL |= EPWM_REGS_DCCAPCTL_SHDWMODE_Set(1);   }
}

/*!
 * Return the DC Capture event status.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function returns the DC capture event status.
 *
 * \return Returns true if a DC capture event has occurs.
 *         Returns false if no DC Capture event has occurred.
 *
 */
static inline bool
EPWM_getDigitalCompareCaptureStatus(EPWM_REGS_Type *base)
{
    /* Check the arguments */
   assert(EPWM_isBaseValid(base));

   /* Return the DC compare status */
   return (EPWM_REGS_DCCAPCTL_CAPSTS_Get(base->DCCAPCTL) == 0x2000U);
}

/*!
 * Return the DC Time Base Counter capture value.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function returns the DC Time Base Counter capture value. The value
 * read is determined by the mode as set in the
 * EPWM_setTimeBaseCounterReadMode() function.
 *
 * \return Returns the DC Time Base Counter Capture count value.
 */
static inline uint16_t
EPWM_getDigitalCompareCaptureCount(EPWM_REGS_Type *base)
{
    /* Check the arguments */
   assert(EPWM_isBaseValid(base));

   /* Return the DC Time Base Counter Capture count value */
   return EPWM_REGS_DCCAP_DCCAP_Get(base->DCCAP);
}

/*!
 * Enable DC TRIP combinational input.
 *
 * \param base is the base address of the EPWM module.
 * \param tripInput is the Trip number.
 * \param dcType is the Digital Compare module.
 *
 * This function enables the specified Trip input.
 * Valid values for the parameters are:
 *  - tripInput
 *      - EPWM_DC_COMBINATIONAL_TRIPINx, where x is 1,2,...12,14,15
 *  - dcType
 *      - EPWM_DC_TYPE_DCAH  - Digital Compare A High
 *      - EPWM_DC_TYPE_DCAL  - Digital Compare A Low
 *      - EPWM_DC_TYPE_DCBH  - Digital Compare B High
 *      - EPWM_DC_TYPE_DCBL  - Digital Compare B Low
 *
 */
static inline void
EPWM_enableDigitalCompareTripCombinationInput(EPWM_REGS_Type *base,
                                              uint16_t tripInput,
                                              EPWM_DigitalCompareType dcType)
{
    /* Check the arguments */
   assert(EPWM_isBaseValid(base));

   /* Get the DCAHTRIPSEL, DCALTRIPSEL, DCBHTRIPSEL, DCBLTRIPSEL register
      offset with respect to DCAHTRIPSEL*/
   switch (dcType)
   {
       /* Set the DC trip input */
       case EPWM_DC_TYPE_DCAH:
            base->DCAHTRIPSEL |= tripInput;
            break;
        case EPWM_DC_TYPE_DCAL:
            base->DCALTRIPSEL |= tripInput;
            break;
        case EPWM_DC_TYPE_DCBH:
            base->DCBHTRIPSEL |= tripInput;
            break;
        case EPWM_DC_TYPE_DCBL:
            base->DCBLTRIPSEL |= tripInput;
            break;
        default:
            break;
    }

    /* Enable the combination input */
    base->DCTRIPSEL |= (0xFU << ((uint16_t)dcType << 2U));
}

/*!
 * Disable DC TRIP combinational input.
 *
 * \param base is the base address of the EPWM module.
 * \param tripInput is the Trip number.
 * \param dcType is the Digital Compare module.
 *
 * This function disables the specified Trip input.
 * Valid values for the parameters are:
 *  - tripInput
 *      - EPWM_DC_COMBINATIONAL_TRIPINx, where x is 1,2,...12,14,15
 *  - dcType
 *      - EPWM_DC_TYPE_DCAH  - Digital Compare A High
 *      - EPWM_DC_TYPE_DCAL  - Digital Compare A Low
 *      - EPWM_DC_TYPE_DCBH  - Digital Compare B High
 *      - EPWM_DC_TYPE_DCBL  - Digital Compare B Low
 *
 */
static inline void
EPWM_disableDigitalCompareTripCombinationInput(EPWM_REGS_Type *base,
                                               uint16_t tripInput,
                                               EPWM_DigitalCompareType dcType)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Get the DCAHTRIPSEL, DCALTRIPSEL, DCBHTRIPSEL, DCBLTRIPSEL register 
       offset with respect to DCAHTRIPSEL*/
    switch (dcType)
    {   
        /* Set the DC trip input */
        case EPWM_DC_TYPE_DCAH:
            base->DCAHTRIPSEL &= ~tripInput;
            break;
        case EPWM_DC_TYPE_DCAL:
            base->DCALTRIPSEL &= ~tripInput;
            break;
        case EPWM_DC_TYPE_DCBH:
            base->DCBHTRIPSEL &= ~tripInput;
            break;
        case EPWM_DC_TYPE_DCBL:
            base->DCBLTRIPSEL &= ~tripInput;
            break;
        default:
            break;
    }
}

/*!
 * Enable valley capture mode.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function enables Valley Capture mode.
 *
 */
static inline void
EPWM_enableValleyCapture(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Set VCAPE bit */
    base->VCAPCTL |= EPWM_REGS_VCAPCTL_VCAPE_Set(1);
}

/*!
 * Disable valley capture mode.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function disables Valley Capture mode.
 *
 */
static inline void
EPWM_disableValleyCapture(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Clear VCAPE bit */
    base->VCAPCTL &= ~EPWM_REGS_VCAPCTL_VCAPE_Set(1);
}

/*!
 * Start valley capture mode.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function starts Valley Capture sequence.
 *
 * \b Make sure you invoke EPWM_setValleyTriggerSource with the trigger
 *    variable set to EPWM_VALLEY_TRIGGER_EVENT_SOFTWARE before calling this
 *    function.
 *
 */
static inline void
EPWM_startValleyCapture(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Set VCAPSTART bit */
    base->VCAPCTL |= EPWM_REGS_VCAPCTL_VCAPSTART_Set(1);
}

/*!
 * Set valley capture trigger.
 *
 * \param base is the base address of the EPWM module.
 * \param trigger is the Valley counter trigger.
 *
 * This function sets the trigger value that initiates Valley Capture sequence
 *
 * \b Set the number of Trigger source events for starting and stopping the
 *    valley capture using EPWM_setValleyTriggerEdgeCounts().
 *
 */
static inline void
EPWM_setValleyTriggerSource(EPWM_REGS_Type *base, EPWM_ValleyTriggerSource trigger)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Write to TRIGSEL bits */
    base->VCAPCTL = (base->VCAPCTL & ~EPWM_REGS_VCAPCTL_TRIGSEL_Msk) |
                        EPWM_REGS_VCAPCTL_TRIGSEL_Set(trigger);
}

/*!
 * Set valley capture trigger source count.
 *
 * \param base is the base address of the EPWM module.
 * \param startCount
 * \param stopCount
 *
 * This function sets the number of trigger events required to start and stop
 * the valley capture count.
 * Maximum values for both startCount and stopCount is 15 corresponding to the
 * 15th edge of the trigger event.
 *
 * \b Note:
 *    A startCount value of 0 prevents starting the valley counter.
 *    A stopCount value of 0 prevents the valley counter from stopping.
 *
 */
static inline void
EPWM_setValleyTriggerEdgeCounts(EPWM_REGS_Type *base, uint16_t startCount,
                                uint16_t stopCount)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));
    assert((startCount < 16U) && (stopCount < 16U));

    /* Write to STARTEDGE and STOPEDGE bits */
    base->VCNTCFG = (base->VCNTCFG & ~(EPWM_REGS_VCNTCFG_STARTEDGE_Msk | EPWM_REGS_VCNTCFG_STOPEDGE_Msk)) |
                        EPWM_REGS_VCNTCFG_STOPEDGE_Set(stopCount) |
                        EPWM_REGS_VCNTCFG_STARTEDGE_Set(startCount);
}

/*!
 * Enable valley switching delay.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function enables Valley switching delay.
 *
 */
static inline void
EPWM_enableValleyHWDelay(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Set EDGEFILTDLYSEL bit */
    base->VCAPCTL |= EPWM_REGS_VCAPCTL_EDGEFILTDLYSEL_Set(1);
}

/*!
 * Disable valley switching delay.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function disables Valley switching delay.
 *
 */
static inline void
EPWM_disableValleyHWDelay(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Clear EDGEFILTDLYSEL bit */
    base->VCAPCTL &= ~EPWM_REGS_VCAPCTL_EDGEFILTDLYSEL_Set(1);
}

/*!
 * Set Valley delay values.
 *
 * \param base is the base address of the EPWM module.
 * \param delayOffsetValue is the software defined delay offset value.
 *
 * This function sets the Valley delay value.
 *
 */
static inline void
EPWM_setValleySWDelayValue(EPWM_REGS_Type *base, uint16_t delayOffsetValue)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Write to SWVDELVAL bits */
    base->SWVDELVAL = EPWM_REGS_SWVDELVAL_SWVDELVAL_Set(delayOffsetValue);
}

/*!
 * Set Valley delay mode.
 *
 * \param base is the base address of the EPWM module.
 * \param delayMode is the Valley delay mode.
 *
 * This function sets the Valley delay mode values.
 *
 */
static inline void
EPWM_setValleyDelayDivider(EPWM_REGS_Type *base, EPWM_ValleyDelayMode delayMode)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Write to VDELAYDIV bits */    // bug VDELATDIV is wrong
    base->VCAPCTL = (base->VCAPCTL & ~EPWM_REGS_VCAPCTL_VDELATDIV_Msk) | 
                        EPWM_REGS_VCAPCTL_VDELATDIV_Set(delayMode);
}

/*!
 * Get the valley edge status bit.
 *
 * \param base is the base address of the EPWM module.
 * \param edge is the start or stop edge.
 *
 * This function returns the status of the start or stop valley status
 * depending on the value of edge.
 * If a start or stop edge has occurred, the function returns true, if not it
 * returns false.
 *
 * \return Returns true if the specified edge has occurred,
 *         Returns false if the specified edge has not occurred.
 */
static inline bool
EPWM_getValleyEdgeStatus(EPWM_REGS_Type *base, EPWM_ValleyCounterEdge edge)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    if(edge == EPWM_VALLEY_COUNT_START_EDGE)
    {
        /* Returns STARTEDGESTS status */
        return EPWM_REGS_VCNTCFG_STARTEDGESTS_Get(base->VCNTCFG);
    }
    else
    {
        /* Returns STOPEDGESTS status */
        return EPWM_REGS_VCNTCFG_STOPEDGESTS_Get(base->VCNTCFG);
    }
}

/*!
 * Get the Valley Counter value.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function returns the valley time base count value which is captured
 * upon occurrence of the stop edge condition selected by
 * EPWM_setValleyTriggerSource() and by the stopCount variable of the
 * EPWM_setValleyTriggerEdgeCounts() function.
 *
 * \return Returns the valley base time count.
 */
static inline uint16_t
EPWM_getValleyCount(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Read VCNTVAL register */
    return EPWM_REGS_VCNTVAL_VCNTVAL_Get(base->VCNTVAL);
}

/*!
 * Get the Valley delay value.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function returns the hardware valley delay count.
 *
 * \return Returns the valley delay count.
 */
static inline uint16_t
EPWM_getValleyHWDelay(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Read HWVDELVAL  register */
    return EPWM_REGS_HWVDELVAL_HWVDELVAL_Get(base->HWVDELVAL);
}

/*!
 * Enable Global shadow load mode.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function enables Global shadow to active load mode of registers.
 * The trigger source for loading shadow to active is determined by
 * EPWM_setGlobalLoadTrigger() function.
 *
 */
static inline void
EPWM_enableGlobalLoad(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Shadow to active load is controlled globally */
    base->GLDCTL |= EPWM_REGS_GLDCTL_GLD_Set(1);
}

/*!
 * Disable Global shadow load mode.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function disables Global shadow to active load mode of registers.
 * Loading shadow to active is determined individually.
 *
 */
static inline void
EPWM_disableGlobalLoad(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Shadow to active load is controlled individually */
    base->GLDCTL &= ~EPWM_REGS_GLDCTL_GLD_Set(1);
}

/*!
 * Set the Global shadow load pulse.
 *
 * \param base is the base address of the EPWM module.
 * \param loadTrigger is the pulse that causes global shadow load.
 *
 * This function sets the pulse that causes Global shadow to active load.
 * Valid values for the loadTrigger parameter are:
 *
 *   - EPWM_GL_LOAD_PULSE_CNTR_ZERO              - load when counter is equal
 *                                                 to zero
 *   - EPWM_GL_LOAD_PULSE_CNTR_PERIOD            - load when counter is equal
 *                                                 to period
 *   - EPWM_GL_LOAD_PULSE_CNTR_ZERO_PERIOD       - load when counter is equal
 *                                                 to zero or period
 *   - EPWM_GL_LOAD_PULSE_SYNC                    - load on sync event
 *   - EPWM_GL_LOAD_PULSE_SYNC_OR_CNTR_ZERO      - load on sync event or when
 *                                                 counter is equal to zero
 *   - EPWM_GL_LOAD_PULSE_SYNC_OR_CNTR_PERIOD    - load on sync event or when
 *                                                 counter is equal to period
 *   - EPWM_GL_LOAD_PULSE_SYNC_CNTR_ZERO_PERIOD  - load on sync event or when
 *                                                 counter is equal to period
 *                                                 or zero
 *   - EPWM_GL_LOAD_PULSE_GLOBAL_FORCE            - load on global force
 *
 */
static inline void
EPWM_setGlobalLoadTrigger(EPWM_REGS_Type *base, EPWM_GlobalLoadTrigger loadTrigger)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Set the Global shadow to active load pulse */
    base->GLDCTL = (base->GLDCTL & ~EPWM_REGS_GLDCTL_GLDMODE_Msk) |
                        EPWM_REGS_GLDCTL_GLDMODE_Set(loadTrigger);
}

/*!
 * Set the number of Global load pulse event counts
 *
 * \param base is the base address of the EPWM module.
 * \param prescalePulseCount is the pulse event counts.
 *
 * This function sets the number of Global Load pulse events that have to
 * occurred before a global load pulse is issued. Valid values for
 * prescaleCount range from 0 to 7. 0 being no event (disables counter), and 7
 * representing 7 events.
 *
 */
static inline void
EPWM_setGlobalLoadEventPrescale(EPWM_REGS_Type *base, uint16_t prescalePulseCount)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));
    assert(prescalePulseCount < 8U);

    /* Set the number of counts that have to occur before a load strobe is issued*/
    base->GLDCTL = (base->GLDCTL & ~EPWM_REGS_GLDCTL_GLDPRD_Msk) |
                        EPWM_REGS_GLDCTL_GLDPRD_Set(prescalePulseCount);
}

/*!
 * Return the number of Global load pulse event counts
 *
 * \param base is the base address of the EPWM module.
 *
 * This function returns the number of Global Load pulse events that have
 * occurred. These pulse events are set by the EPWM_setGlobalLoadTrigger()
 * function.
 *
 * \return Returns the count of global event
 */
static inline uint16_t
EPWM_getGlobalLoadEventCount(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Return the number of events that have occurred */
    return EPWM_REGS_GLDCTL_GLDCNT_Get(base->GLDCTL);
}

/*!
 * Enable continuous global shadow to active load.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function enables global continuous shadow to active load. Register
 * load happens every time the event set by the
 * EPWM_setGlobalLoadTrigger() occurs.
 *
 */
static inline void
EPWM_disableGlobalLoadOneShotMode(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Enable global continuous shadow to active load */
    base->GLDCTL &= ~EPWM_REGS_GLDCTL_OSHTMODE_Set(1);
}

/*!
 * Enable One shot global shadow to active load.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function enables a one time global shadow to active load. Register
 * load happens every time the event set by the
 * EPWM_setGlobalLoadTrigger() occurs.
 *
 */
static inline void
EPWM_enableGlobalLoadOneShotMode(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Enable global continuous shadow to active load */
    base->GLDCTL |= EPWM_REGS_GLDCTL_OSHTMODE_Set(1);
}

/*!
 * Set One shot global shadow to active load pulse.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function sets a one time global shadow to active load pulse. The pulse
 * propagates to generate a load signal if any of the events set by
 * EPWM_setGlobalLoadTrigger() occur.
 *
 */
static inline void
EPWM_setGlobalLoadOneShotLatch(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Set a one shot Global shadow load pulse. */
    base->GLDCTL2 |= EPWM_REGS_GLDCTL2_OSHTLD_Set(1);
}

/*!
 * Force a software One shot global shadow to active load pulse.
 *
 * \param base is the base address of the EPWM module.
 *
 * This function forces a software a one time global shadow to active load
 * pulse.
 *
 */
static inline void
EPWM_forceGlobalLoadOneShotEvent(EPWM_REGS_Type *base)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Force a Software Global shadow load pulse */
    base->GLDCTL2 |= EPWM_REGS_GLDCTL2_GFRCLD_Set(1);
}

/*!
 * Enable a register to be loaded Globally.
 *
 * \param base is the base address of the EPWM module.
 * \param loadRegister is the register.
 *
 * This function enables the register specified by loadRegister to be globally
 * loaded.
 * Valid values for loadRegister are:
 *  - EPWM_GL_REGISTER_TBPRD_TBPRDHR  - Register TBPRD:TBPRDHR
 *  - EPWM_GL_REGISTER_CMPA_CMPAHR    - Register CMPA:CMPAHR
 *  - EPWM_GL_REGISTER_CMPB_CMPBHR    - Register CMPB:CMPBHR
 *  - EPWM_GL_REGISTER_CMPC           - Register CMPC
 *  - EPWM_GL_REGISTER_CMPD           - Register CMPD
 *  - EPWM_GL_REGISTER_DBRED_DBREDHR  - Register DBRED:DBREDHR
 *  - EPWM_GL_REGISTER_DBFED_DBFEDHR  - Register DBFED:DBFEDHR
 *  - EPWM_GL_REGISTER_DBCTL          - Register DBCTL
 *  - EPWM_GL_REGISTER_AQCTLA_AQCTLA2 - Register AQCTLA/A2
 *  - EPWM_GL_REGISTER_AQCTLB_AQCTLB2 - Register AQCTLB/B2
 *  - EPWM_GL_REGISTER_AQCSFRC        - Register AQCSFRC
 *
 */
static inline void
EPWM_enableGlobalLoadRegisters(EPWM_REGS_Type *base, uint16_t loadRegister)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));
    assert((loadRegister > 0x0000U) && (loadRegister < 0x0800U));

    /* The register specified by loadRegister is loaded globally */
    base->GLDCFG |= loadRegister;
}

/*!
 * Disable a register to be loaded Globally.
 *
 * \param base is the base address of the EPWM module.
 * \param loadRegister is the register.
 *
 * This function disables the register specified by loadRegister from being
 * loaded globally. The shadow to active load happens as specified by the
 * register control
 * Valid values for loadRegister are:
 *  - EPWM_GL_REGISTER_TBPRD_TBPRDHR  - Register TBPRD:TBPRDHR
 *  - EPWM_GL_REGISTER_CMPA_CMPAHR    - Register CMPA:CMPAHR
 *  - EPWM_GL_REGISTER_CMPB_CMPBHR    - Register CMPB:CMPBHR
 *  - EPWM_GL_REGISTER_CMPC           - Register CMPC
 *  - EPWM_GL_REGISTER_CMPD           - Register CMPD
 *  - EPWM_GL_REGISTER_DBRED_DBREDHR  - Register DBRED:DBREDHR
 *  - EPWM_GL_REGISTER_DBFED_DBFEDHR  - Register DBFED:DBFEDHR
 *  - EPWM_GL_REGISTER_DBCTL          - Register DBCTL
 *  - EPWM_GL_REGISTER_AQCTLA_AQCTLA2 - Register AQCTLA/A2
 *  - EPWM_GL_REGISTER_AQCTLB_AQCTLB2 - Register AQCTLB/B2
 *  - EPWM_GL_REGISTER_AQCSFRC        - Register AQCSFRC
 *
 */
static inline void
EPWM_disableGlobalLoadRegisters(EPWM_REGS_Type *base, uint16_t loadRegister)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));
    assert((loadRegister > 0x0000U) && (loadRegister < 0x0800U));

    /* The register specified by loadRegister is loaded by individual register configuration setting */
    base->GLDCFG &= ~loadRegister;
}

/*!
 * Lock EALLOW protected register groups
 *
 * \param base is the base address of the EPWM module.
 * \param registerGroup is the EALLOW register groups.
 *
 * This functions locks the EALLOW protected register groups specified by
 * the registerGroup variable.
 *
 */
static inline void
EPWM_lockRegisters(EPWM_REGS_Type *base, EPWM_LockRegisterGroup registerGroup)
{
    /* Check the arguments */
    assert(EPWM_isBaseValid(base));

    /* Write the Key to EPWMLOCK register */
    base->EPWMLOCK = (0xA5A50000UL | ((uint32_t)registerGroup));
}

/*!
 * Set emulation mode
 *
 * \param base is the base address of the EPWM module.
 * \param emulationMode is the emulation mode.
 *
 * This function sets the emulation behaviours of the time base counter. Valid
 * values for emulationMode are:
 *  - EPWM_EMULATION_STOP_AFTER_NEXT_TB    - Stop after next Time Base counter
 *                                           increment or decrement.
 *  - EPWM_EMULATION_STOP_AFTER_FULL_CYCLE - Stop when counter completes whole
 *                                           cycle.
 *  - EPWM_EMULATION_FREE_RUN               - Free run.
 *
 */
extern void
EPWM_setEmulationMode(EPWM_REGS_Type *base, EPWM_EmulationMode emulationMode);

/*!
 * Configures ePWM signal with desired frequency & duty
 *
 * \param base is the base address of the EPWM module.
 * \param signalParams is the desired signal parameters.
 *
 * This function configures the ePWM module to generate a signal with
 * desired frequency & duty.
 *
 */
extern void
EPWM_configureSignal(EPWM_REGS_Type *base, const EPWM_SignalParams *signalParams);

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */ /* end of DRV_HTE_EPWM */

#endif /* HTE_EPWM_H */
