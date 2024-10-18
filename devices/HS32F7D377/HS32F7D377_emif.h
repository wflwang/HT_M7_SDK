/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


/*!
 * \file HS32F7D377_emif.h
 * \brief HS32F7D377 EMIF register file
 * \version V1.0_20231010
 */

#ifndef HS32F7D377_EMIF_H
#define HS32F7D377_EMIF_H

/*!
 * \addtogroup HS32F7D377_EMIF_REGISTER HS32F7D377 EMIF Register
 * \ingroup HS32F7D377_REGISTER
 *
 * \brief EMIF register layout, bitfield and address definitions
 *
 * @{
 */

/* clang-format off */

/*!
 * \name EMIF Register Layout
 *
 *
 * @{
 */

/*! \brief EMIF register */
typedef struct {
    uint8_t    RSV_0X0[4]                                ;  /*!< [ 3: 0] : Reserved Register */
    union
    {
        __IOM uint32_t ASYNC_WCCR                        ;  /*!< 0x00000004 : Async Wait Cycle Config Register */

        struct
        {
            __IOM uint32_t MAX_EXT_WAIT              : 8 ;  /*!< [ 7: 0] : The EMIF will wait for (max_ext_wait + 1) * 16 clock cycles before an extended asynchronous cycle is terminated.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 20;  /*!< [27: 8] : reserved. */
            __IOM uint32_t WP0                       : 1 ;  /*!< [28:28] : Defines the polarity of the EMxWAIT port.: 0: Wait if EMxWAIT port is low.
                                                                           1: Wait if EMxWAIT port is high. Reset type: SYSRSn */
                  uint32_t RSV_1                     : 3 ;  /*!< [31:29] : reserved. */
        } ASYNC_WCCRb;
    };

    union
    {
        __IOM uint32_t SDRAM_CR                          ;  /*!< 0x00000008 : SDRAM (EMxCS0n) Config Register */

        struct
        {
            __IOM uint32_t PAGESIZE                  : 3 ;  /*!< [ 2: 0] : Defines the internal page size of connected SDRAM devices: 000: 256-word pages requiring 8 column address bits.
                                                                           001: 512-word pages requiring 9 column address bits.
                                                                           010: 1024-word pages requiring 10 column address bits.
                                                                           011: 2048-word pages requiring 11 column address bits.
                                                                           1xx: Reserved.
                                                                           A write to this field will cause the EMIF to start the SDRAM initialization sequence.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 1 ;  /*!< [ 3: 3] : reserved. */
            __IOM uint32_t IBANK                     : 3 ;  /*!< [ 6: 4] : Defines number of banks inside connected SDRAM devices: 000: 1 bank SDRAM devices.
                                                                           001: 2 bank SDRAM devices.
                                                                           010: 4 bank SDRAM devices.
                                                                           011: Reserved.
                                                                           1xx: Reserved.
                                                                           A write to this field will cause the EMIF to start the SDRAM initialization sequence.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_1                     : 2 ;  /*!< [ 8: 7] : reserved. */
            __IOM uint32_t CL                        : 3 ;  /*!< [11: 9] : The value of this field defines the CAS latency to be used when accessing connected SDRAM devices. Only CAS latencies of 2 (cl =2) and 3 (cl = 3) are supported.
                                                                           A write to this field will cause the EMIF to start the SDRAM initialization sequence.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_2                     : 2 ;  /*!< [13:12] : reserved. */
            __IOM uint32_t NM                        : 1 ;  /*!< [14:14] : Narrow mode. Set to 1 when system bus width to memory bus width is 2:1 for SDR SDRAM. Set to 0 when system bus width to memory bus width is 1:1 for SDR SDRAM.
                                                                           A write to this field will cause the EMIF to start the SDRAM initialization sequence.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_3                     : 1 ;  /*!< [15:15] : reserved. */
            __IOM uint32_t ECLK_INV                  : 1 ;  /*!< [16:16] : 1: emif clk inv to sdram, 0: emif clk to sdram. */
                  uint32_t RSV_4                     : 12;  /*!< [28:17] : reserved. */
            __IOM uint32_t PDWR                      : 1 ;  /*!< [29:29] : Perform refreshes during Power Down. Writing a 1 to this bit will cause the EMIF to exit the power down state and issue an AUTO REFRESH command every time Refresh May level is set.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PD                        : 1 ;  /*!< [30:30] : Power Down. Writing a 1 to this bit will cause connected SDRAM devices to be placed into Power Down mode. If both sr and pd bits are set, the EMIF will go into Self Refresh.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SR                        : 1 ;  /*!< [31:31] : Self Refresh. Writing a 1 to this bit will cause connected SDRAM devices to be placed into Self Refresh mode and the EMIF to enter the self refresh state. In this state the EMIF will service all asynchronous memory accesses immediately but any SDRAM access will take at least t_ras + 1 cycles due to the time required for the SDRAM devices to out of Self Refresh mode. If an SDRAM access immediately follows the setting of the sr bit, the access will take t_ras + t_xs + 2 cycles. If both sr and pd bits are set, the EMIF will go into Self Refresh.
                                                                           Reset type: SYSRSn */
        } SDRAM_CRb;
    };

    union
    {
        __IOM uint32_t SDRAM_RCR                         ;  /*!< 0x0000000c : SDRAM Refresh Control Register */

        struct
        {
            __IOM uint32_t REFRESH_RATE              : 13;  /*!< [12: 0] : Value in this field is used to define the rate at which connected SDRAM devices will be refreshed, as follows:
                                                                           SDRAM refresh rate = EMIF rate/refresh_rate
                                                                           where EMIF rate=clk rate when full_rate=1, or EMIF rate=1/2 clk rate when full_rate=0.
                                                                           Writing a value < 0x0020 to this field will cause it to be loaded with (2* t_rfc) + 1 value from SDRAM Timing register.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 19;  /*!< [31:13] : reserved. */
        } SDRAM_RCRb;
    };

    union
    {
        __IOM uint32_t ASYNC_CS2_CR                      ;  /*!< 0x00000010 : Async 1 (EMxCS2n) Config Register */

        struct
        {
            __IOM uint32_t ASIZE                     : 2 ;  /*!< [ 1: 0] : Asynchronous Memory Size. Defines the width of the asynchronous device's data bus :
                                                                           00: 8 Bit data bus.
                                                                           01: 16 Bit data bus.
                                                                           10: 32 Bit data bus.
                                                                           11: Reserved.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t TA                        : 2 ;  /*!< [ 3: 2] : Turn Around cycles. Number of EMxCLK cycles between the end of one asynchronous memory access and the start of another asynchronous memory access, minus one cycle. This delay is not incurred between a read followed by a read, or a write followed by a write to the same chip select. The reset value is 4 cycles.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t R_HOLD                    : 3 ;  /*!< [ 6: 4] : Read Strobe Hold cycles. */
            __IOM uint32_t R_STROBE                  : 6 ;  /*!< [12: 7] : Read Strobe Duration cycles. Number of EMxCLK cycles for which EMxOEn is held active, minus one cycle. The reset value is 64 cycles. This field cannot be zero when ew = 1.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t R_SETUP                   : 4 ;  /*!< [16:13] : Read Strobe Setup cycles. Number of EMxCLK cycles from EMxAy, EMxBAy, EMxDQMy, and EMxCS2n being set to EMxOEn asserted, minus one cycle. The reset value is 16 cycles.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t W_HOLD                    : 3 ;  /*!< [19:17] : Write Strobe Hold cycles. */
            __IOM uint32_t W_STROBE                  : 6 ;  /*!< [25:20] : Write Strobe Duration cycles. Number of EMxCLK cycles for which EMxWEn is held active, minus one cycle. The reset value is 64 cycles. This field cannot be zero when ew = 1.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t W_SETUP                   : 4 ;  /*!< [29:26] : Write Strobe Setup cycles. Number of EMxCLK cycles from EMxAy, EMxBAy, EMxDQMy, and EMxCS2n being set to EMxWEn asserted, minus one cycle. The reset value is 16 cycles.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t EW                        : 1 ;  /*!< [30:30] : Extend Wait mode. Set to 1 if extended asynchronous cycles are required based on EMxWAIT.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SS                        : 1 ;  /*!< [31:31] : Select Strobe mode. Set to 1 if chip selects need to have write or read strobe timing.
                                                                           Reset type: SYSRSn */
        } ASYNC_CS2_CRb;
    };

    union
    {
        __IOM uint32_t ASYNC_CS3_CR                      ;  /*!< 0x00000014 : Async 2 (EMxCS3n) Config Register */

        struct
        {
            __IOM uint32_t ASIZE                     : 2 ;  /*!< [ 1: 0] : Asynchronous Memory Size. Defines the width of the asynchronous device's data bus :
                                                                           00: 8 Bit data bus.
                                                                           01: 16 Bit data bus.
                                                                           10: 32 Bit data bus.
                                                                           11: Reserved.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t TA                        : 2 ;  /*!< [ 3: 2] : Turn Around cycles. Number of EMxCLK cycles between the end of one asynchronous memory access and the start of another asynchronous memory access, minus one cycle. This delay is not incurred between a read followed by a read, or a write followed by a write to the same chip select. The reset value is 4 cycles.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t R_HOLD                    : 3 ;  /*!< [ 6: 4] : Read Strobe Hold cycles. */
            __IOM uint32_t R_STROBE                  : 6 ;  /*!< [12: 7] : Read Strobe Duration cycles. Number of EMxCLK cycles for which EMxOEn is held active, minus one cycle. The reset value is 64 cycles. This field cannot be zero when ew = 1.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t R_SETUP                   : 4 ;  /*!< [16:13] : Read Strobe Setup cycles. Number of EMxCLK cycles from EMxAy, EMxBAy, EMxDQMy, and EMxCS3n being set to EMxOEn asserted, minus one cycle. The reset value is 16 cycles.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t W_HOLD                    : 3 ;  /*!< [19:17] : Write Strobe Hold cycles. */
            __IOM uint32_t W_STROBE                  : 6 ;  /*!< [25:20] : Write Strobe Duration cycles. Number of EMxCLK cycles for which EMxWEn is held active, minus one cycle. The reset value is 64 cycles. This field cannot be zero when ew = 1.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t W_SETUP                   : 4 ;  /*!< [29:26] : Write Strobe Setup cycles. Number of EMxCLK cycles from EMxAy, EMxBAy, EMxDQMy, and EMxCS3n being set to EMxWEn asserted, minus one cycle. The reset value is 16 cycles.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t EW                        : 1 ;  /*!< [30:30] : Extend Wait mode. Set to 1 if extended asynchronous cycles are required based on EMxWAIT.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SS                        : 1 ;  /*!< [31:31] : Select Strobe mode. Set to 1 if chip selects need to have write or read strobe timing.
                                                                           Reset type: SYSRSn */
        } ASYNC_CS3_CRb;
    };

    union
    {
        __IOM uint32_t ASYNC_CS4_CR                      ;  /*!< 0x00000018 : Async 3 (EMxCS4n) Config Register */

        struct
        {
            __IOM uint32_t ASIZE                     : 2 ;  /*!< [ 1: 0] : Asynchronous Memory Size. Defines the width of the asynchronous device's data bus :
                                                                           00: 8 Bit data bus.
                                                                           01: 16 Bit data bus.
                                                                           10: 32 Bit data bus.
                                                                           11: Reserved.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t TA                        : 2 ;  /*!< [ 3: 2] : Turn Around cycles. Number of EMxCLK cycles between the end of one asynchronous memory access and the start of another asynchronous memory access, minus one cycle. This delay is not incurred between a read followed by a read, or a write followed by a write to the same chip select. The reset value is 4 cycles.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t R_HOLD                    : 3 ;  /*!< [ 6: 4] : Read Strobe Hold cycles. */
            __IOM uint32_t R_STROBE                  : 6 ;  /*!< [12: 7] : Read Strobe Duration cycles. Number of EMxCLK cycles for which EMxOEn is held active, minus one cycle. The reset value is 64 cycles. This field cannot be zero when ew = 1.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t R_SETUP                   : 4 ;  /*!< [16:13] : Read Strobe Setup cycles. Number of EMxCLK cycles from EMxAy, EMxBAy, EMxDQMy, and EMxCS4n being set to EMxOEn asserted, minus one cycle. The reset value is 16 cycles.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t W_HOLD                    : 3 ;  /*!< [19:17] : Write Strobe Hold cycles. */
            __IOM uint32_t W_STROBE                  : 6 ;  /*!< [25:20] : Write Strobe Duration cycles. Number of EMxCLK cycles for which EMxWEn is held active, minus one cycle. The reset value is 64 cycles. This field cannot be zero when ew = 1.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t W_SETUP                   : 4 ;  /*!< [29:26] : Write Strobe Setup cycles. Number of EMxCLK cycles from EMxAy, EMxBAy, EMxDQMy, and EMxCS4n being set to EMxWEn asserted, minus one cycle. The reset value is 16 cycles.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t EW                        : 1 ;  /*!< [30:30] : Extend Wait mode. Set to 1 if extended asynchronous cycles are required based on EMxWAIT.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SS                        : 1 ;  /*!< [31:31] : Select Strobe mode. Set to 1 if chip selects need to have write or read strobe timing.
                                                                           Reset type: SYSRSn */
        } ASYNC_CS4_CRb;
    };

    uint8_t    RSV_0X1C[4]                               ;  /*!< [ 3: 0] : Reserved Register */
    union
    {
        __IOM uint32_t SDRAM_TR                          ;  /*!< 0x00000020 : SDRAM Timing Register */

        struct
        {
                  uint32_t RSV_0                     : 4 ;  /*!< [ 3: 0] : reserved. */
            __IOM uint32_t T_RRD                     : 3 ;  /*!< [ 6: 4] : Minimum number of EMxCLK cycles from Activate to Activate for a different bank, minus one.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_1                     : 1 ;  /*!< [ 7: 7] : reserved. */
            __IOM uint32_t T_RC                      : 4 ;  /*!< [11: 8] : Minimum number of EMxCLK cycles from Activate to Activate minus one.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t T_RAS                     : 4 ;  /*!< [15:12] : Minimum number of EMxCLK cycles from Activate to Precharge, minus one. t_ras >= t_rcd.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t T_WR                      : 3 ;  /*!< [18:16] : For SDR, this is equal to minimum number of EMxCLK cycles from last Write transfer to Precharge, minus one.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_2                     : 1 ;  /*!< [19:19] : reserved. */
            __IOM uint32_t T_RCD                     : 3 ;  /*!< [22:20] : Minimum number of EMxCLK cycles from Activate to Read or Write, minus one.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_3                     : 1 ;  /*!< [23:23] : reserved. */
            __IOM uint32_t T_RP                      : 3 ;  /*!< [26:24] : Minimum number of EMxCLK cycles from Precharge to Activate or Refresh, minus one.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t T_RFC                     : 5 ;  /*!< [31:27] : Minimum number of EMxCLK cycles from Refresh or Load Mode to Refresh or Activate, minus one.
                                                                           Reset type: SYSRSn */
        } SDRAM_TRb;
    };

    uint8_t    RSV_0X24[12]                              ;  /*!< [ 11: 0] : Reserved Register */
    union
    {
        __IM  uint32_t TOTAL_SDRAM_AR                    ;  /*!< 0x00000030 : Total SDRAM Accesses Register */

        struct
        {
            __IM  uint32_t TOTAL_SDRAM_AR            : 32;  /*!< [31: 0] : Indicates the total number of accesses to SDRAM from a master (CPUx/CPUX.DMA). This counter is incremented by two for a single access crossing page boundaries.
                                                                           Reset type: SYSRSn */
        } TOTAL_SDRAM_ARb;
    };

    union
    {
        __IM  uint32_t TOTAL_SDRAM_ACTR                  ;  /*!< 0x00000034 : Total SDRAM Activate Register */

        struct
        {
            __IM  uint32_t TOTAL_SDRAM_ACTR          : 32;  /*!< [31: 0] : Indicates the total number of SDRAM accesses which require an activate command.
                                                                           Reset type: SYSRSn */
        } TOTAL_SDRAM_ACTRb;
    };

    uint8_t    RSV_0X38[4]                               ;  /*!< [3: 0] : Reserved Register */
    union
    {
        __IOM uint32_t SDR_EXT_TMNG                      ;  /*!< 0x0000003c : SDRAM SR/PD Exit Timing Register */

        struct
        {
            __IOM uint32_t T_XS                      : 5 ;  /*!< [ 4: 0] : This is equal to minimum number of EMxCLK cycles from Self Refresh exit to any command, minus one. For SDR SDRAM, this count should satisfy tXSR.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 27;  /*!< [31: 5] : reserved. */
        } SDR_EXT_TMNGb;
    };

    union
    {
        __IM  uint32_t INT_RAW                           ;  /*!< 0x00000040 : Interrupt Raw Register */

        struct
        {
            __IM  uint32_t AT_FLAG                   : 1 ;  /*!< [ 0: 0] : Asynchronous Timeout. Set to 1 by hardware to indicate that during an extended asynchronous memory access cycle, the EMxWAIT signal did not go inactive within the number of cycles defined by the max_ext_wait field in Async Wait Cycle Config register. AT_FLAG_SET set this bit, AT_FLAG_CLR clr this bit.
                                                                           Reset type: SYSRSn */
            __IM  uint32_t LT_FLAG                   : 1 ;  /*!< [ 1: 1] : Line Trap. Set to 1 by hardware to indicate illegal memory access type or invalid cache line size. LT_FLAG_SET set this bit, LT_FLAG_CLR clr this bit.
                                                                           Reset type: SYSRSn */
            __IM  uint32_t WR_FLAG                   : 1 ;  /*!< [ 2: 2] : Wait Rise. Set to 1 by hardware to indicate rising edge on the corresponding EMxWAIT has been detected. The WPx bits in the Async Wait Cycle Config register has no effect on these bits. WR_FLAG_SET set this bit, WR_FLAG_CLR clr this bit.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 29;  /*!< [31: 3] : reserved. */
        } INT_RAWb;
    };

    union
    {
        __IOM uint32_t INT_EN                            ;  /*!< 0x00000044 : Interrupt Enable Register */

        struct
        {
            __IOM uint32_t AT_IEN                    : 1 ;  /*!< [ 0: 0] : set 1 to enable AT interrupt.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t LT_IEN                    : 1 ;  /*!< [ 1: 1] : set 1 to enable LT interrupt.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t WR_IEN                    : 1 ;  /*!< [ 2: 2] : set 1 to enable WR interrupt.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 29;  /*!< [31: 3] : reserved. */
        } INT_ENb;
    };

    union
    {
        __IOM uint32_t INT_MSK_SET                       ;  /*!< 0x00000048 : FLAG Set Register */

        struct
        {
            __IOM uint32_t AT_FLAG_SET               : 1 ;  /*!< [ 0: 0] : write 1 to set AT flag.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t LT_FLAG_SET               : 1 ;  /*!< [ 1: 1] : write 1 to set LT flag.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t WR_FLAG_SET               : 1 ;  /*!< [ 2: 2] : write 1 to set WR flag.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 29;  /*!< [31: 3] : reserved. */
        } INT_MSK_SETb;
    };

    union
    {
        __IOM uint32_t INT_MSK_CLR                       ;  /*!< 0x0000004c : FLAG Clear Register */

        struct
        {
            __IOM uint32_t AT_FLAG_CLR               : 1 ;  /*!< [ 0: 0] : write 1 to clr AT flag.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t LT_FLAG_CLR               : 1 ;  /*!< [ 1: 1] : write 1 to clr LT flag.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t WR_FLAG_CLR               : 1 ;  /*!< [ 2: 2] : write 1 to clr WR flag.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 29;  /*!< [31: 3] : reserved. */
        } INT_MSK_CLRb;
    };

    union
    {
        __IOM uint32_t EMIF1LOCK                         ;  /*!< 0x00000050 :  */

        struct
        {
            __IOM uint32_t LOCK_EMIF                 : 1 ;  /*!< [ 0: 0] : 1: writes to ACCPROT and Mselect fields are blocked. */
                  uint32_t RSV_0                     : 31;  /*!< [31: 1] : reserved. */
        } EMIF1LOCKb;
    };

    union
    {
        __IOM uint32_t EMIF1MSEL                         ;  /*!< 0x00000054 :  */

        struct
        {
            __IOM uint32_t CPU0_MSEL                 : 1 ;  /*!< [ 0: 0] : . */
            __IOM uint32_t CPU1_MSEL                 : 1 ;  /*!< [ 1: 1] : . */
                  uint32_t RSV_0                     : 30;  /*!< [31: 2] : reserved. */
        } EMIF1MSELb;
    };

    union
    {
        __IOM uint32_t EMIF1ACCROT                       ;  /*!< 0x00000058 :  */

        struct
        {
            __IOM uint32_t CPU0_READ                 : 1 ;  /*!< [ 0: 0] : 0: cpu0_read  allowed, 1: cpu0_read  are blocked. */
            __IOM uint32_t CPU0_WRITE                : 1 ;  /*!< [ 1: 1] : 0: cpu0_write allowed, 1: cpu0_write are blocked. */
            __IOM uint32_t DMA0_READ                 : 1 ;  /*!< [ 2: 2] : 0: dma0_read  allowed, 1: dma0_read  are blocked. */
            __IOM uint32_t DMA0_WRITE                : 1 ;  /*!< [ 3: 3] : 0: dma0_write allowed, 1: dma0_write are blocked. */
            __IOM uint32_t CPU1_READ                 : 1 ;  /*!< [ 4: 4] : 0: cpu1_read  allowed, 1: cpu1_read  are blocked. */
            __IOM uint32_t CPU1_WRITE                : 1 ;  /*!< [ 5: 5] : 0: cpu1_write allowed, 1: cpu1_write are blocked. */
            __IOM uint32_t DMA1_READ                 : 1 ;  /*!< [ 6: 6] : 0: dma1_read  allowed, 1: dma1_read  are blocked. */
            __IOM uint32_t DMA1_WRITE                : 1 ;  /*!< [ 7: 7] : 0: dma1_write allowed, 1: dma1_write are blocked. */
                  uint32_t RSV_0                     : 24;  /*!< [31: 8] : reserved. */
        } EMIF1ACCROTb;
    };

    union
    {
        __IM  uint32_t ST                                ;  /*!< 0x0000005c :  */

        struct
        {
            __IM  uint32_t SDRAM_STATE               : 5 ;  /*!< [ 4: 0] : sdram state. */
            __IM  uint32_t SDRAM_INIT_FINISH         : 1 ;  /*!< [ 5: 5] : 1: sdram init done. */
            __IM  uint32_t CURRENT_ASYNCREQEN        : 1 ;  /*!< [ 6: 6] : 1: asram access valid. */
                  uint32_t RSV_0                     : 25;  /*!< [31: 7] : reserved. */
        } STb;
    };

    uint8_t    RSV_0X60[4000]                            ;  /*!< [3999: 0] : Reserved Register */
} EMIF_Type;


