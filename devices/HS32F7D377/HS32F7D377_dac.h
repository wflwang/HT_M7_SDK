/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


/*!
 * \file   HS32F7D377_dac.h
 * \brief  HS32F7D377 DAC register file
 * \version V1.0_20230804
 */

#ifndef HS32F7D377_DAC_H
#define HS32F7D377_DAC_H

/*!
 * \addtogroup   HS32F7D377_DAC_REGISTER HS32F7D377 DAC Register
 * \ingroup HS32F7D377_REGISTER
 *
 * \brief  DAC register layout, bitfield and address definitions
 *
 * @{
 */

/*!
 * \name DAC Register Layout
 *
 *
 * @{
 */

/*! \brief DAC_REGS register */
typedef struct {
    union
    {
        __IM uint16_t DACREV;  /*!< 0x00000000 */ 
    
        struct
        {
            __IM  uint16_t REV                       : 8 ;     /*!< [7:0] : DAC Revision                                                    <br>  Reset type: SYSRSn                                              <br>. */
                  uint16_t RSV_0                     : 8 ;     /*!< [15:8] : reserved. */
        } DACREVb;
    };

    union
    {
        __IOM uint16_t DACCTL;  /*!< 0x00000002 */ 
    
        struct
        {
            __IOM uint16_t DACREFSEL                 : 1 ;     /*!< [0:0] : DAC reference select. */
                  uint16_t RSV_2                     : 1 ;     /*!< [1:1] : reserved. */
            __IOM uint16_t LOADMODE                  : 1 ;     /*!< [2:2] : DACVALA load mode. */
                  uint16_t RSV_1                     : 1 ;     /*!< [3:3] : reserved. */
            __IOM uint16_t SYNCSEL                   : 4 ;     /*!< [7:4] : DAC EPWMSYNCPER select. */
                  uint16_t RSV_0                     : 8 ;     /*!< [15:8] : reserved. */
        } DACCTLb;
    };

    union
    {
        __IM uint16_t DACVALA;  /*!< 0x00000004 */ 
    
        struct
        {
            __IM  uint16_t DACVALA                   : 12;     /*!< [11:0] : Active output code currently driven by the DAC                  <br>  Reset type: SYSRSn                                              <br>. */
                  uint16_t RSV_0                     : 4 ;     /*!< [15:12] : reserved. */
        } DACVALAb;
    };

    union
    {
        __IOM uint16_t DACVALS;  /*!< 0x00000006 */ 
    
        struct
        {
            __IOM uint16_t DACVALS                   : 12;     /*!< [11:0] : Shadow output code currently driven by the DAC                  <br>  Reset type: SYSRSn                                              <br>. */
                  uint16_t RSV_0                     : 4 ;     /*!< [15:12] : reserved. */
        } DACVALSb;
    };

    union
    {
        __IOM uint16_t DACOUTEN;  /*!< 0x00000008 */ 
    
        struct
        {
            __IOM uint16_t DACOUTEN                  : 1 ;     /*!< [0:0] : DAC output enable                                               <br>  0 DAC output is disabled 1 DAC output is enabled Reset type: SYSRSn<br>. */
                  uint16_t RSV_0                     : 15;     /*!< [15:1] : reserved. */
        } DACOUTENb;
    };

    union
    {
        __IOM uint16_t DACLOCK;  /*!< 0x0000000a */ 
    
        struct
        {
            __IOM uint16_t DACCTL                    : 1 ;     /*!< [0:0] : Lock write-access to the DACCTL register. */
            __IOM uint16_t DACVAL                    : 1 ;     /*!< [1:1] : Lock write-access to the DACVALS register. */
            __IOM uint16_t DACOUTEN                  : 1 ;     /*!< [2:2] : Lock write-access to the DACOUTEN register. */
                  uint16_t RSV_0                     : 9 ;     /*!< [11:3] : reserved. */
            __IM  uint16_t KEY                       : 4 ;     /*!< [15:12] : Writes to this register succeed only if this field is written with a value of 0xA. */
        } DACLOCKb;
    };

    union
    {
        __IOM uint32_t DACTRIM;  /*!< 0x0000000c */ 
    
        struct
        {
            __IOM uint32_t OFFSET_TRIM               : 8 ;     /*!< [7:0] : DAC Offset Trim. */
                  uint32_t RSV_0                     : 24;     /*!< [31:8] : reserved. */
        } DACTRIMb;
    };

    uint8_t    RSV_0X10[48];   /*!< 0x00000010~0x0000003f : reserved */

    union
    {
        __IOM uint32_t TESTFIFO;  /*!< 0x00000040 */ 
    
        struct
        {
            __IOM uint32_t THRESH                    : 5 ;     /*!< [4:0] : FIFOSTS Less than or equal to THRESH, write request             <br>  0: THRESH is 0;                                                 <br>  1: THRESH is 1;                                                 <br>  . */
                  uint32_t RSV_2                     : 3 ;     /*!< [7:5] : reserved. */
            __IM  uint32_t FIFOSTS                   : 5 ;     /*!< [12:8] : TEST FIFO Status                                                <br>  0: FIFO empty                                                   <br>  1: FIFO has 1 data                                              <br>  . */
            __IM  uint32_t FIFOOVF                   : 1 ;     /*!< [13:13] : TEST FIFO Overflow Flag                                         <br>  Reset type: SYSRSn                                              <br>. */
            __IM  uint32_t FIFOUDF                   : 1 ;     /*!< [14:14] : TEST FIFO Underflow Flag                                        <br>  Reset type: SYSRSn                                              <br>. */
                  uint32_t RSV_1                     : 1 ;     /*!< [15:15] : reserved. */
            __IM  uint32_t FIFOVAL                   : 12;     /*!< [27:16] : Fifo output value                                               <br>  Reset type: SYSRSn                                              <br>. */
                  uint32_t RSV_0                     : 4 ;     /*!< [31:28] : reserved. */
        } TESTFIFOb;
    };

    union
    {
        __IM uint32_t TESTCTR;  /*!< 0x00000044 */ 
    
        struct
        {
            __IM  uint32_t CTRVAL                    : 8 ;     /*!< [7:0] : TEST Counter Register                                           <br>  Reset type: SYSRSn                                              <br>. */
                  uint32_t RSV_0                     : 24;     /*!< [31:8] : reserved. */
        } TESTCTRb;
    };

    union
    {
        __IOM uint32_t TESTCTL;  /*!< 0x00000048 */ 
    
        struct
        {
            __IOM uint32_t TESTEN                    : 1 ;     /*!< [0:0] : TEST enable                                                     <br>  0: disable;                                                     <br>  1: enable. */
                  uint32_t RSV_3                     : 7 ;     /*!< [7:1] : reserved. */
            __IOM uint32_t TESTFIFOEN                : 1 ;     /*!< [8:8] : TEST FIFO enable                                                <br>  0: disable;                                                     <br>  1: enable. */
                  uint32_t RSV_2                     : 7 ;     /*!< [15:9] : reserved. */
            __IOM uint32_t DACSOURCE                 : 1 ;     /*!< [16:16] : DAC source select. */
                  uint32_t RSV_1                     : 7 ;     /*!< [23:17] : reserved. */
            __IOM uint32_t FREQDIV                   : 4 ;     /*!< [27:24] : Conversion rate frequency division. */
                  uint32_t RSV_0                     : 4 ;     /*!< [31:28] : reserved. */
        } TESTCTLb;
    };

    union
    {
        __IM uint32_t TESTDMA;  /*!< 0x0000004c */ 
    
        struct
        {
            __IM  uint32_t TRIGFLG                   : 1 ;     /*!< [0:0] : TEST DMA trig flag                                              <br>  Reset type: SYSRSn                                              <br>. */
                  uint32_t RSV_0                     : 31;     /*!< [31:1] : reserved. */
        } TESTDMAb;
    };

    union
    {
        __IM uint32_t TESTDATAIN1;  /*!< 0x00000050 */ 
    
        struct
        {
            __IM  uint32_t TESTVAL1                  : 16;     /*!< [15:0] : TEST value. */
            __IM  uint32_t TESTVAL2                  : 16;     /*!< [31:16] : TEST value. */
        } TESTDATAIN1b;
    };

    union
    {
        __IM uint32_t TESTDATAIN2;  /*!< 0x00000054 */ 
    
        struct
        {
            __IM  uint32_t TESTVAL3                  : 16;     /*!< [15:0] : TEST value. */
            __IM  uint32_t TESTVAL4                  : 16;     /*!< [31:16] : TEST value. */
        } TESTDATAIN2b;
    };

    union
    {
        __IM uint32_t TESTDATAIN3;  /*!< 0x00000058 */ 
    
        struct
        {
            __IM  uint32_t TESTVAL5                  : 16;     /*!< [15:0] : TEST value. */
            __IM  uint32_t TESTVAL6                  : 16;     /*!< [31:16] : TEST value. */
        } TESTDATAIN3b;
    };

    union
    {
        __IM uint32_t TESTDATAIN4;  /*!< 0x0000005c */ 
    
        struct
        {
            __IM  uint32_t TESTVAL7                  : 16;     /*!< [15:0] : TEST value. */
            __IM  uint32_t TESTVAL8                  : 16;     /*!< [31:16] : TEST value. */
        } TESTDATAIN4b;
    };

    union
    {
        __IM uint32_t TESTDATAIN5;  /*!< 0x00000060 */ 
    
        struct
        {
            __IM  uint32_t TESTVAL9                  : 16;     /*!< [15:0] : TEST value. */
            __IM  uint32_t TESTVAL10                 : 16;     /*!< [31:16] : TEST value. */
        } TESTDATAIN5b;
    };

    union
    {
        __IM uint32_t TESTDATAIN6;  /*!< 0x00000064 */ 
    
        struct
        {
            __IM  uint32_t TESTVAL11                 : 16;     /*!< [15:0] : TEST value. */
            __IM  uint32_t TESTVAL12                 : 16;     /*!< [31:16] : TEST value. */
        } TESTDATAIN6b;
    };

    union
    {
        __IM uint32_t TESTDATAIN7;  /*!< 0x00000068 */ 
    
        struct
        {
            __IM  uint32_t TESTVAL13                 : 16;     /*!< [15:0] : TEST value. */
            __IM  uint32_t TESTVAL14                 : 16;     /*!< [31:16] : TEST value. */
        } TESTDATAIN7b;
    };

    union
    {
        __IM uint32_t TESTDATAIN8;  /*!< 0x0000006c */ 
    
        struct
        {
            __IM  uint32_t TESTVAL15                 : 16;     /*!< [15:0] : TEST value. */
            __IM  uint32_t TESTVAL16                 : 16;     /*!< [31:16] : TEST value. */
        } TESTDATAIN8b;
    };

    uint8_t    RSV_0X70[16];   /*!< 0x00000070~0x0000007f : reserved */

    union
    {
        __IOM uint32_t TESTLOCK;  /*!< 0x00000080 */ 
    
        struct
        {
            __IOM uint32_t TESTLOCK                  : 1 ;     /*!< [0:0] : Lock write-access to the TESTDMA register and TESTCTL register. */
                  uint32_t RSV_0                     : 31;     /*!< [31:1] : reserved. */
        } TESTLOCKb;
    };

    uint8_t    RSV_0X84[28];   /*!< 0x00000084~0x0000009f : reserved */

    union
    {
        __IM uint32_t DBPWMSP;  /*!< 0x000000a0 */ 
    
        struct
        {
            __IM  uint32_t SYNCPERLEVEL              : 1 ;     /*!< [0:0] : EPWMSYNCPER Level Signal                                        <br>  Reset type: SYSRSn                                              <br>. */
                  uint32_t RSV_1                     : 15;     /*!< [15:1] : reserved. */
            __IM  uint32_t SYNCPERPULSE              : 1 ;     /*!< [16:16] : EPWMSYNCPER Pulse Signal                                        <br>  Reset type: SYSRSn                                              <br>. */
                  uint32_t RSV_0                     : 15;     /*!< [31:17] : reserved. */
        } DBPWMSPb;
    };

    union
    {
        __IM uint32_t DBDACVAL;  /*!< 0x000000a4 */ 
    
        struct
        {
            __IM  uint32_t DACOVAL                   : 14;     /*!< [13:0] : DAC Offset Value. */
                  uint32_t RSV_1                     : 2 ;     /*!< [15:14] : reserved. */
            __IM  uint32_t DACFVAL                   : 12;     /*!< [27:16] : DAC Final Value. */
                  uint32_t RSV_0                     : 4 ;     /*!< [31:28] : reserved. */
        } DBDACVALb;
    };

    union
    {
        __IM uint32_t DBDACBIN;  /*!< 0x000000a8 */ 
    
        struct
        {
            __IM  uint32_t DACBVAL                   : 7 ;     /*!< [6:0] : DAC Binary Input Value. */
                  uint32_t RSV_0                     : 25;     /*!< [31:7] : reserved. */
        } DBDACBINb;
    };

    union
    {
        __IM uint32_t DBDACTIN;  /*!< 0x000000ac */ 
    
        struct
        {
            __IM  uint32_t DACTVAL                   : 31;     /*!< [30:0] : DAC Thermometer Input Value. */
                  uint32_t RSV_0                     : 1 ;     /*!< [31:31] : reserved. */
        } DBDACTINb;
    };

    union
    {
        __IOM uint32_t DBDACPORTSEL;  /*!< 0x000000b0 */ 
    
        struct
        {
            __IOM uint32_t DBGDACVAL                 : 2 ;     /*!< [1:0] : Dacval debug select. */
                  uint32_t RSV_2                     : 6 ;     /*!< [7:2] : reserved. */
            __IOM uint32_t DBGTEST                   : 2 ;     /*!< [9:8] : Test debug select. */
                  uint32_t RSV_1                     : 6 ;     /*!< [15:10] : reserved. */
            __IOM uint32_t DBGSUB                    : 2 ;     /*!< [17:16] : Subtop debug select. */
                  uint32_t RSV_0                     : 14;     /*!< [31:18] : reserved. */
        } DBDACPORTSELb;
    };
} DAC_REGS_Type;


