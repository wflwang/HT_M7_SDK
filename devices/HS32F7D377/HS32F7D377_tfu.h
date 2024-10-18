/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


/*!
 * \file   HS32F7D377_tfu.h
 * \brief  HS32F7D377 TFU register file
 * \version V1.0_20230920
 */

#ifndef HS32F7D377_TFU_H
#define HS32F7D377_TFU_H

/*!
 * \addtogroup   HS32F7D377_TFU_REGISTER HS32F7D377 TFU Register
 * \ingroup HS32F7D377_REGISTER
 *
 * \brief  TFU register layout, bitfield and address definitions
 *
 * @{
 */

/*!
 * \name TFU Register Layout
 *
 *
 * @{
 */

/*! \brief TFU register layout */
typedef struct {
    /*!< 0x00000000~0x0000000f : group for 0-3 threads of TFU0 instance */
    union
    {
        __IOM uint32_t TFU0_CSR            ;  /*!< 0x00000000 :  */
    
        struct
        {
            __IOM uint32_t TFU0_FUNC_SEL             : 4 ;     /*!< [ 3: 0] : challenge numbers, 1 or 2
                                                                              <li> 4'd0 : cosine
                                                                              <li> 4'd1 : sine
                                                                              <li> 4'd2 : phase
                                                                              <li> 4'd3 : modulus
                                                                              <li> 4'd4 : arctangent
                                                                              <li> 4'd5 : logarithm
                                                                              <li> 4'd6 : exponent
                                                                              <li> 4'd7-15 : reserved */
            __IOM uint32_t TFU0_PRECISION            : 4 ;     /*!< [ 7: 4] : q1.15 or q1.31 precision
                                                                              <li> 4'd0 : reserved
                                                                              <li> 4'd1-15 : close to number of iterations */
                  uint32_t RSV_2                     : 4 ;     /*!< [11: 8] : reserved. */
            __IM  uint32_t TFU0_FRES_EPT             : 1 ;     /*!< [12:12] : response  fifo state
                                                                              <li> 1'b0 : not empty
                                                                              <li> 1'b1 : empty */
            __IM  uint32_t TFU0_FRES_FUL             : 1 ;     /*!< [13:13] : response  fifo state
                                                                              <li> 1'b0 : not full
                                                                              <li> 1'b1 : full */
            __IM  uint32_t TFU0_FARG_EPT             : 1 ;     /*!< [14:14] : challenge fifo state
                                                                              <li> 1'b0 : not empty
                                                                              <li> 1'b1 : empty */
            __IM  uint32_t TFU0_FARG_FUL             : 1 ;     /*!< [15:15] : challenge fifo state
                                                                              <li> 1'b0 : not full
                                                                              <li> 1'b1 : full */
                  uint32_t RSV_1                     : 1 ;     /*!< [16:16] : reserved. */
            __IOM uint32_t TFU0_DMA_REN              : 1 ;     /*!< [17:17] : dma read  enable
                                                                              <li> 1'b0 : disabled
                                                                              no DMA read requests are generated
                                                                              <li> 1'b1 : enabled,
                                                                              when rdy is high, generate a DMA read request */
            __IOM uint32_t TFU0_DMA_WEN              : 1 ;     /*!< [18:18] : dma write enable
                                                                              <li> 1'b0 : disabled
                                                                              no DMA write requests are generated
                                                                              <li> 1'b1 : enabled,
                                                                              when no operation is pending, generate a DMA  write request */
            __IOM uint32_t TFU0_RES_NUM              : 1 ;     /*!< [19:19] : response numbers, 1 or 2
                                                                              <li> 1'b0 : only RDATA1 is used
                                                                              <li> 1'b1 : all RDATAs is used */
            __IOM uint32_t TFU0_ARG_NUM              : 1 ;     /*!< [20:20] : challenge numbers, 1 or 2
                                                                              <li> 1'b0 : only WDATA1 is used
                                                                              <li> 1'b1 : all WDATAs is used */
            __IOM uint32_t TFU0_RES_SIZE             : 1 ;     /*!< [21:21] : width of tfu00 output data
                                                                              <li> 1'b0 : 32-bit
                                                                              <li> 1'b1 : 16-bit
                                                                              if 16-bit is selected:
                                                                              data should write to the least significant half-word */
            __IOM uint32_t TFU0_ARG_SIZE             : 1 ;     /*!< [22:22] : width of tfu00 input data
                                                                              <li> 1'b0 : 32-bit
                                                                              <li> 1'b1 : 16-bit
                                                                              if 16-bit is selected:
                                                                              data should write to the least significant half-word */
                  uint32_t RSV_0                     : 8 ;     /*!< [30:23] : reserved. */
            __IM  uint32_t TFU0_RRDY                 : 1 ;     /*!< [31:31] : tfu0 data ready flag
                                                                              <li> 1'b0 : No new results in output register
                                                                              <li> 1'b1 : new results in output register
                                                                              this bit is set to 1 when a TFU0 calculation completes.
                                                                              this bit is set to 0 when WDATA is read (res_num+1) times. */
        } TFU0_CSRb[4];
    };

    uint8_t    RSV_0X10[112];   /*!< 0x00000010~0x0000007f : reserved */

    union
    {
        __IOM uint32_t TFU0_CFG            ;  /*!< 0x00000080 :  */
    
        struct
        {
            __IOM uint32_t TFU0_TRD0_FIFO_CLR        : 1 ;     /*!< [ 0: 0] : write 1 clear tfu0 thread0 fifo. */
            __IOM uint32_t TFU0_TRD1_FIFO_CLR        : 1 ;     /*!< [ 1: 1] : write 1 clear tfu0 thread1 fifo. */
            __IOM uint32_t TFU0_TRD2_FIFO_CLR        : 1 ;     /*!< [ 2: 2] : write 1 clear tfu0 thread2 fifo. */
            __IOM uint32_t TFU0_TRD3_FIFO_CLR        : 1 ;     /*!< [ 3: 3] : write 1 clear tfu0 thread3 fifo. */
            __IM  uint32_t TFU0_TRD0_LOAD            : 1 ;     /*!< [ 4: 4] : 1 means thread0 is running, data was read from arg fifo. */
            __IM  uint32_t TFU0_TRD1_LOAD            : 1 ;     /*!< [ 5: 5] : 1 means thread1 is running, data was read from arg fifo. */
            __IM  uint32_t TFU0_TRD2_LOAD            : 1 ;     /*!< [ 6: 6] : 1 means thread2 is running, data was read from arg fifo. */
            __IM  uint32_t TFU0_TRD3_LOAD            : 1 ;     /*!< [ 7: 7] : 1 means thread3 is running, data was read from arg fifo. */
                  uint32_t RSV_0                     : 23;     /*!< [30: 8] : reserved. */
            __IOM uint32_t TFU0_ARB_MODE             : 1 ;     /*!< [31:31] : tfu0 arbiter mode select .
                                                                              <li>1: round-robin mode
                                                                              <li>0: fixed-priority mode */
        } TFU0_CFGb;
    };

    union
    {
        __IM  uint32_t TFU0_FIFO_WATERLEVEL;  /*!< 0x00000084 :  */
    
        struct
        {
            __IM  uint32_t TFU0_TRD0_RES_WL          : 4 ;     /*!< [ 3: 0] : tfu0 thread0 response fifo waterlevel. */
            __IM  uint32_t TFU0_TRD0_ARG1_WL         : 4 ;     /*!< [ 7: 4] : tfu0 thread0 argument fifo waterlevel. */
            __IM  uint32_t TFU0_TRD0_ARG0_WL         : 4 ;     /*!< [11: 8] : tfu0 thread0 argument fifo waterlevel. */
            __IM  uint32_t TFU0_TRD1_RES_WL          : 2 ;     /*!< [13:12] : tfu0 thread1 response fifo waterlevel. */
            __IM  uint32_t TFU0_TRD1_ARG1_WL         : 2 ;     /*!< [15:14] : tfu0 thread1 argument fifo waterlevel. */
            __IM  uint32_t TFU0_TRD1_ARG0_WL         : 2 ;     /*!< [17:16] : tfu0 thread1 argument fifo waterlevel. */
            __IM  uint32_t TFU0_TRD2_RES_WL          : 2 ;     /*!< [19:18] : tfu0 thread2 response fifo waterlevel. */
            __IM  uint32_t TFU0_TRD2_ARG1_WL         : 2 ;     /*!< [21:20] : tfu0 thread2 argument fifo waterlevel. */
            __IM  uint32_t TFU0_TRD2_ARG0_WL         : 2 ;     /*!< [23:22] : tfu0 thread2 argument fifo waterlevel. */
            __IM  uint32_t TFU0_TRD3_RES_WL          : 2 ;     /*!< [25:24] : tfu0 thread2 response fifo waterlevel. */
            __IM  uint32_t TFU0_TRD3_ARG1_WL         : 2 ;     /*!< [27:26] : tfu0 thread2 argument fifo waterlevel. */
            __IM  uint32_t TFU0_TRD3_ARG0_WL         : 2 ;     /*!< [29:28] : tfu0 thread3 argument fifo waterlevel. */
                  uint32_t RSV_0                     : 2 ;     /*!< [31:30] : reserved. */
        } TFU0_FIFO_WATERLEVELb;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTP01  ;  /*!< 0x00000088 :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTP01        : 32;     /*!< [31: 0] : t1u0 log&exp operator lut, plus point No. */
        } TFU0_LOGEXP_LUTP01b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTP02  ;  /*!< 0x0000008c :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTP02        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, plus point No. */
        } TFU0_LOGEXP_LUTP02b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTP03  ;  /*!< 0x00000090 :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTP03        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, plus point No. */
        } TFU0_LOGEXP_LUTP03b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTP04  ;  /*!< 0x00000094 :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTP04        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, plus point No. */
        } TFU0_LOGEXP_LUTP04b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTP05  ;  /*!< 0x00000098 :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTP05        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, plus point No. */
        } TFU0_LOGEXP_LUTP05b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTP06  ;  /*!< 0x0000009c :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTP06        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, plus point No. */
        } TFU0_LOGEXP_LUTP06b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTP07  ;  /*!< 0x000000a0 :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTP07        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, plus point No. */
        } TFU0_LOGEXP_LUTP07b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTP08  ;  /*!< 0x000000a4 :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTP08        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, plus point No. */
        } TFU0_LOGEXP_LUTP08b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTP09  ;  /*!< 0x000000a8 :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTP09        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, plus point No. */
        } TFU0_LOGEXP_LUTP09b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTP10  ;  /*!< 0x000000ac :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTP10        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, plus point No. */
        } TFU0_LOGEXP_LUTP10b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTP11  ;  /*!< 0x000000b0 :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTP11        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, plus point No. */
        } TFU0_LOGEXP_LUTP11b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTP12  ;  /*!< 0x000000b4 :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTP12        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, plus point No. */
        } TFU0_LOGEXP_LUTP12b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTP13  ;  /*!< 0x000000b8 :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTP13        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, plus point No. */
        } TFU0_LOGEXP_LUTP13b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTP14  ;  /*!< 0x000000bc :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTP14        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, plus point No. */
        } TFU0_LOGEXP_LUTP14b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTP15  ;  /*!< 0x000000c0 :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTP15        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, plus point No. */
        } TFU0_LOGEXP_LUTP15b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTP16  ;  /*!< 0x000000c4 :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTP16        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, plus point No. */
        } TFU0_LOGEXP_LUTP16b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTP17  ;  /*!< 0x000000c8 :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTP17        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, plus point No. */
        } TFU0_LOGEXP_LUTP17b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTP18  ;  /*!< 0x000000cc :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTP18        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, plus point No. */
        } TFU0_LOGEXP_LUTP18b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTP19  ;  /*!< 0x000000d0 :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTP19        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, plus point No. */
        } TFU0_LOGEXP_LUTP19b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTP20  ;  /*!< 0x000000d4 :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTP20        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, plus point No. */
        } TFU0_LOGEXP_LUTP20b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTP21  ;  /*!< 0x000000d8 :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTP21        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, plus point No. */
        } TFU0_LOGEXP_LUTP21b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTP22  ;  /*!< 0x000000dc :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTP22        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, plus point No. */
        } TFU0_LOGEXP_LUTP22b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTP23  ;  /*!< 0x000000e0 :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTP23        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, plus point No. */
        } TFU0_LOGEXP_LUTP23b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTP24  ;  /*!< 0x000000e4 :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTP24        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, plus point No. */
        } TFU0_LOGEXP_LUTP24b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTM01  ;  /*!< 0x000000e8 :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTM01        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, minus point No. */
        } TFU0_LOGEXP_LUTM01b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTM02  ;  /*!< 0x000000ec :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTM02        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, minus point No. */
        } TFU0_LOGEXP_LUTM02b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTM03  ;  /*!< 0x000000f0 :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTM03        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, minus point No. */
        } TFU0_LOGEXP_LUTM03b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTM04  ;  /*!< 0x000000f4 :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTM04        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, minus point No. */
        } TFU0_LOGEXP_LUTM04b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTM05  ;  /*!< 0x000000f8 :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTM05        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, minus point No. */
        } TFU0_LOGEXP_LUTM05b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTM06  ;  /*!< 0x000000fc :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTM06        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, minus point No. */
        } TFU0_LOGEXP_LUTM06b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTM07  ;  /*!< 0x00000100 :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTM07        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, minus point No. */
        } TFU0_LOGEXP_LUTM07b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTM08  ;  /*!< 0x00000104 :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTM08        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, minus point No. */
        } TFU0_LOGEXP_LUTM08b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTM09  ;  /*!< 0x00000108 :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTM09        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, minus point No. */
        } TFU0_LOGEXP_LUTM09b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTM10  ;  /*!< 0x0000010c :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTM10        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, minus point No. */
        } TFU0_LOGEXP_LUTM10b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTM11  ;  /*!< 0x00000110 :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTM11        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, minus point No. */
        } TFU0_LOGEXP_LUTM11b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTM12  ;  /*!< 0x00000114 :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTM12        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, minus point No. */
        } TFU0_LOGEXP_LUTM12b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTM13  ;  /*!< 0x00000118 :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTM13        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, minus point No. */
        } TFU0_LOGEXP_LUTM13b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTM14  ;  /*!< 0x0000011c :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTM14        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, minus point No. */
        } TFU0_LOGEXP_LUTM14b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTM15  ;  /*!< 0x00000120 :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTM15        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, minus point No. */
        } TFU0_LOGEXP_LUTM15b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTM16  ;  /*!< 0x00000124 :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTM16        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, minus point No. */
        } TFU0_LOGEXP_LUTM16b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTM17  ;  /*!< 0x00000128 :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTM17        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, minus point No. */
        } TFU0_LOGEXP_LUTM17b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTM18  ;  /*!< 0x0000012c :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTM18        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, minus point No. */
        } TFU0_LOGEXP_LUTM18b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTM19  ;  /*!< 0x00000130 :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTM19        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, minus point No. */
        } TFU0_LOGEXP_LUTM19b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTM20  ;  /*!< 0x00000134 :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTM20        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, minus point No. */
        } TFU0_LOGEXP_LUTM20b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTM21  ;  /*!< 0x00000138 :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTM21        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, minus point No. */
        } TFU0_LOGEXP_LUTM21b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTM22  ;  /*!< 0x0000013c :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTM22        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, minus point No. */
        } TFU0_LOGEXP_LUTM22b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTM23  ;  /*!< 0x00000140 :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTM23        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, minus point No. */
        } TFU0_LOGEXP_LUTM23b;
    };

    union
    {
        __IOM uint32_t TFU0_LOGEXP_LUTM24  ;  /*!< 0x00000144 :  */
    
        struct
        {
            __IOM uint32_t TFU0_LOGEXP_LUTM24        : 32;     /*!< [31: 0] : tfu0 log&exp operator lut, minus point No. */
        } TFU0_LOGEXP_LUTM24b;
    };

    uint8_t    RSV_0X148[8];   /*!< 0x00000148~0x0000014f : reserved */

    /*!< 0x00000150~0x0000015f : group for 0-3 threads of TFU1 instance */
    union
    {
        __IOM uint32_t TFU1_CSR            ;  /*!< 0x00000150 :  */
    
        struct
        {
            __IOM uint32_t TFU1_FUNC_SEL             : 4 ;     /*!< [ 3: 0] : challenge numbers, 1 or 2
                                                                              <li> 4'd0 : cosine
                                                                              <li> 4'd1 : sine
                                                                              <li> 4'd2 : phase
                                                                              <li> 4'd3 : modulus
                                                                              <li> 4'd4 : arctangent
                                                                              <li> 4'd5 : logarithm
                                                                              <li> 4'd6 : exponent
                                                                              <li> 4'd7-15 : reserved */
            __IOM uint32_t TFU1_PRECISION            : 4 ;     /*!< [ 7: 4] : q1.15 or q1.31 precision
                                                                              <li> 4'd0 : reserved
                                                                              <li> 4'd1-15 : close to number of iterations */
                  uint32_t RSV_2                     : 4 ;     /*!< [11: 8] : reserved. */
            __IM  uint32_t TFU1_FRES_EPT             : 1 ;     /*!< [12:12] : response  fifo state
                                                                              <li> 1'b0 : not empty
                                                                              <li> 1'b1 : empty */
            __IM  uint32_t TFU1_FRES_FUL             : 1 ;     /*!< [13:13] : response  fifo state
                                                                              <li> 1'b0 : not full
                                                                              <li> 1'b1 : full */
            __IM  uint32_t TFU1_FARG_EPT             : 1 ;     /*!< [14:14] : challenge fifo state
                                                                              <li> 1'b0 : not empty
                                                                              <li> 1'b1 : empty */
            __IM  uint32_t TFU1_FARG_FUL             : 1 ;     /*!< [15:15] : challenge fifo state
                                                                              <li> 1'b0 : not full
                                                                              <li> 1'b1 : full */
                  uint32_t RSV_1                     : 1 ;     /*!< [16:16] : reserved. */
            __IOM uint32_t TFU1_DMA_REN              : 1 ;     /*!< [17:17] : dma read  enable
                                                                              <li> 1'b0 : disabled
                                                                              no DMA read requests are generated
                                                                              <li> 1'b1 : enabled,
                                                                              when rdy is high, generate a DMA read request */
            __IOM uint32_t TFU1_DMA_WEN              : 1 ;     /*!< [18:18] : dma write enable
                                                                              <li> 1'b0 : disabled
                                                                              no DMA write requests are generated
                                                                              <li> 1'b1 : enabled,
                                                                              when no operation is pending, generate a DMA  write request */
            __IOM uint32_t TFU1_RES_NUM              : 1 ;     /*!< [19:19] : response numbers, 1 or 2
                                                                              <li> 1'b0 : only RDATA1 is used
                                                                              <li> 1'b1 : all RDATAs is used */
            __IOM uint32_t TFU1_ARG_NUM              : 1 ;     /*!< [20:20] : challenge numbers, 1 or 2
                                                                              <li> 1'b0 : only WDATA1 is used
                                                                              <li> 1'b1 : all WDATAs is used */
            __IOM uint32_t TFU1_RES_SIZE             : 1 ;     /*!< [21:21] : width of tfu10 output data
                                                                              <li> 1'b0 : 32-bit
                                                                              <li> 1'b1 : 16-bit
                                                                              if 16-bit is selected:
                                                                              data should write to the least significant half-word */
            __IOM uint32_t TFU1_ARG_SIZE             : 1 ;     /*!< [22:22] : width of tfu10 input data
                                                                              <li> 1'b0 : 32-bit
                                                                              <li> 1'b1 : 16-bit
                                                                              if 16-bit is selected:
                                                                              data should write to the least significant half-word */
                  uint32_t RSV_0                     : 8 ;     /*!< [30:23] : reserved. */
            __IM  uint32_t TFU1_RRDY                 : 1 ;     /*!< [31:31] : tfu1 data ready flag
                                                                              <li> 1'b0 : No new results in output register
                                                                              <li> 1'b0 : new results in output register
                                                                              this bit is set to 1 when a TFU1 calculation completes.
                                                                              this bit is set to 0 when WDATA is read (res_num+1) times. */
        } TFU1_CSRb[4];
    };

    uint8_t    RSV_0X160[112];   /*!< 0x00000160~0x000001cf : reserved */

    union
    {
        __IOM uint32_t TFU1_CFG            ;  /*!< 0x000001d0 :  */
    
        struct
        {
            __IOM uint32_t TFU1_TRD0_FIFO_CLR        : 1 ;     /*!< [ 0: 0] : write 1 clear tfu1 thread0 fifo. */
            __IOM uint32_t TFU1_TRD1_FIFO_CLR        : 1 ;     /*!< [ 1: 1] : write 1 clear tfu1 thread1 fifo. */
            __IOM uint32_t TFU1_TRD2_FIFO_CLR        : 1 ;     /*!< [ 2: 2] : write 1 clear tfu1 thread2 fifo. */
            __IOM uint32_t TFU1_TRD3_FIFO_CLR        : 1 ;     /*!< [ 3: 3] : write 1 clear tfu1 thread3 fifo. */
            __IM  uint32_t TFU1_TRD0_LOAD            : 1 ;     /*!< [ 4: 4] : 1 means thread0 is running, data was read from arg fifo. */
            __IM  uint32_t TFU1_TRD1_LOAD            : 1 ;     /*!< [ 5: 5] : 1 means thread1 is running, data was read from arg fifo. */
            __IM  uint32_t TFU1_TRD2_LOAD            : 1 ;     /*!< [ 6: 6] : 1 means thread2 is running, data was read from arg fifo. */
            __IM  uint32_t TFU1_TRD3_LOAD            : 1 ;     /*!< [ 7: 7] : 1 means thread3 is running, data was read from arg fifo. */
                  uint32_t RSV_0                     : 23;     /*!< [30: 8] : reserved. */
            __IOM uint32_t TFU1_ARB_MODE             : 1 ;     /*!< [31:31] : tfu1 arbiter mode select .
                                                                              <li>1: round-robin mode
                                                                              <li>0: fixed-priority mode */
        } TFU1_CFGb;
    };

    union
    {
        __IM  uint32_t TFU1_FIFO_WATERLEVEL;  /*!< 0x000001d4 :  */
    
        struct
        {
            __IM  uint32_t TFU1_TRD0_RES_WL          : 4 ;     /*!< [ 3: 0] : tfu1 thread0 response fifo waterlevel. */
            __IM  uint32_t TFU1_TRD0_ARG1_WL         : 4 ;     /*!< [ 7: 4] : tfu1 thread0 argument fifo waterlevel. */
            __IM  uint32_t TFU1_TRD0_ARG0_WL         : 4 ;     /*!< [11: 8] : tfu1 thread0 argument fifo waterlevel. */
            __IM  uint32_t TFU1_TRD1_RES_WL          : 2 ;     /*!< [13:12] : tfu1 thread1 response fifo waterlevel. */
            __IM  uint32_t TFU1_TRD1_ARG1_WL         : 2 ;     /*!< [15:14] : tfu1 thread1 argument fifo waterlevel. */
            __IM  uint32_t TFU1_TRD1_ARG0_WL         : 2 ;     /*!< [17:16] : tfu1 thread1 argument fifo waterlevel. */
            __IM  uint32_t TFU1_TRD2_RES_WL          : 2 ;     /*!< [19:18] : tfu1 thread2 response fifo waterlevel. */
            __IM  uint32_t TFU1_TRD2_ARG1_WL         : 2 ;     /*!< [21:20] : tfu1 thread2 argument fifo waterlevel. */
            __IM  uint32_t TFU1_TRD2_ARG0_WL         : 2 ;     /*!< [23:22] : tfu1 thread2 argument fifo waterlevel. */
            __IM  uint32_t TFU1_TRD3_RES_WL          : 2 ;     /*!< [25:24] : tfu1 thread2 response fifo waterlevel. */
            __IM  uint32_t TFU1_TRD3_ARG1_WL         : 2 ;     /*!< [27:26] : tfu1 thread2 argument fifo waterlevel. */
            __IM  uint32_t TFU1_TRD3_ARG0_WL         : 2 ;     /*!< [29:28] : tfu1 thread3 argument fifo waterlevel. */
                  uint32_t RSV_0                     : 2 ;     /*!< [31:30] : reserved. */
        } TFU1_FIFO_WATERLEVELb;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTP01  ;  /*!< 0x000001d8 :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTP01        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, plus point No. */
        } TFU1_LOGEXP_LUTP01b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTP02  ;  /*!< 0x000001dc :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTP02        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, plus point No. */
        } TFU1_LOGEXP_LUTP02b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTP03  ;  /*!< 0x000001e0 :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTP03        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, plus point No. */
        } TFU1_LOGEXP_LUTP03b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTP04  ;  /*!< 0x000001e4 :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTP04        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, plus point No. */
        } TFU1_LOGEXP_LUTP04b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTP05  ;  /*!< 0x000001e8 :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTP05        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, plus point No. */
        } TFU1_LOGEXP_LUTP05b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTP06  ;  /*!< 0x000001ec :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTP06        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, plus point No. */
        } TFU1_LOGEXP_LUTP06b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTP07  ;  /*!< 0x000001f0 :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTP07        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, plus point No. */
        } TFU1_LOGEXP_LUTP07b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTP08  ;  /*!< 0x000001f4 :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTP08        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, plus point No. */
        } TFU1_LOGEXP_LUTP08b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTP09  ;  /*!< 0x000001f8 :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTP09        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, plus point No. */
        } TFU1_LOGEXP_LUTP09b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTP10  ;  /*!< 0x000001fc :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTP10        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, plus point No. */
        } TFU1_LOGEXP_LUTP10b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTP11  ;  /*!< 0x00000200 :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTP11        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, plus point No. */
        } TFU1_LOGEXP_LUTP11b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTP12  ;  /*!< 0x00000204 :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTP12        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, plus point No. */
        } TFU1_LOGEXP_LUTP12b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTP13  ;  /*!< 0x00000208 :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTP13        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, plus point No. */
        } TFU1_LOGEXP_LUTP13b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTP14  ;  /*!< 0x0000020c :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTP14        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, plus point No. */
        } TFU1_LOGEXP_LUTP14b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTP15  ;  /*!< 0x00000210 :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTP15        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, plus point No. */
        } TFU1_LOGEXP_LUTP15b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTP16  ;  /*!< 0x00000214 :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTP16        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, plus point No. */
        } TFU1_LOGEXP_LUTP16b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTP17  ;  /*!< 0x00000218 :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTP17        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, plus point No. */
        } TFU1_LOGEXP_LUTP17b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTP18  ;  /*!< 0x0000021c :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTP18        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, plus point No. */
        } TFU1_LOGEXP_LUTP18b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTP19  ;  /*!< 0x00000220 :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTP19        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, plus point No. */
        } TFU1_LOGEXP_LUTP19b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTP20  ;  /*!< 0x00000224 :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTP20        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, plus point No. */
        } TFU1_LOGEXP_LUTP20b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTP21  ;  /*!< 0x00000228 :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTP21        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, plus point No. */
        } TFU1_LOGEXP_LUTP21b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTP22  ;  /*!< 0x0000022c :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTP22        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, plus point No. */
        } TFU1_LOGEXP_LUTP22b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTP23  ;  /*!< 0x00000230 :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTP23        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, plus point No. */
        } TFU1_LOGEXP_LUTP23b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTP24  ;  /*!< 0x00000234 :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTP24        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, plus point No. */
        } TFU1_LOGEXP_LUTP24b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTM01  ;  /*!< 0x00000238 :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTM01        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, minus point No. */
        } TFU1_LOGEXP_LUTM01b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTM02  ;  /*!< 0x0000023c :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTM02        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, minus point No. */
        } TFU1_LOGEXP_LUTM02b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTM03  ;  /*!< 0x00000240 :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTM03        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, minus point No. */
        } TFU1_LOGEXP_LUTM03b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTM04  ;  /*!< 0x00000244 :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTM04        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, minus point No. */
        } TFU1_LOGEXP_LUTM04b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTM05  ;  /*!< 0x00000248 :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTM05        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, minus point No. */
        } TFU1_LOGEXP_LUTM05b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTM06  ;  /*!< 0x0000024c :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTM06        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, minus point No. */
        } TFU1_LOGEXP_LUTM06b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTM07  ;  /*!< 0x00000250 :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTM07        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, minus point No. */
        } TFU1_LOGEXP_LUTM07b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTM08  ;  /*!< 0x00000254 :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTM08        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, minus point No. */
        } TFU1_LOGEXP_LUTM08b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTM09  ;  /*!< 0x00000258 :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTM09        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, minus point No. */
        } TFU1_LOGEXP_LUTM09b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTM10  ;  /*!< 0x0000025c :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTM10        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, minus point No. */
        } TFU1_LOGEXP_LUTM10b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTM11  ;  /*!< 0x00000260 :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTM11        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, minus point No. */
        } TFU1_LOGEXP_LUTM11b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTM12  ;  /*!< 0x00000264 :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTM12        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, minus point No. */
        } TFU1_LOGEXP_LUTM12b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTM13  ;  /*!< 0x00000268 :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTM13        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, minus point No. */
        } TFU1_LOGEXP_LUTM13b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTM14  ;  /*!< 0x0000026c :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTM14        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, minus point No. */
        } TFU1_LOGEXP_LUTM14b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTM15  ;  /*!< 0x00000270 :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTM15        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, minus point No. */
        } TFU1_LOGEXP_LUTM15b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTM16  ;  /*!< 0x00000274 :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTM16        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, minus point No. */
        } TFU1_LOGEXP_LUTM16b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTM17  ;  /*!< 0x00000278 :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTM17        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, minus point No. */
        } TFU1_LOGEXP_LUTM17b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTM18  ;  /*!< 0x0000027c :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTM18        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, minus point No. */
        } TFU1_LOGEXP_LUTM18b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTM19  ;  /*!< 0x00000280 :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTM19        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, minus point No. */
        } TFU1_LOGEXP_LUTM19b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTM20  ;  /*!< 0x00000284 :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTM20        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, minus point No. */
        } TFU1_LOGEXP_LUTM20b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTM21  ;  /*!< 0x00000288 :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTM21        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, minus point No. */
        } TFU1_LOGEXP_LUTM21b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTM22  ;  /*!< 0x0000028c :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTM22        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, minus point No. */
        } TFU1_LOGEXP_LUTM22b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTM23  ;  /*!< 0x00000290 :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTM23        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, minus point No. */
        } TFU1_LOGEXP_LUTM23b;
    };

    union
    {
        __IOM uint32_t TFU1_LOGEXP_LUTM24  ;  /*!< 0x00000294 :  */
    
        struct
        {
            __IOM uint32_t TFU1_LOGEXP_LUTM24        : 32;     /*!< [31: 0] : tfu1 log&exp operator lut, minus point No. */
        } TFU1_LOGEXP_LUTM24b;
    };

    union
    {
        __IOM uint32_t TFU_INT_FLAGS       ;  /*!< 0x00000298 :  */
    
        struct
        {
            __IOM uint32_t TFU1_TRD3_INT_REQ_OF      : 1 ;     /*!< [ 0: 0] : tfu1 thread3 overflow interrupt flag, high means arg fifo is written when fifo full; set 0 to clear. */
            __IOM uint32_t TFU1_TRD2_INT_REQ_OF      : 1 ;     /*!< [ 1: 1] : tfu1 thread2 overflow interrupt flag, high means arg fifo is written when fifo full; set 0 to clear. */
            __IOM uint32_t TFU1_TRD1_INT_REQ_OF      : 1 ;     /*!< [ 2: 2] : tfu1 thread1 overflow interrupt flag, high means arg fifo is written when fifo full; set 0 to clear. */
            __IOM uint32_t TFU1_TRD0_INT_REQ_OF      : 1 ;     /*!< [ 3: 3] : tfu1 thread0 overflow interrupt flag, high means arg fifo is written when fifo full; set 0 to clear. */
            __IOM uint32_t TFU1_TRD3_INT_REQ_UF      : 1 ;     /*!< [ 4: 4] : tfu1 thread3 underflow interrupt flag, high means res fifo is read when fifo empty; set 0 to clear. */
            __IOM uint32_t TFU1_TRD2_INT_REQ_UF      : 1 ;     /*!< [ 5: 5] : tfu1 thread2 underflow interrupt flag, high means res fifo is read when fifo empty; set 0 to clear. */
            __IOM uint32_t TFU1_TRD1_INT_REQ_UF      : 1 ;     /*!< [ 6: 6] : tfu1 thread1 underflow interrupt flag, high means res fifo is read when fifo empty; set 0 to clear. */
            __IOM uint32_t TFU1_TRD0_INT_REQ_UF      : 1 ;     /*!< [ 7: 7] : tfu1 thread0 underflow interrupt flag, high means res fifo is read when fifo empty; set 0 to clear. */
            __IOM uint32_t TFU1_TRD3_INT_REQ         : 1 ;     /*!< [ 8: 8] : tfu1 thread3 interrupt flag, high means res fifo is ready to be read; set 0 to clear. */
            __IOM uint32_t TFU1_TRD2_INT_REQ         : 1 ;     /*!< [ 9: 9] : tfu1 thread2 interrupt flag, high means res fifo is ready to be read; set 0 to clear. */
            __IOM uint32_t TFU1_TRD1_INT_REQ         : 1 ;     /*!< [10:10] : tfu1 thread1 interrupt flag, high means res fifo is ready to be read; set 0 to clear. */
            __IOM uint32_t TFU1_TRD0_INT_REQ         : 1 ;     /*!< [11:11] : tfu1 thread0 interrupt flag, high means res fifo is ready to be read; set 0 to clear. */
            __IOM uint32_t TFU0_TRD3_INT_REQ_OF      : 1 ;     /*!< [12:12] : tfu0 thread3 overflow interrupt flag, high means arg fifo is written when fifo full; set 0 to clear. */
            __IOM uint32_t TFU0_TRD2_INT_REQ_OF      : 1 ;     /*!< [13:13] : tfu0 thread2 overflow interrupt flag, high means arg fifo is written when fifo full; set 0 to clear. */
            __IOM uint32_t TFU0_TRD1_INT_REQ_OF      : 1 ;     /*!< [14:14] : tfu0 thread1 overflow interrupt flag, high means arg fifo is written when fifo full; set 0 to clear. */
            __IOM uint32_t TFU0_TRD0_INT_REQ_OF      : 1 ;     /*!< [15:15] : tfu0 thread0 overflow interrupt flag, high means arg fifo is written when fifo full; set 0 to clear. */
            __IOM uint32_t TFU0_TRD3_INT_REQ_UF      : 1 ;     /*!< [16:16] : tfu0 thread3 underflow interrupt flag, high means res fifo is read when fifo empty; set 0 to clear. */
            __IOM uint32_t TFU0_TRD2_INT_REQ_UF      : 1 ;     /*!< [17:17] : tfu0 thread2 underflow interrupt flag, high means res fifo is read when fifo empty; set 0 to clear. */
            __IOM uint32_t TFU0_TRD1_INT_REQ_UF      : 1 ;     /*!< [18:18] : tfu0 thread1 underflow interrupt flag, high means res fifo is read when fifo empty; set 0 to clear. */
            __IOM uint32_t TFU0_TRD0_INT_REQ_UF      : 1 ;     /*!< [19:19] : tfu0 thread0 underflow interrupt flag, high means res fifo is read when fifo empty; set 0 to clear. */
            __IOM uint32_t TFU0_TRD3_INT_REQ         : 1 ;     /*!< [20:20] : tfu0 thread3 interrupt flag, high means res fifo is ready to be read; set 0 to clear. */
            __IOM uint32_t TFU0_TRD2_INT_REQ         : 1 ;     /*!< [21:21] : tfu0 thread2 interrupt flag, high means res fifo is ready to be read; set 0 to clear. */
            __IOM uint32_t TFU0_TRD1_INT_REQ         : 1 ;     /*!< [22:22] : tfu0 thread1 interrupt flag, high means res fifo is ready to be read; set 0 to clear. */
            __IOM uint32_t TFU0_TRD0_INT_REQ         : 1 ;     /*!< [23:23] : tfu0 thread0 interrupt flag, high means res fifo is ready to be read; set 0 to clear. */
                  uint32_t RSV_0                     : 8 ;     /*!< [31:24] : reserved. */
        } TFU_INT_FLAGSb;
    };

    union
    {
        __IOM uint32_t TFU_INT_EN          ;  /*!< 0x0000029c :  */
    
        struct
        {
            __IOM uint32_t TFU1_TRD3_INT_REQ_OF_EN   : 1 ;     /*!< [ 0: 0] : tfu1 thread3 overflow interrupt enable , active high. */
            __IOM uint32_t TFU1_TRD2_INT_REQ_OF_EN   : 1 ;     /*!< [ 1: 1] : tfu1 thread2 overflow interrupt enable , active high. */
            __IOM uint32_t TFU1_TRD1_INT_REQ_OF_EN   : 1 ;     /*!< [ 2: 2] : tfu1 thread1 overflow interrupt enable , active high. */
            __IOM uint32_t TFU1_TRD0_INT_REQ_OF_EN   : 1 ;     /*!< [ 3: 3] : tfu1 thread0 overflow interrupt enable , active high. */
            __IOM uint32_t TFU1_TRD3_INT_REQ_UF_EN   : 1 ;     /*!< [ 4: 4] : tfu1 thread3 underflow interrupt enable, active high. */
            __IOM uint32_t TFU1_TRD2_INT_REQ_UF_EN   : 1 ;     /*!< [ 5: 5] : tfu1 thread2 underflow interrupt enable, active high. */
            __IOM uint32_t TFU1_TRD1_INT_REQ_UF_EN   : 1 ;     /*!< [ 6: 6] : tfu1 thread1 underflow interrupt enable, active high. */
            __IOM uint32_t TFU1_TRD0_INT_REQ_UF_EN   : 1 ;     /*!< [ 7: 7] : tfu1 thread0 underflow interrupt enable, active high. */
            __IOM uint32_t TFU1_TRD3_INT_REQ_EN      : 1 ;     /*!< [ 8: 8] : tfu0 thread3 res data interrupt enable , active high. */
            __IOM uint32_t TFU1_TRD2_INT_REQ_EN      : 1 ;     /*!< [ 9: 9] : tfu0 thread2 res data interrupt enable , active high. */
            __IOM uint32_t TFU1_TRD1_INT_REQ_EN      : 1 ;     /*!< [10:10] : tfu0 thread1 res data interrupt enable , active high. */
            __IOM uint32_t TFU1_TRD0_INT_REQ_EN      : 1 ;     /*!< [11:11] : tfu0 thread0 res data interrupt enable , active high. */
            __IOM uint32_t TFU0_TRD3_INT_REQ_OF_EN   : 1 ;     /*!< [12:12] : tfu0 thread3 overflow interrupt enable , active high. */
            __IOM uint32_t TFU0_TRD2_INT_REQ_OF_EN   : 1 ;     /*!< [13:13] : tfu0 thread2 overflow interrupt enable , active high. */
            __IOM uint32_t TFU0_TRD1_INT_REQ_OF_EN   : 1 ;     /*!< [14:14] : tfu0 thread1 overflow interrupt enable , active high. */
            __IOM uint32_t TFU0_TRD0_INT_REQ_OF_EN   : 1 ;     /*!< [15:15] : tfu0 thread0 overflow interrupt enable , active high. */
            __IOM uint32_t TFU0_TRD3_INT_REQ_UF_EN   : 1 ;     /*!< [16:16] : tfu0 thread3 underflow interrupt enable, active high. */
            __IOM uint32_t TFU0_TRD2_INT_REQ_UF_EN   : 1 ;     /*!< [17:17] : tfu0 thread2 underflow interrupt enable, active high. */
            __IOM uint32_t TFU0_TRD1_INT_REQ_UF_EN   : 1 ;     /*!< [18:18] : tfu0 thread1 underflow interrupt enable, active high. */
            __IOM uint32_t TFU0_TRD0_INT_REQ_UF_EN   : 1 ;     /*!< [19:19] : tfu0 thread0 underflow interrupt enable, active high. */
            __IOM uint32_t TFU0_TRD3_INT_REQ_EN      : 1 ;     /*!< [20:20] : tfu0 thread3 res data interrupt enable , active high. */
            __IOM uint32_t TFU0_TRD2_INT_REQ_EN      : 1 ;     /*!< [21:21] : tfu0 thread2 res data interrupt enable , active high. */
            __IOM uint32_t TFU0_TRD1_INT_REQ_EN      : 1 ;     /*!< [22:22] : tfu0 thread1 res data interrupt enable , active high. */
            __IOM uint32_t TFU0_TRD0_INT_REQ_EN      : 1 ;     /*!< [23:23] : tfu0 thread0 res data interrupt enable , active high. */
            __IOM uint32_t TFU1_TRD3_INT_SBDNT       : 1 ;     /*!< [24:24] : tfu1 thread3 interrupts subordinate, 0 means cpu0, 1 means cpu1. */
            __IOM uint32_t TFU1_TRD2_INT_SBDNT       : 1 ;     /*!< [25:25] : tfu1 thread2 interrupts subordinate, 0 means cpu0, 1 means cpu1. */
            __IOM uint32_t TFU1_TRD1_INT_SBDNT       : 1 ;     /*!< [26:26] : tfu1 thread1 interrupts subordinate, 0 means cpu0, 1 means cpu1. */
            __IOM uint32_t TFU1_TRD0_INT_SBDNT       : 1 ;     /*!< [27:27] : tfu1 thread0 interrupts subordinate, 0 means cpu0, 1 means cpu1. */
            __IOM uint32_t TFU0_TRD3_INT_SBDNT       : 1 ;     /*!< [28:28] : tfu0 thread3 interrupts subordinate, 0 means cpu0, 1 means cpu1. */
            __IOM uint32_t TFU0_TRD2_INT_SBDNT       : 1 ;     /*!< [29:29] : tfu0 thread2 interrupts subordinate, 0 means cpu0, 1 means cpu1. */
            __IOM uint32_t TFU0_TRD1_INT_SBDNT       : 1 ;     /*!< [30:30] : tfu0 thread1 interrupts subordinate, 0 means cpu0, 1 means cpu1. */
            __IOM uint32_t TFU0_TRD0_INT_SBDNT       : 1 ;     /*!< [31:31] : tfu0 thread0 interrupts subordinate, 0 means cpu0, 1 means cpu1. */
        } TFU_INT_ENb;
    };

    uint8_t    RSV_0X2A0[1376];   /*!< 0x000002a0~0x000007ff : reserved */

    /*!< 0x00000800~0x0000083f : group for 0-3 threads of TFU fifo */
    struct
    {
        union
        {
            __IOM uint32_t TFU0_WDATA0         ;  /*!< 0x00000800 :  */
        
            struct
            {
                __IOM uint32_t TFU0_ARG0                 : 32;     /*!< [31: 0] : tfu0 argument0.
                                                                                  <li> if 32bit is selected, data should be here
                                                                                  <li> if 16bit is selected, data should be right aligned */
            } TFU0_WDATA0b;
        };
    
        union
        {
            __IOM uint32_t TFU0_WDATA1         ;  /*!< 0x00000804 :  */
        
            struct
            {
                __IOM uint32_t TFU0_ARG1                 : 32;     /*!< [31: 0] : tfu0 argument1.
                                                                                  <li>if 32bit & 1args is selected, not used
                                                                                  <li>if 16bit & 2args is selected, data should be in lower part */
            } TFU0_WDATA1b;
        };
    
        union
        {
            __IM  uint32_t TFU0_RDATA0         ;  /*!< 0x00000808 :  */
        
            struct
            {
                __IM  uint32_t TFU0_RES0                 : 32;     /*!< [31: 0] : tfu0 response0.
                                                                                  <li>if 32bit is selected, data should be here
                                                                                  <li>if 16bit is selected, data should be in lower part */
            } TFU0_RDATA0b;
        };
    
        union
        {
            __IM  uint32_t TFU0_RDATA1         ;  /*!< 0x0000080c :  */
        
            struct
            {
                __IM  uint32_t TFU0_RES1                 : 32;     /*!< [31: 0] : tfu0 response1.
                                                                                  <li>if 32bit & 1args is selected, not used
                                                                                  <li>if 16bit & 2args is selected, data should be in lower part */
            } TFU0_RDATA1b;
        };
    
    } TFU0_FIFOb[4];

    /*!< 0x00000840~0x0000087f : group for 0-3 threads of TFU fifo */
    struct
    {
        union
        {
            __IOM uint32_t TFU1_WDATA0         ;  /*!< 0x00000840 :  */
        
            struct
            {
                __IOM uint32_t TFU1_ARG0                 : 32;     /*!< [31: 0] : tfu1 argument0.
                                                                                  <li> if 32bit is selected, data should be here
                                                                                  <li> if 16bit is selected, data should be right aligned */
            } TFU1_WDATA0b;
        };
    
        union
        {
            __IOM uint32_t TFU1_WDATA1         ;  /*!< 0x00000844 :  */
        
            struct
            {
                __IOM uint32_t TFU1_ARG1                 : 32;     /*!< [31: 0] : tfu1 argument1.
                                                                                  <li>if 32bit & 1args is selected, not used
                                                                                  <li>if 16bit & 2args is selected, data should be in lower part */
            } TFU1_WDATA1b;
        };
    
        union
        {
            __IM  uint32_t TFU1_RDATA0         ;  /*!< 0x00000848 :  */
        
            struct
            {
                __IM  uint32_t TFU1_RES0                 : 32;     /*!< [31: 0] : tfu1 response0.
                                                                                  <li>if 32bit is selected, data should be here
                                                                                  <li>if 16bit is selected, data should be in lower part */
            } TFU1_RDATA0b;
        };
    
        union
        {
            __IM  uint32_t TFU1_RDATA1         ;  /*!< 0x0000084c :  */
        
            struct
            {
                __IM  uint32_t TFU1_RES1                 : 32;     /*!< [31: 0] : tfu1 response1.
                                                                                  <li>if 32bit & 1args is selected, not used
                                                                                  <li>if 16bit & 2args is selected, data should be in lower part */
            } TFU1_RDATA1b;
        };
    
    } TFU1_FIFOb[4];

} TFU_Type;

