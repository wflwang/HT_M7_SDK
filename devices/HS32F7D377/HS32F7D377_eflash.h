/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


/*!
 * \file   HS32F7D377_eflash.h
 * \brief  HS32F7D377 EFLASH register file
 * \version V1.0_20230804
 */

#ifndef HS32F7D377_EFLASH_H
#define HS32F7D377_EFLASH_H

/*!
 * \addtogroup   HS32F7D377_EFLASH_REGISTER HS32F7D377 EFLASH Register
 * \ingroup HS32F7D377_REGISTER
 *
 * \brief  EFLASH register layout, bitfield and address definitions
 *
 * @{
 */

/*!
 * \name EFLASH Register Layout
 *
 *
 * @{
 */

/*! \brief EFLASH register layout */
typedef struct {
    union
    {
        __IOM uint32_t POR_CNT;  /*!< 0x00000000 */ 
    
        struct
        {
            __IOM uint32_t TRHR                      : 16;     /*!< [15:0] : tRHR, porb high to any read/write,5us. */
            __IOM uint32_t TRT                       : 8 ;     /*!< [23:16] : tRT, power-up to end of porb, 500ns. */
                  uint32_t RSV_0                     : 8 ;     /*!< [31:24] : reserved. */
        } POR_CNTb;
    };

    union
    {
        __IOM uint32_t DPD_CNT;  /*!< 0x00000004 */ 
    
        struct
        {
                  uint32_t RSV_0                     : 8 ;     /*!< [7:0] : reserved. */
            __IOM uint32_t TDPDSR                    : 8 ;     /*!< [15:8] : tDPDSR, 100ns. */
            __IOM uint32_t TDPDH                     : 16;     /*!< [31:16] : tDPDH, 5us. */
        } DPD_CNTb;
    };

    union
    {
        __IOM uint32_t LVCTL_CNT;  /*!< 0x00000008 */ 
    
        struct
        {
            __IOM uint32_t TACC_LVCTL                : 8 ;     /*!< [7:0] : tACC_LVCTL,50ns. */
            __IOM uint32_t TCRC_LVCTL                : 1 ;     /*!< [8:8] : tCRC_LVCTL,8ns,0:one cycle,1:two cycle. */
                  uint32_t RSV_0                     : 23;     /*!< [31:9] : reserved. */
        } LVCTL_CNTb;
    };

    union
    {
        __IOM uint32_t PROG_CNT1;  /*!< 0x0000000c */ 
    
        struct
        {
            __IOM uint32_t TPGS                      : 13;     /*!< [12:0] : tPGS,8us. */
                  uint32_t RSV_1                     : 3 ;     /*!< [15:13] : reserved. */
            __IOM uint32_t TPROG                     : 13;     /*!< [28:16] : tPROG,8~10us. */
                  uint32_t RSV_0                     : 3 ;     /*!< [31:29] : reserved. */
        } PROG_CNT1b;
    };

    union
    {
        __IOM uint32_t PROG_CNT2;  /*!< 0x00000010 */ 
    
        struct
        {
            __IOM uint32_t TPGH                      : 3 ;     /*!< [2:0] : tPGH,15ns. */
                  uint32_t RSV_2                     : 13;     /*!< [15:3] : reserved. */
            __IOM uint32_t TADH                      : 3 ;     /*!< [18:16] : tADH,15ns. */
                  uint32_t RSV_1                     : 1 ;     /*!< [19:19] : reserved. */
            __IOM uint32_t TADS                      : 3 ;     /*!< [22:20] : tADS,15ns. */
                  uint32_t RSV_0                     : 9 ;     /*!< [31:23] : reserved. */
        } PROG_CNT2b;
    };

    union
    {
        __IOM uint32_t PROG_CNT3;  /*!< 0x00000014 */ 
    
        struct
        {
            __IOM uint32_t TNVS                      : 11;     /*!< [10:0] : tNVS, 4us. */
                  uint32_t RSV_0                     : 21;     /*!< [31:11] : reserved. */
        } PROG_CNT3b;
    };

    union
    {
        __IOM uint32_t PROG_CNT4;  /*!< 0x00000018 */ 
    
        struct
        {
            __IOM uint32_t TRW                       : 8 ;     /*!< [7:0] : tRW, 100ns. */
            __IOM uint32_t TACC                      : 8 ;     /*!< [15:8] : tACC, 25ns. */
            __IOM uint32_t TWS                       : 2 ;     /*!< [17:16] : tWS/H, 5ns. */
                  uint32_t RSV_0                     : 14;     /*!< [31:18] : reserved. */
        } PROG_CNT4b;
    };

    union
    {
        __IOM uint32_t RCV_CNT1;  /*!< 0x0000001c */ 
    
        struct
        {
            __IOM uint32_t TRCV_SECER                : 16;     /*!< [15:0] : tRCV_SECER, 50us. */
            __IOM uint32_t TRCV_PROG                 : 16;     /*!< [31:16] : tRCV_PROG, 5us. */
        } RCV_CNT1b;
    };

    union
    {
        __IOM uint32_t RCV_CNT2;  /*!< 0x00000020 */ 
    
        struct
        {
            __IOM uint32_t TRCV_CHIPER               : 32;     /*!< [31:0] : tRCV_CHIPER, 200us. */
        } RCV_CNT2b;
    };

    union
    {
        __IOM uint32_t ERASE_CNT1;  /*!< 0x00000024 */ 
    
        struct
        {
            __IOM uint32_t TSEC_ERASE                : 32;     /*!< [31:0] : tSEC_ERASE, 8~10ms, for sector erase. */
        } ERASE_CNT1b;
    };

    union
    {
        __IOM uint32_t ERASE_CNT2;  /*!< 0x00000028 */ 
    
        struct
        {
            __IOM uint32_t TCHIP_ERASE               : 32;     /*!< [31:0] : tCHIP_ERASE, 8~10ms, for chip erase&single sector erase. */
        } ERASE_CNT2b;
    };

    union
    {
        __IOM uint32_t NVR_CFG;  /*!< 0x0000002c */ 
    
        struct
        {
            __IOM uint32_t TMS                       : 16;     /*!< [15:0] : tMS,5us. */
            __IOM uint32_t TACC_NVR                  : 16;     /*!< [31:16] : tACC_NVR,200ns. */
        } NVR_CFGb;
    };

    union
    {
        __IOM uint32_t SET_CFG1;  /*!< 0x00000030 */ 
    
        struct
        {
            __IOM uint32_t TCFL                      : 16;     /*!< [15:0] : tCFL,5us. */
            __IOM uint32_t TCFH                      : 8 ;     /*!< [23:16] : tCFH,30ns. */
                  uint32_t RSV_0                     : 8 ;     /*!< [31:24] : reserved. */
        } SET_CFG1b;
    };

    union
    {
        __IOM uint32_t SET_CFG2;  /*!< 0x00000034 */ 
    
        struct
        {
            __IOM uint32_t TCONFEN                   : 3 ;     /*!< [2:0] : tCONFEN, 15ns. */
                  uint32_t RSV_0                     : 29;     /*!< [31:3] : reserved. */
        } SET_CFG2b;
    };

    union
    {
        __IOM uint32_t WR_DATA1;  /*!< 0x00000038 */ 
    
        struct
        {
            __IOM uint32_t WR_DATA_H                 : 32;     /*!< [31:0] : wr_data[63:32]. */
        } WR_DATA1b;
    };

    union
    {
        __IOM uint32_t WR_DATA2;  /*!< 0x0000003c */ 
    
        struct
        {
            __IOM uint32_t WR_DATA_L                 : 32;     /*!< [31:0] : wr_data[31:0]. */
        } WR_DATA2b;
    };

    union
    {
        __IOM uint32_t WR_ADDR;  /*!< 0x00000040 */ 
    
        struct
        {
            __IOM uint32_t OP_ADDR                   : 17;     /*!< [16:0] : read/write/erase_addr. */
                  uint32_t RSV_0                     : 15;     /*!< [31:17] : reserved. */
        } WR_ADDRb;
    };

    union
    {
        __IM uint32_t READ_OUTPUT_H;  /*!< 0x00000044 */ 
    
        struct
        {
            __IM  uint32_t RD_DATA_H                 : 32;     /*!< [31:0] : read data[63:32]. */
        } READ_OUTPUT_Hb;
    };

    union
    {
        __IM uint32_t READ_OUTPUT_L;  /*!< 0x00000048 */ 
    
        struct
        {
            __IM  uint32_t RD_DATA_L                 : 32;     /*!< [31:0] : read data[31:0]. */
        } READ_OUTPUT_Lb;
    };

    union
    {
        __IOM uint32_t TMEN;  /*!< 0x0000004c */ 
    
        struct
        {
            __IOM uint32_t TMEN_CFG                  : 1 ;     /*!< [0:0] : TMEN=1 to enable test modes. */
                  uint32_t RSV_0                     : 31;     /*!< [31:1] : reserved. */
        } TMENb;
    };

    union
    {
        __IOM uint32_t AXI_CFG;  /*!< 0x00000050 */ 
    
        struct
        {
            __IOM uint32_t AXI_PROG_EN               : 1 ;     /*!< [0:0] : axi write(programe) enable. */
                  uint32_t RSV_0                     : 31;     /*!< [31:1] : reserved. */
        } AXI_CFGb;
    };

    union
    {
        __IOM uint32_t FLASH_AXI_FIFO;  /*!< 0x00000054 */ 
    
        struct
        {
            __IM  uint32_t CFIFO_WL                  : 3 ;     /*!< [2:0] : cmd fifo water level. */
                  uint32_t RSV_2                     : 1 ;     /*!< [3:3] : reserved. */
            __IM  uint32_t DFIFO_WL                  : 3 ;     /*!< [6:4] : write fifo water level. */
                  uint32_t RSV_1                     : 1 ;     /*!< [7:7] : reserved. */
            __IOM uint32_t CFIFO_CLR                 : 1 ;     /*!< [8:8] : write 1 to clr cmd buffer. */
            __IOM uint32_t DFIFO_CLR                 : 1 ;     /*!< [9:9] : write 1 to clr write data buffer. */
                  uint32_t RSV_0                     : 22;     /*!< [31:10] : reserved. */
        } FLASH_AXI_FIFOb;
    };

    union
    {
        __IOM uint32_t CFG;  /*!< 0x00000058 */ 
    
        struct
        {
            __IOM uint32_t RECALL                    : 1 ;     /*!< [0:0] : Recall Read is a special slow read mode to obtain the  configuration bits from the NVR and NVR_CFG  sectors with a wider VREF variation before VREF can  be accurately configured. */
            __IOM uint32_t NVR_CFG                   : 1 ;     /*!< [1:1] : NVR_CFG read. */
            __IOM uint32_t NVR                       : 1 ;     /*!< [2:2] : NVR read. */
            __IOM uint32_t AUTO_SETCFG               : 1 ;     /*!< [3:3] : 1: auto set cofig after power on reset. */
            __IOM uint32_t DPD_CFG                   : 1 ;     /*!< [4:4] : dpd value. */
            __IOM uint32_t LCK_CFG                   : 1 ;     /*!< [5:5] : lck_cfg value. */
            __IOM uint32_t AXI_CMD_PRIORITY          : 1 ;     /*!< [6:6] : 0: ahb cmd excute after current axi r/w done  1: ahb cmd excute when no axi r/w. */
            __IOM uint32_t PRE_SAMPLE_EN             : 1 ;     /*!< [7:7] : 0:eflash rdata sampled at laset cycle  1:eflash rdata sampled at second-to-laset cycle. */
                  uint32_t RSV_1                     : 2 ;     /*!< [9:8] : reserved. */
            __IOM uint32_t LVCTL_CFG                 : 1 ;     /*!< [10:10] : LVCTL cfg. */
                  uint32_t RSV_0                     : 21;     /*!< [31:11] : reserved. */
        } CFGb;
    };

    union
    {
        __IOM uint32_t CTRL;  /*!< 0x0000005c */ 
    
        struct
        {
            __IOM uint32_t CMD_ENABLE                : 1 ;     /*!< [0:0] : write/erase/dpd, hw autoclr after done. */
                  uint32_t RSV_1                     : 3 ;     /*!< [3:1] : reserved. */
            __IOM uint32_t MODE_SEL                  : 4 ;     /*!< [7:4] : 4'h0:none, 4'h1:sec erase, 4'h2:chip erase, 4'h3:dpd,  4'h4:read, 4'h5:write,     4'h6:set cfg,  4'd7: sw reset eflash ip,  4'd8:vread mode  hw autoclr after done. */
                  uint32_t RSV_0                     : 24;     /*!< [31:8] : reserved. */
        } CTRLb;
    };

    union
    {
        __IOM uint32_t KEY_VALUE;  /*!< 0x00000060 */ 
    
        struct
        {
            __IOM uint32_t KEY_VALUE                 : 32;     /*!< [31:0] : 0x5432c7d9: write WR_DATA to flash,  0x5a5a00fc: erase sector,  0x5a5ade00: erase chip. */
        } KEY_VALUEb;
    };

    union
    {
        __IOM uint32_t RR0_CFG;  /*!< 0x00000064 */ 
    
        struct
        {
            __IOM uint32_t RR0_ADDR                  : 17;     /*!< [16:0] : Redundancy Sector0 replace addr. */
                  uint32_t RSV_0                     : 14;     /*!< [30:17] : reserved. */
            __IOM uint32_t RR0_EN                    : 1 ;     /*!< [31:31] : set 1: Redundancy Sector0 replace enable,  erase Redundancy Sector0 when sector erase,  erase all Redundancy Sectors when chip erase. */
        } RR0_CFGb;
    };

    union
    {
        __IOM uint32_t RR1_CFG;  /*!< 0x00000068 */ 
    
        struct
        {
            __IOM uint32_t RR1_ADDR                  : 17;     /*!< [16:0] : Redundancy Sector1 replace addr. */
                  uint32_t RSV_0                     : 14;     /*!< [30:17] : reserved. */
            __IOM uint32_t RR1_EN                    : 1 ;     /*!< [31:31] : set 1: Redundancy Sector1 replace enable,  erase Redundancy Sector1 when sector erase,  erase all Redundancy Sectors when chip erase. */
        } RR1_CFGb;
    };

    union
    {
        __IOM uint32_t PROTECT_START;  /*!< 0x0000006c */ 
    
        struct
        {
            __IOM uint32_t LOCK_BEG_ADDR             : 17;     /*!< [16:0] : protect begin address. */
                  uint32_t RSV_0                     : 15;     /*!< [31:17] : reserved. */
        } PROTECT_STARTb;
    };

    union
    {
        __IOM uint32_t PROTECT_END;  /*!< 0x00000070 */ 
    
        struct
        {
            __IOM uint32_t LOCK_END_ADDR             : 17;     /*!< [16:0] : protect end address. */
                  uint32_t RSV_0                     : 15;     /*!< [31:17] : reserved. */
        } PROTECT_ENDb;
    };

    union
    {
        __IOM uint32_t FLASH_INTR_EN;  /*!< 0x00000074 */ 
    
        struct
        {
                  uint32_t RSV_1                     : 2 ;     /*!< [1:0] : reserved. */
            __IOM uint32_t F_DONE_IE                 : 1 ;     /*!< [2:2] : write 1 enable flash done int. */
            __IOM uint32_t AXI_WERR_IE               : 1 ;     /*!< [3:3] : write 1 enable axi write err int. */
            __IOM uint32_t AXI_W_LOCK_AREA_IE        : 1 ;     /*!< [4:4] : write 1 enable axi_w_lock_area int. */
            __IOM uint32_t AHB_W_LOCK_AREA_IE        : 1 ;     /*!< [5:5] : write 1 enable ahb_w_lock_area int. */
                  uint32_t RSV_0                     : 26;     /*!< [31:6] : reserved. */
        } FLASH_INTR_ENb;
    };

    union
    {
        __IM uint32_t FLASH_INTR_ST;  /*!< 0x00000078 */ 
    
        struct
        {
                  uint32_t RSV_1                     : 2 ;     /*!< [1:0] : reserved. */
            __IM  uint32_t F_DONE                    : 1 ;     /*!< [2:2] : flash current oprate done. */
            __IM  uint32_t AXI_WERR                  : 1 ;     /*!< [3:3] : axi_prog_en set 0, axi write happend. */
            __IM  uint32_t AXI_W_LOCK_AREA           : 1 ;     /*!< [4:4] : if lock area enable, axi write lock area will set this bit. */
            __IM  uint32_t AHB_W_LOCK_AREA           : 1 ;     /*!< [5:5] : if lock area enable, ahb write lock area will set this bit. */
            __IM  uint32_t VREAD_OK                  : 1 ;     /*!< [6:6] : if verfy pass after erase, set this bit. */
                  uint32_t RSV_0                     : 25;     /*!< [31:7] : reserved. */
        } FLASH_INTR_STb;
    };

    union
    {
        __IOM uint32_t FLASH_INTR_ST_CLR;  /*!< 0x0000007c */ 
    
        struct
        {
                  uint32_t RSV_1                     : 2 ;     /*!< [1:0] : reserved. */
            __IOM uint32_t F_DONE_CLR                : 1 ;     /*!< [2:2] : clr flash_done. */
            __IOM uint32_t AXI_WERR_CLR              : 1 ;     /*!< [3:3] : clr axi_werr flag. */
            __IOM uint32_t AXI_W_LOCK_AREA_CLR       : 1 ;     /*!< [4:4] : clr axi_w_lock_area flag. */
            __IOM uint32_t AHB_W_LOCK_AREA_CLR       : 1 ;     /*!< [5:5] : clr ahb_w_lock_area flag. */
            __IOM uint32_t VREAD_OK_CLR              : 1 ;     /*!< [6:6] : clr vread_ok. */
                  uint32_t RSV_0                     : 25;     /*!< [31:7] : reserved. */
        } FLASH_INTR_ST_CLRb;
    };

    union
    {
        __IOM uint32_t FLASH_ST_CLR;  /*!< 0x00000080 */ 
    
        struct
        {
                  uint32_t RSV_2                     : 8 ;     /*!< [7:0] : reserved. */
            __IOM uint32_t WRITE_CNT_CLR             : 1 ;     /*!< [8:8] : clr write cnt. */
                  uint32_t RSV_1                     : 1 ;     /*!< [9:9] : reserved. */
            __IOM uint32_t AXI_WERR_ADDR_CLR         : 1 ;     /*!< [10:10] : clr axi_werr_addr. */
                  uint32_t RSV_0                     : 21;     /*!< [31:11] : reserved. */
        } FLASH_ST_CLRb;
    };

    union
    {
        __IM uint32_t FLASH_FSM;  /*!< 0x00000084 */ 
    
        struct
        {
            __IM  uint32_t C_STATE                   : 4 ;     /*!< [3:0] : current state. */
                  uint32_t RSV_1                     : 4 ;     /*!< [7:4] : reserved. */
            __IM  uint32_t FLASH_READY               : 1 ;     /*!< [8:8] : flash ready, can operate flash. */
                  uint32_t RSV_0                     : 23;     /*!< [31:9] : reserved. */
        } FLASH_FSMb;
    };

    union
    {
        __IM uint32_t AXI_WERR_ADDR;  /*!< 0x00000088 */ 
    
        struct
        {
            __IM  uint32_t AXI_WERR_ADDR             : 32;     /*!< [31:0] : axi err write addr. */
        } AXI_WERR_ADDRb;
    };

    union
    {
        __IOM uint32_t PROTECT_EN;  /*!< 0x0000008c */ 
    
        struct
        {
            __IOM uint32_t LOCK_EN                   : 1 ;     /*!< [0:0] : lock enable. */
                  uint32_t RSV_0                     : 31;     /*!< [31:1] : reserved. */
        } PROTECT_ENb;
    };

    union
    {
        __IM uint32_t WRITE_CNT;  /*!< 0x00000090 */ 
    
        struct
        {
            __IM  uint32_t WRITE_CNT                 : 32;     /*!< [31:0] : how many date write. */
        } WRITE_CNTb;
    };

    union
    {
        __IM uint32_t CFIFO_DBG_H;  /*!< 0x00000094 */ 
    
        struct
        {
            __IM  uint32_t CFIFO_DBG_H               : 32;     /*!< [31:0] : axi cmd current used in quence, cfifo_dbg_h,cfifo_debug_l = valid, ready,wr_flag,addr[11:0],burst[1:0],id[2:0],len[3:0],size[2:0]. */
        } CFIFO_DBG_Hb;
    };

    union
    {
        __IM uint32_t CFIFO_DUG2_L;  /*!< 0x00000098 */ 
    
        struct
        {
            __IM  uint32_t CFIFO_DBG_L               : 32;     /*!< [31:0] : axi cmd current used in quence, cfifo_dbg_h,cfifo_debug_l = valid, ready,wr_flag,addr[11:0],burst[1:0],id[2:0],len[3:0],size[2:0]. */
        } CFIFO_DUG2_Lb;
    };

    union
    {
        __IM uint32_t CFG_VALUE0;  /*!< 0x0000009c */ 
    
        struct
        {
            __IM  uint32_t CBD0                      : 16;     /*!< [15:0] : eflash ip cfg value, this value is auto read from nvg_cfg. */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } CFG_VALUE0b;
    };

    union
    {
        __IM uint32_t CFG_VALUE1;  /*!< 0x000000a0 */ 
    
        struct
        {
            __IM  uint32_t CBD1                      : 16;     /*!< [15:0] : eflash ip cfg value, this value is auto read from nvg_cfg. */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } CFG_VALUE1b;
    };

    union
    {
        __IM uint32_t CFG_VALUE2;  /*!< 0x000000a4 */ 
    
        struct
        {
            __IM  uint32_t CBD2                      : 16;     /*!< [15:0] : eflash ip cfg value, this value is auto read from nvg_cfg. */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } CFG_VALUE2b;
    };

    union
    {
        __IM uint32_t CFG_VALUE3;  /*!< 0x000000a8 */ 
    
        struct
        {
            __IM  uint32_t CBD3                      : 16;     /*!< [15:0] : eflash ip cfg value, this value is auto read from nvg_cfg. */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } CFG_VALUE3b;
    };

    union
    {
        __IM uint32_t CFG_VALUE4;  /*!< 0x000000ac */ 
    
        struct
        {
            __IM  uint32_t CBD4                      : 16;     /*!< [15:0] : eflash ip cfg value, this value is auto read from nvg_cfg. */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } CFG_VALUE4b;
    };

    union
    {
        __IM uint32_t CFG_VALUE5;  /*!< 0x000000b0 */ 
    
        struct
        {
            __IM  uint32_t CBD5                      : 16;     /*!< [15:0] : eflash ip cfg value, this value is auto read from nvg_cfg. */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } CFG_VALUE5b;
    };

    union
    {
        __IM uint32_t CFG_VALUE6;  /*!< 0x000000b4 */ 
    
        struct
        {
            __IM  uint32_t CBD6                      : 16;     /*!< [15:0] : eflash ip cfg value, this value is auto read from nvg_cfg. */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } CFG_VALUE6b;
    };

    union
    {
        __IM uint32_t CFG_VALUE7;  /*!< 0x000000b8 */ 
    
        struct
        {
            __IM  uint32_t CBD7                      : 16;     /*!< [15:0] : eflash ip cfg value, this value is auto read from nvg_cfg. */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } CFG_VALUE7b;
    };

    union
    {
        __IM uint32_t USR4_VALUE;  /*!< 0x000000bc */ 
    
        struct
        {
            __IM  uint32_t USR4                      : 32;     /*!< [31:0] : eflash cfg nvr 0x1fff4. */
        } USR4_VALUEb;
    };

    union
    {
        __IM uint32_t USR5_VALUE;  /*!< 0x000000c0 */ 
    
        struct
        {
            __IM  uint32_t USR5                      : 32;     /*!< [31:0] : eflash cfg nvr 0x1fff5. */
        } USR5_VALUEb;
    };

    union
    {
        __IM uint32_t RR0_VALUE;  /*!< 0x000000c4 */ 
    
        struct
        {
            __IM  uint32_t RR0                       : 32;     /*!< [31:0] : eflash ip cfg value, this value is RR0, 0x1fff6. */
        } RR0_VALUEb;
    };

    union
    {
        __IM uint32_t RR1_VALUE;  /*!< 0x000000c8 */ 
    
        struct
        {
            __IM  uint32_t RR1                       : 32;     /*!< [31:0] : eflash ip cfg value, this value is RR1, 0x1fff7. */
        } RR1_VALUEb;
    };

    union
    {
        __IM uint32_t BIST_REG_SOC;  /*!< 0x000000cc */ 
    
        struct
        {
            __IM  uint32_t BIST_REG_SOC              : 32;     /*!< [31:0] : bist reg for soc debug. */
        } BIST_REG_SOCb;
    };

} EFLASH_Type;

