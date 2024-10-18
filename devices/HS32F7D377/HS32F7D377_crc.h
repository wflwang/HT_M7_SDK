/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


/*!
 * \file   HS32F7D377_crc.h
 * \brief  HS32F7D377 CRC register file
 * \version V1.0_20230713
 */

#ifndef HS32F7D377_CRC_H
#define HS32F7D377_CRC_H

/*!
 * \addtogroup   HS32F7D377_CRC_REGISTER HS32F7D377 CRC Register
 * \ingroup HS32F7D377_REGISTER
 *
 * \brief  CRC register layout, bitfield and address definitions
 *
 * @{
 */

/*!
 * \name CRC Register Layout
 *
 *
 * @{
 */

/*! \brief CRC register layout */
typedef struct
{
    union
    {
        __IOM uint32_t CRC_DR; /*!< 0x00000000 */

        struct
        {
            __IOM uint32_t CRC_DR : 32; /*!< [31:0] : crc data register  <br> this register is used to write new data to
                                           CRC unit <br>it can be covered by next data <br> when a new CRC is needed,
                                           the reset bit in CFG should be 1. */
        } CRC_DRb;
    };

    union
    {
        __IM uint32_t CRC_RR; /*!< 0x00000004 */

        struct
        {
            __IM uint32_t
                CRC_RR : 32; /*!< [31:0] : crc result register  <br> this register is used to hold CRC data. */
        } CRC_RRb;
    };

    union
    {
        __IOM uint32_t CRC_CFG; /*!< 0x00000008 */

        struct
        {
            uint32_t       RSV_1     : 1; /*!< [0:0] : reserved. */
            __IOM uint32_t CRC_RESET : 1; /*!< [1:1] : crc reset bit  <br>this bit is set by software to reset the CRC
                                             calculation <br>then set the data initial value to CRC_INIT register
                                             <br>this bit can be automatically cleared by hardware. */
            __IOM uint32_t
                CRC_POLYSIZE : 3; /*!< [4:2] : crc polynimial size  <br> 2'b000 : 32bit polynomial  <br> 2'b010
                                     : 16bit polynomial  <br> 2'b100 : 8bit  polynomial  <br> 2'b110 : 7bit
                                     polynomial  <br> 2'b001 : 24bit  polynomial. */
            __IOM uint32_t
                CRC_REV_IN : 2; /*!< [6:5] : crc reverse input data by bit/byte/hword/word  <br> 2'b00 : bit order
                                   not affected  <br> 2'b01 : bit-reversed by byte  <br> 2'b10 : bit-reversed by
                                   half-word <br> 2'b11 : bit-reversed by word. */
            __IOM uint32_t CRC_REV_BYTE : 1; /*!< [7:7] : crc reverse input by byte  <br> 1'b0 : byte order not
                                                affected  <br> 1'b1 : byte-reversed. */
            __IOM uint32_t CRC_REV_OUT : 1;  /*!< [8:8] : crc reverse output by bit  <br> 1'b0 : bit order not
                                                affected  <br> 1'b1 : bit-reversed output format. */
            uint32_t RSV_0 : 23;             /*!< [31:9] : reserved. */
        } CRC_CFGb;
    };

    union
    {
        __IOM uint32_t CRC_INIT; /*!< 0x0000000c */

        struct
        {
            __IOM uint32_t CRC_INIT : 32; /*!< [31:0] : crc initialized CRC value  <br>this register is used to write
                                             CRC_DR when reset by CRC_CFG. */
        } CRC_INITb;
    };

    union
    {
        __IOM uint32_t CRC_POLY; /*!< 0x00000010 */

        struct
        {
            __IOM uint32_t CRC_POLY : 32; /*!< [31:0] : crc polynomial register  <br>this register is used to write the
                                             coefficients of the polynomial <br>If the poly is less than 32 bits, the
                                             least significant bit should be used. */
        } CRC_POLYb;
    };

    union
    {
        __IOM uint32_t CRC_DBG; /*!< 0x00000014 */

        struct
        {
            __IOM
            uint32_t CRC_DBG_SEL : 8; /*!< [7:0] : crc debug port  <br>   wire [15:0] dbg_crc_00 = <br> 1'b0, <br>
                                         bus_en,               <br>                                bus_addr[4:0], <br>
                                         bus_wr,               <br>                                5'b0, <br>
                                         dbg_cstate[2:0]       <br>   wire [15:0] dbg_crc_01 = <br> 1'b0, <br> bus_en,
                                         <br>                                bus_addr[4:0],        <br> bus_wr, <br>
                                         bus_wstrb[3:0],       <br>                                dbg_ws_fifo_dout[3:0]
                                         <br>   wire [15:0] dbg_crc_02 =                           <br> 1'b0, <br>
                                         bus_en,               <br>                                bus_addr[4:0], <br>
                                         bus_wr,               <br>                                bus_wdata[7:0] <br>
                                         wire [15:0] dbg_crc_03 =                           <br> 1'b0, <br> bus_en, <br>
                                         bus_addr[4:0],        <br>                                bus_wr, <br>
                                         bus_wdata[15:8]       <br>   wire [15:0] dbg_crc_04 = <br> 1'b0, <br> bus_en,
                                         <br>                                bus_addr[4:0],        <br> bus_wr, <br>
                                         bus_wdata[23:16]      <br>   wire [15:0] dbg_crc_05 = <br> 1'b0, <br> bus_en,
                                         <br>                                bus_addr[4:0],        <br> bus_wr, <br>
                                         bus_wdata[31:24]. */
            uint32_t RSV_0 : 24;      /*!< [31:8] : reserved. */
        } CRC_DBGb;
    };

} CRC_Type;

