/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


/*!
 * \file   HS32F7D377_wdt.h
 * \brief  HS32F7D377 WDT register file
 * \version V1.0_20230831
 */

#ifndef HS32F7D377_WDT_H
#define HS32F7D377_WDT_H

/*!
 * \addtogroup   HS32F7D377_WDT_REGISTER HS32F7D377 WDT Register
 * \ingroup HS32F7D377_REGISTER
 *
 * \brief  WDT register layout, bitfield and address definitions
 *
 * @{
 */

/*!
 * \name WDT Register Layout
 *
 *
 * @{
 */

/*! \brief WDT register layout */
typedef struct {
    union
    {
        __IOM uint32_t CR                  ;  /*!< 0x00000000 : Control Register */
    
        struct
        {
            __IOM uint32_t WDT_EN                    : 1 ;     /*!< [ 0: 0] : (WDT_ALWAYS_EN == 1) ? "read-only":"read-write" WDT enable. */
            __IOM uint32_t RMOD                      : 1 ;     /*!< [ 1: 1] : (WDT_HC_RMOD == 1) ? "read-only" : "read-write" Writes have no effect when the parameter WDT_HC_RMOD = 1, thus this register becomes read-only. */
            __IOM uint32_t RPL                       : 3 ;     /*!< [ 4: 2] : (WDT_HC_RPL == 1) ? "read-only" : "read-write". */
            __IOM uint32_t NO_NAME                   : 1 ;     /*!< [ 5: 5] : memory access varies. */
                  uint32_t RSV_0                     : 26;     /*!< [31: 6] : reserved. */
        } CRb;
    };

    union
    {
        __IOM uint32_t TORR                ;  /*!< 0x00000004 : Timeout Range Register */
    
        struct
        {
            __IOM uint32_t TOP                       : 4 ;     /*!< [ 3: 0] : (WDT_HC_TOP == 1) ? "read-only" : "read-write". */
            __IOM uint32_t TOP_INIT                  : 4 ;     /*!< [ 7: 4] : (WDT_DUAL_TOP==0 || WDT_HC_TOP==1 || WDT_ALWAYS_EN==1 ) ? "read-only" : "read-write" Timeout period for initialization. */
                  uint32_t RSV_0                     : 24;     /*!< [31: 8] : reserved. */
        } TORRb;
    };

    union
    {
        __IM  uint32_t CCVR                ;  /*!< 0x00000008 : Current Counter Value Register */
    
        struct
        {
            __IM  uint32_t CCVR                      : 32;     /*!< [31: 0] : WDT Current Counter Value Register. */
        } CCVRb;
    };

    union
    {
        __IOM uint32_t CRR                 ;  /*!< 0x0000000c : Counter Restart Register */
    
        struct
        {
            __OM  uint32_t CRR                       : 8 ;     /*!< [ 7: 0] : Counter Restart Register. */
                  uint32_t RSV_0                     : 24;     /*!< [31: 8] : reserved. */
        } CRRb;
    };

    union
    {
        __IM  uint32_t STAT                ;  /*!< 0x00000010 : Interrupt Status Register */
    
        struct
        {
            __IM  uint32_t STAT                      : 1 ;     /*!< [ 0: 0] : interrupt status of the WDT. */
                  uint32_t RSV_0                     : 31;     /*!< [31: 1] : reserved. */
        } STATb;
    };

    union
    {
        __IM  uint32_t EOI                 ;  /*!< 0x00000014 : Interrupt Clear Register */
    
        struct
        {
            __IM  uint32_t EOI                       : 1 ;     /*!< [ 0: 0] : Interrupt Clear Register. */
                  uint32_t RSV_0                     : 31;     /*!< [31: 1] : reserved. */
        } EOIb;
    };

    uint8_t    RSV_0X18[4];   /*!< 0x00000018~0x0000001b : reserved */

    union
    {
        __IOM uint32_t PROT_LEVEL          ;  /*!< 0x0000001c : WDT Protection level register */
    
        struct
        {
            __IOM uint32_t PROT_LEVEL                : 3 ;     /*!< [ 2: 0] : Protection level register Memory Access: (HC_PROT_LEVEL == 1) ? "read-only" : "read-write". */
                  uint32_t RSV_0                     : 29;     /*!< [31: 3] : reserved. */
        } PROT_LEVELb;
    };

    uint8_t    RSV_0X20[196];   /*!< 0x00000020~0x000000e3 : reserved */

    union
    {
        __IM  uint32_t COMP_PARAM_5        ;  /*!< 0x000000e4 : Component Parameters Register 5 */
    
        struct
        {
            __IM  uint32_t CP_WDT_USER_TOP_MAX       : 32;     /*!< [31: 0] : Upper limit of Timeout Period parameters. */
        } COMP_PARAM_5b;
    };

    union
    {
        __IM  uint32_t COMP_PARAM_4        ;  /*!< 0x000000e8 : Component Parameters Register 4 */
    
        struct
        {
            __IM  uint32_t CP_WDT_USER_TOP_INIT_MAX  : 32;     /*!< [31: 0] : Upper limit of Initial Timeout Period parameters. */
        } COMP_PARAM_4b;
    };

    union
    {
        __IM  uint32_t COMP_PARAM_3        ;  /*!< 0x000000ec : Component Parameters Register 3 */
    
        struct
        {
            __IM  uint32_t CD_WDT_TOP_RST            : 32;     /*!< [31: 0] : The value of this register is derived from the WDT_TOP_RST coreConsultant parameter. */
        } COMP_PARAM_3b;
    };

    union
    {
        __IM  uint32_t COMP_PARAM_2        ;  /*!< 0x000000f0 : Component Parameters Register 2 */
    
        struct
        {
            __IM  uint32_t CP_WDT_CNT_RST            : 32;     /*!< [31: 0] : The value of this register is derived from the WDT_RST_CNT coreConsultant parameter. */
        } COMP_PARAM_2b;
    };

    union
    {
        __IM  uint32_t COMP_PARAM_1        ;  /*!< 0x000000f4 : Component Parameters Register 1 */
    
        struct
        {
            __IM  uint32_t ALWAYS_EN                 : 1 ;     /*!< [ 0: 0] : Configures the WDT to be enabled from reset. */
            __IM  uint32_t DFLT_RMOD                 : 1 ;     /*!< [ 1: 1] : Describes the output response mode that is available directly after reset. */
            __IM  uint32_t DUAL_TOP                  : 1 ;     /*!< [ 2: 2] : When set to 1, includes a second timeout period that is used for initialization prior to the first kick. */
            __IM  uint32_t HC_RMOD                   : 1 ;     /*!< [ 3: 3] : Configures the output response mode to be hard coded. */
            __IM  uint32_t HC_RPL                    : 1 ;     /*!< [ 4: 4] : Configures the reset pulse length to be hard coded. */
            __IM  uint32_t HC_TOP                    : 1 ;     /*!< [ 5: 5] : When set to 1, the selected timeout periods is set to be hard coded. */
            __IM  uint32_t USE_FIX_TOP               : 1 ;     /*!< [ 6: 6] : When this parameter is set to 1, timeout period range is fixed. */
            __IM  uint32_t PAUSE                     : 1 ;     /*!< [ 7: 7] : Configures the peripheral to have a pause enable signal (pause) on the interface that can be used to freeze the watchdog counter during pause mode. */
            __IM  uint32_t APB_DATA_WIDTH            : 2 ;     /*!< [ 9: 8] : Width of the APB Data Bus to which this component is attached. */
            __IM  uint32_t DFLT_RPL                  : 3 ;     /*!< [12:10] : The reset pulse length that is available directly after reset. */
                  uint32_t RSV_1                     : 3 ;     /*!< [15:13] : reserved. */
            __IM  uint32_t DFLT_TOP                  : 4 ;     /*!< [19:16] : Selects the timeout period that is available directly after reset. */
            __IM  uint32_t DFLT_TOP_INIT             : 4 ;     /*!< [23:20] : Describes the initial timeout period that is available directly after reset. */
            __IM  uint32_t CNT_WIDTH                 : 5 ;     /*!< [28:24] : The Watchdog Timer counter width. */
                  uint32_t RSV_0                     : 3 ;     /*!< [31:29] : reserved. */
        } COMP_PARAM_1b;
    };

    union
    {
        __IM  uint32_t COMP_VERSION        ;  /*!< 0x000000f8 : Component Version Register */
    
        struct
        {
            __IM  uint32_t COMP_VERSION              : 32;     /*!< [31: 0] : ASCII value for each number in the version, followed by *. */
        } COMP_VERSIONb;
    };

    union
    {
        __IM  uint32_t COMP_TYPE           ;  /*!< 0x000000fc : Component Type Register */
    
        struct
        {
            __IM  uint32_t COMP_TYPE                 : 32;     /*!< [31: 0] : Designware Component Type number = 0x44_57_01_20. */
        } COMP_TYPEb;
    };

} WDT_Type;

