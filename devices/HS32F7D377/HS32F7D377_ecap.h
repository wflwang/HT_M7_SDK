/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


/*!
 * \file   HS32F7D377_ecap.h
 * \brief  HS32F7D377 ECAP register file
 * \version V1.0_20230713
 */

#ifndef HS32F7D377_ECAP_H
#define HS32F7D377_ECAP_H

/*!
 * \addtogroup   HS32F7D377_ECAP_REGISTER HS32F7D377 ECAP Register
 * \ingroup HS32F7D377_REGISTER
 *
 * \brief  ECAP register layout, bitfield and address definitions
 *
 * @{
 */

/*!
 * \name ECAP Register Layout
 *
 *
 * @{
 */

/*! \brief ECAP_REGS register */
typedef struct {
    union
    {
        __IOM uint32_t TSCTR;  /*!< 0x00000000 */ 
       
        struct
        {
            __IOM uint32_t TSCTR                     : 32;     /*!< [31:0] : Active 32-bit counter register that is used as the capture time-base HR mode :<br>  1) This register reads HRCOUNTER value and is not writable      <br>  2) can be reset using CTRFILTRESET                              <br>  3) Its not synchronized to SYSCLK domain so reads may not be accurate<br>  Reset type: SYSRSn                                              <br>. */
        } TSCTRb;
    };

    union
    {
        __IOM uint32_t CTRPHS;  /*!< 0x00000004 */ 
       
        struct
        {
            __IOM uint32_t CTRPHS                    : 32;     /*!< [31:0] : Counter phase value register that can be programmed for phase lag/ lead. */
        } CTRPHSb;
    };

    union
    {
        __IOM uint32_t CAP1;  /*!< 0x00000008 */ 
       
        struct
        {
            __IOM uint32_t CAP1                      : 32;     /*!< [31:0] : This register can be loaded (written) by:                       <br>  - Time-Stamp counter value (TSCTR) during a capture event       <br>  - Software - may be useful for test purposes or initialization  <br>  - ARPD shadow register (CAP3) when used in APWM mode Reset type: SYSRSn<br>. */
        } CAP1b;
    };

    union
    {
        __IOM uint32_t CAP2;  /*!< 0x0000000c */ 
       
        struct
        {
            __IOM uint32_t CAP2                      : 32;     /*!< [31:0] : This register can be loaded (written) by:                       <br>  - Time-Stamp ( counter value) during a capture event            <br>  - Software - may be useful for test purposes                    <br>  - ACMP shadow register (CAP4) when used in APWM mode Reset type: SYSRSn<br>. */
        } CAP2b;
    };

    union
    {
        __IOM uint32_t CAP3;  /*!< 0x00000010 */ 
       
        struct
        {
            __IOM uint32_t CAP3                      : 32;     /*!< [31:0] : In CMP mode, this is a time-stamp capture register. */
        } CAP3b;
    };

    union
    {
        __IOM uint32_t CAP4;  /*!< 0x00000014 */ 
       
        struct
        {
            __IOM uint32_t CAP4                      : 32;     /*!< [31:0] : In CMP mode, this is a time-stamp capture register. */
        } CAP4b;
    };

    uint8_t    RSV_0X18[12];   /*!< 0x00000018~0x00000023 : reserved */

    union
    {
        __IOM uint32_t ECCTL0;  /*!< 0x00000024 */ 
       
        struct
        {
            __IOM uint32_t INPUTSEL                  : 7 ;     /*!< [6:0] : Capture input source select bits                                <br>  0000000 capture input is ECAPxINPUT[0] 0000001 capture input is ECAPxINPUT[1] 0000010 capture input is ECAPxINPUT[2]<br>  . */
                  uint32_t RSV_0                     : 25;     /*!< [31:7] : reserved. */
        } ECCTL0b;
    };

    union
    {
        __IOM uint32_t ECCTL1;  /*!< 0x00000028 */ 
       
        struct
        {
            __IOM uint32_t CAP1POL                   : 1 ;     /*!< [0:0] : Capture Event 1 Polarity select Reset type: SYSRSn              <br>  0h (R/W) = Capture Event 1 triggered on a rising edge (RE) 1h (R/W) = Capture Event 1 triggered on a falling edge (FE)<br>. */
            __IOM uint32_t CTRRST1                   : 1 ;     /*!< [1:1] : Counter Reset on Capture Event 1 Reset type: SYSRSn             <br>  0h (R/W) = Do not reset counter on Capture Event 1 (absolute time stamp)<br>  1h (R/W) = Reset counter after Event 1 time-stamp has been captured (used in difference mode operation)<br>. */
            __IOM uint32_t CAP2POL                   : 1 ;     /*!< [2:2] : Capture Event 2 Polarity select Reset type: SYSRSn              <br>  0h (R/W) = Capture Event 2 triggered on a rising edge (RE) 1h (R/W) = Capture Event 2 triggered on a falling edge (FE)<br>. */
            __IOM uint32_t CTRRST2                   : 1 ;     /*!< [3:3] : Counter Reset on Capture Event 2 Reset type: SYSRSn             <br>  0h (R/W) = Do not reset counter on Capture Event 2 (absolute time stamp)<br>  1h (R/W) = Reset counter after Event 2 time-stamp has been captured (used in difference mode operation)<br>. */
            __IOM uint32_t CAP3POL                   : 1 ;     /*!< [4:4] : Capture Event 3 Polarity select Reset type: SYSRSn              <br>  0h (R/W) = Capture Event 3 triggered on a rising edge (RE) 1h (R/W) = Capture Event 3 triggered on a falling edge (FE)<br>. */
            __IOM uint32_t CTRRST3                   : 1 ;     /*!< [5:5] : Counter Reset on Capture Event 3 Reset type: SYSRSn             <br>  0h (R/W) = Do not reset counter on Capture Event 3 (absolute time stamp)<br>  1h (R/W) = Reset counter after Event 3 time-stamp has been captured (used in difference mode operation)<br>. */
            __IOM uint32_t CAP4POL                   : 1 ;     /*!< [6:6] : Capture Event 4 Polarity select Reset type: SYSRSn              <br>  0h (R/W) = Capture Event 4 triggered on a rising edge (RE) 1h (R/W) = Capture Event 4 triggered on a falling edge (FE)<br>. */
            __IOM uint32_t CTRRST4                   : 1 ;     /*!< [7:7] : Counter Reset on Capture Event 4 Reset type: SYSRSn             <br>  0h (R/W) = Do not reset counter on Capture Event 4 (absolute time stamp operation)<br>  1h (R/W) = Reset counter after Capture Event 4 time-stamp has been captured (used in difference mode operation)<br>. */
            __IOM uint32_t CAPLDEN                   : 1 ;     /*!< [8:8] : Enable Loading of CAP1-4 registers on a capture event. */
            __IOM uint32_t PRESCALE                  : 5 ;     /*!< [13:9] : Event Filter prescale select Reset type: SYSRSn                 <br>  0h (R/W) = Divide by 1 (i. */
            __IOM uint32_t FREE_SOFT                 : 2 ;     /*!< [15:14] : Emulation Control Reset type: SYSRSn                            <br>  0h (R/W) = TSCTR counter stops immediately on emulation suspend 1h (R/W) = TSCTR counter runs until = 0<br>  2h (R/W) = TSCTR counter is unaffected by emulation suspend (Run Free)<br>  3h (R/W) = TSCTR counter is unaffected by emulation suspend (Run Free)<br>. */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } ECCTL1b;
    };

    union
    {
        __IOM uint32_t ECCTL2;  /*!< 0x0000002c */ 
       
        struct
        {
            __IOM uint32_t CONT_ONESHT               : 1 ;     /*!< [0:0] : Continuous or one-shot mode control (applicable only in capture mode)<br>  Reset type: SYSRSn                                              <br>  0h (R/W) = Operate in continuous mode 1h (R/W) = Operate in one-Shot mode<br>. */
            __IOM uint32_t STOP_WRAP                 : 2 ;     /*!< [2:1] : Stop value for one-shot mode. */
            __IOM uint32_t REARM                     : 1 ;     /*!< [3:3] : Re-Arming Control. */
            __IOM uint32_t TSCTRSTOP                 : 1 ;     /*!< [4:4] : Time Stamp (TSCTR) Counter Stop (freeze) Control Reset type: SYSRSn<br>  0h (R/W) = TSCTR stopped                                        <br>  1h (R/W) = TSCTR free-running                                   <br>. */
            __IOM uint32_t SYNCI_EN                  : 1 ;     /*!< [5:5] : Counter (TSCTR) Sync-In select mode Reset type: SYSRSn          <br>  0h (R/W) = Disable sync-in option                               <br>  1h (R/W) = Enable counter (TSCTR) to be loaded from CTRPHS register upon either a SYNCI signal or a S/W force event. */
            __IOM uint32_t SYNCO_SEL                 : 2 ;     /*!< [7:6] : Sync-Out Select Reset type: SYSRSn                              <br>  0h (R/W) = sync out signal is SWSYNC                            <br>  1h (R/W) = Select CTR = PRD event to be the sync-out signal 2h (R/W) = Disable sync out signal<br>  3h (R/W) = Disable sync out signal                              <br>. */
            __IOM uint32_t SWSYNC                    : 1 ;     /*!< [8:8] : Software-forced Counter (TSCTR) Synchronizer. */
            __IOM uint32_t CAP_APWM                  : 1 ;     /*!< [9:9] : CAP/APWM operating mode select Reset type: SYSRSn               <br>  0h (R/W) = ECAP module operates in capture mode. */
            __IOM uint32_t APWMPOL                   : 1 ;     /*!< [10:10] : APWM output polarity select. */
            __IOM uint32_t CTRFILTRESET              : 1 ;     /*!< [11:11] : Reset Bit                                                       <br>  0h (R) = No effect                                              <br>  1h (W) = Resets event filter, counter, modulo counter and CEVT[1,2,3,4] and CNTOVF , HRERROR flags<br>  Note: This provides an ability start capture module from known state in case spurious inputs are captured while ECAP is configured. */
            __IOM uint32_t DMAEVTSEL                 : 2 ;     /*!< [13:12] : DMA event select                                                <br>  00b (R/W) = DMA interrupt source is CEVT1 01b (R/W) = DMA interrupt source is CEVT2 10b (R/W) = DMA interrupt source is CEVT3 11b (R/W) = DMA interrupt source is CEVT4<br>  Note: ECCTL1. */
            __IM  uint32_t MODCNTRSTS                : 2 ;     /*!< [15:14] : This bit field reads current status on modulo counter           <br>  00b (R) = CAP1 register gets loaded on next capture event. */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } ECCTL2b;
    };

    union
    {
        __IOM uint32_t ECEINT;  /*!< 0x00000030 */ 
       
        struct
        {
                  uint32_t RSV_1                     : 1 ;     /*!< [0:0] : reserved. */
            __IOM uint32_t CEVT1                     : 1 ;     /*!< [1:1] : Capture Event 1 Interrupt Enable Reset type: SYSRSn             <br>  0h (R/W) = Disable Capture Event 1 as an Interrupt source 1h (R/W) = Enable Capture Event 1 as an Interrupt source<br>. */
            __IOM uint32_t CEVT2                     : 1 ;     /*!< [2:2] : Capture Event 2 Interrupt Enable Reset type: SYSRSn             <br>  0h (R/W) = Disable Capture Event 2 as an Interrupt source 1h (R/W) = Enable Capture Event 2 as an Interrupt source<br>. */
            __IOM uint32_t CEVT3                     : 1 ;     /*!< [3:3] : Capture Event 3 Interrupt Enable Reset type: SYSRSn             <br>  0h (R/W) = Disable Capture Event 3 as an Interrupt source 1h (R/W) = Enable Capture Event 3 as an Interrupt source<br>. */
            __IOM uint32_t CEVT4                     : 1 ;     /*!< [4:4] : Capture Event 4 Interrupt Enable Reset type: SYSRSn             <br>  0h (R/W) = Disable Capture Event 4 as an Interrupt source 1h (R/W) = Capture Event 4 Interrupt Enable<br>. */
            __IOM uint32_t CTROVF                    : 1 ;     /*!< [5:5] : Counter Overflow Interrupt Enable Reset type: SYSRSn            <br>  0h (R/W) = Disabled counter Overflow as an Interrupt source 1h (R/W) = Enable counter Overflow as an Interrupt source<br>. */
            __IOM uint32_t CTR_EQ_PRD                : 1 ;     /*!< [6:6] : Counter Equal Period Interrupt Enable Reset type: SYSRSn        <br>  0h (R/W) = Disable Period Equal as an Interrupt source 1h (R/W) = Enable Period Equal as an Interrupt source<br>. */
            __IOM uint32_t CTR_EQ_CMP                : 1 ;     /*!< [7:7] : Counter Equal Compare Interrupt Enable Reset type: SYSRSn       <br>  0h (R/W) = Disable Compare Equal as an Interrupt source 1h (R/W) = Enable Compare Equal as an Interrupt source<br>. */
                  uint32_t RSV_0                     : 24;     /*!< [31:8] : reserved. */
        } ECEINTb;
    };

    union
    {
        __IM uint32_t ECFLG;  /*!< 0x00000034 */ 
       
        struct
        {
            __IM  uint32_t INT_FLAG                  : 1 ;     /*!< [0:0] : Global Interrupt Status Flag Reset type: SYSRSn                 <br>  0h (R/W) = Indicates no event occurred                          <br>  1h (R/W) = Indicates that an interrupt was generated. */
            __IM  uint32_t CEVT1                     : 1 ;     /*!< [1:1] : Capture Event 1 Status Flag. */
            __IM  uint32_t CEVT2                     : 1 ;     /*!< [2:2] : Capture Event 2 Status Flag. */
            __IM  uint32_t CEVT3                     : 1 ;     /*!< [3:3] : Capture Event 3 Status Flag. */
            __IM  uint32_t CEVT4                     : 1 ;     /*!< [4:4] : Capture Event 4 Status Flag This flag is only active in CAP mode. */
            __IM  uint32_t CTROVF                    : 1 ;     /*!< [5:5] : Counter Overflow Status Flag. */
            __IM  uint32_t CTR_PRD                   : 1 ;     /*!< [6:6] : Counter Equal Period Status Flag. */
            __IM  uint32_t CTR_CMP                   : 1 ;     /*!< [7:7] : Compare Equal Compare Status Flag. */
                  uint32_t RSV_0                     : 24;     /*!< [31:8] : reserved. */
        } ECFLGb;
    };

    union
    {
        __IOM uint32_t ECCLR;  /*!< 0x00000038 */ 
       
        struct
        {
            __IOM uint32_t INT_FLAG_CLR              : 1 ;     /*!< [0:0] : ECAP Global Interrupt Status Clear Reset type: SYSRSn           <br>  0h (R/W) = Writing a 0 has no effect. */
            __IOM uint32_t CEVT1                     : 1 ;     /*!< [1:1] : Capture Event 1 Status Clear Reset type: SYSRSn                 <br>  0h (R/W) = Writing a 0 has no effect. */
            __IOM uint32_t CEVT2                     : 1 ;     /*!< [2:2] : Capture Event 2 Status Clear Reset type: SYSRSn                 <br>  0h (R/W) = Writing a 0 has no effect. */
            __IOM uint32_t CEVT3                     : 1 ;     /*!< [3:3] : Capture Event 3 Status Clear Reset type: SYSRSn                 <br>  0h (R/W) = Writing a 0 has no effect. */
            __IOM uint32_t CEVT4                     : 1 ;     /*!< [4:4] : Capture Event 4 Status Clear Reset type: SYSRSn                 <br>  0h (R/W) = Writing a 0 has no effect. */
            __IOM uint32_t CTROVF                    : 1 ;     /*!< [5:5] : Counter Overflow Status Clear Reset type: SYSRSn                <br>  0h (R/W) = Writing a 0 has no effect. */
            __IOM uint32_t CTR_PRD                   : 1 ;     /*!< [6:6] : Counter Equal Period Status Clear Reset type: SYSRSn            <br>  0h (R/W) = Writing a 0 has no effect. */
            __IOM uint32_t CTR_CMP                   : 1 ;     /*!< [7:7] : Counter Equal Compare Status Clear Reset type: SYSRSn           <br>  0h (R/W) = Writing a 0 has no effect. */
                  uint32_t RSV_0                     : 24;     /*!< [31:8] : reserved. */
        } ECCLRb;
    };

    union
    {
        __IOM uint32_t ECFRC;  /*!< 0x0000003c */ 
       
        struct
        {
                  uint32_t RSV_1                     : 1 ;     /*!< [0:0] : reserved. */
            __IOM uint32_t CEVT1                     : 1 ;     /*!< [1:1] : Force Capture Event 1. */
            __IOM uint32_t CEVT2                     : 1 ;     /*!< [2:2] : Force Capture Event 2. */
            __IOM uint32_t CEVT3                     : 1 ;     /*!< [3:3] : Force Capture Event 3. */
            __IOM uint32_t CEVT4                     : 1 ;     /*!< [4:4] : Force Capture Event 4. */
            __IOM uint32_t CTROVF                    : 1 ;     /*!< [5:5] : Force Counter Overflow Reset type: SYSRSn                       <br>  0h (R/W) = No effect. */
            __IOM uint32_t CTR_PRD                   : 1 ;     /*!< [6:6] : Force Counter Equal Period Interrupt. */
            __IOM uint32_t CTR_CMP                   : 1 ;     /*!< [7:7] : Force Counter Equal Compare Interrupt. */
                  uint32_t RSV_0                     : 24;     /*!< [31:8] : reserved. */
        } ECFRCb;
    };

    union
    {
        __IOM uint32_t ECAPSYNCINSEL;  /*!< 0x00000040 */ 
       
        struct
        {
            __IOM uint32_t SEL                       : 5 ;     /*!< [4:0] : These bits determines the source of SYNCIN signal. */
                  uint32_t RSV_0                     : 11;     /*!< [15:5] : reserved. */
            __IOM uint32_t SYNC_EXP_NUM              : 16;     /*!< [31:16] : These bits determines how many cycles expand of ecap internal sync signal. */
        } ECAPSYNCINSELb;
    };

    union
    {
        __IOM uint32_t ECAP_OUT_SEL;  /*!< 0x00000044 */ 
       
        struct
        {
            __IOM uint32_t ECAP_OUT_S                : 1 ;     /*!< [0:0] : 0: output apwm, 1: output from clb. */
            __IOM uint32_t ECAP_OUT_EN_S             : 1 ;     /*!< [1:1] : 0: output apwm en, 1: output from clb. */
                  uint32_t RSV_0                     : 30;     /*!< [31:2] : reserved. */
        } ECAP_OUT_SELb;
    };
} ECAP_Type;

