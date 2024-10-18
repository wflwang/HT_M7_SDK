/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


/*!
 * \file HS32F7D377_syncsoc.h
 * \brief HS32F7D377 SYNCSOC register file
 * \version V1.0_20231121
 */

#ifndef HS32F7D377_SYNCSOC_H
#define HS32F7D377_SYNCSOC_H

/*!
 * \addtogroup HS32F7D377_SYNCSOC_REGISTER HS32F7D377 SYNCSOC Register
 * \ingroup HS32F7D377_REGISTER
 *
 * \brief SYNCSOC register layout, bitfield and address definitions
 *
 * @{
 */

/* clang-format off */

/*!
 * \name SYNCSOC Register Layout
 *
 *
 * @{
 */

/*! \brief SYNC_SOC register */
typedef struct {
    union
    {
        __IOM uint32_t SYNCSELECT                        ;  /*!< 0x00000000 : Sync Input and Output Select Register */

        struct
        {
                  uint32_t RSV_0                     : 24;  /*!< [23: 0] : reserved. */
            __IOM uint32_t SYNCOUT                   : 5 ;  /*!< [28:24] : Select Syncout Source:
                                                                           00000: EPWM1SYNCOUT selected to drive the SYNCOUT pin. 00001: EPWM2SYNCOUT selected to drive the SYNCOUT pin. 00010: EPWM3SYNCOUT selected to drive the SYNCOUT pin. 00011: EPWM4SYNCOUT selected to drive the SYNCOUT pin. 00100: EPWM5SYNCOUT selected to drive the SYNCOUT pin. 00101: EPWM6SYNCOUT selected to drive the SYNCOUT pin. 00110: EPWM7SYNCOUT selected to drive the SYNCOUT pin. 00111: EPWM8SYNCOUT selected to drive the SYNCOUT pin. 01000: EPWM9SYNCOUT selected to drive the SYNCOUT pin. 01001: EPWM10SYNCOUT selected to drive the SYNCOUT pin. 01010: EPWM11SYNCOUT selected to drive the SYNCOUT pin. 01011: EPWM12SYNCOUT selected to drive the SYNCOUT pin. 01100: EPWM13SYNCOUT selected to drive the SYNCOUT pin. 01101: EPWM14SYNCOUT selected to drive the SYNCOUT pin. 01110: EPWM15SYNCOUT selected to drive the SYNCOUT pin. 01111: EPWM16SYNCOUT selected to drive the SYNCOUT pin. 10000: Reserved
                                                                           10001: Reserved
                                                                           10010: Reserved
                                                                           10011: Reserved
                                                                           10100: Reserved
                                                                           10101: Reserved
                                                                           10110: Reserved
                                                                           10111: Reserved
                                                                           11000: ECAP1SYNCOUT selected to drive the SYNCOUT pin. 11001: ECAP2SYNCOUT selected to drive the SYNCOUT pin. 11010: ECAP3SYNCOUT selected to drive the SYNCOUT pin. 11011: ECAP4SYNCOUT selected to drive the SYNCOUT pin. 11100: ECAP5SYNCOUT selected to drive the SYNCOUT pin. 11101: ECAP6SYNCOUT selected to drive the SYNCOUT pin. 11110: ECAP7SYNCOUT selected to drive the SYNCOUT pin. 11111: Reserved
                                                                           Notes:
                                                                           [1] Reserved position defaults to 00 selection Reset type: CPU1.SYSRSn */
                  uint32_t RSV_1                     : 3 ;  /*!< [31:29] : reserved. */
        } SYNCSELECTb;
    };

    union
    {
        __IOM uint32_t ADCSOCOUTSELECT                   ;  /*!< 0x00000004 : External ADC (Off Chip) SOC Select Register */

        struct
        {
            __IOM uint32_t PWM1SOCAEN                : 1 ;  /*!< [ 0: 0] : ADCSOCAOn source select:
                                                                           0: Respective EPWM SOCA output is not selected 1: Respective EPWM SOCA output is selected Reset type: CPU1.SYSRSn */
            __IOM uint32_t PWM2SOCAEN                : 1 ;  /*!< [ 1: 1] : ADCSOCAOn source select:
                                                                           0: Respective EPWM SOCA output is not selected 1: Respective EPWM SOCA output is selected Reset type: CPU1.SYSRSn */
            __IOM uint32_t PWM3SOCAEN                : 1 ;  /*!< [ 2: 2] : ADCSOCAOn source select:
                                                                           0: Respective EPWM SOCA output is not selected 1: Respective EPWM SOCA output is selected Reset type: CPU1.SYSRSn */
            __IOM uint32_t PWM4SOCAEN                : 1 ;  /*!< [ 3: 3] : ADCSOCAOn source select:
                                                                           0: Respective EPWM SOCA output is not selected 1: Respective EPWM SOCA output is selected Reset type: CPU1.SYSRSn */
            __IOM uint32_t PWM5SOCAEN                : 1 ;  /*!< [ 4: 4] : ADCSOCAOn source select:
                                                                           0: Respective EPWM SOCA output is not selected 1: Respective EPWM SOCA output is selected Reset type: CPU1.SYSRSn */
            __IOM uint32_t PWM6SOCAEN                : 1 ;  /*!< [ 5: 5] : ADCSOCAOn source select:
                                                                           0: Respective EPWM SOCA output is not selected 1: Respective EPWM SOCA output is selected Reset type: CPU1.SYSRSn */
            __IOM uint32_t PWM7SOCAEN                : 1 ;  /*!< [ 6: 6] : ADCSOCAOn source select:
                                                                           0: Respective EPWM SOCA output is not selected 1: Respective EPWM SOCA output is selected Reset type: CPU1.SYSRSn */
            __IOM uint32_t PWM8SOCAEN                : 1 ;  /*!< [ 7: 7] : ADCSOCAOn source select:
                                                                           0: Respective EPWM SOCA output is not selected 1: Respective EPWM SOCA output is selected Reset type: CPU1.SYSRSn */
            __IOM uint32_t PWM9SOCAEN                : 1 ;  /*!< [ 8: 8] : ADCSOCAOn source select:
                                                                           0: Respective EPWM SOCA output is not selected 1: Respective EPWM SOCA output is selected Reset type: CPU1.SYSRSn */
            __IOM uint32_t PWM10SOCAEN               : 1 ;  /*!< [ 9: 9] : ADCSOCAOn source select:
                                                                           0: Respective EPWM SOCA output is not selected 1: Respective EPWM SOCA output is selected Reset type: CPU1.SYSRSn */
            __IOM uint32_t PWM11SOCAEN               : 1 ;  /*!< [10:10] : ADCSOCAOn source select:
                                                                           0: Respective EPWM SOCA output is not selected 1: Respective EPWM SOCA output is selected Reset type: CPU1.SYSRSn */
            __IOM uint32_t PWM12SOCAEN               : 1 ;  /*!< [11:11] : ADCSOCAOn source select:
                                                                           0: Respective EPWM SOCA output is not selected 1: Respective EPWM SOCA output is selected Reset type: CPU1.SYSRSn */
                  uint32_t RSV_0                     : 4 ;  /*!< [15:12] : reserved. */
            __IOM uint32_t PWM1SOCBEN                : 1 ;  /*!< [16:16] : ADCSOCBOn source select:
                                                                           0: Respective EPWM SOCB output is not selected 1: Respective EPWM SOCB output is selected Reset type: CPU1.SYSRSn */
            __IOM uint32_t PWM2SOCBEN                : 1 ;  /*!< [17:17] : ADCSOCBOn source select:
                                                                           0: Respective EPWM SOCB output is not selected 1: Respective EPWM SOCB output is selected Reset type: CPU1.SYSRSn */
            __IOM uint32_t PWM3SOCBEN                : 1 ;  /*!< [18:18] : ADCSOCBOn source select:
                                                                           0: Respective EPWM SOCB output is not selected 1: Respective EPWM SOCB output is selected Reset type: CPU1.SYSRSn */
            __IOM uint32_t PWM4SOCBEN                : 1 ;  /*!< [19:19] : ADCSOCBOn source select:
                                                                           0: Respective EPWM SOCB output is not selected 1: Respective EPWM SOCB output is selected Reset type: CPU1.SYSRSn */
            __IOM uint32_t PWM5SOCBEN                : 1 ;  /*!< [20:20] : ADCSOCBOn source select:
                                                                           0: Respective EPWM SOCB output is not selected 1: Respective EPWM SOCB output is selected Reset type: CPU1.SYSRSn */
            __IOM uint32_t PWM6SOCBEN                : 1 ;  /*!< [21:21] : ADCSOCBOn source select:
                                                                           0: Respective EPWM SOCB output is not selected 1: Respective EPWM SOCB output is selected Reset type: CPU1.SYSRSn */
            __IOM uint32_t PWM7SOCBEN                : 1 ;  /*!< [22:22] : ADCSOCBOn source select:
                                                                           0: Respective EPWM SOCB output is not selected 1: Respective EPWM SOCB output is selected Reset type: CPU1.SYSRSn */
            __IOM uint32_t PWM8SOCBEN                : 1 ;  /*!< [23:23] : ADCSOCBOn source select:
                                                                           0: Respective EPWM SOCB output is not selected 1: Respective EPWM SOCB output is selected Reset type: CPU1.SYSRSn */
            __IOM uint32_t PWM9SOCBEN                : 1 ;  /*!< [24:24] : ADCSOCBOn source select:
                                                                           0: Respective EPWM SOCB output is not selected 1: Respective EPWM SOCB output is selected Reset type: CPU1.SYSRSn */
            __IOM uint32_t PWM10SOCBEN               : 1 ;  /*!< [25:25] : ADCSOCBOn source select:
                                                                           0: Respective EPWM SOCB output is not selected 1: Respective EPWM SOCB output is selected Reset type: CPU1.SYSRSn */
            __IOM uint32_t PWM11SOCBEN               : 1 ;  /*!< [26:26] : ADCSOCBOn source select:
                                                                           0: Respective EPWM SOCB output is not selected 1: Respective EPWM SOCB output is selected Reset type: CPU1.SYSRSn */
            __IOM uint32_t PWM12SOCBEN               : 1 ;  /*!< [27:27] : ADCSOCBOn source select:
                                                                           0: Respective EPWM SOCB output is not selected 1: Respective EPWM SOCB output is selected Reset type: CPU1.SYSRSn */
                  uint32_t RSV_1                     : 4 ;  /*!< [31:28] : reserved. */
        } ADCSOCOUTSELECTb;
    };

    union
    {
        __IOM uint32_t SYNCSOCLOCK                       ;  /*!< 0x00000008 : SYNCSEL and EXTADCSOC Select Lock register */

        struct
        {
            __IOM uint32_t SYNCSELECT                : 1 ;  /*!< [ 0: 0] : SYNCSELECT Register Lock bit:
                                                                           0: Respective register is not locked 1: Respective register is locked.
                                                                           Notes:
                                                                           [1] Any bit in this register, once set can only be creaed through a CPU1.SYSRSn. Write of 0 to any bit of this regtister has no effect
                                                                           [2] The locking mechanism applies to only writes. Reads to the registers which have LOCK protection are always allowed Reset type: CPU1.SYSRSn */
            __IOM uint32_t ADCSOCOUTSELECT           : 1 ;  /*!< [ 1: 1] : ADCSOCOUTSELECT Register Lock bit:
                                                                           0: Respective register is not locked 1: Respective register is locked.
                                                                           Notes:
                                                                           [1] Any bit in this register, once set can only be creaed through a CPU1.SYSRSn. Write of 0 to any bit of this regtister has no effect
                                                                           [2] The locking mechanism applies to only writes. Reads to the registers which have LOCK protection are always allowed Reset type: CPU1.SYSRSn */
                  uint32_t RSV_0                     : 30;  /*!< [31: 2] : reserved. */
        } SYNCSOCLOCKb;
    };

    uint8_t    RSV_0XC[20]                               ;
    union
    {
        __IOM uint32_t SYNCOUTDLYPRD                     ;  /*!< 0x00000020 : SYNCOUT Delay Counter Period Register */

        struct
        {
            __IOM uint32_t DLYPRDPRD                 : 16;  /*!< [15: 0] : SYNCOUT Delay counter period
                                                                           0: Delay 1*Tclk_pwm
                                                                           1: Delay 2*Tclk_pwm
                                                                           ...
                                                                           N: Delay (N+1)*Tclk_pwm
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 16;  /*!< [31:16] : reserved. */
        } SYNCOUTDLYPRDb;
    };

    union
    {
        __IOM uint32_t SOCOUTDLYPRD                      ;  /*!< 0x00000024 : SOC Delay Counter Period Register */

        struct
        {
            __IOM uint32_t SOCADLYPRD                : 16;  /*!< [15: 0] : SOCAOUT Delay counter period
                                                                           0: Delay 1*Tclk_pwm
                                                                           1: Delay 2*Tclk_pwm
                                                                           ...
                                                                           N: Delay (N+1)*Tclk_pwm
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SOCBDLYPRD                : 16;  /*!< [31:16] : SOCBOUT Delay counter period
                                                                           0: Delay 1*Tclk_pwm
                                                                           1: Delay 2*Tclk_pwm
                                                                           ...
                                                                           N: Delay (N+1)*Tclk_pwm
                                                                           Reset type: SYSRSn */
        } SOCOUTDLYPRDb;
    };

    uint8_t    RSV_0X28[472]                             ;
} SYNC_SOC_Type;