/*!
 * @}
 */


/*!
 * \name WDT Base Address Definitions
 *
 * @{
 */

/*! \brief WDT base address */
#define WDT_BASE (0x41011000UL)
/*! \brief WDT base pointer */
#define WDT ((WDT_Type *) WDT_BASE)

/*!
 * @}
 */


/*!
 * \name WDT Register Bitfield Definitions
 *
 * @{
 */

/* CR bitfield */
#define WDT_CR_NO_NAME_Pos    (5U)                                                                                  /*!< NO_NAME Position  5          */ 
#define WDT_CR_NO_NAME_Msk    (0x1U << WDT_CR_NO_NAME_Pos)                                                          /*!< NO_NAME Mask      0x00000020 */
#define WDT_CR_NO_NAME_Set(x) (((uint32_t) (x) << WDT_CR_NO_NAME_Pos) & WDT_CR_NO_NAME_Msk)                         /*!< NO_NAME Set Value            */
#define WDT_CR_NO_NAME_Get(x) (((uint32_t) (x) & WDT_CR_NO_NAME_Msk) >> WDT_CR_NO_NAME_Pos)                         /*!< NO_NAME Get Value            */

#define WDT_CR_RPL_Pos    (2U)                                                                                  /*!< RPL Position  2          */ 
#define WDT_CR_RPL_Msk    (0x7U << WDT_CR_RPL_Pos)                                                              /*!< RPL Mask      0x0000001C */
#define WDT_CR_RPL_Set(x) (((uint32_t) (x) << WDT_CR_RPL_Pos) & WDT_CR_RPL_Msk)                                 /*!< RPL Set Value            */
#define WDT_CR_RPL_Get(x) (((uint32_t) (x) & WDT_CR_RPL_Msk) >> WDT_CR_RPL_Pos)                                 /*!< RPL Get Value            */