/*!
 * @}
 */


/*!
 * \name DAC Base Address Definitions
 *
 * @{
 */

/*! \brief DACA base address */
#define DAC_REGS0_BASE (0x41400000UL)
/*! \brief DACB base address */
#define DAC_REGS1_BASE (0x41400400UL)
/*! \brief DACC base address */
#define DAC_REGS2_BASE (0x41400800UL)
/*! \brief DACA base pointer */
#define DACA ((DAC_REGS_Type *) DAC_REGS0_BASE)
/*! \brief DACB base pointer */
#define DACB ((DAC_REGS_Type *) DAC_REGS1_BASE)
/*! \brief DACC base pointer */
#define DACC ((DAC_REGS_Type *) DAC_REGS2_BASE)


/*!
 * @}
 */


/*!
 * \name DAC Register Bitfield Definitions
 *
 * @{
 */

/* DACREV bitfield */
#define DAC_REGS_DACREV_REV_Pos    (0U)                                                                                  /*!< REV Position  0          */ 
#define DAC_REGS_DACREV_REV_Msk    (0xffU << DAC_REGS_DACREV_REV_Pos)                                                    /*!< REV Mask      0x000000FF */
#define DAC_REGS_DACREV_REV_Set(x) (((uint16_t) (x) << DAC_REGS_DACREV_REV_Pos) & DAC_REGS_DACREV_REV_Msk)               /*!< REV Set Value            */
#define DAC_REGS_DACREV_REV_Get(x) (((uint16_t) (x) & DAC_REGS_DACREV_REV_Msk) >> DAC_REGS_DACREV_REV_Pos)               /*!< REV Get Value            */