/*! \brief HRCAP_REGS register */
typedef struct {
    union
    {
        __IOM uint32_t HRCTL;  /*!< 0x00000100 */ 
       
        struct
        {
            __IOM uint32_t HRCAP_EN                  : 1 ;     /*!< [0:0] : set 1 enable hrcap. */
                  uint32_t RSV_0                     : 31;     /*!< [31:1] : reserved. */
        } HRCTLb;
    };

    union
    {
        __IOM uint32_t HRCALICTL;  /*!< 0x00000104 */ 
       
        struct
        {
            __IOM uint32_t CALI_EN                   : 1 ;     /*!< [0:0] : set 1 enable calibrate. */
            __IOM uint32_t CALI_MOD                  : 2 ;     /*!< [2:1] : 0: sw trig calibrate;                                           <br>  1: hw cyclicity trig calibrate;                                 <br>  2: hw auto trig calibrate when capin                            <br>. */
                  uint32_t RSV_1                     : 1 ;     /*!< [3:3] : reserved. */
            __IOM uint32_t CALI_TRIG                 : 1 ;     /*!< [4:4] : when cali_mod==0,write 1 to calibrate one time. */
                  uint32_t RSV_0                     : 27;     /*!< [31:5] : reserved. */
        } HRCALICTLb;
    };

    union
    {
        __IOM uint32_t CALI_INTERVAL;  /*!< 0x00000108 */ 
       
        struct
        {
            __IOM uint32_t CALI_INTERVAL             : 32;     /*!< [31:0] : when cali_mod==1, this register set interval cycle in twice calibration. */
        } CALI_INTERVALb;
    };

    union
    {
        __IM uint32_t HRCAP_DATA_H;  /*!< 0x0000010c */ 
       
        struct
        {
            __IM  uint32_t HRCAP_CAP_DATA_H          : 32;     /*!< [31:0] : hrcap cap data. */
        } HRCAP_DATA_Hb;
    };

    union
    {
        __IM uint32_t HRCAP_DATA_L;  /*!< 0x00000110 */ 
       
        struct
        {
            __IM  uint32_t HRCAP_CAP_DATA_L          : 32;     /*!< [31:0] : hrcap cap data. */
        } HRCAP_DATA_Lb;
    };

    union
    {
        __IM uint32_t CALI_DATA_H;  /*!< 0x00000114 */ 
       
        struct
        {
            __IM  uint32_t HRCAP_CALI_DATA_H         : 32;     /*!< [31:0] : hrcap cali data. */
        } CALI_DATA_Hb;
    };

    union
    {
        __IM uint32_t CALI_DATA_L;  /*!< 0x00000118 */ 
       
        struct
        {
            __IM  uint32_t HRCAP_CALI_DATA_L         : 32;     /*!< [31:0] : hrcap cali data. */
        } CALI_DATA_Lb;
    };

    union
    {
        __IOM uint32_t HRCAP_IE;  /*!< 0x0000011c */ 
       
        struct
        {
            __IOM uint32_t HRCAP_CALI_DONE_IE        : 1 ;     /*!< [0:0] : set 1 enable hrcap_cali_done int. */
                  uint32_t RSV_0                     : 31;     /*!< [31:1] : reserved. */
        } HRCAP_IEb;
    };

    union
    {
        __IM uint32_t HRCAP_FLG;  /*!< 0x00000120 */ 
       
        struct
        {
            __IM  uint32_t HRCAP_CALI_DONE           : 1 ;     /*!< [0:0] : hrcap calibration done flag. */
                  uint32_t RSV_0                     : 31;     /*!< [31:1] : reserved. */
        } HRCAP_FLGb;
    };

    union
    {
        __IOM uint32_t HRCAP_FLG_CLR;  /*!< 0x00000124 */ 
       
        struct
        {
            __IOM uint32_t HRCAP_CALI_DONE_CLR       : 1 ;     /*!< [0:0] : clr hrcap calibration done flag. */
                  uint32_t RSV_0                     : 31;     /*!< [31:1] : reserved. */
        } HRCAP_FLG_CLRb;
    };
} HRCAP_Type;


/*!
 * @}
 */

/*!
 * \name ECAP Base Address Definitions
 *
 * @{
 */

 /*! \brief ECAP1 base address */