/*!
 * @}
 */


/*!
 * \name EFLASH Base Address Definitions
 *
 * @{
 */
#if defined(HTE_DEVICE_HS32F7D377_CPU1)
/*! \brief EFLASH0 base address */
#define EFLASH0_BASE (0x41700000UL)
/*! \brief EFLASH0 base pointer */
#define EFLASH0 ((EFLASH_Type *)EFLASH0_BASE)
/*! \brief EFLASH1 base address */
#define EFLASH1_BASE (0x41701000UL)
/*! \brief EFLASH1 base pointer */
#define EFLASH1 ((EFLASH_Type *)EFLASH1_BASE)

#elif defined(HTE_DEVICE_HS32F7D377_CPU2)
/*! \brief EFLASH1 base address */
#define EFLASH1_BASE (0x41700000UL)
/*! \brief EFLASH1 base pointer */
#define EFLASH1 ((EFLASH_Type *)EFLASH1_BASE)

#endif


/*!
 * @}
 */


/*!
 * \name EFLASH Register Bitfield Definitions
 *
 * @{
 */

/* POR_CNT bitfield */
#define EFLASH_POR_CNT_TRT_Pos    (16U)                                                                                 /*!< TRT Position  16         */ 
#define EFLASH_POR_CNT_TRT_Msk    (0xffU << EFLASH_POR_CNT_TRT_Pos)                                                     /*!< TRT Mask      0x00FF0000 */
#define EFLASH_POR_CNT_TRT_Set(x) (((uint32_t) (x) << EFLASH_POR_CNT_TRT_Pos) & EFLASH_POR_CNT_TRT_Msk)                 /*!< TRT Set Value            */
#define EFLASH_POR_CNT_TRT_Get(x) (((uint32_t) (x) & EFLASH_POR_CNT_TRT_Msk) >> EFLASH_POR_CNT_TRT_Pos)                 /*!< TRT Get Value            */

#define EFLASH_POR_CNT_TRHR_Pos    (0U)                                                                                  /*!< TRHR Position  0          */ 
#define EFLASH_POR_CNT_TRHR_Msk    (0xffffU << EFLASH_POR_CNT_TRHR_Pos)                                                  /*!< TRHR Mask      0x0000FFFF */
#define EFLASH_POR_CNT_TRHR_Set(x) (((uint32_t) (x) << EFLASH_POR_CNT_TRHR_Pos) & EFLASH_POR_CNT_TRHR_Msk)               /*!< TRHR Set Value            */
#define EFLASH_POR_CNT_TRHR_Get(x) (((uint32_t) (x) & EFLASH_POR_CNT_TRHR_Msk) >> EFLASH_POR_CNT_TRHR_Pos)               /*!< TRHR Get Value            */

/* DPD_CNT bitfield */
#define EFLASH_DPD_CNT_TDPDH_Pos    (16U)                                                                                 /*!< TDPDH Position  16         */ 
#define EFLASH_DPD_CNT_TDPDH_Msk    (0xffffU << EFLASH_DPD_CNT_TDPDH_Pos)                                                 /*!< TDPDH Mask      0xFFFF0000 */
#define EFLASH_DPD_CNT_TDPDH_Set(x) (((uint32_t) (x) << EFLASH_DPD_CNT_TDPDH_Pos) & EFLASH_DPD_CNT_TDPDH_Msk)             /*!< TDPDH Set Value            */
#define EFLASH_DPD_CNT_TDPDH_Get(x) (((uint32_t) (x) & EFLASH_DPD_CNT_TDPDH_Msk) >> EFLASH_DPD_CNT_TDPDH_Pos)             /*!< TDPDH Get Value            */