/* DACCTL bitfield */
#define DAC_REGS_DACCTL_SYNCSEL_Pos    (4U)                                                                                  /*!< SYNCSEL Position  4          */ 
#define DAC_REGS_DACCTL_SYNCSEL_Msk    (0xfU << DAC_REGS_DACCTL_SYNCSEL_Pos)                                                 /*!< SYNCSEL Mask      0x000000F0 */
#define DAC_REGS_DACCTL_SYNCSEL_Set(x) (((uint16_t) (x) << DAC_REGS_DACCTL_SYNCSEL_Pos) & DAC_REGS_DACCTL_SYNCSEL_Msk)       /*!< SYNCSEL Set Value            */
#define DAC_REGS_DACCTL_SYNCSEL_Get(x) (((uint16_t) (x) & DAC_REGS_DACCTL_SYNCSEL_Msk) >> DAC_REGS_DACCTL_SYNCSEL_Pos)       /*!< SYNCSEL Get Value            */

#define DAC_REGS_DACCTL_LOADMODE_Pos    (2U)                                                                                  /*!< LOADMODE Position  2          */ 
#define DAC_REGS_DACCTL_LOADMODE_Msk    (0x1U << DAC_REGS_DACCTL_LOADMODE_Pos)                                                /*!< LOADMODE Mask      0x00000004 */
#define DAC_REGS_DACCTL_LOADMODE_Set(x) (((uint16_t) (x) << DAC_REGS_DACCTL_LOADMODE_Pos) & DAC_REGS_DACCTL_LOADMODE_Msk)     /*!< LOADMODE Set Value            */
#define DAC_REGS_DACCTL_LOADMODE_Get(x) (((uint16_t) (x) & DAC_REGS_DACCTL_LOADMODE_Msk) >> DAC_REGS_DACCTL_LOADMODE_Pos)     /*!< LOADMODE Get Value            */

#define DAC_REGS_DACCTL_DACREFSEL_Pos    (0U)                                                                                  /*!< DACREFSEL Position  0          */ 
#define DAC_REGS_DACCTL_DACREFSEL_Msk    (0x1U << DAC_REGS_DACCTL_DACREFSEL_Pos)                                               /*!< DACREFSEL Mask      0x00000001 */
#define DAC_REGS_DACCTL_DACREFSEL_Set(x) (((uint16_t) (x) << DAC_REGS_DACCTL_DACREFSEL_Pos) & DAC_REGS_DACCTL_DACREFSEL_Msk)   /*!< DACREFSEL Set Value            */
#define DAC_REGS_DACCTL_DACREFSEL_Get(x) (((uint16_t) (x) & DAC_REGS_DACCTL_DACREFSEL_Msk) >> DAC_REGS_DACCTL_DACREFSEL_Pos)   /*!< DACREFSEL Get Value            */

/* DACVALA bitfield */
#define DAC_REGS_DACVALA_DACVALA_Pos    (0U)                                                                                  /*!< DACVALA Position  0          */ 
#define DAC_REGS_DACVALA_DACVALA_Msk    (0xfffU << DAC_REGS_DACVALA_DACVALA_Pos)                                              /*!< DACVALA Mask      0x00000FFF */
#define DAC_REGS_DACVALA_DACVALA_Set(x) (((uint16_t) (x) << DAC_REGS_DACVALA_DACVALA_Pos) & DAC_REGS_DACVALA_DACVALA_Msk)     /*!< DACVALA Set Value            */
#define DAC_REGS_DACVALA_DACVALA_Get(x) (((uint16_t) (x) & DAC_REGS_DACVALA_DACVALA_Msk) >> DAC_REGS_DACVALA_DACVALA_Pos)     /*!< DACVALA Get Value            */

/* DACVALS bitfield */
#define DAC_REGS_DACVALS_DACVALS_Pos    (0U)                                                                                  /*!< DACVALS Position  0          */ 
#define DAC_REGS_DACVALS_DACVALS_Msk    (0xfffU << DAC_REGS_DACVALS_DACVALS_Pos)                                              /*!< DACVALS Mask      0x00000FFF */
#define DAC_REGS_DACVALS_DACVALS_Set(x) (((uint16_t) (x) << DAC_REGS_DACVALS_DACVALS_Pos) & DAC_REGS_DACVALS_DACVALS_Msk)     /*!< DACVALS Set Value            */
#define DAC_REGS_DACVALS_DACVALS_Get(x) (((uint16_t) (x) & DAC_REGS_DACVALS_DACVALS_Msk) >> DAC_REGS_DACVALS_DACVALS_Pos)     /*!< DACVALS Get Value            */

/* DACOUTEN bitfield */
#define DAC_REGS_DACOUTEN_DACOUTEN_Pos    (0U)                                                                                  /*!< DACOUTEN Position  0          */ 
#define DAC_REGS_DACOUTEN_DACOUTEN_Msk    (0x1U << DAC_REGS_DACOUTEN_DACOUTEN_Pos)                                              /*!< DACOUTEN Mask      0x00000001 */
#define DAC_REGS_DACOUTEN_DACOUTEN_Set(x) (((uint16_t) (x) << DAC_REGS_DACOUTEN_DACOUTEN_Pos) & DAC_REGS_DACOUTEN_DACOUTEN_Msk) /*!< DACOUTEN Set Value            */
#define DAC_REGS_DACOUTEN_DACOUTEN_Get(x) (((uint16_t) (x) & DAC_REGS_DACOUTEN_DACOUTEN_Msk) >> DAC_REGS_DACOUTEN_DACOUTEN_Pos) /*!< DACOUTEN Get Value            */

/* DACLOCK bitfield */
#define DAC_REGS_DACLOCK_KEY_Pos    (12U)                                                                                 /*!< KEY Position  12         */ 
#define DAC_REGS_DACLOCK_KEY_Msk    (0xfU << DAC_REGS_DACLOCK_KEY_Pos)                                                    /*!< KEY Mask      0x0000F000 */
#define DAC_REGS_DACLOCK_KEY_Set(x) (((uint16_t) (x) << DAC_REGS_DACLOCK_KEY_Pos) & DAC_REGS_DACLOCK_KEY_Msk)             /*!< KEY Set Value            */
#define DAC_REGS_DACLOCK_KEY_Get(x) (((uint16_t) (x) & DAC_REGS_DACLOCK_KEY_Msk) >> DAC_REGS_DACLOCK_KEY_Pos)             /*!< KEY Get Value            */

#define DAC_REGS_DACLOCK_DACOUTEN_Pos    (2U)                                                                                  /*!< DACOUTEN Position  2          */ 
#define DAC_REGS_DACLOCK_DACOUTEN_Msk    (0x1U << DAC_REGS_DACLOCK_DACOUTEN_Pos)                                               /*!< DACOUTEN Mask      0x00000004 */
#define DAC_REGS_DACLOCK_DACOUTEN_Set(x) (((uint16_t) (x) << DAC_REGS_DACLOCK_DACOUTEN_Pos) & DAC_REGS_DACLOCK_DACOUTEN_Msk)   /*!< DACOUTEN Set Value            */
#define DAC_REGS_DACLOCK_DACOUTEN_Get(x) (((uint16_t) (x) & DAC_REGS_DACLOCK_DACOUTEN_Msk) >> DAC_REGS_DACLOCK_DACOUTEN_Pos)   /*!< DACOUTEN Get Value            */

#define DAC_REGS_DACLOCK_DACVAL_Pos    (1U)                                                                                  /*!< DACVAL Position  1          */ 
#define DAC_REGS_DACLOCK_DACVAL_Msk    (0x1U << DAC_REGS_DACLOCK_DACVAL_Pos)                                                 /*!< DACVAL Mask      0x00000002 */
#define DAC_REGS_DACLOCK_DACVAL_Set(x) (((uint16_t) (x) << DAC_REGS_DACLOCK_DACVAL_Pos) & DAC_REGS_DACLOCK_DACVAL_Msk)       /*!< DACVAL Set Value            */
#define DAC_REGS_DACLOCK_DACVAL_Get(x) (((uint16_t) (x) & DAC_REGS_DACLOCK_DACVAL_Msk) >> DAC_REGS_DACLOCK_DACVAL_Pos)       /*!< DACVAL Get Value            */

