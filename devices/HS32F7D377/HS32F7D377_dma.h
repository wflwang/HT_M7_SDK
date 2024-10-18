/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


/*!
 * \file   HS32F7D377_dma.h
 * \brief  HS32F7D377 DMA register file
 * \version V1.0_20230809
 */

#ifndef HS32F7D377_DMA_H
#define HS32F7D377_DMA_H

/*!
 * \addtogroup   HS32F7D377_DMA_REGISTER HS32F7D377 DMA Register
 * \ingroup HS32F7D377_REGISTER
 *
 * \brief  DMA register layout, bitfield and address definitions
 *
 * @{
 */

/*!
 * \name DMA Register Layout
 *
 *
 * @{
 */

/*! \brief DMA register layout */
typedef struct {
    union
    {
        __IOM uint32_t CTRL;  /*!< 0x00000000 */ 
    
        struct
        {
            __IOM uint32_t CH1_PRIORITY              : 1 ;     /*!< [0:0] : 1: ch1 had higher priority. */
            __IOM uint32_t WDONE_SEL                 : 1 ;     /*!< [1:1] : sel whice done pull busy signal,1: write channel done; 0: reponse channel done. */
                  uint32_t RSV_2                     : 14;     /*!< [15:2] : reserved. */
            __IOM uint32_t FREE                      : 1 ;     /*!< [16:16] : debug ctrl ??. */
                  uint32_t RSV_1                     : 7 ;     /*!< [23:17] : reserved. */
            __IOM uint32_t HARD_RESET                : 1 ;     /*!< [24:24] : reset whole dma. */
            __IOM uint32_t PRIORITY_RESET            : 1 ;     /*!< [25:25] : reset round-robin state machine. */
                  uint32_t RSV_0                     : 6 ;     /*!< [31:26] : reserved. */
        } CTRLb;
    };

    union
    {
        __IM uint32_t STATUS;  /*!< 0x00000004 */ 
    
        struct
        {
            __IM  uint32_t ACTIVE_STS                : 3 ;     /*!< [2:0] : active channel status. */
                  uint32_t RSV_1                     : 1 ;     /*!< [3:3] : reserved. */
            __IM  uint32_t ACTIVE_STS_SHADOW         : 3 ;     /*!< [6:4] : active channel status shadow. */
                  uint32_t RSV_0                     : 25;     /*!< [31:7] : reserved. */
        } STATUSb;
    };

    uint8_t    RSV_0X8[248];   /*!< 0x00000008~0x000000ff : reserved */

    struct
    {
        union
        {
            __IOM uint32_t CH_CFG;  /*!< 0x00000100 */ 
        
            struct
            {
                __IOM uint32_t PERINTSEL                 : 8 ;     /*!< [7:0] : Peripheral Event Trigger Source Select. */
                __IOM uint32_t PERINTE                   : 1 ;     /*!< [8:8] : Peripheral Event Trigger Enable. */
                      uint32_t RSV_2                     : 7 ;     /*!< [15:9] : reserved. */
                __IOM uint32_t ONESHOT                   : 1 ;     /*!< [16:16] : 1: each peripheral event trigger causes the channel to perform an entire transfer;  0: the channel only performs one burst per trigger;. */
                __IOM uint32_t CONTINUOUS                : 1 ;     /*!< [17:17] : 1: channel re-initializes when TRANSFER_COUNT is zero and waits for next event trigger;  0: dma stops and clears the runsts bit. */
                      uint32_t RSV_1                     : 5 ;     /*!< [22:18] : reserved. */
                __IOM uint32_t BRESP_ERR_IE              : 1 ;     /*!< [23:23] : bresp err Interrupt Enable. */
                __IOM uint32_t RRESP_ERR_IE              : 1 ;     /*!< [24:24] : rresp err Interrupt Enable. */
                __IOM uint32_t OVR_IE                    : 1 ;     /*!< [25:25] : Overflow Interrupt Enable. */
                __IOM uint32_t TRANS_END_IE              : 1 ;     /*!< [26:26] : transfer end Interrupt Enable. */
                __IOM uint32_t TRANS_BEG_IE              : 1 ;     /*!< [27:27] : transfer begin Interrupt Enable. */
                      uint32_t RSV_0                     : 4 ;     /*!< [31:28] : reserved. */
            } CH_CFGb;
        };
    
        union
        {
            __IOM uint32_t CH_CTRL;  /*!< 0x00000104 */ 
        
            struct
            {
                __IOM uint32_t RUN                       : 1 ;     /*!< [0:0] : writing a 1 to this bit enables the dma channel and sets the runsts bit to 1. */
                __IOM uint32_t HALT                      : 1 ;     /*!< [1:1] : Writing a 1 to this bit halts the DMA channel in its current state after any ongoing read/write access has completed. */
                __IOM uint32_t SOFT_RESET                : 1 ;     /*!< [2:2] : writing a 1 to this bit places the channel into its default state after the current read/write access has completed. */
                __IOM uint32_t PERINTFRC                 : 1 ;     /*!< [3:3] : Force Peripheral Event Trigger, software trigger. */
                      uint32_t RSV_0                     : 28;     /*!< [31:4] : reserved. */
            } CH_CTRLb;
        };
    
        union
        {
            __IOM uint32_t CH_STS;  /*!< 0x00000108 */ 
        
            struct
            {
                __IOM uint32_t PERINT_CLR                : 1 ;     /*!< [0:0] : Clear Peripheral Event Trigger. */
                __IOM uint32_t OVR_CLR                   : 1 ;     /*!< [1:1] : Clear Error, overflag bit. */
                __IOM uint32_t TRANS_END_CLR             : 1 ;     /*!< [2:2] : clear ch1_trans_end_flg. */
                __IOM uint32_t TRANS_BEG_CLR             : 1 ;     /*!< [3:3] : clear ch1_trans_beg_flg. */
                __IOM uint32_t RRESP_ERR_CLR             : 1 ;     /*!< [4:4] : clear rresp err flg. */
                __IOM uint32_t BRESP_ERR_CLR             : 1 ;     /*!< [5:5] : clear bresp err flg. */
                      uint32_t RSV_2                     : 2 ;     /*!< [7:6] : reserved. */
                __IM  uint32_t PERINT_FLG                : 1 ;     /*!< [8:8] : Peripheral Event TriggerFlag. */
                __IM  uint32_t OVR_FLG                   : 1 ;     /*!< [9:9] : 1: overflow detectied;  0: no overflow detected;. */
                __IM  uint32_t TRANS_END_FLG             : 1 ;     /*!< [10:10] : 1: new transfer end has detected;  0: no transfer end has detected;. */
                __IM  uint32_t TRANS_BEG_FLG             : 1 ;     /*!< [11:11] : 1: new transfer begin has detected;  0: no transfer begin has detected;. */
                __IM  uint32_t RRESP_ERR_FLG             : 1 ;     /*!< [12:12] : 1: rresp err detected. */
                __IM  uint32_t BRESP_ERR_FLG             : 1 ;     /*!< [13:13] : 1: bresp err detected. */
                      uint32_t RSV_1                     : 2 ;     /*!< [15:14] : reserved. */
                __IM  uint32_t TRANSFERSTS               : 1 ;     /*!< [16:16] : 1: the channel is currently in the middle of a transfer;  0: no transfer activity;. */
                __IM  uint32_t BURSTSTS                  : 1 ;     /*!< [17:17] : 1: the dma is currently servicing or suspending a burst transfer from this channel;  0: no burst activity;. */
                __IM  uint32_t RUNSTS                    : 1 ;     /*!< [18:18] : 1: the channel is enable;  0: the channel is disable;. */
                      uint32_t RSV_0                     : 13;     /*!< [31:19] : reserved. */
            } CH_STSb;
        };
    
        union
        {
            __IOM uint32_t CH_BURST_SET;  /*!< 0x0000010c */ 
        
            struct
            {
                __IM  uint32_t BURST_COUNT               : 5 ;     /*!< [4:0] : These bits indicate the number of dwords left in the current burst. */
                      uint32_t RSV_2                     : 3 ;     /*!< [7:5] : reserved. */
                __IOM uint32_t BURST_SIZE                : 5 ;     /*!< [12:8] : These bits specify the burst size in dsize. */
                      uint32_t RSV_1                     : 3 ;     /*!< [15:13] : reserved. */
                __IOM uint32_t DSIZE                     : 2 ;     /*!< [17:16] : data size, 0x3,0x2:32bits; 0x1:16bits; 0x0:8bits. */
                      uint32_t RSV_0                     : 14;     /*!< [31:18] : reserved. */
            } CH_BURST_SETb;
        };
    
        union
        {
            __IOM uint32_t CH_SRC_BURST_STEP;  /*!< 0x00000110 */ 
        
            struct
            {
                __IOM uint32_t SRC_BURST_STEP            : 24;     /*!< [23:0] : These bits specify the change in the source address after each word in a burst. */
                      uint32_t RSV_0                     : 8 ;     /*!< [31:24] : reserved. */
            } CH_SRC_BURST_STEPb;
        };
    
        union
        {
            __IOM uint32_t CH_DST_BURST_STEP;  /*!< 0x00000114 */ 
        
            struct
            {
                __IOM uint32_t DST_BURST_STEP            : 24;     /*!< [23:0] : These bits specify the change in the destination address after each word in a burst. */
                      uint32_t RSV_0                     : 8 ;     /*!< [31:24] : reserved. */
            } CH_DST_BURST_STEPb;
        };
    
        union
        {
            __IOM uint32_t CH_TRANSFER_SET;  /*!< 0x00000118 */ 
        
            struct
            {
                __IM  uint32_t TRANS_COUNT               : 16;     /*!< [15:0] : These bits indicate the number of bursts left in the current transfer. */
                __IOM uint32_t TRANS_SIZE                : 16;     /*!< [31:16] : These bits specify the transfer size in bursts. */
            } CH_TRANSFER_SETb;
        };
    
        union
        {
            __IOM uint32_t CH_SRC_TRANSFER_STEP;  /*!< 0x0000011c */ 
        
            struct
            {
                __IOM uint32_t SRC_TRANS_STEP            : 24;     /*!< [23:0] : These bits specify the change in the source address after a burst completes. */
                      uint32_t RSV_0                     : 8 ;     /*!< [31:24] : reserved. */
            } CH_SRC_TRANSFER_STEPb;
        };
    
        union
        {
            __IOM uint32_t CH_DST_TRANSFER_STEP;  /*!< 0x00000120 */ 
        
            struct
            {
                __IOM uint32_t DST_TRANS_STEP            : 24;     /*!< [23:0] : These bits specify the change in the destination address after a burst completes. */
                      uint32_t RSV_0                     : 8 ;     /*!< [31:24] : reserved. */
            } CH_DST_TRANSFER_STEPb;
        };
    
        union
        {
            __IOM uint32_t CH_SRC_WRAP_SET;  /*!< 0x00000124 */ 
        
            struct
            {
                __IM  uint32_t SRC_WRAP_COUNT            : 16;     /*!< [15:0] : These bits indicate the number of bursts left before wrapping the source address. */
                __IOM uint32_t SRC_WRAP_SIZE             : 16;     /*!< [31:16] : These bits specify the number of bursts to transfer before the source address wraps around to the beginning address. */
            } CH_SRC_WRAP_SETb;
        };
    
        union
        {
            __IOM uint32_t CH_DST_WRAP_SET;  /*!< 0x00000128 */ 
        
            struct
            {
                __IM  uint32_t DST_WRAP_COUNT            : 16;     /*!< [15:0] : These bits indicate the number of bursts left before wrapping the destination address. */
                __IOM uint32_t DST_WRAP_SIZE             : 16;     /*!< [31:16] : These bits specify the number of bursts to transfer before the destination address wraps around to the beginning address. */
            } CH_DST_WRAP_SETb;
        };
    
        union
        {
            __IOM uint32_t CH_SRC_WRAP_STEP;  /*!< 0x0000012c */ 
        
            struct
            {
                __IOM uint32_t SRC_WRAP_STEP             : 24;     /*!< [23:0] : These bits specify the change in the source beginning address when the wrap counter reaches zero. */
                      uint32_t RSV_0                     : 8 ;     /*!< [31:24] : reserved. */
            } CH_SRC_WRAP_STEPb;
        };
    
        union
        {
            __IOM uint32_t CH_DST_WRAP_STEP;  /*!< 0x00000130 */ 
        
            struct
            {
                __IOM uint32_t DST_WRAP_STEP             : 24;     /*!< [23:0] : These bits specify the change in the destination beginning address when the wrap counter reaches zero. */
                      uint32_t RSV_0                     : 8 ;     /*!< [31:24] : reserved. */
            } CH_DST_WRAP_STEPb;
        };
    
        union
        {
            __IOM uint32_t CH_SRC_BEG_ADDR_SHADOW;  /*!< 0x00000134 */ 
        
            struct
            {
                __IOM uint32_t SRC_BEG_ADDR_SHADOW       : 32;     /*!< [31:0] : Shadow Source Beginning Address At the start of a transfer,  the value in this register is loaded into the SRC_BEG_ADDR_ACTIVE register and used as the beginning value for the source address. */
            } CH_SRC_BEG_ADDR_SHADOWb;
        };
    
        union
        {
            __IOM uint32_t CH_SRC_ADDR_SHADOW;  /*!< 0x00000138 */ 
        
            struct
            {
                __IOM uint32_t SRC_ADDR_SHADOW           : 32;     /*!< [31:0] : Shadow Source Address At the start of a transfer,  the value in this register is loaded into the SRC_ADDR_ACTIVE register and used as the value of the source address. */
            } CH_SRC_ADDR_SHADOWb;
        };
    
        union
        {
            __IM uint32_t CH_SRC_BEG_ADDR_ACTIVE;  /*!< 0x0000013c */ 
        
            struct
            {
                __IM  uint32_t SRC_BEG_ADDR_ACTIVE       : 32;     /*!< [31:0] : Active Source Beginning Address If a transfer is ongoing,  this register holds the current beginning value for the source address. */
            } CH_SRC_BEG_ADDR_ACTIVEb;
        };
    
        union
        {
            __IM uint32_t CH_SRC_ADDR_ACTIVE;  /*!< 0x00000140 */ 
        
            struct
            {
                __IM  uint32_t SRC_ADDR_ACTIVE           : 32;     /*!< [31:0] : Active Source Address If a transfer is ongoing, this register holds the current value of the source address. */
            } CH_SRC_ADDR_ACTIVEb;
        };
    
        union
        {
            __IOM uint32_t CH_DST_BEG_ADDR_SHADOW;  /*!< 0x00000144 */ 
        
            struct
            {
                __IOM uint32_t DST_BEG_ADDR_SHADOW       : 32;     /*!< [31:0] : Shadow Destination Beginning Address At the start of a transfer,  the value in this register is loaded into the DST_BEG_ADDR_ACTIVE register and used as the beginning value for the destination address. */
            } CH_DST_BEG_ADDR_SHADOWb;
        };
    
        union
        {
            __IOM uint32_t CH_DST_ADDR_SHADOW;  /*!< 0x00000148 */ 
        
            struct
            {
                __IOM uint32_t DST_ADDR_SHADOW           : 32;     /*!< [31:0] : Shadow Destination Address At the start of a transfer,  the value in this register is loaded into the DST_ADDR_ACTIVE register and used as the value of the destination address. */
            } CH_DST_ADDR_SHADOWb;
        };
    
        union
        {
            __IM uint32_t CH_DST_BEG_ADDR_ACTIVE;  /*!< 0x0000014c */ 
        
            struct
            {
                __IM  uint32_t DST_BEG_ADDR_ACTIVE       : 32;     /*!< [31:0] : Active Destination Beginning Address If a transfer is ongoing,  this register holds the current destination value for the source address. */
            } CH_DST_BEG_ADDR_ACTIVEb;
        };
    
        union
        {
            __IM uint32_t CH_DST_ADDR_ACTIVE;  /*!< 0x00000150 */ 
        
            struct
            {
                __IM  uint32_t DST_ADDR_ACTIVE           : 32;     /*!< [31:0] : Active Destination Address If a transfer is ongoing,  this register holds the current value of the destination address. */
            } CH_DST_ADDR_ACTIVEb;
        };

        uint8_t RSV_0X9[172];

    } CHANNEL[6]; /*!< 0x00000100~0x000006ff : register for DIEPTXF group */

    union
    {
        __IOM uint32_t AXI_AR_OUTSTANDING;  /*!< 0x00000700 */ 
    
        struct
        {
            __IOM uint32_t CH1_AXI_AR_OUTSTANDING    : 4 ;     /*!< [3:0] : ch1 axi ar outstanding. */
            __IOM uint32_t CH2_AXI_AR_OUTSTANDING    : 4 ;     /*!< [7:4] : ch2 axi ar outstanding. */
            __IOM uint32_t CH3_AXI_AR_OUTSTANDING    : 4 ;     /*!< [11:8] : ch3 axi ar outstanding. */
            __IOM uint32_t CH4_AXI_AR_OUTSTANDING    : 4 ;     /*!< [15:12] : ch4 axi ar outstanding. */
            __IOM uint32_t CH5_AXI_AR_OUTSTANDING    : 4 ;     /*!< [19:16] : ch5 axi ar outstanding. */
            __IOM uint32_t CH6_AXI_AR_OUTSTANDING    : 4 ;     /*!< [23:20] : ch6 axi ar outstanding. */
                  uint32_t RSV_0                     : 8 ;     /*!< [31:24] : reserved. */
        } AXI_AR_OUTSTANDINGb;
    };

    union
    {
        __IM uint32_t DFIFO_WL1;  /*!< 0x00000704 */ 
    
        struct
        {
            __IM  uint32_t D1_WATER_LEVEL            : 7 ;     /*!< [6:0] : ch1 rdata fifo waterlevel. */
                  uint32_t RSV_3                     : 1 ;     /*!< [7:7] : reserved. */
            __IM  uint32_t D2_WATER_LEVEL            : 7 ;     /*!< [14:8] : ch2 rdata fifo waterlevel. */
                  uint32_t RSV_2                     : 1 ;     /*!< [15:15] : reserved. */
            __IM  uint32_t D3_WATER_LEVEL            : 7 ;     /*!< [22:16] : ch3 rdata fifo waterlevel. */
                  uint32_t RSV_1                     : 1 ;     /*!< [23:23] : reserved. */
            __IM  uint32_t D4_WATER_LEVEL            : 7 ;     /*!< [30:24] : ch4 rdata fifo waterlevel. */
                  uint32_t RSV_0                     : 1 ;     /*!< [31:31] : reserved. */
        } DFIFO_WL1b;
    };

    union
    {
        __IM uint32_t DFIFO_WL2;  /*!< 0x00000708 */ 
    
        struct
        {
            __IM  uint32_t D5_WATER_LEVEL            : 7 ;     /*!< [6:0] : ch5 rdata fifo waterlevel. */
                  uint32_t RSV_1                     : 1 ;     /*!< [7:7] : reserved. */
            __IM  uint32_t D6_WATER_LEVEL            : 7 ;     /*!< [14:8] : ch6 rdata fifo waterlevel. */
                  uint32_t RSV_0                     : 17;     /*!< [31:15] : reserved. */
        } DFIFO_WL2b;
    };

    union
    {
        __IM uint32_t CFIFO_WL;  /*!< 0x0000070c */ 
    
        struct
        {
            __IM  uint32_t C1_WATER_LEVEL            : 3 ;     /*!< [2:0] : ch1 ar fifo waterlevel. */
                  uint32_t RSV_5                     : 1 ;     /*!< [3:3] : reserved. */
            __IM  uint32_t C2_WATER_LEVEL            : 3 ;     /*!< [6:4] : ch2 ar fifo waterlevel. */
                  uint32_t RSV_4                     : 1 ;     /*!< [7:7] : reserved. */
            __IM  uint32_t C3_WATER_LEVEL            : 3 ;     /*!< [10:8] : ch3 ar fifo waterlevel. */
                  uint32_t RSV_3                     : 1 ;     /*!< [11:11] : reserved. */
            __IM  uint32_t C4_WATER_LEVEL            : 3 ;     /*!< [14:12] : ch4 ar fifo waterlevel. */
                  uint32_t RSV_2                     : 1 ;     /*!< [15:15] : reserved. */
            __IM  uint32_t C5_WATER_LEVEL            : 3 ;     /*!< [18:16] : ch5 ar fifo waterlevel. */
                  uint32_t RSV_1                     : 1 ;     /*!< [19:19] : reserved. */
            __IM  uint32_t C6_WATER_LEVEL            : 3 ;     /*!< [22:20] : ch6 ar fifo waterlevel. */
                  uint32_t RSV_0                     : 9 ;     /*!< [31:23] : reserved. */
        } CFIFO_WLb;
    };

} DMA_Type;

