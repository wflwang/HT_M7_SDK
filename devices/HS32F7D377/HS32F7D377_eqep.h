/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*!
 * \file   HS32F7D377_eqep.h
 * \brief  HS32F7D377 EQEP register file
 * \version Windows demo, not used svn
 */

#ifndef HS32F7D377_EQEP_H
#define HS32F7D377_EQEP_H

/*!
 * \addtogroup   HS32F7D377_EQEP_REGISTER HS32F7D377 EQEP Register
 * \ingroup HS32F7D377_REGISTER
 *
 * \brief  EQEP register layout, bitfield and address definitions
 *
 * @{
 */

/*!
 * \name EQEP Register Layout
 *
 *
 * @{
 */

/*! \brief EQEP register layout */
/*! \brief EQEP_REGS register */
typedef struct {
        union
        {
           __IOM uint32_t QPOSCNT;  /*!< 0x00000000 */ 
           
           struct
           {
              __IOM  uint32_t QPOSCNT                   : 32;     /*!< [31:0] : Position Counter                                                <br>  This 32-bit position counter register counts up/down on every eQEP pulse based on direction input. */
           } QPOSCNTb;
        };

        union
        {
           __IOM uint32_t QPOSINIT;  /*!< 0x00000004 */ 
           
           struct
           {
              __IOM uint32_t QPOSINIT                  : 32;     /*!< [31:0] : Position Counter Init                                           <br>  This register contains the position value that is used to initialize the position counter based on external strobe or index event. */
           } QPOSINITb;
        };

        union
        {
           __IOM uint32_t QPOSMAX;  /*!< 0x00000008 */ 
           
           struct
           {
              __IOM uint32_t QPOSMAX                   : 32;     /*!< [31:0] : Maximum Position Count                                          <br>  This register contains the maximum position counter value. */
           } QPOSMAXb;
        };

        union
        {
           __IOM uint32_t QPOSCMP;  /*!< 0x0000000c */ 
           
           struct
           {
              __IOM uint32_t QPOSCMP                   : 32;     /*!< [31:0] : Position Compare                                                <br>  The position-compare value in this register is compared with the position counter (QPOSCNT) to generate sync output and/or interrupt on compare match. */
           } QPOSCMPb;
        };

        union
        {
           __IM uint32_t QPOSILAT;  /*!< 0x00000010 */ 
           
           struct
           {
              __IM  uint32_t QPOSILAT                  : 32;     /*!< [31:0] : Index Position Latch                                            <br>  The position-counter value is latched into this register on an index event as defined by the QEPCTL[IEL] bits. */
           } QPOSILATb;
        };

        union
        {
           __IM uint32_t QPOSSLAT;  /*!< 0x00000014 */ 
           
           struct
           {
              __IM  uint32_t QPOSSLAT                  : 32;     /*!< [31:0] : Strobe Position Latch                                           <br>  The position-counter value is latched into this register on a strobe event as defined by the QEPCTL[SEL] bits. */
           } QPOSSLATb;
        };

        union
        {
           __IM uint32_t QPOSLAT;  /*!< 0x00000018 */ 
           
           struct
           {
              __IM  uint32_t QPOSLAT                   : 32;     /*!< [31:0] : Position Latch                                                  <br>  The position-counter value is latched into this register on a unit time out event. */
           } QPOSLATb;
        };

        union
        {
           __IOM uint32_t QUTMR;  /*!< 0x0000001c */ 
           
           struct
           {
              __IOM  uint32_t QUTMR                     : 32;     /*!< [31:0] : QEP Unit Timer                                                  <br>  This register acts as time base for unit time event generation. */
           } QUTMRb;
        };

        union
        {
           __IOM uint32_t QUPRD;  /*!< 0x00000020 */ 
           
           struct
           {
              __IOM uint32_t QUPRD                     : 32;     /*!< [31:0] : QEP Unit Period                                                 <br>  This register contains the period count for the unit timer to generate periodic unit time events. */
           } QUPRDb;
        };

        union
        {
           __IOM uint16_t QWDTMR;  /*!< 0x00000024 */ 
           
           struct
           {
              __IOM  uint16_t QWDTMR                    : 16;     /*!< [15:0] : QEP Watchdog Timer                                              <br>  This register acts as time base for the watchdog to detect motor stalls. */
           } QWDTMRb;
        };

        union
        {
           __IOM uint16_t QWDPRD;  /*!< 0x00000026 */ 
           
           struct
           {
              __IOM uint16_t QWDPRD                    : 16;     /*!< [15:0] : QEP Watchdog Period                                             <br>  This register contains the time-out count for the eQEP peripheral watch dog timer. */
           } QWDPRDb;
        };

        union
        {
           __IOM uint16_t QDECCTL;  /*!< 0x00000028 */ 
           
           struct
           {
              __IOM uint16_t QIDIRE                    : 1 ;     /*!< [0:0] : 0 - Compatible mode, Behavior same as existing devices          <br>  1 - Enhancement for Direction change during Index will be enabled<br>  Reset type: SYSRSn                                              <br>. */
                    uint16_t RSV_0                     : 4 ;     /*!< [4:1] : reserved. */
              __IOM uint16_t QSP                       : 1 ;     /*!< [5:5] : QEPS input polarity                                             <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No effect                                            <br>  1h (R/W) = Negates QEPS input                                   <br>. */
              __IOM uint16_t QIP                       : 1 ;     /*!< [6:6] : QEPI input polarity                                             <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No effect                                            <br>  1h (R/W) = Negates QEPI input                                   <br>. */
              __IOM uint16_t QBP                       : 1 ;     /*!< [7:7] : QEPB input polarity                                             <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No effect                                            <br>  1h (R/W) = Negates QEPB input                                   <br>. */
              __IOM uint16_t QAP                       : 1 ;     /*!< [8:8] : QEPA input polarity                                             <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No effect                                            <br>  1h (R/W) = Negates QEPA input                                   <br>. */
              __IOM uint16_t IGATE                     : 1 ;     /*!< [9:9] : Index pulse gating option                                       <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = Disable gating of Index pulse                        <br>  1h (R/W) = Gate the index pin with strobe                       <br>. */
              __IOM uint16_t SWAP                      : 1 ;     /*!< [10:10] : CLK/DIR Signal Source for Position Counter                      <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = Quadrature-clock inputs are not swapped              <br>  1h (R/W) = Quadrature-clock inputs are swapped                  <br>. */
              __IOM uint16_t XCR                       : 1 ;     /*!< [11:11] : External Clock Rate                                             <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = 2x resolution: Count the rising/falling edge         <br>  1h (R/W) = 1x resolution: Count the rising edge only            <br>. */
              __IOM uint16_t SPSEL                     : 1 ;     /*!< [12:12] : Sync output pin selection                                       <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = Index pin is used for sync output                    <br>  1h (R/W) = Strobe pin is used for sync output                   <br>. */
              __IOM uint16_t SOEN                      : 1 ;     /*!< [13:13] : Sync output-enable                                              <br>  0h (R/W) = Disable position-compare sync output                 <br>  1h (R/W) = Enable position-compare sync output                  <br>. */
              __IOM uint16_t QSRC                      : 2 ;     /*!< [15:14] : Position-counter source selection                               <br>  Reset type: SYSRSn                                              <br>. */
           } QDECCTLb;
        };

        union
        {
           __IOM uint16_t QEPCTL;  /*!< 0x0000002a */ 
           
           struct
           {
              __IOM uint16_t WDE                       : 1 ;     /*!< [0:0] : QEP watchdog enable                                             <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = Disable the eQEP watchdog timer                      <br>  1h (R/W) = Enable the eQEP watchdog timer                       <br>. */
              __IOM uint16_t UTE                       : 1 ;     /*!< [1:1] : QEP unit timer enable                                           <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = Disable eQEP unit timer                              <br>  1h (R/W) = Enable unit timer                                    <br>. */
              __IOM uint16_t QCLM                      : 1 ;     /*!< [2:2] : QEP capture latch mode                                          <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = Latch on position counter read by CPU. */
              __IOM uint16_t QPEN                      : 1 ;     /*!< [3:3] : Quadrature position counter enable/software reset               <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = Reset the eQEP peripheral internal operating flags/read only registers. */
              __IOM uint16_t IEL                       : 2 ;     /*!< [5:4] : Reset type: SYSRSn                                              <br>  0h (R/W) = Reserved                                             <br>  1h (R/W) = Latches position counter on rising edge of the index signal<br>  2h (R/W) = Latches position counter on falling edge of the index signal<br>  3h (R/W) = Software index marker. */
              __IOM uint16_t SEL                       : 1 ;     /*!< [6:6] : Strobe event latch of position counter                          <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = The position counter is latched on the rising edge of<br>  QEPS strobe (QPOSSLAT = POSCCNT). */
              __IOM uint16_t SWI                       : 1 ;     /*!< [7:7] : Software init position counter                                  <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = Do nothing (action disabled)                         <br>  1h (R/W) = Initialize position counter (QPOSCNT=QPOSINIT). */
              __IOM uint16_t IEI                       : 2 ;     /*!< [9:8] : Index event init of position count                              <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = Do nothing (action disabled)                         <br>  1h (R/W) = Do nothing (action disabled)                         <br>  2h (R/W) = Initializes the position counter on the rising edge of the<br>  QEPI signal (QPOSCNT = QPOSINIT)                                <br>  3h (R/W) = Initializes the position counter on the falling edge of <br>  QEPI signal (QPOSCNT = QPOSINIT)                                <br>. */
              __IOM uint16_t SEI                       : 2 ;     /*!< [11:10] : Strobe event initialization of position counter                 <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = Does nothing (action disabled)                       <br>  1h (R/W) = Does nothing (action disabled)                       <br>  2h (R/W) = Initializes the position counter on rising edge of the<br>  QEPS signal                                                     <br>  3h (R/W) = Clockwise Direction:                                 <br>  Initializes the position counter on the rising edge of QEPS strobe<br>  Counter Clockwise Direction:                                    <br>  Initializes the position counter on the falling edge of QEPS strobe<br>. */
              __IOM uint16_t PCRM                      : 2 ;     /*!< [13:12] : Postion counter reset                                           <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = Position counter reset on an index event             <br>  1h (R/W) = Position counter reset on the maximum position       <br>  2h (R/W) = Position counter reset on the first index event      <br>  3h (R/W) = Position counter reset on a unit time event          <br>. */
              __IOM uint16_t FREE_SOFT                 : 2 ;     /*!< [15:14] : Emulation mode                                                  <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = QPOSCNT behavior                                     <br>  Position counter stops immediately on emulation suspend         <br>  0h (R/W) = QWDTMR behavior                                      <br>  Watchdog counter stops immediately                              <br>  0h (R/W) = QUTMR behavior                                       <br>  Unit timer stops immediately                                    <br>  0h (R/W) = QCTMR behavior                                       <br>  Capture Timer stops immediately                                 <br>  1h (R/W) = QPOSCNT behavior                                     <br>  Position counter continues to count until the rollover          <br>  1h (R/W) = QWDTMR behavior                                      <br>  Watchdog counter counts until WD period match roll over         <br>  1h (R/W) = QUTMR behavior                                       <br>  Unit timer counts until period rollover                         <br>  1h (R/W) = QCTMR behavior                                       <br>  Capture Timer counts until next unit period event               <br>  2h (R/W) = QPOSCNT behavior                                     <br>  Position counter is unaffected by emulation suspend             <br>  2h (R/W) = QWDTMR behavior                                      <br>  Watchdog counter is unaffected by emulation suspend             <br>  2h (R/W) = QUTMR behavior                                       <br>  Unit timer is unaffected by emulation suspend                   <br>  2h (R/W) = QCTMR behavior                                       <br>  Capture Timer is unaffected by emulation suspend                <br>  3h (R/W) = Same as FREE_SOFT=2                                  <br>. */
           } QEPCTLb;
        };

        union
        {
           __IOM uint16_t QCAPCTL;  /*!< 0x0000002c */ 
           
           struct
           {
              __IOM uint16_t UPPS                      : 4 ;     /*!< [3:0] : Unit position event prescaler                                   <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = UPEVNT = QCLK/1                                      <br>  1h (R/W) = UPEVNT = QCLK/2                                      <br>  2h (R/W) = UPEVNT = QCLK/4                                      <br>  3h (R/W) = UPEVNT = QCLK/8                                      <br>  4h (R/W) = UPEVNT = QCLK/16                                     <br>  5h (R/W) = UPEVNT = QCLK/32                                     <br>  6h (R/W) = UPEVNT = QCLK/64                                     <br>  7h (R/W) = UPEVNT = QCLK/128                                    <br>  8h (R/W) = UPEVNT = QCLK/256                                    <br>  9h (R/W) = UPEVNT = QCLK/512                                    <br>  Ah (R/W) = UPEVNT = QCLK/1024                                   <br>  Bh (R/W) = UPEVNT = QCLK/2048                                   <br>  Ch (R/W) = Reserved                                             <br>  Dh (R/W) = Reserved                                             <br>  Eh (R/W) = Reserved                                             <br>  Fh (R/W) = Reserved                                             <br>. */
              __IOM uint16_t CCPS                      : 3 ;     /*!< [6:4] : eQEP capture timer clock prescaler                              <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = CAPCLK = SYSCLKOUT/1                                 <br>  1h (R/W) = CAPCLK = SYSCLKOUT/2                                 <br>  2h (R/W) = CAPCLK = SYSCLKOUT/4                                 <br>  3h (R/W) = CAPCLK = SYSCLKOUT/8                                 <br>  4h (R/W) = CAPCLK = SYSCLKOUT/16                                <br>  5h (R/W) = CAPCLK = SYSCLKOUT/32                                <br>  6h (R/W) = CAPCLK = SYSCLKOUT/64                                <br>  7h (R/W) = CAPCLK = SYSCLKOUT/128                               <br>. */
                    uint16_t RSV_0                     : 8 ;     /*!< [14:7] : reserved. */
              __IOM uint16_t CEN                       : 1 ;     /*!< [15:15] : Enable eQEP capture                                             <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = eQEP capture unit is disabled                        <br>  1h (R/W) = eQEP capture unit is enabled                         <br>. */
           } QCAPCTLb;
        };

        union
        {
           __IOM uint16_t QPOSCTL;  /*!< 0x0000002e */ 
           
           struct
           {
              __IOM uint16_t PCSPW                     : 12;     /*!< [11:0] : Select-position-compare sync output pulse width                 <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = 1 * 4 * SYSCLKOUT cycles                             <br>  1h (R/W) = 2 * 4 * SYSCLKOUT cycles                             <br>  FFFh (R/W) = 4096 * 4 * SYSCLKOUT cycles                        <br>. */
              __IOM uint16_t PCE                       : 1 ;     /*!< [12:12] : Position compare enable/disable                                 <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = Disable position compare unit                        <br>  1h (R/W) = Enable position compare unit                         <br>. */
              __IOM uint16_t PCPOL                     : 1 ;     /*!< [13:13] : Polarity of sync output                                         <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = Active HIGH pulse output                             <br>  1h (R/W) = Active LOW pulse output                              <br>. */
              __IOM uint16_t PCLOAD                    : 1 ;     /*!< [14:14] : Position compare of shadow load                                 <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = Load on QPOSCNT = 0                                  <br>  1h (R/W) = Load when QPOSCNT = QPOSCMP                          <br>. */
              __IOM uint16_t PCSHDW                    : 1 ;     /*!< [15:15] : Position compare of shadow enable                               <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = Shadow disabled, load Immediate                      <br>  1h (R/W) = Shadow enabled                                       <br>. */
           } QPOSCTLb;
        };

        union
        {
           __IOM uint16_t QEINT;  /*!< 0x00000030 */ 
           
           struct
           {
                    uint16_t RSV_1                     : 1 ;     /*!< [0:0] : reserved. */
              __IOM uint16_t PCE                       : 1 ;     /*!< [1:1] : Position counter error interrupt enable                         <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = Interrupt is disabled                                <br>  1h (R/W) = Interrupt is enabled                                 <br>. */
              __IOM uint16_t QPE                       : 1 ;     /*!< [2:2] : Quadrature phase error interrupt enable                         <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = Interrupt is disabled                                <br>  1h (R/W) = Interrupt is enabled                                 <br>. */
              __IOM uint16_t QDC                       : 1 ;     /*!< [3:3] : Quadrature direction change interrupt enable                    <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = Interrupt is disabled                                <br>  1h (R/W) = Interrupt is enabled                                 <br>. */
              __IOM uint16_t WTO                       : 1 ;     /*!< [4:4] : Watchdog time out interrupt enable                              <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = Interrupt is disabled                                <br>  1h (R/W) = Interrupt is enabled                                 <br>. */
              __IOM uint16_t PCU                       : 1 ;     /*!< [5:5] : Position counter underflow interrupt enable                     <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = Interrupt is disabled                                <br>  1h (R/W) = Interrupt is enabled                                 <br>. */
              __IOM uint16_t PCO                       : 1 ;     /*!< [6:6] : Position counter overflow interrupt enable                      <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = Interrupt is disabled                                <br>  1h (R/W) = Interrupt is enabled                                 <br>. */
              __IOM uint16_t PCR                       : 1 ;     /*!< [7:7] : Position-compare ready interrupt enable                         <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = Interrupt is disabled                                <br>  1h (R/W) = Interrupt is enabled                                 <br>. */
              __IOM uint16_t PCM                       : 1 ;     /*!< [8:8] : Position-compare match interrupt enable                         <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = Interrupt is disabled                                <br>  1h (R/W) = Interrupt is enabled                                 <br>. */
              __IOM uint16_t SEL                       : 1 ;     /*!< [9:9] : Strobe event latch interrupt enable                             <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = Interrupt is disabled                                <br>  1h (R/W) = Interrupt is enabled                                 <br>. */
              __IOM uint16_t IEL                       : 1 ;     /*!< [10:10] : Index event latch interrupt enable                              <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = Interrupt is disabled                                <br>  1h (R/W) = Interrupt is enabled                                 <br>. */
              __IOM uint16_t UTO                       : 1 ;     /*!< [11:11] : Unit time out interrupt enable                                  <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = Interrupt is disabled                                <br>  1h (R/W) = Interrupt is enabled                                 <br>. */
              __IOM uint16_t QMAE                      : 1 ;     /*!< [12:12] : QMA Error Interrupt enable                                      <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = Interrupt is disabled                                <br>  1h (R/W) = Interrupt is enabled                                 <br>. */
                    uint16_t RSV_0                     : 3 ;     /*!< [15:13] : reserved. */
           } QEINTb;
        };

        union
        {
           __IM uint16_t QFLG;  /*!< 0x00000032 */ 
           
           struct
           {
              __IM  uint16_t EQEPINT                    : 1 ;     /*!< [0:0] : Global interrupt status flag                                    <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No interrupt generated                               <br>  1h (R/W) = Interrupt was generated                              <br>. */
              __IM  uint16_t PCE                       : 1 ;     /*!< [1:1] : Position counter error interrupt flag                           <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No interrupt generated                               <br>  1h (R/W) = Position counter error                               <br>. */
              __IM  uint16_t PHE                       : 1 ;     /*!< [2:2] : Quadrature phase error interrupt flag                           <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No interrupt generated                               <br>  1h (R/W) = Set on simultaneous transition of QEPA and QEPB      <br>. */
              __IM  uint16_t QDC                       : 1 ;     /*!< [3:3] : Quadrature direction change interrupt flag                      <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No interrupt generated                               <br>  1h (R/W) = Interrupt was generated                              <br>. */
              __IM  uint16_t WTO                       : 1 ;     /*!< [4:4] : Watchdog timeout interrupt flag                                 <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No interrupt generated                               <br>  1h (R/W) = Set by watchdog timeout                              <br>. */
              __IM  uint16_t PCU                       : 1 ;     /*!< [5:5] : Position counter underflow interrupt flag                       <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No interrupt generated                               <br>  1h (R/W) = This bit is set on position counter underflow. */
              __IM  uint16_t PCO                       : 1 ;     /*!< [6:6] : Position counter overflow interrupt flag                        <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No interrupt generated                               <br>  1h (R/W) = This bit is set on position counter overflow         <br>. */
              __IM  uint16_t PCR                       : 1 ;     /*!< [7:7] : Position-compare ready interrupt flag                           <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No interrupt generated                               <br>  1h (R/W) = This bit is set after transferring the shadow register value<br>  to the active position compare register                         <br>. */
              __IM  uint16_t PCM                       : 1 ;     /*!< [8:8] : eQEP compare match event interrupt flag                         <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No interrupt generated                               <br>  1h (R/W) = This bit is set on position-compare match            <br>. */
              __IM  uint16_t SEL                       : 1 ;     /*!< [9:9] : Strobe event latch interrupt flag                               <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No interrupt generated                               <br>  1h (R/W) = This bit is set after latching the QPOSCNT to QPOSSLAT<br>. */
              __IM  uint16_t IEL                       : 1 ;     /*!< [10:10] : Index event latch interrupt flag                                <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No interrupt generated                               <br>  1h (R/W) = This bit is set after latching the QPOSCNT to QPOSILAT<br>. */
              __IM  uint16_t UTO                       : 1 ;     /*!< [11:11] : Unit time out interrupt flag                                    <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No interrupt generated                               <br>  1h (R/W) = Set by eQEP unit timer period match                  <br>. */
              __IM  uint16_t QMAE                      : 1 ;     /*!< [12:12] : QMA Error interrupt flag                                        <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No interrupt generated                               <br>  1h (R/W) = Interrupt was generated                              <br>. */
                    uint16_t RSV_0                     : 3 ;     /*!< [15:13] : reserved. */
           } QFLGb;
        };

        union
        {
           __IOM uint16_t QCLR;  /*!< 0x00000034 */ 
           
           struct
           {
              __IOM uint16_t INTCLR                    : 1 ;     /*!< [0:0] : Global interrupt clear flag                                     <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No effect                                            <br>  1h (R/W) = Clears the interrupt flag                            <br>. */
              __IOM uint16_t PCE                       : 1 ;     /*!< [1:1] : Clear position counter error interrupt flag                     <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No effect                                            <br>  1h (R/W) = Clears the interrupt flag                            <br>. */
              __IOM uint16_t PHE                       : 1 ;     /*!< [2:2] : Clear quadrature phase error interrupt flag                     <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No effect                                            <br>  1h (R/W) = Clears the interrupt flag                            <br>. */
              __IOM uint16_t QDC                       : 1 ;     /*!< [3:3] : Clear quadrature direction change interrupt flag                <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No effect                                            <br>  1h (R/W) = Clears the interrupt flag                            <br>. */
              __IOM uint16_t WTO                       : 1 ;     /*!< [4:4] : Clear watchdog timeout interrupt flag                           <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No effect                                            <br>  1h (R/W) = Clears the interrupt flag                            <br>. */
              __IOM uint16_t PCU                       : 1 ;     /*!< [5:5] : Clear position counter underflow interrupt flag                 <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No effect                                            <br>  1h (R/W) = Clears the interrupt flag                            <br>. */
              __IOM uint16_t PCO                       : 1 ;     /*!< [6:6] : Clear position counter overflow interrupt flag                  <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No effect                                            <br>  1h (R/W) = Clears the interrupt flag                            <br>. */
              __IOM uint16_t PCR                       : 1 ;     /*!< [7:7] : Clear position-compare ready interrupt flag                     <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No effect                                            <br>  1h (R/W) = Clears the interrupt flag                            <br>. */
              __IOM uint16_t PCM                       : 1 ;     /*!< [8:8] : Clear eQEP compare match event interrupt flag                   <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No effect                                            <br>  1h (R/W) = Clears the interrupt flag                            <br>. */
              __IOM uint16_t SEL                       : 1 ;     /*!< [9:9] : Clear strobe event latch interrupt flag                         <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No effect                                            <br>  1h (R/W) = Clears the interrupt flag                            <br>. */
              __IOM uint16_t IEL                       : 1 ;     /*!< [10:10] : Clear index event latch interrupt flag                          <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No effect                                            <br>  1h (R/W) = Clears the interrupt flag                            <br>. */
              __IOM uint16_t UTO                       : 1 ;     /*!< [11:11] : Clear unit time out interrupt flag                              <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No effect                                            <br>  1h (R/W) = Clears the interrupt flag                            <br>. */
              __IOM uint16_t QMAE                      : 1 ;     /*!< [12:12] : Clear QMA Error interrupt flag                                  <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No effect                                            <br>  1h (R/W) = Clears the interrupt flag                            <br>. */
                    uint16_t RSV_0                     : 3 ;     /*!< [15:13] : reserved. */
           } QCLRb;
        };

        union
        {
           __IOM uint16_t QFRC;  /*!< 0x00000036 */ 
           
           struct
           {
                    uint16_t RSV_1                     : 1 ;     /*!< [0:0] : reserved. */
              __IOM uint16_t PCE                       : 1 ;     /*!< [1:1] : Force position counter error interrupt                          <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No effect                                            <br>  1h (R/W) = Force the interrupt                                  <br>. */
              __IOM uint16_t PHE                       : 1 ;     /*!< [2:2] : Force quadrature phase error interrupt                          <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No effect                                            <br>  1h (R/W) = Force the interrupt                                  <br>. */
              __IOM uint16_t QDC                       : 1 ;     /*!< [3:3] : Force quadrature direction change interrupt                     <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No effect                                            <br>  1h (R/W) = Force the interrupt                                  <br>. */
              __IOM uint16_t WTO                       : 1 ;     /*!< [4:4] : Force watchdog time out interrupt                               <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No effect                                            <br>  1h (R/W) = Force the interrupt                                  <br>. */
              __IOM uint16_t PCU                       : 1 ;     /*!< [5:5] : Force position counter underflow interrupt                      <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No effect                                            <br>  1h (R/W) = Force the interrupt                                  <br>. */
              __IOM uint16_t PCO                       : 1 ;     /*!< [6:6] : Force position counter overflow interrupt                       <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No effect                                            <br>  1h (R/W) = Force the interrupt                                  <br>. */
              __IOM uint16_t PCR                       : 1 ;     /*!< [7:7] : Force position-compare ready interrupt                          <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No effect                                            <br>  1h (R/W) = Force the interrupt                                  <br>. */
              __IOM uint16_t PCM                       : 1 ;     /*!< [8:8] : Force position-compare match interrupt                          <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No effect                                            <br>  1h (R/W) = Force the interrupt                                  <br>. */
              __IOM uint16_t SEL                       : 1 ;     /*!< [9:9] : Force strobe event latch interrupt                              <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No effect                                            <br>  1h (R/W) = Force the interrupt                                  <br>. */
              __IOM uint16_t IEL                       : 1 ;     /*!< [10:10] : Force index event latch interrupt                               <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No effect                                            <br>  1h (R/W) = Force the interrupt                                  <br>. */
              __IOM uint16_t UTO                       : 1 ;     /*!< [11:11] : Force unit time out interrupt                                   <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No effect                                            <br>  1h (R/W) = Force the interrupt                                  <br>. */
              __IOM uint16_t QMAE                      : 1 ;     /*!< [12:12] : Force QMA error interrupt                                       <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No effect                                            <br>  1h (R/W) = Force the interrupt                                  <br>. */
                    uint16_t RSV_0                     : 3 ;     /*!< [15:13] : reserved. */
           } QFRCb;
        };

        union
        {
           __IOM uint16_t QEPSTS;  /*!< 0x00000038 */ 
           
           struct
           {
              __IM  uint16_t PCEF                      : 1 ;     /*!< [0:0] : Position counter error flag. */
              __IOM uint16_t FIMF                      : 1 ;     /*!< [1:1] : First index marker flag                                         <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = First index pulse has not occurred. */
              __IOM uint16_t CDEF                      : 1 ;     /*!< [2:2] : Capture direction error flag                                    <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = Capture direction error has not occurred. */
              __IOM uint16_t COEF                      : 1 ;     /*!< [3:3] : Capture overflow error flag                                     <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = Overflow has not occurred. */
              __IM  uint16_t QDLF                      : 1 ;     /*!< [4:4] : eQEP direction latch flag                                       <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = Counter-clockwise rotation (or reverse movement) on index event marker<br>  1h (R/W) = Clockwise rotation (or forward movement) on index event marker<br>. */
              __IM  uint16_t QDF                       : 1 ;     /*!< [5:5] : Quadrature direction flag                                       <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = Counter-clockwise rotation (or reverse movement)     <br>  1h (R/W) = Clockwise rotation (or forward movement)             <br>. */
              __IM  uint16_t FIDF                      : 1 ;     /*!< [6:6] : Direction on the first index marker                             <br>  Status of the direction is latched on the first index event marker. */
              __IOM uint16_t UPEVENT                   : 1 ;     /*!< [7:7] : Unit position event flag                                        <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = No unit position event detected                      <br>  1h (R/W) = Unit position event detected. */
                    uint16_t RSV_0                     : 8 ;     /*!< [15:8] : reserved. */
           } QEPSTSb;
        };

        union
        {
           __IOM uint16_t QCTMR;  /*!< 0x0000003a */ 
           
           struct
           {
              __IOM  uint16_t QCTMR                     : 16;     /*!< [15:0] : This register provides time base for edge capture unit. */
           } QCTMRb;
        };

        union
        {
           __IOM uint16_t QCPRD;  /*!< 0x0000003c */ 
           
           struct
           {
              __IOM  uint16_t QCPRD                     : 16;     /*!< [15:0] : This register holds the period count value between the last     <br>  successive eQEP position events                                 <br>  Reset type: SYSRSn                                              <br>. */
           } QCPRDb;
        };

        union
        {
           __IM uint16_t QCTMRLAT;  /*!< 0x0000003e */ 
           
           struct
           {
              __IM  uint16_t QCTMRLAT                  : 16;     /*!< [15:0] : The eQEP capture timer value can be latched into this register on<br>  two events viz. */
           } QCTMRLATb;
        };

        union
        {
           __IM uint32_t QCPRDLAT;  /*!< 0x00000040 */ 
           
           struct
           {
              __IM  uint32_t QCPRDLAT                  : 16;     /*!< [15:0] : eQEP capture period value can be latched into this register on two<br>  events viz. */
                    uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
           } QCPRDLATb;
        };

        uint8_t    RSV_0X44[28];   /*!< 0x00000044~0x0000005f : reserved */

        union
        {
           __IM uint32_t REV;  /*!< 0x00000060 */ 
           
           struct
           {
              __IM  uint32_t MAJOR                     : 3 ;     /*!< [2:0] : This field specifies the Major Revision number for the eQEP IP. */
              __IM  uint32_t MINOR                     : 3 ;     /*!< [5:3] : This field specifies the Minor Revision number for the eQEP IP. */
                    uint32_t RSV_0                     : 26;     /*!< [31:6] : reserved. */
           } REVb;
        };

        union
        {
           __IOM uint32_t QEPSTROBESEL;  /*!< 0x00000064 */ 
           
           struct
           {
              __IOM uint32_t STROBESEL                 : 2 ;     /*!< [1:0] : Strobe source select:                                           <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = QEP Strobe after polarity mux                        <br>  1h (R/W) = QEP Strobe after polarity mux                        <br>  2h (R/W) = QEP Strobe after polarity mux ORed with ADCSOCA      <br>  3h (R/W) = QEP Strobe after polarity mux ORed with ADCSOCB      <br>. */
                    uint32_t RSV_0                     : 30;     /*!< [31:2] : reserved. */
           } QEPSTROBESELb;
        };

        union
        {
           __IOM uint32_t QMACTRL;  /*!< 0x00000068 */ 
           
           struct
           {
              __IOM uint32_t MODE                      : 3 ;     /*!< [2:0] : Select Mode for QMA mode:                                       <br>  000 : QMA Module is bypassed. */
              __IOM uint32_t BIN_MODE                  : 1 ;     /*!< [3:3] : Select Binary Mode for PDU mode:                                <br>  0: working as existing devices. */
                    uint32_t RSV_0                     : 28;     /*!< [31:4] : reserved. */
           } QMACTRLb;
        };

        union
        {
           __IOM uint32_t QEPSRCSEL;  /*!< 0x0000006c */ 
           
           struct
           {
              __IOM uint32_t QEPASEL                   : 4 ;     /*!< [3:0] : QEPA source select:                                             <br>  0x0: Device Pin (Default)                                       <br>  0x1: CMPSS1. */
              __IOM uint32_t QEPBSEL                   : 4 ;     /*!< [7:4] : QEPB source select:                                             <br>  0x0: Device Pin (Default)                                       <br>  0x1: CMPSS1. */
              __IOM uint32_t QEPISEL                   : 4 ;     /*!< [11:8] : QEP Index source select:                                        <br>  0x0: Device Pin (Default)                                       <br>  0x1: CMPSS1. */
              __IOM uint32_t QEPSSEL                   : 4 ;     /*!< [15:12] : QEP Strobe source select:                                       <br>  0x0: From device Pins (Default). */
                    uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
           } QEPSRCSELb;
        };

        union
        {
           __IOM uint32_t ADCSOCSEL;  /*!< 0x00000070 */ 
           
           struct
           {
              __IOM uint32_t ADCSOCA                   : 4 ;     /*!< [3:0] : ADCSOCA source select:                                          <br>  0x0: all ADCSOCA signal ORed (Default)                          <br>  0x1: ADCSOCA. */
              __IOM uint32_t ADCSOCB                   : 4 ;     /*!< [7:4] : ADCSOCB source select:                                          <br>  0x0: all ADCSOCB signal ORed (Default)                          <br>  0x1: ADCSOCB. */
                    uint32_t RSV_0                     : 24;     /*!< [31:8] : reserved. */
           } ADCSOCSELb;
        };

        uint8_t    RSV_0X74[12];   /*!< 0x00000074~0x0000007f : reserved */

        union
        {
           __IOM uint32_t CLBBYPASS;  /*!< 0x00000080 */ 
           
           struct
           {
              __IOM uint32_t QASEL                     : 1 ;     /*!< [0:0] : 0x0: bypass CLB QA input                                        <br>  0x1: select CLB QA input                                        <br>. */
              __IOM uint32_t QBSEL                     : 1 ;     /*!< [1:1] : 0x0: bypass CLB QB input                                        <br>  0x1: select CLB QB input                                        <br>. */
              __IOM uint32_t QDIRSEL                   : 1 ;     /*!< [2:2] : 0x0: bypass CLB QDIR input                                      <br>  0x1: select CLB QDIR input                                      <br>. */
              __IOM uint32_t QCLKSEL                   : 1 ;     /*!< [3:3] : 0x0: bypass CLB QCLK input                                      <br>  0x1: select CLB QCLK input                                      <br>. */
                    uint32_t RSV_0                     : 28;     /*!< [31:4] : reserved. */
           } CLBBYPASSb;
        };

        union
        {
           __IOM uint32_t DBGSEL;  /*!< 0x00000084 */ 
           
           struct
           {
              __IOM uint32_t DBG_SEL                   : 5 ;     /*!< [4:0] : signal debug port select:                                       <br>  Reset type: SYSRSn                                              <br>. */
              __IOM uint32_t MODULE_SELECT             : 3 ;     /*!< [7:5] : module debug port select:                                       <br>  0x0: controller                                                 <br>  0x1: captor                                                     <br>  0x2: decoder                                                    <br>  0x3: controller                                                 <br>  others: controller                                              <br>  Reset type: SYSRSn                                              <br>. */
                    uint32_t RSV_0                     : 24;     /*!< [31:8] : reserved. */
           } DBGSELb;
        };
} EQEP_REGS_Type;