#define EFLASH_DPD_CNT_TDPDSR_Pos    (8U)                                                                                  /*!< TDPDSR Position  8          */ 
#define EFLASH_DPD_CNT_TDPDSR_Msk    (0xffU << EFLASH_DPD_CNT_TDPDSR_Pos)                                                  /*!< TDPDSR Mask      0x0000FF00 */
#define EFLASH_DPD_CNT_TDPDSR_Set(x) (((uint32_t) (x) << EFLASH_DPD_CNT_TDPDSR_Pos) & EFLASH_DPD_CNT_TDPDSR_Msk)           /*!< TDPDSR Set Value            */
#define EFLASH_DPD_CNT_TDPDSR_Get(x) (((uint32_t) (x) & EFLASH_DPD_CNT_TDPDSR_Msk) >> EFLASH_DPD_CNT_TDPDSR_Pos)           /*!< TDPDSR Get Value            */

/* LVCTL_CNT bitfield */
#define EFLASH_LVCTL_CNT_TCRC_LVCTL_Pos    (8U)                                                                                  /*!< TCRC_LVCTL Position  8          */ 
#define EFLASH_LVCTL_CNT_TCRC_LVCTL_Msk    (0x1U << EFLASH_LVCTL_CNT_TCRC_LVCTL_Pos)                                             /*!< TCRC_LVCTL Mask      0x00000100 */
#define EFLASH_LVCTL_CNT_TCRC_LVCTL_Set(x) (((uint32_t) (x) << EFLASH_LVCTL_CNT_TCRC_LVCTL_Pos) & EFLASH_LVCTL_CNT_TCRC_LVCTL_Msk) /*!< TCRC_LVCTL Set Value            */
#define EFLASH_LVCTL_CNT_TCRC_LVCTL_Get(x) (((uint32_t) (x) & EFLASH_LVCTL_CNT_TCRC_LVCTL_Msk) >> EFLASH_LVCTL_CNT_TCRC_LVCTL_Pos) /*!< TCRC_LVCTL Get Value            */

#define EFLASH_LVCTL_CNT_TACC_LVCTL_Pos    (0U)                                                                                  /*!< TACC_LVCTL Position  0          */ 
#define EFLASH_LVCTL_CNT_TACC_LVCTL_Msk    (0xffU << EFLASH_LVCTL_CNT_TACC_LVCTL_Pos)                                            /*!< TACC_LVCTL Mask      0x000000FF */
#define EFLASH_LVCTL_CNT_TACC_LVCTL_Set(x) (((uint32_t) (x) << EFLASH_LVCTL_CNT_TACC_LVCTL_Pos) & EFLASH_LVCTL_CNT_TACC_LVCTL_Msk) /*!< TACC_LVCTL Set Value            */
#define EFLASH_LVCTL_CNT_TACC_LVCTL_Get(x) (((uint32_t) (x) & EFLASH_LVCTL_CNT_TACC_LVCTL_Msk) >> EFLASH_LVCTL_CNT_TACC_LVCTL_Pos) /*!< TACC_LVCTL Get Value            */

/* PROG_CNT1 bitfield */
#define EFLASH_PROG_CNT1_TPROG_Pos    (16U)                                                                                 /*!< TPROG Position  16         */ 
#define EFLASH_PROG_CNT1_TPROG_Msk    (0x1fffU << EFLASH_PROG_CNT1_TPROG_Pos)                                               /*!< TPROG Mask      0x1FFF0000 */
#define EFLASH_PROG_CNT1_TPROG_Set(x) (((uint32_t) (x) << EFLASH_PROG_CNT1_TPROG_Pos) & EFLASH_PROG_CNT1_TPROG_Msk)         /*!< TPROG Set Value            */
#define EFLASH_PROG_CNT1_TPROG_Get(x) (((uint32_t) (x) & EFLASH_PROG_CNT1_TPROG_Msk) >> EFLASH_PROG_CNT1_TPROG_Pos)         /*!< TPROG Get Value            */

#define EFLASH_PROG_CNT1_TPGS_Pos    (0U)                                                                                  /*!< TPGS Position  0          */ 
#define EFLASH_PROG_CNT1_TPGS_Msk    (0x1fffU << EFLASH_PROG_CNT1_TPGS_Pos)                                                /*!< TPGS Mask      0x00001FFF */
#define EFLASH_PROG_CNT1_TPGS_Set(x) (((uint32_t) (x) << EFLASH_PROG_CNT1_TPGS_Pos) & EFLASH_PROG_CNT1_TPGS_Msk)           /*!< TPGS Set Value            */
#define EFLASH_PROG_CNT1_TPGS_Get(x) (((uint32_t) (x) & EFLASH_PROG_CNT1_TPGS_Msk) >> EFLASH_PROG_CNT1_TPGS_Pos)           /*!< TPGS Get Value            */

/* PROG_CNT2 bitfield */
#define EFLASH_PROG_CNT2_TADS_Pos    (20U)                                                                                 /*!< TADS Position  20         */ 
#define EFLASH_PROG_CNT2_TADS_Msk    (0x7U << EFLASH_PROG_CNT2_TADS_Pos)                                                   /*!< TADS Mask      0x00700000 */
#define EFLASH_PROG_CNT2_TADS_Set(x) (((uint32_t) (x) << EFLASH_PROG_CNT2_TADS_Pos) & EFLASH_PROG_CNT2_TADS_Msk)           /*!< TADS Set Value            */
#define EFLASH_PROG_CNT2_TADS_Get(x) (((uint32_t) (x) & EFLASH_PROG_CNT2_TADS_Msk) >> EFLASH_PROG_CNT2_TADS_Pos)           /*!< TADS Get Value            */

#define EFLASH_PROG_CNT2_TADH_Pos    (16U)                                                                                 /*!< TADH Position  16         */ 
#define EFLASH_PROG_CNT2_TADH_Msk    (0x7U << EFLASH_PROG_CNT2_TADH_Pos)                                                   /*!< TADH Mask      0x00070000 */
#define EFLASH_PROG_CNT2_TADH_Set(x) (((uint32_t) (x) << EFLASH_PROG_CNT2_TADH_Pos) & EFLASH_PROG_CNT2_TADH_Msk)           /*!< TADH Set Value            */
#define EFLASH_PROG_CNT2_TADH_Get(x) (((uint32_t) (x) & EFLASH_PROG_CNT2_TADH_Msk) >> EFLASH_PROG_CNT2_TADH_Pos)           /*!< TADH Get Value            */

#define EFLASH_PROG_CNT2_TPGH_Pos    (0U)                                                                                  /*!< TPGH Position  0          */ 
#define EFLASH_PROG_CNT2_TPGH_Msk    (0x7U << EFLASH_PROG_CNT2_TPGH_Pos)                                                   /*!< TPGH Mask      0x00000007 */
#define EFLASH_PROG_CNT2_TPGH_Set(x) (((uint32_t) (x) << EFLASH_PROG_CNT2_TPGH_Pos) & EFLASH_PROG_CNT2_TPGH_Msk)           /*!< TPGH Set Value            */
#define EFLASH_PROG_CNT2_TPGH_Get(x) (((uint32_t) (x) & EFLASH_PROG_CNT2_TPGH_Msk) >> EFLASH_PROG_CNT2_TPGH_Pos)           /*!< TPGH Get Value            */

/* PROG_CNT3 bitfield */
#define EFLASH_PROG_CNT3_TNVS_Pos    (0U)                                                                                  /*!< TNVS Position  0          */ 
#define EFLASH_PROG_CNT3_TNVS_Msk    (0x7ffU << EFLASH_PROG_CNT3_TNVS_Pos)                                                 /*!< TNVS Mask      0x000007FF */
#define EFLASH_PROG_CNT3_TNVS_Set(x) (((uint32_t) (x) << EFLASH_PROG_CNT3_TNVS_Pos) & EFLASH_PROG_CNT3_TNVS_Msk)           /*!< TNVS Set Value            */
#define EFLASH_PROG_CNT3_TNVS_Get(x) (((uint32_t) (x) & EFLASH_PROG_CNT3_TNVS_Msk) >> EFLASH_PROG_CNT3_TNVS_Pos)           /*!< TNVS Get Value            */

/* PROG_CNT4 bitfield */
#define EFLASH_PROG_CNT4_TWS_Pos    (16U)                                                                                 /*!< TWS Position  16         */ 
#define EFLASH_PROG_CNT4_TWS_Msk    (0x3U << EFLASH_PROG_CNT4_TWS_Pos)                                                    /*!< TWS Mask      0x00030000 */
#define EFLASH_PROG_CNT4_TWS_Set(x) (((uint32_t) (x) << EFLASH_PROG_CNT4_TWS_Pos) & EFLASH_PROG_CNT4_TWS_Msk)             /*!< TWS Set Value            */
#define EFLASH_PROG_CNT4_TWS_Get(x) (((uint32_t) (x) & EFLASH_PROG_CNT4_TWS_Msk) >> EFLASH_PROG_CNT4_TWS_Pos)             /*!< TWS Get Value            */

#define EFLASH_PROG_CNT4_TACC_Pos    (8U)                                                                                  /*!< TACC Position  8          */ 
#define EFLASH_PROG_CNT4_TACC_Msk    (0xffU << EFLASH_PROG_CNT4_TACC_Pos)                                                  /*!< TACC Mask      0x0000FF00 */
#define EFLASH_PROG_CNT4_TACC_Set(x) (((uint32_t) (x) << EFLASH_PROG_CNT4_TACC_Pos) & EFLASH_PROG_CNT4_TACC_Msk)           /*!< TACC Set Value            */
#define EFLASH_PROG_CNT4_TACC_Get(x) (((uint32_t) (x) & EFLASH_PROG_CNT4_TACC_Msk) >> EFLASH_PROG_CNT4_TACC_Pos)           /*!< TACC Get Value            */

#define EFLASH_PROG_CNT4_TRW_Pos    (0U)                                                                                  /*!< TRW Position  0          */ 
#define EFLASH_PROG_CNT4_TRW_Msk    (0xffU << EFLASH_PROG_CNT4_TRW_Pos)                                                   /*!< TRW Mask      0x000000FF */
#define EFLASH_PROG_CNT4_TRW_Set(x) (((uint32_t) (x) << EFLASH_PROG_CNT4_TRW_Pos) & EFLASH_PROG_CNT4_TRW_Msk)             /*!< TRW Set Value            */
#define EFLASH_PROG_CNT4_TRW_Get(x) (((uint32_t) (x) & EFLASH_PROG_CNT4_TRW_Msk) >> EFLASH_PROG_CNT4_TRW_Pos)             /*!< TRW Get Value            */

/* RCV_CNT1 bitfield */
#define EFLASH_RCV_CNT1_TRCV_PROG_Pos    (16U)                                                                                 /*!< TRCV_PROG Position  16         */ 
#define EFLASH_RCV_CNT1_TRCV_PROG_Msk    (0xffffU << EFLASH_RCV_CNT1_TRCV_PROG_Pos)                                            /*!< TRCV_PROG Mask      0xFFFF0000 */
#define EFLASH_RCV_CNT1_TRCV_PROG_Set(x) (((uint32_t) (x) << EFLASH_RCV_CNT1_TRCV_PROG_Pos) & EFLASH_RCV_CNT1_TRCV_PROG_Msk)   /*!< TRCV_PROG Set Value            */
#define EFLASH_RCV_CNT1_TRCV_PROG_Get(x) (((uint32_t) (x) & EFLASH_RCV_CNT1_TRCV_PROG_Msk) >> EFLASH_RCV_CNT1_TRCV_PROG_Pos)   /*!< TRCV_PROG Get Value            */

#define EFLASH_RCV_CNT1_TRCV_SECER_Pos    (0U)                                                                                  /*!< TRCV_SECER Position  0          */ 
#define EFLASH_RCV_CNT1_TRCV_SECER_Msk    (0xffffU << EFLASH_RCV_CNT1_TRCV_SECER_Pos)                                           /*!< TRCV_SECER Mask      0x0000FFFF */
#define EFLASH_RCV_CNT1_TRCV_SECER_Set(x) (((uint32_t) (x) << EFLASH_RCV_CNT1_TRCV_SECER_Pos) & EFLASH_RCV_CNT1_TRCV_SECER_Msk) /*!< TRCV_SECER Set Value            */
#define EFLASH_RCV_CNT1_TRCV_SECER_Get(x) (((uint32_t) (x) & EFLASH_RCV_CNT1_TRCV_SECER_Msk) >> EFLASH_RCV_CNT1_TRCV_SECER_Pos) /*!< TRCV_SECER Get Value            */

/* RCV_CNT2 bitfield */
#define EFLASH_RCV_CNT2_TRCV_CHIPER_Pos    (0U)                                                                                  /*!< TRCV_CHIPER Position  0          */ 
#define EFLASH_RCV_CNT2_TRCV_CHIPER_Msk    (0xffffffffU << EFLASH_RCV_CNT2_TRCV_CHIPER_Pos)                                      /*!< TRCV_CHIPER Mask      0xFFFFFFFF */
#define EFLASH_RCV_CNT2_TRCV_CHIPER_Set(x) (((uint32_t) (x) << EFLASH_RCV_CNT2_TRCV_CHIPER_Pos) & EFLASH_RCV_CNT2_TRCV_CHIPER_Msk) /*!< TRCV_CHIPER Set Value            */
#define EFLASH_RCV_CNT2_TRCV_CHIPER_Get(x) (((uint32_t) (x) & EFLASH_RCV_CNT2_TRCV_CHIPER_Msk) >> EFLASH_RCV_CNT2_TRCV_CHIPER_Pos) /*!< TRCV_CHIPER Get Value            */

/* ERASE_CNT1 bitfield */
#define EFLASH_ERASE_CNT1_TSEC_ERASE_Pos    (0U)                                                                                  /*!< TSEC_ERASE Position  0          */ 
#define EFLASH_ERASE_CNT1_TSEC_ERASE_Msk    (0xffffffffU << EFLASH_ERASE_CNT1_TSEC_ERASE_Pos)                                     /*!< TSEC_ERASE Mask      0xFFFFFFFF */
#define EFLASH_ERASE_CNT1_TSEC_ERASE_Set(x) (((uint32_t) (x) << EFLASH_ERASE_CNT1_TSEC_ERASE_Pos) & EFLASH_ERASE_CNT1_TSEC_ERASE_Msk) /*!< TSEC_ERASE Set Value            */
#define EFLASH_ERASE_CNT1_TSEC_ERASE_Get(x) (((uint32_t) (x) & EFLASH_ERASE_CNT1_TSEC_ERASE_Msk) >> EFLASH_ERASE_CNT1_TSEC_ERASE_Pos) /*!< TSEC_ERASE Get Value            */