/*!
 * @}
 */


/*!
 * \name TFU Base Address Definitions
 *
 * @{
 */

/*! \brief TFU base address */
#define TFU_BASE (0x40100000UL)
/*! \brief TFU base pointer */
#define TFU ((TFU_Type *) TFU_BASE)

/*!
 * @}
 */


/*!
 * \name TFU Register Bitfield Definitions
 *
 * @{
 */

/* TFU0_CSR bitfield */
#define TFU_TFU0_CSR_TFU0_RRDY_Pos    (31U)                                                                                 /*!< TFU0_RRDY Position  31         */ 
#define TFU_TFU0_CSR_TFU0_RRDY_Msk    (0x1U << TFU_TFU0_CSR_TFU0_RRDY_Pos)                                                  /*!< TFU0_RRDY Mask      0x80000000 */
#define TFU_TFU0_CSR_TFU0_RRDY_Set(x) (((uint32_t) (x) << TFU_TFU0_CSR_TFU0_RRDY_Pos) & TFU_TFU0_CSR_TFU0_RRDY_Msk)         /*!< TFU0_RRDY Set Value            */
#define TFU_TFU0_CSR_TFU0_RRDY_Get(x) (((uint32_t) (x) & TFU_TFU0_CSR_TFU0_RRDY_Msk) >> TFU_TFU0_CSR_TFU0_RRDY_Pos)         /*!< TFU0_RRDY Get Value            */

#define TFU_TFU0_CSR_TFU0_ARG_SIZE_Pos    (22U)                                                                                 /*!< TFU0_ARG_SIZE Position  22         */ 
#define TFU_TFU0_CSR_TFU0_ARG_SIZE_Msk    (0x1U << TFU_TFU0_CSR_TFU0_ARG_SIZE_Pos)                                              /*!< TFU0_ARG_SIZE Mask      0x00400000 */
#define TFU_TFU0_CSR_TFU0_ARG_SIZE_Set(x) (((uint32_t) (x) << TFU_TFU0_CSR_TFU0_ARG_SIZE_Pos) & TFU_TFU0_CSR_TFU0_ARG_SIZE_Msk) /*!< TFU0_ARG_SIZE Set Value            */
#define TFU_TFU0_CSR_TFU0_ARG_SIZE_Get(x) (((uint32_t) (x) & TFU_TFU0_CSR_TFU0_ARG_SIZE_Msk) >> TFU_TFU0_CSR_TFU0_ARG_SIZE_Pos) /*!< TFU0_ARG_SIZE Get Value            */

#define TFU_TFU0_CSR_TFU0_RES_SIZE_Pos    (21U)                                                                                 /*!< TFU0_RES_SIZE Position  21         */ 
#define TFU_TFU0_CSR_TFU0_RES_SIZE_Msk    (0x1U << TFU_TFU0_CSR_TFU0_RES_SIZE_Pos)                                              /*!< TFU0_RES_SIZE Mask      0x00200000 */
#define TFU_TFU0_CSR_TFU0_RES_SIZE_Set(x) (((uint32_t) (x) << TFU_TFU0_CSR_TFU0_RES_SIZE_Pos) & TFU_TFU0_CSR_TFU0_RES_SIZE_Msk) /*!< TFU0_RES_SIZE Set Value            */
#define TFU_TFU0_CSR_TFU0_RES_SIZE_Get(x) (((uint32_t) (x) & TFU_TFU0_CSR_TFU0_RES_SIZE_Msk) >> TFU_TFU0_CSR_TFU0_RES_SIZE_Pos) /*!< TFU0_RES_SIZE Get Value            */

#define TFU_TFU0_CSR_TFU0_ARG_NUM_Pos    (20U)                                                                                 /*!< TFU0_ARG_NUM Position  20         */ 
#define TFU_TFU0_CSR_TFU0_ARG_NUM_Msk    (0x1U << TFU_TFU0_CSR_TFU0_ARG_NUM_Pos)                                               /*!< TFU0_ARG_NUM Mask      0x00100000 */
#define TFU_TFU0_CSR_TFU0_ARG_NUM_Set(x) (((uint32_t) (x) << TFU_TFU0_CSR_TFU0_ARG_NUM_Pos) & TFU_TFU0_CSR_TFU0_ARG_NUM_Msk)   /*!< TFU0_ARG_NUM Set Value            */
#define TFU_TFU0_CSR_TFU0_ARG_NUM_Get(x) (((uint32_t) (x) & TFU_TFU0_CSR_TFU0_ARG_NUM_Msk) >> TFU_TFU0_CSR_TFU0_ARG_NUM_Pos)   /*!< TFU0_ARG_NUM Get Value            */

#define TFU_TFU0_CSR_TFU0_RES_NUM_Pos    (19U)                                                                                 /*!< TFU0_RES_NUM Position  19         */ 
#define TFU_TFU0_CSR_TFU0_RES_NUM_Msk    (0x1U << TFU_TFU0_CSR_TFU0_RES_NUM_Pos)                                               /*!< TFU0_RES_NUM Mask      0x00080000 */
#define TFU_TFU0_CSR_TFU0_RES_NUM_Set(x) (((uint32_t) (x) << TFU_TFU0_CSR_TFU0_RES_NUM_Pos) & TFU_TFU0_CSR_TFU0_RES_NUM_Msk)   /*!< TFU0_RES_NUM Set Value            */
#define TFU_TFU0_CSR_TFU0_RES_NUM_Get(x) (((uint32_t) (x) & TFU_TFU0_CSR_TFU0_RES_NUM_Msk) >> TFU_TFU0_CSR_TFU0_RES_NUM_Pos)   /*!< TFU0_RES_NUM Get Value            */

#define TFU_TFU0_CSR_TFU0_DMA_WEN_Pos    (18U)                                                                                 /*!< TFU0_DMA_WEN Position  18         */ 
#define TFU_TFU0_CSR_TFU0_DMA_WEN_Msk    (0x1U << TFU_TFU0_CSR_TFU0_DMA_WEN_Pos)                                               /*!< TFU0_DMA_WEN Mask      0x00040000 */
#define TFU_TFU0_CSR_TFU0_DMA_WEN_Set(x) (((uint32_t) (x) << TFU_TFU0_CSR_TFU0_DMA_WEN_Pos) & TFU_TFU0_CSR_TFU0_DMA_WEN_Msk)   /*!< TFU0_DMA_WEN Set Value            */
#define TFU_TFU0_CSR_TFU0_DMA_WEN_Get(x) (((uint32_t) (x) & TFU_TFU0_CSR_TFU0_DMA_WEN_Msk) >> TFU_TFU0_CSR_TFU0_DMA_WEN_Pos)   /*!< TFU0_DMA_WEN Get Value            */

#define TFU_TFU0_CSR_TFU0_DMA_REN_Pos    (17U)                                                                                 /*!< TFU0_DMA_REN Position  17         */ 
#define TFU_TFU0_CSR_TFU0_DMA_REN_Msk    (0x1U << TFU_TFU0_CSR_TFU0_DMA_REN_Pos)                                               /*!< TFU0_DMA_REN Mask      0x00020000 */
#define TFU_TFU0_CSR_TFU0_DMA_REN_Set(x) (((uint32_t) (x) << TFU_TFU0_CSR_TFU0_DMA_REN_Pos) & TFU_TFU0_CSR_TFU0_DMA_REN_Msk)   /*!< TFU0_DMA_REN Set Value            */
#define TFU_TFU0_CSR_TFU0_DMA_REN_Get(x) (((uint32_t) (x) & TFU_TFU0_CSR_TFU0_DMA_REN_Msk) >> TFU_TFU0_CSR_TFU0_DMA_REN_Pos)   /*!< TFU0_DMA_REN Get Value            */

#define TFU_TFU0_CSR_TFU0_FARG_FUL_Pos    (15U)                                                                                 /*!< TFU0_FARG_FUL Position  15         */ 
#define TFU_TFU0_CSR_TFU0_FARG_FUL_Msk    (0x1U << TFU_TFU0_CSR_TFU0_FARG_FUL_Pos)                                              /*!< TFU0_FARG_FUL Mask      0x00008000 */
#define TFU_TFU0_CSR_TFU0_FARG_FUL_Set(x) (((uint32_t) (x) << TFU_TFU0_CSR_TFU0_FARG_FUL_Pos) & TFU_TFU0_CSR_TFU0_FARG_FUL_Msk) /*!< TFU0_FARG_FUL Set Value            */
#define TFU_TFU0_CSR_TFU0_FARG_FUL_Get(x) (((uint32_t) (x) & TFU_TFU0_CSR_TFU0_FARG_FUL_Msk) >> TFU_TFU0_CSR_TFU0_FARG_FUL_Pos) /*!< TFU0_FARG_FUL Get Value            */

#define TFU_TFU0_CSR_TFU0_FARG_EPT_Pos    (14U)                                                                                 /*!< TFU0_FARG_EPT Position  14         */ 
#define TFU_TFU0_CSR_TFU0_FARG_EPT_Msk    (0x1U << TFU_TFU0_CSR_TFU0_FARG_EPT_Pos)                                              /*!< TFU0_FARG_EPT Mask      0x00004000 */
#define TFU_TFU0_CSR_TFU0_FARG_EPT_Set(x) (((uint32_t) (x) << TFU_TFU0_CSR_TFU0_FARG_EPT_Pos) & TFU_TFU0_CSR_TFU0_FARG_EPT_Msk) /*!< TFU0_FARG_EPT Set Value            */
#define TFU_TFU0_CSR_TFU0_FARG_EPT_Get(x) (((uint32_t) (x) & TFU_TFU0_CSR_TFU0_FARG_EPT_Msk) >> TFU_TFU0_CSR_TFU0_FARG_EPT_Pos) /*!< TFU0_FARG_EPT Get Value            */

#define TFU_TFU0_CSR_TFU0_FRES_FUL_Pos    (13U)                                                                                 /*!< TFU0_FRES_FUL Position  13         */ 
#define TFU_TFU0_CSR_TFU0_FRES_FUL_Msk    (0x1U << TFU_TFU0_CSR_TFU0_FRES_FUL_Pos)                                              /*!< TFU0_FRES_FUL Mask      0x00002000 */
#define TFU_TFU0_CSR_TFU0_FRES_FUL_Set(x) (((uint32_t) (x) << TFU_TFU0_CSR_TFU0_FRES_FUL_Pos) & TFU_TFU0_CSR_TFU0_FRES_FUL_Msk) /*!< TFU0_FRES_FUL Set Value            */
#define TFU_TFU0_CSR_TFU0_FRES_FUL_Get(x) (((uint32_t) (x) & TFU_TFU0_CSR_TFU0_FRES_FUL_Msk) >> TFU_TFU0_CSR_TFU0_FRES_FUL_Pos) /*!< TFU0_FRES_FUL Get Value            */

#define TFU_TFU0_CSR_TFU0_FRES_EPT_Pos    (12U)                                                                                 /*!< TFU0_FRES_EPT Position  12         */ 
#define TFU_TFU0_CSR_TFU0_FRES_EPT_Msk    (0x1U << TFU_TFU0_CSR_TFU0_FRES_EPT_Pos)                                              /*!< TFU0_FRES_EPT Mask      0x00001000 */
#define TFU_TFU0_CSR_TFU0_FRES_EPT_Set(x) (((uint32_t) (x) << TFU_TFU0_CSR_TFU0_FRES_EPT_Pos) & TFU_TFU0_CSR_TFU0_FRES_EPT_Msk) /*!< TFU0_FRES_EPT Set Value            */
#define TFU_TFU0_CSR_TFU0_FRES_EPT_Get(x) (((uint32_t) (x) & TFU_TFU0_CSR_TFU0_FRES_EPT_Msk) >> TFU_TFU0_CSR_TFU0_FRES_EPT_Pos) /*!< TFU0_FRES_EPT Get Value            */

#define TFU_TFU0_CSR_TFU0_PRECISION_Pos    (4U)                                                                                  /*!< TFU0_PRECISION Position  4          */ 
#define TFU_TFU0_CSR_TFU0_PRECISION_Msk    (0xfU << TFU_TFU0_CSR_TFU0_PRECISION_Pos)                                             /*!< TFU0_PRECISION Mask      0x000000F0 */
#define TFU_TFU0_CSR_TFU0_PRECISION_Set(x) (((uint32_t) (x) << TFU_TFU0_CSR_TFU0_PRECISION_Pos) & TFU_TFU0_CSR_TFU0_PRECISION_Msk) /*!< TFU0_PRECISION Set Value            */
#define TFU_TFU0_CSR_TFU0_PRECISION_Get(x) (((uint32_t) (x) & TFU_TFU0_CSR_TFU0_PRECISION_Msk) >> TFU_TFU0_CSR_TFU0_PRECISION_Pos) /*!< TFU0_PRECISION Get Value            */

#define TFU_TFU0_CSR_TFU0_FUNC_SEL_Pos    (0U)                                                                                  /*!< TFU0_FUNC_SEL Position  0          */ 
#define TFU_TFU0_CSR_TFU0_FUNC_SEL_Msk    (0xfU << TFU_TFU0_CSR_TFU0_FUNC_SEL_Pos)                                              /*!< TFU0_FUNC_SEL Mask      0x0000000F */
#define TFU_TFU0_CSR_TFU0_FUNC_SEL_Set(x) (((uint32_t) (x) << TFU_TFU0_CSR_TFU0_FUNC_SEL_Pos) & TFU_TFU0_CSR_TFU0_FUNC_SEL_Msk) /*!< TFU0_FUNC_SEL Set Value            */
#define TFU_TFU0_CSR_TFU0_FUNC_SEL_Get(x) (((uint32_t) (x) & TFU_TFU0_CSR_TFU0_FUNC_SEL_Msk) >> TFU_TFU0_CSR_TFU0_FUNC_SEL_Pos) /*!< TFU0_FUNC_SEL Get Value            */

/* TFU1_CSR bitfield */
#define TFU_TFU1_CSR_TFU1_RRDY_Pos    (31U)                                                                                 /*!< TFU1_RRDY Position  31         */ 
#define TFU_TFU1_CSR_TFU1_RRDY_Msk    (0x1U << TFU_TFU1_CSR_TFU1_RRDY_Pos)                                                  /*!< TFU1_RRDY Mask      0x80000000 */
#define TFU_TFU1_CSR_TFU1_RRDY_Set(x) (((uint32_t) (x) << TFU_TFU1_CSR_TFU1_RRDY_Pos) & TFU_TFU1_CSR_TFU1_RRDY_Msk)         /*!< TFU1_RRDY Set Value            */
#define TFU_TFU1_CSR_TFU1_RRDY_Get(x) (((uint32_t) (x) & TFU_TFU1_CSR_TFU1_RRDY_Msk) >> TFU_TFU1_CSR_TFU1_RRDY_Pos)         /*!< TFU1_RRDY Get Value            */

#define TFU_TFU1_CSR_TFU1_ARG_SIZE_Pos    (22U)                                                                                 /*!< TFU1_ARG_SIZE Position  22         */ 
#define TFU_TFU1_CSR_TFU1_ARG_SIZE_Msk    (0x1U << TFU_TFU1_CSR_TFU1_ARG_SIZE_Pos)                                              /*!< TFU1_ARG_SIZE Mask      0x00400000 */
#define TFU_TFU1_CSR_TFU1_ARG_SIZE_Set(x) (((uint32_t) (x) << TFU_TFU1_CSR_TFU1_ARG_SIZE_Pos) & TFU_TFU1_CSR_TFU1_ARG_SIZE_Msk) /*!< TFU1_ARG_SIZE Set Value            */
#define TFU_TFU1_CSR_TFU1_ARG_SIZE_Get(x) (((uint32_t) (x) & TFU_TFU1_CSR_TFU1_ARG_SIZE_Msk) >> TFU_TFU1_CSR_TFU1_ARG_SIZE_Pos) /*!< TFU1_ARG_SIZE Get Value            */

#define TFU_TFU1_CSR_TFU1_RES_SIZE_Pos    (21U)                                                                                 /*!< TFU1_RES_SIZE Position  21         */ 
#define TFU_TFU1_CSR_TFU1_RES_SIZE_Msk    (0x1U << TFU_TFU1_CSR_TFU1_RES_SIZE_Pos)                                              /*!< TFU1_RES_SIZE Mask      0x00200000 */
#define TFU_TFU1_CSR_TFU1_RES_SIZE_Set(x) (((uint32_t) (x) << TFU_TFU1_CSR_TFU1_RES_SIZE_Pos) & TFU_TFU1_CSR_TFU1_RES_SIZE_Msk) /*!< TFU1_RES_SIZE Set Value            */
#define TFU_TFU1_CSR_TFU1_RES_SIZE_Get(x) (((uint32_t) (x) & TFU_TFU1_CSR_TFU1_RES_SIZE_Msk) >> TFU_TFU1_CSR_TFU1_RES_SIZE_Pos) /*!< TFU1_RES_SIZE Get Value            */

#define TFU_TFU1_CSR_TFU1_ARG_NUM_Pos    (20U)                                                                                 /*!< TFU1_ARG_NUM Position  20         */ 
#define TFU_TFU1_CSR_TFU1_ARG_NUM_Msk    (0x1U << TFU_TFU1_CSR_TFU1_ARG_NUM_Pos)                                               /*!< TFU1_ARG_NUM Mask      0x00100000 */
#define TFU_TFU1_CSR_TFU1_ARG_NUM_Set(x) (((uint32_t) (x) << TFU_TFU1_CSR_TFU1_ARG_NUM_Pos) & TFU_TFU1_CSR_TFU1_ARG_NUM_Msk)   /*!< TFU1_ARG_NUM Set Value            */
#define TFU_TFU1_CSR_TFU1_ARG_NUM_Get(x) (((uint32_t) (x) & TFU_TFU1_CSR_TFU1_ARG_NUM_Msk) >> TFU_TFU1_CSR_TFU1_ARG_NUM_Pos)   /*!< TFU1_ARG_NUM Get Value            */

#define TFU_TFU1_CSR_TFU1_RES_NUM_Pos    (19U)                                                                                 /*!< TFU1_RES_NUM Position  19         */ 
#define TFU_TFU1_CSR_TFU1_RES_NUM_Msk    (0x1U << TFU_TFU1_CSR_TFU1_RES_NUM_Pos)                                               /*!< TFU1_RES_NUM Mask      0x00080000 */
#define TFU_TFU1_CSR_TFU1_RES_NUM_Set(x) (((uint32_t) (x) << TFU_TFU1_CSR_TFU1_RES_NUM_Pos) & TFU_TFU1_CSR_TFU1_RES_NUM_Msk)   /*!< TFU1_RES_NUM Set Value            */
#define TFU_TFU1_CSR_TFU1_RES_NUM_Get(x) (((uint32_t) (x) & TFU_TFU1_CSR_TFU1_RES_NUM_Msk) >> TFU_TFU1_CSR_TFU1_RES_NUM_Pos)   /*!< TFU1_RES_NUM Get Value            */

#define TFU_TFU1_CSR_TFU1_DMA_WEN_Pos    (18U)                                                                                 /*!< TFU1_DMA_WEN Position  18         */ 
#define TFU_TFU1_CSR_TFU1_DMA_WEN_Msk    (0x1U << TFU_TFU1_CSR_TFU1_DMA_WEN_Pos)                                               /*!< TFU1_DMA_WEN Mask      0x00040000 */
#define TFU_TFU1_CSR_TFU1_DMA_WEN_Set(x) (((uint32_t) (x) << TFU_TFU1_CSR_TFU1_DMA_WEN_Pos) & TFU_TFU1_CSR_TFU1_DMA_WEN_Msk)   /*!< TFU1_DMA_WEN Set Value            */
#define TFU_TFU1_CSR_TFU1_DMA_WEN_Get(x) (((uint32_t) (x) & TFU_TFU1_CSR_TFU1_DMA_WEN_Msk) >> TFU_TFU1_CSR_TFU1_DMA_WEN_Pos)   /*!< TFU1_DMA_WEN Get Value            */

#define TFU_TFU1_CSR_TFU1_DMA_REN_Pos    (17U)                                                                                 /*!< TFU1_DMA_REN Position  17         */ 
#define TFU_TFU1_CSR_TFU1_DMA_REN_Msk    (0x1U << TFU_TFU1_CSR_TFU1_DMA_REN_Pos)                                               /*!< TFU1_DMA_REN Mask      0x00020000 */
#define TFU_TFU1_CSR_TFU1_DMA_REN_Set(x) (((uint32_t) (x) << TFU_TFU1_CSR_TFU1_DMA_REN_Pos) & TFU_TFU1_CSR_TFU1_DMA_REN_Msk)   /*!< TFU1_DMA_REN Set Value            */
#define TFU_TFU1_CSR_TFU1_DMA_REN_Get(x) (((uint32_t) (x) & TFU_TFU1_CSR_TFU1_DMA_REN_Msk) >> TFU_TFU1_CSR_TFU1_DMA_REN_Pos)   /*!< TFU1_DMA_REN Get Value            */

#define TFU_TFU1_CSR_TFU1_FARG_FUL_Pos    (15U)                                                                                 /*!< TFU1_FARG_FUL Position  15         */ 
#define TFU_TFU1_CSR_TFU1_FARG_FUL_Msk    (0x1U << TFU_TFU1_CSR_TFU1_FARG_FUL_Pos)                                              /*!< TFU1_FARG_FUL Mask      0x00008000 */
#define TFU_TFU1_CSR_TFU1_FARG_FUL_Set(x) (((uint32_t) (x) << TFU_TFU1_CSR_TFU1_FARG_FUL_Pos) & TFU_TFU1_CSR_TFU1_FARG_FUL_Msk) /*!< TFU1_FARG_FUL Set Value            */
#define TFU_TFU1_CSR_TFU1_FARG_FUL_Get(x) (((uint32_t) (x) & TFU_TFU1_CSR_TFU1_FARG_FUL_Msk) >> TFU_TFU1_CSR_TFU1_FARG_FUL_Pos) /*!< TFU1_FARG_FUL Get Value            */

#define TFU_TFU1_CSR_TFU1_FARG_EPT_Pos    (14U)                                                                                 /*!< TFU1_FARG_EPT Position  14         */ 
#define TFU_TFU1_CSR_TFU1_FARG_EPT_Msk    (0x1U << TFU_TFU1_CSR_TFU1_FARG_EPT_Pos)                                              /*!< TFU1_FARG_EPT Mask      0x00004000 */
#define TFU_TFU1_CSR_TFU1_FARG_EPT_Set(x) (((uint32_t) (x) << TFU_TFU1_CSR_TFU1_FARG_EPT_Pos) & TFU_TFU1_CSR_TFU1_FARG_EPT_Msk) /*!< TFU1_FARG_EPT Set Value            */
#define TFU_TFU1_CSR_TFU1_FARG_EPT_Get(x) (((uint32_t) (x) & TFU_TFU1_CSR_TFU1_FARG_EPT_Msk) >> TFU_TFU1_CSR_TFU1_FARG_EPT_Pos) /*!< TFU1_FARG_EPT Get Value            */

#define TFU_TFU1_CSR_TFU1_FRES_FUL_Pos    (13U)                                                                                 /*!< TFU1_FRES_FUL Position  13         */ 
#define TFU_TFU1_CSR_TFU1_FRES_FUL_Msk    (0x1U << TFU_TFU1_CSR_TFU1_FRES_FUL_Pos)                                              /*!< TFU1_FRES_FUL Mask      0x00002000 */
#define TFU_TFU1_CSR_TFU1_FRES_FUL_Set(x) (((uint32_t) (x) << TFU_TFU1_CSR_TFU1_FRES_FUL_Pos) & TFU_TFU1_CSR_TFU1_FRES_FUL_Msk) /*!< TFU1_FRES_FUL Set Value            */
#define TFU_TFU1_CSR_TFU1_FRES_FUL_Get(x) (((uint32_t) (x) & TFU_TFU1_CSR_TFU1_FRES_FUL_Msk) >> TFU_TFU1_CSR_TFU1_FRES_FUL_Pos) /*!< TFU1_FRES_FUL Get Value            */

#define TFU_TFU1_CSR_TFU1_FRES_EPT_Pos    (12U)                                                                                 /*!< TFU1_FRES_EPT Position  12         */ 
#define TFU_TFU1_CSR_TFU1_FRES_EPT_Msk    (0x1U << TFU_TFU1_CSR_TFU1_FRES_EPT_Pos)                                              /*!< TFU1_FRES_EPT Mask      0x00001000 */
#define TFU_TFU1_CSR_TFU1_FRES_EPT_Set(x) (((uint32_t) (x) << TFU_TFU1_CSR_TFU1_FRES_EPT_Pos) & TFU_TFU1_CSR_TFU1_FRES_EPT_Msk) /*!< TFU1_FRES_EPT Set Value            */
#define TFU_TFU1_CSR_TFU1_FRES_EPT_Get(x) (((uint32_t) (x) & TFU_TFU1_CSR_TFU1_FRES_EPT_Msk) >> TFU_TFU1_CSR_TFU1_FRES_EPT_Pos) /*!< TFU1_FRES_EPT Get Value            */

#define TFU_TFU1_CSR_TFU1_PRECISION_Pos    (4U)                                                                                  /*!< TFU1_PRECISION Position  4          */ 
#define TFU_TFU1_CSR_TFU1_PRECISION_Msk    (0xfU << TFU_TFU1_CSR_TFU1_PRECISION_Pos)                                             /*!< TFU1_PRECISION Mask      0x000000F0 */
#define TFU_TFU1_CSR_TFU1_PRECISION_Set(x) (((uint32_t) (x) << TFU_TFU1_CSR_TFU1_PRECISION_Pos) & TFU_TFU1_CSR_TFU1_PRECISION_Msk) /*!< TFU1_PRECISION Set Value            */
#define TFU_TFU1_CSR_TFU1_PRECISION_Get(x) (((uint32_t) (x) & TFU_TFU1_CSR_TFU1_PRECISION_Msk) >> TFU_TFU1_CSR_TFU1_PRECISION_Pos) /*!< TFU1_PRECISION Get Value            */

#define TFU_TFU1_CSR_TFU1_FUNC_SEL_Pos    (0U)                                                                                  /*!< TFU1_FUNC_SEL Position  0          */ 
#define TFU_TFU1_CSR_TFU1_FUNC_SEL_Msk    (0xfU << TFU_TFU1_CSR_TFU1_FUNC_SEL_Pos)                                              /*!< TFU1_FUNC_SEL Mask      0x0000000F */
#define TFU_TFU1_CSR_TFU1_FUNC_SEL_Set(x) (((uint32_t) (x) << TFU_TFU1_CSR_TFU1_FUNC_SEL_Pos) & TFU_TFU1_CSR_TFU1_FUNC_SEL_Msk) /*!< TFU1_FUNC_SEL Set Value            */
#define TFU_TFU1_CSR_TFU1_FUNC_SEL_Get(x) (((uint32_t) (x) & TFU_TFU1_CSR_TFU1_FUNC_SEL_Msk) >> TFU_TFU1_CSR_TFU1_FUNC_SEL_Pos) /*!< TFU1_FUNC_SEL Get Value            */