/*! \brief HRCAL register */
typedef struct {
    union
    {
        __IOM uint32_t HRCALCFG                          ;  /*!< 0x00000000 : High Resolution Calibration Configuration Register */

        struct
        {
            __IOM uint32_t HRCALEN                   : 1 ;  /*!< [ 0: 0] : ADCSOCBOn source select:
                                                                           0: High Resolution calibration is disable
                                                                           1: High Resolution calibration is enable
                                                                           Reset type: SYSRSn */
            __IOM uint32_t ACCSEL                    : 4 ;  /*!< [ 4: 1] : Select accumulator bit width:
                                                                           0: Select [7:0] bits
                                                                           1: Select [8:1] bits
                                                                           2: Select [9:2] bits
                                                                           3: Select [10:3] bits
                                                                           4: Select [11:4] bits
                                                                           5: Select [12:5] bits
                                                                           6: Select [13:6] bits
                                                                           7: Select [14:7] bits
                                                                           8: Select [15:8] bits
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 3 ;  /*!< [ 7: 5] : reserved. */
            __IOM uint32_t SYNCPERSEL                : 4 ;  /*!< [11: 8] : Select epwm syncper:
                                                                           1: Select epwm1 syncper
                                                                           2: Select epwm2 syncper
                                                                           3: Select epwm3 syncper
                                                                           4: Select epwm4 syncper
                                                                           5: Select epwm5 syncper
                                                                           6: Select epwm6 syncper
                                                                           7: Select epwm7 syncper
                                                                           8: Select epwm8 syncper
                                                                           9: Select epwm9 syncper
                                                                           10: Select epwm10 syncper
                                                                           11: Select epwm11 syncper
                                                                           12: Select epwm12 syncper
                                                                           Other: Reserved
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SWUP                      : 1 ;  /*!< [12:12] : Software force update MEP
                                                                           0: Writing a 0 (zero) has no effect. Always reads back a 0.
                                                                           1: Initiates a single software update event.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_1                     : 3 ;  /*!< [15:13] : reserved. */
            __IOM uint32_t UPMODE                    : 2 ;  /*!< [17:16] : Update mode
                                                                           00: Use hrcal counter
                                                                           01: Use pwm syncper
                                                                           10: Use software
                                                                           11: Reserved
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_2                     : 14;  /*!< [31:18] : reserved. */
        } HRCALCFGb;
    };

    union
    {
        __IOM uint32_t HRCALCTRPRD                       ;  /*!< 0x00000004 : High Resolution Calibration Counter Period Register Register */

        struct
        {
            __IOM uint32_t CTRPRD                    : 32;  /*!< [31: 0] : Update when hrcal counter counts to period. */
        } HRCALCTRPRDb;
    };

    union
    {
        __IM  uint32_t HRMSTEP                           ;  /*!< 0x00000008 : High Resolution Calibration MEP Step Register */

        struct
        {
            __IM  uint32_t HRMSTEP                   : 8 ;  /*!< [ 7: 0] : High resolution MEP step
                                                                           When auto-conversion is enabled (HRCNFG[AUTOCONV] = 1), This
                                                                           8-bit field contains the MEP_ScaleFactor (number of MEP steps per
                                                                           coarse steps) used by the hardware to automatically convert the
                                                                           value in the CMPAHR, CMPBHR, DBFEDHR, DBREDHR ,
                                                                           TBPHSHR, or TBPRDHR register to a scaled micro-edge delay on
                                                                           the high-resolution ePWM output. The value in this register is written
                                                                           by the SFO calibration software at the end of each calibration run.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 24;  /*!< [31: 8] : reserved. */
        } HRMSTEPb;
    };

    union
    {
        __IOM uint32_t HRCALINT                          ;  /*!< 0x0000000c : High Resolution Calibration Interrupt Register */

        struct
        {
            __IOM uint32_t CALEREN                   : 1 ;  /*!< [ 0: 0] : High resolution calibration enable
                                                                           0: Disable
                                                                           1: Enable */
                  uint32_t RSV_0                     : 7 ;  /*!< [ 7: 1] : reserved. */
            __IM  uint32_t CALERSTS                  : 2 ;  /*!< [ 9: 8] : High resolution calibration error status flag
                                                                           00: Indicates no error event has occurred on high resolution calibration
                                                                           01: Indicates overflow error event has occurred on high resolution calibration
                                                                           10: Indicates underflow error event has occurred on high resolution calibration
                                                                           11: Reserved
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_1                     : 6 ;  /*!< [15:10] : reserved. */
            __IOM uint32_t CALERCLR                  : 1 ;  /*!< [16:16] : High resolution calibration error status clear flag
                                                                           0: Indicates no error event has occurred on high resolution calibration
                                                                           1: Indicates error event has occurred on high resolution calibration
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_2                     : 15;  /*!< [31:17] : reserved. */
        } HRCALINTb;
    };

    union
    {
        __IOM uint32_t HRCALSTEPCFG                      ;  /*!< 0x00000010 : High Resolution Calibration Step Value Config Register */

        struct
        {
            __IOM uint32_t STEPMODE                  : 1 ;  /*!< [ 0: 0] : High resolution calibration step value adjustment
                                                                           0: Step value always equals 1
                                                                           1: Step value is divided into coarse step value and fine step value, first use coarse step value, and then use fine step value after the first change of increase/decrease status */
                  uint32_t RSV_0                     : 7 ;  /*!< [ 7: 1] : reserved. */
            __IOM uint32_t CSTEPVAL                  : 4 ;  /*!< [11: 8] : High resolution calibration coarse step value
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_1                     : 4 ;  /*!< [15:12] : reserved. */
            __IOM uint32_t FSTEPVAL                  : 4 ;  /*!< [19:16] : High resolution calibration fine step value
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_2                     : 12;  /*!< [31:20] : reserved. */
        } HRCALSTEPCFGb;
    };

    union
    {
        __IOM uint32_t HRCALSTORECFG                     ;  /*!< 0x00000014 : High Resolution Calibration Storage Config Register */

        struct
        {
            __IOM uint32_t STOREMODE                 : 3 ;  /*!< [ 2: 0] : High resolution calibration data storage number
                                                                           0: Store 4 data
                                                                           1: Store 8 data
                                                                           2: Store 16 data
                                                                           3: Store 32 data
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 5 ;  /*!< [ 7: 3] : reserved. */
            __IOM uint32_t THRESH                    : 4 ;  /*!< [11: 8] : Threshold value.
                                                                           Average every storage number of data and subtract it from the current data.
                                                                           The difference is compared with the threshold value.
                                                                           If it is less than the threshold value, it means it is locked.
                                                                           If it is greater than or equal to the threshold value, it means it is not locked.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_1                     : 4 ;  /*!< [15:12] : reserved. */
            __IOM uint32_t INIT                      : 1 ;  /*!< [16:16] : High resolution calibration coarse step value
                                                                           After switching storage mode or threshold, carry out an initialization.
                                                                           0: No effect
                                                                           1: Initialize storage status
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_2                     : 7 ;  /*!< [23:17] : reserved. */
            __IM  uint32_t LOCKSTS                   : 1 ;  /*!< [24:24] : High resolution calibration lock status.
                                                                           0: unlocked
                                                                           1: locked
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_3                     : 7 ;  /*!< [31:25] : reserved. */
        } HRCALSTORECFGb;
    };

    union
    {
        __IOM uint32_t HRCALLOCK                         ;  /*!< 0x00000018 : High Resolution Calibration Lock register */

        struct
        {
                  uint32_t RSV_0                     : 24;  /*!< [23: 0] : reserved. */
            __IOM uint32_t HRCALLOCK                 : 1 ;  /*!< [24:24] : HRCAL Register Lock bit:
                                                                           0: Respective register is not locked
                                                                           1: Respective register is locked.
                                                                           Reset type: PORESETn */
                  uint32_t RSV_1                     : 7 ;  /*!< [31:25] : reserved. */
        } HRCALLOCKb;
    };

    uint8_t    RSV_0X21C[484]                            ;
} HRCAL_Type;


