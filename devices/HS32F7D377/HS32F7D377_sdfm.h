/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


/*!
 * \file   HS32F7D377_sdfm.h
 * \brief  HS32F7D377 SDFM register file
 * \version V1.0_20230713
 */

#ifndef HS32F7D377_SDFM_H
#define HS32F7D377_SDFM_H

/*!
 * \addtogroup   HS32F7D377_SDFM_REGISTER HS32F7D377 SDFM Register
 * \ingroup HS32F7D377_REGISTER
 *
 * \brief  SDFM register layout, bitfield and address definitions
 *
 * @{
 */

/*!
 * \name SDFM Register Layout
 *
 *
 * @{
 */

/*! \brief SDFM_REGS register */
typedef struct {
    union
    {
        __IM uint32_t SDIFLG;  /*!< 0x00000000 */ 
       
        struct
        {
            __IM  uint32_t FLT1_FLG_CEVT1            : 1 ;     /*!< [0:0] : CEVT1 Interrupt flag for filter1                                <br>  0: CEVT1 event has not occured 1: CEVT1 event has occurred Reset type: SYSRSn<br>. */
            __IM  uint32_t FLT1_FLG_CEVT2            : 1 ;     /*!< [1:1] : CEVT2 Interrupt flag for filter1                                <br>  0: CEVT2 event has not occured 1: CEVT2 event has occurred Reset type: SYSRSn<br>. */
            __IM  uint32_t FLT2_FLG_CEVT1            : 1 ;     /*!< [2:2] : CEVT1 Interrupt flag for filter2                                <br>  0: CEVT1 event has not occured 1: CEVT1 event has occurred Reset type: SYSRSn<br>. */
            __IM  uint32_t FLT2_FLG_CEVT2            : 1 ;     /*!< [3:3] : CEVT2 Interrupt flag for filter2                                <br>  0: CEVT2 event has not occured 1: CEVT2 event has occurred Reset type: SYSRSn<br>. */
            __IM  uint32_t FLT3_FLG_CEVT1            : 1 ;     /*!< [4:4] : CEVT1 Interrupt flag for filter3                                <br>  0: CEVT1 event has not occured 1: CEVT1 event has occurred Reset type: SYSRSn<br>. */
            __IM  uint32_t FLT3_FLG_CEVT2            : 1 ;     /*!< [5:5] : CEVT2 Interrupt flag for filter3                                <br>  0: CEVT2 event has not occured 1: CEVT2 event has occurred Reset type: SYSRSn<br>. */
            __IM  uint32_t FLT4_FLG_CEVT1            : 1 ;     /*!< [6:6] : CEVT1 Interrupt flag for filter4                                <br>  0: CEVT1 event has not occured 1: CEVT1 event has occurred Reset type: SYSRSn<br>. */
            __IM  uint32_t FLT4_FLG_CEVT2            : 1 ;     /*!< [7:7] : CEVT2 Interrupt flag for filter4                                <br>  0: CEVT2 event has not occured 1: CEVT2 event has occurred Reset type: SYSRSn<br>. */
            __IM  uint32_t MF1                       : 1 ;     /*!< [8:8] : Modulator Failure for Filter 1                                  <br>  0: Modulator is operating normally for Filter 1: Modulator failure for Filter<br>  Reset type: SYSRSn                                              <br>. */
            __IM  uint32_t MF2                       : 1 ;     /*!< [9:9] : Modulator Failure for Filter 2                                  <br>  0: Modulator is operating normally for Filter 1: Modulator failure for Filter<br>  Reset type: SYSRSn                                              <br>. */
            __IM  uint32_t MF3                       : 1 ;     /*!< [10:10] : Modulator Failure for Filter 3                                  <br>  0: Modulator is operating normally for Filter 1: Modulator failure for Filter<br>  Reset type: SYSRSn                                              <br>. */
            __IM  uint32_t MF4                       : 1 ;     /*!< [11:11] : Modulator Failure for Filter 4                                  <br>  0: Modulator is operating normally for Filter 1: Modulator failure for Filter<br>  Reset type: SYSRSn                                              <br>. */
            __IM  uint32_t AF1                       : 1 ;     /*!< [12:12] : Acknowledge flag for Filter 1                                   <br>  0: No new data available for Filter (in non-FIFO mode) 1: New data available for Filter (in non-FIFO mode) Reset type: SYSRSn<br>. */
            __IM  uint32_t AF2                       : 1 ;     /*!< [13:13] : Acknowledge flag for Filter 2                                   <br>  0: No new data available for Filter (in non-FIFO mode) 1: New data available for Filter (in non-FIFO mode) Reset type: SYSRSn<br>. */
            __IM  uint32_t AF3                       : 1 ;     /*!< [14:14] : Acknowledge flag for Filter 3                                   <br>  0: No new data available for Filter (in non-FIFO mode) 1: New data available for Filter (in non-FIFO mode) Reset type: SYSRSn<br>. */
            __IM  uint32_t AF4                       : 1 ;     /*!< [15:15] : Acknowledge flag for Filter 4                                   <br>  0: No new data available for Filter (in non-FIFO mode) 1: New data available for Filter (in non-FIFO mode) Reset type: SYSRSn<br>. */
            __IM  uint32_t SDFFOVF1                  : 1 ;     /*!< [16:16] : FIFO Overflow Flag for Ch1 0 - FIFO has not overflowed          <br>  1 - FIFO overflowed. */
            __IM  uint32_t SDFFOVF2                  : 1 ;     /*!< [17:17] : FIFO Overflow Flag for Ch2 Reset type: SYSRSn. */
            __IM  uint32_t SDFFOVF3                  : 1 ;     /*!< [18:18] : FIFO Overflow Flag for Ch3 Reset type: SYSRSn. */
            __IM  uint32_t SDFFOVF4                  : 1 ;     /*!< [19:19] : FIFO Overflow Flag for Ch4 Reset type: SYSRSn. */
            __IM  uint32_t SDFFINT1                  : 1 ;     /*!< [20:20] : SDFIFO data ready interrupt for Ch1                             <br>  0: SDFIFO data ready interrupt has NOT occurred 1: SDFIFO data ready interrupt has occurred Reset type: SYSRSn<br>. */
            __IM  uint32_t SDFFINT2                  : 1 ;     /*!< [21:21] : SDFIFO data ready interrupt for Ch2 Reset type: SYSRSn. */
            __IM  uint32_t SDFFINT3                  : 1 ;     /*!< [22:22] : SDFIFO data ready interrupt for Ch3 Reset type: SYSRSn. */
            __IM  uint32_t SDFFINT4                  : 1 ;     /*!< [23:23] : SDFIFO data ready interrupt for Ch4 Reset type: SYSRSn. */
            __IM  uint32_t SDFFUDF1                  : 1 ;     /*!< [24:24] : FIFO Underflow Flag for Ch1 0 - FIFO has not underflowed        <br>  1 - FIFO underflowed. */
            __IM  uint32_t SDFFUDF2                  : 1 ;     /*!< [25:25] : FIFO Underflow Flag for Ch2 Reset type: SYSRSn. */
            __IM  uint32_t SDFFUDF3                  : 1 ;     /*!< [26:26] : FIFO Underflow Flag for Ch3 Reset type: SYSRSn. */
            __IM  uint32_t SDFFUDF4                  : 1 ;     /*!< [27:27] : FIFO Underflow Flag for Ch4 Reset type: SYSRSn. */
                  uint32_t RSV_0                     : 3 ;     /*!< [30:28] : reserved. */
            __IM  uint32_t MIF                       : 1 ;     /*!< [31:31] : Set whenever any "error" interrupt                              <br>  (MF1-4,IFL1-4,IFH1-4,SDFFOVF1-4) is active                      <br>  Reset type: SYSRSn                                              <br>. */
        } SDIFLGb;
    };

    union
    {
        __IOM uint32_t SDIFLGCLR;  /*!< 0x00000004 */ 
       
        struct
        {
            __IOM uint32_t FLT1_FLG_CEVT1            : 1 ;     /*!< [0:0] : Flag Clear bit for FLT1_FLG_CEVT1 Reset type: SYSRSn. */
            __IOM uint32_t FLT1_FLG_CEVT2            : 1 ;     /*!< [1:1] : Flag Clear bit for FLT1_FLG_CEVT2 Reset type: SYSRSn. */
            __IOM uint32_t FLT2_FLG_CEVT1            : 1 ;     /*!< [2:2] : Flag Clear bit for FLT2_FLG_CEVT1 Reset type: SYSRSn. */
            __IOM uint32_t FLT2_FLG_CEVT2            : 1 ;     /*!< [3:3] : Flag Clear bit for FLT2_FLG_CEVT2 Reset type: SYSRSn. */
            __IOM uint32_t FLT3_FLG_CEVT1            : 1 ;     /*!< [4:4] : Flag Clear bit for FLT3_FLG_CEVT1 Reset type: SYSRSn. */
            __IOM uint32_t FLT3_FLG_CEVT2            : 1 ;     /*!< [5:5] : Flag Clear bit for FLT3_FLG_CEVT2 Reset type: SYSRSn. */
            __IOM uint32_t FLT4_FLG_CEVT1            : 1 ;     /*!< [6:6] : Flag Clear bit for FLT4_FLG_CEVT1 Reset type: SYSRSn. */
            __IOM uint32_t FLT4_FLG_CEVT2            : 1 ;     /*!< [7:7] : Flag Clear bit for FLT4_FLG_CEVT2 Reset type: SYSRSn. */
            __IOM uint32_t MF1                       : 1 ;     /*!< [8:8] : Flag Clear bit for MF1 Reset type: SYSRSn. */
            __IOM uint32_t MF2                       : 1 ;     /*!< [9:9] : Flag Clear bit for MF2 Reset type: SYSRSn. */
            __IOM uint32_t MF3                       : 1 ;     /*!< [10:10] : Flag Clear bit for MF3 Reset type: SYSRSn. */
            __IOM uint32_t MF4                       : 1 ;     /*!< [11:11] : Flag Clear bit for MF4 Reset type: SYSRSn. */
            __IOM uint32_t AF1                       : 1 ;     /*!< [12:12] : Flag Clear bit for AF1 Reset type: SYSRSn. */
            __IOM uint32_t AF2                       : 1 ;     /*!< [13:13] : Flag Clear bit for AF2 Reset type: SYSRSn. */
            __IOM uint32_t AF3                       : 1 ;     /*!< [14:14] : Flag Clear bit for AF3 Reset type: SYSRSn. */
            __IOM uint32_t AF4                       : 1 ;     /*!< [15:15] : Flag-clear bit for Acknowledge flag for Filter 4 Reset type: SYSRSn. */
            __IOM uint32_t SDFFOVF1                  : 1 ;     /*!< [16:16] : SDFIFO overflow clear Ch1 Reset type: SYSRSn. */
            __IOM uint32_t SDFFOVF2                  : 1 ;     /*!< [17:17] : SDFIFO overflow clear Ch2 Reset type: SYSRSn. */
            __IOM uint32_t SDFFOVF3                  : 1 ;     /*!< [18:18] : SDFIFO overflow clear Ch3 Reset type: SYSRSn. */
            __IOM uint32_t SDFFOVF4                  : 1 ;     /*!< [19:19] : SDFIFO overflow clear Ch4 Reset type: SYSRSn. */
            __IOM uint32_t SDFFINT1                  : 1 ;     /*!< [20:20] : SDFIFO data ready Interrupt flag-clear bit for Ch1 Reset type: SYSRSn. */
            __IOM uint32_t SDFFINT2                  : 1 ;     /*!< [21:21] : SDFIFO data ready Interrupt flag-clear bit for Ch2 Reset type: SYSRSn. */
            __IOM uint32_t SDFFINT3                  : 1 ;     /*!< [22:22] : SDFIFO data ready Interrupt flag-clear bit for Ch3 Reset type: SYSRSn. */
            __IOM uint32_t SDFFINT4                  : 1 ;     /*!< [23:23] : SDFIFO data ready Interrupt flag-clear bit for Ch4 Reset type: SYSRSn. */
            __IOM uint32_t SDFFUDF1                  : 1 ;     /*!< [24:24] : SDFIFO overflow clear Ch1 Reset type: SYSRSn. */
            __IOM uint32_t SDFFUDF2                  : 1 ;     /*!< [25:25] : SDFIFO overflow clear Ch2 Reset type: SYSRSn. */
            __IOM uint32_t SDFFUDF3                  : 1 ;     /*!< [26:26] : SDFIFO overflow clear Ch3 Reset type: SYSRSn. */
            __IOM uint32_t SDFFUDF4                  : 1 ;     /*!< [27:27] : SDFIFO overflow clear Ch4 Reset type: SYSRSn. */
                  uint32_t RSV_0                     : 3 ;     /*!< [30:28] : reserved. */
            __IOM uint32_t MIF                       : 1 ;     /*!< [31:31] : Flag-clear bit for SDFM Master Interrupt flag. */
        } SDIFLGCLRb;
    };

    union
    {
        __IOM uint32_t SDCTL;  /*!< 0x00000008 */ 
       
        struct
        {
            __IOM uint32_t HZ1                       : 1 ;     /*!< [0:0] : Flag Clear bit for HZ1 Reset type: SYSRSn. */
            __IOM uint32_t HZ2                       : 1 ;     /*!< [1:1] : Flag Clear bit for HZ2 Reset type: SYSRSn. */
            __IOM uint32_t HZ3                       : 1 ;     /*!< [2:2] : Flag Clear bit for HZ3 Reset type: SYSRSn. */
            __IOM uint32_t HZ4                       : 1 ;     /*!< [3:3] : Flag Clear bit for HZ4 Reset type: SYSRSn. */
                  uint32_t RSV_1                     : 9 ;     /*!< [12:4] : reserved. */
            __IOM uint32_t MIE                       : 1 ;     /*!< [13:13] : Master SDy_ERR interrupt enable                                 <br>  0: SDy_ERR Interrupt and interrupt flags are disabled 1: SDy_ERR Interrupt and interrupt flags are enabled Reset type: SYSRSn<br>. */
                  uint32_t RSV_0                     : 18;     /*!< [31:14] : reserved. */
        } SDCTLb;
    };

    union
    {
        __IOM uint16_t SDMFILEN;  /*!< 0x0000000c */ 
       
        struct
        {
                  uint16_t RSV_1                     : 11;     /*!< [10:0] : reserved. */
            __IOM uint16_t MFE                       : 1 ;     /*!< [11:11] : Master Filter Enable                                            <br>  0: All the four data filter units of SDFM module are disabled. */
                  uint16_t RSV_0                     : 4 ;     /*!< [15:12] : reserved. */
        } SDMFILENb;
    };

    union
    {
        __IM uint16_t SDSTATUS;  /*!< 0x0000000e */ 
       
        struct
        {
            __IM  uint16_t HZ1                       : 1 ;     /*!< [0:0] : High-level Threshold crossing (Z) flag Ch1                      <br>  Primarily intended for detecting "zero"-crossing events. */
            __IM  uint16_t HZ2                       : 1 ;     /*!< [1:1] : High-level Threshold crossing (Z) flag Ch2                      <br>  Primarily intended for detecting "zero"-crossing events. */
            __IM  uint16_t HZ3                       : 1 ;     /*!< [2:2] : High-level Threshold crossing (Z) flag Ch3                      <br>  Primarily intended for detecting "zero"-crossing events. */
            __IM  uint16_t HZ4                       : 1 ;     /*!< [3:3] : High-level Threshold crossing (Z) flag Ch4                      <br>  Primarily intended for detecting "zero"-crossing events. */
                  uint16_t RSV_0                     : 12;     /*!< [15:4] : reserved. */
        } SDSTATUSb;
    };

    uint8_t    RSV_0X10[16];   /*!< 0x00000010~0x0000001f : reserved */

    union
    {
        __IOM uint16_t SDCTLPARM1;  /*!< 0x00000020 */ 
       
        struct
        {
            __IOM uint16_t MOD                       : 2 ;     /*!< [1:0] : Delta-Sigma Modulator mode                                      <br>  00: The clock speed is equal to the data rate from the modulator<br>  01: The clock rate is half of the data rate from the modulator  <br>  10: The data from the modulator is Manchester decoded           <br>  11: The clock rate is twice the data rate of the modulator      <br>  Reset type: SYSRSn                                              <br>. */
                  uint16_t RSV_0                     : 14;     /*!< [15:2] : reserved. */
        } SDCTLPARM1b;
    };

    union
    {
        __IOM uint16_t SDDFPARM1;  /*!< 0x00000022 */ 
       
        struct
        {
            __IOM uint16_t DOSR                      : 8 ;     /*!< [7:0] : Data filter Oversampling ratio                                  <br>  The actual oversampling ratio of data filter is DOSR + 1 These bits set the oversampling ratio of the data filter. */
            __IOM uint16_t FEN                       : 1 ;     /*!< [8:8] : Filter Enable                                                   <br>  0: The data filter is disabled and no data is produced          <br>  1: The data filter is enabled and data are produced in the data filter Note: When filter is disabled, DOSR counter held in reset, filter data erased. */
            __IOM uint16_t AE                        : 1 ;     /*!< [9:9] : Data filter Acknowledge Enable                                  <br>  0: Acknowledge flag is disabled for the particular filter 1: Acknowledge flag is enabled for the particular filter Reset type: SYSRSn<br>. */
            __IOM uint16_t SST                       : 2 ;     /*!< [11:10] : Data filter structure                                           <br>  00: Data filter runs with a Sincfast structure 01: Data filter runs with a Sinc1 structure 10: Data filter runs with a Sinc2 structure 11: Data filter runs with a Sinc3 structure Reset type: SYSRSn<br>. */
            __IOM uint16_t SDSYNCEN                  : 1 ;     /*!< [12:12] : PWM synchronization (SDSYNC) of data filter 0: PWM synchronization of data filter is disabled 1: PWM synchronization of data filter is enabled<br>  Note: SDSYNCx. */
                  uint16_t RSV_0                     : 3 ;     /*!< [15:13] : reserved. */
        } SDDFPARM1b;
    };

    union
    {
        __IOM uint16_t SDDPARM1;  /*!< 0x00000024 */ 
       
        struct
        {
                  uint16_t RSV_0                     : 10;     /*!< [9:0] : reserved. */
            __IOM uint16_t DR                        : 1 ;     /*!< [10:10] : Data filter Data representation                                 <br>  0: Data stored in 16b 2's complement 1: Data stored in 32b 2's complement Reset type: SYSRSn<br>. */
            __IOM uint16_t SH                        : 5 ;     /*!< [15:11] : Shift Control                                                   <br>  These bits indicate by how many bits the 16-bit window is shifted up when 16-bit data representation is chosen. */
        } SDDPARM1b;
    };

    union
    {
        __IOM uint16_t SDFLT1CMPH1;  /*!< 0x00000026 */ 
       
        struct
        {
            __IOM uint16_t HLT                       : 15;     /*!< [14:0] : Unsigned high-level threshold for the comparator filter output. */
                  uint16_t RSV_0                     : 1 ;     /*!< [15:15] : reserved. */
        } SDFLT1CMPH1b;
    };

    union
    {
        __IOM uint16_t SDFLT1CMPL1;  /*!< 0x00000028 */ 
       
        struct
        {
            __IOM uint16_t LLT                       : 15;     /*!< [14:0] : Unsigned low-level threshold for the comparator filter output. */
                  uint16_t RSV_0                     : 1 ;     /*!< [15:15] : reserved. */
        } SDFLT1CMPL1b;
    };

    union
    {
        __IOM uint16_t SDCPARM1;  /*!< 0x0000002a */ 
       
        struct
        {
            __IOM uint16_t COSR                      : 5 ;     /*!< [4:0] : Comparator Oversampling ratio. */
            __IOM uint16_t EN_CEVT1                  : 1 ;     /*!< [5:5] : CEVT1 interrupt enable                                          <br>  0: Disable CEVT1 interrupt 1: Enable CEVT1 interrupt Reset type: SYSRSn<br>. */
            __IOM uint16_t EN_CEVT2                  : 1 ;     /*!< [6:6] : CEVT2 interrupt enable                                          <br>  0: Disable CEVT2 interrupt 1: Enable CEVT2 interrupt Reset type: SYSRSn<br>. */
            __IOM uint16_t CS1_CS0                   : 2 ;     /*!< [8:7] : Comparator filter structure                                     <br>  00: Comparator filter runs with a sincfast structure 01: Comparator filter runs with a Sinc1 structure 10: Comparator filter runs with a Sinc2 structure 11: Comparator filter runs with a Sinc3 structure Reset type: SYSRSn<br>. */
            __IOM uint16_t MFIE                      : 1 ;     /*!< [9:9] : Modulator Failure Interrupt Enable                              <br>  0: Disable modulator failure interrupt and its flag 1: Enable modulator failure interrupt and its flag Reset type: SYSRSn<br>. */
            __IOM uint16_t HZEN                      : 1 ;     /*!< [10:10] : High level (Z) Threshold crossing output enable 0: Disable Higher level Threshold (Z) crossing 1: Enable Higher level Threhold (Z) crossing Reset type: SYSRSn. */
            __IOM uint16_t CEVT1SEL                  : 2 ;     /*!< [12:11] : Comparator Event1 Select 00: COMPH1                             <br>  01: COMPL1 OR COMPH1                                            <br>  10: COMPH2                                                      <br>  11: COMPL2 OR COMPH2                                            <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint16_t CEN                       : 1 ;     /*!< [13:13] : Comparator Filter enable 0: Disable comparator filter 1: Enable comparator filter Reset type: SYSRSn. */
            __IOM uint16_t CEVT2SEL                  : 2 ;     /*!< [15:14] : Comparator Event2 Select 00: COMPL1                             <br>  01: COMPL1 OR COMPH1                                            <br>  10: COMPL2                                                      <br>  11: COMPL2 OR COMPH2                                            <br>  Reset type: SYSRSn                                              <br>. */
        } SDCPARM1b;
    };

    union
    {
        __IM uint32_t SDDATA1;  /*!< 0x0000002c */ 
       
        struct
        {
            __IM  uint32_t DATA16                    : 16;     /*!< [15:0] : Lo-order 16b in 32b mode, 16-bit Data in 16b mode Reset type: SYSRSn. */
            __IM  uint32_t DATA32HI                  : 16;     /*!< [31:16] : Hi-order 16b in 32b mode Reset type: SYSRSn. */
        } SDDATA1b;
    };

    union
    {
        __IM uint32_t SDDATFIFO1;  /*!< 0x00000030 */ 
       
        struct
        {
            __IM  uint32_t DATA16                    : 16;     /*!< [15:0] : Lo-order 16b in 32b mode, 16-bit Data in 16b mode Reset type: SYSRSn. */
            __IM  uint32_t DATA32HI                  : 16;     /*!< [31:16] : Hi-order 16b in 32b mode Reset type: SYSRSn. */
        } SDDATFIFO1b;
    };

    union
    {
        __IM uint16_t SDCDATA1;  /*!< 0x00000034 */ 
       
        struct
        {
            __IM  uint16_t DATA16                    : 16;     /*!< [15:0] : Comparator Data output - 16b only Reset type: SYSRSn. */
        } SDCDATA1b;
    };

    union
    {
        __IOM uint16_t SDFLT1CMPH2;  /*!< 0x00000036 */ 
       
        struct
        {
            __IOM uint16_t HLT2                      : 15;     /*!< [14:0] : Second Unsigned high-level threshold for the comparator filter output. */
                  uint16_t RSV_0                     : 1 ;     /*!< [15:15] : reserved. */
        } SDFLT1CMPH2b;
    };

    union
    {
        __IOM uint16_t SDFLT1CMPHZ;  /*!< 0x00000038 */ 
       
        struct
        {
            __IOM uint16_t HLTZ                      : 15;     /*!< [14:0] : Unsigned High-level threshold (Z) for the comparator filter output Primarily intended for detecting "zero"-crossing events. */
                  uint16_t RSV_0                     : 1 ;     /*!< [15:15] : reserved. */
        } SDFLT1CMPHZb;
    };

    union
    {
        __IOM uint16_t SDFIFOCTL1;  /*!< 0x0000003a */ 
       
        struct
        {
            __IOM uint16_t SDFFIL                    : 5 ;     /*!< [4:0] : SDFIFO interrupt level bits                                     <br>  The FIFO will generate an interrupt when the FIFO status (SDFFST) >= FIFO level (SDFFIL )<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint16_t DRDMASEL                  : 1 ;     /*!< [5:5] : Data-Ready DMA (DRDMA) source select                            <br>  0 = AF1 (Select non-FIFO data-ready interrupt)                  <br>  1 = SDFFINT1 (Select FIFO data-ready interrupt) Reset type: SYSRSn<br>. */
            __IM  uint16_t SDFFST                    : 5 ;     /*!< [10:6] : SDFIFO Status 00000 FIFO empty                                  <br>  00001 FIFO has 1 word                                           <br>  . */
            __IOM uint16_t UDFIEN                    : 1 ;     /*!< [11:11] : SDFIFO Underflow interrupt enable                               <br>  0: SDFIFO Underflow condition will not generate an interrupt    <br>  1: SDFIFO Underflow condition generates an interrupt on SDy_ERR Reset type: SYSRSn<br>. */
            __IOM uint16_t FFIEN                     : 1 ;     /*!< [12:12] : SDFIFO data ready Interrupt Enable Reset type: SYSRSn. */
            __IOM uint16_t FFEN                      : 1 ;     /*!< [13:13] : SDFIFO Enable                                                   <br>  0: Disable FIFO operation 1: Enable FIFO operation              <br>  Note: When FIFO is disabled, FIFO contents are cleared Reset type: SYSRSn<br>. */
            __IOM uint16_t DRINTSEL                  : 1 ;     /*!< [14:14] : Data-Ready Interrupt (DRINT) source select                      <br>  0 = AF1 (Select non-FIFO data-ready interrupt)                  <br>  1 = SDFFINT1 (Select FIFO data-ready interrupt) Reset type: SYSRSn<br>. */
            __IOM uint16_t OVFIEN                    : 1 ;     /*!< [15:15] : SDFIFO Overflow interrupt enable                                <br>  0: SDFIFO Overflow condition will not generate an interrupt     <br>  1: SDFIFO overflow condition generates an interrupt on SDy_ERR Reset type: SYSRSn<br>. */
        } SDFIFOCTL1b;
    };

    union
    {
        __IOM uint16_t SDSYNC1;  /*!< 0x0000003c */ 
       
        struct
        {
            __IOM uint16_t SYNCSEL                   : 6 ;     /*!< [5:0] : Defines source for the SDSYNC Input on this channel Refer SDSYNCx. */
            __IOM uint16_t WTSYNCEN                  : 1 ;     /*!< [6:6] : Wait-for-Sync Enable                                            <br>  0: Incoming Data written to SDFIFO on every Data-Ready (DR) Event<br>  1: Incoming Data written to SDFIFO on DR event only after SDSYNC event occurs<br>  Reset type: SYSRSn                                              <br>. */
            __IM  uint16_t WTSYNFLG                  : 1 ;     /*!< [7:7] : Wait-for-Sync Flag                                              <br>  0: SDSYNC event has not occurred 1: SDSYNC event occurred. */
            __IOM uint16_t WTSYNCLR                  : 1 ;     /*!< [8:8] : Wait-for-Sync Flag Clear (always reads 0) 0: Write of 0 has no affect<br>  1: Write of 1 clears WTSYNFLG Reset type: SYSRSn                <br>. */
            __IOM uint16_t FFSYNCCLREN               : 1 ;     /*!< [9:9] : FIFO Clear-on-SDSYNC Enable                                     <br>  0: SDFIFO is not automaticaly cleared upon receiving SDSYNC 1: SDFIFO is automaticaly cleared upon receiving SDSYNC Reset type: SYSRSn<br>. */
            __IOM uint16_t WTSCLREN                  : 1 ;     /*!< [10:10] : WTSYNFLG Clear-on-FIFOINT Enable                                <br>  0: WTSYNFLG can only be cleared manually (using WTSYNCLR bit) 1: WTSYNFLG is cleared automatically on SDFFINT<br>  Reset type: SYSRSn                                              <br>. */
                  uint16_t RSV_0                     : 5 ;     /*!< [15:11] : reserved. */
        } SDSYNC1b;
    };

    union
    {
        __IOM uint16_t SDFLT1CMPL2;  /*!< 0x0000003e */ 
       
        struct
        {
            __IOM uint16_t LLT2                      : 15;     /*!< [14:0] : Second Unsigned low-level threshold for the comparator filter output. */
                  uint16_t RSV_0                     : 1 ;     /*!< [15:15] : reserved. */
        } SDFLT1CMPL2b;
    };

    union
    {
        __IOM uint16_t SDCTLPARM2;  /*!< 0x00000040 */ 
       
        struct
        {
            __IOM uint16_t MOD                       : 2 ;     /*!< [1:0] : Delta-Sigma Modulator mode                                      <br>  00: The clock speed is equal to the data rate from the modulator<br>  01: The clock rate is half of the data rate from the modulator  <br>  10: The data from the modulator is Manchester decoded           <br>  11: The clock rate is twice the data rate of the modulator      <br>  Reset type: SYSRSn                                              <br>. */
                  uint16_t RSV_0                     : 14;     /*!< [15:2] : reserved. */
        } SDCTLPARM2b;
    };

    union
    {
        __IOM uint16_t SDDFPARM2;  /*!< 0x00000042 */ 
       
        struct
        {
            __IOM uint16_t DOSR                      : 8 ;     /*!< [7:0] : Data filter Oversampling ratio                                  <br>  The actual oversampling ratio of data filter is DOSR + 1 These bits set the oversampling ratio of the data filter. */
            __IOM uint16_t FEN                       : 1 ;     /*!< [8:8] : Filter Enable                                                   <br>  0: The data filter is disabled and no data is produced          <br>  1: The data filter is enabled and data are produced in the data filter Note: When filter is disabled, DOSR counter held in reset, filter data erased. */
            __IOM uint16_t AE                        : 1 ;     /*!< [9:9] : Data filter Acknowledge Enable                                  <br>  0: Acknowledge flag is disabled for the particular filter 1: Acknowledge flag is enabled for the particular filter Reset type: SYSRSn<br>. */
            __IOM uint16_t SST                       : 2 ;     /*!< [11:10] : Data filter structure                                           <br>  00: Data filter runs with a Sincfast structure 01: Data filter runs with a Sinc1 structure 10: Data filter runs with a Sinc2 structure 11: Data filter runs with a Sinc3 structure Reset type: SYSRSn<br>. */
            __IOM uint16_t SDSYNCEN                  : 1 ;     /*!< [12:12] : PWM synchronization (SDSYNC) of data filter 0: PWM synchronization of data filter is disabled 1: PWM synchronization of data filter is enabled<br>  Note: SDSYNCx. */
                  uint16_t RSV_0                     : 3 ;     /*!< [15:13] : reserved. */
        } SDDFPARM2b;
    };

    union
    {
        __IOM uint16_t SDDPARM2;  /*!< 0x00000044 */ 
       
        struct
        {
                  uint16_t RSV_0                     : 10;     /*!< [9:0] : reserved. */
            __IOM uint16_t DR                        : 1 ;     /*!< [10:10] : Data filter Data representation                                 <br>  0: Data stored in 16b 2's complement 1: Data stored in 32b 2's complement Reset type: SYSRSn<br>. */
            __IOM uint16_t SH                        : 5 ;     /*!< [15:11] : Shift Control                                                   <br>  These bits indicate by how many bits the 16-bit window is shifted up when 16-bit data representation is chosen. */
        } SDDPARM2b;
    };

    union
    {
        __IOM uint16_t SDFLT2CMPH1;  /*!< 0x00000046 */ 
       
        struct
        {
            __IOM uint16_t HLT                       : 15;     /*!< [14:0] : Unsigned high-level threshold for the comparator filter output. */
                  uint16_t RSV_0                     : 1 ;     /*!< [15:15] : reserved. */
        } SDFLT2CMPH1b;
    };

    union
    {
        __IOM uint16_t SDFLT2CMPL1;  /*!< 0x00000048 */ 
       
        struct
        {
            __IOM uint16_t LLT                       : 15;     /*!< [14:0] : Unsigned low-level threshold for the comparator filter output. */
                  uint16_t RSV_0                     : 1 ;     /*!< [15:15] : reserved. */
        } SDFLT2CMPL1b;
    };

    union
    {
        __IOM uint16_t SDCPARM2;  /*!< 0x0000004a */ 
       
        struct
        {
            __IOM uint16_t COSR                      : 5 ;     /*!< [4:0] : Comparator Oversampling ratio. */
            __IOM uint16_t EN_CEVT1                  : 1 ;     /*!< [5:5] : CEVT1 interrupt enable                                          <br>  0: Disable CEVT1 interrupt 1: Enable CEVT1 interrupt Reset type: SYSRSn<br>. */
            __IOM uint16_t EN_CEVT2                  : 1 ;     /*!< [6:6] : CEVT2 interrupt enable                                          <br>  0: Disable CEVT2 interrupt 1: Enable CEVT2 interrupt Reset type: SYSRSn<br>. */
            __IOM uint16_t CS1_CS0                   : 2 ;     /*!< [8:7] : Comparator filter structure                                     <br>  00: Comparator filter runs with a sincfast structure 01: Comparator filter runs with a Sinc1 structure 10: Comparator filter runs with a Sinc2 structure 11: Comparator filter runs with a Sinc3 structure Reset type: SYSRSn<br>. */
            __IOM uint16_t MFIE                      : 1 ;     /*!< [9:9] : Modulator Failure Interrupt Enable                              <br>  0: Disable modulator failure interrupt and its flag 1: Enable modulator failure interrupt and its flag Reset type: SYSRSn<br>. */
            __IOM uint16_t HZEN                      : 1 ;     /*!< [10:10] : High level (Z) Threshold crossing output enable 0: Disable Higher level Threshold (Z) crossing 1: Enable Higher level Threhold (Z) crossing Reset type: SYSRSn. */
            __IOM uint16_t CEVT1SEL                  : 2 ;     /*!< [12:11] : Comparator Event1 Select 00: COMPH1                             <br>  01: COMPL1 OR COMPH1                                            <br>  10: COMPH2                                                      <br>  11: COMPL2 OR COMPH2                                            <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint16_t CEN                       : 1 ;     /*!< [13:13] : Comparator Filter enable 0: Disable comparator filter 1: Enable comparator filter Reset type: SYSRSn. */
            __IOM uint16_t CEVT2SEL                  : 2 ;     /*!< [15:14] : Comparator Event2 Select 00: COMPL1                             <br>  01: COMPL1 OR COMPH1                                            <br>  10: COMPL2                                                      <br>  11: COMPL2 OR COMPH2                                            <br>  Reset type: SYSRSn                                              <br>. */
        } SDCPARM2b;
    };

    union
    {
        __IM uint32_t SDDATA2;  /*!< 0x0000004c */ 
       
        struct
        {
            __IM  uint32_t DATA16                    : 16;     /*!< [15:0] : Lo-order 16b in 32b mode Reset type: SYSRSn. */
            __IM  uint32_t DATA32HI                  : 16;     /*!< [31:16] : Hi-order 16b in 32b mode, 16-bit Data in 16b mode Reset type: SYSRSn. */
        } SDDATA2b;
    };

    union
    {
        __IM uint32_t SDDATFIFO2;  /*!< 0x00000050 */ 
       
        struct
        {
            __IM  uint32_t DATA16                    : 16;     /*!< [15:0] : Lo-order 16b in 32b mode Reset type: SYSRSn. */
            __IM  uint32_t DATA32HI                  : 16;     /*!< [31:16] : Hi-order 16b in 32b mode, 16-bit Data in 16b mode Reset type: SYSRSn. */
        } SDDATFIFO2b;
    };

    union
    {
        __IM uint16_t SDCDATA2;  /*!< 0x00000054 */ 
       
        struct
        {
            __IM  uint16_t DATA16                    : 16;     /*!< [15:0] : Comparator Data output - 16b only Reset type: SYSRSn. */
        } SDCDATA2b;
    };

    union
    {
        __IOM uint16_t SDFLT2CMPH2;  /*!< 0x00000056 */ 
       
        struct
        {
            __IOM uint16_t HLT2                      : 15;     /*!< [14:0] : Second Unsigned high-level threshold for the comparator filter output. */
                  uint16_t RSV_0                     : 1 ;     /*!< [15:15] : reserved. */
        } SDFLT2CMPH2b;
    };

    union
    {
        __IOM uint16_t SDFLT2CMPHZ;  /*!< 0x00000058 */ 
       
        struct
        {
            __IOM uint16_t HLTZ                      : 15;     /*!< [14:0] : Unsigned High-level threshold (Z) for the comparator filter output Primarily intended for detecting "zero"-crossing events. */
                  uint16_t RSV_0                     : 1 ;     /*!< [15:15] : reserved. */
        } SDFLT2CMPHZb;
    };

    union
    {
        __IOM uint16_t SDFIFOCTL2;  /*!< 0x0000005a */ 
       
        struct
        {
            __IOM uint16_t SDFFIL                    : 5 ;     /*!< [4:0] : SDFIFO interrupt level bits                                     <br>  The FIFO will generate an interrupt when the FIFO status (SDFFST) >= FIFO level (SDFFIL )<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint16_t DRDMASEL                  : 1 ;     /*!< [5:5] : Data-Ready DMA (DRDMA) source select                            <br>  0 = AF2 (Select non-FIFO data-ready interrupt)                  <br>  1 = SDFFINT2 (Select FIFO data-ready interrupt) Reset type: SYSRSn<br>. */
            __IM  uint16_t SDFFST                    : 5 ;     /*!< [10:6] : SDFIFO Status 00000 FIFO empty                                  <br>  00001 FIFO has 1 word                                           <br>  . */
            __IOM uint16_t UDFIEN                    : 1 ;     /*!< [11:11] : SDFIFO Underflow interrupt enable                               <br>  0: SDFIFO Underflow condition will not generate an interrupt    <br>  1: SDFIFO Underflow condition generates an interrupt on SDy_ERR Reset type: SYSRSn<br>. */
            __IOM uint16_t FFIEN                     : 1 ;     /*!< [12:12] : SDFIFO data ready Interrupt Enable Reset type: SYSRSn. */
            __IOM uint16_t FFEN                      : 1 ;     /*!< [13:13] : SDFIFO Enable                                                   <br>  0: Disable FIFO operation 1: Enable FIFO operation              <br>  Note: When FIFO is disabled, FIFO contents are cleared Reset type: SYSRSn<br>. */
            __IOM uint16_t DRINTSEL                  : 1 ;     /*!< [14:14] : Data-Ready Interrupt (DRINT) source select                      <br>  0 = AF1 (Select non-FIFO data-ready interrupt)                  <br>  1 = SDFFINT1 (Select FIFO data-ready interrupt) Reset type: SYSRSn<br>. */
            __IOM uint16_t OVFIEN                    : 1 ;     /*!< [15:15] : SDFIFO Overflow interrupt enable                                <br>  0: SDFIFO Overflow condition will not generate an interrupt     <br>  1: SDFIFO overflow condition generates an interrupt on SDy_ERR Reset type: SYSRSn<br>. */
        } SDFIFOCTL2b;
    };

    union
    {
        __IOM uint16_t SDSYNC2;  /*!< 0x0000005c */ 
       
        struct
        {
            __IOM uint16_t SYNCSEL                   : 6 ;     /*!< [5:0] : Defines source for the SDSYNC Input on this channel Refer SDSYNCx. */
            __IOM uint16_t WTSYNCEN                  : 1 ;     /*!< [6:6] : Wait-for-Sync Enable                                            <br>  0: Incoming Data written to SDFIFO on every Data-Ready (DR) Event<br>  1: Incoming Data written to SDFIFO on DR event only after SDSYNC event occurs<br>  Reset type: SYSRSn                                              <br>. */
            __IM  uint16_t WTSYNFLG                  : 1 ;     /*!< [7:7] : Wait-for-Sync Flag                                              <br>  0: SDSYNC event has not occurred 1: SDSYNC event occurred. */
            __IOM uint16_t WTSYNCLR                  : 1 ;     /*!< [8:8] : Wait-for-Sync Flag Clear (always reads 0) 0: Write of 0 has no affect<br>  1: Write of 1 clears WTSYNFLG Reset type: SYSRSn                <br>. */
            __IOM uint16_t FFSYNCCLREN               : 1 ;     /*!< [9:9] : FIFO Clear-on-SDSYNC Enable                                     <br>  0: SDFIFO is not automaticaly cleared upon receiving SDSYNC 1: SDFIFO is automaticaly cleared upon receiving SDSYNC Reset type: SYSRSn<br>. */
            __IOM uint16_t WTSCLREN                  : 1 ;     /*!< [10:10] : WTSYNFLG Clear-on-FIFOINT Enable                                <br>  0: WTSYNFLG can only be cleared manually (using WTSYNCLR bit) 1: WTSYNFLG is cleared automatically on SDFFINT<br>  Reset type: SYSRSn                                              <br>. */
                  uint16_t RSV_0                     : 5 ;     /*!< [15:11] : reserved. */
        } SDSYNC2b;
    };

    union
    {
        __IOM uint16_t SDFLT2CMPL2;  /*!< 0x0000005e */ 
       
        struct
        {
            __IOM uint16_t LLT2                      : 15;     /*!< [14:0] : Second Unsigned low-level threshold for the comparator filter output. */
                  uint16_t RSV_0                     : 1 ;     /*!< [15:15] : reserved. */
        } SDFLT2CMPL2b;
    };

    union
    {
        __IOM uint16_t SDCTLPARM3;  /*!< 0x00000060 */ 
       
        struct
        {
            __IOM uint16_t MOD                       : 2 ;     /*!< [1:0] : Delta-Sigma Modulator mode                                      <br>  00: The clock speed is equal to the data rate from the modulator<br>  01: The clock rate is half of the data rate from the modulator  <br>  10: The data from the modulator is Manchester decoded           <br>  11: The clock rate is twice the data rate of the modulator      <br>  Reset type: SYSRSn                                              <br>. */
                  uint16_t RSV_0                     : 14;     /*!< [15:2] : reserved. */
        } SDCTLPARM3b;
    };

    union
    {
        __IOM uint16_t SDDFPARM3;  /*!< 0x00000062 */ 
       
        struct
        {
            __IOM uint16_t DOSR                      : 8 ;     /*!< [7:0] : Data filter Oversampling ratio                                  <br>  The actual oversampling ratio of data filter is DOSR + 1 These bits set the oversampling ratio of the data filter. */
            __IOM uint16_t FEN                       : 1 ;     /*!< [8:8] : Filter Enable                                                   <br>  0: The data filter is disabled and no data is produced          <br>  1: The data filter is enabled and data are produced in the data filter Note: When filter is disabled, DOSR counter held in reset, filter data erased. */
            __IOM uint16_t AE                        : 1 ;     /*!< [9:9] : Data filter Acknowledge Enable                                  <br>  0: Acknowledge flag is disabled for the particular filter 1: Acknowledge flag is enabled for the particular filter Reset type: SYSRSn<br>. */
            __IOM uint16_t SST                       : 2 ;     /*!< [11:10] : Data filter structure                                           <br>  00: Data filter runs with a Sincfast structure 01: Data filter runs with a Sinc1 structure 10: Data filter runs with a Sinc2 structure 11: Data filter runs with a Sinc3 structure Reset type: SYSRSn<br>. */
            __IOM uint16_t SDSYNCEN                  : 1 ;     /*!< [12:12] : PWM synchronization (SDSYNC) of data filter 0: PWM synchronization of data filter is disabled 1: PWM synchronization of data filter is enabled<br>  Note: SDSYNCx. */
                  uint16_t RSV_0                     : 3 ;     /*!< [15:13] : reserved. */
        } SDDFPARM3b;
    };

    union
    {
        __IOM uint16_t SDDPARM3;  /*!< 0x00000064 */ 
       
        struct
        {
                  uint16_t RSV_0                     : 10;     /*!< [9:0] : reserved. */
            __IOM uint16_t DR                        : 1 ;     /*!< [10:10] : Data filter Data representation                                 <br>  0: Data stored in 16b 2's complement 1: Data stored in 32b 2's complement Reset type: SYSRSn<br>. */
            __IOM uint16_t SH                        : 5 ;     /*!< [15:11] : Shift Control                                                   <br>  These bits indicate by how many bits the 16-bit window is shifted up when 16-bit data representation is chosen. */
        } SDDPARM3b;
    };

    union
    {
        __IOM uint16_t SDFLT3CMPH1;  /*!< 0x00000066 */ 
       
        struct
        {
            __IOM uint16_t HLT                       : 15;     /*!< [14:0] : Unsigned high-level threshold for the comparator filter output. */
                  uint16_t RSV_0                     : 1 ;     /*!< [15:15] : reserved. */
        } SDFLT3CMPH1b;
    };

    union
    {
        __IOM uint16_t SDFLT3CMPL1;  /*!< 0x00000068 */ 
       
        struct
        {
            __IOM uint16_t LLT                       : 15;     /*!< [14:0] : Unsigned low-level threshold for the comparator filter output. */
                  uint16_t RSV_0                     : 1 ;     /*!< [15:15] : reserved. */
        } SDFLT3CMPL1b;
    };

    union
    {
        __IOM uint16_t SDCPARM3;  /*!< 0x0000006a */ 
       
        struct
        {
            __IOM uint16_t COSR                      : 5 ;     /*!< [4:0] : Comparator Oversampling ratio. */
            __IOM uint16_t EN_CEVT1                  : 1 ;     /*!< [5:5] : CEVT1 interrupt enable                                          <br>  0: Disable CEVT1 interrupt 1: Enable CEVT1 interrupt Reset type: SYSRSn<br>. */
            __IOM uint16_t EN_CEVT2                  : 1 ;     /*!< [6:6] : CEVT2 interrupt enable                                          <br>  0: Disable CEVT2 interrupt 1: Enable CEVT2 interrupt Reset type: SYSRSn<br>. */
            __IOM uint16_t CS1_CS0                   : 2 ;     /*!< [8:7] : Comparator filter structure                                     <br>  00: Comparator filter runs with a sincfast structure 01: Comparator filter runs with a Sinc1 structure 10: Comparator filter runs with a Sinc2 structure 11: Comparator filter runs with a Sinc3 structure Reset type: SYSRSn<br>. */
            __IOM uint16_t MFIE                      : 1 ;     /*!< [9:9] : Modulator Failure Interrupt Enable                              <br>  0: Disable modulator failure interrupt and its flag 1: Enable modulator failure interrupt and its flag Reset type: SYSRSn<br>. */
            __IOM uint16_t HZEN                      : 1 ;     /*!< [10:10] : High level (Z) Threshold crossing output enable 0: Disable Higher level Threshold (Z) crossing 1: Enable Higher level Threhold (Z) crossing Reset type: SYSRSn. */
            __IOM uint16_t CEVT1SEL                  : 2 ;     /*!< [12:11] : Comparator Event1 Select 00: COMPH1                             <br>  01: COMPL1 OR COMPH1                                            <br>  10: COMPH2                                                      <br>  11: COMPL2 OR COMPH2                                            <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint16_t CEN                       : 1 ;     /*!< [13:13] : Comparator Filter enable 0: Disable comparator filter 1: Enable comparator filter Reset type: SYSRSn. */
            __IOM uint16_t CEVT2SEL                  : 2 ;     /*!< [15:14] : Comparator Event2 Select 00: COMPL1                             <br>  01: COMPL1 OR COMPH1                                            <br>  10: COMPL2                                                      <br>  11: COMPL2 OR COMPH2                                            <br>  Reset type: SYSRSn                                              <br>. */
        } SDCPARM3b;
    };

    union
    {
        __IM uint32_t SDDATA3;  /*!< 0x0000006c */ 
       
        struct
        {
            __IM  uint32_t DATA16                    : 16;     /*!< [15:0] : Lo-order 16b in 32b mode Reset type: SYSRSn. */
            __IM  uint32_t DATA32HI                  : 16;     /*!< [31:16] : Hi-order 16b in 32b mode, 16-bit Data in 16b mode Reset type: SYSRSn. */
        } SDDATA3b;
    };

    union
    {
        __IM uint32_t SDDATFIFO3;  /*!< 0x00000070 */ 
       
        struct
        {
            __IM  uint32_t DATA16                    : 16;     /*!< [15:0] : Lo-order 16b in 32b mode Reset type: SYSRSn. */
            __IM  uint32_t DATA32HI                  : 16;     /*!< [31:16] : Hi-order 16b in 32b mode, 16-bit Data in 16b mode Reset type: SYSRSn. */
        } SDDATFIFO3b;
    };

    union
    {
        __IM uint16_t SDCDATA3;  /*!< 0x00000074 */ 
       
        struct
        {
            __IM  uint16_t DATA16                    : 16;     /*!< [15:0] : Comparator Data output - 16b only Reset type: SYSRSn. */
        } SDCDATA3b;
    };

    union
    {
        __IOM uint16_t SDFLT3CMPH2;  /*!< 0x00000076 */ 
       
        struct
        {
            __IOM uint16_t HLT2                      : 15;     /*!< [14:0] : Second Unsigned high-level threshold for the comparator filter output. */
                  uint16_t RSV_0                     : 1 ;     /*!< [15:15] : reserved. */
        } SDFLT3CMPH2b;
    };

    union
    {
        __IOM uint16_t SDFLT3CMPHZ;  /*!< 0x00000078 */ 
       
        struct
        {
            __IOM uint16_t HLTZ                      : 15;     /*!< [14:0] : Unsigned High-level threshold (Z) for the comparator filter output Primarily intended for detecting "zero"-crossing events. */
                  uint16_t RSV_0                     : 1 ;     /*!< [15:15] : reserved. */
        } SDFLT3CMPHZb;
    };

    union
    {
        __IOM uint16_t SDFIFOCTL3;  /*!< 0x0000007a */ 
       
        struct
        {
            __IOM uint16_t SDFFIL                    : 5 ;     /*!< [4:0] : SDFIFO interrupt level bits                                     <br>  The FIFO will generate an interrupt when the FIFO status (SDFFST) >= FIFO level (SDFFIL )<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint16_t DRDMASEL                  : 1 ;     /*!< [5:5] : Data-Ready DMA (DRDMA) source select                            <br>  0 = AF3 (Select non-FIFO data-ready interrupt)                  <br>  1 = SDFFINT3 (Select FIFO data-ready interrupt) Reset type: SYSRSn<br>. */
            __IM  uint16_t SDFFST                    : 5 ;     /*!< [10:6] : SDFIFO Status 00000 FIFO empty                                  <br>  00001 FIFO has 1 word                                           <br>  . */
            __IOM uint16_t UDFIEN                    : 1 ;     /*!< [11:11] : SDFIFO Underflow interrupt enable                               <br>  0: SDFIFO Underflow condition will not generate an interrupt    <br>  1: SDFIFO Underflow condition generates an interrupt on SDy_ERR Reset type: SYSRSn<br>. */
            __IOM uint16_t FFIEN                     : 1 ;     /*!< [12:12] : SDFIFO data ready Interrupt Enable Reset type: SYSRSn. */
            __IOM uint16_t FFEN                      : 1 ;     /*!< [13:13] : SDFIFO Enable                                                   <br>  0: Disable FIFO operation 1: Enable FIFO operation              <br>  Note: When FIFO is disabled, FIFO contents are cleared Reset type: SYSRSn<br>. */
            __IOM uint16_t DRINTSEL                  : 1 ;     /*!< [14:14] : Data-Ready Interrupt (DRINT) source select                      <br>  0 = AF1 (Select non-FIFO data-ready interrupt)                  <br>  1 = SDFFINT1 (Select FIFO data-ready interrupt) Reset type: SYSRSn<br>. */
            __IOM uint16_t OVFIEN                    : 1 ;     /*!< [15:15] : SDFIFO Overflow interrupt enable                                <br>  0: SDFIFO Overflow condition will not generate an interrupt     <br>  1: SDFIFO overflow condition generates an interrupt on SDy_ERR Reset type: SYSRSn<br>. */
        } SDFIFOCTL3b;
    };

    union
    {
        __IOM uint16_t SDSYNC3;  /*!< 0x0000007c */ 
       
        struct
        {
            __IOM uint16_t SYNCSEL                   : 6 ;     /*!< [5:0] : Defines source for the SDSYNC Input on this channel Refer SDSYNCx. */
            __IOM uint16_t WTSYNCEN                  : 1 ;     /*!< [6:6] : Wait-for-Sync Enable                                            <br>  0: Incoming Data written to SDFIFO on every Data-Ready (DR) Event<br>  1: Incoming Data written to SDFIFO on DR event only after SDSYNC event occurs<br>  Reset type: SYSRSn                                              <br>. */
            __IM  uint16_t WTSYNFLG                  : 1 ;     /*!< [7:7] : Wait-for-Sync Flag                                              <br>  0: SDSYNC event has not occurred 1: SDSYNC event occurred. */
            __IOM uint16_t WTSYNCLR                  : 1 ;     /*!< [8:8] : Wait-for-Sync Flag Clear (always reads 0) 0: Write of 0 has no affect<br>  1: Write of 1 clears WTSYNFLG Reset type: SYSRSn                <br>. */
            __IOM uint16_t FFSYNCCLREN               : 1 ;     /*!< [9:9] : FIFO Clear-on-SDSYNC Enable                                     <br>  0: SDFIFO is not automaticaly cleared upon receiving SDSYNC 1: SDFIFO is automaticaly cleared upon receiving SDSYNC Reset type: SYSRSn<br>. */
            __IOM uint16_t WTSCLREN                  : 1 ;     /*!< [10:10] : WTSYNFLG Clear-on-FIFOINT Enable                                <br>  0: WTSYNFLG can only be cleared manually (using WTSYNCLR bit) 1: WTSYNFLG is cleared automatically on SDFFINT<br>  Reset type: SYSRSn                                              <br>. */
                  uint16_t RSV_0                     : 5 ;     /*!< [15:11] : reserved. */
        } SDSYNC3b;
    };

    union
    {
        __IOM uint16_t SDFLT3CMPL2;  /*!< 0x0000007e */ 
       
        struct
        {
            __IOM uint16_t LLT2                      : 15;     /*!< [14:0] : Second Unsigned low-level threshold for the comparator filter output. */
                  uint16_t RSV_0                     : 1 ;     /*!< [15:15] : reserved. */
        } SDFLT3CMPL2b;
    };

    union
    {
        __IOM uint16_t SDCTLPARM4;  /*!< 0x00000080 */ 
       
        struct
        {
            __IOM uint16_t MOD                       : 2 ;     /*!< [1:0] : Delta-Sigma Modulator mode                                      <br>  00: The clock speed is equal to the data rate from the modulator<br>  01: The clock rate is half of the data rate from the modulator  <br>  10: The data from the modulator is Manchester decoded           <br>  11: The clock rate is twice the data rate of the modulator      <br>  Reset type: SYSRSn                                              <br>. */
                  uint16_t RSV_0                     : 14;     /*!< [15:2] : reserved. */
        } SDCTLPARM4b;
    };

    union
    {
        __IOM uint16_t SDDFPARM4;  /*!< 0x00000082 */ 
       
        struct
        {
            __IOM uint16_t DOSR                      : 8 ;     /*!< [7:0] : Data filter Oversampling ratio                                  <br>  The actual oversampling ratio of data filter is DOSR + 1 These bits set the oversampling ratio of the data filter. */
            __IOM uint16_t FEN                       : 1 ;     /*!< [8:8] : Filter Enable                                                   <br>  0: The data filter is disabled and no data is produced          <br>  1: The data filter is enabled and data are produced in the data filter Note: When filter is disabled, DOSR counter held in reset, filter data erased. */
            __IOM uint16_t AE                        : 1 ;     /*!< [9:9] : Data filter Acknowledge Enable                                  <br>  0: Acknowledge flag is disabled for the particular filter 1: Acknowledge flag is enabled for the particular filter Reset type: SYSRSn<br>. */
            __IOM uint16_t SST                       : 2 ;     /*!< [11:10] : Data filter structure                                           <br>  00: Data filter runs with a Sincfast structure 01: Data filter runs with a Sinc1 structure 10: Data filter runs with a Sinc2 structure 11: Data filter runs with a Sinc3 structure Reset type: SYSRSn<br>. */
            __IOM uint16_t SDSYNCEN                  : 1 ;     /*!< [12:12] : PWM synchronization (SDSYNC) of data filter 0: PWM synchronization of data filter is disabled 1: PWM synchronization of data filter is enabled<br>  Note: SDSYNCx. */
                  uint16_t RSV_0                     : 3 ;     /*!< [15:13] : reserved. */
        } SDDFPARM4b;
    };

    union
    {
        __IOM uint16_t SDDPARM4;  /*!< 0x00000084 */ 
       
        struct
        {
                  uint16_t RSV_0                     : 10;     /*!< [9:0] : reserved. */
            __IOM uint16_t DR                        : 1 ;     /*!< [10:10] : Data filter Data representation                                 <br>  0: Data stored in 16b 2's complement 1: Data stored in 32b 2's complement Reset type: SYSRSn<br>. */
            __IOM uint16_t SH                        : 5 ;     /*!< [15:11] : Shift Control                                                   <br>  These bits indicate by how many bits the 16-bit window is shifted up when 16-bit data representation is chosen. */
        } SDDPARM4b;
    };

    union
    {
        __IOM uint16_t SDFLT4CMPH1;  /*!< 0x00000086 */ 
       
        struct
        {
            __IOM uint16_t HLT                       : 15;     /*!< [14:0] : Unsigned high-level threshold for the comparator filter output. */
                  uint16_t RSV_0                     : 1 ;     /*!< [15:15] : reserved. */
        } SDFLT4CMPH1b;
    };

    union
    {
        __IOM uint16_t SDFLT4CMPL1;  /*!< 0x00000088 */ 
       
        struct
        {
            __IOM uint16_t LLT                       : 15;     /*!< [14:0] : Unsigned low-level threshold for the comparator filter output. */
                  uint16_t RSV_0                     : 1 ;     /*!< [15:15] : reserved. */
        } SDFLT4CMPL1b;
    };

    union
    {
        __IOM uint16_t SDCPARM4;  /*!< 0x0000008a */ 
       
        struct
        {
            __IOM uint16_t COSR                      : 5 ;     /*!< [4:0] : Comparator Oversampling ratio. */
            __IOM uint16_t EN_CEVT1                  : 1 ;     /*!< [5:5] : CEVT1 interrupt enable                                          <br>  0: Disable CEVT1 interrupt 1: Enable CEVT1 interrupt Reset type: SYSRSn<br>. */
            __IOM uint16_t EN_CEVT2                  : 1 ;     /*!< [6:6] : CEVT2 interrupt enable                                          <br>  0: Disable CEVT2 interrupt 1: Enable CEVT2 interrupt Reset type: SYSRSn<br>. */
            __IOM uint16_t CS1_CS0                   : 2 ;     /*!< [8:7] : Comparator filter structure                                     <br>  00: Comparator filter runs with a sincfast structure 01: Comparator filter runs with a Sinc1 structure 10: Comparator filter runs with a Sinc2 structure 11: Comparator filter runs with a Sinc3 structure Reset type: SYSRSn<br>. */
            __IOM uint16_t MFIE                      : 1 ;     /*!< [9:9] : Modulator Failure Interrupt Enable                              <br>  0: Disable modulator failure interrupt and its flag 1: Enable modulator failure interrupt and its flag Reset type: SYSRSn<br>. */
            __IOM uint16_t HZEN                      : 1 ;     /*!< [10:10] : High level (Z) Threshold crossing output enable 0: Disable Higher level Threshold (Z) crossing 1: Enable Higher level Threhold (Z) crossing Reset type: SYSRSn. */
            __IOM uint16_t CEVT1SEL                  : 2 ;     /*!< [12:11] : Comparator Event1 Select 00: COMPH1                             <br>  01: COMPL1 OR COMPH1                                            <br>  10: COMPH2                                                      <br>  11: COMPL2 OR COMPH2                                            <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint16_t CEN                       : 1 ;     /*!< [13:13] : Comparator Filter enable 0: Disable comparator filter 1: Enable comparator filter Reset type: SYSRSn. */
            __IOM uint16_t CEVT2SEL                  : 2 ;     /*!< [15:14] : Comparator Event2 Select 00: COMPL1                             <br>  01: COMPL1 OR COMPH1                                            <br>  10: COMPL2                                                      <br>  11: COMPL2 OR COMPH2                                            <br>  Reset type: SYSRSn                                              <br>. */
        } SDCPARM4b;
    };

    union
    {
        __IM uint32_t SDDATA4;  /*!< 0x0000008c */ 
       
        struct
        {
            __IM  uint32_t DATA16                    : 16;     /*!< [15:0] : Lo-order 16b in 32b mode Reset type: SYSRSn. */
            __IM  uint32_t DATA32HI                  : 16;     /*!< [31:16] : Hi-order 16b in 32b mode, 16-bit Data in 16b mode Reset type: SYSRSn. */
        } SDDATA4b;
    };

    union
    {
        __IM uint32_t SDDATFIFO4;  /*!< 0x00000090 */ 
       
        struct
        {
            __IM  uint32_t DATA16                    : 16;     /*!< [15:0] : Lo-order 16b in 32b mode Reset type: SYSRSn. */
            __IM  uint32_t DATA32HI                  : 16;     /*!< [31:16] : Hi-order 16b in 32b mode, 16-bit Data in 16b mode Reset type: SYSRSn. */
        } SDDATFIFO4b;
    };

    union
    {
        __IM uint16_t SDCDATA4;  /*!< 0x00000094 */ 
       
        struct
        {
            __IM  uint16_t DATA16                    : 16;     /*!< [15:0] : Comparator Data output - 16b only Reset type: SYSRSn. */
        } SDCDATA4b;
    };

    union
    {
        __IOM uint16_t SDFLT4CMPH2;  /*!< 0x00000096 */ 
       
        struct
        {
            __IOM uint16_t HLT2                      : 15;     /*!< [14:0] : Second Unsigned high-level threshold for the comparator filter output. */
                  uint16_t RSV_0                     : 1 ;     /*!< [15:15] : reserved. */
        } SDFLT4CMPH2b;
    };

    union
    {
        __IOM uint16_t SDFLT4CMPHZ;  /*!< 0x00000098 */ 
       
        struct
        {
            __IOM uint16_t HLTZ                      : 15;     /*!< [14:0] : Unsigned High-level threshold (Z) for the comparator filter output Primarily intended for detecting "zero"-crossing events. */
                  uint16_t RSV_0                     : 1 ;     /*!< [15:15] : reserved. */
        } SDFLT4CMPHZb;
    };

    union
    {
        __IOM uint16_t SDFIFOCTL4;  /*!< 0x0000009a */ 
       
        struct
        {
            __IOM uint16_t SDFFIL                    : 5 ;     /*!< [4:0] : SDFIFO interrupt level bits                                     <br>  The FIFO will generate an interrupt when the FIFO status (SDFFST) >= FIFO level (SDFFIL )<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint16_t DRDMASEL                  : 1 ;     /*!< [5:5] : Data-Ready DMA (DRDMA) source select                            <br>  0 = AF4 (Select non-FIFO data-ready interrupt)                  <br>  1 = SDFFINT4 (Select FIFO data-ready interrupt) Reset type: SYSRSn<br>. */
            __IM  uint16_t SDFFST                    : 5 ;     /*!< [10:6] : SDFIFO Status 00000 FIFO empty                                  <br>  00001 FIFO has 1 word                                           <br>  . */
            __IOM uint16_t UDFIEN                    : 1 ;     /*!< [11:11] : SDFIFO Underflow interrupt enable                               <br>  0: SDFIFO Underflow condition will not generate an interrupt    <br>  1: SDFIFO Underflow condition generates an interrupt on SDy_ERR Reset type: SYSRSn<br>. */
            __IOM uint16_t FFIEN                     : 1 ;     /*!< [12:12] : SDFIFO data ready Interrupt Enable Reset type: SYSRSn. */
            __IOM uint16_t FFEN                      : 1 ;     /*!< [13:13] : SDFIFO Enable                                                   <br>  0: Disable FIFO operation 1: Enable FIFO operation              <br>  Note: When FIFO is disabled, FIFO contents are cleared Reset type: SYSRSn<br>. */
            __IOM uint16_t DRINTSEL                  : 1 ;     /*!< [14:14] : Data-Ready Interrupt (DRINT) source select                      <br>  0 = AF1 (Select non-FIFO data-ready interrupt)                  <br>  1 = SDFFINT1 (Select FIFO data-ready interrupt) Reset type: SYSRSn<br>. */
            __IOM uint16_t OVFIEN                    : 1 ;     /*!< [15:15] : SDFIFO Overflow interrupt enable                                <br>  0: SDFIFO Overflow condition will not generate an interrupt     <br>  1: SDFIFO overflow condition generates an interrupt on SDy_ERR Reset type: SYSRSn<br>. */
        } SDFIFOCTL4b;
    };

    union
    {
        __IOM uint16_t SDSYNC4;  /*!< 0x0000009c */ 
       
        struct
        {
            __IOM uint16_t SYNCSEL                   : 6 ;     /*!< [5:0] : Defines source for the SDSYNC Input on this channel Refer SDSYNCx. */
            __IOM uint16_t WTSYNCEN                  : 1 ;     /*!< [6:6] : Wait-for-Sync Enable                                            <br>  0: Incoming Data written to SDFIFO on every Data-Ready (DR) Event<br>  1: Incoming Data written to SDFIFO on DR event only after SDSYNC event occurs<br>  Reset type: SYSRSn                                              <br>. */
            __IM  uint16_t WTSYNFLG                  : 1 ;     /*!< [7:7] : Wait-for-Sync Flag                                              <br>  0: SDSYNC event has not occurred 1: SDSYNC event occurred. */
            __IOM uint16_t WTSYNCLR                  : 1 ;     /*!< [8:8] : Wait-for-Sync Flag Clear (always reads 0) 0: Write of 0 has no affect<br>  1: Write of 1 clears WTSYNFLG Reset type: SYSRSn                <br>. */
            __IOM uint16_t FFSYNCCLREN               : 1 ;     /*!< [9:9] : FIFO Clear-on-SDSYNC Enable                                     <br>  0: SDFIFO is not automaticaly cleared upon receiving SDSYNC 1: SDFIFO is automaticaly cleared upon receiving SDSYNC Reset type: SYSRSn<br>. */
            __IOM uint16_t WTSCLREN                  : 1 ;     /*!< [10:10] : WTSYNFLG Clear-on-FIFOINT Enable                                <br>  0: WTSYNFLG can only be cleared manually (using WTSYNCLR bit) 1: WTSYNFLG is cleared automatically on SDFFINT<br>  Reset type: SYSRSn                                              <br>. */
                  uint16_t RSV_0                     : 5 ;     /*!< [15:11] : reserved. */
        } SDSYNC4b;
    };

    union
    {
        __IOM uint16_t SDFLT4CMPL2;  /*!< 0x0000009e */ 
       
        struct
        {
            __IOM uint16_t LLT2                      : 15;     /*!< [14:0] : Second Unsigned low-level threshold for the comparator filter output. */
                  uint16_t RSV_0                     : 1 ;     /*!< [15:15] : reserved. */
        } SDFLT4CMPL2b;
    };

    uint8_t    RSV_0XA0[32];   /*!< 0x000000a0~0x000000bf : reserved */

    union
    {
        __IOM uint16_t SDCOMP1CTL;  /*!< 0x000000c0 */ 
       
        struct
        {
                  uint16_t RSV_2                     : 2 ;     /*!< [1:0] : reserved. */
            __IOM uint16_t CEVT1DIGFILTSEL           : 2 ;     /*!< [3:2] : High comparator COMPH source select. */
                  uint16_t RSV_1                     : 6 ;     /*!< [9:4] : reserved. */
            __IOM uint16_t CEVT2DIGFILTSEL           : 2 ;     /*!< [11:10] : High comparator COMPH source select. */
                  uint16_t RSV_0                     : 4 ;     /*!< [15:12] : reserved. */
        } SDCOMP1CTLb;
    };

    union
    {
        __IOM uint16_t SDCOMP1EVT2FLTCTL;  /*!< 0x000000c2 */ 
       
        struct
        {
                  uint16_t RSV_1                     : 4 ;     /*!< [3:0] : reserved. */
            __IOM uint16_t SAMPWIN                   : 5 ;     /*!< [8:4] : Low filter sample window size. */
            __IOM uint16_t THRESH                    : 5 ;     /*!< [13:9] : Low filter majority voting threshold. */
                  uint16_t RSV_0                     : 1 ;     /*!< [14:14] : reserved. */
            __IOM uint16_t FILINIT                   : 1 ;     /*!< [15:15] : Low filter initialization. */
        } SDCOMP1EVT2FLTCTLb;
    };

    union
    {
        __IOM uint16_t SDCOMP1EVT2FLTCLKCTL;  /*!< 0x000000c4 */ 
       
        struct
        {
            __IOM uint16_t CLKPRESCALE               : 10;     /*!< [9:0] : Low filter sample clock prescale. */
                  uint16_t RSV_0                     : 6 ;     /*!< [15:10] : reserved. */
        } SDCOMP1EVT2FLTCLKCTLb;
    };

    union
    {
        __IOM uint16_t SDCOMP1EVT1FLTCTL;  /*!< 0x000000c6 */ 
       
        struct
        {
                  uint16_t RSV_1                     : 4 ;     /*!< [3:0] : reserved. */
            __IOM uint16_t SAMPWIN                   : 5 ;     /*!< [8:4] : Low filter sample window size. */
            __IOM uint16_t THRESH                    : 5 ;     /*!< [13:9] : Low filter majority voting threshold. */
                  uint16_t RSV_0                     : 1 ;     /*!< [14:14] : reserved. */
            __IOM uint16_t FILINIT                   : 1 ;     /*!< [15:15] : High filter initialization. */
        } SDCOMP1EVT1FLTCTLb;
    };

    union
    {
        __IOM uint16_t SDCOMP1EVT1FLTCLKCTL;  /*!< 0x000000c8 */ 
       
        struct
        {
            __IOM uint16_t CLKPRESCALE               : 10;     /*!< [9:0] : Low filter sample clock prescale. */
                  uint16_t RSV_0                     : 6 ;     /*!< [15:10] : reserved. */
        } SDCOMP1EVT1FLTCLKCTLb;
    };

    union
    {
        __IM uint16_t RESERVED1;  /*!< 0x000000ca */ 
       
        struct
        {
            __IM  uint16_t RSVD1_0                   : 16;     /*!< [15:0] : Reserved. */
        } RESERVED1b;
    };

    uint8_t    RSV_0XCC[2];   /*!< 0x000000cc~0x000000cd : reserved */

    union
    {
        __IOM uint16_t SDCOMP1LOCK;  /*!< 0x000000ce */ 
       
        struct
        {
            __IOM uint16_t SDCOMP1CTL                : 1 ;     /*!< [0:0] : Lock write-access to the SDCOMP1CTL register. */
                  uint16_t RSV_1                     : 2 ;     /*!< [2:1] : reserved. */
            __IOM uint16_t COMP                      : 1 ;     /*!< [3:3] : Lock write-access to the SDCOMP1EVT1/2FLTTCTL and COMP1FILCLKCTL registers. */
                  uint16_t RSV_0                     : 12;     /*!< [15:4] : reserved. */
        } SDCOMP1LOCKb;
    };

    union
    {
        __IOM uint16_t SDCOMP2CTL;  /*!< 0x000000d0 */ 
       
        struct
        {
                  uint16_t RSV_2                     : 2 ;     /*!< [1:0] : reserved. */
            __IOM uint16_t CEVT1DIGFILTSEL           : 2 ;     /*!< [3:2] : High comparator COMPH source select. */
                  uint16_t RSV_1                     : 6 ;     /*!< [9:4] : reserved. */
            __IOM uint16_t CEVT2DIGFILTSEL           : 2 ;     /*!< [11:10] : High comparator COMPH source select. */
                  uint16_t RSV_0                     : 4 ;     /*!< [15:12] : reserved. */
        } SDCOMP2CTLb;
    };

    union
    {
        __IOM uint16_t SDCOMP2EVT2FLTCTL;  /*!< 0x000000d2 */ 
       
        struct
        {
                  uint16_t RSV_1                     : 4 ;     /*!< [3:0] : reserved. */
            __IOM uint16_t SAMPWIN                   : 5 ;     /*!< [8:4] : Low filter sample window size. */
            __IOM uint16_t THRESH                    : 5 ;     /*!< [13:9] : Low filter majority voting threshold. */
                  uint16_t RSV_0                     : 1 ;     /*!< [14:14] : reserved. */
            __IOM uint16_t FILINIT                   : 1 ;     /*!< [15:15] : Low filter initialization. */
        } SDCOMP2EVT2FLTCTLb;
    };

    union
    {
        __IOM uint16_t SDCOMP2EVT2FLTCLKCTL;  /*!< 0x000000d4 */ 
       
        struct
        {
            __IOM uint16_t CLKPRESCALE               : 10;     /*!< [9:0] : Low filter sample clock prescale. */
                  uint16_t RSV_0                     : 6 ;     /*!< [15:10] : reserved. */
        } SDCOMP2EVT2FLTCLKCTLb;
    };

    union
    {
        __IOM uint16_t SDCOMP2EVT1FLTCTL;  /*!< 0x000000d6 */ 
       
        struct
        {
                  uint16_t RSV_1                     : 4 ;     /*!< [3:0] : reserved. */
            __IOM uint16_t SAMPWIN                   : 5 ;     /*!< [8:4] : Low filter sample window size. */
            __IOM uint16_t THRESH                    : 5 ;     /*!< [13:9] : Low filter majority voting threshold. */
                  uint16_t RSV_0                     : 1 ;     /*!< [14:14] : reserved. */
            __IOM uint16_t FILINIT                   : 1 ;     /*!< [15:15] : High filter initialization. */
        } SDCOMP2EVT1FLTCTLb;
    };

    union
    {
        __IOM uint16_t SDCOMP2EVT1FLTCLKCTL;  /*!< 0x000000d8 */ 
       
        struct
        {
            __IOM uint16_t CLKPRESCALE               : 10;     /*!< [9:0] : Low filter sample clock prescale. */
                  uint16_t RSV_0                     : 6 ;     /*!< [15:10] : reserved. */
        } SDCOMP2EVT1FLTCLKCTLb;
    };

    union
    {
        __IM uint16_t RESERVED2;  /*!< 0x000000da */ 
       
        struct
        {
            __IM  uint16_t RSVD2_0                   : 16;     /*!< [15:0] : Reserved. */
        } RESERVED2b;
    };

    uint8_t    RSV_0XDC[2];   /*!< 0x000000dc~0x000000dd : reserved */

    union
    {
        __IOM uint16_t SDCOMP2LOCK;  /*!< 0x000000de */ 
       
        struct
        {
            __IOM uint16_t SDCOMP2CTL                : 1 ;     /*!< [0:0] : Lock write-access to the SDCOMP2CTL register. */
                  uint16_t RSV_1                     : 2 ;     /*!< [2:1] : reserved. */
            __IOM uint16_t COMP                      : 1 ;     /*!< [3:3] : Lock write-access to the SDCOMP2EVT1/2FLTTCTL and COMP2FILCLKCTL registers. */
                  uint16_t RSV_0                     : 12;     /*!< [15:4] : reserved. */
        } SDCOMP2LOCKb;
    };

    union
    {
        __IOM uint16_t SDCOMP3CTL;  /*!< 0x000000e0 */ 
       
        struct
        {
                  uint16_t RSV_2                     : 2 ;     /*!< [1:0] : reserved. */
            __IOM uint16_t CEVT1DIGFILTSEL           : 2 ;     /*!< [3:2] : High comparator COMPH source select. */
                  uint16_t RSV_1                     : 6 ;     /*!< [9:4] : reserved. */
            __IOM uint16_t CEVT2DIGFILTSEL           : 2 ;     /*!< [11:10] : High comparator COMPH source select. */
                  uint16_t RSV_0                     : 4 ;     /*!< [15:12] : reserved. */
        } SDCOMP3CTLb;
    };

    union
    {
        __IOM uint16_t SDCOMP3EVT2FLTCTL;  /*!< 0x000000e2 */ 
       
        struct
        {
                  uint16_t RSV_1                     : 4 ;     /*!< [3:0] : reserved. */
            __IOM uint16_t SAMPWIN                   : 5 ;     /*!< [8:4] : Low filter sample window size. */
            __IOM uint16_t THRESH                    : 5 ;     /*!< [13:9] : Low filter majority voting threshold. */
                  uint16_t RSV_0                     : 1 ;     /*!< [14:14] : reserved. */
            __IOM uint16_t FILINIT                   : 1 ;     /*!< [15:15] : Low filter initialization. */
        } SDCOMP3EVT2FLTCTLb;
    };

    union
    {
        __IOM uint16_t SDCOMP3EVT2FLTCLKCTL;  /*!< 0x000000e4 */ 
       
        struct
        {
            __IOM uint16_t CLKPRESCALE               : 10;     /*!< [9:0] : Low filter sample clock prescale. */
                  uint16_t RSV_0                     : 6 ;     /*!< [15:10] : reserved. */
        } SDCOMP3EVT2FLTCLKCTLb;
    };

    union
    {
        __IOM uint16_t SDCOMP3EVT1FLTCTL;  /*!< 0x000000e6 */ 
       
        struct
        {
                  uint16_t RSV_1                     : 4 ;     /*!< [3:0] : reserved. */
            __IOM uint16_t SAMPWIN                   : 5 ;     /*!< [8:4] : Low filter sample window size. */
            __IOM uint16_t THRESH                    : 5 ;     /*!< [13:9] : Low filter majority voting threshold. */
                  uint16_t RSV_0                     : 1 ;     /*!< [14:14] : reserved. */
            __IOM uint16_t FILINIT                   : 1 ;     /*!< [15:15] : High filter initialization. */
        } SDCOMP3EVT1FLTCTLb;
    };

    union
    {
        __IOM uint16_t SDCOMP3EVT1FLTCLKCTL;  /*!< 0x000000e8 */ 
       
        struct
        {
            __IOM uint16_t CLKPRESCALE               : 10;     /*!< [9:0] : Low filter sample clock prescale. */
                  uint16_t RSV_0                     : 6 ;     /*!< [15:10] : reserved. */
        } SDCOMP3EVT1FLTCLKCTLb;
    };

    union
    {
        __IM uint16_t RESERVED3;  /*!< 0x000000ea */ 
       
        struct
        {
            __IM  uint16_t RSVD3_0                   : 16;     /*!< [15:0] : Reserved. */
        } RESERVED3b;
    };

    uint8_t    RSV_0XEC[2];   /*!< 0x000000ec~0x000000ed : reserved */

    union
    {
        __IOM uint16_t SDCOMP3LOCK;  /*!< 0x000000ee */ 
       
        struct
        {
            __IOM uint16_t SDCOMP3CTL                : 1 ;     /*!< [0:0] : Lock write-access to the SDCOMP3CTL register. */
                  uint16_t RSV_1                     : 2 ;     /*!< [2:1] : reserved. */
            __IOM uint16_t COMP                      : 1 ;     /*!< [3:3] : Lock write-access to the SDCOMP3EVT1/2FLTTCTL and COMP3FILCLKCTL registers. */
                  uint16_t RSV_0                     : 12;     /*!< [15:4] : reserved. */
        } SDCOMP3LOCKb;
    };

    union
    {
        __IOM uint16_t SDCOMP4CTL;  /*!< 0x000000f0 */ 
       
        struct
        {
                  uint16_t RSV_2                     : 2 ;     /*!< [1:0] : reserved. */
            __IOM uint16_t CEVT1DIGFILTSEL           : 2 ;     /*!< [3:2] : High comparator COMPH source select. */
                  uint16_t RSV_1                     : 6 ;     /*!< [9:4] : reserved. */
            __IOM uint16_t CEVT2DIGFILTSEL           : 2 ;     /*!< [11:10] : High comparator COMPH source select. */
                  uint16_t RSV_0                     : 4 ;     /*!< [15:12] : reserved. */
        } SDCOMP4CTLb;
    };

    union
    {
        __IOM uint16_t SDCOMP4EVT2FLTCTL;  /*!< 0x000000f2 */ 
       
        struct
        {
                  uint16_t RSV_1                     : 4 ;     /*!< [3:0] : reserved. */
            __IOM uint16_t SAMPWIN                   : 5 ;     /*!< [8:4] : Low filter sample window size. */
            __IOM uint16_t THRESH                    : 5 ;     /*!< [13:9] : Low filter majority voting threshold. */
                  uint16_t RSV_0                     : 1 ;     /*!< [14:14] : reserved. */
            __IOM uint16_t FILINIT                   : 1 ;     /*!< [15:15] : Low filter initialization. */
        } SDCOMP4EVT2FLTCTLb;
    };

    union
    {
        __IOM uint16_t SDCOMP4EVT2FLTCLKCTL;  /*!< 0x000000f4 */ 
       
        struct
        {
            __IOM uint16_t CLKPRESCALE               : 10;     /*!< [9:0] : Low filter sample clock prescale. */
                  uint16_t RSV_0                     : 6 ;     /*!< [15:10] : reserved. */
        } SDCOMP4EVT2FLTCLKCTLb;
    };

    union
    {
        __IOM uint16_t SDCOMP4EVT1FLTCTL;  /*!< 0x000000f6 */ 
       
        struct
        {
                  uint16_t RSV_1                     : 4 ;     /*!< [3:0] : reserved. */
            __IOM uint16_t SAMPWIN                   : 5 ;     /*!< [8:4] : Low filter sample window size. */
            __IOM uint16_t THRESH                    : 5 ;     /*!< [13:9] : Low filter majority voting threshold. */
                  uint16_t RSV_0                     : 1 ;     /*!< [14:14] : reserved. */
            __IOM uint16_t FILINIT                   : 1 ;     /*!< [15:15] : High filter initialization. */
        } SDCOMP4EVT1FLTCTLb;
    };

    union
    {
        __IOM uint16_t SDCOMP4EVT1FLTCLKCTL;  /*!< 0x000000f8 */ 
       
        struct
        {
            __IOM uint16_t CLKPRESCALE               : 10;     /*!< [9:0] : Low filter sample clock prescale. */
                  uint16_t RSV_0                     : 6 ;     /*!< [15:10] : reserved. */
        } SDCOMP4EVT1FLTCLKCTLb;
    };

    union
    {
        __IM uint16_t RESERVED4;  /*!< 0x000000fa */ 
       
        struct
        {
            __IM  uint16_t RSVD4_0                   : 16;     /*!< [15:0] : Reserved. */
        } RESERVED4b;
    };

    uint8_t    RSV_0XFC[2];   /*!< 0x000000fc~0x000000fd : reserved */

    union
    {
        __IOM uint16_t SDCOMP4LOCK;  /*!< 0x000000fe */ 
       
        struct
        {
            __IOM uint16_t SDCOMP4CTL                : 1 ;     /*!< [0:0] : Lock write-access to the SDCOMP4CTL register. */
                  uint16_t RSV_1                     : 2 ;     /*!< [2:1] : reserved. */
            __IOM uint16_t COMP                      : 1 ;     /*!< [3:3] : Lock write-access to the SDCOMP4EVT1/2FLTTCTL and COMP4FILCLKCTL registers. */
                  uint16_t RSV_0                     : 12;     /*!< [15:4] : reserved. */
        } SDCOMP4LOCKb;
    };

    union
    {
        __IOM uint32_t SDDMAEN;  /*!< 0x00000100 */ 
       
        struct
        {
            __IOM uint32_t FFDMAEN1                  : 1 ;     /*!< [0:0] : SDFIFO4 data ready DMA Enable Reset type: SYSRSn. */
            __IOM uint32_t FFDMAEN2                  : 1 ;     /*!< [1:1] : SDFIFO3 data ready DMA Enable Reset type: SYSRSn. */
            __IOM uint32_t FFDMAEN3                  : 1 ;     /*!< [2:2] : SDFIFO2 data ready DMA Enable Reset type: SYSRSn. */
            __IOM uint32_t FFDMAEN4                  : 1 ;     /*!< [3:3] : SDFIFO1 data ready DMA Enable Reset type: SYSRSn. */
                  uint32_t RSV_1                     : 4 ;     /*!< [7:4] : reserved. */
            __IOM uint32_t DMAEN1                    : 1 ;     /*!< [8:8] : DMA1 Enable                                                     <br>  0: DMA flag is disabled for the particular filter 1: DMA flag is enabled for the particular filter Reset type: SYSRSn<br>. */
            __IOM uint32_t DMAEN2                    : 1 ;     /*!< [9:9] : DMA2 Enable                                                     <br>  0: DMA flag is disabled for the particular filter 1: DMA flag is enabled for the particular filter Reset type: SYSRSn<br>. */
            __IOM uint32_t DMAEN3                    : 1 ;     /*!< [10:10] : DMA3 Enable                                                     <br>  0: DMA flag is disabled for the particular filter 1: DMA flag is enabled for the particular filter Reset type: SYSRSn<br>. */
            __IOM uint32_t DMAEN4                    : 1 ;     /*!< [11:11] : DMA4 Enable                                                     <br>  0: DMA flag is disabled for the particular filter 1: DMA flag is enabled for the particular filter Reset type: SYSRSn<br>. */
                  uint32_t RSV_0                     : 20;     /*!< [31:12] : reserved. */
        } SDDMAENb;
    };

    union
    {
        __IM uint32_t SDDMAFLG;  /*!< 0x00000104 */ 
       
        struct
        {
            __IM  uint32_t FFDMA1                    : 1 ;     /*!< [0:0] : SDFIFO data ready DMA for Ch1 Reset type: SYSRSn. */
            __IM  uint32_t FFDMA2                    : 1 ;     /*!< [1:1] : SDFIFO data ready DMA for Ch2 Reset type: SYSRSn. */
            __IM  uint32_t FFDMA3                    : 1 ;     /*!< [2:2] : SDFIFO data ready DMA for Ch3 Reset type: SYSRSn. */
            __IM  uint32_t FFDMA4                    : 1 ;     /*!< [3:3] : SDFIFO data ready DMA for Ch4 Reset type: SYSRSn. */
                  uint32_t RSV_1                     : 4 ;     /*!< [7:4] : reserved. */
            __IM  uint32_t DMAFLG1                   : 1 ;     /*!< [8:8] : DMA flag for Filter 1                                           <br>  0: No new data available for Filter (in non-FIFO mode) 1: New data available for Filter (in non-FIFO mode) Reset type: SYSRSn<br>. */
            __IM  uint32_t DMAFLG2                   : 1 ;     /*!< [9:9] : DMA flag for Filter 2                                           <br>  0: No new data available for Filter (in non-FIFO mode) 1: New data available for Filter (in non-FIFO mode) Reset type: SYSRSn<br>. */
            __IM  uint32_t DMAFLG3                   : 1 ;     /*!< [10:10] : DMA flag for Filter 3                                           <br>  0: No new data available for Filter (in non-FIFO mode) 1: New data available for Filter (in non-FIFO mode) Reset type: SYSRSn<br>. */
            __IM  uint32_t DMAFLG4                   : 1 ;     /*!< [11:11] : DMA flag for Filter 4                                           <br>  0: No new data available for Filter (in non-FIFO mode) 1: New data available for Filter (in non-FIFO mode) Reset type: SYSRSn<br>. */
                  uint32_t RSV_0                     : 20;     /*!< [31:12] : reserved. */
        } SDDMAFLGb;
    };

    union
    {
        __IM uint32_t SDMAXDATA1;  /*!< 0x00000108 */ 
       
        struct
        {
            __IM  uint32_t MAXDATA16                 : 16;     /*!< [15:0] : MAX Data. */
            __IM  uint32_t MAXDATA32HI               : 16;     /*!< [31:16] : MAX Data. */
        } SDMAXDATA1b;
    };

    union
    {
        __IM uint32_t SDMINDATA1;  /*!< 0x0000010c */ 
       
        struct
        {
            __IM  uint32_t MINDATA16                 : 16;     /*!< [15:0] : MIN Data. */
            __IM  uint32_t MINDATA32HI               : 16;     /*!< [31:16] : MIN Data. */
        } SDMINDATA1b;
    };

    union
    {
        __IM uint32_t SDMAXDATA2;  /*!< 0x00000110 */ 
       
        struct
        {
            __IM  uint32_t MAXDATA16                 : 16;     /*!< [15:0] : MAX Data. */
            __IM  uint32_t MAXDATA32HI               : 16;     /*!< [31:16] : MAX Data. */
        } SDMAXDATA2b;
    };

    union
    {
        __IM uint32_t SDMINDATA2;  /*!< 0x00000114 */ 
       
        struct
        {
            __IM  uint32_t MINDATA16                 : 16;     /*!< [15:0] : MIN Data. */
            __IM  uint32_t MINDATA32HI               : 16;     /*!< [31:16] : MIN Data. */
        } SDMINDATA2b;
    };

    union
    {
        __IM uint32_t SDMAXDATA3;  /*!< 0x00000118 */ 
       
        struct
        {
            __IM  uint32_t MAXDATA16                 : 16;     /*!< [15:0] : MAX Data. */
            __IM  uint32_t MAXDATA32HI               : 16;     /*!< [31:16] : MAX Data. */
        } SDMAXDATA3b;
    };

    union
    {
        __IM uint32_t SDMINDATA3;  /*!< 0x0000011c */ 
       
        struct
        {
            __IM  uint32_t MINDATA16                 : 16;     /*!< [15:0] : MIN Data. */
            __IM  uint32_t MINDATA32HI               : 16;     /*!< [31:16] : MIN Data. */
        } SDMINDATA3b;
    };

    union
    {
        __IM uint32_t SDMAXDATA4;  /*!< 0x00000120 */ 
       
        struct
        {
            __IM  uint32_t MAXDATA16                 : 16;     /*!< [15:0] : MAX Data. */
            __IM  uint32_t MAXDATA32HI               : 16;     /*!< [31:16] : MAX Data. */
        } SDMAXDATA4b;
    };

    union
    {
        __IM uint32_t SDMINDATA4;  /*!< 0x00000124 */ 
       
        struct
        {
            __IM  uint32_t MINDATA16                 : 16;     /*!< [15:0] : MIN Data. */
            __IM  uint32_t MINDATA32HI               : 16;     /*!< [31:16] : MIN Data. */
        } SDMINDATA4b;
    };

    union
    {
        __IM uint32_t SDCMAXDATA1;  /*!< 0x00000128 */ 
       
        struct
        {
            __IM  uint32_t MAXDATA16                 : 16;     /*!< [15:0] : MAX Data. */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } SDCMAXDATA1b;
    };

    union
    {
        __IM uint32_t SDCMINDATA1;  /*!< 0x0000012c */ 
       
        struct
        {
            __IM  uint32_t MINDATA16                 : 16;     /*!< [15:0] : MIN Data. */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } SDCMINDATA1b;
    };

    union
    {
        __IM uint32_t SDCMAXDATA2;  /*!< 0x00000130 */ 
       
        struct
        {
            __IM  uint32_t MAXDATA16                 : 16;     /*!< [15:0] : MAX Data. */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } SDCMAXDATA2b;
    };

    union
    {
        __IM uint32_t SDCMINDATA2;  /*!< 0x00000134 */ 
       
        struct
        {
            __IM  uint32_t MINDATA16                 : 16;     /*!< [15:0] : MIN Data. */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } SDCMINDATA2b;
    };

    union
    {
        __IM uint32_t SDCMAXDATA3;  /*!< 0x00000138 */ 
       
        struct
        {
            __IM  uint32_t MAXDATA16                 : 16;     /*!< [15:0] : MAX Data. */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } SDCMAXDATA3b;
    };

    union
    {
        __IM uint32_t SDCMINDATA3;  /*!< 0x0000013c */ 
       
        struct
        {
            __IM  uint32_t MINDATA16                 : 16;     /*!< [15:0] : MIN Data. */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } SDCMINDATA3b;
    };

    union
    {
        __IM uint32_t SDCMAXDATA4;  /*!< 0x00000140 */ 
       
        struct
        {
            __IM  uint32_t MAXDATA16                 : 16;     /*!< [15:0] : MAX Data. */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } SDCMAXDATA4b;
    };

    union
    {
        __IM uint32_t SDCMINDATA4;  /*!< 0x00000144 */ 
       
        struct
        {
            __IM  uint32_t MINDATA16                 : 16;     /*!< [15:0] : MIN Data. */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } SDCMINDATA4b;
    };
} SDFM_REGS_Type;

/*!
 * @}
 */

/*!
 * \name SDFM Base Address Definitions
 *
 * @{
 */

 /*! \brief SDFM1 base address */
#define SDFM1_BASE (0x40800000UL)
/*! \brief SDFM2 base address */
#define SDFM2_BASE (0x40800400UL)

/*! \brief SDFM1 base pointer */
#define SDFM1 ((SDFM_REGS_Type *) SDFM1_BASE)
/*! \brief SDFM1 base pointer */
#define SDFM2 ((SDFM_REGS_Type *) SDFM2_BASE)


/*!
 * @}
 */

 
/*!
 * \name SDFM Register Bitfield Definitions
 *
 * @{
 */

 /* SDIFLG bitfield */
#define SDFM_SDIFLG_MIF_Pos    (31U)                                                                                 /*!< MIF Postion   31         */ 
#define SDFM_SDIFLG_MIF_Msk    (0x1U << SDFM_SDIFLG_MIF_Pos)                                                    /*!< MIF Mask      0x80000000 */
#define SDFM_SDIFLG_MIF_Set(x) (((uint32_t) (x) << SDFM_SDIFLG_MIF_Pos) & SDFM_SDIFLG_MIF_Msk)             /*!< MIF Set Value            */
#define SDFM_SDIFLG_MIF_Get(x) (((uint32_t) (x) & SDFM_SDIFLG_MIF_Msk) >> SDFM_SDIFLG_MIF_Pos)             /*!< MIF Get Value            */


#define SDFM_SDIFLG_SDFFUDF4_Pos    (27U)                                                                                 /*!< SDFFUDF4 Postion   27         */ 
#define SDFM_SDIFLG_SDFFUDF4_Msk    (0x1U << SDFM_SDIFLG_SDFFUDF4_Pos)                                               /*!< SDFFUDF4 Mask      0x08000000 */
#define SDFM_SDIFLG_SDFFUDF4_Set(x) (((uint32_t) (x) << SDFM_SDIFLG_SDFFUDF4_Pos) & SDFM_SDIFLG_SDFFUDF4_Msk)   /*!< SDFFUDF4 Set Value            */
#define SDFM_SDIFLG_SDFFUDF4_Get(x) (((uint32_t) (x) & SDFM_SDIFLG_SDFFUDF4_Msk) >> SDFM_SDIFLG_SDFFUDF4_Pos)   /*!< SDFFUDF4 Get Value            */


#define SDFM_SDIFLG_SDFFUDF3_Pos    (26U)                                                                                 /*!< SDFFUDF3 Postion   26         */ 
#define SDFM_SDIFLG_SDFFUDF3_Msk    (0x1U << SDFM_SDIFLG_SDFFUDF3_Pos)                                               /*!< SDFFUDF3 Mask      0x04000000 */
#define SDFM_SDIFLG_SDFFUDF3_Set(x) (((uint32_t) (x) << SDFM_SDIFLG_SDFFUDF3_Pos) & SDFM_SDIFLG_SDFFUDF3_Msk)   /*!< SDFFUDF3 Set Value            */
#define SDFM_SDIFLG_SDFFUDF3_Get(x) (((uint32_t) (x) & SDFM_SDIFLG_SDFFUDF3_Msk) >> SDFM_SDIFLG_SDFFUDF3_Pos)   /*!< SDFFUDF3 Get Value            */


#define SDFM_SDIFLG_SDFFUDF2_Pos    (25U)                                                                                 /*!< SDFFUDF2 Postion   25         */ 
#define SDFM_SDIFLG_SDFFUDF2_Msk    (0x1U << SDFM_SDIFLG_SDFFUDF2_Pos)                                               /*!< SDFFUDF2 Mask      0x02000000 */
#define SDFM_SDIFLG_SDFFUDF2_Set(x) (((uint32_t) (x) << SDFM_SDIFLG_SDFFUDF2_Pos) & SDFM_SDIFLG_SDFFUDF2_Msk)   /*!< SDFFUDF2 Set Value            */
#define SDFM_SDIFLG_SDFFUDF2_Get(x) (((uint32_t) (x) & SDFM_SDIFLG_SDFFUDF2_Msk) >> SDFM_SDIFLG_SDFFUDF2_Pos)   /*!< SDFFUDF2 Get Value            */


#define SDFM_SDIFLG_SDFFUDF1_Pos    (24U)                                                                                 /*!< SDFFUDF1 Postion   24         */ 
#define SDFM_SDIFLG_SDFFUDF1_Msk    (0x1U << SDFM_SDIFLG_SDFFUDF1_Pos)                                               /*!< SDFFUDF1 Mask      0x01000000 */
#define SDFM_SDIFLG_SDFFUDF1_Set(x) (((uint32_t) (x) << SDFM_SDIFLG_SDFFUDF1_Pos) & SDFM_SDIFLG_SDFFUDF1_Msk)   /*!< SDFFUDF1 Set Value            */
#define SDFM_SDIFLG_SDFFUDF1_Get(x) (((uint32_t) (x) & SDFM_SDIFLG_SDFFUDF1_Msk) >> SDFM_SDIFLG_SDFFUDF1_Pos)   /*!< SDFFUDF1 Get Value            */


#define SDFM_SDIFLG_SDFFINT4_Pos    (23U)                                                                                 /*!< SDFFINT4 Postion   23         */ 
#define SDFM_SDIFLG_SDFFINT4_Msk    (0x1U << SDFM_SDIFLG_SDFFINT4_Pos)                                               /*!< SDFFINT4 Mask      0x00800000 */
#define SDFM_SDIFLG_SDFFINT4_Set(x) (((uint32_t) (x) << SDFM_SDIFLG_SDFFINT4_Pos) & SDFM_SDIFLG_SDFFINT4_Msk)   /*!< SDFFINT4 Set Value            */
#define SDFM_SDIFLG_SDFFINT4_Get(x) (((uint32_t) (x) & SDFM_SDIFLG_SDFFINT4_Msk) >> SDFM_SDIFLG_SDFFINT4_Pos)   /*!< SDFFINT4 Get Value            */


#define SDFM_SDIFLG_SDFFINT3_Pos    (22U)                                                                                 /*!< SDFFINT3 Postion   22         */ 
#define SDFM_SDIFLG_SDFFINT3_Msk    (0x1U << SDFM_SDIFLG_SDFFINT3_Pos)                                               /*!< SDFFINT3 Mask      0x00400000 */
#define SDFM_SDIFLG_SDFFINT3_Set(x) (((uint32_t) (x) << SDFM_SDIFLG_SDFFINT3_Pos) & SDFM_SDIFLG_SDFFINT3_Msk)   /*!< SDFFINT3 Set Value            */
#define SDFM_SDIFLG_SDFFINT3_Get(x) (((uint32_t) (x) & SDFM_SDIFLG_SDFFINT3_Msk) >> SDFM_SDIFLG_SDFFINT3_Pos)   /*!< SDFFINT3 Get Value            */


#define SDFM_SDIFLG_SDFFINT2_Pos    (21U)                                                                                 /*!< SDFFINT2 Postion   21         */ 
#define SDFM_SDIFLG_SDFFINT2_Msk    (0x1U << SDFM_SDIFLG_SDFFINT2_Pos)                                               /*!< SDFFINT2 Mask      0x00200000 */
#define SDFM_SDIFLG_SDFFINT2_Set(x) (((uint32_t) (x) << SDFM_SDIFLG_SDFFINT2_Pos) & SDFM_SDIFLG_SDFFINT2_Msk)   /*!< SDFFINT2 Set Value            */
#define SDFM_SDIFLG_SDFFINT2_Get(x) (((uint32_t) (x) & SDFM_SDIFLG_SDFFINT2_Msk) >> SDFM_SDIFLG_SDFFINT2_Pos)   /*!< SDFFINT2 Get Value            */


#define SDFM_SDIFLG_SDFFINT1_Pos    (20U)                                                                                 /*!< SDFFINT1 Postion   20         */ 
#define SDFM_SDIFLG_SDFFINT1_Msk    (0x1U << SDFM_SDIFLG_SDFFINT1_Pos)                                               /*!< SDFFINT1 Mask      0x00100000 */
#define SDFM_SDIFLG_SDFFINT1_Set(x) (((uint32_t) (x) << SDFM_SDIFLG_SDFFINT1_Pos) & SDFM_SDIFLG_SDFFINT1_Msk)   /*!< SDFFINT1 Set Value            */
#define SDFM_SDIFLG_SDFFINT1_Get(x) (((uint32_t) (x) & SDFM_SDIFLG_SDFFINT1_Msk) >> SDFM_SDIFLG_SDFFINT1_Pos)   /*!< SDFFINT1 Get Value            */


#define SDFM_SDIFLG_SDFFOVF4_Pos    (19U)                                                                                 /*!< SDFFOVF4 Postion   19         */ 
#define SDFM_SDIFLG_SDFFOVF4_Msk    (0x1U << SDFM_SDIFLG_SDFFOVF4_Pos)                                               /*!< SDFFOVF4 Mask      0x00080000 */
#define SDFM_SDIFLG_SDFFOVF4_Set(x) (((uint32_t) (x) << SDFM_SDIFLG_SDFFOVF4_Pos) & SDFM_SDIFLG_SDFFOVF4_Msk)   /*!< SDFFOVF4 Set Value            */
#define SDFM_SDIFLG_SDFFOVF4_Get(x) (((uint32_t) (x) & SDFM_SDIFLG_SDFFOVF4_Msk) >> SDFM_SDIFLG_SDFFOVF4_Pos)   /*!< SDFFOVF4 Get Value            */


#define SDFM_SDIFLG_SDFFOVF3_Pos    (18U)                                                                                 /*!< SDFFOVF3 Postion   18         */ 
#define SDFM_SDIFLG_SDFFOVF3_Msk    (0x1U << SDFM_SDIFLG_SDFFOVF3_Pos)                                               /*!< SDFFOVF3 Mask      0x00040000 */
#define SDFM_SDIFLG_SDFFOVF3_Set(x) (((uint32_t) (x) << SDFM_SDIFLG_SDFFOVF3_Pos) & SDFM_SDIFLG_SDFFOVF3_Msk)   /*!< SDFFOVF3 Set Value            */
#define SDFM_SDIFLG_SDFFOVF3_Get(x) (((uint32_t) (x) & SDFM_SDIFLG_SDFFOVF3_Msk) >> SDFM_SDIFLG_SDFFOVF3_Pos)   /*!< SDFFOVF3 Get Value            */


#define SDFM_SDIFLG_SDFFOVF2_Pos    (17U)                                                                                 /*!< SDFFOVF2 Postion   17         */ 
#define SDFM_SDIFLG_SDFFOVF2_Msk    (0x1U << SDFM_SDIFLG_SDFFOVF2_Pos)                                               /*!< SDFFOVF2 Mask      0x00020000 */
#define SDFM_SDIFLG_SDFFOVF2_Set(x) (((uint32_t) (x) << SDFM_SDIFLG_SDFFOVF2_Pos) & SDFM_SDIFLG_SDFFOVF2_Msk)   /*!< SDFFOVF2 Set Value            */
#define SDFM_SDIFLG_SDFFOVF2_Get(x) (((uint32_t) (x) & SDFM_SDIFLG_SDFFOVF2_Msk) >> SDFM_SDIFLG_SDFFOVF2_Pos)   /*!< SDFFOVF2 Get Value            */


#define SDFM_SDIFLG_SDFFOVF1_Pos    (16U)                                                                                 /*!< SDFFOVF1 Postion   16         */ 
#define SDFM_SDIFLG_SDFFOVF1_Msk    (0x1U << SDFM_SDIFLG_SDFFOVF1_Pos)                                               /*!< SDFFOVF1 Mask      0x00010000 */
#define SDFM_SDIFLG_SDFFOVF1_Set(x) (((uint32_t) (x) << SDFM_SDIFLG_SDFFOVF1_Pos) & SDFM_SDIFLG_SDFFOVF1_Msk)   /*!< SDFFOVF1 Set Value            */
#define SDFM_SDIFLG_SDFFOVF1_Get(x) (((uint32_t) (x) & SDFM_SDIFLG_SDFFOVF1_Msk) >> SDFM_SDIFLG_SDFFOVF1_Pos)   /*!< SDFFOVF1 Get Value            */


#define SDFM_SDIFLG_AF4_Pos    (15U)                                                                                 /*!< AF4 Postion   15         */ 
#define SDFM_SDIFLG_AF4_Msk    (0x1U << SDFM_SDIFLG_AF4_Pos)                                                    /*!< AF4 Mask      0x00008000 */
#define SDFM_SDIFLG_AF4_Set(x) (((uint32_t) (x) << SDFM_SDIFLG_AF4_Pos) & SDFM_SDIFLG_AF4_Msk)             /*!< AF4 Set Value            */
#define SDFM_SDIFLG_AF4_Get(x) (((uint32_t) (x) & SDFM_SDIFLG_AF4_Msk) >> SDFM_SDIFLG_AF4_Pos)             /*!< AF4 Get Value            */


#define SDFM_SDIFLG_AF3_Pos    (14U)                                                                                 /*!< AF3 Postion   14         */ 
#define SDFM_SDIFLG_AF3_Msk    (0x1U << SDFM_SDIFLG_AF3_Pos)                                                    /*!< AF3 Mask      0x00004000 */
#define SDFM_SDIFLG_AF3_Set(x) (((uint32_t) (x) << SDFM_SDIFLG_AF3_Pos) & SDFM_SDIFLG_AF3_Msk)             /*!< AF3 Set Value            */
#define SDFM_SDIFLG_AF3_Get(x) (((uint32_t) (x) & SDFM_SDIFLG_AF3_Msk) >> SDFM_SDIFLG_AF3_Pos)             /*!< AF3 Get Value            */


#define SDFM_SDIFLG_AF2_Pos    (13U)                                                                                 /*!< AF2 Postion   13         */ 
#define SDFM_SDIFLG_AF2_Msk    (0x1U << SDFM_SDIFLG_AF2_Pos)                                                    /*!< AF2 Mask      0x00002000 */
#define SDFM_SDIFLG_AF2_Set(x) (((uint32_t) (x) << SDFM_SDIFLG_AF2_Pos) & SDFM_SDIFLG_AF2_Msk)             /*!< AF2 Set Value            */
#define SDFM_SDIFLG_AF2_Get(x) (((uint32_t) (x) & SDFM_SDIFLG_AF2_Msk) >> SDFM_SDIFLG_AF2_Pos)             /*!< AF2 Get Value            */


#define SDFM_SDIFLG_AF1_Pos    (12U)                                                                                 /*!< AF1 Postion   12         */ 
#define SDFM_SDIFLG_AF1_Msk    (0x1U << SDFM_SDIFLG_AF1_Pos)                                                    /*!< AF1 Mask      0x00001000 */
#define SDFM_SDIFLG_AF1_Set(x) (((uint32_t) (x) << SDFM_SDIFLG_AF1_Pos) & SDFM_SDIFLG_AF1_Msk)             /*!< AF1 Set Value            */
#define SDFM_SDIFLG_AF1_Get(x) (((uint32_t) (x) & SDFM_SDIFLG_AF1_Msk) >> SDFM_SDIFLG_AF1_Pos)             /*!< AF1 Get Value            */


#define SDFM_SDIFLG_MF4_Pos    (11U)                                                                                 /*!< MF4 Postion   11         */ 
#define SDFM_SDIFLG_MF4_Msk    (0x1U << SDFM_SDIFLG_MF4_Pos)                                                    /*!< MF4 Mask      0x00000800 */
#define SDFM_SDIFLG_MF4_Set(x) (((uint32_t) (x) << SDFM_SDIFLG_MF4_Pos) & SDFM_SDIFLG_MF4_Msk)             /*!< MF4 Set Value            */
#define SDFM_SDIFLG_MF4_Get(x) (((uint32_t) (x) & SDFM_SDIFLG_MF4_Msk) >> SDFM_SDIFLG_MF4_Pos)             /*!< MF4 Get Value            */


#define SDFM_SDIFLG_MF3_Pos    (10U)                                                                                 /*!< MF3 Postion   10         */ 
#define SDFM_SDIFLG_MF3_Msk    (0x1U << SDFM_SDIFLG_MF3_Pos)                                                    /*!< MF3 Mask      0x00000400 */
#define SDFM_SDIFLG_MF3_Set(x) (((uint32_t) (x) << SDFM_SDIFLG_MF3_Pos) & SDFM_SDIFLG_MF3_Msk)             /*!< MF3 Set Value            */
#define SDFM_SDIFLG_MF3_Get(x) (((uint32_t) (x) & SDFM_SDIFLG_MF3_Msk) >> SDFM_SDIFLG_MF3_Pos)             /*!< MF3 Get Value            */


#define SDFM_SDIFLG_MF2_Pos    (9U)                                                                                  /*!< MF2 Postion   9          */ 
#define SDFM_SDIFLG_MF2_Msk    (0x1U << SDFM_SDIFLG_MF2_Pos)                                                    /*!< MF2 Mask      0x00000200 */
#define SDFM_SDIFLG_MF2_Set(x) (((uint32_t) (x) << SDFM_SDIFLG_MF2_Pos) & SDFM_SDIFLG_MF2_Msk)             /*!< MF2 Set Value            */
#define SDFM_SDIFLG_MF2_Get(x) (((uint32_t) (x) & SDFM_SDIFLG_MF2_Msk) >> SDFM_SDIFLG_MF2_Pos)             /*!< MF2 Get Value            */


#define SDFM_SDIFLG_MF1_Pos    (8U)                                                                                  /*!< MF1 Postion   8          */ 
#define SDFM_SDIFLG_MF1_Msk    (0x1U << SDFM_SDIFLG_MF1_Pos)                                                    /*!< MF1 Mask      0x00000100 */
#define SDFM_SDIFLG_MF1_Set(x) (((uint32_t) (x) << SDFM_SDIFLG_MF1_Pos) & SDFM_SDIFLG_MF1_Msk)             /*!< MF1 Set Value            */
#define SDFM_SDIFLG_MF1_Get(x) (((uint32_t) (x) & SDFM_SDIFLG_MF1_Msk) >> SDFM_SDIFLG_MF1_Pos)             /*!< MF1 Get Value            */


#define SDFM_SDIFLG_FLT4_FLG_CEVT2_Pos    (7U)                                                                                  /*!< FLT4_FLG_CEVT2 Postion   7          */ 
#define SDFM_SDIFLG_FLT4_FLG_CEVT2_Msk    (0x1U << SDFM_SDIFLG_FLT4_FLG_CEVT2_Pos)                                         /*!< FLT4_FLG_CEVT2 Mask      0x00000080 */
#define SDFM_SDIFLG_FLT4_FLG_CEVT2_Set(x) (((uint32_t) (x) << SDFM_SDIFLG_FLT4_FLG_CEVT2_Pos) & SDFM_SDIFLG_FLT4_FLG_CEVT2_Msk) /*!< FLT4_FLG_CEVT2 Set Value            */
#define SDFM_SDIFLG_FLT4_FLG_CEVT2_Get(x) (((uint32_t) (x) & SDFM_SDIFLG_FLT4_FLG_CEVT2_Msk) >> SDFM_SDIFLG_FLT4_FLG_CEVT2_Pos) /*!< FLT4_FLG_CEVT2 Get Value            */


#define SDFM_SDIFLG_FLT4_FLG_CEVT1_Pos    (6U)                                                                                  /*!< FLT4_FLG_CEVT1 Postion   6          */ 
#define SDFM_SDIFLG_FLT4_FLG_CEVT1_Msk    (0x1U << SDFM_SDIFLG_FLT4_FLG_CEVT1_Pos)                                         /*!< FLT4_FLG_CEVT1 Mask      0x00000040 */
#define SDFM_SDIFLG_FLT4_FLG_CEVT1_Set(x) (((uint32_t) (x) << SDFM_SDIFLG_FLT4_FLG_CEVT1_Pos) & SDFM_SDIFLG_FLT4_FLG_CEVT1_Msk) /*!< FLT4_FLG_CEVT1 Set Value            */
#define SDFM_SDIFLG_FLT4_FLG_CEVT1_Get(x) (((uint32_t) (x) & SDFM_SDIFLG_FLT4_FLG_CEVT1_Msk) >> SDFM_SDIFLG_FLT4_FLG_CEVT1_Pos) /*!< FLT4_FLG_CEVT1 Get Value            */


#define SDFM_SDIFLG_FLT3_FLG_CEVT2_Pos    (5U)                                                                                  /*!< FLT3_FLG_CEVT2 Postion   5          */ 
#define SDFM_SDIFLG_FLT3_FLG_CEVT2_Msk    (0x1U << SDFM_SDIFLG_FLT3_FLG_CEVT2_Pos)                                         /*!< FLT3_FLG_CEVT2 Mask      0x00000020 */
#define SDFM_SDIFLG_FLT3_FLG_CEVT2_Set(x) (((uint32_t) (x) << SDFM_SDIFLG_FLT3_FLG_CEVT2_Pos) & SDFM_SDIFLG_FLT3_FLG_CEVT2_Msk) /*!< FLT3_FLG_CEVT2 Set Value            */
#define SDFM_SDIFLG_FLT3_FLG_CEVT2_Get(x) (((uint32_t) (x) & SDFM_SDIFLG_FLT3_FLG_CEVT2_Msk) >> SDFM_SDIFLG_FLT3_FLG_CEVT2_Pos) /*!< FLT3_FLG_CEVT2 Get Value            */


#define SDFM_SDIFLG_FLT3_FLG_CEVT1_Pos    (4U)                                                                                  /*!< FLT3_FLG_CEVT1 Postion   4          */ 
#define SDFM_SDIFLG_FLT3_FLG_CEVT1_Msk    (0x1U << SDFM_SDIFLG_FLT3_FLG_CEVT1_Pos)                                         /*!< FLT3_FLG_CEVT1 Mask      0x00000010 */
#define SDFM_SDIFLG_FLT3_FLG_CEVT1_Set(x) (((uint32_t) (x) << SDFM_SDIFLG_FLT3_FLG_CEVT1_Pos) & SDFM_SDIFLG_FLT3_FLG_CEVT1_Msk) /*!< FLT3_FLG_CEVT1 Set Value            */
#define SDFM_SDIFLG_FLT3_FLG_CEVT1_Get(x) (((uint32_t) (x) & SDFM_SDIFLG_FLT3_FLG_CEVT1_Msk) >> SDFM_SDIFLG_FLT3_FLG_CEVT1_Pos) /*!< FLT3_FLG_CEVT1 Get Value            */


#define SDFM_SDIFLG_FLT2_FLG_CEVT2_Pos    (3U)                                                                                  /*!< FLT2_FLG_CEVT2 Postion   3          */ 
#define SDFM_SDIFLG_FLT2_FLG_CEVT2_Msk    (0x1U << SDFM_SDIFLG_FLT2_FLG_CEVT2_Pos)                                         /*!< FLT2_FLG_CEVT2 Mask      0x00000008 */
#define SDFM_SDIFLG_FLT2_FLG_CEVT2_Set(x) (((uint32_t) (x) << SDFM_SDIFLG_FLT2_FLG_CEVT2_Pos) & SDFM_SDIFLG_FLT2_FLG_CEVT2_Msk) /*!< FLT2_FLG_CEVT2 Set Value            */
#define SDFM_SDIFLG_FLT2_FLG_CEVT2_Get(x) (((uint32_t) (x) & SDFM_SDIFLG_FLT2_FLG_CEVT2_Msk) >> SDFM_SDIFLG_FLT2_FLG_CEVT2_Pos) /*!< FLT2_FLG_CEVT2 Get Value            */


#define SDFM_SDIFLG_FLT2_FLG_CEVT1_Pos    (2U)                                                                                  /*!< FLT2_FLG_CEVT1 Postion   2          */ 
#define SDFM_SDIFLG_FLT2_FLG_CEVT1_Msk    (0x1U << SDFM_SDIFLG_FLT2_FLG_CEVT1_Pos)                                         /*!< FLT2_FLG_CEVT1 Mask      0x00000004 */
#define SDFM_SDIFLG_FLT2_FLG_CEVT1_Set(x) (((uint32_t) (x) << SDFM_SDIFLG_FLT2_FLG_CEVT1_Pos) & SDFM_SDIFLG_FLT2_FLG_CEVT1_Msk) /*!< FLT2_FLG_CEVT1 Set Value            */
#define SDFM_SDIFLG_FLT2_FLG_CEVT1_Get(x) (((uint32_t) (x) & SDFM_SDIFLG_FLT2_FLG_CEVT1_Msk) >> SDFM_SDIFLG_FLT2_FLG_CEVT1_Pos) /*!< FLT2_FLG_CEVT1 Get Value            */


#define SDFM_SDIFLG_FLT1_FLG_CEVT2_Pos    (1U)                                                                                  /*!< FLT1_FLG_CEVT2 Postion   1          */ 
#define SDFM_SDIFLG_FLT1_FLG_CEVT2_Msk    (0x1U << SDFM_SDIFLG_FLT1_FLG_CEVT2_Pos)                                         /*!< FLT1_FLG_CEVT2 Mask      0x00000002 */
#define SDFM_SDIFLG_FLT1_FLG_CEVT2_Set(x) (((uint32_t) (x) << SDFM_SDIFLG_FLT1_FLG_CEVT2_Pos) & SDFM_SDIFLG_FLT1_FLG_CEVT2_Msk) /*!< FLT1_FLG_CEVT2 Set Value            */
#define SDFM_SDIFLG_FLT1_FLG_CEVT2_Get(x) (((uint32_t) (x) & SDFM_SDIFLG_FLT1_FLG_CEVT2_Msk) >> SDFM_SDIFLG_FLT1_FLG_CEVT2_Pos) /*!< FLT1_FLG_CEVT2 Get Value            */


#define SDFM_SDIFLG_FLT1_FLG_CEVT1_Pos    (0U)                                                                                  /*!< FLT1_FLG_CEVT1 Postion   0          */ 
#define SDFM_SDIFLG_FLT1_FLG_CEVT1_Msk    (0x1U << SDFM_SDIFLG_FLT1_FLG_CEVT1_Pos)                                         /*!< FLT1_FLG_CEVT1 Mask      0x00000001 */
#define SDFM_SDIFLG_FLT1_FLG_CEVT1_Set(x) (((uint32_t) (x) << SDFM_SDIFLG_FLT1_FLG_CEVT1_Pos) & SDFM_SDIFLG_FLT1_FLG_CEVT1_Msk) /*!< FLT1_FLG_CEVT1 Set Value            */
#define SDFM_SDIFLG_FLT1_FLG_CEVT1_Get(x) (((uint32_t) (x) & SDFM_SDIFLG_FLT1_FLG_CEVT1_Msk) >> SDFM_SDIFLG_FLT1_FLG_CEVT1_Pos) /*!< FLT1_FLG_CEVT1 Get Value            */


/* SDIFLGCLR bitfield */
#define SDFM_SDIFLGCLR_MIF_Pos    (31U)                                                                                 /*!< MIF Postion   31         */ 
#define SDFM_SDIFLGCLR_MIF_Msk    (0x1U << SDFM_SDIFLGCLR_MIF_Pos)                                                 /*!< MIF Mask      0x80000000 */
#define SDFM_SDIFLGCLR_MIF_Set(x) (((uint32_t) (x) << SDFM_SDIFLGCLR_MIF_Pos) & SDFM_SDIFLGCLR_MIF_Msk)       /*!< MIF Set Value            */
#define SDFM_SDIFLGCLR_MIF_Get(x) (((uint32_t) (x) & SDFM_SDIFLGCLR_MIF_Msk) >> SDFM_SDIFLGCLR_MIF_Pos)       /*!< MIF Get Value            */


#define SDFM_SDIFLGCLR_SDFFUDF4_Pos    (27U)                                                                                 /*!< SDFFUDF4 Postion   27         */ 
#define SDFM_SDIFLGCLR_SDFFUDF4_Msk    (0x1U << SDFM_SDIFLGCLR_SDFFUDF4_Pos)                                            /*!< SDFFUDF4 Mask      0x08000000 */
#define SDFM_SDIFLGCLR_SDFFUDF4_Set(x) (((uint32_t) (x) << SDFM_SDIFLGCLR_SDFFUDF4_Pos) & SDFM_SDIFLGCLR_SDFFUDF4_Msk) /*!< SDFFUDF4 Set Value            */
#define SDFM_SDIFLGCLR_SDFFUDF4_Get(x) (((uint32_t) (x) & SDFM_SDIFLGCLR_SDFFUDF4_Msk) >> SDFM_SDIFLGCLR_SDFFUDF4_Pos) /*!< SDFFUDF4 Get Value            */


#define SDFM_SDIFLGCLR_SDFFUDF3_Pos    (26U)                                                                                 /*!< SDFFUDF3 Postion   26         */ 
#define SDFM_SDIFLGCLR_SDFFUDF3_Msk    (0x1U << SDFM_SDIFLGCLR_SDFFUDF3_Pos)                                            /*!< SDFFUDF3 Mask      0x04000000 */
#define SDFM_SDIFLGCLR_SDFFUDF3_Set(x) (((uint32_t) (x) << SDFM_SDIFLGCLR_SDFFUDF3_Pos) & SDFM_SDIFLGCLR_SDFFUDF3_Msk) /*!< SDFFUDF3 Set Value            */
#define SDFM_SDIFLGCLR_SDFFUDF3_Get(x) (((uint32_t) (x) & SDFM_SDIFLGCLR_SDFFUDF3_Msk) >> SDFM_SDIFLGCLR_SDFFUDF3_Pos) /*!< SDFFUDF3 Get Value            */


#define SDFM_SDIFLGCLR_SDFFUDF2_Pos    (25U)                                                                                 /*!< SDFFUDF2 Postion   25         */ 
#define SDFM_SDIFLGCLR_SDFFUDF2_Msk    (0x1U << SDFM_SDIFLGCLR_SDFFUDF2_Pos)                                            /*!< SDFFUDF2 Mask      0x02000000 */
#define SDFM_SDIFLGCLR_SDFFUDF2_Set(x) (((uint32_t) (x) << SDFM_SDIFLGCLR_SDFFUDF2_Pos) & SDFM_SDIFLGCLR_SDFFUDF2_Msk) /*!< SDFFUDF2 Set Value            */
#define SDFM_SDIFLGCLR_SDFFUDF2_Get(x) (((uint32_t) (x) & SDFM_SDIFLGCLR_SDFFUDF2_Msk) >> SDFM_SDIFLGCLR_SDFFUDF2_Pos) /*!< SDFFUDF2 Get Value            */


#define SDFM_SDIFLGCLR_SDFFUDF1_Pos    (24U)                                                                                 /*!< SDFFUDF1 Postion   24         */ 
#define SDFM_SDIFLGCLR_SDFFUDF1_Msk    (0x1U << SDFM_SDIFLGCLR_SDFFUDF1_Pos)                                            /*!< SDFFUDF1 Mask      0x01000000 */
#define SDFM_SDIFLGCLR_SDFFUDF1_Set(x) (((uint32_t) (x) << SDFM_SDIFLGCLR_SDFFUDF1_Pos) & SDFM_SDIFLGCLR_SDFFUDF1_Msk) /*!< SDFFUDF1 Set Value            */
#define SDFM_SDIFLGCLR_SDFFUDF1_Get(x) (((uint32_t) (x) & SDFM_SDIFLGCLR_SDFFUDF1_Msk) >> SDFM_SDIFLGCLR_SDFFUDF1_Pos) /*!< SDFFUDF1 Get Value            */


#define SDFM_SDIFLGCLR_SDFFINT4_Pos    (23U)                                                                                 /*!< SDFFINT4 Postion   23         */ 
#define SDFM_SDIFLGCLR_SDFFINT4_Msk    (0x1U << SDFM_SDIFLGCLR_SDFFINT4_Pos)                                            /*!< SDFFINT4 Mask      0x00800000 */
#define SDFM_SDIFLGCLR_SDFFINT4_Set(x) (((uint32_t) (x) << SDFM_SDIFLGCLR_SDFFINT4_Pos) & SDFM_SDIFLGCLR_SDFFINT4_Msk) /*!< SDFFINT4 Set Value            */
#define SDFM_SDIFLGCLR_SDFFINT4_Get(x) (((uint32_t) (x) & SDFM_SDIFLGCLR_SDFFINT4_Msk) >> SDFM_SDIFLGCLR_SDFFINT4_Pos) /*!< SDFFINT4 Get Value            */


#define SDFM_SDIFLGCLR_SDFFINT3_Pos    (22U)                                                                                 /*!< SDFFINT3 Postion   22         */ 
#define SDFM_SDIFLGCLR_SDFFINT3_Msk    (0x1U << SDFM_SDIFLGCLR_SDFFINT3_Pos)                                            /*!< SDFFINT3 Mask      0x00400000 */
#define SDFM_SDIFLGCLR_SDFFINT3_Set(x) (((uint32_t) (x) << SDFM_SDIFLGCLR_SDFFINT3_Pos) & SDFM_SDIFLGCLR_SDFFINT3_Msk) /*!< SDFFINT3 Set Value            */
#define SDFM_SDIFLGCLR_SDFFINT3_Get(x) (((uint32_t) (x) & SDFM_SDIFLGCLR_SDFFINT3_Msk) >> SDFM_SDIFLGCLR_SDFFINT3_Pos) /*!< SDFFINT3 Get Value            */


#define SDFM_SDIFLGCLR_SDFFINT2_Pos    (21U)                                                                                 /*!< SDFFINT2 Postion   21         */ 
#define SDFM_SDIFLGCLR_SDFFINT2_Msk    (0x1U << SDFM_SDIFLGCLR_SDFFINT2_Pos)                                            /*!< SDFFINT2 Mask      0x00200000 */
#define SDFM_SDIFLGCLR_SDFFINT2_Set(x) (((uint32_t) (x) << SDFM_SDIFLGCLR_SDFFINT2_Pos) & SDFM_SDIFLGCLR_SDFFINT2_Msk) /*!< SDFFINT2 Set Value            */
#define SDFM_SDIFLGCLR_SDFFINT2_Get(x) (((uint32_t) (x) & SDFM_SDIFLGCLR_SDFFINT2_Msk) >> SDFM_SDIFLGCLR_SDFFINT2_Pos) /*!< SDFFINT2 Get Value            */


#define SDFM_SDIFLGCLR_SDFFINT1_Pos    (20U)                                                                                 /*!< SDFFINT1 Postion   20         */ 
#define SDFM_SDIFLGCLR_SDFFINT1_Msk    (0x1U << SDFM_SDIFLGCLR_SDFFINT1_Pos)                                            /*!< SDFFINT1 Mask      0x00100000 */
#define SDFM_SDIFLGCLR_SDFFINT1_Set(x) (((uint32_t) (x) << SDFM_SDIFLGCLR_SDFFINT1_Pos) & SDFM_SDIFLGCLR_SDFFINT1_Msk) /*!< SDFFINT1 Set Value            */
#define SDFM_SDIFLGCLR_SDFFINT1_Get(x) (((uint32_t) (x) & SDFM_SDIFLGCLR_SDFFINT1_Msk) >> SDFM_SDIFLGCLR_SDFFINT1_Pos) /*!< SDFFINT1 Get Value            */


#define SDFM_SDIFLGCLR_SDFFOVF4_Pos    (19U)                                                                                 /*!< SDFFOVF4 Postion   19         */ 
#define SDFM_SDIFLGCLR_SDFFOVF4_Msk    (0x1U << SDFM_SDIFLGCLR_SDFFOVF4_Pos)                                            /*!< SDFFOVF4 Mask      0x00080000 */
#define SDFM_SDIFLGCLR_SDFFOVF4_Set(x) (((uint32_t) (x) << SDFM_SDIFLGCLR_SDFFOVF4_Pos) & SDFM_SDIFLGCLR_SDFFOVF4_Msk) /*!< SDFFOVF4 Set Value            */
#define SDFM_SDIFLGCLR_SDFFOVF4_Get(x) (((uint32_t) (x) & SDFM_SDIFLGCLR_SDFFOVF4_Msk) >> SDFM_SDIFLGCLR_SDFFOVF4_Pos) /*!< SDFFOVF4 Get Value            */


#define SDFM_SDIFLGCLR_SDFFOVF3_Pos    (18U)                                                                                 /*!< SDFFOVF3 Postion   18         */ 
#define SDFM_SDIFLGCLR_SDFFOVF3_Msk    (0x1U << SDFM_SDIFLGCLR_SDFFOVF3_Pos)                                            /*!< SDFFOVF3 Mask      0x00040000 */
#define SDFM_SDIFLGCLR_SDFFOVF3_Set(x) (((uint32_t) (x) << SDFM_SDIFLGCLR_SDFFOVF3_Pos) & SDFM_SDIFLGCLR_SDFFOVF3_Msk) /*!< SDFFOVF3 Set Value            */
#define SDFM_SDIFLGCLR_SDFFOVF3_Get(x) (((uint32_t) (x) & SDFM_SDIFLGCLR_SDFFOVF3_Msk) >> SDFM_SDIFLGCLR_SDFFOVF3_Pos) /*!< SDFFOVF3 Get Value            */


#define SDFM_SDIFLGCLR_SDFFOVF2_Pos    (17U)                                                                                 /*!< SDFFOVF2 Postion   17         */ 
#define SDFM_SDIFLGCLR_SDFFOVF2_Msk    (0x1U << SDFM_SDIFLGCLR_SDFFOVF2_Pos)                                            /*!< SDFFOVF2 Mask      0x00020000 */
#define SDFM_SDIFLGCLR_SDFFOVF2_Set(x) (((uint32_t) (x) << SDFM_SDIFLGCLR_SDFFOVF2_Pos) & SDFM_SDIFLGCLR_SDFFOVF2_Msk) /*!< SDFFOVF2 Set Value            */
#define SDFM_SDIFLGCLR_SDFFOVF2_Get(x) (((uint32_t) (x) & SDFM_SDIFLGCLR_SDFFOVF2_Msk) >> SDFM_SDIFLGCLR_SDFFOVF2_Pos) /*!< SDFFOVF2 Get Value            */


#define SDFM_SDIFLGCLR_SDFFOVF1_Pos    (16U)                                                                                 /*!< SDFFOVF1 Postion   16         */ 
#define SDFM_SDIFLGCLR_SDFFOVF1_Msk    (0x1U << SDFM_SDIFLGCLR_SDFFOVF1_Pos)                                            /*!< SDFFOVF1 Mask      0x00010000 */
#define SDFM_SDIFLGCLR_SDFFOVF1_Set(x) (((uint32_t) (x) << SDFM_SDIFLGCLR_SDFFOVF1_Pos) & SDFM_SDIFLGCLR_SDFFOVF1_Msk) /*!< SDFFOVF1 Set Value            */
#define SDFM_SDIFLGCLR_SDFFOVF1_Get(x) (((uint32_t) (x) & SDFM_SDIFLGCLR_SDFFOVF1_Msk) >> SDFM_SDIFLGCLR_SDFFOVF1_Pos) /*!< SDFFOVF1 Get Value            */


#define SDFM_SDIFLGCLR_AF4_Pos    (15U)                                                                                 /*!< AF4 Postion   15         */ 
#define SDFM_SDIFLGCLR_AF4_Msk    (0x1U << SDFM_SDIFLGCLR_AF4_Pos)                                                 /*!< AF4 Mask      0x00008000 */
#define SDFM_SDIFLGCLR_AF4_Set(x) (((uint32_t) (x) << SDFM_SDIFLGCLR_AF4_Pos) & SDFM_SDIFLGCLR_AF4_Msk)       /*!< AF4 Set Value            */
#define SDFM_SDIFLGCLR_AF4_Get(x) (((uint32_t) (x) & SDFM_SDIFLGCLR_AF4_Msk) >> SDFM_SDIFLGCLR_AF4_Pos)       /*!< AF4 Get Value            */


#define SDFM_SDIFLGCLR_AF3_Pos    (14U)                                                                                 /*!< AF3 Postion   14         */ 
#define SDFM_SDIFLGCLR_AF3_Msk    (0x1U << SDFM_SDIFLGCLR_AF3_Pos)                                                 /*!< AF3 Mask      0x00004000 */
#define SDFM_SDIFLGCLR_AF3_Set(x) (((uint32_t) (x) << SDFM_SDIFLGCLR_AF3_Pos) & SDFM_SDIFLGCLR_AF3_Msk)       /*!< AF3 Set Value            */
#define SDFM_SDIFLGCLR_AF3_Get(x) (((uint32_t) (x) & SDFM_SDIFLGCLR_AF3_Msk) >> SDFM_SDIFLGCLR_AF3_Pos)       /*!< AF3 Get Value            */


#define SDFM_SDIFLGCLR_AF2_Pos    (13U)                                                                                 /*!< AF2 Postion   13         */ 
#define SDFM_SDIFLGCLR_AF2_Msk    (0x1U << SDFM_SDIFLGCLR_AF2_Pos)                                                 /*!< AF2 Mask      0x00002000 */
#define SDFM_SDIFLGCLR_AF2_Set(x) (((uint32_t) (x) << SDFM_SDIFLGCLR_AF2_Pos) & SDFM_SDIFLGCLR_AF2_Msk)       /*!< AF2 Set Value            */
#define SDFM_SDIFLGCLR_AF2_Get(x) (((uint32_t) (x) & SDFM_SDIFLGCLR_AF2_Msk) >> SDFM_SDIFLGCLR_AF2_Pos)       /*!< AF2 Get Value            */


#define SDFM_SDIFLGCLR_AF1_Pos    (12U)                                                                                 /*!< AF1 Postion   12         */ 
#define SDFM_SDIFLGCLR_AF1_Msk    (0x1U << SDFM_SDIFLGCLR_AF1_Pos)                                                 /*!< AF1 Mask      0x00001000 */
#define SDFM_SDIFLGCLR_AF1_Set(x) (((uint32_t) (x) << SDFM_SDIFLGCLR_AF1_Pos) & SDFM_SDIFLGCLR_AF1_Msk)       /*!< AF1 Set Value            */
#define SDFM_SDIFLGCLR_AF1_Get(x) (((uint32_t) (x) & SDFM_SDIFLGCLR_AF1_Msk) >> SDFM_SDIFLGCLR_AF1_Pos)       /*!< AF1 Get Value            */


#define SDFM_SDIFLGCLR_MF4_Pos    (11U)                                                                                 /*!< MF4 Postion   11         */ 
#define SDFM_SDIFLGCLR_MF4_Msk    (0x1U << SDFM_SDIFLGCLR_MF4_Pos)                                                 /*!< MF4 Mask      0x00000800 */
#define SDFM_SDIFLGCLR_MF4_Set(x) (((uint32_t) (x) << SDFM_SDIFLGCLR_MF4_Pos) & SDFM_SDIFLGCLR_MF4_Msk)       /*!< MF4 Set Value            */
#define SDFM_SDIFLGCLR_MF4_Get(x) (((uint32_t) (x) & SDFM_SDIFLGCLR_MF4_Msk) >> SDFM_SDIFLGCLR_MF4_Pos)       /*!< MF4 Get Value            */


#define SDFM_SDIFLGCLR_MF3_Pos    (10U)                                                                                 /*!< MF3 Postion   10         */ 
#define SDFM_SDIFLGCLR_MF3_Msk    (0x1U << SDFM_SDIFLGCLR_MF3_Pos)                                                 /*!< MF3 Mask      0x00000400 */
#define SDFM_SDIFLGCLR_MF3_Set(x) (((uint32_t) (x) << SDFM_SDIFLGCLR_MF3_Pos) & SDFM_SDIFLGCLR_MF3_Msk)       /*!< MF3 Set Value            */
#define SDFM_SDIFLGCLR_MF3_Get(x) (((uint32_t) (x) & SDFM_SDIFLGCLR_MF3_Msk) >> SDFM_SDIFLGCLR_MF3_Pos)       /*!< MF3 Get Value            */


#define SDFM_SDIFLGCLR_MF2_Pos    (9U)                                                                                  /*!< MF2 Postion   9          */ 
#define SDFM_SDIFLGCLR_MF2_Msk    (0x1U << SDFM_SDIFLGCLR_MF2_Pos)                                                 /*!< MF2 Mask      0x00000200 */
#define SDFM_SDIFLGCLR_MF2_Set(x) (((uint32_t) (x) << SDFM_SDIFLGCLR_MF2_Pos) & SDFM_SDIFLGCLR_MF2_Msk)       /*!< MF2 Set Value            */
#define SDFM_SDIFLGCLR_MF2_Get(x) (((uint32_t) (x) & SDFM_SDIFLGCLR_MF2_Msk) >> SDFM_SDIFLGCLR_MF2_Pos)       /*!< MF2 Get Value            */


#define SDFM_SDIFLGCLR_MF1_Pos    (8U)                                                                                  /*!< MF1 Postion   8          */ 
#define SDFM_SDIFLGCLR_MF1_Msk    (0x1U << SDFM_SDIFLGCLR_MF1_Pos)                                                 /*!< MF1 Mask      0x00000100 */
#define SDFM_SDIFLGCLR_MF1_Set(x) (((uint32_t) (x) << SDFM_SDIFLGCLR_MF1_Pos) & SDFM_SDIFLGCLR_MF1_Msk)       /*!< MF1 Set Value            */
#define SDFM_SDIFLGCLR_MF1_Get(x) (((uint32_t) (x) & SDFM_SDIFLGCLR_MF1_Msk) >> SDFM_SDIFLGCLR_MF1_Pos)       /*!< MF1 Get Value            */


#define SDFM_SDIFLGCLR_FLT4_FLG_CEVT2_Pos    (7U)                                                                                  /*!< FLT4_FLG_CEVT2 Postion   7          */ 
#define SDFM_SDIFLGCLR_FLT4_FLG_CEVT2_Msk    (0x1U << SDFM_SDIFLGCLR_FLT4_FLG_CEVT2_Pos)                                      /*!< FLT4_FLG_CEVT2 Mask      0x00000080 */
#define SDFM_SDIFLGCLR_FLT4_FLG_CEVT2_Set(x) (((uint32_t) (x) << SDFM_SDIFLGCLR_FLT4_FLG_CEVT2_Pos) & SDFM_SDIFLGCLR_FLT4_FLG_CEVT2_Msk) /*!< FLT4_FLG_CEVT2 Set Value            */
#define SDFM_SDIFLGCLR_FLT4_FLG_CEVT2_Get(x) (((uint32_t) (x) & SDFM_SDIFLGCLR_FLT4_FLG_CEVT2_Msk) >> SDFM_SDIFLGCLR_FLT4_FLG_CEVT2_Pos) /*!< FLT4_FLG_CEVT2 Get Value            */


#define SDFM_SDIFLGCLR_FLT4_FLG_CEVT1_Pos    (6U)                                                                                  /*!< FLT4_FLG_CEVT1 Postion   6          */ 
#define SDFM_SDIFLGCLR_FLT4_FLG_CEVT1_Msk    (0x1U << SDFM_SDIFLGCLR_FLT4_FLG_CEVT1_Pos)                                      /*!< FLT4_FLG_CEVT1 Mask      0x00000040 */
#define SDFM_SDIFLGCLR_FLT4_FLG_CEVT1_Set(x) (((uint32_t) (x) << SDFM_SDIFLGCLR_FLT4_FLG_CEVT1_Pos) & SDFM_SDIFLGCLR_FLT4_FLG_CEVT1_Msk) /*!< FLT4_FLG_CEVT1 Set Value            */
#define SDFM_SDIFLGCLR_FLT4_FLG_CEVT1_Get(x) (((uint32_t) (x) & SDFM_SDIFLGCLR_FLT4_FLG_CEVT1_Msk) >> SDFM_SDIFLGCLR_FLT4_FLG_CEVT1_Pos) /*!< FLT4_FLG_CEVT1 Get Value            */


#define SDFM_SDIFLGCLR_FLT3_FLG_CEVT2_Pos    (5U)                                                                                  /*!< FLT3_FLG_CEVT2 Postion   5          */ 
#define SDFM_SDIFLGCLR_FLT3_FLG_CEVT2_Msk    (0x1U << SDFM_SDIFLGCLR_FLT3_FLG_CEVT2_Pos)                                      /*!< FLT3_FLG_CEVT2 Mask      0x00000020 */
#define SDFM_SDIFLGCLR_FLT3_FLG_CEVT2_Set(x) (((uint32_t) (x) << SDFM_SDIFLGCLR_FLT3_FLG_CEVT2_Pos) & SDFM_SDIFLGCLR_FLT3_FLG_CEVT2_Msk) /*!< FLT3_FLG_CEVT2 Set Value            */
#define SDFM_SDIFLGCLR_FLT3_FLG_CEVT2_Get(x) (((uint32_t) (x) & SDFM_SDIFLGCLR_FLT3_FLG_CEVT2_Msk) >> SDFM_SDIFLGCLR_FLT3_FLG_CEVT2_Pos) /*!< FLT3_FLG_CEVT2 Get Value            */


#define SDFM_SDIFLGCLR_FLT3_FLG_CEVT1_Pos    (4U)                                                                                  /*!< FLT3_FLG_CEVT1 Postion   4          */ 
#define SDFM_SDIFLGCLR_FLT3_FLG_CEVT1_Msk    (0x1U << SDFM_SDIFLGCLR_FLT3_FLG_CEVT1_Pos)                                      /*!< FLT3_FLG_CEVT1 Mask      0x00000010 */
#define SDFM_SDIFLGCLR_FLT3_FLG_CEVT1_Set(x) (((uint32_t) (x) << SDFM_SDIFLGCLR_FLT3_FLG_CEVT1_Pos) & SDFM_SDIFLGCLR_FLT3_FLG_CEVT1_Msk) /*!< FLT3_FLG_CEVT1 Set Value            */
#define SDFM_SDIFLGCLR_FLT3_FLG_CEVT1_Get(x) (((uint32_t) (x) & SDFM_SDIFLGCLR_FLT3_FLG_CEVT1_Msk) >> SDFM_SDIFLGCLR_FLT3_FLG_CEVT1_Pos) /*!< FLT3_FLG_CEVT1 Get Value            */


#define SDFM_SDIFLGCLR_FLT2_FLG_CEVT2_Pos    (3U)                                                                                  /*!< FLT2_FLG_CEVT2 Postion   3          */ 
#define SDFM_SDIFLGCLR_FLT2_FLG_CEVT2_Msk    (0x1U << SDFM_SDIFLGCLR_FLT2_FLG_CEVT2_Pos)                                      /*!< FLT2_FLG_CEVT2 Mask      0x00000008 */
#define SDFM_SDIFLGCLR_FLT2_FLG_CEVT2_Set(x) (((uint32_t) (x) << SDFM_SDIFLGCLR_FLT2_FLG_CEVT2_Pos) & SDFM_SDIFLGCLR_FLT2_FLG_CEVT2_Msk) /*!< FLT2_FLG_CEVT2 Set Value            */
#define SDFM_SDIFLGCLR_FLT2_FLG_CEVT2_Get(x) (((uint32_t) (x) & SDFM_SDIFLGCLR_FLT2_FLG_CEVT2_Msk) >> SDFM_SDIFLGCLR_FLT2_FLG_CEVT2_Pos) /*!< FLT2_FLG_CEVT2 Get Value            */


#define SDFM_SDIFLGCLR_FLT2_FLG_CEVT1_Pos    (2U)                                                                                  /*!< FLT2_FLG_CEVT1 Postion   2          */ 
#define SDFM_SDIFLGCLR_FLT2_FLG_CEVT1_Msk    (0x1U << SDFM_SDIFLGCLR_FLT2_FLG_CEVT1_Pos)                                      /*!< FLT2_FLG_CEVT1 Mask      0x00000004 */
#define SDFM_SDIFLGCLR_FLT2_FLG_CEVT1_Set(x) (((uint32_t) (x) << SDFM_SDIFLGCLR_FLT2_FLG_CEVT1_Pos) & SDFM_SDIFLGCLR_FLT2_FLG_CEVT1_Msk) /*!< FLT2_FLG_CEVT1 Set Value            */
#define SDFM_SDIFLGCLR_FLT2_FLG_CEVT1_Get(x) (((uint32_t) (x) & SDFM_SDIFLGCLR_FLT2_FLG_CEVT1_Msk) >> SDFM_SDIFLGCLR_FLT2_FLG_CEVT1_Pos) /*!< FLT2_FLG_CEVT1 Get Value            */


#define SDFM_SDIFLGCLR_FLT1_FLG_CEVT2_Pos    (1U)                                                                                  /*!< FLT1_FLG_CEVT2 Postion   1          */ 
#define SDFM_SDIFLGCLR_FLT1_FLG_CEVT2_Msk    (0x1U << SDFM_SDIFLGCLR_FLT1_FLG_CEVT2_Pos)                                      /*!< FLT1_FLG_CEVT2 Mask      0x00000002 */
#define SDFM_SDIFLGCLR_FLT1_FLG_CEVT2_Set(x) (((uint32_t) (x) << SDFM_SDIFLGCLR_FLT1_FLG_CEVT2_Pos) & SDFM_SDIFLGCLR_FLT1_FLG_CEVT2_Msk) /*!< FLT1_FLG_CEVT2 Set Value            */
#define SDFM_SDIFLGCLR_FLT1_FLG_CEVT2_Get(x) (((uint32_t) (x) & SDFM_SDIFLGCLR_FLT1_FLG_CEVT2_Msk) >> SDFM_SDIFLGCLR_FLT1_FLG_CEVT2_Pos) /*!< FLT1_FLG_CEVT2 Get Value            */


#define SDFM_SDIFLGCLR_FLT1_FLG_CEVT1_Pos    (0U)                                                                                  /*!< FLT1_FLG_CEVT1 Postion   0          */ 
#define SDFM_SDIFLGCLR_FLT1_FLG_CEVT1_Msk    (0x1U << SDFM_SDIFLGCLR_FLT1_FLG_CEVT1_Pos)                                      /*!< FLT1_FLG_CEVT1 Mask      0x00000001 */
#define SDFM_SDIFLGCLR_FLT1_FLG_CEVT1_Set(x) (((uint32_t) (x) << SDFM_SDIFLGCLR_FLT1_FLG_CEVT1_Pos) & SDFM_SDIFLGCLR_FLT1_FLG_CEVT1_Msk) /*!< FLT1_FLG_CEVT1 Set Value            */
#define SDFM_SDIFLGCLR_FLT1_FLG_CEVT1_Get(x) (((uint32_t) (x) & SDFM_SDIFLGCLR_FLT1_FLG_CEVT1_Msk) >> SDFM_SDIFLGCLR_FLT1_FLG_CEVT1_Pos) /*!< FLT1_FLG_CEVT1 Get Value            */


/* SDCTL bitfield */
#define SDFM_SDCTL_MIE_Pos    (13U)                                                                                 /*!< MIE Postion   13         */ 
#define SDFM_SDCTL_MIE_Msk    (0x1U << SDFM_SDCTL_MIE_Pos)                                                     /*!< MIE Mask      0x00002000 */
#define SDFM_SDCTL_MIE_Set(x) (((uint32_t) (x) << SDFM_SDCTL_MIE_Pos) & SDFM_SDCTL_MIE_Msk)               /*!< MIE Set Value            */
#define SDFM_SDCTL_MIE_Get(x) (((uint32_t) (x) & SDFM_SDCTL_MIE_Msk) >> SDFM_SDCTL_MIE_Pos)               /*!< MIE Get Value            */


#define SDFM_SDCTL_HZ4_Pos    (3U)                                                                                  /*!< HZ4 Postion   3          */ 
#define SDFM_SDCTL_HZ4_Msk    (0x1U << SDFM_SDCTL_HZ4_Pos)                                                     /*!< HZ4 Mask      0x00000008 */
#define SDFM_SDCTL_HZ4_Set(x) (((uint32_t) (x) << SDFM_SDCTL_HZ4_Pos) & SDFM_SDCTL_HZ4_Msk)               /*!< HZ4 Set Value            */
#define SDFM_SDCTL_HZ4_Get(x) (((uint32_t) (x) & SDFM_SDCTL_HZ4_Msk) >> SDFM_SDCTL_HZ4_Pos)               /*!< HZ4 Get Value            */


#define SDFM_SDCTL_HZ3_Pos    (2U)                                                                                  /*!< HZ3 Postion   2          */ 
#define SDFM_SDCTL_HZ3_Msk    (0x1U << SDFM_SDCTL_HZ3_Pos)                                                     /*!< HZ3 Mask      0x00000004 */
#define SDFM_SDCTL_HZ3_Set(x) (((uint32_t) (x) << SDFM_SDCTL_HZ3_Pos) & SDFM_SDCTL_HZ3_Msk)               /*!< HZ3 Set Value            */
#define SDFM_SDCTL_HZ3_Get(x) (((uint32_t) (x) & SDFM_SDCTL_HZ3_Msk) >> SDFM_SDCTL_HZ3_Pos)               /*!< HZ3 Get Value            */


#define SDFM_SDCTL_HZ2_Pos    (1U)                                                                                  /*!< HZ2 Postion   1          */ 
#define SDFM_SDCTL_HZ2_Msk    (0x1U << SDFM_SDCTL_HZ2_Pos)                                                     /*!< HZ2 Mask      0x00000002 */
#define SDFM_SDCTL_HZ2_Set(x) (((uint32_t) (x) << SDFM_SDCTL_HZ2_Pos) & SDFM_SDCTL_HZ2_Msk)               /*!< HZ2 Set Value            */
#define SDFM_SDCTL_HZ2_Get(x) (((uint32_t) (x) & SDFM_SDCTL_HZ2_Msk) >> SDFM_SDCTL_HZ2_Pos)               /*!< HZ2 Get Value            */


#define SDFM_SDCTL_HZ1_Pos    (0U)                                                                                  /*!< HZ1 Postion   0          */ 
#define SDFM_SDCTL_HZ1_Msk    (0x1U << SDFM_SDCTL_HZ1_Pos)                                                     /*!< HZ1 Mask      0x00000001 */
#define SDFM_SDCTL_HZ1_Set(x) (((uint32_t) (x) << SDFM_SDCTL_HZ1_Pos) & SDFM_SDCTL_HZ1_Msk)               /*!< HZ1 Set Value            */
#define SDFM_SDCTL_HZ1_Get(x) (((uint32_t) (x) & SDFM_SDCTL_HZ1_Msk) >> SDFM_SDCTL_HZ1_Pos)               /*!< HZ1 Get Value            */


/* SDMFILEN bitfield */
#define SDFM_SDMFILEN_MFE_Pos    (11U)                                                                                 /*!< MFE Postion   11         */ 
#define SDFM_SDMFILEN_MFE_Msk    (0x1U << SDFM_SDMFILEN_MFE_Pos)                                                  /*!< MFE Mask      0x00000800 */
#define SDFM_SDMFILEN_MFE_Set(x) (((uint16_t) (x) << SDFM_SDMFILEN_MFE_Pos) & SDFM_SDMFILEN_MFE_Msk)         /*!< MFE Set Value            */
#define SDFM_SDMFILEN_MFE_Get(x) (((uint16_t) (x) & SDFM_SDMFILEN_MFE_Msk) >> SDFM_SDMFILEN_MFE_Pos)         /*!< MFE Get Value            */


/* SDSTATUS bitfield */
#define SDFM_SDSTATUS_HZ4_Pos    (3U)                                                                                  /*!< HZ4 Postion   3          */ 
#define SDFM_SDSTATUS_HZ4_Msk    (0x1U << SDFM_SDSTATUS_HZ4_Pos)                                                  /*!< HZ4 Mask      0x00000008 */
#define SDFM_SDSTATUS_HZ4_Set(x) (((uint16_t) (x) << SDFM_SDSTATUS_HZ4_Pos) & SDFM_SDSTATUS_HZ4_Msk)         /*!< HZ4 Set Value            */
#define SDFM_SDSTATUS_HZ4_Get(x) (((uint16_t) (x) & SDFM_SDSTATUS_HZ4_Msk) >> SDFM_SDSTATUS_HZ4_Pos)         /*!< HZ4 Get Value            */


#define SDFM_SDSTATUS_HZ3_Pos    (2U)                                                                                  /*!< HZ3 Postion   2          */ 
#define SDFM_SDSTATUS_HZ3_Msk    (0x1U << SDFM_SDSTATUS_HZ3_Pos)                                                  /*!< HZ3 Mask      0x00000004 */
#define SDFM_SDSTATUS_HZ3_Set(x) (((uint16_t) (x) << SDFM_SDSTATUS_HZ3_Pos) & SDFM_SDSTATUS_HZ3_Msk)         /*!< HZ3 Set Value            */
#define SDFM_SDSTATUS_HZ3_Get(x) (((uint16_t) (x) & SDFM_SDSTATUS_HZ3_Msk) >> SDFM_SDSTATUS_HZ3_Pos)         /*!< HZ3 Get Value            */


#define SDFM_SDSTATUS_HZ2_Pos    (1U)                                                                                  /*!< HZ2 Postion   1          */ 
#define SDFM_SDSTATUS_HZ2_Msk    (0x1U << SDFM_SDSTATUS_HZ2_Pos)                                                  /*!< HZ2 Mask      0x00000002 */
#define SDFM_SDSTATUS_HZ2_Set(x) (((uint16_t) (x) << SDFM_SDSTATUS_HZ2_Pos) & SDFM_SDSTATUS_HZ2_Msk)         /*!< HZ2 Set Value            */
#define SDFM_SDSTATUS_HZ2_Get(x) (((uint16_t) (x) & SDFM_SDSTATUS_HZ2_Msk) >> SDFM_SDSTATUS_HZ2_Pos)         /*!< HZ2 Get Value            */


#define SDFM_SDSTATUS_HZ1_Pos    (0U)                                                                                  /*!< HZ1 Postion   0          */ 
#define SDFM_SDSTATUS_HZ1_Msk    (0x1U << SDFM_SDSTATUS_HZ1_Pos)                                                  /*!< HZ1 Mask      0x00000001 */
#define SDFM_SDSTATUS_HZ1_Set(x) (((uint16_t) (x) << SDFM_SDSTATUS_HZ1_Pos) & SDFM_SDSTATUS_HZ1_Msk)         /*!< HZ1 Set Value            */
#define SDFM_SDSTATUS_HZ1_Get(x) (((uint16_t) (x) & SDFM_SDSTATUS_HZ1_Msk) >> SDFM_SDSTATUS_HZ1_Pos)         /*!< HZ1 Get Value            */


/* SDCTLPARM1 bitfield */
#define SDFM_SDCTLPARM1_MOD_Pos    (0U)                                                                                  /*!< MOD Postion   0          */ 
#define SDFM_SDCTLPARM1_MOD_Msk    (0x3U << SDFM_SDCTLPARM1_MOD_Pos)                                                /*!< MOD Mask      0x00000003 */
#define SDFM_SDCTLPARM1_MOD_Set(x) (((uint16_t) (x) << SDFM_SDCTLPARM1_MOD_Pos) & SDFM_SDCTLPARM1_MOD_Msk)     /*!< MOD Set Value            */
#define SDFM_SDCTLPARM1_MOD_Get(x) (((uint16_t) (x) & SDFM_SDCTLPARM1_MOD_Msk) >> SDFM_SDCTLPARM1_MOD_Pos)     /*!< MOD Get Value            */


/* SDDFPARM1 bitfield */
#define SDFM_SDDFPARM1_SDSYNCEN_Pos    (12U)                                                                                 /*!< SDSYNCEN Postion   12         */ 
#define SDFM_SDDFPARM1_SDSYNCEN_Msk    (0x1U << SDFM_SDDFPARM1_SDSYNCEN_Pos)                                            /*!< SDSYNCEN Mask      0x00001000 */
#define SDFM_SDDFPARM1_SDSYNCEN_Set(x) (((uint16_t) (x) << SDFM_SDDFPARM1_SDSYNCEN_Pos) & SDFM_SDDFPARM1_SDSYNCEN_Msk) /*!< SDSYNCEN Set Value            */
#define SDFM_SDDFPARM1_SDSYNCEN_Get(x) (((uint16_t) (x) & SDFM_SDDFPARM1_SDSYNCEN_Msk) >> SDFM_SDDFPARM1_SDSYNCEN_Pos) /*!< SDSYNCEN Get Value            */


#define SDFM_SDDFPARM1_SST_Pos    (10U)                                                                                 /*!< SST Postion   10         */ 
#define SDFM_SDDFPARM1_SST_Msk    (0x3U << SDFM_SDDFPARM1_SST_Pos)                                                 /*!< SST Mask      0x00000C00 */
#define SDFM_SDDFPARM1_SST_Set(x) (((uint16_t) (x) << SDFM_SDDFPARM1_SST_Pos) & SDFM_SDDFPARM1_SST_Msk)       /*!< SST Set Value            */
#define SDFM_SDDFPARM1_SST_Get(x) (((uint16_t) (x) & SDFM_SDDFPARM1_SST_Msk) >> SDFM_SDDFPARM1_SST_Pos)       /*!< SST Get Value            */


#define SDFM_SDDFPARM1_AE_Pos    (9U)                                                                                  /*!< AE Postion   9          */ 
#define SDFM_SDDFPARM1_AE_Msk    (0x1U << SDFM_SDDFPARM1_AE_Pos)                                                  /*!< AE Mask      0x00000200 */
#define SDFM_SDDFPARM1_AE_Set(x) (((uint16_t) (x) << SDFM_SDDFPARM1_AE_Pos) & SDFM_SDDFPARM1_AE_Msk)         /*!< AE Set Value            */
#define SDFM_SDDFPARM1_AE_Get(x) (((uint16_t) (x) & SDFM_SDDFPARM1_AE_Msk) >> SDFM_SDDFPARM1_AE_Pos)         /*!< AE Get Value            */


#define SDFM_SDDFPARM1_FEN_Pos    (8U)                                                                                  /*!< FEN Postion   8          */ 
#define SDFM_SDDFPARM1_FEN_Msk    (0x1U << SDFM_SDDFPARM1_FEN_Pos)                                                 /*!< FEN Mask      0x00000100 */
#define SDFM_SDDFPARM1_FEN_Set(x) (((uint16_t) (x) << SDFM_SDDFPARM1_FEN_Pos) & SDFM_SDDFPARM1_FEN_Msk)       /*!< FEN Set Value            */
#define SDFM_SDDFPARM1_FEN_Get(x) (((uint16_t) (x) & SDFM_SDDFPARM1_FEN_Msk) >> SDFM_SDDFPARM1_FEN_Pos)       /*!< FEN Get Value            */


#define SDFM_SDDFPARM1_DOSR_Pos    (0U)                                                                                  /*!< DOSR Postion   0          */ 
#define SDFM_SDDFPARM1_DOSR_Msk    (0xffU << SDFM_SDDFPARM1_DOSR_Pos)                                               /*!< DOSR Mask      0x000000FF */
#define SDFM_SDDFPARM1_DOSR_Set(x) (((uint16_t) (x) << SDFM_SDDFPARM1_DOSR_Pos) & SDFM_SDDFPARM1_DOSR_Msk)     /*!< DOSR Set Value            */
#define SDFM_SDDFPARM1_DOSR_Get(x) (((uint16_t) (x) & SDFM_SDDFPARM1_DOSR_Msk) >> SDFM_SDDFPARM1_DOSR_Pos)     /*!< DOSR Get Value            */


/* SDDPARM1 bitfield */
#define SDFM_SDDPARM1_SH_Pos    (11U)                                                                                 /*!< SH Postion   11         */ 
#define SDFM_SDDPARM1_SH_Msk    (0x1fU << SDFM_SDDPARM1_SH_Pos)                                                  /*!< SH Mask      0x0000F800 */
#define SDFM_SDDPARM1_SH_Set(x) (((uint16_t) (x) << SDFM_SDDPARM1_SH_Pos) & SDFM_SDDPARM1_SH_Msk)           /*!< SH Set Value            */
#define SDFM_SDDPARM1_SH_Get(x) (((uint16_t) (x) & SDFM_SDDPARM1_SH_Msk) >> SDFM_SDDPARM1_SH_Pos)           /*!< SH Get Value            */


#define SDFM_SDDPARM1_DR_Pos    (10U)                                                                                 /*!< DR Postion   10         */ 
#define SDFM_SDDPARM1_DR_Msk    (0x1U << SDFM_SDDPARM1_DR_Pos)                                                   /*!< DR Mask      0x00000400 */
#define SDFM_SDDPARM1_DR_Set(x) (((uint16_t) (x) << SDFM_SDDPARM1_DR_Pos) & SDFM_SDDPARM1_DR_Msk)           /*!< DR Set Value            */
#define SDFM_SDDPARM1_DR_Get(x) (((uint16_t) (x) & SDFM_SDDPARM1_DR_Msk) >> SDFM_SDDPARM1_DR_Pos)           /*!< DR Get Value            */


/* SDFLT1CMPH1 bitfield */
#define SDFM_SDFLT1CMPH1_HLT_Pos    (0U)                                                                                  /*!< HLT Postion   0          */ 
#define SDFM_SDFLT1CMPH1_HLT_Msk    (0x7fffU << SDFM_SDFLT1CMPH1_HLT_Pos)                                            /*!< HLT Mask      0x00007FFF */
#define SDFM_SDFLT1CMPH1_HLT_Set(x) (((uint16_t) (x) << SDFM_SDFLT1CMPH1_HLT_Pos) & SDFM_SDFLT1CMPH1_HLT_Msk)   /*!< HLT Set Value            */
#define SDFM_SDFLT1CMPH1_HLT_Get(x) (((uint16_t) (x) & SDFM_SDFLT1CMPH1_HLT_Msk) >> SDFM_SDFLT1CMPH1_HLT_Pos)   /*!< HLT Get Value            */


/* SDFLT1CMPL1 bitfield */
#define SDFM_SDFLT1CMPL1_LLT_Pos    (0U)                                                                                  /*!< LLT Postion   0          */ 
#define SDFM_SDFLT1CMPL1_LLT_Msk    (0x7fffU << SDFM_SDFLT1CMPL1_LLT_Pos)                                            /*!< LLT Mask      0x00007FFF */
#define SDFM_SDFLT1CMPL1_LLT_Set(x) (((uint16_t) (x) << SDFM_SDFLT1CMPL1_LLT_Pos) & SDFM_SDFLT1CMPL1_LLT_Msk)   /*!< LLT Set Value            */
#define SDFM_SDFLT1CMPL1_LLT_Get(x) (((uint16_t) (x) & SDFM_SDFLT1CMPL1_LLT_Msk) >> SDFM_SDFLT1CMPL1_LLT_Pos)   /*!< LLT Get Value            */


/* SDCPARM1 bitfield */
#define SDFM_SDCPARM1_CEVT2SEL_Pos    (14U)                                                                                 /*!< CEVT2SEL Postion   14         */ 
#define SDFM_SDCPARM1_CEVT2SEL_Msk    (0x3U << SDFM_SDCPARM1_CEVT2SEL_Pos)                                             /*!< CEVT2SEL Mask      0x0000C000 */
#define SDFM_SDCPARM1_CEVT2SEL_Set(x) (((uint16_t) (x) << SDFM_SDCPARM1_CEVT2SEL_Pos) & SDFM_SDCPARM1_CEVT2SEL_Msk) /*!< CEVT2SEL Set Value            */
#define SDFM_SDCPARM1_CEVT2SEL_Get(x) (((uint16_t) (x) & SDFM_SDCPARM1_CEVT2SEL_Msk) >> SDFM_SDCPARM1_CEVT2SEL_Pos) /*!< CEVT2SEL Get Value            */


#define SDFM_SDCPARM1_CEN_Pos    (13U)                                                                                 /*!< CEN Postion   13         */ 
#define SDFM_SDCPARM1_CEN_Msk    (0x1U << SDFM_SDCPARM1_CEN_Pos)                                                  /*!< CEN Mask      0x00002000 */
#define SDFM_SDCPARM1_CEN_Set(x) (((uint16_t) (x) << SDFM_SDCPARM1_CEN_Pos) & SDFM_SDCPARM1_CEN_Msk)         /*!< CEN Set Value            */
#define SDFM_SDCPARM1_CEN_Get(x) (((uint16_t) (x) & SDFM_SDCPARM1_CEN_Msk) >> SDFM_SDCPARM1_CEN_Pos)         /*!< CEN Get Value            */


#define SDFM_SDCPARM1_CEVT1SEL_Pos    (11U)                                                                                 /*!< CEVT1SEL Postion   11         */ 
#define SDFM_SDCPARM1_CEVT1SEL_Msk    (0x3U << SDFM_SDCPARM1_CEVT1SEL_Pos)                                             /*!< CEVT1SEL Mask      0x00001800 */
#define SDFM_SDCPARM1_CEVT1SEL_Set(x) (((uint16_t) (x) << SDFM_SDCPARM1_CEVT1SEL_Pos) & SDFM_SDCPARM1_CEVT1SEL_Msk) /*!< CEVT1SEL Set Value            */
#define SDFM_SDCPARM1_CEVT1SEL_Get(x) (((uint16_t) (x) & SDFM_SDCPARM1_CEVT1SEL_Msk) >> SDFM_SDCPARM1_CEVT1SEL_Pos) /*!< CEVT1SEL Get Value            */


#define SDFM_SDCPARM1_HZEN_Pos    (10U)                                                                                 /*!< HZEN Postion   10         */ 
#define SDFM_SDCPARM1_HZEN_Msk    (0x1U << SDFM_SDCPARM1_HZEN_Pos)                                                 /*!< HZEN Mask      0x00000400 */
#define SDFM_SDCPARM1_HZEN_Set(x) (((uint16_t) (x) << SDFM_SDCPARM1_HZEN_Pos) & SDFM_SDCPARM1_HZEN_Msk)       /*!< HZEN Set Value            */
#define SDFM_SDCPARM1_HZEN_Get(x) (((uint16_t) (x) & SDFM_SDCPARM1_HZEN_Msk) >> SDFM_SDCPARM1_HZEN_Pos)       /*!< HZEN Get Value            */


#define SDFM_SDCPARM1_MFIE_Pos    (9U)                                                                                  /*!< MFIE Postion   9          */ 
#define SDFM_SDCPARM1_MFIE_Msk    (0x1U << SDFM_SDCPARM1_MFIE_Pos)                                                 /*!< MFIE Mask      0x00000200 */
#define SDFM_SDCPARM1_MFIE_Set(x) (((uint16_t) (x) << SDFM_SDCPARM1_MFIE_Pos) & SDFM_SDCPARM1_MFIE_Msk)       /*!< MFIE Set Value            */
#define SDFM_SDCPARM1_MFIE_Get(x) (((uint16_t) (x) & SDFM_SDCPARM1_MFIE_Msk) >> SDFM_SDCPARM1_MFIE_Pos)       /*!< MFIE Get Value            */


#define SDFM_SDCPARM1_CS1_CS0_Pos    (7U)                                                                                  /*!< CS1_CS0 Postion   7          */ 
#define SDFM_SDCPARM1_CS1_CS0_Msk    (0x3U << SDFM_SDCPARM1_CS1_CS0_Pos)                                              /*!< CS1_CS0 Mask      0x00000180 */
#define SDFM_SDCPARM1_CS1_CS0_Set(x) (((uint16_t) (x) << SDFM_SDCPARM1_CS1_CS0_Pos) & SDFM_SDCPARM1_CS1_CS0_Msk) /*!< CS1_CS0 Set Value            */
#define SDFM_SDCPARM1_CS1_CS0_Get(x) (((uint16_t) (x) & SDFM_SDCPARM1_CS1_CS0_Msk) >> SDFM_SDCPARM1_CS1_CS0_Pos) /*!< CS1_CS0 Get Value            */


#define SDFM_SDCPARM1_EN_CEVT2_Pos    (6U)                                                                                  /*!< EN_CEVT2 Postion   6          */ 
#define SDFM_SDCPARM1_EN_CEVT2_Msk    (0x1U << SDFM_SDCPARM1_EN_CEVT2_Pos)                                             /*!< EN_CEVT2 Mask      0x00000040 */
#define SDFM_SDCPARM1_EN_CEVT2_Set(x) (((uint16_t) (x) << SDFM_SDCPARM1_EN_CEVT2_Pos) & SDFM_SDCPARM1_EN_CEVT2_Msk) /*!< EN_CEVT2 Set Value            */
#define SDFM_SDCPARM1_EN_CEVT2_Get(x) (((uint16_t) (x) & SDFM_SDCPARM1_EN_CEVT2_Msk) >> SDFM_SDCPARM1_EN_CEVT2_Pos) /*!< EN_CEVT2 Get Value            */


#define SDFM_SDCPARM1_EN_CEVT1_Pos    (5U)                                                                                  /*!< EN_CEVT1 Postion   5          */ 
#define SDFM_SDCPARM1_EN_CEVT1_Msk    (0x1U << SDFM_SDCPARM1_EN_CEVT1_Pos)                                             /*!< EN_CEVT1 Mask      0x00000020 */
#define SDFM_SDCPARM1_EN_CEVT1_Set(x) (((uint16_t) (x) << SDFM_SDCPARM1_EN_CEVT1_Pos) & SDFM_SDCPARM1_EN_CEVT1_Msk) /*!< EN_CEVT1 Set Value            */
#define SDFM_SDCPARM1_EN_CEVT1_Get(x) (((uint16_t) (x) & SDFM_SDCPARM1_EN_CEVT1_Msk) >> SDFM_SDCPARM1_EN_CEVT1_Pos) /*!< EN_CEVT1 Get Value            */


#define SDFM_SDCPARM1_COSR_Pos    (0U)                                                                                  /*!< COSR Postion   0          */ 
#define SDFM_SDCPARM1_COSR_Msk    (0x1fU << SDFM_SDCPARM1_COSR_Pos)                                                /*!< COSR Mask      0x0000001F */
#define SDFM_SDCPARM1_COSR_Set(x) (((uint16_t) (x) << SDFM_SDCPARM1_COSR_Pos) & SDFM_SDCPARM1_COSR_Msk)       /*!< COSR Set Value            */
#define SDFM_SDCPARM1_COSR_Get(x) (((uint16_t) (x) & SDFM_SDCPARM1_COSR_Msk) >> SDFM_SDCPARM1_COSR_Pos)       /*!< COSR Get Value            */


/* SDDATA1 bitfield */
#define SDFM_SDDATA1_DATA32HI_Pos    (16U)                                                                                 /*!< DATA32HI Postion   16         */ 
#define SDFM_SDDATA1_DATA32HI_Msk    (0xffffU << SDFM_SDDATA1_DATA32HI_Pos)                                           /*!< DATA32HI Mask      0xFFFF0000 */
#define SDFM_SDDATA1_DATA32HI_Set(x) (((uint32_t) (x) << SDFM_SDDATA1_DATA32HI_Pos) & SDFM_SDDATA1_DATA32HI_Msk) /*!< DATA32HI Set Value            */
#define SDFM_SDDATA1_DATA32HI_Get(x) (((uint32_t) (x) & SDFM_SDDATA1_DATA32HI_Msk) >> SDFM_SDDATA1_DATA32HI_Pos) /*!< DATA32HI Get Value            */


#define SDFM_SDDATA1_DATA16_Pos    (0U)                                                                                  /*!< DATA16 Postion   0          */ 
#define SDFM_SDDATA1_DATA16_Msk    (0xffffU << SDFM_SDDATA1_DATA16_Pos)                                             /*!< DATA16 Mask      0x0000FFFF */
#define SDFM_SDDATA1_DATA16_Set(x) (((uint32_t) (x) << SDFM_SDDATA1_DATA16_Pos) & SDFM_SDDATA1_DATA16_Msk)     /*!< DATA16 Set Value            */
#define SDFM_SDDATA1_DATA16_Get(x) (((uint32_t) (x) & SDFM_SDDATA1_DATA16_Msk) >> SDFM_SDDATA1_DATA16_Pos)     /*!< DATA16 Get Value            */


/* SDDATFIFO1 bitfield */
#define SDFM_SDDATFIFO1_DATA32HI_Pos    (16U)                                                                                 /*!< DATA32HI Postion   16         */ 
#define SDFM_SDDATFIFO1_DATA32HI_Msk    (0xffffU << SDFM_SDDATFIFO1_DATA32HI_Pos)                                        /*!< DATA32HI Mask      0xFFFF0000 */
#define SDFM_SDDATFIFO1_DATA32HI_Set(x) (((uint32_t) (x) << SDFM_SDDATFIFO1_DATA32HI_Pos) & SDFM_SDDATFIFO1_DATA32HI_Msk) /*!< DATA32HI Set Value            */
#define SDFM_SDDATFIFO1_DATA32HI_Get(x) (((uint32_t) (x) & SDFM_SDDATFIFO1_DATA32HI_Msk) >> SDFM_SDDATFIFO1_DATA32HI_Pos) /*!< DATA32HI Get Value            */


#define SDFM_SDDATFIFO1_DATA16_Pos    (0U)                                                                                  /*!< DATA16 Postion   0          */ 
#define SDFM_SDDATFIFO1_DATA16_Msk    (0xffffU << SDFM_SDDATFIFO1_DATA16_Pos)                                          /*!< DATA16 Mask      0x0000FFFF */
#define SDFM_SDDATFIFO1_DATA16_Set(x) (((uint32_t) (x) << SDFM_SDDATFIFO1_DATA16_Pos) & SDFM_SDDATFIFO1_DATA16_Msk) /*!< DATA16 Set Value            */
#define SDFM_SDDATFIFO1_DATA16_Get(x) (((uint32_t) (x) & SDFM_SDDATFIFO1_DATA16_Msk) >> SDFM_SDDATFIFO1_DATA16_Pos) /*!< DATA16 Get Value            */


/* SDCDATA1 bitfield */
#define SDFM_SDCDATA1_DATA16_Pos    (0U)                                                                                  /*!< DATA16 Postion   0          */ 
#define SDFM_SDCDATA1_DATA16_Msk    (0xffffU << SDFM_SDCDATA1_DATA16_Pos)                                            /*!< DATA16 Mask      0x0000FFFF */
#define SDFM_SDCDATA1_DATA16_Set(x) (((uint16_t) (x) << SDFM_SDCDATA1_DATA16_Pos) & SDFM_SDCDATA1_DATA16_Msk)   /*!< DATA16 Set Value            */
#define SDFM_SDCDATA1_DATA16_Get(x) (((uint16_t) (x) & SDFM_SDCDATA1_DATA16_Msk) >> SDFM_SDCDATA1_DATA16_Pos)   /*!< DATA16 Get Value            */


/* SDFLT1CMPH2 bitfield */
#define SDFM_SDFLT1CMPH2_HLT2_Pos    (0U)                                                                                  /*!< HLT2 Postion   0          */ 
#define SDFM_SDFLT1CMPH2_HLT2_Msk    (0x7fffU << SDFM_SDFLT1CMPH2_HLT2_Pos)                                           /*!< HLT2 Mask      0x00007FFF */
#define SDFM_SDFLT1CMPH2_HLT2_Set(x) (((uint16_t) (x) << SDFM_SDFLT1CMPH2_HLT2_Pos) & SDFM_SDFLT1CMPH2_HLT2_Msk) /*!< HLT2 Set Value            */
#define SDFM_SDFLT1CMPH2_HLT2_Get(x) (((uint16_t) (x) & SDFM_SDFLT1CMPH2_HLT2_Msk) >> SDFM_SDFLT1CMPH2_HLT2_Pos) /*!< HLT2 Get Value            */


/* SDFLT1CMPHZ bitfield */
#define SDFM_SDFLT1CMPHZ_HLTZ_Pos    (0U)                                                                                  /*!< HLTZ Postion   0          */ 
#define SDFM_SDFLT1CMPHZ_HLTZ_Msk    (0x7fffU << SDFM_SDFLT1CMPHZ_HLTZ_Pos)                                           /*!< HLTZ Mask      0x00007FFF */
#define SDFM_SDFLT1CMPHZ_HLTZ_Set(x) (((uint16_t) (x) << SDFM_SDFLT1CMPHZ_HLTZ_Pos) & SDFM_SDFLT1CMPHZ_HLTZ_Msk) /*!< HLTZ Set Value            */
#define SDFM_SDFLT1CMPHZ_HLTZ_Get(x) (((uint16_t) (x) & SDFM_SDFLT1CMPHZ_HLTZ_Msk) >> SDFM_SDFLT1CMPHZ_HLTZ_Pos) /*!< HLTZ Get Value            */


/* SDFIFOCTL1 bitfield */
#define SDFM_SDFIFOCTL1_OVFIEN_Pos    (15U)                                                                                 /*!< OVFIEN Postion   15         */ 
#define SDFM_SDFIFOCTL1_OVFIEN_Msk    (0x1U << SDFM_SDFIFOCTL1_OVFIEN_Pos)                                             /*!< OVFIEN Mask      0x00008000 */
#define SDFM_SDFIFOCTL1_OVFIEN_Set(x) (((uint16_t) (x) << SDFM_SDFIFOCTL1_OVFIEN_Pos) & SDFM_SDFIFOCTL1_OVFIEN_Msk) /*!< OVFIEN Set Value            */
#define SDFM_SDFIFOCTL1_OVFIEN_Get(x) (((uint16_t) (x) & SDFM_SDFIFOCTL1_OVFIEN_Msk) >> SDFM_SDFIFOCTL1_OVFIEN_Pos) /*!< OVFIEN Get Value            */


#define SDFM_SDFIFOCTL1_DRINTSEL_Pos    (14U)                                                                                 /*!< DRINTSEL Postion   14         */ 
#define SDFM_SDFIFOCTL1_DRINTSEL_Msk    (0x1U << SDFM_SDFIFOCTL1_DRINTSEL_Pos)                                           /*!< DRINTSEL Mask      0x00004000 */
#define SDFM_SDFIFOCTL1_DRINTSEL_Set(x) (((uint16_t) (x) << SDFM_SDFIFOCTL1_DRINTSEL_Pos) & SDFM_SDFIFOCTL1_DRINTSEL_Msk) /*!< DRINTSEL Set Value            */
#define SDFM_SDFIFOCTL1_DRINTSEL_Get(x) (((uint16_t) (x) & SDFM_SDFIFOCTL1_DRINTSEL_Msk) >> SDFM_SDFIFOCTL1_DRINTSEL_Pos) /*!< DRINTSEL Get Value            */


#define SDFM_SDFIFOCTL1_FFEN_Pos    (13U)                                                                                 /*!< FFEN Postion   13         */ 
#define SDFM_SDFIFOCTL1_FFEN_Msk    (0x1U << SDFM_SDFIFOCTL1_FFEN_Pos)                                               /*!< FFEN Mask      0x00002000 */
#define SDFM_SDFIFOCTL1_FFEN_Set(x) (((uint16_t) (x) << SDFM_SDFIFOCTL1_FFEN_Pos) & SDFM_SDFIFOCTL1_FFEN_Msk)   /*!< FFEN Set Value            */
#define SDFM_SDFIFOCTL1_FFEN_Get(x) (((uint16_t) (x) & SDFM_SDFIFOCTL1_FFEN_Msk) >> SDFM_SDFIFOCTL1_FFEN_Pos)   /*!< FFEN Get Value            */


#define SDFM_SDFIFOCTL1_FFIEN_Pos    (12U)                                                                                 /*!< FFIEN Postion   12         */ 
#define SDFM_SDFIFOCTL1_FFIEN_Msk    (0x1U << SDFM_SDFIFOCTL1_FFIEN_Pos)                                              /*!< FFIEN Mask      0x00001000 */
#define SDFM_SDFIFOCTL1_FFIEN_Set(x) (((uint16_t) (x) << SDFM_SDFIFOCTL1_FFIEN_Pos) & SDFM_SDFIFOCTL1_FFIEN_Msk) /*!< FFIEN Set Value            */
#define SDFM_SDFIFOCTL1_FFIEN_Get(x) (((uint16_t) (x) & SDFM_SDFIFOCTL1_FFIEN_Msk) >> SDFM_SDFIFOCTL1_FFIEN_Pos) /*!< FFIEN Get Value            */


#define SDFM_SDFIFOCTL1_UDFIEN_Pos    (11U)                                                                                 /*!< UDFIEN Postion   11         */ 
#define SDFM_SDFIFOCTL1_UDFIEN_Msk    (0x1U << SDFM_SDFIFOCTL1_UDFIEN_Pos)                                             /*!< UDFIEN Mask      0x00000800 */
#define SDFM_SDFIFOCTL1_UDFIEN_Set(x) (((uint16_t) (x) << SDFM_SDFIFOCTL1_UDFIEN_Pos) & SDFM_SDFIFOCTL1_UDFIEN_Msk) /*!< UDFIEN Set Value            */
#define SDFM_SDFIFOCTL1_UDFIEN_Get(x) (((uint16_t) (x) & SDFM_SDFIFOCTL1_UDFIEN_Msk) >> SDFM_SDFIFOCTL1_UDFIEN_Pos) /*!< UDFIEN Get Value            */


#define SDFM_SDFIFOCTL1_SDFFST_Pos    (6U)                                                                                  /*!< SDFFST Postion   6          */ 
#define SDFM_SDFIFOCTL1_SDFFST_Msk    (0x1fU << SDFM_SDFIFOCTL1_SDFFST_Pos)                                            /*!< SDFFST Mask      0x000007C0 */
#define SDFM_SDFIFOCTL1_SDFFST_Set(x) (((uint16_t) (x) << SDFM_SDFIFOCTL1_SDFFST_Pos) & SDFM_SDFIFOCTL1_SDFFST_Msk) /*!< SDFFST Set Value            */
#define SDFM_SDFIFOCTL1_SDFFST_Get(x) (((uint16_t) (x) & SDFM_SDFIFOCTL1_SDFFST_Msk) >> SDFM_SDFIFOCTL1_SDFFST_Pos) /*!< SDFFST Get Value            */


#define SDFM_SDFIFOCTL1_DRDMASEL_Pos    (5U)                                                                                  /*!< DRDMASEL Postion   5          */ 
#define SDFM_SDFIFOCTL1_DRDMASEL_Msk    (0x1U << SDFM_SDFIFOCTL1_DRDMASEL_Pos)                                           /*!< DRDMASEL Mask      0x00000020 */
#define SDFM_SDFIFOCTL1_DRDMASEL_Set(x) (((uint16_t) (x) << SDFM_SDFIFOCTL1_DRDMASEL_Pos) & SDFM_SDFIFOCTL1_DRDMASEL_Msk) /*!< DRDMASEL Set Value            */
#define SDFM_SDFIFOCTL1_DRDMASEL_Get(x) (((uint16_t) (x) & SDFM_SDFIFOCTL1_DRDMASEL_Msk) >> SDFM_SDFIFOCTL1_DRDMASEL_Pos) /*!< DRDMASEL Get Value            */


#define SDFM_SDFIFOCTL1_SDFFIL_Pos    (0U)                                                                                  /*!< SDFFIL Postion   0          */ 
#define SDFM_SDFIFOCTL1_SDFFIL_Msk    (0x1fU << SDFM_SDFIFOCTL1_SDFFIL_Pos)                                            /*!< SDFFIL Mask      0x0000001F */
#define SDFM_SDFIFOCTL1_SDFFIL_Set(x) (((uint16_t) (x) << SDFM_SDFIFOCTL1_SDFFIL_Pos) & SDFM_SDFIFOCTL1_SDFFIL_Msk) /*!< SDFFIL Set Value            */
#define SDFM_SDFIFOCTL1_SDFFIL_Get(x) (((uint16_t) (x) & SDFM_SDFIFOCTL1_SDFFIL_Msk) >> SDFM_SDFIFOCTL1_SDFFIL_Pos) /*!< SDFFIL Get Value            */


/* SDSYNC1 bitfield */
#define SDFM_SDSYNC1_WTSCLREN_Pos    (10U)                                                                                 /*!< WTSCLREN Postion   10         */ 
#define SDFM_SDSYNC1_WTSCLREN_Msk    (0x1U << SDFM_SDSYNC1_WTSCLREN_Pos)                                              /*!< WTSCLREN Mask      0x00000400 */
#define SDFM_SDSYNC1_WTSCLREN_Set(x) (((uint16_t) (x) << SDFM_SDSYNC1_WTSCLREN_Pos) & SDFM_SDSYNC1_WTSCLREN_Msk) /*!< WTSCLREN Set Value            */
#define SDFM_SDSYNC1_WTSCLREN_Get(x) (((uint16_t) (x) & SDFM_SDSYNC1_WTSCLREN_Msk) >> SDFM_SDSYNC1_WTSCLREN_Pos) /*!< WTSCLREN Get Value            */


#define SDFM_SDSYNC1_FFSYNCCLREN_Pos    (9U)                                                                                  /*!< FFSYNCCLREN Postion   9          */ 
#define SDFM_SDSYNC1_FFSYNCCLREN_Msk    (0x1U << SDFM_SDSYNC1_FFSYNCCLREN_Pos)                                           /*!< FFSYNCCLREN Mask      0x00000200 */
#define SDFM_SDSYNC1_FFSYNCCLREN_Set(x) (((uint16_t) (x) << SDFM_SDSYNC1_FFSYNCCLREN_Pos) & SDFM_SDSYNC1_FFSYNCCLREN_Msk) /*!< FFSYNCCLREN Set Value            */
#define SDFM_SDSYNC1_FFSYNCCLREN_Get(x) (((uint16_t) (x) & SDFM_SDSYNC1_FFSYNCCLREN_Msk) >> SDFM_SDSYNC1_FFSYNCCLREN_Pos) /*!< FFSYNCCLREN Get Value            */


#define SDFM_SDSYNC1_WTSYNCLR_Pos    (8U)                                                                                  /*!< WTSYNCLR Postion   8          */ 
#define SDFM_SDSYNC1_WTSYNCLR_Msk    (0x1U << SDFM_SDSYNC1_WTSYNCLR_Pos)                                              /*!< WTSYNCLR Mask      0x00000100 */
#define SDFM_SDSYNC1_WTSYNCLR_Set(x) (((uint16_t) (x) << SDFM_SDSYNC1_WTSYNCLR_Pos) & SDFM_SDSYNC1_WTSYNCLR_Msk) /*!< WTSYNCLR Set Value            */
#define SDFM_SDSYNC1_WTSYNCLR_Get(x) (((uint16_t) (x) & SDFM_SDSYNC1_WTSYNCLR_Msk) >> SDFM_SDSYNC1_WTSYNCLR_Pos) /*!< WTSYNCLR Get Value            */


#define SDFM_SDSYNC1_WTSYNFLG_Pos    (7U)                                                                                  /*!< WTSYNFLG Postion   7          */ 
#define SDFM_SDSYNC1_WTSYNFLG_Msk    (0x1U << SDFM_SDSYNC1_WTSYNFLG_Pos)                                              /*!< WTSYNFLG Mask      0x00000080 */
#define SDFM_SDSYNC1_WTSYNFLG_Set(x) (((uint16_t) (x) << SDFM_SDSYNC1_WTSYNFLG_Pos) & SDFM_SDSYNC1_WTSYNFLG_Msk) /*!< WTSYNFLG Set Value            */
#define SDFM_SDSYNC1_WTSYNFLG_Get(x) (((uint16_t) (x) & SDFM_SDSYNC1_WTSYNFLG_Msk) >> SDFM_SDSYNC1_WTSYNFLG_Pos) /*!< WTSYNFLG Get Value            */


#define SDFM_SDSYNC1_WTSYNCEN_Pos    (6U)                                                                                  /*!< WTSYNCEN Postion   6          */ 
#define SDFM_SDSYNC1_WTSYNCEN_Msk    (0x1U << SDFM_SDSYNC1_WTSYNCEN_Pos)                                              /*!< WTSYNCEN Mask      0x00000040 */
#define SDFM_SDSYNC1_WTSYNCEN_Set(x) (((uint16_t) (x) << SDFM_SDSYNC1_WTSYNCEN_Pos) & SDFM_SDSYNC1_WTSYNCEN_Msk) /*!< WTSYNCEN Set Value            */
#define SDFM_SDSYNC1_WTSYNCEN_Get(x) (((uint16_t) (x) & SDFM_SDSYNC1_WTSYNCEN_Msk) >> SDFM_SDSYNC1_WTSYNCEN_Pos) /*!< WTSYNCEN Get Value            */


#define SDFM_SDSYNC1_SYNCSEL_Pos    (0U)                                                                                  /*!< SYNCSEL Postion   0          */ 
#define SDFM_SDSYNC1_SYNCSEL_Msk    (0x3fU << SDFM_SDSYNC1_SYNCSEL_Pos)                                              /*!< SYNCSEL Mask      0x0000003F */
#define SDFM_SDSYNC1_SYNCSEL_Set(x) (((uint16_t) (x) << SDFM_SDSYNC1_SYNCSEL_Pos) & SDFM_SDSYNC1_SYNCSEL_Msk)   /*!< SYNCSEL Set Value            */
#define SDFM_SDSYNC1_SYNCSEL_Get(x) (((uint16_t) (x) & SDFM_SDSYNC1_SYNCSEL_Msk) >> SDFM_SDSYNC1_SYNCSEL_Pos)   /*!< SYNCSEL Get Value            */


/* SDFLT1CMPL2 bitfield */
#define SDFM_SDFLT1CMPL2_LLT2_Pos    (0U)                                                                                  /*!< LLT2 Postion   0          */ 
#define SDFM_SDFLT1CMPL2_LLT2_Msk    (0x7fffU << SDFM_SDFLT1CMPL2_LLT2_Pos)                                           /*!< LLT2 Mask      0x00007FFF */
#define SDFM_SDFLT1CMPL2_LLT2_Set(x) (((uint16_t) (x) << SDFM_SDFLT1CMPL2_LLT2_Pos) & SDFM_SDFLT1CMPL2_LLT2_Msk) /*!< LLT2 Set Value            */
#define SDFM_SDFLT1CMPL2_LLT2_Get(x) (((uint16_t) (x) & SDFM_SDFLT1CMPL2_LLT2_Msk) >> SDFM_SDFLT1CMPL2_LLT2_Pos) /*!< LLT2 Get Value            */


/* SDCTLPARM2 bitfield */
#define SDFM_SDCTLPARM2_MOD_Pos    (0U)                                                                                  /*!< MOD Postion   0          */ 
#define SDFM_SDCTLPARM2_MOD_Msk    (0x3U << SDFM_SDCTLPARM2_MOD_Pos)                                                /*!< MOD Mask      0x00000003 */
#define SDFM_SDCTLPARM2_MOD_Set(x) (((uint16_t) (x) << SDFM_SDCTLPARM2_MOD_Pos) & SDFM_SDCTLPARM2_MOD_Msk)     /*!< MOD Set Value            */
#define SDFM_SDCTLPARM2_MOD_Get(x) (((uint16_t) (x) & SDFM_SDCTLPARM2_MOD_Msk) >> SDFM_SDCTLPARM2_MOD_Pos)     /*!< MOD Get Value            */


/* SDDFPARM2 bitfield */
#define SDFM_SDDFPARM2_SDSYNCEN_Pos    (12U)                                                                                 /*!< SDSYNCEN Postion   12         */ 
#define SDFM_SDDFPARM2_SDSYNCEN_Msk    (0x1U << SDFM_SDDFPARM2_SDSYNCEN_Pos)                                            /*!< SDSYNCEN Mask      0x00001000 */
#define SDFM_SDDFPARM2_SDSYNCEN_Set(x) (((uint16_t) (x) << SDFM_SDDFPARM2_SDSYNCEN_Pos) & SDFM_SDDFPARM2_SDSYNCEN_Msk) /*!< SDSYNCEN Set Value            */
#define SDFM_SDDFPARM2_SDSYNCEN_Get(x) (((uint16_t) (x) & SDFM_SDDFPARM2_SDSYNCEN_Msk) >> SDFM_SDDFPARM2_SDSYNCEN_Pos) /*!< SDSYNCEN Get Value            */


#define SDFM_SDDFPARM2_SST_Pos    (10U)                                                                                 /*!< SST Postion   10         */ 
#define SDFM_SDDFPARM2_SST_Msk    (0x3U << SDFM_SDDFPARM2_SST_Pos)                                                 /*!< SST Mask      0x00000C00 */
#define SDFM_SDDFPARM2_SST_Set(x) (((uint16_t) (x) << SDFM_SDDFPARM2_SST_Pos) & SDFM_SDDFPARM2_SST_Msk)       /*!< SST Set Value            */
#define SDFM_SDDFPARM2_SST_Get(x) (((uint16_t) (x) & SDFM_SDDFPARM2_SST_Msk) >> SDFM_SDDFPARM2_SST_Pos)       /*!< SST Get Value            */


#define SDFM_SDDFPARM2_AE_Pos    (9U)                                                                                  /*!< AE Postion   9          */ 
#define SDFM_SDDFPARM2_AE_Msk    (0x1U << SDFM_SDDFPARM2_AE_Pos)                                                  /*!< AE Mask      0x00000200 */
#define SDFM_SDDFPARM2_AE_Set(x) (((uint16_t) (x) << SDFM_SDDFPARM2_AE_Pos) & SDFM_SDDFPARM2_AE_Msk)         /*!< AE Set Value            */
#define SDFM_SDDFPARM2_AE_Get(x) (((uint16_t) (x) & SDFM_SDDFPARM2_AE_Msk) >> SDFM_SDDFPARM2_AE_Pos)         /*!< AE Get Value            */


#define SDFM_SDDFPARM2_FEN_Pos    (8U)                                                                                  /*!< FEN Postion   8          */ 
#define SDFM_SDDFPARM2_FEN_Msk    (0x1U << SDFM_SDDFPARM2_FEN_Pos)                                                 /*!< FEN Mask      0x00000100 */
#define SDFM_SDDFPARM2_FEN_Set(x) (((uint16_t) (x) << SDFM_SDDFPARM2_FEN_Pos) & SDFM_SDDFPARM2_FEN_Msk)       /*!< FEN Set Value            */
#define SDFM_SDDFPARM2_FEN_Get(x) (((uint16_t) (x) & SDFM_SDDFPARM2_FEN_Msk) >> SDFM_SDDFPARM2_FEN_Pos)       /*!< FEN Get Value            */


#define SDFM_SDDFPARM2_DOSR_Pos    (0U)                                                                                  /*!< DOSR Postion   0          */ 
#define SDFM_SDDFPARM2_DOSR_Msk    (0xffU << SDFM_SDDFPARM2_DOSR_Pos)                                               /*!< DOSR Mask      0x000000FF */
#define SDFM_SDDFPARM2_DOSR_Set(x) (((uint16_t) (x) << SDFM_SDDFPARM2_DOSR_Pos) & SDFM_SDDFPARM2_DOSR_Msk)     /*!< DOSR Set Value            */
#define SDFM_SDDFPARM2_DOSR_Get(x) (((uint16_t) (x) & SDFM_SDDFPARM2_DOSR_Msk) >> SDFM_SDDFPARM2_DOSR_Pos)     /*!< DOSR Get Value            */


/* SDDPARM2 bitfield */
#define SDFM_SDDPARM2_SH_Pos    (11U)                                                                                 /*!< SH Postion   11         */ 
#define SDFM_SDDPARM2_SH_Msk    (0x1fU << SDFM_SDDPARM2_SH_Pos)                                                  /*!< SH Mask      0x0000F800 */
#define SDFM_SDDPARM2_SH_Set(x) (((uint16_t) (x) << SDFM_SDDPARM2_SH_Pos) & SDFM_SDDPARM2_SH_Msk)           /*!< SH Set Value            */
#define SDFM_SDDPARM2_SH_Get(x) (((uint16_t) (x) & SDFM_SDDPARM2_SH_Msk) >> SDFM_SDDPARM2_SH_Pos)           /*!< SH Get Value            */


#define SDFM_SDDPARM2_DR_Pos    (10U)                                                                                 /*!< DR Postion   10         */ 
#define SDFM_SDDPARM2_DR_Msk    (0x1U << SDFM_SDDPARM2_DR_Pos)                                                   /*!< DR Mask      0x00000400 */
#define SDFM_SDDPARM2_DR_Set(x) (((uint16_t) (x) << SDFM_SDDPARM2_DR_Pos) & SDFM_SDDPARM2_DR_Msk)           /*!< DR Set Value            */
#define SDFM_SDDPARM2_DR_Get(x) (((uint16_t) (x) & SDFM_SDDPARM2_DR_Msk) >> SDFM_SDDPARM2_DR_Pos)           /*!< DR Get Value            */


/* SDFLT2CMPH1 bitfield */
#define SDFM_SDFLT2CMPH1_HLT_Pos    (0U)                                                                                  /*!< HLT Postion   0          */ 
#define SDFM_SDFLT2CMPH1_HLT_Msk    (0x7fffU << SDFM_SDFLT2CMPH1_HLT_Pos)                                            /*!< HLT Mask      0x00007FFF */
#define SDFM_SDFLT2CMPH1_HLT_Set(x) (((uint16_t) (x) << SDFM_SDFLT2CMPH1_HLT_Pos) & SDFM_SDFLT2CMPH1_HLT_Msk)   /*!< HLT Set Value            */
#define SDFM_SDFLT2CMPH1_HLT_Get(x) (((uint16_t) (x) & SDFM_SDFLT2CMPH1_HLT_Msk) >> SDFM_SDFLT2CMPH1_HLT_Pos)   /*!< HLT Get Value            */


/* SDFLT2CMPL1 bitfield */
#define SDFM_SDFLT2CMPL1_LLT_Pos    (0U)                                                                                  /*!< LLT Postion   0          */ 
#define SDFM_SDFLT2CMPL1_LLT_Msk    (0x7fffU << SDFM_SDFLT2CMPL1_LLT_Pos)                                            /*!< LLT Mask      0x00007FFF */
#define SDFM_SDFLT2CMPL1_LLT_Set(x) (((uint16_t) (x) << SDFM_SDFLT2CMPL1_LLT_Pos) & SDFM_SDFLT2CMPL1_LLT_Msk)   /*!< LLT Set Value            */
#define SDFM_SDFLT2CMPL1_LLT_Get(x) (((uint16_t) (x) & SDFM_SDFLT2CMPL1_LLT_Msk) >> SDFM_SDFLT2CMPL1_LLT_Pos)   /*!< LLT Get Value            */


/* SDCPARM2 bitfield */
#define SDFM_SDCPARM2_CEVT2SEL_Pos    (14U)                                                                                 /*!< CEVT2SEL Postion   14         */ 
#define SDFM_SDCPARM2_CEVT2SEL_Msk    (0x3U << SDFM_SDCPARM2_CEVT2SEL_Pos)                                             /*!< CEVT2SEL Mask      0x0000C000 */
#define SDFM_SDCPARM2_CEVT2SEL_Set(x) (((uint16_t) (x) << SDFM_SDCPARM2_CEVT2SEL_Pos) & SDFM_SDCPARM2_CEVT2SEL_Msk) /*!< CEVT2SEL Set Value            */
#define SDFM_SDCPARM2_CEVT2SEL_Get(x) (((uint16_t) (x) & SDFM_SDCPARM2_CEVT2SEL_Msk) >> SDFM_SDCPARM2_CEVT2SEL_Pos) /*!< CEVT2SEL Get Value            */


#define SDFM_SDCPARM2_CEN_Pos    (13U)                                                                                 /*!< CEN Postion   13         */ 
#define SDFM_SDCPARM2_CEN_Msk    (0x1U << SDFM_SDCPARM2_CEN_Pos)                                                  /*!< CEN Mask      0x00002000 */
#define SDFM_SDCPARM2_CEN_Set(x) (((uint16_t) (x) << SDFM_SDCPARM2_CEN_Pos) & SDFM_SDCPARM2_CEN_Msk)         /*!< CEN Set Value            */
#define SDFM_SDCPARM2_CEN_Get(x) (((uint16_t) (x) & SDFM_SDCPARM2_CEN_Msk) >> SDFM_SDCPARM2_CEN_Pos)         /*!< CEN Get Value            */


#define SDFM_SDCPARM2_CEVT1SEL_Pos    (11U)                                                                                 /*!< CEVT1SEL Postion   11         */ 
#define SDFM_SDCPARM2_CEVT1SEL_Msk    (0x3U << SDFM_SDCPARM2_CEVT1SEL_Pos)                                             /*!< CEVT1SEL Mask      0x00001800 */
#define SDFM_SDCPARM2_CEVT1SEL_Set(x) (((uint16_t) (x) << SDFM_SDCPARM2_CEVT1SEL_Pos) & SDFM_SDCPARM2_CEVT1SEL_Msk) /*!< CEVT1SEL Set Value            */
#define SDFM_SDCPARM2_CEVT1SEL_Get(x) (((uint16_t) (x) & SDFM_SDCPARM2_CEVT1SEL_Msk) >> SDFM_SDCPARM2_CEVT1SEL_Pos) /*!< CEVT1SEL Get Value            */


#define SDFM_SDCPARM2_HZEN_Pos    (10U)                                                                                 /*!< HZEN Postion   10         */ 
#define SDFM_SDCPARM2_HZEN_Msk    (0x1U << SDFM_SDCPARM2_HZEN_Pos)                                                 /*!< HZEN Mask      0x00000400 */
#define SDFM_SDCPARM2_HZEN_Set(x) (((uint16_t) (x) << SDFM_SDCPARM2_HZEN_Pos) & SDFM_SDCPARM2_HZEN_Msk)       /*!< HZEN Set Value            */
#define SDFM_SDCPARM2_HZEN_Get(x) (((uint16_t) (x) & SDFM_SDCPARM2_HZEN_Msk) >> SDFM_SDCPARM2_HZEN_Pos)       /*!< HZEN Get Value            */


#define SDFM_SDCPARM2_MFIE_Pos    (9U)                                                                                  /*!< MFIE Postion   9          */ 
#define SDFM_SDCPARM2_MFIE_Msk    (0x1U << SDFM_SDCPARM2_MFIE_Pos)                                                 /*!< MFIE Mask      0x00000200 */
#define SDFM_SDCPARM2_MFIE_Set(x) (((uint16_t) (x) << SDFM_SDCPARM2_MFIE_Pos) & SDFM_SDCPARM2_MFIE_Msk)       /*!< MFIE Set Value            */
#define SDFM_SDCPARM2_MFIE_Get(x) (((uint16_t) (x) & SDFM_SDCPARM2_MFIE_Msk) >> SDFM_SDCPARM2_MFIE_Pos)       /*!< MFIE Get Value            */


#define SDFM_SDCPARM2_CS1_CS0_Pos    (7U)                                                                                  /*!< CS1_CS0 Postion   7          */ 
#define SDFM_SDCPARM2_CS1_CS0_Msk    (0x3U << SDFM_SDCPARM2_CS1_CS0_Pos)                                              /*!< CS1_CS0 Mask      0x00000180 */
#define SDFM_SDCPARM2_CS1_CS0_Set(x) (((uint16_t) (x) << SDFM_SDCPARM2_CS1_CS0_Pos) & SDFM_SDCPARM2_CS1_CS0_Msk) /*!< CS1_CS0 Set Value            */
#define SDFM_SDCPARM2_CS1_CS0_Get(x) (((uint16_t) (x) & SDFM_SDCPARM2_CS1_CS0_Msk) >> SDFM_SDCPARM2_CS1_CS0_Pos) /*!< CS1_CS0 Get Value            */


#define SDFM_SDCPARM2_EN_CEVT2_Pos    (6U)                                                                                  /*!< EN_CEVT2 Postion   6          */ 
#define SDFM_SDCPARM2_EN_CEVT2_Msk    (0x1U << SDFM_SDCPARM2_EN_CEVT2_Pos)                                             /*!< EN_CEVT2 Mask      0x00000040 */
#define SDFM_SDCPARM2_EN_CEVT2_Set(x) (((uint16_t) (x) << SDFM_SDCPARM2_EN_CEVT2_Pos) & SDFM_SDCPARM2_EN_CEVT2_Msk) /*!< EN_CEVT2 Set Value            */
#define SDFM_SDCPARM2_EN_CEVT2_Get(x) (((uint16_t) (x) & SDFM_SDCPARM2_EN_CEVT2_Msk) >> SDFM_SDCPARM2_EN_CEVT2_Pos) /*!< EN_CEVT2 Get Value            */


#define SDFM_SDCPARM2_EN_CEVT1_Pos    (5U)                                                                                  /*!< EN_CEVT1 Postion   5          */ 
#define SDFM_SDCPARM2_EN_CEVT1_Msk    (0x1U << SDFM_SDCPARM2_EN_CEVT1_Pos)                                             /*!< EN_CEVT1 Mask      0x00000020 */
#define SDFM_SDCPARM2_EN_CEVT1_Set(x) (((uint16_t) (x) << SDFM_SDCPARM2_EN_CEVT1_Pos) & SDFM_SDCPARM2_EN_CEVT1_Msk) /*!< EN_CEVT1 Set Value            */
#define SDFM_SDCPARM2_EN_CEVT1_Get(x) (((uint16_t) (x) & SDFM_SDCPARM2_EN_CEVT1_Msk) >> SDFM_SDCPARM2_EN_CEVT1_Pos) /*!< EN_CEVT1 Get Value            */


#define SDFM_SDCPARM2_COSR_Pos    (0U)                                                                                  /*!< COSR Postion   0          */ 
#define SDFM_SDCPARM2_COSR_Msk    (0x1fU << SDFM_SDCPARM2_COSR_Pos)                                                /*!< COSR Mask      0x0000001F */
#define SDFM_SDCPARM2_COSR_Set(x) (((uint16_t) (x) << SDFM_SDCPARM2_COSR_Pos) & SDFM_SDCPARM2_COSR_Msk)       /*!< COSR Set Value            */
#define SDFM_SDCPARM2_COSR_Get(x) (((uint16_t) (x) & SDFM_SDCPARM2_COSR_Msk) >> SDFM_SDCPARM2_COSR_Pos)       /*!< COSR Get Value            */


/* SDDATA2 bitfield */
#define SDFM_SDDATA2_DATA32HI_Pos    (16U)                                                                                 /*!< DATA32HI Postion   16         */ 
#define SDFM_SDDATA2_DATA32HI_Msk    (0xffffU << SDFM_SDDATA2_DATA32HI_Pos)                                           /*!< DATA32HI Mask      0xFFFF0000 */
#define SDFM_SDDATA2_DATA32HI_Set(x) (((uint32_t) (x) << SDFM_SDDATA2_DATA32HI_Pos) & SDFM_SDDATA2_DATA32HI_Msk) /*!< DATA32HI Set Value            */
#define SDFM_SDDATA2_DATA32HI_Get(x) (((uint32_t) (x) & SDFM_SDDATA2_DATA32HI_Msk) >> SDFM_SDDATA2_DATA32HI_Pos) /*!< DATA32HI Get Value            */


#define SDFM_SDDATA2_DATA16_Pos    (0U)                                                                                  /*!< DATA16 Postion   0          */ 
#define SDFM_SDDATA2_DATA16_Msk    (0xffffU << SDFM_SDDATA2_DATA16_Pos)                                             /*!< DATA16 Mask      0x0000FFFF */
#define SDFM_SDDATA2_DATA16_Set(x) (((uint32_t) (x) << SDFM_SDDATA2_DATA16_Pos) & SDFM_SDDATA2_DATA16_Msk)     /*!< DATA16 Set Value            */
#define SDFM_SDDATA2_DATA16_Get(x) (((uint32_t) (x) & SDFM_SDDATA2_DATA16_Msk) >> SDFM_SDDATA2_DATA16_Pos)     /*!< DATA16 Get Value            */


/* SDDATFIFO2 bitfield */
#define SDFM_SDDATFIFO2_DATA32HI_Pos    (16U)                                                                                 /*!< DATA32HI Postion   16         */ 
#define SDFM_SDDATFIFO2_DATA32HI_Msk    (0xffffU << SDFM_SDDATFIFO2_DATA32HI_Pos)                                        /*!< DATA32HI Mask      0xFFFF0000 */
#define SDFM_SDDATFIFO2_DATA32HI_Set(x) (((uint32_t) (x) << SDFM_SDDATFIFO2_DATA32HI_Pos) & SDFM_SDDATFIFO2_DATA32HI_Msk) /*!< DATA32HI Set Value            */
#define SDFM_SDDATFIFO2_DATA32HI_Get(x) (((uint32_t) (x) & SDFM_SDDATFIFO2_DATA32HI_Msk) >> SDFM_SDDATFIFO2_DATA32HI_Pos) /*!< DATA32HI Get Value            */


#define SDFM_SDDATFIFO2_DATA16_Pos    (0U)                                                                                  /*!< DATA16 Postion   0          */ 
#define SDFM_SDDATFIFO2_DATA16_Msk    (0xffffU << SDFM_SDDATFIFO2_DATA16_Pos)                                          /*!< DATA16 Mask      0x0000FFFF */
#define SDFM_SDDATFIFO2_DATA16_Set(x) (((uint32_t) (x) << SDFM_SDDATFIFO2_DATA16_Pos) & SDFM_SDDATFIFO2_DATA16_Msk) /*!< DATA16 Set Value            */
#define SDFM_SDDATFIFO2_DATA16_Get(x) (((uint32_t) (x) & SDFM_SDDATFIFO2_DATA16_Msk) >> SDFM_SDDATFIFO2_DATA16_Pos) /*!< DATA16 Get Value            */


/* SDCDATA2 bitfield */
#define SDFM_SDCDATA2_DATA16_Pos    (0U)                                                                                  /*!< DATA16 Postion   0          */ 
#define SDFM_SDCDATA2_DATA16_Msk    (0xffffU << SDFM_SDCDATA2_DATA16_Pos)                                            /*!< DATA16 Mask      0x0000FFFF */
#define SDFM_SDCDATA2_DATA16_Set(x) (((uint16_t) (x) << SDFM_SDCDATA2_DATA16_Pos) & SDFM_SDCDATA2_DATA16_Msk)   /*!< DATA16 Set Value            */
#define SDFM_SDCDATA2_DATA16_Get(x) (((uint16_t) (x) & SDFM_SDCDATA2_DATA16_Msk) >> SDFM_SDCDATA2_DATA16_Pos)   /*!< DATA16 Get Value            */


/* SDFLT2CMPH2 bitfield */
#define SDFM_SDFLT2CMPH2_HLT2_Pos    (0U)                                                                                  /*!< HLT2 Postion   0          */ 
#define SDFM_SDFLT2CMPH2_HLT2_Msk    (0x7fffU << SDFM_SDFLT2CMPH2_HLT2_Pos)                                           /*!< HLT2 Mask      0x00007FFF */
#define SDFM_SDFLT2CMPH2_HLT2_Set(x) (((uint16_t) (x) << SDFM_SDFLT2CMPH2_HLT2_Pos) & SDFM_SDFLT2CMPH2_HLT2_Msk) /*!< HLT2 Set Value            */
#define SDFM_SDFLT2CMPH2_HLT2_Get(x) (((uint16_t) (x) & SDFM_SDFLT2CMPH2_HLT2_Msk) >> SDFM_SDFLT2CMPH2_HLT2_Pos) /*!< HLT2 Get Value            */


/* SDFLT2CMPHZ bitfield */
#define SDFM_SDFLT2CMPHZ_HLTZ_Pos    (0U)                                                                                  /*!< HLTZ Postion   0          */ 
#define SDFM_SDFLT2CMPHZ_HLTZ_Msk    (0x7fffU << SDFM_SDFLT2CMPHZ_HLTZ_Pos)                                           /*!< HLTZ Mask      0x00007FFF */
#define SDFM_SDFLT2CMPHZ_HLTZ_Set(x) (((uint16_t) (x) << SDFM_SDFLT2CMPHZ_HLTZ_Pos) & SDFM_SDFLT2CMPHZ_HLTZ_Msk) /*!< HLTZ Set Value            */
#define SDFM_SDFLT2CMPHZ_HLTZ_Get(x) (((uint16_t) (x) & SDFM_SDFLT2CMPHZ_HLTZ_Msk) >> SDFM_SDFLT2CMPHZ_HLTZ_Pos) /*!< HLTZ Get Value            */


/* SDFIFOCTL2 bitfield */
#define SDFM_SDFIFOCTL2_OVFIEN_Pos    (15U)                                                                                 /*!< OVFIEN Postion   15         */ 
#define SDFM_SDFIFOCTL2_OVFIEN_Msk    (0x1U << SDFM_SDFIFOCTL2_OVFIEN_Pos)                                             /*!< OVFIEN Mask      0x00008000 */
#define SDFM_SDFIFOCTL2_OVFIEN_Set(x) (((uint16_t) (x) << SDFM_SDFIFOCTL2_OVFIEN_Pos) & SDFM_SDFIFOCTL2_OVFIEN_Msk) /*!< OVFIEN Set Value            */
#define SDFM_SDFIFOCTL2_OVFIEN_Get(x) (((uint16_t) (x) & SDFM_SDFIFOCTL2_OVFIEN_Msk) >> SDFM_SDFIFOCTL2_OVFIEN_Pos) /*!< OVFIEN Get Value            */


#define SDFM_SDFIFOCTL2_DRINTSEL_Pos    (14U)                                                                                 /*!< DRINTSEL Postion   14         */ 
#define SDFM_SDFIFOCTL2_DRINTSEL_Msk    (0x1U << SDFM_SDFIFOCTL2_DRINTSEL_Pos)                                           /*!< DRINTSEL Mask      0x00004000 */
#define SDFM_SDFIFOCTL2_DRINTSEL_Set(x) (((uint16_t) (x) << SDFM_SDFIFOCTL2_DRINTSEL_Pos) & SDFM_SDFIFOCTL2_DRINTSEL_Msk) /*!< DRINTSEL Set Value            */
#define SDFM_SDFIFOCTL2_DRINTSEL_Get(x) (((uint16_t) (x) & SDFM_SDFIFOCTL2_DRINTSEL_Msk) >> SDFM_SDFIFOCTL2_DRINTSEL_Pos) /*!< DRINTSEL Get Value            */


#define SDFM_SDFIFOCTL2_FFEN_Pos    (13U)                                                                                 /*!< FFEN Postion   13         */ 
#define SDFM_SDFIFOCTL2_FFEN_Msk    (0x1U << SDFM_SDFIFOCTL2_FFEN_Pos)                                               /*!< FFEN Mask      0x00002000 */
#define SDFM_SDFIFOCTL2_FFEN_Set(x) (((uint16_t) (x) << SDFM_SDFIFOCTL2_FFEN_Pos) & SDFM_SDFIFOCTL2_FFEN_Msk)   /*!< FFEN Set Value            */
#define SDFM_SDFIFOCTL2_FFEN_Get(x) (((uint16_t) (x) & SDFM_SDFIFOCTL2_FFEN_Msk) >> SDFM_SDFIFOCTL2_FFEN_Pos)   /*!< FFEN Get Value            */


#define SDFM_SDFIFOCTL2_FFIEN_Pos    (12U)                                                                                 /*!< FFIEN Postion   12         */ 
#define SDFM_SDFIFOCTL2_FFIEN_Msk    (0x1U << SDFM_SDFIFOCTL2_FFIEN_Pos)                                              /*!< FFIEN Mask      0x00001000 */
#define SDFM_SDFIFOCTL2_FFIEN_Set(x) (((uint16_t) (x) << SDFM_SDFIFOCTL2_FFIEN_Pos) & SDFM_SDFIFOCTL2_FFIEN_Msk) /*!< FFIEN Set Value            */
#define SDFM_SDFIFOCTL2_FFIEN_Get(x) (((uint16_t) (x) & SDFM_SDFIFOCTL2_FFIEN_Msk) >> SDFM_SDFIFOCTL2_FFIEN_Pos) /*!< FFIEN Get Value            */


#define SDFM_SDFIFOCTL2_UDFIEN_Pos    (11U)                                                                                 /*!< UDFIEN Postion   11         */ 
#define SDFM_SDFIFOCTL2_UDFIEN_Msk    (0x1U << SDFM_SDFIFOCTL2_UDFIEN_Pos)                                             /*!< UDFIEN Mask      0x00000800 */
#define SDFM_SDFIFOCTL2_UDFIEN_Set(x) (((uint16_t) (x) << SDFM_SDFIFOCTL2_UDFIEN_Pos) & SDFM_SDFIFOCTL2_UDFIEN_Msk) /*!< UDFIEN Set Value            */
#define SDFM_SDFIFOCTL2_UDFIEN_Get(x) (((uint16_t) (x) & SDFM_SDFIFOCTL2_UDFIEN_Msk) >> SDFM_SDFIFOCTL2_UDFIEN_Pos) /*!< UDFIEN Get Value            */


#define SDFM_SDFIFOCTL2_SDFFST_Pos    (6U)                                                                                  /*!< SDFFST Postion   6          */ 
#define SDFM_SDFIFOCTL2_SDFFST_Msk    (0x1fU << SDFM_SDFIFOCTL2_SDFFST_Pos)                                            /*!< SDFFST Mask      0x000007C0 */
#define SDFM_SDFIFOCTL2_SDFFST_Set(x) (((uint16_t) (x) << SDFM_SDFIFOCTL2_SDFFST_Pos) & SDFM_SDFIFOCTL2_SDFFST_Msk) /*!< SDFFST Set Value            */
#define SDFM_SDFIFOCTL2_SDFFST_Get(x) (((uint16_t) (x) & SDFM_SDFIFOCTL2_SDFFST_Msk) >> SDFM_SDFIFOCTL2_SDFFST_Pos) /*!< SDFFST Get Value            */


#define SDFM_SDFIFOCTL2_DRDMASEL_Pos    (5U)                                                                                  /*!< DRDMASEL Postion   5          */ 
#define SDFM_SDFIFOCTL2_DRDMASEL_Msk    (0x1U << SDFM_SDFIFOCTL2_DRDMASEL_Pos)                                           /*!< DRDMASEL Mask      0x00000020 */
#define SDFM_SDFIFOCTL2_DRDMASEL_Set(x) (((uint16_t) (x) << SDFM_SDFIFOCTL2_DRDMASEL_Pos) & SDFM_SDFIFOCTL2_DRDMASEL_Msk) /*!< DRDMASEL Set Value            */
#define SDFM_SDFIFOCTL2_DRDMASEL_Get(x) (((uint16_t) (x) & SDFM_SDFIFOCTL2_DRDMASEL_Msk) >> SDFM_SDFIFOCTL2_DRDMASEL_Pos) /*!< DRDMASEL Get Value            */


#define SDFM_SDFIFOCTL2_SDFFIL_Pos    (0U)                                                                                  /*!< SDFFIL Postion   0          */ 
#define SDFM_SDFIFOCTL2_SDFFIL_Msk    (0x1fU << SDFM_SDFIFOCTL2_SDFFIL_Pos)                                            /*!< SDFFIL Mask      0x0000001F */
#define SDFM_SDFIFOCTL2_SDFFIL_Set(x) (((uint16_t) (x) << SDFM_SDFIFOCTL2_SDFFIL_Pos) & SDFM_SDFIFOCTL2_SDFFIL_Msk) /*!< SDFFIL Set Value            */
#define SDFM_SDFIFOCTL2_SDFFIL_Get(x) (((uint16_t) (x) & SDFM_SDFIFOCTL2_SDFFIL_Msk) >> SDFM_SDFIFOCTL2_SDFFIL_Pos) /*!< SDFFIL Get Value            */


/* SDSYNC2 bitfield */
#define SDFM_SDSYNC2_WTSCLREN_Pos    (10U)                                                                                 /*!< WTSCLREN Postion   10         */ 
#define SDFM_SDSYNC2_WTSCLREN_Msk    (0x1U << SDFM_SDSYNC2_WTSCLREN_Pos)                                              /*!< WTSCLREN Mask      0x00000400 */
#define SDFM_SDSYNC2_WTSCLREN_Set(x) (((uint16_t) (x) << SDFM_SDSYNC2_WTSCLREN_Pos) & SDFM_SDSYNC2_WTSCLREN_Msk) /*!< WTSCLREN Set Value            */
#define SDFM_SDSYNC2_WTSCLREN_Get(x) (((uint16_t) (x) & SDFM_SDSYNC2_WTSCLREN_Msk) >> SDFM_SDSYNC2_WTSCLREN_Pos) /*!< WTSCLREN Get Value            */


#define SDFM_SDSYNC2_FFSYNCCLREN_Pos    (9U)                                                                                  /*!< FFSYNCCLREN Postion   9          */ 
#define SDFM_SDSYNC2_FFSYNCCLREN_Msk    (0x1U << SDFM_SDSYNC2_FFSYNCCLREN_Pos)                                           /*!< FFSYNCCLREN Mask      0x00000200 */
#define SDFM_SDSYNC2_FFSYNCCLREN_Set(x) (((uint16_t) (x) << SDFM_SDSYNC2_FFSYNCCLREN_Pos) & SDFM_SDSYNC2_FFSYNCCLREN_Msk) /*!< FFSYNCCLREN Set Value            */
#define SDFM_SDSYNC2_FFSYNCCLREN_Get(x) (((uint16_t) (x) & SDFM_SDSYNC2_FFSYNCCLREN_Msk) >> SDFM_SDSYNC2_FFSYNCCLREN_Pos) /*!< FFSYNCCLREN Get Value            */


#define SDFM_SDSYNC2_WTSYNCLR_Pos    (8U)                                                                                  /*!< WTSYNCLR Postion   8          */ 
#define SDFM_SDSYNC2_WTSYNCLR_Msk    (0x1U << SDFM_SDSYNC2_WTSYNCLR_Pos)                                              /*!< WTSYNCLR Mask      0x00000100 */
#define SDFM_SDSYNC2_WTSYNCLR_Set(x) (((uint16_t) (x) << SDFM_SDSYNC2_WTSYNCLR_Pos) & SDFM_SDSYNC2_WTSYNCLR_Msk) /*!< WTSYNCLR Set Value            */
#define SDFM_SDSYNC2_WTSYNCLR_Get(x) (((uint16_t) (x) & SDFM_SDSYNC2_WTSYNCLR_Msk) >> SDFM_SDSYNC2_WTSYNCLR_Pos) /*!< WTSYNCLR Get Value            */


#define SDFM_SDSYNC2_WTSYNFLG_Pos    (7U)                                                                                  /*!< WTSYNFLG Postion   7          */ 
#define SDFM_SDSYNC2_WTSYNFLG_Msk    (0x1U << SDFM_SDSYNC2_WTSYNFLG_Pos)                                              /*!< WTSYNFLG Mask      0x00000080 */
#define SDFM_SDSYNC2_WTSYNFLG_Set(x) (((uint16_t) (x) << SDFM_SDSYNC2_WTSYNFLG_Pos) & SDFM_SDSYNC2_WTSYNFLG_Msk) /*!< WTSYNFLG Set Value            */
#define SDFM_SDSYNC2_WTSYNFLG_Get(x) (((uint16_t) (x) & SDFM_SDSYNC2_WTSYNFLG_Msk) >> SDFM_SDSYNC2_WTSYNFLG_Pos) /*!< WTSYNFLG Get Value            */


#define SDFM_SDSYNC2_WTSYNCEN_Pos    (6U)                                                                                  /*!< WTSYNCEN Postion   6          */ 
#define SDFM_SDSYNC2_WTSYNCEN_Msk    (0x1U << SDFM_SDSYNC2_WTSYNCEN_Pos)                                              /*!< WTSYNCEN Mask      0x00000040 */
#define SDFM_SDSYNC2_WTSYNCEN_Set(x) (((uint16_t) (x) << SDFM_SDSYNC2_WTSYNCEN_Pos) & SDFM_SDSYNC2_WTSYNCEN_Msk) /*!< WTSYNCEN Set Value            */
#define SDFM_SDSYNC2_WTSYNCEN_Get(x) (((uint16_t) (x) & SDFM_SDSYNC2_WTSYNCEN_Msk) >> SDFM_SDSYNC2_WTSYNCEN_Pos) /*!< WTSYNCEN Get Value            */


#define SDFM_SDSYNC2_SYNCSEL_Pos    (0U)                                                                                  /*!< SYNCSEL Postion   0          */ 
#define SDFM_SDSYNC2_SYNCSEL_Msk    (0x3fU << SDFM_SDSYNC2_SYNCSEL_Pos)                                              /*!< SYNCSEL Mask      0x0000003F */
#define SDFM_SDSYNC2_SYNCSEL_Set(x) (((uint16_t) (x) << SDFM_SDSYNC2_SYNCSEL_Pos) & SDFM_SDSYNC2_SYNCSEL_Msk)   /*!< SYNCSEL Set Value            */
#define SDFM_SDSYNC2_SYNCSEL_Get(x) (((uint16_t) (x) & SDFM_SDSYNC2_SYNCSEL_Msk) >> SDFM_SDSYNC2_SYNCSEL_Pos)   /*!< SYNCSEL Get Value            */


/* SDFLT2CMPL2 bitfield */
#define SDFM_SDFLT2CMPL2_LLT2_Pos    (0U)                                                                                  /*!< LLT2 Postion   0          */ 
#define SDFM_SDFLT2CMPL2_LLT2_Msk    (0x7fffU << SDFM_SDFLT2CMPL2_LLT2_Pos)                                           /*!< LLT2 Mask      0x00007FFF */
#define SDFM_SDFLT2CMPL2_LLT2_Set(x) (((uint16_t) (x) << SDFM_SDFLT2CMPL2_LLT2_Pos) & SDFM_SDFLT2CMPL2_LLT2_Msk) /*!< LLT2 Set Value            */
#define SDFM_SDFLT2CMPL2_LLT2_Get(x) (((uint16_t) (x) & SDFM_SDFLT2CMPL2_LLT2_Msk) >> SDFM_SDFLT2CMPL2_LLT2_Pos) /*!< LLT2 Get Value            */


/* SDCTLPARM3 bitfield */
#define SDFM_SDCTLPARM3_MOD_Pos    (0U)                                                                                  /*!< MOD Postion   0          */ 
#define SDFM_SDCTLPARM3_MOD_Msk    (0x3U << SDFM_SDCTLPARM3_MOD_Pos)                                                /*!< MOD Mask      0x00000003 */
#define SDFM_SDCTLPARM3_MOD_Set(x) (((uint16_t) (x) << SDFM_SDCTLPARM3_MOD_Pos) & SDFM_SDCTLPARM3_MOD_Msk)     /*!< MOD Set Value            */
#define SDFM_SDCTLPARM3_MOD_Get(x) (((uint16_t) (x) & SDFM_SDCTLPARM3_MOD_Msk) >> SDFM_SDCTLPARM3_MOD_Pos)     /*!< MOD Get Value            */


/* SDDFPARM3 bitfield */
#define SDFM_SDDFPARM3_SDSYNCEN_Pos    (12U)                                                                                 /*!< SDSYNCEN Postion   12         */ 
#define SDFM_SDDFPARM3_SDSYNCEN_Msk    (0x1U << SDFM_SDDFPARM3_SDSYNCEN_Pos)                                            /*!< SDSYNCEN Mask      0x00001000 */
#define SDFM_SDDFPARM3_SDSYNCEN_Set(x) (((uint16_t) (x) << SDFM_SDDFPARM3_SDSYNCEN_Pos) & SDFM_SDDFPARM3_SDSYNCEN_Msk) /*!< SDSYNCEN Set Value            */
#define SDFM_SDDFPARM3_SDSYNCEN_Get(x) (((uint16_t) (x) & SDFM_SDDFPARM3_SDSYNCEN_Msk) >> SDFM_SDDFPARM3_SDSYNCEN_Pos) /*!< SDSYNCEN Get Value            */


#define SDFM_SDDFPARM3_SST_Pos    (10U)                                                                                 /*!< SST Postion   10         */ 
#define SDFM_SDDFPARM3_SST_Msk    (0x3U << SDFM_SDDFPARM3_SST_Pos)                                                 /*!< SST Mask      0x00000C00 */
#define SDFM_SDDFPARM3_SST_Set(x) (((uint16_t) (x) << SDFM_SDDFPARM3_SST_Pos) & SDFM_SDDFPARM3_SST_Msk)       /*!< SST Set Value            */
#define SDFM_SDDFPARM3_SST_Get(x) (((uint16_t) (x) & SDFM_SDDFPARM3_SST_Msk) >> SDFM_SDDFPARM3_SST_Pos)       /*!< SST Get Value            */


#define SDFM_SDDFPARM3_AE_Pos    (9U)                                                                                  /*!< AE Postion   9          */ 
#define SDFM_SDDFPARM3_AE_Msk    (0x1U << SDFM_SDDFPARM3_AE_Pos)                                                  /*!< AE Mask      0x00000200 */
#define SDFM_SDDFPARM3_AE_Set(x) (((uint16_t) (x) << SDFM_SDDFPARM3_AE_Pos) & SDFM_SDDFPARM3_AE_Msk)         /*!< AE Set Value            */
#define SDFM_SDDFPARM3_AE_Get(x) (((uint16_t) (x) & SDFM_SDDFPARM3_AE_Msk) >> SDFM_SDDFPARM3_AE_Pos)         /*!< AE Get Value            */


#define SDFM_SDDFPARM3_FEN_Pos    (8U)                                                                                  /*!< FEN Postion   8          */ 
#define SDFM_SDDFPARM3_FEN_Msk    (0x1U << SDFM_SDDFPARM3_FEN_Pos)                                                 /*!< FEN Mask      0x00000100 */
#define SDFM_SDDFPARM3_FEN_Set(x) (((uint16_t) (x) << SDFM_SDDFPARM3_FEN_Pos) & SDFM_SDDFPARM3_FEN_Msk)       /*!< FEN Set Value            */
#define SDFM_SDDFPARM3_FEN_Get(x) (((uint16_t) (x) & SDFM_SDDFPARM3_FEN_Msk) >> SDFM_SDDFPARM3_FEN_Pos)       /*!< FEN Get Value            */


#define SDFM_SDDFPARM3_DOSR_Pos    (0U)                                                                                  /*!< DOSR Postion   0          */ 
#define SDFM_SDDFPARM3_DOSR_Msk    (0xffU << SDFM_SDDFPARM3_DOSR_Pos)                                               /*!< DOSR Mask      0x000000FF */
#define SDFM_SDDFPARM3_DOSR_Set(x) (((uint16_t) (x) << SDFM_SDDFPARM3_DOSR_Pos) & SDFM_SDDFPARM3_DOSR_Msk)     /*!< DOSR Set Value            */
#define SDFM_SDDFPARM3_DOSR_Get(x) (((uint16_t) (x) & SDFM_SDDFPARM3_DOSR_Msk) >> SDFM_SDDFPARM3_DOSR_Pos)     /*!< DOSR Get Value            */


/* SDDPARM3 bitfield */
#define SDFM_SDDPARM3_SH_Pos    (11U)                                                                                 /*!< SH Postion   11         */ 
#define SDFM_SDDPARM3_SH_Msk    (0x1fU << SDFM_SDDPARM3_SH_Pos)                                                  /*!< SH Mask      0x0000F800 */
#define SDFM_SDDPARM3_SH_Set(x) (((uint16_t) (x) << SDFM_SDDPARM3_SH_Pos) & SDFM_SDDPARM3_SH_Msk)           /*!< SH Set Value            */
#define SDFM_SDDPARM3_SH_Get(x) (((uint16_t) (x) & SDFM_SDDPARM3_SH_Msk) >> SDFM_SDDPARM3_SH_Pos)           /*!< SH Get Value            */


#define SDFM_SDDPARM3_DR_Pos    (10U)                                                                                 /*!< DR Postion   10         */ 
#define SDFM_SDDPARM3_DR_Msk    (0x1U << SDFM_SDDPARM3_DR_Pos)                                                   /*!< DR Mask      0x00000400 */
#define SDFM_SDDPARM3_DR_Set(x) (((uint16_t) (x) << SDFM_SDDPARM3_DR_Pos) & SDFM_SDDPARM3_DR_Msk)           /*!< DR Set Value            */
#define SDFM_SDDPARM3_DR_Get(x) (((uint16_t) (x) & SDFM_SDDPARM3_DR_Msk) >> SDFM_SDDPARM3_DR_Pos)           /*!< DR Get Value            */


/* SDFLT3CMPH1 bitfield */
#define SDFM_SDFLT3CMPH1_HLT_Pos    (0U)                                                                                  /*!< HLT Postion   0          */ 
#define SDFM_SDFLT3CMPH1_HLT_Msk    (0x7fffU << SDFM_SDFLT3CMPH1_HLT_Pos)                                            /*!< HLT Mask      0x00007FFF */
#define SDFM_SDFLT3CMPH1_HLT_Set(x) (((uint16_t) (x) << SDFM_SDFLT3CMPH1_HLT_Pos) & SDFM_SDFLT3CMPH1_HLT_Msk)   /*!< HLT Set Value            */
#define SDFM_SDFLT3CMPH1_HLT_Get(x) (((uint16_t) (x) & SDFM_SDFLT3CMPH1_HLT_Msk) >> SDFM_SDFLT3CMPH1_HLT_Pos)   /*!< HLT Get Value            */


/* SDFLT3CMPL1 bitfield */
#define SDFM_SDFLT3CMPL1_LLT_Pos    (0U)                                                                                  /*!< LLT Postion   0          */ 
#define SDFM_SDFLT3CMPL1_LLT_Msk    (0x7fffU << SDFM_SDFLT3CMPL1_LLT_Pos)                                            /*!< LLT Mask      0x00007FFF */
#define SDFM_SDFLT3CMPL1_LLT_Set(x) (((uint16_t) (x) << SDFM_SDFLT3CMPL1_LLT_Pos) & SDFM_SDFLT3CMPL1_LLT_Msk)   /*!< LLT Set Value            */
#define SDFM_SDFLT3CMPL1_LLT_Get(x) (((uint16_t) (x) & SDFM_SDFLT3CMPL1_LLT_Msk) >> SDFM_SDFLT3CMPL1_LLT_Pos)   /*!< LLT Get Value            */


/* SDCPARM3 bitfield */
#define SDFM_SDCPARM3_CEVT2SEL_Pos    (14U)                                                                                 /*!< CEVT2SEL Postion   14         */ 
#define SDFM_SDCPARM3_CEVT2SEL_Msk    (0x3U << SDFM_SDCPARM3_CEVT2SEL_Pos)                                             /*!< CEVT2SEL Mask      0x0000C000 */
#define SDFM_SDCPARM3_CEVT2SEL_Set(x) (((uint16_t) (x) << SDFM_SDCPARM3_CEVT2SEL_Pos) & SDFM_SDCPARM3_CEVT2SEL_Msk) /*!< CEVT2SEL Set Value            */
#define SDFM_SDCPARM3_CEVT2SEL_Get(x) (((uint16_t) (x) & SDFM_SDCPARM3_CEVT2SEL_Msk) >> SDFM_SDCPARM3_CEVT2SEL_Pos) /*!< CEVT2SEL Get Value            */


#define SDFM_SDCPARM3_CEN_Pos    (13U)                                                                                 /*!< CEN Postion   13         */ 
#define SDFM_SDCPARM3_CEN_Msk    (0x1U << SDFM_SDCPARM3_CEN_Pos)                                                  /*!< CEN Mask      0x00002000 */
#define SDFM_SDCPARM3_CEN_Set(x) (((uint16_t) (x) << SDFM_SDCPARM3_CEN_Pos) & SDFM_SDCPARM3_CEN_Msk)         /*!< CEN Set Value            */
#define SDFM_SDCPARM3_CEN_Get(x) (((uint16_t) (x) & SDFM_SDCPARM3_CEN_Msk) >> SDFM_SDCPARM3_CEN_Pos)         /*!< CEN Get Value            */


#define SDFM_SDCPARM3_CEVT1SEL_Pos    (11U)                                                                                 /*!< CEVT1SEL Postion   11         */ 
#define SDFM_SDCPARM3_CEVT1SEL_Msk    (0x3U << SDFM_SDCPARM3_CEVT1SEL_Pos)                                             /*!< CEVT1SEL Mask      0x00001800 */
#define SDFM_SDCPARM3_CEVT1SEL_Set(x) (((uint16_t) (x) << SDFM_SDCPARM3_CEVT1SEL_Pos) & SDFM_SDCPARM3_CEVT1SEL_Msk) /*!< CEVT1SEL Set Value            */
#define SDFM_SDCPARM3_CEVT1SEL_Get(x) (((uint16_t) (x) & SDFM_SDCPARM3_CEVT1SEL_Msk) >> SDFM_SDCPARM3_CEVT1SEL_Pos) /*!< CEVT1SEL Get Value            */


#define SDFM_SDCPARM3_HZEN_Pos    (10U)                                                                                 /*!< HZEN Postion   10         */ 
#define SDFM_SDCPARM3_HZEN_Msk    (0x1U << SDFM_SDCPARM3_HZEN_Pos)                                                 /*!< HZEN Mask      0x00000400 */
#define SDFM_SDCPARM3_HZEN_Set(x) (((uint16_t) (x) << SDFM_SDCPARM3_HZEN_Pos) & SDFM_SDCPARM3_HZEN_Msk)       /*!< HZEN Set Value            */
#define SDFM_SDCPARM3_HZEN_Get(x) (((uint16_t) (x) & SDFM_SDCPARM3_HZEN_Msk) >> SDFM_SDCPARM3_HZEN_Pos)       /*!< HZEN Get Value            */


#define SDFM_SDCPARM3_MFIE_Pos    (9U)                                                                                  /*!< MFIE Postion   9          */ 
#define SDFM_SDCPARM3_MFIE_Msk    (0x1U << SDFM_SDCPARM3_MFIE_Pos)                                                 /*!< MFIE Mask      0x00000200 */
#define SDFM_SDCPARM3_MFIE_Set(x) (((uint16_t) (x) << SDFM_SDCPARM3_MFIE_Pos) & SDFM_SDCPARM3_MFIE_Msk)       /*!< MFIE Set Value            */
#define SDFM_SDCPARM3_MFIE_Get(x) (((uint16_t) (x) & SDFM_SDCPARM3_MFIE_Msk) >> SDFM_SDCPARM3_MFIE_Pos)       /*!< MFIE Get Value            */


#define SDFM_SDCPARM3_CS1_CS0_Pos    (7U)                                                                                  /*!< CS1_CS0 Postion   7          */ 
#define SDFM_SDCPARM3_CS1_CS0_Msk    (0x3U << SDFM_SDCPARM3_CS1_CS0_Pos)                                              /*!< CS1_CS0 Mask      0x00000180 */
#define SDFM_SDCPARM3_CS1_CS0_Set(x) (((uint16_t) (x) << SDFM_SDCPARM3_CS1_CS0_Pos) & SDFM_SDCPARM3_CS1_CS0_Msk) /*!< CS1_CS0 Set Value            */
#define SDFM_SDCPARM3_CS1_CS0_Get(x) (((uint16_t) (x) & SDFM_SDCPARM3_CS1_CS0_Msk) >> SDFM_SDCPARM3_CS1_CS0_Pos) /*!< CS1_CS0 Get Value            */


#define SDFM_SDCPARM3_EN_CEVT2_Pos    (6U)                                                                                  /*!< EN_CEVT2 Postion   6          */ 
#define SDFM_SDCPARM3_EN_CEVT2_Msk    (0x1U << SDFM_SDCPARM3_EN_CEVT2_Pos)                                             /*!< EN_CEVT2 Mask      0x00000040 */
#define SDFM_SDCPARM3_EN_CEVT2_Set(x) (((uint16_t) (x) << SDFM_SDCPARM3_EN_CEVT2_Pos) & SDFM_SDCPARM3_EN_CEVT2_Msk) /*!< EN_CEVT2 Set Value            */
#define SDFM_SDCPARM3_EN_CEVT2_Get(x) (((uint16_t) (x) & SDFM_SDCPARM3_EN_CEVT2_Msk) >> SDFM_SDCPARM3_EN_CEVT2_Pos) /*!< EN_CEVT2 Get Value            */


#define SDFM_SDCPARM3_EN_CEVT1_Pos    (5U)                                                                                  /*!< EN_CEVT1 Postion   5          */ 
#define SDFM_SDCPARM3_EN_CEVT1_Msk    (0x1U << SDFM_SDCPARM3_EN_CEVT1_Pos)                                             /*!< EN_CEVT1 Mask      0x00000020 */
#define SDFM_SDCPARM3_EN_CEVT1_Set(x) (((uint16_t) (x) << SDFM_SDCPARM3_EN_CEVT1_Pos) & SDFM_SDCPARM3_EN_CEVT1_Msk) /*!< EN_CEVT1 Set Value            */
#define SDFM_SDCPARM3_EN_CEVT1_Get(x) (((uint16_t) (x) & SDFM_SDCPARM3_EN_CEVT1_Msk) >> SDFM_SDCPARM3_EN_CEVT1_Pos) /*!< EN_CEVT1 Get Value            */


#define SDFM_SDCPARM3_COSR_Pos    (0U)                                                                                  /*!< COSR Postion   0          */ 
#define SDFM_SDCPARM3_COSR_Msk    (0x1fU << SDFM_SDCPARM3_COSR_Pos)                                                /*!< COSR Mask      0x0000001F */
#define SDFM_SDCPARM3_COSR_Set(x) (((uint16_t) (x) << SDFM_SDCPARM3_COSR_Pos) & SDFM_SDCPARM3_COSR_Msk)       /*!< COSR Set Value            */
#define SDFM_SDCPARM3_COSR_Get(x) (((uint16_t) (x) & SDFM_SDCPARM3_COSR_Msk) >> SDFM_SDCPARM3_COSR_Pos)       /*!< COSR Get Value            */


/* SDDATA3 bitfield */
#define SDFM_SDDATA3_DATA32HI_Pos    (16U)                                                                                 /*!< DATA32HI Postion   16         */ 
#define SDFM_SDDATA3_DATA32HI_Msk    (0xffffU << SDFM_SDDATA3_DATA32HI_Pos)                                           /*!< DATA32HI Mask      0xFFFF0000 */
#define SDFM_SDDATA3_DATA32HI_Set(x) (((uint32_t) (x) << SDFM_SDDATA3_DATA32HI_Pos) & SDFM_SDDATA3_DATA32HI_Msk) /*!< DATA32HI Set Value            */
#define SDFM_SDDATA3_DATA32HI_Get(x) (((uint32_t) (x) & SDFM_SDDATA3_DATA32HI_Msk) >> SDFM_SDDATA3_DATA32HI_Pos) /*!< DATA32HI Get Value            */


#define SDFM_SDDATA3_DATA16_Pos    (0U)                                                                                  /*!< DATA16 Postion   0          */ 
#define SDFM_SDDATA3_DATA16_Msk    (0xffffU << SDFM_SDDATA3_DATA16_Pos)                                             /*!< DATA16 Mask      0x0000FFFF */
#define SDFM_SDDATA3_DATA16_Set(x) (((uint32_t) (x) << SDFM_SDDATA3_DATA16_Pos) & SDFM_SDDATA3_DATA16_Msk)     /*!< DATA16 Set Value            */
#define SDFM_SDDATA3_DATA16_Get(x) (((uint32_t) (x) & SDFM_SDDATA3_DATA16_Msk) >> SDFM_SDDATA3_DATA16_Pos)     /*!< DATA16 Get Value            */


/* SDDATFIFO3 bitfield */
#define SDFM_SDDATFIFO3_DATA32HI_Pos    (16U)                                                                                 /*!< DATA32HI Postion   16         */ 
#define SDFM_SDDATFIFO3_DATA32HI_Msk    (0xffffU << SDFM_SDDATFIFO3_DATA32HI_Pos)                                        /*!< DATA32HI Mask      0xFFFF0000 */
#define SDFM_SDDATFIFO3_DATA32HI_Set(x) (((uint32_t) (x) << SDFM_SDDATFIFO3_DATA32HI_Pos) & SDFM_SDDATFIFO3_DATA32HI_Msk) /*!< DATA32HI Set Value            */
#define SDFM_SDDATFIFO3_DATA32HI_Get(x) (((uint32_t) (x) & SDFM_SDDATFIFO3_DATA32HI_Msk) >> SDFM_SDDATFIFO3_DATA32HI_Pos) /*!< DATA32HI Get Value            */


#define SDFM_SDDATFIFO3_DATA16_Pos    (0U)                                                                                  /*!< DATA16 Postion   0          */ 
#define SDFM_SDDATFIFO3_DATA16_Msk    (0xffffU << SDFM_SDDATFIFO3_DATA16_Pos)                                          /*!< DATA16 Mask      0x0000FFFF */
#define SDFM_SDDATFIFO3_DATA16_Set(x) (((uint32_t) (x) << SDFM_SDDATFIFO3_DATA16_Pos) & SDFM_SDDATFIFO3_DATA16_Msk) /*!< DATA16 Set Value            */
#define SDFM_SDDATFIFO3_DATA16_Get(x) (((uint32_t) (x) & SDFM_SDDATFIFO3_DATA16_Msk) >> SDFM_SDDATFIFO3_DATA16_Pos) /*!< DATA16 Get Value            */


/* SDCDATA3 bitfield */
#define SDFM_SDCDATA3_DATA16_Pos    (0U)                                                                                  /*!< DATA16 Postion   0          */ 
#define SDFM_SDCDATA3_DATA16_Msk    (0xffffU << SDFM_SDCDATA3_DATA16_Pos)                                            /*!< DATA16 Mask      0x0000FFFF */
#define SDFM_SDCDATA3_DATA16_Set(x) (((uint16_t) (x) << SDFM_SDCDATA3_DATA16_Pos) & SDFM_SDCDATA3_DATA16_Msk)   /*!< DATA16 Set Value            */
#define SDFM_SDCDATA3_DATA16_Get(x) (((uint16_t) (x) & SDFM_SDCDATA3_DATA16_Msk) >> SDFM_SDCDATA3_DATA16_Pos)   /*!< DATA16 Get Value            */


/* SDFLT3CMPH2 bitfield */
#define SDFM_SDFLT3CMPH2_HLT2_Pos    (0U)                                                                                  /*!< HLT2 Postion   0          */ 
#define SDFM_SDFLT3CMPH2_HLT2_Msk    (0x7fffU << SDFM_SDFLT3CMPH2_HLT2_Pos)                                           /*!< HLT2 Mask      0x00007FFF */
#define SDFM_SDFLT3CMPH2_HLT2_Set(x) (((uint16_t) (x) << SDFM_SDFLT3CMPH2_HLT2_Pos) & SDFM_SDFLT3CMPH2_HLT2_Msk) /*!< HLT2 Set Value            */
#define SDFM_SDFLT3CMPH2_HLT2_Get(x) (((uint16_t) (x) & SDFM_SDFLT3CMPH2_HLT2_Msk) >> SDFM_SDFLT3CMPH2_HLT2_Pos) /*!< HLT2 Get Value            */


/* SDFLT3CMPHZ bitfield */
#define SDFM_SDFLT3CMPHZ_HLTZ_Pos    (0U)                                                                                  /*!< HLTZ Postion   0          */ 
#define SDFM_SDFLT3CMPHZ_HLTZ_Msk    (0x7fffU << SDFM_SDFLT3CMPHZ_HLTZ_Pos)                                           /*!< HLTZ Mask      0x00007FFF */
#define SDFM_SDFLT3CMPHZ_HLTZ_Set(x) (((uint16_t) (x) << SDFM_SDFLT3CMPHZ_HLTZ_Pos) & SDFM_SDFLT3CMPHZ_HLTZ_Msk) /*!< HLTZ Set Value            */
#define SDFM_SDFLT3CMPHZ_HLTZ_Get(x) (((uint16_t) (x) & SDFM_SDFLT3CMPHZ_HLTZ_Msk) >> SDFM_SDFLT3CMPHZ_HLTZ_Pos) /*!< HLTZ Get Value            */


/* SDFIFOCTL3 bitfield */
#define SDFM_SDFIFOCTL3_OVFIEN_Pos    (15U)                                                                                 /*!< OVFIEN Postion   15         */ 
#define SDFM_SDFIFOCTL3_OVFIEN_Msk    (0x1U << SDFM_SDFIFOCTL3_OVFIEN_Pos)                                             /*!< OVFIEN Mask      0x00008000 */
#define SDFM_SDFIFOCTL3_OVFIEN_Set(x) (((uint16_t) (x) << SDFM_SDFIFOCTL3_OVFIEN_Pos) & SDFM_SDFIFOCTL3_OVFIEN_Msk) /*!< OVFIEN Set Value            */
#define SDFM_SDFIFOCTL3_OVFIEN_Get(x) (((uint16_t) (x) & SDFM_SDFIFOCTL3_OVFIEN_Msk) >> SDFM_SDFIFOCTL3_OVFIEN_Pos) /*!< OVFIEN Get Value            */


#define SDFM_SDFIFOCTL3_DRINTSEL_Pos    (14U)                                                                                 /*!< DRINTSEL Postion   14         */ 
#define SDFM_SDFIFOCTL3_DRINTSEL_Msk    (0x1U << SDFM_SDFIFOCTL3_DRINTSEL_Pos)                                           /*!< DRINTSEL Mask      0x00004000 */
#define SDFM_SDFIFOCTL3_DRINTSEL_Set(x) (((uint16_t) (x) << SDFM_SDFIFOCTL3_DRINTSEL_Pos) & SDFM_SDFIFOCTL3_DRINTSEL_Msk) /*!< DRINTSEL Set Value            */
#define SDFM_SDFIFOCTL3_DRINTSEL_Get(x) (((uint16_t) (x) & SDFM_SDFIFOCTL3_DRINTSEL_Msk) >> SDFM_SDFIFOCTL3_DRINTSEL_Pos) /*!< DRINTSEL Get Value            */


#define SDFM_SDFIFOCTL3_FFEN_Pos    (13U)                                                                                 /*!< FFEN Postion   13         */ 
#define SDFM_SDFIFOCTL3_FFEN_Msk    (0x1U << SDFM_SDFIFOCTL3_FFEN_Pos)                                               /*!< FFEN Mask      0x00002000 */
#define SDFM_SDFIFOCTL3_FFEN_Set(x) (((uint16_t) (x) << SDFM_SDFIFOCTL3_FFEN_Pos) & SDFM_SDFIFOCTL3_FFEN_Msk)   /*!< FFEN Set Value            */
#define SDFM_SDFIFOCTL3_FFEN_Get(x) (((uint16_t) (x) & SDFM_SDFIFOCTL3_FFEN_Msk) >> SDFM_SDFIFOCTL3_FFEN_Pos)   /*!< FFEN Get Value            */


#define SDFM_SDFIFOCTL3_FFIEN_Pos    (12U)                                                                                 /*!< FFIEN Postion   12         */ 
#define SDFM_SDFIFOCTL3_FFIEN_Msk    (0x1U << SDFM_SDFIFOCTL3_FFIEN_Pos)                                              /*!< FFIEN Mask      0x00001000 */
#define SDFM_SDFIFOCTL3_FFIEN_Set(x) (((uint16_t) (x) << SDFM_SDFIFOCTL3_FFIEN_Pos) & SDFM_SDFIFOCTL3_FFIEN_Msk) /*!< FFIEN Set Value            */
#define SDFM_SDFIFOCTL3_FFIEN_Get(x) (((uint16_t) (x) & SDFM_SDFIFOCTL3_FFIEN_Msk) >> SDFM_SDFIFOCTL3_FFIEN_Pos) /*!< FFIEN Get Value            */


#define SDFM_SDFIFOCTL3_UDFIEN_Pos    (11U)                                                                                 /*!< UDFIEN Postion   11         */ 
#define SDFM_SDFIFOCTL3_UDFIEN_Msk    (0x1U << SDFM_SDFIFOCTL3_UDFIEN_Pos)                                             /*!< UDFIEN Mask      0x00000800 */
#define SDFM_SDFIFOCTL3_UDFIEN_Set(x) (((uint16_t) (x) << SDFM_SDFIFOCTL3_UDFIEN_Pos) & SDFM_SDFIFOCTL3_UDFIEN_Msk) /*!< UDFIEN Set Value            */
#define SDFM_SDFIFOCTL3_UDFIEN_Get(x) (((uint16_t) (x) & SDFM_SDFIFOCTL3_UDFIEN_Msk) >> SDFM_SDFIFOCTL3_UDFIEN_Pos) /*!< UDFIEN Get Value            */


#define SDFM_SDFIFOCTL3_SDFFST_Pos    (6U)                                                                                  /*!< SDFFST Postion   6          */ 
#define SDFM_SDFIFOCTL3_SDFFST_Msk    (0x1fU << SDFM_SDFIFOCTL3_SDFFST_Pos)                                            /*!< SDFFST Mask      0x000007C0 */
#define SDFM_SDFIFOCTL3_SDFFST_Set(x) (((uint16_t) (x) << SDFM_SDFIFOCTL3_SDFFST_Pos) & SDFM_SDFIFOCTL3_SDFFST_Msk) /*!< SDFFST Set Value            */
#define SDFM_SDFIFOCTL3_SDFFST_Get(x) (((uint16_t) (x) & SDFM_SDFIFOCTL3_SDFFST_Msk) >> SDFM_SDFIFOCTL3_SDFFST_Pos) /*!< SDFFST Get Value            */


#define SDFM_SDFIFOCTL3_DRDMASEL_Pos    (5U)                                                                                  /*!< DRDMASEL Postion   5          */ 
#define SDFM_SDFIFOCTL3_DRDMASEL_Msk    (0x1U << SDFM_SDFIFOCTL3_DRDMASEL_Pos)                                           /*!< DRDMASEL Mask      0x00000020 */
#define SDFM_SDFIFOCTL3_DRDMASEL_Set(x) (((uint16_t) (x) << SDFM_SDFIFOCTL3_DRDMASEL_Pos) & SDFM_SDFIFOCTL3_DRDMASEL_Msk) /*!< DRDMASEL Set Value            */
#define SDFM_SDFIFOCTL3_DRDMASEL_Get(x) (((uint16_t) (x) & SDFM_SDFIFOCTL3_DRDMASEL_Msk) >> SDFM_SDFIFOCTL3_DRDMASEL_Pos) /*!< DRDMASEL Get Value            */


#define SDFM_SDFIFOCTL3_SDFFIL_Pos    (0U)                                                                                  /*!< SDFFIL Postion   0          */ 
#define SDFM_SDFIFOCTL3_SDFFIL_Msk    (0x1fU << SDFM_SDFIFOCTL3_SDFFIL_Pos)                                            /*!< SDFFIL Mask      0x0000001F */
#define SDFM_SDFIFOCTL3_SDFFIL_Set(x) (((uint16_t) (x) << SDFM_SDFIFOCTL3_SDFFIL_Pos) & SDFM_SDFIFOCTL3_SDFFIL_Msk) /*!< SDFFIL Set Value            */
#define SDFM_SDFIFOCTL3_SDFFIL_Get(x) (((uint16_t) (x) & SDFM_SDFIFOCTL3_SDFFIL_Msk) >> SDFM_SDFIFOCTL3_SDFFIL_Pos) /*!< SDFFIL Get Value            */


/* SDSYNC3 bitfield */
#define SDFM_SDSYNC3_WTSCLREN_Pos    (10U)                                                                                 /*!< WTSCLREN Postion   10         */ 
#define SDFM_SDSYNC3_WTSCLREN_Msk    (0x1U << SDFM_SDSYNC3_WTSCLREN_Pos)                                              /*!< WTSCLREN Mask      0x00000400 */
#define SDFM_SDSYNC3_WTSCLREN_Set(x) (((uint16_t) (x) << SDFM_SDSYNC3_WTSCLREN_Pos) & SDFM_SDSYNC3_WTSCLREN_Msk) /*!< WTSCLREN Set Value            */
#define SDFM_SDSYNC3_WTSCLREN_Get(x) (((uint16_t) (x) & SDFM_SDSYNC3_WTSCLREN_Msk) >> SDFM_SDSYNC3_WTSCLREN_Pos) /*!< WTSCLREN Get Value            */


#define SDFM_SDSYNC3_FFSYNCCLREN_Pos    (9U)                                                                                  /*!< FFSYNCCLREN Postion   9          */ 
#define SDFM_SDSYNC3_FFSYNCCLREN_Msk    (0x1U << SDFM_SDSYNC3_FFSYNCCLREN_Pos)                                           /*!< FFSYNCCLREN Mask      0x00000200 */
#define SDFM_SDSYNC3_FFSYNCCLREN_Set(x) (((uint16_t) (x) << SDFM_SDSYNC3_FFSYNCCLREN_Pos) & SDFM_SDSYNC3_FFSYNCCLREN_Msk) /*!< FFSYNCCLREN Set Value            */
#define SDFM_SDSYNC3_FFSYNCCLREN_Get(x) (((uint16_t) (x) & SDFM_SDSYNC3_FFSYNCCLREN_Msk) >> SDFM_SDSYNC3_FFSYNCCLREN_Pos) /*!< FFSYNCCLREN Get Value            */


#define SDFM_SDSYNC3_WTSYNCLR_Pos    (8U)                                                                                  /*!< WTSYNCLR Postion   8          */ 
#define SDFM_SDSYNC3_WTSYNCLR_Msk    (0x1U << SDFM_SDSYNC3_WTSYNCLR_Pos)                                              /*!< WTSYNCLR Mask      0x00000100 */
#define SDFM_SDSYNC3_WTSYNCLR_Set(x) (((uint16_t) (x) << SDFM_SDSYNC3_WTSYNCLR_Pos) & SDFM_SDSYNC3_WTSYNCLR_Msk) /*!< WTSYNCLR Set Value            */
#define SDFM_SDSYNC3_WTSYNCLR_Get(x) (((uint16_t) (x) & SDFM_SDSYNC3_WTSYNCLR_Msk) >> SDFM_SDSYNC3_WTSYNCLR_Pos) /*!< WTSYNCLR Get Value            */


#define SDFM_SDSYNC3_WTSYNFLG_Pos    (7U)                                                                                  /*!< WTSYNFLG Postion   7          */ 
#define SDFM_SDSYNC3_WTSYNFLG_Msk    (0x1U << SDFM_SDSYNC3_WTSYNFLG_Pos)                                              /*!< WTSYNFLG Mask      0x00000080 */
#define SDFM_SDSYNC3_WTSYNFLG_Set(x) (((uint16_t) (x) << SDFM_SDSYNC3_WTSYNFLG_Pos) & SDFM_SDSYNC3_WTSYNFLG_Msk) /*!< WTSYNFLG Set Value            */
#define SDFM_SDSYNC3_WTSYNFLG_Get(x) (((uint16_t) (x) & SDFM_SDSYNC3_WTSYNFLG_Msk) >> SDFM_SDSYNC3_WTSYNFLG_Pos) /*!< WTSYNFLG Get Value            */


#define SDFM_SDSYNC3_WTSYNCEN_Pos    (6U)                                                                                  /*!< WTSYNCEN Postion   6          */ 
#define SDFM_SDSYNC3_WTSYNCEN_Msk    (0x1U << SDFM_SDSYNC3_WTSYNCEN_Pos)                                              /*!< WTSYNCEN Mask      0x00000040 */
#define SDFM_SDSYNC3_WTSYNCEN_Set(x) (((uint16_t) (x) << SDFM_SDSYNC3_WTSYNCEN_Pos) & SDFM_SDSYNC3_WTSYNCEN_Msk) /*!< WTSYNCEN Set Value            */
#define SDFM_SDSYNC3_WTSYNCEN_Get(x) (((uint16_t) (x) & SDFM_SDSYNC3_WTSYNCEN_Msk) >> SDFM_SDSYNC3_WTSYNCEN_Pos) /*!< WTSYNCEN Get Value            */


#define SDFM_SDSYNC3_SYNCSEL_Pos    (0U)                                                                                  /*!< SYNCSEL Postion   0          */ 
#define SDFM_SDSYNC3_SYNCSEL_Msk    (0x3fU << SDFM_SDSYNC3_SYNCSEL_Pos)                                              /*!< SYNCSEL Mask      0x0000003F */
#define SDFM_SDSYNC3_SYNCSEL_Set(x) (((uint16_t) (x) << SDFM_SDSYNC3_SYNCSEL_Pos) & SDFM_SDSYNC3_SYNCSEL_Msk)   /*!< SYNCSEL Set Value            */
#define SDFM_SDSYNC3_SYNCSEL_Get(x) (((uint16_t) (x) & SDFM_SDSYNC3_SYNCSEL_Msk) >> SDFM_SDSYNC3_SYNCSEL_Pos)   /*!< SYNCSEL Get Value            */


/* SDFLT3CMPL2 bitfield */
#define SDFM_SDFLT3CMPL2_LLT2_Pos    (0U)                                                                                  /*!< LLT2 Postion   0          */ 
#define SDFM_SDFLT3CMPL2_LLT2_Msk    (0x7fffU << SDFM_SDFLT3CMPL2_LLT2_Pos)                                           /*!< LLT2 Mask      0x00007FFF */
#define SDFM_SDFLT3CMPL2_LLT2_Set(x) (((uint16_t) (x) << SDFM_SDFLT3CMPL2_LLT2_Pos) & SDFM_SDFLT3CMPL2_LLT2_Msk) /*!< LLT2 Set Value            */
#define SDFM_SDFLT3CMPL2_LLT2_Get(x) (((uint16_t) (x) & SDFM_SDFLT3CMPL2_LLT2_Msk) >> SDFM_SDFLT3CMPL2_LLT2_Pos) /*!< LLT2 Get Value            */


/* SDCTLPARM4 bitfield */
#define SDFM_SDCTLPARM4_MOD_Pos    (0U)                                                                                  /*!< MOD Postion   0          */ 
#define SDFM_SDCTLPARM4_MOD_Msk    (0x3U << SDFM_SDCTLPARM4_MOD_Pos)                                                /*!< MOD Mask      0x00000003 */
#define SDFM_SDCTLPARM4_MOD_Set(x) (((uint16_t) (x) << SDFM_SDCTLPARM4_MOD_Pos) & SDFM_SDCTLPARM4_MOD_Msk)     /*!< MOD Set Value            */
#define SDFM_SDCTLPARM4_MOD_Get(x) (((uint16_t) (x) & SDFM_SDCTLPARM4_MOD_Msk) >> SDFM_SDCTLPARM4_MOD_Pos)     /*!< MOD Get Value            */


/* SDDFPARM4 bitfield */
#define SDFM_SDDFPARM4_SDSYNCEN_Pos    (12U)                                                                                 /*!< SDSYNCEN Postion   12         */ 
#define SDFM_SDDFPARM4_SDSYNCEN_Msk    (0x1U << SDFM_SDDFPARM4_SDSYNCEN_Pos)                                            /*!< SDSYNCEN Mask      0x00001000 */
#define SDFM_SDDFPARM4_SDSYNCEN_Set(x) (((uint16_t) (x) << SDFM_SDDFPARM4_SDSYNCEN_Pos) & SDFM_SDDFPARM4_SDSYNCEN_Msk) /*!< SDSYNCEN Set Value            */
#define SDFM_SDDFPARM4_SDSYNCEN_Get(x) (((uint16_t) (x) & SDFM_SDDFPARM4_SDSYNCEN_Msk) >> SDFM_SDDFPARM4_SDSYNCEN_Pos) /*!< SDSYNCEN Get Value            */


#define SDFM_SDDFPARM4_SST_Pos    (10U)                                                                                 /*!< SST Postion   10         */ 
#define SDFM_SDDFPARM4_SST_Msk    (0x3U << SDFM_SDDFPARM4_SST_Pos)                                                 /*!< SST Mask      0x00000C00 */
#define SDFM_SDDFPARM4_SST_Set(x) (((uint16_t) (x) << SDFM_SDDFPARM4_SST_Pos) & SDFM_SDDFPARM4_SST_Msk)       /*!< SST Set Value            */
#define SDFM_SDDFPARM4_SST_Get(x) (((uint16_t) (x) & SDFM_SDDFPARM4_SST_Msk) >> SDFM_SDDFPARM4_SST_Pos)       /*!< SST Get Value            */


#define SDFM_SDDFPARM4_AE_Pos    (9U)                                                                                  /*!< AE Postion   9          */ 
#define SDFM_SDDFPARM4_AE_Msk    (0x1U << SDFM_SDDFPARM4_AE_Pos)                                                  /*!< AE Mask      0x00000200 */
#define SDFM_SDDFPARM4_AE_Set(x) (((uint16_t) (x) << SDFM_SDDFPARM4_AE_Pos) & SDFM_SDDFPARM4_AE_Msk)         /*!< AE Set Value            */
#define SDFM_SDDFPARM4_AE_Get(x) (((uint16_t) (x) & SDFM_SDDFPARM4_AE_Msk) >> SDFM_SDDFPARM4_AE_Pos)         /*!< AE Get Value            */


#define SDFM_SDDFPARM4_FEN_Pos    (8U)                                                                                  /*!< FEN Postion   8          */ 
#define SDFM_SDDFPARM4_FEN_Msk    (0x1U << SDFM_SDDFPARM4_FEN_Pos)                                                 /*!< FEN Mask      0x00000100 */
#define SDFM_SDDFPARM4_FEN_Set(x) (((uint16_t) (x) << SDFM_SDDFPARM4_FEN_Pos) & SDFM_SDDFPARM4_FEN_Msk)       /*!< FEN Set Value            */
#define SDFM_SDDFPARM4_FEN_Get(x) (((uint16_t) (x) & SDFM_SDDFPARM4_FEN_Msk) >> SDFM_SDDFPARM4_FEN_Pos)       /*!< FEN Get Value            */


#define SDFM_SDDFPARM4_DOSR_Pos    (0U)                                                                                  /*!< DOSR Postion   0          */ 
#define SDFM_SDDFPARM4_DOSR_Msk    (0xffU << SDFM_SDDFPARM4_DOSR_Pos)                                               /*!< DOSR Mask      0x000000FF */
#define SDFM_SDDFPARM4_DOSR_Set(x) (((uint16_t) (x) << SDFM_SDDFPARM4_DOSR_Pos) & SDFM_SDDFPARM4_DOSR_Msk)     /*!< DOSR Set Value            */
#define SDFM_SDDFPARM4_DOSR_Get(x) (((uint16_t) (x) & SDFM_SDDFPARM4_DOSR_Msk) >> SDFM_SDDFPARM4_DOSR_Pos)     /*!< DOSR Get Value            */


/* SDDPARM4 bitfield */
#define SDFM_SDDPARM4_SH_Pos    (11U)                                                                                 /*!< SH Postion   11         */ 
#define SDFM_SDDPARM4_SH_Msk    (0x1fU << SDFM_SDDPARM4_SH_Pos)                                                  /*!< SH Mask      0x0000F800 */
#define SDFM_SDDPARM4_SH_Set(x) (((uint16_t) (x) << SDFM_SDDPARM4_SH_Pos) & SDFM_SDDPARM4_SH_Msk)           /*!< SH Set Value            */
#define SDFM_SDDPARM4_SH_Get(x) (((uint16_t) (x) & SDFM_SDDPARM4_SH_Msk) >> SDFM_SDDPARM4_SH_Pos)           /*!< SH Get Value            */


#define SDFM_SDDPARM4_DR_Pos    (10U)                                                                                 /*!< DR Postion   10         */ 
#define SDFM_SDDPARM4_DR_Msk    (0x1U << SDFM_SDDPARM4_DR_Pos)                                                   /*!< DR Mask      0x00000400 */
#define SDFM_SDDPARM4_DR_Set(x) (((uint16_t) (x) << SDFM_SDDPARM4_DR_Pos) & SDFM_SDDPARM4_DR_Msk)           /*!< DR Set Value            */
#define SDFM_SDDPARM4_DR_Get(x) (((uint16_t) (x) & SDFM_SDDPARM4_DR_Msk) >> SDFM_SDDPARM4_DR_Pos)           /*!< DR Get Value            */


/* SDFLT4CMPH1 bitfield */
#define SDFM_SDFLT4CMPH1_HLT_Pos    (0U)                                                                                  /*!< HLT Postion   0          */ 
#define SDFM_SDFLT4CMPH1_HLT_Msk    (0x7fffU << SDFM_SDFLT4CMPH1_HLT_Pos)                                            /*!< HLT Mask      0x00007FFF */
#define SDFM_SDFLT4CMPH1_HLT_Set(x) (((uint16_t) (x) << SDFM_SDFLT4CMPH1_HLT_Pos) & SDFM_SDFLT4CMPH1_HLT_Msk)   /*!< HLT Set Value            */
#define SDFM_SDFLT4CMPH1_HLT_Get(x) (((uint16_t) (x) & SDFM_SDFLT4CMPH1_HLT_Msk) >> SDFM_SDFLT4CMPH1_HLT_Pos)   /*!< HLT Get Value            */


/* SDFLT4CMPL1 bitfield */
#define SDFM_SDFLT4CMPL1_LLT_Pos    (0U)                                                                                  /*!< LLT Postion   0          */ 
#define SDFM_SDFLT4CMPL1_LLT_Msk    (0x7fffU << SDFM_SDFLT4CMPL1_LLT_Pos)                                            /*!< LLT Mask      0x00007FFF */
#define SDFM_SDFLT4CMPL1_LLT_Set(x) (((uint16_t) (x) << SDFM_SDFLT4CMPL1_LLT_Pos) & SDFM_SDFLT4CMPL1_LLT_Msk)   /*!< LLT Set Value            */
#define SDFM_SDFLT4CMPL1_LLT_Get(x) (((uint16_t) (x) & SDFM_SDFLT4CMPL1_LLT_Msk) >> SDFM_SDFLT4CMPL1_LLT_Pos)   /*!< LLT Get Value            */


/* SDCPARM4 bitfield */
#define SDFM_SDCPARM4_CEVT2SEL_Pos    (14U)                                                                                 /*!< CEVT2SEL Postion   14         */ 
#define SDFM_SDCPARM4_CEVT2SEL_Msk    (0x3U << SDFM_SDCPARM4_CEVT2SEL_Pos)                                             /*!< CEVT2SEL Mask      0x0000C000 */
#define SDFM_SDCPARM4_CEVT2SEL_Set(x) (((uint16_t) (x) << SDFM_SDCPARM4_CEVT2SEL_Pos) & SDFM_SDCPARM4_CEVT2SEL_Msk) /*!< CEVT2SEL Set Value            */
#define SDFM_SDCPARM4_CEVT2SEL_Get(x) (((uint16_t) (x) & SDFM_SDCPARM4_CEVT2SEL_Msk) >> SDFM_SDCPARM4_CEVT2SEL_Pos) /*!< CEVT2SEL Get Value            */


#define SDFM_SDCPARM4_CEN_Pos    (13U)                                                                                 /*!< CEN Postion   13         */ 
#define SDFM_SDCPARM4_CEN_Msk    (0x1U << SDFM_SDCPARM4_CEN_Pos)                                                  /*!< CEN Mask      0x00002000 */
#define SDFM_SDCPARM4_CEN_Set(x) (((uint16_t) (x) << SDFM_SDCPARM4_CEN_Pos) & SDFM_SDCPARM4_CEN_Msk)         /*!< CEN Set Value            */
#define SDFM_SDCPARM4_CEN_Get(x) (((uint16_t) (x) & SDFM_SDCPARM4_CEN_Msk) >> SDFM_SDCPARM4_CEN_Pos)         /*!< CEN Get Value            */


#define SDFM_SDCPARM4_CEVT1SEL_Pos    (11U)                                                                                 /*!< CEVT1SEL Postion   11         */ 
#define SDFM_SDCPARM4_CEVT1SEL_Msk    (0x3U << SDFM_SDCPARM4_CEVT1SEL_Pos)                                             /*!< CEVT1SEL Mask      0x00001800 */
#define SDFM_SDCPARM4_CEVT1SEL_Set(x) (((uint16_t) (x) << SDFM_SDCPARM4_CEVT1SEL_Pos) & SDFM_SDCPARM4_CEVT1SEL_Msk) /*!< CEVT1SEL Set Value            */
#define SDFM_SDCPARM4_CEVT1SEL_Get(x) (((uint16_t) (x) & SDFM_SDCPARM4_CEVT1SEL_Msk) >> SDFM_SDCPARM4_CEVT1SEL_Pos) /*!< CEVT1SEL Get Value            */


#define SDFM_SDCPARM4_HZEN_Pos    (10U)                                                                                 /*!< HZEN Postion   10         */ 
#define SDFM_SDCPARM4_HZEN_Msk    (0x1U << SDFM_SDCPARM4_HZEN_Pos)                                                 /*!< HZEN Mask      0x00000400 */
#define SDFM_SDCPARM4_HZEN_Set(x) (((uint16_t) (x) << SDFM_SDCPARM4_HZEN_Pos) & SDFM_SDCPARM4_HZEN_Msk)       /*!< HZEN Set Value            */
#define SDFM_SDCPARM4_HZEN_Get(x) (((uint16_t) (x) & SDFM_SDCPARM4_HZEN_Msk) >> SDFM_SDCPARM4_HZEN_Pos)       /*!< HZEN Get Value            */


#define SDFM_SDCPARM4_MFIE_Pos    (9U)                                                                                  /*!< MFIE Postion   9          */ 
#define SDFM_SDCPARM4_MFIE_Msk    (0x1U << SDFM_SDCPARM4_MFIE_Pos)                                                 /*!< MFIE Mask      0x00000200 */
#define SDFM_SDCPARM4_MFIE_Set(x) (((uint16_t) (x) << SDFM_SDCPARM4_MFIE_Pos) & SDFM_SDCPARM4_MFIE_Msk)       /*!< MFIE Set Value            */
#define SDFM_SDCPARM4_MFIE_Get(x) (((uint16_t) (x) & SDFM_SDCPARM4_MFIE_Msk) >> SDFM_SDCPARM4_MFIE_Pos)       /*!< MFIE Get Value            */


#define SDFM_SDCPARM4_CS1_CS0_Pos    (7U)                                                                                  /*!< CS1_CS0 Postion   7          */ 
#define SDFM_SDCPARM4_CS1_CS0_Msk    (0x3U << SDFM_SDCPARM4_CS1_CS0_Pos)                                              /*!< CS1_CS0 Mask      0x00000180 */
#define SDFM_SDCPARM4_CS1_CS0_Set(x) (((uint16_t) (x) << SDFM_SDCPARM4_CS1_CS0_Pos) & SDFM_SDCPARM4_CS1_CS0_Msk) /*!< CS1_CS0 Set Value            */
#define SDFM_SDCPARM4_CS1_CS0_Get(x) (((uint16_t) (x) & SDFM_SDCPARM4_CS1_CS0_Msk) >> SDFM_SDCPARM4_CS1_CS0_Pos) /*!< CS1_CS0 Get Value            */


#define SDFM_SDCPARM4_EN_CEVT2_Pos    (6U)                                                                                  /*!< EN_CEVT2 Postion   6          */ 
#define SDFM_SDCPARM4_EN_CEVT2_Msk    (0x1U << SDFM_SDCPARM4_EN_CEVT2_Pos)                                             /*!< EN_CEVT2 Mask      0x00000040 */
#define SDFM_SDCPARM4_EN_CEVT2_Set(x) (((uint16_t) (x) << SDFM_SDCPARM4_EN_CEVT2_Pos) & SDFM_SDCPARM4_EN_CEVT2_Msk) /*!< EN_CEVT2 Set Value            */
#define SDFM_SDCPARM4_EN_CEVT2_Get(x) (((uint16_t) (x) & SDFM_SDCPARM4_EN_CEVT2_Msk) >> SDFM_SDCPARM4_EN_CEVT2_Pos) /*!< EN_CEVT2 Get Value            */


#define SDFM_SDCPARM4_EN_CEVT1_Pos    (5U)                                                                                  /*!< EN_CEVT1 Postion   5          */ 
#define SDFM_SDCPARM4_EN_CEVT1_Msk    (0x1U << SDFM_SDCPARM4_EN_CEVT1_Pos)                                             /*!< EN_CEVT1 Mask      0x00000020 */
#define SDFM_SDCPARM4_EN_CEVT1_Set(x) (((uint16_t) (x) << SDFM_SDCPARM4_EN_CEVT1_Pos) & SDFM_SDCPARM4_EN_CEVT1_Msk) /*!< EN_CEVT1 Set Value            */
#define SDFM_SDCPARM4_EN_CEVT1_Get(x) (((uint16_t) (x) & SDFM_SDCPARM4_EN_CEVT1_Msk) >> SDFM_SDCPARM4_EN_CEVT1_Pos) /*!< EN_CEVT1 Get Value            */


#define SDFM_SDCPARM4_COSR_Pos    (0U)                                                                                  /*!< COSR Postion   0          */ 
#define SDFM_SDCPARM4_COSR_Msk    (0x1fU << SDFM_SDCPARM4_COSR_Pos)                                                /*!< COSR Mask      0x0000001F */
#define SDFM_SDCPARM4_COSR_Set(x) (((uint16_t) (x) << SDFM_SDCPARM4_COSR_Pos) & SDFM_SDCPARM4_COSR_Msk)       /*!< COSR Set Value            */
#define SDFM_SDCPARM4_COSR_Get(x) (((uint16_t) (x) & SDFM_SDCPARM4_COSR_Msk) >> SDFM_SDCPARM4_COSR_Pos)       /*!< COSR Get Value            */


/* SDDATA4 bitfield */
#define SDFM_SDDATA4_DATA32HI_Pos    (16U)                                                                                 /*!< DATA32HI Postion   16         */ 
#define SDFM_SDDATA4_DATA32HI_Msk    (0xffffU << SDFM_SDDATA4_DATA32HI_Pos)                                           /*!< DATA32HI Mask      0xFFFF0000 */
#define SDFM_SDDATA4_DATA32HI_Set(x) (((uint32_t) (x) << SDFM_SDDATA4_DATA32HI_Pos) & SDFM_SDDATA4_DATA32HI_Msk) /*!< DATA32HI Set Value            */
#define SDFM_SDDATA4_DATA32HI_Get(x) (((uint32_t) (x) & SDFM_SDDATA4_DATA32HI_Msk) >> SDFM_SDDATA4_DATA32HI_Pos) /*!< DATA32HI Get Value            */


#define SDFM_SDDATA4_DATA16_Pos    (0U)                                                                                  /*!< DATA16 Postion   0          */ 
#define SDFM_SDDATA4_DATA16_Msk    (0xffffU << SDFM_SDDATA4_DATA16_Pos)                                             /*!< DATA16 Mask      0x0000FFFF */
#define SDFM_SDDATA4_DATA16_Set(x) (((uint32_t) (x) << SDFM_SDDATA4_DATA16_Pos) & SDFM_SDDATA4_DATA16_Msk)     /*!< DATA16 Set Value            */
#define SDFM_SDDATA4_DATA16_Get(x) (((uint32_t) (x) & SDFM_SDDATA4_DATA16_Msk) >> SDFM_SDDATA4_DATA16_Pos)     /*!< DATA16 Get Value            */


/* SDDATFIFO4 bitfield */
#define SDFM_SDDATFIFO4_DATA32HI_Pos    (16U)                                                                                 /*!< DATA32HI Postion   16         */ 
#define SDFM_SDDATFIFO4_DATA32HI_Msk    (0xffffU << SDFM_SDDATFIFO4_DATA32HI_Pos)                                        /*!< DATA32HI Mask      0xFFFF0000 */
#define SDFM_SDDATFIFO4_DATA32HI_Set(x) (((uint32_t) (x) << SDFM_SDDATFIFO4_DATA32HI_Pos) & SDFM_SDDATFIFO4_DATA32HI_Msk) /*!< DATA32HI Set Value            */
#define SDFM_SDDATFIFO4_DATA32HI_Get(x) (((uint32_t) (x) & SDFM_SDDATFIFO4_DATA32HI_Msk) >> SDFM_SDDATFIFO4_DATA32HI_Pos) /*!< DATA32HI Get Value            */


#define SDFM_SDDATFIFO4_DATA16_Pos    (0U)                                                                                  /*!< DATA16 Postion   0          */ 
#define SDFM_SDDATFIFO4_DATA16_Msk    (0xffffU << SDFM_SDDATFIFO4_DATA16_Pos)                                          /*!< DATA16 Mask      0x0000FFFF */
#define SDFM_SDDATFIFO4_DATA16_Set(x) (((uint32_t) (x) << SDFM_SDDATFIFO4_DATA16_Pos) & SDFM_SDDATFIFO4_DATA16_Msk) /*!< DATA16 Set Value            */
#define SDFM_SDDATFIFO4_DATA16_Get(x) (((uint32_t) (x) & SDFM_SDDATFIFO4_DATA16_Msk) >> SDFM_SDDATFIFO4_DATA16_Pos) /*!< DATA16 Get Value            */


/* SDCDATA4 bitfield */
#define SDFM_SDCDATA4_DATA16_Pos    (0U)                                                                                  /*!< DATA16 Postion   0          */ 
#define SDFM_SDCDATA4_DATA16_Msk    (0xffffU << SDFM_SDCDATA4_DATA16_Pos)                                            /*!< DATA16 Mask      0x0000FFFF */
#define SDFM_SDCDATA4_DATA16_Set(x) (((uint16_t) (x) << SDFM_SDCDATA4_DATA16_Pos) & SDFM_SDCDATA4_DATA16_Msk)   /*!< DATA16 Set Value            */
#define SDFM_SDCDATA4_DATA16_Get(x) (((uint16_t) (x) & SDFM_SDCDATA4_DATA16_Msk) >> SDFM_SDCDATA4_DATA16_Pos)   /*!< DATA16 Get Value            */


/* SDFLT4CMPH2 bitfield */
#define SDFM_SDFLT4CMPH2_HLT2_Pos    (0U)                                                                                  /*!< HLT2 Postion   0          */ 
#define SDFM_SDFLT4CMPH2_HLT2_Msk    (0x7fffU << SDFM_SDFLT4CMPH2_HLT2_Pos)                                           /*!< HLT2 Mask      0x00007FFF */
#define SDFM_SDFLT4CMPH2_HLT2_Set(x) (((uint16_t) (x) << SDFM_SDFLT4CMPH2_HLT2_Pos) & SDFM_SDFLT4CMPH2_HLT2_Msk) /*!< HLT2 Set Value            */
#define SDFM_SDFLT4CMPH2_HLT2_Get(x) (((uint16_t) (x) & SDFM_SDFLT4CMPH2_HLT2_Msk) >> SDFM_SDFLT4CMPH2_HLT2_Pos) /*!< HLT2 Get Value            */


/* SDFLT4CMPHZ bitfield */
#define SDFM_SDFLT4CMPHZ_HLTZ_Pos    (0U)                                                                                  /*!< HLTZ Postion   0          */ 
#define SDFM_SDFLT4CMPHZ_HLTZ_Msk    (0x7fffU << SDFM_SDFLT4CMPHZ_HLTZ_Pos)                                           /*!< HLTZ Mask      0x00007FFF */
#define SDFM_SDFLT4CMPHZ_HLTZ_Set(x) (((uint16_t) (x) << SDFM_SDFLT4CMPHZ_HLTZ_Pos) & SDFM_SDFLT4CMPHZ_HLTZ_Msk) /*!< HLTZ Set Value            */
#define SDFM_SDFLT4CMPHZ_HLTZ_Get(x) (((uint16_t) (x) & SDFM_SDFLT4CMPHZ_HLTZ_Msk) >> SDFM_SDFLT4CMPHZ_HLTZ_Pos) /*!< HLTZ Get Value            */


/* SDFIFOCTL4 bitfield */
#define SDFM_SDFIFOCTL4_OVFIEN_Pos    (15U)                                                                                 /*!< OVFIEN Postion   15         */ 
#define SDFM_SDFIFOCTL4_OVFIEN_Msk    (0x1U << SDFM_SDFIFOCTL4_OVFIEN_Pos)                                             /*!< OVFIEN Mask      0x00008000 */
#define SDFM_SDFIFOCTL4_OVFIEN_Set(x) (((uint16_t) (x) << SDFM_SDFIFOCTL4_OVFIEN_Pos) & SDFM_SDFIFOCTL4_OVFIEN_Msk) /*!< OVFIEN Set Value            */
#define SDFM_SDFIFOCTL4_OVFIEN_Get(x) (((uint16_t) (x) & SDFM_SDFIFOCTL4_OVFIEN_Msk) >> SDFM_SDFIFOCTL4_OVFIEN_Pos) /*!< OVFIEN Get Value            */


#define SDFM_SDFIFOCTL4_DRINTSEL_Pos    (14U)                                                                                 /*!< DRINTSEL Postion   14         */ 
#define SDFM_SDFIFOCTL4_DRINTSEL_Msk    (0x1U << SDFM_SDFIFOCTL4_DRINTSEL_Pos)                                           /*!< DRINTSEL Mask      0x00004000 */
#define SDFM_SDFIFOCTL4_DRINTSEL_Set(x) (((uint16_t) (x) << SDFM_SDFIFOCTL4_DRINTSEL_Pos) & SDFM_SDFIFOCTL4_DRINTSEL_Msk) /*!< DRINTSEL Set Value            */
#define SDFM_SDFIFOCTL4_DRINTSEL_Get(x) (((uint16_t) (x) & SDFM_SDFIFOCTL4_DRINTSEL_Msk) >> SDFM_SDFIFOCTL4_DRINTSEL_Pos) /*!< DRINTSEL Get Value            */


#define SDFM_SDFIFOCTL4_FFEN_Pos    (13U)                                                                                 /*!< FFEN Postion   13         */ 
#define SDFM_SDFIFOCTL4_FFEN_Msk    (0x1U << SDFM_SDFIFOCTL4_FFEN_Pos)                                               /*!< FFEN Mask      0x00002000 */
#define SDFM_SDFIFOCTL4_FFEN_Set(x) (((uint16_t) (x) << SDFM_SDFIFOCTL4_FFEN_Pos) & SDFM_SDFIFOCTL4_FFEN_Msk)   /*!< FFEN Set Value            */
#define SDFM_SDFIFOCTL4_FFEN_Get(x) (((uint16_t) (x) & SDFM_SDFIFOCTL4_FFEN_Msk) >> SDFM_SDFIFOCTL4_FFEN_Pos)   /*!< FFEN Get Value            */


#define SDFM_SDFIFOCTL4_FFIEN_Pos    (12U)                                                                                 /*!< FFIEN Postion   12         */ 
#define SDFM_SDFIFOCTL4_FFIEN_Msk    (0x1U << SDFM_SDFIFOCTL4_FFIEN_Pos)                                              /*!< FFIEN Mask      0x00001000 */
#define SDFM_SDFIFOCTL4_FFIEN_Set(x) (((uint16_t) (x) << SDFM_SDFIFOCTL4_FFIEN_Pos) & SDFM_SDFIFOCTL4_FFIEN_Msk) /*!< FFIEN Set Value            */
#define SDFM_SDFIFOCTL4_FFIEN_Get(x) (((uint16_t) (x) & SDFM_SDFIFOCTL4_FFIEN_Msk) >> SDFM_SDFIFOCTL4_FFIEN_Pos) /*!< FFIEN Get Value            */


#define SDFM_SDFIFOCTL4_UDFIEN_Pos    (11U)                                                                                 /*!< UDFIEN Postion   11         */ 
#define SDFM_SDFIFOCTL4_UDFIEN_Msk    (0x1U << SDFM_SDFIFOCTL4_UDFIEN_Pos)                                             /*!< UDFIEN Mask      0x00000800 */
#define SDFM_SDFIFOCTL4_UDFIEN_Set(x) (((uint16_t) (x) << SDFM_SDFIFOCTL4_UDFIEN_Pos) & SDFM_SDFIFOCTL4_UDFIEN_Msk) /*!< UDFIEN Set Value            */
#define SDFM_SDFIFOCTL4_UDFIEN_Get(x) (((uint16_t) (x) & SDFM_SDFIFOCTL4_UDFIEN_Msk) >> SDFM_SDFIFOCTL4_UDFIEN_Pos) /*!< UDFIEN Get Value            */


#define SDFM_SDFIFOCTL4_SDFFST_Pos    (6U)                                                                                  /*!< SDFFST Postion   6          */ 
#define SDFM_SDFIFOCTL4_SDFFST_Msk    (0x1fU << SDFM_SDFIFOCTL4_SDFFST_Pos)                                            /*!< SDFFST Mask      0x000007C0 */
#define SDFM_SDFIFOCTL4_SDFFST_Set(x) (((uint16_t) (x) << SDFM_SDFIFOCTL4_SDFFST_Pos) & SDFM_SDFIFOCTL4_SDFFST_Msk) /*!< SDFFST Set Value            */
#define SDFM_SDFIFOCTL4_SDFFST_Get(x) (((uint16_t) (x) & SDFM_SDFIFOCTL4_SDFFST_Msk) >> SDFM_SDFIFOCTL4_SDFFST_Pos) /*!< SDFFST Get Value            */


#define SDFM_SDFIFOCTL4_DRDMASEL_Pos    (5U)                                                                                  /*!< DRDMASEL Postion   5          */ 
#define SDFM_SDFIFOCTL4_DRDMASEL_Msk    (0x1U << SDFM_SDFIFOCTL4_DRDMASEL_Pos)                                           /*!< DRDMASEL Mask      0x00000020 */
#define SDFM_SDFIFOCTL4_DRDMASEL_Set(x) (((uint16_t) (x) << SDFM_SDFIFOCTL4_DRDMASEL_Pos) & SDFM_SDFIFOCTL4_DRDMASEL_Msk) /*!< DRDMASEL Set Value            */
#define SDFM_SDFIFOCTL4_DRDMASEL_Get(x) (((uint16_t) (x) & SDFM_SDFIFOCTL4_DRDMASEL_Msk) >> SDFM_SDFIFOCTL4_DRDMASEL_Pos) /*!< DRDMASEL Get Value            */


#define SDFM_SDFIFOCTL4_SDFFIL_Pos    (0U)                                                                                  /*!< SDFFIL Postion   0          */ 
#define SDFM_SDFIFOCTL4_SDFFIL_Msk    (0x1fU << SDFM_SDFIFOCTL4_SDFFIL_Pos)                                            /*!< SDFFIL Mask      0x0000001F */
#define SDFM_SDFIFOCTL4_SDFFIL_Set(x) (((uint16_t) (x) << SDFM_SDFIFOCTL4_SDFFIL_Pos) & SDFM_SDFIFOCTL4_SDFFIL_Msk) /*!< SDFFIL Set Value            */
#define SDFM_SDFIFOCTL4_SDFFIL_Get(x) (((uint16_t) (x) & SDFM_SDFIFOCTL4_SDFFIL_Msk) >> SDFM_SDFIFOCTL4_SDFFIL_Pos) /*!< SDFFIL Get Value            */


/* SDSYNC4 bitfield */
#define SDFM_SDSYNC4_WTSCLREN_Pos    (10U)                                                                                 /*!< WTSCLREN Postion   10         */ 
#define SDFM_SDSYNC4_WTSCLREN_Msk    (0x1U << SDFM_SDSYNC4_WTSCLREN_Pos)                                              /*!< WTSCLREN Mask      0x00000400 */
#define SDFM_SDSYNC4_WTSCLREN_Set(x) (((uint16_t) (x) << SDFM_SDSYNC4_WTSCLREN_Pos) & SDFM_SDSYNC4_WTSCLREN_Msk) /*!< WTSCLREN Set Value            */
#define SDFM_SDSYNC4_WTSCLREN_Get(x) (((uint16_t) (x) & SDFM_SDSYNC4_WTSCLREN_Msk) >> SDFM_SDSYNC4_WTSCLREN_Pos) /*!< WTSCLREN Get Value            */


#define SDFM_SDSYNC4_FFSYNCCLREN_Pos    (9U)                                                                                  /*!< FFSYNCCLREN Postion   9          */ 
#define SDFM_SDSYNC4_FFSYNCCLREN_Msk    (0x1U << SDFM_SDSYNC4_FFSYNCCLREN_Pos)                                           /*!< FFSYNCCLREN Mask      0x00000200 */
#define SDFM_SDSYNC4_FFSYNCCLREN_Set(x) (((uint16_t) (x) << SDFM_SDSYNC4_FFSYNCCLREN_Pos) & SDFM_SDSYNC4_FFSYNCCLREN_Msk) /*!< FFSYNCCLREN Set Value            */
#define SDFM_SDSYNC4_FFSYNCCLREN_Get(x) (((uint16_t) (x) & SDFM_SDSYNC4_FFSYNCCLREN_Msk) >> SDFM_SDSYNC4_FFSYNCCLREN_Pos) /*!< FFSYNCCLREN Get Value            */


#define SDFM_SDSYNC4_WTSYNCLR_Pos    (8U)                                                                                  /*!< WTSYNCLR Postion   8          */ 
#define SDFM_SDSYNC4_WTSYNCLR_Msk    (0x1U << SDFM_SDSYNC4_WTSYNCLR_Pos)                                              /*!< WTSYNCLR Mask      0x00000100 */
#define SDFM_SDSYNC4_WTSYNCLR_Set(x) (((uint16_t) (x) << SDFM_SDSYNC4_WTSYNCLR_Pos) & SDFM_SDSYNC4_WTSYNCLR_Msk) /*!< WTSYNCLR Set Value            */
#define SDFM_SDSYNC4_WTSYNCLR_Get(x) (((uint16_t) (x) & SDFM_SDSYNC4_WTSYNCLR_Msk) >> SDFM_SDSYNC4_WTSYNCLR_Pos) /*!< WTSYNCLR Get Value            */


#define SDFM_SDSYNC4_WTSYNFLG_Pos    (7U)                                                                                  /*!< WTSYNFLG Postion   7          */ 
#define SDFM_SDSYNC4_WTSYNFLG_Msk    (0x1U << SDFM_SDSYNC4_WTSYNFLG_Pos)                                              /*!< WTSYNFLG Mask      0x00000080 */
#define SDFM_SDSYNC4_WTSYNFLG_Set(x) (((uint16_t) (x) << SDFM_SDSYNC4_WTSYNFLG_Pos) & SDFM_SDSYNC4_WTSYNFLG_Msk) /*!< WTSYNFLG Set Value            */
#define SDFM_SDSYNC4_WTSYNFLG_Get(x) (((uint16_t) (x) & SDFM_SDSYNC4_WTSYNFLG_Msk) >> SDFM_SDSYNC4_WTSYNFLG_Pos) /*!< WTSYNFLG Get Value            */


#define SDFM_SDSYNC4_WTSYNCEN_Pos    (6U)                                                                                  /*!< WTSYNCEN Postion   6          */ 
#define SDFM_SDSYNC4_WTSYNCEN_Msk    (0x1U << SDFM_SDSYNC4_WTSYNCEN_Pos)                                              /*!< WTSYNCEN Mask      0x00000040 */
#define SDFM_SDSYNC4_WTSYNCEN_Set(x) (((uint16_t) (x) << SDFM_SDSYNC4_WTSYNCEN_Pos) & SDFM_SDSYNC4_WTSYNCEN_Msk) /*!< WTSYNCEN Set Value            */
#define SDFM_SDSYNC4_WTSYNCEN_Get(x) (((uint16_t) (x) & SDFM_SDSYNC4_WTSYNCEN_Msk) >> SDFM_SDSYNC4_WTSYNCEN_Pos) /*!< WTSYNCEN Get Value            */


#define SDFM_SDSYNC4_SYNCSEL_Pos    (0U)                                                                                  /*!< SYNCSEL Postion   0          */ 
#define SDFM_SDSYNC4_SYNCSEL_Msk    (0x3fU << SDFM_SDSYNC4_SYNCSEL_Pos)                                              /*!< SYNCSEL Mask      0x0000003F */
#define SDFM_SDSYNC4_SYNCSEL_Set(x) (((uint16_t) (x) << SDFM_SDSYNC4_SYNCSEL_Pos) & SDFM_SDSYNC4_SYNCSEL_Msk)   /*!< SYNCSEL Set Value            */
#define SDFM_SDSYNC4_SYNCSEL_Get(x) (((uint16_t) (x) & SDFM_SDSYNC4_SYNCSEL_Msk) >> SDFM_SDSYNC4_SYNCSEL_Pos)   /*!< SYNCSEL Get Value            */


/* SDFLT4CMPL2 bitfield */
#define SDFM_SDFLT4CMPL2_LLT2_Pos    (0U)                                                                                  /*!< LLT2 Postion   0          */ 
#define SDFM_SDFLT4CMPL2_LLT2_Msk    (0x7fffU << SDFM_SDFLT4CMPL2_LLT2_Pos)                                           /*!< LLT2 Mask      0x00007FFF */
#define SDFM_SDFLT4CMPL2_LLT2_Set(x) (((uint16_t) (x) << SDFM_SDFLT4CMPL2_LLT2_Pos) & SDFM_SDFLT4CMPL2_LLT2_Msk) /*!< LLT2 Set Value            */
#define SDFM_SDFLT4CMPL2_LLT2_Get(x) (((uint16_t) (x) & SDFM_SDFLT4CMPL2_LLT2_Msk) >> SDFM_SDFLT4CMPL2_LLT2_Pos) /*!< LLT2 Get Value            */


/* SDCOMP1CTL bitfield */
#define SDFM_SDCOMP1CTL_CEVT2DIGFILTSEL_Pos    (10U)                                                                                 /*!< CEVT2DIGFILTSEL Postion   10         */ 
#define SDFM_SDCOMP1CTL_CEVT2DIGFILTSEL_Msk    (0x3U << SDFM_SDCOMP1CTL_CEVT2DIGFILTSEL_Pos)                                    /*!< CEVT2DIGFILTSEL Mask      0x00000C00 */
#define SDFM_SDCOMP1CTL_CEVT2DIGFILTSEL_Set(x) (((uint16_t) (x) << SDFM_SDCOMP1CTL_CEVT2DIGFILTSEL_Pos) & SDFM_SDCOMP1CTL_CEVT2DIGFILTSEL_Msk) /*!< CEVT2DIGFILTSEL Set Value            */
#define SDFM_SDCOMP1CTL_CEVT2DIGFILTSEL_Get(x) (((uint16_t) (x) & SDFM_SDCOMP1CTL_CEVT2DIGFILTSEL_Msk) >> SDFM_SDCOMP1CTL_CEVT2DIGFILTSEL_Pos) /*!< CEVT2DIGFILTSEL Get Value            */


#define SDFM_SDCOMP1CTL_CEVT1DIGFILTSEL_Pos    (2U)                                                                                  /*!< CEVT1DIGFILTSEL Postion   2          */ 
#define SDFM_SDCOMP1CTL_CEVT1DIGFILTSEL_Msk    (0x3U << SDFM_SDCOMP1CTL_CEVT1DIGFILTSEL_Pos)                                    /*!< CEVT1DIGFILTSEL Mask      0x0000000C */
#define SDFM_SDCOMP1CTL_CEVT1DIGFILTSEL_Set(x) (((uint16_t) (x) << SDFM_SDCOMP1CTL_CEVT1DIGFILTSEL_Pos) & SDFM_SDCOMP1CTL_CEVT1DIGFILTSEL_Msk) /*!< CEVT1DIGFILTSEL Set Value            */
#define SDFM_SDCOMP1CTL_CEVT1DIGFILTSEL_Get(x) (((uint16_t) (x) & SDFM_SDCOMP1CTL_CEVT1DIGFILTSEL_Msk) >> SDFM_SDCOMP1CTL_CEVT1DIGFILTSEL_Pos) /*!< CEVT1DIGFILTSEL Get Value            */


/* SDCOMP1EVT2FLTCTL bitfield */
#define SDFM_SDCOMP1EVT2FLTCTL_FILINIT_Pos    (15U)                                                                                 /*!< FILINIT Postion   15         */ 
#define SDFM_SDCOMP1EVT2FLTCTL_FILINIT_Msk    (0x1U << SDFM_SDCOMP1EVT2FLTCTL_FILINIT_Pos)                                     /*!< FILINIT Mask      0x00008000 */
#define SDFM_SDCOMP1EVT2FLTCTL_FILINIT_Set(x) (((uint16_t) (x) << SDFM_SDCOMP1EVT2FLTCTL_FILINIT_Pos) & SDFM_SDCOMP1EVT2FLTCTL_FILINIT_Msk) /*!< FILINIT Set Value            */
#define SDFM_SDCOMP1EVT2FLTCTL_FILINIT_Get(x) (((uint16_t) (x) & SDFM_SDCOMP1EVT2FLTCTL_FILINIT_Msk) >> SDFM_SDCOMP1EVT2FLTCTL_FILINIT_Pos) /*!< FILINIT Get Value            */


#define SDFM_SDCOMP1EVT2FLTCTL_THRESH_Pos    (9U)                                                                                  /*!< THRESH Postion   9          */ 
#define SDFM_SDCOMP1EVT2FLTCTL_THRESH_Msk    (0x1fU << SDFM_SDCOMP1EVT2FLTCTL_THRESH_Pos)                                     /*!< THRESH Mask      0x00003E00 */
#define SDFM_SDCOMP1EVT2FLTCTL_THRESH_Set(x) (((uint16_t) (x) << SDFM_SDCOMP1EVT2FLTCTL_THRESH_Pos) & SDFM_SDCOMP1EVT2FLTCTL_THRESH_Msk) /*!< THRESH Set Value            */
#define SDFM_SDCOMP1EVT2FLTCTL_THRESH_Get(x) (((uint16_t) (x) & SDFM_SDCOMP1EVT2FLTCTL_THRESH_Msk) >> SDFM_SDCOMP1EVT2FLTCTL_THRESH_Pos) /*!< THRESH Get Value            */


#define SDFM_SDCOMP1EVT2FLTCTL_SAMPWIN_Pos    (4U)                                                                                  /*!< SAMPWIN Postion   4          */ 
#define SDFM_SDCOMP1EVT2FLTCTL_SAMPWIN_Msk    (0x1fU << SDFM_SDCOMP1EVT2FLTCTL_SAMPWIN_Pos)                                    /*!< SAMPWIN Mask      0x000001F0 */
#define SDFM_SDCOMP1EVT2FLTCTL_SAMPWIN_Set(x) (((uint16_t) (x) << SDFM_SDCOMP1EVT2FLTCTL_SAMPWIN_Pos) & SDFM_SDCOMP1EVT2FLTCTL_SAMPWIN_Msk) /*!< SAMPWIN Set Value            */
#define SDFM_SDCOMP1EVT2FLTCTL_SAMPWIN_Get(x) (((uint16_t) (x) & SDFM_SDCOMP1EVT2FLTCTL_SAMPWIN_Msk) >> SDFM_SDCOMP1EVT2FLTCTL_SAMPWIN_Pos) /*!< SAMPWIN Get Value            */


/* SDCOMP1EVT2FLTCLKCTL bitfield */
#define SDFM_SDCOMP1EVT2FLTCLKCTL_CLKPRESCALE_Pos    (0U)                                                                                  /*!< CLKPRESCALE Postion   0          */ 
#define SDFM_SDCOMP1EVT2FLTCLKCTL_CLKPRESCALE_Msk    (0x3ffU << SDFM_SDCOMP1EVT2FLTCLKCTL_CLKPRESCALE_Pos)                            /*!< CLKPRESCALE Mask      0x000003FF */
#define SDFM_SDCOMP1EVT2FLTCLKCTL_CLKPRESCALE_Set(x) (((uint16_t) (x) << SDFM_SDCOMP1EVT2FLTCLKCTL_CLKPRESCALE_Pos) & SDFM_SDCOMP1EVT2FLTCLKCTL_CLKPRESCALE_Msk) /*!< CLKPRESCALE Set Value            */
#define SDFM_SDCOMP1EVT2FLTCLKCTL_CLKPRESCALE_Get(x) (((uint16_t) (x) & SDFM_SDCOMP1EVT2FLTCLKCTL_CLKPRESCALE_Msk) >> SDFM_SDCOMP1EVT2FLTCLKCTL_CLKPRESCALE_Pos) /*!< CLKPRESCALE Get Value            */


/* SDCOMP1EVT1FLTCTL bitfield */
#define SDFM_SDCOMP1EVT1FLTCTL_FILINIT_Pos    (15U)                                                                                 /*!< FILINIT Postion   15         */ 
#define SDFM_SDCOMP1EVT1FLTCTL_FILINIT_Msk    (0x1U << SDFM_SDCOMP1EVT1FLTCTL_FILINIT_Pos)                                     /*!< FILINIT Mask      0x00008000 */
#define SDFM_SDCOMP1EVT1FLTCTL_FILINIT_Set(x) (((uint16_t) (x) << SDFM_SDCOMP1EVT1FLTCTL_FILINIT_Pos) & SDFM_SDCOMP1EVT1FLTCTL_FILINIT_Msk) /*!< FILINIT Set Value            */
#define SDFM_SDCOMP1EVT1FLTCTL_FILINIT_Get(x) (((uint16_t) (x) & SDFM_SDCOMP1EVT1FLTCTL_FILINIT_Msk) >> SDFM_SDCOMP1EVT1FLTCTL_FILINIT_Pos) /*!< FILINIT Get Value            */


#define SDFM_SDCOMP1EVT1FLTCTL_THRESH_Pos    (9U)                                                                                  /*!< THRESH Postion   9          */ 
#define SDFM_SDCOMP1EVT1FLTCTL_THRESH_Msk    (0x1fU << SDFM_SDCOMP1EVT1FLTCTL_THRESH_Pos)                                     /*!< THRESH Mask      0x00003E00 */
#define SDFM_SDCOMP1EVT1FLTCTL_THRESH_Set(x) (((uint16_t) (x) << SDFM_SDCOMP1EVT1FLTCTL_THRESH_Pos) & SDFM_SDCOMP1EVT1FLTCTL_THRESH_Msk) /*!< THRESH Set Value            */
#define SDFM_SDCOMP1EVT1FLTCTL_THRESH_Get(x) (((uint16_t) (x) & SDFM_SDCOMP1EVT1FLTCTL_THRESH_Msk) >> SDFM_SDCOMP1EVT1FLTCTL_THRESH_Pos) /*!< THRESH Get Value            */


#define SDFM_SDCOMP1EVT1FLTCTL_SAMPWIN_Pos    (4U)                                                                                  /*!< SAMPWIN Postion   4          */ 
#define SDFM_SDCOMP1EVT1FLTCTL_SAMPWIN_Msk    (0x1fU << SDFM_SDCOMP1EVT1FLTCTL_SAMPWIN_Pos)                                    /*!< SAMPWIN Mask      0x000001F0 */
#define SDFM_SDCOMP1EVT1FLTCTL_SAMPWIN_Set(x) (((uint16_t) (x) << SDFM_SDCOMP1EVT1FLTCTL_SAMPWIN_Pos) & SDFM_SDCOMP1EVT1FLTCTL_SAMPWIN_Msk) /*!< SAMPWIN Set Value            */
#define SDFM_SDCOMP1EVT1FLTCTL_SAMPWIN_Get(x) (((uint16_t) (x) & SDFM_SDCOMP1EVT1FLTCTL_SAMPWIN_Msk) >> SDFM_SDCOMP1EVT1FLTCTL_SAMPWIN_Pos) /*!< SAMPWIN Get Value            */


/* SDCOMP1EVT1FLTCLKCTL bitfield */
#define SDFM_SDCOMP1EVT1FLTCLKCTL_CLKPRESCALE_Pos    (0U)                                                                                  /*!< CLKPRESCALE Postion   0          */ 
#define SDFM_SDCOMP1EVT1FLTCLKCTL_CLKPRESCALE_Msk    (0x3ffU << SDFM_SDCOMP1EVT1FLTCLKCTL_CLKPRESCALE_Pos)                            /*!< CLKPRESCALE Mask      0x000003FF */
#define SDFM_SDCOMP1EVT1FLTCLKCTL_CLKPRESCALE_Set(x) (((uint16_t) (x) << SDFM_SDCOMP1EVT1FLTCLKCTL_CLKPRESCALE_Pos) & SDFM_SDCOMP1EVT1FLTCLKCTL_CLKPRESCALE_Msk) /*!< CLKPRESCALE Set Value            */
#define SDFM_SDCOMP1EVT1FLTCLKCTL_CLKPRESCALE_Get(x) (((uint16_t) (x) & SDFM_SDCOMP1EVT1FLTCLKCTL_CLKPRESCALE_Msk) >> SDFM_SDCOMP1EVT1FLTCLKCTL_CLKPRESCALE_Pos) /*!< CLKPRESCALE Get Value            */


/* RESERVED1 bitfield */
/* SDCOMP1LOCK bitfield */
#define SDFM_SDCOMP1LOCK_COMP_Pos    (3U)                                                                                  /*!< COMP Postion   3          */ 
#define SDFM_SDCOMP1LOCK_COMP_Msk    (0x1U << SDFM_SDCOMP1LOCK_COMP_Pos)                                              /*!< COMP Mask      0x00000008 */
#define SDFM_SDCOMP1LOCK_COMP_Set(x) (((uint16_t) (x) << SDFM_SDCOMP1LOCK_COMP_Pos) & SDFM_SDCOMP1LOCK_COMP_Msk) /*!< COMP Set Value            */
#define SDFM_SDCOMP1LOCK_COMP_Get(x) (((uint16_t) (x) & SDFM_SDCOMP1LOCK_COMP_Msk) >> SDFM_SDCOMP1LOCK_COMP_Pos) /*!< COMP Get Value            */


#define SDFM_SDCOMP1LOCK_SDCOMP1CTL_Pos    (0U)                                                                                  /*!< SDCOMP1CTL Postion   0          */ 
#define SDFM_SDCOMP1LOCK_SDCOMP1CTL_Msk    (0x1U << SDFM_SDCOMP1LOCK_SDCOMP1CTL_Pos)                                        /*!< SDCOMP1CTL Mask      0x00000001 */
#define SDFM_SDCOMP1LOCK_SDCOMP1CTL_Set(x) (((uint16_t) (x) << SDFM_SDCOMP1LOCK_SDCOMP1CTL_Pos) & SDFM_SDCOMP1LOCK_SDCOMP1CTL_Msk) /*!< SDCOMP1CTL Set Value            */
#define SDFM_SDCOMP1LOCK_SDCOMP1CTL_Get(x) (((uint16_t) (x) & SDFM_SDCOMP1LOCK_SDCOMP1CTL_Msk) >> SDFM_SDCOMP1LOCK_SDCOMP1CTL_Pos) /*!< SDCOMP1CTL Get Value            */


/* SDCOMP2CTL bitfield */
#define SDFM_SDCOMP2CTL_CEVT2DIGFILTSEL_Pos    (10U)                                                                                 /*!< CEVT2DIGFILTSEL Postion   10         */ 
#define SDFM_SDCOMP2CTL_CEVT2DIGFILTSEL_Msk    (0x3U << SDFM_SDCOMP2CTL_CEVT2DIGFILTSEL_Pos)                                    /*!< CEVT2DIGFILTSEL Mask      0x00000C00 */
#define SDFM_SDCOMP2CTL_CEVT2DIGFILTSEL_Set(x) (((uint16_t) (x) << SDFM_SDCOMP2CTL_CEVT2DIGFILTSEL_Pos) & SDFM_SDCOMP2CTL_CEVT2DIGFILTSEL_Msk) /*!< CEVT2DIGFILTSEL Set Value            */
#define SDFM_SDCOMP2CTL_CEVT2DIGFILTSEL_Get(x) (((uint16_t) (x) & SDFM_SDCOMP2CTL_CEVT2DIGFILTSEL_Msk) >> SDFM_SDCOMP2CTL_CEVT2DIGFILTSEL_Pos) /*!< CEVT2DIGFILTSEL Get Value            */


#define SDFM_SDCOMP2CTL_CEVT1DIGFILTSEL_Pos    (2U)                                                                                  /*!< CEVT1DIGFILTSEL Postion   2          */ 
#define SDFM_SDCOMP2CTL_CEVT1DIGFILTSEL_Msk    (0x3U << SDFM_SDCOMP2CTL_CEVT1DIGFILTSEL_Pos)                                    /*!< CEVT1DIGFILTSEL Mask      0x0000000C */
#define SDFM_SDCOMP2CTL_CEVT1DIGFILTSEL_Set(x) (((uint16_t) (x) << SDFM_SDCOMP2CTL_CEVT1DIGFILTSEL_Pos) & SDFM_SDCOMP2CTL_CEVT1DIGFILTSEL_Msk) /*!< CEVT1DIGFILTSEL Set Value            */
#define SDFM_SDCOMP2CTL_CEVT1DIGFILTSEL_Get(x) (((uint16_t) (x) & SDFM_SDCOMP2CTL_CEVT1DIGFILTSEL_Msk) >> SDFM_SDCOMP2CTL_CEVT1DIGFILTSEL_Pos) /*!< CEVT1DIGFILTSEL Get Value            */


/* SDCOMP2EVT2FLTCTL bitfield */
#define SDFM_SDCOMP2EVT2FLTCTL_FILINIT_Pos    (15U)                                                                                 /*!< FILINIT Postion   15         */ 
#define SDFM_SDCOMP2EVT2FLTCTL_FILINIT_Msk    (0x1U << SDFM_SDCOMP2EVT2FLTCTL_FILINIT_Pos)                                     /*!< FILINIT Mask      0x00008000 */
#define SDFM_SDCOMP2EVT2FLTCTL_FILINIT_Set(x) (((uint16_t) (x) << SDFM_SDCOMP2EVT2FLTCTL_FILINIT_Pos) & SDFM_SDCOMP2EVT2FLTCTL_FILINIT_Msk) /*!< FILINIT Set Value            */
#define SDFM_SDCOMP2EVT2FLTCTL_FILINIT_Get(x) (((uint16_t) (x) & SDFM_SDCOMP2EVT2FLTCTL_FILINIT_Msk) >> SDFM_SDCOMP2EVT2FLTCTL_FILINIT_Pos) /*!< FILINIT Get Value            */


#define SDFM_SDCOMP2EVT2FLTCTL_THRESH_Pos    (9U)                                                                                  /*!< THRESH Postion   9          */ 
#define SDFM_SDCOMP2EVT2FLTCTL_THRESH_Msk    (0x1fU << SDFM_SDCOMP2EVT2FLTCTL_THRESH_Pos)                                     /*!< THRESH Mask      0x00003E00 */
#define SDFM_SDCOMP2EVT2FLTCTL_THRESH_Set(x) (((uint16_t) (x) << SDFM_SDCOMP2EVT2FLTCTL_THRESH_Pos) & SDFM_SDCOMP2EVT2FLTCTL_THRESH_Msk) /*!< THRESH Set Value            */
#define SDFM_SDCOMP2EVT2FLTCTL_THRESH_Get(x) (((uint16_t) (x) & SDFM_SDCOMP2EVT2FLTCTL_THRESH_Msk) >> SDFM_SDCOMP2EVT2FLTCTL_THRESH_Pos) /*!< THRESH Get Value            */


#define SDFM_SDCOMP2EVT2FLTCTL_SAMPWIN_Pos    (4U)                                                                                  /*!< SAMPWIN Postion   4          */ 
#define SDFM_SDCOMP2EVT2FLTCTL_SAMPWIN_Msk    (0x1fU << SDFM_SDCOMP2EVT2FLTCTL_SAMPWIN_Pos)                                    /*!< SAMPWIN Mask      0x000001F0 */
#define SDFM_SDCOMP2EVT2FLTCTL_SAMPWIN_Set(x) (((uint16_t) (x) << SDFM_SDCOMP2EVT2FLTCTL_SAMPWIN_Pos) & SDFM_SDCOMP2EVT2FLTCTL_SAMPWIN_Msk) /*!< SAMPWIN Set Value            */
#define SDFM_SDCOMP2EVT2FLTCTL_SAMPWIN_Get(x) (((uint16_t) (x) & SDFM_SDCOMP2EVT2FLTCTL_SAMPWIN_Msk) >> SDFM_SDCOMP2EVT2FLTCTL_SAMPWIN_Pos) /*!< SAMPWIN Get Value            */


/* SDCOMP2EVT2FLTCLKCTL bitfield */
#define SDFM_SDCOMP2EVT2FLTCLKCTL_CLKPRESCALE_Pos    (0U)                                                                                  /*!< CLKPRESCALE Postion   0          */ 
#define SDFM_SDCOMP2EVT2FLTCLKCTL_CLKPRESCALE_Msk    (0x3ffU << SDFM_SDCOMP2EVT2FLTCLKCTL_CLKPRESCALE_Pos)                            /*!< CLKPRESCALE Mask      0x000003FF */
#define SDFM_SDCOMP2EVT2FLTCLKCTL_CLKPRESCALE_Set(x) (((uint16_t) (x) << SDFM_SDCOMP2EVT2FLTCLKCTL_CLKPRESCALE_Pos) & SDFM_SDCOMP2EVT2FLTCLKCTL_CLKPRESCALE_Msk) /*!< CLKPRESCALE Set Value            */
#define SDFM_SDCOMP2EVT2FLTCLKCTL_CLKPRESCALE_Get(x) (((uint16_t) (x) & SDFM_SDCOMP2EVT2FLTCLKCTL_CLKPRESCALE_Msk) >> SDFM_SDCOMP2EVT2FLTCLKCTL_CLKPRESCALE_Pos) /*!< CLKPRESCALE Get Value            */


/* SDCOMP2EVT1FLTCTL bitfield */
#define SDFM_SDCOMP2EVT1FLTCTL_FILINIT_Pos    (15U)                                                                                 /*!< FILINIT Postion   15         */ 
#define SDFM_SDCOMP2EVT1FLTCTL_FILINIT_Msk    (0x1U << SDFM_SDCOMP2EVT1FLTCTL_FILINIT_Pos)                                     /*!< FILINIT Mask      0x00008000 */
#define SDFM_SDCOMP2EVT1FLTCTL_FILINIT_Set(x) (((uint16_t) (x) << SDFM_SDCOMP2EVT1FLTCTL_FILINIT_Pos) & SDFM_SDCOMP2EVT1FLTCTL_FILINIT_Msk) /*!< FILINIT Set Value            */
#define SDFM_SDCOMP2EVT1FLTCTL_FILINIT_Get(x) (((uint16_t) (x) & SDFM_SDCOMP2EVT1FLTCTL_FILINIT_Msk) >> SDFM_SDCOMP2EVT1FLTCTL_FILINIT_Pos) /*!< FILINIT Get Value            */


#define SDFM_SDCOMP2EVT1FLTCTL_THRESH_Pos    (9U)                                                                                  /*!< THRESH Postion   9          */ 
#define SDFM_SDCOMP2EVT1FLTCTL_THRESH_Msk    (0x1fU << SDFM_SDCOMP2EVT1FLTCTL_THRESH_Pos)                                     /*!< THRESH Mask      0x00003E00 */
#define SDFM_SDCOMP2EVT1FLTCTL_THRESH_Set(x) (((uint16_t) (x) << SDFM_SDCOMP2EVT1FLTCTL_THRESH_Pos) & SDFM_SDCOMP2EVT1FLTCTL_THRESH_Msk) /*!< THRESH Set Value            */
#define SDFM_SDCOMP2EVT1FLTCTL_THRESH_Get(x) (((uint16_t) (x) & SDFM_SDCOMP2EVT1FLTCTL_THRESH_Msk) >> SDFM_SDCOMP2EVT1FLTCTL_THRESH_Pos) /*!< THRESH Get Value            */


#define SDFM_SDCOMP2EVT1FLTCTL_SAMPWIN_Pos    (4U)                                                                                  /*!< SAMPWIN Postion   4          */ 
#define SDFM_SDCOMP2EVT1FLTCTL_SAMPWIN_Msk    (0x1fU << SDFM_SDCOMP2EVT1FLTCTL_SAMPWIN_Pos)                                    /*!< SAMPWIN Mask      0x000001F0 */
#define SDFM_SDCOMP2EVT1FLTCTL_SAMPWIN_Set(x) (((uint16_t) (x) << SDFM_SDCOMP2EVT1FLTCTL_SAMPWIN_Pos) & SDFM_SDCOMP2EVT1FLTCTL_SAMPWIN_Msk) /*!< SAMPWIN Set Value            */
#define SDFM_SDCOMP2EVT1FLTCTL_SAMPWIN_Get(x) (((uint16_t) (x) & SDFM_SDCOMP2EVT1FLTCTL_SAMPWIN_Msk) >> SDFM_SDCOMP2EVT1FLTCTL_SAMPWIN_Pos) /*!< SAMPWIN Get Value            */


/* SDCOMP2EVT1FLTCLKCTL bitfield */
#define SDFM_SDCOMP2EVT1FLTCLKCTL_CLKPRESCALE_Pos    (0U)                                                                                  /*!< CLKPRESCALE Postion   0          */ 
#define SDFM_SDCOMP2EVT1FLTCLKCTL_CLKPRESCALE_Msk    (0x3ffU << SDFM_SDCOMP2EVT1FLTCLKCTL_CLKPRESCALE_Pos)                            /*!< CLKPRESCALE Mask      0x000003FF */
#define SDFM_SDCOMP2EVT1FLTCLKCTL_CLKPRESCALE_Set(x) (((uint16_t) (x) << SDFM_SDCOMP2EVT1FLTCLKCTL_CLKPRESCALE_Pos) & SDFM_SDCOMP2EVT1FLTCLKCTL_CLKPRESCALE_Msk) /*!< CLKPRESCALE Set Value            */
#define SDFM_SDCOMP2EVT1FLTCLKCTL_CLKPRESCALE_Get(x) (((uint16_t) (x) & SDFM_SDCOMP2EVT1FLTCLKCTL_CLKPRESCALE_Msk) >> SDFM_SDCOMP2EVT1FLTCLKCTL_CLKPRESCALE_Pos) /*!< CLKPRESCALE Get Value            */


/* RESERVED2 bitfield */
/* SDCOMP2LOCK bitfield */
#define SDFM_SDCOMP2LOCK_COMP_Pos    (3U)                                                                                  /*!< COMP Postion   3          */ 
#define SDFM_SDCOMP2LOCK_COMP_Msk    (0x1U << SDFM_SDCOMP2LOCK_COMP_Pos)                                              /*!< COMP Mask      0x00000008 */
#define SDFM_SDCOMP2LOCK_COMP_Set(x) (((uint16_t) (x) << SDFM_SDCOMP2LOCK_COMP_Pos) & SDFM_SDCOMP2LOCK_COMP_Msk) /*!< COMP Set Value            */
#define SDFM_SDCOMP2LOCK_COMP_Get(x) (((uint16_t) (x) & SDFM_SDCOMP2LOCK_COMP_Msk) >> SDFM_SDCOMP2LOCK_COMP_Pos) /*!< COMP Get Value            */


#define SDFM_SDCOMP2LOCK_SDCOMP2CTL_Pos    (0U)                                                                                  /*!< SDCOMP2CTL Postion   0          */ 
#define SDFM_SDCOMP2LOCK_SDCOMP2CTL_Msk    (0x1U << SDFM_SDCOMP2LOCK_SDCOMP2CTL_Pos)                                        /*!< SDCOMP2CTL Mask      0x00000001 */
#define SDFM_SDCOMP2LOCK_SDCOMP2CTL_Set(x) (((uint16_t) (x) << SDFM_SDCOMP2LOCK_SDCOMP2CTL_Pos) & SDFM_SDCOMP2LOCK_SDCOMP2CTL_Msk) /*!< SDCOMP2CTL Set Value            */
#define SDFM_SDCOMP2LOCK_SDCOMP2CTL_Get(x) (((uint16_t) (x) & SDFM_SDCOMP2LOCK_SDCOMP2CTL_Msk) >> SDFM_SDCOMP2LOCK_SDCOMP2CTL_Pos) /*!< SDCOMP2CTL Get Value            */


/* SDCOMP3CTL bitfield */
#define SDFM_SDCOMP3CTL_CEVT2DIGFILTSEL_Pos    (10U)                                                                                 /*!< CEVT2DIGFILTSEL Postion   10         */ 
#define SDFM_SDCOMP3CTL_CEVT2DIGFILTSEL_Msk    (0x3U << SDFM_SDCOMP3CTL_CEVT2DIGFILTSEL_Pos)                                    /*!< CEVT2DIGFILTSEL Mask      0x00000C00 */
#define SDFM_SDCOMP3CTL_CEVT2DIGFILTSEL_Set(x) (((uint16_t) (x) << SDFM_SDCOMP3CTL_CEVT2DIGFILTSEL_Pos) & SDFM_SDCOMP3CTL_CEVT2DIGFILTSEL_Msk) /*!< CEVT2DIGFILTSEL Set Value            */
#define SDFM_SDCOMP3CTL_CEVT2DIGFILTSEL_Get(x) (((uint16_t) (x) & SDFM_SDCOMP3CTL_CEVT2DIGFILTSEL_Msk) >> SDFM_SDCOMP3CTL_CEVT2DIGFILTSEL_Pos) /*!< CEVT2DIGFILTSEL Get Value            */


#define SDFM_SDCOMP3CTL_CEVT1DIGFILTSEL_Pos    (2U)                                                                                  /*!< CEVT1DIGFILTSEL Postion   2          */ 
#define SDFM_SDCOMP3CTL_CEVT1DIGFILTSEL_Msk    (0x3U << SDFM_SDCOMP3CTL_CEVT1DIGFILTSEL_Pos)                                    /*!< CEVT1DIGFILTSEL Mask      0x0000000C */
#define SDFM_SDCOMP3CTL_CEVT1DIGFILTSEL_Set(x) (((uint16_t) (x) << SDFM_SDCOMP3CTL_CEVT1DIGFILTSEL_Pos) & SDFM_SDCOMP3CTL_CEVT1DIGFILTSEL_Msk) /*!< CEVT1DIGFILTSEL Set Value            */
#define SDFM_SDCOMP3CTL_CEVT1DIGFILTSEL_Get(x) (((uint16_t) (x) & SDFM_SDCOMP3CTL_CEVT1DIGFILTSEL_Msk) >> SDFM_SDCOMP3CTL_CEVT1DIGFILTSEL_Pos) /*!< CEVT1DIGFILTSEL Get Value            */


/* SDCOMP3EVT2FLTCTL bitfield */
#define SDFM_SDCOMP3EVT2FLTCTL_FILINIT_Pos    (15U)                                                                                 /*!< FILINIT Postion   15         */ 
#define SDFM_SDCOMP3EVT2FLTCTL_FILINIT_Msk    (0x1U << SDFM_SDCOMP3EVT2FLTCTL_FILINIT_Pos)                                     /*!< FILINIT Mask      0x00008000 */
#define SDFM_SDCOMP3EVT2FLTCTL_FILINIT_Set(x) (((uint16_t) (x) << SDFM_SDCOMP3EVT2FLTCTL_FILINIT_Pos) & SDFM_SDCOMP3EVT2FLTCTL_FILINIT_Msk) /*!< FILINIT Set Value            */
#define SDFM_SDCOMP3EVT2FLTCTL_FILINIT_Get(x) (((uint16_t) (x) & SDFM_SDCOMP3EVT2FLTCTL_FILINIT_Msk) >> SDFM_SDCOMP3EVT2FLTCTL_FILINIT_Pos) /*!< FILINIT Get Value            */


#define SDFM_SDCOMP3EVT2FLTCTL_THRESH_Pos    (9U)                                                                                  /*!< THRESH Postion   9          */ 
#define SDFM_SDCOMP3EVT2FLTCTL_THRESH_Msk    (0x1fU << SDFM_SDCOMP3EVT2FLTCTL_THRESH_Pos)                                     /*!< THRESH Mask      0x00003E00 */
#define SDFM_SDCOMP3EVT2FLTCTL_THRESH_Set(x) (((uint16_t) (x) << SDFM_SDCOMP3EVT2FLTCTL_THRESH_Pos) & SDFM_SDCOMP3EVT2FLTCTL_THRESH_Msk) /*!< THRESH Set Value            */
#define SDFM_SDCOMP3EVT2FLTCTL_THRESH_Get(x) (((uint16_t) (x) & SDFM_SDCOMP3EVT2FLTCTL_THRESH_Msk) >> SDFM_SDCOMP3EVT2FLTCTL_THRESH_Pos) /*!< THRESH Get Value            */


#define SDFM_SDCOMP3EVT2FLTCTL_SAMPWIN_Pos    (4U)                                                                                  /*!< SAMPWIN Postion   4          */ 
#define SDFM_SDCOMP3EVT2FLTCTL_SAMPWIN_Msk    (0x1fU << SDFM_SDCOMP3EVT2FLTCTL_SAMPWIN_Pos)                                    /*!< SAMPWIN Mask      0x000001F0 */
#define SDFM_SDCOMP3EVT2FLTCTL_SAMPWIN_Set(x) (((uint16_t) (x) << SDFM_SDCOMP3EVT2FLTCTL_SAMPWIN_Pos) & SDFM_SDCOMP3EVT2FLTCTL_SAMPWIN_Msk) /*!< SAMPWIN Set Value            */
#define SDFM_SDCOMP3EVT2FLTCTL_SAMPWIN_Get(x) (((uint16_t) (x) & SDFM_SDCOMP3EVT2FLTCTL_SAMPWIN_Msk) >> SDFM_SDCOMP3EVT2FLTCTL_SAMPWIN_Pos) /*!< SAMPWIN Get Value            */


/* SDCOMP3EVT2FLTCLKCTL bitfield */
#define SDFM_SDCOMP3EVT2FLTCLKCTL_CLKPRESCALE_Pos    (0U)                                                                                  /*!< CLKPRESCALE Postion   0          */ 
#define SDFM_SDCOMP3EVT2FLTCLKCTL_CLKPRESCALE_Msk    (0x3ffU << SDFM_SDCOMP3EVT2FLTCLKCTL_CLKPRESCALE_Pos)                            /*!< CLKPRESCALE Mask      0x000003FF */
#define SDFM_SDCOMP3EVT2FLTCLKCTL_CLKPRESCALE_Set(x) (((uint16_t) (x) << SDFM_SDCOMP3EVT2FLTCLKCTL_CLKPRESCALE_Pos) & SDFM_SDCOMP3EVT2FLTCLKCTL_CLKPRESCALE_Msk) /*!< CLKPRESCALE Set Value            */
#define SDFM_SDCOMP3EVT2FLTCLKCTL_CLKPRESCALE_Get(x) (((uint16_t) (x) & SDFM_SDCOMP3EVT2FLTCLKCTL_CLKPRESCALE_Msk) >> SDFM_SDCOMP3EVT2FLTCLKCTL_CLKPRESCALE_Pos) /*!< CLKPRESCALE Get Value            */


/* SDCOMP3EVT1FLTCTL bitfield */
#define SDFM_SDCOMP3EVT1FLTCTL_FILINIT_Pos    (15U)                                                                                 /*!< FILINIT Postion   15         */ 
#define SDFM_SDCOMP3EVT1FLTCTL_FILINIT_Msk    (0x1U << SDFM_SDCOMP3EVT1FLTCTL_FILINIT_Pos)                                     /*!< FILINIT Mask      0x00008000 */
#define SDFM_SDCOMP3EVT1FLTCTL_FILINIT_Set(x) (((uint16_t) (x) << SDFM_SDCOMP3EVT1FLTCTL_FILINIT_Pos) & SDFM_SDCOMP3EVT1FLTCTL_FILINIT_Msk) /*!< FILINIT Set Value            */
#define SDFM_SDCOMP3EVT1FLTCTL_FILINIT_Get(x) (((uint16_t) (x) & SDFM_SDCOMP3EVT1FLTCTL_FILINIT_Msk) >> SDFM_SDCOMP3EVT1FLTCTL_FILINIT_Pos) /*!< FILINIT Get Value            */


#define SDFM_SDCOMP3EVT1FLTCTL_THRESH_Pos    (9U)                                                                                  /*!< THRESH Postion   9          */ 
#define SDFM_SDCOMP3EVT1FLTCTL_THRESH_Msk    (0x1fU << SDFM_SDCOMP3EVT1FLTCTL_THRESH_Pos)                                     /*!< THRESH Mask      0x00003E00 */
#define SDFM_SDCOMP3EVT1FLTCTL_THRESH_Set(x) (((uint16_t) (x) << SDFM_SDCOMP3EVT1FLTCTL_THRESH_Pos) & SDFM_SDCOMP3EVT1FLTCTL_THRESH_Msk) /*!< THRESH Set Value            */
#define SDFM_SDCOMP3EVT1FLTCTL_THRESH_Get(x) (((uint16_t) (x) & SDFM_SDCOMP3EVT1FLTCTL_THRESH_Msk) >> SDFM_SDCOMP3EVT1FLTCTL_THRESH_Pos) /*!< THRESH Get Value            */


#define SDFM_SDCOMP3EVT1FLTCTL_SAMPWIN_Pos    (4U)                                                                                  /*!< SAMPWIN Postion   4          */ 
#define SDFM_SDCOMP3EVT1FLTCTL_SAMPWIN_Msk    (0x1fU << SDFM_SDCOMP3EVT1FLTCTL_SAMPWIN_Pos)                                    /*!< SAMPWIN Mask      0x000001F0 */
#define SDFM_SDCOMP3EVT1FLTCTL_SAMPWIN_Set(x) (((uint16_t) (x) << SDFM_SDCOMP3EVT1FLTCTL_SAMPWIN_Pos) & SDFM_SDCOMP3EVT1FLTCTL_SAMPWIN_Msk) /*!< SAMPWIN Set Value            */
#define SDFM_SDCOMP3EVT1FLTCTL_SAMPWIN_Get(x) (((uint16_t) (x) & SDFM_SDCOMP3EVT1FLTCTL_SAMPWIN_Msk) >> SDFM_SDCOMP3EVT1FLTCTL_SAMPWIN_Pos) /*!< SAMPWIN Get Value            */


/* SDCOMP3EVT1FLTCLKCTL bitfield */
#define SDFM_SDCOMP3EVT1FLTCLKCTL_CLKPRESCALE_Pos    (0U)                                                                                  /*!< CLKPRESCALE Postion   0          */ 
#define SDFM_SDCOMP3EVT1FLTCLKCTL_CLKPRESCALE_Msk    (0x3ffU << SDFM_SDCOMP3EVT1FLTCLKCTL_CLKPRESCALE_Pos)                            /*!< CLKPRESCALE Mask      0x000003FF */
#define SDFM_SDCOMP3EVT1FLTCLKCTL_CLKPRESCALE_Set(x) (((uint16_t) (x) << SDFM_SDCOMP3EVT1FLTCLKCTL_CLKPRESCALE_Pos) & SDFM_SDCOMP3EVT1FLTCLKCTL_CLKPRESCALE_Msk) /*!< CLKPRESCALE Set Value            */
#define SDFM_SDCOMP3EVT1FLTCLKCTL_CLKPRESCALE_Get(x) (((uint16_t) (x) & SDFM_SDCOMP3EVT1FLTCLKCTL_CLKPRESCALE_Msk) >> SDFM_SDCOMP3EVT1FLTCLKCTL_CLKPRESCALE_Pos) /*!< CLKPRESCALE Get Value            */


/* RESERVED3 bitfield */
/* SDCOMP3LOCK bitfield */
#define SDFM_SDCOMP3LOCK_COMP_Pos    (3U)                                                                                  /*!< COMP Postion   3          */ 
#define SDFM_SDCOMP3LOCK_COMP_Msk    (0x1U << SDFM_SDCOMP3LOCK_COMP_Pos)                                              /*!< COMP Mask      0x00000008 */
#define SDFM_SDCOMP3LOCK_COMP_Set(x) (((uint16_t) (x) << SDFM_SDCOMP3LOCK_COMP_Pos) & SDFM_SDCOMP3LOCK_COMP_Msk) /*!< COMP Set Value            */
#define SDFM_SDCOMP3LOCK_COMP_Get(x) (((uint16_t) (x) & SDFM_SDCOMP3LOCK_COMP_Msk) >> SDFM_SDCOMP3LOCK_COMP_Pos) /*!< COMP Get Value            */


#define SDFM_SDCOMP3LOCK_SDCOMP3CTL_Pos    (0U)                                                                                  /*!< SDCOMP3CTL Postion   0          */ 
#define SDFM_SDCOMP3LOCK_SDCOMP3CTL_Msk    (0x1U << SDFM_SDCOMP3LOCK_SDCOMP3CTL_Pos)                                        /*!< SDCOMP3CTL Mask      0x00000001 */
#define SDFM_SDCOMP3LOCK_SDCOMP3CTL_Set(x) (((uint16_t) (x) << SDFM_SDCOMP3LOCK_SDCOMP3CTL_Pos) & SDFM_SDCOMP3LOCK_SDCOMP3CTL_Msk) /*!< SDCOMP3CTL Set Value            */
#define SDFM_SDCOMP3LOCK_SDCOMP3CTL_Get(x) (((uint16_t) (x) & SDFM_SDCOMP3LOCK_SDCOMP3CTL_Msk) >> SDFM_SDCOMP3LOCK_SDCOMP3CTL_Pos) /*!< SDCOMP3CTL Get Value            */


/* SDCOMP4CTL bitfield */
#define SDFM_SDCOMP4CTL_CEVT2DIGFILTSEL_Pos    (10U)                                                                                 /*!< CEVT2DIGFILTSEL Postion   10         */ 
#define SDFM_SDCOMP4CTL_CEVT2DIGFILTSEL_Msk    (0x3U << SDFM_SDCOMP4CTL_CEVT2DIGFILTSEL_Pos)                                    /*!< CEVT2DIGFILTSEL Mask      0x00000C00 */
#define SDFM_SDCOMP4CTL_CEVT2DIGFILTSEL_Set(x) (((uint16_t) (x) << SDFM_SDCOMP4CTL_CEVT2DIGFILTSEL_Pos) & SDFM_SDCOMP4CTL_CEVT2DIGFILTSEL_Msk) /*!< CEVT2DIGFILTSEL Set Value            */
#define SDFM_SDCOMP4CTL_CEVT2DIGFILTSEL_Get(x) (((uint16_t) (x) & SDFM_SDCOMP4CTL_CEVT2DIGFILTSEL_Msk) >> SDFM_SDCOMP4CTL_CEVT2DIGFILTSEL_Pos) /*!< CEVT2DIGFILTSEL Get Value            */


#define SDFM_SDCOMP4CTL_CEVT1DIGFILTSEL_Pos    (2U)                                                                                  /*!< CEVT1DIGFILTSEL Postion   2          */ 
#define SDFM_SDCOMP4CTL_CEVT1DIGFILTSEL_Msk    (0x3U << SDFM_SDCOMP4CTL_CEVT1DIGFILTSEL_Pos)                                    /*!< CEVT1DIGFILTSEL Mask      0x0000000C */
#define SDFM_SDCOMP4CTL_CEVT1DIGFILTSEL_Set(x) (((uint16_t) (x) << SDFM_SDCOMP4CTL_CEVT1DIGFILTSEL_Pos) & SDFM_SDCOMP4CTL_CEVT1DIGFILTSEL_Msk) /*!< CEVT1DIGFILTSEL Set Value            */
#define SDFM_SDCOMP4CTL_CEVT1DIGFILTSEL_Get(x) (((uint16_t) (x) & SDFM_SDCOMP4CTL_CEVT1DIGFILTSEL_Msk) >> SDFM_SDCOMP4CTL_CEVT1DIGFILTSEL_Pos) /*!< CEVT1DIGFILTSEL Get Value            */


/* SDCOMP4EVT2FLTCTL bitfield */
#define SDFM_SDCOMP4EVT2FLTCTL_FILINIT_Pos    (15U)                                                                                 /*!< FILINIT Postion   15         */ 
#define SDFM_SDCOMP4EVT2FLTCTL_FILINIT_Msk    (0x1U << SDFM_SDCOMP4EVT2FLTCTL_FILINIT_Pos)                                     /*!< FILINIT Mask      0x00008000 */
#define SDFM_SDCOMP4EVT2FLTCTL_FILINIT_Set(x) (((uint16_t) (x) << SDFM_SDCOMP4EVT2FLTCTL_FILINIT_Pos) & SDFM_SDCOMP4EVT2FLTCTL_FILINIT_Msk) /*!< FILINIT Set Value            */
#define SDFM_SDCOMP4EVT2FLTCTL_FILINIT_Get(x) (((uint16_t) (x) & SDFM_SDCOMP4EVT2FLTCTL_FILINIT_Msk) >> SDFM_SDCOMP4EVT2FLTCTL_FILINIT_Pos) /*!< FILINIT Get Value            */


#define SDFM_SDCOMP4EVT2FLTCTL_THRESH_Pos    (9U)                                                                                  /*!< THRESH Postion   9          */ 
#define SDFM_SDCOMP4EVT2FLTCTL_THRESH_Msk    (0x1fU << SDFM_SDCOMP4EVT2FLTCTL_THRESH_Pos)                                     /*!< THRESH Mask      0x00003E00 */
#define SDFM_SDCOMP4EVT2FLTCTL_THRESH_Set(x) (((uint16_t) (x) << SDFM_SDCOMP4EVT2FLTCTL_THRESH_Pos) & SDFM_SDCOMP4EVT2FLTCTL_THRESH_Msk) /*!< THRESH Set Value            */
#define SDFM_SDCOMP4EVT2FLTCTL_THRESH_Get(x) (((uint16_t) (x) & SDFM_SDCOMP4EVT2FLTCTL_THRESH_Msk) >> SDFM_SDCOMP4EVT2FLTCTL_THRESH_Pos) /*!< THRESH Get Value            */


#define SDFM_SDCOMP4EVT2FLTCTL_SAMPWIN_Pos    (4U)                                                                                  /*!< SAMPWIN Postion   4          */ 
#define SDFM_SDCOMP4EVT2FLTCTL_SAMPWIN_Msk    (0x1fU << SDFM_SDCOMP4EVT2FLTCTL_SAMPWIN_Pos)                                    /*!< SAMPWIN Mask      0x000001F0 */
#define SDFM_SDCOMP4EVT2FLTCTL_SAMPWIN_Set(x) (((uint16_t) (x) << SDFM_SDCOMP4EVT2FLTCTL_SAMPWIN_Pos) & SDFM_SDCOMP4EVT2FLTCTL_SAMPWIN_Msk) /*!< SAMPWIN Set Value            */
#define SDFM_SDCOMP4EVT2FLTCTL_SAMPWIN_Get(x) (((uint16_t) (x) & SDFM_SDCOMP4EVT2FLTCTL_SAMPWIN_Msk) >> SDFM_SDCOMP4EVT2FLTCTL_SAMPWIN_Pos) /*!< SAMPWIN Get Value            */


/* SDCOMP4EVT2FLTCLKCTL bitfield */
#define SDFM_SDCOMP4EVT2FLTCLKCTL_CLKPRESCALE_Pos    (0U)                                                                                  /*!< CLKPRESCALE Postion   0          */ 
#define SDFM_SDCOMP4EVT2FLTCLKCTL_CLKPRESCALE_Msk    (0x3ffU << SDFM_SDCOMP4EVT2FLTCLKCTL_CLKPRESCALE_Pos)                            /*!< CLKPRESCALE Mask      0x000003FF */
#define SDFM_SDCOMP4EVT2FLTCLKCTL_CLKPRESCALE_Set(x) (((uint16_t) (x) << SDFM_SDCOMP4EVT2FLTCLKCTL_CLKPRESCALE_Pos) & SDFM_SDCOMP4EVT2FLTCLKCTL_CLKPRESCALE_Msk) /*!< CLKPRESCALE Set Value            */
#define SDFM_SDCOMP4EVT2FLTCLKCTL_CLKPRESCALE_Get(x) (((uint16_t) (x) & SDFM_SDCOMP4EVT2FLTCLKCTL_CLKPRESCALE_Msk) >> SDFM_SDCOMP4EVT2FLTCLKCTL_CLKPRESCALE_Pos) /*!< CLKPRESCALE Get Value            */


/* SDCOMP4EVT1FLTCTL bitfield */
#define SDFM_SDCOMP4EVT1FLTCTL_FILINIT_Pos    (15U)                                                                                 /*!< FILINIT Postion   15         */ 
#define SDFM_SDCOMP4EVT1FLTCTL_FILINIT_Msk    (0x1U << SDFM_SDCOMP4EVT1FLTCTL_FILINIT_Pos)                                     /*!< FILINIT Mask      0x00008000 */
#define SDFM_SDCOMP4EVT1FLTCTL_FILINIT_Set(x) (((uint16_t) (x) << SDFM_SDCOMP4EVT1FLTCTL_FILINIT_Pos) & SDFM_SDCOMP4EVT1FLTCTL_FILINIT_Msk) /*!< FILINIT Set Value            */
#define SDFM_SDCOMP4EVT1FLTCTL_FILINIT_Get(x) (((uint16_t) (x) & SDFM_SDCOMP4EVT1FLTCTL_FILINIT_Msk) >> SDFM_SDCOMP4EVT1FLTCTL_FILINIT_Pos) /*!< FILINIT Get Value            */


#define SDFM_SDCOMP4EVT1FLTCTL_THRESH_Pos    (9U)                                                                                  /*!< THRESH Postion   9          */ 
#define SDFM_SDCOMP4EVT1FLTCTL_THRESH_Msk    (0x1fU << SDFM_SDCOMP4EVT1FLTCTL_THRESH_Pos)                                     /*!< THRESH Mask      0x00003E00 */
#define SDFM_SDCOMP4EVT1FLTCTL_THRESH_Set(x) (((uint16_t) (x) << SDFM_SDCOMP4EVT1FLTCTL_THRESH_Pos) & SDFM_SDCOMP4EVT1FLTCTL_THRESH_Msk) /*!< THRESH Set Value            */
#define SDFM_SDCOMP4EVT1FLTCTL_THRESH_Get(x) (((uint16_t) (x) & SDFM_SDCOMP4EVT1FLTCTL_THRESH_Msk) >> SDFM_SDCOMP4EVT1FLTCTL_THRESH_Pos) /*!< THRESH Get Value            */


#define SDFM_SDCOMP4EVT1FLTCTL_SAMPWIN_Pos    (4U)                                                                                  /*!< SAMPWIN Postion   4          */ 
#define SDFM_SDCOMP4EVT1FLTCTL_SAMPWIN_Msk    (0x1fU << SDFM_SDCOMP4EVT1FLTCTL_SAMPWIN_Pos)                                    /*!< SAMPWIN Mask      0x000001F0 */
#define SDFM_SDCOMP4EVT1FLTCTL_SAMPWIN_Set(x) (((uint16_t) (x) << SDFM_SDCOMP4EVT1FLTCTL_SAMPWIN_Pos) & SDFM_SDCOMP4EVT1FLTCTL_SAMPWIN_Msk) /*!< SAMPWIN Set Value            */
#define SDFM_SDCOMP4EVT1FLTCTL_SAMPWIN_Get(x) (((uint16_t) (x) & SDFM_SDCOMP4EVT1FLTCTL_SAMPWIN_Msk) >> SDFM_SDCOMP4EVT1FLTCTL_SAMPWIN_Pos) /*!< SAMPWIN Get Value            */


/* SDCOMP4EVT1FLTCLKCTL bitfield */
#define SDFM_SDCOMP4EVT1FLTCLKCTL_CLKPRESCALE_Pos    (0U)                                                                                  /*!< CLKPRESCALE Postion   0          */ 
#define SDFM_SDCOMP4EVT1FLTCLKCTL_CLKPRESCALE_Msk    (0x3ffU << SDFM_SDCOMP4EVT1FLTCLKCTL_CLKPRESCALE_Pos)                            /*!< CLKPRESCALE Mask      0x000003FF */
#define SDFM_SDCOMP4EVT1FLTCLKCTL_CLKPRESCALE_Set(x) (((uint16_t) (x) << SDFM_SDCOMP4EVT1FLTCLKCTL_CLKPRESCALE_Pos) & SDFM_SDCOMP4EVT1FLTCLKCTL_CLKPRESCALE_Msk) /*!< CLKPRESCALE Set Value            */
#define SDFM_SDCOMP4EVT1FLTCLKCTL_CLKPRESCALE_Get(x) (((uint16_t) (x) & SDFM_SDCOMP4EVT1FLTCLKCTL_CLKPRESCALE_Msk) >> SDFM_SDCOMP4EVT1FLTCLKCTL_CLKPRESCALE_Pos) /*!< CLKPRESCALE Get Value            */


/* RESERVED4 bitfield */
/* SDCOMP4LOCK bitfield */
#define SDFM_SDCOMP4LOCK_COMP_Pos    (3U)                                                                                  /*!< COMP Postion   3          */ 
#define SDFM_SDCOMP4LOCK_COMP_Msk    (0x1U << SDFM_SDCOMP4LOCK_COMP_Pos)                                              /*!< COMP Mask      0x00000008 */
#define SDFM_SDCOMP4LOCK_COMP_Set(x) (((uint16_t) (x) << SDFM_SDCOMP4LOCK_COMP_Pos) & SDFM_SDCOMP4LOCK_COMP_Msk) /*!< COMP Set Value            */
#define SDFM_SDCOMP4LOCK_COMP_Get(x) (((uint16_t) (x) & SDFM_SDCOMP4LOCK_COMP_Msk) >> SDFM_SDCOMP4LOCK_COMP_Pos) /*!< COMP Get Value            */


#define SDFM_SDCOMP4LOCK_SDCOMP4CTL_Pos    (0U)                                                                                  /*!< SDCOMP4CTL Postion   0          */ 
#define SDFM_SDCOMP4LOCK_SDCOMP4CTL_Msk    (0x1U << SDFM_SDCOMP4LOCK_SDCOMP4CTL_Pos)                                        /*!< SDCOMP4CTL Mask      0x00000001 */
#define SDFM_SDCOMP4LOCK_SDCOMP4CTL_Set(x) (((uint16_t) (x) << SDFM_SDCOMP4LOCK_SDCOMP4CTL_Pos) & SDFM_SDCOMP4LOCK_SDCOMP4CTL_Msk) /*!< SDCOMP4CTL Set Value            */
#define SDFM_SDCOMP4LOCK_SDCOMP4CTL_Get(x) (((uint16_t) (x) & SDFM_SDCOMP4LOCK_SDCOMP4CTL_Msk) >> SDFM_SDCOMP4LOCK_SDCOMP4CTL_Pos) /*!< SDCOMP4CTL Get Value            */


/* SDDMAEN bitfield */
#define SDFM_SDDMAEN_DMAEN4_Pos    (11U)                                                                                 /*!< DMAEN4 Postion   11         */ 
#define SDFM_SDDMAEN_DMAEN4_Msk    (0x1U << SDFM_SDDMAEN_DMAEN4_Pos)                                                /*!< DMAEN4 Mask      0x00000800 */
#define SDFM_SDDMAEN_DMAEN4_Set(x) (((uint32_t) (x) << SDFM_SDDMAEN_DMAEN4_Pos) & SDFM_SDDMAEN_DMAEN4_Msk)     /*!< DMAEN4 Set Value            */
#define SDFM_SDDMAEN_DMAEN4_Get(x) (((uint32_t) (x) & SDFM_SDDMAEN_DMAEN4_Msk) >> SDFM_SDDMAEN_DMAEN4_Pos)     /*!< DMAEN4 Get Value            */


#define SDFM_SDDMAEN_DMAEN3_Pos    (10U)                                                                                 /*!< DMAEN3 Postion   10         */ 
#define SDFM_SDDMAEN_DMAEN3_Msk    (0x1U << SDFM_SDDMAEN_DMAEN3_Pos)                                                /*!< DMAEN3 Mask      0x00000400 */
#define SDFM_SDDMAEN_DMAEN3_Set(x) (((uint32_t) (x) << SDFM_SDDMAEN_DMAEN3_Pos) & SDFM_SDDMAEN_DMAEN3_Msk)     /*!< DMAEN3 Set Value            */
#define SDFM_SDDMAEN_DMAEN3_Get(x) (((uint32_t) (x) & SDFM_SDDMAEN_DMAEN3_Msk) >> SDFM_SDDMAEN_DMAEN3_Pos)     /*!< DMAEN3 Get Value            */


#define SDFM_SDDMAEN_DMAEN2_Pos    (9U)                                                                                  /*!< DMAEN2 Postion   9          */ 
#define SDFM_SDDMAEN_DMAEN2_Msk    (0x1U << SDFM_SDDMAEN_DMAEN2_Pos)                                                /*!< DMAEN2 Mask      0x00000200 */
#define SDFM_SDDMAEN_DMAEN2_Set(x) (((uint32_t) (x) << SDFM_SDDMAEN_DMAEN2_Pos) & SDFM_SDDMAEN_DMAEN2_Msk)     /*!< DMAEN2 Set Value            */
#define SDFM_SDDMAEN_DMAEN2_Get(x) (((uint32_t) (x) & SDFM_SDDMAEN_DMAEN2_Msk) >> SDFM_SDDMAEN_DMAEN2_Pos)     /*!< DMAEN2 Get Value            */


#define SDFM_SDDMAEN_DMAEN1_Pos    (8U)                                                                                  /*!< DMAEN1 Postion   8          */ 
#define SDFM_SDDMAEN_DMAEN1_Msk    (0x1U << SDFM_SDDMAEN_DMAEN1_Pos)                                                /*!< DMAEN1 Mask      0x00000100 */
#define SDFM_SDDMAEN_DMAEN1_Set(x) (((uint32_t) (x) << SDFM_SDDMAEN_DMAEN1_Pos) & SDFM_SDDMAEN_DMAEN1_Msk)     /*!< DMAEN1 Set Value            */
#define SDFM_SDDMAEN_DMAEN1_Get(x) (((uint32_t) (x) & SDFM_SDDMAEN_DMAEN1_Msk) >> SDFM_SDDMAEN_DMAEN1_Pos)     /*!< DMAEN1 Get Value            */


#define SDFM_SDDMAEN_FFDMAEN4_Pos    (3U)                                                                                  /*!< FFDMAEN4 Postion   3          */ 
#define SDFM_SDDMAEN_FFDMAEN4_Msk    (0x1U << SDFM_SDDMAEN_FFDMAEN4_Pos)                                              /*!< FFDMAEN4 Mask      0x00000008 */
#define SDFM_SDDMAEN_FFDMAEN4_Set(x) (((uint32_t) (x) << SDFM_SDDMAEN_FFDMAEN4_Pos) & SDFM_SDDMAEN_FFDMAEN4_Msk) /*!< FFDMAEN4 Set Value            */
#define SDFM_SDDMAEN_FFDMAEN4_Get(x) (((uint32_t) (x) & SDFM_SDDMAEN_FFDMAEN4_Msk) >> SDFM_SDDMAEN_FFDMAEN4_Pos) /*!< FFDMAEN4 Get Value            */


#define SDFM_SDDMAEN_FFDMAEN3_Pos    (2U)                                                                                  /*!< FFDMAEN3 Postion   2          */ 
#define SDFM_SDDMAEN_FFDMAEN3_Msk    (0x1U << SDFM_SDDMAEN_FFDMAEN3_Pos)                                              /*!< FFDMAEN3 Mask      0x00000004 */
#define SDFM_SDDMAEN_FFDMAEN3_Set(x) (((uint32_t) (x) << SDFM_SDDMAEN_FFDMAEN3_Pos) & SDFM_SDDMAEN_FFDMAEN3_Msk) /*!< FFDMAEN3 Set Value            */
#define SDFM_SDDMAEN_FFDMAEN3_Get(x) (((uint32_t) (x) & SDFM_SDDMAEN_FFDMAEN3_Msk) >> SDFM_SDDMAEN_FFDMAEN3_Pos) /*!< FFDMAEN3 Get Value            */


#define SDFM_SDDMAEN_FFDMAEN2_Pos    (1U)                                                                                  /*!< FFDMAEN2 Postion   1          */ 
#define SDFM_SDDMAEN_FFDMAEN2_Msk    (0x1U << SDFM_SDDMAEN_FFDMAEN2_Pos)                                              /*!< FFDMAEN2 Mask      0x00000002 */
#define SDFM_SDDMAEN_FFDMAEN2_Set(x) (((uint32_t) (x) << SDFM_SDDMAEN_FFDMAEN2_Pos) & SDFM_SDDMAEN_FFDMAEN2_Msk) /*!< FFDMAEN2 Set Value            */
#define SDFM_SDDMAEN_FFDMAEN2_Get(x) (((uint32_t) (x) & SDFM_SDDMAEN_FFDMAEN2_Msk) >> SDFM_SDDMAEN_FFDMAEN2_Pos) /*!< FFDMAEN2 Get Value            */


#define SDFM_SDDMAEN_FFDMAEN1_Pos    (0U)                                                                                  /*!< FFDMAEN1 Postion   0          */ 
#define SDFM_SDDMAEN_FFDMAEN1_Msk    (0x1U << SDFM_SDDMAEN_FFDMAEN1_Pos)                                              /*!< FFDMAEN1 Mask      0x00000001 */
#define SDFM_SDDMAEN_FFDMAEN1_Set(x) (((uint32_t) (x) << SDFM_SDDMAEN_FFDMAEN1_Pos) & SDFM_SDDMAEN_FFDMAEN1_Msk) /*!< FFDMAEN1 Set Value            */
#define SDFM_SDDMAEN_FFDMAEN1_Get(x) (((uint32_t) (x) & SDFM_SDDMAEN_FFDMAEN1_Msk) >> SDFM_SDDMAEN_FFDMAEN1_Pos) /*!< FFDMAEN1 Get Value            */


/* SDDMAFLG bitfield */
#define SDFM_SDDMAFLG_DMAFLG4_Pos    (11U)                                                                                 /*!< DMAFLG4 Postion   11         */ 
#define SDFM_SDDMAFLG_DMAFLG4_Msk    (0x1U << SDFM_SDDMAFLG_DMAFLG4_Pos)                                              /*!< DMAFLG4 Mask      0x00000800 */
#define SDFM_SDDMAFLG_DMAFLG4_Set(x) (((uint32_t) (x) << SDFM_SDDMAFLG_DMAFLG4_Pos) & SDFM_SDDMAFLG_DMAFLG4_Msk) /*!< DMAFLG4 Set Value            */
#define SDFM_SDDMAFLG_DMAFLG4_Get(x) (((uint32_t) (x) & SDFM_SDDMAFLG_DMAFLG4_Msk) >> SDFM_SDDMAFLG_DMAFLG4_Pos) /*!< DMAFLG4 Get Value            */


#define SDFM_SDDMAFLG_DMAFLG3_Pos    (10U)                                                                                 /*!< DMAFLG3 Postion   10         */ 
#define SDFM_SDDMAFLG_DMAFLG3_Msk    (0x1U << SDFM_SDDMAFLG_DMAFLG3_Pos)                                              /*!< DMAFLG3 Mask      0x00000400 */
#define SDFM_SDDMAFLG_DMAFLG3_Set(x) (((uint32_t) (x) << SDFM_SDDMAFLG_DMAFLG3_Pos) & SDFM_SDDMAFLG_DMAFLG3_Msk) /*!< DMAFLG3 Set Value            */
#define SDFM_SDDMAFLG_DMAFLG3_Get(x) (((uint32_t) (x) & SDFM_SDDMAFLG_DMAFLG3_Msk) >> SDFM_SDDMAFLG_DMAFLG3_Pos) /*!< DMAFLG3 Get Value            */


#define SDFM_SDDMAFLG_DMAFLG2_Pos    (9U)                                                                                  /*!< DMAFLG2 Postion   9          */ 
#define SDFM_SDDMAFLG_DMAFLG2_Msk    (0x1U << SDFM_SDDMAFLG_DMAFLG2_Pos)                                              /*!< DMAFLG2 Mask      0x00000200 */
#define SDFM_SDDMAFLG_DMAFLG2_Set(x) (((uint32_t) (x) << SDFM_SDDMAFLG_DMAFLG2_Pos) & SDFM_SDDMAFLG_DMAFLG2_Msk) /*!< DMAFLG2 Set Value            */
#define SDFM_SDDMAFLG_DMAFLG2_Get(x) (((uint32_t) (x) & SDFM_SDDMAFLG_DMAFLG2_Msk) >> SDFM_SDDMAFLG_DMAFLG2_Pos) /*!< DMAFLG2 Get Value            */


#define SDFM_SDDMAFLG_DMAFLG1_Pos    (8U)                                                                                  /*!< DMAFLG1 Postion   8          */ 
#define SDFM_SDDMAFLG_DMAFLG1_Msk    (0x1U << SDFM_SDDMAFLG_DMAFLG1_Pos)                                              /*!< DMAFLG1 Mask      0x00000100 */
#define SDFM_SDDMAFLG_DMAFLG1_Set(x) (((uint32_t) (x) << SDFM_SDDMAFLG_DMAFLG1_Pos) & SDFM_SDDMAFLG_DMAFLG1_Msk) /*!< DMAFLG1 Set Value            */
#define SDFM_SDDMAFLG_DMAFLG1_Get(x) (((uint32_t) (x) & SDFM_SDDMAFLG_DMAFLG1_Msk) >> SDFM_SDDMAFLG_DMAFLG1_Pos) /*!< DMAFLG1 Get Value            */


#define SDFM_SDDMAFLG_FFDMA4_Pos    (3U)                                                                                  /*!< FFDMA4 Postion   3          */ 
#define SDFM_SDDMAFLG_FFDMA4_Msk    (0x1U << SDFM_SDDMAFLG_FFDMA4_Pos)                                               /*!< FFDMA4 Mask      0x00000008 */
#define SDFM_SDDMAFLG_FFDMA4_Set(x) (((uint32_t) (x) << SDFM_SDDMAFLG_FFDMA4_Pos) & SDFM_SDDMAFLG_FFDMA4_Msk)   /*!< FFDMA4 Set Value            */
#define SDFM_SDDMAFLG_FFDMA4_Get(x) (((uint32_t) (x) & SDFM_SDDMAFLG_FFDMA4_Msk) >> SDFM_SDDMAFLG_FFDMA4_Pos)   /*!< FFDMA4 Get Value            */


#define SDFM_SDDMAFLG_FFDMA3_Pos    (2U)                                                                                  /*!< FFDMA3 Postion   2          */ 
#define SDFM_SDDMAFLG_FFDMA3_Msk    (0x1U << SDFM_SDDMAFLG_FFDMA3_Pos)                                               /*!< FFDMA3 Mask      0x00000004 */
#define SDFM_SDDMAFLG_FFDMA3_Set(x) (((uint32_t) (x) << SDFM_SDDMAFLG_FFDMA3_Pos) & SDFM_SDDMAFLG_FFDMA3_Msk)   /*!< FFDMA3 Set Value            */
#define SDFM_SDDMAFLG_FFDMA3_Get(x) (((uint32_t) (x) & SDFM_SDDMAFLG_FFDMA3_Msk) >> SDFM_SDDMAFLG_FFDMA3_Pos)   /*!< FFDMA3 Get Value            */


#define SDFM_SDDMAFLG_FFDMA2_Pos    (1U)                                                                                  /*!< FFDMA2 Postion   1          */ 
#define SDFM_SDDMAFLG_FFDMA2_Msk    (0x1U << SDFM_SDDMAFLG_FFDMA2_Pos)                                               /*!< FFDMA2 Mask      0x00000002 */
#define SDFM_SDDMAFLG_FFDMA2_Set(x) (((uint32_t) (x) << SDFM_SDDMAFLG_FFDMA2_Pos) & SDFM_SDDMAFLG_FFDMA2_Msk)   /*!< FFDMA2 Set Value            */
#define SDFM_SDDMAFLG_FFDMA2_Get(x) (((uint32_t) (x) & SDFM_SDDMAFLG_FFDMA2_Msk) >> SDFM_SDDMAFLG_FFDMA2_Pos)   /*!< FFDMA2 Get Value            */


#define SDFM_SDDMAFLG_FFDMA1_Pos    (0U)                                                                                  /*!< FFDMA1 Postion   0          */ 
#define SDFM_SDDMAFLG_FFDMA1_Msk    (0x1U << SDFM_SDDMAFLG_FFDMA1_Pos)                                               /*!< FFDMA1 Mask      0x00000001 */
#define SDFM_SDDMAFLG_FFDMA1_Set(x) (((uint32_t) (x) << SDFM_SDDMAFLG_FFDMA1_Pos) & SDFM_SDDMAFLG_FFDMA1_Msk)   /*!< FFDMA1 Set Value            */
#define SDFM_SDDMAFLG_FFDMA1_Get(x) (((uint32_t) (x) & SDFM_SDDMAFLG_FFDMA1_Msk) >> SDFM_SDDMAFLG_FFDMA1_Pos)   /*!< FFDMA1 Get Value            */


/* SDMAXDATA1 bitfield */
#define SDFM_SDMAXDATA1_MAXDATA32HI_Pos    (16U)                                                                                 /*!< MAXDATA32HI Postion   16         */ 
#define SDFM_SDMAXDATA1_MAXDATA32HI_Msk    (0xffffU << SDFM_SDMAXDATA1_MAXDATA32HI_Pos)                                     /*!< MAXDATA32HI Mask      0xFFFF0000 */
#define SDFM_SDMAXDATA1_MAXDATA32HI_Set(x) (((uint32_t) (x) << SDFM_SDMAXDATA1_MAXDATA32HI_Pos) & SDFM_SDMAXDATA1_MAXDATA32HI_Msk) /*!< MAXDATA32HI Set Value            */
#define SDFM_SDMAXDATA1_MAXDATA32HI_Get(x) (((uint32_t) (x) & SDFM_SDMAXDATA1_MAXDATA32HI_Msk) >> SDFM_SDMAXDATA1_MAXDATA32HI_Pos) /*!< MAXDATA32HI Get Value            */


#define SDFM_SDMAXDATA1_MAXDATA16_Pos    (0U)                                                                                  /*!< MAXDATA16 Postion   0          */ 
#define SDFM_SDMAXDATA1_MAXDATA16_Msk    (0xffffU << SDFM_SDMAXDATA1_MAXDATA16_Pos)                                       /*!< MAXDATA16 Mask      0x0000FFFF */
#define SDFM_SDMAXDATA1_MAXDATA16_Set(x) (((uint32_t) (x) << SDFM_SDMAXDATA1_MAXDATA16_Pos) & SDFM_SDMAXDATA1_MAXDATA16_Msk) /*!< MAXDATA16 Set Value            */
#define SDFM_SDMAXDATA1_MAXDATA16_Get(x) (((uint32_t) (x) & SDFM_SDMAXDATA1_MAXDATA16_Msk) >> SDFM_SDMAXDATA1_MAXDATA16_Pos) /*!< MAXDATA16 Get Value            */


/* SDMINDATA1 bitfield */
#define SDFM_SDMINDATA1_MINDATA32HI_Pos    (16U)                                                                                 /*!< MINDATA32HI Postion   16         */ 
#define SDFM_SDMINDATA1_MINDATA32HI_Msk    (0xffffU << SDFM_SDMINDATA1_MINDATA32HI_Pos)                                     /*!< MINDATA32HI Mask      0xFFFF0000 */
#define SDFM_SDMINDATA1_MINDATA32HI_Set(x) (((uint32_t) (x) << SDFM_SDMINDATA1_MINDATA32HI_Pos) & SDFM_SDMINDATA1_MINDATA32HI_Msk) /*!< MINDATA32HI Set Value            */
#define SDFM_SDMINDATA1_MINDATA32HI_Get(x) (((uint32_t) (x) & SDFM_SDMINDATA1_MINDATA32HI_Msk) >> SDFM_SDMINDATA1_MINDATA32HI_Pos) /*!< MINDATA32HI Get Value            */


#define SDFM_SDMINDATA1_MINDATA16_Pos    (0U)                                                                                  /*!< MINDATA16 Postion   0          */ 
#define SDFM_SDMINDATA1_MINDATA16_Msk    (0xffffU << SDFM_SDMINDATA1_MINDATA16_Pos)                                       /*!< MINDATA16 Mask      0x0000FFFF */
#define SDFM_SDMINDATA1_MINDATA16_Set(x) (((uint32_t) (x) << SDFM_SDMINDATA1_MINDATA16_Pos) & SDFM_SDMINDATA1_MINDATA16_Msk) /*!< MINDATA16 Set Value            */
#define SDFM_SDMINDATA1_MINDATA16_Get(x) (((uint32_t) (x) & SDFM_SDMINDATA1_MINDATA16_Msk) >> SDFM_SDMINDATA1_MINDATA16_Pos) /*!< MINDATA16 Get Value            */


/* SDMAXDATA2 bitfield */
#define SDFM_SDMAXDATA2_MAXDATA32HI_Pos    (16U)                                                                                 /*!< MAXDATA32HI Postion   16         */ 
#define SDFM_SDMAXDATA2_MAXDATA32HI_Msk    (0xffffU << SDFM_SDMAXDATA2_MAXDATA32HI_Pos)                                     /*!< MAXDATA32HI Mask      0xFFFF0000 */
#define SDFM_SDMAXDATA2_MAXDATA32HI_Set(x) (((uint32_t) (x) << SDFM_SDMAXDATA2_MAXDATA32HI_Pos) & SDFM_SDMAXDATA2_MAXDATA32HI_Msk) /*!< MAXDATA32HI Set Value            */
#define SDFM_SDMAXDATA2_MAXDATA32HI_Get(x) (((uint32_t) (x) & SDFM_SDMAXDATA2_MAXDATA32HI_Msk) >> SDFM_SDMAXDATA2_MAXDATA32HI_Pos) /*!< MAXDATA32HI Get Value            */


#define SDFM_SDMAXDATA2_MAXDATA16_Pos    (0U)                                                                                  /*!< MAXDATA16 Postion   0          */ 
#define SDFM_SDMAXDATA2_MAXDATA16_Msk    (0xffffU << SDFM_SDMAXDATA2_MAXDATA16_Pos)                                       /*!< MAXDATA16 Mask      0x0000FFFF */
#define SDFM_SDMAXDATA2_MAXDATA16_Set(x) (((uint32_t) (x) << SDFM_SDMAXDATA2_MAXDATA16_Pos) & SDFM_SDMAXDATA2_MAXDATA16_Msk) /*!< MAXDATA16 Set Value            */
#define SDFM_SDMAXDATA2_MAXDATA16_Get(x) (((uint32_t) (x) & SDFM_SDMAXDATA2_MAXDATA16_Msk) >> SDFM_SDMAXDATA2_MAXDATA16_Pos) /*!< MAXDATA16 Get Value            */


/* SDMINDATA2 bitfield */
#define SDFM_SDMINDATA2_MINDATA32HI_Pos    (16U)                                                                                 /*!< MINDATA32HI Postion   16         */ 
#define SDFM_SDMINDATA2_MINDATA32HI_Msk    (0xffffU << SDFM_SDMINDATA2_MINDATA32HI_Pos)                                     /*!< MINDATA32HI Mask      0xFFFF0000 */
#define SDFM_SDMINDATA2_MINDATA32HI_Set(x) (((uint32_t) (x) << SDFM_SDMINDATA2_MINDATA32HI_Pos) & SDFM_SDMINDATA2_MINDATA32HI_Msk) /*!< MINDATA32HI Set Value            */
#define SDFM_SDMINDATA2_MINDATA32HI_Get(x) (((uint32_t) (x) & SDFM_SDMINDATA2_MINDATA32HI_Msk) >> SDFM_SDMINDATA2_MINDATA32HI_Pos) /*!< MINDATA32HI Get Value            */


#define SDFM_SDMINDATA2_MINDATA16_Pos    (0U)                                                                                  /*!< MINDATA16 Postion   0          */ 
#define SDFM_SDMINDATA2_MINDATA16_Msk    (0xffffU << SDFM_SDMINDATA2_MINDATA16_Pos)                                       /*!< MINDATA16 Mask      0x0000FFFF */
#define SDFM_SDMINDATA2_MINDATA16_Set(x) (((uint32_t) (x) << SDFM_SDMINDATA2_MINDATA16_Pos) & SDFM_SDMINDATA2_MINDATA16_Msk) /*!< MINDATA16 Set Value            */
#define SDFM_SDMINDATA2_MINDATA16_Get(x) (((uint32_t) (x) & SDFM_SDMINDATA2_MINDATA16_Msk) >> SDFM_SDMINDATA2_MINDATA16_Pos) /*!< MINDATA16 Get Value            */


/* SDMAXDATA3 bitfield */
#define SDFM_SDMAXDATA3_MAXDATA32HI_Pos    (16U)                                                                                 /*!< MAXDATA32HI Postion   16         */ 
#define SDFM_SDMAXDATA3_MAXDATA32HI_Msk    (0xffffU << SDFM_SDMAXDATA3_MAXDATA32HI_Pos)                                     /*!< MAXDATA32HI Mask      0xFFFF0000 */
#define SDFM_SDMAXDATA3_MAXDATA32HI_Set(x) (((uint32_t) (x) << SDFM_SDMAXDATA3_MAXDATA32HI_Pos) & SDFM_SDMAXDATA3_MAXDATA32HI_Msk) /*!< MAXDATA32HI Set Value            */
#define SDFM_SDMAXDATA3_MAXDATA32HI_Get(x) (((uint32_t) (x) & SDFM_SDMAXDATA3_MAXDATA32HI_Msk) >> SDFM_SDMAXDATA3_MAXDATA32HI_Pos) /*!< MAXDATA32HI Get Value            */


#define SDFM_SDMAXDATA3_MAXDATA16_Pos    (0U)                                                                                  /*!< MAXDATA16 Postion   0          */ 
#define SDFM_SDMAXDATA3_MAXDATA16_Msk    (0xffffU << SDFM_SDMAXDATA3_MAXDATA16_Pos)                                       /*!< MAXDATA16 Mask      0x0000FFFF */
#define SDFM_SDMAXDATA3_MAXDATA16_Set(x) (((uint32_t) (x) << SDFM_SDMAXDATA3_MAXDATA16_Pos) & SDFM_SDMAXDATA3_MAXDATA16_Msk) /*!< MAXDATA16 Set Value            */
#define SDFM_SDMAXDATA3_MAXDATA16_Get(x) (((uint32_t) (x) & SDFM_SDMAXDATA3_MAXDATA16_Msk) >> SDFM_SDMAXDATA3_MAXDATA16_Pos) /*!< MAXDATA16 Get Value            */


/* SDMINDATA3 bitfield */
#define SDFM_SDMINDATA3_MINDATA32HI_Pos    (16U)                                                                                 /*!< MINDATA32HI Postion   16         */ 
#define SDFM_SDMINDATA3_MINDATA32HI_Msk    (0xffffU << SDFM_SDMINDATA3_MINDATA32HI_Pos)                                     /*!< MINDATA32HI Mask      0xFFFF0000 */
#define SDFM_SDMINDATA3_MINDATA32HI_Set(x) (((uint32_t) (x) << SDFM_SDMINDATA3_MINDATA32HI_Pos) & SDFM_SDMINDATA3_MINDATA32HI_Msk) /*!< MINDATA32HI Set Value            */
#define SDFM_SDMINDATA3_MINDATA32HI_Get(x) (((uint32_t) (x) & SDFM_SDMINDATA3_MINDATA32HI_Msk) >> SDFM_SDMINDATA3_MINDATA32HI_Pos) /*!< MINDATA32HI Get Value            */


#define SDFM_SDMINDATA3_MINDATA16_Pos    (0U)                                                                                  /*!< MINDATA16 Postion   0          */ 
#define SDFM_SDMINDATA3_MINDATA16_Msk    (0xffffU << SDFM_SDMINDATA3_MINDATA16_Pos)                                       /*!< MINDATA16 Mask      0x0000FFFF */
#define SDFM_SDMINDATA3_MINDATA16_Set(x) (((uint32_t) (x) << SDFM_SDMINDATA3_MINDATA16_Pos) & SDFM_SDMINDATA3_MINDATA16_Msk) /*!< MINDATA16 Set Value            */
#define SDFM_SDMINDATA3_MINDATA16_Get(x) (((uint32_t) (x) & SDFM_SDMINDATA3_MINDATA16_Msk) >> SDFM_SDMINDATA3_MINDATA16_Pos) /*!< MINDATA16 Get Value            */


/* SDMAXDATA4 bitfield */
#define SDFM_SDMAXDATA4_MAXDATA32HI_Pos    (16U)                                                                                 /*!< MAXDATA32HI Postion   16         */ 
#define SDFM_SDMAXDATA4_MAXDATA32HI_Msk    (0xffffU << SDFM_SDMAXDATA4_MAXDATA32HI_Pos)                                     /*!< MAXDATA32HI Mask      0xFFFF0000 */
#define SDFM_SDMAXDATA4_MAXDATA32HI_Set(x) (((uint32_t) (x) << SDFM_SDMAXDATA4_MAXDATA32HI_Pos) & SDFM_SDMAXDATA4_MAXDATA32HI_Msk) /*!< MAXDATA32HI Set Value            */
#define SDFM_SDMAXDATA4_MAXDATA32HI_Get(x) (((uint32_t) (x) & SDFM_SDMAXDATA4_MAXDATA32HI_Msk) >> SDFM_SDMAXDATA4_MAXDATA32HI_Pos) /*!< MAXDATA32HI Get Value            */


#define SDFM_SDMAXDATA4_MAXDATA16_Pos    (0U)                                                                                  /*!< MAXDATA16 Postion   0          */ 
#define SDFM_SDMAXDATA4_MAXDATA16_Msk    (0xffffU << SDFM_SDMAXDATA4_MAXDATA16_Pos)                                       /*!< MAXDATA16 Mask      0x0000FFFF */
#define SDFM_SDMAXDATA4_MAXDATA16_Set(x) (((uint32_t) (x) << SDFM_SDMAXDATA4_MAXDATA16_Pos) & SDFM_SDMAXDATA4_MAXDATA16_Msk) /*!< MAXDATA16 Set Value            */
#define SDFM_SDMAXDATA4_MAXDATA16_Get(x) (((uint32_t) (x) & SDFM_SDMAXDATA4_MAXDATA16_Msk) >> SDFM_SDMAXDATA4_MAXDATA16_Pos) /*!< MAXDATA16 Get Value            */


/* SDMINDATA4 bitfield */
#define SDFM_SDMINDATA4_MINDATA32HI_Pos    (16U)                                                                                 /*!< MINDATA32HI Postion   16         */ 
#define SDFM_SDMINDATA4_MINDATA32HI_Msk    (0xffffU << SDFM_SDMINDATA4_MINDATA32HI_Pos)                                     /*!< MINDATA32HI Mask      0xFFFF0000 */
#define SDFM_SDMINDATA4_MINDATA32HI_Set(x) (((uint32_t) (x) << SDFM_SDMINDATA4_MINDATA32HI_Pos) & SDFM_SDMINDATA4_MINDATA32HI_Msk) /*!< MINDATA32HI Set Value            */
#define SDFM_SDMINDATA4_MINDATA32HI_Get(x) (((uint32_t) (x) & SDFM_SDMINDATA4_MINDATA32HI_Msk) >> SDFM_SDMINDATA4_MINDATA32HI_Pos) /*!< MINDATA32HI Get Value            */


#define SDFM_SDMINDATA4_MINDATA16_Pos    (0U)                                                                                  /*!< MINDATA16 Postion   0          */ 
#define SDFM_SDMINDATA4_MINDATA16_Msk    (0xffffU << SDFM_SDMINDATA4_MINDATA16_Pos)                                       /*!< MINDATA16 Mask      0x0000FFFF */
#define SDFM_SDMINDATA4_MINDATA16_Set(x) (((uint32_t) (x) << SDFM_SDMINDATA4_MINDATA16_Pos) & SDFM_SDMINDATA4_MINDATA16_Msk) /*!< MINDATA16 Set Value            */
#define SDFM_SDMINDATA4_MINDATA16_Get(x) (((uint32_t) (x) & SDFM_SDMINDATA4_MINDATA16_Msk) >> SDFM_SDMINDATA4_MINDATA16_Pos) /*!< MINDATA16 Get Value            */


/* SDCMAXDATA1 bitfield */
#define SDFM_SDCMAXDATA1_MAXDATA16_Pos    (0U)                                                                                  /*!< MAXDATA16 Postion   0          */ 
#define SDFM_SDCMAXDATA1_MAXDATA16_Msk    (0xffffU << SDFM_SDCMAXDATA1_MAXDATA16_Pos)                                      /*!< MAXDATA16 Mask      0x0000FFFF */
#define SDFM_SDCMAXDATA1_MAXDATA16_Set(x) (((uint32_t) (x) << SDFM_SDCMAXDATA1_MAXDATA16_Pos) & SDFM_SDCMAXDATA1_MAXDATA16_Msk) /*!< MAXDATA16 Set Value            */
#define SDFM_SDCMAXDATA1_MAXDATA16_Get(x) (((uint32_t) (x) & SDFM_SDCMAXDATA1_MAXDATA16_Msk) >> SDFM_SDCMAXDATA1_MAXDATA16_Pos) /*!< MAXDATA16 Get Value            */


/* SDCMINDATA1 bitfield */
#define SDFM_SDCMINDATA1_MINDATA16_Pos    (0U)                                                                                  /*!< MINDATA16 Postion   0          */ 
#define SDFM_SDCMINDATA1_MINDATA16_Msk    (0xffffU << SDFM_SDCMINDATA1_MINDATA16_Pos)                                      /*!< MINDATA16 Mask      0x0000FFFF */
#define SDFM_SDCMINDATA1_MINDATA16_Set(x) (((uint32_t) (x) << SDFM_SDCMINDATA1_MINDATA16_Pos) & SDFM_SDCMINDATA1_MINDATA16_Msk) /*!< MINDATA16 Set Value            */
#define SDFM_SDCMINDATA1_MINDATA16_Get(x) (((uint32_t) (x) & SDFM_SDCMINDATA1_MINDATA16_Msk) >> SDFM_SDCMINDATA1_MINDATA16_Pos) /*!< MINDATA16 Get Value            */


/* SDCMAXDATA2 bitfield */
#define SDFM_SDCMAXDATA2_MAXDATA16_Pos    (0U)                                                                                  /*!< MAXDATA16 Postion   0          */ 
#define SDFM_SDCMAXDATA2_MAXDATA16_Msk    (0xffffU << SDFM_SDCMAXDATA2_MAXDATA16_Pos)                                      /*!< MAXDATA16 Mask      0x0000FFFF */
#define SDFM_SDCMAXDATA2_MAXDATA16_Set(x) (((uint32_t) (x) << SDFM_SDCMAXDATA2_MAXDATA16_Pos) & SDFM_SDCMAXDATA2_MAXDATA16_Msk) /*!< MAXDATA16 Set Value            */
#define SDFM_SDCMAXDATA2_MAXDATA16_Get(x) (((uint32_t) (x) & SDFM_SDCMAXDATA2_MAXDATA16_Msk) >> SDFM_SDCMAXDATA2_MAXDATA16_Pos) /*!< MAXDATA16 Get Value            */


/* SDCMINDATA2 bitfield */
#define SDFM_SDCMINDATA2_MINDATA16_Pos    (0U)                                                                                  /*!< MINDATA16 Postion   0          */ 
#define SDFM_SDCMINDATA2_MINDATA16_Msk    (0xffffU << SDFM_SDCMINDATA2_MINDATA16_Pos)                                      /*!< MINDATA16 Mask      0x0000FFFF */
#define SDFM_SDCMINDATA2_MINDATA16_Set(x) (((uint32_t) (x) << SDFM_SDCMINDATA2_MINDATA16_Pos) & SDFM_SDCMINDATA2_MINDATA16_Msk) /*!< MINDATA16 Set Value            */
#define SDFM_SDCMINDATA2_MINDATA16_Get(x) (((uint32_t) (x) & SDFM_SDCMINDATA2_MINDATA16_Msk) >> SDFM_SDCMINDATA2_MINDATA16_Pos) /*!< MINDATA16 Get Value            */


/* SDCMAXDATA3 bitfield */
#define SDFM_SDCMAXDATA3_MAXDATA16_Pos    (0U)                                                                                  /*!< MAXDATA16 Postion   0          */ 
#define SDFM_SDCMAXDATA3_MAXDATA16_Msk    (0xffffU << SDFM_SDCMAXDATA3_MAXDATA16_Pos)                                      /*!< MAXDATA16 Mask      0x0000FFFF */
#define SDFM_SDCMAXDATA3_MAXDATA16_Set(x) (((uint32_t) (x) << SDFM_SDCMAXDATA3_MAXDATA16_Pos) & SDFM_SDCMAXDATA3_MAXDATA16_Msk) /*!< MAXDATA16 Set Value            */
#define SDFM_SDCMAXDATA3_MAXDATA16_Get(x) (((uint32_t) (x) & SDFM_SDCMAXDATA3_MAXDATA16_Msk) >> SDFM_SDCMAXDATA3_MAXDATA16_Pos) /*!< MAXDATA16 Get Value            */


/* SDCMINDATA3 bitfield */
#define SDFM_SDCMINDATA3_MINDATA16_Pos    (0U)                                                                                  /*!< MINDATA16 Postion   0          */ 
#define SDFM_SDCMINDATA3_MINDATA16_Msk    (0xffffU << SDFM_SDCMINDATA3_MINDATA16_Pos)                                      /*!< MINDATA16 Mask      0x0000FFFF */
#define SDFM_SDCMINDATA3_MINDATA16_Set(x) (((uint32_t) (x) << SDFM_SDCMINDATA3_MINDATA16_Pos) & SDFM_SDCMINDATA3_MINDATA16_Msk) /*!< MINDATA16 Set Value            */
#define SDFM_SDCMINDATA3_MINDATA16_Get(x) (((uint32_t) (x) & SDFM_SDCMINDATA3_MINDATA16_Msk) >> SDFM_SDCMINDATA3_MINDATA16_Pos) /*!< MINDATA16 Get Value            */


/* SDCMAXDATA4 bitfield */
#define SDFM_SDCMAXDATA4_MAXDATA16_Pos    (0U)                                                                                  /*!< MAXDATA16 Postion   0          */ 
#define SDFM_SDCMAXDATA4_MAXDATA16_Msk    (0xffffU << SDFM_SDCMAXDATA4_MAXDATA16_Pos)                                      /*!< MAXDATA16 Mask      0x0000FFFF */
#define SDFM_SDCMAXDATA4_MAXDATA16_Set(x) (((uint32_t) (x) << SDFM_SDCMAXDATA4_MAXDATA16_Pos) & SDFM_SDCMAXDATA4_MAXDATA16_Msk) /*!< MAXDATA16 Set Value            */
#define SDFM_SDCMAXDATA4_MAXDATA16_Get(x) (((uint32_t) (x) & SDFM_SDCMAXDATA4_MAXDATA16_Msk) >> SDFM_SDCMAXDATA4_MAXDATA16_Pos) /*!< MAXDATA16 Get Value            */


/* SDCMINDATA4 bitfield */
#define SDFM_SDCMINDATA4_MINDATA16_Pos    (0U)                                                                                  /*!< MINDATA16 Postion   0          */ 
#define SDFM_SDCMINDATA4_MINDATA16_Msk    (0xffffU << SDFM_SDCMINDATA4_MINDATA16_Pos)                                      /*!< MINDATA16 Mask      0x0000FFFF */
#define SDFM_SDCMINDATA4_MINDATA16_Set(x) (((uint32_t) (x) << SDFM_SDCMINDATA4_MINDATA16_Pos) & SDFM_SDCMINDATA4_MINDATA16_Msk) /*!< MINDATA16 Set Value            */
#define SDFM_SDCMINDATA4_MINDATA16_Get(x) (((uint32_t) (x) & SDFM_SDCMINDATA4_MINDATA16_Msk) >> SDFM_SDCMINDATA4_MINDATA16_Pos) /*!< MINDATA16 Get Value            */


/*!
 * @}
 */


/*!
 * @}
 */ /* end of HS32F7D377_SDFM_REGISTER */

#endif /* HS32F7D377_SDFM_H */