/*!
 * @}
 */

/*!
 * \name EQEP Base Address Definitions
 *
 * @{
 */

 /*! \brief EQEP1 base address */
#define EQEP1_BASE (0x40700000UL)
/*! \brief EQEP2 base address */
#define EQEP2_BASE (0x40700400UL)
/*! \brief EQEP3 base address */
#define EQEP3_BASE (0x40700800UL)

/*! \brief EQEP1 base pointer */
#define EQEP1 ((EQEP_REGS_Type *) EQEP1_BASE)
/*! \brief EQEP2 base pointer */
#define EQEP2 ((EQEP_REGS_Type *) EQEP2_BASE)
/*! \brief EQEP3 base pointer */
#define EQEP3 ((EQEP_REGS_Type *) EQEP3_BASE)


/*!
 * @}
 */

 
/*!
 * \name EQEP Register Bitfield Definitions
 *
 * @{
 */

 /* QPOSCNT bitfield */
#define EQEP_QPOSCNT_QPOSCNT_Pos    (0U)                                                                                  /*!< QPOSCNT Postion   0          */ 
#define EQEP_QPOSCNT_QPOSCNT_Msk    (0xffffffffU << EQEP_QPOSCNT_QPOSCNT_Pos)                                              /*!< QPOSCNT Mask      0xFFFFFFFF */
#define EQEP_QPOSCNT_QPOSCNT_Set(x) (((uint32_t) (x) << EQEP_QPOSCNT_QPOSCNT_Pos) & EQEP_QPOSCNT_QPOSCNT_Msk)               /*!< QPOSCNT Set Value            */
#define EQEP_QPOSCNT_QPOSCNT_Get(x) (((uint32_t) (x) & EQEP_QPOSCNT_QPOSCNT_Msk) >> EQEP_QPOSCNT_QPOSCNT_Pos)               /*!< QPOSCNT Get Value            */