/* TFU0_WDATA0 bitfield */
#define TFU_TFU0_WDATA0_TFU0_ARG0_Pos    (0U)                                                                                  /*!< TFU0_ARG0 Position  0          */ 
#define TFU_TFU0_WDATA0_TFU0_ARG0_Msk    (0xffffffffU << TFU_TFU0_WDATA0_TFU0_ARG0_Pos)                                        /*!< TFU0_ARG0 Mask      0xFFFFFFFF */
#define TFU_TFU0_WDATA0_TFU0_ARG0_Set(x) (((uint32_t) (x) << TFU_TFU0_WDATA0_TFU0_ARG0_Pos) & TFU_TFU0_WDATA0_TFU0_ARG0_Msk)   /*!< TFU0_ARG0 Set Value            */
#define TFU_TFU0_WDATA0_TFU0_ARG0_Get(x) (((uint32_t) (x) & TFU_TFU0_WDATA0_TFU0_ARG0_Msk) >> TFU_TFU0_WDATA0_TFU0_ARG0_Pos)   /*!< TFU0_ARG0 Get Value            */

/* TFU0_WDATA1 bitfield */
#define TFU_TFU0_WDATA1_TFU0_ARG1_Pos    (0U)                                                                                  /*!< TFU0_ARG1 Position  0          */ 
#define TFU_TFU0_WDATA1_TFU0_ARG1_Msk    (0xffffffffU << TFU_TFU0_WDATA1_TFU0_ARG1_Pos)                                        /*!< TFU0_ARG1 Mask      0xFFFFFFFF */
#define TFU_TFU0_WDATA1_TFU0_ARG1_Set(x) (((uint32_t) (x) << TFU_TFU0_WDATA1_TFU0_ARG1_Pos) & TFU_TFU0_WDATA1_TFU0_ARG1_Msk)   /*!< TFU0_ARG1 Set Value            */
#define TFU_TFU0_WDATA1_TFU0_ARG1_Get(x) (((uint32_t) (x) & TFU_TFU0_WDATA1_TFU0_ARG1_Msk) >> TFU_TFU0_WDATA1_TFU0_ARG1_Pos)   /*!< TFU0_ARG1 Get Value            */

/* TFU0_RDATA0 bitfield */
#define TFU_TFU0_RDATA0_TFU0_RES0_Pos    (0U)                                                                                  /*!< TFU0_RES0 Position  0          */ 
#define TFU_TFU0_RDATA0_TFU0_RES0_Msk    (0xffffffffU << TFU_TFU0_RDATA0_TFU0_RES0_Pos)                                        /*!< TFU0_RES0 Mask      0xFFFFFFFF */
#define TFU_TFU0_RDATA0_TFU0_RES0_Set(x) (((uint32_t) (x) << TFU_TFU0_RDATA0_TFU0_RES0_Pos) & TFU_TFU0_RDATA0_TFU0_RES0_Msk)   /*!< TFU0_RES0 Set Value            */
#define TFU_TFU0_RDATA0_TFU0_RES0_Get(x) (((uint32_t) (x) & TFU_TFU0_RDATA0_TFU0_RES0_Msk) >> TFU_TFU0_RDATA0_TFU0_RES0_Pos)   /*!< TFU0_RES0 Get Value            */

/* TFU0_RDATA1 bitfield */
#define TFU_TFU0_RDATA1_TFU0_RES1_Pos    (0U)                                                                                  /*!< TFU0_RES1 Position  0          */ 
#define TFU_TFU0_RDATA1_TFU0_RES1_Msk    (0xffffffffU << TFU_TFU0_RDATA1_TFU0_RES1_Pos)                                        /*!< TFU0_RES1 Mask      0xFFFFFFFF */
#define TFU_TFU0_RDATA1_TFU0_RES1_Set(x) (((uint32_t) (x) << TFU_TFU0_RDATA1_TFU0_RES1_Pos) & TFU_TFU0_RDATA1_TFU0_RES1_Msk)   /*!< TFU0_RES1 Set Value            */
#define TFU_TFU0_RDATA1_TFU0_RES1_Get(x) (((uint32_t) (x) & TFU_TFU0_RDATA1_TFU0_RES1_Msk) >> TFU_TFU0_RDATA1_TFU0_RES1_Pos)   /*!< TFU0_RES1 Get Value            */

/* TFU1_WDATA0 bitfield */
#define TFU_TFU1_WDATA0_TFU1_ARG0_Pos    (0U)                                                                                  /*!< TFU1_ARG0 Position  0          */ 
#define TFU_TFU1_WDATA0_TFU1_ARG0_Msk    (0xffffffffU << TFU_TFU1_WDATA0_TFU1_ARG0_Pos)                                        /*!< TFU1_ARG0 Mask      0xFFFFFFFF */
#define TFU_TFU1_WDATA0_TFU1_ARG0_Set(x) (((uint32_t) (x) << TFU_TFU1_WDATA0_TFU1_ARG0_Pos) & TFU_TFU1_WDATA0_TFU1_ARG0_Msk)   /*!< TFU1_ARG0 Set Value            */
#define TFU_TFU1_WDATA0_TFU1_ARG0_Get(x) (((uint32_t) (x) & TFU_TFU1_WDATA0_TFU1_ARG0_Msk) >> TFU_TFU1_WDATA0_TFU1_ARG0_Pos)   /*!< TFU1_ARG0 Get Value            */

/* TFU1_WDATA1 bitfield */
#define TFU_TFU1_WDATA1_TFU1_ARG1_Pos    (0U)                                                                                  /*!< TFU1_ARG1 Position  0          */ 
#define TFU_TFU1_WDATA1_TFU1_ARG1_Msk    (0xffffffffU << TFU_TFU1_WDATA1_TFU1_ARG1_Pos)                                        /*!< TFU1_ARG1 Mask      0xFFFFFFFF */
#define TFU_TFU1_WDATA1_TFU1_ARG1_Set(x) (((uint32_t) (x) << TFU_TFU1_WDATA1_TFU1_ARG1_Pos) & TFU_TFU1_WDATA1_TFU1_ARG1_Msk)   /*!< TFU1_ARG1 Set Value            */
#define TFU_TFU1_WDATA1_TFU1_ARG1_Get(x) (((uint32_t) (x) & TFU_TFU1_WDATA1_TFU1_ARG1_Msk) >> TFU_TFU1_WDATA1_TFU1_ARG1_Pos)   /*!< TFU1_ARG1 Get Value            */

/* TFU1_RDATA0 bitfield */
#define TFU_TFU1_RDATA0_TFU1_RES0_Pos    (0U)                                                                                  /*!< TFU1_RES0 Position  0          */ 
#define TFU_TFU1_RDATA0_TFU1_RES0_Msk    (0xffffffffU << TFU_TFU1_RDATA0_TFU1_RES0_Pos)                                        /*!< TFU1_RES0 Mask      0xFFFFFFFF */
#define TFU_TFU1_RDATA0_TFU1_RES0_Set(x) (((uint32_t) (x) << TFU_TFU1_RDATA0_TFU1_RES0_Pos) & TFU_TFU1_RDATA0_TFU1_RES0_Msk)   /*!< TFU1_RES0 Set Value            */
#define TFU_TFU1_RDATA0_TFU1_RES0_Get(x) (((uint32_t) (x) & TFU_TFU1_RDATA0_TFU1_RES0_Msk) >> TFU_TFU1_RDATA0_TFU1_RES0_Pos)   /*!< TFU1_RES0 Get Value            */

/* TFU1_RDATA1 bitfield */
#define TFU_TFU1_RDATA1_TFU1_RES1_Pos    (0U)                                                                                  /*!< TFU1_RES1 Position  0          */ 
#define TFU_TFU1_RDATA1_TFU1_RES1_Msk    (0xffffffffU << TFU_TFU1_RDATA1_TFU1_RES1_Pos)                                        /*!< TFU1_RES1 Mask      0xFFFFFFFF */
#define TFU_TFU1_RDATA1_TFU1_RES1_Set(x) (((uint32_t) (x) << TFU_TFU1_RDATA1_TFU1_RES1_Pos) & TFU_TFU1_RDATA1_TFU1_RES1_Msk)   /*!< TFU1_RES1 Set Value            */
#define TFU_TFU1_RDATA1_TFU1_RES1_Get(x) (((uint32_t) (x) & TFU_TFU1_RDATA1_TFU1_RES1_Msk) >> TFU_TFU1_RDATA1_TFU1_RES1_Pos)   /*!< TFU1_RES1 Get Value            */

/* TFU0_CFG bitfield */
#define TFU_TFU0_CFG_TFU0_ARB_MODE_Pos    (31U)                                                                                 /*!< TFU0_ARB_MODE Position  31         */ 
#define TFU_TFU0_CFG_TFU0_ARB_MODE_Msk    (0x1U << TFU_TFU0_CFG_TFU0_ARB_MODE_Pos)                                              /*!< TFU0_ARB_MODE Mask      0x80000000 */
#define TFU_TFU0_CFG_TFU0_ARB_MODE_Set(x) (((uint32_t) (x) << TFU_TFU0_CFG_TFU0_ARB_MODE_Pos) & TFU_TFU0_CFG_TFU0_ARB_MODE_Msk) /*!< TFU0_ARB_MODE Set Value            */
#define TFU_TFU0_CFG_TFU0_ARB_MODE_Get(x) (((uint32_t) (x) & TFU_TFU0_CFG_TFU0_ARB_MODE_Msk) >> TFU_TFU0_CFG_TFU0_ARB_MODE_Pos) /*!< TFU0_ARB_MODE Get Value            */

#define TFU_TFU0_CFG_TFU0_TRD3_LOAD_Pos    (7U)                                                                                  /*!< TFU0_TRD3_LOAD Position  7          */ 
#define TFU_TFU0_CFG_TFU0_TRD3_LOAD_Msk    (0x1U << TFU_TFU0_CFG_TFU0_TRD3_LOAD_Pos)                                             /*!< TFU0_TRD3_LOAD Mask      0x00000080 */
#define TFU_TFU0_CFG_TFU0_TRD3_LOAD_Set(x) (((uint32_t) (x) << TFU_TFU0_CFG_TFU0_TRD3_LOAD_Pos) & TFU_TFU0_CFG_TFU0_TRD3_LOAD_Msk) /*!< TFU0_TRD3_LOAD Set Value            */
#define TFU_TFU0_CFG_TFU0_TRD3_LOAD_Get(x) (((uint32_t) (x) & TFU_TFU0_CFG_TFU0_TRD3_LOAD_Msk) >> TFU_TFU0_CFG_TFU0_TRD3_LOAD_Pos) /*!< TFU0_TRD3_LOAD Get Value            */

#define TFU_TFU0_CFG_TFU0_TRD2_LOAD_Pos    (6U)                                                                                  /*!< TFU0_TRD2_LOAD Position  6          */ 
#define TFU_TFU0_CFG_TFU0_TRD2_LOAD_Msk    (0x1U << TFU_TFU0_CFG_TFU0_TRD2_LOAD_Pos)                                             /*!< TFU0_TRD2_LOAD Mask      0x00000040 */
#define TFU_TFU0_CFG_TFU0_TRD2_LOAD_Set(x) (((uint32_t) (x) << TFU_TFU0_CFG_TFU0_TRD2_LOAD_Pos) & TFU_TFU0_CFG_TFU0_TRD2_LOAD_Msk) /*!< TFU0_TRD2_LOAD Set Value            */
#define TFU_TFU0_CFG_TFU0_TRD2_LOAD_Get(x) (((uint32_t) (x) & TFU_TFU0_CFG_TFU0_TRD2_LOAD_Msk) >> TFU_TFU0_CFG_TFU0_TRD2_LOAD_Pos) /*!< TFU0_TRD2_LOAD Get Value            */

#define TFU_TFU0_CFG_TFU0_TRD1_LOAD_Pos    (5U)                                                                                  /*!< TFU0_TRD1_LOAD Position  5          */ 
#define TFU_TFU0_CFG_TFU0_TRD1_LOAD_Msk    (0x1U << TFU_TFU0_CFG_TFU0_TRD1_LOAD_Pos)                                             /*!< TFU0_TRD1_LOAD Mask      0x00000020 */
#define TFU_TFU0_CFG_TFU0_TRD1_LOAD_Set(x) (((uint32_t) (x) << TFU_TFU0_CFG_TFU0_TRD1_LOAD_Pos) & TFU_TFU0_CFG_TFU0_TRD1_LOAD_Msk) /*!< TFU0_TRD1_LOAD Set Value            */
#define TFU_TFU0_CFG_TFU0_TRD1_LOAD_Get(x) (((uint32_t) (x) & TFU_TFU0_CFG_TFU0_TRD1_LOAD_Msk) >> TFU_TFU0_CFG_TFU0_TRD1_LOAD_Pos) /*!< TFU0_TRD1_LOAD Get Value            */

#define TFU_TFU0_CFG_TFU0_TRD0_LOAD_Pos    (4U)                                                                                  /*!< TFU0_TRD0_LOAD Position  4          */ 
#define TFU_TFU0_CFG_TFU0_TRD0_LOAD_Msk    (0x1U << TFU_TFU0_CFG_TFU0_TRD0_LOAD_Pos)                                             /*!< TFU0_TRD0_LOAD Mask      0x00000010 */
#define TFU_TFU0_CFG_TFU0_TRD0_LOAD_Set(x) (((uint32_t) (x) << TFU_TFU0_CFG_TFU0_TRD0_LOAD_Pos) & TFU_TFU0_CFG_TFU0_TRD0_LOAD_Msk) /*!< TFU0_TRD0_LOAD Set Value            */
#define TFU_TFU0_CFG_TFU0_TRD0_LOAD_Get(x) (((uint32_t) (x) & TFU_TFU0_CFG_TFU0_TRD0_LOAD_Msk) >> TFU_TFU0_CFG_TFU0_TRD0_LOAD_Pos) /*!< TFU0_TRD0_LOAD Get Value            */

#define TFU_TFU0_CFG_TFU0_TRD3_FIFO_CLR_Pos    (3U)                                                                                  /*!< TFU0_TRD3_FIFO_CLR Position  3          */ 
#define TFU_TFU0_CFG_TFU0_TRD3_FIFO_CLR_Msk    (0x1U << TFU_TFU0_CFG_TFU0_TRD3_FIFO_CLR_Pos)                                         /*!< TFU0_TRD3_FIFO_CLR Mask      0x00000008 */
#define TFU_TFU0_CFG_TFU0_TRD3_FIFO_CLR_Set(x) (((uint32_t) (x) << TFU_TFU0_CFG_TFU0_TRD3_FIFO_CLR_Pos) & TFU_TFU0_CFG_TFU0_TRD3_FIFO_CLR_Msk) /*!< TFU0_TRD3_FIFO_CLR Set Value            */
#define TFU_TFU0_CFG_TFU0_TRD3_FIFO_CLR_Get(x) (((uint32_t) (x) & TFU_TFU0_CFG_TFU0_TRD3_FIFO_CLR_Msk) >> TFU_TFU0_CFG_TFU0_TRD3_FIFO_CLR_Pos) /*!< TFU0_TRD3_FIFO_CLR Get Value            */

#define TFU_TFU0_CFG_TFU0_TRD2_FIFO_CLR_Pos    (2U)                                                                                  /*!< TFU0_TRD2_FIFO_CLR Position  2          */ 
#define TFU_TFU0_CFG_TFU0_TRD2_FIFO_CLR_Msk    (0x1U << TFU_TFU0_CFG_TFU0_TRD2_FIFO_CLR_Pos)                                         /*!< TFU0_TRD2_FIFO_CLR Mask      0x00000004 */
#define TFU_TFU0_CFG_TFU0_TRD2_FIFO_CLR_Set(x) (((uint32_t) (x) << TFU_TFU0_CFG_TFU0_TRD2_FIFO_CLR_Pos) & TFU_TFU0_CFG_TFU0_TRD2_FIFO_CLR_Msk) /*!< TFU0_TRD2_FIFO_CLR Set Value            */
#define TFU_TFU0_CFG_TFU0_TRD2_FIFO_CLR_Get(x) (((uint32_t) (x) & TFU_TFU0_CFG_TFU0_TRD2_FIFO_CLR_Msk) >> TFU_TFU0_CFG_TFU0_TRD2_FIFO_CLR_Pos) /*!< TFU0_TRD2_FIFO_CLR Get Value            */

#define TFU_TFU0_CFG_TFU0_TRD1_FIFO_CLR_Pos    (1U)                                                                                  /*!< TFU0_TRD1_FIFO_CLR Position  1          */ 
#define TFU_TFU0_CFG_TFU0_TRD1_FIFO_CLR_Msk    (0x1U << TFU_TFU0_CFG_TFU0_TRD1_FIFO_CLR_Pos)                                         /*!< TFU0_TRD1_FIFO_CLR Mask      0x00000002 */
#define TFU_TFU0_CFG_TFU0_TRD1_FIFO_CLR_Set(x) (((uint32_t) (x) << TFU_TFU0_CFG_TFU0_TRD1_FIFO_CLR_Pos) & TFU_TFU0_CFG_TFU0_TRD1_FIFO_CLR_Msk) /*!< TFU0_TRD1_FIFO_CLR Set Value            */
#define TFU_TFU0_CFG_TFU0_TRD1_FIFO_CLR_Get(x) (((uint32_t) (x) & TFU_TFU0_CFG_TFU0_TRD1_FIFO_CLR_Msk) >> TFU_TFU0_CFG_TFU0_TRD1_FIFO_CLR_Pos) /*!< TFU0_TRD1_FIFO_CLR Get Value            */

#define TFU_TFU0_CFG_TFU0_TRD0_FIFO_CLR_Pos    (0U)                                                                                  /*!< TFU0_TRD0_FIFO_CLR Position  0          */ 
#define TFU_TFU0_CFG_TFU0_TRD0_FIFO_CLR_Msk    (0x1U << TFU_TFU0_CFG_TFU0_TRD0_FIFO_CLR_Pos)                                         /*!< TFU0_TRD0_FIFO_CLR Mask      0x00000001 */
#define TFU_TFU0_CFG_TFU0_TRD0_FIFO_CLR_Set(x) (((uint32_t) (x) << TFU_TFU0_CFG_TFU0_TRD0_FIFO_CLR_Pos) & TFU_TFU0_CFG_TFU0_TRD0_FIFO_CLR_Msk) /*!< TFU0_TRD0_FIFO_CLR Set Value            */
#define TFU_TFU0_CFG_TFU0_TRD0_FIFO_CLR_Get(x) (((uint32_t) (x) & TFU_TFU0_CFG_TFU0_TRD0_FIFO_CLR_Msk) >> TFU_TFU0_CFG_TFU0_TRD0_FIFO_CLR_Pos) /*!< TFU0_TRD0_FIFO_CLR Get Value            */

/* TFU0_FIFO_WATERLEVEL bitfield */
#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD3_ARG0_WL_Pos    (28U)                                                                                 /*!< TFU0_TRD3_ARG0_WL Position  28         */ 
#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD3_ARG0_WL_Msk    (0x3U << TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD3_ARG0_WL_Pos)                              /*!< TFU0_TRD3_ARG0_WL Mask      0x30000000 */
#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD3_ARG0_WL_Set(x) (((uint32_t) (x) << TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD3_ARG0_WL_Pos) & TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD3_ARG0_WL_Msk) /*!< TFU0_TRD3_ARG0_WL Set Value            */
#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD3_ARG0_WL_Get(x) (((uint32_t) (x) & TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD3_ARG0_WL_Msk) >> TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD3_ARG0_WL_Pos) /*!< TFU0_TRD3_ARG0_WL Get Value            */

#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD3_ARG1_WL_Pos    (26U)                                                                                 /*!< TFU0_TRD3_ARG1_WL Position  26         */ 
#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD3_ARG1_WL_Msk    (0x3U << TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD3_ARG1_WL_Pos)                              /*!< TFU0_TRD3_ARG1_WL Mask      0x0C000000 */
#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD3_ARG1_WL_Set(x) (((uint32_t) (x) << TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD3_ARG1_WL_Pos) & TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD3_ARG1_WL_Msk) /*!< TFU0_TRD3_ARG1_WL Set Value            */
#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD3_ARG1_WL_Get(x) (((uint32_t) (x) & TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD3_ARG1_WL_Msk) >> TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD3_ARG1_WL_Pos) /*!< TFU0_TRD3_ARG1_WL Get Value            */

#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD3_RES_WL_Pos    (24U)                                                                                 /*!< TFU0_TRD3_RES_WL Position  24         */ 
#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD3_RES_WL_Msk    (0x3U << TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD3_RES_WL_Pos)                               /*!< TFU0_TRD3_RES_WL Mask      0x03000000 */
#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD3_RES_WL_Set(x) (((uint32_t) (x) << TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD3_RES_WL_Pos) & TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD3_RES_WL_Msk) /*!< TFU0_TRD3_RES_WL Set Value            */
#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD3_RES_WL_Get(x) (((uint32_t) (x) & TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD3_RES_WL_Msk) >> TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD3_RES_WL_Pos) /*!< TFU0_TRD3_RES_WL Get Value            */

#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD2_ARG0_WL_Pos    (22U)                                                                                 /*!< TFU0_TRD2_ARG0_WL Position  22         */ 
#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD2_ARG0_WL_Msk    (0x3U << TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD2_ARG0_WL_Pos)                              /*!< TFU0_TRD2_ARG0_WL Mask      0x00C00000 */
#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD2_ARG0_WL_Set(x) (((uint32_t) (x) << TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD2_ARG0_WL_Pos) & TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD2_ARG0_WL_Msk) /*!< TFU0_TRD2_ARG0_WL Set Value            */
#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD2_ARG0_WL_Get(x) (((uint32_t) (x) & TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD2_ARG0_WL_Msk) >> TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD2_ARG0_WL_Pos) /*!< TFU0_TRD2_ARG0_WL Get Value            */

#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD2_ARG1_WL_Pos    (20U)                                                                                 /*!< TFU0_TRD2_ARG1_WL Position  20         */ 
#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD2_ARG1_WL_Msk    (0x3U << TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD2_ARG1_WL_Pos)                              /*!< TFU0_TRD2_ARG1_WL Mask      0x00300000 */
#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD2_ARG1_WL_Set(x) (((uint32_t) (x) << TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD2_ARG1_WL_Pos) & TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD2_ARG1_WL_Msk) /*!< TFU0_TRD2_ARG1_WL Set Value            */
#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD2_ARG1_WL_Get(x) (((uint32_t) (x) & TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD2_ARG1_WL_Msk) >> TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD2_ARG1_WL_Pos) /*!< TFU0_TRD2_ARG1_WL Get Value            */

#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD2_RES_WL_Pos    (18U)                                                                                 /*!< TFU0_TRD2_RES_WL Position  18         */ 
#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD2_RES_WL_Msk    (0x3U << TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD2_RES_WL_Pos)                               /*!< TFU0_TRD2_RES_WL Mask      0x000C0000 */
#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD2_RES_WL_Set(x) (((uint32_t) (x) << TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD2_RES_WL_Pos) & TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD2_RES_WL_Msk) /*!< TFU0_TRD2_RES_WL Set Value            */
#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD2_RES_WL_Get(x) (((uint32_t) (x) & TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD2_RES_WL_Msk) >> TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD2_RES_WL_Pos) /*!< TFU0_TRD2_RES_WL Get Value            */

#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD1_ARG0_WL_Pos    (16U)                                                                                 /*!< TFU0_TRD1_ARG0_WL Position  16         */ 
#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD1_ARG0_WL_Msk    (0x3U << TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD1_ARG0_WL_Pos)                              /*!< TFU0_TRD1_ARG0_WL Mask      0x00030000 */
#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD1_ARG0_WL_Set(x) (((uint32_t) (x) << TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD1_ARG0_WL_Pos) & TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD1_ARG0_WL_Msk) /*!< TFU0_TRD1_ARG0_WL Set Value            */
#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD1_ARG0_WL_Get(x) (((uint32_t) (x) & TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD1_ARG0_WL_Msk) >> TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD1_ARG0_WL_Pos) /*!< TFU0_TRD1_ARG0_WL Get Value            */

#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD1_ARG1_WL_Pos    (14U)                                                                                 /*!< TFU0_TRD1_ARG1_WL Position  14         */ 
#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD1_ARG1_WL_Msk    (0x3U << TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD1_ARG1_WL_Pos)                              /*!< TFU0_TRD1_ARG1_WL Mask      0x0000C000 */
#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD1_ARG1_WL_Set(x) (((uint32_t) (x) << TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD1_ARG1_WL_Pos) & TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD1_ARG1_WL_Msk) /*!< TFU0_TRD1_ARG1_WL Set Value            */
#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD1_ARG1_WL_Get(x) (((uint32_t) (x) & TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD1_ARG1_WL_Msk) >> TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD1_ARG1_WL_Pos) /*!< TFU0_TRD1_ARG1_WL Get Value            */

#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD1_RES_WL_Pos    (12U)                                                                                 /*!< TFU0_TRD1_RES_WL Position  12         */ 
#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD1_RES_WL_Msk    (0x3U << TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD1_RES_WL_Pos)                               /*!< TFU0_TRD1_RES_WL Mask      0x00003000 */
#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD1_RES_WL_Set(x) (((uint32_t) (x) << TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD1_RES_WL_Pos) & TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD1_RES_WL_Msk) /*!< TFU0_TRD1_RES_WL Set Value            */
#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD1_RES_WL_Get(x) (((uint32_t) (x) & TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD1_RES_WL_Msk) >> TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD1_RES_WL_Pos) /*!< TFU0_TRD1_RES_WL Get Value            */

#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD0_ARG0_WL_Pos    (8U)                                                                                  /*!< TFU0_TRD0_ARG0_WL Position  8          */ 
#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD0_ARG0_WL_Msk    (0xfU << TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD0_ARG0_WL_Pos)                              /*!< TFU0_TRD0_ARG0_WL Mask      0x00000F00 */
#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD0_ARG0_WL_Set(x) (((uint32_t) (x) << TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD0_ARG0_WL_Pos) & TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD0_ARG0_WL_Msk) /*!< TFU0_TRD0_ARG0_WL Set Value            */
#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD0_ARG0_WL_Get(x) (((uint32_t) (x) & TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD0_ARG0_WL_Msk) >> TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD0_ARG0_WL_Pos) /*!< TFU0_TRD0_ARG0_WL Get Value            */

#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD0_ARG1_WL_Pos    (4U)                                                                                  /*!< TFU0_TRD0_ARG1_WL Position  4          */ 
#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD0_ARG1_WL_Msk    (0xfU << TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD0_ARG1_WL_Pos)                              /*!< TFU0_TRD0_ARG1_WL Mask      0x000000F0 */
#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD0_ARG1_WL_Set(x) (((uint32_t) (x) << TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD0_ARG1_WL_Pos) & TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD0_ARG1_WL_Msk) /*!< TFU0_TRD0_ARG1_WL Set Value            */
#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD0_ARG1_WL_Get(x) (((uint32_t) (x) & TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD0_ARG1_WL_Msk) >> TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD0_ARG1_WL_Pos) /*!< TFU0_TRD0_ARG1_WL Get Value            */

#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD0_RES_WL_Pos    (0U)                                                                                  /*!< TFU0_TRD0_RES_WL Position  0          */ 
#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD0_RES_WL_Msk    (0xfU << TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD0_RES_WL_Pos)                               /*!< TFU0_TRD0_RES_WL Mask      0x0000000F */
#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD0_RES_WL_Set(x) (((uint32_t) (x) << TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD0_RES_WL_Pos) & TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD0_RES_WL_Msk) /*!< TFU0_TRD0_RES_WL Set Value            */
#define TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD0_RES_WL_Get(x) (((uint32_t) (x) & TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD0_RES_WL_Msk) >> TFU_TFU0_FIFO_WATERLEVEL_TFU0_TRD0_RES_WL_Pos) /*!< TFU0_TRD0_RES_WL Get Value            */

/* TFU0_LOGEXP_LUTP01 bitfield */
#define TFU_TFU0_LOGEXP_LUTP01_TFU0_LOGEXP_LUTP01_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTP01 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTP01_TFU0_LOGEXP_LUTP01_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTP01_TFU0_LOGEXP_LUTP01_Pos)                        /*!< TFU0_LOGEXP_LUTP01 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTP01_TFU0_LOGEXP_LUTP01_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTP01_TFU0_LOGEXP_LUTP01_Pos) & TFU_TFU0_LOGEXP_LUTP01_TFU0_LOGEXP_LUTP01_Msk) /*!< TFU0_LOGEXP_LUTP01 Set Value            */
#define TFU_TFU0_LOGEXP_LUTP01_TFU0_LOGEXP_LUTP01_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTP01_TFU0_LOGEXP_LUTP01_Msk) >> TFU_TFU0_LOGEXP_LUTP01_TFU0_LOGEXP_LUTP01_Pos) /*!< TFU0_LOGEXP_LUTP01 Get Value            */

/* TFU0_LOGEXP_LUTP02 bitfield */
#define TFU_TFU0_LOGEXP_LUTP02_TFU0_LOGEXP_LUTP02_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTP02 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTP02_TFU0_LOGEXP_LUTP02_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTP02_TFU0_LOGEXP_LUTP02_Pos)                        /*!< TFU0_LOGEXP_LUTP02 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTP02_TFU0_LOGEXP_LUTP02_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTP02_TFU0_LOGEXP_LUTP02_Pos) & TFU_TFU0_LOGEXP_LUTP02_TFU0_LOGEXP_LUTP02_Msk) /*!< TFU0_LOGEXP_LUTP02 Set Value            */
#define TFU_TFU0_LOGEXP_LUTP02_TFU0_LOGEXP_LUTP02_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTP02_TFU0_LOGEXP_LUTP02_Msk) >> TFU_TFU0_LOGEXP_LUTP02_TFU0_LOGEXP_LUTP02_Pos) /*!< TFU0_LOGEXP_LUTP02 Get Value            */

/* TFU0_LOGEXP_LUTP03 bitfield */
#define TFU_TFU0_LOGEXP_LUTP03_TFU0_LOGEXP_LUTP03_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTP03 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTP03_TFU0_LOGEXP_LUTP03_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTP03_TFU0_LOGEXP_LUTP03_Pos)                        /*!< TFU0_LOGEXP_LUTP03 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTP03_TFU0_LOGEXP_LUTP03_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTP03_TFU0_LOGEXP_LUTP03_Pos) & TFU_TFU0_LOGEXP_LUTP03_TFU0_LOGEXP_LUTP03_Msk) /*!< TFU0_LOGEXP_LUTP03 Set Value            */
#define TFU_TFU0_LOGEXP_LUTP03_TFU0_LOGEXP_LUTP03_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTP03_TFU0_LOGEXP_LUTP03_Msk) >> TFU_TFU0_LOGEXP_LUTP03_TFU0_LOGEXP_LUTP03_Pos) /*!< TFU0_LOGEXP_LUTP03 Get Value            */

/* TFU0_LOGEXP_LUTP04 bitfield */
#define TFU_TFU0_LOGEXP_LUTP04_TFU0_LOGEXP_LUTP04_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTP04 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTP04_TFU0_LOGEXP_LUTP04_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTP04_TFU0_LOGEXP_LUTP04_Pos)                        /*!< TFU0_LOGEXP_LUTP04 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTP04_TFU0_LOGEXP_LUTP04_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTP04_TFU0_LOGEXP_LUTP04_Pos) & TFU_TFU0_LOGEXP_LUTP04_TFU0_LOGEXP_LUTP04_Msk) /*!< TFU0_LOGEXP_LUTP04 Set Value            */
#define TFU_TFU0_LOGEXP_LUTP04_TFU0_LOGEXP_LUTP04_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTP04_TFU0_LOGEXP_LUTP04_Msk) >> TFU_TFU0_LOGEXP_LUTP04_TFU0_LOGEXP_LUTP04_Pos) /*!< TFU0_LOGEXP_LUTP04 Get Value            */

/* TFU0_LOGEXP_LUTP05 bitfield */
#define TFU_TFU0_LOGEXP_LUTP05_TFU0_LOGEXP_LUTP05_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTP05 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTP05_TFU0_LOGEXP_LUTP05_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTP05_TFU0_LOGEXP_LUTP05_Pos)                        /*!< TFU0_LOGEXP_LUTP05 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTP05_TFU0_LOGEXP_LUTP05_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTP05_TFU0_LOGEXP_LUTP05_Pos) & TFU_TFU0_LOGEXP_LUTP05_TFU0_LOGEXP_LUTP05_Msk) /*!< TFU0_LOGEXP_LUTP05 Set Value            */
#define TFU_TFU0_LOGEXP_LUTP05_TFU0_LOGEXP_LUTP05_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTP05_TFU0_LOGEXP_LUTP05_Msk) >> TFU_TFU0_LOGEXP_LUTP05_TFU0_LOGEXP_LUTP05_Pos) /*!< TFU0_LOGEXP_LUTP05 Get Value            */

/* TFU0_LOGEXP_LUTP06 bitfield */
#define TFU_TFU0_LOGEXP_LUTP06_TFU0_LOGEXP_LUTP06_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTP06 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTP06_TFU0_LOGEXP_LUTP06_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTP06_TFU0_LOGEXP_LUTP06_Pos)                        /*!< TFU0_LOGEXP_LUTP06 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTP06_TFU0_LOGEXP_LUTP06_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTP06_TFU0_LOGEXP_LUTP06_Pos) & TFU_TFU0_LOGEXP_LUTP06_TFU0_LOGEXP_LUTP06_Msk) /*!< TFU0_LOGEXP_LUTP06 Set Value            */
#define TFU_TFU0_LOGEXP_LUTP06_TFU0_LOGEXP_LUTP06_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTP06_TFU0_LOGEXP_LUTP06_Msk) >> TFU_TFU0_LOGEXP_LUTP06_TFU0_LOGEXP_LUTP06_Pos) /*!< TFU0_LOGEXP_LUTP06 Get Value            */

/* TFU0_LOGEXP_LUTP07 bitfield */
#define TFU_TFU0_LOGEXP_LUTP07_TFU0_LOGEXP_LUTP07_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTP07 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTP07_TFU0_LOGEXP_LUTP07_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTP07_TFU0_LOGEXP_LUTP07_Pos)                        /*!< TFU0_LOGEXP_LUTP07 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTP07_TFU0_LOGEXP_LUTP07_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTP07_TFU0_LOGEXP_LUTP07_Pos) & TFU_TFU0_LOGEXP_LUTP07_TFU0_LOGEXP_LUTP07_Msk) /*!< TFU0_LOGEXP_LUTP07 Set Value            */
#define TFU_TFU0_LOGEXP_LUTP07_TFU0_LOGEXP_LUTP07_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTP07_TFU0_LOGEXP_LUTP07_Msk) >> TFU_TFU0_LOGEXP_LUTP07_TFU0_LOGEXP_LUTP07_Pos) /*!< TFU0_LOGEXP_LUTP07 Get Value            */

/* TFU0_LOGEXP_LUTP08 bitfield */
#define TFU_TFU0_LOGEXP_LUTP08_TFU0_LOGEXP_LUTP08_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTP08 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTP08_TFU0_LOGEXP_LUTP08_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTP08_TFU0_LOGEXP_LUTP08_Pos)                        /*!< TFU0_LOGEXP_LUTP08 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTP08_TFU0_LOGEXP_LUTP08_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTP08_TFU0_LOGEXP_LUTP08_Pos) & TFU_TFU0_LOGEXP_LUTP08_TFU0_LOGEXP_LUTP08_Msk) /*!< TFU0_LOGEXP_LUTP08 Set Value            */
#define TFU_TFU0_LOGEXP_LUTP08_TFU0_LOGEXP_LUTP08_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTP08_TFU0_LOGEXP_LUTP08_Msk) >> TFU_TFU0_LOGEXP_LUTP08_TFU0_LOGEXP_LUTP08_Pos) /*!< TFU0_LOGEXP_LUTP08 Get Value            */