#define WDT_CR_RMOD_Pos    (1U)                                                                                  /*!< RMOD Position  1          */ 
#define WDT_CR_RMOD_Msk    (0x1U << WDT_CR_RMOD_Pos)                                                             /*!< RMOD Mask      0x00000002 */
#define WDT_CR_RMOD_Set(x) (((uint32_t) (x) << WDT_CR_RMOD_Pos) & WDT_CR_RMOD_Msk)                               /*!< RMOD Set Value            */
#define WDT_CR_RMOD_Get(x) (((uint32_t) (x) & WDT_CR_RMOD_Msk) >> WDT_CR_RMOD_Pos)                               /*!< RMOD Get Value            */

#define WDT_CR_WDT_EN_Pos    (0U)                                                                                  /*!< WDT_EN Position  0          */ 
#define WDT_CR_WDT_EN_Msk    (0x1U << WDT_CR_WDT_EN_Pos)                                                           /*!< WDT_EN Mask      0x00000001 */
#define WDT_CR_WDT_EN_Set(x) (((uint32_t) (x) << WDT_CR_WDT_EN_Pos) & WDT_CR_WDT_EN_Msk)                           /*!< WDT_EN Set Value            */
#define WDT_CR_WDT_EN_Get(x) (((uint32_t) (x) & WDT_CR_WDT_EN_Msk) >> WDT_CR_WDT_EN_Pos)                           /*!< WDT_EN Get Value            */

/* TORR bitfield */
#define WDT_TORR_TOP_INIT_Pos    (4U)                                                                                  /*!< TOP_INIT Position  4          */ 
#define WDT_TORR_TOP_INIT_Msk    (0xfU << WDT_TORR_TOP_INIT_Pos)                                                       /*!< TOP_INIT Mask      0x000000F0 */
#define WDT_TORR_TOP_INIT_Set(x) (((uint32_t) (x) << WDT_TORR_TOP_INIT_Pos) & WDT_TORR_TOP_INIT_Msk)                   /*!< TOP_INIT Set Value            */
#define WDT_TORR_TOP_INIT_Get(x) (((uint32_t) (x) & WDT_TORR_TOP_INIT_Msk) >> WDT_TORR_TOP_INIT_Pos)                   /*!< TOP_INIT Get Value            */

#define WDT_TORR_TOP_Pos    (0U)                                                                                  /*!< TOP Position  0          */ 
#define WDT_TORR_TOP_Msk    (0xfU << WDT_TORR_TOP_Pos)                                                            /*!< TOP Mask      0x0000000F */
#define WDT_TORR_TOP_Set(x) (((uint32_t) (x) << WDT_TORR_TOP_Pos) & WDT_TORR_TOP_Msk)                             /*!< TOP Set Value            */
#define WDT_TORR_TOP_Get(x) (((uint32_t) (x) & WDT_TORR_TOP_Msk) >> WDT_TORR_TOP_Pos)                             /*!< TOP Get Value            */

/* CCVR bitfield */
#define WDT_CCVR_CCVR_Pos    (0U)                                                                                  /*!< CCVR Position  0          */ 
#define WDT_CCVR_CCVR_Msk    (0xffffffffU << WDT_CCVR_CCVR_Pos)                                                    /*!< CCVR Mask      0xFFFFFFFF */
#define WDT_CCVR_CCVR_Set(x) (((uint32_t) (x) << WDT_CCVR_CCVR_Pos) & WDT_CCVR_CCVR_Msk)                           /*!< CCVR Set Value            */
#define WDT_CCVR_CCVR_Get(x) (((uint32_t) (x) & WDT_CCVR_CCVR_Msk) >> WDT_CCVR_CCVR_Pos)                           /*!< CCVR Get Value            */