#define ECAP1_BASE (0x40600000UL)
/*! \brief ECAP2 base address */
#define ECAP2_BASE (0x40600400UL)
/*! \brief ECAP3 base address */
#define ECAP3_BASE (0x40600800UL)
/*! \brief ECAP4 base address */
#define ECAP4_BASE (0x40600c00UL)
/*! \brief ECAP5 base address */
#define ECAP5_BASE (0x40601000UL)
/*! \brief ECAP6 base address */
#define ECAP6_BASE (0x40601400UL)
/*! \brief ECAP1 base pointer */
#define ECAP1 ((ECAP_Type *) ECAP1_BASE)
/*! \brief ECAP2 base pointer */
#define ECAP2 ((ECAP_Type *) ECAP2_BASE)
/*! \brief ECAP3 base pointer */
#define ECAP3 ((ECAP_Type *) ECAP3_BASE)
/*! \brief ECAP4 base pointer */
#define ECAP4 ((ECAP_Type *) ECAP4_BASE)
/*! \brief ECAP5 base pointer */
#define ECAP5 ((ECAP_Type *) ECAP5_BASE)
/*! \brief ECAP6 base pointer */
#define ECAP6 ((ECAP_Type *) ECAP6_BASE)

/*! \brief HRCAP1 base address */
#define HRCAP1_BASE (0x40600100UL)
/*! \brief HRCAP2 base address */
#define HRCAP2_BASE (0x40600500UL)
/*! \brief HRCAP1 base pointer */
#define HRCAP1 ((HRCAP_Type *) HRCAP1_BASE)
/*! \brief HRCAP2 base pointer */
#define HRCAP2 ((HRCAP_Type *) HRCAP2_BASE)


/*!
 * @}
 */

 
/*!
 * \name ECAP Register Bitfield Definitions
 *
 * @{
 */

 /* TSCTR bitfield */
#define ECAP_TSCTR_Pos    (0U)                                                                                  /*!< TSCTR Postion   0          */ 
#define ECAP_TSCTR_Msk    (0xffffffffU << ECAP_TSCTR_Pos)                                            /*!< TSCTR Mask      0xFFFFFFFF */
#define ECAP_TSCTR_Set(x) (((uint32_t) (x) << ECAP_TSCTR_Pos) & ECAP_TSCTR_Msk)           /*!< TSCTR Set Value            */
#define ECAP_TSCTR_Get(x) (((uint32_t) (x) & ECAP_TSCTR_Msk) >> ECAP_TSCTR_Pos)           /*!< TSCTR Get Value            */


/* CTRPHS bitfield */
#define ECAP_CTRPHS_Pos    (0U)                                                                                  /*!< CTRPHS Postion   0          */ 
#define ECAP_CTRPHS_Msk    (0xffffffffU << ECAP_CTRPHS_Pos)                                          /*!< CTRPHS Mask      0xFFFFFFFF */
#define ECAP_CTRPHS_Set(x) (((uint32_t) (x) << ECAP_CTRPHS_Pos) & ECAP_CTRPHS_Msk)       /*!< CTRPHS Set Value            */
#define ECAP_CTRPHS_Get(x) (((uint32_t) (x) & ECAP_CTRPHS_Msk) >> ECAP_CTRPHS_Pos)       /*!< CTRPHS Get Value            */


/* CAP1 bitfield */
#define ECAP_CAP1_Pos    (0U)                                                                                  /*!< CAP1 Postion   0          */ 
#define ECAP_CAP1_Msk    (0xffffffffU << ECAP_CAP1_Pos)                                              /*!< CAP1 Mask      0xFFFFFFFF */
#define ECAP_CAP1_Set(x) (((uint32_t) (x) << ECAP_CAP1_Pos) & ECAP_CAP1_Msk)               /*!< CAP1 Set Value            */
#define ECAP_CAP1_Get(x) (((uint32_t) (x) & ECAP_CAP1_Msk) >> ECAP_CAP1_Pos)               /*!< CAP1 Get Value            */


/* CAP2 bitfield */
#define ECAP_CAP2_Pos    (0U)                                                                                  /*!< CAP2 Postion   0          */ 
#define ECAP_CAP2_Msk    (0xffffffffU << ECAP_CAP2_Pos)                                              /*!< CAP2 Mask      0xFFFFFFFF */
#define ECAP_CAP2_Set(x) (((uint32_t) (x) << ECAP_CAP2_Pos) & ECAP_CAP2_Msk)               /*!< CAP2 Set Value            */
#define ECAP_CAP2_Get(x) (((uint32_t) (x) & ECAP_CAP2_Msk) >> ECAP_CAP2_Pos)               /*!< CAP2 Get Value            */


/* CAP3 bitfield */
#define ECAP_CAP3_Pos    (0U)                                                                                  /*!< CAP3 Postion   0          */ 
#define ECAP_CAP3_Msk    (0xffffffffU << ECAP_CAP3_Pos)                                              /*!< CAP3 Mask      0xFFFFFFFF */
#define ECAP_CAP3_Set(x) (((uint32_t) (x) << ECAP_CAP3_Pos) & ECAP_CAP3_Msk)               /*!< CAP3 Set Value            */
#define ECAP_CAP3_Get(x) (((uint32_t) (x) & ECAP_CAP3_Msk) >> ECAP_CAP3_Pos)               /*!< CAP3 Get Value            */


/* CAP4 bitfield */
#define ECAP_CAP4_Pos    (0U)                                                                                  /*!< CAP4 Postion   0          */ 
#define ECAP_CAP4_Msk    (0xffffffffU << ECAP_CAP4_Pos)                                              /*!< CAP4 Mask      0xFFFFFFFF */
#define ECAP_CAP4_Set(x) (((uint32_t) (x) << ECAP_CAP4_Pos) & ECAP_CAP4_Msk)               /*!< CAP4 Set Value            */
#define ECAP_CAP4_Get(x) (((uint32_t) (x) & ECAP_CAP4_Msk) >> ECAP_CAP4_Pos)               /*!< CAP4 Get Value            */


/* ECCTL0 bitfield */
#define ECAP_ECCTL0_INPUTSEL_Pos    (0U)                                                                                  /*!< INPUTSEL Postion   0          */ 
#define ECAP_ECCTL0_INPUTSEL_Msk    (0x7fU << ECAP_ECCTL0_INPUTSEL_Pos)                                              /*!< INPUTSEL Mask      0x0000007F */
#define ECAP_ECCTL0_INPUTSEL_Set(x) (((uint32_t) (x) << ECAP_ECCTL0_INPUTSEL_Pos) & ECAP_ECCTL0_INPUTSEL_Msk)   /*!< INPUTSEL Set Value            */
#define ECAP_ECCTL0_INPUTSEL_Get(x) (((uint32_t) (x) & ECAP_ECCTL0_INPUTSEL_Msk) >> ECAP_ECCTL0_INPUTSEL_Pos)   /*!< INPUTSEL Get Value            */


/* ECCTL1 bitfield */
#define ECAP_ECCTL1_FREE_SOFT_Pos    (14U)                                                                                 /*!< FREE_SOFT Postion   14         */ 
#define ECAP_ECCTL1_FREE_SOFT_Msk    (0x3U << ECAP_ECCTL1_FREE_SOFT_Pos)                                              /*!< FREE_SOFT Mask      0x0000C000 */
#define ECAP_ECCTL1_FREE_SOFT_Set(x) (((uint32_t) (x) << ECAP_ECCTL1_FREE_SOFT_Pos) & ECAP_ECCTL1_FREE_SOFT_Msk) /*!< FREE_SOFT Set Value            */
#define ECAP_ECCTL1_FREE_SOFT_Get(x) (((uint32_t) (x) & ECAP_ECCTL1_FREE_SOFT_Msk) >> ECAP_ECCTL1_FREE_SOFT_Pos) /*!< FREE_SOFT Get Value            */


#define ECAP_ECCTL1_PRESCALE_Pos    (9U)                                                                                  /*!< PRESCALE Postion   9          */ 
#define ECAP_ECCTL1_PRESCALE_Msk    (0x1fU << ECAP_ECCTL1_PRESCALE_Pos)                                              /*!< PRESCALE Mask      0x00003E00 */
#define ECAP_ECCTL1_PRESCALE_Set(x) (((uint32_t) (x) << ECAP_ECCTL1_PRESCALE_Pos) & ECAP_ECCTL1_PRESCALE_Msk)   /*!< PRESCALE Set Value            */
#define ECAP_ECCTL1_PRESCALE_Get(x) (((uint32_t) (x) & ECAP_ECCTL1_PRESCALE_Msk) >> ECAP_ECCTL1_PRESCALE_Pos)   /*!< PRESCALE Get Value            */


#define ECAP_ECCTL1_CAPLDEN_Pos    (8U)                                                                                  /*!< CAPLDEN Postion   8          */ 
#define ECAP_ECCTL1_CAPLDEN_Msk    (0x1U << ECAP_ECCTL1_CAPLDEN_Pos)                                                /*!< CAPLDEN Mask      0x00000100 */
#define ECAP_ECCTL1_CAPLDEN_Set(x) (((uint32_t) (x) << ECAP_ECCTL1_CAPLDEN_Pos) & ECAP_ECCTL1_CAPLDEN_Msk)     /*!< CAPLDEN Set Value            */
#define ECAP_ECCTL1_CAPLDEN_Get(x) (((uint32_t) (x) & ECAP_ECCTL1_CAPLDEN_Msk) >> ECAP_ECCTL1_CAPLDEN_Pos)     /*!< CAPLDEN Get Value            */


#define ECAP_ECCTL1_CTRRST4_Pos    (7U)                                                                                  /*!< CTRRST4 Postion   7          */ 
#define ECAP_ECCTL1_CTRRST4_Msk    (0x1U << ECAP_ECCTL1_CTRRST4_Pos)                                                /*!< CTRRST4 Mask      0x00000080 */
#define ECAP_ECCTL1_CTRRST4_Set(x) (((uint32_t) (x) << ECAP_ECCTL1_CTRRST4_Pos) & ECAP_ECCTL1_CTRRST4_Msk)     /*!< CTRRST4 Set Value            */
#define ECAP_ECCTL1_CTRRST4_Get(x) (((uint32_t) (x) & ECAP_ECCTL1_CTRRST4_Msk) >> ECAP_ECCTL1_CTRRST4_Pos)     /*!< CTRRST4 Get Value            */


#define ECAP_ECCTL1_CAP4POL_Pos    (6U)                                                                                  /*!< CAP4POL Postion   6          */ 
#define ECAP_ECCTL1_CAP4POL_Msk    (0x1U << ECAP_ECCTL1_CAP4POL_Pos)                                                /*!< CAP4POL Mask      0x00000040 */
#define ECAP_ECCTL1_CAP4POL_Set(x) (((uint32_t) (x) << ECAP_ECCTL1_CAP4POL_Pos) & ECAP_ECCTL1_CAP4POL_Msk)     /*!< CAP4POL Set Value            */
#define ECAP_ECCTL1_CAP4POL_Get(x) (((uint32_t) (x) & ECAP_ECCTL1_CAP4POL_Msk) >> ECAP_ECCTL1_CAP4POL_Pos)     /*!< CAP4POL Get Value            */


#define ECAP_ECCTL1_CTRRST3_Pos    (5U)                                                                                  /*!< CTRRST3 Postion   5          */ 
#define ECAP_ECCTL1_CTRRST3_Msk    (0x1U << ECAP_ECCTL1_CTRRST3_Pos)                                                /*!< CTRRST3 Mask      0x00000020 */
#define ECAP_ECCTL1_CTRRST3_Set(x) (((uint32_t) (x) << ECAP_ECCTL1_CTRRST3_Pos) & ECAP_ECCTL1_CTRRST3_Msk)     /*!< CTRRST3 Set Value            */
#define ECAP_ECCTL1_CTRRST3_Get(x) (((uint32_t) (x) & ECAP_ECCTL1_CTRRST3_Msk) >> ECAP_ECCTL1_CTRRST3_Pos)     /*!< CTRRST3 Get Value            */