/* ERASE_CNT2 bitfield */
#define EFLASH_ERASE_CNT2_TCHIP_ERASE_Pos    (0U)                                                                                  /*!< TCHIP_ERASE Position  0          */ 
#define EFLASH_ERASE_CNT2_TCHIP_ERASE_Msk    (0xffffffffU << EFLASH_ERASE_CNT2_TCHIP_ERASE_Pos)                                    /*!< TCHIP_ERASE Mask      0xFFFFFFFF */
#define EFLASH_ERASE_CNT2_TCHIP_ERASE_Set(x) (((uint32_t) (x) << EFLASH_ERASE_CNT2_TCHIP_ERASE_Pos) & EFLASH_ERASE_CNT2_TCHIP_ERASE_Msk) /*!< TCHIP_ERASE Set Value            */
#define EFLASH_ERASE_CNT2_TCHIP_ERASE_Get(x) (((uint32_t) (x) & EFLASH_ERASE_CNT2_TCHIP_ERASE_Msk) >> EFLASH_ERASE_CNT2_TCHIP_ERASE_Pos) /*!< TCHIP_ERASE Get Value            */

/* NVR_CFG bitfield */
#define EFLASH_NVR_CFG_TACC_NVR_Pos    (16U)                                                                                 /*!< TACC_NVR Position  16         */ 
#define EFLASH_NVR_CFG_TACC_NVR_Msk    (0xffffU << EFLASH_NVR_CFG_TACC_NVR_Pos)                                              /*!< TACC_NVR Mask      0xFFFF0000 */
#define EFLASH_NVR_CFG_TACC_NVR_Set(x) (((uint32_t) (x) << EFLASH_NVR_CFG_TACC_NVR_Pos) & EFLASH_NVR_CFG_TACC_NVR_Msk)       /*!< TACC_NVR Set Value            */
#define EFLASH_NVR_CFG_TACC_NVR_Get(x) (((uint32_t) (x) & EFLASH_NVR_CFG_TACC_NVR_Msk) >> EFLASH_NVR_CFG_TACC_NVR_Pos)       /*!< TACC_NVR Get Value            */

#define EFLASH_NVR_CFG_TMS_Pos    (0U)                                                                                  /*!< TMS Position  0          */ 
#define EFLASH_NVR_CFG_TMS_Msk    (0xffffU << EFLASH_NVR_CFG_TMS_Pos)                                                   /*!< TMS Mask      0x0000FFFF */
#define EFLASH_NVR_CFG_TMS_Set(x) (((uint32_t) (x) << EFLASH_NVR_CFG_TMS_Pos) & EFLASH_NVR_CFG_TMS_Msk)                 /*!< TMS Set Value            */
#define EFLASH_NVR_CFG_TMS_Get(x) (((uint32_t) (x) & EFLASH_NVR_CFG_TMS_Msk) >> EFLASH_NVR_CFG_TMS_Pos)                 /*!< TMS Get Value            */

/* SET_CFG1 bitfield */
#define EFLASH_SET_CFG1_TCFH_Pos    (16U)                                                                                 /*!< TCFH Position  16         */ 
#define EFLASH_SET_CFG1_TCFH_Msk    (0xffU << EFLASH_SET_CFG1_TCFH_Pos)                                                   /*!< TCFH Mask      0x00FF0000 */
#define EFLASH_SET_CFG1_TCFH_Set(x) (((uint32_t) (x) << EFLASH_SET_CFG1_TCFH_Pos) & EFLASH_SET_CFG1_TCFH_Msk)             /*!< TCFH Set Value            */
#define EFLASH_SET_CFG1_TCFH_Get(x) (((uint32_t) (x) & EFLASH_SET_CFG1_TCFH_Msk) >> EFLASH_SET_CFG1_TCFH_Pos)             /*!< TCFH Get Value            */

#define EFLASH_SET_CFG1_TCFL_Pos    (0U)                                                                                  /*!< TCFL Position  0          */ 
#define EFLASH_SET_CFG1_TCFL_Msk    (0xffffU << EFLASH_SET_CFG1_TCFL_Pos)                                                 /*!< TCFL Mask      0x0000FFFF */
#define EFLASH_SET_CFG1_TCFL_Set(x) (((uint32_t) (x) << EFLASH_SET_CFG1_TCFL_Pos) & EFLASH_SET_CFG1_TCFL_Msk)             /*!< TCFL Set Value            */
#define EFLASH_SET_CFG1_TCFL_Get(x) (((uint32_t) (x) & EFLASH_SET_CFG1_TCFL_Msk) >> EFLASH_SET_CFG1_TCFL_Pos)             /*!< TCFL Get Value            */

/* SET_CFG2 bitfield */
#define EFLASH_SET_CFG2_TCONFEN_Pos    (0U)                                                                                  /*!< TCONFEN Position  0          */ 
#define EFLASH_SET_CFG2_TCONFEN_Msk    (0x7U << EFLASH_SET_CFG2_TCONFEN_Pos)                                                 /*!< TCONFEN Mask      0x00000007 */
#define EFLASH_SET_CFG2_TCONFEN_Set(x) (((uint32_t) (x) << EFLASH_SET_CFG2_TCONFEN_Pos) & EFLASH_SET_CFG2_TCONFEN_Msk)       /*!< TCONFEN Set Value            */
#define EFLASH_SET_CFG2_TCONFEN_Get(x) (((uint32_t) (x) & EFLASH_SET_CFG2_TCONFEN_Msk) >> EFLASH_SET_CFG2_TCONFEN_Pos)       /*!< TCONFEN Get Value            */

/* WR_DATA1 bitfield */
#define EFLASH_WR_DATA1_WR_DATA_H_Pos    (0U)                                                                                  /*!< WR_DATA_H Position  0          */ 
#define EFLASH_WR_DATA1_WR_DATA_H_Msk    (0xffffffffU << EFLASH_WR_DATA1_WR_DATA_H_Pos)                                        /*!< WR_DATA_H Mask      0xFFFFFFFF */
#define EFLASH_WR_DATA1_WR_DATA_H_Set(x) (((uint32_t) (x) << EFLASH_WR_DATA1_WR_DATA_H_Pos) & EFLASH_WR_DATA1_WR_DATA_H_Msk)   /*!< WR_DATA_H Set Value            */
#define EFLASH_WR_DATA1_WR_DATA_H_Get(x) (((uint32_t) (x) & EFLASH_WR_DATA1_WR_DATA_H_Msk) >> EFLASH_WR_DATA1_WR_DATA_H_Pos)   /*!< WR_DATA_H Get Value            */

/* WR_DATA2 bitfield */
#define EFLASH_WR_DATA2_WR_DATA_L_Pos    (0U)                                                                                  /*!< WR_DATA_L Position  0          */ 
#define EFLASH_WR_DATA2_WR_DATA_L_Msk    (0xffffffffU << EFLASH_WR_DATA2_WR_DATA_L_Pos)                                        /*!< WR_DATA_L Mask      0xFFFFFFFF */
#define EFLASH_WR_DATA2_WR_DATA_L_Set(x) (((uint32_t) (x) << EFLASH_WR_DATA2_WR_DATA_L_Pos) & EFLASH_WR_DATA2_WR_DATA_L_Msk)   /*!< WR_DATA_L Set Value            */
#define EFLASH_WR_DATA2_WR_DATA_L_Get(x) (((uint32_t) (x) & EFLASH_WR_DATA2_WR_DATA_L_Msk) >> EFLASH_WR_DATA2_WR_DATA_L_Pos)   /*!< WR_DATA_L Get Value            */

/* WR_ADDR bitfield */
#define EFLASH_WR_ADDR_OP_ADDR_Pos    (0U)                                                                                  /*!< OP_ADDR Position  0          */ 
#define EFLASH_WR_ADDR_OP_ADDR_Msk    (0x1ffffU << EFLASH_WR_ADDR_OP_ADDR_Pos)                                              /*!< OP_ADDR Mask      0x0001FFFF */
#define EFLASH_WR_ADDR_OP_ADDR_Set(x) (((uint32_t) (x) << EFLASH_WR_ADDR_OP_ADDR_Pos) & EFLASH_WR_ADDR_OP_ADDR_Msk)         /*!< OP_ADDR Set Value            */
#define EFLASH_WR_ADDR_OP_ADDR_Get(x) (((uint32_t) (x) & EFLASH_WR_ADDR_OP_ADDR_Msk) >> EFLASH_WR_ADDR_OP_ADDR_Pos)         /*!< OP_ADDR Get Value            */

/* READ_OUTPUT_H bitfield */
#define EFLASH_READ_OUTPUT_H_RD_DATA_H_Pos    (0U)                                                                                  /*!< RD_DATA_H Position  0          */ 
#define EFLASH_READ_OUTPUT_H_RD_DATA_H_Msk    (0xffffffffU << EFLASH_READ_OUTPUT_H_RD_DATA_H_Pos)                                   /*!< RD_DATA_H Mask      0xFFFFFFFF */
#define EFLASH_READ_OUTPUT_H_RD_DATA_H_Set(x) (((uint32_t) (x) << EFLASH_READ_OUTPUT_H_RD_DATA_H_Pos) & EFLASH_READ_OUTPUT_H_RD_DATA_H_Msk) /*!< RD_DATA_H Set Value            */
#define EFLASH_READ_OUTPUT_H_RD_DATA_H_Get(x) (((uint32_t) (x) & EFLASH_READ_OUTPUT_H_RD_DATA_H_Msk) >> EFLASH_READ_OUTPUT_H_RD_DATA_H_Pos) /*!< RD_DATA_H Get Value            */

/* READ_OUTPUT_L bitfield */
#define EFLASH_READ_OUTPUT_L_RD_DATA_L_Pos    (0U)                                                                                  /*!< RD_DATA_L Position  0          */ 
#define EFLASH_READ_OUTPUT_L_RD_DATA_L_Msk    (0xffffffffU << EFLASH_READ_OUTPUT_L_RD_DATA_L_Pos)                                   /*!< RD_DATA_L Mask      0xFFFFFFFF */
#define EFLASH_READ_OUTPUT_L_RD_DATA_L_Set(x) (((uint32_t) (x) << EFLASH_READ_OUTPUT_L_RD_DATA_L_Pos) & EFLASH_READ_OUTPUT_L_RD_DATA_L_Msk) /*!< RD_DATA_L Set Value            */
#define EFLASH_READ_OUTPUT_L_RD_DATA_L_Get(x) (((uint32_t) (x) & EFLASH_READ_OUTPUT_L_RD_DATA_L_Msk) >> EFLASH_READ_OUTPUT_L_RD_DATA_L_Pos) /*!< RD_DATA_L Get Value            */

/* TMEN bitfield */
#define EFLASH_TMEN_TMEN_CFG_Pos    (0U)                                                                                  /*!< TMEN_CFG Position  0          */ 
#define EFLASH_TMEN_TMEN_CFG_Msk    (0x1U << EFLASH_TMEN_TMEN_CFG_Pos)                                                    /*!< TMEN_CFG Mask      0x00000001 */
#define EFLASH_TMEN_TMEN_CFG_Set(x) (((uint32_t) (x) << EFLASH_TMEN_TMEN_CFG_Pos) & EFLASH_TMEN_TMEN_CFG_Msk)             /*!< TMEN_CFG Set Value            */
#define EFLASH_TMEN_TMEN_CFG_Get(x) (((uint32_t) (x) & EFLASH_TMEN_TMEN_CFG_Msk) >> EFLASH_TMEN_TMEN_CFG_Pos)             /*!< TMEN_CFG Get Value            */

/* AXI_CFG bitfield */
#define EFLASH_AXI_CFG_AXI_PROG_EN_Pos    (0U)                                                                                  /*!< AXI_PROG_EN Position  0          */ 
#define EFLASH_AXI_CFG_AXI_PROG_EN_Msk    (0x1U << EFLASH_AXI_CFG_AXI_PROG_EN_Pos)                                              /*!< AXI_PROG_EN Mask      0x00000001 */
#define EFLASH_AXI_CFG_AXI_PROG_EN_Set(x) (((uint32_t) (x) << EFLASH_AXI_CFG_AXI_PROG_EN_Pos) & EFLASH_AXI_CFG_AXI_PROG_EN_Msk) /*!< AXI_PROG_EN Set Value            */
#define EFLASH_AXI_CFG_AXI_PROG_EN_Get(x) (((uint32_t) (x) & EFLASH_AXI_CFG_AXI_PROG_EN_Msk) >> EFLASH_AXI_CFG_AXI_PROG_EN_Pos) /*!< AXI_PROG_EN Get Value            */

/* FLASH_AXI_FIFO bitfield */
#define EFLASH_FLASH_AXI_FIFO_DFIFO_CLR_Pos    (9U)                                                                                  /*!< DFIFO_CLR Position  9          */ 
#define EFLASH_FLASH_AXI_FIFO_DFIFO_CLR_Msk    (0x1U << EFLASH_FLASH_AXI_FIFO_DFIFO_CLR_Pos)                                         /*!< DFIFO_CLR Mask      0x00000200 */
#define EFLASH_FLASH_AXI_FIFO_DFIFO_CLR_Set(x) (((uint32_t) (x) << EFLASH_FLASH_AXI_FIFO_DFIFO_CLR_Pos) & EFLASH_FLASH_AXI_FIFO_DFIFO_CLR_Msk) /*!< DFIFO_CLR Set Value            */
#define EFLASH_FLASH_AXI_FIFO_DFIFO_CLR_Get(x) (((uint32_t) (x) & EFLASH_FLASH_AXI_FIFO_DFIFO_CLR_Msk) >> EFLASH_FLASH_AXI_FIFO_DFIFO_CLR_Pos) /*!< DFIFO_CLR Get Value            */

#define EFLASH_FLASH_AXI_FIFO_CFIFO_CLR_Pos    (8U)                                                                                  /*!< CFIFO_CLR Position  8          */ 
#define EFLASH_FLASH_AXI_FIFO_CFIFO_CLR_Msk    (0x1U << EFLASH_FLASH_AXI_FIFO_CFIFO_CLR_Pos)                                         /*!< CFIFO_CLR Mask      0x00000100 */
#define EFLASH_FLASH_AXI_FIFO_CFIFO_CLR_Set(x) (((uint32_t) (x) << EFLASH_FLASH_AXI_FIFO_CFIFO_CLR_Pos) & EFLASH_FLASH_AXI_FIFO_CFIFO_CLR_Msk) /*!< CFIFO_CLR Set Value            */
#define EFLASH_FLASH_AXI_FIFO_CFIFO_CLR_Get(x) (((uint32_t) (x) & EFLASH_FLASH_AXI_FIFO_CFIFO_CLR_Msk) >> EFLASH_FLASH_AXI_FIFO_CFIFO_CLR_Pos) /*!< CFIFO_CLR Get Value            */