/* CRR bitfield */
#define WDT_CRR_CRR_Pos    (0U)                                                                                  /*!< CRR Position  0          */ 
#define WDT_CRR_CRR_Msk    (0xffU << WDT_CRR_CRR_Pos)                                                            /*!< CRR Mask      0x000000FF */
#define WDT_CRR_CRR_Set(x) (((uint32_t) (x) << WDT_CRR_CRR_Pos) & WDT_CRR_CRR_Msk)                               /*!< CRR Set Value            */
#define WDT_CRR_CRR_Get(x) (((uint32_t) (x) & WDT_CRR_CRR_Msk) >> WDT_CRR_CRR_Pos)                               /*!< CRR Get Value            */

/* STAT bitfield */
#define WDT_STAT_STAT_Pos    (0U)                                                                                  /*!< STAT Position  0          */ 
#define WDT_STAT_STAT_Msk    (0x1U << WDT_STAT_STAT_Pos)                                                           /*!< STAT Mask      0x00000001 */
#define WDT_STAT_STAT_Set(x) (((uint32_t) (x) << WDT_STAT_STAT_Pos) & WDT_STAT_STAT_Msk)                           /*!< STAT Set Value            */
#define WDT_STAT_STAT_Get(x) (((uint32_t) (x) & WDT_STAT_STAT_Msk) >> WDT_STAT_STAT_Pos)                           /*!< STAT Get Value            */

/* EOI bitfield */
#define WDT_EOI_EOI_Pos    (0U)                                                                                  /*!< EOI Position  0          */ 
#define WDT_EOI_EOI_Msk    (0x1U << WDT_EOI_EOI_Pos)                                                             /*!< EOI Mask      0x00000001 */
#define WDT_EOI_EOI_Set(x) (((uint32_t) (x) << WDT_EOI_EOI_Pos) & WDT_EOI_EOI_Msk)                               /*!< EOI Set Value            */
#define WDT_EOI_EOI_Get(x) (((uint32_t) (x) & WDT_EOI_EOI_Msk) >> WDT_EOI_EOI_Pos)                               /*!< EOI Get Value            */

/* PROT_LEVEL bitfield */
#define WDT_PROT_LEVEL_PROT_LEVEL_Pos    (0U)                                                                                  /*!< PROT_LEVEL Position  0          */ 
#define WDT_PROT_LEVEL_PROT_LEVEL_Msk    (0x7U << WDT_PROT_LEVEL_PROT_LEVEL_Pos)                                               /*!< PROT_LEVEL Mask      0x00000007 */
#define WDT_PROT_LEVEL_PROT_LEVEL_Set(x) (((uint32_t) (x) << WDT_PROT_LEVEL_PROT_LEVEL_Pos) & WDT_PROT_LEVEL_PROT_LEVEL_Msk)   /*!< PROT_LEVEL Set Value            */
#define WDT_PROT_LEVEL_PROT_LEVEL_Get(x) (((uint32_t) (x) & WDT_PROT_LEVEL_PROT_LEVEL_Msk) >> WDT_PROT_LEVEL_PROT_LEVEL_Pos)   /*!< PROT_LEVEL Get Value            */

/* COMP_PARAM_5 bitfield */
#define WDT_COMP_PARAM_5_CP_WDT_USER_TOP_MAX_Pos    (0U)                                                                                  /*!< CP_WDT_USER_TOP_MAX Position  0          */ 
#define WDT_COMP_PARAM_5_CP_WDT_USER_TOP_MAX_Msk    (0xffffffffU << WDT_COMP_PARAM_5_CP_WDT_USER_TOP_MAX_Pos)                             /*!< CP_WDT_USER_TOP_MAX Mask      0xFFFFFFFF */
#define WDT_COMP_PARAM_5_CP_WDT_USER_TOP_MAX_Set(x) (((uint32_t) (x) << WDT_COMP_PARAM_5_CP_WDT_USER_TOP_MAX_Pos) & WDT_COMP_PARAM_5_CP_WDT_USER_TOP_MAX_Msk) /*!< CP_WDT_USER_TOP_MAX Set Value            */
#define WDT_COMP_PARAM_5_CP_WDT_USER_TOP_MAX_Get(x) (((uint32_t) (x) & WDT_COMP_PARAM_5_CP_WDT_USER_TOP_MAX_Msk) >> WDT_COMP_PARAM_5_CP_WDT_USER_TOP_MAX_Pos) /*!< CP_WDT_USER_TOP_MAX Get Value            */