/*!
 * @}
 */


/*!
 * \name DMA Base Address Definitions
 *
 * @{
 */

/*! \brief DMA base address */
#define DMA_BASE (0x41100000UL)
/*! \brief DMA base pointer */
#define DMA ((DMA_Type *) DMA_BASE)
/*! \brief DMA channel1 base pointer */
#define DMA_CH1_BASE    (0x41100100UL)
/*! \brief DMA channel2 base pointer */
#define DMA_CH2_BASE    (0x41100200UL)
/*! \brief DMA channel3 base pointer */
#define DMA_CH3_BASE    (0x41100300UL)
/*! \brief DMA channel4 base pointer */
#define DMA_CH4_BASE    (0x41100400UL)
/*! \brief DMA channel5 base pointer */
#define DMA_CH5_BASE    (0x41100500UL)
/*! \brief DMA channel6 base pointer */
#define DMA_CH6_BASE    (0x41100600UL)


/*!
 * @}
 */


/*!
 * \name DMA Register Bitfield Definitions
 *
 * @{
 */

/* CH_CFG bitfield */
#define DMA_CH_CFG_TRANS_BEG_IE_Pos    (27U)                                                                                 /*!< TRANS_BEG_IE Position  27         */ 
#define DMA_CH_CFG_TRANS_BEG_IE_Msk    (0x1U << DMA_CH_CFG_TRANS_BEG_IE_Pos)                                                 /*!< TRANS_BEG_IE Mask      0x08000000 */
#define DMA_CH_CFG_TRANS_BEG_IE_Set(x) (((uint32_t) (x) << DMA_CH_CFG_TRANS_BEG_IE_Pos) & DMA_CH_CFG_TRANS_BEG_IE_Msk)       /*!< TRANS_BEG_IE Set Value            */
#define DMA_CH_CFG_TRANS_BEG_IE_Get(x) (((uint32_t) (x) & DMA_CH_CFG_TRANS_BEG_IE_Msk) >> DMA_CH_CFG_TRANS_BEG_IE_Pos)       /*!< TRANS_BEG_IE Get Value            */

#define DMA_CH_CFG_TRANS_END_IE_Pos    (26U)                                                                                 /*!< TRANS_END_IE Position  26         */ 
#define DMA_CH_CFG_TRANS_END_IE_Msk    (0x1U << DMA_CH_CFG_TRANS_END_IE_Pos)                                                 /*!< TRANS_END_IE Mask      0x04000000 */
#define DMA_CH_CFG_TRANS_END_IE_Set(x) (((uint32_t) (x) << DMA_CH_CFG_TRANS_END_IE_Pos) & DMA_CH_CFG_TRANS_END_IE_Msk)       /*!< TRANS_END_IE Set Value            */
#define DMA_CH_CFG_TRANS_END_IE_Get(x) (((uint32_t) (x) & DMA_CH_CFG_TRANS_END_IE_Msk) >> DMA_CH_CFG_TRANS_END_IE_Pos)       /*!< TRANS_END_IE Get Value            */

#define DMA_CH_CFG_OVR_IE_Pos    (25U)                                                                                 /*!< OVR_IE Position  25         */ 
#define DMA_CH_CFG_OVR_IE_Msk    (0x1U << DMA_CH_CFG_OVR_IE_Pos)                                                       /*!< OVR_IE Mask      0x02000000 */
#define DMA_CH_CFG_OVR_IE_Set(x) (((uint32_t) (x) << DMA_CH_CFG_OVR_IE_Pos) & DMA_CH_CFG_OVR_IE_Msk)                   /*!< OVR_IE Set Value            */
#define DMA_CH_CFG_OVR_IE_Get(x) (((uint32_t) (x) & DMA_CH_CFG_OVR_IE_Msk) >> DMA_CH_CFG_OVR_IE_Pos)                   /*!< OVR_IE Get Value            */

#define DMA_CH_CFG_RRESP_ERR_IE_Pos    (24U)                                                                                 /*!< RRESP_ERR_IE Position  24         */ 
#define DMA_CH_CFG_RRESP_ERR_IE_Msk    (0x1U << DMA_CH_CFG_RRESP_ERR_IE_Pos)                                                 /*!< RRESP_ERR_IE Mask      0x01000000 */
#define DMA_CH_CFG_RRESP_ERR_IE_Set(x) (((uint32_t) (x) << DMA_CH_CFG_RRESP_ERR_IE_Pos) & DMA_CH_CFG_RRESP_ERR_IE_Msk)       /*!< RRESP_ERR_IE Set Value            */
#define DMA_CH_CFG_RRESP_ERR_IE_Get(x) (((uint32_t) (x) & DMA_CH_CFG_RRESP_ERR_IE_Msk) >> DMA_CH_CFG_RRESP_ERR_IE_Pos)       /*!< RRESP_ERR_IE Get Value            */