#define ECAP_ECCTL1_CAP3POL_Pos    (4U)                                                                                  /*!< CAP3POL Postion   4          */ 
#define ECAP_ECCTL1_CAP3POL_Msk    (0x1U << ECAP_ECCTL1_CAP3POL_Pos)                                                /*!< CAP3POL Mask      0x00000010 */
#define ECAP_ECCTL1_CAP3POL_Set(x) (((uint32_t) (x) << ECAP_ECCTL1_CAP3POL_Pos) & ECAP_ECCTL1_CAP3POL_Msk)     /*!< CAP3POL Set Value            */
#define ECAP_ECCTL1_CAP3POL_Get(x) (((uint32_t) (x) & ECAP_ECCTL1_CAP3POL_Msk) >> ECAP_ECCTL1_CAP3POL_Pos)     /*!< CAP3POL Get Value            */


#define ECAP_ECCTL1_CTRRST2_Pos    (3U)                                                                                  /*!< CTRRST2 Postion   3          */ 
#define ECAP_ECCTL1_CTRRST2_Msk    (0x1U << ECAP_ECCTL1_CTRRST2_Pos)                                                /*!< CTRRST2 Mask      0x00000008 */
#define ECAP_ECCTL1_CTRRST2_Set(x) (((uint32_t) (x) << ECAP_ECCTL1_CTRRST2_Pos) & ECAP_ECCTL1_CTRRST2_Msk)     /*!< CTRRST2 Set Value            */
#define ECAP_ECCTL1_CTRRST2_Get(x) (((uint32_t) (x) & ECAP_ECCTL1_CTRRST2_Msk) >> ECAP_ECCTL1_CTRRST2_Pos)     /*!< CTRRST2 Get Value            */


#define ECAP_ECCTL1_CAP2POL_Pos    (2U)                                                                                  /*!< CAP2POL Postion   2          */ 
#define ECAP_ECCTL1_CAP2POL_Msk    (0x1U << ECAP_ECCTL1_CAP2POL_Pos)                                                /*!< CAP2POL Mask      0x00000004 */
#define ECAP_ECCTL1_CAP2POL_Set(x) (((uint32_t) (x) << ECAP_ECCTL1_CAP2POL_Pos) & ECAP_ECCTL1_CAP2POL_Msk)     /*!< CAP2POL Set Value            */
#define ECAP_ECCTL1_CAP2POL_Get(x) (((uint32_t) (x) & ECAP_ECCTL1_CAP2POL_Msk) >> ECAP_ECCTL1_CAP2POL_Pos)     /*!< CAP2POL Get Value            */


#define ECAP_ECCTL1_CTRRST1_Pos    (1U)                                                                                  /*!< CTRRST1 Postion   1          */ 
#define ECAP_ECCTL1_CTRRST1_Msk    (0x1U << ECAP_ECCTL1_CTRRST1_Pos)                                                /*!< CTRRST1 Mask      0x00000002 */
#define ECAP_ECCTL1_CTRRST1_Set(x) (((uint32_t) (x) << ECAP_ECCTL1_CTRRST1_Pos) & ECAP_ECCTL1_CTRRST1_Msk)     /*!< CTRRST1 Set Value            */
#define ECAP_ECCTL1_CTRRST1_Get(x) (((uint32_t) (x) & ECAP_ECCTL1_CTRRST1_Msk) >> ECAP_ECCTL1_CTRRST1_Pos)     /*!< CTRRST1 Get Value            */


#define ECAP_ECCTL1_CAP1POL_Pos    (0U)                                                                                  /*!< CAP1POL Postion   0          */ 
#define ECAP_ECCTL1_CAP1POL_Msk    (0x1U << ECAP_ECCTL1_CAP1POL_Pos)                                                /*!< CAP1POL Mask      0x00000001 */
#define ECAP_ECCTL1_CAP1POL_Set(x) (((uint32_t) (x) << ECAP_ECCTL1_CAP1POL_Pos) & ECAP_ECCTL1_CAP1POL_Msk)     /*!< CAP1POL Set Value            */
#define ECAP_ECCTL1_CAP1POL_Get(x) (((uint32_t) (x) & ECAP_ECCTL1_CAP1POL_Msk) >> ECAP_ECCTL1_CAP1POL_Pos)     /*!< CAP1POL Get Value            */


/* ECCTL2 bitfield */
#define ECAP_ECCTL2_MODCNTRSTS_Pos    (14U)                                                                                 /*!< MODCNTRSTS Postion   14         */ 
#define ECAP_ECCTL2_MODCNTRSTS_Msk    (0x3U << ECAP_ECCTL2_MODCNTRSTS_Pos)                                             /*!< MODCNTRSTS Mask      0x0000C000 */
#define ECAP_ECCTL2_MODCNTRSTS_Set(x) (((uint32_t) (x) << ECAP_ECCTL2_MODCNTRSTS_Pos) & ECAP_ECCTL2_MODCNTRSTS_Msk) /*!< MODCNTRSTS Set Value            */
#define ECAP_ECCTL2_MODCNTRSTS_Get(x) (((uint32_t) (x) & ECAP_ECCTL2_MODCNTRSTS_Msk) >> ECAP_ECCTL2_MODCNTRSTS_Pos) /*!< MODCNTRSTS Get Value            */


#define ECAP_ECCTL2_DMAEVTSEL_Pos    (12U)                                                                                 /*!< DMAEVTSEL Postion   12         */ 
#define ECAP_ECCTL2_DMAEVTSEL_Msk    (0x3U << ECAP_ECCTL2_DMAEVTSEL_Pos)                                              /*!< DMAEVTSEL Mask      0x00003000 */
#define ECAP_ECCTL2_DMAEVTSEL_Set(x) (((uint32_t) (x) << ECAP_ECCTL2_DMAEVTSEL_Pos) & ECAP_ECCTL2_DMAEVTSEL_Msk) /*!< DMAEVTSEL Set Value            */
#define ECAP_ECCTL2_DMAEVTSEL_Get(x) (((uint32_t) (x) & ECAP_ECCTL2_DMAEVTSEL_Msk) >> ECAP_ECCTL2_DMAEVTSEL_Pos) /*!< DMAEVTSEL Get Value            */


#define ECAP_ECCTL2_CTRFILTRESET_Pos    (11U)                                                                                 /*!< CTRFILTRESET Postion   11         */ 
#define ECAP_ECCTL2_CTRFILTRESET_Msk    (0x1U << ECAP_ECCTL2_CTRFILTRESET_Pos)                                           /*!< CTRFILTRESET Mask      0x00000800 */
#define ECAP_ECCTL2_CTRFILTRESET_Set(x) (((uint32_t) (x) << ECAP_ECCTL2_CTRFILTRESET_Pos) & ECAP_ECCTL2_CTRFILTRESET_Msk) /*!< CTRFILTRESET Set Value            */
#define ECAP_ECCTL2_CTRFILTRESET_Get(x) (((uint32_t) (x) & ECAP_ECCTL2_CTRFILTRESET_Msk) >> ECAP_ECCTL2_CTRFILTRESET_Pos) /*!< CTRFILTRESET Get Value            */


#define ECAP_ECCTL2_APWMPOL_Pos    (10U)                                                                                 /*!< APWMPOL Postion   10         */ 
#define ECAP_ECCTL2_APWMPOL_Msk    (0x1U << ECAP_ECCTL2_APWMPOL_Pos)                                                /*!< APWMPOL Mask      0x00000400 */
#define ECAP_ECCTL2_APWMPOL_Set(x) (((uint32_t) (x) << ECAP_ECCTL2_APWMPOL_Pos) & ECAP_ECCTL2_APWMPOL_Msk)     /*!< APWMPOL Set Value            */
#define ECAP_ECCTL2_APWMPOL_Get(x) (((uint32_t) (x) & ECAP_ECCTL2_APWMPOL_Msk) >> ECAP_ECCTL2_APWMPOL_Pos)     /*!< APWMPOL Get Value            */


#define ECAP_ECCTL2_CAP_APWM_Pos    (9U)                                                                                  /*!< CAP_APWM Postion   9          */ 
#define ECAP_ECCTL2_CAP_APWM_Msk    (0x1U << ECAP_ECCTL2_CAP_APWM_Pos)                                               /*!< CAP_APWM Mask      0x00000200 */
#define ECAP_ECCTL2_CAP_APWM_Set(x) (((uint32_t) (x) << ECAP_ECCTL2_CAP_APWM_Pos) & ECAP_ECCTL2_CAP_APWM_Msk)   /*!< CAP_APWM Set Value            */
#define ECAP_ECCTL2_CAP_APWM_Get(x) (((uint32_t) (x) & ECAP_ECCTL2_CAP_APWM_Msk) >> ECAP_ECCTL2_CAP_APWM_Pos)   /*!< CAP_APWM Get Value            */


#define ECAP_ECCTL2_SWSYNC_Pos    (8U)                                                                                  /*!< SWSYNC Postion   8          */ 
#define ECAP_ECCTL2_SWSYNC_Msk    (0x1U << ECAP_ECCTL2_SWSYNC_Pos)                                                 /*!< SWSYNC Mask      0x00000100 */
#define ECAP_ECCTL2_SWSYNC_Set(x) (((uint32_t) (x) << ECAP_ECCTL2_SWSYNC_Pos) & ECAP_ECCTL2_SWSYNC_Msk)       /*!< SWSYNC Set Value            */
#define ECAP_ECCTL2_SWSYNC_Get(x) (((uint32_t) (x) & ECAP_ECCTL2_SWSYNC_Msk) >> ECAP_ECCTL2_SWSYNC_Pos)       /*!< SWSYNC Get Value            */


#define ECAP_ECCTL2_SYNCO_SEL_Pos    (6U)                                                                                  /*!< SYNCO_SEL Postion   6          */ 
#define ECAP_ECCTL2_SYNCO_SEL_Msk    (0x3U << ECAP_ECCTL2_SYNCO_SEL_Pos)                                              /*!< SYNCO_SEL Mask      0x000000C0 */
#define ECAP_ECCTL2_SYNCO_SEL_Set(x) (((uint32_t) (x) << ECAP_ECCTL2_SYNCO_SEL_Pos) & ECAP_ECCTL2_SYNCO_SEL_Msk) /*!< SYNCO_SEL Set Value            */
#define ECAP_ECCTL2_SYNCO_SEL_Get(x) (((uint32_t) (x) & ECAP_ECCTL2_SYNCO_SEL_Msk) >> ECAP_ECCTL2_SYNCO_SEL_Pos) /*!< SYNCO_SEL Get Value            */


#define ECAP_ECCTL2_SYNCI_EN_Pos    (5U)                                                                                  /*!< SYNCI_EN Postion   5          */ 
#define ECAP_ECCTL2_SYNCI_EN_Msk    (0x1U << ECAP_ECCTL2_SYNCI_EN_Pos)                                               /*!< SYNCI_EN Mask      0x00000020 */
#define ECAP_ECCTL2_SYNCI_EN_Set(x) (((uint32_t) (x) << ECAP_ECCTL2_SYNCI_EN_Pos) & ECAP_ECCTL2_SYNCI_EN_Msk)   /*!< SYNCI_EN Set Value            */
#define ECAP_ECCTL2_SYNCI_EN_Get(x) (((uint32_t) (x) & ECAP_ECCTL2_SYNCI_EN_Msk) >> ECAP_ECCTL2_SYNCI_EN_Pos)   /*!< SYNCI_EN Get Value            */