/* COMP_PARAM_4 bitfield */
#define WDT_COMP_PARAM_4_CP_WDT_USER_TOP_INIT_MAX_Pos    (0U)                                                                                  /*!< CP_WDT_USER_TOP_INIT_MAX Position  0          */ 
#define WDT_COMP_PARAM_4_CP_WDT_USER_TOP_INIT_MAX_Msk    (0xffffffffU << WDT_COMP_PARAM_4_CP_WDT_USER_TOP_INIT_MAX_Pos)                        /*!< CP_WDT_USER_TOP_INIT_MAX Mask      0xFFFFFFFF */
#define WDT_COMP_PARAM_4_CP_WDT_USER_TOP_INIT_MAX_Set(x) (((uint32_t) (x) << WDT_COMP_PARAM_4_CP_WDT_USER_TOP_INIT_MAX_Pos) & WDT_COMP_PARAM_4_CP_WDT_USER_TOP_INIT_MAX_Msk) /*!< CP_WDT_USER_TOP_INIT_MAX Set Value            */
#define WDT_COMP_PARAM_4_CP_WDT_USER_TOP_INIT_MAX_Get(x) (((uint32_t) (x) & WDT_COMP_PARAM_4_CP_WDT_USER_TOP_INIT_MAX_Msk) >> WDT_COMP_PARAM_4_CP_WDT_USER_TOP_INIT_MAX_Pos) /*!< CP_WDT_USER_TOP_INIT_MAX Get Value            */

/* COMP_PARAM_3 bitfield */
#define WDT_COMP_PARAM_3_CD_WDT_TOP_RST_Pos    (0U)                                                                                  /*!< CD_WDT_TOP_RST Position  0          */ 
#define WDT_COMP_PARAM_3_CD_WDT_TOP_RST_Msk    (0xffffffffU << WDT_COMP_PARAM_3_CD_WDT_TOP_RST_Pos)                                  /*!< CD_WDT_TOP_RST Mask      0xFFFFFFFF */
#define WDT_COMP_PARAM_3_CD_WDT_TOP_RST_Set(x) (((uint32_t) (x) << WDT_COMP_PARAM_3_CD_WDT_TOP_RST_Pos) & WDT_COMP_PARAM_3_CD_WDT_TOP_RST_Msk) /*!< CD_WDT_TOP_RST Set Value            */
#define WDT_COMP_PARAM_3_CD_WDT_TOP_RST_Get(x) (((uint32_t) (x) & WDT_COMP_PARAM_3_CD_WDT_TOP_RST_Msk) >> WDT_COMP_PARAM_3_CD_WDT_TOP_RST_Pos) /*!< CD_WDT_TOP_RST Get Value            */

/* COMP_PARAM_2 bitfield */
#define WDT_COMP_PARAM_2_CP_WDT_CNT_RST_Pos    (0U)                                                                                  /*!< CP_WDT_CNT_RST Position  0          */ 
#define WDT_COMP_PARAM_2_CP_WDT_CNT_RST_Msk    (0xffffffffU << WDT_COMP_PARAM_2_CP_WDT_CNT_RST_Pos)                                  /*!< CP_WDT_CNT_RST Mask      0xFFFFFFFF */
#define WDT_COMP_PARAM_2_CP_WDT_CNT_RST_Set(x) (((uint32_t) (x) << WDT_COMP_PARAM_2_CP_WDT_CNT_RST_Pos) & WDT_COMP_PARAM_2_CP_WDT_CNT_RST_Msk) /*!< CP_WDT_CNT_RST Set Value            */
#define WDT_COMP_PARAM_2_CP_WDT_CNT_RST_Get(x) (((uint32_t) (x) & WDT_COMP_PARAM_2_CP_WDT_CNT_RST_Msk) >> WDT_COMP_PARAM_2_CP_WDT_CNT_RST_Pos) /*!< CP_WDT_CNT_RST Get Value            */

/* COMP_PARAM_1 bitfield */
#define WDT_COMP_PARAM_1_CNT_WIDTH_Pos    (24U)                                                                                 /*!< CNT_WIDTH Position  24         */ 
#define WDT_COMP_PARAM_1_CNT_WIDTH_Msk    (0x1fU << WDT_COMP_PARAM_1_CNT_WIDTH_Pos)                                             /*!< CNT_WIDTH Mask      0x1F000000 */
#define WDT_COMP_PARAM_1_CNT_WIDTH_Set(x) (((uint32_t) (x) << WDT_COMP_PARAM_1_CNT_WIDTH_Pos) & WDT_COMP_PARAM_1_CNT_WIDTH_Msk) /*!< CNT_WIDTH Set Value            */
#define WDT_COMP_PARAM_1_CNT_WIDTH_Get(x) (((uint32_t) (x) & WDT_COMP_PARAM_1_CNT_WIDTH_Msk) >> WDT_COMP_PARAM_1_CNT_WIDTH_Pos) /*!< CNT_WIDTH Get Value            */