/*!
 * @}
 */

/*!
 * \name EMIF Base Address Definitions
 *
 * @{
 */

/*! \brief EMIF base address */
#define EMIF1_BASE (0x41600000UL)
/*! \brief EMIF base pointer */
#define EMIF1 ((EMIF_Type *) EMIF1_BASE)


/*!
 * @}
 */


/*!
 * \name EMIF Register Bitfield Definitions
 *
 * @{
 */

/* ASYNC_WCCR bitfield */
#define EMIF_ASYNC_WCCR_WP0_Pos     (28U)                                                                     /*!< WP0 Position 28 */
#define EMIF_ASYNC_WCCR_WP0_Msk     (0x1U << EMIF_ASYNC_WCCR_WP0_Pos)                                         /*!< WP0 Mask 0x10000000 */
#define EMIF_ASYNC_WCCR_WP0_Set(x)  (((uint32_t) (x) << EMIF_ASYNC_WCCR_WP0_Pos) & EMIF_ASYNC_WCCR_WP0_Msk)   /*!< WP0 Set Value */
#define EMIF_ASYNC_WCCR_WP0_Get(x)  (((uint32_t) (x) & EMIF_ASYNC_WCCR_WP0_Msk) >> EMIF_ASYNC_WCCR_WP0_Pos)   /*!< WP0 Get Value */