/* TFU0_LOGEXP_LUTP09 bitfield */
#define TFU_TFU0_LOGEXP_LUTP09_TFU0_LOGEXP_LUTP09_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTP09 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTP09_TFU0_LOGEXP_LUTP09_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTP09_TFU0_LOGEXP_LUTP09_Pos)                        /*!< TFU0_LOGEXP_LUTP09 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTP09_TFU0_LOGEXP_LUTP09_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTP09_TFU0_LOGEXP_LUTP09_Pos) & TFU_TFU0_LOGEXP_LUTP09_TFU0_LOGEXP_LUTP09_Msk) /*!< TFU0_LOGEXP_LUTP09 Set Value            */
#define TFU_TFU0_LOGEXP_LUTP09_TFU0_LOGEXP_LUTP09_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTP09_TFU0_LOGEXP_LUTP09_Msk) >> TFU_TFU0_LOGEXP_LUTP09_TFU0_LOGEXP_LUTP09_Pos) /*!< TFU0_LOGEXP_LUTP09 Get Value            */

/* TFU0_LOGEXP_LUTP10 bitfield */
#define TFU_TFU0_LOGEXP_LUTP10_TFU0_LOGEXP_LUTP10_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTP10 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTP10_TFU0_LOGEXP_LUTP10_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTP10_TFU0_LOGEXP_LUTP10_Pos)                        /*!< TFU0_LOGEXP_LUTP10 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTP10_TFU0_LOGEXP_LUTP10_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTP10_TFU0_LOGEXP_LUTP10_Pos) & TFU_TFU0_LOGEXP_LUTP10_TFU0_LOGEXP_LUTP10_Msk) /*!< TFU0_LOGEXP_LUTP10 Set Value            */
#define TFU_TFU0_LOGEXP_LUTP10_TFU0_LOGEXP_LUTP10_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTP10_TFU0_LOGEXP_LUTP10_Msk) >> TFU_TFU0_LOGEXP_LUTP10_TFU0_LOGEXP_LUTP10_Pos) /*!< TFU0_LOGEXP_LUTP10 Get Value            */

/* TFU0_LOGEXP_LUTP11 bitfield */
#define TFU_TFU0_LOGEXP_LUTP11_TFU0_LOGEXP_LUTP11_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTP11 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTP11_TFU0_LOGEXP_LUTP11_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTP11_TFU0_LOGEXP_LUTP11_Pos)                        /*!< TFU0_LOGEXP_LUTP11 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTP11_TFU0_LOGEXP_LUTP11_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTP11_TFU0_LOGEXP_LUTP11_Pos) & TFU_TFU0_LOGEXP_LUTP11_TFU0_LOGEXP_LUTP11_Msk) /*!< TFU0_LOGEXP_LUTP11 Set Value            */
#define TFU_TFU0_LOGEXP_LUTP11_TFU0_LOGEXP_LUTP11_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTP11_TFU0_LOGEXP_LUTP11_Msk) >> TFU_TFU0_LOGEXP_LUTP11_TFU0_LOGEXP_LUTP11_Pos) /*!< TFU0_LOGEXP_LUTP11 Get Value            */

/* TFU0_LOGEXP_LUTP12 bitfield */
#define TFU_TFU0_LOGEXP_LUTP12_TFU0_LOGEXP_LUTP12_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTP12 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTP12_TFU0_LOGEXP_LUTP12_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTP12_TFU0_LOGEXP_LUTP12_Pos)                        /*!< TFU0_LOGEXP_LUTP12 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTP12_TFU0_LOGEXP_LUTP12_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTP12_TFU0_LOGEXP_LUTP12_Pos) & TFU_TFU0_LOGEXP_LUTP12_TFU0_LOGEXP_LUTP12_Msk) /*!< TFU0_LOGEXP_LUTP12 Set Value            */
#define TFU_TFU0_LOGEXP_LUTP12_TFU0_LOGEXP_LUTP12_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTP12_TFU0_LOGEXP_LUTP12_Msk) >> TFU_TFU0_LOGEXP_LUTP12_TFU0_LOGEXP_LUTP12_Pos) /*!< TFU0_LOGEXP_LUTP12 Get Value            */

/* TFU0_LOGEXP_LUTP13 bitfield */
#define TFU_TFU0_LOGEXP_LUTP13_TFU0_LOGEXP_LUTP13_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTP13 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTP13_TFU0_LOGEXP_LUTP13_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTP13_TFU0_LOGEXP_LUTP13_Pos)                        /*!< TFU0_LOGEXP_LUTP13 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTP13_TFU0_LOGEXP_LUTP13_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTP13_TFU0_LOGEXP_LUTP13_Pos) & TFU_TFU0_LOGEXP_LUTP13_TFU0_LOGEXP_LUTP13_Msk) /*!< TFU0_LOGEXP_LUTP13 Set Value            */
#define TFU_TFU0_LOGEXP_LUTP13_TFU0_LOGEXP_LUTP13_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTP13_TFU0_LOGEXP_LUTP13_Msk) >> TFU_TFU0_LOGEXP_LUTP13_TFU0_LOGEXP_LUTP13_Pos) /*!< TFU0_LOGEXP_LUTP13 Get Value            */

/* TFU0_LOGEXP_LUTP14 bitfield */
#define TFU_TFU0_LOGEXP_LUTP14_TFU0_LOGEXP_LUTP14_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTP14 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTP14_TFU0_LOGEXP_LUTP14_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTP14_TFU0_LOGEXP_LUTP14_Pos)                        /*!< TFU0_LOGEXP_LUTP14 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTP14_TFU0_LOGEXP_LUTP14_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTP14_TFU0_LOGEXP_LUTP14_Pos) & TFU_TFU0_LOGEXP_LUTP14_TFU0_LOGEXP_LUTP14_Msk) /*!< TFU0_LOGEXP_LUTP14 Set Value            */
#define TFU_TFU0_LOGEXP_LUTP14_TFU0_LOGEXP_LUTP14_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTP14_TFU0_LOGEXP_LUTP14_Msk) >> TFU_TFU0_LOGEXP_LUTP14_TFU0_LOGEXP_LUTP14_Pos) /*!< TFU0_LOGEXP_LUTP14 Get Value            */

/* TFU0_LOGEXP_LUTP15 bitfield */
#define TFU_TFU0_LOGEXP_LUTP15_TFU0_LOGEXP_LUTP15_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTP15 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTP15_TFU0_LOGEXP_LUTP15_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTP15_TFU0_LOGEXP_LUTP15_Pos)                        /*!< TFU0_LOGEXP_LUTP15 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTP15_TFU0_LOGEXP_LUTP15_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTP15_TFU0_LOGEXP_LUTP15_Pos) & TFU_TFU0_LOGEXP_LUTP15_TFU0_LOGEXP_LUTP15_Msk) /*!< TFU0_LOGEXP_LUTP15 Set Value            */
#define TFU_TFU0_LOGEXP_LUTP15_TFU0_LOGEXP_LUTP15_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTP15_TFU0_LOGEXP_LUTP15_Msk) >> TFU_TFU0_LOGEXP_LUTP15_TFU0_LOGEXP_LUTP15_Pos) /*!< TFU0_LOGEXP_LUTP15 Get Value            */

/* TFU0_LOGEXP_LUTP16 bitfield */
#define TFU_TFU0_LOGEXP_LUTP16_TFU0_LOGEXP_LUTP16_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTP16 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTP16_TFU0_LOGEXP_LUTP16_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTP16_TFU0_LOGEXP_LUTP16_Pos)                        /*!< TFU0_LOGEXP_LUTP16 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTP16_TFU0_LOGEXP_LUTP16_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTP16_TFU0_LOGEXP_LUTP16_Pos) & TFU_TFU0_LOGEXP_LUTP16_TFU0_LOGEXP_LUTP16_Msk) /*!< TFU0_LOGEXP_LUTP16 Set Value            */
#define TFU_TFU0_LOGEXP_LUTP16_TFU0_LOGEXP_LUTP16_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTP16_TFU0_LOGEXP_LUTP16_Msk) >> TFU_TFU0_LOGEXP_LUTP16_TFU0_LOGEXP_LUTP16_Pos) /*!< TFU0_LOGEXP_LUTP16 Get Value            */

/* TFU0_LOGEXP_LUTP17 bitfield */
#define TFU_TFU0_LOGEXP_LUTP17_TFU0_LOGEXP_LUTP17_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTP17 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTP17_TFU0_LOGEXP_LUTP17_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTP17_TFU0_LOGEXP_LUTP17_Pos)                        /*!< TFU0_LOGEXP_LUTP17 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTP17_TFU0_LOGEXP_LUTP17_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTP17_TFU0_LOGEXP_LUTP17_Pos) & TFU_TFU0_LOGEXP_LUTP17_TFU0_LOGEXP_LUTP17_Msk) /*!< TFU0_LOGEXP_LUTP17 Set Value            */
#define TFU_TFU0_LOGEXP_LUTP17_TFU0_LOGEXP_LUTP17_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTP17_TFU0_LOGEXP_LUTP17_Msk) >> TFU_TFU0_LOGEXP_LUTP17_TFU0_LOGEXP_LUTP17_Pos) /*!< TFU0_LOGEXP_LUTP17 Get Value            */

/* TFU0_LOGEXP_LUTP18 bitfield */
#define TFU_TFU0_LOGEXP_LUTP18_TFU0_LOGEXP_LUTP18_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTP18 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTP18_TFU0_LOGEXP_LUTP18_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTP18_TFU0_LOGEXP_LUTP18_Pos)                        /*!< TFU0_LOGEXP_LUTP18 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTP18_TFU0_LOGEXP_LUTP18_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTP18_TFU0_LOGEXP_LUTP18_Pos) & TFU_TFU0_LOGEXP_LUTP18_TFU0_LOGEXP_LUTP18_Msk) /*!< TFU0_LOGEXP_LUTP18 Set Value            */
#define TFU_TFU0_LOGEXP_LUTP18_TFU0_LOGEXP_LUTP18_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTP18_TFU0_LOGEXP_LUTP18_Msk) >> TFU_TFU0_LOGEXP_LUTP18_TFU0_LOGEXP_LUTP18_Pos) /*!< TFU0_LOGEXP_LUTP18 Get Value            */

/* TFU0_LOGEXP_LUTP19 bitfield */
#define TFU_TFU0_LOGEXP_LUTP19_TFU0_LOGEXP_LUTP19_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTP19 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTP19_TFU0_LOGEXP_LUTP19_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTP19_TFU0_LOGEXP_LUTP19_Pos)                        /*!< TFU0_LOGEXP_LUTP19 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTP19_TFU0_LOGEXP_LUTP19_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTP19_TFU0_LOGEXP_LUTP19_Pos) & TFU_TFU0_LOGEXP_LUTP19_TFU0_LOGEXP_LUTP19_Msk) /*!< TFU0_LOGEXP_LUTP19 Set Value            */
#define TFU_TFU0_LOGEXP_LUTP19_TFU0_LOGEXP_LUTP19_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTP19_TFU0_LOGEXP_LUTP19_Msk) >> TFU_TFU0_LOGEXP_LUTP19_TFU0_LOGEXP_LUTP19_Pos) /*!< TFU0_LOGEXP_LUTP19 Get Value            */

/* TFU0_LOGEXP_LUTP20 bitfield */
#define TFU_TFU0_LOGEXP_LUTP20_TFU0_LOGEXP_LUTP20_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTP20 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTP20_TFU0_LOGEXP_LUTP20_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTP20_TFU0_LOGEXP_LUTP20_Pos)                        /*!< TFU0_LOGEXP_LUTP20 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTP20_TFU0_LOGEXP_LUTP20_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTP20_TFU0_LOGEXP_LUTP20_Pos) & TFU_TFU0_LOGEXP_LUTP20_TFU0_LOGEXP_LUTP20_Msk) /*!< TFU0_LOGEXP_LUTP20 Set Value            */
#define TFU_TFU0_LOGEXP_LUTP20_TFU0_LOGEXP_LUTP20_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTP20_TFU0_LOGEXP_LUTP20_Msk) >> TFU_TFU0_LOGEXP_LUTP20_TFU0_LOGEXP_LUTP20_Pos) /*!< TFU0_LOGEXP_LUTP20 Get Value            */

/* TFU0_LOGEXP_LUTP21 bitfield */
#define TFU_TFU0_LOGEXP_LUTP21_TFU0_LOGEXP_LUTP21_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTP21 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTP21_TFU0_LOGEXP_LUTP21_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTP21_TFU0_LOGEXP_LUTP21_Pos)                        /*!< TFU0_LOGEXP_LUTP21 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTP21_TFU0_LOGEXP_LUTP21_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTP21_TFU0_LOGEXP_LUTP21_Pos) & TFU_TFU0_LOGEXP_LUTP21_TFU0_LOGEXP_LUTP21_Msk) /*!< TFU0_LOGEXP_LUTP21 Set Value            */
#define TFU_TFU0_LOGEXP_LUTP21_TFU0_LOGEXP_LUTP21_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTP21_TFU0_LOGEXP_LUTP21_Msk) >> TFU_TFU0_LOGEXP_LUTP21_TFU0_LOGEXP_LUTP21_Pos) /*!< TFU0_LOGEXP_LUTP21 Get Value            */

/* TFU0_LOGEXP_LUTP22 bitfield */
#define TFU_TFU0_LOGEXP_LUTP22_TFU0_LOGEXP_LUTP22_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTP22 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTP22_TFU0_LOGEXP_LUTP22_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTP22_TFU0_LOGEXP_LUTP22_Pos)                        /*!< TFU0_LOGEXP_LUTP22 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTP22_TFU0_LOGEXP_LUTP22_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTP22_TFU0_LOGEXP_LUTP22_Pos) & TFU_TFU0_LOGEXP_LUTP22_TFU0_LOGEXP_LUTP22_Msk) /*!< TFU0_LOGEXP_LUTP22 Set Value            */
#define TFU_TFU0_LOGEXP_LUTP22_TFU0_LOGEXP_LUTP22_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTP22_TFU0_LOGEXP_LUTP22_Msk) >> TFU_TFU0_LOGEXP_LUTP22_TFU0_LOGEXP_LUTP22_Pos) /*!< TFU0_LOGEXP_LUTP22 Get Value            */

/* TFU0_LOGEXP_LUTP23 bitfield */
#define TFU_TFU0_LOGEXP_LUTP23_TFU0_LOGEXP_LUTP23_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTP23 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTP23_TFU0_LOGEXP_LUTP23_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTP23_TFU0_LOGEXP_LUTP23_Pos)                        /*!< TFU0_LOGEXP_LUTP23 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTP23_TFU0_LOGEXP_LUTP23_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTP23_TFU0_LOGEXP_LUTP23_Pos) & TFU_TFU0_LOGEXP_LUTP23_TFU0_LOGEXP_LUTP23_Msk) /*!< TFU0_LOGEXP_LUTP23 Set Value            */
#define TFU_TFU0_LOGEXP_LUTP23_TFU0_LOGEXP_LUTP23_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTP23_TFU0_LOGEXP_LUTP23_Msk) >> TFU_TFU0_LOGEXP_LUTP23_TFU0_LOGEXP_LUTP23_Pos) /*!< TFU0_LOGEXP_LUTP23 Get Value            */

/* TFU0_LOGEXP_LUTP24 bitfield */
#define TFU_TFU0_LOGEXP_LUTP24_TFU0_LOGEXP_LUTP24_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTP24 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTP24_TFU0_LOGEXP_LUTP24_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTP24_TFU0_LOGEXP_LUTP24_Pos)                        /*!< TFU0_LOGEXP_LUTP24 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTP24_TFU0_LOGEXP_LUTP24_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTP24_TFU0_LOGEXP_LUTP24_Pos) & TFU_TFU0_LOGEXP_LUTP24_TFU0_LOGEXP_LUTP24_Msk) /*!< TFU0_LOGEXP_LUTP24 Set Value            */
#define TFU_TFU0_LOGEXP_LUTP24_TFU0_LOGEXP_LUTP24_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTP24_TFU0_LOGEXP_LUTP24_Msk) >> TFU_TFU0_LOGEXP_LUTP24_TFU0_LOGEXP_LUTP24_Pos) /*!< TFU0_LOGEXP_LUTP24 Get Value            */

/* TFU0_LOGEXP_LUTM01 bitfield */
#define TFU_TFU0_LOGEXP_LUTM01_TFU0_LOGEXP_LUTM01_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTM01 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTM01_TFU0_LOGEXP_LUTM01_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTM01_TFU0_LOGEXP_LUTM01_Pos)                        /*!< TFU0_LOGEXP_LUTM01 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTM01_TFU0_LOGEXP_LUTM01_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTM01_TFU0_LOGEXP_LUTM01_Pos) & TFU_TFU0_LOGEXP_LUTM01_TFU0_LOGEXP_LUTM01_Msk) /*!< TFU0_LOGEXP_LUTM01 Set Value            */
#define TFU_TFU0_LOGEXP_LUTM01_TFU0_LOGEXP_LUTM01_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTM01_TFU0_LOGEXP_LUTM01_Msk) >> TFU_TFU0_LOGEXP_LUTM01_TFU0_LOGEXP_LUTM01_Pos) /*!< TFU0_LOGEXP_LUTM01 Get Value            */

/* TFU0_LOGEXP_LUTM02 bitfield */
#define TFU_TFU0_LOGEXP_LUTM02_TFU0_LOGEXP_LUTM02_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTM02 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTM02_TFU0_LOGEXP_LUTM02_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTM02_TFU0_LOGEXP_LUTM02_Pos)                        /*!< TFU0_LOGEXP_LUTM02 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTM02_TFU0_LOGEXP_LUTM02_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTM02_TFU0_LOGEXP_LUTM02_Pos) & TFU_TFU0_LOGEXP_LUTM02_TFU0_LOGEXP_LUTM02_Msk) /*!< TFU0_LOGEXP_LUTM02 Set Value            */
#define TFU_TFU0_LOGEXP_LUTM02_TFU0_LOGEXP_LUTM02_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTM02_TFU0_LOGEXP_LUTM02_Msk) >> TFU_TFU0_LOGEXP_LUTM02_TFU0_LOGEXP_LUTM02_Pos) /*!< TFU0_LOGEXP_LUTM02 Get Value            */

/* TFU0_LOGEXP_LUTM03 bitfield */
#define TFU_TFU0_LOGEXP_LUTM03_TFU0_LOGEXP_LUTM03_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTM03 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTM03_TFU0_LOGEXP_LUTM03_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTM03_TFU0_LOGEXP_LUTM03_Pos)                        /*!< TFU0_LOGEXP_LUTM03 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTM03_TFU0_LOGEXP_LUTM03_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTM03_TFU0_LOGEXP_LUTM03_Pos) & TFU_TFU0_LOGEXP_LUTM03_TFU0_LOGEXP_LUTM03_Msk) /*!< TFU0_LOGEXP_LUTM03 Set Value            */
#define TFU_TFU0_LOGEXP_LUTM03_TFU0_LOGEXP_LUTM03_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTM03_TFU0_LOGEXP_LUTM03_Msk) >> TFU_TFU0_LOGEXP_LUTM03_TFU0_LOGEXP_LUTM03_Pos) /*!< TFU0_LOGEXP_LUTM03 Get Value            */

/* TFU0_LOGEXP_LUTM04 bitfield */
#define TFU_TFU0_LOGEXP_LUTM04_TFU0_LOGEXP_LUTM04_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTM04 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTM04_TFU0_LOGEXP_LUTM04_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTM04_TFU0_LOGEXP_LUTM04_Pos)                        /*!< TFU0_LOGEXP_LUTM04 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTM04_TFU0_LOGEXP_LUTM04_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTM04_TFU0_LOGEXP_LUTM04_Pos) & TFU_TFU0_LOGEXP_LUTM04_TFU0_LOGEXP_LUTM04_Msk) /*!< TFU0_LOGEXP_LUTM04 Set Value            */
#define TFU_TFU0_LOGEXP_LUTM04_TFU0_LOGEXP_LUTM04_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTM04_TFU0_LOGEXP_LUTM04_Msk) >> TFU_TFU0_LOGEXP_LUTM04_TFU0_LOGEXP_LUTM04_Pos) /*!< TFU0_LOGEXP_LUTM04 Get Value            */

/* TFU0_LOGEXP_LUTM05 bitfield */
#define TFU_TFU0_LOGEXP_LUTM05_TFU0_LOGEXP_LUTM05_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTM05 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTM05_TFU0_LOGEXP_LUTM05_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTM05_TFU0_LOGEXP_LUTM05_Pos)                        /*!< TFU0_LOGEXP_LUTM05 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTM05_TFU0_LOGEXP_LUTM05_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTM05_TFU0_LOGEXP_LUTM05_Pos) & TFU_TFU0_LOGEXP_LUTM05_TFU0_LOGEXP_LUTM05_Msk) /*!< TFU0_LOGEXP_LUTM05 Set Value            */
#define TFU_TFU0_LOGEXP_LUTM05_TFU0_LOGEXP_LUTM05_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTM05_TFU0_LOGEXP_LUTM05_Msk) >> TFU_TFU0_LOGEXP_LUTM05_TFU0_LOGEXP_LUTM05_Pos) /*!< TFU0_LOGEXP_LUTM05 Get Value            */

/* TFU0_LOGEXP_LUTM06 bitfield */
#define TFU_TFU0_LOGEXP_LUTM06_TFU0_LOGEXP_LUTM06_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTM06 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTM06_TFU0_LOGEXP_LUTM06_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTM06_TFU0_LOGEXP_LUTM06_Pos)                        /*!< TFU0_LOGEXP_LUTM06 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTM06_TFU0_LOGEXP_LUTM06_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTM06_TFU0_LOGEXP_LUTM06_Pos) & TFU_TFU0_LOGEXP_LUTM06_TFU0_LOGEXP_LUTM06_Msk) /*!< TFU0_LOGEXP_LUTM06 Set Value            */
#define TFU_TFU0_LOGEXP_LUTM06_TFU0_LOGEXP_LUTM06_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTM06_TFU0_LOGEXP_LUTM06_Msk) >> TFU_TFU0_LOGEXP_LUTM06_TFU0_LOGEXP_LUTM06_Pos) /*!< TFU0_LOGEXP_LUTM06 Get Value            */

/* TFU0_LOGEXP_LUTM07 bitfield */
#define TFU_TFU0_LOGEXP_LUTM07_TFU0_LOGEXP_LUTM07_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTM07 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTM07_TFU0_LOGEXP_LUTM07_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTM07_TFU0_LOGEXP_LUTM07_Pos)                        /*!< TFU0_LOGEXP_LUTM07 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTM07_TFU0_LOGEXP_LUTM07_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTM07_TFU0_LOGEXP_LUTM07_Pos) & TFU_TFU0_LOGEXP_LUTM07_TFU0_LOGEXP_LUTM07_Msk) /*!< TFU0_LOGEXP_LUTM07 Set Value            */
#define TFU_TFU0_LOGEXP_LUTM07_TFU0_LOGEXP_LUTM07_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTM07_TFU0_LOGEXP_LUTM07_Msk) >> TFU_TFU0_LOGEXP_LUTM07_TFU0_LOGEXP_LUTM07_Pos) /*!< TFU0_LOGEXP_LUTM07 Get Value            */

/* TFU0_LOGEXP_LUTM08 bitfield */
#define TFU_TFU0_LOGEXP_LUTM08_TFU0_LOGEXP_LUTM08_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTM08 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTM08_TFU0_LOGEXP_LUTM08_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTM08_TFU0_LOGEXP_LUTM08_Pos)                        /*!< TFU0_LOGEXP_LUTM08 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTM08_TFU0_LOGEXP_LUTM08_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTM08_TFU0_LOGEXP_LUTM08_Pos) & TFU_TFU0_LOGEXP_LUTM08_TFU0_LOGEXP_LUTM08_Msk) /*!< TFU0_LOGEXP_LUTM08 Set Value            */
#define TFU_TFU0_LOGEXP_LUTM08_TFU0_LOGEXP_LUTM08_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTM08_TFU0_LOGEXP_LUTM08_Msk) >> TFU_TFU0_LOGEXP_LUTM08_TFU0_LOGEXP_LUTM08_Pos) /*!< TFU0_LOGEXP_LUTM08 Get Value            */

/* TFU0_LOGEXP_LUTM09 bitfield */
#define TFU_TFU0_LOGEXP_LUTM09_TFU0_LOGEXP_LUTM09_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTM09 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTM09_TFU0_LOGEXP_LUTM09_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTM09_TFU0_LOGEXP_LUTM09_Pos)                        /*!< TFU0_LOGEXP_LUTM09 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTM09_TFU0_LOGEXP_LUTM09_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTM09_TFU0_LOGEXP_LUTM09_Pos) & TFU_TFU0_LOGEXP_LUTM09_TFU0_LOGEXP_LUTM09_Msk) /*!< TFU0_LOGEXP_LUTM09 Set Value            */
#define TFU_TFU0_LOGEXP_LUTM09_TFU0_LOGEXP_LUTM09_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTM09_TFU0_LOGEXP_LUTM09_Msk) >> TFU_TFU0_LOGEXP_LUTM09_TFU0_LOGEXP_LUTM09_Pos) /*!< TFU0_LOGEXP_LUTM09 Get Value            */

/* TFU0_LOGEXP_LUTM10 bitfield */
#define TFU_TFU0_LOGEXP_LUTM10_TFU0_LOGEXP_LUTM10_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTM10 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTM10_TFU0_LOGEXP_LUTM10_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTM10_TFU0_LOGEXP_LUTM10_Pos)                        /*!< TFU0_LOGEXP_LUTM10 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTM10_TFU0_LOGEXP_LUTM10_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTM10_TFU0_LOGEXP_LUTM10_Pos) & TFU_TFU0_LOGEXP_LUTM10_TFU0_LOGEXP_LUTM10_Msk) /*!< TFU0_LOGEXP_LUTM10 Set Value            */
#define TFU_TFU0_LOGEXP_LUTM10_TFU0_LOGEXP_LUTM10_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTM10_TFU0_LOGEXP_LUTM10_Msk) >> TFU_TFU0_LOGEXP_LUTM10_TFU0_LOGEXP_LUTM10_Pos) /*!< TFU0_LOGEXP_LUTM10 Get Value            */

/* TFU0_LOGEXP_LUTM11 bitfield */
#define TFU_TFU0_LOGEXP_LUTM11_TFU0_LOGEXP_LUTM11_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTM11 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTM11_TFU0_LOGEXP_LUTM11_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTM11_TFU0_LOGEXP_LUTM11_Pos)                        /*!< TFU0_LOGEXP_LUTM11 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTM11_TFU0_LOGEXP_LUTM11_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTM11_TFU0_LOGEXP_LUTM11_Pos) & TFU_TFU0_LOGEXP_LUTM11_TFU0_LOGEXP_LUTM11_Msk) /*!< TFU0_LOGEXP_LUTM11 Set Value            */
#define TFU_TFU0_LOGEXP_LUTM11_TFU0_LOGEXP_LUTM11_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTM11_TFU0_LOGEXP_LUTM11_Msk) >> TFU_TFU0_LOGEXP_LUTM11_TFU0_LOGEXP_LUTM11_Pos) /*!< TFU0_LOGEXP_LUTM11 Get Value            */

/* TFU0_LOGEXP_LUTM12 bitfield */
#define TFU_TFU0_LOGEXP_LUTM12_TFU0_LOGEXP_LUTM12_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTM12 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTM12_TFU0_LOGEXP_LUTM12_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTM12_TFU0_LOGEXP_LUTM12_Pos)                        /*!< TFU0_LOGEXP_LUTM12 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTM12_TFU0_LOGEXP_LUTM12_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTM12_TFU0_LOGEXP_LUTM12_Pos) & TFU_TFU0_LOGEXP_LUTM12_TFU0_LOGEXP_LUTM12_Msk) /*!< TFU0_LOGEXP_LUTM12 Set Value            */
#define TFU_TFU0_LOGEXP_LUTM12_TFU0_LOGEXP_LUTM12_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTM12_TFU0_LOGEXP_LUTM12_Msk) >> TFU_TFU0_LOGEXP_LUTM12_TFU0_LOGEXP_LUTM12_Pos) /*!< TFU0_LOGEXP_LUTM12 Get Value            */

/* TFU0_LOGEXP_LUTM13 bitfield */
#define TFU_TFU0_LOGEXP_LUTM13_TFU0_LOGEXP_LUTM13_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTM13 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTM13_TFU0_LOGEXP_LUTM13_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTM13_TFU0_LOGEXP_LUTM13_Pos)                        /*!< TFU0_LOGEXP_LUTM13 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTM13_TFU0_LOGEXP_LUTM13_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTM13_TFU0_LOGEXP_LUTM13_Pos) & TFU_TFU0_LOGEXP_LUTM13_TFU0_LOGEXP_LUTM13_Msk) /*!< TFU0_LOGEXP_LUTM13 Set Value            */
#define TFU_TFU0_LOGEXP_LUTM13_TFU0_LOGEXP_LUTM13_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTM13_TFU0_LOGEXP_LUTM13_Msk) >> TFU_TFU0_LOGEXP_LUTM13_TFU0_LOGEXP_LUTM13_Pos) /*!< TFU0_LOGEXP_LUTM13 Get Value            */

/* TFU0_LOGEXP_LUTM14 bitfield */
#define TFU_TFU0_LOGEXP_LUTM14_TFU0_LOGEXP_LUTM14_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTM14 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTM14_TFU0_LOGEXP_LUTM14_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTM14_TFU0_LOGEXP_LUTM14_Pos)                        /*!< TFU0_LOGEXP_LUTM14 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTM14_TFU0_LOGEXP_LUTM14_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTM14_TFU0_LOGEXP_LUTM14_Pos) & TFU_TFU0_LOGEXP_LUTM14_TFU0_LOGEXP_LUTM14_Msk) /*!< TFU0_LOGEXP_LUTM14 Set Value            */
#define TFU_TFU0_LOGEXP_LUTM14_TFU0_LOGEXP_LUTM14_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTM14_TFU0_LOGEXP_LUTM14_Msk) >> TFU_TFU0_LOGEXP_LUTM14_TFU0_LOGEXP_LUTM14_Pos) /*!< TFU0_LOGEXP_LUTM14 Get Value            */

/* TFU0_LOGEXP_LUTM15 bitfield */
#define TFU_TFU0_LOGEXP_LUTM15_TFU0_LOGEXP_LUTM15_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTM15 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTM15_TFU0_LOGEXP_LUTM15_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTM15_TFU0_LOGEXP_LUTM15_Pos)                        /*!< TFU0_LOGEXP_LUTM15 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTM15_TFU0_LOGEXP_LUTM15_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTM15_TFU0_LOGEXP_LUTM15_Pos) & TFU_TFU0_LOGEXP_LUTM15_TFU0_LOGEXP_LUTM15_Msk) /*!< TFU0_LOGEXP_LUTM15 Set Value            */
#define TFU_TFU0_LOGEXP_LUTM15_TFU0_LOGEXP_LUTM15_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTM15_TFU0_LOGEXP_LUTM15_Msk) >> TFU_TFU0_LOGEXP_LUTM15_TFU0_LOGEXP_LUTM15_Pos) /*!< TFU0_LOGEXP_LUTM15 Get Value            */

/* TFU0_LOGEXP_LUTM16 bitfield */
#define TFU_TFU0_LOGEXP_LUTM16_TFU0_LOGEXP_LUTM16_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTM16 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTM16_TFU0_LOGEXP_LUTM16_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTM16_TFU0_LOGEXP_LUTM16_Pos)                        /*!< TFU0_LOGEXP_LUTM16 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTM16_TFU0_LOGEXP_LUTM16_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTM16_TFU0_LOGEXP_LUTM16_Pos) & TFU_TFU0_LOGEXP_LUTM16_TFU0_LOGEXP_LUTM16_Msk) /*!< TFU0_LOGEXP_LUTM16 Set Value            */
#define TFU_TFU0_LOGEXP_LUTM16_TFU0_LOGEXP_LUTM16_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTM16_TFU0_LOGEXP_LUTM16_Msk) >> TFU_TFU0_LOGEXP_LUTM16_TFU0_LOGEXP_LUTM16_Pos) /*!< TFU0_LOGEXP_LUTM16 Get Value            */

/* TFU0_LOGEXP_LUTM17 bitfield */
#define TFU_TFU0_LOGEXP_LUTM17_TFU0_LOGEXP_LUTM17_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTM17 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTM17_TFU0_LOGEXP_LUTM17_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTM17_TFU0_LOGEXP_LUTM17_Pos)                        /*!< TFU0_LOGEXP_LUTM17 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTM17_TFU0_LOGEXP_LUTM17_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTM17_TFU0_LOGEXP_LUTM17_Pos) & TFU_TFU0_LOGEXP_LUTM17_TFU0_LOGEXP_LUTM17_Msk) /*!< TFU0_LOGEXP_LUTM17 Set Value            */
#define TFU_TFU0_LOGEXP_LUTM17_TFU0_LOGEXP_LUTM17_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTM17_TFU0_LOGEXP_LUTM17_Msk) >> TFU_TFU0_LOGEXP_LUTM17_TFU0_LOGEXP_LUTM17_Pos) /*!< TFU0_LOGEXP_LUTM17 Get Value            */

/* TFU0_LOGEXP_LUTM18 bitfield */
#define TFU_TFU0_LOGEXP_LUTM18_TFU0_LOGEXP_LUTM18_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTM18 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTM18_TFU0_LOGEXP_LUTM18_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTM18_TFU0_LOGEXP_LUTM18_Pos)                        /*!< TFU0_LOGEXP_LUTM18 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTM18_TFU0_LOGEXP_LUTM18_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTM18_TFU0_LOGEXP_LUTM18_Pos) & TFU_TFU0_LOGEXP_LUTM18_TFU0_LOGEXP_LUTM18_Msk) /*!< TFU0_LOGEXP_LUTM18 Set Value            */
#define TFU_TFU0_LOGEXP_LUTM18_TFU0_LOGEXP_LUTM18_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTM18_TFU0_LOGEXP_LUTM18_Msk) >> TFU_TFU0_LOGEXP_LUTM18_TFU0_LOGEXP_LUTM18_Pos) /*!< TFU0_LOGEXP_LUTM18 Get Value            */

/* TFU0_LOGEXP_LUTM19 bitfield */
#define TFU_TFU0_LOGEXP_LUTM19_TFU0_LOGEXP_LUTM19_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTM19 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTM19_TFU0_LOGEXP_LUTM19_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTM19_TFU0_LOGEXP_LUTM19_Pos)                        /*!< TFU0_LOGEXP_LUTM19 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTM19_TFU0_LOGEXP_LUTM19_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTM19_TFU0_LOGEXP_LUTM19_Pos) & TFU_TFU0_LOGEXP_LUTM19_TFU0_LOGEXP_LUTM19_Msk) /*!< TFU0_LOGEXP_LUTM19 Set Value            */
#define TFU_TFU0_LOGEXP_LUTM19_TFU0_LOGEXP_LUTM19_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTM19_TFU0_LOGEXP_LUTM19_Msk) >> TFU_TFU0_LOGEXP_LUTM19_TFU0_LOGEXP_LUTM19_Pos) /*!< TFU0_LOGEXP_LUTM19 Get Value            */

/* TFU0_LOGEXP_LUTM20 bitfield */
#define TFU_TFU0_LOGEXP_LUTM20_TFU0_LOGEXP_LUTM20_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTM20 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTM20_TFU0_LOGEXP_LUTM20_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTM20_TFU0_LOGEXP_LUTM20_Pos)                        /*!< TFU0_LOGEXP_LUTM20 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTM20_TFU0_LOGEXP_LUTM20_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTM20_TFU0_LOGEXP_LUTM20_Pos) & TFU_TFU0_LOGEXP_LUTM20_TFU0_LOGEXP_LUTM20_Msk) /*!< TFU0_LOGEXP_LUTM20 Set Value            */
#define TFU_TFU0_LOGEXP_LUTM20_TFU0_LOGEXP_LUTM20_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTM20_TFU0_LOGEXP_LUTM20_Msk) >> TFU_TFU0_LOGEXP_LUTM20_TFU0_LOGEXP_LUTM20_Pos) /*!< TFU0_LOGEXP_LUTM20 Get Value            */

/* TFU0_LOGEXP_LUTM21 bitfield */
#define TFU_TFU0_LOGEXP_LUTM21_TFU0_LOGEXP_LUTM21_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTM21 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTM21_TFU0_LOGEXP_LUTM21_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTM21_TFU0_LOGEXP_LUTM21_Pos)                        /*!< TFU0_LOGEXP_LUTM21 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTM21_TFU0_LOGEXP_LUTM21_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTM21_TFU0_LOGEXP_LUTM21_Pos) & TFU_TFU0_LOGEXP_LUTM21_TFU0_LOGEXP_LUTM21_Msk) /*!< TFU0_LOGEXP_LUTM21 Set Value            */
#define TFU_TFU0_LOGEXP_LUTM21_TFU0_LOGEXP_LUTM21_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTM21_TFU0_LOGEXP_LUTM21_Msk) >> TFU_TFU0_LOGEXP_LUTM21_TFU0_LOGEXP_LUTM21_Pos) /*!< TFU0_LOGEXP_LUTM21 Get Value            */