#define DMA_CH_CFG_BRESP_ERR_IE_Pos    (23U)                                                                                 /*!< BRESP_ERR_IE Position  23         */ 
#define DMA_CH_CFG_BRESP_ERR_IE_Msk    (0x1U << DMA_CH_CFG_BRESP_ERR_IE_Pos)                                                 /*!< BRESP_ERR_IE Mask      0x00800000 */
#define DMA_CH_CFG_BRESP_ERR_IE_Set(x) (((uint32_t) (x) << DMA_CH_CFG_BRESP_ERR_IE_Pos) & DMA_CH_CFG_BRESP_ERR_IE_Msk)       /*!< BRESP_ERR_IE Set Value            */
#define DMA_CH_CFG_BRESP_ERR_IE_Get(x) (((uint32_t) (x) & DMA_CH_CFG_BRESP_ERR_IE_Msk) >> DMA_CH_CFG_BRESP_ERR_IE_Pos)       /*!< BRESP_ERR_IE Get Value            */

#define DMA_CH_CFG_CONTINUOUS_Pos    (17U)                                                                                 /*!< CONTINUOUS Position  17         */ 
#define DMA_CH_CFG_CONTINUOUS_Msk    (0x1U << DMA_CH_CFG_CONTINUOUS_Pos)                                                   /*!< CONTINUOUS Mask      0x00020000 */
#define DMA_CH_CFG_CONTINUOUS_Set(x) (((uint32_t) (x) << DMA_CH_CFG_CONTINUOUS_Pos) & DMA_CH_CFG_CONTINUOUS_Msk)           /*!< CONTINUOUS Set Value            */
#define DMA_CH_CFG_CONTINUOUS_Get(x) (((uint32_t) (x) & DMA_CH_CFG_CONTINUOUS_Msk) >> DMA_CH_CFG_CONTINUOUS_Pos)           /*!< CONTINUOUS Get Value            */

#define DMA_CH_CFG_ONESHOT_Pos    (16U)                                                                                 /*!< ONESHOT Position  16         */ 
#define DMA_CH_CFG_ONESHOT_Msk    (0x1U << DMA_CH_CFG_ONESHOT_Pos)                                                      /*!< ONESHOT Mask      0x00010000 */
#define DMA_CH_CFG_ONESHOT_Set(x) (((uint32_t) (x) << DMA_CH_CFG_ONESHOT_Pos) & DMA_CH_CFG_ONESHOT_Msk)                 /*!< ONESHOT Set Value            */
#define DMA_CH_CFG_ONESHOT_Get(x) (((uint32_t) (x) & DMA_CH_CFG_ONESHOT_Msk) >> DMA_CH_CFG_ONESHOT_Pos)                 /*!< ONESHOT Get Value            */

#define DMA_CH_CFG_PERINTE_Pos    (8U)                                                                                  /*!< PERINTE Position  8          */ 
#define DMA_CH_CFG_PERINTE_Msk    (0x1U << DMA_CH_CFG_PERINTE_Pos)                                                      /*!< PERINTE Mask      0x00000100 */
#define DMA_CH_CFG_PERINTE_Set(x) (((uint32_t) (x) << DMA_CH_CFG_PERINTE_Pos) & DMA_CH_CFG_PERINTE_Msk)                 /*!< PERINTE Set Value            */
#define DMA_CH_CFG_PERINTE_Get(x) (((uint32_t) (x) & DMA_CH_CFG_PERINTE_Msk) >> DMA_CH_CFG_PERINTE_Pos)                 /*!< PERINTE Get Value            */

#define DMA_CH_CFG_PERINTSEL_Pos    (0U)                                                                                  /*!< PERINTSEL Position  0          */ 
#define DMA_CH_CFG_PERINTSEL_Msk    (0xffU << DMA_CH_CFG_PERINTSEL_Pos)                                                   /*!< PERINTSEL Mask      0x000000FF */
#define DMA_CH_CFG_PERINTSEL_Set(x) (((uint32_t) (x) << DMA_CH_CFG_PERINTSEL_Pos) & DMA_CH_CFG_PERINTSEL_Msk)             /*!< PERINTSEL Set Value            */
#define DMA_CH_CFG_PERINTSEL_Get(x) (((uint32_t) (x) & DMA_CH_CFG_PERINTSEL_Msk) >> DMA_CH_CFG_PERINTSEL_Pos)             /*!< PERINTSEL Get Value            */

/* CH_CTRL bitfield */
#define DMA_CH_CTRL_PERINTFRC_Pos    (3U)                                                                                  /*!< PERINTFRC Position  3          */ 
#define DMA_CH_CTRL_PERINTFRC_Msk    (0x1U << DMA_CH_CTRL_PERINTFRC_Pos)                                                   /*!< PERINTFRC Mask      0x00000008 */
#define DMA_CH_CTRL_PERINTFRC_Set(x) (((uint32_t) (x) << DMA_CH_CTRL_PERINTFRC_Pos) & DMA_CH_CTRL_PERINTFRC_Msk)           /*!< PERINTFRC Set Value            */
#define DMA_CH_CTRL_PERINTFRC_Get(x) (((uint32_t) (x) & DMA_CH_CTRL_PERINTFRC_Msk) >> DMA_CH_CTRL_PERINTFRC_Pos)           /*!< PERINTFRC Get Value            */

#define DMA_CH_CTRL_SOFT_RESET_Pos    (2U)                                                                                  /*!< SOFT_RESET Position  2          */ 
#define DMA_CH_CTRL_SOFT_RESET_Msk    (0x1U << DMA_CH_CTRL_SOFT_RESET_Pos)                                                  /*!< SOFT_RESET Mask      0x00000004 */
#define DMA_CH_CTRL_SOFT_RESET_Set(x) (((uint32_t) (x) << DMA_CH_CTRL_SOFT_RESET_Pos) & DMA_CH_CTRL_SOFT_RESET_Msk)         /*!< SOFT_RESET Set Value            */
#define DMA_CH_CTRL_SOFT_RESET_Get(x) (((uint32_t) (x) & DMA_CH_CTRL_SOFT_RESET_Msk) >> DMA_CH_CTRL_SOFT_RESET_Pos)         /*!< SOFT_RESET Get Value            */

#define DMA_CH_CTRL_HALT_Pos    (1U)                                                                                  /*!< HALT Position  1          */ 
#define DMA_CH_CTRL_HALT_Msk    (0x1U << DMA_CH_CTRL_HALT_Pos)                                                        /*!< HALT Mask      0x00000002 */
#define DMA_CH_CTRL_HALT_Set(x) (((uint32_t) (x) << DMA_CH_CTRL_HALT_Pos) & DMA_CH_CTRL_HALT_Msk)                     /*!< HALT Set Value            */
#define DMA_CH_CTRL_HALT_Get(x) (((uint32_t) (x) & DMA_CH_CTRL_HALT_Msk) >> DMA_CH_CTRL_HALT_Pos)                     /*!< HALT Get Value            */

#define DMA_CH_CTRL_RUN_Pos    (0U)                                                                                  /*!< RUN Position  0          */ 
#define DMA_CH_CTRL_RUN_Msk    (0x1U << DMA_CH_CTRL_RUN_Pos)                                                         /*!< RUN Mask      0x00000001 */
#define DMA_CH_CTRL_RUN_Set(x) (((uint32_t) (x) << DMA_CH_CTRL_RUN_Pos) & DMA_CH_CTRL_RUN_Msk)                       /*!< RUN Set Value            */
#define DMA_CH_CTRL_RUN_Get(x) (((uint32_t) (x) & DMA_CH_CTRL_RUN_Msk) >> DMA_CH_CTRL_RUN_Pos)                       /*!< RUN Get Value            */

/* CH_STS bitfield */
#define DMA_CH_STS_RUNSTS_Pos    (18U)                                                                                 /*!< RUNSTS Position  18         */ 
#define DMA_CH_STS_RUNSTS_Msk    (0x1U << DMA_CH_STS_RUNSTS_Pos)                                                       /*!< RUNSTS Mask      0x00040000 */
#define DMA_CH_STS_RUNSTS_Set(x) (((uint32_t) (x) << DMA_CH_STS_RUNSTS_Pos) & DMA_CH_STS_RUNSTS_Msk)                   /*!< RUNSTS Set Value            */
#define DMA_CH_STS_RUNSTS_Get(x) (((uint32_t) (x) & DMA_CH_STS_RUNSTS_Msk) >> DMA_CH_STS_RUNSTS_Pos)                   /*!< RUNSTS Get Value            */

#define DMA_CH_STS_BURSTSTS_Pos    (17U)                                                                                 /*!< BURSTSTS Position  17         */ 
#define DMA_CH_STS_BURSTSTS_Msk    (0x1U << DMA_CH_STS_BURSTSTS_Pos)                                                     /*!< BURSTSTS Mask      0x00020000 */
#define DMA_CH_STS_BURSTSTS_Set(x) (((uint32_t) (x) << DMA_CH_STS_BURSTSTS_Pos) & DMA_CH_STS_BURSTSTS_Msk)               /*!< BURSTSTS Set Value            */
#define DMA_CH_STS_BURSTSTS_Get(x) (((uint32_t) (x) & DMA_CH_STS_BURSTSTS_Msk) >> DMA_CH_STS_BURSTSTS_Pos)               /*!< BURSTSTS Get Value            */

#define DMA_CH_STS_TRANSFERSTS_Pos    (16U)                                                                                 /*!< TRANSFERSTS Position  16         */ 
#define DMA_CH_STS_TRANSFERSTS_Msk    (0x1U << DMA_CH_STS_TRANSFERSTS_Pos)                                                  /*!< TRANSFERSTS Mask      0x00010000 */
#define DMA_CH_STS_TRANSFERSTS_Set(x) (((uint32_t) (x) << DMA_CH_STS_TRANSFERSTS_Pos) & DMA_CH_STS_TRANSFERSTS_Msk)         /*!< TRANSFERSTS Set Value            */
#define DMA_CH_STS_TRANSFERSTS_Get(x) (((uint32_t) (x) & DMA_CH_STS_TRANSFERSTS_Msk) >> DMA_CH_STS_TRANSFERSTS_Pos)         /*!< TRANSFERSTS Get Value            */

#define DMA_CH_STS_BRESP_ERR_FLG_Pos    (13U)                                                                                 /*!< BRESP_ERR_FLG Position  13         */ 
#define DMA_CH_STS_BRESP_ERR_FLG_Msk    (0x1U << DMA_CH_STS_BRESP_ERR_FLG_Pos)                                                /*!< BRESP_ERR_FLG Mask      0x00002000 */
#define DMA_CH_STS_BRESP_ERR_FLG_Set(x) (((uint32_t) (x) << DMA_CH_STS_BRESP_ERR_FLG_Pos) & DMA_CH_STS_BRESP_ERR_FLG_Msk)     /*!< BRESP_ERR_FLG Set Value            */
#define DMA_CH_STS_BRESP_ERR_FLG_Get(x) (((uint32_t) (x) & DMA_CH_STS_BRESP_ERR_FLG_Msk) >> DMA_CH_STS_BRESP_ERR_FLG_Pos)     /*!< BRESP_ERR_FLG Get Value            */

#define DMA_CH_STS_RRESP_ERR_FLG_Pos    (12U)                                                                                 /*!< RRESP_ERR_FLG Position  12         */ 
#define DMA_CH_STS_RRESP_ERR_FLG_Msk    (0x1U << DMA_CH_STS_RRESP_ERR_FLG_Pos)                                                /*!< RRESP_ERR_FLG Mask      0x00001000 */
#define DMA_CH_STS_RRESP_ERR_FLG_Set(x) (((uint32_t) (x) << DMA_CH_STS_RRESP_ERR_FLG_Pos) & DMA_CH_STS_RRESP_ERR_FLG_Msk)     /*!< RRESP_ERR_FLG Set Value            */
#define DMA_CH_STS_RRESP_ERR_FLG_Get(x) (((uint32_t) (x) & DMA_CH_STS_RRESP_ERR_FLG_Msk) >> DMA_CH_STS_RRESP_ERR_FLG_Pos)     /*!< RRESP_ERR_FLG Get Value            */

#define DMA_CH_STS_TRANS_BEG_FLG_Pos    (11U)                                                                                 /*!< TRANS_BEG_FLG Position  11         */ 
#define DMA_CH_STS_TRANS_BEG_FLG_Msk    (0x1U << DMA_CH_STS_TRANS_BEG_FLG_Pos)                                                /*!< TRANS_BEG_FLG Mask      0x00000800 */
#define DMA_CH_STS_TRANS_BEG_FLG_Set(x) (((uint32_t) (x) << DMA_CH_STS_TRANS_BEG_FLG_Pos) & DMA_CH_STS_TRANS_BEG_FLG_Msk)     /*!< TRANS_BEG_FLG Set Value            */
#define DMA_CH_STS_TRANS_BEG_FLG_Get(x) (((uint32_t) (x) & DMA_CH_STS_TRANS_BEG_FLG_Msk) >> DMA_CH_STS_TRANS_BEG_FLG_Pos)     /*!< TRANS_BEG_FLG Get Value            */