#define EFLASH_FLASH_AXI_FIFO_DFIFO_WL_Pos    (4U)                                                                                  /*!< DFIFO_WL Position  4          */ 
#define EFLASH_FLASH_AXI_FIFO_DFIFO_WL_Msk    (0x7U << EFLASH_FLASH_AXI_FIFO_DFIFO_WL_Pos)                                          /*!< DFIFO_WL Mask      0x00000070 */
#define EFLASH_FLASH_AXI_FIFO_DFIFO_WL_Set(x) (((uint32_t) (x) << EFLASH_FLASH_AXI_FIFO_DFIFO_WL_Pos) & EFLASH_FLASH_AXI_FIFO_DFIFO_WL_Msk) /*!< DFIFO_WL Set Value            */
#define EFLASH_FLASH_AXI_FIFO_DFIFO_WL_Get(x) (((uint32_t) (x) & EFLASH_FLASH_AXI_FIFO_DFIFO_WL_Msk) >> EFLASH_FLASH_AXI_FIFO_DFIFO_WL_Pos) /*!< DFIFO_WL Get Value            */

#define EFLASH_FLASH_AXI_FIFO_CFIFO_WL_Pos    (0U)                                                                                  /*!< CFIFO_WL Position  0          */ 
#define EFLASH_FLASH_AXI_FIFO_CFIFO_WL_Msk    (0x7U << EFLASH_FLASH_AXI_FIFO_CFIFO_WL_Pos)                                          /*!< CFIFO_WL Mask      0x00000007 */
#define EFLASH_FLASH_AXI_FIFO_CFIFO_WL_Set(x) (((uint32_t) (x) << EFLASH_FLASH_AXI_FIFO_CFIFO_WL_Pos) & EFLASH_FLASH_AXI_FIFO_CFIFO_WL_Msk) /*!< CFIFO_WL Set Value            */
#define EFLASH_FLASH_AXI_FIFO_CFIFO_WL_Get(x) (((uint32_t) (x) & EFLASH_FLASH_AXI_FIFO_CFIFO_WL_Msk) >> EFLASH_FLASH_AXI_FIFO_CFIFO_WL_Pos) /*!< CFIFO_WL Get Value            */

/* CFG bitfield */
#define EFLASH_CFG_LVCTL_CFG_Pos    (10U)                                                                                 /*!< LVCTL_CFG Position  10         */ 
#define EFLASH_CFG_LVCTL_CFG_Msk    (0x1U << EFLASH_CFG_LVCTL_CFG_Pos)                                                    /*!< LVCTL_CFG Mask      0x00000400 */
#define EFLASH_CFG_LVCTL_CFG_Set(x) (((uint32_t) (x) << EFLASH_CFG_LVCTL_CFG_Pos) & EFLASH_CFG_LVCTL_CFG_Msk)             /*!< LVCTL_CFG Set Value            */
#define EFLASH_CFG_LVCTL_CFG_Get(x) (((uint32_t) (x) & EFLASH_CFG_LVCTL_CFG_Msk) >> EFLASH_CFG_LVCTL_CFG_Pos)             /*!< LVCTL_CFG Get Value            */

#define EFLASH_CFG_PRE_SAMPLE_EN_Pos    (7U)                                                                                  /*!< PRE_SAMPLE_EN Position  7          */ 
#define EFLASH_CFG_PRE_SAMPLE_EN_Msk    (0x1U << EFLASH_CFG_PRE_SAMPLE_EN_Pos)                                                /*!< PRE_SAMPLE_EN Mask      0x00000080 */
#define EFLASH_CFG_PRE_SAMPLE_EN_Set(x) (((uint32_t) (x) << EFLASH_CFG_PRE_SAMPLE_EN_Pos) & EFLASH_CFG_PRE_SAMPLE_EN_Msk)     /*!< PRE_SAMPLE_EN Set Value            */
#define EFLASH_CFG_PRE_SAMPLE_EN_Get(x) (((uint32_t) (x) & EFLASH_CFG_PRE_SAMPLE_EN_Msk) >> EFLASH_CFG_PRE_SAMPLE_EN_Pos)     /*!< PRE_SAMPLE_EN Get Value            */

#define EFLASH_CFG_AXI_CMD_PRIORITY_Pos    (6U)                                                                                  /*!< AXI_CMD_PRIORITY Position  6          */ 
#define EFLASH_CFG_AXI_CMD_PRIORITY_Msk    (0x1U << EFLASH_CFG_AXI_CMD_PRIORITY_Pos)                                             /*!< AXI_CMD_PRIORITY Mask      0x00000040 */
#define EFLASH_CFG_AXI_CMD_PRIORITY_Set(x) (((uint32_t) (x) << EFLASH_CFG_AXI_CMD_PRIORITY_Pos) & EFLASH_CFG_AXI_CMD_PRIORITY_Msk) /*!< AXI_CMD_PRIORITY Set Value            */
#define EFLASH_CFG_AXI_CMD_PRIORITY_Get(x) (((uint32_t) (x) & EFLASH_CFG_AXI_CMD_PRIORITY_Msk) >> EFLASH_CFG_AXI_CMD_PRIORITY_Pos) /*!< AXI_CMD_PRIORITY Get Value            */

#define EFLASH_CFG_LCK_CFG_Pos    (5U)                                                                                  /*!< LCK_CFG Position  5          */ 
#define EFLASH_CFG_LCK_CFG_Msk    (0x1U << EFLASH_CFG_LCK_CFG_Pos)                                                      /*!< LCK_CFG Mask      0x00000020 */
#define EFLASH_CFG_LCK_CFG_Set(x) (((uint32_t) (x) << EFLASH_CFG_LCK_CFG_Pos) & EFLASH_CFG_LCK_CFG_Msk)                 /*!< LCK_CFG Set Value            */
#define EFLASH_CFG_LCK_CFG_Get(x) (((uint32_t) (x) & EFLASH_CFG_LCK_CFG_Msk) >> EFLASH_CFG_LCK_CFG_Pos)                 /*!< LCK_CFG Get Value            */

#define EFLASH_CFG_DPD_CFG_Pos    (4U)                                                                                  /*!< DPD_CFG Position  4          */ 
#define EFLASH_CFG_DPD_CFG_Msk    (0x1U << EFLASH_CFG_DPD_CFG_Pos)                                                      /*!< DPD_CFG Mask      0x00000010 */
#define EFLASH_CFG_DPD_CFG_Set(x) (((uint32_t) (x) << EFLASH_CFG_DPD_CFG_Pos) & EFLASH_CFG_DPD_CFG_Msk)                 /*!< DPD_CFG Set Value            */
#define EFLASH_CFG_DPD_CFG_Get(x) (((uint32_t) (x) & EFLASH_CFG_DPD_CFG_Msk) >> EFLASH_CFG_DPD_CFG_Pos)                 /*!< DPD_CFG Get Value            */

#define EFLASH_CFG_AUTO_SETCFG_Pos    (3U)                                                                                  /*!< AUTO_SETCFG Position  3          */ 
#define EFLASH_CFG_AUTO_SETCFG_Msk    (0x1U << EFLASH_CFG_AUTO_SETCFG_Pos)                                                  /*!< AUTO_SETCFG Mask      0x00000008 */
#define EFLASH_CFG_AUTO_SETCFG_Set(x) (((uint32_t) (x) << EFLASH_CFG_AUTO_SETCFG_Pos) & EFLASH_CFG_AUTO_SETCFG_Msk)         /*!< AUTO_SETCFG Set Value            */
#define EFLASH_CFG_AUTO_SETCFG_Get(x) (((uint32_t) (x) & EFLASH_CFG_AUTO_SETCFG_Msk) >> EFLASH_CFG_AUTO_SETCFG_Pos)         /*!< AUTO_SETCFG Get Value            */

#define EFLASH_CFG_NVR_Pos    (2U)                                                                                  /*!< NVR Position  2          */ 
#define EFLASH_CFG_NVR_Msk    (0x1U << EFLASH_CFG_NVR_Pos)                                                          /*!< NVR Mask      0x00000004 */
#define EFLASH_CFG_NVR_Set(x) (((uint32_t) (x) << EFLASH_CFG_NVR_Pos) & EFLASH_CFG_NVR_Msk)                         /*!< NVR Set Value            */
#define EFLASH_CFG_NVR_Get(x) (((uint32_t) (x) & EFLASH_CFG_NVR_Msk) >> EFLASH_CFG_NVR_Pos)                         /*!< NVR Get Value            */

#define EFLASH_CFG_NVR_CFG_Pos    (1U)                                                                                  /*!< NVR_CFG Position  1          */ 
#define EFLASH_CFG_NVR_CFG_Msk    (0x1U << EFLASH_CFG_NVR_CFG_Pos)                                                      /*!< NVR_CFG Mask      0x00000002 */
#define EFLASH_CFG_NVR_CFG_Set(x) (((uint32_t) (x) << EFLASH_CFG_NVR_CFG_Pos) & EFLASH_CFG_NVR_CFG_Msk)                 /*!< NVR_CFG Set Value            */
#define EFLASH_CFG_NVR_CFG_Get(x) (((uint32_t) (x) & EFLASH_CFG_NVR_CFG_Msk) >> EFLASH_CFG_NVR_CFG_Pos)                 /*!< NVR_CFG Get Value            */

#define EFLASH_CFG_RECALL_Pos    (0U)                                                                                  /*!< RECALL Position  0          */ 
#define EFLASH_CFG_RECALL_Msk    (0x1U << EFLASH_CFG_RECALL_Pos)                                                       /*!< RECALL Mask      0x00000001 */
#define EFLASH_CFG_RECALL_Set(x) (((uint32_t) (x) << EFLASH_CFG_RECALL_Pos) & EFLASH_CFG_RECALL_Msk)                   /*!< RECALL Set Value            */
#define EFLASH_CFG_RECALL_Get(x) (((uint32_t) (x) & EFLASH_CFG_RECALL_Msk) >> EFLASH_CFG_RECALL_Pos)                   /*!< RECALL Get Value            */

/* CTRL bitfield */
#define EFLASH_CTRL_MODE_SEL_Pos    (4U)                                                                                  /*!< MODE_SEL Position  4          */ 
#define EFLASH_CTRL_MODE_SEL_Msk    (0xfU << EFLASH_CTRL_MODE_SEL_Pos)                                                    /*!< MODE_SEL Mask      0x000000F0 */
#define EFLASH_CTRL_MODE_SEL_Set(x) (((uint32_t) (x) << EFLASH_CTRL_MODE_SEL_Pos) & EFLASH_CTRL_MODE_SEL_Msk)             /*!< MODE_SEL Set Value            */
#define EFLASH_CTRL_MODE_SEL_Get(x) (((uint32_t) (x) & EFLASH_CTRL_MODE_SEL_Msk) >> EFLASH_CTRL_MODE_SEL_Pos)             /*!< MODE_SEL Get Value            */

#define EFLASH_CTRL_CMD_ENABLE_Pos    (0U)                                                                                  /*!< CMD_ENABLE Position  0          */ 
#define EFLASH_CTRL_CMD_ENABLE_Msk    (0x1U << EFLASH_CTRL_CMD_ENABLE_Pos)                                                  /*!< CMD_ENABLE Mask      0x00000001 */
#define EFLASH_CTRL_CMD_ENABLE_Set(x) (((uint32_t) (x) << EFLASH_CTRL_CMD_ENABLE_Pos) & EFLASH_CTRL_CMD_ENABLE_Msk)         /*!< CMD_ENABLE Set Value            */
#define EFLASH_CTRL_CMD_ENABLE_Get(x) (((uint32_t) (x) & EFLASH_CTRL_CMD_ENABLE_Msk) >> EFLASH_CTRL_CMD_ENABLE_Pos)         /*!< CMD_ENABLE Get Value            */

/* KEY_VALUE bitfield */
#define EFLASH_KEY_VALUE_KEY_VALUE_Pos    (0U)                                                                                  /*!< KEY_VALUE Position  0          */ 
#define EFLASH_KEY_VALUE_KEY_VALUE_Msk    (0xffffffffU << EFLASH_KEY_VALUE_KEY_VALUE_Pos)                                       /*!< KEY_VALUE Mask      0xFFFFFFFF */
#define EFLASH_KEY_VALUE_KEY_VALUE_Set(x) (((uint32_t) (x) << EFLASH_KEY_VALUE_KEY_VALUE_Pos) & EFLASH_KEY_VALUE_KEY_VALUE_Msk) /*!< KEY_VALUE Set Value            */
#define EFLASH_KEY_VALUE_KEY_VALUE_Get(x) (((uint32_t) (x) & EFLASH_KEY_VALUE_KEY_VALUE_Msk) >> EFLASH_KEY_VALUE_KEY_VALUE_Pos) /*!< KEY_VALUE Get Value            */

/* RR0_CFG bitfield */
#define EFLASH_RR0_CFG_RR0_EN_Pos    (31U)                                                                                 /*!< RR0_EN Position  31         */ 
#define EFLASH_RR0_CFG_RR0_EN_Msk    (0x1U << EFLASH_RR0_CFG_RR0_EN_Pos)                                                   /*!< RR0_EN Mask      0x80000000 */
#define EFLASH_RR0_CFG_RR0_EN_Set(x) (((uint32_t) (x) << EFLASH_RR0_CFG_RR0_EN_Pos) & EFLASH_RR0_CFG_RR0_EN_Msk)           /*!< RR0_EN Set Value            */
#define EFLASH_RR0_CFG_RR0_EN_Get(x) (((uint32_t) (x) & EFLASH_RR0_CFG_RR0_EN_Msk) >> EFLASH_RR0_CFG_RR0_EN_Pos)           /*!< RR0_EN Get Value            */

#define EFLASH_RR0_CFG_RR0_ADDR_Pos    (0U)                                                                                  /*!< RR0_ADDR Position  0          */ 
#define EFLASH_RR0_CFG_RR0_ADDR_Msk    (0x1ffffU << EFLASH_RR0_CFG_RR0_ADDR_Pos)                                             /*!< RR0_ADDR Mask      0x0001FFFF */
#define EFLASH_RR0_CFG_RR0_ADDR_Set(x) (((uint32_t) (x) << EFLASH_RR0_CFG_RR0_ADDR_Pos) & EFLASH_RR0_CFG_RR0_ADDR_Msk)       /*!< RR0_ADDR Set Value            */
#define EFLASH_RR0_CFG_RR0_ADDR_Get(x) (((uint32_t) (x) & EFLASH_RR0_CFG_RR0_ADDR_Msk) >> EFLASH_RR0_CFG_RR0_ADDR_Pos)       /*!< RR0_ADDR Get Value            */