#define EMIF_ASYNC_WCCR_MAX_EXT_WAIT_Pos     (0U)                                                                                        /*!< MAX_EXT_WAIT Position 0 */
#define EMIF_ASYNC_WCCR_MAX_EXT_WAIT_Msk     (0xffU << EMIF_ASYNC_WCCR_MAX_EXT_WAIT_Pos)                                                 /*!< MAX_EXT_WAIT Mask 0x000000FF */
#define EMIF_ASYNC_WCCR_MAX_EXT_WAIT_Set(x)  (((uint32_t) (x) << EMIF_ASYNC_WCCR_MAX_EXT_WAIT_Pos) & EMIF_ASYNC_WCCR_MAX_EXT_WAIT_Msk)   /*!< MAX_EXT_WAIT Set Value */
#define EMIF_ASYNC_WCCR_MAX_EXT_WAIT_Get(x)  (((uint32_t) (x) & EMIF_ASYNC_WCCR_MAX_EXT_WAIT_Msk) >> EMIF_ASYNC_WCCR_MAX_EXT_WAIT_Pos)   /*!< MAX_EXT_WAIT Get Value */

/* SDRAM_CR bitfield */
#define EMIF_SDRAM_CR_SR_Pos     (31U)                                                               /*!< SR Position 31 */
#define EMIF_SDRAM_CR_SR_Msk     (0x1U << EMIF_SDRAM_CR_SR_Pos)                                      /*!< SR Mask 0x80000000 */
#define EMIF_SDRAM_CR_SR_Set(x)  (((uint32_t) (x) << EMIF_SDRAM_CR_SR_Pos) & EMIF_SDRAM_CR_SR_Msk)   /*!< SR Set Value */
#define EMIF_SDRAM_CR_SR_Get(x)  (((uint32_t) (x) & EMIF_SDRAM_CR_SR_Msk) >> EMIF_SDRAM_CR_SR_Pos)   /*!< SR Get Value */

#define EMIF_SDRAM_CR_PD_Pos     (30U)                                                               /*!< PD Position 30 */
#define EMIF_SDRAM_CR_PD_Msk     (0x1U << EMIF_SDRAM_CR_PD_Pos)                                      /*!< PD Mask 0x40000000 */
#define EMIF_SDRAM_CR_PD_Set(x)  (((uint32_t) (x) << EMIF_SDRAM_CR_PD_Pos) & EMIF_SDRAM_CR_PD_Msk)   /*!< PD Set Value */
#define EMIF_SDRAM_CR_PD_Get(x)  (((uint32_t) (x) & EMIF_SDRAM_CR_PD_Msk) >> EMIF_SDRAM_CR_PD_Pos)   /*!< PD Get Value */

#define EMIF_SDRAM_CR_PDWR_Pos     (29U)                                                                   /*!< PDWR Position 29 */
#define EMIF_SDRAM_CR_PDWR_Msk     (0x1U << EMIF_SDRAM_CR_PDWR_Pos)                                        /*!< PDWR Mask 0x20000000 */
#define EMIF_SDRAM_CR_PDWR_Set(x)  (((uint32_t) (x) << EMIF_SDRAM_CR_PDWR_Pos) & EMIF_SDRAM_CR_PDWR_Msk)   /*!< PDWR Set Value */
#define EMIF_SDRAM_CR_PDWR_Get(x)  (((uint32_t) (x) & EMIF_SDRAM_CR_PDWR_Msk) >> EMIF_SDRAM_CR_PDWR_Pos)   /*!< PDWR Get Value */

#define EMIF_SDRAM_CR_ECLK_INV_Pos     (16U)                                                                           /*!< ECLK_INV Position 16 */
#define EMIF_SDRAM_CR_ECLK_INV_Msk     (0x1U << EMIF_SDRAM_CR_ECLK_INV_Pos)                                            /*!< ECLK_INV Mask 0x00010000 */
#define EMIF_SDRAM_CR_ECLK_INV_Set(x)  (((uint32_t) (x) << EMIF_SDRAM_CR_ECLK_INV_Pos) & EMIF_SDRAM_CR_ECLK_INV_Msk)   /*!< ECLK_INV Set Value */
#define EMIF_SDRAM_CR_ECLK_INV_Get(x)  (((uint32_t) (x) & EMIF_SDRAM_CR_ECLK_INV_Msk) >> EMIF_SDRAM_CR_ECLK_INV_Pos)   /*!< ECLK_INV Get Value */

#define EMIF_SDRAM_CR_NM_Pos     (14U)                                                               /*!< NM Position 14 */
#define EMIF_SDRAM_CR_NM_Msk     (0x1U << EMIF_SDRAM_CR_NM_Pos)                                      /*!< NM Mask 0x00004000 */
#define EMIF_SDRAM_CR_NM_Set(x)  (((uint32_t) (x) << EMIF_SDRAM_CR_NM_Pos) & EMIF_SDRAM_CR_NM_Msk)   /*!< NM Set Value */
#define EMIF_SDRAM_CR_NM_Get(x)  (((uint32_t) (x) & EMIF_SDRAM_CR_NM_Msk) >> EMIF_SDRAM_CR_NM_Pos)   /*!< NM Get Value */

#define EMIF_SDRAM_CR_CL_Pos     (9U)                                                                /*!< CL Position 9 */
#define EMIF_SDRAM_CR_CL_Msk     (0x7U << EMIF_SDRAM_CR_CL_Pos)                                      /*!< CL Mask 0x00000E00 */
#define EMIF_SDRAM_CR_CL_Set(x)  (((uint32_t) (x) << EMIF_SDRAM_CR_CL_Pos) & EMIF_SDRAM_CR_CL_Msk)   /*!< CL Set Value */
#define EMIF_SDRAM_CR_CL_Get(x)  (((uint32_t) (x) & EMIF_SDRAM_CR_CL_Msk) >> EMIF_SDRAM_CR_CL_Pos)   /*!< CL Get Value */

#define EMIF_SDRAM_CR_IBANK_Pos     (4U)                                                                      /*!< IBANK Position 4 */
#define EMIF_SDRAM_CR_IBANK_Msk     (0x7U << EMIF_SDRAM_CR_IBANK_Pos)                                         /*!< IBANK Mask 0x00000070 */
#define EMIF_SDRAM_CR_IBANK_Set(x)  (((uint32_t) (x) << EMIF_SDRAM_CR_IBANK_Pos) & EMIF_SDRAM_CR_IBANK_Msk)   /*!< IBANK Set Value */
#define EMIF_SDRAM_CR_IBANK_Get(x)  (((uint32_t) (x) & EMIF_SDRAM_CR_IBANK_Msk) >> EMIF_SDRAM_CR_IBANK_Pos)   /*!< IBANK Get Value */

#define EMIF_SDRAM_CR_PAGESIZE_Pos     (0U)                                                                            /*!< PAGESIZE Position 0 */
#define EMIF_SDRAM_CR_PAGESIZE_Msk     (0x7U << EMIF_SDRAM_CR_PAGESIZE_Pos)                                            /*!< PAGESIZE Mask 0x00000007 */
#define EMIF_SDRAM_CR_PAGESIZE_Set(x)  (((uint32_t) (x) << EMIF_SDRAM_CR_PAGESIZE_Pos) & EMIF_SDRAM_CR_PAGESIZE_Msk)   /*!< PAGESIZE Set Value */
#define EMIF_SDRAM_CR_PAGESIZE_Get(x)  (((uint32_t) (x) & EMIF_SDRAM_CR_PAGESIZE_Msk) >> EMIF_SDRAM_CR_PAGESIZE_Pos)   /*!< PAGESIZE Get Value */

/* SDRAM_RCR bitfield */
#define EMIF_SDRAM_RCR_REFRESH_RATE_Pos     (0U)                                                                                      /*!< REFRESH_RATE Position 0 */
#define EMIF_SDRAM_RCR_REFRESH_RATE_Msk     (0x1fffU << EMIF_SDRAM_RCR_REFRESH_RATE_Pos)                                              /*!< REFRESH_RATE Mask 0x00001FFF */
#define EMIF_SDRAM_RCR_REFRESH_RATE_Set(x)  (((uint32_t) (x) << EMIF_SDRAM_RCR_REFRESH_RATE_Pos) & EMIF_SDRAM_RCR_REFRESH_RATE_Msk)   /*!< REFRESH_RATE Set Value */
#define EMIF_SDRAM_RCR_REFRESH_RATE_Get(x)  (((uint32_t) (x) & EMIF_SDRAM_RCR_REFRESH_RATE_Msk) >> EMIF_SDRAM_RCR_REFRESH_RATE_Pos)   /*!< REFRESH_RATE Get Value */

/* ASYNC_CS2_CR bitfield */
#define EMIF_ASYNC_CS2_CR_SS_Pos     (31U)                                                                       /*!< SS Position 31 */
#define EMIF_ASYNC_CS2_CR_SS_Msk     (0x1U << EMIF_ASYNC_CS2_CR_SS_Pos)                                          /*!< SS Mask 0x80000000 */
#define EMIF_ASYNC_CS2_CR_SS_Set(x)  (((uint32_t) (x) << EMIF_ASYNC_CS2_CR_SS_Pos) & EMIF_ASYNC_CS2_CR_SS_Msk)   /*!< SS Set Value */
#define EMIF_ASYNC_CS2_CR_SS_Get(x)  (((uint32_t) (x) & EMIF_ASYNC_CS2_CR_SS_Msk) >> EMIF_ASYNC_CS2_CR_SS_Pos)   /*!< SS Get Value */

#define EMIF_ASYNC_CS2_CR_EW_Pos     (30U)                                                                       /*!< EW Position 30 */
#define EMIF_ASYNC_CS2_CR_EW_Msk     (0x1U << EMIF_ASYNC_CS2_CR_EW_Pos)                                          /*!< EW Mask 0x40000000 */
#define EMIF_ASYNC_CS2_CR_EW_Set(x)  (((uint32_t) (x) << EMIF_ASYNC_CS2_CR_EW_Pos) & EMIF_ASYNC_CS2_CR_EW_Msk)   /*!< EW Set Value */
#define EMIF_ASYNC_CS2_CR_EW_Get(x)  (((uint32_t) (x) & EMIF_ASYNC_CS2_CR_EW_Msk) >> EMIF_ASYNC_CS2_CR_EW_Pos)   /*!< EW Get Value */

#define EMIF_ASYNC_CS2_CR_W_SETUP_Pos     (26U)                                                                                 /*!< W_SETUP Position 26 */
#define EMIF_ASYNC_CS2_CR_W_SETUP_Msk     (0xfU << EMIF_ASYNC_CS2_CR_W_SETUP_Pos)                                               /*!< W_SETUP Mask 0x3C000000 */
#define EMIF_ASYNC_CS2_CR_W_SETUP_Set(x)  (((uint32_t) (x) << EMIF_ASYNC_CS2_CR_W_SETUP_Pos) & EMIF_ASYNC_CS2_CR_W_SETUP_Msk)   /*!< W_SETUP Set Value */
#define EMIF_ASYNC_CS2_CR_W_SETUP_Get(x)  (((uint32_t) (x) & EMIF_ASYNC_CS2_CR_W_SETUP_Msk) >> EMIF_ASYNC_CS2_CR_W_SETUP_Pos)   /*!< W_SETUP Get Value */