#define DMA_CH_STS_TRANS_END_FLG_Pos    (10U)                                                                                 /*!< TRANS_END_FLG Position  10         */ 
#define DMA_CH_STS_TRANS_END_FLG_Msk    (0x1U << DMA_CH_STS_TRANS_END_FLG_Pos)                                                /*!< TRANS_END_FLG Mask      0x00000400 */
#define DMA_CH_STS_TRANS_END_FLG_Set(x) (((uint32_t) (x) << DMA_CH_STS_TRANS_END_FLG_Pos) & DMA_CH_STS_TRANS_END_FLG_Msk)     /*!< TRANS_END_FLG Set Value            */
#define DMA_CH_STS_TRANS_END_FLG_Get(x) (((uint32_t) (x) & DMA_CH_STS_TRANS_END_FLG_Msk) >> DMA_CH_STS_TRANS_END_FLG_Pos)     /*!< TRANS_END_FLG Get Value            */

#define DMA_CH_STS_OVR_FLG_Pos    (9U)                                                                                  /*!< OVR_FLG Position  9          */ 
#define DMA_CH_STS_OVR_FLG_Msk    (0x1U << DMA_CH_STS_OVR_FLG_Pos)                                                      /*!< OVR_FLG Mask      0x00000200 */
#define DMA_CH_STS_OVR_FLG_Set(x) (((uint32_t) (x) << DMA_CH_STS_OVR_FLG_Pos) & DMA_CH_STS_OVR_FLG_Msk)                 /*!< OVR_FLG Set Value            */
#define DMA_CH_STS_OVR_FLG_Get(x) (((uint32_t) (x) & DMA_CH_STS_OVR_FLG_Msk) >> DMA_CH_STS_OVR_FLG_Pos)                 /*!< OVR_FLG Get Value            */

#define DMA_CH_STS_PERINT_FLG_Pos    (8U)                                                                                  /*!< PERINT_FLG Position  8          */ 
#define DMA_CH_STS_PERINT_FLG_Msk    (0x1U << DMA_CH_STS_PERINT_FLG_Pos)                                                   /*!< PERINT_FLG Mask      0x00000100 */
#define DMA_CH_STS_PERINT_FLG_Set(x) (((uint32_t) (x) << DMA_CH_STS_PERINT_FLG_Pos) & DMA_CH_STS_PERINT_FLG_Msk)           /*!< PERINT_FLG Set Value            */
#define DMA_CH_STS_PERINT_FLG_Get(x) (((uint32_t) (x) & DMA_CH_STS_PERINT_FLG_Msk) >> DMA_CH_STS_PERINT_FLG_Pos)           /*!< PERINT_FLG Get Value            */

#define DMA_CH_STS_BRESP_ERR_CLR_Pos    (5U)                                                                                  /*!< BRESP_ERR_CLR Position  5          */ 
#define DMA_CH_STS_BRESP_ERR_CLR_Msk    (0x1U << DMA_CH_STS_BRESP_ERR_CLR_Pos)                                                /*!< BRESP_ERR_CLR Mask      0x00000020 */
#define DMA_CH_STS_BRESP_ERR_CLR_Set(x) (((uint32_t) (x) << DMA_CH_STS_BRESP_ERR_CLR_Pos) & DMA_CH_STS_BRESP_ERR_CLR_Msk)     /*!< BRESP_ERR_CLR Set Value            */
#define DMA_CH_STS_BRESP_ERR_CLR_Get(x) (((uint32_t) (x) & DMA_CH_STS_BRESP_ERR_CLR_Msk) >> DMA_CH_STS_BRESP_ERR_CLR_Pos)     /*!< BRESP_ERR_CLR Get Value            */

#define DMA_CH_STS_RRESP_ERR_CLR_Pos    (4U)                                                                                  /*!< RRESP_ERR_CLR Position  4          */ 
#define DMA_CH_STS_RRESP_ERR_CLR_Msk    (0x1U << DMA_CH_STS_RRESP_ERR_CLR_Pos)                                                /*!< RRESP_ERR_CLR Mask      0x00000010 */
#define DMA_CH_STS_RRESP_ERR_CLR_Set(x) (((uint32_t) (x) << DMA_CH_STS_RRESP_ERR_CLR_Pos) & DMA_CH_STS_RRESP_ERR_CLR_Msk)     /*!< RRESP_ERR_CLR Set Value            */
#define DMA_CH_STS_RRESP_ERR_CLR_Get(x) (((uint32_t) (x) & DMA_CH_STS_RRESP_ERR_CLR_Msk) >> DMA_CH_STS_RRESP_ERR_CLR_Pos)     /*!< RRESP_ERR_CLR Get Value            */

#define DMA_CH_STS_TRANS_BEG_CLR_Pos    (3U)                                                                                  /*!< TRANS_BEG_CLR Position  3          */ 
#define DMA_CH_STS_TRANS_BEG_CLR_Msk    (0x1U << DMA_CH_STS_TRANS_BEG_CLR_Pos)                                                /*!< TRANS_BEG_CLR Mask      0x00000008 */
#define DMA_CH_STS_TRANS_BEG_CLR_Set(x) (((uint32_t) (x) << DMA_CH_STS_TRANS_BEG_CLR_Pos) & DMA_CH_STS_TRANS_BEG_CLR_Msk)     /*!< TRANS_BEG_CLR Set Value            */
#define DMA_CH_STS_TRANS_BEG_CLR_Get(x) (((uint32_t) (x) & DMA_CH_STS_TRANS_BEG_CLR_Msk) >> DMA_CH_STS_TRANS_BEG_CLR_Pos)     /*!< TRANS_BEG_CLR Get Value            */

#define DMA_CH_STS_TRANS_END_CLR_Pos    (2U)                                                                                  /*!< TRANS_END_CLR Position  2          */ 
#define DMA_CH_STS_TRANS_END_CLR_Msk    (0x1U << DMA_CH_STS_TRANS_END_CLR_Pos)                                                /*!< TRANS_END_CLR Mask      0x00000004 */
#define DMA_CH_STS_TRANS_END_CLR_Set(x) (((uint32_t) (x) << DMA_CH_STS_TRANS_END_CLR_Pos) & DMA_CH_STS_TRANS_END_CLR_Msk)     /*!< TRANS_END_CLR Set Value            */
#define DMA_CH_STS_TRANS_END_CLR_Get(x) (((uint32_t) (x) & DMA_CH_STS_TRANS_END_CLR_Msk) >> DMA_CH_STS_TRANS_END_CLR_Pos)     /*!< TRANS_END_CLR Get Value            */

#define DMA_CH_STS_OVR_CLR_Pos    (1U)                                                                                  /*!< OVR_CLR Position  1          */ 
#define DMA_CH_STS_OVR_CLR_Msk    (0x1U << DMA_CH_STS_OVR_CLR_Pos)                                                      /*!< OVR_CLR Mask      0x00000002 */
#define DMA_CH_STS_OVR_CLR_Set(x) (((uint32_t) (x) << DMA_CH_STS_OVR_CLR_Pos) & DMA_CH_STS_OVR_CLR_Msk)                 /*!< OVR_CLR Set Value            */
#define DMA_CH_STS_OVR_CLR_Get(x) (((uint32_t) (x) & DMA_CH_STS_OVR_CLR_Msk) >> DMA_CH_STS_OVR_CLR_Pos)                 /*!< OVR_CLR Get Value            */

#define DMA_CH_STS_PERINT_CLR_Pos    (0U)                                                                                  /*!< PERINT_CLR Position  0          */ 
#define DMA_CH_STS_PERINT_CLR_Msk    (0x1U << DMA_CH_STS_PERINT_CLR_Pos)                                                   /*!< PERINT_CLR Mask      0x00000001 */
#define DMA_CH_STS_PERINT_CLR_Set(x) (((uint32_t) (x) << DMA_CH_STS_PERINT_CLR_Pos) & DMA_CH_STS_PERINT_CLR_Msk)           /*!< PERINT_CLR Set Value            */
#define DMA_CH_STS_PERINT_CLR_Get(x) (((uint32_t) (x) & DMA_CH_STS_PERINT_CLR_Msk) >> DMA_CH_STS_PERINT_CLR_Pos)           /*!< PERINT_CLR Get Value            */

/* CH_BURST_SET bitfield */
#define DMA_CH_BURST_SET_DSIZE_Pos    (16U)                                                                                 /*!< DSIZE Position  16         */ 
#define DMA_CH_BURST_SET_DSIZE_Msk    (0x3U << DMA_CH_BURST_SET_DSIZE_Pos)                                                  /*!< DSIZE Mask      0x00030000 */
#define DMA_CH_BURST_SET_DSIZE_Set(x) (((uint32_t) (x) << DMA_CH_BURST_SET_DSIZE_Pos) & DMA_CH_BURST_SET_DSIZE_Msk)         /*!< DSIZE Set Value            */
#define DMA_CH_BURST_SET_DSIZE_Get(x) (((uint32_t) (x) & DMA_CH_BURST_SET_DSIZE_Msk) >> DMA_CH_BURST_SET_DSIZE_Pos)         /*!< DSIZE Get Value            */

#define DMA_CH_BURST_SET_BURST_SIZE_Pos    (8U)                                                                                  /*!< BURST_SIZE Position  8          */ 
#define DMA_CH_BURST_SET_BURST_SIZE_Msk    (0x1fU << DMA_CH_BURST_SET_BURST_SIZE_Pos)                                            /*!< BURST_SIZE Mask      0x00001F00 */
#define DMA_CH_BURST_SET_BURST_SIZE_Set(x) (((uint32_t) (x) << DMA_CH_BURST_SET_BURST_SIZE_Pos) & DMA_CH_BURST_SET_BURST_SIZE_Msk) /*!< BURST_SIZE Set Value            */
#define DMA_CH_BURST_SET_BURST_SIZE_Get(x) (((uint32_t) (x) & DMA_CH_BURST_SET_BURST_SIZE_Msk) >> DMA_CH_BURST_SET_BURST_SIZE_Pos) /*!< BURST_SIZE Get Value            */

#define DMA_CH_BURST_SET_BURST_COUNT_Pos    (0U)                                                                                  /*!< BURST_COUNT Position  0          */ 
#define DMA_CH_BURST_SET_BURST_COUNT_Msk    (0x1fU << DMA_CH_BURST_SET_BURST_COUNT_Pos)                                           /*!< BURST_COUNT Mask      0x0000001F */
#define DMA_CH_BURST_SET_BURST_COUNT_Set(x) (((uint32_t) (x) << DMA_CH_BURST_SET_BURST_COUNT_Pos) & DMA_CH_BURST_SET_BURST_COUNT_Msk) /*!< BURST_COUNT Set Value            */
#define DMA_CH_BURST_SET_BURST_COUNT_Get(x) (((uint32_t) (x) & DMA_CH_BURST_SET_BURST_COUNT_Msk) >> DMA_CH_BURST_SET_BURST_COUNT_Pos) /*!< BURST_COUNT Get Value            */

/* CH_SRC_BURST_STEP bitfield */
#define DMA_CH_SRC_BURST_STEP_SRC_BURST_STEP_Pos    (0U)                                                                                  /*!< SRC_BURST_STEP Position  0          */ 
#define DMA_CH_SRC_BURST_STEP_SRC_BURST_STEP_Msk    (0xffffffU << DMA_CH_SRC_BURST_STEP_SRC_BURST_STEP_Pos)                               /*!< SRC_BURST_STEP Mask      0x00FFFFFF */
#define DMA_CH_SRC_BURST_STEP_SRC_BURST_STEP_Set(x) (((uint32_t) (x) << DMA_CH_SRC_BURST_STEP_SRC_BURST_STEP_Pos) & DMA_CH_SRC_BURST_STEP_SRC_BURST_STEP_Msk) /*!< SRC_BURST_STEP Set Value            */
#define DMA_CH_SRC_BURST_STEP_SRC_BURST_STEP_Get(x) (((uint32_t) (x) & DMA_CH_SRC_BURST_STEP_SRC_BURST_STEP_Msk) >> DMA_CH_SRC_BURST_STEP_SRC_BURST_STEP_Pos) /*!< SRC_BURST_STEP Get Value            */

/* CH_DST_BURST_STEP bitfield */
#define DMA_CH_DST_BURST_STEP_DST_BURST_STEP_Pos    (0U)                                                                                  /*!< DST_BURST_STEP Position  0          */ 
#define DMA_CH_DST_BURST_STEP_DST_BURST_STEP_Msk    (0xffffffU << DMA_CH_DST_BURST_STEP_DST_BURST_STEP_Pos)                               /*!< DST_BURST_STEP Mask      0x00FFFFFF */
#define DMA_CH_DST_BURST_STEP_DST_BURST_STEP_Set(x) (((uint32_t) (x) << DMA_CH_DST_BURST_STEP_DST_BURST_STEP_Pos) & DMA_CH_DST_BURST_STEP_DST_BURST_STEP_Msk) /*!< DST_BURST_STEP Set Value            */
#define DMA_CH_DST_BURST_STEP_DST_BURST_STEP_Get(x) (((uint32_t) (x) & DMA_CH_DST_BURST_STEP_DST_BURST_STEP_Msk) >> DMA_CH_DST_BURST_STEP_DST_BURST_STEP_Pos) /*!< DST_BURST_STEP Get Value            */