#define DAC_REGS_DACLOCK_DACCTL_Pos    (0U)                                                                                  /*!< DACCTL Position  0          */ 
#define DAC_REGS_DACLOCK_DACCTL_Msk    (0x1U << DAC_REGS_DACLOCK_DACCTL_Pos)                                                 /*!< DACCTL Mask      0x00000001 */
#define DAC_REGS_DACLOCK_DACCTL_Set(x) (((uint16_t) (x) << DAC_REGS_DACLOCK_DACCTL_Pos) & DAC_REGS_DACLOCK_DACCTL_Msk)       /*!< DACCTL Set Value            */
#define DAC_REGS_DACLOCK_DACCTL_Get(x) (((uint16_t) (x) & DAC_REGS_DACLOCK_DACCTL_Msk) >> DAC_REGS_DACLOCK_DACCTL_Pos)       /*!< DACCTL Get Value            */

/* DACTRIM bitfield */
#define DAC_REGS_DACTRIM_OFFSET_TRIM_Pos    (0U)                                                                                  /*!< OFFSET_TRIM Position  0          */ 
#define DAC_REGS_DACTRIM_OFFSET_TRIM_Msk    (0xffU << DAC_REGS_DACTRIM_OFFSET_TRIM_Pos)                                           /*!< OFFSET_TRIM Mask      0x000000FF */
#define DAC_REGS_DACTRIM_OFFSET_TRIM_Set(x) (((uint32_t) (x) << DAC_REGS_DACTRIM_OFFSET_TRIM_Pos) & DAC_REGS_DACTRIM_OFFSET_TRIM_Msk) /*!< OFFSET_TRIM Set Value            */
#define DAC_REGS_DACTRIM_OFFSET_TRIM_Get(x) (((uint32_t) (x) & DAC_REGS_DACTRIM_OFFSET_TRIM_Msk) >> DAC_REGS_DACTRIM_OFFSET_TRIM_Pos) /*!< OFFSET_TRIM Get Value            */

/* TESTFIFO bitfield */
#define DAC_REGS_TESTFIFO_FIFOVAL_Pos    (16U)                                                                                 /*!< FIFOVAL Position  16         */ 
#define DAC_REGS_TESTFIFO_FIFOVAL_Msk    (0xfffU << DAC_REGS_TESTFIFO_FIFOVAL_Pos)                                             /*!< FIFOVAL Mask      0x0FFF0000 */
#define DAC_REGS_TESTFIFO_FIFOVAL_Set(x) (((uint32_t) (x) << DAC_REGS_TESTFIFO_FIFOVAL_Pos) & DAC_REGS_TESTFIFO_FIFOVAL_Msk)   /*!< FIFOVAL Set Value            */
#define DAC_REGS_TESTFIFO_FIFOVAL_Get(x) (((uint32_t) (x) & DAC_REGS_TESTFIFO_FIFOVAL_Msk) >> DAC_REGS_TESTFIFO_FIFOVAL_Pos)   /*!< FIFOVAL Get Value            */

#define DAC_REGS_TESTFIFO_FIFOUDF_Pos    (14U)                                                                                 /*!< FIFOUDF Position  14         */ 
#define DAC_REGS_TESTFIFO_FIFOUDF_Msk    (0x1U << DAC_REGS_TESTFIFO_FIFOUDF_Pos)                                               /*!< FIFOUDF Mask      0x00004000 */
#define DAC_REGS_TESTFIFO_FIFOUDF_Set(x) (((uint32_t) (x) << DAC_REGS_TESTFIFO_FIFOUDF_Pos) & DAC_REGS_TESTFIFO_FIFOUDF_Msk)   /*!< FIFOUDF Set Value            */
#define DAC_REGS_TESTFIFO_FIFOUDF_Get(x) (((uint32_t) (x) & DAC_REGS_TESTFIFO_FIFOUDF_Msk) >> DAC_REGS_TESTFIFO_FIFOUDF_Pos)   /*!< FIFOUDF Get Value            */

#define DAC_REGS_TESTFIFO_FIFOOVF_Pos    (13U)                                                                                 /*!< FIFOOVF Position  13         */ 
#define DAC_REGS_TESTFIFO_FIFOOVF_Msk    (0x1U << DAC_REGS_TESTFIFO_FIFOOVF_Pos)                                               /*!< FIFOOVF Mask      0x00002000 */
#define DAC_REGS_TESTFIFO_FIFOOVF_Set(x) (((uint32_t) (x) << DAC_REGS_TESTFIFO_FIFOOVF_Pos) & DAC_REGS_TESTFIFO_FIFOOVF_Msk)   /*!< FIFOOVF Set Value            */
#define DAC_REGS_TESTFIFO_FIFOOVF_Get(x) (((uint32_t) (x) & DAC_REGS_TESTFIFO_FIFOOVF_Msk) >> DAC_REGS_TESTFIFO_FIFOOVF_Pos)   /*!< FIFOOVF Get Value            */

#define DAC_REGS_TESTFIFO_FIFOSTS_Pos    (8U)                                                                                  /*!< FIFOSTS Position  8          */ 
#define DAC_REGS_TESTFIFO_FIFOSTS_Msk    (0x1fU << DAC_REGS_TESTFIFO_FIFOSTS_Pos)                                              /*!< FIFOSTS Mask      0x00001F00 */
#define DAC_REGS_TESTFIFO_FIFOSTS_Set(x) (((uint32_t) (x) << DAC_REGS_TESTFIFO_FIFOSTS_Pos) & DAC_REGS_TESTFIFO_FIFOSTS_Msk)   /*!< FIFOSTS Set Value            */
#define DAC_REGS_TESTFIFO_FIFOSTS_Get(x) (((uint32_t) (x) & DAC_REGS_TESTFIFO_FIFOSTS_Msk) >> DAC_REGS_TESTFIFO_FIFOSTS_Pos)   /*!< FIFOSTS Get Value            */

#define DAC_REGS_TESTFIFO_THRESH_Pos    (0U)                                                                                  /*!< THRESH Position  0          */ 
#define DAC_REGS_TESTFIFO_THRESH_Msk    (0x1fU << DAC_REGS_TESTFIFO_THRESH_Pos)                                               /*!< THRESH Mask      0x0000001F */
#define DAC_REGS_TESTFIFO_THRESH_Set(x) (((uint32_t) (x) << DAC_REGS_TESTFIFO_THRESH_Pos) & DAC_REGS_TESTFIFO_THRESH_Msk)     /*!< THRESH Set Value            */
#define DAC_REGS_TESTFIFO_THRESH_Get(x) (((uint32_t) (x) & DAC_REGS_TESTFIFO_THRESH_Msk) >> DAC_REGS_TESTFIFO_THRESH_Pos)     /*!< THRESH Get Value            */

/* TESTCTR bitfield */
#define DAC_REGS_TESTCTR_CTRVAL_Pos    (0U)                                                                                  /*!< CTRVAL Position  0          */ 
#define DAC_REGS_TESTCTR_CTRVAL_Msk    (0xffU << DAC_REGS_TESTCTR_CTRVAL_Pos)                                                /*!< CTRVAL Mask      0x000000FF */
#define DAC_REGS_TESTCTR_CTRVAL_Set(x) (((uint32_t) (x) << DAC_REGS_TESTCTR_CTRVAL_Pos) & DAC_REGS_TESTCTR_CTRVAL_Msk)       /*!< CTRVAL Set Value            */
#define DAC_REGS_TESTCTR_CTRVAL_Get(x) (((uint32_t) (x) & DAC_REGS_TESTCTR_CTRVAL_Msk) >> DAC_REGS_TESTCTR_CTRVAL_Pos)       /*!< CTRVAL Get Value            */