#define WDT_COMP_PARAM_1_DFLT_TOP_INIT_Pos    (20U)                                                                                 /*!< DFLT_TOP_INIT Position  20         */ 
#define WDT_COMP_PARAM_1_DFLT_TOP_INIT_Msk    (0xfU << WDT_COMP_PARAM_1_DFLT_TOP_INIT_Pos)                                          /*!< DFLT_TOP_INIT Mask      0x00F00000 */
#define WDT_COMP_PARAM_1_DFLT_TOP_INIT_Set(x) (((uint32_t) (x) << WDT_COMP_PARAM_1_DFLT_TOP_INIT_Pos) & WDT_COMP_PARAM_1_DFLT_TOP_INIT_Msk) /*!< DFLT_TOP_INIT Set Value            */
#define WDT_COMP_PARAM_1_DFLT_TOP_INIT_Get(x) (((uint32_t) (x) & WDT_COMP_PARAM_1_DFLT_TOP_INIT_Msk) >> WDT_COMP_PARAM_1_DFLT_TOP_INIT_Pos) /*!< DFLT_TOP_INIT Get Value            */

#define WDT_COMP_PARAM_1_DFLT_TOP_Pos    (16U)                                                                                 /*!< DFLT_TOP Position  16         */ 
#define WDT_COMP_PARAM_1_DFLT_TOP_Msk    (0xfU << WDT_COMP_PARAM_1_DFLT_TOP_Pos)                                               /*!< DFLT_TOP Mask      0x000F0000 */
#define WDT_COMP_PARAM_1_DFLT_TOP_Set(x) (((uint32_t) (x) << WDT_COMP_PARAM_1_DFLT_TOP_Pos) & WDT_COMP_PARAM_1_DFLT_TOP_Msk)   /*!< DFLT_TOP Set Value            */
#define WDT_COMP_PARAM_1_DFLT_TOP_Get(x) (((uint32_t) (x) & WDT_COMP_PARAM_1_DFLT_TOP_Msk) >> WDT_COMP_PARAM_1_DFLT_TOP_Pos)   /*!< DFLT_TOP Get Value            */

#define WDT_COMP_PARAM_1_DFLT_RPL_Pos    (10U)                                                                                 /*!< DFLT_RPL Position  10         */ 
#define WDT_COMP_PARAM_1_DFLT_RPL_Msk    (0x7U << WDT_COMP_PARAM_1_DFLT_RPL_Pos)                                               /*!< DFLT_RPL Mask      0x00001C00 */
#define WDT_COMP_PARAM_1_DFLT_RPL_Set(x) (((uint32_t) (x) << WDT_COMP_PARAM_1_DFLT_RPL_Pos) & WDT_COMP_PARAM_1_DFLT_RPL_Msk)   /*!< DFLT_RPL Set Value            */
#define WDT_COMP_PARAM_1_DFLT_RPL_Get(x) (((uint32_t) (x) & WDT_COMP_PARAM_1_DFLT_RPL_Msk) >> WDT_COMP_PARAM_1_DFLT_RPL_Pos)   /*!< DFLT_RPL Get Value            */

#define WDT_COMP_PARAM_1_APB_DATA_WIDTH_Pos    (8U)                                                                                  /*!< APB_DATA_WIDTH Position  8          */ 
#define WDT_COMP_PARAM_1_APB_DATA_WIDTH_Msk    (0x3U << WDT_COMP_PARAM_1_APB_DATA_WIDTH_Pos)                                         /*!< APB_DATA_WIDTH Mask      0x00000300 */
#define WDT_COMP_PARAM_1_APB_DATA_WIDTH_Set(x) (((uint32_t) (x) << WDT_COMP_PARAM_1_APB_DATA_WIDTH_Pos) & WDT_COMP_PARAM_1_APB_DATA_WIDTH_Msk) /*!< APB_DATA_WIDTH Set Value            */
#define WDT_COMP_PARAM_1_APB_DATA_WIDTH_Get(x) (((uint32_t) (x) & WDT_COMP_PARAM_1_APB_DATA_WIDTH_Msk) >> WDT_COMP_PARAM_1_APB_DATA_WIDTH_Pos) /*!< APB_DATA_WIDTH Get Value            */