/*!
 * @}
 */

/*!
 * \name CRC Base Address Definitions
 *
 * @{
 */

/*! \brief CRC base address */
#define CRC_BASE (0x41800000UL)
/*! \brief CRC base pointer */
#define CRC ((CRC_Type *)CRC_BASE)

/*!
 * @}
 */


/*!
 * \name CRC Register Bitfield Definitions
 *
 * @{
 */

/* CRC_DR bitfield */
#define CRC_CRC_DR_CRC_DR_Pos (0U)                                   /*!< CRC_DR Postion   0          */
#define CRC_CRC_DR_CRC_DR_Msk (0xffffffffU << CRC_CRC_DR_CRC_DR_Pos) /*!< CRC_DR Mask      0xFFFFFFFF */
#define CRC_CRC_DR_CRC_DR_Set(x) \
    (((uint32_t)(x) << CRC_CRC_DR_CRC_DR_Pos) & CRC_CRC_DR_CRC_DR_Msk) /*!< CRC_DR Set Value            */
#define CRC_CRC_DR_CRC_DR_Get(x) \
    (((uint32_t)(x)&CRC_CRC_DR_CRC_DR_Msk) >> CRC_CRC_DR_CRC_DR_Pos) /*!< CRC_DR Get Value            */


/* CRC_RR bitfield */
#define CRC_CRC_RR_CRC_RR_Pos (0U)                                   /*!< CRC_RR Postion   0          */
#define CRC_CRC_RR_CRC_RR_Msk (0xffffffffU << CRC_CRC_RR_CRC_RR_Pos) /*!< CRC_RR Mask      0xFFFFFFFF */
#define CRC_CRC_RR_CRC_RR_Set(x) \
    (((uint32_t)(x) << CRC_CRC_RR_CRC_RR_Pos) & CRC_CRC_RR_CRC_RR_Msk) /*!< CRC_RR Set Value            */
#define CRC_CRC_RR_CRC_RR_Get(x) \
    (((uint32_t)(x)&CRC_CRC_RR_CRC_RR_Msk) >> CRC_CRC_RR_CRC_RR_Pos) /*!< CRC_RR Get Value            */