#define EMIF_ASYNC_CS2_CR_W_STROBE_Pos     (20U)                                                                                   /*!< W_STROBE Position 20 */
#define EMIF_ASYNC_CS2_CR_W_STROBE_Msk     (0x3fU << EMIF_ASYNC_CS2_CR_W_STROBE_Pos)                                               /*!< W_STROBE Mask 0x03F00000 */
#define EMIF_ASYNC_CS2_CR_W_STROBE_Set(x)  (((uint32_t) (x) << EMIF_ASYNC_CS2_CR_W_STROBE_Pos) & EMIF_ASYNC_CS2_CR_W_STROBE_Msk)   /*!< W_STROBE Set Value */
#define EMIF_ASYNC_CS2_CR_W_STROBE_Get(x)  (((uint32_t) (x) & EMIF_ASYNC_CS2_CR_W_STROBE_Msk) >> EMIF_ASYNC_CS2_CR_W_STROBE_Pos)   /*!< W_STROBE Get Value */

#define EMIF_ASYNC_CS2_CR_W_HOLD_Pos     (17U)                                                                               /*!< W_HOLD Position 17 */
#define EMIF_ASYNC_CS2_CR_W_HOLD_Msk     (0x7U << EMIF_ASYNC_CS2_CR_W_HOLD_Pos)                                              /*!< W_HOLD Mask 0x000E0000 */
#define EMIF_ASYNC_CS2_CR_W_HOLD_Set(x)  (((uint32_t) (x) << EMIF_ASYNC_CS2_CR_W_HOLD_Pos) & EMIF_ASYNC_CS2_CR_W_HOLD_Msk)   /*!< W_HOLD Set Value */
#define EMIF_ASYNC_CS2_CR_W_HOLD_Get(x)  (((uint32_t) (x) & EMIF_ASYNC_CS2_CR_W_HOLD_Msk) >> EMIF_ASYNC_CS2_CR_W_HOLD_Pos)   /*!< W_HOLD Get Value */

#define EMIF_ASYNC_CS2_CR_R_SETUP_Pos     (13U)                                                                                 /*!< R_SETUP Position 13 */
#define EMIF_ASYNC_CS2_CR_R_SETUP_Msk     (0xfU << EMIF_ASYNC_CS2_CR_R_SETUP_Pos)                                               /*!< R_SETUP Mask 0x0001E000 */
#define EMIF_ASYNC_CS2_CR_R_SETUP_Set(x)  (((uint32_t) (x) << EMIF_ASYNC_CS2_CR_R_SETUP_Pos) & EMIF_ASYNC_CS2_CR_R_SETUP_Msk)   /*!< R_SETUP Set Value */
#define EMIF_ASYNC_CS2_CR_R_SETUP_Get(x)  (((uint32_t) (x) & EMIF_ASYNC_CS2_CR_R_SETUP_Msk) >> EMIF_ASYNC_CS2_CR_R_SETUP_Pos)   /*!< R_SETUP Get Value */

#define EMIF_ASYNC_CS2_CR_R_STROBE_Pos     (7U)                                                                                    /*!< R_STROBE Position 7 */
#define EMIF_ASYNC_CS2_CR_R_STROBE_Msk     (0x3fU << EMIF_ASYNC_CS2_CR_R_STROBE_Pos)                                               /*!< R_STROBE Mask 0x00001F80 */
#define EMIF_ASYNC_CS2_CR_R_STROBE_Set(x)  (((uint32_t) (x) << EMIF_ASYNC_CS2_CR_R_STROBE_Pos) & EMIF_ASYNC_CS2_CR_R_STROBE_Msk)   /*!< R_STROBE Set Value */
#define EMIF_ASYNC_CS2_CR_R_STROBE_Get(x)  (((uint32_t) (x) & EMIF_ASYNC_CS2_CR_R_STROBE_Msk) >> EMIF_ASYNC_CS2_CR_R_STROBE_Pos)   /*!< R_STROBE Get Value */

#define EMIF_ASYNC_CS2_CR_R_HOLD_Pos     (4U)                                                                                /*!< R_HOLD Position 4 */
#define EMIF_ASYNC_CS2_CR_R_HOLD_Msk     (0x7U << EMIF_ASYNC_CS2_CR_R_HOLD_Pos)                                              /*!< R_HOLD Mask 0x00000070 */
#define EMIF_ASYNC_CS2_CR_R_HOLD_Set(x)  (((uint32_t) (x) << EMIF_ASYNC_CS2_CR_R_HOLD_Pos) & EMIF_ASYNC_CS2_CR_R_HOLD_Msk)   /*!< R_HOLD Set Value */
#define EMIF_ASYNC_CS2_CR_R_HOLD_Get(x)  (((uint32_t) (x) & EMIF_ASYNC_CS2_CR_R_HOLD_Msk) >> EMIF_ASYNC_CS2_CR_R_HOLD_Pos)   /*!< R_HOLD Get Value */

#define EMIF_ASYNC_CS2_CR_TA_Pos     (2U)                                                                        /*!< TA Position 2 */
#define EMIF_ASYNC_CS2_CR_TA_Msk     (0x3U << EMIF_ASYNC_CS2_CR_TA_Pos)                                          /*!< TA Mask 0x0000000C */
#define EMIF_ASYNC_CS2_CR_TA_Set(x)  (((uint32_t) (x) << EMIF_ASYNC_CS2_CR_TA_Pos) & EMIF_ASYNC_CS2_CR_TA_Msk)   /*!< TA Set Value */
#define EMIF_ASYNC_CS2_CR_TA_Get(x)  (((uint32_t) (x) & EMIF_ASYNC_CS2_CR_TA_Msk) >> EMIF_ASYNC_CS2_CR_TA_Pos)   /*!< TA Get Value */

#define EMIF_ASYNC_CS2_CR_ASIZE_Pos     (0U)                                                                              /*!< ASIZE Position 0 */
#define EMIF_ASYNC_CS2_CR_ASIZE_Msk     (0x3U << EMIF_ASYNC_CS2_CR_ASIZE_Pos)                                             /*!< ASIZE Mask 0x00000003 */
#define EMIF_ASYNC_CS2_CR_ASIZE_Set(x)  (((uint32_t) (x) << EMIF_ASYNC_CS2_CR_ASIZE_Pos) & EMIF_ASYNC_CS2_CR_ASIZE_Msk)   /*!< ASIZE Set Value */
#define EMIF_ASYNC_CS2_CR_ASIZE_Get(x)  (((uint32_t) (x) & EMIF_ASYNC_CS2_CR_ASIZE_Msk) >> EMIF_ASYNC_CS2_CR_ASIZE_Pos)   /*!< ASIZE Get Value */

/* ASYNC_CS3_CR bitfield */
#define EMIF_ASYNC_CS3_CR_SS_Pos     (31U)                                                                       /*!< SS Position 31 */
#define EMIF_ASYNC_CS3_CR_SS_Msk     (0x1U << EMIF_ASYNC_CS3_CR_SS_Pos)                                          /*!< SS Mask 0x80000000 */
#define EMIF_ASYNC_CS3_CR_SS_Set(x)  (((uint32_t) (x) << EMIF_ASYNC_CS3_CR_SS_Pos) & EMIF_ASYNC_CS3_CR_SS_Msk)   /*!< SS Set Value */
#define EMIF_ASYNC_CS3_CR_SS_Get(x)  (((uint32_t) (x) & EMIF_ASYNC_CS3_CR_SS_Msk) >> EMIF_ASYNC_CS3_CR_SS_Pos)   /*!< SS Get Value */

#define EMIF_ASYNC_CS3_CR_EW_Pos     (30U)                                                                       /*!< EW Position 30 */
#define EMIF_ASYNC_CS3_CR_EW_Msk     (0x1U << EMIF_ASYNC_CS3_CR_EW_Pos)                                          /*!< EW Mask 0x40000000 */
#define EMIF_ASYNC_CS3_CR_EW_Set(x)  (((uint32_t) (x) << EMIF_ASYNC_CS3_CR_EW_Pos) & EMIF_ASYNC_CS3_CR_EW_Msk)   /*!< EW Set Value */
#define EMIF_ASYNC_CS3_CR_EW_Get(x)  (((uint32_t) (x) & EMIF_ASYNC_CS3_CR_EW_Msk) >> EMIF_ASYNC_CS3_CR_EW_Pos)   /*!< EW Get Value */

#define EMIF_ASYNC_CS3_CR_W_SETUP_Pos     (26U)                                                                                 /*!< W_SETUP Position 26 */
#define EMIF_ASYNC_CS3_CR_W_SETUP_Msk     (0xfU << EMIF_ASYNC_CS3_CR_W_SETUP_Pos)                                               /*!< W_SETUP Mask 0x3C000000 */
#define EMIF_ASYNC_CS3_CR_W_SETUP_Set(x)  (((uint32_t) (x) << EMIF_ASYNC_CS3_CR_W_SETUP_Pos) & EMIF_ASYNC_CS3_CR_W_SETUP_Msk)   /*!< W_SETUP Set Value */
#define EMIF_ASYNC_CS3_CR_W_SETUP_Get(x)  (((uint32_t) (x) & EMIF_ASYNC_CS3_CR_W_SETUP_Msk) >> EMIF_ASYNC_CS3_CR_W_SETUP_Pos)   /*!< W_SETUP Get Value */

#define EMIF_ASYNC_CS3_CR_W_STROBE_Pos     (20U)                                                                                   /*!< W_STROBE Position 20 */
#define EMIF_ASYNC_CS3_CR_W_STROBE_Msk     (0x3fU << EMIF_ASYNC_CS3_CR_W_STROBE_Pos)                                               /*!< W_STROBE Mask 0x03F00000 */
#define EMIF_ASYNC_CS3_CR_W_STROBE_Set(x)  (((uint32_t) (x) << EMIF_ASYNC_CS3_CR_W_STROBE_Pos) & EMIF_ASYNC_CS3_CR_W_STROBE_Msk)   /*!< W_STROBE Set Value */
#define EMIF_ASYNC_CS3_CR_W_STROBE_Get(x)  (((uint32_t) (x) & EMIF_ASYNC_CS3_CR_W_STROBE_Msk) >> EMIF_ASYNC_CS3_CR_W_STROBE_Pos)   /*!< W_STROBE Get Value */

#define EMIF_ASYNC_CS3_CR_W_HOLD_Pos     (17U)                                                                               /*!< W_HOLD Position 17 */
#define EMIF_ASYNC_CS3_CR_W_HOLD_Msk     (0x7U << EMIF_ASYNC_CS3_CR_W_HOLD_Pos)                                              /*!< W_HOLD Mask 0x000E0000 */
#define EMIF_ASYNC_CS3_CR_W_HOLD_Set(x)  (((uint32_t) (x) << EMIF_ASYNC_CS3_CR_W_HOLD_Pos) & EMIF_ASYNC_CS3_CR_W_HOLD_Msk)   /*!< W_HOLD Set Value */
#define EMIF_ASYNC_CS3_CR_W_HOLD_Get(x)  (((uint32_t) (x) & EMIF_ASYNC_CS3_CR_W_HOLD_Msk) >> EMIF_ASYNC_CS3_CR_W_HOLD_Pos)   /*!< W_HOLD Get Value */

#define EMIF_ASYNC_CS3_CR_R_SETUP_Pos     (13U)                                                                                 /*!< R_SETUP Position 13 */
#define EMIF_ASYNC_CS3_CR_R_SETUP_Msk     (0xfU << EMIF_ASYNC_CS3_CR_R_SETUP_Pos)                                               /*!< R_SETUP Mask 0x0001E000 */
#define EMIF_ASYNC_CS3_CR_R_SETUP_Set(x)  (((uint32_t) (x) << EMIF_ASYNC_CS3_CR_R_SETUP_Pos) & EMIF_ASYNC_CS3_CR_R_SETUP_Msk)   /*!< R_SETUP Set Value */
#define EMIF_ASYNC_CS3_CR_R_SETUP_Get(x)  (((uint32_t) (x) & EMIF_ASYNC_CS3_CR_R_SETUP_Msk) >> EMIF_ASYNC_CS3_CR_R_SETUP_Pos)   /*!< R_SETUP Get Value */