/* CH_TRANSFER_SET bitfield */
#define DMA_CH_TRANSFER_SET_TRANS_SIZE_Pos    (16U)                                                                                 /*!< TRANS_SIZE Position  16         */ 
#define DMA_CH_TRANSFER_SET_TRANS_SIZE_Msk    (0xffffU << DMA_CH_TRANSFER_SET_TRANS_SIZE_Pos)                                       /*!< TRANS_SIZE Mask      0xFFFF0000 */
#define DMA_CH_TRANSFER_SET_TRANS_SIZE_Set(x) (((uint32_t) (x) << DMA_CH_TRANSFER_SET_TRANS_SIZE_Pos) & DMA_CH_TRANSFER_SET_TRANS_SIZE_Msk) /*!< TRANS_SIZE Set Value            */
#define DMA_CH_TRANSFER_SET_TRANS_SIZE_Get(x) (((uint32_t) (x) & DMA_CH_TRANSFER_SET_TRANS_SIZE_Msk) >> DMA_CH_TRANSFER_SET_TRANS_SIZE_Pos) /*!< TRANS_SIZE Get Value            */

#define DMA_CH_TRANSFER_SET_TRANS_COUNT_Pos    (0U)                                                                                  /*!< TRANS_COUNT Position  0          */ 
#define DMA_CH_TRANSFER_SET_TRANS_COUNT_Msk    (0xffffU << DMA_CH_TRANSFER_SET_TRANS_COUNT_Pos)                                      /*!< TRANS_COUNT Mask      0x0000FFFF */
#define DMA_CH_TRANSFER_SET_TRANS_COUNT_Set(x) (((uint32_t) (x) << DMA_CH_TRANSFER_SET_TRANS_COUNT_Pos) & DMA_CH_TRANSFER_SET_TRANS_COUNT_Msk) /*!< TRANS_COUNT Set Value            */
#define DMA_CH_TRANSFER_SET_TRANS_COUNT_Get(x) (((uint32_t) (x) & DMA_CH_TRANSFER_SET_TRANS_COUNT_Msk) >> DMA_CH_TRANSFER_SET_TRANS_COUNT_Pos) /*!< TRANS_COUNT Get Value            */

/* CH_SRC_TRANSFER_STEP bitfield */
#define DMA_CH_SRC_TRANSFER_STEP_SRC_TRANS_STEP_Pos    (0U)                                                                                  /*!< SRC_TRANS_STEP Position  0          */ 
#define DMA_CH_SRC_TRANSFER_STEP_SRC_TRANS_STEP_Msk    (0xffffffU << DMA_CH_SRC_TRANSFER_STEP_SRC_TRANS_STEP_Pos)                            /*!< SRC_TRANS_STEP Mask      0x00FFFFFF */
#define DMA_CH_SRC_TRANSFER_STEP_SRC_TRANS_STEP_Set(x) (((uint32_t) (x) << DMA_CH_SRC_TRANSFER_STEP_SRC_TRANS_STEP_Pos) & DMA_CH_SRC_TRANSFER_STEP_SRC_TRANS_STEP_Msk) /*!< SRC_TRANS_STEP Set Value            */
#define DMA_CH_SRC_TRANSFER_STEP_SRC_TRANS_STEP_Get(x) (((uint32_t) (x) & DMA_CH_SRC_TRANSFER_STEP_SRC_TRANS_STEP_Msk) >> DMA_CH_SRC_TRANSFER_STEP_SRC_TRANS_STEP_Pos) /*!< SRC_TRANS_STEP Get Value            */

/* CH_DST_TRANSFER_STEP bitfield */
#define DMA_CH_DST_TRANSFER_STEP_DST_TRANS_STEP_Pos    (0U)                                                                                  /*!< DST_TRANS_STEP Position  0          */ 
#define DMA_CH_DST_TRANSFER_STEP_DST_TRANS_STEP_Msk    (0xffffffU << DMA_CH_DST_TRANSFER_STEP_DST_TRANS_STEP_Pos)                            /*!< DST_TRANS_STEP Mask      0x00FFFFFF */
#define DMA_CH_DST_TRANSFER_STEP_DST_TRANS_STEP_Set(x) (((uint32_t) (x) << DMA_CH_DST_TRANSFER_STEP_DST_TRANS_STEP_Pos) & DMA_CH_DST_TRANSFER_STEP_DST_TRANS_STEP_Msk) /*!< DST_TRANS_STEP Set Value            */
#define DMA_CH_DST_TRANSFER_STEP_DST_TRANS_STEP_Get(x) (((uint32_t) (x) & DMA_CH_DST_TRANSFER_STEP_DST_TRANS_STEP_Msk) >> DMA_CH_DST_TRANSFER_STEP_DST_TRANS_STEP_Pos) /*!< DST_TRANS_STEP Get Value            */

/* CH_SRC_WRAP_SET bitfield */
#define DMA_CH_SRC_WRAP_SET_SRC_WRAP_SIZE_Pos    (16U)                                                                                 /*!< SRC_WRAP_SIZE Position  16         */ 
#define DMA_CH_SRC_WRAP_SET_SRC_WRAP_SIZE_Msk    (0xffffU << DMA_CH_SRC_WRAP_SET_SRC_WRAP_SIZE_Pos)                                    /*!< SRC_WRAP_SIZE Mask      0xFFFF0000 */
#define DMA_CH_SRC_WRAP_SET_SRC_WRAP_SIZE_Set(x) (((uint32_t) (x) << DMA_CH_SRC_WRAP_SET_SRC_WRAP_SIZE_Pos) & DMA_CH_SRC_WRAP_SET_SRC_WRAP_SIZE_Msk) /*!< SRC_WRAP_SIZE Set Value            */
#define DMA_CH_SRC_WRAP_SET_SRC_WRAP_SIZE_Get(x) (((uint32_t) (x) & DMA_CH_SRC_WRAP_SET_SRC_WRAP_SIZE_Msk) >> DMA_CH_SRC_WRAP_SET_SRC_WRAP_SIZE_Pos) /*!< SRC_WRAP_SIZE Get Value            */

#define DMA_CH_SRC_WRAP_SET_SRC_WRAP_COUNT_Pos    (0U)                                                                                  /*!< SRC_WRAP_COUNT Position  0          */ 
#define DMA_CH_SRC_WRAP_SET_SRC_WRAP_COUNT_Msk    (0xffffU << DMA_CH_SRC_WRAP_SET_SRC_WRAP_COUNT_Pos)                                   /*!< SRC_WRAP_COUNT Mask      0x0000FFFF */
#define DMA_CH_SRC_WRAP_SET_SRC_WRAP_COUNT_Set(x) (((uint32_t) (x) << DMA_CH_SRC_WRAP_SET_SRC_WRAP_COUNT_Pos) & DMA_CH_SRC_WRAP_SET_SRC_WRAP_COUNT_Msk) /*!< SRC_WRAP_COUNT Set Value            */
#define DMA_CH_SRC_WRAP_SET_SRC_WRAP_COUNT_Get(x) (((uint32_t) (x) & DMA_CH_SRC_WRAP_SET_SRC_WRAP_COUNT_Msk) >> DMA_CH_SRC_WRAP_SET_SRC_WRAP_COUNT_Pos) /*!< SRC_WRAP_COUNT Get Value            */

/* CH_DST_WRAP_SET bitfield */
#define DMA_CH_DST_WRAP_SET_DST_WRAP_SIZE_Pos    (16U)                                                                                 /*!< DST_WRAP_SIZE Position  16         */ 
#define DMA_CH_DST_WRAP_SET_DST_WRAP_SIZE_Msk    (0xffffU << DMA_CH_DST_WRAP_SET_DST_WRAP_SIZE_Pos)                                    /*!< DST_WRAP_SIZE Mask      0xFFFF0000 */
#define DMA_CH_DST_WRAP_SET_DST_WRAP_SIZE_Set(x) (((uint32_t) (x) << DMA_CH_DST_WRAP_SET_DST_WRAP_SIZE_Pos) & DMA_CH_DST_WRAP_SET_DST_WRAP_SIZE_Msk) /*!< DST_WRAP_SIZE Set Value            */
#define DMA_CH_DST_WRAP_SET_DST_WRAP_SIZE_Get(x) (((uint32_t) (x) & DMA_CH_DST_WRAP_SET_DST_WRAP_SIZE_Msk) >> DMA_CH_DST_WRAP_SET_DST_WRAP_SIZE_Pos) /*!< DST_WRAP_SIZE Get Value            */

#define DMA_CH_DST_WRAP_SET_DST_WRAP_COUNT_Pos    (0U)                                                                                  /*!< DST_WRAP_COUNT Position  0          */ 
#define DMA_CH_DST_WRAP_SET_DST_WRAP_COUNT_Msk    (0xffffU << DMA_CH_DST_WRAP_SET_DST_WRAP_COUNT_Pos)                                   /*!< DST_WRAP_COUNT Mask      0x0000FFFF */
#define DMA_CH_DST_WRAP_SET_DST_WRAP_COUNT_Set(x) (((uint32_t) (x) << DMA_CH_DST_WRAP_SET_DST_WRAP_COUNT_Pos) & DMA_CH_DST_WRAP_SET_DST_WRAP_COUNT_Msk) /*!< DST_WRAP_COUNT Set Value            */
#define DMA_CH_DST_WRAP_SET_DST_WRAP_COUNT_Get(x) (((uint32_t) (x) & DMA_CH_DST_WRAP_SET_DST_WRAP_COUNT_Msk) >> DMA_CH_DST_WRAP_SET_DST_WRAP_COUNT_Pos) /*!< DST_WRAP_COUNT Get Value            */

/* CH_SRC_WRAP_STEP bitfield */
#define DMA_CH_SRC_WRAP_STEP_SRC_WRAP_STEP_Pos    (0U)                                                                                  /*!< SRC_WRAP_STEP Position  0          */ 
#define DMA_CH_SRC_WRAP_STEP_SRC_WRAP_STEP_Msk    (0xffffffU << DMA_CH_SRC_WRAP_STEP_SRC_WRAP_STEP_Pos)                                 /*!< SRC_WRAP_STEP Mask      0x00FFFFFF */
#define DMA_CH_SRC_WRAP_STEP_SRC_WRAP_STEP_Set(x) (((uint32_t) (x) << DMA_CH_SRC_WRAP_STEP_SRC_WRAP_STEP_Pos) & DMA_CH_SRC_WRAP_STEP_SRC_WRAP_STEP_Msk) /*!< SRC_WRAP_STEP Set Value            */
#define DMA_CH_SRC_WRAP_STEP_SRC_WRAP_STEP_Get(x) (((uint32_t) (x) & DMA_CH_SRC_WRAP_STEP_SRC_WRAP_STEP_Msk) >> DMA_CH_SRC_WRAP_STEP_SRC_WRAP_STEP_Pos) /*!< SRC_WRAP_STEP Get Value            */

/* CH_DST_WRAP_STEP bitfield */
#define DMA_CH_DST_WRAP_STEP_DST_WRAP_STEP_Pos    (0U)                                                                                  /*!< DST_WRAP_STEP Position  0          */ 
#define DMA_CH_DST_WRAP_STEP_DST_WRAP_STEP_Msk    (0xffffffU << DMA_CH_DST_WRAP_STEP_DST_WRAP_STEP_Pos)                                 /*!< DST_WRAP_STEP Mask      0x00FFFFFF */
#define DMA_CH_DST_WRAP_STEP_DST_WRAP_STEP_Set(x) (((uint32_t) (x) << DMA_CH_DST_WRAP_STEP_DST_WRAP_STEP_Pos) & DMA_CH_DST_WRAP_STEP_DST_WRAP_STEP_Msk) /*!< DST_WRAP_STEP Set Value            */
#define DMA_CH_DST_WRAP_STEP_DST_WRAP_STEP_Get(x) (((uint32_t) (x) & DMA_CH_DST_WRAP_STEP_DST_WRAP_STEP_Msk) >> DMA_CH_DST_WRAP_STEP_DST_WRAP_STEP_Pos) /*!< DST_WRAP_STEP Get Value            */