/* QPOSINIT bitfield */
#define EQEP_QPOSINIT_QPOSINIT_Pos    (0U)                                                                                  /*!< QPOSINIT Postion   0          */ 
#define EQEP_QPOSINIT_QPOSINIT_Msk    (0xffffffffU << EQEP_QPOSINIT_QPOSINIT_Pos)                                            /*!< QPOSINIT Mask      0xFFFFFFFF */
#define EQEP_QPOSINIT_QPOSINIT_Set(x) (((uint32_t) (x) << EQEP_QPOSINIT_QPOSINIT_Pos) & EQEP_QPOSINIT_QPOSINIT_Msk)           /*!< QPOSINIT Set Value            */
#define EQEP_QPOSINIT_QPOSINIT_Get(x) (((uint32_t) (x) & EQEP_QPOSINIT_QPOSINIT_Msk) >> EQEP_QPOSINIT_QPOSINIT_Pos)           /*!< QPOSINIT Get Value            */


/* QPOSMAX bitfield */
#define EQEP_QPOSMAX_QPOSMAX_Pos    (0U)                                                                                  /*!< QPOSMAX Postion   0          */ 
#define EQEP_QPOSMAX_QPOSMAX_Msk    (0xffffffffU << EQEP_QPOSMAX_QPOSMAX_Pos)                                              /*!< QPOSMAX Mask      0xFFFFFFFF */
#define EQEP_QPOSMAX_QPOSMAX_Set(x) (((uint32_t) (x) << EQEP_QPOSMAX_QPOSMAX_Pos) & EQEP_QPOSMAX_QPOSMAX_Msk)               /*!< QPOSMAX Set Value            */
#define EQEP_QPOSMAX_QPOSMAX_Get(x) (((uint32_t) (x) & EQEP_QPOSMAX_QPOSMAX_Msk) >> EQEP_QPOSMAX_QPOSMAX_Pos)               /*!< QPOSMAX Get Value            */


/* QPOSCMP bitfield */
#define EQEP_QPOSCMP_QPOSCMP_Pos    (0U)                                                                                  /*!< QPOSCMP Postion   0          */ 
#define EQEP_QPOSCMP_QPOSCMP_Msk    (0xffffffffU << EQEP_QPOSCMP_QPOSCMP_Pos)                                              /*!< QPOSCMP Mask      0xFFFFFFFF */
#define EQEP_QPOSCMP_QPOSCMP_Set(x) (((uint32_t) (x) << EQEP_QPOSCMP_QPOSCMP_Pos) & EQEP_QPOSCMP_QPOSCMP_Msk)               /*!< QPOSCMP Set Value            */
#define EQEP_QPOSCMP_QPOSCMP_Get(x) (((uint32_t) (x) & EQEP_QPOSCMP_QPOSCMP_Msk) >> EQEP_QPOSCMP_QPOSCMP_Pos)               /*!< QPOSCMP Get Value            */


/* QPOSILAT bitfield */
#define EQEP_QPOSILAT_QPOSILAT_Pos    (0U)                                                                                  /*!< QPOSILAT Postion   0          */ 
#define EQEP_QPOSILAT_QPOSILAT_Msk    (0xffffffffU << EQEP_QPOSILAT_QPOSILAT_Pos)                                            /*!< QPOSILAT Mask      0xFFFFFFFF */
#define EQEP_QPOSILAT_QPOSILAT_Set(x) (((uint32_t) (x) << EQEP_QPOSILAT_QPOSILAT_Pos) & EQEP_QPOSILAT_QPOSILAT_Msk)           /*!< QPOSILAT Set Value            */
#define EQEP_QPOSILAT_QPOSILAT_Get(x) (((uint32_t) (x) & EQEP_QPOSILAT_QPOSILAT_Msk) >> EQEP_QPOSILAT_QPOSILAT_Pos)           /*!< QPOSILAT Get Value            */


/* QPOSSLAT bitfield */
#define EQEP_QPOSSLAT_QPOSSLAT_Pos    (0U)                                                                                  /*!< QPOSSLAT Postion   0          */ 
#define EQEP_QPOSSLAT_QPOSSLAT_Msk    (0xffffffffU << EQEP_QPOSSLAT_QPOSSLAT_Pos)                                            /*!< QPOSSLAT Mask      0xFFFFFFFF */
#define EQEP_QPOSSLAT_QPOSSLAT_Set(x) (((uint32_t) (x) << EQEP_QPOSSLAT_QPOSSLAT_Pos) & EQEP_QPOSSLAT_QPOSSLAT_Msk)           /*!< QPOSSLAT Set Value            */
#define EQEP_QPOSSLAT_QPOSSLAT_Get(x) (((uint32_t) (x) & EQEP_QPOSSLAT_QPOSSLAT_Msk) >> EQEP_QPOSSLAT_QPOSSLAT_Pos)           /*!< QPOSSLAT Get Value            */


/* QPOSLAT bitfield */
#define EQEP_QPOSLAT_QPOSLAT_Pos    (0U)                                                                                  /*!< QPOSLAT Postion   0          */ 
#define EQEP_QPOSLAT_QPOSLAT_Msk    (0xffffffffU << EQEP_QPOSLAT_QPOSLAT_Pos)                                              /*!< QPOSLAT Mask      0xFFFFFFFF */
#define EQEP_QPOSLAT_QPOSLAT_Set(x) (((uint32_t) (x) << EQEP_QPOSLAT_QPOSLAT_Pos) & EQEP_QPOSLAT_QPOSLAT_Msk)               /*!< QPOSLAT Set Value            */
#define EQEP_QPOSLAT_QPOSLAT_Get(x) (((uint32_t) (x) & EQEP_QPOSLAT_QPOSLAT_Msk) >> EQEP_QPOSLAT_QPOSLAT_Pos)               /*!< QPOSLAT Get Value            */


/* QUTMR bitfield */
#define EQEP_QUTMR_QUTMR_Pos    (0U)                                                                                  /*!< QUTMR Postion   0          */ 
#define EQEP_QUTMR_QUTMR_Msk    (0xffffffffU << EQEP_QUTMR_QUTMR_Pos)                                                  /*!< QUTMR Mask      0xFFFFFFFF */
#define EQEP_QUTMR_QUTMR_Set(x) (((uint32_t) (x) << EQEP_QUTMR_QUTMR_Pos) & EQEP_QUTMR_QUTMR_Msk)                       /*!< QUTMR Set Value            */
#define EQEP_QUTMR_QUTMR_Get(x) (((uint32_t) (x) & EQEP_QUTMR_QUTMR_Msk) >> EQEP_QUTMR_QUTMR_Pos)                       /*!< QUTMR Get Value            */


/* QUPRD bitfield */
#define EQEP_QUPRD_QUPRD_Pos    (0U)                                                                                  /*!< QUPRD Postion   0          */ 
#define EQEP_QUPRD_QUPRD_Msk    (0xffffffffU << EQEP_QUPRD_QUPRD_Pos)                                                  /*!< QUPRD Mask      0xFFFFFFFF */
#define EQEP_QUPRD_QUPRD_Set(x) (((uint32_t) (x) << EQEP_QUPRD_QUPRD_Pos) & EQEP_QUPRD_QUPRD_Msk)                       /*!< QUPRD Set Value            */
#define EQEP_QUPRD_QUPRD_Get(x) (((uint32_t) (x) & EQEP_QUPRD_QUPRD_Msk) >> EQEP_QUPRD_QUPRD_Pos)                       /*!< QUPRD Get Value            */


/* QWDTMR bitfield */
#define EQEP_QWDTMR_QWDTMR_Pos    (0U)                                                                                  /*!< QWDTMR Postion   0          */ 
#define EQEP_QWDTMR_QWDTMR_Msk    (0xffffU << EQEP_QWDTMR_QWDTMR_Pos)                                                    /*!< QWDTMR Mask      0x0000FFFF */
#define EQEP_QWDTMR_QWDTMR_Set(x) (((uint16_t) (x) << EQEP_QWDTMR_QWDTMR_Pos) & EQEP_QWDTMR_QWDTMR_Msk)                   /*!< QWDTMR Set Value            */
#define EQEP_QWDTMR_QWDTMR_Get(x) (((uint16_t) (x) & EQEP_QWDTMR_QWDTMR_Msk) >> EQEP_QWDTMR_QWDTMR_Pos)                   /*!< QWDTMR Get Value            */


/* QWDPRD bitfield */
#define EQEP_QWDPRD_QWDPRD_Pos    (0U)                                                                                  /*!< QWDPRD Postion   0          */ 
#define EQEP_QWDPRD_QWDPRD_Msk    (0xffffU << EQEP_QWDPRD_QWDPRD_Pos)                                                    /*!< QWDPRD Mask      0x0000FFFF */
#define EQEP_QWDPRD_QWDPRD_Set(x) (((uint16_t) (x) << EQEP_QWDPRD_QWDPRD_Pos) & EQEP_QWDPRD_QWDPRD_Msk)                   /*!< QWDPRD Set Value            */
#define EQEP_QWDPRD_QWDPRD_Get(x) (((uint16_t) (x) & EQEP_QWDPRD_QWDPRD_Msk) >> EQEP_QWDPRD_QWDPRD_Pos)                   /*!< QWDPRD Get Value            */


/* QDECCTL bitfield */
#define EQEP_QDECCTL_QSRC_Pos    (14U)                                                                                 /*!< QSRC Postion   14         */ 
#define EQEP_QDECCTL_QSRC_Msk    (0x3U << EQEP_QDECCTL_QSRC_Pos)                                                        /*!< QSRC Mask      0x0000C000 */
#define EQEP_QDECCTL_QSRC_Set(x) (((uint16_t) (x) << EQEP_QDECCTL_QSRC_Pos) & EQEP_QDECCTL_QSRC_Msk)                     /*!< QSRC Set Value            */
#define EQEP_QDECCTL_QSRC_Get(x) (((uint16_t) (x) & EQEP_QDECCTL_QSRC_Msk) >> EQEP_QDECCTL_QSRC_Pos)                     /*!< QSRC Get Value            */


#define EQEP_QDECCTL_SOEN_Pos    (13U)                                                                                 /*!< SOEN Postion   13         */ 
#define EQEP_QDECCTL_SOEN_Msk    (0x1U << EQEP_QDECCTL_SOEN_Pos)                                                        /*!< SOEN Mask      0x00002000 */
#define EQEP_QDECCTL_SOEN_Set(x) (((uint16_t) (x) << EQEP_QDECCTL_SOEN_Pos) & EQEP_QDECCTL_SOEN_Msk)                     /*!< SOEN Set Value            */
#define EQEP_QDECCTL_SOEN_Get(x) (((uint16_t) (x) & EQEP_QDECCTL_SOEN_Msk) >> EQEP_QDECCTL_SOEN_Pos)                     /*!< SOEN Get Value            */


#define EQEP_QDECCTL_SPSEL_Pos    (12U)                                                                                 /*!< SPSEL Postion   12         */ 
#define EQEP_QDECCTL_SPSEL_Msk    (0x1U << EQEP_QDECCTL_SPSEL_Pos)                                                       /*!< SPSEL Mask      0x00001000 */
#define EQEP_QDECCTL_SPSEL_Set(x) (((uint16_t) (x) << EQEP_QDECCTL_SPSEL_Pos) & EQEP_QDECCTL_SPSEL_Msk)                   /*!< SPSEL Set Value            */
#define EQEP_QDECCTL_SPSEL_Get(x) (((uint16_t) (x) & EQEP_QDECCTL_SPSEL_Msk) >> EQEP_QDECCTL_SPSEL_Pos)                   /*!< SPSEL Get Value            */