/*!
 * @}
 */

/*!
 * \name SYNCSOC Base Address Definitions
 *
 * @{
 */

/*! \brief SYNC_SOC base address */
#define SYNC_SOC_BASE (0x40500000UL)
/*! \brief SYNC_SOC base pointer */
#define SYNC_SOC ((SYNC_SOC_Type *) SYNC_SOC_BASE)

/*! \brief HRCAL base address */
#define HRCAL_BASE (0x40500200UL)
/*! \brief HRCAL base pointer */
#define HRCAL ((HRCAL_Type *) HRCAL_BASE)


/*!
 * @}
 */


/*!
 * \name SYNCSOC Register Bitfield Definitions
 *
 * @{
 */

/* SYNCSELECT bitfield */
#define SYNC_SOC_SYNCSELECT_SYNCOUT_Pos     (24U)                                                                                     /*!< SYNCOUT Position 24 */
#define SYNC_SOC_SYNCSELECT_SYNCOUT_Msk     (0x1fU << SYNC_SOC_SYNCSELECT_SYNCOUT_Pos)                                                /*!< SYNCOUT Mask 0x1F000000 */
#define SYNC_SOC_SYNCSELECT_SYNCOUT_Set(x)  (((uint32_t) (x) << SYNC_SOC_SYNCSELECT_SYNCOUT_Pos) & SYNC_SOC_SYNCSELECT_SYNCOUT_Msk)   /*!< SYNCOUT Set Value */
#define SYNC_SOC_SYNCSELECT_SYNCOUT_Get(x)  (((uint32_t) (x) & SYNC_SOC_SYNCSELECT_SYNCOUT_Msk) >> SYNC_SOC_SYNCSELECT_SYNCOUT_Pos)   /*!< SYNCOUT Get Value */

/* ADCSOCOUTSELECT bitfield */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM12SOCBEN_Pos     (27U)                                                                                                       /*!< PWM12SOCBEN Position 27 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM12SOCBEN_Msk     (0x1U << SYNC_SOC_ADCSOCOUTSELECT_PWM12SOCBEN_Pos)                                                          /*!< PWM12SOCBEN Mask 0x08000000 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM12SOCBEN_Set(x)  (((uint32_t) (x) << SYNC_SOC_ADCSOCOUTSELECT_PWM12SOCBEN_Pos) & SYNC_SOC_ADCSOCOUTSELECT_PWM12SOCBEN_Msk)   /*!< PWM12SOCBEN Set Value */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM12SOCBEN_Get(x)  (((uint32_t) (x) & SYNC_SOC_ADCSOCOUTSELECT_PWM12SOCBEN_Msk) >> SYNC_SOC_ADCSOCOUTSELECT_PWM12SOCBEN_Pos)   /*!< PWM12SOCBEN Get Value */

#define SYNC_SOC_ADCSOCOUTSELECT_PWM11SOCBEN_Pos     (26U)                                                                                                       /*!< PWM11SOCBEN Position 26 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM11SOCBEN_Msk     (0x1U << SYNC_SOC_ADCSOCOUTSELECT_PWM11SOCBEN_Pos)                                                          /*!< PWM11SOCBEN Mask 0x04000000 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM11SOCBEN_Set(x)  (((uint32_t) (x) << SYNC_SOC_ADCSOCOUTSELECT_PWM11SOCBEN_Pos) & SYNC_SOC_ADCSOCOUTSELECT_PWM11SOCBEN_Msk)   /*!< PWM11SOCBEN Set Value */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM11SOCBEN_Get(x)  (((uint32_t) (x) & SYNC_SOC_ADCSOCOUTSELECT_PWM11SOCBEN_Msk) >> SYNC_SOC_ADCSOCOUTSELECT_PWM11SOCBEN_Pos)   /*!< PWM11SOCBEN Get Value */

#define SYNC_SOC_ADCSOCOUTSELECT_PWM10SOCBEN_Pos     (25U)                                                                                                       /*!< PWM10SOCBEN Position 25 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM10SOCBEN_Msk     (0x1U << SYNC_SOC_ADCSOCOUTSELECT_PWM10SOCBEN_Pos)                                                          /*!< PWM10SOCBEN Mask 0x02000000 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM10SOCBEN_Set(x)  (((uint32_t) (x) << SYNC_SOC_ADCSOCOUTSELECT_PWM10SOCBEN_Pos) & SYNC_SOC_ADCSOCOUTSELECT_PWM10SOCBEN_Msk)   /*!< PWM10SOCBEN Set Value */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM10SOCBEN_Get(x)  (((uint32_t) (x) & SYNC_SOC_ADCSOCOUTSELECT_PWM10SOCBEN_Msk) >> SYNC_SOC_ADCSOCOUTSELECT_PWM10SOCBEN_Pos)   /*!< PWM10SOCBEN Get Value */