/* CH_SRC_BEG_ADDR_SHADOW bitfield */
#define DMA_CH_SRC_BEG_ADDR_SHADOW_SRC_BEG_ADDR_SHADOW_Pos    (0U)                                                                                  /*!< SRC_BEG_ADDR_SHADOW Position  0          */ 
#define DMA_CH_SRC_BEG_ADDR_SHADOW_SRC_BEG_ADDR_SHADOW_Msk    (0xffffffffU << DMA_CH_SRC_BEG_ADDR_SHADOW_SRC_BEG_ADDR_SHADOW_Pos)                   /*!< SRC_BEG_ADDR_SHADOW Mask      0xFFFFFFFF */
#define DMA_CH_SRC_BEG_ADDR_SHADOW_SRC_BEG_ADDR_SHADOW_Set(x) (((uint32_t) (x) << DMA_CH_SRC_BEG_ADDR_SHADOW_SRC_BEG_ADDR_SHADOW_Pos) & DMA_CH_SRC_BEG_ADDR_SHADOW_SRC_BEG_ADDR_SHADOW_Msk) /*!< SRC_BEG_ADDR_SHADOW Set Value            */
#define DMA_CH_SRC_BEG_ADDR_SHADOW_SRC_BEG_ADDR_SHADOW_Get(x) (((uint32_t) (x) & DMA_CH_SRC_BEG_ADDR_SHADOW_SRC_BEG_ADDR_SHADOW_Msk) >> DMA_CH_SRC_BEG_ADDR_SHADOW_SRC_BEG_ADDR_SHADOW_Pos) /*!< SRC_BEG_ADDR_SHADOW Get Value            */

/* CH_SRC_ADDR_SHADOW bitfield */
#define DMA_CH_SRC_ADDR_SHADOW_SRC_ADDR_SHADOW_Pos    (0U)                                                                                  /*!< SRC_ADDR_SHADOW Position  0          */ 
#define DMA_CH_SRC_ADDR_SHADOW_SRC_ADDR_SHADOW_Msk    (0xffffffffU << DMA_CH_SRC_ADDR_SHADOW_SRC_ADDR_SHADOW_Pos)                           /*!< SRC_ADDR_SHADOW Mask      0xFFFFFFFF */
#define DMA_CH_SRC_ADDR_SHADOW_SRC_ADDR_SHADOW_Set(x) (((uint32_t) (x) << DMA_CH_SRC_ADDR_SHADOW_SRC_ADDR_SHADOW_Pos) & DMA_CH_SRC_ADDR_SHADOW_SRC_ADDR_SHADOW_Msk) /*!< SRC_ADDR_SHADOW Set Value            */
#define DMA_CH_SRC_ADDR_SHADOW_SRC_ADDR_SHADOW_Get(x) (((uint32_t) (x) & DMA_CH_SRC_ADDR_SHADOW_SRC_ADDR_SHADOW_Msk) >> DMA_CH_SRC_ADDR_SHADOW_SRC_ADDR_SHADOW_Pos) /*!< SRC_ADDR_SHADOW Get Value            */

/* CH_SRC_BEG_ADDR_ACTIVE bitfield */
#define DMA_CH_SRC_BEG_ADDR_ACTIVE_SRC_BEG_ADDR_ACTIVE_Pos    (0U)                                                                                  /*!< SRC_BEG_ADDR_ACTIVE Position  0          */ 
#define DMA_CH_SRC_BEG_ADDR_ACTIVE_SRC_BEG_ADDR_ACTIVE_Msk    (0xffffffffU << DMA_CH_SRC_BEG_ADDR_ACTIVE_SRC_BEG_ADDR_ACTIVE_Pos)                   /*!< SRC_BEG_ADDR_ACTIVE Mask      0xFFFFFFFF */
#define DMA_CH_SRC_BEG_ADDR_ACTIVE_SRC_BEG_ADDR_ACTIVE_Set(x) (((uint32_t) (x) << DMA_CH_SRC_BEG_ADDR_ACTIVE_SRC_BEG_ADDR_ACTIVE_Pos) & DMA_CH_SRC_BEG_ADDR_ACTIVE_SRC_BEG_ADDR_ACTIVE_Msk) /*!< SRC_BEG_ADDR_ACTIVE Set Value            */
#define DMA_CH_SRC_BEG_ADDR_ACTIVE_SRC_BEG_ADDR_ACTIVE_Get(x) (((uint32_t) (x) & DMA_CH_SRC_BEG_ADDR_ACTIVE_SRC_BEG_ADDR_ACTIVE_Msk) >> DMA_CH_SRC_BEG_ADDR_ACTIVE_SRC_BEG_ADDR_ACTIVE_Pos) /*!< SRC_BEG_ADDR_ACTIVE Get Value            */

/* CH_SRC_ADDR_ACTIVE bitfield */
#define DMA_CH_SRC_ADDR_ACTIVE_SRC_ADDR_ACTIVE_Pos    (0U)                                                                                  /*!< SRC_ADDR_ACTIVE Position  0          */ 
#define DMA_CH_SRC_ADDR_ACTIVE_SRC_ADDR_ACTIVE_Msk    (0xffffffffU << DMA_CH_SRC_ADDR_ACTIVE_SRC_ADDR_ACTIVE_Pos)                           /*!< SRC_ADDR_ACTIVE Mask      0xFFFFFFFF */
#define DMA_CH_SRC_ADDR_ACTIVE_SRC_ADDR_ACTIVE_Set(x) (((uint32_t) (x) << DMA_CH_SRC_ADDR_ACTIVE_SRC_ADDR_ACTIVE_Pos) & DMA_CH_SRC_ADDR_ACTIVE_SRC_ADDR_ACTIVE_Msk) /*!< SRC_ADDR_ACTIVE Set Value            */
#define DMA_CH_SRC_ADDR_ACTIVE_SRC_ADDR_ACTIVE_Get(x) (((uint32_t) (x) & DMA_CH_SRC_ADDR_ACTIVE_SRC_ADDR_ACTIVE_Msk) >> DMA_CH_SRC_ADDR_ACTIVE_SRC_ADDR_ACTIVE_Pos) /*!< SRC_ADDR_ACTIVE Get Value            */

/* CH_DST_BEG_ADDR_SHADOW bitfield */
#define DMA_CH_DST_BEG_ADDR_SHADOW_DST_BEG_ADDR_SHADOW_Pos    (0U)                                                                                  /*!< DST_BEG_ADDR_SHADOW Position  0          */ 
#define DMA_CH_DST_BEG_ADDR_SHADOW_DST_BEG_ADDR_SHADOW_Msk    (0xffffffffU << DMA_CH_DST_BEG_ADDR_SHADOW_DST_BEG_ADDR_SHADOW_Pos)                   /*!< DST_BEG_ADDR_SHADOW Mask      0xFFFFFFFF */
#define DMA_CH_DST_BEG_ADDR_SHADOW_DST_BEG_ADDR_SHADOW_Set(x) (((uint32_t) (x) << DMA_CH_DST_BEG_ADDR_SHADOW_DST_BEG_ADDR_SHADOW_Pos) & DMA_CH_DST_BEG_ADDR_SHADOW_DST_BEG_ADDR_SHADOW_Msk) /*!< DST_BEG_ADDR_SHADOW Set Value            */
#define DMA_CH_DST_BEG_ADDR_SHADOW_DST_BEG_ADDR_SHADOW_Get(x) (((uint32_t) (x) & DMA_CH_DST_BEG_ADDR_SHADOW_DST_BEG_ADDR_SHADOW_Msk) >> DMA_CH_DST_BEG_ADDR_SHADOW_DST_BEG_ADDR_SHADOW_Pos) /*!< DST_BEG_ADDR_SHADOW Get Value            */

/* CH_DST_ADDR_SHADOW bitfield */
#define DMA_CH_DST_ADDR_SHADOW_DST_ADDR_SHADOW_Pos    (0U)                                                                                  /*!< DST_ADDR_SHADOW Position  0          */ 
#define DMA_CH_DST_ADDR_SHADOW_DST_ADDR_SHADOW_Msk    (0xffffffffU << DMA_CH_DST_ADDR_SHADOW_DST_ADDR_SHADOW_Pos)                           /*!< DST_ADDR_SHADOW Mask      0xFFFFFFFF */
#define DMA_CH_DST_ADDR_SHADOW_DST_ADDR_SHADOW_Set(x) (((uint32_t) (x) << DMA_CH_DST_ADDR_SHADOW_DST_ADDR_SHADOW_Pos) & DMA_CH_DST_ADDR_SHADOW_DST_ADDR_SHADOW_Msk) /*!< DST_ADDR_SHADOW Set Value            */
#define DMA_CH_DST_ADDR_SHADOW_DST_ADDR_SHADOW_Get(x) (((uint32_t) (x) & DMA_CH_DST_ADDR_SHADOW_DST_ADDR_SHADOW_Msk) >> DMA_CH_DST_ADDR_SHADOW_DST_ADDR_SHADOW_Pos) /*!< DST_ADDR_SHADOW Get Value            */

/* CH_DST_BEG_ADDR_ACTIVE bitfield */
#define DMA_CH_DST_BEG_ADDR_ACTIVE_DST_BEG_ADDR_ACTIVE_Pos    (0U)                                                                                  /*!< DST_BEG_ADDR_ACTIVE Position  0          */ 
#define DMA_CH_DST_BEG_ADDR_ACTIVE_DST_BEG_ADDR_ACTIVE_Msk    (0xffffffffU << DMA_CH_DST_BEG_ADDR_ACTIVE_DST_BEG_ADDR_ACTIVE_Pos)                   /*!< DST_BEG_ADDR_ACTIVE Mask      0xFFFFFFFF */
#define DMA_CH_DST_BEG_ADDR_ACTIVE_DST_BEG_ADDR_ACTIVE_Set(x) (((uint32_t) (x) << DMA_CH_DST_BEG_ADDR_ACTIVE_DST_BEG_ADDR_ACTIVE_Pos) & DMA_CH_DST_BEG_ADDR_ACTIVE_DST_BEG_ADDR_ACTIVE_Msk) /*!< DST_BEG_ADDR_ACTIVE Set Value            */
#define DMA_CH_DST_BEG_ADDR_ACTIVE_DST_BEG_ADDR_ACTIVE_Get(x) (((uint32_t) (x) & DMA_CH_DST_BEG_ADDR_ACTIVE_DST_BEG_ADDR_ACTIVE_Msk) >> DMA_CH_DST_BEG_ADDR_ACTIVE_DST_BEG_ADDR_ACTIVE_Pos) /*!< DST_BEG_ADDR_ACTIVE Get Value            */

/* CH_DST_ADDR_ACTIVE bitfield */
#define DMA_CH_DST_ADDR_ACTIVE_DST_ADDR_ACTIVE_Pos    (0U)                                                                                  /*!< DST_ADDR_ACTIVE Position  0          */ 
#define DMA_CH_DST_ADDR_ACTIVE_DST_ADDR_ACTIVE_Msk    (0xffffffffU << DMA_CH_DST_ADDR_ACTIVE_DST_ADDR_ACTIVE_Pos)                           /*!< DST_ADDR_ACTIVE Mask      0xFFFFFFFF */
#define DMA_CH_DST_ADDR_ACTIVE_DST_ADDR_ACTIVE_Set(x) (((uint32_t) (x) << DMA_CH_DST_ADDR_ACTIVE_DST_ADDR_ACTIVE_Pos) & DMA_CH_DST_ADDR_ACTIVE_DST_ADDR_ACTIVE_Msk) /*!< DST_ADDR_ACTIVE Set Value            */
#define DMA_CH_DST_ADDR_ACTIVE_DST_ADDR_ACTIVE_Get(x) (((uint32_t) (x) & DMA_CH_DST_ADDR_ACTIVE_DST_ADDR_ACTIVE_Msk) >> DMA_CH_DST_ADDR_ACTIVE_DST_ADDR_ACTIVE_Pos) /*!< DST_ADDR_ACTIVE Get Value            */

/* CTRL bitfield */
#define DMA_CTRL_PRIORITY_RESET_Pos    (25U)                                                                                 /*!< PRIORITY_RESET Position  25         */ 
#define DMA_CTRL_PRIORITY_RESET_Msk    (0x1U << DMA_CTRL_PRIORITY_RESET_Pos)                                                 /*!< PRIORITY_RESET Mask      0x02000000 */
#define DMA_CTRL_PRIORITY_RESET_Set(x) (((uint32_t) (x) << DMA_CTRL_PRIORITY_RESET_Pos) & DMA_CTRL_PRIORITY_RESET_Msk)       /*!< PRIORITY_RESET Set Value            */
#define DMA_CTRL_PRIORITY_RESET_Get(x) (((uint32_t) (x) & DMA_CTRL_PRIORITY_RESET_Msk) >> DMA_CTRL_PRIORITY_RESET_Pos)       /*!< PRIORITY_RESET Get Value            */

#define DMA_CTRL_HARD_RESET_Pos    (24U)                                                                                 /*!< HARD_RESET Position  24         */ 
#define DMA_CTRL_HARD_RESET_Msk    (0x1U << DMA_CTRL_HARD_RESET_Pos)                                                     /*!< HARD_RESET Mask      0x01000000 */
#define DMA_CTRL_HARD_RESET_Set(x) (((uint32_t) (x) << DMA_CTRL_HARD_RESET_Pos) & DMA_CTRL_HARD_RESET_Msk)               /*!< HARD_RESET Set Value            */
#define DMA_CTRL_HARD_RESET_Get(x) (((uint32_t) (x) & DMA_CTRL_HARD_RESET_Msk) >> DMA_CTRL_HARD_RESET_Pos)               /*!< HARD_RESET Get Value            */