/* TFU0_LOGEXP_LUTM22 bitfield */
#define TFU_TFU0_LOGEXP_LUTM22_TFU0_LOGEXP_LUTM22_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTM22 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTM22_TFU0_LOGEXP_LUTM22_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTM22_TFU0_LOGEXP_LUTM22_Pos)                        /*!< TFU0_LOGEXP_LUTM22 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTM22_TFU0_LOGEXP_LUTM22_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTM22_TFU0_LOGEXP_LUTM22_Pos) & TFU_TFU0_LOGEXP_LUTM22_TFU0_LOGEXP_LUTM22_Msk) /*!< TFU0_LOGEXP_LUTM22 Set Value            */
#define TFU_TFU0_LOGEXP_LUTM22_TFU0_LOGEXP_LUTM22_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTM22_TFU0_LOGEXP_LUTM22_Msk) >> TFU_TFU0_LOGEXP_LUTM22_TFU0_LOGEXP_LUTM22_Pos) /*!< TFU0_LOGEXP_LUTM22 Get Value            */

/* TFU0_LOGEXP_LUTM23 bitfield */
#define TFU_TFU0_LOGEXP_LUTM23_TFU0_LOGEXP_LUTM23_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTM23 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTM23_TFU0_LOGEXP_LUTM23_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTM23_TFU0_LOGEXP_LUTM23_Pos)                        /*!< TFU0_LOGEXP_LUTM23 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTM23_TFU0_LOGEXP_LUTM23_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTM23_TFU0_LOGEXP_LUTM23_Pos) & TFU_TFU0_LOGEXP_LUTM23_TFU0_LOGEXP_LUTM23_Msk) /*!< TFU0_LOGEXP_LUTM23 Set Value            */
#define TFU_TFU0_LOGEXP_LUTM23_TFU0_LOGEXP_LUTM23_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTM23_TFU0_LOGEXP_LUTM23_Msk) >> TFU_TFU0_LOGEXP_LUTM23_TFU0_LOGEXP_LUTM23_Pos) /*!< TFU0_LOGEXP_LUTM23 Get Value            */

/* TFU0_LOGEXP_LUTM24 bitfield */
#define TFU_TFU0_LOGEXP_LUTM24_TFU0_LOGEXP_LUTM24_Pos    (0U)                                                                                  /*!< TFU0_LOGEXP_LUTM24 Position  0          */ 
#define TFU_TFU0_LOGEXP_LUTM24_TFU0_LOGEXP_LUTM24_Msk    (0xffffffffU << TFU_TFU0_LOGEXP_LUTM24_TFU0_LOGEXP_LUTM24_Pos)                        /*!< TFU0_LOGEXP_LUTM24 Mask      0xFFFFFFFF */
#define TFU_TFU0_LOGEXP_LUTM24_TFU0_LOGEXP_LUTM24_Set(x) (((uint32_t) (x) << TFU_TFU0_LOGEXP_LUTM24_TFU0_LOGEXP_LUTM24_Pos) & TFU_TFU0_LOGEXP_LUTM24_TFU0_LOGEXP_LUTM24_Msk) /*!< TFU0_LOGEXP_LUTM24 Set Value            */
#define TFU_TFU0_LOGEXP_LUTM24_TFU0_LOGEXP_LUTM24_Get(x) (((uint32_t) (x) & TFU_TFU0_LOGEXP_LUTM24_TFU0_LOGEXP_LUTM24_Msk) >> TFU_TFU0_LOGEXP_LUTM24_TFU0_LOGEXP_LUTM24_Pos) /*!< TFU0_LOGEXP_LUTM24 Get Value            */

/* TFU1_CFG bitfield */
#define TFU_TFU1_CFG_TFU1_ARB_MODE_Pos    (31U)                                                                                 /*!< TFU1_ARB_MODE Position  31         */ 
#define TFU_TFU1_CFG_TFU1_ARB_MODE_Msk    (0x1U << TFU_TFU1_CFG_TFU1_ARB_MODE_Pos)                                              /*!< TFU1_ARB_MODE Mask      0x80000000 */
#define TFU_TFU1_CFG_TFU1_ARB_MODE_Set(x) (((uint32_t) (x) << TFU_TFU1_CFG_TFU1_ARB_MODE_Pos) & TFU_TFU1_CFG_TFU1_ARB_MODE_Msk) /*!< TFU1_ARB_MODE Set Value            */
#define TFU_TFU1_CFG_TFU1_ARB_MODE_Get(x) (((uint32_t) (x) & TFU_TFU1_CFG_TFU1_ARB_MODE_Msk) >> TFU_TFU1_CFG_TFU1_ARB_MODE_Pos) /*!< TFU1_ARB_MODE Get Value            */

#define TFU_TFU1_CFG_TFU1_TRD3_LOAD_Pos    (7U)                                                                                  /*!< TFU1_TRD3_LOAD Position  7          */ 
#define TFU_TFU1_CFG_TFU1_TRD3_LOAD_Msk    (0x1U << TFU_TFU1_CFG_TFU1_TRD3_LOAD_Pos)                                             /*!< TFU1_TRD3_LOAD Mask      0x00000080 */
#define TFU_TFU1_CFG_TFU1_TRD3_LOAD_Set(x) (((uint32_t) (x) << TFU_TFU1_CFG_TFU1_TRD3_LOAD_Pos) & TFU_TFU1_CFG_TFU1_TRD3_LOAD_Msk) /*!< TFU1_TRD3_LOAD Set Value            */
#define TFU_TFU1_CFG_TFU1_TRD3_LOAD_Get(x) (((uint32_t) (x) & TFU_TFU1_CFG_TFU1_TRD3_LOAD_Msk) >> TFU_TFU1_CFG_TFU1_TRD3_LOAD_Pos) /*!< TFU1_TRD3_LOAD Get Value            */

#define TFU_TFU1_CFG_TFU1_TRD2_LOAD_Pos    (6U)                                                                                  /*!< TFU1_TRD2_LOAD Position  6          */ 
#define TFU_TFU1_CFG_TFU1_TRD2_LOAD_Msk    (0x1U << TFU_TFU1_CFG_TFU1_TRD2_LOAD_Pos)                                             /*!< TFU1_TRD2_LOAD Mask      0x00000040 */
#define TFU_TFU1_CFG_TFU1_TRD2_LOAD_Set(x) (((uint32_t) (x) << TFU_TFU1_CFG_TFU1_TRD2_LOAD_Pos) & TFU_TFU1_CFG_TFU1_TRD2_LOAD_Msk) /*!< TFU1_TRD2_LOAD Set Value            */
#define TFU_TFU1_CFG_TFU1_TRD2_LOAD_Get(x) (((uint32_t) (x) & TFU_TFU1_CFG_TFU1_TRD2_LOAD_Msk) >> TFU_TFU1_CFG_TFU1_TRD2_LOAD_Pos) /*!< TFU1_TRD2_LOAD Get Value            */

#define TFU_TFU1_CFG_TFU1_TRD1_LOAD_Pos    (5U)                                                                                  /*!< TFU1_TRD1_LOAD Position  5          */ 
#define TFU_TFU1_CFG_TFU1_TRD1_LOAD_Msk    (0x1U << TFU_TFU1_CFG_TFU1_TRD1_LOAD_Pos)                                             /*!< TFU1_TRD1_LOAD Mask      0x00000020 */
#define TFU_TFU1_CFG_TFU1_TRD1_LOAD_Set(x) (((uint32_t) (x) << TFU_TFU1_CFG_TFU1_TRD1_LOAD_Pos) & TFU_TFU1_CFG_TFU1_TRD1_LOAD_Msk) /*!< TFU1_TRD1_LOAD Set Value            */
#define TFU_TFU1_CFG_TFU1_TRD1_LOAD_Get(x) (((uint32_t) (x) & TFU_TFU1_CFG_TFU1_TRD1_LOAD_Msk) >> TFU_TFU1_CFG_TFU1_TRD1_LOAD_Pos) /*!< TFU1_TRD1_LOAD Get Value            */

#define TFU_TFU1_CFG_TFU1_TRD0_LOAD_Pos    (4U)                                                                                  /*!< TFU1_TRD0_LOAD Position  4          */ 
#define TFU_TFU1_CFG_TFU1_TRD0_LOAD_Msk    (0x1U << TFU_TFU1_CFG_TFU1_TRD0_LOAD_Pos)                                             /*!< TFU1_TRD0_LOAD Mask      0x00000010 */
#define TFU_TFU1_CFG_TFU1_TRD0_LOAD_Set(x) (((uint32_t) (x) << TFU_TFU1_CFG_TFU1_TRD0_LOAD_Pos) & TFU_TFU1_CFG_TFU1_TRD0_LOAD_Msk) /*!< TFU1_TRD0_LOAD Set Value            */
#define TFU_TFU1_CFG_TFU1_TRD0_LOAD_Get(x) (((uint32_t) (x) & TFU_TFU1_CFG_TFU1_TRD0_LOAD_Msk) >> TFU_TFU1_CFG_TFU1_TRD0_LOAD_Pos) /*!< TFU1_TRD0_LOAD Get Value            */

#define TFU_TFU1_CFG_TFU1_TRD3_FIFO_CLR_Pos    (3U)                                                                                  /*!< TFU1_TRD3_FIFO_CLR Position  3          */ 
#define TFU_TFU1_CFG_TFU1_TRD3_FIFO_CLR_Msk    (0x1U << TFU_TFU1_CFG_TFU1_TRD3_FIFO_CLR_Pos)                                         /*!< TFU1_TRD3_FIFO_CLR Mask      0x00000008 */
#define TFU_TFU1_CFG_TFU1_TRD3_FIFO_CLR_Set(x) (((uint32_t) (x) << TFU_TFU1_CFG_TFU1_TRD3_FIFO_CLR_Pos) & TFU_TFU1_CFG_TFU1_TRD3_FIFO_CLR_Msk) /*!< TFU1_TRD3_FIFO_CLR Set Value            */
#define TFU_TFU1_CFG_TFU1_TRD3_FIFO_CLR_Get(x) (((uint32_t) (x) & TFU_TFU1_CFG_TFU1_TRD3_FIFO_CLR_Msk) >> TFU_TFU1_CFG_TFU1_TRD3_FIFO_CLR_Pos) /*!< TFU1_TRD3_FIFO_CLR Get Value            */

#define TFU_TFU1_CFG_TFU1_TRD2_FIFO_CLR_Pos    (2U)                                                                                  /*!< TFU1_TRD2_FIFO_CLR Position  2          */ 
#define TFU_TFU1_CFG_TFU1_TRD2_FIFO_CLR_Msk    (0x1U << TFU_TFU1_CFG_TFU1_TRD2_FIFO_CLR_Pos)                                         /*!< TFU1_TRD2_FIFO_CLR Mask      0x00000004 */
#define TFU_TFU1_CFG_TFU1_TRD2_FIFO_CLR_Set(x) (((uint32_t) (x) << TFU_TFU1_CFG_TFU1_TRD2_FIFO_CLR_Pos) & TFU_TFU1_CFG_TFU1_TRD2_FIFO_CLR_Msk) /*!< TFU1_TRD2_FIFO_CLR Set Value            */
#define TFU_TFU1_CFG_TFU1_TRD2_FIFO_CLR_Get(x) (((uint32_t) (x) & TFU_TFU1_CFG_TFU1_TRD2_FIFO_CLR_Msk) >> TFU_TFU1_CFG_TFU1_TRD2_FIFO_CLR_Pos) /*!< TFU1_TRD2_FIFO_CLR Get Value            */

#define TFU_TFU1_CFG_TFU1_TRD1_FIFO_CLR_Pos    (1U)                                                                                  /*!< TFU1_TRD1_FIFO_CLR Position  1          */ 
#define TFU_TFU1_CFG_TFU1_TRD1_FIFO_CLR_Msk    (0x1U << TFU_TFU1_CFG_TFU1_TRD1_FIFO_CLR_Pos)                                         /*!< TFU1_TRD1_FIFO_CLR Mask      0x00000002 */
#define TFU_TFU1_CFG_TFU1_TRD1_FIFO_CLR_Set(x) (((uint32_t) (x) << TFU_TFU1_CFG_TFU1_TRD1_FIFO_CLR_Pos) & TFU_TFU1_CFG_TFU1_TRD1_FIFO_CLR_Msk) /*!< TFU1_TRD1_FIFO_CLR Set Value            */
#define TFU_TFU1_CFG_TFU1_TRD1_FIFO_CLR_Get(x) (((uint32_t) (x) & TFU_TFU1_CFG_TFU1_TRD1_FIFO_CLR_Msk) >> TFU_TFU1_CFG_TFU1_TRD1_FIFO_CLR_Pos) /*!< TFU1_TRD1_FIFO_CLR Get Value            */

#define TFU_TFU1_CFG_TFU1_TRD0_FIFO_CLR_Pos    (0U)                                                                                  /*!< TFU1_TRD0_FIFO_CLR Position  0          */ 
#define TFU_TFU1_CFG_TFU1_TRD0_FIFO_CLR_Msk    (0x1U << TFU_TFU1_CFG_TFU1_TRD0_FIFO_CLR_Pos)                                         /*!< TFU1_TRD0_FIFO_CLR Mask      0x00000001 */
#define TFU_TFU1_CFG_TFU1_TRD0_FIFO_CLR_Set(x) (((uint32_t) (x) << TFU_TFU1_CFG_TFU1_TRD0_FIFO_CLR_Pos) & TFU_TFU1_CFG_TFU1_TRD0_FIFO_CLR_Msk) /*!< TFU1_TRD0_FIFO_CLR Set Value            */
#define TFU_TFU1_CFG_TFU1_TRD0_FIFO_CLR_Get(x) (((uint32_t) (x) & TFU_TFU1_CFG_TFU1_TRD0_FIFO_CLR_Msk) >> TFU_TFU1_CFG_TFU1_TRD0_FIFO_CLR_Pos) /*!< TFU1_TRD0_FIFO_CLR Get Value            */

/* TFU1_FIFO_WATERLEVEL bitfield */
#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD3_ARG0_WL_Pos    (28U)                                                                                 /*!< TFU1_TRD3_ARG0_WL Position  28         */ 
#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD3_ARG0_WL_Msk    (0x3U << TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD3_ARG0_WL_Pos)                              /*!< TFU1_TRD3_ARG0_WL Mask      0x30000000 */
#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD3_ARG0_WL_Set(x) (((uint32_t) (x) << TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD3_ARG0_WL_Pos) & TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD3_ARG0_WL_Msk) /*!< TFU1_TRD3_ARG0_WL Set Value            */
#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD3_ARG0_WL_Get(x) (((uint32_t) (x) & TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD3_ARG0_WL_Msk) >> TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD3_ARG0_WL_Pos) /*!< TFU1_TRD3_ARG0_WL Get Value            */

#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD3_ARG1_WL_Pos    (26U)                                                                                 /*!< TFU1_TRD3_ARG1_WL Position  26         */ 
#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD3_ARG1_WL_Msk    (0x3U << TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD3_ARG1_WL_Pos)                              /*!< TFU1_TRD3_ARG1_WL Mask      0x0C000000 */
#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD3_ARG1_WL_Set(x) (((uint32_t) (x) << TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD3_ARG1_WL_Pos) & TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD3_ARG1_WL_Msk) /*!< TFU1_TRD3_ARG1_WL Set Value            */
#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD3_ARG1_WL_Get(x) (((uint32_t) (x) & TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD3_ARG1_WL_Msk) >> TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD3_ARG1_WL_Pos) /*!< TFU1_TRD3_ARG1_WL Get Value            */

#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD3_RES_WL_Pos    (24U)                                                                                 /*!< TFU1_TRD3_RES_WL Position  24         */ 
#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD3_RES_WL_Msk    (0x3U << TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD3_RES_WL_Pos)                               /*!< TFU1_TRD3_RES_WL Mask      0x03000000 */
#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD3_RES_WL_Set(x) (((uint32_t) (x) << TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD3_RES_WL_Pos) & TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD3_RES_WL_Msk) /*!< TFU1_TRD3_RES_WL Set Value            */
#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD3_RES_WL_Get(x) (((uint32_t) (x) & TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD3_RES_WL_Msk) >> TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD3_RES_WL_Pos) /*!< TFU1_TRD3_RES_WL Get Value            */

#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD2_ARG0_WL_Pos    (22U)                                                                                 /*!< TFU1_TRD2_ARG0_WL Position  22         */ 
#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD2_ARG0_WL_Msk    (0x3U << TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD2_ARG0_WL_Pos)                              /*!< TFU1_TRD2_ARG0_WL Mask      0x00C00000 */
#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD2_ARG0_WL_Set(x) (((uint32_t) (x) << TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD2_ARG0_WL_Pos) & TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD2_ARG0_WL_Msk) /*!< TFU1_TRD2_ARG0_WL Set Value            */
#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD2_ARG0_WL_Get(x) (((uint32_t) (x) & TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD2_ARG0_WL_Msk) >> TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD2_ARG0_WL_Pos) /*!< TFU1_TRD2_ARG0_WL Get Value            */

#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD2_ARG1_WL_Pos    (20U)                                                                                 /*!< TFU1_TRD2_ARG1_WL Position  20         */ 
#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD2_ARG1_WL_Msk    (0x3U << TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD2_ARG1_WL_Pos)                              /*!< TFU1_TRD2_ARG1_WL Mask      0x00300000 */
#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD2_ARG1_WL_Set(x) (((uint32_t) (x) << TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD2_ARG1_WL_Pos) & TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD2_ARG1_WL_Msk) /*!< TFU1_TRD2_ARG1_WL Set Value            */
#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD2_ARG1_WL_Get(x) (((uint32_t) (x) & TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD2_ARG1_WL_Msk) >> TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD2_ARG1_WL_Pos) /*!< TFU1_TRD2_ARG1_WL Get Value            */

#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD2_RES_WL_Pos    (18U)                                                                                 /*!< TFU1_TRD2_RES_WL Position  18         */ 
#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD2_RES_WL_Msk    (0x3U << TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD2_RES_WL_Pos)                               /*!< TFU1_TRD2_RES_WL Mask      0x000C0000 */
#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD2_RES_WL_Set(x) (((uint32_t) (x) << TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD2_RES_WL_Pos) & TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD2_RES_WL_Msk) /*!< TFU1_TRD2_RES_WL Set Value            */
#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD2_RES_WL_Get(x) (((uint32_t) (x) & TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD2_RES_WL_Msk) >> TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD2_RES_WL_Pos) /*!< TFU1_TRD2_RES_WL Get Value            */

#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD1_ARG0_WL_Pos    (16U)                                                                                 /*!< TFU1_TRD1_ARG0_WL Position  16         */ 
#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD1_ARG0_WL_Msk    (0x3U << TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD1_ARG0_WL_Pos)                              /*!< TFU1_TRD1_ARG0_WL Mask      0x00030000 */
#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD1_ARG0_WL_Set(x) (((uint32_t) (x) << TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD1_ARG0_WL_Pos) & TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD1_ARG0_WL_Msk) /*!< TFU1_TRD1_ARG0_WL Set Value            */
#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD1_ARG0_WL_Get(x) (((uint32_t) (x) & TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD1_ARG0_WL_Msk) >> TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD1_ARG0_WL_Pos) /*!< TFU1_TRD1_ARG0_WL Get Value            */

#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD1_ARG1_WL_Pos    (14U)                                                                                 /*!< TFU1_TRD1_ARG1_WL Position  14         */ 
#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD1_ARG1_WL_Msk    (0x3U << TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD1_ARG1_WL_Pos)                              /*!< TFU1_TRD1_ARG1_WL Mask      0x0000C000 */
#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD1_ARG1_WL_Set(x) (((uint32_t) (x) << TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD1_ARG1_WL_Pos) & TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD1_ARG1_WL_Msk) /*!< TFU1_TRD1_ARG1_WL Set Value            */
#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD1_ARG1_WL_Get(x) (((uint32_t) (x) & TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD1_ARG1_WL_Msk) >> TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD1_ARG1_WL_Pos) /*!< TFU1_TRD1_ARG1_WL Get Value            */

#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD1_RES_WL_Pos    (12U)                                                                                 /*!< TFU1_TRD1_RES_WL Position  12         */ 
#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD1_RES_WL_Msk    (0x3U << TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD1_RES_WL_Pos)                               /*!< TFU1_TRD1_RES_WL Mask      0x00003000 */
#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD1_RES_WL_Set(x) (((uint32_t) (x) << TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD1_RES_WL_Pos) & TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD1_RES_WL_Msk) /*!< TFU1_TRD1_RES_WL Set Value            */
#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD1_RES_WL_Get(x) (((uint32_t) (x) & TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD1_RES_WL_Msk) >> TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD1_RES_WL_Pos) /*!< TFU1_TRD1_RES_WL Get Value            */

#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD0_ARG0_WL_Pos    (8U)                                                                                  /*!< TFU1_TRD0_ARG0_WL Position  8          */ 
#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD0_ARG0_WL_Msk    (0xfU << TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD0_ARG0_WL_Pos)                              /*!< TFU1_TRD0_ARG0_WL Mask      0x00000F00 */
#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD0_ARG0_WL_Set(x) (((uint32_t) (x) << TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD0_ARG0_WL_Pos) & TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD0_ARG0_WL_Msk) /*!< TFU1_TRD0_ARG0_WL Set Value            */
#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD0_ARG0_WL_Get(x) (((uint32_t) (x) & TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD0_ARG0_WL_Msk) >> TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD0_ARG0_WL_Pos) /*!< TFU1_TRD0_ARG0_WL Get Value            */

#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD0_ARG1_WL_Pos    (4U)                                                                                  /*!< TFU1_TRD0_ARG1_WL Position  4          */ 
#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD0_ARG1_WL_Msk    (0xfU << TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD0_ARG1_WL_Pos)                              /*!< TFU1_TRD0_ARG1_WL Mask      0x000000F0 */
#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD0_ARG1_WL_Set(x) (((uint32_t) (x) << TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD0_ARG1_WL_Pos) & TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD0_ARG1_WL_Msk) /*!< TFU1_TRD0_ARG1_WL Set Value            */
#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD0_ARG1_WL_Get(x) (((uint32_t) (x) & TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD0_ARG1_WL_Msk) >> TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD0_ARG1_WL_Pos) /*!< TFU1_TRD0_ARG1_WL Get Value            */

#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD0_RES_WL_Pos    (0U)                                                                                  /*!< TFU1_TRD0_RES_WL Position  0          */ 
#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD0_RES_WL_Msk    (0xfU << TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD0_RES_WL_Pos)                               /*!< TFU1_TRD0_RES_WL Mask      0x0000000F */
#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD0_RES_WL_Set(x) (((uint32_t) (x) << TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD0_RES_WL_Pos) & TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD0_RES_WL_Msk) /*!< TFU1_TRD0_RES_WL Set Value            */
#define TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD0_RES_WL_Get(x) (((uint32_t) (x) & TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD0_RES_WL_Msk) >> TFU_TFU1_FIFO_WATERLEVEL_TFU1_TRD0_RES_WL_Pos) /*!< TFU1_TRD0_RES_WL Get Value            */

/* TFU1_LOGEXP_LUTP01 bitfield */
#define TFU_TFU1_LOGEXP_LUTP01_TFU1_LOGEXP_LUTP01_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTP01 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTP01_TFU1_LOGEXP_LUTP01_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTP01_TFU1_LOGEXP_LUTP01_Pos)                        /*!< TFU1_LOGEXP_LUTP01 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTP01_TFU1_LOGEXP_LUTP01_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTP01_TFU1_LOGEXP_LUTP01_Pos) & TFU_TFU1_LOGEXP_LUTP01_TFU1_LOGEXP_LUTP01_Msk) /*!< TFU1_LOGEXP_LUTP01 Set Value            */
#define TFU_TFU1_LOGEXP_LUTP01_TFU1_LOGEXP_LUTP01_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTP01_TFU1_LOGEXP_LUTP01_Msk) >> TFU_TFU1_LOGEXP_LUTP01_TFU1_LOGEXP_LUTP01_Pos) /*!< TFU1_LOGEXP_LUTP01 Get Value            */

/* TFU1_LOGEXP_LUTP02 bitfield */
#define TFU_TFU1_LOGEXP_LUTP02_TFU1_LOGEXP_LUTP02_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTP02 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTP02_TFU1_LOGEXP_LUTP02_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTP02_TFU1_LOGEXP_LUTP02_Pos)                        /*!< TFU1_LOGEXP_LUTP02 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTP02_TFU1_LOGEXP_LUTP02_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTP02_TFU1_LOGEXP_LUTP02_Pos) & TFU_TFU1_LOGEXP_LUTP02_TFU1_LOGEXP_LUTP02_Msk) /*!< TFU1_LOGEXP_LUTP02 Set Value            */
#define TFU_TFU1_LOGEXP_LUTP02_TFU1_LOGEXP_LUTP02_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTP02_TFU1_LOGEXP_LUTP02_Msk) >> TFU_TFU1_LOGEXP_LUTP02_TFU1_LOGEXP_LUTP02_Pos) /*!< TFU1_LOGEXP_LUTP02 Get Value            */

/* TFU1_LOGEXP_LUTP03 bitfield */
#define TFU_TFU1_LOGEXP_LUTP03_TFU1_LOGEXP_LUTP03_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTP03 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTP03_TFU1_LOGEXP_LUTP03_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTP03_TFU1_LOGEXP_LUTP03_Pos)                        /*!< TFU1_LOGEXP_LUTP03 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTP03_TFU1_LOGEXP_LUTP03_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTP03_TFU1_LOGEXP_LUTP03_Pos) & TFU_TFU1_LOGEXP_LUTP03_TFU1_LOGEXP_LUTP03_Msk) /*!< TFU1_LOGEXP_LUTP03 Set Value            */
#define TFU_TFU1_LOGEXP_LUTP03_TFU1_LOGEXP_LUTP03_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTP03_TFU1_LOGEXP_LUTP03_Msk) >> TFU_TFU1_LOGEXP_LUTP03_TFU1_LOGEXP_LUTP03_Pos) /*!< TFU1_LOGEXP_LUTP03 Get Value            */

/* TFU1_LOGEXP_LUTP04 bitfield */
#define TFU_TFU1_LOGEXP_LUTP04_TFU1_LOGEXP_LUTP04_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTP04 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTP04_TFU1_LOGEXP_LUTP04_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTP04_TFU1_LOGEXP_LUTP04_Pos)                        /*!< TFU1_LOGEXP_LUTP04 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTP04_TFU1_LOGEXP_LUTP04_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTP04_TFU1_LOGEXP_LUTP04_Pos) & TFU_TFU1_LOGEXP_LUTP04_TFU1_LOGEXP_LUTP04_Msk) /*!< TFU1_LOGEXP_LUTP04 Set Value            */
#define TFU_TFU1_LOGEXP_LUTP04_TFU1_LOGEXP_LUTP04_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTP04_TFU1_LOGEXP_LUTP04_Msk) >> TFU_TFU1_LOGEXP_LUTP04_TFU1_LOGEXP_LUTP04_Pos) /*!< TFU1_LOGEXP_LUTP04 Get Value            */

/* TFU1_LOGEXP_LUTP05 bitfield */
#define TFU_TFU1_LOGEXP_LUTP05_TFU1_LOGEXP_LUTP05_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTP05 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTP05_TFU1_LOGEXP_LUTP05_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTP05_TFU1_LOGEXP_LUTP05_Pos)                        /*!< TFU1_LOGEXP_LUTP05 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTP05_TFU1_LOGEXP_LUTP05_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTP05_TFU1_LOGEXP_LUTP05_Pos) & TFU_TFU1_LOGEXP_LUTP05_TFU1_LOGEXP_LUTP05_Msk) /*!< TFU1_LOGEXP_LUTP05 Set Value            */
#define TFU_TFU1_LOGEXP_LUTP05_TFU1_LOGEXP_LUTP05_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTP05_TFU1_LOGEXP_LUTP05_Msk) >> TFU_TFU1_LOGEXP_LUTP05_TFU1_LOGEXP_LUTP05_Pos) /*!< TFU1_LOGEXP_LUTP05 Get Value            */

/* TFU1_LOGEXP_LUTP06 bitfield */
#define TFU_TFU1_LOGEXP_LUTP06_TFU1_LOGEXP_LUTP06_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTP06 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTP06_TFU1_LOGEXP_LUTP06_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTP06_TFU1_LOGEXP_LUTP06_Pos)                        /*!< TFU1_LOGEXP_LUTP06 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTP06_TFU1_LOGEXP_LUTP06_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTP06_TFU1_LOGEXP_LUTP06_Pos) & TFU_TFU1_LOGEXP_LUTP06_TFU1_LOGEXP_LUTP06_Msk) /*!< TFU1_LOGEXP_LUTP06 Set Value            */
#define TFU_TFU1_LOGEXP_LUTP06_TFU1_LOGEXP_LUTP06_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTP06_TFU1_LOGEXP_LUTP06_Msk) >> TFU_TFU1_LOGEXP_LUTP06_TFU1_LOGEXP_LUTP06_Pos) /*!< TFU1_LOGEXP_LUTP06 Get Value            */

/* TFU1_LOGEXP_LUTP07 bitfield */
#define TFU_TFU1_LOGEXP_LUTP07_TFU1_LOGEXP_LUTP07_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTP07 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTP07_TFU1_LOGEXP_LUTP07_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTP07_TFU1_LOGEXP_LUTP07_Pos)                        /*!< TFU1_LOGEXP_LUTP07 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTP07_TFU1_LOGEXP_LUTP07_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTP07_TFU1_LOGEXP_LUTP07_Pos) & TFU_TFU1_LOGEXP_LUTP07_TFU1_LOGEXP_LUTP07_Msk) /*!< TFU1_LOGEXP_LUTP07 Set Value            */
#define TFU_TFU1_LOGEXP_LUTP07_TFU1_LOGEXP_LUTP07_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTP07_TFU1_LOGEXP_LUTP07_Msk) >> TFU_TFU1_LOGEXP_LUTP07_TFU1_LOGEXP_LUTP07_Pos) /*!< TFU1_LOGEXP_LUTP07 Get Value            */

/* TFU1_LOGEXP_LUTP08 bitfield */
#define TFU_TFU1_LOGEXP_LUTP08_TFU1_LOGEXP_LUTP08_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTP08 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTP08_TFU1_LOGEXP_LUTP08_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTP08_TFU1_LOGEXP_LUTP08_Pos)                        /*!< TFU1_LOGEXP_LUTP08 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTP08_TFU1_LOGEXP_LUTP08_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTP08_TFU1_LOGEXP_LUTP08_Pos) & TFU_TFU1_LOGEXP_LUTP08_TFU1_LOGEXP_LUTP08_Msk) /*!< TFU1_LOGEXP_LUTP08 Set Value            */
#define TFU_TFU1_LOGEXP_LUTP08_TFU1_LOGEXP_LUTP08_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTP08_TFU1_LOGEXP_LUTP08_Msk) >> TFU_TFU1_LOGEXP_LUTP08_TFU1_LOGEXP_LUTP08_Pos) /*!< TFU1_LOGEXP_LUTP08 Get Value            */

/* TFU1_LOGEXP_LUTP09 bitfield */
#define TFU_TFU1_LOGEXP_LUTP09_TFU1_LOGEXP_LUTP09_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTP09 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTP09_TFU1_LOGEXP_LUTP09_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTP09_TFU1_LOGEXP_LUTP09_Pos)                        /*!< TFU1_LOGEXP_LUTP09 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTP09_TFU1_LOGEXP_LUTP09_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTP09_TFU1_LOGEXP_LUTP09_Pos) & TFU_TFU1_LOGEXP_LUTP09_TFU1_LOGEXP_LUTP09_Msk) /*!< TFU1_LOGEXP_LUTP09 Set Value            */
#define TFU_TFU1_LOGEXP_LUTP09_TFU1_LOGEXP_LUTP09_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTP09_TFU1_LOGEXP_LUTP09_Msk) >> TFU_TFU1_LOGEXP_LUTP09_TFU1_LOGEXP_LUTP09_Pos) /*!< TFU1_LOGEXP_LUTP09 Get Value            */

/* TFU1_LOGEXP_LUTP10 bitfield */
#define TFU_TFU1_LOGEXP_LUTP10_TFU1_LOGEXP_LUTP10_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTP10 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTP10_TFU1_LOGEXP_LUTP10_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTP10_TFU1_LOGEXP_LUTP10_Pos)                        /*!< TFU1_LOGEXP_LUTP10 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTP10_TFU1_LOGEXP_LUTP10_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTP10_TFU1_LOGEXP_LUTP10_Pos) & TFU_TFU1_LOGEXP_LUTP10_TFU1_LOGEXP_LUTP10_Msk) /*!< TFU1_LOGEXP_LUTP10 Set Value            */
#define TFU_TFU1_LOGEXP_LUTP10_TFU1_LOGEXP_LUTP10_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTP10_TFU1_LOGEXP_LUTP10_Msk) >> TFU_TFU1_LOGEXP_LUTP10_TFU1_LOGEXP_LUTP10_Pos) /*!< TFU1_LOGEXP_LUTP10 Get Value            */

/* TFU1_LOGEXP_LUTP11 bitfield */
#define TFU_TFU1_LOGEXP_LUTP11_TFU1_LOGEXP_LUTP11_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTP11 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTP11_TFU1_LOGEXP_LUTP11_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTP11_TFU1_LOGEXP_LUTP11_Pos)                        /*!< TFU1_LOGEXP_LUTP11 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTP11_TFU1_LOGEXP_LUTP11_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTP11_TFU1_LOGEXP_LUTP11_Pos) & TFU_TFU1_LOGEXP_LUTP11_TFU1_LOGEXP_LUTP11_Msk) /*!< TFU1_LOGEXP_LUTP11 Set Value            */
#define TFU_TFU1_LOGEXP_LUTP11_TFU1_LOGEXP_LUTP11_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTP11_TFU1_LOGEXP_LUTP11_Msk) >> TFU_TFU1_LOGEXP_LUTP11_TFU1_LOGEXP_LUTP11_Pos) /*!< TFU1_LOGEXP_LUTP11 Get Value            */

/* TFU1_LOGEXP_LUTP12 bitfield */
#define TFU_TFU1_LOGEXP_LUTP12_TFU1_LOGEXP_LUTP12_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTP12 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTP12_TFU1_LOGEXP_LUTP12_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTP12_TFU1_LOGEXP_LUTP12_Pos)                        /*!< TFU1_LOGEXP_LUTP12 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTP12_TFU1_LOGEXP_LUTP12_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTP12_TFU1_LOGEXP_LUTP12_Pos) & TFU_TFU1_LOGEXP_LUTP12_TFU1_LOGEXP_LUTP12_Msk) /*!< TFU1_LOGEXP_LUTP12 Set Value            */
#define TFU_TFU1_LOGEXP_LUTP12_TFU1_LOGEXP_LUTP12_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTP12_TFU1_LOGEXP_LUTP12_Msk) >> TFU_TFU1_LOGEXP_LUTP12_TFU1_LOGEXP_LUTP12_Pos) /*!< TFU1_LOGEXP_LUTP12 Get Value            */

/* TFU1_LOGEXP_LUTP13 bitfield */
#define TFU_TFU1_LOGEXP_LUTP13_TFU1_LOGEXP_LUTP13_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTP13 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTP13_TFU1_LOGEXP_LUTP13_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTP13_TFU1_LOGEXP_LUTP13_Pos)                        /*!< TFU1_LOGEXP_LUTP13 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTP13_TFU1_LOGEXP_LUTP13_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTP13_TFU1_LOGEXP_LUTP13_Pos) & TFU_TFU1_LOGEXP_LUTP13_TFU1_LOGEXP_LUTP13_Msk) /*!< TFU1_LOGEXP_LUTP13 Set Value            */
#define TFU_TFU1_LOGEXP_LUTP13_TFU1_LOGEXP_LUTP13_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTP13_TFU1_LOGEXP_LUTP13_Msk) >> TFU_TFU1_LOGEXP_LUTP13_TFU1_LOGEXP_LUTP13_Pos) /*!< TFU1_LOGEXP_LUTP13 Get Value            */