#define SYNC_SOC_ADCSOCOUTSELECT_PWM9SOCBEN_Pos     (24U)                                                                                                     /*!< PWM9SOCBEN Position 24 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM9SOCBEN_Msk     (0x1U << SYNC_SOC_ADCSOCOUTSELECT_PWM9SOCBEN_Pos)                                                         /*!< PWM9SOCBEN Mask 0x01000000 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM9SOCBEN_Set(x)  (((uint32_t) (x) << SYNC_SOC_ADCSOCOUTSELECT_PWM9SOCBEN_Pos) & SYNC_SOC_ADCSOCOUTSELECT_PWM9SOCBEN_Msk)   /*!< PWM9SOCBEN Set Value */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM9SOCBEN_Get(x)  (((uint32_t) (x) & SYNC_SOC_ADCSOCOUTSELECT_PWM9SOCBEN_Msk) >> SYNC_SOC_ADCSOCOUTSELECT_PWM9SOCBEN_Pos)   /*!< PWM9SOCBEN Get Value */

#define SYNC_SOC_ADCSOCOUTSELECT_PWM8SOCBEN_Pos     (23U)                                                                                                     /*!< PWM8SOCBEN Position 23 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM8SOCBEN_Msk     (0x1U << SYNC_SOC_ADCSOCOUTSELECT_PWM8SOCBEN_Pos)                                                         /*!< PWM8SOCBEN Mask 0x00800000 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM8SOCBEN_Set(x)  (((uint32_t) (x) << SYNC_SOC_ADCSOCOUTSELECT_PWM8SOCBEN_Pos) & SYNC_SOC_ADCSOCOUTSELECT_PWM8SOCBEN_Msk)   /*!< PWM8SOCBEN Set Value */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM8SOCBEN_Get(x)  (((uint32_t) (x) & SYNC_SOC_ADCSOCOUTSELECT_PWM8SOCBEN_Msk) >> SYNC_SOC_ADCSOCOUTSELECT_PWM8SOCBEN_Pos)   /*!< PWM8SOCBEN Get Value */

#define SYNC_SOC_ADCSOCOUTSELECT_PWM7SOCBEN_Pos     (22U)                                                                                                     /*!< PWM7SOCBEN Position 22 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM7SOCBEN_Msk     (0x1U << SYNC_SOC_ADCSOCOUTSELECT_PWM7SOCBEN_Pos)                                                         /*!< PWM7SOCBEN Mask 0x00400000 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM7SOCBEN_Set(x)  (((uint32_t) (x) << SYNC_SOC_ADCSOCOUTSELECT_PWM7SOCBEN_Pos) & SYNC_SOC_ADCSOCOUTSELECT_PWM7SOCBEN_Msk)   /*!< PWM7SOCBEN Set Value */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM7SOCBEN_Get(x)  (((uint32_t) (x) & SYNC_SOC_ADCSOCOUTSELECT_PWM7SOCBEN_Msk) >> SYNC_SOC_ADCSOCOUTSELECT_PWM7SOCBEN_Pos)   /*!< PWM7SOCBEN Get Value */

#define SYNC_SOC_ADCSOCOUTSELECT_PWM6SOCBEN_Pos     (21U)                                                                                                     /*!< PWM6SOCBEN Position 21 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM6SOCBEN_Msk     (0x1U << SYNC_SOC_ADCSOCOUTSELECT_PWM6SOCBEN_Pos)                                                         /*!< PWM6SOCBEN Mask 0x00200000 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM6SOCBEN_Set(x)  (((uint32_t) (x) << SYNC_SOC_ADCSOCOUTSELECT_PWM6SOCBEN_Pos) & SYNC_SOC_ADCSOCOUTSELECT_PWM6SOCBEN_Msk)   /*!< PWM6SOCBEN Set Value */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM6SOCBEN_Get(x)  (((uint32_t) (x) & SYNC_SOC_ADCSOCOUTSELECT_PWM6SOCBEN_Msk) >> SYNC_SOC_ADCSOCOUTSELECT_PWM6SOCBEN_Pos)   /*!< PWM6SOCBEN Get Value */

#define SYNC_SOC_ADCSOCOUTSELECT_PWM5SOCBEN_Pos     (20U)                                                                                                     /*!< PWM5SOCBEN Position 20 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM5SOCBEN_Msk     (0x1U << SYNC_SOC_ADCSOCOUTSELECT_PWM5SOCBEN_Pos)                                                         /*!< PWM5SOCBEN Mask 0x00100000 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM5SOCBEN_Set(x)  (((uint32_t) (x) << SYNC_SOC_ADCSOCOUTSELECT_PWM5SOCBEN_Pos) & SYNC_SOC_ADCSOCOUTSELECT_PWM5SOCBEN_Msk)   /*!< PWM5SOCBEN Set Value */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM5SOCBEN_Get(x)  (((uint32_t) (x) & SYNC_SOC_ADCSOCOUTSELECT_PWM5SOCBEN_Msk) >> SYNC_SOC_ADCSOCOUTSELECT_PWM5SOCBEN_Pos)   /*!< PWM5SOCBEN Get Value */

#define SYNC_SOC_ADCSOCOUTSELECT_PWM4SOCBEN_Pos     (19U)                                                                                                     /*!< PWM4SOCBEN Position 19 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM4SOCBEN_Msk     (0x1U << SYNC_SOC_ADCSOCOUTSELECT_PWM4SOCBEN_Pos)                                                         /*!< PWM4SOCBEN Mask 0x00080000 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM4SOCBEN_Set(x)  (((uint32_t) (x) << SYNC_SOC_ADCSOCOUTSELECT_PWM4SOCBEN_Pos) & SYNC_SOC_ADCSOCOUTSELECT_PWM4SOCBEN_Msk)   /*!< PWM4SOCBEN Set Value */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM4SOCBEN_Get(x)  (((uint32_t) (x) & SYNC_SOC_ADCSOCOUTSELECT_PWM4SOCBEN_Msk) >> SYNC_SOC_ADCSOCOUTSELECT_PWM4SOCBEN_Pos)   /*!< PWM4SOCBEN Get Value */

#define SYNC_SOC_ADCSOCOUTSELECT_PWM3SOCBEN_Pos     (18U)                                                                                                     /*!< PWM3SOCBEN Position 18 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM3SOCBEN_Msk     (0x1U << SYNC_SOC_ADCSOCOUTSELECT_PWM3SOCBEN_Pos)                                                         /*!< PWM3SOCBEN Mask 0x00040000 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM3SOCBEN_Set(x)  (((uint32_t) (x) << SYNC_SOC_ADCSOCOUTSELECT_PWM3SOCBEN_Pos) & SYNC_SOC_ADCSOCOUTSELECT_PWM3SOCBEN_Msk)   /*!< PWM3SOCBEN Set Value */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM3SOCBEN_Get(x)  (((uint32_t) (x) & SYNC_SOC_ADCSOCOUTSELECT_PWM3SOCBEN_Msk) >> SYNC_SOC_ADCSOCOUTSELECT_PWM3SOCBEN_Pos)   /*!< PWM3SOCBEN Get Value */

#define SYNC_SOC_ADCSOCOUTSELECT_PWM2SOCBEN_Pos     (17U)                                                                                                     /*!< PWM2SOCBEN Position 17 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM2SOCBEN_Msk     (0x1U << SYNC_SOC_ADCSOCOUTSELECT_PWM2SOCBEN_Pos)                                                         /*!< PWM2SOCBEN Mask 0x00020000 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM2SOCBEN_Set(x)  (((uint32_t) (x) << SYNC_SOC_ADCSOCOUTSELECT_PWM2SOCBEN_Pos) & SYNC_SOC_ADCSOCOUTSELECT_PWM2SOCBEN_Msk)   /*!< PWM2SOCBEN Set Value */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM2SOCBEN_Get(x)  (((uint32_t) (x) & SYNC_SOC_ADCSOCOUTSELECT_PWM2SOCBEN_Msk) >> SYNC_SOC_ADCSOCOUTSELECT_PWM2SOCBEN_Pos)   /*!< PWM2SOCBEN Get Value */

#define SYNC_SOC_ADCSOCOUTSELECT_PWM1SOCBEN_Pos     (16U)                                                                                                     /*!< PWM1SOCBEN Position 16 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM1SOCBEN_Msk     (0x1U << SYNC_SOC_ADCSOCOUTSELECT_PWM1SOCBEN_Pos)                                                         /*!< PWM1SOCBEN Mask 0x00010000 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM1SOCBEN_Set(x)  (((uint32_t) (x) << SYNC_SOC_ADCSOCOUTSELECT_PWM1SOCBEN_Pos) & SYNC_SOC_ADCSOCOUTSELECT_PWM1SOCBEN_Msk)   /*!< PWM1SOCBEN Set Value */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM1SOCBEN_Get(x)  (((uint32_t) (x) & SYNC_SOC_ADCSOCOUTSELECT_PWM1SOCBEN_Msk) >> SYNC_SOC_ADCSOCOUTSELECT_PWM1SOCBEN_Pos)   /*!< PWM1SOCBEN Get Value */