#define DMA_CTRL_FREE_Pos    (16U)                                                                                 /*!< FREE Position  16         */ 
#define DMA_CTRL_FREE_Msk    (0x1U << DMA_CTRL_FREE_Pos)                                                           /*!< FREE Mask      0x00010000 */
#define DMA_CTRL_FREE_Set(x) (((uint32_t) (x) << DMA_CTRL_FREE_Pos) & DMA_CTRL_FREE_Msk)                           /*!< FREE Set Value            */
#define DMA_CTRL_FREE_Get(x) (((uint32_t) (x) & DMA_CTRL_FREE_Msk) >> DMA_CTRL_FREE_Pos)                           /*!< FREE Get Value            */

#define DMA_CTRL_WDONE_SEL_Pos    (1U)                                                                                  /*!< WDONE_SEL Position  1          */ 
#define DMA_CTRL_WDONE_SEL_Msk    (0x1U << DMA_CTRL_WDONE_SEL_Pos)                                                      /*!< WDONE_SEL Mask      0x00000002 */
#define DMA_CTRL_WDONE_SEL_Set(x) (((uint32_t) (x) << DMA_CTRL_WDONE_SEL_Pos) & DMA_CTRL_WDONE_SEL_Msk)                 /*!< WDONE_SEL Set Value            */
#define DMA_CTRL_WDONE_SEL_Get(x) (((uint32_t) (x) & DMA_CTRL_WDONE_SEL_Msk) >> DMA_CTRL_WDONE_SEL_Pos)                 /*!< WDONE_SEL Get Value            */

#define DMA_CTRL_CH1_PRIORITY_Pos    (0U)                                                                                  /*!< CH1_PRIORITY Position  0          */ 
#define DMA_CTRL_CH1_PRIORITY_Msk    (0x1U << DMA_CTRL_CH1_PRIORITY_Pos)                                                   /*!< CH1_PRIORITY Mask      0x00000001 */
#define DMA_CTRL_CH1_PRIORITY_Set(x) (((uint32_t) (x) << DMA_CTRL_CH1_PRIORITY_Pos) & DMA_CTRL_CH1_PRIORITY_Msk)           /*!< CH1_PRIORITY Set Value            */
#define DMA_CTRL_CH1_PRIORITY_Get(x) (((uint32_t) (x) & DMA_CTRL_CH1_PRIORITY_Msk) >> DMA_CTRL_CH1_PRIORITY_Pos)           /*!< CH1_PRIORITY Get Value            */

/* STATUS bitfield */
#define DMA_STATUS_ACTIVE_STS_SHADOW_Pos    (4U)                                                                                  /*!< ACTIVE_STS_SHADOW Position  4          */ 
#define DMA_STATUS_ACTIVE_STS_SHADOW_Msk    (0x7U << DMA_STATUS_ACTIVE_STS_SHADOW_Pos)                                            /*!< ACTIVE_STS_SHADOW Mask      0x00000070 */
#define DMA_STATUS_ACTIVE_STS_SHADOW_Set(x) (((uint32_t) (x) << DMA_STATUS_ACTIVE_STS_SHADOW_Pos) & DMA_STATUS_ACTIVE_STS_SHADOW_Msk) /*!< ACTIVE_STS_SHADOW Set Value            */
#define DMA_STATUS_ACTIVE_STS_SHADOW_Get(x) (((uint32_t) (x) & DMA_STATUS_ACTIVE_STS_SHADOW_Msk) >> DMA_STATUS_ACTIVE_STS_SHADOW_Pos) /*!< ACTIVE_STS_SHADOW Get Value            */

#define DMA_STATUS_ACTIVE_STS_Pos    (0U)                                                                                  /*!< ACTIVE_STS Position  0          */ 
#define DMA_STATUS_ACTIVE_STS_Msk    (0x7U << DMA_STATUS_ACTIVE_STS_Pos)                                                   /*!< ACTIVE_STS Mask      0x00000007 */
#define DMA_STATUS_ACTIVE_STS_Set(x) (((uint32_t) (x) << DMA_STATUS_ACTIVE_STS_Pos) & DMA_STATUS_ACTIVE_STS_Msk)           /*!< ACTIVE_STS Set Value            */
#define DMA_STATUS_ACTIVE_STS_Get(x) (((uint32_t) (x) & DMA_STATUS_ACTIVE_STS_Msk) >> DMA_STATUS_ACTIVE_STS_Pos)           /*!< ACTIVE_STS Get Value            */

/* AXI_AR_OUTSTANDING bitfield */
#define DMA_AXI_AR_OUTSTANDING_CH6_AXI_AR_OUTSTANDING_Pos    (20U)                                                                                 /*!< CH6_AXI_AR_OUTSTANDING Position  20         */ 
#define DMA_AXI_AR_OUTSTANDING_CH6_AXI_AR_OUTSTANDING_Msk    (0xfU << DMA_AXI_AR_OUTSTANDING_CH6_AXI_AR_OUTSTANDING_Pos)                           /*!< CH6_AXI_AR_OUTSTANDING Mask      0x00F00000 */
#define DMA_AXI_AR_OUTSTANDING_CH6_AXI_AR_OUTSTANDING_Set(x) (((uint32_t) (x) << DMA_AXI_AR_OUTSTANDING_CH6_AXI_AR_OUTSTANDING_Pos) & DMA_AXI_AR_OUTSTANDING_CH6_AXI_AR_OUTSTANDING_Msk) /*!< CH6_AXI_AR_OUTSTANDING Set Value            */
#define DMA_AXI_AR_OUTSTANDING_CH6_AXI_AR_OUTSTANDING_Get(x) (((uint32_t) (x) & DMA_AXI_AR_OUTSTANDING_CH6_AXI_AR_OUTSTANDING_Msk) >> DMA_AXI_AR_OUTSTANDING_CH6_AXI_AR_OUTSTANDING_Pos) /*!< CH6_AXI_AR_OUTSTANDING Get Value            */

#define DMA_AXI_AR_OUTSTANDING_CH5_AXI_AR_OUTSTANDING_Pos    (16U)                                                                                 /*!< CH5_AXI_AR_OUTSTANDING Position  16         */ 
#define DMA_AXI_AR_OUTSTANDING_CH5_AXI_AR_OUTSTANDING_Msk    (0xfU << DMA_AXI_AR_OUTSTANDING_CH5_AXI_AR_OUTSTANDING_Pos)                           /*!< CH5_AXI_AR_OUTSTANDING Mask      0x000F0000 */
#define DMA_AXI_AR_OUTSTANDING_CH5_AXI_AR_OUTSTANDING_Set(x) (((uint32_t) (x) << DMA_AXI_AR_OUTSTANDING_CH5_AXI_AR_OUTSTANDING_Pos) & DMA_AXI_AR_OUTSTANDING_CH5_AXI_AR_OUTSTANDING_Msk) /*!< CH5_AXI_AR_OUTSTANDING Set Value            */
#define DMA_AXI_AR_OUTSTANDING_CH5_AXI_AR_OUTSTANDING_Get(x) (((uint32_t) (x) & DMA_AXI_AR_OUTSTANDING_CH5_AXI_AR_OUTSTANDING_Msk) >> DMA_AXI_AR_OUTSTANDING_CH5_AXI_AR_OUTSTANDING_Pos) /*!< CH5_AXI_AR_OUTSTANDING Get Value            */

#define DMA_AXI_AR_OUTSTANDING_CH4_AXI_AR_OUTSTANDING_Pos    (12U)                                                                                 /*!< CH4_AXI_AR_OUTSTANDING Position  12         */ 
#define DMA_AXI_AR_OUTSTANDING_CH4_AXI_AR_OUTSTANDING_Msk    (0xfU << DMA_AXI_AR_OUTSTANDING_CH4_AXI_AR_OUTSTANDING_Pos)                           /*!< CH4_AXI_AR_OUTSTANDING Mask      0x0000F000 */
#define DMA_AXI_AR_OUTSTANDING_CH4_AXI_AR_OUTSTANDING_Set(x) (((uint32_t) (x) << DMA_AXI_AR_OUTSTANDING_CH4_AXI_AR_OUTSTANDING_Pos) & DMA_AXI_AR_OUTSTANDING_CH4_AXI_AR_OUTSTANDING_Msk) /*!< CH4_AXI_AR_OUTSTANDING Set Value            */
#define DMA_AXI_AR_OUTSTANDING_CH4_AXI_AR_OUTSTANDING_Get(x) (((uint32_t) (x) & DMA_AXI_AR_OUTSTANDING_CH4_AXI_AR_OUTSTANDING_Msk) >> DMA_AXI_AR_OUTSTANDING_CH4_AXI_AR_OUTSTANDING_Pos) /*!< CH4_AXI_AR_OUTSTANDING Get Value            */

#define DMA_AXI_AR_OUTSTANDING_CH3_AXI_AR_OUTSTANDING_Pos    (8U)                                                                                  /*!< CH3_AXI_AR_OUTSTANDING Position  8          */ 
#define DMA_AXI_AR_OUTSTANDING_CH3_AXI_AR_OUTSTANDING_Msk    (0xfU << DMA_AXI_AR_OUTSTANDING_CH3_AXI_AR_OUTSTANDING_Pos)                           /*!< CH3_AXI_AR_OUTSTANDING Mask      0x00000F00 */
#define DMA_AXI_AR_OUTSTANDING_CH3_AXI_AR_OUTSTANDING_Set(x) (((uint32_t) (x) << DMA_AXI_AR_OUTSTANDING_CH3_AXI_AR_OUTSTANDING_Pos) & DMA_AXI_AR_OUTSTANDING_CH3_AXI_AR_OUTSTANDING_Msk) /*!< CH3_AXI_AR_OUTSTANDING Set Value            */
#define DMA_AXI_AR_OUTSTANDING_CH3_AXI_AR_OUTSTANDING_Get(x) (((uint32_t) (x) & DMA_AXI_AR_OUTSTANDING_CH3_AXI_AR_OUTSTANDING_Msk) >> DMA_AXI_AR_OUTSTANDING_CH3_AXI_AR_OUTSTANDING_Pos) /*!< CH3_AXI_AR_OUTSTANDING Get Value            */

#define DMA_AXI_AR_OUTSTANDING_CH2_AXI_AR_OUTSTANDING_Pos    (4U)                                                                                  /*!< CH2_AXI_AR_OUTSTANDING Position  4          */ 
#define DMA_AXI_AR_OUTSTANDING_CH2_AXI_AR_OUTSTANDING_Msk    (0xfU << DMA_AXI_AR_OUTSTANDING_CH2_AXI_AR_OUTSTANDING_Pos)                           /*!< CH2_AXI_AR_OUTSTANDING Mask      0x000000F0 */
#define DMA_AXI_AR_OUTSTANDING_CH2_AXI_AR_OUTSTANDING_Set(x) (((uint32_t) (x) << DMA_AXI_AR_OUTSTANDING_CH2_AXI_AR_OUTSTANDING_Pos) & DMA_AXI_AR_OUTSTANDING_CH2_AXI_AR_OUTSTANDING_Msk) /*!< CH2_AXI_AR_OUTSTANDING Set Value            */
#define DMA_AXI_AR_OUTSTANDING_CH2_AXI_AR_OUTSTANDING_Get(x) (((uint32_t) (x) & DMA_AXI_AR_OUTSTANDING_CH2_AXI_AR_OUTSTANDING_Msk) >> DMA_AXI_AR_OUTSTANDING_CH2_AXI_AR_OUTSTANDING_Pos) /*!< CH2_AXI_AR_OUTSTANDING Get Value            */

#define DMA_AXI_AR_OUTSTANDING_CH1_AXI_AR_OUTSTANDING_Pos    (0U)                                                                                  /*!< CH1_AXI_AR_OUTSTANDING Position  0          */ 
#define DMA_AXI_AR_OUTSTANDING_CH1_AXI_AR_OUTSTANDING_Msk    (0xfU << DMA_AXI_AR_OUTSTANDING_CH1_AXI_AR_OUTSTANDING_Pos)                           /*!< CH1_AXI_AR_OUTSTANDING Mask      0x0000000F */
#define DMA_AXI_AR_OUTSTANDING_CH1_AXI_AR_OUTSTANDING_Set(x) (((uint32_t) (x) << DMA_AXI_AR_OUTSTANDING_CH1_AXI_AR_OUTSTANDING_Pos) & DMA_AXI_AR_OUTSTANDING_CH1_AXI_AR_OUTSTANDING_Msk) /*!< CH1_AXI_AR_OUTSTANDING Set Value            */
#define DMA_AXI_AR_OUTSTANDING_CH1_AXI_AR_OUTSTANDING_Get(x) (((uint32_t) (x) & DMA_AXI_AR_OUTSTANDING_CH1_AXI_AR_OUTSTANDING_Msk) >> DMA_AXI_AR_OUTSTANDING_CH1_AXI_AR_OUTSTANDING_Pos) /*!< CH1_AXI_AR_OUTSTANDING Get Value            */

