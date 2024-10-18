/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


/*!
 * \file   HS32F7D377_mcan.h
 * \brief  HS32F7D377 MCAN register file
 * \version V1.0_20230713
 */

#ifndef HS32F7D377_MCAN_H
#define HS32F7D377_MCAN_H

/*!
 * \addtogroup   HS32F7D377_MCAN_REGISTER HS32F7D377 MCAN Register
 * \ingroup HS32F7D377_REGISTER
 *
 * \brief  MCAN register layout, bitfield and address definitions
 *
 * @{
 */

/*!
 * \name MCAN Register Layout
 *
 *
 * @{
 */

/*! \brief MCAN_REGS register */
typedef struct
{
    union
    {
        __IM uint32_t CREL; /*!< 0x00000000 */

        struct
        {
            __IM uint32_t DAY     : 8; /*!< [7:0] : Time Stamp Day. */
            __IM uint32_t MON     : 8; /*!< [15:8] : Time Stamp Month. */
            __IM uint32_t YEAR    : 4; /*!< [19:16] : Time Stamp Year. */
            __IM uint32_t SUBSTEP : 4; /*!< [23:20] : Sub-Step of Core Release. */
            __IM uint32_t STEP    : 4; /*!< [27:24] : Step of Core Release. */
            __IM uint32_t REL     : 4; /*!< [31:28] : Core Release. */
        } CRELb;
    };

    union
    {
        __IM uint32_t ENDN; /*!< 0x00000004 */

        struct
        {
            __IM uint32_t ETV : 32; /*!< [31:0] : Endianess Test Value. */
        } ENDNb;
    };

    uint8_t RSV_0X8[4]; /*!< 0x00000008~0x0000000b : reserved */

    union
    {
        __IOM uint32_t DBTP; /*!< 0x0000000c */

        struct
        {
            __IOM uint32_t DSJW   : 4; /*!< [3:0] : Data Resynchronization Jump Width. */
            __IOM uint32_t DTSEG2 : 4; /*!< [7:4] : Data Time Segment After Sample Point. */
            __IOM uint32_t DTSEG1 : 5; /*!< [12:8] : Data Time Segment Before Sample Point. */
            uint32_t       RSV_2  : 3; /*!< [15:13] : reserved. */
            __IOM uint32_t DBRP   : 5; /*!< [20:16] : Data Bit Rate Prescaler. */
            uint32_t       RSV_1  : 2; /*!< [22:21] : reserved. */
            __IOM uint32_t TDC : 1; /*!< [23:23] : Transmitter Delay Compensation                                  <br>
                                       0 Transmitter Delay Compensation disabled 1 Transmitter Delay Compensation
                                       enabled+I107<br>  Reset type: SYSRSn <br>. */
            uint32_t RSV_0 : 8;     /*!< [31:24] : reserved. */
        } DBTPb;
    };

    union
    {
        __IOM uint32_t TEST; /*!< 0x00000010 */

        struct
        {
            uint32_t       RSV_2 : 4; /*!< [3:0] : reserved. */
            __IOM uint32_t LBCK  : 1; /*!< [4:4] : Loop Back Mode                                                  <br>
                                         0 Reset value, Loop Back Mode is disabled 1 Loop Back Mode is enabled<br>
                                         Qualified Write is possible only with CCCR. */
            __IOM uint32_t TX : 2; /*!< [6:5] : Control of Transmit Pin                                         <br>  00
                                      CAN TX pin controlled by the CAN Core, updated at the end of the CAN bit time<br>
                                      01 Sample Point can be monitored at CAN TX pin 10 Dominant ('0') level at CAN TX
                                      pin<br>  11 Recessive ('1') at CAN TX pin                                <br>
                                      Qualified Write is possible only with CCCR. */
            __IM uint32_t RX    : 1; /*!< [7:7] : Receive Pin. */
            __IM uint32_t TXBNP : 5; /*!< [12:8] : Tx Buffer Number Prepared                                       <br>
                                        Tx Buffer number of message that is ready for transmission. */
            __IM uint32_t PVAL : 1;  /*!< [13:13] : Prepared Valid                                                  <br>
                                        0= Value of TXBNP not valid                                     <br>  1= Value of
                                        TXBNP valid                                         <br>. */
            uint32_t      RSV_1 : 2; /*!< [15:14] : reserved. */
            __IM uint32_t TXBNS : 5; /*!< [20:16] : Tx Buffer Number Started                                        <br>
                                        Tx Buffer number of message whose transmission was started last. */
            __IM uint32_t SVAL : 1;  /*!< [21:21] : Started Valid                                                   <br>
                                        0= Value of TXBNS not valid                                     <br>  1= Value of
                                        TXBNS valid                                         <br>. */
            uint32_t RSV_0 : 10;     /*!< [31:22] : reserved. */
        } TESTb;
    };

    union
    {
        __IOM uint32_t RWD; /*!< 0x00000014 */

        struct
        {
            __IOM uint32_t WDC   : 8;  /*!< [7:0] : Watchdog Configuration. */
            __IM uint32_t  WDV   : 8;  /*!< [15:8] : Watchdog Value. */
            uint32_t       RSV_0 : 16; /*!< [31:16] : reserved. */
        } RWDb;
    };

    union
    {
        __IOM uint32_t CCCR; /*!< 0x00000018 */

        struct
        {
            __IOM uint32_t
                INIT : 1; /*!< [0:0] : Initialization                                                  <br>  0 Normal
                             Operation                                              <br>  1 Initialization is started
                             <br>  Note: Due to the synchronization mechanism between the two clock domains, there may
                             be a delay until the value written to INIT can be read back. */
            __IOM uint32_t CCE : 1; /*!< [1:1] : Configuration Change Enable                                     <br>  0
                                       The CPU has no write access to the protected configuration registers<br>  1 The
                                       CPU has write access to the protected configuration registers (while CCCR. */
            __IOM uint32_t ASM : 1; /*!< [2:2] : Restricted Operation Mode. */
            __IM uint32_t
                CSA : 1; /*!< [3:3] : Clock Stop Acknowledge                                          <br>  0 No clock
                            stop acknowledged                                    <br>  1 MCAN may be set in power down
                            by stopping the Host and CAN clocks<br>  Reset type: SYSRSn <br>. */
            __IOM uint32_t
                CSR : 1; /*!< [4:4] : Clock Stop Request                                              <br>  0 No clock
                            stop is requested                                    <br>  1 Clock stop requested. */
            __IOM uint32_t MON : 1; /*!< [5:5] : Bus Monitoring Mode. */
            __IOM uint32_t DAR : 1; /*!< [6:6] : Disable Automatic Retransmission                                <br>  0
                                       Automatic retransmission of messages not transmitted successfully enabled<br>  1
                                       Automatic retransmission disabled                             <br>  Qualified
                                       Write is possible only with CCCR. */
            __IOM uint32_t
                TEST : 1; /*!< [7:7] : Test Mode Enable                                                <br>  0 Normal
                             operation, register TEST holds reset values 1 Test Mode, write access to register TEST
                             enabled<br>  Qualified Write 1 to Set is possible only with CCCR. */
            __IOM uint32_t FDOE : 1; /*!< [8:8] : Flexible Datarate Operation Enable 0 FD operation disabled      <br>
                                        1 FD operation enabled                                          <br>  Qualified
                                        Write is possible only with CCCR. */
            __IOM uint32_t
                BRSE : 1; /*!< [9:9] : Bit Rate Switch Enable                                          <br>  0 Bit rate
                             switching for transmissions disabled 1 Bit rate switching for transmissions enabled<br>
                             Note: When CAN FD operation is disabled FDOE = '0', BRSE is not evaluated. */
            __IOM uint32_t
                UTSU : 1; /*!< [10:10] : Use Timestamping Unit                                           <br>  When UTSU
                             is set, 16-bit Wide Message Markers are also enabled regardless of the value of WMM. */
            __IOM uint32_t WMM : 1;  /*!< [11:11] : Wide Message Marker                                             <br>
                                        Enables the use of 16-bit Wide Message Markers. */
            __IOM uint32_t PXHD : 1; /*!< [12:12] : Protocol Exception Handling Disable  0 Protocol exception handling
                                        enabled<br>  1 Protocol exception handling disabled <br>  Note: When protocol
                                        exception handling is disabled, the MCAN will transmit an error frame when it
                                        detects a protocol exception condition. */
            __IOM uint32_t EFBI : 1; /*!< [13:13] : Edge Filtering during Bus Integration 0 Edge filtering disabled <br>
                                        1 Two consecutive dominant tq required to detect an edge for hard
                                        synchronization<br>  Qualified Write is possible only with CCCR. */
            __IOM uint32_t TXP   : 1;  /*!< [14:14] : Transmit Pause. */
            __IOM uint32_t NISO  : 1;  /*!< [15:15] : Non ISO Operation. */
            uint32_t       RSV_0 : 16; /*!< [31:16] : reserved. */
        } CCCRb;
    };

    union
    {
        __IOM uint32_t NBTP; /*!< 0x0000001c */

        struct
        {
            __IOM uint32_t NTSEG2 : 7; /*!< [6:0] : Nominal Time Segment After Sample Point. */
            uint32_t       RSV_0  : 1; /*!< [7:7] : reserved. */
            __IOM uint32_t NTSEG1 : 8; /*!< [15:8] : Nominal Time Segment Before Sample Point. */
            __IOM uint32_t NBRP   : 9; /*!< [24:16] : Nominal Bit Rate Prescaler. */
            __IOM uint32_t NSJW   : 7; /*!< [31:25] : Nominal (Re)Synchronization Jump Width. */
        } NBTPb;
    };

    union
    {
        __IOM uint32_t TSCC; /*!< 0x00000020 */

        struct
        {
            __IOM uint32_t TSS : 2; /*!< [1:0] : Timestamp Select                                                <br> 00
                                       Timestamp counter value always 0x0000                        <br>  01 Timestamp
                                       counter value incremented according to TCP 10 External timestamp counter value
                                       used<br>  11 Same as "00" <br>  Qualified Write is possible only with CCCR. */
            uint32_t       RSV_1 : 14; /*!< [15:2] : reserved. */
            __IOM uint32_t TCP   : 4;  /*!< [19:16] : Timestamp Counter Prescaler. */
            uint32_t       RSV_0 : 12; /*!< [31:20] : reserved. */
        } TSCCb;
    };

    union
    {
        __IOM uint32_t TSCV; /*!< 0x00000024 */

        struct
        {
            __IOM uint32_t TSC   : 16; /*!< [15:0] : Timestamp Counter. */
            uint32_t       RSV_0 : 16; /*!< [31:16] : reserved. */
        } TSCVb;
    };

    union
    {
        __IOM uint32_t TOCC; /*!< 0x00000028 */

        struct
        {
            __IOM uint32_t ETOC : 1;   /*!< [0:0] : Enable Timeout Counter                                          <br>
                                          0 Timeout Counter disabled 1 Timeout Counter enabled            <br>  Qualified
                                          Write is possible only with CCCR. */
            __IOM uint32_t TOS   : 2;  /*!< [2:1] : Timeout Select. */
            uint32_t       RSV_0 : 13; /*!< [15:3] : reserved. */
            __IOM uint32_t TOP   : 16; /*!< [31:16] : Timeout Period. */
        } TOCCb;
    };

    union
    {
        __IOM uint32_t TOCV; /*!< 0x0000002c */

        struct
        {
            __IOM uint32_t TOC   : 16; /*!< [15:0] : Timeout Counter. */
            uint32_t       RSV_0 : 16; /*!< [31:16] : reserved. */
        } TOCVb;
    };

    uint8_t RSV_0X30[16]; /*!< 0x00000030~0x0000003f : reserved */

    union
    {
        __IOM uint32_t ECR; /*!< 0x00000040 */

        struct
        {
            __IM uint32_t TEC : 8; /*!< [7:0] : Transmit Error Counter. */
            __IM uint32_t REC : 7; /*!< [14:8] : Receive Error Counter. */
            __IM uint32_t
                RP : 1; /*!< [15:15] : Receive Error Passive                                           <br>  0 The
                           Receive Error Counter is below the error passive level of 128 1 The Receive Error Counter has
                           reached the error passive level of 128<br>  Reset type: SYSRSn <br>. */
            __IM uint32_t CEL   : 8; /*!< [23:16] : CAN Error Logging. */
            uint32_t      RSV_0 : 8; /*!< [31:24] : reserved. */
        } ECRb;
    };

    union
    {
        __IOM uint32_t PSR; /*!< 0x00000044 */

        struct
        {
            __IM uint32_t LEC : 3; /*!< [2:0] : Last Error Code. */
            __IM uint32_t ACT : 2; /*!< [4:3] : Node Activity. */
            __IM uint32_t EP  : 1; /*!< [5:5] : Error Passive                                                   <br>  0
                                      The M_CAN is in the Error_Active state. */
            __IM uint32_t
                EW : 1; /*!< [6:6] : Warning Status                                                  <br>  0 Both error
                           counters are below the Error_Warning limit of 96   <br>  1 At least one of error counter has
                           reached the Error_Warning limit of 96<br>  Reset type: SYSRSn <br>. */
            __IM uint32_t BO : 1;   /*!< [7:7] : Bus_Off Status                                                  <br>  0
                                       The M_CAN is not Bus_Off                                      <br>  1 The M_CAN is
                                       in Bus_Off state Reset type: SYSRSn              <br>. */
            __IM uint32_t DLEC : 3; /*!< [10:8] : Data Phase Last Error Code. */
            __IM uint32_t RESI : 1; /*!< [11:11] : ESI Flag of Last Received CAN FD Message. */
            __IM uint32_t RBRS : 1; /*!< [12:12] : BRS Flag of Last Received CAN FD Message. */
            __IM uint32_t RFDF : 1; /*!< [13:13] : Received a CAN FD Message. */
            __IM uint32_t PXE  : 1; /*!< [14:14] : Protocol Exception Event                                        <br>
                                       0 No protocol exception event occurred since last read access 1 Protocol exception
                                       event occurred<br>  Reset type: SYSRSn  <br>. */
            uint32_t      RSV_1 : 1; /*!< [15:15] : reserved. */
            __IM uint32_t TDCV  : 7; /*!< [22:16] : Transmitter Delay Compensation Value. */
            uint32_t      RSV_0 : 9; /*!< [31:23] : reserved. */
        } PSRb;
    };

    union
    {
        __IOM uint32_t TDCR; /*!< 0x00000048 */

        struct
        {
            __IOM uint32_t TDCF  : 7;  /*!< [6:0] : Transmitter Delay Compensation Filter Window Length. */
            uint32_t       RSV_1 : 1;  /*!< [7:7] : reserved. */
            __IOM uint32_t TDCO  : 7;  /*!< [14:8] : Transmitter Delay Compensation Offset. */
            uint32_t       RSV_0 : 17; /*!< [31:15] : reserved. */
        } TDCRb;
    };

    uint8_t RSV_0X4C[4]; /*!< 0x0000004c~0x0000004f : reserved */

    union
    {
        __IOM uint32_t IR; /*!< 0x00000050 */

        struct
        {
            __IOM uint32_t
                RF0N : 1; /*!< [0:0] : Rx FIFO 0 New Message                                           <br>  0 No new
                             message written to Rx FIFO 0 1 New message written to Rx FIFO 0 Reset type: SYSRSn<br>. */
            __IOM uint32_t RF0W : 1; /*!< [1:1] : Rx FIFO 0 Watermark Reached                                     <br>
                                        0 Rx FIFO 0 fill level below watermark                          <br>  1 Rx FIFO
                                        0 fill level reached watermark Reset type: SYSRSn     <br>. */
            __IOM uint32_t RF0F : 1; /*!< [2:2] : Rx FIFO 0 Full                                                  <br>
                                        0 Rx FIFO 0 not full                                            <br>  1 Rx FIFO
                                        0 full Reset type: SYSRSn                             <br>. */
            __IOM uint32_t
                RF0L : 1; /*!< [3:3] : Rx FIFO 0 Message Lost                                          <br>  0 No Rx
                             FIFO 0 message lost                                     <br>  1 Rx FIFO 0 message lost,
                             also set after write attempt to Rx FIFO 0 of size zero<br>  Reset type: SYSRSn <br>. */
            __IOM uint32_t
                RF1N : 1; /*!< [4:4] : Rx FIFO 1 New Message                                           <br>  0 No new
                             message written to Rx FIFO 1 1 New message written to Rx FIFO 1 Reset type: SYSRSn<br>. */
            __IOM uint32_t RF1W : 1; /*!< [5:5] : Rx FIFO 1 Watermark Reached                                     <br>
                                        0 Rx FIFO 1 fill level below watermark                          <br>  1 Rx FIFO
                                        1 fill level reached watermark Reset type: SYSRSn     <br>. */
            __IOM uint32_t RF1F : 1; /*!< [6:6] : Rx FIFO 1 Full                                                  <br>
                                        0 Rx FIFO 1 not full                                            <br>  1 Rx FIFO
                                        1 full Reset type: SYSRSn                             <br>. */
            __IOM uint32_t
                RF1L : 1; /*!< [7:7] : Rx FIFO 1 Message Lost                                          <br>  0 No Rx
                             FIFO 1 message lost                                     <br>  1 Rx FIFO 1 message lost,
                             also set after write attempt to Rx FIFO 1 of size zero<br>  Reset type: SYSRSn <br>. */
            __IOM uint32_t
                HPM : 1; /*!< [8:8] : High Priority Message                                           <br>  0 No high
                            priority message received 1 High priority message received Reset type: SYSRSn<br>. */
            __IOM uint32_t TC : 1;  /*!< [9:9] : Transmission Completed                                          <br>  0
                                       No transmission completed 1 Transmission completed Reset type: SYSRSn<br>. */
            __IOM uint32_t TCF : 1; /*!< [10:10] : Transmission Cancellation Finished                              <br>
                                       0 No transmission cancellation finished 1 Transmission cancellation finished
                                       Reset type: SYSRSn<br>. */
            __IOM uint32_t TFE : 1; /*!< [11:11] : Tx FIFO Empty                                                   <br>
                                       0 Tx FIFO non-empty 1 Tx FIFO empty Reset type: SYSRSn          <br>. */
            __IOM uint32_t TEFN : 1; /*!< [12:12] : Tx Event FIFO New Entry                                         <br>
                                        0 Tx Event FIFO unchanged                                       <br>  1 Tx
                                        Handler wrote Tx Event FIFO element Reset type: SYSRSn     <br>. */
            __IOM uint32_t TEFW : 1; /*!< [13:13] : Tx Event FIFO Watermark Reached                                 <br>
                                        0 Tx Event FIFO fill level below watermark                      <br>  1 Tx Event
                                        FIFO fill level reached watermark Reset type: SYSRSn <br>. */
            __IOM uint32_t TEFF : 1; /*!< [14:14] : Tx Event FIFO Full                                              <br>
                                        0 Tx Event FIFO not full 1 Tx Event FIFO full Reset type: SYSRSn<br>. */
            __IOM uint32_t
                TEFL : 1; /*!< [15:15] : Tx Event FIFO Element Lost                                      <br>  0 No Tx
                             Event FIFO element lost                                 <br>  1 Tx Event FIFO element lost,
                             also set after write attempt to Tx Event FIFO of size zero<br>  Reset type: SYSRSn <br>. */
            __IOM uint32_t
                TSW : 1; /*!< [16:16] : Timestamp Wraparound                                            <br>  0 No
                            timestamp counter wrap-around 1 Timestamp counter wrapped around Reset type: SYSRSn<br>. */
            __IOM uint32_t MRAF : 1; /*!< [17:17] : Message RAM Access Failure. */
            __IOM uint32_t TOO  : 1; /*!< [18:18] : Timeout Occurred 0 No timeout                                   <br>
                                        1 Timeout reached Reset type: SYSRSn                            <br>. */
            __IOM uint32_t DRX : 1;  /*!< [19:19] : Message Stored to Dedicated Rx Buffer. */
            __IOM uint32_t BEC : 1;  /*!< [20:20] : Bit Error Corrected. */
            __IOM uint32_t BEU : 1;  /*!< [21:21] : Bit Error Uncorrected. */
            __IOM uint32_t ELO : 1;  /*!< [22:22] : Error Logging Overflow                                          <br>
                                        0 CAN Error Logging Counter did not overflow                    <br>  1 Overflow
                                        of CAN Error Logging Counter occurred Reset type: SYSRSn<br>. */
            __IOM uint32_t
                EP : 1; /*!< [23:23] : Error Passive                                                   <br>  0
                           Error_Passive status unchanged 1 Error_Passive status changed Reset type: SYSRSn<br>. */
            __IOM uint32_t
                EW : 1; /*!< [24:24] : Warning Status                                                  <br>  0
                           Error_Warning status unchanged 1 Error_Warning status changed Reset type: SYSRSn<br>. */
            __IOM uint32_t BO : 1;  /*!< [25:25] : Bus_Off Status                                                  <br>
                                       0 Bus_Off status unchanged 1 Bus_Off status changed Reset type: SYSRSn<br>. */
            __IOM uint32_t WDI : 1; /*!< [26:26] : Watchdog Interrupt                                              <br>
                                       0 No Message RAM Watchdog event occurred                        <br>  1 Message
                                       RAM Watchdog event due to missing READY Reset type: SYSRSn<br>. */
            __IOM uint32_t
                PEA : 1; /*!< [27:27] : Protocol Error in Arbitration Phase (Nominal Bit Time is used) 0 No protocol
                            error in arbitration phase<br>  1 Protocol error in arbitration phase detected (PSR. */
            __IOM uint32_t PED : 1; /*!< [28:28] : Protocol Error in Data Phase (Data Bit Time is used) 0 No protocol
                                       error in data phase<br>  1 Protocol error in data phase detected (PSR. */
            __IOM uint32_t ARA : 1; /*!< [29:29] : Access to Reserved Address                                      <br>
                                       0 No access to reserved address occurred 1 Access to reserved address occurred
                                       Reset type: SYSRSn<br>. */
            uint32_t RSV_0 : 2;     /*!< [31:30] : reserved. */
        } IRb;
    };

    union
    {
        __IOM uint32_t IE; /*!< 0x00000054 */

        struct
        {
            __IOM uint32_t RF0NE : 1; /*!< [0:0] : Rx FIFO 0 New Message Enable Reset type: SYSRSn. */
            __IOM uint32_t RF0WE : 1; /*!< [1:1] : Rx FIFO 0 Watermark Reached Enable Reset type: SYSRSn. */
            __IOM uint32_t RF0FE : 1; /*!< [2:2] : Rx FIFO 0 Full Enable Reset type: SYSRSn. */
            __IOM uint32_t RF0LE : 1; /*!< [3:3] : Rx FIFO 0 Message Lost Enable Reset type: SYSRSn. */
            __IOM uint32_t RF1NE : 1; /*!< [4:4] : Rx FIFO 1 New Message Enable Reset type: SYSRSn. */
            __IOM uint32_t RF1WE : 1; /*!< [5:5] : Rx FIFO 1 Watermark Reached Enable Reset type: SYSRSn. */
            __IOM uint32_t RF1FE : 1; /*!< [6:6] : Rx FIFO 1 Full Enable Reset type: SYSRSn. */
            __IOM uint32_t RF1LE : 1; /*!< [7:7] : Rx FIFO 1 Message Lost Enable Reset type: SYSRSn. */
            __IOM uint32_t HPME  : 1; /*!< [8:8] : High Priority Message Enable Reset type: SYSRSn. */
            __IOM uint32_t TCE   : 1; /*!< [9:9] : Transmission Completed Enable Reset type: SYSRSn. */
            __IOM uint32_t TCFE  : 1; /*!< [10:10] : Transmission Cancellation Finished Enable Reset type: SYSRSn. */
            __IOM uint32_t TFEE  : 1; /*!< [11:11] : Tx FIFO Empty Enable Reset type: SYSRSn. */
            __IOM uint32_t TEFNE : 1; /*!< [12:12] : Tx Event FIFO New Entry Enable Reset type: SYSRSn. */
            __IOM uint32_t TEFWE : 1; /*!< [13:13] : Tx Event FIFO Watermark Reached Enable Reset type: SYSRSn. */
            __IOM uint32_t TEFFE : 1; /*!< [14:14] : Tx Event FIFO Full Enable Reset type: SYSRSn. */
            __IOM uint32_t TEFLE : 1; /*!< [15:15] : Tx Event FIFO Element Lost Enable Reset type: SYSRSn. */
            __IOM uint32_t TSWE  : 1; /*!< [16:16] : Timestamp Wraparound Enable Reset type: SYSRSn. */
            __IOM uint32_t MRAFE : 1; /*!< [17:17] : Message RAM Access Failure Enable Reset type: SYSRSn. */
            __IOM uint32_t TOOE  : 1; /*!< [18:18] : Timeout Occurred Enable Reset type: SYSRSn. */
            __IOM uint32_t DRXE  : 1; /*!< [19:19] : Message Stored to Dedicated Rx Buffer Enable Reset type: SYSRSn. */
            __IOM uint32_t BECE : 1; /*!< [20:20] : Bit Error Corrected Enable                                      <br>
                                        A separate interrupt line reserved for corrected bit errors is provided via the
                                        MCAN_ERROR_REGS. */
            __IOM uint32_t BEUE  : 1; /*!< [21:21] : Bit Error Uncorrected Enable Reset type: SYSRSn. */
            __IOM uint32_t ELOE  : 1; /*!< [22:22] : Error Logging Overflow Enable Reset type: SYSRSn. */
            __IOM uint32_t EPE   : 1; /*!< [23:23] : Error Passive Enable Reset type: SYSRSn. */
            __IOM uint32_t EWE   : 1; /*!< [24:24] : Warning Status Enable Reset type: SYSRSn. */
            __IOM uint32_t BOE   : 1; /*!< [25:25] : Bus_Off Status Enable Reset type: SYSRSn. */
            __IOM uint32_t WDIE  : 1; /*!< [26:26] : Watchdog Interrupt Enable Reset type: SYSRSn. */
            __IOM uint32_t PEAE  : 1; /*!< [27:27] : Protocol Error in Arbitration Phase Enable Reset type: SYSRSn. */
            __IOM uint32_t PEDE  : 1; /*!< [28:28] : Protocol Error in Data Phase Enable Reset type: SYSRSn. */
            __IOM uint32_t ARAE  : 1; /*!< [29:29] : Access to Reserved Address Enable Reset type: SYSRSn. */
            uint32_t       RSV_0 : 2; /*!< [31:30] : reserved. */
        } IEb;
    };

    union
    {
        __IOM uint32_t ILS; /*!< 0x00000058 */

        struct
        {
            __IOM uint32_t RF0NL : 1; /*!< [0:0] : Rx FIFO 0 New Message Line                                      <br>
                                         0 Interrupt source is assigned to Interrupt Line 0 1 Interrupt source is
                                         assigned to Interrupt Line 1 Reset type: SYSRSn<br>. */
            __IOM uint32_t RF0WL : 1; /*!< [1:1] : Rx FIFO 0 Watermark Reached Line                                <br>
                                         0 Interrupt source is assigned to Interrupt Line 0 1 Interrupt source is
                                         assigned to Interrupt Line 1 Reset type: SYSRSn<br>. */
            __IOM uint32_t RF0FL : 1; /*!< [2:2] : Rx FIFO 0 Full Line                                             <br>
                                         0 Interrupt source is assigned to Interrupt Line 0 1 Interrupt source is
                                         assigned to Interrupt Line 1 Reset type: SYSRSn<br>. */
            __IOM uint32_t RF0LL : 1; /*!< [3:3] : Rx FIFO 0 Message Lost Line                                     <br>
                                         0 Interrupt source is assigned to Interrupt Line 0 1 Interrupt source is
                                         assigned to Interrupt Line 1 Reset type: SYSRSn<br>. */
            __IOM uint32_t RF1NL : 1; /*!< [4:4] : Rx FIFO 1 New Message Line                                      <br>
                                         0 Interrupt source is assigned to Interrupt Line 0 1 Interrupt source is
                                         assigned to Interrupt Line 1 Reset type: SYSRSn<br>. */
            __IOM uint32_t RF1WL : 1; /*!< [5:5] : Rx FIFO 1 Watermark Reached Line                                <br>
                                         0 Interrupt source is assigned to Interrupt Line 0 1 Interrupt source is
                                         assigned to Interrupt Line 1 Reset type: SYSRSn<br>. */
            __IOM uint32_t RF1FL : 1; /*!< [6:6] : Rx FIFO 1 Full Line                                             <br>
                                         0 Interrupt source is assigned to Interrupt Line 0 1 Interrupt source is
                                         assigned to Interrupt Line 1 Reset type: SYSRSn<br>. */
            __IOM uint32_t RF1LL : 1; /*!< [7:7] : Rx FIFO 1 Message Lost Line                                     <br>
                                         0 Interrupt source is assigned to Interrupt Line 0 1 Interrupt source is
                                         assigned to Interrupt Line 1 Reset type: SYSRSn<br>. */
            __IOM uint32_t HPML : 1;  /*!< [8:8] : High Priority Message Line                                      <br>
                                         0 Interrupt source is assigned to Interrupt Line 0 1 Interrupt source is
                                         assigned to Interrupt Line 1 Reset type: SYSRSn<br>. */
            __IOM uint32_t TCL : 1; /*!< [9:9] : Transmission Completed Line                                     <br>  0
                                       Interrupt source is assigned to Interrupt Line 0 1 Interrupt source is assigned
                                       to Interrupt Line 1 Reset type: SYSRSn<br>. */
            __IOM uint32_t TCFL : 1; /*!< [10:10] : Transmission Cancellation Finished Line                         <br>
                                        0 Interrupt source is assigned to Interrupt Line 0 1 Interrupt source is
                                        assigned to Interrupt Line 1 Reset type: SYSRSn<br>. */
            __IOM uint32_t TFEL : 1; /*!< [11:11] : Tx FIFO Empty Line                                              <br>
                                        0 Interrupt source is assigned to Interrupt Line 0 1 Interrupt source is
                                        assigned to Interrupt Line 1 Reset type: SYSRSn<br>. */
            __IOM uint32_t TEFNL : 1; /*!< [12:12] : Tx Event FIFO New Entry Line <br>  0 Interrupt source is assigned
                                         to Interrupt Line 0 1 Interrupt source is assigned to Interrupt Line 1 Reset
                                         type: SYSRSn<br>. */
            __IOM uint32_t TEFWL : 1; /*!< [13:13] : Tx Event FIFO Watermark Reached Line <br>  0 Interrupt source is
                                         assigned to Interrupt Line 0 1 Interrupt source is assigned to Interrupt Line 1
                                         Reset type: SYSRSn<br>. */
            __IOM uint32_t TEFFL : 1; /*!< [14:14] : Tx Event FIFO Full Line <br>  0 Interrupt source is assigned to
                                         Interrupt Line 0 1 Interrupt source is assigned to Interrupt Line 1 Reset type:
                                         SYSRSn<br>. */
            __IOM uint32_t TEFLL : 1; /*!< [15:15] : Tx Event FIFO Element Lost Line <br>  0 Interrupt source is
                                         assigned to Interrupt Line 0 1 Interrupt source is assigned to Interrupt Line 1
                                         Reset type: SYSRSn<br>. */
            __IOM uint32_t TSWL : 1; /*!< [16:16] : Timestamp Wraparound Line                                       <br>
                                        0 Interrupt source is assigned to Interrupt Line 0 1 Interrupt source is
                                        assigned to Interrupt Line 1 Reset type: SYSRSn<br>. */
            __IOM uint32_t MRAFL : 1; /*!< [17:17] : Message RAM Access Failure Line <br>  0 Interrupt source is
                                         assigned to Interrupt Line 0 1 Interrupt source is assigned to Interrupt Line 1
                                         Reset type: SYSRSn<br>. */
            __IOM uint32_t TOOL : 1; /*!< [18:18] : Timeout Occurred Line                                           <br>
                                        0 Interrupt source is assigned to Interrupt Line 0 1 Interrupt source is
                                        assigned to Interrupt Line 1 Reset type: SYSRSn<br>. */
            __IOM uint32_t DRXL : 1; /*!< [19:19] : Message Stored to Dedicated Rx Buffer Line                      <br>
                                        0 Interrupt source is assigned to Interrupt Line 0 1 Interrupt source is
                                        assigned to Interrupt Line 1 Reset type: SYSRSn<br>. */
            __IOM uint32_t BECL : 1; /*!< [20:20] : Bit Error Corrected Line                                        <br>
                                        A separate interrupt line reserved for corrected bit errors is provided via the
                                        MCAN_ERROR_REGS. */
            __IOM uint32_t BEUL : 1; /*!< [21:21] : Bit Error Uncorrected Line                                      <br>
                                        0 Interrupt source is assigned to Interrupt Line 0 1 Interrupt source is
                                        assigned to Interrupt Line 1 Reset type: SYSRSn<br>. */
            __IOM uint32_t ELOL : 1; /*!< [22:22] : Error Logging Overflow Line                                     <br>
                                        0 Interrupt source is assigned to Interrupt Line 0 1 Interrupt source is
                                        assigned to Interrupt Line 1 Reset type: SYSRSn<br>. */
            __IOM uint32_t EPL : 1;  /*!< [23:23] : Error Passive Line                                              <br>
                                        0 Interrupt source is assigned to Interrupt Line 0 1 Interrupt source is assigned
                                        to Interrupt Line 1 Reset type: SYSRSn<br>. */
            __IOM uint32_t EWL : 1;  /*!< [24:24] : Warning Status Line                                             <br>
                                        0 Interrupt source is assigned to Interrupt Line 0 1 Interrupt source is assigned
                                        to Interrupt Line 1 Reset type: SYSRSn<br>. */
            __IOM uint32_t BOL : 1;  /*!< [25:25] : Bus_Off Status Line                                             <br>
                                        0 Interrupt source is assigned to Interrupt Line 0 1 Interrupt source is assigned
                                        to Interrupt Line 1 Reset type: SYSRSn<br>. */
            __IOM uint32_t WDIL : 1; /*!< [26:26] : Watchdog Interrupt Line                                         <br>
                                        0 Interrupt source is assigned to Interrupt Line 0 1 Interrupt source is
                                        assigned to Interrupt Line 1 Reset type: SYSRSn<br>. */
            __IOM uint32_t PEAL : 1; /*!< [27:27] : Protocol Error in Arbitration Phase Line                        <br>
                                        0 Interrupt source is assigned to Interrupt Line 0 1 Interrupt source is
                                        assigned to Interrupt Line 1 Reset type: SYSRSn<br>. */
            __IOM uint32_t PEDL : 1; /*!< [28:28] : Protocol Error in Data Phase Line                               <br>
                                        0 Interrupt source is assigned to Interrupt Line 0 1 Interrupt source is
                                        assigned to Interrupt Line 1 Reset type: SYSRSn<br>. */
            __IOM uint32_t ARAL : 1; /*!< [29:29] : Access to Reserved Address Line                                 <br>
                                        0 Interrupt source is assigned to Interrupt Line 0 1 Interrupt source is
                                        assigned to Interrupt Line 1 Reset type: SYSRSn<br>. */
            uint32_t RSV_0 : 2;      /*!< [31:30] : reserved. */
        } ILSb;
    };

    union
    {
        __IOM uint32_t ILE; /*!< 0x0000005c */

        struct
        {
            __IOM uint32_t EINT0 : 1; /*!< [0:0] : Enable Interrupt Line 0                                         <br>
                                         0 Interrupt Line 0 is disabled                                  <br>  1
                                         Interrupt Line 0 is enabled Reset type: SYSRSn                <br>. */
            __IOM uint32_t EINT1 : 1; /*!< [1:1] : Enable Interrupt Line 1                                         <br>
                                         0 Interrupt Line 1 is disabled                                  <br>  1
                                         Interrupt Line 1 is enabled Reset type: SYSRSn                <br>. */
            uint32_t RSV_0 : 30;      /*!< [31:2] : reserved. */
        } ILEb;
    };

    uint8_t RSV_0X60[32]; /*!< 0x00000060~0x0000007f : reserved */

    union
    {
        __IOM uint32_t GFC; /*!< 0x00000080 */

        struct
        {
            __IOM uint32_t
                RRFE : 1; /*!< [0:0] : Reject Remote Frames Extended                                   <br>  0 Filter
                             remote frames with 29-bit extended IDs                 <br>  1 Reject all remote frames
                             with 29-bit extended IDs Qualified Write is possible only with CCCR. */
            __IOM uint32_t
                RRFS : 1; /*!< [1:1] : Reject Remote Frames Standard                                   <br>  0 Filter
                             remote frames with 11-bit standard IDs                 <br>  1 Reject all remote frames
                             with 11-bit standard IDs Qualified Write is possible only with CCCR. */
            __IOM uint32_t ANFE  : 2;  /*!< [3:2] : Accept Non-matching Frames Extended. */
            __IOM uint32_t ANFS  : 2;  /*!< [5:4] : Accept Non-matching Frames Standard. */
            uint32_t       RSV_0 : 26; /*!< [31:6] : reserved. */
        } GFCb;
    };

    union
    {
        __IOM uint32_t SIDFC; /*!< 0x00000084 */

        struct
        {
            uint32_t       RSV_1 : 2;  /*!< [1:0] : reserved. */
            __IOM uint32_t FLSSA : 14; /*!< [15:2] : Filter List Standard Start Address. */
            __IOM uint32_t LSS : 8; /*!< [23:16] : List Size Standard                                              <br>
                                       0 No standard Message ID filter                                 <br>  1-128
                                       Number of standard Message ID filter elements             <br>  >128 Values
                                       greater than 128 are interpreted as 128 Reset type: SYSRSn<br>. */
            uint32_t RSV_0 : 8;     /*!< [31:24] : reserved. */
        } SIDFCb;
    };

    union
    {
        __IOM uint32_t XIDFC; /*!< 0x00000088 */

        struct
        {
            uint32_t       RSV_1 : 2;  /*!< [1:0] : reserved. */
            __IOM uint32_t FLESA : 14; /*!< [15:2] : Filter List Extended Start Address. */
            __IOM uint32_t LSE : 7; /*!< [22:16] : List Size Extended                                              <br>
                                       0 No extended Message ID filter                                 <br>  1-64 Number
                                       of extended Message ID filter elements              <br>  >64 Values greater than
                                       64 are interpreted as 64 Qualified Write is possible only with CCCR. */
            uint32_t RSV_0 : 9;     /*!< [31:23] : reserved. */
        } XIDFCb;
    };

    uint8_t RSV_0X8C[4]; /*!< 0x0000008c~0x0000008f : reserved */

    union
    {
        __IOM uint32_t XIDAM; /*!< 0x00000090 */

        struct
        {
            __IOM uint32_t EIDM  : 29; /*!< [28:0] : Extended ID Mask. */
            uint32_t       RSV_0 : 3;  /*!< [31:29] : reserved. */
        } XIDAMb;
    };

    union
    {
        __IM uint32_t HPMS; /*!< 0x00000094 */

        struct
        {
            __IM uint32_t BIDX : 6; /*!< [5:0] : Buffer Index. */
            __IM uint32_t MSI : 2; /*!< [7:6] : Message Storage Indicator 00 No FIFO selected                   <br>  01
                                      FIFO message lost                                            <br>  10 Message
                                      stored in FIFO 0 <br>  11 Message stored in FIFO 1 Reset type: SYSRSn <br>. */
            __IM uint32_t FIDX  : 7;  /*!< [14:8] : Filter Index. */
            __IM uint32_t FLST  : 1;  /*!< [15:15] : Filter List. */
            uint32_t      RSV_0 : 16; /*!< [31:16] : reserved. */
        } HPMSb;
    };

    union
    {
        __IOM uint32_t NDAT1; /*!< 0x00000098 */

        struct
        {
            __IOM uint32_t ND0 : 1; /*!< [0:0] : New Data RX Buffer 0 0 Rx Buffer not updated                    <br>  1
                                       Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND1 : 1; /*!< [1:1] : New Data RX Buffer 1 0 Rx Buffer not updated                    <br>  1
                                       Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND2 : 1; /*!< [2:2] : New Data RX Buffer 2 0 Rx Buffer not updated                    <br>  1
                                       Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND3 : 1; /*!< [3:3] : New Data RX Buffer 3 0 Rx Buffer not updated                    <br>  1
                                       Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND4 : 1; /*!< [4:4] : New Data RX Buffer 4 0 Rx Buffer not updated                    <br>  1
                                       Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND5 : 1; /*!< [5:5] : New Data RX Buffer 5 0 Rx Buffer not updated                    <br>  1
                                       Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND6 : 1; /*!< [6:6] : New Data RX Buffer 6 0 Rx Buffer not updated                    <br>  1
                                       Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND7 : 1; /*!< [7:7] : New Data RX Buffer 7 0 Rx Buffer not updated                    <br>  1
                                       Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND8 : 1; /*!< [8:8] : New Data RX Buffer 8 0 Rx Buffer not updated                    <br>  1
                                       Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND9 : 1; /*!< [9:9] : New Data RX Buffer 9 0 Rx Buffer not updated                    <br>  1
                                       Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND10 : 1; /*!< [10:10] : New Data RX Buffer 10 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND11 : 1; /*!< [11:11] : New Data RX Buffer 11 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND12 : 1; /*!< [12:12] : New Data RX Buffer 12 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND13 : 1; /*!< [13:13] : New Data RX Buffer 13 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND14 : 1; /*!< [14:14] : New Data RX Buffer 14 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND15 : 1; /*!< [15:15] : New Data RX Buffer 15 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND16 : 1; /*!< [16:16] : New Data RX Buffer 16 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND17 : 1; /*!< [17:17] : New Data RX Buffer 17 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND18 : 1; /*!< [18:18] : New Data RX Buffer 18 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND19 : 1; /*!< [19:19] : New Data RX Buffer 19 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND20 : 1; /*!< [20:20] : New Data RX Buffer 20 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND21 : 1; /*!< [21:21] : New Data RX Buffer 21 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND22 : 1; /*!< [22:22] : New Data RX Buffer 22 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND23 : 1; /*!< [23:23] : New Data RX Buffer 23 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND24 : 1; /*!< [24:24] : New Data RX Buffer 24 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND25 : 1; /*!< [25:25] : New Data RX Buffer 25 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND26 : 1; /*!< [26:26] : New Data RX Buffer 26 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND27 : 1; /*!< [27:27] : New Data RX Buffer 27 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND28 : 1; /*!< [28:28] : New Data RX Buffer 28 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND29 : 1; /*!< [29:29] : New Data RX Buffer 29 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND30 : 1; /*!< [30:30] : New Data RX Buffer 30 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND31 : 1; /*!< [31:31] : New Data RX Buffer 31 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
        } NDAT1b;
    };

    union
    {
        __IOM uint32_t NDAT2; /*!< 0x0000009c */

        struct
        {
            __IOM uint32_t ND32 : 1; /*!< [0:0] : New Data RX Buffer 32 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND33 : 1; /*!< [1:1] : New Data RX Buffer 33 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND34 : 1; /*!< [2:2] : New Data RX Buffer 34 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND35 : 1; /*!< [3:3] : New Data RX Buffer 35 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND36 : 1; /*!< [4:4] : New Data RX Buffer 36 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND37 : 1; /*!< [5:5] : New Data RX Buffer 37 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND38 : 1; /*!< [6:6] : New Data RX Buffer 38 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND39 : 1; /*!< [7:7] : New Data RX Buffer 39 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND40 : 1; /*!< [8:8] : New Data RX Buffer 40 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND41 : 1; /*!< [9:9] : New Data RX Buffer 41 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND42 : 1; /*!< [10:10] : New Data RX Buffer 42 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND43 : 1; /*!< [11:11] : New Data RX Buffer 43 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND44 : 1; /*!< [12:12] : New Data RX Buffer 44 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND45 : 1; /*!< [13:13] : New Data RX Buffer 45 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND46 : 1; /*!< [14:14] : New Data RX Buffer 46 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND47 : 1; /*!< [15:15] : New Data RX Buffer 47 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND48 : 1; /*!< [16:16] : New Data RX Buffer 48 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND49 : 1; /*!< [17:17] : New Data RX Buffer 49 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND50 : 1; /*!< [18:18] : New Data RX Buffer 50 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND51 : 1; /*!< [19:19] : New Data RX Buffer 51 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND52 : 1; /*!< [20:20] : New Data RX Buffer 52 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND53 : 1; /*!< [21:21] : New Data RX Buffer 53 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND54 : 1; /*!< [22:22] : New Data RX Buffer 54 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND55 : 1; /*!< [23:23] : New Data RX Buffer 55 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND56 : 1; /*!< [24:24] : New Data RX Buffer 56 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND57 : 1; /*!< [25:25] : New Data RX Buffer 57 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND58 : 1; /*!< [26:26] : New Data RX Buffer 58 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND59 : 1; /*!< [27:27] : New Data RX Buffer 59 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND60 : 1; /*!< [28:28] : New Data RX Buffer 60 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND61 : 1; /*!< [29:29] : New Data RX Buffer 61 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND62 : 1; /*!< [30:30] : New Data RX Buffer 62 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
            __IOM uint32_t ND63 : 1; /*!< [31:31] : New Data RX Buffer 63 0 Rx Buffer not updated                   <br>
                                        1 Rx Buffer updated from new message Reset type: SYSRSn         <br>. */
        } NDAT2b;
    };

    union
    {
        __IOM uint32_t RXF0C; /*!< 0x000000a0 */

        struct
        {
            uint32_t       RSV_1 : 2;  /*!< [1:0] : reserved. */
            __IOM uint32_t F0SA  : 14; /*!< [15:2] : Rx FIFO 0 Start Address. */
            __IOM uint32_t F0S   : 7;  /*!< [22:16] : Rx FIFO 0 Size. */
            uint32_t       RSV_0 : 1;  /*!< [23:23] : reserved. */
            __IOM uint32_t F0WM : 7; /*!< [30:24] : Rx FIFO 0 Watermark                                             <br>
                                        0 Watermark interrupt disabled                                  <br>  1-64 Level
                                        for Rx FIFO 0 watermark interrupt (IR. */
            __IOM uint32_t F0OM : 1; /*!< [31:31] : FIFO 0 Operation Mode. */
        } RXF0Cb;
    };

    union
    {
        __IM uint32_t RXF0S; /*!< 0x000000a4 */

        struct
        {
            __IM uint32_t F0FL  : 7; /*!< [6:0] : Rx FIFO 0 Fill Level. */
            uint32_t      RSV_3 : 1; /*!< [7:7] : reserved. */
            __IM uint32_t F0GI  : 6; /*!< [13:8] : Rx FIFO 0 Get Index. */
            uint32_t      RSV_2 : 2; /*!< [15:14] : reserved. */
            __IM uint32_t F0PI  : 6; /*!< [21:16] : Rx FIFO 0 Put Index. */
            uint32_t      RSV_1 : 2; /*!< [23:22] : reserved. */
            __IM uint32_t
                F0F : 1; /*!< [24:24] : Rx FIFO 0 Full                                                  <br>  0 Rx FIFO
                            0 not full                                            <br>  1 Rx FIFO 0 full <br>  Reset
                            type: SYSRSn                                              <br>. */
            __IM uint32_t RF0L  : 1; /*!< [25:25] : Rx FIFO 0 Message Lost. */
            uint32_t      RSV_0 : 6; /*!< [31:26] : reserved. */
        } RXF0Sb;
    };

    union
    {
        __IOM uint32_t RXF0A; /*!< 0x000000a8 */

        struct
        {
            __IOM uint32_t F0AI  : 6;  /*!< [5:0] : Rx FIFO 0 Acknowledge Index. */
            uint32_t       RSV_0 : 26; /*!< [31:6] : reserved. */
        } RXF0Ab;
    };

    union
    {
        __IOM uint32_t RXBC; /*!< 0x000000ac */

        struct
        {
            uint32_t       RSV_1 : 2;  /*!< [1:0] : reserved. */
            __IOM uint32_t RBSA  : 14; /*!< [15:2] : Rx Buffer Start Address. */
            uint32_t       RSV_0 : 16; /*!< [31:16] : reserved. */
        } RXBCb;
    };

    union
    {
        __IOM uint32_t RXF1C; /*!< 0x000000b0 */

        struct
        {
            uint32_t       RSV_1 : 2;  /*!< [1:0] : reserved. */
            __IOM uint32_t F1SA  : 14; /*!< [15:2] : Rx FIFO 1 Start Address Start address of Rx FIFO 1 in Message RAM
                                          (32-bit word address). */
            __IOM uint32_t F1S   : 7;  /*!< [22:16] : Rx FIFO 1 Size. */
            uint32_t       RSV_0 : 1;  /*!< [23:23] : reserved. */
            __IOM uint32_t F1WM : 7; /*!< [30:24] : Rx FIFO 1 Watermark                                             <br>
                                        0 Watermark interrupt disabled                                  <br>  1-64 Level
                                        for Rx FIFO 1 watermark interrupt (IR. */
            __IOM uint32_t F1OM : 1; /*!< [31:31] : FIFO 1 Operation Mode. */
        } RXF1Cb;
    };

    union
    {
        __IM uint32_t RXF1S; /*!< 0x000000b4 */

        struct
        {
            __IM uint32_t F1FL  : 7; /*!< [6:0] : Rx FIFO 1 Fill Level. */
            uint32_t      RSV_3 : 1; /*!< [7:7] : reserved. */
            __IM uint32_t F1GI  : 6; /*!< [13:8] : Rx FIFO 1 Get Index. */
            uint32_t      RSV_2 : 2; /*!< [15:14] : reserved. */
            __IM uint32_t F1PI  : 6; /*!< [21:16] : Rx FIFO 1 Put Index. */
            uint32_t      RSV_1 : 2; /*!< [23:22] : reserved. */
            __IM uint32_t F1F   : 1; /*!< [24:24] : Rx FIFO 1 Full                                                  <br>
                                        0 Rx FIFO 1 not full                                            <br>  1 Rx FIFO 1
                                        full Reset type: SYSRSn                             <br>. */
            __IM uint32_t RF1L  : 1; /*!< [25:25] : Rx FIFO 1 Message Lost. */
            uint32_t      RSV_0 : 4; /*!< [29:26] : reserved. */
            __IM uint32_t
                DMS : 2; /*!< [31:30] : Debug Message Status                                            <br>  00 Idle
                            state, wait for reception of debug messages, DMA request is cleared<br>  01 Debug message A
                            received                                     <br>  10 Debug messages A, B received <br>  11
                            Debug messages A, B, C received, DMA request is set Reset type: SYSRSn<br>. */
        } RXF1Sb;
    };

    union
    {
        __IOM uint32_t RXF1A; /*!< 0x000000b8 */

        struct
        {
            __IOM uint32_t F1AI  : 6;  /*!< [5:0] : Rx FIFO 1 Acknowledge Index. */
            uint32_t       RSV_0 : 26; /*!< [31:6] : reserved. */
        } RXF1Ab;
    };

    union
    {
        __IOM uint32_t RXESC; /*!< 0x000000bc */

        struct
        {
            __IOM uint32_t
                F0DS : 3; /*!< [2:0] : Rx FIFO 0 Data Field Size 000 8 byte data field                 <br>  001 12 byte
                             data field                                          <br>  010 16 byte data field <br>  011
                             20 byte data field                                          <br>  100 24 byte data field
                             <br>  101 32 byte data field                                          <br>  110 48 byte
                             data field                                          <br>  111 64 byte data field <br> Note:
                             In case the data field size of an accepted CAN frame exceeds the data field size configured
                             for the matching Rx Buffer or Rx FIFO, only the number of bytes as configured by RXESC are
                             stored to the Rx Buffer resp. */
            uint32_t RSV_2 : 1; /*!< [3:3] : reserved. */
            __IOM uint32_t
                F1DS : 3; /*!< [6:4] : Rx FIFO 1 Data Field Size 000 8 byte data field                 <br>  001 12 byte
                             data field                                          <br>  010 16 byte data field <br>  011
                             20 byte data field                                          <br>  100 24 byte data field
                             <br>  101 32 byte data field                                          <br>  110 48 byte
                             data field                                          <br>  111 64 byte data field <br> Note:
                             In case the data field size of an accepted CAN frame exceeds the data field size configured
                             for the matching Rx Buffer or Rx FIFO, only the number of bytes as configured by RXESC are
                             stored to the Rx Buffer resp. */
            uint32_t       RSV_1 : 1; /*!< [7:7] : reserved. */
            __IOM uint32_t RBDS  : 3; /*!< [10:8] : Rx Buffer Data Field Size 000 8 byte data field                 <br>
                                         001 12  byte data field                                          <br>  010 16
                                         byte data field <br>  011 20 byte data field  <br>  100 24 byte data  field  <br>
                                         101 32 byte data field <br>  110 48  byte data field  <br>  111 64 byte data
                                         field  <br>  Note: In case the data field size of an accepted CAN frame exceeds
                                         the data  field size  configured for the matching Rx Buffer or Rx FIFO, only the
                                         number of  bytes as configured by  RXESC are stored to the Rx Buffer resp. */
            uint32_t RSV_0 : 21;      /*!< [31:11] : reserved. */
        } RXESCb;
    };

    union
    {
        __IOM uint32_t TXBC; /*!< 0x000000c0 */

        struct
        {
            uint32_t       RSV_2 : 2;  /*!< [1:0] : reserved. */
            __IOM uint32_t TBSA  : 14; /*!< [15:2] : Tx Buffers Start Address. */
            __IOM uint32_t NDTB : 6; /*!< [21:16] : Number of Dedicated Transmit Buffers 0 No Dedicated Tx Buffers  <br>
                                        1-32 Number of Dedicated Tx Buffers                             <br>  >32 Values
                                        greater than 32 are interpreted as 32                <br>  Note: Be aware that
                                        the sum of TFQS and NDTB may be not greater than 32. */
            uint32_t       RSV_1 : 2; /*!< [23:22] : reserved. */
            __IOM uint32_t TFQS : 6; /*!< [29:24] : Transmit FIFO/Queue Size 0 No Tx FIFO/Queue                     <br>
                                        1-32 Number of Tx Buffers used for Tx FIFO/Queue                <br>  >32 Values
                                        greater than 32 are interpreted as 32                <br>  Note: Be aware that
                                        the sum of TFQS and NDTB may be not greater than 32. */
            __IOM uint32_t TFQM : 1; /*!< [30:30] : Tx FIFO/Queue Mode 0 Tx FIFO operation  1 Tx Queue operation    <br>
                                        Qualified Write is possible only with CCCR. */
            uint32_t RSV_0 : 1;      /*!< [31:31] : reserved. */
        } TXBCb;
    };

    union
    {
        __IM uint32_t TXFQS; /*!< 0x000000c4 */

        struct
        {
            __IM uint32_t TFFL  : 6; /*!< [5:0] : Tx FIFO Free Level. */
            uint32_t      RSV_2 : 2; /*!< [7:6] : reserved. */
            __IM uint32_t TFGI  : 5; /*!< [12:8] : Tx FIFO Get Index. */
            uint32_t      RSV_1 : 3; /*!< [15:13] : reserved. */
            __IM uint32_t TFQP  : 5; /*!< [20:16] : Tx FIFO/Queue Put Index. */
            __IM uint32_t TFQF  : 1; /*!< [21:21] : Tx FIFO/Queue Full                                              <br>
                                        0 Tx FIFO/Queue not full 1 Tx FIFO/Queue full Reset type: SYSRSn<br>. */
            uint32_t RSV_0 : 10;     /*!< [31:22] : reserved. */
        } TXFQSb;
    };

    union
    {
        __IOM uint32_t TXESC; /*!< 0x000000c8 */

        struct
        {
            __IOM uint32_t
                TBDS : 3; /*!< [2:0] : Tx Buffer Data Field Size 000 8 byte data field                 <br>  001 12 byte
                             data field                                          <br>  010 16 byte data field <br>  011
                             20 byte data field                                          <br>  100 24 byte data field
                             <br>  101 32 byte data field                                          <br>  110 48 byte
                             data field                                          <br>  111 64 byte data field <br> Note:
                             In case the data length code DLC of a Tx Buffer element is configured to a value higher
                             than the Tx Buffer data field size TXESC. */
            uint32_t RSV_0 : 29; /*!< [31:3] : reserved. */
        } TXESCb;
    };

    union
    {
        __IM uint32_t TXBRP; /*!< 0x000000cc */

        struct
        {
            __IM uint32_t TRP0  : 1; /*!< [0:0] : Transmission Request Pending 0. */
            __IM uint32_t TRP1  : 1; /*!< [1:1] : Transmission Request Pending 1. */
            __IM uint32_t TRP2  : 1; /*!< [2:2] : Transmission Request Pending 2. */
            __IM uint32_t TRP3  : 1; /*!< [3:3] : Transmission Request Pending 3. */
            __IM uint32_t TRP4  : 1; /*!< [4:4] : Transmission Request Pending 4. */
            __IM uint32_t TRP5  : 1; /*!< [5:5] : Transmission Request Pending 5. */
            __IM uint32_t TRP6  : 1; /*!< [6:6] : Transmission Request Pending 6. */
            __IM uint32_t TRP7  : 1; /*!< [7:7] : Transmission Request Pending 7. */
            __IM uint32_t TRP8  : 1; /*!< [8:8] : Transmission Request Pending 8. */
            __IM uint32_t TRP9  : 1; /*!< [9:9] : Transmission Request Pending 9. */
            __IM uint32_t TRP10 : 1; /*!< [10:10] : Transmission Request Pending 10. */
            __IM uint32_t TRP11 : 1; /*!< [11:11] : Transmission Request Pending 11. */
            __IM uint32_t TRP12 : 1; /*!< [12:12] : Transmission Request Pending 12. */
            __IM uint32_t TRP13 : 1; /*!< [13:13] : Transmission Request Pending 13. */
            __IM uint32_t TRP14 : 1; /*!< [14:14] : Transmission Request Pending 14. */
            __IM uint32_t TRP15 : 1; /*!< [15:15] : Transmission Request Pending 15. */
            __IM uint32_t TRP16 : 1; /*!< [16:16] : Transmission Request Pending 16. */
            __IM uint32_t TRP17 : 1; /*!< [17:17] : Transmission Request Pending 17. */
            __IM uint32_t TRP18 : 1; /*!< [18:18] : Transmission Request Pending 18. */
            __IM uint32_t TRP19 : 1; /*!< [19:19] : Transmission Request Pending 19. */
            __IM uint32_t TRP20 : 1; /*!< [20:20] : Transmission Request Pending 20. */
            __IM uint32_t TRP21 : 1; /*!< [21:21] : Transmission Request Pending 21. */
            __IM uint32_t TRP22 : 1; /*!< [22:22] : Transmission Request Pending 22. */
            __IM uint32_t TRP23 : 1; /*!< [23:23] : Transmission Request Pending 23. */
            __IM uint32_t TRP24 : 1; /*!< [24:24] : Transmission Request Pending 24. */
            __IM uint32_t TRP25 : 1; /*!< [25:25] : Transmission Request Pending 25. */
            __IM uint32_t TRP26 : 1; /*!< [26:26] : Transmission Request Pending 26. */
            __IM uint32_t TRP27 : 1; /*!< [27:27] : Transmission Request Pending 27. */
            __IM uint32_t TRP28 : 1; /*!< [28:28] : Transmission Request Pending 28. */
            __IM uint32_t TRP29 : 1; /*!< [29:29] : Transmission Request Pending 29. */
            __IM uint32_t TRP30 : 1; /*!< [30:30] : Transmission Request Pending 30. */
            __IM uint32_t TRP31 : 1; /*!< [31:31] : Transmission Request Pending 31. */
        } TXBRPb;
    };

    union
    {
        __IOM uint32_t TXBAR; /*!< 0x000000d0 */

        struct
        {
            __IOM uint32_t AR0  : 1; /*!< [0:0] : Add Request 0. */
            __IOM uint32_t AR1  : 1; /*!< [1:1] : Add Request 1. */
            __IOM uint32_t AR2  : 1; /*!< [2:2] : Add Request 2. */
            __IOM uint32_t AR3  : 1; /*!< [3:3] : Add Request 3. */
            __IOM uint32_t AR4  : 1; /*!< [4:4] : Add Request 4. */
            __IOM uint32_t AR5  : 1; /*!< [5:5] : Add Request 5. */
            __IOM uint32_t AR6  : 1; /*!< [6:6] : Add Request 6. */
            __IOM uint32_t AR7  : 1; /*!< [7:7] : Add Request 7. */
            __IOM uint32_t AR8  : 1; /*!< [8:8] : Add Request 8. */
            __IOM uint32_t AR9  : 1; /*!< [9:9] : Add Request 9. */
            __IOM uint32_t AR10 : 1; /*!< [10:10] : Add Request 10. */
            __IOM uint32_t AR11 : 1; /*!< [11:11] : Add Request 11. */
            __IOM uint32_t AR12 : 1; /*!< [12:12] : Add Request 12. */
            __IOM uint32_t AR13 : 1; /*!< [13:13] : Add Request 13. */
            __IOM uint32_t AR14 : 1; /*!< [14:14] : Add Request 14. */
            __IOM uint32_t AR15 : 1; /*!< [15:15] : Add Request 15. */
            __IOM uint32_t AR16 : 1; /*!< [16:16] : Add Request 16. */
            __IOM uint32_t AR17 : 1; /*!< [17:17] : Add Request 17. */
            __IOM uint32_t AR18 : 1; /*!< [18:18] : Add Request 18. */
            __IOM uint32_t AR19 : 1; /*!< [19:19] : Add Request 19. */
            __IOM uint32_t AR20 : 1; /*!< [20:20] : Add Request 20. */
            __IOM uint32_t AR21 : 1; /*!< [21:21] : Add Request 21. */
            __IOM uint32_t AR22 : 1; /*!< [22:22] : Add Request 22. */
            __IOM uint32_t AR23 : 1; /*!< [23:23] : Add Request 23. */
            __IOM uint32_t AR24 : 1; /*!< [24:24] : Add Request 24. */
            __IOM uint32_t AR25 : 1; /*!< [25:25] : Add Request 25. */
            __IOM uint32_t AR26 : 1; /*!< [26:26] : Add Request 26. */
            __IOM uint32_t AR27 : 1; /*!< [27:27] : Add Request 27. */
            __IOM uint32_t AR28 : 1; /*!< [28:28] : Add Request 28. */
            __IOM uint32_t AR29 : 1; /*!< [29:29] : Add Request 29. */
            __IOM uint32_t AR30 : 1; /*!< [30:30] : Add Request 30. */
            __IOM uint32_t AR31 : 1; /*!< [31:31] : Add Request 31. */
        } TXBARb;
    };

    union
    {
        __IOM uint32_t TXBCR; /*!< 0x000000d4 */

        struct
        {
            __IOM uint32_t CR0  : 1; /*!< [0:0] : Cancellation Request 0. */
            __IOM uint32_t CR1  : 1; /*!< [1:1] : Cancellation Request 1. */
            __IOM uint32_t CR2  : 1; /*!< [2:2] : Cancellation Request 2. */
            __IOM uint32_t CR3  : 1; /*!< [3:3] : Cancellation Request 3. */
            __IOM uint32_t CR4  : 1; /*!< [4:4] : Cancellation Request 4. */
            __IOM uint32_t CR5  : 1; /*!< [5:5] : Cancellation Request 5. */
            __IOM uint32_t CR6  : 1; /*!< [6:6] : Cancellation Request 6. */
            __IOM uint32_t CR7  : 1; /*!< [7:7] : Cancellation Request 7. */
            __IOM uint32_t CR8  : 1; /*!< [8:8] : Cancellation Request 8. */
            __IOM uint32_t CR9  : 1; /*!< [9:9] : Cancellation Request 9. */
            __IOM uint32_t CR10 : 1; /*!< [10:10] : Cancellation Request 10. */
            __IOM uint32_t CR11 : 1; /*!< [11:11] : Cancellation Request 11. */
            __IOM uint32_t CR12 : 1; /*!< [12:12] : Cancellation Request 12. */
            __IOM uint32_t CR13 : 1; /*!< [13:13] : Cancellation Request 13. */
            __IOM uint32_t CR14 : 1; /*!< [14:14] : Cancellation Request 14. */
            __IOM uint32_t CR15 : 1; /*!< [15:15] : Cancellation Request 15. */
            __IOM uint32_t CR16 : 1; /*!< [16:16] : Cancellation Request 16. */
            __IOM uint32_t CR17 : 1; /*!< [17:17] : Cancellation Request 17. */
            __IOM uint32_t CR18 : 1; /*!< [18:18] : Cancellation Request 18. */
            __IOM uint32_t CR19 : 1; /*!< [19:19] : Cancellation Request 19. */
            __IOM uint32_t CR20 : 1; /*!< [20:20] : Cancellation Request 20. */
            __IOM uint32_t CR21 : 1; /*!< [21:21] : Cancellation Request 21. */
            __IOM uint32_t CR22 : 1; /*!< [22:22] : Cancellation Request 22. */
            __IOM uint32_t CR23 : 1; /*!< [23:23] : Cancellation Request 23. */
            __IOM uint32_t CR24 : 1; /*!< [24:24] : Cancellation Request 24. */
            __IOM uint32_t CR25 : 1; /*!< [25:25] : Cancellation Request 25. */
            __IOM uint32_t CR26 : 1; /*!< [26:26] : Cancellation Request 26. */
            __IOM uint32_t CR27 : 1; /*!< [27:27] : Cancellation Request 27. */
            __IOM uint32_t CR28 : 1; /*!< [28:28] : Cancellation Request 28. */
            __IOM uint32_t CR29 : 1; /*!< [29:29] : Cancellation Request 29. */
            __IOM uint32_t CR30 : 1; /*!< [30:30] : Cancellation Request 30. */
            __IOM uint32_t CR31 : 1; /*!< [31:31] : Cancellation Request 31. */
        } TXBCRb;
    };

    union
    {
        __IM uint32_t TXBTO; /*!< 0x000000d8 */

        struct
        {
            __IM uint32_t TO0  : 1; /*!< [0:0] : Transmission Occurred 0. */
            __IM uint32_t TO1  : 1; /*!< [1:1] : Transmission Occurred 1. */
            __IM uint32_t TO2  : 1; /*!< [2:2] : Transmission Occurred 2. */
            __IM uint32_t TO3  : 1; /*!< [3:3] : Transmission Occurred 3. */
            __IM uint32_t TO4  : 1; /*!< [4:4] : Transmission Occurred 4. */
            __IM uint32_t TO5  : 1; /*!< [5:5] : Transmission Occurred 5. */
            __IM uint32_t TO6  : 1; /*!< [6:6] : Transmission Occurred 6. */
            __IM uint32_t TO7  : 1; /*!< [7:7] : Transmission Occurred 7. */
            __IM uint32_t TO8  : 1; /*!< [8:8] : Transmission Occurred 8. */
            __IM uint32_t TO9  : 1; /*!< [9:9] : Transmission Occurred 9. */
            __IM uint32_t TO10 : 1; /*!< [10:10] : Transmission Occurred 10. */
            __IM uint32_t TO11 : 1; /*!< [11:11] : Transmission Occurred 11. */
            __IM uint32_t TO12 : 1; /*!< [12:12] : Transmission Occurred 12. */
            __IM uint32_t TO13 : 1; /*!< [13:13] : Transmission Occurred 13. */
            __IM uint32_t TO14 : 1; /*!< [14:14] : Transmission Occurred 14. */
            __IM uint32_t TO15 : 1; /*!< [15:15] : Transmission Occurred 15. */
            __IM uint32_t TO16 : 1; /*!< [16:16] : Transmission Occurred 16. */
            __IM uint32_t TO17 : 1; /*!< [17:17] : Transmission Occurred 17. */
            __IM uint32_t TO18 : 1; /*!< [18:18] : Transmission Occurred 18. */
            __IM uint32_t TO19 : 1; /*!< [19:19] : Transmission Occurred 19. */
            __IM uint32_t TO20 : 1; /*!< [20:20] : Transmission Occurred 20. */
            __IM uint32_t TO21 : 1; /*!< [21:21] : Transmission Occurred 21. */
            __IM uint32_t TO22 : 1; /*!< [22:22] : Transmission Occurred 22. */
            __IM uint32_t TO23 : 1; /*!< [23:23] : Transmission Occurred 23. */
            __IM uint32_t TO24 : 1; /*!< [24:24] : Transmission Occurred 24. */
            __IM uint32_t TO25 : 1; /*!< [25:25] : Transmission Occurred 25. */
            __IM uint32_t TO26 : 1; /*!< [26:26] : Transmission Occurred 26. */
            __IM uint32_t TO27 : 1; /*!< [27:27] : Transmission Occurred 27. */
            __IM uint32_t TO28 : 1; /*!< [28:28] : Transmission Occurred 28. */
            __IM uint32_t TO29 : 1; /*!< [29:29] : Transmission Occurred 29. */
            __IM uint32_t TO30 : 1; /*!< [30:30] : Transmission Occurred 30. */
            __IM uint32_t TO31 : 1; /*!< [31:31] : Transmission Occurred 31. */
        } TXBTOb;
    };

    union
    {
        __IM uint32_t TXBCF; /*!< 0x000000dc */

        struct
        {
            __IM uint32_t CF0  : 1; /*!< [0:0] : Cancellation Finished 0. */
            __IM uint32_t CF1  : 1; /*!< [1:1] : Cancellation Finished 1. */
            __IM uint32_t CF2  : 1; /*!< [2:2] : Cancellation Finished 2. */
            __IM uint32_t CF3  : 1; /*!< [3:3] : Cancellation Finished 3. */
            __IM uint32_t CF4  : 1; /*!< [4:4] : Cancellation Finished 4. */
            __IM uint32_t CF5  : 1; /*!< [5:5] : Cancellation Finished 5. */
            __IM uint32_t CF6  : 1; /*!< [6:6] : Cancellation Finished 6. */
            __IM uint32_t CF7  : 1; /*!< [7:7] : Cancellation Finished 7. */
            __IM uint32_t CF8  : 1; /*!< [8:8] : Cancellation Finished 8. */
            __IM uint32_t CF9  : 1; /*!< [9:9] : Cancellation Finished 9. */
            __IM uint32_t CF10 : 1; /*!< [10:10] : Cancellation Finished 10. */
            __IM uint32_t CF11 : 1; /*!< [11:11] : Cancellation Finished 11. */
            __IM uint32_t CF12 : 1; /*!< [12:12] : Cancellation Finished 12. */
            __IM uint32_t CF13 : 1; /*!< [13:13] : Cancellation Finished 13. */
            __IM uint32_t CF14 : 1; /*!< [14:14] : Cancellation Finished 14. */
            __IM uint32_t CF15 : 1; /*!< [15:15] : Cancellation Finished 15. */
            __IM uint32_t CF16 : 1; /*!< [16:16] : Cancellation Finished 16. */
            __IM uint32_t CF17 : 1; /*!< [17:17] : Cancellation Finished 17. */
            __IM uint32_t CF18 : 1; /*!< [18:18] : Cancellation Finished 18. */
            __IM uint32_t CF19 : 1; /*!< [19:19] : Cancellation Finished 19. */
            __IM uint32_t CF20 : 1; /*!< [20:20] : Cancellation Finished 20. */
            __IM uint32_t CF21 : 1; /*!< [21:21] : Cancellation Finished 21. */
            __IM uint32_t CF22 : 1; /*!< [22:22] : Cancellation Finished 22. */
            __IM uint32_t CF23 : 1; /*!< [23:23] : Cancellation Finished 23. */
            __IM uint32_t CF24 : 1; /*!< [24:24] : Cancellation Finished 24. */
            __IM uint32_t CF25 : 1; /*!< [25:25] : Cancellation Finished 25. */
            __IM uint32_t CF26 : 1; /*!< [26:26] : Cancellation Finished 26. */
            __IM uint32_t CF27 : 1; /*!< [27:27] : Cancellation Finished 27. */
            __IM uint32_t CF28 : 1; /*!< [28:28] : Cancellation Finished 28. */
            __IM uint32_t CF29 : 1; /*!< [29:29] : Cancellation Finished 29. */
            __IM uint32_t CF30 : 1; /*!< [30:30] : Cancellation Finished 30. */
            __IM uint32_t CF31 : 1; /*!< [31:31] : Cancellation Finished 31. */
        } TXBCFb;
    };

    union
    {
        __IOM uint32_t TXBTIE; /*!< 0x000000e0 */

        struct
        {
            __IOM uint32_t TIE0  : 1; /*!< [0:0] : Transmission Interrupt Enable 0. */
            __IOM uint32_t TIE1  : 1; /*!< [1:1] : Transmission Interrupt Enable 1. */
            __IOM uint32_t TIE2  : 1; /*!< [2:2] : Transmission Interrupt Enable 2. */
            __IOM uint32_t TIE3  : 1; /*!< [3:3] : Transmission Interrupt Enable 3. */
            __IOM uint32_t TIE4  : 1; /*!< [4:4] : Transmission Interrupt Enable 4. */
            __IOM uint32_t TIE5  : 1; /*!< [5:5] : Transmission Interrupt Enable 5. */
            __IOM uint32_t TIE6  : 1; /*!< [6:6] : Transmission Interrupt Enable 6. */
            __IOM uint32_t TIE7  : 1; /*!< [7:7] : Transmission Interrupt Enable 7. */
            __IOM uint32_t TIE8  : 1; /*!< [8:8] : Transmission Interrupt Enable 8. */
            __IOM uint32_t TIE9  : 1; /*!< [9:9] : Transmission Interrupt Enable 9. */
            __IOM uint32_t TIE10 : 1; /*!< [10:10] : Transmission Interrupt Enable 10. */
            __IOM uint32_t TIE11 : 1; /*!< [11:11] : Transmission Interrupt Enable 11. */
            __IOM uint32_t TIE12 : 1; /*!< [12:12] : Transmission Interrupt Enable 12. */
            __IOM uint32_t TIE13 : 1; /*!< [13:13] : Transmission Interrupt Enable 13. */
            __IOM uint32_t TIE14 : 1; /*!< [14:14] : Transmission Interrupt Enable 14. */
            __IOM uint32_t TIE15 : 1; /*!< [15:15] : Transmission Interrupt Enable 15. */
            __IOM uint32_t TIE16 : 1; /*!< [16:16] : Transmission Interrupt Enable 16. */
            __IOM uint32_t TIE17 : 1; /*!< [17:17] : Transmission Interrupt Enable 17. */
            __IOM uint32_t TIE18 : 1; /*!< [18:18] : Transmission Interrupt Enable 18. */
            __IOM uint32_t TIE19 : 1; /*!< [19:19] : Transmission Interrupt Enable 19. */
            __IOM uint32_t TIE20 : 1; /*!< [20:20] : Transmission Interrupt Enable 20. */
            __IOM uint32_t TIE21 : 1; /*!< [21:21] : Transmission Interrupt Enable 21. */
            __IOM uint32_t TIE22 : 1; /*!< [22:22] : Transmission Interrupt Enable 22. */
            __IOM uint32_t TIE23 : 1; /*!< [23:23] : Transmission Interrupt Enable 23. */
            __IOM uint32_t TIE24 : 1; /*!< [24:24] : Transmission Interrupt Enable 24. */
            __IOM uint32_t TIE25 : 1; /*!< [25:25] : Transmission Interrupt Enable 25. */
            __IOM uint32_t TIE26 : 1; /*!< [26:26] : Transmission Interrupt Enable 26. */
            __IOM uint32_t TIE27 : 1; /*!< [27:27] : Transmission Interrupt Enable 27. */
            __IOM uint32_t TIE28 : 1; /*!< [28:28] : Transmission Interrupt Enable 28. */
            __IOM uint32_t TIE29 : 1; /*!< [29:29] : Transmission Interrupt Enable 29. */
            __IOM uint32_t TIE30 : 1; /*!< [30:30] : Transmission Interrupt Enable 30. */
            __IOM uint32_t TIE31 : 1; /*!< [31:31] : Transmission Interrupt Enable 31. */
        } TXBTIEb;
    };

    union
    {
        __IOM uint32_t TXBCIE; /*!< 0x000000e4 */

        struct
        {
            __IOM uint32_t CFIE0  : 1; /*!< [0:0] : Cancellation Finished Interrupt Enable 0. */
            __IOM uint32_t CFIE1  : 1; /*!< [1:1] : Cancellation Finished Interrupt Enable 1. */
            __IOM uint32_t CFIE2  : 1; /*!< [2:2] : Cancellation Finished Interrupt Enable 2. */
            __IOM uint32_t CFIE3  : 1; /*!< [3:3] : Cancellation Finished Interrupt Enable 3. */
            __IOM uint32_t CFIE4  : 1; /*!< [4:4] : Cancellation Finished Interrupt Enable 4. */
            __IOM uint32_t CFIE5  : 1; /*!< [5:5] : Cancellation Finished Interrupt Enable 5. */
            __IOM uint32_t CFIE6  : 1; /*!< [6:6] : Cancellation Finished Interrupt Enable 6. */
            __IOM uint32_t CFIE7  : 1; /*!< [7:7] : Cancellation Finished Interrupt Enable 7. */
            __IOM uint32_t CFIE8  : 1; /*!< [8:8] : Cancellation Finished Interrupt Enable 8. */
            __IOM uint32_t CFIE9  : 1; /*!< [9:9] : Cancellation Finished Interrupt Enable 9. */
            __IOM uint32_t CFIE10 : 1; /*!< [10:10] : Cancellation Finished Interrupt Enable 10. */
            __IOM uint32_t CFIE11 : 1; /*!< [11:11] : Cancellation Finished Interrupt Enable 11. */
            __IOM uint32_t CFIE12 : 1; /*!< [12:12] : Cancellation Finished Interrupt Enable 12. */
            __IOM uint32_t CFIE13 : 1; /*!< [13:13] : Cancellation Finished Interrupt Enable 13. */
            __IOM uint32_t CFIE14 : 1; /*!< [14:14] : Cancellation Finished Interrupt Enable 14. */
            __IOM uint32_t CFIE15 : 1; /*!< [15:15] : Cancellation Finished Interrupt Enable 15. */
            __IOM uint32_t CFIE16 : 1; /*!< [16:16] : Cancellation Finished Interrupt Enable 16. */
            __IOM uint32_t CFIE17 : 1; /*!< [17:17] : Cancellation Finished Interrupt Enable 17. */
            __IOM uint32_t CFIE18 : 1; /*!< [18:18] : Cancellation Finished Interrupt Enable 18. */
            __IOM uint32_t CFIE19 : 1; /*!< [19:19] : Cancellation Finished Interrupt Enable 19. */
            __IOM uint32_t CFIE20 : 1; /*!< [20:20] : Cancellation Finished Interrupt Enable 20. */
            __IOM uint32_t CFIE21 : 1; /*!< [21:21] : Cancellation Finished Interrupt Enable 21. */
            __IOM uint32_t CFIE22 : 1; /*!< [22:22] : Cancellation Finished Interrupt Enable 22. */
            __IOM uint32_t CFIE23 : 1; /*!< [23:23] : Cancellation Finished Interrupt Enable 23. */
            __IOM uint32_t CFIE24 : 1; /*!< [24:24] : Cancellation Finished Interrupt Enable 24. */
            __IOM uint32_t CFIE25 : 1; /*!< [25:25] : Cancellation Finished Interrupt Enable 25. */
            __IOM uint32_t CFIE26 : 1; /*!< [26:26] : Cancellation Finished Interrupt Enable 26. */
            __IOM uint32_t CFIE27 : 1; /*!< [27:27] : Cancellation Finished Interrupt Enable 27. */
            __IOM uint32_t CFIE28 : 1; /*!< [28:28] : Cancellation Finished Interrupt Enable 28. */
            __IOM uint32_t CFIE29 : 1; /*!< [29:29] : Cancellation Finished Interrupt Enable 29. */
            __IOM uint32_t CFIE30 : 1; /*!< [30:30] : Cancellation Finished Interrupt Enable 30. */
            __IOM uint32_t CFIE31 : 1; /*!< [31:31] : Cancellation Finished Interrupt Enable 31. */
        } TXBCIEb;
    };

    uint8_t RSV_0XE8[8]; /*!< 0x000000e8~0x000000ef : reserved */

    union
    {
        __IOM uint32_t TXEFC; /*!< 0x000000f0 */

        struct
        {
            uint32_t       RSV_2 : 2;  /*!< [1:0] : reserved. */
            __IOM uint32_t EFSA  : 14; /*!< [15:2] : Event FIFO Start Address. */
            __IOM uint32_t EFS   : 6;  /*!< [21:16] : Event FIFO Size. */
            uint32_t       RSV_1 : 2;  /*!< [23:22] : reserved. */
            __IOM uint32_t EFWM : 6; /*!< [29:24] : Event FIFO Watermark                                            <br>
                                        0 Watermark interrupt disabled                                  <br>  1-32 Level
                                        for Tx Event FIFO watermark interrupt (IR. */
            uint32_t RSV_0 : 2;      /*!< [31:30] : reserved. */
        } TXEFCb;
    };

    union
    {
        __IM uint32_t TXEFS; /*!< 0x000000f4 */

        struct
        {
            __IM uint32_t EFFL  : 6; /*!< [5:0] : Event FIFO Fill Level. */
            uint32_t      RSV_3 : 2; /*!< [7:6] : reserved. */
            __IM uint32_t EFGI  : 5; /*!< [12:8] : Event FIFO Get Index. */
            uint32_t      RSV_2 : 3; /*!< [15:13] : reserved. */
            __IM uint32_t EFPI  : 5; /*!< [20:16] : Event FIFO Put Index. */
            uint32_t      RSV_1 : 3; /*!< [23:21] : reserved. */
            __IM uint32_t EFF   : 1; /*!< [24:24] : Event FIFO Full                                                 <br>
                                        0 Tx Event FIFO not full 1 Tx Event FIFO full Reset type: SYSRSn<br>. */
            __IM uint32_t TEFL  : 1; /*!< [25:25] : Tx Event FIFO Element Lost. */
            uint32_t      RSV_0 : 6; /*!< [31:26] : reserved. */
        } TXEFSb;
    };

    union
    {
        __IOM uint32_t TXEFA; /*!< 0x000000f8 */

        struct
        {
            __IOM uint32_t EFAI  : 5;  /*!< [4:0] : Event FIFO Acknowledge Index. */
            uint32_t       RSV_0 : 27; /*!< [31:5] : reserved. */
        } TXEFAb;
    };
} MCAN_Type;

/*!
 * @}
 */

/*!
 * \name MCAN Base Address Definitions
 *
 * @{
 */

/*! \brief MCANA base address */
#define MCANA_BASE (0x42100000UL)
/*! \brief MCANB base address */
#define MCANB_BASE (0x42101000UL)
/*! \brief MCANC base address */
#define MCANC_BASE (0x42102000UL)

/*! \brief MCANA MESSAGE RAM base address */
#define MCANA_MSG_RAM_BASE (0x42110000UL)
/*! \brief MCANB MESSAGE RAM base address */
#define MCANB_MSG_RAM_BASE (0x42114400UL)
/*! \brief MCANC MESSAGE RAM base address */
#define MCANC_MSG_RAM_BASE (0x42118800UL)


/*! \brief MCANA base pointer */
#define MCANA ((MCAN_Type *) MCANA_BASE)
/*! \brief MCANB base pointer */
#define MCANB ((MCAN_Type *) MCANB_BASE)
/*! \brief MCANC base pointer */
#define MCANC ((MCAN_Type *) MCANC_BASE)


/*!
 * @}
 */


/*!
 * \name MCAN Register Bitfield Definitions
 *
 * @{
 */

/* CREL bitfield */
#define MCAN_CREL_REL_Pos (28U)                       /*!< REL Postion   28         */
#define MCAN_CREL_REL_Msk (0xfU << MCAN_CREL_REL_Pos) /*!< REL Mask      0xF0000000 */
#define MCAN_CREL_REL_Set(x) \
    (((uint32_t) (x) << MCAN_CREL_REL_Pos) & MCAN_CREL_REL_Msk)                         /*!< REL Set Value            */
#define MCAN_CREL_REL_Get(x) (((uint32_t) (x) &MCAN_CREL_REL_Msk) >> MCAN_CREL_REL_Pos) /*!< REL Get Value */


#define MCAN_CREL_STEP_Pos (24U)                        /*!< STEP Postion   24         */
#define MCAN_CREL_STEP_Msk (0xfU << MCAN_CREL_STEP_Pos) /*!< STEP Mask      0x0F000000 */
#define MCAN_CREL_STEP_Set(x) \
    (((uint32_t) (x) << MCAN_CREL_STEP_Pos) & MCAN_CREL_STEP_Msk) /*!< STEP Set Value            */
#define MCAN_CREL_STEP_Get(x) \
    (((uint32_t) (x) &MCAN_CREL_STEP_Msk) >> MCAN_CREL_STEP_Pos) /*!< STEP Get Value            */


#define MCAN_CREL_SUBSTEP_Pos (20U)                           /*!< SUBSTEP Postion   20         */
#define MCAN_CREL_SUBSTEP_Msk (0xfU << MCAN_CREL_SUBSTEP_Pos) /*!< SUBSTEP Mask      0x00F00000 */
#define MCAN_CREL_SUBSTEP_Set(x) \
    (((uint32_t) (x) << MCAN_CREL_SUBSTEP_Pos) & MCAN_CREL_SUBSTEP_Msk) /*!< SUBSTEP Set Value            */
#define MCAN_CREL_SUBSTEP_Get(x) \
    (((uint32_t) (x) &MCAN_CREL_SUBSTEP_Msk) >> MCAN_CREL_SUBSTEP_Pos) /*!< SUBSTEP Get Value            */


#define MCAN_CREL_YEAR_Pos (16U)                        /*!< YEAR Postion   16         */
#define MCAN_CREL_YEAR_Msk (0xfU << MCAN_CREL_YEAR_Pos) /*!< YEAR Mask      0x000F0000 */
#define MCAN_CREL_YEAR_Set(x) \
    (((uint32_t) (x) << MCAN_CREL_YEAR_Pos) & MCAN_CREL_YEAR_Msk) /*!< YEAR Set Value            */
#define MCAN_CREL_YEAR_Get(x) \
    (((uint32_t) (x) &MCAN_CREL_YEAR_Msk) >> MCAN_CREL_YEAR_Pos) /*!< YEAR Get Value            */


#define MCAN_CREL_MON_Pos (8U)                         /*!< MON Postion   8          */
#define MCAN_CREL_MON_Msk (0xffU << MCAN_CREL_MON_Pos) /*!< MON Mask      0x0000FF00 */
#define MCAN_CREL_MON_Set(x) \
    (((uint32_t) (x) << MCAN_CREL_MON_Pos) & MCAN_CREL_MON_Msk)                         /*!< MON Set Value            */
#define MCAN_CREL_MON_Get(x) (((uint32_t) (x) &MCAN_CREL_MON_Msk) >> MCAN_CREL_MON_Pos) /*!< MON Get Value */


#define MCAN_CREL_DAY_Pos (0U)                         /*!< DAY Postion   0          */
#define MCAN_CREL_DAY_Msk (0xffU << MCAN_CREL_DAY_Pos) /*!< DAY Mask      0x000000FF */
#define MCAN_CREL_DAY_Set(x) \
    (((uint32_t) (x) << MCAN_CREL_DAY_Pos) & MCAN_CREL_DAY_Msk)                         /*!< DAY Set Value            */
#define MCAN_CREL_DAY_Get(x) (((uint32_t) (x) &MCAN_CREL_DAY_Msk) >> MCAN_CREL_DAY_Pos) /*!< DAY Get Value */


/* ENDN bitfield */
#define MCAN_ENDN_ETV_Pos (0U)                               /*!< ETV Postion   0          */
#define MCAN_ENDN_ETV_Msk (0xffffffffU << MCAN_ENDN_ETV_Pos) /*!< ETV Mask      0xFFFFFFFF */
#define MCAN_ENDN_ETV_Set(x) \
    (((uint32_t) (x) << MCAN_ENDN_ETV_Pos) & MCAN_ENDN_ETV_Msk)                         /*!< ETV Set Value            */
#define MCAN_ENDN_ETV_Get(x) (((uint32_t) (x) &MCAN_ENDN_ETV_Msk) >> MCAN_ENDN_ETV_Pos) /*!< ETV Get Value */


/* DBTP bitfield */
#define MCAN_DBTP_TDC_Pos (23U)                       /*!< TDC Postion   23         */
#define MCAN_DBTP_TDC_Msk (0x1U << MCAN_DBTP_TDC_Pos) /*!< TDC Mask      0x00800000 */
#define MCAN_DBTP_TDC_Set(x) \
    (((uint32_t) (x) << MCAN_DBTP_TDC_Pos) & MCAN_DBTP_TDC_Msk)                         /*!< TDC Set Value            */
#define MCAN_DBTP_TDC_Get(x) (((uint32_t) (x) &MCAN_DBTP_TDC_Msk) >> MCAN_DBTP_TDC_Pos) /*!< TDC Get Value */


#define MCAN_DBTP_DBRP_Pos (16U)                         /*!< DBRP Postion   16         */
#define MCAN_DBTP_DBRP_Msk (0x1fU << MCAN_DBTP_DBRP_Pos) /*!< DBRP Mask      0x001F0000 */
#define MCAN_DBTP_DBRP_Set(x) \
    (((uint32_t) (x) << MCAN_DBTP_DBRP_Pos) & MCAN_DBTP_DBRP_Msk) /*!< DBRP Set Value            */
#define MCAN_DBTP_DBRP_Get(x) \
    (((uint32_t) (x) &MCAN_DBTP_DBRP_Msk) >> MCAN_DBTP_DBRP_Pos) /*!< DBRP Get Value            */


#define MCAN_DBTP_DTSEG1_Pos (8U)                            /*!< DTSEG1 Postion   8          */
#define MCAN_DBTP_DTSEG1_Msk (0x1fU << MCAN_DBTP_DTSEG1_Pos) /*!< DTSEG1 Mask      0x00001F00 */
#define MCAN_DBTP_DTSEG1_Set(x) \
    (((uint32_t) (x) << MCAN_DBTP_DTSEG1_Pos) & MCAN_DBTP_DTSEG1_Msk) /*!< DTSEG1 Set Value            */
#define MCAN_DBTP_DTSEG1_Get(x) \
    (((uint32_t) (x) &MCAN_DBTP_DTSEG1_Msk) >> MCAN_DBTP_DTSEG1_Pos) /*!< DTSEG1 Get Value            */


#define MCAN_DBTP_DTSEG2_Pos (4U)                           /*!< DTSEG2 Postion   4          */
#define MCAN_DBTP_DTSEG2_Msk (0xfU << MCAN_DBTP_DTSEG2_Pos) /*!< DTSEG2 Mask      0x000000F0 */
#define MCAN_DBTP_DTSEG2_Set(x) \
    (((uint32_t) (x) << MCAN_DBTP_DTSEG2_Pos) & MCAN_DBTP_DTSEG2_Msk) /*!< DTSEG2 Set Value            */
#define MCAN_DBTP_DTSEG2_Get(x) \
    (((uint32_t) (x) &MCAN_DBTP_DTSEG2_Msk) >> MCAN_DBTP_DTSEG2_Pos) /*!< DTSEG2 Get Value            */


#define MCAN_DBTP_DSJW_Pos (0U)                         /*!< DSJW Postion   0          */
#define MCAN_DBTP_DSJW_Msk (0xfU << MCAN_DBTP_DSJW_Pos) /*!< DSJW Mask      0x0000000F */
#define MCAN_DBTP_DSJW_Set(x) \
    (((uint32_t) (x) << MCAN_DBTP_DSJW_Pos) & MCAN_DBTP_DSJW_Msk) /*!< DSJW Set Value            */
#define MCAN_DBTP_DSJW_Get(x) \
    (((uint32_t) (x) &MCAN_DBTP_DSJW_Msk) >> MCAN_DBTP_DSJW_Pos) /*!< DSJW Get Value            */


/* TEST bitfield */
#define MCAN_TEST_SVAL_Pos (21U)                        /*!< SVAL Postion   21         */
#define MCAN_TEST_SVAL_Msk (0x1U << MCAN_TEST_SVAL_Pos) /*!< SVAL Mask      0x00200000 */
#define MCAN_TEST_SVAL_Set(x) \
    (((uint32_t) (x) << MCAN_TEST_SVAL_Pos) & MCAN_TEST_SVAL_Msk) /*!< SVAL Set Value            */
#define MCAN_TEST_SVAL_Get(x) \
    (((uint32_t) (x) &MCAN_TEST_SVAL_Msk) >> MCAN_TEST_SVAL_Pos) /*!< SVAL Get Value            */


#define MCAN_TEST_TXBNS_Pos (16U)                          /*!< TXBNS Postion   16         */
#define MCAN_TEST_TXBNS_Msk (0x1fU << MCAN_TEST_TXBNS_Pos) /*!< TXBNS Mask      0x001F0000 */
#define MCAN_TEST_TXBNS_Set(x) \
    (((uint32_t) (x) << MCAN_TEST_TXBNS_Pos) & MCAN_TEST_TXBNS_Msk) /*!< TXBNS Set Value            */
#define MCAN_TEST_TXBNS_Get(x) \
    (((uint32_t) (x) &MCAN_TEST_TXBNS_Msk) >> MCAN_TEST_TXBNS_Pos) /*!< TXBNS Get Value            */


#define MCAN_TEST_PVAL_Pos (13U)                        /*!< PVAL Postion   13         */
#define MCAN_TEST_PVAL_Msk (0x1U << MCAN_TEST_PVAL_Pos) /*!< PVAL Mask      0x00002000 */
#define MCAN_TEST_PVAL_Set(x) \
    (((uint32_t) (x) << MCAN_TEST_PVAL_Pos) & MCAN_TEST_PVAL_Msk) /*!< PVAL Set Value            */
#define MCAN_TEST_PVAL_Get(x) \
    (((uint32_t) (x) &MCAN_TEST_PVAL_Msk) >> MCAN_TEST_PVAL_Pos) /*!< PVAL Get Value            */


#define MCAN_TEST_TXBNP_Pos (8U)                           /*!< TXBNP Postion   8          */
#define MCAN_TEST_TXBNP_Msk (0x1fU << MCAN_TEST_TXBNP_Pos) /*!< TXBNP Mask      0x00001F00 */
#define MCAN_TEST_TXBNP_Set(x) \
    (((uint32_t) (x) << MCAN_TEST_TXBNP_Pos) & MCAN_TEST_TXBNP_Msk) /*!< TXBNP Set Value            */
#define MCAN_TEST_TXBNP_Get(x) \
    (((uint32_t) (x) &MCAN_TEST_TXBNP_Msk) >> MCAN_TEST_TXBNP_Pos) /*!< TXBNP Get Value            */


#define MCAN_TEST_RX_Pos    (7U)                                                      /*!< RX Postion   7          */
#define MCAN_TEST_RX_Msk    (0x1U << MCAN_TEST_RX_Pos)                                /*!< RX Mask      0x00000080 */
#define MCAN_TEST_RX_Set(x) (((uint32_t) (x) << MCAN_TEST_RX_Pos) & MCAN_TEST_RX_Msk) /*!< RX Set Value            */
#define MCAN_TEST_RX_Get(x) (((uint32_t) (x) &MCAN_TEST_RX_Msk) >> MCAN_TEST_RX_Pos)  /*!< RX Get Value            */


#define MCAN_TEST_TX_Pos    (5U)                                                      /*!< TX Postion   5          */
#define MCAN_TEST_TX_Msk    (0x3U << MCAN_TEST_TX_Pos)                                /*!< TX Mask      0x00000060 */
#define MCAN_TEST_TX_Set(x) (((uint32_t) (x) << MCAN_TEST_TX_Pos) & MCAN_TEST_TX_Msk) /*!< TX Set Value            */
#define MCAN_TEST_TX_Get(x) (((uint32_t) (x) &MCAN_TEST_TX_Msk) >> MCAN_TEST_TX_Pos)  /*!< TX Get Value            */


#define MCAN_TEST_LBCK_Pos (4U)                         /*!< LBCK Postion   4          */
#define MCAN_TEST_LBCK_Msk (0x1U << MCAN_TEST_LBCK_Pos) /*!< LBCK Mask      0x00000010 */
#define MCAN_TEST_LBCK_Set(x) \
    (((uint32_t) (x) << MCAN_TEST_LBCK_Pos) & MCAN_TEST_LBCK_Msk) /*!< LBCK Set Value            */
#define MCAN_TEST_LBCK_Get(x) \
    (((uint32_t) (x) &MCAN_TEST_LBCK_Msk) >> MCAN_TEST_LBCK_Pos) /*!< LBCK Get Value            */


/* RWD bitfield */
#define MCAN_RWD_WDV_Pos    (8U)                                                      /*!< WDV Postion   8          */
#define MCAN_RWD_WDV_Msk    (0xffU << MCAN_RWD_WDV_Pos)                               /*!< WDV Mask      0x0000FF00 */
#define MCAN_RWD_WDV_Set(x) (((uint32_t) (x) << MCAN_RWD_WDV_Pos) & MCAN_RWD_WDV_Msk) /*!< WDV Set Value            */
#define MCAN_RWD_WDV_Get(x) (((uint32_t) (x) &MCAN_RWD_WDV_Msk) >> MCAN_RWD_WDV_Pos)  /*!< WDV Get Value            */


#define MCAN_RWD_WDC_Pos    (0U)                                                      /*!< WDC Postion   0          */
#define MCAN_RWD_WDC_Msk    (0xffU << MCAN_RWD_WDC_Pos)                               /*!< WDC Mask      0x000000FF */
#define MCAN_RWD_WDC_Set(x) (((uint32_t) (x) << MCAN_RWD_WDC_Pos) & MCAN_RWD_WDC_Msk) /*!< WDC Set Value            */
#define MCAN_RWD_WDC_Get(x) (((uint32_t) (x) &MCAN_RWD_WDC_Msk) >> MCAN_RWD_WDC_Pos)  /*!< WDC Get Value            */


/* CCCR bitfield */
#define MCAN_CCCR_NISO_Pos (15U)                        /*!< NISO Postion   15         */
#define MCAN_CCCR_NISO_Msk (0x1U << MCAN_CCCR_NISO_Pos) /*!< NISO Mask      0x00008000 */
#define MCAN_CCCR_NISO_Set(x) \
    (((uint32_t) (x) << MCAN_CCCR_NISO_Pos) & MCAN_CCCR_NISO_Msk) /*!< NISO Set Value            */
#define MCAN_CCCR_NISO_Get(x) \
    (((uint32_t) (x) &MCAN_CCCR_NISO_Msk) >> MCAN_CCCR_NISO_Pos) /*!< NISO Get Value            */


#define MCAN_CCCR_TXP_Pos (14U)                       /*!< TXP Postion   14         */
#define MCAN_CCCR_TXP_Msk (0x1U << MCAN_CCCR_TXP_Pos) /*!< TXP Mask      0x00004000 */
#define MCAN_CCCR_TXP_Set(x) \
    (((uint32_t) (x) << MCAN_CCCR_TXP_Pos) & MCAN_CCCR_TXP_Msk)                         /*!< TXP Set Value            */
#define MCAN_CCCR_TXP_Get(x) (((uint32_t) (x) &MCAN_CCCR_TXP_Msk) >> MCAN_CCCR_TXP_Pos) /*!< TXP Get Value */


#define MCAN_CCCR_EFBI_Pos (13U)                        /*!< EFBI Postion   13         */
#define MCAN_CCCR_EFBI_Msk (0x1U << MCAN_CCCR_EFBI_Pos) /*!< EFBI Mask      0x00002000 */
#define MCAN_CCCR_EFBI_Set(x) \
    (((uint32_t) (x) << MCAN_CCCR_EFBI_Pos) & MCAN_CCCR_EFBI_Msk) /*!< EFBI Set Value            */
#define MCAN_CCCR_EFBI_Get(x) \
    (((uint32_t) (x) &MCAN_CCCR_EFBI_Msk) >> MCAN_CCCR_EFBI_Pos) /*!< EFBI Get Value            */


#define MCAN_CCCR_PXHD_Pos (12U)                        /*!< PXHD Postion   12         */
#define MCAN_CCCR_PXHD_Msk (0x1U << MCAN_CCCR_PXHD_Pos) /*!< PXHD Mask      0x00001000 */
#define MCAN_CCCR_PXHD_Set(x) \
    (((uint32_t) (x) << MCAN_CCCR_PXHD_Pos) & MCAN_CCCR_PXHD_Msk) /*!< PXHD Set Value            */
#define MCAN_CCCR_PXHD_Get(x) \
    (((uint32_t) (x) &MCAN_CCCR_PXHD_Msk) >> MCAN_CCCR_PXHD_Pos) /*!< PXHD Get Value            */


#define MCAN_CCCR_WMM_Pos (11U)                       /*!< WMM Postion   11         */
#define MCAN_CCCR_WMM_Msk (0x1U << MCAN_CCCR_WMM_Pos) /*!< WMM Mask      0x00000800 */
#define MCAN_CCCR_WMM_Set(x) \
    (((uint32_t) (x) << MCAN_CCCR_WMM_Pos) & MCAN_CCCR_WMM_Msk)                         /*!< WMM Set Value            */
#define MCAN_CCCR_WMM_Get(x) (((uint32_t) (x) &MCAN_CCCR_WMM_Msk) >> MCAN_CCCR_WMM_Pos) /*!< WMM Get Value */


#define MCAN_CCCR_UTSU_Pos (10U)                        /*!< UTSU Postion   10         */
#define MCAN_CCCR_UTSU_Msk (0x1U << MCAN_CCCR_UTSU_Pos) /*!< UTSU Mask      0x00000400 */
#define MCAN_CCCR_UTSU_Set(x) \
    (((uint32_t) (x) << MCAN_CCCR_UTSU_Pos) & MCAN_CCCR_UTSU_Msk) /*!< UTSU Set Value            */
#define MCAN_CCCR_UTSU_Get(x) \
    (((uint32_t) (x) &MCAN_CCCR_UTSU_Msk) >> MCAN_CCCR_UTSU_Pos) /*!< UTSU Get Value            */


#define MCAN_CCCR_BRSE_Pos (9U)                         /*!< BRSE Postion   9          */
#define MCAN_CCCR_BRSE_Msk (0x1U << MCAN_CCCR_BRSE_Pos) /*!< BRSE Mask      0x00000200 */
#define MCAN_CCCR_BRSE_Set(x) \
    (((uint32_t) (x) << MCAN_CCCR_BRSE_Pos) & MCAN_CCCR_BRSE_Msk) /*!< BRSE Set Value            */
#define MCAN_CCCR_BRSE_Get(x) \
    (((uint32_t) (x) &MCAN_CCCR_BRSE_Msk) >> MCAN_CCCR_BRSE_Pos) /*!< BRSE Get Value            */


#define MCAN_CCCR_FDOE_Pos (8U)                         /*!< FDOE Postion   8          */
#define MCAN_CCCR_FDOE_Msk (0x1U << MCAN_CCCR_FDOE_Pos) /*!< FDOE Mask      0x00000100 */
#define MCAN_CCCR_FDOE_Set(x) \
    (((uint32_t) (x) << MCAN_CCCR_FDOE_Pos) & MCAN_CCCR_FDOE_Msk) /*!< FDOE Set Value            */
#define MCAN_CCCR_FDOE_Get(x) \
    (((uint32_t) (x) &MCAN_CCCR_FDOE_Msk) >> MCAN_CCCR_FDOE_Pos) /*!< FDOE Get Value            */


#define MCAN_CCCR_TEST_Pos (7U)                         /*!< TEST Postion   7          */
#define MCAN_CCCR_TEST_Msk (0x1U << MCAN_CCCR_TEST_Pos) /*!< TEST Mask      0x00000080 */
#define MCAN_CCCR_TEST_Set(x) \
    (((uint32_t) (x) << MCAN_CCCR_TEST_Pos) & MCAN_CCCR_TEST_Msk) /*!< TEST Set Value            */
#define MCAN_CCCR_TEST_Get(x) \
    (((uint32_t) (x) &MCAN_CCCR_TEST_Msk) >> MCAN_CCCR_TEST_Pos) /*!< TEST Get Value            */


#define MCAN_CCCR_DAR_Pos (6U)                        /*!< DAR Postion   6          */
#define MCAN_CCCR_DAR_Msk (0x1U << MCAN_CCCR_DAR_Pos) /*!< DAR Mask      0x00000040 */
#define MCAN_CCCR_DAR_Set(x) \
    (((uint32_t) (x) << MCAN_CCCR_DAR_Pos) & MCAN_CCCR_DAR_Msk)                         /*!< DAR Set Value            */
#define MCAN_CCCR_DAR_Get(x) (((uint32_t) (x) &MCAN_CCCR_DAR_Msk) >> MCAN_CCCR_DAR_Pos) /*!< DAR Get Value */


#define MCAN_CCCR_MON_Pos (5U)                        /*!< MON Postion   5          */
#define MCAN_CCCR_MON_Msk (0x1U << MCAN_CCCR_MON_Pos) /*!< MON Mask      0x00000020 */
#define MCAN_CCCR_MON_Set(x) \
    (((uint32_t) (x) << MCAN_CCCR_MON_Pos) & MCAN_CCCR_MON_Msk)                         /*!< MON Set Value            */
#define MCAN_CCCR_MON_Get(x) (((uint32_t) (x) &MCAN_CCCR_MON_Msk) >> MCAN_CCCR_MON_Pos) /*!< MON Get Value */


#define MCAN_CCCR_CSR_Pos (4U)                        /*!< CSR Postion   4          */
#define MCAN_CCCR_CSR_Msk (0x1U << MCAN_CCCR_CSR_Pos) /*!< CSR Mask      0x00000010 */
#define MCAN_CCCR_CSR_Set(x) \
    (((uint32_t) (x) << MCAN_CCCR_CSR_Pos) & MCAN_CCCR_CSR_Msk)                         /*!< CSR Set Value            */
#define MCAN_CCCR_CSR_Get(x) (((uint32_t) (x) &MCAN_CCCR_CSR_Msk) >> MCAN_CCCR_CSR_Pos) /*!< CSR Get Value */


#define MCAN_CCCR_CSA_Pos (3U)                        /*!< CSA Postion   3          */
#define MCAN_CCCR_CSA_Msk (0x1U << MCAN_CCCR_CSA_Pos) /*!< CSA Mask      0x00000008 */
#define MCAN_CCCR_CSA_Set(x) \
    (((uint32_t) (x) << MCAN_CCCR_CSA_Pos) & MCAN_CCCR_CSA_Msk)                         /*!< CSA Set Value            */
#define MCAN_CCCR_CSA_Get(x) (((uint32_t) (x) &MCAN_CCCR_CSA_Msk) >> MCAN_CCCR_CSA_Pos) /*!< CSA Get Value */


#define MCAN_CCCR_ASM_Pos (2U)                        /*!< ASM Postion   2          */
#define MCAN_CCCR_ASM_Msk (0x1U << MCAN_CCCR_ASM_Pos) /*!< ASM Mask      0x00000004 */
#define MCAN_CCCR_ASM_Set(x) \
    (((uint32_t) (x) << MCAN_CCCR_ASM_Pos) & MCAN_CCCR_ASM_Msk)                         /*!< ASM Set Value            */
#define MCAN_CCCR_ASM_Get(x) (((uint32_t) (x) &MCAN_CCCR_ASM_Msk) >> MCAN_CCCR_ASM_Pos) /*!< ASM Get Value */


#define MCAN_CCCR_CCE_Pos (1U)                        /*!< CCE Postion   1          */
#define MCAN_CCCR_CCE_Msk (0x1U << MCAN_CCCR_CCE_Pos) /*!< CCE Mask      0x00000002 */
#define MCAN_CCCR_CCE_Set(x) \
    (((uint32_t) (x) << MCAN_CCCR_CCE_Pos) & MCAN_CCCR_CCE_Msk)                         /*!< CCE Set Value            */
#define MCAN_CCCR_CCE_Get(x) (((uint32_t) (x) &MCAN_CCCR_CCE_Msk) >> MCAN_CCCR_CCE_Pos) /*!< CCE Get Value */


#define MCAN_CCCR_INIT_Pos (0U)                         /*!< INIT Postion   0          */
#define MCAN_CCCR_INIT_Msk (0x1U << MCAN_CCCR_INIT_Pos) /*!< INIT Mask      0x00000001 */
#define MCAN_CCCR_INIT_Set(x) \
    (((uint32_t) (x) << MCAN_CCCR_INIT_Pos) & MCAN_CCCR_INIT_Msk) /*!< INIT Set Value            */
#define MCAN_CCCR_INIT_Get(x) \
    (((uint32_t) (x) &MCAN_CCCR_INIT_Msk) >> MCAN_CCCR_INIT_Pos) /*!< INIT Get Value            */


/* NBTP bitfield */
#define MCAN_NBTP_NSJW_Pos (25U)                         /*!< NSJW Postion   25         */
#define MCAN_NBTP_NSJW_Msk (0x7fU << MCAN_NBTP_NSJW_Pos) /*!< NSJW Mask      0xFE000000 */
#define MCAN_NBTP_NSJW_Set(x) \
    (((uint32_t) (x) << MCAN_NBTP_NSJW_Pos) & MCAN_NBTP_NSJW_Msk) /*!< NSJW Set Value            */
#define MCAN_NBTP_NSJW_Get(x) \
    (((uint32_t) (x) &MCAN_NBTP_NSJW_Msk) >> MCAN_NBTP_NSJW_Pos) /*!< NSJW Get Value            */


#define MCAN_NBTP_NBRP_Pos (16U)                          /*!< NBRP Postion   16         */
#define MCAN_NBTP_NBRP_Msk (0x1ffU << MCAN_NBTP_NBRP_Pos) /*!< NBRP Mask      0x01FF0000 */
#define MCAN_NBTP_NBRP_Set(x) \
    (((uint32_t) (x) << MCAN_NBTP_NBRP_Pos) & MCAN_NBTP_NBRP_Msk) /*!< NBRP Set Value            */
#define MCAN_NBTP_NBRP_Get(x) \
    (((uint32_t) (x) &MCAN_NBTP_NBRP_Msk) >> MCAN_NBTP_NBRP_Pos) /*!< NBRP Get Value            */


#define MCAN_NBTP_NTSEG1_Pos (8U)                            /*!< NTSEG1 Postion   8          */
#define MCAN_NBTP_NTSEG1_Msk (0xffU << MCAN_NBTP_NTSEG1_Pos) /*!< NTSEG1 Mask      0x0000FF00 */
#define MCAN_NBTP_NTSEG1_Set(x) \
    (((uint32_t) (x) << MCAN_NBTP_NTSEG1_Pos) & MCAN_NBTP_NTSEG1_Msk) /*!< NTSEG1 Set Value            */
#define MCAN_NBTP_NTSEG1_Get(x) \
    (((uint32_t) (x) &MCAN_NBTP_NTSEG1_Msk) >> MCAN_NBTP_NTSEG1_Pos) /*!< NTSEG1 Get Value            */


#define MCAN_NBTP_NTSEG2_Pos (0U)                            /*!< NTSEG2 Postion   0          */
#define MCAN_NBTP_NTSEG2_Msk (0x7fU << MCAN_NBTP_NTSEG2_Pos) /*!< NTSEG2 Mask      0x0000007F */
#define MCAN_NBTP_NTSEG2_Set(x) \
    (((uint32_t) (x) << MCAN_NBTP_NTSEG2_Pos) & MCAN_NBTP_NTSEG2_Msk) /*!< NTSEG2 Set Value            */
#define MCAN_NBTP_NTSEG2_Get(x) \
    (((uint32_t) (x) &MCAN_NBTP_NTSEG2_Msk) >> MCAN_NBTP_NTSEG2_Pos) /*!< NTSEG2 Get Value            */


/* TSCC bitfield */
#define MCAN_TSCC_TCP_Pos (16U)                       /*!< TCP Postion   16         */
#define MCAN_TSCC_TCP_Msk (0xfU << MCAN_TSCC_TCP_Pos) /*!< TCP Mask      0x000F0000 */
#define MCAN_TSCC_TCP_Set(x) \
    (((uint32_t) (x) << MCAN_TSCC_TCP_Pos) & MCAN_TSCC_TCP_Msk)                         /*!< TCP Set Value            */
#define MCAN_TSCC_TCP_Get(x) (((uint32_t) (x) &MCAN_TSCC_TCP_Msk) >> MCAN_TSCC_TCP_Pos) /*!< TCP Get Value */


#define MCAN_TSCC_TSS_Pos (0U)                        /*!< TSS Postion   0          */
#define MCAN_TSCC_TSS_Msk (0x3U << MCAN_TSCC_TSS_Pos) /*!< TSS Mask      0x00000003 */
#define MCAN_TSCC_TSS_Set(x) \
    (((uint32_t) (x) << MCAN_TSCC_TSS_Pos) & MCAN_TSCC_TSS_Msk)                         /*!< TSS Set Value            */
#define MCAN_TSCC_TSS_Get(x) (((uint32_t) (x) &MCAN_TSCC_TSS_Msk) >> MCAN_TSCC_TSS_Pos) /*!< TSS Get Value */


/* TSCV bitfield */
#define MCAN_TSCV_TSC_Pos (0U)                           /*!< TSC Postion   0          */
#define MCAN_TSCV_TSC_Msk (0xffffU << MCAN_TSCV_TSC_Pos) /*!< TSC Mask      0x0000FFFF */
#define MCAN_TSCV_TSC_Set(x) \
    (((uint32_t) (x) << MCAN_TSCV_TSC_Pos) & MCAN_TSCV_TSC_Msk)                         /*!< TSC Set Value            */
#define MCAN_TSCV_TSC_Get(x) (((uint32_t) (x) &MCAN_TSCV_TSC_Msk) >> MCAN_TSCV_TSC_Pos) /*!< TSC Get Value */


/* TOCC bitfield */
#define MCAN_TOCC_TOP_Pos (16U)                          /*!< TOP Postion   16         */
#define MCAN_TOCC_TOP_Msk (0xffffU << MCAN_TOCC_TOP_Pos) /*!< TOP Mask      0xFFFF0000 */
#define MCAN_TOCC_TOP_Set(x) \
    (((uint32_t) (x) << MCAN_TOCC_TOP_Pos) & MCAN_TOCC_TOP_Msk)                         /*!< TOP Set Value            */
#define MCAN_TOCC_TOP_Get(x) (((uint32_t) (x) &MCAN_TOCC_TOP_Msk) >> MCAN_TOCC_TOP_Pos) /*!< TOP Get Value */


#define MCAN_TOCC_TOS_Pos (1U)                        /*!< TOS Postion   1          */
#define MCAN_TOCC_TOS_Msk (0x3U << MCAN_TOCC_TOS_Pos) /*!< TOS Mask      0x00000006 */
#define MCAN_TOCC_TOS_Set(x) \
    (((uint32_t) (x) << MCAN_TOCC_TOS_Pos) & MCAN_TOCC_TOS_Msk)                         /*!< TOS Set Value            */
#define MCAN_TOCC_TOS_Get(x) (((uint32_t) (x) &MCAN_TOCC_TOS_Msk) >> MCAN_TOCC_TOS_Pos) /*!< TOS Get Value */


#define MCAN_TOCC_ETOC_Pos (0U)                         /*!< ETOC Postion   0          */
#define MCAN_TOCC_ETOC_Msk (0x1U << MCAN_TOCC_ETOC_Pos) /*!< ETOC Mask      0x00000001 */
#define MCAN_TOCC_ETOC_Set(x) \
    (((uint32_t) (x) << MCAN_TOCC_ETOC_Pos) & MCAN_TOCC_ETOC_Msk) /*!< ETOC Set Value            */
#define MCAN_TOCC_ETOC_Get(x) \
    (((uint32_t) (x) &MCAN_TOCC_ETOC_Msk) >> MCAN_TOCC_ETOC_Pos) /*!< ETOC Get Value            */


/* TOCV bitfield */
#define MCAN_TOCV_TOC_Pos (0U)                           /*!< TOC Postion   0          */
#define MCAN_TOCV_TOC_Msk (0xffffU << MCAN_TOCV_TOC_Pos) /*!< TOC Mask      0x0000FFFF */
#define MCAN_TOCV_TOC_Set(x) \
    (((uint32_t) (x) << MCAN_TOCV_TOC_Pos) & MCAN_TOCV_TOC_Msk)                         /*!< TOC Set Value            */
#define MCAN_TOCV_TOC_Get(x) (((uint32_t) (x) &MCAN_TOCV_TOC_Msk) >> MCAN_TOCV_TOC_Pos) /*!< TOC Get Value */


/* ECR bitfield */
#define MCAN_ECR_CEL_Pos    (16U)                                                     /*!< CEL Postion   16         */
#define MCAN_ECR_CEL_Msk    (0xffU << MCAN_ECR_CEL_Pos)                               /*!< CEL Mask      0x00FF0000 */
#define MCAN_ECR_CEL_Set(x) (((uint32_t) (x) << MCAN_ECR_CEL_Pos) & MCAN_ECR_CEL_Msk) /*!< CEL Set Value            */
#define MCAN_ECR_CEL_Get(x) (((uint32_t) (x) &MCAN_ECR_CEL_Msk) >> MCAN_ECR_CEL_Pos)  /*!< CEL Get Value            */


#define MCAN_ECR_RP_Pos    (15U)                                                   /*!< RP Postion   15         */
#define MCAN_ECR_RP_Msk    (0x1U << MCAN_ECR_RP_Pos)                               /*!< RP Mask      0x00008000 */
#define MCAN_ECR_RP_Set(x) (((uint32_t) (x) << MCAN_ECR_RP_Pos) & MCAN_ECR_RP_Msk) /*!< RP Set Value            */
#define MCAN_ECR_RP_Get(x) (((uint32_t) (x) &MCAN_ECR_RP_Msk) >> MCAN_ECR_RP_Pos)  /*!< RP Get Value            */


#define MCAN_ECR_REC_Pos    (8U)                                                      /*!< REC Postion   8          */
#define MCAN_ECR_REC_Msk    (0x7fU << MCAN_ECR_REC_Pos)                               /*!< REC Mask      0x00007F00 */
#define MCAN_ECR_REC_Set(x) (((uint32_t) (x) << MCAN_ECR_REC_Pos) & MCAN_ECR_REC_Msk) /*!< REC Set Value            */
#define MCAN_ECR_REC_Get(x) (((uint32_t) (x) &MCAN_ECR_REC_Msk) >> MCAN_ECR_REC_Pos)  /*!< REC Get Value            */


#define MCAN_ECR_TEC_Pos    (0U)                                                      /*!< TEC Postion   0          */
#define MCAN_ECR_TEC_Msk    (0xffU << MCAN_ECR_TEC_Pos)                               /*!< TEC Mask      0x000000FF */
#define MCAN_ECR_TEC_Set(x) (((uint32_t) (x) << MCAN_ECR_TEC_Pos) & MCAN_ECR_TEC_Msk) /*!< TEC Set Value            */
#define MCAN_ECR_TEC_Get(x) (((uint32_t) (x) &MCAN_ECR_TEC_Msk) >> MCAN_ECR_TEC_Pos)  /*!< TEC Get Value            */


/* PSR bitfield */
#define MCAN_PSR_TDCV_Pos (16U)                        /*!< TDCV Postion   16         */
#define MCAN_PSR_TDCV_Msk (0x7fU << MCAN_PSR_TDCV_Pos) /*!< TDCV Mask      0x007F0000 */
#define MCAN_PSR_TDCV_Set(x) \
    (((uint32_t) (x) << MCAN_PSR_TDCV_Pos) & MCAN_PSR_TDCV_Msk) /*!< TDCV Set Value            */
#define MCAN_PSR_TDCV_Get(x) \
    (((uint32_t) (x) &MCAN_PSR_TDCV_Msk) >> MCAN_PSR_TDCV_Pos) /*!< TDCV Get Value            */


#define MCAN_PSR_PXE_Pos    (14U)                                                     /*!< PXE Postion   14         */
#define MCAN_PSR_PXE_Msk    (0x1U << MCAN_PSR_PXE_Pos)                                /*!< PXE Mask      0x00004000 */
#define MCAN_PSR_PXE_Set(x) (((uint32_t) (x) << MCAN_PSR_PXE_Pos) & MCAN_PSR_PXE_Msk) /*!< PXE Set Value            */
#define MCAN_PSR_PXE_Get(x) (((uint32_t) (x) &MCAN_PSR_PXE_Msk) >> MCAN_PSR_PXE_Pos)  /*!< PXE Get Value            */


#define MCAN_PSR_RFDF_Pos (13U)                       /*!< RFDF Postion   13         */
#define MCAN_PSR_RFDF_Msk (0x1U << MCAN_PSR_RFDF_Pos) /*!< RFDF Mask      0x00002000 */
#define MCAN_PSR_RFDF_Set(x) \
    (((uint32_t) (x) << MCAN_PSR_RFDF_Pos) & MCAN_PSR_RFDF_Msk) /*!< RFDF Set Value            */
#define MCAN_PSR_RFDF_Get(x) \
    (((uint32_t) (x) &MCAN_PSR_RFDF_Msk) >> MCAN_PSR_RFDF_Pos) /*!< RFDF Get Value            */


#define MCAN_PSR_RBRS_Pos (12U)                       /*!< RBRS Postion   12         */
#define MCAN_PSR_RBRS_Msk (0x1U << MCAN_PSR_RBRS_Pos) /*!< RBRS Mask      0x00001000 */
#define MCAN_PSR_RBRS_Set(x) \
    (((uint32_t) (x) << MCAN_PSR_RBRS_Pos) & MCAN_PSR_RBRS_Msk) /*!< RBRS Set Value            */
#define MCAN_PSR_RBRS_Get(x) \
    (((uint32_t) (x) &MCAN_PSR_RBRS_Msk) >> MCAN_PSR_RBRS_Pos) /*!< RBRS Get Value            */


#define MCAN_PSR_RESI_Pos (11U)                       /*!< RESI Postion   11         */
#define MCAN_PSR_RESI_Msk (0x1U << MCAN_PSR_RESI_Pos) /*!< RESI Mask      0x00000800 */
#define MCAN_PSR_RESI_Set(x) \
    (((uint32_t) (x) << MCAN_PSR_RESI_Pos) & MCAN_PSR_RESI_Msk) /*!< RESI Set Value            */
#define MCAN_PSR_RESI_Get(x) \
    (((uint32_t) (x) &MCAN_PSR_RESI_Msk) >> MCAN_PSR_RESI_Pos) /*!< RESI Get Value            */


#define MCAN_PSR_DLEC_Pos (8U)                        /*!< DLEC Postion   8          */
#define MCAN_PSR_DLEC_Msk (0x7U << MCAN_PSR_DLEC_Pos) /*!< DLEC Mask      0x00000700 */
#define MCAN_PSR_DLEC_Set(x) \
    (((uint32_t) (x) << MCAN_PSR_DLEC_Pos) & MCAN_PSR_DLEC_Msk) /*!< DLEC Set Value            */
#define MCAN_PSR_DLEC_Get(x) \
    (((uint32_t) (x) &MCAN_PSR_DLEC_Msk) >> MCAN_PSR_DLEC_Pos) /*!< DLEC Get Value            */


#define MCAN_PSR_BO_Pos    (7U)                                                    /*!< BO Postion   7          */
#define MCAN_PSR_BO_Msk    (0x1U << MCAN_PSR_BO_Pos)                               /*!< BO Mask      0x00000080 */
#define MCAN_PSR_BO_Set(x) (((uint32_t) (x) << MCAN_PSR_BO_Pos) & MCAN_PSR_BO_Msk) /*!< BO Set Value            */
#define MCAN_PSR_BO_Get(x) (((uint32_t) (x) &MCAN_PSR_BO_Msk) >> MCAN_PSR_BO_Pos)  /*!< BO Get Value            */


#define MCAN_PSR_EW_Pos    (6U)                                                    /*!< EW Postion   6          */
#define MCAN_PSR_EW_Msk    (0x1U << MCAN_PSR_EW_Pos)                               /*!< EW Mask      0x00000040 */
#define MCAN_PSR_EW_Set(x) (((uint32_t) (x) << MCAN_PSR_EW_Pos) & MCAN_PSR_EW_Msk) /*!< EW Set Value            */
#define MCAN_PSR_EW_Get(x) (((uint32_t) (x) &MCAN_PSR_EW_Msk) >> MCAN_PSR_EW_Pos)  /*!< EW Get Value            */


#define MCAN_PSR_EP_Pos    (5U)                                                    /*!< EP Postion   5          */
#define MCAN_PSR_EP_Msk    (0x1U << MCAN_PSR_EP_Pos)                               /*!< EP Mask      0x00000020 */
#define MCAN_PSR_EP_Set(x) (((uint32_t) (x) << MCAN_PSR_EP_Pos) & MCAN_PSR_EP_Msk) /*!< EP Set Value            */
#define MCAN_PSR_EP_Get(x) (((uint32_t) (x) &MCAN_PSR_EP_Msk) >> MCAN_PSR_EP_Pos)  /*!< EP Get Value            */


#define MCAN_PSR_ACT_Pos    (3U)                                                      /*!< ACT Postion   3          */
#define MCAN_PSR_ACT_Msk    (0x3U << MCAN_PSR_ACT_Pos)                                /*!< ACT Mask      0x00000018 */
#define MCAN_PSR_ACT_Set(x) (((uint32_t) (x) << MCAN_PSR_ACT_Pos) & MCAN_PSR_ACT_Msk) /*!< ACT Set Value            */
#define MCAN_PSR_ACT_Get(x) (((uint32_t) (x) &MCAN_PSR_ACT_Msk) >> MCAN_PSR_ACT_Pos)  /*!< ACT Get Value            */


#define MCAN_PSR_LEC_Pos    (0U)                                                      /*!< LEC Postion   0          */
#define MCAN_PSR_LEC_Msk    (0x7U << MCAN_PSR_LEC_Pos)                                /*!< LEC Mask      0x00000007 */
#define MCAN_PSR_LEC_Set(x) (((uint32_t) (x) << MCAN_PSR_LEC_Pos) & MCAN_PSR_LEC_Msk) /*!< LEC Set Value            */
#define MCAN_PSR_LEC_Get(x) (((uint32_t) (x) &MCAN_PSR_LEC_Msk) >> MCAN_PSR_LEC_Pos)  /*!< LEC Get Value            */


/* TDCR bitfield */
#define MCAN_TDCR_TDCO_Pos (8U)                          /*!< TDCO Postion   8          */
#define MCAN_TDCR_TDCO_Msk (0x7fU << MCAN_TDCR_TDCO_Pos) /*!< TDCO Mask      0x00007F00 */
#define MCAN_TDCR_TDCO_Set(x) \
    (((uint32_t) (x) << MCAN_TDCR_TDCO_Pos) & MCAN_TDCR_TDCO_Msk) /*!< TDCO Set Value            */
#define MCAN_TDCR_TDCO_Get(x) \
    (((uint32_t) (x) &MCAN_TDCR_TDCO_Msk) >> MCAN_TDCR_TDCO_Pos) /*!< TDCO Get Value            */


#define MCAN_TDCR_TDCF_Pos (0U)                          /*!< TDCF Postion   0          */
#define MCAN_TDCR_TDCF_Msk (0x7fU << MCAN_TDCR_TDCF_Pos) /*!< TDCF Mask      0x0000007F */
#define MCAN_TDCR_TDCF_Set(x) \
    (((uint32_t) (x) << MCAN_TDCR_TDCF_Pos) & MCAN_TDCR_TDCF_Msk) /*!< TDCF Set Value            */
#define MCAN_TDCR_TDCF_Get(x) \
    (((uint32_t) (x) &MCAN_TDCR_TDCF_Msk) >> MCAN_TDCR_TDCF_Pos) /*!< TDCF Get Value            */


/* IR bitfield */
#define MCAN_IR_ARA_Pos    (29U)                                                   /*!< ARA Postion   29         */
#define MCAN_IR_ARA_Msk    (0x1U << MCAN_IR_ARA_Pos)                               /*!< ARA Mask      0x20000000 */
#define MCAN_IR_ARA_Set(x) (((uint32_t) (x) << MCAN_IR_ARA_Pos) & MCAN_IR_ARA_Msk) /*!< ARA Set Value            */
#define MCAN_IR_ARA_Get(x) (((uint32_t) (x) &MCAN_IR_ARA_Msk) >> MCAN_IR_ARA_Pos)  /*!< ARA Get Value            */


#define MCAN_IR_PED_Pos    (28U)                                                   /*!< PED Postion   28         */
#define MCAN_IR_PED_Msk    (0x1U << MCAN_IR_PED_Pos)                               /*!< PED Mask      0x10000000 */
#define MCAN_IR_PED_Set(x) (((uint32_t) (x) << MCAN_IR_PED_Pos) & MCAN_IR_PED_Msk) /*!< PED Set Value            */
#define MCAN_IR_PED_Get(x) (((uint32_t) (x) &MCAN_IR_PED_Msk) >> MCAN_IR_PED_Pos)  /*!< PED Get Value            */


#define MCAN_IR_PEA_Pos    (27U)                                                   /*!< PEA Postion   27         */
#define MCAN_IR_PEA_Msk    (0x1U << MCAN_IR_PEA_Pos)                               /*!< PEA Mask      0x08000000 */
#define MCAN_IR_PEA_Set(x) (((uint32_t) (x) << MCAN_IR_PEA_Pos) & MCAN_IR_PEA_Msk) /*!< PEA Set Value            */
#define MCAN_IR_PEA_Get(x) (((uint32_t) (x) &MCAN_IR_PEA_Msk) >> MCAN_IR_PEA_Pos)  /*!< PEA Get Value            */


#define MCAN_IR_WDI_Pos    (26U)                                                   /*!< WDI Postion   26         */
#define MCAN_IR_WDI_Msk    (0x1U << MCAN_IR_WDI_Pos)                               /*!< WDI Mask      0x04000000 */
#define MCAN_IR_WDI_Set(x) (((uint32_t) (x) << MCAN_IR_WDI_Pos) & MCAN_IR_WDI_Msk) /*!< WDI Set Value            */
#define MCAN_IR_WDI_Get(x) (((uint32_t) (x) &MCAN_IR_WDI_Msk) >> MCAN_IR_WDI_Pos)  /*!< WDI Get Value            */


#define MCAN_IR_BO_Pos    (25U)                                                 /*!< BO Postion   25         */
#define MCAN_IR_BO_Msk    (0x1U << MCAN_IR_BO_Pos)                              /*!< BO Mask      0x02000000 */
#define MCAN_IR_BO_Set(x) (((uint32_t) (x) << MCAN_IR_BO_Pos) & MCAN_IR_BO_Msk) /*!< BO Set Value            */
#define MCAN_IR_BO_Get(x) (((uint32_t) (x) &MCAN_IR_BO_Msk) >> MCAN_IR_BO_Pos)  /*!< BO Get Value            */


#define MCAN_IR_EW_Pos    (24U)                                                 /*!< EW Postion   24         */
#define MCAN_IR_EW_Msk    (0x1U << MCAN_IR_EW_Pos)                              /*!< EW Mask      0x01000000 */
#define MCAN_IR_EW_Set(x) (((uint32_t) (x) << MCAN_IR_EW_Pos) & MCAN_IR_EW_Msk) /*!< EW Set Value            */
#define MCAN_IR_EW_Get(x) (((uint32_t) (x) &MCAN_IR_EW_Msk) >> MCAN_IR_EW_Pos)  /*!< EW Get Value            */


#define MCAN_IR_EP_Pos    (23U)                                                 /*!< EP Postion   23         */
#define MCAN_IR_EP_Msk    (0x1U << MCAN_IR_EP_Pos)                              /*!< EP Mask      0x00800000 */
#define MCAN_IR_EP_Set(x) (((uint32_t) (x) << MCAN_IR_EP_Pos) & MCAN_IR_EP_Msk) /*!< EP Set Value            */
#define MCAN_IR_EP_Get(x) (((uint32_t) (x) &MCAN_IR_EP_Msk) >> MCAN_IR_EP_Pos)  /*!< EP Get Value            */


#define MCAN_IR_ELO_Pos    (22U)                                                   /*!< ELO Postion   22         */
#define MCAN_IR_ELO_Msk    (0x1U << MCAN_IR_ELO_Pos)                               /*!< ELO Mask      0x00400000 */
#define MCAN_IR_ELO_Set(x) (((uint32_t) (x) << MCAN_IR_ELO_Pos) & MCAN_IR_ELO_Msk) /*!< ELO Set Value            */
#define MCAN_IR_ELO_Get(x) (((uint32_t) (x) &MCAN_IR_ELO_Msk) >> MCAN_IR_ELO_Pos)  /*!< ELO Get Value            */


#define MCAN_IR_BEU_Pos    (21U)                                                   /*!< BEU Postion   21         */
#define MCAN_IR_BEU_Msk    (0x1U << MCAN_IR_BEU_Pos)                               /*!< BEU Mask      0x00200000 */
#define MCAN_IR_BEU_Set(x) (((uint32_t) (x) << MCAN_IR_BEU_Pos) & MCAN_IR_BEU_Msk) /*!< BEU Set Value            */
#define MCAN_IR_BEU_Get(x) (((uint32_t) (x) &MCAN_IR_BEU_Msk) >> MCAN_IR_BEU_Pos)  /*!< BEU Get Value            */


#define MCAN_IR_BEC_Pos    (20U)                                                   /*!< BEC Postion   20         */
#define MCAN_IR_BEC_Msk    (0x1U << MCAN_IR_BEC_Pos)                               /*!< BEC Mask      0x00100000 */
#define MCAN_IR_BEC_Set(x) (((uint32_t) (x) << MCAN_IR_BEC_Pos) & MCAN_IR_BEC_Msk) /*!< BEC Set Value            */
#define MCAN_IR_BEC_Get(x) (((uint32_t) (x) &MCAN_IR_BEC_Msk) >> MCAN_IR_BEC_Pos)  /*!< BEC Get Value            */


#define MCAN_IR_DRX_Pos    (19U)                                                   /*!< DRX Postion   19         */
#define MCAN_IR_DRX_Msk    (0x1U << MCAN_IR_DRX_Pos)                               /*!< DRX Mask      0x00080000 */
#define MCAN_IR_DRX_Set(x) (((uint32_t) (x) << MCAN_IR_DRX_Pos) & MCAN_IR_DRX_Msk) /*!< DRX Set Value            */
#define MCAN_IR_DRX_Get(x) (((uint32_t) (x) &MCAN_IR_DRX_Msk) >> MCAN_IR_DRX_Pos)  /*!< DRX Get Value            */


#define MCAN_IR_TOO_Pos    (18U)                                                   /*!< TOO Postion   18         */
#define MCAN_IR_TOO_Msk    (0x1U << MCAN_IR_TOO_Pos)                               /*!< TOO Mask      0x00040000 */
#define MCAN_IR_TOO_Set(x) (((uint32_t) (x) << MCAN_IR_TOO_Pos) & MCAN_IR_TOO_Msk) /*!< TOO Set Value            */
#define MCAN_IR_TOO_Get(x) (((uint32_t) (x) &MCAN_IR_TOO_Msk) >> MCAN_IR_TOO_Pos)  /*!< TOO Get Value            */


#define MCAN_IR_MRAF_Pos    (17U)                                                     /*!< MRAF Postion   17         */
#define MCAN_IR_MRAF_Msk    (0x1U << MCAN_IR_MRAF_Pos)                                /*!< MRAF Mask      0x00020000 */
#define MCAN_IR_MRAF_Set(x) (((uint32_t) (x) << MCAN_IR_MRAF_Pos) & MCAN_IR_MRAF_Msk) /*!< MRAF Set Value */
#define MCAN_IR_MRAF_Get(x) (((uint32_t) (x) &MCAN_IR_MRAF_Msk) >> MCAN_IR_MRAF_Pos)  /*!< MRAF Get Value            */


#define MCAN_IR_TSW_Pos    (16U)                                                   /*!< TSW Postion   16         */
#define MCAN_IR_TSW_Msk    (0x1U << MCAN_IR_TSW_Pos)                               /*!< TSW Mask      0x00010000 */
#define MCAN_IR_TSW_Set(x) (((uint32_t) (x) << MCAN_IR_TSW_Pos) & MCAN_IR_TSW_Msk) /*!< TSW Set Value            */
#define MCAN_IR_TSW_Get(x) (((uint32_t) (x) &MCAN_IR_TSW_Msk) >> MCAN_IR_TSW_Pos)  /*!< TSW Get Value            */


#define MCAN_IR_TEFL_Pos    (15U)                                                     /*!< TEFL Postion   15         */
#define MCAN_IR_TEFL_Msk    (0x1U << MCAN_IR_TEFL_Pos)                                /*!< TEFL Mask      0x00008000 */
#define MCAN_IR_TEFL_Set(x) (((uint32_t) (x) << MCAN_IR_TEFL_Pos) & MCAN_IR_TEFL_Msk) /*!< TEFL Set Value */
#define MCAN_IR_TEFL_Get(x) (((uint32_t) (x) &MCAN_IR_TEFL_Msk) >> MCAN_IR_TEFL_Pos)  /*!< TEFL Get Value            */


#define MCAN_IR_TEFF_Pos    (14U)                                                     /*!< TEFF Postion   14         */
#define MCAN_IR_TEFF_Msk    (0x1U << MCAN_IR_TEFF_Pos)                                /*!< TEFF Mask      0x00004000 */
#define MCAN_IR_TEFF_Set(x) (((uint32_t) (x) << MCAN_IR_TEFF_Pos) & MCAN_IR_TEFF_Msk) /*!< TEFF Set Value */
#define MCAN_IR_TEFF_Get(x) (((uint32_t) (x) &MCAN_IR_TEFF_Msk) >> MCAN_IR_TEFF_Pos)  /*!< TEFF Get Value            */


#define MCAN_IR_TEFW_Pos    (13U)                                                     /*!< TEFW Postion   13         */
#define MCAN_IR_TEFW_Msk    (0x1U << MCAN_IR_TEFW_Pos)                                /*!< TEFW Mask      0x00002000 */
#define MCAN_IR_TEFW_Set(x) (((uint32_t) (x) << MCAN_IR_TEFW_Pos) & MCAN_IR_TEFW_Msk) /*!< TEFW Set Value */
#define MCAN_IR_TEFW_Get(x) (((uint32_t) (x) &MCAN_IR_TEFW_Msk) >> MCAN_IR_TEFW_Pos)  /*!< TEFW Get Value            */


#define MCAN_IR_TEFN_Pos    (12U)                                                     /*!< TEFN Postion   12         */
#define MCAN_IR_TEFN_Msk    (0x1U << MCAN_IR_TEFN_Pos)                                /*!< TEFN Mask      0x00001000 */
#define MCAN_IR_TEFN_Set(x) (((uint32_t) (x) << MCAN_IR_TEFN_Pos) & MCAN_IR_TEFN_Msk) /*!< TEFN Set Value */
#define MCAN_IR_TEFN_Get(x) (((uint32_t) (x) &MCAN_IR_TEFN_Msk) >> MCAN_IR_TEFN_Pos)  /*!< TEFN Get Value            */


#define MCAN_IR_TFE_Pos    (11U)                                                   /*!< TFE Postion   11         */
#define MCAN_IR_TFE_Msk    (0x1U << MCAN_IR_TFE_Pos)                               /*!< TFE Mask      0x00000800 */
#define MCAN_IR_TFE_Set(x) (((uint32_t) (x) << MCAN_IR_TFE_Pos) & MCAN_IR_TFE_Msk) /*!< TFE Set Value            */
#define MCAN_IR_TFE_Get(x) (((uint32_t) (x) &MCAN_IR_TFE_Msk) >> MCAN_IR_TFE_Pos)  /*!< TFE Get Value            */


#define MCAN_IR_TCF_Pos    (10U)                                                   /*!< TCF Postion   10         */
#define MCAN_IR_TCF_Msk    (0x1U << MCAN_IR_TCF_Pos)                               /*!< TCF Mask      0x00000400 */
#define MCAN_IR_TCF_Set(x) (((uint32_t) (x) << MCAN_IR_TCF_Pos) & MCAN_IR_TCF_Msk) /*!< TCF Set Value            */
#define MCAN_IR_TCF_Get(x) (((uint32_t) (x) &MCAN_IR_TCF_Msk) >> MCAN_IR_TCF_Pos)  /*!< TCF Get Value            */


#define MCAN_IR_TC_Pos    (9U)                                                  /*!< TC Postion   9          */
#define MCAN_IR_TC_Msk    (0x1U << MCAN_IR_TC_Pos)                              /*!< TC Mask      0x00000200 */
#define MCAN_IR_TC_Set(x) (((uint32_t) (x) << MCAN_IR_TC_Pos) & MCAN_IR_TC_Msk) /*!< TC Set Value            */
#define MCAN_IR_TC_Get(x) (((uint32_t) (x) &MCAN_IR_TC_Msk) >> MCAN_IR_TC_Pos)  /*!< TC Get Value            */


#define MCAN_IR_HPM_Pos    (8U)                                                    /*!< HPM Postion   8          */
#define MCAN_IR_HPM_Msk    (0x1U << MCAN_IR_HPM_Pos)                               /*!< HPM Mask      0x00000100 */
#define MCAN_IR_HPM_Set(x) (((uint32_t) (x) << MCAN_IR_HPM_Pos) & MCAN_IR_HPM_Msk) /*!< HPM Set Value            */
#define MCAN_IR_HPM_Get(x) (((uint32_t) (x) &MCAN_IR_HPM_Msk) >> MCAN_IR_HPM_Pos)  /*!< HPM Get Value            */


#define MCAN_IR_RF1L_Pos    (7U)                                                      /*!< RF1L Postion   7          */
#define MCAN_IR_RF1L_Msk    (0x1U << MCAN_IR_RF1L_Pos)                                /*!< RF1L Mask      0x00000080 */
#define MCAN_IR_RF1L_Set(x) (((uint32_t) (x) << MCAN_IR_RF1L_Pos) & MCAN_IR_RF1L_Msk) /*!< RF1L Set Value */
#define MCAN_IR_RF1L_Get(x) (((uint32_t) (x) &MCAN_IR_RF1L_Msk) >> MCAN_IR_RF1L_Pos)  /*!< RF1L Get Value            */


#define MCAN_IR_RF1F_Pos    (6U)                                                      /*!< RF1F Postion   6          */
#define MCAN_IR_RF1F_Msk    (0x1U << MCAN_IR_RF1F_Pos)                                /*!< RF1F Mask      0x00000040 */
#define MCAN_IR_RF1F_Set(x) (((uint32_t) (x) << MCAN_IR_RF1F_Pos) & MCAN_IR_RF1F_Msk) /*!< RF1F Set Value */
#define MCAN_IR_RF1F_Get(x) (((uint32_t) (x) &MCAN_IR_RF1F_Msk) >> MCAN_IR_RF1F_Pos)  /*!< RF1F Get Value            */


#define MCAN_IR_RF1W_Pos    (5U)                                                      /*!< RF1W Postion   5          */
#define MCAN_IR_RF1W_Msk    (0x1U << MCAN_IR_RF1W_Pos)                                /*!< RF1W Mask      0x00000020 */
#define MCAN_IR_RF1W_Set(x) (((uint32_t) (x) << MCAN_IR_RF1W_Pos) & MCAN_IR_RF1W_Msk) /*!< RF1W Set Value */
#define MCAN_IR_RF1W_Get(x) (((uint32_t) (x) &MCAN_IR_RF1W_Msk) >> MCAN_IR_RF1W_Pos)  /*!< RF1W Get Value            */


#define MCAN_IR_RF1N_Pos    (4U)                                                      /*!< RF1N Postion   4          */
#define MCAN_IR_RF1N_Msk    (0x1U << MCAN_IR_RF1N_Pos)                                /*!< RF1N Mask      0x00000010 */
#define MCAN_IR_RF1N_Set(x) (((uint32_t) (x) << MCAN_IR_RF1N_Pos) & MCAN_IR_RF1N_Msk) /*!< RF1N Set Value */
#define MCAN_IR_RF1N_Get(x) (((uint32_t) (x) &MCAN_IR_RF1N_Msk) >> MCAN_IR_RF1N_Pos)  /*!< RF1N Get Value            */


#define MCAN_IR_RF0L_Pos    (3U)                                                      /*!< RF0L Postion   3          */
#define MCAN_IR_RF0L_Msk    (0x1U << MCAN_IR_RF0L_Pos)                                /*!< RF0L Mask      0x00000008 */
#define MCAN_IR_RF0L_Set(x) (((uint32_t) (x) << MCAN_IR_RF0L_Pos) & MCAN_IR_RF0L_Msk) /*!< RF0L Set Value */
#define MCAN_IR_RF0L_Get(x) (((uint32_t) (x) &MCAN_IR_RF0L_Msk) >> MCAN_IR_RF0L_Pos)  /*!< RF0L Get Value            */


#define MCAN_IR_RF0F_Pos    (2U)                                                      /*!< RF0F Postion   2          */
#define MCAN_IR_RF0F_Msk    (0x1U << MCAN_IR_RF0F_Pos)                                /*!< RF0F Mask      0x00000004 */
#define MCAN_IR_RF0F_Set(x) (((uint32_t) (x) << MCAN_IR_RF0F_Pos) & MCAN_IR_RF0F_Msk) /*!< RF0F Set Value */
#define MCAN_IR_RF0F_Get(x) (((uint32_t) (x) &MCAN_IR_RF0F_Msk) >> MCAN_IR_RF0F_Pos)  /*!< RF0F Get Value            */


#define MCAN_IR_RF0W_Pos    (1U)                                                      /*!< RF0W Postion   1          */
#define MCAN_IR_RF0W_Msk    (0x1U << MCAN_IR_RF0W_Pos)                                /*!< RF0W Mask      0x00000002 */
#define MCAN_IR_RF0W_Set(x) (((uint32_t) (x) << MCAN_IR_RF0W_Pos) & MCAN_IR_RF0W_Msk) /*!< RF0W Set Value */
#define MCAN_IR_RF0W_Get(x) (((uint32_t) (x) &MCAN_IR_RF0W_Msk) >> MCAN_IR_RF0W_Pos)  /*!< RF0W Get Value            */


#define MCAN_IR_RF0N_Pos    (0U)                                                      /*!< RF0N Postion   0          */
#define MCAN_IR_RF0N_Msk    (0x1U << MCAN_IR_RF0N_Pos)                                /*!< RF0N Mask      0x00000001 */
#define MCAN_IR_RF0N_Set(x) (((uint32_t) (x) << MCAN_IR_RF0N_Pos) & MCAN_IR_RF0N_Msk) /*!< RF0N Set Value */
#define MCAN_IR_RF0N_Get(x) (((uint32_t) (x) &MCAN_IR_RF0N_Msk) >> MCAN_IR_RF0N_Pos)  /*!< RF0N Get Value            */


/* IE bitfield */
#define MCAN_IE_ARAE_Pos    (29U)                                                     /*!< ARAE Postion   29         */
#define MCAN_IE_ARAE_Msk    (0x1U << MCAN_IE_ARAE_Pos)                                /*!< ARAE Mask      0x20000000 */
#define MCAN_IE_ARAE_Set(x) (((uint32_t) (x) << MCAN_IE_ARAE_Pos) & MCAN_IE_ARAE_Msk) /*!< ARAE Set Value */
#define MCAN_IE_ARAE_Get(x) (((uint32_t) (x) &MCAN_IE_ARAE_Msk) >> MCAN_IE_ARAE_Pos)  /*!< ARAE Get Value            */


#define MCAN_IE_PEDE_Pos    (28U)                                                     /*!< PEDE Postion   28         */
#define MCAN_IE_PEDE_Msk    (0x1U << MCAN_IE_PEDE_Pos)                                /*!< PEDE Mask      0x10000000 */
#define MCAN_IE_PEDE_Set(x) (((uint32_t) (x) << MCAN_IE_PEDE_Pos) & MCAN_IE_PEDE_Msk) /*!< PEDE Set Value */
#define MCAN_IE_PEDE_Get(x) (((uint32_t) (x) &MCAN_IE_PEDE_Msk) >> MCAN_IE_PEDE_Pos)  /*!< PEDE Get Value            */


#define MCAN_IE_PEAE_Pos    (27U)                                                     /*!< PEAE Postion   27         */
#define MCAN_IE_PEAE_Msk    (0x1U << MCAN_IE_PEAE_Pos)                                /*!< PEAE Mask      0x08000000 */
#define MCAN_IE_PEAE_Set(x) (((uint32_t) (x) << MCAN_IE_PEAE_Pos) & MCAN_IE_PEAE_Msk) /*!< PEAE Set Value */
#define MCAN_IE_PEAE_Get(x) (((uint32_t) (x) &MCAN_IE_PEAE_Msk) >> MCAN_IE_PEAE_Pos)  /*!< PEAE Get Value            */


#define MCAN_IE_WDIE_Pos    (26U)                                                     /*!< WDIE Postion   26         */
#define MCAN_IE_WDIE_Msk    (0x1U << MCAN_IE_WDIE_Pos)                                /*!< WDIE Mask      0x04000000 */
#define MCAN_IE_WDIE_Set(x) (((uint32_t) (x) << MCAN_IE_WDIE_Pos) & MCAN_IE_WDIE_Msk) /*!< WDIE Set Value */
#define MCAN_IE_WDIE_Get(x) (((uint32_t) (x) &MCAN_IE_WDIE_Msk) >> MCAN_IE_WDIE_Pos)  /*!< WDIE Get Value            */


#define MCAN_IE_BOE_Pos    (25U)                                                   /*!< BOE Postion   25         */
#define MCAN_IE_BOE_Msk    (0x1U << MCAN_IE_BOE_Pos)                               /*!< BOE Mask      0x02000000 */
#define MCAN_IE_BOE_Set(x) (((uint32_t) (x) << MCAN_IE_BOE_Pos) & MCAN_IE_BOE_Msk) /*!< BOE Set Value            */
#define MCAN_IE_BOE_Get(x) (((uint32_t) (x) &MCAN_IE_BOE_Msk) >> MCAN_IE_BOE_Pos)  /*!< BOE Get Value            */


#define MCAN_IE_EWE_Pos    (24U)                                                   /*!< EWE Postion   24         */
#define MCAN_IE_EWE_Msk    (0x1U << MCAN_IE_EWE_Pos)                               /*!< EWE Mask      0x01000000 */
#define MCAN_IE_EWE_Set(x) (((uint32_t) (x) << MCAN_IE_EWE_Pos) & MCAN_IE_EWE_Msk) /*!< EWE Set Value            */
#define MCAN_IE_EWE_Get(x) (((uint32_t) (x) &MCAN_IE_EWE_Msk) >> MCAN_IE_EWE_Pos)  /*!< EWE Get Value            */


#define MCAN_IE_EPE_Pos    (23U)                                                   /*!< EPE Postion   23         */
#define MCAN_IE_EPE_Msk    (0x1U << MCAN_IE_EPE_Pos)                               /*!< EPE Mask      0x00800000 */
#define MCAN_IE_EPE_Set(x) (((uint32_t) (x) << MCAN_IE_EPE_Pos) & MCAN_IE_EPE_Msk) /*!< EPE Set Value            */
#define MCAN_IE_EPE_Get(x) (((uint32_t) (x) &MCAN_IE_EPE_Msk) >> MCAN_IE_EPE_Pos)  /*!< EPE Get Value            */


#define MCAN_IE_ELOE_Pos    (22U)                                                     /*!< ELOE Postion   22         */
#define MCAN_IE_ELOE_Msk    (0x1U << MCAN_IE_ELOE_Pos)                                /*!< ELOE Mask      0x00400000 */
#define MCAN_IE_ELOE_Set(x) (((uint32_t) (x) << MCAN_IE_ELOE_Pos) & MCAN_IE_ELOE_Msk) /*!< ELOE Set Value */
#define MCAN_IE_ELOE_Get(x) (((uint32_t) (x) &MCAN_IE_ELOE_Msk) >> MCAN_IE_ELOE_Pos)  /*!< ELOE Get Value            */


#define MCAN_IE_BEUE_Pos    (21U)                                                     /*!< BEUE Postion   21         */
#define MCAN_IE_BEUE_Msk    (0x1U << MCAN_IE_BEUE_Pos)                                /*!< BEUE Mask      0x00200000 */
#define MCAN_IE_BEUE_Set(x) (((uint32_t) (x) << MCAN_IE_BEUE_Pos) & MCAN_IE_BEUE_Msk) /*!< BEUE Set Value */
#define MCAN_IE_BEUE_Get(x) (((uint32_t) (x) &MCAN_IE_BEUE_Msk) >> MCAN_IE_BEUE_Pos)  /*!< BEUE Get Value            */


#define MCAN_IE_BECE_Pos    (20U)                                                     /*!< BECE Postion   20         */
#define MCAN_IE_BECE_Msk    (0x1U << MCAN_IE_BECE_Pos)                                /*!< BECE Mask      0x00100000 */
#define MCAN_IE_BECE_Set(x) (((uint32_t) (x) << MCAN_IE_BECE_Pos) & MCAN_IE_BECE_Msk) /*!< BECE Set Value */
#define MCAN_IE_BECE_Get(x) (((uint32_t) (x) &MCAN_IE_BECE_Msk) >> MCAN_IE_BECE_Pos)  /*!< BECE Get Value            */


#define MCAN_IE_DRX_Pos    (19U)                                                   /*!< DRX Postion   19         */
#define MCAN_IE_DRX_Msk    (0x1U << MCAN_IE_DRX_Pos)                               /*!< DRX Mask      0x00080000 */
#define MCAN_IE_DRX_Set(x) (((uint32_t) (x) << MCAN_IE_DRX_Pos) & MCAN_IE_DRX_Msk) /*!< DRX Set Value            */
#define MCAN_IE_DRX_Get(x) (((uint32_t) (x) &MCAN_IE_DRX_Msk) >> MCAN_IE_DRX_Pos)  /*!< DRX Get Value            */


#define MCAN_IE_TOOE_Pos    (18U)                                                     /*!< TOOE Postion   18         */
#define MCAN_IE_TOOE_Msk    (0x1U << MCAN_IE_TOOE_Pos)                                /*!< TOOE Mask      0x00040000 */
#define MCAN_IE_TOOE_Set(x) (((uint32_t) (x) << MCAN_IE_TOOE_Pos) & MCAN_IE_TOOE_Msk) /*!< TOOE Set Value */
#define MCAN_IE_TOOE_Get(x) (((uint32_t) (x) &MCAN_IE_TOOE_Msk) >> MCAN_IE_TOOE_Pos)  /*!< TOOE Get Value            */


#define MCAN_IE_MRAFE_Pos (17U)                       /*!< MRAFE Postion   17         */
#define MCAN_IE_MRAFE_Msk (0x1U << MCAN_IE_MRAFE_Pos) /*!< MRAFE Mask      0x00020000 */
#define MCAN_IE_MRAFE_Set(x) \
    (((uint32_t) (x) << MCAN_IE_MRAFE_Pos) & MCAN_IE_MRAFE_Msk) /*!< MRAFE Set Value            */
#define MCAN_IE_MRAFE_Get(x) \
    (((uint32_t) (x) &MCAN_IE_MRAFE_Msk) >> MCAN_IE_MRAFE_Pos) /*!< MRAFE Get Value            */


#define MCAN_IE_TSWE_Pos    (16U)                                                     /*!< TSWE Postion   16         */
#define MCAN_IE_TSWE_Msk    (0x1U << MCAN_IE_TSWE_Pos)                                /*!< TSWE Mask      0x00010000 */
#define MCAN_IE_TSWE_Set(x) (((uint32_t) (x) << MCAN_IE_TSWE_Pos) & MCAN_IE_TSWE_Msk) /*!< TSWE Set Value */
#define MCAN_IE_TSWE_Get(x) (((uint32_t) (x) &MCAN_IE_TSWE_Msk) >> MCAN_IE_TSWE_Pos)  /*!< TSWE Get Value            */


#define MCAN_IE_TEFLE_Pos (15U)                       /*!< TEFLE Postion   15         */
#define MCAN_IE_TEFLE_Msk (0x1U << MCAN_IE_TEFLE_Pos) /*!< TEFLE Mask      0x00008000 */
#define MCAN_IE_TEFLE_Set(x) \
    (((uint32_t) (x) << MCAN_IE_TEFLE_Pos) & MCAN_IE_TEFLE_Msk) /*!< TEFLE Set Value            */
#define MCAN_IE_TEFLE_Get(x) \
    (((uint32_t) (x) &MCAN_IE_TEFLE_Msk) >> MCAN_IE_TEFLE_Pos) /*!< TEFLE Get Value            */


#define MCAN_IE_TEFFE_Pos (14U)                       /*!< TEFFE Postion   14         */
#define MCAN_IE_TEFFE_Msk (0x1U << MCAN_IE_TEFFE_Pos) /*!< TEFFE Mask      0x00004000 */
#define MCAN_IE_TEFFE_Set(x) \
    (((uint32_t) (x) << MCAN_IE_TEFFE_Pos) & MCAN_IE_TEFFE_Msk) /*!< TEFFE Set Value            */
#define MCAN_IE_TEFFE_Get(x) \
    (((uint32_t) (x) &MCAN_IE_TEFFE_Msk) >> MCAN_IE_TEFFE_Pos) /*!< TEFFE Get Value            */


#define MCAN_IE_TEFWE_Pos (13U)                       /*!< TEFWE Postion   13         */
#define MCAN_IE_TEFWE_Msk (0x1U << MCAN_IE_TEFWE_Pos) /*!< TEFWE Mask      0x00002000 */
#define MCAN_IE_TEFWE_Set(x) \
    (((uint32_t) (x) << MCAN_IE_TEFWE_Pos) & MCAN_IE_TEFWE_Msk) /*!< TEFWE Set Value            */
#define MCAN_IE_TEFWE_Get(x) \
    (((uint32_t) (x) &MCAN_IE_TEFWE_Msk) >> MCAN_IE_TEFWE_Pos) /*!< TEFWE Get Value            */


#define MCAN_IE_TEFNE_Pos (12U)                       /*!< TEFNE Postion   12         */
#define MCAN_IE_TEFNE_Msk (0x1U << MCAN_IE_TEFNE_Pos) /*!< TEFNE Mask      0x00001000 */
#define MCAN_IE_TEFNE_Set(x) \
    (((uint32_t) (x) << MCAN_IE_TEFNE_Pos) & MCAN_IE_TEFNE_Msk) /*!< TEFNE Set Value            */
#define MCAN_IE_TEFNE_Get(x) \
    (((uint32_t) (x) &MCAN_IE_TEFNE_Msk) >> MCAN_IE_TEFNE_Pos) /*!< TEFNE Get Value            */


#define MCAN_IE_TFEE_Pos    (11U)                                                     /*!< TFEE Postion   11         */
#define MCAN_IE_TFEE_Msk    (0x1U << MCAN_IE_TFEE_Pos)                                /*!< TFEE Mask      0x00000800 */
#define MCAN_IE_TFEE_Set(x) (((uint32_t) (x) << MCAN_IE_TFEE_Pos) & MCAN_IE_TFEE_Msk) /*!< TFEE Set Value */
#define MCAN_IE_TFEE_Get(x) (((uint32_t) (x) &MCAN_IE_TFEE_Msk) >> MCAN_IE_TFEE_Pos)  /*!< TFEE Get Value            */


#define MCAN_IE_TCFE_Pos    (10U)                                                     /*!< TCFE Postion   10         */
#define MCAN_IE_TCFE_Msk    (0x1U << MCAN_IE_TCFE_Pos)                                /*!< TCFE Mask      0x00000400 */
#define MCAN_IE_TCFE_Set(x) (((uint32_t) (x) << MCAN_IE_TCFE_Pos) & MCAN_IE_TCFE_Msk) /*!< TCFE Set Value */
#define MCAN_IE_TCFE_Get(x) (((uint32_t) (x) &MCAN_IE_TCFE_Msk) >> MCAN_IE_TCFE_Pos)  /*!< TCFE Get Value            */


#define MCAN_IE_TCE_Pos    (9U)                                                    /*!< TCE Postion   9          */
#define MCAN_IE_TCE_Msk    (0x1U << MCAN_IE_TCE_Pos)                               /*!< TCE Mask      0x00000200 */
#define MCAN_IE_TCE_Set(x) (((uint32_t) (x) << MCAN_IE_TCE_Pos) & MCAN_IE_TCE_Msk) /*!< TCE Set Value            */
#define MCAN_IE_TCE_Get(x) (((uint32_t) (x) &MCAN_IE_TCE_Msk) >> MCAN_IE_TCE_Pos)  /*!< TCE Get Value            */


#define MCAN_IE_HPME_Pos    (8U)                                                      /*!< HPME Postion   8          */
#define MCAN_IE_HPME_Msk    (0x1U << MCAN_IE_HPME_Pos)                                /*!< HPME Mask      0x00000100 */
#define MCAN_IE_HPME_Set(x) (((uint32_t) (x) << MCAN_IE_HPME_Pos) & MCAN_IE_HPME_Msk) /*!< HPME Set Value */
#define MCAN_IE_HPME_Get(x) (((uint32_t) (x) &MCAN_IE_HPME_Msk) >> MCAN_IE_HPME_Pos)  /*!< HPME Get Value            */


#define MCAN_IE_RF1LE_Pos (7U)                        /*!< RF1LE Postion   7          */
#define MCAN_IE_RF1LE_Msk (0x1U << MCAN_IE_RF1LE_Pos) /*!< RF1LE Mask      0x00000080 */
#define MCAN_IE_RF1LE_Set(x) \
    (((uint32_t) (x) << MCAN_IE_RF1LE_Pos) & MCAN_IE_RF1LE_Msk) /*!< RF1LE Set Value            */
#define MCAN_IE_RF1LE_Get(x) \
    (((uint32_t) (x) &MCAN_IE_RF1LE_Msk) >> MCAN_IE_RF1LE_Pos) /*!< RF1LE Get Value            */


#define MCAN_IE_RF1FE_Pos (6U)                        /*!< RF1FE Postion   6          */
#define MCAN_IE_RF1FE_Msk (0x1U << MCAN_IE_RF1FE_Pos) /*!< RF1FE Mask      0x00000040 */
#define MCAN_IE_RF1FE_Set(x) \
    (((uint32_t) (x) << MCAN_IE_RF1FE_Pos) & MCAN_IE_RF1FE_Msk) /*!< RF1FE Set Value            */
#define MCAN_IE_RF1FE_Get(x) \
    (((uint32_t) (x) &MCAN_IE_RF1FE_Msk) >> MCAN_IE_RF1FE_Pos) /*!< RF1FE Get Value            */


#define MCAN_IE_RF1WE_Pos (5U)                        /*!< RF1WE Postion   5          */
#define MCAN_IE_RF1WE_Msk (0x1U << MCAN_IE_RF1WE_Pos) /*!< RF1WE Mask      0x00000020 */
#define MCAN_IE_RF1WE_Set(x) \
    (((uint32_t) (x) << MCAN_IE_RF1WE_Pos) & MCAN_IE_RF1WE_Msk) /*!< RF1WE Set Value            */
#define MCAN_IE_RF1WE_Get(x) \
    (((uint32_t) (x) &MCAN_IE_RF1WE_Msk) >> MCAN_IE_RF1WE_Pos) /*!< RF1WE Get Value            */


#define MCAN_IE_RF1NE_Pos (4U)                        /*!< RF1NE Postion   4          */
#define MCAN_IE_RF1NE_Msk (0x1U << MCAN_IE_RF1NE_Pos) /*!< RF1NE Mask      0x00000010 */
#define MCAN_IE_RF1NE_Set(x) \
    (((uint32_t) (x) << MCAN_IE_RF1NE_Pos) & MCAN_IE_RF1NE_Msk) /*!< RF1NE Set Value            */
#define MCAN_IE_RF1NE_Get(x) \
    (((uint32_t) (x) &MCAN_IE_RF1NE_Msk) >> MCAN_IE_RF1NE_Pos) /*!< RF1NE Get Value            */


#define MCAN_IE_RF0LE_Pos (3U)                        /*!< RF0LE Postion   3          */
#define MCAN_IE_RF0LE_Msk (0x1U << MCAN_IE_RF0LE_Pos) /*!< RF0LE Mask      0x00000008 */
#define MCAN_IE_RF0LE_Set(x) \
    (((uint32_t) (x) << MCAN_IE_RF0LE_Pos) & MCAN_IE_RF0LE_Msk) /*!< RF0LE Set Value            */
#define MCAN_IE_RF0LE_Get(x) \
    (((uint32_t) (x) &MCAN_IE_RF0LE_Msk) >> MCAN_IE_RF0LE_Pos) /*!< RF0LE Get Value            */


#define MCAN_IE_RF0FE_Pos (2U)                        /*!< RF0FE Postion   2          */
#define MCAN_IE_RF0FE_Msk (0x1U << MCAN_IE_RF0FE_Pos) /*!< RF0FE Mask      0x00000004 */
#define MCAN_IE_RF0FE_Set(x) \
    (((uint32_t) (x) << MCAN_IE_RF0FE_Pos) & MCAN_IE_RF0FE_Msk) /*!< RF0FE Set Value            */
#define MCAN_IE_RF0FE_Get(x) \
    (((uint32_t) (x) &MCAN_IE_RF0FE_Msk) >> MCAN_IE_RF0FE_Pos) /*!< RF0FE Get Value            */


#define MCAN_IE_RF0WE_Pos (1U)                        /*!< RF0WE Postion   1          */
#define MCAN_IE_RF0WE_Msk (0x1U << MCAN_IE_RF0WE_Pos) /*!< RF0WE Mask      0x00000002 */
#define MCAN_IE_RF0WE_Set(x) \
    (((uint32_t) (x) << MCAN_IE_RF0WE_Pos) & MCAN_IE_RF0WE_Msk) /*!< RF0WE Set Value            */
#define MCAN_IE_RF0WE_Get(x) \
    (((uint32_t) (x) &MCAN_IE_RF0WE_Msk) >> MCAN_IE_RF0WE_Pos) /*!< RF0WE Get Value            */


#define MCAN_IE_RF0NE_Pos (0U)                        /*!< RF0NE Postion   0          */
#define MCAN_IE_RF0NE_Msk (0x1U << MCAN_IE_RF0NE_Pos) /*!< RF0NE Mask      0x00000001 */
#define MCAN_IE_RF0NE_Set(x) \
    (((uint32_t) (x) << MCAN_IE_RF0NE_Pos) & MCAN_IE_RF0NE_Msk) /*!< RF0NE Set Value            */
#define MCAN_IE_RF0NE_Get(x) \
    (((uint32_t) (x) &MCAN_IE_RF0NE_Msk) >> MCAN_IE_RF0NE_Pos) /*!< RF0NE Get Value            */


/* ILS bitfield */
#define MCAN_ILS_ARAL_Pos (29U)                       /*!< ARAL Postion   29         */
#define MCAN_ILS_ARAL_Msk (0x1U << MCAN_ILS_ARAL_Pos) /*!< ARAL Mask      0x20000000 */
#define MCAN_ILS_ARAL_Set(x) \
    (((uint32_t) (x) << MCAN_ILS_ARAL_Pos) & MCAN_ILS_ARAL_Msk) /*!< ARAL Set Value            */
#define MCAN_ILS_ARAL_Get(x) \
    (((uint32_t) (x) &MCAN_ILS_ARAL_Msk) >> MCAN_ILS_ARAL_Pos) /*!< ARAL Get Value            */


#define MCAN_ILS_PEDL_Pos (28U)                       /*!< PEDL Postion   28         */
#define MCAN_ILS_PEDL_Msk (0x1U << MCAN_ILS_PEDL_Pos) /*!< PEDL Mask      0x10000000 */
#define MCAN_ILS_PEDL_Set(x) \
    (((uint32_t) (x) << MCAN_ILS_PEDL_Pos) & MCAN_ILS_PEDL_Msk) /*!< PEDL Set Value            */
#define MCAN_ILS_PEDL_Get(x) \
    (((uint32_t) (x) &MCAN_ILS_PEDL_Msk) >> MCAN_ILS_PEDL_Pos) /*!< PEDL Get Value            */


#define MCAN_ILS_PEAL_Pos (27U)                       /*!< PEAL Postion   27         */
#define MCAN_ILS_PEAL_Msk (0x1U << MCAN_ILS_PEAL_Pos) /*!< PEAL Mask      0x08000000 */
#define MCAN_ILS_PEAL_Set(x) \
    (((uint32_t) (x) << MCAN_ILS_PEAL_Pos) & MCAN_ILS_PEAL_Msk) /*!< PEAL Set Value            */
#define MCAN_ILS_PEAL_Get(x) \
    (((uint32_t) (x) &MCAN_ILS_PEAL_Msk) >> MCAN_ILS_PEAL_Pos) /*!< PEAL Get Value            */


#define MCAN_ILS_WDIL_Pos (26U)                       /*!< WDIL Postion   26         */
#define MCAN_ILS_WDIL_Msk (0x1U << MCAN_ILS_WDIL_Pos) /*!< WDIL Mask      0x04000000 */
#define MCAN_ILS_WDIL_Set(x) \
    (((uint32_t) (x) << MCAN_ILS_WDIL_Pos) & MCAN_ILS_WDIL_Msk) /*!< WDIL Set Value            */
#define MCAN_ILS_WDIL_Get(x) \
    (((uint32_t) (x) &MCAN_ILS_WDIL_Msk) >> MCAN_ILS_WDIL_Pos) /*!< WDIL Get Value            */


#define MCAN_ILS_BOL_Pos    (25U)                                                     /*!< BOL Postion   25         */
#define MCAN_ILS_BOL_Msk    (0x1U << MCAN_ILS_BOL_Pos)                                /*!< BOL Mask      0x02000000 */
#define MCAN_ILS_BOL_Set(x) (((uint32_t) (x) << MCAN_ILS_BOL_Pos) & MCAN_ILS_BOL_Msk) /*!< BOL Set Value            */
#define MCAN_ILS_BOL_Get(x) (((uint32_t) (x) &MCAN_ILS_BOL_Msk) >> MCAN_ILS_BOL_Pos)  /*!< BOL Get Value            */


#define MCAN_ILS_EWL_Pos    (24U)                                                     /*!< EWL Postion   24         */
#define MCAN_ILS_EWL_Msk    (0x1U << MCAN_ILS_EWL_Pos)                                /*!< EWL Mask      0x01000000 */
#define MCAN_ILS_EWL_Set(x) (((uint32_t) (x) << MCAN_ILS_EWL_Pos) & MCAN_ILS_EWL_Msk) /*!< EWL Set Value            */
#define MCAN_ILS_EWL_Get(x) (((uint32_t) (x) &MCAN_ILS_EWL_Msk) >> MCAN_ILS_EWL_Pos)  /*!< EWL Get Value            */


#define MCAN_ILS_EPL_Pos    (23U)                                                     /*!< EPL Postion   23         */
#define MCAN_ILS_EPL_Msk    (0x1U << MCAN_ILS_EPL_Pos)                                /*!< EPL Mask      0x00800000 */
#define MCAN_ILS_EPL_Set(x) (((uint32_t) (x) << MCAN_ILS_EPL_Pos) & MCAN_ILS_EPL_Msk) /*!< EPL Set Value            */
#define MCAN_ILS_EPL_Get(x) (((uint32_t) (x) &MCAN_ILS_EPL_Msk) >> MCAN_ILS_EPL_Pos)  /*!< EPL Get Value            */


#define MCAN_ILS_ELOL_Pos (22U)                       /*!< ELOL Postion   22         */
#define MCAN_ILS_ELOL_Msk (0x1U << MCAN_ILS_ELOL_Pos) /*!< ELOL Mask      0x00400000 */
#define MCAN_ILS_ELOL_Set(x) \
    (((uint32_t) (x) << MCAN_ILS_ELOL_Pos) & MCAN_ILS_ELOL_Msk) /*!< ELOL Set Value            */
#define MCAN_ILS_ELOL_Get(x) \
    (((uint32_t) (x) &MCAN_ILS_ELOL_Msk) >> MCAN_ILS_ELOL_Pos) /*!< ELOL Get Value            */


#define MCAN_ILS_BEUL_Pos (21U)                       /*!< BEUL Postion   21         */
#define MCAN_ILS_BEUL_Msk (0x1U << MCAN_ILS_BEUL_Pos) /*!< BEUL Mask      0x00200000 */
#define MCAN_ILS_BEUL_Set(x) \
    (((uint32_t) (x) << MCAN_ILS_BEUL_Pos) & MCAN_ILS_BEUL_Msk) /*!< BEUL Set Value            */
#define MCAN_ILS_BEUL_Get(x) \
    (((uint32_t) (x) &MCAN_ILS_BEUL_Msk) >> MCAN_ILS_BEUL_Pos) /*!< BEUL Get Value            */


#define MCAN_ILS_BECL_Pos (20U)                       /*!< BECL Postion   20         */
#define MCAN_ILS_BECL_Msk (0x1U << MCAN_ILS_BECL_Pos) /*!< BECL Mask      0x00100000 */
#define MCAN_ILS_BECL_Set(x) \
    (((uint32_t) (x) << MCAN_ILS_BECL_Pos) & MCAN_ILS_BECL_Msk) /*!< BECL Set Value            */
#define MCAN_ILS_BECL_Get(x) \
    (((uint32_t) (x) &MCAN_ILS_BECL_Msk) >> MCAN_ILS_BECL_Pos) /*!< BECL Get Value            */


#define MCAN_ILS_DRXL_Pos (19U)                       /*!< DRXL Postion   19         */
#define MCAN_ILS_DRXL_Msk (0x1U << MCAN_ILS_DRXL_Pos) /*!< DRXL Mask      0x00080000 */
#define MCAN_ILS_DRXL_Set(x) \
    (((uint32_t) (x) << MCAN_ILS_DRXL_Pos) & MCAN_ILS_DRXL_Msk) /*!< DRXL Set Value            */
#define MCAN_ILS_DRXL_Get(x) \
    (((uint32_t) (x) &MCAN_ILS_DRXL_Msk) >> MCAN_ILS_DRXL_Pos) /*!< DRXL Get Value            */


#define MCAN_ILS_TOOL_Pos (18U)                       /*!< TOOL Postion   18         */
#define MCAN_ILS_TOOL_Msk (0x1U << MCAN_ILS_TOOL_Pos) /*!< TOOL Mask      0x00040000 */
#define MCAN_ILS_TOOL_Set(x) \
    (((uint32_t) (x) << MCAN_ILS_TOOL_Pos) & MCAN_ILS_TOOL_Msk) /*!< TOOL Set Value            */
#define MCAN_ILS_TOOL_Get(x) \
    (((uint32_t) (x) &MCAN_ILS_TOOL_Msk) >> MCAN_ILS_TOOL_Pos) /*!< TOOL Get Value            */


#define MCAN_ILS_MRAFL_Pos (17U)                        /*!< MRAFL Postion   17         */
#define MCAN_ILS_MRAFL_Msk (0x1U << MCAN_ILS_MRAFL_Pos) /*!< MRAFL Mask      0x00020000 */
#define MCAN_ILS_MRAFL_Set(x) \
    (((uint32_t) (x) << MCAN_ILS_MRAFL_Pos) & MCAN_ILS_MRAFL_Msk) /*!< MRAFL Set Value            */
#define MCAN_ILS_MRAFL_Get(x) \
    (((uint32_t) (x) &MCAN_ILS_MRAFL_Msk) >> MCAN_ILS_MRAFL_Pos) /*!< MRAFL Get Value            */


#define MCAN_ILS_TSWL_Pos (16U)                       /*!< TSWL Postion   16         */
#define MCAN_ILS_TSWL_Msk (0x1U << MCAN_ILS_TSWL_Pos) /*!< TSWL Mask      0x00010000 */
#define MCAN_ILS_TSWL_Set(x) \
    (((uint32_t) (x) << MCAN_ILS_TSWL_Pos) & MCAN_ILS_TSWL_Msk) /*!< TSWL Set Value            */
#define MCAN_ILS_TSWL_Get(x) \
    (((uint32_t) (x) &MCAN_ILS_TSWL_Msk) >> MCAN_ILS_TSWL_Pos) /*!< TSWL Get Value            */


#define MCAN_ILS_TEFLL_Pos (15U)                        /*!< TEFLL Postion   15         */
#define MCAN_ILS_TEFLL_Msk (0x1U << MCAN_ILS_TEFLL_Pos) /*!< TEFLL Mask      0x00008000 */
#define MCAN_ILS_TEFLL_Set(x) \
    (((uint32_t) (x) << MCAN_ILS_TEFLL_Pos) & MCAN_ILS_TEFLL_Msk) /*!< TEFLL Set Value            */
#define MCAN_ILS_TEFLL_Get(x) \
    (((uint32_t) (x) &MCAN_ILS_TEFLL_Msk) >> MCAN_ILS_TEFLL_Pos) /*!< TEFLL Get Value            */


#define MCAN_ILS_TEFFL_Pos (14U)                        /*!< TEFFL Postion   14         */
#define MCAN_ILS_TEFFL_Msk (0x1U << MCAN_ILS_TEFFL_Pos) /*!< TEFFL Mask      0x00004000 */
#define MCAN_ILS_TEFFL_Set(x) \
    (((uint32_t) (x) << MCAN_ILS_TEFFL_Pos) & MCAN_ILS_TEFFL_Msk) /*!< TEFFL Set Value            */
#define MCAN_ILS_TEFFL_Get(x) \
    (((uint32_t) (x) &MCAN_ILS_TEFFL_Msk) >> MCAN_ILS_TEFFL_Pos) /*!< TEFFL Get Value            */


#define MCAN_ILS_TEFWL_Pos (13U)                        /*!< TEFWL Postion   13         */
#define MCAN_ILS_TEFWL_Msk (0x1U << MCAN_ILS_TEFWL_Pos) /*!< TEFWL Mask      0x00002000 */
#define MCAN_ILS_TEFWL_Set(x) \
    (((uint32_t) (x) << MCAN_ILS_TEFWL_Pos) & MCAN_ILS_TEFWL_Msk) /*!< TEFWL Set Value            */
#define MCAN_ILS_TEFWL_Get(x) \
    (((uint32_t) (x) &MCAN_ILS_TEFWL_Msk) >> MCAN_ILS_TEFWL_Pos) /*!< TEFWL Get Value            */


#define MCAN_ILS_TEFNL_Pos (12U)                        /*!< TEFNL Postion   12         */
#define MCAN_ILS_TEFNL_Msk (0x1U << MCAN_ILS_TEFNL_Pos) /*!< TEFNL Mask      0x00001000 */
#define MCAN_ILS_TEFNL_Set(x) \
    (((uint32_t) (x) << MCAN_ILS_TEFNL_Pos) & MCAN_ILS_TEFNL_Msk) /*!< TEFNL Set Value            */
#define MCAN_ILS_TEFNL_Get(x) \
    (((uint32_t) (x) &MCAN_ILS_TEFNL_Msk) >> MCAN_ILS_TEFNL_Pos) /*!< TEFNL Get Value            */


#define MCAN_ILS_TFEL_Pos (11U)                       /*!< TFEL Postion   11         */
#define MCAN_ILS_TFEL_Msk (0x1U << MCAN_ILS_TFEL_Pos) /*!< TFEL Mask      0x00000800 */
#define MCAN_ILS_TFEL_Set(x) \
    (((uint32_t) (x) << MCAN_ILS_TFEL_Pos) & MCAN_ILS_TFEL_Msk) /*!< TFEL Set Value            */
#define MCAN_ILS_TFEL_Get(x) \
    (((uint32_t) (x) &MCAN_ILS_TFEL_Msk) >> MCAN_ILS_TFEL_Pos) /*!< TFEL Get Value            */


#define MCAN_ILS_TCFL_Pos (10U)                       /*!< TCFL Postion   10         */
#define MCAN_ILS_TCFL_Msk (0x1U << MCAN_ILS_TCFL_Pos) /*!< TCFL Mask      0x00000400 */
#define MCAN_ILS_TCFL_Set(x) \
    (((uint32_t) (x) << MCAN_ILS_TCFL_Pos) & MCAN_ILS_TCFL_Msk) /*!< TCFL Set Value            */
#define MCAN_ILS_TCFL_Get(x) \
    (((uint32_t) (x) &MCAN_ILS_TCFL_Msk) >> MCAN_ILS_TCFL_Pos) /*!< TCFL Get Value            */


#define MCAN_ILS_TCL_Pos    (9U)                                                      /*!< TCL Postion   9          */
#define MCAN_ILS_TCL_Msk    (0x1U << MCAN_ILS_TCL_Pos)                                /*!< TCL Mask      0x00000200 */
#define MCAN_ILS_TCL_Set(x) (((uint32_t) (x) << MCAN_ILS_TCL_Pos) & MCAN_ILS_TCL_Msk) /*!< TCL Set Value            */
#define MCAN_ILS_TCL_Get(x) (((uint32_t) (x) &MCAN_ILS_TCL_Msk) >> MCAN_ILS_TCL_Pos)  /*!< TCL Get Value            */


#define MCAN_ILS_HPML_Pos (8U)                        /*!< HPML Postion   8          */
#define MCAN_ILS_HPML_Msk (0x1U << MCAN_ILS_HPML_Pos) /*!< HPML Mask      0x00000100 */
#define MCAN_ILS_HPML_Set(x) \
    (((uint32_t) (x) << MCAN_ILS_HPML_Pos) & MCAN_ILS_HPML_Msk) /*!< HPML Set Value            */
#define MCAN_ILS_HPML_Get(x) \
    (((uint32_t) (x) &MCAN_ILS_HPML_Msk) >> MCAN_ILS_HPML_Pos) /*!< HPML Get Value            */


#define MCAN_ILS_RF1LL_Pos (7U)                         /*!< RF1LL Postion   7          */
#define MCAN_ILS_RF1LL_Msk (0x1U << MCAN_ILS_RF1LL_Pos) /*!< RF1LL Mask      0x00000080 */
#define MCAN_ILS_RF1LL_Set(x) \
    (((uint32_t) (x) << MCAN_ILS_RF1LL_Pos) & MCAN_ILS_RF1LL_Msk) /*!< RF1LL Set Value            */
#define MCAN_ILS_RF1LL_Get(x) \
    (((uint32_t) (x) &MCAN_ILS_RF1LL_Msk) >> MCAN_ILS_RF1LL_Pos) /*!< RF1LL Get Value            */


#define MCAN_ILS_RF1FL_Pos (6U)                         /*!< RF1FL Postion   6          */
#define MCAN_ILS_RF1FL_Msk (0x1U << MCAN_ILS_RF1FL_Pos) /*!< RF1FL Mask      0x00000040 */
#define MCAN_ILS_RF1FL_Set(x) \
    (((uint32_t) (x) << MCAN_ILS_RF1FL_Pos) & MCAN_ILS_RF1FL_Msk) /*!< RF1FL Set Value            */
#define MCAN_ILS_RF1FL_Get(x) \
    (((uint32_t) (x) &MCAN_ILS_RF1FL_Msk) >> MCAN_ILS_RF1FL_Pos) /*!< RF1FL Get Value            */


#define MCAN_ILS_RF1WL_Pos (5U)                         /*!< RF1WL Postion   5          */
#define MCAN_ILS_RF1WL_Msk (0x1U << MCAN_ILS_RF1WL_Pos) /*!< RF1WL Mask      0x00000020 */
#define MCAN_ILS_RF1WL_Set(x) \
    (((uint32_t) (x) << MCAN_ILS_RF1WL_Pos) & MCAN_ILS_RF1WL_Msk) /*!< RF1WL Set Value            */
#define MCAN_ILS_RF1WL_Get(x) \
    (((uint32_t) (x) &MCAN_ILS_RF1WL_Msk) >> MCAN_ILS_RF1WL_Pos) /*!< RF1WL Get Value            */


#define MCAN_ILS_RF1NL_Pos (4U)                         /*!< RF1NL Postion   4          */
#define MCAN_ILS_RF1NL_Msk (0x1U << MCAN_ILS_RF1NL_Pos) /*!< RF1NL Mask      0x00000010 */
#define MCAN_ILS_RF1NL_Set(x) \
    (((uint32_t) (x) << MCAN_ILS_RF1NL_Pos) & MCAN_ILS_RF1NL_Msk) /*!< RF1NL Set Value            */
#define MCAN_ILS_RF1NL_Get(x) \
    (((uint32_t) (x) &MCAN_ILS_RF1NL_Msk) >> MCAN_ILS_RF1NL_Pos) /*!< RF1NL Get Value            */


#define MCAN_ILS_RF0LL_Pos (3U)                         /*!< RF0LL Postion   3          */
#define MCAN_ILS_RF0LL_Msk (0x1U << MCAN_ILS_RF0LL_Pos) /*!< RF0LL Mask      0x00000008 */
#define MCAN_ILS_RF0LL_Set(x) \
    (((uint32_t) (x) << MCAN_ILS_RF0LL_Pos) & MCAN_ILS_RF0LL_Msk) /*!< RF0LL Set Value            */
#define MCAN_ILS_RF0LL_Get(x) \
    (((uint32_t) (x) &MCAN_ILS_RF0LL_Msk) >> MCAN_ILS_RF0LL_Pos) /*!< RF0LL Get Value            */


#define MCAN_ILS_RF0FL_Pos (2U)                         /*!< RF0FL Postion   2          */
#define MCAN_ILS_RF0FL_Msk (0x1U << MCAN_ILS_RF0FL_Pos) /*!< RF0FL Mask      0x00000004 */
#define MCAN_ILS_RF0FL_Set(x) \
    (((uint32_t) (x) << MCAN_ILS_RF0FL_Pos) & MCAN_ILS_RF0FL_Msk) /*!< RF0FL Set Value            */
#define MCAN_ILS_RF0FL_Get(x) \
    (((uint32_t) (x) &MCAN_ILS_RF0FL_Msk) >> MCAN_ILS_RF0FL_Pos) /*!< RF0FL Get Value            */


#define MCAN_ILS_RF0WL_Pos (1U)                         /*!< RF0WL Postion   1          */
#define MCAN_ILS_RF0WL_Msk (0x1U << MCAN_ILS_RF0WL_Pos) /*!< RF0WL Mask      0x00000002 */
#define MCAN_ILS_RF0WL_Set(x) \
    (((uint32_t) (x) << MCAN_ILS_RF0WL_Pos) & MCAN_ILS_RF0WL_Msk) /*!< RF0WL Set Value            */
#define MCAN_ILS_RF0WL_Get(x) \
    (((uint32_t) (x) &MCAN_ILS_RF0WL_Msk) >> MCAN_ILS_RF0WL_Pos) /*!< RF0WL Get Value            */


#define MCAN_ILS_RF0NL_Pos (0U)                         /*!< RF0NL Postion   0          */
#define MCAN_ILS_RF0NL_Msk (0x1U << MCAN_ILS_RF0NL_Pos) /*!< RF0NL Mask      0x00000001 */
#define MCAN_ILS_RF0NL_Set(x) \
    (((uint32_t) (x) << MCAN_ILS_RF0NL_Pos) & MCAN_ILS_RF0NL_Msk) /*!< RF0NL Set Value            */
#define MCAN_ILS_RF0NL_Get(x) \
    (((uint32_t) (x) &MCAN_ILS_RF0NL_Msk) >> MCAN_ILS_RF0NL_Pos) /*!< RF0NL Get Value            */


/* ILE bitfield */
#define MCAN_ILE_EINT1_Pos (1U)                         /*!< EINT1 Postion   1          */
#define MCAN_ILE_EINT1_Msk (0x1U << MCAN_ILE_EINT1_Pos) /*!< EINT1 Mask      0x00000002 */
#define MCAN_ILE_EINT1_Set(x) \
    (((uint32_t) (x) << MCAN_ILE_EINT1_Pos) & MCAN_ILE_EINT1_Msk) /*!< EINT1 Set Value            */
#define MCAN_ILE_EINT1_Get(x) \
    (((uint32_t) (x) &MCAN_ILE_EINT1_Msk) >> MCAN_ILE_EINT1_Pos) /*!< EINT1 Get Value            */


#define MCAN_ILE_EINT0_Pos (0U)                         /*!< EINT0 Postion   0          */
#define MCAN_ILE_EINT0_Msk (0x1U << MCAN_ILE_EINT0_Pos) /*!< EINT0 Mask      0x00000001 */
#define MCAN_ILE_EINT0_Set(x) \
    (((uint32_t) (x) << MCAN_ILE_EINT0_Pos) & MCAN_ILE_EINT0_Msk) /*!< EINT0 Set Value            */
#define MCAN_ILE_EINT0_Get(x) \
    (((uint32_t) (x) &MCAN_ILE_EINT0_Msk) >> MCAN_ILE_EINT0_Pos) /*!< EINT0 Get Value            */


/* GFC bitfield */
#define MCAN_GFC_ANFS_Pos (4U)                        /*!< ANFS Postion   4          */
#define MCAN_GFC_ANFS_Msk (0x3U << MCAN_GFC_ANFS_Pos) /*!< ANFS Mask      0x00000030 */
#define MCAN_GFC_ANFS_Set(x) \
    (((uint32_t) (x) << MCAN_GFC_ANFS_Pos) & MCAN_GFC_ANFS_Msk) /*!< ANFS Set Value            */
#define MCAN_GFC_ANFS_Get(x) \
    (((uint32_t) (x) &MCAN_GFC_ANFS_Msk) >> MCAN_GFC_ANFS_Pos) /*!< ANFS Get Value            */


#define MCAN_GFC_ANFE_Pos (2U)                        /*!< ANFE Postion   2          */
#define MCAN_GFC_ANFE_Msk (0x3U << MCAN_GFC_ANFE_Pos) /*!< ANFE Mask      0x0000000C */
#define MCAN_GFC_ANFE_Set(x) \
    (((uint32_t) (x) << MCAN_GFC_ANFE_Pos) & MCAN_GFC_ANFE_Msk) /*!< ANFE Set Value            */
#define MCAN_GFC_ANFE_Get(x) \
    (((uint32_t) (x) &MCAN_GFC_ANFE_Msk) >> MCAN_GFC_ANFE_Pos) /*!< ANFE Get Value            */


#define MCAN_GFC_RRFS_Pos (1U)                        /*!< RRFS Postion   1          */
#define MCAN_GFC_RRFS_Msk (0x1U << MCAN_GFC_RRFS_Pos) /*!< RRFS Mask      0x00000002 */
#define MCAN_GFC_RRFS_Set(x) \
    (((uint32_t) (x) << MCAN_GFC_RRFS_Pos) & MCAN_GFC_RRFS_Msk) /*!< RRFS Set Value            */
#define MCAN_GFC_RRFS_Get(x) \
    (((uint32_t) (x) &MCAN_GFC_RRFS_Msk) >> MCAN_GFC_RRFS_Pos) /*!< RRFS Get Value            */


#define MCAN_GFC_RRFE_Pos (0U)                        /*!< RRFE Postion   0          */
#define MCAN_GFC_RRFE_Msk (0x1U << MCAN_GFC_RRFE_Pos) /*!< RRFE Mask      0x00000001 */
#define MCAN_GFC_RRFE_Set(x) \
    (((uint32_t) (x) << MCAN_GFC_RRFE_Pos) & MCAN_GFC_RRFE_Msk) /*!< RRFE Set Value            */
#define MCAN_GFC_RRFE_Get(x) \
    (((uint32_t) (x) &MCAN_GFC_RRFE_Msk) >> MCAN_GFC_RRFE_Pos) /*!< RRFE Get Value            */


/* SIDFC bitfield */
#define MCAN_SIDFC_LSS_Pos (16U)                         /*!< LSS Postion   16         */
#define MCAN_SIDFC_LSS_Msk (0xffU << MCAN_SIDFC_LSS_Pos) /*!< LSS Mask      0x00FF0000 */
#define MCAN_SIDFC_LSS_Set(x) \
    (((uint32_t) (x) << MCAN_SIDFC_LSS_Pos) & MCAN_SIDFC_LSS_Msk) /*!< LSS Set Value            */
#define MCAN_SIDFC_LSS_Get(x) \
    (((uint32_t) (x) &MCAN_SIDFC_LSS_Msk) >> MCAN_SIDFC_LSS_Pos) /*!< LSS Get Value            */


#define MCAN_SIDFC_FLSSA_Pos (2U)                              /*!< FLSSA Postion   2          */
#define MCAN_SIDFC_FLSSA_Msk (0x3fffU << MCAN_SIDFC_FLSSA_Pos) /*!< FLSSA Mask      0x0000FFFC */
#define MCAN_SIDFC_FLSSA_Set(x) \
    (((uint32_t) (x) << MCAN_SIDFC_FLSSA_Pos) & MCAN_SIDFC_FLSSA_Msk) /*!< FLSSA Set Value            */
#define MCAN_SIDFC_FLSSA_Get(x) \
    (((uint32_t) (x) &MCAN_SIDFC_FLSSA_Msk) >> MCAN_SIDFC_FLSSA_Pos) /*!< FLSSA Get Value            */


/* XIDFC bitfield */
#define MCAN_XIDFC_LSE_Pos (16U)                         /*!< LSE Postion   16         */
#define MCAN_XIDFC_LSE_Msk (0x7fU << MCAN_XIDFC_LSE_Pos) /*!< LSE Mask      0x007F0000 */
#define MCAN_XIDFC_LSE_Set(x) \
    (((uint32_t) (x) << MCAN_XIDFC_LSE_Pos) & MCAN_XIDFC_LSE_Msk) /*!< LSE Set Value            */
#define MCAN_XIDFC_LSE_Get(x) \
    (((uint32_t) (x) &MCAN_XIDFC_LSE_Msk) >> MCAN_XIDFC_LSE_Pos) /*!< LSE Get Value            */


#define MCAN_XIDFC_FLESA_Pos (2U)                              /*!< FLESA Postion   2          */
#define MCAN_XIDFC_FLESA_Msk (0x3fffU << MCAN_XIDFC_FLESA_Pos) /*!< FLESA Mask      0x0000FFFC */
#define MCAN_XIDFC_FLESA_Set(x) \
    (((uint32_t) (x) << MCAN_XIDFC_FLESA_Pos) & MCAN_XIDFC_FLESA_Msk) /*!< FLESA Set Value            */
#define MCAN_XIDFC_FLESA_Get(x) \
    (((uint32_t) (x) &MCAN_XIDFC_FLESA_Msk) >> MCAN_XIDFC_FLESA_Pos) /*!< FLESA Get Value            */


/* XIDAM bitfield */
#define MCAN_XIDAM_EIDM_Pos (0U)                                 /*!< EIDM Postion   0          */
#define MCAN_XIDAM_EIDM_Msk (0x1fffffffU << MCAN_XIDAM_EIDM_Pos) /*!< EIDM Mask      0x1FFFFFFF */
#define MCAN_XIDAM_EIDM_Set(x) \
    (((uint32_t) (x) << MCAN_XIDAM_EIDM_Pos) & MCAN_XIDAM_EIDM_Msk) /*!< EIDM Set Value            */
#define MCAN_XIDAM_EIDM_Get(x) \
    (((uint32_t) (x) &MCAN_XIDAM_EIDM_Msk) >> MCAN_XIDAM_EIDM_Pos) /*!< EIDM Get Value            */


/* HPMS bitfield */
#define MCAN_HPMS_FLST_Pos (15U)                        /*!< FLST Postion   15         */
#define MCAN_HPMS_FLST_Msk (0x1U << MCAN_HPMS_FLST_Pos) /*!< FLST Mask      0x00008000 */
#define MCAN_HPMS_FLST_Set(x) \
    (((uint32_t) (x) << MCAN_HPMS_FLST_Pos) & MCAN_HPMS_FLST_Msk) /*!< FLST Set Value            */
#define MCAN_HPMS_FLST_Get(x) \
    (((uint32_t) (x) &MCAN_HPMS_FLST_Msk) >> MCAN_HPMS_FLST_Pos) /*!< FLST Get Value            */


#define MCAN_HPMS_FIDX_Pos (8U)                          /*!< FIDX Postion   8          */
#define MCAN_HPMS_FIDX_Msk (0x7fU << MCAN_HPMS_FIDX_Pos) /*!< FIDX Mask      0x00007F00 */
#define MCAN_HPMS_FIDX_Set(x) \
    (((uint32_t) (x) << MCAN_HPMS_FIDX_Pos) & MCAN_HPMS_FIDX_Msk) /*!< FIDX Set Value            */
#define MCAN_HPMS_FIDX_Get(x) \
    (((uint32_t) (x) &MCAN_HPMS_FIDX_Msk) >> MCAN_HPMS_FIDX_Pos) /*!< FIDX Get Value            */


#define MCAN_HPMS_MSI_Pos (6U)                        /*!< MSI Postion   6          */
#define MCAN_HPMS_MSI_Msk (0x3U << MCAN_HPMS_MSI_Pos) /*!< MSI Mask      0x000000C0 */
#define MCAN_HPMS_MSI_Set(x) \
    (((uint32_t) (x) << MCAN_HPMS_MSI_Pos) & MCAN_HPMS_MSI_Msk)                         /*!< MSI Set Value            */
#define MCAN_HPMS_MSI_Get(x) (((uint32_t) (x) &MCAN_HPMS_MSI_Msk) >> MCAN_HPMS_MSI_Pos) /*!< MSI Get Value */


#define MCAN_HPMS_BIDX_Pos (0U)                          /*!< BIDX Postion   0          */
#define MCAN_HPMS_BIDX_Msk (0x3fU << MCAN_HPMS_BIDX_Pos) /*!< BIDX Mask      0x0000003F */
#define MCAN_HPMS_BIDX_Set(x) \
    (((uint32_t) (x) << MCAN_HPMS_BIDX_Pos) & MCAN_HPMS_BIDX_Msk) /*!< BIDX Set Value            */
#define MCAN_HPMS_BIDX_Get(x) \
    (((uint32_t) (x) &MCAN_HPMS_BIDX_Msk) >> MCAN_HPMS_BIDX_Pos) /*!< BIDX Get Value            */


/* NDAT1 bitfield */
#define MCAN_NDAT1_ND31_Pos (31U)                         /*!< ND31 Postion   31         */
#define MCAN_NDAT1_ND31_Msk (0x1U << MCAN_NDAT1_ND31_Pos) /*!< ND31 Mask      0x80000000 */
#define MCAN_NDAT1_ND31_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT1_ND31_Pos) & MCAN_NDAT1_ND31_Msk) /*!< ND31 Set Value            */
#define MCAN_NDAT1_ND31_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT1_ND31_Msk) >> MCAN_NDAT1_ND31_Pos) /*!< ND31 Get Value            */


#define MCAN_NDAT1_ND30_Pos (30U)                         /*!< ND30 Postion   30         */
#define MCAN_NDAT1_ND30_Msk (0x1U << MCAN_NDAT1_ND30_Pos) /*!< ND30 Mask      0x40000000 */
#define MCAN_NDAT1_ND30_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT1_ND30_Pos) & MCAN_NDAT1_ND30_Msk) /*!< ND30 Set Value            */
#define MCAN_NDAT1_ND30_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT1_ND30_Msk) >> MCAN_NDAT1_ND30_Pos) /*!< ND30 Get Value            */


#define MCAN_NDAT1_ND29_Pos (29U)                         /*!< ND29 Postion   29         */
#define MCAN_NDAT1_ND29_Msk (0x1U << MCAN_NDAT1_ND29_Pos) /*!< ND29 Mask      0x20000000 */
#define MCAN_NDAT1_ND29_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT1_ND29_Pos) & MCAN_NDAT1_ND29_Msk) /*!< ND29 Set Value            */
#define MCAN_NDAT1_ND29_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT1_ND29_Msk) >> MCAN_NDAT1_ND29_Pos) /*!< ND29 Get Value            */


#define MCAN_NDAT1_ND28_Pos (28U)                         /*!< ND28 Postion   28         */
#define MCAN_NDAT1_ND28_Msk (0x1U << MCAN_NDAT1_ND28_Pos) /*!< ND28 Mask      0x10000000 */
#define MCAN_NDAT1_ND28_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT1_ND28_Pos) & MCAN_NDAT1_ND28_Msk) /*!< ND28 Set Value            */
#define MCAN_NDAT1_ND28_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT1_ND28_Msk) >> MCAN_NDAT1_ND28_Pos) /*!< ND28 Get Value            */


#define MCAN_NDAT1_ND27_Pos (27U)                         /*!< ND27 Postion   27         */
#define MCAN_NDAT1_ND27_Msk (0x1U << MCAN_NDAT1_ND27_Pos) /*!< ND27 Mask      0x08000000 */
#define MCAN_NDAT1_ND27_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT1_ND27_Pos) & MCAN_NDAT1_ND27_Msk) /*!< ND27 Set Value            */
#define MCAN_NDAT1_ND27_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT1_ND27_Msk) >> MCAN_NDAT1_ND27_Pos) /*!< ND27 Get Value            */


#define MCAN_NDAT1_ND26_Pos (26U)                         /*!< ND26 Postion   26         */
#define MCAN_NDAT1_ND26_Msk (0x1U << MCAN_NDAT1_ND26_Pos) /*!< ND26 Mask      0x04000000 */
#define MCAN_NDAT1_ND26_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT1_ND26_Pos) & MCAN_NDAT1_ND26_Msk) /*!< ND26 Set Value            */
#define MCAN_NDAT1_ND26_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT1_ND26_Msk) >> MCAN_NDAT1_ND26_Pos) /*!< ND26 Get Value            */


#define MCAN_NDAT1_ND25_Pos (25U)                         /*!< ND25 Postion   25         */
#define MCAN_NDAT1_ND25_Msk (0x1U << MCAN_NDAT1_ND25_Pos) /*!< ND25 Mask      0x02000000 */
#define MCAN_NDAT1_ND25_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT1_ND25_Pos) & MCAN_NDAT1_ND25_Msk) /*!< ND25 Set Value            */
#define MCAN_NDAT1_ND25_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT1_ND25_Msk) >> MCAN_NDAT1_ND25_Pos) /*!< ND25 Get Value            */


#define MCAN_NDAT1_ND24_Pos (24U)                         /*!< ND24 Postion   24         */
#define MCAN_NDAT1_ND24_Msk (0x1U << MCAN_NDAT1_ND24_Pos) /*!< ND24 Mask      0x01000000 */
#define MCAN_NDAT1_ND24_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT1_ND24_Pos) & MCAN_NDAT1_ND24_Msk) /*!< ND24 Set Value            */
#define MCAN_NDAT1_ND24_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT1_ND24_Msk) >> MCAN_NDAT1_ND24_Pos) /*!< ND24 Get Value            */


#define MCAN_NDAT1_ND23_Pos (23U)                         /*!< ND23 Postion   23         */
#define MCAN_NDAT1_ND23_Msk (0x1U << MCAN_NDAT1_ND23_Pos) /*!< ND23 Mask      0x00800000 */
#define MCAN_NDAT1_ND23_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT1_ND23_Pos) & MCAN_NDAT1_ND23_Msk) /*!< ND23 Set Value            */
#define MCAN_NDAT1_ND23_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT1_ND23_Msk) >> MCAN_NDAT1_ND23_Pos) /*!< ND23 Get Value            */


#define MCAN_NDAT1_ND22_Pos (22U)                         /*!< ND22 Postion   22         */
#define MCAN_NDAT1_ND22_Msk (0x1U << MCAN_NDAT1_ND22_Pos) /*!< ND22 Mask      0x00400000 */
#define MCAN_NDAT1_ND22_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT1_ND22_Pos) & MCAN_NDAT1_ND22_Msk) /*!< ND22 Set Value            */
#define MCAN_NDAT1_ND22_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT1_ND22_Msk) >> MCAN_NDAT1_ND22_Pos) /*!< ND22 Get Value            */


#define MCAN_NDAT1_ND21_Pos (21U)                         /*!< ND21 Postion   21         */
#define MCAN_NDAT1_ND21_Msk (0x1U << MCAN_NDAT1_ND21_Pos) /*!< ND21 Mask      0x00200000 */
#define MCAN_NDAT1_ND21_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT1_ND21_Pos) & MCAN_NDAT1_ND21_Msk) /*!< ND21 Set Value            */
#define MCAN_NDAT1_ND21_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT1_ND21_Msk) >> MCAN_NDAT1_ND21_Pos) /*!< ND21 Get Value            */


#define MCAN_NDAT1_ND20_Pos (20U)                         /*!< ND20 Postion   20         */
#define MCAN_NDAT1_ND20_Msk (0x1U << MCAN_NDAT1_ND20_Pos) /*!< ND20 Mask      0x00100000 */
#define MCAN_NDAT1_ND20_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT1_ND20_Pos) & MCAN_NDAT1_ND20_Msk) /*!< ND20 Set Value            */
#define MCAN_NDAT1_ND20_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT1_ND20_Msk) >> MCAN_NDAT1_ND20_Pos) /*!< ND20 Get Value            */


#define MCAN_NDAT1_ND19_Pos (19U)                         /*!< ND19 Postion   19         */
#define MCAN_NDAT1_ND19_Msk (0x1U << MCAN_NDAT1_ND19_Pos) /*!< ND19 Mask      0x00080000 */
#define MCAN_NDAT1_ND19_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT1_ND19_Pos) & MCAN_NDAT1_ND19_Msk) /*!< ND19 Set Value            */
#define MCAN_NDAT1_ND19_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT1_ND19_Msk) >> MCAN_NDAT1_ND19_Pos) /*!< ND19 Get Value            */


#define MCAN_NDAT1_ND18_Pos (18U)                         /*!< ND18 Postion   18         */
#define MCAN_NDAT1_ND18_Msk (0x1U << MCAN_NDAT1_ND18_Pos) /*!< ND18 Mask      0x00040000 */
#define MCAN_NDAT1_ND18_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT1_ND18_Pos) & MCAN_NDAT1_ND18_Msk) /*!< ND18 Set Value            */
#define MCAN_NDAT1_ND18_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT1_ND18_Msk) >> MCAN_NDAT1_ND18_Pos) /*!< ND18 Get Value            */


#define MCAN_NDAT1_ND17_Pos (17U)                         /*!< ND17 Postion   17         */
#define MCAN_NDAT1_ND17_Msk (0x1U << MCAN_NDAT1_ND17_Pos) /*!< ND17 Mask      0x00020000 */
#define MCAN_NDAT1_ND17_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT1_ND17_Pos) & MCAN_NDAT1_ND17_Msk) /*!< ND17 Set Value            */
#define MCAN_NDAT1_ND17_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT1_ND17_Msk) >> MCAN_NDAT1_ND17_Pos) /*!< ND17 Get Value            */


#define MCAN_NDAT1_ND16_Pos (16U)                         /*!< ND16 Postion   16         */
#define MCAN_NDAT1_ND16_Msk (0x1U << MCAN_NDAT1_ND16_Pos) /*!< ND16 Mask      0x00010000 */
#define MCAN_NDAT1_ND16_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT1_ND16_Pos) & MCAN_NDAT1_ND16_Msk) /*!< ND16 Set Value            */
#define MCAN_NDAT1_ND16_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT1_ND16_Msk) >> MCAN_NDAT1_ND16_Pos) /*!< ND16 Get Value            */


#define MCAN_NDAT1_ND15_Pos (15U)                         /*!< ND15 Postion   15         */
#define MCAN_NDAT1_ND15_Msk (0x1U << MCAN_NDAT1_ND15_Pos) /*!< ND15 Mask      0x00008000 */
#define MCAN_NDAT1_ND15_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT1_ND15_Pos) & MCAN_NDAT1_ND15_Msk) /*!< ND15 Set Value            */
#define MCAN_NDAT1_ND15_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT1_ND15_Msk) >> MCAN_NDAT1_ND15_Pos) /*!< ND15 Get Value            */


#define MCAN_NDAT1_ND14_Pos (14U)                         /*!< ND14 Postion   14         */
#define MCAN_NDAT1_ND14_Msk (0x1U << MCAN_NDAT1_ND14_Pos) /*!< ND14 Mask      0x00004000 */
#define MCAN_NDAT1_ND14_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT1_ND14_Pos) & MCAN_NDAT1_ND14_Msk) /*!< ND14 Set Value            */
#define MCAN_NDAT1_ND14_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT1_ND14_Msk) >> MCAN_NDAT1_ND14_Pos) /*!< ND14 Get Value            */


#define MCAN_NDAT1_ND13_Pos (13U)                         /*!< ND13 Postion   13         */
#define MCAN_NDAT1_ND13_Msk (0x1U << MCAN_NDAT1_ND13_Pos) /*!< ND13 Mask      0x00002000 */
#define MCAN_NDAT1_ND13_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT1_ND13_Pos) & MCAN_NDAT1_ND13_Msk) /*!< ND13 Set Value            */
#define MCAN_NDAT1_ND13_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT1_ND13_Msk) >> MCAN_NDAT1_ND13_Pos) /*!< ND13 Get Value            */


#define MCAN_NDAT1_ND12_Pos (12U)                         /*!< ND12 Postion   12         */
#define MCAN_NDAT1_ND12_Msk (0x1U << MCAN_NDAT1_ND12_Pos) /*!< ND12 Mask      0x00001000 */
#define MCAN_NDAT1_ND12_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT1_ND12_Pos) & MCAN_NDAT1_ND12_Msk) /*!< ND12 Set Value            */
#define MCAN_NDAT1_ND12_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT1_ND12_Msk) >> MCAN_NDAT1_ND12_Pos) /*!< ND12 Get Value            */


#define MCAN_NDAT1_ND11_Pos (11U)                         /*!< ND11 Postion   11         */
#define MCAN_NDAT1_ND11_Msk (0x1U << MCAN_NDAT1_ND11_Pos) /*!< ND11 Mask      0x00000800 */
#define MCAN_NDAT1_ND11_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT1_ND11_Pos) & MCAN_NDAT1_ND11_Msk) /*!< ND11 Set Value            */
#define MCAN_NDAT1_ND11_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT1_ND11_Msk) >> MCAN_NDAT1_ND11_Pos) /*!< ND11 Get Value            */


#define MCAN_NDAT1_ND10_Pos (10U)                         /*!< ND10 Postion   10         */
#define MCAN_NDAT1_ND10_Msk (0x1U << MCAN_NDAT1_ND10_Pos) /*!< ND10 Mask      0x00000400 */
#define MCAN_NDAT1_ND10_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT1_ND10_Pos) & MCAN_NDAT1_ND10_Msk) /*!< ND10 Set Value            */
#define MCAN_NDAT1_ND10_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT1_ND10_Msk) >> MCAN_NDAT1_ND10_Pos) /*!< ND10 Get Value            */


#define MCAN_NDAT1_ND9_Pos (9U)                         /*!< ND9 Postion   9          */
#define MCAN_NDAT1_ND9_Msk (0x1U << MCAN_NDAT1_ND9_Pos) /*!< ND9 Mask      0x00000200 */
#define MCAN_NDAT1_ND9_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT1_ND9_Pos) & MCAN_NDAT1_ND9_Msk) /*!< ND9 Set Value            */
#define MCAN_NDAT1_ND9_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT1_ND9_Msk) >> MCAN_NDAT1_ND9_Pos) /*!< ND9 Get Value            */


#define MCAN_NDAT1_ND8_Pos (8U)                         /*!< ND8 Postion   8          */
#define MCAN_NDAT1_ND8_Msk (0x1U << MCAN_NDAT1_ND8_Pos) /*!< ND8 Mask      0x00000100 */
#define MCAN_NDAT1_ND8_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT1_ND8_Pos) & MCAN_NDAT1_ND8_Msk) /*!< ND8 Set Value            */
#define MCAN_NDAT1_ND8_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT1_ND8_Msk) >> MCAN_NDAT1_ND8_Pos) /*!< ND8 Get Value            */


#define MCAN_NDAT1_ND7_Pos (7U)                         /*!< ND7 Postion   7          */
#define MCAN_NDAT1_ND7_Msk (0x1U << MCAN_NDAT1_ND7_Pos) /*!< ND7 Mask      0x00000080 */
#define MCAN_NDAT1_ND7_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT1_ND7_Pos) & MCAN_NDAT1_ND7_Msk) /*!< ND7 Set Value            */
#define MCAN_NDAT1_ND7_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT1_ND7_Msk) >> MCAN_NDAT1_ND7_Pos) /*!< ND7 Get Value            */


#define MCAN_NDAT1_ND6_Pos (6U)                         /*!< ND6 Postion   6          */
#define MCAN_NDAT1_ND6_Msk (0x1U << MCAN_NDAT1_ND6_Pos) /*!< ND6 Mask      0x00000040 */
#define MCAN_NDAT1_ND6_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT1_ND6_Pos) & MCAN_NDAT1_ND6_Msk) /*!< ND6 Set Value            */
#define MCAN_NDAT1_ND6_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT1_ND6_Msk) >> MCAN_NDAT1_ND6_Pos) /*!< ND6 Get Value            */


#define MCAN_NDAT1_ND5_Pos (5U)                         /*!< ND5 Postion   5          */
#define MCAN_NDAT1_ND5_Msk (0x1U << MCAN_NDAT1_ND5_Pos) /*!< ND5 Mask      0x00000020 */
#define MCAN_NDAT1_ND5_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT1_ND5_Pos) & MCAN_NDAT1_ND5_Msk) /*!< ND5 Set Value            */
#define MCAN_NDAT1_ND5_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT1_ND5_Msk) >> MCAN_NDAT1_ND5_Pos) /*!< ND5 Get Value            */


#define MCAN_NDAT1_ND4_Pos (4U)                         /*!< ND4 Postion   4          */
#define MCAN_NDAT1_ND4_Msk (0x1U << MCAN_NDAT1_ND4_Pos) /*!< ND4 Mask      0x00000010 */
#define MCAN_NDAT1_ND4_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT1_ND4_Pos) & MCAN_NDAT1_ND4_Msk) /*!< ND4 Set Value            */
#define MCAN_NDAT1_ND4_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT1_ND4_Msk) >> MCAN_NDAT1_ND4_Pos) /*!< ND4 Get Value            */


#define MCAN_NDAT1_ND3_Pos (3U)                         /*!< ND3 Postion   3          */
#define MCAN_NDAT1_ND3_Msk (0x1U << MCAN_NDAT1_ND3_Pos) /*!< ND3 Mask      0x00000008 */
#define MCAN_NDAT1_ND3_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT1_ND3_Pos) & MCAN_NDAT1_ND3_Msk) /*!< ND3 Set Value            */
#define MCAN_NDAT1_ND3_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT1_ND3_Msk) >> MCAN_NDAT1_ND3_Pos) /*!< ND3 Get Value            */


#define MCAN_NDAT1_ND2_Pos (2U)                         /*!< ND2 Postion   2          */
#define MCAN_NDAT1_ND2_Msk (0x1U << MCAN_NDAT1_ND2_Pos) /*!< ND2 Mask      0x00000004 */
#define MCAN_NDAT1_ND2_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT1_ND2_Pos) & MCAN_NDAT1_ND2_Msk) /*!< ND2 Set Value            */
#define MCAN_NDAT1_ND2_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT1_ND2_Msk) >> MCAN_NDAT1_ND2_Pos) /*!< ND2 Get Value            */


#define MCAN_NDAT1_ND1_Pos (1U)                         /*!< ND1 Postion   1          */
#define MCAN_NDAT1_ND1_Msk (0x1U << MCAN_NDAT1_ND1_Pos) /*!< ND1 Mask      0x00000002 */
#define MCAN_NDAT1_ND1_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT1_ND1_Pos) & MCAN_NDAT1_ND1_Msk) /*!< ND1 Set Value            */
#define MCAN_NDAT1_ND1_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT1_ND1_Msk) >> MCAN_NDAT1_ND1_Pos) /*!< ND1 Get Value            */


#define MCAN_NDAT1_ND0_Pos (0U)                         /*!< ND0 Postion   0          */
#define MCAN_NDAT1_ND0_Msk (0x1U << MCAN_NDAT1_ND0_Pos) /*!< ND0 Mask      0x00000001 */
#define MCAN_NDAT1_ND0_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT1_ND0_Pos) & MCAN_NDAT1_ND0_Msk) /*!< ND0 Set Value            */
#define MCAN_NDAT1_ND0_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT1_ND0_Msk) >> MCAN_NDAT1_ND0_Pos) /*!< ND0 Get Value            */


/* NDAT2 bitfield */
#define MCAN_NDAT2_ND63_Pos (31U)                         /*!< ND63 Postion   31         */
#define MCAN_NDAT2_ND63_Msk (0x1U << MCAN_NDAT2_ND63_Pos) /*!< ND63 Mask      0x80000000 */
#define MCAN_NDAT2_ND63_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT2_ND63_Pos) & MCAN_NDAT2_ND63_Msk) /*!< ND63 Set Value            */
#define MCAN_NDAT2_ND63_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT2_ND63_Msk) >> MCAN_NDAT2_ND63_Pos) /*!< ND63 Get Value            */


#define MCAN_NDAT2_ND62_Pos (30U)                         /*!< ND62 Postion   30         */
#define MCAN_NDAT2_ND62_Msk (0x1U << MCAN_NDAT2_ND62_Pos) /*!< ND62 Mask      0x40000000 */
#define MCAN_NDAT2_ND62_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT2_ND62_Pos) & MCAN_NDAT2_ND62_Msk) /*!< ND62 Set Value            */
#define MCAN_NDAT2_ND62_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT2_ND62_Msk) >> MCAN_NDAT2_ND62_Pos) /*!< ND62 Get Value            */


#define MCAN_NDAT2_ND61_Pos (29U)                         /*!< ND61 Postion   29         */
#define MCAN_NDAT2_ND61_Msk (0x1U << MCAN_NDAT2_ND61_Pos) /*!< ND61 Mask      0x20000000 */
#define MCAN_NDAT2_ND61_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT2_ND61_Pos) & MCAN_NDAT2_ND61_Msk) /*!< ND61 Set Value            */
#define MCAN_NDAT2_ND61_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT2_ND61_Msk) >> MCAN_NDAT2_ND61_Pos) /*!< ND61 Get Value            */


#define MCAN_NDAT2_ND60_Pos (28U)                         /*!< ND60 Postion   28         */
#define MCAN_NDAT2_ND60_Msk (0x1U << MCAN_NDAT2_ND60_Pos) /*!< ND60 Mask      0x10000000 */
#define MCAN_NDAT2_ND60_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT2_ND60_Pos) & MCAN_NDAT2_ND60_Msk) /*!< ND60 Set Value            */
#define MCAN_NDAT2_ND60_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT2_ND60_Msk) >> MCAN_NDAT2_ND60_Pos) /*!< ND60 Get Value            */


#define MCAN_NDAT2_ND59_Pos (27U)                         /*!< ND59 Postion   27         */
#define MCAN_NDAT2_ND59_Msk (0x1U << MCAN_NDAT2_ND59_Pos) /*!< ND59 Mask      0x08000000 */
#define MCAN_NDAT2_ND59_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT2_ND59_Pos) & MCAN_NDAT2_ND59_Msk) /*!< ND59 Set Value            */
#define MCAN_NDAT2_ND59_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT2_ND59_Msk) >> MCAN_NDAT2_ND59_Pos) /*!< ND59 Get Value            */


#define MCAN_NDAT2_ND58_Pos (26U)                         /*!< ND58 Postion   26         */
#define MCAN_NDAT2_ND58_Msk (0x1U << MCAN_NDAT2_ND58_Pos) /*!< ND58 Mask      0x04000000 */
#define MCAN_NDAT2_ND58_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT2_ND58_Pos) & MCAN_NDAT2_ND58_Msk) /*!< ND58 Set Value            */
#define MCAN_NDAT2_ND58_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT2_ND58_Msk) >> MCAN_NDAT2_ND58_Pos) /*!< ND58 Get Value            */


#define MCAN_NDAT2_ND57_Pos (25U)                         /*!< ND57 Postion   25         */
#define MCAN_NDAT2_ND57_Msk (0x1U << MCAN_NDAT2_ND57_Pos) /*!< ND57 Mask      0x02000000 */
#define MCAN_NDAT2_ND57_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT2_ND57_Pos) & MCAN_NDAT2_ND57_Msk) /*!< ND57 Set Value            */
#define MCAN_NDAT2_ND57_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT2_ND57_Msk) >> MCAN_NDAT2_ND57_Pos) /*!< ND57 Get Value            */


#define MCAN_NDAT2_ND56_Pos (24U)                         /*!< ND56 Postion   24         */
#define MCAN_NDAT2_ND56_Msk (0x1U << MCAN_NDAT2_ND56_Pos) /*!< ND56 Mask      0x01000000 */
#define MCAN_NDAT2_ND56_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT2_ND56_Pos) & MCAN_NDAT2_ND56_Msk) /*!< ND56 Set Value            */
#define MCAN_NDAT2_ND56_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT2_ND56_Msk) >> MCAN_NDAT2_ND56_Pos) /*!< ND56 Get Value            */


#define MCAN_NDAT2_ND55_Pos (23U)                         /*!< ND55 Postion   23         */
#define MCAN_NDAT2_ND55_Msk (0x1U << MCAN_NDAT2_ND55_Pos) /*!< ND55 Mask      0x00800000 */
#define MCAN_NDAT2_ND55_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT2_ND55_Pos) & MCAN_NDAT2_ND55_Msk) /*!< ND55 Set Value            */
#define MCAN_NDAT2_ND55_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT2_ND55_Msk) >> MCAN_NDAT2_ND55_Pos) /*!< ND55 Get Value            */


#define MCAN_NDAT2_ND54_Pos (22U)                         /*!< ND54 Postion   22         */
#define MCAN_NDAT2_ND54_Msk (0x1U << MCAN_NDAT2_ND54_Pos) /*!< ND54 Mask      0x00400000 */
#define MCAN_NDAT2_ND54_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT2_ND54_Pos) & MCAN_NDAT2_ND54_Msk) /*!< ND54 Set Value            */
#define MCAN_NDAT2_ND54_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT2_ND54_Msk) >> MCAN_NDAT2_ND54_Pos) /*!< ND54 Get Value            */


#define MCAN_NDAT2_ND53_Pos (21U)                         /*!< ND53 Postion   21         */
#define MCAN_NDAT2_ND53_Msk (0x1U << MCAN_NDAT2_ND53_Pos) /*!< ND53 Mask      0x00200000 */
#define MCAN_NDAT2_ND53_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT2_ND53_Pos) & MCAN_NDAT2_ND53_Msk) /*!< ND53 Set Value            */
#define MCAN_NDAT2_ND53_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT2_ND53_Msk) >> MCAN_NDAT2_ND53_Pos) /*!< ND53 Get Value            */


#define MCAN_NDAT2_ND52_Pos (20U)                         /*!< ND52 Postion   20         */
#define MCAN_NDAT2_ND52_Msk (0x1U << MCAN_NDAT2_ND52_Pos) /*!< ND52 Mask      0x00100000 */
#define MCAN_NDAT2_ND52_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT2_ND52_Pos) & MCAN_NDAT2_ND52_Msk) /*!< ND52 Set Value            */
#define MCAN_NDAT2_ND52_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT2_ND52_Msk) >> MCAN_NDAT2_ND52_Pos) /*!< ND52 Get Value            */


#define MCAN_NDAT2_ND51_Pos (19U)                         /*!< ND51 Postion   19         */
#define MCAN_NDAT2_ND51_Msk (0x1U << MCAN_NDAT2_ND51_Pos) /*!< ND51 Mask      0x00080000 */
#define MCAN_NDAT2_ND51_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT2_ND51_Pos) & MCAN_NDAT2_ND51_Msk) /*!< ND51 Set Value            */
#define MCAN_NDAT2_ND51_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT2_ND51_Msk) >> MCAN_NDAT2_ND51_Pos) /*!< ND51 Get Value            */


#define MCAN_NDAT2_ND50_Pos (18U)                         /*!< ND50 Postion   18         */
#define MCAN_NDAT2_ND50_Msk (0x1U << MCAN_NDAT2_ND50_Pos) /*!< ND50 Mask      0x00040000 */
#define MCAN_NDAT2_ND50_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT2_ND50_Pos) & MCAN_NDAT2_ND50_Msk) /*!< ND50 Set Value            */
#define MCAN_NDAT2_ND50_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT2_ND50_Msk) >> MCAN_NDAT2_ND50_Pos) /*!< ND50 Get Value            */


#define MCAN_NDAT2_ND49_Pos (17U)                         /*!< ND49 Postion   17         */
#define MCAN_NDAT2_ND49_Msk (0x1U << MCAN_NDAT2_ND49_Pos) /*!< ND49 Mask      0x00020000 */
#define MCAN_NDAT2_ND49_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT2_ND49_Pos) & MCAN_NDAT2_ND49_Msk) /*!< ND49 Set Value            */
#define MCAN_NDAT2_ND49_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT2_ND49_Msk) >> MCAN_NDAT2_ND49_Pos) /*!< ND49 Get Value            */


#define MCAN_NDAT2_ND48_Pos (16U)                         /*!< ND48 Postion   16         */
#define MCAN_NDAT2_ND48_Msk (0x1U << MCAN_NDAT2_ND48_Pos) /*!< ND48 Mask      0x00010000 */
#define MCAN_NDAT2_ND48_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT2_ND48_Pos) & MCAN_NDAT2_ND48_Msk) /*!< ND48 Set Value            */
#define MCAN_NDAT2_ND48_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT2_ND48_Msk) >> MCAN_NDAT2_ND48_Pos) /*!< ND48 Get Value            */


#define MCAN_NDAT2_ND47_Pos (15U)                         /*!< ND47 Postion   15         */
#define MCAN_NDAT2_ND47_Msk (0x1U << MCAN_NDAT2_ND47_Pos) /*!< ND47 Mask      0x00008000 */
#define MCAN_NDAT2_ND47_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT2_ND47_Pos) & MCAN_NDAT2_ND47_Msk) /*!< ND47 Set Value            */
#define MCAN_NDAT2_ND47_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT2_ND47_Msk) >> MCAN_NDAT2_ND47_Pos) /*!< ND47 Get Value            */


#define MCAN_NDAT2_ND46_Pos (14U)                         /*!< ND46 Postion   14         */
#define MCAN_NDAT2_ND46_Msk (0x1U << MCAN_NDAT2_ND46_Pos) /*!< ND46 Mask      0x00004000 */
#define MCAN_NDAT2_ND46_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT2_ND46_Pos) & MCAN_NDAT2_ND46_Msk) /*!< ND46 Set Value            */
#define MCAN_NDAT2_ND46_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT2_ND46_Msk) >> MCAN_NDAT2_ND46_Pos) /*!< ND46 Get Value            */


#define MCAN_NDAT2_ND45_Pos (13U)                         /*!< ND45 Postion   13         */
#define MCAN_NDAT2_ND45_Msk (0x1U << MCAN_NDAT2_ND45_Pos) /*!< ND45 Mask      0x00002000 */
#define MCAN_NDAT2_ND45_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT2_ND45_Pos) & MCAN_NDAT2_ND45_Msk) /*!< ND45 Set Value            */
#define MCAN_NDAT2_ND45_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT2_ND45_Msk) >> MCAN_NDAT2_ND45_Pos) /*!< ND45 Get Value            */


#define MCAN_NDAT2_ND44_Pos (12U)                         /*!< ND44 Postion   12         */
#define MCAN_NDAT2_ND44_Msk (0x1U << MCAN_NDAT2_ND44_Pos) /*!< ND44 Mask      0x00001000 */
#define MCAN_NDAT2_ND44_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT2_ND44_Pos) & MCAN_NDAT2_ND44_Msk) /*!< ND44 Set Value            */
#define MCAN_NDAT2_ND44_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT2_ND44_Msk) >> MCAN_NDAT2_ND44_Pos) /*!< ND44 Get Value            */


#define MCAN_NDAT2_ND43_Pos (11U)                         /*!< ND43 Postion   11         */
#define MCAN_NDAT2_ND43_Msk (0x1U << MCAN_NDAT2_ND43_Pos) /*!< ND43 Mask      0x00000800 */
#define MCAN_NDAT2_ND43_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT2_ND43_Pos) & MCAN_NDAT2_ND43_Msk) /*!< ND43 Set Value            */
#define MCAN_NDAT2_ND43_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT2_ND43_Msk) >> MCAN_NDAT2_ND43_Pos) /*!< ND43 Get Value            */


#define MCAN_NDAT2_ND42_Pos (10U)                         /*!< ND42 Postion   10         */
#define MCAN_NDAT2_ND42_Msk (0x1U << MCAN_NDAT2_ND42_Pos) /*!< ND42 Mask      0x00000400 */
#define MCAN_NDAT2_ND42_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT2_ND42_Pos) & MCAN_NDAT2_ND42_Msk) /*!< ND42 Set Value            */
#define MCAN_NDAT2_ND42_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT2_ND42_Msk) >> MCAN_NDAT2_ND42_Pos) /*!< ND42 Get Value            */


#define MCAN_NDAT2_ND41_Pos (9U)                          /*!< ND41 Postion   9          */
#define MCAN_NDAT2_ND41_Msk (0x1U << MCAN_NDAT2_ND41_Pos) /*!< ND41 Mask      0x00000200 */
#define MCAN_NDAT2_ND41_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT2_ND41_Pos) & MCAN_NDAT2_ND41_Msk) /*!< ND41 Set Value            */
#define MCAN_NDAT2_ND41_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT2_ND41_Msk) >> MCAN_NDAT2_ND41_Pos) /*!< ND41 Get Value            */


#define MCAN_NDAT2_ND40_Pos (8U)                          /*!< ND40 Postion   8          */
#define MCAN_NDAT2_ND40_Msk (0x1U << MCAN_NDAT2_ND40_Pos) /*!< ND40 Mask      0x00000100 */
#define MCAN_NDAT2_ND40_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT2_ND40_Pos) & MCAN_NDAT2_ND40_Msk) /*!< ND40 Set Value            */
#define MCAN_NDAT2_ND40_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT2_ND40_Msk) >> MCAN_NDAT2_ND40_Pos) /*!< ND40 Get Value            */


#define MCAN_NDAT2_ND39_Pos (7U)                          /*!< ND39 Postion   7          */
#define MCAN_NDAT2_ND39_Msk (0x1U << MCAN_NDAT2_ND39_Pos) /*!< ND39 Mask      0x00000080 */
#define MCAN_NDAT2_ND39_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT2_ND39_Pos) & MCAN_NDAT2_ND39_Msk) /*!< ND39 Set Value            */
#define MCAN_NDAT2_ND39_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT2_ND39_Msk) >> MCAN_NDAT2_ND39_Pos) /*!< ND39 Get Value            */


#define MCAN_NDAT2_ND38_Pos (6U)                          /*!< ND38 Postion   6          */
#define MCAN_NDAT2_ND38_Msk (0x1U << MCAN_NDAT2_ND38_Pos) /*!< ND38 Mask      0x00000040 */
#define MCAN_NDAT2_ND38_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT2_ND38_Pos) & MCAN_NDAT2_ND38_Msk) /*!< ND38 Set Value            */
#define MCAN_NDAT2_ND38_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT2_ND38_Msk) >> MCAN_NDAT2_ND38_Pos) /*!< ND38 Get Value            */


#define MCAN_NDAT2_ND37_Pos (5U)                          /*!< ND37 Postion   5          */
#define MCAN_NDAT2_ND37_Msk (0x1U << MCAN_NDAT2_ND37_Pos) /*!< ND37 Mask      0x00000020 */
#define MCAN_NDAT2_ND37_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT2_ND37_Pos) & MCAN_NDAT2_ND37_Msk) /*!< ND37 Set Value            */
#define MCAN_NDAT2_ND37_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT2_ND37_Msk) >> MCAN_NDAT2_ND37_Pos) /*!< ND37 Get Value            */


#define MCAN_NDAT2_ND36_Pos (4U)                          /*!< ND36 Postion   4          */
#define MCAN_NDAT2_ND36_Msk (0x1U << MCAN_NDAT2_ND36_Pos) /*!< ND36 Mask      0x00000010 */
#define MCAN_NDAT2_ND36_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT2_ND36_Pos) & MCAN_NDAT2_ND36_Msk) /*!< ND36 Set Value            */
#define MCAN_NDAT2_ND36_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT2_ND36_Msk) >> MCAN_NDAT2_ND36_Pos) /*!< ND36 Get Value            */


#define MCAN_NDAT2_ND35_Pos (3U)                          /*!< ND35 Postion   3          */
#define MCAN_NDAT2_ND35_Msk (0x1U << MCAN_NDAT2_ND35_Pos) /*!< ND35 Mask      0x00000008 */
#define MCAN_NDAT2_ND35_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT2_ND35_Pos) & MCAN_NDAT2_ND35_Msk) /*!< ND35 Set Value            */
#define MCAN_NDAT2_ND35_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT2_ND35_Msk) >> MCAN_NDAT2_ND35_Pos) /*!< ND35 Get Value            */


#define MCAN_NDAT2_ND34_Pos (2U)                          /*!< ND34 Postion   2          */
#define MCAN_NDAT2_ND34_Msk (0x1U << MCAN_NDAT2_ND34_Pos) /*!< ND34 Mask      0x00000004 */
#define MCAN_NDAT2_ND34_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT2_ND34_Pos) & MCAN_NDAT2_ND34_Msk) /*!< ND34 Set Value            */
#define MCAN_NDAT2_ND34_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT2_ND34_Msk) >> MCAN_NDAT2_ND34_Pos) /*!< ND34 Get Value            */


#define MCAN_NDAT2_ND33_Pos (1U)                          /*!< ND33 Postion   1          */
#define MCAN_NDAT2_ND33_Msk (0x1U << MCAN_NDAT2_ND33_Pos) /*!< ND33 Mask      0x00000002 */
#define MCAN_NDAT2_ND33_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT2_ND33_Pos) & MCAN_NDAT2_ND33_Msk) /*!< ND33 Set Value            */
#define MCAN_NDAT2_ND33_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT2_ND33_Msk) >> MCAN_NDAT2_ND33_Pos) /*!< ND33 Get Value            */


#define MCAN_NDAT2_ND32_Pos (0U)                          /*!< ND32 Postion   0          */
#define MCAN_NDAT2_ND32_Msk (0x1U << MCAN_NDAT2_ND32_Pos) /*!< ND32 Mask      0x00000001 */
#define MCAN_NDAT2_ND32_Set(x) \
    (((uint32_t) (x) << MCAN_NDAT2_ND32_Pos) & MCAN_NDAT2_ND32_Msk) /*!< ND32 Set Value            */
#define MCAN_NDAT2_ND32_Get(x) \
    (((uint32_t) (x) &MCAN_NDAT2_ND32_Msk) >> MCAN_NDAT2_ND32_Pos) /*!< ND32 Get Value            */


/* RXF0C bitfield */
#define MCAN_RXF0C_F0OM_Pos (31U)                         /*!< F0OM Postion   31         */
#define MCAN_RXF0C_F0OM_Msk (0x1U << MCAN_RXF0C_F0OM_Pos) /*!< F0OM Mask      0x80000000 */
#define MCAN_RXF0C_F0OM_Set(x) \
    (((uint32_t) (x) << MCAN_RXF0C_F0OM_Pos) & MCAN_RXF0C_F0OM_Msk) /*!< F0OM Set Value            */
#define MCAN_RXF0C_F0OM_Get(x) \
    (((uint32_t) (x) &MCAN_RXF0C_F0OM_Msk) >> MCAN_RXF0C_F0OM_Pos) /*!< F0OM Get Value            */


#define MCAN_RXF0C_F0WM_Pos (24U)                          /*!< F0WM Postion   24         */
#define MCAN_RXF0C_F0WM_Msk (0x7fU << MCAN_RXF0C_F0WM_Pos) /*!< F0WM Mask      0x7F000000 */
#define MCAN_RXF0C_F0WM_Set(x) \
    (((uint32_t) (x) << MCAN_RXF0C_F0WM_Pos) & MCAN_RXF0C_F0WM_Msk) /*!< F0WM Set Value            */
#define MCAN_RXF0C_F0WM_Get(x) \
    (((uint32_t) (x) &MCAN_RXF0C_F0WM_Msk) >> MCAN_RXF0C_F0WM_Pos) /*!< F0WM Get Value            */


#define MCAN_RXF0C_F0S_Pos (16U)                         /*!< F0S Postion   16         */
#define MCAN_RXF0C_F0S_Msk (0x7fU << MCAN_RXF0C_F0S_Pos) /*!< F0S Mask      0x007F0000 */
#define MCAN_RXF0C_F0S_Set(x) \
    (((uint32_t) (x) << MCAN_RXF0C_F0S_Pos) & MCAN_RXF0C_F0S_Msk) /*!< F0S Set Value            */
#define MCAN_RXF0C_F0S_Get(x) \
    (((uint32_t) (x) &MCAN_RXF0C_F0S_Msk) >> MCAN_RXF0C_F0S_Pos) /*!< F0S Get Value            */


#define MCAN_RXF0C_F0SA_Pos (2U)                             /*!< F0SA Postion   2          */
#define MCAN_RXF0C_F0SA_Msk (0x3fffU << MCAN_RXF0C_F0SA_Pos) /*!< F0SA Mask      0x0000FFFC */
#define MCAN_RXF0C_F0SA_Set(x) \
    (((uint32_t) (x) << MCAN_RXF0C_F0SA_Pos) & MCAN_RXF0C_F0SA_Msk) /*!< F0SA Set Value            */
#define MCAN_RXF0C_F0SA_Get(x) \
    (((uint32_t) (x) &MCAN_RXF0C_F0SA_Msk) >> MCAN_RXF0C_F0SA_Pos) /*!< F0SA Get Value            */


/* RXF0S bitfield */
#define MCAN_RXF0S_RF0L_Pos (25U)                         /*!< RF0L Postion   25         */
#define MCAN_RXF0S_RF0L_Msk (0x1U << MCAN_RXF0S_RF0L_Pos) /*!< RF0L Mask      0x02000000 */
#define MCAN_RXF0S_RF0L_Set(x) \
    (((uint32_t) (x) << MCAN_RXF0S_RF0L_Pos) & MCAN_RXF0S_RF0L_Msk) /*!< RF0L Set Value            */
#define MCAN_RXF0S_RF0L_Get(x) \
    (((uint32_t) (x) &MCAN_RXF0S_RF0L_Msk) >> MCAN_RXF0S_RF0L_Pos) /*!< RF0L Get Value            */


#define MCAN_RXF0S_F0F_Pos (24U)                        /*!< F0F Postion   24         */
#define MCAN_RXF0S_F0F_Msk (0x1U << MCAN_RXF0S_F0F_Pos) /*!< F0F Mask      0x01000000 */
#define MCAN_RXF0S_F0F_Set(x) \
    (((uint32_t) (x) << MCAN_RXF0S_F0F_Pos) & MCAN_RXF0S_F0F_Msk) /*!< F0F Set Value            */
#define MCAN_RXF0S_F0F_Get(x) \
    (((uint32_t) (x) &MCAN_RXF0S_F0F_Msk) >> MCAN_RXF0S_F0F_Pos) /*!< F0F Get Value            */


#define MCAN_RXF0S_F0PI_Pos (16U)                          /*!< F0PI Postion   16         */
#define MCAN_RXF0S_F0PI_Msk (0x3fU << MCAN_RXF0S_F0PI_Pos) /*!< F0PI Mask      0x003F0000 */
#define MCAN_RXF0S_F0PI_Set(x) \
    (((uint32_t) (x) << MCAN_RXF0S_F0PI_Pos) & MCAN_RXF0S_F0PI_Msk) /*!< F0PI Set Value            */
#define MCAN_RXF0S_F0PI_Get(x) \
    (((uint32_t) (x) &MCAN_RXF0S_F0PI_Msk) >> MCAN_RXF0S_F0PI_Pos) /*!< F0PI Get Value            */


#define MCAN_RXF0S_F0GI_Pos (8U)                           /*!< F0GI Postion   8          */
#define MCAN_RXF0S_F0GI_Msk (0x3fU << MCAN_RXF0S_F0GI_Pos) /*!< F0GI Mask      0x00003F00 */
#define MCAN_RXF0S_F0GI_Set(x) \
    (((uint32_t) (x) << MCAN_RXF0S_F0GI_Pos) & MCAN_RXF0S_F0GI_Msk) /*!< F0GI Set Value            */
#define MCAN_RXF0S_F0GI_Get(x) \
    (((uint32_t) (x) &MCAN_RXF0S_F0GI_Msk) >> MCAN_RXF0S_F0GI_Pos) /*!< F0GI Get Value            */


#define MCAN_RXF0S_F0FL_Pos (0U)                           /*!< F0FL Postion   0          */
#define MCAN_RXF0S_F0FL_Msk (0x7fU << MCAN_RXF0S_F0FL_Pos) /*!< F0FL Mask      0x0000007F */
#define MCAN_RXF0S_F0FL_Set(x) \
    (((uint32_t) (x) << MCAN_RXF0S_F0FL_Pos) & MCAN_RXF0S_F0FL_Msk) /*!< F0FL Set Value            */
#define MCAN_RXF0S_F0FL_Get(x) \
    (((uint32_t) (x) &MCAN_RXF0S_F0FL_Msk) >> MCAN_RXF0S_F0FL_Pos) /*!< F0FL Get Value            */


/* RXF0A bitfield */
#define MCAN_RXF0A_F0AI_Pos (0U)                           /*!< F0AI Postion   0          */
#define MCAN_RXF0A_F0AI_Msk (0x3fU << MCAN_RXF0A_F0AI_Pos) /*!< F0AI Mask      0x0000003F */
#define MCAN_RXF0A_F0AI_Set(x) \
    (((uint32_t) (x) << MCAN_RXF0A_F0AI_Pos) & MCAN_RXF0A_F0AI_Msk) /*!< F0AI Set Value            */
#define MCAN_RXF0A_F0AI_Get(x) \
    (((uint32_t) (x) &MCAN_RXF0A_F0AI_Msk) >> MCAN_RXF0A_F0AI_Pos) /*!< F0AI Get Value            */


/* RXBC bitfield */
#define MCAN_RXBC_RBSA_Pos (2U)                            /*!< RBSA Postion   2          */
#define MCAN_RXBC_RBSA_Msk (0x3fffU << MCAN_RXBC_RBSA_Pos) /*!< RBSA Mask      0x0000FFFC */
#define MCAN_RXBC_RBSA_Set(x) \
    (((uint32_t) (x) << MCAN_RXBC_RBSA_Pos) & MCAN_RXBC_RBSA_Msk) /*!< RBSA Set Value            */
#define MCAN_RXBC_RBSA_Get(x) \
    (((uint32_t) (x) &MCAN_RXBC_RBSA_Msk) >> MCAN_RXBC_RBSA_Pos) /*!< RBSA Get Value            */


/* RXF1C bitfield */
#define MCAN_RXF1C_F1OM_Pos (31U)                         /*!< F1OM Postion   31         */
#define MCAN_RXF1C_F1OM_Msk (0x1U << MCAN_RXF1C_F1OM_Pos) /*!< F1OM Mask      0x80000000 */
#define MCAN_RXF1C_F1OM_Set(x) \
    (((uint32_t) (x) << MCAN_RXF1C_F1OM_Pos) & MCAN_RXF1C_F1OM_Msk) /*!< F1OM Set Value            */
#define MCAN_RXF1C_F1OM_Get(x) \
    (((uint32_t) (x) &MCAN_RXF1C_F1OM_Msk) >> MCAN_RXF1C_F1OM_Pos) /*!< F1OM Get Value            */


#define MCAN_RXF1C_F1WM_Pos (24U)                          /*!< F1WM Postion   24         */
#define MCAN_RXF1C_F1WM_Msk (0x7fU << MCAN_RXF1C_F1WM_Pos) /*!< F1WM Mask      0x7F000000 */
#define MCAN_RXF1C_F1WM_Set(x) \
    (((uint32_t) (x) << MCAN_RXF1C_F1WM_Pos) & MCAN_RXF1C_F1WM_Msk) /*!< F1WM Set Value            */
#define MCAN_RXF1C_F1WM_Get(x) \
    (((uint32_t) (x) &MCAN_RXF1C_F1WM_Msk) >> MCAN_RXF1C_F1WM_Pos) /*!< F1WM Get Value            */


#define MCAN_RXF1C_F1S_Pos (16U)                         /*!< F1S Postion   16         */
#define MCAN_RXF1C_F1S_Msk (0x7fU << MCAN_RXF1C_F1S_Pos) /*!< F1S Mask      0x007F0000 */
#define MCAN_RXF1C_F1S_Set(x) \
    (((uint32_t) (x) << MCAN_RXF1C_F1S_Pos) & MCAN_RXF1C_F1S_Msk) /*!< F1S Set Value            */
#define MCAN_RXF1C_F1S_Get(x) \
    (((uint32_t) (x) &MCAN_RXF1C_F1S_Msk) >> MCAN_RXF1C_F1S_Pos) /*!< F1S Get Value            */


#define MCAN_RXF1C_F1SA_Pos (2U)                             /*!< F1SA Postion   2          */
#define MCAN_RXF1C_F1SA_Msk (0x3fffU << MCAN_RXF1C_F1SA_Pos) /*!< F1SA Mask      0x0000FFFC */
#define MCAN_RXF1C_F1SA_Set(x) \
    (((uint32_t) (x) << MCAN_RXF1C_F1SA_Pos) & MCAN_RXF1C_F1SA_Msk) /*!< F1SA Set Value            */
#define MCAN_RXF1C_F1SA_Get(x) \
    (((uint32_t) (x) &MCAN_RXF1C_F1SA_Msk) >> MCAN_RXF1C_F1SA_Pos) /*!< F1SA Get Value            */


/* RXF1S bitfield */
#define MCAN_RXF1S_DMS_Pos (30U)                        /*!< DMS Postion   30         */
#define MCAN_RXF1S_DMS_Msk (0x3U << MCAN_RXF1S_DMS_Pos) /*!< DMS Mask      0xC0000000 */
#define MCAN_RXF1S_DMS_Set(x) \
    (((uint32_t) (x) << MCAN_RXF1S_DMS_Pos) & MCAN_RXF1S_DMS_Msk) /*!< DMS Set Value            */
#define MCAN_RXF1S_DMS_Get(x) \
    (((uint32_t) (x) &MCAN_RXF1S_DMS_Msk) >> MCAN_RXF1S_DMS_Pos) /*!< DMS Get Value            */


#define MCAN_RXF1S_RF1L_Pos (25U)                         /*!< RF1L Postion   25         */
#define MCAN_RXF1S_RF1L_Msk (0x1U << MCAN_RXF1S_RF1L_Pos) /*!< RF1L Mask      0x02000000 */
#define MCAN_RXF1S_RF1L_Set(x) \
    (((uint32_t) (x) << MCAN_RXF1S_RF1L_Pos) & MCAN_RXF1S_RF1L_Msk) /*!< RF1L Set Value            */
#define MCAN_RXF1S_RF1L_Get(x) \
    (((uint32_t) (x) &MCAN_RXF1S_RF1L_Msk) >> MCAN_RXF1S_RF1L_Pos) /*!< RF1L Get Value            */


#define MCAN_RXF1S_F1F_Pos (24U)                        /*!< F1F Postion   24         */
#define MCAN_RXF1S_F1F_Msk (0x1U << MCAN_RXF1S_F1F_Pos) /*!< F1F Mask      0x01000000 */
#define MCAN_RXF1S_F1F_Set(x) \
    (((uint32_t) (x) << MCAN_RXF1S_F1F_Pos) & MCAN_RXF1S_F1F_Msk) /*!< F1F Set Value            */
#define MCAN_RXF1S_F1F_Get(x) \
    (((uint32_t) (x) &MCAN_RXF1S_F1F_Msk) >> MCAN_RXF1S_F1F_Pos) /*!< F1F Get Value            */


#define MCAN_RXF1S_F1PI_Pos (16U)                          /*!< F1PI Postion   16         */
#define MCAN_RXF1S_F1PI_Msk (0x3fU << MCAN_RXF1S_F1PI_Pos) /*!< F1PI Mask      0x003F0000 */
#define MCAN_RXF1S_F1PI_Set(x) \
    (((uint32_t) (x) << MCAN_RXF1S_F1PI_Pos) & MCAN_RXF1S_F1PI_Msk) /*!< F1PI Set Value            */
#define MCAN_RXF1S_F1PI_Get(x) \
    (((uint32_t) (x) &MCAN_RXF1S_F1PI_Msk) >> MCAN_RXF1S_F1PI_Pos) /*!< F1PI Get Value            */


#define MCAN_RXF1S_F1GI_Pos (8U)                           /*!< F1GI Postion   8          */
#define MCAN_RXF1S_F1GI_Msk (0x3fU << MCAN_RXF1S_F1GI_Pos) /*!< F1GI Mask      0x00003F00 */
#define MCAN_RXF1S_F1GI_Set(x) \
    (((uint32_t) (x) << MCAN_RXF1S_F1GI_Pos) & MCAN_RXF1S_F1GI_Msk) /*!< F1GI Set Value            */
#define MCAN_RXF1S_F1GI_Get(x) \
    (((uint32_t) (x) &MCAN_RXF1S_F1GI_Msk) >> MCAN_RXF1S_F1GI_Pos) /*!< F1GI Get Value            */


#define MCAN_RXF1S_F1FL_Pos (0U)                           /*!< F1FL Postion   0          */
#define MCAN_RXF1S_F1FL_Msk (0x7fU << MCAN_RXF1S_F1FL_Pos) /*!< F1FL Mask      0x0000007F */
#define MCAN_RXF1S_F1FL_Set(x) \
    (((uint32_t) (x) << MCAN_RXF1S_F1FL_Pos) & MCAN_RXF1S_F1FL_Msk) /*!< F1FL Set Value            */
#define MCAN_RXF1S_F1FL_Get(x) \
    (((uint32_t) (x) &MCAN_RXF1S_F1FL_Msk) >> MCAN_RXF1S_F1FL_Pos) /*!< F1FL Get Value            */


/* RXF1A bitfield */
#define MCAN_RXF1A_F1AI_Pos (0U)                           /*!< F1AI Postion   0          */
#define MCAN_RXF1A_F1AI_Msk (0x3fU << MCAN_RXF1A_F1AI_Pos) /*!< F1AI Mask      0x0000003F */
#define MCAN_RXF1A_F1AI_Set(x) \
    (((uint32_t) (x) << MCAN_RXF1A_F1AI_Pos) & MCAN_RXF1A_F1AI_Msk) /*!< F1AI Set Value            */
#define MCAN_RXF1A_F1AI_Get(x) \
    (((uint32_t) (x) &MCAN_RXF1A_F1AI_Msk) >> MCAN_RXF1A_F1AI_Pos) /*!< F1AI Get Value            */


/* RXESC bitfield */
#define MCAN_RXESC_RBDS_Pos (8U)                          /*!< RBDS Postion   8          */
#define MCAN_RXESC_RBDS_Msk (0x7U << MCAN_RXESC_RBDS_Pos) /*!< RBDS Mask      0x00000700 */
#define MCAN_RXESC_RBDS_Set(x) \
    (((uint32_t) (x) << MCAN_RXESC_RBDS_Pos) & MCAN_RXESC_RBDS_Msk) /*!< RBDS Set Value            */
#define MCAN_RXESC_RBDS_Get(x) \
    (((uint32_t) (x) &MCAN_RXESC_RBDS_Msk) >> MCAN_RXESC_RBDS_Pos) /*!< RBDS Get Value            */


#define MCAN_RXESC_F1DS_Pos (4U)                          /*!< F1DS Postion   4          */
#define MCAN_RXESC_F1DS_Msk (0x7U << MCAN_RXESC_F1DS_Pos) /*!< F1DS Mask      0x00000070 */
#define MCAN_RXESC_F1DS_Set(x) \
    (((uint32_t) (x) << MCAN_RXESC_F1DS_Pos) & MCAN_RXESC_F1DS_Msk) /*!< F1DS Set Value            */
#define MCAN_RXESC_F1DS_Get(x) \
    (((uint32_t) (x) &MCAN_RXESC_F1DS_Msk) >> MCAN_RXESC_F1DS_Pos) /*!< F1DS Get Value            */


#define MCAN_RXESC_F0DS_Pos (0U)                          /*!< F0DS Postion   0          */
#define MCAN_RXESC_F0DS_Msk (0x7U << MCAN_RXESC_F0DS_Pos) /*!< F0DS Mask      0x00000007 */
#define MCAN_RXESC_F0DS_Set(x) \
    (((uint32_t) (x) << MCAN_RXESC_F0DS_Pos) & MCAN_RXESC_F0DS_Msk) /*!< F0DS Set Value            */
#define MCAN_RXESC_F0DS_Get(x) \
    (((uint32_t) (x) &MCAN_RXESC_F0DS_Msk) >> MCAN_RXESC_F0DS_Pos) /*!< F0DS Get Value            */


/* TXBC bitfield */
#define MCAN_TXBC_TFQM_Pos (30U)                        /*!< TFQM Postion   30         */
#define MCAN_TXBC_TFQM_Msk (0x1U << MCAN_TXBC_TFQM_Pos) /*!< TFQM Mask      0x40000000 */
#define MCAN_TXBC_TFQM_Set(x) \
    (((uint32_t) (x) << MCAN_TXBC_TFQM_Pos) & MCAN_TXBC_TFQM_Msk) /*!< TFQM Set Value            */
#define MCAN_TXBC_TFQM_Get(x) \
    (((uint32_t) (x) &MCAN_TXBC_TFQM_Msk) >> MCAN_TXBC_TFQM_Pos) /*!< TFQM Get Value            */


#define MCAN_TXBC_TFQS_Pos (24U)                         /*!< TFQS Postion   24         */
#define MCAN_TXBC_TFQS_Msk (0x3fU << MCAN_TXBC_TFQS_Pos) /*!< TFQS Mask      0x3F000000 */
#define MCAN_TXBC_TFQS_Set(x) \
    (((uint32_t) (x) << MCAN_TXBC_TFQS_Pos) & MCAN_TXBC_TFQS_Msk) /*!< TFQS Set Value            */
#define MCAN_TXBC_TFQS_Get(x) \
    (((uint32_t) (x) &MCAN_TXBC_TFQS_Msk) >> MCAN_TXBC_TFQS_Pos) /*!< TFQS Get Value            */


#define MCAN_TXBC_NDTB_Pos (16U)                         /*!< NDTB Postion   16         */
#define MCAN_TXBC_NDTB_Msk (0x3fU << MCAN_TXBC_NDTB_Pos) /*!< NDTB Mask      0x003F0000 */
#define MCAN_TXBC_NDTB_Set(x) \
    (((uint32_t) (x) << MCAN_TXBC_NDTB_Pos) & MCAN_TXBC_NDTB_Msk) /*!< NDTB Set Value            */
#define MCAN_TXBC_NDTB_Get(x) \
    (((uint32_t) (x) &MCAN_TXBC_NDTB_Msk) >> MCAN_TXBC_NDTB_Pos) /*!< NDTB Get Value            */


#define MCAN_TXBC_TBSA_Pos (2U)                            /*!< TBSA Postion   2          */
#define MCAN_TXBC_TBSA_Msk (0x3fffU << MCAN_TXBC_TBSA_Pos) /*!< TBSA Mask      0x0000FFFC */
#define MCAN_TXBC_TBSA_Set(x) \
    (((uint32_t) (x) << MCAN_TXBC_TBSA_Pos) & MCAN_TXBC_TBSA_Msk) /*!< TBSA Set Value            */
#define MCAN_TXBC_TBSA_Get(x) \
    (((uint32_t) (x) &MCAN_TXBC_TBSA_Msk) >> MCAN_TXBC_TBSA_Pos) /*!< TBSA Get Value            */


/* TXFQS bitfield */
#define MCAN_TXFQS_TFQF_Pos (21U)                         /*!< TFQF Postion   21         */
#define MCAN_TXFQS_TFQF_Msk (0x1U << MCAN_TXFQS_TFQF_Pos) /*!< TFQF Mask      0x00200000 */
#define MCAN_TXFQS_TFQF_Set(x) \
    (((uint32_t) (x) << MCAN_TXFQS_TFQF_Pos) & MCAN_TXFQS_TFQF_Msk) /*!< TFQF Set Value            */
#define MCAN_TXFQS_TFQF_Get(x) \
    (((uint32_t) (x) &MCAN_TXFQS_TFQF_Msk) >> MCAN_TXFQS_TFQF_Pos) /*!< TFQF Get Value            */


#define MCAN_TXFQS_TFQP_Pos (16U)                          /*!< TFQP Postion   16         */
#define MCAN_TXFQS_TFQP_Msk (0x1fU << MCAN_TXFQS_TFQP_Pos) /*!< TFQP Mask      0x001F0000 */
#define MCAN_TXFQS_TFQP_Set(x) \
    (((uint32_t) (x) << MCAN_TXFQS_TFQP_Pos) & MCAN_TXFQS_TFQP_Msk) /*!< TFQP Set Value            */
#define MCAN_TXFQS_TFQP_Get(x) \
    (((uint32_t) (x) &MCAN_TXFQS_TFQP_Msk) >> MCAN_TXFQS_TFQP_Pos) /*!< TFQP Get Value            */


#define MCAN_TXFQS_TFGI_Pos (8U)                           /*!< TFGI Postion   8          */
#define MCAN_TXFQS_TFGI_Msk (0x1fU << MCAN_TXFQS_TFGI_Pos) /*!< TFGI Mask      0x00001F00 */
#define MCAN_TXFQS_TFGI_Set(x) \
    (((uint32_t) (x) << MCAN_TXFQS_TFGI_Pos) & MCAN_TXFQS_TFGI_Msk) /*!< TFGI Set Value            */
#define MCAN_TXFQS_TFGI_Get(x) \
    (((uint32_t) (x) &MCAN_TXFQS_TFGI_Msk) >> MCAN_TXFQS_TFGI_Pos) /*!< TFGI Get Value            */


#define MCAN_TXFQS_TFFL_Pos (0U)                           /*!< TFFL Postion   0          */
#define MCAN_TXFQS_TFFL_Msk (0x3fU << MCAN_TXFQS_TFFL_Pos) /*!< TFFL Mask      0x0000003F */
#define MCAN_TXFQS_TFFL_Set(x) \
    (((uint32_t) (x) << MCAN_TXFQS_TFFL_Pos) & MCAN_TXFQS_TFFL_Msk) /*!< TFFL Set Value            */
#define MCAN_TXFQS_TFFL_Get(x) \
    (((uint32_t) (x) &MCAN_TXFQS_TFFL_Msk) >> MCAN_TXFQS_TFFL_Pos) /*!< TFFL Get Value            */


/* TXESC bitfield */
#define MCAN_TXESC_TBDS_Pos (0U)                          /*!< TBDS Postion   0          */
#define MCAN_TXESC_TBDS_Msk (0x7U << MCAN_TXESC_TBDS_Pos) /*!< TBDS Mask      0x00000007 */
#define MCAN_TXESC_TBDS_Set(x) \
    (((uint32_t) (x) << MCAN_TXESC_TBDS_Pos) & MCAN_TXESC_TBDS_Msk) /*!< TBDS Set Value            */
#define MCAN_TXESC_TBDS_Get(x) \
    (((uint32_t) (x) &MCAN_TXESC_TBDS_Msk) >> MCAN_TXESC_TBDS_Pos) /*!< TBDS Get Value            */


/* TXBRP bitfield */
#define MCAN_TXBRP_TRP31_Pos (31U)                          /*!< TRP31 Postion   31         */
#define MCAN_TXBRP_TRP31_Msk (0x1U << MCAN_TXBRP_TRP31_Pos) /*!< TRP31 Mask      0x80000000 */
#define MCAN_TXBRP_TRP31_Set(x) \
    (((uint32_t) (x) << MCAN_TXBRP_TRP31_Pos) & MCAN_TXBRP_TRP31_Msk) /*!< TRP31 Set Value            */
#define MCAN_TXBRP_TRP31_Get(x) \
    (((uint32_t) (x) &MCAN_TXBRP_TRP31_Msk) >> MCAN_TXBRP_TRP31_Pos) /*!< TRP31 Get Value            */


#define MCAN_TXBRP_TRP30_Pos (30U)                          /*!< TRP30 Postion   30         */
#define MCAN_TXBRP_TRP30_Msk (0x1U << MCAN_TXBRP_TRP30_Pos) /*!< TRP30 Mask      0x40000000 */
#define MCAN_TXBRP_TRP30_Set(x) \
    (((uint32_t) (x) << MCAN_TXBRP_TRP30_Pos) & MCAN_TXBRP_TRP30_Msk) /*!< TRP30 Set Value            */
#define MCAN_TXBRP_TRP30_Get(x) \
    (((uint32_t) (x) &MCAN_TXBRP_TRP30_Msk) >> MCAN_TXBRP_TRP30_Pos) /*!< TRP30 Get Value            */


#define MCAN_TXBRP_TRP29_Pos (29U)                          /*!< TRP29 Postion   29         */
#define MCAN_TXBRP_TRP29_Msk (0x1U << MCAN_TXBRP_TRP29_Pos) /*!< TRP29 Mask      0x20000000 */
#define MCAN_TXBRP_TRP29_Set(x) \
    (((uint32_t) (x) << MCAN_TXBRP_TRP29_Pos) & MCAN_TXBRP_TRP29_Msk) /*!< TRP29 Set Value            */
#define MCAN_TXBRP_TRP29_Get(x) \
    (((uint32_t) (x) &MCAN_TXBRP_TRP29_Msk) >> MCAN_TXBRP_TRP29_Pos) /*!< TRP29 Get Value            */


#define MCAN_TXBRP_TRP28_Pos (28U)                          /*!< TRP28 Postion   28         */
#define MCAN_TXBRP_TRP28_Msk (0x1U << MCAN_TXBRP_TRP28_Pos) /*!< TRP28 Mask      0x10000000 */
#define MCAN_TXBRP_TRP28_Set(x) \
    (((uint32_t) (x) << MCAN_TXBRP_TRP28_Pos) & MCAN_TXBRP_TRP28_Msk) /*!< TRP28 Set Value            */
#define MCAN_TXBRP_TRP28_Get(x) \
    (((uint32_t) (x) &MCAN_TXBRP_TRP28_Msk) >> MCAN_TXBRP_TRP28_Pos) /*!< TRP28 Get Value            */


#define MCAN_TXBRP_TRP27_Pos (27U)                          /*!< TRP27 Postion   27         */
#define MCAN_TXBRP_TRP27_Msk (0x1U << MCAN_TXBRP_TRP27_Pos) /*!< TRP27 Mask      0x08000000 */
#define MCAN_TXBRP_TRP27_Set(x) \
    (((uint32_t) (x) << MCAN_TXBRP_TRP27_Pos) & MCAN_TXBRP_TRP27_Msk) /*!< TRP27 Set Value            */
#define MCAN_TXBRP_TRP27_Get(x) \
    (((uint32_t) (x) &MCAN_TXBRP_TRP27_Msk) >> MCAN_TXBRP_TRP27_Pos) /*!< TRP27 Get Value            */


#define MCAN_TXBRP_TRP26_Pos (26U)                          /*!< TRP26 Postion   26         */
#define MCAN_TXBRP_TRP26_Msk (0x1U << MCAN_TXBRP_TRP26_Pos) /*!< TRP26 Mask      0x04000000 */
#define MCAN_TXBRP_TRP26_Set(x) \
    (((uint32_t) (x) << MCAN_TXBRP_TRP26_Pos) & MCAN_TXBRP_TRP26_Msk) /*!< TRP26 Set Value            */
#define MCAN_TXBRP_TRP26_Get(x) \
    (((uint32_t) (x) &MCAN_TXBRP_TRP26_Msk) >> MCAN_TXBRP_TRP26_Pos) /*!< TRP26 Get Value            */


#define MCAN_TXBRP_TRP25_Pos (25U)                          /*!< TRP25 Postion   25         */
#define MCAN_TXBRP_TRP25_Msk (0x1U << MCAN_TXBRP_TRP25_Pos) /*!< TRP25 Mask      0x02000000 */
#define MCAN_TXBRP_TRP25_Set(x) \
    (((uint32_t) (x) << MCAN_TXBRP_TRP25_Pos) & MCAN_TXBRP_TRP25_Msk) /*!< TRP25 Set Value            */
#define MCAN_TXBRP_TRP25_Get(x) \
    (((uint32_t) (x) &MCAN_TXBRP_TRP25_Msk) >> MCAN_TXBRP_TRP25_Pos) /*!< TRP25 Get Value            */


#define MCAN_TXBRP_TRP24_Pos (24U)                          /*!< TRP24 Postion   24         */
#define MCAN_TXBRP_TRP24_Msk (0x1U << MCAN_TXBRP_TRP24_Pos) /*!< TRP24 Mask      0x01000000 */
#define MCAN_TXBRP_TRP24_Set(x) \
    (((uint32_t) (x) << MCAN_TXBRP_TRP24_Pos) & MCAN_TXBRP_TRP24_Msk) /*!< TRP24 Set Value            */
#define MCAN_TXBRP_TRP24_Get(x) \
    (((uint32_t) (x) &MCAN_TXBRP_TRP24_Msk) >> MCAN_TXBRP_TRP24_Pos) /*!< TRP24 Get Value            */


#define MCAN_TXBRP_TRP23_Pos (23U)                          /*!< TRP23 Postion   23         */
#define MCAN_TXBRP_TRP23_Msk (0x1U << MCAN_TXBRP_TRP23_Pos) /*!< TRP23 Mask      0x00800000 */
#define MCAN_TXBRP_TRP23_Set(x) \
    (((uint32_t) (x) << MCAN_TXBRP_TRP23_Pos) & MCAN_TXBRP_TRP23_Msk) /*!< TRP23 Set Value            */
#define MCAN_TXBRP_TRP23_Get(x) \
    (((uint32_t) (x) &MCAN_TXBRP_TRP23_Msk) >> MCAN_TXBRP_TRP23_Pos) /*!< TRP23 Get Value            */


#define MCAN_TXBRP_TRP22_Pos (22U)                          /*!< TRP22 Postion   22         */
#define MCAN_TXBRP_TRP22_Msk (0x1U << MCAN_TXBRP_TRP22_Pos) /*!< TRP22 Mask      0x00400000 */
#define MCAN_TXBRP_TRP22_Set(x) \
    (((uint32_t) (x) << MCAN_TXBRP_TRP22_Pos) & MCAN_TXBRP_TRP22_Msk) /*!< TRP22 Set Value            */
#define MCAN_TXBRP_TRP22_Get(x) \
    (((uint32_t) (x) &MCAN_TXBRP_TRP22_Msk) >> MCAN_TXBRP_TRP22_Pos) /*!< TRP22 Get Value            */


#define MCAN_TXBRP_TRP21_Pos (21U)                          /*!< TRP21 Postion   21         */
#define MCAN_TXBRP_TRP21_Msk (0x1U << MCAN_TXBRP_TRP21_Pos) /*!< TRP21 Mask      0x00200000 */
#define MCAN_TXBRP_TRP21_Set(x) \
    (((uint32_t) (x) << MCAN_TXBRP_TRP21_Pos) & MCAN_TXBRP_TRP21_Msk) /*!< TRP21 Set Value            */
#define MCAN_TXBRP_TRP21_Get(x) \
    (((uint32_t) (x) &MCAN_TXBRP_TRP21_Msk) >> MCAN_TXBRP_TRP21_Pos) /*!< TRP21 Get Value            */


#define MCAN_TXBRP_TRP20_Pos (20U)                          /*!< TRP20 Postion   20         */
#define MCAN_TXBRP_TRP20_Msk (0x1U << MCAN_TXBRP_TRP20_Pos) /*!< TRP20 Mask      0x00100000 */
#define MCAN_TXBRP_TRP20_Set(x) \
    (((uint32_t) (x) << MCAN_TXBRP_TRP20_Pos) & MCAN_TXBRP_TRP20_Msk) /*!< TRP20 Set Value            */
#define MCAN_TXBRP_TRP20_Get(x) \
    (((uint32_t) (x) &MCAN_TXBRP_TRP20_Msk) >> MCAN_TXBRP_TRP20_Pos) /*!< TRP20 Get Value            */


#define MCAN_TXBRP_TRP19_Pos (19U)                          /*!< TRP19 Postion   19         */
#define MCAN_TXBRP_TRP19_Msk (0x1U << MCAN_TXBRP_TRP19_Pos) /*!< TRP19 Mask      0x00080000 */
#define MCAN_TXBRP_TRP19_Set(x) \
    (((uint32_t) (x) << MCAN_TXBRP_TRP19_Pos) & MCAN_TXBRP_TRP19_Msk) /*!< TRP19 Set Value            */
#define MCAN_TXBRP_TRP19_Get(x) \
    (((uint32_t) (x) &MCAN_TXBRP_TRP19_Msk) >> MCAN_TXBRP_TRP19_Pos) /*!< TRP19 Get Value            */


#define MCAN_TXBRP_TRP18_Pos (18U)                          /*!< TRP18 Postion   18         */
#define MCAN_TXBRP_TRP18_Msk (0x1U << MCAN_TXBRP_TRP18_Pos) /*!< TRP18 Mask      0x00040000 */
#define MCAN_TXBRP_TRP18_Set(x) \
    (((uint32_t) (x) << MCAN_TXBRP_TRP18_Pos) & MCAN_TXBRP_TRP18_Msk) /*!< TRP18 Set Value            */
#define MCAN_TXBRP_TRP18_Get(x) \
    (((uint32_t) (x) &MCAN_TXBRP_TRP18_Msk) >> MCAN_TXBRP_TRP18_Pos) /*!< TRP18 Get Value            */


#define MCAN_TXBRP_TRP17_Pos (17U)                          /*!< TRP17 Postion   17         */
#define MCAN_TXBRP_TRP17_Msk (0x1U << MCAN_TXBRP_TRP17_Pos) /*!< TRP17 Mask      0x00020000 */
#define MCAN_TXBRP_TRP17_Set(x) \
    (((uint32_t) (x) << MCAN_TXBRP_TRP17_Pos) & MCAN_TXBRP_TRP17_Msk) /*!< TRP17 Set Value            */
#define MCAN_TXBRP_TRP17_Get(x) \
    (((uint32_t) (x) &MCAN_TXBRP_TRP17_Msk) >> MCAN_TXBRP_TRP17_Pos) /*!< TRP17 Get Value            */


#define MCAN_TXBRP_TRP16_Pos (16U)                          /*!< TRP16 Postion   16         */
#define MCAN_TXBRP_TRP16_Msk (0x1U << MCAN_TXBRP_TRP16_Pos) /*!< TRP16 Mask      0x00010000 */
#define MCAN_TXBRP_TRP16_Set(x) \
    (((uint32_t) (x) << MCAN_TXBRP_TRP16_Pos) & MCAN_TXBRP_TRP16_Msk) /*!< TRP16 Set Value            */
#define MCAN_TXBRP_TRP16_Get(x) \
    (((uint32_t) (x) &MCAN_TXBRP_TRP16_Msk) >> MCAN_TXBRP_TRP16_Pos) /*!< TRP16 Get Value            */


#define MCAN_TXBRP_TRP15_Pos (15U)                          /*!< TRP15 Postion   15         */
#define MCAN_TXBRP_TRP15_Msk (0x1U << MCAN_TXBRP_TRP15_Pos) /*!< TRP15 Mask      0x00008000 */
#define MCAN_TXBRP_TRP15_Set(x) \
    (((uint32_t) (x) << MCAN_TXBRP_TRP15_Pos) & MCAN_TXBRP_TRP15_Msk) /*!< TRP15 Set Value            */
#define MCAN_TXBRP_TRP15_Get(x) \
    (((uint32_t) (x) &MCAN_TXBRP_TRP15_Msk) >> MCAN_TXBRP_TRP15_Pos) /*!< TRP15 Get Value            */


#define MCAN_TXBRP_TRP14_Pos (14U)                          /*!< TRP14 Postion   14         */
#define MCAN_TXBRP_TRP14_Msk (0x1U << MCAN_TXBRP_TRP14_Pos) /*!< TRP14 Mask      0x00004000 */
#define MCAN_TXBRP_TRP14_Set(x) \
    (((uint32_t) (x) << MCAN_TXBRP_TRP14_Pos) & MCAN_TXBRP_TRP14_Msk) /*!< TRP14 Set Value            */
#define MCAN_TXBRP_TRP14_Get(x) \
    (((uint32_t) (x) &MCAN_TXBRP_TRP14_Msk) >> MCAN_TXBRP_TRP14_Pos) /*!< TRP14 Get Value            */


#define MCAN_TXBRP_TRP13_Pos (13U)                          /*!< TRP13 Postion   13         */
#define MCAN_TXBRP_TRP13_Msk (0x1U << MCAN_TXBRP_TRP13_Pos) /*!< TRP13 Mask      0x00002000 */
#define MCAN_TXBRP_TRP13_Set(x) \
    (((uint32_t) (x) << MCAN_TXBRP_TRP13_Pos) & MCAN_TXBRP_TRP13_Msk) /*!< TRP13 Set Value            */
#define MCAN_TXBRP_TRP13_Get(x) \
    (((uint32_t) (x) &MCAN_TXBRP_TRP13_Msk) >> MCAN_TXBRP_TRP13_Pos) /*!< TRP13 Get Value            */


#define MCAN_TXBRP_TRP12_Pos (12U)                          /*!< TRP12 Postion   12         */
#define MCAN_TXBRP_TRP12_Msk (0x1U << MCAN_TXBRP_TRP12_Pos) /*!< TRP12 Mask      0x00001000 */
#define MCAN_TXBRP_TRP12_Set(x) \
    (((uint32_t) (x) << MCAN_TXBRP_TRP12_Pos) & MCAN_TXBRP_TRP12_Msk) /*!< TRP12 Set Value            */
#define MCAN_TXBRP_TRP12_Get(x) \
    (((uint32_t) (x) &MCAN_TXBRP_TRP12_Msk) >> MCAN_TXBRP_TRP12_Pos) /*!< TRP12 Get Value            */


#define MCAN_TXBRP_TRP11_Pos (11U)                          /*!< TRP11 Postion   11         */
#define MCAN_TXBRP_TRP11_Msk (0x1U << MCAN_TXBRP_TRP11_Pos) /*!< TRP11 Mask      0x00000800 */
#define MCAN_TXBRP_TRP11_Set(x) \
    (((uint32_t) (x) << MCAN_TXBRP_TRP11_Pos) & MCAN_TXBRP_TRP11_Msk) /*!< TRP11 Set Value            */
#define MCAN_TXBRP_TRP11_Get(x) \
    (((uint32_t) (x) &MCAN_TXBRP_TRP11_Msk) >> MCAN_TXBRP_TRP11_Pos) /*!< TRP11 Get Value            */


#define MCAN_TXBRP_TRP10_Pos (10U)                          /*!< TRP10 Postion   10         */
#define MCAN_TXBRP_TRP10_Msk (0x1U << MCAN_TXBRP_TRP10_Pos) /*!< TRP10 Mask      0x00000400 */
#define MCAN_TXBRP_TRP10_Set(x) \
    (((uint32_t) (x) << MCAN_TXBRP_TRP10_Pos) & MCAN_TXBRP_TRP10_Msk) /*!< TRP10 Set Value            */
#define MCAN_TXBRP_TRP10_Get(x) \
    (((uint32_t) (x) &MCAN_TXBRP_TRP10_Msk) >> MCAN_TXBRP_TRP10_Pos) /*!< TRP10 Get Value            */


#define MCAN_TXBRP_TRP9_Pos (9U)                          /*!< TRP9 Postion   9          */
#define MCAN_TXBRP_TRP9_Msk (0x1U << MCAN_TXBRP_TRP9_Pos) /*!< TRP9 Mask      0x00000200 */
#define MCAN_TXBRP_TRP9_Set(x) \
    (((uint32_t) (x) << MCAN_TXBRP_TRP9_Pos) & MCAN_TXBRP_TRP9_Msk) /*!< TRP9 Set Value            */
#define MCAN_TXBRP_TRP9_Get(x) \
    (((uint32_t) (x) &MCAN_TXBRP_TRP9_Msk) >> MCAN_TXBRP_TRP9_Pos) /*!< TRP9 Get Value            */


#define MCAN_TXBRP_TRP8_Pos (8U)                          /*!< TRP8 Postion   8          */
#define MCAN_TXBRP_TRP8_Msk (0x1U << MCAN_TXBRP_TRP8_Pos) /*!< TRP8 Mask      0x00000100 */
#define MCAN_TXBRP_TRP8_Set(x) \
    (((uint32_t) (x) << MCAN_TXBRP_TRP8_Pos) & MCAN_TXBRP_TRP8_Msk) /*!< TRP8 Set Value            */
#define MCAN_TXBRP_TRP8_Get(x) \
    (((uint32_t) (x) &MCAN_TXBRP_TRP8_Msk) >> MCAN_TXBRP_TRP8_Pos) /*!< TRP8 Get Value            */


#define MCAN_TXBRP_TRP7_Pos (7U)                          /*!< TRP7 Postion   7          */
#define MCAN_TXBRP_TRP7_Msk (0x1U << MCAN_TXBRP_TRP7_Pos) /*!< TRP7 Mask      0x00000080 */
#define MCAN_TXBRP_TRP7_Set(x) \
    (((uint32_t) (x) << MCAN_TXBRP_TRP7_Pos) & MCAN_TXBRP_TRP7_Msk) /*!< TRP7 Set Value            */
#define MCAN_TXBRP_TRP7_Get(x) \
    (((uint32_t) (x) &MCAN_TXBRP_TRP7_Msk) >> MCAN_TXBRP_TRP7_Pos) /*!< TRP7 Get Value            */


#define MCAN_TXBRP_TRP6_Pos (6U)                          /*!< TRP6 Postion   6          */
#define MCAN_TXBRP_TRP6_Msk (0x1U << MCAN_TXBRP_TRP6_Pos) /*!< TRP6 Mask      0x00000040 */
#define MCAN_TXBRP_TRP6_Set(x) \
    (((uint32_t) (x) << MCAN_TXBRP_TRP6_Pos) & MCAN_TXBRP_TRP6_Msk) /*!< TRP6 Set Value            */
#define MCAN_TXBRP_TRP6_Get(x) \
    (((uint32_t) (x) &MCAN_TXBRP_TRP6_Msk) >> MCAN_TXBRP_TRP6_Pos) /*!< TRP6 Get Value            */


#define MCAN_TXBRP_TRP5_Pos (5U)                          /*!< TRP5 Postion   5          */
#define MCAN_TXBRP_TRP5_Msk (0x1U << MCAN_TXBRP_TRP5_Pos) /*!< TRP5 Mask      0x00000020 */
#define MCAN_TXBRP_TRP5_Set(x) \
    (((uint32_t) (x) << MCAN_TXBRP_TRP5_Pos) & MCAN_TXBRP_TRP5_Msk) /*!< TRP5 Set Value            */
#define MCAN_TXBRP_TRP5_Get(x) \
    (((uint32_t) (x) &MCAN_TXBRP_TRP5_Msk) >> MCAN_TXBRP_TRP5_Pos) /*!< TRP5 Get Value            */


#define MCAN_TXBRP_TRP4_Pos (4U)                          /*!< TRP4 Postion   4          */
#define MCAN_TXBRP_TRP4_Msk (0x1U << MCAN_TXBRP_TRP4_Pos) /*!< TRP4 Mask      0x00000010 */
#define MCAN_TXBRP_TRP4_Set(x) \
    (((uint32_t) (x) << MCAN_TXBRP_TRP4_Pos) & MCAN_TXBRP_TRP4_Msk) /*!< TRP4 Set Value            */
#define MCAN_TXBRP_TRP4_Get(x) \
    (((uint32_t) (x) &MCAN_TXBRP_TRP4_Msk) >> MCAN_TXBRP_TRP4_Pos) /*!< TRP4 Get Value            */


#define MCAN_TXBRP_TRP3_Pos (3U)                          /*!< TRP3 Postion   3          */
#define MCAN_TXBRP_TRP3_Msk (0x1U << MCAN_TXBRP_TRP3_Pos) /*!< TRP3 Mask      0x00000008 */
#define MCAN_TXBRP_TRP3_Set(x) \
    (((uint32_t) (x) << MCAN_TXBRP_TRP3_Pos) & MCAN_TXBRP_TRP3_Msk) /*!< TRP3 Set Value            */
#define MCAN_TXBRP_TRP3_Get(x) \
    (((uint32_t) (x) &MCAN_TXBRP_TRP3_Msk) >> MCAN_TXBRP_TRP3_Pos) /*!< TRP3 Get Value            */


#define MCAN_TXBRP_TRP2_Pos (2U)                          /*!< TRP2 Postion   2          */
#define MCAN_TXBRP_TRP2_Msk (0x1U << MCAN_TXBRP_TRP2_Pos) /*!< TRP2 Mask      0x00000004 */
#define MCAN_TXBRP_TRP2_Set(x) \
    (((uint32_t) (x) << MCAN_TXBRP_TRP2_Pos) & MCAN_TXBRP_TRP2_Msk) /*!< TRP2 Set Value            */
#define MCAN_TXBRP_TRP2_Get(x) \
    (((uint32_t) (x) &MCAN_TXBRP_TRP2_Msk) >> MCAN_TXBRP_TRP2_Pos) /*!< TRP2 Get Value            */


#define MCAN_TXBRP_TRP1_Pos (1U)                          /*!< TRP1 Postion   1          */
#define MCAN_TXBRP_TRP1_Msk (0x1U << MCAN_TXBRP_TRP1_Pos) /*!< TRP1 Mask      0x00000002 */
#define MCAN_TXBRP_TRP1_Set(x) \
    (((uint32_t) (x) << MCAN_TXBRP_TRP1_Pos) & MCAN_TXBRP_TRP1_Msk) /*!< TRP1 Set Value            */
#define MCAN_TXBRP_TRP1_Get(x) \
    (((uint32_t) (x) &MCAN_TXBRP_TRP1_Msk) >> MCAN_TXBRP_TRP1_Pos) /*!< TRP1 Get Value            */


#define MCAN_TXBRP_TRP0_Pos (0U)                          /*!< TRP0 Postion   0          */
#define MCAN_TXBRP_TRP0_Msk (0x1U << MCAN_TXBRP_TRP0_Pos) /*!< TRP0 Mask      0x00000001 */
#define MCAN_TXBRP_TRP0_Set(x) \
    (((uint32_t) (x) << MCAN_TXBRP_TRP0_Pos) & MCAN_TXBRP_TRP0_Msk) /*!< TRP0 Set Value            */
#define MCAN_TXBRP_TRP0_Get(x) \
    (((uint32_t) (x) &MCAN_TXBRP_TRP0_Msk) >> MCAN_TXBRP_TRP0_Pos) /*!< TRP0 Get Value            */


/* TXBAR bitfield */
#define MCAN_TXBAR_AR31_Pos (31U)                         /*!< AR31 Postion   31         */
#define MCAN_TXBAR_AR31_Msk (0x1U << MCAN_TXBAR_AR31_Pos) /*!< AR31 Mask      0x80000000 */
#define MCAN_TXBAR_AR31_Set(x) \
    (((uint32_t) (x) << MCAN_TXBAR_AR31_Pos) & MCAN_TXBAR_AR31_Msk) /*!< AR31 Set Value            */
#define MCAN_TXBAR_AR31_Get(x) \
    (((uint32_t) (x) &MCAN_TXBAR_AR31_Msk) >> MCAN_TXBAR_AR31_Pos) /*!< AR31 Get Value            */


#define MCAN_TXBAR_AR30_Pos (30U)                         /*!< AR30 Postion   30         */
#define MCAN_TXBAR_AR30_Msk (0x1U << MCAN_TXBAR_AR30_Pos) /*!< AR30 Mask      0x40000000 */
#define MCAN_TXBAR_AR30_Set(x) \
    (((uint32_t) (x) << MCAN_TXBAR_AR30_Pos) & MCAN_TXBAR_AR30_Msk) /*!< AR30 Set Value            */
#define MCAN_TXBAR_AR30_Get(x) \
    (((uint32_t) (x) &MCAN_TXBAR_AR30_Msk) >> MCAN_TXBAR_AR30_Pos) /*!< AR30 Get Value            */


#define MCAN_TXBAR_AR29_Pos (29U)                         /*!< AR29 Postion   29         */
#define MCAN_TXBAR_AR29_Msk (0x1U << MCAN_TXBAR_AR29_Pos) /*!< AR29 Mask      0x20000000 */
#define MCAN_TXBAR_AR29_Set(x) \
    (((uint32_t) (x) << MCAN_TXBAR_AR29_Pos) & MCAN_TXBAR_AR29_Msk) /*!< AR29 Set Value            */
#define MCAN_TXBAR_AR29_Get(x) \
    (((uint32_t) (x) &MCAN_TXBAR_AR29_Msk) >> MCAN_TXBAR_AR29_Pos) /*!< AR29 Get Value            */


#define MCAN_TXBAR_AR28_Pos (28U)                         /*!< AR28 Postion   28         */
#define MCAN_TXBAR_AR28_Msk (0x1U << MCAN_TXBAR_AR28_Pos) /*!< AR28 Mask      0x10000000 */
#define MCAN_TXBAR_AR28_Set(x) \
    (((uint32_t) (x) << MCAN_TXBAR_AR28_Pos) & MCAN_TXBAR_AR28_Msk) /*!< AR28 Set Value            */
#define MCAN_TXBAR_AR28_Get(x) \
    (((uint32_t) (x) &MCAN_TXBAR_AR28_Msk) >> MCAN_TXBAR_AR28_Pos) /*!< AR28 Get Value            */


#define MCAN_TXBAR_AR27_Pos (27U)                         /*!< AR27 Postion   27         */
#define MCAN_TXBAR_AR27_Msk (0x1U << MCAN_TXBAR_AR27_Pos) /*!< AR27 Mask      0x08000000 */
#define MCAN_TXBAR_AR27_Set(x) \
    (((uint32_t) (x) << MCAN_TXBAR_AR27_Pos) & MCAN_TXBAR_AR27_Msk) /*!< AR27 Set Value            */
#define MCAN_TXBAR_AR27_Get(x) \
    (((uint32_t) (x) &MCAN_TXBAR_AR27_Msk) >> MCAN_TXBAR_AR27_Pos) /*!< AR27 Get Value            */


#define MCAN_TXBAR_AR26_Pos (26U)                         /*!< AR26 Postion   26         */
#define MCAN_TXBAR_AR26_Msk (0x1U << MCAN_TXBAR_AR26_Pos) /*!< AR26 Mask      0x04000000 */
#define MCAN_TXBAR_AR26_Set(x) \
    (((uint32_t) (x) << MCAN_TXBAR_AR26_Pos) & MCAN_TXBAR_AR26_Msk) /*!< AR26 Set Value            */
#define MCAN_TXBAR_AR26_Get(x) \
    (((uint32_t) (x) &MCAN_TXBAR_AR26_Msk) >> MCAN_TXBAR_AR26_Pos) /*!< AR26 Get Value            */


#define MCAN_TXBAR_AR25_Pos (25U)                         /*!< AR25 Postion   25         */
#define MCAN_TXBAR_AR25_Msk (0x1U << MCAN_TXBAR_AR25_Pos) /*!< AR25 Mask      0x02000000 */
#define MCAN_TXBAR_AR25_Set(x) \
    (((uint32_t) (x) << MCAN_TXBAR_AR25_Pos) & MCAN_TXBAR_AR25_Msk) /*!< AR25 Set Value            */
#define MCAN_TXBAR_AR25_Get(x) \
    (((uint32_t) (x) &MCAN_TXBAR_AR25_Msk) >> MCAN_TXBAR_AR25_Pos) /*!< AR25 Get Value            */


#define MCAN_TXBAR_AR24_Pos (24U)                         /*!< AR24 Postion   24         */
#define MCAN_TXBAR_AR24_Msk (0x1U << MCAN_TXBAR_AR24_Pos) /*!< AR24 Mask      0x01000000 */
#define MCAN_TXBAR_AR24_Set(x) \
    (((uint32_t) (x) << MCAN_TXBAR_AR24_Pos) & MCAN_TXBAR_AR24_Msk) /*!< AR24 Set Value            */
#define MCAN_TXBAR_AR24_Get(x) \
    (((uint32_t) (x) &MCAN_TXBAR_AR24_Msk) >> MCAN_TXBAR_AR24_Pos) /*!< AR24 Get Value            */


#define MCAN_TXBAR_AR23_Pos (23U)                         /*!< AR23 Postion   23         */
#define MCAN_TXBAR_AR23_Msk (0x1U << MCAN_TXBAR_AR23_Pos) /*!< AR23 Mask      0x00800000 */
#define MCAN_TXBAR_AR23_Set(x) \
    (((uint32_t) (x) << MCAN_TXBAR_AR23_Pos) & MCAN_TXBAR_AR23_Msk) /*!< AR23 Set Value            */
#define MCAN_TXBAR_AR23_Get(x) \
    (((uint32_t) (x) &MCAN_TXBAR_AR23_Msk) >> MCAN_TXBAR_AR23_Pos) /*!< AR23 Get Value            */


#define MCAN_TXBAR_AR22_Pos (22U)                         /*!< AR22 Postion   22         */
#define MCAN_TXBAR_AR22_Msk (0x1U << MCAN_TXBAR_AR22_Pos) /*!< AR22 Mask      0x00400000 */
#define MCAN_TXBAR_AR22_Set(x) \
    (((uint32_t) (x) << MCAN_TXBAR_AR22_Pos) & MCAN_TXBAR_AR22_Msk) /*!< AR22 Set Value            */
#define MCAN_TXBAR_AR22_Get(x) \
    (((uint32_t) (x) &MCAN_TXBAR_AR22_Msk) >> MCAN_TXBAR_AR22_Pos) /*!< AR22 Get Value            */


#define MCAN_TXBAR_AR21_Pos (21U)                         /*!< AR21 Postion   21         */
#define MCAN_TXBAR_AR21_Msk (0x1U << MCAN_TXBAR_AR21_Pos) /*!< AR21 Mask      0x00200000 */
#define MCAN_TXBAR_AR21_Set(x) \
    (((uint32_t) (x) << MCAN_TXBAR_AR21_Pos) & MCAN_TXBAR_AR21_Msk) /*!< AR21 Set Value            */
#define MCAN_TXBAR_AR21_Get(x) \
    (((uint32_t) (x) &MCAN_TXBAR_AR21_Msk) >> MCAN_TXBAR_AR21_Pos) /*!< AR21 Get Value            */


#define MCAN_TXBAR_AR20_Pos (20U)                         /*!< AR20 Postion   20         */
#define MCAN_TXBAR_AR20_Msk (0x1U << MCAN_TXBAR_AR20_Pos) /*!< AR20 Mask      0x00100000 */
#define MCAN_TXBAR_AR20_Set(x) \
    (((uint32_t) (x) << MCAN_TXBAR_AR20_Pos) & MCAN_TXBAR_AR20_Msk) /*!< AR20 Set Value            */
#define MCAN_TXBAR_AR20_Get(x) \
    (((uint32_t) (x) &MCAN_TXBAR_AR20_Msk) >> MCAN_TXBAR_AR20_Pos) /*!< AR20 Get Value            */


#define MCAN_TXBAR_AR19_Pos (19U)                         /*!< AR19 Postion   19         */
#define MCAN_TXBAR_AR19_Msk (0x1U << MCAN_TXBAR_AR19_Pos) /*!< AR19 Mask      0x00080000 */
#define MCAN_TXBAR_AR19_Set(x) \
    (((uint32_t) (x) << MCAN_TXBAR_AR19_Pos) & MCAN_TXBAR_AR19_Msk) /*!< AR19 Set Value            */
#define MCAN_TXBAR_AR19_Get(x) \
    (((uint32_t) (x) &MCAN_TXBAR_AR19_Msk) >> MCAN_TXBAR_AR19_Pos) /*!< AR19 Get Value            */


#define MCAN_TXBAR_AR18_Pos (18U)                         /*!< AR18 Postion   18         */
#define MCAN_TXBAR_AR18_Msk (0x1U << MCAN_TXBAR_AR18_Pos) /*!< AR18 Mask      0x00040000 */
#define MCAN_TXBAR_AR18_Set(x) \
    (((uint32_t) (x) << MCAN_TXBAR_AR18_Pos) & MCAN_TXBAR_AR18_Msk) /*!< AR18 Set Value            */
#define MCAN_TXBAR_AR18_Get(x) \
    (((uint32_t) (x) &MCAN_TXBAR_AR18_Msk) >> MCAN_TXBAR_AR18_Pos) /*!< AR18 Get Value            */


#define MCAN_TXBAR_AR17_Pos (17U)                         /*!< AR17 Postion   17         */
#define MCAN_TXBAR_AR17_Msk (0x1U << MCAN_TXBAR_AR17_Pos) /*!< AR17 Mask      0x00020000 */
#define MCAN_TXBAR_AR17_Set(x) \
    (((uint32_t) (x) << MCAN_TXBAR_AR17_Pos) & MCAN_TXBAR_AR17_Msk) /*!< AR17 Set Value            */
#define MCAN_TXBAR_AR17_Get(x) \
    (((uint32_t) (x) &MCAN_TXBAR_AR17_Msk) >> MCAN_TXBAR_AR17_Pos) /*!< AR17 Get Value            */


#define MCAN_TXBAR_AR16_Pos (16U)                         /*!< AR16 Postion   16         */
#define MCAN_TXBAR_AR16_Msk (0x1U << MCAN_TXBAR_AR16_Pos) /*!< AR16 Mask      0x00010000 */
#define MCAN_TXBAR_AR16_Set(x) \
    (((uint32_t) (x) << MCAN_TXBAR_AR16_Pos) & MCAN_TXBAR_AR16_Msk) /*!< AR16 Set Value            */
#define MCAN_TXBAR_AR16_Get(x) \
    (((uint32_t) (x) &MCAN_TXBAR_AR16_Msk) >> MCAN_TXBAR_AR16_Pos) /*!< AR16 Get Value            */


#define MCAN_TXBAR_AR15_Pos (15U)                         /*!< AR15 Postion   15         */
#define MCAN_TXBAR_AR15_Msk (0x1U << MCAN_TXBAR_AR15_Pos) /*!< AR15 Mask      0x00008000 */
#define MCAN_TXBAR_AR15_Set(x) \
    (((uint32_t) (x) << MCAN_TXBAR_AR15_Pos) & MCAN_TXBAR_AR15_Msk) /*!< AR15 Set Value            */
#define MCAN_TXBAR_AR15_Get(x) \
    (((uint32_t) (x) &MCAN_TXBAR_AR15_Msk) >> MCAN_TXBAR_AR15_Pos) /*!< AR15 Get Value            */


#define MCAN_TXBAR_AR14_Pos (14U)                         /*!< AR14 Postion   14         */
#define MCAN_TXBAR_AR14_Msk (0x1U << MCAN_TXBAR_AR14_Pos) /*!< AR14 Mask      0x00004000 */
#define MCAN_TXBAR_AR14_Set(x) \
    (((uint32_t) (x) << MCAN_TXBAR_AR14_Pos) & MCAN_TXBAR_AR14_Msk) /*!< AR14 Set Value            */
#define MCAN_TXBAR_AR14_Get(x) \
    (((uint32_t) (x) &MCAN_TXBAR_AR14_Msk) >> MCAN_TXBAR_AR14_Pos) /*!< AR14 Get Value            */


#define MCAN_TXBAR_AR13_Pos (13U)                         /*!< AR13 Postion   13         */
#define MCAN_TXBAR_AR13_Msk (0x1U << MCAN_TXBAR_AR13_Pos) /*!< AR13 Mask      0x00002000 */
#define MCAN_TXBAR_AR13_Set(x) \
    (((uint32_t) (x) << MCAN_TXBAR_AR13_Pos) & MCAN_TXBAR_AR13_Msk) /*!< AR13 Set Value            */
#define MCAN_TXBAR_AR13_Get(x) \
    (((uint32_t) (x) &MCAN_TXBAR_AR13_Msk) >> MCAN_TXBAR_AR13_Pos) /*!< AR13 Get Value            */


#define MCAN_TXBAR_AR12_Pos (12U)                         /*!< AR12 Postion   12         */
#define MCAN_TXBAR_AR12_Msk (0x1U << MCAN_TXBAR_AR12_Pos) /*!< AR12 Mask      0x00001000 */
#define MCAN_TXBAR_AR12_Set(x) \
    (((uint32_t) (x) << MCAN_TXBAR_AR12_Pos) & MCAN_TXBAR_AR12_Msk) /*!< AR12 Set Value            */
#define MCAN_TXBAR_AR12_Get(x) \
    (((uint32_t) (x) &MCAN_TXBAR_AR12_Msk) >> MCAN_TXBAR_AR12_Pos) /*!< AR12 Get Value            */


#define MCAN_TXBAR_AR11_Pos (11U)                         /*!< AR11 Postion   11         */
#define MCAN_TXBAR_AR11_Msk (0x1U << MCAN_TXBAR_AR11_Pos) /*!< AR11 Mask      0x00000800 */
#define MCAN_TXBAR_AR11_Set(x) \
    (((uint32_t) (x) << MCAN_TXBAR_AR11_Pos) & MCAN_TXBAR_AR11_Msk) /*!< AR11 Set Value            */
#define MCAN_TXBAR_AR11_Get(x) \
    (((uint32_t) (x) &MCAN_TXBAR_AR11_Msk) >> MCAN_TXBAR_AR11_Pos) /*!< AR11 Get Value            */


#define MCAN_TXBAR_AR10_Pos (10U)                         /*!< AR10 Postion   10         */
#define MCAN_TXBAR_AR10_Msk (0x1U << MCAN_TXBAR_AR10_Pos) /*!< AR10 Mask      0x00000400 */
#define MCAN_TXBAR_AR10_Set(x) \
    (((uint32_t) (x) << MCAN_TXBAR_AR10_Pos) & MCAN_TXBAR_AR10_Msk) /*!< AR10 Set Value            */
#define MCAN_TXBAR_AR10_Get(x) \
    (((uint32_t) (x) &MCAN_TXBAR_AR10_Msk) >> MCAN_TXBAR_AR10_Pos) /*!< AR10 Get Value            */


#define MCAN_TXBAR_AR9_Pos (9U)                         /*!< AR9 Postion   9          */
#define MCAN_TXBAR_AR9_Msk (0x1U << MCAN_TXBAR_AR9_Pos) /*!< AR9 Mask      0x00000200 */
#define MCAN_TXBAR_AR9_Set(x) \
    (((uint32_t) (x) << MCAN_TXBAR_AR9_Pos) & MCAN_TXBAR_AR9_Msk) /*!< AR9 Set Value            */
#define MCAN_TXBAR_AR9_Get(x) \
    (((uint32_t) (x) &MCAN_TXBAR_AR9_Msk) >> MCAN_TXBAR_AR9_Pos) /*!< AR9 Get Value            */


#define MCAN_TXBAR_AR8_Pos (8U)                         /*!< AR8 Postion   8          */
#define MCAN_TXBAR_AR8_Msk (0x1U << MCAN_TXBAR_AR8_Pos) /*!< AR8 Mask      0x00000100 */
#define MCAN_TXBAR_AR8_Set(x) \
    (((uint32_t) (x) << MCAN_TXBAR_AR8_Pos) & MCAN_TXBAR_AR8_Msk) /*!< AR8 Set Value            */
#define MCAN_TXBAR_AR8_Get(x) \
    (((uint32_t) (x) &MCAN_TXBAR_AR8_Msk) >> MCAN_TXBAR_AR8_Pos) /*!< AR8 Get Value            */


#define MCAN_TXBAR_AR7_Pos (7U)                         /*!< AR7 Postion   7          */
#define MCAN_TXBAR_AR7_Msk (0x1U << MCAN_TXBAR_AR7_Pos) /*!< AR7 Mask      0x00000080 */
#define MCAN_TXBAR_AR7_Set(x) \
    (((uint32_t) (x) << MCAN_TXBAR_AR7_Pos) & MCAN_TXBAR_AR7_Msk) /*!< AR7 Set Value            */
#define MCAN_TXBAR_AR7_Get(x) \
    (((uint32_t) (x) &MCAN_TXBAR_AR7_Msk) >> MCAN_TXBAR_AR7_Pos) /*!< AR7 Get Value            */


#define MCAN_TXBAR_AR6_Pos (6U)                         /*!< AR6 Postion   6          */
#define MCAN_TXBAR_AR6_Msk (0x1U << MCAN_TXBAR_AR6_Pos) /*!< AR6 Mask      0x00000040 */
#define MCAN_TXBAR_AR6_Set(x) \
    (((uint32_t) (x) << MCAN_TXBAR_AR6_Pos) & MCAN_TXBAR_AR6_Msk) /*!< AR6 Set Value            */
#define MCAN_TXBAR_AR6_Get(x) \
    (((uint32_t) (x) &MCAN_TXBAR_AR6_Msk) >> MCAN_TXBAR_AR6_Pos) /*!< AR6 Get Value            */


#define MCAN_TXBAR_AR5_Pos (5U)                         /*!< AR5 Postion   5          */
#define MCAN_TXBAR_AR5_Msk (0x1U << MCAN_TXBAR_AR5_Pos) /*!< AR5 Mask      0x00000020 */
#define MCAN_TXBAR_AR5_Set(x) \
    (((uint32_t) (x) << MCAN_TXBAR_AR5_Pos) & MCAN_TXBAR_AR5_Msk) /*!< AR5 Set Value            */
#define MCAN_TXBAR_AR5_Get(x) \
    (((uint32_t) (x) &MCAN_TXBAR_AR5_Msk) >> MCAN_TXBAR_AR5_Pos) /*!< AR5 Get Value            */


#define MCAN_TXBAR_AR4_Pos (4U)                         /*!< AR4 Postion   4          */
#define MCAN_TXBAR_AR4_Msk (0x1U << MCAN_TXBAR_AR4_Pos) /*!< AR4 Mask      0x00000010 */
#define MCAN_TXBAR_AR4_Set(x) \
    (((uint32_t) (x) << MCAN_TXBAR_AR4_Pos) & MCAN_TXBAR_AR4_Msk) /*!< AR4 Set Value            */
#define MCAN_TXBAR_AR4_Get(x) \
    (((uint32_t) (x) &MCAN_TXBAR_AR4_Msk) >> MCAN_TXBAR_AR4_Pos) /*!< AR4 Get Value            */


#define MCAN_TXBAR_AR3_Pos (3U)                         /*!< AR3 Postion   3          */
#define MCAN_TXBAR_AR3_Msk (0x1U << MCAN_TXBAR_AR3_Pos) /*!< AR3 Mask      0x00000008 */
#define MCAN_TXBAR_AR3_Set(x) \
    (((uint32_t) (x) << MCAN_TXBAR_AR3_Pos) & MCAN_TXBAR_AR3_Msk) /*!< AR3 Set Value            */
#define MCAN_TXBAR_AR3_Get(x) \
    (((uint32_t) (x) &MCAN_TXBAR_AR3_Msk) >> MCAN_TXBAR_AR3_Pos) /*!< AR3 Get Value            */


#define MCAN_TXBAR_AR2_Pos (2U)                         /*!< AR2 Postion   2          */
#define MCAN_TXBAR_AR2_Msk (0x1U << MCAN_TXBAR_AR2_Pos) /*!< AR2 Mask      0x00000004 */
#define MCAN_TXBAR_AR2_Set(x) \
    (((uint32_t) (x) << MCAN_TXBAR_AR2_Pos) & MCAN_TXBAR_AR2_Msk) /*!< AR2 Set Value            */
#define MCAN_TXBAR_AR2_Get(x) \
    (((uint32_t) (x) &MCAN_TXBAR_AR2_Msk) >> MCAN_TXBAR_AR2_Pos) /*!< AR2 Get Value            */


#define MCAN_TXBAR_AR1_Pos (1U)                         /*!< AR1 Postion   1          */
#define MCAN_TXBAR_AR1_Msk (0x1U << MCAN_TXBAR_AR1_Pos) /*!< AR1 Mask      0x00000002 */
#define MCAN_TXBAR_AR1_Set(x) \
    (((uint32_t) (x) << MCAN_TXBAR_AR1_Pos) & MCAN_TXBAR_AR1_Msk) /*!< AR1 Set Value            */
#define MCAN_TXBAR_AR1_Get(x) \
    (((uint32_t) (x) &MCAN_TXBAR_AR1_Msk) >> MCAN_TXBAR_AR1_Pos) /*!< AR1 Get Value            */


#define MCAN_TXBAR_AR0_Pos (0U)                         /*!< AR0 Postion   0          */
#define MCAN_TXBAR_AR0_Msk (0x1U << MCAN_TXBAR_AR0_Pos) /*!< AR0 Mask      0x00000001 */
#define MCAN_TXBAR_AR0_Set(x) \
    (((uint32_t) (x) << MCAN_TXBAR_AR0_Pos) & MCAN_TXBAR_AR0_Msk) /*!< AR0 Set Value            */
#define MCAN_TXBAR_AR0_Get(x) \
    (((uint32_t) (x) &MCAN_TXBAR_AR0_Msk) >> MCAN_TXBAR_AR0_Pos) /*!< AR0 Get Value            */


/* TXBCR bitfield */
#define MCAN_TXBCR_CR31_Pos (31U)                         /*!< CR31 Postion   31         */
#define MCAN_TXBCR_CR31_Msk (0x1U << MCAN_TXBCR_CR31_Pos) /*!< CR31 Mask      0x80000000 */
#define MCAN_TXBCR_CR31_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCR_CR31_Pos) & MCAN_TXBCR_CR31_Msk) /*!< CR31 Set Value            */
#define MCAN_TXBCR_CR31_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCR_CR31_Msk) >> MCAN_TXBCR_CR31_Pos) /*!< CR31 Get Value            */


#define MCAN_TXBCR_CR30_Pos (30U)                         /*!< CR30 Postion   30         */
#define MCAN_TXBCR_CR30_Msk (0x1U << MCAN_TXBCR_CR30_Pos) /*!< CR30 Mask      0x40000000 */
#define MCAN_TXBCR_CR30_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCR_CR30_Pos) & MCAN_TXBCR_CR30_Msk) /*!< CR30 Set Value            */
#define MCAN_TXBCR_CR30_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCR_CR30_Msk) >> MCAN_TXBCR_CR30_Pos) /*!< CR30 Get Value            */


#define MCAN_TXBCR_CR29_Pos (29U)                         /*!< CR29 Postion   29         */
#define MCAN_TXBCR_CR29_Msk (0x1U << MCAN_TXBCR_CR29_Pos) /*!< CR29 Mask      0x20000000 */
#define MCAN_TXBCR_CR29_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCR_CR29_Pos) & MCAN_TXBCR_CR29_Msk) /*!< CR29 Set Value            */
#define MCAN_TXBCR_CR29_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCR_CR29_Msk) >> MCAN_TXBCR_CR29_Pos) /*!< CR29 Get Value            */


#define MCAN_TXBCR_CR28_Pos (28U)                         /*!< CR28 Postion   28         */
#define MCAN_TXBCR_CR28_Msk (0x1U << MCAN_TXBCR_CR28_Pos) /*!< CR28 Mask      0x10000000 */
#define MCAN_TXBCR_CR28_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCR_CR28_Pos) & MCAN_TXBCR_CR28_Msk) /*!< CR28 Set Value            */
#define MCAN_TXBCR_CR28_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCR_CR28_Msk) >> MCAN_TXBCR_CR28_Pos) /*!< CR28 Get Value            */


#define MCAN_TXBCR_CR27_Pos (27U)                         /*!< CR27 Postion   27         */
#define MCAN_TXBCR_CR27_Msk (0x1U << MCAN_TXBCR_CR27_Pos) /*!< CR27 Mask      0x08000000 */
#define MCAN_TXBCR_CR27_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCR_CR27_Pos) & MCAN_TXBCR_CR27_Msk) /*!< CR27 Set Value            */
#define MCAN_TXBCR_CR27_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCR_CR27_Msk) >> MCAN_TXBCR_CR27_Pos) /*!< CR27 Get Value            */


#define MCAN_TXBCR_CR26_Pos (26U)                         /*!< CR26 Postion   26         */
#define MCAN_TXBCR_CR26_Msk (0x1U << MCAN_TXBCR_CR26_Pos) /*!< CR26 Mask      0x04000000 */
#define MCAN_TXBCR_CR26_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCR_CR26_Pos) & MCAN_TXBCR_CR26_Msk) /*!< CR26 Set Value            */
#define MCAN_TXBCR_CR26_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCR_CR26_Msk) >> MCAN_TXBCR_CR26_Pos) /*!< CR26 Get Value            */


#define MCAN_TXBCR_CR25_Pos (25U)                         /*!< CR25 Postion   25         */
#define MCAN_TXBCR_CR25_Msk (0x1U << MCAN_TXBCR_CR25_Pos) /*!< CR25 Mask      0x02000000 */
#define MCAN_TXBCR_CR25_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCR_CR25_Pos) & MCAN_TXBCR_CR25_Msk) /*!< CR25 Set Value            */
#define MCAN_TXBCR_CR25_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCR_CR25_Msk) >> MCAN_TXBCR_CR25_Pos) /*!< CR25 Get Value            */


#define MCAN_TXBCR_CR24_Pos (24U)                         /*!< CR24 Postion   24         */
#define MCAN_TXBCR_CR24_Msk (0x1U << MCAN_TXBCR_CR24_Pos) /*!< CR24 Mask      0x01000000 */
#define MCAN_TXBCR_CR24_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCR_CR24_Pos) & MCAN_TXBCR_CR24_Msk) /*!< CR24 Set Value            */
#define MCAN_TXBCR_CR24_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCR_CR24_Msk) >> MCAN_TXBCR_CR24_Pos) /*!< CR24 Get Value            */


#define MCAN_TXBCR_CR23_Pos (23U)                         /*!< CR23 Postion   23         */
#define MCAN_TXBCR_CR23_Msk (0x1U << MCAN_TXBCR_CR23_Pos) /*!< CR23 Mask      0x00800000 */
#define MCAN_TXBCR_CR23_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCR_CR23_Pos) & MCAN_TXBCR_CR23_Msk) /*!< CR23 Set Value            */
#define MCAN_TXBCR_CR23_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCR_CR23_Msk) >> MCAN_TXBCR_CR23_Pos) /*!< CR23 Get Value            */


#define MCAN_TXBCR_CR22_Pos (22U)                         /*!< CR22 Postion   22         */
#define MCAN_TXBCR_CR22_Msk (0x1U << MCAN_TXBCR_CR22_Pos) /*!< CR22 Mask      0x00400000 */
#define MCAN_TXBCR_CR22_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCR_CR22_Pos) & MCAN_TXBCR_CR22_Msk) /*!< CR22 Set Value            */
#define MCAN_TXBCR_CR22_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCR_CR22_Msk) >> MCAN_TXBCR_CR22_Pos) /*!< CR22 Get Value            */


#define MCAN_TXBCR_CR21_Pos (21U)                         /*!< CR21 Postion   21         */
#define MCAN_TXBCR_CR21_Msk (0x1U << MCAN_TXBCR_CR21_Pos) /*!< CR21 Mask      0x00200000 */
#define MCAN_TXBCR_CR21_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCR_CR21_Pos) & MCAN_TXBCR_CR21_Msk) /*!< CR21 Set Value            */
#define MCAN_TXBCR_CR21_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCR_CR21_Msk) >> MCAN_TXBCR_CR21_Pos) /*!< CR21 Get Value            */


#define MCAN_TXBCR_CR20_Pos (20U)                         /*!< CR20 Postion   20         */
#define MCAN_TXBCR_CR20_Msk (0x1U << MCAN_TXBCR_CR20_Pos) /*!< CR20 Mask      0x00100000 */
#define MCAN_TXBCR_CR20_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCR_CR20_Pos) & MCAN_TXBCR_CR20_Msk) /*!< CR20 Set Value            */
#define MCAN_TXBCR_CR20_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCR_CR20_Msk) >> MCAN_TXBCR_CR20_Pos) /*!< CR20 Get Value            */


#define MCAN_TXBCR_CR19_Pos (19U)                         /*!< CR19 Postion   19         */
#define MCAN_TXBCR_CR19_Msk (0x1U << MCAN_TXBCR_CR19_Pos) /*!< CR19 Mask      0x00080000 */
#define MCAN_TXBCR_CR19_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCR_CR19_Pos) & MCAN_TXBCR_CR19_Msk) /*!< CR19 Set Value            */
#define MCAN_TXBCR_CR19_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCR_CR19_Msk) >> MCAN_TXBCR_CR19_Pos) /*!< CR19 Get Value            */


#define MCAN_TXBCR_CR18_Pos (18U)                         /*!< CR18 Postion   18         */
#define MCAN_TXBCR_CR18_Msk (0x1U << MCAN_TXBCR_CR18_Pos) /*!< CR18 Mask      0x00040000 */
#define MCAN_TXBCR_CR18_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCR_CR18_Pos) & MCAN_TXBCR_CR18_Msk) /*!< CR18 Set Value            */
#define MCAN_TXBCR_CR18_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCR_CR18_Msk) >> MCAN_TXBCR_CR18_Pos) /*!< CR18 Get Value            */


#define MCAN_TXBCR_CR17_Pos (17U)                         /*!< CR17 Postion   17         */
#define MCAN_TXBCR_CR17_Msk (0x1U << MCAN_TXBCR_CR17_Pos) /*!< CR17 Mask      0x00020000 */
#define MCAN_TXBCR_CR17_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCR_CR17_Pos) & MCAN_TXBCR_CR17_Msk) /*!< CR17 Set Value            */
#define MCAN_TXBCR_CR17_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCR_CR17_Msk) >> MCAN_TXBCR_CR17_Pos) /*!< CR17 Get Value            */


#define MCAN_TXBCR_CR16_Pos (16U)                         /*!< CR16 Postion   16         */
#define MCAN_TXBCR_CR16_Msk (0x1U << MCAN_TXBCR_CR16_Pos) /*!< CR16 Mask      0x00010000 */
#define MCAN_TXBCR_CR16_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCR_CR16_Pos) & MCAN_TXBCR_CR16_Msk) /*!< CR16 Set Value            */
#define MCAN_TXBCR_CR16_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCR_CR16_Msk) >> MCAN_TXBCR_CR16_Pos) /*!< CR16 Get Value            */


#define MCAN_TXBCR_CR15_Pos (15U)                         /*!< CR15 Postion   15         */
#define MCAN_TXBCR_CR15_Msk (0x1U << MCAN_TXBCR_CR15_Pos) /*!< CR15 Mask      0x00008000 */
#define MCAN_TXBCR_CR15_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCR_CR15_Pos) & MCAN_TXBCR_CR15_Msk) /*!< CR15 Set Value            */
#define MCAN_TXBCR_CR15_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCR_CR15_Msk) >> MCAN_TXBCR_CR15_Pos) /*!< CR15 Get Value            */


#define MCAN_TXBCR_CR14_Pos (14U)                         /*!< CR14 Postion   14         */
#define MCAN_TXBCR_CR14_Msk (0x1U << MCAN_TXBCR_CR14_Pos) /*!< CR14 Mask      0x00004000 */
#define MCAN_TXBCR_CR14_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCR_CR14_Pos) & MCAN_TXBCR_CR14_Msk) /*!< CR14 Set Value            */
#define MCAN_TXBCR_CR14_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCR_CR14_Msk) >> MCAN_TXBCR_CR14_Pos) /*!< CR14 Get Value            */


#define MCAN_TXBCR_CR13_Pos (13U)                         /*!< CR13 Postion   13         */
#define MCAN_TXBCR_CR13_Msk (0x1U << MCAN_TXBCR_CR13_Pos) /*!< CR13 Mask      0x00002000 */
#define MCAN_TXBCR_CR13_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCR_CR13_Pos) & MCAN_TXBCR_CR13_Msk) /*!< CR13 Set Value            */
#define MCAN_TXBCR_CR13_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCR_CR13_Msk) >> MCAN_TXBCR_CR13_Pos) /*!< CR13 Get Value            */


#define MCAN_TXBCR_CR12_Pos (12U)                         /*!< CR12 Postion   12         */
#define MCAN_TXBCR_CR12_Msk (0x1U << MCAN_TXBCR_CR12_Pos) /*!< CR12 Mask      0x00001000 */
#define MCAN_TXBCR_CR12_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCR_CR12_Pos) & MCAN_TXBCR_CR12_Msk) /*!< CR12 Set Value            */
#define MCAN_TXBCR_CR12_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCR_CR12_Msk) >> MCAN_TXBCR_CR12_Pos) /*!< CR12 Get Value            */


#define MCAN_TXBCR_CR11_Pos (11U)                         /*!< CR11 Postion   11         */
#define MCAN_TXBCR_CR11_Msk (0x1U << MCAN_TXBCR_CR11_Pos) /*!< CR11 Mask      0x00000800 */
#define MCAN_TXBCR_CR11_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCR_CR11_Pos) & MCAN_TXBCR_CR11_Msk) /*!< CR11 Set Value            */
#define MCAN_TXBCR_CR11_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCR_CR11_Msk) >> MCAN_TXBCR_CR11_Pos) /*!< CR11 Get Value            */


#define MCAN_TXBCR_CR10_Pos (10U)                         /*!< CR10 Postion   10         */
#define MCAN_TXBCR_CR10_Msk (0x1U << MCAN_TXBCR_CR10_Pos) /*!< CR10 Mask      0x00000400 */
#define MCAN_TXBCR_CR10_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCR_CR10_Pos) & MCAN_TXBCR_CR10_Msk) /*!< CR10 Set Value            */
#define MCAN_TXBCR_CR10_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCR_CR10_Msk) >> MCAN_TXBCR_CR10_Pos) /*!< CR10 Get Value            */


#define MCAN_TXBCR_CR9_Pos (9U)                         /*!< CR9 Postion   9          */
#define MCAN_TXBCR_CR9_Msk (0x1U << MCAN_TXBCR_CR9_Pos) /*!< CR9 Mask      0x00000200 */
#define MCAN_TXBCR_CR9_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCR_CR9_Pos) & MCAN_TXBCR_CR9_Msk) /*!< CR9 Set Value            */
#define MCAN_TXBCR_CR9_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCR_CR9_Msk) >> MCAN_TXBCR_CR9_Pos) /*!< CR9 Get Value            */


#define MCAN_TXBCR_CR8_Pos (8U)                         /*!< CR8 Postion   8          */
#define MCAN_TXBCR_CR8_Msk (0x1U << MCAN_TXBCR_CR8_Pos) /*!< CR8 Mask      0x00000100 */
#define MCAN_TXBCR_CR8_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCR_CR8_Pos) & MCAN_TXBCR_CR8_Msk) /*!< CR8 Set Value            */
#define MCAN_TXBCR_CR8_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCR_CR8_Msk) >> MCAN_TXBCR_CR8_Pos) /*!< CR8 Get Value            */


#define MCAN_TXBCR_CR7_Pos (7U)                         /*!< CR7 Postion   7          */
#define MCAN_TXBCR_CR7_Msk (0x1U << MCAN_TXBCR_CR7_Pos) /*!< CR7 Mask      0x00000080 */
#define MCAN_TXBCR_CR7_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCR_CR7_Pos) & MCAN_TXBCR_CR7_Msk) /*!< CR7 Set Value            */
#define MCAN_TXBCR_CR7_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCR_CR7_Msk) >> MCAN_TXBCR_CR7_Pos) /*!< CR7 Get Value            */


#define MCAN_TXBCR_CR6_Pos (6U)                         /*!< CR6 Postion   6          */
#define MCAN_TXBCR_CR6_Msk (0x1U << MCAN_TXBCR_CR6_Pos) /*!< CR6 Mask      0x00000040 */
#define MCAN_TXBCR_CR6_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCR_CR6_Pos) & MCAN_TXBCR_CR6_Msk) /*!< CR6 Set Value            */
#define MCAN_TXBCR_CR6_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCR_CR6_Msk) >> MCAN_TXBCR_CR6_Pos) /*!< CR6 Get Value            */


#define MCAN_TXBCR_CR5_Pos (5U)                         /*!< CR5 Postion   5          */
#define MCAN_TXBCR_CR5_Msk (0x1U << MCAN_TXBCR_CR5_Pos) /*!< CR5 Mask      0x00000020 */
#define MCAN_TXBCR_CR5_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCR_CR5_Pos) & MCAN_TXBCR_CR5_Msk) /*!< CR5 Set Value            */
#define MCAN_TXBCR_CR5_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCR_CR5_Msk) >> MCAN_TXBCR_CR5_Pos) /*!< CR5 Get Value            */


#define MCAN_TXBCR_CR4_Pos (4U)                         /*!< CR4 Postion   4          */
#define MCAN_TXBCR_CR4_Msk (0x1U << MCAN_TXBCR_CR4_Pos) /*!< CR4 Mask      0x00000010 */
#define MCAN_TXBCR_CR4_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCR_CR4_Pos) & MCAN_TXBCR_CR4_Msk) /*!< CR4 Set Value            */
#define MCAN_TXBCR_CR4_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCR_CR4_Msk) >> MCAN_TXBCR_CR4_Pos) /*!< CR4 Get Value            */


#define MCAN_TXBCR_CR3_Pos (3U)                         /*!< CR3 Postion   3          */
#define MCAN_TXBCR_CR3_Msk (0x1U << MCAN_TXBCR_CR3_Pos) /*!< CR3 Mask      0x00000008 */
#define MCAN_TXBCR_CR3_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCR_CR3_Pos) & MCAN_TXBCR_CR3_Msk) /*!< CR3 Set Value            */
#define MCAN_TXBCR_CR3_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCR_CR3_Msk) >> MCAN_TXBCR_CR3_Pos) /*!< CR3 Get Value            */


#define MCAN_TXBCR_CR2_Pos (2U)                         /*!< CR2 Postion   2          */
#define MCAN_TXBCR_CR2_Msk (0x1U << MCAN_TXBCR_CR2_Pos) /*!< CR2 Mask      0x00000004 */
#define MCAN_TXBCR_CR2_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCR_CR2_Pos) & MCAN_TXBCR_CR2_Msk) /*!< CR2 Set Value            */
#define MCAN_TXBCR_CR2_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCR_CR2_Msk) >> MCAN_TXBCR_CR2_Pos) /*!< CR2 Get Value            */


#define MCAN_TXBCR_CR1_Pos (1U)                         /*!< CR1 Postion   1          */
#define MCAN_TXBCR_CR1_Msk (0x1U << MCAN_TXBCR_CR1_Pos) /*!< CR1 Mask      0x00000002 */
#define MCAN_TXBCR_CR1_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCR_CR1_Pos) & MCAN_TXBCR_CR1_Msk) /*!< CR1 Set Value            */
#define MCAN_TXBCR_CR1_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCR_CR1_Msk) >> MCAN_TXBCR_CR1_Pos) /*!< CR1 Get Value            */


#define MCAN_TXBCR_CR0_Pos (0U)                         /*!< CR0 Postion   0          */
#define MCAN_TXBCR_CR0_Msk (0x1U << MCAN_TXBCR_CR0_Pos) /*!< CR0 Mask      0x00000001 */
#define MCAN_TXBCR_CR0_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCR_CR0_Pos) & MCAN_TXBCR_CR0_Msk) /*!< CR0 Set Value            */
#define MCAN_TXBCR_CR0_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCR_CR0_Msk) >> MCAN_TXBCR_CR0_Pos) /*!< CR0 Get Value            */


/* TXBTO bitfield */
#define MCAN_TXBTO_TO31_Pos (31U)                         /*!< TO31 Postion   31         */
#define MCAN_TXBTO_TO31_Msk (0x1U << MCAN_TXBTO_TO31_Pos) /*!< TO31 Mask      0x80000000 */
#define MCAN_TXBTO_TO31_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTO_TO31_Pos) & MCAN_TXBTO_TO31_Msk) /*!< TO31 Set Value            */
#define MCAN_TXBTO_TO31_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTO_TO31_Msk) >> MCAN_TXBTO_TO31_Pos) /*!< TO31 Get Value            */


#define MCAN_TXBTO_TO30_Pos (30U)                         /*!< TO30 Postion   30         */
#define MCAN_TXBTO_TO30_Msk (0x1U << MCAN_TXBTO_TO30_Pos) /*!< TO30 Mask      0x40000000 */
#define MCAN_TXBTO_TO30_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTO_TO30_Pos) & MCAN_TXBTO_TO30_Msk) /*!< TO30 Set Value            */
#define MCAN_TXBTO_TO30_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTO_TO30_Msk) >> MCAN_TXBTO_TO30_Pos) /*!< TO30 Get Value            */


#define MCAN_TXBTO_TO29_Pos (29U)                         /*!< TO29 Postion   29         */
#define MCAN_TXBTO_TO29_Msk (0x1U << MCAN_TXBTO_TO29_Pos) /*!< TO29 Mask      0x20000000 */
#define MCAN_TXBTO_TO29_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTO_TO29_Pos) & MCAN_TXBTO_TO29_Msk) /*!< TO29 Set Value            */
#define MCAN_TXBTO_TO29_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTO_TO29_Msk) >> MCAN_TXBTO_TO29_Pos) /*!< TO29 Get Value            */


#define MCAN_TXBTO_TO28_Pos (28U)                         /*!< TO28 Postion   28         */
#define MCAN_TXBTO_TO28_Msk (0x1U << MCAN_TXBTO_TO28_Pos) /*!< TO28 Mask      0x10000000 */
#define MCAN_TXBTO_TO28_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTO_TO28_Pos) & MCAN_TXBTO_TO28_Msk) /*!< TO28 Set Value            */
#define MCAN_TXBTO_TO28_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTO_TO28_Msk) >> MCAN_TXBTO_TO28_Pos) /*!< TO28 Get Value            */


#define MCAN_TXBTO_TO27_Pos (27U)                         /*!< TO27 Postion   27         */
#define MCAN_TXBTO_TO27_Msk (0x1U << MCAN_TXBTO_TO27_Pos) /*!< TO27 Mask      0x08000000 */
#define MCAN_TXBTO_TO27_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTO_TO27_Pos) & MCAN_TXBTO_TO27_Msk) /*!< TO27 Set Value            */
#define MCAN_TXBTO_TO27_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTO_TO27_Msk) >> MCAN_TXBTO_TO27_Pos) /*!< TO27 Get Value            */


#define MCAN_TXBTO_TO26_Pos (26U)                         /*!< TO26 Postion   26         */
#define MCAN_TXBTO_TO26_Msk (0x1U << MCAN_TXBTO_TO26_Pos) /*!< TO26 Mask      0x04000000 */
#define MCAN_TXBTO_TO26_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTO_TO26_Pos) & MCAN_TXBTO_TO26_Msk) /*!< TO26 Set Value            */
#define MCAN_TXBTO_TO26_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTO_TO26_Msk) >> MCAN_TXBTO_TO26_Pos) /*!< TO26 Get Value            */


#define MCAN_TXBTO_TO25_Pos (25U)                         /*!< TO25 Postion   25         */
#define MCAN_TXBTO_TO25_Msk (0x1U << MCAN_TXBTO_TO25_Pos) /*!< TO25 Mask      0x02000000 */
#define MCAN_TXBTO_TO25_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTO_TO25_Pos) & MCAN_TXBTO_TO25_Msk) /*!< TO25 Set Value            */
#define MCAN_TXBTO_TO25_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTO_TO25_Msk) >> MCAN_TXBTO_TO25_Pos) /*!< TO25 Get Value            */


#define MCAN_TXBTO_TO24_Pos (24U)                         /*!< TO24 Postion   24         */
#define MCAN_TXBTO_TO24_Msk (0x1U << MCAN_TXBTO_TO24_Pos) /*!< TO24 Mask      0x01000000 */
#define MCAN_TXBTO_TO24_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTO_TO24_Pos) & MCAN_TXBTO_TO24_Msk) /*!< TO24 Set Value            */
#define MCAN_TXBTO_TO24_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTO_TO24_Msk) >> MCAN_TXBTO_TO24_Pos) /*!< TO24 Get Value            */


#define MCAN_TXBTO_TO23_Pos (23U)                         /*!< TO23 Postion   23         */
#define MCAN_TXBTO_TO23_Msk (0x1U << MCAN_TXBTO_TO23_Pos) /*!< TO23 Mask      0x00800000 */
#define MCAN_TXBTO_TO23_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTO_TO23_Pos) & MCAN_TXBTO_TO23_Msk) /*!< TO23 Set Value            */
#define MCAN_TXBTO_TO23_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTO_TO23_Msk) >> MCAN_TXBTO_TO23_Pos) /*!< TO23 Get Value            */


#define MCAN_TXBTO_TO22_Pos (22U)                         /*!< TO22 Postion   22         */
#define MCAN_TXBTO_TO22_Msk (0x1U << MCAN_TXBTO_TO22_Pos) /*!< TO22 Mask      0x00400000 */
#define MCAN_TXBTO_TO22_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTO_TO22_Pos) & MCAN_TXBTO_TO22_Msk) /*!< TO22 Set Value            */
#define MCAN_TXBTO_TO22_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTO_TO22_Msk) >> MCAN_TXBTO_TO22_Pos) /*!< TO22 Get Value            */


#define MCAN_TXBTO_TO21_Pos (21U)                         /*!< TO21 Postion   21         */
#define MCAN_TXBTO_TO21_Msk (0x1U << MCAN_TXBTO_TO21_Pos) /*!< TO21 Mask      0x00200000 */
#define MCAN_TXBTO_TO21_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTO_TO21_Pos) & MCAN_TXBTO_TO21_Msk) /*!< TO21 Set Value            */
#define MCAN_TXBTO_TO21_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTO_TO21_Msk) >> MCAN_TXBTO_TO21_Pos) /*!< TO21 Get Value            */


#define MCAN_TXBTO_TO20_Pos (20U)                         /*!< TO20 Postion   20         */
#define MCAN_TXBTO_TO20_Msk (0x1U << MCAN_TXBTO_TO20_Pos) /*!< TO20 Mask      0x00100000 */
#define MCAN_TXBTO_TO20_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTO_TO20_Pos) & MCAN_TXBTO_TO20_Msk) /*!< TO20 Set Value            */
#define MCAN_TXBTO_TO20_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTO_TO20_Msk) >> MCAN_TXBTO_TO20_Pos) /*!< TO20 Get Value            */


#define MCAN_TXBTO_TO19_Pos (19U)                         /*!< TO19 Postion   19         */
#define MCAN_TXBTO_TO19_Msk (0x1U << MCAN_TXBTO_TO19_Pos) /*!< TO19 Mask      0x00080000 */
#define MCAN_TXBTO_TO19_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTO_TO19_Pos) & MCAN_TXBTO_TO19_Msk) /*!< TO19 Set Value            */
#define MCAN_TXBTO_TO19_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTO_TO19_Msk) >> MCAN_TXBTO_TO19_Pos) /*!< TO19 Get Value            */


#define MCAN_TXBTO_TO18_Pos (18U)                         /*!< TO18 Postion   18         */
#define MCAN_TXBTO_TO18_Msk (0x1U << MCAN_TXBTO_TO18_Pos) /*!< TO18 Mask      0x00040000 */
#define MCAN_TXBTO_TO18_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTO_TO18_Pos) & MCAN_TXBTO_TO18_Msk) /*!< TO18 Set Value            */
#define MCAN_TXBTO_TO18_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTO_TO18_Msk) >> MCAN_TXBTO_TO18_Pos) /*!< TO18 Get Value            */


#define MCAN_TXBTO_TO17_Pos (17U)                         /*!< TO17 Postion   17         */
#define MCAN_TXBTO_TO17_Msk (0x1U << MCAN_TXBTO_TO17_Pos) /*!< TO17 Mask      0x00020000 */
#define MCAN_TXBTO_TO17_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTO_TO17_Pos) & MCAN_TXBTO_TO17_Msk) /*!< TO17 Set Value            */
#define MCAN_TXBTO_TO17_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTO_TO17_Msk) >> MCAN_TXBTO_TO17_Pos) /*!< TO17 Get Value            */


#define MCAN_TXBTO_TO16_Pos (16U)                         /*!< TO16 Postion   16         */
#define MCAN_TXBTO_TO16_Msk (0x1U << MCAN_TXBTO_TO16_Pos) /*!< TO16 Mask      0x00010000 */
#define MCAN_TXBTO_TO16_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTO_TO16_Pos) & MCAN_TXBTO_TO16_Msk) /*!< TO16 Set Value            */
#define MCAN_TXBTO_TO16_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTO_TO16_Msk) >> MCAN_TXBTO_TO16_Pos) /*!< TO16 Get Value            */


#define MCAN_TXBTO_TO15_Pos (15U)                         /*!< TO15 Postion   15         */
#define MCAN_TXBTO_TO15_Msk (0x1U << MCAN_TXBTO_TO15_Pos) /*!< TO15 Mask      0x00008000 */
#define MCAN_TXBTO_TO15_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTO_TO15_Pos) & MCAN_TXBTO_TO15_Msk) /*!< TO15 Set Value            */
#define MCAN_TXBTO_TO15_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTO_TO15_Msk) >> MCAN_TXBTO_TO15_Pos) /*!< TO15 Get Value            */


#define MCAN_TXBTO_TO14_Pos (14U)                         /*!< TO14 Postion   14         */
#define MCAN_TXBTO_TO14_Msk (0x1U << MCAN_TXBTO_TO14_Pos) /*!< TO14 Mask      0x00004000 */
#define MCAN_TXBTO_TO14_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTO_TO14_Pos) & MCAN_TXBTO_TO14_Msk) /*!< TO14 Set Value            */
#define MCAN_TXBTO_TO14_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTO_TO14_Msk) >> MCAN_TXBTO_TO14_Pos) /*!< TO14 Get Value            */


#define MCAN_TXBTO_TO13_Pos (13U)                         /*!< TO13 Postion   13         */
#define MCAN_TXBTO_TO13_Msk (0x1U << MCAN_TXBTO_TO13_Pos) /*!< TO13 Mask      0x00002000 */
#define MCAN_TXBTO_TO13_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTO_TO13_Pos) & MCAN_TXBTO_TO13_Msk) /*!< TO13 Set Value            */
#define MCAN_TXBTO_TO13_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTO_TO13_Msk) >> MCAN_TXBTO_TO13_Pos) /*!< TO13 Get Value            */


#define MCAN_TXBTO_TO12_Pos (12U)                         /*!< TO12 Postion   12         */
#define MCAN_TXBTO_TO12_Msk (0x1U << MCAN_TXBTO_TO12_Pos) /*!< TO12 Mask      0x00001000 */
#define MCAN_TXBTO_TO12_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTO_TO12_Pos) & MCAN_TXBTO_TO12_Msk) /*!< TO12 Set Value            */
#define MCAN_TXBTO_TO12_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTO_TO12_Msk) >> MCAN_TXBTO_TO12_Pos) /*!< TO12 Get Value            */


#define MCAN_TXBTO_TO11_Pos (11U)                         /*!< TO11 Postion   11         */
#define MCAN_TXBTO_TO11_Msk (0x1U << MCAN_TXBTO_TO11_Pos) /*!< TO11 Mask      0x00000800 */
#define MCAN_TXBTO_TO11_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTO_TO11_Pos) & MCAN_TXBTO_TO11_Msk) /*!< TO11 Set Value            */
#define MCAN_TXBTO_TO11_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTO_TO11_Msk) >> MCAN_TXBTO_TO11_Pos) /*!< TO11 Get Value            */


#define MCAN_TXBTO_TO10_Pos (10U)                         /*!< TO10 Postion   10         */
#define MCAN_TXBTO_TO10_Msk (0x1U << MCAN_TXBTO_TO10_Pos) /*!< TO10 Mask      0x00000400 */
#define MCAN_TXBTO_TO10_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTO_TO10_Pos) & MCAN_TXBTO_TO10_Msk) /*!< TO10 Set Value            */
#define MCAN_TXBTO_TO10_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTO_TO10_Msk) >> MCAN_TXBTO_TO10_Pos) /*!< TO10 Get Value            */


#define MCAN_TXBTO_TO9_Pos (9U)                         /*!< TO9 Postion   9          */
#define MCAN_TXBTO_TO9_Msk (0x1U << MCAN_TXBTO_TO9_Pos) /*!< TO9 Mask      0x00000200 */
#define MCAN_TXBTO_TO9_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTO_TO9_Pos) & MCAN_TXBTO_TO9_Msk) /*!< TO9 Set Value            */
#define MCAN_TXBTO_TO9_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTO_TO9_Msk) >> MCAN_TXBTO_TO9_Pos) /*!< TO9 Get Value            */


#define MCAN_TXBTO_TO8_Pos (8U)                         /*!< TO8 Postion   8          */
#define MCAN_TXBTO_TO8_Msk (0x1U << MCAN_TXBTO_TO8_Pos) /*!< TO8 Mask      0x00000100 */
#define MCAN_TXBTO_TO8_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTO_TO8_Pos) & MCAN_TXBTO_TO8_Msk) /*!< TO8 Set Value            */
#define MCAN_TXBTO_TO8_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTO_TO8_Msk) >> MCAN_TXBTO_TO8_Pos) /*!< TO8 Get Value            */


#define MCAN_TXBTO_TO7_Pos (7U)                         /*!< TO7 Postion   7          */
#define MCAN_TXBTO_TO7_Msk (0x1U << MCAN_TXBTO_TO7_Pos) /*!< TO7 Mask      0x00000080 */
#define MCAN_TXBTO_TO7_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTO_TO7_Pos) & MCAN_TXBTO_TO7_Msk) /*!< TO7 Set Value            */
#define MCAN_TXBTO_TO7_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTO_TO7_Msk) >> MCAN_TXBTO_TO7_Pos) /*!< TO7 Get Value            */


#define MCAN_TXBTO_TO6_Pos (6U)                         /*!< TO6 Postion   6          */
#define MCAN_TXBTO_TO6_Msk (0x1U << MCAN_TXBTO_TO6_Pos) /*!< TO6 Mask      0x00000040 */
#define MCAN_TXBTO_TO6_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTO_TO6_Pos) & MCAN_TXBTO_TO6_Msk) /*!< TO6 Set Value            */
#define MCAN_TXBTO_TO6_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTO_TO6_Msk) >> MCAN_TXBTO_TO6_Pos) /*!< TO6 Get Value            */


#define MCAN_TXBTO_TO5_Pos (5U)                         /*!< TO5 Postion   5          */
#define MCAN_TXBTO_TO5_Msk (0x1U << MCAN_TXBTO_TO5_Pos) /*!< TO5 Mask      0x00000020 */
#define MCAN_TXBTO_TO5_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTO_TO5_Pos) & MCAN_TXBTO_TO5_Msk) /*!< TO5 Set Value            */
#define MCAN_TXBTO_TO5_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTO_TO5_Msk) >> MCAN_TXBTO_TO5_Pos) /*!< TO5 Get Value            */


#define MCAN_TXBTO_TO4_Pos (4U)                         /*!< TO4 Postion   4          */
#define MCAN_TXBTO_TO4_Msk (0x1U << MCAN_TXBTO_TO4_Pos) /*!< TO4 Mask      0x00000010 */
#define MCAN_TXBTO_TO4_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTO_TO4_Pos) & MCAN_TXBTO_TO4_Msk) /*!< TO4 Set Value            */
#define MCAN_TXBTO_TO4_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTO_TO4_Msk) >> MCAN_TXBTO_TO4_Pos) /*!< TO4 Get Value            */


#define MCAN_TXBTO_TO3_Pos (3U)                         /*!< TO3 Postion   3          */
#define MCAN_TXBTO_TO3_Msk (0x1U << MCAN_TXBTO_TO3_Pos) /*!< TO3 Mask      0x00000008 */
#define MCAN_TXBTO_TO3_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTO_TO3_Pos) & MCAN_TXBTO_TO3_Msk) /*!< TO3 Set Value            */
#define MCAN_TXBTO_TO3_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTO_TO3_Msk) >> MCAN_TXBTO_TO3_Pos) /*!< TO3 Get Value            */


#define MCAN_TXBTO_TO2_Pos (2U)                         /*!< TO2 Postion   2          */
#define MCAN_TXBTO_TO2_Msk (0x1U << MCAN_TXBTO_TO2_Pos) /*!< TO2 Mask      0x00000004 */
#define MCAN_TXBTO_TO2_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTO_TO2_Pos) & MCAN_TXBTO_TO2_Msk) /*!< TO2 Set Value            */
#define MCAN_TXBTO_TO2_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTO_TO2_Msk) >> MCAN_TXBTO_TO2_Pos) /*!< TO2 Get Value            */


#define MCAN_TXBTO_TO1_Pos (1U)                         /*!< TO1 Postion   1          */
#define MCAN_TXBTO_TO1_Msk (0x1U << MCAN_TXBTO_TO1_Pos) /*!< TO1 Mask      0x00000002 */
#define MCAN_TXBTO_TO1_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTO_TO1_Pos) & MCAN_TXBTO_TO1_Msk) /*!< TO1 Set Value            */
#define MCAN_TXBTO_TO1_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTO_TO1_Msk) >> MCAN_TXBTO_TO1_Pos) /*!< TO1 Get Value            */


#define MCAN_TXBTO_TO0_Pos (0U)                         /*!< TO0 Postion   0          */
#define MCAN_TXBTO_TO0_Msk (0x1U << MCAN_TXBTO_TO0_Pos) /*!< TO0 Mask      0x00000001 */
#define MCAN_TXBTO_TO0_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTO_TO0_Pos) & MCAN_TXBTO_TO0_Msk) /*!< TO0 Set Value            */
#define MCAN_TXBTO_TO0_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTO_TO0_Msk) >> MCAN_TXBTO_TO0_Pos) /*!< TO0 Get Value            */


/* TXBCF bitfield */
#define MCAN_TXBCF_CF31_Pos (31U)                         /*!< CF31 Postion   31         */
#define MCAN_TXBCF_CF31_Msk (0x1U << MCAN_TXBCF_CF31_Pos) /*!< CF31 Mask      0x80000000 */
#define MCAN_TXBCF_CF31_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCF_CF31_Pos) & MCAN_TXBCF_CF31_Msk) /*!< CF31 Set Value            */
#define MCAN_TXBCF_CF31_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCF_CF31_Msk) >> MCAN_TXBCF_CF31_Pos) /*!< CF31 Get Value            */


#define MCAN_TXBCF_CF30_Pos (30U)                         /*!< CF30 Postion   30         */
#define MCAN_TXBCF_CF30_Msk (0x1U << MCAN_TXBCF_CF30_Pos) /*!< CF30 Mask      0x40000000 */
#define MCAN_TXBCF_CF30_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCF_CF30_Pos) & MCAN_TXBCF_CF30_Msk) /*!< CF30 Set Value            */
#define MCAN_TXBCF_CF30_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCF_CF30_Msk) >> MCAN_TXBCF_CF30_Pos) /*!< CF30 Get Value            */


#define MCAN_TXBCF_CF29_Pos (29U)                         /*!< CF29 Postion   29         */
#define MCAN_TXBCF_CF29_Msk (0x1U << MCAN_TXBCF_CF29_Pos) /*!< CF29 Mask      0x20000000 */
#define MCAN_TXBCF_CF29_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCF_CF29_Pos) & MCAN_TXBCF_CF29_Msk) /*!< CF29 Set Value            */
#define MCAN_TXBCF_CF29_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCF_CF29_Msk) >> MCAN_TXBCF_CF29_Pos) /*!< CF29 Get Value            */


#define MCAN_TXBCF_CF28_Pos (28U)                         /*!< CF28 Postion   28         */
#define MCAN_TXBCF_CF28_Msk (0x1U << MCAN_TXBCF_CF28_Pos) /*!< CF28 Mask      0x10000000 */
#define MCAN_TXBCF_CF28_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCF_CF28_Pos) & MCAN_TXBCF_CF28_Msk) /*!< CF28 Set Value            */
#define MCAN_TXBCF_CF28_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCF_CF28_Msk) >> MCAN_TXBCF_CF28_Pos) /*!< CF28 Get Value            */


#define MCAN_TXBCF_CF27_Pos (27U)                         /*!< CF27 Postion   27         */
#define MCAN_TXBCF_CF27_Msk (0x1U << MCAN_TXBCF_CF27_Pos) /*!< CF27 Mask      0x08000000 */
#define MCAN_TXBCF_CF27_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCF_CF27_Pos) & MCAN_TXBCF_CF27_Msk) /*!< CF27 Set Value            */
#define MCAN_TXBCF_CF27_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCF_CF27_Msk) >> MCAN_TXBCF_CF27_Pos) /*!< CF27 Get Value            */


#define MCAN_TXBCF_CF26_Pos (26U)                         /*!< CF26 Postion   26         */
#define MCAN_TXBCF_CF26_Msk (0x1U << MCAN_TXBCF_CF26_Pos) /*!< CF26 Mask      0x04000000 */
#define MCAN_TXBCF_CF26_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCF_CF26_Pos) & MCAN_TXBCF_CF26_Msk) /*!< CF26 Set Value            */
#define MCAN_TXBCF_CF26_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCF_CF26_Msk) >> MCAN_TXBCF_CF26_Pos) /*!< CF26 Get Value            */


#define MCAN_TXBCF_CF25_Pos (25U)                         /*!< CF25 Postion   25         */
#define MCAN_TXBCF_CF25_Msk (0x1U << MCAN_TXBCF_CF25_Pos) /*!< CF25 Mask      0x02000000 */
#define MCAN_TXBCF_CF25_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCF_CF25_Pos) & MCAN_TXBCF_CF25_Msk) /*!< CF25 Set Value            */
#define MCAN_TXBCF_CF25_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCF_CF25_Msk) >> MCAN_TXBCF_CF25_Pos) /*!< CF25 Get Value            */


#define MCAN_TXBCF_CF24_Pos (24U)                         /*!< CF24 Postion   24         */
#define MCAN_TXBCF_CF24_Msk (0x1U << MCAN_TXBCF_CF24_Pos) /*!< CF24 Mask      0x01000000 */
#define MCAN_TXBCF_CF24_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCF_CF24_Pos) & MCAN_TXBCF_CF24_Msk) /*!< CF24 Set Value            */
#define MCAN_TXBCF_CF24_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCF_CF24_Msk) >> MCAN_TXBCF_CF24_Pos) /*!< CF24 Get Value            */


#define MCAN_TXBCF_CF23_Pos (23U)                         /*!< CF23 Postion   23         */
#define MCAN_TXBCF_CF23_Msk (0x1U << MCAN_TXBCF_CF23_Pos) /*!< CF23 Mask      0x00800000 */
#define MCAN_TXBCF_CF23_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCF_CF23_Pos) & MCAN_TXBCF_CF23_Msk) /*!< CF23 Set Value            */
#define MCAN_TXBCF_CF23_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCF_CF23_Msk) >> MCAN_TXBCF_CF23_Pos) /*!< CF23 Get Value            */


#define MCAN_TXBCF_CF22_Pos (22U)                         /*!< CF22 Postion   22         */
#define MCAN_TXBCF_CF22_Msk (0x1U << MCAN_TXBCF_CF22_Pos) /*!< CF22 Mask      0x00400000 */
#define MCAN_TXBCF_CF22_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCF_CF22_Pos) & MCAN_TXBCF_CF22_Msk) /*!< CF22 Set Value            */
#define MCAN_TXBCF_CF22_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCF_CF22_Msk) >> MCAN_TXBCF_CF22_Pos) /*!< CF22 Get Value            */


#define MCAN_TXBCF_CF21_Pos (21U)                         /*!< CF21 Postion   21         */
#define MCAN_TXBCF_CF21_Msk (0x1U << MCAN_TXBCF_CF21_Pos) /*!< CF21 Mask      0x00200000 */
#define MCAN_TXBCF_CF21_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCF_CF21_Pos) & MCAN_TXBCF_CF21_Msk) /*!< CF21 Set Value            */
#define MCAN_TXBCF_CF21_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCF_CF21_Msk) >> MCAN_TXBCF_CF21_Pos) /*!< CF21 Get Value            */


#define MCAN_TXBCF_CF20_Pos (20U)                         /*!< CF20 Postion   20         */
#define MCAN_TXBCF_CF20_Msk (0x1U << MCAN_TXBCF_CF20_Pos) /*!< CF20 Mask      0x00100000 */
#define MCAN_TXBCF_CF20_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCF_CF20_Pos) & MCAN_TXBCF_CF20_Msk) /*!< CF20 Set Value            */
#define MCAN_TXBCF_CF20_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCF_CF20_Msk) >> MCAN_TXBCF_CF20_Pos) /*!< CF20 Get Value            */


#define MCAN_TXBCF_CF19_Pos (19U)                         /*!< CF19 Postion   19         */
#define MCAN_TXBCF_CF19_Msk (0x1U << MCAN_TXBCF_CF19_Pos) /*!< CF19 Mask      0x00080000 */
#define MCAN_TXBCF_CF19_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCF_CF19_Pos) & MCAN_TXBCF_CF19_Msk) /*!< CF19 Set Value            */
#define MCAN_TXBCF_CF19_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCF_CF19_Msk) >> MCAN_TXBCF_CF19_Pos) /*!< CF19 Get Value            */


#define MCAN_TXBCF_CF18_Pos (18U)                         /*!< CF18 Postion   18         */
#define MCAN_TXBCF_CF18_Msk (0x1U << MCAN_TXBCF_CF18_Pos) /*!< CF18 Mask      0x00040000 */
#define MCAN_TXBCF_CF18_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCF_CF18_Pos) & MCAN_TXBCF_CF18_Msk) /*!< CF18 Set Value            */
#define MCAN_TXBCF_CF18_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCF_CF18_Msk) >> MCAN_TXBCF_CF18_Pos) /*!< CF18 Get Value            */


#define MCAN_TXBCF_CF17_Pos (17U)                         /*!< CF17 Postion   17         */
#define MCAN_TXBCF_CF17_Msk (0x1U << MCAN_TXBCF_CF17_Pos) /*!< CF17 Mask      0x00020000 */
#define MCAN_TXBCF_CF17_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCF_CF17_Pos) & MCAN_TXBCF_CF17_Msk) /*!< CF17 Set Value            */
#define MCAN_TXBCF_CF17_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCF_CF17_Msk) >> MCAN_TXBCF_CF17_Pos) /*!< CF17 Get Value            */


#define MCAN_TXBCF_CF16_Pos (16U)                         /*!< CF16 Postion   16         */
#define MCAN_TXBCF_CF16_Msk (0x1U << MCAN_TXBCF_CF16_Pos) /*!< CF16 Mask      0x00010000 */
#define MCAN_TXBCF_CF16_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCF_CF16_Pos) & MCAN_TXBCF_CF16_Msk) /*!< CF16 Set Value            */
#define MCAN_TXBCF_CF16_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCF_CF16_Msk) >> MCAN_TXBCF_CF16_Pos) /*!< CF16 Get Value            */


#define MCAN_TXBCF_CF15_Pos (15U)                         /*!< CF15 Postion   15         */
#define MCAN_TXBCF_CF15_Msk (0x1U << MCAN_TXBCF_CF15_Pos) /*!< CF15 Mask      0x00008000 */
#define MCAN_TXBCF_CF15_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCF_CF15_Pos) & MCAN_TXBCF_CF15_Msk) /*!< CF15 Set Value            */
#define MCAN_TXBCF_CF15_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCF_CF15_Msk) >> MCAN_TXBCF_CF15_Pos) /*!< CF15 Get Value            */


#define MCAN_TXBCF_CF14_Pos (14U)                         /*!< CF14 Postion   14         */
#define MCAN_TXBCF_CF14_Msk (0x1U << MCAN_TXBCF_CF14_Pos) /*!< CF14 Mask      0x00004000 */
#define MCAN_TXBCF_CF14_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCF_CF14_Pos) & MCAN_TXBCF_CF14_Msk) /*!< CF14 Set Value            */
#define MCAN_TXBCF_CF14_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCF_CF14_Msk) >> MCAN_TXBCF_CF14_Pos) /*!< CF14 Get Value            */


#define MCAN_TXBCF_CF13_Pos (13U)                         /*!< CF13 Postion   13         */
#define MCAN_TXBCF_CF13_Msk (0x1U << MCAN_TXBCF_CF13_Pos) /*!< CF13 Mask      0x00002000 */
#define MCAN_TXBCF_CF13_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCF_CF13_Pos) & MCAN_TXBCF_CF13_Msk) /*!< CF13 Set Value            */
#define MCAN_TXBCF_CF13_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCF_CF13_Msk) >> MCAN_TXBCF_CF13_Pos) /*!< CF13 Get Value            */


#define MCAN_TXBCF_CF12_Pos (12U)                         /*!< CF12 Postion   12         */
#define MCAN_TXBCF_CF12_Msk (0x1U << MCAN_TXBCF_CF12_Pos) /*!< CF12 Mask      0x00001000 */
#define MCAN_TXBCF_CF12_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCF_CF12_Pos) & MCAN_TXBCF_CF12_Msk) /*!< CF12 Set Value            */
#define MCAN_TXBCF_CF12_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCF_CF12_Msk) >> MCAN_TXBCF_CF12_Pos) /*!< CF12 Get Value            */


#define MCAN_TXBCF_CF11_Pos (11U)                         /*!< CF11 Postion   11         */
#define MCAN_TXBCF_CF11_Msk (0x1U << MCAN_TXBCF_CF11_Pos) /*!< CF11 Mask      0x00000800 */
#define MCAN_TXBCF_CF11_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCF_CF11_Pos) & MCAN_TXBCF_CF11_Msk) /*!< CF11 Set Value            */
#define MCAN_TXBCF_CF11_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCF_CF11_Msk) >> MCAN_TXBCF_CF11_Pos) /*!< CF11 Get Value            */


#define MCAN_TXBCF_CF10_Pos (10U)                         /*!< CF10 Postion   10         */
#define MCAN_TXBCF_CF10_Msk (0x1U << MCAN_TXBCF_CF10_Pos) /*!< CF10 Mask      0x00000400 */
#define MCAN_TXBCF_CF10_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCF_CF10_Pos) & MCAN_TXBCF_CF10_Msk) /*!< CF10 Set Value            */
#define MCAN_TXBCF_CF10_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCF_CF10_Msk) >> MCAN_TXBCF_CF10_Pos) /*!< CF10 Get Value            */


#define MCAN_TXBCF_CF9_Pos (9U)                         /*!< CF9 Postion   9          */
#define MCAN_TXBCF_CF9_Msk (0x1U << MCAN_TXBCF_CF9_Pos) /*!< CF9 Mask      0x00000200 */
#define MCAN_TXBCF_CF9_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCF_CF9_Pos) & MCAN_TXBCF_CF9_Msk) /*!< CF9 Set Value            */
#define MCAN_TXBCF_CF9_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCF_CF9_Msk) >> MCAN_TXBCF_CF9_Pos) /*!< CF9 Get Value            */


#define MCAN_TXBCF_CF8_Pos (8U)                         /*!< CF8 Postion   8          */
#define MCAN_TXBCF_CF8_Msk (0x1U << MCAN_TXBCF_CF8_Pos) /*!< CF8 Mask      0x00000100 */
#define MCAN_TXBCF_CF8_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCF_CF8_Pos) & MCAN_TXBCF_CF8_Msk) /*!< CF8 Set Value            */
#define MCAN_TXBCF_CF8_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCF_CF8_Msk) >> MCAN_TXBCF_CF8_Pos) /*!< CF8 Get Value            */


#define MCAN_TXBCF_CF7_Pos (7U)                         /*!< CF7 Postion   7          */
#define MCAN_TXBCF_CF7_Msk (0x1U << MCAN_TXBCF_CF7_Pos) /*!< CF7 Mask      0x00000080 */
#define MCAN_TXBCF_CF7_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCF_CF7_Pos) & MCAN_TXBCF_CF7_Msk) /*!< CF7 Set Value            */
#define MCAN_TXBCF_CF7_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCF_CF7_Msk) >> MCAN_TXBCF_CF7_Pos) /*!< CF7 Get Value            */


#define MCAN_TXBCF_CF6_Pos (6U)                         /*!< CF6 Postion   6          */
#define MCAN_TXBCF_CF6_Msk (0x1U << MCAN_TXBCF_CF6_Pos) /*!< CF6 Mask      0x00000040 */
#define MCAN_TXBCF_CF6_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCF_CF6_Pos) & MCAN_TXBCF_CF6_Msk) /*!< CF6 Set Value            */
#define MCAN_TXBCF_CF6_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCF_CF6_Msk) >> MCAN_TXBCF_CF6_Pos) /*!< CF6 Get Value            */


#define MCAN_TXBCF_CF5_Pos (5U)                         /*!< CF5 Postion   5          */
#define MCAN_TXBCF_CF5_Msk (0x1U << MCAN_TXBCF_CF5_Pos) /*!< CF5 Mask      0x00000020 */
#define MCAN_TXBCF_CF5_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCF_CF5_Pos) & MCAN_TXBCF_CF5_Msk) /*!< CF5 Set Value            */
#define MCAN_TXBCF_CF5_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCF_CF5_Msk) >> MCAN_TXBCF_CF5_Pos) /*!< CF5 Get Value            */


#define MCAN_TXBCF_CF4_Pos (4U)                         /*!< CF4 Postion   4          */
#define MCAN_TXBCF_CF4_Msk (0x1U << MCAN_TXBCF_CF4_Pos) /*!< CF4 Mask      0x00000010 */
#define MCAN_TXBCF_CF4_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCF_CF4_Pos) & MCAN_TXBCF_CF4_Msk) /*!< CF4 Set Value            */
#define MCAN_TXBCF_CF4_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCF_CF4_Msk) >> MCAN_TXBCF_CF4_Pos) /*!< CF4 Get Value            */


#define MCAN_TXBCF_CF3_Pos (3U)                         /*!< CF3 Postion   3          */
#define MCAN_TXBCF_CF3_Msk (0x1U << MCAN_TXBCF_CF3_Pos) /*!< CF3 Mask      0x00000008 */
#define MCAN_TXBCF_CF3_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCF_CF3_Pos) & MCAN_TXBCF_CF3_Msk) /*!< CF3 Set Value            */
#define MCAN_TXBCF_CF3_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCF_CF3_Msk) >> MCAN_TXBCF_CF3_Pos) /*!< CF3 Get Value            */


#define MCAN_TXBCF_CF2_Pos (2U)                         /*!< CF2 Postion   2          */
#define MCAN_TXBCF_CF2_Msk (0x1U << MCAN_TXBCF_CF2_Pos) /*!< CF2 Mask      0x00000004 */
#define MCAN_TXBCF_CF2_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCF_CF2_Pos) & MCAN_TXBCF_CF2_Msk) /*!< CF2 Set Value            */
#define MCAN_TXBCF_CF2_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCF_CF2_Msk) >> MCAN_TXBCF_CF2_Pos) /*!< CF2 Get Value            */


#define MCAN_TXBCF_CF1_Pos (1U)                         /*!< CF1 Postion   1          */
#define MCAN_TXBCF_CF1_Msk (0x1U << MCAN_TXBCF_CF1_Pos) /*!< CF1 Mask      0x00000002 */
#define MCAN_TXBCF_CF1_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCF_CF1_Pos) & MCAN_TXBCF_CF1_Msk) /*!< CF1 Set Value            */
#define MCAN_TXBCF_CF1_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCF_CF1_Msk) >> MCAN_TXBCF_CF1_Pos) /*!< CF1 Get Value            */


#define MCAN_TXBCF_CF0_Pos (0U)                         /*!< CF0 Postion   0          */
#define MCAN_TXBCF_CF0_Msk (0x1U << MCAN_TXBCF_CF0_Pos) /*!< CF0 Mask      0x00000001 */
#define MCAN_TXBCF_CF0_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCF_CF0_Pos) & MCAN_TXBCF_CF0_Msk) /*!< CF0 Set Value            */
#define MCAN_TXBCF_CF0_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCF_CF0_Msk) >> MCAN_TXBCF_CF0_Pos) /*!< CF0 Get Value            */


/* TXBTIE bitfield */
#define MCAN_TXBTIE_TIE31_Pos (31U)                           /*!< TIE31 Postion   31         */
#define MCAN_TXBTIE_TIE31_Msk (0x1U << MCAN_TXBTIE_TIE31_Pos) /*!< TIE31 Mask      0x80000000 */
#define MCAN_TXBTIE_TIE31_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTIE_TIE31_Pos) & MCAN_TXBTIE_TIE31_Msk) /*!< TIE31 Set Value            */
#define MCAN_TXBTIE_TIE31_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTIE_TIE31_Msk) >> MCAN_TXBTIE_TIE31_Pos) /*!< TIE31 Get Value            */


#define MCAN_TXBTIE_TIE30_Pos (30U)                           /*!< TIE30 Postion   30         */
#define MCAN_TXBTIE_TIE30_Msk (0x1U << MCAN_TXBTIE_TIE30_Pos) /*!< TIE30 Mask      0x40000000 */
#define MCAN_TXBTIE_TIE30_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTIE_TIE30_Pos) & MCAN_TXBTIE_TIE30_Msk) /*!< TIE30 Set Value            */
#define MCAN_TXBTIE_TIE30_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTIE_TIE30_Msk) >> MCAN_TXBTIE_TIE30_Pos) /*!< TIE30 Get Value            */


#define MCAN_TXBTIE_TIE29_Pos (29U)                           /*!< TIE29 Postion   29         */
#define MCAN_TXBTIE_TIE29_Msk (0x1U << MCAN_TXBTIE_TIE29_Pos) /*!< TIE29 Mask      0x20000000 */
#define MCAN_TXBTIE_TIE29_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTIE_TIE29_Pos) & MCAN_TXBTIE_TIE29_Msk) /*!< TIE29 Set Value            */
#define MCAN_TXBTIE_TIE29_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTIE_TIE29_Msk) >> MCAN_TXBTIE_TIE29_Pos) /*!< TIE29 Get Value            */


#define MCAN_TXBTIE_TIE28_Pos (28U)                           /*!< TIE28 Postion   28         */
#define MCAN_TXBTIE_TIE28_Msk (0x1U << MCAN_TXBTIE_TIE28_Pos) /*!< TIE28 Mask      0x10000000 */
#define MCAN_TXBTIE_TIE28_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTIE_TIE28_Pos) & MCAN_TXBTIE_TIE28_Msk) /*!< TIE28 Set Value            */
#define MCAN_TXBTIE_TIE28_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTIE_TIE28_Msk) >> MCAN_TXBTIE_TIE28_Pos) /*!< TIE28 Get Value            */


#define MCAN_TXBTIE_TIE27_Pos (27U)                           /*!< TIE27 Postion   27         */
#define MCAN_TXBTIE_TIE27_Msk (0x1U << MCAN_TXBTIE_TIE27_Pos) /*!< TIE27 Mask      0x08000000 */
#define MCAN_TXBTIE_TIE27_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTIE_TIE27_Pos) & MCAN_TXBTIE_TIE27_Msk) /*!< TIE27 Set Value            */
#define MCAN_TXBTIE_TIE27_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTIE_TIE27_Msk) >> MCAN_TXBTIE_TIE27_Pos) /*!< TIE27 Get Value            */


#define MCAN_TXBTIE_TIE26_Pos (26U)                           /*!< TIE26 Postion   26         */
#define MCAN_TXBTIE_TIE26_Msk (0x1U << MCAN_TXBTIE_TIE26_Pos) /*!< TIE26 Mask      0x04000000 */
#define MCAN_TXBTIE_TIE26_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTIE_TIE26_Pos) & MCAN_TXBTIE_TIE26_Msk) /*!< TIE26 Set Value            */
#define MCAN_TXBTIE_TIE26_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTIE_TIE26_Msk) >> MCAN_TXBTIE_TIE26_Pos) /*!< TIE26 Get Value            */


#define MCAN_TXBTIE_TIE25_Pos (25U)                           /*!< TIE25 Postion   25         */
#define MCAN_TXBTIE_TIE25_Msk (0x1U << MCAN_TXBTIE_TIE25_Pos) /*!< TIE25 Mask      0x02000000 */
#define MCAN_TXBTIE_TIE25_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTIE_TIE25_Pos) & MCAN_TXBTIE_TIE25_Msk) /*!< TIE25 Set Value            */
#define MCAN_TXBTIE_TIE25_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTIE_TIE25_Msk) >> MCAN_TXBTIE_TIE25_Pos) /*!< TIE25 Get Value            */


#define MCAN_TXBTIE_TIE24_Pos (24U)                           /*!< TIE24 Postion   24         */
#define MCAN_TXBTIE_TIE24_Msk (0x1U << MCAN_TXBTIE_TIE24_Pos) /*!< TIE24 Mask      0x01000000 */
#define MCAN_TXBTIE_TIE24_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTIE_TIE24_Pos) & MCAN_TXBTIE_TIE24_Msk) /*!< TIE24 Set Value            */
#define MCAN_TXBTIE_TIE24_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTIE_TIE24_Msk) >> MCAN_TXBTIE_TIE24_Pos) /*!< TIE24 Get Value            */


#define MCAN_TXBTIE_TIE23_Pos (23U)                           /*!< TIE23 Postion   23         */
#define MCAN_TXBTIE_TIE23_Msk (0x1U << MCAN_TXBTIE_TIE23_Pos) /*!< TIE23 Mask      0x00800000 */
#define MCAN_TXBTIE_TIE23_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTIE_TIE23_Pos) & MCAN_TXBTIE_TIE23_Msk) /*!< TIE23 Set Value            */
#define MCAN_TXBTIE_TIE23_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTIE_TIE23_Msk) >> MCAN_TXBTIE_TIE23_Pos) /*!< TIE23 Get Value            */


#define MCAN_TXBTIE_TIE22_Pos (22U)                           /*!< TIE22 Postion   22         */
#define MCAN_TXBTIE_TIE22_Msk (0x1U << MCAN_TXBTIE_TIE22_Pos) /*!< TIE22 Mask      0x00400000 */
#define MCAN_TXBTIE_TIE22_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTIE_TIE22_Pos) & MCAN_TXBTIE_TIE22_Msk) /*!< TIE22 Set Value            */
#define MCAN_TXBTIE_TIE22_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTIE_TIE22_Msk) >> MCAN_TXBTIE_TIE22_Pos) /*!< TIE22 Get Value            */


#define MCAN_TXBTIE_TIE21_Pos (21U)                           /*!< TIE21 Postion   21         */
#define MCAN_TXBTIE_TIE21_Msk (0x1U << MCAN_TXBTIE_TIE21_Pos) /*!< TIE21 Mask      0x00200000 */
#define MCAN_TXBTIE_TIE21_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTIE_TIE21_Pos) & MCAN_TXBTIE_TIE21_Msk) /*!< TIE21 Set Value            */
#define MCAN_TXBTIE_TIE21_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTIE_TIE21_Msk) >> MCAN_TXBTIE_TIE21_Pos) /*!< TIE21 Get Value            */


#define MCAN_TXBTIE_TIE20_Pos (20U)                           /*!< TIE20 Postion   20         */
#define MCAN_TXBTIE_TIE20_Msk (0x1U << MCAN_TXBTIE_TIE20_Pos) /*!< TIE20 Mask      0x00100000 */
#define MCAN_TXBTIE_TIE20_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTIE_TIE20_Pos) & MCAN_TXBTIE_TIE20_Msk) /*!< TIE20 Set Value            */
#define MCAN_TXBTIE_TIE20_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTIE_TIE20_Msk) >> MCAN_TXBTIE_TIE20_Pos) /*!< TIE20 Get Value            */


#define MCAN_TXBTIE_TIE19_Pos (19U)                           /*!< TIE19 Postion   19         */
#define MCAN_TXBTIE_TIE19_Msk (0x1U << MCAN_TXBTIE_TIE19_Pos) /*!< TIE19 Mask      0x00080000 */
#define MCAN_TXBTIE_TIE19_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTIE_TIE19_Pos) & MCAN_TXBTIE_TIE19_Msk) /*!< TIE19 Set Value            */
#define MCAN_TXBTIE_TIE19_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTIE_TIE19_Msk) >> MCAN_TXBTIE_TIE19_Pos) /*!< TIE19 Get Value            */


#define MCAN_TXBTIE_TIE18_Pos (18U)                           /*!< TIE18 Postion   18         */
#define MCAN_TXBTIE_TIE18_Msk (0x1U << MCAN_TXBTIE_TIE18_Pos) /*!< TIE18 Mask      0x00040000 */
#define MCAN_TXBTIE_TIE18_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTIE_TIE18_Pos) & MCAN_TXBTIE_TIE18_Msk) /*!< TIE18 Set Value            */
#define MCAN_TXBTIE_TIE18_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTIE_TIE18_Msk) >> MCAN_TXBTIE_TIE18_Pos) /*!< TIE18 Get Value            */


#define MCAN_TXBTIE_TIE17_Pos (17U)                           /*!< TIE17 Postion   17         */
#define MCAN_TXBTIE_TIE17_Msk (0x1U << MCAN_TXBTIE_TIE17_Pos) /*!< TIE17 Mask      0x00020000 */
#define MCAN_TXBTIE_TIE17_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTIE_TIE17_Pos) & MCAN_TXBTIE_TIE17_Msk) /*!< TIE17 Set Value            */
#define MCAN_TXBTIE_TIE17_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTIE_TIE17_Msk) >> MCAN_TXBTIE_TIE17_Pos) /*!< TIE17 Get Value            */


#define MCAN_TXBTIE_TIE16_Pos (16U)                           /*!< TIE16 Postion   16         */
#define MCAN_TXBTIE_TIE16_Msk (0x1U << MCAN_TXBTIE_TIE16_Pos) /*!< TIE16 Mask      0x00010000 */
#define MCAN_TXBTIE_TIE16_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTIE_TIE16_Pos) & MCAN_TXBTIE_TIE16_Msk) /*!< TIE16 Set Value            */
#define MCAN_TXBTIE_TIE16_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTIE_TIE16_Msk) >> MCAN_TXBTIE_TIE16_Pos) /*!< TIE16 Get Value            */


#define MCAN_TXBTIE_TIE15_Pos (15U)                           /*!< TIE15 Postion   15         */
#define MCAN_TXBTIE_TIE15_Msk (0x1U << MCAN_TXBTIE_TIE15_Pos) /*!< TIE15 Mask      0x00008000 */
#define MCAN_TXBTIE_TIE15_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTIE_TIE15_Pos) & MCAN_TXBTIE_TIE15_Msk) /*!< TIE15 Set Value            */
#define MCAN_TXBTIE_TIE15_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTIE_TIE15_Msk) >> MCAN_TXBTIE_TIE15_Pos) /*!< TIE15 Get Value            */


#define MCAN_TXBTIE_TIE14_Pos (14U)                           /*!< TIE14 Postion   14         */
#define MCAN_TXBTIE_TIE14_Msk (0x1U << MCAN_TXBTIE_TIE14_Pos) /*!< TIE14 Mask      0x00004000 */
#define MCAN_TXBTIE_TIE14_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTIE_TIE14_Pos) & MCAN_TXBTIE_TIE14_Msk) /*!< TIE14 Set Value            */
#define MCAN_TXBTIE_TIE14_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTIE_TIE14_Msk) >> MCAN_TXBTIE_TIE14_Pos) /*!< TIE14 Get Value            */


#define MCAN_TXBTIE_TIE13_Pos (13U)                           /*!< TIE13 Postion   13         */
#define MCAN_TXBTIE_TIE13_Msk (0x1U << MCAN_TXBTIE_TIE13_Pos) /*!< TIE13 Mask      0x00002000 */
#define MCAN_TXBTIE_TIE13_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTIE_TIE13_Pos) & MCAN_TXBTIE_TIE13_Msk) /*!< TIE13 Set Value            */
#define MCAN_TXBTIE_TIE13_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTIE_TIE13_Msk) >> MCAN_TXBTIE_TIE13_Pos) /*!< TIE13 Get Value            */


#define MCAN_TXBTIE_TIE12_Pos (12U)                           /*!< TIE12 Postion   12         */
#define MCAN_TXBTIE_TIE12_Msk (0x1U << MCAN_TXBTIE_TIE12_Pos) /*!< TIE12 Mask      0x00001000 */
#define MCAN_TXBTIE_TIE12_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTIE_TIE12_Pos) & MCAN_TXBTIE_TIE12_Msk) /*!< TIE12 Set Value            */
#define MCAN_TXBTIE_TIE12_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTIE_TIE12_Msk) >> MCAN_TXBTIE_TIE12_Pos) /*!< TIE12 Get Value            */


#define MCAN_TXBTIE_TIE11_Pos (11U)                           /*!< TIE11 Postion   11         */
#define MCAN_TXBTIE_TIE11_Msk (0x1U << MCAN_TXBTIE_TIE11_Pos) /*!< TIE11 Mask      0x00000800 */
#define MCAN_TXBTIE_TIE11_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTIE_TIE11_Pos) & MCAN_TXBTIE_TIE11_Msk) /*!< TIE11 Set Value            */
#define MCAN_TXBTIE_TIE11_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTIE_TIE11_Msk) >> MCAN_TXBTIE_TIE11_Pos) /*!< TIE11 Get Value            */


#define MCAN_TXBTIE_TIE10_Pos (10U)                           /*!< TIE10 Postion   10         */
#define MCAN_TXBTIE_TIE10_Msk (0x1U << MCAN_TXBTIE_TIE10_Pos) /*!< TIE10 Mask      0x00000400 */
#define MCAN_TXBTIE_TIE10_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTIE_TIE10_Pos) & MCAN_TXBTIE_TIE10_Msk) /*!< TIE10 Set Value            */
#define MCAN_TXBTIE_TIE10_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTIE_TIE10_Msk) >> MCAN_TXBTIE_TIE10_Pos) /*!< TIE10 Get Value            */


#define MCAN_TXBTIE_TIE9_Pos (9U)                           /*!< TIE9 Postion   9          */
#define MCAN_TXBTIE_TIE9_Msk (0x1U << MCAN_TXBTIE_TIE9_Pos) /*!< TIE9 Mask      0x00000200 */
#define MCAN_TXBTIE_TIE9_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTIE_TIE9_Pos) & MCAN_TXBTIE_TIE9_Msk) /*!< TIE9 Set Value            */
#define MCAN_TXBTIE_TIE9_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTIE_TIE9_Msk) >> MCAN_TXBTIE_TIE9_Pos) /*!< TIE9 Get Value            */


#define MCAN_TXBTIE_TIE8_Pos (8U)                           /*!< TIE8 Postion   8          */
#define MCAN_TXBTIE_TIE8_Msk (0x1U << MCAN_TXBTIE_TIE8_Pos) /*!< TIE8 Mask      0x00000100 */
#define MCAN_TXBTIE_TIE8_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTIE_TIE8_Pos) & MCAN_TXBTIE_TIE8_Msk) /*!< TIE8 Set Value            */
#define MCAN_TXBTIE_TIE8_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTIE_TIE8_Msk) >> MCAN_TXBTIE_TIE8_Pos) /*!< TIE8 Get Value            */


#define MCAN_TXBTIE_TIE7_Pos (7U)                           /*!< TIE7 Postion   7          */
#define MCAN_TXBTIE_TIE7_Msk (0x1U << MCAN_TXBTIE_TIE7_Pos) /*!< TIE7 Mask      0x00000080 */
#define MCAN_TXBTIE_TIE7_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTIE_TIE7_Pos) & MCAN_TXBTIE_TIE7_Msk) /*!< TIE7 Set Value            */
#define MCAN_TXBTIE_TIE7_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTIE_TIE7_Msk) >> MCAN_TXBTIE_TIE7_Pos) /*!< TIE7 Get Value            */


#define MCAN_TXBTIE_TIE6_Pos (6U)                           /*!< TIE6 Postion   6          */
#define MCAN_TXBTIE_TIE6_Msk (0x1U << MCAN_TXBTIE_TIE6_Pos) /*!< TIE6 Mask      0x00000040 */
#define MCAN_TXBTIE_TIE6_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTIE_TIE6_Pos) & MCAN_TXBTIE_TIE6_Msk) /*!< TIE6 Set Value            */
#define MCAN_TXBTIE_TIE6_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTIE_TIE6_Msk) >> MCAN_TXBTIE_TIE6_Pos) /*!< TIE6 Get Value            */


#define MCAN_TXBTIE_TIE5_Pos (5U)                           /*!< TIE5 Postion   5          */
#define MCAN_TXBTIE_TIE5_Msk (0x1U << MCAN_TXBTIE_TIE5_Pos) /*!< TIE5 Mask      0x00000020 */
#define MCAN_TXBTIE_TIE5_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTIE_TIE5_Pos) & MCAN_TXBTIE_TIE5_Msk) /*!< TIE5 Set Value            */
#define MCAN_TXBTIE_TIE5_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTIE_TIE5_Msk) >> MCAN_TXBTIE_TIE5_Pos) /*!< TIE5 Get Value            */


#define MCAN_TXBTIE_TIE4_Pos (4U)                           /*!< TIE4 Postion   4          */
#define MCAN_TXBTIE_TIE4_Msk (0x1U << MCAN_TXBTIE_TIE4_Pos) /*!< TIE4 Mask      0x00000010 */
#define MCAN_TXBTIE_TIE4_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTIE_TIE4_Pos) & MCAN_TXBTIE_TIE4_Msk) /*!< TIE4 Set Value            */
#define MCAN_TXBTIE_TIE4_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTIE_TIE4_Msk) >> MCAN_TXBTIE_TIE4_Pos) /*!< TIE4 Get Value            */


#define MCAN_TXBTIE_TIE3_Pos (3U)                           /*!< TIE3 Postion   3          */
#define MCAN_TXBTIE_TIE3_Msk (0x1U << MCAN_TXBTIE_TIE3_Pos) /*!< TIE3 Mask      0x00000008 */
#define MCAN_TXBTIE_TIE3_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTIE_TIE3_Pos) & MCAN_TXBTIE_TIE3_Msk) /*!< TIE3 Set Value            */
#define MCAN_TXBTIE_TIE3_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTIE_TIE3_Msk) >> MCAN_TXBTIE_TIE3_Pos) /*!< TIE3 Get Value            */


#define MCAN_TXBTIE_TIE2_Pos (2U)                           /*!< TIE2 Postion   2          */
#define MCAN_TXBTIE_TIE2_Msk (0x1U << MCAN_TXBTIE_TIE2_Pos) /*!< TIE2 Mask      0x00000004 */
#define MCAN_TXBTIE_TIE2_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTIE_TIE2_Pos) & MCAN_TXBTIE_TIE2_Msk) /*!< TIE2 Set Value            */
#define MCAN_TXBTIE_TIE2_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTIE_TIE2_Msk) >> MCAN_TXBTIE_TIE2_Pos) /*!< TIE2 Get Value            */


#define MCAN_TXBTIE_TIE1_Pos (1U)                           /*!< TIE1 Postion   1          */
#define MCAN_TXBTIE_TIE1_Msk (0x1U << MCAN_TXBTIE_TIE1_Pos) /*!< TIE1 Mask      0x00000002 */
#define MCAN_TXBTIE_TIE1_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTIE_TIE1_Pos) & MCAN_TXBTIE_TIE1_Msk) /*!< TIE1 Set Value            */
#define MCAN_TXBTIE_TIE1_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTIE_TIE1_Msk) >> MCAN_TXBTIE_TIE1_Pos) /*!< TIE1 Get Value            */


#define MCAN_TXBTIE_TIE0_Pos (0U)                           /*!< TIE0 Postion   0          */
#define MCAN_TXBTIE_TIE0_Msk (0x1U << MCAN_TXBTIE_TIE0_Pos) /*!< TIE0 Mask      0x00000001 */
#define MCAN_TXBTIE_TIE0_Set(x) \
    (((uint32_t) (x) << MCAN_TXBTIE_TIE0_Pos) & MCAN_TXBTIE_TIE0_Msk) /*!< TIE0 Set Value            */
#define MCAN_TXBTIE_TIE0_Get(x) \
    (((uint32_t) (x) &MCAN_TXBTIE_TIE0_Msk) >> MCAN_TXBTIE_TIE0_Pos) /*!< TIE0 Get Value            */


/* TXBCIE bitfield */
#define MCAN_TXBCIE_CFIE31_Pos (31U)                            /*!< CFIE31 Postion   31         */
#define MCAN_TXBCIE_CFIE31_Msk (0x1U << MCAN_TXBCIE_CFIE31_Pos) /*!< CFIE31 Mask      0x80000000 */
#define MCAN_TXBCIE_CFIE31_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCIE_CFIE31_Pos) & MCAN_TXBCIE_CFIE31_Msk) /*!< CFIE31 Set Value            */
#define MCAN_TXBCIE_CFIE31_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCIE_CFIE31_Msk) >> MCAN_TXBCIE_CFIE31_Pos) /*!< CFIE31 Get Value            */


#define MCAN_TXBCIE_CFIE30_Pos (30U)                            /*!< CFIE30 Postion   30         */
#define MCAN_TXBCIE_CFIE30_Msk (0x1U << MCAN_TXBCIE_CFIE30_Pos) /*!< CFIE30 Mask      0x40000000 */
#define MCAN_TXBCIE_CFIE30_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCIE_CFIE30_Pos) & MCAN_TXBCIE_CFIE30_Msk) /*!< CFIE30 Set Value            */
#define MCAN_TXBCIE_CFIE30_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCIE_CFIE30_Msk) >> MCAN_TXBCIE_CFIE30_Pos) /*!< CFIE30 Get Value            */


#define MCAN_TXBCIE_CFIE29_Pos (29U)                            /*!< CFIE29 Postion   29         */
#define MCAN_TXBCIE_CFIE29_Msk (0x1U << MCAN_TXBCIE_CFIE29_Pos) /*!< CFIE29 Mask      0x20000000 */
#define MCAN_TXBCIE_CFIE29_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCIE_CFIE29_Pos) & MCAN_TXBCIE_CFIE29_Msk) /*!< CFIE29 Set Value            */
#define MCAN_TXBCIE_CFIE29_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCIE_CFIE29_Msk) >> MCAN_TXBCIE_CFIE29_Pos) /*!< CFIE29 Get Value            */


#define MCAN_TXBCIE_CFIE28_Pos (28U)                            /*!< CFIE28 Postion   28         */
#define MCAN_TXBCIE_CFIE28_Msk (0x1U << MCAN_TXBCIE_CFIE28_Pos) /*!< CFIE28 Mask      0x10000000 */
#define MCAN_TXBCIE_CFIE28_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCIE_CFIE28_Pos) & MCAN_TXBCIE_CFIE28_Msk) /*!< CFIE28 Set Value            */
#define MCAN_TXBCIE_CFIE28_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCIE_CFIE28_Msk) >> MCAN_TXBCIE_CFIE28_Pos) /*!< CFIE28 Get Value            */


#define MCAN_TXBCIE_CFIE27_Pos (27U)                            /*!< CFIE27 Postion   27         */
#define MCAN_TXBCIE_CFIE27_Msk (0x1U << MCAN_TXBCIE_CFIE27_Pos) /*!< CFIE27 Mask      0x08000000 */
#define MCAN_TXBCIE_CFIE27_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCIE_CFIE27_Pos) & MCAN_TXBCIE_CFIE27_Msk) /*!< CFIE27 Set Value            */
#define MCAN_TXBCIE_CFIE27_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCIE_CFIE27_Msk) >> MCAN_TXBCIE_CFIE27_Pos) /*!< CFIE27 Get Value            */


#define MCAN_TXBCIE_CFIE26_Pos (26U)                            /*!< CFIE26 Postion   26         */
#define MCAN_TXBCIE_CFIE26_Msk (0x1U << MCAN_TXBCIE_CFIE26_Pos) /*!< CFIE26 Mask      0x04000000 */
#define MCAN_TXBCIE_CFIE26_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCIE_CFIE26_Pos) & MCAN_TXBCIE_CFIE26_Msk) /*!< CFIE26 Set Value            */
#define MCAN_TXBCIE_CFIE26_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCIE_CFIE26_Msk) >> MCAN_TXBCIE_CFIE26_Pos) /*!< CFIE26 Get Value            */


#define MCAN_TXBCIE_CFIE25_Pos (25U)                            /*!< CFIE25 Postion   25         */
#define MCAN_TXBCIE_CFIE25_Msk (0x1U << MCAN_TXBCIE_CFIE25_Pos) /*!< CFIE25 Mask      0x02000000 */
#define MCAN_TXBCIE_CFIE25_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCIE_CFIE25_Pos) & MCAN_TXBCIE_CFIE25_Msk) /*!< CFIE25 Set Value            */
#define MCAN_TXBCIE_CFIE25_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCIE_CFIE25_Msk) >> MCAN_TXBCIE_CFIE25_Pos) /*!< CFIE25 Get Value            */


#define MCAN_TXBCIE_CFIE24_Pos (24U)                            /*!< CFIE24 Postion   24         */
#define MCAN_TXBCIE_CFIE24_Msk (0x1U << MCAN_TXBCIE_CFIE24_Pos) /*!< CFIE24 Mask      0x01000000 */
#define MCAN_TXBCIE_CFIE24_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCIE_CFIE24_Pos) & MCAN_TXBCIE_CFIE24_Msk) /*!< CFIE24 Set Value            */
#define MCAN_TXBCIE_CFIE24_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCIE_CFIE24_Msk) >> MCAN_TXBCIE_CFIE24_Pos) /*!< CFIE24 Get Value            */


#define MCAN_TXBCIE_CFIE23_Pos (23U)                            /*!< CFIE23 Postion   23         */
#define MCAN_TXBCIE_CFIE23_Msk (0x1U << MCAN_TXBCIE_CFIE23_Pos) /*!< CFIE23 Mask      0x00800000 */
#define MCAN_TXBCIE_CFIE23_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCIE_CFIE23_Pos) & MCAN_TXBCIE_CFIE23_Msk) /*!< CFIE23 Set Value            */
#define MCAN_TXBCIE_CFIE23_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCIE_CFIE23_Msk) >> MCAN_TXBCIE_CFIE23_Pos) /*!< CFIE23 Get Value            */


#define MCAN_TXBCIE_CFIE22_Pos (22U)                            /*!< CFIE22 Postion   22         */
#define MCAN_TXBCIE_CFIE22_Msk (0x1U << MCAN_TXBCIE_CFIE22_Pos) /*!< CFIE22 Mask      0x00400000 */
#define MCAN_TXBCIE_CFIE22_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCIE_CFIE22_Pos) & MCAN_TXBCIE_CFIE22_Msk) /*!< CFIE22 Set Value            */
#define MCAN_TXBCIE_CFIE22_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCIE_CFIE22_Msk) >> MCAN_TXBCIE_CFIE22_Pos) /*!< CFIE22 Get Value            */


#define MCAN_TXBCIE_CFIE21_Pos (21U)                            /*!< CFIE21 Postion   21         */
#define MCAN_TXBCIE_CFIE21_Msk (0x1U << MCAN_TXBCIE_CFIE21_Pos) /*!< CFIE21 Mask      0x00200000 */
#define MCAN_TXBCIE_CFIE21_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCIE_CFIE21_Pos) & MCAN_TXBCIE_CFIE21_Msk) /*!< CFIE21 Set Value            */
#define MCAN_TXBCIE_CFIE21_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCIE_CFIE21_Msk) >> MCAN_TXBCIE_CFIE21_Pos) /*!< CFIE21 Get Value            */


#define MCAN_TXBCIE_CFIE20_Pos (20U)                            /*!< CFIE20 Postion   20         */
#define MCAN_TXBCIE_CFIE20_Msk (0x1U << MCAN_TXBCIE_CFIE20_Pos) /*!< CFIE20 Mask      0x00100000 */
#define MCAN_TXBCIE_CFIE20_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCIE_CFIE20_Pos) & MCAN_TXBCIE_CFIE20_Msk) /*!< CFIE20 Set Value            */
#define MCAN_TXBCIE_CFIE20_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCIE_CFIE20_Msk) >> MCAN_TXBCIE_CFIE20_Pos) /*!< CFIE20 Get Value            */


#define MCAN_TXBCIE_CFIE19_Pos (19U)                            /*!< CFIE19 Postion   19         */
#define MCAN_TXBCIE_CFIE19_Msk (0x1U << MCAN_TXBCIE_CFIE19_Pos) /*!< CFIE19 Mask      0x00080000 */
#define MCAN_TXBCIE_CFIE19_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCIE_CFIE19_Pos) & MCAN_TXBCIE_CFIE19_Msk) /*!< CFIE19 Set Value            */
#define MCAN_TXBCIE_CFIE19_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCIE_CFIE19_Msk) >> MCAN_TXBCIE_CFIE19_Pos) /*!< CFIE19 Get Value            */


#define MCAN_TXBCIE_CFIE18_Pos (18U)                            /*!< CFIE18 Postion   18         */
#define MCAN_TXBCIE_CFIE18_Msk (0x1U << MCAN_TXBCIE_CFIE18_Pos) /*!< CFIE18 Mask      0x00040000 */
#define MCAN_TXBCIE_CFIE18_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCIE_CFIE18_Pos) & MCAN_TXBCIE_CFIE18_Msk) /*!< CFIE18 Set Value            */
#define MCAN_TXBCIE_CFIE18_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCIE_CFIE18_Msk) >> MCAN_TXBCIE_CFIE18_Pos) /*!< CFIE18 Get Value            */


#define MCAN_TXBCIE_CFIE17_Pos (17U)                            /*!< CFIE17 Postion   17         */
#define MCAN_TXBCIE_CFIE17_Msk (0x1U << MCAN_TXBCIE_CFIE17_Pos) /*!< CFIE17 Mask      0x00020000 */
#define MCAN_TXBCIE_CFIE17_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCIE_CFIE17_Pos) & MCAN_TXBCIE_CFIE17_Msk) /*!< CFIE17 Set Value            */
#define MCAN_TXBCIE_CFIE17_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCIE_CFIE17_Msk) >> MCAN_TXBCIE_CFIE17_Pos) /*!< CFIE17 Get Value            */


#define MCAN_TXBCIE_CFIE16_Pos (16U)                            /*!< CFIE16 Postion   16         */
#define MCAN_TXBCIE_CFIE16_Msk (0x1U << MCAN_TXBCIE_CFIE16_Pos) /*!< CFIE16 Mask      0x00010000 */
#define MCAN_TXBCIE_CFIE16_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCIE_CFIE16_Pos) & MCAN_TXBCIE_CFIE16_Msk) /*!< CFIE16 Set Value            */
#define MCAN_TXBCIE_CFIE16_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCIE_CFIE16_Msk) >> MCAN_TXBCIE_CFIE16_Pos) /*!< CFIE16 Get Value            */


#define MCAN_TXBCIE_CFIE15_Pos (15U)                            /*!< CFIE15 Postion   15         */
#define MCAN_TXBCIE_CFIE15_Msk (0x1U << MCAN_TXBCIE_CFIE15_Pos) /*!< CFIE15 Mask      0x00008000 */
#define MCAN_TXBCIE_CFIE15_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCIE_CFIE15_Pos) & MCAN_TXBCIE_CFIE15_Msk) /*!< CFIE15 Set Value            */
#define MCAN_TXBCIE_CFIE15_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCIE_CFIE15_Msk) >> MCAN_TXBCIE_CFIE15_Pos) /*!< CFIE15 Get Value            */


#define MCAN_TXBCIE_CFIE14_Pos (14U)                            /*!< CFIE14 Postion   14         */
#define MCAN_TXBCIE_CFIE14_Msk (0x1U << MCAN_TXBCIE_CFIE14_Pos) /*!< CFIE14 Mask      0x00004000 */
#define MCAN_TXBCIE_CFIE14_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCIE_CFIE14_Pos) & MCAN_TXBCIE_CFIE14_Msk) /*!< CFIE14 Set Value            */
#define MCAN_TXBCIE_CFIE14_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCIE_CFIE14_Msk) >> MCAN_TXBCIE_CFIE14_Pos) /*!< CFIE14 Get Value            */


#define MCAN_TXBCIE_CFIE13_Pos (13U)                            /*!< CFIE13 Postion   13         */
#define MCAN_TXBCIE_CFIE13_Msk (0x1U << MCAN_TXBCIE_CFIE13_Pos) /*!< CFIE13 Mask      0x00002000 */
#define MCAN_TXBCIE_CFIE13_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCIE_CFIE13_Pos) & MCAN_TXBCIE_CFIE13_Msk) /*!< CFIE13 Set Value            */
#define MCAN_TXBCIE_CFIE13_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCIE_CFIE13_Msk) >> MCAN_TXBCIE_CFIE13_Pos) /*!< CFIE13 Get Value            */


#define MCAN_TXBCIE_CFIE12_Pos (12U)                            /*!< CFIE12 Postion   12         */
#define MCAN_TXBCIE_CFIE12_Msk (0x1U << MCAN_TXBCIE_CFIE12_Pos) /*!< CFIE12 Mask      0x00001000 */
#define MCAN_TXBCIE_CFIE12_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCIE_CFIE12_Pos) & MCAN_TXBCIE_CFIE12_Msk) /*!< CFIE12 Set Value            */
#define MCAN_TXBCIE_CFIE12_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCIE_CFIE12_Msk) >> MCAN_TXBCIE_CFIE12_Pos) /*!< CFIE12 Get Value            */


#define MCAN_TXBCIE_CFIE11_Pos (11U)                            /*!< CFIE11 Postion   11         */
#define MCAN_TXBCIE_CFIE11_Msk (0x1U << MCAN_TXBCIE_CFIE11_Pos) /*!< CFIE11 Mask      0x00000800 */
#define MCAN_TXBCIE_CFIE11_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCIE_CFIE11_Pos) & MCAN_TXBCIE_CFIE11_Msk) /*!< CFIE11 Set Value            */
#define MCAN_TXBCIE_CFIE11_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCIE_CFIE11_Msk) >> MCAN_TXBCIE_CFIE11_Pos) /*!< CFIE11 Get Value            */


#define MCAN_TXBCIE_CFIE10_Pos (10U)                            /*!< CFIE10 Postion   10         */
#define MCAN_TXBCIE_CFIE10_Msk (0x1U << MCAN_TXBCIE_CFIE10_Pos) /*!< CFIE10 Mask      0x00000400 */
#define MCAN_TXBCIE_CFIE10_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCIE_CFIE10_Pos) & MCAN_TXBCIE_CFIE10_Msk) /*!< CFIE10 Set Value            */
#define MCAN_TXBCIE_CFIE10_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCIE_CFIE10_Msk) >> MCAN_TXBCIE_CFIE10_Pos) /*!< CFIE10 Get Value            */


#define MCAN_TXBCIE_CFIE9_Pos (9U)                            /*!< CFIE9 Postion   9          */
#define MCAN_TXBCIE_CFIE9_Msk (0x1U << MCAN_TXBCIE_CFIE9_Pos) /*!< CFIE9 Mask      0x00000200 */
#define MCAN_TXBCIE_CFIE9_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCIE_CFIE9_Pos) & MCAN_TXBCIE_CFIE9_Msk) /*!< CFIE9 Set Value            */
#define MCAN_TXBCIE_CFIE9_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCIE_CFIE9_Msk) >> MCAN_TXBCIE_CFIE9_Pos) /*!< CFIE9 Get Value            */


#define MCAN_TXBCIE_CFIE8_Pos (8U)                            /*!< CFIE8 Postion   8          */
#define MCAN_TXBCIE_CFIE8_Msk (0x1U << MCAN_TXBCIE_CFIE8_Pos) /*!< CFIE8 Mask      0x00000100 */
#define MCAN_TXBCIE_CFIE8_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCIE_CFIE8_Pos) & MCAN_TXBCIE_CFIE8_Msk) /*!< CFIE8 Set Value            */
#define MCAN_TXBCIE_CFIE8_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCIE_CFIE8_Msk) >> MCAN_TXBCIE_CFIE8_Pos) /*!< CFIE8 Get Value            */


#define MCAN_TXBCIE_CFIE7_Pos (7U)                            /*!< CFIE7 Postion   7          */
#define MCAN_TXBCIE_CFIE7_Msk (0x1U << MCAN_TXBCIE_CFIE7_Pos) /*!< CFIE7 Mask      0x00000080 */
#define MCAN_TXBCIE_CFIE7_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCIE_CFIE7_Pos) & MCAN_TXBCIE_CFIE7_Msk) /*!< CFIE7 Set Value            */
#define MCAN_TXBCIE_CFIE7_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCIE_CFIE7_Msk) >> MCAN_TXBCIE_CFIE7_Pos) /*!< CFIE7 Get Value            */


#define MCAN_TXBCIE_CFIE6_Pos (6U)                            /*!< CFIE6 Postion   6          */
#define MCAN_TXBCIE_CFIE6_Msk (0x1U << MCAN_TXBCIE_CFIE6_Pos) /*!< CFIE6 Mask      0x00000040 */
#define MCAN_TXBCIE_CFIE6_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCIE_CFIE6_Pos) & MCAN_TXBCIE_CFIE6_Msk) /*!< CFIE6 Set Value            */
#define MCAN_TXBCIE_CFIE6_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCIE_CFIE6_Msk) >> MCAN_TXBCIE_CFIE6_Pos) /*!< CFIE6 Get Value            */


#define MCAN_TXBCIE_CFIE5_Pos (5U)                            /*!< CFIE5 Postion   5          */
#define MCAN_TXBCIE_CFIE5_Msk (0x1U << MCAN_TXBCIE_CFIE5_Pos) /*!< CFIE5 Mask      0x00000020 */
#define MCAN_TXBCIE_CFIE5_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCIE_CFIE5_Pos) & MCAN_TXBCIE_CFIE5_Msk) /*!< CFIE5 Set Value            */
#define MCAN_TXBCIE_CFIE5_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCIE_CFIE5_Msk) >> MCAN_TXBCIE_CFIE5_Pos) /*!< CFIE5 Get Value            */


#define MCAN_TXBCIE_CFIE4_Pos (4U)                            /*!< CFIE4 Postion   4          */
#define MCAN_TXBCIE_CFIE4_Msk (0x1U << MCAN_TXBCIE_CFIE4_Pos) /*!< CFIE4 Mask      0x00000010 */
#define MCAN_TXBCIE_CFIE4_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCIE_CFIE4_Pos) & MCAN_TXBCIE_CFIE4_Msk) /*!< CFIE4 Set Value            */
#define MCAN_TXBCIE_CFIE4_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCIE_CFIE4_Msk) >> MCAN_TXBCIE_CFIE4_Pos) /*!< CFIE4 Get Value            */


#define MCAN_TXBCIE_CFIE3_Pos (3U)                            /*!< CFIE3 Postion   3          */
#define MCAN_TXBCIE_CFIE3_Msk (0x1U << MCAN_TXBCIE_CFIE3_Pos) /*!< CFIE3 Mask      0x00000008 */
#define MCAN_TXBCIE_CFIE3_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCIE_CFIE3_Pos) & MCAN_TXBCIE_CFIE3_Msk) /*!< CFIE3 Set Value            */
#define MCAN_TXBCIE_CFIE3_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCIE_CFIE3_Msk) >> MCAN_TXBCIE_CFIE3_Pos) /*!< CFIE3 Get Value            */


#define MCAN_TXBCIE_CFIE2_Pos (2U)                            /*!< CFIE2 Postion   2          */
#define MCAN_TXBCIE_CFIE2_Msk (0x1U << MCAN_TXBCIE_CFIE2_Pos) /*!< CFIE2 Mask      0x00000004 */
#define MCAN_TXBCIE_CFIE2_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCIE_CFIE2_Pos) & MCAN_TXBCIE_CFIE2_Msk) /*!< CFIE2 Set Value            */
#define MCAN_TXBCIE_CFIE2_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCIE_CFIE2_Msk) >> MCAN_TXBCIE_CFIE2_Pos) /*!< CFIE2 Get Value            */


#define MCAN_TXBCIE_CFIE1_Pos (1U)                            /*!< CFIE1 Postion   1          */
#define MCAN_TXBCIE_CFIE1_Msk (0x1U << MCAN_TXBCIE_CFIE1_Pos) /*!< CFIE1 Mask      0x00000002 */
#define MCAN_TXBCIE_CFIE1_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCIE_CFIE1_Pos) & MCAN_TXBCIE_CFIE1_Msk) /*!< CFIE1 Set Value            */
#define MCAN_TXBCIE_CFIE1_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCIE_CFIE1_Msk) >> MCAN_TXBCIE_CFIE1_Pos) /*!< CFIE1 Get Value            */


#define MCAN_TXBCIE_CFIE0_Pos (0U)                            /*!< CFIE0 Postion   0          */
#define MCAN_TXBCIE_CFIE0_Msk (0x1U << MCAN_TXBCIE_CFIE0_Pos) /*!< CFIE0 Mask      0x00000001 */
#define MCAN_TXBCIE_CFIE0_Set(x) \
    (((uint32_t) (x) << MCAN_TXBCIE_CFIE0_Pos) & MCAN_TXBCIE_CFIE0_Msk) /*!< CFIE0 Set Value            */
#define MCAN_TXBCIE_CFIE0_Get(x) \
    (((uint32_t) (x) &MCAN_TXBCIE_CFIE0_Msk) >> MCAN_TXBCIE_CFIE0_Pos) /*!< CFIE0 Get Value            */


/* TXEFC bitfield */
#define MCAN_TXEFC_EFWM_Pos (24U)                          /*!< EFWM Postion   24         */
#define MCAN_TXEFC_EFWM_Msk (0x3fU << MCAN_TXEFC_EFWM_Pos) /*!< EFWM Mask      0x3F000000 */
#define MCAN_TXEFC_EFWM_Set(x) \
    (((uint32_t) (x) << MCAN_TXEFC_EFWM_Pos) & MCAN_TXEFC_EFWM_Msk) /*!< EFWM Set Value            */
#define MCAN_TXEFC_EFWM_Get(x) \
    (((uint32_t) (x) &MCAN_TXEFC_EFWM_Msk) >> MCAN_TXEFC_EFWM_Pos) /*!< EFWM Get Value            */


#define MCAN_TXEFC_EFS_Pos (16U)                         /*!< EFS Postion   16         */
#define MCAN_TXEFC_EFS_Msk (0x3fU << MCAN_TXEFC_EFS_Pos) /*!< EFS Mask      0x003F0000 */
#define MCAN_TXEFC_EFS_Set(x) \
    (((uint32_t) (x) << MCAN_TXEFC_EFS_Pos) & MCAN_TXEFC_EFS_Msk) /*!< EFS Set Value            */
#define MCAN_TXEFC_EFS_Get(x) \
    (((uint32_t) (x) &MCAN_TXEFC_EFS_Msk) >> MCAN_TXEFC_EFS_Pos) /*!< EFS Get Value            */


#define MCAN_TXEFC_EFSA_Pos (2U)                             /*!< EFSA Postion   2          */
#define MCAN_TXEFC_EFSA_Msk (0x3fffU << MCAN_TXEFC_EFSA_Pos) /*!< EFSA Mask      0x0000FFFC */
#define MCAN_TXEFC_EFSA_Set(x) \
    (((uint32_t) (x) << MCAN_TXEFC_EFSA_Pos) & MCAN_TXEFC_EFSA_Msk) /*!< EFSA Set Value            */
#define MCAN_TXEFC_EFSA_Get(x) \
    (((uint32_t) (x) &MCAN_TXEFC_EFSA_Msk) >> MCAN_TXEFC_EFSA_Pos) /*!< EFSA Get Value            */


/* TXEFS bitfield */
#define MCAN_TXEFS_TEFL_Pos (25U)                         /*!< TEFL Postion   25         */
#define MCAN_TXEFS_TEFL_Msk (0x1U << MCAN_TXEFS_TEFL_Pos) /*!< TEFL Mask      0x02000000 */
#define MCAN_TXEFS_TEFL_Set(x) \
    (((uint32_t) (x) << MCAN_TXEFS_TEFL_Pos) & MCAN_TXEFS_TEFL_Msk) /*!< TEFL Set Value            */
#define MCAN_TXEFS_TEFL_Get(x) \
    (((uint32_t) (x) &MCAN_TXEFS_TEFL_Msk) >> MCAN_TXEFS_TEFL_Pos) /*!< TEFL Get Value            */


#define MCAN_TXEFS_EFF_Pos (24U)                        /*!< EFF Postion   24         */
#define MCAN_TXEFS_EFF_Msk (0x1U << MCAN_TXEFS_EFF_Pos) /*!< EFF Mask      0x01000000 */
#define MCAN_TXEFS_EFF_Set(x) \
    (((uint32_t) (x) << MCAN_TXEFS_EFF_Pos) & MCAN_TXEFS_EFF_Msk) /*!< EFF Set Value            */
#define MCAN_TXEFS_EFF_Get(x) \
    (((uint32_t) (x) &MCAN_TXEFS_EFF_Msk) >> MCAN_TXEFS_EFF_Pos) /*!< EFF Get Value            */


#define MCAN_TXEFS_EFPI_Pos (16U)                          /*!< EFPI Postion   16         */
#define MCAN_TXEFS_EFPI_Msk (0x1fU << MCAN_TXEFS_EFPI_Pos) /*!< EFPI Mask      0x001F0000 */
#define MCAN_TXEFS_EFPI_Set(x) \
    (((uint32_t) (x) << MCAN_TXEFS_EFPI_Pos) & MCAN_TXEFS_EFPI_Msk) /*!< EFPI Set Value            */
#define MCAN_TXEFS_EFPI_Get(x) \
    (((uint32_t) (x) &MCAN_TXEFS_EFPI_Msk) >> MCAN_TXEFS_EFPI_Pos) /*!< EFPI Get Value            */


#define MCAN_TXEFS_EFGI_Pos (8U)                           /*!< EFGI Postion   8          */
#define MCAN_TXEFS_EFGI_Msk (0x1fU << MCAN_TXEFS_EFGI_Pos) /*!< EFGI Mask      0x00001F00 */
#define MCAN_TXEFS_EFGI_Set(x) \
    (((uint32_t) (x) << MCAN_TXEFS_EFGI_Pos) & MCAN_TXEFS_EFGI_Msk) /*!< EFGI Set Value            */
#define MCAN_TXEFS_EFGI_Get(x) \
    (((uint32_t) (x) &MCAN_TXEFS_EFGI_Msk) >> MCAN_TXEFS_EFGI_Pos) /*!< EFGI Get Value            */


#define MCAN_TXEFS_EFFL_Pos (0U)                           /*!< EFFL Postion   0          */
#define MCAN_TXEFS_EFFL_Msk (0x3fU << MCAN_TXEFS_EFFL_Pos) /*!< EFFL Mask      0x0000003F */
#define MCAN_TXEFS_EFFL_Set(x) \
    (((uint32_t) (x) << MCAN_TXEFS_EFFL_Pos) & MCAN_TXEFS_EFFL_Msk) /*!< EFFL Set Value            */
#define MCAN_TXEFS_EFFL_Get(x) \
    (((uint32_t) (x) &MCAN_TXEFS_EFFL_Msk) >> MCAN_TXEFS_EFFL_Pos) /*!< EFFL Get Value            */


/* TXEFA bitfield */
#define MCAN_TXEFA_EFAI_Pos (0U)                           /*!< EFAI Postion   0          */
#define MCAN_TXEFA_EFAI_Msk (0x1fU << MCAN_TXEFA_EFAI_Pos) /*!< EFAI Mask      0x0000001F */
#define MCAN_TXEFA_EFAI_Set(x) \
    (((uint32_t) (x) << MCAN_TXEFA_EFAI_Pos) & MCAN_TXEFA_EFAI_Msk) /*!< EFAI Set Value            */
#define MCAN_TXEFA_EFAI_Get(x) \
    (((uint32_t) (x) &MCAN_TXEFA_EFAI_Msk) >> MCAN_TXEFA_EFAI_Pos) /*!< EFAI Get Value            */


/*!
 * @}
 */


/*!
 * @}
 */ /* end of HS32F7D377_MCAN_REGISTER */

#endif /* HS32F7D377_MCAN_H */