#define SYNC_SOC_ADCSOCOUTSELECT_PWM12SOCAEN_Pos     (11U)                                                                                                       /*!< PWM12SOCAEN Position 11 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM12SOCAEN_Msk     (0x1U << SYNC_SOC_ADCSOCOUTSELECT_PWM12SOCAEN_Pos)                                                          /*!< PWM12SOCAEN Mask 0x00000800 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM12SOCAEN_Set(x)  (((uint32_t) (x) << SYNC_SOC_ADCSOCOUTSELECT_PWM12SOCAEN_Pos) & SYNC_SOC_ADCSOCOUTSELECT_PWM12SOCAEN_Msk)   /*!< PWM12SOCAEN Set Value */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM12SOCAEN_Get(x)  (((uint32_t) (x) & SYNC_SOC_ADCSOCOUTSELECT_PWM12SOCAEN_Msk) >> SYNC_SOC_ADCSOCOUTSELECT_PWM12SOCAEN_Pos)   /*!< PWM12SOCAEN Get Value */

#define SYNC_SOC_ADCSOCOUTSELECT_PWM11SOCAEN_Pos     (10U)                                                                                                       /*!< PWM11SOCAEN Position 10 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM11SOCAEN_Msk     (0x1U << SYNC_SOC_ADCSOCOUTSELECT_PWM11SOCAEN_Pos)                                                          /*!< PWM11SOCAEN Mask 0x00000400 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM11SOCAEN_Set(x)  (((uint32_t) (x) << SYNC_SOC_ADCSOCOUTSELECT_PWM11SOCAEN_Pos) & SYNC_SOC_ADCSOCOUTSELECT_PWM11SOCAEN_Msk)   /*!< PWM11SOCAEN Set Value */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM11SOCAEN_Get(x)  (((uint32_t) (x) & SYNC_SOC_ADCSOCOUTSELECT_PWM11SOCAEN_Msk) >> SYNC_SOC_ADCSOCOUTSELECT_PWM11SOCAEN_Pos)   /*!< PWM11SOCAEN Get Value */

#define SYNC_SOC_ADCSOCOUTSELECT_PWM10SOCAEN_Pos     (9U)                                                                                                        /*!< PWM10SOCAEN Position 9 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM10SOCAEN_Msk     (0x1U << SYNC_SOC_ADCSOCOUTSELECT_PWM10SOCAEN_Pos)                                                          /*!< PWM10SOCAEN Mask 0x00000200 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM10SOCAEN_Set(x)  (((uint32_t) (x) << SYNC_SOC_ADCSOCOUTSELECT_PWM10SOCAEN_Pos) & SYNC_SOC_ADCSOCOUTSELECT_PWM10SOCAEN_Msk)   /*!< PWM10SOCAEN Set Value */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM10SOCAEN_Get(x)  (((uint32_t) (x) & SYNC_SOC_ADCSOCOUTSELECT_PWM10SOCAEN_Msk) >> SYNC_SOC_ADCSOCOUTSELECT_PWM10SOCAEN_Pos)   /*!< PWM10SOCAEN Get Value */

#define SYNC_SOC_ADCSOCOUTSELECT_PWM9SOCAEN_Pos     (8U)                                                                                                      /*!< PWM9SOCAEN Position 8 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM9SOCAEN_Msk     (0x1U << SYNC_SOC_ADCSOCOUTSELECT_PWM9SOCAEN_Pos)                                                         /*!< PWM9SOCAEN Mask 0x00000100 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM9SOCAEN_Set(x)  (((uint32_t) (x) << SYNC_SOC_ADCSOCOUTSELECT_PWM9SOCAEN_Pos) & SYNC_SOC_ADCSOCOUTSELECT_PWM9SOCAEN_Msk)   /*!< PWM9SOCAEN Set Value */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM9SOCAEN_Get(x)  (((uint32_t) (x) & SYNC_SOC_ADCSOCOUTSELECT_PWM9SOCAEN_Msk) >> SYNC_SOC_ADCSOCOUTSELECT_PWM9SOCAEN_Pos)   /*!< PWM9SOCAEN Get Value */

#define SYNC_SOC_ADCSOCOUTSELECT_PWM8SOCAEN_Pos     (7U)                                                                                                      /*!< PWM8SOCAEN Position 7 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM8SOCAEN_Msk     (0x1U << SYNC_SOC_ADCSOCOUTSELECT_PWM8SOCAEN_Pos)                                                         /*!< PWM8SOCAEN Mask 0x00000080 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM8SOCAEN_Set(x)  (((uint32_t) (x) << SYNC_SOC_ADCSOCOUTSELECT_PWM8SOCAEN_Pos) & SYNC_SOC_ADCSOCOUTSELECT_PWM8SOCAEN_Msk)   /*!< PWM8SOCAEN Set Value */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM8SOCAEN_Get(x)  (((uint32_t) (x) & SYNC_SOC_ADCSOCOUTSELECT_PWM8SOCAEN_Msk) >> SYNC_SOC_ADCSOCOUTSELECT_PWM8SOCAEN_Pos)   /*!< PWM8SOCAEN Get Value */

#define SYNC_SOC_ADCSOCOUTSELECT_PWM7SOCAEN_Pos     (6U)                                                                                                      /*!< PWM7SOCAEN Position 6 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM7SOCAEN_Msk     (0x1U << SYNC_SOC_ADCSOCOUTSELECT_PWM7SOCAEN_Pos)                                                         /*!< PWM7SOCAEN Mask 0x00000040 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM7SOCAEN_Set(x)  (((uint32_t) (x) << SYNC_SOC_ADCSOCOUTSELECT_PWM7SOCAEN_Pos) & SYNC_SOC_ADCSOCOUTSELECT_PWM7SOCAEN_Msk)   /*!< PWM7SOCAEN Set Value */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM7SOCAEN_Get(x)  (((uint32_t) (x) & SYNC_SOC_ADCSOCOUTSELECT_PWM7SOCAEN_Msk) >> SYNC_SOC_ADCSOCOUTSELECT_PWM7SOCAEN_Pos)   /*!< PWM7SOCAEN Get Value */

#define SYNC_SOC_ADCSOCOUTSELECT_PWM6SOCAEN_Pos     (5U)                                                                                                      /*!< PWM6SOCAEN Position 5 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM6SOCAEN_Msk     (0x1U << SYNC_SOC_ADCSOCOUTSELECT_PWM6SOCAEN_Pos)                                                         /*!< PWM6SOCAEN Mask 0x00000020 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM6SOCAEN_Set(x)  (((uint32_t) (x) << SYNC_SOC_ADCSOCOUTSELECT_PWM6SOCAEN_Pos) & SYNC_SOC_ADCSOCOUTSELECT_PWM6SOCAEN_Msk)   /*!< PWM6SOCAEN Set Value */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM6SOCAEN_Get(x)  (((uint32_t) (x) & SYNC_SOC_ADCSOCOUTSELECT_PWM6SOCAEN_Msk) >> SYNC_SOC_ADCSOCOUTSELECT_PWM6SOCAEN_Pos)   /*!< PWM6SOCAEN Get Value */

#define SYNC_SOC_ADCSOCOUTSELECT_PWM5SOCAEN_Pos     (4U)                                                                                                      /*!< PWM5SOCAEN Position 4 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM5SOCAEN_Msk     (0x1U << SYNC_SOC_ADCSOCOUTSELECT_PWM5SOCAEN_Pos)                                                         /*!< PWM5SOCAEN Mask 0x00000010 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM5SOCAEN_Set(x)  (((uint32_t) (x) << SYNC_SOC_ADCSOCOUTSELECT_PWM5SOCAEN_Pos) & SYNC_SOC_ADCSOCOUTSELECT_PWM5SOCAEN_Msk)   /*!< PWM5SOCAEN Set Value */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM5SOCAEN_Get(x)  (((uint32_t) (x) & SYNC_SOC_ADCSOCOUTSELECT_PWM5SOCAEN_Msk) >> SYNC_SOC_ADCSOCOUTSELECT_PWM5SOCAEN_Pos)   /*!< PWM5SOCAEN Get Value */

#define SYNC_SOC_ADCSOCOUTSELECT_PWM4SOCAEN_Pos     (3U)                                                                                                      /*!< PWM4SOCAEN Position 3 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM4SOCAEN_Msk     (0x1U << SYNC_SOC_ADCSOCOUTSELECT_PWM4SOCAEN_Pos)                                                         /*!< PWM4SOCAEN Mask 0x00000008 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM4SOCAEN_Set(x)  (((uint32_t) (x) << SYNC_SOC_ADCSOCOUTSELECT_PWM4SOCAEN_Pos) & SYNC_SOC_ADCSOCOUTSELECT_PWM4SOCAEN_Msk)   /*!< PWM4SOCAEN Set Value */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM4SOCAEN_Get(x)  (((uint32_t) (x) & SYNC_SOC_ADCSOCOUTSELECT_PWM4SOCAEN_Msk) >> SYNC_SOC_ADCSOCOUTSELECT_PWM4SOCAEN_Pos)   /*!< PWM4SOCAEN Get Value */