#define EQEP_QDECCTL_XCR_Pos    (11U)                                                                                 /*!< XCR Postion   11         */ 
#define EQEP_QDECCTL_XCR_Msk    (0x1U << EQEP_QDECCTL_XCR_Pos)                                                         /*!< XCR Mask      0x00000800 */
#define EQEP_QDECCTL_XCR_Set(x) (((uint16_t) (x) << EQEP_QDECCTL_XCR_Pos) & EQEP_QDECCTL_XCR_Msk)                       /*!< XCR Set Value            */
#define EQEP_QDECCTL_XCR_Get(x) (((uint16_t) (x) & EQEP_QDECCTL_XCR_Msk) >> EQEP_QDECCTL_XCR_Pos)                       /*!< XCR Get Value            */


#define EQEP_QDECCTL_SWAP_Pos    (10U)                                                                                 /*!< SWAP Postion   10         */ 
#define EQEP_QDECCTL_SWAP_Msk    (0x1U << EQEP_QDECCTL_SWAP_Pos)                                                        /*!< SWAP Mask      0x00000400 */
#define EQEP_QDECCTL_SWAP_Set(x) (((uint16_t) (x) << EQEP_QDECCTL_SWAP_Pos) & EQEP_QDECCTL_SWAP_Msk)                     /*!< SWAP Set Value            */
#define EQEP_QDECCTL_SWAP_Get(x) (((uint16_t) (x) & EQEP_QDECCTL_SWAP_Msk) >> EQEP_QDECCTL_SWAP_Pos)                     /*!< SWAP Get Value            */


#define EQEP_QDECCTL_IGATE_Pos    (9U)                                                                                  /*!< IGATE Postion   9          */ 
#define EQEP_QDECCTL_IGATE_Msk    (0x1U << EQEP_QDECCTL_IGATE_Pos)                                                       /*!< IGATE Mask      0x00000200 */
#define EQEP_QDECCTL_IGATE_Set(x) (((uint16_t) (x) << EQEP_QDECCTL_IGATE_Pos) & EQEP_QDECCTL_IGATE_Msk)                   /*!< IGATE Set Value            */
#define EQEP_QDECCTL_IGATE_Get(x) (((uint16_t) (x) & EQEP_QDECCTL_IGATE_Msk) >> EQEP_QDECCTL_IGATE_Pos)                   /*!< IGATE Get Value            */


#define EQEP_QDECCTL_QAP_Pos    (8U)                                                                                  /*!< QAP Postion   8          */ 
#define EQEP_QDECCTL_QAP_Msk    (0x1U << EQEP_QDECCTL_QAP_Pos)                                                         /*!< QAP Mask      0x00000100 */
#define EQEP_QDECCTL_QAP_Set(x) (((uint16_t) (x) << EQEP_QDECCTL_QAP_Pos) & EQEP_QDECCTL_QAP_Msk)                       /*!< QAP Set Value            */
#define EQEP_QDECCTL_QAP_Get(x) (((uint16_t) (x) & EQEP_QDECCTL_QAP_Msk) >> EQEP_QDECCTL_QAP_Pos)                       /*!< QAP Get Value            */


#define EQEP_QDECCTL_QBP_Pos    (7U)                                                                                  /*!< QBP Postion   7          */ 
#define EQEP_QDECCTL_QBP_Msk    (0x1U << EQEP_QDECCTL_QBP_Pos)                                                         /*!< QBP Mask      0x00000080 */
#define EQEP_QDECCTL_QBP_Set(x) (((uint16_t) (x) << EQEP_QDECCTL_QBP_Pos) & EQEP_QDECCTL_QBP_Msk)                       /*!< QBP Set Value            */
#define EQEP_QDECCTL_QBP_Get(x) (((uint16_t) (x) & EQEP_QDECCTL_QBP_Msk) >> EQEP_QDECCTL_QBP_Pos)                       /*!< QBP Get Value            */


#define EQEP_QDECCTL_QIP_Pos    (6U)                                                                                  /*!< QIP Postion   6          */ 
#define EQEP_QDECCTL_QIP_Msk    (0x1U << EQEP_QDECCTL_QIP_Pos)                                                         /*!< QIP Mask      0x00000040 */
#define EQEP_QDECCTL_QIP_Set(x) (((uint16_t) (x) << EQEP_QDECCTL_QIP_Pos) & EQEP_QDECCTL_QIP_Msk)                       /*!< QIP Set Value            */
#define EQEP_QDECCTL_QIP_Get(x) (((uint16_t) (x) & EQEP_QDECCTL_QIP_Msk) >> EQEP_QDECCTL_QIP_Pos)                       /*!< QIP Get Value            */


#define EQEP_QDECCTL_QSP_Pos    (5U)                                                                                  /*!< QSP Postion   5          */ 
#define EQEP_QDECCTL_QSP_Msk    (0x1U << EQEP_QDECCTL_QSP_Pos)                                                         /*!< QSP Mask      0x00000020 */
#define EQEP_QDECCTL_QSP_Set(x) (((uint16_t) (x) << EQEP_QDECCTL_QSP_Pos) & EQEP_QDECCTL_QSP_Msk)                       /*!< QSP Set Value            */
#define EQEP_QDECCTL_QSP_Get(x) (((uint16_t) (x) & EQEP_QDECCTL_QSP_Msk) >> EQEP_QDECCTL_QSP_Pos)                       /*!< QSP Get Value            */


#define EQEP_QDECCTL_QIDIRE_Pos    (0U)                                                                                  /*!< QIDIRE Postion   0          */ 
#define EQEP_QDECCTL_QIDIRE_Msk    (0x1U << EQEP_QDECCTL_QIDIRE_Pos)                                                      /*!< QIDIRE Mask      0x00000001 */
#define EQEP_QDECCTL_QIDIRE_Set(x) (((uint16_t) (x) << EQEP_QDECCTL_QIDIRE_Pos) & EQEP_QDECCTL_QIDIRE_Msk)                 /*!< QIDIRE Set Value            */
#define EQEP_QDECCTL_QIDIRE_Get(x) (((uint16_t) (x) & EQEP_QDECCTL_QIDIRE_Msk) >> EQEP_QDECCTL_QIDIRE_Pos)                 /*!< QIDIRE Get Value            */


/* QEPCTL bitfield */
#define EQEP_QEPCTL_FREE_SOFT_Pos    (14U)                                                                                 /*!< FREE_SOFT Postion   14         */ 
#define EQEP_QEPCTL_FREE_SOFT_Msk    (0x3U << EQEP_QEPCTL_FREE_SOFT_Pos)                                                    /*!< FREE_SOFT Mask      0x0000C000 */
#define EQEP_QEPCTL_FREE_SOFT_Set(x) (((uint16_t) (x) << EQEP_QEPCTL_FREE_SOFT_Pos) & EQEP_QEPCTL_FREE_SOFT_Msk)             /*!< FREE_SOFT Set Value            */
#define EQEP_QEPCTL_FREE_SOFT_Get(x) (((uint16_t) (x) & EQEP_QEPCTL_FREE_SOFT_Msk) >> EQEP_QEPCTL_FREE_SOFT_Pos)             /*!< FREE_SOFT Get Value            */


#define EQEP_QEPCTL_PCRM_Pos    (12U)                                                                                 /*!< PCRM Postion   12         */ 
#define EQEP_QEPCTL_PCRM_Msk    (0x3U << EQEP_QEPCTL_PCRM_Pos)                                                         /*!< PCRM Mask      0x00003000 */
#define EQEP_QEPCTL_PCRM_Set(x) (((uint16_t) (x) << EQEP_QEPCTL_PCRM_Pos) & EQEP_QEPCTL_PCRM_Msk)                       /*!< PCRM Set Value            */
#define EQEP_QEPCTL_PCRM_Get(x) (((uint16_t) (x) & EQEP_QEPCTL_PCRM_Msk) >> EQEP_QEPCTL_PCRM_Pos)                       /*!< PCRM Get Value            */


#define EQEP_QEPCTL_SEI_Pos    (10U)                                                                                 /*!< SEI Postion   10         */ 
#define EQEP_QEPCTL_SEI_Msk    (0x3U << EQEP_QEPCTL_SEI_Pos)                                                          /*!< SEI Mask      0x00000C00 */
#define EQEP_QEPCTL_SEI_Set(x) (((uint16_t) (x) << EQEP_QEPCTL_SEI_Pos) & EQEP_QEPCTL_SEI_Msk)                         /*!< SEI Set Value            */
#define EQEP_QEPCTL_SEI_Get(x) (((uint16_t) (x) & EQEP_QEPCTL_SEI_Msk) >> EQEP_QEPCTL_SEI_Pos)                         /*!< SEI Get Value            */


#define EQEP_QEPCTL_IEI_Pos    (8U)                                                                                  /*!< IEI Postion   8          */ 
#define EQEP_QEPCTL_IEI_Msk    (0x3U << EQEP_QEPCTL_IEI_Pos)                                                          /*!< IEI Mask      0x00000300 */
#define EQEP_QEPCTL_IEI_Set(x) (((uint16_t) (x) << EQEP_QEPCTL_IEI_Pos) & EQEP_QEPCTL_IEI_Msk)                         /*!< IEI Set Value            */
#define EQEP_QEPCTL_IEI_Get(x) (((uint16_t) (x) & EQEP_QEPCTL_IEI_Msk) >> EQEP_QEPCTL_IEI_Pos)                         /*!< IEI Get Value            */


#define EQEP_QEPCTL_SWI_Pos    (7U)                                                                                  /*!< SWI Postion   7          */ 
#define EQEP_QEPCTL_SWI_Msk    (0x1U << EQEP_QEPCTL_SWI_Pos)                                                          /*!< SWI Mask      0x00000080 */
#define EQEP_QEPCTL_SWI_Set(x) (((uint16_t) (x) << EQEP_QEPCTL_SWI_Pos) & EQEP_QEPCTL_SWI_Msk)                         /*!< SWI Set Value            */
#define EQEP_QEPCTL_SWI_Get(x) (((uint16_t) (x) & EQEP_QEPCTL_SWI_Msk) >> EQEP_QEPCTL_SWI_Pos)                         /*!< SWI Get Value            */


#define EQEP_QEPCTL_SEL_Pos    (6U)                                                                                  /*!< SEL Postion   6          */ 
#define EQEP_QEPCTL_SEL_Msk    (0x1U << EQEP_QEPCTL_SEL_Pos)                                                          /*!< SEL Mask      0x00000040 */
#define EQEP_QEPCTL_SEL_Set(x) (((uint16_t) (x) << EQEP_QEPCTL_SEL_Pos) & EQEP_QEPCTL_SEL_Msk)                         /*!< SEL Set Value            */
#define EQEP_QEPCTL_SEL_Get(x) (((uint16_t) (x) & EQEP_QEPCTL_SEL_Msk) >> EQEP_QEPCTL_SEL_Pos)                         /*!< SEL Get Value            */


#define EQEP_QEPCTL_IEL_Pos    (4U)                                                                                  /*!< IEL Postion   4          */ 
#define EQEP_QEPCTL_IEL_Msk    (0x3U << EQEP_QEPCTL_IEL_Pos)                                                          /*!< IEL Mask      0x00000030 */
#define EQEP_QEPCTL_IEL_Set(x) (((uint16_t) (x) << EQEP_QEPCTL_IEL_Pos) & EQEP_QEPCTL_IEL_Msk)                         /*!< IEL Set Value            */
#define EQEP_QEPCTL_IEL_Get(x) (((uint16_t) (x) & EQEP_QEPCTL_IEL_Msk) >> EQEP_QEPCTL_IEL_Pos)                         /*!< IEL Get Value            */


#define EQEP_QEPCTL_QPEN_Pos    (3U)                                                                                  /*!< QPEN Postion   3          */ 
#define EQEP_QEPCTL_QPEN_Msk    (0x1U << EQEP_QEPCTL_QPEN_Pos)                                                         /*!< QPEN Mask      0x00000008 */
#define EQEP_QEPCTL_QPEN_Set(x) (((uint16_t) (x) << EQEP_QEPCTL_QPEN_Pos) & EQEP_QEPCTL_QPEN_Msk)                       /*!< QPEN Set Value            */
#define EQEP_QEPCTL_QPEN_Get(x) (((uint16_t) (x) & EQEP_QEPCTL_QPEN_Msk) >> EQEP_QEPCTL_QPEN_Pos)                       /*!< QPEN Get Value            */


#define EQEP_QEPCTL_QCLM_Pos    (2U)                                                                                  /*!< QCLM Postion   2          */ 
#define EQEP_QEPCTL_QCLM_Msk    (0x1U << EQEP_QEPCTL_QCLM_Pos)                                                         /*!< QCLM Mask      0x00000004 */
#define EQEP_QEPCTL_QCLM_Set(x) (((uint16_t) (x) << EQEP_QEPCTL_QCLM_Pos) & EQEP_QEPCTL_QCLM_Msk)                       /*!< QCLM Set Value            */
#define EQEP_QEPCTL_QCLM_Get(x) (((uint16_t) (x) & EQEP_QEPCTL_QCLM_Msk) >> EQEP_QEPCTL_QCLM_Pos)                       /*!< QCLM Get Value            */


#define EQEP_QEPCTL_UTE_Pos    (1U)                                                                                  /*!< UTE Postion   1          */ 
#define EQEP_QEPCTL_UTE_Msk    (0x1U << EQEP_QEPCTL_UTE_Pos)                                                          /*!< UTE Mask      0x00000002 */
#define EQEP_QEPCTL_UTE_Set(x) (((uint16_t) (x) << EQEP_QEPCTL_UTE_Pos) & EQEP_QEPCTL_UTE_Msk)                         /*!< UTE Set Value            */
#define EQEP_QEPCTL_UTE_Get(x) (((uint16_t) (x) & EQEP_QEPCTL_UTE_Msk) >> EQEP_QEPCTL_UTE_Pos)                         /*!< UTE Get Value            */


#define EQEP_QEPCTL_WDE_Pos    (0U)                                                                                  /*!< WDE Postion   0          */ 
#define EQEP_QEPCTL_WDE_Msk    (0x1U << EQEP_QEPCTL_WDE_Pos)                                                          /*!< WDE Mask      0x00000001 */
#define EQEP_QEPCTL_WDE_Set(x) (((uint16_t) (x) << EQEP_QEPCTL_WDE_Pos) & EQEP_QEPCTL_WDE_Msk)                         /*!< WDE Set Value            */
#define EQEP_QEPCTL_WDE_Get(x) (((uint16_t) (x) & EQEP_QEPCTL_WDE_Msk) >> EQEP_QEPCTL_WDE_Pos)                         /*!< WDE Get Value            */


/* QCAPCTL bitfield */
#define EQEP_QCAPCTL_CEN_Pos    (15U)                                                                                 /*!< CEN Postion   15         */ 
#define EQEP_QCAPCTL_CEN_Msk    (0x1U << EQEP_QCAPCTL_CEN_Pos)                                                         /*!< CEN Mask      0x00008000 */
#define EQEP_QCAPCTL_CEN_Set(x) (((uint16_t) (x) << EQEP_QCAPCTL_CEN_Pos) & EQEP_QCAPCTL_CEN_Msk)                       /*!< CEN Set Value            */
#define EQEP_QCAPCTL_CEN_Get(x) (((uint16_t) (x) & EQEP_QCAPCTL_CEN_Msk) >> EQEP_QCAPCTL_CEN_Pos)                       /*!< CEN Get Value            */


#define EQEP_QCAPCTL_CCPS_Pos    (4U)                                                                                  /*!< CCPS Postion   4          */ 
#define EQEP_QCAPCTL_CCPS_Msk    (0x7U << EQEP_QCAPCTL_CCPS_Pos)                                                        /*!< CCPS Mask      0x00000070 */
#define EQEP_QCAPCTL_CCPS_Set(x) (((uint16_t) (x) << EQEP_QCAPCTL_CCPS_Pos) & EQEP_QCAPCTL_CCPS_Msk)                     /*!< CCPS Set Value            */
#define EQEP_QCAPCTL_CCPS_Get(x) (((uint16_t) (x) & EQEP_QCAPCTL_CCPS_Msk) >> EQEP_QCAPCTL_CCPS_Pos)                     /*!< CCPS Get Value            */