#define WDT_COMP_PARAM_1_PAUSE_Pos    (7U)                                                                                  /*!< PAUSE Position  7          */ 
#define WDT_COMP_PARAM_1_PAUSE_Msk    (0x1U << WDT_COMP_PARAM_1_PAUSE_Pos)                                                  /*!< PAUSE Mask      0x00000080 */
#define WDT_COMP_PARAM_1_PAUSE_Set(x) (((uint32_t) (x) << WDT_COMP_PARAM_1_PAUSE_Pos) & WDT_COMP_PARAM_1_PAUSE_Msk)         /*!< PAUSE Set Value            */
#define WDT_COMP_PARAM_1_PAUSE_Get(x) (((uint32_t) (x) & WDT_COMP_PARAM_1_PAUSE_Msk) >> WDT_COMP_PARAM_1_PAUSE_Pos)         /*!< PAUSE Get Value            */

#define WDT_COMP_PARAM_1_USE_FIX_TOP_Pos    (6U)                                                                                  /*!< USE_FIX_TOP Position  6          */ 
#define WDT_COMP_PARAM_1_USE_FIX_TOP_Msk    (0x1U << WDT_COMP_PARAM_1_USE_FIX_TOP_Pos)                                            /*!< USE_FIX_TOP Mask      0x00000040 */
#define WDT_COMP_PARAM_1_USE_FIX_TOP_Set(x) (((uint32_t) (x) << WDT_COMP_PARAM_1_USE_FIX_TOP_Pos) & WDT_COMP_PARAM_1_USE_FIX_TOP_Msk) /*!< USE_FIX_TOP Set Value            */
#define WDT_COMP_PARAM_1_USE_FIX_TOP_Get(x) (((uint32_t) (x) & WDT_COMP_PARAM_1_USE_FIX_TOP_Msk) >> WDT_COMP_PARAM_1_USE_FIX_TOP_Pos) /*!< USE_FIX_TOP Get Value            */

#define WDT_COMP_PARAM_1_HC_TOP_Pos    (5U)                                                                                  /*!< HC_TOP Position  5          */ 
#define WDT_COMP_PARAM_1_HC_TOP_Msk    (0x1U << WDT_COMP_PARAM_1_HC_TOP_Pos)                                                 /*!< HC_TOP Mask      0x00000020 */
#define WDT_COMP_PARAM_1_HC_TOP_Set(x) (((uint32_t) (x) << WDT_COMP_PARAM_1_HC_TOP_Pos) & WDT_COMP_PARAM_1_HC_TOP_Msk)       /*!< HC_TOP Set Value            */
#define WDT_COMP_PARAM_1_HC_TOP_Get(x) (((uint32_t) (x) & WDT_COMP_PARAM_1_HC_TOP_Msk) >> WDT_COMP_PARAM_1_HC_TOP_Pos)       /*!< HC_TOP Get Value            */

#define WDT_COMP_PARAM_1_HC_RPL_Pos    (4U)                                                                                  /*!< HC_RPL Position  4          */ 
#define WDT_COMP_PARAM_1_HC_RPL_Msk    (0x1U << WDT_COMP_PARAM_1_HC_RPL_Pos)                                                 /*!< HC_RPL Mask      0x00000010 */
#define WDT_COMP_PARAM_1_HC_RPL_Set(x) (((uint32_t) (x) << WDT_COMP_PARAM_1_HC_RPL_Pos) & WDT_COMP_PARAM_1_HC_RPL_Msk)       /*!< HC_RPL Set Value            */
#define WDT_COMP_PARAM_1_HC_RPL_Get(x) (((uint32_t) (x) & WDT_COMP_PARAM_1_HC_RPL_Msk) >> WDT_COMP_PARAM_1_HC_RPL_Pos)       /*!< HC_RPL Get Value            */

#define WDT_COMP_PARAM_1_HC_RMOD_Pos    (3U)                                                                                  /*!< HC_RMOD Position  3          */ 
#define WDT_COMP_PARAM_1_HC_RMOD_Msk    (0x1U << WDT_COMP_PARAM_1_HC_RMOD_Pos)                                                /*!< HC_RMOD Mask      0x00000008 */
#define WDT_COMP_PARAM_1_HC_RMOD_Set(x) (((uint32_t) (x) << WDT_COMP_PARAM_1_HC_RMOD_Pos) & WDT_COMP_PARAM_1_HC_RMOD_Msk)     /*!< HC_RMOD Set Value            */
#define WDT_COMP_PARAM_1_HC_RMOD_Get(x) (((uint32_t) (x) & WDT_COMP_PARAM_1_HC_RMOD_Msk) >> WDT_COMP_PARAM_1_HC_RMOD_Pos)     /*!< HC_RMOD Get Value            */