/* RR1_CFG bitfield */
#define EFLASH_RR1_CFG_RR1_EN_Pos    (31U)                                                                                 /*!< RR1_EN Position  31         */ 
#define EFLASH_RR1_CFG_RR1_EN_Msk    (0x1U << EFLASH_RR1_CFG_RR1_EN_Pos)                                                   /*!< RR1_EN Mask      0x80000000 */
#define EFLASH_RR1_CFG_RR1_EN_Set(x) (((uint32_t) (x) << EFLASH_RR1_CFG_RR1_EN_Pos) & EFLASH_RR1_CFG_RR1_EN_Msk)           /*!< RR1_EN Set Value            */
#define EFLASH_RR1_CFG_RR1_EN_Get(x) (((uint32_t) (x) & EFLASH_RR1_CFG_RR1_EN_Msk) >> EFLASH_RR1_CFG_RR1_EN_Pos)           /*!< RR1_EN Get Value            */

#define EFLASH_RR1_CFG_RR1_ADDR_Pos    (0U)                                                                                  /*!< RR1_ADDR Position  0          */ 
#define EFLASH_RR1_CFG_RR1_ADDR_Msk    (0x1ffffU << EFLASH_RR1_CFG_RR1_ADDR_Pos)                                             /*!< RR1_ADDR Mask      0x0001FFFF */
#define EFLASH_RR1_CFG_RR1_ADDR_Set(x) (((uint32_t) (x) << EFLASH_RR1_CFG_RR1_ADDR_Pos) & EFLASH_RR1_CFG_RR1_ADDR_Msk)       /*!< RR1_ADDR Set Value            */
#define EFLASH_RR1_CFG_RR1_ADDR_Get(x) (((uint32_t) (x) & EFLASH_RR1_CFG_RR1_ADDR_Msk) >> EFLASH_RR1_CFG_RR1_ADDR_Pos)       /*!< RR1_ADDR Get Value            */

/* PROTECT_START bitfield */
#define EFLASH_PROTECT_START_LOCK_BEG_ADDR_Pos    (0U)                                                                                  /*!< LOCK_BEG_ADDR Position  0          */ 
#define EFLASH_PROTECT_START_LOCK_BEG_ADDR_Msk    (0x1ffffU << EFLASH_PROTECT_START_LOCK_BEG_ADDR_Pos)                                  /*!< LOCK_BEG_ADDR Mask      0x0001FFFF */
#define EFLASH_PROTECT_START_LOCK_BEG_ADDR_Set(x) (((uint32_t) (x) << EFLASH_PROTECT_START_LOCK_BEG_ADDR_Pos) & EFLASH_PROTECT_START_LOCK_BEG_ADDR_Msk) /*!< LOCK_BEG_ADDR Set Value            */
#define EFLASH_PROTECT_START_LOCK_BEG_ADDR_Get(x) (((uint32_t) (x) & EFLASH_PROTECT_START_LOCK_BEG_ADDR_Msk) >> EFLASH_PROTECT_START_LOCK_BEG_ADDR_Pos) /*!< LOCK_BEG_ADDR Get Value            */

/* PROTECT_END bitfield */
#define EFLASH_PROTECT_END_LOCK_END_ADDR_Pos    (0U)                                                                                  /*!< LOCK_END_ADDR Position  0          */ 
#define EFLASH_PROTECT_END_LOCK_END_ADDR_Msk    (0x1ffffU << EFLASH_PROTECT_END_LOCK_END_ADDR_Pos)                                    /*!< LOCK_END_ADDR Mask      0x0001FFFF */
#define EFLASH_PROTECT_END_LOCK_END_ADDR_Set(x) (((uint32_t) (x) << EFLASH_PROTECT_END_LOCK_END_ADDR_Pos) & EFLASH_PROTECT_END_LOCK_END_ADDR_Msk) /*!< LOCK_END_ADDR Set Value            */
#define EFLASH_PROTECT_END_LOCK_END_ADDR_Get(x) (((uint32_t) (x) & EFLASH_PROTECT_END_LOCK_END_ADDR_Msk) >> EFLASH_PROTECT_END_LOCK_END_ADDR_Pos) /*!< LOCK_END_ADDR Get Value            */

/* FLASH_INTR_EN bitfield */
#define EFLASH_FLASH_INTR_EN_AHB_W_LOCK_AREA_IE_Pos    (5U)                                                                                  /*!< AHB_W_LOCK_AREA_IE Position  5          */ 
#define EFLASH_FLASH_INTR_EN_AHB_W_LOCK_AREA_IE_Msk    (0x1U << EFLASH_FLASH_INTR_EN_AHB_W_LOCK_AREA_IE_Pos)                                 /*!< AHB_W_LOCK_AREA_IE Mask      0x00000020 */
#define EFLASH_FLASH_INTR_EN_AHB_W_LOCK_AREA_IE_Set(x) (((uint32_t) (x) << EFLASH_FLASH_INTR_EN_AHB_W_LOCK_AREA_IE_Pos) & EFLASH_FLASH_INTR_EN_AHB_W_LOCK_AREA_IE_Msk) /*!< AHB_W_LOCK_AREA_IE Set Value            */
#define EFLASH_FLASH_INTR_EN_AHB_W_LOCK_AREA_IE_Get(x) (((uint32_t) (x) & EFLASH_FLASH_INTR_EN_AHB_W_LOCK_AREA_IE_Msk) >> EFLASH_FLASH_INTR_EN_AHB_W_LOCK_AREA_IE_Pos) /*!< AHB_W_LOCK_AREA_IE Get Value            */

#define EFLASH_FLASH_INTR_EN_AXI_W_LOCK_AREA_IE_Pos    (4U)                                                                                  /*!< AXI_W_LOCK_AREA_IE Position  4          */ 
#define EFLASH_FLASH_INTR_EN_AXI_W_LOCK_AREA_IE_Msk    (0x1U << EFLASH_FLASH_INTR_EN_AXI_W_LOCK_AREA_IE_Pos)                                 /*!< AXI_W_LOCK_AREA_IE Mask      0x00000010 */
#define EFLASH_FLASH_INTR_EN_AXI_W_LOCK_AREA_IE_Set(x) (((uint32_t) (x) << EFLASH_FLASH_INTR_EN_AXI_W_LOCK_AREA_IE_Pos) & EFLASH_FLASH_INTR_EN_AXI_W_LOCK_AREA_IE_Msk) /*!< AXI_W_LOCK_AREA_IE Set Value            */
#define EFLASH_FLASH_INTR_EN_AXI_W_LOCK_AREA_IE_Get(x) (((uint32_t) (x) & EFLASH_FLASH_INTR_EN_AXI_W_LOCK_AREA_IE_Msk) >> EFLASH_FLASH_INTR_EN_AXI_W_LOCK_AREA_IE_Pos) /*!< AXI_W_LOCK_AREA_IE Get Value            */

#define EFLASH_FLASH_INTR_EN_AXI_WERR_IE_Pos    (3U)                                                                                  /*!< AXI_WERR_IE Position  3          */ 
#define EFLASH_FLASH_INTR_EN_AXI_WERR_IE_Msk    (0x1U << EFLASH_FLASH_INTR_EN_AXI_WERR_IE_Pos)                                        /*!< AXI_WERR_IE Mask      0x00000008 */
#define EFLASH_FLASH_INTR_EN_AXI_WERR_IE_Set(x) (((uint32_t) (x) << EFLASH_FLASH_INTR_EN_AXI_WERR_IE_Pos) & EFLASH_FLASH_INTR_EN_AXI_WERR_IE_Msk) /*!< AXI_WERR_IE Set Value            */
#define EFLASH_FLASH_INTR_EN_AXI_WERR_IE_Get(x) (((uint32_t) (x) & EFLASH_FLASH_INTR_EN_AXI_WERR_IE_Msk) >> EFLASH_FLASH_INTR_EN_AXI_WERR_IE_Pos) /*!< AXI_WERR_IE Get Value            */

#define EFLASH_FLASH_INTR_EN_F_DONE_IE_Pos    (2U)                                                                                  /*!< F_DONE_IE Position  2          */ 
#define EFLASH_FLASH_INTR_EN_F_DONE_IE_Msk    (0x1U << EFLASH_FLASH_INTR_EN_F_DONE_IE_Pos)                                          /*!< F_DONE_IE Mask      0x00000004 */
#define EFLASH_FLASH_INTR_EN_F_DONE_IE_Set(x) (((uint32_t) (x) << EFLASH_FLASH_INTR_EN_F_DONE_IE_Pos) & EFLASH_FLASH_INTR_EN_F_DONE_IE_Msk) /*!< F_DONE_IE Set Value            */
#define EFLASH_FLASH_INTR_EN_F_DONE_IE_Get(x) (((uint32_t) (x) & EFLASH_FLASH_INTR_EN_F_DONE_IE_Msk) >> EFLASH_FLASH_INTR_EN_F_DONE_IE_Pos) /*!< F_DONE_IE Get Value            */

/* FLASH_INTR_ST bitfield */
#define EFLASH_FLASH_INTR_ST_VREAD_OK_Pos    (6U)                                                                                  /*!< VREAD_OK Position  6          */ 
#define EFLASH_FLASH_INTR_ST_VREAD_OK_Msk    (0x1U << EFLASH_FLASH_INTR_ST_VREAD_OK_Pos)                                           /*!< VREAD_OK Mask      0x00000040 */
#define EFLASH_FLASH_INTR_ST_VREAD_OK_Set(x) (((uint32_t) (x) << EFLASH_FLASH_INTR_ST_VREAD_OK_Pos) & EFLASH_FLASH_INTR_ST_VREAD_OK_Msk) /*!< VREAD_OK Set Value            */
#define EFLASH_FLASH_INTR_ST_VREAD_OK_Get(x) (((uint32_t) (x) & EFLASH_FLASH_INTR_ST_VREAD_OK_Msk) >> EFLASH_FLASH_INTR_ST_VREAD_OK_Pos) /*!< VREAD_OK Get Value            */

#define EFLASH_FLASH_INTR_ST_AHB_W_LOCK_AREA_Pos    (5U)                                                                                  /*!< AHB_W_LOCK_AREA Position  5          */ 
#define EFLASH_FLASH_INTR_ST_AHB_W_LOCK_AREA_Msk    (0x1U << EFLASH_FLASH_INTR_ST_AHB_W_LOCK_AREA_Pos)                                    /*!< AHB_W_LOCK_AREA Mask      0x00000020 */
#define EFLASH_FLASH_INTR_ST_AHB_W_LOCK_AREA_Set(x) (((uint32_t) (x) << EFLASH_FLASH_INTR_ST_AHB_W_LOCK_AREA_Pos) & EFLASH_FLASH_INTR_ST_AHB_W_LOCK_AREA_Msk) /*!< AHB_W_LOCK_AREA Set Value            */
#define EFLASH_FLASH_INTR_ST_AHB_W_LOCK_AREA_Get(x) (((uint32_t) (x) & EFLASH_FLASH_INTR_ST_AHB_W_LOCK_AREA_Msk) >> EFLASH_FLASH_INTR_ST_AHB_W_LOCK_AREA_Pos) /*!< AHB_W_LOCK_AREA Get Value            */

#define EFLASH_FLASH_INTR_ST_AXI_W_LOCK_AREA_Pos    (4U)                                                                                  /*!< AXI_W_LOCK_AREA Position  4          */ 
#define EFLASH_FLASH_INTR_ST_AXI_W_LOCK_AREA_Msk    (0x1U << EFLASH_FLASH_INTR_ST_AXI_W_LOCK_AREA_Pos)                                    /*!< AXI_W_LOCK_AREA Mask      0x00000010 */
#define EFLASH_FLASH_INTR_ST_AXI_W_LOCK_AREA_Set(x) (((uint32_t) (x) << EFLASH_FLASH_INTR_ST_AXI_W_LOCK_AREA_Pos) & EFLASH_FLASH_INTR_ST_AXI_W_LOCK_AREA_Msk) /*!< AXI_W_LOCK_AREA Set Value            */
#define EFLASH_FLASH_INTR_ST_AXI_W_LOCK_AREA_Get(x) (((uint32_t) (x) & EFLASH_FLASH_INTR_ST_AXI_W_LOCK_AREA_Msk) >> EFLASH_FLASH_INTR_ST_AXI_W_LOCK_AREA_Pos) /*!< AXI_W_LOCK_AREA Get Value            */

#define EFLASH_FLASH_INTR_ST_AXI_WERR_Pos    (3U)                                                                                  /*!< AXI_WERR Position  3          */ 
#define EFLASH_FLASH_INTR_ST_AXI_WERR_Msk    (0x1U << EFLASH_FLASH_INTR_ST_AXI_WERR_Pos)                                           /*!< AXI_WERR Mask      0x00000008 */
#define EFLASH_FLASH_INTR_ST_AXI_WERR_Set(x) (((uint32_t) (x) << EFLASH_FLASH_INTR_ST_AXI_WERR_Pos) & EFLASH_FLASH_INTR_ST_AXI_WERR_Msk) /*!< AXI_WERR Set Value            */
#define EFLASH_FLASH_INTR_ST_AXI_WERR_Get(x) (((uint32_t) (x) & EFLASH_FLASH_INTR_ST_AXI_WERR_Msk) >> EFLASH_FLASH_INTR_ST_AXI_WERR_Pos) /*!< AXI_WERR Get Value            */

#define EFLASH_FLASH_INTR_ST_F_DONE_Pos    (2U)                                                                                  /*!< F_DONE Position  2          */ 
#define EFLASH_FLASH_INTR_ST_F_DONE_Msk    (0x1U << EFLASH_FLASH_INTR_ST_F_DONE_Pos)                                             /*!< F_DONE Mask      0x00000004 */
#define EFLASH_FLASH_INTR_ST_F_DONE_Set(x) (((uint32_t) (x) << EFLASH_FLASH_INTR_ST_F_DONE_Pos) & EFLASH_FLASH_INTR_ST_F_DONE_Msk) /*!< F_DONE Set Value            */
#define EFLASH_FLASH_INTR_ST_F_DONE_Get(x) (((uint32_t) (x) & EFLASH_FLASH_INTR_ST_F_DONE_Msk) >> EFLASH_FLASH_INTR_ST_F_DONE_Pos) /*!< F_DONE Get Value            */