#define ECAP_ECCTL2_TSCTRSTOP_Pos    (4U)                                                                                  /*!< TSCTRSTOP Postion   4          */ 
#define ECAP_ECCTL2_TSCTRSTOP_Msk    (0x1U << ECAP_ECCTL2_TSCTRSTOP_Pos)                                              /*!< TSCTRSTOP Mask      0x00000010 */
#define ECAP_ECCTL2_TSCTRSTOP_Set(x) (((uint32_t) (x) << ECAP_ECCTL2_TSCTRSTOP_Pos) & ECAP_ECCTL2_TSCTRSTOP_Msk) /*!< TSCTRSTOP Set Value            */
#define ECAP_ECCTL2_TSCTRSTOP_Get(x) (((uint32_t) (x) & ECAP_ECCTL2_TSCTRSTOP_Msk) >> ECAP_ECCTL2_TSCTRSTOP_Pos) /*!< TSCTRSTOP Get Value            */


#define ECAP_ECCTL2_REARM_Pos    (3U)                                                                                  /*!< REARM Postion   3          */ 
#define ECAP_ECCTL2_REARM_Msk    (0x1U << ECAP_ECCTL2_REARM_Pos)                                                  /*!< REARM Mask      0x00000008 */
#define ECAP_ECCTL2_REARM_Set(x) (((uint32_t) (x) << ECAP_ECCTL2_REARM_Pos) & ECAP_ECCTL2_REARM_Msk)         /*!< REARM Set Value            */
#define ECAP_ECCTL2_REARM_Get(x) (((uint32_t) (x) & ECAP_ECCTL2_REARM_Msk) >> ECAP_ECCTL2_REARM_Pos)         /*!< REARM Get Value            */


#define ECAP_ECCTL2_STOP_WRAP_Pos    (1U)                                                                                  /*!< STOP_WRAP Postion   1          */ 
#define ECAP_ECCTL2_STOP_WRAP_Msk    (0x3U << ECAP_ECCTL2_STOP_WRAP_Pos)                                              /*!< STOP_WRAP Mask      0x00000006 */
#define ECAP_ECCTL2_STOP_WRAP_Set(x) (((uint32_t) (x) << ECAP_ECCTL2_STOP_WRAP_Pos) & ECAP_ECCTL2_STOP_WRAP_Msk) /*!< STOP_WRAP Set Value            */
#define ECAP_ECCTL2_STOP_WRAP_Get(x) (((uint32_t) (x) & ECAP_ECCTL2_STOP_WRAP_Msk) >> ECAP_ECCTL2_STOP_WRAP_Pos) /*!< STOP_WRAP Get Value            */


#define ECAP_ECCTL2_CONT_ONESHT_Pos    (0U)                                                                                  /*!< CONT_ONESHT Postion   0          */ 
#define ECAP_ECCTL2_CONT_ONESHT_Msk    (0x1U << ECAP_ECCTL2_CONT_ONESHT_Pos)                                            /*!< CONT_ONESHT Mask      0x00000001 */
#define ECAP_ECCTL2_CONT_ONESHT_Set(x) (((uint32_t) (x) << ECAP_ECCTL2_CONT_ONESHT_Pos) & ECAP_ECCTL2_CONT_ONESHT_Msk) /*!< CONT_ONESHT Set Value            */
#define ECAP_ECCTL2_CONT_ONESHT_Get(x) (((uint32_t) (x) & ECAP_ECCTL2_CONT_ONESHT_Msk) >> ECAP_ECCTL2_CONT_ONESHT_Pos) /*!< CONT_ONESHT Get Value            */


/* ECEINT bitfield */
#define ECAP_ECEINT_CTR_EQ_CMP_Pos    (7U)                                                                                  /*!< CTR_EQ_CMP Postion   7          */ 
#define ECAP_ECEINT_CTR_EQ_CMP_Msk    (0x1U << ECAP_ECEINT_CTR_EQ_CMP_Pos)                                             /*!< CTR_EQ_CMP Mask      0x00000080 */
#define ECAP_ECEINT_CTR_EQ_CMP_Set(x) (((uint32_t) (x) << ECAP_ECEINT_CTR_EQ_CMP_Pos) & ECAP_ECEINT_CTR_EQ_CMP_Msk) /*!< CTR_EQ_CMP Set Value            */
#define ECAP_ECEINT_CTR_EQ_CMP_Get(x) (((uint32_t) (x) & ECAP_ECEINT_CTR_EQ_CMP_Msk) >> ECAP_ECEINT_CTR_EQ_CMP_Pos) /*!< CTR_EQ_CMP Get Value            */


#define ECAP_ECEINT_CTR_EQ_PRD_Pos    (6U)                                                                                  /*!< CTR_EQ_PRD Postion   6          */ 
#define ECAP_ECEINT_CTR_EQ_PRD_Msk    (0x1U << ECAP_ECEINT_CTR_EQ_PRD_Pos)                                             /*!< CTR_EQ_PRD Mask      0x00000040 */
#define ECAP_ECEINT_CTR_EQ_PRD_Set(x) (((uint32_t) (x) << ECAP_ECEINT_CTR_EQ_PRD_Pos) & ECAP_ECEINT_CTR_EQ_PRD_Msk) /*!< CTR_EQ_PRD Set Value            */
#define ECAP_ECEINT_CTR_EQ_PRD_Get(x) (((uint32_t) (x) & ECAP_ECEINT_CTR_EQ_PRD_Msk) >> ECAP_ECEINT_CTR_EQ_PRD_Pos) /*!< CTR_EQ_PRD Get Value            */


#define ECAP_ECEINT_CTROVF_Pos    (5U)                                                                                  /*!< CTROVF Postion   5          */ 
#define ECAP_ECEINT_CTROVF_Msk    (0x1U << ECAP_ECEINT_CTROVF_Pos)                                                 /*!< CTROVF Mask      0x00000020 */
#define ECAP_ECEINT_CTROVF_Set(x) (((uint32_t) (x) << ECAP_ECEINT_CTROVF_Pos) & ECAP_ECEINT_CTROVF_Msk)       /*!< CTROVF Set Value            */
#define ECAP_ECEINT_CTROVF_Get(x) (((uint32_t) (x) & ECAP_ECEINT_CTROVF_Msk) >> ECAP_ECEINT_CTROVF_Pos)       /*!< CTROVF Get Value            */


#define ECAP_ECEINT_CEVT4_Pos    (4U)                                                                                  /*!< CEVT4 Postion   4          */ 
#define ECAP_ECEINT_CEVT4_Msk    (0x1U << ECAP_ECEINT_CEVT4_Pos)                                                  /*!< CEVT4 Mask      0x00000010 */
#define ECAP_ECEINT_CEVT4_Set(x) (((uint32_t) (x) << ECAP_ECEINT_CEVT4_Pos) & ECAP_ECEINT_CEVT4_Msk)         /*!< CEVT4 Set Value            */
#define ECAP_ECEINT_CEVT4_Get(x) (((uint32_t) (x) & ECAP_ECEINT_CEVT4_Msk) >> ECAP_ECEINT_CEVT4_Pos)         /*!< CEVT4 Get Value            */


#define ECAP_ECEINT_CEVT3_Pos    (3U)                                                                                  /*!< CEVT3 Postion   3          */ 
#define ECAP_ECEINT_CEVT3_Msk    (0x1U << ECAP_ECEINT_CEVT3_Pos)                                                  /*!< CEVT3 Mask      0x00000008 */
#define ECAP_ECEINT_CEVT3_Set(x) (((uint32_t) (x) << ECAP_ECEINT_CEVT3_Pos) & ECAP_ECEINT_CEVT3_Msk)         /*!< CEVT3 Set Value            */
#define ECAP_ECEINT_CEVT3_Get(x) (((uint32_t) (x) & ECAP_ECEINT_CEVT3_Msk) >> ECAP_ECEINT_CEVT3_Pos)         /*!< CEVT3 Get Value            */


#define ECAP_ECEINT_CEVT2_Pos    (2U)                                                                                  /*!< CEVT2 Postion   2          */ 
#define ECAP_ECEINT_CEVT2_Msk    (0x1U << ECAP_ECEINT_CEVT2_Pos)                                                  /*!< CEVT2 Mask      0x00000004 */
#define ECAP_ECEINT_CEVT2_Set(x) (((uint32_t) (x) << ECAP_ECEINT_CEVT2_Pos) & ECAP_ECEINT_CEVT2_Msk)         /*!< CEVT2 Set Value            */
#define ECAP_ECEINT_CEVT2_Get(x) (((uint32_t) (x) & ECAP_ECEINT_CEVT2_Msk) >> ECAP_ECEINT_CEVT2_Pos)         /*!< CEVT2 Get Value            */


#define ECAP_ECEINT_CEVT1_Pos    (1U)                                                                                  /*!< CEVT1 Postion   1          */ 
#define ECAP_ECEINT_CEVT1_Msk    (0x1U << ECAP_ECEINT_CEVT1_Pos)                                                  /*!< CEVT1 Mask      0x00000002 */
#define ECAP_ECEINT_CEVT1_Set(x) (((uint32_t) (x) << ECAP_ECEINT_CEVT1_Pos) & ECAP_ECEINT_CEVT1_Msk)         /*!< CEVT1 Set Value            */
#define ECAP_ECEINT_CEVT1_Get(x) (((uint32_t) (x) & ECAP_ECEINT_CEVT1_Msk) >> ECAP_ECEINT_CEVT1_Pos)         /*!< CEVT1 Get Value            */


/* ECFLG bitfield */
#define ECAP_ECFLG_CTR_CMP_Pos    (7U)                                                                                  /*!< CTR_CMP Postion   7          */ 
#define ECAP_ECFLG_CTR_CMP_Msk    (0x1U << ECAP_ECFLG_CTR_CMP_Pos)                                                 /*!< CTR_CMP Mask      0x00000080 */
#define ECAP_ECFLG_CTR_CMP_Set(x) (((uint32_t) (x) << ECAP_ECFLG_CTR_CMP_Pos) & ECAP_ECFLG_CTR_CMP_Msk)       /*!< CTR_CMP Set Value            */
#define ECAP_ECFLG_CTR_CMP_Get(x) (((uint32_t) (x) & ECAP_ECFLG_CTR_CMP_Msk) >> ECAP_ECFLG_CTR_CMP_Pos)       /*!< CTR_CMP Get Value            */


#define ECAP_ECFLG_CTR_PRD_Pos    (6U)                                                                                  /*!< CTR_PRD Postion   6          */ 
#define ECAP_ECFLG_CTR_PRD_Msk    (0x1U << ECAP_ECFLG_CTR_PRD_Pos)                                                 /*!< CTR_PRD Mask      0x00000040 */
#define ECAP_ECFLG_CTR_PRD_Set(x) (((uint32_t) (x) << ECAP_ECFLG_CTR_PRD_Pos) & ECAP_ECFLG_CTR_PRD_Msk)       /*!< CTR_PRD Set Value            */
#define ECAP_ECFLG_CTR_PRD_Get(x) (((uint32_t) (x) & ECAP_ECFLG_CTR_PRD_Msk) >> ECAP_ECFLG_CTR_PRD_Pos)       /*!< CTR_PRD Get Value            */


#define ECAP_ECFLG_CTROVF_Pos    (5U)                                                                                  /*!< CTROVF Postion   5          */ 
#define ECAP_ECFLG_CTROVF_Msk    (0x1U << ECAP_ECFLG_CTROVF_Pos)                                                  /*!< CTROVF Mask      0x00000020 */
#define ECAP_ECFLG_CTROVF_Set(x) (((uint32_t) (x) << ECAP_ECFLG_CTROVF_Pos) & ECAP_ECFLG_CTROVF_Msk)         /*!< CTROVF Set Value            */
#define ECAP_ECFLG_CTROVF_Get(x) (((uint32_t) (x) & ECAP_ECFLG_CTROVF_Msk) >> ECAP_ECFLG_CTROVF_Pos)         /*!< CTROVF Get Value            */