/* DFIFO_WL1 bitfield */
#define DMA_DFIFO_WL1_D4_WATER_LEVEL_Pos    (24U)                                                                                 /*!< D4_WATER_LEVEL Position  24         */ 
#define DMA_DFIFO_WL1_D4_WATER_LEVEL_Msk    (0x7fU << DMA_DFIFO_WL1_D4_WATER_LEVEL_Pos)                                           /*!< D4_WATER_LEVEL Mask      0x7F000000 */
#define DMA_DFIFO_WL1_D4_WATER_LEVEL_Set(x) (((uint32_t) (x) << DMA_DFIFO_WL1_D4_WATER_LEVEL_Pos) & DMA_DFIFO_WL1_D4_WATER_LEVEL_Msk) /*!< D4_WATER_LEVEL Set Value            */
#define DMA_DFIFO_WL1_D4_WATER_LEVEL_Get(x) (((uint32_t) (x) & DMA_DFIFO_WL1_D4_WATER_LEVEL_Msk) >> DMA_DFIFO_WL1_D4_WATER_LEVEL_Pos) /*!< D4_WATER_LEVEL Get Value            */

#define DMA_DFIFO_WL1_D3_WATER_LEVEL_Pos    (16U)                                                                                 /*!< D3_WATER_LEVEL Position  16         */ 
#define DMA_DFIFO_WL1_D3_WATER_LEVEL_Msk    (0x7fU << DMA_DFIFO_WL1_D3_WATER_LEVEL_Pos)                                           /*!< D3_WATER_LEVEL Mask      0x007F0000 */
#define DMA_DFIFO_WL1_D3_WATER_LEVEL_Set(x) (((uint32_t) (x) << DMA_DFIFO_WL1_D3_WATER_LEVEL_Pos) & DMA_DFIFO_WL1_D3_WATER_LEVEL_Msk) /*!< D3_WATER_LEVEL Set Value            */
#define DMA_DFIFO_WL1_D3_WATER_LEVEL_Get(x) (((uint32_t) (x) & DMA_DFIFO_WL1_D3_WATER_LEVEL_Msk) >> DMA_DFIFO_WL1_D3_WATER_LEVEL_Pos) /*!< D3_WATER_LEVEL Get Value            */

#define DMA_DFIFO_WL1_D2_WATER_LEVEL_Pos    (8U)                                                                                  /*!< D2_WATER_LEVEL Position  8          */ 
#define DMA_DFIFO_WL1_D2_WATER_LEVEL_Msk    (0x7fU << DMA_DFIFO_WL1_D2_WATER_LEVEL_Pos)                                           /*!< D2_WATER_LEVEL Mask      0x00007F00 */
#define DMA_DFIFO_WL1_D2_WATER_LEVEL_Set(x) (((uint32_t) (x) << DMA_DFIFO_WL1_D2_WATER_LEVEL_Pos) & DMA_DFIFO_WL1_D2_WATER_LEVEL_Msk) /*!< D2_WATER_LEVEL Set Value            */
#define DMA_DFIFO_WL1_D2_WATER_LEVEL_Get(x) (((uint32_t) (x) & DMA_DFIFO_WL1_D2_WATER_LEVEL_Msk) >> DMA_DFIFO_WL1_D2_WATER_LEVEL_Pos) /*!< D2_WATER_LEVEL Get Value            */

#define DMA_DFIFO_WL1_D1_WATER_LEVEL_Pos    (0U)                                                                                  /*!< D1_WATER_LEVEL Position  0          */ 
#define DMA_DFIFO_WL1_D1_WATER_LEVEL_Msk    (0x7fU << DMA_DFIFO_WL1_D1_WATER_LEVEL_Pos)                                           /*!< D1_WATER_LEVEL Mask      0x0000007F */
#define DMA_DFIFO_WL1_D1_WATER_LEVEL_Set(x) (((uint32_t) (x) << DMA_DFIFO_WL1_D1_WATER_LEVEL_Pos) & DMA_DFIFO_WL1_D1_WATER_LEVEL_Msk) /*!< D1_WATER_LEVEL Set Value            */
#define DMA_DFIFO_WL1_D1_WATER_LEVEL_Get(x) (((uint32_t) (x) & DMA_DFIFO_WL1_D1_WATER_LEVEL_Msk) >> DMA_DFIFO_WL1_D1_WATER_LEVEL_Pos) /*!< D1_WATER_LEVEL Get Value            */

/* DFIFO_WL2 bitfield */
#define DMA_DFIFO_WL2_D6_WATER_LEVEL_Pos    (8U)                                                                                  /*!< D6_WATER_LEVEL Position  8          */ 
#define DMA_DFIFO_WL2_D6_WATER_LEVEL_Msk    (0x7fU << DMA_DFIFO_WL2_D6_WATER_LEVEL_Pos)                                           /*!< D6_WATER_LEVEL Mask      0x00007F00 */
#define DMA_DFIFO_WL2_D6_WATER_LEVEL_Set(x) (((uint32_t) (x) << DMA_DFIFO_WL2_D6_WATER_LEVEL_Pos) & DMA_DFIFO_WL2_D6_WATER_LEVEL_Msk) /*!< D6_WATER_LEVEL Set Value            */
#define DMA_DFIFO_WL2_D6_WATER_LEVEL_Get(x) (((uint32_t) (x) & DMA_DFIFO_WL2_D6_WATER_LEVEL_Msk) >> DMA_DFIFO_WL2_D6_WATER_LEVEL_Pos) /*!< D6_WATER_LEVEL Get Value            */

#define DMA_DFIFO_WL2_D5_WATER_LEVEL_Pos    (0U)                                                                                  /*!< D5_WATER_LEVEL Position  0          */ 
#define DMA_DFIFO_WL2_D5_WATER_LEVEL_Msk    (0x7fU << DMA_DFIFO_WL2_D5_WATER_LEVEL_Pos)                                           /*!< D5_WATER_LEVEL Mask      0x0000007F */
#define DMA_DFIFO_WL2_D5_WATER_LEVEL_Set(x) (((uint32_t) (x) << DMA_DFIFO_WL2_D5_WATER_LEVEL_Pos) & DMA_DFIFO_WL2_D5_WATER_LEVEL_Msk) /*!< D5_WATER_LEVEL Set Value            */
#define DMA_DFIFO_WL2_D5_WATER_LEVEL_Get(x) (((uint32_t) (x) & DMA_DFIFO_WL2_D5_WATER_LEVEL_Msk) >> DMA_DFIFO_WL2_D5_WATER_LEVEL_Pos) /*!< D5_WATER_LEVEL Get Value            */

/* CFIFO_WL bitfield */
#define DMA_CFIFO_WL_C6_WATER_LEVEL_Pos    (20U)                                                                                 /*!< C6_WATER_LEVEL Position  20         */ 
#define DMA_CFIFO_WL_C6_WATER_LEVEL_Msk    (0x7U << DMA_CFIFO_WL_C6_WATER_LEVEL_Pos)                                             /*!< C6_WATER_LEVEL Mask      0x00700000 */
#define DMA_CFIFO_WL_C6_WATER_LEVEL_Set(x) (((uint32_t) (x) << DMA_CFIFO_WL_C6_WATER_LEVEL_Pos) & DMA_CFIFO_WL_C6_WATER_LEVEL_Msk) /*!< C6_WATER_LEVEL Set Value            */
#define DMA_CFIFO_WL_C6_WATER_LEVEL_Get(x) (((uint32_t) (x) & DMA_CFIFO_WL_C6_WATER_LEVEL_Msk) >> DMA_CFIFO_WL_C6_WATER_LEVEL_Pos) /*!< C6_WATER_LEVEL Get Value            */

#define DMA_CFIFO_WL_C5_WATER_LEVEL_Pos    (16U)                                                                                 /*!< C5_WATER_LEVEL Position  16         */ 
#define DMA_CFIFO_WL_C5_WATER_LEVEL_Msk    (0x7U << DMA_CFIFO_WL_C5_WATER_LEVEL_Pos)                                             /*!< C5_WATER_LEVEL Mask      0x00070000 */
#define DMA_CFIFO_WL_C5_WATER_LEVEL_Set(x) (((uint32_t) (x) << DMA_CFIFO_WL_C5_WATER_LEVEL_Pos) & DMA_CFIFO_WL_C5_WATER_LEVEL_Msk) /*!< C5_WATER_LEVEL Set Value            */
#define DMA_CFIFO_WL_C5_WATER_LEVEL_Get(x) (((uint32_t) (x) & DMA_CFIFO_WL_C5_WATER_LEVEL_Msk) >> DMA_CFIFO_WL_C5_WATER_LEVEL_Pos) /*!< C5_WATER_LEVEL Get Value            */

#define DMA_CFIFO_WL_C4_WATER_LEVEL_Pos    (12U)                                                                                 /*!< C4_WATER_LEVEL Position  12         */ 
#define DMA_CFIFO_WL_C4_WATER_LEVEL_Msk    (0x7U << DMA_CFIFO_WL_C4_WATER_LEVEL_Pos)                                             /*!< C4_WATER_LEVEL Mask      0x00007000 */
#define DMA_CFIFO_WL_C4_WATER_LEVEL_Set(x) (((uint32_t) (x) << DMA_CFIFO_WL_C4_WATER_LEVEL_Pos) & DMA_CFIFO_WL_C4_WATER_LEVEL_Msk) /*!< C4_WATER_LEVEL Set Value            */
#define DMA_CFIFO_WL_C4_WATER_LEVEL_Get(x) (((uint32_t) (x) & DMA_CFIFO_WL_C4_WATER_LEVEL_Msk) >> DMA_CFIFO_WL_C4_WATER_LEVEL_Pos) /*!< C4_WATER_LEVEL Get Value            */

#define DMA_CFIFO_WL_C3_WATER_LEVEL_Pos    (8U)                                                                                  /*!< C3_WATER_LEVEL Position  8          */ 
#define DMA_CFIFO_WL_C3_WATER_LEVEL_Msk    (0x7U << DMA_CFIFO_WL_C3_WATER_LEVEL_Pos)                                             /*!< C3_WATER_LEVEL Mask      0x00000700 */
#define DMA_CFIFO_WL_C3_WATER_LEVEL_Set(x) (((uint32_t) (x) << DMA_CFIFO_WL_C3_WATER_LEVEL_Pos) & DMA_CFIFO_WL_C3_WATER_LEVEL_Msk) /*!< C3_WATER_LEVEL Set Value            */
#define DMA_CFIFO_WL_C3_WATER_LEVEL_Get(x) (((uint32_t) (x) & DMA_CFIFO_WL_C3_WATER_LEVEL_Msk) >> DMA_CFIFO_WL_C3_WATER_LEVEL_Pos) /*!< C3_WATER_LEVEL Get Value            */

#define DMA_CFIFO_WL_C2_WATER_LEVEL_Pos    (4U)                                                                                  /*!< C2_WATER_LEVEL Position  4          */ 
#define DMA_CFIFO_WL_C2_WATER_LEVEL_Msk    (0x7U << DMA_CFIFO_WL_C2_WATER_LEVEL_Pos)                                             /*!< C2_WATER_LEVEL Mask      0x00000070 */
#define DMA_CFIFO_WL_C2_WATER_LEVEL_Set(x) (((uint32_t) (x) << DMA_CFIFO_WL_C2_WATER_LEVEL_Pos) & DMA_CFIFO_WL_C2_WATER_LEVEL_Msk) /*!< C2_WATER_LEVEL Set Value            */
#define DMA_CFIFO_WL_C2_WATER_LEVEL_Get(x) (((uint32_t) (x) & DMA_CFIFO_WL_C2_WATER_LEVEL_Msk) >> DMA_CFIFO_WL_C2_WATER_LEVEL_Pos) /*!< C2_WATER_LEVEL Get Value            */

#define DMA_CFIFO_WL_C1_WATER_LEVEL_Pos    (0U)                                                                                  /*!< C1_WATER_LEVEL Position  0          */ 
#define DMA_CFIFO_WL_C1_WATER_LEVEL_Msk    (0x7U << DMA_CFIFO_WL_C1_WATER_LEVEL_Pos)                                             /*!< C1_WATER_LEVEL Mask      0x00000007 */
#define DMA_CFIFO_WL_C1_WATER_LEVEL_Set(x) (((uint32_t) (x) << DMA_CFIFO_WL_C1_WATER_LEVEL_Pos) & DMA_CFIFO_WL_C1_WATER_LEVEL_Msk) /*!< C1_WATER_LEVEL Set Value            */
#define DMA_CFIFO_WL_C1_WATER_LEVEL_Get(x) (((uint32_t) (x) & DMA_CFIFO_WL_C1_WATER_LEVEL_Msk) >> DMA_CFIFO_WL_C1_WATER_LEVEL_Pos) /*!< C1_WATER_LEVEL Get Value            */

/*!
 * @}
 */

/*!
 * @}
 */ /* end of HS32F7D377_DMA_REGISTER */

#endif /* HS32F7D377_DMA_H */