#define EQEP_QCAPCTL_UPPS_Pos    (0U)                                                                                  /*!< UPPS Postion   0          */ 
#define EQEP_QCAPCTL_UPPS_Msk    (0xfU << EQEP_QCAPCTL_UPPS_Pos)                                                        /*!< UPPS Mask      0x0000000F */
#define EQEP_QCAPCTL_UPPS_Set(x) (((uint16_t) (x) << EQEP_QCAPCTL_UPPS_Pos) & EQEP_QCAPCTL_UPPS_Msk)                     /*!< UPPS Set Value            */
#define EQEP_QCAPCTL_UPPS_Get(x) (((uint16_t) (x) & EQEP_QCAPCTL_UPPS_Msk) >> EQEP_QCAPCTL_UPPS_Pos)                     /*!< UPPS Get Value            */


/* QPOSCTL bitfield */
#define EQEP_QPOSCTL_PCSHDW_Pos    (15U)                                                                                 /*!< PCSHDW Postion   15         */ 
#define EQEP_QPOSCTL_PCSHDW_Msk    (0x1U << EQEP_QPOSCTL_PCSHDW_Pos)                                                      /*!< PCSHDW Mask      0x00008000 */
#define EQEP_QPOSCTL_PCSHDW_Set(x) (((uint16_t) (x) << EQEP_QPOSCTL_PCSHDW_Pos) & EQEP_QPOSCTL_PCSHDW_Msk)                 /*!< PCSHDW Set Value            */
#define EQEP_QPOSCTL_PCSHDW_Get(x) (((uint16_t) (x) & EQEP_QPOSCTL_PCSHDW_Msk) >> EQEP_QPOSCTL_PCSHDW_Pos)                 /*!< PCSHDW Get Value            */


#define EQEP_QPOSCTL_PCLOAD_Pos    (14U)                                                                                 /*!< PCLOAD Postion   14         */ 
#define EQEP_QPOSCTL_PCLOAD_Msk    (0x1U << EQEP_QPOSCTL_PCLOAD_Pos)                                                      /*!< PCLOAD Mask      0x00004000 */
#define EQEP_QPOSCTL_PCLOAD_Set(x) (((uint16_t) (x) << EQEP_QPOSCTL_PCLOAD_Pos) & EQEP_QPOSCTL_PCLOAD_Msk)                 /*!< PCLOAD Set Value            */
#define EQEP_QPOSCTL_PCLOAD_Get(x) (((uint16_t) (x) & EQEP_QPOSCTL_PCLOAD_Msk) >> EQEP_QPOSCTL_PCLOAD_Pos)                 /*!< PCLOAD Get Value            */


#define EQEP_QPOSCTL_PCPOL_Pos    (13U)                                                                                 /*!< PCPOL Postion   13         */ 
#define EQEP_QPOSCTL_PCPOL_Msk    (0x1U << EQEP_QPOSCTL_PCPOL_Pos)                                                       /*!< PCPOL Mask      0x00002000 */
#define EQEP_QPOSCTL_PCPOL_Set(x) (((uint16_t) (x) << EQEP_QPOSCTL_PCPOL_Pos) & EQEP_QPOSCTL_PCPOL_Msk)                   /*!< PCPOL Set Value            */
#define EQEP_QPOSCTL_PCPOL_Get(x) (((uint16_t) (x) & EQEP_QPOSCTL_PCPOL_Msk) >> EQEP_QPOSCTL_PCPOL_Pos)                   /*!< PCPOL Get Value            */


#define EQEP_QPOSCTL_PCE_Pos    (12U)                                                                                 /*!< PCE Postion   12         */ 
#define EQEP_QPOSCTL_PCE_Msk    (0x1U << EQEP_QPOSCTL_PCE_Pos)                                                         /*!< PCE Mask      0x00001000 */
#define EQEP_QPOSCTL_PCE_Set(x) (((uint16_t) (x) << EQEP_QPOSCTL_PCE_Pos) & EQEP_QPOSCTL_PCE_Msk)                       /*!< PCE Set Value            */
#define EQEP_QPOSCTL_PCE_Get(x) (((uint16_t) (x) & EQEP_QPOSCTL_PCE_Msk) >> EQEP_QPOSCTL_PCE_Pos)                       /*!< PCE Get Value            */


#define EQEP_QPOSCTL_PCSPW_Pos    (0U)                                                                                  /*!< PCSPW Postion   0          */ 
#define EQEP_QPOSCTL_PCSPW_Msk    (0xfffU << EQEP_QPOSCTL_PCSPW_Pos)                                                     /*!< PCSPW Mask      0x00000FFF */
#define EQEP_QPOSCTL_PCSPW_Set(x) (((uint16_t) (x) << EQEP_QPOSCTL_PCSPW_Pos) & EQEP_QPOSCTL_PCSPW_Msk)                   /*!< PCSPW Set Value            */
#define EQEP_QPOSCTL_PCSPW_Get(x) (((uint16_t) (x) & EQEP_QPOSCTL_PCSPW_Msk) >> EQEP_QPOSCTL_PCSPW_Pos)                   /*!< PCSPW Get Value            */


/* QEINT bitfield */
#define EQEP_QEINT_QMAE_Pos    (12U)                                                                                 /*!< QMAE Postion   12         */ 
#define EQEP_QEINT_QMAE_Msk    (0x1U << EQEP_QEINT_QMAE_Pos)                                                          /*!< QMAE Mask      0x00001000 */
#define EQEP_QEINT_QMAE_Set(x) (((uint16_t) (x) << EQEP_QEINT_QMAE_Pos) & EQEP_QEINT_QMAE_Msk)                         /*!< QMAE Set Value            */
#define EQEP_QEINT_QMAE_Get(x) (((uint16_t) (x) & EQEP_QEINT_QMAE_Msk) >> EQEP_QEINT_QMAE_Pos)                         /*!< QMAE Get Value            */


#define EQEP_QEINT_UTO_Pos    (11U)                                                                                 /*!< UTO Postion   11         */ 
#define EQEP_QEINT_UTO_Msk    (0x1U << EQEP_QEINT_UTO_Pos)                                                           /*!< UTO Mask      0x00000800 */
#define EQEP_QEINT_UTO_Set(x) (((uint16_t) (x) << EQEP_QEINT_UTO_Pos) & EQEP_QEINT_UTO_Msk)                           /*!< UTO Set Value            */
#define EQEP_QEINT_UTO_Get(x) (((uint16_t) (x) & EQEP_QEINT_UTO_Msk) >> EQEP_QEINT_UTO_Pos)                           /*!< UTO Get Value            */


#define EQEP_QEINT_IEL_Pos    (10U)                                                                                 /*!< IEL Postion   10         */ 
#define EQEP_QEINT_IEL_Msk    (0x1U << EQEP_QEINT_IEL_Pos)                                                           /*!< IEL Mask      0x00000400 */
#define EQEP_QEINT_IEL_Set(x) (((uint16_t) (x) << EQEP_QEINT_IEL_Pos) & EQEP_QEINT_IEL_Msk)                           /*!< IEL Set Value            */
#define EQEP_QEINT_IEL_Get(x) (((uint16_t) (x) & EQEP_QEINT_IEL_Msk) >> EQEP_QEINT_IEL_Pos)                           /*!< IEL Get Value            */


#define EQEP_QEINT_SEL_Pos    (9U)                                                                                  /*!< SEL Postion   9          */ 
#define EQEP_QEINT_SEL_Msk    (0x1U << EQEP_QEINT_SEL_Pos)                                                           /*!< SEL Mask      0x00000200 */
#define EQEP_QEINT_SEL_Set(x) (((uint16_t) (x) << EQEP_QEINT_SEL_Pos) & EQEP_QEINT_SEL_Msk)                           /*!< SEL Set Value            */
#define EQEP_QEINT_SEL_Get(x) (((uint16_t) (x) & EQEP_QEINT_SEL_Msk) >> EQEP_QEINT_SEL_Pos)                           /*!< SEL Get Value            */


#define EQEP_QEINT_PCM_Pos    (8U)                                                                                  /*!< PCM Postion   8          */ 
#define EQEP_QEINT_PCM_Msk    (0x1U << EQEP_QEINT_PCM_Pos)                                                           /*!< PCM Mask      0x00000100 */
#define EQEP_QEINT_PCM_Set(x) (((uint16_t) (x) << EQEP_QEINT_PCM_Pos) & EQEP_QEINT_PCM_Msk)                           /*!< PCM Set Value            */
#define EQEP_QEINT_PCM_Get(x) (((uint16_t) (x) & EQEP_QEINT_PCM_Msk) >> EQEP_QEINT_PCM_Pos)                           /*!< PCM Get Value            */


#define EQEP_QEINT_PCR_Pos    (7U)                                                                                  /*!< PCR Postion   7          */ 
#define EQEP_QEINT_PCR_Msk    (0x1U << EQEP_QEINT_PCR_Pos)                                                           /*!< PCR Mask      0x00000080 */
#define EQEP_QEINT_PCR_Set(x) (((uint16_t) (x) << EQEP_QEINT_PCR_Pos) & EQEP_QEINT_PCR_Msk)                           /*!< PCR Set Value            */
#define EQEP_QEINT_PCR_Get(x) (((uint16_t) (x) & EQEP_QEINT_PCR_Msk) >> EQEP_QEINT_PCR_Pos)                           /*!< PCR Get Value            */


#define EQEP_QEINT_PCO_Pos    (6U)                                                                                  /*!< PCO Postion   6          */ 
#define EQEP_QEINT_PCO_Msk    (0x1U << EQEP_QEINT_PCO_Pos)                                                           /*!< PCO Mask      0x00000040 */
#define EQEP_QEINT_PCO_Set(x) (((uint16_t) (x) << EQEP_QEINT_PCO_Pos) & EQEP_QEINT_PCO_Msk)                           /*!< PCO Set Value            */
#define EQEP_QEINT_PCO_Get(x) (((uint16_t) (x) & EQEP_QEINT_PCO_Msk) >> EQEP_QEINT_PCO_Pos)                           /*!< PCO Get Value            */


#define EQEP_QEINT_PCU_Pos    (5U)                                                                                  /*!< PCU Postion   5          */ 
#define EQEP_QEINT_PCU_Msk    (0x1U << EQEP_QEINT_PCU_Pos)                                                           /*!< PCU Mask      0x00000020 */
#define EQEP_QEINT_PCU_Set(x) (((uint16_t) (x) << EQEP_QEINT_PCU_Pos) & EQEP_QEINT_PCU_Msk)                           /*!< PCU Set Value            */
#define EQEP_QEINT_PCU_Get(x) (((uint16_t) (x) & EQEP_QEINT_PCU_Msk) >> EQEP_QEINT_PCU_Pos)                           /*!< PCU Get Value            */


#define EQEP_QEINT_WTO_Pos    (4U)                                                                                  /*!< WTO Postion   4          */ 
#define EQEP_QEINT_WTO_Msk    (0x1U << EQEP_QEINT_WTO_Pos)                                                           /*!< WTO Mask      0x00000010 */
#define EQEP_QEINT_WTO_Set(x) (((uint16_t) (x) << EQEP_QEINT_WTO_Pos) & EQEP_QEINT_WTO_Msk)                           /*!< WTO Set Value            */
#define EQEP_QEINT_WTO_Get(x) (((uint16_t) (x) & EQEP_QEINT_WTO_Msk) >> EQEP_QEINT_WTO_Pos)                           /*!< WTO Get Value            */


#define EQEP_QEINT_QDC_Pos    (3U)                                                                                  /*!< QDC Postion   3          */ 
#define EQEP_QEINT_QDC_Msk    (0x1U << EQEP_QEINT_QDC_Pos)                                                           /*!< QDC Mask      0x00000008 */
#define EQEP_QEINT_QDC_Set(x) (((uint16_t) (x) << EQEP_QEINT_QDC_Pos) & EQEP_QEINT_QDC_Msk)                           /*!< QDC Set Value            */
#define EQEP_QEINT_QDC_Get(x) (((uint16_t) (x) & EQEP_QEINT_QDC_Msk) >> EQEP_QEINT_QDC_Pos)                           /*!< QDC Get Value            */


#define EQEP_QEINT_QPE_Pos    (2U)                                                                                  /*!< QPE Postion   2          */ 
#define EQEP_QEINT_QPE_Msk    (0x1U << EQEP_QEINT_QPE_Pos)                                                           /*!< QPE Mask      0x00000004 */
#define EQEP_QEINT_QPE_Set(x) (((uint16_t) (x) << EQEP_QEINT_QPE_Pos) & EQEP_QEINT_QPE_Msk)                           /*!< QPE Set Value            */
#define EQEP_QEINT_QPE_Get(x) (((uint16_t) (x) & EQEP_QEINT_QPE_Msk) >> EQEP_QEINT_QPE_Pos)                           /*!< QPE Get Value            */


#define EQEP_QEINT_PCE_Pos    (1U)                                                                                  /*!< PCE Postion   1          */ 
#define EQEP_QEINT_PCE_Msk    (0x1U << EQEP_QEINT_PCE_Pos)                                                           /*!< PCE Mask      0x00000002 */
#define EQEP_QEINT_PCE_Set(x) (((uint16_t) (x) << EQEP_QEINT_PCE_Pos) & EQEP_QEINT_PCE_Msk)                           /*!< PCE Set Value            */
#define EQEP_QEINT_PCE_Get(x) (((uint16_t) (x) & EQEP_QEINT_PCE_Msk) >> EQEP_QEINT_PCE_Pos)                           /*!< PCE Get Value            */


/* QFLG bitfield */
#define EQEP_QFLG_QMAE_Pos    (12U)                                                                                 /*!< QMAE Postion   12         */ 
#define EQEP_QFLG_QMAE_Msk    (0x1U << EQEP_QFLG_QMAE_Pos)                                                           /*!< QMAE Mask      0x00001000 */
#define EQEP_QFLG_QMAE_Set(x) (((uint16_t) (x) << EQEP_QFLG_QMAE_Pos) & EQEP_QFLG_QMAE_Msk)                           /*!< QMAE Set Value            */
#define EQEP_QFLG_QMAE_Get(x) (((uint16_t) (x) & EQEP_QFLG_QMAE_Msk) >> EQEP_QFLG_QMAE_Pos)                           /*!< QMAE Get Value            */


#define EQEP_QFLG_UTO_Pos    (11U)                                                                                 /*!< UTO Postion   11         */ 
#define EQEP_QFLG_UTO_Msk    (0x1U << EQEP_QFLG_UTO_Pos)                                                            /*!< UTO Mask      0x00000800 */
#define EQEP_QFLG_UTO_Set(x) (((uint16_t) (x) << EQEP_QFLG_UTO_Pos) & EQEP_QFLG_UTO_Msk)                             /*!< UTO Set Value            */
#define EQEP_QFLG_UTO_Get(x) (((uint16_t) (x) & EQEP_QFLG_UTO_Msk) >> EQEP_QFLG_UTO_Pos)                             /*!< UTO Get Value            */


#define EQEP_QFLG_IEL_Pos    (10U)                                                                                 /*!< IEL Postion   10         */ 
#define EQEP_QFLG_IEL_Msk    (0x1U << EQEP_QFLG_IEL_Pos)                                                            /*!< IEL Mask      0x00000400 */
#define EQEP_QFLG_IEL_Set(x) (((uint16_t) (x) << EQEP_QFLG_IEL_Pos) & EQEP_QFLG_IEL_Msk)                             /*!< IEL Set Value            */
#define EQEP_QFLG_IEL_Get(x) (((uint16_t) (x) & EQEP_QFLG_IEL_Msk) >> EQEP_QFLG_IEL_Pos)                             /*!< IEL Get Value            */


#define EQEP_QFLG_SEL_Pos    (9U)                                                                                  /*!< SEL Postion   9          */ 
#define EQEP_QFLG_SEL_Msk    (0x1U << EQEP_QFLG_SEL_Pos)                                                            /*!< SEL Mask      0x00000200 */
#define EQEP_QFLG_SEL_Set(x) (((uint16_t) (x) << EQEP_QFLG_SEL_Pos) & EQEP_QFLG_SEL_Msk)                             /*!< SEL Set Value            */
#define EQEP_QFLG_SEL_Get(x) (((uint16_t) (x) & EQEP_QFLG_SEL_Msk) >> EQEP_QFLG_SEL_Pos)                             /*!< SEL Get Value            */