/* CRC_CFG bitfield */
#define CRC_CRC_CFG_CRC_REV_OUT_Pos (8U)                                  /*!< CRC_REV_OUT Postion   8          */
#define CRC_CRC_CFG_CRC_REV_OUT_Msk (0x1U << CRC_CRC_CFG_CRC_REV_OUT_Pos) /*!< CRC_REV_OUT Mask      0x00000100 */
#define CRC_CRC_CFG_CRC_REV_OUT_Set(x) \
    (((uint32_t)(x) << CRC_CRC_CFG_CRC_REV_OUT_Pos) & CRC_CRC_CFG_CRC_REV_OUT_Msk) /*!< CRC_REV_OUT Set Value */
#define CRC_CRC_CFG_CRC_REV_OUT_Get(x) \
    (((uint32_t)(x)&CRC_CRC_CFG_CRC_REV_OUT_Msk) >> CRC_CRC_CFG_CRC_REV_OUT_Pos) /*!< CRC_REV_OUT Get Value */


#define CRC_CRC_CFG_CRC_REV_BYTE_Pos (7U)                                   /*!< CRC_REV_BYTE Postion   7          */
#define CRC_CRC_CFG_CRC_REV_BYTE_Msk (0x1U << CRC_CRC_CFG_CRC_REV_BYTE_Pos) /*!< CRC_REV_BYTE Mask      0x00000080 */
#define CRC_CRC_CFG_CRC_REV_BYTE_Set(x) \
    (((uint32_t)(x) << CRC_CRC_CFG_CRC_REV_BYTE_Pos) & CRC_CRC_CFG_CRC_REV_BYTE_Msk) /*!< CRC_REV_BYTE Set Value */
#define CRC_CRC_CFG_CRC_REV_BYTE_Get(x) \
    (((uint32_t)(x)&CRC_CRC_CFG_CRC_REV_BYTE_Msk) >> CRC_CRC_CFG_CRC_REV_BYTE_Pos) /*!< CRC_REV_BYTE Get Value */


#define CRC_CRC_CFG_CRC_REV_IN_Pos (5U)                                 /*!< CRC_REV_IN Postion   5          */
#define CRC_CRC_CFG_CRC_REV_IN_Msk (0x3U << CRC_CRC_CFG_CRC_REV_IN_Pos) /*!< CRC_REV_IN Mask      0x00000060 */
#define CRC_CRC_CFG_CRC_REV_IN_Set(x) \
    (((uint32_t)(x) << CRC_CRC_CFG_CRC_REV_IN_Pos) & CRC_CRC_CFG_CRC_REV_IN_Msk) /*!< CRC_REV_IN Set Value */
#define CRC_CRC_CFG_CRC_REV_IN_Get(x) \
    (((uint32_t)(x)&CRC_CRC_CFG_CRC_REV_IN_Msk) >> CRC_CRC_CFG_CRC_REV_IN_Pos) /*!< CRC_REV_IN Get Value            */


#define CRC_CRC_CFG_CRC_POLYSIZE_Pos (2U)                                   /*!< CRC_POLYSIZE Postion   2          */
#define CRC_CRC_CFG_CRC_POLYSIZE_Msk (0x7U << CRC_CRC_CFG_CRC_POLYSIZE_Pos) /*!< CRC_POLYSIZE Mask      0x0000001C */
#define CRC_CRC_CFG_CRC_POLYSIZE_Set(x) \
    (((uint32_t)(x) << CRC_CRC_CFG_CRC_POLYSIZE_Pos) & CRC_CRC_CFG_CRC_POLYSIZE_Msk) /*!< CRC_POLYSIZE Set Value */
#define CRC_CRC_CFG_CRC_POLYSIZE_Get(x) \
    (((uint32_t)(x)&CRC_CRC_CFG_CRC_POLYSIZE_Msk) >> CRC_CRC_CFG_CRC_POLYSIZE_Pos) /*!< CRC_POLYSIZE Get Value */