#define ECAP_ECFLG_CEVT4_Pos    (4U)                                                                                  /*!< CEVT4 Postion   4          */ 
#define ECAP_ECFLG_CEVT4_Msk    (0x1U << ECAP_ECFLG_CEVT4_Pos)                                                   /*!< CEVT4 Mask      0x00000010 */
#define ECAP_ECFLG_CEVT4_Set(x) (((uint32_t) (x) << ECAP_ECFLG_CEVT4_Pos) & ECAP_ECFLG_CEVT4_Msk)           /*!< CEVT4 Set Value            */
#define ECAP_ECFLG_CEVT4_Get(x) (((uint32_t) (x) & ECAP_ECFLG_CEVT4_Msk) >> ECAP_ECFLG_CEVT4_Pos)           /*!< CEVT4 Get Value            */


#define ECAP_ECFLG_CEVT3_Pos    (3U)                                                                                  /*!< CEVT3 Postion   3          */ 
#define ECAP_ECFLG_CEVT3_Msk    (0x1U << ECAP_ECFLG_CEVT3_Pos)                                                   /*!< CEVT3 Mask      0x00000008 */
#define ECAP_ECFLG_CEVT3_Set(x) (((uint32_t) (x) << ECAP_ECFLG_CEVT3_Pos) & ECAP_ECFLG_CEVT3_Msk)           /*!< CEVT3 Set Value            */
#define ECAP_ECFLG_CEVT3_Get(x) (((uint32_t) (x) & ECAP_ECFLG_CEVT3_Msk) >> ECAP_ECFLG_CEVT3_Pos)           /*!< CEVT3 Get Value            */


#define ECAP_ECFLG_CEVT2_Pos    (2U)                                                                                  /*!< CEVT2 Postion   2          */ 
#define ECAP_ECFLG_CEVT2_Msk    (0x1U << ECAP_ECFLG_CEVT2_Pos)                                                   /*!< CEVT2 Mask      0x00000004 */
#define ECAP_ECFLG_CEVT2_Set(x) (((uint32_t) (x) << ECAP_ECFLG_CEVT2_Pos) & ECAP_ECFLG_CEVT2_Msk)           /*!< CEVT2 Set Value            */
#define ECAP_ECFLG_CEVT2_Get(x) (((uint32_t) (x) & ECAP_ECFLG_CEVT2_Msk) >> ECAP_ECFLG_CEVT2_Pos)           /*!< CEVT2 Get Value            */


#define ECAP_ECFLG_CEVT1_Pos    (1U)                                                                                  /*!< CEVT1 Postion   1          */ 
#define ECAP_ECFLG_CEVT1_Msk    (0x1U << ECAP_ECFLG_CEVT1_Pos)                                                   /*!< CEVT1 Mask      0x00000002 */
#define ECAP_ECFLG_CEVT1_Set(x) (((uint32_t) (x) << ECAP_ECFLG_CEVT1_Pos) & ECAP_ECFLG_CEVT1_Msk)           /*!< CEVT1 Set Value            */
#define ECAP_ECFLG_CEVT1_Get(x) (((uint32_t) (x) & ECAP_ECFLG_CEVT1_Msk) >> ECAP_ECFLG_CEVT1_Pos)           /*!< CEVT1 Get Value            */


#define ECAP_ECFLG_INT_FLAG_Pos    (0U)                                                                                  /*!< INT_FLAG Postion   0          */ 
#define ECAP_ECFLG_INT_FLAG_Msk    (0x1U << ECAP_ECFLG_INT_FLAG_Pos)                                                /*!< INT_FLAG Mask      0x00000001 */
#define ECAP_ECFLG_INT_FLAG_Set(x) (((uint32_t) (x) << ECAP_ECFLG_INT_FLAG_Pos) & ECAP_ECFLG_INT_FLAG_Msk)     /*!< INT_FLAG Set Value            */
#define ECAP_ECFLG_INT_FLAG_Get(x) (((uint32_t) (x) & ECAP_ECFLG_INT_FLAG_Msk) >> ECAP_ECFLG_INT_FLAG_Pos)     /*!< INT_FLAG Get Value            */


/* ECCLR bitfield */
#define ECAP_ECCLR_CTR_CMP_Pos    (7U)                                                                                  /*!< CTR_CMP Postion   7          */ 
#define ECAP_ECCLR_CTR_CMP_Msk    (0x1U << ECAP_ECCLR_CTR_CMP_Pos)                                                 /*!< CTR_CMP Mask      0x00000080 */
#define ECAP_ECCLR_CTR_CMP_Set(x) (((uint32_t) (x) << ECAP_ECCLR_CTR_CMP_Pos) & ECAP_ECCLR_CTR_CMP_Msk)       /*!< CTR_CMP Set Value            */
#define ECAP_ECCLR_CTR_CMP_Get(x) (((uint32_t) (x) & ECAP_ECCLR_CTR_CMP_Msk) >> ECAP_ECCLR_CTR_CMP_Pos)       /*!< CTR_CMP Get Value            */


#define ECAP_ECCLR_CTR_PRD_Pos    (6U)                                                                                  /*!< CTR_PRD Postion   6          */ 
#define ECAP_ECCLR_CTR_PRD_Msk    (0x1U << ECAP_ECCLR_CTR_PRD_Pos)                                                 /*!< CTR_PRD Mask      0x00000040 */
#define ECAP_ECCLR_CTR_PRD_Set(x) (((uint32_t) (x) << ECAP_ECCLR_CTR_PRD_Pos) & ECAP_ECCLR_CTR_PRD_Msk)       /*!< CTR_PRD Set Value            */
#define ECAP_ECCLR_CTR_PRD_Get(x) (((uint32_t) (x) & ECAP_ECCLR_CTR_PRD_Msk) >> ECAP_ECCLR_CTR_PRD_Pos)       /*!< CTR_PRD Get Value            */


#define ECAP_ECCLR_CTROVF_Pos    (5U)                                                                                  /*!< CTROVF Postion   5          */ 
#define ECAP_ECCLR_CTROVF_Msk    (0x1U << ECAP_ECCLR_CTROVF_Pos)                                                  /*!< CTROVF Mask      0x00000020 */
#define ECAP_ECCLR_CTROVF_Set(x) (((uint32_t) (x) << ECAP_ECCLR_CTROVF_Pos) & ECAP_ECCLR_CTROVF_Msk)         /*!< CTROVF Set Value            */
#define ECAP_ECCLR_CTROVF_Get(x) (((uint32_t) (x) & ECAP_ECCLR_CTROVF_Msk) >> ECAP_ECCLR_CTROVF_Pos)         /*!< CTROVF Get Value            */


#define ECAP_ECCLR_CEVT4_Pos    (4U)                                                                                  /*!< CEVT4 Postion   4          */ 
#define ECAP_ECCLR_CEVT4_Msk    (0x1U << ECAP_ECCLR_CEVT4_Pos)                                                   /*!< CEVT4 Mask      0x00000010 */
#define ECAP_ECCLR_CEVT4_Set(x) (((uint32_t) (x) << ECAP_ECCLR_CEVT4_Pos) & ECAP_ECCLR_CEVT4_Msk)           /*!< CEVT4 Set Value            */
#define ECAP_ECCLR_CEVT4_Get(x) (((uint32_t) (x) & ECAP_ECCLR_CEVT4_Msk) >> ECAP_ECCLR_CEVT4_Pos)           /*!< CEVT4 Get Value            */


#define ECAP_ECCLR_CEVT3_Pos    (3U)                                                                                  /*!< CEVT3 Postion   3          */ 
#define ECAP_ECCLR_CEVT3_Msk    (0x1U << ECAP_ECCLR_CEVT3_Pos)                                                   /*!< CEVT3 Mask      0x00000008 */
#define ECAP_ECCLR_CEVT3_Set(x) (((uint32_t) (x) << ECAP_ECCLR_CEVT3_Pos) & ECAP_ECCLR_CEVT3_Msk)           /*!< CEVT3 Set Value            */
#define ECAP_ECCLR_CEVT3_Get(x) (((uint32_t) (x) & ECAP_ECCLR_CEVT3_Msk) >> ECAP_ECCLR_CEVT3_Pos)           /*!< CEVT3 Get Value            */


#define ECAP_ECCLR_CEVT2_Pos    (2U)                                                                                  /*!< CEVT2 Postion   2          */ 
#define ECAP_ECCLR_CEVT2_Msk    (0x1U << ECAP_ECCLR_CEVT2_Pos)                                                   /*!< CEVT2 Mask      0x00000004 */
#define ECAP_ECCLR_CEVT2_Set(x) (((uint32_t) (x) << ECAP_ECCLR_CEVT2_Pos) & ECAP_ECCLR_CEVT2_Msk)           /*!< CEVT2 Set Value            */
#define ECAP_ECCLR_CEVT2_Get(x) (((uint32_t) (x) & ECAP_ECCLR_CEVT2_Msk) >> ECAP_ECCLR_CEVT2_Pos)           /*!< CEVT2 Get Value            */


#define ECAP_ECCLR_CEVT1_Pos    (1U)                                                                                  /*!< CEVT1 Postion   1          */ 
#define ECAP_ECCLR_CEVT1_Msk    (0x1U << ECAP_ECCLR_CEVT1_Pos)                                                   /*!< CEVT1 Mask      0x00000002 */
#define ECAP_ECCLR_CEVT1_Set(x) (((uint32_t) (x) << ECAP_ECCLR_CEVT1_Pos) & ECAP_ECCLR_CEVT1_Msk)           /*!< CEVT1 Set Value            */
#define ECAP_ECCLR_CEVT1_Get(x) (((uint32_t) (x) & ECAP_ECCLR_CEVT1_Msk) >> ECAP_ECCLR_CEVT1_Pos)           /*!< CEVT1 Get Value            */


#define ECAP_ECCLR_INT_FLAG_CLR_Pos    (0U)                                                                                  /*!< INT_FLAG_CLR Postion   0          */ 
#define ECAP_ECCLR_INT_FLAG_CLR_Msk    (0x1U << ECAP_ECCLR_INT_FLAG_CLR_Pos)                                            /*!< INT_FLAG_CLR Mask      0x00000001 */
#define ECAP_ECCLR_INT_FLAG_CLR_Set(x) (((uint32_t) (x) << ECAP_ECCLR_INT_FLAG_CLR_Pos) & ECAP_ECCLR_INT_FLAG_CLR_Msk) /*!< INT_FLAG_CLR Set Value            */
#define ECAP_ECCLR_INT_FLAG_CLR_Get(x) (((uint32_t) (x) & ECAP_ECCLR_INT_FLAG_CLR_Msk) >> ECAP_ECCLR_INT_FLAG_CLR_Pos) /*!< INT_FLAG_CLR Get Value            */


/* ECFRC bitfield */
#define ECAP_ECFRC_CTR_CMP_Pos    (7U)                                                                                  /*!< CTR_CMP Postion   7          */ 
#define ECAP_ECFRC_CTR_CMP_Msk    (0x1U << ECAP_ECFRC_CTR_CMP_Pos)                                                 /*!< CTR_CMP Mask      0x00000080 */
#define ECAP_ECFRC_CTR_CMP_Set(x) (((uint32_t) (x) << ECAP_ECFRC_CTR_CMP_Pos) & ECAP_ECFRC_CTR_CMP_Msk)       /*!< CTR_CMP Set Value            */
#define ECAP_ECFRC_CTR_CMP_Get(x) (((uint32_t) (x) & ECAP_ECFRC_CTR_CMP_Msk) >> ECAP_ECFRC_CTR_CMP_Pos)       /*!< CTR_CMP Get Value            */