#define EQEP_QFLG_PCM_Pos    (8U)                                                                                  /*!< PCM Postion   8          */ 
#define EQEP_QFLG_PCM_Msk    (0x1U << EQEP_QFLG_PCM_Pos)                                                            /*!< PCM Mask      0x00000100 */
#define EQEP_QFLG_PCM_Set(x) (((uint16_t) (x) << EQEP_QFLG_PCM_Pos) & EQEP_QFLG_PCM_Msk)                             /*!< PCM Set Value            */
#define EQEP_QFLG_PCM_Get(x) (((uint16_t) (x) & EQEP_QFLG_PCM_Msk) >> EQEP_QFLG_PCM_Pos)                             /*!< PCM Get Value            */


#define EQEP_QFLG_PCR_Pos    (7U)                                                                                  /*!< PCR Postion   7          */ 
#define EQEP_QFLG_PCR_Msk    (0x1U << EQEP_QFLG_PCR_Pos)                                                            /*!< PCR Mask      0x00000080 */
#define EQEP_QFLG_PCR_Set(x) (((uint16_t) (x) << EQEP_QFLG_PCR_Pos) & EQEP_QFLG_PCR_Msk)                             /*!< PCR Set Value            */
#define EQEP_QFLG_PCR_Get(x) (((uint16_t) (x) & EQEP_QFLG_PCR_Msk) >> EQEP_QFLG_PCR_Pos)                             /*!< PCR Get Value            */


#define EQEP_QFLG_PCO_Pos    (6U)                                                                                  /*!< PCO Postion   6          */ 
#define EQEP_QFLG_PCO_Msk    (0x1U << EQEP_QFLG_PCO_Pos)                                                            /*!< PCO Mask      0x00000040 */
#define EQEP_QFLG_PCO_Set(x) (((uint16_t) (x) << EQEP_QFLG_PCO_Pos) & EQEP_QFLG_PCO_Msk)                             /*!< PCO Set Value            */
#define EQEP_QFLG_PCO_Get(x) (((uint16_t) (x) & EQEP_QFLG_PCO_Msk) >> EQEP_QFLG_PCO_Pos)                             /*!< PCO Get Value            */


#define EQEP_QFLG_PCU_Pos    (5U)                                                                                  /*!< PCU Postion   5          */ 
#define EQEP_QFLG_PCU_Msk    (0x1U << EQEP_QFLG_PCU_Pos)                                                            /*!< PCU Mask      0x00000020 */
#define EQEP_QFLG_PCU_Set(x) (((uint16_t) (x) << EQEP_QFLG_PCU_Pos) & EQEP_QFLG_PCU_Msk)                             /*!< PCU Set Value            */
#define EQEP_QFLG_PCU_Get(x) (((uint16_t) (x) & EQEP_QFLG_PCU_Msk) >> EQEP_QFLG_PCU_Pos)                             /*!< PCU Get Value            */


#define EQEP_QFLG_WTO_Pos    (4U)                                                                                  /*!< WTO Postion   4          */ 
#define EQEP_QFLG_WTO_Msk    (0x1U << EQEP_QFLG_WTO_Pos)                                                            /*!< WTO Mask      0x00000010 */
#define EQEP_QFLG_WTO_Set(x) (((uint16_t) (x) << EQEP_QFLG_WTO_Pos) & EQEP_QFLG_WTO_Msk)                             /*!< WTO Set Value            */
#define EQEP_QFLG_WTO_Get(x) (((uint16_t) (x) & EQEP_QFLG_WTO_Msk) >> EQEP_QFLG_WTO_Pos)                             /*!< WTO Get Value            */


#define EQEP_QFLG_QDC_Pos    (3U)                                                                                  /*!< QDC Postion   3          */ 
#define EQEP_QFLG_QDC_Msk    (0x1U << EQEP_QFLG_QDC_Pos)                                                            /*!< QDC Mask      0x00000008 */
#define EQEP_QFLG_QDC_Set(x) (((uint16_t) (x) << EQEP_QFLG_QDC_Pos) & EQEP_QFLG_QDC_Msk)                             /*!< QDC Set Value            */
#define EQEP_QFLG_QDC_Get(x) (((uint16_t) (x) & EQEP_QFLG_QDC_Msk) >> EQEP_QFLG_QDC_Pos)                             /*!< QDC Get Value            */


#define EQEP_QFLG_PHE_Pos    (2U)                                                                                  /*!< PHE Postion   2          */ 
#define EQEP_QFLG_PHE_Msk    (0x1U << EQEP_QFLG_PHE_Pos)                                                            /*!< PHE Mask      0x00000004 */
#define EQEP_QFLG_PHE_Set(x) (((uint16_t) (x) << EQEP_QFLG_PHE_Pos) & EQEP_QFLG_PHE_Msk)                             /*!< PHE Set Value            */
#define EQEP_QFLG_PHE_Get(x) (((uint16_t) (x) & EQEP_QFLG_PHE_Msk) >> EQEP_QFLG_PHE_Pos)                             /*!< PHE Get Value            */


#define EQEP_QFLG_PCE_Pos    (1U)                                                                                  /*!< PCE Postion   1          */ 
#define EQEP_QFLG_PCE_Msk    (0x1U << EQEP_QFLG_PCE_Pos)                                                            /*!< PCE Mask      0x00000002 */
#define EQEP_QFLG_PCE_Set(x) (((uint16_t) (x) << EQEP_QFLG_PCE_Pos) & EQEP_QFLG_PCE_Msk)                             /*!< PCE Set Value            */
#define EQEP_QFLG_PCE_Get(x) (((uint16_t) (x) & EQEP_QFLG_PCE_Msk) >> EQEP_QFLG_PCE_Pos)                             /*!< PCE Get Value            */


#define EQEP_QFLG_EQEPINT_Pos    (0U)                                                                                  /*!< EQEPINT Postion   0          */ 
#define EQEP_QFLG_EQEPINT_Msk    (0x1U << EQEP_QFLG_EQEPINT_Pos)                                                         /*!< EQEPINT Mask      0x00000001 */
#define EQEP_QFLG_EQEPINT_Set(x) (((uint16_t) (x) << EQEP_QFLG_EQEPINT_Pos) & EQEP_QFLG_EQEPINT_Msk)                       /*!< EQEPINT Set Value            */
#define EQEP_QFLG_EQEPINT_Get(x) (((uint16_t) (x) & EQEP_QFLG_EQEPINT_Msk) >> EQEP_QFLG_EQEPINT_Pos)                       /*!< EQEPINT Get Value            */


/* QCLR bitfield */
#define EQEP_QCLR_QMAE_Pos    (12U)                                                                                 /*!< QMAE Postion   12         */ 
#define EQEP_QCLR_QMAE_Msk    (0x1U << EQEP_QCLR_QMAE_Pos)                                                           /*!< QMAE Mask      0x00001000 */
#define EQEP_QCLR_QMAE_Set(x) (((uint16_t) (x) << EQEP_QCLR_QMAE_Pos) & EQEP_QCLR_QMAE_Msk)                           /*!< QMAE Set Value            */
#define EQEP_QCLR_QMAE_Get(x) (((uint16_t) (x) & EQEP_QCLR_QMAE_Msk) >> EQEP_QCLR_QMAE_Pos)                           /*!< QMAE Get Value            */


#define EQEP_QCLR_UTO_Pos    (11U)                                                                                 /*!< UTO Postion   11         */ 
#define EQEP_QCLR_UTO_Msk    (0x1U << EQEP_QCLR_UTO_Pos)                                                            /*!< UTO Mask      0x00000800 */
#define EQEP_QCLR_UTO_Set(x) (((uint16_t) (x) << EQEP_QCLR_UTO_Pos) & EQEP_QCLR_UTO_Msk)                             /*!< UTO Set Value            */
#define EQEP_QCLR_UTO_Get(x) (((uint16_t) (x) & EQEP_QCLR_UTO_Msk) >> EQEP_QCLR_UTO_Pos)                             /*!< UTO Get Value            */


#define EQEP_QCLR_IEL_Pos    (10U)                                                                                 /*!< IEL Postion   10         */ 
#define EQEP_QCLR_IEL_Msk    (0x1U << EQEP_QCLR_IEL_Pos)                                                            /*!< IEL Mask      0x00000400 */
#define EQEP_QCLR_IEL_Set(x) (((uint16_t) (x) << EQEP_QCLR_IEL_Pos) & EQEP_QCLR_IEL_Msk)                             /*!< IEL Set Value            */
#define EQEP_QCLR_IEL_Get(x) (((uint16_t) (x) & EQEP_QCLR_IEL_Msk) >> EQEP_QCLR_IEL_Pos)                             /*!< IEL Get Value            */


#define EQEP_QCLR_SEL_Pos    (9U)                                                                                  /*!< SEL Postion   9          */ 
#define EQEP_QCLR_SEL_Msk    (0x1U << EQEP_QCLR_SEL_Pos)                                                            /*!< SEL Mask      0x00000200 */
#define EQEP_QCLR_SEL_Set(x) (((uint16_t) (x) << EQEP_QCLR_SEL_Pos) & EQEP_QCLR_SEL_Msk)                             /*!< SEL Set Value            */
#define EQEP_QCLR_SEL_Get(x) (((uint16_t) (x) & EQEP_QCLR_SEL_Msk) >> EQEP_QCLR_SEL_Pos)                             /*!< SEL Get Value            */


#define EQEP_QCLR_PCM_Pos    (8U)                                                                                  /*!< PCM Postion   8          */ 
#define EQEP_QCLR_PCM_Msk    (0x1U << EQEP_QCLR_PCM_Pos)                                                            /*!< PCM Mask      0x00000100 */
#define EQEP_QCLR_PCM_Set(x) (((uint16_t) (x) << EQEP_QCLR_PCM_Pos) & EQEP_QCLR_PCM_Msk)                             /*!< PCM Set Value            */
#define EQEP_QCLR_PCM_Get(x) (((uint16_t) (x) & EQEP_QCLR_PCM_Msk) >> EQEP_QCLR_PCM_Pos)                             /*!< PCM Get Value            */


#define EQEP_QCLR_PCR_Pos    (7U)                                                                                  /*!< PCR Postion   7          */ 
#define EQEP_QCLR_PCR_Msk    (0x1U << EQEP_QCLR_PCR_Pos)                                                            /*!< PCR Mask      0x00000080 */
#define EQEP_QCLR_PCR_Set(x) (((uint16_t) (x) << EQEP_QCLR_PCR_Pos) & EQEP_QCLR_PCR_Msk)                             /*!< PCR Set Value            */
#define EQEP_QCLR_PCR_Get(x) (((uint16_t) (x) & EQEP_QCLR_PCR_Msk) >> EQEP_QCLR_PCR_Pos)                             /*!< PCR Get Value            */


#define EQEP_QCLR_PCO_Pos    (6U)                                                                                  /*!< PCO Postion   6          */ 
#define EQEP_QCLR_PCO_Msk    (0x1U << EQEP_QCLR_PCO_Pos)                                                            /*!< PCO Mask      0x00000040 */
#define EQEP_QCLR_PCO_Set(x) (((uint16_t) (x) << EQEP_QCLR_PCO_Pos) & EQEP_QCLR_PCO_Msk)                             /*!< PCO Set Value            */
#define EQEP_QCLR_PCO_Get(x) (((uint16_t) (x) & EQEP_QCLR_PCO_Msk) >> EQEP_QCLR_PCO_Pos)                             /*!< PCO Get Value            */


#define EQEP_QCLR_PCU_Pos    (5U)                                                                                  /*!< PCU Postion   5          */ 
#define EQEP_QCLR_PCU_Msk    (0x1U << EQEP_QCLR_PCU_Pos)                                                            /*!< PCU Mask      0x00000020 */
#define EQEP_QCLR_PCU_Set(x) (((uint16_t) (x) << EQEP_QCLR_PCU_Pos) & EQEP_QCLR_PCU_Msk)                             /*!< PCU Set Value            */
#define EQEP_QCLR_PCU_Get(x) (((uint16_t) (x) & EQEP_QCLR_PCU_Msk) >> EQEP_QCLR_PCU_Pos)                             /*!< PCU Get Value            */


#define EQEP_QCLR_WTO_Pos    (4U)                                                                                  /*!< WTO Postion   4          */ 
#define EQEP_QCLR_WTO_Msk    (0x1U << EQEP_QCLR_WTO_Pos)                                                            /*!< WTO Mask      0x00000010 */
#define EQEP_QCLR_WTO_Set(x) (((uint16_t) (x) << EQEP_QCLR_WTO_Pos) & EQEP_QCLR_WTO_Msk)                             /*!< WTO Set Value            */
#define EQEP_QCLR_WTO_Get(x) (((uint16_t) (x) & EQEP_QCLR_WTO_Msk) >> EQEP_QCLR_WTO_Pos)                             /*!< WTO Get Value            */


#define EQEP_QCLR_QDC_Pos    (3U)                                                                                  /*!< QDC Postion   3          */ 
#define EQEP_QCLR_QDC_Msk    (0x1U << EQEP_QCLR_QDC_Pos)                                                            /*!< QDC Mask      0x00000008 */
#define EQEP_QCLR_QDC_Set(x) (((uint16_t) (x) << EQEP_QCLR_QDC_Pos) & EQEP_QCLR_QDC_Msk)                             /*!< QDC Set Value            */
#define EQEP_QCLR_QDC_Get(x) (((uint16_t) (x) & EQEP_QCLR_QDC_Msk) >> EQEP_QCLR_QDC_Pos)                             /*!< QDC Get Value            */


#define EQEP_QCLR_PHE_Pos    (2U)                                                                                  /*!< PHE Postion   2          */ 
#define EQEP_QCLR_PHE_Msk    (0x1U << EQEP_QCLR_PHE_Pos)                                                            /*!< PHE Mask      0x00000004 */
#define EQEP_QCLR_PHE_Set(x) (((uint16_t) (x) << EQEP_QCLR_PHE_Pos) & EQEP_QCLR_PHE_Msk)                             /*!< PHE Set Value            */
#define EQEP_QCLR_PHE_Get(x) (((uint16_t) (x) & EQEP_QCLR_PHE_Msk) >> EQEP_QCLR_PHE_Pos)                             /*!< PHE Get Value            */


#define EQEP_QCLR_PCE_Pos    (1U)                                                                                  /*!< PCE Postion   1          */ 
#define EQEP_QCLR_PCE_Msk    (0x1U << EQEP_QCLR_PCE_Pos)                                                            /*!< PCE Mask      0x00000002 */
#define EQEP_QCLR_PCE_Set(x) (((uint16_t) (x) << EQEP_QCLR_PCE_Pos) & EQEP_QCLR_PCE_Msk)                             /*!< PCE Set Value            */
#define EQEP_QCLR_PCE_Get(x) (((uint16_t) (x) & EQEP_QCLR_PCE_Msk) >> EQEP_QCLR_PCE_Pos)                             /*!< PCE Get Value            */


#define EQEP_QCLR_INTCLR_Pos    (0U)                                                                                  /*!< INTCLR Postion   0          */ 
#define EQEP_QCLR_INTCLR_Msk    (0x1U << EQEP_QCLR_INTCLR_Pos)                                                         /*!< INTCLR Mask      0x00000001 */
#define EQEP_QCLR_INTCLR_Set(x) (((uint16_t) (x) << EQEP_QCLR_INTCLR_Pos) & EQEP_QCLR_INTCLR_Msk)                       /*!< INTCLR Set Value            */
#define EQEP_QCLR_INTCLR_Get(x) (((uint16_t) (x) & EQEP_QCLR_INTCLR_Msk) >> EQEP_QCLR_INTCLR_Pos)                       /*!< INTCLR Get Value            */


/* QFRC bitfield */
#define EQEP_QFRC_QMAE_Pos    (12U)                                                                                 /*!< QMAE Postion   12         */ 
#define EQEP_QFRC_QMAE_Msk    (0x1U << EQEP_QFRC_QMAE_Pos)                                                           /*!< QMAE Mask      0x00001000 */
#define EQEP_QFRC_QMAE_Set(x) (((uint16_t) (x) << EQEP_QFRC_QMAE_Pos) & EQEP_QFRC_QMAE_Msk)                           /*!< QMAE Set Value            */
#define EQEP_QFRC_QMAE_Get(x) (((uint16_t) (x) & EQEP_QFRC_QMAE_Msk) >> EQEP_QFRC_QMAE_Pos)                           /*!< QMAE Get Value            */