#define CRC_CRC_CFG_CRC_RESET_Pos (1U)                                /*!< CRC_RESET Postion   1          */
#define CRC_CRC_CFG_CRC_RESET_Msk (0x1U << CRC_CRC_CFG_CRC_RESET_Pos) /*!< CRC_RESET Mask      0x00000002 */
#define CRC_CRC_CFG_CRC_RESET_Set(x) \
    (((uint32_t)(x) << CRC_CRC_CFG_CRC_RESET_Pos) & CRC_CRC_CFG_CRC_RESET_Msk) /*!< CRC_RESET Set Value            */
#define CRC_CRC_CFG_CRC_RESET_Get(x) \
    (((uint32_t)(x)&CRC_CRC_CFG_CRC_RESET_Msk) >> CRC_CRC_CFG_CRC_RESET_Pos) /*!< CRC_RESET Get Value            */


/* CRC_INIT bitfield */
#define CRC_CRC_INIT_CRC_INIT_Pos (0U)                                       /*!< CRC_INIT Postion   0          */
#define CRC_CRC_INIT_CRC_INIT_Msk (0xffffffffU << CRC_CRC_INIT_CRC_INIT_Pos) /*!< CRC_INIT Mask      0xFFFFFFFF */
#define CRC_CRC_INIT_CRC_INIT_Set(x) \
    (((uint32_t)(x) << CRC_CRC_INIT_CRC_INIT_Pos) & CRC_CRC_INIT_CRC_INIT_Msk) /*!< CRC_INIT Set Value            */
#define CRC_CRC_INIT_CRC_INIT_Get(x) \
    (((uint32_t)(x)&CRC_CRC_INIT_CRC_INIT_Msk) >> CRC_CRC_INIT_CRC_INIT_Pos) /*!< CRC_INIT Get Value            */


/* CRC_POLY bitfield */
#define CRC_CRC_POLY_CRC_POLY_Pos (0U)                                       /*!< CRC_POLY Postion   0          */
#define CRC_CRC_POLY_CRC_POLY_Msk (0xffffffffU << CRC_CRC_POLY_CRC_POLY_Pos) /*!< CRC_POLY Mask      0xFFFFFFFF */
#define CRC_CRC_POLY_CRC_POLY_Set(x) \
    (((uint32_t)(x) << CRC_CRC_POLY_CRC_POLY_Pos) & CRC_CRC_POLY_CRC_POLY_Msk) /*!< CRC_POLY Set Value            */
#define CRC_CRC_POLY_CRC_POLY_Get(x) \
    (((uint32_t)(x)&CRC_CRC_POLY_CRC_POLY_Msk) >> CRC_CRC_POLY_CRC_POLY_Pos) /*!< CRC_POLY Get Value            */


/* CRC_DBG bitfield */
#define CRC_CRC_DBG_CRC_DBG_SEL_Pos (0U)                                   /*!< CRC_DBG_SEL Postion   0          */
#define CRC_CRC_DBG_CRC_DBG_SEL_Msk (0xffU << CRC_CRC_DBG_CRC_DBG_SEL_Pos) /*!< CRC_DBG_SEL Mask      0x000000FF */
#define CRC_CRC_DBG_CRC_DBG_SEL_Set(x) \
    (((uint32_t)(x) << CRC_CRC_DBG_CRC_DBG_SEL_Pos) & CRC_CRC_DBG_CRC_DBG_SEL_Msk) /*!< CRC_DBG_SEL Set Value */
#define CRC_CRC_DBG_CRC_DBG_SEL_Get(x) \
    (((uint32_t)(x)&CRC_CRC_DBG_CRC_DBG_SEL_Msk) >> CRC_CRC_DBG_CRC_DBG_SEL_Pos) /*!< CRC_DBG_SEL Get Value */


/*!
 * @}
 */


/*!
 * @}
 */ /* end of HS32F7D377_CRC_REGISTER */

#endif /* HS32F7D377_CRC_H */