/* FLASH_INTR_ST_CLR bitfield */
#define EFLASH_FLASH_INTR_ST_CLR_VREAD_OK_CLR_Pos    (6U)                                                                                  /*!< VREAD_OK_CLR Position  6          */ 
#define EFLASH_FLASH_INTR_ST_CLR_VREAD_OK_CLR_Msk    (0x1U << EFLASH_FLASH_INTR_ST_CLR_VREAD_OK_CLR_Pos)                                   /*!< VREAD_OK_CLR Mask      0x00000040 */
#define EFLASH_FLASH_INTR_ST_CLR_VREAD_OK_CLR_Set(x) (((uint32_t) (x) << EFLASH_FLASH_INTR_ST_CLR_VREAD_OK_CLR_Pos) & EFLASH_FLASH_INTR_ST_CLR_VREAD_OK_CLR_Msk) /*!< VREAD_OK_CLR Set Value            */
#define EFLASH_FLASH_INTR_ST_CLR_VREAD_OK_CLR_Get(x) (((uint32_t) (x) & EFLASH_FLASH_INTR_ST_CLR_VREAD_OK_CLR_Msk) >> EFLASH_FLASH_INTR_ST_CLR_VREAD_OK_CLR_Pos) /*!< VREAD_OK_CLR Get Value            */

#define EFLASH_FLASH_INTR_ST_CLR_AHB_W_LOCK_AREA_CLR_Pos    (5U)                                                                                  /*!< AHB_W_LOCK_AREA_CLR Position  5          */ 
#define EFLASH_FLASH_INTR_ST_CLR_AHB_W_LOCK_AREA_CLR_Msk    (0x1U << EFLASH_FLASH_INTR_ST_CLR_AHB_W_LOCK_AREA_CLR_Pos)                            /*!< AHB_W_LOCK_AREA_CLR Mask      0x00000020 */
#define EFLASH_FLASH_INTR_ST_CLR_AHB_W_LOCK_AREA_CLR_Set(x) (((uint32_t) (x) << EFLASH_FLASH_INTR_ST_CLR_AHB_W_LOCK_AREA_CLR_Pos) & EFLASH_FLASH_INTR_ST_CLR_AHB_W_LOCK_AREA_CLR_Msk) /*!< AHB_W_LOCK_AREA_CLR Set Value            */
#define EFLASH_FLASH_INTR_ST_CLR_AHB_W_LOCK_AREA_CLR_Get(x) (((uint32_t) (x) & EFLASH_FLASH_INTR_ST_CLR_AHB_W_LOCK_AREA_CLR_Msk) >> EFLASH_FLASH_INTR_ST_CLR_AHB_W_LOCK_AREA_CLR_Pos) /*!< AHB_W_LOCK_AREA_CLR Get Value            */

#define EFLASH_FLASH_INTR_ST_CLR_AXI_W_LOCK_AREA_CLR_Pos    (4U)                                                                                  /*!< AXI_W_LOCK_AREA_CLR Position  4          */ 
#define EFLASH_FLASH_INTR_ST_CLR_AXI_W_LOCK_AREA_CLR_Msk    (0x1U << EFLASH_FLASH_INTR_ST_CLR_AXI_W_LOCK_AREA_CLR_Pos)                            /*!< AXI_W_LOCK_AREA_CLR Mask      0x00000010 */
#define EFLASH_FLASH_INTR_ST_CLR_AXI_W_LOCK_AREA_CLR_Set(x) (((uint32_t) (x) << EFLASH_FLASH_INTR_ST_CLR_AXI_W_LOCK_AREA_CLR_Pos) & EFLASH_FLASH_INTR_ST_CLR_AXI_W_LOCK_AREA_CLR_Msk) /*!< AXI_W_LOCK_AREA_CLR Set Value            */
#define EFLASH_FLASH_INTR_ST_CLR_AXI_W_LOCK_AREA_CLR_Get(x) (((uint32_t) (x) & EFLASH_FLASH_INTR_ST_CLR_AXI_W_LOCK_AREA_CLR_Msk) >> EFLASH_FLASH_INTR_ST_CLR_AXI_W_LOCK_AREA_CLR_Pos) /*!< AXI_W_LOCK_AREA_CLR Get Value            */

#define EFLASH_FLASH_INTR_ST_CLR_AXI_WERR_CLR_Pos    (3U)                                                                                  /*!< AXI_WERR_CLR Position  3          */ 
#define EFLASH_FLASH_INTR_ST_CLR_AXI_WERR_CLR_Msk    (0x1U << EFLASH_FLASH_INTR_ST_CLR_AXI_WERR_CLR_Pos)                                   /*!< AXI_WERR_CLR Mask      0x00000008 */
#define EFLASH_FLASH_INTR_ST_CLR_AXI_WERR_CLR_Set(x) (((uint32_t) (x) << EFLASH_FLASH_INTR_ST_CLR_AXI_WERR_CLR_Pos) & EFLASH_FLASH_INTR_ST_CLR_AXI_WERR_CLR_Msk) /*!< AXI_WERR_CLR Set Value            */
#define EFLASH_FLASH_INTR_ST_CLR_AXI_WERR_CLR_Get(x) (((uint32_t) (x) & EFLASH_FLASH_INTR_ST_CLR_AXI_WERR_CLR_Msk) >> EFLASH_FLASH_INTR_ST_CLR_AXI_WERR_CLR_Pos) /*!< AXI_WERR_CLR Get Value            */

#define EFLASH_FLASH_INTR_ST_CLR_F_DONE_CLR_Pos    (2U)                                                                                  /*!< F_DONE_CLR Position  2          */ 
#define EFLASH_FLASH_INTR_ST_CLR_F_DONE_CLR_Msk    (0x1U << EFLASH_FLASH_INTR_ST_CLR_F_DONE_CLR_Pos)                                     /*!< F_DONE_CLR Mask      0x00000004 */
#define EFLASH_FLASH_INTR_ST_CLR_F_DONE_CLR_Set(x) (((uint32_t) (x) << EFLASH_FLASH_INTR_ST_CLR_F_DONE_CLR_Pos) & EFLASH_FLASH_INTR_ST_CLR_F_DONE_CLR_Msk) /*!< F_DONE_CLR Set Value            */
#define EFLASH_FLASH_INTR_ST_CLR_F_DONE_CLR_Get(x) (((uint32_t) (x) & EFLASH_FLASH_INTR_ST_CLR_F_DONE_CLR_Msk) >> EFLASH_FLASH_INTR_ST_CLR_F_DONE_CLR_Pos) /*!< F_DONE_CLR Get Value            */

/* FLASH_ST_CLR bitfield */
#define EFLASH_FLASH_ST_CLR_AXI_WERR_ADDR_CLR_Pos    (10U)                                                                                 /*!< AXI_WERR_ADDR_CLR Position  10         */ 
#define EFLASH_FLASH_ST_CLR_AXI_WERR_ADDR_CLR_Msk    (0x1U << EFLASH_FLASH_ST_CLR_AXI_WERR_ADDR_CLR_Pos)                                   /*!< AXI_WERR_ADDR_CLR Mask      0x00000400 */
#define EFLASH_FLASH_ST_CLR_AXI_WERR_ADDR_CLR_Set(x) (((uint32_t) (x) << EFLASH_FLASH_ST_CLR_AXI_WERR_ADDR_CLR_Pos) & EFLASH_FLASH_ST_CLR_AXI_WERR_ADDR_CLR_Msk) /*!< AXI_WERR_ADDR_CLR Set Value            */
#define EFLASH_FLASH_ST_CLR_AXI_WERR_ADDR_CLR_Get(x) (((uint32_t) (x) & EFLASH_FLASH_ST_CLR_AXI_WERR_ADDR_CLR_Msk) >> EFLASH_FLASH_ST_CLR_AXI_WERR_ADDR_CLR_Pos) /*!< AXI_WERR_ADDR_CLR Get Value            */

#define EFLASH_FLASH_ST_CLR_WRITE_CNT_CLR_Pos    (8U)                                                                                  /*!< WRITE_CNT_CLR Position  8          */ 
#define EFLASH_FLASH_ST_CLR_WRITE_CNT_CLR_Msk    (0x1U << EFLASH_FLASH_ST_CLR_WRITE_CNT_CLR_Pos)                                       /*!< WRITE_CNT_CLR Mask      0x00000100 */
#define EFLASH_FLASH_ST_CLR_WRITE_CNT_CLR_Set(x) (((uint32_t) (x) << EFLASH_FLASH_ST_CLR_WRITE_CNT_CLR_Pos) & EFLASH_FLASH_ST_CLR_WRITE_CNT_CLR_Msk) /*!< WRITE_CNT_CLR Set Value            */
#define EFLASH_FLASH_ST_CLR_WRITE_CNT_CLR_Get(x) (((uint32_t) (x) & EFLASH_FLASH_ST_CLR_WRITE_CNT_CLR_Msk) >> EFLASH_FLASH_ST_CLR_WRITE_CNT_CLR_Pos) /*!< WRITE_CNT_CLR Get Value            */

/* FLASH_FSM bitfield */
#define EFLASH_FLASH_FSM_FLASH_READY_Pos    (8U)                                                                                  /*!< FLASH_READY Position  8          */ 
#define EFLASH_FLASH_FSM_FLASH_READY_Msk    (0x1U << EFLASH_FLASH_FSM_FLASH_READY_Pos)                                            /*!< FLASH_READY Mask      0x00000100 */
#define EFLASH_FLASH_FSM_FLASH_READY_Set(x) (((uint32_t) (x) << EFLASH_FLASH_FSM_FLASH_READY_Pos) & EFLASH_FLASH_FSM_FLASH_READY_Msk) /*!< FLASH_READY Set Value            */
#define EFLASH_FLASH_FSM_FLASH_READY_Get(x) (((uint32_t) (x) & EFLASH_FLASH_FSM_FLASH_READY_Msk) >> EFLASH_FLASH_FSM_FLASH_READY_Pos) /*!< FLASH_READY Get Value            */

#define EFLASH_FLASH_FSM_C_STATE_Pos    (0U)                                                                                  /*!< C_STATE Position  0          */ 
#define EFLASH_FLASH_FSM_C_STATE_Msk    (0xfU << EFLASH_FLASH_FSM_C_STATE_Pos)                                                /*!< C_STATE Mask      0x0000000F */
#define EFLASH_FLASH_FSM_C_STATE_Set(x) (((uint32_t) (x) << EFLASH_FLASH_FSM_C_STATE_Pos) & EFLASH_FLASH_FSM_C_STATE_Msk)     /*!< C_STATE Set Value            */
#define EFLASH_FLASH_FSM_C_STATE_Get(x) (((uint32_t) (x) & EFLASH_FLASH_FSM_C_STATE_Msk) >> EFLASH_FLASH_FSM_C_STATE_Pos)     /*!< C_STATE Get Value            */

/* AXI_WERR_ADDR bitfield */
#define EFLASH_AXI_WERR_ADDR_AXI_WERR_ADDR_Pos    (0U)                                                                                  /*!< AXI_WERR_ADDR Position  0          */ 
#define EFLASH_AXI_WERR_ADDR_AXI_WERR_ADDR_Msk    (0xffffffffU << EFLASH_AXI_WERR_ADDR_AXI_WERR_ADDR_Pos)                               /*!< AXI_WERR_ADDR Mask      0xFFFFFFFF */
#define EFLASH_AXI_WERR_ADDR_AXI_WERR_ADDR_Set(x) (((uint32_t) (x) << EFLASH_AXI_WERR_ADDR_AXI_WERR_ADDR_Pos) & EFLASH_AXI_WERR_ADDR_AXI_WERR_ADDR_Msk) /*!< AXI_WERR_ADDR Set Value            */
#define EFLASH_AXI_WERR_ADDR_AXI_WERR_ADDR_Get(x) (((uint32_t) (x) & EFLASH_AXI_WERR_ADDR_AXI_WERR_ADDR_Msk) >> EFLASH_AXI_WERR_ADDR_AXI_WERR_ADDR_Pos) /*!< AXI_WERR_ADDR Get Value            */

/* PROTECT_EN bitfield */
#define EFLASH_PROTECT_EN_LOCK_EN_Pos    (0U)                                                                                  /*!< LOCK_EN Position  0          */ 
#define EFLASH_PROTECT_EN_LOCK_EN_Msk    (0x1U << EFLASH_PROTECT_EN_LOCK_EN_Pos)                                               /*!< LOCK_EN Mask      0x00000001 */
#define EFLASH_PROTECT_EN_LOCK_EN_Set(x) (((uint32_t) (x) << EFLASH_PROTECT_EN_LOCK_EN_Pos) & EFLASH_PROTECT_EN_LOCK_EN_Msk)   /*!< LOCK_EN Set Value            */
#define EFLASH_PROTECT_EN_LOCK_EN_Get(x) (((uint32_t) (x) & EFLASH_PROTECT_EN_LOCK_EN_Msk) >> EFLASH_PROTECT_EN_LOCK_EN_Pos)   /*!< LOCK_EN Get Value            */

/* WRITE_CNT bitfield */
#define EFLASH_WRITE_CNT_WRITE_CNT_Pos    (0U)                                                                                  /*!< WRITE_CNT Position  0          */ 
#define EFLASH_WRITE_CNT_WRITE_CNT_Msk    (0xffffffffU << EFLASH_WRITE_CNT_WRITE_CNT_Pos)                                       /*!< WRITE_CNT Mask      0xFFFFFFFF */
#define EFLASH_WRITE_CNT_WRITE_CNT_Set(x) (((uint32_t) (x) << EFLASH_WRITE_CNT_WRITE_CNT_Pos) & EFLASH_WRITE_CNT_WRITE_CNT_Msk) /*!< WRITE_CNT Set Value            */
#define EFLASH_WRITE_CNT_WRITE_CNT_Get(x) (((uint32_t) (x) & EFLASH_WRITE_CNT_WRITE_CNT_Msk) >> EFLASH_WRITE_CNT_WRITE_CNT_Pos) /*!< WRITE_CNT Get Value            */