#define ECAP_ECFRC_CTR_PRD_Pos    (6U)                                                                                  /*!< CTR_PRD Postion   6          */ 
#define ECAP_ECFRC_CTR_PRD_Msk    (0x1U << ECAP_ECFRC_CTR_PRD_Pos)                                                 /*!< CTR_PRD Mask      0x00000040 */
#define ECAP_ECFRC_CTR_PRD_Set(x) (((uint32_t) (x) << ECAP_ECFRC_CTR_PRD_Pos) & ECAP_ECFRC_CTR_PRD_Msk)       /*!< CTR_PRD Set Value            */
#define ECAP_ECFRC_CTR_PRD_Get(x) (((uint32_t) (x) & ECAP_ECFRC_CTR_PRD_Msk) >> ECAP_ECFRC_CTR_PRD_Pos)       /*!< CTR_PRD Get Value            */


#define ECAP_ECFRC_CTROVF_Pos    (5U)                                                                                  /*!< CTROVF Postion   5          */ 
#define ECAP_ECFRC_CTROVF_Msk    (0x1U << ECAP_ECFRC_CTROVF_Pos)                                                  /*!< CTROVF Mask      0x00000020 */
#define ECAP_ECFRC_CTROVF_Set(x) (((uint32_t) (x) << ECAP_ECFRC_CTROVF_Pos) & ECAP_ECFRC_CTROVF_Msk)         /*!< CTROVF Set Value            */
#define ECAP_ECFRC_CTROVF_Get(x) (((uint32_t) (x) & ECAP_ECFRC_CTROVF_Msk) >> ECAP_ECFRC_CTROVF_Pos)         /*!< CTROVF Get Value            */


#define ECAP_ECFRC_CEVT4_Pos    (4U)                                                                                  /*!< CEVT4 Postion   4          */ 
#define ECAP_ECFRC_CEVT4_Msk    (0x1U << ECAP_ECFRC_CEVT4_Pos)                                                   /*!< CEVT4 Mask      0x00000010 */
#define ECAP_ECFRC_CEVT4_Set(x) (((uint32_t) (x) << ECAP_ECFRC_CEVT4_Pos) & ECAP_ECFRC_CEVT4_Msk)           /*!< CEVT4 Set Value            */
#define ECAP_ECFRC_CEVT4_Get(x) (((uint32_t) (x) & ECAP_ECFRC_CEVT4_Msk) >> ECAP_ECFRC_CEVT4_Pos)           /*!< CEVT4 Get Value            */


#define ECAP_ECFRC_CEVT3_Pos    (3U)                                                                                  /*!< CEVT3 Postion   3          */ 
#define ECAP_ECFRC_CEVT3_Msk    (0x1U << ECAP_ECFRC_CEVT3_Pos)                                                   /*!< CEVT3 Mask      0x00000008 */
#define ECAP_ECFRC_CEVT3_Set(x) (((uint32_t) (x) << ECAP_ECFRC_CEVT3_Pos) & ECAP_ECFRC_CEVT3_Msk)           /*!< CEVT3 Set Value            */
#define ECAP_ECFRC_CEVT3_Get(x) (((uint32_t) (x) & ECAP_ECFRC_CEVT3_Msk) >> ECAP_ECFRC_CEVT3_Pos)           /*!< CEVT3 Get Value            */


#define ECAP_ECFRC_CEVT2_Pos    (2U)                                                                                  /*!< CEVT2 Postion   2          */ 
#define ECAP_ECFRC_CEVT2_Msk    (0x1U << ECAP_ECFRC_CEVT2_Pos)                                                   /*!< CEVT2 Mask      0x00000004 */
#define ECAP_ECFRC_CEVT2_Set(x) (((uint32_t) (x) << ECAP_ECFRC_CEVT2_Pos) & ECAP_ECFRC_CEVT2_Msk)           /*!< CEVT2 Set Value            */
#define ECAP_ECFRC_CEVT2_Get(x) (((uint32_t) (x) & ECAP_ECFRC_CEVT2_Msk) >> ECAP_ECFRC_CEVT2_Pos)           /*!< CEVT2 Get Value            */


#define ECAP_ECFRC_CEVT1_Pos    (1U)                                                                                  /*!< CEVT1 Postion   1          */ 
#define ECAP_ECFRC_CEVT1_Msk    (0x1U << ECAP_ECFRC_CEVT1_Pos)                                                   /*!< CEVT1 Mask      0x00000002 */
#define ECAP_ECFRC_CEVT1_Set(x) (((uint32_t) (x) << ECAP_ECFRC_CEVT1_Pos) & ECAP_ECFRC_CEVT1_Msk)           /*!< CEVT1 Set Value            */
#define ECAP_ECFRC_CEVT1_Get(x) (((uint32_t) (x) & ECAP_ECFRC_CEVT1_Msk) >> ECAP_ECFRC_CEVT1_Pos)           /*!< CEVT1 Get Value            */


/* ECAPSYNCINSEL bitfield */
#define ECAP_ECAPSYNCINSEL_SYNC_EXP_NUM_Pos    (16U)                                                                                 /*!< SYNC_EXP_NUM Postion   16         */ 
#define ECAP_ECAPSYNCINSEL_SYNC_EXP_NUM_Msk    (0xffffU << ECAP_ECAPSYNCINSEL_SYNC_EXP_NUM_Pos)                                 /*!< SYNC_EXP_NUM Mask      0xFFFF0000 */
#define ECAP_ECAPSYNCINSEL_SYNC_EXP_NUM_Set(x) (((uint32_t) (x) << ECAP_ECAPSYNCINSEL_SYNC_EXP_NUM_Pos) & ECAP_ECAPSYNCINSEL_SYNC_EXP_NUM_Msk) /*!< SYNC_EXP_NUM Set Value            */
#define ECAP_ECAPSYNCINSEL_SYNC_EXP_NUM_Get(x) (((uint32_t) (x) & ECAP_ECAPSYNCINSEL_SYNC_EXP_NUM_Msk) >> ECAP_ECAPSYNCINSEL_SYNC_EXP_NUM_Pos) /*!< SYNC_EXP_NUM Get Value            */


#define ECAP_ECAPSYNCINSEL_SEL_Pos    (0U)                                                                                  /*!< SEL Postion   0          */ 
#define ECAP_ECAPSYNCINSEL_SEL_Msk    (0x1fU << ECAP_ECAPSYNCINSEL_SEL_Pos)                                            /*!< SEL Mask      0x0000001F */
#define ECAP_ECAPSYNCINSEL_SEL_Set(x) (((uint32_t) (x) << ECAP_ECAPSYNCINSEL_SEL_Pos) & ECAP_ECAPSYNCINSEL_SEL_Msk) /*!< SEL Set Value            */
#define ECAP_ECAPSYNCINSEL_SEL_Get(x) (((uint32_t) (x) & ECAP_ECAPSYNCINSEL_SEL_Msk) >> ECAP_ECAPSYNCINSEL_SEL_Pos) /*!< SEL Get Value            */


/* ECAP_OUT_SEL bitfield */
#define ECAP_ECAP_OUT_SEL_ECAP_OUT_EN_S_Pos    (1U)                                                                                  /*!< ECAP_OUT_EN_S Postion   1          */ 
#define ECAP_ECAP_OUT_SEL_ECAP_OUT_EN_S_Msk    (0x1U << ECAP_ECAP_OUT_SEL_ECAP_OUT_EN_S_Pos)                                    /*!< ECAP_OUT_EN_S Mask      0x00000002 */
#define ECAP_ECAP_OUT_SEL_ECAP_OUT_EN_S_Set(x) (((uint32_t) (x) << ECAP_ECAP_OUT_SEL_ECAP_OUT_EN_S_Pos) & ECAP_ECAP_OUT_SEL_ECAP_OUT_EN_S_Msk) /*!< ECAP_OUT_EN_S Set Value            */
#define ECAP_ECAP_OUT_SEL_ECAP_OUT_EN_S_Get(x) (((uint32_t) (x) & ECAP_ECAP_OUT_SEL_ECAP_OUT_EN_S_Msk) >> ECAP_ECAP_OUT_SEL_ECAP_OUT_EN_S_Pos) /*!< ECAP_OUT_EN_S Get Value            */


#define ECAP_ECAP_OUT_SEL_ECAP_OUT_S_Pos    (0U)                                                                                  /*!< ECAP_OUT_S Postion   0          */ 
#define ECAP_ECAP_OUT_SEL_ECAP_OUT_S_Msk    (0x1U << ECAP_ECAP_OUT_SEL_ECAP_OUT_S_Pos)                                       /*!< ECAP_OUT_S Mask      0x00000001 */
#define ECAP_ECAP_OUT_SEL_ECAP_OUT_S_Set(x) (((uint32_t) (x) << ECAP_ECAP_OUT_SEL_ECAP_OUT_S_Pos) & ECAP_ECAP_OUT_SEL_ECAP_OUT_S_Msk) /*!< ECAP_OUT_S Set Value            */
#define ECAP_ECAP_OUT_SEL_ECAP_OUT_S_Get(x) (((uint32_t) (x) & ECAP_ECAP_OUT_SEL_ECAP_OUT_S_Msk) >> ECAP_ECAP_OUT_SEL_ECAP_OUT_S_Pos) /*!< ECAP_OUT_S Get Value            */


/* HRCTL bitfield */
#define HRCAP_HRCTL_HRCAP_EN_Pos    (0U)                                                                                  /*!< HRCAP_EN Postion   0          */ 
#define HRCAP_HRCTL_HRCAP_EN_Msk    (0x1U << HRCAP_HRCTL_HRCAP_EN_Pos)                                               /*!< HRCAP_EN Mask      0x00000001 */
#define HRCAP_HRCTL_HRCAP_EN_Set(x) (((uint32_t) (x) << HRCAP_HRCTL_HRCAP_EN_Pos) & HRCAP_HRCTL_HRCAP_EN_Msk)   /*!< HRCAP_EN Set Value            */
#define HRCAP_HRCTL_HRCAP_EN_Get(x) (((uint32_t) (x) & HRCAP_HRCTL_HRCAP_EN_Msk) >> HRCAP_HRCTL_HRCAP_EN_Pos)   /*!< HRCAP_EN Get Value            */


/* HRCALICTL bitfield */
#define HRCAP_HRCALICTL_CALI_TRIG_Pos    (4U)                                                                                  /*!< CALI_TRIG Postion   4          */ 
#define HRCAP_HRCALICTL_CALI_TRIG_Msk    (0x1U << HRCAP_HRCALICTL_CALI_TRIG_Pos)                                          /*!< CALI_TRIG Mask      0x00000010 */
#define HRCAP_HRCALICTL_CALI_TRIG_Set(x) (((uint32_t) (x) << HRCAP_HRCALICTL_CALI_TRIG_Pos) & HRCAP_HRCALICTL_CALI_TRIG_Msk) /*!< CALI_TRIG Set Value            */
#define HRCAP_HRCALICTL_CALI_TRIG_Get(x) (((uint32_t) (x) & HRCAP_HRCALICTL_CALI_TRIG_Msk) >> HRCAP_HRCALICTL_CALI_TRIG_Pos) /*!< CALI_TRIG Get Value            */