#define EQEP_QFRC_UTO_Pos    (11U)                                                                                 /*!< UTO Postion   11         */ 
#define EQEP_QFRC_UTO_Msk    (0x1U << EQEP_QFRC_UTO_Pos)                                                            /*!< UTO Mask      0x00000800 */
#define EQEP_QFRC_UTO_Set(x) (((uint16_t) (x) << EQEP_QFRC_UTO_Pos) & EQEP_QFRC_UTO_Msk)                             /*!< UTO Set Value            */
#define EQEP_QFRC_UTO_Get(x) (((uint16_t) (x) & EQEP_QFRC_UTO_Msk) >> EQEP_QFRC_UTO_Pos)                             /*!< UTO Get Value            */


#define EQEP_QFRC_IEL_Pos    (10U)                                                                                 /*!< IEL Postion   10         */ 
#define EQEP_QFRC_IEL_Msk    (0x1U << EQEP_QFRC_IEL_Pos)                                                            /*!< IEL Mask      0x00000400 */
#define EQEP_QFRC_IEL_Set(x) (((uint16_t) (x) << EQEP_QFRC_IEL_Pos) & EQEP_QFRC_IEL_Msk)                             /*!< IEL Set Value            */
#define EQEP_QFRC_IEL_Get(x) (((uint16_t) (x) & EQEP_QFRC_IEL_Msk) >> EQEP_QFRC_IEL_Pos)                             /*!< IEL Get Value            */


#define EQEP_QFRC_SEL_Pos    (9U)                                                                                  /*!< SEL Postion   9          */ 
#define EQEP_QFRC_SEL_Msk    (0x1U << EQEP_QFRC_SEL_Pos)                                                            /*!< SEL Mask      0x00000200 */
#define EQEP_QFRC_SEL_Set(x) (((uint16_t) (x) << EQEP_QFRC_SEL_Pos) & EQEP_QFRC_SEL_Msk)                             /*!< SEL Set Value            */
#define EQEP_QFRC_SEL_Get(x) (((uint16_t) (x) & EQEP_QFRC_SEL_Msk) >> EQEP_QFRC_SEL_Pos)                             /*!< SEL Get Value            */


#define EQEP_QFRC_PCM_Pos    (8U)                                                                                  /*!< PCM Postion   8          */ 
#define EQEP_QFRC_PCM_Msk    (0x1U << EQEP_QFRC_PCM_Pos)                                                            /*!< PCM Mask      0x00000100 */
#define EQEP_QFRC_PCM_Set(x) (((uint16_t) (x) << EQEP_QFRC_PCM_Pos) & EQEP_QFRC_PCM_Msk)                             /*!< PCM Set Value            */
#define EQEP_QFRC_PCM_Get(x) (((uint16_t) (x) & EQEP_QFRC_PCM_Msk) >> EQEP_QFRC_PCM_Pos)                             /*!< PCM Get Value            */


#define EQEP_QFRC_PCR_Pos    (7U)                                                                                  /*!< PCR Postion   7          */ 
#define EQEP_QFRC_PCR_Msk    (0x1U << EQEP_QFRC_PCR_Pos)                                                            /*!< PCR Mask      0x00000080 */
#define EQEP_QFRC_PCR_Set(x) (((uint16_t) (x) << EQEP_QFRC_PCR_Pos) & EQEP_QFRC_PCR_Msk)                             /*!< PCR Set Value            */
#define EQEP_QFRC_PCR_Get(x) (((uint16_t) (x) & EQEP_QFRC_PCR_Msk) >> EQEP_QFRC_PCR_Pos)                             /*!< PCR Get Value            */


#define EQEP_QFRC_PCO_Pos    (6U)                                                                                  /*!< PCO Postion   6          */ 
#define EQEP_QFRC_PCO_Msk    (0x1U << EQEP_QFRC_PCO_Pos)                                                            /*!< PCO Mask      0x00000040 */
#define EQEP_QFRC_PCO_Set(x) (((uint16_t) (x) << EQEP_QFRC_PCO_Pos) & EQEP_QFRC_PCO_Msk)                             /*!< PCO Set Value            */
#define EQEP_QFRC_PCO_Get(x) (((uint16_t) (x) & EQEP_QFRC_PCO_Msk) >> EQEP_QFRC_PCO_Pos)                             /*!< PCO Get Value            */


#define EQEP_QFRC_PCU_Pos    (5U)                                                                                  /*!< PCU Postion   5          */ 
#define EQEP_QFRC_PCU_Msk    (0x1U << EQEP_QFRC_PCU_Pos)                                                            /*!< PCU Mask      0x00000020 */
#define EQEP_QFRC_PCU_Set(x) (((uint16_t) (x) << EQEP_QFRC_PCU_Pos) & EQEP_QFRC_PCU_Msk)                             /*!< PCU Set Value            */
#define EQEP_QFRC_PCU_Get(x) (((uint16_t) (x) & EQEP_QFRC_PCU_Msk) >> EQEP_QFRC_PCU_Pos)                             /*!< PCU Get Value            */


#define EQEP_QFRC_WTO_Pos    (4U)                                                                                  /*!< WTO Postion   4          */ 
#define EQEP_QFRC_WTO_Msk    (0x1U << EQEP_QFRC_WTO_Pos)                                                            /*!< WTO Mask      0x00000010 */
#define EQEP_QFRC_WTO_Set(x) (((uint16_t) (x) << EQEP_QFRC_WTO_Pos) & EQEP_QFRC_WTO_Msk)                             /*!< WTO Set Value            */
#define EQEP_QFRC_WTO_Get(x) (((uint16_t) (x) & EQEP_QFRC_WTO_Msk) >> EQEP_QFRC_WTO_Pos)                             /*!< WTO Get Value            */


#define EQEP_QFRC_QDC_Pos    (3U)                                                                                  /*!< QDC Postion   3          */ 
#define EQEP_QFRC_QDC_Msk    (0x1U << EQEP_QFRC_QDC_Pos)                                                            /*!< QDC Mask      0x00000008 */
#define EQEP_QFRC_QDC_Set(x) (((uint16_t) (x) << EQEP_QFRC_QDC_Pos) & EQEP_QFRC_QDC_Msk)                             /*!< QDC Set Value            */
#define EQEP_QFRC_QDC_Get(x) (((uint16_t) (x) & EQEP_QFRC_QDC_Msk) >> EQEP_QFRC_QDC_Pos)                             /*!< QDC Get Value            */


#define EQEP_QFRC_PHE_Pos    (2U)                                                                                  /*!< PHE Postion   2          */ 
#define EQEP_QFRC_PHE_Msk    (0x1U << EQEP_QFRC_PHE_Pos)                                                            /*!< PHE Mask      0x00000004 */
#define EQEP_QFRC_PHE_Set(x) (((uint16_t) (x) << EQEP_QFRC_PHE_Pos) & EQEP_QFRC_PHE_Msk)                             /*!< PHE Set Value            */
#define EQEP_QFRC_PHE_Get(x) (((uint16_t) (x) & EQEP_QFRC_PHE_Msk) >> EQEP_QFRC_PHE_Pos)                             /*!< PHE Get Value            */


#define EQEP_QFRC_PCE_Pos    (1U)                                                                                  /*!< PCE Postion   1          */ 
#define EQEP_QFRC_PCE_Msk    (0x1U << EQEP_QFRC_PCE_Pos)                                                            /*!< PCE Mask      0x00000002 */
#define EQEP_QFRC_PCE_Set(x) (((uint16_t) (x) << EQEP_QFRC_PCE_Pos) & EQEP_QFRC_PCE_Msk)                             /*!< PCE Set Value            */
#define EQEP_QFRC_PCE_Get(x) (((uint16_t) (x) & EQEP_QFRC_PCE_Msk) >> EQEP_QFRC_PCE_Pos)                             /*!< PCE Get Value            */


/* QEPSTS bitfield */
#define EQEP_QEPSTS_UPEVENT_Pos    (7U)                                                                                  /*!< UPEVENT Postion   7          */ 
#define EQEP_QEPSTS_UPEVENT_Msk    (0x1U << EQEP_QEPSTS_UPEVENT_Pos)                                                      /*!< UPEVENT Mask      0x00000080 */
#define EQEP_QEPSTS_UPEVENT_Set(x) (((uint16_t) (x) << EQEP_QEPSTS_UPEVENT_Pos) & EQEP_QEPSTS_UPEVENT_Msk)                 /*!< UPEVENT Set Value            */
#define EQEP_QEPSTS_UPEVENT_Get(x) (((uint16_t) (x) & EQEP_QEPSTS_UPEVENT_Msk) >> EQEP_QEPSTS_UPEVENT_Pos)                 /*!< UPEVENT Get Value            */


#define EQEP_QEPSTS_FIDF_Pos    (6U)                                                                                  /*!< FIDF Postion   6          */ 
#define EQEP_QEPSTS_FIDF_Msk    (0x1U << EQEP_QEPSTS_FIDF_Pos)                                                         /*!< FIDF Mask      0x00000040 */
#define EQEP_QEPSTS_FIDF_Set(x) (((uint16_t) (x) << EQEP_QEPSTS_FIDF_Pos) & EQEP_QEPSTS_FIDF_Msk)                       /*!< FIDF Set Value            */
#define EQEP_QEPSTS_FIDF_Get(x) (((uint16_t) (x) & EQEP_QEPSTS_FIDF_Msk) >> EQEP_QEPSTS_FIDF_Pos)                       /*!< FIDF Get Value            */


#define EQEP_QEPSTS_QDF_Pos    (5U)                                                                                  /*!< QDF Postion   5          */ 
#define EQEP_QEPSTS_QDF_Msk    (0x1U << EQEP_QEPSTS_QDF_Pos)                                                          /*!< QDF Mask      0x00000020 */
#define EQEP_QEPSTS_QDF_Set(x) (((uint16_t) (x) << EQEP_QEPSTS_QDF_Pos) & EQEP_QEPSTS_QDF_Msk)                         /*!< QDF Set Value            */
#define EQEP_QEPSTS_QDF_Get(x) (((uint16_t) (x) & EQEP_QEPSTS_QDF_Msk) >> EQEP_QEPSTS_QDF_Pos)                         /*!< QDF Get Value            */


#define EQEP_QEPSTS_QDLF_Pos    (4U)                                                                                  /*!< QDLF Postion   4          */ 
#define EQEP_QEPSTS_QDLF_Msk    (0x1U << EQEP_QEPSTS_QDLF_Pos)                                                         /*!< QDLF Mask      0x00000010 */
#define EQEP_QEPSTS_QDLF_Set(x) (((uint16_t) (x) << EQEP_QEPSTS_QDLF_Pos) & EQEP_QEPSTS_QDLF_Msk)                       /*!< QDLF Set Value            */
#define EQEP_QEPSTS_QDLF_Get(x) (((uint16_t) (x) & EQEP_QEPSTS_QDLF_Msk) >> EQEP_QEPSTS_QDLF_Pos)                       /*!< QDLF Get Value            */


#define EQEP_QEPSTS_COEF_Pos    (3U)                                                                                  /*!< COEF Postion   3          */ 
#define EQEP_QEPSTS_COEF_Msk    (0x1U << EQEP_QEPSTS_COEF_Pos)                                                         /*!< COEF Mask      0x00000008 */
#define EQEP_QEPSTS_COEF_Set(x) (((uint16_t) (x) << EQEP_QEPSTS_COEF_Pos) & EQEP_QEPSTS_COEF_Msk)                       /*!< COEF Set Value            */
#define EQEP_QEPSTS_COEF_Get(x) (((uint16_t) (x) & EQEP_QEPSTS_COEF_Msk) >> EQEP_QEPSTS_COEF_Pos)                       /*!< COEF Get Value            */


#define EQEP_QEPSTS_CDEF_Pos    (2U)                                                                                  /*!< CDEF Postion   2          */ 
#define EQEP_QEPSTS_CDEF_Msk    (0x1U << EQEP_QEPSTS_CDEF_Pos)                                                         /*!< CDEF Mask      0x00000004 */
#define EQEP_QEPSTS_CDEF_Set(x) (((uint16_t) (x) << EQEP_QEPSTS_CDEF_Pos) & EQEP_QEPSTS_CDEF_Msk)                       /*!< CDEF Set Value            */
#define EQEP_QEPSTS_CDEF_Get(x) (((uint16_t) (x) & EQEP_QEPSTS_CDEF_Msk) >> EQEP_QEPSTS_CDEF_Pos)                       /*!< CDEF Get Value            */


#define EQEP_QEPSTS_FIMF_Pos    (1U)                                                                                  /*!< FIMF Postion   1          */ 
#define EQEP_QEPSTS_FIMF_Msk    (0x1U << EQEP_QEPSTS_FIMF_Pos)                                                         /*!< FIMF Mask      0x00000002 */
#define EQEP_QEPSTS_FIMF_Set(x) (((uint16_t) (x) << EQEP_QEPSTS_FIMF_Pos) & EQEP_QEPSTS_FIMF_Msk)                       /*!< FIMF Set Value            */
#define EQEP_QEPSTS_FIMF_Get(x) (((uint16_t) (x) & EQEP_QEPSTS_FIMF_Msk) >> EQEP_QEPSTS_FIMF_Pos)                       /*!< FIMF Get Value            */


#define EQEP_QEPSTS_PCEF_Pos    (0U)                                                                                  /*!< PCEF Postion   0          */ 
#define EQEP_QEPSTS_PCEF_Msk    (0x1U << EQEP_QEPSTS_PCEF_Pos)                                                         /*!< PCEF Mask      0x00000001 */
#define EQEP_QEPSTS_PCEF_Set(x) (((uint16_t) (x) << EQEP_QEPSTS_PCEF_Pos) & EQEP_QEPSTS_PCEF_Msk)                       /*!< PCEF Set Value            */
#define EQEP_QEPSTS_PCEF_Get(x) (((uint16_t) (x) & EQEP_QEPSTS_PCEF_Msk) >> EQEP_QEPSTS_PCEF_Pos)                       /*!< PCEF Get Value            */


/* QCTMR bitfield */
#define EQEP_QCTMR_QCTMR_Pos    (0U)                                                                                  /*!< QCTMR Postion   0          */ 
#define EQEP_QCTMR_QCTMR_Msk    (0xffffU << EQEP_QCTMR_QCTMR_Pos)                                                      /*!< QCTMR Mask      0x0000FFFF */
#define EQEP_QCTMR_QCTMR_Set(x) (((uint16_t) (x) << EQEP_QCTMR_QCTMR_Pos) & EQEP_QCTMR_QCTMR_Msk)                       /*!< QCTMR Set Value            */
#define EQEP_QCTMR_QCTMR_Get(x) (((uint16_t) (x) & EQEP_QCTMR_QCTMR_Msk) >> EQEP_QCTMR_QCTMR_Pos)                       /*!< QCTMR Get Value            */


/* QCPRD bitfield */
#define EQEP_QCPRD_QCPRD_Pos    (0U)                                                                                  /*!< QCPRD Postion   0          */ 
#define EQEP_QCPRD_QCPRD_Msk    (0xffffU << EQEP_QCPRD_QCPRD_Pos)                                                      /*!< QCPRD Mask      0x0000FFFF */
#define EQEP_QCPRD_QCPRD_Set(x) (((uint16_t) (x) << EQEP_QCPRD_QCPRD_Pos) & EQEP_QCPRD_QCPRD_Msk)                       /*!< QCPRD Set Value            */
#define EQEP_QCPRD_QCPRD_Get(x) (((uint16_t) (x) & EQEP_QCPRD_QCPRD_Msk) >> EQEP_QCPRD_QCPRD_Pos)                       /*!< QCPRD Get Value            */


/* QCTMRLAT bitfield */
#define EQEP_QCTMRLAT_QCTMRLAT_Pos    (0U)                                                                                  /*!< QCTMRLAT Postion   0          */ 
#define EQEP_QCTMRLAT_QCTMRLAT_Msk    (0xffffU << EQEP_QCTMRLAT_QCTMRLAT_Pos)                                                /*!< QCTMRLAT Mask      0x0000FFFF */
#define EQEP_QCTMRLAT_QCTMRLAT_Set(x) (((uint16_t) (x) << EQEP_QCTMRLAT_QCTMRLAT_Pos) & EQEP_QCTMRLAT_QCTMRLAT_Msk)           /*!< QCTMRLAT Set Value            */
#define EQEP_QCTMRLAT_QCTMRLAT_Get(x) (((uint16_t) (x) & EQEP_QCTMRLAT_QCTMRLAT_Msk) >> EQEP_QCTMRLAT_QCTMRLAT_Pos)           /*!< QCTMRLAT Get Value            */