#define EMIF_ASYNC_CS3_CR_R_STROBE_Pos     (7U)                                                                                    /*!< R_STROBE Position 7 */
#define EMIF_ASYNC_CS3_CR_R_STROBE_Msk     (0x3fU << EMIF_ASYNC_CS3_CR_R_STROBE_Pos)                                               /*!< R_STROBE Mask 0x00001F80 */
#define EMIF_ASYNC_CS3_CR_R_STROBE_Set(x)  (((uint32_t) (x) << EMIF_ASYNC_CS3_CR_R_STROBE_Pos) & EMIF_ASYNC_CS3_CR_R_STROBE_Msk)   /*!< R_STROBE Set Value */
#define EMIF_ASYNC_CS3_CR_R_STROBE_Get(x)  (((uint32_t) (x) & EMIF_ASYNC_CS3_CR_R_STROBE_Msk) >> EMIF_ASYNC_CS3_CR_R_STROBE_Pos)   /*!< R_STROBE Get Value */

#define EMIF_ASYNC_CS3_CR_R_HOLD_Pos     (4U)                                                                                /*!< R_HOLD Position 4 */
#define EMIF_ASYNC_CS3_CR_R_HOLD_Msk     (0x7U << EMIF_ASYNC_CS3_CR_R_HOLD_Pos)                                              /*!< R_HOLD Mask 0x00000070 */
#define EMIF_ASYNC_CS3_CR_R_HOLD_Set(x)  (((uint32_t) (x) << EMIF_ASYNC_CS3_CR_R_HOLD_Pos) & EMIF_ASYNC_CS3_CR_R_HOLD_Msk)   /*!< R_HOLD Set Value */
#define EMIF_ASYNC_CS3_CR_R_HOLD_Get(x)  (((uint32_t) (x) & EMIF_ASYNC_CS3_CR_R_HOLD_Msk) >> EMIF_ASYNC_CS3_CR_R_HOLD_Pos)   /*!< R_HOLD Get Value */

#define EMIF_ASYNC_CS3_CR_TA_Pos     (2U)                                                                        /*!< TA Position 2 */
#define EMIF_ASYNC_CS3_CR_TA_Msk     (0x3U << EMIF_ASYNC_CS3_CR_TA_Pos)                                          /*!< TA Mask 0x0000000C */
#define EMIF_ASYNC_CS3_CR_TA_Set(x)  (((uint32_t) (x) << EMIF_ASYNC_CS3_CR_TA_Pos) & EMIF_ASYNC_CS3_CR_TA_Msk)   /*!< TA Set Value */
#define EMIF_ASYNC_CS3_CR_TA_Get(x)  (((uint32_t) (x) & EMIF_ASYNC_CS3_CR_TA_Msk) >> EMIF_ASYNC_CS3_CR_TA_Pos)   /*!< TA Get Value */

#define EMIF_ASYNC_CS3_CR_ASIZE_Pos     (0U)                                                                              /*!< ASIZE Position 0 */
#define EMIF_ASYNC_CS3_CR_ASIZE_Msk     (0x3U << EMIF_ASYNC_CS3_CR_ASIZE_Pos)                                             /*!< ASIZE Mask 0x00000003 */
#define EMIF_ASYNC_CS3_CR_ASIZE_Set(x)  (((uint32_t) (x) << EMIF_ASYNC_CS3_CR_ASIZE_Pos) & EMIF_ASYNC_CS3_CR_ASIZE_Msk)   /*!< ASIZE Set Value */
#define EMIF_ASYNC_CS3_CR_ASIZE_Get(x)  (((uint32_t) (x) & EMIF_ASYNC_CS3_CR_ASIZE_Msk) >> EMIF_ASYNC_CS3_CR_ASIZE_Pos)   /*!< ASIZE Get Value */

/* ASYNC_CS4_CR bitfield */
#define EMIF_ASYNC_CS4_CR_SS_Pos     (31U)                                                                       /*!< SS Position 31 */
#define EMIF_ASYNC_CS4_CR_SS_Msk     (0x1U << EMIF_ASYNC_CS4_CR_SS_Pos)                                          /*!< SS Mask 0x80000000 */
#define EMIF_ASYNC_CS4_CR_SS_Set(x)  (((uint32_t) (x) << EMIF_ASYNC_CS4_CR_SS_Pos) & EMIF_ASYNC_CS4_CR_SS_Msk)   /*!< SS Set Value */
#define EMIF_ASYNC_CS4_CR_SS_Get(x)  (((uint32_t) (x) & EMIF_ASYNC_CS4_CR_SS_Msk) >> EMIF_ASYNC_CS4_CR_SS_Pos)   /*!< SS Get Value */

#define EMIF_ASYNC_CS4_CR_EW_Pos     (30U)                                                                       /*!< EW Position 30 */
#define EMIF_ASYNC_CS4_CR_EW_Msk     (0x1U << EMIF_ASYNC_CS4_CR_EW_Pos)                                          /*!< EW Mask 0x40000000 */
#define EMIF_ASYNC_CS4_CR_EW_Set(x)  (((uint32_t) (x) << EMIF_ASYNC_CS4_CR_EW_Pos) & EMIF_ASYNC_CS4_CR_EW_Msk)   /*!< EW Set Value */
#define EMIF_ASYNC_CS4_CR_EW_Get(x)  (((uint32_t) (x) & EMIF_ASYNC_CS4_CR_EW_Msk) >> EMIF_ASYNC_CS4_CR_EW_Pos)   /*!< EW Get Value */

#define EMIF_ASYNC_CS4_CR_W_SETUP_Pos     (26U)                                                                                 /*!< W_SETUP Position 26 */
#define EMIF_ASYNC_CS4_CR_W_SETUP_Msk     (0xfU << EMIF_ASYNC_CS4_CR_W_SETUP_Pos)                                               /*!< W_SETUP Mask 0x3C000000 */
#define EMIF_ASYNC_CS4_CR_W_SETUP_Set(x)  (((uint32_t) (x) << EMIF_ASYNC_CS4_CR_W_SETUP_Pos) & EMIF_ASYNC_CS4_CR_W_SETUP_Msk)   /*!< W_SETUP Set Value */
#define EMIF_ASYNC_CS4_CR_W_SETUP_Get(x)  (((uint32_t) (x) & EMIF_ASYNC_CS4_CR_W_SETUP_Msk) >> EMIF_ASYNC_CS4_CR_W_SETUP_Pos)   /*!< W_SETUP Get Value */

#define EMIF_ASYNC_CS4_CR_W_STROBE_Pos     (20U)                                                                                   /*!< W_STROBE Position 20 */
#define EMIF_ASYNC_CS4_CR_W_STROBE_Msk     (0x3fU << EMIF_ASYNC_CS4_CR_W_STROBE_Pos)                                               /*!< W_STROBE Mask 0x03F00000 */
#define EMIF_ASYNC_CS4_CR_W_STROBE_Set(x)  (((uint32_t) (x) << EMIF_ASYNC_CS4_CR_W_STROBE_Pos) & EMIF_ASYNC_CS4_CR_W_STROBE_Msk)   /*!< W_STROBE Set Value */
#define EMIF_ASYNC_CS4_CR_W_STROBE_Get(x)  (((uint32_t) (x) & EMIF_ASYNC_CS4_CR_W_STROBE_Msk) >> EMIF_ASYNC_CS4_CR_W_STROBE_Pos)   /*!< W_STROBE Get Value */

#define EMIF_ASYNC_CS4_CR_W_HOLD_Pos     (17U)                                                                               /*!< W_HOLD Position 17 */
#define EMIF_ASYNC_CS4_CR_W_HOLD_Msk     (0x7U << EMIF_ASYNC_CS4_CR_W_HOLD_Pos)                                              /*!< W_HOLD Mask 0x000E0000 */
#define EMIF_ASYNC_CS4_CR_W_HOLD_Set(x)  (((uint32_t) (x) << EMIF_ASYNC_CS4_CR_W_HOLD_Pos) & EMIF_ASYNC_CS4_CR_W_HOLD_Msk)   /*!< W_HOLD Set Value */
#define EMIF_ASYNC_CS4_CR_W_HOLD_Get(x)  (((uint32_t) (x) & EMIF_ASYNC_CS4_CR_W_HOLD_Msk) >> EMIF_ASYNC_CS4_CR_W_HOLD_Pos)   /*!< W_HOLD Get Value */

#define EMIF_ASYNC_CS4_CR_R_SETUP_Pos     (13U)                                                                                 /*!< R_SETUP Position 13 */
#define EMIF_ASYNC_CS4_CR_R_SETUP_Msk     (0xfU << EMIF_ASYNC_CS4_CR_R_SETUP_Pos)                                               /*!< R_SETUP Mask 0x0001E000 */
#define EMIF_ASYNC_CS4_CR_R_SETUP_Set(x)  (((uint32_t) (x) << EMIF_ASYNC_CS4_CR_R_SETUP_Pos) & EMIF_ASYNC_CS4_CR_R_SETUP_Msk)   /*!< R_SETUP Set Value */
#define EMIF_ASYNC_CS4_CR_R_SETUP_Get(x)  (((uint32_t) (x) & EMIF_ASYNC_CS4_CR_R_SETUP_Msk) >> EMIF_ASYNC_CS4_CR_R_SETUP_Pos)   /*!< R_SETUP Get Value */

#define EMIF_ASYNC_CS4_CR_R_STROBE_Pos     (7U)                                                                                    /*!< R_STROBE Position 7 */
#define EMIF_ASYNC_CS4_CR_R_STROBE_Msk     (0x3fU << EMIF_ASYNC_CS4_CR_R_STROBE_Pos)                                               /*!< R_STROBE Mask 0x00001F80 */
#define EMIF_ASYNC_CS4_CR_R_STROBE_Set(x)  (((uint32_t) (x) << EMIF_ASYNC_CS4_CR_R_STROBE_Pos) & EMIF_ASYNC_CS4_CR_R_STROBE_Msk)   /*!< R_STROBE Set Value */
#define EMIF_ASYNC_CS4_CR_R_STROBE_Get(x)  (((uint32_t) (x) & EMIF_ASYNC_CS4_CR_R_STROBE_Msk) >> EMIF_ASYNC_CS4_CR_R_STROBE_Pos)   /*!< R_STROBE Get Value */

#define EMIF_ASYNC_CS4_CR_R_HOLD_Pos     (4U)                                                                                /*!< R_HOLD Position 4 */
#define EMIF_ASYNC_CS4_CR_R_HOLD_Msk     (0x7U << EMIF_ASYNC_CS4_CR_R_HOLD_Pos)                                              /*!< R_HOLD Mask 0x00000070 */
#define EMIF_ASYNC_CS4_CR_R_HOLD_Set(x)  (((uint32_t) (x) << EMIF_ASYNC_CS4_CR_R_HOLD_Pos) & EMIF_ASYNC_CS4_CR_R_HOLD_Msk)   /*!< R_HOLD Set Value */
#define EMIF_ASYNC_CS4_CR_R_HOLD_Get(x)  (((uint32_t) (x) & EMIF_ASYNC_CS4_CR_R_HOLD_Msk) >> EMIF_ASYNC_CS4_CR_R_HOLD_Pos)   /*!< R_HOLD Get Value */

#define EMIF_ASYNC_CS4_CR_TA_Pos     (2U)                                                                        /*!< TA Position 2 */
#define EMIF_ASYNC_CS4_CR_TA_Msk     (0x3U << EMIF_ASYNC_CS4_CR_TA_Pos)                                          /*!< TA Mask 0x0000000C */
#define EMIF_ASYNC_CS4_CR_TA_Set(x)  (((uint32_t) (x) << EMIF_ASYNC_CS4_CR_TA_Pos) & EMIF_ASYNC_CS4_CR_TA_Msk)   /*!< TA Set Value */
#define EMIF_ASYNC_CS4_CR_TA_Get(x)  (((uint32_t) (x) & EMIF_ASYNC_CS4_CR_TA_Msk) >> EMIF_ASYNC_CS4_CR_TA_Pos)   /*!< TA Get Value */