/* TFU1_LOGEXP_LUTP14 bitfield */
#define TFU_TFU1_LOGEXP_LUTP14_TFU1_LOGEXP_LUTP14_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTP14 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTP14_TFU1_LOGEXP_LUTP14_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTP14_TFU1_LOGEXP_LUTP14_Pos)                        /*!< TFU1_LOGEXP_LUTP14 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTP14_TFU1_LOGEXP_LUTP14_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTP14_TFU1_LOGEXP_LUTP14_Pos) & TFU_TFU1_LOGEXP_LUTP14_TFU1_LOGEXP_LUTP14_Msk) /*!< TFU1_LOGEXP_LUTP14 Set Value            */
#define TFU_TFU1_LOGEXP_LUTP14_TFU1_LOGEXP_LUTP14_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTP14_TFU1_LOGEXP_LUTP14_Msk) >> TFU_TFU1_LOGEXP_LUTP14_TFU1_LOGEXP_LUTP14_Pos) /*!< TFU1_LOGEXP_LUTP14 Get Value            */

/* TFU1_LOGEXP_LUTP15 bitfield */
#define TFU_TFU1_LOGEXP_LUTP15_TFU1_LOGEXP_LUTP15_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTP15 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTP15_TFU1_LOGEXP_LUTP15_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTP15_TFU1_LOGEXP_LUTP15_Pos)                        /*!< TFU1_LOGEXP_LUTP15 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTP15_TFU1_LOGEXP_LUTP15_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTP15_TFU1_LOGEXP_LUTP15_Pos) & TFU_TFU1_LOGEXP_LUTP15_TFU1_LOGEXP_LUTP15_Msk) /*!< TFU1_LOGEXP_LUTP15 Set Value            */
#define TFU_TFU1_LOGEXP_LUTP15_TFU1_LOGEXP_LUTP15_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTP15_TFU1_LOGEXP_LUTP15_Msk) >> TFU_TFU1_LOGEXP_LUTP15_TFU1_LOGEXP_LUTP15_Pos) /*!< TFU1_LOGEXP_LUTP15 Get Value            */

/* TFU1_LOGEXP_LUTP16 bitfield */
#define TFU_TFU1_LOGEXP_LUTP16_TFU1_LOGEXP_LUTP16_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTP16 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTP16_TFU1_LOGEXP_LUTP16_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTP16_TFU1_LOGEXP_LUTP16_Pos)                        /*!< TFU1_LOGEXP_LUTP16 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTP16_TFU1_LOGEXP_LUTP16_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTP16_TFU1_LOGEXP_LUTP16_Pos) & TFU_TFU1_LOGEXP_LUTP16_TFU1_LOGEXP_LUTP16_Msk) /*!< TFU1_LOGEXP_LUTP16 Set Value            */
#define TFU_TFU1_LOGEXP_LUTP16_TFU1_LOGEXP_LUTP16_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTP16_TFU1_LOGEXP_LUTP16_Msk) >> TFU_TFU1_LOGEXP_LUTP16_TFU1_LOGEXP_LUTP16_Pos) /*!< TFU1_LOGEXP_LUTP16 Get Value            */

/* TFU1_LOGEXP_LUTP17 bitfield */
#define TFU_TFU1_LOGEXP_LUTP17_TFU1_LOGEXP_LUTP17_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTP17 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTP17_TFU1_LOGEXP_LUTP17_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTP17_TFU1_LOGEXP_LUTP17_Pos)                        /*!< TFU1_LOGEXP_LUTP17 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTP17_TFU1_LOGEXP_LUTP17_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTP17_TFU1_LOGEXP_LUTP17_Pos) & TFU_TFU1_LOGEXP_LUTP17_TFU1_LOGEXP_LUTP17_Msk) /*!< TFU1_LOGEXP_LUTP17 Set Value            */
#define TFU_TFU1_LOGEXP_LUTP17_TFU1_LOGEXP_LUTP17_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTP17_TFU1_LOGEXP_LUTP17_Msk) >> TFU_TFU1_LOGEXP_LUTP17_TFU1_LOGEXP_LUTP17_Pos) /*!< TFU1_LOGEXP_LUTP17 Get Value            */

/* TFU1_LOGEXP_LUTP18 bitfield */
#define TFU_TFU1_LOGEXP_LUTP18_TFU1_LOGEXP_LUTP18_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTP18 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTP18_TFU1_LOGEXP_LUTP18_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTP18_TFU1_LOGEXP_LUTP18_Pos)                        /*!< TFU1_LOGEXP_LUTP18 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTP18_TFU1_LOGEXP_LUTP18_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTP18_TFU1_LOGEXP_LUTP18_Pos) & TFU_TFU1_LOGEXP_LUTP18_TFU1_LOGEXP_LUTP18_Msk) /*!< TFU1_LOGEXP_LUTP18 Set Value            */
#define TFU_TFU1_LOGEXP_LUTP18_TFU1_LOGEXP_LUTP18_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTP18_TFU1_LOGEXP_LUTP18_Msk) >> TFU_TFU1_LOGEXP_LUTP18_TFU1_LOGEXP_LUTP18_Pos) /*!< TFU1_LOGEXP_LUTP18 Get Value            */

/* TFU1_LOGEXP_LUTP19 bitfield */
#define TFU_TFU1_LOGEXP_LUTP19_TFU1_LOGEXP_LUTP19_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTP19 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTP19_TFU1_LOGEXP_LUTP19_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTP19_TFU1_LOGEXP_LUTP19_Pos)                        /*!< TFU1_LOGEXP_LUTP19 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTP19_TFU1_LOGEXP_LUTP19_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTP19_TFU1_LOGEXP_LUTP19_Pos) & TFU_TFU1_LOGEXP_LUTP19_TFU1_LOGEXP_LUTP19_Msk) /*!< TFU1_LOGEXP_LUTP19 Set Value            */
#define TFU_TFU1_LOGEXP_LUTP19_TFU1_LOGEXP_LUTP19_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTP19_TFU1_LOGEXP_LUTP19_Msk) >> TFU_TFU1_LOGEXP_LUTP19_TFU1_LOGEXP_LUTP19_Pos) /*!< TFU1_LOGEXP_LUTP19 Get Value            */

/* TFU1_LOGEXP_LUTP20 bitfield */
#define TFU_TFU1_LOGEXP_LUTP20_TFU1_LOGEXP_LUTP20_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTP20 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTP20_TFU1_LOGEXP_LUTP20_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTP20_TFU1_LOGEXP_LUTP20_Pos)                        /*!< TFU1_LOGEXP_LUTP20 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTP20_TFU1_LOGEXP_LUTP20_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTP20_TFU1_LOGEXP_LUTP20_Pos) & TFU_TFU1_LOGEXP_LUTP20_TFU1_LOGEXP_LUTP20_Msk) /*!< TFU1_LOGEXP_LUTP20 Set Value            */
#define TFU_TFU1_LOGEXP_LUTP20_TFU1_LOGEXP_LUTP20_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTP20_TFU1_LOGEXP_LUTP20_Msk) >> TFU_TFU1_LOGEXP_LUTP20_TFU1_LOGEXP_LUTP20_Pos) /*!< TFU1_LOGEXP_LUTP20 Get Value            */

/* TFU1_LOGEXP_LUTP21 bitfield */
#define TFU_TFU1_LOGEXP_LUTP21_TFU1_LOGEXP_LUTP21_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTP21 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTP21_TFU1_LOGEXP_LUTP21_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTP21_TFU1_LOGEXP_LUTP21_Pos)                        /*!< TFU1_LOGEXP_LUTP21 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTP21_TFU1_LOGEXP_LUTP21_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTP21_TFU1_LOGEXP_LUTP21_Pos) & TFU_TFU1_LOGEXP_LUTP21_TFU1_LOGEXP_LUTP21_Msk) /*!< TFU1_LOGEXP_LUTP21 Set Value            */
#define TFU_TFU1_LOGEXP_LUTP21_TFU1_LOGEXP_LUTP21_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTP21_TFU1_LOGEXP_LUTP21_Msk) >> TFU_TFU1_LOGEXP_LUTP21_TFU1_LOGEXP_LUTP21_Pos) /*!< TFU1_LOGEXP_LUTP21 Get Value            */

/* TFU1_LOGEXP_LUTP22 bitfield */
#define TFU_TFU1_LOGEXP_LUTP22_TFU1_LOGEXP_LUTP22_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTP22 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTP22_TFU1_LOGEXP_LUTP22_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTP22_TFU1_LOGEXP_LUTP22_Pos)                        /*!< TFU1_LOGEXP_LUTP22 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTP22_TFU1_LOGEXP_LUTP22_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTP22_TFU1_LOGEXP_LUTP22_Pos) & TFU_TFU1_LOGEXP_LUTP22_TFU1_LOGEXP_LUTP22_Msk) /*!< TFU1_LOGEXP_LUTP22 Set Value            */
#define TFU_TFU1_LOGEXP_LUTP22_TFU1_LOGEXP_LUTP22_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTP22_TFU1_LOGEXP_LUTP22_Msk) >> TFU_TFU1_LOGEXP_LUTP22_TFU1_LOGEXP_LUTP22_Pos) /*!< TFU1_LOGEXP_LUTP22 Get Value            */

/* TFU1_LOGEXP_LUTP23 bitfield */
#define TFU_TFU1_LOGEXP_LUTP23_TFU1_LOGEXP_LUTP23_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTP23 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTP23_TFU1_LOGEXP_LUTP23_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTP23_TFU1_LOGEXP_LUTP23_Pos)                        /*!< TFU1_LOGEXP_LUTP23 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTP23_TFU1_LOGEXP_LUTP23_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTP23_TFU1_LOGEXP_LUTP23_Pos) & TFU_TFU1_LOGEXP_LUTP23_TFU1_LOGEXP_LUTP23_Msk) /*!< TFU1_LOGEXP_LUTP23 Set Value            */
#define TFU_TFU1_LOGEXP_LUTP23_TFU1_LOGEXP_LUTP23_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTP23_TFU1_LOGEXP_LUTP23_Msk) >> TFU_TFU1_LOGEXP_LUTP23_TFU1_LOGEXP_LUTP23_Pos) /*!< TFU1_LOGEXP_LUTP23 Get Value            */

/* TFU1_LOGEXP_LUTP24 bitfield */
#define TFU_TFU1_LOGEXP_LUTP24_TFU1_LOGEXP_LUTP24_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTP24 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTP24_TFU1_LOGEXP_LUTP24_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTP24_TFU1_LOGEXP_LUTP24_Pos)                        /*!< TFU1_LOGEXP_LUTP24 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTP24_TFU1_LOGEXP_LUTP24_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTP24_TFU1_LOGEXP_LUTP24_Pos) & TFU_TFU1_LOGEXP_LUTP24_TFU1_LOGEXP_LUTP24_Msk) /*!< TFU1_LOGEXP_LUTP24 Set Value            */
#define TFU_TFU1_LOGEXP_LUTP24_TFU1_LOGEXP_LUTP24_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTP24_TFU1_LOGEXP_LUTP24_Msk) >> TFU_TFU1_LOGEXP_LUTP24_TFU1_LOGEXP_LUTP24_Pos) /*!< TFU1_LOGEXP_LUTP24 Get Value            */

/* TFU1_LOGEXP_LUTM01 bitfield */
#define TFU_TFU1_LOGEXP_LUTM01_TFU1_LOGEXP_LUTM01_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTM01 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTM01_TFU1_LOGEXP_LUTM01_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTM01_TFU1_LOGEXP_LUTM01_Pos)                        /*!< TFU1_LOGEXP_LUTM01 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTM01_TFU1_LOGEXP_LUTM01_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTM01_TFU1_LOGEXP_LUTM01_Pos) & TFU_TFU1_LOGEXP_LUTM01_TFU1_LOGEXP_LUTM01_Msk) /*!< TFU1_LOGEXP_LUTM01 Set Value            */
#define TFU_TFU1_LOGEXP_LUTM01_TFU1_LOGEXP_LUTM01_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTM01_TFU1_LOGEXP_LUTM01_Msk) >> TFU_TFU1_LOGEXP_LUTM01_TFU1_LOGEXP_LUTM01_Pos) /*!< TFU1_LOGEXP_LUTM01 Get Value            */

/* TFU1_LOGEXP_LUTM02 bitfield */
#define TFU_TFU1_LOGEXP_LUTM02_TFU1_LOGEXP_LUTM02_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTM02 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTM02_TFU1_LOGEXP_LUTM02_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTM02_TFU1_LOGEXP_LUTM02_Pos)                        /*!< TFU1_LOGEXP_LUTM02 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTM02_TFU1_LOGEXP_LUTM02_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTM02_TFU1_LOGEXP_LUTM02_Pos) & TFU_TFU1_LOGEXP_LUTM02_TFU1_LOGEXP_LUTM02_Msk) /*!< TFU1_LOGEXP_LUTM02 Set Value            */
#define TFU_TFU1_LOGEXP_LUTM02_TFU1_LOGEXP_LUTM02_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTM02_TFU1_LOGEXP_LUTM02_Msk) >> TFU_TFU1_LOGEXP_LUTM02_TFU1_LOGEXP_LUTM02_Pos) /*!< TFU1_LOGEXP_LUTM02 Get Value            */

/* TFU1_LOGEXP_LUTM03 bitfield */
#define TFU_TFU1_LOGEXP_LUTM03_TFU1_LOGEXP_LUTM03_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTM03 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTM03_TFU1_LOGEXP_LUTM03_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTM03_TFU1_LOGEXP_LUTM03_Pos)                        /*!< TFU1_LOGEXP_LUTM03 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTM03_TFU1_LOGEXP_LUTM03_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTM03_TFU1_LOGEXP_LUTM03_Pos) & TFU_TFU1_LOGEXP_LUTM03_TFU1_LOGEXP_LUTM03_Msk) /*!< TFU1_LOGEXP_LUTM03 Set Value            */
#define TFU_TFU1_LOGEXP_LUTM03_TFU1_LOGEXP_LUTM03_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTM03_TFU1_LOGEXP_LUTM03_Msk) >> TFU_TFU1_LOGEXP_LUTM03_TFU1_LOGEXP_LUTM03_Pos) /*!< TFU1_LOGEXP_LUTM03 Get Value            */

/* TFU1_LOGEXP_LUTM04 bitfield */
#define TFU_TFU1_LOGEXP_LUTM04_TFU1_LOGEXP_LUTM04_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTM04 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTM04_TFU1_LOGEXP_LUTM04_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTM04_TFU1_LOGEXP_LUTM04_Pos)                        /*!< TFU1_LOGEXP_LUTM04 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTM04_TFU1_LOGEXP_LUTM04_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTM04_TFU1_LOGEXP_LUTM04_Pos) & TFU_TFU1_LOGEXP_LUTM04_TFU1_LOGEXP_LUTM04_Msk) /*!< TFU1_LOGEXP_LUTM04 Set Value            */
#define TFU_TFU1_LOGEXP_LUTM04_TFU1_LOGEXP_LUTM04_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTM04_TFU1_LOGEXP_LUTM04_Msk) >> TFU_TFU1_LOGEXP_LUTM04_TFU1_LOGEXP_LUTM04_Pos) /*!< TFU1_LOGEXP_LUTM04 Get Value            */

/* TFU1_LOGEXP_LUTM05 bitfield */
#define TFU_TFU1_LOGEXP_LUTM05_TFU1_LOGEXP_LUTM05_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTM05 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTM05_TFU1_LOGEXP_LUTM05_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTM05_TFU1_LOGEXP_LUTM05_Pos)                        /*!< TFU1_LOGEXP_LUTM05 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTM05_TFU1_LOGEXP_LUTM05_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTM05_TFU1_LOGEXP_LUTM05_Pos) & TFU_TFU1_LOGEXP_LUTM05_TFU1_LOGEXP_LUTM05_Msk) /*!< TFU1_LOGEXP_LUTM05 Set Value            */
#define TFU_TFU1_LOGEXP_LUTM05_TFU1_LOGEXP_LUTM05_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTM05_TFU1_LOGEXP_LUTM05_Msk) >> TFU_TFU1_LOGEXP_LUTM05_TFU1_LOGEXP_LUTM05_Pos) /*!< TFU1_LOGEXP_LUTM05 Get Value            */

/* TFU1_LOGEXP_LUTM06 bitfield */
#define TFU_TFU1_LOGEXP_LUTM06_TFU1_LOGEXP_LUTM06_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTM06 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTM06_TFU1_LOGEXP_LUTM06_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTM06_TFU1_LOGEXP_LUTM06_Pos)                        /*!< TFU1_LOGEXP_LUTM06 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTM06_TFU1_LOGEXP_LUTM06_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTM06_TFU1_LOGEXP_LUTM06_Pos) & TFU_TFU1_LOGEXP_LUTM06_TFU1_LOGEXP_LUTM06_Msk) /*!< TFU1_LOGEXP_LUTM06 Set Value            */
#define TFU_TFU1_LOGEXP_LUTM06_TFU1_LOGEXP_LUTM06_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTM06_TFU1_LOGEXP_LUTM06_Msk) >> TFU_TFU1_LOGEXP_LUTM06_TFU1_LOGEXP_LUTM06_Pos) /*!< TFU1_LOGEXP_LUTM06 Get Value            */

/* TFU1_LOGEXP_LUTM07 bitfield */
#define TFU_TFU1_LOGEXP_LUTM07_TFU1_LOGEXP_LUTM07_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTM07 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTM07_TFU1_LOGEXP_LUTM07_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTM07_TFU1_LOGEXP_LUTM07_Pos)                        /*!< TFU1_LOGEXP_LUTM07 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTM07_TFU1_LOGEXP_LUTM07_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTM07_TFU1_LOGEXP_LUTM07_Pos) & TFU_TFU1_LOGEXP_LUTM07_TFU1_LOGEXP_LUTM07_Msk) /*!< TFU1_LOGEXP_LUTM07 Set Value            */
#define TFU_TFU1_LOGEXP_LUTM07_TFU1_LOGEXP_LUTM07_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTM07_TFU1_LOGEXP_LUTM07_Msk) >> TFU_TFU1_LOGEXP_LUTM07_TFU1_LOGEXP_LUTM07_Pos) /*!< TFU1_LOGEXP_LUTM07 Get Value            */

/* TFU1_LOGEXP_LUTM08 bitfield */
#define TFU_TFU1_LOGEXP_LUTM08_TFU1_LOGEXP_LUTM08_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTM08 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTM08_TFU1_LOGEXP_LUTM08_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTM08_TFU1_LOGEXP_LUTM08_Pos)                        /*!< TFU1_LOGEXP_LUTM08 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTM08_TFU1_LOGEXP_LUTM08_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTM08_TFU1_LOGEXP_LUTM08_Pos) & TFU_TFU1_LOGEXP_LUTM08_TFU1_LOGEXP_LUTM08_Msk) /*!< TFU1_LOGEXP_LUTM08 Set Value            */
#define TFU_TFU1_LOGEXP_LUTM08_TFU1_LOGEXP_LUTM08_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTM08_TFU1_LOGEXP_LUTM08_Msk) >> TFU_TFU1_LOGEXP_LUTM08_TFU1_LOGEXP_LUTM08_Pos) /*!< TFU1_LOGEXP_LUTM08 Get Value            */

/* TFU1_LOGEXP_LUTM09 bitfield */
#define TFU_TFU1_LOGEXP_LUTM09_TFU1_LOGEXP_LUTM09_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTM09 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTM09_TFU1_LOGEXP_LUTM09_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTM09_TFU1_LOGEXP_LUTM09_Pos)                        /*!< TFU1_LOGEXP_LUTM09 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTM09_TFU1_LOGEXP_LUTM09_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTM09_TFU1_LOGEXP_LUTM09_Pos) & TFU_TFU1_LOGEXP_LUTM09_TFU1_LOGEXP_LUTM09_Msk) /*!< TFU1_LOGEXP_LUTM09 Set Value            */
#define TFU_TFU1_LOGEXP_LUTM09_TFU1_LOGEXP_LUTM09_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTM09_TFU1_LOGEXP_LUTM09_Msk) >> TFU_TFU1_LOGEXP_LUTM09_TFU1_LOGEXP_LUTM09_Pos) /*!< TFU1_LOGEXP_LUTM09 Get Value            */

/* TFU1_LOGEXP_LUTM10 bitfield */
#define TFU_TFU1_LOGEXP_LUTM10_TFU1_LOGEXP_LUTM10_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTM10 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTM10_TFU1_LOGEXP_LUTM10_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTM10_TFU1_LOGEXP_LUTM10_Pos)                        /*!< TFU1_LOGEXP_LUTM10 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTM10_TFU1_LOGEXP_LUTM10_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTM10_TFU1_LOGEXP_LUTM10_Pos) & TFU_TFU1_LOGEXP_LUTM10_TFU1_LOGEXP_LUTM10_Msk) /*!< TFU1_LOGEXP_LUTM10 Set Value            */
#define TFU_TFU1_LOGEXP_LUTM10_TFU1_LOGEXP_LUTM10_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTM10_TFU1_LOGEXP_LUTM10_Msk) >> TFU_TFU1_LOGEXP_LUTM10_TFU1_LOGEXP_LUTM10_Pos) /*!< TFU1_LOGEXP_LUTM10 Get Value            */

/* TFU1_LOGEXP_LUTM11 bitfield */
#define TFU_TFU1_LOGEXP_LUTM11_TFU1_LOGEXP_LUTM11_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTM11 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTM11_TFU1_LOGEXP_LUTM11_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTM11_TFU1_LOGEXP_LUTM11_Pos)                        /*!< TFU1_LOGEXP_LUTM11 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTM11_TFU1_LOGEXP_LUTM11_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTM11_TFU1_LOGEXP_LUTM11_Pos) & TFU_TFU1_LOGEXP_LUTM11_TFU1_LOGEXP_LUTM11_Msk) /*!< TFU1_LOGEXP_LUTM11 Set Value            */
#define TFU_TFU1_LOGEXP_LUTM11_TFU1_LOGEXP_LUTM11_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTM11_TFU1_LOGEXP_LUTM11_Msk) >> TFU_TFU1_LOGEXP_LUTM11_TFU1_LOGEXP_LUTM11_Pos) /*!< TFU1_LOGEXP_LUTM11 Get Value            */

/* TFU1_LOGEXP_LUTM12 bitfield */
#define TFU_TFU1_LOGEXP_LUTM12_TFU1_LOGEXP_LUTM12_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTM12 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTM12_TFU1_LOGEXP_LUTM12_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTM12_TFU1_LOGEXP_LUTM12_Pos)                        /*!< TFU1_LOGEXP_LUTM12 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTM12_TFU1_LOGEXP_LUTM12_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTM12_TFU1_LOGEXP_LUTM12_Pos) & TFU_TFU1_LOGEXP_LUTM12_TFU1_LOGEXP_LUTM12_Msk) /*!< TFU1_LOGEXP_LUTM12 Set Value            */
#define TFU_TFU1_LOGEXP_LUTM12_TFU1_LOGEXP_LUTM12_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTM12_TFU1_LOGEXP_LUTM12_Msk) >> TFU_TFU1_LOGEXP_LUTM12_TFU1_LOGEXP_LUTM12_Pos) /*!< TFU1_LOGEXP_LUTM12 Get Value            */

/* TFU1_LOGEXP_LUTM13 bitfield */
#define TFU_TFU1_LOGEXP_LUTM13_TFU1_LOGEXP_LUTM13_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTM13 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTM13_TFU1_LOGEXP_LUTM13_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTM13_TFU1_LOGEXP_LUTM13_Pos)                        /*!< TFU1_LOGEXP_LUTM13 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTM13_TFU1_LOGEXP_LUTM13_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTM13_TFU1_LOGEXP_LUTM13_Pos) & TFU_TFU1_LOGEXP_LUTM13_TFU1_LOGEXP_LUTM13_Msk) /*!< TFU1_LOGEXP_LUTM13 Set Value            */
#define TFU_TFU1_LOGEXP_LUTM13_TFU1_LOGEXP_LUTM13_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTM13_TFU1_LOGEXP_LUTM13_Msk) >> TFU_TFU1_LOGEXP_LUTM13_TFU1_LOGEXP_LUTM13_Pos) /*!< TFU1_LOGEXP_LUTM13 Get Value            */

/* TFU1_LOGEXP_LUTM14 bitfield */
#define TFU_TFU1_LOGEXP_LUTM14_TFU1_LOGEXP_LUTM14_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTM14 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTM14_TFU1_LOGEXP_LUTM14_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTM14_TFU1_LOGEXP_LUTM14_Pos)                        /*!< TFU1_LOGEXP_LUTM14 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTM14_TFU1_LOGEXP_LUTM14_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTM14_TFU1_LOGEXP_LUTM14_Pos) & TFU_TFU1_LOGEXP_LUTM14_TFU1_LOGEXP_LUTM14_Msk) /*!< TFU1_LOGEXP_LUTM14 Set Value            */
#define TFU_TFU1_LOGEXP_LUTM14_TFU1_LOGEXP_LUTM14_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTM14_TFU1_LOGEXP_LUTM14_Msk) >> TFU_TFU1_LOGEXP_LUTM14_TFU1_LOGEXP_LUTM14_Pos) /*!< TFU1_LOGEXP_LUTM14 Get Value            */

/* TFU1_LOGEXP_LUTM15 bitfield */
#define TFU_TFU1_LOGEXP_LUTM15_TFU1_LOGEXP_LUTM15_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTM15 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTM15_TFU1_LOGEXP_LUTM15_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTM15_TFU1_LOGEXP_LUTM15_Pos)                        /*!< TFU1_LOGEXP_LUTM15 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTM15_TFU1_LOGEXP_LUTM15_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTM15_TFU1_LOGEXP_LUTM15_Pos) & TFU_TFU1_LOGEXP_LUTM15_TFU1_LOGEXP_LUTM15_Msk) /*!< TFU1_LOGEXP_LUTM15 Set Value            */
#define TFU_TFU1_LOGEXP_LUTM15_TFU1_LOGEXP_LUTM15_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTM15_TFU1_LOGEXP_LUTM15_Msk) >> TFU_TFU1_LOGEXP_LUTM15_TFU1_LOGEXP_LUTM15_Pos) /*!< TFU1_LOGEXP_LUTM15 Get Value            */

/* TFU1_LOGEXP_LUTM16 bitfield */
#define TFU_TFU1_LOGEXP_LUTM16_TFU1_LOGEXP_LUTM16_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTM16 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTM16_TFU1_LOGEXP_LUTM16_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTM16_TFU1_LOGEXP_LUTM16_Pos)                        /*!< TFU1_LOGEXP_LUTM16 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTM16_TFU1_LOGEXP_LUTM16_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTM16_TFU1_LOGEXP_LUTM16_Pos) & TFU_TFU1_LOGEXP_LUTM16_TFU1_LOGEXP_LUTM16_Msk) /*!< TFU1_LOGEXP_LUTM16 Set Value            */
#define TFU_TFU1_LOGEXP_LUTM16_TFU1_LOGEXP_LUTM16_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTM16_TFU1_LOGEXP_LUTM16_Msk) >> TFU_TFU1_LOGEXP_LUTM16_TFU1_LOGEXP_LUTM16_Pos) /*!< TFU1_LOGEXP_LUTM16 Get Value            */

/* TFU1_LOGEXP_LUTM17 bitfield */
#define TFU_TFU1_LOGEXP_LUTM17_TFU1_LOGEXP_LUTM17_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTM17 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTM17_TFU1_LOGEXP_LUTM17_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTM17_TFU1_LOGEXP_LUTM17_Pos)                        /*!< TFU1_LOGEXP_LUTM17 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTM17_TFU1_LOGEXP_LUTM17_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTM17_TFU1_LOGEXP_LUTM17_Pos) & TFU_TFU1_LOGEXP_LUTM17_TFU1_LOGEXP_LUTM17_Msk) /*!< TFU1_LOGEXP_LUTM17 Set Value            */
#define TFU_TFU1_LOGEXP_LUTM17_TFU1_LOGEXP_LUTM17_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTM17_TFU1_LOGEXP_LUTM17_Msk) >> TFU_TFU1_LOGEXP_LUTM17_TFU1_LOGEXP_LUTM17_Pos) /*!< TFU1_LOGEXP_LUTM17 Get Value            */

/* TFU1_LOGEXP_LUTM18 bitfield */
#define TFU_TFU1_LOGEXP_LUTM18_TFU1_LOGEXP_LUTM18_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTM18 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTM18_TFU1_LOGEXP_LUTM18_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTM18_TFU1_LOGEXP_LUTM18_Pos)                        /*!< TFU1_LOGEXP_LUTM18 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTM18_TFU1_LOGEXP_LUTM18_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTM18_TFU1_LOGEXP_LUTM18_Pos) & TFU_TFU1_LOGEXP_LUTM18_TFU1_LOGEXP_LUTM18_Msk) /*!< TFU1_LOGEXP_LUTM18 Set Value            */
#define TFU_TFU1_LOGEXP_LUTM18_TFU1_LOGEXP_LUTM18_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTM18_TFU1_LOGEXP_LUTM18_Msk) >> TFU_TFU1_LOGEXP_LUTM18_TFU1_LOGEXP_LUTM18_Pos) /*!< TFU1_LOGEXP_LUTM18 Get Value            */

/* TFU1_LOGEXP_LUTM19 bitfield */
#define TFU_TFU1_LOGEXP_LUTM19_TFU1_LOGEXP_LUTM19_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTM19 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTM19_TFU1_LOGEXP_LUTM19_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTM19_TFU1_LOGEXP_LUTM19_Pos)                        /*!< TFU1_LOGEXP_LUTM19 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTM19_TFU1_LOGEXP_LUTM19_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTM19_TFU1_LOGEXP_LUTM19_Pos) & TFU_TFU1_LOGEXP_LUTM19_TFU1_LOGEXP_LUTM19_Msk) /*!< TFU1_LOGEXP_LUTM19 Set Value            */
#define TFU_TFU1_LOGEXP_LUTM19_TFU1_LOGEXP_LUTM19_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTM19_TFU1_LOGEXP_LUTM19_Msk) >> TFU_TFU1_LOGEXP_LUTM19_TFU1_LOGEXP_LUTM19_Pos) /*!< TFU1_LOGEXP_LUTM19 Get Value            */

/* TFU1_LOGEXP_LUTM20 bitfield */
#define TFU_TFU1_LOGEXP_LUTM20_TFU1_LOGEXP_LUTM20_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTM20 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTM20_TFU1_LOGEXP_LUTM20_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTM20_TFU1_LOGEXP_LUTM20_Pos)                        /*!< TFU1_LOGEXP_LUTM20 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTM20_TFU1_LOGEXP_LUTM20_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTM20_TFU1_LOGEXP_LUTM20_Pos) & TFU_TFU1_LOGEXP_LUTM20_TFU1_LOGEXP_LUTM20_Msk) /*!< TFU1_LOGEXP_LUTM20 Set Value            */
#define TFU_TFU1_LOGEXP_LUTM20_TFU1_LOGEXP_LUTM20_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTM20_TFU1_LOGEXP_LUTM20_Msk) >> TFU_TFU1_LOGEXP_LUTM20_TFU1_LOGEXP_LUTM20_Pos) /*!< TFU1_LOGEXP_LUTM20 Get Value            */

/* TFU1_LOGEXP_LUTM21 bitfield */
#define TFU_TFU1_LOGEXP_LUTM21_TFU1_LOGEXP_LUTM21_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTM21 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTM21_TFU1_LOGEXP_LUTM21_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTM21_TFU1_LOGEXP_LUTM21_Pos)                        /*!< TFU1_LOGEXP_LUTM21 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTM21_TFU1_LOGEXP_LUTM21_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTM21_TFU1_LOGEXP_LUTM21_Pos) & TFU_TFU1_LOGEXP_LUTM21_TFU1_LOGEXP_LUTM21_Msk) /*!< TFU1_LOGEXP_LUTM21 Set Value            */
#define TFU_TFU1_LOGEXP_LUTM21_TFU1_LOGEXP_LUTM21_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTM21_TFU1_LOGEXP_LUTM21_Msk) >> TFU_TFU1_LOGEXP_LUTM21_TFU1_LOGEXP_LUTM21_Pos) /*!< TFU1_LOGEXP_LUTM21 Get Value            */

/* TFU1_LOGEXP_LUTM22 bitfield */
#define TFU_TFU1_LOGEXP_LUTM22_TFU1_LOGEXP_LUTM22_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTM22 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTM22_TFU1_LOGEXP_LUTM22_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTM22_TFU1_LOGEXP_LUTM22_Pos)                        /*!< TFU1_LOGEXP_LUTM22 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTM22_TFU1_LOGEXP_LUTM22_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTM22_TFU1_LOGEXP_LUTM22_Pos) & TFU_TFU1_LOGEXP_LUTM22_TFU1_LOGEXP_LUTM22_Msk) /*!< TFU1_LOGEXP_LUTM22 Set Value            */
#define TFU_TFU1_LOGEXP_LUTM22_TFU1_LOGEXP_LUTM22_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTM22_TFU1_LOGEXP_LUTM22_Msk) >> TFU_TFU1_LOGEXP_LUTM22_TFU1_LOGEXP_LUTM22_Pos) /*!< TFU1_LOGEXP_LUTM22 Get Value            */

/* TFU1_LOGEXP_LUTM23 bitfield */
#define TFU_TFU1_LOGEXP_LUTM23_TFU1_LOGEXP_LUTM23_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTM23 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTM23_TFU1_LOGEXP_LUTM23_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTM23_TFU1_LOGEXP_LUTM23_Pos)                        /*!< TFU1_LOGEXP_LUTM23 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTM23_TFU1_LOGEXP_LUTM23_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTM23_TFU1_LOGEXP_LUTM23_Pos) & TFU_TFU1_LOGEXP_LUTM23_TFU1_LOGEXP_LUTM23_Msk) /*!< TFU1_LOGEXP_LUTM23 Set Value            */
#define TFU_TFU1_LOGEXP_LUTM23_TFU1_LOGEXP_LUTM23_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTM23_TFU1_LOGEXP_LUTM23_Msk) >> TFU_TFU1_LOGEXP_LUTM23_TFU1_LOGEXP_LUTM23_Pos) /*!< TFU1_LOGEXP_LUTM23 Get Value            */

/* TFU1_LOGEXP_LUTM24 bitfield */
#define TFU_TFU1_LOGEXP_LUTM24_TFU1_LOGEXP_LUTM24_Pos    (0U)                                                                                  /*!< TFU1_LOGEXP_LUTM24 Position  0          */ 
#define TFU_TFU1_LOGEXP_LUTM24_TFU1_LOGEXP_LUTM24_Msk    (0xffffffffU << TFU_TFU1_LOGEXP_LUTM24_TFU1_LOGEXP_LUTM24_Pos)                        /*!< TFU1_LOGEXP_LUTM24 Mask      0xFFFFFFFF */
#define TFU_TFU1_LOGEXP_LUTM24_TFU1_LOGEXP_LUTM24_Set(x) (((uint32_t) (x) << TFU_TFU1_LOGEXP_LUTM24_TFU1_LOGEXP_LUTM24_Pos) & TFU_TFU1_LOGEXP_LUTM24_TFU1_LOGEXP_LUTM24_Msk) /*!< TFU1_LOGEXP_LUTM24 Set Value            */
#define TFU_TFU1_LOGEXP_LUTM24_TFU1_LOGEXP_LUTM24_Get(x) (((uint32_t) (x) & TFU_TFU1_LOGEXP_LUTM24_TFU1_LOGEXP_LUTM24_Msk) >> TFU_TFU1_LOGEXP_LUTM24_TFU1_LOGEXP_LUTM24_Pos) /*!< TFU1_LOGEXP_LUTM24 Get Value            */

/* TFU_INT_FLAGS bitfield */
#define TFU_TFU_INT_FLAGS_TFU0_TRD0_INT_REQ_Pos    (23U)                                                                                 /*!< TFU0_TRD0_INT_REQ Position  23         */ 
#define TFU_TFU_INT_FLAGS_TFU0_TRD0_INT_REQ_Msk    (0x1U << TFU_TFU_INT_FLAGS_TFU0_TRD0_INT_REQ_Pos)                                     /*!< TFU0_TRD0_INT_REQ Mask      0x00800000 */
#define TFU_TFU_INT_FLAGS_TFU0_TRD0_INT_REQ_Set(x) (((uint32_t) (x) << TFU_TFU_INT_FLAGS_TFU0_TRD0_INT_REQ_Pos) & TFU_TFU_INT_FLAGS_TFU0_TRD0_INT_REQ_Msk) /*!< TFU0_TRD0_INT_REQ Set Value            */
#define TFU_TFU_INT_FLAGS_TFU0_TRD0_INT_REQ_Get(x) (((uint32_t) (x) & TFU_TFU_INT_FLAGS_TFU0_TRD0_INT_REQ_Msk) >> TFU_TFU_INT_FLAGS_TFU0_TRD0_INT_REQ_Pos) /*!< TFU0_TRD0_INT_REQ Get Value            */