/* TESTCTL bitfield */
#define DAC_REGS_TESTCTL_FREQDIV_Pos    (24U)                                                                                 /*!< FREQDIV Position  24         */ 
#define DAC_REGS_TESTCTL_FREQDIV_Msk    (0xfU << DAC_REGS_TESTCTL_FREQDIV_Pos)                                                /*!< FREQDIV Mask      0x0F000000 */
#define DAC_REGS_TESTCTL_FREQDIV_Set(x) (((uint32_t) (x) << DAC_REGS_TESTCTL_FREQDIV_Pos) & DAC_REGS_TESTCTL_FREQDIV_Msk)     /*!< FREQDIV Set Value            */
#define DAC_REGS_TESTCTL_FREQDIV_Get(x) (((uint32_t) (x) & DAC_REGS_TESTCTL_FREQDIV_Msk) >> DAC_REGS_TESTCTL_FREQDIV_Pos)     /*!< FREQDIV Get Value            */

#define DAC_REGS_TESTCTL_DACSOURCE_Pos    (16U)                                                                                 /*!< DACSOURCE Position  16         */ 
#define DAC_REGS_TESTCTL_DACSOURCE_Msk    (0x1U << DAC_REGS_TESTCTL_DACSOURCE_Pos)                                              /*!< DACSOURCE Mask      0x00010000 */
#define DAC_REGS_TESTCTL_DACSOURCE_Set(x) (((uint32_t) (x) << DAC_REGS_TESTCTL_DACSOURCE_Pos) & DAC_REGS_TESTCTL_DACSOURCE_Msk) /*!< DACSOURCE Set Value            */
#define DAC_REGS_TESTCTL_DACSOURCE_Get(x) (((uint32_t) (x) & DAC_REGS_TESTCTL_DACSOURCE_Msk) >> DAC_REGS_TESTCTL_DACSOURCE_Pos) /*!< DACSOURCE Get Value            */

#define DAC_REGS_TESTCTL_TESTFIFOEN_Pos    (8U)                                                                                  /*!< TESTFIFOEN Position  8          */ 
#define DAC_REGS_TESTCTL_TESTFIFOEN_Msk    (0x1U << DAC_REGS_TESTCTL_TESTFIFOEN_Pos)                                             /*!< TESTFIFOEN Mask      0x00000100 */
#define DAC_REGS_TESTCTL_TESTFIFOEN_Set(x) (((uint32_t) (x) << DAC_REGS_TESTCTL_TESTFIFOEN_Pos) & DAC_REGS_TESTCTL_TESTFIFOEN_Msk) /*!< TESTFIFOEN Set Value            */
#define DAC_REGS_TESTCTL_TESTFIFOEN_Get(x) (((uint32_t) (x) & DAC_REGS_TESTCTL_TESTFIFOEN_Msk) >> DAC_REGS_TESTCTL_TESTFIFOEN_Pos) /*!< TESTFIFOEN Get Value            */

#define DAC_REGS_TESTCTL_TESTEN_Pos    (0U)                                                                                  /*!< TESTEN Position  0          */ 
#define DAC_REGS_TESTCTL_TESTEN_Msk    (0x1U << DAC_REGS_TESTCTL_TESTEN_Pos)                                                 /*!< TESTEN Mask      0x00000001 */
#define DAC_REGS_TESTCTL_TESTEN_Set(x) (((uint32_t) (x) << DAC_REGS_TESTCTL_TESTEN_Pos) & DAC_REGS_TESTCTL_TESTEN_Msk)       /*!< TESTEN Set Value            */
#define DAC_REGS_TESTCTL_TESTEN_Get(x) (((uint32_t) (x) & DAC_REGS_TESTCTL_TESTEN_Msk) >> DAC_REGS_TESTCTL_TESTEN_Pos)       /*!< TESTEN Get Value            */

/* TESTDMA bitfield */
#define DAC_REGS_TESTDMA_TRIGFLG_Pos    (0U)                                                                                  /*!< TRIGFLG Position  0          */ 
#define DAC_REGS_TESTDMA_TRIGFLG_Msk    (0x1U << DAC_REGS_TESTDMA_TRIGFLG_Pos)                                                /*!< TRIGFLG Mask      0x00000001 */
#define DAC_REGS_TESTDMA_TRIGFLG_Set(x) (((uint32_t) (x) << DAC_REGS_TESTDMA_TRIGFLG_Pos) & DAC_REGS_TESTDMA_TRIGFLG_Msk)     /*!< TRIGFLG Set Value            */
#define DAC_REGS_TESTDMA_TRIGFLG_Get(x) (((uint32_t) (x) & DAC_REGS_TESTDMA_TRIGFLG_Msk) >> DAC_REGS_TESTDMA_TRIGFLG_Pos)     /*!< TRIGFLG Get Value            */

/* TESTDATAIN1 bitfield */
#define DAC_REGS_TESTDATAIN1_TESTVAL2_Pos    (16U)                                                                                 /*!< TESTVAL2 Position  16         */ 
#define DAC_REGS_TESTDATAIN1_TESTVAL2_Msk    (0xffffU << DAC_REGS_TESTDATAIN1_TESTVAL2_Pos)                                        /*!< TESTVAL2 Mask      0xFFFF0000 */
#define DAC_REGS_TESTDATAIN1_TESTVAL2_Set(x) (((uint32_t) (x) << DAC_REGS_TESTDATAIN1_TESTVAL2_Pos) & DAC_REGS_TESTDATAIN1_TESTVAL2_Msk) /*!< TESTVAL2 Set Value            */
#define DAC_REGS_TESTDATAIN1_TESTVAL2_Get(x) (((uint32_t) (x) & DAC_REGS_TESTDATAIN1_TESTVAL2_Msk) >> DAC_REGS_TESTDATAIN1_TESTVAL2_Pos) /*!< TESTVAL2 Get Value            */

#define DAC_REGS_TESTDATAIN1_TESTVAL1_Pos    (0U)                                                                                  /*!< TESTVAL1 Position  0          */ 
#define DAC_REGS_TESTDATAIN1_TESTVAL1_Msk    (0xffffU << DAC_REGS_TESTDATAIN1_TESTVAL1_Pos)                                        /*!< TESTVAL1 Mask      0x0000FFFF */
#define DAC_REGS_TESTDATAIN1_TESTVAL1_Set(x) (((uint32_t) (x) << DAC_REGS_TESTDATAIN1_TESTVAL1_Pos) & DAC_REGS_TESTDATAIN1_TESTVAL1_Msk) /*!< TESTVAL1 Set Value            */
#define DAC_REGS_TESTDATAIN1_TESTVAL1_Get(x) (((uint32_t) (x) & DAC_REGS_TESTDATAIN1_TESTVAL1_Msk) >> DAC_REGS_TESTDATAIN1_TESTVAL1_Pos) /*!< TESTVAL1 Get Value            */

/* TESTDATAIN2 bitfield */
#define DAC_REGS_TESTDATAIN2_TESTVAL4_Pos    (16U)                                                                                 /*!< TESTVAL4 Position  16         */ 
#define DAC_REGS_TESTDATAIN2_TESTVAL4_Msk    (0xffffU << DAC_REGS_TESTDATAIN2_TESTVAL4_Pos)                                        /*!< TESTVAL4 Mask      0xFFFF0000 */
#define DAC_REGS_TESTDATAIN2_TESTVAL4_Set(x) (((uint32_t) (x) << DAC_REGS_TESTDATAIN2_TESTVAL4_Pos) & DAC_REGS_TESTDATAIN2_TESTVAL4_Msk) /*!< TESTVAL4 Set Value            */
#define DAC_REGS_TESTDATAIN2_TESTVAL4_Get(x) (((uint32_t) (x) & DAC_REGS_TESTDATAIN2_TESTVAL4_Msk) >> DAC_REGS_TESTDATAIN2_TESTVAL4_Pos) /*!< TESTVAL4 Get Value            */