#define SYNC_SOC_ADCSOCOUTSELECT_PWM3SOCAEN_Pos     (2U)                                                                                                      /*!< PWM3SOCAEN Position 2 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM3SOCAEN_Msk     (0x1U << SYNC_SOC_ADCSOCOUTSELECT_PWM3SOCAEN_Pos)                                                         /*!< PWM3SOCAEN Mask 0x00000004 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM3SOCAEN_Set(x)  (((uint32_t) (x) << SYNC_SOC_ADCSOCOUTSELECT_PWM3SOCAEN_Pos) & SYNC_SOC_ADCSOCOUTSELECT_PWM3SOCAEN_Msk)   /*!< PWM3SOCAEN Set Value */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM3SOCAEN_Get(x)  (((uint32_t) (x) & SYNC_SOC_ADCSOCOUTSELECT_PWM3SOCAEN_Msk) >> SYNC_SOC_ADCSOCOUTSELECT_PWM3SOCAEN_Pos)   /*!< PWM3SOCAEN Get Value */

#define SYNC_SOC_ADCSOCOUTSELECT_PWM2SOCAEN_Pos     (1U)                                                                                                      /*!< PWM2SOCAEN Position 1 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM2SOCAEN_Msk     (0x1U << SYNC_SOC_ADCSOCOUTSELECT_PWM2SOCAEN_Pos)                                                         /*!< PWM2SOCAEN Mask 0x00000002 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM2SOCAEN_Set(x)  (((uint32_t) (x) << SYNC_SOC_ADCSOCOUTSELECT_PWM2SOCAEN_Pos) & SYNC_SOC_ADCSOCOUTSELECT_PWM2SOCAEN_Msk)   /*!< PWM2SOCAEN Set Value */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM2SOCAEN_Get(x)  (((uint32_t) (x) & SYNC_SOC_ADCSOCOUTSELECT_PWM2SOCAEN_Msk) >> SYNC_SOC_ADCSOCOUTSELECT_PWM2SOCAEN_Pos)   /*!< PWM2SOCAEN Get Value */

#define SYNC_SOC_ADCSOCOUTSELECT_PWM1SOCAEN_Pos     (0U)                                                                                                      /*!< PWM1SOCAEN Position 0 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM1SOCAEN_Msk     (0x1U << SYNC_SOC_ADCSOCOUTSELECT_PWM1SOCAEN_Pos)                                                         /*!< PWM1SOCAEN Mask 0x00000001 */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM1SOCAEN_Set(x)  (((uint32_t) (x) << SYNC_SOC_ADCSOCOUTSELECT_PWM1SOCAEN_Pos) & SYNC_SOC_ADCSOCOUTSELECT_PWM1SOCAEN_Msk)   /*!< PWM1SOCAEN Set Value */
#define SYNC_SOC_ADCSOCOUTSELECT_PWM1SOCAEN_Get(x)  (((uint32_t) (x) & SYNC_SOC_ADCSOCOUTSELECT_PWM1SOCAEN_Msk) >> SYNC_SOC_ADCSOCOUTSELECT_PWM1SOCAEN_Pos)   /*!< PWM1SOCAEN Get Value */

/* SYNCSOCLOCK bitfield */
#define SYNC_SOC_SYNCSOCLOCK_ADCSOCOUTSELECT_Pos     (1U)                                                                                                        /*!< ADCSOCOUTSELECT Position 1 */
#define SYNC_SOC_SYNCSOCLOCK_ADCSOCOUTSELECT_Msk     (0x1U << SYNC_SOC_SYNCSOCLOCK_ADCSOCOUTSELECT_Pos)                                                          /*!< ADCSOCOUTSELECT Mask 0x00000002 */
#define SYNC_SOC_SYNCSOCLOCK_ADCSOCOUTSELECT_Set(x)  (((uint32_t) (x) << SYNC_SOC_SYNCSOCLOCK_ADCSOCOUTSELECT_Pos) & SYNC_SOC_SYNCSOCLOCK_ADCSOCOUTSELECT_Msk)   /*!< ADCSOCOUTSELECT Set Value */
#define SYNC_SOC_SYNCSOCLOCK_ADCSOCOUTSELECT_Get(x)  (((uint32_t) (x) & SYNC_SOC_SYNCSOCLOCK_ADCSOCOUTSELECT_Msk) >> SYNC_SOC_SYNCSOCLOCK_ADCSOCOUTSELECT_Pos)   /*!< ADCSOCOUTSELECT Get Value */

#define SYNC_SOC_SYNCSOCLOCK_SYNCSELECT_Pos     (0U)                                                                                              /*!< SYNCSELECT Position 0 */
#define SYNC_SOC_SYNCSOCLOCK_SYNCSELECT_Msk     (0x1U << SYNC_SOC_SYNCSOCLOCK_SYNCSELECT_Pos)                                                     /*!< SYNCSELECT Mask 0x00000001 */
#define SYNC_SOC_SYNCSOCLOCK_SYNCSELECT_Set(x)  (((uint32_t) (x) << SYNC_SOC_SYNCSOCLOCK_SYNCSELECT_Pos) & SYNC_SOC_SYNCSOCLOCK_SYNCSELECT_Msk)   /*!< SYNCSELECT Set Value */
#define SYNC_SOC_SYNCSOCLOCK_SYNCSELECT_Get(x)  (((uint32_t) (x) & SYNC_SOC_SYNCSOCLOCK_SYNCSELECT_Msk) >> SYNC_SOC_SYNCSOCLOCK_SYNCSELECT_Pos)   /*!< SYNCSELECT Get Value */

/* SYNCOUTDLYPRD bitfield */
#define SYNC_SOC_SYNCOUTDLYPRD_DLYPRDPRD_Pos     (0U)                                                                                                /*!< DLYPRDPRD Position 0 */
#define SYNC_SOC_SYNCOUTDLYPRD_DLYPRDPRD_Msk     (0xffffU << SYNC_SOC_SYNCOUTDLYPRD_DLYPRDPRD_Pos)                                                   /*!< DLYPRDPRD Mask 0x0000FFFF */
#define SYNC_SOC_SYNCOUTDLYPRD_DLYPRDPRD_Set(x)  (((uint32_t) (x) << SYNC_SOC_SYNCOUTDLYPRD_DLYPRDPRD_Pos) & SYNC_SOC_SYNCOUTDLYPRD_DLYPRDPRD_Msk)   /*!< DLYPRDPRD Set Value */
#define SYNC_SOC_SYNCOUTDLYPRD_DLYPRDPRD_Get(x)  (((uint32_t) (x) & SYNC_SOC_SYNCOUTDLYPRD_DLYPRDPRD_Msk) >> SYNC_SOC_SYNCOUTDLYPRD_DLYPRDPRD_Pos)   /*!< DLYPRDPRD Get Value */

/* SOCOUTDLYPRD bitfield */
#define SYNC_SOC_SOCOUTDLYPRD_SOCBDLYPRD_Pos     (16U)                                                                                               /*!< SOCBDLYPRD Position 16 */
#define SYNC_SOC_SOCOUTDLYPRD_SOCBDLYPRD_Msk     (0xffffU << SYNC_SOC_SOCOUTDLYPRD_SOCBDLYPRD_Pos)                                                   /*!< SOCBDLYPRD Mask 0xFFFF0000 */
#define SYNC_SOC_SOCOUTDLYPRD_SOCBDLYPRD_Set(x)  (((uint32_t) (x) << SYNC_SOC_SOCOUTDLYPRD_SOCBDLYPRD_Pos) & SYNC_SOC_SOCOUTDLYPRD_SOCBDLYPRD_Msk)   /*!< SOCBDLYPRD Set Value */
#define SYNC_SOC_SOCOUTDLYPRD_SOCBDLYPRD_Get(x)  (((uint32_t) (x) & SYNC_SOC_SOCOUTDLYPRD_SOCBDLYPRD_Msk) >> SYNC_SOC_SOCOUTDLYPRD_SOCBDLYPRD_Pos)   /*!< SOCBDLYPRD Get Value */