#define TFU_TFU_INT_FLAGS_TFU0_TRD1_INT_REQ_Pos    (22U)                                                                                 /*!< TFU0_TRD1_INT_REQ Position  22         */ 
#define TFU_TFU_INT_FLAGS_TFU0_TRD1_INT_REQ_Msk    (0x1U << TFU_TFU_INT_FLAGS_TFU0_TRD1_INT_REQ_Pos)                                     /*!< TFU0_TRD1_INT_REQ Mask      0x00400000 */
#define TFU_TFU_INT_FLAGS_TFU0_TRD1_INT_REQ_Set(x) (((uint32_t) (x) << TFU_TFU_INT_FLAGS_TFU0_TRD1_INT_REQ_Pos) & TFU_TFU_INT_FLAGS_TFU0_TRD1_INT_REQ_Msk) /*!< TFU0_TRD1_INT_REQ Set Value            */
#define TFU_TFU_INT_FLAGS_TFU0_TRD1_INT_REQ_Get(x) (((uint32_t) (x) & TFU_TFU_INT_FLAGS_TFU0_TRD1_INT_REQ_Msk) >> TFU_TFU_INT_FLAGS_TFU0_TRD1_INT_REQ_Pos) /*!< TFU0_TRD1_INT_REQ Get Value            */

#define TFU_TFU_INT_FLAGS_TFU0_TRD2_INT_REQ_Pos    (21U)                                                                                 /*!< TFU0_TRD2_INT_REQ Position  21         */ 
#define TFU_TFU_INT_FLAGS_TFU0_TRD2_INT_REQ_Msk    (0x1U << TFU_TFU_INT_FLAGS_TFU0_TRD2_INT_REQ_Pos)                                     /*!< TFU0_TRD2_INT_REQ Mask      0x00200000 */
#define TFU_TFU_INT_FLAGS_TFU0_TRD2_INT_REQ_Set(x) (((uint32_t) (x) << TFU_TFU_INT_FLAGS_TFU0_TRD2_INT_REQ_Pos) & TFU_TFU_INT_FLAGS_TFU0_TRD2_INT_REQ_Msk) /*!< TFU0_TRD2_INT_REQ Set Value            */
#define TFU_TFU_INT_FLAGS_TFU0_TRD2_INT_REQ_Get(x) (((uint32_t) (x) & TFU_TFU_INT_FLAGS_TFU0_TRD2_INT_REQ_Msk) >> TFU_TFU_INT_FLAGS_TFU0_TRD2_INT_REQ_Pos) /*!< TFU0_TRD2_INT_REQ Get Value            */

#define TFU_TFU_INT_FLAGS_TFU0_TRD3_INT_REQ_Pos    (20U)                                                                                 /*!< TFU0_TRD3_INT_REQ Position  20         */ 
#define TFU_TFU_INT_FLAGS_TFU0_TRD3_INT_REQ_Msk    (0x1U << TFU_TFU_INT_FLAGS_TFU0_TRD3_INT_REQ_Pos)                                     /*!< TFU0_TRD3_INT_REQ Mask      0x00100000 */
#define TFU_TFU_INT_FLAGS_TFU0_TRD3_INT_REQ_Set(x) (((uint32_t) (x) << TFU_TFU_INT_FLAGS_TFU0_TRD3_INT_REQ_Pos) & TFU_TFU_INT_FLAGS_TFU0_TRD3_INT_REQ_Msk) /*!< TFU0_TRD3_INT_REQ Set Value            */
#define TFU_TFU_INT_FLAGS_TFU0_TRD3_INT_REQ_Get(x) (((uint32_t) (x) & TFU_TFU_INT_FLAGS_TFU0_TRD3_INT_REQ_Msk) >> TFU_TFU_INT_FLAGS_TFU0_TRD3_INT_REQ_Pos) /*!< TFU0_TRD3_INT_REQ Get Value            */

#define TFU_TFU_INT_FLAGS_TFU0_TRD0_INT_REQ_UF_Pos    (19U)                                                                                 /*!< TFU0_TRD0_INT_REQ_UF Position  19         */ 
#define TFU_TFU_INT_FLAGS_TFU0_TRD0_INT_REQ_UF_Msk    (0x1U << TFU_TFU_INT_FLAGS_TFU0_TRD0_INT_REQ_UF_Pos)                                  /*!< TFU0_TRD0_INT_REQ_UF Mask      0x00080000 */
#define TFU_TFU_INT_FLAGS_TFU0_TRD0_INT_REQ_UF_Set(x) (((uint32_t) (x) << TFU_TFU_INT_FLAGS_TFU0_TRD0_INT_REQ_UF_Pos) & TFU_TFU_INT_FLAGS_TFU0_TRD0_INT_REQ_UF_Msk) /*!< TFU0_TRD0_INT_REQ_UF Set Value            */
#define TFU_TFU_INT_FLAGS_TFU0_TRD0_INT_REQ_UF_Get(x) (((uint32_t) (x) & TFU_TFU_INT_FLAGS_TFU0_TRD0_INT_REQ_UF_Msk) >> TFU_TFU_INT_FLAGS_TFU0_TRD0_INT_REQ_UF_Pos) /*!< TFU0_TRD0_INT_REQ_UF Get Value            */

#define TFU_TFU_INT_FLAGS_TFU0_TRD1_INT_REQ_UF_Pos    (18U)                                                                                 /*!< TFU0_TRD1_INT_REQ_UF Position  18         */ 
#define TFU_TFU_INT_FLAGS_TFU0_TRD1_INT_REQ_UF_Msk    (0x1U << TFU_TFU_INT_FLAGS_TFU0_TRD1_INT_REQ_UF_Pos)                                  /*!< TFU0_TRD1_INT_REQ_UF Mask      0x00040000 */
#define TFU_TFU_INT_FLAGS_TFU0_TRD1_INT_REQ_UF_Set(x) (((uint32_t) (x) << TFU_TFU_INT_FLAGS_TFU0_TRD1_INT_REQ_UF_Pos) & TFU_TFU_INT_FLAGS_TFU0_TRD1_INT_REQ_UF_Msk) /*!< TFU0_TRD1_INT_REQ_UF Set Value            */
#define TFU_TFU_INT_FLAGS_TFU0_TRD1_INT_REQ_UF_Get(x) (((uint32_t) (x) & TFU_TFU_INT_FLAGS_TFU0_TRD1_INT_REQ_UF_Msk) >> TFU_TFU_INT_FLAGS_TFU0_TRD1_INT_REQ_UF_Pos) /*!< TFU0_TRD1_INT_REQ_UF Get Value            */

#define TFU_TFU_INT_FLAGS_TFU0_TRD2_INT_REQ_UF_Pos    (17U)                                                                                 /*!< TFU0_TRD2_INT_REQ_UF Position  17         */ 
#define TFU_TFU_INT_FLAGS_TFU0_TRD2_INT_REQ_UF_Msk    (0x1U << TFU_TFU_INT_FLAGS_TFU0_TRD2_INT_REQ_UF_Pos)                                  /*!< TFU0_TRD2_INT_REQ_UF Mask      0x00020000 */
#define TFU_TFU_INT_FLAGS_TFU0_TRD2_INT_REQ_UF_Set(x) (((uint32_t) (x) << TFU_TFU_INT_FLAGS_TFU0_TRD2_INT_REQ_UF_Pos) & TFU_TFU_INT_FLAGS_TFU0_TRD2_INT_REQ_UF_Msk) /*!< TFU0_TRD2_INT_REQ_UF Set Value            */
#define TFU_TFU_INT_FLAGS_TFU0_TRD2_INT_REQ_UF_Get(x) (((uint32_t) (x) & TFU_TFU_INT_FLAGS_TFU0_TRD2_INT_REQ_UF_Msk) >> TFU_TFU_INT_FLAGS_TFU0_TRD2_INT_REQ_UF_Pos) /*!< TFU0_TRD2_INT_REQ_UF Get Value            */

#define TFU_TFU_INT_FLAGS_TFU0_TRD3_INT_REQ_UF_Pos    (16U)                                                                                 /*!< TFU0_TRD3_INT_REQ_UF Position  16         */ 
#define TFU_TFU_INT_FLAGS_TFU0_TRD3_INT_REQ_UF_Msk    (0x1U << TFU_TFU_INT_FLAGS_TFU0_TRD3_INT_REQ_UF_Pos)                                  /*!< TFU0_TRD3_INT_REQ_UF Mask      0x00010000 */
#define TFU_TFU_INT_FLAGS_TFU0_TRD3_INT_REQ_UF_Set(x) (((uint32_t) (x) << TFU_TFU_INT_FLAGS_TFU0_TRD3_INT_REQ_UF_Pos) & TFU_TFU_INT_FLAGS_TFU0_TRD3_INT_REQ_UF_Msk) /*!< TFU0_TRD3_INT_REQ_UF Set Value            */
#define TFU_TFU_INT_FLAGS_TFU0_TRD3_INT_REQ_UF_Get(x) (((uint32_t) (x) & TFU_TFU_INT_FLAGS_TFU0_TRD3_INT_REQ_UF_Msk) >> TFU_TFU_INT_FLAGS_TFU0_TRD3_INT_REQ_UF_Pos) /*!< TFU0_TRD3_INT_REQ_UF Get Value            */

#define TFU_TFU_INT_FLAGS_TFU0_TRD0_INT_REQ_OF_Pos    (15U)                                                                                 /*!< TFU0_TRD0_INT_REQ_OF Position  15         */ 
#define TFU_TFU_INT_FLAGS_TFU0_TRD0_INT_REQ_OF_Msk    (0x1U << TFU_TFU_INT_FLAGS_TFU0_TRD0_INT_REQ_OF_Pos)                                  /*!< TFU0_TRD0_INT_REQ_OF Mask      0x00008000 */
#define TFU_TFU_INT_FLAGS_TFU0_TRD0_INT_REQ_OF_Set(x) (((uint32_t) (x) << TFU_TFU_INT_FLAGS_TFU0_TRD0_INT_REQ_OF_Pos) & TFU_TFU_INT_FLAGS_TFU0_TRD0_INT_REQ_OF_Msk) /*!< TFU0_TRD0_INT_REQ_OF Set Value            */
#define TFU_TFU_INT_FLAGS_TFU0_TRD0_INT_REQ_OF_Get(x) (((uint32_t) (x) & TFU_TFU_INT_FLAGS_TFU0_TRD0_INT_REQ_OF_Msk) >> TFU_TFU_INT_FLAGS_TFU0_TRD0_INT_REQ_OF_Pos) /*!< TFU0_TRD0_INT_REQ_OF Get Value            */

#define TFU_TFU_INT_FLAGS_TFU0_TRD1_INT_REQ_OF_Pos    (14U)                                                                                 /*!< TFU0_TRD1_INT_REQ_OF Position  14         */ 
#define TFU_TFU_INT_FLAGS_TFU0_TRD1_INT_REQ_OF_Msk    (0x1U << TFU_TFU_INT_FLAGS_TFU0_TRD1_INT_REQ_OF_Pos)                                  /*!< TFU0_TRD1_INT_REQ_OF Mask      0x00004000 */
#define TFU_TFU_INT_FLAGS_TFU0_TRD1_INT_REQ_OF_Set(x) (((uint32_t) (x) << TFU_TFU_INT_FLAGS_TFU0_TRD1_INT_REQ_OF_Pos) & TFU_TFU_INT_FLAGS_TFU0_TRD1_INT_REQ_OF_Msk) /*!< TFU0_TRD1_INT_REQ_OF Set Value            */
#define TFU_TFU_INT_FLAGS_TFU0_TRD1_INT_REQ_OF_Get(x) (((uint32_t) (x) & TFU_TFU_INT_FLAGS_TFU0_TRD1_INT_REQ_OF_Msk) >> TFU_TFU_INT_FLAGS_TFU0_TRD1_INT_REQ_OF_Pos) /*!< TFU0_TRD1_INT_REQ_OF Get Value            */

#define TFU_TFU_INT_FLAGS_TFU0_TRD2_INT_REQ_OF_Pos    (13U)                                                                                 /*!< TFU0_TRD2_INT_REQ_OF Position  13         */ 
#define TFU_TFU_INT_FLAGS_TFU0_TRD2_INT_REQ_OF_Msk    (0x1U << TFU_TFU_INT_FLAGS_TFU0_TRD2_INT_REQ_OF_Pos)                                  /*!< TFU0_TRD2_INT_REQ_OF Mask      0x00002000 */
#define TFU_TFU_INT_FLAGS_TFU0_TRD2_INT_REQ_OF_Set(x) (((uint32_t) (x) << TFU_TFU_INT_FLAGS_TFU0_TRD2_INT_REQ_OF_Pos) & TFU_TFU_INT_FLAGS_TFU0_TRD2_INT_REQ_OF_Msk) /*!< TFU0_TRD2_INT_REQ_OF Set Value            */
#define TFU_TFU_INT_FLAGS_TFU0_TRD2_INT_REQ_OF_Get(x) (((uint32_t) (x) & TFU_TFU_INT_FLAGS_TFU0_TRD2_INT_REQ_OF_Msk) >> TFU_TFU_INT_FLAGS_TFU0_TRD2_INT_REQ_OF_Pos) /*!< TFU0_TRD2_INT_REQ_OF Get Value            */

#define TFU_TFU_INT_FLAGS_TFU0_TRD3_INT_REQ_OF_Pos    (12U)                                                                                 /*!< TFU0_TRD3_INT_REQ_OF Position  12         */ 
#define TFU_TFU_INT_FLAGS_TFU0_TRD3_INT_REQ_OF_Msk    (0x1U << TFU_TFU_INT_FLAGS_TFU0_TRD3_INT_REQ_OF_Pos)                                  /*!< TFU0_TRD3_INT_REQ_OF Mask      0x00001000 */
#define TFU_TFU_INT_FLAGS_TFU0_TRD3_INT_REQ_OF_Set(x) (((uint32_t) (x) << TFU_TFU_INT_FLAGS_TFU0_TRD3_INT_REQ_OF_Pos) & TFU_TFU_INT_FLAGS_TFU0_TRD3_INT_REQ_OF_Msk) /*!< TFU0_TRD3_INT_REQ_OF Set Value            */
#define TFU_TFU_INT_FLAGS_TFU0_TRD3_INT_REQ_OF_Get(x) (((uint32_t) (x) & TFU_TFU_INT_FLAGS_TFU0_TRD3_INT_REQ_OF_Msk) >> TFU_TFU_INT_FLAGS_TFU0_TRD3_INT_REQ_OF_Pos) /*!< TFU0_TRD3_INT_REQ_OF Get Value            */

#define TFU_TFU_INT_FLAGS_TFU1_TRD0_INT_REQ_Pos    (11U)                                                                                 /*!< TFU1_TRD0_INT_REQ Position  11         */ 
#define TFU_TFU_INT_FLAGS_TFU1_TRD0_INT_REQ_Msk    (0x1U << TFU_TFU_INT_FLAGS_TFU1_TRD0_INT_REQ_Pos)                                     /*!< TFU1_TRD0_INT_REQ Mask      0x00000800 */
#define TFU_TFU_INT_FLAGS_TFU1_TRD0_INT_REQ_Set(x) (((uint32_t) (x) << TFU_TFU_INT_FLAGS_TFU1_TRD0_INT_REQ_Pos) & TFU_TFU_INT_FLAGS_TFU1_TRD0_INT_REQ_Msk) /*!< TFU1_TRD0_INT_REQ Set Value            */
#define TFU_TFU_INT_FLAGS_TFU1_TRD0_INT_REQ_Get(x) (((uint32_t) (x) & TFU_TFU_INT_FLAGS_TFU1_TRD0_INT_REQ_Msk) >> TFU_TFU_INT_FLAGS_TFU1_TRD0_INT_REQ_Pos) /*!< TFU1_TRD0_INT_REQ Get Value            */

#define TFU_TFU_INT_FLAGS_TFU1_TRD1_INT_REQ_Pos    (10U)                                                                                 /*!< TFU1_TRD1_INT_REQ Position  10         */ 
#define TFU_TFU_INT_FLAGS_TFU1_TRD1_INT_REQ_Msk    (0x1U << TFU_TFU_INT_FLAGS_TFU1_TRD1_INT_REQ_Pos)                                     /*!< TFU1_TRD1_INT_REQ Mask      0x00000400 */
#define TFU_TFU_INT_FLAGS_TFU1_TRD1_INT_REQ_Set(x) (((uint32_t) (x) << TFU_TFU_INT_FLAGS_TFU1_TRD1_INT_REQ_Pos) & TFU_TFU_INT_FLAGS_TFU1_TRD1_INT_REQ_Msk) /*!< TFU1_TRD1_INT_REQ Set Value            */
#define TFU_TFU_INT_FLAGS_TFU1_TRD1_INT_REQ_Get(x) (((uint32_t) (x) & TFU_TFU_INT_FLAGS_TFU1_TRD1_INT_REQ_Msk) >> TFU_TFU_INT_FLAGS_TFU1_TRD1_INT_REQ_Pos) /*!< TFU1_TRD1_INT_REQ Get Value            */

#define TFU_TFU_INT_FLAGS_TFU1_TRD2_INT_REQ_Pos    (9U)                                                                                  /*!< TFU1_TRD2_INT_REQ Position  9          */ 
#define TFU_TFU_INT_FLAGS_TFU1_TRD2_INT_REQ_Msk    (0x1U << TFU_TFU_INT_FLAGS_TFU1_TRD2_INT_REQ_Pos)                                     /*!< TFU1_TRD2_INT_REQ Mask      0x00000200 */
#define TFU_TFU_INT_FLAGS_TFU1_TRD2_INT_REQ_Set(x) (((uint32_t) (x) << TFU_TFU_INT_FLAGS_TFU1_TRD2_INT_REQ_Pos) & TFU_TFU_INT_FLAGS_TFU1_TRD2_INT_REQ_Msk) /*!< TFU1_TRD2_INT_REQ Set Value            */
#define TFU_TFU_INT_FLAGS_TFU1_TRD2_INT_REQ_Get(x) (((uint32_t) (x) & TFU_TFU_INT_FLAGS_TFU1_TRD2_INT_REQ_Msk) >> TFU_TFU_INT_FLAGS_TFU1_TRD2_INT_REQ_Pos) /*!< TFU1_TRD2_INT_REQ Get Value            */

#define TFU_TFU_INT_FLAGS_TFU1_TRD3_INT_REQ_Pos    (8U)                                                                                  /*!< TFU1_TRD3_INT_REQ Position  8          */ 
#define TFU_TFU_INT_FLAGS_TFU1_TRD3_INT_REQ_Msk    (0x1U << TFU_TFU_INT_FLAGS_TFU1_TRD3_INT_REQ_Pos)                                     /*!< TFU1_TRD3_INT_REQ Mask      0x00000100 */
#define TFU_TFU_INT_FLAGS_TFU1_TRD3_INT_REQ_Set(x) (((uint32_t) (x) << TFU_TFU_INT_FLAGS_TFU1_TRD3_INT_REQ_Pos) & TFU_TFU_INT_FLAGS_TFU1_TRD3_INT_REQ_Msk) /*!< TFU1_TRD3_INT_REQ Set Value            */
#define TFU_TFU_INT_FLAGS_TFU1_TRD3_INT_REQ_Get(x) (((uint32_t) (x) & TFU_TFU_INT_FLAGS_TFU1_TRD3_INT_REQ_Msk) >> TFU_TFU_INT_FLAGS_TFU1_TRD3_INT_REQ_Pos) /*!< TFU1_TRD3_INT_REQ Get Value            */

#define TFU_TFU_INT_FLAGS_TFU1_TRD0_INT_REQ_UF_Pos    (7U)                                                                                  /*!< TFU1_TRD0_INT_REQ_UF Position  7          */ 
#define TFU_TFU_INT_FLAGS_TFU1_TRD0_INT_REQ_UF_Msk    (0x1U << TFU_TFU_INT_FLAGS_TFU1_TRD0_INT_REQ_UF_Pos)                                  /*!< TFU1_TRD0_INT_REQ_UF Mask      0x00000080 */
#define TFU_TFU_INT_FLAGS_TFU1_TRD0_INT_REQ_UF_Set(x) (((uint32_t) (x) << TFU_TFU_INT_FLAGS_TFU1_TRD0_INT_REQ_UF_Pos) & TFU_TFU_INT_FLAGS_TFU1_TRD0_INT_REQ_UF_Msk) /*!< TFU1_TRD0_INT_REQ_UF Set Value            */
#define TFU_TFU_INT_FLAGS_TFU1_TRD0_INT_REQ_UF_Get(x) (((uint32_t) (x) & TFU_TFU_INT_FLAGS_TFU1_TRD0_INT_REQ_UF_Msk) >> TFU_TFU_INT_FLAGS_TFU1_TRD0_INT_REQ_UF_Pos) /*!< TFU1_TRD0_INT_REQ_UF Get Value            */

#define TFU_TFU_INT_FLAGS_TFU1_TRD1_INT_REQ_UF_Pos    (6U)                                                                                  /*!< TFU1_TRD1_INT_REQ_UF Position  6          */ 
#define TFU_TFU_INT_FLAGS_TFU1_TRD1_INT_REQ_UF_Msk    (0x1U << TFU_TFU_INT_FLAGS_TFU1_TRD1_INT_REQ_UF_Pos)                                  /*!< TFU1_TRD1_INT_REQ_UF Mask      0x00000040 */
#define TFU_TFU_INT_FLAGS_TFU1_TRD1_INT_REQ_UF_Set(x) (((uint32_t) (x) << TFU_TFU_INT_FLAGS_TFU1_TRD1_INT_REQ_UF_Pos) & TFU_TFU_INT_FLAGS_TFU1_TRD1_INT_REQ_UF_Msk) /*!< TFU1_TRD1_INT_REQ_UF Set Value            */
#define TFU_TFU_INT_FLAGS_TFU1_TRD1_INT_REQ_UF_Get(x) (((uint32_t) (x) & TFU_TFU_INT_FLAGS_TFU1_TRD1_INT_REQ_UF_Msk) >> TFU_TFU_INT_FLAGS_TFU1_TRD1_INT_REQ_UF_Pos) /*!< TFU1_TRD1_INT_REQ_UF Get Value            */

#define TFU_TFU_INT_FLAGS_TFU1_TRD2_INT_REQ_UF_Pos    (5U)                                                                                  /*!< TFU1_TRD2_INT_REQ_UF Position  5          */ 
#define TFU_TFU_INT_FLAGS_TFU1_TRD2_INT_REQ_UF_Msk    (0x1U << TFU_TFU_INT_FLAGS_TFU1_TRD2_INT_REQ_UF_Pos)                                  /*!< TFU1_TRD2_INT_REQ_UF Mask      0x00000020 */
#define TFU_TFU_INT_FLAGS_TFU1_TRD2_INT_REQ_UF_Set(x) (((uint32_t) (x) << TFU_TFU_INT_FLAGS_TFU1_TRD2_INT_REQ_UF_Pos) & TFU_TFU_INT_FLAGS_TFU1_TRD2_INT_REQ_UF_Msk) /*!< TFU1_TRD2_INT_REQ_UF Set Value            */
#define TFU_TFU_INT_FLAGS_TFU1_TRD2_INT_REQ_UF_Get(x) (((uint32_t) (x) & TFU_TFU_INT_FLAGS_TFU1_TRD2_INT_REQ_UF_Msk) >> TFU_TFU_INT_FLAGS_TFU1_TRD2_INT_REQ_UF_Pos) /*!< TFU1_TRD2_INT_REQ_UF Get Value            */

#define TFU_TFU_INT_FLAGS_TFU1_TRD3_INT_REQ_UF_Pos    (4U)                                                                                  /*!< TFU1_TRD3_INT_REQ_UF Position  4          */ 
#define TFU_TFU_INT_FLAGS_TFU1_TRD3_INT_REQ_UF_Msk    (0x1U << TFU_TFU_INT_FLAGS_TFU1_TRD3_INT_REQ_UF_Pos)                                  /*!< TFU1_TRD3_INT_REQ_UF Mask      0x00000010 */
#define TFU_TFU_INT_FLAGS_TFU1_TRD3_INT_REQ_UF_Set(x) (((uint32_t) (x) << TFU_TFU_INT_FLAGS_TFU1_TRD3_INT_REQ_UF_Pos) & TFU_TFU_INT_FLAGS_TFU1_TRD3_INT_REQ_UF_Msk) /*!< TFU1_TRD3_INT_REQ_UF Set Value            */
#define TFU_TFU_INT_FLAGS_TFU1_TRD3_INT_REQ_UF_Get(x) (((uint32_t) (x) & TFU_TFU_INT_FLAGS_TFU1_TRD3_INT_REQ_UF_Msk) >> TFU_TFU_INT_FLAGS_TFU1_TRD3_INT_REQ_UF_Pos) /*!< TFU1_TRD3_INT_REQ_UF Get Value            */

#define TFU_TFU_INT_FLAGS_TFU1_TRD0_INT_REQ_OF_Pos    (3U)                                                                                  /*!< TFU1_TRD0_INT_REQ_OF Position  3          */ 
#define TFU_TFU_INT_FLAGS_TFU1_TRD0_INT_REQ_OF_Msk    (0x1U << TFU_TFU_INT_FLAGS_TFU1_TRD0_INT_REQ_OF_Pos)                                  /*!< TFU1_TRD0_INT_REQ_OF Mask      0x00000008 */
#define TFU_TFU_INT_FLAGS_TFU1_TRD0_INT_REQ_OF_Set(x) (((uint32_t) (x) << TFU_TFU_INT_FLAGS_TFU1_TRD0_INT_REQ_OF_Pos) & TFU_TFU_INT_FLAGS_TFU1_TRD0_INT_REQ_OF_Msk) /*!< TFU1_TRD0_INT_REQ_OF Set Value            */
#define TFU_TFU_INT_FLAGS_TFU1_TRD0_INT_REQ_OF_Get(x) (((uint32_t) (x) & TFU_TFU_INT_FLAGS_TFU1_TRD0_INT_REQ_OF_Msk) >> TFU_TFU_INT_FLAGS_TFU1_TRD0_INT_REQ_OF_Pos) /*!< TFU1_TRD0_INT_REQ_OF Get Value            */

#define TFU_TFU_INT_FLAGS_TFU1_TRD1_INT_REQ_OF_Pos    (2U)                                                                                  /*!< TFU1_TRD1_INT_REQ_OF Position  2          */ 
#define TFU_TFU_INT_FLAGS_TFU1_TRD1_INT_REQ_OF_Msk    (0x1U << TFU_TFU_INT_FLAGS_TFU1_TRD1_INT_REQ_OF_Pos)                                  /*!< TFU1_TRD1_INT_REQ_OF Mask      0x00000004 */
#define TFU_TFU_INT_FLAGS_TFU1_TRD1_INT_REQ_OF_Set(x) (((uint32_t) (x) << TFU_TFU_INT_FLAGS_TFU1_TRD1_INT_REQ_OF_Pos) & TFU_TFU_INT_FLAGS_TFU1_TRD1_INT_REQ_OF_Msk) /*!< TFU1_TRD1_INT_REQ_OF Set Value            */
#define TFU_TFU_INT_FLAGS_TFU1_TRD1_INT_REQ_OF_Get(x) (((uint32_t) (x) & TFU_TFU_INT_FLAGS_TFU1_TRD1_INT_REQ_OF_Msk) >> TFU_TFU_INT_FLAGS_TFU1_TRD1_INT_REQ_OF_Pos) /*!< TFU1_TRD1_INT_REQ_OF Get Value            */

#define TFU_TFU_INT_FLAGS_TFU1_TRD2_INT_REQ_OF_Pos    (1U)                                                                                  /*!< TFU1_TRD2_INT_REQ_OF Position  1          */ 
#define TFU_TFU_INT_FLAGS_TFU1_TRD2_INT_REQ_OF_Msk    (0x1U << TFU_TFU_INT_FLAGS_TFU1_TRD2_INT_REQ_OF_Pos)                                  /*!< TFU1_TRD2_INT_REQ_OF Mask      0x00000002 */
#define TFU_TFU_INT_FLAGS_TFU1_TRD2_INT_REQ_OF_Set(x) (((uint32_t) (x) << TFU_TFU_INT_FLAGS_TFU1_TRD2_INT_REQ_OF_Pos) & TFU_TFU_INT_FLAGS_TFU1_TRD2_INT_REQ_OF_Msk) /*!< TFU1_TRD2_INT_REQ_OF Set Value            */
#define TFU_TFU_INT_FLAGS_TFU1_TRD2_INT_REQ_OF_Get(x) (((uint32_t) (x) & TFU_TFU_INT_FLAGS_TFU1_TRD2_INT_REQ_OF_Msk) >> TFU_TFU_INT_FLAGS_TFU1_TRD2_INT_REQ_OF_Pos) /*!< TFU1_TRD2_INT_REQ_OF Get Value            */

#define TFU_TFU_INT_FLAGS_TFU1_TRD3_INT_REQ_OF_Pos    (0U)                                                                                  /*!< TFU1_TRD3_INT_REQ_OF Position  0          */ 
#define TFU_TFU_INT_FLAGS_TFU1_TRD3_INT_REQ_OF_Msk    (0x1U << TFU_TFU_INT_FLAGS_TFU1_TRD3_INT_REQ_OF_Pos)                                  /*!< TFU1_TRD3_INT_REQ_OF Mask      0x00000001 */
#define TFU_TFU_INT_FLAGS_TFU1_TRD3_INT_REQ_OF_Set(x) (((uint32_t) (x) << TFU_TFU_INT_FLAGS_TFU1_TRD3_INT_REQ_OF_Pos) & TFU_TFU_INT_FLAGS_TFU1_TRD3_INT_REQ_OF_Msk) /*!< TFU1_TRD3_INT_REQ_OF Set Value            */
#define TFU_TFU_INT_FLAGS_TFU1_TRD3_INT_REQ_OF_Get(x) (((uint32_t) (x) & TFU_TFU_INT_FLAGS_TFU1_TRD3_INT_REQ_OF_Msk) >> TFU_TFU_INT_FLAGS_TFU1_TRD3_INT_REQ_OF_Pos) /*!< TFU1_TRD3_INT_REQ_OF Get Value            */

/* TFU_INT_EN bitfield */
#define TFU_TFU_INT_EN_TFU0_TRD0_INT_SBDNT_Pos    (31U)                                                                                 /*!< TFU0_TRD0_INT_SBDNT Position  31         */ 
#define TFU_TFU_INT_EN_TFU0_TRD0_INT_SBDNT_Msk    (0x1U << TFU_TFU_INT_EN_TFU0_TRD0_INT_SBDNT_Pos)                                      /*!< TFU0_TRD0_INT_SBDNT Mask      0x80000000 */
#define TFU_TFU_INT_EN_TFU0_TRD0_INT_SBDNT_Set(x) (((uint32_t) (x) << TFU_TFU_INT_EN_TFU0_TRD0_INT_SBDNT_Pos) & TFU_TFU_INT_EN_TFU0_TRD0_INT_SBDNT_Msk) /*!< TFU0_TRD0_INT_SBDNT Set Value            */
#define TFU_TFU_INT_EN_TFU0_TRD0_INT_SBDNT_Get(x) (((uint32_t) (x) & TFU_TFU_INT_EN_TFU0_TRD0_INT_SBDNT_Msk) >> TFU_TFU_INT_EN_TFU0_TRD0_INT_SBDNT_Pos) /*!< TFU0_TRD0_INT_SBDNT Get Value            */

#define TFU_TFU_INT_EN_TFU0_TRD1_INT_SBDNT_Pos    (30U)                                                                                 /*!< TFU0_TRD1_INT_SBDNT Position  30         */ 
#define TFU_TFU_INT_EN_TFU0_TRD1_INT_SBDNT_Msk    (0x1U << TFU_TFU_INT_EN_TFU0_TRD1_INT_SBDNT_Pos)                                      /*!< TFU0_TRD1_INT_SBDNT Mask      0x40000000 */
#define TFU_TFU_INT_EN_TFU0_TRD1_INT_SBDNT_Set(x) (((uint32_t) (x) << TFU_TFU_INT_EN_TFU0_TRD1_INT_SBDNT_Pos) & TFU_TFU_INT_EN_TFU0_TRD1_INT_SBDNT_Msk) /*!< TFU0_TRD1_INT_SBDNT Set Value            */
#define TFU_TFU_INT_EN_TFU0_TRD1_INT_SBDNT_Get(x) (((uint32_t) (x) & TFU_TFU_INT_EN_TFU0_TRD1_INT_SBDNT_Msk) >> TFU_TFU_INT_EN_TFU0_TRD1_INT_SBDNT_Pos) /*!< TFU0_TRD1_INT_SBDNT Get Value            */

#define TFU_TFU_INT_EN_TFU0_TRD2_INT_SBDNT_Pos    (29U)                                                                                 /*!< TFU0_TRD2_INT_SBDNT Position  29         */ 
#define TFU_TFU_INT_EN_TFU0_TRD2_INT_SBDNT_Msk    (0x1U << TFU_TFU_INT_EN_TFU0_TRD2_INT_SBDNT_Pos)                                      /*!< TFU0_TRD2_INT_SBDNT Mask      0x20000000 */
#define TFU_TFU_INT_EN_TFU0_TRD2_INT_SBDNT_Set(x) (((uint32_t) (x) << TFU_TFU_INT_EN_TFU0_TRD2_INT_SBDNT_Pos) & TFU_TFU_INT_EN_TFU0_TRD2_INT_SBDNT_Msk) /*!< TFU0_TRD2_INT_SBDNT Set Value            */
#define TFU_TFU_INT_EN_TFU0_TRD2_INT_SBDNT_Get(x) (((uint32_t) (x) & TFU_TFU_INT_EN_TFU0_TRD2_INT_SBDNT_Msk) >> TFU_TFU_INT_EN_TFU0_TRD2_INT_SBDNT_Pos) /*!< TFU0_TRD2_INT_SBDNT Get Value            */

#define TFU_TFU_INT_EN_TFU0_TRD3_INT_SBDNT_Pos    (28U)                                                                                 /*!< TFU0_TRD3_INT_SBDNT Position  28         */ 
#define TFU_TFU_INT_EN_TFU0_TRD3_INT_SBDNT_Msk    (0x1U << TFU_TFU_INT_EN_TFU0_TRD3_INT_SBDNT_Pos)                                      /*!< TFU0_TRD3_INT_SBDNT Mask      0x10000000 */
#define TFU_TFU_INT_EN_TFU0_TRD3_INT_SBDNT_Set(x) (((uint32_t) (x) << TFU_TFU_INT_EN_TFU0_TRD3_INT_SBDNT_Pos) & TFU_TFU_INT_EN_TFU0_TRD3_INT_SBDNT_Msk) /*!< TFU0_TRD3_INT_SBDNT Set Value            */
#define TFU_TFU_INT_EN_TFU0_TRD3_INT_SBDNT_Get(x) (((uint32_t) (x) & TFU_TFU_INT_EN_TFU0_TRD3_INT_SBDNT_Msk) >> TFU_TFU_INT_EN_TFU0_TRD3_INT_SBDNT_Pos) /*!< TFU0_TRD3_INT_SBDNT Get Value            */

#define TFU_TFU_INT_EN_TFU1_TRD0_INT_SBDNT_Pos    (27U)                                                                                 /*!< TFU1_TRD0_INT_SBDNT Position  27         */ 
#define TFU_TFU_INT_EN_TFU1_TRD0_INT_SBDNT_Msk    (0x1U << TFU_TFU_INT_EN_TFU1_TRD0_INT_SBDNT_Pos)                                      /*!< TFU1_TRD0_INT_SBDNT Mask      0x08000000 */
#define TFU_TFU_INT_EN_TFU1_TRD0_INT_SBDNT_Set(x) (((uint32_t) (x) << TFU_TFU_INT_EN_TFU1_TRD0_INT_SBDNT_Pos) & TFU_TFU_INT_EN_TFU1_TRD0_INT_SBDNT_Msk) /*!< TFU1_TRD0_INT_SBDNT Set Value            */
#define TFU_TFU_INT_EN_TFU1_TRD0_INT_SBDNT_Get(x) (((uint32_t) (x) & TFU_TFU_INT_EN_TFU1_TRD0_INT_SBDNT_Msk) >> TFU_TFU_INT_EN_TFU1_TRD0_INT_SBDNT_Pos) /*!< TFU1_TRD0_INT_SBDNT Get Value            */