/* QCPRDLAT bitfield */
#define EQEP_QCPRDLAT_QCPRDLAT_Pos    (0U)                                                                                  /*!< QCPRDLAT Postion   0          */ 
#define EQEP_QCPRDLAT_QCPRDLAT_Msk    (0xffffU << EQEP_QCPRDLAT_QCPRDLAT_Pos)                                                /*!< QCPRDLAT Mask      0x0000FFFF */
#define EQEP_QCPRDLAT_QCPRDLAT_Set(x) (((uint32_t) (x) << EQEP_QCPRDLAT_QCPRDLAT_Pos) & EQEP_QCPRDLAT_QCPRDLAT_Msk)           /*!< QCPRDLAT Set Value            */
#define EQEP_QCPRDLAT_QCPRDLAT_Get(x) (((uint32_t) (x) & EQEP_QCPRDLAT_QCPRDLAT_Msk) >> EQEP_QCPRDLAT_QCPRDLAT_Pos)           /*!< QCPRDLAT Get Value            */


/* REV bitfield */
#define EQEP_REV_MINOR_Pos    (3U)                                                                                  /*!< MINOR Postion   3          */ 
#define EQEP_REV_MINOR_Msk    (0x7U << EQEP_REV_MINOR_Pos)                                                           /*!< MINOR Mask      0x00000038 */
#define EQEP_REV_MINOR_Set(x) (((uint32_t) (x) << EQEP_REV_MINOR_Pos) & EQEP_REV_MINOR_Msk)                           /*!< MINOR Set Value            */
#define EQEP_REV_MINOR_Get(x) (((uint32_t) (x) & EQEP_REV_MINOR_Msk) >> EQEP_REV_MINOR_Pos)                           /*!< MINOR Get Value            */


#define EQEP_REV_MAJOR_Pos    (0U)                                                                                  /*!< MAJOR Postion   0          */ 
#define EQEP_REV_MAJOR_Msk    (0x7U << EQEP_REV_MAJOR_Pos)                                                           /*!< MAJOR Mask      0x00000007 */
#define EQEP_REV_MAJOR_Set(x) (((uint32_t) (x) << EQEP_REV_MAJOR_Pos) & EQEP_REV_MAJOR_Msk)                           /*!< MAJOR Set Value            */
#define EQEP_REV_MAJOR_Get(x) (((uint32_t) (x) & EQEP_REV_MAJOR_Msk) >> EQEP_REV_MAJOR_Pos)                           /*!< MAJOR Get Value            */


/* QEPSTROBESEL bitfield */
#define EQEP_QEPSTROBESEL_STROBESEL_Pos    (0U)                                                                                  /*!< STROBESEL Postion   0          */ 
#define EQEP_QEPSTROBESEL_STROBESEL_Msk    (0x3U << EQEP_QEPSTROBESEL_STROBESEL_Pos)                                              /*!< STROBESEL Mask      0x00000003 */
#define EQEP_QEPSTROBESEL_STROBESEL_Set(x) (((uint32_t) (x) << EQEP_QEPSTROBESEL_STROBESEL_Pos) & EQEP_QEPSTROBESEL_STROBESEL_Msk) /*!< STROBESEL Set Value            */
#define EQEP_QEPSTROBESEL_STROBESEL_Get(x) (((uint32_t) (x) & EQEP_QEPSTROBESEL_STROBESEL_Msk) >> EQEP_QEPSTROBESEL_STROBESEL_Pos) /*!< STROBESEL Get Value            */


/* QMACTRL bitfield */
#define EQEP_QMACTRL_BIN_MODE_Pos    (3U)                                                                                  /*!< BIN_MODE Postion   3          */ 
#define EQEP_QMACTRL_BIN_MODE_Msk    (0x1U << EQEP_QMACTRL_BIN_MODE_Pos)                                                    /*!< BIN_MODE Mask      0x00000008 */
#define EQEP_QMACTRL_BIN_MODE_Set(x) (((uint32_t) (x) << EQEP_QMACTRL_BIN_MODE_Pos) & EQEP_QMACTRL_BIN_MODE_Msk)             /*!< BIN_MODE Set Value            */
#define EQEP_QMACTRL_BIN_MODE_Get(x) (((uint32_t) (x) & EQEP_QMACTRL_BIN_MODE_Msk) >> EQEP_QMACTRL_BIN_MODE_Pos)             /*!< BIN_MODE Get Value            */


#define EQEP_QMACTRL_MODE_Pos    (0U)                                                                                  /*!< MODE Postion   0          */ 
#define EQEP_QMACTRL_MODE_Msk    (0x7U << EQEP_QMACTRL_MODE_Pos)                                                        /*!< MODE Mask      0x00000007 */
#define EQEP_QMACTRL_MODE_Set(x) (((uint32_t) (x) << EQEP_QMACTRL_MODE_Pos) & EQEP_QMACTRL_MODE_Msk)                     /*!< MODE Set Value            */
#define EQEP_QMACTRL_MODE_Get(x) (((uint32_t) (x) & EQEP_QMACTRL_MODE_Msk) >> EQEP_QMACTRL_MODE_Pos)                     /*!< MODE Get Value            */


/* QEPSRCSEL bitfield */
#define EQEP_QEPSRCSEL_QEPSSEL_Pos    (12U)                                                                                 /*!< QEPSSEL Postion   12         */ 
#define EQEP_QEPSRCSEL_QEPSSEL_Msk    (0xfU << EQEP_QEPSRCSEL_QEPSSEL_Pos)                                                   /*!< QEPSSEL Mask      0x0000F000 */
#define EQEP_QEPSRCSEL_QEPSSEL_Set(x) (((uint32_t) (x) << EQEP_QEPSRCSEL_QEPSSEL_Pos) & EQEP_QEPSRCSEL_QEPSSEL_Msk)           /*!< QEPSSEL Set Value            */
#define EQEP_QEPSRCSEL_QEPSSEL_Get(x) (((uint32_t) (x) & EQEP_QEPSRCSEL_QEPSSEL_Msk) >> EQEP_QEPSRCSEL_QEPSSEL_Pos)           /*!< QEPSSEL Get Value            */


#define EQEP_QEPSRCSEL_QEPISEL_Pos    (8U)                                                                                  /*!< QEPISEL Postion   8          */ 
#define EQEP_QEPSRCSEL_QEPISEL_Msk    (0xfU << EQEP_QEPSRCSEL_QEPISEL_Pos)                                                   /*!< QEPISEL Mask      0x00000F00 */
#define EQEP_QEPSRCSEL_QEPISEL_Set(x) (((uint32_t) (x) << EQEP_QEPSRCSEL_QEPISEL_Pos) & EQEP_QEPSRCSEL_QEPISEL_Msk)           /*!< QEPISEL Set Value            */
#define EQEP_QEPSRCSEL_QEPISEL_Get(x) (((uint32_t) (x) & EQEP_QEPSRCSEL_QEPISEL_Msk) >> EQEP_QEPSRCSEL_QEPISEL_Pos)           /*!< QEPISEL Get Value            */


#define EQEP_QEPSRCSEL_QEPBSEL_Pos    (4U)                                                                                  /*!< QEPBSEL Postion   4          */ 
#define EQEP_QEPSRCSEL_QEPBSEL_Msk    (0xfU << EQEP_QEPSRCSEL_QEPBSEL_Pos)                                                   /*!< QEPBSEL Mask      0x000000F0 */
#define EQEP_QEPSRCSEL_QEPBSEL_Set(x) (((uint32_t) (x) << EQEP_QEPSRCSEL_QEPBSEL_Pos) & EQEP_QEPSRCSEL_QEPBSEL_Msk)           /*!< QEPBSEL Set Value            */
#define EQEP_QEPSRCSEL_QEPBSEL_Get(x) (((uint32_t) (x) & EQEP_QEPSRCSEL_QEPBSEL_Msk) >> EQEP_QEPSRCSEL_QEPBSEL_Pos)           /*!< QEPBSEL Get Value            */


#define EQEP_QEPSRCSEL_QEPASEL_Pos    (0U)                                                                                  /*!< QEPASEL Postion   0          */ 
#define EQEP_QEPSRCSEL_QEPASEL_Msk    (0xfU << EQEP_QEPSRCSEL_QEPASEL_Pos)                                                   /*!< QEPASEL Mask      0x0000000F */
#define EQEP_QEPSRCSEL_QEPASEL_Set(x) (((uint32_t) (x) << EQEP_QEPSRCSEL_QEPASEL_Pos) & EQEP_QEPSRCSEL_QEPASEL_Msk)           /*!< QEPASEL Set Value            */
#define EQEP_QEPSRCSEL_QEPASEL_Get(x) (((uint32_t) (x) & EQEP_QEPSRCSEL_QEPASEL_Msk) >> EQEP_QEPSRCSEL_QEPASEL_Pos)           /*!< QEPASEL Get Value            */


/* ADCSOCSEL bitfield */
#define EQEP_ADCSOCSEL_ADCSOCB_Pos    (4U)                                                                                  /*!< ADCSOCB Postion   4          */ 
#define EQEP_ADCSOCSEL_ADCSOCB_Msk    (0xfU << EQEP_ADCSOCSEL_ADCSOCB_Pos)                                                   /*!< ADCSOCB Mask      0x000000F0 */
#define EQEP_ADCSOCSEL_ADCSOCB_Set(x) (((uint32_t) (x) << EQEP_ADCSOCSEL_ADCSOCB_Pos) & EQEP_ADCSOCSEL_ADCSOCB_Msk)           /*!< ADCSOCB Set Value            */
#define EQEP_ADCSOCSEL_ADCSOCB_Get(x) (((uint32_t) (x) & EQEP_ADCSOCSEL_ADCSOCB_Msk) >> EQEP_ADCSOCSEL_ADCSOCB_Pos)           /*!< ADCSOCB Get Value            */


#define EQEP_ADCSOCSEL_ADCSOCA_Pos    (0U)                                                                                  /*!< ADCSOCA Postion   0          */ 
#define EQEP_ADCSOCSEL_ADCSOCA_Msk    (0xfU << EQEP_ADCSOCSEL_ADCSOCA_Pos)                                                   /*!< ADCSOCA Mask      0x0000000F */
#define EQEP_ADCSOCSEL_ADCSOCA_Set(x) (((uint32_t) (x) << EQEP_ADCSOCSEL_ADCSOCA_Pos) & EQEP_ADCSOCSEL_ADCSOCA_Msk)           /*!< ADCSOCA Set Value            */
#define EQEP_ADCSOCSEL_ADCSOCA_Get(x) (((uint32_t) (x) & EQEP_ADCSOCSEL_ADCSOCA_Msk) >> EQEP_ADCSOCSEL_ADCSOCA_Pos)           /*!< ADCSOCA Get Value            */


/* CLBBYPASS bitfield */
#define EQEP_CLBBYPASS_QCLKSEL_Pos    (3U)                                                                                  /*!< QCLKSEL Postion   3          */ 
#define EQEP_CLBBYPASS_QCLKSEL_Msk    (0x1U << EQEP_CLBBYPASS_QCLKSEL_Pos)                                                   /*!< QCLKSEL Mask      0x00000008 */
#define EQEP_CLBBYPASS_QCLKSEL_Set(x) (((uint32_t) (x) << EQEP_CLBBYPASS_QCLKSEL_Pos) & EQEP_CLBBYPASS_QCLKSEL_Msk)           /*!< QCLKSEL Set Value            */
#define EQEP_CLBBYPASS_QCLKSEL_Get(x) (((uint32_t) (x) & EQEP_CLBBYPASS_QCLKSEL_Msk) >> EQEP_CLBBYPASS_QCLKSEL_Pos)           /*!< QCLKSEL Get Value            */


#define EQEP_CLBBYPASS_QDIRSEL_Pos    (2U)                                                                                  /*!< QDIRSEL Postion   2          */ 
#define EQEP_CLBBYPASS_QDIRSEL_Msk    (0x1U << EQEP_CLBBYPASS_QDIRSEL_Pos)                                                   /*!< QDIRSEL Mask      0x00000004 */
#define EQEP_CLBBYPASS_QDIRSEL_Set(x) (((uint32_t) (x) << EQEP_CLBBYPASS_QDIRSEL_Pos) & EQEP_CLBBYPASS_QDIRSEL_Msk)           /*!< QDIRSEL Set Value            */
#define EQEP_CLBBYPASS_QDIRSEL_Get(x) (((uint32_t) (x) & EQEP_CLBBYPASS_QDIRSEL_Msk) >> EQEP_CLBBYPASS_QDIRSEL_Pos)           /*!< QDIRSEL Get Value            */


#define EQEP_CLBBYPASS_QBSEL_Pos    (1U)                                                                                  /*!< QBSEL Postion   1          */ 
#define EQEP_CLBBYPASS_QBSEL_Msk    (0x1U << EQEP_CLBBYPASS_QBSEL_Pos)                                                     /*!< QBSEL Mask      0x00000002 */
#define EQEP_CLBBYPASS_QBSEL_Set(x) (((uint32_t) (x) << EQEP_CLBBYPASS_QBSEL_Pos) & EQEP_CLBBYPASS_QBSEL_Msk)               /*!< QBSEL Set Value            */
#define EQEP_CLBBYPASS_QBSEL_Get(x) (((uint32_t) (x) & EQEP_CLBBYPASS_QBSEL_Msk) >> EQEP_CLBBYPASS_QBSEL_Pos)               /*!< QBSEL Get Value            */


#define EQEP_CLBBYPASS_QASEL_Pos    (0U)                                                                                  /*!< QASEL Postion   0          */ 
#define EQEP_CLBBYPASS_QASEL_Msk    (0x1U << EQEP_CLBBYPASS_QASEL_Pos)                                                     /*!< QASEL Mask      0x00000001 */
#define EQEP_CLBBYPASS_QASEL_Set(x) (((uint32_t) (x) << EQEP_CLBBYPASS_QASEL_Pos) & EQEP_CLBBYPASS_QASEL_Msk)               /*!< QASEL Set Value            */
#define EQEP_CLBBYPASS_QASEL_Get(x) (((uint32_t) (x) & EQEP_CLBBYPASS_QASEL_Msk) >> EQEP_CLBBYPASS_QASEL_Pos)               /*!< QASEL Get Value            */


/* DBGSEL bitfield */
#define EQEP_DBGSEL_MODULE_SELECT_Pos    (5U)                                                                                  /*!< MODULE_SELECT Postion   5          */ 
#define EQEP_DBGSEL_MODULE_SELECT_Msk    (0x7U << EQEP_DBGSEL_MODULE_SELECT_Pos)                                                /*!< MODULE_SELECT Mask      0x000000E0 */
#define EQEP_DBGSEL_MODULE_SELECT_Set(x) (((uint32_t) (x) << EQEP_DBGSEL_MODULE_SELECT_Pos) & EQEP_DBGSEL_MODULE_SELECT_Msk)     /*!< MODULE_SELECT Set Value            */
#define EQEP_DBGSEL_MODULE_SELECT_Get(x) (((uint32_t) (x) & EQEP_DBGSEL_MODULE_SELECT_Msk) >> EQEP_DBGSEL_MODULE_SELECT_Pos)     /*!< MODULE_SELECT Get Value            */


#define EQEP_DBGSEL_DBG_SEL_Pos    (0U)                                                                                  /*!< DBG_SEL Postion   0          */ 
#define EQEP_DBGSEL_DBG_SEL_Msk    (0x1fU << EQEP_DBGSEL_DBG_SEL_Pos)                                                     /*!< DBG_SEL Mask      0x0000001F */
#define EQEP_DBGSEL_DBG_SEL_Set(x) (((uint32_t) (x) << EQEP_DBGSEL_DBG_SEL_Pos) & EQEP_DBGSEL_DBG_SEL_Msk)                 /*!< DBG_SEL Set Value            */
#define EQEP_DBGSEL_DBG_SEL_Get(x) (((uint32_t) (x) & EQEP_DBGSEL_DBG_SEL_Msk) >> EQEP_DBGSEL_DBG_SEL_Pos)                 /*!< DBG_SEL Get Value            */


/*!
 * @}
 */


/*!
 * @}
 */ /* end of HS32F7D377_EQEP_REGISTER */

#endif /* HS32F7D377_EQEP_H */