#define EMIF_ASYNC_CS4_CR_ASIZE_Pos     (0U)                                                                              /*!< ASIZE Position 0 */
#define EMIF_ASYNC_CS4_CR_ASIZE_Msk     (0x3U << EMIF_ASYNC_CS4_CR_ASIZE_Pos)                                             /*!< ASIZE Mask 0x00000003 */
#define EMIF_ASYNC_CS4_CR_ASIZE_Set(x)  (((uint32_t) (x) << EMIF_ASYNC_CS4_CR_ASIZE_Pos) & EMIF_ASYNC_CS4_CR_ASIZE_Msk)   /*!< ASIZE Set Value */
#define EMIF_ASYNC_CS4_CR_ASIZE_Get(x)  (((uint32_t) (x) & EMIF_ASYNC_CS4_CR_ASIZE_Msk) >> EMIF_ASYNC_CS4_CR_ASIZE_Pos)   /*!< ASIZE Get Value */

/* SDRAM_TR bitfield */
#define EMIF_SDRAM_TR_T_RFC_Pos     (27U)                                                                     /*!< T_RFC Position 27 */
#define EMIF_SDRAM_TR_T_RFC_Msk     (0x1fU << EMIF_SDRAM_TR_T_RFC_Pos)                                        /*!< T_RFC Mask 0xF8000000 */
#define EMIF_SDRAM_TR_T_RFC_Set(x)  (((uint32_t) (x) << EMIF_SDRAM_TR_T_RFC_Pos) & EMIF_SDRAM_TR_T_RFC_Msk)   /*!< T_RFC Set Value */
#define EMIF_SDRAM_TR_T_RFC_Get(x)  (((uint32_t) (x) & EMIF_SDRAM_TR_T_RFC_Msk) >> EMIF_SDRAM_TR_T_RFC_Pos)   /*!< T_RFC Get Value */

#define EMIF_SDRAM_TR_T_RP_Pos     (24U)                                                                   /*!< T_RP Position 24 */
#define EMIF_SDRAM_TR_T_RP_Msk     (0x7U << EMIF_SDRAM_TR_T_RP_Pos)                                        /*!< T_RP Mask 0x07000000 */
#define EMIF_SDRAM_TR_T_RP_Set(x)  (((uint32_t) (x) << EMIF_SDRAM_TR_T_RP_Pos) & EMIF_SDRAM_TR_T_RP_Msk)   /*!< T_RP Set Value */
#define EMIF_SDRAM_TR_T_RP_Get(x)  (((uint32_t) (x) & EMIF_SDRAM_TR_T_RP_Msk) >> EMIF_SDRAM_TR_T_RP_Pos)   /*!< T_RP Get Value */

#define EMIF_SDRAM_TR_T_RCD_Pos     (20U)                                                                     /*!< T_RCD Position 20 */
#define EMIF_SDRAM_TR_T_RCD_Msk     (0x7U << EMIF_SDRAM_TR_T_RCD_Pos)                                         /*!< T_RCD Mask 0x00700000 */
#define EMIF_SDRAM_TR_T_RCD_Set(x)  (((uint32_t) (x) << EMIF_SDRAM_TR_T_RCD_Pos) & EMIF_SDRAM_TR_T_RCD_Msk)   /*!< T_RCD Set Value */
#define EMIF_SDRAM_TR_T_RCD_Get(x)  (((uint32_t) (x) & EMIF_SDRAM_TR_T_RCD_Msk) >> EMIF_SDRAM_TR_T_RCD_Pos)   /*!< T_RCD Get Value */

#define EMIF_SDRAM_TR_T_WR_Pos     (16U)                                                                   /*!< T_WR Position 16 */
#define EMIF_SDRAM_TR_T_WR_Msk     (0x7U << EMIF_SDRAM_TR_T_WR_Pos)                                        /*!< T_WR Mask 0x00070000 */
#define EMIF_SDRAM_TR_T_WR_Set(x)  (((uint32_t) (x) << EMIF_SDRAM_TR_T_WR_Pos) & EMIF_SDRAM_TR_T_WR_Msk)   /*!< T_WR Set Value */
#define EMIF_SDRAM_TR_T_WR_Get(x)  (((uint32_t) (x) & EMIF_SDRAM_TR_T_WR_Msk) >> EMIF_SDRAM_TR_T_WR_Pos)   /*!< T_WR Get Value */

#define EMIF_SDRAM_TR_T_RAS_Pos     (12U)                                                                     /*!< T_RAS Position 12 */
#define EMIF_SDRAM_TR_T_RAS_Msk     (0xfU << EMIF_SDRAM_TR_T_RAS_Pos)                                         /*!< T_RAS Mask 0x0000F000 */
#define EMIF_SDRAM_TR_T_RAS_Set(x)  (((uint32_t) (x) << EMIF_SDRAM_TR_T_RAS_Pos) & EMIF_SDRAM_TR_T_RAS_Msk)   /*!< T_RAS Set Value */
#define EMIF_SDRAM_TR_T_RAS_Get(x)  (((uint32_t) (x) & EMIF_SDRAM_TR_T_RAS_Msk) >> EMIF_SDRAM_TR_T_RAS_Pos)   /*!< T_RAS Get Value */

#define EMIF_SDRAM_TR_T_RC_Pos     (8U)                                                                    /*!< T_RC Position 8 */
#define EMIF_SDRAM_TR_T_RC_Msk     (0xfU << EMIF_SDRAM_TR_T_RC_Pos)                                        /*!< T_RC Mask 0x00000F00 */
#define EMIF_SDRAM_TR_T_RC_Set(x)  (((uint32_t) (x) << EMIF_SDRAM_TR_T_RC_Pos) & EMIF_SDRAM_TR_T_RC_Msk)   /*!< T_RC Set Value */
#define EMIF_SDRAM_TR_T_RC_Get(x)  (((uint32_t) (x) & EMIF_SDRAM_TR_T_RC_Msk) >> EMIF_SDRAM_TR_T_RC_Pos)   /*!< T_RC Get Value */

#define EMIF_SDRAM_TR_T_RRD_Pos     (4U)                                                                      /*!< T_RRD Position 4 */
#define EMIF_SDRAM_TR_T_RRD_Msk     (0x7U << EMIF_SDRAM_TR_T_RRD_Pos)                                         /*!< T_RRD Mask 0x00000070 */
#define EMIF_SDRAM_TR_T_RRD_Set(x)  (((uint32_t) (x) << EMIF_SDRAM_TR_T_RRD_Pos) & EMIF_SDRAM_TR_T_RRD_Msk)   /*!< T_RRD Set Value */
#define EMIF_SDRAM_TR_T_RRD_Get(x)  (((uint32_t) (x) & EMIF_SDRAM_TR_T_RRD_Msk) >> EMIF_SDRAM_TR_T_RRD_Pos)   /*!< T_RRD Get Value */

/* TOTAL_SDRAM_AR bitfield */
#define EMIF_TOTAL_SDRAM_AR_TOTAL_SDRAM_AR_Pos     (0U)                                                                                                    /*!< TOTAL_SDRAM_AR Position 0 */
#define EMIF_TOTAL_SDRAM_AR_TOTAL_SDRAM_AR_Msk     (0xffffffffU << EMIF_TOTAL_SDRAM_AR_TOTAL_SDRAM_AR_Pos)                                                 /*!< TOTAL_SDRAM_AR Mask 0xFFFFFFFF */
#define EMIF_TOTAL_SDRAM_AR_TOTAL_SDRAM_AR_Set(x)  (((uint32_t) (x) << EMIF_TOTAL_SDRAM_AR_TOTAL_SDRAM_AR_Pos) & EMIF_TOTAL_SDRAM_AR_TOTAL_SDRAM_AR_Msk)   /*!< TOTAL_SDRAM_AR Set Value */
#define EMIF_TOTAL_SDRAM_AR_TOTAL_SDRAM_AR_Get(x)  (((uint32_t) (x) & EMIF_TOTAL_SDRAM_AR_TOTAL_SDRAM_AR_Msk) >> EMIF_TOTAL_SDRAM_AR_TOTAL_SDRAM_AR_Pos)   /*!< TOTAL_SDRAM_AR Get Value */

/* TOTAL_SDRAM_ACTR bitfield */
#define EMIF_TOTAL_SDRAM_ACTR_TOTAL_SDRAM_ACTR_Pos     (0U)                                                                                                            /*!< TOTAL_SDRAM_ACTR Position 0 */
#define EMIF_TOTAL_SDRAM_ACTR_TOTAL_SDRAM_ACTR_Msk     (0xffffffffU << EMIF_TOTAL_SDRAM_ACTR_TOTAL_SDRAM_ACTR_Pos)                                                     /*!< TOTAL_SDRAM_ACTR Mask 0xFFFFFFFF */
#define EMIF_TOTAL_SDRAM_ACTR_TOTAL_SDRAM_ACTR_Set(x)  (((uint32_t) (x) << EMIF_TOTAL_SDRAM_ACTR_TOTAL_SDRAM_ACTR_Pos) & EMIF_TOTAL_SDRAM_ACTR_TOTAL_SDRAM_ACTR_Msk)   /*!< TOTAL_SDRAM_ACTR Set Value */
#define EMIF_TOTAL_SDRAM_ACTR_TOTAL_SDRAM_ACTR_Get(x)  (((uint32_t) (x) & EMIF_TOTAL_SDRAM_ACTR_TOTAL_SDRAM_ACTR_Msk) >> EMIF_TOTAL_SDRAM_ACTR_TOTAL_SDRAM_ACTR_Pos)   /*!< TOTAL_SDRAM_ACTR Get Value */

/* SDR_EXT_TMNG bitfield */
#define EMIF_SDR_EXT_TMNG_T_XS_Pos     (0U)                                                                            /*!< T_XS Position 0 */
#define EMIF_SDR_EXT_TMNG_T_XS_Msk     (0x1fU << EMIF_SDR_EXT_TMNG_T_XS_Pos)                                           /*!< T_XS Mask 0x0000001F */
#define EMIF_SDR_EXT_TMNG_T_XS_Set(x)  (((uint32_t) (x) << EMIF_SDR_EXT_TMNG_T_XS_Pos) & EMIF_SDR_EXT_TMNG_T_XS_Msk)   /*!< T_XS Set Value */
#define EMIF_SDR_EXT_TMNG_T_XS_Get(x)  (((uint32_t) (x) & EMIF_SDR_EXT_TMNG_T_XS_Msk) >> EMIF_SDR_EXT_TMNG_T_XS_Pos)   /*!< T_XS Get Value */

/* INT_RAW bitfield */
#define EMIF_INT_RAW_WR_FLAG_Pos     (2U)                                                                        /*!< WR_FLAG Position 2 */
#define EMIF_INT_RAW_WR_FLAG_Msk     (0x1U << EMIF_INT_RAW_WR_FLAG_Pos)                                          /*!< WR_FLAG Mask 0x00000004 */
#define EMIF_INT_RAW_WR_FLAG_Set(x)  (((uint32_t) (x) << EMIF_INT_RAW_WR_FLAG_Pos) & EMIF_INT_RAW_WR_FLAG_Msk)   /*!< WR_FLAG Set Value */
#define EMIF_INT_RAW_WR_FLAG_Get(x)  (((uint32_t) (x) & EMIF_INT_RAW_WR_FLAG_Msk) >> EMIF_INT_RAW_WR_FLAG_Pos)   /*!< WR_FLAG Get Value */

#define EMIF_INT_RAW_LT_FLAG_Pos     (1U)                                                                        /*!< LT_FLAG Position 1 */
#define EMIF_INT_RAW_LT_FLAG_Msk     (0x1U << EMIF_INT_RAW_LT_FLAG_Pos)                                          /*!< LT_FLAG Mask 0x00000002 */
#define EMIF_INT_RAW_LT_FLAG_Set(x)  (((uint32_t) (x) << EMIF_INT_RAW_LT_FLAG_Pos) & EMIF_INT_RAW_LT_FLAG_Msk)   /*!< LT_FLAG Set Value */
#define EMIF_INT_RAW_LT_FLAG_Get(x)  (((uint32_t) (x) & EMIF_INT_RAW_LT_FLAG_Msk) >> EMIF_INT_RAW_LT_FLAG_Pos)   /*!< LT_FLAG Get Value */