#define TFU_TFU_INT_EN_TFU1_TRD1_INT_SBDNT_Pos    (26U)                                                                                 /*!< TFU1_TRD1_INT_SBDNT Position  26         */ 
#define TFU_TFU_INT_EN_TFU1_TRD1_INT_SBDNT_Msk    (0x1U << TFU_TFU_INT_EN_TFU1_TRD1_INT_SBDNT_Pos)                                      /*!< TFU1_TRD1_INT_SBDNT Mask      0x04000000 */
#define TFU_TFU_INT_EN_TFU1_TRD1_INT_SBDNT_Set(x) (((uint32_t) (x) << TFU_TFU_INT_EN_TFU1_TRD1_INT_SBDNT_Pos) & TFU_TFU_INT_EN_TFU1_TRD1_INT_SBDNT_Msk) /*!< TFU1_TRD1_INT_SBDNT Set Value            */
#define TFU_TFU_INT_EN_TFU1_TRD1_INT_SBDNT_Get(x) (((uint32_t) (x) & TFU_TFU_INT_EN_TFU1_TRD1_INT_SBDNT_Msk) >> TFU_TFU_INT_EN_TFU1_TRD1_INT_SBDNT_Pos) /*!< TFU1_TRD1_INT_SBDNT Get Value            */

#define TFU_TFU_INT_EN_TFU1_TRD2_INT_SBDNT_Pos    (25U)                                                                                 /*!< TFU1_TRD2_INT_SBDNT Position  25         */ 
#define TFU_TFU_INT_EN_TFU1_TRD2_INT_SBDNT_Msk    (0x1U << TFU_TFU_INT_EN_TFU1_TRD2_INT_SBDNT_Pos)                                      /*!< TFU1_TRD2_INT_SBDNT Mask      0x02000000 */
#define TFU_TFU_INT_EN_TFU1_TRD2_INT_SBDNT_Set(x) (((uint32_t) (x) << TFU_TFU_INT_EN_TFU1_TRD2_INT_SBDNT_Pos) & TFU_TFU_INT_EN_TFU1_TRD2_INT_SBDNT_Msk) /*!< TFU1_TRD2_INT_SBDNT Set Value            */
#define TFU_TFU_INT_EN_TFU1_TRD2_INT_SBDNT_Get(x) (((uint32_t) (x) & TFU_TFU_INT_EN_TFU1_TRD2_INT_SBDNT_Msk) >> TFU_TFU_INT_EN_TFU1_TRD2_INT_SBDNT_Pos) /*!< TFU1_TRD2_INT_SBDNT Get Value            */

#define TFU_TFU_INT_EN_TFU1_TRD3_INT_SBDNT_Pos    (24U)                                                                                 /*!< TFU1_TRD3_INT_SBDNT Position  24         */ 
#define TFU_TFU_INT_EN_TFU1_TRD3_INT_SBDNT_Msk    (0x1U << TFU_TFU_INT_EN_TFU1_TRD3_INT_SBDNT_Pos)                                      /*!< TFU1_TRD3_INT_SBDNT Mask      0x01000000 */
#define TFU_TFU_INT_EN_TFU1_TRD3_INT_SBDNT_Set(x) (((uint32_t) (x) << TFU_TFU_INT_EN_TFU1_TRD3_INT_SBDNT_Pos) & TFU_TFU_INT_EN_TFU1_TRD3_INT_SBDNT_Msk) /*!< TFU1_TRD3_INT_SBDNT Set Value            */
#define TFU_TFU_INT_EN_TFU1_TRD3_INT_SBDNT_Get(x) (((uint32_t) (x) & TFU_TFU_INT_EN_TFU1_TRD3_INT_SBDNT_Msk) >> TFU_TFU_INT_EN_TFU1_TRD3_INT_SBDNT_Pos) /*!< TFU1_TRD3_INT_SBDNT Get Value            */

#define TFU_TFU_INT_EN_TFU0_TRD0_INT_REQ_EN_Pos    (23U)                                                                                 /*!< TFU0_TRD0_INT_REQ_EN Position  23         */ 
#define TFU_TFU_INT_EN_TFU0_TRD0_INT_REQ_EN_Msk    (0x1U << TFU_TFU_INT_EN_TFU0_TRD0_INT_REQ_EN_Pos)                                     /*!< TFU0_TRD0_INT_REQ_EN Mask      0x00800000 */
#define TFU_TFU_INT_EN_TFU0_TRD0_INT_REQ_EN_Set(x) (((uint32_t) (x) << TFU_TFU_INT_EN_TFU0_TRD0_INT_REQ_EN_Pos) & TFU_TFU_INT_EN_TFU0_TRD0_INT_REQ_EN_Msk) /*!< TFU0_TRD0_INT_REQ_EN Set Value            */
#define TFU_TFU_INT_EN_TFU0_TRD0_INT_REQ_EN_Get(x) (((uint32_t) (x) & TFU_TFU_INT_EN_TFU0_TRD0_INT_REQ_EN_Msk) >> TFU_TFU_INT_EN_TFU0_TRD0_INT_REQ_EN_Pos) /*!< TFU0_TRD0_INT_REQ_EN Get Value            */

#define TFU_TFU_INT_EN_TFU0_TRD1_INT_REQ_EN_Pos    (22U)                                                                                 /*!< TFU0_TRD1_INT_REQ_EN Position  22         */ 
#define TFU_TFU_INT_EN_TFU0_TRD1_INT_REQ_EN_Msk    (0x1U << TFU_TFU_INT_EN_TFU0_TRD1_INT_REQ_EN_Pos)                                     /*!< TFU0_TRD1_INT_REQ_EN Mask      0x00400000 */
#define TFU_TFU_INT_EN_TFU0_TRD1_INT_REQ_EN_Set(x) (((uint32_t) (x) << TFU_TFU_INT_EN_TFU0_TRD1_INT_REQ_EN_Pos) & TFU_TFU_INT_EN_TFU0_TRD1_INT_REQ_EN_Msk) /*!< TFU0_TRD1_INT_REQ_EN Set Value            */
#define TFU_TFU_INT_EN_TFU0_TRD1_INT_REQ_EN_Get(x) (((uint32_t) (x) & TFU_TFU_INT_EN_TFU0_TRD1_INT_REQ_EN_Msk) >> TFU_TFU_INT_EN_TFU0_TRD1_INT_REQ_EN_Pos) /*!< TFU0_TRD1_INT_REQ_EN Get Value            */

#define TFU_TFU_INT_EN_TFU0_TRD2_INT_REQ_EN_Pos    (21U)                                                                                 /*!< TFU0_TRD2_INT_REQ_EN Position  21         */ 
#define TFU_TFU_INT_EN_TFU0_TRD2_INT_REQ_EN_Msk    (0x1U << TFU_TFU_INT_EN_TFU0_TRD2_INT_REQ_EN_Pos)                                     /*!< TFU0_TRD2_INT_REQ_EN Mask      0x00200000 */
#define TFU_TFU_INT_EN_TFU0_TRD2_INT_REQ_EN_Set(x) (((uint32_t) (x) << TFU_TFU_INT_EN_TFU0_TRD2_INT_REQ_EN_Pos) & TFU_TFU_INT_EN_TFU0_TRD2_INT_REQ_EN_Msk) /*!< TFU0_TRD2_INT_REQ_EN Set Value            */
#define TFU_TFU_INT_EN_TFU0_TRD2_INT_REQ_EN_Get(x) (((uint32_t) (x) & TFU_TFU_INT_EN_TFU0_TRD2_INT_REQ_EN_Msk) >> TFU_TFU_INT_EN_TFU0_TRD2_INT_REQ_EN_Pos) /*!< TFU0_TRD2_INT_REQ_EN Get Value            */

#define TFU_TFU_INT_EN_TFU0_TRD3_INT_REQ_EN_Pos    (20U)                                                                                 /*!< TFU0_TRD3_INT_REQ_EN Position  20         */ 
#define TFU_TFU_INT_EN_TFU0_TRD3_INT_REQ_EN_Msk    (0x1U << TFU_TFU_INT_EN_TFU0_TRD3_INT_REQ_EN_Pos)                                     /*!< TFU0_TRD3_INT_REQ_EN Mask      0x00100000 */
#define TFU_TFU_INT_EN_TFU0_TRD3_INT_REQ_EN_Set(x) (((uint32_t) (x) << TFU_TFU_INT_EN_TFU0_TRD3_INT_REQ_EN_Pos) & TFU_TFU_INT_EN_TFU0_TRD3_INT_REQ_EN_Msk) /*!< TFU0_TRD3_INT_REQ_EN Set Value            */
#define TFU_TFU_INT_EN_TFU0_TRD3_INT_REQ_EN_Get(x) (((uint32_t) (x) & TFU_TFU_INT_EN_TFU0_TRD3_INT_REQ_EN_Msk) >> TFU_TFU_INT_EN_TFU0_TRD3_INT_REQ_EN_Pos) /*!< TFU0_TRD3_INT_REQ_EN Get Value            */

#define TFU_TFU_INT_EN_TFU0_TRD0_INT_REQ_UF_EN_Pos    (19U)                                                                                 /*!< TFU0_TRD0_INT_REQ_UF_EN Position  19         */ 
#define TFU_TFU_INT_EN_TFU0_TRD0_INT_REQ_UF_EN_Msk    (0x1U << TFU_TFU_INT_EN_TFU0_TRD0_INT_REQ_UF_EN_Pos)                                  /*!< TFU0_TRD0_INT_REQ_UF_EN Mask      0x00080000 */
#define TFU_TFU_INT_EN_TFU0_TRD0_INT_REQ_UF_EN_Set(x) (((uint32_t) (x) << TFU_TFU_INT_EN_TFU0_TRD0_INT_REQ_UF_EN_Pos) & TFU_TFU_INT_EN_TFU0_TRD0_INT_REQ_UF_EN_Msk) /*!< TFU0_TRD0_INT_REQ_UF_EN Set Value            */
#define TFU_TFU_INT_EN_TFU0_TRD0_INT_REQ_UF_EN_Get(x) (((uint32_t) (x) & TFU_TFU_INT_EN_TFU0_TRD0_INT_REQ_UF_EN_Msk) >> TFU_TFU_INT_EN_TFU0_TRD0_INT_REQ_UF_EN_Pos) /*!< TFU0_TRD0_INT_REQ_UF_EN Get Value            */

#define TFU_TFU_INT_EN_TFU0_TRD1_INT_REQ_UF_EN_Pos    (18U)                                                                                 /*!< TFU0_TRD1_INT_REQ_UF_EN Position  18         */ 
#define TFU_TFU_INT_EN_TFU0_TRD1_INT_REQ_UF_EN_Msk    (0x1U << TFU_TFU_INT_EN_TFU0_TRD1_INT_REQ_UF_EN_Pos)                                  /*!< TFU0_TRD1_INT_REQ_UF_EN Mask      0x00040000 */
#define TFU_TFU_INT_EN_TFU0_TRD1_INT_REQ_UF_EN_Set(x) (((uint32_t) (x) << TFU_TFU_INT_EN_TFU0_TRD1_INT_REQ_UF_EN_Pos) & TFU_TFU_INT_EN_TFU0_TRD1_INT_REQ_UF_EN_Msk) /*!< TFU0_TRD1_INT_REQ_UF_EN Set Value            */
#define TFU_TFU_INT_EN_TFU0_TRD1_INT_REQ_UF_EN_Get(x) (((uint32_t) (x) & TFU_TFU_INT_EN_TFU0_TRD1_INT_REQ_UF_EN_Msk) >> TFU_TFU_INT_EN_TFU0_TRD1_INT_REQ_UF_EN_Pos) /*!< TFU0_TRD1_INT_REQ_UF_EN Get Value            */

#define TFU_TFU_INT_EN_TFU0_TRD2_INT_REQ_UF_EN_Pos    (17U)                                                                                 /*!< TFU0_TRD2_INT_REQ_UF_EN Position  17         */ 
#define TFU_TFU_INT_EN_TFU0_TRD2_INT_REQ_UF_EN_Msk    (0x1U << TFU_TFU_INT_EN_TFU0_TRD2_INT_REQ_UF_EN_Pos)                                  /*!< TFU0_TRD2_INT_REQ_UF_EN Mask      0x00020000 */
#define TFU_TFU_INT_EN_TFU0_TRD2_INT_REQ_UF_EN_Set(x) (((uint32_t) (x) << TFU_TFU_INT_EN_TFU0_TRD2_INT_REQ_UF_EN_Pos) & TFU_TFU_INT_EN_TFU0_TRD2_INT_REQ_UF_EN_Msk) /*!< TFU0_TRD2_INT_REQ_UF_EN Set Value            */
#define TFU_TFU_INT_EN_TFU0_TRD2_INT_REQ_UF_EN_Get(x) (((uint32_t) (x) & TFU_TFU_INT_EN_TFU0_TRD2_INT_REQ_UF_EN_Msk) >> TFU_TFU_INT_EN_TFU0_TRD2_INT_REQ_UF_EN_Pos) /*!< TFU0_TRD2_INT_REQ_UF_EN Get Value            */

#define TFU_TFU_INT_EN_TFU0_TRD3_INT_REQ_UF_EN_Pos    (16U)                                                                                 /*!< TFU0_TRD3_INT_REQ_UF_EN Position  16         */ 
#define TFU_TFU_INT_EN_TFU0_TRD3_INT_REQ_UF_EN_Msk    (0x1U << TFU_TFU_INT_EN_TFU0_TRD3_INT_REQ_UF_EN_Pos)                                  /*!< TFU0_TRD3_INT_REQ_UF_EN Mask      0x00010000 */
#define TFU_TFU_INT_EN_TFU0_TRD3_INT_REQ_UF_EN_Set(x) (((uint32_t) (x) << TFU_TFU_INT_EN_TFU0_TRD3_INT_REQ_UF_EN_Pos) & TFU_TFU_INT_EN_TFU0_TRD3_INT_REQ_UF_EN_Msk) /*!< TFU0_TRD3_INT_REQ_UF_EN Set Value            */
#define TFU_TFU_INT_EN_TFU0_TRD3_INT_REQ_UF_EN_Get(x) (((uint32_t) (x) & TFU_TFU_INT_EN_TFU0_TRD3_INT_REQ_UF_EN_Msk) >> TFU_TFU_INT_EN_TFU0_TRD3_INT_REQ_UF_EN_Pos) /*!< TFU0_TRD3_INT_REQ_UF_EN Get Value            */

#define TFU_TFU_INT_EN_TFU0_TRD0_INT_REQ_OF_EN_Pos    (15U)                                                                                 /*!< TFU0_TRD0_INT_REQ_OF_EN Position  15         */ 
#define TFU_TFU_INT_EN_TFU0_TRD0_INT_REQ_OF_EN_Msk    (0x1U << TFU_TFU_INT_EN_TFU0_TRD0_INT_REQ_OF_EN_Pos)                                  /*!< TFU0_TRD0_INT_REQ_OF_EN Mask      0x00008000 */
#define TFU_TFU_INT_EN_TFU0_TRD0_INT_REQ_OF_EN_Set(x) (((uint32_t) (x) << TFU_TFU_INT_EN_TFU0_TRD0_INT_REQ_OF_EN_Pos) & TFU_TFU_INT_EN_TFU0_TRD0_INT_REQ_OF_EN_Msk) /*!< TFU0_TRD0_INT_REQ_OF_EN Set Value            */
#define TFU_TFU_INT_EN_TFU0_TRD0_INT_REQ_OF_EN_Get(x) (((uint32_t) (x) & TFU_TFU_INT_EN_TFU0_TRD0_INT_REQ_OF_EN_Msk) >> TFU_TFU_INT_EN_TFU0_TRD0_INT_REQ_OF_EN_Pos) /*!< TFU0_TRD0_INT_REQ_OF_EN Get Value            */

#define TFU_TFU_INT_EN_TFU0_TRD1_INT_REQ_OF_EN_Pos    (14U)                                                                                 /*!< TFU0_TRD1_INT_REQ_OF_EN Position  14         */ 
#define TFU_TFU_INT_EN_TFU0_TRD1_INT_REQ_OF_EN_Msk    (0x1U << TFU_TFU_INT_EN_TFU0_TRD1_INT_REQ_OF_EN_Pos)                                  /*!< TFU0_TRD1_INT_REQ_OF_EN Mask      0x00004000 */
#define TFU_TFU_INT_EN_TFU0_TRD1_INT_REQ_OF_EN_Set(x) (((uint32_t) (x) << TFU_TFU_INT_EN_TFU0_TRD1_INT_REQ_OF_EN_Pos) & TFU_TFU_INT_EN_TFU0_TRD1_INT_REQ_OF_EN_Msk) /*!< TFU0_TRD1_INT_REQ_OF_EN Set Value            */
#define TFU_TFU_INT_EN_TFU0_TRD1_INT_REQ_OF_EN_Get(x) (((uint32_t) (x) & TFU_TFU_INT_EN_TFU0_TRD1_INT_REQ_OF_EN_Msk) >> TFU_TFU_INT_EN_TFU0_TRD1_INT_REQ_OF_EN_Pos) /*!< TFU0_TRD1_INT_REQ_OF_EN Get Value            */

#define TFU_TFU_INT_EN_TFU0_TRD2_INT_REQ_OF_EN_Pos    (13U)                                                                                 /*!< TFU0_TRD2_INT_REQ_OF_EN Position  13         */ 
#define TFU_TFU_INT_EN_TFU0_TRD2_INT_REQ_OF_EN_Msk    (0x1U << TFU_TFU_INT_EN_TFU0_TRD2_INT_REQ_OF_EN_Pos)                                  /*!< TFU0_TRD2_INT_REQ_OF_EN Mask      0x00002000 */
#define TFU_TFU_INT_EN_TFU0_TRD2_INT_REQ_OF_EN_Set(x) (((uint32_t) (x) << TFU_TFU_INT_EN_TFU0_TRD2_INT_REQ_OF_EN_Pos) & TFU_TFU_INT_EN_TFU0_TRD2_INT_REQ_OF_EN_Msk) /*!< TFU0_TRD2_INT_REQ_OF_EN Set Value            */
#define TFU_TFU_INT_EN_TFU0_TRD2_INT_REQ_OF_EN_Get(x) (((uint32_t) (x) & TFU_TFU_INT_EN_TFU0_TRD2_INT_REQ_OF_EN_Msk) >> TFU_TFU_INT_EN_TFU0_TRD2_INT_REQ_OF_EN_Pos) /*!< TFU0_TRD2_INT_REQ_OF_EN Get Value            */

#define TFU_TFU_INT_EN_TFU0_TRD3_INT_REQ_OF_EN_Pos    (12U)                                                                                 /*!< TFU0_TRD3_INT_REQ_OF_EN Position  12         */ 
#define TFU_TFU_INT_EN_TFU0_TRD3_INT_REQ_OF_EN_Msk    (0x1U << TFU_TFU_INT_EN_TFU0_TRD3_INT_REQ_OF_EN_Pos)                                  /*!< TFU0_TRD3_INT_REQ_OF_EN Mask      0x00001000 */
#define TFU_TFU_INT_EN_TFU0_TRD3_INT_REQ_OF_EN_Set(x) (((uint32_t) (x) << TFU_TFU_INT_EN_TFU0_TRD3_INT_REQ_OF_EN_Pos) & TFU_TFU_INT_EN_TFU0_TRD3_INT_REQ_OF_EN_Msk) /*!< TFU0_TRD3_INT_REQ_OF_EN Set Value            */
#define TFU_TFU_INT_EN_TFU0_TRD3_INT_REQ_OF_EN_Get(x) (((uint32_t) (x) & TFU_TFU_INT_EN_TFU0_TRD3_INT_REQ_OF_EN_Msk) >> TFU_TFU_INT_EN_TFU0_TRD3_INT_REQ_OF_EN_Pos) /*!< TFU0_TRD3_INT_REQ_OF_EN Get Value            */

#define TFU_TFU_INT_EN_TFU1_TRD0_INT_REQ_EN_Pos    (11U)                                                                                 /*!< TFU1_TRD0_INT_REQ_EN Position  11         */ 
#define TFU_TFU_INT_EN_TFU1_TRD0_INT_REQ_EN_Msk    (0x1U << TFU_TFU_INT_EN_TFU1_TRD0_INT_REQ_EN_Pos)                                     /*!< TFU1_TRD0_INT_REQ_EN Mask      0x00000800 */
#define TFU_TFU_INT_EN_TFU1_TRD0_INT_REQ_EN_Set(x) (((uint32_t) (x) << TFU_TFU_INT_EN_TFU1_TRD0_INT_REQ_EN_Pos) & TFU_TFU_INT_EN_TFU1_TRD0_INT_REQ_EN_Msk) /*!< TFU1_TRD0_INT_REQ_EN Set Value            */
#define TFU_TFU_INT_EN_TFU1_TRD0_INT_REQ_EN_Get(x) (((uint32_t) (x) & TFU_TFU_INT_EN_TFU1_TRD0_INT_REQ_EN_Msk) >> TFU_TFU_INT_EN_TFU1_TRD0_INT_REQ_EN_Pos) /*!< TFU1_TRD0_INT_REQ_EN Get Value            */

#define TFU_TFU_INT_EN_TFU1_TRD1_INT_REQ_EN_Pos    (10U)                                                                                 /*!< TFU1_TRD1_INT_REQ_EN Position  10         */ 
#define TFU_TFU_INT_EN_TFU1_TRD1_INT_REQ_EN_Msk    (0x1U << TFU_TFU_INT_EN_TFU1_TRD1_INT_REQ_EN_Pos)                                     /*!< TFU1_TRD1_INT_REQ_EN Mask      0x00000400 */
#define TFU_TFU_INT_EN_TFU1_TRD1_INT_REQ_EN_Set(x) (((uint32_t) (x) << TFU_TFU_INT_EN_TFU1_TRD1_INT_REQ_EN_Pos) & TFU_TFU_INT_EN_TFU1_TRD1_INT_REQ_EN_Msk) /*!< TFU1_TRD1_INT_REQ_EN Set Value            */
#define TFU_TFU_INT_EN_TFU1_TRD1_INT_REQ_EN_Get(x) (((uint32_t) (x) & TFU_TFU_INT_EN_TFU1_TRD1_INT_REQ_EN_Msk) >> TFU_TFU_INT_EN_TFU1_TRD1_INT_REQ_EN_Pos) /*!< TFU1_TRD1_INT_REQ_EN Get Value            */

#define TFU_TFU_INT_EN_TFU1_TRD2_INT_REQ_EN_Pos    (9U)                                                                                  /*!< TFU1_TRD2_INT_REQ_EN Position  9          */ 
#define TFU_TFU_INT_EN_TFU1_TRD2_INT_REQ_EN_Msk    (0x1U << TFU_TFU_INT_EN_TFU1_TRD2_INT_REQ_EN_Pos)                                     /*!< TFU1_TRD2_INT_REQ_EN Mask      0x00000200 */
#define TFU_TFU_INT_EN_TFU1_TRD2_INT_REQ_EN_Set(x) (((uint32_t) (x) << TFU_TFU_INT_EN_TFU1_TRD2_INT_REQ_EN_Pos) & TFU_TFU_INT_EN_TFU1_TRD2_INT_REQ_EN_Msk) /*!< TFU1_TRD2_INT_REQ_EN Set Value            */
#define TFU_TFU_INT_EN_TFU1_TRD2_INT_REQ_EN_Get(x) (((uint32_t) (x) & TFU_TFU_INT_EN_TFU1_TRD2_INT_REQ_EN_Msk) >> TFU_TFU_INT_EN_TFU1_TRD2_INT_REQ_EN_Pos) /*!< TFU1_TRD2_INT_REQ_EN Get Value            */

#define TFU_TFU_INT_EN_TFU1_TRD3_INT_REQ_EN_Pos    (8U)                                                                                  /*!< TFU1_TRD3_INT_REQ_EN Position  8          */ 
#define TFU_TFU_INT_EN_TFU1_TRD3_INT_REQ_EN_Msk    (0x1U << TFU_TFU_INT_EN_TFU1_TRD3_INT_REQ_EN_Pos)                                     /*!< TFU1_TRD3_INT_REQ_EN Mask      0x00000100 */
#define TFU_TFU_INT_EN_TFU1_TRD3_INT_REQ_EN_Set(x) (((uint32_t) (x) << TFU_TFU_INT_EN_TFU1_TRD3_INT_REQ_EN_Pos) & TFU_TFU_INT_EN_TFU1_TRD3_INT_REQ_EN_Msk) /*!< TFU1_TRD3_INT_REQ_EN Set Value            */
#define TFU_TFU_INT_EN_TFU1_TRD3_INT_REQ_EN_Get(x) (((uint32_t) (x) & TFU_TFU_INT_EN_TFU1_TRD3_INT_REQ_EN_Msk) >> TFU_TFU_INT_EN_TFU1_TRD3_INT_REQ_EN_Pos) /*!< TFU1_TRD3_INT_REQ_EN Get Value            */

#define TFU_TFU_INT_EN_TFU1_TRD0_INT_REQ_UF_EN_Pos    (7U)                                                                                  /*!< TFU1_TRD0_INT_REQ_UF_EN Position  7          */ 
#define TFU_TFU_INT_EN_TFU1_TRD0_INT_REQ_UF_EN_Msk    (0x1U << TFU_TFU_INT_EN_TFU1_TRD0_INT_REQ_UF_EN_Pos)                                  /*!< TFU1_TRD0_INT_REQ_UF_EN Mask      0x00000080 */
#define TFU_TFU_INT_EN_TFU1_TRD0_INT_REQ_UF_EN_Set(x) (((uint32_t) (x) << TFU_TFU_INT_EN_TFU1_TRD0_INT_REQ_UF_EN_Pos) & TFU_TFU_INT_EN_TFU1_TRD0_INT_REQ_UF_EN_Msk) /*!< TFU1_TRD0_INT_REQ_UF_EN Set Value            */
#define TFU_TFU_INT_EN_TFU1_TRD0_INT_REQ_UF_EN_Get(x) (((uint32_t) (x) & TFU_TFU_INT_EN_TFU1_TRD0_INT_REQ_UF_EN_Msk) >> TFU_TFU_INT_EN_TFU1_TRD0_INT_REQ_UF_EN_Pos) /*!< TFU1_TRD0_INT_REQ_UF_EN Get Value            */

#define TFU_TFU_INT_EN_TFU1_TRD1_INT_REQ_UF_EN_Pos    (6U)                                                                                  /*!< TFU1_TRD1_INT_REQ_UF_EN Position  6          */ 
#define TFU_TFU_INT_EN_TFU1_TRD1_INT_REQ_UF_EN_Msk    (0x1U << TFU_TFU_INT_EN_TFU1_TRD1_INT_REQ_UF_EN_Pos)                                  /*!< TFU1_TRD1_INT_REQ_UF_EN Mask      0x00000040 */
#define TFU_TFU_INT_EN_TFU1_TRD1_INT_REQ_UF_EN_Set(x) (((uint32_t) (x) << TFU_TFU_INT_EN_TFU1_TRD1_INT_REQ_UF_EN_Pos) & TFU_TFU_INT_EN_TFU1_TRD1_INT_REQ_UF_EN_Msk) /*!< TFU1_TRD1_INT_REQ_UF_EN Set Value            */
#define TFU_TFU_INT_EN_TFU1_TRD1_INT_REQ_UF_EN_Get(x) (((uint32_t) (x) & TFU_TFU_INT_EN_TFU1_TRD1_INT_REQ_UF_EN_Msk) >> TFU_TFU_INT_EN_TFU1_TRD1_INT_REQ_UF_EN_Pos) /*!< TFU1_TRD1_INT_REQ_UF_EN Get Value            */

#define TFU_TFU_INT_EN_TFU1_TRD2_INT_REQ_UF_EN_Pos    (5U)                                                                                  /*!< TFU1_TRD2_INT_REQ_UF_EN Position  5          */ 
#define TFU_TFU_INT_EN_TFU1_TRD2_INT_REQ_UF_EN_Msk    (0x1U << TFU_TFU_INT_EN_TFU1_TRD2_INT_REQ_UF_EN_Pos)                                  /*!< TFU1_TRD2_INT_REQ_UF_EN Mask      0x00000020 */
#define TFU_TFU_INT_EN_TFU1_TRD2_INT_REQ_UF_EN_Set(x) (((uint32_t) (x) << TFU_TFU_INT_EN_TFU1_TRD2_INT_REQ_UF_EN_Pos) & TFU_TFU_INT_EN_TFU1_TRD2_INT_REQ_UF_EN_Msk) /*!< TFU1_TRD2_INT_REQ_UF_EN Set Value            */
#define TFU_TFU_INT_EN_TFU1_TRD2_INT_REQ_UF_EN_Get(x) (((uint32_t) (x) & TFU_TFU_INT_EN_TFU1_TRD2_INT_REQ_UF_EN_Msk) >> TFU_TFU_INT_EN_TFU1_TRD2_INT_REQ_UF_EN_Pos) /*!< TFU1_TRD2_INT_REQ_UF_EN Get Value            */

#define TFU_TFU_INT_EN_TFU1_TRD3_INT_REQ_UF_EN_Pos    (4U)                                                                                  /*!< TFU1_TRD3_INT_REQ_UF_EN Position  4          */ 
#define TFU_TFU_INT_EN_TFU1_TRD3_INT_REQ_UF_EN_Msk    (0x1U << TFU_TFU_INT_EN_TFU1_TRD3_INT_REQ_UF_EN_Pos)                                  /*!< TFU1_TRD3_INT_REQ_UF_EN Mask      0x00000010 */
#define TFU_TFU_INT_EN_TFU1_TRD3_INT_REQ_UF_EN_Set(x) (((uint32_t) (x) << TFU_TFU_INT_EN_TFU1_TRD3_INT_REQ_UF_EN_Pos) & TFU_TFU_INT_EN_TFU1_TRD3_INT_REQ_UF_EN_Msk) /*!< TFU1_TRD3_INT_REQ_UF_EN Set Value            */
#define TFU_TFU_INT_EN_TFU1_TRD3_INT_REQ_UF_EN_Get(x) (((uint32_t) (x) & TFU_TFU_INT_EN_TFU1_TRD3_INT_REQ_UF_EN_Msk) >> TFU_TFU_INT_EN_TFU1_TRD3_INT_REQ_UF_EN_Pos) /*!< TFU1_TRD3_INT_REQ_UF_EN Get Value            */

#define TFU_TFU_INT_EN_TFU1_TRD0_INT_REQ_OF_EN_Pos    (3U)                                                                                  /*!< TFU1_TRD0_INT_REQ_OF_EN Position  3          */ 
#define TFU_TFU_INT_EN_TFU1_TRD0_INT_REQ_OF_EN_Msk    (0x1U << TFU_TFU_INT_EN_TFU1_TRD0_INT_REQ_OF_EN_Pos)                                  /*!< TFU1_TRD0_INT_REQ_OF_EN Mask      0x00000008 */
#define TFU_TFU_INT_EN_TFU1_TRD0_INT_REQ_OF_EN_Set(x) (((uint32_t) (x) << TFU_TFU_INT_EN_TFU1_TRD0_INT_REQ_OF_EN_Pos) & TFU_TFU_INT_EN_TFU1_TRD0_INT_REQ_OF_EN_Msk) /*!< TFU1_TRD0_INT_REQ_OF_EN Set Value            */
#define TFU_TFU_INT_EN_TFU1_TRD0_INT_REQ_OF_EN_Get(x) (((uint32_t) (x) & TFU_TFU_INT_EN_TFU1_TRD0_INT_REQ_OF_EN_Msk) >> TFU_TFU_INT_EN_TFU1_TRD0_INT_REQ_OF_EN_Pos) /*!< TFU1_TRD0_INT_REQ_OF_EN Get Value            */

#define TFU_TFU_INT_EN_TFU1_TRD1_INT_REQ_OF_EN_Pos    (2U)                                                                                  /*!< TFU1_TRD1_INT_REQ_OF_EN Position  2          */ 
#define TFU_TFU_INT_EN_TFU1_TRD1_INT_REQ_OF_EN_Msk    (0x1U << TFU_TFU_INT_EN_TFU1_TRD1_INT_REQ_OF_EN_Pos)                                  /*!< TFU1_TRD1_INT_REQ_OF_EN Mask      0x00000004 */
#define TFU_TFU_INT_EN_TFU1_TRD1_INT_REQ_OF_EN_Set(x) (((uint32_t) (x) << TFU_TFU_INT_EN_TFU1_TRD1_INT_REQ_OF_EN_Pos) & TFU_TFU_INT_EN_TFU1_TRD1_INT_REQ_OF_EN_Msk) /*!< TFU1_TRD1_INT_REQ_OF_EN Set Value            */
#define TFU_TFU_INT_EN_TFU1_TRD1_INT_REQ_OF_EN_Get(x) (((uint32_t) (x) & TFU_TFU_INT_EN_TFU1_TRD1_INT_REQ_OF_EN_Msk) >> TFU_TFU_INT_EN_TFU1_TRD1_INT_REQ_OF_EN_Pos) /*!< TFU1_TRD1_INT_REQ_OF_EN Get Value            */

#define TFU_TFU_INT_EN_TFU1_TRD2_INT_REQ_OF_EN_Pos    (1U)                                                                                  /*!< TFU1_TRD2_INT_REQ_OF_EN Position  1          */ 
#define TFU_TFU_INT_EN_TFU1_TRD2_INT_REQ_OF_EN_Msk    (0x1U << TFU_TFU_INT_EN_TFU1_TRD2_INT_REQ_OF_EN_Pos)                                  /*!< TFU1_TRD2_INT_REQ_OF_EN Mask      0x00000002 */
#define TFU_TFU_INT_EN_TFU1_TRD2_INT_REQ_OF_EN_Set(x) (((uint32_t) (x) << TFU_TFU_INT_EN_TFU1_TRD2_INT_REQ_OF_EN_Pos) & TFU_TFU_INT_EN_TFU1_TRD2_INT_REQ_OF_EN_Msk) /*!< TFU1_TRD2_INT_REQ_OF_EN Set Value            */
#define TFU_TFU_INT_EN_TFU1_TRD2_INT_REQ_OF_EN_Get(x) (((uint32_t) (x) & TFU_TFU_INT_EN_TFU1_TRD2_INT_REQ_OF_EN_Msk) >> TFU_TFU_INT_EN_TFU1_TRD2_INT_REQ_OF_EN_Pos) /*!< TFU1_TRD2_INT_REQ_OF_EN Get Value            */

#define TFU_TFU_INT_EN_TFU1_TRD3_INT_REQ_OF_EN_Pos    (0U)                                                                                  /*!< TFU1_TRD3_INT_REQ_OF_EN Position  0          */ 
#define TFU_TFU_INT_EN_TFU1_TRD3_INT_REQ_OF_EN_Msk    (0x1U << TFU_TFU_INT_EN_TFU1_TRD3_INT_REQ_OF_EN_Pos)                                  /*!< TFU1_TRD3_INT_REQ_OF_EN Mask      0x00000001 */
#define TFU_TFU_INT_EN_TFU1_TRD3_INT_REQ_OF_EN_Set(x) (((uint32_t) (x) << TFU_TFU_INT_EN_TFU1_TRD3_INT_REQ_OF_EN_Pos) & TFU_TFU_INT_EN_TFU1_TRD3_INT_REQ_OF_EN_Msk) /*!< TFU1_TRD3_INT_REQ_OF_EN Set Value            */
#define TFU_TFU_INT_EN_TFU1_TRD3_INT_REQ_OF_EN_Get(x) (((uint32_t) (x) & TFU_TFU_INT_EN_TFU1_TRD3_INT_REQ_OF_EN_Msk) >> TFU_TFU_INT_EN_TFU1_TRD3_INT_REQ_OF_EN_Pos) /*!< TFU1_TRD3_INT_REQ_OF_EN Get Value            */

/*!
 * @}
 */

/*!
 * @}
 */ /* end of HS32F7D377_TFU_REGISTER */

#endif /* HS32F7D377_TFU_H */