#define SYNC_SOC_SOCOUTDLYPRD_SOCADLYPRD_Pos     (0U)                                                                                                /*!< SOCADLYPRD Position 0 */
#define SYNC_SOC_SOCOUTDLYPRD_SOCADLYPRD_Msk     (0xffffU << SYNC_SOC_SOCOUTDLYPRD_SOCADLYPRD_Pos)                                                   /*!< SOCADLYPRD Mask 0x0000FFFF */
#define SYNC_SOC_SOCOUTDLYPRD_SOCADLYPRD_Set(x)  (((uint32_t) (x) << SYNC_SOC_SOCOUTDLYPRD_SOCADLYPRD_Pos) & SYNC_SOC_SOCOUTDLYPRD_SOCADLYPRD_Msk)   /*!< SOCADLYPRD Set Value */
#define SYNC_SOC_SOCOUTDLYPRD_SOCADLYPRD_Get(x)  (((uint32_t) (x) & SYNC_SOC_SOCOUTDLYPRD_SOCADLYPRD_Msk) >> SYNC_SOC_SOCOUTDLYPRD_SOCADLYPRD_Pos)   /*!< SOCADLYPRD Get Value */

/* HRCALCFG bitfield */
#define HRCAL_HRCALCFG_UPMODE_Pos     (16U)                                                                         /*!< UPMODE Position 16 */
#define HRCAL_HRCALCFG_UPMODE_Msk     (0x3U << HRCAL_HRCALCFG_UPMODE_Pos)                                           /*!< UPMODE Mask 0x00030000 */
#define HRCAL_HRCALCFG_UPMODE_Set(x)  (((uint32_t) (x) << HRCAL_HRCALCFG_UPMODE_Pos) & HRCAL_HRCALCFG_UPMODE_Msk)   /*!< UPMODE Set Value */
#define HRCAL_HRCALCFG_UPMODE_Get(x)  (((uint32_t) (x) & HRCAL_HRCALCFG_UPMODE_Msk) >> HRCAL_HRCALCFG_UPMODE_Pos)   /*!< UPMODE Get Value */

#define HRCAL_HRCALCFG_SWUP_Pos     (12U)                                                                     /*!< SWUP Position 12 */
#define HRCAL_HRCALCFG_SWUP_Msk     (0x1U << HRCAL_HRCALCFG_SWUP_Pos)                                         /*!< SWUP Mask 0x00001000 */
#define HRCAL_HRCALCFG_SWUP_Set(x)  (((uint32_t) (x) << HRCAL_HRCALCFG_SWUP_Pos) & HRCAL_HRCALCFG_SWUP_Msk)   /*!< SWUP Set Value */
#define HRCAL_HRCALCFG_SWUP_Get(x)  (((uint32_t) (x) & HRCAL_HRCALCFG_SWUP_Msk) >> HRCAL_HRCALCFG_SWUP_Pos)   /*!< SWUP Get Value */

#define HRCAL_HRCALCFG_SYNCPERSEL_Pos     (8U)                                                                                  /*!< SYNCPERSEL Position 8 */
#define HRCAL_HRCALCFG_SYNCPERSEL_Msk     (0xfU << HRCAL_HRCALCFG_SYNCPERSEL_Pos)                                               /*!< SYNCPERSEL Mask 0x00000F00 */
#define HRCAL_HRCALCFG_SYNCPERSEL_Set(x)  (((uint32_t) (x) << HRCAL_HRCALCFG_SYNCPERSEL_Pos) & HRCAL_HRCALCFG_SYNCPERSEL_Msk)   /*!< SYNCPERSEL Set Value */
#define HRCAL_HRCALCFG_SYNCPERSEL_Get(x)  (((uint32_t) (x) & HRCAL_HRCALCFG_SYNCPERSEL_Msk) >> HRCAL_HRCALCFG_SYNCPERSEL_Pos)   /*!< SYNCPERSEL Get Value */

#define HRCAL_HRCALCFG_ACCSEL_Pos     (1U)                                                                          /*!< ACCSEL Position 1 */
#define HRCAL_HRCALCFG_ACCSEL_Msk     (0xfU << HRCAL_HRCALCFG_ACCSEL_Pos)                                           /*!< ACCSEL Mask 0x0000001E */
#define HRCAL_HRCALCFG_ACCSEL_Set(x)  (((uint32_t) (x) << HRCAL_HRCALCFG_ACCSEL_Pos) & HRCAL_HRCALCFG_ACCSEL_Msk)   /*!< ACCSEL Set Value */
#define HRCAL_HRCALCFG_ACCSEL_Get(x)  (((uint32_t) (x) & HRCAL_HRCALCFG_ACCSEL_Msk) >> HRCAL_HRCALCFG_ACCSEL_Pos)   /*!< ACCSEL Get Value */

#define HRCAL_HRCALCFG_HRCALEN_Pos     (0U)                                                                            /*!< HRCALEN Position 0 */
#define HRCAL_HRCALCFG_HRCALEN_Msk     (0x1U << HRCAL_HRCALCFG_HRCALEN_Pos)                                            /*!< HRCALEN Mask 0x00000001 */
#define HRCAL_HRCALCFG_HRCALEN_Set(x)  (((uint32_t) (x) << HRCAL_HRCALCFG_HRCALEN_Pos) & HRCAL_HRCALCFG_HRCALEN_Msk)   /*!< HRCALEN Set Value */
#define HRCAL_HRCALCFG_HRCALEN_Get(x)  (((uint32_t) (x) & HRCAL_HRCALCFG_HRCALEN_Msk) >> HRCAL_HRCALCFG_HRCALEN_Pos)   /*!< HRCALEN Get Value */

/* HRCALCTRPRD bitfield */
#define HRCAL_HRCALCTRPRD_CTRPRD_Pos     (0U)                                                                                /*!< CTRPRD Position 0 */
#define HRCAL_HRCALCTRPRD_CTRPRD_Msk     (0xffffffffU << HRCAL_HRCALCTRPRD_CTRPRD_Pos)                                       /*!< CTRPRD Mask 0xFFFFFFFF */
#define HRCAL_HRCALCTRPRD_CTRPRD_Set(x)  (((uint32_t) (x) << HRCAL_HRCALCTRPRD_CTRPRD_Pos) & HRCAL_HRCALCTRPRD_CTRPRD_Msk)   /*!< CTRPRD Set Value */
#define HRCAL_HRCALCTRPRD_CTRPRD_Get(x)  (((uint32_t) (x) & HRCAL_HRCALCTRPRD_CTRPRD_Msk) >> HRCAL_HRCALCTRPRD_CTRPRD_Pos)   /*!< CTRPRD Get Value */

/* HRMSTEP bitfield */
#define HRCAL_HRMSTEP_HRMSTEP_Pos     (0U)                                                                          /*!< HRMSTEP Position 0 */
#define HRCAL_HRMSTEP_HRMSTEP_Msk     (0xffU << HRCAL_HRMSTEP_HRMSTEP_Pos)                                          /*!< HRMSTEP Mask 0x000000FF */
#define HRCAL_HRMSTEP_HRMSTEP_Set(x)  (((uint32_t) (x) << HRCAL_HRMSTEP_HRMSTEP_Pos) & HRCAL_HRMSTEP_HRMSTEP_Msk)   /*!< HRMSTEP Set Value */
#define HRCAL_HRMSTEP_HRMSTEP_Get(x)  (((uint32_t) (x) & HRCAL_HRMSTEP_HRMSTEP_Msk) >> HRCAL_HRMSTEP_HRMSTEP_Pos)   /*!< HRMSTEP Get Value */

/* HRCALINT bitfield */
#define HRCAL_HRCALINT_CALERCLR_Pos     (16U)                                                                             /*!< CALERCLR Position 16 */
#define HRCAL_HRCALINT_CALERCLR_Msk     (0x1U << HRCAL_HRCALINT_CALERCLR_Pos)                                             /*!< CALERCLR Mask 0x00010000 */
#define HRCAL_HRCALINT_CALERCLR_Set(x)  (((uint32_t) (x) << HRCAL_HRCALINT_CALERCLR_Pos) & HRCAL_HRCALINT_CALERCLR_Msk)   /*!< CALERCLR Set Value */
#define HRCAL_HRCALINT_CALERCLR_Get(x)  (((uint32_t) (x) & HRCAL_HRCALINT_CALERCLR_Msk) >> HRCAL_HRCALINT_CALERCLR_Pos)   /*!< CALERCLR Get Value */

#define HRCAL_HRCALINT_CALERSTS_Pos     (8U)                                                                              /*!< CALERSTS Position 8 */
#define HRCAL_HRCALINT_CALERSTS_Msk     (0x3U << HRCAL_HRCALINT_CALERSTS_Pos)                                             /*!< CALERSTS Mask 0x00000300 */
#define HRCAL_HRCALINT_CALERSTS_Set(x)  (((uint32_t) (x) << HRCAL_HRCALINT_CALERSTS_Pos) & HRCAL_HRCALINT_CALERSTS_Msk)   /*!< CALERSTS Set Value */
#define HRCAL_HRCALINT_CALERSTS_Get(x)  (((uint32_t) (x) & HRCAL_HRCALINT_CALERSTS_Msk) >> HRCAL_HRCALINT_CALERSTS_Pos)   /*!< CALERSTS Get Value */