#define WDT_COMP_PARAM_1_DUAL_TOP_Pos    (2U)                                                                                  /*!< DUAL_TOP Position  2          */ 
#define WDT_COMP_PARAM_1_DUAL_TOP_Msk    (0x1U << WDT_COMP_PARAM_1_DUAL_TOP_Pos)                                               /*!< DUAL_TOP Mask      0x00000004 */
#define WDT_COMP_PARAM_1_DUAL_TOP_Set(x) (((uint32_t) (x) << WDT_COMP_PARAM_1_DUAL_TOP_Pos) & WDT_COMP_PARAM_1_DUAL_TOP_Msk)   /*!< DUAL_TOP Set Value            */
#define WDT_COMP_PARAM_1_DUAL_TOP_Get(x) (((uint32_t) (x) & WDT_COMP_PARAM_1_DUAL_TOP_Msk) >> WDT_COMP_PARAM_1_DUAL_TOP_Pos)   /*!< DUAL_TOP Get Value            */

#define WDT_COMP_PARAM_1_DFLT_RMOD_Pos    (1U)                                                                                  /*!< DFLT_RMOD Position  1          */ 
#define WDT_COMP_PARAM_1_DFLT_RMOD_Msk    (0x1U << WDT_COMP_PARAM_1_DFLT_RMOD_Pos)                                              /*!< DFLT_RMOD Mask      0x00000002 */
#define WDT_COMP_PARAM_1_DFLT_RMOD_Set(x) (((uint32_t) (x) << WDT_COMP_PARAM_1_DFLT_RMOD_Pos) & WDT_COMP_PARAM_1_DFLT_RMOD_Msk) /*!< DFLT_RMOD Set Value            */
#define WDT_COMP_PARAM_1_DFLT_RMOD_Get(x) (((uint32_t) (x) & WDT_COMP_PARAM_1_DFLT_RMOD_Msk) >> WDT_COMP_PARAM_1_DFLT_RMOD_Pos) /*!< DFLT_RMOD Get Value            */

#define WDT_COMP_PARAM_1_ALWAYS_EN_Pos    (0U)                                                                                  /*!< ALWAYS_EN Position  0          */ 
#define WDT_COMP_PARAM_1_ALWAYS_EN_Msk    (0x1U << WDT_COMP_PARAM_1_ALWAYS_EN_Pos)                                              /*!< ALWAYS_EN Mask      0x00000001 */
#define WDT_COMP_PARAM_1_ALWAYS_EN_Set(x) (((uint32_t) (x) << WDT_COMP_PARAM_1_ALWAYS_EN_Pos) & WDT_COMP_PARAM_1_ALWAYS_EN_Msk) /*!< ALWAYS_EN Set Value            */
#define WDT_COMP_PARAM_1_ALWAYS_EN_Get(x) (((uint32_t) (x) & WDT_COMP_PARAM_1_ALWAYS_EN_Msk) >> WDT_COMP_PARAM_1_ALWAYS_EN_Pos) /*!< ALWAYS_EN Get Value            */

/* COMP_VERSION bitfield */
#define WDT_COMP_VERSION_COMP_VERSION_Pos    (0U)                                                                                  /*!< COMP_VERSION Position  0          */ 
#define WDT_COMP_VERSION_COMP_VERSION_Msk    (0xffffffffU << WDT_COMP_VERSION_COMP_VERSION_Pos)                                    /*!< COMP_VERSION Mask      0xFFFFFFFF */
#define WDT_COMP_VERSION_COMP_VERSION_Set(x) (((uint32_t) (x) << WDT_COMP_VERSION_COMP_VERSION_Pos) & WDT_COMP_VERSION_COMP_VERSION_Msk) /*!< COMP_VERSION Set Value            */
#define WDT_COMP_VERSION_COMP_VERSION_Get(x) (((uint32_t) (x) & WDT_COMP_VERSION_COMP_VERSION_Msk) >> WDT_COMP_VERSION_COMP_VERSION_Pos) /*!< COMP_VERSION Get Value            */

/* COMP_TYPE bitfield */
#define WDT_COMP_TYPE_COMP_TYPE_Pos    (0U)                                                                                  /*!< COMP_TYPE Position  0          */ 
#define WDT_COMP_TYPE_COMP_TYPE_Msk    (0xffffffffU << WDT_COMP_TYPE_COMP_TYPE_Pos)                                          /*!< COMP_TYPE Mask      0xFFFFFFFF */
#define WDT_COMP_TYPE_COMP_TYPE_Set(x) (((uint32_t) (x) << WDT_COMP_TYPE_COMP_TYPE_Pos) & WDT_COMP_TYPE_COMP_TYPE_Msk)       /*!< COMP_TYPE Set Value            */
#define WDT_COMP_TYPE_COMP_TYPE_Get(x) (((uint32_t) (x) & WDT_COMP_TYPE_COMP_TYPE_Msk) >> WDT_COMP_TYPE_COMP_TYPE_Pos)       /*!< COMP_TYPE Get Value            */

/*!
 * @}
 */

/*!
 * @}
 */ /* end of HS32F7D377_WDT_REGISTER */

#endif /* HS32F7D377_WDT_H */