/* CFIFO_DBG_H bitfield */
#define EFLASH_CFIFO_DBG_H_CFIFO_DBG_H_Pos    (0U)                                                                                  /*!< CFIFO_DBG_H Position  0          */ 
#define EFLASH_CFIFO_DBG_H_CFIFO_DBG_H_Msk    (0xffffffffU << EFLASH_CFIFO_DBG_H_CFIFO_DBG_H_Pos)                                   /*!< CFIFO_DBG_H Mask      0xFFFFFFFF */
#define EFLASH_CFIFO_DBG_H_CFIFO_DBG_H_Set(x) (((uint32_t) (x) << EFLASH_CFIFO_DBG_H_CFIFO_DBG_H_Pos) & EFLASH_CFIFO_DBG_H_CFIFO_DBG_H_Msk) /*!< CFIFO_DBG_H Set Value            */
#define EFLASH_CFIFO_DBG_H_CFIFO_DBG_H_Get(x) (((uint32_t) (x) & EFLASH_CFIFO_DBG_H_CFIFO_DBG_H_Msk) >> EFLASH_CFIFO_DBG_H_CFIFO_DBG_H_Pos) /*!< CFIFO_DBG_H Get Value            */

/* CFIFO_DUG2_L bitfield */
#define EFLASH_CFIFO_DUG2_L_CFIFO_DBG_L_Pos    (0U)                                                                                  /*!< CFIFO_DBG_L Position  0          */ 
#define EFLASH_CFIFO_DUG2_L_CFIFO_DBG_L_Msk    (0xffffffffU << EFLASH_CFIFO_DUG2_L_CFIFO_DBG_L_Pos)                                  /*!< CFIFO_DBG_L Mask      0xFFFFFFFF */
#define EFLASH_CFIFO_DUG2_L_CFIFO_DBG_L_Set(x) (((uint32_t) (x) << EFLASH_CFIFO_DUG2_L_CFIFO_DBG_L_Pos) & EFLASH_CFIFO_DUG2_L_CFIFO_DBG_L_Msk) /*!< CFIFO_DBG_L Set Value            */
#define EFLASH_CFIFO_DUG2_L_CFIFO_DBG_L_Get(x) (((uint32_t) (x) & EFLASH_CFIFO_DUG2_L_CFIFO_DBG_L_Msk) >> EFLASH_CFIFO_DUG2_L_CFIFO_DBG_L_Pos) /*!< CFIFO_DBG_L Get Value            */

/* CFG_VALUE0 bitfield */
#define EFLASH_CFG_VALUE0_CBD0_Pos    (0U)                                                                                  /*!< CBD0 Position  0          */ 
#define EFLASH_CFG_VALUE0_CBD0_Msk    (0xffffU << EFLASH_CFG_VALUE0_CBD0_Pos)                                               /*!< CBD0 Mask      0x0000FFFF */
#define EFLASH_CFG_VALUE0_CBD0_Set(x) (((uint32_t) (x) << EFLASH_CFG_VALUE0_CBD0_Pos) & EFLASH_CFG_VALUE0_CBD0_Msk)         /*!< CBD0 Set Value            */
#define EFLASH_CFG_VALUE0_CBD0_Get(x) (((uint32_t) (x) & EFLASH_CFG_VALUE0_CBD0_Msk) >> EFLASH_CFG_VALUE0_CBD0_Pos)         /*!< CBD0 Get Value            */

/* CFG_VALUE1 bitfield */
#define EFLASH_CFG_VALUE1_CBD1_Pos    (0U)                                                                                  /*!< CBD1 Position  0          */ 
#define EFLASH_CFG_VALUE1_CBD1_Msk    (0xffffU << EFLASH_CFG_VALUE1_CBD1_Pos)                                               /*!< CBD1 Mask      0x0000FFFF */
#define EFLASH_CFG_VALUE1_CBD1_Set(x) (((uint32_t) (x) << EFLASH_CFG_VALUE1_CBD1_Pos) & EFLASH_CFG_VALUE1_CBD1_Msk)         /*!< CBD1 Set Value            */
#define EFLASH_CFG_VALUE1_CBD1_Get(x) (((uint32_t) (x) & EFLASH_CFG_VALUE1_CBD1_Msk) >> EFLASH_CFG_VALUE1_CBD1_Pos)         /*!< CBD1 Get Value            */

/* CFG_VALUE2 bitfield */
#define EFLASH_CFG_VALUE2_CBD2_Pos    (0U)                                                                                  /*!< CBD2 Position  0          */ 
#define EFLASH_CFG_VALUE2_CBD2_Msk    (0xffffU << EFLASH_CFG_VALUE2_CBD2_Pos)                                               /*!< CBD2 Mask      0x0000FFFF */
#define EFLASH_CFG_VALUE2_CBD2_Set(x) (((uint32_t) (x) << EFLASH_CFG_VALUE2_CBD2_Pos) & EFLASH_CFG_VALUE2_CBD2_Msk)         /*!< CBD2 Set Value            */
#define EFLASH_CFG_VALUE2_CBD2_Get(x) (((uint32_t) (x) & EFLASH_CFG_VALUE2_CBD2_Msk) >> EFLASH_CFG_VALUE2_CBD2_Pos)         /*!< CBD2 Get Value            */

/* CFG_VALUE3 bitfield */
#define EFLASH_CFG_VALUE3_CBD3_Pos    (0U)                                                                                  /*!< CBD3 Position  0          */ 
#define EFLASH_CFG_VALUE3_CBD3_Msk    (0xffffU << EFLASH_CFG_VALUE3_CBD3_Pos)                                               /*!< CBD3 Mask      0x0000FFFF */
#define EFLASH_CFG_VALUE3_CBD3_Set(x) (((uint32_t) (x) << EFLASH_CFG_VALUE3_CBD3_Pos) & EFLASH_CFG_VALUE3_CBD3_Msk)         /*!< CBD3 Set Value            */
#define EFLASH_CFG_VALUE3_CBD3_Get(x) (((uint32_t) (x) & EFLASH_CFG_VALUE3_CBD3_Msk) >> EFLASH_CFG_VALUE3_CBD3_Pos)         /*!< CBD3 Get Value            */

/* CFG_VALUE4 bitfield */
#define EFLASH_CFG_VALUE4_CBD4_Pos    (0U)                                                                                  /*!< CBD4 Position  0          */ 
#define EFLASH_CFG_VALUE4_CBD4_Msk    (0xffffU << EFLASH_CFG_VALUE4_CBD4_Pos)                                               /*!< CBD4 Mask      0x0000FFFF */
#define EFLASH_CFG_VALUE4_CBD4_Set(x) (((uint32_t) (x) << EFLASH_CFG_VALUE4_CBD4_Pos) & EFLASH_CFG_VALUE4_CBD4_Msk)         /*!< CBD4 Set Value            */
#define EFLASH_CFG_VALUE4_CBD4_Get(x) (((uint32_t) (x) & EFLASH_CFG_VALUE4_CBD4_Msk) >> EFLASH_CFG_VALUE4_CBD4_Pos)         /*!< CBD4 Get Value            */

/* CFG_VALUE5 bitfield */
#define EFLASH_CFG_VALUE5_CBD5_Pos    (0U)                                                                                  /*!< CBD5 Position  0          */ 
#define EFLASH_CFG_VALUE5_CBD5_Msk    (0xffffU << EFLASH_CFG_VALUE5_CBD5_Pos)                                               /*!< CBD5 Mask      0x0000FFFF */
#define EFLASH_CFG_VALUE5_CBD5_Set(x) (((uint32_t) (x) << EFLASH_CFG_VALUE5_CBD5_Pos) & EFLASH_CFG_VALUE5_CBD5_Msk)         /*!< CBD5 Set Value            */
#define EFLASH_CFG_VALUE5_CBD5_Get(x) (((uint32_t) (x) & EFLASH_CFG_VALUE5_CBD5_Msk) >> EFLASH_CFG_VALUE5_CBD5_Pos)         /*!< CBD5 Get Value            */

/* CFG_VALUE6 bitfield */
#define EFLASH_CFG_VALUE6_CBD6_Pos    (0U)                                                                                  /*!< CBD6 Position  0          */ 
#define EFLASH_CFG_VALUE6_CBD6_Msk    (0xffffU << EFLASH_CFG_VALUE6_CBD6_Pos)                                               /*!< CBD6 Mask      0x0000FFFF */
#define EFLASH_CFG_VALUE6_CBD6_Set(x) (((uint32_t) (x) << EFLASH_CFG_VALUE6_CBD6_Pos) & EFLASH_CFG_VALUE6_CBD6_Msk)         /*!< CBD6 Set Value            */
#define EFLASH_CFG_VALUE6_CBD6_Get(x) (((uint32_t) (x) & EFLASH_CFG_VALUE6_CBD6_Msk) >> EFLASH_CFG_VALUE6_CBD6_Pos)         /*!< CBD6 Get Value            */

/* CFG_VALUE7 bitfield */
#define EFLASH_CFG_VALUE7_CBD7_Pos    (0U)                                                                                  /*!< CBD7 Position  0          */ 
#define EFLASH_CFG_VALUE7_CBD7_Msk    (0xffffU << EFLASH_CFG_VALUE7_CBD7_Pos)                                               /*!< CBD7 Mask      0x0000FFFF */
#define EFLASH_CFG_VALUE7_CBD7_Set(x) (((uint32_t) (x) << EFLASH_CFG_VALUE7_CBD7_Pos) & EFLASH_CFG_VALUE7_CBD7_Msk)         /*!< CBD7 Set Value            */
#define EFLASH_CFG_VALUE7_CBD7_Get(x) (((uint32_t) (x) & EFLASH_CFG_VALUE7_CBD7_Msk) >> EFLASH_CFG_VALUE7_CBD7_Pos)         /*!< CBD7 Get Value            */

/* USR4_VALUE bitfield */
#define EFLASH_USR4_VALUE_USR4_Pos    (0U)                                                                                  /*!< USR4 Position  0          */ 
#define EFLASH_USR4_VALUE_USR4_Msk    (0xffffffffU << EFLASH_USR4_VALUE_USR4_Pos)                                           /*!< USR4 Mask      0xFFFFFFFF */
#define EFLASH_USR4_VALUE_USR4_Set(x) (((uint32_t) (x) << EFLASH_USR4_VALUE_USR4_Pos) & EFLASH_USR4_VALUE_USR4_Msk)         /*!< USR4 Set Value            */
#define EFLASH_USR4_VALUE_USR4_Get(x) (((uint32_t) (x) & EFLASH_USR4_VALUE_USR4_Msk) >> EFLASH_USR4_VALUE_USR4_Pos)         /*!< USR4 Get Value            */

/* USR5_VALUE bitfield */
#define EFLASH_USR5_VALUE_USR5_Pos    (0U)                                                                                  /*!< USR5 Position  0          */ 
#define EFLASH_USR5_VALUE_USR5_Msk    (0xffffffffU << EFLASH_USR5_VALUE_USR5_Pos)                                           /*!< USR5 Mask      0xFFFFFFFF */
#define EFLASH_USR5_VALUE_USR5_Set(x) (((uint32_t) (x) << EFLASH_USR5_VALUE_USR5_Pos) & EFLASH_USR5_VALUE_USR5_Msk)         /*!< USR5 Set Value            */
#define EFLASH_USR5_VALUE_USR5_Get(x) (((uint32_t) (x) & EFLASH_USR5_VALUE_USR5_Msk) >> EFLASH_USR5_VALUE_USR5_Pos)         /*!< USR5 Get Value            */

/* RR0_VALUE bitfield */
#define EFLASH_RR0_VALUE_RR0_Pos    (0U)                                                                                  /*!< RR0 Position  0          */ 
#define EFLASH_RR0_VALUE_RR0_Msk    (0xffffffffU << EFLASH_RR0_VALUE_RR0_Pos)                                             /*!< RR0 Mask      0xFFFFFFFF */
#define EFLASH_RR0_VALUE_RR0_Set(x) (((uint32_t) (x) << EFLASH_RR0_VALUE_RR0_Pos) & EFLASH_RR0_VALUE_RR0_Msk)             /*!< RR0 Set Value            */
#define EFLASH_RR0_VALUE_RR0_Get(x) (((uint32_t) (x) & EFLASH_RR0_VALUE_RR0_Msk) >> EFLASH_RR0_VALUE_RR0_Pos)             /*!< RR0 Get Value            */

/* RR1_VALUE bitfield */
#define EFLASH_RR1_VALUE_RR1_Pos    (0U)                                                                                  /*!< RR1 Position  0          */ 
#define EFLASH_RR1_VALUE_RR1_Msk    (0xffffffffU << EFLASH_RR1_VALUE_RR1_Pos)                                             /*!< RR1 Mask      0xFFFFFFFF */
#define EFLASH_RR1_VALUE_RR1_Set(x) (((uint32_t) (x) << EFLASH_RR1_VALUE_RR1_Pos) & EFLASH_RR1_VALUE_RR1_Msk)             /*!< RR1 Set Value            */
#define EFLASH_RR1_VALUE_RR1_Get(x) (((uint32_t) (x) & EFLASH_RR1_VALUE_RR1_Msk) >> EFLASH_RR1_VALUE_RR1_Pos)             /*!< RR1 Get Value            */

/* BIST_REG_SOC bitfield */
#define EFLASH_BIST_REG_SOC_BIST_REG_SOC_Pos    (0U)                                                                                  /*!< BIST_REG_SOC Position  0          */ 
#define EFLASH_BIST_REG_SOC_BIST_REG_SOC_Msk    (0xffffffffU << EFLASH_BIST_REG_SOC_BIST_REG_SOC_Pos)                                 /*!< BIST_REG_SOC Mask      0xFFFFFFFF */
#define EFLASH_BIST_REG_SOC_BIST_REG_SOC_Set(x) (((uint32_t) (x) << EFLASH_BIST_REG_SOC_BIST_REG_SOC_Pos) & EFLASH_BIST_REG_SOC_BIST_REG_SOC_Msk) /*!< BIST_REG_SOC Set Value            */
#define EFLASH_BIST_REG_SOC_BIST_REG_SOC_Get(x) (((uint32_t) (x) & EFLASH_BIST_REG_SOC_BIST_REG_SOC_Msk) >> EFLASH_BIST_REG_SOC_BIST_REG_SOC_Pos) /*!< BIST_REG_SOC Get Value            */

/*!
 * @}
 */

/*!
 * @}
 */ /* end of HS32F7D377_EFLASH_REGISTER */

#endif /* HS32F7D377_EFLASH_H */