#define HRCAL_HRCALINT_CALEREN_Pos     (0U)                                                                            /*!< CALEREN Position 0 */
#define HRCAL_HRCALINT_CALEREN_Msk     (0x1U << HRCAL_HRCALINT_CALEREN_Pos)                                            /*!< CALEREN Mask 0x00000001 */
#define HRCAL_HRCALINT_CALEREN_Set(x)  (((uint32_t) (x) << HRCAL_HRCALINT_CALEREN_Pos) & HRCAL_HRCALINT_CALEREN_Msk)   /*!< CALEREN Set Value */
#define HRCAL_HRCALINT_CALEREN_Get(x)  (((uint32_t) (x) & HRCAL_HRCALINT_CALEREN_Msk) >> HRCAL_HRCALINT_CALEREN_Pos)   /*!< CALEREN Get Value */

/* HRCALSTEPCFG bitfield */
#define HRCAL_HRCALSTEPCFG_FSTEPVAL_Pos     (16U)                                                                                     /*!< FSTEPVAL Position 16 */
#define HRCAL_HRCALSTEPCFG_FSTEPVAL_Msk     (0xfU << HRCAL_HRCALSTEPCFG_FSTEPVAL_Pos)                                                 /*!< FSTEPVAL Mask 0x000F0000 */
#define HRCAL_HRCALSTEPCFG_FSTEPVAL_Set(x)  (((uint32_t) (x) << HRCAL_HRCALSTEPCFG_FSTEPVAL_Pos) & HRCAL_HRCALSTEPCFG_FSTEPVAL_Msk)   /*!< FSTEPVAL Set Value */
#define HRCAL_HRCALSTEPCFG_FSTEPVAL_Get(x)  (((uint32_t) (x) & HRCAL_HRCALSTEPCFG_FSTEPVAL_Msk) >> HRCAL_HRCALSTEPCFG_FSTEPVAL_Pos)   /*!< FSTEPVAL Get Value */

#define HRCAL_HRCALSTEPCFG_CSTEPVAL_Pos     (8U)                                                                                      /*!< CSTEPVAL Position 8 */
#define HRCAL_HRCALSTEPCFG_CSTEPVAL_Msk     (0xfU << HRCAL_HRCALSTEPCFG_CSTEPVAL_Pos)                                                 /*!< CSTEPVAL Mask 0x00000F00 */
#define HRCAL_HRCALSTEPCFG_CSTEPVAL_Set(x)  (((uint32_t) (x) << HRCAL_HRCALSTEPCFG_CSTEPVAL_Pos) & HRCAL_HRCALSTEPCFG_CSTEPVAL_Msk)   /*!< CSTEPVAL Set Value */
#define HRCAL_HRCALSTEPCFG_CSTEPVAL_Get(x)  (((uint32_t) (x) & HRCAL_HRCALSTEPCFG_CSTEPVAL_Msk) >> HRCAL_HRCALSTEPCFG_CSTEPVAL_Pos)   /*!< CSTEPVAL Get Value */

#define HRCAL_HRCALSTEPCFG_STEPMODE_Pos     (0U)                                                                                      /*!< STEPMODE Position 0 */
#define HRCAL_HRCALSTEPCFG_STEPMODE_Msk     (0x1U << HRCAL_HRCALSTEPCFG_STEPMODE_Pos)                                                 /*!< STEPMODE Mask 0x00000001 */
#define HRCAL_HRCALSTEPCFG_STEPMODE_Set(x)  (((uint32_t) (x) << HRCAL_HRCALSTEPCFG_STEPMODE_Pos) & HRCAL_HRCALSTEPCFG_STEPMODE_Msk)   /*!< STEPMODE Set Value */
#define HRCAL_HRCALSTEPCFG_STEPMODE_Get(x)  (((uint32_t) (x) & HRCAL_HRCALSTEPCFG_STEPMODE_Msk) >> HRCAL_HRCALSTEPCFG_STEPMODE_Pos)   /*!< STEPMODE Get Value */

/* HRCALSTORECFG bitfield */
#define HRCAL_HRCALSTORECFG_LOCKSTS_Pos     (24U)                                                                                     /*!< LOCKSTS Position 24 */
#define HRCAL_HRCALSTORECFG_LOCKSTS_Msk     (0x1U << HRCAL_HRCALSTORECFG_LOCKSTS_Pos)                                                 /*!< LOCKSTS Mask 0x01000000 */
#define HRCAL_HRCALSTORECFG_LOCKSTS_Set(x)  (((uint32_t) (x) << HRCAL_HRCALSTORECFG_LOCKSTS_Pos) & HRCAL_HRCALSTORECFG_LOCKSTS_Msk)   /*!< LOCKSTS Set Value */
#define HRCAL_HRCALSTORECFG_LOCKSTS_Get(x)  (((uint32_t) (x) & HRCAL_HRCALSTORECFG_LOCKSTS_Msk) >> HRCAL_HRCALSTORECFG_LOCKSTS_Pos)   /*!< LOCKSTS Get Value */

#define HRCAL_HRCALSTORECFG_INIT_Pos     (16U)                                                                               /*!< INIT Position 16 */
#define HRCAL_HRCALSTORECFG_INIT_Msk     (0x1U << HRCAL_HRCALSTORECFG_INIT_Pos)                                              /*!< INIT Mask 0x00010000 */
#define HRCAL_HRCALSTORECFG_INIT_Set(x)  (((uint32_t) (x) << HRCAL_HRCALSTORECFG_INIT_Pos) & HRCAL_HRCALSTORECFG_INIT_Msk)   /*!< INIT Set Value */
#define HRCAL_HRCALSTORECFG_INIT_Get(x)  (((uint32_t) (x) & HRCAL_HRCALSTORECFG_INIT_Msk) >> HRCAL_HRCALSTORECFG_INIT_Pos)   /*!< INIT Get Value */

#define HRCAL_HRCALSTORECFG_THRESH_Pos     (8U)                                                                                    /*!< THRESH Position 8 */
#define HRCAL_HRCALSTORECFG_THRESH_Msk     (0xfU << HRCAL_HRCALSTORECFG_THRESH_Pos)                                                /*!< THRESH Mask 0x00000F00 */
#define HRCAL_HRCALSTORECFG_THRESH_Set(x)  (((uint32_t) (x) << HRCAL_HRCALSTORECFG_THRESH_Pos) & HRCAL_HRCALSTORECFG_THRESH_Msk)   /*!< THRESH Set Value */
#define HRCAL_HRCALSTORECFG_THRESH_Get(x)  (((uint32_t) (x) & HRCAL_HRCALSTORECFG_THRESH_Msk) >> HRCAL_HRCALSTORECFG_THRESH_Pos)   /*!< THRESH Get Value */

#define HRCAL_HRCALSTORECFG_STOREMODE_Pos     (0U)                                                                                          /*!< STOREMODE Position 0 */
#define HRCAL_HRCALSTORECFG_STOREMODE_Msk     (0x7U << HRCAL_HRCALSTORECFG_STOREMODE_Pos)                                                   /*!< STOREMODE Mask 0x00000007 */
#define HRCAL_HRCALSTORECFG_STOREMODE_Set(x)  (((uint32_t) (x) << HRCAL_HRCALSTORECFG_STOREMODE_Pos) & HRCAL_HRCALSTORECFG_STOREMODE_Msk)   /*!< STOREMODE Set Value */
#define HRCAL_HRCALSTORECFG_STOREMODE_Get(x)  (((uint32_t) (x) & HRCAL_HRCALSTORECFG_STOREMODE_Msk) >> HRCAL_HRCALSTORECFG_STOREMODE_Pos)   /*!< STOREMODE Get Value */

/* HRCALLOCK bitfield */
#define HRCAL_HRCALLOCK_HRCALLOCK_Pos     (24U)                                                                                 /*!< HRCALLOCK Position 24 */
#define HRCAL_HRCALLOCK_HRCALLOCK_Msk     (0x1U << HRCAL_HRCALLOCK_HRCALLOCK_Pos)                                               /*!< HRCALLOCK Mask 0x01000000 */
#define HRCAL_HRCALLOCK_HRCALLOCK_Set(x)  (((uint32_t) (x) << HRCAL_HRCALLOCK_HRCALLOCK_Pos) & HRCAL_HRCALLOCK_HRCALLOCK_Msk)   /*!< HRCALLOCK Set Value */
#define HRCAL_HRCALLOCK_HRCALLOCK_Get(x)  (((uint32_t) (x) & HRCAL_HRCALLOCK_HRCALLOCK_Msk) >> HRCAL_HRCALLOCK_HRCALLOCK_Pos)   /*!< HRCALLOCK Get Value */

/*!
 * @}
 */

/* clang-format on */

/*!
 * @}
 */ /* end of HS32F7D377_SYNCSOC_REGISTER */

#endif /* HS32F7D377_SYNCSOC_H */