#define DAC_REGS_TESTDATAIN2_TESTVAL3_Pos    (0U)                                                                                  /*!< TESTVAL3 Position  0          */ 
#define DAC_REGS_TESTDATAIN2_TESTVAL3_Msk    (0xffffU << DAC_REGS_TESTDATAIN2_TESTVAL3_Pos)                                        /*!< TESTVAL3 Mask      0x0000FFFF */
#define DAC_REGS_TESTDATAIN2_TESTVAL3_Set(x) (((uint32_t) (x) << DAC_REGS_TESTDATAIN2_TESTVAL3_Pos) & DAC_REGS_TESTDATAIN2_TESTVAL3_Msk) /*!< TESTVAL3 Set Value            */
#define DAC_REGS_TESTDATAIN2_TESTVAL3_Get(x) (((uint32_t) (x) & DAC_REGS_TESTDATAIN2_TESTVAL3_Msk) >> DAC_REGS_TESTDATAIN2_TESTVAL3_Pos) /*!< TESTVAL3 Get Value            */

/* TESTDATAIN3 bitfield */
#define DAC_REGS_TESTDATAIN3_TESTVAL6_Pos    (16U)                                                                                 /*!< TESTVAL6 Position  16         */ 
#define DAC_REGS_TESTDATAIN3_TESTVAL6_Msk    (0xffffU << DAC_REGS_TESTDATAIN3_TESTVAL6_Pos)                                        /*!< TESTVAL6 Mask      0xFFFF0000 */
#define DAC_REGS_TESTDATAIN3_TESTVAL6_Set(x) (((uint32_t) (x) << DAC_REGS_TESTDATAIN3_TESTVAL6_Pos) & DAC_REGS_TESTDATAIN3_TESTVAL6_Msk) /*!< TESTVAL6 Set Value            */
#define DAC_REGS_TESTDATAIN3_TESTVAL6_Get(x) (((uint32_t) (x) & DAC_REGS_TESTDATAIN3_TESTVAL6_Msk) >> DAC_REGS_TESTDATAIN3_TESTVAL6_Pos) /*!< TESTVAL6 Get Value            */

#define DAC_REGS_TESTDATAIN3_TESTVAL5_Pos    (0U)                                                                                  /*!< TESTVAL5 Position  0          */ 
#define DAC_REGS_TESTDATAIN3_TESTVAL5_Msk    (0xffffU << DAC_REGS_TESTDATAIN3_TESTVAL5_Pos)                                        /*!< TESTVAL5 Mask      0x0000FFFF */
#define DAC_REGS_TESTDATAIN3_TESTVAL5_Set(x) (((uint32_t) (x) << DAC_REGS_TESTDATAIN3_TESTVAL5_Pos) & DAC_REGS_TESTDATAIN3_TESTVAL5_Msk) /*!< TESTVAL5 Set Value            */
#define DAC_REGS_TESTDATAIN3_TESTVAL5_Get(x) (((uint32_t) (x) & DAC_REGS_TESTDATAIN3_TESTVAL5_Msk) >> DAC_REGS_TESTDATAIN3_TESTVAL5_Pos) /*!< TESTVAL5 Get Value            */

/* TESTDATAIN4 bitfield */
#define DAC_REGS_TESTDATAIN4_TESTVAL8_Pos    (16U)                                                                                 /*!< TESTVAL8 Position  16         */ 
#define DAC_REGS_TESTDATAIN4_TESTVAL8_Msk    (0xffffU << DAC_REGS_TESTDATAIN4_TESTVAL8_Pos)                                        /*!< TESTVAL8 Mask      0xFFFF0000 */
#define DAC_REGS_TESTDATAIN4_TESTVAL8_Set(x) (((uint32_t) (x) << DAC_REGS_TESTDATAIN4_TESTVAL8_Pos) & DAC_REGS_TESTDATAIN4_TESTVAL8_Msk) /*!< TESTVAL8 Set Value            */
#define DAC_REGS_TESTDATAIN4_TESTVAL8_Get(x) (((uint32_t) (x) & DAC_REGS_TESTDATAIN4_TESTVAL8_Msk) >> DAC_REGS_TESTDATAIN4_TESTVAL8_Pos) /*!< TESTVAL8 Get Value            */

#define DAC_REGS_TESTDATAIN4_TESTVAL7_Pos    (0U)                                                                                  /*!< TESTVAL7 Position  0          */ 
#define DAC_REGS_TESTDATAIN4_TESTVAL7_Msk    (0xffffU << DAC_REGS_TESTDATAIN4_TESTVAL7_Pos)                                        /*!< TESTVAL7 Mask      0x0000FFFF */
#define DAC_REGS_TESTDATAIN4_TESTVAL7_Set(x) (((uint32_t) (x) << DAC_REGS_TESTDATAIN4_TESTVAL7_Pos) & DAC_REGS_TESTDATAIN4_TESTVAL7_Msk) /*!< TESTVAL7 Set Value            */
#define DAC_REGS_TESTDATAIN4_TESTVAL7_Get(x) (((uint32_t) (x) & DAC_REGS_TESTDATAIN4_TESTVAL7_Msk) >> DAC_REGS_TESTDATAIN4_TESTVAL7_Pos) /*!< TESTVAL7 Get Value            */

/* TESTDATAIN5 bitfield */
#define DAC_REGS_TESTDATAIN5_TESTVAL10_Pos    (16U)                                                                                 /*!< TESTVAL10 Position  16         */ 
#define DAC_REGS_TESTDATAIN5_TESTVAL10_Msk    (0xffffU << DAC_REGS_TESTDATAIN5_TESTVAL10_Pos)                                       /*!< TESTVAL10 Mask      0xFFFF0000 */
#define DAC_REGS_TESTDATAIN5_TESTVAL10_Set(x) (((uint32_t) (x) << DAC_REGS_TESTDATAIN5_TESTVAL10_Pos) & DAC_REGS_TESTDATAIN5_TESTVAL10_Msk) /*!< TESTVAL10 Set Value            */
#define DAC_REGS_TESTDATAIN5_TESTVAL10_Get(x) (((uint32_t) (x) & DAC_REGS_TESTDATAIN5_TESTVAL10_Msk) >> DAC_REGS_TESTDATAIN5_TESTVAL10_Pos) /*!< TESTVAL10 Get Value            */

#define DAC_REGS_TESTDATAIN5_TESTVAL9_Pos    (0U)                                                                                  /*!< TESTVAL9 Position  0          */ 
#define DAC_REGS_TESTDATAIN5_TESTVAL9_Msk    (0xffffU << DAC_REGS_TESTDATAIN5_TESTVAL9_Pos)                                        /*!< TESTVAL9 Mask      0x0000FFFF */
#define DAC_REGS_TESTDATAIN5_TESTVAL9_Set(x) (((uint32_t) (x) << DAC_REGS_TESTDATAIN5_TESTVAL9_Pos) & DAC_REGS_TESTDATAIN5_TESTVAL9_Msk) /*!< TESTVAL9 Set Value            */
#define DAC_REGS_TESTDATAIN5_TESTVAL9_Get(x) (((uint32_t) (x) & DAC_REGS_TESTDATAIN5_TESTVAL9_Msk) >> DAC_REGS_TESTDATAIN5_TESTVAL9_Pos) /*!< TESTVAL9 Get Value            */

/* TESTDATAIN6 bitfield */
#define DAC_REGS_TESTDATAIN6_TESTVAL12_Pos    (16U)                                                                                 /*!< TESTVAL12 Position  16         */ 
#define DAC_REGS_TESTDATAIN6_TESTVAL12_Msk    (0xffffU << DAC_REGS_TESTDATAIN6_TESTVAL12_Pos)                                       /*!< TESTVAL12 Mask      0xFFFF0000 */
#define DAC_REGS_TESTDATAIN6_TESTVAL12_Set(x) (((uint32_t) (x) << DAC_REGS_TESTDATAIN6_TESTVAL12_Pos) & DAC_REGS_TESTDATAIN6_TESTVAL12_Msk) /*!< TESTVAL12 Set Value            */
#define DAC_REGS_TESTDATAIN6_TESTVAL12_Get(x) (((uint32_t) (x) & DAC_REGS_TESTDATAIN6_TESTVAL12_Msk) >> DAC_REGS_TESTDATAIN6_TESTVAL12_Pos) /*!< TESTVAL12 Get Value            */