#define EMIF_INT_RAW_AT_FLAG_Pos     (0U)                                                                        /*!< AT_FLAG Position 0 */
#define EMIF_INT_RAW_AT_FLAG_Msk     (0x1U << EMIF_INT_RAW_AT_FLAG_Pos)                                          /*!< AT_FLAG Mask 0x00000001 */
#define EMIF_INT_RAW_AT_FLAG_Set(x)  (((uint32_t) (x) << EMIF_INT_RAW_AT_FLAG_Pos) & EMIF_INT_RAW_AT_FLAG_Msk)   /*!< AT_FLAG Set Value */
#define EMIF_INT_RAW_AT_FLAG_Get(x)  (((uint32_t) (x) & EMIF_INT_RAW_AT_FLAG_Msk) >> EMIF_INT_RAW_AT_FLAG_Pos)   /*!< AT_FLAG Get Value */

/* INT_EN bitfield */
#define EMIF_INT_EN_WR_IEN_Pos     (2U)                                                                    /*!< WR_IEN Position 2 */
#define EMIF_INT_EN_WR_IEN_Msk     (0x1U << EMIF_INT_EN_WR_IEN_Pos)                                        /*!< WR_IEN Mask 0x00000004 */
#define EMIF_INT_EN_WR_IEN_Set(x)  (((uint32_t) (x) << EMIF_INT_EN_WR_IEN_Pos) & EMIF_INT_EN_WR_IEN_Msk)   /*!< WR_IEN Set Value */
#define EMIF_INT_EN_WR_IEN_Get(x)  (((uint32_t) (x) & EMIF_INT_EN_WR_IEN_Msk) >> EMIF_INT_EN_WR_IEN_Pos)   /*!< WR_IEN Get Value */

#define EMIF_INT_EN_LT_IEN_Pos     (1U)                                                                    /*!< LT_IEN Position 1 */
#define EMIF_INT_EN_LT_IEN_Msk     (0x1U << EMIF_INT_EN_LT_IEN_Pos)                                        /*!< LT_IEN Mask 0x00000002 */
#define EMIF_INT_EN_LT_IEN_Set(x)  (((uint32_t) (x) << EMIF_INT_EN_LT_IEN_Pos) & EMIF_INT_EN_LT_IEN_Msk)   /*!< LT_IEN Set Value */
#define EMIF_INT_EN_LT_IEN_Get(x)  (((uint32_t) (x) & EMIF_INT_EN_LT_IEN_Msk) >> EMIF_INT_EN_LT_IEN_Pos)   /*!< LT_IEN Get Value */

#define EMIF_INT_EN_AT_IEN_Pos     (0U)                                                                    /*!< AT_IEN Position 0 */
#define EMIF_INT_EN_AT_IEN_Msk     (0x1U << EMIF_INT_EN_AT_IEN_Pos)                                        /*!< AT_IEN Mask 0x00000001 */
#define EMIF_INT_EN_AT_IEN_Set(x)  (((uint32_t) (x) << EMIF_INT_EN_AT_IEN_Pos) & EMIF_INT_EN_AT_IEN_Msk)   /*!< AT_IEN Set Value */
#define EMIF_INT_EN_AT_IEN_Get(x)  (((uint32_t) (x) & EMIF_INT_EN_AT_IEN_Msk) >> EMIF_INT_EN_AT_IEN_Pos)   /*!< AT_IEN Get Value */

/* INT_MSK_SET bitfield */
#define EMIF_INT_MSK_SET_WR_FLAG_SET_Pos     (2U)                                                                                        /*!< WR_FLAG_SET Position 2 */
#define EMIF_INT_MSK_SET_WR_FLAG_SET_Msk     (0x1U << EMIF_INT_MSK_SET_WR_FLAG_SET_Pos)                                                  /*!< WR_FLAG_SET Mask 0x00000004 */
#define EMIF_INT_MSK_SET_WR_FLAG_SET_Set(x)  (((uint32_t) (x) << EMIF_INT_MSK_SET_WR_FLAG_SET_Pos) & EMIF_INT_MSK_SET_WR_FLAG_SET_Msk)   /*!< WR_FLAG_SET Set Value */
#define EMIF_INT_MSK_SET_WR_FLAG_SET_Get(x)  (((uint32_t) (x) & EMIF_INT_MSK_SET_WR_FLAG_SET_Msk) >> EMIF_INT_MSK_SET_WR_FLAG_SET_Pos)   /*!< WR_FLAG_SET Get Value */

#define EMIF_INT_MSK_SET_LT_FLAG_SET_Pos     (1U)                                                                                        /*!< LT_FLAG_SET Position 1 */
#define EMIF_INT_MSK_SET_LT_FLAG_SET_Msk     (0x1U << EMIF_INT_MSK_SET_LT_FLAG_SET_Pos)                                                  /*!< LT_FLAG_SET Mask 0x00000002 */
#define EMIF_INT_MSK_SET_LT_FLAG_SET_Set(x)  (((uint32_t) (x) << EMIF_INT_MSK_SET_LT_FLAG_SET_Pos) & EMIF_INT_MSK_SET_LT_FLAG_SET_Msk)   /*!< LT_FLAG_SET Set Value */
#define EMIF_INT_MSK_SET_LT_FLAG_SET_Get(x)  (((uint32_t) (x) & EMIF_INT_MSK_SET_LT_FLAG_SET_Msk) >> EMIF_INT_MSK_SET_LT_FLAG_SET_Pos)   /*!< LT_FLAG_SET Get Value */

#define EMIF_INT_MSK_SET_AT_FLAG_SET_Pos     (0U)                                                                                        /*!< AT_FLAG_SET Position 0 */
#define EMIF_INT_MSK_SET_AT_FLAG_SET_Msk     (0x1U << EMIF_INT_MSK_SET_AT_FLAG_SET_Pos)                                                  /*!< AT_FLAG_SET Mask 0x00000001 */
#define EMIF_INT_MSK_SET_AT_FLAG_SET_Set(x)  (((uint32_t) (x) << EMIF_INT_MSK_SET_AT_FLAG_SET_Pos) & EMIF_INT_MSK_SET_AT_FLAG_SET_Msk)   /*!< AT_FLAG_SET Set Value */
#define EMIF_INT_MSK_SET_AT_FLAG_SET_Get(x)  (((uint32_t) (x) & EMIF_INT_MSK_SET_AT_FLAG_SET_Msk) >> EMIF_INT_MSK_SET_AT_FLAG_SET_Pos)   /*!< AT_FLAG_SET Get Value */

/* INT_MSK_CLR bitfield */
#define EMIF_INT_MSK_CLR_WR_FLAG_CLR_Pos     (2U)                                                                                        /*!< WR_FLAG_CLR Position 2 */
#define EMIF_INT_MSK_CLR_WR_FLAG_CLR_Msk     (0x1U << EMIF_INT_MSK_CLR_WR_FLAG_CLR_Pos)                                                  /*!< WR_FLAG_CLR Mask 0x00000004 */
#define EMIF_INT_MSK_CLR_WR_FLAG_CLR_Set(x)  (((uint32_t) (x) << EMIF_INT_MSK_CLR_WR_FLAG_CLR_Pos) & EMIF_INT_MSK_CLR_WR_FLAG_CLR_Msk)   /*!< WR_FLAG_CLR Set Value */
#define EMIF_INT_MSK_CLR_WR_FLAG_CLR_Get(x)  (((uint32_t) (x) & EMIF_INT_MSK_CLR_WR_FLAG_CLR_Msk) >> EMIF_INT_MSK_CLR_WR_FLAG_CLR_Pos)   /*!< WR_FLAG_CLR Get Value */

#define EMIF_INT_MSK_CLR_LT_FLAG_CLR_Pos     (1U)                                                                                        /*!< LT_FLAG_CLR Position 1 */
#define EMIF_INT_MSK_CLR_LT_FLAG_CLR_Msk     (0x1U << EMIF_INT_MSK_CLR_LT_FLAG_CLR_Pos)                                                  /*!< LT_FLAG_CLR Mask 0x00000002 */
#define EMIF_INT_MSK_CLR_LT_FLAG_CLR_Set(x)  (((uint32_t) (x) << EMIF_INT_MSK_CLR_LT_FLAG_CLR_Pos) & EMIF_INT_MSK_CLR_LT_FLAG_CLR_Msk)   /*!< LT_FLAG_CLR Set Value */
#define EMIF_INT_MSK_CLR_LT_FLAG_CLR_Get(x)  (((uint32_t) (x) & EMIF_INT_MSK_CLR_LT_FLAG_CLR_Msk) >> EMIF_INT_MSK_CLR_LT_FLAG_CLR_Pos)   /*!< LT_FLAG_CLR Get Value */

#define EMIF_INT_MSK_CLR_AT_FLAG_CLR_Pos     (0U)                                                                                        /*!< AT_FLAG_CLR Position 0 */
#define EMIF_INT_MSK_CLR_AT_FLAG_CLR_Msk     (0x1U << EMIF_INT_MSK_CLR_AT_FLAG_CLR_Pos)                                                  /*!< AT_FLAG_CLR Mask 0x00000001 */
#define EMIF_INT_MSK_CLR_AT_FLAG_CLR_Set(x)  (((uint32_t) (x) << EMIF_INT_MSK_CLR_AT_FLAG_CLR_Pos) & EMIF_INT_MSK_CLR_AT_FLAG_CLR_Msk)   /*!< AT_FLAG_CLR Set Value */
#define EMIF_INT_MSK_CLR_AT_FLAG_CLR_Get(x)  (((uint32_t) (x) & EMIF_INT_MSK_CLR_AT_FLAG_CLR_Msk) >> EMIF_INT_MSK_CLR_AT_FLAG_CLR_Pos)   /*!< AT_FLAG_CLR Get Value */

/* EMIF1LOCK bitfield */
#define EMIF_EMIF1LOCK_LOCK_EMIF_Pos     (0U)                                                                                /*!< LOCK_EMIF Position 0 */
#define EMIF_EMIF1LOCK_LOCK_EMIF_Msk     (0x1U << EMIF_EMIF1LOCK_LOCK_EMIF_Pos)                                              /*!< LOCK_EMIF Mask 0x00000001 */
#define EMIF_EMIF1LOCK_LOCK_EMIF_Set(x)  (((uint32_t) (x) << EMIF_EMIF1LOCK_LOCK_EMIF_Pos) & EMIF_EMIF1LOCK_LOCK_EMIF_Msk)   /*!< LOCK_EMIF Set Value */
#define EMIF_EMIF1LOCK_LOCK_EMIF_Get(x)  (((uint32_t) (x) & EMIF_EMIF1LOCK_LOCK_EMIF_Msk) >> EMIF_EMIF1LOCK_LOCK_EMIF_Pos)   /*!< LOCK_EMIF Get Value */

/* EMIF1MSEL bitfield */
#define EMIF_EMIF1MSEL_CPU1_MSEL_Pos     (1U)                                                                                /*!< CPU1_MSEL Position 1 */
#define EMIF_EMIF1MSEL_CPU1_MSEL_Msk     (0x1U << EMIF_EMIF1MSEL_CPU1_MSEL_Pos)                                              /*!< CPU1_MSEL Mask 0x00000002 */
#define EMIF_EMIF1MSEL_CPU1_MSEL_Set(x)  (((uint32_t) (x) << EMIF_EMIF1MSEL_CPU1_MSEL_Pos) & EMIF_EMIF1MSEL_CPU1_MSEL_Msk)   /*!< CPU1_MSEL Set Value */
#define EMIF_EMIF1MSEL_CPU1_MSEL_Get(x)  (((uint32_t) (x) & EMIF_EMIF1MSEL_CPU1_MSEL_Msk) >> EMIF_EMIF1MSEL_CPU1_MSEL_Pos)   /*!< CPU1_MSEL Get Value */