#define HRCAP_HRCALICTL_CALI_MOD_Pos    (1U)                                                                                  /*!< CALI_MOD Postion   1          */ 
#define HRCAP_HRCALICTL_CALI_MOD_Msk    (0x3U << HRCAP_HRCALICTL_CALI_MOD_Pos)                                           /*!< CALI_MOD Mask      0x00000006 */
#define HRCAP_HRCALICTL_CALI_MOD_Set(x) (((uint32_t) (x) << HRCAP_HRCALICTL_CALI_MOD_Pos) & HRCAP_HRCALICTL_CALI_MOD_Msk) /*!< CALI_MOD Set Value            */
#define HRCAP_HRCALICTL_CALI_MOD_Get(x) (((uint32_t) (x) & HRCAP_HRCALICTL_CALI_MOD_Msk) >> HRCAP_HRCALICTL_CALI_MOD_Pos) /*!< CALI_MOD Get Value            */


#define HRCAP_HRCALICTL_CALI_EN_Pos    (0U)                                                                                  /*!< CALI_EN Postion   0          */ 
#define HRCAP_HRCALICTL_CALI_EN_Msk    (0x1U << HRCAP_HRCALICTL_CALI_EN_Pos)                                            /*!< CALI_EN Mask      0x00000001 */
#define HRCAP_HRCALICTL_CALI_EN_Set(x) (((uint32_t) (x) << HRCAP_HRCALICTL_CALI_EN_Pos) & HRCAP_HRCALICTL_CALI_EN_Msk) /*!< CALI_EN Set Value            */
#define HRCAP_HRCALICTL_CALI_EN_Get(x) (((uint32_t) (x) & HRCAP_HRCALICTL_CALI_EN_Msk) >> HRCAP_HRCALICTL_CALI_EN_Pos) /*!< CALI_EN Get Value            */


/* CALI_INTERVAL bitfield */
#define HRCAP_CALI_INTERVAL_CALI_INTERVAL_Pos    (0U)                                                                                  /*!< CALI_INTERVAL Postion   0          */ 
#define HRCAP_CALI_INTERVAL_CALI_INTERVAL_Msk    (0xffffffffU << HRCAP_CALI_INTERVAL_CALI_INTERVAL_Pos)                           /*!< CALI_INTERVAL Mask      0xFFFFFFFF */
#define HRCAP_CALI_INTERVAL_CALI_INTERVAL_Set(x) (((uint32_t) (x) << HRCAP_CALI_INTERVAL_CALI_INTERVAL_Pos) & HRCAP_CALI_INTERVAL_CALI_INTERVAL_Msk) /*!< CALI_INTERVAL Set Value            */
#define HRCAP_CALI_INTERVAL_CALI_INTERVAL_Get(x) (((uint32_t) (x) & HRCAP_CALI_INTERVAL_CALI_INTERVAL_Msk) >> HRCAP_CALI_INTERVAL_CALI_INTERVAL_Pos) /*!< CALI_INTERVAL Get Value            */


/* HRCAP_DATA_H bitfield */
#define HRCAP_HRCAP_DATA_H_HRCAP_CAP_DATA_H_Pos    (0U)                                                                                  /*!< HRCAP_CAP_DATA_H Postion   0          */ 
#define HRCAP_HRCAP_DATA_H_HRCAP_CAP_DATA_H_Msk    (0xffffffffU << HRCAP_HRCAP_DATA_H_HRCAP_CAP_DATA_H_Pos)                         /*!< HRCAP_CAP_DATA_H Mask      0xFFFFFFFF */
#define HRCAP_HRCAP_DATA_H_HRCAP_CAP_DATA_H_Set(x) (((uint32_t) (x) << HRCAP_HRCAP_DATA_H_HRCAP_CAP_DATA_H_Pos) & HRCAP_HRCAP_DATA_H_HRCAP_CAP_DATA_H_Msk) /*!< HRCAP_CAP_DATA_H Set Value            */
#define HRCAP_HRCAP_DATA_H_HRCAP_CAP_DATA_H_Get(x) (((uint32_t) (x) & HRCAP_HRCAP_DATA_H_HRCAP_CAP_DATA_H_Msk) >> HRCAP_HRCAP_DATA_H_HRCAP_CAP_DATA_H_Pos) /*!< HRCAP_CAP_DATA_H Get Value            */


/* HRCAP_DATA_L bitfield */
#define HRCAP_HRCAP_DATA_L_HRCAP_CAP_DATA_L_Pos    (0U)                                                                                  /*!< HRCAP_CAP_DATA_L Postion   0          */ 
#define HRCAP_HRCAP_DATA_L_HRCAP_CAP_DATA_L_Msk    (0xffffffffU << HRCAP_HRCAP_DATA_L_HRCAP_CAP_DATA_L_Pos)                         /*!< HRCAP_CAP_DATA_L Mask      0xFFFFFFFF */
#define HRCAP_HRCAP_DATA_L_HRCAP_CAP_DATA_L_Set(x) (((uint32_t) (x) << HRCAP_HRCAP_DATA_L_HRCAP_CAP_DATA_L_Pos) & HRCAP_HRCAP_DATA_L_HRCAP_CAP_DATA_L_Msk) /*!< HRCAP_CAP_DATA_L Set Value            */
#define HRCAP_HRCAP_DATA_L_HRCAP_CAP_DATA_L_Get(x) (((uint32_t) (x) & HRCAP_HRCAP_DATA_L_HRCAP_CAP_DATA_L_Msk) >> HRCAP_HRCAP_DATA_L_HRCAP_CAP_DATA_L_Pos) /*!< HRCAP_CAP_DATA_L Get Value            */


/* CALI_DATA_H bitfield */
#define HRCAP_CALI_DATA_H_HRCAP_CALI_DATA_H_Pos    (0U)                                                                                  /*!< HRCAP_CALI_DATA_H Postion   0          */ 
#define HRCAP_CALI_DATA_H_HRCAP_CALI_DATA_H_Msk    (0xffffffffU << HRCAP_CALI_DATA_H_HRCAP_CALI_DATA_H_Pos)                         /*!< HRCAP_CALI_DATA_H Mask      0xFFFFFFFF */
#define HRCAP_CALI_DATA_H_HRCAP_CALI_DATA_H_Set(x) (((uint32_t) (x) << HRCAP_CALI_DATA_H_HRCAP_CALI_DATA_H_Pos) & HRCAP_CALI_DATA_H_HRCAP_CALI_DATA_H_Msk) /*!< HRCAP_CALI_DATA_H Set Value            */
#define HRCAP_CALI_DATA_H_HRCAP_CALI_DATA_H_Get(x) (((uint32_t) (x) & HRCAP_CALI_DATA_H_HRCAP_CALI_DATA_H_Msk) >> HRCAP_CALI_DATA_H_HRCAP_CALI_DATA_H_Pos) /*!< HRCAP_CALI_DATA_H Get Value            */


/* CALI_DATA_L bitfield */
#define HRCAP_CALI_DATA_L_HRCAP_CALI_DATA_L_Pos    (0U)                                                                                  /*!< HRCAP_CALI_DATA_L Postion   0          */ 
#define HRCAP_CALI_DATA_L_HRCAP_CALI_DATA_L_Msk    (0xffffffffU << HRCAP_CALI_DATA_L_HRCAP_CALI_DATA_L_Pos)                         /*!< HRCAP_CALI_DATA_L Mask      0xFFFFFFFF */
#define HRCAP_CALI_DATA_L_HRCAP_CALI_DATA_L_Set(x) (((uint32_t) (x) << HRCAP_CALI_DATA_L_HRCAP_CALI_DATA_L_Pos) & HRCAP_CALI_DATA_L_HRCAP_CALI_DATA_L_Msk) /*!< HRCAP_CALI_DATA_L Set Value            */
#define HRCAP_CALI_DATA_L_HRCAP_CALI_DATA_L_Get(x) (((uint32_t) (x) & HRCAP_CALI_DATA_L_HRCAP_CALI_DATA_L_Msk) >> HRCAP_CALI_DATA_L_HRCAP_CALI_DATA_L_Pos) /*!< HRCAP_CALI_DATA_L Get Value            */


/* HRCAP_IE bitfield */
#define HRCAP_HRCAP_IE_HRCAP_CALI_DONE_IE_Pos    (0U)                                                                                  /*!< HRCAP_CALI_DONE_IE Postion   0          */ 
#define HRCAP_HRCAP_IE_HRCAP_CALI_DONE_IE_Msk    (0x1U << HRCAP_HRCAP_IE_HRCAP_CALI_DONE_IE_Pos)                                  /*!< HRCAP_CALI_DONE_IE Mask      0x00000001 */
#define HRCAP_HRCAP_IE_HRCAP_CALI_DONE_IE_Set(x) (((uint32_t) (x) << HRCAP_HRCAP_IE_HRCAP_CALI_DONE_IE_Pos) & HRCAP_HRCAP_IE_HRCAP_CALI_DONE_IE_Msk) /*!< HRCAP_CALI_DONE_IE Set Value            */
#define HRCAP_HRCAP_IE_HRCAP_CALI_DONE_IE_Get(x) (((uint32_t) (x) & HRCAP_HRCAP_IE_HRCAP_CALI_DONE_IE_Msk) >> HRCAP_HRCAP_IE_HRCAP_CALI_DONE_IE_Pos) /*!< HRCAP_CALI_DONE_IE Get Value            */


/* HRCAP_FLG bitfield */
#define HRCAP_HRCAP_FLG_HRCAP_CALI_DONE_Pos    (0U)                                                                                  /*!< HRCAP_CALI_DONE Postion   0          */ 
#define HRCAP_HRCAP_FLG_HRCAP_CALI_DONE_Msk    (0x1U << HRCAP_HRCAP_FLG_HRCAP_CALI_DONE_Pos)                                    /*!< HRCAP_CALI_DONE Mask      0x00000001 */
#define HRCAP_HRCAP_FLG_HRCAP_CALI_DONE_Set(x) (((uint32_t) (x) << HRCAP_HRCAP_FLG_HRCAP_CALI_DONE_Pos) & HRCAP_HRCAP_FLG_HRCAP_CALI_DONE_Msk) /*!< HRCAP_CALI_DONE Set Value            */
#define HRCAP_HRCAP_FLG_HRCAP_CALI_DONE_Get(x) (((uint32_t) (x) & HRCAP_HRCAP_FLG_HRCAP_CALI_DONE_Msk) >> HRCAP_HRCAP_FLG_HRCAP_CALI_DONE_Pos) /*!< HRCAP_CALI_DONE Get Value            */


/* HRCAP_FLG_CLR bitfield */
#define HRCAP_HRCAP_FLG_CLR_HRCAP_CALI_DONE_CLR_Pos    (0U)                                                                                  /*!< HRCAP_CALI_DONE_CLR Postion   0          */ 
#define HRCAP_HRCAP_FLG_CLR_HRCAP_CALI_DONE_CLR_Msk    (0x1U << HRCAP_HRCAP_FLG_CLR_HRCAP_CALI_DONE_CLR_Pos)                            /*!< HRCAP_CALI_DONE_CLR Mask      0x00000001 */
#define HRCAP_HRCAP_FLG_CLR_HRCAP_CALI_DONE_CLR_Set(x) (((uint32_t) (x) << HRCAP_HRCAP_FLG_CLR_HRCAP_CALI_DONE_CLR_Pos) & HRCAP_HRCAP_FLG_CLR_HRCAP_CALI_DONE_CLR_Msk) /*!< HRCAP_CALI_DONE_CLR Set Value            */
#define HRCAP_HRCAP_FLG_CLR_HRCAP_CALI_DONE_CLR_Get(x) (((uint32_t) (x) & HRCAP_HRCAP_FLG_CLR_HRCAP_CALI_DONE_CLR_Msk) >> HRCAP_HRCAP_FLG_CLR_HRCAP_CALI_DONE_CLR_Pos) /*!< HRCAP_CALI_DONE_CLR Get Value            */


/*!
 * @}
 */


/*!
 * @}
 */ /* end of HS32F7D377_ECAP_REGISTER */

#endif /* HS32F7D377_ECAP_H */