#define DAC_REGS_TESTDATAIN6_TESTVAL11_Pos    (0U)                                                                                  /*!< TESTVAL11 Position  0          */ 
#define DAC_REGS_TESTDATAIN6_TESTVAL11_Msk    (0xffffU << DAC_REGS_TESTDATAIN6_TESTVAL11_Pos)                                       /*!< TESTVAL11 Mask      0x0000FFFF */
#define DAC_REGS_TESTDATAIN6_TESTVAL11_Set(x) (((uint32_t) (x) << DAC_REGS_TESTDATAIN6_TESTVAL11_Pos) & DAC_REGS_TESTDATAIN6_TESTVAL11_Msk) /*!< TESTVAL11 Set Value            */
#define DAC_REGS_TESTDATAIN6_TESTVAL11_Get(x) (((uint32_t) (x) & DAC_REGS_TESTDATAIN6_TESTVAL11_Msk) >> DAC_REGS_TESTDATAIN6_TESTVAL11_Pos) /*!< TESTVAL11 Get Value            */

/* TESTDATAIN7 bitfield */
#define DAC_REGS_TESTDATAIN7_TESTVAL14_Pos    (16U)                                                                                 /*!< TESTVAL14 Position  16         */ 
#define DAC_REGS_TESTDATAIN7_TESTVAL14_Msk    (0xffffU << DAC_REGS_TESTDATAIN7_TESTVAL14_Pos)                                       /*!< TESTVAL14 Mask      0xFFFF0000 */
#define DAC_REGS_TESTDATAIN7_TESTVAL14_Set(x) (((uint32_t) (x) << DAC_REGS_TESTDATAIN7_TESTVAL14_Pos) & DAC_REGS_TESTDATAIN7_TESTVAL14_Msk) /*!< TESTVAL14 Set Value            */
#define DAC_REGS_TESTDATAIN7_TESTVAL14_Get(x) (((uint32_t) (x) & DAC_REGS_TESTDATAIN7_TESTVAL14_Msk) >> DAC_REGS_TESTDATAIN7_TESTVAL14_Pos) /*!< TESTVAL14 Get Value            */

#define DAC_REGS_TESTDATAIN7_TESTVAL13_Pos    (0U)                                                                                  /*!< TESTVAL13 Position  0          */ 
#define DAC_REGS_TESTDATAIN7_TESTVAL13_Msk    (0xffffU << DAC_REGS_TESTDATAIN7_TESTVAL13_Pos)                                       /*!< TESTVAL13 Mask      0x0000FFFF */
#define DAC_REGS_TESTDATAIN7_TESTVAL13_Set(x) (((uint32_t) (x) << DAC_REGS_TESTDATAIN7_TESTVAL13_Pos) & DAC_REGS_TESTDATAIN7_TESTVAL13_Msk) /*!< TESTVAL13 Set Value            */
#define DAC_REGS_TESTDATAIN7_TESTVAL13_Get(x) (((uint32_t) (x) & DAC_REGS_TESTDATAIN7_TESTVAL13_Msk) >> DAC_REGS_TESTDATAIN7_TESTVAL13_Pos) /*!< TESTVAL13 Get Value            */

/* TESTDATAIN8 bitfield */
#define DAC_REGS_TESTDATAIN8_TESTVAL16_Pos    (16U)                                                                                 /*!< TESTVAL16 Position  16         */ 
#define DAC_REGS_TESTDATAIN8_TESTVAL16_Msk    (0xffffU << DAC_REGS_TESTDATAIN8_TESTVAL16_Pos)                                       /*!< TESTVAL16 Mask      0xFFFF0000 */
#define DAC_REGS_TESTDATAIN8_TESTVAL16_Set(x) (((uint32_t) (x) << DAC_REGS_TESTDATAIN8_TESTVAL16_Pos) & DAC_REGS_TESTDATAIN8_TESTVAL16_Msk) /*!< TESTVAL16 Set Value            */
#define DAC_REGS_TESTDATAIN8_TESTVAL16_Get(x) (((uint32_t) (x) & DAC_REGS_TESTDATAIN8_TESTVAL16_Msk) >> DAC_REGS_TESTDATAIN8_TESTVAL16_Pos) /*!< TESTVAL16 Get Value            */

#define DAC_REGS_TESTDATAIN8_TESTVAL15_Pos    (0U)                                                                                  /*!< TESTVAL15 Position  0          */ 
#define DAC_REGS_TESTDATAIN8_TESTVAL15_Msk    (0xffffU << DAC_REGS_TESTDATAIN8_TESTVAL15_Pos)                                       /*!< TESTVAL15 Mask      0x0000FFFF */
#define DAC_REGS_TESTDATAIN8_TESTVAL15_Set(x) (((uint32_t) (x) << DAC_REGS_TESTDATAIN8_TESTVAL15_Pos) & DAC_REGS_TESTDATAIN8_TESTVAL15_Msk) /*!< TESTVAL15 Set Value            */
#define DAC_REGS_TESTDATAIN8_TESTVAL15_Get(x) (((uint32_t) (x) & DAC_REGS_TESTDATAIN8_TESTVAL15_Msk) >> DAC_REGS_TESTDATAIN8_TESTVAL15_Pos) /*!< TESTVAL15 Get Value            */

/* TESTLOCK bitfield */
#define DAC_REGS_TESTLOCK_TESTLOCK_Pos    (0U)                                                                                  /*!< TESTLOCK Position  0          */ 
#define DAC_REGS_TESTLOCK_TESTLOCK_Msk    (0x1U << DAC_REGS_TESTLOCK_TESTLOCK_Pos)                                              /*!< TESTLOCK Mask      0x00000001 */
#define DAC_REGS_TESTLOCK_TESTLOCK_Set(x) (((uint32_t) (x) << DAC_REGS_TESTLOCK_TESTLOCK_Pos) & DAC_REGS_TESTLOCK_TESTLOCK_Msk) /*!< TESTLOCK Set Value            */
#define DAC_REGS_TESTLOCK_TESTLOCK_Get(x) (((uint32_t) (x) & DAC_REGS_TESTLOCK_TESTLOCK_Msk) >> DAC_REGS_TESTLOCK_TESTLOCK_Pos) /*!< TESTLOCK Get Value            */

/* DBPWMSP bitfield */
#define DAC_REGS_DBPWMSP_SYNCPERPULSE_Pos    (16U)                                                                                 /*!< SYNCPERPULSE Position  16         */ 
#define DAC_REGS_DBPWMSP_SYNCPERPULSE_Msk    (0x1U << DAC_REGS_DBPWMSP_SYNCPERPULSE_Pos)                                           /*!< SYNCPERPULSE Mask      0x00010000 */
#define DAC_REGS_DBPWMSP_SYNCPERPULSE_Set(x) (((uint32_t) (x) << DAC_REGS_DBPWMSP_SYNCPERPULSE_Pos) & DAC_REGS_DBPWMSP_SYNCPERPULSE_Msk) /*!< SYNCPERPULSE Set Value            */
#define DAC_REGS_DBPWMSP_SYNCPERPULSE_Get(x) (((uint32_t) (x) & DAC_REGS_DBPWMSP_SYNCPERPULSE_Msk) >> DAC_REGS_DBPWMSP_SYNCPERPULSE_Pos) /*!< SYNCPERPULSE Get Value            */