#define EMIF_EMIF1MSEL_CPU0_MSEL_Pos     (0U)                                                                                /*!< CPU0_MSEL Position 0 */
#define EMIF_EMIF1MSEL_CPU0_MSEL_Msk     (0x1U << EMIF_EMIF1MSEL_CPU0_MSEL_Pos)                                              /*!< CPU0_MSEL Mask 0x00000001 */
#define EMIF_EMIF1MSEL_CPU0_MSEL_Set(x)  (((uint32_t) (x) << EMIF_EMIF1MSEL_CPU0_MSEL_Pos) & EMIF_EMIF1MSEL_CPU0_MSEL_Msk)   /*!< CPU0_MSEL Set Value */
#define EMIF_EMIF1MSEL_CPU0_MSEL_Get(x)  (((uint32_t) (x) & EMIF_EMIF1MSEL_CPU0_MSEL_Msk) >> EMIF_EMIF1MSEL_CPU0_MSEL_Pos)   /*!< CPU0_MSEL Get Value */

/* EMIF1ACCROT bitfield */
#define EMIF_EMIF1ACCROT_DMA1_WRITE_Pos     (7U)                                                                                      /*!< DMA1_WRITE Position 7 */
#define EMIF_EMIF1ACCROT_DMA1_WRITE_Msk     (0x1U << EMIF_EMIF1ACCROT_DMA1_WRITE_Pos)                                                 /*!< DMA1_WRITE Mask 0x00000080 */
#define EMIF_EMIF1ACCROT_DMA1_WRITE_Set(x)  (((uint32_t) (x) << EMIF_EMIF1ACCROT_DMA1_WRITE_Pos) & EMIF_EMIF1ACCROT_DMA1_WRITE_Msk)   /*!< DMA1_WRITE Set Value */
#define EMIF_EMIF1ACCROT_DMA1_WRITE_Get(x)  (((uint32_t) (x) & EMIF_EMIF1ACCROT_DMA1_WRITE_Msk) >> EMIF_EMIF1ACCROT_DMA1_WRITE_Pos)   /*!< DMA1_WRITE Get Value */

#define EMIF_EMIF1ACCROT_DMA1_READ_Pos     (6U)                                                                                    /*!< DMA1_READ Position 6 */
#define EMIF_EMIF1ACCROT_DMA1_READ_Msk     (0x1U << EMIF_EMIF1ACCROT_DMA1_READ_Pos)                                                /*!< DMA1_READ Mask 0x00000040 */
#define EMIF_EMIF1ACCROT_DMA1_READ_Set(x)  (((uint32_t) (x) << EMIF_EMIF1ACCROT_DMA1_READ_Pos) & EMIF_EMIF1ACCROT_DMA1_READ_Msk)   /*!< DMA1_READ Set Value */
#define EMIF_EMIF1ACCROT_DMA1_READ_Get(x)  (((uint32_t) (x) & EMIF_EMIF1ACCROT_DMA1_READ_Msk) >> EMIF_EMIF1ACCROT_DMA1_READ_Pos)   /*!< DMA1_READ Get Value */

#define EMIF_EMIF1ACCROT_CPU1_WRITE_Pos     (5U)                                                                                      /*!< CPU1_WRITE Position 5 */
#define EMIF_EMIF1ACCROT_CPU1_WRITE_Msk     (0x1U << EMIF_EMIF1ACCROT_CPU1_WRITE_Pos)                                                 /*!< CPU1_WRITE Mask 0x00000020 */
#define EMIF_EMIF1ACCROT_CPU1_WRITE_Set(x)  (((uint32_t) (x) << EMIF_EMIF1ACCROT_CPU1_WRITE_Pos) & EMIF_EMIF1ACCROT_CPU1_WRITE_Msk)   /*!< CPU1_WRITE Set Value */
#define EMIF_EMIF1ACCROT_CPU1_WRITE_Get(x)  (((uint32_t) (x) & EMIF_EMIF1ACCROT_CPU1_WRITE_Msk) >> EMIF_EMIF1ACCROT_CPU1_WRITE_Pos)   /*!< CPU1_WRITE Get Value */

#define EMIF_EMIF1ACCROT_CPU1_READ_Pos     (4U)                                                                                    /*!< CPU1_READ Position 4 */
#define EMIF_EMIF1ACCROT_CPU1_READ_Msk     (0x1U << EMIF_EMIF1ACCROT_CPU1_READ_Pos)                                                /*!< CPU1_READ Mask 0x00000010 */
#define EMIF_EMIF1ACCROT_CPU1_READ_Set(x)  (((uint32_t) (x) << EMIF_EMIF1ACCROT_CPU1_READ_Pos) & EMIF_EMIF1ACCROT_CPU1_READ_Msk)   /*!< CPU1_READ Set Value */
#define EMIF_EMIF1ACCROT_CPU1_READ_Get(x)  (((uint32_t) (x) & EMIF_EMIF1ACCROT_CPU1_READ_Msk) >> EMIF_EMIF1ACCROT_CPU1_READ_Pos)   /*!< CPU1_READ Get Value */

#define EMIF_EMIF1ACCROT_DMA0_WRITE_Pos     (3U)                                                                                      /*!< DMA0_WRITE Position 3 */
#define EMIF_EMIF1ACCROT_DMA0_WRITE_Msk     (0x1U << EMIF_EMIF1ACCROT_DMA0_WRITE_Pos)                                                 /*!< DMA0_WRITE Mask 0x00000008 */
#define EMIF_EMIF1ACCROT_DMA0_WRITE_Set(x)  (((uint32_t) (x) << EMIF_EMIF1ACCROT_DMA0_WRITE_Pos) & EMIF_EMIF1ACCROT_DMA0_WRITE_Msk)   /*!< DMA0_WRITE Set Value */
#define EMIF_EMIF1ACCROT_DMA0_WRITE_Get(x)  (((uint32_t) (x) & EMIF_EMIF1ACCROT_DMA0_WRITE_Msk) >> EMIF_EMIF1ACCROT_DMA0_WRITE_Pos)   /*!< DMA0_WRITE Get Value */

#define EMIF_EMIF1ACCROT_DMA0_READ_Pos     (2U)                                                                                    /*!< DMA0_READ Position 2 */
#define EMIF_EMIF1ACCROT_DMA0_READ_Msk     (0x1U << EMIF_EMIF1ACCROT_DMA0_READ_Pos)                                                /*!< DMA0_READ Mask 0x00000004 */
#define EMIF_EMIF1ACCROT_DMA0_READ_Set(x)  (((uint32_t) (x) << EMIF_EMIF1ACCROT_DMA0_READ_Pos) & EMIF_EMIF1ACCROT_DMA0_READ_Msk)   /*!< DMA0_READ Set Value */
#define EMIF_EMIF1ACCROT_DMA0_READ_Get(x)  (((uint32_t) (x) & EMIF_EMIF1ACCROT_DMA0_READ_Msk) >> EMIF_EMIF1ACCROT_DMA0_READ_Pos)   /*!< DMA0_READ Get Value */

#define EMIF_EMIF1ACCROT_CPU0_WRITE_Pos     (1U)                                                                                      /*!< CPU0_WRITE Position 1 */
#define EMIF_EMIF1ACCROT_CPU0_WRITE_Msk     (0x1U << EMIF_EMIF1ACCROT_CPU0_WRITE_Pos)                                                 /*!< CPU0_WRITE Mask 0x00000002 */
#define EMIF_EMIF1ACCROT_CPU0_WRITE_Set(x)  (((uint32_t) (x) << EMIF_EMIF1ACCROT_CPU0_WRITE_Pos) & EMIF_EMIF1ACCROT_CPU0_WRITE_Msk)   /*!< CPU0_WRITE Set Value */
#define EMIF_EMIF1ACCROT_CPU0_WRITE_Get(x)  (((uint32_t) (x) & EMIF_EMIF1ACCROT_CPU0_WRITE_Msk) >> EMIF_EMIF1ACCROT_CPU0_WRITE_Pos)   /*!< CPU0_WRITE Get Value */

#define EMIF_EMIF1ACCROT_CPU0_READ_Pos     (0U)                                                                                    /*!< CPU0_READ Position 0 */
#define EMIF_EMIF1ACCROT_CPU0_READ_Msk     (0x1U << EMIF_EMIF1ACCROT_CPU0_READ_Pos)                                                /*!< CPU0_READ Mask 0x00000001 */
#define EMIF_EMIF1ACCROT_CPU0_READ_Set(x)  (((uint32_t) (x) << EMIF_EMIF1ACCROT_CPU0_READ_Pos) & EMIF_EMIF1ACCROT_CPU0_READ_Msk)   /*!< CPU0_READ Set Value */
#define EMIF_EMIF1ACCROT_CPU0_READ_Get(x)  (((uint32_t) (x) & EMIF_EMIF1ACCROT_CPU0_READ_Msk) >> EMIF_EMIF1ACCROT_CPU0_READ_Pos)   /*!< CPU0_READ Get Value */

/* ST bitfield */
#define EMIF_ST_CURRENT_ASYNCREQEN_Pos     (6U)                                                                                    /*!< CURRENT_ASYNCREQEN Position 6 */
#define EMIF_ST_CURRENT_ASYNCREQEN_Msk     (0x1U << EMIF_ST_CURRENT_ASYNCREQEN_Pos)                                                /*!< CURRENT_ASYNCREQEN Mask 0x00000040 */
#define EMIF_ST_CURRENT_ASYNCREQEN_Set(x)  (((uint32_t) (x) << EMIF_ST_CURRENT_ASYNCREQEN_Pos) & EMIF_ST_CURRENT_ASYNCREQEN_Msk)   /*!< CURRENT_ASYNCREQEN Set Value */
#define EMIF_ST_CURRENT_ASYNCREQEN_Get(x)  (((uint32_t) (x) & EMIF_ST_CURRENT_ASYNCREQEN_Msk) >> EMIF_ST_CURRENT_ASYNCREQEN_Pos)   /*!< CURRENT_ASYNCREQEN Get Value */

#define EMIF_ST_SDRAM_INIT_FINISH_Pos     (5U)                                                                                  /*!< SDRAM_INIT_FINISH Position 5 */
#define EMIF_ST_SDRAM_INIT_FINISH_Msk     (0x1U << EMIF_ST_SDRAM_INIT_FINISH_Pos)                                               /*!< SDRAM_INIT_FINISH Mask 0x00000020 */
#define EMIF_ST_SDRAM_INIT_FINISH_Set(x)  (((uint32_t) (x) << EMIF_ST_SDRAM_INIT_FINISH_Pos) & EMIF_ST_SDRAM_INIT_FINISH_Msk)   /*!< SDRAM_INIT_FINISH Set Value */
#define EMIF_ST_SDRAM_INIT_FINISH_Get(x)  (((uint32_t) (x) & EMIF_ST_SDRAM_INIT_FINISH_Msk) >> EMIF_ST_SDRAM_INIT_FINISH_Pos)   /*!< SDRAM_INIT_FINISH Get Value */

#define EMIF_ST_SDRAM_STATE_Pos     (0U)                                                                      /*!< SDRAM_STATE Position 0 */
#define EMIF_ST_SDRAM_STATE_Msk     (0x1fU << EMIF_ST_SDRAM_STATE_Pos)                                        /*!< SDRAM_STATE Mask 0x0000001F */
#define EMIF_ST_SDRAM_STATE_Set(x)  (((uint32_t) (x) << EMIF_ST_SDRAM_STATE_Pos) & EMIF_ST_SDRAM_STATE_Msk)   /*!< SDRAM_STATE Set Value */
#define EMIF_ST_SDRAM_STATE_Get(x)  (((uint32_t) (x) & EMIF_ST_SDRAM_STATE_Msk) >> EMIF_ST_SDRAM_STATE_Pos)   /*!< SDRAM_STATE Get Value */

/*!
 * @}
 */

/* clang-format on */

/*!
 * @}
 */ /* end of HS32F7D377_EMIF_REGISTER */

#endif /* HS32F7D377_EMIF_H */
