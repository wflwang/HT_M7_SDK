/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


/*!
 * \file   HS32F7D377_epwm.h
 * \brief  HS32F7D377 EPWM register file
 * \version V1.0_20230713
 */

#ifndef HS32F7D377_EPWM_H
#define HS32F7D377_EPWM_H

/*!
 * \addtogroup   HS32F7D377_EPWM_REGISTER HS32F7D377 EPWM Register
 * \ingroup HS32F7D377_REGISTER
 *
 * \brief  EPWM register layout, bitfield and address definitions
 *
 * @{
 */

/*!
 * \name EPWM Register Layout
 *
 *
 * @{
 */

/*! \brief EPWM_REGS register */
typedef struct {
    union
    {
        __IOM uint16_t TBCTL;  /*!< 0x00000000 */ 
       
        struct
        {
            __IOM uint16_t CTRMODE                   : 2 ;     /*!< [1:0] : Counter Mode                                                    <br>  The time-base counter mode is normally configured once and not changed during normal operation. */
            __IOM uint16_t PHSEN                     : 1 ;     /*!< [2:2] : Counter Reg Load from Phase Reg Enable                          <br>  0: Do not load the time-base counter (TBCTR) from the time-base phase register (TBPHS). */
            __IOM uint16_t PRDLD                     : 1 ;     /*!< [3:3] : Active Period Reg Load from Shadow Select                       <br>  0: The period register (TBPRD) is loaded from its shadow register when the time-base counter, TBCTR, is equal to zero and/or a sync event as determined by the TBCTL2[PRDLDSYNC] bit. */
                  uint16_t RSV_0                     : 2 ;     /*!< [5:4] : reserved. */
            __IOM uint16_t SWFSYNC                   : 1 ;     /*!< [6:6] : Software Forced Sync Pulse                                      <br>  0: Writing a 0 has no effect and reads always return a 0. */
            __IOM uint16_t HSPCLKDIV                 : 3 ;     /*!< [9:7] : High Speed Time Base Clock Pre-Scale Bits                       <br>  These bits determine part of the time-base clock prescale value. */
            __IOM uint16_t CLKDIV                    : 3 ;     /*!< [12:10] : Time Base Clock Pre-Scale Bits                                  <br>  These bits select the time base clock pre-scale value (TBCLK = EPWMCLK/(HSPCLKDIV * CLKDIV):<br>  000: /1 (default on reset) 001: /2                              <br>  010: /4                                                         <br>  011: /8                                                         <br>  100: /16                                                        <br>  101: /32                                                        <br>  110: /64                                                        <br>  111: /128                                                       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint16_t PHSDIR                    : 1 ;     /*!< [13:13] : Phase Direction Bit                                             <br>  This bit is only used when the time-base counter is configured in the up-down-count mode. */
            __IOM uint16_t FREE_SOFT                 : 2 ;     /*!< [15:14] : Emulation Mode Bits. */
        } TBCTLb;
    };

    union
    {
        __IOM uint16_t TBCTL2;  /*!< 0x00000002 */ 
       
        struct
        {
                  uint16_t RSV_1                     : 6 ;     /*!< [5:0] : reserved. */
            __IOM uint16_t OSHTSYNCMODE              : 1 ;     /*!< [6:6] : Oneshot sync enable bit                                         <br>  0: Oneshot sync mode disabled 1: Oneshot sync mode enabled Reset type: SYSRSn<br>. */
            __IOM uint16_t OSHTSYNC                  : 1 ;     /*!< [7:7] : Oneshot sync bit                                                <br>  0: Writing a '0' has no effect. */
                  uint16_t RSV_0                     : 6 ;     /*!< [13:8] : reserved. */
            __IOM uint16_t PRDLDSYNC                 : 2 ;     /*!< [15:14] : Shadow to Active Period Register Load on SYNC event             <br>  00: Shadow to Active Load of TBPRD occurs only when TBCTR = 0 (same as legacy). */
        } TBCTL2b;
    };

    uint8_t    RSV_0X4[2];   /*!< 0x00000004~0x00000005 : reserved */

    union
    {
        __IOM uint16_t EPWMSYNCINSEL;  /*!< 0x00000006 */ 
       
        struct
        {
            __IOM uint16_t SEL                       : 5 ;     /*!< [4:0] : These bits determine the source of the EPWMxSYNCI signal. */
                  uint16_t RSV_0                     : 11;     /*!< [15:5] : reserved. */
        } EPWMSYNCINSELb;
    };

    union
    {
        __IOM uint16_t TBCTR;  /*!< 0x00000008 */ 
       
        struct
        {
            __IOM uint16_t TBCTR                     : 16;     /*!< [15:0] : Time Base Counter Register Reset type: SYSRSn. */
        } TBCTRb;
    };

    union
    {
        __IOM uint16_t TBSTS;  /*!< 0x0000000a */ 
       
        struct
        {
            __IM  uint16_t CTRDIR                    : 1 ;     /*!< [0:0] : Time Base Counter Direction Status Bit                          <br>  0: Time-Base Counter is currently counting down. */
            __IOM uint16_t SYNCI                     : 1 ;     /*!< [1:1] : Input Synchronization Latched Status Bit                        <br>  0: Writing a 0 will have no effect. */
            __IOM uint16_t CTRMAX                    : 1 ;     /*!< [2:2] : Time-Base Counter Max Latched Status Bit                        <br>  0: Reading a 0 indicates the time-base counter never reached its maximum value. */
                  uint16_t RSV_0                     : 13;     /*!< [15:3] : reserved. */
        } TBSTSb;
    };

    union
    {
        __IOM uint16_t EPWMSYNCOUTEN;  /*!< 0x0000000c */ 
       
        struct
        {
            __IOM uint16_t SWEN                      : 1 ;     /*!< [0:0] : This bit enables the TBCTL. */
            __IOM uint16_t ZEROEN                    : 1 ;     /*!< [1:1] : This bit enables the TBCTR = 0x0000 event to set the EPWMxSYNCOUT signal. */
            __IOM uint16_t CMPBEN                    : 1 ;     /*!< [2:2] : This bit enables the TBCTR = CMPB event to set the EPWMxSYNCO signal. */
            __IOM uint16_t CMPCEN                    : 1 ;     /*!< [3:3] : This bit enables the TBCTR = CMPC event to set the EPWMxSYNCO signal. */
            __IOM uint16_t CMPDEN                    : 1 ;     /*!< [4:4] : This bit enables the TBCTR = CMPD event to set the EPWMxSYNCO signal. */
            __IOM uint16_t DCAEVT1EN                 : 1 ;     /*!< [5:5] : This bit enables the DCAEVT1. */
            __IOM uint16_t DCBEVT1EN                 : 1 ;     /*!< [6:6] : This bit enables the DCBEVT1. */
                  uint16_t RSV_0                     : 9 ;     /*!< [15:7] : reserved. */
        } EPWMSYNCOUTENb;
    };

    union
    {
        __IOM uint16_t TBCTL3;  /*!< 0x0000000e */ 
       
        struct
        {
            __IOM uint16_t OSSFRCEN                  : 1 ;     /*!< [0:0] : This bit determines which bit sets the EPWMxSYNCOUT One Shot Latch. */
                  uint16_t RSV_0                     : 15;     /*!< [15:1] : reserved. */
        } TBCTL3b;
    };

    union
    {
        __IOM uint16_t CMPCTL;  /*!< 0x00000010 */ 
       
        struct
        {
            __IOM uint16_t LOADAMODE                 : 2 ;     /*!< [1:0] : Active Counter-Compare A (CMPA) Load From Shadow Select Mode This bit has no effect in immediate mode (CMPCTL[SHDWAMODE]<br>  = 1). */
            __IOM uint16_t LOADBMODE                 : 2 ;     /*!< [3:2] : Active Counter-Compare B (CMPB) Load From Shadow Select Mode    <br>  This bit has no effect in immediate mode (CMPCTL[SHDWBMODE]     <br>  = 1). */
            __IOM uint16_t SHDWAMODE                 : 1 ;     /*!< [4:4] : Counter-compare A (CMPA) Register Operating Mode                <br>  0: Shadow mode. */
                  uint16_t RSV_2                     : 1 ;     /*!< [5:5] : reserved. */
            __IOM uint16_t SHDWBMODE                 : 1 ;     /*!< [6:6] : Counter-compare B (CMPB) Register Operating Mode                <br>  0: Shadow mode. */
                  uint16_t RSV_1                     : 1 ;     /*!< [7:7] : reserved. */
            __IM  uint16_t SHDWAFULL                 : 1 ;     /*!< [8:8] : Counter-compare A (CMPA) Shadow Register Full Status Flag       <br>  The flag bit is set when a 32-bit write to CMPA:CMPAHR register or a 16-bit write to CMPA register is made. */
            __IM  uint16_t SHDWBFULL                 : 1 ;     /*!< [9:9] : Counter-compare B (CMPB) Shadow Register Full Status Flag This bit self clears once a loadstrobe occurs. */
            __IOM uint16_t LOADASYNC                 : 2 ;     /*!< [11:10] : Shadow to Active CMPA Register Load on SYNC event               <br>  00: Shadow to Active Load of CMPA:CMPAHR occurs according to LOADAMODE (bits 1,0) (same as legacy)<br>  01: Shadow to Active Load of CMPA:CMPAHR occurs both according to LOADAMODE bits and when SYNC occurs<br>  10: Shadow to Active Load of CMPA:CMPAHR occurs only when a SYNC is received<br>  11: Reserved                                                    <br>  Note: This bit is valid only if CMPCTL[SHDWAMODE] = 0. */
            __IOM uint16_t LOADBSYNC                 : 2 ;     /*!< [13:12] : Shadow to Active CMPB Register Load on SYNC event               <br>  00: Shadow to Active Load of CMPB:CMPBHR occurs according to LOADBMODE (bits 1,0) (same as legacy)<br>  01: Shadow to Active Load of CMPB:CMPBHR occurs both according to LOADBMODE bits and when SYNC occurs<br>  10: Shadow to Active Load of CMPB:CMPBHR occurs only when a SYNC is received<br>  11: Reserved                                                    <br>  Note: This bit is valid only if CMPCTL[SHDWBMODE] = 0. */
                  uint16_t RSV_0                     : 2 ;     /*!< [15:14] : reserved. */
        } CMPCTLb;
    };

    union
    {
        __IOM uint16_t CMPCTL2;  /*!< 0x00000012 */ 
       
        struct
        {
            __IOM uint16_t LOADCMODE                 : 2 ;     /*!< [1:0] : Active Counter-Compare C (CMPC) Load from Shadow Select Mode 00: Load on CTR = Zero: Time-base counter equal to zero (TBCTR = 0x0000)<br>  01: Load on CTR = PRD: Time-base counter equal to period (TBCTR <br>  = TBPRD)                                                        <br>  10: Load on either CTR = Zero or CTR = PRD 11: Freeze (no loads possible)<br>  Note: Has no effect in Immediate mode. */
            __IOM uint16_t LOADDMODE                 : 2 ;     /*!< [3:2] : Active Counter-Compare D (CMPD) Load from Shadow Select Mode 00: Load on CTR = Zero: Time-base counter equal to zero (TBCTR = 0x0000)<br>  01: Load on CTR = PRD: Time-base counter equal to period (TBCTR <br>  = TBPRD)                                                        <br>  10: Load on either CTR = Zero or CTR = PRD 11: Freeze (no loads possible)<br>  Note: Has no effect in Immediate mode. */
            __IOM uint16_t SHDWCMODE                 : 1 ;     /*!< [4:4] : Counter-Compare C Register Operating Mode                       <br>  0: Shadow mode - operates as a double buffer. */
                  uint16_t RSV_2                     : 1 ;     /*!< [5:5] : reserved. */
            __IOM uint16_t SHDWDMODE                 : 1 ;     /*!< [6:6] : Counter-Compare D Register Operating Mode                       <br>  0: Shadow mode - operates as a double buffer. */
                  uint16_t RSV_1                     : 3 ;     /*!< [9:7] : reserved. */
            __IOM uint16_t LOADCSYNC                 : 2 ;     /*!< [11:10] : Shadow to Active CMPC Register Load on SYNC event 00: Shadow to Active Load of CMPC occurs according to LOADCMODE<br>  01: Shadow to Active Load of CMPC occurs both according to LOADCMODE bits and when SYNC occurs<br>  10: Shadow to Active Load of CMPC occurs only when a SYNC is received<br>  11: Reserved                                                    <br>  Note: This bit is valid only if CMPCTL2[SHDWCMODE] = 0. */
            __IOM uint16_t LOADDSYNC                 : 2 ;     /*!< [13:12] : Shadow to Active CMPD Register Load on SYNC event 00: Shadow to Active Load of CMPD occurs according to LOADDMODE<br>  01: Shadow to Active Load of CMPD occurs both according to LOADDMODE bits and when SYNC occurs<br>  10: Shadow to Active Load of CMPD occurs only when a SYNC is received<br>  11: Reserved                                                    <br>  Note: This bit is valid only if CMPCTL2[SHDWDMODE] = 0. */
                  uint16_t RSV_0                     : 2 ;     /*!< [15:14] : reserved. */
        } CMPCTL2b;
    };

    uint8_t    RSV_0X14[4];   /*!< 0x00000014~0x00000017 : reserved */

    union
    {
        __IOM uint16_t DBCTL;  /*!< 0x00000018 */ 
       
        struct
        {
            __IOM uint16_t OUT_MODE                  : 2 ;     /*!< [1:0] : Dead-Band Output Mode Control                                   <br>  Bit 1 controls the S1 switch and bit 0 controls the S0 switch. */
            __IOM uint16_t POLSEL                    : 2 ;     /*!< [3:2] : Polarity Select Control                                         <br>  Bit 3 controls the S3 switch and bit 2 controls the S2 switch. */
            __IOM uint16_t IN_MODE                   : 2 ;     /*!< [5:4] : Dead-Band Input Mode Control                                    <br>  Bit 5 controls the S5 switch and bit 4 controls the S4 switch shown. */
            __IOM uint16_t LOADREDMODE               : 2 ;     /*!< [7:6] : Active DBRED Load from Shadow Select Mode 00: Load on Counter = 0 (CNT_eq)<br>  01: Load on Counter = Period (PRD_eq)                           <br>  10: Load on either Counter = 0, or Counter = Period 11: Freeze (no loads possible)<br>  Note: has no effect in Immediate mode. */
            __IOM uint16_t LOADFEDMODE               : 2 ;     /*!< [9:8] : Active DBFED Load from Shadow Select Mode 00: Load on Counter = 0 (CNT_eq)<br>  01: Load on Counter = Period (PRD_eq)                           <br>  10: Load on either Counter = 0, or Counter = Period 11: Freeze (no loads possible)<br>  Note: has no effect in Immediate mode. */
            __IOM uint16_t SHDWDBREDMODE             : 1 ;     /*!< [10:10] : RED Dead-Band Load Mode                                         <br>  0: Immediate mode. */
            __IOM uint16_t SHDWDBFEDMODE             : 1 ;     /*!< [11:11] : FED Dead-Band Load Mode                                         <br>  0: Immediate mode. */
            __IOM uint16_t OUTSWAP                   : 2 ;     /*!< [13:12] : Dead Band Output Swap Control                                   <br>  Bit 13 controls the S6 switch and bit 12 controls the S7 switch. */
            __IOM uint16_t DEDB_MODE                 : 1 ;     /*!< [14:14] : Dead Band Dual-Edge B Mode Control (S8 switch)                  <br>  0: Rising edge delay applied to InA/InB as selected by S4 switch (IN- MODE bits) on A signal path only. */
            __IOM uint16_t HALFCYCLE                 : 1 ;     /*!< [15:15] : Half Cycle Clocking Enable Bit                                  <br>  0: Full cycle clocking enabled. */
        } DBCTLb;
    };

    union
    {
        __IOM uint16_t DBCTL2;  /*!< 0x0000001a */ 
       
        struct
        {
            __IOM uint16_t LOADDBCTLMODE             : 2 ;     /*!< [1:0] : Active DBCTL Load from Shadow Select Mode 00: Load on Counter = 0 (CNT_eq)<br>  01: Load on Counter = Period (PRD_eq)                           <br>  10: Load on either Counter = 0, or Counter = Period 11: Freeze (no loads possible)<br>  Note: has no effect in Immediate mode Reset type: SYSRSn        <br>. */
            __IOM uint16_t SHDWDBCTLMODE             : 1 ;     /*!< [2:2] : DBCTL Load Mode                                                 <br>  0: Immediate mode - only the Active DBCTL register is used. */
                  uint16_t RSV_0                     : 13;     /*!< [15:3] : reserved. */
        } DBCTL2b;
    };

    uint8_t    RSV_0X1C[4];   /*!< 0x0000001c~0x0000001f : reserved */

    union
    {
        __IOM uint16_t AQCTL;  /*!< 0x00000020 */ 
       
        struct
        {
            __IOM uint16_t LDAQAMODE                 : 2 ;     /*!< [1:0] : Active Action Qualifier A Load from Shadow Select Mode          <br>  00: Load on CTR = Zero: Time-base counter equal to zero (TBCTR = 0x0000)<br>  01: Load on CTR = PRD: Time-base counter equal to period (TBCTR <br>  = TBPRD)                                                        <br>  10: Load on either CTR = Zero or CTR = PRD 11: Freeze (no loads possible)<br>  Note: has no effect in Immediate mode. */
            __IOM uint16_t LDAQBMODE                 : 2 ;     /*!< [3:2] : Active Action Qualifier B Load from Shadow Select Mode          <br>  00: Load on CTR = Zero: Time-base counter equal to zero (TBCTR = 0x0000)<br>  01: Load on CTR = PRD: Time-base counter equal to period (TBCTR <br>  = TBPRD)                                                        <br>  10: Load on either CTR = Zero or CTR = PRD 11: Freeze (no loads possible)<br>  Note: has no effect in Immediate mode. */
            __IOM uint16_t SHDWAQAMODE               : 1 ;     /*!< [4:4] : Action Qualifier A Register operating mode                      <br>  1: Shadow mode - operates as a double buffer. */
                  uint16_t RSV_2                     : 1 ;     /*!< [5:5] : reserved. */
            __IOM uint16_t SHDWAQBMODE               : 1 ;     /*!< [6:6] : Action Qualifier B Register operating mode                      <br>  1: Shadow mode - operates as a double buffer. */
                  uint16_t RSV_1                     : 1 ;     /*!< [7:7] : reserved. */
            __IOM uint16_t LDAQASYNC                 : 2 ;     /*!< [9:8] : Shadow to Active AQCTLA Register Load on SYNC event 00: Shadow to Active Load of AQCTLA occurs according to LDAQAMODE<br>  01: Shadow to Active Load of AQCTLA occurs both according to LDAQAMODE bits and when SYNC occurs. */
            __IOM uint16_t LDAQBSYNC                 : 2 ;     /*!< [11:10] : Shadow to Active AQCTLB Register Load on SYNC event 00: Shadow to Active Load of AQCTLB occurs according to LDAQBMODE<br>  01: Shadow to Active Load of AQCTLB occurs both according to LDAQBMODE bits and when SYNC occurs. */
                  uint16_t RSV_0                     : 4 ;     /*!< [15:12] : reserved. */
        } AQCTLb;
    };

    union
    {
        __IOM uint16_t AQTSRCSEL;  /*!< 0x00000022 */ 
       
        struct
        {
            __IOM uint16_t T1SEL                     : 4 ;     /*!< [3:0] : T1 Event Source Select Bits 0000: DCAEVT1                       <br>  0001: DCAEVT2                                                   <br>  0010: DCBEVT1                                                   <br>  0011: DCBEVT2                                                   <br>  0100: TZ1                                                       <br>  0101: TZ2                                                       <br>  0110: TZ3                                                       <br>  0111: EPWMxSYNCI                                                <br>  1000: DCEVTFILT                                                 <br>  Others: Reserved Reset type: SYSRSn                             <br>. */
            __IOM uint16_t T2SEL                     : 4 ;     /*!< [7:4] : T2 Event Source Select Bits 0000: DCAEVT1                       <br>  0001: DCAEVT2                                                   <br>  0010: DCBEVT1                                                   <br>  0011: DCBEVT2                                                   <br>  0100: TZ1                                                       <br>  0101: TZ2                                                       <br>  0110: TZ3                                                       <br>  0111: EPWMxSYNCI                                                <br>  1000: DCEVTFILT                                                 <br>  Others: Reserved Reset type: SYSRSn                             <br>. */
                  uint16_t RSV_0                     : 8 ;     /*!< [15:8] : reserved. */
        } AQTSRCSELb;
    };

    uint8_t    RSV_0X24[4];   /*!< 0x00000024~0x00000027 : reserved */

    union
    {
        __IOM uint32_t PCCTL;  /*!< 0x00000028 */ 
       
        struct
        {
            __IOM uint32_t CHPEN                     : 1 ;     /*!< [0:0] : PWM-Chopping Enable                                             <br>  0: Disable (bypass) PWM chopping function 1: Enable chopping function<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t OSHTWTH                   : 4 ;     /*!< [4:1] : One-Shot Pulse Width                                            <br>  0000: 1 x EPWMCLK / 8 wide ( = 80 ns at 100 MHz EPWMCLK)        <br>  0001: 2 x EPWMCLK / 8 wide ( = 160 ns at 100 MHz EPWMCLK)       <br>  0010: 3 x EPWMCLK / 8 wide ( = 240 ns at 100 MHz EPWMCLK)       <br>  0011: 4 x EPWMCLK / 8 wide ( = 320 ns at 100 MHz EPWMCLK)       <br>  0100: 5 x EPWMCLK / 8 wide ( = 400 ns at 100 MHz EPWMCLK)       <br>  0101: 6 x EPWMCLK / 8 wide ( = 480 ns at 100 MHz EPWMCLK)       <br>  0110: 7 x EPWMCLK / 8 wide ( = 560 ns at 100 MHz EPWMCLK)       <br>  0111: 8 x EPWMCLK / 8 wide ( = 640 ns at 100 MHz EPWMCLK)       <br>  1000: 9 x EPWMCLK / 8 wide ( = 720 ns at 100 MHz EPWMCLK)       <br>  1001: 10 x EPWMCLK / 8 wide ( = 800 ns at 100 MHz EPWMCLK)      <br>  1010: 11 x EPWMCLK / 8 wide ( = 880 ns at 100 MHz EPWMCLK)      <br>  1011: 12 x EPWMCLK / 8 wide ( = 960 ns at 100 MHz EPWMCLK)      <br>  1100: 13 x EPWMCLK / 8 wide ( = 1040 ns at 100 MHz EPWMCLK)     <br>  1101: 14 x EPWMCLK / 8 wide ( = 1120 ns at 100 MHz EPWMCLK)     <br>  1110: 15 x EPWMCLK / 8 wide ( = 1200 ns at 100 MHz EPWMCLK)     <br>  1111: 16 x EPWMCLK / 8 wide ( = 1280 ns at 100 MHz EPWMCLK)     <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t CHPFREQ                   : 3 ;     /*!< [7:5] : Chopping Clock Frequency                                        <br>  000: Divide by 1 (no prescale, = 12. */
            __IOM uint32_t CHPDUTY                   : 3 ;     /*!< [10:8] : Chopping Clock Duty Cycle 000: Duty = 1/8 (12. */
            __IOM uint32_t CHPMODE                   : 1 ;     /*!< [11:11] : Chopping Mode                                                   <br>  0: Carrier generate all the time                                <br>  1: Carrier generate only when One-Shot Pulse Width is Low       <br>  Reset type: SYSRSn                                              <br>. */
                  uint32_t RSV_0                     : 20;     /*!< [31:12] : reserved. */
        } PCCTLb;
    };

    uint8_t    RSV_0X2C[4];   /*!< 0x0000002c~0x0000002f : reserved */

    union
    {
        __IOM uint16_t VCAPCTL;  /*!< 0x00000030 */ 
       
        struct
        {
            __IOM uint16_t VCAPE                     : 1 ;     /*!< [0:0] : Valley Capture Enable/Disable 0: Disabled                       <br>  1: Enabled                                                      <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint16_t VCAPSTART                 : 1 ;     /*!< [1:1] : Valley Capture Start                                            <br>  0: Writing a 0 has no effect                                    <br>  1: Trigger the capture sequence once if VCAPCTL[TRIGSEL]=0x0 Note: This bit is used to start valley capture sequence through software. */
            __IOM uint16_t TRIGSEL                   : 3 ;     /*!< [4:2] : Status of Numbered of Captured Events                           <br>  000: Capture sequence is triggered by software via writes to VCAPCTL[VCAPSTART]. */
                  uint16_t RSV_1                     : 2 ;     /*!< [6:5] : reserved. */
            __IOM uint16_t VDELATDIV                 : 3 ;     /*!< [9:7] : Valley Delay Mode Divide Enable 000: HWVDELVAL = SWVDELVAL      <br>  001: HWVDELVAL = VCNTVAL+SWVDELVAL                              <br>  010: HWVDELVAL = VCNTVAL>>1+SWVDELVAL                           <br>  011: HWVDELVAL = VCNTVAL>>2+SWVDELVAL                           <br>  100: HWVDELVAL = VCNTVAL>>4+SWVDELVAL                           <br>  Note: Delay value between the consecutive edge captures can optionally be divided by using these bits. */
            __IOM uint16_t EDGEFILTDLYSEL            : 1 ;     /*!< [10:10] : Valley Switching Mode Delay Selection                           <br>  0: No delay applied to the edge filter output                   <br>  1: HWDELAYVAL delay applied to the edge filter output Reset type: SYSRSn<br>. */
                  uint16_t RSV_0                     : 5 ;     /*!< [15:11] : reserved. */
        } VCAPCTLb;
    };

    union
    {
        __IOM uint16_t VCNTCFG;  /*!< 0x00000032 */ 
       
        struct
        {
            __IOM uint16_t STARTEDGE                 : 4 ;     /*!< [3:0] : Counter Start Edge Selection                                    <br>  Once the counter operation is armed, upon occurrence of trigger pulse selected through VCAPCTL[TRIGSEL] pulse - valley counter would start counting upon the occurrence of chosen number of events thorough this bit field. */
                  uint16_t RSV_1                     : 3 ;     /*!< [6:4] : reserved. */
            __IM  uint16_t STARTEDGESTS              : 1 ;     /*!< [7:7] : Start Edge Status Bit                                           <br>  0: Start edge has not occurred 1: Start edge occurred           <br>  Note: This bit is set only after the trigger sequence is armed (upon occurrence of trigger pulse selected through VCAPCTL[TRIGSEL]) and STARTEDGE occurs. */
            __IOM uint16_t STOPEDGE                  : 4 ;     /*!< [11:8] : Counter Stop Edge Selection                                     <br>  Once the counter operation is armed, upon occurrence of trigger pulse selected through VCAPCTL[TRIGSEL] pulse - valley counter would stop counting upon the occurrence of chosen number of events thorough this bit field. */
                  uint16_t RSV_0                     : 3 ;     /*!< [14:12] : reserved. */
            __IM  uint16_t STOPEDGESTS               : 1 ;     /*!< [15:15] : Stop Edge Status Bit                                            <br>  0: Stop edge has not occurred 1: Stop edge occurred             <br>  Note: This bit is set only after the trigger sequence is armed (upon occurrence of trigger pulse selected through VCAPCTL[TRIGSEL]) and STOPEDGE occurs. */
        } VCNTCFGb;
    };

    uint8_t    RSV_0X34[38];   /*!< 0x00000034~0x00000059 : reserved */

    union
    {
        __IOM uint16_t HRPCTL;  /*!< 0x0000005a */ 
       
        struct
        {
                  uint16_t RSV_2                     : 1 ;     /*!< [0:0] : reserved. */
            __IOM uint16_t PWMSYNCSEL                : 1 ;     /*!< [1:1] : PWMSYNC Source Select Bit: This bit selects the source for the EPWMSYNCPER signal that goes to the CMPSS and GPDAC: <br>  0 CTR = PRD: Time-base counter equal to period (TBCTR = TBPRD)  <br>  1 CTR = zero: Time-base counter equal to zero (TBCTR = 0x00) Reset type: SYSRSn<br>. */
                  uint16_t RSV_1                     : 2 ;     /*!< [3:2] : reserved. */
            __IOM uint16_t PWMSYNCSELX               : 3 ;     /*!< [6:4] : Extended selection bits for EPWMSYNCPER                         <br>  000: EPWMSYNCPER is defined by PWMSYNCSEL - > default condition (compatible with previous EPWM versions)<br>  001: Reserved                                                   <br>  010: Reserved                                                   <br>  011: Reserved                                                   <br>  100: CTR = CMPC, Count direction Up                             <br>  101: CTR = CMPC, Count direction Down                           <br>  110: CTR = CMPD, Count direction Up                             <br>  111: CTR = CMPD, Count direction Down Reset type: SYSRSn        <br>. */
                  uint16_t RSV_0                     : 9 ;     /*!< [15:7] : reserved. */
        } HRPCTLb;
    };

    uint8_t    RSV_0X5C[12];   /*!< 0x0000005c~0x00000067 : reserved */

    union
    {
        __IOM uint16_t GLDCTL;  /*!< 0x00000068 */ 
       
        struct
        {
            __IOM uint16_t GLD                       : 1 ;     /*!< [0:0] : Global Shadow to Active Load Event Control                      <br>  0: Shadow to active reload for all shadowed registers happens as per the individual reload control bits specified (Compatible with previous EPWM versions). */
            __IOM uint16_t GLDMODE                   : 4 ;     /*!< [4:1] : Global Load Pulse selection for Shadow to Active Mode Reloads 0000: Load on Counter = 0 (CNT_ZRO)<br>  0001: Load on Counter = Period (PRD_EQ)                         <br>  0010: Load on either Counter = 0, or Counter = Period           <br>  0011: Load on SYNCEVT - this is logical OR of DCAEVT1. */
            __IOM uint16_t OSHTMODE                  : 1 ;     /*!< [5:5] : One Shot Load Mode Control Bit                                  <br>  0: One shot load mode is disabled and shadow to active loading happens continuously on all the chosen load strobes. */
                  uint16_t RSV_1                     : 1 ;     /*!< [6:6] : reserved. */
            __IOM uint16_t GLDPRD                    : 3 ;     /*!< [9:7] : Global Load Strobe Period Select Register                       <br>  These bits select how many selected events need to occur before a load strobe is generated<br>  000: Disable counter                                            <br>  001: Generate strobe on GLDCNT = 001 (1st event) 010: Generate strobe on GLDCNT = 010 (2nd event) 011: Generate strobe on GLDCNT = 011 (3rd event) 100: Generate strobe on GLDCNT = 011 (4th event) 101: Generate strobe on GLDCNT = 001 (5th event) 110: Generate strobe on GLDCNT = 010 (6th event) 111: Generate strobe on GLDCNT = 011 (7th event) Reset type: SYSRSn<br>. */
            __IM  uint16_t GLDCNT                    : 3 ;     /*!< [12:10] : Global Load Strobe Counter Register                             <br>  These bits indicate how many selected events have occurred: 000: No events<br>  001: 1 event                                                    <br>  010: 2 events                                                   <br>  011: 3 events                                                   <br>  100: 4 events                                                   <br>  101: 5 events                                                   <br>  110: 6 events                                                   <br>  111: 7 events                                                   <br>  Reset type: SYSRSn                                              <br>. */
                  uint16_t RSV_0                     : 3 ;     /*!< [15:13] : reserved. */
        } GLDCTLb;
    };

    union
    {
        __IOM uint16_t GLDCFG;  /*!< 0x0000006a */ 
       
        struct
        {
            __IOM uint16_t TBPRD_TBPRDHR             : 1 ;     /*!< [0:0] : 0: Registers use local reload configuration even if GLDCTL(GLD)=1 (reload is compatible with previous EPWMs)<br>  1: Registers use global load configuration if this bit is set and GLDCTL(GLD)=1<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint16_t CMPA                      : 1 ;     /*!< [1:1] : Global load event configuration for CMPA_CMPAHR                 <br>  0: Registers use local reload configuration even if GLDCTL(GLD)=1 (reload is compatible with previous EPWMs)<br>  1: Registers use global load configuration if this bit is set and GLDCTL(GLD)=1<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint16_t CMPB                      : 1 ;     /*!< [2:2] : Global load event configuration for CMPB_CMPBHR                 <br>  0: Registers use local reload configuration even if GLDCTL(GLD)=1 (reload is compatible with previous EPWMs)<br>  1: Registers use global load configuration if this bit is set and GLDCTL(GLD)=1<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint16_t CMPC                      : 1 ;     /*!< [3:3] : Global load event configuration for CMPC                        <br>  0: Registers use local reload configuration even if GLDCTL(GLD)=1 (reload is compatible with previous EPWMs)<br>  1: Registers use global load configuration if this bit is set and GLDCTL(GLD)=1<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint16_t CMPD                      : 1 ;     /*!< [4:4] : Global load event configuration for CMPD                        <br>  0: Registers use local reload configuration even if GLDCTL(GLD)=1 (reload is compatible with previous EPWMs)<br>  1: Registers use global load configuration if this bit is set and GLDCTL(GLD)=1<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint16_t DBRED                     : 1 ;     /*!< [5:5] : Global load event configuration for DBRED_DBREDHR               <br>  0: Registers use local reload configuration even if GLDCTL(GLD)=1 (reload is compatible with previous EPWMs)<br>  1: Registers use global load configuration if this bit is set and GLDCTL(GLD)=1<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint16_t DBFED                     : 1 ;     /*!< [6:6] : Global load event configuration for DBFED_DBFEDHR               <br>  0: Registers use local reload configuration even if GLDCTL(GLD)=1 (reload is compatible with previous EPWMs)<br>  1: Registers use global load configuration if this bit is set and GLDCTL(GLD)=1<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint16_t DBCTL                     : 1 ;     /*!< [7:7] : Global load event configuration for DBCTL                       <br>  0: Registers use local reload configuration even if GLDCTL(GLD)=1 (reload is compatible with previous EPWMs)<br>  1: Registers use global load configuration if this bit is set and GLDCTL(GLD)=1<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint16_t AQCTLA_AQCTLA2            : 1 ;     /*!< [8:8] : Global load event configuration for AQCTLA_AQCTLA2              <br>  0: Registers use local reload configuration even if GLDCTL(GLD)=1 (reload is compatible with previous EPWMs)<br>  1: Registers use global load configuration if this bit is set and GLDCTL(GLD)=1<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint16_t AQCTLB_AQCTLB2            : 1 ;     /*!< [9:9] : Global load event configuration for AQCTLB_AQCTLB2              <br>  0: Registers use local reload configuration even if GLDCTL(GLD)=1 (reload is compatible with previous EPWMs)<br>  1: Registers use global load configuration if this bit is set and GLDCTL(GLD)=1<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint16_t AQCSFRC                   : 1 ;     /*!< [10:10] : Global load event configuration for AQCSFRC                     <br>  0: Registers use local reload configuration even if GLDCTL(GLD)=1 (reload is compatible with previous EPWMs)<br>  1: Registers use global load configuration if this bit is set and GLDCTL(GLD)=1<br>  Reset type: SYSRSn                                              <br>. */
                  uint16_t RSV_0                     : 5 ;     /*!< [15:11] : reserved. */
        } GLDCFGb;
    };

    uint8_t    RSV_0X6C[4];   /*!< 0x0000006c~0x0000006f : reserved */

    union
    {
        __IOM uint32_t EPWMXLINK;  /*!< 0x00000070 */ 
       
        struct
        {
            __IOM uint32_t TBPRDLINK                 : 4 ;     /*!< [3:0] : TBPRD_TBPRDHR Link Bits                                         <br>  Writes to the TBPRD:TBPRDHR registers in the ePWM module selected by the following bit selections results in a simultaneous write to the current ePWM module's TBPRD_TBPRDHR registers. */
            __IOM uint32_t CMPALINK                  : 4 ;     /*!< [7:4] : CMPA_CMPAHR Link Bits                                           <br>  Writes to the CMPA_CMPAHR registers in the ePWM module selected by the following bit selections results in a simultaneous write to the current ePWM module's CMPA_CMPAHR registers. */
            __IOM uint32_t CMPBLINK                  : 4 ;     /*!< [11:8] : CMPB_CMPBHR Link Bits                                           <br>  Writes to the CMPB_CMPBHR registers in the ePWM module selected by the following bit selections results in a simultaneous write to the current ePWM module's CMPB_CMPBHR registers. */
            __IOM uint32_t CMPCLINK                  : 4 ;     /*!< [15:12] : CMPC Link Bits                                                  <br>  Writes to the CMPC registers in the ePWM module selected by the following bit selections results in a simultaneous write to the current ePWM module's CMPC registers. */
            __IOM uint32_t CMPDLINK                  : 4 ;     /*!< [19:16] : CMPD Link Bits                                                  <br>  Writes to the CMPD registers in the ePWM module selected by the following bit selections results in a simultaneous write to the current ePWM module's CMPD registers. */
                  uint32_t RSV_0                     : 8 ;     /*!< [27:20] : reserved. */
            __IOM uint32_t GLDCTL2LINK               : 4 ;     /*!< [31:28] : GLDCTL2 Link Bits                                               <br>  Writes to the GLDCTL2 registers in the ePWM module selected by the following bit selections results in a simultaneous write to the current ePWM module's GLDCTL2 registers. */
        } EPWMXLINKb;
    };

    uint8_t    RSV_0X74[12];   /*!< 0x00000074~0x0000007f : reserved */

    union
    {
        __IOM uint16_t AQCTLA;  /*!< 0x00000080 */ 
       
        struct
        {
            __IOM uint16_t ZRO                       : 2 ;     /*!< [1:0] : Action When TBCTR = 0                                           <br>  Note: By definition, in count up-down mode when the counter equals 0 the direction is defined as 1 or counting up. */
            __IOM uint16_t PRD                       : 2 ;     /*!< [3:2] : Action When TBCTR = TBPRD                                       <br>  Note: By definition, in count up-down mode when the counter equals 0 the direction is defined as 1 or counting up. */
            __IOM uint16_t CAU                       : 2 ;     /*!< [5:4] : Action When TBCTR = CMPA on Up Count                            <br>  Note: By definition, in count up-down mode when the counter equals 0 the direction is defined as 1 or counting up. */
            __IOM uint16_t CAD                       : 2 ;     /*!< [7:6] : Action When TBCTR = CMPA on Down Count                          <br>  Note: By definition, in count up-down mode when the counter equals 0 the direction is defined as 1 or counting up. */
            __IOM uint16_t CBU                       : 2 ;     /*!< [9:8] : Action When TBCTR = CMPB on Up Count                            <br>  Note: By definition, in count up-down mode when the counter equals 0 the direction is defined as 1 or counting up. */
            __IOM uint16_t CBD                       : 2 ;     /*!< [11:10] : Action When TBCTR = CMPB on Down Count                          <br>  Note: By definition, in count up-down mode when the counter equals 0 the direction is defined as 1 or counting up. */
                  uint16_t RSV_0                     : 4 ;     /*!< [15:12] : reserved. */
        } AQCTLAb;
    };

    union
    {
        __IOM uint16_t AQCTLA2;  /*!< 0x00000082 */ 
       
        struct
        {
            __IOM uint16_t T1U                       : 2 ;     /*!< [1:0] : Action when event occurs on T1 in UP-Count                      <br>  Note: By definition, in count up-down mode when the counter equals 0 the direction is defined as 1 or counting up. */
            __IOM uint16_t T1D                       : 2 ;     /*!< [3:2] : Action when event occurs on T1 in DOWN-Count                    <br>  Note: By definition, in count up-down mode when the counter equals 0 the direction is defined as 1 or counting up. */
            __IOM uint16_t T2U                       : 2 ;     /*!< [5:4] : Action when event occurs on T2 in UP-Count                      <br>  Note: By definition, in count up-down mode when the counter equals 0 the direction is defined as 1 or counting up. */
            __IOM uint16_t T2D                       : 2 ;     /*!< [7:6] : Action when event occurs on T2 in DOWN-Count                    <br>  Note: By definition, in count up-down mode when the counter equals 0 the direction is defined as 1 or counting up. */
                  uint16_t RSV_0                     : 8 ;     /*!< [15:8] : reserved. */
        } AQCTLA2b;
    };

    union
    {
        __IOM uint16_t AQCTLB;  /*!< 0x00000084 */ 
       
        struct
        {
            __IOM uint16_t ZRO                       : 2 ;     /*!< [1:0] : Action When TBCTR = 0                                           <br>  Note: By definition, in count up-down mode when the counter equals 0 the direction is defined as 1 or counting up. */
            __IOM uint16_t PRD                       : 2 ;     /*!< [3:2] : Action When TBCTR = TBPRD                                       <br>  Note: By definition, in count up-down mode when the counter equals 0 the direction is defined as 1 or counting up. */
            __IOM uint16_t CAU                       : 2 ;     /*!< [5:4] : Action When TBCTR = CMPA on Up Count                            <br>  Note: By definition, in count up-down mode when the counter equals 0 the direction is defined as 1 or counting up. */
            __IOM uint16_t CAD                       : 2 ;     /*!< [7:6] : Action When TBCTR = CMPA on Down Count                          <br>  Note: By definition, in count up-down mode when the counter equals 0 the direction is defined as 1 or counting up. */
            __IOM uint16_t CBU                       : 2 ;     /*!< [9:8] : Action When TBCTR = CMPB on Up Count                            <br>  Note: By definition, in count up-down mode when the counter equals 0 the direction is defined as 1 or counting up. */
            __IOM uint16_t CBD                       : 2 ;     /*!< [11:10] : Action When TBCTR = CMPB on Down Count                          <br>  Note: By definition, in count up-down mode when the counter equals 0 the direction is defined as 1 or counting up. */
                  uint16_t RSV_0                     : 4 ;     /*!< [15:12] : reserved. */
        } AQCTLBb;
    };

    union
    {
        __IOM uint16_t AQCTLB2;  /*!< 0x00000086 */ 
       
        struct
        {
            __IOM uint16_t T1U                       : 2 ;     /*!< [1:0] : Action when event occurs on T1 in UP-Count                      <br>  Note: By definition, in count up-down mode when the counter equals 0 the direction is defined as 1 or counting up. */
            __IOM uint16_t T1D                       : 2 ;     /*!< [3:2] : Action when event occurs on T1 in DOWN-Count                    <br>  Note: By definition, in count up-down mode when the counter equals 0 the direction is defined as 1 or counting up. */
            __IOM uint16_t T2U                       : 2 ;     /*!< [5:4] : Action when event occurs on T2 in UP-Count                      <br>  Note: By definition, in count up-down mode when the counter equals 0 the direction is defined as 1 or counting up. */
            __IOM uint16_t T2D                       : 2 ;     /*!< [7:6] : Action when event occurs on T2 in DOWN-Count                    <br>  Note: By definition, in count up-down mode when the counter equals 0 the direction is defined as 1 or counting up. */
                  uint16_t RSV_0                     : 8 ;     /*!< [15:8] : reserved. */
        } AQCTLB2b;
    };

    uint8_t    RSV_0X88[6];   /*!< 0x00000088~0x0000008d : reserved */

    union
    {
        __IOM uint16_t AQSFRC;  /*!< 0x0000008e */ 
       
        struct
        {
            __IOM uint16_t ACTSFA                    : 2 ;     /*!< [1:0] : Action When One-Time Software Force A Is Invoked 00: Does nothing (action disabled)<br>  01: Clear (low)                                                 <br>  10: Set (high)                                                  <br>  11: Toggle (Low -> High, High -> Low)                           <br>  Note: This action is not qualified by counter direction (CNT_dir) Reset type: SYSRSn<br>. */
            __IOM uint16_t OTSFA                     : 1 ;     /*!< [2:2] : One-Time Software Forced Event on Output A                      <br>  0: Writing a 0 (zero) has no effect. */
            __IOM uint16_t ACTSFB                    : 2 ;     /*!< [4:3] : Action When One-Time Software Force B is Invoked 00: Does nothing (action disabled)<br>  01: Clear (low)                                                 <br>  10: Set (high)                                                  <br>  11: Toggle (Low -> High, High -> Low)                           <br>  Note: This action is not qualified by counter direction (CNT_dir) Reset type: SYSRSn<br>. */
            __IOM uint16_t OTSFB                     : 1 ;     /*!< [5:5] : One-Time Software Forced Event on Output B                      <br>  0: Writing a 0 (zero) has no effect. */
            __IOM uint16_t RLDCSF                    : 2 ;     /*!< [7:6] : AQCSFRC Active Register Reload From Shadow Options 00: Load on event counter equals zero<br>  01: Load on event counter equals period                         <br>  10: Load on event counter equals zero or counter equals period  <br>  11: Load immediately (the active register is directly accessed by the CPU and is not loaded from the shadow register). */
                  uint16_t RSV_0                     : 8 ;     /*!< [15:8] : reserved. */
        } AQSFRCb;
    };

    uint8_t    RSV_0X90[2];   /*!< 0x00000090~0x00000091 : reserved */

    union
    {
        __IOM uint16_t AQCSFRC;  /*!< 0x00000092 */ 
       
        struct
        {
            __IOM uint16_t CSFA                      : 2 ;     /*!< [1:0] : Continuous Software Force on Output A                           <br>  In immediate mode, a continuous force takes effect on the next TBCLK edge. */
            __IOM uint16_t CSFB                      : 2 ;     /*!< [3:2] : Continuous Software Force on Output B                           <br>  In immediate mode, a continuous force takes effect on the next TBCLK edge. */
                  uint16_t RSV_0                     : 12;     /*!< [15:4] : reserved. */
        } AQCSFRCb;
    };

    uint8_t    RSV_0X94[14];   /*!< 0x00000094~0x000000a1 : reserved */

    union
    {
        __IOM uint16_t DBRED;  /*!< 0x000000a2 */ 
       
        struct
        {
            __IOM uint16_t DBRED                     : 14;     /*!< [13:0] : Rising edge delay value Reset type: SYSRSn. */
                  uint16_t RSV_0                     : 2 ;     /*!< [15:14] : reserved. */
        } DBREDb;
    };

    uint8_t    RSV_0XA4[2];   /*!< 0x000000a4~0x000000a5 : reserved */

    union
    {
        __IOM uint16_t DBFED;  /*!< 0x000000a6 */ 
       
        struct
        {
            __IOM uint16_t DBFED                     : 14;     /*!< [13:0] : Falling Edge Delay Count 14-bit counter Reset type: SYSRSn. */
                  uint16_t RSV_0                     : 2 ;     /*!< [15:14] : reserved. */
        } DBFEDb;
    };

    uint8_t    RSV_0XA8[24];   /*!< 0x000000a8~0x000000bf : reserved */

    union
    {
        __IOM uint32_t TBPHS;  /*!< 0x000000c0 */ 
       
        struct
        {
                  uint32_t RSV_0                     : 16;     /*!< [15:0] : reserved. */
            __IOM uint32_t TBPHS                     : 16;     /*!< [31:16] : Phase Offset Register                                           <br>  These bits set time-base counter phase of the selected ePWM relative to the time-base that is supplying the synchronization input signal. */
        } TBPHSb;
    };

    union
    {
        __IOM uint32_t TBPRD;  /*!< 0x000000c4 */ 
       
        struct
        {
                  uint32_t RSV_0                     : 16;     /*!< [15:0] : reserved. */
            __IOM uint32_t TBPRD                     : 16;     /*!< [31:16] : Time Base Period Register                                       <br>  These bits determine the period of the time-base counter. */
        } TBPRDb;
    };

    uint8_t    RSV_0XC8[12];   /*!< 0x000000c8~0x000000d3 : reserved */

    union
    {
        __IOM uint32_t CMPA;  /*!< 0x000000d4 */ 
       
        struct
        {
                  uint32_t RSV_0                     : 16;     /*!< [15:0] : reserved. */
            __IOM uint32_t CMPA                      : 16;     /*!< [31:16] : Compare A Register                                              <br>  The value in the active CMPA register is continuously compared to the time-base counter (TBCTR). */
        } CMPAb;
    };

    union
    {
        __IOM uint32_t CMPB;  /*!< 0x000000d8 */ 
       
        struct
        {
                  uint32_t RSV_0                     : 16;     /*!< [15:0] : reserved. */
            __IOM uint32_t CMPB                      : 16;     /*!< [31:16] : Compare B Register                                              <br>  The value in the active CMPB register is continuously compared to the time-base counter (TBCTR). */
        } CMPBb;
    };

    uint8_t    RSV_0XDC[2];   /*!< 0x000000dc~0x000000dd : reserved */

    union
    {
        __IOM uint16_t CMPC;  /*!< 0x000000de */ 
       
        struct
        {
            __IOM uint16_t CMPC                      : 16;     /*!< [15:0] : Compare C Register                                              <br>  The value in the active CMPC register is continuously compared to the time-base counter (TBCTR). */
        } CMPCb;
    };

    uint8_t    RSV_0XE0[2];   /*!< 0x000000e0~0x000000e1 : reserved */

    union
    {
        __IOM uint16_t CMPD;  /*!< 0x000000e2 */ 
       
        struct
        {
            __IOM uint16_t CMPD                      : 16;     /*!< [15:0] : Compare D Register                                              <br>  The value in the active CMPD register is continuously compared to the time-base counter (TBCTR). */
        } CMPDb;
    };

    uint8_t    RSV_0XE4[4];   /*!< 0x000000e4~0x000000e7 : reserved */

    union
    {
        __IOM uint32_t GLDCTL2;  /*!< 0x000000e8 */ 
       
        struct
        {
            __IOM uint32_t OSHTLD                    : 1 ;     /*!< [0:0] : Enable Reload Event in One Shot Mode                            <br>  0: Writing of 0 will be ignored. */
            __IOM uint32_t GFRCLD                    : 1 ;     /*!< [1:1] : Force Load Event in One Shot Mode                               <br>  0: Writing of 0 will be ignored. */
                  uint32_t RSV_0                     : 30;     /*!< [31:2] : reserved. */
        } GLDCTL2b;
    };

    uint8_t    RSV_0XEC[2];   /*!< 0x000000ec~0x000000ed : reserved */

    union
    {
        __IOM uint16_t SWVDELVAL;  /*!< 0x000000ee */ 
       
        struct
        {
            __IOM uint16_t SWVDELVAL                 : 16;     /*!< [15:0] : Software Valley Delay Value Register                            <br>  This register can be optionally used define offset value for the hardware calculated delay HWDELAYVAL as defined in VCAPCTL[VDELAYDIV] bits. */
        } SWVDELVALb;
    };

    uint8_t    RSV_0XF0[16];   /*!< 0x000000f0~0x000000ff : reserved */

    union
    {
        __IOM uint32_t TZSEL;  /*!< 0x00000100 */ 
       
        struct
        {
            __IOM uint32_t CBC1                      : 1 ;     /*!< [0:0] : Trip-zone 1 (TZ1) Select                                        <br>  0: Disable TZ1 as a CBC trip source for this ePWM module 1: Enable TZ1 as a CBC trip source for this ePWM module Reset type: SYSRSn<br>. */
            __IOM uint32_t CBC2                      : 1 ;     /*!< [1:1] : Trip-zone 2 (TZ2) Select                                        <br>  0: Disable TZ2 as a CBC trip source for this ePWM module 1: Enable TZ2 as a CBC trip source for this ePWM module Reset type: SYSRSn<br>. */
            __IOM uint32_t CBC3                      : 1 ;     /*!< [2:2] : Trip-zone 3 (TZ3) Select                                        <br>  0: Disable TZ3 as a CBC trip source for this ePWM module 1: Enable TZ3 as a CBC trip source for this ePWM module Reset type: SYSRSn<br>. */
            __IOM uint32_t CBC4                      : 1 ;     /*!< [3:3] : Trip-zone 4 (TZ4) Select                                        <br>  0: Disable TZ4 as a CBC trip source for this ePWM module 1: Enable TZ4 as a CBC trip source for this ePWM module Reset type: SYSRSn<br>. */
            __IOM uint32_t CBC5                      : 1 ;     /*!< [4:4] : Trip-zone 5 (TZ5) Select                                        <br>  0: Disable TZ5 as a CBC trip source for this ePWM module 1: Enable TZ5 as a CBC trip source for this ePWM module Reset type: SYSRSn<br>. */
            __IOM uint32_t CBC6                      : 1 ;     /*!< [5:5] : Trip-zone 6 (TZ6) Select                                        <br>  0: Disable TZ6 as a CBC trip source for this ePWM module 1: Enable TZ6 as a CBC trip source for this ePWM module Reset type: SYSRSn<br>. */
            __IOM uint32_t DCAEVT2                   : 1 ;     /*!< [6:6] : Digital Compare Output A Event 2 Select                         <br>  0: Disable DCAEVT2 as a CBC trip source for this ePWM module 1: Enable DCAEVT2 as a CBC trip source for this ePWM module Reset type: SYSRSn<br>. */
            __IOM uint32_t DCBEVT2                   : 1 ;     /*!< [7:7] : Digital Compare Output B Event 2 Select                         <br>  0: Disable DCBEVT2 as a CBC trip source for this ePWM module 1: Enable DCBEVT2 as a CBC trip source for this ePWM module Reset type: SYSRSn<br>. */
            __IOM uint32_t OSHT1                     : 1 ;     /*!< [8:8] : Trip-zone 1 (TZ1) Select                                        <br>  0: Disable TZ1 as a one-shot trip source for this ePWM module 1: Enable TZ1 as a one-shot trip source for this ePWM module Reset type: SYSRSn<br>. */
            __IOM uint32_t OSHT2                     : 1 ;     /*!< [9:9] : Trip-zone 2 (TZ2) Select                                        <br>  0: Disable TZ2 as a one-shot trip source for this ePWM module 1: Enable TZ2 as a one-shot trip source for this ePWM module Reset type: SYSRSn<br>. */
            __IOM uint32_t OSHT3                     : 1 ;     /*!< [10:10] : Trip-zone 3 (TZ3) Select                                        <br>  0: Disable TZ3 as a one-shot trip source for this ePWM module 1: Enable TZ3 as a one-shot trip source for this ePWM module Reset type: SYSRSn<br>. */
            __IOM uint32_t OSHT4                     : 1 ;     /*!< [11:11] : Trip-zone 4 (TZ4) Select                                        <br>  0: Disable TZ4 as a one-shot trip source for this ePWM module 1: Enable TZ4 as a one-shot trip source for this ePWM module Reset type: SYSRSn<br>. */
            __IOM uint32_t OSHT5                     : 1 ;     /*!< [12:12] : Trip-zone 5 (TZ5) Select                                        <br>  0: Disable TZ5 as a one-shot trip source for this ePWM module 1: Enable TZ5 as a one-shot trip source for this ePWM module Reset type: SYSRSn<br>. */
            __IOM uint32_t OSHT6                     : 1 ;     /*!< [13:13] : Trip-zone 6 (TZ6) Select                                        <br>  0: Disable TZ6 as a one-shot trip source for this ePWM module 1: Enable TZ6 as a one-shot trip source for this ePWM module Reset type: SYSRSn<br>. */
            __IOM uint32_t DCAEVT1                   : 1 ;     /*!< [14:14] : Digital Compare Output A Event 1 Select                         <br>  0: Disable DCAEVT1 as one-shot-trip source for this ePWM module. */
            __IOM uint32_t DCBEVT1                   : 1 ;     /*!< [15:15] : Digital Compare Output B Event 1 Select                         <br>  0: Disable DCBEVT1 as one-shot-trip source for this ePWM module. */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } TZSELb;
    };

    union
    {
        __IOM uint32_t TZDCSEL;  /*!< 0x00000104 */ 
       
        struct
        {
            __IOM uint32_t DCAEVT1                   : 3 ;     /*!< [2:0] : Digital Compare Output A Event 1 Selection 000: Event disabled  <br>  001: DCAH = low, DCAL = don't care 010: DCAH = high, DCAL = don't care 011: DCAL = low, DCAH = don't care 100: DCAL = high, DCAH = don't care 101: DCAL = high, DCAH = low<br>  110: Reserved                                                   <br>  111: Reserved                                                   <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t DCAEVT2                   : 3 ;     /*!< [5:3] : Digital Compare Output A Event 2 Selection 000: Event disabled  <br>  001: DCAH = low, DCAL = don't care 010: DCAH = high, DCAL = don't care 011: DCAL = low, DCAH = don't care 100: DCAL = high, DCAH = don't care 101: DCAL = high, DCAH = low<br>  110: Reserved                                                   <br>  111: Reserved                                                   <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t DCBEVT1                   : 3 ;     /*!< [8:6] : Digital Compare Output B Event 1 Selection 000: Event disabled  <br>  001: DCBH = low, DCBL = don't care 010: DCBH = high, DCBL = don't care 011: DCBL = low, DCBH = don't care 100: DCBL = high, DCBH = don't care 101: DCBL = high, DCBH = low<br>  110: Reserved                                                   <br>  111: Reserved                                                   <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t DCBEVT2                   : 3 ;     /*!< [11:9] : Digital Compare Output B Event 2 Selection 000: Event disabled  <br>  001: DCBH = low, DCBL = don't care 010: DCBH = high, DCBL = don't care 011: DCBL = low, DCBH = don't care 100: DCBL = high, DCBH = don't care 101: DCBL = high, DCBH = low<br>  110: Reserved                                                   <br>  111: Reserved                                                   <br>  Reset type: SYSRSn                                              <br>. */
                  uint32_t RSV_0                     : 20;     /*!< [31:12] : reserved. */
        } TZDCSELb;
    };

    union
    {
        __IOM uint16_t TZCTL;  /*!< 0x00000108 */ 
       
        struct
        {
            __IOM uint16_t TZA                       : 2 ;     /*!< [1:0] : TZ1 to TZ6, DCAEVT1/2, DCBEVT1/2 Trip Action On EPWMxA When a trip event occurs the following action is taken on output EPWMxA. */
            __IOM uint16_t TZB                       : 2 ;     /*!< [3:2] : TZ1 to TZ6, DCAEVT1/2, DCBEVT1/2Trip Action On EPWMxB When a trip event occurs the following action is taken on output EPWMxB. */
            __IOM uint16_t DCAEVT1                   : 2 ;     /*!< [5:4] : Digital Compare Output A Event 1 Action On EPWMxA 00: High-impedance (EPWMxA = High-impedance state) 01: Force EPWMxA to a high state. */
            __IOM uint16_t DCAEVT2                   : 2 ;     /*!< [7:6] : Digital Compare Output A Event 2 Action On EPWMxA 00: High-impedance (EPWMxA = High-impedance state) 01: Force EPWMxA to a high state. */
            __IOM uint16_t DCBEVT1                   : 2 ;     /*!< [9:8] : Digital Compare Output B Event 1 Action On EPWMxB 00: High-impedance (EPWMxB = High-impedance state) 01: Force EPWMxB to a high state. */
            __IOM uint16_t DCBEVT2                   : 2 ;     /*!< [11:10] : Digital Compare Output B Event 2 Action On EPWMxB 00: High-impedance (EPWMxB = High-impedance state) 01: Force EPWMxB to a high state. */
                  uint16_t RSV_0                     : 4 ;     /*!< [15:12] : reserved. */
        } TZCTLb;
    };

    union
    {
        __IOM uint16_t TZCTL2;  /*!< 0x0000010a */ 
       
        struct
        {
            __IOM uint16_t TZAU                      : 3 ;     /*!< [2:0] : TZ1 to TZ6, DCAEVT1/2, DCBEVT1/2 Trip Action On EPWMxA while Count direction is UP<br>  000: HiZ (EPWMxA = HiZ state)                                   <br>  001: Forced Hi (EPWMxA = High state) 010: Forced Lo (EPWMxA = Lo state) 011: Toggle (Low -> High, High -> Low) 100: Reserved<br>  101: Reserved                                                   <br>  110: Reserved                                                   <br>  111: Do Nothing, trip action is disabled Reset type: SYSRSn     <br>. */
            __IOM uint16_t TZAD                      : 3 ;     /*!< [5:3] : TZ1 to TZ6, DCAEVT1/2, DCBEVT1/2 Trip Action On EPWMxA while Count direction is DOWN<br>  000: HiZ (EPWMxA = HiZ state)                                   <br>  001: Forced Hi (EPWMxA = High state) 010: Forced Lo (EPWMxA = Lo state) 011: Toggle (Low -> High, High -> Low) 100: Reserved<br>  101: Reserved                                                   <br>  110: Reserved                                                   <br>  111: Do Nothing, trip action is disabled Reset type: SYSRSn     <br>. */
            __IOM uint16_t TZBU                      : 3 ;     /*!< [8:6] : TZ1 to TZ6, DCAEVT1/2, DCBEVT1/2 Trip Action On EPWMxB while Count direction is UP<br>  000: HiZ (EPWMxB = HiZ state)                                   <br>  001: Forced Hi (EPWMxB = High state) 010: Forced Lo (EPWMxB = Lo state) 011: Toggle (Low -> High, High -> Low) 100: Reserved<br>  101: Reserved                                                   <br>  110: Reserved                                                   <br>  111: Do Nothing, trip action is disabled Reset type: SYSRSn     <br>. */
            __IOM uint16_t TZBD                      : 3 ;     /*!< [11:9] : TZ1 to TZ6 Trip Action On EPWMxB while Count direction is DOWN 000: HiZ (EPWMxB = HiZ state)<br>  001: Forced Hi (EPWMxB = High state) 010: Forced Lo (EPWMxB = Lo state) 011: Toggle (Low -> High, High -> Low) 100: Reserved<br>  101: Reserved                                                   <br>  110: Reserved                                                   <br>  111: Do Nothing, trip action is disabled Reset type: SYSRSn     <br>. */
                  uint16_t RSV_0                     : 3 ;     /*!< [14:12] : reserved. */
            __IOM uint16_t ETZE                      : 1 ;     /*!< [15:15] : TZCTL2 Enable                                                   <br>  0: Use trip action from TZCTL (legacy EPWM compatibility)       <br>  1: Use trip action defined in TZCTL2, TZCTLDCA and TZCTLDCB. */
        } TZCTL2b;
    };

    union
    {
        __IOM uint16_t TZCTLDCA;  /*!< 0x0000010c */ 
       
        struct
        {
            __IOM uint16_t DCAEVT1U                  : 3 ;     /*!< [2:0] : Digital Compare Output A Event 1 Action On EPWMxA while Count direction is UP<br>  000: HiZ (EPWMxA = HiZ state)                                   <br>  001: Forced Hi (EPWMxA = High state) 010: Forced Lo (EPWMxA = Lo state) 011: Toggle (Low -> High, High -> Low) 100: Reserved<br>  101: Reserved                                                   <br>  110: Reserved                                                   <br>  111: Do Nothing, trip action is disabled Reset type: SYSRSn     <br>. */
            __IOM uint16_t DCAEVT1D                  : 3 ;     /*!< [5:3] : Digital Compare Output A Event 1 Action On EPWMxA while Count direction is DOWN<br>  000: HiZ (EPWMxA = HiZ state)                                   <br>  001: Forced Hi (EPWMxA = High state) 010: Forced Lo (EPWMxA = Lo state) 011: Toggle (Low -> High, High -> Low) 100: Reserved<br>  101: Reserved                                                   <br>  110: Reserved                                                   <br>  111: Do Nothing, trip action is disabled Reset type: SYSRSn     <br>. */
            __IOM uint16_t DCAEVT2U                  : 3 ;     /*!< [8:6] : Digital Compare Output A Event 2 Action On EPWMxA while Count direction is UP<br>  000: HiZ (EPWMxA = HiZ state)                                   <br>  001: Forced Hi (EPWMxA = High state) 010: Forced Lo (EPWMxA = Lo state) 011: Toggle (Low -> High, High -> Low) 100: Reserved<br>  101: Reserved                                                   <br>  110: Reserved                                                   <br>  111: Do Nothing, trip action is disabled Reset type: SYSRSn     <br>. */
            __IOM uint16_t DCAEVT2D                  : 3 ;     /*!< [11:9] : Digital Compare Output A Event 2 Action On EPWMxA while Count direction is DOWN<br>  000: HiZ (EPWMxA = HiZ state)                                   <br>  001: Forced Hi (EPWMxA = High state) 010: Forced Lo (EPWMxA = Lo state) 011: Toggle (Low -> High, High -> Low) 100: Reserved<br>  101: Reserved                                                   <br>  110: Reserved                                                   <br>  111: Do Nothing, trip action is disabled Reset type: SYSRSn     <br>. */
                  uint16_t RSV_0                     : 4 ;     /*!< [15:12] : reserved. */
        } TZCTLDCAb;
    };

    union
    {
        __IOM uint16_t TZCTLDCB;  /*!< 0x0000010e */ 
       
        struct
        {
            __IOM uint16_t DCBEVT1U                  : 3 ;     /*!< [2:0] : Digital Compare Output B Event 1 Action On EPWMxB while Count direction is UP<br>  000: HiZ (EPWMxB = HiZ state)                                   <br>  001: Forced Hi (EPWMxB = High state) 010: Forced Lo (EPWMxB = Lo state) 011: Toggle (Low -> High, High -> Low) 100: Reserved<br>  101: Reserved                                                   <br>  110: Reserved                                                   <br>  111: Do Nothing, trip action is disabled Reset type: SYSRSn     <br>. */
            __IOM uint16_t DCBEVT1D                  : 3 ;     /*!< [5:3] : Digital Compare Output B Event 1 Action On EPWMxB while Count direction is DOWN<br>  000: HiZ (EPWMxB = HiZ state)                                   <br>  001: Forced Hi (EPWMxB = High state) 010: Forced Lo (EPWMxB = Lo state) 011: Toggle (Low -> High, High -> Low) 100: Reserved<br>  101: Reserved                                                   <br>  110: Reserved                                                   <br>  111: Do Nothing, trip action is disabled Reset type: SYSRSn     <br>. */
            __IOM uint16_t DCBEVT2U                  : 3 ;     /*!< [8:6] : Digital Compare Output B Event 2 Action On EPWMxB while Count direction is UP<br>  000: HiZ (EPWMxB = HiZ state)                                   <br>  001: Forced Hi (EPWMxB = High state) 010: Forced Lo (EPWMxB = Lo state) 011: Toggle (Low -> High, High -> Low) 100: Reserved<br>  101: Reserved                                                   <br>  110: Reserved                                                   <br>  111: Do Nothing, trip action is disabled Reset type: SYSRSn     <br>. */
            __IOM uint16_t DCBEVT2D                  : 3 ;     /*!< [11:9] : Digital Compare Output B Event 2 Action On EPWMxB while Count direction is DOWN<br>  000: HiZ (EPWMxB = HiZ state)                                   <br>  001: Forced Hi (EPWMxB = High state) 010: Forced Lo (EPWMxB = Lo state) 011: Toggle (Low -> High, High -> Low) 100: Reserved<br>  101: Reserved                                                   <br>  110: Reserved                                                   <br>  111: Do Nothing, trip action is disabled Reset type: SYSRSn     <br>. */
                  uint16_t RSV_0                     : 4 ;     /*!< [15:12] : reserved. */
        } TZCTLDCBb;
    };

    uint8_t    RSV_0X110[10];   /*!< 0x00000110~0x00000119 : reserved */

    union
    {
        __IOM uint16_t TZEINT;  /*!< 0x0000011a */ 
       
        struct
        {
                  uint16_t RSV_1                     : 1 ;     /*!< [0:0] : reserved. */
            __IOM uint16_t CBC                       : 1 ;     /*!< [1:1] : Trip-zone Cycle-by-Cycle Interrupt Enable                       <br>  0: Disable cycle-by-cycle interrupt generation. */
            __IOM uint16_t OST                       : 1 ;     /*!< [2:2] : Trip-zone One-Shot Interrupt Enable                             <br>  0: Disable one-shot interrupt generation 1: Enable Interrupt generation<br>  a one-shot trip event will cause a EPWMx_TZINT PIE interrupt. */
            __IOM uint16_t DCAEVT1                   : 1 ;     /*!< [3:3] : Digital Compare Output A Event 1 Interrupt Enable 0: Disabled   <br>  1: Enabled                                                      <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint16_t DCAEVT2                   : 1 ;     /*!< [4:4] : Digital Compare Output A Event 2 Interrupt Enable 0: Disabled   <br>  1: Enabled                                                      <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint16_t DCBEVT1                   : 1 ;     /*!< [5:5] : Digital Compare Output B Event 1 Interrupt Enable 0: Disabled   <br>  1: Enabled                                                      <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint16_t DCBEVT2                   : 1 ;     /*!< [6:6] : Digital Compare Output B Event 2 Interrupt Enable 0: Disabled   <br>  1: Enabled                                                      <br>  Reset type: SYSRSn                                              <br>. */
                  uint16_t RSV_0                     : 9 ;     /*!< [15:7] : reserved. */
        } TZEINTb;
    };

    uint8_t    RSV_0X11C[10];   /*!< 0x0000011c~0x00000125 : reserved */

    union
    {
        __IM uint16_t TZFLG;  /*!< 0x00000126 */ 
       
        struct
        {
            __IM  uint16_t TZINT                     : 1 ;     /*!< [0:0] : Latched Trip Interrupt Status Flag                              <br>  0: Indicates no interrupt has been generated. */
            __IM  uint16_t CBC                       : 1 ;     /*!< [1:1] : Latched Status Flag for Cycle-By-Cycle Trip Event 0: No cycle-by-cycle trip event has occurred. */
            __IM  uint16_t OST                       : 1 ;     /*!< [2:2] : Latched Status Flag for A One-Shot Trip Event 0: No one-shot trip event has occurred. */
            __IM  uint16_t DCAEVT1                   : 1 ;     /*!< [3:3] : Latched Status Flag for Digital Compare Output A Event 1 0: Indicates no trip event has occurred on DCAEVT1<br>  1: Indicates a trip event has occurred for the event defined for DCAEVT1<br>  Reset type: SYSRSn                                              <br>. */
            __IM  uint16_t DCAEVT2                   : 1 ;     /*!< [4:4] : Latched Status Flag for Digital Compare Output A Event 2 0: Indicates no trip event has occurred on DCAEVT2<br>  1: Indicates a trip event has occurred for the event defined for DCAEVT2<br>  Reset type: SYSRSn                                              <br>. */
            __IM  uint16_t DCBEVT1                   : 1 ;     /*!< [5:5] : Latched Status Flag for Digital Compare Output B Event 1 0: Indicates no trip event has occurred on DCBEVT1<br>  1: Indicates a trip event has occurred for the event defined for DCBEVT1<br>  Reset type: SYSRSn                                              <br>. */
            __IM  uint16_t DCBEVT2                   : 1 ;     /*!< [6:6] : Latched Status Flag for Digital Compare Output B Event 2 0: Indicates no trip event has occurred on DCBEVT2<br>  1: Indicates a trip event has occurred for the event defined for DCBEVT2<br>  Reset type: SYSRSn                                              <br>. */
                  uint16_t RSV_0                     : 9 ;     /*!< [15:7] : reserved. */
        } TZFLGb;
    };

    union
    {
        __IM uint16_t TZCBCFLG;  /*!< 0x00000128 */ 
       
        struct
        {
            __IM  uint16_t CBC1                      : 1 ;     /*!< [0:0] : Latched Status Flag for CBC1 Trip Latch                         <br>  0: Reading a 0 indicates that no trip has occurred on CBC1. */
            __IM  uint16_t CBC2                      : 1 ;     /*!< [1:1] : Latched Status Flag for CBC2 Trip Latch                         <br>  0: Reading a 0 indicates that no trip has occurred on CBC2. */
            __IM  uint16_t CBC3                      : 1 ;     /*!< [2:2] : Latched Status Flag for CBC3 Trip Latch                         <br>  0: Reading a 0 indicates that no trip has occurred on CBC3. */
            __IM  uint16_t CBC4                      : 1 ;     /*!< [3:3] : Latched Status Flag for CBC4 Trip Latch                         <br>  0: Reading a 0 indicates that no trip has occurred on CBC4. */
            __IM  uint16_t CBC5                      : 1 ;     /*!< [4:4] : Latched Status Flag for CBC5 Trip Latch                         <br>  0: Reading a 0 indicates that no trip has occurred on CBC5. */
            __IM  uint16_t CBC6                      : 1 ;     /*!< [5:5] : Latched Status Flag for CBC6 Trip Latch                         <br>  0: Reading a 0 indicates that no trip has occurred on CBC6. */
            __IM  uint16_t DCAEVT2                   : 1 ;     /*!< [6:6] : Latched Status Flag for Digital Compare A Output Event 2 Trip Latch 0: Reading a 0 indicates that no trip has occurred on DCAEVT2. */
            __IM  uint16_t DCBEVT2                   : 1 ;     /*!< [7:7] : Latched Status Flag for Digital Compare B Output Event 2 Trip Latch 0: Reading a 0 indicates that no trip has occurred on DCBEVT2. */
                  uint16_t RSV_0                     : 8 ;     /*!< [15:8] : reserved. */
        } TZCBCFLGb;
    };

    union
    {
        __IM uint16_t TZOSTFLG;  /*!< 0x0000012a */ 
       
        struct
        {
            __IM  uint16_t OST1                      : 1 ;     /*!< [0:0] : Latched Status Flag for OST1 Trip Latch                         <br>  0: Reading a 0 indicates that no trip has occurred on OST1. */
            __IM  uint16_t OST2                      : 1 ;     /*!< [1:1] : Latched Status Flag for OST2 Trip Latch                         <br>  0: Reading a 0 indicates that no trip has occurred on OST2. */
            __IM  uint16_t OST3                      : 1 ;     /*!< [2:2] : Latched Status Flag for OST3 Trip Latch                         <br>  0: Reading a 0 indicates that no trip has occurred on OST3. */
            __IM  uint16_t OST4                      : 1 ;     /*!< [3:3] : Latched Status Flag for OST4 Trip Latch                         <br>  0: Reading a 0 indicates that no trip has occurred on OST4. */
            __IM  uint16_t OST5                      : 1 ;     /*!< [4:4] : Latched Status Flag for OST5 Trip Latch                         <br>  0: Reading a 0 indicates that no trip has occurred on OST5. */
            __IM  uint16_t OST6                      : 1 ;     /*!< [5:5] : Latched Status Flag for OST6 Trip Latch                         <br>  0: Reading a 0 indicates that no trip has occurred on OST6. */
            __IM  uint16_t DCAEVT1                   : 1 ;     /*!< [6:6] : Latched Status Flag for Digital Compare A Output Event 1 Trip Latch 0: Reading a 0 indicates that no trip has occurred on DCAEVT1. */
            __IM  uint16_t DCBEVT1                   : 1 ;     /*!< [7:7] : Latched Status Flag for Digital Compare B Output Event 1 Trip Latch 0: Reading a 0 indicates that no trip has occurred on DCBEVT1. */
                  uint16_t RSV_0                     : 8 ;     /*!< [15:8] : reserved. */
        } TZOSTFLGb;
    };

    uint8_t    RSV_0X12C[2];   /*!< 0x0000012c~0x0000012d : reserved */

    union
    {
        __IOM uint16_t TZCLR;  /*!< 0x0000012e */ 
       
        struct
        {
            __IOM uint16_t TZINT                     : 1 ;     /*!< [0:0] : Global Interrupt Clear Flag                                     <br>  0: Has no effect. */
            __IOM uint16_t CBC                       : 1 ;     /*!< [1:1] : Clear Flag for Cycle-By-Cycle (CBC) Trip Latch 0: Has no effect. */
            __IOM uint16_t OST                       : 1 ;     /*!< [2:2] : Clear Flag for One-Shot Trip (OST) Latch 0: Has no effect. */
            __IOM uint16_t DCAEVT1                   : 1 ;     /*!< [3:3] : Clear Flag for Digital Compare Output A Event 1                 <br>  0: Writing 0 has no effect. */
            __IOM uint16_t DCAEVT2                   : 1 ;     /*!< [4:4] : Clear Flag for Digital Compare Output A Event 2                 <br>  0: Writing 0 has no effect. */
            __IOM uint16_t DCBEVT1                   : 1 ;     /*!< [5:5] : Clear Flag for Digital Compare Output B Event 1                 <br>  0: Writing 0 has no effect. */
            __IOM uint16_t DCBEVT2                   : 1 ;     /*!< [6:6] : Clear Flag for Digital Compare Output B Event 2                 <br>  0: Writing 0 has no effect. */
                  uint16_t RSV_0                     : 7 ;     /*!< [13:7] : reserved. */
            __IOM uint16_t CBCPULSE                  : 2 ;     /*!< [15:14] : Clear Pulse for Cycle-By-Cycle (CBC) Trip Latch                 <br>  This bit field determines which pulse clears the CBC trip latch. */
        } TZCLRb;
    };

    union
    {
        __IOM uint16_t TZCBCCLR;  /*!< 0x00000130 */ 
       
        struct
        {
            __IOM uint16_t CBC1                      : 1 ;     /*!< [0:0] : Clear Flag for Cycle-By-Cycle (CBC1) Trip Latch 0: Writing a 0 has no effect. */
            __IOM uint16_t CBC2                      : 1 ;     /*!< [1:1] : Clear Flag for Cycle-By-Cycle (CBC2) Trip Latch 0: Writing a 0 has no effect. */
            __IOM uint16_t CBC3                      : 1 ;     /*!< [2:2] : Clear Flag for Cycle-By-Cycle (CBC3) Trip Latch 0: Writing a 0 has no effect. */
            __IOM uint16_t CBC4                      : 1 ;     /*!< [3:3] : Clear Flag for Cycle-By-Cycle (CBC4) Trip Latch 0: Writing a 0 has no effect. */
            __IOM uint16_t CBC5                      : 1 ;     /*!< [4:4] : Clear Flag for Cycle-By-Cycle (CBC5) Trip Latch 0: Writing a 0 has no effect. */
            __IOM uint16_t CBC6                      : 1 ;     /*!< [5:5] : Clear Flag for Cycle-By-Cycle (CBC6) Trip Latch 0: Writing a 0 has no effect. */
            __IOM uint16_t DCAEVT2                   : 1 ;     /*!< [6:6] : Clear Flag for Digital Compare Output A Event 2 selected for CBC 0: Writing a 0 has no effect. */
            __IOM uint16_t DCBEVT2                   : 1 ;     /*!< [7:7] : Clear Flag for Digital Compare Output B Event 2 selected for CBC 0: Writing a 0 has no effect. */
                  uint16_t RSV_0                     : 8 ;     /*!< [15:8] : reserved. */
        } TZCBCCLRb;
    };

    union
    {
        __IOM uint16_t TZOSTCLR;  /*!< 0x00000132 */ 
       
        struct
        {
            __IOM uint16_t OST1                      : 1 ;     /*!< [0:0] : Clear Flag for Oneshot (OST1) Trip Latch 0: Writing a 0 has no effect. */
            __IOM uint16_t OST2                      : 1 ;     /*!< [1:1] : Clear Flag for Oneshot (OST2) Trip Latch 0: Writing a 0 has no effect. */
            __IOM uint16_t OST3                      : 1 ;     /*!< [2:2] : Clear Flag for Oneshot (OST3) Trip Latch 0: Writing a 0 has no effect. */
            __IOM uint16_t OST4                      : 1 ;     /*!< [3:3] : Clear Flag for Oneshot (OST4) Trip Latch 0: Writing a 0 has no effect. */
            __IOM uint16_t OST5                      : 1 ;     /*!< [4:4] : Clear Flag for Oneshot (OST5) Trip Latch 0: Writing a 0 has no effect. */
            __IOM uint16_t OST6                      : 1 ;     /*!< [5:5] : Clear Flag for Oneshot (OST6) Trip Latch 0: Writing a 0 has no effect. */
            __IOM uint16_t DCAEVT1                   : 1 ;     /*!< [6:6] : Clear Flag for Digital Compare Output A Event 1 selected for OST 0: Writing a 0 has no effect. */
            __IOM uint16_t DCBEVT1                   : 1 ;     /*!< [7:7] : Clear Flag for Digital Compare Output B Event 1 selected for OST 0: Writing a 0 has no effect. */
                  uint16_t RSV_0                     : 8 ;     /*!< [15:8] : reserved. */
        } TZOSTCLRb;
    };

    uint8_t    RSV_0X134[2];   /*!< 0x00000134~0x00000135 : reserved */

    union
    {
        __IOM uint16_t TZFRC;  /*!< 0x00000136 */ 
       
        struct
        {
                  uint16_t RSV_1                     : 1 ;     /*!< [0:0] : reserved. */
            __IOM uint16_t CBC                       : 1 ;     /*!< [1:1] : Force a Cycle-by-Cycle Trip Event via Software 0: Writing of 0 is ignored. */
            __IOM uint16_t OST                       : 1 ;     /*!< [2:2] : Force a One-Shot Trip Event via Software                        <br>  0: Writing of 0 is ignored. */
            __IOM uint16_t DCAEVT1                   : 1 ;     /*!< [3:3] : Force Flag for Digital Compare Output A Event 1                 <br>  0: Writing 0 has no effect. */
            __IOM uint16_t DCAEVT2                   : 1 ;     /*!< [4:4] : Force Flag for Digital Compare Output A Event 2                 <br>  0: Writing 0 has no effect. */
            __IOM uint16_t DCBEVT1                   : 1 ;     /*!< [5:5] : Force Flag for Digital Compare Output B Event 1                 <br>  0: Writing 0 has no effect. */
            __IOM uint16_t DCBEVT2                   : 1 ;     /*!< [6:6] : Force Flag for Digital Compare Output B Event 2                 <br>  0: Writing 0 has no effect. */
                  uint16_t RSV_0                     : 9 ;     /*!< [15:7] : reserved. */
        } TZFRCb;
    };

    uint8_t    RSV_0X138[16];   /*!< 0x00000138~0x00000147 : reserved */

    union
    {
        __IOM uint32_t ETSEL;  /*!< 0x00000148 */ 
       
        struct
        {
            __IOM uint32_t INTSEL                    : 3 ;     /*!< [2:0] : ePWM Interrupt (EPWMx_INT) Selection Options 000: Reserved      <br>  001: Enable event time-base counter equal to zero. */
            __IOM uint32_t INTEN                     : 1 ;     /*!< [3:3] : Enable ePWM Interrupt (EPWMx_INT) Generation 0: Disable EPWMx_INT generation<br>  1: Enable EPWMx_INT generation Reset type: SYSRSn               <br>. */
            __IOM uint32_t SOCASELCMP                : 1 ;     /*!< [4:4] : EPWMxSOCA Compare Register Selection Options                    <br>  0: Enable event time-base counter equal to CMPA when the timer is incrementing / Enable event time-base counter equal to CMPA when the timer is decrementing / Enable event: time-base counter equal to CMPB when the timer is incrementing / Enable event: time-base counter equal to CMPB when the timer is decrementing to SOCASEL selection mux. */
            __IOM uint32_t SOCBSELCMP                : 1 ;     /*!< [5:5] : EPWMxSOCB Compare Register Selection Options                    <br>  0: Enable event time-base counter equal to CMPA when the timer is incrementing / Enable event time-base counter equal to CMPA when the timer is decrementing / Enable event: time-base counter equal to CMPB when the timer is incrementing / Enable event: time-base counter equal to CMPB when the timer is decrementing to SOCBSEL selection mux. */
            __IOM uint32_t INTSELCMP                 : 1 ;     /*!< [6:6] : EPWMxINT Compare Register Selection Options                     <br>  0: Enable event time-base counter equal to CMPA when the timer is incrementing / Enable event time-base counter equal to CMPA when the timer is decrementing / Enable event: time-base counter equal to CMPB when the timer is incrementing / Enable event: time-base counter equal to CMPB when the timer is decrementing to INTSEL selection mux. */
                  uint32_t RSV_1                     : 1 ;     /*!< [7:7] : reserved. */
            __IOM uint32_t SOCASEL                   : 3 ;     /*!< [10:8] : Enable the ADC Start of Conversion B (EPWMxSOCB) Pulse 0: Disable EPWMxSOCB. */
            __IOM uint32_t SOCAEN                    : 1 ;     /*!< [11:11] : EPWMxSOCA. */
            __IOM uint32_t SOCBSEL                   : 3 ;     /*!< [14:12] : EPWMxSOCB Selection Options                                     <br>  These bits determine when a EPWMxSOCB pulse will be generated. */
            __IOM uint32_t SOCBEN                    : 1 ;     /*!< [15:15] : Enable the ADC Start of Conversion B (EPWMxSOCB) Pulse 0: Disable EPWMxSOCB. */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } ETSELb;
    };

    union
    {
        __IOM uint32_t ETPS;  /*!< 0x0000014c */ 
       
        struct
        {
            __IOM uint32_t INTPRD                    : 2 ;     /*!< [1:0] : ePWM Interrupt (EPWMx_INT) Period Select                        <br>  These bits determine how many selected ETSEL[INTSEL] events need to occur before an interrupt is generated. */
            __IM  uint32_t INTCNT                    : 2 ;     /*!< [3:2] : ePWM Interrupt Event (EPWMx_INT) Counter Register               <br>  These bits indicate how many selected ETSEL[INTSEL] events have occurred. */
            __IOM uint32_t INTPSSEL                  : 1 ;     /*!< [4:4] : EPWMxINTn Pre-Scale Selection Bits                              <br>  0: Selects ETPS [INTCNT, and INTPRD] registers to determine frequency of events (interrupt once every 0-3 events). */
            __IOM uint32_t SOCPSSEL                  : 1 ;     /*!< [5:5] : EPWMxSOC A/B Pre-Scale Selection Bits                           <br>  0: Selects ETPS [SOCACNT/SOCBCNT] and [SOCAPRD/                 <br>  SOCBPRD] registers to determine frequency of events (interrupt once every 0-3 events). */
                  uint32_t RSV_1                     : 2 ;     /*!< [7:6] : reserved. */
            __IOM uint32_t SOCAPRD                   : 2 ;     /*!< [9:8] : ePWM ADC Start-of-Conversion A Event (EPWMxSOCA) Period Select  <br>  These bits determine how many selected ETSEL[SOCASEL] events need to occur before an EPWMxSOCA pulse is generated. */
            __IM  uint32_t SOCACNT                   : 2 ;     /*!< [11:10] : ePWM ADC Start-of-Conversion A Event (EPWMxSOCA) Counter Register<br>  These bits indicate how many selected ETSEL[SOCASEL] events have occurred:<br>  00: No events have occurred. */
            __IOM uint32_t SOCBPRD                   : 2 ;     /*!< [13:12] : ePWM ADC Start-of-Conversion B Event (EPWMxSOCB) Period Select  <br>  These bits determine how many selected ETSEL[SOCBSEL] events need to occur before an EPWMxSOCB pulse is generated. */
            __IM  uint32_t SOCBCNT                   : 2 ;     /*!< [15:14] : ePWM ADC Start-of-Conversion B Event (EPWMxSOCB) Counter Register<br>  These bits indicate how many selected ETSEL[SOCBSEL] events have occurred:<br>  00: No events have occurred. */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } ETPSb;
    };

    union
    {
        __IM uint32_t ETFLG;  /*!< 0x00000150 */ 
       
        struct
        {
            __IM  uint32_t ETINT                     : 1 ;     /*!< [0:0] : Latched ePWM Interrupt (EPWMx_INT) Status Flag 0: Indicates no event occurred<br>  1: Indicates that an ePWMx interrupt (EPWMx_INT) was generated. */
                  uint32_t RSV_1                     : 1 ;     /*!< [1:1] : reserved. */
            __IM  uint32_t SOCA                      : 1 ;     /*!< [2:2] : Latched ePWM ADC Start-of-Conversion A (EPWMxSOCA) Status Flag  <br>  Unlike the ETFLG[INT] flag, the EPWMxSOCA output will continue to pulse even if the flag bit is set. */
            __IM  uint32_t SOCB                      : 1 ;     /*!< [3:3] : Latched ePWM ADC Start-of-Conversion A (EPWMxSOCB) Status Flag  <br>  Unlike the ETFLG[INT] flag, the EPWMxSOCB output will continue to pulse even if the flag bit is set. */
                  uint32_t RSV_0                     : 28;     /*!< [31:4] : reserved. */
        } ETFLGb;
    };

    union
    {
        __IOM uint32_t ETCLR;  /*!< 0x00000154 */ 
       
        struct
        {
            __IOM uint32_t ETINT                     : 1 ;     /*!< [0:0] : ePWM Interrupt (EPWMx_INT) Flag Clear Bit                       <br>  0: Writing a 0 has no effect. */
                  uint32_t RSV_1                     : 1 ;     /*!< [1:1] : reserved. */
            __IOM uint32_t SOCA                      : 1 ;     /*!< [2:2] : ePWM ADC Start-of-Conversion A (EPWMxSOCA) Flag Clear Bit 0: Writing a 0 has no effect. */
            __IOM uint32_t SOCB                      : 1 ;     /*!< [3:3] : ePWM ADC Start-of-Conversion A (EPWMxSOCB) Flag Clear Bit 0: Writing a 0 has no effect. */
                  uint32_t RSV_0                     : 28;     /*!< [31:4] : reserved. */
        } ETCLRb;
    };

    union
    {
        __IOM uint32_t ETFRC;  /*!< 0x00000158 */ 
       
        struct
        {
            __IOM uint32_t ETINT                     : 1 ;     /*!< [0:0] : INT Force Bit                                                   <br>  The interrupt will only be generated if the event is enabled in the ETSEL register. */
                  uint32_t RSV_1                     : 1 ;     /*!< [1:1] : reserved. */
            __IOM uint32_t SOCA                      : 1 ;     /*!< [2:2] : SOCA Force Bit                                                  <br>  The SOCA pulse will only be generated if the event is enabled in the ETSEL register. */
            __IOM uint32_t SOCB                      : 1 ;     /*!< [3:3] : SOCB Force Bit                                                  <br>  The SOCB pulse will only be generated if the event is enabled in the ETSEL register. */
                  uint32_t RSV_0                     : 28;     /*!< [31:4] : reserved. */
        } ETFRCb;
    };

    union
    {
        __IOM uint32_t ETINTPS;  /*!< 0x0000015c */ 
       
        struct
        {
            __IOM uint32_t INTPRD2                   : 4 ;     /*!< [3:0] : EPWMxINT Period 2 Select                                        <br>  When ETPS[INTPSSEL] = 1, these bits select how many selected events need to occur before an interrupt is generated:<br>  0000: Disable counter                                           <br>  0001: Generate interrupt on INTCNT = 1 (first event) 0010: Generate interrupt on INTCNT = 2 (second event) 0011: Generate interrupt on INTCNT = 3 (third event) 0100: Generate interrupt on INTCNT = 4 (fourth event)<br>  . */
            __IM  uint32_t INTCNT2                   : 4 ;     /*!< [7:4] : EPWMxINT Counter 2                                              <br>  When ETPS[INTPSSEL]=1, these bits indicate how many selected events have occurred:<br>  0000: No events                                                 <br>  0001: 1 event                                                   <br>  0010: 2 events                                                  <br>  0011: 3 events                                                  <br>  0100: 4 events                                                  <br>  . */
                  uint32_t RSV_0                     : 24;     /*!< [31:8] : reserved. */
        } ETINTPSb;
    };

    union
    {
        __IOM uint32_t ETSOCPS;  /*!< 0x00000160 */ 
       
        struct
        {
            __IOM uint32_t SOCAPRD2                  : 4 ;     /*!< [3:0] : EPWMxSOCA Period 2 Select                                       <br>  When ETPS[SOCPSSEL] = 1, these bits select how many selected event need to occur before an SOCA pulse is generated:<br>  0000: Disable counter                                           <br>  0001: Generate interrupt on SOCACNT2 = 1 (first event) 0010: Generate interrupt on SOCACNT2 = 2 (second event) 0011: Generate interrupt on SOCACNT2 = 3 (third event) 0100: Generate interrupt on SOCACNT2 = 4 (fourth event)<br>  . */
            __IM  uint32_t SOCACNT2                  : 4 ;     /*!< [7:4] : EPWMxSOCA Counter 2                                             <br>  When ETPS[SOCPSSEL] = 1, these bits indicate how many selected events have occurred:<br>  0000: No events                                                 <br>  0001: 1 event                                                   <br>  0010: 2 events                                                  <br>  0011: 3 events                                                  <br>  0100: 4 events                                                  <br>  . */
            __IOM uint32_t SOCBPRD2                  : 4 ;     /*!< [11:8] : EPWMxSOCB Period 2 Select                                       <br>  When ETPS[SOCPSSEL] = 1, these bits select how many selected event need to occur before an SOCB pulse is generated:<br>  0000: Disable counter                                           <br>  0001: Generate interrupt on SOCBCNT2 = 1 (first event) 0010: Generate interrupt on SOCBCNT2 = 2 (second event) 0011: Generate interrupt on SOCBCNT2 = 3 (third event) 0100: Generate interrupt on SOCBCNT2 = 4 (fourth event)<br>  . */
            __IM  uint32_t SOCBCNT2                  : 4 ;     /*!< [15:12] : EPWMxSOCB Counter 2                                             <br>  When ETPS[SOCPSSEL] = 1, these bits indicate how many selected events have occurred:<br>  0000: No events                                                 <br>  0001: 1 event                                                   <br>  0010: 2 events                                                  <br>  0011: 3 events                                                  <br>  0100: 4 events                                                  <br>  . */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } ETSOCPSb;
    };

    union
    {
        __IOM uint32_t ETCNTINITCTL;  /*!< 0x00000164 */ 
       
        struct
        {
                  uint32_t RSV_1                     : 10;     /*!< [9:0] : reserved. */
            __IOM uint32_t INTINITFRC                : 1 ;     /*!< [10:10] : EPWMxINT Counter 2 Initialization Force 0: Has no effect. */
            __IOM uint32_t SOCAINITFRC               : 1 ;     /*!< [11:11] : EPWMxSOCA Counter 2 Initialization Force 0: Has no effect. */
            __IOM uint32_t SOCBINITFRC               : 1 ;     /*!< [12:12] : EPWMxSOCB Counter 2 Initialization Force 0: Has no effect. */
            __IOM uint32_t INTINITEN                 : 1 ;     /*!< [13:13] : EPWMxINT Counter 2 Initialization Enable 0: Has no effect. */
            __IOM uint32_t SOCAINITEN                : 1 ;     /*!< [14:14] : EPWMxSOCA Counter 2 Initialization Enable 0: Has no effect. */
            __IOM uint32_t SOCBINITEN                : 1 ;     /*!< [15:15] : EPWMxSOCB Counter 2 Initialization Enable 0: Has no effect. */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } ETCNTINITCTLb;
    };

    union
    {
        __IOM uint32_t ETCNTINIT;  /*!< 0x00000168 */ 
       
        struct
        {
            __IOM uint32_t INTINIT                   : 4 ;     /*!< [3:0] : EPWMxINT Counter 2 Initialization Bits                          <br>  The ET EPWMxINT counter is initialized with the contents of this register on an ePWM SYNC event or a software force. */
            __IOM uint32_t SOCAINIT                  : 4 ;     /*!< [7:4] : EPWMxSOCA Counter 2 Initialization Bits                         <br>  The ET EPWMxSOCA counter is initialized with the contents of this register on an ePWM SYNC event or a software force. */
            __IOM uint32_t SOCBINIT                  : 4 ;     /*!< [11:8] : EPWMxSOCB Counter 2 Initialization Bits                         <br>  The ET EPWMxSOCB counter is initialized with the contents of this register on an ePWM SYNC event or a software force. */
                  uint32_t RSV_0                     : 20;     /*!< [31:12] : reserved. */
        } ETCNTINITb;
    };

    uint8_t    RSV_0X16C[20];   /*!< 0x0000016c~0x0000017f : reserved */

    union
    {
        __IOM uint32_t DCTRIPSEL;  /*!< 0x00000180 */ 
       
        struct
        {
            __IOM uint32_t DCAHCOMPSEL               : 4 ;     /*!< [3:0] : Digital Compare A High Input Select Bits 0000: TRIPIN1          <br>  0001: TRIPIN2                                                   <br>  0010: TRIPIN3                                                   <br>  0011: TRIPIN4                                                   <br>  . */
            __IOM uint32_t DCALCOMPSEL               : 4 ;     /*!< [7:4] : Digital Compare A Low Input Select Bits 0000: TRIPIN1           <br>  0001: TRIPIN2                                                   <br>  0010: TRIPIN3                                                   <br>  0011: TRIPIN4                                                   <br>  . */
            __IOM uint32_t DCBHCOMPSEL               : 4 ;     /*!< [11:8] : Digital Compare B High Input Select Bits 0000: TRIPIN1          <br>  0001: TRIPIN2                                                   <br>  0010: TRIPIN3                                                   <br>  0011: TRIPIN4                                                   <br>  . */
            __IOM uint32_t DCBLCOMPSEL               : 4 ;     /*!< [15:12] : Digital Compare B Low Input Select Bits 0000: TRIPIN1           <br>  0001: TRIPIN2                                                   <br>  0010: TRIPIN3                                                   <br>  0011: TRIPIN4                                                   <br>  . */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } DCTRIPSELb;
    };

    uint8_t    RSV_0X184[2];   /*!< 0x00000184~0x00000185 : reserved */

    union
    {
        __IOM uint16_t DCACTL;  /*!< 0x00000186 */ 
       
        struct
        {
            __IOM uint16_t EVT1SRCSEL                : 1 ;     /*!< [0:0] : DCAEVT1 Source Signal Select 0: Source Is DCAEVT1 Signal 1: Source Is DCEVTFILT Signal Reset type: SYSRSn. */
            __IOM uint16_t EVT1FRCSYNCSEL            : 1 ;     /*!< [1:1] : DCAEVT1 Force Synchronization Signal Select 0: Source is synchronized with EPWMCLK<br>  1: Source is passed through asynchronously Reset type: SYSRSn   <br>. */
            __IOM uint16_t EVT1SOCE                  : 1 ;     /*!< [2:2] : DCAEVT1 SOC, Enable/Disable 0: SOC Generation Disabled          <br>  1: SOC Generation Enabled Reset type: SYSRSn                    <br>. */
            __IOM uint16_t EVT1SYNCE                 : 1 ;     /*!< [3:3] : DCAEVT1 SYNC, Enable/Disable 0: SYNC Generation Disabled        <br>  1: SYNC Generation Enabled Reset type: SYSRSn                   <br>. */
            __IOM uint16_t EVT1LATSEL                : 1 ;     /*!< [4:4] : DCAEVT1 Latched signal select:                                  <br>  0 Does not select the DCAEVT1 latched signal (Refer figure "Modifications to DCAEVT1. */
            __IOM uint16_t EVT1LATCLRSEL             : 2 ;     /*!< [6:5] : DCAEVT1 Latched clear source select:                            <br>  00 CNT_ZERO event clears DCAEVT1 latch. */
            __IM  uint16_t EVT1LAT                   : 1 ;     /*!< [7:7] : Indicates the status of DCAEVT1LAT signal. */
            __IOM uint16_t EVT2SRCSEL                : 1 ;     /*!< [8:8] : DCAEVT2 Source Signal Select 0: Source Is DCAEVT2 Signal 1: Source Is DCEVTFILT Signal Reset type: SYSRSn. */
            __IOM uint16_t EVT2FRCSYNCSEL            : 1 ;     /*!< [9:9] : DCAEVT2 Force Synchronization Signal Select 0: Source is synchronized with EPWMCLK<br>  1: Source is passed through asynchronously Reset type: SYSRSn   <br>. */
                  uint16_t RSV_0                     : 2 ;     /*!< [11:10] : reserved. */
            __IOM uint16_t EVT2LATSEL                : 1 ;     /*!< [12:12] : DCAEVT2 Latched signal select:                                  <br>  0 Does not select the DCAEVT2 latched signal (Refer figure "Modifications to DCAEVT1. */
            __IOM uint16_t EVT2LATCLRSEL             : 2 ;     /*!< [14:13] : DCAEVT2 Latched clear source select:                            <br>  00 CNT_ZERO event clears DCAEVT2 latch. */
            __IM  uint16_t EVT2LAT                   : 1 ;     /*!< [15:15] : Indicates the status of DCAEVT2LAT signal. */
        } DCACTLb;
    };

    union
    {
        __IOM uint32_t DCBCTL;  /*!< 0x00000188 */ 
       
        struct
        {
            __IOM uint32_t EVT1SRCSEL                : 1 ;     /*!< [0:0] : DCBEVT1 Source Signal Select 0: Source Is DCBEVT1 Signal 1: Source Is DCEVTFILT Signal Reset type: SYSRSn. */
            __IOM uint32_t EVT1FRCSYNCSEL            : 1 ;     /*!< [1:1] : DCBEVT1 Force Synchronization Signal Select 0: Source is synchronized with EPWMCLK<br>  1: Source is passed through asynchronously Reset type: SYSRSn   <br>. */
            __IOM uint32_t EVT1SOCE                  : 1 ;     /*!< [2:2] : DCBEVT1 SOC, Enable/Disable 0: SOC Generation Disabled          <br>  1: SOC Generation Enabled Reset type: SYSRSn                    <br>. */
            __IOM uint32_t EVT1SYNCE                 : 1 ;     /*!< [3:3] : DCBEVT1 SYNC, Enable/Disable 0: SYNC Generation Disabled        <br>  1: SYNC Generation Enabled Reset type: SYSRSn                   <br>. */
            __IOM uint32_t EVT1LATSEL                : 1 ;     /*!< [4:4] : DCBEVT1 Latched signal select:                                  <br>  0 Does not select the DCBEVT1 latched signal (Refer figure "Modifications to DCBEVT1. */
            __IOM uint32_t EVT1LATCLRSEL             : 2 ;     /*!< [6:5] : DCBEVT1 Latched clear source select:                            <br>  00 CNT_ZERO event clears DCBEVT1 latch. */
            __IM  uint32_t EVT1LAT                   : 1 ;     /*!< [7:7] : Indicates the status of DCBEVT1LAT signal. */
            __IOM uint32_t EVT2SRCSEL                : 1 ;     /*!< [8:8] : DCBEVT2 Source Signal Select 0: Source Is DCBEVT2 Signal 1: Source Is DCEVTFILT Signal Reset type: SYSRSn. */
            __IOM uint32_t EVT2FRCSYNCSEL            : 1 ;     /*!< [9:9] : DCBEVT2 Force Synchronization Signal Select 0: Source is synchronized with EPWMCLK<br>  1: Source is passed through asynchronously Reset type: SYSRSn   <br>. */
                  uint32_t RSV_1                     : 2 ;     /*!< [11:10] : reserved. */
            __IOM uint32_t EVT2LATSEL                : 1 ;     /*!< [12:12] : DCBEVT2 Latched signal select:                                  <br>  0 Does not select the DCBEVT2 latched signal (Refer figure "Modifications to DCBEVT1. */
            __IOM uint32_t EVT2LATCLRSEL             : 2 ;     /*!< [14:13] : DCBEVT2 Latched clear source select:                            <br>  00 CNT_ZERO event clears DCBEVT2 latch. */
            __IM  uint32_t EVT2LAT                   : 1 ;     /*!< [15:15] : Indicates the status of DCBEVT2LAT signal. */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } DCBCTLb;
    };

    uint8_t    RSV_0X18C[2];   /*!< 0x0000018c~0x0000018d : reserved */

    union
    {
        __IOM uint16_t DCFCTL;  /*!< 0x0000018e */ 
       
        struct
        {
            __IOM uint16_t SRCSEL                    : 2 ;     /*!< [1:0] : Filter Block Signal Source Select 00: Source Is DCAEVT1 Signal 01: Source Is DCAEVT2 Signal 10: Source Is DCBEVT1 Signal 11: Source Is DCBEVT2 Signal Reset type: SYSRSn. */
            __IOM uint16_t BLANKE                    : 1 ;     /*!< [2:2] : Blanking Window Enable/Disable 0: Blanking window is disabled   <br>  1: Blanking window is enabled Reset type: SYSRSn                <br>. */
            __IOM uint16_t BLANKINV                  : 1 ;     /*!< [3:3] : Blanking Window Inversion                                       <br>  0: Blanking window not inverted 1: Blanking window inverted Reset type: SYSRSn<br>. */
            __IOM uint16_t PULSESEL                  : 2 ;     /*!< [5:4] : Pulse Select For Blanking & Capture Alignment                   <br>  00: Time-base counter equal to period (TBCTR = TBPRD) 01: Time-base counter equal to zero (TBCTR = 0x00)<br>  10: Time-base counter equal to zero (TBCTR = 0x00) or period (TBCTR = TBPRD)<br>  11: Reserved                                                    <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint16_t EDGEFILTSEL               : 1 ;     /*!< [6:6] : Edge Filter Select:                                             <br>  0: Edge Filter Not Selected 1: Edge Filter Selected Reset type: SYSRSn<br>. */
                  uint16_t RSV_0                     : 1 ;     /*!< [7:7] : reserved. */
            __IOM uint16_t EDGEMODE                  : 2 ;     /*!< [9:8] : Edge Mode Select: 00: Low To High Edge 01: High To Low Edge 10: Both Edges<br>  11: Reserved                                                    <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint16_t EDGECOUNT                 : 3 ;     /*!< [12:10] : Edge Count: These bits select how many edges to count before generating a TBCLK wide pulse on the DCEVTFILT signal:  000: no edges, reset current EDGESTATUS bits to 0,0,0<br>  001: 1 edge                                                     <br>  010: 2 edges                                                    <br>  011: 3 edges                                                    <br>  100: 4 edges                                                    <br>  101: 5 edges                                                    <br>  110: 6 edges                                                    <br>  111: 7 edges                                                    <br>  Reset type: SYSRSn                                              <br>. */
            __IM  uint16_t EDGESTATUS                : 3 ;     /*!< [15:13] : Edge Status:                                                    <br>  These bits reflect the total number of edges currently captured. */
        } DCFCTLb;
    };

    union
    {
        __IOM uint16_t DCCAPCTL;  /*!< 0x00000190 */ 
       
        struct
        {
            __IOM uint16_t CAPE                      : 1 ;     /*!< [0:0] : TBCTR Counter Capture Enable/Disable 0: Disable the time-base counter capture. */
            __IOM uint16_t SHDWMODE                  : 1 ;     /*!< [1:1] : TBCTR Counter Capture Shadow Select Mode                        <br>  0: Enable shadow mode. */
                  uint16_t RSV_0                     : 11;     /*!< [12:2] : reserved. */
            __IM  uint16_t CAPSTS                    : 1 ;     /*!< [13:13] : Latched Status Flag for Capture Event 0: No DC capture event occurred. */
            __IOM uint16_t CAPCLR                    : 1 ;     /*!< [14:14] : DC Capture Latched Status Clear Flag 0: Writing a 0 has no effect. */
            __IOM uint16_t CAPMODE                   : 1 ;     /*!< [15:15] : Counter Capture Mode                                            <br>  0: When a DCEVTFILT occurs and the counter capture is enabled, then the current TBCNT value is captured in the active register. */
        } DCCAPCTLb;
    };

    union
    {
        __IOM uint16_t DCFOFFSET;  /*!< 0x00000192 */ 
       
        struct
        {
            __IOM uint16_t DCFOFFSET                 : 16;     /*!< [15:0] : Blanking Window Offset                                          <br>  These 16-bits specify the number of TBCLK cycles from the blanking window reference to the point when the blanking window is applied. */
        } DCFOFFSETb;
    };

    union
    {
        __IM uint16_t DCFOFFSETCNT;  /*!< 0x00000194 */ 
       
        struct
        {
            __IM  uint16_t DCFOFFSETCNT              : 16;     /*!< [15:0] : Blanking Offset Counter                                         <br>  These 16-bits are read only and indicate the current value of the offset counter. */
        } DCFOFFSETCNTb;
    };

    union
    {
        __IOM uint16_t DCFWINDOW;  /*!< 0x00000196 */ 
       
        struct
        {
            __IOM uint16_t DCFWINDOW                 : 16;     /*!< [15:0] : Blanking Window Width                                           <br>  00h: No blanking window is generated. */
        } DCFWINDOWb;
    };

    union
    {
        __IM uint32_t DCFWINDOWCNT;  /*!< 0x00000198 */ 
       
        struct
        {
            __IM  uint32_t DCFWINDOW                 : 16;     /*!< [15:0] : Blanking Window Counter                                         <br>  These 16 bits are read only and indicate the current value of the window counter. */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } DCFWINDOWCNTb;
    };

    uint8_t    RSV_0X19C[2];   /*!< 0x0000019c~0x0000019d : reserved */

    union
    {
        __IM uint16_t DCCAP;  /*!< 0x0000019e */ 
       
        struct
        {
            __IM  uint16_t DCCAP                     : 16;     /*!< [15:0] : Digital Compare Time-Base Counter Capture                       <br>  To enable time-base counter capture, set the DCCAPCLT[CAPE] bit to 1. */
        } DCCAPb;
    };

    uint8_t    RSV_0X1A0[4];   /*!< 0x000001a0~0x000001a3 : reserved */

    union
    {
        __IOM uint16_t DCAHTRIPSEL;  /*!< 0x000001a4 */ 
       
        struct
        {
            __IOM uint16_t TRIPINPUT1                : 1 ;     /*!< [0:0] : TRIP Input 1                                                    <br>  0: Trip Input 1 not selected as combinational ORed input        <br>  1: Trip Input 1 selected as combinational ORed input to DCAH mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT2                : 1 ;     /*!< [1:1] : TRIP Input 2                                                    <br>  0: Trip Input 2 not selected as combinational ORed input        <br>  1: Trip Input 2 selected as combinational ORed input to DCAH mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT3                : 1 ;     /*!< [2:2] : 0: Trip Input 3 not selected as combinational ORed input        <br>  1: Trip Input 3 selected as combinational ORed input to DCAH mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT4                : 1 ;     /*!< [3:3] : TRIP Input 4                                                    <br>  0: Trip Input 4 not selected as combinational ORed input        <br>  1: Trip Input 4 selected as combinational ORed input to DCAH mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT5                : 1 ;     /*!< [4:4] : TRIP Input 5                                                    <br>  0: Trip Input 5 not selected as combinational ORed input        <br>  1: Trip Input 5 selected as combinational ORed input to DCAH mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT6                : 1 ;     /*!< [5:5] : TRIP Input 6                                                    <br>  0: Trip Input 6 not selected as combinational ORed input        <br>  1: Trip Input 6 selected as combinational ORed input to DCAH mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT7                : 1 ;     /*!< [6:6] : TRIP Input 7                                                    <br>  0: Trip Input 7 not selected as combinational ORed input        <br>  1: Trip Input 7 selected as combinational ORed input to DCAH mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT8                : 1 ;     /*!< [7:7] : TRIP Input 8                                                    <br>  0: Trip Input 8 not selected as combinational ORed input        <br>  1: Trip Input 8 selected as combinational ORed input to DCAH mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT9                : 1 ;     /*!< [8:8] : TRIP Input 9                                                    <br>  0: Trip Input 9 not selected as combinational ORed input        <br>  1: Trip Input 9 selected as combinational ORed input to DCAH mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT10               : 1 ;     /*!< [9:9] : TRIP Input 10                                                   <br>  0: Trip Input 10 not selected as combinational ORed input       <br>  1: Trip Input 10 selected as combinational ORed input to DCAH mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT11               : 1 ;     /*!< [10:10] : TRIP Input 11                                                   <br>  0: Trip Input 11 not selected as combinational ORed input       <br>  1: Trip Input 11 selected as combinational ORed input to DCAH mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT12               : 1 ;     /*!< [11:11] : TRIP Input 12                                                   <br>  0: Trip Input 12 not selected as combinational ORed input       <br>  1: Trip Input 12 selected as combinational ORed input to DCAH mux Reset type: SYSRSn<br>. */
                  uint16_t RSV_1                     : 1 ;     /*!< [12:12] : reserved. */
            __IOM uint16_t TRIPINPUT14               : 1 ;     /*!< [13:13] : TRIP Input 14                                                   <br>  0: Trip Input 14 not selected as combinational ORed input       <br>  1: Trip Input 14 selected as combinational ORed input to DCAH mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT15               : 1 ;     /*!< [14:14] : TRIP Input 15                                                   <br>  0: Trip Input 15 not selected as combinational ORed input       <br>  1: Trip Input 15 selected as combinational ORed input to DCAH mux Reset type: SYSRSn<br>. */
                  uint16_t RSV_0                     : 1 ;     /*!< [15:15] : reserved. */
        } DCAHTRIPSELb;
    };

    union
    {
        __IOM uint16_t DCALTRIPSEL;  /*!< 0x000001a6 */ 
       
        struct
        {
            __IOM uint16_t TRIPINPUT1                : 1 ;     /*!< [0:0] : TRIP Input 1                                                    <br>  0: Trip Input 1 not selected as combinational ORed input        <br>  1: Trip Input 1 selected as combinational ORed input to DCAL mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT2                : 1 ;     /*!< [1:1] : TRIP Input 2                                                    <br>  0: Trip Input 2 not selected as combinational ORed input        <br>  1: Trip Input 2 selected as combinational ORed input to DCAL mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT3                : 1 ;     /*!< [2:2] : TRIP Input 3                                                    <br>  0: Trip Input 3 not selected as combinational ORed input        <br>  1: Trip Input 3 selected as combinational ORed input to DCAL mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT4                : 1 ;     /*!< [3:3] : TRIP Input 4                                                    <br>  0: Trip Input 4 not selected as combinational ORed input        <br>  1: Trip Input 4 selected as combinational ORed input to DCAL mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT5                : 1 ;     /*!< [4:4] : TRIP Input 5                                                    <br>  0: Trip Input 5 not selected as combinational ORed input        <br>  1: Trip Input 5 selected as combinational ORed input to DCAL mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT6                : 1 ;     /*!< [5:5] : TRIP Input 6                                                    <br>  0: Trip Input 6 not selected as combinational ORed input        <br>  1: Trip Input 6 selected as combinational ORed input to DCAL mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT7                : 1 ;     /*!< [6:6] : TRIP Input 7                                                    <br>  0: Trip Input 7 not selected as combinational ORed input        <br>  1: Trip Input 7 selected as combinational ORed input to DCAL mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT8                : 1 ;     /*!< [7:7] : TRIP Input 8                                                    <br>  0: Trip Input 8 not selected as combinational ORed input        <br>  1: Trip Input 8 selected as combinational ORed input to DCAL mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT9                : 1 ;     /*!< [8:8] : TRIP Input 9                                                    <br>  0: Trip Input 9 not selected as combinational ORed input        <br>  1: Trip Input 9 selected as combinational ORed input to DCAL mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT10               : 1 ;     /*!< [9:9] : TRIP Input 10                                                   <br>  0: Trip Input 10 not selected as combinational ORed input       <br>  1: Trip Input 10 selected as combinational ORed input to DCAL mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT11               : 1 ;     /*!< [10:10] : TRIP Input 11                                                   <br>  0: Trip Input 11 not selected as combinational ORed input       <br>  1: Trip Input 11 selected as combinational ORed input to DCAL mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT12               : 1 ;     /*!< [11:11] : TRIP Input 12                                                   <br>  0: Trip Input 12 not selected as combinational ORed input       <br>  1: Trip Input 12 selected as combinational ORed input to DCAL mux Reset type: SYSRSn<br>. */
                  uint16_t RSV_1                     : 1 ;     /*!< [12:12] : reserved. */
            __IOM uint16_t TRIPINPUT14               : 1 ;     /*!< [13:13] : TRIP Input 14                                                   <br>  0: Trip Input 14 not selected as combinational ORed input       <br>  1: Trip Input 14 selected as combinational ORed input to DCAL mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT15               : 1 ;     /*!< [14:14] : TRIP Input 15                                                   <br>  0: Trip Input 15 not selected as combinational ORed input       <br>  1: Trip Input 15 selected as combinational ORed input to DCAL mux Reset type: SYSRSn<br>. */
                  uint16_t RSV_0                     : 1 ;     /*!< [15:15] : reserved. */
        } DCALTRIPSELb;
    };

    union
    {
        __IOM uint16_t DCBHTRIPSEL;  /*!< 0x000001a8 */ 
       
        struct
        {
            __IOM uint16_t TRIPINPUT1                : 1 ;     /*!< [0:0] : TRIP Input 1                                                    <br>  0: Trip Input 1 not selected as combinational ORed input        <br>  1: Trip Input 1 selected as combinational ORed input to DCBH mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT2                : 1 ;     /*!< [1:1] : TRIP Input 2                                                    <br>  0: Trip Input 2 not selected as combinational ORed input        <br>  1: Trip Input 2 selected as combinational ORed input to DCBH mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT3                : 1 ;     /*!< [2:2] : TRIP Input 3                                                    <br>  0: Trip Input 3 not selected as combinational ORed input        <br>  1: Trip Input 3 selected as combinational ORed input to DCBH mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT4                : 1 ;     /*!< [3:3] : TRIP Input 4                                                    <br>  0: Trip Input 4 not selected as combinational ORed input        <br>  1: Trip Input 4 selected as combinational ORed input to DCBH mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT5                : 1 ;     /*!< [4:4] : TRIP Input 5                                                    <br>  0: Trip Input 5 not selected as combinational ORed input        <br>  1: Trip Input 5 selected as combinational ORed input to DCBH mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT6                : 1 ;     /*!< [5:5] : TRIP Input 6                                                    <br>  0: Trip Input 6 not selected as combinational ORed input        <br>  1: Trip Input 6 selected as combinational ORed input to DCBH mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT7                : 1 ;     /*!< [6:6] : TRIP Input 7                                                    <br>  0: Trip Input 7 not selected as combinational ORed input        <br>  1: Trip Input 7 selected as combinational ORed input to DCBH mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT8                : 1 ;     /*!< [7:7] : TRIP Input 8                                                    <br>  0: Trip Input 8 not selected as combinational ORed input        <br>  1: Trip Input 8 selected as combinational ORed input to DCBH mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT9                : 1 ;     /*!< [8:8] : TRIP Input 9                                                    <br>  0: Trip Input 9 not selected as combinational ORed input        <br>  1: Trip Input 9 selected as combinational ORed input to DCBH mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT10               : 1 ;     /*!< [9:9] : TRIP Input 10                                                   <br>  0: Trip Input 10 not selected as combinational ORed input       <br>  1: Trip Input 10 selected as combinational ORed input to DCBH mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT11               : 1 ;     /*!< [10:10] : TRIP Input 11                                                   <br>  0: Trip Input 11 not selected as combinational ORed input       <br>  1: Trip Input 11 selected as combinational ORed input to DCBH mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT12               : 1 ;     /*!< [11:11] : TRIP Input 12                                                   <br>  0: Trip Input 12 not selected as combinational ORed input       <br>  1: Trip Input 12 selected as combinational ORed input to DCBH mux Reset type: SYSRSn<br>. */
                  uint16_t RSV_1                     : 1 ;     /*!< [12:12] : reserved. */
            __IOM uint16_t TRIPINPUT14               : 1 ;     /*!< [13:13] : TRIP Input 14                                                   <br>  0: Trip Input 14 not selected as combinational ORed input       <br>  1: Trip Input 14 selected as combinational ORed input to DCBH mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT15               : 1 ;     /*!< [14:14] : TRIP Input 15                                                   <br>  0: Trip Input 15 not selected as combinational ORed input       <br>  1: Trip Input 15 selected as combinational ORed input to DCBH mux Reset type: SYSRSn<br>. */
                  uint16_t RSV_0                     : 1 ;     /*!< [15:15] : reserved. */
        } DCBHTRIPSELb;
    };

    union
    {
        __IOM uint16_t DCBLTRIPSEL;  /*!< 0x000001aa */ 
       
        struct
        {
            __IOM uint16_t TRIPINPUT1                : 1 ;     /*!< [0:0] : TRIP Input 1                                                    <br>  0: Trip Input 1 not selected as combinational ORed input        <br>  1: Trip Input 1 selected as combinational ORed input to DCAL mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT2                : 1 ;     /*!< [1:1] : TRIP Input 2                                                    <br>  0: Trip Input 2 not selected as combinational ORed input        <br>  1: Trip Input 2 selected as combinational ORed input to DCAL mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT3                : 1 ;     /*!< [2:2] : TRIP Input 3                                                    <br>  0: Trip Input 3 not selected as combinational ORed input        <br>  1: Trip Input 3 selected as combinational ORed input to DCAL mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT4                : 1 ;     /*!< [3:3] : TRIP Input 4                                                    <br>  0: Trip Input 4 not selected as combinational ORed input        <br>  1: Trip Input 4 selected as combinational ORed input to DCAL mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT5                : 1 ;     /*!< [4:4] : TRIP Input 5                                                    <br>  0: Trip Input 5 not selected as combinational ORed input        <br>  1: Trip Input 5 selected as combinational ORed input to DCAL mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT6                : 1 ;     /*!< [5:5] : 0: Trip Input 6 not selected as combinational ORed input        <br>  1: Trip Input 6 selected as combinational ORed input to DCAL mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT7                : 1 ;     /*!< [6:6] : TRIP Input 7                                                    <br>  0: Trip Input 7 not selected as combinational ORed input        <br>  1: Trip Input 7 selected as combinational ORed input to DCAL mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT8                : 1 ;     /*!< [7:7] : TRIP Input 8                                                    <br>  0: Trip Input 8 not selected as combinational ORed input        <br>  1: Trip Input 8 selected as combinational ORed input to DCAL mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT9                : 1 ;     /*!< [8:8] : TRIP Input 9                                                    <br>  0: Trip Input 9 not selected as combinational ORed input        <br>  1: Trip Input 9 selected as combinational ORed input to DCAL mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT10               : 1 ;     /*!< [9:9] : TRIP Input 10                                                   <br>  0: Trip Input 10 not selected as combinational ORed input       <br>  1: Trip Input 10 selected as combinational ORed input to DCAL mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT11               : 1 ;     /*!< [10:10] : TRIP Input 11                                                   <br>  0: Trip Input 11 not selected as combinational ORed input       <br>  1: Trip Input 11 selected as combinational ORed input to DCAL mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT12               : 1 ;     /*!< [11:11] : TRIP Input 12                                                   <br>  0: Trip Input 12 not selected as combinational ORed input       <br>  1: Trip Input 12 selected as combinational ORed input to DCAL mux Reset type: SYSRSn<br>. */
                  uint16_t RSV_1                     : 1 ;     /*!< [12:12] : reserved. */
            __IOM uint16_t TRIPINPUT14               : 1 ;     /*!< [13:13] : TRIP Input 14                                                   <br>  0: Trip Input 14 not selected as combinational ORed input       <br>  1: Trip Input 14 selected as combinational ORed input to DCAL mux Reset type: SYSRSn<br>. */
            __IOM uint16_t TRIPINPUT15               : 1 ;     /*!< [14:14] : TRIP Input 15                                                   <br>  0: Trip Input 15 not selected as combinational ORed input       <br>  1: Trip Input 15 selected as combinational ORed input to DCAL mux Reset type: SYSRSn<br>. */
                  uint16_t RSV_0                     : 1 ;     /*!< [15:15] : reserved. */
        } DCBLTRIPSELb;
    };

    uint8_t    RSV_0X1AC[72];   /*!< 0x000001ac~0x000001f3 : reserved */

    union
    {
        __IOM uint32_t EPWMLOCK;  /*!< 0x000001f4 */ 
       
        struct
        {
            __IOM uint32_t HRLOCK                    : 1 ;     /*!< [0:0] : 0: HRPWM registers from 0x20 to 0x2D offsets are protected by EALLOW<br>  1: HRPWM registers from 0x20 and 0x2D offsets are locked and not writable. */
            __IOM uint32_t GLLOCK                    : 1 ;     /*!< [1:1] : 0:TripZone registers from 0x34 to 0x35 offsets are protected by EALLOW. */
            __IOM uint32_t TZCFGLOCK                 : 1 ;     /*!< [2:2] : 0:TripZone registers from 0x80 to 0x8D and TZTRIPOUTSEL at 0x9D offsets are protected by EALLOW. */
            __IOM uint32_t TZCLRLOCK                 : 1 ;     /*!< [3:3] : 0:Digital Compare registers from 0x97 to 0x9B offsets are protected by EALLOW. */
            __IOM uint32_t DCLOCK                    : 1 ;     /*!< [4:4] : 0:Digital Compare registers from 0xC0 to 0xD9 offsets are protected by EALLOW. */
                  uint32_t RSV_0                     : 11;     /*!< [15:5] : reserved. */
            __IM  uint32_t KEY                       : 16;     /*!< [31:16] : Write to this register succeeds only if this field is written with a value of 0xa5a5<br>  Note:                                                           <br>  [1] Due to this KEY, only 32-bit writes will succeed (provided the KEY matches). */
        } EPWMLOCKb;
    };

    uint8_t    RSV_0X1F8[2];   /*!< 0x000001f8~0x000001f9 : reserved */

    union
    {
        __IM uint16_t HWVDELVAL;  /*!< 0x000001fa */ 
       
        struct
        {
            __IM  uint16_t HWVDELVAL                 : 16;     /*!< [15:0] : Hardware Valley Delay Value Register                            <br>  This read only register reflects the hardware delay value calculated by the equations defined in VCAPCTL[VDELAYDIV]. */
        } HWVDELVALb;
    };

    union
    {
        __IM uint32_t VCNTVAL;  /*!< 0x000001fc */ 
       
        struct
        {
            __IM  uint32_t VCNTVAL                   : 16;     /*!< [15:0] : Valley Time Base Counter Register                               <br>  This register reflects the captured VCNT value upon occurrence of STOPEDGE selected in VCNTCFG register. */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } VCNTVALb;
    };

    uint8_t    RSV_0X200[32];   /*!< 0x00000200~0x0000021f : reserved */

    union
    {
        __IOM uint32_t DCFCTL2;  /*!< 0x00000220 */ 
       
        struct
        {
            __IOM uint32_t EDGECAPMODE               : 2 ;     /*!< [1:0] : Edge Cap Mode Select: 00: Low To High Edge 01: High To Low Edge 10: Both Edges 11: Reserved Reset type: SYSRSn. */
                  uint32_t RSV_0                     : 30;     /*!< [31:2] : reserved. */
        } DCFCTL2b;
    };

    union
    {
        __IOM uint32_t TZDLYCTL;  /*!< 0x00000224 */ 
       
        struct
        {
            __IOM uint32_t DLYMODEA                  : 1 ;     /*!< [0:0] : Delay Mode for channel A: 0: select no delay mode 1: select delau mode Reset type: SYSRSn. */
                  uint32_t RSV_1                     : 15;     /*!< [15:1] : reserved. */
            __IOM uint32_t DLYMODEB                  : 1 ;     /*!< [16:16] : Delay Mode for channel B: 0: select no delay mode 1: select delau mode Reset type: SYSRSn. */
                  uint32_t RSV_0                     : 15;     /*!< [31:17] : reserved. */
        } TZDLYCTLb;
    };

    union
    {
        __IOM uint32_t TZDLYPRD;  /*!< 0x00000228 */ 
       
        struct
        {
            __IOM uint32_t ADLYPRD                   : 16;     /*!< [15:0] : Delay counter period for channel A                              <br>  0: Delay greater than 1*Tclk_pwm, less than 2*Tclk_pwm take effect<br>  1: Delay greater than 2*Tclk_pwm, less than 3*Tclk_pwm take effect<br>  . */
            __IOM uint32_t BDLYPRD                   : 16;     /*!< [31:16] : Delay counter period for channel B                              <br>  0: Delay greater than 1*Tclk_pwm, less than 2*Tclk_pwm take effect<br>  1: Delay greater than 2*Tclk_pwm, less than 3*Tclk_pwm take effect<br>  . */
        } TZDLYPRDb;
    };

    union
    {
        __IOM uint32_t DICTL;  /*!< 0x0000022c */ 
       
        struct
        {
            __IM  uint32_t DICTR                     : 4 ;     /*!< [3:0] : Dithering Counter                                               <br>  Reset type: SYSRSn                                              <br>. */
                  uint32_t RSV_3                     : 4 ;     /*!< [7:4] : reserved. */
            __IOM uint32_t DICMP                     : 4 ;     /*!< [11:8] : Dithering Counter Compare Value                                 <br>  Reset type: SYSRSn                                              <br>. */
                  uint32_t RSV_2                     : 4 ;     /*!< [15:12] : reserved. */
            __IOM uint32_t DISWCLR                   : 1 ;     /*!< [16:16] : Dithering Counter Software Clear                                <br>  0: Write 0 has no effect                                        <br>  1: Clear Dithering Counter                                      <br>  Reset type: SYSRSn                                              <br>. */
                  uint32_t RSV_1                     : 7 ;     /*!< [23:17] : reserved. */
            __IOM uint32_t DIMODE                    : 3 ;     /*!< [26:24] : Dithering Mode Select                                           <br>  0: cmpb unchanged, cmpa unchanged, tcprd unchanged              <br>  1: cmpb unchanged, cmpa unchanged, tcprd+1                      <br>  2: cmpb unchanged, cmpa+1, tcprd unchanged                      <br>  3: cmpb unchanged, cmpa+1, tcprd+1                              <br>  4: cmpb+1, cmpa unchanged, tcprd unchanged                      <br>  5: cmpb+1, cmpa unchanged, tcprd+1                              <br>  6: cmpb+1, cmpa+1, tcprd unchanged                              <br>  7: cmpb+1, cmpa+1, tcprd+1                                      <br>  Reset type: SYSRSn                                              <br>. */
                  uint32_t RSV_0                     : 5 ;     /*!< [31:27] : reserved. */
        } DICTLb;
    };

    uint8_t    RSV_0X230[48];   /*!< 0x00000230~0x0000025f : reserved */

    union
    {
        __IM uint32_t DBCLKGEN;  /*!< 0x00000260 */ 
       
        struct
        {
            __IM  uint32_t TC_CNT                    : 10;     /*!< [9:0] : Reset type: SYSRSn. */
                  uint32_t RSV_1                     : 6 ;     /*!< [15:10] : reserved. */
            __IM  uint32_t CNT_MAX                   : 10;     /*!< [25:16] : Reset type: SYSRSn. */
                  uint32_t RSV_0                     : 6 ;     /*!< [31:26] : reserved. */
        } DBCLKGENb;
    };

    union
    {
        __IM uint32_t DBLINKTCPRD;  /*!< 0x00000264 */ 
       
        struct
        {
            __IM  uint32_t PWM_LINK_TCPRD_SEL        : 16;     /*!< [15:0] : Reset type: SYSRSn. */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } DBLINKTCPRDb;
    };

    union
    {
        __IM uint32_t DBLINKCMPAB;  /*!< 0x00000268 */ 
       
        struct
        {
            __IM  uint32_t PWM_LINK_CMPA_SEL         : 16;     /*!< [15:0] : Reset type: SYSRSn. */
            __IM  uint32_t PWM_LINK_CMPB_SEL         : 16;     /*!< [31:16] : Reset type: SYSRSn. */
        } DBLINKCMPABb;
    };

    union
    {
        __IM uint32_t DBLINKCMPCD;  /*!< 0x0000026c */ 
       
        struct
        {
            __IM  uint32_t PWM_LINK_CMPC_SEL         : 16;     /*!< [15:0] : Reset type: SYSRSn. */
            __IM  uint32_t PWM_LINK_CMPD_SEL         : 16;     /*!< [31:16] : Reset type: SYSRSn. */
        } DBLINKCMPCDb;
    };

    union
    {
        __IM uint32_t DBLINKGLD;  /*!< 0x00000270 */ 
       
        struct
        {
            __IM  uint32_t PWM_LINK_GLDFRCLOAD_SEL   : 1 ;     /*!< [0:0] : Reset type: SYSRSn. */
                  uint32_t RSV_1                     : 15;     /*!< [15:1] : reserved. */
            __IM  uint32_t PWM_LINK_GLDOOFFLOAD_SEL  : 1 ;     /*!< [16:16] : Reset type: SYSRSn. */
                  uint32_t RSV_0                     : 15;     /*!< [31:17] : reserved. */
        } DBLINKGLDb;
    };

    union
    {
        __IM uint32_t DBSHDTCPRD;  /*!< 0x00000274 */ 
       
        struct
        {
            __IM  uint32_t RA_TCPRD_TCPRD            : 16;     /*!< [15:0] : Reset type: SYSRSn. */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } DBSHDTCPRDb;
    };

    union
    {
        __IM uint32_t DBSHDCMPAB;  /*!< 0x00000278 */ 
       
        struct
        {
            __IM  uint32_t RA_CMPA_CMPA              : 16;     /*!< [15:0] : Reset type: SYSRSn. */
            __IM  uint32_t RA_CMPB_CMPB              : 16;     /*!< [31:16] : Reset type: SYSRSn. */
        } DBSHDCMPABb;
    };

    union
    {
        __IM uint32_t DBSHDCMPCD;  /*!< 0x0000027c */ 
       
        struct
        {
            __IM  uint32_t RA_CMPC_CMPC              : 16;     /*!< [15:0] : Reset type: SYSRSn. */
            __IM  uint32_t RA_CMPD_CMPD              : 16;     /*!< [31:16] : Reset type: SYSRSn. */
        } DBSHDCMPCDb;
    };

    union
    {
        __IM uint32_t DBSHDWGA;  /*!< 0x00000280 */ 
       
        struct
        {
            __IM  uint32_t RA_WGCFGA_ACAD            : 2 ;     /*!< [1:0] : Reset type: SYSRSn. */
            __IM  uint32_t RA_WGCFGA_ACAU            : 2 ;     /*!< [3:2] : Reset type: SYSRSn. */
            __IM  uint32_t RA_WGCFGA_ACBD            : 2 ;     /*!< [5:4] : Reset type: SYSRSn. */
            __IM  uint32_t RA_WGCFGA_ACBU            : 2 ;     /*!< [7:6] : Reset type: SYSRSn. */
            __IM  uint32_t RA_WGCFGA_AZRO            : 2 ;     /*!< [9:8] : Reset type: SYSRSn. */
            __IM  uint32_t RA_WGCFGA_APRD            : 2 ;     /*!< [11:10] : Reset type: SYSRSn. */
                  uint32_t RSV_1                     : 4 ;     /*!< [15:12] : reserved. */
            __IM  uint32_t RA_WGCFGA_AEVT1D          : 2 ;     /*!< [17:16] : Reset type: SYSRSn. */
            __IM  uint32_t RA_WGCFGA_AEVT1U          : 2 ;     /*!< [19:18] : Reset type: SYSRSn. */
            __IM  uint32_t RA_WGCFGA_AEVT2D          : 2 ;     /*!< [21:20] : Reset type: SYSRSn. */
            __IM  uint32_t RA_WGCFGA_AEVT2U          : 2 ;     /*!< [23:22] : Reset type: SYSRSn. */
            __IM  uint32_t RA_WGCTL_CSWFRCACTA       : 2 ;     /*!< [25:24] : Reset type: SYSRSn. */
                  uint32_t RSV_0                     : 6 ;     /*!< [31:26] : reserved. */
        } DBSHDWGAb;
    };

    union
    {
        __IM uint32_t DBSHDWGB;  /*!< 0x00000284 */ 
       
        struct
        {
            __IM  uint32_t RA_WGCFGB_BCAD            : 2 ;     /*!< [1:0] : Reset type: SYSRSn. */
            __IM  uint32_t RA_WGCFGB_BCAU            : 2 ;     /*!< [3:2] : Reset type: SYSRSn. */
            __IM  uint32_t RA_WGCFGB_BCBD            : 2 ;     /*!< [5:4] : Reset type: SYSRSn. */
            __IM  uint32_t RA_WGCFGB_BCBU            : 2 ;     /*!< [7:6] : Reset type: SYSRSn. */
            __IM  uint32_t RA_WGCFGB_BZRO            : 2 ;     /*!< [9:8] : Reset type: SYSRSn. */
            __IM  uint32_t RA_WGCFGB_BPRD            : 2 ;     /*!< [11:10] : Reset type: SYSRSn. */
                  uint32_t RSV_1                     : 4 ;     /*!< [15:12] : reserved. */
            __IM  uint32_t RA_WGCFGB_BEVT1D          : 2 ;     /*!< [17:16] : Reset type: SYSRSn. */
            __IM  uint32_t RA_WGCFGB_BEVT1U          : 2 ;     /*!< [19:18] : Reset type: SYSRSn. */
            __IM  uint32_t RA_WGCFGB_BEVT2D          : 2 ;     /*!< [21:20] : Reset type: SYSRSn. */
            __IM  uint32_t RA_WGCFGB_BEVT2U          : 2 ;     /*!< [23:22] : Reset type: SYSRSn. */
            __IM  uint32_t RA_WGCTL_CSWFRCACTB       : 2 ;     /*!< [25:24] : Reset type: SYSRSn. */
                  uint32_t RSV_0                     : 6 ;     /*!< [31:26] : reserved. */
        } DBSHDWGBb;
    };

    union
    {
        __IM uint32_t DBSHDDTCTL;  /*!< 0x00000288 */ 
       
        struct
        {
            __IM  uint32_t RA_DTCTL_INSEL            : 2 ;     /*!< [1:0] : Reset type: SYSRSn. */
                  uint32_t RSV_2                     : 6 ;     /*!< [7:2] : reserved. */
            __IM  uint32_t RA_DTCTL_POLSEL           : 2 ;     /*!< [9:8] : Reset type: SYSRSn. */
                  uint32_t RSV_1                     : 6 ;     /*!< [15:10] : reserved. */
            __IM  uint32_t RA_DTCTL_OUTSEL           : 2 ;     /*!< [17:16] : Reset type: SYSRSn. */
                  uint32_t RSV_0                     : 14;     /*!< [31:18] : reserved. */
        } DBSHDDTCTLb;
    };

    union
    {
        __IM uint32_t DBSHDDTXED;  /*!< 0x0000028c */ 
       
        struct
        {
            __IM  uint32_t RA_DTRED_DTRED            : 14;     /*!< [13:0] : Reset type: SYSRSn. */
                  uint32_t RSV_1                     : 2 ;     /*!< [15:14] : reserved. */
            __IM  uint32_t RA_DTFED_DTFED            : 14;     /*!< [29:16] : Reset type: SYSRSn. */
                  uint32_t RSV_0                     : 2 ;     /*!< [31:30] : reserved. */
        } DBSHDDTXEDb;
    };

    union
    {
        __IM uint32_t DBDITHER1;  /*!< 0x00000290 */ 
       
        struct
        {
            __IM  uint32_t RI_TCPRD_TCPRD            : 16;     /*!< [15:0] : Reset type: SYSRSn. */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } DBDITHER1b;
    };

    union
    {
        __IM uint32_t DBDITHER2;  /*!< 0x00000294 */ 
       
        struct
        {
            __IM  uint32_t RI_CMPA_CMPA              : 16;     /*!< [15:0] : Reset type: SYSRSn. */
            __IM  uint32_t RI_CMPB_CMPB              : 16;     /*!< [31:16] : Reset type: SYSRSn. */
        } DBDITHER2b;
    };

    union
    {
        __IM uint32_t DBTC;  /*!< 0x00000298 */ 
       
        struct
        {
            __IM  uint32_t TCCTR_PRE                 : 16;     /*!< [15:0] : Reset type: SYSRSn. */
            __IM  uint32_t TCCTR_NEXT                : 16;     /*!< [31:16] : Reset type: SYSRSn. */
        } DBTCb;
    };

    union
    {
        __IM uint32_t DBDT1;  /*!< 0x0000029c */ 
       
        struct
        {
            __IM  uint32_t CNT_R_S                   : 14;     /*!< [13:0] : Reset type: SYSRSn. */
                  uint32_t RSV_1                     : 2 ;     /*!< [15:14] : reserved. */
            __IM  uint32_t CNT_F_S                   : 14;     /*!< [29:16] : Reset type: SYSRSn. */
                  uint32_t RSV_0                     : 2 ;     /*!< [31:30] : reserved. */
        } DBDT1b;
    };

    union
    {
        __IM uint32_t DBDT2;  /*!< 0x000002a0 */ 
       
        struct
        {
            __IM  uint32_t CNT_R_POS                 : 14;     /*!< [13:0] : Reset type: SYSRSn. */
                  uint32_t RSV_1                     : 2 ;     /*!< [15:14] : reserved. */
            __IM  uint32_t CNT_R_NEG                 : 14;     /*!< [29:16] : Reset type: SYSRSn. */
                  uint32_t RSV_0                     : 2 ;     /*!< [31:30] : reserved. */
        } DBDT2b;
    };

    union
    {
        __IM uint32_t DBDT3;  /*!< 0x000002a4 */ 
       
        struct
        {
            __IM  uint32_t CNT_F_POS                 : 14;     /*!< [13:0] : Reset type: SYSRSn. */
                  uint32_t RSV_1                     : 2 ;     /*!< [15:14] : reserved. */
            __IM  uint32_t CNT_F_NEG                 : 14;     /*!< [29:16] : Reset type: SYSRSn. */
                  uint32_t RSV_0                     : 2 ;     /*!< [31:30] : reserved. */
        } DBDT3b;
    };

    union
    {
        __IM uint32_t DBCHP1;  /*!< 0x000002a8 */ 
       
        struct
        {
            __IM  uint32_t CNT_PS_MAX                : 6 ;     /*!< [5:0] : Reset type: SYSRSn. */
                  uint32_t RSV_1                     : 10;     /*!< [15:6] : reserved. */
            __IM  uint32_t CNT_PS_DUTY               : 6 ;     /*!< [21:16] : Reset type: SYSRSn. */
                  uint32_t RSV_0                     : 10;     /*!< [31:22] : reserved. */
        } DBCHP1b;
    };

    union
    {
        __IM uint32_t DBCHP2;  /*!< 0x000002ac */ 
       
        struct
        {
            __IM  uint32_t PS_CNT_A                  : 6 ;     /*!< [5:0] : Reset type: SYSRSn. */
                  uint32_t RSV_2                     : 2 ;     /*!< [7:6] : reserved. */
            __IM  uint32_t PS_CNT_B                  : 6 ;     /*!< [13:8] : Reset type: SYSRSn. */
                  uint32_t RSV_1                     : 2 ;     /*!< [15:14] : reserved. */
            __IM  uint32_t PS_CNT                    : 6 ;     /*!< [21:16] : Reset type: SYSRSn. */
                  uint32_t RSV_0                     : 10;     /*!< [31:22] : reserved. */
        } DBCHP2b;
    };

    union
    {
        __IM uint32_t DBCHP3;  /*!< 0x000002b0 */ 
       
        struct
        {
            __IM  uint32_t OOFF_CNT_A                : 6 ;     /*!< [5:0] : Reset type: SYSRSn. */
                  uint32_t RSV_2                     : 2 ;     /*!< [7:6] : reserved. */
            __IM  uint32_t OOFF_CNT_B                : 6 ;     /*!< [13:8] : Reset type: SYSRSn. */
                  uint32_t RSV_1                     : 2 ;     /*!< [15:14] : reserved. */
            __IM  uint32_t OOFF_WIDTH                : 6 ;     /*!< [21:16] : Reset type: SYSRSn. */
                  uint32_t RSV_0                     : 10;     /*!< [31:22] : reserved. */
        } DBCHP3b;
    };

    union
    {
        __IM uint32_t DBDP1;  /*!< 0x000002b4 */ 
       
        struct
        {
            __IM  uint32_t OFFSET_CNT                : 16;     /*!< [15:0] : Reset type: SYSRSn. */
            __IM  uint32_t WINDOW_CNT                : 16;     /*!< [31:16] : Reset type: SYSRSn. */
        } DBDP1b;
    };

    union
    {
        __IM uint32_t DBDP2;  /*!< 0x000002b8 */ 
       
        struct
        {
            __IM  uint32_t VALLEY_CNT                : 16;     /*!< [15:0] : Reset type: SYSRSn. */
            __IM  uint32_t VALLEY_CNT_REG            : 16;     /*!< [31:16] : Reset type: SYSRSn. */
        } DBDP2b;
    };

    union
    {
        __IM uint32_t DBDP3;  /*!< 0x000002bc */ 
       
        struct
        {
            __IM  uint32_t DELAY_CNT                 : 16;     /*!< [15:0] : Reset type: SYSRSn. */
            __IM  uint32_t HWVDELAY_VALUE            : 16;     /*!< [31:16] : Reset type: SYSRSn. */
        } DBDP3b;
    };

    union
    {
        __IM uint32_t DBDP4;  /*!< 0x000002c0 */ 
       
        struct
        {
            __IM  uint32_t HWVDELAY_VALUE_TMP        : 17;     /*!< [16:0] : Reset type: SYSRSn. */
                  uint32_t RSV_0                     : 15;     /*!< [31:17] : reserved. */
        } DBDP4b;
    };

    union
    {
        __IM uint32_t DBDP5;  /*!< 0x000002c4 */ 
       
        struct
        {
            __IM  uint32_t TCCTR_SHADOW              : 16;     /*!< [15:0] : Reset type: SYSRSn. */
            __IM  uint32_t TCCTR_ACTIVE              : 16;     /*!< [31:16] : Reset type: SYSRSn. */
        } DBDP5b;
    };

    union
    {
        __IM uint32_t DBEH;  /*!< 0x000002c8 */ 
       
        struct
        {
            __IM  uint32_t SOCA_CNT                  : 4 ;     /*!< [3:0] : Reset type: SYSRSn. */
                  uint32_t RSV_2                     : 4 ;     /*!< [7:4] : reserved. */
            __IM  uint32_t SOCB_CNT                  : 4 ;     /*!< [11:8] : Reset type: SYSRSn. */
                  uint32_t RSV_1                     : 4 ;     /*!< [15:12] : reserved. */
            __IM  uint32_t INT_CNT                   : 4 ;     /*!< [19:16] : Reset type: SYSRSn. */
                  uint32_t RSV_0                     : 12;     /*!< [31:20] : reserved. */
        } DBEHb;
    };

    union
    {
        __IM uint32_t DBER1;  /*!< 0x000002cc */ 
       
        struct
        {
            __IM  uint32_t CNT_AVALDLY               : 16;     /*!< [15:0] : Reset type: SYSRSn. */
            __IM  uint32_t CNT_APUDLY                : 16;     /*!< [31:16] : Reset type: SYSRSn. */
        } DBER1b;
    };

    union
    {
        __IM uint32_t DBER2;  /*!< 0x000002d0 */ 
       
        struct
        {
            __IM  uint32_t CNT_BVALDLY               : 16;     /*!< [15:0] : Reset type: SYSRSn. */
            __IM  uint32_t CNT_BPUDLY                : 16;     /*!< [31:16] : Reset type: SYSRSn. */
        } DBER2b;
    };

    uint8_t    RSV_0X2D4[44];   /*!< 0x000002d4~0x000002ff : reserved */

    union
    {
        __IOM uint32_t DBPORTSEL1;  /*!< 0x00000300 */ 
       
        struct
        {
            __IOM uint32_t DBGSYNCSEL                : 5 ;     /*!< [4:0] : Reset type: SYSRSn. */
                  uint32_t RSV_3                     : 3 ;     /*!< [7:5] : reserved. */
            __IOM uint32_t DBGSHDREG                 : 5 ;     /*!< [12:8] : Reset type: SYSRSn. */
                  uint32_t RSV_2                     : 3 ;     /*!< [15:13] : reserved. */
            __IOM uint32_t DBGTC                     : 5 ;     /*!< [20:16] : Reset type: SYSRSn. */
                  uint32_t RSV_1                     : 3 ;     /*!< [23:21] : reserved. */
            __IOM uint32_t DBGWG                     : 5 ;     /*!< [28:24] : Reset type: SYSRSn. */
                  uint32_t RSV_0                     : 3 ;     /*!< [31:29] : reserved. */
        } DBPORTSEL1b;
    };

    union
    {
        __IOM uint32_t DBPORTSEL2;  /*!< 0x00000304 */ 
       
        struct
        {
            __IOM uint32_t DBGDT                     : 5 ;     /*!< [4:0] : Reset type: SYSRSn. */
                  uint32_t RSV_3                     : 3 ;     /*!< [7:5] : reserved. */
            __IOM uint32_t DBGPC                     : 5 ;     /*!< [12:8] : Reset type: SYSRSn. */
                  uint32_t RSV_2                     : 3 ;     /*!< [15:13] : reserved. */
            __IOM uint32_t DBGDP                     : 5 ;     /*!< [20:16] : Reset type: SYSRSn. */
                  uint32_t RSV_1                     : 3 ;     /*!< [23:21] : reserved. */
            __IOM uint32_t DBGET                     : 5 ;     /*!< [28:24] : Reset type: SYSRSn. */
                  uint32_t RSV_0                     : 3 ;     /*!< [31:29] : reserved. */
        } DBPORTSEL2b;
    };

    union
    {
        __IOM uint32_t DBPORTSEL3;  /*!< 0x00000308 */ 
       
        struct
        {
            __IOM uint32_t DBGER                     : 5 ;     /*!< [4:0] : Reset type: SYSRSn. */
                  uint32_t RSV_1                     : 11;     /*!< [15:5] : reserved. */
            __IOM uint32_t DBGSUB                    : 5 ;     /*!< [20:16] : Reset type: SYSRSn. */
                  uint32_t RSV_0                     : 11;     /*!< [31:21] : reserved. */
        } DBPORTSEL3b;
    };
} EPWM_REGS_Type;


/*!
 * @}
 */

/*!
 * \name EPWM Base Address Definitions
 *
 * @{
 */

 /*! \brief EPWM_REGS base address */
#define EPWM_REGS_BASE (0x40502400UL)
/*! \brief EPWM_REGS base pointer */
#define EPWM_REGS ((EPWM_REGS_Type *) EPWM_REGS_BASE)


#define EPWM1  (EPWM_REGS_Type *)0x40500400U
#define EPWM2  (EPWM_REGS_Type *)0x40500800U
#define EPWM3  (EPWM_REGS_Type *)0x40500C00U
#define EPWM4  (EPWM_REGS_Type *)0x40501000U
#define EPWM5  (EPWM_REGS_Type *)0x40501400U
#define EPWM6  (EPWM_REGS_Type *)0x40501800U
#define EPWM7  (EPWM_REGS_Type *)0x40501C00U
#define EPWM8  (EPWM_REGS_Type *)0x40502000U
#define EPWM9  (EPWM_REGS_Type *)0x40502400U
#define EPWM10 (EPWM_REGS_Type *)0x40502800U
#define EPWM11 (EPWM_REGS_Type *)0x40502C00U
#define EPWM12 (EPWM_REGS_Type *)0x40503000U

/*!
 * @}
 */

 
/*!
 * \name EPWM Register Bitfield Definitions
 *
 * @{
 */

 /* TBCTL bitfield */
#define EPWM_REGS_TBCTL_FREE_SOFT_Pos    (14U)                                                                                 /*!< FREE_SOFT Postion   14         */ 
#define EPWM_REGS_TBCTL_FREE_SOFT_Msk    (0x3U << EPWM_REGS_TBCTL_FREE_SOFT_Pos)                                               /*!< FREE_SOFT Mask      0x0000C000 */
#define EPWM_REGS_TBCTL_FREE_SOFT_Set(x) (((uint16_t) (x) << EPWM_REGS_TBCTL_FREE_SOFT_Pos) & EPWM_REGS_TBCTL_FREE_SOFT_Msk)   /*!< FREE_SOFT Set Value            */
#define EPWM_REGS_TBCTL_FREE_SOFT_Get(x) (((uint16_t) (x) & EPWM_REGS_TBCTL_FREE_SOFT_Msk) >> EPWM_REGS_TBCTL_FREE_SOFT_Pos)   /*!< FREE_SOFT Get Value            */


#define EPWM_REGS_TBCTL_PHSDIR_Pos    (13U)                                                                                 /*!< PHSDIR Postion   13         */ 
#define EPWM_REGS_TBCTL_PHSDIR_Msk    (0x1U << EPWM_REGS_TBCTL_PHSDIR_Pos)                                                  /*!< PHSDIR Mask      0x00002000 */
#define EPWM_REGS_TBCTL_PHSDIR_Set(x) (((uint16_t) (x) << EPWM_REGS_TBCTL_PHSDIR_Pos) & EPWM_REGS_TBCTL_PHSDIR_Msk)         /*!< PHSDIR Set Value            */
#define EPWM_REGS_TBCTL_PHSDIR_Get(x) (((uint16_t) (x) & EPWM_REGS_TBCTL_PHSDIR_Msk) >> EPWM_REGS_TBCTL_PHSDIR_Pos)         /*!< PHSDIR Get Value            */


#define EPWM_REGS_TBCTL_CLKDIV_Pos    (10U)                                                                                 /*!< CLKDIV Postion   10         */ 
#define EPWM_REGS_TBCTL_CLKDIV_Msk    (0x7U << EPWM_REGS_TBCTL_CLKDIV_Pos)                                                  /*!< CLKDIV Mask      0x00001C00 */
#define EPWM_REGS_TBCTL_CLKDIV_Set(x) (((uint16_t) (x) << EPWM_REGS_TBCTL_CLKDIV_Pos) & EPWM_REGS_TBCTL_CLKDIV_Msk)         /*!< CLKDIV Set Value            */
#define EPWM_REGS_TBCTL_CLKDIV_Get(x) (((uint16_t) (x) & EPWM_REGS_TBCTL_CLKDIV_Msk) >> EPWM_REGS_TBCTL_CLKDIV_Pos)         /*!< CLKDIV Get Value            */


#define EPWM_REGS_TBCTL_HSPCLKDIV_Pos    (7U)                                                                                  /*!< HSPCLKDIV Postion   7          */ 
#define EPWM_REGS_TBCTL_HSPCLKDIV_Msk    (0x7U << EPWM_REGS_TBCTL_HSPCLKDIV_Pos)                                               /*!< HSPCLKDIV Mask      0x00000380 */
#define EPWM_REGS_TBCTL_HSPCLKDIV_Set(x) (((uint16_t) (x) << EPWM_REGS_TBCTL_HSPCLKDIV_Pos) & EPWM_REGS_TBCTL_HSPCLKDIV_Msk)   /*!< HSPCLKDIV Set Value            */
#define EPWM_REGS_TBCTL_HSPCLKDIV_Get(x) (((uint16_t) (x) & EPWM_REGS_TBCTL_HSPCLKDIV_Msk) >> EPWM_REGS_TBCTL_HSPCLKDIV_Pos)   /*!< HSPCLKDIV Get Value            */


#define EPWM_REGS_TBCTL_SWFSYNC_Pos    (6U)                                                                                  /*!< SWFSYNC Postion   6          */ 
#define EPWM_REGS_TBCTL_SWFSYNC_Msk    (0x1U << EPWM_REGS_TBCTL_SWFSYNC_Pos)                                                 /*!< SWFSYNC Mask      0x00000040 */
#define EPWM_REGS_TBCTL_SWFSYNC_Set(x) (((uint16_t) (x) << EPWM_REGS_TBCTL_SWFSYNC_Pos) & EPWM_REGS_TBCTL_SWFSYNC_Msk)       /*!< SWFSYNC Set Value            */
#define EPWM_REGS_TBCTL_SWFSYNC_Get(x) (((uint16_t) (x) & EPWM_REGS_TBCTL_SWFSYNC_Msk) >> EPWM_REGS_TBCTL_SWFSYNC_Pos)       /*!< SWFSYNC Get Value            */


#define EPWM_REGS_TBCTL_PRDLD_Pos    (3U)                                                                                  /*!< PRDLD Postion   3          */ 
#define EPWM_REGS_TBCTL_PRDLD_Msk    (0x1U << EPWM_REGS_TBCTL_PRDLD_Pos)                                                   /*!< PRDLD Mask      0x00000008 */
#define EPWM_REGS_TBCTL_PRDLD_Set(x) (((uint16_t) (x) << EPWM_REGS_TBCTL_PRDLD_Pos) & EPWM_REGS_TBCTL_PRDLD_Msk)           /*!< PRDLD Set Value            */
#define EPWM_REGS_TBCTL_PRDLD_Get(x) (((uint16_t) (x) & EPWM_REGS_TBCTL_PRDLD_Msk) >> EPWM_REGS_TBCTL_PRDLD_Pos)           /*!< PRDLD Get Value            */


#define EPWM_REGS_TBCTL_PHSEN_Pos    (2U)                                                                                  /*!< PHSEN Postion   2          */ 
#define EPWM_REGS_TBCTL_PHSEN_Msk    (0x1U << EPWM_REGS_TBCTL_PHSEN_Pos)                                                   /*!< PHSEN Mask      0x00000004 */
#define EPWM_REGS_TBCTL_PHSEN_Set(x) (((uint16_t) (x) << EPWM_REGS_TBCTL_PHSEN_Pos) & EPWM_REGS_TBCTL_PHSEN_Msk)           /*!< PHSEN Set Value            */
#define EPWM_REGS_TBCTL_PHSEN_Get(x) (((uint16_t) (x) & EPWM_REGS_TBCTL_PHSEN_Msk) >> EPWM_REGS_TBCTL_PHSEN_Pos)           /*!< PHSEN Get Value            */


#define EPWM_REGS_TBCTL_CTRMODE_Pos    (0U)                                                                                  /*!< CTRMODE Postion   0          */ 
#define EPWM_REGS_TBCTL_CTRMODE_Msk    (0x3U << EPWM_REGS_TBCTL_CTRMODE_Pos)                                                 /*!< CTRMODE Mask      0x00000003 */
#define EPWM_REGS_TBCTL_CTRMODE_Set(x) (((uint16_t) (x) << EPWM_REGS_TBCTL_CTRMODE_Pos) & EPWM_REGS_TBCTL_CTRMODE_Msk)       /*!< CTRMODE Set Value            */
#define EPWM_REGS_TBCTL_CTRMODE_Get(x) (((uint16_t) (x) & EPWM_REGS_TBCTL_CTRMODE_Msk) >> EPWM_REGS_TBCTL_CTRMODE_Pos)       /*!< CTRMODE Get Value            */


/* TBCTL2 bitfield */
#define EPWM_REGS_TBCTL2_PRDLDSYNC_Pos    (14U)                                                                                 /*!< PRDLDSYNC Postion   14         */ 
#define EPWM_REGS_TBCTL2_PRDLDSYNC_Msk    (0x3U << EPWM_REGS_TBCTL2_PRDLDSYNC_Pos)                                              /*!< PRDLDSYNC Mask      0x0000C000 */
#define EPWM_REGS_TBCTL2_PRDLDSYNC_Set(x) (((uint16_t) (x) << EPWM_REGS_TBCTL2_PRDLDSYNC_Pos) & EPWM_REGS_TBCTL2_PRDLDSYNC_Msk) /*!< PRDLDSYNC Set Value            */
#define EPWM_REGS_TBCTL2_PRDLDSYNC_Get(x) (((uint16_t) (x) & EPWM_REGS_TBCTL2_PRDLDSYNC_Msk) >> EPWM_REGS_TBCTL2_PRDLDSYNC_Pos) /*!< PRDLDSYNC Get Value            */


#define EPWM_REGS_TBCTL2_OSHTSYNC_Pos    (7U)                                                                                  /*!< OSHTSYNC Postion   7          */ 
#define EPWM_REGS_TBCTL2_OSHTSYNC_Msk    (0x1U << EPWM_REGS_TBCTL2_OSHTSYNC_Pos)                                               /*!< OSHTSYNC Mask      0x00000080 */
#define EPWM_REGS_TBCTL2_OSHTSYNC_Set(x) (((uint16_t) (x) << EPWM_REGS_TBCTL2_OSHTSYNC_Pos) & EPWM_REGS_TBCTL2_OSHTSYNC_Msk)   /*!< OSHTSYNC Set Value            */
#define EPWM_REGS_TBCTL2_OSHTSYNC_Get(x) (((uint16_t) (x) & EPWM_REGS_TBCTL2_OSHTSYNC_Msk) >> EPWM_REGS_TBCTL2_OSHTSYNC_Pos)   /*!< OSHTSYNC Get Value            */


#define EPWM_REGS_TBCTL2_OSHTSYNCMODE_Pos    (6U)                                                                                  /*!< OSHTSYNCMODE Postion   6          */ 
#define EPWM_REGS_TBCTL2_OSHTSYNCMODE_Msk    (0x1U << EPWM_REGS_TBCTL2_OSHTSYNCMODE_Pos)                                           /*!< OSHTSYNCMODE Mask      0x00000040 */
#define EPWM_REGS_TBCTL2_OSHTSYNCMODE_Set(x) (((uint16_t) (x) << EPWM_REGS_TBCTL2_OSHTSYNCMODE_Pos) & EPWM_REGS_TBCTL2_OSHTSYNCMODE_Msk) /*!< OSHTSYNCMODE Set Value            */
#define EPWM_REGS_TBCTL2_OSHTSYNCMODE_Get(x) (((uint16_t) (x) & EPWM_REGS_TBCTL2_OSHTSYNCMODE_Msk) >> EPWM_REGS_TBCTL2_OSHTSYNCMODE_Pos) /*!< OSHTSYNCMODE Get Value            */


/* EPWMSYNCINSEL bitfield */
#define EPWM_REGS_EPWMSYNCINSEL_SEL_Pos    (0U)                                                                                  /*!< SEL Postion   0          */ 
#define EPWM_REGS_EPWMSYNCINSEL_SEL_Msk    (0x1fU << EPWM_REGS_EPWMSYNCINSEL_SEL_Pos)                                            /*!< SEL Mask      0x0000001F */
#define EPWM_REGS_EPWMSYNCINSEL_SEL_Set(x) (((uint16_t) (x) << EPWM_REGS_EPWMSYNCINSEL_SEL_Pos) & EPWM_REGS_EPWMSYNCINSEL_SEL_Msk) /*!< SEL Set Value            */
#define EPWM_REGS_EPWMSYNCINSEL_SEL_Get(x) (((uint16_t) (x) & EPWM_REGS_EPWMSYNCINSEL_SEL_Msk) >> EPWM_REGS_EPWMSYNCINSEL_SEL_Pos) /*!< SEL Get Value            */


/* TBCTR bitfield */
#define EPWM_REGS_TBCTR_TBCTR_Pos    (0U)                                                                                  /*!< TBCTR Postion   0          */ 
#define EPWM_REGS_TBCTR_TBCTR_Msk    (0xffffU << EPWM_REGS_TBCTR_TBCTR_Pos)                                                /*!< TBCTR Mask      0x0000FFFF */
#define EPWM_REGS_TBCTR_TBCTR_Set(x) (((uint16_t) (x) << EPWM_REGS_TBCTR_TBCTR_Pos) & EPWM_REGS_TBCTR_TBCTR_Msk)           /*!< TBCTR Set Value            */
#define EPWM_REGS_TBCTR_TBCTR_Get(x) (((uint16_t) (x) & EPWM_REGS_TBCTR_TBCTR_Msk) >> EPWM_REGS_TBCTR_TBCTR_Pos)           /*!< TBCTR Get Value            */


/* TBSTS bitfield */
#define EPWM_REGS_TBSTS_CTRMAX_Pos    (2U)                                                                                  /*!< CTRMAX Postion   2          */ 
#define EPWM_REGS_TBSTS_CTRMAX_Msk    (0x1U << EPWM_REGS_TBSTS_CTRMAX_Pos)                                                  /*!< CTRMAX Mask      0x00000004 */
#define EPWM_REGS_TBSTS_CTRMAX_Set(x) (((uint16_t) (x) << EPWM_REGS_TBSTS_CTRMAX_Pos) & EPWM_REGS_TBSTS_CTRMAX_Msk)         /*!< CTRMAX Set Value            */
#define EPWM_REGS_TBSTS_CTRMAX_Get(x) (((uint16_t) (x) & EPWM_REGS_TBSTS_CTRMAX_Msk) >> EPWM_REGS_TBSTS_CTRMAX_Pos)         /*!< CTRMAX Get Value            */


#define EPWM_REGS_TBSTS_SYNCI_Pos    (1U)                                                                                  /*!< SYNCI Postion   1          */ 
#define EPWM_REGS_TBSTS_SYNCI_Msk    (0x1U << EPWM_REGS_TBSTS_SYNCI_Pos)                                                   /*!< SYNCI Mask      0x00000002 */
#define EPWM_REGS_TBSTS_SYNCI_Set(x) (((uint16_t) (x) << EPWM_REGS_TBSTS_SYNCI_Pos) & EPWM_REGS_TBSTS_SYNCI_Msk)           /*!< SYNCI Set Value            */
#define EPWM_REGS_TBSTS_SYNCI_Get(x) (((uint16_t) (x) & EPWM_REGS_TBSTS_SYNCI_Msk) >> EPWM_REGS_TBSTS_SYNCI_Pos)           /*!< SYNCI Get Value            */


#define EPWM_REGS_TBSTS_CTRDIR_Pos    (0U)                                                                                  /*!< CTRDIR Postion   0          */ 
#define EPWM_REGS_TBSTS_CTRDIR_Msk    (0x1U << EPWM_REGS_TBSTS_CTRDIR_Pos)                                                  /*!< CTRDIR Mask      0x00000001 */
#define EPWM_REGS_TBSTS_CTRDIR_Set(x) (((uint16_t) (x) << EPWM_REGS_TBSTS_CTRDIR_Pos) & EPWM_REGS_TBSTS_CTRDIR_Msk)         /*!< CTRDIR Set Value            */
#define EPWM_REGS_TBSTS_CTRDIR_Get(x) (((uint16_t) (x) & EPWM_REGS_TBSTS_CTRDIR_Msk) >> EPWM_REGS_TBSTS_CTRDIR_Pos)         /*!< CTRDIR Get Value            */


/* EPWMSYNCOUTEN bitfield */
#define EPWM_REGS_EPWMSYNCOUTEN_DCBEVT1EN_Pos    (6U)                                                                                  /*!< DCBEVT1EN Postion   6          */ 
#define EPWM_REGS_EPWMSYNCOUTEN_DCBEVT1EN_Msk    (0x1U << EPWM_REGS_EPWMSYNCOUTEN_DCBEVT1EN_Pos)                                       /*!< DCBEVT1EN Mask      0x00000040 */
#define EPWM_REGS_EPWMSYNCOUTEN_DCBEVT1EN_Set(x) (((uint16_t) (x) << EPWM_REGS_EPWMSYNCOUTEN_DCBEVT1EN_Pos) & EPWM_REGS_EPWMSYNCOUTEN_DCBEVT1EN_Msk) /*!< DCBEVT1EN Set Value            */
#define EPWM_REGS_EPWMSYNCOUTEN_DCBEVT1EN_Get(x) (((uint16_t) (x) & EPWM_REGS_EPWMSYNCOUTEN_DCBEVT1EN_Msk) >> EPWM_REGS_EPWMSYNCOUTEN_DCBEVT1EN_Pos) /*!< DCBEVT1EN Get Value            */


#define EPWM_REGS_EPWMSYNCOUTEN_DCAEVT1EN_Pos    (5U)                                                                                  /*!< DCAEVT1EN Postion   5          */ 
#define EPWM_REGS_EPWMSYNCOUTEN_DCAEVT1EN_Msk    (0x1U << EPWM_REGS_EPWMSYNCOUTEN_DCAEVT1EN_Pos)                                       /*!< DCAEVT1EN Mask      0x00000020 */
#define EPWM_REGS_EPWMSYNCOUTEN_DCAEVT1EN_Set(x) (((uint16_t) (x) << EPWM_REGS_EPWMSYNCOUTEN_DCAEVT1EN_Pos) & EPWM_REGS_EPWMSYNCOUTEN_DCAEVT1EN_Msk) /*!< DCAEVT1EN Set Value            */
#define EPWM_REGS_EPWMSYNCOUTEN_DCAEVT1EN_Get(x) (((uint16_t) (x) & EPWM_REGS_EPWMSYNCOUTEN_DCAEVT1EN_Msk) >> EPWM_REGS_EPWMSYNCOUTEN_DCAEVT1EN_Pos) /*!< DCAEVT1EN Get Value            */


#define EPWM_REGS_EPWMSYNCOUTEN_CMPDEN_Pos    (4U)                                                                                  /*!< CMPDEN Postion   4          */ 
#define EPWM_REGS_EPWMSYNCOUTEN_CMPDEN_Msk    (0x1U << EPWM_REGS_EPWMSYNCOUTEN_CMPDEN_Pos)                                          /*!< CMPDEN Mask      0x00000010 */
#define EPWM_REGS_EPWMSYNCOUTEN_CMPDEN_Set(x) (((uint16_t) (x) << EPWM_REGS_EPWMSYNCOUTEN_CMPDEN_Pos) & EPWM_REGS_EPWMSYNCOUTEN_CMPDEN_Msk) /*!< CMPDEN Set Value            */
#define EPWM_REGS_EPWMSYNCOUTEN_CMPDEN_Get(x) (((uint16_t) (x) & EPWM_REGS_EPWMSYNCOUTEN_CMPDEN_Msk) >> EPWM_REGS_EPWMSYNCOUTEN_CMPDEN_Pos) /*!< CMPDEN Get Value            */


#define EPWM_REGS_EPWMSYNCOUTEN_CMPCEN_Pos    (3U)                                                                                  /*!< CMPCEN Postion   3          */ 
#define EPWM_REGS_EPWMSYNCOUTEN_CMPCEN_Msk    (0x1U << EPWM_REGS_EPWMSYNCOUTEN_CMPCEN_Pos)                                          /*!< CMPCEN Mask      0x00000008 */
#define EPWM_REGS_EPWMSYNCOUTEN_CMPCEN_Set(x) (((uint16_t) (x) << EPWM_REGS_EPWMSYNCOUTEN_CMPCEN_Pos) & EPWM_REGS_EPWMSYNCOUTEN_CMPCEN_Msk) /*!< CMPCEN Set Value            */
#define EPWM_REGS_EPWMSYNCOUTEN_CMPCEN_Get(x) (((uint16_t) (x) & EPWM_REGS_EPWMSYNCOUTEN_CMPCEN_Msk) >> EPWM_REGS_EPWMSYNCOUTEN_CMPCEN_Pos) /*!< CMPCEN Get Value            */


#define EPWM_REGS_EPWMSYNCOUTEN_CMPBEN_Pos    (2U)                                                                                  /*!< CMPBEN Postion   2          */ 
#define EPWM_REGS_EPWMSYNCOUTEN_CMPBEN_Msk    (0x1U << EPWM_REGS_EPWMSYNCOUTEN_CMPBEN_Pos)                                          /*!< CMPBEN Mask      0x00000004 */
#define EPWM_REGS_EPWMSYNCOUTEN_CMPBEN_Set(x) (((uint16_t) (x) << EPWM_REGS_EPWMSYNCOUTEN_CMPBEN_Pos) & EPWM_REGS_EPWMSYNCOUTEN_CMPBEN_Msk) /*!< CMPBEN Set Value            */
#define EPWM_REGS_EPWMSYNCOUTEN_CMPBEN_Get(x) (((uint16_t) (x) & EPWM_REGS_EPWMSYNCOUTEN_CMPBEN_Msk) >> EPWM_REGS_EPWMSYNCOUTEN_CMPBEN_Pos) /*!< CMPBEN Get Value            */


#define EPWM_REGS_EPWMSYNCOUTEN_ZEROEN_Pos    (1U)                                                                                  /*!< ZEROEN Postion   1          */ 
#define EPWM_REGS_EPWMSYNCOUTEN_ZEROEN_Msk    (0x1U << EPWM_REGS_EPWMSYNCOUTEN_ZEROEN_Pos)                                          /*!< ZEROEN Mask      0x00000002 */
#define EPWM_REGS_EPWMSYNCOUTEN_ZEROEN_Set(x) (((uint16_t) (x) << EPWM_REGS_EPWMSYNCOUTEN_ZEROEN_Pos) & EPWM_REGS_EPWMSYNCOUTEN_ZEROEN_Msk) /*!< ZEROEN Set Value            */
#define EPWM_REGS_EPWMSYNCOUTEN_ZEROEN_Get(x) (((uint16_t) (x) & EPWM_REGS_EPWMSYNCOUTEN_ZEROEN_Msk) >> EPWM_REGS_EPWMSYNCOUTEN_ZEROEN_Pos) /*!< ZEROEN Get Value            */


#define EPWM_REGS_EPWMSYNCOUTEN_SWEN_Pos    (0U)                                                                                  /*!< SWEN Postion   0          */ 
#define EPWM_REGS_EPWMSYNCOUTEN_SWEN_Msk    (0x1U << EPWM_REGS_EPWMSYNCOUTEN_SWEN_Pos)                                            /*!< SWEN Mask      0x00000001 */
#define EPWM_REGS_EPWMSYNCOUTEN_SWEN_Set(x) (((uint16_t) (x) << EPWM_REGS_EPWMSYNCOUTEN_SWEN_Pos) & EPWM_REGS_EPWMSYNCOUTEN_SWEN_Msk) /*!< SWEN Set Value            */
#define EPWM_REGS_EPWMSYNCOUTEN_SWEN_Get(x) (((uint16_t) (x) & EPWM_REGS_EPWMSYNCOUTEN_SWEN_Msk) >> EPWM_REGS_EPWMSYNCOUTEN_SWEN_Pos) /*!< SWEN Get Value            */


/* TBCTL3 bitfield */
#define EPWM_REGS_TBCTL3_OSSFRCEN_Pos    (0U)                                                                                  /*!< OSSFRCEN Postion   0          */ 
#define EPWM_REGS_TBCTL3_OSSFRCEN_Msk    (0x1U << EPWM_REGS_TBCTL3_OSSFRCEN_Pos)                                               /*!< OSSFRCEN Mask      0x00000001 */
#define EPWM_REGS_TBCTL3_OSSFRCEN_Set(x) (((uint16_t) (x) << EPWM_REGS_TBCTL3_OSSFRCEN_Pos) & EPWM_REGS_TBCTL3_OSSFRCEN_Msk)   /*!< OSSFRCEN Set Value            */
#define EPWM_REGS_TBCTL3_OSSFRCEN_Get(x) (((uint16_t) (x) & EPWM_REGS_TBCTL3_OSSFRCEN_Msk) >> EPWM_REGS_TBCTL3_OSSFRCEN_Pos)   /*!< OSSFRCEN Get Value            */


/* CMPCTL bitfield */
#define EPWM_REGS_CMPCTL_LOADBSYNC_Pos    (12U)                                                                                 /*!< LOADBSYNC Postion   12         */ 
#define EPWM_REGS_CMPCTL_LOADBSYNC_Msk    (0x3U << EPWM_REGS_CMPCTL_LOADBSYNC_Pos)                                              /*!< LOADBSYNC Mask      0x00003000 */
#define EPWM_REGS_CMPCTL_LOADBSYNC_Set(x) (((uint16_t) (x) << EPWM_REGS_CMPCTL_LOADBSYNC_Pos) & EPWM_REGS_CMPCTL_LOADBSYNC_Msk) /*!< LOADBSYNC Set Value            */
#define EPWM_REGS_CMPCTL_LOADBSYNC_Get(x) (((uint16_t) (x) & EPWM_REGS_CMPCTL_LOADBSYNC_Msk) >> EPWM_REGS_CMPCTL_LOADBSYNC_Pos) /*!< LOADBSYNC Get Value            */


#define EPWM_REGS_CMPCTL_LOADASYNC_Pos    (10U)                                                                                 /*!< LOADASYNC Postion   10         */ 
#define EPWM_REGS_CMPCTL_LOADASYNC_Msk    (0x3U << EPWM_REGS_CMPCTL_LOADASYNC_Pos)                                              /*!< LOADASYNC Mask      0x00000C00 */
#define EPWM_REGS_CMPCTL_LOADASYNC_Set(x) (((uint16_t) (x) << EPWM_REGS_CMPCTL_LOADASYNC_Pos) & EPWM_REGS_CMPCTL_LOADASYNC_Msk) /*!< LOADASYNC Set Value            */
#define EPWM_REGS_CMPCTL_LOADASYNC_Get(x) (((uint16_t) (x) & EPWM_REGS_CMPCTL_LOADASYNC_Msk) >> EPWM_REGS_CMPCTL_LOADASYNC_Pos) /*!< LOADASYNC Get Value            */


#define EPWM_REGS_CMPCTL_SHDWBFULL_Pos    (9U)                                                                                  /*!< SHDWBFULL Postion   9          */ 
#define EPWM_REGS_CMPCTL_SHDWBFULL_Msk    (0x1U << EPWM_REGS_CMPCTL_SHDWBFULL_Pos)                                              /*!< SHDWBFULL Mask      0x00000200 */
#define EPWM_REGS_CMPCTL_SHDWBFULL_Set(x) (((uint16_t) (x) << EPWM_REGS_CMPCTL_SHDWBFULL_Pos) & EPWM_REGS_CMPCTL_SHDWBFULL_Msk) /*!< SHDWBFULL Set Value            */
#define EPWM_REGS_CMPCTL_SHDWBFULL_Get(x) (((uint16_t) (x) & EPWM_REGS_CMPCTL_SHDWBFULL_Msk) >> EPWM_REGS_CMPCTL_SHDWBFULL_Pos) /*!< SHDWBFULL Get Value            */


#define EPWM_REGS_CMPCTL_SHDWAFULL_Pos    (8U)                                                                                  /*!< SHDWAFULL Postion   8          */ 
#define EPWM_REGS_CMPCTL_SHDWAFULL_Msk    (0x1U << EPWM_REGS_CMPCTL_SHDWAFULL_Pos)                                              /*!< SHDWAFULL Mask      0x00000100 */
#define EPWM_REGS_CMPCTL_SHDWAFULL_Set(x) (((uint16_t) (x) << EPWM_REGS_CMPCTL_SHDWAFULL_Pos) & EPWM_REGS_CMPCTL_SHDWAFULL_Msk) /*!< SHDWAFULL Set Value            */
#define EPWM_REGS_CMPCTL_SHDWAFULL_Get(x) (((uint16_t) (x) & EPWM_REGS_CMPCTL_SHDWAFULL_Msk) >> EPWM_REGS_CMPCTL_SHDWAFULL_Pos) /*!< SHDWAFULL Get Value            */


#define EPWM_REGS_CMPCTL_SHDWBMODE_Pos    (6U)                                                                                  /*!< SHDWBMODE Postion   6          */ 
#define EPWM_REGS_CMPCTL_SHDWBMODE_Msk    (0x1U << EPWM_REGS_CMPCTL_SHDWBMODE_Pos)                                              /*!< SHDWBMODE Mask      0x00000040 */
#define EPWM_REGS_CMPCTL_SHDWBMODE_Set(x) (((uint16_t) (x) << EPWM_REGS_CMPCTL_SHDWBMODE_Pos) & EPWM_REGS_CMPCTL_SHDWBMODE_Msk) /*!< SHDWBMODE Set Value            */
#define EPWM_REGS_CMPCTL_SHDWBMODE_Get(x) (((uint16_t) (x) & EPWM_REGS_CMPCTL_SHDWBMODE_Msk) >> EPWM_REGS_CMPCTL_SHDWBMODE_Pos) /*!< SHDWBMODE Get Value            */


#define EPWM_REGS_CMPCTL_SHDWAMODE_Pos    (4U)                                                                                  /*!< SHDWAMODE Postion   4          */ 
#define EPWM_REGS_CMPCTL_SHDWAMODE_Msk    (0x1U << EPWM_REGS_CMPCTL_SHDWAMODE_Pos)                                              /*!< SHDWAMODE Mask      0x00000010 */
#define EPWM_REGS_CMPCTL_SHDWAMODE_Set(x) (((uint16_t) (x) << EPWM_REGS_CMPCTL_SHDWAMODE_Pos) & EPWM_REGS_CMPCTL_SHDWAMODE_Msk) /*!< SHDWAMODE Set Value            */
#define EPWM_REGS_CMPCTL_SHDWAMODE_Get(x) (((uint16_t) (x) & EPWM_REGS_CMPCTL_SHDWAMODE_Msk) >> EPWM_REGS_CMPCTL_SHDWAMODE_Pos) /*!< SHDWAMODE Get Value            */


#define EPWM_REGS_CMPCTL_LOADBMODE_Pos    (2U)                                                                                  /*!< LOADBMODE Postion   2          */ 
#define EPWM_REGS_CMPCTL_LOADBMODE_Msk    (0x3U << EPWM_REGS_CMPCTL_LOADBMODE_Pos)                                              /*!< LOADBMODE Mask      0x0000000C */
#define EPWM_REGS_CMPCTL_LOADBMODE_Set(x) (((uint16_t) (x) << EPWM_REGS_CMPCTL_LOADBMODE_Pos) & EPWM_REGS_CMPCTL_LOADBMODE_Msk) /*!< LOADBMODE Set Value            */
#define EPWM_REGS_CMPCTL_LOADBMODE_Get(x) (((uint16_t) (x) & EPWM_REGS_CMPCTL_LOADBMODE_Msk) >> EPWM_REGS_CMPCTL_LOADBMODE_Pos) /*!< LOADBMODE Get Value            */


#define EPWM_REGS_CMPCTL_LOADAMODE_Pos    (0U)                                                                                  /*!< LOADAMODE Postion   0          */ 
#define EPWM_REGS_CMPCTL_LOADAMODE_Msk    (0x3U << EPWM_REGS_CMPCTL_LOADAMODE_Pos)                                              /*!< LOADAMODE Mask      0x00000003 */
#define EPWM_REGS_CMPCTL_LOADAMODE_Set(x) (((uint16_t) (x) << EPWM_REGS_CMPCTL_LOADAMODE_Pos) & EPWM_REGS_CMPCTL_LOADAMODE_Msk) /*!< LOADAMODE Set Value            */
#define EPWM_REGS_CMPCTL_LOADAMODE_Get(x) (((uint16_t) (x) & EPWM_REGS_CMPCTL_LOADAMODE_Msk) >> EPWM_REGS_CMPCTL_LOADAMODE_Pos) /*!< LOADAMODE Get Value            */


/* CMPCTL2 bitfield */
#define EPWM_REGS_CMPCTL2_LOADDSYNC_Pos    (12U)                                                                                 /*!< LOADDSYNC Postion   12         */ 
#define EPWM_REGS_CMPCTL2_LOADDSYNC_Msk    (0x3U << EPWM_REGS_CMPCTL2_LOADDSYNC_Pos)                                             /*!< LOADDSYNC Mask      0x00003000 */
#define EPWM_REGS_CMPCTL2_LOADDSYNC_Set(x) (((uint16_t) (x) << EPWM_REGS_CMPCTL2_LOADDSYNC_Pos) & EPWM_REGS_CMPCTL2_LOADDSYNC_Msk) /*!< LOADDSYNC Set Value            */
#define EPWM_REGS_CMPCTL2_LOADDSYNC_Get(x) (((uint16_t) (x) & EPWM_REGS_CMPCTL2_LOADDSYNC_Msk) >> EPWM_REGS_CMPCTL2_LOADDSYNC_Pos) /*!< LOADDSYNC Get Value            */


#define EPWM_REGS_CMPCTL2_LOADCSYNC_Pos    (10U)                                                                                 /*!< LOADCSYNC Postion   10         */ 
#define EPWM_REGS_CMPCTL2_LOADCSYNC_Msk    (0x3U << EPWM_REGS_CMPCTL2_LOADCSYNC_Pos)                                             /*!< LOADCSYNC Mask      0x00000C00 */
#define EPWM_REGS_CMPCTL2_LOADCSYNC_Set(x) (((uint16_t) (x) << EPWM_REGS_CMPCTL2_LOADCSYNC_Pos) & EPWM_REGS_CMPCTL2_LOADCSYNC_Msk) /*!< LOADCSYNC Set Value            */
#define EPWM_REGS_CMPCTL2_LOADCSYNC_Get(x) (((uint16_t) (x) & EPWM_REGS_CMPCTL2_LOADCSYNC_Msk) >> EPWM_REGS_CMPCTL2_LOADCSYNC_Pos) /*!< LOADCSYNC Get Value            */


#define EPWM_REGS_CMPCTL2_SHDWDMODE_Pos    (6U)                                                                                  /*!< SHDWDMODE Postion   6          */ 
#define EPWM_REGS_CMPCTL2_SHDWDMODE_Msk    (0x1U << EPWM_REGS_CMPCTL2_SHDWDMODE_Pos)                                             /*!< SHDWDMODE Mask      0x00000040 */
#define EPWM_REGS_CMPCTL2_SHDWDMODE_Set(x) (((uint16_t) (x) << EPWM_REGS_CMPCTL2_SHDWDMODE_Pos) & EPWM_REGS_CMPCTL2_SHDWDMODE_Msk) /*!< SHDWDMODE Set Value            */
#define EPWM_REGS_CMPCTL2_SHDWDMODE_Get(x) (((uint16_t) (x) & EPWM_REGS_CMPCTL2_SHDWDMODE_Msk) >> EPWM_REGS_CMPCTL2_SHDWDMODE_Pos) /*!< SHDWDMODE Get Value            */


#define EPWM_REGS_CMPCTL2_SHDWCMODE_Pos    (4U)                                                                                  /*!< SHDWCMODE Postion   4          */ 
#define EPWM_REGS_CMPCTL2_SHDWCMODE_Msk    (0x1U << EPWM_REGS_CMPCTL2_SHDWCMODE_Pos)                                             /*!< SHDWCMODE Mask      0x00000010 */
#define EPWM_REGS_CMPCTL2_SHDWCMODE_Set(x) (((uint16_t) (x) << EPWM_REGS_CMPCTL2_SHDWCMODE_Pos) & EPWM_REGS_CMPCTL2_SHDWCMODE_Msk) /*!< SHDWCMODE Set Value            */
#define EPWM_REGS_CMPCTL2_SHDWCMODE_Get(x) (((uint16_t) (x) & EPWM_REGS_CMPCTL2_SHDWCMODE_Msk) >> EPWM_REGS_CMPCTL2_SHDWCMODE_Pos) /*!< SHDWCMODE Get Value            */


#define EPWM_REGS_CMPCTL2_LOADDMODE_Pos    (2U)                                                                                  /*!< LOADDMODE Postion   2          */ 
#define EPWM_REGS_CMPCTL2_LOADDMODE_Msk    (0x3U << EPWM_REGS_CMPCTL2_LOADDMODE_Pos)                                             /*!< LOADDMODE Mask      0x0000000C */
#define EPWM_REGS_CMPCTL2_LOADDMODE_Set(x) (((uint16_t) (x) << EPWM_REGS_CMPCTL2_LOADDMODE_Pos) & EPWM_REGS_CMPCTL2_LOADDMODE_Msk) /*!< LOADDMODE Set Value            */
#define EPWM_REGS_CMPCTL2_LOADDMODE_Get(x) (((uint16_t) (x) & EPWM_REGS_CMPCTL2_LOADDMODE_Msk) >> EPWM_REGS_CMPCTL2_LOADDMODE_Pos) /*!< LOADDMODE Get Value            */


#define EPWM_REGS_CMPCTL2_LOADCMODE_Pos    (0U)                                                                                  /*!< LOADCMODE Postion   0          */ 
#define EPWM_REGS_CMPCTL2_LOADCMODE_Msk    (0x3U << EPWM_REGS_CMPCTL2_LOADCMODE_Pos)                                             /*!< LOADCMODE Mask      0x00000003 */
#define EPWM_REGS_CMPCTL2_LOADCMODE_Set(x) (((uint16_t) (x) << EPWM_REGS_CMPCTL2_LOADCMODE_Pos) & EPWM_REGS_CMPCTL2_LOADCMODE_Msk) /*!< LOADCMODE Set Value            */
#define EPWM_REGS_CMPCTL2_LOADCMODE_Get(x) (((uint16_t) (x) & EPWM_REGS_CMPCTL2_LOADCMODE_Msk) >> EPWM_REGS_CMPCTL2_LOADCMODE_Pos) /*!< LOADCMODE Get Value            */


/* DBCTL bitfield */
#define EPWM_REGS_DBCTL_HALFCYCLE_Pos    (15U)                                                                                 /*!< HALFCYCLE Postion   15         */ 
#define EPWM_REGS_DBCTL_HALFCYCLE_Msk    (0x1U << EPWM_REGS_DBCTL_HALFCYCLE_Pos)                                               /*!< HALFCYCLE Mask      0x00008000 */
#define EPWM_REGS_DBCTL_HALFCYCLE_Set(x) (((uint16_t) (x) << EPWM_REGS_DBCTL_HALFCYCLE_Pos) & EPWM_REGS_DBCTL_HALFCYCLE_Msk)   /*!< HALFCYCLE Set Value            */
#define EPWM_REGS_DBCTL_HALFCYCLE_Get(x) (((uint16_t) (x) & EPWM_REGS_DBCTL_HALFCYCLE_Msk) >> EPWM_REGS_DBCTL_HALFCYCLE_Pos)   /*!< HALFCYCLE Get Value            */


#define EPWM_REGS_DBCTL_DEDB_MODE_Pos    (14U)                                                                                 /*!< DEDB_MODE Postion   14         */ 
#define EPWM_REGS_DBCTL_DEDB_MODE_Msk    (0x1U << EPWM_REGS_DBCTL_DEDB_MODE_Pos)                                               /*!< DEDB_MODE Mask      0x00004000 */
#define EPWM_REGS_DBCTL_DEDB_MODE_Set(x) (((uint16_t) (x) << EPWM_REGS_DBCTL_DEDB_MODE_Pos) & EPWM_REGS_DBCTL_DEDB_MODE_Msk)   /*!< DEDB_MODE Set Value            */
#define EPWM_REGS_DBCTL_DEDB_MODE_Get(x) (((uint16_t) (x) & EPWM_REGS_DBCTL_DEDB_MODE_Msk) >> EPWM_REGS_DBCTL_DEDB_MODE_Pos)   /*!< DEDB_MODE Get Value            */


#define EPWM_REGS_DBCTL_OUTSWAP_Pos    (12U)                                                                                 /*!< OUTSWAP Postion   12         */ 
#define EPWM_REGS_DBCTL_OUTSWAP_Msk    (0x3U << EPWM_REGS_DBCTL_OUTSWAP_Pos)                                                 /*!< OUTSWAP Mask      0x00003000 */
#define EPWM_REGS_DBCTL_OUTSWAP_Set(x) (((uint16_t) (x) << EPWM_REGS_DBCTL_OUTSWAP_Pos) & EPWM_REGS_DBCTL_OUTSWAP_Msk)       /*!< OUTSWAP Set Value            */
#define EPWM_REGS_DBCTL_OUTSWAP_Get(x) (((uint16_t) (x) & EPWM_REGS_DBCTL_OUTSWAP_Msk) >> EPWM_REGS_DBCTL_OUTSWAP_Pos)       /*!< OUTSWAP Get Value            */


#define EPWM_REGS_DBCTL_SHDWDBFEDMODE_Pos    (11U)                                                                                 /*!< SHDWDBFEDMODE Postion   11         */ 
#define EPWM_REGS_DBCTL_SHDWDBFEDMODE_Msk    (0x1U << EPWM_REGS_DBCTL_SHDWDBFEDMODE_Pos)                                           /*!< SHDWDBFEDMODE Mask      0x00000800 */
#define EPWM_REGS_DBCTL_SHDWDBFEDMODE_Set(x) (((uint16_t) (x) << EPWM_REGS_DBCTL_SHDWDBFEDMODE_Pos) & EPWM_REGS_DBCTL_SHDWDBFEDMODE_Msk) /*!< SHDWDBFEDMODE Set Value            */
#define EPWM_REGS_DBCTL_SHDWDBFEDMODE_Get(x) (((uint16_t) (x) & EPWM_REGS_DBCTL_SHDWDBFEDMODE_Msk) >> EPWM_REGS_DBCTL_SHDWDBFEDMODE_Pos) /*!< SHDWDBFEDMODE Get Value            */


#define EPWM_REGS_DBCTL_SHDWDBREDMODE_Pos    (10U)                                                                                 /*!< SHDWDBREDMODE Postion   10         */ 
#define EPWM_REGS_DBCTL_SHDWDBREDMODE_Msk    (0x1U << EPWM_REGS_DBCTL_SHDWDBREDMODE_Pos)                                           /*!< SHDWDBREDMODE Mask      0x00000400 */
#define EPWM_REGS_DBCTL_SHDWDBREDMODE_Set(x) (((uint16_t) (x) << EPWM_REGS_DBCTL_SHDWDBREDMODE_Pos) & EPWM_REGS_DBCTL_SHDWDBREDMODE_Msk) /*!< SHDWDBREDMODE Set Value            */
#define EPWM_REGS_DBCTL_SHDWDBREDMODE_Get(x) (((uint16_t) (x) & EPWM_REGS_DBCTL_SHDWDBREDMODE_Msk) >> EPWM_REGS_DBCTL_SHDWDBREDMODE_Pos) /*!< SHDWDBREDMODE Get Value            */


#define EPWM_REGS_DBCTL_LOADFEDMODE_Pos    (8U)                                                                                  /*!< LOADFEDMODE Postion   8          */ 
#define EPWM_REGS_DBCTL_LOADFEDMODE_Msk    (0x3U << EPWM_REGS_DBCTL_LOADFEDMODE_Pos)                                             /*!< LOADFEDMODE Mask      0x00000300 */
#define EPWM_REGS_DBCTL_LOADFEDMODE_Set(x) (((uint16_t) (x) << EPWM_REGS_DBCTL_LOADFEDMODE_Pos) & EPWM_REGS_DBCTL_LOADFEDMODE_Msk) /*!< LOADFEDMODE Set Value            */
#define EPWM_REGS_DBCTL_LOADFEDMODE_Get(x) (((uint16_t) (x) & EPWM_REGS_DBCTL_LOADFEDMODE_Msk) >> EPWM_REGS_DBCTL_LOADFEDMODE_Pos) /*!< LOADFEDMODE Get Value            */


#define EPWM_REGS_DBCTL_LOADREDMODE_Pos    (6U)                                                                                  /*!< LOADREDMODE Postion   6          */ 
#define EPWM_REGS_DBCTL_LOADREDMODE_Msk    (0x3U << EPWM_REGS_DBCTL_LOADREDMODE_Pos)                                             /*!< LOADREDMODE Mask      0x000000C0 */
#define EPWM_REGS_DBCTL_LOADREDMODE_Set(x) (((uint16_t) (x) << EPWM_REGS_DBCTL_LOADREDMODE_Pos) & EPWM_REGS_DBCTL_LOADREDMODE_Msk) /*!< LOADREDMODE Set Value            */
#define EPWM_REGS_DBCTL_LOADREDMODE_Get(x) (((uint16_t) (x) & EPWM_REGS_DBCTL_LOADREDMODE_Msk) >> EPWM_REGS_DBCTL_LOADREDMODE_Pos) /*!< LOADREDMODE Get Value            */


#define EPWM_REGS_DBCTL_IN_MODE_Pos    (4U)                                                                                  /*!< IN_MODE Postion   4          */ 
#define EPWM_REGS_DBCTL_IN_MODE_Msk    (0x3U << EPWM_REGS_DBCTL_IN_MODE_Pos)                                                 /*!< IN_MODE Mask      0x00000030 */
#define EPWM_REGS_DBCTL_IN_MODE_Set(x) (((uint16_t) (x) << EPWM_REGS_DBCTL_IN_MODE_Pos) & EPWM_REGS_DBCTL_IN_MODE_Msk)       /*!< IN_MODE Set Value            */
#define EPWM_REGS_DBCTL_IN_MODE_Get(x) (((uint16_t) (x) & EPWM_REGS_DBCTL_IN_MODE_Msk) >> EPWM_REGS_DBCTL_IN_MODE_Pos)       /*!< IN_MODE Get Value            */


#define EPWM_REGS_DBCTL_POLSEL_Pos    (2U)                                                                                  /*!< POLSEL Postion   2          */ 
#define EPWM_REGS_DBCTL_POLSEL_Msk    (0x3U << EPWM_REGS_DBCTL_POLSEL_Pos)                                                  /*!< POLSEL Mask      0x0000000C */
#define EPWM_REGS_DBCTL_POLSEL_Set(x) (((uint16_t) (x) << EPWM_REGS_DBCTL_POLSEL_Pos) & EPWM_REGS_DBCTL_POLSEL_Msk)         /*!< POLSEL Set Value            */
#define EPWM_REGS_DBCTL_POLSEL_Get(x) (((uint16_t) (x) & EPWM_REGS_DBCTL_POLSEL_Msk) >> EPWM_REGS_DBCTL_POLSEL_Pos)         /*!< POLSEL Get Value            */


#define EPWM_REGS_DBCTL_OUT_MODE_Pos    (0U)                                                                                  /*!< OUT_MODE Postion   0          */ 
#define EPWM_REGS_DBCTL_OUT_MODE_Msk    (0x3U << EPWM_REGS_DBCTL_OUT_MODE_Pos)                                                /*!< OUT_MODE Mask      0x00000003 */
#define EPWM_REGS_DBCTL_OUT_MODE_Set(x) (((uint16_t) (x) << EPWM_REGS_DBCTL_OUT_MODE_Pos) & EPWM_REGS_DBCTL_OUT_MODE_Msk)     /*!< OUT_MODE Set Value            */
#define EPWM_REGS_DBCTL_OUT_MODE_Get(x) (((uint16_t) (x) & EPWM_REGS_DBCTL_OUT_MODE_Msk) >> EPWM_REGS_DBCTL_OUT_MODE_Pos)     /*!< OUT_MODE Get Value            */


/* DBCTL2 bitfield */
#define EPWM_REGS_DBCTL2_SHDWDBCTLMODE_Pos    (2U)                                                                                  /*!< SHDWDBCTLMODE Postion   2          */ 
#define EPWM_REGS_DBCTL2_SHDWDBCTLMODE_Msk    (0x1U << EPWM_REGS_DBCTL2_SHDWDBCTLMODE_Pos)                                          /*!< SHDWDBCTLMODE Mask      0x00000004 */
#define EPWM_REGS_DBCTL2_SHDWDBCTLMODE_Set(x) (((uint16_t) (x) << EPWM_REGS_DBCTL2_SHDWDBCTLMODE_Pos) & EPWM_REGS_DBCTL2_SHDWDBCTLMODE_Msk) /*!< SHDWDBCTLMODE Set Value            */
#define EPWM_REGS_DBCTL2_SHDWDBCTLMODE_Get(x) (((uint16_t) (x) & EPWM_REGS_DBCTL2_SHDWDBCTLMODE_Msk) >> EPWM_REGS_DBCTL2_SHDWDBCTLMODE_Pos) /*!< SHDWDBCTLMODE Get Value            */


#define EPWM_REGS_DBCTL2_LOADDBCTLMODE_Pos    (0U)                                                                                  /*!< LOADDBCTLMODE Postion   0          */ 
#define EPWM_REGS_DBCTL2_LOADDBCTLMODE_Msk    (0x3U << EPWM_REGS_DBCTL2_LOADDBCTLMODE_Pos)                                          /*!< LOADDBCTLMODE Mask      0x00000003 */
#define EPWM_REGS_DBCTL2_LOADDBCTLMODE_Set(x) (((uint16_t) (x) << EPWM_REGS_DBCTL2_LOADDBCTLMODE_Pos) & EPWM_REGS_DBCTL2_LOADDBCTLMODE_Msk) /*!< LOADDBCTLMODE Set Value            */
#define EPWM_REGS_DBCTL2_LOADDBCTLMODE_Get(x) (((uint16_t) (x) & EPWM_REGS_DBCTL2_LOADDBCTLMODE_Msk) >> EPWM_REGS_DBCTL2_LOADDBCTLMODE_Pos) /*!< LOADDBCTLMODE Get Value            */


/* AQCTL bitfield */
#define EPWM_REGS_AQCTL_LDAQBSYNC_Pos    (10U)                                                                                 /*!< LDAQBSYNC Postion   10         */ 
#define EPWM_REGS_AQCTL_LDAQBSYNC_Msk    (0x3U << EPWM_REGS_AQCTL_LDAQBSYNC_Pos)                                               /*!< LDAQBSYNC Mask      0x00000C00 */
#define EPWM_REGS_AQCTL_LDAQBSYNC_Set(x) (((uint16_t) (x) << EPWM_REGS_AQCTL_LDAQBSYNC_Pos) & EPWM_REGS_AQCTL_LDAQBSYNC_Msk)   /*!< LDAQBSYNC Set Value            */
#define EPWM_REGS_AQCTL_LDAQBSYNC_Get(x) (((uint16_t) (x) & EPWM_REGS_AQCTL_LDAQBSYNC_Msk) >> EPWM_REGS_AQCTL_LDAQBSYNC_Pos)   /*!< LDAQBSYNC Get Value            */


#define EPWM_REGS_AQCTL_LDAQASYNC_Pos    (8U)                                                                                  /*!< LDAQASYNC Postion   8          */ 
#define EPWM_REGS_AQCTL_LDAQASYNC_Msk    (0x3U << EPWM_REGS_AQCTL_LDAQASYNC_Pos)                                               /*!< LDAQASYNC Mask      0x00000300 */
#define EPWM_REGS_AQCTL_LDAQASYNC_Set(x) (((uint16_t) (x) << EPWM_REGS_AQCTL_LDAQASYNC_Pos) & EPWM_REGS_AQCTL_LDAQASYNC_Msk)   /*!< LDAQASYNC Set Value            */
#define EPWM_REGS_AQCTL_LDAQASYNC_Get(x) (((uint16_t) (x) & EPWM_REGS_AQCTL_LDAQASYNC_Msk) >> EPWM_REGS_AQCTL_LDAQASYNC_Pos)   /*!< LDAQASYNC Get Value            */


#define EPWM_REGS_AQCTL_SHDWAQBMODE_Pos    (6U)                                                                                  /*!< SHDWAQBMODE Postion   6          */ 
#define EPWM_REGS_AQCTL_SHDWAQBMODE_Msk    (0x1U << EPWM_REGS_AQCTL_SHDWAQBMODE_Pos)                                             /*!< SHDWAQBMODE Mask      0x00000040 */
#define EPWM_REGS_AQCTL_SHDWAQBMODE_Set(x) (((uint16_t) (x) << EPWM_REGS_AQCTL_SHDWAQBMODE_Pos) & EPWM_REGS_AQCTL_SHDWAQBMODE_Msk) /*!< SHDWAQBMODE Set Value            */
#define EPWM_REGS_AQCTL_SHDWAQBMODE_Get(x) (((uint16_t) (x) & EPWM_REGS_AQCTL_SHDWAQBMODE_Msk) >> EPWM_REGS_AQCTL_SHDWAQBMODE_Pos) /*!< SHDWAQBMODE Get Value            */


#define EPWM_REGS_AQCTL_SHDWAQAMODE_Pos    (4U)                                                                                  /*!< SHDWAQAMODE Postion   4          */ 
#define EPWM_REGS_AQCTL_SHDWAQAMODE_Msk    (0x1U << EPWM_REGS_AQCTL_SHDWAQAMODE_Pos)                                             /*!< SHDWAQAMODE Mask      0x00000010 */
#define EPWM_REGS_AQCTL_SHDWAQAMODE_Set(x) (((uint16_t) (x) << EPWM_REGS_AQCTL_SHDWAQAMODE_Pos) & EPWM_REGS_AQCTL_SHDWAQAMODE_Msk) /*!< SHDWAQAMODE Set Value            */
#define EPWM_REGS_AQCTL_SHDWAQAMODE_Get(x) (((uint16_t) (x) & EPWM_REGS_AQCTL_SHDWAQAMODE_Msk) >> EPWM_REGS_AQCTL_SHDWAQAMODE_Pos) /*!< SHDWAQAMODE Get Value            */


#define EPWM_REGS_AQCTL_LDAQBMODE_Pos    (2U)                                                                                  /*!< LDAQBMODE Postion   2          */ 
#define EPWM_REGS_AQCTL_LDAQBMODE_Msk    (0x3U << EPWM_REGS_AQCTL_LDAQBMODE_Pos)                                               /*!< LDAQBMODE Mask      0x0000000C */
#define EPWM_REGS_AQCTL_LDAQBMODE_Set(x) (((uint16_t) (x) << EPWM_REGS_AQCTL_LDAQBMODE_Pos) & EPWM_REGS_AQCTL_LDAQBMODE_Msk)   /*!< LDAQBMODE Set Value            */
#define EPWM_REGS_AQCTL_LDAQBMODE_Get(x) (((uint16_t) (x) & EPWM_REGS_AQCTL_LDAQBMODE_Msk) >> EPWM_REGS_AQCTL_LDAQBMODE_Pos)   /*!< LDAQBMODE Get Value            */


#define EPWM_REGS_AQCTL_LDAQAMODE_Pos    (0U)                                                                                  /*!< LDAQAMODE Postion   0          */ 
#define EPWM_REGS_AQCTL_LDAQAMODE_Msk    (0x3U << EPWM_REGS_AQCTL_LDAQAMODE_Pos)                                               /*!< LDAQAMODE Mask      0x00000003 */
#define EPWM_REGS_AQCTL_LDAQAMODE_Set(x) (((uint16_t) (x) << EPWM_REGS_AQCTL_LDAQAMODE_Pos) & EPWM_REGS_AQCTL_LDAQAMODE_Msk)   /*!< LDAQAMODE Set Value            */
#define EPWM_REGS_AQCTL_LDAQAMODE_Get(x) (((uint16_t) (x) & EPWM_REGS_AQCTL_LDAQAMODE_Msk) >> EPWM_REGS_AQCTL_LDAQAMODE_Pos)   /*!< LDAQAMODE Get Value            */


/* AQTSRCSEL bitfield */
#define EPWM_REGS_AQTSRCSEL_T2SEL_Pos    (4U)                                                                                  /*!< T2SEL Postion   4          */ 
#define EPWM_REGS_AQTSRCSEL_T2SEL_Msk    (0xfU << EPWM_REGS_AQTSRCSEL_T2SEL_Pos)                                               /*!< T2SEL Mask      0x000000F0 */
#define EPWM_REGS_AQTSRCSEL_T2SEL_Set(x) (((uint16_t) (x) << EPWM_REGS_AQTSRCSEL_T2SEL_Pos) & EPWM_REGS_AQTSRCSEL_T2SEL_Msk)   /*!< T2SEL Set Value            */
#define EPWM_REGS_AQTSRCSEL_T2SEL_Get(x) (((uint16_t) (x) & EPWM_REGS_AQTSRCSEL_T2SEL_Msk) >> EPWM_REGS_AQTSRCSEL_T2SEL_Pos)   /*!< T2SEL Get Value            */


#define EPWM_REGS_AQTSRCSEL_T1SEL_Pos    (0U)                                                                                  /*!< T1SEL Postion   0          */ 
#define EPWM_REGS_AQTSRCSEL_T1SEL_Msk    (0xfU << EPWM_REGS_AQTSRCSEL_T1SEL_Pos)                                               /*!< T1SEL Mask      0x0000000F */
#define EPWM_REGS_AQTSRCSEL_T1SEL_Set(x) (((uint16_t) (x) << EPWM_REGS_AQTSRCSEL_T1SEL_Pos) & EPWM_REGS_AQTSRCSEL_T1SEL_Msk)   /*!< T1SEL Set Value            */
#define EPWM_REGS_AQTSRCSEL_T1SEL_Get(x) (((uint16_t) (x) & EPWM_REGS_AQTSRCSEL_T1SEL_Msk) >> EPWM_REGS_AQTSRCSEL_T1SEL_Pos)   /*!< T1SEL Get Value            */


/* PCCTL bitfield */
#define EPWM_REGS_PCCTL_CHPMODE_Pos    (11U)                                                                                 /*!< CHPMODE Postion   11         */ 
#define EPWM_REGS_PCCTL_CHPMODE_Msk    (0x1U << EPWM_REGS_PCCTL_CHPMODE_Pos)                                                 /*!< CHPMODE Mask      0x00000800 */
#define EPWM_REGS_PCCTL_CHPMODE_Set(x) (((uint32_t) (x) << EPWM_REGS_PCCTL_CHPMODE_Pos) & EPWM_REGS_PCCTL_CHPMODE_Msk)       /*!< CHPMODE Set Value            */
#define EPWM_REGS_PCCTL_CHPMODE_Get(x) (((uint32_t) (x) & EPWM_REGS_PCCTL_CHPMODE_Msk) >> EPWM_REGS_PCCTL_CHPMODE_Pos)       /*!< CHPMODE Get Value            */


#define EPWM_REGS_PCCTL_CHPDUTY_Pos    (8U)                                                                                  /*!< CHPDUTY Postion   8          */ 
#define EPWM_REGS_PCCTL_CHPDUTY_Msk    (0x7U << EPWM_REGS_PCCTL_CHPDUTY_Pos)                                                 /*!< CHPDUTY Mask      0x00000700 */
#define EPWM_REGS_PCCTL_CHPDUTY_Set(x) (((uint32_t) (x) << EPWM_REGS_PCCTL_CHPDUTY_Pos) & EPWM_REGS_PCCTL_CHPDUTY_Msk)       /*!< CHPDUTY Set Value            */
#define EPWM_REGS_PCCTL_CHPDUTY_Get(x) (((uint32_t) (x) & EPWM_REGS_PCCTL_CHPDUTY_Msk) >> EPWM_REGS_PCCTL_CHPDUTY_Pos)       /*!< CHPDUTY Get Value            */


#define EPWM_REGS_PCCTL_CHPFREQ_Pos    (5U)                                                                                  /*!< CHPFREQ Postion   5          */ 
#define EPWM_REGS_PCCTL_CHPFREQ_Msk    (0x7U << EPWM_REGS_PCCTL_CHPFREQ_Pos)                                                 /*!< CHPFREQ Mask      0x000000E0 */
#define EPWM_REGS_PCCTL_CHPFREQ_Set(x) (((uint32_t) (x) << EPWM_REGS_PCCTL_CHPFREQ_Pos) & EPWM_REGS_PCCTL_CHPFREQ_Msk)       /*!< CHPFREQ Set Value            */
#define EPWM_REGS_PCCTL_CHPFREQ_Get(x) (((uint32_t) (x) & EPWM_REGS_PCCTL_CHPFREQ_Msk) >> EPWM_REGS_PCCTL_CHPFREQ_Pos)       /*!< CHPFREQ Get Value            */


#define EPWM_REGS_PCCTL_OSHTWTH_Pos    (1U)                                                                                  /*!< OSHTWTH Postion   1          */ 
#define EPWM_REGS_PCCTL_OSHTWTH_Msk    (0xfU << EPWM_REGS_PCCTL_OSHTWTH_Pos)                                                 /*!< OSHTWTH Mask      0x0000001E */
#define EPWM_REGS_PCCTL_OSHTWTH_Set(x) (((uint32_t) (x) << EPWM_REGS_PCCTL_OSHTWTH_Pos) & EPWM_REGS_PCCTL_OSHTWTH_Msk)       /*!< OSHTWTH Set Value            */
#define EPWM_REGS_PCCTL_OSHTWTH_Get(x) (((uint32_t) (x) & EPWM_REGS_PCCTL_OSHTWTH_Msk) >> EPWM_REGS_PCCTL_OSHTWTH_Pos)       /*!< OSHTWTH Get Value            */


#define EPWM_REGS_PCCTL_CHPEN_Pos    (0U)                                                                                  /*!< CHPEN Postion   0          */ 
#define EPWM_REGS_PCCTL_CHPEN_Msk    (0x1U << EPWM_REGS_PCCTL_CHPEN_Pos)                                                   /*!< CHPEN Mask      0x00000001 */
#define EPWM_REGS_PCCTL_CHPEN_Set(x) (((uint32_t) (x) << EPWM_REGS_PCCTL_CHPEN_Pos) & EPWM_REGS_PCCTL_CHPEN_Msk)           /*!< CHPEN Set Value            */
#define EPWM_REGS_PCCTL_CHPEN_Get(x) (((uint32_t) (x) & EPWM_REGS_PCCTL_CHPEN_Msk) >> EPWM_REGS_PCCTL_CHPEN_Pos)           /*!< CHPEN Get Value            */


/* VCAPCTL bitfield */
#define EPWM_REGS_VCAPCTL_EDGEFILTDLYSEL_Pos    (10U)                                                                                 /*!< EDGEFILTDLYSEL Postion   10         */ 
#define EPWM_REGS_VCAPCTL_EDGEFILTDLYSEL_Msk    (0x1U << EPWM_REGS_VCAPCTL_EDGEFILTDLYSEL_Pos)                                        /*!< EDGEFILTDLYSEL Mask      0x00000400 */
#define EPWM_REGS_VCAPCTL_EDGEFILTDLYSEL_Set(x) (((uint16_t) (x) << EPWM_REGS_VCAPCTL_EDGEFILTDLYSEL_Pos) & EPWM_REGS_VCAPCTL_EDGEFILTDLYSEL_Msk) /*!< EDGEFILTDLYSEL Set Value            */
#define EPWM_REGS_VCAPCTL_EDGEFILTDLYSEL_Get(x) (((uint16_t) (x) & EPWM_REGS_VCAPCTL_EDGEFILTDLYSEL_Msk) >> EPWM_REGS_VCAPCTL_EDGEFILTDLYSEL_Pos) /*!< EDGEFILTDLYSEL Get Value            */


#define EPWM_REGS_VCAPCTL_VDELATDIV_Pos    (7U)                                                                                  /*!< VDELATDIV Postion   7          */ 
#define EPWM_REGS_VCAPCTL_VDELATDIV_Msk    (0x7U << EPWM_REGS_VCAPCTL_VDELATDIV_Pos)                                             /*!< VDELATDIV Mask      0x00000380 */
#define EPWM_REGS_VCAPCTL_VDELATDIV_Set(x) (((uint16_t) (x) << EPWM_REGS_VCAPCTL_VDELATDIV_Pos) & EPWM_REGS_VCAPCTL_VDELATDIV_Msk) /*!< VDELATDIV Set Value            */
#define EPWM_REGS_VCAPCTL_VDELATDIV_Get(x) (((uint16_t) (x) & EPWM_REGS_VCAPCTL_VDELATDIV_Msk) >> EPWM_REGS_VCAPCTL_VDELATDIV_Pos) /*!< VDELATDIV Get Value            */


#define EPWM_REGS_VCAPCTL_TRIGSEL_Pos    (2U)                                                                                  /*!< TRIGSEL Postion   2          */ 
#define EPWM_REGS_VCAPCTL_TRIGSEL_Msk    (0x7U << EPWM_REGS_VCAPCTL_TRIGSEL_Pos)                                               /*!< TRIGSEL Mask      0x0000001C */
#define EPWM_REGS_VCAPCTL_TRIGSEL_Set(x) (((uint16_t) (x) << EPWM_REGS_VCAPCTL_TRIGSEL_Pos) & EPWM_REGS_VCAPCTL_TRIGSEL_Msk)   /*!< TRIGSEL Set Value            */
#define EPWM_REGS_VCAPCTL_TRIGSEL_Get(x) (((uint16_t) (x) & EPWM_REGS_VCAPCTL_TRIGSEL_Msk) >> EPWM_REGS_VCAPCTL_TRIGSEL_Pos)   /*!< TRIGSEL Get Value            */


#define EPWM_REGS_VCAPCTL_VCAPSTART_Pos    (1U)                                                                                  /*!< VCAPSTART Postion   1          */ 
#define EPWM_REGS_VCAPCTL_VCAPSTART_Msk    (0x1U << EPWM_REGS_VCAPCTL_VCAPSTART_Pos)                                             /*!< VCAPSTART Mask      0x00000002 */
#define EPWM_REGS_VCAPCTL_VCAPSTART_Set(x) (((uint16_t) (x) << EPWM_REGS_VCAPCTL_VCAPSTART_Pos) & EPWM_REGS_VCAPCTL_VCAPSTART_Msk) /*!< VCAPSTART Set Value            */
#define EPWM_REGS_VCAPCTL_VCAPSTART_Get(x) (((uint16_t) (x) & EPWM_REGS_VCAPCTL_VCAPSTART_Msk) >> EPWM_REGS_VCAPCTL_VCAPSTART_Pos) /*!< VCAPSTART Get Value            */


#define EPWM_REGS_VCAPCTL_VCAPE_Pos    (0U)                                                                                  /*!< VCAPE Postion   0          */ 
#define EPWM_REGS_VCAPCTL_VCAPE_Msk    (0x1U << EPWM_REGS_VCAPCTL_VCAPE_Pos)                                                 /*!< VCAPE Mask      0x00000001 */
#define EPWM_REGS_VCAPCTL_VCAPE_Set(x) (((uint16_t) (x) << EPWM_REGS_VCAPCTL_VCAPE_Pos) & EPWM_REGS_VCAPCTL_VCAPE_Msk)       /*!< VCAPE Set Value            */
#define EPWM_REGS_VCAPCTL_VCAPE_Get(x) (((uint16_t) (x) & EPWM_REGS_VCAPCTL_VCAPE_Msk) >> EPWM_REGS_VCAPCTL_VCAPE_Pos)       /*!< VCAPE Get Value            */


/* VCNTCFG bitfield */
#define EPWM_REGS_VCNTCFG_STOPEDGESTS_Pos    (15U)                                                                                 /*!< STOPEDGESTS Postion   15         */ 
#define EPWM_REGS_VCNTCFG_STOPEDGESTS_Msk    (0x1U << EPWM_REGS_VCNTCFG_STOPEDGESTS_Pos)                                           /*!< STOPEDGESTS Mask      0x00008000 */
#define EPWM_REGS_VCNTCFG_STOPEDGESTS_Set(x) (((uint16_t) (x) << EPWM_REGS_VCNTCFG_STOPEDGESTS_Pos) & EPWM_REGS_VCNTCFG_STOPEDGESTS_Msk) /*!< STOPEDGESTS Set Value            */
#define EPWM_REGS_VCNTCFG_STOPEDGESTS_Get(x) (((uint16_t) (x) & EPWM_REGS_VCNTCFG_STOPEDGESTS_Msk) >> EPWM_REGS_VCNTCFG_STOPEDGESTS_Pos) /*!< STOPEDGESTS Get Value            */


#define EPWM_REGS_VCNTCFG_STOPEDGE_Pos    (8U)                                                                                  /*!< STOPEDGE Postion   8          */ 
#define EPWM_REGS_VCNTCFG_STOPEDGE_Msk    (0xfU << EPWM_REGS_VCNTCFG_STOPEDGE_Pos)                                              /*!< STOPEDGE Mask      0x00000F00 */
#define EPWM_REGS_VCNTCFG_STOPEDGE_Set(x) (((uint16_t) (x) << EPWM_REGS_VCNTCFG_STOPEDGE_Pos) & EPWM_REGS_VCNTCFG_STOPEDGE_Msk) /*!< STOPEDGE Set Value            */
#define EPWM_REGS_VCNTCFG_STOPEDGE_Get(x) (((uint16_t) (x) & EPWM_REGS_VCNTCFG_STOPEDGE_Msk) >> EPWM_REGS_VCNTCFG_STOPEDGE_Pos) /*!< STOPEDGE Get Value            */


#define EPWM_REGS_VCNTCFG_STARTEDGESTS_Pos    (7U)                                                                                  /*!< STARTEDGESTS Postion   7          */ 
#define EPWM_REGS_VCNTCFG_STARTEDGESTS_Msk    (0x1U << EPWM_REGS_VCNTCFG_STARTEDGESTS_Pos)                                          /*!< STARTEDGESTS Mask      0x00000080 */
#define EPWM_REGS_VCNTCFG_STARTEDGESTS_Set(x) (((uint16_t) (x) << EPWM_REGS_VCNTCFG_STARTEDGESTS_Pos) & EPWM_REGS_VCNTCFG_STARTEDGESTS_Msk) /*!< STARTEDGESTS Set Value            */
#define EPWM_REGS_VCNTCFG_STARTEDGESTS_Get(x) (((uint16_t) (x) & EPWM_REGS_VCNTCFG_STARTEDGESTS_Msk) >> EPWM_REGS_VCNTCFG_STARTEDGESTS_Pos) /*!< STARTEDGESTS Get Value            */


#define EPWM_REGS_VCNTCFG_STARTEDGE_Pos    (0U)                                                                                  /*!< STARTEDGE Postion   0          */ 
#define EPWM_REGS_VCNTCFG_STARTEDGE_Msk    (0xfU << EPWM_REGS_VCNTCFG_STARTEDGE_Pos)                                             /*!< STARTEDGE Mask      0x0000000F */
#define EPWM_REGS_VCNTCFG_STARTEDGE_Set(x) (((uint16_t) (x) << EPWM_REGS_VCNTCFG_STARTEDGE_Pos) & EPWM_REGS_VCNTCFG_STARTEDGE_Msk) /*!< STARTEDGE Set Value            */
#define EPWM_REGS_VCNTCFG_STARTEDGE_Get(x) (((uint16_t) (x) & EPWM_REGS_VCNTCFG_STARTEDGE_Msk) >> EPWM_REGS_VCNTCFG_STARTEDGE_Pos) /*!< STARTEDGE Get Value            */


/* HRPCTL bitfield */
#define EPWM_REGS_HRPCTL_PWMSYNCSELX_Pos    (4U)                                                                                  /*!< PWMSYNCSELX Postion   4          */ 
#define EPWM_REGS_HRPCTL_PWMSYNCSELX_Msk    (0x7U << EPWM_REGS_HRPCTL_PWMSYNCSELX_Pos)                                            /*!< PWMSYNCSELX Mask      0x00000070 */
#define EPWM_REGS_HRPCTL_PWMSYNCSELX_Set(x) (((uint16_t) (x) << EPWM_REGS_HRPCTL_PWMSYNCSELX_Pos) & EPWM_REGS_HRPCTL_PWMSYNCSELX_Msk) /*!< PWMSYNCSELX Set Value            */
#define EPWM_REGS_HRPCTL_PWMSYNCSELX_Get(x) (((uint16_t) (x) & EPWM_REGS_HRPCTL_PWMSYNCSELX_Msk) >> EPWM_REGS_HRPCTL_PWMSYNCSELX_Pos) /*!< PWMSYNCSELX Get Value            */


#define EPWM_REGS_HRPCTL_PWMSYNCSEL_Pos    (1U)                                                                                  /*!< PWMSYNCSEL Postion   1          */ 
#define EPWM_REGS_HRPCTL_PWMSYNCSEL_Msk    (0x1U << EPWM_REGS_HRPCTL_PWMSYNCSEL_Pos)                                             /*!< PWMSYNCSEL Mask      0x00000002 */
#define EPWM_REGS_HRPCTL_PWMSYNCSEL_Set(x) (((uint16_t) (x) << EPWM_REGS_HRPCTL_PWMSYNCSEL_Pos) & EPWM_REGS_HRPCTL_PWMSYNCSEL_Msk) /*!< PWMSYNCSEL Set Value            */
#define EPWM_REGS_HRPCTL_PWMSYNCSEL_Get(x) (((uint16_t) (x) & EPWM_REGS_HRPCTL_PWMSYNCSEL_Msk) >> EPWM_REGS_HRPCTL_PWMSYNCSEL_Pos) /*!< PWMSYNCSEL Get Value            */


/* GLDCTL bitfield */
#define EPWM_REGS_GLDCTL_GLDCNT_Pos    (10U)                                                                                 /*!< GLDCNT Postion   10         */ 
#define EPWM_REGS_GLDCTL_GLDCNT_Msk    (0x7U << EPWM_REGS_GLDCTL_GLDCNT_Pos)                                                 /*!< GLDCNT Mask      0x00001C00 */
#define EPWM_REGS_GLDCTL_GLDCNT_Set(x) (((uint16_t) (x) << EPWM_REGS_GLDCTL_GLDCNT_Pos) & EPWM_REGS_GLDCTL_GLDCNT_Msk)       /*!< GLDCNT Set Value            */
#define EPWM_REGS_GLDCTL_GLDCNT_Get(x) (((uint16_t) (x) & EPWM_REGS_GLDCTL_GLDCNT_Msk) >> EPWM_REGS_GLDCTL_GLDCNT_Pos)       /*!< GLDCNT Get Value            */


#define EPWM_REGS_GLDCTL_GLDPRD_Pos    (7U)                                                                                  /*!< GLDPRD Postion   7          */ 
#define EPWM_REGS_GLDCTL_GLDPRD_Msk    (0x7U << EPWM_REGS_GLDCTL_GLDPRD_Pos)                                                 /*!< GLDPRD Mask      0x00000380 */
#define EPWM_REGS_GLDCTL_GLDPRD_Set(x) (((uint16_t) (x) << EPWM_REGS_GLDCTL_GLDPRD_Pos) & EPWM_REGS_GLDCTL_GLDPRD_Msk)       /*!< GLDPRD Set Value            */
#define EPWM_REGS_GLDCTL_GLDPRD_Get(x) (((uint16_t) (x) & EPWM_REGS_GLDCTL_GLDPRD_Msk) >> EPWM_REGS_GLDCTL_GLDPRD_Pos)       /*!< GLDPRD Get Value            */


#define EPWM_REGS_GLDCTL_OSHTMODE_Pos    (5U)                                                                                  /*!< OSHTMODE Postion   5          */ 
#define EPWM_REGS_GLDCTL_OSHTMODE_Msk    (0x1U << EPWM_REGS_GLDCTL_OSHTMODE_Pos)                                               /*!< OSHTMODE Mask      0x00000020 */
#define EPWM_REGS_GLDCTL_OSHTMODE_Set(x) (((uint16_t) (x) << EPWM_REGS_GLDCTL_OSHTMODE_Pos) & EPWM_REGS_GLDCTL_OSHTMODE_Msk)   /*!< OSHTMODE Set Value            */
#define EPWM_REGS_GLDCTL_OSHTMODE_Get(x) (((uint16_t) (x) & EPWM_REGS_GLDCTL_OSHTMODE_Msk) >> EPWM_REGS_GLDCTL_OSHTMODE_Pos)   /*!< OSHTMODE Get Value            */


#define EPWM_REGS_GLDCTL_GLDMODE_Pos    (1U)                                                                                  /*!< GLDMODE Postion   1          */ 
#define EPWM_REGS_GLDCTL_GLDMODE_Msk    (0xfU << EPWM_REGS_GLDCTL_GLDMODE_Pos)                                                /*!< GLDMODE Mask      0x0000001E */
#define EPWM_REGS_GLDCTL_GLDMODE_Set(x) (((uint16_t) (x) << EPWM_REGS_GLDCTL_GLDMODE_Pos) & EPWM_REGS_GLDCTL_GLDMODE_Msk)     /*!< GLDMODE Set Value            */
#define EPWM_REGS_GLDCTL_GLDMODE_Get(x) (((uint16_t) (x) & EPWM_REGS_GLDCTL_GLDMODE_Msk) >> EPWM_REGS_GLDCTL_GLDMODE_Pos)     /*!< GLDMODE Get Value            */


#define EPWM_REGS_GLDCTL_GLD_Pos    (0U)                                                                                  /*!< GLD Postion   0          */ 
#define EPWM_REGS_GLDCTL_GLD_Msk    (0x1U << EPWM_REGS_GLDCTL_GLD_Pos)                                                    /*!< GLD Mask      0x00000001 */
#define EPWM_REGS_GLDCTL_GLD_Set(x) (((uint16_t) (x) << EPWM_REGS_GLDCTL_GLD_Pos) & EPWM_REGS_GLDCTL_GLD_Msk)             /*!< GLD Set Value            */
#define EPWM_REGS_GLDCTL_GLD_Get(x) (((uint16_t) (x) & EPWM_REGS_GLDCTL_GLD_Msk) >> EPWM_REGS_GLDCTL_GLD_Pos)             /*!< GLD Get Value            */


/* GLDCFG bitfield */
#define EPWM_REGS_GLDCFG_AQCSFRC_Pos    (10U)                                                                                 /*!< AQCSFRC Postion   10         */ 
#define EPWM_REGS_GLDCFG_AQCSFRC_Msk    (0x1U << EPWM_REGS_GLDCFG_AQCSFRC_Pos)                                                /*!< AQCSFRC Mask      0x00000400 */
#define EPWM_REGS_GLDCFG_AQCSFRC_Set(x) (((uint16_t) (x) << EPWM_REGS_GLDCFG_AQCSFRC_Pos) & EPWM_REGS_GLDCFG_AQCSFRC_Msk)     /*!< AQCSFRC Set Value            */
#define EPWM_REGS_GLDCFG_AQCSFRC_Get(x) (((uint16_t) (x) & EPWM_REGS_GLDCFG_AQCSFRC_Msk) >> EPWM_REGS_GLDCFG_AQCSFRC_Pos)     /*!< AQCSFRC Get Value            */


#define EPWM_REGS_GLDCFG_AQCTLB_AQCTLB2_Pos    (9U)                                                                                  /*!< AQCTLB_AQCTLB2 Postion   9          */ 
#define EPWM_REGS_GLDCFG_AQCTLB_AQCTLB2_Msk    (0x1U << EPWM_REGS_GLDCFG_AQCTLB_AQCTLB2_Pos)                                         /*!< AQCTLB_AQCTLB2 Mask      0x00000200 */
#define EPWM_REGS_GLDCFG_AQCTLB_AQCTLB2_Set(x) (((uint16_t) (x) << EPWM_REGS_GLDCFG_AQCTLB_AQCTLB2_Pos) & EPWM_REGS_GLDCFG_AQCTLB_AQCTLB2_Msk) /*!< AQCTLB_AQCTLB2 Set Value            */
#define EPWM_REGS_GLDCFG_AQCTLB_AQCTLB2_Get(x) (((uint16_t) (x) & EPWM_REGS_GLDCFG_AQCTLB_AQCTLB2_Msk) >> EPWM_REGS_GLDCFG_AQCTLB_AQCTLB2_Pos) /*!< AQCTLB_AQCTLB2 Get Value            */


#define EPWM_REGS_GLDCFG_AQCTLA_AQCTLA2_Pos    (8U)                                                                                  /*!< AQCTLA_AQCTLA2 Postion   8          */ 
#define EPWM_REGS_GLDCFG_AQCTLA_AQCTLA2_Msk    (0x1U << EPWM_REGS_GLDCFG_AQCTLA_AQCTLA2_Pos)                                         /*!< AQCTLA_AQCTLA2 Mask      0x00000100 */
#define EPWM_REGS_GLDCFG_AQCTLA_AQCTLA2_Set(x) (((uint16_t) (x) << EPWM_REGS_GLDCFG_AQCTLA_AQCTLA2_Pos) & EPWM_REGS_GLDCFG_AQCTLA_AQCTLA2_Msk) /*!< AQCTLA_AQCTLA2 Set Value            */
#define EPWM_REGS_GLDCFG_AQCTLA_AQCTLA2_Get(x) (((uint16_t) (x) & EPWM_REGS_GLDCFG_AQCTLA_AQCTLA2_Msk) >> EPWM_REGS_GLDCFG_AQCTLA_AQCTLA2_Pos) /*!< AQCTLA_AQCTLA2 Get Value            */


#define EPWM_REGS_GLDCFG_DBCTL_Pos    (7U)                                                                                  /*!< DBCTL Postion   7          */ 
#define EPWM_REGS_GLDCFG_DBCTL_Msk    (0x1U << EPWM_REGS_GLDCFG_DBCTL_Pos)                                                  /*!< DBCTL Mask      0x00000080 */
#define EPWM_REGS_GLDCFG_DBCTL_Set(x) (((uint16_t) (x) << EPWM_REGS_GLDCFG_DBCTL_Pos) & EPWM_REGS_GLDCFG_DBCTL_Msk)         /*!< DBCTL Set Value            */
#define EPWM_REGS_GLDCFG_DBCTL_Get(x) (((uint16_t) (x) & EPWM_REGS_GLDCFG_DBCTL_Msk) >> EPWM_REGS_GLDCFG_DBCTL_Pos)         /*!< DBCTL Get Value            */


#define EPWM_REGS_GLDCFG_DBFED_Pos    (6U)                                                                                  /*!< DBFED Postion   6          */ 
#define EPWM_REGS_GLDCFG_DBFED_Msk    (0x1U << EPWM_REGS_GLDCFG_DBFED_Pos)                                                  /*!< DBFED Mask      0x00000040 */
#define EPWM_REGS_GLDCFG_DBFED_Set(x) (((uint16_t) (x) << EPWM_REGS_GLDCFG_DBFED_Pos) & EPWM_REGS_GLDCFG_DBFED_Msk)         /*!< DBFED Set Value            */
#define EPWM_REGS_GLDCFG_DBFED_Get(x) (((uint16_t) (x) & EPWM_REGS_GLDCFG_DBFED_Msk) >> EPWM_REGS_GLDCFG_DBFED_Pos)         /*!< DBFED Get Value            */


#define EPWM_REGS_GLDCFG_DBRED_Pos    (5U)                                                                                  /*!< DBRED Postion   5          */ 
#define EPWM_REGS_GLDCFG_DBRED_Msk    (0x1U << EPWM_REGS_GLDCFG_DBRED_Pos)                                                  /*!< DBRED Mask      0x00000020 */
#define EPWM_REGS_GLDCFG_DBRED_Set(x) (((uint16_t) (x) << EPWM_REGS_GLDCFG_DBRED_Pos) & EPWM_REGS_GLDCFG_DBRED_Msk)         /*!< DBRED Set Value            */
#define EPWM_REGS_GLDCFG_DBRED_Get(x) (((uint16_t) (x) & EPWM_REGS_GLDCFG_DBRED_Msk) >> EPWM_REGS_GLDCFG_DBRED_Pos)         /*!< DBRED Get Value            */


#define EPWM_REGS_GLDCFG_CMPD_Pos    (4U)                                                                                  /*!< CMPD Postion   4          */ 
#define EPWM_REGS_GLDCFG_CMPD_Msk    (0x1U << EPWM_REGS_GLDCFG_CMPD_Pos)                                                   /*!< CMPD Mask      0x00000010 */
#define EPWM_REGS_GLDCFG_CMPD_Set(x) (((uint16_t) (x) << EPWM_REGS_GLDCFG_CMPD_Pos) & EPWM_REGS_GLDCFG_CMPD_Msk)           /*!< CMPD Set Value            */
#define EPWM_REGS_GLDCFG_CMPD_Get(x) (((uint16_t) (x) & EPWM_REGS_GLDCFG_CMPD_Msk) >> EPWM_REGS_GLDCFG_CMPD_Pos)           /*!< CMPD Get Value            */


#define EPWM_REGS_GLDCFG_CMPC_Pos    (3U)                                                                                  /*!< CMPC Postion   3          */ 
#define EPWM_REGS_GLDCFG_CMPC_Msk    (0x1U << EPWM_REGS_GLDCFG_CMPC_Pos)                                                   /*!< CMPC Mask      0x00000008 */
#define EPWM_REGS_GLDCFG_CMPC_Set(x) (((uint16_t) (x) << EPWM_REGS_GLDCFG_CMPC_Pos) & EPWM_REGS_GLDCFG_CMPC_Msk)           /*!< CMPC Set Value            */
#define EPWM_REGS_GLDCFG_CMPC_Get(x) (((uint16_t) (x) & EPWM_REGS_GLDCFG_CMPC_Msk) >> EPWM_REGS_GLDCFG_CMPC_Pos)           /*!< CMPC Get Value            */


#define EPWM_REGS_GLDCFG_CMPB_Pos    (2U)                                                                                  /*!< CMPB Postion   2          */ 
#define EPWM_REGS_GLDCFG_CMPB_Msk    (0x1U << EPWM_REGS_GLDCFG_CMPB_Pos)                                                   /*!< CMPB Mask      0x00000004 */
#define EPWM_REGS_GLDCFG_CMPB_Set(x) (((uint16_t) (x) << EPWM_REGS_GLDCFG_CMPB_Pos) & EPWM_REGS_GLDCFG_CMPB_Msk)           /*!< CMPB Set Value            */
#define EPWM_REGS_GLDCFG_CMPB_Get(x) (((uint16_t) (x) & EPWM_REGS_GLDCFG_CMPB_Msk) >> EPWM_REGS_GLDCFG_CMPB_Pos)           /*!< CMPB Get Value            */


#define EPWM_REGS_GLDCFG_CMPA_Pos    (1U)                                                                                  /*!< CMPA Postion   1          */ 
#define EPWM_REGS_GLDCFG_CMPA_Msk    (0x1U << EPWM_REGS_GLDCFG_CMPA_Pos)                                                   /*!< CMPA Mask      0x00000002 */
#define EPWM_REGS_GLDCFG_CMPA_Set(x) (((uint16_t) (x) << EPWM_REGS_GLDCFG_CMPA_Pos) & EPWM_REGS_GLDCFG_CMPA_Msk)           /*!< CMPA Set Value            */
#define EPWM_REGS_GLDCFG_CMPA_Get(x) (((uint16_t) (x) & EPWM_REGS_GLDCFG_CMPA_Msk) >> EPWM_REGS_GLDCFG_CMPA_Pos)           /*!< CMPA Get Value            */


#define EPWM_REGS_GLDCFG_TBPRD_TBPRDHR_Pos    (0U)                                                                                  /*!< TBPRD_TBPRDHR Postion   0          */ 
#define EPWM_REGS_GLDCFG_TBPRD_TBPRDHR_Msk    (0x1U << EPWM_REGS_GLDCFG_TBPRD_TBPRDHR_Pos)                                          /*!< TBPRD_TBPRDHR Mask      0x00000001 */
#define EPWM_REGS_GLDCFG_TBPRD_TBPRDHR_Set(x) (((uint16_t) (x) << EPWM_REGS_GLDCFG_TBPRD_TBPRDHR_Pos) & EPWM_REGS_GLDCFG_TBPRD_TBPRDHR_Msk) /*!< TBPRD_TBPRDHR Set Value            */
#define EPWM_REGS_GLDCFG_TBPRD_TBPRDHR_Get(x) (((uint16_t) (x) & EPWM_REGS_GLDCFG_TBPRD_TBPRDHR_Msk) >> EPWM_REGS_GLDCFG_TBPRD_TBPRDHR_Pos) /*!< TBPRD_TBPRDHR Get Value            */


/* EPWMXLINK bitfield */
#define EPWM_REGS_EPWMXLINK_GLDCTL2LINK_Pos    (28U)                                                                                 /*!< GLDCTL2LINK Postion   28         */ 
#define EPWM_REGS_EPWMXLINK_GLDCTL2LINK_Msk    (0xfU << EPWM_REGS_EPWMXLINK_GLDCTL2LINK_Pos)                                         /*!< GLDCTL2LINK Mask      0xF0000000 */
#define EPWM_REGS_EPWMXLINK_GLDCTL2LINK_Set(x) (((uint32_t) (x) << EPWM_REGS_EPWMXLINK_GLDCTL2LINK_Pos) & EPWM_REGS_EPWMXLINK_GLDCTL2LINK_Msk) /*!< GLDCTL2LINK Set Value            */
#define EPWM_REGS_EPWMXLINK_GLDCTL2LINK_Get(x) (((uint32_t) (x) & EPWM_REGS_EPWMXLINK_GLDCTL2LINK_Msk) >> EPWM_REGS_EPWMXLINK_GLDCTL2LINK_Pos) /*!< GLDCTL2LINK Get Value            */


#define EPWM_REGS_EPWMXLINK_CMPDLINK_Pos    (16U)                                                                                 /*!< CMPDLINK Postion   16         */ 
#define EPWM_REGS_EPWMXLINK_CMPDLINK_Msk    (0xfU << EPWM_REGS_EPWMXLINK_CMPDLINK_Pos)                                            /*!< CMPDLINK Mask      0x000F0000 */
#define EPWM_REGS_EPWMXLINK_CMPDLINK_Set(x) (((uint32_t) (x) << EPWM_REGS_EPWMXLINK_CMPDLINK_Pos) & EPWM_REGS_EPWMXLINK_CMPDLINK_Msk) /*!< CMPDLINK Set Value            */
#define EPWM_REGS_EPWMXLINK_CMPDLINK_Get(x) (((uint32_t) (x) & EPWM_REGS_EPWMXLINK_CMPDLINK_Msk) >> EPWM_REGS_EPWMXLINK_CMPDLINK_Pos) /*!< CMPDLINK Get Value            */


#define EPWM_REGS_EPWMXLINK_CMPCLINK_Pos    (12U)                                                                                 /*!< CMPCLINK Postion   12         */ 
#define EPWM_REGS_EPWMXLINK_CMPCLINK_Msk    (0xfU << EPWM_REGS_EPWMXLINK_CMPCLINK_Pos)                                            /*!< CMPCLINK Mask      0x0000F000 */
#define EPWM_REGS_EPWMXLINK_CMPCLINK_Set(x) (((uint32_t) (x) << EPWM_REGS_EPWMXLINK_CMPCLINK_Pos) & EPWM_REGS_EPWMXLINK_CMPCLINK_Msk) /*!< CMPCLINK Set Value            */
#define EPWM_REGS_EPWMXLINK_CMPCLINK_Get(x) (((uint32_t) (x) & EPWM_REGS_EPWMXLINK_CMPCLINK_Msk) >> EPWM_REGS_EPWMXLINK_CMPCLINK_Pos) /*!< CMPCLINK Get Value            */


#define EPWM_REGS_EPWMXLINK_CMPBLINK_Pos    (8U)                                                                                  /*!< CMPBLINK Postion   8          */ 
#define EPWM_REGS_EPWMXLINK_CMPBLINK_Msk    (0xfU << EPWM_REGS_EPWMXLINK_CMPBLINK_Pos)                                            /*!< CMPBLINK Mask      0x00000F00 */
#define EPWM_REGS_EPWMXLINK_CMPBLINK_Set(x) (((uint32_t) (x) << EPWM_REGS_EPWMXLINK_CMPBLINK_Pos) & EPWM_REGS_EPWMXLINK_CMPBLINK_Msk) /*!< CMPBLINK Set Value            */
#define EPWM_REGS_EPWMXLINK_CMPBLINK_Get(x) (((uint32_t) (x) & EPWM_REGS_EPWMXLINK_CMPBLINK_Msk) >> EPWM_REGS_EPWMXLINK_CMPBLINK_Pos) /*!< CMPBLINK Get Value            */


#define EPWM_REGS_EPWMXLINK_CMPALINK_Pos    (4U)                                                                                  /*!< CMPALINK Postion   4          */ 
#define EPWM_REGS_EPWMXLINK_CMPALINK_Msk    (0xfU << EPWM_REGS_EPWMXLINK_CMPALINK_Pos)                                            /*!< CMPALINK Mask      0x000000F0 */
#define EPWM_REGS_EPWMXLINK_CMPALINK_Set(x) (((uint32_t) (x) << EPWM_REGS_EPWMXLINK_CMPALINK_Pos) & EPWM_REGS_EPWMXLINK_CMPALINK_Msk) /*!< CMPALINK Set Value            */
#define EPWM_REGS_EPWMXLINK_CMPALINK_Get(x) (((uint32_t) (x) & EPWM_REGS_EPWMXLINK_CMPALINK_Msk) >> EPWM_REGS_EPWMXLINK_CMPALINK_Pos) /*!< CMPALINK Get Value            */


#define EPWM_REGS_EPWMXLINK_TBPRDLINK_Pos    (0U)                                                                                  /*!< TBPRDLINK Postion   0          */ 
#define EPWM_REGS_EPWMXLINK_TBPRDLINK_Msk    (0xfU << EPWM_REGS_EPWMXLINK_TBPRDLINK_Pos)                                           /*!< TBPRDLINK Mask      0x0000000F */
#define EPWM_REGS_EPWMXLINK_TBPRDLINK_Set(x) (((uint32_t) (x) << EPWM_REGS_EPWMXLINK_TBPRDLINK_Pos) & EPWM_REGS_EPWMXLINK_TBPRDLINK_Msk) /*!< TBPRDLINK Set Value            */
#define EPWM_REGS_EPWMXLINK_TBPRDLINK_Get(x) (((uint32_t) (x) & EPWM_REGS_EPWMXLINK_TBPRDLINK_Msk) >> EPWM_REGS_EPWMXLINK_TBPRDLINK_Pos) /*!< TBPRDLINK Get Value            */


/* AQCTLA bitfield */
#define EPWM_REGS_AQCTLA_CBD_Pos    (10U)                                                                                 /*!< CBD Postion   10         */ 
#define EPWM_REGS_AQCTLA_CBD_Msk    (0x3U << EPWM_REGS_AQCTLA_CBD_Pos)                                                    /*!< CBD Mask      0x00000C00 */
#define EPWM_REGS_AQCTLA_CBD_Set(x) (((uint16_t) (x) << EPWM_REGS_AQCTLA_CBD_Pos) & EPWM_REGS_AQCTLA_CBD_Msk)             /*!< CBD Set Value            */
#define EPWM_REGS_AQCTLA_CBD_Get(x) (((uint16_t) (x) & EPWM_REGS_AQCTLA_CBD_Msk) >> EPWM_REGS_AQCTLA_CBD_Pos)             /*!< CBD Get Value            */


#define EPWM_REGS_AQCTLA_CBU_Pos    (8U)                                                                                  /*!< CBU Postion   8          */ 
#define EPWM_REGS_AQCTLA_CBU_Msk    (0x3U << EPWM_REGS_AQCTLA_CBU_Pos)                                                    /*!< CBU Mask      0x00000300 */
#define EPWM_REGS_AQCTLA_CBU_Set(x) (((uint16_t) (x) << EPWM_REGS_AQCTLA_CBU_Pos) & EPWM_REGS_AQCTLA_CBU_Msk)             /*!< CBU Set Value            */
#define EPWM_REGS_AQCTLA_CBU_Get(x) (((uint16_t) (x) & EPWM_REGS_AQCTLA_CBU_Msk) >> EPWM_REGS_AQCTLA_CBU_Pos)             /*!< CBU Get Value            */


#define EPWM_REGS_AQCTLA_CAD_Pos    (6U)                                                                                  /*!< CAD Postion   6          */ 
#define EPWM_REGS_AQCTLA_CAD_Msk    (0x3U << EPWM_REGS_AQCTLA_CAD_Pos)                                                    /*!< CAD Mask      0x000000C0 */
#define EPWM_REGS_AQCTLA_CAD_Set(x) (((uint16_t) (x) << EPWM_REGS_AQCTLA_CAD_Pos) & EPWM_REGS_AQCTLA_CAD_Msk)             /*!< CAD Set Value            */
#define EPWM_REGS_AQCTLA_CAD_Get(x) (((uint16_t) (x) & EPWM_REGS_AQCTLA_CAD_Msk) >> EPWM_REGS_AQCTLA_CAD_Pos)             /*!< CAD Get Value            */


#define EPWM_REGS_AQCTLA_CAU_Pos    (4U)                                                                                  /*!< CAU Postion   4          */ 
#define EPWM_REGS_AQCTLA_CAU_Msk    (0x3U << EPWM_REGS_AQCTLA_CAU_Pos)                                                    /*!< CAU Mask      0x00000030 */
#define EPWM_REGS_AQCTLA_CAU_Set(x) (((uint16_t) (x) << EPWM_REGS_AQCTLA_CAU_Pos) & EPWM_REGS_AQCTLA_CAU_Msk)             /*!< CAU Set Value            */
#define EPWM_REGS_AQCTLA_CAU_Get(x) (((uint16_t) (x) & EPWM_REGS_AQCTLA_CAU_Msk) >> EPWM_REGS_AQCTLA_CAU_Pos)             /*!< CAU Get Value            */


#define EPWM_REGS_AQCTLA_PRD_Pos    (2U)                                                                                  /*!< PRD Postion   2          */ 
#define EPWM_REGS_AQCTLA_PRD_Msk    (0x3U << EPWM_REGS_AQCTLA_PRD_Pos)                                                    /*!< PRD Mask      0x0000000C */
#define EPWM_REGS_AQCTLA_PRD_Set(x) (((uint16_t) (x) << EPWM_REGS_AQCTLA_PRD_Pos) & EPWM_REGS_AQCTLA_PRD_Msk)             /*!< PRD Set Value            */
#define EPWM_REGS_AQCTLA_PRD_Get(x) (((uint16_t) (x) & EPWM_REGS_AQCTLA_PRD_Msk) >> EPWM_REGS_AQCTLA_PRD_Pos)             /*!< PRD Get Value            */


#define EPWM_REGS_AQCTLA_ZRO_Pos    (0U)                                                                                  /*!< ZRO Postion   0          */ 
#define EPWM_REGS_AQCTLA_ZRO_Msk    (0x3U << EPWM_REGS_AQCTLA_ZRO_Pos)                                                    /*!< ZRO Mask      0x00000003 */
#define EPWM_REGS_AQCTLA_ZRO_Set(x) (((uint16_t) (x) << EPWM_REGS_AQCTLA_ZRO_Pos) & EPWM_REGS_AQCTLA_ZRO_Msk)             /*!< ZRO Set Value            */
#define EPWM_REGS_AQCTLA_ZRO_Get(x) (((uint16_t) (x) & EPWM_REGS_AQCTLA_ZRO_Msk) >> EPWM_REGS_AQCTLA_ZRO_Pos)             /*!< ZRO Get Value            */


/* AQCTLA2 bitfield */
#define EPWM_REGS_AQCTLA2_T2D_Pos    (6U)                                                                                  /*!< T2D Postion   6          */ 
#define EPWM_REGS_AQCTLA2_T2D_Msk    (0x3U << EPWM_REGS_AQCTLA2_T2D_Pos)                                                   /*!< T2D Mask      0x000000C0 */
#define EPWM_REGS_AQCTLA2_T2D_Set(x) (((uint16_t) (x) << EPWM_REGS_AQCTLA2_T2D_Pos) & EPWM_REGS_AQCTLA2_T2D_Msk)           /*!< T2D Set Value            */
#define EPWM_REGS_AQCTLA2_T2D_Get(x) (((uint16_t) (x) & EPWM_REGS_AQCTLA2_T2D_Msk) >> EPWM_REGS_AQCTLA2_T2D_Pos)           /*!< T2D Get Value            */


#define EPWM_REGS_AQCTLA2_T2U_Pos    (4U)                                                                                  /*!< T2U Postion   4          */ 
#define EPWM_REGS_AQCTLA2_T2U_Msk    (0x3U << EPWM_REGS_AQCTLA2_T2U_Pos)                                                   /*!< T2U Mask      0x00000030 */
#define EPWM_REGS_AQCTLA2_T2U_Set(x) (((uint16_t) (x) << EPWM_REGS_AQCTLA2_T2U_Pos) & EPWM_REGS_AQCTLA2_T2U_Msk)           /*!< T2U Set Value            */
#define EPWM_REGS_AQCTLA2_T2U_Get(x) (((uint16_t) (x) & EPWM_REGS_AQCTLA2_T2U_Msk) >> EPWM_REGS_AQCTLA2_T2U_Pos)           /*!< T2U Get Value            */


#define EPWM_REGS_AQCTLA2_T1D_Pos    (2U)                                                                                  /*!< T1D Postion   2          */ 
#define EPWM_REGS_AQCTLA2_T1D_Msk    (0x3U << EPWM_REGS_AQCTLA2_T1D_Pos)                                                   /*!< T1D Mask      0x0000000C */
#define EPWM_REGS_AQCTLA2_T1D_Set(x) (((uint16_t) (x) << EPWM_REGS_AQCTLA2_T1D_Pos) & EPWM_REGS_AQCTLA2_T1D_Msk)           /*!< T1D Set Value            */
#define EPWM_REGS_AQCTLA2_T1D_Get(x) (((uint16_t) (x) & EPWM_REGS_AQCTLA2_T1D_Msk) >> EPWM_REGS_AQCTLA2_T1D_Pos)           /*!< T1D Get Value            */


#define EPWM_REGS_AQCTLA2_T1U_Pos    (0U)                                                                                  /*!< T1U Postion   0          */ 
#define EPWM_REGS_AQCTLA2_T1U_Msk    (0x3U << EPWM_REGS_AQCTLA2_T1U_Pos)                                                   /*!< T1U Mask      0x00000003 */
#define EPWM_REGS_AQCTLA2_T1U_Set(x) (((uint16_t) (x) << EPWM_REGS_AQCTLA2_T1U_Pos) & EPWM_REGS_AQCTLA2_T1U_Msk)           /*!< T1U Set Value            */
#define EPWM_REGS_AQCTLA2_T1U_Get(x) (((uint16_t) (x) & EPWM_REGS_AQCTLA2_T1U_Msk) >> EPWM_REGS_AQCTLA2_T1U_Pos)           /*!< T1U Get Value            */


/* AQCTLB bitfield */
#define EPWM_REGS_AQCTLB_CBD_Pos    (10U)                                                                                 /*!< CBD Postion   10         */ 
#define EPWM_REGS_AQCTLB_CBD_Msk    (0x3U << EPWM_REGS_AQCTLB_CBD_Pos)                                                    /*!< CBD Mask      0x00000C00 */
#define EPWM_REGS_AQCTLB_CBD_Set(x) (((uint16_t) (x) << EPWM_REGS_AQCTLB_CBD_Pos) & EPWM_REGS_AQCTLB_CBD_Msk)             /*!< CBD Set Value            */
#define EPWM_REGS_AQCTLB_CBD_Get(x) (((uint16_t) (x) & EPWM_REGS_AQCTLB_CBD_Msk) >> EPWM_REGS_AQCTLB_CBD_Pos)             /*!< CBD Get Value            */


#define EPWM_REGS_AQCTLB_CBU_Pos    (8U)                                                                                  /*!< CBU Postion   8          */ 
#define EPWM_REGS_AQCTLB_CBU_Msk    (0x3U << EPWM_REGS_AQCTLB_CBU_Pos)                                                    /*!< CBU Mask      0x00000300 */
#define EPWM_REGS_AQCTLB_CBU_Set(x) (((uint16_t) (x) << EPWM_REGS_AQCTLB_CBU_Pos) & EPWM_REGS_AQCTLB_CBU_Msk)             /*!< CBU Set Value            */
#define EPWM_REGS_AQCTLB_CBU_Get(x) (((uint16_t) (x) & EPWM_REGS_AQCTLB_CBU_Msk) >> EPWM_REGS_AQCTLB_CBU_Pos)             /*!< CBU Get Value            */


#define EPWM_REGS_AQCTLB_CAD_Pos    (6U)                                                                                  /*!< CAD Postion   6          */ 
#define EPWM_REGS_AQCTLB_CAD_Msk    (0x3U << EPWM_REGS_AQCTLB_CAD_Pos)                                                    /*!< CAD Mask      0x000000C0 */
#define EPWM_REGS_AQCTLB_CAD_Set(x) (((uint16_t) (x) << EPWM_REGS_AQCTLB_CAD_Pos) & EPWM_REGS_AQCTLB_CAD_Msk)             /*!< CAD Set Value            */
#define EPWM_REGS_AQCTLB_CAD_Get(x) (((uint16_t) (x) & EPWM_REGS_AQCTLB_CAD_Msk) >> EPWM_REGS_AQCTLB_CAD_Pos)             /*!< CAD Get Value            */


#define EPWM_REGS_AQCTLB_CAU_Pos    (4U)                                                                                  /*!< CAU Postion   4          */ 
#define EPWM_REGS_AQCTLB_CAU_Msk    (0x3U << EPWM_REGS_AQCTLB_CAU_Pos)                                                    /*!< CAU Mask      0x00000030 */
#define EPWM_REGS_AQCTLB_CAU_Set(x) (((uint16_t) (x) << EPWM_REGS_AQCTLB_CAU_Pos) & EPWM_REGS_AQCTLB_CAU_Msk)             /*!< CAU Set Value            */
#define EPWM_REGS_AQCTLB_CAU_Get(x) (((uint16_t) (x) & EPWM_REGS_AQCTLB_CAU_Msk) >> EPWM_REGS_AQCTLB_CAU_Pos)             /*!< CAU Get Value            */


#define EPWM_REGS_AQCTLB_PRD_Pos    (2U)                                                                                  /*!< PRD Postion   2          */ 
#define EPWM_REGS_AQCTLB_PRD_Msk    (0x3U << EPWM_REGS_AQCTLB_PRD_Pos)                                                    /*!< PRD Mask      0x0000000C */
#define EPWM_REGS_AQCTLB_PRD_Set(x) (((uint16_t) (x) << EPWM_REGS_AQCTLB_PRD_Pos) & EPWM_REGS_AQCTLB_PRD_Msk)             /*!< PRD Set Value            */
#define EPWM_REGS_AQCTLB_PRD_Get(x) (((uint16_t) (x) & EPWM_REGS_AQCTLB_PRD_Msk) >> EPWM_REGS_AQCTLB_PRD_Pos)             /*!< PRD Get Value            */


#define EPWM_REGS_AQCTLB_ZRO_Pos    (0U)                                                                                  /*!< ZRO Postion   0          */ 
#define EPWM_REGS_AQCTLB_ZRO_Msk    (0x3U << EPWM_REGS_AQCTLB_ZRO_Pos)                                                    /*!< ZRO Mask      0x00000003 */
#define EPWM_REGS_AQCTLB_ZRO_Set(x) (((uint16_t) (x) << EPWM_REGS_AQCTLB_ZRO_Pos) & EPWM_REGS_AQCTLB_ZRO_Msk)             /*!< ZRO Set Value            */
#define EPWM_REGS_AQCTLB_ZRO_Get(x) (((uint16_t) (x) & EPWM_REGS_AQCTLB_ZRO_Msk) >> EPWM_REGS_AQCTLB_ZRO_Pos)             /*!< ZRO Get Value            */


/* AQCTLB2 bitfield */
#define EPWM_REGS_AQCTLB2_T2D_Pos    (6U)                                                                                  /*!< T2D Postion   6          */ 
#define EPWM_REGS_AQCTLB2_T2D_Msk    (0x3U << EPWM_REGS_AQCTLB2_T2D_Pos)                                                   /*!< T2D Mask      0x000000C0 */
#define EPWM_REGS_AQCTLB2_T2D_Set(x) (((uint16_t) (x) << EPWM_REGS_AQCTLB2_T2D_Pos) & EPWM_REGS_AQCTLB2_T2D_Msk)           /*!< T2D Set Value            */
#define EPWM_REGS_AQCTLB2_T2D_Get(x) (((uint16_t) (x) & EPWM_REGS_AQCTLB2_T2D_Msk) >> EPWM_REGS_AQCTLB2_T2D_Pos)           /*!< T2D Get Value            */


#define EPWM_REGS_AQCTLB2_T2U_Pos    (4U)                                                                                  /*!< T2U Postion   4          */ 
#define EPWM_REGS_AQCTLB2_T2U_Msk    (0x3U << EPWM_REGS_AQCTLB2_T2U_Pos)                                                   /*!< T2U Mask      0x00000030 */
#define EPWM_REGS_AQCTLB2_T2U_Set(x) (((uint16_t) (x) << EPWM_REGS_AQCTLB2_T2U_Pos) & EPWM_REGS_AQCTLB2_T2U_Msk)           /*!< T2U Set Value            */
#define EPWM_REGS_AQCTLB2_T2U_Get(x) (((uint16_t) (x) & EPWM_REGS_AQCTLB2_T2U_Msk) >> EPWM_REGS_AQCTLB2_T2U_Pos)           /*!< T2U Get Value            */


#define EPWM_REGS_AQCTLB2_T1D_Pos    (2U)                                                                                  /*!< T1D Postion   2          */ 
#define EPWM_REGS_AQCTLB2_T1D_Msk    (0x3U << EPWM_REGS_AQCTLB2_T1D_Pos)                                                   /*!< T1D Mask      0x0000000C */
#define EPWM_REGS_AQCTLB2_T1D_Set(x) (((uint16_t) (x) << EPWM_REGS_AQCTLB2_T1D_Pos) & EPWM_REGS_AQCTLB2_T1D_Msk)           /*!< T1D Set Value            */
#define EPWM_REGS_AQCTLB2_T1D_Get(x) (((uint16_t) (x) & EPWM_REGS_AQCTLB2_T1D_Msk) >> EPWM_REGS_AQCTLB2_T1D_Pos)           /*!< T1D Get Value            */


#define EPWM_REGS_AQCTLB2_T1U_Pos    (0U)                                                                                  /*!< T1U Postion   0          */ 
#define EPWM_REGS_AQCTLB2_T1U_Msk    (0x3U << EPWM_REGS_AQCTLB2_T1U_Pos)                                                   /*!< T1U Mask      0x00000003 */
#define EPWM_REGS_AQCTLB2_T1U_Set(x) (((uint16_t) (x) << EPWM_REGS_AQCTLB2_T1U_Pos) & EPWM_REGS_AQCTLB2_T1U_Msk)           /*!< T1U Set Value            */
#define EPWM_REGS_AQCTLB2_T1U_Get(x) (((uint16_t) (x) & EPWM_REGS_AQCTLB2_T1U_Msk) >> EPWM_REGS_AQCTLB2_T1U_Pos)           /*!< T1U Get Value            */


/* AQSFRC bitfield */
#define EPWM_REGS_AQSFRC_RLDCSF_Pos    (6U)                                                                                  /*!< RLDCSF Postion   6          */ 
#define EPWM_REGS_AQSFRC_RLDCSF_Msk    (0x3U << EPWM_REGS_AQSFRC_RLDCSF_Pos)                                                 /*!< RLDCSF Mask      0x000000C0 */
#define EPWM_REGS_AQSFRC_RLDCSF_Set(x) (((uint16_t) (x) << EPWM_REGS_AQSFRC_RLDCSF_Pos) & EPWM_REGS_AQSFRC_RLDCSF_Msk)       /*!< RLDCSF Set Value            */
#define EPWM_REGS_AQSFRC_RLDCSF_Get(x) (((uint16_t) (x) & EPWM_REGS_AQSFRC_RLDCSF_Msk) >> EPWM_REGS_AQSFRC_RLDCSF_Pos)       /*!< RLDCSF Get Value            */


#define EPWM_REGS_AQSFRC_OTSFB_Pos    (5U)                                                                                  /*!< OTSFB Postion   5          */ 
#define EPWM_REGS_AQSFRC_OTSFB_Msk    (0x1U << EPWM_REGS_AQSFRC_OTSFB_Pos)                                                  /*!< OTSFB Mask      0x00000020 */
#define EPWM_REGS_AQSFRC_OTSFB_Set(x) (((uint16_t) (x) << EPWM_REGS_AQSFRC_OTSFB_Pos) & EPWM_REGS_AQSFRC_OTSFB_Msk)         /*!< OTSFB Set Value            */
#define EPWM_REGS_AQSFRC_OTSFB_Get(x) (((uint16_t) (x) & EPWM_REGS_AQSFRC_OTSFB_Msk) >> EPWM_REGS_AQSFRC_OTSFB_Pos)         /*!< OTSFB Get Value            */


#define EPWM_REGS_AQSFRC_ACTSFB_Pos    (3U)                                                                                  /*!< ACTSFB Postion   3          */ 
#define EPWM_REGS_AQSFRC_ACTSFB_Msk    (0x3U << EPWM_REGS_AQSFRC_ACTSFB_Pos)                                                 /*!< ACTSFB Mask      0x00000018 */
#define EPWM_REGS_AQSFRC_ACTSFB_Set(x) (((uint16_t) (x) << EPWM_REGS_AQSFRC_ACTSFB_Pos) & EPWM_REGS_AQSFRC_ACTSFB_Msk)       /*!< ACTSFB Set Value            */
#define EPWM_REGS_AQSFRC_ACTSFB_Get(x) (((uint16_t) (x) & EPWM_REGS_AQSFRC_ACTSFB_Msk) >> EPWM_REGS_AQSFRC_ACTSFB_Pos)       /*!< ACTSFB Get Value            */


#define EPWM_REGS_AQSFRC_OTSFA_Pos    (2U)                                                                                  /*!< OTSFA Postion   2          */ 
#define EPWM_REGS_AQSFRC_OTSFA_Msk    (0x1U << EPWM_REGS_AQSFRC_OTSFA_Pos)                                                  /*!< OTSFA Mask      0x00000004 */
#define EPWM_REGS_AQSFRC_OTSFA_Set(x) (((uint16_t) (x) << EPWM_REGS_AQSFRC_OTSFA_Pos) & EPWM_REGS_AQSFRC_OTSFA_Msk)         /*!< OTSFA Set Value            */
#define EPWM_REGS_AQSFRC_OTSFA_Get(x) (((uint16_t) (x) & EPWM_REGS_AQSFRC_OTSFA_Msk) >> EPWM_REGS_AQSFRC_OTSFA_Pos)         /*!< OTSFA Get Value            */


#define EPWM_REGS_AQSFRC_ACTSFA_Pos    (0U)                                                                                  /*!< ACTSFA Postion   0          */ 
#define EPWM_REGS_AQSFRC_ACTSFA_Msk    (0x3U << EPWM_REGS_AQSFRC_ACTSFA_Pos)                                                 /*!< ACTSFA Mask      0x00000003 */
#define EPWM_REGS_AQSFRC_ACTSFA_Set(x) (((uint16_t) (x) << EPWM_REGS_AQSFRC_ACTSFA_Pos) & EPWM_REGS_AQSFRC_ACTSFA_Msk)       /*!< ACTSFA Set Value            */
#define EPWM_REGS_AQSFRC_ACTSFA_Get(x) (((uint16_t) (x) & EPWM_REGS_AQSFRC_ACTSFA_Msk) >> EPWM_REGS_AQSFRC_ACTSFA_Pos)       /*!< ACTSFA Get Value            */


/* AQCSFRC bitfield */
#define EPWM_REGS_AQCSFRC_CSFB_Pos    (2U)                                                                                  /*!< CSFB Postion   2          */ 
#define EPWM_REGS_AQCSFRC_CSFB_Msk    (0x3U << EPWM_REGS_AQCSFRC_CSFB_Pos)                                                  /*!< CSFB Mask      0x0000000C */
#define EPWM_REGS_AQCSFRC_CSFB_Set(x) (((uint16_t) (x) << EPWM_REGS_AQCSFRC_CSFB_Pos) & EPWM_REGS_AQCSFRC_CSFB_Msk)         /*!< CSFB Set Value            */
#define EPWM_REGS_AQCSFRC_CSFB_Get(x) (((uint16_t) (x) & EPWM_REGS_AQCSFRC_CSFB_Msk) >> EPWM_REGS_AQCSFRC_CSFB_Pos)         /*!< CSFB Get Value            */


#define EPWM_REGS_AQCSFRC_CSFA_Pos    (0U)                                                                                  /*!< CSFA Postion   0          */ 
#define EPWM_REGS_AQCSFRC_CSFA_Msk    (0x3U << EPWM_REGS_AQCSFRC_CSFA_Pos)                                                  /*!< CSFA Mask      0x00000003 */
#define EPWM_REGS_AQCSFRC_CSFA_Set(x) (((uint16_t) (x) << EPWM_REGS_AQCSFRC_CSFA_Pos) & EPWM_REGS_AQCSFRC_CSFA_Msk)         /*!< CSFA Set Value            */
#define EPWM_REGS_AQCSFRC_CSFA_Get(x) (((uint16_t) (x) & EPWM_REGS_AQCSFRC_CSFA_Msk) >> EPWM_REGS_AQCSFRC_CSFA_Pos)         /*!< CSFA Get Value            */


/* DBRED bitfield */
#define EPWM_REGS_DBRED_DBRED_Pos    (0U)                                                                                  /*!< DBRED Postion   0          */ 
#define EPWM_REGS_DBRED_DBRED_Msk    (0x3fffU << EPWM_REGS_DBRED_DBRED_Pos)                                                /*!< DBRED Mask      0x00003FFF */
#define EPWM_REGS_DBRED_DBRED_Set(x) (((uint16_t) (x) << EPWM_REGS_DBRED_DBRED_Pos) & EPWM_REGS_DBRED_DBRED_Msk)           /*!< DBRED Set Value            */
#define EPWM_REGS_DBRED_DBRED_Get(x) (((uint16_t) (x) & EPWM_REGS_DBRED_DBRED_Msk) >> EPWM_REGS_DBRED_DBRED_Pos)           /*!< DBRED Get Value            */


/* DBFED bitfield */
#define EPWM_REGS_DBFED_DBFED_Pos    (0U)                                                                                  /*!< DBFED Postion   0          */ 
#define EPWM_REGS_DBFED_DBFED_Msk    (0x3fffU << EPWM_REGS_DBFED_DBFED_Pos)                                                /*!< DBFED Mask      0x00003FFF */
#define EPWM_REGS_DBFED_DBFED_Set(x) (((uint16_t) (x) << EPWM_REGS_DBFED_DBFED_Pos) & EPWM_REGS_DBFED_DBFED_Msk)           /*!< DBFED Set Value            */
#define EPWM_REGS_DBFED_DBFED_Get(x) (((uint16_t) (x) & EPWM_REGS_DBFED_DBFED_Msk) >> EPWM_REGS_DBFED_DBFED_Pos)           /*!< DBFED Get Value            */


/* TBPHS bitfield */
#define EPWM_REGS_TBPHS_TBPHS_Pos    (16U)                                                                                 /*!< TBPHS Postion   16         */ 
#define EPWM_REGS_TBPHS_TBPHS_Msk    (0xffffU << EPWM_REGS_TBPHS_TBPHS_Pos)                                                /*!< TBPHS Mask      0xFFFF0000 */
#define EPWM_REGS_TBPHS_TBPHS_Set(x) (((uint32_t) (x) << EPWM_REGS_TBPHS_TBPHS_Pos) & EPWM_REGS_TBPHS_TBPHS_Msk)           /*!< TBPHS Set Value            */
#define EPWM_REGS_TBPHS_TBPHS_Get(x) (((uint32_t) (x) & EPWM_REGS_TBPHS_TBPHS_Msk) >> EPWM_REGS_TBPHS_TBPHS_Pos)           /*!< TBPHS Get Value            */


/* TBPRD bitfield */
#define EPWM_REGS_TBPRD_TBPRD_Pos    (16U)                                                                                 /*!< TBPRD Postion   16         */ 
#define EPWM_REGS_TBPRD_TBPRD_Msk    (0xffffU << EPWM_REGS_TBPRD_TBPRD_Pos)                                                /*!< TBPRD Mask      0xFFFF0000 */
#define EPWM_REGS_TBPRD_TBPRD_Set(x) (((uint32_t) (x) << EPWM_REGS_TBPRD_TBPRD_Pos) & EPWM_REGS_TBPRD_TBPRD_Msk)           /*!< TBPRD Set Value            */
#define EPWM_REGS_TBPRD_TBPRD_Get(x) (((uint32_t) (x) & EPWM_REGS_TBPRD_TBPRD_Msk) >> EPWM_REGS_TBPRD_TBPRD_Pos)           /*!< TBPRD Get Value            */


/* CMPA bitfield */
#define EPWM_REGS_CMPA_CMPA_Pos    (16U)                                                                                 /*!< CMPA Postion   16         */ 
#define EPWM_REGS_CMPA_CMPA_Msk    (0xffffU << EPWM_REGS_CMPA_CMPA_Pos)                                                  /*!< CMPA Mask      0xFFFF0000 */
#define EPWM_REGS_CMPA_CMPA_Set(x) (((uint32_t) (x) << EPWM_REGS_CMPA_CMPA_Pos) & EPWM_REGS_CMPA_CMPA_Msk)               /*!< CMPA Set Value            */
#define EPWM_REGS_CMPA_CMPA_Get(x) (((uint32_t) (x) & EPWM_REGS_CMPA_CMPA_Msk) >> EPWM_REGS_CMPA_CMPA_Pos)               /*!< CMPA Get Value            */


/* CMPB bitfield */
#define EPWM_REGS_CMPB_CMPB_Pos    (16U)                                                                                 /*!< CMPB Postion   16         */ 
#define EPWM_REGS_CMPB_CMPB_Msk    (0xffffU << EPWM_REGS_CMPB_CMPB_Pos)                                                  /*!< CMPB Mask      0xFFFF0000 */
#define EPWM_REGS_CMPB_CMPB_Set(x) (((uint32_t) (x) << EPWM_REGS_CMPB_CMPB_Pos) & EPWM_REGS_CMPB_CMPB_Msk)               /*!< CMPB Set Value            */
#define EPWM_REGS_CMPB_CMPB_Get(x) (((uint32_t) (x) & EPWM_REGS_CMPB_CMPB_Msk) >> EPWM_REGS_CMPB_CMPB_Pos)               /*!< CMPB Get Value            */


/* CMPC bitfield */
#define EPWM_REGS_CMPC_CMPC_Pos    (0U)                                                                                  /*!< CMPC Postion   0          */ 
#define EPWM_REGS_CMPC_CMPC_Msk    (0xffffU << EPWM_REGS_CMPC_CMPC_Pos)                                                  /*!< CMPC Mask      0x0000FFFF */
#define EPWM_REGS_CMPC_CMPC_Set(x) (((uint16_t) (x) << EPWM_REGS_CMPC_CMPC_Pos) & EPWM_REGS_CMPC_CMPC_Msk)               /*!< CMPC Set Value            */
#define EPWM_REGS_CMPC_CMPC_Get(x) (((uint16_t) (x) & EPWM_REGS_CMPC_CMPC_Msk) >> EPWM_REGS_CMPC_CMPC_Pos)               /*!< CMPC Get Value            */


/* CMPD bitfield */
#define EPWM_REGS_CMPD_CMPD_Pos    (0U)                                                                                  /*!< CMPD Postion   0          */ 
#define EPWM_REGS_CMPD_CMPD_Msk    (0xffffU << EPWM_REGS_CMPD_CMPD_Pos)                                                  /*!< CMPD Mask      0x0000FFFF */
#define EPWM_REGS_CMPD_CMPD_Set(x) (((uint16_t) (x) << EPWM_REGS_CMPD_CMPD_Pos) & EPWM_REGS_CMPD_CMPD_Msk)               /*!< CMPD Set Value            */
#define EPWM_REGS_CMPD_CMPD_Get(x) (((uint16_t) (x) & EPWM_REGS_CMPD_CMPD_Msk) >> EPWM_REGS_CMPD_CMPD_Pos)               /*!< CMPD Get Value            */


/* GLDCTL2 bitfield */
#define EPWM_REGS_GLDCTL2_GFRCLD_Pos    (1U)                                                                                  /*!< GFRCLD Postion   1          */ 
#define EPWM_REGS_GLDCTL2_GFRCLD_Msk    (0x1U << EPWM_REGS_GLDCTL2_GFRCLD_Pos)                                                /*!< GFRCLD Mask      0x00000002 */
#define EPWM_REGS_GLDCTL2_GFRCLD_Set(x) (((uint32_t) (x) << EPWM_REGS_GLDCTL2_GFRCLD_Pos) & EPWM_REGS_GLDCTL2_GFRCLD_Msk)     /*!< GFRCLD Set Value            */
#define EPWM_REGS_GLDCTL2_GFRCLD_Get(x) (((uint32_t) (x) & EPWM_REGS_GLDCTL2_GFRCLD_Msk) >> EPWM_REGS_GLDCTL2_GFRCLD_Pos)     /*!< GFRCLD Get Value            */


#define EPWM_REGS_GLDCTL2_OSHTLD_Pos    (0U)                                                                                  /*!< OSHTLD Postion   0          */ 
#define EPWM_REGS_GLDCTL2_OSHTLD_Msk    (0x1U << EPWM_REGS_GLDCTL2_OSHTLD_Pos)                                                /*!< OSHTLD Mask      0x00000001 */
#define EPWM_REGS_GLDCTL2_OSHTLD_Set(x) (((uint32_t) (x) << EPWM_REGS_GLDCTL2_OSHTLD_Pos) & EPWM_REGS_GLDCTL2_OSHTLD_Msk)     /*!< OSHTLD Set Value            */
#define EPWM_REGS_GLDCTL2_OSHTLD_Get(x) (((uint32_t) (x) & EPWM_REGS_GLDCTL2_OSHTLD_Msk) >> EPWM_REGS_GLDCTL2_OSHTLD_Pos)     /*!< OSHTLD Get Value            */


/* SWVDELVAL bitfield */
#define EPWM_REGS_SWVDELVAL_SWVDELVAL_Pos    (0U)                                                                                  /*!< SWVDELVAL Postion   0          */ 
#define EPWM_REGS_SWVDELVAL_SWVDELVAL_Msk    (0xffffU << EPWM_REGS_SWVDELVAL_SWVDELVAL_Pos)                                        /*!< SWVDELVAL Mask      0x0000FFFF */
#define EPWM_REGS_SWVDELVAL_SWVDELVAL_Set(x) (((uint16_t) (x) << EPWM_REGS_SWVDELVAL_SWVDELVAL_Pos) & EPWM_REGS_SWVDELVAL_SWVDELVAL_Msk) /*!< SWVDELVAL Set Value            */
#define EPWM_REGS_SWVDELVAL_SWVDELVAL_Get(x) (((uint16_t) (x) & EPWM_REGS_SWVDELVAL_SWVDELVAL_Msk) >> EPWM_REGS_SWVDELVAL_SWVDELVAL_Pos) /*!< SWVDELVAL Get Value            */


/* TZSEL bitfield */
#define EPWM_REGS_TZSEL_DCBEVT1_Pos    (15U)                                                                                 /*!< DCBEVT1 Postion   15         */ 
#define EPWM_REGS_TZSEL_DCBEVT1_Msk    (0x1U << EPWM_REGS_TZSEL_DCBEVT1_Pos)                                                 /*!< DCBEVT1 Mask      0x00008000 */
#define EPWM_REGS_TZSEL_DCBEVT1_Set(x) (((uint32_t) (x) << EPWM_REGS_TZSEL_DCBEVT1_Pos) & EPWM_REGS_TZSEL_DCBEVT1_Msk)       /*!< DCBEVT1 Set Value            */
#define EPWM_REGS_TZSEL_DCBEVT1_Get(x) (((uint32_t) (x) & EPWM_REGS_TZSEL_DCBEVT1_Msk) >> EPWM_REGS_TZSEL_DCBEVT1_Pos)       /*!< DCBEVT1 Get Value            */


#define EPWM_REGS_TZSEL_DCAEVT1_Pos    (14U)                                                                                 /*!< DCAEVT1 Postion   14         */ 
#define EPWM_REGS_TZSEL_DCAEVT1_Msk    (0x1U << EPWM_REGS_TZSEL_DCAEVT1_Pos)                                                 /*!< DCAEVT1 Mask      0x00004000 */
#define EPWM_REGS_TZSEL_DCAEVT1_Set(x) (((uint32_t) (x) << EPWM_REGS_TZSEL_DCAEVT1_Pos) & EPWM_REGS_TZSEL_DCAEVT1_Msk)       /*!< DCAEVT1 Set Value            */
#define EPWM_REGS_TZSEL_DCAEVT1_Get(x) (((uint32_t) (x) & EPWM_REGS_TZSEL_DCAEVT1_Msk) >> EPWM_REGS_TZSEL_DCAEVT1_Pos)       /*!< DCAEVT1 Get Value            */


#define EPWM_REGS_TZSEL_OSHT6_Pos    (13U)                                                                                 /*!< OSHT6 Postion   13         */ 
#define EPWM_REGS_TZSEL_OSHT6_Msk    (0x1U << EPWM_REGS_TZSEL_OSHT6_Pos)                                                   /*!< OSHT6 Mask      0x00002000 */
#define EPWM_REGS_TZSEL_OSHT6_Set(x) (((uint32_t) (x) << EPWM_REGS_TZSEL_OSHT6_Pos) & EPWM_REGS_TZSEL_OSHT6_Msk)           /*!< OSHT6 Set Value            */
#define EPWM_REGS_TZSEL_OSHT6_Get(x) (((uint32_t) (x) & EPWM_REGS_TZSEL_OSHT6_Msk) >> EPWM_REGS_TZSEL_OSHT6_Pos)           /*!< OSHT6 Get Value            */


#define EPWM_REGS_TZSEL_OSHT5_Pos    (12U)                                                                                 /*!< OSHT5 Postion   12         */ 
#define EPWM_REGS_TZSEL_OSHT5_Msk    (0x1U << EPWM_REGS_TZSEL_OSHT5_Pos)                                                   /*!< OSHT5 Mask      0x00001000 */
#define EPWM_REGS_TZSEL_OSHT5_Set(x) (((uint32_t) (x) << EPWM_REGS_TZSEL_OSHT5_Pos) & EPWM_REGS_TZSEL_OSHT5_Msk)           /*!< OSHT5 Set Value            */
#define EPWM_REGS_TZSEL_OSHT5_Get(x) (((uint32_t) (x) & EPWM_REGS_TZSEL_OSHT5_Msk) >> EPWM_REGS_TZSEL_OSHT5_Pos)           /*!< OSHT5 Get Value            */


#define EPWM_REGS_TZSEL_OSHT4_Pos    (11U)                                                                                 /*!< OSHT4 Postion   11         */ 
#define EPWM_REGS_TZSEL_OSHT4_Msk    (0x1U << EPWM_REGS_TZSEL_OSHT4_Pos)                                                   /*!< OSHT4 Mask      0x00000800 */
#define EPWM_REGS_TZSEL_OSHT4_Set(x) (((uint32_t) (x) << EPWM_REGS_TZSEL_OSHT4_Pos) & EPWM_REGS_TZSEL_OSHT4_Msk)           /*!< OSHT4 Set Value            */
#define EPWM_REGS_TZSEL_OSHT4_Get(x) (((uint32_t) (x) & EPWM_REGS_TZSEL_OSHT4_Msk) >> EPWM_REGS_TZSEL_OSHT4_Pos)           /*!< OSHT4 Get Value            */


#define EPWM_REGS_TZSEL_OSHT3_Pos    (10U)                                                                                 /*!< OSHT3 Postion   10         */ 
#define EPWM_REGS_TZSEL_OSHT3_Msk    (0x1U << EPWM_REGS_TZSEL_OSHT3_Pos)                                                   /*!< OSHT3 Mask      0x00000400 */
#define EPWM_REGS_TZSEL_OSHT3_Set(x) (((uint32_t) (x) << EPWM_REGS_TZSEL_OSHT3_Pos) & EPWM_REGS_TZSEL_OSHT3_Msk)           /*!< OSHT3 Set Value            */
#define EPWM_REGS_TZSEL_OSHT3_Get(x) (((uint32_t) (x) & EPWM_REGS_TZSEL_OSHT3_Msk) >> EPWM_REGS_TZSEL_OSHT3_Pos)           /*!< OSHT3 Get Value            */


#define EPWM_REGS_TZSEL_OSHT2_Pos    (9U)                                                                                  /*!< OSHT2 Postion   9          */ 
#define EPWM_REGS_TZSEL_OSHT2_Msk    (0x1U << EPWM_REGS_TZSEL_OSHT2_Pos)                                                   /*!< OSHT2 Mask      0x00000200 */
#define EPWM_REGS_TZSEL_OSHT2_Set(x) (((uint32_t) (x) << EPWM_REGS_TZSEL_OSHT2_Pos) & EPWM_REGS_TZSEL_OSHT2_Msk)           /*!< OSHT2 Set Value            */
#define EPWM_REGS_TZSEL_OSHT2_Get(x) (((uint32_t) (x) & EPWM_REGS_TZSEL_OSHT2_Msk) >> EPWM_REGS_TZSEL_OSHT2_Pos)           /*!< OSHT2 Get Value            */


#define EPWM_REGS_TZSEL_OSHT1_Pos    (8U)                                                                                  /*!< OSHT1 Postion   8          */ 
#define EPWM_REGS_TZSEL_OSHT1_Msk    (0x1U << EPWM_REGS_TZSEL_OSHT1_Pos)                                                   /*!< OSHT1 Mask      0x00000100 */
#define EPWM_REGS_TZSEL_OSHT1_Set(x) (((uint32_t) (x) << EPWM_REGS_TZSEL_OSHT1_Pos) & EPWM_REGS_TZSEL_OSHT1_Msk)           /*!< OSHT1 Set Value            */
#define EPWM_REGS_TZSEL_OSHT1_Get(x) (((uint32_t) (x) & EPWM_REGS_TZSEL_OSHT1_Msk) >> EPWM_REGS_TZSEL_OSHT1_Pos)           /*!< OSHT1 Get Value            */


#define EPWM_REGS_TZSEL_DCBEVT2_Pos    (7U)                                                                                  /*!< DCBEVT2 Postion   7          */ 
#define EPWM_REGS_TZSEL_DCBEVT2_Msk    (0x1U << EPWM_REGS_TZSEL_DCBEVT2_Pos)                                                 /*!< DCBEVT2 Mask      0x00000080 */
#define EPWM_REGS_TZSEL_DCBEVT2_Set(x) (((uint32_t) (x) << EPWM_REGS_TZSEL_DCBEVT2_Pos) & EPWM_REGS_TZSEL_DCBEVT2_Msk)       /*!< DCBEVT2 Set Value            */
#define EPWM_REGS_TZSEL_DCBEVT2_Get(x) (((uint32_t) (x) & EPWM_REGS_TZSEL_DCBEVT2_Msk) >> EPWM_REGS_TZSEL_DCBEVT2_Pos)       /*!< DCBEVT2 Get Value            */


#define EPWM_REGS_TZSEL_DCAEVT2_Pos    (6U)                                                                                  /*!< DCAEVT2 Postion   6          */ 
#define EPWM_REGS_TZSEL_DCAEVT2_Msk    (0x1U << EPWM_REGS_TZSEL_DCAEVT2_Pos)                                                 /*!< DCAEVT2 Mask      0x00000040 */
#define EPWM_REGS_TZSEL_DCAEVT2_Set(x) (((uint32_t) (x) << EPWM_REGS_TZSEL_DCAEVT2_Pos) & EPWM_REGS_TZSEL_DCAEVT2_Msk)       /*!< DCAEVT2 Set Value            */
#define EPWM_REGS_TZSEL_DCAEVT2_Get(x) (((uint32_t) (x) & EPWM_REGS_TZSEL_DCAEVT2_Msk) >> EPWM_REGS_TZSEL_DCAEVT2_Pos)       /*!< DCAEVT2 Get Value            */


#define EPWM_REGS_TZSEL_CBC6_Pos    (5U)                                                                                  /*!< CBC6 Postion   5          */ 
#define EPWM_REGS_TZSEL_CBC6_Msk    (0x1U << EPWM_REGS_TZSEL_CBC6_Pos)                                                    /*!< CBC6 Mask      0x00000020 */
#define EPWM_REGS_TZSEL_CBC6_Set(x) (((uint32_t) (x) << EPWM_REGS_TZSEL_CBC6_Pos) & EPWM_REGS_TZSEL_CBC6_Msk)             /*!< CBC6 Set Value            */
#define EPWM_REGS_TZSEL_CBC6_Get(x) (((uint32_t) (x) & EPWM_REGS_TZSEL_CBC6_Msk) >> EPWM_REGS_TZSEL_CBC6_Pos)             /*!< CBC6 Get Value            */


#define EPWM_REGS_TZSEL_CBC5_Pos    (4U)                                                                                  /*!< CBC5 Postion   4          */ 
#define EPWM_REGS_TZSEL_CBC5_Msk    (0x1U << EPWM_REGS_TZSEL_CBC5_Pos)                                                    /*!< CBC5 Mask      0x00000010 */
#define EPWM_REGS_TZSEL_CBC5_Set(x) (((uint32_t) (x) << EPWM_REGS_TZSEL_CBC5_Pos) & EPWM_REGS_TZSEL_CBC5_Msk)             /*!< CBC5 Set Value            */
#define EPWM_REGS_TZSEL_CBC5_Get(x) (((uint32_t) (x) & EPWM_REGS_TZSEL_CBC5_Msk) >> EPWM_REGS_TZSEL_CBC5_Pos)             /*!< CBC5 Get Value            */


#define EPWM_REGS_TZSEL_CBC4_Pos    (3U)                                                                                  /*!< CBC4 Postion   3          */ 
#define EPWM_REGS_TZSEL_CBC4_Msk    (0x1U << EPWM_REGS_TZSEL_CBC4_Pos)                                                    /*!< CBC4 Mask      0x00000008 */
#define EPWM_REGS_TZSEL_CBC4_Set(x) (((uint32_t) (x) << EPWM_REGS_TZSEL_CBC4_Pos) & EPWM_REGS_TZSEL_CBC4_Msk)             /*!< CBC4 Set Value            */
#define EPWM_REGS_TZSEL_CBC4_Get(x) (((uint32_t) (x) & EPWM_REGS_TZSEL_CBC4_Msk) >> EPWM_REGS_TZSEL_CBC4_Pos)             /*!< CBC4 Get Value            */


#define EPWM_REGS_TZSEL_CBC3_Pos    (2U)                                                                                  /*!< CBC3 Postion   2          */ 
#define EPWM_REGS_TZSEL_CBC3_Msk    (0x1U << EPWM_REGS_TZSEL_CBC3_Pos)                                                    /*!< CBC3 Mask      0x00000004 */
#define EPWM_REGS_TZSEL_CBC3_Set(x) (((uint32_t) (x) << EPWM_REGS_TZSEL_CBC3_Pos) & EPWM_REGS_TZSEL_CBC3_Msk)             /*!< CBC3 Set Value            */
#define EPWM_REGS_TZSEL_CBC3_Get(x) (((uint32_t) (x) & EPWM_REGS_TZSEL_CBC3_Msk) >> EPWM_REGS_TZSEL_CBC3_Pos)             /*!< CBC3 Get Value            */


#define EPWM_REGS_TZSEL_CBC2_Pos    (1U)                                                                                  /*!< CBC2 Postion   1          */ 
#define EPWM_REGS_TZSEL_CBC2_Msk    (0x1U << EPWM_REGS_TZSEL_CBC2_Pos)                                                    /*!< CBC2 Mask      0x00000002 */
#define EPWM_REGS_TZSEL_CBC2_Set(x) (((uint32_t) (x) << EPWM_REGS_TZSEL_CBC2_Pos) & EPWM_REGS_TZSEL_CBC2_Msk)             /*!< CBC2 Set Value            */
#define EPWM_REGS_TZSEL_CBC2_Get(x) (((uint32_t) (x) & EPWM_REGS_TZSEL_CBC2_Msk) >> EPWM_REGS_TZSEL_CBC2_Pos)             /*!< CBC2 Get Value            */


#define EPWM_REGS_TZSEL_CBC1_Pos    (0U)                                                                                  /*!< CBC1 Postion   0          */ 
#define EPWM_REGS_TZSEL_CBC1_Msk    (0x1U << EPWM_REGS_TZSEL_CBC1_Pos)                                                    /*!< CBC1 Mask      0x00000001 */
#define EPWM_REGS_TZSEL_CBC1_Set(x) (((uint32_t) (x) << EPWM_REGS_TZSEL_CBC1_Pos) & EPWM_REGS_TZSEL_CBC1_Msk)             /*!< CBC1 Set Value            */
#define EPWM_REGS_TZSEL_CBC1_Get(x) (((uint32_t) (x) & EPWM_REGS_TZSEL_CBC1_Msk) >> EPWM_REGS_TZSEL_CBC1_Pos)             /*!< CBC1 Get Value            */


/* TZDCSEL bitfield */
#define EPWM_REGS_TZDCSEL_DCBEVT2_Pos    (9U)                                                                                  /*!< DCBEVT2 Postion   9          */ 
#define EPWM_REGS_TZDCSEL_DCBEVT2_Msk    (0x7U << EPWM_REGS_TZDCSEL_DCBEVT2_Pos)                                               /*!< DCBEVT2 Mask      0x00000E00 */
#define EPWM_REGS_TZDCSEL_DCBEVT2_Set(x) (((uint32_t) (x) << EPWM_REGS_TZDCSEL_DCBEVT2_Pos) & EPWM_REGS_TZDCSEL_DCBEVT2_Msk)   /*!< DCBEVT2 Set Value            */
#define EPWM_REGS_TZDCSEL_DCBEVT2_Get(x) (((uint32_t) (x) & EPWM_REGS_TZDCSEL_DCBEVT2_Msk) >> EPWM_REGS_TZDCSEL_DCBEVT2_Pos)   /*!< DCBEVT2 Get Value            */


#define EPWM_REGS_TZDCSEL_DCBEVT1_Pos    (6U)                                                                                  /*!< DCBEVT1 Postion   6          */ 
#define EPWM_REGS_TZDCSEL_DCBEVT1_Msk    (0x7U << EPWM_REGS_TZDCSEL_DCBEVT1_Pos)                                               /*!< DCBEVT1 Mask      0x000001C0 */
#define EPWM_REGS_TZDCSEL_DCBEVT1_Set(x) (((uint32_t) (x) << EPWM_REGS_TZDCSEL_DCBEVT1_Pos) & EPWM_REGS_TZDCSEL_DCBEVT1_Msk)   /*!< DCBEVT1 Set Value            */
#define EPWM_REGS_TZDCSEL_DCBEVT1_Get(x) (((uint32_t) (x) & EPWM_REGS_TZDCSEL_DCBEVT1_Msk) >> EPWM_REGS_TZDCSEL_DCBEVT1_Pos)   /*!< DCBEVT1 Get Value            */


#define EPWM_REGS_TZDCSEL_DCAEVT2_Pos    (3U)                                                                                  /*!< DCAEVT2 Postion   3          */ 
#define EPWM_REGS_TZDCSEL_DCAEVT2_Msk    (0x7U << EPWM_REGS_TZDCSEL_DCAEVT2_Pos)                                               /*!< DCAEVT2 Mask      0x00000038 */
#define EPWM_REGS_TZDCSEL_DCAEVT2_Set(x) (((uint32_t) (x) << EPWM_REGS_TZDCSEL_DCAEVT2_Pos) & EPWM_REGS_TZDCSEL_DCAEVT2_Msk)   /*!< DCAEVT2 Set Value            */
#define EPWM_REGS_TZDCSEL_DCAEVT2_Get(x) (((uint32_t) (x) & EPWM_REGS_TZDCSEL_DCAEVT2_Msk) >> EPWM_REGS_TZDCSEL_DCAEVT2_Pos)   /*!< DCAEVT2 Get Value            */


#define EPWM_REGS_TZDCSEL_DCAEVT1_Pos    (0U)                                                                                  /*!< DCAEVT1 Postion   0          */ 
#define EPWM_REGS_TZDCSEL_DCAEVT1_Msk    (0x7U << EPWM_REGS_TZDCSEL_DCAEVT1_Pos)                                               /*!< DCAEVT1 Mask      0x00000007 */
#define EPWM_REGS_TZDCSEL_DCAEVT1_Set(x) (((uint32_t) (x) << EPWM_REGS_TZDCSEL_DCAEVT1_Pos) & EPWM_REGS_TZDCSEL_DCAEVT1_Msk)   /*!< DCAEVT1 Set Value            */
#define EPWM_REGS_TZDCSEL_DCAEVT1_Get(x) (((uint32_t) (x) & EPWM_REGS_TZDCSEL_DCAEVT1_Msk) >> EPWM_REGS_TZDCSEL_DCAEVT1_Pos)   /*!< DCAEVT1 Get Value            */


/* TZCTL bitfield */
#define EPWM_REGS_TZCTL_DCBEVT2_Pos    (10U)                                                                                 /*!< DCBEVT2 Postion   10         */ 
#define EPWM_REGS_TZCTL_DCBEVT2_Msk    (0x3U << EPWM_REGS_TZCTL_DCBEVT2_Pos)                                                 /*!< DCBEVT2 Mask      0x00000C00 */
#define EPWM_REGS_TZCTL_DCBEVT2_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCTL_DCBEVT2_Pos) & EPWM_REGS_TZCTL_DCBEVT2_Msk)       /*!< DCBEVT2 Set Value            */
#define EPWM_REGS_TZCTL_DCBEVT2_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCTL_DCBEVT2_Msk) >> EPWM_REGS_TZCTL_DCBEVT2_Pos)       /*!< DCBEVT2 Get Value            */


#define EPWM_REGS_TZCTL_DCBEVT1_Pos    (8U)                                                                                  /*!< DCBEVT1 Postion   8          */ 
#define EPWM_REGS_TZCTL_DCBEVT1_Msk    (0x3U << EPWM_REGS_TZCTL_DCBEVT1_Pos)                                                 /*!< DCBEVT1 Mask      0x00000300 */
#define EPWM_REGS_TZCTL_DCBEVT1_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCTL_DCBEVT1_Pos) & EPWM_REGS_TZCTL_DCBEVT1_Msk)       /*!< DCBEVT1 Set Value            */
#define EPWM_REGS_TZCTL_DCBEVT1_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCTL_DCBEVT1_Msk) >> EPWM_REGS_TZCTL_DCBEVT1_Pos)       /*!< DCBEVT1 Get Value            */


#define EPWM_REGS_TZCTL_DCAEVT2_Pos    (6U)                                                                                  /*!< DCAEVT2 Postion   6          */ 
#define EPWM_REGS_TZCTL_DCAEVT2_Msk    (0x3U << EPWM_REGS_TZCTL_DCAEVT2_Pos)                                                 /*!< DCAEVT2 Mask      0x000000C0 */
#define EPWM_REGS_TZCTL_DCAEVT2_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCTL_DCAEVT2_Pos) & EPWM_REGS_TZCTL_DCAEVT2_Msk)       /*!< DCAEVT2 Set Value            */
#define EPWM_REGS_TZCTL_DCAEVT2_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCTL_DCAEVT2_Msk) >> EPWM_REGS_TZCTL_DCAEVT2_Pos)       /*!< DCAEVT2 Get Value            */


#define EPWM_REGS_TZCTL_DCAEVT1_Pos    (4U)                                                                                  /*!< DCAEVT1 Postion   4          */ 
#define EPWM_REGS_TZCTL_DCAEVT1_Msk    (0x3U << EPWM_REGS_TZCTL_DCAEVT1_Pos)                                                 /*!< DCAEVT1 Mask      0x00000030 */
#define EPWM_REGS_TZCTL_DCAEVT1_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCTL_DCAEVT1_Pos) & EPWM_REGS_TZCTL_DCAEVT1_Msk)       /*!< DCAEVT1 Set Value            */
#define EPWM_REGS_TZCTL_DCAEVT1_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCTL_DCAEVT1_Msk) >> EPWM_REGS_TZCTL_DCAEVT1_Pos)       /*!< DCAEVT1 Get Value            */


#define EPWM_REGS_TZCTL_TZB_Pos    (2U)                                                                                  /*!< TZB Postion   2          */ 
#define EPWM_REGS_TZCTL_TZB_Msk    (0x3U << EPWM_REGS_TZCTL_TZB_Pos)                                                     /*!< TZB Mask      0x0000000C */
#define EPWM_REGS_TZCTL_TZB_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCTL_TZB_Pos) & EPWM_REGS_TZCTL_TZB_Msk)               /*!< TZB Set Value            */
#define EPWM_REGS_TZCTL_TZB_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCTL_TZB_Msk) >> EPWM_REGS_TZCTL_TZB_Pos)               /*!< TZB Get Value            */


#define EPWM_REGS_TZCTL_TZA_Pos    (0U)                                                                                  /*!< TZA Postion   0          */ 
#define EPWM_REGS_TZCTL_TZA_Msk    (0x3U << EPWM_REGS_TZCTL_TZA_Pos)                                                     /*!< TZA Mask      0x00000003 */
#define EPWM_REGS_TZCTL_TZA_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCTL_TZA_Pos) & EPWM_REGS_TZCTL_TZA_Msk)               /*!< TZA Set Value            */
#define EPWM_REGS_TZCTL_TZA_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCTL_TZA_Msk) >> EPWM_REGS_TZCTL_TZA_Pos)               /*!< TZA Get Value            */


/* TZCTL2 bitfield */
#define EPWM_REGS_TZCTL2_ETZE_Pos    (15U)                                                                                 /*!< ETZE Postion   15         */ 
#define EPWM_REGS_TZCTL2_ETZE_Msk    (0x1U << EPWM_REGS_TZCTL2_ETZE_Pos)                                                   /*!< ETZE Mask      0x00008000 */
#define EPWM_REGS_TZCTL2_ETZE_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCTL2_ETZE_Pos) & EPWM_REGS_TZCTL2_ETZE_Msk)           /*!< ETZE Set Value            */
#define EPWM_REGS_TZCTL2_ETZE_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCTL2_ETZE_Msk) >> EPWM_REGS_TZCTL2_ETZE_Pos)           /*!< ETZE Get Value            */


#define EPWM_REGS_TZCTL2_TZBD_Pos    (9U)                                                                                  /*!< TZBD Postion   9          */ 
#define EPWM_REGS_TZCTL2_TZBD_Msk    (0x7U << EPWM_REGS_TZCTL2_TZBD_Pos)                                                   /*!< TZBD Mask      0x00000E00 */
#define EPWM_REGS_TZCTL2_TZBD_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCTL2_TZBD_Pos) & EPWM_REGS_TZCTL2_TZBD_Msk)           /*!< TZBD Set Value            */
#define EPWM_REGS_TZCTL2_TZBD_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCTL2_TZBD_Msk) >> EPWM_REGS_TZCTL2_TZBD_Pos)           /*!< TZBD Get Value            */


#define EPWM_REGS_TZCTL2_TZBU_Pos    (6U)                                                                                  /*!< TZBU Postion   6          */ 
#define EPWM_REGS_TZCTL2_TZBU_Msk    (0x7U << EPWM_REGS_TZCTL2_TZBU_Pos)                                                   /*!< TZBU Mask      0x000001C0 */
#define EPWM_REGS_TZCTL2_TZBU_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCTL2_TZBU_Pos) & EPWM_REGS_TZCTL2_TZBU_Msk)           /*!< TZBU Set Value            */
#define EPWM_REGS_TZCTL2_TZBU_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCTL2_TZBU_Msk) >> EPWM_REGS_TZCTL2_TZBU_Pos)           /*!< TZBU Get Value            */


#define EPWM_REGS_TZCTL2_TZAD_Pos    (3U)                                                                                  /*!< TZAD Postion   3          */ 
#define EPWM_REGS_TZCTL2_TZAD_Msk    (0x7U << EPWM_REGS_TZCTL2_TZAD_Pos)                                                   /*!< TZAD Mask      0x00000038 */
#define EPWM_REGS_TZCTL2_TZAD_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCTL2_TZAD_Pos) & EPWM_REGS_TZCTL2_TZAD_Msk)           /*!< TZAD Set Value            */
#define EPWM_REGS_TZCTL2_TZAD_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCTL2_TZAD_Msk) >> EPWM_REGS_TZCTL2_TZAD_Pos)           /*!< TZAD Get Value            */


#define EPWM_REGS_TZCTL2_TZAU_Pos    (0U)                                                                                  /*!< TZAU Postion   0          */ 
#define EPWM_REGS_TZCTL2_TZAU_Msk    (0x7U << EPWM_REGS_TZCTL2_TZAU_Pos)                                                   /*!< TZAU Mask      0x00000007 */
#define EPWM_REGS_TZCTL2_TZAU_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCTL2_TZAU_Pos) & EPWM_REGS_TZCTL2_TZAU_Msk)           /*!< TZAU Set Value            */
#define EPWM_REGS_TZCTL2_TZAU_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCTL2_TZAU_Msk) >> EPWM_REGS_TZCTL2_TZAU_Pos)           /*!< TZAU Get Value            */


/* TZCTLDCA bitfield */
#define EPWM_REGS_TZCTLDCA_DCAEVT2D_Pos    (9U)                                                                                  /*!< DCAEVT2D Postion   9          */ 
#define EPWM_REGS_TZCTLDCA_DCAEVT2D_Msk    (0x7U << EPWM_REGS_TZCTLDCA_DCAEVT2D_Pos)                                             /*!< DCAEVT2D Mask      0x00000E00 */
#define EPWM_REGS_TZCTLDCA_DCAEVT2D_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCTLDCA_DCAEVT2D_Pos) & EPWM_REGS_TZCTLDCA_DCAEVT2D_Msk) /*!< DCAEVT2D Set Value            */
#define EPWM_REGS_TZCTLDCA_DCAEVT2D_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCTLDCA_DCAEVT2D_Msk) >> EPWM_REGS_TZCTLDCA_DCAEVT2D_Pos) /*!< DCAEVT2D Get Value            */


#define EPWM_REGS_TZCTLDCA_DCAEVT2U_Pos    (6U)                                                                                  /*!< DCAEVT2U Postion   6          */ 
#define EPWM_REGS_TZCTLDCA_DCAEVT2U_Msk    (0x7U << EPWM_REGS_TZCTLDCA_DCAEVT2U_Pos)                                             /*!< DCAEVT2U Mask      0x000001C0 */
#define EPWM_REGS_TZCTLDCA_DCAEVT2U_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCTLDCA_DCAEVT2U_Pos) & EPWM_REGS_TZCTLDCA_DCAEVT2U_Msk) /*!< DCAEVT2U Set Value            */
#define EPWM_REGS_TZCTLDCA_DCAEVT2U_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCTLDCA_DCAEVT2U_Msk) >> EPWM_REGS_TZCTLDCA_DCAEVT2U_Pos) /*!< DCAEVT2U Get Value            */


#define EPWM_REGS_TZCTLDCA_DCAEVT1D_Pos    (3U)                                                                                  /*!< DCAEVT1D Postion   3          */ 
#define EPWM_REGS_TZCTLDCA_DCAEVT1D_Msk    (0x7U << EPWM_REGS_TZCTLDCA_DCAEVT1D_Pos)                                             /*!< DCAEVT1D Mask      0x00000038 */
#define EPWM_REGS_TZCTLDCA_DCAEVT1D_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCTLDCA_DCAEVT1D_Pos) & EPWM_REGS_TZCTLDCA_DCAEVT1D_Msk) /*!< DCAEVT1D Set Value            */
#define EPWM_REGS_TZCTLDCA_DCAEVT1D_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCTLDCA_DCAEVT1D_Msk) >> EPWM_REGS_TZCTLDCA_DCAEVT1D_Pos) /*!< DCAEVT1D Get Value            */


#define EPWM_REGS_TZCTLDCA_DCAEVT1U_Pos    (0U)                                                                                  /*!< DCAEVT1U Postion   0          */ 
#define EPWM_REGS_TZCTLDCA_DCAEVT1U_Msk    (0x7U << EPWM_REGS_TZCTLDCA_DCAEVT1U_Pos)                                             /*!< DCAEVT1U Mask      0x00000007 */
#define EPWM_REGS_TZCTLDCA_DCAEVT1U_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCTLDCA_DCAEVT1U_Pos) & EPWM_REGS_TZCTLDCA_DCAEVT1U_Msk) /*!< DCAEVT1U Set Value            */
#define EPWM_REGS_TZCTLDCA_DCAEVT1U_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCTLDCA_DCAEVT1U_Msk) >> EPWM_REGS_TZCTLDCA_DCAEVT1U_Pos) /*!< DCAEVT1U Get Value            */


/* TZCTLDCB bitfield */
#define EPWM_REGS_TZCTLDCB_DCBEVT2D_Pos    (9U)                                                                                  /*!< DCBEVT2D Postion   9          */ 
#define EPWM_REGS_TZCTLDCB_DCBEVT2D_Msk    (0x7U << EPWM_REGS_TZCTLDCB_DCBEVT2D_Pos)                                             /*!< DCBEVT2D Mask      0x00000E00 */
#define EPWM_REGS_TZCTLDCB_DCBEVT2D_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCTLDCB_DCBEVT2D_Pos) & EPWM_REGS_TZCTLDCB_DCBEVT2D_Msk) /*!< DCBEVT2D Set Value            */
#define EPWM_REGS_TZCTLDCB_DCBEVT2D_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCTLDCB_DCBEVT2D_Msk) >> EPWM_REGS_TZCTLDCB_DCBEVT2D_Pos) /*!< DCBEVT2D Get Value            */


#define EPWM_REGS_TZCTLDCB_DCBEVT2U_Pos    (6U)                                                                                  /*!< DCBEVT2U Postion   6          */ 
#define EPWM_REGS_TZCTLDCB_DCBEVT2U_Msk    (0x7U << EPWM_REGS_TZCTLDCB_DCBEVT2U_Pos)                                             /*!< DCBEVT2U Mask      0x000001C0 */
#define EPWM_REGS_TZCTLDCB_DCBEVT2U_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCTLDCB_DCBEVT2U_Pos) & EPWM_REGS_TZCTLDCB_DCBEVT2U_Msk) /*!< DCBEVT2U Set Value            */
#define EPWM_REGS_TZCTLDCB_DCBEVT2U_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCTLDCB_DCBEVT2U_Msk) >> EPWM_REGS_TZCTLDCB_DCBEVT2U_Pos) /*!< DCBEVT2U Get Value            */


#define EPWM_REGS_TZCTLDCB_DCBEVT1D_Pos    (3U)                                                                                  /*!< DCBEVT1D Postion   3          */ 
#define EPWM_REGS_TZCTLDCB_DCBEVT1D_Msk    (0x7U << EPWM_REGS_TZCTLDCB_DCBEVT1D_Pos)                                             /*!< DCBEVT1D Mask      0x00000038 */
#define EPWM_REGS_TZCTLDCB_DCBEVT1D_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCTLDCB_DCBEVT1D_Pos) & EPWM_REGS_TZCTLDCB_DCBEVT1D_Msk) /*!< DCBEVT1D Set Value            */
#define EPWM_REGS_TZCTLDCB_DCBEVT1D_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCTLDCB_DCBEVT1D_Msk) >> EPWM_REGS_TZCTLDCB_DCBEVT1D_Pos) /*!< DCBEVT1D Get Value            */


#define EPWM_REGS_TZCTLDCB_DCBEVT1U_Pos    (0U)                                                                                  /*!< DCBEVT1U Postion   0          */ 
#define EPWM_REGS_TZCTLDCB_DCBEVT1U_Msk    (0x7U << EPWM_REGS_TZCTLDCB_DCBEVT1U_Pos)                                             /*!< DCBEVT1U Mask      0x00000007 */
#define EPWM_REGS_TZCTLDCB_DCBEVT1U_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCTLDCB_DCBEVT1U_Pos) & EPWM_REGS_TZCTLDCB_DCBEVT1U_Msk) /*!< DCBEVT1U Set Value            */
#define EPWM_REGS_TZCTLDCB_DCBEVT1U_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCTLDCB_DCBEVT1U_Msk) >> EPWM_REGS_TZCTLDCB_DCBEVT1U_Pos) /*!< DCBEVT1U Get Value            */


/* TZEINT bitfield */
#define EPWM_REGS_TZEINT_DCBEVT2_Pos    (6U)                                                                                  /*!< DCBEVT2 Postion   6          */ 
#define EPWM_REGS_TZEINT_DCBEVT2_Msk    (0x1U << EPWM_REGS_TZEINT_DCBEVT2_Pos)                                                /*!< DCBEVT2 Mask      0x00000040 */
#define EPWM_REGS_TZEINT_DCBEVT2_Set(x) (((uint16_t) (x) << EPWM_REGS_TZEINT_DCBEVT2_Pos) & EPWM_REGS_TZEINT_DCBEVT2_Msk)     /*!< DCBEVT2 Set Value            */
#define EPWM_REGS_TZEINT_DCBEVT2_Get(x) (((uint16_t) (x) & EPWM_REGS_TZEINT_DCBEVT2_Msk) >> EPWM_REGS_TZEINT_DCBEVT2_Pos)     /*!< DCBEVT2 Get Value            */


#define EPWM_REGS_TZEINT_DCBEVT1_Pos    (5U)                                                                                  /*!< DCBEVT1 Postion   5          */ 
#define EPWM_REGS_TZEINT_DCBEVT1_Msk    (0x1U << EPWM_REGS_TZEINT_DCBEVT1_Pos)                                                /*!< DCBEVT1 Mask      0x00000020 */
#define EPWM_REGS_TZEINT_DCBEVT1_Set(x) (((uint16_t) (x) << EPWM_REGS_TZEINT_DCBEVT1_Pos) & EPWM_REGS_TZEINT_DCBEVT1_Msk)     /*!< DCBEVT1 Set Value            */
#define EPWM_REGS_TZEINT_DCBEVT1_Get(x) (((uint16_t) (x) & EPWM_REGS_TZEINT_DCBEVT1_Msk) >> EPWM_REGS_TZEINT_DCBEVT1_Pos)     /*!< DCBEVT1 Get Value            */


#define EPWM_REGS_TZEINT_DCAEVT2_Pos    (4U)                                                                                  /*!< DCAEVT2 Postion   4          */ 
#define EPWM_REGS_TZEINT_DCAEVT2_Msk    (0x1U << EPWM_REGS_TZEINT_DCAEVT2_Pos)                                                /*!< DCAEVT2 Mask      0x00000010 */
#define EPWM_REGS_TZEINT_DCAEVT2_Set(x) (((uint16_t) (x) << EPWM_REGS_TZEINT_DCAEVT2_Pos) & EPWM_REGS_TZEINT_DCAEVT2_Msk)     /*!< DCAEVT2 Set Value            */
#define EPWM_REGS_TZEINT_DCAEVT2_Get(x) (((uint16_t) (x) & EPWM_REGS_TZEINT_DCAEVT2_Msk) >> EPWM_REGS_TZEINT_DCAEVT2_Pos)     /*!< DCAEVT2 Get Value            */


#define EPWM_REGS_TZEINT_DCAEVT1_Pos    (3U)                                                                                  /*!< DCAEVT1 Postion   3          */ 
#define EPWM_REGS_TZEINT_DCAEVT1_Msk    (0x1U << EPWM_REGS_TZEINT_DCAEVT1_Pos)                                                /*!< DCAEVT1 Mask      0x00000008 */
#define EPWM_REGS_TZEINT_DCAEVT1_Set(x) (((uint16_t) (x) << EPWM_REGS_TZEINT_DCAEVT1_Pos) & EPWM_REGS_TZEINT_DCAEVT1_Msk)     /*!< DCAEVT1 Set Value            */
#define EPWM_REGS_TZEINT_DCAEVT1_Get(x) (((uint16_t) (x) & EPWM_REGS_TZEINT_DCAEVT1_Msk) >> EPWM_REGS_TZEINT_DCAEVT1_Pos)     /*!< DCAEVT1 Get Value            */


#define EPWM_REGS_TZEINT_OST_Pos    (2U)                                                                                  /*!< OST Postion   2          */ 
#define EPWM_REGS_TZEINT_OST_Msk    (0x1U << EPWM_REGS_TZEINT_OST_Pos)                                                    /*!< OST Mask      0x00000004 */
#define EPWM_REGS_TZEINT_OST_Set(x) (((uint16_t) (x) << EPWM_REGS_TZEINT_OST_Pos) & EPWM_REGS_TZEINT_OST_Msk)             /*!< OST Set Value            */
#define EPWM_REGS_TZEINT_OST_Get(x) (((uint16_t) (x) & EPWM_REGS_TZEINT_OST_Msk) >> EPWM_REGS_TZEINT_OST_Pos)             /*!< OST Get Value            */


#define EPWM_REGS_TZEINT_CBC_Pos    (1U)                                                                                  /*!< CBC Postion   1          */ 
#define EPWM_REGS_TZEINT_CBC_Msk    (0x1U << EPWM_REGS_TZEINT_CBC_Pos)                                                    /*!< CBC Mask      0x00000002 */
#define EPWM_REGS_TZEINT_CBC_Set(x) (((uint16_t) (x) << EPWM_REGS_TZEINT_CBC_Pos) & EPWM_REGS_TZEINT_CBC_Msk)             /*!< CBC Set Value            */
#define EPWM_REGS_TZEINT_CBC_Get(x) (((uint16_t) (x) & EPWM_REGS_TZEINT_CBC_Msk) >> EPWM_REGS_TZEINT_CBC_Pos)             /*!< CBC Get Value            */


/* TZFLG bitfield */
#define EPWM_REGS_TZFLG_DCBEVT2_Pos    (6U)                                                                                  /*!< DCBEVT2 Postion   6          */ 
#define EPWM_REGS_TZFLG_DCBEVT2_Msk    (0x1U << EPWM_REGS_TZFLG_DCBEVT2_Pos)                                                 /*!< DCBEVT2 Mask      0x00000040 */
#define EPWM_REGS_TZFLG_DCBEVT2_Set(x) (((uint16_t) (x) << EPWM_REGS_TZFLG_DCBEVT2_Pos) & EPWM_REGS_TZFLG_DCBEVT2_Msk)       /*!< DCBEVT2 Set Value            */
#define EPWM_REGS_TZFLG_DCBEVT2_Get(x) (((uint16_t) (x) & EPWM_REGS_TZFLG_DCBEVT2_Msk) >> EPWM_REGS_TZFLG_DCBEVT2_Pos)       /*!< DCBEVT2 Get Value            */


#define EPWM_REGS_TZFLG_DCBEVT1_Pos    (5U)                                                                                  /*!< DCBEVT1 Postion   5          */ 
#define EPWM_REGS_TZFLG_DCBEVT1_Msk    (0x1U << EPWM_REGS_TZFLG_DCBEVT1_Pos)                                                 /*!< DCBEVT1 Mask      0x00000020 */
#define EPWM_REGS_TZFLG_DCBEVT1_Set(x) (((uint16_t) (x) << EPWM_REGS_TZFLG_DCBEVT1_Pos) & EPWM_REGS_TZFLG_DCBEVT1_Msk)       /*!< DCBEVT1 Set Value            */
#define EPWM_REGS_TZFLG_DCBEVT1_Get(x) (((uint16_t) (x) & EPWM_REGS_TZFLG_DCBEVT1_Msk) >> EPWM_REGS_TZFLG_DCBEVT1_Pos)       /*!< DCBEVT1 Get Value            */


#define EPWM_REGS_TZFLG_DCAEVT2_Pos    (4U)                                                                                  /*!< DCAEVT2 Postion   4          */ 
#define EPWM_REGS_TZFLG_DCAEVT2_Msk    (0x1U << EPWM_REGS_TZFLG_DCAEVT2_Pos)                                                 /*!< DCAEVT2 Mask      0x00000010 */
#define EPWM_REGS_TZFLG_DCAEVT2_Set(x) (((uint16_t) (x) << EPWM_REGS_TZFLG_DCAEVT2_Pos) & EPWM_REGS_TZFLG_DCAEVT2_Msk)       /*!< DCAEVT2 Set Value            */
#define EPWM_REGS_TZFLG_DCAEVT2_Get(x) (((uint16_t) (x) & EPWM_REGS_TZFLG_DCAEVT2_Msk) >> EPWM_REGS_TZFLG_DCAEVT2_Pos)       /*!< DCAEVT2 Get Value            */


#define EPWM_REGS_TZFLG_DCAEVT1_Pos    (3U)                                                                                  /*!< DCAEVT1 Postion   3          */ 
#define EPWM_REGS_TZFLG_DCAEVT1_Msk    (0x1U << EPWM_REGS_TZFLG_DCAEVT1_Pos)                                                 /*!< DCAEVT1 Mask      0x00000008 */
#define EPWM_REGS_TZFLG_DCAEVT1_Set(x) (((uint16_t) (x) << EPWM_REGS_TZFLG_DCAEVT1_Pos) & EPWM_REGS_TZFLG_DCAEVT1_Msk)       /*!< DCAEVT1 Set Value            */
#define EPWM_REGS_TZFLG_DCAEVT1_Get(x) (((uint16_t) (x) & EPWM_REGS_TZFLG_DCAEVT1_Msk) >> EPWM_REGS_TZFLG_DCAEVT1_Pos)       /*!< DCAEVT1 Get Value            */


#define EPWM_REGS_TZFLG_OST_Pos    (2U)                                                                                  /*!< OST Postion   2          */ 
#define EPWM_REGS_TZFLG_OST_Msk    (0x1U << EPWM_REGS_TZFLG_OST_Pos)                                                     /*!< OST Mask      0x00000004 */
#define EPWM_REGS_TZFLG_OST_Set(x) (((uint16_t) (x) << EPWM_REGS_TZFLG_OST_Pos) & EPWM_REGS_TZFLG_OST_Msk)               /*!< OST Set Value            */
#define EPWM_REGS_TZFLG_OST_Get(x) (((uint16_t) (x) & EPWM_REGS_TZFLG_OST_Msk) >> EPWM_REGS_TZFLG_OST_Pos)               /*!< OST Get Value            */


#define EPWM_REGS_TZFLG_CBC_Pos    (1U)                                                                                  /*!< CBC Postion   1          */ 
#define EPWM_REGS_TZFLG_CBC_Msk    (0x1U << EPWM_REGS_TZFLG_CBC_Pos)                                                     /*!< CBC Mask      0x00000002 */
#define EPWM_REGS_TZFLG_CBC_Set(x) (((uint16_t) (x) << EPWM_REGS_TZFLG_CBC_Pos) & EPWM_REGS_TZFLG_CBC_Msk)               /*!< CBC Set Value            */
#define EPWM_REGS_TZFLG_CBC_Get(x) (((uint16_t) (x) & EPWM_REGS_TZFLG_CBC_Msk) >> EPWM_REGS_TZFLG_CBC_Pos)               /*!< CBC Get Value            */


#define EPWM_REGS_TZFLG_TZINT_Pos    (0U)                                                                                  /*!< TZINT Postion   0          */ 
#define EPWM_REGS_TZFLG_TZINT_Msk    (0x1U << EPWM_REGS_TZFLG_TZINT_Pos)                                                   /*!< TZINT Mask      0x00000001 */
#define EPWM_REGS_TZFLG_TZINT_Set(x) (((uint16_t) (x) << EPWM_REGS_TZFLG_TZINT_Pos) & EPWM_REGS_TZFLG_TZINT_Msk)           /*!< TZINT Set Value            */
#define EPWM_REGS_TZFLG_TZINT_Get(x) (((uint16_t) (x) & EPWM_REGS_TZFLG_TZINT_Msk) >> EPWM_REGS_TZFLG_TZINT_Pos)           /*!< TZINT Get Value            */


/* TZCBCFLG bitfield */
#define EPWM_REGS_TZCBCFLG_DCBEVT2_Pos    (7U)                                                                                  /*!< DCBEVT2 Postion   7          */ 
#define EPWM_REGS_TZCBCFLG_DCBEVT2_Msk    (0x1U << EPWM_REGS_TZCBCFLG_DCBEVT2_Pos)                                              /*!< DCBEVT2 Mask      0x00000080 */
#define EPWM_REGS_TZCBCFLG_DCBEVT2_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCBCFLG_DCBEVT2_Pos) & EPWM_REGS_TZCBCFLG_DCBEVT2_Msk) /*!< DCBEVT2 Set Value            */
#define EPWM_REGS_TZCBCFLG_DCBEVT2_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCBCFLG_DCBEVT2_Msk) >> EPWM_REGS_TZCBCFLG_DCBEVT2_Pos) /*!< DCBEVT2 Get Value            */


#define EPWM_REGS_TZCBCFLG_DCAEVT2_Pos    (6U)                                                                                  /*!< DCAEVT2 Postion   6          */ 
#define EPWM_REGS_TZCBCFLG_DCAEVT2_Msk    (0x1U << EPWM_REGS_TZCBCFLG_DCAEVT2_Pos)                                              /*!< DCAEVT2 Mask      0x00000040 */
#define EPWM_REGS_TZCBCFLG_DCAEVT2_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCBCFLG_DCAEVT2_Pos) & EPWM_REGS_TZCBCFLG_DCAEVT2_Msk) /*!< DCAEVT2 Set Value            */
#define EPWM_REGS_TZCBCFLG_DCAEVT2_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCBCFLG_DCAEVT2_Msk) >> EPWM_REGS_TZCBCFLG_DCAEVT2_Pos) /*!< DCAEVT2 Get Value            */


#define EPWM_REGS_TZCBCFLG_CBC6_Pos    (5U)                                                                                  /*!< CBC6 Postion   5          */ 
#define EPWM_REGS_TZCBCFLG_CBC6_Msk    (0x1U << EPWM_REGS_TZCBCFLG_CBC6_Pos)                                                 /*!< CBC6 Mask      0x00000020 */
#define EPWM_REGS_TZCBCFLG_CBC6_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCBCFLG_CBC6_Pos) & EPWM_REGS_TZCBCFLG_CBC6_Msk)       /*!< CBC6 Set Value            */
#define EPWM_REGS_TZCBCFLG_CBC6_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCBCFLG_CBC6_Msk) >> EPWM_REGS_TZCBCFLG_CBC6_Pos)       /*!< CBC6 Get Value            */


#define EPWM_REGS_TZCBCFLG_CBC5_Pos    (4U)                                                                                  /*!< CBC5 Postion   4          */ 
#define EPWM_REGS_TZCBCFLG_CBC5_Msk    (0x1U << EPWM_REGS_TZCBCFLG_CBC5_Pos)                                                 /*!< CBC5 Mask      0x00000010 */
#define EPWM_REGS_TZCBCFLG_CBC5_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCBCFLG_CBC5_Pos) & EPWM_REGS_TZCBCFLG_CBC5_Msk)       /*!< CBC5 Set Value            */
#define EPWM_REGS_TZCBCFLG_CBC5_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCBCFLG_CBC5_Msk) >> EPWM_REGS_TZCBCFLG_CBC5_Pos)       /*!< CBC5 Get Value            */


#define EPWM_REGS_TZCBCFLG_CBC4_Pos    (3U)                                                                                  /*!< CBC4 Postion   3          */ 
#define EPWM_REGS_TZCBCFLG_CBC4_Msk    (0x1U << EPWM_REGS_TZCBCFLG_CBC4_Pos)                                                 /*!< CBC4 Mask      0x00000008 */
#define EPWM_REGS_TZCBCFLG_CBC4_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCBCFLG_CBC4_Pos) & EPWM_REGS_TZCBCFLG_CBC4_Msk)       /*!< CBC4 Set Value            */
#define EPWM_REGS_TZCBCFLG_CBC4_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCBCFLG_CBC4_Msk) >> EPWM_REGS_TZCBCFLG_CBC4_Pos)       /*!< CBC4 Get Value            */


#define EPWM_REGS_TZCBCFLG_CBC3_Pos    (2U)                                                                                  /*!< CBC3 Postion   2          */ 
#define EPWM_REGS_TZCBCFLG_CBC3_Msk    (0x1U << EPWM_REGS_TZCBCFLG_CBC3_Pos)                                                 /*!< CBC3 Mask      0x00000004 */
#define EPWM_REGS_TZCBCFLG_CBC3_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCBCFLG_CBC3_Pos) & EPWM_REGS_TZCBCFLG_CBC3_Msk)       /*!< CBC3 Set Value            */
#define EPWM_REGS_TZCBCFLG_CBC3_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCBCFLG_CBC3_Msk) >> EPWM_REGS_TZCBCFLG_CBC3_Pos)       /*!< CBC3 Get Value            */


#define EPWM_REGS_TZCBCFLG_CBC2_Pos    (1U)                                                                                  /*!< CBC2 Postion   1          */ 
#define EPWM_REGS_TZCBCFLG_CBC2_Msk    (0x1U << EPWM_REGS_TZCBCFLG_CBC2_Pos)                                                 /*!< CBC2 Mask      0x00000002 */
#define EPWM_REGS_TZCBCFLG_CBC2_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCBCFLG_CBC2_Pos) & EPWM_REGS_TZCBCFLG_CBC2_Msk)       /*!< CBC2 Set Value            */
#define EPWM_REGS_TZCBCFLG_CBC2_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCBCFLG_CBC2_Msk) >> EPWM_REGS_TZCBCFLG_CBC2_Pos)       /*!< CBC2 Get Value            */


#define EPWM_REGS_TZCBCFLG_CBC1_Pos    (0U)                                                                                  /*!< CBC1 Postion   0          */ 
#define EPWM_REGS_TZCBCFLG_CBC1_Msk    (0x1U << EPWM_REGS_TZCBCFLG_CBC1_Pos)                                                 /*!< CBC1 Mask      0x00000001 */
#define EPWM_REGS_TZCBCFLG_CBC1_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCBCFLG_CBC1_Pos) & EPWM_REGS_TZCBCFLG_CBC1_Msk)       /*!< CBC1 Set Value            */
#define EPWM_REGS_TZCBCFLG_CBC1_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCBCFLG_CBC1_Msk) >> EPWM_REGS_TZCBCFLG_CBC1_Pos)       /*!< CBC1 Get Value            */


/* TZOSTFLG bitfield */
#define EPWM_REGS_TZOSTFLG_DCBEVT1_Pos    (7U)                                                                                  /*!< DCBEVT1 Postion   7          */ 
#define EPWM_REGS_TZOSTFLG_DCBEVT1_Msk    (0x1U << EPWM_REGS_TZOSTFLG_DCBEVT1_Pos)                                              /*!< DCBEVT1 Mask      0x00000080 */
#define EPWM_REGS_TZOSTFLG_DCBEVT1_Set(x) (((uint16_t) (x) << EPWM_REGS_TZOSTFLG_DCBEVT1_Pos) & EPWM_REGS_TZOSTFLG_DCBEVT1_Msk) /*!< DCBEVT1 Set Value            */
#define EPWM_REGS_TZOSTFLG_DCBEVT1_Get(x) (((uint16_t) (x) & EPWM_REGS_TZOSTFLG_DCBEVT1_Msk) >> EPWM_REGS_TZOSTFLG_DCBEVT1_Pos) /*!< DCBEVT1 Get Value            */


#define EPWM_REGS_TZOSTFLG_DCAEVT1_Pos    (6U)                                                                                  /*!< DCAEVT1 Postion   6          */ 
#define EPWM_REGS_TZOSTFLG_DCAEVT1_Msk    (0x1U << EPWM_REGS_TZOSTFLG_DCAEVT1_Pos)                                              /*!< DCAEVT1 Mask      0x00000040 */
#define EPWM_REGS_TZOSTFLG_DCAEVT1_Set(x) (((uint16_t) (x) << EPWM_REGS_TZOSTFLG_DCAEVT1_Pos) & EPWM_REGS_TZOSTFLG_DCAEVT1_Msk) /*!< DCAEVT1 Set Value            */
#define EPWM_REGS_TZOSTFLG_DCAEVT1_Get(x) (((uint16_t) (x) & EPWM_REGS_TZOSTFLG_DCAEVT1_Msk) >> EPWM_REGS_TZOSTFLG_DCAEVT1_Pos) /*!< DCAEVT1 Get Value            */


#define EPWM_REGS_TZOSTFLG_OST6_Pos    (5U)                                                                                  /*!< OST6 Postion   5          */ 
#define EPWM_REGS_TZOSTFLG_OST6_Msk    (0x1U << EPWM_REGS_TZOSTFLG_OST6_Pos)                                                 /*!< OST6 Mask      0x00000020 */
#define EPWM_REGS_TZOSTFLG_OST6_Set(x) (((uint16_t) (x) << EPWM_REGS_TZOSTFLG_OST6_Pos) & EPWM_REGS_TZOSTFLG_OST6_Msk)       /*!< OST6 Set Value            */
#define EPWM_REGS_TZOSTFLG_OST6_Get(x) (((uint16_t) (x) & EPWM_REGS_TZOSTFLG_OST6_Msk) >> EPWM_REGS_TZOSTFLG_OST6_Pos)       /*!< OST6 Get Value            */


#define EPWM_REGS_TZOSTFLG_OST5_Pos    (4U)                                                                                  /*!< OST5 Postion   4          */ 
#define EPWM_REGS_TZOSTFLG_OST5_Msk    (0x1U << EPWM_REGS_TZOSTFLG_OST5_Pos)                                                 /*!< OST5 Mask      0x00000010 */
#define EPWM_REGS_TZOSTFLG_OST5_Set(x) (((uint16_t) (x) << EPWM_REGS_TZOSTFLG_OST5_Pos) & EPWM_REGS_TZOSTFLG_OST5_Msk)       /*!< OST5 Set Value            */
#define EPWM_REGS_TZOSTFLG_OST5_Get(x) (((uint16_t) (x) & EPWM_REGS_TZOSTFLG_OST5_Msk) >> EPWM_REGS_TZOSTFLG_OST5_Pos)       /*!< OST5 Get Value            */


#define EPWM_REGS_TZOSTFLG_OST4_Pos    (3U)                                                                                  /*!< OST4 Postion   3          */ 
#define EPWM_REGS_TZOSTFLG_OST4_Msk    (0x1U << EPWM_REGS_TZOSTFLG_OST4_Pos)                                                 /*!< OST4 Mask      0x00000008 */
#define EPWM_REGS_TZOSTFLG_OST4_Set(x) (((uint16_t) (x) << EPWM_REGS_TZOSTFLG_OST4_Pos) & EPWM_REGS_TZOSTFLG_OST4_Msk)       /*!< OST4 Set Value            */
#define EPWM_REGS_TZOSTFLG_OST4_Get(x) (((uint16_t) (x) & EPWM_REGS_TZOSTFLG_OST4_Msk) >> EPWM_REGS_TZOSTFLG_OST4_Pos)       /*!< OST4 Get Value            */


#define EPWM_REGS_TZOSTFLG_OST3_Pos    (2U)                                                                                  /*!< OST3 Postion   2          */ 
#define EPWM_REGS_TZOSTFLG_OST3_Msk    (0x1U << EPWM_REGS_TZOSTFLG_OST3_Pos)                                                 /*!< OST3 Mask      0x00000004 */
#define EPWM_REGS_TZOSTFLG_OST3_Set(x) (((uint16_t) (x) << EPWM_REGS_TZOSTFLG_OST3_Pos) & EPWM_REGS_TZOSTFLG_OST3_Msk)       /*!< OST3 Set Value            */
#define EPWM_REGS_TZOSTFLG_OST3_Get(x) (((uint16_t) (x) & EPWM_REGS_TZOSTFLG_OST3_Msk) >> EPWM_REGS_TZOSTFLG_OST3_Pos)       /*!< OST3 Get Value            */


#define EPWM_REGS_TZOSTFLG_OST2_Pos    (1U)                                                                                  /*!< OST2 Postion   1          */ 
#define EPWM_REGS_TZOSTFLG_OST2_Msk    (0x1U << EPWM_REGS_TZOSTFLG_OST2_Pos)                                                 /*!< OST2 Mask      0x00000002 */
#define EPWM_REGS_TZOSTFLG_OST2_Set(x) (((uint16_t) (x) << EPWM_REGS_TZOSTFLG_OST2_Pos) & EPWM_REGS_TZOSTFLG_OST2_Msk)       /*!< OST2 Set Value            */
#define EPWM_REGS_TZOSTFLG_OST2_Get(x) (((uint16_t) (x) & EPWM_REGS_TZOSTFLG_OST2_Msk) >> EPWM_REGS_TZOSTFLG_OST2_Pos)       /*!< OST2 Get Value            */


#define EPWM_REGS_TZOSTFLG_OST1_Pos    (0U)                                                                                  /*!< OST1 Postion   0          */ 
#define EPWM_REGS_TZOSTFLG_OST1_Msk    (0x1U << EPWM_REGS_TZOSTFLG_OST1_Pos)                                                 /*!< OST1 Mask      0x00000001 */
#define EPWM_REGS_TZOSTFLG_OST1_Set(x) (((uint16_t) (x) << EPWM_REGS_TZOSTFLG_OST1_Pos) & EPWM_REGS_TZOSTFLG_OST1_Msk)       /*!< OST1 Set Value            */
#define EPWM_REGS_TZOSTFLG_OST1_Get(x) (((uint16_t) (x) & EPWM_REGS_TZOSTFLG_OST1_Msk) >> EPWM_REGS_TZOSTFLG_OST1_Pos)       /*!< OST1 Get Value            */


/* TZCLR bitfield */
#define EPWM_REGS_TZCLR_CBCPULSE_Pos    (14U)                                                                                 /*!< CBCPULSE Postion   14         */ 
#define EPWM_REGS_TZCLR_CBCPULSE_Msk    (0x3U << EPWM_REGS_TZCLR_CBCPULSE_Pos)                                                /*!< CBCPULSE Mask      0x0000C000 */
#define EPWM_REGS_TZCLR_CBCPULSE_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCLR_CBCPULSE_Pos) & EPWM_REGS_TZCLR_CBCPULSE_Msk)     /*!< CBCPULSE Set Value            */
#define EPWM_REGS_TZCLR_CBCPULSE_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCLR_CBCPULSE_Msk) >> EPWM_REGS_TZCLR_CBCPULSE_Pos)     /*!< CBCPULSE Get Value            */


#define EPWM_REGS_TZCLR_DCBEVT2_Pos    (6U)                                                                                  /*!< DCBEVT2 Postion   6          */ 
#define EPWM_REGS_TZCLR_DCBEVT2_Msk    (0x1U << EPWM_REGS_TZCLR_DCBEVT2_Pos)                                                 /*!< DCBEVT2 Mask      0x00000040 */
#define EPWM_REGS_TZCLR_DCBEVT2_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCLR_DCBEVT2_Pos) & EPWM_REGS_TZCLR_DCBEVT2_Msk)       /*!< DCBEVT2 Set Value            */
#define EPWM_REGS_TZCLR_DCBEVT2_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCLR_DCBEVT2_Msk) >> EPWM_REGS_TZCLR_DCBEVT2_Pos)       /*!< DCBEVT2 Get Value            */


#define EPWM_REGS_TZCLR_DCBEVT1_Pos    (5U)                                                                                  /*!< DCBEVT1 Postion   5          */ 
#define EPWM_REGS_TZCLR_DCBEVT1_Msk    (0x1U << EPWM_REGS_TZCLR_DCBEVT1_Pos)                                                 /*!< DCBEVT1 Mask      0x00000020 */
#define EPWM_REGS_TZCLR_DCBEVT1_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCLR_DCBEVT1_Pos) & EPWM_REGS_TZCLR_DCBEVT1_Msk)       /*!< DCBEVT1 Set Value            */
#define EPWM_REGS_TZCLR_DCBEVT1_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCLR_DCBEVT1_Msk) >> EPWM_REGS_TZCLR_DCBEVT1_Pos)       /*!< DCBEVT1 Get Value            */


#define EPWM_REGS_TZCLR_DCAEVT2_Pos    (4U)                                                                                  /*!< DCAEVT2 Postion   4          */ 
#define EPWM_REGS_TZCLR_DCAEVT2_Msk    (0x1U << EPWM_REGS_TZCLR_DCAEVT2_Pos)                                                 /*!< DCAEVT2 Mask      0x00000010 */
#define EPWM_REGS_TZCLR_DCAEVT2_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCLR_DCAEVT2_Pos) & EPWM_REGS_TZCLR_DCAEVT2_Msk)       /*!< DCAEVT2 Set Value            */
#define EPWM_REGS_TZCLR_DCAEVT2_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCLR_DCAEVT2_Msk) >> EPWM_REGS_TZCLR_DCAEVT2_Pos)       /*!< DCAEVT2 Get Value            */


#define EPWM_REGS_TZCLR_DCAEVT1_Pos    (3U)                                                                                  /*!< DCAEVT1 Postion   3          */ 
#define EPWM_REGS_TZCLR_DCAEVT1_Msk    (0x1U << EPWM_REGS_TZCLR_DCAEVT1_Pos)                                                 /*!< DCAEVT1 Mask      0x00000008 */
#define EPWM_REGS_TZCLR_DCAEVT1_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCLR_DCAEVT1_Pos) & EPWM_REGS_TZCLR_DCAEVT1_Msk)       /*!< DCAEVT1 Set Value            */
#define EPWM_REGS_TZCLR_DCAEVT1_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCLR_DCAEVT1_Msk) >> EPWM_REGS_TZCLR_DCAEVT1_Pos)       /*!< DCAEVT1 Get Value            */


#define EPWM_REGS_TZCLR_OST_Pos    (2U)                                                                                  /*!< OST Postion   2          */ 
#define EPWM_REGS_TZCLR_OST_Msk    (0x1U << EPWM_REGS_TZCLR_OST_Pos)                                                     /*!< OST Mask      0x00000004 */
#define EPWM_REGS_TZCLR_OST_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCLR_OST_Pos) & EPWM_REGS_TZCLR_OST_Msk)               /*!< OST Set Value            */
#define EPWM_REGS_TZCLR_OST_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCLR_OST_Msk) >> EPWM_REGS_TZCLR_OST_Pos)               /*!< OST Get Value            */


#define EPWM_REGS_TZCLR_CBC_Pos    (1U)                                                                                  /*!< CBC Postion   1          */ 
#define EPWM_REGS_TZCLR_CBC_Msk    (0x1U << EPWM_REGS_TZCLR_CBC_Pos)                                                     /*!< CBC Mask      0x00000002 */
#define EPWM_REGS_TZCLR_CBC_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCLR_CBC_Pos) & EPWM_REGS_TZCLR_CBC_Msk)               /*!< CBC Set Value            */
#define EPWM_REGS_TZCLR_CBC_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCLR_CBC_Msk) >> EPWM_REGS_TZCLR_CBC_Pos)               /*!< CBC Get Value            */


#define EPWM_REGS_TZCLR_TZINT_Pos    (0U)                                                                                  /*!< TZINT Postion   0          */ 
#define EPWM_REGS_TZCLR_TZINT_Msk    (0x1U << EPWM_REGS_TZCLR_TZINT_Pos)                                                   /*!< TZINT Mask      0x00000001 */
#define EPWM_REGS_TZCLR_TZINT_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCLR_TZINT_Pos) & EPWM_REGS_TZCLR_TZINT_Msk)           /*!< TZINT Set Value            */
#define EPWM_REGS_TZCLR_TZINT_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCLR_TZINT_Msk) >> EPWM_REGS_TZCLR_TZINT_Pos)           /*!< TZINT Get Value            */


/* TZCBCCLR bitfield */
#define EPWM_REGS_TZCBCCLR_DCBEVT2_Pos    (7U)                                                                                  /*!< DCBEVT2 Postion   7          */ 
#define EPWM_REGS_TZCBCCLR_DCBEVT2_Msk    (0x1U << EPWM_REGS_TZCBCCLR_DCBEVT2_Pos)                                              /*!< DCBEVT2 Mask      0x00000080 */
#define EPWM_REGS_TZCBCCLR_DCBEVT2_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCBCCLR_DCBEVT2_Pos) & EPWM_REGS_TZCBCCLR_DCBEVT2_Msk) /*!< DCBEVT2 Set Value            */
#define EPWM_REGS_TZCBCCLR_DCBEVT2_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCBCCLR_DCBEVT2_Msk) >> EPWM_REGS_TZCBCCLR_DCBEVT2_Pos) /*!< DCBEVT2 Get Value            */


#define EPWM_REGS_TZCBCCLR_DCAEVT2_Pos    (6U)                                                                                  /*!< DCAEVT2 Postion   6          */ 
#define EPWM_REGS_TZCBCCLR_DCAEVT2_Msk    (0x1U << EPWM_REGS_TZCBCCLR_DCAEVT2_Pos)                                              /*!< DCAEVT2 Mask      0x00000040 */
#define EPWM_REGS_TZCBCCLR_DCAEVT2_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCBCCLR_DCAEVT2_Pos) & EPWM_REGS_TZCBCCLR_DCAEVT2_Msk) /*!< DCAEVT2 Set Value            */
#define EPWM_REGS_TZCBCCLR_DCAEVT2_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCBCCLR_DCAEVT2_Msk) >> EPWM_REGS_TZCBCCLR_DCAEVT2_Pos) /*!< DCAEVT2 Get Value            */


#define EPWM_REGS_TZCBCCLR_CBC6_Pos    (5U)                                                                                  /*!< CBC6 Postion   5          */ 
#define EPWM_REGS_TZCBCCLR_CBC6_Msk    (0x1U << EPWM_REGS_TZCBCCLR_CBC6_Pos)                                                 /*!< CBC6 Mask      0x00000020 */
#define EPWM_REGS_TZCBCCLR_CBC6_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCBCCLR_CBC6_Pos) & EPWM_REGS_TZCBCCLR_CBC6_Msk)       /*!< CBC6 Set Value            */
#define EPWM_REGS_TZCBCCLR_CBC6_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCBCCLR_CBC6_Msk) >> EPWM_REGS_TZCBCCLR_CBC6_Pos)       /*!< CBC6 Get Value            */


#define EPWM_REGS_TZCBCCLR_CBC5_Pos    (4U)                                                                                  /*!< CBC5 Postion   4          */ 
#define EPWM_REGS_TZCBCCLR_CBC5_Msk    (0x1U << EPWM_REGS_TZCBCCLR_CBC5_Pos)                                                 /*!< CBC5 Mask      0x00000010 */
#define EPWM_REGS_TZCBCCLR_CBC5_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCBCCLR_CBC5_Pos) & EPWM_REGS_TZCBCCLR_CBC5_Msk)       /*!< CBC5 Set Value            */
#define EPWM_REGS_TZCBCCLR_CBC5_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCBCCLR_CBC5_Msk) >> EPWM_REGS_TZCBCCLR_CBC5_Pos)       /*!< CBC5 Get Value            */


#define EPWM_REGS_TZCBCCLR_CBC4_Pos    (3U)                                                                                  /*!< CBC4 Postion   3          */ 
#define EPWM_REGS_TZCBCCLR_CBC4_Msk    (0x1U << EPWM_REGS_TZCBCCLR_CBC4_Pos)                                                 /*!< CBC4 Mask      0x00000008 */
#define EPWM_REGS_TZCBCCLR_CBC4_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCBCCLR_CBC4_Pos) & EPWM_REGS_TZCBCCLR_CBC4_Msk)       /*!< CBC4 Set Value            */
#define EPWM_REGS_TZCBCCLR_CBC4_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCBCCLR_CBC4_Msk) >> EPWM_REGS_TZCBCCLR_CBC4_Pos)       /*!< CBC4 Get Value            */


#define EPWM_REGS_TZCBCCLR_CBC3_Pos    (2U)                                                                                  /*!< CBC3 Postion   2          */ 
#define EPWM_REGS_TZCBCCLR_CBC3_Msk    (0x1U << EPWM_REGS_TZCBCCLR_CBC3_Pos)                                                 /*!< CBC3 Mask      0x00000004 */
#define EPWM_REGS_TZCBCCLR_CBC3_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCBCCLR_CBC3_Pos) & EPWM_REGS_TZCBCCLR_CBC3_Msk)       /*!< CBC3 Set Value            */
#define EPWM_REGS_TZCBCCLR_CBC3_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCBCCLR_CBC3_Msk) >> EPWM_REGS_TZCBCCLR_CBC3_Pos)       /*!< CBC3 Get Value            */


#define EPWM_REGS_TZCBCCLR_CBC2_Pos    (1U)                                                                                  /*!< CBC2 Postion   1          */ 
#define EPWM_REGS_TZCBCCLR_CBC2_Msk    (0x1U << EPWM_REGS_TZCBCCLR_CBC2_Pos)                                                 /*!< CBC2 Mask      0x00000002 */
#define EPWM_REGS_TZCBCCLR_CBC2_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCBCCLR_CBC2_Pos) & EPWM_REGS_TZCBCCLR_CBC2_Msk)       /*!< CBC2 Set Value            */
#define EPWM_REGS_TZCBCCLR_CBC2_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCBCCLR_CBC2_Msk) >> EPWM_REGS_TZCBCCLR_CBC2_Pos)       /*!< CBC2 Get Value            */


#define EPWM_REGS_TZCBCCLR_CBC1_Pos    (0U)                                                                                  /*!< CBC1 Postion   0          */ 
#define EPWM_REGS_TZCBCCLR_CBC1_Msk    (0x1U << EPWM_REGS_TZCBCCLR_CBC1_Pos)                                                 /*!< CBC1 Mask      0x00000001 */
#define EPWM_REGS_TZCBCCLR_CBC1_Set(x) (((uint16_t) (x) << EPWM_REGS_TZCBCCLR_CBC1_Pos) & EPWM_REGS_TZCBCCLR_CBC1_Msk)       /*!< CBC1 Set Value            */
#define EPWM_REGS_TZCBCCLR_CBC1_Get(x) (((uint16_t) (x) & EPWM_REGS_TZCBCCLR_CBC1_Msk) >> EPWM_REGS_TZCBCCLR_CBC1_Pos)       /*!< CBC1 Get Value            */


/* TZOSTCLR bitfield */
#define EPWM_REGS_TZOSTCLR_DCBEVT1_Pos    (7U)                                                                                  /*!< DCBEVT1 Postion   7          */ 
#define EPWM_REGS_TZOSTCLR_DCBEVT1_Msk    (0x1U << EPWM_REGS_TZOSTCLR_DCBEVT1_Pos)                                              /*!< DCBEVT1 Mask      0x00000080 */
#define EPWM_REGS_TZOSTCLR_DCBEVT1_Set(x) (((uint16_t) (x) << EPWM_REGS_TZOSTCLR_DCBEVT1_Pos) & EPWM_REGS_TZOSTCLR_DCBEVT1_Msk) /*!< DCBEVT1 Set Value            */
#define EPWM_REGS_TZOSTCLR_DCBEVT1_Get(x) (((uint16_t) (x) & EPWM_REGS_TZOSTCLR_DCBEVT1_Msk) >> EPWM_REGS_TZOSTCLR_DCBEVT1_Pos) /*!< DCBEVT1 Get Value            */


#define EPWM_REGS_TZOSTCLR_DCAEVT1_Pos    (6U)                                                                                  /*!< DCAEVT1 Postion   6          */ 
#define EPWM_REGS_TZOSTCLR_DCAEVT1_Msk    (0x1U << EPWM_REGS_TZOSTCLR_DCAEVT1_Pos)                                              /*!< DCAEVT1 Mask      0x00000040 */
#define EPWM_REGS_TZOSTCLR_DCAEVT1_Set(x) (((uint16_t) (x) << EPWM_REGS_TZOSTCLR_DCAEVT1_Pos) & EPWM_REGS_TZOSTCLR_DCAEVT1_Msk) /*!< DCAEVT1 Set Value            */
#define EPWM_REGS_TZOSTCLR_DCAEVT1_Get(x) (((uint16_t) (x) & EPWM_REGS_TZOSTCLR_DCAEVT1_Msk) >> EPWM_REGS_TZOSTCLR_DCAEVT1_Pos) /*!< DCAEVT1 Get Value            */


#define EPWM_REGS_TZOSTCLR_OST6_Pos    (5U)                                                                                  /*!< OST6 Postion   5          */ 
#define EPWM_REGS_TZOSTCLR_OST6_Msk    (0x1U << EPWM_REGS_TZOSTCLR_OST6_Pos)                                                 /*!< OST6 Mask      0x00000020 */
#define EPWM_REGS_TZOSTCLR_OST6_Set(x) (((uint16_t) (x) << EPWM_REGS_TZOSTCLR_OST6_Pos) & EPWM_REGS_TZOSTCLR_OST6_Msk)       /*!< OST6 Set Value            */
#define EPWM_REGS_TZOSTCLR_OST6_Get(x) (((uint16_t) (x) & EPWM_REGS_TZOSTCLR_OST6_Msk) >> EPWM_REGS_TZOSTCLR_OST6_Pos)       /*!< OST6 Get Value            */


#define EPWM_REGS_TZOSTCLR_OST5_Pos    (4U)                                                                                  /*!< OST5 Postion   4          */ 
#define EPWM_REGS_TZOSTCLR_OST5_Msk    (0x1U << EPWM_REGS_TZOSTCLR_OST5_Pos)                                                 /*!< OST5 Mask      0x00000010 */
#define EPWM_REGS_TZOSTCLR_OST5_Set(x) (((uint16_t) (x) << EPWM_REGS_TZOSTCLR_OST5_Pos) & EPWM_REGS_TZOSTCLR_OST5_Msk)       /*!< OST5 Set Value            */
#define EPWM_REGS_TZOSTCLR_OST5_Get(x) (((uint16_t) (x) & EPWM_REGS_TZOSTCLR_OST5_Msk) >> EPWM_REGS_TZOSTCLR_OST5_Pos)       /*!< OST5 Get Value            */


#define EPWM_REGS_TZOSTCLR_OST4_Pos    (3U)                                                                                  /*!< OST4 Postion   3          */ 
#define EPWM_REGS_TZOSTCLR_OST4_Msk    (0x1U << EPWM_REGS_TZOSTCLR_OST4_Pos)                                                 /*!< OST4 Mask      0x00000008 */
#define EPWM_REGS_TZOSTCLR_OST4_Set(x) (((uint16_t) (x) << EPWM_REGS_TZOSTCLR_OST4_Pos) & EPWM_REGS_TZOSTCLR_OST4_Msk)       /*!< OST4 Set Value            */
#define EPWM_REGS_TZOSTCLR_OST4_Get(x) (((uint16_t) (x) & EPWM_REGS_TZOSTCLR_OST4_Msk) >> EPWM_REGS_TZOSTCLR_OST4_Pos)       /*!< OST4 Get Value            */


#define EPWM_REGS_TZOSTCLR_OST3_Pos    (2U)                                                                                  /*!< OST3 Postion   2          */ 
#define EPWM_REGS_TZOSTCLR_OST3_Msk    (0x1U << EPWM_REGS_TZOSTCLR_OST3_Pos)                                                 /*!< OST3 Mask      0x00000004 */
#define EPWM_REGS_TZOSTCLR_OST3_Set(x) (((uint16_t) (x) << EPWM_REGS_TZOSTCLR_OST3_Pos) & EPWM_REGS_TZOSTCLR_OST3_Msk)       /*!< OST3 Set Value            */
#define EPWM_REGS_TZOSTCLR_OST3_Get(x) (((uint16_t) (x) & EPWM_REGS_TZOSTCLR_OST3_Msk) >> EPWM_REGS_TZOSTCLR_OST3_Pos)       /*!< OST3 Get Value            */


#define EPWM_REGS_TZOSTCLR_OST2_Pos    (1U)                                                                                  /*!< OST2 Postion   1          */ 
#define EPWM_REGS_TZOSTCLR_OST2_Msk    (0x1U << EPWM_REGS_TZOSTCLR_OST2_Pos)                                                 /*!< OST2 Mask      0x00000002 */
#define EPWM_REGS_TZOSTCLR_OST2_Set(x) (((uint16_t) (x) << EPWM_REGS_TZOSTCLR_OST2_Pos) & EPWM_REGS_TZOSTCLR_OST2_Msk)       /*!< OST2 Set Value            */
#define EPWM_REGS_TZOSTCLR_OST2_Get(x) (((uint16_t) (x) & EPWM_REGS_TZOSTCLR_OST2_Msk) >> EPWM_REGS_TZOSTCLR_OST2_Pos)       /*!< OST2 Get Value            */


#define EPWM_REGS_TZOSTCLR_OST1_Pos    (0U)                                                                                  /*!< OST1 Postion   0          */ 
#define EPWM_REGS_TZOSTCLR_OST1_Msk    (0x1U << EPWM_REGS_TZOSTCLR_OST1_Pos)                                                 /*!< OST1 Mask      0x00000001 */
#define EPWM_REGS_TZOSTCLR_OST1_Set(x) (((uint16_t) (x) << EPWM_REGS_TZOSTCLR_OST1_Pos) & EPWM_REGS_TZOSTCLR_OST1_Msk)       /*!< OST1 Set Value            */
#define EPWM_REGS_TZOSTCLR_OST1_Get(x) (((uint16_t) (x) & EPWM_REGS_TZOSTCLR_OST1_Msk) >> EPWM_REGS_TZOSTCLR_OST1_Pos)       /*!< OST1 Get Value            */


/* TZFRC bitfield */
#define EPWM_REGS_TZFRC_DCBEVT2_Pos    (6U)                                                                                  /*!< DCBEVT2 Postion   6          */ 
#define EPWM_REGS_TZFRC_DCBEVT2_Msk    (0x1U << EPWM_REGS_TZFRC_DCBEVT2_Pos)                                                 /*!< DCBEVT2 Mask      0x00000040 */
#define EPWM_REGS_TZFRC_DCBEVT2_Set(x) (((uint16_t) (x) << EPWM_REGS_TZFRC_DCBEVT2_Pos) & EPWM_REGS_TZFRC_DCBEVT2_Msk)       /*!< DCBEVT2 Set Value            */
#define EPWM_REGS_TZFRC_DCBEVT2_Get(x) (((uint16_t) (x) & EPWM_REGS_TZFRC_DCBEVT2_Msk) >> EPWM_REGS_TZFRC_DCBEVT2_Pos)       /*!< DCBEVT2 Get Value            */


#define EPWM_REGS_TZFRC_DCBEVT1_Pos    (5U)                                                                                  /*!< DCBEVT1 Postion   5          */ 
#define EPWM_REGS_TZFRC_DCBEVT1_Msk    (0x1U << EPWM_REGS_TZFRC_DCBEVT1_Pos)                                                 /*!< DCBEVT1 Mask      0x00000020 */
#define EPWM_REGS_TZFRC_DCBEVT1_Set(x) (((uint16_t) (x) << EPWM_REGS_TZFRC_DCBEVT1_Pos) & EPWM_REGS_TZFRC_DCBEVT1_Msk)       /*!< DCBEVT1 Set Value            */
#define EPWM_REGS_TZFRC_DCBEVT1_Get(x) (((uint16_t) (x) & EPWM_REGS_TZFRC_DCBEVT1_Msk) >> EPWM_REGS_TZFRC_DCBEVT1_Pos)       /*!< DCBEVT1 Get Value            */


#define EPWM_REGS_TZFRC_DCAEVT2_Pos    (4U)                                                                                  /*!< DCAEVT2 Postion   4          */ 
#define EPWM_REGS_TZFRC_DCAEVT2_Msk    (0x1U << EPWM_REGS_TZFRC_DCAEVT2_Pos)                                                 /*!< DCAEVT2 Mask      0x00000010 */
#define EPWM_REGS_TZFRC_DCAEVT2_Set(x) (((uint16_t) (x) << EPWM_REGS_TZFRC_DCAEVT2_Pos) & EPWM_REGS_TZFRC_DCAEVT2_Msk)       /*!< DCAEVT2 Set Value            */
#define EPWM_REGS_TZFRC_DCAEVT2_Get(x) (((uint16_t) (x) & EPWM_REGS_TZFRC_DCAEVT2_Msk) >> EPWM_REGS_TZFRC_DCAEVT2_Pos)       /*!< DCAEVT2 Get Value            */


#define EPWM_REGS_TZFRC_DCAEVT1_Pos    (3U)                                                                                  /*!< DCAEVT1 Postion   3          */ 
#define EPWM_REGS_TZFRC_DCAEVT1_Msk    (0x1U << EPWM_REGS_TZFRC_DCAEVT1_Pos)                                                 /*!< DCAEVT1 Mask      0x00000008 */
#define EPWM_REGS_TZFRC_DCAEVT1_Set(x) (((uint16_t) (x) << EPWM_REGS_TZFRC_DCAEVT1_Pos) & EPWM_REGS_TZFRC_DCAEVT1_Msk)       /*!< DCAEVT1 Set Value            */
#define EPWM_REGS_TZFRC_DCAEVT1_Get(x) (((uint16_t) (x) & EPWM_REGS_TZFRC_DCAEVT1_Msk) >> EPWM_REGS_TZFRC_DCAEVT1_Pos)       /*!< DCAEVT1 Get Value            */


#define EPWM_REGS_TZFRC_OST_Pos    (2U)                                                                                  /*!< OST Postion   2          */ 
#define EPWM_REGS_TZFRC_OST_Msk    (0x1U << EPWM_REGS_TZFRC_OST_Pos)                                                     /*!< OST Mask      0x00000004 */
#define EPWM_REGS_TZFRC_OST_Set(x) (((uint16_t) (x) << EPWM_REGS_TZFRC_OST_Pos) & EPWM_REGS_TZFRC_OST_Msk)               /*!< OST Set Value            */
#define EPWM_REGS_TZFRC_OST_Get(x) (((uint16_t) (x) & EPWM_REGS_TZFRC_OST_Msk) >> EPWM_REGS_TZFRC_OST_Pos)               /*!< OST Get Value            */


#define EPWM_REGS_TZFRC_CBC_Pos    (1U)                                                                                  /*!< CBC Postion   1          */ 
#define EPWM_REGS_TZFRC_CBC_Msk    (0x1U << EPWM_REGS_TZFRC_CBC_Pos)                                                     /*!< CBC Mask      0x00000002 */
#define EPWM_REGS_TZFRC_CBC_Set(x) (((uint16_t) (x) << EPWM_REGS_TZFRC_CBC_Pos) & EPWM_REGS_TZFRC_CBC_Msk)               /*!< CBC Set Value            */
#define EPWM_REGS_TZFRC_CBC_Get(x) (((uint16_t) (x) & EPWM_REGS_TZFRC_CBC_Msk) >> EPWM_REGS_TZFRC_CBC_Pos)               /*!< CBC Get Value            */


/* ETSEL bitfield */
#define EPWM_REGS_ETSEL_SOCBEN_Pos    (15U)                                                                                 /*!< SOCBEN Postion   15         */ 
#define EPWM_REGS_ETSEL_SOCBEN_Msk    (0x1U << EPWM_REGS_ETSEL_SOCBEN_Pos)                                                  /*!< SOCBEN Mask      0x00008000 */
#define EPWM_REGS_ETSEL_SOCBEN_Set(x) (((uint32_t) (x) << EPWM_REGS_ETSEL_SOCBEN_Pos) & EPWM_REGS_ETSEL_SOCBEN_Msk)         /*!< SOCBEN Set Value            */
#define EPWM_REGS_ETSEL_SOCBEN_Get(x) (((uint32_t) (x) & EPWM_REGS_ETSEL_SOCBEN_Msk) >> EPWM_REGS_ETSEL_SOCBEN_Pos)         /*!< SOCBEN Get Value            */


#define EPWM_REGS_ETSEL_SOCBSEL_Pos    (12U)                                                                                 /*!< SOCBSEL Postion   12         */ 
#define EPWM_REGS_ETSEL_SOCBSEL_Msk    (0x7U << EPWM_REGS_ETSEL_SOCBSEL_Pos)                                                 /*!< SOCBSEL Mask      0x00007000 */
#define EPWM_REGS_ETSEL_SOCBSEL_Set(x) (((uint32_t) (x) << EPWM_REGS_ETSEL_SOCBSEL_Pos) & EPWM_REGS_ETSEL_SOCBSEL_Msk)       /*!< SOCBSEL Set Value            */
#define EPWM_REGS_ETSEL_SOCBSEL_Get(x) (((uint32_t) (x) & EPWM_REGS_ETSEL_SOCBSEL_Msk) >> EPWM_REGS_ETSEL_SOCBSEL_Pos)       /*!< SOCBSEL Get Value            */


#define EPWM_REGS_ETSEL_SOCAEN_Pos    (11U)                                                                                 /*!< SOCAEN Postion   11         */ 
#define EPWM_REGS_ETSEL_SOCAEN_Msk    (0x1U << EPWM_REGS_ETSEL_SOCAEN_Pos)                                                  /*!< SOCAEN Mask      0x00000800 */
#define EPWM_REGS_ETSEL_SOCAEN_Set(x) (((uint32_t) (x) << EPWM_REGS_ETSEL_SOCAEN_Pos) & EPWM_REGS_ETSEL_SOCAEN_Msk)         /*!< SOCAEN Set Value            */
#define EPWM_REGS_ETSEL_SOCAEN_Get(x) (((uint32_t) (x) & EPWM_REGS_ETSEL_SOCAEN_Msk) >> EPWM_REGS_ETSEL_SOCAEN_Pos)         /*!< SOCAEN Get Value            */


#define EPWM_REGS_ETSEL_SOCASEL_Pos    (8U)                                                                                  /*!< SOCASEL Postion   8          */ 
#define EPWM_REGS_ETSEL_SOCASEL_Msk    (0x7U << EPWM_REGS_ETSEL_SOCASEL_Pos)                                                 /*!< SOCASEL Mask      0x00000700 */
#define EPWM_REGS_ETSEL_SOCASEL_Set(x) (((uint32_t) (x) << EPWM_REGS_ETSEL_SOCASEL_Pos) & EPWM_REGS_ETSEL_SOCASEL_Msk)       /*!< SOCASEL Set Value            */
#define EPWM_REGS_ETSEL_SOCASEL_Get(x) (((uint32_t) (x) & EPWM_REGS_ETSEL_SOCASEL_Msk) >> EPWM_REGS_ETSEL_SOCASEL_Pos)       /*!< SOCASEL Get Value            */


#define EPWM_REGS_ETSEL_INTSELCMP_Pos    (6U)                                                                                  /*!< INTSELCMP Postion   6          */ 
#define EPWM_REGS_ETSEL_INTSELCMP_Msk    (0x1U << EPWM_REGS_ETSEL_INTSELCMP_Pos)                                               /*!< INTSELCMP Mask      0x00000040 */
#define EPWM_REGS_ETSEL_INTSELCMP_Set(x) (((uint32_t) (x) << EPWM_REGS_ETSEL_INTSELCMP_Pos) & EPWM_REGS_ETSEL_INTSELCMP_Msk)   /*!< INTSELCMP Set Value            */
#define EPWM_REGS_ETSEL_INTSELCMP_Get(x) (((uint32_t) (x) & EPWM_REGS_ETSEL_INTSELCMP_Msk) >> EPWM_REGS_ETSEL_INTSELCMP_Pos)   /*!< INTSELCMP Get Value            */


#define EPWM_REGS_ETSEL_SOCBSELCMP_Pos    (5U)                                                                                  /*!< SOCBSELCMP Postion   5          */ 
#define EPWM_REGS_ETSEL_SOCBSELCMP_Msk    (0x1U << EPWM_REGS_ETSEL_SOCBSELCMP_Pos)                                              /*!< SOCBSELCMP Mask      0x00000020 */
#define EPWM_REGS_ETSEL_SOCBSELCMP_Set(x) (((uint32_t) (x) << EPWM_REGS_ETSEL_SOCBSELCMP_Pos) & EPWM_REGS_ETSEL_SOCBSELCMP_Msk) /*!< SOCBSELCMP Set Value            */
#define EPWM_REGS_ETSEL_SOCBSELCMP_Get(x) (((uint32_t) (x) & EPWM_REGS_ETSEL_SOCBSELCMP_Msk) >> EPWM_REGS_ETSEL_SOCBSELCMP_Pos) /*!< SOCBSELCMP Get Value            */


#define EPWM_REGS_ETSEL_SOCASELCMP_Pos    (4U)                                                                                  /*!< SOCASELCMP Postion   4          */ 
#define EPWM_REGS_ETSEL_SOCASELCMP_Msk    (0x1U << EPWM_REGS_ETSEL_SOCASELCMP_Pos)                                              /*!< SOCASELCMP Mask      0x00000010 */
#define EPWM_REGS_ETSEL_SOCASELCMP_Set(x) (((uint32_t) (x) << EPWM_REGS_ETSEL_SOCASELCMP_Pos) & EPWM_REGS_ETSEL_SOCASELCMP_Msk) /*!< SOCASELCMP Set Value            */
#define EPWM_REGS_ETSEL_SOCASELCMP_Get(x) (((uint32_t) (x) & EPWM_REGS_ETSEL_SOCASELCMP_Msk) >> EPWM_REGS_ETSEL_SOCASELCMP_Pos) /*!< SOCASELCMP Get Value            */


#define EPWM_REGS_ETSEL_INTEN_Pos    (3U)                                                                                  /*!< INTEN Postion   3          */ 
#define EPWM_REGS_ETSEL_INTEN_Msk    (0x1U << EPWM_REGS_ETSEL_INTEN_Pos)                                                   /*!< INTEN Mask      0x00000008 */
#define EPWM_REGS_ETSEL_INTEN_Set(x) (((uint32_t) (x) << EPWM_REGS_ETSEL_INTEN_Pos) & EPWM_REGS_ETSEL_INTEN_Msk)           /*!< INTEN Set Value            */
#define EPWM_REGS_ETSEL_INTEN_Get(x) (((uint32_t) (x) & EPWM_REGS_ETSEL_INTEN_Msk) >> EPWM_REGS_ETSEL_INTEN_Pos)           /*!< INTEN Get Value            */


#define EPWM_REGS_ETSEL_INTSEL_Pos    (0U)                                                                                  /*!< INTSEL Postion   0          */ 
#define EPWM_REGS_ETSEL_INTSEL_Msk    (0x7U << EPWM_REGS_ETSEL_INTSEL_Pos)                                                  /*!< INTSEL Mask      0x00000007 */
#define EPWM_REGS_ETSEL_INTSEL_Set(x) (((uint32_t) (x) << EPWM_REGS_ETSEL_INTSEL_Pos) & EPWM_REGS_ETSEL_INTSEL_Msk)         /*!< INTSEL Set Value            */
#define EPWM_REGS_ETSEL_INTSEL_Get(x) (((uint32_t) (x) & EPWM_REGS_ETSEL_INTSEL_Msk) >> EPWM_REGS_ETSEL_INTSEL_Pos)         /*!< INTSEL Get Value            */


/* ETPS bitfield */
#define EPWM_REGS_ETPS_SOCBCNT_Pos    (14U)                                                                                 /*!< SOCBCNT Postion   14         */ 
#define EPWM_REGS_ETPS_SOCBCNT_Msk    (0x3U << EPWM_REGS_ETPS_SOCBCNT_Pos)                                                  /*!< SOCBCNT Mask      0x0000C000 */
#define EPWM_REGS_ETPS_SOCBCNT_Set(x) (((uint32_t) (x) << EPWM_REGS_ETPS_SOCBCNT_Pos) & EPWM_REGS_ETPS_SOCBCNT_Msk)         /*!< SOCBCNT Set Value            */
#define EPWM_REGS_ETPS_SOCBCNT_Get(x) (((uint32_t) (x) & EPWM_REGS_ETPS_SOCBCNT_Msk) >> EPWM_REGS_ETPS_SOCBCNT_Pos)         /*!< SOCBCNT Get Value            */


#define EPWM_REGS_ETPS_SOCBPRD_Pos    (12U)                                                                                 /*!< SOCBPRD Postion   12         */ 
#define EPWM_REGS_ETPS_SOCBPRD_Msk    (0x3U << EPWM_REGS_ETPS_SOCBPRD_Pos)                                                  /*!< SOCBPRD Mask      0x00003000 */
#define EPWM_REGS_ETPS_SOCBPRD_Set(x) (((uint32_t) (x) << EPWM_REGS_ETPS_SOCBPRD_Pos) & EPWM_REGS_ETPS_SOCBPRD_Msk)         /*!< SOCBPRD Set Value            */
#define EPWM_REGS_ETPS_SOCBPRD_Get(x) (((uint32_t) (x) & EPWM_REGS_ETPS_SOCBPRD_Msk) >> EPWM_REGS_ETPS_SOCBPRD_Pos)         /*!< SOCBPRD Get Value            */


#define EPWM_REGS_ETPS_SOCACNT_Pos    (10U)                                                                                 /*!< SOCACNT Postion   10         */ 
#define EPWM_REGS_ETPS_SOCACNT_Msk    (0x3U << EPWM_REGS_ETPS_SOCACNT_Pos)                                                  /*!< SOCACNT Mask      0x00000C00 */
#define EPWM_REGS_ETPS_SOCACNT_Set(x) (((uint32_t) (x) << EPWM_REGS_ETPS_SOCACNT_Pos) & EPWM_REGS_ETPS_SOCACNT_Msk)         /*!< SOCACNT Set Value            */
#define EPWM_REGS_ETPS_SOCACNT_Get(x) (((uint32_t) (x) & EPWM_REGS_ETPS_SOCACNT_Msk) >> EPWM_REGS_ETPS_SOCACNT_Pos)         /*!< SOCACNT Get Value            */


#define EPWM_REGS_ETPS_SOCAPRD_Pos    (8U)                                                                                  /*!< SOCAPRD Postion   8          */ 
#define EPWM_REGS_ETPS_SOCAPRD_Msk    (0x3U << EPWM_REGS_ETPS_SOCAPRD_Pos)                                                  /*!< SOCAPRD Mask      0x00000300 */
#define EPWM_REGS_ETPS_SOCAPRD_Set(x) (((uint32_t) (x) << EPWM_REGS_ETPS_SOCAPRD_Pos) & EPWM_REGS_ETPS_SOCAPRD_Msk)         /*!< SOCAPRD Set Value            */
#define EPWM_REGS_ETPS_SOCAPRD_Get(x) (((uint32_t) (x) & EPWM_REGS_ETPS_SOCAPRD_Msk) >> EPWM_REGS_ETPS_SOCAPRD_Pos)         /*!< SOCAPRD Get Value            */


#define EPWM_REGS_ETPS_SOCPSSEL_Pos    (5U)                                                                                  /*!< SOCPSSEL Postion   5          */ 
#define EPWM_REGS_ETPS_SOCPSSEL_Msk    (0x1U << EPWM_REGS_ETPS_SOCPSSEL_Pos)                                                 /*!< SOCPSSEL Mask      0x00000020 */
#define EPWM_REGS_ETPS_SOCPSSEL_Set(x) (((uint32_t) (x) << EPWM_REGS_ETPS_SOCPSSEL_Pos) & EPWM_REGS_ETPS_SOCPSSEL_Msk)       /*!< SOCPSSEL Set Value            */
#define EPWM_REGS_ETPS_SOCPSSEL_Get(x) (((uint32_t) (x) & EPWM_REGS_ETPS_SOCPSSEL_Msk) >> EPWM_REGS_ETPS_SOCPSSEL_Pos)       /*!< SOCPSSEL Get Value            */


#define EPWM_REGS_ETPS_INTPSSEL_Pos    (4U)                                                                                  /*!< INTPSSEL Postion   4          */ 
#define EPWM_REGS_ETPS_INTPSSEL_Msk    (0x1U << EPWM_REGS_ETPS_INTPSSEL_Pos)                                                 /*!< INTPSSEL Mask      0x00000010 */
#define EPWM_REGS_ETPS_INTPSSEL_Set(x) (((uint32_t) (x) << EPWM_REGS_ETPS_INTPSSEL_Pos) & EPWM_REGS_ETPS_INTPSSEL_Msk)       /*!< INTPSSEL Set Value            */
#define EPWM_REGS_ETPS_INTPSSEL_Get(x) (((uint32_t) (x) & EPWM_REGS_ETPS_INTPSSEL_Msk) >> EPWM_REGS_ETPS_INTPSSEL_Pos)       /*!< INTPSSEL Get Value            */


#define EPWM_REGS_ETPS_INTCNT_Pos    (2U)                                                                                  /*!< INTCNT Postion   2          */ 
#define EPWM_REGS_ETPS_INTCNT_Msk    (0x3U << EPWM_REGS_ETPS_INTCNT_Pos)                                                   /*!< INTCNT Mask      0x0000000C */
#define EPWM_REGS_ETPS_INTCNT_Set(x) (((uint32_t) (x) << EPWM_REGS_ETPS_INTCNT_Pos) & EPWM_REGS_ETPS_INTCNT_Msk)           /*!< INTCNT Set Value            */
#define EPWM_REGS_ETPS_INTCNT_Get(x) (((uint32_t) (x) & EPWM_REGS_ETPS_INTCNT_Msk) >> EPWM_REGS_ETPS_INTCNT_Pos)           /*!< INTCNT Get Value            */


#define EPWM_REGS_ETPS_INTPRD_Pos    (0U)                                                                                  /*!< INTPRD Postion   0          */ 
#define EPWM_REGS_ETPS_INTPRD_Msk    (0x3U << EPWM_REGS_ETPS_INTPRD_Pos)                                                   /*!< INTPRD Mask      0x00000003 */
#define EPWM_REGS_ETPS_INTPRD_Set(x) (((uint32_t) (x) << EPWM_REGS_ETPS_INTPRD_Pos) & EPWM_REGS_ETPS_INTPRD_Msk)           /*!< INTPRD Set Value            */
#define EPWM_REGS_ETPS_INTPRD_Get(x) (((uint32_t) (x) & EPWM_REGS_ETPS_INTPRD_Msk) >> EPWM_REGS_ETPS_INTPRD_Pos)           /*!< INTPRD Get Value            */


/* ETFLG bitfield */
#define EPWM_REGS_ETFLG_SOCB_Pos    (3U)                                                                                  /*!< SOCB Postion   3          */ 
#define EPWM_REGS_ETFLG_SOCB_Msk    (0x1U << EPWM_REGS_ETFLG_SOCB_Pos)                                                    /*!< SOCB Mask      0x00000008 */
#define EPWM_REGS_ETFLG_SOCB_Set(x) (((uint32_t) (x) << EPWM_REGS_ETFLG_SOCB_Pos) & EPWM_REGS_ETFLG_SOCB_Msk)             /*!< SOCB Set Value            */
#define EPWM_REGS_ETFLG_SOCB_Get(x) (((uint32_t) (x) & EPWM_REGS_ETFLG_SOCB_Msk) >> EPWM_REGS_ETFLG_SOCB_Pos)             /*!< SOCB Get Value            */


#define EPWM_REGS_ETFLG_SOCA_Pos    (2U)                                                                                  /*!< SOCA Postion   2          */ 
#define EPWM_REGS_ETFLG_SOCA_Msk    (0x1U << EPWM_REGS_ETFLG_SOCA_Pos)                                                    /*!< SOCA Mask      0x00000004 */
#define EPWM_REGS_ETFLG_SOCA_Set(x) (((uint32_t) (x) << EPWM_REGS_ETFLG_SOCA_Pos) & EPWM_REGS_ETFLG_SOCA_Msk)             /*!< SOCA Set Value            */
#define EPWM_REGS_ETFLG_SOCA_Get(x) (((uint32_t) (x) & EPWM_REGS_ETFLG_SOCA_Msk) >> EPWM_REGS_ETFLG_SOCA_Pos)             /*!< SOCA Get Value            */


#define EPWM_REGS_ETFLG_ETINT_Pos    (0U)                                                                                  /*!< ETINT Postion   0          */ 
#define EPWM_REGS_ETFLG_ETINT_Msk    (0x1U << EPWM_REGS_ETFLG_ETINT_Pos)                                                   /*!< ETINT Mask      0x00000001 */
#define EPWM_REGS_ETFLG_ETINT_Set(x) (((uint32_t) (x) << EPWM_REGS_ETFLG_ETINT_Pos) & EPWM_REGS_ETFLG_ETINT_Msk)           /*!< ETINT Set Value            */
#define EPWM_REGS_ETFLG_ETINT_Get(x) (((uint32_t) (x) & EPWM_REGS_ETFLG_ETINT_Msk) >> EPWM_REGS_ETFLG_ETINT_Pos)           /*!< ETINT Get Value            */


/* ETCLR bitfield */
#define EPWM_REGS_ETCLR_SOCB_Pos    (3U)                                                                                  /*!< SOCB Postion   3          */ 
#define EPWM_REGS_ETCLR_SOCB_Msk    (0x1U << EPWM_REGS_ETCLR_SOCB_Pos)                                                    /*!< SOCB Mask      0x00000008 */
#define EPWM_REGS_ETCLR_SOCB_Set(x) (((uint32_t) (x) << EPWM_REGS_ETCLR_SOCB_Pos) & EPWM_REGS_ETCLR_SOCB_Msk)             /*!< SOCB Set Value            */
#define EPWM_REGS_ETCLR_SOCB_Get(x) (((uint32_t) (x) & EPWM_REGS_ETCLR_SOCB_Msk) >> EPWM_REGS_ETCLR_SOCB_Pos)             /*!< SOCB Get Value            */


#define EPWM_REGS_ETCLR_SOCA_Pos    (2U)                                                                                  /*!< SOCA Postion   2          */ 
#define EPWM_REGS_ETCLR_SOCA_Msk    (0x1U << EPWM_REGS_ETCLR_SOCA_Pos)                                                    /*!< SOCA Mask      0x00000004 */
#define EPWM_REGS_ETCLR_SOCA_Set(x) (((uint32_t) (x) << EPWM_REGS_ETCLR_SOCA_Pos) & EPWM_REGS_ETCLR_SOCA_Msk)             /*!< SOCA Set Value            */
#define EPWM_REGS_ETCLR_SOCA_Get(x) (((uint32_t) (x) & EPWM_REGS_ETCLR_SOCA_Msk) >> EPWM_REGS_ETCLR_SOCA_Pos)             /*!< SOCA Get Value            */


#define EPWM_REGS_ETCLR_ETINT_Pos    (0U)                                                                                  /*!< ETINT Postion   0          */ 
#define EPWM_REGS_ETCLR_ETINT_Msk    (0x1U << EPWM_REGS_ETCLR_ETINT_Pos)                                                   /*!< ETINT Mask      0x00000001 */
#define EPWM_REGS_ETCLR_ETINT_Set(x) (((uint32_t) (x) << EPWM_REGS_ETCLR_ETINT_Pos) & EPWM_REGS_ETCLR_ETINT_Msk)           /*!< ETINT Set Value            */
#define EPWM_REGS_ETCLR_ETINT_Get(x) (((uint32_t) (x) & EPWM_REGS_ETCLR_ETINT_Msk) >> EPWM_REGS_ETCLR_ETINT_Pos)           /*!< ETINT Get Value            */


/* ETFRC bitfield */
#define EPWM_REGS_ETFRC_SOCB_Pos    (3U)                                                                                  /*!< SOCB Postion   3          */ 
#define EPWM_REGS_ETFRC_SOCB_Msk    (0x1U << EPWM_REGS_ETFRC_SOCB_Pos)                                                    /*!< SOCB Mask      0x00000008 */
#define EPWM_REGS_ETFRC_SOCB_Set(x) (((uint32_t) (x) << EPWM_REGS_ETFRC_SOCB_Pos) & EPWM_REGS_ETFRC_SOCB_Msk)             /*!< SOCB Set Value            */
#define EPWM_REGS_ETFRC_SOCB_Get(x) (((uint32_t) (x) & EPWM_REGS_ETFRC_SOCB_Msk) >> EPWM_REGS_ETFRC_SOCB_Pos)             /*!< SOCB Get Value            */


#define EPWM_REGS_ETFRC_SOCA_Pos    (2U)                                                                                  /*!< SOCA Postion   2          */ 
#define EPWM_REGS_ETFRC_SOCA_Msk    (0x1U << EPWM_REGS_ETFRC_SOCA_Pos)                                                    /*!< SOCA Mask      0x00000004 */
#define EPWM_REGS_ETFRC_SOCA_Set(x) (((uint32_t) (x) << EPWM_REGS_ETFRC_SOCA_Pos) & EPWM_REGS_ETFRC_SOCA_Msk)             /*!< SOCA Set Value            */
#define EPWM_REGS_ETFRC_SOCA_Get(x) (((uint32_t) (x) & EPWM_REGS_ETFRC_SOCA_Msk) >> EPWM_REGS_ETFRC_SOCA_Pos)             /*!< SOCA Get Value            */


#define EPWM_REGS_ETFRC_ETINT_Pos    (0U)                                                                                  /*!< ETINT Postion   0          */ 
#define EPWM_REGS_ETFRC_ETINT_Msk    (0x1U << EPWM_REGS_ETFRC_ETINT_Pos)                                                   /*!< ETINT Mask      0x00000001 */
#define EPWM_REGS_ETFRC_ETINT_Set(x) (((uint32_t) (x) << EPWM_REGS_ETFRC_ETINT_Pos) & EPWM_REGS_ETFRC_ETINT_Msk)           /*!< ETINT Set Value            */
#define EPWM_REGS_ETFRC_ETINT_Get(x) (((uint32_t) (x) & EPWM_REGS_ETFRC_ETINT_Msk) >> EPWM_REGS_ETFRC_ETINT_Pos)           /*!< ETINT Get Value            */


/* ETINTPS bitfield */
#define EPWM_REGS_ETINTPS_INTCNT2_Pos    (4U)                                                                                  /*!< INTCNT2 Postion   4          */ 
#define EPWM_REGS_ETINTPS_INTCNT2_Msk    (0xfU << EPWM_REGS_ETINTPS_INTCNT2_Pos)                                               /*!< INTCNT2 Mask      0x000000F0 */
#define EPWM_REGS_ETINTPS_INTCNT2_Set(x) (((uint32_t) (x) << EPWM_REGS_ETINTPS_INTCNT2_Pos) & EPWM_REGS_ETINTPS_INTCNT2_Msk)   /*!< INTCNT2 Set Value            */
#define EPWM_REGS_ETINTPS_INTCNT2_Get(x) (((uint32_t) (x) & EPWM_REGS_ETINTPS_INTCNT2_Msk) >> EPWM_REGS_ETINTPS_INTCNT2_Pos)   /*!< INTCNT2 Get Value            */


#define EPWM_REGS_ETINTPS_INTPRD2_Pos    (0U)                                                                                  /*!< INTPRD2 Postion   0          */ 
#define EPWM_REGS_ETINTPS_INTPRD2_Msk    (0xfU << EPWM_REGS_ETINTPS_INTPRD2_Pos)                                               /*!< INTPRD2 Mask      0x0000000F */
#define EPWM_REGS_ETINTPS_INTPRD2_Set(x) (((uint32_t) (x) << EPWM_REGS_ETINTPS_INTPRD2_Pos) & EPWM_REGS_ETINTPS_INTPRD2_Msk)   /*!< INTPRD2 Set Value            */
#define EPWM_REGS_ETINTPS_INTPRD2_Get(x) (((uint32_t) (x) & EPWM_REGS_ETINTPS_INTPRD2_Msk) >> EPWM_REGS_ETINTPS_INTPRD2_Pos)   /*!< INTPRD2 Get Value            */


/* ETSOCPS bitfield */
#define EPWM_REGS_ETSOCPS_SOCBCNT2_Pos    (12U)                                                                                 /*!< SOCBCNT2 Postion   12         */ 
#define EPWM_REGS_ETSOCPS_SOCBCNT2_Msk    (0xfU << EPWM_REGS_ETSOCPS_SOCBCNT2_Pos)                                              /*!< SOCBCNT2 Mask      0x0000F000 */
#define EPWM_REGS_ETSOCPS_SOCBCNT2_Set(x) (((uint32_t) (x) << EPWM_REGS_ETSOCPS_SOCBCNT2_Pos) & EPWM_REGS_ETSOCPS_SOCBCNT2_Msk) /*!< SOCBCNT2 Set Value            */
#define EPWM_REGS_ETSOCPS_SOCBCNT2_Get(x) (((uint32_t) (x) & EPWM_REGS_ETSOCPS_SOCBCNT2_Msk) >> EPWM_REGS_ETSOCPS_SOCBCNT2_Pos) /*!< SOCBCNT2 Get Value            */


#define EPWM_REGS_ETSOCPS_SOCBPRD2_Pos    (8U)                                                                                  /*!< SOCBPRD2 Postion   8          */ 
#define EPWM_REGS_ETSOCPS_SOCBPRD2_Msk    (0xfU << EPWM_REGS_ETSOCPS_SOCBPRD2_Pos)                                              /*!< SOCBPRD2 Mask      0x00000F00 */
#define EPWM_REGS_ETSOCPS_SOCBPRD2_Set(x) (((uint32_t) (x) << EPWM_REGS_ETSOCPS_SOCBPRD2_Pos) & EPWM_REGS_ETSOCPS_SOCBPRD2_Msk) /*!< SOCBPRD2 Set Value            */
#define EPWM_REGS_ETSOCPS_SOCBPRD2_Get(x) (((uint32_t) (x) & EPWM_REGS_ETSOCPS_SOCBPRD2_Msk) >> EPWM_REGS_ETSOCPS_SOCBPRD2_Pos) /*!< SOCBPRD2 Get Value            */


#define EPWM_REGS_ETSOCPS_SOCACNT2_Pos    (4U)                                                                                  /*!< SOCACNT2 Postion   4          */ 
#define EPWM_REGS_ETSOCPS_SOCACNT2_Msk    (0xfU << EPWM_REGS_ETSOCPS_SOCACNT2_Pos)                                              /*!< SOCACNT2 Mask      0x000000F0 */
#define EPWM_REGS_ETSOCPS_SOCACNT2_Set(x) (((uint32_t) (x) << EPWM_REGS_ETSOCPS_SOCACNT2_Pos) & EPWM_REGS_ETSOCPS_SOCACNT2_Msk) /*!< SOCACNT2 Set Value            */
#define EPWM_REGS_ETSOCPS_SOCACNT2_Get(x) (((uint32_t) (x) & EPWM_REGS_ETSOCPS_SOCACNT2_Msk) >> EPWM_REGS_ETSOCPS_SOCACNT2_Pos) /*!< SOCACNT2 Get Value            */


#define EPWM_REGS_ETSOCPS_SOCAPRD2_Pos    (0U)                                                                                  /*!< SOCAPRD2 Postion   0          */ 
#define EPWM_REGS_ETSOCPS_SOCAPRD2_Msk    (0xfU << EPWM_REGS_ETSOCPS_SOCAPRD2_Pos)                                              /*!< SOCAPRD2 Mask      0x0000000F */
#define EPWM_REGS_ETSOCPS_SOCAPRD2_Set(x) (((uint32_t) (x) << EPWM_REGS_ETSOCPS_SOCAPRD2_Pos) & EPWM_REGS_ETSOCPS_SOCAPRD2_Msk) /*!< SOCAPRD2 Set Value            */
#define EPWM_REGS_ETSOCPS_SOCAPRD2_Get(x) (((uint32_t) (x) & EPWM_REGS_ETSOCPS_SOCAPRD2_Msk) >> EPWM_REGS_ETSOCPS_SOCAPRD2_Pos) /*!< SOCAPRD2 Get Value            */


/* ETCNTINITCTL bitfield */
#define EPWM_REGS_ETCNTINITCTL_SOCBINITEN_Pos    (15U)                                                                                 /*!< SOCBINITEN Postion   15         */ 
#define EPWM_REGS_ETCNTINITCTL_SOCBINITEN_Msk    (0x1U << EPWM_REGS_ETCNTINITCTL_SOCBINITEN_Pos)                                       /*!< SOCBINITEN Mask      0x00008000 */
#define EPWM_REGS_ETCNTINITCTL_SOCBINITEN_Set(x) (((uint32_t) (x) << EPWM_REGS_ETCNTINITCTL_SOCBINITEN_Pos) & EPWM_REGS_ETCNTINITCTL_SOCBINITEN_Msk) /*!< SOCBINITEN Set Value            */
#define EPWM_REGS_ETCNTINITCTL_SOCBINITEN_Get(x) (((uint32_t) (x) & EPWM_REGS_ETCNTINITCTL_SOCBINITEN_Msk) >> EPWM_REGS_ETCNTINITCTL_SOCBINITEN_Pos) /*!< SOCBINITEN Get Value            */


#define EPWM_REGS_ETCNTINITCTL_SOCAINITEN_Pos    (14U)                                                                                 /*!< SOCAINITEN Postion   14         */ 
#define EPWM_REGS_ETCNTINITCTL_SOCAINITEN_Msk    (0x1U << EPWM_REGS_ETCNTINITCTL_SOCAINITEN_Pos)                                       /*!< SOCAINITEN Mask      0x00004000 */
#define EPWM_REGS_ETCNTINITCTL_SOCAINITEN_Set(x) (((uint32_t) (x) << EPWM_REGS_ETCNTINITCTL_SOCAINITEN_Pos) & EPWM_REGS_ETCNTINITCTL_SOCAINITEN_Msk) /*!< SOCAINITEN Set Value            */
#define EPWM_REGS_ETCNTINITCTL_SOCAINITEN_Get(x) (((uint32_t) (x) & EPWM_REGS_ETCNTINITCTL_SOCAINITEN_Msk) >> EPWM_REGS_ETCNTINITCTL_SOCAINITEN_Pos) /*!< SOCAINITEN Get Value            */


#define EPWM_REGS_ETCNTINITCTL_INTINITEN_Pos    (13U)                                                                                 /*!< INTINITEN Postion   13         */ 
#define EPWM_REGS_ETCNTINITCTL_INTINITEN_Msk    (0x1U << EPWM_REGS_ETCNTINITCTL_INTINITEN_Pos)                                        /*!< INTINITEN Mask      0x00002000 */
#define EPWM_REGS_ETCNTINITCTL_INTINITEN_Set(x) (((uint32_t) (x) << EPWM_REGS_ETCNTINITCTL_INTINITEN_Pos) & EPWM_REGS_ETCNTINITCTL_INTINITEN_Msk) /*!< INTINITEN Set Value            */
#define EPWM_REGS_ETCNTINITCTL_INTINITEN_Get(x) (((uint32_t) (x) & EPWM_REGS_ETCNTINITCTL_INTINITEN_Msk) >> EPWM_REGS_ETCNTINITCTL_INTINITEN_Pos) /*!< INTINITEN Get Value            */


#define EPWM_REGS_ETCNTINITCTL_SOCBINITFRC_Pos    (12U)                                                                                 /*!< SOCBINITFRC Postion   12         */ 
#define EPWM_REGS_ETCNTINITCTL_SOCBINITFRC_Msk    (0x1U << EPWM_REGS_ETCNTINITCTL_SOCBINITFRC_Pos)                                      /*!< SOCBINITFRC Mask      0x00001000 */
#define EPWM_REGS_ETCNTINITCTL_SOCBINITFRC_Set(x) (((uint32_t) (x) << EPWM_REGS_ETCNTINITCTL_SOCBINITFRC_Pos) & EPWM_REGS_ETCNTINITCTL_SOCBINITFRC_Msk) /*!< SOCBINITFRC Set Value            */
#define EPWM_REGS_ETCNTINITCTL_SOCBINITFRC_Get(x) (((uint32_t) (x) & EPWM_REGS_ETCNTINITCTL_SOCBINITFRC_Msk) >> EPWM_REGS_ETCNTINITCTL_SOCBINITFRC_Pos) /*!< SOCBINITFRC Get Value            */


#define EPWM_REGS_ETCNTINITCTL_SOCAINITFRC_Pos    (11U)                                                                                 /*!< SOCAINITFRC Postion   11         */ 
#define EPWM_REGS_ETCNTINITCTL_SOCAINITFRC_Msk    (0x1U << EPWM_REGS_ETCNTINITCTL_SOCAINITFRC_Pos)                                      /*!< SOCAINITFRC Mask      0x00000800 */
#define EPWM_REGS_ETCNTINITCTL_SOCAINITFRC_Set(x) (((uint32_t) (x) << EPWM_REGS_ETCNTINITCTL_SOCAINITFRC_Pos) & EPWM_REGS_ETCNTINITCTL_SOCAINITFRC_Msk) /*!< SOCAINITFRC Set Value            */
#define EPWM_REGS_ETCNTINITCTL_SOCAINITFRC_Get(x) (((uint32_t) (x) & EPWM_REGS_ETCNTINITCTL_SOCAINITFRC_Msk) >> EPWM_REGS_ETCNTINITCTL_SOCAINITFRC_Pos) /*!< SOCAINITFRC Get Value            */


#define EPWM_REGS_ETCNTINITCTL_INTINITFRC_Pos    (10U)                                                                                 /*!< INTINITFRC Postion   10         */ 
#define EPWM_REGS_ETCNTINITCTL_INTINITFRC_Msk    (0x1U << EPWM_REGS_ETCNTINITCTL_INTINITFRC_Pos)                                       /*!< INTINITFRC Mask      0x00000400 */
#define EPWM_REGS_ETCNTINITCTL_INTINITFRC_Set(x) (((uint32_t) (x) << EPWM_REGS_ETCNTINITCTL_INTINITFRC_Pos) & EPWM_REGS_ETCNTINITCTL_INTINITFRC_Msk) /*!< INTINITFRC Set Value            */
#define EPWM_REGS_ETCNTINITCTL_INTINITFRC_Get(x) (((uint32_t) (x) & EPWM_REGS_ETCNTINITCTL_INTINITFRC_Msk) >> EPWM_REGS_ETCNTINITCTL_INTINITFRC_Pos) /*!< INTINITFRC Get Value            */


/* ETCNTINIT bitfield */
#define EPWM_REGS_ETCNTINIT_SOCBINIT_Pos    (8U)                                                                                  /*!< SOCBINIT Postion   8          */ 
#define EPWM_REGS_ETCNTINIT_SOCBINIT_Msk    (0xfU << EPWM_REGS_ETCNTINIT_SOCBINIT_Pos)                                            /*!< SOCBINIT Mask      0x00000F00 */
#define EPWM_REGS_ETCNTINIT_SOCBINIT_Set(x) (((uint32_t) (x) << EPWM_REGS_ETCNTINIT_SOCBINIT_Pos) & EPWM_REGS_ETCNTINIT_SOCBINIT_Msk) /*!< SOCBINIT Set Value            */
#define EPWM_REGS_ETCNTINIT_SOCBINIT_Get(x) (((uint32_t) (x) & EPWM_REGS_ETCNTINIT_SOCBINIT_Msk) >> EPWM_REGS_ETCNTINIT_SOCBINIT_Pos) /*!< SOCBINIT Get Value            */


#define EPWM_REGS_ETCNTINIT_SOCAINIT_Pos    (4U)                                                                                  /*!< SOCAINIT Postion   4          */ 
#define EPWM_REGS_ETCNTINIT_SOCAINIT_Msk    (0xfU << EPWM_REGS_ETCNTINIT_SOCAINIT_Pos)                                            /*!< SOCAINIT Mask      0x000000F0 */
#define EPWM_REGS_ETCNTINIT_SOCAINIT_Set(x) (((uint32_t) (x) << EPWM_REGS_ETCNTINIT_SOCAINIT_Pos) & EPWM_REGS_ETCNTINIT_SOCAINIT_Msk) /*!< SOCAINIT Set Value            */
#define EPWM_REGS_ETCNTINIT_SOCAINIT_Get(x) (((uint32_t) (x) & EPWM_REGS_ETCNTINIT_SOCAINIT_Msk) >> EPWM_REGS_ETCNTINIT_SOCAINIT_Pos) /*!< SOCAINIT Get Value            */


#define EPWM_REGS_ETCNTINIT_INTINIT_Pos    (0U)                                                                                  /*!< INTINIT Postion   0          */ 
#define EPWM_REGS_ETCNTINIT_INTINIT_Msk    (0xfU << EPWM_REGS_ETCNTINIT_INTINIT_Pos)                                             /*!< INTINIT Mask      0x0000000F */
#define EPWM_REGS_ETCNTINIT_INTINIT_Set(x) (((uint32_t) (x) << EPWM_REGS_ETCNTINIT_INTINIT_Pos) & EPWM_REGS_ETCNTINIT_INTINIT_Msk) /*!< INTINIT Set Value            */
#define EPWM_REGS_ETCNTINIT_INTINIT_Get(x) (((uint32_t) (x) & EPWM_REGS_ETCNTINIT_INTINIT_Msk) >> EPWM_REGS_ETCNTINIT_INTINIT_Pos) /*!< INTINIT Get Value            */


/* DCTRIPSEL bitfield */
#define EPWM_REGS_DCTRIPSEL_DCBLCOMPSEL_Pos    (12U)                                                                                 /*!< DCBLCOMPSEL Postion   12         */ 
#define EPWM_REGS_DCTRIPSEL_DCBLCOMPSEL_Msk    (0xfU << EPWM_REGS_DCTRIPSEL_DCBLCOMPSEL_Pos)                                         /*!< DCBLCOMPSEL Mask      0x0000F000 */
#define EPWM_REGS_DCTRIPSEL_DCBLCOMPSEL_Set(x) (((uint32_t) (x) << EPWM_REGS_DCTRIPSEL_DCBLCOMPSEL_Pos) & EPWM_REGS_DCTRIPSEL_DCBLCOMPSEL_Msk) /*!< DCBLCOMPSEL Set Value            */
#define EPWM_REGS_DCTRIPSEL_DCBLCOMPSEL_Get(x) (((uint32_t) (x) & EPWM_REGS_DCTRIPSEL_DCBLCOMPSEL_Msk) >> EPWM_REGS_DCTRIPSEL_DCBLCOMPSEL_Pos) /*!< DCBLCOMPSEL Get Value            */


#define EPWM_REGS_DCTRIPSEL_DCBHCOMPSEL_Pos    (8U)                                                                                  /*!< DCBHCOMPSEL Postion   8          */ 
#define EPWM_REGS_DCTRIPSEL_DCBHCOMPSEL_Msk    (0xfU << EPWM_REGS_DCTRIPSEL_DCBHCOMPSEL_Pos)                                         /*!< DCBHCOMPSEL Mask      0x00000F00 */
#define EPWM_REGS_DCTRIPSEL_DCBHCOMPSEL_Set(x) (((uint32_t) (x) << EPWM_REGS_DCTRIPSEL_DCBHCOMPSEL_Pos) & EPWM_REGS_DCTRIPSEL_DCBHCOMPSEL_Msk) /*!< DCBHCOMPSEL Set Value            */
#define EPWM_REGS_DCTRIPSEL_DCBHCOMPSEL_Get(x) (((uint32_t) (x) & EPWM_REGS_DCTRIPSEL_DCBHCOMPSEL_Msk) >> EPWM_REGS_DCTRIPSEL_DCBHCOMPSEL_Pos) /*!< DCBHCOMPSEL Get Value            */


#define EPWM_REGS_DCTRIPSEL_DCALCOMPSEL_Pos    (4U)                                                                                  /*!< DCALCOMPSEL Postion   4          */ 
#define EPWM_REGS_DCTRIPSEL_DCALCOMPSEL_Msk    (0xfU << EPWM_REGS_DCTRIPSEL_DCALCOMPSEL_Pos)                                         /*!< DCALCOMPSEL Mask      0x000000F0 */
#define EPWM_REGS_DCTRIPSEL_DCALCOMPSEL_Set(x) (((uint32_t) (x) << EPWM_REGS_DCTRIPSEL_DCALCOMPSEL_Pos) & EPWM_REGS_DCTRIPSEL_DCALCOMPSEL_Msk) /*!< DCALCOMPSEL Set Value            */
#define EPWM_REGS_DCTRIPSEL_DCALCOMPSEL_Get(x) (((uint32_t) (x) & EPWM_REGS_DCTRIPSEL_DCALCOMPSEL_Msk) >> EPWM_REGS_DCTRIPSEL_DCALCOMPSEL_Pos) /*!< DCALCOMPSEL Get Value            */


#define EPWM_REGS_DCTRIPSEL_DCAHCOMPSEL_Pos    (0U)                                                                                  /*!< DCAHCOMPSEL Postion   0          */ 
#define EPWM_REGS_DCTRIPSEL_DCAHCOMPSEL_Msk    (0xfU << EPWM_REGS_DCTRIPSEL_DCAHCOMPSEL_Pos)                                         /*!< DCAHCOMPSEL Mask      0x0000000F */
#define EPWM_REGS_DCTRIPSEL_DCAHCOMPSEL_Set(x) (((uint32_t) (x) << EPWM_REGS_DCTRIPSEL_DCAHCOMPSEL_Pos) & EPWM_REGS_DCTRIPSEL_DCAHCOMPSEL_Msk) /*!< DCAHCOMPSEL Set Value            */
#define EPWM_REGS_DCTRIPSEL_DCAHCOMPSEL_Get(x) (((uint32_t) (x) & EPWM_REGS_DCTRIPSEL_DCAHCOMPSEL_Msk) >> EPWM_REGS_DCTRIPSEL_DCAHCOMPSEL_Pos) /*!< DCAHCOMPSEL Get Value            */


/* DCACTL bitfield */
#define EPWM_REGS_DCACTL_EVT2LAT_Pos    (15U)                                                                                 /*!< EVT2LAT Postion   15         */ 
#define EPWM_REGS_DCACTL_EVT2LAT_Msk    (0x1U << EPWM_REGS_DCACTL_EVT2LAT_Pos)                                                /*!< EVT2LAT Mask      0x00008000 */
#define EPWM_REGS_DCACTL_EVT2LAT_Set(x) (((uint16_t) (x) << EPWM_REGS_DCACTL_EVT2LAT_Pos) & EPWM_REGS_DCACTL_EVT2LAT_Msk)     /*!< EVT2LAT Set Value            */
#define EPWM_REGS_DCACTL_EVT2LAT_Get(x) (((uint16_t) (x) & EPWM_REGS_DCACTL_EVT2LAT_Msk) >> EPWM_REGS_DCACTL_EVT2LAT_Pos)     /*!< EVT2LAT Get Value            */


#define EPWM_REGS_DCACTL_EVT2LATCLRSEL_Pos    (13U)                                                                                 /*!< EVT2LATCLRSEL Postion   13         */ 
#define EPWM_REGS_DCACTL_EVT2LATCLRSEL_Msk    (0x3U << EPWM_REGS_DCACTL_EVT2LATCLRSEL_Pos)                                          /*!< EVT2LATCLRSEL Mask      0x00006000 */
#define EPWM_REGS_DCACTL_EVT2LATCLRSEL_Set(x) (((uint16_t) (x) << EPWM_REGS_DCACTL_EVT2LATCLRSEL_Pos) & EPWM_REGS_DCACTL_EVT2LATCLRSEL_Msk) /*!< EVT2LATCLRSEL Set Value            */
#define EPWM_REGS_DCACTL_EVT2LATCLRSEL_Get(x) (((uint16_t) (x) & EPWM_REGS_DCACTL_EVT2LATCLRSEL_Msk) >> EPWM_REGS_DCACTL_EVT2LATCLRSEL_Pos) /*!< EVT2LATCLRSEL Get Value            */


#define EPWM_REGS_DCACTL_EVT2LATSEL_Pos    (12U)                                                                                 /*!< EVT2LATSEL Postion   12         */ 
#define EPWM_REGS_DCACTL_EVT2LATSEL_Msk    (0x1U << EPWM_REGS_DCACTL_EVT2LATSEL_Pos)                                             /*!< EVT2LATSEL Mask      0x00001000 */
#define EPWM_REGS_DCACTL_EVT2LATSEL_Set(x) (((uint16_t) (x) << EPWM_REGS_DCACTL_EVT2LATSEL_Pos) & EPWM_REGS_DCACTL_EVT2LATSEL_Msk) /*!< EVT2LATSEL Set Value            */
#define EPWM_REGS_DCACTL_EVT2LATSEL_Get(x) (((uint16_t) (x) & EPWM_REGS_DCACTL_EVT2LATSEL_Msk) >> EPWM_REGS_DCACTL_EVT2LATSEL_Pos) /*!< EVT2LATSEL Get Value            */


#define EPWM_REGS_DCACTL_EVT2FRCSYNCSEL_Pos    (9U)                                                                                  /*!< EVT2FRCSYNCSEL Postion   9          */ 
#define EPWM_REGS_DCACTL_EVT2FRCSYNCSEL_Msk    (0x1U << EPWM_REGS_DCACTL_EVT2FRCSYNCSEL_Pos)                                         /*!< EVT2FRCSYNCSEL Mask      0x00000200 */
#define EPWM_REGS_DCACTL_EVT2FRCSYNCSEL_Set(x) (((uint16_t) (x) << EPWM_REGS_DCACTL_EVT2FRCSYNCSEL_Pos) & EPWM_REGS_DCACTL_EVT2FRCSYNCSEL_Msk) /*!< EVT2FRCSYNCSEL Set Value            */
#define EPWM_REGS_DCACTL_EVT2FRCSYNCSEL_Get(x) (((uint16_t) (x) & EPWM_REGS_DCACTL_EVT2FRCSYNCSEL_Msk) >> EPWM_REGS_DCACTL_EVT2FRCSYNCSEL_Pos) /*!< EVT2FRCSYNCSEL Get Value            */


#define EPWM_REGS_DCACTL_EVT2SRCSEL_Pos    (8U)                                                                                  /*!< EVT2SRCSEL Postion   8          */ 
#define EPWM_REGS_DCACTL_EVT2SRCSEL_Msk    (0x1U << EPWM_REGS_DCACTL_EVT2SRCSEL_Pos)                                             /*!< EVT2SRCSEL Mask      0x00000100 */
#define EPWM_REGS_DCACTL_EVT2SRCSEL_Set(x) (((uint16_t) (x) << EPWM_REGS_DCACTL_EVT2SRCSEL_Pos) & EPWM_REGS_DCACTL_EVT2SRCSEL_Msk) /*!< EVT2SRCSEL Set Value            */
#define EPWM_REGS_DCACTL_EVT2SRCSEL_Get(x) (((uint16_t) (x) & EPWM_REGS_DCACTL_EVT2SRCSEL_Msk) >> EPWM_REGS_DCACTL_EVT2SRCSEL_Pos) /*!< EVT2SRCSEL Get Value            */


#define EPWM_REGS_DCACTL_EVT1LAT_Pos    (7U)                                                                                  /*!< EVT1LAT Postion   7          */ 
#define EPWM_REGS_DCACTL_EVT1LAT_Msk    (0x1U << EPWM_REGS_DCACTL_EVT1LAT_Pos)                                                /*!< EVT1LAT Mask      0x00000080 */
#define EPWM_REGS_DCACTL_EVT1LAT_Set(x) (((uint16_t) (x) << EPWM_REGS_DCACTL_EVT1LAT_Pos) & EPWM_REGS_DCACTL_EVT1LAT_Msk)     /*!< EVT1LAT Set Value            */
#define EPWM_REGS_DCACTL_EVT1LAT_Get(x) (((uint16_t) (x) & EPWM_REGS_DCACTL_EVT1LAT_Msk) >> EPWM_REGS_DCACTL_EVT1LAT_Pos)     /*!< EVT1LAT Get Value            */


#define EPWM_REGS_DCACTL_EVT1LATCLRSEL_Pos    (5U)                                                                                  /*!< EVT1LATCLRSEL Postion   5          */ 
#define EPWM_REGS_DCACTL_EVT1LATCLRSEL_Msk    (0x3U << EPWM_REGS_DCACTL_EVT1LATCLRSEL_Pos)                                          /*!< EVT1LATCLRSEL Mask      0x00000060 */
#define EPWM_REGS_DCACTL_EVT1LATCLRSEL_Set(x) (((uint16_t) (x) << EPWM_REGS_DCACTL_EVT1LATCLRSEL_Pos) & EPWM_REGS_DCACTL_EVT1LATCLRSEL_Msk) /*!< EVT1LATCLRSEL Set Value            */
#define EPWM_REGS_DCACTL_EVT1LATCLRSEL_Get(x) (((uint16_t) (x) & EPWM_REGS_DCACTL_EVT1LATCLRSEL_Msk) >> EPWM_REGS_DCACTL_EVT1LATCLRSEL_Pos) /*!< EVT1LATCLRSEL Get Value            */


#define EPWM_REGS_DCACTL_EVT1LATSEL_Pos    (4U)                                                                                  /*!< EVT1LATSEL Postion   4          */ 
#define EPWM_REGS_DCACTL_EVT1LATSEL_Msk    (0x1U << EPWM_REGS_DCACTL_EVT1LATSEL_Pos)                                             /*!< EVT1LATSEL Mask      0x00000010 */
#define EPWM_REGS_DCACTL_EVT1LATSEL_Set(x) (((uint16_t) (x) << EPWM_REGS_DCACTL_EVT1LATSEL_Pos) & EPWM_REGS_DCACTL_EVT1LATSEL_Msk) /*!< EVT1LATSEL Set Value            */
#define EPWM_REGS_DCACTL_EVT1LATSEL_Get(x) (((uint16_t) (x) & EPWM_REGS_DCACTL_EVT1LATSEL_Msk) >> EPWM_REGS_DCACTL_EVT1LATSEL_Pos) /*!< EVT1LATSEL Get Value            */


#define EPWM_REGS_DCACTL_EVT1SYNCE_Pos    (3U)                                                                                  /*!< EVT1SYNCE Postion   3          */ 
#define EPWM_REGS_DCACTL_EVT1SYNCE_Msk    (0x1U << EPWM_REGS_DCACTL_EVT1SYNCE_Pos)                                              /*!< EVT1SYNCE Mask      0x00000008 */
#define EPWM_REGS_DCACTL_EVT1SYNCE_Set(x) (((uint16_t) (x) << EPWM_REGS_DCACTL_EVT1SYNCE_Pos) & EPWM_REGS_DCACTL_EVT1SYNCE_Msk) /*!< EVT1SYNCE Set Value            */
#define EPWM_REGS_DCACTL_EVT1SYNCE_Get(x) (((uint16_t) (x) & EPWM_REGS_DCACTL_EVT1SYNCE_Msk) >> EPWM_REGS_DCACTL_EVT1SYNCE_Pos) /*!< EVT1SYNCE Get Value            */


#define EPWM_REGS_DCACTL_EVT1SOCE_Pos    (2U)                                                                                  /*!< EVT1SOCE Postion   2          */ 
#define EPWM_REGS_DCACTL_EVT1SOCE_Msk    (0x1U << EPWM_REGS_DCACTL_EVT1SOCE_Pos)                                               /*!< EVT1SOCE Mask      0x00000004 */
#define EPWM_REGS_DCACTL_EVT1SOCE_Set(x) (((uint16_t) (x) << EPWM_REGS_DCACTL_EVT1SOCE_Pos) & EPWM_REGS_DCACTL_EVT1SOCE_Msk)   /*!< EVT1SOCE Set Value            */
#define EPWM_REGS_DCACTL_EVT1SOCE_Get(x) (((uint16_t) (x) & EPWM_REGS_DCACTL_EVT1SOCE_Msk) >> EPWM_REGS_DCACTL_EVT1SOCE_Pos)   /*!< EVT1SOCE Get Value            */


#define EPWM_REGS_DCACTL_EVT1FRCSYNCSEL_Pos    (1U)                                                                                  /*!< EVT1FRCSYNCSEL Postion   1          */ 
#define EPWM_REGS_DCACTL_EVT1FRCSYNCSEL_Msk    (0x1U << EPWM_REGS_DCACTL_EVT1FRCSYNCSEL_Pos)                                         /*!< EVT1FRCSYNCSEL Mask      0x00000002 */
#define EPWM_REGS_DCACTL_EVT1FRCSYNCSEL_Set(x) (((uint16_t) (x) << EPWM_REGS_DCACTL_EVT1FRCSYNCSEL_Pos) & EPWM_REGS_DCACTL_EVT1FRCSYNCSEL_Msk) /*!< EVT1FRCSYNCSEL Set Value            */
#define EPWM_REGS_DCACTL_EVT1FRCSYNCSEL_Get(x) (((uint16_t) (x) & EPWM_REGS_DCACTL_EVT1FRCSYNCSEL_Msk) >> EPWM_REGS_DCACTL_EVT1FRCSYNCSEL_Pos) /*!< EVT1FRCSYNCSEL Get Value            */


#define EPWM_REGS_DCACTL_EVT1SRCSEL_Pos    (0U)                                                                                  /*!< EVT1SRCSEL Postion   0          */ 
#define EPWM_REGS_DCACTL_EVT1SRCSEL_Msk    (0x1U << EPWM_REGS_DCACTL_EVT1SRCSEL_Pos)                                             /*!< EVT1SRCSEL Mask      0x00000001 */
#define EPWM_REGS_DCACTL_EVT1SRCSEL_Set(x) (((uint16_t) (x) << EPWM_REGS_DCACTL_EVT1SRCSEL_Pos) & EPWM_REGS_DCACTL_EVT1SRCSEL_Msk) /*!< EVT1SRCSEL Set Value            */
#define EPWM_REGS_DCACTL_EVT1SRCSEL_Get(x) (((uint16_t) (x) & EPWM_REGS_DCACTL_EVT1SRCSEL_Msk) >> EPWM_REGS_DCACTL_EVT1SRCSEL_Pos) /*!< EVT1SRCSEL Get Value            */


/* DCBCTL bitfield */
#define EPWM_REGS_DCBCTL_EVT2LAT_Pos    (15U)                                                                                 /*!< EVT2LAT Postion   15         */ 
#define EPWM_REGS_DCBCTL_EVT2LAT_Msk    (0x1U << EPWM_REGS_DCBCTL_EVT2LAT_Pos)                                                /*!< EVT2LAT Mask      0x00008000 */
#define EPWM_REGS_DCBCTL_EVT2LAT_Set(x) (((uint32_t) (x) << EPWM_REGS_DCBCTL_EVT2LAT_Pos) & EPWM_REGS_DCBCTL_EVT2LAT_Msk)     /*!< EVT2LAT Set Value            */
#define EPWM_REGS_DCBCTL_EVT2LAT_Get(x) (((uint32_t) (x) & EPWM_REGS_DCBCTL_EVT2LAT_Msk) >> EPWM_REGS_DCBCTL_EVT2LAT_Pos)     /*!< EVT2LAT Get Value            */


#define EPWM_REGS_DCBCTL_EVT2LATCLRSEL_Pos    (13U)                                                                                 /*!< EVT2LATCLRSEL Postion   13         */ 
#define EPWM_REGS_DCBCTL_EVT2LATCLRSEL_Msk    (0x3U << EPWM_REGS_DCBCTL_EVT2LATCLRSEL_Pos)                                          /*!< EVT2LATCLRSEL Mask      0x00006000 */
#define EPWM_REGS_DCBCTL_EVT2LATCLRSEL_Set(x) (((uint32_t) (x) << EPWM_REGS_DCBCTL_EVT2LATCLRSEL_Pos) & EPWM_REGS_DCBCTL_EVT2LATCLRSEL_Msk) /*!< EVT2LATCLRSEL Set Value            */
#define EPWM_REGS_DCBCTL_EVT2LATCLRSEL_Get(x) (((uint32_t) (x) & EPWM_REGS_DCBCTL_EVT2LATCLRSEL_Msk) >> EPWM_REGS_DCBCTL_EVT2LATCLRSEL_Pos) /*!< EVT2LATCLRSEL Get Value            */


#define EPWM_REGS_DCBCTL_EVT2LATSEL_Pos    (12U)                                                                                 /*!< EVT2LATSEL Postion   12         */ 
#define EPWM_REGS_DCBCTL_EVT2LATSEL_Msk    (0x1U << EPWM_REGS_DCBCTL_EVT2LATSEL_Pos)                                             /*!< EVT2LATSEL Mask      0x00001000 */
#define EPWM_REGS_DCBCTL_EVT2LATSEL_Set(x) (((uint32_t) (x) << EPWM_REGS_DCBCTL_EVT2LATSEL_Pos) & EPWM_REGS_DCBCTL_EVT2LATSEL_Msk) /*!< EVT2LATSEL Set Value            */
#define EPWM_REGS_DCBCTL_EVT2LATSEL_Get(x) (((uint32_t) (x) & EPWM_REGS_DCBCTL_EVT2LATSEL_Msk) >> EPWM_REGS_DCBCTL_EVT2LATSEL_Pos) /*!< EVT2LATSEL Get Value            */


#define EPWM_REGS_DCBCTL_EVT2FRCSYNCSEL_Pos    (9U)                                                                                  /*!< EVT2FRCSYNCSEL Postion   9          */ 
#define EPWM_REGS_DCBCTL_EVT2FRCSYNCSEL_Msk    (0x1U << EPWM_REGS_DCBCTL_EVT2FRCSYNCSEL_Pos)                                         /*!< EVT2FRCSYNCSEL Mask      0x00000200 */
#define EPWM_REGS_DCBCTL_EVT2FRCSYNCSEL_Set(x) (((uint32_t) (x) << EPWM_REGS_DCBCTL_EVT2FRCSYNCSEL_Pos) & EPWM_REGS_DCBCTL_EVT2FRCSYNCSEL_Msk) /*!< EVT2FRCSYNCSEL Set Value            */
#define EPWM_REGS_DCBCTL_EVT2FRCSYNCSEL_Get(x) (((uint32_t) (x) & EPWM_REGS_DCBCTL_EVT2FRCSYNCSEL_Msk) >> EPWM_REGS_DCBCTL_EVT2FRCSYNCSEL_Pos) /*!< EVT2FRCSYNCSEL Get Value            */


#define EPWM_REGS_DCBCTL_EVT2SRCSEL_Pos    (8U)                                                                                  /*!< EVT2SRCSEL Postion   8          */ 
#define EPWM_REGS_DCBCTL_EVT2SRCSEL_Msk    (0x1U << EPWM_REGS_DCBCTL_EVT2SRCSEL_Pos)                                             /*!< EVT2SRCSEL Mask      0x00000100 */
#define EPWM_REGS_DCBCTL_EVT2SRCSEL_Set(x) (((uint32_t) (x) << EPWM_REGS_DCBCTL_EVT2SRCSEL_Pos) & EPWM_REGS_DCBCTL_EVT2SRCSEL_Msk) /*!< EVT2SRCSEL Set Value            */
#define EPWM_REGS_DCBCTL_EVT2SRCSEL_Get(x) (((uint32_t) (x) & EPWM_REGS_DCBCTL_EVT2SRCSEL_Msk) >> EPWM_REGS_DCBCTL_EVT2SRCSEL_Pos) /*!< EVT2SRCSEL Get Value            */


#define EPWM_REGS_DCBCTL_EVT1LAT_Pos    (7U)                                                                                  /*!< EVT1LAT Postion   7          */ 
#define EPWM_REGS_DCBCTL_EVT1LAT_Msk    (0x1U << EPWM_REGS_DCBCTL_EVT1LAT_Pos)                                                /*!< EVT1LAT Mask      0x00000080 */
#define EPWM_REGS_DCBCTL_EVT1LAT_Set(x) (((uint32_t) (x) << EPWM_REGS_DCBCTL_EVT1LAT_Pos) & EPWM_REGS_DCBCTL_EVT1LAT_Msk)     /*!< EVT1LAT Set Value            */
#define EPWM_REGS_DCBCTL_EVT1LAT_Get(x) (((uint32_t) (x) & EPWM_REGS_DCBCTL_EVT1LAT_Msk) >> EPWM_REGS_DCBCTL_EVT1LAT_Pos)     /*!< EVT1LAT Get Value            */


#define EPWM_REGS_DCBCTL_EVT1LATCLRSEL_Pos    (5U)                                                                                  /*!< EVT1LATCLRSEL Postion   5          */ 
#define EPWM_REGS_DCBCTL_EVT1LATCLRSEL_Msk    (0x3U << EPWM_REGS_DCBCTL_EVT1LATCLRSEL_Pos)                                          /*!< EVT1LATCLRSEL Mask      0x00000060 */
#define EPWM_REGS_DCBCTL_EVT1LATCLRSEL_Set(x) (((uint32_t) (x) << EPWM_REGS_DCBCTL_EVT1LATCLRSEL_Pos) & EPWM_REGS_DCBCTL_EVT1LATCLRSEL_Msk) /*!< EVT1LATCLRSEL Set Value            */
#define EPWM_REGS_DCBCTL_EVT1LATCLRSEL_Get(x) (((uint32_t) (x) & EPWM_REGS_DCBCTL_EVT1LATCLRSEL_Msk) >> EPWM_REGS_DCBCTL_EVT1LATCLRSEL_Pos) /*!< EVT1LATCLRSEL Get Value            */


#define EPWM_REGS_DCBCTL_EVT1LATSEL_Pos    (4U)                                                                                  /*!< EVT1LATSEL Postion   4          */ 
#define EPWM_REGS_DCBCTL_EVT1LATSEL_Msk    (0x1U << EPWM_REGS_DCBCTL_EVT1LATSEL_Pos)                                             /*!< EVT1LATSEL Mask      0x00000010 */
#define EPWM_REGS_DCBCTL_EVT1LATSEL_Set(x) (((uint32_t) (x) << EPWM_REGS_DCBCTL_EVT1LATSEL_Pos) & EPWM_REGS_DCBCTL_EVT1LATSEL_Msk) /*!< EVT1LATSEL Set Value            */
#define EPWM_REGS_DCBCTL_EVT1LATSEL_Get(x) (((uint32_t) (x) & EPWM_REGS_DCBCTL_EVT1LATSEL_Msk) >> EPWM_REGS_DCBCTL_EVT1LATSEL_Pos) /*!< EVT1LATSEL Get Value            */


#define EPWM_REGS_DCBCTL_EVT1SYNCE_Pos    (3U)                                                                                  /*!< EVT1SYNCE Postion   3          */ 
#define EPWM_REGS_DCBCTL_EVT1SYNCE_Msk    (0x1U << EPWM_REGS_DCBCTL_EVT1SYNCE_Pos)                                              /*!< EVT1SYNCE Mask      0x00000008 */
#define EPWM_REGS_DCBCTL_EVT1SYNCE_Set(x) (((uint32_t) (x) << EPWM_REGS_DCBCTL_EVT1SYNCE_Pos) & EPWM_REGS_DCBCTL_EVT1SYNCE_Msk) /*!< EVT1SYNCE Set Value            */
#define EPWM_REGS_DCBCTL_EVT1SYNCE_Get(x) (((uint32_t) (x) & EPWM_REGS_DCBCTL_EVT1SYNCE_Msk) >> EPWM_REGS_DCBCTL_EVT1SYNCE_Pos) /*!< EVT1SYNCE Get Value            */


#define EPWM_REGS_DCBCTL_EVT1SOCE_Pos    (2U)                                                                                  /*!< EVT1SOCE Postion   2          */ 
#define EPWM_REGS_DCBCTL_EVT1SOCE_Msk    (0x1U << EPWM_REGS_DCBCTL_EVT1SOCE_Pos)                                               /*!< EVT1SOCE Mask      0x00000004 */
#define EPWM_REGS_DCBCTL_EVT1SOCE_Set(x) (((uint32_t) (x) << EPWM_REGS_DCBCTL_EVT1SOCE_Pos) & EPWM_REGS_DCBCTL_EVT1SOCE_Msk)   /*!< EVT1SOCE Set Value            */
#define EPWM_REGS_DCBCTL_EVT1SOCE_Get(x) (((uint32_t) (x) & EPWM_REGS_DCBCTL_EVT1SOCE_Msk) >> EPWM_REGS_DCBCTL_EVT1SOCE_Pos)   /*!< EVT1SOCE Get Value            */


#define EPWM_REGS_DCBCTL_EVT1FRCSYNCSEL_Pos    (1U)                                                                                  /*!< EVT1FRCSYNCSEL Postion   1          */ 
#define EPWM_REGS_DCBCTL_EVT1FRCSYNCSEL_Msk    (0x1U << EPWM_REGS_DCBCTL_EVT1FRCSYNCSEL_Pos)                                         /*!< EVT1FRCSYNCSEL Mask      0x00000002 */
#define EPWM_REGS_DCBCTL_EVT1FRCSYNCSEL_Set(x) (((uint32_t) (x) << EPWM_REGS_DCBCTL_EVT1FRCSYNCSEL_Pos) & EPWM_REGS_DCBCTL_EVT1FRCSYNCSEL_Msk) /*!< EVT1FRCSYNCSEL Set Value            */
#define EPWM_REGS_DCBCTL_EVT1FRCSYNCSEL_Get(x) (((uint32_t) (x) & EPWM_REGS_DCBCTL_EVT1FRCSYNCSEL_Msk) >> EPWM_REGS_DCBCTL_EVT1FRCSYNCSEL_Pos) /*!< EVT1FRCSYNCSEL Get Value            */


#define EPWM_REGS_DCBCTL_EVT1SRCSEL_Pos    (0U)                                                                                  /*!< EVT1SRCSEL Postion   0          */ 
#define EPWM_REGS_DCBCTL_EVT1SRCSEL_Msk    (0x1U << EPWM_REGS_DCBCTL_EVT1SRCSEL_Pos)                                             /*!< EVT1SRCSEL Mask      0x00000001 */
#define EPWM_REGS_DCBCTL_EVT1SRCSEL_Set(x) (((uint32_t) (x) << EPWM_REGS_DCBCTL_EVT1SRCSEL_Pos) & EPWM_REGS_DCBCTL_EVT1SRCSEL_Msk) /*!< EVT1SRCSEL Set Value            */
#define EPWM_REGS_DCBCTL_EVT1SRCSEL_Get(x) (((uint32_t) (x) & EPWM_REGS_DCBCTL_EVT1SRCSEL_Msk) >> EPWM_REGS_DCBCTL_EVT1SRCSEL_Pos) /*!< EVT1SRCSEL Get Value            */


/* DCFCTL bitfield */
#define EPWM_REGS_DCFCTL_EDGESTATUS_Pos    (13U)                                                                                 /*!< EDGESTATUS Postion   13         */ 
#define EPWM_REGS_DCFCTL_EDGESTATUS_Msk    (0x7U << EPWM_REGS_DCFCTL_EDGESTATUS_Pos)                                             /*!< EDGESTATUS Mask      0x0000E000 */
#define EPWM_REGS_DCFCTL_EDGESTATUS_Set(x) (((uint16_t) (x) << EPWM_REGS_DCFCTL_EDGESTATUS_Pos) & EPWM_REGS_DCFCTL_EDGESTATUS_Msk) /*!< EDGESTATUS Set Value            */
#define EPWM_REGS_DCFCTL_EDGESTATUS_Get(x) (((uint16_t) (x) & EPWM_REGS_DCFCTL_EDGESTATUS_Msk) >> EPWM_REGS_DCFCTL_EDGESTATUS_Pos) /*!< EDGESTATUS Get Value            */


#define EPWM_REGS_DCFCTL_EDGECOUNT_Pos    (10U)                                                                                 /*!< EDGECOUNT Postion   10         */ 
#define EPWM_REGS_DCFCTL_EDGECOUNT_Msk    (0x7U << EPWM_REGS_DCFCTL_EDGECOUNT_Pos)                                              /*!< EDGECOUNT Mask      0x00001C00 */
#define EPWM_REGS_DCFCTL_EDGECOUNT_Set(x) (((uint16_t) (x) << EPWM_REGS_DCFCTL_EDGECOUNT_Pos) & EPWM_REGS_DCFCTL_EDGECOUNT_Msk) /*!< EDGECOUNT Set Value            */
#define EPWM_REGS_DCFCTL_EDGECOUNT_Get(x) (((uint16_t) (x) & EPWM_REGS_DCFCTL_EDGECOUNT_Msk) >> EPWM_REGS_DCFCTL_EDGECOUNT_Pos) /*!< EDGECOUNT Get Value            */


#define EPWM_REGS_DCFCTL_EDGEMODE_Pos    (8U)                                                                                  /*!< EDGEMODE Postion   8          */ 
#define EPWM_REGS_DCFCTL_EDGEMODE_Msk    (0x3U << EPWM_REGS_DCFCTL_EDGEMODE_Pos)                                               /*!< EDGEMODE Mask      0x00000300 */
#define EPWM_REGS_DCFCTL_EDGEMODE_Set(x) (((uint16_t) (x) << EPWM_REGS_DCFCTL_EDGEMODE_Pos) & EPWM_REGS_DCFCTL_EDGEMODE_Msk)   /*!< EDGEMODE Set Value            */
#define EPWM_REGS_DCFCTL_EDGEMODE_Get(x) (((uint16_t) (x) & EPWM_REGS_DCFCTL_EDGEMODE_Msk) >> EPWM_REGS_DCFCTL_EDGEMODE_Pos)   /*!< EDGEMODE Get Value            */


#define EPWM_REGS_DCFCTL_EDGEFILTSEL_Pos    (6U)                                                                                  /*!< EDGEFILTSEL Postion   6          */ 
#define EPWM_REGS_DCFCTL_EDGEFILTSEL_Msk    (0x1U << EPWM_REGS_DCFCTL_EDGEFILTSEL_Pos)                                            /*!< EDGEFILTSEL Mask      0x00000040 */
#define EPWM_REGS_DCFCTL_EDGEFILTSEL_Set(x) (((uint16_t) (x) << EPWM_REGS_DCFCTL_EDGEFILTSEL_Pos) & EPWM_REGS_DCFCTL_EDGEFILTSEL_Msk) /*!< EDGEFILTSEL Set Value            */
#define EPWM_REGS_DCFCTL_EDGEFILTSEL_Get(x) (((uint16_t) (x) & EPWM_REGS_DCFCTL_EDGEFILTSEL_Msk) >> EPWM_REGS_DCFCTL_EDGEFILTSEL_Pos) /*!< EDGEFILTSEL Get Value            */


#define EPWM_REGS_DCFCTL_PULSESEL_Pos    (4U)                                                                                  /*!< PULSESEL Postion   4          */ 
#define EPWM_REGS_DCFCTL_PULSESEL_Msk    (0x3U << EPWM_REGS_DCFCTL_PULSESEL_Pos)                                               /*!< PULSESEL Mask      0x00000030 */
#define EPWM_REGS_DCFCTL_PULSESEL_Set(x) (((uint16_t) (x) << EPWM_REGS_DCFCTL_PULSESEL_Pos) & EPWM_REGS_DCFCTL_PULSESEL_Msk)   /*!< PULSESEL Set Value            */
#define EPWM_REGS_DCFCTL_PULSESEL_Get(x) (((uint16_t) (x) & EPWM_REGS_DCFCTL_PULSESEL_Msk) >> EPWM_REGS_DCFCTL_PULSESEL_Pos)   /*!< PULSESEL Get Value            */


#define EPWM_REGS_DCFCTL_BLANKINV_Pos    (3U)                                                                                  /*!< BLANKINV Postion   3          */ 
#define EPWM_REGS_DCFCTL_BLANKINV_Msk    (0x1U << EPWM_REGS_DCFCTL_BLANKINV_Pos)                                               /*!< BLANKINV Mask      0x00000008 */
#define EPWM_REGS_DCFCTL_BLANKINV_Set(x) (((uint16_t) (x) << EPWM_REGS_DCFCTL_BLANKINV_Pos) & EPWM_REGS_DCFCTL_BLANKINV_Msk)   /*!< BLANKINV Set Value            */
#define EPWM_REGS_DCFCTL_BLANKINV_Get(x) (((uint16_t) (x) & EPWM_REGS_DCFCTL_BLANKINV_Msk) >> EPWM_REGS_DCFCTL_BLANKINV_Pos)   /*!< BLANKINV Get Value            */


#define EPWM_REGS_DCFCTL_BLANKE_Pos    (2U)                                                                                  /*!< BLANKE Postion   2          */ 
#define EPWM_REGS_DCFCTL_BLANKE_Msk    (0x1U << EPWM_REGS_DCFCTL_BLANKE_Pos)                                                 /*!< BLANKE Mask      0x00000004 */
#define EPWM_REGS_DCFCTL_BLANKE_Set(x) (((uint16_t) (x) << EPWM_REGS_DCFCTL_BLANKE_Pos) & EPWM_REGS_DCFCTL_BLANKE_Msk)       /*!< BLANKE Set Value            */
#define EPWM_REGS_DCFCTL_BLANKE_Get(x) (((uint16_t) (x) & EPWM_REGS_DCFCTL_BLANKE_Msk) >> EPWM_REGS_DCFCTL_BLANKE_Pos)       /*!< BLANKE Get Value            */


#define EPWM_REGS_DCFCTL_SRCSEL_Pos    (0U)                                                                                  /*!< SRCSEL Postion   0          */ 
#define EPWM_REGS_DCFCTL_SRCSEL_Msk    (0x3U << EPWM_REGS_DCFCTL_SRCSEL_Pos)                                                 /*!< SRCSEL Mask      0x00000003 */
#define EPWM_REGS_DCFCTL_SRCSEL_Set(x) (((uint16_t) (x) << EPWM_REGS_DCFCTL_SRCSEL_Pos) & EPWM_REGS_DCFCTL_SRCSEL_Msk)       /*!< SRCSEL Set Value            */
#define EPWM_REGS_DCFCTL_SRCSEL_Get(x) (((uint16_t) (x) & EPWM_REGS_DCFCTL_SRCSEL_Msk) >> EPWM_REGS_DCFCTL_SRCSEL_Pos)       /*!< SRCSEL Get Value            */


/* DCCAPCTL bitfield */
#define EPWM_REGS_DCCAPCTL_CAPMODE_Pos    (15U)                                                                                 /*!< CAPMODE Postion   15         */ 
#define EPWM_REGS_DCCAPCTL_CAPMODE_Msk    (0x1U << EPWM_REGS_DCCAPCTL_CAPMODE_Pos)                                              /*!< CAPMODE Mask      0x00008000 */
#define EPWM_REGS_DCCAPCTL_CAPMODE_Set(x) (((uint16_t) (x) << EPWM_REGS_DCCAPCTL_CAPMODE_Pos) & EPWM_REGS_DCCAPCTL_CAPMODE_Msk) /*!< CAPMODE Set Value            */
#define EPWM_REGS_DCCAPCTL_CAPMODE_Get(x) (((uint16_t) (x) & EPWM_REGS_DCCAPCTL_CAPMODE_Msk) >> EPWM_REGS_DCCAPCTL_CAPMODE_Pos) /*!< CAPMODE Get Value            */


#define EPWM_REGS_DCCAPCTL_CAPCLR_Pos    (14U)                                                                                 /*!< CAPCLR Postion   14         */ 
#define EPWM_REGS_DCCAPCTL_CAPCLR_Msk    (0x1U << EPWM_REGS_DCCAPCTL_CAPCLR_Pos)                                               /*!< CAPCLR Mask      0x00004000 */
#define EPWM_REGS_DCCAPCTL_CAPCLR_Set(x) (((uint16_t) (x) << EPWM_REGS_DCCAPCTL_CAPCLR_Pos) & EPWM_REGS_DCCAPCTL_CAPCLR_Msk)   /*!< CAPCLR Set Value            */
#define EPWM_REGS_DCCAPCTL_CAPCLR_Get(x) (((uint16_t) (x) & EPWM_REGS_DCCAPCTL_CAPCLR_Msk) >> EPWM_REGS_DCCAPCTL_CAPCLR_Pos)   /*!< CAPCLR Get Value            */


#define EPWM_REGS_DCCAPCTL_CAPSTS_Pos    (13U)                                                                                 /*!< CAPSTS Postion   13         */ 
#define EPWM_REGS_DCCAPCTL_CAPSTS_Msk    (0x1U << EPWM_REGS_DCCAPCTL_CAPSTS_Pos)                                               /*!< CAPSTS Mask      0x00002000 */
#define EPWM_REGS_DCCAPCTL_CAPSTS_Set(x) (((uint16_t) (x) << EPWM_REGS_DCCAPCTL_CAPSTS_Pos) & EPWM_REGS_DCCAPCTL_CAPSTS_Msk)   /*!< CAPSTS Set Value            */
#define EPWM_REGS_DCCAPCTL_CAPSTS_Get(x) (((uint16_t) (x) & EPWM_REGS_DCCAPCTL_CAPSTS_Msk) >> EPWM_REGS_DCCAPCTL_CAPSTS_Pos)   /*!< CAPSTS Get Value            */


#define EPWM_REGS_DCCAPCTL_SHDWMODE_Pos    (1U)                                                                                  /*!< SHDWMODE Postion   1          */ 
#define EPWM_REGS_DCCAPCTL_SHDWMODE_Msk    (0x1U << EPWM_REGS_DCCAPCTL_SHDWMODE_Pos)                                             /*!< SHDWMODE Mask      0x00000002 */
#define EPWM_REGS_DCCAPCTL_SHDWMODE_Set(x) (((uint16_t) (x) << EPWM_REGS_DCCAPCTL_SHDWMODE_Pos) & EPWM_REGS_DCCAPCTL_SHDWMODE_Msk) /*!< SHDWMODE Set Value            */
#define EPWM_REGS_DCCAPCTL_SHDWMODE_Get(x) (((uint16_t) (x) & EPWM_REGS_DCCAPCTL_SHDWMODE_Msk) >> EPWM_REGS_DCCAPCTL_SHDWMODE_Pos) /*!< SHDWMODE Get Value            */


#define EPWM_REGS_DCCAPCTL_CAPE_Pos    (0U)                                                                                  /*!< CAPE Postion   0          */ 
#define EPWM_REGS_DCCAPCTL_CAPE_Msk    (0x1U << EPWM_REGS_DCCAPCTL_CAPE_Pos)                                                 /*!< CAPE Mask      0x00000001 */
#define EPWM_REGS_DCCAPCTL_CAPE_Set(x) (((uint16_t) (x) << EPWM_REGS_DCCAPCTL_CAPE_Pos) & EPWM_REGS_DCCAPCTL_CAPE_Msk)       /*!< CAPE Set Value            */
#define EPWM_REGS_DCCAPCTL_CAPE_Get(x) (((uint16_t) (x) & EPWM_REGS_DCCAPCTL_CAPE_Msk) >> EPWM_REGS_DCCAPCTL_CAPE_Pos)       /*!< CAPE Get Value            */


/* DCFOFFSET bitfield */
#define EPWM_REGS_DCFOFFSET_DCFOFFSET_Pos    (0U)                                                                                  /*!< DCFOFFSET Postion   0          */ 
#define EPWM_REGS_DCFOFFSET_DCFOFFSET_Msk    (0xffffU << EPWM_REGS_DCFOFFSET_DCFOFFSET_Pos)                                        /*!< DCFOFFSET Mask      0x0000FFFF */
#define EPWM_REGS_DCFOFFSET_DCFOFFSET_Set(x) (((uint16_t) (x) << EPWM_REGS_DCFOFFSET_DCFOFFSET_Pos) & EPWM_REGS_DCFOFFSET_DCFOFFSET_Msk) /*!< DCFOFFSET Set Value            */
#define EPWM_REGS_DCFOFFSET_DCFOFFSET_Get(x) (((uint16_t) (x) & EPWM_REGS_DCFOFFSET_DCFOFFSET_Msk) >> EPWM_REGS_DCFOFFSET_DCFOFFSET_Pos) /*!< DCFOFFSET Get Value            */


/* DCFOFFSETCNT bitfield */
#define EPWM_REGS_DCFOFFSETCNT_DCFOFFSETCNT_Pos    (0U)                                                                                  /*!< DCFOFFSETCNT Postion   0          */ 
#define EPWM_REGS_DCFOFFSETCNT_DCFOFFSETCNT_Msk    (0xffffU << EPWM_REGS_DCFOFFSETCNT_DCFOFFSETCNT_Pos)                                  /*!< DCFOFFSETCNT Mask      0x0000FFFF */
#define EPWM_REGS_DCFOFFSETCNT_DCFOFFSETCNT_Set(x) (((uint16_t) (x) << EPWM_REGS_DCFOFFSETCNT_DCFOFFSETCNT_Pos) & EPWM_REGS_DCFOFFSETCNT_DCFOFFSETCNT_Msk) /*!< DCFOFFSETCNT Set Value            */
#define EPWM_REGS_DCFOFFSETCNT_DCFOFFSETCNT_Get(x) (((uint16_t) (x) & EPWM_REGS_DCFOFFSETCNT_DCFOFFSETCNT_Msk) >> EPWM_REGS_DCFOFFSETCNT_DCFOFFSETCNT_Pos) /*!< DCFOFFSETCNT Get Value            */


/* DCFWINDOW bitfield */
#define EPWM_REGS_DCFWINDOW_DCFWINDOW_Pos    (0U)                                                                                  /*!< DCFWINDOW Postion   0          */ 
#define EPWM_REGS_DCFWINDOW_DCFWINDOW_Msk    (0xffffU << EPWM_REGS_DCFWINDOW_DCFWINDOW_Pos)                                        /*!< DCFWINDOW Mask      0x0000FFFF */
#define EPWM_REGS_DCFWINDOW_DCFWINDOW_Set(x) (((uint16_t) (x) << EPWM_REGS_DCFWINDOW_DCFWINDOW_Pos) & EPWM_REGS_DCFWINDOW_DCFWINDOW_Msk) /*!< DCFWINDOW Set Value            */
#define EPWM_REGS_DCFWINDOW_DCFWINDOW_Get(x) (((uint16_t) (x) & EPWM_REGS_DCFWINDOW_DCFWINDOW_Msk) >> EPWM_REGS_DCFWINDOW_DCFWINDOW_Pos) /*!< DCFWINDOW Get Value            */


/* DCFWINDOWCNT bitfield */
#define EPWM_REGS_DCFWINDOWCNT_DCFWINDOW_Pos    (0U)                                                                                  /*!< DCFWINDOW Postion   0          */ 
#define EPWM_REGS_DCFWINDOWCNT_DCFWINDOW_Msk    (0xffffU << EPWM_REGS_DCFWINDOWCNT_DCFWINDOW_Pos)                                     /*!< DCFWINDOW Mask      0x0000FFFF */
#define EPWM_REGS_DCFWINDOWCNT_DCFWINDOW_Set(x) (((uint32_t) (x) << EPWM_REGS_DCFWINDOWCNT_DCFWINDOW_Pos) & EPWM_REGS_DCFWINDOWCNT_DCFWINDOW_Msk) /*!< DCFWINDOW Set Value            */
#define EPWM_REGS_DCFWINDOWCNT_DCFWINDOW_Get(x) (((uint32_t) (x) & EPWM_REGS_DCFWINDOWCNT_DCFWINDOW_Msk) >> EPWM_REGS_DCFWINDOWCNT_DCFWINDOW_Pos) /*!< DCFWINDOW Get Value            */


/* DCCAP bitfield */
#define EPWM_REGS_DCCAP_DCCAP_Pos    (0U)                                                                                  /*!< DCCAP Postion   0          */ 
#define EPWM_REGS_DCCAP_DCCAP_Msk    (0xffffU << EPWM_REGS_DCCAP_DCCAP_Pos)                                                /*!< DCCAP Mask      0x0000FFFF */
#define EPWM_REGS_DCCAP_DCCAP_Set(x) (((uint16_t) (x) << EPWM_REGS_DCCAP_DCCAP_Pos) & EPWM_REGS_DCCAP_DCCAP_Msk)           /*!< DCCAP Set Value            */
#define EPWM_REGS_DCCAP_DCCAP_Get(x) (((uint16_t) (x) & EPWM_REGS_DCCAP_DCCAP_Msk) >> EPWM_REGS_DCCAP_DCCAP_Pos)           /*!< DCCAP Get Value            */


/* DCAHTRIPSEL bitfield */
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT15_Pos    (14U)                                                                                 /*!< TRIPINPUT15 Postion   14         */ 
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT15_Msk    (0x1U << EPWM_REGS_DCAHTRIPSEL_TRIPINPUT15_Pos)                                       /*!< TRIPINPUT15 Mask      0x00004000 */
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT15_Set(x) (((uint16_t) (x) << EPWM_REGS_DCAHTRIPSEL_TRIPINPUT15_Pos) & EPWM_REGS_DCAHTRIPSEL_TRIPINPUT15_Msk) /*!< TRIPINPUT15 Set Value            */
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT15_Get(x) (((uint16_t) (x) & EPWM_REGS_DCAHTRIPSEL_TRIPINPUT15_Msk) >> EPWM_REGS_DCAHTRIPSEL_TRIPINPUT15_Pos) /*!< TRIPINPUT15 Get Value            */


#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT14_Pos    (13U)                                                                                 /*!< TRIPINPUT14 Postion   13         */ 
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT14_Msk    (0x1U << EPWM_REGS_DCAHTRIPSEL_TRIPINPUT14_Pos)                                       /*!< TRIPINPUT14 Mask      0x00002000 */
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT14_Set(x) (((uint16_t) (x) << EPWM_REGS_DCAHTRIPSEL_TRIPINPUT14_Pos) & EPWM_REGS_DCAHTRIPSEL_TRIPINPUT14_Msk) /*!< TRIPINPUT14 Set Value            */
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT14_Get(x) (((uint16_t) (x) & EPWM_REGS_DCAHTRIPSEL_TRIPINPUT14_Msk) >> EPWM_REGS_DCAHTRIPSEL_TRIPINPUT14_Pos) /*!< TRIPINPUT14 Get Value            */


#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT12_Pos    (11U)                                                                                 /*!< TRIPINPUT12 Postion   11         */ 
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT12_Msk    (0x1U << EPWM_REGS_DCAHTRIPSEL_TRIPINPUT12_Pos)                                       /*!< TRIPINPUT12 Mask      0x00000800 */
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT12_Set(x) (((uint16_t) (x) << EPWM_REGS_DCAHTRIPSEL_TRIPINPUT12_Pos) & EPWM_REGS_DCAHTRIPSEL_TRIPINPUT12_Msk) /*!< TRIPINPUT12 Set Value            */
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT12_Get(x) (((uint16_t) (x) & EPWM_REGS_DCAHTRIPSEL_TRIPINPUT12_Msk) >> EPWM_REGS_DCAHTRIPSEL_TRIPINPUT12_Pos) /*!< TRIPINPUT12 Get Value            */


#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT11_Pos    (10U)                                                                                 /*!< TRIPINPUT11 Postion   10         */ 
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT11_Msk    (0x1U << EPWM_REGS_DCAHTRIPSEL_TRIPINPUT11_Pos)                                       /*!< TRIPINPUT11 Mask      0x00000400 */
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT11_Set(x) (((uint16_t) (x) << EPWM_REGS_DCAHTRIPSEL_TRIPINPUT11_Pos) & EPWM_REGS_DCAHTRIPSEL_TRIPINPUT11_Msk) /*!< TRIPINPUT11 Set Value            */
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT11_Get(x) (((uint16_t) (x) & EPWM_REGS_DCAHTRIPSEL_TRIPINPUT11_Msk) >> EPWM_REGS_DCAHTRIPSEL_TRIPINPUT11_Pos) /*!< TRIPINPUT11 Get Value            */


#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT10_Pos    (9U)                                                                                  /*!< TRIPINPUT10 Postion   9          */ 
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT10_Msk    (0x1U << EPWM_REGS_DCAHTRIPSEL_TRIPINPUT10_Pos)                                       /*!< TRIPINPUT10 Mask      0x00000200 */
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT10_Set(x) (((uint16_t) (x) << EPWM_REGS_DCAHTRIPSEL_TRIPINPUT10_Pos) & EPWM_REGS_DCAHTRIPSEL_TRIPINPUT10_Msk) /*!< TRIPINPUT10 Set Value            */
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT10_Get(x) (((uint16_t) (x) & EPWM_REGS_DCAHTRIPSEL_TRIPINPUT10_Msk) >> EPWM_REGS_DCAHTRIPSEL_TRIPINPUT10_Pos) /*!< TRIPINPUT10 Get Value            */


#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT9_Pos    (8U)                                                                                  /*!< TRIPINPUT9 Postion   8          */ 
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT9_Msk    (0x1U << EPWM_REGS_DCAHTRIPSEL_TRIPINPUT9_Pos)                                        /*!< TRIPINPUT9 Mask      0x00000100 */
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT9_Set(x) (((uint16_t) (x) << EPWM_REGS_DCAHTRIPSEL_TRIPINPUT9_Pos) & EPWM_REGS_DCAHTRIPSEL_TRIPINPUT9_Msk) /*!< TRIPINPUT9 Set Value            */
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT9_Get(x) (((uint16_t) (x) & EPWM_REGS_DCAHTRIPSEL_TRIPINPUT9_Msk) >> EPWM_REGS_DCAHTRIPSEL_TRIPINPUT9_Pos) /*!< TRIPINPUT9 Get Value            */


#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT8_Pos    (7U)                                                                                  /*!< TRIPINPUT8 Postion   7          */ 
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT8_Msk    (0x1U << EPWM_REGS_DCAHTRIPSEL_TRIPINPUT8_Pos)                                        /*!< TRIPINPUT8 Mask      0x00000080 */
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT8_Set(x) (((uint16_t) (x) << EPWM_REGS_DCAHTRIPSEL_TRIPINPUT8_Pos) & EPWM_REGS_DCAHTRIPSEL_TRIPINPUT8_Msk) /*!< TRIPINPUT8 Set Value            */
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT8_Get(x) (((uint16_t) (x) & EPWM_REGS_DCAHTRIPSEL_TRIPINPUT8_Msk) >> EPWM_REGS_DCAHTRIPSEL_TRIPINPUT8_Pos) /*!< TRIPINPUT8 Get Value            */


#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT7_Pos    (6U)                                                                                  /*!< TRIPINPUT7 Postion   6          */ 
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT7_Msk    (0x1U << EPWM_REGS_DCAHTRIPSEL_TRIPINPUT7_Pos)                                        /*!< TRIPINPUT7 Mask      0x00000040 */
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT7_Set(x) (((uint16_t) (x) << EPWM_REGS_DCAHTRIPSEL_TRIPINPUT7_Pos) & EPWM_REGS_DCAHTRIPSEL_TRIPINPUT7_Msk) /*!< TRIPINPUT7 Set Value            */
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT7_Get(x) (((uint16_t) (x) & EPWM_REGS_DCAHTRIPSEL_TRIPINPUT7_Msk) >> EPWM_REGS_DCAHTRIPSEL_TRIPINPUT7_Pos) /*!< TRIPINPUT7 Get Value            */


#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT6_Pos    (5U)                                                                                  /*!< TRIPINPUT6 Postion   5          */ 
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT6_Msk    (0x1U << EPWM_REGS_DCAHTRIPSEL_TRIPINPUT6_Pos)                                        /*!< TRIPINPUT6 Mask      0x00000020 */
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT6_Set(x) (((uint16_t) (x) << EPWM_REGS_DCAHTRIPSEL_TRIPINPUT6_Pos) & EPWM_REGS_DCAHTRIPSEL_TRIPINPUT6_Msk) /*!< TRIPINPUT6 Set Value            */
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT6_Get(x) (((uint16_t) (x) & EPWM_REGS_DCAHTRIPSEL_TRIPINPUT6_Msk) >> EPWM_REGS_DCAHTRIPSEL_TRIPINPUT6_Pos) /*!< TRIPINPUT6 Get Value            */


#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT5_Pos    (4U)                                                                                  /*!< TRIPINPUT5 Postion   4          */ 
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT5_Msk    (0x1U << EPWM_REGS_DCAHTRIPSEL_TRIPINPUT5_Pos)                                        /*!< TRIPINPUT5 Mask      0x00000010 */
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT5_Set(x) (((uint16_t) (x) << EPWM_REGS_DCAHTRIPSEL_TRIPINPUT5_Pos) & EPWM_REGS_DCAHTRIPSEL_TRIPINPUT5_Msk) /*!< TRIPINPUT5 Set Value            */
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT5_Get(x) (((uint16_t) (x) & EPWM_REGS_DCAHTRIPSEL_TRIPINPUT5_Msk) >> EPWM_REGS_DCAHTRIPSEL_TRIPINPUT5_Pos) /*!< TRIPINPUT5 Get Value            */


#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT4_Pos    (3U)                                                                                  /*!< TRIPINPUT4 Postion   3          */ 
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT4_Msk    (0x1U << EPWM_REGS_DCAHTRIPSEL_TRIPINPUT4_Pos)                                        /*!< TRIPINPUT4 Mask      0x00000008 */
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT4_Set(x) (((uint16_t) (x) << EPWM_REGS_DCAHTRIPSEL_TRIPINPUT4_Pos) & EPWM_REGS_DCAHTRIPSEL_TRIPINPUT4_Msk) /*!< TRIPINPUT4 Set Value            */
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT4_Get(x) (((uint16_t) (x) & EPWM_REGS_DCAHTRIPSEL_TRIPINPUT4_Msk) >> EPWM_REGS_DCAHTRIPSEL_TRIPINPUT4_Pos) /*!< TRIPINPUT4 Get Value            */


#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT3_Pos    (2U)                                                                                  /*!< TRIPINPUT3 Postion   2          */ 
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT3_Msk    (0x1U << EPWM_REGS_DCAHTRIPSEL_TRIPINPUT3_Pos)                                        /*!< TRIPINPUT3 Mask      0x00000004 */
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT3_Set(x) (((uint16_t) (x) << EPWM_REGS_DCAHTRIPSEL_TRIPINPUT3_Pos) & EPWM_REGS_DCAHTRIPSEL_TRIPINPUT3_Msk) /*!< TRIPINPUT3 Set Value            */
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT3_Get(x) (((uint16_t) (x) & EPWM_REGS_DCAHTRIPSEL_TRIPINPUT3_Msk) >> EPWM_REGS_DCAHTRIPSEL_TRIPINPUT3_Pos) /*!< TRIPINPUT3 Get Value            */


#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT2_Pos    (1U)                                                                                  /*!< TRIPINPUT2 Postion   1          */ 
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT2_Msk    (0x1U << EPWM_REGS_DCAHTRIPSEL_TRIPINPUT2_Pos)                                        /*!< TRIPINPUT2 Mask      0x00000002 */
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT2_Set(x) (((uint16_t) (x) << EPWM_REGS_DCAHTRIPSEL_TRIPINPUT2_Pos) & EPWM_REGS_DCAHTRIPSEL_TRIPINPUT2_Msk) /*!< TRIPINPUT2 Set Value            */
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT2_Get(x) (((uint16_t) (x) & EPWM_REGS_DCAHTRIPSEL_TRIPINPUT2_Msk) >> EPWM_REGS_DCAHTRIPSEL_TRIPINPUT2_Pos) /*!< TRIPINPUT2 Get Value            */


#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT1_Pos    (0U)                                                                                  /*!< TRIPINPUT1 Postion   0          */ 
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT1_Msk    (0x1U << EPWM_REGS_DCAHTRIPSEL_TRIPINPUT1_Pos)                                        /*!< TRIPINPUT1 Mask      0x00000001 */
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT1_Set(x) (((uint16_t) (x) << EPWM_REGS_DCAHTRIPSEL_TRIPINPUT1_Pos) & EPWM_REGS_DCAHTRIPSEL_TRIPINPUT1_Msk) /*!< TRIPINPUT1 Set Value            */
#define EPWM_REGS_DCAHTRIPSEL_TRIPINPUT1_Get(x) (((uint16_t) (x) & EPWM_REGS_DCAHTRIPSEL_TRIPINPUT1_Msk) >> EPWM_REGS_DCAHTRIPSEL_TRIPINPUT1_Pos) /*!< TRIPINPUT1 Get Value            */


/* DCALTRIPSEL bitfield */
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT15_Pos    (14U)                                                                                 /*!< TRIPINPUT15 Postion   14         */ 
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT15_Msk    (0x1U << EPWM_REGS_DCALTRIPSEL_TRIPINPUT15_Pos)                                       /*!< TRIPINPUT15 Mask      0x00004000 */
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT15_Set(x) (((uint16_t) (x) << EPWM_REGS_DCALTRIPSEL_TRIPINPUT15_Pos) & EPWM_REGS_DCALTRIPSEL_TRIPINPUT15_Msk) /*!< TRIPINPUT15 Set Value            */
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT15_Get(x) (((uint16_t) (x) & EPWM_REGS_DCALTRIPSEL_TRIPINPUT15_Msk) >> EPWM_REGS_DCALTRIPSEL_TRIPINPUT15_Pos) /*!< TRIPINPUT15 Get Value            */


#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT14_Pos    (13U)                                                                                 /*!< TRIPINPUT14 Postion   13         */ 
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT14_Msk    (0x1U << EPWM_REGS_DCALTRIPSEL_TRIPINPUT14_Pos)                                       /*!< TRIPINPUT14 Mask      0x00002000 */
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT14_Set(x) (((uint16_t) (x) << EPWM_REGS_DCALTRIPSEL_TRIPINPUT14_Pos) & EPWM_REGS_DCALTRIPSEL_TRIPINPUT14_Msk) /*!< TRIPINPUT14 Set Value            */
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT14_Get(x) (((uint16_t) (x) & EPWM_REGS_DCALTRIPSEL_TRIPINPUT14_Msk) >> EPWM_REGS_DCALTRIPSEL_TRIPINPUT14_Pos) /*!< TRIPINPUT14 Get Value            */


#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT12_Pos    (11U)                                                                                 /*!< TRIPINPUT12 Postion   11         */ 
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT12_Msk    (0x1U << EPWM_REGS_DCALTRIPSEL_TRIPINPUT12_Pos)                                       /*!< TRIPINPUT12 Mask      0x00000800 */
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT12_Set(x) (((uint16_t) (x) << EPWM_REGS_DCALTRIPSEL_TRIPINPUT12_Pos) & EPWM_REGS_DCALTRIPSEL_TRIPINPUT12_Msk) /*!< TRIPINPUT12 Set Value            */
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT12_Get(x) (((uint16_t) (x) & EPWM_REGS_DCALTRIPSEL_TRIPINPUT12_Msk) >> EPWM_REGS_DCALTRIPSEL_TRIPINPUT12_Pos) /*!< TRIPINPUT12 Get Value            */


#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT11_Pos    (10U)                                                                                 /*!< TRIPINPUT11 Postion   10         */ 
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT11_Msk    (0x1U << EPWM_REGS_DCALTRIPSEL_TRIPINPUT11_Pos)                                       /*!< TRIPINPUT11 Mask      0x00000400 */
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT11_Set(x) (((uint16_t) (x) << EPWM_REGS_DCALTRIPSEL_TRIPINPUT11_Pos) & EPWM_REGS_DCALTRIPSEL_TRIPINPUT11_Msk) /*!< TRIPINPUT11 Set Value            */
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT11_Get(x) (((uint16_t) (x) & EPWM_REGS_DCALTRIPSEL_TRIPINPUT11_Msk) >> EPWM_REGS_DCALTRIPSEL_TRIPINPUT11_Pos) /*!< TRIPINPUT11 Get Value            */


#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT10_Pos    (9U)                                                                                  /*!< TRIPINPUT10 Postion   9          */ 
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT10_Msk    (0x1U << EPWM_REGS_DCALTRIPSEL_TRIPINPUT10_Pos)                                       /*!< TRIPINPUT10 Mask      0x00000200 */
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT10_Set(x) (((uint16_t) (x) << EPWM_REGS_DCALTRIPSEL_TRIPINPUT10_Pos) & EPWM_REGS_DCALTRIPSEL_TRIPINPUT10_Msk) /*!< TRIPINPUT10 Set Value            */
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT10_Get(x) (((uint16_t) (x) & EPWM_REGS_DCALTRIPSEL_TRIPINPUT10_Msk) >> EPWM_REGS_DCALTRIPSEL_TRIPINPUT10_Pos) /*!< TRIPINPUT10 Get Value            */


#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT9_Pos    (8U)                                                                                  /*!< TRIPINPUT9 Postion   8          */ 
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT9_Msk    (0x1U << EPWM_REGS_DCALTRIPSEL_TRIPINPUT9_Pos)                                        /*!< TRIPINPUT9 Mask      0x00000100 */
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT9_Set(x) (((uint16_t) (x) << EPWM_REGS_DCALTRIPSEL_TRIPINPUT9_Pos) & EPWM_REGS_DCALTRIPSEL_TRIPINPUT9_Msk) /*!< TRIPINPUT9 Set Value            */
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT9_Get(x) (((uint16_t) (x) & EPWM_REGS_DCALTRIPSEL_TRIPINPUT9_Msk) >> EPWM_REGS_DCALTRIPSEL_TRIPINPUT9_Pos) /*!< TRIPINPUT9 Get Value            */


#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT8_Pos    (7U)                                                                                  /*!< TRIPINPUT8 Postion   7          */ 
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT8_Msk    (0x1U << EPWM_REGS_DCALTRIPSEL_TRIPINPUT8_Pos)                                        /*!< TRIPINPUT8 Mask      0x00000080 */
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT8_Set(x) (((uint16_t) (x) << EPWM_REGS_DCALTRIPSEL_TRIPINPUT8_Pos) & EPWM_REGS_DCALTRIPSEL_TRIPINPUT8_Msk) /*!< TRIPINPUT8 Set Value            */
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT8_Get(x) (((uint16_t) (x) & EPWM_REGS_DCALTRIPSEL_TRIPINPUT8_Msk) >> EPWM_REGS_DCALTRIPSEL_TRIPINPUT8_Pos) /*!< TRIPINPUT8 Get Value            */


#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT7_Pos    (6U)                                                                                  /*!< TRIPINPUT7 Postion   6          */ 
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT7_Msk    (0x1U << EPWM_REGS_DCALTRIPSEL_TRIPINPUT7_Pos)                                        /*!< TRIPINPUT7 Mask      0x00000040 */
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT7_Set(x) (((uint16_t) (x) << EPWM_REGS_DCALTRIPSEL_TRIPINPUT7_Pos) & EPWM_REGS_DCALTRIPSEL_TRIPINPUT7_Msk) /*!< TRIPINPUT7 Set Value            */
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT7_Get(x) (((uint16_t) (x) & EPWM_REGS_DCALTRIPSEL_TRIPINPUT7_Msk) >> EPWM_REGS_DCALTRIPSEL_TRIPINPUT7_Pos) /*!< TRIPINPUT7 Get Value            */


#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT6_Pos    (5U)                                                                                  /*!< TRIPINPUT6 Postion   5          */ 
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT6_Msk    (0x1U << EPWM_REGS_DCALTRIPSEL_TRIPINPUT6_Pos)                                        /*!< TRIPINPUT6 Mask      0x00000020 */
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT6_Set(x) (((uint16_t) (x) << EPWM_REGS_DCALTRIPSEL_TRIPINPUT6_Pos) & EPWM_REGS_DCALTRIPSEL_TRIPINPUT6_Msk) /*!< TRIPINPUT6 Set Value            */
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT6_Get(x) (((uint16_t) (x) & EPWM_REGS_DCALTRIPSEL_TRIPINPUT6_Msk) >> EPWM_REGS_DCALTRIPSEL_TRIPINPUT6_Pos) /*!< TRIPINPUT6 Get Value            */


#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT5_Pos    (4U)                                                                                  /*!< TRIPINPUT5 Postion   4          */ 
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT5_Msk    (0x1U << EPWM_REGS_DCALTRIPSEL_TRIPINPUT5_Pos)                                        /*!< TRIPINPUT5 Mask      0x00000010 */
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT5_Set(x) (((uint16_t) (x) << EPWM_REGS_DCALTRIPSEL_TRIPINPUT5_Pos) & EPWM_REGS_DCALTRIPSEL_TRIPINPUT5_Msk) /*!< TRIPINPUT5 Set Value            */
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT5_Get(x) (((uint16_t) (x) & EPWM_REGS_DCALTRIPSEL_TRIPINPUT5_Msk) >> EPWM_REGS_DCALTRIPSEL_TRIPINPUT5_Pos) /*!< TRIPINPUT5 Get Value            */


#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT4_Pos    (3U)                                                                                  /*!< TRIPINPUT4 Postion   3          */ 
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT4_Msk    (0x1U << EPWM_REGS_DCALTRIPSEL_TRIPINPUT4_Pos)                                        /*!< TRIPINPUT4 Mask      0x00000008 */
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT4_Set(x) (((uint16_t) (x) << EPWM_REGS_DCALTRIPSEL_TRIPINPUT4_Pos) & EPWM_REGS_DCALTRIPSEL_TRIPINPUT4_Msk) /*!< TRIPINPUT4 Set Value            */
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT4_Get(x) (((uint16_t) (x) & EPWM_REGS_DCALTRIPSEL_TRIPINPUT4_Msk) >> EPWM_REGS_DCALTRIPSEL_TRIPINPUT4_Pos) /*!< TRIPINPUT4 Get Value            */


#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT3_Pos    (2U)                                                                                  /*!< TRIPINPUT3 Postion   2          */ 
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT3_Msk    (0x1U << EPWM_REGS_DCALTRIPSEL_TRIPINPUT3_Pos)                                        /*!< TRIPINPUT3 Mask      0x00000004 */
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT3_Set(x) (((uint16_t) (x) << EPWM_REGS_DCALTRIPSEL_TRIPINPUT3_Pos) & EPWM_REGS_DCALTRIPSEL_TRIPINPUT3_Msk) /*!< TRIPINPUT3 Set Value            */
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT3_Get(x) (((uint16_t) (x) & EPWM_REGS_DCALTRIPSEL_TRIPINPUT3_Msk) >> EPWM_REGS_DCALTRIPSEL_TRIPINPUT3_Pos) /*!< TRIPINPUT3 Get Value            */


#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT2_Pos    (1U)                                                                                  /*!< TRIPINPUT2 Postion   1          */ 
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT2_Msk    (0x1U << EPWM_REGS_DCALTRIPSEL_TRIPINPUT2_Pos)                                        /*!< TRIPINPUT2 Mask      0x00000002 */
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT2_Set(x) (((uint16_t) (x) << EPWM_REGS_DCALTRIPSEL_TRIPINPUT2_Pos) & EPWM_REGS_DCALTRIPSEL_TRIPINPUT2_Msk) /*!< TRIPINPUT2 Set Value            */
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT2_Get(x) (((uint16_t) (x) & EPWM_REGS_DCALTRIPSEL_TRIPINPUT2_Msk) >> EPWM_REGS_DCALTRIPSEL_TRIPINPUT2_Pos) /*!< TRIPINPUT2 Get Value            */


#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT1_Pos    (0U)                                                                                  /*!< TRIPINPUT1 Postion   0          */ 
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT1_Msk    (0x1U << EPWM_REGS_DCALTRIPSEL_TRIPINPUT1_Pos)                                        /*!< TRIPINPUT1 Mask      0x00000001 */
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT1_Set(x) (((uint16_t) (x) << EPWM_REGS_DCALTRIPSEL_TRIPINPUT1_Pos) & EPWM_REGS_DCALTRIPSEL_TRIPINPUT1_Msk) /*!< TRIPINPUT1 Set Value            */
#define EPWM_REGS_DCALTRIPSEL_TRIPINPUT1_Get(x) (((uint16_t) (x) & EPWM_REGS_DCALTRIPSEL_TRIPINPUT1_Msk) >> EPWM_REGS_DCALTRIPSEL_TRIPINPUT1_Pos) /*!< TRIPINPUT1 Get Value            */


/* DCBHTRIPSEL bitfield */
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT15_Pos    (14U)                                                                                 /*!< TRIPINPUT15 Postion   14         */ 
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT15_Msk    (0x1U << EPWM_REGS_DCBHTRIPSEL_TRIPINPUT15_Pos)                                       /*!< TRIPINPUT15 Mask      0x00004000 */
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT15_Set(x) (((uint16_t) (x) << EPWM_REGS_DCBHTRIPSEL_TRIPINPUT15_Pos) & EPWM_REGS_DCBHTRIPSEL_TRIPINPUT15_Msk) /*!< TRIPINPUT15 Set Value            */
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT15_Get(x) (((uint16_t) (x) & EPWM_REGS_DCBHTRIPSEL_TRIPINPUT15_Msk) >> EPWM_REGS_DCBHTRIPSEL_TRIPINPUT15_Pos) /*!< TRIPINPUT15 Get Value            */


#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT14_Pos    (13U)                                                                                 /*!< TRIPINPUT14 Postion   13         */ 
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT14_Msk    (0x1U << EPWM_REGS_DCBHTRIPSEL_TRIPINPUT14_Pos)                                       /*!< TRIPINPUT14 Mask      0x00002000 */
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT14_Set(x) (((uint16_t) (x) << EPWM_REGS_DCBHTRIPSEL_TRIPINPUT14_Pos) & EPWM_REGS_DCBHTRIPSEL_TRIPINPUT14_Msk) /*!< TRIPINPUT14 Set Value            */
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT14_Get(x) (((uint16_t) (x) & EPWM_REGS_DCBHTRIPSEL_TRIPINPUT14_Msk) >> EPWM_REGS_DCBHTRIPSEL_TRIPINPUT14_Pos) /*!< TRIPINPUT14 Get Value            */


#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT12_Pos    (11U)                                                                                 /*!< TRIPINPUT12 Postion   11         */ 
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT12_Msk    (0x1U << EPWM_REGS_DCBHTRIPSEL_TRIPINPUT12_Pos)                                       /*!< TRIPINPUT12 Mask      0x00000800 */
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT12_Set(x) (((uint16_t) (x) << EPWM_REGS_DCBHTRIPSEL_TRIPINPUT12_Pos) & EPWM_REGS_DCBHTRIPSEL_TRIPINPUT12_Msk) /*!< TRIPINPUT12 Set Value            */
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT12_Get(x) (((uint16_t) (x) & EPWM_REGS_DCBHTRIPSEL_TRIPINPUT12_Msk) >> EPWM_REGS_DCBHTRIPSEL_TRIPINPUT12_Pos) /*!< TRIPINPUT12 Get Value            */


#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT11_Pos    (10U)                                                                                 /*!< TRIPINPUT11 Postion   10         */ 
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT11_Msk    (0x1U << EPWM_REGS_DCBHTRIPSEL_TRIPINPUT11_Pos)                                       /*!< TRIPINPUT11 Mask      0x00000400 */
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT11_Set(x) (((uint16_t) (x) << EPWM_REGS_DCBHTRIPSEL_TRIPINPUT11_Pos) & EPWM_REGS_DCBHTRIPSEL_TRIPINPUT11_Msk) /*!< TRIPINPUT11 Set Value            */
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT11_Get(x) (((uint16_t) (x) & EPWM_REGS_DCBHTRIPSEL_TRIPINPUT11_Msk) >> EPWM_REGS_DCBHTRIPSEL_TRIPINPUT11_Pos) /*!< TRIPINPUT11 Get Value            */


#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT10_Pos    (9U)                                                                                  /*!< TRIPINPUT10 Postion   9          */ 
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT10_Msk    (0x1U << EPWM_REGS_DCBHTRIPSEL_TRIPINPUT10_Pos)                                       /*!< TRIPINPUT10 Mask      0x00000200 */
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT10_Set(x) (((uint16_t) (x) << EPWM_REGS_DCBHTRIPSEL_TRIPINPUT10_Pos) & EPWM_REGS_DCBHTRIPSEL_TRIPINPUT10_Msk) /*!< TRIPINPUT10 Set Value            */
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT10_Get(x) (((uint16_t) (x) & EPWM_REGS_DCBHTRIPSEL_TRIPINPUT10_Msk) >> EPWM_REGS_DCBHTRIPSEL_TRIPINPUT10_Pos) /*!< TRIPINPUT10 Get Value            */


#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT9_Pos    (8U)                                                                                  /*!< TRIPINPUT9 Postion   8          */ 
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT9_Msk    (0x1U << EPWM_REGS_DCBHTRIPSEL_TRIPINPUT9_Pos)                                        /*!< TRIPINPUT9 Mask      0x00000100 */
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT9_Set(x) (((uint16_t) (x) << EPWM_REGS_DCBHTRIPSEL_TRIPINPUT9_Pos) & EPWM_REGS_DCBHTRIPSEL_TRIPINPUT9_Msk) /*!< TRIPINPUT9 Set Value            */
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT9_Get(x) (((uint16_t) (x) & EPWM_REGS_DCBHTRIPSEL_TRIPINPUT9_Msk) >> EPWM_REGS_DCBHTRIPSEL_TRIPINPUT9_Pos) /*!< TRIPINPUT9 Get Value            */


#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT8_Pos    (7U)                                                                                  /*!< TRIPINPUT8 Postion   7          */ 
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT8_Msk    (0x1U << EPWM_REGS_DCBHTRIPSEL_TRIPINPUT8_Pos)                                        /*!< TRIPINPUT8 Mask      0x00000080 */
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT8_Set(x) (((uint16_t) (x) << EPWM_REGS_DCBHTRIPSEL_TRIPINPUT8_Pos) & EPWM_REGS_DCBHTRIPSEL_TRIPINPUT8_Msk) /*!< TRIPINPUT8 Set Value            */
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT8_Get(x) (((uint16_t) (x) & EPWM_REGS_DCBHTRIPSEL_TRIPINPUT8_Msk) >> EPWM_REGS_DCBHTRIPSEL_TRIPINPUT8_Pos) /*!< TRIPINPUT8 Get Value            */


#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT7_Pos    (6U)                                                                                  /*!< TRIPINPUT7 Postion   6          */ 
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT7_Msk    (0x1U << EPWM_REGS_DCBHTRIPSEL_TRIPINPUT7_Pos)                                        /*!< TRIPINPUT7 Mask      0x00000040 */
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT7_Set(x) (((uint16_t) (x) << EPWM_REGS_DCBHTRIPSEL_TRIPINPUT7_Pos) & EPWM_REGS_DCBHTRIPSEL_TRIPINPUT7_Msk) /*!< TRIPINPUT7 Set Value            */
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT7_Get(x) (((uint16_t) (x) & EPWM_REGS_DCBHTRIPSEL_TRIPINPUT7_Msk) >> EPWM_REGS_DCBHTRIPSEL_TRIPINPUT7_Pos) /*!< TRIPINPUT7 Get Value            */


#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT6_Pos    (5U)                                                                                  /*!< TRIPINPUT6 Postion   5          */ 
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT6_Msk    (0x1U << EPWM_REGS_DCBHTRIPSEL_TRIPINPUT6_Pos)                                        /*!< TRIPINPUT6 Mask      0x00000020 */
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT6_Set(x) (((uint16_t) (x) << EPWM_REGS_DCBHTRIPSEL_TRIPINPUT6_Pos) & EPWM_REGS_DCBHTRIPSEL_TRIPINPUT6_Msk) /*!< TRIPINPUT6 Set Value            */
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT6_Get(x) (((uint16_t) (x) & EPWM_REGS_DCBHTRIPSEL_TRIPINPUT6_Msk) >> EPWM_REGS_DCBHTRIPSEL_TRIPINPUT6_Pos) /*!< TRIPINPUT6 Get Value            */


#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT5_Pos    (4U)                                                                                  /*!< TRIPINPUT5 Postion   4          */ 
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT5_Msk    (0x1U << EPWM_REGS_DCBHTRIPSEL_TRIPINPUT5_Pos)                                        /*!< TRIPINPUT5 Mask      0x00000010 */
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT5_Set(x) (((uint16_t) (x) << EPWM_REGS_DCBHTRIPSEL_TRIPINPUT5_Pos) & EPWM_REGS_DCBHTRIPSEL_TRIPINPUT5_Msk) /*!< TRIPINPUT5 Set Value            */
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT5_Get(x) (((uint16_t) (x) & EPWM_REGS_DCBHTRIPSEL_TRIPINPUT5_Msk) >> EPWM_REGS_DCBHTRIPSEL_TRIPINPUT5_Pos) /*!< TRIPINPUT5 Get Value            */


#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT4_Pos    (3U)                                                                                  /*!< TRIPINPUT4 Postion   3          */ 
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT4_Msk    (0x1U << EPWM_REGS_DCBHTRIPSEL_TRIPINPUT4_Pos)                                        /*!< TRIPINPUT4 Mask      0x00000008 */
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT4_Set(x) (((uint16_t) (x) << EPWM_REGS_DCBHTRIPSEL_TRIPINPUT4_Pos) & EPWM_REGS_DCBHTRIPSEL_TRIPINPUT4_Msk) /*!< TRIPINPUT4 Set Value            */
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT4_Get(x) (((uint16_t) (x) & EPWM_REGS_DCBHTRIPSEL_TRIPINPUT4_Msk) >> EPWM_REGS_DCBHTRIPSEL_TRIPINPUT4_Pos) /*!< TRIPINPUT4 Get Value            */


#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT3_Pos    (2U)                                                                                  /*!< TRIPINPUT3 Postion   2          */ 
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT3_Msk    (0x1U << EPWM_REGS_DCBHTRIPSEL_TRIPINPUT3_Pos)                                        /*!< TRIPINPUT3 Mask      0x00000004 */
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT3_Set(x) (((uint16_t) (x) << EPWM_REGS_DCBHTRIPSEL_TRIPINPUT3_Pos) & EPWM_REGS_DCBHTRIPSEL_TRIPINPUT3_Msk) /*!< TRIPINPUT3 Set Value            */
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT3_Get(x) (((uint16_t) (x) & EPWM_REGS_DCBHTRIPSEL_TRIPINPUT3_Msk) >> EPWM_REGS_DCBHTRIPSEL_TRIPINPUT3_Pos) /*!< TRIPINPUT3 Get Value            */


#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT2_Pos    (1U)                                                                                  /*!< TRIPINPUT2 Postion   1          */ 
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT2_Msk    (0x1U << EPWM_REGS_DCBHTRIPSEL_TRIPINPUT2_Pos)                                        /*!< TRIPINPUT2 Mask      0x00000002 */
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT2_Set(x) (((uint16_t) (x) << EPWM_REGS_DCBHTRIPSEL_TRIPINPUT2_Pos) & EPWM_REGS_DCBHTRIPSEL_TRIPINPUT2_Msk) /*!< TRIPINPUT2 Set Value            */
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT2_Get(x) (((uint16_t) (x) & EPWM_REGS_DCBHTRIPSEL_TRIPINPUT2_Msk) >> EPWM_REGS_DCBHTRIPSEL_TRIPINPUT2_Pos) /*!< TRIPINPUT2 Get Value            */


#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT1_Pos    (0U)                                                                                  /*!< TRIPINPUT1 Postion   0          */ 
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT1_Msk    (0x1U << EPWM_REGS_DCBHTRIPSEL_TRIPINPUT1_Pos)                                        /*!< TRIPINPUT1 Mask      0x00000001 */
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT1_Set(x) (((uint16_t) (x) << EPWM_REGS_DCBHTRIPSEL_TRIPINPUT1_Pos) & EPWM_REGS_DCBHTRIPSEL_TRIPINPUT1_Msk) /*!< TRIPINPUT1 Set Value            */
#define EPWM_REGS_DCBHTRIPSEL_TRIPINPUT1_Get(x) (((uint16_t) (x) & EPWM_REGS_DCBHTRIPSEL_TRIPINPUT1_Msk) >> EPWM_REGS_DCBHTRIPSEL_TRIPINPUT1_Pos) /*!< TRIPINPUT1 Get Value            */


/* DCBLTRIPSEL bitfield */
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT15_Pos    (14U)                                                                                 /*!< TRIPINPUT15 Postion   14         */ 
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT15_Msk    (0x1U << EPWM_REGS_DCBLTRIPSEL_TRIPINPUT15_Pos)                                       /*!< TRIPINPUT15 Mask      0x00004000 */
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT15_Set(x) (((uint16_t) (x) << EPWM_REGS_DCBLTRIPSEL_TRIPINPUT15_Pos) & EPWM_REGS_DCBLTRIPSEL_TRIPINPUT15_Msk) /*!< TRIPINPUT15 Set Value            */
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT15_Get(x) (((uint16_t) (x) & EPWM_REGS_DCBLTRIPSEL_TRIPINPUT15_Msk) >> EPWM_REGS_DCBLTRIPSEL_TRIPINPUT15_Pos) /*!< TRIPINPUT15 Get Value            */


#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT14_Pos    (13U)                                                                                 /*!< TRIPINPUT14 Postion   13         */ 
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT14_Msk    (0x1U << EPWM_REGS_DCBLTRIPSEL_TRIPINPUT14_Pos)                                       /*!< TRIPINPUT14 Mask      0x00002000 */
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT14_Set(x) (((uint16_t) (x) << EPWM_REGS_DCBLTRIPSEL_TRIPINPUT14_Pos) & EPWM_REGS_DCBLTRIPSEL_TRIPINPUT14_Msk) /*!< TRIPINPUT14 Set Value            */
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT14_Get(x) (((uint16_t) (x) & EPWM_REGS_DCBLTRIPSEL_TRIPINPUT14_Msk) >> EPWM_REGS_DCBLTRIPSEL_TRIPINPUT14_Pos) /*!< TRIPINPUT14 Get Value            */


#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT12_Pos    (11U)                                                                                 /*!< TRIPINPUT12 Postion   11         */ 
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT12_Msk    (0x1U << EPWM_REGS_DCBLTRIPSEL_TRIPINPUT12_Pos)                                       /*!< TRIPINPUT12 Mask      0x00000800 */
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT12_Set(x) (((uint16_t) (x) << EPWM_REGS_DCBLTRIPSEL_TRIPINPUT12_Pos) & EPWM_REGS_DCBLTRIPSEL_TRIPINPUT12_Msk) /*!< TRIPINPUT12 Set Value            */
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT12_Get(x) (((uint16_t) (x) & EPWM_REGS_DCBLTRIPSEL_TRIPINPUT12_Msk) >> EPWM_REGS_DCBLTRIPSEL_TRIPINPUT12_Pos) /*!< TRIPINPUT12 Get Value            */


#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT11_Pos    (10U)                                                                                 /*!< TRIPINPUT11 Postion   10         */ 
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT11_Msk    (0x1U << EPWM_REGS_DCBLTRIPSEL_TRIPINPUT11_Pos)                                       /*!< TRIPINPUT11 Mask      0x00000400 */
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT11_Set(x) (((uint16_t) (x) << EPWM_REGS_DCBLTRIPSEL_TRIPINPUT11_Pos) & EPWM_REGS_DCBLTRIPSEL_TRIPINPUT11_Msk) /*!< TRIPINPUT11 Set Value            */
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT11_Get(x) (((uint16_t) (x) & EPWM_REGS_DCBLTRIPSEL_TRIPINPUT11_Msk) >> EPWM_REGS_DCBLTRIPSEL_TRIPINPUT11_Pos) /*!< TRIPINPUT11 Get Value            */


#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT10_Pos    (9U)                                                                                  /*!< TRIPINPUT10 Postion   9          */ 
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT10_Msk    (0x1U << EPWM_REGS_DCBLTRIPSEL_TRIPINPUT10_Pos)                                       /*!< TRIPINPUT10 Mask      0x00000200 */
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT10_Set(x) (((uint16_t) (x) << EPWM_REGS_DCBLTRIPSEL_TRIPINPUT10_Pos) & EPWM_REGS_DCBLTRIPSEL_TRIPINPUT10_Msk) /*!< TRIPINPUT10 Set Value            */
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT10_Get(x) (((uint16_t) (x) & EPWM_REGS_DCBLTRIPSEL_TRIPINPUT10_Msk) >> EPWM_REGS_DCBLTRIPSEL_TRIPINPUT10_Pos) /*!< TRIPINPUT10 Get Value            */


#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT9_Pos    (8U)                                                                                  /*!< TRIPINPUT9 Postion   8          */ 
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT9_Msk    (0x1U << EPWM_REGS_DCBLTRIPSEL_TRIPINPUT9_Pos)                                        /*!< TRIPINPUT9 Mask      0x00000100 */
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT9_Set(x) (((uint16_t) (x) << EPWM_REGS_DCBLTRIPSEL_TRIPINPUT9_Pos) & EPWM_REGS_DCBLTRIPSEL_TRIPINPUT9_Msk) /*!< TRIPINPUT9 Set Value            */
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT9_Get(x) (((uint16_t) (x) & EPWM_REGS_DCBLTRIPSEL_TRIPINPUT9_Msk) >> EPWM_REGS_DCBLTRIPSEL_TRIPINPUT9_Pos) /*!< TRIPINPUT9 Get Value            */


#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT8_Pos    (7U)                                                                                  /*!< TRIPINPUT8 Postion   7          */ 
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT8_Msk    (0x1U << EPWM_REGS_DCBLTRIPSEL_TRIPINPUT8_Pos)                                        /*!< TRIPINPUT8 Mask      0x00000080 */
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT8_Set(x) (((uint16_t) (x) << EPWM_REGS_DCBLTRIPSEL_TRIPINPUT8_Pos) & EPWM_REGS_DCBLTRIPSEL_TRIPINPUT8_Msk) /*!< TRIPINPUT8 Set Value            */
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT8_Get(x) (((uint16_t) (x) & EPWM_REGS_DCBLTRIPSEL_TRIPINPUT8_Msk) >> EPWM_REGS_DCBLTRIPSEL_TRIPINPUT8_Pos) /*!< TRIPINPUT8 Get Value            */


#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT7_Pos    (6U)                                                                                  /*!< TRIPINPUT7 Postion   6          */ 
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT7_Msk    (0x1U << EPWM_REGS_DCBLTRIPSEL_TRIPINPUT7_Pos)                                        /*!< TRIPINPUT7 Mask      0x00000040 */
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT7_Set(x) (((uint16_t) (x) << EPWM_REGS_DCBLTRIPSEL_TRIPINPUT7_Pos) & EPWM_REGS_DCBLTRIPSEL_TRIPINPUT7_Msk) /*!< TRIPINPUT7 Set Value            */
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT7_Get(x) (((uint16_t) (x) & EPWM_REGS_DCBLTRIPSEL_TRIPINPUT7_Msk) >> EPWM_REGS_DCBLTRIPSEL_TRIPINPUT7_Pos) /*!< TRIPINPUT7 Get Value            */


#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT6_Pos    (5U)                                                                                  /*!< TRIPINPUT6 Postion   5          */ 
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT6_Msk    (0x1U << EPWM_REGS_DCBLTRIPSEL_TRIPINPUT6_Pos)                                        /*!< TRIPINPUT6 Mask      0x00000020 */
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT6_Set(x) (((uint16_t) (x) << EPWM_REGS_DCBLTRIPSEL_TRIPINPUT6_Pos) & EPWM_REGS_DCBLTRIPSEL_TRIPINPUT6_Msk) /*!< TRIPINPUT6 Set Value            */
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT6_Get(x) (((uint16_t) (x) & EPWM_REGS_DCBLTRIPSEL_TRIPINPUT6_Msk) >> EPWM_REGS_DCBLTRIPSEL_TRIPINPUT6_Pos) /*!< TRIPINPUT6 Get Value            */


#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT5_Pos    (4U)                                                                                  /*!< TRIPINPUT5 Postion   4          */ 
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT5_Msk    (0x1U << EPWM_REGS_DCBLTRIPSEL_TRIPINPUT5_Pos)                                        /*!< TRIPINPUT5 Mask      0x00000010 */
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT5_Set(x) (((uint16_t) (x) << EPWM_REGS_DCBLTRIPSEL_TRIPINPUT5_Pos) & EPWM_REGS_DCBLTRIPSEL_TRIPINPUT5_Msk) /*!< TRIPINPUT5 Set Value            */
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT5_Get(x) (((uint16_t) (x) & EPWM_REGS_DCBLTRIPSEL_TRIPINPUT5_Msk) >> EPWM_REGS_DCBLTRIPSEL_TRIPINPUT5_Pos) /*!< TRIPINPUT5 Get Value            */


#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT4_Pos    (3U)                                                                                  /*!< TRIPINPUT4 Postion   3          */ 
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT4_Msk    (0x1U << EPWM_REGS_DCBLTRIPSEL_TRIPINPUT4_Pos)                                        /*!< TRIPINPUT4 Mask      0x00000008 */
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT4_Set(x) (((uint16_t) (x) << EPWM_REGS_DCBLTRIPSEL_TRIPINPUT4_Pos) & EPWM_REGS_DCBLTRIPSEL_TRIPINPUT4_Msk) /*!< TRIPINPUT4 Set Value            */
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT4_Get(x) (((uint16_t) (x) & EPWM_REGS_DCBLTRIPSEL_TRIPINPUT4_Msk) >> EPWM_REGS_DCBLTRIPSEL_TRIPINPUT4_Pos) /*!< TRIPINPUT4 Get Value            */


#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT3_Pos    (2U)                                                                                  /*!< TRIPINPUT3 Postion   2          */ 
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT3_Msk    (0x1U << EPWM_REGS_DCBLTRIPSEL_TRIPINPUT3_Pos)                                        /*!< TRIPINPUT3 Mask      0x00000004 */
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT3_Set(x) (((uint16_t) (x) << EPWM_REGS_DCBLTRIPSEL_TRIPINPUT3_Pos) & EPWM_REGS_DCBLTRIPSEL_TRIPINPUT3_Msk) /*!< TRIPINPUT3 Set Value            */
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT3_Get(x) (((uint16_t) (x) & EPWM_REGS_DCBLTRIPSEL_TRIPINPUT3_Msk) >> EPWM_REGS_DCBLTRIPSEL_TRIPINPUT3_Pos) /*!< TRIPINPUT3 Get Value            */


#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT2_Pos    (1U)                                                                                  /*!< TRIPINPUT2 Postion   1          */ 
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT2_Msk    (0x1U << EPWM_REGS_DCBLTRIPSEL_TRIPINPUT2_Pos)                                        /*!< TRIPINPUT2 Mask      0x00000002 */
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT2_Set(x) (((uint16_t) (x) << EPWM_REGS_DCBLTRIPSEL_TRIPINPUT2_Pos) & EPWM_REGS_DCBLTRIPSEL_TRIPINPUT2_Msk) /*!< TRIPINPUT2 Set Value            */
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT2_Get(x) (((uint16_t) (x) & EPWM_REGS_DCBLTRIPSEL_TRIPINPUT2_Msk) >> EPWM_REGS_DCBLTRIPSEL_TRIPINPUT2_Pos) /*!< TRIPINPUT2 Get Value            */


#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT1_Pos    (0U)                                                                                  /*!< TRIPINPUT1 Postion   0          */ 
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT1_Msk    (0x1U << EPWM_REGS_DCBLTRIPSEL_TRIPINPUT1_Pos)                                        /*!< TRIPINPUT1 Mask      0x00000001 */
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT1_Set(x) (((uint16_t) (x) << EPWM_REGS_DCBLTRIPSEL_TRIPINPUT1_Pos) & EPWM_REGS_DCBLTRIPSEL_TRIPINPUT1_Msk) /*!< TRIPINPUT1 Set Value            */
#define EPWM_REGS_DCBLTRIPSEL_TRIPINPUT1_Get(x) (((uint16_t) (x) & EPWM_REGS_DCBLTRIPSEL_TRIPINPUT1_Msk) >> EPWM_REGS_DCBLTRIPSEL_TRIPINPUT1_Pos) /*!< TRIPINPUT1 Get Value            */


/* EPWMLOCK bitfield */
#define EPWM_REGS_EPWMLOCK_KEY_Pos    (16U)                                                                                 /*!< KEY Postion   16         */ 
#define EPWM_REGS_EPWMLOCK_KEY_Msk    (0xffffU << EPWM_REGS_EPWMLOCK_KEY_Pos)                                               /*!< KEY Mask      0xFFFF0000 */
#define EPWM_REGS_EPWMLOCK_KEY_Set(x) (((uint32_t) (x) << EPWM_REGS_EPWMLOCK_KEY_Pos) & EPWM_REGS_EPWMLOCK_KEY_Msk)         /*!< KEY Set Value            */
#define EPWM_REGS_EPWMLOCK_KEY_Get(x) (((uint32_t) (x) & EPWM_REGS_EPWMLOCK_KEY_Msk) >> EPWM_REGS_EPWMLOCK_KEY_Pos)         /*!< KEY Get Value            */


#define EPWM_REGS_EPWMLOCK_DCLOCK_Pos    (4U)                                                                                  /*!< DCLOCK Postion   4          */ 
#define EPWM_REGS_EPWMLOCK_DCLOCK_Msk    (0x1U << EPWM_REGS_EPWMLOCK_DCLOCK_Pos)                                               /*!< DCLOCK Mask      0x00000010 */
#define EPWM_REGS_EPWMLOCK_DCLOCK_Set(x) (((uint32_t) (x) << EPWM_REGS_EPWMLOCK_DCLOCK_Pos) & EPWM_REGS_EPWMLOCK_DCLOCK_Msk)   /*!< DCLOCK Set Value            */
#define EPWM_REGS_EPWMLOCK_DCLOCK_Get(x) (((uint32_t) (x) & EPWM_REGS_EPWMLOCK_DCLOCK_Msk) >> EPWM_REGS_EPWMLOCK_DCLOCK_Pos)   /*!< DCLOCK Get Value            */


#define EPWM_REGS_EPWMLOCK_TZCLRLOCK_Pos    (3U)                                                                                  /*!< TZCLRLOCK Postion   3          */ 
#define EPWM_REGS_EPWMLOCK_TZCLRLOCK_Msk    (0x1U << EPWM_REGS_EPWMLOCK_TZCLRLOCK_Pos)                                            /*!< TZCLRLOCK Mask      0x00000008 */
#define EPWM_REGS_EPWMLOCK_TZCLRLOCK_Set(x) (((uint32_t) (x) << EPWM_REGS_EPWMLOCK_TZCLRLOCK_Pos) & EPWM_REGS_EPWMLOCK_TZCLRLOCK_Msk) /*!< TZCLRLOCK Set Value            */
#define EPWM_REGS_EPWMLOCK_TZCLRLOCK_Get(x) (((uint32_t) (x) & EPWM_REGS_EPWMLOCK_TZCLRLOCK_Msk) >> EPWM_REGS_EPWMLOCK_TZCLRLOCK_Pos) /*!< TZCLRLOCK Get Value            */


#define EPWM_REGS_EPWMLOCK_TZCFGLOCK_Pos    (2U)                                                                                  /*!< TZCFGLOCK Postion   2          */ 
#define EPWM_REGS_EPWMLOCK_TZCFGLOCK_Msk    (0x1U << EPWM_REGS_EPWMLOCK_TZCFGLOCK_Pos)                                            /*!< TZCFGLOCK Mask      0x00000004 */
#define EPWM_REGS_EPWMLOCK_TZCFGLOCK_Set(x) (((uint32_t) (x) << EPWM_REGS_EPWMLOCK_TZCFGLOCK_Pos) & EPWM_REGS_EPWMLOCK_TZCFGLOCK_Msk) /*!< TZCFGLOCK Set Value            */
#define EPWM_REGS_EPWMLOCK_TZCFGLOCK_Get(x) (((uint32_t) (x) & EPWM_REGS_EPWMLOCK_TZCFGLOCK_Msk) >> EPWM_REGS_EPWMLOCK_TZCFGLOCK_Pos) /*!< TZCFGLOCK Get Value            */


#define EPWM_REGS_EPWMLOCK_GLLOCK_Pos    (1U)                                                                                  /*!< GLLOCK Postion   1          */ 
#define EPWM_REGS_EPWMLOCK_GLLOCK_Msk    (0x1U << EPWM_REGS_EPWMLOCK_GLLOCK_Pos)                                               /*!< GLLOCK Mask      0x00000002 */
#define EPWM_REGS_EPWMLOCK_GLLOCK_Set(x) (((uint32_t) (x) << EPWM_REGS_EPWMLOCK_GLLOCK_Pos) & EPWM_REGS_EPWMLOCK_GLLOCK_Msk)   /*!< GLLOCK Set Value            */
#define EPWM_REGS_EPWMLOCK_GLLOCK_Get(x) (((uint32_t) (x) & EPWM_REGS_EPWMLOCK_GLLOCK_Msk) >> EPWM_REGS_EPWMLOCK_GLLOCK_Pos)   /*!< GLLOCK Get Value            */


#define EPWM_REGS_EPWMLOCK_HRLOCK_Pos    (0U)                                                                                  /*!< HRLOCK Postion   0          */ 
#define EPWM_REGS_EPWMLOCK_HRLOCK_Msk    (0x1U << EPWM_REGS_EPWMLOCK_HRLOCK_Pos)                                               /*!< HRLOCK Mask      0x00000001 */
#define EPWM_REGS_EPWMLOCK_HRLOCK_Set(x) (((uint32_t) (x) << EPWM_REGS_EPWMLOCK_HRLOCK_Pos) & EPWM_REGS_EPWMLOCK_HRLOCK_Msk)   /*!< HRLOCK Set Value            */
#define EPWM_REGS_EPWMLOCK_HRLOCK_Get(x) (((uint32_t) (x) & EPWM_REGS_EPWMLOCK_HRLOCK_Msk) >> EPWM_REGS_EPWMLOCK_HRLOCK_Pos)   /*!< HRLOCK Get Value            */


/* HWVDELVAL bitfield */
#define EPWM_REGS_HWVDELVAL_HWVDELVAL_Pos    (0U)                                                                                  /*!< HWVDELVAL Postion   0          */ 
#define EPWM_REGS_HWVDELVAL_HWVDELVAL_Msk    (0xffffU << EPWM_REGS_HWVDELVAL_HWVDELVAL_Pos)                                        /*!< HWVDELVAL Mask      0x0000FFFF */
#define EPWM_REGS_HWVDELVAL_HWVDELVAL_Set(x) (((uint16_t) (x) << EPWM_REGS_HWVDELVAL_HWVDELVAL_Pos) & EPWM_REGS_HWVDELVAL_HWVDELVAL_Msk) /*!< HWVDELVAL Set Value            */
#define EPWM_REGS_HWVDELVAL_HWVDELVAL_Get(x) (((uint16_t) (x) & EPWM_REGS_HWVDELVAL_HWVDELVAL_Msk) >> EPWM_REGS_HWVDELVAL_HWVDELVAL_Pos) /*!< HWVDELVAL Get Value            */


/* VCNTVAL bitfield */
#define EPWM_REGS_VCNTVAL_VCNTVAL_Pos    (0U)                                                                                  /*!< VCNTVAL Postion   0          */ 
#define EPWM_REGS_VCNTVAL_VCNTVAL_Msk    (0xffffU << EPWM_REGS_VCNTVAL_VCNTVAL_Pos)                                            /*!< VCNTVAL Mask      0x0000FFFF */
#define EPWM_REGS_VCNTVAL_VCNTVAL_Set(x) (((uint32_t) (x) << EPWM_REGS_VCNTVAL_VCNTVAL_Pos) & EPWM_REGS_VCNTVAL_VCNTVAL_Msk)   /*!< VCNTVAL Set Value            */
#define EPWM_REGS_VCNTVAL_VCNTVAL_Get(x) (((uint32_t) (x) & EPWM_REGS_VCNTVAL_VCNTVAL_Msk) >> EPWM_REGS_VCNTVAL_VCNTVAL_Pos)   /*!< VCNTVAL Get Value            */


/* DCFCTL2 bitfield */
#define EPWM_REGS_DCFCTL2_EDGECAPMODE_Pos    (0U)                                                                                  /*!< EDGECAPMODE Postion   0          */ 
#define EPWM_REGS_DCFCTL2_EDGECAPMODE_Msk    (0x3U << EPWM_REGS_DCFCTL2_EDGECAPMODE_Pos)                                           /*!< EDGECAPMODE Mask      0x00000003 */
#define EPWM_REGS_DCFCTL2_EDGECAPMODE_Set(x) (((uint32_t) (x) << EPWM_REGS_DCFCTL2_EDGECAPMODE_Pos) & EPWM_REGS_DCFCTL2_EDGECAPMODE_Msk) /*!< EDGECAPMODE Set Value            */
#define EPWM_REGS_DCFCTL2_EDGECAPMODE_Get(x) (((uint32_t) (x) & EPWM_REGS_DCFCTL2_EDGECAPMODE_Msk) >> EPWM_REGS_DCFCTL2_EDGECAPMODE_Pos) /*!< EDGECAPMODE Get Value            */


/* TZDLYCTL bitfield */
#define EPWM_REGS_TZDLYCTL_DLYMODEB_Pos    (16U)                                                                                 /*!< DLYMODEB Postion   16         */ 
#define EPWM_REGS_TZDLYCTL_DLYMODEB_Msk    (0x1U << EPWM_REGS_TZDLYCTL_DLYMODEB_Pos)                                             /*!< DLYMODEB Mask      0x00010000 */
#define EPWM_REGS_TZDLYCTL_DLYMODEB_Set(x) (((uint32_t) (x) << EPWM_REGS_TZDLYCTL_DLYMODEB_Pos) & EPWM_REGS_TZDLYCTL_DLYMODEB_Msk) /*!< DLYMODEB Set Value            */
#define EPWM_REGS_TZDLYCTL_DLYMODEB_Get(x) (((uint32_t) (x) & EPWM_REGS_TZDLYCTL_DLYMODEB_Msk) >> EPWM_REGS_TZDLYCTL_DLYMODEB_Pos) /*!< DLYMODEB Get Value            */


#define EPWM_REGS_TZDLYCTL_DLYMODEA_Pos    (0U)                                                                                  /*!< DLYMODEA Postion   0          */ 
#define EPWM_REGS_TZDLYCTL_DLYMODEA_Msk    (0x1U << EPWM_REGS_TZDLYCTL_DLYMODEA_Pos)                                             /*!< DLYMODEA Mask      0x00000001 */
#define EPWM_REGS_TZDLYCTL_DLYMODEA_Set(x) (((uint32_t) (x) << EPWM_REGS_TZDLYCTL_DLYMODEA_Pos) & EPWM_REGS_TZDLYCTL_DLYMODEA_Msk) /*!< DLYMODEA Set Value            */
#define EPWM_REGS_TZDLYCTL_DLYMODEA_Get(x) (((uint32_t) (x) & EPWM_REGS_TZDLYCTL_DLYMODEA_Msk) >> EPWM_REGS_TZDLYCTL_DLYMODEA_Pos) /*!< DLYMODEA Get Value            */


/* TZDLYPRD bitfield */
#define EPWM_REGS_TZDLYPRD_BDLYPRD_Pos    (16U)                                                                                 /*!< BDLYPRD Postion   16         */ 
#define EPWM_REGS_TZDLYPRD_BDLYPRD_Msk    (0xffffU << EPWM_REGS_TZDLYPRD_BDLYPRD_Pos)                                           /*!< BDLYPRD Mask      0xFFFF0000 */
#define EPWM_REGS_TZDLYPRD_BDLYPRD_Set(x) (((uint32_t) (x) << EPWM_REGS_TZDLYPRD_BDLYPRD_Pos) & EPWM_REGS_TZDLYPRD_BDLYPRD_Msk) /*!< BDLYPRD Set Value            */
#define EPWM_REGS_TZDLYPRD_BDLYPRD_Get(x) (((uint32_t) (x) & EPWM_REGS_TZDLYPRD_BDLYPRD_Msk) >> EPWM_REGS_TZDLYPRD_BDLYPRD_Pos) /*!< BDLYPRD Get Value            */


#define EPWM_REGS_TZDLYPRD_ADLYPRD_Pos    (0U)                                                                                  /*!< ADLYPRD Postion   0          */ 
#define EPWM_REGS_TZDLYPRD_ADLYPRD_Msk    (0xffffU << EPWM_REGS_TZDLYPRD_ADLYPRD_Pos)                                           /*!< ADLYPRD Mask      0x0000FFFF */
#define EPWM_REGS_TZDLYPRD_ADLYPRD_Set(x) (((uint32_t) (x) << EPWM_REGS_TZDLYPRD_ADLYPRD_Pos) & EPWM_REGS_TZDLYPRD_ADLYPRD_Msk) /*!< ADLYPRD Set Value            */
#define EPWM_REGS_TZDLYPRD_ADLYPRD_Get(x) (((uint32_t) (x) & EPWM_REGS_TZDLYPRD_ADLYPRD_Msk) >> EPWM_REGS_TZDLYPRD_ADLYPRD_Pos) /*!< ADLYPRD Get Value            */


/* DICTL bitfield */
#define EPWM_REGS_DICTL_DIMODE_Pos    (24U)                                                                                 /*!< DIMODE Postion   24         */ 
#define EPWM_REGS_DICTL_DIMODE_Msk    (0x7U << EPWM_REGS_DICTL_DIMODE_Pos)                                                  /*!< DIMODE Mask      0x07000000 */
#define EPWM_REGS_DICTL_DIMODE_Set(x) (((uint32_t) (x) << EPWM_REGS_DICTL_DIMODE_Pos) & EPWM_REGS_DICTL_DIMODE_Msk)         /*!< DIMODE Set Value            */
#define EPWM_REGS_DICTL_DIMODE_Get(x) (((uint32_t) (x) & EPWM_REGS_DICTL_DIMODE_Msk) >> EPWM_REGS_DICTL_DIMODE_Pos)         /*!< DIMODE Get Value            */


#define EPWM_REGS_DICTL_DISWCLR_Pos    (16U)                                                                                 /*!< DISWCLR Postion   16         */ 
#define EPWM_REGS_DICTL_DISWCLR_Msk    (0x1U << EPWM_REGS_DICTL_DISWCLR_Pos)                                                 /*!< DISWCLR Mask      0x00010000 */
#define EPWM_REGS_DICTL_DISWCLR_Set(x) (((uint32_t) (x) << EPWM_REGS_DICTL_DISWCLR_Pos) & EPWM_REGS_DICTL_DISWCLR_Msk)       /*!< DISWCLR Set Value            */
#define EPWM_REGS_DICTL_DISWCLR_Get(x) (((uint32_t) (x) & EPWM_REGS_DICTL_DISWCLR_Msk) >> EPWM_REGS_DICTL_DISWCLR_Pos)       /*!< DISWCLR Get Value            */


#define EPWM_REGS_DICTL_DICMP_Pos    (8U)                                                                                  /*!< DICMP Postion   8          */ 
#define EPWM_REGS_DICTL_DICMP_Msk    (0xfU << EPWM_REGS_DICTL_DICMP_Pos)                                                   /*!< DICMP Mask      0x00000F00 */
#define EPWM_REGS_DICTL_DICMP_Set(x) (((uint32_t) (x) << EPWM_REGS_DICTL_DICMP_Pos) & EPWM_REGS_DICTL_DICMP_Msk)           /*!< DICMP Set Value            */
#define EPWM_REGS_DICTL_DICMP_Get(x) (((uint32_t) (x) & EPWM_REGS_DICTL_DICMP_Msk) >> EPWM_REGS_DICTL_DICMP_Pos)           /*!< DICMP Get Value            */


#define EPWM_REGS_DICTL_DICTR_Pos    (0U)                                                                                  /*!< DICTR Postion   0          */ 
#define EPWM_REGS_DICTL_DICTR_Msk    (0xfU << EPWM_REGS_DICTL_DICTR_Pos)                                                   /*!< DICTR Mask      0x0000000F */
#define EPWM_REGS_DICTL_DICTR_Set(x) (((uint32_t) (x) << EPWM_REGS_DICTL_DICTR_Pos) & EPWM_REGS_DICTL_DICTR_Msk)           /*!< DICTR Set Value            */
#define EPWM_REGS_DICTL_DICTR_Get(x) (((uint32_t) (x) & EPWM_REGS_DICTL_DICTR_Msk) >> EPWM_REGS_DICTL_DICTR_Pos)           /*!< DICTR Get Value            */


/* DBCLKGEN bitfield */
#define EPWM_REGS_DBCLKGEN_CNT_MAX_Pos    (16U)                                                                                 /*!< CNT_MAX Postion   16         */ 
#define EPWM_REGS_DBCLKGEN_CNT_MAX_Msk    (0x3ffU << EPWM_REGS_DBCLKGEN_CNT_MAX_Pos)                                            /*!< CNT_MAX Mask      0x03FF0000 */
#define EPWM_REGS_DBCLKGEN_CNT_MAX_Set(x) (((uint32_t) (x) << EPWM_REGS_DBCLKGEN_CNT_MAX_Pos) & EPWM_REGS_DBCLKGEN_CNT_MAX_Msk) /*!< CNT_MAX Set Value            */
#define EPWM_REGS_DBCLKGEN_CNT_MAX_Get(x) (((uint32_t) (x) & EPWM_REGS_DBCLKGEN_CNT_MAX_Msk) >> EPWM_REGS_DBCLKGEN_CNT_MAX_Pos) /*!< CNT_MAX Get Value            */


#define EPWM_REGS_DBCLKGEN_TC_CNT_Pos    (0U)                                                                                  /*!< TC_CNT Postion   0          */ 
#define EPWM_REGS_DBCLKGEN_TC_CNT_Msk    (0x3ffU << EPWM_REGS_DBCLKGEN_TC_CNT_Pos)                                             /*!< TC_CNT Mask      0x000003FF */
#define EPWM_REGS_DBCLKGEN_TC_CNT_Set(x) (((uint32_t) (x) << EPWM_REGS_DBCLKGEN_TC_CNT_Pos) & EPWM_REGS_DBCLKGEN_TC_CNT_Msk)   /*!< TC_CNT Set Value            */
#define EPWM_REGS_DBCLKGEN_TC_CNT_Get(x) (((uint32_t) (x) & EPWM_REGS_DBCLKGEN_TC_CNT_Msk) >> EPWM_REGS_DBCLKGEN_TC_CNT_Pos)   /*!< TC_CNT Get Value            */


/* DBLINKTCPRD bitfield */
#define EPWM_REGS_DBLINKTCPRD_PWM_LINK_TCPRD_SEL_Pos    (0U)                                                                                  /*!< PWM_LINK_TCPRD_SEL Postion   0          */ 
#define EPWM_REGS_DBLINKTCPRD_PWM_LINK_TCPRD_SEL_Msk    (0xffffU << EPWM_REGS_DBLINKTCPRD_PWM_LINK_TCPRD_SEL_Pos)                             /*!< PWM_LINK_TCPRD_SEL Mask      0x0000FFFF */
#define EPWM_REGS_DBLINKTCPRD_PWM_LINK_TCPRD_SEL_Set(x) (((uint32_t) (x) << EPWM_REGS_DBLINKTCPRD_PWM_LINK_TCPRD_SEL_Pos) & EPWM_REGS_DBLINKTCPRD_PWM_LINK_TCPRD_SEL_Msk) /*!< PWM_LINK_TCPRD_SEL Set Value            */
#define EPWM_REGS_DBLINKTCPRD_PWM_LINK_TCPRD_SEL_Get(x) (((uint32_t) (x) & EPWM_REGS_DBLINKTCPRD_PWM_LINK_TCPRD_SEL_Msk) >> EPWM_REGS_DBLINKTCPRD_PWM_LINK_TCPRD_SEL_Pos) /*!< PWM_LINK_TCPRD_SEL Get Value            */


/* DBLINKCMPAB bitfield */
#define EPWM_REGS_DBLINKCMPAB_PWM_LINK_CMPB_SEL_Pos    (16U)                                                                                 /*!< PWM_LINK_CMPB_SEL Postion   16         */ 
#define EPWM_REGS_DBLINKCMPAB_PWM_LINK_CMPB_SEL_Msk    (0xffffU << EPWM_REGS_DBLINKCMPAB_PWM_LINK_CMPB_SEL_Pos)                              /*!< PWM_LINK_CMPB_SEL Mask      0xFFFF0000 */
#define EPWM_REGS_DBLINKCMPAB_PWM_LINK_CMPB_SEL_Set(x) (((uint32_t) (x) << EPWM_REGS_DBLINKCMPAB_PWM_LINK_CMPB_SEL_Pos) & EPWM_REGS_DBLINKCMPAB_PWM_LINK_CMPB_SEL_Msk) /*!< PWM_LINK_CMPB_SEL Set Value            */
#define EPWM_REGS_DBLINKCMPAB_PWM_LINK_CMPB_SEL_Get(x) (((uint32_t) (x) & EPWM_REGS_DBLINKCMPAB_PWM_LINK_CMPB_SEL_Msk) >> EPWM_REGS_DBLINKCMPAB_PWM_LINK_CMPB_SEL_Pos) /*!< PWM_LINK_CMPB_SEL Get Value            */


#define EPWM_REGS_DBLINKCMPAB_PWM_LINK_CMPA_SEL_Pos    (0U)                                                                                  /*!< PWM_LINK_CMPA_SEL Postion   0          */ 
#define EPWM_REGS_DBLINKCMPAB_PWM_LINK_CMPA_SEL_Msk    (0xffffU << EPWM_REGS_DBLINKCMPAB_PWM_LINK_CMPA_SEL_Pos)                              /*!< PWM_LINK_CMPA_SEL Mask      0x0000FFFF */
#define EPWM_REGS_DBLINKCMPAB_PWM_LINK_CMPA_SEL_Set(x) (((uint32_t) (x) << EPWM_REGS_DBLINKCMPAB_PWM_LINK_CMPA_SEL_Pos) & EPWM_REGS_DBLINKCMPAB_PWM_LINK_CMPA_SEL_Msk) /*!< PWM_LINK_CMPA_SEL Set Value            */
#define EPWM_REGS_DBLINKCMPAB_PWM_LINK_CMPA_SEL_Get(x) (((uint32_t) (x) & EPWM_REGS_DBLINKCMPAB_PWM_LINK_CMPA_SEL_Msk) >> EPWM_REGS_DBLINKCMPAB_PWM_LINK_CMPA_SEL_Pos) /*!< PWM_LINK_CMPA_SEL Get Value            */


/* DBLINKCMPCD bitfield */
#define EPWM_REGS_DBLINKCMPCD_PWM_LINK_CMPD_SEL_Pos    (16U)                                                                                 /*!< PWM_LINK_CMPD_SEL Postion   16         */ 
#define EPWM_REGS_DBLINKCMPCD_PWM_LINK_CMPD_SEL_Msk    (0xffffU << EPWM_REGS_DBLINKCMPCD_PWM_LINK_CMPD_SEL_Pos)                              /*!< PWM_LINK_CMPD_SEL Mask      0xFFFF0000 */
#define EPWM_REGS_DBLINKCMPCD_PWM_LINK_CMPD_SEL_Set(x) (((uint32_t) (x) << EPWM_REGS_DBLINKCMPCD_PWM_LINK_CMPD_SEL_Pos) & EPWM_REGS_DBLINKCMPCD_PWM_LINK_CMPD_SEL_Msk) /*!< PWM_LINK_CMPD_SEL Set Value            */
#define EPWM_REGS_DBLINKCMPCD_PWM_LINK_CMPD_SEL_Get(x) (((uint32_t) (x) & EPWM_REGS_DBLINKCMPCD_PWM_LINK_CMPD_SEL_Msk) >> EPWM_REGS_DBLINKCMPCD_PWM_LINK_CMPD_SEL_Pos) /*!< PWM_LINK_CMPD_SEL Get Value            */


#define EPWM_REGS_DBLINKCMPCD_PWM_LINK_CMPC_SEL_Pos    (0U)                                                                                  /*!< PWM_LINK_CMPC_SEL Postion   0          */ 
#define EPWM_REGS_DBLINKCMPCD_PWM_LINK_CMPC_SEL_Msk    (0xffffU << EPWM_REGS_DBLINKCMPCD_PWM_LINK_CMPC_SEL_Pos)                              /*!< PWM_LINK_CMPC_SEL Mask      0x0000FFFF */
#define EPWM_REGS_DBLINKCMPCD_PWM_LINK_CMPC_SEL_Set(x) (((uint32_t) (x) << EPWM_REGS_DBLINKCMPCD_PWM_LINK_CMPC_SEL_Pos) & EPWM_REGS_DBLINKCMPCD_PWM_LINK_CMPC_SEL_Msk) /*!< PWM_LINK_CMPC_SEL Set Value            */
#define EPWM_REGS_DBLINKCMPCD_PWM_LINK_CMPC_SEL_Get(x) (((uint32_t) (x) & EPWM_REGS_DBLINKCMPCD_PWM_LINK_CMPC_SEL_Msk) >> EPWM_REGS_DBLINKCMPCD_PWM_LINK_CMPC_SEL_Pos) /*!< PWM_LINK_CMPC_SEL Get Value            */


/* DBLINKGLD bitfield */
#define EPWM_REGS_DBLINKGLD_PWM_LINK_GLDOOFFLOAD_SEL_Pos    (16U)                                                                                 /*!< PWM_LINK_GLDOOFFLOAD_SEL Postion   16         */ 
#define EPWM_REGS_DBLINKGLD_PWM_LINK_GLDOOFFLOAD_SEL_Msk    (0x1U << EPWM_REGS_DBLINKGLD_PWM_LINK_GLDOOFFLOAD_SEL_Pos)                            /*!< PWM_LINK_GLDOOFFLOAD_SEL Mask      0x00010000 */
#define EPWM_REGS_DBLINKGLD_PWM_LINK_GLDOOFFLOAD_SEL_Set(x) (((uint32_t) (x) << EPWM_REGS_DBLINKGLD_PWM_LINK_GLDOOFFLOAD_SEL_Pos) & EPWM_REGS_DBLINKGLD_PWM_LINK_GLDOOFFLOAD_SEL_Msk) /*!< PWM_LINK_GLDOOFFLOAD_SEL Set Value            */
#define EPWM_REGS_DBLINKGLD_PWM_LINK_GLDOOFFLOAD_SEL_Get(x) (((uint32_t) (x) & EPWM_REGS_DBLINKGLD_PWM_LINK_GLDOOFFLOAD_SEL_Msk) >> EPWM_REGS_DBLINKGLD_PWM_LINK_GLDOOFFLOAD_SEL_Pos) /*!< PWM_LINK_GLDOOFFLOAD_SEL Get Value            */


#define EPWM_REGS_DBLINKGLD_PWM_LINK_GLDFRCLOAD_SEL_Pos    (0U)                                                                                  /*!< PWM_LINK_GLDFRCLOAD_SEL Postion   0          */ 
#define EPWM_REGS_DBLINKGLD_PWM_LINK_GLDFRCLOAD_SEL_Msk    (0x1U << EPWM_REGS_DBLINKGLD_PWM_LINK_GLDFRCLOAD_SEL_Pos)                             /*!< PWM_LINK_GLDFRCLOAD_SEL Mask      0x00000001 */
#define EPWM_REGS_DBLINKGLD_PWM_LINK_GLDFRCLOAD_SEL_Set(x) (((uint32_t) (x) << EPWM_REGS_DBLINKGLD_PWM_LINK_GLDFRCLOAD_SEL_Pos) & EPWM_REGS_DBLINKGLD_PWM_LINK_GLDFRCLOAD_SEL_Msk) /*!< PWM_LINK_GLDFRCLOAD_SEL Set Value            */
#define EPWM_REGS_DBLINKGLD_PWM_LINK_GLDFRCLOAD_SEL_Get(x) (((uint32_t) (x) & EPWM_REGS_DBLINKGLD_PWM_LINK_GLDFRCLOAD_SEL_Msk) >> EPWM_REGS_DBLINKGLD_PWM_LINK_GLDFRCLOAD_SEL_Pos) /*!< PWM_LINK_GLDFRCLOAD_SEL Get Value            */


/* DBSHDTCPRD bitfield */
#define EPWM_REGS_DBSHDTCPRD_RA_TCPRD_TCPRD_Pos    (0U)                                                                                  /*!< RA_TCPRD_TCPRD Postion   0          */ 
#define EPWM_REGS_DBSHDTCPRD_RA_TCPRD_TCPRD_Msk    (0xffffU << EPWM_REGS_DBSHDTCPRD_RA_TCPRD_TCPRD_Pos)                                  /*!< RA_TCPRD_TCPRD Mask      0x0000FFFF */
#define EPWM_REGS_DBSHDTCPRD_RA_TCPRD_TCPRD_Set(x) (((uint32_t) (x) << EPWM_REGS_DBSHDTCPRD_RA_TCPRD_TCPRD_Pos) & EPWM_REGS_DBSHDTCPRD_RA_TCPRD_TCPRD_Msk) /*!< RA_TCPRD_TCPRD Set Value            */
#define EPWM_REGS_DBSHDTCPRD_RA_TCPRD_TCPRD_Get(x) (((uint32_t) (x) & EPWM_REGS_DBSHDTCPRD_RA_TCPRD_TCPRD_Msk) >> EPWM_REGS_DBSHDTCPRD_RA_TCPRD_TCPRD_Pos) /*!< RA_TCPRD_TCPRD Get Value            */


/* DBSHDCMPAB bitfield */
#define EPWM_REGS_DBSHDCMPAB_RA_CMPB_CMPB_Pos    (16U)                                                                                 /*!< RA_CMPB_CMPB Postion   16         */ 
#define EPWM_REGS_DBSHDCMPAB_RA_CMPB_CMPB_Msk    (0xffffU << EPWM_REGS_DBSHDCMPAB_RA_CMPB_CMPB_Pos)                                    /*!< RA_CMPB_CMPB Mask      0xFFFF0000 */
#define EPWM_REGS_DBSHDCMPAB_RA_CMPB_CMPB_Set(x) (((uint32_t) (x) << EPWM_REGS_DBSHDCMPAB_RA_CMPB_CMPB_Pos) & EPWM_REGS_DBSHDCMPAB_RA_CMPB_CMPB_Msk) /*!< RA_CMPB_CMPB Set Value            */
#define EPWM_REGS_DBSHDCMPAB_RA_CMPB_CMPB_Get(x) (((uint32_t) (x) & EPWM_REGS_DBSHDCMPAB_RA_CMPB_CMPB_Msk) >> EPWM_REGS_DBSHDCMPAB_RA_CMPB_CMPB_Pos) /*!< RA_CMPB_CMPB Get Value            */


#define EPWM_REGS_DBSHDCMPAB_RA_CMPA_CMPA_Pos    (0U)                                                                                  /*!< RA_CMPA_CMPA Postion   0          */ 
#define EPWM_REGS_DBSHDCMPAB_RA_CMPA_CMPA_Msk    (0xffffU << EPWM_REGS_DBSHDCMPAB_RA_CMPA_CMPA_Pos)                                    /*!< RA_CMPA_CMPA Mask      0x0000FFFF */
#define EPWM_REGS_DBSHDCMPAB_RA_CMPA_CMPA_Set(x) (((uint32_t) (x) << EPWM_REGS_DBSHDCMPAB_RA_CMPA_CMPA_Pos) & EPWM_REGS_DBSHDCMPAB_RA_CMPA_CMPA_Msk) /*!< RA_CMPA_CMPA Set Value            */
#define EPWM_REGS_DBSHDCMPAB_RA_CMPA_CMPA_Get(x) (((uint32_t) (x) & EPWM_REGS_DBSHDCMPAB_RA_CMPA_CMPA_Msk) >> EPWM_REGS_DBSHDCMPAB_RA_CMPA_CMPA_Pos) /*!< RA_CMPA_CMPA Get Value            */


/* DBSHDCMPCD bitfield */
#define EPWM_REGS_DBSHDCMPCD_RA_CMPD_CMPD_Pos    (16U)                                                                                 /*!< RA_CMPD_CMPD Postion   16         */ 
#define EPWM_REGS_DBSHDCMPCD_RA_CMPD_CMPD_Msk    (0xffffU << EPWM_REGS_DBSHDCMPCD_RA_CMPD_CMPD_Pos)                                    /*!< RA_CMPD_CMPD Mask      0xFFFF0000 */
#define EPWM_REGS_DBSHDCMPCD_RA_CMPD_CMPD_Set(x) (((uint32_t) (x) << EPWM_REGS_DBSHDCMPCD_RA_CMPD_CMPD_Pos) & EPWM_REGS_DBSHDCMPCD_RA_CMPD_CMPD_Msk) /*!< RA_CMPD_CMPD Set Value            */
#define EPWM_REGS_DBSHDCMPCD_RA_CMPD_CMPD_Get(x) (((uint32_t) (x) & EPWM_REGS_DBSHDCMPCD_RA_CMPD_CMPD_Msk) >> EPWM_REGS_DBSHDCMPCD_RA_CMPD_CMPD_Pos) /*!< RA_CMPD_CMPD Get Value            */


#define EPWM_REGS_DBSHDCMPCD_RA_CMPC_CMPC_Pos    (0U)                                                                                  /*!< RA_CMPC_CMPC Postion   0          */ 
#define EPWM_REGS_DBSHDCMPCD_RA_CMPC_CMPC_Msk    (0xffffU << EPWM_REGS_DBSHDCMPCD_RA_CMPC_CMPC_Pos)                                    /*!< RA_CMPC_CMPC Mask      0x0000FFFF */
#define EPWM_REGS_DBSHDCMPCD_RA_CMPC_CMPC_Set(x) (((uint32_t) (x) << EPWM_REGS_DBSHDCMPCD_RA_CMPC_CMPC_Pos) & EPWM_REGS_DBSHDCMPCD_RA_CMPC_CMPC_Msk) /*!< RA_CMPC_CMPC Set Value            */
#define EPWM_REGS_DBSHDCMPCD_RA_CMPC_CMPC_Get(x) (((uint32_t) (x) & EPWM_REGS_DBSHDCMPCD_RA_CMPC_CMPC_Msk) >> EPWM_REGS_DBSHDCMPCD_RA_CMPC_CMPC_Pos) /*!< RA_CMPC_CMPC Get Value            */


/* DBSHDWGA bitfield */
#define EPWM_REGS_DBSHDWGA_RA_WGCTL_CSWFRCACTA_Pos    (24U)                                                                                 /*!< RA_WGCTL_CSWFRCACTA Postion   24         */ 
#define EPWM_REGS_DBSHDWGA_RA_WGCTL_CSWFRCACTA_Msk    (0x3U << EPWM_REGS_DBSHDWGA_RA_WGCTL_CSWFRCACTA_Pos)                                  /*!< RA_WGCTL_CSWFRCACTA Mask      0x03000000 */
#define EPWM_REGS_DBSHDWGA_RA_WGCTL_CSWFRCACTA_Set(x) (((uint32_t) (x) << EPWM_REGS_DBSHDWGA_RA_WGCTL_CSWFRCACTA_Pos) & EPWM_REGS_DBSHDWGA_RA_WGCTL_CSWFRCACTA_Msk) /*!< RA_WGCTL_CSWFRCACTA Set Value            */
#define EPWM_REGS_DBSHDWGA_RA_WGCTL_CSWFRCACTA_Get(x) (((uint32_t) (x) & EPWM_REGS_DBSHDWGA_RA_WGCTL_CSWFRCACTA_Msk) >> EPWM_REGS_DBSHDWGA_RA_WGCTL_CSWFRCACTA_Pos) /*!< RA_WGCTL_CSWFRCACTA Get Value            */


#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_AEVT2U_Pos    (22U)                                                                                 /*!< RA_WGCFGA_AEVT2U Postion   22         */ 
#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_AEVT2U_Msk    (0x3U << EPWM_REGS_DBSHDWGA_RA_WGCFGA_AEVT2U_Pos)                                     /*!< RA_WGCFGA_AEVT2U Mask      0x00C00000 */
#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_AEVT2U_Set(x) (((uint32_t) (x) << EPWM_REGS_DBSHDWGA_RA_WGCFGA_AEVT2U_Pos) & EPWM_REGS_DBSHDWGA_RA_WGCFGA_AEVT2U_Msk) /*!< RA_WGCFGA_AEVT2U Set Value            */
#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_AEVT2U_Get(x) (((uint32_t) (x) & EPWM_REGS_DBSHDWGA_RA_WGCFGA_AEVT2U_Msk) >> EPWM_REGS_DBSHDWGA_RA_WGCFGA_AEVT2U_Pos) /*!< RA_WGCFGA_AEVT2U Get Value            */


#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_AEVT2D_Pos    (20U)                                                                                 /*!< RA_WGCFGA_AEVT2D Postion   20         */ 
#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_AEVT2D_Msk    (0x3U << EPWM_REGS_DBSHDWGA_RA_WGCFGA_AEVT2D_Pos)                                     /*!< RA_WGCFGA_AEVT2D Mask      0x00300000 */
#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_AEVT2D_Set(x) (((uint32_t) (x) << EPWM_REGS_DBSHDWGA_RA_WGCFGA_AEVT2D_Pos) & EPWM_REGS_DBSHDWGA_RA_WGCFGA_AEVT2D_Msk) /*!< RA_WGCFGA_AEVT2D Set Value            */
#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_AEVT2D_Get(x) (((uint32_t) (x) & EPWM_REGS_DBSHDWGA_RA_WGCFGA_AEVT2D_Msk) >> EPWM_REGS_DBSHDWGA_RA_WGCFGA_AEVT2D_Pos) /*!< RA_WGCFGA_AEVT2D Get Value            */


#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_AEVT1U_Pos    (18U)                                                                                 /*!< RA_WGCFGA_AEVT1U Postion   18         */ 
#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_AEVT1U_Msk    (0x3U << EPWM_REGS_DBSHDWGA_RA_WGCFGA_AEVT1U_Pos)                                     /*!< RA_WGCFGA_AEVT1U Mask      0x000C0000 */
#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_AEVT1U_Set(x) (((uint32_t) (x) << EPWM_REGS_DBSHDWGA_RA_WGCFGA_AEVT1U_Pos) & EPWM_REGS_DBSHDWGA_RA_WGCFGA_AEVT1U_Msk) /*!< RA_WGCFGA_AEVT1U Set Value            */
#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_AEVT1U_Get(x) (((uint32_t) (x) & EPWM_REGS_DBSHDWGA_RA_WGCFGA_AEVT1U_Msk) >> EPWM_REGS_DBSHDWGA_RA_WGCFGA_AEVT1U_Pos) /*!< RA_WGCFGA_AEVT1U Get Value            */


#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_AEVT1D_Pos    (16U)                                                                                 /*!< RA_WGCFGA_AEVT1D Postion   16         */ 
#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_AEVT1D_Msk    (0x3U << EPWM_REGS_DBSHDWGA_RA_WGCFGA_AEVT1D_Pos)                                     /*!< RA_WGCFGA_AEVT1D Mask      0x00030000 */
#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_AEVT1D_Set(x) (((uint32_t) (x) << EPWM_REGS_DBSHDWGA_RA_WGCFGA_AEVT1D_Pos) & EPWM_REGS_DBSHDWGA_RA_WGCFGA_AEVT1D_Msk) /*!< RA_WGCFGA_AEVT1D Set Value            */
#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_AEVT1D_Get(x) (((uint32_t) (x) & EPWM_REGS_DBSHDWGA_RA_WGCFGA_AEVT1D_Msk) >> EPWM_REGS_DBSHDWGA_RA_WGCFGA_AEVT1D_Pos) /*!< RA_WGCFGA_AEVT1D Get Value            */


#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_APRD_Pos    (10U)                                                                                 /*!< RA_WGCFGA_APRD Postion   10         */ 
#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_APRD_Msk    (0x3U << EPWM_REGS_DBSHDWGA_RA_WGCFGA_APRD_Pos)                                       /*!< RA_WGCFGA_APRD Mask      0x00000C00 */
#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_APRD_Set(x) (((uint32_t) (x) << EPWM_REGS_DBSHDWGA_RA_WGCFGA_APRD_Pos) & EPWM_REGS_DBSHDWGA_RA_WGCFGA_APRD_Msk) /*!< RA_WGCFGA_APRD Set Value            */
#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_APRD_Get(x) (((uint32_t) (x) & EPWM_REGS_DBSHDWGA_RA_WGCFGA_APRD_Msk) >> EPWM_REGS_DBSHDWGA_RA_WGCFGA_APRD_Pos) /*!< RA_WGCFGA_APRD Get Value            */


#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_AZRO_Pos    (8U)                                                                                  /*!< RA_WGCFGA_AZRO Postion   8          */ 
#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_AZRO_Msk    (0x3U << EPWM_REGS_DBSHDWGA_RA_WGCFGA_AZRO_Pos)                                       /*!< RA_WGCFGA_AZRO Mask      0x00000300 */
#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_AZRO_Set(x) (((uint32_t) (x) << EPWM_REGS_DBSHDWGA_RA_WGCFGA_AZRO_Pos) & EPWM_REGS_DBSHDWGA_RA_WGCFGA_AZRO_Msk) /*!< RA_WGCFGA_AZRO Set Value            */
#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_AZRO_Get(x) (((uint32_t) (x) & EPWM_REGS_DBSHDWGA_RA_WGCFGA_AZRO_Msk) >> EPWM_REGS_DBSHDWGA_RA_WGCFGA_AZRO_Pos) /*!< RA_WGCFGA_AZRO Get Value            */


#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_ACBU_Pos    (6U)                                                                                  /*!< RA_WGCFGA_ACBU Postion   6          */ 
#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_ACBU_Msk    (0x3U << EPWM_REGS_DBSHDWGA_RA_WGCFGA_ACBU_Pos)                                       /*!< RA_WGCFGA_ACBU Mask      0x000000C0 */
#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_ACBU_Set(x) (((uint32_t) (x) << EPWM_REGS_DBSHDWGA_RA_WGCFGA_ACBU_Pos) & EPWM_REGS_DBSHDWGA_RA_WGCFGA_ACBU_Msk) /*!< RA_WGCFGA_ACBU Set Value            */
#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_ACBU_Get(x) (((uint32_t) (x) & EPWM_REGS_DBSHDWGA_RA_WGCFGA_ACBU_Msk) >> EPWM_REGS_DBSHDWGA_RA_WGCFGA_ACBU_Pos) /*!< RA_WGCFGA_ACBU Get Value            */


#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_ACBD_Pos    (4U)                                                                                  /*!< RA_WGCFGA_ACBD Postion   4          */ 
#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_ACBD_Msk    (0x3U << EPWM_REGS_DBSHDWGA_RA_WGCFGA_ACBD_Pos)                                       /*!< RA_WGCFGA_ACBD Mask      0x00000030 */
#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_ACBD_Set(x) (((uint32_t) (x) << EPWM_REGS_DBSHDWGA_RA_WGCFGA_ACBD_Pos) & EPWM_REGS_DBSHDWGA_RA_WGCFGA_ACBD_Msk) /*!< RA_WGCFGA_ACBD Set Value            */
#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_ACBD_Get(x) (((uint32_t) (x) & EPWM_REGS_DBSHDWGA_RA_WGCFGA_ACBD_Msk) >> EPWM_REGS_DBSHDWGA_RA_WGCFGA_ACBD_Pos) /*!< RA_WGCFGA_ACBD Get Value            */


#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_ACAU_Pos    (2U)                                                                                  /*!< RA_WGCFGA_ACAU Postion   2          */ 
#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_ACAU_Msk    (0x3U << EPWM_REGS_DBSHDWGA_RA_WGCFGA_ACAU_Pos)                                       /*!< RA_WGCFGA_ACAU Mask      0x0000000C */
#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_ACAU_Set(x) (((uint32_t) (x) << EPWM_REGS_DBSHDWGA_RA_WGCFGA_ACAU_Pos) & EPWM_REGS_DBSHDWGA_RA_WGCFGA_ACAU_Msk) /*!< RA_WGCFGA_ACAU Set Value            */
#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_ACAU_Get(x) (((uint32_t) (x) & EPWM_REGS_DBSHDWGA_RA_WGCFGA_ACAU_Msk) >> EPWM_REGS_DBSHDWGA_RA_WGCFGA_ACAU_Pos) /*!< RA_WGCFGA_ACAU Get Value            */


#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_ACAD_Pos    (0U)                                                                                  /*!< RA_WGCFGA_ACAD Postion   0          */ 
#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_ACAD_Msk    (0x3U << EPWM_REGS_DBSHDWGA_RA_WGCFGA_ACAD_Pos)                                       /*!< RA_WGCFGA_ACAD Mask      0x00000003 */
#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_ACAD_Set(x) (((uint32_t) (x) << EPWM_REGS_DBSHDWGA_RA_WGCFGA_ACAD_Pos) & EPWM_REGS_DBSHDWGA_RA_WGCFGA_ACAD_Msk) /*!< RA_WGCFGA_ACAD Set Value            */
#define EPWM_REGS_DBSHDWGA_RA_WGCFGA_ACAD_Get(x) (((uint32_t) (x) & EPWM_REGS_DBSHDWGA_RA_WGCFGA_ACAD_Msk) >> EPWM_REGS_DBSHDWGA_RA_WGCFGA_ACAD_Pos) /*!< RA_WGCFGA_ACAD Get Value            */


/* DBSHDWGB bitfield */
#define EPWM_REGS_DBSHDWGB_RA_WGCTL_CSWFRCACTB_Pos    (24U)                                                                                 /*!< RA_WGCTL_CSWFRCACTB Postion   24         */ 
#define EPWM_REGS_DBSHDWGB_RA_WGCTL_CSWFRCACTB_Msk    (0x3U << EPWM_REGS_DBSHDWGB_RA_WGCTL_CSWFRCACTB_Pos)                                  /*!< RA_WGCTL_CSWFRCACTB Mask      0x03000000 */
#define EPWM_REGS_DBSHDWGB_RA_WGCTL_CSWFRCACTB_Set(x) (((uint32_t) (x) << EPWM_REGS_DBSHDWGB_RA_WGCTL_CSWFRCACTB_Pos) & EPWM_REGS_DBSHDWGB_RA_WGCTL_CSWFRCACTB_Msk) /*!< RA_WGCTL_CSWFRCACTB Set Value            */
#define EPWM_REGS_DBSHDWGB_RA_WGCTL_CSWFRCACTB_Get(x) (((uint32_t) (x) & EPWM_REGS_DBSHDWGB_RA_WGCTL_CSWFRCACTB_Msk) >> EPWM_REGS_DBSHDWGB_RA_WGCTL_CSWFRCACTB_Pos) /*!< RA_WGCTL_CSWFRCACTB Get Value            */


#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BEVT2U_Pos    (22U)                                                                                 /*!< RA_WGCFGB_BEVT2U Postion   22         */ 
#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BEVT2U_Msk    (0x3U << EPWM_REGS_DBSHDWGB_RA_WGCFGB_BEVT2U_Pos)                                     /*!< RA_WGCFGB_BEVT2U Mask      0x00C00000 */
#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BEVT2U_Set(x) (((uint32_t) (x) << EPWM_REGS_DBSHDWGB_RA_WGCFGB_BEVT2U_Pos) & EPWM_REGS_DBSHDWGB_RA_WGCFGB_BEVT2U_Msk) /*!< RA_WGCFGB_BEVT2U Set Value            */
#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BEVT2U_Get(x) (((uint32_t) (x) & EPWM_REGS_DBSHDWGB_RA_WGCFGB_BEVT2U_Msk) >> EPWM_REGS_DBSHDWGB_RA_WGCFGB_BEVT2U_Pos) /*!< RA_WGCFGB_BEVT2U Get Value            */


#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BEVT2D_Pos    (20U)                                                                                 /*!< RA_WGCFGB_BEVT2D Postion   20         */ 
#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BEVT2D_Msk    (0x3U << EPWM_REGS_DBSHDWGB_RA_WGCFGB_BEVT2D_Pos)                                     /*!< RA_WGCFGB_BEVT2D Mask      0x00300000 */
#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BEVT2D_Set(x) (((uint32_t) (x) << EPWM_REGS_DBSHDWGB_RA_WGCFGB_BEVT2D_Pos) & EPWM_REGS_DBSHDWGB_RA_WGCFGB_BEVT2D_Msk) /*!< RA_WGCFGB_BEVT2D Set Value            */
#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BEVT2D_Get(x) (((uint32_t) (x) & EPWM_REGS_DBSHDWGB_RA_WGCFGB_BEVT2D_Msk) >> EPWM_REGS_DBSHDWGB_RA_WGCFGB_BEVT2D_Pos) /*!< RA_WGCFGB_BEVT2D Get Value            */


#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BEVT1U_Pos    (18U)                                                                                 /*!< RA_WGCFGB_BEVT1U Postion   18         */ 
#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BEVT1U_Msk    (0x3U << EPWM_REGS_DBSHDWGB_RA_WGCFGB_BEVT1U_Pos)                                     /*!< RA_WGCFGB_BEVT1U Mask      0x000C0000 */
#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BEVT1U_Set(x) (((uint32_t) (x) << EPWM_REGS_DBSHDWGB_RA_WGCFGB_BEVT1U_Pos) & EPWM_REGS_DBSHDWGB_RA_WGCFGB_BEVT1U_Msk) /*!< RA_WGCFGB_BEVT1U Set Value            */
#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BEVT1U_Get(x) (((uint32_t) (x) & EPWM_REGS_DBSHDWGB_RA_WGCFGB_BEVT1U_Msk) >> EPWM_REGS_DBSHDWGB_RA_WGCFGB_BEVT1U_Pos) /*!< RA_WGCFGB_BEVT1U Get Value            */


#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BEVT1D_Pos    (16U)                                                                                 /*!< RA_WGCFGB_BEVT1D Postion   16         */ 
#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BEVT1D_Msk    (0x3U << EPWM_REGS_DBSHDWGB_RA_WGCFGB_BEVT1D_Pos)                                     /*!< RA_WGCFGB_BEVT1D Mask      0x00030000 */
#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BEVT1D_Set(x) (((uint32_t) (x) << EPWM_REGS_DBSHDWGB_RA_WGCFGB_BEVT1D_Pos) & EPWM_REGS_DBSHDWGB_RA_WGCFGB_BEVT1D_Msk) /*!< RA_WGCFGB_BEVT1D Set Value            */
#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BEVT1D_Get(x) (((uint32_t) (x) & EPWM_REGS_DBSHDWGB_RA_WGCFGB_BEVT1D_Msk) >> EPWM_REGS_DBSHDWGB_RA_WGCFGB_BEVT1D_Pos) /*!< RA_WGCFGB_BEVT1D Get Value            */


#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BPRD_Pos    (10U)                                                                                 /*!< RA_WGCFGB_BPRD Postion   10         */ 
#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BPRD_Msk    (0x3U << EPWM_REGS_DBSHDWGB_RA_WGCFGB_BPRD_Pos)                                       /*!< RA_WGCFGB_BPRD Mask      0x00000C00 */
#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BPRD_Set(x) (((uint32_t) (x) << EPWM_REGS_DBSHDWGB_RA_WGCFGB_BPRD_Pos) & EPWM_REGS_DBSHDWGB_RA_WGCFGB_BPRD_Msk) /*!< RA_WGCFGB_BPRD Set Value            */
#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BPRD_Get(x) (((uint32_t) (x) & EPWM_REGS_DBSHDWGB_RA_WGCFGB_BPRD_Msk) >> EPWM_REGS_DBSHDWGB_RA_WGCFGB_BPRD_Pos) /*!< RA_WGCFGB_BPRD Get Value            */


#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BZRO_Pos    (8U)                                                                                  /*!< RA_WGCFGB_BZRO Postion   8          */ 
#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BZRO_Msk    (0x3U << EPWM_REGS_DBSHDWGB_RA_WGCFGB_BZRO_Pos)                                       /*!< RA_WGCFGB_BZRO Mask      0x00000300 */
#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BZRO_Set(x) (((uint32_t) (x) << EPWM_REGS_DBSHDWGB_RA_WGCFGB_BZRO_Pos) & EPWM_REGS_DBSHDWGB_RA_WGCFGB_BZRO_Msk) /*!< RA_WGCFGB_BZRO Set Value            */
#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BZRO_Get(x) (((uint32_t) (x) & EPWM_REGS_DBSHDWGB_RA_WGCFGB_BZRO_Msk) >> EPWM_REGS_DBSHDWGB_RA_WGCFGB_BZRO_Pos) /*!< RA_WGCFGB_BZRO Get Value            */


#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BCBU_Pos    (6U)                                                                                  /*!< RA_WGCFGB_BCBU Postion   6          */ 
#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BCBU_Msk    (0x3U << EPWM_REGS_DBSHDWGB_RA_WGCFGB_BCBU_Pos)                                       /*!< RA_WGCFGB_BCBU Mask      0x000000C0 */
#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BCBU_Set(x) (((uint32_t) (x) << EPWM_REGS_DBSHDWGB_RA_WGCFGB_BCBU_Pos) & EPWM_REGS_DBSHDWGB_RA_WGCFGB_BCBU_Msk) /*!< RA_WGCFGB_BCBU Set Value            */
#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BCBU_Get(x) (((uint32_t) (x) & EPWM_REGS_DBSHDWGB_RA_WGCFGB_BCBU_Msk) >> EPWM_REGS_DBSHDWGB_RA_WGCFGB_BCBU_Pos) /*!< RA_WGCFGB_BCBU Get Value            */


#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BCBD_Pos    (4U)                                                                                  /*!< RA_WGCFGB_BCBD Postion   4          */ 
#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BCBD_Msk    (0x3U << EPWM_REGS_DBSHDWGB_RA_WGCFGB_BCBD_Pos)                                       /*!< RA_WGCFGB_BCBD Mask      0x00000030 */
#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BCBD_Set(x) (((uint32_t) (x) << EPWM_REGS_DBSHDWGB_RA_WGCFGB_BCBD_Pos) & EPWM_REGS_DBSHDWGB_RA_WGCFGB_BCBD_Msk) /*!< RA_WGCFGB_BCBD Set Value            */
#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BCBD_Get(x) (((uint32_t) (x) & EPWM_REGS_DBSHDWGB_RA_WGCFGB_BCBD_Msk) >> EPWM_REGS_DBSHDWGB_RA_WGCFGB_BCBD_Pos) /*!< RA_WGCFGB_BCBD Get Value            */


#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BCAU_Pos    (2U)                                                                                  /*!< RA_WGCFGB_BCAU Postion   2          */ 
#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BCAU_Msk    (0x3U << EPWM_REGS_DBSHDWGB_RA_WGCFGB_BCAU_Pos)                                       /*!< RA_WGCFGB_BCAU Mask      0x0000000C */
#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BCAU_Set(x) (((uint32_t) (x) << EPWM_REGS_DBSHDWGB_RA_WGCFGB_BCAU_Pos) & EPWM_REGS_DBSHDWGB_RA_WGCFGB_BCAU_Msk) /*!< RA_WGCFGB_BCAU Set Value            */
#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BCAU_Get(x) (((uint32_t) (x) & EPWM_REGS_DBSHDWGB_RA_WGCFGB_BCAU_Msk) >> EPWM_REGS_DBSHDWGB_RA_WGCFGB_BCAU_Pos) /*!< RA_WGCFGB_BCAU Get Value            */


#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BCAD_Pos    (0U)                                                                                  /*!< RA_WGCFGB_BCAD Postion   0          */ 
#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BCAD_Msk    (0x3U << EPWM_REGS_DBSHDWGB_RA_WGCFGB_BCAD_Pos)                                       /*!< RA_WGCFGB_BCAD Mask      0x00000003 */
#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BCAD_Set(x) (((uint32_t) (x) << EPWM_REGS_DBSHDWGB_RA_WGCFGB_BCAD_Pos) & EPWM_REGS_DBSHDWGB_RA_WGCFGB_BCAD_Msk) /*!< RA_WGCFGB_BCAD Set Value            */
#define EPWM_REGS_DBSHDWGB_RA_WGCFGB_BCAD_Get(x) (((uint32_t) (x) & EPWM_REGS_DBSHDWGB_RA_WGCFGB_BCAD_Msk) >> EPWM_REGS_DBSHDWGB_RA_WGCFGB_BCAD_Pos) /*!< RA_WGCFGB_BCAD Get Value            */


/* DBSHDDTCTL bitfield */
#define EPWM_REGS_DBSHDDTCTL_RA_DTCTL_OUTSEL_Pos    (16U)                                                                                 /*!< RA_DTCTL_OUTSEL Postion   16         */ 
#define EPWM_REGS_DBSHDDTCTL_RA_DTCTL_OUTSEL_Msk    (0x3U << EPWM_REGS_DBSHDDTCTL_RA_DTCTL_OUTSEL_Pos)                                    /*!< RA_DTCTL_OUTSEL Mask      0x00030000 */
#define EPWM_REGS_DBSHDDTCTL_RA_DTCTL_OUTSEL_Set(x) (((uint32_t) (x) << EPWM_REGS_DBSHDDTCTL_RA_DTCTL_OUTSEL_Pos) & EPWM_REGS_DBSHDDTCTL_RA_DTCTL_OUTSEL_Msk) /*!< RA_DTCTL_OUTSEL Set Value            */
#define EPWM_REGS_DBSHDDTCTL_RA_DTCTL_OUTSEL_Get(x) (((uint32_t) (x) & EPWM_REGS_DBSHDDTCTL_RA_DTCTL_OUTSEL_Msk) >> EPWM_REGS_DBSHDDTCTL_RA_DTCTL_OUTSEL_Pos) /*!< RA_DTCTL_OUTSEL Get Value            */


#define EPWM_REGS_DBSHDDTCTL_RA_DTCTL_POLSEL_Pos    (8U)                                                                                  /*!< RA_DTCTL_POLSEL Postion   8          */ 
#define EPWM_REGS_DBSHDDTCTL_RA_DTCTL_POLSEL_Msk    (0x3U << EPWM_REGS_DBSHDDTCTL_RA_DTCTL_POLSEL_Pos)                                    /*!< RA_DTCTL_POLSEL Mask      0x00000300 */
#define EPWM_REGS_DBSHDDTCTL_RA_DTCTL_POLSEL_Set(x) (((uint32_t) (x) << EPWM_REGS_DBSHDDTCTL_RA_DTCTL_POLSEL_Pos) & EPWM_REGS_DBSHDDTCTL_RA_DTCTL_POLSEL_Msk) /*!< RA_DTCTL_POLSEL Set Value            */
#define EPWM_REGS_DBSHDDTCTL_RA_DTCTL_POLSEL_Get(x) (((uint32_t) (x) & EPWM_REGS_DBSHDDTCTL_RA_DTCTL_POLSEL_Msk) >> EPWM_REGS_DBSHDDTCTL_RA_DTCTL_POLSEL_Pos) /*!< RA_DTCTL_POLSEL Get Value            */


#define EPWM_REGS_DBSHDDTCTL_RA_DTCTL_INSEL_Pos    (0U)                                                                                  /*!< RA_DTCTL_INSEL Postion   0          */ 
#define EPWM_REGS_DBSHDDTCTL_RA_DTCTL_INSEL_Msk    (0x3U << EPWM_REGS_DBSHDDTCTL_RA_DTCTL_INSEL_Pos)                                     /*!< RA_DTCTL_INSEL Mask      0x00000003 */
#define EPWM_REGS_DBSHDDTCTL_RA_DTCTL_INSEL_Set(x) (((uint32_t) (x) << EPWM_REGS_DBSHDDTCTL_RA_DTCTL_INSEL_Pos) & EPWM_REGS_DBSHDDTCTL_RA_DTCTL_INSEL_Msk) /*!< RA_DTCTL_INSEL Set Value            */
#define EPWM_REGS_DBSHDDTCTL_RA_DTCTL_INSEL_Get(x) (((uint32_t) (x) & EPWM_REGS_DBSHDDTCTL_RA_DTCTL_INSEL_Msk) >> EPWM_REGS_DBSHDDTCTL_RA_DTCTL_INSEL_Pos) /*!< RA_DTCTL_INSEL Get Value            */


/* DBSHDDTXED bitfield */
#define EPWM_REGS_DBSHDDTXED_RA_DTFED_DTFED_Pos    (16U)                                                                                 /*!< RA_DTFED_DTFED Postion   16         */ 
#define EPWM_REGS_DBSHDDTXED_RA_DTFED_DTFED_Msk    (0x3fffU << EPWM_REGS_DBSHDDTXED_RA_DTFED_DTFED_Pos)                                  /*!< RA_DTFED_DTFED Mask      0x3FFF0000 */
#define EPWM_REGS_DBSHDDTXED_RA_DTFED_DTFED_Set(x) (((uint32_t) (x) << EPWM_REGS_DBSHDDTXED_RA_DTFED_DTFED_Pos) & EPWM_REGS_DBSHDDTXED_RA_DTFED_DTFED_Msk) /*!< RA_DTFED_DTFED Set Value            */
#define EPWM_REGS_DBSHDDTXED_RA_DTFED_DTFED_Get(x) (((uint32_t) (x) & EPWM_REGS_DBSHDDTXED_RA_DTFED_DTFED_Msk) >> EPWM_REGS_DBSHDDTXED_RA_DTFED_DTFED_Pos) /*!< RA_DTFED_DTFED Get Value            */


#define EPWM_REGS_DBSHDDTXED_RA_DTRED_DTRED_Pos    (0U)                                                                                  /*!< RA_DTRED_DTRED Postion   0          */ 
#define EPWM_REGS_DBSHDDTXED_RA_DTRED_DTRED_Msk    (0x3fffU << EPWM_REGS_DBSHDDTXED_RA_DTRED_DTRED_Pos)                                  /*!< RA_DTRED_DTRED Mask      0x00003FFF */
#define EPWM_REGS_DBSHDDTXED_RA_DTRED_DTRED_Set(x) (((uint32_t) (x) << EPWM_REGS_DBSHDDTXED_RA_DTRED_DTRED_Pos) & EPWM_REGS_DBSHDDTXED_RA_DTRED_DTRED_Msk) /*!< RA_DTRED_DTRED Set Value            */
#define EPWM_REGS_DBSHDDTXED_RA_DTRED_DTRED_Get(x) (((uint32_t) (x) & EPWM_REGS_DBSHDDTXED_RA_DTRED_DTRED_Msk) >> EPWM_REGS_DBSHDDTXED_RA_DTRED_DTRED_Pos) /*!< RA_DTRED_DTRED Get Value            */


/* DBDITHER1 bitfield */
#define EPWM_REGS_DBDITHER1_RI_TCPRD_TCPRD_Pos    (0U)                                                                                  /*!< RI_TCPRD_TCPRD Postion   0          */ 
#define EPWM_REGS_DBDITHER1_RI_TCPRD_TCPRD_Msk    (0xffffU << EPWM_REGS_DBDITHER1_RI_TCPRD_TCPRD_Pos)                                   /*!< RI_TCPRD_TCPRD Mask      0x0000FFFF */
#define EPWM_REGS_DBDITHER1_RI_TCPRD_TCPRD_Set(x) (((uint32_t) (x) << EPWM_REGS_DBDITHER1_RI_TCPRD_TCPRD_Pos) & EPWM_REGS_DBDITHER1_RI_TCPRD_TCPRD_Msk) /*!< RI_TCPRD_TCPRD Set Value            */
#define EPWM_REGS_DBDITHER1_RI_TCPRD_TCPRD_Get(x) (((uint32_t) (x) & EPWM_REGS_DBDITHER1_RI_TCPRD_TCPRD_Msk) >> EPWM_REGS_DBDITHER1_RI_TCPRD_TCPRD_Pos) /*!< RI_TCPRD_TCPRD Get Value            */


/* DBDITHER2 bitfield */
#define EPWM_REGS_DBDITHER2_RI_CMPB_CMPB_Pos    (16U)                                                                                 /*!< RI_CMPB_CMPB Postion   16         */ 
#define EPWM_REGS_DBDITHER2_RI_CMPB_CMPB_Msk    (0xffffU << EPWM_REGS_DBDITHER2_RI_CMPB_CMPB_Pos)                                     /*!< RI_CMPB_CMPB Mask      0xFFFF0000 */
#define EPWM_REGS_DBDITHER2_RI_CMPB_CMPB_Set(x) (((uint32_t) (x) << EPWM_REGS_DBDITHER2_RI_CMPB_CMPB_Pos) & EPWM_REGS_DBDITHER2_RI_CMPB_CMPB_Msk) /*!< RI_CMPB_CMPB Set Value            */
#define EPWM_REGS_DBDITHER2_RI_CMPB_CMPB_Get(x) (((uint32_t) (x) & EPWM_REGS_DBDITHER2_RI_CMPB_CMPB_Msk) >> EPWM_REGS_DBDITHER2_RI_CMPB_CMPB_Pos) /*!< RI_CMPB_CMPB Get Value            */


#define EPWM_REGS_DBDITHER2_RI_CMPA_CMPA_Pos    (0U)                                                                                  /*!< RI_CMPA_CMPA Postion   0          */ 
#define EPWM_REGS_DBDITHER2_RI_CMPA_CMPA_Msk    (0xffffU << EPWM_REGS_DBDITHER2_RI_CMPA_CMPA_Pos)                                     /*!< RI_CMPA_CMPA Mask      0x0000FFFF */
#define EPWM_REGS_DBDITHER2_RI_CMPA_CMPA_Set(x) (((uint32_t) (x) << EPWM_REGS_DBDITHER2_RI_CMPA_CMPA_Pos) & EPWM_REGS_DBDITHER2_RI_CMPA_CMPA_Msk) /*!< RI_CMPA_CMPA Set Value            */
#define EPWM_REGS_DBDITHER2_RI_CMPA_CMPA_Get(x) (((uint32_t) (x) & EPWM_REGS_DBDITHER2_RI_CMPA_CMPA_Msk) >> EPWM_REGS_DBDITHER2_RI_CMPA_CMPA_Pos) /*!< RI_CMPA_CMPA Get Value            */


/* DBTC bitfield */
#define EPWM_REGS_DBTC_TCCTR_NEXT_Pos    (16U)                                                                                 /*!< TCCTR_NEXT Postion   16         */ 
#define EPWM_REGS_DBTC_TCCTR_NEXT_Msk    (0xffffU << EPWM_REGS_DBTC_TCCTR_NEXT_Pos)                                            /*!< TCCTR_NEXT Mask      0xFFFF0000 */
#define EPWM_REGS_DBTC_TCCTR_NEXT_Set(x) (((uint32_t) (x) << EPWM_REGS_DBTC_TCCTR_NEXT_Pos) & EPWM_REGS_DBTC_TCCTR_NEXT_Msk)   /*!< TCCTR_NEXT Set Value            */
#define EPWM_REGS_DBTC_TCCTR_NEXT_Get(x) (((uint32_t) (x) & EPWM_REGS_DBTC_TCCTR_NEXT_Msk) >> EPWM_REGS_DBTC_TCCTR_NEXT_Pos)   /*!< TCCTR_NEXT Get Value            */


#define EPWM_REGS_DBTC_TCCTR_PRE_Pos    (0U)                                                                                  /*!< TCCTR_PRE Postion   0          */ 
#define EPWM_REGS_DBTC_TCCTR_PRE_Msk    (0xffffU << EPWM_REGS_DBTC_TCCTR_PRE_Pos)                                             /*!< TCCTR_PRE Mask      0x0000FFFF */
#define EPWM_REGS_DBTC_TCCTR_PRE_Set(x) (((uint32_t) (x) << EPWM_REGS_DBTC_TCCTR_PRE_Pos) & EPWM_REGS_DBTC_TCCTR_PRE_Msk)     /*!< TCCTR_PRE Set Value            */
#define EPWM_REGS_DBTC_TCCTR_PRE_Get(x) (((uint32_t) (x) & EPWM_REGS_DBTC_TCCTR_PRE_Msk) >> EPWM_REGS_DBTC_TCCTR_PRE_Pos)     /*!< TCCTR_PRE Get Value            */


/* DBDT1 bitfield */
#define EPWM_REGS_DBDT1_CNT_F_S_Pos    (16U)                                                                                 /*!< CNT_F_S Postion   16         */ 
#define EPWM_REGS_DBDT1_CNT_F_S_Msk    (0x3fffU << EPWM_REGS_DBDT1_CNT_F_S_Pos)                                              /*!< CNT_F_S Mask      0x3FFF0000 */
#define EPWM_REGS_DBDT1_CNT_F_S_Set(x) (((uint32_t) (x) << EPWM_REGS_DBDT1_CNT_F_S_Pos) & EPWM_REGS_DBDT1_CNT_F_S_Msk)       /*!< CNT_F_S Set Value            */
#define EPWM_REGS_DBDT1_CNT_F_S_Get(x) (((uint32_t) (x) & EPWM_REGS_DBDT1_CNT_F_S_Msk) >> EPWM_REGS_DBDT1_CNT_F_S_Pos)       /*!< CNT_F_S Get Value            */


#define EPWM_REGS_DBDT1_CNT_R_S_Pos    (0U)                                                                                  /*!< CNT_R_S Postion   0          */ 
#define EPWM_REGS_DBDT1_CNT_R_S_Msk    (0x3fffU << EPWM_REGS_DBDT1_CNT_R_S_Pos)                                              /*!< CNT_R_S Mask      0x00003FFF */
#define EPWM_REGS_DBDT1_CNT_R_S_Set(x) (((uint32_t) (x) << EPWM_REGS_DBDT1_CNT_R_S_Pos) & EPWM_REGS_DBDT1_CNT_R_S_Msk)       /*!< CNT_R_S Set Value            */
#define EPWM_REGS_DBDT1_CNT_R_S_Get(x) (((uint32_t) (x) & EPWM_REGS_DBDT1_CNT_R_S_Msk) >> EPWM_REGS_DBDT1_CNT_R_S_Pos)       /*!< CNT_R_S Get Value            */


/* DBDT2 bitfield */
#define EPWM_REGS_DBDT2_CNT_R_NEG_Pos    (16U)                                                                                 /*!< CNT_R_NEG Postion   16         */ 
#define EPWM_REGS_DBDT2_CNT_R_NEG_Msk    (0x3fffU << EPWM_REGS_DBDT2_CNT_R_NEG_Pos)                                            /*!< CNT_R_NEG Mask      0x3FFF0000 */
#define EPWM_REGS_DBDT2_CNT_R_NEG_Set(x) (((uint32_t) (x) << EPWM_REGS_DBDT2_CNT_R_NEG_Pos) & EPWM_REGS_DBDT2_CNT_R_NEG_Msk)   /*!< CNT_R_NEG Set Value            */
#define EPWM_REGS_DBDT2_CNT_R_NEG_Get(x) (((uint32_t) (x) & EPWM_REGS_DBDT2_CNT_R_NEG_Msk) >> EPWM_REGS_DBDT2_CNT_R_NEG_Pos)   /*!< CNT_R_NEG Get Value            */


#define EPWM_REGS_DBDT2_CNT_R_POS_Pos    (0U)                                                                                  /*!< CNT_R_POS Postion   0          */ 
#define EPWM_REGS_DBDT2_CNT_R_POS_Msk    (0x3fffU << EPWM_REGS_DBDT2_CNT_R_POS_Pos)                                            /*!< CNT_R_POS Mask      0x00003FFF */
#define EPWM_REGS_DBDT2_CNT_R_POS_Set(x) (((uint32_t) (x) << EPWM_REGS_DBDT2_CNT_R_POS_Pos) & EPWM_REGS_DBDT2_CNT_R_POS_Msk)   /*!< CNT_R_POS Set Value            */
#define EPWM_REGS_DBDT2_CNT_R_POS_Get(x) (((uint32_t) (x) & EPWM_REGS_DBDT2_CNT_R_POS_Msk) >> EPWM_REGS_DBDT2_CNT_R_POS_Pos)   /*!< CNT_R_POS Get Value            */


/* DBDT3 bitfield */
#define EPWM_REGS_DBDT3_CNT_F_NEG_Pos    (16U)                                                                                 /*!< CNT_F_NEG Postion   16         */ 
#define EPWM_REGS_DBDT3_CNT_F_NEG_Msk    (0x3fffU << EPWM_REGS_DBDT3_CNT_F_NEG_Pos)                                            /*!< CNT_F_NEG Mask      0x3FFF0000 */
#define EPWM_REGS_DBDT3_CNT_F_NEG_Set(x) (((uint32_t) (x) << EPWM_REGS_DBDT3_CNT_F_NEG_Pos) & EPWM_REGS_DBDT3_CNT_F_NEG_Msk)   /*!< CNT_F_NEG Set Value            */
#define EPWM_REGS_DBDT3_CNT_F_NEG_Get(x) (((uint32_t) (x) & EPWM_REGS_DBDT3_CNT_F_NEG_Msk) >> EPWM_REGS_DBDT3_CNT_F_NEG_Pos)   /*!< CNT_F_NEG Get Value            */


#define EPWM_REGS_DBDT3_CNT_F_POS_Pos    (0U)                                                                                  /*!< CNT_F_POS Postion   0          */ 
#define EPWM_REGS_DBDT3_CNT_F_POS_Msk    (0x3fffU << EPWM_REGS_DBDT3_CNT_F_POS_Pos)                                            /*!< CNT_F_POS Mask      0x00003FFF */
#define EPWM_REGS_DBDT3_CNT_F_POS_Set(x) (((uint32_t) (x) << EPWM_REGS_DBDT3_CNT_F_POS_Pos) & EPWM_REGS_DBDT3_CNT_F_POS_Msk)   /*!< CNT_F_POS Set Value            */
#define EPWM_REGS_DBDT3_CNT_F_POS_Get(x) (((uint32_t) (x) & EPWM_REGS_DBDT3_CNT_F_POS_Msk) >> EPWM_REGS_DBDT3_CNT_F_POS_Pos)   /*!< CNT_F_POS Get Value            */


/* DBCHP1 bitfield */
#define EPWM_REGS_DBCHP1_CNT_PS_DUTY_Pos    (16U)                                                                                 /*!< CNT_PS_DUTY Postion   16         */ 
#define EPWM_REGS_DBCHP1_CNT_PS_DUTY_Msk    (0x3fU << EPWM_REGS_DBCHP1_CNT_PS_DUTY_Pos)                                           /*!< CNT_PS_DUTY Mask      0x003F0000 */
#define EPWM_REGS_DBCHP1_CNT_PS_DUTY_Set(x) (((uint32_t) (x) << EPWM_REGS_DBCHP1_CNT_PS_DUTY_Pos) & EPWM_REGS_DBCHP1_CNT_PS_DUTY_Msk) /*!< CNT_PS_DUTY Set Value            */
#define EPWM_REGS_DBCHP1_CNT_PS_DUTY_Get(x) (((uint32_t) (x) & EPWM_REGS_DBCHP1_CNT_PS_DUTY_Msk) >> EPWM_REGS_DBCHP1_CNT_PS_DUTY_Pos) /*!< CNT_PS_DUTY Get Value            */


#define EPWM_REGS_DBCHP1_CNT_PS_MAX_Pos    (0U)                                                                                  /*!< CNT_PS_MAX Postion   0          */ 
#define EPWM_REGS_DBCHP1_CNT_PS_MAX_Msk    (0x3fU << EPWM_REGS_DBCHP1_CNT_PS_MAX_Pos)                                            /*!< CNT_PS_MAX Mask      0x0000003F */
#define EPWM_REGS_DBCHP1_CNT_PS_MAX_Set(x) (((uint32_t) (x) << EPWM_REGS_DBCHP1_CNT_PS_MAX_Pos) & EPWM_REGS_DBCHP1_CNT_PS_MAX_Msk) /*!< CNT_PS_MAX Set Value            */
#define EPWM_REGS_DBCHP1_CNT_PS_MAX_Get(x) (((uint32_t) (x) & EPWM_REGS_DBCHP1_CNT_PS_MAX_Msk) >> EPWM_REGS_DBCHP1_CNT_PS_MAX_Pos) /*!< CNT_PS_MAX Get Value            */


/* DBCHP2 bitfield */
#define EPWM_REGS_DBCHP2_PS_CNT_Pos    (16U)                                                                                 /*!< PS_CNT Postion   16         */ 
#define EPWM_REGS_DBCHP2_PS_CNT_Msk    (0x3fU << EPWM_REGS_DBCHP2_PS_CNT_Pos)                                                /*!< PS_CNT Mask      0x003F0000 */
#define EPWM_REGS_DBCHP2_PS_CNT_Set(x) (((uint32_t) (x) << EPWM_REGS_DBCHP2_PS_CNT_Pos) & EPWM_REGS_DBCHP2_PS_CNT_Msk)       /*!< PS_CNT Set Value            */
#define EPWM_REGS_DBCHP2_PS_CNT_Get(x) (((uint32_t) (x) & EPWM_REGS_DBCHP2_PS_CNT_Msk) >> EPWM_REGS_DBCHP2_PS_CNT_Pos)       /*!< PS_CNT Get Value            */


#define EPWM_REGS_DBCHP2_PS_CNT_B_Pos    (8U)                                                                                  /*!< PS_CNT_B Postion   8          */ 
#define EPWM_REGS_DBCHP2_PS_CNT_B_Msk    (0x3fU << EPWM_REGS_DBCHP2_PS_CNT_B_Pos)                                              /*!< PS_CNT_B Mask      0x00003F00 */
#define EPWM_REGS_DBCHP2_PS_CNT_B_Set(x) (((uint32_t) (x) << EPWM_REGS_DBCHP2_PS_CNT_B_Pos) & EPWM_REGS_DBCHP2_PS_CNT_B_Msk)   /*!< PS_CNT_B Set Value            */
#define EPWM_REGS_DBCHP2_PS_CNT_B_Get(x) (((uint32_t) (x) & EPWM_REGS_DBCHP2_PS_CNT_B_Msk) >> EPWM_REGS_DBCHP2_PS_CNT_B_Pos)   /*!< PS_CNT_B Get Value            */


#define EPWM_REGS_DBCHP2_PS_CNT_A_Pos    (0U)                                                                                  /*!< PS_CNT_A Postion   0          */ 
#define EPWM_REGS_DBCHP2_PS_CNT_A_Msk    (0x3fU << EPWM_REGS_DBCHP2_PS_CNT_A_Pos)                                              /*!< PS_CNT_A Mask      0x0000003F */
#define EPWM_REGS_DBCHP2_PS_CNT_A_Set(x) (((uint32_t) (x) << EPWM_REGS_DBCHP2_PS_CNT_A_Pos) & EPWM_REGS_DBCHP2_PS_CNT_A_Msk)   /*!< PS_CNT_A Set Value            */
#define EPWM_REGS_DBCHP2_PS_CNT_A_Get(x) (((uint32_t) (x) & EPWM_REGS_DBCHP2_PS_CNT_A_Msk) >> EPWM_REGS_DBCHP2_PS_CNT_A_Pos)   /*!< PS_CNT_A Get Value            */


/* DBCHP3 bitfield */
#define EPWM_REGS_DBCHP3_OOFF_WIDTH_Pos    (16U)                                                                                 /*!< OOFF_WIDTH Postion   16         */ 
#define EPWM_REGS_DBCHP3_OOFF_WIDTH_Msk    (0x3fU << EPWM_REGS_DBCHP3_OOFF_WIDTH_Pos)                                            /*!< OOFF_WIDTH Mask      0x003F0000 */
#define EPWM_REGS_DBCHP3_OOFF_WIDTH_Set(x) (((uint32_t) (x) << EPWM_REGS_DBCHP3_OOFF_WIDTH_Pos) & EPWM_REGS_DBCHP3_OOFF_WIDTH_Msk) /*!< OOFF_WIDTH Set Value            */
#define EPWM_REGS_DBCHP3_OOFF_WIDTH_Get(x) (((uint32_t) (x) & EPWM_REGS_DBCHP3_OOFF_WIDTH_Msk) >> EPWM_REGS_DBCHP3_OOFF_WIDTH_Pos) /*!< OOFF_WIDTH Get Value            */


#define EPWM_REGS_DBCHP3_OOFF_CNT_B_Pos    (8U)                                                                                  /*!< OOFF_CNT_B Postion   8          */ 
#define EPWM_REGS_DBCHP3_OOFF_CNT_B_Msk    (0x3fU << EPWM_REGS_DBCHP3_OOFF_CNT_B_Pos)                                            /*!< OOFF_CNT_B Mask      0x00003F00 */
#define EPWM_REGS_DBCHP3_OOFF_CNT_B_Set(x) (((uint32_t) (x) << EPWM_REGS_DBCHP3_OOFF_CNT_B_Pos) & EPWM_REGS_DBCHP3_OOFF_CNT_B_Msk) /*!< OOFF_CNT_B Set Value            */
#define EPWM_REGS_DBCHP3_OOFF_CNT_B_Get(x) (((uint32_t) (x) & EPWM_REGS_DBCHP3_OOFF_CNT_B_Msk) >> EPWM_REGS_DBCHP3_OOFF_CNT_B_Pos) /*!< OOFF_CNT_B Get Value            */


#define EPWM_REGS_DBCHP3_OOFF_CNT_A_Pos    (0U)                                                                                  /*!< OOFF_CNT_A Postion   0          */ 
#define EPWM_REGS_DBCHP3_OOFF_CNT_A_Msk    (0x3fU << EPWM_REGS_DBCHP3_OOFF_CNT_A_Pos)                                            /*!< OOFF_CNT_A Mask      0x0000003F */
#define EPWM_REGS_DBCHP3_OOFF_CNT_A_Set(x) (((uint32_t) (x) << EPWM_REGS_DBCHP3_OOFF_CNT_A_Pos) & EPWM_REGS_DBCHP3_OOFF_CNT_A_Msk) /*!< OOFF_CNT_A Set Value            */
#define EPWM_REGS_DBCHP3_OOFF_CNT_A_Get(x) (((uint32_t) (x) & EPWM_REGS_DBCHP3_OOFF_CNT_A_Msk) >> EPWM_REGS_DBCHP3_OOFF_CNT_A_Pos) /*!< OOFF_CNT_A Get Value            */


/* DBDP1 bitfield */
#define EPWM_REGS_DBDP1_WINDOW_CNT_Pos    (16U)                                                                                 /*!< WINDOW_CNT Postion   16         */ 
#define EPWM_REGS_DBDP1_WINDOW_CNT_Msk    (0xffffU << EPWM_REGS_DBDP1_WINDOW_CNT_Pos)                                           /*!< WINDOW_CNT Mask      0xFFFF0000 */
#define EPWM_REGS_DBDP1_WINDOW_CNT_Set(x) (((uint32_t) (x) << EPWM_REGS_DBDP1_WINDOW_CNT_Pos) & EPWM_REGS_DBDP1_WINDOW_CNT_Msk) /*!< WINDOW_CNT Set Value            */
#define EPWM_REGS_DBDP1_WINDOW_CNT_Get(x) (((uint32_t) (x) & EPWM_REGS_DBDP1_WINDOW_CNT_Msk) >> EPWM_REGS_DBDP1_WINDOW_CNT_Pos) /*!< WINDOW_CNT Get Value            */


#define EPWM_REGS_DBDP1_OFFSET_CNT_Pos    (0U)                                                                                  /*!< OFFSET_CNT Postion   0          */ 
#define EPWM_REGS_DBDP1_OFFSET_CNT_Msk    (0xffffU << EPWM_REGS_DBDP1_OFFSET_CNT_Pos)                                           /*!< OFFSET_CNT Mask      0x0000FFFF */
#define EPWM_REGS_DBDP1_OFFSET_CNT_Set(x) (((uint32_t) (x) << EPWM_REGS_DBDP1_OFFSET_CNT_Pos) & EPWM_REGS_DBDP1_OFFSET_CNT_Msk) /*!< OFFSET_CNT Set Value            */
#define EPWM_REGS_DBDP1_OFFSET_CNT_Get(x) (((uint32_t) (x) & EPWM_REGS_DBDP1_OFFSET_CNT_Msk) >> EPWM_REGS_DBDP1_OFFSET_CNT_Pos) /*!< OFFSET_CNT Get Value            */


/* DBDP2 bitfield */
#define EPWM_REGS_DBDP2_VALLEY_CNT_REG_Pos    (16U)                                                                                 /*!< VALLEY_CNT_REG Postion   16         */ 
#define EPWM_REGS_DBDP2_VALLEY_CNT_REG_Msk    (0xffffU << EPWM_REGS_DBDP2_VALLEY_CNT_REG_Pos)                                       /*!< VALLEY_CNT_REG Mask      0xFFFF0000 */
#define EPWM_REGS_DBDP2_VALLEY_CNT_REG_Set(x) (((uint32_t) (x) << EPWM_REGS_DBDP2_VALLEY_CNT_REG_Pos) & EPWM_REGS_DBDP2_VALLEY_CNT_REG_Msk) /*!< VALLEY_CNT_REG Set Value            */
#define EPWM_REGS_DBDP2_VALLEY_CNT_REG_Get(x) (((uint32_t) (x) & EPWM_REGS_DBDP2_VALLEY_CNT_REG_Msk) >> EPWM_REGS_DBDP2_VALLEY_CNT_REG_Pos) /*!< VALLEY_CNT_REG Get Value            */


#define EPWM_REGS_DBDP2_VALLEY_CNT_Pos    (0U)                                                                                  /*!< VALLEY_CNT Postion   0          */ 
#define EPWM_REGS_DBDP2_VALLEY_CNT_Msk    (0xffffU << EPWM_REGS_DBDP2_VALLEY_CNT_Pos)                                           /*!< VALLEY_CNT Mask      0x0000FFFF */
#define EPWM_REGS_DBDP2_VALLEY_CNT_Set(x) (((uint32_t) (x) << EPWM_REGS_DBDP2_VALLEY_CNT_Pos) & EPWM_REGS_DBDP2_VALLEY_CNT_Msk) /*!< VALLEY_CNT Set Value            */
#define EPWM_REGS_DBDP2_VALLEY_CNT_Get(x) (((uint32_t) (x) & EPWM_REGS_DBDP2_VALLEY_CNT_Msk) >> EPWM_REGS_DBDP2_VALLEY_CNT_Pos) /*!< VALLEY_CNT Get Value            */


/* DBDP3 bitfield */
#define EPWM_REGS_DBDP3_HWVDELAY_VALUE_Pos    (16U)                                                                                 /*!< HWVDELAY_VALUE Postion   16         */ 
#define EPWM_REGS_DBDP3_HWVDELAY_VALUE_Msk    (0xffffU << EPWM_REGS_DBDP3_HWVDELAY_VALUE_Pos)                                       /*!< HWVDELAY_VALUE Mask      0xFFFF0000 */
#define EPWM_REGS_DBDP3_HWVDELAY_VALUE_Set(x) (((uint32_t) (x) << EPWM_REGS_DBDP3_HWVDELAY_VALUE_Pos) & EPWM_REGS_DBDP3_HWVDELAY_VALUE_Msk) /*!< HWVDELAY_VALUE Set Value            */
#define EPWM_REGS_DBDP3_HWVDELAY_VALUE_Get(x) (((uint32_t) (x) & EPWM_REGS_DBDP3_HWVDELAY_VALUE_Msk) >> EPWM_REGS_DBDP3_HWVDELAY_VALUE_Pos) /*!< HWVDELAY_VALUE Get Value            */


#define EPWM_REGS_DBDP3_DELAY_CNT_Pos    (0U)                                                                                  /*!< DELAY_CNT Postion   0          */ 
#define EPWM_REGS_DBDP3_DELAY_CNT_Msk    (0xffffU << EPWM_REGS_DBDP3_DELAY_CNT_Pos)                                            /*!< DELAY_CNT Mask      0x0000FFFF */
#define EPWM_REGS_DBDP3_DELAY_CNT_Set(x) (((uint32_t) (x) << EPWM_REGS_DBDP3_DELAY_CNT_Pos) & EPWM_REGS_DBDP3_DELAY_CNT_Msk)   /*!< DELAY_CNT Set Value            */
#define EPWM_REGS_DBDP3_DELAY_CNT_Get(x) (((uint32_t) (x) & EPWM_REGS_DBDP3_DELAY_CNT_Msk) >> EPWM_REGS_DBDP3_DELAY_CNT_Pos)   /*!< DELAY_CNT Get Value            */


/* DBDP4 bitfield */
#define EPWM_REGS_DBDP4_HWVDELAY_VALUE_TMP_Pos    (0U)                                                                                  /*!< HWVDELAY_VALUE_TMP Postion   0          */ 
#define EPWM_REGS_DBDP4_HWVDELAY_VALUE_TMP_Msk    (0x1ffffU << EPWM_REGS_DBDP4_HWVDELAY_VALUE_TMP_Pos)                                  /*!< HWVDELAY_VALUE_TMP Mask      0x0001FFFF */
#define EPWM_REGS_DBDP4_HWVDELAY_VALUE_TMP_Set(x) (((uint32_t) (x) << EPWM_REGS_DBDP4_HWVDELAY_VALUE_TMP_Pos) & EPWM_REGS_DBDP4_HWVDELAY_VALUE_TMP_Msk) /*!< HWVDELAY_VALUE_TMP Set Value            */
#define EPWM_REGS_DBDP4_HWVDELAY_VALUE_TMP_Get(x) (((uint32_t) (x) & EPWM_REGS_DBDP4_HWVDELAY_VALUE_TMP_Msk) >> EPWM_REGS_DBDP4_HWVDELAY_VALUE_TMP_Pos) /*!< HWVDELAY_VALUE_TMP Get Value            */


/* DBDP5 bitfield */
#define EPWM_REGS_DBDP5_TCCTR_ACTIVE_Pos    (16U)                                                                                 /*!< TCCTR_ACTIVE Postion   16         */ 
#define EPWM_REGS_DBDP5_TCCTR_ACTIVE_Msk    (0xffffU << EPWM_REGS_DBDP5_TCCTR_ACTIVE_Pos)                                         /*!< TCCTR_ACTIVE Mask      0xFFFF0000 */
#define EPWM_REGS_DBDP5_TCCTR_ACTIVE_Set(x) (((uint32_t) (x) << EPWM_REGS_DBDP5_TCCTR_ACTIVE_Pos) & EPWM_REGS_DBDP5_TCCTR_ACTIVE_Msk) /*!< TCCTR_ACTIVE Set Value            */
#define EPWM_REGS_DBDP5_TCCTR_ACTIVE_Get(x) (((uint32_t) (x) & EPWM_REGS_DBDP5_TCCTR_ACTIVE_Msk) >> EPWM_REGS_DBDP5_TCCTR_ACTIVE_Pos) /*!< TCCTR_ACTIVE Get Value            */


#define EPWM_REGS_DBDP5_TCCTR_SHADOW_Pos    (0U)                                                                                  /*!< TCCTR_SHADOW Postion   0          */ 
#define EPWM_REGS_DBDP5_TCCTR_SHADOW_Msk    (0xffffU << EPWM_REGS_DBDP5_TCCTR_SHADOW_Pos)                                         /*!< TCCTR_SHADOW Mask      0x0000FFFF */
#define EPWM_REGS_DBDP5_TCCTR_SHADOW_Set(x) (((uint32_t) (x) << EPWM_REGS_DBDP5_TCCTR_SHADOW_Pos) & EPWM_REGS_DBDP5_TCCTR_SHADOW_Msk) /*!< TCCTR_SHADOW Set Value            */
#define EPWM_REGS_DBDP5_TCCTR_SHADOW_Get(x) (((uint32_t) (x) & EPWM_REGS_DBDP5_TCCTR_SHADOW_Msk) >> EPWM_REGS_DBDP5_TCCTR_SHADOW_Pos) /*!< TCCTR_SHADOW Get Value            */


/* DBEH bitfield */
#define EPWM_REGS_DBEH_INT_CNT_Pos    (16U)                                                                                 /*!< INT_CNT Postion   16         */ 
#define EPWM_REGS_DBEH_INT_CNT_Msk    (0xfU << EPWM_REGS_DBEH_INT_CNT_Pos)                                                  /*!< INT_CNT Mask      0x000F0000 */
#define EPWM_REGS_DBEH_INT_CNT_Set(x) (((uint32_t) (x) << EPWM_REGS_DBEH_INT_CNT_Pos) & EPWM_REGS_DBEH_INT_CNT_Msk)         /*!< INT_CNT Set Value            */
#define EPWM_REGS_DBEH_INT_CNT_Get(x) (((uint32_t) (x) & EPWM_REGS_DBEH_INT_CNT_Msk) >> EPWM_REGS_DBEH_INT_CNT_Pos)         /*!< INT_CNT Get Value            */


#define EPWM_REGS_DBEH_SOCB_CNT_Pos    (8U)                                                                                  /*!< SOCB_CNT Postion   8          */ 
#define EPWM_REGS_DBEH_SOCB_CNT_Msk    (0xfU << EPWM_REGS_DBEH_SOCB_CNT_Pos)                                                 /*!< SOCB_CNT Mask      0x00000F00 */
#define EPWM_REGS_DBEH_SOCB_CNT_Set(x) (((uint32_t) (x) << EPWM_REGS_DBEH_SOCB_CNT_Pos) & EPWM_REGS_DBEH_SOCB_CNT_Msk)       /*!< SOCB_CNT Set Value            */
#define EPWM_REGS_DBEH_SOCB_CNT_Get(x) (((uint32_t) (x) & EPWM_REGS_DBEH_SOCB_CNT_Msk) >> EPWM_REGS_DBEH_SOCB_CNT_Pos)       /*!< SOCB_CNT Get Value            */


#define EPWM_REGS_DBEH_SOCA_CNT_Pos    (0U)                                                                                  /*!< SOCA_CNT Postion   0          */ 
#define EPWM_REGS_DBEH_SOCA_CNT_Msk    (0xfU << EPWM_REGS_DBEH_SOCA_CNT_Pos)                                                 /*!< SOCA_CNT Mask      0x0000000F */
#define EPWM_REGS_DBEH_SOCA_CNT_Set(x) (((uint32_t) (x) << EPWM_REGS_DBEH_SOCA_CNT_Pos) & EPWM_REGS_DBEH_SOCA_CNT_Msk)       /*!< SOCA_CNT Set Value            */
#define EPWM_REGS_DBEH_SOCA_CNT_Get(x) (((uint32_t) (x) & EPWM_REGS_DBEH_SOCA_CNT_Msk) >> EPWM_REGS_DBEH_SOCA_CNT_Pos)       /*!< SOCA_CNT Get Value            */


/* DBER1 bitfield */
#define EPWM_REGS_DBER1_CNT_APUDLY_Pos    (16U)                                                                                 /*!< CNT_APUDLY Postion   16         */ 
#define EPWM_REGS_DBER1_CNT_APUDLY_Msk    (0xffffU << EPWM_REGS_DBER1_CNT_APUDLY_Pos)                                           /*!< CNT_APUDLY Mask      0xFFFF0000 */
#define EPWM_REGS_DBER1_CNT_APUDLY_Set(x) (((uint32_t) (x) << EPWM_REGS_DBER1_CNT_APUDLY_Pos) & EPWM_REGS_DBER1_CNT_APUDLY_Msk) /*!< CNT_APUDLY Set Value            */
#define EPWM_REGS_DBER1_CNT_APUDLY_Get(x) (((uint32_t) (x) & EPWM_REGS_DBER1_CNT_APUDLY_Msk) >> EPWM_REGS_DBER1_CNT_APUDLY_Pos) /*!< CNT_APUDLY Get Value            */


#define EPWM_REGS_DBER1_CNT_AVALDLY_Pos    (0U)                                                                                  /*!< CNT_AVALDLY Postion   0          */ 
#define EPWM_REGS_DBER1_CNT_AVALDLY_Msk    (0xffffU << EPWM_REGS_DBER1_CNT_AVALDLY_Pos)                                          /*!< CNT_AVALDLY Mask      0x0000FFFF */
#define EPWM_REGS_DBER1_CNT_AVALDLY_Set(x) (((uint32_t) (x) << EPWM_REGS_DBER1_CNT_AVALDLY_Pos) & EPWM_REGS_DBER1_CNT_AVALDLY_Msk) /*!< CNT_AVALDLY Set Value            */
#define EPWM_REGS_DBER1_CNT_AVALDLY_Get(x) (((uint32_t) (x) & EPWM_REGS_DBER1_CNT_AVALDLY_Msk) >> EPWM_REGS_DBER1_CNT_AVALDLY_Pos) /*!< CNT_AVALDLY Get Value            */


/* DBER2 bitfield */
#define EPWM_REGS_DBER2_CNT_BPUDLY_Pos    (16U)                                                                                 /*!< CNT_BPUDLY Postion   16         */ 
#define EPWM_REGS_DBER2_CNT_BPUDLY_Msk    (0xffffU << EPWM_REGS_DBER2_CNT_BPUDLY_Pos)                                           /*!< CNT_BPUDLY Mask      0xFFFF0000 */
#define EPWM_REGS_DBER2_CNT_BPUDLY_Set(x) (((uint32_t) (x) << EPWM_REGS_DBER2_CNT_BPUDLY_Pos) & EPWM_REGS_DBER2_CNT_BPUDLY_Msk) /*!< CNT_BPUDLY Set Value            */
#define EPWM_REGS_DBER2_CNT_BPUDLY_Get(x) (((uint32_t) (x) & EPWM_REGS_DBER2_CNT_BPUDLY_Msk) >> EPWM_REGS_DBER2_CNT_BPUDLY_Pos) /*!< CNT_BPUDLY Get Value            */


#define EPWM_REGS_DBER2_CNT_BVALDLY_Pos    (0U)                                                                                  /*!< CNT_BVALDLY Postion   0          */ 
#define EPWM_REGS_DBER2_CNT_BVALDLY_Msk    (0xffffU << EPWM_REGS_DBER2_CNT_BVALDLY_Pos)                                          /*!< CNT_BVALDLY Mask      0x0000FFFF */
#define EPWM_REGS_DBER2_CNT_BVALDLY_Set(x) (((uint32_t) (x) << EPWM_REGS_DBER2_CNT_BVALDLY_Pos) & EPWM_REGS_DBER2_CNT_BVALDLY_Msk) /*!< CNT_BVALDLY Set Value            */
#define EPWM_REGS_DBER2_CNT_BVALDLY_Get(x) (((uint32_t) (x) & EPWM_REGS_DBER2_CNT_BVALDLY_Msk) >> EPWM_REGS_DBER2_CNT_BVALDLY_Pos) /*!< CNT_BVALDLY Get Value            */


/* DBPORTSEL1 bitfield */
#define EPWM_REGS_DBPORTSEL1_DBGWG_Pos    (24U)                                                                                 /*!< DBGWG Postion   24         */ 
#define EPWM_REGS_DBPORTSEL1_DBGWG_Msk    (0x1fU << EPWM_REGS_DBPORTSEL1_DBGWG_Pos)                                             /*!< DBGWG Mask      0x1F000000 */
#define EPWM_REGS_DBPORTSEL1_DBGWG_Set(x) (((uint32_t) (x) << EPWM_REGS_DBPORTSEL1_DBGWG_Pos) & EPWM_REGS_DBPORTSEL1_DBGWG_Msk) /*!< DBGWG Set Value            */
#define EPWM_REGS_DBPORTSEL1_DBGWG_Get(x) (((uint32_t) (x) & EPWM_REGS_DBPORTSEL1_DBGWG_Msk) >> EPWM_REGS_DBPORTSEL1_DBGWG_Pos) /*!< DBGWG Get Value            */


#define EPWM_REGS_DBPORTSEL1_DBGTC_Pos    (16U)                                                                                 /*!< DBGTC Postion   16         */ 
#define EPWM_REGS_DBPORTSEL1_DBGTC_Msk    (0x1fU << EPWM_REGS_DBPORTSEL1_DBGTC_Pos)                                             /*!< DBGTC Mask      0x001F0000 */
#define EPWM_REGS_DBPORTSEL1_DBGTC_Set(x) (((uint32_t) (x) << EPWM_REGS_DBPORTSEL1_DBGTC_Pos) & EPWM_REGS_DBPORTSEL1_DBGTC_Msk) /*!< DBGTC Set Value            */
#define EPWM_REGS_DBPORTSEL1_DBGTC_Get(x) (((uint32_t) (x) & EPWM_REGS_DBPORTSEL1_DBGTC_Msk) >> EPWM_REGS_DBPORTSEL1_DBGTC_Pos) /*!< DBGTC Get Value            */


#define EPWM_REGS_DBPORTSEL1_DBGSHDREG_Pos    (8U)                                                                                  /*!< DBGSHDREG Postion   8          */ 
#define EPWM_REGS_DBPORTSEL1_DBGSHDREG_Msk    (0x1fU << EPWM_REGS_DBPORTSEL1_DBGSHDREG_Pos)                                         /*!< DBGSHDREG Mask      0x00001F00 */
#define EPWM_REGS_DBPORTSEL1_DBGSHDREG_Set(x) (((uint32_t) (x) << EPWM_REGS_DBPORTSEL1_DBGSHDREG_Pos) & EPWM_REGS_DBPORTSEL1_DBGSHDREG_Msk) /*!< DBGSHDREG Set Value            */
#define EPWM_REGS_DBPORTSEL1_DBGSHDREG_Get(x) (((uint32_t) (x) & EPWM_REGS_DBPORTSEL1_DBGSHDREG_Msk) >> EPWM_REGS_DBPORTSEL1_DBGSHDREG_Pos) /*!< DBGSHDREG Get Value            */


#define EPWM_REGS_DBPORTSEL1_DBGSYNCSEL_Pos    (0U)                                                                                  /*!< DBGSYNCSEL Postion   0          */ 
#define EPWM_REGS_DBPORTSEL1_DBGSYNCSEL_Msk    (0x1fU << EPWM_REGS_DBPORTSEL1_DBGSYNCSEL_Pos)                                        /*!< DBGSYNCSEL Mask      0x0000001F */
#define EPWM_REGS_DBPORTSEL1_DBGSYNCSEL_Set(x) (((uint32_t) (x) << EPWM_REGS_DBPORTSEL1_DBGSYNCSEL_Pos) & EPWM_REGS_DBPORTSEL1_DBGSYNCSEL_Msk) /*!< DBGSYNCSEL Set Value            */
#define EPWM_REGS_DBPORTSEL1_DBGSYNCSEL_Get(x) (((uint32_t) (x) & EPWM_REGS_DBPORTSEL1_DBGSYNCSEL_Msk) >> EPWM_REGS_DBPORTSEL1_DBGSYNCSEL_Pos) /*!< DBGSYNCSEL Get Value            */


/* DBPORTSEL2 bitfield */
#define EPWM_REGS_DBPORTSEL2_DBGET_Pos    (24U)                                                                                 /*!< DBGET Postion   24         */ 
#define EPWM_REGS_DBPORTSEL2_DBGET_Msk    (0x1fU << EPWM_REGS_DBPORTSEL2_DBGET_Pos)                                             /*!< DBGET Mask      0x1F000000 */
#define EPWM_REGS_DBPORTSEL2_DBGET_Set(x) (((uint32_t) (x) << EPWM_REGS_DBPORTSEL2_DBGET_Pos) & EPWM_REGS_DBPORTSEL2_DBGET_Msk) /*!< DBGET Set Value            */
#define EPWM_REGS_DBPORTSEL2_DBGET_Get(x) (((uint32_t) (x) & EPWM_REGS_DBPORTSEL2_DBGET_Msk) >> EPWM_REGS_DBPORTSEL2_DBGET_Pos) /*!< DBGET Get Value            */


#define EPWM_REGS_DBPORTSEL2_DBGDP_Pos    (16U)                                                                                 /*!< DBGDP Postion   16         */ 
#define EPWM_REGS_DBPORTSEL2_DBGDP_Msk    (0x1fU << EPWM_REGS_DBPORTSEL2_DBGDP_Pos)                                             /*!< DBGDP Mask      0x001F0000 */
#define EPWM_REGS_DBPORTSEL2_DBGDP_Set(x) (((uint32_t) (x) << EPWM_REGS_DBPORTSEL2_DBGDP_Pos) & EPWM_REGS_DBPORTSEL2_DBGDP_Msk) /*!< DBGDP Set Value            */
#define EPWM_REGS_DBPORTSEL2_DBGDP_Get(x) (((uint32_t) (x) & EPWM_REGS_DBPORTSEL2_DBGDP_Msk) >> EPWM_REGS_DBPORTSEL2_DBGDP_Pos) /*!< DBGDP Get Value            */


#define EPWM_REGS_DBPORTSEL2_DBGPC_Pos    (8U)                                                                                  /*!< DBGPC Postion   8          */ 
#define EPWM_REGS_DBPORTSEL2_DBGPC_Msk    (0x1fU << EPWM_REGS_DBPORTSEL2_DBGPC_Pos)                                             /*!< DBGPC Mask      0x00001F00 */
#define EPWM_REGS_DBPORTSEL2_DBGPC_Set(x) (((uint32_t) (x) << EPWM_REGS_DBPORTSEL2_DBGPC_Pos) & EPWM_REGS_DBPORTSEL2_DBGPC_Msk) /*!< DBGPC Set Value            */
#define EPWM_REGS_DBPORTSEL2_DBGPC_Get(x) (((uint32_t) (x) & EPWM_REGS_DBPORTSEL2_DBGPC_Msk) >> EPWM_REGS_DBPORTSEL2_DBGPC_Pos) /*!< DBGPC Get Value            */


#define EPWM_REGS_DBPORTSEL2_DBGDT_Pos    (0U)                                                                                  /*!< DBGDT Postion   0          */ 
#define EPWM_REGS_DBPORTSEL2_DBGDT_Msk    (0x1fU << EPWM_REGS_DBPORTSEL2_DBGDT_Pos)                                             /*!< DBGDT Mask      0x0000001F */
#define EPWM_REGS_DBPORTSEL2_DBGDT_Set(x) (((uint32_t) (x) << EPWM_REGS_DBPORTSEL2_DBGDT_Pos) & EPWM_REGS_DBPORTSEL2_DBGDT_Msk) /*!< DBGDT Set Value            */
#define EPWM_REGS_DBPORTSEL2_DBGDT_Get(x) (((uint32_t) (x) & EPWM_REGS_DBPORTSEL2_DBGDT_Msk) >> EPWM_REGS_DBPORTSEL2_DBGDT_Pos) /*!< DBGDT Get Value            */


/* DBPORTSEL3 bitfield */
#define EPWM_REGS_DBPORTSEL3_DBGSUB_Pos    (16U)                                                                                 /*!< DBGSUB Postion   16         */ 
#define EPWM_REGS_DBPORTSEL3_DBGSUB_Msk    (0x1fU << EPWM_REGS_DBPORTSEL3_DBGSUB_Pos)                                            /*!< DBGSUB Mask      0x001F0000 */
#define EPWM_REGS_DBPORTSEL3_DBGSUB_Set(x) (((uint32_t) (x) << EPWM_REGS_DBPORTSEL3_DBGSUB_Pos) & EPWM_REGS_DBPORTSEL3_DBGSUB_Msk) /*!< DBGSUB Set Value            */
#define EPWM_REGS_DBPORTSEL3_DBGSUB_Get(x) (((uint32_t) (x) & EPWM_REGS_DBPORTSEL3_DBGSUB_Msk) >> EPWM_REGS_DBPORTSEL3_DBGSUB_Pos) /*!< DBGSUB Get Value            */


#define EPWM_REGS_DBPORTSEL3_DBGER_Pos    (0U)                                                                                  /*!< DBGER Postion   0          */ 
#define EPWM_REGS_DBPORTSEL3_DBGER_Msk    (0x1fU << EPWM_REGS_DBPORTSEL3_DBGER_Pos)                                             /*!< DBGER Mask      0x0000001F */
#define EPWM_REGS_DBPORTSEL3_DBGER_Set(x) (((uint32_t) (x) << EPWM_REGS_DBPORTSEL3_DBGER_Pos) & EPWM_REGS_DBPORTSEL3_DBGER_Msk) /*!< DBGER Set Value            */
#define EPWM_REGS_DBPORTSEL3_DBGER_Get(x) (((uint32_t) (x) & EPWM_REGS_DBPORTSEL3_DBGER_Msk) >> EPWM_REGS_DBPORTSEL3_DBGER_Pos) /*!< DBGER Get Value            */


/*!
 * @}
 */


/*!
 * @}
 */ /* end of HS32F7D377_EPWM_REGISTER */

#endif /* HS32F7D377_EPWM_H */