#define DAC_REGS_DBPWMSP_SYNCPERLEVEL_Pos    (0U)                                                                                  /*!< SYNCPERLEVEL Position  0          */ 
#define DAC_REGS_DBPWMSP_SYNCPERLEVEL_Msk    (0x1U << DAC_REGS_DBPWMSP_SYNCPERLEVEL_Pos)                                           /*!< SYNCPERLEVEL Mask      0x00000001 */
#define DAC_REGS_DBPWMSP_SYNCPERLEVEL_Set(x) (((uint32_t) (x) << DAC_REGS_DBPWMSP_SYNCPERLEVEL_Pos) & DAC_REGS_DBPWMSP_SYNCPERLEVEL_Msk) /*!< SYNCPERLEVEL Set Value            */
#define DAC_REGS_DBPWMSP_SYNCPERLEVEL_Get(x) (((uint32_t) (x) & DAC_REGS_DBPWMSP_SYNCPERLEVEL_Msk) >> DAC_REGS_DBPWMSP_SYNCPERLEVEL_Pos) /*!< SYNCPERLEVEL Get Value            */

/* DBDACVAL bitfield */
#define DAC_REGS_DBDACVAL_DACFVAL_Pos    (16U)                                                                                 /*!< DACFVAL Position  16         */ 
#define DAC_REGS_DBDACVAL_DACFVAL_Msk    (0xfffU << DAC_REGS_DBDACVAL_DACFVAL_Pos)                                             /*!< DACFVAL Mask      0x0FFF0000 */
#define DAC_REGS_DBDACVAL_DACFVAL_Set(x) (((uint32_t) (x) << DAC_REGS_DBDACVAL_DACFVAL_Pos) & DAC_REGS_DBDACVAL_DACFVAL_Msk)   /*!< DACFVAL Set Value            */
#define DAC_REGS_DBDACVAL_DACFVAL_Get(x) (((uint32_t) (x) & DAC_REGS_DBDACVAL_DACFVAL_Msk) >> DAC_REGS_DBDACVAL_DACFVAL_Pos)   /*!< DACFVAL Get Value            */

#define DAC_REGS_DBDACVAL_DACOVAL_Pos    (0U)                                                                                  /*!< DACOVAL Position  0          */ 
#define DAC_REGS_DBDACVAL_DACOVAL_Msk    (0x3fffU << DAC_REGS_DBDACVAL_DACOVAL_Pos)                                            /*!< DACOVAL Mask      0x00003FFF */
#define DAC_REGS_DBDACVAL_DACOVAL_Set(x) (((uint32_t) (x) << DAC_REGS_DBDACVAL_DACOVAL_Pos) & DAC_REGS_DBDACVAL_DACOVAL_Msk)   /*!< DACOVAL Set Value            */
#define DAC_REGS_DBDACVAL_DACOVAL_Get(x) (((uint32_t) (x) & DAC_REGS_DBDACVAL_DACOVAL_Msk) >> DAC_REGS_DBDACVAL_DACOVAL_Pos)   /*!< DACOVAL Get Value            */

/* DBDACBIN bitfield */
#define DAC_REGS_DBDACBIN_DACBVAL_Pos    (0U)                                                                                  /*!< DACBVAL Position  0          */ 
#define DAC_REGS_DBDACBIN_DACBVAL_Msk    (0x7fU << DAC_REGS_DBDACBIN_DACBVAL_Pos)                                              /*!< DACBVAL Mask      0x0000007F */
#define DAC_REGS_DBDACBIN_DACBVAL_Set(x) (((uint32_t) (x) << DAC_REGS_DBDACBIN_DACBVAL_Pos) & DAC_REGS_DBDACBIN_DACBVAL_Msk)   /*!< DACBVAL Set Value            */
#define DAC_REGS_DBDACBIN_DACBVAL_Get(x) (((uint32_t) (x) & DAC_REGS_DBDACBIN_DACBVAL_Msk) >> DAC_REGS_DBDACBIN_DACBVAL_Pos)   /*!< DACBVAL Get Value            */

/* DBDACTIN bitfield */
#define DAC_REGS_DBDACTIN_DACTVAL_Pos    (0U)                                                                                  /*!< DACTVAL Position  0          */ 
#define DAC_REGS_DBDACTIN_DACTVAL_Msk    (0x7fffffffU << DAC_REGS_DBDACTIN_DACTVAL_Pos)                                        /*!< DACTVAL Mask      0x7FFFFFFF */
#define DAC_REGS_DBDACTIN_DACTVAL_Set(x) (((uint32_t) (x) << DAC_REGS_DBDACTIN_DACTVAL_Pos) & DAC_REGS_DBDACTIN_DACTVAL_Msk)   /*!< DACTVAL Set Value            */
#define DAC_REGS_DBDACTIN_DACTVAL_Get(x) (((uint32_t) (x) & DAC_REGS_DBDACTIN_DACTVAL_Msk) >> DAC_REGS_DBDACTIN_DACTVAL_Pos)   /*!< DACTVAL Get Value            */

/* DBDACPORTSEL bitfield */
#define DAC_REGS_DBDACPORTSEL_DBGSUB_Pos    (16U)                                                                                 /*!< DBGSUB Position  16         */ 
#define DAC_REGS_DBDACPORTSEL_DBGSUB_Msk    (0x3U << DAC_REGS_DBDACPORTSEL_DBGSUB_Pos)                                            /*!< DBGSUB Mask      0x00030000 */
#define DAC_REGS_DBDACPORTSEL_DBGSUB_Set(x) (((uint32_t) (x) << DAC_REGS_DBDACPORTSEL_DBGSUB_Pos) & DAC_REGS_DBDACPORTSEL_DBGSUB_Msk) /*!< DBGSUB Set Value            */
#define DAC_REGS_DBDACPORTSEL_DBGSUB_Get(x) (((uint32_t) (x) & DAC_REGS_DBDACPORTSEL_DBGSUB_Msk) >> DAC_REGS_DBDACPORTSEL_DBGSUB_Pos) /*!< DBGSUB Get Value            */

#define DAC_REGS_DBDACPORTSEL_DBGTEST_Pos    (8U)                                                                                  /*!< DBGTEST Position  8          */ 
#define DAC_REGS_DBDACPORTSEL_DBGTEST_Msk    (0x3U << DAC_REGS_DBDACPORTSEL_DBGTEST_Pos)                                           /*!< DBGTEST Mask      0x00000300 */
#define DAC_REGS_DBDACPORTSEL_DBGTEST_Set(x) (((uint32_t) (x) << DAC_REGS_DBDACPORTSEL_DBGTEST_Pos) & DAC_REGS_DBDACPORTSEL_DBGTEST_Msk) /*!< DBGTEST Set Value            */
#define DAC_REGS_DBDACPORTSEL_DBGTEST_Get(x) (((uint32_t) (x) & DAC_REGS_DBDACPORTSEL_DBGTEST_Msk) >> DAC_REGS_DBDACPORTSEL_DBGTEST_Pos) /*!< DBGTEST Get Value            */

#define DAC_REGS_DBDACPORTSEL_DBGDACVAL_Pos    (0U)                                                                                  /*!< DBGDACVAL Position  0          */ 
#define DAC_REGS_DBDACPORTSEL_DBGDACVAL_Msk    (0x3U << DAC_REGS_DBDACPORTSEL_DBGDACVAL_Pos)                                         /*!< DBGDACVAL Mask      0x00000003 */
#define DAC_REGS_DBDACPORTSEL_DBGDACVAL_Set(x) (((uint32_t) (x) << DAC_REGS_DBDACPORTSEL_DBGDACVAL_Pos) & DAC_REGS_DBDACPORTSEL_DBGDACVAL_Msk) /*!< DBGDACVAL Set Value            */
#define DAC_REGS_DBDACPORTSEL_DBGDACVAL_Get(x) (((uint32_t) (x) & DAC_REGS_DBDACPORTSEL_DBGDACVAL_Msk) >> DAC_REGS_DBDACPORTSEL_DBGDACVAL_Pos) /*!< DBGDACVAL Get Value            */

/*!
 * @}
 */

/*!
 * @}
 */ /* end of HS32F7D377_DAC_REGISTER */

#endif /* HS32F7D377_DAC_H */
