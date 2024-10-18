/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


/*!
 * \file   HS32F7D377_xbar.h
 * \brief  HS32F7D377 XBAR register file
 * \version V1.0_20230713
 */

#ifndef HS32F7D377_XBAR_H
#define HS32F7D377_XBAR_H

/*!
 * \addtogroup   HS32F7D377_XBAR_REGISTER HS32F7D377 XBAR Register
 * \ingroup HS32F7D377_REGISTER
 *
 * \brief  XBAR register layout, bitfield and address definitions
 *
 * @{
 */

/*!
 * \name XBAR Register Layout
 *
 *
 * @{
 */

/*! \brief INPUT_XBAR register */
typedef struct
{
    union
    {
        __IOM uint16_t INPUTSELECT[16]; /*!< 0x00000000 */

        struct
        {
            __IOM uint16_t SELECT : 16; /*!< [15:0] : Select GPIO for INPUT1 signal: 0x0 : Select GPIO0 <br>  0x1 :
                                           Select GPIO1 0x2 : Select GPIO2                           <br>  . */
        } INPUTSELECTb[16];
    };

    uint8_t RSV_0X20[28]; /*!< 0x00000020~0x0000003b : reserved */

    union
    {
        __IOM uint32_t INPUTSELECTLOCK; /*!< 0x0000003c */

        struct
        {
            __IOM uint32_t INPUT1SELECT : 1; /*!< [0:0] : Lock bit for INPUT1SELECT Register <br>  0: Register is not
                                                locked                                       <br>  1: Register is locked
                                                <br>  Reset type: CPU1. */
            __IOM uint32_t INPUT2SELECT : 1; /*!< [1:1] : Lock bit for INPUT2SELECT Register <br>  0: Register is not
                                                locked                                       <br>  1: Register is locked
                                                <br>  Reset type: CPU1. */
            __IOM uint32_t INPUT3SELECT : 1; /*!< [2:2] : Lock bit for INPUT3SELECT Register <br>  0: Register is not
                                                locked                                       <br>  1: Register is locked
                                                <br>  Reset type: CPU1. */
            __IOM uint32_t INPUT4SELECT : 1; /*!< [3:3] : Lock bit for INPUT4SELECT Register <br>  0: Register is not
                                                locked                                       <br>  1: Register is locked
                                                <br>  Reset type: CPU1. */
            __IOM uint32_t INPUT5SELECT : 1; /*!< [4:4] : Lock bit for INPUT5SELECT Register <br>  0: Register is not
                                                locked                                       <br>  1: Register is locked
                                                <br>  Reset type: CPU1. */
            __IOM uint32_t INPUT6SELECT : 1; /*!< [5:5] : Lock bit for INPUT6SELECT Register <br>  0: Register is not
                                                locked                                       <br>  1: Register is locked
                                                <br>  Reset type: CPU1. */
            __IOM uint32_t INPUT7SELECT : 1; /*!< [6:6] : Lock bit for INPUT7SELECT Register <br>  0: Register is not
                                                locked                                       <br>  1: Register is locked
                                                <br>  Reset type: CPU1. */
            __IOM uint32_t INPUT8SELECT : 1; /*!< [7:7] : Lock bit for INPUT8SELECT Register <br>  0: Register is not
                                                locked                                       <br>  1: Register is locked
                                                <br>  Reset type: CPU1. */
            __IOM uint32_t INPUT9SELECT : 1; /*!< [8:8] : Lock bit for INPUT9SELECT Register <br>  0: Register is not
                                                locked                                       <br>  1: Register is locked
                                                <br>  Reset type: CPU1. */
            __IOM uint32_t
                INPUT10SELECT : 1; /*!< [9:9] : Lock bit for INPUT10SELECT Register                             <br>  0:
                                      Register is not locked                                       <br>  1: Register is
                                      locked                                           <br>  Reset type: CPU1. */
            __IOM uint32_t
                INPUT11SELECT : 1; /*!< [10:10] : Lock bit for INPUT11SELECT Register                             <br>
                                      0: Register is not locked                                       <br>  1: Register
                                      is locked                                           <br>  Reset type: CPU1. */
            __IOM uint32_t
                INPUT12SELECT : 1; /*!< [11:11] : Lock bit for INPUT12SELECT Register                             <br>
                                      0: Register is not locked                                       <br>  1: Register
                                      is locked                                           <br>  Reset type: CPU1. */
            __IOM uint32_t
                INPUT13SELECT : 1; /*!< [12:12] : Lock bit for INPUT13SELECT Register                             <br>
                                      0: Register is not locked                                       <br>  1: Register
                                      is locked                                           <br>  Reset type: CPU1. */
            __IOM uint32_t
                INPUT14SELECT : 1; /*!< [13:13] : Lock bit for INPUT14SELECT Register                             <br>
                                      0: Register is not locked                                       <br>  1: Register
                                      is locked                                           <br>  Reset type: CPU1. */
            __IOM uint32_t
                INPUT15SELECT : 1; /*!< [14:14] : Lock bit for INPUT15SELECT Register                             <br>
                                      0: Register is not locked                                       <br>  1: Register
                                      is locked                                           <br>  Reset type: CPU1. */
            __IOM uint32_t
                INPUT16SELECT : 1; /*!< [15:15] : Lock bit for INPUT16SELECT Register                             <br>
                                      0: Register is not locked                                       <br>  1: Register
                                      is locked                                           <br>  Reset type: CPU1. */
            uint32_t RSV_0 : 16;   /*!< [31:16] : reserved. */
        } INPUTSELECTLOCKb;
    };
} INPUT_XBAR_Type;

/*! \brief XBAR register */
typedef struct
{
    union
    {
        __IOM uint32_t XBARFLG1; /*!< 0x00000400 */

        struct
        {
            __IOM uint32_t CMPSS1_CTRIPL    : 1; /*!< [0:0] : CMPSS1_CTRIPL XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t CMPSS1_CTRIPH    : 1; /*!< [1:1] : CMPSS1_CTRIPH XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t CMPSS2_CTRIPL    : 1; /*!< [2:2] : CMPSS2_CTRIPL XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t CMPSS2_CTRIPH    : 1; /*!< [3:3] : CMPSS2_CTRIPH XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t CMPSS3_CTRIPL    : 1; /*!< [4:4] : CMPSS3_CTRIPL XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t CMPSS3_CTRIPH    : 1; /*!< [5:5] : CMPSS3_CTRIPH XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t CMPSS4_CTRIPL    : 1; /*!< [6:6] : CMPSS4_CTRIPL XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t CMPSS4_CTRIPH    : 1; /*!< [7:7] : CMPSS4_CTRIPH XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t CMPSS5_CTRIPL    : 1; /*!< [8:8] : CMPSS5_CTRIPL XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t CMPSS5_CTRIPH    : 1; /*!< [9:9] : CMPSS5_CTRIPH XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t CMPSS6_CTRIPL    : 1; /*!< [10:10] : CMPSS6_CTRIPL XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t CMPSS6_CTRIPH    : 1; /*!< [11:11] : CMPSS6_CTRIPH XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t CMPSS7_CTRIPL    : 1; /*!< [12:12] : CMPSS7_CTRIPL XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t CMPSS7_CTRIPH    : 1; /*!< [13:13] : CMPSS7_CTRIPH XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t CMPSS8_CTRIPL    : 1; /*!< [14:14] : CMPSS8_CTRIPL XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t CMPSS8_CTRIPH    : 1; /*!< [15:15] : CMPSS8_CTRIPH XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t CMPSS1_CTRIPOUTL : 1; /*!< [16:16] : CMPSS1_CTRIPOUTL XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t CMPSS1_CTRIPOUTH : 1; /*!< [17:17] : CMPSS1_CTRIPOUTH XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t CMPSS2_CTRIPOUTL : 1; /*!< [18:18] : CMPSS2_CTRIPOUTL XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t CMPSS2_CTRIPOUTH : 1; /*!< [19:19] : CMPSS2_CTRIPOUTH XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t CMPSS3_CTRIPOUTL : 1; /*!< [20:20] : CMPSS3_CTRIPOUTL XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t CMPSS3_CTRIPOUTH : 1; /*!< [21:21] : CMPSS3_CTRIPOUTH XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t CMPSS4_CTRIPOUTL : 1; /*!< [22:22] : CMPSS4_CTRIPOUTL XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t CMPSS4_CTRIPOUTH : 1; /*!< [23:23] : CMPSS4_CTRIPOUTH XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t CMPSS5_CTRIPOUTL : 1; /*!< [24:24] : CMPSS5_CTRIPOUTL XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t CMPSS5_CTRIPOUTH : 1; /*!< [25:25] : CMPSS5_CTRIPOUTH XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t CMPSS6_CTRIPOUTL : 1; /*!< [26:26] : CMPSS6_CTRIPOUTL XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t CMPSS6_CTRIPOUTH : 1; /*!< [27:27] : CMPSS6_CTRIPOUTH XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t CMPSS7_CTRIPOUTL : 1; /*!< [28:28] : CMPSS7_CTRIPOUTL XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t CMPSS7_CTRIPOUTH : 1; /*!< [29:29] : CMPSS7_CTRIPOUTH XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t CMPSS8_CTRIPOUTL : 1; /*!< [30:30] : CMPSS8_CTRIPOUTL XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t CMPSS8_CTRIPOUTH : 1; /*!< [31:31] : CMPSS8_CTRIPOUTH XBAR Flag <br>  Reset type: CPU1. */
        } XBARFLG1b;
    };

    union
    {
        __IOM uint32_t XBARFLG2; /*!< 0x00000404 */

        struct
        {
            __IOM uint32_t INPUT1 : 1; /*!< [0:0] : INPUT1 XBAR Flag                                               <br>
                                          Reset type: CPU1. */
            __IOM uint32_t INPUT2 : 1; /*!< [1:1] : INPUT2 XBAR Flag                                               <br>
                                          Reset type: CPU1. */
            __IOM uint32_t INPUT3 : 1; /*!< [2:2] : INPUT3 XBAR Flag                                               <br>
                                          Reset type: CPU1. */
            __IOM uint32_t INPUT4 : 1; /*!< [3:3] : INPUT4 XBAR Flag                                               <br>
                                          Reset type: CPU1. */
            __IOM uint32_t INPUT5 : 1; /*!< [4:4] : INPUT5 XBAR Flag                                               <br>
                                          Reset type: CPU1. */
            __IOM uint32_t INPUT6 : 1; /*!< [5:5] : INPUT6 XBAR Flag                                               <br>
                                          Reset type: CPU1. */
            __IOM uint32_t ADCSOCAO : 1; /*!< [6:6] : ADCSOCAO XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t ADCSOCBO : 1; /*!< [7:7] : ADCSOCBO XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t INPUT7 : 1; /*!< [8:8] : INPUT7 XBAR Flag                                               <br>
                                          Reset type: CPU1. */
            __IOM uint32_t INPUT8 : 1; /*!< [9:9] : INPUT8 XBAR Flag                                               <br>
                                          Reset type: CPU1. */
            __IOM uint32_t INPUT9     : 1; /*!< [10:10] : INPUT9 XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t INPUT10    : 1; /*!< [11:11] : INPUT10 XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t INPUT11    : 1; /*!< [12:12] : INPUT11 XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t INPUT12    : 1; /*!< [13:13] : INPUT12 XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t INPUT13    : 1; /*!< [14:14] : INPUT13 XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t INPUT14    : 1; /*!< [15:15] : INPUT14 XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t ECAP1_OUT  : 1; /*!< [16:16] : ECAP1_OUT XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t ECAP2_OUT  : 1; /*!< [17:17] : ECAP2_OUT XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t ECAP3_OUT  : 1; /*!< [18:18] : ECAP3_OUT XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t ECAP4_OUT  : 1; /*!< [19:19] : ECAP4_OUT XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t ECAP5_OUT  : 1; /*!< [20:20] : ECAP5_OUT XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t ECAP6_OUT  : 1; /*!< [21:21] : ECAP6_OUT XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t EXTSYNCOUT : 1; /*!< [22:22] : EXTSYNCOUT XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t ADCAEVT1   : 1; /*!< [23:23] : ADCAEVT1 XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t ADCAEVT2   : 1; /*!< [24:24] : ADCAEVT2 XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t ADCAEVT3   : 1; /*!< [25:25] : ADCAEVT3 XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t ADCAEVT4   : 1; /*!< [26:26] : ADCAEVT4 XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t ADCBEVT1   : 1; /*!< [27:27] : ADCBEVT1 XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t ADCBEVT2   : 1; /*!< [28:28] : ADCBEVT2 XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t ADCBEVT3   : 1; /*!< [29:29] : ADCBEVT3 XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t ADCBEVT4   : 1; /*!< [30:30] : ADCBEVT4 XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t ADCCEVT1   : 1; /*!< [31:31] : ADCCEVT1 XBAR Flag <br>  Reset type: CPU1. */
        } XBARFLG2b;
    };

    union
    {
        __IOM uint32_t XBARFLG3; /*!< 0x00000408 */

        struct
        {
            __IOM uint32_t ADCCEVT2 : 1; /*!< [0:0] : This register is used to Flag the inputs of the X-Bars to provide
                                            software knowledge of the input sources which got triggered. */
            __IOM uint32_t ADCCEVT3 : 1; /*!< [1:1] : This register is used to Flag the inputs of the X-Bars to provide
                                            software knowledge of the input sources which got triggered. */
            __IOM uint32_t ADCCEVT4 : 1; /*!< [2:2] : This register is used to Flag the inputs of the X-Bars to provide
                                            software knowledge of the input sources which got triggered. */
            __IOM uint32_t ADCDEVT1 : 1; /*!< [3:3] : This register is used to Flag the inputs of the X-Bars to provide
                                            software knowledge of the input sources which got triggered. */
            __IOM uint32_t ADCDEVT2 : 1; /*!< [4:4] : This register is used to Flag the inputs of the X-Bars to provide
                                            software knowledge of the input sources which got triggered. */
            __IOM uint32_t ADCDEVT3 : 1; /*!< [5:5] : This register is used to Flag the inputs of the X-Bars to provide
                                            software knowledge of the input sources which got triggered. */
            __IOM uint32_t ADCDEVT4 : 1; /*!< [6:6] : This register is used to Flag the inputs of the X-Bars to provide
                                            software knowledge of the input sources which got triggered. */
            __IOM uint32_t SD1FLT1_COMPL : 1; /*!< [7:7] : This register is used to Flag the inputs of the X-Bars to
                                                 provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t SD1FLT1_COMPH : 1; /*!< [8:8] : This register is used to Flag the inputs of the X-Bars to
                                                 provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t SD1FLT2_COMPL : 1; /*!< [9:9] : This register is used to Flag the inputs of the X-Bars to
                                                 provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t SD1FLT2_COMPH : 1; /*!< [10:10] : This register is used to Flag the inputs of the X-Bars to
                                                 provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t SD1FLT3_COMPL : 1; /*!< [11:11] : This register is used to Flag the inputs of the X-Bars to
                                                 provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t SD1FLT3_COMPH : 1; /*!< [12:12] : This register is used to Flag the inputs of the X-Bars to
                                                 provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t SD1FLT4_COMPL : 1; /*!< [13:13] : This register is used to Flag the inputs of the X-Bars to
                                                 provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t SD1FLT4_COMPH : 1; /*!< [14:14] : This register is used to Flag the inputs of the X-Bars to
                                                 provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t SD2FLT1_COMPL : 1; /*!< [15:15] : This register is used to Flag the inputs of the X-Bars to
                                                 provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t SD2FLT1_COMPH : 1; /*!< [16:16] : This register is used to Flag the inputs of the X-Bars to
                                                 provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t SD2FLT2_COMPL : 1; /*!< [17:17] : This register is used to Flag the inputs of the X-Bars to
                                                 provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t SD2FLT2_COMPH : 1; /*!< [18:18] : This register is used to Flag the inputs of the X-Bars to
                                                 provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t SD2FLT3_COMPL : 1; /*!< [19:19] : This register is used to Flag the inputs of the X-Bars to
                                                 provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t SD2FLT3_COMPH : 1; /*!< [20:20] : This register is used to Flag the inputs of the X-Bars to
                                                 provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t SD2FLT4_COMPL : 1; /*!< [21:21] : This register is used to Flag the inputs of the X-Bars to
                                                 provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t SD2FLT4_COMPH : 1; /*!< [22:22] : This register is used to Flag the inputs of the X-Bars to
                                                 provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t ECAP7_OUT : 1;     /*!< [23:23] : This register is used to Flag the inputs of the X-Bars to
                                                 provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t SD1FLT1_COMPZ : 1; /*!< [24:24] : This register is used to Flag the inputs of the X-Bars to
                                                 provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t SD1FLT1_DRINT : 1; /*!< [25:25] : This register is used to Flag the inputs of the X-Bars to
                                                 provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t SD1FLT2_COMPZ : 1; /*!< [26:26] : This register is used to Flag the inputs of the X-Bars to
                                                 provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t SD1FLT2_DRINT : 1; /*!< [27:27] : This register is used to Flag the inputs of the X-Bars to
                                                 provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t SD1FLT3_COMPZ : 1; /*!< [28:28] : This register is used to Flag the inputs of the X-Bars to
                                                 provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t SD1FLT3_DRINT : 1; /*!< [29:29] : This register is used to Flag the inputs of the X-Bars to
                                                 provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t SD1FLT4_COMPZ : 1; /*!< [30:30] : This register is used to Flag the inputs of the X-Bars to
                                                 provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t SD1FLT4_DRINT : 1; /*!< [31:31] : This register is used to Flag the inputs of the X-Bars to
                                                 provide software knowledge of the input sources which got triggered. */
        } XBARFLG3b;
    };

    union
    {
        __IOM uint32_t XBARFLG4; /*!< 0x0000040c */

        struct
        {
            __IOM uint32_t SD2FLT1_COMPZ : 1; /*!< [0:0] : This register is used to Flag the inputs of the X-Bars to
                                                 provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t SD2FLT1_DRINT : 1; /*!< [1:1] : This register is used to Flag the inputs of the X-Bars to
                                                 provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t SD2FLT2_COMPZ : 1; /*!< [2:2] : This register is used to Flag the inputs of the X-Bars to
                                                 provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t SD2FLT2_DRINT : 1; /*!< [3:3] : This register is used to Flag the inputs of the X-Bars to
                                                 provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t SD2FLT3_COMPZ : 1; /*!< [4:4] : This register is used to Flag the inputs of the X-Bars to
                                                 provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t SD2FLT3_DRINT : 1; /*!< [5:5] : This register is used to Flag the inputs of the X-Bars to
                                                 provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t SD2FLT4_COMPZ : 1; /*!< [6:6] : This register is used to Flag the inputs of the X-Bars to
                                                 provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t SD2FLT4_DRINT : 1; /*!< [7:7] : This register is used to Flag the inputs of the X-Bars to
                                                 provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t EMAC_PPS0 : 1; /*!< [8:8] : This register is used to Flag the inputs of the X-Bars to provide
                                             software knowledge of the input sources which got triggered. */
            __IOM uint32_t MCANA_FEVT0 : 1; /*!< [9:9] : This register is used to Flag the inputs of the X-Bars to
                                               provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t MCANA_FEVT1 : 1; /*!< [10:10] : This register is used to Flag the inputs of the X-Bars to
                                               provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t MCANA_FEVT2 : 1; /*!< [11:11] : This register is used to Flag the inputs of the X-Bars to
                                               provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t CLB7_OUT4 : 1;   /*!< [12:12] : This register is used to Flag the inputs of the X-Bars to
                                               provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t CLB7_OUT5 : 1;   /*!< [13:13] : This register is used to Flag the inputs of the X-Bars to
                                               provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t CLB8_OUT4 : 1;   /*!< [14:14] : This register is used to Flag the inputs of the X-Bars to
                                               provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t CLB8_OUT5 : 1;   /*!< [15:15] : This register is used to Flag the inputs of the X-Bars to
                                               provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t CLB1_OUT4 : 1;   /*!< [16:16] : This register is used to Flag the inputs of the X-Bars to
                                               provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t CLB1_OUT5 : 1;   /*!< [17:17] : This register is used to Flag the inputs of the X-Bars to
                                               provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t CLB2_OUT4 : 1;   /*!< [18:18] : This register is used to Flag the inputs of the X-Bars to
                                               provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t CLB2_OUT5 : 1;   /*!< [19:19] : This register is used to Flag the inputs of the X-Bars to
                                               provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t CLB3_OUT4 : 1;   /*!< [20:20] : This register is used to Flag the inputs of the X-Bars to
                                               provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t CLB3_OUT5 : 1;   /*!< [21:21] : This register is used to Flag the inputs of the X-Bars to
                                               provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t CLB4_OUT4 : 1;   /*!< [22:22] : This register is used to Flag the inputs of the X-Bars to
                                               provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t CLB4_OUT5 : 1;   /*!< [23:23] : This register is used to Flag the inputs of the X-Bars to
                                               provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t CLB5_OUT4 : 1;   /*!< [24:24] : This register is used to Flag the inputs of the X-Bars to
                                               provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t CLB5_OUT5 : 1;   /*!< [25:25] : This register is used to Flag the inputs of the X-Bars to
                                               provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t CLB6_OUT4 : 1;   /*!< [26:26] : This register is used to Flag the inputs of the X-Bars to
                                               provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t CLB6_OUT5 : 1;   /*!< [27:27] : This register is used to Flag the inputs of the X-Bars to
                                               provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t
                ERRORSTS_ERROR : 1; /*!< [28:28] : This register is used to Flag the inputs of the X-Bars to provide
                                       software knowledge of the input sources which got triggered. */
            __IOM uint32_t ECATSYNC0 : 1; /*!< [29:29] : This register is used to Flag the inputs of the X-Bars to
                                             provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t ECATSYNC1 : 1; /*!< [30:30] : This register is used to Flag the inputs of the X-Bars to
                                             provide software knowledge of the input sources which got triggered. */
            __IOM uint32_t CLAHALT : 1; /*!< [31:31] : This register is used to Flag the inputs of the X-Bars to provide
                                           software knowledge of the input sources which got triggered. */
        } XBARFLG4b;
    };

    union
    {
        __OM uint32_t XBARCLR1; /*!< 0x00000410 */

        struct
        {
            __OM uint32_t CMPSS1_CTRIPL : 1; /*!< [0:0] : CMPSS1_CTRIPL XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t CMPSS1_CTRIPH : 1; /*!< [1:1] : CMPSS1_CTRIPH XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t CMPSS2_CTRIPL : 1; /*!< [2:2] : CMPSS2_CTRIPL XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t CMPSS2_CTRIPH : 1; /*!< [3:3] : CMPSS2_CTRIPH XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t CMPSS3_CTRIPL : 1; /*!< [4:4] : CMPSS3_CTRIPL XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t CMPSS3_CTRIPH : 1; /*!< [5:5] : CMPSS3_CTRIPH XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t CMPSS4_CTRIPL : 1; /*!< [6:6] : CMPSS4_CTRIPL XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t CMPSS4_CTRIPH : 1; /*!< [7:7] : CMPSS4_CTRIPH XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t CMPSS5_CTRIPL : 1; /*!< [8:8] : CMPSS5_CTRIPL XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t CMPSS5_CTRIPH : 1; /*!< [9:9] : CMPSS5_CTRIPH XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t CMPSS6_CTRIPL : 1; /*!< [10:10] : CMPSS6_CTRIPL XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t CMPSS6_CTRIPH : 1; /*!< [11:11] : CMPSS6_CTRIPH XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t CMPSS7_CTRIPL : 1; /*!< [12:12] : CMPSS7_CTRIPL XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t CMPSS7_CTRIPH : 1; /*!< [13:13] : CMPSS7_CTRIPH XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t CMPSS8_CTRIPL : 1; /*!< [14:14] : CMPSS8_CTRIPL XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t CMPSS8_CTRIPH : 1; /*!< [15:15] : CMPSS8_CTRIPH XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t
                CMPSS1_CTRIPOUTL : 1; /*!< [16:16] : CMPSS1_CTRIPOUTL XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t
                CMPSS1_CTRIPOUTH : 1; /*!< [17:17] : CMPSS1_CTRIPOUTH XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t
                CMPSS2_CTRIPOUTL : 1; /*!< [18:18] : CMPSS2_CTRIPOUTL XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t
                CMPSS2_CTRIPOUTH : 1; /*!< [19:19] : CMPSS2_CTRIPOUTH XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t
                CMPSS3_CTRIPOUTL : 1; /*!< [20:20] : CMPSS3_CTRIPOUTL XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t
                CMPSS3_CTRIPOUTH : 1; /*!< [21:21] : CMPSS3_CTRIPOUTH XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t
                CMPSS4_CTRIPOUTL : 1; /*!< [22:22] : CMPSS4_CTRIPOUTL XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t
                CMPSS4_CTRIPOUTH : 1; /*!< [23:23] : CMPSS4_CTRIPOUTH XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t
                CMPSS5_CTRIPOUTL : 1; /*!< [24:24] : CMPSS5_CTRIPOUTL XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t
                CMPSS5_CTRIPOUTH : 1; /*!< [25:25] : CMPSS5_CTRIPOUTH XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t
                CMPSS6_CTRIPOUTL : 1; /*!< [26:26] : CMPSS6_CTRIPOUTL XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t
                CMPSS6_CTRIPOUTH : 1; /*!< [27:27] : CMPSS6_CTRIPOUTH XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t
                CMPSS7_CTRIPOUTL : 1; /*!< [28:28] : CMPSS7_CTRIPOUTL XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t
                CMPSS7_CTRIPOUTH : 1; /*!< [29:29] : CMPSS7_CTRIPOUTH XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t
                CMPSS8_CTRIPOUTL : 1; /*!< [30:30] : CMPSS8_CTRIPOUTL XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t
                CMPSS8_CTRIPOUTH : 1; /*!< [31:31] : CMPSS8_CTRIPOUTH XBAR Flag Clear <br>  Reset type: CPU1. */
        } XBARCLR1b;
    };

    union
    {
        __OM uint32_t XBARCLR2; /*!< 0x00000414 */

        struct
        {
            __OM uint32_t INPUT1 : 1;   /*!< [0:0] : INPUT1 XBAR Flag Clear                                         <br>
                                           Reset type: CPU1. */
            __OM uint32_t INPUT2 : 1;   /*!< [1:1] : INPUT2 XBAR Flag Clear                                         <br>
                                           Reset type: CPU1. */
            __OM uint32_t INPUT3 : 1;   /*!< [2:2] : INPUT3 XBAR Flag Clear                                         <br>
                                           Reset type: CPU1. */
            __OM uint32_t INPUT4 : 1;   /*!< [3:3] : INPUT4 XBAR Flag Clear                                         <br>
                                           Reset type: CPU1. */
            __OM uint32_t INPUT5 : 1;   /*!< [4:4] : INPUT5 XBAR Flag Clear                                         <br>
                                           Reset type: CPU1. */
            __OM uint32_t INPUT6 : 1;   /*!< [5:5] : INPUT7 XBAR Flag Clear                                         <br>
                                           Reset type: CPU1. */
            __OM uint32_t ADCSOCAO : 1; /*!< [6:6] : ADCSOCAO XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t ADCSOCBO : 1; /*!< [7:7] : ADCSOCBO XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t INPUT7   : 1; /*!< [8:8] : INPUT7 XBAR Flag Clear                                         <br>
                                           Reset type: CPU1. */
            __OM uint32_t INPUT8 : 1;   /*!< [9:9] : INPUT8 XBAR Flag Clear                                         <br>
                                           Reset type: CPU1. */
            __OM uint32_t INPUT9     : 1; /*!< [10:10] : INPUT9 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t INPUT10    : 1; /*!< [11:11] : INPUT10 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t INPUT11    : 1; /*!< [12:12] : INPUT11 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t INPUT12    : 1; /*!< [13:13] : INPUT12 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t INPUT13    : 1; /*!< [14:14] : INPUT13 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t INPUT14    : 1; /*!< [15:15] : INPUT14 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t ECAP1_OUT  : 1; /*!< [16:16] : ECAP1_OUT XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t ECAP2_OUT  : 1; /*!< [17:17] : ECAP2_OUT XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t ECAP3_OUT  : 1; /*!< [18:18] : ECAP3_OUT XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t ECAP4_OUT  : 1; /*!< [19:19] : ECAP4_OUT XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t ECAP5_OUT  : 1; /*!< [20:20] : ECAP5_OUT XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t ECAP6_OUT  : 1; /*!< [21:21] : ECAP6_OUT XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t EXTSYNCOUT : 1; /*!< [22:22] : EXTSYNCOUT XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t ADCAEVT1   : 1; /*!< [23:23] : ADCAEVT1 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t ADCAEVT2   : 1; /*!< [24:24] : ADCAEVT2 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t ADCAEVT3   : 1; /*!< [25:25] : ADCAEVT3 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t ADCAEVT4   : 1; /*!< [26:26] : ADCAEVT4 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t ADCBEVT1   : 1; /*!< [27:27] : ADCBEVT1 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t ADCBEVT2   : 1; /*!< [28:28] : ADCBEVT2 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t ADCBEVT3   : 1; /*!< [29:29] : ADCBEVT3 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t ADCBEVT4   : 1; /*!< [30:30] : ADCBEVT4 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t ADCCEVT1   : 1; /*!< [31:31] : ADCCEVT1 XBAR Flag Clear <br>  Reset type: CPU1. */
        } XBARCLR2b;
    };

    union
    {
        __OM uint32_t XBARCLR3; /*!< 0x00000418 */

        struct
        {
            __OM uint32_t ADCCEVT2      : 1; /*!< [0:0] : ADCCEVT2 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t ADCCEVT3      : 1; /*!< [1:1] : ADCCEVT3 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t ADCCEVT4      : 1; /*!< [2:2] : ADCCEVT4 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t ADCDEVT1      : 1; /*!< [3:3] : ADCDEVT1 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t ADCDEVT2      : 1; /*!< [4:4] : ADCDEVT2 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t ADCDEVT3      : 1; /*!< [5:5] : ADCDEVT3 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t ADCDEVT4      : 1; /*!< [6:6] : ADCDEVT4 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD1FLT1_COMPL : 1; /*!< [7:7] : SD1FLT1_COMPL XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD1FLT1_COMPH : 1; /*!< [8:8] : SD1FLT1_COMPH XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD1FLT2_COMPL : 1; /*!< [9:9] : SD1FLT2_COMPL XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD1FLT2_COMPH : 1; /*!< [10:10] : SD1FLT2_COMPH XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD1FLT3_COMPL : 1; /*!< [11:11] : SD1FLT3_COMPL XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD1FLT3_COMPH : 1; /*!< [12:12] : SD1FLT3_COMPH XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD1FLT4_COMPL : 1; /*!< [13:13] : SD1FLT4_COMPL XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD1FLT4_COMPH : 1; /*!< [14:14] : SD1FLT4_COMPH XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD2FLT1_COMPL : 1; /*!< [15:15] : SD2FLT1_COMPL XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD2FLT1_COMPH : 1; /*!< [16:16] : SD2FLT1_COMPH XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD2FLT2_COMPL : 1; /*!< [17:17] : SD2FLT2_COMPL XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD2FLT2_COMPH : 1; /*!< [18:18] : SD2FLT2_COMPH XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD2FLT3_COMPL : 1; /*!< [19:19] : SD2FLT3_COMPL XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD2FLT3_COMPH : 1; /*!< [20:20] : SD2FLT3_COMPH XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD2FLT4_COMPL : 1; /*!< [21:21] : SD2FLT4_COMPL XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD2FLT4_COMPH : 1; /*!< [22:22] : SD2FLT4_COMPH XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t ECAP7_OUT     : 1; /*!< [23:23] : ECAP7_OUT XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD1FLT1_COMPZ : 1; /*!< [24:24] : SD1FLT1_COMPZ XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD1FLT1_DRINT : 1; /*!< [25:25] : SD1FLT1_DRINT XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD1FLT2_COMPZ : 1; /*!< [26:26] : SD1FLT2_COMPZ XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD1FLT2_DRINT : 1; /*!< [27:27] : SD1FLT2_DRINT XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD1FLT3_COMPZ : 1; /*!< [28:28] : SD1FLT3_COMPZ XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD1FLT3_DRINT : 1; /*!< [29:29] : SD1FLT3_DRINT XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD1FLT4_COMPZ : 1; /*!< [30:30] : SD1FLT4_COMPZ XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD1FLT4_DRINT : 1; /*!< [31:31] : SD1FLT4_DRINT XBAR Flag Clear <br>  Reset type: CPU1. */
        } XBARCLR3b;
    };

    union
    {
        __OM uint32_t XBARCLR4; /*!< 0x0000041c */

        struct
        {
            __OM uint32_t SD2FLT1_COMPZ  : 1; /*!< [0:0] : SD2FLT1_COMPZ XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD2FLT1_DRINT  : 1; /*!< [1:1] : SD2FLT1_DRINT XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD2FLT2_COMPZ  : 1; /*!< [2:2] : SD2FLT2_COMPZ XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD2FLT2_DRINT  : 1; /*!< [3:3] : SD2FLT2_DRINT XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD2FLT3_COMPZ  : 1; /*!< [4:4] : SD2FLT3_COMPZ XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD2FLT3_DRINT  : 1; /*!< [5:5] : SD2FLT3_DRINT XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD2FLT4_COMPZ  : 1; /*!< [6:6] : SD2FLT4_COMPZ XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD2FLT4_DRINT  : 1; /*!< [7:7] : SD2FLT4_DRINT XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t EMAC_PPS0      : 1; /*!< [8:8] : EMAC_PPS0 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t MCANA_FEVT0    : 1; /*!< [9:9] : MCANA_FEVT0 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t MCANA_FEVT1    : 1; /*!< [10:10] : MCANA_FEVT1 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t MCANA_FEVT2    : 1; /*!< [11:11] : MCANA_FEVT2 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t CLB7_OUT4      : 1; /*!< [12:12] : CLB7_OUT4 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t CLB7_OUT5      : 1; /*!< [13:13] : CLB7_OUT5 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t CLB8_OUT4      : 1; /*!< [14:14] : CLB8_OUT4 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t CLB8_OUT5      : 1; /*!< [15:15] : CLB8_OUT5 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t CLB1_OUT4      : 1; /*!< [16:16] : CLB1_OUT4 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t CLB1_OUT5      : 1; /*!< [17:17] : CLB1_OUT5 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t CLB2_OUT4      : 1; /*!< [18:18] : CLB2_OUT4 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t CLB2_OUT5      : 1; /*!< [19:19] : CLB2_OUT5 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t CLB3_OUT4      : 1; /*!< [20:20] : CLB3_OUT4 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t CLB3_OUT5      : 1; /*!< [21:21] : CLB3_OUT5 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t CLB4_OUT4      : 1; /*!< [22:22] : CLB4_OUT4 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t CLB4_OUT5      : 1; /*!< [23:23] : CLB4_OUT5 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t CLB5_OUT4      : 1; /*!< [24:24] : CLB5_OUT4 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t CLB5_OUT5      : 1; /*!< [25:25] : CLB5_OUT5 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t CLB6_OUT4      : 1; /*!< [26:26] : CLB6_OUT4 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t CLB6_OUT5      : 1; /*!< [27:27] : CLB6_OUT5 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t ERRORSTS_ERROR : 1; /*!< [28:28] : ERRORSTS_ERROR XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t ECATSYNC0      : 1; /*!< [29:29] : ECATSYNC0 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t ECATSYNC1      : 1; /*!< [30:30] : ECATSYNC1 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t CLAHALT        : 1; /*!< [31:31] : CLAHALT XBAR Flag Clear <br>  Reset type: CPU1. */
        } XBARCLR4b;
    };

    union
    {
        __IOM uint32_t XBARFLG5; /*!< 0x00000420 */

        struct
        {
            __IOM uint32_t SD1FLT1_COMPL2   : 1; /*!< [0:0] : SD1FLT1_COMPL2 XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t SD1FLT1_COMPH2   : 1; /*!< [1:1] : SD1FLT1_COMPH2 XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t SD1FLT2_COMPL2   : 1; /*!< [2:2] : SD1FLT2_COMPL2 XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t SD1FLT2_COMPH2   : 1; /*!< [3:3] : SD1FLT2_COMPH2 XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t SD1FLT3_COMPL2   : 1; /*!< [4:4] : SD1FLT3_COMPL2 XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t SD1FLT3_COMPH2   : 1; /*!< [5:5] : SD1FLT3_COMPH2 XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t SD1FLT4_COMPL2   : 1; /*!< [6:6] : SD1FLT4_COMPL2 XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t SD1FLT4_COMPH2   : 1; /*!< [7:7] : SD1FLT4_COMPH2 XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t SD2FLT1_COMPL2   : 1; /*!< [8:8] : SD2FLT1_COMPL2 XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t SD2FLT1_COMPH2   : 1; /*!< [9:9] : SD2FLT1_COMPH2 XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t SD2FLT2_COMPL2   : 1; /*!< [10:10] : SD2FLT2_COMPL2 XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t SD2FLT2_COMPH2   : 1; /*!< [11:11] : SD2FLT2_COMPH2 XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t SD2FLT3_COMPL2   : 1; /*!< [12:12] : SD2FLT3_COMPL2 XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t SD2FLT3_COMPH2   : 1; /*!< [13:13] : SD2FLT3_COMPH2 XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t SD2FLT4_COMPL2   : 1; /*!< [14:14] : SD2FLT4_COMPL2 XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t SD2FLT4_COMPH2   : 1; /*!< [15:15] : SD2FLT4_COMPH2 XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t SD1FLT1_CEVT2OUT : 1; /*!< [16:16] : SD1FLT1_CEVT2OUT XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t SD1FLT1_CEVT1OUT : 1; /*!< [17:17] : SD1FLT1_CEVT1OUT XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t SD1FLT2_CEVT2OUT : 1; /*!< [18:18] : SD1FLT2_CEVT2OUT XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t SD1FLT2_CEVT1OUT : 1; /*!< [19:19] : SD1FLT2_CEVT1OUT XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t SD1FLT3_CEVT2OUT : 1; /*!< [20:20] : SD1FLT3_CEVT2OUT XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t SD1FLT3_CEVT1OUT : 1; /*!< [21:21] : SD1FLT3_CEVT1OUT XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t SD1FLT4_CEVT2OUT : 1; /*!< [22:22] : SD1FLT4_CEVT2OUT XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t SD1FLT4_CEVT1OUT : 1; /*!< [23:23] : SD1FLT4_CEVT1OUT XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t SD2FLT1_CEVT2OUT : 1; /*!< [24:24] : SD2FLT1_CEVT2OUT XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t SD2FLT1_CEVT1OUT : 1; /*!< [25:25] : SD2FLT1_CEVT1OUT XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t SD2FLT2_CEVT2OUT : 1; /*!< [26:26] : SD2FLT2_CEVT2OUT XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t SD2FLT2_CEVT1OUT : 1; /*!< [27:27] : SD2FLT2_CEVT1OUT XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t SD2FLT3_CEVT2OUT : 1; /*!< [28:28] : SD2FLT3_CEVT2OUT XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t SD2FLT3_CEVT1OUT : 1; /*!< [29:29] : SD2FLT3_CEVT1OUT XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t SD2FLT4_CEVT2OUT : 1; /*!< [30:30] : SD2FLT4_CEVT2OUT XBAR Flag <br>  Reset type: CPU1. */
            __IOM uint32_t SD2FLT4_CEVT1OUT : 1; /*!< [31:31] : SD2FLT4_CEVT1OUT XBAR Flag <br>  Reset type: CPU1. */
        } XBARFLG5b;
    };

    uint8_t RSV_0X424[12]; /*!< 0x00000424~0x0000042f : reserved */

    union
    {
        __OM uint32_t XBARCLR5; /*!< 0x00000430 */

        struct
        {
            __OM uint32_t SD1FLT1_COMPL2 : 1; /*!< [0:0] : SD1FLT1_COMPL2 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD1FLT1_COMPH2 : 1; /*!< [1:1] : SD1FLT1_COMPH2 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD1FLT2_COMPL2 : 1; /*!< [2:2] : SD1FLT2_COMPL2 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD1FLT2_COMPH2 : 1; /*!< [3:3] : SD1FLT2_COMPH2 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD1FLT3_COMPL2 : 1; /*!< [4:4] : SD1FLT3_COMPL2 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD1FLT3_COMPH2 : 1; /*!< [5:5] : SD1FLT3_COMPH2 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD1FLT4_COMPL2 : 1; /*!< [6:6] : SD1FLT4_COMPL2 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD1FLT4_COMPH2 : 1; /*!< [7:7] : SD1FLT4_COMPH2 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD2FLT1_COMPL2 : 1; /*!< [8:8] : SD2FLT1_COMPL2 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD2FLT1_COMPH2 : 1; /*!< [9:9] : SD2FLT1_COMPH2 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD2FLT2_COMPL2 : 1; /*!< [10:10] : SD2FLT2_COMPL2 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD2FLT2_COMPH2 : 1; /*!< [11:11] : SD2FLT2_COMPH2 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD2FLT3_COMPL2 : 1; /*!< [12:12] : SD2FLT3_COMPL2 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD2FLT3_COMPH2 : 1; /*!< [13:13] : SD2FLT3_COMPH2 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD2FLT4_COMPL2 : 1; /*!< [14:14] : SD2FLT4_COMPL2 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t SD2FLT4_COMPH2 : 1; /*!< [15:15] : SD2FLT4_COMPH2 XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t
                SD1FLT1_CEVT2OUT : 1; /*!< [16:16] : SD1FLT1_CEVT2OUT XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t
                SD1FLT1_CEVT1OUT : 1; /*!< [17:17] : SD1FLT1_CEVT1OUT XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t
                SD1FLT2_CEVT2OUT : 1; /*!< [18:18] : SD1FLT2_CEVT2OUT XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t
                SD1FLT2_CEVT1OUT : 1; /*!< [19:19] : SD1FLT2_CEVT1OUT XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t
                SD1FLT3_CEVT2OUT : 1; /*!< [20:20] : SD1FLT3_CEVT2OUT XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t
                SD1FLT3_CEVT1OUT : 1; /*!< [21:21] : SD1FLT3_CEVT1OUT XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t
                SD1FLT4_CEVT2OUT : 1; /*!< [22:22] : SD1FLT4_CEVT2OUT XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t
                SD1FLT4_CEVT1OUT : 1; /*!< [23:23] : SD1FLT4_CEVT1OUT XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t
                SD2FLT1_CEVT2OUT : 1; /*!< [24:24] : SD2FLT1_CEVT2OUT XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t
                SD2FLT1_CEVT1OUT : 1; /*!< [25:25] : SD2FLT1_CEVT1OUT XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t
                SD2FLT2_CEVT2OUT : 1; /*!< [26:26] : SD2FLT2_CEVT2OUT XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t
                SD2FLT2_CEVT1OUT : 1; /*!< [27:27] : SD2FLT2_CEVT1OUT XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t
                SD2FLT3_CEVT2OUT : 1; /*!< [28:28] : SD2FLT3_CEVT2OUT XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t
                SD2FLT3_CEVT1OUT : 1; /*!< [29:29] : SD2FLT3_CEVT1OUT XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t
                SD2FLT4_CEVT2OUT : 1; /*!< [30:30] : SD2FLT4_CEVT2OUT XBAR Flag Clear <br>  Reset type: CPU1. */
            __OM uint32_t
                SD2FLT4_CEVT1OUT : 1; /*!< [31:31] : SD2FLT4_CEVT1OUT XBAR Flag Clear <br>  Reset type: CPU1. */
        } XBARCLR5b;
    };

    uint8_t RSV_0X434[76]; /*!< 0x00000434~0x0000047f : reserved */

    union
    {
        __IOM uint32_t XBARMISC; /*!< 0x00000480 */

        struct
        {
            __IOM uint32_t MUXCFG_SWITCH : 1; /*!< [0:0] : 0: switch to type 8, MuxCfg Input <br>  1: switch to type 7,
                                                 MuxCfg Input                               <br>. */
            uint32_t RSV_0 : 31;              /*!< [31:1] : reserved. */
        } XBARMISCb;
    };
} XBAR_Type;

/*! \brief EPWM_XBAR register */
typedef struct
{
    struct
    {
        union
        {
            __IOM uint32_t MUX0TO15CFG; /*!< 0x00000c00 */

            struct
            {
                __IOM uint32_t MUX0  : 2; /*!< [1:0] : Select Bits for TRIP4 MUX0: <br>  00 : Select . */
                __IOM uint32_t MUX1  : 2; /*!< [3:2] : Select Bits for TRIP4 MUX14: <br>  00 : Select . */
                __IOM uint32_t MUX2  : 2; /*!< [5:4] : Select Bits for TRIP4 MUX2: <br>  00 : Select . */
                __IOM uint32_t MUX3  : 2; /*!< [7:6] : Select Bits for TRIP4 MUX3: <br>  00 : Select . */
                __IOM uint32_t MUX4  : 2; /*!< [9:8] : Select Bits for TRIP4 MUX4: <br>  00 : Select . */
                __IOM uint32_t MUX5  : 2; /*!< [11:10] : Select Bits for TRIP4 MUX5: <br>  00 : Select . */
                __IOM uint32_t MUX6  : 2; /*!< [13:12] : Select Bits for TRIP4 MUX6: <br>  00 : Select . */
                __IOM uint32_t MUX7  : 2; /*!< [15:14] : Select Bits for TRIP4 MUX7: <br>  00 : Select . */
                __IOM uint32_t MUX8  : 2; /*!< [17:16] : Select Bits for TRIP4 MUX8: <br>  00 : Select . */
                __IOM uint32_t MUX9  : 2; /*!< [19:18] : Select Bits for TRIP4 MUX9: <br>  00 : Select . */
                __IOM uint32_t MUX10 : 2; /*!< [21:20] : Select Bits for TRIP4 MUX10: <br>  00 : Select . */
                __IOM uint32_t MUX11 : 2; /*!< [23:22] : Select Bits for TRIP4 MUX11: <br>  00 : Select . */
                __IOM uint32_t MUX12 : 2; /*!< [25:24] : Select Bits for TRIP4 MUX12: <br>  00 : Select . */
                __IOM uint32_t MUX13 : 2; /*!< [27:26] : Select Bits for TRIP4 MUX13: <br>  00 : Select . */
                __IOM uint32_t MUX14 : 2; /*!< [29:28] : Select Bits for TRIP4 MUX14: <br>  00 : Select . */
                __IOM uint32_t MUX15 : 2; /*!< [31:30] : Select Bits for TRIP4 Mux15: <br>  00 : Select . */
            } MUX0TO15CFGb;
        };

        union
        {
            __IOM uint32_t MUX16TO31CFG; /*!< 0x00000c04 */

            struct
            {
                __IOM uint32_t MUX16 : 2; /*!< [1:0] : Select Bits for TRIP4 MUX16: <br>  00 : Select . */
                __IOM uint32_t MUX17 : 2; /*!< [3:2] : Select Bits for TRIP4 MUX17: <br>  00 : Select . */
                __IOM uint32_t MUX18 : 2; /*!< [5:4] : Select Bits for TRIP4 MUX18: <br>  00 : Select . */
                __IOM uint32_t MUX19 : 2; /*!< [7:6] : Select Bits for TRIP4 MUX19: <br>  00 : Select . */
                __IOM uint32_t MUX20 : 2; /*!< [9:8] : Select Bits for TRIP4 MUX20: <br>  00 : Select . */
                __IOM uint32_t MUX21 : 2; /*!< [11:10] : Select Bits for TRIP4 MUX21: <br>  00 : Select . */
                __IOM uint32_t MUX22 : 2; /*!< [13:12] : Select Bits for TRIP4 MUX22: <br>  00 : Select . */
                __IOM uint32_t MUX23 : 2; /*!< [15:14] : Select Bits for TRIP4 MUX23: <br>  00 : Select . */
                __IOM uint32_t MUX24 : 2; /*!< [17:16] : Select Bits for TRIP4 MUX24: <br>  00 : Select . */
                __IOM uint32_t MUX25 : 2; /*!< [19:18] : Select Bits for TRIP4 MUX25: <br>  00 : Select . */
                __IOM uint32_t MUX26 : 2; /*!< [21:20] : Select Bits for TRIP4 MUX26: <br>  00 : Select . */
                __IOM uint32_t MUX27 : 2; /*!< [23:22] : Select Bits for TRIP4 MUX27: <br>  00 : Select . */
                __IOM uint32_t MUX28 : 2; /*!< [25:24] : Select Bits for TRIP4 MUX28: <br>  00 : Select . */
                __IOM uint32_t MUX29 : 2; /*!< [27:26] : Select Bits for TRIP4 MUX29: <br>  00 : Select . */
                __IOM uint32_t MUX30 : 2; /*!< [29:28] : Select Bits for TRIP4 MUX30: <br>  00 : Select . */
                __IOM uint32_t MUX31 : 2; /*!< [31:30] : Select Bits for TRIP4 MUX31: <br>  00 : Select . */
            } MUX16TO31CFGb;
        };
    } TRIPMUX[8]; /*!< 0x00000c00 + 0x8 * n : TRIP mux configuration */

    union
    {
        __IOM uint32_t TRIPMUXENABLE[8]; /*!< 0x00000c40 */

        struct
        {
            __IOM uint32_t MUX0 : 1;  /*!< [0:0] : Selects the output of MUX0 to drive TRIP4 of ePWM--XBAR         <br>
                                         0: Respective output of MUX0 is disabled to drive the TRIP4 of ePWM--XBAR<br>  1:
                                         Respective output of MUX0 is enabled to drive the TRIP4 of ePWM--XBAR<br>  Refer
                                         to the ePWM X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX1 : 1;  /*!< [1:1] : Selects the output of MUX1 to drive TRIP4 of ePWM--XBAR         <br>
                                         0: Respective output of MUX1 is disabled to drive the TRIP4 of ePWM--XBAR<br>  1:
                                         Respective output of MUX1 is enabled to drive the TRIP4 of ePWM--XBAR<br>  Refer
                                         to the ePWM X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX2 : 1;  /*!< [2:2] : Selects the output of MUX2 to drive TRIP4 of ePWM--XBAR         <br>
                                         0: Respective output of MUX2 is disabled to drive the TRIP4 of ePWM--XBAR<br>  1:
                                         Respective output of MUX2 is enabled to drive the TRIP4 of ePWM--XBAR<br>  Refer
                                         to the ePWM X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX3 : 1;  /*!< [3:3] : Selects the output of MUX3 to drive TRIP4 of ePWM--XBAR         <br>
                                         0: Respective output of MUX3 is disabled to drive the TRIP4 of ePWM--XBAR<br>  1:
                                         Respective output of MUX3 is enabled to drive the TRIP4 of ePWM--XBAR<br>  Refer
                                         to the ePWM X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX4 : 1;  /*!< [4:4] : Selects the output of MUX4 to drive TRIP4 of ePWM--XBAR         <br>
                                         0: Respective output of MUX4 is disabled to drive the TRIP4 of ePWM--XBAR<br>  1:
                                         Respective output of MUX4 is enabled to drive the TRIP4 of ePWM--XBAR<br>  Refer
                                         to the ePWM X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX5 : 1;  /*!< [5:5] : Selects the output of MUX5 to drive TRIP4 of ePWM--XBAR         <br>
                                         0: Respective output of MUX5 is disabled to drive the TRIP4 of ePWM--XBAR<br>  1:
                                         Respective output of MUX5 is enabled to drive the TRIP4 of ePWM--XBAR<br>  Refer
                                         to the ePWM X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX6 : 1;  /*!< [6:6] : Selects the output of MUX6 to drive TRIP4 of ePWM--XBAR         <br>
                                         0: Respective output of MUX6 is disabled to drive the TRIP4 of ePWM--XBAR<br>  1:
                                         Respective output of MUX6 is enabled to drive the TRIP4 of ePWM--XBAR<br>  Refer
                                         to the ePWM X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX7 : 1;  /*!< [7:7] : Selects the output of MUX7 to drive TRIP4 of ePWM--XBAR         <br>
                                         0: Respective output of MUX7 is disabled to drive the TRIP4 of ePWM--XBAR<br>  1:
                                         Respective output of MUX7 is enabled to drive the TRIP4 of ePWM--XBAR<br>  Refer
                                         to the ePWM X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX8 : 1;  /*!< [8:8] : Selects the output of MUX8 to drive TRIP4 of ePWM--XBAR         <br>
                                         0: Respective output of MUX8 is disabled to drive the TRIP4 of ePWM--XBAR<br>  1:
                                         Respective output of MUX8 is enabled to drive the TRIP4 of ePWM--XBAR<br>  Refer
                                         to the ePWM X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX9 : 1;  /*!< [9:9] : Selects the output of MUX9 to drive TRIP4 of ePWM--XBAR         <br>
                                         0: Respective output of MUX9 is disabled to drive the TRIP4 of ePWM--XBAR<br>  1:
                                         Respective output of MUX9 is enabled to drive the TRIP4 of ePWM--XBAR<br>  Refer
                                         to the ePWM X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX10 : 1; /*!< [10:10] : Selects the output of MUX10 to drive TRIP4 of ePWM--XBAR <br>  0:
                                         Respective output of MUX10 is disabled to drive the TRIP4 of ePWM--XBAR<br>  1:
                                         Respective output of MUX10 is enabled to drive the TRIP4 of ePWM--XBAR<br>
                                         Refer to the ePWM X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX11 : 1; /*!< [11:11] : Selects the output of MUX11 to drive TRIP4 of ePWM--XBAR <br>  0:
                                         Respective output of MUX11 is disabled to drive the TRIP4 of ePWM--XBAR<br>  1:
                                         Respective output of MUX11 is enabled to drive the TRIP4 of ePWM--XBAR<br>
                                         Refer to the ePWM X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX12 : 1; /*!< [12:12] : Selects the output of MUX12 to drive TRIP4 of ePWM--XBAR <br>  0:
                                         Respective output of MUX12 is disabled to drive the TRIP4 of ePWM--XBAR<br>  1:
                                         Respective output of MUX12 is enabled to drive the TRIP4 of ePWM--XBAR<br>
                                         Refer to the ePWM X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX13 : 1; /*!< [13:13] : Selects the output of MUX13 to drive TRIP4 of ePWM--XBAR <br>  0:
                                         Respective output of MUX13 is disabled to drive the TRIP4 of ePWM--XBAR<br>  1:
                                         Respective output of MUX13 is enabled to drive the TRIP4 of ePWM--XBAR<br>
                                         Refer to the ePWM X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX14 : 1; /*!< [14:14] : Selects the output of MUX14 to drive TRIP4 of ePWM--XBAR <br>  0:
                                         Respective output of MUX14 is disabled to drive the TRIP4 of ePWM--XBAR<br>  1:
                                         Respective output of MUX14 is enabled to drive the TRIP4 of ePWM--XBAR<br>
                                         Refer to the ePWM X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX15 : 1; /*!< [15:15] : Selects the output of MUX15 to drive TRIP4 of ePWM--XBAR <br>  0:
                                         Respective output of MUX15 is disabled to drive the TRIP4 of ePWM--XBAR<br>  1:
                                         Respective output of MUX15 is enabled to drive the TRIP4 of ePWM--XBAR<br>
                                         Refer to the ePWM X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX16 : 1; /*!< [16:16] : Selects the output of MUX16 to drive TRIP4 of ePWM--XBAR <br>  0:
                                         Respective output of MUX16 is disabled to drive the TRIP4 of ePWM--XBAR<br>  1:
                                         Respective output of MUX16 is enabled to drive the TRIP4 of ePWM--XBAR<br>
                                         Refer to the ePWM X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX17 : 1; /*!< [17:17] : Selects the output of MUX17 to drive TRIP4 of ePWM--XBAR <br>  0:
                                         Respective output of MUX17 is disabled to drive the TRIP4 of ePWM--XBAR<br>  1:
                                         Respective output of MUX17 is enabled to drive the TRIP4 of ePWM--XBAR<br>
                                         Refer to the ePWM X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX18 : 1; /*!< [18:18] : Selects the output of MUX18 to drive TRIP4 of ePWM--XBAR <br>  0:
                                         Respective output of MUX18 is disabled to drive the TRIP4 of ePWM--XBAR<br>  1:
                                         Respective output of MUX18 is enabled to drive the TRIP4 of ePWM--XBAR<br>
                                         Refer to the ePWM X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX19 : 1; /*!< [19:19] : Selects the output of MUX19 to drive TRIP4 of ePWM--XBAR <br>  0:
                                         Respective output of MUX19 is disabled to drive the TRIP4 of ePWM--XBAR<br>  1:
                                         Respective output of MUX19 is enabled to drive the TRIP4 of ePWM--XBAR<br>
                                         Refer to the ePWM X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX20 : 1; /*!< [20:20] : Selects the output of MUX20 to drive TRIP4 of ePWM--XBAR <br>  0:
                                         Respective output of MUX20 is disabled to drive the TRIP4 of ePWM--XBAR<br>  1:
                                         Respective output of MUX20 is enabled to drive the TRIP4 of ePWM--XBAR<br>
                                         Refer to the ePWM X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX21 : 1; /*!< [21:21] : Selects the output of MUX21 to drive TRIP4 of ePWM--XBAR <br>  0:
                                         Respective output of MUX21 is disabled to drive the TRIP4 of ePWM--XBAR<br>  1:
                                         Respective output of MUX21 is enabled to drive the TRIP4 of ePWM--XBAR<br>
                                         Refer to the ePWM X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX22 : 1; /*!< [22:22] : Selects the output of MUX22 to drive TRIP4 of ePWM--XBAR <br>  0:
                                         Respective output of MUX22 is disabled to drive the TRIP4 of ePWM--XBAR<br>  1:
                                         Respective output of MUX22 is enabled to drive the TRIP4 of ePWM--XBAR<br>
                                         Refer to the ePWM X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX23 : 1; /*!< [23:23] : Selects the output of MUX23 to drive TRIP4 of ePWM--XBAR <br>  0:
                                         Respective output of MUX23 is disabled to drive the TRIP4 of ePWM--XBAR<br>  1:
                                         Respective output of MUX23 is enabled to drive the TRIP4 of ePWM--XBAR<br>
                                         Refer to the ePWM X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX24 : 1; /*!< [24:24] : Selects the output of MUX24 to drive TRIP4 of ePWM--XBAR <br>  0:
                                         Respective output of MUX24 is disabled to drive the TRIP4 of ePWM--XBAR<br>  1:
                                         Respective output of MUX24 is enabled to drive the TRIP4 of ePWM--XBAR<br>
                                         Refer to the ePWM X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX25 : 1; /*!< [25:25] : Selects the output of MUX25 to drive TRIP4 of ePWM--XBAR <br>  0:
                                         Respective output of MUX25 is disabled to drive the TRIP4 of ePWM--XBAR<br>  1:
                                         Respective output of MUX25 is enabled to drive the TRIP4 of ePWM--XBAR<br>
                                         Refer to the ePWM X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX26 : 1; /*!< [26:26] : Selects the output of MUX26 to drive TRIP4 of ePWM--XBAR <br>  0:
                                         Respective output of MUX26 is disabled to drive the TRIP4 of ePWM--XBAR<br>  1:
                                         Respective output of MUX26 is enabled to drive the TRIP4 of ePWM--XBAR<br>
                                         Refer to the ePWM X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX27 : 1; /*!< [27:27] : Selects the output of MUX27 to drive TRIP4 of ePWM--XBAR <br>  0:
                                         Respective output of MUX27 is disabled to drive the TRIP4 of ePWM--XBAR<br>  1:
                                         Respective output of MUX27 is enabled to drive the TRIP4 of ePWM--XBAR<br>
                                         Refer to the ePWM X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX28 : 1; /*!< [28:28] : Selects the output of MUX28 to drive TRIP4 of ePWM--XBAR <br>  0:
                                         Respective output of MUX28 is disabled to drive the TRIP4 of ePWM--XBAR<br>  1:
                                         Respective output of MUX28 is enabled to drive the TRIP4 of ePWM--XBAR<br>
                                         Refer to the ePWM X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX29 : 1; /*!< [29:29] : Selects the output of MUX29 to drive TRIP4 of ePWM--XBAR <br>  0:
                                         Respective output of MUX29 is disabled to drive the TRIP4 of ePWM--XBAR<br>  1:
                                         Respective output of MUX29 is enabled to drive the TRIP4 of ePWM--XBAR<br>
                                         Refer to the ePWM X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX30 : 1; /*!< [30:30] : Selects the output of MUX30 to drive TRIP4 of ePWM--XBAR <br>  0:
                                         Respective output of MUX30 is disabled to drive the TRIP4 of ePWM--XBAR<br>  1:
                                         Respective output of MUX30 is enabled to drive the TRIP4 of ePWM--XBAR<br>
                                         Refer to the ePWM X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX31 : 1; /*!< [31:31] : Selects the output of MUX31 to drive TRIP4 of ePWM--XBAR <br>  0:
                                         Respective output of MUX31 is disabled to drive the TRIP4 of ePWM--XBAR<br>  1:
                                         Respective output of MUX31 is enabled to drive the TRIP4 of ePWM--XBAR<br>
                                         Refer to the ePWM X--BAR section of this chapter for more details. */
        } TRIPMUXENABLEb[8];
    };

    uint8_t RSV_0XC60[16]; /*!< 0x00000c60~0x00000c6f : reserved */

    union
    {
        __IOM uint32_t TRIPOUTINV; /*!< 0x00000c70 */

        struct
        {
            __IOM uint32_t
                TRIP4 : 1; /*!< [0:0] : Selects polarity for TRIP4 of ePWM--XBAR                        <br>  0: drives
                              active high output                                    <br>  1: drives active--low output
                              <br>  Refer to the ePWM X--BAR section of this chapter for more details. */
            __IOM uint32_t
                TRIP5 : 1; /*!< [1:1] : Selects polarity for TRIP5 of ePWM--XBAR                        <br>  0: drives
                              active high output                                    <br>  1: drives active--low output
                              <br>  Refer to the ePWM X--BAR section of this chapter for more details. */
            __IOM uint32_t
                TRIP7 : 1; /*!< [2:2] : Selects polarity for TRIP7 of ePWM--XBAR                        <br>  0: drives
                              active high output                                    <br>  1: drives active--low output
                              <br>  Refer to the ePWM X--BAR section of this chapter for more details. */
            __IOM uint32_t
                TRIP8 : 1; /*!< [3:3] : Selects polarity for TRIP8 of ePWM--XBAR                        <br>  0: drives
                              active high output                                    <br>  1: drives active--low output
                              <br>  Refer to the ePWM X--BAR section of this chapter for more details. */
            __IOM uint32_t
                TRIP9 : 1; /*!< [4:4] : Selects polarity for TRIP9 of ePWM--XBAR                        <br>  0: drives
                              active high output                                    <br>  1: drives active--low output
                              <br>  Refer to the ePWM X--BAR section of this chapter for more details. */
            __IOM uint32_t
                TRIP10 : 1; /*!< [5:5] : Selects polarity for TRIP10 of ePWM--XBAR                       <br>  0: drives
                               active high output                                    <br>  1: drives active--low output
                               <br>  Refer to the ePWM X--BAR section of this chapter for more details. */
            __IOM uint32_t
                TRIP11 : 1; /*!< [6:6] : Selects polarity for TRIP11 of ePWM--XBAR                       <br>  0: drives
                               active high output                                    <br>  1: drives active--low output
                               <br>  Refer to the ePWM X--BAR section of this chapter for more details. */
            __IOM uint32_t
                TRIP12 : 1; /*!< [7:7] : Selects polarity for TRIP12 of ePWM--XBAR                       <br>  0: drives
                               active high output                                    <br>  1: drives active--low output
                               <br>  Refer to the ePWM X--BAR section of this chapter for more details. */
            uint32_t RSV_0 : 24; /*!< [31:8] : reserved. */
        } TRIPOUTINVb;
    };

    uint8_t RSV_0XC74[8]; /*!< 0x00000c74~0x00000c7b : reserved */

    union
    {
        __IOM uint32_t TRIPLOCK; /*!< 0x00000c7c */

        struct
        {
            __IOM uint32_t LOCK  : 1;  /*!< [0:0] : Locks the configuration for ePWM--XBAR. */
            uint32_t       RSV_0 : 15; /*!< [15:1] : reserved. */
            __IOM uint32_t KEY : 16; /*!< [31:16] : Bit--0 of this register can be set only if KEY= 0x5a5a          <br>
                                        Reset type: CPU1. */
        } TRIPLOCKb;
    };
} EPWM_XBAR_Type;

/*! \brief CLB_XBAR register */
typedef struct
{
    struct
    {
        union
        {
            __IOM uint32_t MUX0TO15CFG; /*!< 0x00001000 */

            struct
            {
                __IOM uint32_t MUX0  : 2; /*!< [1:0] : Select Bits for AUXSIG0 MUX0: <br>  00 : Select . */
                __IOM uint32_t MUX1  : 2; /*!< [3:2] : Select Bits for AUXSIG0 MUX14: <br>  00 : Select . */
                __IOM uint32_t MUX2  : 2; /*!< [5:4] : Select Bits for AUXSIG0 MUX2: <br>  00 : Select . */
                __IOM uint32_t MUX3  : 2; /*!< [7:6] : Select Bits for AUXSIG0 MUX3: <br>  00 : Select . */
                __IOM uint32_t MUX4  : 2; /*!< [9:8] : Select Bits for AUXSIG0 MUX4: <br>  00 : Select . */
                __IOM uint32_t MUX5  : 2; /*!< [11:10] : Select Bits for AUXSIG0 MUX5: <br>  00 : Select . */
                __IOM uint32_t MUX6  : 2; /*!< [13:12] : Select Bits for AUXSIG0 MUX6: <br>  00 : Select . */
                __IOM uint32_t MUX7  : 2; /*!< [15:14] : Select Bits for AUXSIG0 MUX7: <br>  00 : Select . */
                __IOM uint32_t MUX8  : 2; /*!< [17:16] : Select Bits for AUXSIG0 MUX8: <br>  00 : Select . */
                __IOM uint32_t MUX9  : 2; /*!< [19:18] : Select Bits for AUXSIG0 MUX9: <br>  00 : Select . */
                __IOM uint32_t MUX10 : 2; /*!< [21:20] : Select Bits for AUXSIG0 MUX10: <br>  00 : Select . */
                __IOM uint32_t MUX11 : 2; /*!< [23:22] : Select Bits for AUXSIG0 MUX11: <br>  00 : Select . */
                __IOM uint32_t MUX12 : 2; /*!< [25:24] : Select Bits for AUXSIG0 MUX12: <br>  00 : Select . */
                __IOM uint32_t MUX13 : 2; /*!< [27:26] : Select Bits for AUXSIG0 MUX13: <br>  00 : Select . */
                __IOM uint32_t MUX14 : 2; /*!< [29:28] : Select Bits for AUXSIG0 MUX14: <br>  00 : Select . */
                __IOM uint32_t MUX15 : 2; /*!< [31:30] : Select Bits for AUXSIG0 Mux15: <br>  00 : Select . */
            } MUX0TO15CFGb;
        };

        union
        {
            __IOM uint32_t MUX16TO31CFG; /*!< 0x00001004 */

            struct
            {
                __IOM uint32_t MUX16 : 2; /*!< [1:0] : Select Bits for AUXSIG0 MUX16: <br>  00 : Select . */
                __IOM uint32_t MUX17 : 2; /*!< [3:2] : Select Bits for AUXSIG0 MUX17: <br>  00 : Select . */
                __IOM uint32_t MUX18 : 2; /*!< [5:4] : Select Bits for AUXSIG0 MUX18: <br>  00 : Select . */
                __IOM uint32_t MUX19 : 2; /*!< [7:6] : Select Bits for AUXSIG0 MUX19: <br>  00 : Select . */
                __IOM uint32_t MUX20 : 2; /*!< [9:8] : Select Bits for AUXSIG0 MUX20: <br>  00 : Select . */
                __IOM uint32_t MUX21 : 2; /*!< [11:10] : Select Bits for AUXSIG0 MUX21: <br>  00 : Select . */
                __IOM uint32_t MUX22 : 2; /*!< [13:12] : Select Bits for AUXSIG0 MUX22: <br>  00 : Select . */
                __IOM uint32_t MUX23 : 2; /*!< [15:14] : Select Bits for AUXSIG0 MUX23: <br>  00 : Select . */
                __IOM uint32_t MUX24 : 2; /*!< [17:16] : Select Bits for AUXSIG0 MUX24: <br>  00 : Select . */
                __IOM uint32_t MUX25 : 2; /*!< [19:18] : Select Bits for AUXSIG0 MUX25: <br>  00 : Select . */
                __IOM uint32_t MUX26 : 2; /*!< [21:20] : Select Bits for AUXSIG0 MUX26: <br>  00 : Select . */
                __IOM uint32_t MUX27 : 2; /*!< [23:22] : Select Bits for AUXSIG0 MUX27: <br>  00 : Select . */
                __IOM uint32_t MUX28 : 2; /*!< [25:24] : Select Bits for AUXSIG0 MUX28: <br>  00 : Select . */
                __IOM uint32_t MUX29 : 2; /*!< [27:26] : Select Bits for AUXSIG0 MUX29: <br>  00 : Select . */
                __IOM uint32_t MUX30 : 2; /*!< [29:28] : Select Bits for AUXSIG0 MUX30: <br>  00 : Select . */
                __IOM uint32_t MUX31 : 2; /*!< [31:30] : Select Bits for AUXSIG0 MUX31: <br>  00 : Select . */
            } MUX16TO31CFGb;
        };
    } AUXSIGMUX[8]; /*!< 0x00001000 + 0x8 * n : AUXSIG mux configuration */

    union
    {
        __IOM uint32_t AUXSIGMUXENABLE[8]; /*!< 0x00001040 */

        struct
        {
            __IOM uint32_t MUX0 : 1;  /*!< [0:0] : Selects the output of MUX0 to drive AUXSIG0 of CLB--XBAR        <br>
                                         0: Respective output of MUX0 is disabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         1: Respective output of MUX0 is enabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         Refer to the CLB X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX1 : 1;  /*!< [1:1] : Selects the output of MUX1 to drive AUXSIG0 of CLB--XBAR        <br>
                                         0: Respective output of MUX1 is disabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         1: Respective output of MUX1 is enabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         Refer to the CLB X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX2 : 1;  /*!< [2:2] : Selects the output of MUX2 to drive AUXSIG0 of CLB--XBAR        <br>
                                         0: Respective output of MUX2 is disabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         1: Respective output of MUX2 is enabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         Refer to the CLB X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX3 : 1;  /*!< [3:3] : Selects the output of MUX3 to drive AUXSIG0 of CLB--XBAR        <br>
                                         0: Respective output of MUX3 is disabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         1: Respective output of MUX3 is enabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         Refer to the CLB X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX4 : 1;  /*!< [4:4] : Selects the output of MUX4 to drive AUXSIG0 of CLB--XBAR        <br>
                                         0: Respective output of MUX4 is disabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         1: Respective output of MUX4 is enabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         Refer to the CLB X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX5 : 1;  /*!< [5:5] : Selects the output of MUX5 to drive AUXSIG0 of CLB--XBAR        <br>
                                         0: Respective output of MUX5 is disabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         1: Respective output of MUX5 is enabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         Refer to the CLB X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX6 : 1;  /*!< [6:6] : Selects the output of MUX6 to drive AUXSIG0 of CLB--XBAR        <br>
                                         0: Respective output of MUX6 is disabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         1: Respective output of MUX6 is enabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         Refer to the CLB X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX7 : 1;  /*!< [7:7] : Selects the output of MUX7 to drive AUXSIG0 of CLB--XBAR        <br>
                                         0: Respective output of MUX7 is disabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         1: Respective output of MUX7 is enabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         Refer to the CLB X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX8 : 1;  /*!< [8:8] : Selects the output of MUX8 to drive AUXSIG0 of CLB--XBAR        <br>
                                         0: Respective output of MUX8 is disabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         1: Respective output of MUX8 is enabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         Refer to the CLB X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX9 : 1;  /*!< [9:9] : Selects the output of MUX9 to drive AUXSIG0 of CLB--XBAR        <br>
                                         0: Respective output of MUX9 is disabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         1: Respective output of MUX9 is enabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         Refer to the CLB X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX10 : 1; /*!< [10:10] : Selects the output of MUX10 to drive AUXSIG0 of CLB--XBAR <br>  0:
                                         Respective output of MUX10 is disabled to drive the AUXSIG0 of CLB--XBAR<br> 1:
                                         Respective output of MUX10 is enabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         Refer to the CLB X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX11 : 1; /*!< [11:11] : Selects the output of MUX11 to drive AUXSIG0 of CLB--XBAR <br>  0:
                                         Respective output of MUX11 is disabled to drive the AUXSIG0 of CLB--XBAR<br> 1:
                                         Respective output of MUX11 is enabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         Refer to the CLB X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX12 : 1; /*!< [12:12] : Selects the output of MUX12 to drive AUXSIG0 of CLB--XBAR <br>  0:
                                         Respective output of MUX12 is disabled to drive the AUXSIG0 of CLB--XBAR<br> 1:
                                         Respective output of MUX12 is enabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         Refer to the CLB X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX13 : 1; /*!< [13:13] : Selects the output of MUX13 to drive AUXSIG0 of CLB--XBAR <br>  0:
                                         Respective output of MUX13 is disabled to drive the AUXSIG0 of CLB--XBAR<br> 1:
                                         Respective output of MUX13 is enabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         Refer to the CLB X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX14 : 1; /*!< [14:14] : Selects the output of MUX14 to drive AUXSIG0 of CLB--XBAR <br>  0:
                                         Respective output of MUX14 is disabled to drive the AUXSIG0 of CLB--XBAR<br> 1:
                                         Respective output of MUX14 is enabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         Refer to the CLB X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX15 : 1; /*!< [15:15] : Selects the output of MUX15 to drive AUXSIG0 of CLB--XBAR <br>  0:
                                         Respective output of MUX15 is disabled to drive the AUXSIG0 of CLB--XBAR<br> 1:
                                         Respective output of MUX15 is enabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         Refer to the CLB X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX16 : 1; /*!< [16:16] : Selects the output of MUX16 to drive AUXSIG0 of CLB--XBAR <br>  0:
                                         Respective output of MUX16 is disabled to drive the AUXSIG0 of CLB--XBAR<br> 1:
                                         Respective output of MUX16 is enabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         Refer to the CLB X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX17 : 1; /*!< [17:17] : Selects the output of MUX17 to drive AUXSIG0 of CLB--XBAR <br>  0:
                                         Respective output of MUX17 is disabled to drive the AUXSIG0 of CLB--XBAR<br> 1:
                                         Respective output of MUX17 is enabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         Refer to the CLB X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX18 : 1; /*!< [18:18] : Selects the output of MUX18 to drive AUXSIG0 of CLB--XBAR <br>  0:
                                         Respective output of MUX18 is disabled to drive the AUXSIG0 of CLB--XBAR<br> 1:
                                         Respective output of MUX18 is enabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         Refer to the CLB X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX19 : 1; /*!< [19:19] : Selects the output of MUX19 to drive AUXSIG0 of CLB--XBAR <br>  0:
                                         Respective output of MUX19 is disabled to drive the AUXSIG0 of CLB--XBAR<br> 1:
                                         Respective output of MUX19 is enabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         Refer to the CLB X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX20 : 1; /*!< [20:20] : Selects the output of MUX20 to drive AUXSIG0 of CLB--XBAR <br>  0:
                                         Respective output of MUX20 is disabled to drive the AUXSIG0 of CLB--XBAR<br> 1:
                                         Respective output of MUX20 is enabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         Refer to the CLB X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX21 : 1; /*!< [21:21] : Selects the output of MUX21 to drive AUXSIG0 of CLB--XBAR <br>  0:
                                         Respective output of MUX21 is disabled to drive the AUXSIG0 of CLB--XBAR<br> 1:
                                         Respective output of MUX21 is enabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         Refer to the CLB X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX22 : 1; /*!< [22:22] : Selects the output of MUX22 to drive AUXSIG0 of CLB--XBAR <br>  0:
                                         Respective output of MUX22 is disabled to drive the AUXSIG0 of CLB--XBAR<br> 1:
                                         Respective output of MUX22 is enabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         Refer to the CLB X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX23 : 1; /*!< [23:23] : Selects the output of MUX23 to drive AUXSIG0 of CLB--XBAR <br>  0:
                                         Respective output of MUX23 is disabled to drive the AUXSIG0 of CLB--XBAR<br> 1:
                                         Respective output of MUX23 is enabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         Refer to the CLB X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX24 : 1; /*!< [24:24] : Selects the output of MUX24 to drive AUXSIG0 of CLB--XBAR <br>  0:
                                         Respective output of MUX24 is disabled to drive the AUXSIG0 of CLB--XBAR<br> 1:
                                         Respective output of MUX24 is enabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         Refer to the CLB X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX25 : 1; /*!< [25:25] : Selects the output of MUX25 to drive AUXSIG0 of CLB--XBAR <br>  0:
                                         Respective output of MUX25 is disabled to drive the AUXSIG0 of CLB--XBAR<br> 1:
                                         Respective output of MUX25 is enabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         Refer to the CLB X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX26 : 1; /*!< [26:26] : Selects the output of MUX26 to drive AUXSIG0 of CLB--XBAR <br>  0:
                                         Respective output of MUX26 is disabled to drive the AUXSIG0 of CLB--XBAR<br> 1:
                                         Respective output of MUX26 is enabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         Refer to the CLB X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX27 : 1; /*!< [27:27] : Selects the output of MUX27 to drive AUXSIG0 of CLB--XBAR <br>  0:
                                         Respective output of MUX27 is disabled to drive the AUXSIG0 of CLB--XBAR<br> 1:
                                         Respective output of MUX27 is enabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         Refer to the CLB X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX28 : 1; /*!< [28:28] : Selects the output of MUX28 to drive AUXSIG0 of CLB--XBAR <br>  0:
                                         Respective output of MUX28 is disabled to drive the AUXSIG0 of CLB--XBAR<br> 1:
                                         Respective output of MUX28 is enabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         Refer to the CLB X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX29 : 1; /*!< [29:29] : Selects the output of MUX29 to drive AUXSIG0 of CLB--XBAR <br>  0:
                                         Respective output of MUX29 is disabled to drive the AUXSIG0 of CLB--XBAR<br> 1:
                                         Respective output of MUX29 is enabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         Refer to the CLB X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX30 : 1; /*!< [30:30] : Selects the output of MUX30 to drive AUXSIG0 of CLB--XBAR <br>  0:
                                         Respective output of MUX30 is disabled to drive the AUXSIG0 of CLB--XBAR<br> 1:
                                         Respective output of MUX30 is enabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         Refer to the CLB X--BAR section of this chapter for more details. */
            __IOM uint32_t MUX31 : 1; /*!< [31:31] : Selects the output of MUX31 to drive AUXSIG0 of CLB--XBAR <br>  0:
                                         Respective output of MUX31 is disabled to drive the AUXSIG0 of CLB--XBAR<br> 1:
                                         Respective output of MUX31 is enabled to drive the AUXSIG0 of CLB--XBAR<br>
                                         Refer to the CLB X--BAR section of this chapter for more details. */
        } AUXSIGMUXENABLEb[8];
    };

    uint8_t RSV_0X1060[16]; /*!< 0x00001060~0x0000106f : reserved */

    union
    {
        __IOM uint32_t AUXSIGOUTINV; /*!< 0x00001070 */

        struct
        {
            __IOM uint32_t AUXSIG0 : 1; /*!< [0:0] : Selects polarity for AUXSIG0 of CLB--XBAR <br>  0: drives active
                                           high output                                    <br>  1: drives active--low
                                           output                                    <br>  Refer to the CLB X--BAR
                                           section of this chapter for more details. */
            __IOM uint32_t AUXSIG1 : 1; /*!< [1:1] : Selects polarity for AUXSIG1 of CLB--XBAR <br>  0: drives active
                                           high output                                    <br>  1: drives active--low
                                           output                                    <br>  Refer to the CLB X--BAR
                                           section of this chapter for more details. */
            __IOM uint32_t AUXSIG2 : 1; /*!< [2:2] : Selects polarity for AUXSIG2 of CLB--XBAR <br>  0: drives active
                                           high output                                    <br>  1: drives active--low
                                           output                                    <br>  Refer to the CLB X--BAR
                                           section of this chapter for more details. */
            __IOM uint32_t AUXSIG3 : 1; /*!< [3:3] : Selects polarity for AUXSIG3 of CLB--XBAR <br>  0: drives active
                                           high output                                    <br>  1: drives active--low
                                           output                                    <br>  Refer to the CLB X--BAR
                                           section of this chapter for more details. */
            __IOM uint32_t AUXSIG4 : 1; /*!< [4:4] : Selects polarity for AUXSIG4 of CLB--XBAR <br>  0: drives active
                                           high output                                    <br>  1: drives active--low
                                           output                                    <br>  Refer to the CLB X--BAR
                                           section of this chapter for more details. */
            __IOM uint32_t AUXSIG5 : 1; /*!< [5:5] : Selects polarity for AUXSIG5 of CLB--XBAR <br>  0: drives active
                                           high output                                    <br>  1: drives active--low
                                           output                                    <br>  Refer to the CLB X--BAR
                                           section of this chapter for more details. */
            __IOM uint32_t AUXSIG6 : 1; /*!< [6:6] : Selects polarity for AUXSIG6 of CLB--XBAR <br>  0: drives active
                                           high output                                    <br>  1: drives active--low
                                           output                                    <br>  Refer to the CLB X--BAR
                                           section of this chapter for more details. */
            __IOM uint32_t AUXSIG7 : 1; /*!< [7:7] : Selects polarity for AUXSIG7 of CLB--XBAR <br>  0: drives active
                                           high output                                    <br>  1: drives active--low
                                           output                                    <br>  Refer to the CLB X--BAR
                                           section of this chapter for more details. */
            uint32_t RSV_0 : 24;        /*!< [31:8] : reserved. */
        } AUXSIGOUTINVb;
    };

    uint8_t RSV_0X1074[8]; /*!< 0x00001074~0x0000107b : reserved */

    union
    {
        __IOM uint32_t AUXSIGLOCK; /*!< 0x0000107c */

        struct
        {
            __IOM uint32_t LOCK  : 1;  /*!< [0:0] : Locks the configuration for CLB--XBAR. */
            uint32_t       RSV_0 : 15; /*!< [15:1] : reserved. */
            __IOM uint32_t KEY : 16; /*!< [31:16] : Bit--0 of this register can be set only if KEY= 0x5a5a          <br>
                                        Reset type: CPU1. */
        } AUXSIGLOCKb;
    };
} CLB_XBAR_Type;

/*! \brief OUTPUT_XBAR register */
typedef struct
{
    struct
    {
        union
        {
            __IOM uint32_t MUX0TO15CFG; /*!< 0x00001400 */

            struct
            {
                __IOM uint32_t MUX0  : 2; /*!< [1:0] : Select Bits for OUTPUT1 MUX0: <br>  00 : Select . */
                __IOM uint32_t MUX1  : 2; /*!< [3:2] : Select Bits for OUTPUT1 MUX14: <br>  00 : Select . */
                __IOM uint32_t MUX2  : 2; /*!< [5:4] : Select Bits for OUTPUT1 MUX2: <br>  00 : Select . */
                __IOM uint32_t MUX3  : 2; /*!< [7:6] : Select Bits for OUTPUT1 MUX3: <br>  00 : Select . */
                __IOM uint32_t MUX4  : 2; /*!< [9:8] : Select Bits for OUTPUT1 MUX4: <br>  00 : Select . */
                __IOM uint32_t MUX5  : 2; /*!< [11:10] : Select Bits for OUTPUT1 MUX5: <br>  00 : Select . */
                __IOM uint32_t MUX6  : 2; /*!< [13:12] : Select Bits for OUTPUT1 MUX6: <br>  00 : Select . */
                __IOM uint32_t MUX7  : 2; /*!< [15:14] : Select Bits for OUTPUT1 MUX7: <br>  00 : Select . */
                __IOM uint32_t MUX8  : 2; /*!< [17:16] : Select Bits for OUTPUT1 MUX8: <br>  00 : Select . */
                __IOM uint32_t MUX9  : 2; /*!< [19:18] : Select Bits for OUTPUT1 MUX9: <br>  00 : Select . */
                __IOM uint32_t MUX10 : 2; /*!< [21:20] : Select Bits for OUTPUT1 MUX10: <br>  00 : Select . */
                __IOM uint32_t MUX11 : 2; /*!< [23:22] : Select Bits for OUTPUT1 MUX11: <br>  00 : Select . */
                __IOM uint32_t MUX12 : 2; /*!< [25:24] : Select Bits for OUTPUT1 MUX12: <br>  00 : Select . */
                __IOM uint32_t MUX13 : 2; /*!< [27:26] : Select Bits for OUTPUT1 MUX13: <br>  00 : Select . */
                __IOM uint32_t MUX14 : 2; /*!< [29:28] : Select Bits for OUTPUT1 MUX14: <br>  00 : Select . */
                __IOM uint32_t MUX15 : 2; /*!< [31:30] : Select Bits for OUTPUT1 Mux15: <br>  00 : Select . */
            } MUX0TO15CFGb;
        };

        union
        {
            __IOM uint32_t MUX16TO31CFG; /*!< 0x00001404 */

            struct
            {
                __IOM uint32_t MUX16 : 2; /*!< [1:0] : Select Bits for OUTPUT1 MUX16: <br>  00 : Select . */
                __IOM uint32_t MUX17 : 2; /*!< [3:2] : Select Bits for OUTPUT1 MUX17: <br>  00 : Select . */
                __IOM uint32_t MUX18 : 2; /*!< [5:4] : Select Bits for OUTPUT1 MUX18: <br>  00 : Select . */
                __IOM uint32_t MUX19 : 2; /*!< [7:6] : Select Bits for OUTPUT1 MUX19: <br>  00 : Select . */
                __IOM uint32_t MUX20 : 2; /*!< [9:8] : Select Bits for OUTPUT1 MUX20: <br>  00 : Select . */
                __IOM uint32_t MUX21 : 2; /*!< [11:10] : Select Bits for OUTPUT1 MUX21: <br>  00 : Select . */
                __IOM uint32_t MUX22 : 2; /*!< [13:12] : Select Bits for OUTPUT1 MUX22: <br>  00 : Select . */
                __IOM uint32_t MUX23 : 2; /*!< [15:14] : Select Bits for OUTPUT1 MUX23: <br>  00 : Select . */
                __IOM uint32_t MUX24 : 2; /*!< [17:16] : Select Bits for OUTPUT1 MUX24: <br>  00 : Select . */
                __IOM uint32_t MUX25 : 2; /*!< [19:18] : Select Bits for OUTPUT1 MUX25: <br>  00 : Select . */
                __IOM uint32_t MUX26 : 2; /*!< [21:20] : Select Bits for OUTPUT1 MUX26: <br>  00 : Select . */
                __IOM uint32_t MUX27 : 2; /*!< [23:22] : Select Bits for OUTPUT1 MUX27: <br>  00 : Select . */
                __IOM uint32_t MUX28 : 2; /*!< [25:24] : Select Bits for OUTPUT1 MUX28: <br>  00 : Select . */
                __IOM uint32_t MUX29 : 2; /*!< [27:26] : Select Bits for OUTPUT1 MUX29: <br>  00 : Select . */
                __IOM uint32_t MUX30 : 2; /*!< [29:28] : Select Bits for OUTPUT1 MUX30: <br>  00 : Select . */
                __IOM uint32_t MUX31 : 2; /*!< [31:30] : Select Bits for OUTPUT1 MUX31: <br>  00 : Select . */
            } MUX16TO31CFGb;
        };
    } OUTPUTMUX[8]; /*!< 0x00001400 + 0x8 * n : OUTPUT mux configuration */

    union
    {
        __IOM uint32_t OUTPUTMUXENABLE[8]; /*!< 0x00001440 */

        struct
        {
            __IOM uint32_t MUX0 : 1; /*!< [0:0] : Selects the output of MUX0 to drive OUTPUT1 of OUTPUT-XBAR      <br>
                                        0: Respective output of MUX0 is disabled to drive the OUTPUT1 of OUTPUT-XBAR<br>
                                        1: Respective output of MUX0 is enabled to drive the OUTPUT1 of OUTPUT-XBAR<br>
                                        Refer to the OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t MUX1 : 1; /*!< [1:1] : Selects the output of MUX1 to drive OUTPUT1 of OUTPUT-XBAR      <br>
                                        0: Respective output of MUX1 is disabled to drive the OUTPUT1 of OUTPUT-XBAR<br>
                                        1: Respective output of MUX1 is enabled to drive the OUTPUT1 of OUTPUT-XBAR<br>
                                        Refer to the OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t MUX2 : 1; /*!< [2:2] : Selects the output of MUX2 to drive OUTPUT1 of OUTPUT-XBAR      <br>
                                        0: Respective output of MUX2 is disabled to drive the OUTPUT1 of OUTPUT-XBAR<br>
                                        1: Respective output of MUX2 is enabled to drive the OUTPUT1 of OUTPUT-XBAR<br>
                                        Refer to the OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t MUX3 : 1; /*!< [3:3] : Selects the output of MUX3 to drive OUTPUT1 of OUTPUT-XBAR      <br>
                                        0: Respective output of MUX3 is disabled to drive the OUTPUT1 of OUTPUT-XBAR<br>
                                        1: Respective output of MUX3 is enabled to drive the OUTPUT1 of OUTPUT-XBAR<br>
                                        Refer to the OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t MUX4 : 1; /*!< [4:4] : Selects the output of MUX4 to drive OUTPUT1 of OUTPUT-XBAR      <br>
                                        0: Respective output of MUX4 is disabled to drive the OUTPUT1 of OUTPUT-XBAR<br>
                                        1: Respective output of MUX4 is enabled to drive the OUTPUT1 of OUTPUT-XBAR<br>
                                        Refer to the OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t MUX5 : 1; /*!< [5:5] : Selects the output of MUX5 to drive OUTPUT1 of OUTPUT-XBAR      <br>
                                        0: Respective output of MUX5 is disabled to drive the OUTPUT1 of OUTPUT-XBAR<br>
                                        1: Respective output of MUX5 is enabled to drive the OUTPUT1 of OUTPUT-XBAR<br>
                                        Refer to the OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t MUX6 : 1; /*!< [6:6] : Selects the output of MUX6 to drive OUTPUT1 of OUTPUT-XBAR      <br>
                                        0: Respective output of MUX6 is disabled to drive the OUTPUT1 of OUTPUT-XBAR<br>
                                        1: Respective output of MUX6 is enabled to drive the OUTPUT1 of OUTPUT-XBAR<br>
                                        Refer to the OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t MUX7 : 1; /*!< [7:7] : Selects the output of MUX7 to drive OUTPUT1 of OUTPUT-XBAR      <br>
                                        0: Respective output of MUX7 is disabled to drive the OUTPUT1 of OUTPUT-XBAR<br>
                                        1: Respective output of MUX7 is enabled to drive the OUTPUT1 of OUTPUT-XBAR<br>
                                        Refer to the OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t MUX8 : 1; /*!< [8:8] : Selects the output of MUX8 to drive OUTPUT1 of OUTPUT-XBAR      <br>
                                        0: Respective output of MUX8 is disabled to drive the OUTPUT1 of OUTPUT-XBAR<br>
                                        1: Respective output of MUX8 is enabled to drive the OUTPUT1 of OUTPUT-XBAR<br>
                                        Refer to the OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t MUX9 : 1; /*!< [9:9] : Selects the output of MUX9 to drive OUTPUT1 of OUTPUT-XBAR      <br>
                                        0: Respective output of MUX9 is disabled to drive the OUTPUT1 of OUTPUT-XBAR<br>
                                        1: Respective output of MUX9 is enabled to drive the OUTPUT1 of OUTPUT-XBAR<br>
                                        Refer to the OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t
                MUX10 : 1; /*!< [10:10] : Selects the output of MUX10 to drive OUTPUT1 of OUTPUT-XBAR     <br>  0:
                              Respective output of MUX10 is disabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  1:
                              Respective output of MUX10 is enabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  Refer to
                              the OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t
                MUX11 : 1; /*!< [11:11] : Selects the output of MUX11 to drive OUTPUT1 of OUTPUT-XBAR     <br>  0:
                              Respective output of MUX11 is disabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  1:
                              Respective output of MUX11 is enabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  Refer to
                              the OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t
                MUX12 : 1; /*!< [12:12] : Selects the output of MUX12 to drive OUTPUT1 of OUTPUT-XBAR     <br>  0:
                              Respective output of MUX12 is disabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  1:
                              Respective output of MUX12 is enabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  Refer to
                              the OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t
                MUX13 : 1; /*!< [13:13] : Selects the output of MUX13 to drive OUTPUT1 of OUTPUT-XBAR     <br>  0:
                              Respective output of MUX13 is disabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  1:
                              Respective output of MUX13 is enabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  Refer to
                              the OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t
                MUX14 : 1; /*!< [14:14] : Selects the output of MUX14 to drive OUTPUT1 of OUTPUT-XBAR     <br>  0:
                              Respective output of MUX14 is disabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  1:
                              Respective output of MUX14 is enabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  Refer to
                              the OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t
                MUX15 : 1; /*!< [15:15] : Selects the output of MUX15 to drive OUTPUT1 of OUTPUT-XBAR     <br>  0:
                              Respective output of MUX15 is disabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  1:
                              Respective output of MUX15 is enabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  Refer to
                              the OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t
                MUX16 : 1; /*!< [16:16] : Selects the output of MUX16 to drive OUTPUT1 of OUTPUT-XBAR     <br>  0:
                              Respective output of MUX16 is disabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  1:
                              Respective output of MUX16 is enabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  Refer to
                              the OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t
                MUX17 : 1; /*!< [17:17] : Selects the output of MUX17 to drive OUTPUT1 of OUTPUT-XBAR     <br>  0:
                              Respective output of MUX17 is disabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  1:
                              Respective output of MUX17 is enabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  Refer to
                              the OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t
                MUX18 : 1; /*!< [18:18] : Selects the output of MUX18 to drive OUTPUT1 of OUTPUT-XBAR     <br>  0:
                              Respective output of MUX18 is disabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  1:
                              Respective output of MUX18 is enabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  Refer to
                              the OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t
                MUX19 : 1; /*!< [19:19] : Selects the output of MUX19 to drive OUTPUT1 of OUTPUT-XBAR     <br>  0:
                              Respective output of MUX19 is disabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  1:
                              Respective output of MUX19 is enabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  Refer to
                              the OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t
                MUX20 : 1; /*!< [20:20] : Selects the output of MUX20 to drive OUTPUT1 of OUTPUT-XBAR     <br>  0:
                              Respective output of MUX20 is disabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  1:
                              Respective output of MUX20 is enabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  Refer to
                              the OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t
                MUX21 : 1; /*!< [21:21] : Selects the output of MUX21 to drive OUTPUT1 of OUTPUT-XBAR     <br>  0:
                              Respective output of MUX21 is disabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  1:
                              Respective output of MUX21 is enabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  Refer to
                              the OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t
                MUX22 : 1; /*!< [22:22] : Selects the output of MUX22 to drive OUTPUT1 of OUTPUT-XBAR     <br>  0:
                              Respective output of MUX22 is disabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  1:
                              Respective output of MUX22 is enabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  Refer to
                              the OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t
                MUX23 : 1; /*!< [23:23] : Selects the output of MUX23 to drive OUTPUT1 of OUTPUT-XBAR     <br>  0:
                              Respective output of MUX23 is disabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  1:
                              Respective output of MUX23 is enabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  Refer to
                              the OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t
                MUX24 : 1; /*!< [24:24] : Selects the output of MUX24 to drive OUTPUT1 of OUTPUT-XBAR     <br>  0:
                              Respective output of MUX24 is disabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  1:
                              Respective output of MUX24 is enabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  Refer to
                              the OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t
                MUX25 : 1; /*!< [25:25] : Selects the output of MUX25 to drive OUTPUT1 of OUTPUT-XBAR     <br>  0:
                              Respective output of MUX25 is disabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  1:
                              Respective output of MUX25 is enabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  Refer to
                              the OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t
                MUX26 : 1; /*!< [26:26] : Selects the output of MUX26 to drive OUTPUT1 of OUTPUT-XBAR     <br>  0:
                              Respective output of MUX26 is disabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  1:
                              Respective output of MUX26 is enabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  Refer to
                              the OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t
                MUX27 : 1; /*!< [27:27] : Selects the output of MUX27 to drive OUTPUT1 of OUTPUT-XBAR     <br>  0:
                              Respective output of MUX27 is disabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  1:
                              Respective output of MUX27 is enabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  Refer to
                              the OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t
                MUX28 : 1; /*!< [28:28] : Selects the output of MUX28 to drive OUTPUT1 of OUTPUT-XBAR     <br>  0:
                              Respective output of MUX28 is disabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  1:
                              Respective output of MUX28 is enabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  Refer to
                              the OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t
                MUX29 : 1; /*!< [29:29] : Selects the output of MUX29 to drive OUTPUT1 of OUTPUT-XBAR     <br>  0:
                              Respective output of MUX29 is disabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  1:
                              Respective output of MUX29 is enabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  Refer to
                              the OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t
                MUX30 : 1; /*!< [30:30] : Selects the output of MUX30 to drive OUTPUT1 of OUTPUT-XBAR     <br>  0:
                              Respective output of MUX30 is disabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  1:
                              Respective output of MUX30 is enabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  Refer to
                              the OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t
                MUX31 : 1; /*!< [31:31] : Selects the output of MUX31 to drive OUTPUT1 of OUTPUT-XBAR     <br>  0:
                              Respective output of MUX31 is disabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  1:
                              Respective output of MUX31 is enabled to drive the OUTPUT1 of OUTPUT-XBAR<br>  Refer to
                              the OUTPUT XBAR section of this chapter for more details. */
        } OUTPUTMUXENABLEb[8];
    };

    union
    {
        __IM uint32_t OUTPUTLATCH; /*!< 0x00001460 */

        struct
        {
            __IM uint32_t OUTPUT1 : 1;  /*!< [0:0] : Records the OUTPUT1 of OUTPUT-XBAR. */
            __IM uint32_t OUTPUT2 : 1;  /*!< [1:1] : Records the OUTPUT2 of OUTPUT-XBAR. */
            __IM uint32_t OUTPUT3 : 1;  /*!< [2:2] : Records the OUTPUT3 of OUTPUT-XBAR. */
            __IM uint32_t OUTPUT4 : 1;  /*!< [3:3] : Records the OUTPUT4 of OUTPUT-XBAR. */
            __IM uint32_t OUTPUT5 : 1;  /*!< [4:4] : Records the OUTPUT5 of OUTPUT-XBAR. */
            __IM uint32_t OUTPUT6 : 1;  /*!< [5:5] : Records the OUTPUT6 of OUTPUT-XBAR. */
            __IM uint32_t OUTPUT7 : 1;  /*!< [6:6] : Records the OUTPUT7 of OUTPUT-XBAR. */
            __IM uint32_t OUTPUT8 : 1;  /*!< [7:7] : Records the OUTPUT8 of OUTPUT-XBAR. */
            uint32_t      RSV_0   : 24; /*!< [31:8] : reserved. */
        } OUTPUTLATCHb;
    };

    union
    {
        __IOM uint32_t OUTPUTLATCHCLR; /*!< 0x00001464 */

        struct
        {
            __IOM uint32_t OUTPUT1 : 1; /*!< [0:0] : Clears the OUTPUT-Latch for OUTPUT1 of OUTPUT-XBAR <br>  Write 1
                                           clears the corresponding output latch bit in the OUTPUTLATCH register<br>
                                           Write of 0 has no effect                                        <br>  Refer
                                           to the OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t OUTPUT2 : 1; /*!< [1:1] : Clears the OUTPUT-Latch for OUTPUT2 of OUTPUT-XBAR <br>  Write 1
                                           clears the corresponding output latch bit in the OUTPUTLATCH register<br>
                                           Write of 0 has no effect                                        <br>  Refer
                                           to the OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t OUTPUT3 : 1; /*!< [2:2] : Clears the OUTPUT-Latch for OUTPUT3 of OUTPUT-XBAR <br>  Write 1
                                           clears the corresponding output latch bit in the OUTPUTLATCH register<br>
                                           Write of 0 has no effect                                        <br>  Refer
                                           to the OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t OUTPUT4 : 1; /*!< [3:3] : Clears the OUTPUT-Latch for OUTPUT4 of OUTPUT-XBAR <br>  Write 1
                                           clears the corresponding output latch bit in the OUTPUTLATCH register<br>
                                           Write of 0 has no effect                                        <br>  Refer
                                           to the OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t OUTPUT5 : 1; /*!< [4:4] : Clears the OUTPUT-Latch for OUTPUT5 of OUTPUT-XBAR <br>  Write 1
                                           clears the corresponding output latch bit in the OUTPUTLATCH register<br>
                                           Write of 0 has no effect                                        <br>  Refer
                                           to the OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t OUTPUT6 : 1; /*!< [5:5] : Clears the OUTPUT-Latch for OUTPUT6 of OUTPUT-XBAR <br>  Write 1
                                           clears the corresponding output latch bit in the OUTPUTLATCH register<br>
                                           Write of 0 has no effect                                        <br>  Refer
                                           to the OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t OUTPUT7 : 1; /*!< [6:6] : Clears the OUTPUT-Latch for OUTPUT7 of OUTPUT-XBAR <br>  Write 1
                                           clears the corresponding output latch bit in the OUTPUTLATCH register<br>
                                           Write of 0 has no effect                                        <br>  Refer
                                           to the OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t OUTPUT8 : 1; /*!< [7:7] : Clears the OUTPUT-Latch for OUTPUT8 of OUTPUT-XBAR <br>  Write 1
                                           clears the corresponding output latch bit in the OUTPUTLATCH register<br>
                                           Write of 0 has no effect                                        <br>  Refer
                                           to the OUTPUT XBAR section of this chapter for more details. */
            uint32_t RSV_0 : 24;        /*!< [31:8] : reserved. */
        } OUTPUTLATCHCLRb;
    };

    union
    {
        __IOM uint32_t OUTPUTLATCHFRC; /*!< 0x00001468 */

        struct
        {
            __IOM uint32_t OUTPUT1 : 1; /*!< [0:0] : Sets the OUTPUT-Latch for OUTPUT1 of OUTPUT-XBAR <br>  Writing 1
                                           sets the corresponding output latch bit in the OUTPUTLATCH register<br> Write
                                           of 0 has no effect                                        <br>  Refer to the
                                           OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t OUTPUT2 : 1; /*!< [1:1] : Sets the OUTPUT-Latch for OUTPUT2 of OUTPUT-XBAR <br>  Writing 1
                                           sets the corresponding output latch bit in the OUTPUTLATCH register<br> Write
                                           of 0 has no effect                                        <br>  Refer to the
                                           OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t OUTPUT3 : 1; /*!< [2:2] : Sets the OUTPUT-Latch for OUTPUT3 of OUTPUT-XBAR <br>  Writing 1
                                           sets the corresponding output latch bit in the OUTPUTLATCH register<br> Write
                                           of 0 has no effect                                        <br>  Refer to the
                                           OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t OUTPUT4 : 1; /*!< [3:3] : Sets the OUTPUT-Latch for OUTPUT4 of OUTPUT-XBAR <br>  Writing 1
                                           sets the corresponding output latch bit in the OUTPUTLATCH register<br> Write
                                           of 0 has no effect                                        <br>  Refer to the
                                           OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t OUTPUT5 : 1; /*!< [4:4] : Sets the OUTPUT-Latch for OUTPUT5 of OUTPUT-XBAR <br>  Writing 1
                                           sets the corresponding output latch bit in the OUTPUTLATCH register<br> Write
                                           of 0 has no effect                                        <br>  Refer to the
                                           OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t OUTPUT6 : 1; /*!< [5:5] : Sets the OUTPUT-Latch for OUTPUT6 of OUTPUT-XBAR <br>  Writing 1
                                           sets the corresponding output latch bit in the OUTPUTLATCH register<br> Write
                                           of 0 has no effect                                        <br>  Refer to the
                                           OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t OUTPUT7 : 1; /*!< [6:6] : Sets the OUTPUT-Latch for OUTPUT7 of OUTPUT-XBAR <br>  Writing 1
                                           sets the corresponding output latch bit in the OUTPUTLATCH register<br> Write
                                           of 0 has no effect                                        <br>  Refer to the
                                           OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t OUTPUT8 : 1; /*!< [7:7] : Sets the OUTPUT-Latch for OUTPUT8 of OUTPUT-XBAR <br>  Writing 1
                                           sets the corresponding output latch bit in the OUTPUTLATCH register<br> Write
                                           of 0 has no effect                                        <br>  Refer to the
                                           OUTPUT XBAR section of this chapter for more details. */
            uint32_t RSV_0 : 24;        /*!< [31:8] : reserved. */
        } OUTPUTLATCHFRCb;
    };

    union
    {
        __IOM uint32_t OUTPUTLATCHENABLE; /*!< 0x0000146c */

        struct
        {
            __IOM uint32_t OUTPUT1 : 1; /*!< [0:0] : Selects the output latch to drive OUTPUT1 for OUTPUT-XBAR <br>  0:
                                           OUTPUT Latch is not selected to driven the respective output <br>  1: OUTPUT
                                           Latch is selected to drive the respective output      <br>  Refer to the
                                           OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t OUTPUT2 : 1; /*!< [1:1] : Selects the output latch to drive OUTPUT2 for OUTPUT-XBAR <br>  0:
                                           OUTPUT Latch is not selected to driven the respective output <br>  1: OUTPUT
                                           Latch is selected to drive the respective output      <br>  Refer to the
                                           OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t OUTPUT3 : 1; /*!< [2:2] : Selects the output latch to drive OUTPUT3 for OUTPUT-XBAR <br>  0:
                                           OUTPUT Latch is not selected to driven the respective output <br>  1: OUTPUT
                                           Latch is selected to drive the respective output      <br>  Refer to the
                                           OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t OUTPUT4 : 1; /*!< [3:3] : Selects the output latch to drive OUTPUT4 for OUTPUT-XBAR <br>  0:
                                           OUTPUT Latch is not selected to driven the respective output <br>  1: OUTPUT
                                           Latch is selected to drive the respective output     <br>  Refer to the
                                           OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t OUTPUT5 : 1; /*!< [4:4] : Selects the output latch to drive OUTPUT5 for OUTPUT-XBAR <br>  0:
                                           OUTPUT Latch is not selected to driven the respective output <br>  1: OUTPUT
                                           Latch is selected to drive the respective output      <br>  Refer to the
                                           OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t OUTPUT6 : 1; /*!< [5:5] : Selects the output latch to drive OUTPUT6 for OUTPUT-XBAR <br>  0:
                                           OUTPUT Latch is not selected to driven the respective output <br>  1: OUTPUT
                                           Latch is selected to drive the respective output      <br>  Refer to the
                                           OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t OUTPUT7 : 1; /*!< [6:6] : Selects the output latch to drive OUTPUT7 for OUTPUT-XBAR <br>  0:
                                           OUTPUT Latch is not selected to driven the respective output <br>  1: OUTPUT
                                           Latch is selected to drive the respective output      <br>  Refer to the
                                           OUTPUT XBAR section of this chapter for more details. */
            __IOM uint32_t OUTPUT8 : 1; /*!< [7:7] : Selects the output latch to drive OUTPUT8 for OUTPUT-XBAR <br>  0:
                                           OUTPUT Latch is not selected to driven the respective output <br>  1: OUTPUT
                                           Latch is selected to drive the respective output      <br>  Refer to the
                                           OUTPUT XBAR section of this chapter for more details. */
            uint32_t RSV_0 : 24;        /*!< [31:8] : reserved. */
        } OUTPUTLATCHENABLEb;
    };

    union
    {
        __IOM uint32_t OUTPUTINV; /*!< 0x00001470 */

        struct
        {
            __IOM uint32_t OUTPUT1 : 1; /*!< [0:0] : Selects polarity for OUTPUT1 of OUTPUT-XBAR <br>  0: drives active
                                           high output                                    <br>  1: drives active-low
                                           output                                     <br>  Refer to the OUTPUT XBAR
                                           section of this chapter for more details. */
            __IOM uint32_t OUTPUT2 : 1; /*!< [1:1] : Selects polarity for OUTPUT2 of OUTPUT-XBAR <br>  0: drives active
                                           high output                                    <br>  1: drives active-low
                                           output                                     <br>  Refer to the OUTPUT XBAR
                                           section of this chapter for more details. */
            __IOM uint32_t OUTPUT3 : 1; /*!< [2:2] : Selects polarity for OUTPUT3 of OUTPUT-XBAR <br>  0: drives active
                                           high output                                    <br>  1: drives active-low
                                           output                                     <br>  Refer to the OUTPUT XBAR
                                           section of this chapter for more details. */
            __IOM uint32_t OUTPUT4 : 1; /*!< [3:3] : Selects polarity for OUTPUT4 of OUTPUT-XBAR <br>  0: drives active
                                           high output                                    <br>  1: drives active-low
                                           output                                     <br>  Refer to the OUTPUT XBAR
                                           section of this chapter for more details. */
            __IOM uint32_t OUTPUT5 : 1; /*!< [4:4] : Selects polarity for OUTPUT5 of OUTPUT-XBAR <br>  0: drives active
                                           high output                                    <br>  1: drives active-low
                                           output                                     <br>  Refer to the OUTPUT XBAR
                                           section of this chapter for more details. */
            __IOM uint32_t OUTPUT6 : 1; /*!< [5:5] : Selects polarity for OUTPUT6 of OUTPUT-XBAR <br>  0: drives active
                                           high output                                    <br>  1: drives active-low
                                           output                                     <br>  Refer to the OUTPUT XBAR
                                           section of this chapter for more details. */
            __IOM uint32_t OUTPUT7 : 1; /*!< [6:6] : Selects polarity for OUTPUT7 of OUTPUT-XBAR <br>  0: drives active
                                           high output                                    <br>  1: drives active-low
                                           output                                     <br>  Refer to the OUTPUT XBAR
                                           section of this chapter for more details. */
            __IOM uint32_t OUTPUT8 : 1; /*!< [7:7] : Selects polarity for OUTPUT8 of OUTPUT-XBAR <br>  0: drives active
                                           high output                                    <br>  1: drives active-low
                                           output                                     <br>  Refer to the OUTPUT XBAR
                                           section of this chapter for more details. */
            uint32_t RSV_0 : 24;        /*!< [31:8] : reserved. */
        } OUTPUTINVb;
    };

    uint8_t RSV_0X1474[8]; /*!< 0x00001474~0x0000147b : reserved */

    union
    {
        __IOM uint32_t OUTPUTLOCK; /*!< 0x0000147c */

        struct
        {
            __IOM uint32_t LOCK  : 1;  /*!< [0:0] : Locks the configuration for OUTPUT-XBAR. */
            uint32_t       RSV_0 : 15; /*!< [15:1] : reserved. */
            __IOM uint32_t KEY : 16; /*!< [31:16] : Bit-0 of this register can be set only if KEY= 0x5a5a           <br>
                                        Reset type: CPU1. */
        } OUTPUTLOCKb;
    };
} OUTPUT_XBAR_Type;

/*!
 * @}
 */

/*!
 * \name XBAR Base Address Definitions
 *
 * @{
 */

/*! \brief INPUT_XBAR base address */
#define INPUT_XBAR_BASE (0x41200000UL)
/*! \brief INPUT_XBAR base pointer */
#define INPUT_XBAR ((INPUT_XBAR_Type *) INPUT_XBAR_BASE)

/*! \brief XBAR base address */
#define XBAR_BASE (0x41200400UL)
/*! \brief XBAR base pointer */
#define XBAR ((XBAR_Type *) XBAR_BASE)

/*! \brief CLBINPUT_XBAR base address */
#define CLBINPUT_XBAR_BASE (0x41200800UL)
/*! \brief CLBINPUT_XBAR base pointer */
#define CLBINPUT_XBAR ((INPUT_XBAR_Type *) CLBINPUT_XBAR_BASE)

/*! \brief EPWM_XBAR base address */
#define EPWM_XBAR_BASE (0x41200c00UL)
/*! \brief EPWM_XBAR base pointer */
#define EPWM_XBAR ((EPWM_XBAR_Type *) EPWM_XBAR_BASE)

/*! \brief CLB_XBAR base address */
#define CLB_XBAR_BASE (0x41201000UL)
/*! \brief CLB_XBAR base pointer */
#define CLB_XBAR ((CLB_XBAR_Type *) CLB_XBAR_BASE)

/*! \brief OUTPUT_XBAR base address */
#define OUTPUT_XBAR_BASE (0x41201400UL)
/*! \brief OUTPUT_XBAR base pointer */
#define OUTPUT_XBAR ((OUTPUT_XBAR_Type *) OUTPUT_XBAR_BASE)

/*! \brief CLBOUTPUT_XBAR base address */
#define CLBOUTPUT_XBAR_BASE (0x41201800UL)
/*! \brief CLBOUTPUT_XBAR base pointer */
#define CLBOUTPUT_XBAR ((OUTPUT_XBAR_Type *) CLBOUTPUT_XBAR_BASE)

/*!
 * @}
 */


/*!
 * \name XBAR Register Bitfield Definitions
 *
 * @{
 */

/* INPUTSELECT bitfield */
#define INPUT_XBAR_INPUTSELECT_SELECT_Pos (0U) /*!< SELECT Postion   0          */
#define INPUT_XBAR_INPUTSELECT_SELECT_Msk \
    (0xffffU << INPUT_XBAR_INPUTSELECT_SELECT_Pos) /*!< SELECT Mask      0x0000FFFF */
#define INPUT_XBAR_INPUTSELECT_SELECT_Set(x)                 \
    (((uint16_t) (x) << INPUT_XBAR_INPUTSELECT_SELECT_Pos) & \
     INPUT_XBAR_INPUTSELECT_SELECT_Msk) /*!< SELECT Set Value            */
#define INPUT_XBAR_INPUTSELECT_SELECT_Get(x)                \
    (((uint16_t) (x) &INPUT_XBAR_INPUTSELECT_SELECT_Msk) >> \
     INPUT_XBAR_INPUTSELECT_SELECT_Pos) /*!< SELECT Get Value            */


/* INPUTSELECTLOCK bitfield */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT16SELECT_Pos (15U) /*!< INPUT16SELECT Postion   15         */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT16SELECT_Msk \
    (0x1U << INPUT_XBAR_INPUTSELECTLOCK_INPUT16SELECT_Pos) /*!< INPUT16SELECT Mask      0x00008000 */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT16SELECT_Set(x)                 \
    (((uint32_t) (x) << INPUT_XBAR_INPUTSELECTLOCK_INPUT16SELECT_Pos) & \
     INPUT_XBAR_INPUTSELECTLOCK_INPUT16SELECT_Msk) /*!< INPUT16SELECT Set Value            */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT16SELECT_Get(x)                \
    (((uint32_t) (x) &INPUT_XBAR_INPUTSELECTLOCK_INPUT16SELECT_Msk) >> \
     INPUT_XBAR_INPUTSELECTLOCK_INPUT16SELECT_Pos) /*!< INPUT16SELECT Get Value            */


#define INPUT_XBAR_INPUTSELECTLOCK_INPUT15SELECT_Pos (14U) /*!< INPUT15SELECT Postion   14         */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT15SELECT_Msk \
    (0x1U << INPUT_XBAR_INPUTSELECTLOCK_INPUT15SELECT_Pos) /*!< INPUT15SELECT Mask      0x00004000 */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT15SELECT_Set(x)                 \
    (((uint32_t) (x) << INPUT_XBAR_INPUTSELECTLOCK_INPUT15SELECT_Pos) & \
     INPUT_XBAR_INPUTSELECTLOCK_INPUT15SELECT_Msk) /*!< INPUT15SELECT Set Value            */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT15SELECT_Get(x)                \
    (((uint32_t) (x) &INPUT_XBAR_INPUTSELECTLOCK_INPUT15SELECT_Msk) >> \
     INPUT_XBAR_INPUTSELECTLOCK_INPUT15SELECT_Pos) /*!< INPUT15SELECT Get Value            */


#define INPUT_XBAR_INPUTSELECTLOCK_INPUT14SELECT_Pos (13U) /*!< INPUT14SELECT Postion   13         */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT14SELECT_Msk \
    (0x1U << INPUT_XBAR_INPUTSELECTLOCK_INPUT14SELECT_Pos) /*!< INPUT14SELECT Mask      0x00002000 */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT14SELECT_Set(x)                 \
    (((uint32_t) (x) << INPUT_XBAR_INPUTSELECTLOCK_INPUT14SELECT_Pos) & \
     INPUT_XBAR_INPUTSELECTLOCK_INPUT14SELECT_Msk) /*!< INPUT14SELECT Set Value            */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT14SELECT_Get(x)                \
    (((uint32_t) (x) &INPUT_XBAR_INPUTSELECTLOCK_INPUT14SELECT_Msk) >> \
     INPUT_XBAR_INPUTSELECTLOCK_INPUT14SELECT_Pos) /*!< INPUT14SELECT Get Value            */


#define INPUT_XBAR_INPUTSELECTLOCK_INPUT13SELECT_Pos (12U) /*!< INPUT13SELECT Postion   12         */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT13SELECT_Msk \
    (0x1U << INPUT_XBAR_INPUTSELECTLOCK_INPUT13SELECT_Pos) /*!< INPUT13SELECT Mask      0x00001000 */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT13SELECT_Set(x)                 \
    (((uint32_t) (x) << INPUT_XBAR_INPUTSELECTLOCK_INPUT13SELECT_Pos) & \
     INPUT_XBAR_INPUTSELECTLOCK_INPUT13SELECT_Msk) /*!< INPUT13SELECT Set Value            */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT13SELECT_Get(x)                \
    (((uint32_t) (x) &INPUT_XBAR_INPUTSELECTLOCK_INPUT13SELECT_Msk) >> \
     INPUT_XBAR_INPUTSELECTLOCK_INPUT13SELECT_Pos) /*!< INPUT13SELECT Get Value            */


#define INPUT_XBAR_INPUTSELECTLOCK_INPUT12SELECT_Pos (11U) /*!< INPUT12SELECT Postion   11         */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT12SELECT_Msk \
    (0x1U << INPUT_XBAR_INPUTSELECTLOCK_INPUT12SELECT_Pos) /*!< INPUT12SELECT Mask      0x00000800 */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT12SELECT_Set(x)                 \
    (((uint32_t) (x) << INPUT_XBAR_INPUTSELECTLOCK_INPUT12SELECT_Pos) & \
     INPUT_XBAR_INPUTSELECTLOCK_INPUT12SELECT_Msk) /*!< INPUT12SELECT Set Value            */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT12SELECT_Get(x)                \
    (((uint32_t) (x) &INPUT_XBAR_INPUTSELECTLOCK_INPUT12SELECT_Msk) >> \
     INPUT_XBAR_INPUTSELECTLOCK_INPUT12SELECT_Pos) /*!< INPUT12SELECT Get Value            */


#define INPUT_XBAR_INPUTSELECTLOCK_INPUT11SELECT_Pos (10U) /*!< INPUT11SELECT Postion   10         */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT11SELECT_Msk \
    (0x1U << INPUT_XBAR_INPUTSELECTLOCK_INPUT11SELECT_Pos) /*!< INPUT11SELECT Mask      0x00000400 */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT11SELECT_Set(x)                 \
    (((uint32_t) (x) << INPUT_XBAR_INPUTSELECTLOCK_INPUT11SELECT_Pos) & \
     INPUT_XBAR_INPUTSELECTLOCK_INPUT11SELECT_Msk) /*!< INPUT11SELECT Set Value            */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT11SELECT_Get(x)                \
    (((uint32_t) (x) &INPUT_XBAR_INPUTSELECTLOCK_INPUT11SELECT_Msk) >> \
     INPUT_XBAR_INPUTSELECTLOCK_INPUT11SELECT_Pos) /*!< INPUT11SELECT Get Value            */


#define INPUT_XBAR_INPUTSELECTLOCK_INPUT10SELECT_Pos (9U) /*!< INPUT10SELECT Postion   9          */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT10SELECT_Msk \
    (0x1U << INPUT_XBAR_INPUTSELECTLOCK_INPUT10SELECT_Pos) /*!< INPUT10SELECT Mask      0x00000200 */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT10SELECT_Set(x)                 \
    (((uint32_t) (x) << INPUT_XBAR_INPUTSELECTLOCK_INPUT10SELECT_Pos) & \
     INPUT_XBAR_INPUTSELECTLOCK_INPUT10SELECT_Msk) /*!< INPUT10SELECT Set Value            */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT10SELECT_Get(x)                \
    (((uint32_t) (x) &INPUT_XBAR_INPUTSELECTLOCK_INPUT10SELECT_Msk) >> \
     INPUT_XBAR_INPUTSELECTLOCK_INPUT10SELECT_Pos) /*!< INPUT10SELECT Get Value            */


#define INPUT_XBAR_INPUTSELECTLOCK_INPUT9SELECT_Pos (8U) /*!< INPUT9SELECT Postion   8          */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT9SELECT_Msk \
    (0x1U << INPUT_XBAR_INPUTSELECTLOCK_INPUT9SELECT_Pos) /*!< INPUT9SELECT Mask      0x00000100 */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT9SELECT_Set(x)                 \
    (((uint32_t) (x) << INPUT_XBAR_INPUTSELECTLOCK_INPUT9SELECT_Pos) & \
     INPUT_XBAR_INPUTSELECTLOCK_INPUT9SELECT_Msk) /*!< INPUT9SELECT Set Value            */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT9SELECT_Get(x)                \
    (((uint32_t) (x) &INPUT_XBAR_INPUTSELECTLOCK_INPUT9SELECT_Msk) >> \
     INPUT_XBAR_INPUTSELECTLOCK_INPUT9SELECT_Pos) /*!< INPUT9SELECT Get Value            */


#define INPUT_XBAR_INPUTSELECTLOCK_INPUT8SELECT_Pos (7U) /*!< INPUT8SELECT Postion   7          */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT8SELECT_Msk \
    (0x1U << INPUT_XBAR_INPUTSELECTLOCK_INPUT8SELECT_Pos) /*!< INPUT8SELECT Mask      0x00000080 */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT8SELECT_Set(x)                 \
    (((uint32_t) (x) << INPUT_XBAR_INPUTSELECTLOCK_INPUT8SELECT_Pos) & \
     INPUT_XBAR_INPUTSELECTLOCK_INPUT8SELECT_Msk) /*!< INPUT8SELECT Set Value            */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT8SELECT_Get(x)                \
    (((uint32_t) (x) &INPUT_XBAR_INPUTSELECTLOCK_INPUT8SELECT_Msk) >> \
     INPUT_XBAR_INPUTSELECTLOCK_INPUT8SELECT_Pos) /*!< INPUT8SELECT Get Value            */


#define INPUT_XBAR_INPUTSELECTLOCK_INPUT7SELECT_Pos (6U) /*!< INPUT7SELECT Postion   6          */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT7SELECT_Msk \
    (0x1U << INPUT_XBAR_INPUTSELECTLOCK_INPUT7SELECT_Pos) /*!< INPUT7SELECT Mask      0x00000040 */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT7SELECT_Set(x)                 \
    (((uint32_t) (x) << INPUT_XBAR_INPUTSELECTLOCK_INPUT7SELECT_Pos) & \
     INPUT_XBAR_INPUTSELECTLOCK_INPUT7SELECT_Msk) /*!< INPUT7SELECT Set Value            */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT7SELECT_Get(x)                \
    (((uint32_t) (x) &INPUT_XBAR_INPUTSELECTLOCK_INPUT7SELECT_Msk) >> \
     INPUT_XBAR_INPUTSELECTLOCK_INPUT7SELECT_Pos) /*!< INPUT7SELECT Get Value            */


#define INPUT_XBAR_INPUTSELECTLOCK_INPUT6SELECT_Pos (5U) /*!< INPUT6SELECT Postion   5          */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT6SELECT_Msk \
    (0x1U << INPUT_XBAR_INPUTSELECTLOCK_INPUT6SELECT_Pos) /*!< INPUT6SELECT Mask      0x00000020 */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT6SELECT_Set(x)                 \
    (((uint32_t) (x) << INPUT_XBAR_INPUTSELECTLOCK_INPUT6SELECT_Pos) & \
     INPUT_XBAR_INPUTSELECTLOCK_INPUT6SELECT_Msk) /*!< INPUT6SELECT Set Value            */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT6SELECT_Get(x)                \
    (((uint32_t) (x) &INPUT_XBAR_INPUTSELECTLOCK_INPUT6SELECT_Msk) >> \
     INPUT_XBAR_INPUTSELECTLOCK_INPUT6SELECT_Pos) /*!< INPUT6SELECT Get Value            */


#define INPUT_XBAR_INPUTSELECTLOCK_INPUT5SELECT_Pos (4U) /*!< INPUT5SELECT Postion   4          */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT5SELECT_Msk \
    (0x1U << INPUT_XBAR_INPUTSELECTLOCK_INPUT5SELECT_Pos) /*!< INPUT5SELECT Mask      0x00000010 */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT5SELECT_Set(x)                 \
    (((uint32_t) (x) << INPUT_XBAR_INPUTSELECTLOCK_INPUT5SELECT_Pos) & \
     INPUT_XBAR_INPUTSELECTLOCK_INPUT5SELECT_Msk) /*!< INPUT5SELECT Set Value            */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT5SELECT_Get(x)                \
    (((uint32_t) (x) &INPUT_XBAR_INPUTSELECTLOCK_INPUT5SELECT_Msk) >> \
     INPUT_XBAR_INPUTSELECTLOCK_INPUT5SELECT_Pos) /*!< INPUT5SELECT Get Value            */


#define INPUT_XBAR_INPUTSELECTLOCK_INPUT4SELECT_Pos (3U) /*!< INPUT4SELECT Postion   3          */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT4SELECT_Msk \
    (0x1U << INPUT_XBAR_INPUTSELECTLOCK_INPUT4SELECT_Pos) /*!< INPUT4SELECT Mask      0x00000008 */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT4SELECT_Set(x)                 \
    (((uint32_t) (x) << INPUT_XBAR_INPUTSELECTLOCK_INPUT4SELECT_Pos) & \
     INPUT_XBAR_INPUTSELECTLOCK_INPUT4SELECT_Msk) /*!< INPUT4SELECT Set Value            */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT4SELECT_Get(x)                \
    (((uint32_t) (x) &INPUT_XBAR_INPUTSELECTLOCK_INPUT4SELECT_Msk) >> \
     INPUT_XBAR_INPUTSELECTLOCK_INPUT4SELECT_Pos) /*!< INPUT4SELECT Get Value            */


#define INPUT_XBAR_INPUTSELECTLOCK_INPUT3SELECT_Pos (2U) /*!< INPUT3SELECT Postion   2          */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT3SELECT_Msk \
    (0x1U << INPUT_XBAR_INPUTSELECTLOCK_INPUT3SELECT_Pos) /*!< INPUT3SELECT Mask      0x00000004 */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT3SELECT_Set(x)                 \
    (((uint32_t) (x) << INPUT_XBAR_INPUTSELECTLOCK_INPUT3SELECT_Pos) & \
     INPUT_XBAR_INPUTSELECTLOCK_INPUT3SELECT_Msk) /*!< INPUT3SELECT Set Value            */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT3SELECT_Get(x)                \
    (((uint32_t) (x) &INPUT_XBAR_INPUTSELECTLOCK_INPUT3SELECT_Msk) >> \
     INPUT_XBAR_INPUTSELECTLOCK_INPUT3SELECT_Pos) /*!< INPUT3SELECT Get Value            */


#define INPUT_XBAR_INPUTSELECTLOCK_INPUT2SELECT_Pos (1U) /*!< INPUT2SELECT Postion   1          */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT2SELECT_Msk \
    (0x1U << INPUT_XBAR_INPUTSELECTLOCK_INPUT2SELECT_Pos) /*!< INPUT2SELECT Mask      0x00000002 */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT2SELECT_Set(x)                 \
    (((uint32_t) (x) << INPUT_XBAR_INPUTSELECTLOCK_INPUT2SELECT_Pos) & \
     INPUT_XBAR_INPUTSELECTLOCK_INPUT2SELECT_Msk) /*!< INPUT2SELECT Set Value            */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT2SELECT_Get(x)                \
    (((uint32_t) (x) &INPUT_XBAR_INPUTSELECTLOCK_INPUT2SELECT_Msk) >> \
     INPUT_XBAR_INPUTSELECTLOCK_INPUT2SELECT_Pos) /*!< INPUT2SELECT Get Value            */


#define INPUT_XBAR_INPUTSELECTLOCK_INPUT1SELECT_Pos (0U) /*!< INPUT1SELECT Postion   0          */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT1SELECT_Msk \
    (0x1U << INPUT_XBAR_INPUTSELECTLOCK_INPUT1SELECT_Pos) /*!< INPUT1SELECT Mask      0x00000001 */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT1SELECT_Set(x)                 \
    (((uint32_t) (x) << INPUT_XBAR_INPUTSELECTLOCK_INPUT1SELECT_Pos) & \
     INPUT_XBAR_INPUTSELECTLOCK_INPUT1SELECT_Msk) /*!< INPUT1SELECT Set Value            */
#define INPUT_XBAR_INPUTSELECTLOCK_INPUT1SELECT_Get(x)                \
    (((uint32_t) (x) &INPUT_XBAR_INPUTSELECTLOCK_INPUT1SELECT_Msk) >> \
     INPUT_XBAR_INPUTSELECTLOCK_INPUT1SELECT_Pos) /*!< INPUT1SELECT Get Value            */


/* XBARFLG1 bitfield */
#define XBAR_XBARFLG1_CMPSS8_CTRIPOUTH_Pos (31U) /*!< CMPSS8_CTRIPOUTH Postion   31         */
#define XBAR_XBARFLG1_CMPSS8_CTRIPOUTH_Msk \
    (0x1U << XBAR_XBARFLG1_CMPSS8_CTRIPOUTH_Pos) /*!< CMPSS8_CTRIPOUTH Mask      0x80000000 */
#define XBAR_XBARFLG1_CMPSS8_CTRIPOUTH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG1_CMPSS8_CTRIPOUTH_Pos) & \
     XBAR_XBARFLG1_CMPSS8_CTRIPOUTH_Msk) /*!< CMPSS8_CTRIPOUTH Set Value            */
#define XBAR_XBARFLG1_CMPSS8_CTRIPOUTH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG1_CMPSS8_CTRIPOUTH_Msk) >> \
     XBAR_XBARFLG1_CMPSS8_CTRIPOUTH_Pos) /*!< CMPSS8_CTRIPOUTH Get Value            */


#define XBAR_XBARFLG1_CMPSS8_CTRIPOUTL_Pos (30U) /*!< CMPSS8_CTRIPOUTL Postion   30         */
#define XBAR_XBARFLG1_CMPSS8_CTRIPOUTL_Msk \
    (0x1U << XBAR_XBARFLG1_CMPSS8_CTRIPOUTL_Pos) /*!< CMPSS8_CTRIPOUTL Mask      0x40000000 */
#define XBAR_XBARFLG1_CMPSS8_CTRIPOUTL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG1_CMPSS8_CTRIPOUTL_Pos) & \
     XBAR_XBARFLG1_CMPSS8_CTRIPOUTL_Msk) /*!< CMPSS8_CTRIPOUTL Set Value            */
#define XBAR_XBARFLG1_CMPSS8_CTRIPOUTL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG1_CMPSS8_CTRIPOUTL_Msk) >> \
     XBAR_XBARFLG1_CMPSS8_CTRIPOUTL_Pos) /*!< CMPSS8_CTRIPOUTL Get Value            */


#define XBAR_XBARFLG1_CMPSS7_CTRIPOUTH_Pos (29U) /*!< CMPSS7_CTRIPOUTH Postion   29         */
#define XBAR_XBARFLG1_CMPSS7_CTRIPOUTH_Msk \
    (0x1U << XBAR_XBARFLG1_CMPSS7_CTRIPOUTH_Pos) /*!< CMPSS7_CTRIPOUTH Mask      0x20000000 */
#define XBAR_XBARFLG1_CMPSS7_CTRIPOUTH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG1_CMPSS7_CTRIPOUTH_Pos) & \
     XBAR_XBARFLG1_CMPSS7_CTRIPOUTH_Msk) /*!< CMPSS7_CTRIPOUTH Set Value            */
#define XBAR_XBARFLG1_CMPSS7_CTRIPOUTH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG1_CMPSS7_CTRIPOUTH_Msk) >> \
     XBAR_XBARFLG1_CMPSS7_CTRIPOUTH_Pos) /*!< CMPSS7_CTRIPOUTH Get Value            */


#define XBAR_XBARFLG1_CMPSS7_CTRIPOUTL_Pos (28U) /*!< CMPSS7_CTRIPOUTL Postion   28         */
#define XBAR_XBARFLG1_CMPSS7_CTRIPOUTL_Msk \
    (0x1U << XBAR_XBARFLG1_CMPSS7_CTRIPOUTL_Pos) /*!< CMPSS7_CTRIPOUTL Mask      0x10000000 */
#define XBAR_XBARFLG1_CMPSS7_CTRIPOUTL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG1_CMPSS7_CTRIPOUTL_Pos) & \
     XBAR_XBARFLG1_CMPSS7_CTRIPOUTL_Msk) /*!< CMPSS7_CTRIPOUTL Set Value            */
#define XBAR_XBARFLG1_CMPSS7_CTRIPOUTL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG1_CMPSS7_CTRIPOUTL_Msk) >> \
     XBAR_XBARFLG1_CMPSS7_CTRIPOUTL_Pos) /*!< CMPSS7_CTRIPOUTL Get Value            */


#define XBAR_XBARFLG1_CMPSS6_CTRIPOUTH_Pos (27U) /*!< CMPSS6_CTRIPOUTH Postion   27         */
#define XBAR_XBARFLG1_CMPSS6_CTRIPOUTH_Msk \
    (0x1U << XBAR_XBARFLG1_CMPSS6_CTRIPOUTH_Pos) /*!< CMPSS6_CTRIPOUTH Mask      0x08000000 */
#define XBAR_XBARFLG1_CMPSS6_CTRIPOUTH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG1_CMPSS6_CTRIPOUTH_Pos) & \
     XBAR_XBARFLG1_CMPSS6_CTRIPOUTH_Msk) /*!< CMPSS6_CTRIPOUTH Set Value            */
#define XBAR_XBARFLG1_CMPSS6_CTRIPOUTH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG1_CMPSS6_CTRIPOUTH_Msk) >> \
     XBAR_XBARFLG1_CMPSS6_CTRIPOUTH_Pos) /*!< CMPSS6_CTRIPOUTH Get Value            */


#define XBAR_XBARFLG1_CMPSS6_CTRIPOUTL_Pos (26U) /*!< CMPSS6_CTRIPOUTL Postion   26         */
#define XBAR_XBARFLG1_CMPSS6_CTRIPOUTL_Msk \
    (0x1U << XBAR_XBARFLG1_CMPSS6_CTRIPOUTL_Pos) /*!< CMPSS6_CTRIPOUTL Mask      0x04000000 */
#define XBAR_XBARFLG1_CMPSS6_CTRIPOUTL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG1_CMPSS6_CTRIPOUTL_Pos) & \
     XBAR_XBARFLG1_CMPSS6_CTRIPOUTL_Msk) /*!< CMPSS6_CTRIPOUTL Set Value            */
#define XBAR_XBARFLG1_CMPSS6_CTRIPOUTL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG1_CMPSS6_CTRIPOUTL_Msk) >> \
     XBAR_XBARFLG1_CMPSS6_CTRIPOUTL_Pos) /*!< CMPSS6_CTRIPOUTL Get Value            */


#define XBAR_XBARFLG1_CMPSS5_CTRIPOUTH_Pos (25U) /*!< CMPSS5_CTRIPOUTH Postion   25         */
#define XBAR_XBARFLG1_CMPSS5_CTRIPOUTH_Msk \
    (0x1U << XBAR_XBARFLG1_CMPSS5_CTRIPOUTH_Pos) /*!< CMPSS5_CTRIPOUTH Mask      0x02000000 */
#define XBAR_XBARFLG1_CMPSS5_CTRIPOUTH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG1_CMPSS5_CTRIPOUTH_Pos) & \
     XBAR_XBARFLG1_CMPSS5_CTRIPOUTH_Msk) /*!< CMPSS5_CTRIPOUTH Set Value            */
#define XBAR_XBARFLG1_CMPSS5_CTRIPOUTH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG1_CMPSS5_CTRIPOUTH_Msk) >> \
     XBAR_XBARFLG1_CMPSS5_CTRIPOUTH_Pos) /*!< CMPSS5_CTRIPOUTH Get Value            */


#define XBAR_XBARFLG1_CMPSS5_CTRIPOUTL_Pos (24U) /*!< CMPSS5_CTRIPOUTL Postion   24         */
#define XBAR_XBARFLG1_CMPSS5_CTRIPOUTL_Msk \
    (0x1U << XBAR_XBARFLG1_CMPSS5_CTRIPOUTL_Pos) /*!< CMPSS5_CTRIPOUTL Mask      0x01000000 */
#define XBAR_XBARFLG1_CMPSS5_CTRIPOUTL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG1_CMPSS5_CTRIPOUTL_Pos) & \
     XBAR_XBARFLG1_CMPSS5_CTRIPOUTL_Msk) /*!< CMPSS5_CTRIPOUTL Set Value            */
#define XBAR_XBARFLG1_CMPSS5_CTRIPOUTL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG1_CMPSS5_CTRIPOUTL_Msk) >> \
     XBAR_XBARFLG1_CMPSS5_CTRIPOUTL_Pos) /*!< CMPSS5_CTRIPOUTL Get Value            */


#define XBAR_XBARFLG1_CMPSS4_CTRIPOUTH_Pos (23U) /*!< CMPSS4_CTRIPOUTH Postion   23         */
#define XBAR_XBARFLG1_CMPSS4_CTRIPOUTH_Msk \
    (0x1U << XBAR_XBARFLG1_CMPSS4_CTRIPOUTH_Pos) /*!< CMPSS4_CTRIPOUTH Mask      0x00800000 */
#define XBAR_XBARFLG1_CMPSS4_CTRIPOUTH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG1_CMPSS4_CTRIPOUTH_Pos) & \
     XBAR_XBARFLG1_CMPSS4_CTRIPOUTH_Msk) /*!< CMPSS4_CTRIPOUTH Set Value            */
#define XBAR_XBARFLG1_CMPSS4_CTRIPOUTH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG1_CMPSS4_CTRIPOUTH_Msk) >> \
     XBAR_XBARFLG1_CMPSS4_CTRIPOUTH_Pos) /*!< CMPSS4_CTRIPOUTH Get Value            */


#define XBAR_XBARFLG1_CMPSS4_CTRIPOUTL_Pos (22U) /*!< CMPSS4_CTRIPOUTL Postion   22         */
#define XBAR_XBARFLG1_CMPSS4_CTRIPOUTL_Msk \
    (0x1U << XBAR_XBARFLG1_CMPSS4_CTRIPOUTL_Pos) /*!< CMPSS4_CTRIPOUTL Mask      0x00400000 */
#define XBAR_XBARFLG1_CMPSS4_CTRIPOUTL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG1_CMPSS4_CTRIPOUTL_Pos) & \
     XBAR_XBARFLG1_CMPSS4_CTRIPOUTL_Msk) /*!< CMPSS4_CTRIPOUTL Set Value            */
#define XBAR_XBARFLG1_CMPSS4_CTRIPOUTL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG1_CMPSS4_CTRIPOUTL_Msk) >> \
     XBAR_XBARFLG1_CMPSS4_CTRIPOUTL_Pos) /*!< CMPSS4_CTRIPOUTL Get Value            */


#define XBAR_XBARFLG1_CMPSS3_CTRIPOUTH_Pos (21U) /*!< CMPSS3_CTRIPOUTH Postion   21         */
#define XBAR_XBARFLG1_CMPSS3_CTRIPOUTH_Msk \
    (0x1U << XBAR_XBARFLG1_CMPSS3_CTRIPOUTH_Pos) /*!< CMPSS3_CTRIPOUTH Mask      0x00200000 */
#define XBAR_XBARFLG1_CMPSS3_CTRIPOUTH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG1_CMPSS3_CTRIPOUTH_Pos) & \
     XBAR_XBARFLG1_CMPSS3_CTRIPOUTH_Msk) /*!< CMPSS3_CTRIPOUTH Set Value            */
#define XBAR_XBARFLG1_CMPSS3_CTRIPOUTH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG1_CMPSS3_CTRIPOUTH_Msk) >> \
     XBAR_XBARFLG1_CMPSS3_CTRIPOUTH_Pos) /*!< CMPSS3_CTRIPOUTH Get Value            */


#define XBAR_XBARFLG1_CMPSS3_CTRIPOUTL_Pos (20U) /*!< CMPSS3_CTRIPOUTL Postion   20         */
#define XBAR_XBARFLG1_CMPSS3_CTRIPOUTL_Msk \
    (0x1U << XBAR_XBARFLG1_CMPSS3_CTRIPOUTL_Pos) /*!< CMPSS3_CTRIPOUTL Mask      0x00100000 */
#define XBAR_XBARFLG1_CMPSS3_CTRIPOUTL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG1_CMPSS3_CTRIPOUTL_Pos) & \
     XBAR_XBARFLG1_CMPSS3_CTRIPOUTL_Msk) /*!< CMPSS3_CTRIPOUTL Set Value            */
#define XBAR_XBARFLG1_CMPSS3_CTRIPOUTL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG1_CMPSS3_CTRIPOUTL_Msk) >> \
     XBAR_XBARFLG1_CMPSS3_CTRIPOUTL_Pos) /*!< CMPSS3_CTRIPOUTL Get Value            */


#define XBAR_XBARFLG1_CMPSS2_CTRIPOUTH_Pos (19U) /*!< CMPSS2_CTRIPOUTH Postion   19         */
#define XBAR_XBARFLG1_CMPSS2_CTRIPOUTH_Msk \
    (0x1U << XBAR_XBARFLG1_CMPSS2_CTRIPOUTH_Pos) /*!< CMPSS2_CTRIPOUTH Mask      0x00080000 */
#define XBAR_XBARFLG1_CMPSS2_CTRIPOUTH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG1_CMPSS2_CTRIPOUTH_Pos) & \
     XBAR_XBARFLG1_CMPSS2_CTRIPOUTH_Msk) /*!< CMPSS2_CTRIPOUTH Set Value            */
#define XBAR_XBARFLG1_CMPSS2_CTRIPOUTH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG1_CMPSS2_CTRIPOUTH_Msk) >> \
     XBAR_XBARFLG1_CMPSS2_CTRIPOUTH_Pos) /*!< CMPSS2_CTRIPOUTH Get Value            */


#define XBAR_XBARFLG1_CMPSS2_CTRIPOUTL_Pos (18U) /*!< CMPSS2_CTRIPOUTL Postion   18         */
#define XBAR_XBARFLG1_CMPSS2_CTRIPOUTL_Msk \
    (0x1U << XBAR_XBARFLG1_CMPSS2_CTRIPOUTL_Pos) /*!< CMPSS2_CTRIPOUTL Mask      0x00040000 */
#define XBAR_XBARFLG1_CMPSS2_CTRIPOUTL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG1_CMPSS2_CTRIPOUTL_Pos) & \
     XBAR_XBARFLG1_CMPSS2_CTRIPOUTL_Msk) /*!< CMPSS2_CTRIPOUTL Set Value            */
#define XBAR_XBARFLG1_CMPSS2_CTRIPOUTL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG1_CMPSS2_CTRIPOUTL_Msk) >> \
     XBAR_XBARFLG1_CMPSS2_CTRIPOUTL_Pos) /*!< CMPSS2_CTRIPOUTL Get Value            */


#define XBAR_XBARFLG1_CMPSS1_CTRIPOUTH_Pos (17U) /*!< CMPSS1_CTRIPOUTH Postion   17         */
#define XBAR_XBARFLG1_CMPSS1_CTRIPOUTH_Msk \
    (0x1U << XBAR_XBARFLG1_CMPSS1_CTRIPOUTH_Pos) /*!< CMPSS1_CTRIPOUTH Mask      0x00020000 */
#define XBAR_XBARFLG1_CMPSS1_CTRIPOUTH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG1_CMPSS1_CTRIPOUTH_Pos) & \
     XBAR_XBARFLG1_CMPSS1_CTRIPOUTH_Msk) /*!< CMPSS1_CTRIPOUTH Set Value            */
#define XBAR_XBARFLG1_CMPSS1_CTRIPOUTH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG1_CMPSS1_CTRIPOUTH_Msk) >> \
     XBAR_XBARFLG1_CMPSS1_CTRIPOUTH_Pos) /*!< CMPSS1_CTRIPOUTH Get Value            */


#define XBAR_XBARFLG1_CMPSS1_CTRIPOUTL_Pos (16U) /*!< CMPSS1_CTRIPOUTL Postion   16         */
#define XBAR_XBARFLG1_CMPSS1_CTRIPOUTL_Msk \
    (0x1U << XBAR_XBARFLG1_CMPSS1_CTRIPOUTL_Pos) /*!< CMPSS1_CTRIPOUTL Mask      0x00010000 */
#define XBAR_XBARFLG1_CMPSS1_CTRIPOUTL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG1_CMPSS1_CTRIPOUTL_Pos) & \
     XBAR_XBARFLG1_CMPSS1_CTRIPOUTL_Msk) /*!< CMPSS1_CTRIPOUTL Set Value            */
#define XBAR_XBARFLG1_CMPSS1_CTRIPOUTL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG1_CMPSS1_CTRIPOUTL_Msk) >> \
     XBAR_XBARFLG1_CMPSS1_CTRIPOUTL_Pos) /*!< CMPSS1_CTRIPOUTL Get Value            */


#define XBAR_XBARFLG1_CMPSS8_CTRIPH_Pos (15U) /*!< CMPSS8_CTRIPH Postion   15         */
#define XBAR_XBARFLG1_CMPSS8_CTRIPH_Msk \
    (0x1U << XBAR_XBARFLG1_CMPSS8_CTRIPH_Pos) /*!< CMPSS8_CTRIPH Mask      0x00008000 */
#define XBAR_XBARFLG1_CMPSS8_CTRIPH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG1_CMPSS8_CTRIPH_Pos) & \
     XBAR_XBARFLG1_CMPSS8_CTRIPH_Msk) /*!< CMPSS8_CTRIPH Set Value            */
#define XBAR_XBARFLG1_CMPSS8_CTRIPH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG1_CMPSS8_CTRIPH_Msk) >> \
     XBAR_XBARFLG1_CMPSS8_CTRIPH_Pos) /*!< CMPSS8_CTRIPH Get Value            */


#define XBAR_XBARFLG1_CMPSS8_CTRIPL_Pos (14U) /*!< CMPSS8_CTRIPL Postion   14         */
#define XBAR_XBARFLG1_CMPSS8_CTRIPL_Msk \
    (0x1U << XBAR_XBARFLG1_CMPSS8_CTRIPL_Pos) /*!< CMPSS8_CTRIPL Mask      0x00004000 */
#define XBAR_XBARFLG1_CMPSS8_CTRIPL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG1_CMPSS8_CTRIPL_Pos) & \
     XBAR_XBARFLG1_CMPSS8_CTRIPL_Msk) /*!< CMPSS8_CTRIPL Set Value            */
#define XBAR_XBARFLG1_CMPSS8_CTRIPL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG1_CMPSS8_CTRIPL_Msk) >> \
     XBAR_XBARFLG1_CMPSS8_CTRIPL_Pos) /*!< CMPSS8_CTRIPL Get Value            */


#define XBAR_XBARFLG1_CMPSS7_CTRIPH_Pos (13U) /*!< CMPSS7_CTRIPH Postion   13         */
#define XBAR_XBARFLG1_CMPSS7_CTRIPH_Msk \
    (0x1U << XBAR_XBARFLG1_CMPSS7_CTRIPH_Pos) /*!< CMPSS7_CTRIPH Mask      0x00002000 */
#define XBAR_XBARFLG1_CMPSS7_CTRIPH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG1_CMPSS7_CTRIPH_Pos) & \
     XBAR_XBARFLG1_CMPSS7_CTRIPH_Msk) /*!< CMPSS7_CTRIPH Set Value            */
#define XBAR_XBARFLG1_CMPSS7_CTRIPH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG1_CMPSS7_CTRIPH_Msk) >> \
     XBAR_XBARFLG1_CMPSS7_CTRIPH_Pos) /*!< CMPSS7_CTRIPH Get Value            */


#define XBAR_XBARFLG1_CMPSS7_CTRIPL_Pos (12U) /*!< CMPSS7_CTRIPL Postion   12         */
#define XBAR_XBARFLG1_CMPSS7_CTRIPL_Msk \
    (0x1U << XBAR_XBARFLG1_CMPSS7_CTRIPL_Pos) /*!< CMPSS7_CTRIPL Mask      0x00001000 */
#define XBAR_XBARFLG1_CMPSS7_CTRIPL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG1_CMPSS7_CTRIPL_Pos) & \
     XBAR_XBARFLG1_CMPSS7_CTRIPL_Msk) /*!< CMPSS7_CTRIPL Set Value            */
#define XBAR_XBARFLG1_CMPSS7_CTRIPL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG1_CMPSS7_CTRIPL_Msk) >> \
     XBAR_XBARFLG1_CMPSS7_CTRIPL_Pos) /*!< CMPSS7_CTRIPL Get Value            */


#define XBAR_XBARFLG1_CMPSS6_CTRIPH_Pos (11U) /*!< CMPSS6_CTRIPH Postion   11         */
#define XBAR_XBARFLG1_CMPSS6_CTRIPH_Msk \
    (0x1U << XBAR_XBARFLG1_CMPSS6_CTRIPH_Pos) /*!< CMPSS6_CTRIPH Mask      0x00000800 */
#define XBAR_XBARFLG1_CMPSS6_CTRIPH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG1_CMPSS6_CTRIPH_Pos) & \
     XBAR_XBARFLG1_CMPSS6_CTRIPH_Msk) /*!< CMPSS6_CTRIPH Set Value            */
#define XBAR_XBARFLG1_CMPSS6_CTRIPH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG1_CMPSS6_CTRIPH_Msk) >> \
     XBAR_XBARFLG1_CMPSS6_CTRIPH_Pos) /*!< CMPSS6_CTRIPH Get Value            */


#define XBAR_XBARFLG1_CMPSS6_CTRIPL_Pos (10U) /*!< CMPSS6_CTRIPL Postion   10         */
#define XBAR_XBARFLG1_CMPSS6_CTRIPL_Msk \
    (0x1U << XBAR_XBARFLG1_CMPSS6_CTRIPL_Pos) /*!< CMPSS6_CTRIPL Mask      0x00000400 */
#define XBAR_XBARFLG1_CMPSS6_CTRIPL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG1_CMPSS6_CTRIPL_Pos) & \
     XBAR_XBARFLG1_CMPSS6_CTRIPL_Msk) /*!< CMPSS6_CTRIPL Set Value            */
#define XBAR_XBARFLG1_CMPSS6_CTRIPL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG1_CMPSS6_CTRIPL_Msk) >> \
     XBAR_XBARFLG1_CMPSS6_CTRIPL_Pos) /*!< CMPSS6_CTRIPL Get Value            */


#define XBAR_XBARFLG1_CMPSS5_CTRIPH_Pos (9U) /*!< CMPSS5_CTRIPH Postion   9          */
#define XBAR_XBARFLG1_CMPSS5_CTRIPH_Msk \
    (0x1U << XBAR_XBARFLG1_CMPSS5_CTRIPH_Pos) /*!< CMPSS5_CTRIPH Mask      0x00000200 */
#define XBAR_XBARFLG1_CMPSS5_CTRIPH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG1_CMPSS5_CTRIPH_Pos) & \
     XBAR_XBARFLG1_CMPSS5_CTRIPH_Msk) /*!< CMPSS5_CTRIPH Set Value            */
#define XBAR_XBARFLG1_CMPSS5_CTRIPH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG1_CMPSS5_CTRIPH_Msk) >> \
     XBAR_XBARFLG1_CMPSS5_CTRIPH_Pos) /*!< CMPSS5_CTRIPH Get Value            */


#define XBAR_XBARFLG1_CMPSS5_CTRIPL_Pos (8U) /*!< CMPSS5_CTRIPL Postion   8          */
#define XBAR_XBARFLG1_CMPSS5_CTRIPL_Msk \
    (0x1U << XBAR_XBARFLG1_CMPSS5_CTRIPL_Pos) /*!< CMPSS5_CTRIPL Mask      0x00000100 */
#define XBAR_XBARFLG1_CMPSS5_CTRIPL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG1_CMPSS5_CTRIPL_Pos) & \
     XBAR_XBARFLG1_CMPSS5_CTRIPL_Msk) /*!< CMPSS5_CTRIPL Set Value            */
#define XBAR_XBARFLG1_CMPSS5_CTRIPL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG1_CMPSS5_CTRIPL_Msk) >> \
     XBAR_XBARFLG1_CMPSS5_CTRIPL_Pos) /*!< CMPSS5_CTRIPL Get Value            */


#define XBAR_XBARFLG1_CMPSS4_CTRIPH_Pos (7U) /*!< CMPSS4_CTRIPH Postion   7          */
#define XBAR_XBARFLG1_CMPSS4_CTRIPH_Msk \
    (0x1U << XBAR_XBARFLG1_CMPSS4_CTRIPH_Pos) /*!< CMPSS4_CTRIPH Mask      0x00000080 */
#define XBAR_XBARFLG1_CMPSS4_CTRIPH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG1_CMPSS4_CTRIPH_Pos) & \
     XBAR_XBARFLG1_CMPSS4_CTRIPH_Msk) /*!< CMPSS4_CTRIPH Set Value            */
#define XBAR_XBARFLG1_CMPSS4_CTRIPH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG1_CMPSS4_CTRIPH_Msk) >> \
     XBAR_XBARFLG1_CMPSS4_CTRIPH_Pos) /*!< CMPSS4_CTRIPH Get Value            */


#define XBAR_XBARFLG1_CMPSS4_CTRIPL_Pos (6U) /*!< CMPSS4_CTRIPL Postion   6          */
#define XBAR_XBARFLG1_CMPSS4_CTRIPL_Msk \
    (0x1U << XBAR_XBARFLG1_CMPSS4_CTRIPL_Pos) /*!< CMPSS4_CTRIPL Mask      0x00000040 */
#define XBAR_XBARFLG1_CMPSS4_CTRIPL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG1_CMPSS4_CTRIPL_Pos) & \
     XBAR_XBARFLG1_CMPSS4_CTRIPL_Msk) /*!< CMPSS4_CTRIPL Set Value            */
#define XBAR_XBARFLG1_CMPSS4_CTRIPL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG1_CMPSS4_CTRIPL_Msk) >> \
     XBAR_XBARFLG1_CMPSS4_CTRIPL_Pos) /*!< CMPSS4_CTRIPL Get Value            */


#define XBAR_XBARFLG1_CMPSS3_CTRIPH_Pos (5U) /*!< CMPSS3_CTRIPH Postion   5          */
#define XBAR_XBARFLG1_CMPSS3_CTRIPH_Msk \
    (0x1U << XBAR_XBARFLG1_CMPSS3_CTRIPH_Pos) /*!< CMPSS3_CTRIPH Mask      0x00000020 */
#define XBAR_XBARFLG1_CMPSS3_CTRIPH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG1_CMPSS3_CTRIPH_Pos) & \
     XBAR_XBARFLG1_CMPSS3_CTRIPH_Msk) /*!< CMPSS3_CTRIPH Set Value            */
#define XBAR_XBARFLG1_CMPSS3_CTRIPH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG1_CMPSS3_CTRIPH_Msk) >> \
     XBAR_XBARFLG1_CMPSS3_CTRIPH_Pos) /*!< CMPSS3_CTRIPH Get Value            */


#define XBAR_XBARFLG1_CMPSS3_CTRIPL_Pos (4U) /*!< CMPSS3_CTRIPL Postion   4          */
#define XBAR_XBARFLG1_CMPSS3_CTRIPL_Msk \
    (0x1U << XBAR_XBARFLG1_CMPSS3_CTRIPL_Pos) /*!< CMPSS3_CTRIPL Mask      0x00000010 */
#define XBAR_XBARFLG1_CMPSS3_CTRIPL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG1_CMPSS3_CTRIPL_Pos) & \
     XBAR_XBARFLG1_CMPSS3_CTRIPL_Msk) /*!< CMPSS3_CTRIPL Set Value            */
#define XBAR_XBARFLG1_CMPSS3_CTRIPL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG1_CMPSS3_CTRIPL_Msk) >> \
     XBAR_XBARFLG1_CMPSS3_CTRIPL_Pos) /*!< CMPSS3_CTRIPL Get Value            */


#define XBAR_XBARFLG1_CMPSS2_CTRIPH_Pos (3U) /*!< CMPSS2_CTRIPH Postion   3          */
#define XBAR_XBARFLG1_CMPSS2_CTRIPH_Msk \
    (0x1U << XBAR_XBARFLG1_CMPSS2_CTRIPH_Pos) /*!< CMPSS2_CTRIPH Mask      0x00000008 */
#define XBAR_XBARFLG1_CMPSS2_CTRIPH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG1_CMPSS2_CTRIPH_Pos) & \
     XBAR_XBARFLG1_CMPSS2_CTRIPH_Msk) /*!< CMPSS2_CTRIPH Set Value            */
#define XBAR_XBARFLG1_CMPSS2_CTRIPH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG1_CMPSS2_CTRIPH_Msk) >> \
     XBAR_XBARFLG1_CMPSS2_CTRIPH_Pos) /*!< CMPSS2_CTRIPH Get Value            */


#define XBAR_XBARFLG1_CMPSS2_CTRIPL_Pos (2U) /*!< CMPSS2_CTRIPL Postion   2          */
#define XBAR_XBARFLG1_CMPSS2_CTRIPL_Msk \
    (0x1U << XBAR_XBARFLG1_CMPSS2_CTRIPL_Pos) /*!< CMPSS2_CTRIPL Mask      0x00000004 */
#define XBAR_XBARFLG1_CMPSS2_CTRIPL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG1_CMPSS2_CTRIPL_Pos) & \
     XBAR_XBARFLG1_CMPSS2_CTRIPL_Msk) /*!< CMPSS2_CTRIPL Set Value            */
#define XBAR_XBARFLG1_CMPSS2_CTRIPL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG1_CMPSS2_CTRIPL_Msk) >> \
     XBAR_XBARFLG1_CMPSS2_CTRIPL_Pos) /*!< CMPSS2_CTRIPL Get Value            */


#define XBAR_XBARFLG1_CMPSS1_CTRIPH_Pos (1U) /*!< CMPSS1_CTRIPH Postion   1          */
#define XBAR_XBARFLG1_CMPSS1_CTRIPH_Msk \
    (0x1U << XBAR_XBARFLG1_CMPSS1_CTRIPH_Pos) /*!< CMPSS1_CTRIPH Mask      0x00000002 */
#define XBAR_XBARFLG1_CMPSS1_CTRIPH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG1_CMPSS1_CTRIPH_Pos) & \
     XBAR_XBARFLG1_CMPSS1_CTRIPH_Msk) /*!< CMPSS1_CTRIPH Set Value            */
#define XBAR_XBARFLG1_CMPSS1_CTRIPH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG1_CMPSS1_CTRIPH_Msk) >> \
     XBAR_XBARFLG1_CMPSS1_CTRIPH_Pos) /*!< CMPSS1_CTRIPH Get Value            */


#define XBAR_XBARFLG1_CMPSS1_CTRIPL_Pos (0U) /*!< CMPSS1_CTRIPL Postion   0          */
#define XBAR_XBARFLG1_CMPSS1_CTRIPL_Msk \
    (0x1U << XBAR_XBARFLG1_CMPSS1_CTRIPL_Pos) /*!< CMPSS1_CTRIPL Mask      0x00000001 */
#define XBAR_XBARFLG1_CMPSS1_CTRIPL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG1_CMPSS1_CTRIPL_Pos) & \
     XBAR_XBARFLG1_CMPSS1_CTRIPL_Msk) /*!< CMPSS1_CTRIPL Set Value            */
#define XBAR_XBARFLG1_CMPSS1_CTRIPL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG1_CMPSS1_CTRIPL_Msk) >> \
     XBAR_XBARFLG1_CMPSS1_CTRIPL_Pos) /*!< CMPSS1_CTRIPL Get Value            */


/* XBARFLG2 bitfield */
#define XBAR_XBARFLG2_ADCCEVT1_Pos (31U)                                /*!< ADCCEVT1 Postion   31         */
#define XBAR_XBARFLG2_ADCCEVT1_Msk (0x1U << XBAR_XBARFLG2_ADCCEVT1_Pos) /*!< ADCCEVT1 Mask      0x80000000 */
#define XBAR_XBARFLG2_ADCCEVT1_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG2_ADCCEVT1_Pos) & XBAR_XBARFLG2_ADCCEVT1_Msk) /*!< ADCCEVT1 Set Value */
#define XBAR_XBARFLG2_ADCCEVT1_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG2_ADCCEVT1_Msk) >> XBAR_XBARFLG2_ADCCEVT1_Pos) /*!< ADCCEVT1 Get Value            */


#define XBAR_XBARFLG2_ADCBEVT4_Pos (30U)                                /*!< ADCBEVT4 Postion   30         */
#define XBAR_XBARFLG2_ADCBEVT4_Msk (0x1U << XBAR_XBARFLG2_ADCBEVT4_Pos) /*!< ADCBEVT4 Mask      0x40000000 */
#define XBAR_XBARFLG2_ADCBEVT4_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG2_ADCBEVT4_Pos) & XBAR_XBARFLG2_ADCBEVT4_Msk) /*!< ADCBEVT4 Set Value */
#define XBAR_XBARFLG2_ADCBEVT4_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG2_ADCBEVT4_Msk) >> XBAR_XBARFLG2_ADCBEVT4_Pos) /*!< ADCBEVT4 Get Value            */


#define XBAR_XBARFLG2_ADCBEVT3_Pos (29U)                                /*!< ADCBEVT3 Postion   29         */
#define XBAR_XBARFLG2_ADCBEVT3_Msk (0x1U << XBAR_XBARFLG2_ADCBEVT3_Pos) /*!< ADCBEVT3 Mask      0x20000000 */
#define XBAR_XBARFLG2_ADCBEVT3_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG2_ADCBEVT3_Pos) & XBAR_XBARFLG2_ADCBEVT3_Msk) /*!< ADCBEVT3 Set Value */
#define XBAR_XBARFLG2_ADCBEVT3_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG2_ADCBEVT3_Msk) >> XBAR_XBARFLG2_ADCBEVT3_Pos) /*!< ADCBEVT3 Get Value            */


#define XBAR_XBARFLG2_ADCBEVT2_Pos (28U)                                /*!< ADCBEVT2 Postion   28         */
#define XBAR_XBARFLG2_ADCBEVT2_Msk (0x1U << XBAR_XBARFLG2_ADCBEVT2_Pos) /*!< ADCBEVT2 Mask      0x10000000 */
#define XBAR_XBARFLG2_ADCBEVT2_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG2_ADCBEVT2_Pos) & XBAR_XBARFLG2_ADCBEVT2_Msk) /*!< ADCBEVT2 Set Value */
#define XBAR_XBARFLG2_ADCBEVT2_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG2_ADCBEVT2_Msk) >> XBAR_XBARFLG2_ADCBEVT2_Pos) /*!< ADCBEVT2 Get Value            */


#define XBAR_XBARFLG2_ADCBEVT1_Pos (27U)                                /*!< ADCBEVT1 Postion   27         */
#define XBAR_XBARFLG2_ADCBEVT1_Msk (0x1U << XBAR_XBARFLG2_ADCBEVT1_Pos) /*!< ADCBEVT1 Mask      0x08000000 */
#define XBAR_XBARFLG2_ADCBEVT1_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG2_ADCBEVT1_Pos) & XBAR_XBARFLG2_ADCBEVT1_Msk) /*!< ADCBEVT1 Set Value */
#define XBAR_XBARFLG2_ADCBEVT1_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG2_ADCBEVT1_Msk) >> XBAR_XBARFLG2_ADCBEVT1_Pos) /*!< ADCBEVT1 Get Value            */


#define XBAR_XBARFLG2_ADCAEVT4_Pos (26U)                                /*!< ADCAEVT4 Postion   26         */
#define XBAR_XBARFLG2_ADCAEVT4_Msk (0x1U << XBAR_XBARFLG2_ADCAEVT4_Pos) /*!< ADCAEVT4 Mask      0x04000000 */
#define XBAR_XBARFLG2_ADCAEVT4_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG2_ADCAEVT4_Pos) & XBAR_XBARFLG2_ADCAEVT4_Msk) /*!< ADCAEVT4 Set Value */
#define XBAR_XBARFLG2_ADCAEVT4_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG2_ADCAEVT4_Msk) >> XBAR_XBARFLG2_ADCAEVT4_Pos) /*!< ADCAEVT4 Get Value            */


#define XBAR_XBARFLG2_ADCAEVT3_Pos (25U)                                /*!< ADCAEVT3 Postion   25         */
#define XBAR_XBARFLG2_ADCAEVT3_Msk (0x1U << XBAR_XBARFLG2_ADCAEVT3_Pos) /*!< ADCAEVT3 Mask      0x02000000 */
#define XBAR_XBARFLG2_ADCAEVT3_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG2_ADCAEVT3_Pos) & XBAR_XBARFLG2_ADCAEVT3_Msk) /*!< ADCAEVT3 Set Value */
#define XBAR_XBARFLG2_ADCAEVT3_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG2_ADCAEVT3_Msk) >> XBAR_XBARFLG2_ADCAEVT3_Pos) /*!< ADCAEVT3 Get Value            */


#define XBAR_XBARFLG2_ADCAEVT2_Pos (24U)                                /*!< ADCAEVT2 Postion   24         */
#define XBAR_XBARFLG2_ADCAEVT2_Msk (0x1U << XBAR_XBARFLG2_ADCAEVT2_Pos) /*!< ADCAEVT2 Mask      0x01000000 */
#define XBAR_XBARFLG2_ADCAEVT2_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG2_ADCAEVT2_Pos) & XBAR_XBARFLG2_ADCAEVT2_Msk) /*!< ADCAEVT2 Set Value */
#define XBAR_XBARFLG2_ADCAEVT2_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG2_ADCAEVT2_Msk) >> XBAR_XBARFLG2_ADCAEVT2_Pos) /*!< ADCAEVT2 Get Value            */


#define XBAR_XBARFLG2_ADCAEVT1_Pos (23U)                                /*!< ADCAEVT1 Postion   23         */
#define XBAR_XBARFLG2_ADCAEVT1_Msk (0x1U << XBAR_XBARFLG2_ADCAEVT1_Pos) /*!< ADCAEVT1 Mask      0x00800000 */
#define XBAR_XBARFLG2_ADCAEVT1_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG2_ADCAEVT1_Pos) & XBAR_XBARFLG2_ADCAEVT1_Msk) /*!< ADCAEVT1 Set Value */
#define XBAR_XBARFLG2_ADCAEVT1_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG2_ADCAEVT1_Msk) >> XBAR_XBARFLG2_ADCAEVT1_Pos) /*!< ADCAEVT1 Get Value            */


#define XBAR_XBARFLG2_EXTSYNCOUT_Pos (22U)                                  /*!< EXTSYNCOUT Postion   22         */
#define XBAR_XBARFLG2_EXTSYNCOUT_Msk (0x1U << XBAR_XBARFLG2_EXTSYNCOUT_Pos) /*!< EXTSYNCOUT Mask      0x00400000 */
#define XBAR_XBARFLG2_EXTSYNCOUT_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG2_EXTSYNCOUT_Pos) & XBAR_XBARFLG2_EXTSYNCOUT_Msk) /*!< EXTSYNCOUT Set Value */
#define XBAR_XBARFLG2_EXTSYNCOUT_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG2_EXTSYNCOUT_Msk) >> XBAR_XBARFLG2_EXTSYNCOUT_Pos) /*!< EXTSYNCOUT Get Value */


#define XBAR_XBARFLG2_ECAP6_OUT_Pos (21U)                                 /*!< ECAP6_OUT Postion   21         */
#define XBAR_XBARFLG2_ECAP6_OUT_Msk (0x1U << XBAR_XBARFLG2_ECAP6_OUT_Pos) /*!< ECAP6_OUT Mask      0x00200000 */
#define XBAR_XBARFLG2_ECAP6_OUT_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG2_ECAP6_OUT_Pos) & XBAR_XBARFLG2_ECAP6_OUT_Msk) /*!< ECAP6_OUT Set Value */
#define XBAR_XBARFLG2_ECAP6_OUT_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG2_ECAP6_OUT_Msk) >> XBAR_XBARFLG2_ECAP6_OUT_Pos) /*!< ECAP6_OUT Get Value */


#define XBAR_XBARFLG2_ECAP5_OUT_Pos (20U)                                 /*!< ECAP5_OUT Postion   20         */
#define XBAR_XBARFLG2_ECAP5_OUT_Msk (0x1U << XBAR_XBARFLG2_ECAP5_OUT_Pos) /*!< ECAP5_OUT Mask      0x00100000 */
#define XBAR_XBARFLG2_ECAP5_OUT_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG2_ECAP5_OUT_Pos) & XBAR_XBARFLG2_ECAP5_OUT_Msk) /*!< ECAP5_OUT Set Value */
#define XBAR_XBARFLG2_ECAP5_OUT_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG2_ECAP5_OUT_Msk) >> XBAR_XBARFLG2_ECAP5_OUT_Pos) /*!< ECAP5_OUT Get Value */


#define XBAR_XBARFLG2_ECAP4_OUT_Pos (19U)                                 /*!< ECAP4_OUT Postion   19         */
#define XBAR_XBARFLG2_ECAP4_OUT_Msk (0x1U << XBAR_XBARFLG2_ECAP4_OUT_Pos) /*!< ECAP4_OUT Mask      0x00080000 */
#define XBAR_XBARFLG2_ECAP4_OUT_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG2_ECAP4_OUT_Pos) & XBAR_XBARFLG2_ECAP4_OUT_Msk) /*!< ECAP4_OUT Set Value */
#define XBAR_XBARFLG2_ECAP4_OUT_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG2_ECAP4_OUT_Msk) >> XBAR_XBARFLG2_ECAP4_OUT_Pos) /*!< ECAP4_OUT Get Value */


#define XBAR_XBARFLG2_ECAP3_OUT_Pos (18U)                                 /*!< ECAP3_OUT Postion   18         */
#define XBAR_XBARFLG2_ECAP3_OUT_Msk (0x1U << XBAR_XBARFLG2_ECAP3_OUT_Pos) /*!< ECAP3_OUT Mask      0x00040000 */
#define XBAR_XBARFLG2_ECAP3_OUT_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG2_ECAP3_OUT_Pos) & XBAR_XBARFLG2_ECAP3_OUT_Msk) /*!< ECAP3_OUT Set Value */
#define XBAR_XBARFLG2_ECAP3_OUT_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG2_ECAP3_OUT_Msk) >> XBAR_XBARFLG2_ECAP3_OUT_Pos) /*!< ECAP3_OUT Get Value */


#define XBAR_XBARFLG2_ECAP2_OUT_Pos (17U)                                 /*!< ECAP2_OUT Postion   17         */
#define XBAR_XBARFLG2_ECAP2_OUT_Msk (0x1U << XBAR_XBARFLG2_ECAP2_OUT_Pos) /*!< ECAP2_OUT Mask      0x00020000 */
#define XBAR_XBARFLG2_ECAP2_OUT_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG2_ECAP2_OUT_Pos) & XBAR_XBARFLG2_ECAP2_OUT_Msk) /*!< ECAP2_OUT Set Value */
#define XBAR_XBARFLG2_ECAP2_OUT_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG2_ECAP2_OUT_Msk) >> XBAR_XBARFLG2_ECAP2_OUT_Pos) /*!< ECAP2_OUT Get Value */


#define XBAR_XBARFLG2_ECAP1_OUT_Pos (16U)                                 /*!< ECAP1_OUT Postion   16         */
#define XBAR_XBARFLG2_ECAP1_OUT_Msk (0x1U << XBAR_XBARFLG2_ECAP1_OUT_Pos) /*!< ECAP1_OUT Mask      0x00010000 */
#define XBAR_XBARFLG2_ECAP1_OUT_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG2_ECAP1_OUT_Pos) & XBAR_XBARFLG2_ECAP1_OUT_Msk) /*!< ECAP1_OUT Set Value */
#define XBAR_XBARFLG2_ECAP1_OUT_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG2_ECAP1_OUT_Msk) >> XBAR_XBARFLG2_ECAP1_OUT_Pos) /*!< ECAP1_OUT Get Value */


#define XBAR_XBARFLG2_INPUT14_Pos (15U)                               /*!< INPUT14 Postion   15         */
#define XBAR_XBARFLG2_INPUT14_Msk (0x1U << XBAR_XBARFLG2_INPUT14_Pos) /*!< INPUT14 Mask      0x00008000 */
#define XBAR_XBARFLG2_INPUT14_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG2_INPUT14_Pos) & XBAR_XBARFLG2_INPUT14_Msk) /*!< INPUT14 Set Value            */
#define XBAR_XBARFLG2_INPUT14_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG2_INPUT14_Msk) >> XBAR_XBARFLG2_INPUT14_Pos) /*!< INPUT14 Get Value            */


#define XBAR_XBARFLG2_INPUT13_Pos (14U)                               /*!< INPUT13 Postion   14         */
#define XBAR_XBARFLG2_INPUT13_Msk (0x1U << XBAR_XBARFLG2_INPUT13_Pos) /*!< INPUT13 Mask      0x00004000 */
#define XBAR_XBARFLG2_INPUT13_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG2_INPUT13_Pos) & XBAR_XBARFLG2_INPUT13_Msk) /*!< INPUT13 Set Value            */
#define XBAR_XBARFLG2_INPUT13_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG2_INPUT13_Msk) >> XBAR_XBARFLG2_INPUT13_Pos) /*!< INPUT13 Get Value            */


#define XBAR_XBARFLG2_INPUT12_Pos (13U)                               /*!< INPUT12 Postion   13         */
#define XBAR_XBARFLG2_INPUT12_Msk (0x1U << XBAR_XBARFLG2_INPUT12_Pos) /*!< INPUT12 Mask      0x00002000 */
#define XBAR_XBARFLG2_INPUT12_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG2_INPUT12_Pos) & XBAR_XBARFLG2_INPUT12_Msk) /*!< INPUT12 Set Value            */
#define XBAR_XBARFLG2_INPUT12_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG2_INPUT12_Msk) >> XBAR_XBARFLG2_INPUT12_Pos) /*!< INPUT12 Get Value            */


#define XBAR_XBARFLG2_INPUT11_Pos (12U)                               /*!< INPUT11 Postion   12         */
#define XBAR_XBARFLG2_INPUT11_Msk (0x1U << XBAR_XBARFLG2_INPUT11_Pos) /*!< INPUT11 Mask      0x00001000 */
#define XBAR_XBARFLG2_INPUT11_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG2_INPUT11_Pos) & XBAR_XBARFLG2_INPUT11_Msk) /*!< INPUT11 Set Value            */
#define XBAR_XBARFLG2_INPUT11_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG2_INPUT11_Msk) >> XBAR_XBARFLG2_INPUT11_Pos) /*!< INPUT11 Get Value            */


#define XBAR_XBARFLG2_INPUT10_Pos (11U)                               /*!< INPUT10 Postion   11         */
#define XBAR_XBARFLG2_INPUT10_Msk (0x1U << XBAR_XBARFLG2_INPUT10_Pos) /*!< INPUT10 Mask      0x00000800 */
#define XBAR_XBARFLG2_INPUT10_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG2_INPUT10_Pos) & XBAR_XBARFLG2_INPUT10_Msk) /*!< INPUT10 Set Value            */
#define XBAR_XBARFLG2_INPUT10_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG2_INPUT10_Msk) >> XBAR_XBARFLG2_INPUT10_Pos) /*!< INPUT10 Get Value            */


#define XBAR_XBARFLG2_INPUT9_Pos (10U)                              /*!< INPUT9 Postion   10         */
#define XBAR_XBARFLG2_INPUT9_Msk (0x1U << XBAR_XBARFLG2_INPUT9_Pos) /*!< INPUT9 Mask      0x00000400 */
#define XBAR_XBARFLG2_INPUT9_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG2_INPUT9_Pos) & XBAR_XBARFLG2_INPUT9_Msk) /*!< INPUT9 Set Value            */
#define XBAR_XBARFLG2_INPUT9_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG2_INPUT9_Msk) >> XBAR_XBARFLG2_INPUT9_Pos) /*!< INPUT9 Get Value            */


#define XBAR_XBARFLG2_INPUT8_Pos (9U)                               /*!< INPUT8 Postion   9          */
#define XBAR_XBARFLG2_INPUT8_Msk (0x1U << XBAR_XBARFLG2_INPUT8_Pos) /*!< INPUT8 Mask      0x00000200 */
#define XBAR_XBARFLG2_INPUT8_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG2_INPUT8_Pos) & XBAR_XBARFLG2_INPUT8_Msk) /*!< INPUT8 Set Value            */
#define XBAR_XBARFLG2_INPUT8_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG2_INPUT8_Msk) >> XBAR_XBARFLG2_INPUT8_Pos) /*!< INPUT8 Get Value            */


#define XBAR_XBARFLG2_INPUT7_Pos (8U)                               /*!< INPUT7 Postion   8          */
#define XBAR_XBARFLG2_INPUT7_Msk (0x1U << XBAR_XBARFLG2_INPUT7_Pos) /*!< INPUT7 Mask      0x00000100 */
#define XBAR_XBARFLG2_INPUT7_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG2_INPUT7_Pos) & XBAR_XBARFLG2_INPUT7_Msk) /*!< INPUT7 Set Value            */
#define XBAR_XBARFLG2_INPUT7_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG2_INPUT7_Msk) >> XBAR_XBARFLG2_INPUT7_Pos) /*!< INPUT7 Get Value            */


#define XBAR_XBARFLG2_ADCSOCBO_Pos (7U)                                 /*!< ADCSOCBO Postion   7          */
#define XBAR_XBARFLG2_ADCSOCBO_Msk (0x1U << XBAR_XBARFLG2_ADCSOCBO_Pos) /*!< ADCSOCBO Mask      0x00000080 */
#define XBAR_XBARFLG2_ADCSOCBO_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG2_ADCSOCBO_Pos) & XBAR_XBARFLG2_ADCSOCBO_Msk) /*!< ADCSOCBO Set Value */
#define XBAR_XBARFLG2_ADCSOCBO_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG2_ADCSOCBO_Msk) >> XBAR_XBARFLG2_ADCSOCBO_Pos) /*!< ADCSOCBO Get Value            */


#define XBAR_XBARFLG2_ADCSOCAO_Pos (6U)                                 /*!< ADCSOCAO Postion   6          */
#define XBAR_XBARFLG2_ADCSOCAO_Msk (0x1U << XBAR_XBARFLG2_ADCSOCAO_Pos) /*!< ADCSOCAO Mask      0x00000040 */
#define XBAR_XBARFLG2_ADCSOCAO_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG2_ADCSOCAO_Pos) & XBAR_XBARFLG2_ADCSOCAO_Msk) /*!< ADCSOCAO Set Value */
#define XBAR_XBARFLG2_ADCSOCAO_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG2_ADCSOCAO_Msk) >> XBAR_XBARFLG2_ADCSOCAO_Pos) /*!< ADCSOCAO Get Value            */


#define XBAR_XBARFLG2_INPUT6_Pos (5U)                               /*!< INPUT6 Postion   5          */
#define XBAR_XBARFLG2_INPUT6_Msk (0x1U << XBAR_XBARFLG2_INPUT6_Pos) /*!< INPUT6 Mask      0x00000020 */
#define XBAR_XBARFLG2_INPUT6_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG2_INPUT6_Pos) & XBAR_XBARFLG2_INPUT6_Msk) /*!< INPUT6 Set Value            */
#define XBAR_XBARFLG2_INPUT6_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG2_INPUT6_Msk) >> XBAR_XBARFLG2_INPUT6_Pos) /*!< INPUT6 Get Value            */


#define XBAR_XBARFLG2_INPUT5_Pos (4U)                               /*!< INPUT5 Postion   4          */
#define XBAR_XBARFLG2_INPUT5_Msk (0x1U << XBAR_XBARFLG2_INPUT5_Pos) /*!< INPUT5 Mask      0x00000010 */
#define XBAR_XBARFLG2_INPUT5_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG2_INPUT5_Pos) & XBAR_XBARFLG2_INPUT5_Msk) /*!< INPUT5 Set Value            */
#define XBAR_XBARFLG2_INPUT5_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG2_INPUT5_Msk) >> XBAR_XBARFLG2_INPUT5_Pos) /*!< INPUT5 Get Value            */


#define XBAR_XBARFLG2_INPUT4_Pos (3U)                               /*!< INPUT4 Postion   3          */
#define XBAR_XBARFLG2_INPUT4_Msk (0x1U << XBAR_XBARFLG2_INPUT4_Pos) /*!< INPUT4 Mask      0x00000008 */
#define XBAR_XBARFLG2_INPUT4_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG2_INPUT4_Pos) & XBAR_XBARFLG2_INPUT4_Msk) /*!< INPUT4 Set Value            */
#define XBAR_XBARFLG2_INPUT4_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG2_INPUT4_Msk) >> XBAR_XBARFLG2_INPUT4_Pos) /*!< INPUT4 Get Value            */


#define XBAR_XBARFLG2_INPUT3_Pos (2U)                               /*!< INPUT3 Postion   2          */
#define XBAR_XBARFLG2_INPUT3_Msk (0x1U << XBAR_XBARFLG2_INPUT3_Pos) /*!< INPUT3 Mask      0x00000004 */
#define XBAR_XBARFLG2_INPUT3_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG2_INPUT3_Pos) & XBAR_XBARFLG2_INPUT3_Msk) /*!< INPUT3 Set Value            */
#define XBAR_XBARFLG2_INPUT3_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG2_INPUT3_Msk) >> XBAR_XBARFLG2_INPUT3_Pos) /*!< INPUT3 Get Value            */


#define XBAR_XBARFLG2_INPUT2_Pos (1U)                               /*!< INPUT2 Postion   1          */
#define XBAR_XBARFLG2_INPUT2_Msk (0x1U << XBAR_XBARFLG2_INPUT2_Pos) /*!< INPUT2 Mask      0x00000002 */
#define XBAR_XBARFLG2_INPUT2_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG2_INPUT2_Pos) & XBAR_XBARFLG2_INPUT2_Msk) /*!< INPUT2 Set Value            */
#define XBAR_XBARFLG2_INPUT2_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG2_INPUT2_Msk) >> XBAR_XBARFLG2_INPUT2_Pos) /*!< INPUT2 Get Value            */


#define XBAR_XBARFLG2_INPUT1_Pos (0U)                               /*!< INPUT1 Postion   0          */
#define XBAR_XBARFLG2_INPUT1_Msk (0x1U << XBAR_XBARFLG2_INPUT1_Pos) /*!< INPUT1 Mask      0x00000001 */
#define XBAR_XBARFLG2_INPUT1_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG2_INPUT1_Pos) & XBAR_XBARFLG2_INPUT1_Msk) /*!< INPUT1 Set Value            */
#define XBAR_XBARFLG2_INPUT1_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG2_INPUT1_Msk) >> XBAR_XBARFLG2_INPUT1_Pos) /*!< INPUT1 Get Value            */


/* XBARFLG3 bitfield */
#define XBAR_XBARFLG3_SD1FLT4_DRINT_Pos (31U) /*!< SD1FLT4_DRINT Postion   31         */
#define XBAR_XBARFLG3_SD1FLT4_DRINT_Msk \
    (0x1U << XBAR_XBARFLG3_SD1FLT4_DRINT_Pos) /*!< SD1FLT4_DRINT Mask      0x80000000 */
#define XBAR_XBARFLG3_SD1FLT4_DRINT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG3_SD1FLT4_DRINT_Pos) & \
     XBAR_XBARFLG3_SD1FLT4_DRINT_Msk) /*!< SD1FLT4_DRINT Set Value            */
#define XBAR_XBARFLG3_SD1FLT4_DRINT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG3_SD1FLT4_DRINT_Msk) >> \
     XBAR_XBARFLG3_SD1FLT4_DRINT_Pos) /*!< SD1FLT4_DRINT Get Value            */


#define XBAR_XBARFLG3_SD1FLT4_COMPZ_Pos (30U) /*!< SD1FLT4_COMPZ Postion   30         */
#define XBAR_XBARFLG3_SD1FLT4_COMPZ_Msk \
    (0x1U << XBAR_XBARFLG3_SD1FLT4_COMPZ_Pos) /*!< SD1FLT4_COMPZ Mask      0x40000000 */
#define XBAR_XBARFLG3_SD1FLT4_COMPZ_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG3_SD1FLT4_COMPZ_Pos) & \
     XBAR_XBARFLG3_SD1FLT4_COMPZ_Msk) /*!< SD1FLT4_COMPZ Set Value            */
#define XBAR_XBARFLG3_SD1FLT4_COMPZ_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG3_SD1FLT4_COMPZ_Msk) >> \
     XBAR_XBARFLG3_SD1FLT4_COMPZ_Pos) /*!< SD1FLT4_COMPZ Get Value            */


#define XBAR_XBARFLG3_SD1FLT3_DRINT_Pos (29U) /*!< SD1FLT3_DRINT Postion   29         */
#define XBAR_XBARFLG3_SD1FLT3_DRINT_Msk \
    (0x1U << XBAR_XBARFLG3_SD1FLT3_DRINT_Pos) /*!< SD1FLT3_DRINT Mask      0x20000000 */
#define XBAR_XBARFLG3_SD1FLT3_DRINT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG3_SD1FLT3_DRINT_Pos) & \
     XBAR_XBARFLG3_SD1FLT3_DRINT_Msk) /*!< SD1FLT3_DRINT Set Value            */
#define XBAR_XBARFLG3_SD1FLT3_DRINT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG3_SD1FLT3_DRINT_Msk) >> \
     XBAR_XBARFLG3_SD1FLT3_DRINT_Pos) /*!< SD1FLT3_DRINT Get Value            */


#define XBAR_XBARFLG3_SD1FLT3_COMPZ_Pos (28U) /*!< SD1FLT3_COMPZ Postion   28         */
#define XBAR_XBARFLG3_SD1FLT3_COMPZ_Msk \
    (0x1U << XBAR_XBARFLG3_SD1FLT3_COMPZ_Pos) /*!< SD1FLT3_COMPZ Mask      0x10000000 */
#define XBAR_XBARFLG3_SD1FLT3_COMPZ_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG3_SD1FLT3_COMPZ_Pos) & \
     XBAR_XBARFLG3_SD1FLT3_COMPZ_Msk) /*!< SD1FLT3_COMPZ Set Value            */
#define XBAR_XBARFLG3_SD1FLT3_COMPZ_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG3_SD1FLT3_COMPZ_Msk) >> \
     XBAR_XBARFLG3_SD1FLT3_COMPZ_Pos) /*!< SD1FLT3_COMPZ Get Value            */


#define XBAR_XBARFLG3_SD1FLT2_DRINT_Pos (27U) /*!< SD1FLT2_DRINT Postion   27         */
#define XBAR_XBARFLG3_SD1FLT2_DRINT_Msk \
    (0x1U << XBAR_XBARFLG3_SD1FLT2_DRINT_Pos) /*!< SD1FLT2_DRINT Mask      0x08000000 */
#define XBAR_XBARFLG3_SD1FLT2_DRINT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG3_SD1FLT2_DRINT_Pos) & \
     XBAR_XBARFLG3_SD1FLT2_DRINT_Msk) /*!< SD1FLT2_DRINT Set Value            */
#define XBAR_XBARFLG3_SD1FLT2_DRINT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG3_SD1FLT2_DRINT_Msk) >> \
     XBAR_XBARFLG3_SD1FLT2_DRINT_Pos) /*!< SD1FLT2_DRINT Get Value            */


#define XBAR_XBARFLG3_SD1FLT2_COMPZ_Pos (26U) /*!< SD1FLT2_COMPZ Postion   26         */
#define XBAR_XBARFLG3_SD1FLT2_COMPZ_Msk \
    (0x1U << XBAR_XBARFLG3_SD1FLT2_COMPZ_Pos) /*!< SD1FLT2_COMPZ Mask      0x04000000 */
#define XBAR_XBARFLG3_SD1FLT2_COMPZ_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG3_SD1FLT2_COMPZ_Pos) & \
     XBAR_XBARFLG3_SD1FLT2_COMPZ_Msk) /*!< SD1FLT2_COMPZ Set Value            */
#define XBAR_XBARFLG3_SD1FLT2_COMPZ_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG3_SD1FLT2_COMPZ_Msk) >> \
     XBAR_XBARFLG3_SD1FLT2_COMPZ_Pos) /*!< SD1FLT2_COMPZ Get Value            */


#define XBAR_XBARFLG3_SD1FLT1_DRINT_Pos (25U) /*!< SD1FLT1_DRINT Postion   25         */
#define XBAR_XBARFLG3_SD1FLT1_DRINT_Msk \
    (0x1U << XBAR_XBARFLG3_SD1FLT1_DRINT_Pos) /*!< SD1FLT1_DRINT Mask      0x02000000 */
#define XBAR_XBARFLG3_SD1FLT1_DRINT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG3_SD1FLT1_DRINT_Pos) & \
     XBAR_XBARFLG3_SD1FLT1_DRINT_Msk) /*!< SD1FLT1_DRINT Set Value            */
#define XBAR_XBARFLG3_SD1FLT1_DRINT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG3_SD1FLT1_DRINT_Msk) >> \
     XBAR_XBARFLG3_SD1FLT1_DRINT_Pos) /*!< SD1FLT1_DRINT Get Value            */


#define XBAR_XBARFLG3_SD1FLT1_COMPZ_Pos (24U) /*!< SD1FLT1_COMPZ Postion   24         */
#define XBAR_XBARFLG3_SD1FLT1_COMPZ_Msk \
    (0x1U << XBAR_XBARFLG3_SD1FLT1_COMPZ_Pos) /*!< SD1FLT1_COMPZ Mask      0x01000000 */
#define XBAR_XBARFLG3_SD1FLT1_COMPZ_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG3_SD1FLT1_COMPZ_Pos) & \
     XBAR_XBARFLG3_SD1FLT1_COMPZ_Msk) /*!< SD1FLT1_COMPZ Set Value            */
#define XBAR_XBARFLG3_SD1FLT1_COMPZ_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG3_SD1FLT1_COMPZ_Msk) >> \
     XBAR_XBARFLG3_SD1FLT1_COMPZ_Pos) /*!< SD1FLT1_COMPZ Get Value            */


#define XBAR_XBARFLG3_ECAP7_OUT_Pos (23U)                                 /*!< ECAP7_OUT Postion   23         */
#define XBAR_XBARFLG3_ECAP7_OUT_Msk (0x1U << XBAR_XBARFLG3_ECAP7_OUT_Pos) /*!< ECAP7_OUT Mask      0x00800000 */
#define XBAR_XBARFLG3_ECAP7_OUT_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG3_ECAP7_OUT_Pos) & XBAR_XBARFLG3_ECAP7_OUT_Msk) /*!< ECAP7_OUT Set Value */
#define XBAR_XBARFLG3_ECAP7_OUT_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG3_ECAP7_OUT_Msk) >> XBAR_XBARFLG3_ECAP7_OUT_Pos) /*!< ECAP7_OUT Get Value */


#define XBAR_XBARFLG3_SD2FLT4_COMPH_Pos (22U) /*!< SD2FLT4_COMPH Postion   22         */
#define XBAR_XBARFLG3_SD2FLT4_COMPH_Msk \
    (0x1U << XBAR_XBARFLG3_SD2FLT4_COMPH_Pos) /*!< SD2FLT4_COMPH Mask      0x00400000 */
#define XBAR_XBARFLG3_SD2FLT4_COMPH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG3_SD2FLT4_COMPH_Pos) & \
     XBAR_XBARFLG3_SD2FLT4_COMPH_Msk) /*!< SD2FLT4_COMPH Set Value            */
#define XBAR_XBARFLG3_SD2FLT4_COMPH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG3_SD2FLT4_COMPH_Msk) >> \
     XBAR_XBARFLG3_SD2FLT4_COMPH_Pos) /*!< SD2FLT4_COMPH Get Value            */


#define XBAR_XBARFLG3_SD2FLT4_COMPL_Pos (21U) /*!< SD2FLT4_COMPL Postion   21         */
#define XBAR_XBARFLG3_SD2FLT4_COMPL_Msk \
    (0x1U << XBAR_XBARFLG3_SD2FLT4_COMPL_Pos) /*!< SD2FLT4_COMPL Mask      0x00200000 */
#define XBAR_XBARFLG3_SD2FLT4_COMPL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG3_SD2FLT4_COMPL_Pos) & \
     XBAR_XBARFLG3_SD2FLT4_COMPL_Msk) /*!< SD2FLT4_COMPL Set Value            */
#define XBAR_XBARFLG3_SD2FLT4_COMPL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG3_SD2FLT4_COMPL_Msk) >> \
     XBAR_XBARFLG3_SD2FLT4_COMPL_Pos) /*!< SD2FLT4_COMPL Get Value            */


#define XBAR_XBARFLG3_SD2FLT3_COMPH_Pos (20U) /*!< SD2FLT3_COMPH Postion   20         */
#define XBAR_XBARFLG3_SD2FLT3_COMPH_Msk \
    (0x1U << XBAR_XBARFLG3_SD2FLT3_COMPH_Pos) /*!< SD2FLT3_COMPH Mask      0x00100000 */
#define XBAR_XBARFLG3_SD2FLT3_COMPH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG3_SD2FLT3_COMPH_Pos) & \
     XBAR_XBARFLG3_SD2FLT3_COMPH_Msk) /*!< SD2FLT3_COMPH Set Value            */
#define XBAR_XBARFLG3_SD2FLT3_COMPH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG3_SD2FLT3_COMPH_Msk) >> \
     XBAR_XBARFLG3_SD2FLT3_COMPH_Pos) /*!< SD2FLT3_COMPH Get Value            */


#define XBAR_XBARFLG3_SD2FLT3_COMPL_Pos (19U) /*!< SD2FLT3_COMPL Postion   19         */
#define XBAR_XBARFLG3_SD2FLT3_COMPL_Msk \
    (0x1U << XBAR_XBARFLG3_SD2FLT3_COMPL_Pos) /*!< SD2FLT3_COMPL Mask      0x00080000 */
#define XBAR_XBARFLG3_SD2FLT3_COMPL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG3_SD2FLT3_COMPL_Pos) & \
     XBAR_XBARFLG3_SD2FLT3_COMPL_Msk) /*!< SD2FLT3_COMPL Set Value            */
#define XBAR_XBARFLG3_SD2FLT3_COMPL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG3_SD2FLT3_COMPL_Msk) >> \
     XBAR_XBARFLG3_SD2FLT3_COMPL_Pos) /*!< SD2FLT3_COMPL Get Value            */


#define XBAR_XBARFLG3_SD2FLT2_COMPH_Pos (18U) /*!< SD2FLT2_COMPH Postion   18         */
#define XBAR_XBARFLG3_SD2FLT2_COMPH_Msk \
    (0x1U << XBAR_XBARFLG3_SD2FLT2_COMPH_Pos) /*!< SD2FLT2_COMPH Mask      0x00040000 */
#define XBAR_XBARFLG3_SD2FLT2_COMPH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG3_SD2FLT2_COMPH_Pos) & \
     XBAR_XBARFLG3_SD2FLT2_COMPH_Msk) /*!< SD2FLT2_COMPH Set Value            */
#define XBAR_XBARFLG3_SD2FLT2_COMPH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG3_SD2FLT2_COMPH_Msk) >> \
     XBAR_XBARFLG3_SD2FLT2_COMPH_Pos) /*!< SD2FLT2_COMPH Get Value            */


#define XBAR_XBARFLG3_SD2FLT2_COMPL_Pos (17U) /*!< SD2FLT2_COMPL Postion   17         */
#define XBAR_XBARFLG3_SD2FLT2_COMPL_Msk \
    (0x1U << XBAR_XBARFLG3_SD2FLT2_COMPL_Pos) /*!< SD2FLT2_COMPL Mask      0x00020000 */
#define XBAR_XBARFLG3_SD2FLT2_COMPL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG3_SD2FLT2_COMPL_Pos) & \
     XBAR_XBARFLG3_SD2FLT2_COMPL_Msk) /*!< SD2FLT2_COMPL Set Value            */
#define XBAR_XBARFLG3_SD2FLT2_COMPL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG3_SD2FLT2_COMPL_Msk) >> \
     XBAR_XBARFLG3_SD2FLT2_COMPL_Pos) /*!< SD2FLT2_COMPL Get Value            */


#define XBAR_XBARFLG3_SD2FLT1_COMPH_Pos (16U) /*!< SD2FLT1_COMPH Postion   16         */
#define XBAR_XBARFLG3_SD2FLT1_COMPH_Msk \
    (0x1U << XBAR_XBARFLG3_SD2FLT1_COMPH_Pos) /*!< SD2FLT1_COMPH Mask      0x00010000 */
#define XBAR_XBARFLG3_SD2FLT1_COMPH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG3_SD2FLT1_COMPH_Pos) & \
     XBAR_XBARFLG3_SD2FLT1_COMPH_Msk) /*!< SD2FLT1_COMPH Set Value            */
#define XBAR_XBARFLG3_SD2FLT1_COMPH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG3_SD2FLT1_COMPH_Msk) >> \
     XBAR_XBARFLG3_SD2FLT1_COMPH_Pos) /*!< SD2FLT1_COMPH Get Value            */


#define XBAR_XBARFLG3_SD2FLT1_COMPL_Pos (15U) /*!< SD2FLT1_COMPL Postion   15         */
#define XBAR_XBARFLG3_SD2FLT1_COMPL_Msk \
    (0x1U << XBAR_XBARFLG3_SD2FLT1_COMPL_Pos) /*!< SD2FLT1_COMPL Mask      0x00008000 */
#define XBAR_XBARFLG3_SD2FLT1_COMPL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG3_SD2FLT1_COMPL_Pos) & \
     XBAR_XBARFLG3_SD2FLT1_COMPL_Msk) /*!< SD2FLT1_COMPL Set Value            */
#define XBAR_XBARFLG3_SD2FLT1_COMPL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG3_SD2FLT1_COMPL_Msk) >> \
     XBAR_XBARFLG3_SD2FLT1_COMPL_Pos) /*!< SD2FLT1_COMPL Get Value            */


#define XBAR_XBARFLG3_SD1FLT4_COMPH_Pos (14U) /*!< SD1FLT4_COMPH Postion   14         */
#define XBAR_XBARFLG3_SD1FLT4_COMPH_Msk \
    (0x1U << XBAR_XBARFLG3_SD1FLT4_COMPH_Pos) /*!< SD1FLT4_COMPH Mask      0x00004000 */
#define XBAR_XBARFLG3_SD1FLT4_COMPH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG3_SD1FLT4_COMPH_Pos) & \
     XBAR_XBARFLG3_SD1FLT4_COMPH_Msk) /*!< SD1FLT4_COMPH Set Value            */
#define XBAR_XBARFLG3_SD1FLT4_COMPH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG3_SD1FLT4_COMPH_Msk) >> \
     XBAR_XBARFLG3_SD1FLT4_COMPH_Pos) /*!< SD1FLT4_COMPH Get Value            */


#define XBAR_XBARFLG3_SD1FLT4_COMPL_Pos (13U) /*!< SD1FLT4_COMPL Postion   13         */
#define XBAR_XBARFLG3_SD1FLT4_COMPL_Msk \
    (0x1U << XBAR_XBARFLG3_SD1FLT4_COMPL_Pos) /*!< SD1FLT4_COMPL Mask      0x00002000 */
#define XBAR_XBARFLG3_SD1FLT4_COMPL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG3_SD1FLT4_COMPL_Pos) & \
     XBAR_XBARFLG3_SD1FLT4_COMPL_Msk) /*!< SD1FLT4_COMPL Set Value            */
#define XBAR_XBARFLG3_SD1FLT4_COMPL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG3_SD1FLT4_COMPL_Msk) >> \
     XBAR_XBARFLG3_SD1FLT4_COMPL_Pos) /*!< SD1FLT4_COMPL Get Value            */


#define XBAR_XBARFLG3_SD1FLT3_COMPH_Pos (12U) /*!< SD1FLT3_COMPH Postion   12         */
#define XBAR_XBARFLG3_SD1FLT3_COMPH_Msk \
    (0x1U << XBAR_XBARFLG3_SD1FLT3_COMPH_Pos) /*!< SD1FLT3_COMPH Mask      0x00001000 */
#define XBAR_XBARFLG3_SD1FLT3_COMPH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG3_SD1FLT3_COMPH_Pos) & \
     XBAR_XBARFLG3_SD1FLT3_COMPH_Msk) /*!< SD1FLT3_COMPH Set Value            */
#define XBAR_XBARFLG3_SD1FLT3_COMPH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG3_SD1FLT3_COMPH_Msk) >> \
     XBAR_XBARFLG3_SD1FLT3_COMPH_Pos) /*!< SD1FLT3_COMPH Get Value            */


#define XBAR_XBARFLG3_SD1FLT3_COMPL_Pos (11U) /*!< SD1FLT3_COMPL Postion   11         */
#define XBAR_XBARFLG3_SD1FLT3_COMPL_Msk \
    (0x1U << XBAR_XBARFLG3_SD1FLT3_COMPL_Pos) /*!< SD1FLT3_COMPL Mask      0x00000800 */
#define XBAR_XBARFLG3_SD1FLT3_COMPL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG3_SD1FLT3_COMPL_Pos) & \
     XBAR_XBARFLG3_SD1FLT3_COMPL_Msk) /*!< SD1FLT3_COMPL Set Value            */
#define XBAR_XBARFLG3_SD1FLT3_COMPL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG3_SD1FLT3_COMPL_Msk) >> \
     XBAR_XBARFLG3_SD1FLT3_COMPL_Pos) /*!< SD1FLT3_COMPL Get Value            */


#define XBAR_XBARFLG3_SD1FLT2_COMPH_Pos (10U) /*!< SD1FLT2_COMPH Postion   10         */
#define XBAR_XBARFLG3_SD1FLT2_COMPH_Msk \
    (0x1U << XBAR_XBARFLG3_SD1FLT2_COMPH_Pos) /*!< SD1FLT2_COMPH Mask      0x00000400 */
#define XBAR_XBARFLG3_SD1FLT2_COMPH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG3_SD1FLT2_COMPH_Pos) & \
     XBAR_XBARFLG3_SD1FLT2_COMPH_Msk) /*!< SD1FLT2_COMPH Set Value            */
#define XBAR_XBARFLG3_SD1FLT2_COMPH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG3_SD1FLT2_COMPH_Msk) >> \
     XBAR_XBARFLG3_SD1FLT2_COMPH_Pos) /*!< SD1FLT2_COMPH Get Value            */


#define XBAR_XBARFLG3_SD1FLT2_COMPL_Pos (9U) /*!< SD1FLT2_COMPL Postion   9          */
#define XBAR_XBARFLG3_SD1FLT2_COMPL_Msk \
    (0x1U << XBAR_XBARFLG3_SD1FLT2_COMPL_Pos) /*!< SD1FLT2_COMPL Mask      0x00000200 */
#define XBAR_XBARFLG3_SD1FLT2_COMPL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG3_SD1FLT2_COMPL_Pos) & \
     XBAR_XBARFLG3_SD1FLT2_COMPL_Msk) /*!< SD1FLT2_COMPL Set Value            */
#define XBAR_XBARFLG3_SD1FLT2_COMPL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG3_SD1FLT2_COMPL_Msk) >> \
     XBAR_XBARFLG3_SD1FLT2_COMPL_Pos) /*!< SD1FLT2_COMPL Get Value            */


#define XBAR_XBARFLG3_SD1FLT1_COMPH_Pos (8U) /*!< SD1FLT1_COMPH Postion   8          */
#define XBAR_XBARFLG3_SD1FLT1_COMPH_Msk \
    (0x1U << XBAR_XBARFLG3_SD1FLT1_COMPH_Pos) /*!< SD1FLT1_COMPH Mask      0x00000100 */
#define XBAR_XBARFLG3_SD1FLT1_COMPH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG3_SD1FLT1_COMPH_Pos) & \
     XBAR_XBARFLG3_SD1FLT1_COMPH_Msk) /*!< SD1FLT1_COMPH Set Value            */
#define XBAR_XBARFLG3_SD1FLT1_COMPH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG3_SD1FLT1_COMPH_Msk) >> \
     XBAR_XBARFLG3_SD1FLT1_COMPH_Pos) /*!< SD1FLT1_COMPH Get Value            */


#define XBAR_XBARFLG3_SD1FLT1_COMPL_Pos (7U) /*!< SD1FLT1_COMPL Postion   7          */
#define XBAR_XBARFLG3_SD1FLT1_COMPL_Msk \
    (0x1U << XBAR_XBARFLG3_SD1FLT1_COMPL_Pos) /*!< SD1FLT1_COMPL Mask      0x00000080 */
#define XBAR_XBARFLG3_SD1FLT1_COMPL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG3_SD1FLT1_COMPL_Pos) & \
     XBAR_XBARFLG3_SD1FLT1_COMPL_Msk) /*!< SD1FLT1_COMPL Set Value            */
#define XBAR_XBARFLG3_SD1FLT1_COMPL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG3_SD1FLT1_COMPL_Msk) >> \
     XBAR_XBARFLG3_SD1FLT1_COMPL_Pos) /*!< SD1FLT1_COMPL Get Value            */


#define XBAR_XBARFLG3_ADCDEVT4_Pos (6U)                                 /*!< ADCDEVT4 Postion   6          */
#define XBAR_XBARFLG3_ADCDEVT4_Msk (0x1U << XBAR_XBARFLG3_ADCDEVT4_Pos) /*!< ADCDEVT4 Mask      0x00000040 */
#define XBAR_XBARFLG3_ADCDEVT4_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG3_ADCDEVT4_Pos) & XBAR_XBARFLG3_ADCDEVT4_Msk) /*!< ADCDEVT4 Set Value */
#define XBAR_XBARFLG3_ADCDEVT4_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG3_ADCDEVT4_Msk) >> XBAR_XBARFLG3_ADCDEVT4_Pos) /*!< ADCDEVT4 Get Value            */


#define XBAR_XBARFLG3_ADCDEVT3_Pos (5U)                                 /*!< ADCDEVT3 Postion   5          */
#define XBAR_XBARFLG3_ADCDEVT3_Msk (0x1U << XBAR_XBARFLG3_ADCDEVT3_Pos) /*!< ADCDEVT3 Mask      0x00000020 */
#define XBAR_XBARFLG3_ADCDEVT3_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG3_ADCDEVT3_Pos) & XBAR_XBARFLG3_ADCDEVT3_Msk) /*!< ADCDEVT3 Set Value */
#define XBAR_XBARFLG3_ADCDEVT3_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG3_ADCDEVT3_Msk) >> XBAR_XBARFLG3_ADCDEVT3_Pos) /*!< ADCDEVT3 Get Value            */


#define XBAR_XBARFLG3_ADCDEVT2_Pos (4U)                                 /*!< ADCDEVT2 Postion   4          */
#define XBAR_XBARFLG3_ADCDEVT2_Msk (0x1U << XBAR_XBARFLG3_ADCDEVT2_Pos) /*!< ADCDEVT2 Mask      0x00000010 */
#define XBAR_XBARFLG3_ADCDEVT2_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG3_ADCDEVT2_Pos) & XBAR_XBARFLG3_ADCDEVT2_Msk) /*!< ADCDEVT2 Set Value */
#define XBAR_XBARFLG3_ADCDEVT2_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG3_ADCDEVT2_Msk) >> XBAR_XBARFLG3_ADCDEVT2_Pos) /*!< ADCDEVT2 Get Value            */


#define XBAR_XBARFLG3_ADCDEVT1_Pos (3U)                                 /*!< ADCDEVT1 Postion   3          */
#define XBAR_XBARFLG3_ADCDEVT1_Msk (0x1U << XBAR_XBARFLG3_ADCDEVT1_Pos) /*!< ADCDEVT1 Mask      0x00000008 */
#define XBAR_XBARFLG3_ADCDEVT1_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG3_ADCDEVT1_Pos) & XBAR_XBARFLG3_ADCDEVT1_Msk) /*!< ADCDEVT1 Set Value */
#define XBAR_XBARFLG3_ADCDEVT1_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG3_ADCDEVT1_Msk) >> XBAR_XBARFLG3_ADCDEVT1_Pos) /*!< ADCDEVT1 Get Value            */


#define XBAR_XBARFLG3_ADCCEVT4_Pos (2U)                                 /*!< ADCCEVT4 Postion   2          */
#define XBAR_XBARFLG3_ADCCEVT4_Msk (0x1U << XBAR_XBARFLG3_ADCCEVT4_Pos) /*!< ADCCEVT4 Mask      0x00000004 */
#define XBAR_XBARFLG3_ADCCEVT4_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG3_ADCCEVT4_Pos) & XBAR_XBARFLG3_ADCCEVT4_Msk) /*!< ADCCEVT4 Set Value */
#define XBAR_XBARFLG3_ADCCEVT4_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG3_ADCCEVT4_Msk) >> XBAR_XBARFLG3_ADCCEVT4_Pos) /*!< ADCCEVT4 Get Value            */


#define XBAR_XBARFLG3_ADCCEVT3_Pos (1U)                                 /*!< ADCCEVT3 Postion   1          */
#define XBAR_XBARFLG3_ADCCEVT3_Msk (0x1U << XBAR_XBARFLG3_ADCCEVT3_Pos) /*!< ADCCEVT3 Mask      0x00000002 */
#define XBAR_XBARFLG3_ADCCEVT3_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG3_ADCCEVT3_Pos) & XBAR_XBARFLG3_ADCCEVT3_Msk) /*!< ADCCEVT3 Set Value */
#define XBAR_XBARFLG3_ADCCEVT3_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG3_ADCCEVT3_Msk) >> XBAR_XBARFLG3_ADCCEVT3_Pos) /*!< ADCCEVT3 Get Value            */


#define XBAR_XBARFLG3_ADCCEVT2_Pos (0U)                                 /*!< ADCCEVT2 Postion   0          */
#define XBAR_XBARFLG3_ADCCEVT2_Msk (0x1U << XBAR_XBARFLG3_ADCCEVT2_Pos) /*!< ADCCEVT2 Mask      0x00000001 */
#define XBAR_XBARFLG3_ADCCEVT2_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG3_ADCCEVT2_Pos) & XBAR_XBARFLG3_ADCCEVT2_Msk) /*!< ADCCEVT2 Set Value */
#define XBAR_XBARFLG3_ADCCEVT2_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG3_ADCCEVT2_Msk) >> XBAR_XBARFLG3_ADCCEVT2_Pos) /*!< ADCCEVT2 Get Value            */


/* XBARFLG4 bitfield */
#define XBAR_XBARFLG4_CLAHALT_Pos (31U)                               /*!< CLAHALT Postion   31         */
#define XBAR_XBARFLG4_CLAHALT_Msk (0x1U << XBAR_XBARFLG4_CLAHALT_Pos) /*!< CLAHALT Mask      0x80000000 */
#define XBAR_XBARFLG4_CLAHALT_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG4_CLAHALT_Pos) & XBAR_XBARFLG4_CLAHALT_Msk) /*!< CLAHALT Set Value            */
#define XBAR_XBARFLG4_CLAHALT_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG4_CLAHALT_Msk) >> XBAR_XBARFLG4_CLAHALT_Pos) /*!< CLAHALT Get Value            */


#define XBAR_XBARFLG4_ECATSYNC1_Pos (30U)                                 /*!< ECATSYNC1 Postion   30         */
#define XBAR_XBARFLG4_ECATSYNC1_Msk (0x1U << XBAR_XBARFLG4_ECATSYNC1_Pos) /*!< ECATSYNC1 Mask      0x40000000 */
#define XBAR_XBARFLG4_ECATSYNC1_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG4_ECATSYNC1_Pos) & XBAR_XBARFLG4_ECATSYNC1_Msk) /*!< ECATSYNC1 Set Value */
#define XBAR_XBARFLG4_ECATSYNC1_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG4_ECATSYNC1_Msk) >> XBAR_XBARFLG4_ECATSYNC1_Pos) /*!< ECATSYNC1 Get Value */


#define XBAR_XBARFLG4_ECATSYNC0_Pos (29U)                                 /*!< ECATSYNC0 Postion   29         */
#define XBAR_XBARFLG4_ECATSYNC0_Msk (0x1U << XBAR_XBARFLG4_ECATSYNC0_Pos) /*!< ECATSYNC0 Mask      0x20000000 */
#define XBAR_XBARFLG4_ECATSYNC0_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG4_ECATSYNC0_Pos) & XBAR_XBARFLG4_ECATSYNC0_Msk) /*!< ECATSYNC0 Set Value */
#define XBAR_XBARFLG4_ECATSYNC0_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG4_ECATSYNC0_Msk) >> XBAR_XBARFLG4_ECATSYNC0_Pos) /*!< ECATSYNC0 Get Value */


#define XBAR_XBARFLG4_ERRORSTS_ERROR_Pos (28U) /*!< ERRORSTS_ERROR Postion   28         */
#define XBAR_XBARFLG4_ERRORSTS_ERROR_Msk \
    (0x1U << XBAR_XBARFLG4_ERRORSTS_ERROR_Pos) /*!< ERRORSTS_ERROR Mask      0x10000000 */
#define XBAR_XBARFLG4_ERRORSTS_ERROR_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG4_ERRORSTS_ERROR_Pos) & \
     XBAR_XBARFLG4_ERRORSTS_ERROR_Msk) /*!< ERRORSTS_ERROR Set Value            */
#define XBAR_XBARFLG4_ERRORSTS_ERROR_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG4_ERRORSTS_ERROR_Msk) >> \
     XBAR_XBARFLG4_ERRORSTS_ERROR_Pos) /*!< ERRORSTS_ERROR Get Value            */


#define XBAR_XBARFLG4_CLB6_OUT5_Pos (27U)                                 /*!< CLB6_OUT5 Postion   27         */
#define XBAR_XBARFLG4_CLB6_OUT5_Msk (0x1U << XBAR_XBARFLG4_CLB6_OUT5_Pos) /*!< CLB6_OUT5 Mask      0x08000000 */
#define XBAR_XBARFLG4_CLB6_OUT5_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG4_CLB6_OUT5_Pos) & XBAR_XBARFLG4_CLB6_OUT5_Msk) /*!< CLB6_OUT5 Set Value */
#define XBAR_XBARFLG4_CLB6_OUT5_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG4_CLB6_OUT5_Msk) >> XBAR_XBARFLG4_CLB6_OUT5_Pos) /*!< CLB6_OUT5 Get Value */


#define XBAR_XBARFLG4_CLB6_OUT4_Pos (26U)                                 /*!< CLB6_OUT4 Postion   26         */
#define XBAR_XBARFLG4_CLB6_OUT4_Msk (0x1U << XBAR_XBARFLG4_CLB6_OUT4_Pos) /*!< CLB6_OUT4 Mask      0x04000000 */
#define XBAR_XBARFLG4_CLB6_OUT4_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG4_CLB6_OUT4_Pos) & XBAR_XBARFLG4_CLB6_OUT4_Msk) /*!< CLB6_OUT4 Set Value */
#define XBAR_XBARFLG4_CLB6_OUT4_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG4_CLB6_OUT4_Msk) >> XBAR_XBARFLG4_CLB6_OUT4_Pos) /*!< CLB6_OUT4 Get Value */


#define XBAR_XBARFLG4_CLB5_OUT5_Pos (25U)                                 /*!< CLB5_OUT5 Postion   25         */
#define XBAR_XBARFLG4_CLB5_OUT5_Msk (0x1U << XBAR_XBARFLG4_CLB5_OUT5_Pos) /*!< CLB5_OUT5 Mask      0x02000000 */
#define XBAR_XBARFLG4_CLB5_OUT5_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG4_CLB5_OUT5_Pos) & XBAR_XBARFLG4_CLB5_OUT5_Msk) /*!< CLB5_OUT5 Set Value */
#define XBAR_XBARFLG4_CLB5_OUT5_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG4_CLB5_OUT5_Msk) >> XBAR_XBARFLG4_CLB5_OUT5_Pos) /*!< CLB5_OUT5 Get Value */


#define XBAR_XBARFLG4_CLB5_OUT4_Pos (24U)                                 /*!< CLB5_OUT4 Postion   24         */
#define XBAR_XBARFLG4_CLB5_OUT4_Msk (0x1U << XBAR_XBARFLG4_CLB5_OUT4_Pos) /*!< CLB5_OUT4 Mask      0x01000000 */
#define XBAR_XBARFLG4_CLB5_OUT4_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG4_CLB5_OUT4_Pos) & XBAR_XBARFLG4_CLB5_OUT4_Msk) /*!< CLB5_OUT4 Set Value */
#define XBAR_XBARFLG4_CLB5_OUT4_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG4_CLB5_OUT4_Msk) >> XBAR_XBARFLG4_CLB5_OUT4_Pos) /*!< CLB5_OUT4 Get Value */


#define XBAR_XBARFLG4_CLB4_OUT5_Pos (23U)                                 /*!< CLB4_OUT5 Postion   23         */
#define XBAR_XBARFLG4_CLB4_OUT5_Msk (0x1U << XBAR_XBARFLG4_CLB4_OUT5_Pos) /*!< CLB4_OUT5 Mask      0x00800000 */
#define XBAR_XBARFLG4_CLB4_OUT5_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG4_CLB4_OUT5_Pos) & XBAR_XBARFLG4_CLB4_OUT5_Msk) /*!< CLB4_OUT5 Set Value */
#define XBAR_XBARFLG4_CLB4_OUT5_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG4_CLB4_OUT5_Msk) >> XBAR_XBARFLG4_CLB4_OUT5_Pos) /*!< CLB4_OUT5 Get Value */


#define XBAR_XBARFLG4_CLB4_OUT4_Pos (22U)                                 /*!< CLB4_OUT4 Postion   22         */
#define XBAR_XBARFLG4_CLB4_OUT4_Msk (0x1U << XBAR_XBARFLG4_CLB4_OUT4_Pos) /*!< CLB4_OUT4 Mask      0x00400000 */
#define XBAR_XBARFLG4_CLB4_OUT4_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG4_CLB4_OUT4_Pos) & XBAR_XBARFLG4_CLB4_OUT4_Msk) /*!< CLB4_OUT4 Set Value */
#define XBAR_XBARFLG4_CLB4_OUT4_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG4_CLB4_OUT4_Msk) >> XBAR_XBARFLG4_CLB4_OUT4_Pos) /*!< CLB4_OUT4 Get Value */


#define XBAR_XBARFLG4_CLB3_OUT5_Pos (21U)                                 /*!< CLB3_OUT5 Postion   21         */
#define XBAR_XBARFLG4_CLB3_OUT5_Msk (0x1U << XBAR_XBARFLG4_CLB3_OUT5_Pos) /*!< CLB3_OUT5 Mask      0x00200000 */
#define XBAR_XBARFLG4_CLB3_OUT5_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG4_CLB3_OUT5_Pos) & XBAR_XBARFLG4_CLB3_OUT5_Msk) /*!< CLB3_OUT5 Set Value */
#define XBAR_XBARFLG4_CLB3_OUT5_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG4_CLB3_OUT5_Msk) >> XBAR_XBARFLG4_CLB3_OUT5_Pos) /*!< CLB3_OUT5 Get Value */


#define XBAR_XBARFLG4_CLB3_OUT4_Pos (20U)                                 /*!< CLB3_OUT4 Postion   20         */
#define XBAR_XBARFLG4_CLB3_OUT4_Msk (0x1U << XBAR_XBARFLG4_CLB3_OUT4_Pos) /*!< CLB3_OUT4 Mask      0x00100000 */
#define XBAR_XBARFLG4_CLB3_OUT4_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG4_CLB3_OUT4_Pos) & XBAR_XBARFLG4_CLB3_OUT4_Msk) /*!< CLB3_OUT4 Set Value */
#define XBAR_XBARFLG4_CLB3_OUT4_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG4_CLB3_OUT4_Msk) >> XBAR_XBARFLG4_CLB3_OUT4_Pos) /*!< CLB3_OUT4 Get Value */


#define XBAR_XBARFLG4_CLB2_OUT5_Pos (19U)                                 /*!< CLB2_OUT5 Postion   19         */
#define XBAR_XBARFLG4_CLB2_OUT5_Msk (0x1U << XBAR_XBARFLG4_CLB2_OUT5_Pos) /*!< CLB2_OUT5 Mask      0x00080000 */
#define XBAR_XBARFLG4_CLB2_OUT5_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG4_CLB2_OUT5_Pos) & XBAR_XBARFLG4_CLB2_OUT5_Msk) /*!< CLB2_OUT5 Set Value */
#define XBAR_XBARFLG4_CLB2_OUT5_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG4_CLB2_OUT5_Msk) >> XBAR_XBARFLG4_CLB2_OUT5_Pos) /*!< CLB2_OUT5 Get Value */


#define XBAR_XBARFLG4_CLB2_OUT4_Pos (18U)                                 /*!< CLB2_OUT4 Postion   18         */
#define XBAR_XBARFLG4_CLB2_OUT4_Msk (0x1U << XBAR_XBARFLG4_CLB2_OUT4_Pos) /*!< CLB2_OUT4 Mask      0x00040000 */
#define XBAR_XBARFLG4_CLB2_OUT4_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG4_CLB2_OUT4_Pos) & XBAR_XBARFLG4_CLB2_OUT4_Msk) /*!< CLB2_OUT4 Set Value */
#define XBAR_XBARFLG4_CLB2_OUT4_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG4_CLB2_OUT4_Msk) >> XBAR_XBARFLG4_CLB2_OUT4_Pos) /*!< CLB2_OUT4 Get Value */


#define XBAR_XBARFLG4_CLB1_OUT5_Pos (17U)                                 /*!< CLB1_OUT5 Postion   17         */
#define XBAR_XBARFLG4_CLB1_OUT5_Msk (0x1U << XBAR_XBARFLG4_CLB1_OUT5_Pos) /*!< CLB1_OUT5 Mask      0x00020000 */
#define XBAR_XBARFLG4_CLB1_OUT5_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG4_CLB1_OUT5_Pos) & XBAR_XBARFLG4_CLB1_OUT5_Msk) /*!< CLB1_OUT5 Set Value */
#define XBAR_XBARFLG4_CLB1_OUT5_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG4_CLB1_OUT5_Msk) >> XBAR_XBARFLG4_CLB1_OUT5_Pos) /*!< CLB1_OUT5 Get Value */


#define XBAR_XBARFLG4_CLB1_OUT4_Pos (16U)                                 /*!< CLB1_OUT4 Postion   16         */
#define XBAR_XBARFLG4_CLB1_OUT4_Msk (0x1U << XBAR_XBARFLG4_CLB1_OUT4_Pos) /*!< CLB1_OUT4 Mask      0x00010000 */
#define XBAR_XBARFLG4_CLB1_OUT4_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG4_CLB1_OUT4_Pos) & XBAR_XBARFLG4_CLB1_OUT4_Msk) /*!< CLB1_OUT4 Set Value */
#define XBAR_XBARFLG4_CLB1_OUT4_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG4_CLB1_OUT4_Msk) >> XBAR_XBARFLG4_CLB1_OUT4_Pos) /*!< CLB1_OUT4 Get Value */


#define XBAR_XBARFLG4_CLB8_OUT5_Pos (15U)                                 /*!< CLB8_OUT5 Postion   15         */
#define XBAR_XBARFLG4_CLB8_OUT5_Msk (0x1U << XBAR_XBARFLG4_CLB8_OUT5_Pos) /*!< CLB8_OUT5 Mask      0x00008000 */
#define XBAR_XBARFLG4_CLB8_OUT5_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG4_CLB8_OUT5_Pos) & XBAR_XBARFLG4_CLB8_OUT5_Msk) /*!< CLB8_OUT5 Set Value */
#define XBAR_XBARFLG4_CLB8_OUT5_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG4_CLB8_OUT5_Msk) >> XBAR_XBARFLG4_CLB8_OUT5_Pos) /*!< CLB8_OUT5 Get Value */


#define XBAR_XBARFLG4_CLB8_OUT4_Pos (14U)                                 /*!< CLB8_OUT4 Postion   14         */
#define XBAR_XBARFLG4_CLB8_OUT4_Msk (0x1U << XBAR_XBARFLG4_CLB8_OUT4_Pos) /*!< CLB8_OUT4 Mask      0x00004000 */
#define XBAR_XBARFLG4_CLB8_OUT4_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG4_CLB8_OUT4_Pos) & XBAR_XBARFLG4_CLB8_OUT4_Msk) /*!< CLB8_OUT4 Set Value */
#define XBAR_XBARFLG4_CLB8_OUT4_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG4_CLB8_OUT4_Msk) >> XBAR_XBARFLG4_CLB8_OUT4_Pos) /*!< CLB8_OUT4 Get Value */


#define XBAR_XBARFLG4_CLB7_OUT5_Pos (13U)                                 /*!< CLB7_OUT5 Postion   13         */
#define XBAR_XBARFLG4_CLB7_OUT5_Msk (0x1U << XBAR_XBARFLG4_CLB7_OUT5_Pos) /*!< CLB7_OUT5 Mask      0x00002000 */
#define XBAR_XBARFLG4_CLB7_OUT5_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG4_CLB7_OUT5_Pos) & XBAR_XBARFLG4_CLB7_OUT5_Msk) /*!< CLB7_OUT5 Set Value */
#define XBAR_XBARFLG4_CLB7_OUT5_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG4_CLB7_OUT5_Msk) >> XBAR_XBARFLG4_CLB7_OUT5_Pos) /*!< CLB7_OUT5 Get Value */


#define XBAR_XBARFLG4_CLB7_OUT4_Pos (12U)                                 /*!< CLB7_OUT4 Postion   12         */
#define XBAR_XBARFLG4_CLB7_OUT4_Msk (0x1U << XBAR_XBARFLG4_CLB7_OUT4_Pos) /*!< CLB7_OUT4 Mask      0x00001000 */
#define XBAR_XBARFLG4_CLB7_OUT4_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG4_CLB7_OUT4_Pos) & XBAR_XBARFLG4_CLB7_OUT4_Msk) /*!< CLB7_OUT4 Set Value */
#define XBAR_XBARFLG4_CLB7_OUT4_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG4_CLB7_OUT4_Msk) >> XBAR_XBARFLG4_CLB7_OUT4_Pos) /*!< CLB7_OUT4 Get Value */


#define XBAR_XBARFLG4_MCANA_FEVT2_Pos (11U)                                   /*!< MCANA_FEVT2 Postion   11         */
#define XBAR_XBARFLG4_MCANA_FEVT2_Msk (0x1U << XBAR_XBARFLG4_MCANA_FEVT2_Pos) /*!< MCANA_FEVT2 Mask      0x00000800 */
#define XBAR_XBARFLG4_MCANA_FEVT2_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG4_MCANA_FEVT2_Pos) & XBAR_XBARFLG4_MCANA_FEVT2_Msk) /*!< MCANA_FEVT2 Set Value */
#define XBAR_XBARFLG4_MCANA_FEVT2_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG4_MCANA_FEVT2_Msk) >> XBAR_XBARFLG4_MCANA_FEVT2_Pos) /*!< MCANA_FEVT2 Get Value */


#define XBAR_XBARFLG4_MCANA_FEVT1_Pos (10U)                                   /*!< MCANA_FEVT1 Postion   10         */
#define XBAR_XBARFLG4_MCANA_FEVT1_Msk (0x1U << XBAR_XBARFLG4_MCANA_FEVT1_Pos) /*!< MCANA_FEVT1 Mask      0x00000400 */
#define XBAR_XBARFLG4_MCANA_FEVT1_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG4_MCANA_FEVT1_Pos) & XBAR_XBARFLG4_MCANA_FEVT1_Msk) /*!< MCANA_FEVT1 Set Value */
#define XBAR_XBARFLG4_MCANA_FEVT1_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG4_MCANA_FEVT1_Msk) >> XBAR_XBARFLG4_MCANA_FEVT1_Pos) /*!< MCANA_FEVT1 Get Value */


#define XBAR_XBARFLG4_MCANA_FEVT0_Pos (9U)                                    /*!< MCANA_FEVT0 Postion   9          */
#define XBAR_XBARFLG4_MCANA_FEVT0_Msk (0x1U << XBAR_XBARFLG4_MCANA_FEVT0_Pos) /*!< MCANA_FEVT0 Mask      0x00000200 */
#define XBAR_XBARFLG4_MCANA_FEVT0_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG4_MCANA_FEVT0_Pos) & XBAR_XBARFLG4_MCANA_FEVT0_Msk) /*!< MCANA_FEVT0 Set Value */
#define XBAR_XBARFLG4_MCANA_FEVT0_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG4_MCANA_FEVT0_Msk) >> XBAR_XBARFLG4_MCANA_FEVT0_Pos) /*!< MCANA_FEVT0 Get Value */


#define XBAR_XBARFLG4_EMAC_PPS0_Pos (8U)                                  /*!< EMAC_PPS0 Postion   8          */
#define XBAR_XBARFLG4_EMAC_PPS0_Msk (0x1U << XBAR_XBARFLG4_EMAC_PPS0_Pos) /*!< EMAC_PPS0 Mask      0x00000100 */
#define XBAR_XBARFLG4_EMAC_PPS0_Set(x) \
    (((uint32_t) (x) << XBAR_XBARFLG4_EMAC_PPS0_Pos) & XBAR_XBARFLG4_EMAC_PPS0_Msk) /*!< EMAC_PPS0 Set Value */
#define XBAR_XBARFLG4_EMAC_PPS0_Get(x) \
    (((uint32_t) (x) &XBAR_XBARFLG4_EMAC_PPS0_Msk) >> XBAR_XBARFLG4_EMAC_PPS0_Pos) /*!< EMAC_PPS0 Get Value */


#define XBAR_XBARFLG4_SD2FLT4_DRINT_Pos (7U) /*!< SD2FLT4_DRINT Postion   7          */
#define XBAR_XBARFLG4_SD2FLT4_DRINT_Msk \
    (0x1U << XBAR_XBARFLG4_SD2FLT4_DRINT_Pos) /*!< SD2FLT4_DRINT Mask      0x00000080 */
#define XBAR_XBARFLG4_SD2FLT4_DRINT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG4_SD2FLT4_DRINT_Pos) & \
     XBAR_XBARFLG4_SD2FLT4_DRINT_Msk) /*!< SD2FLT4_DRINT Set Value            */
#define XBAR_XBARFLG4_SD2FLT4_DRINT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG4_SD2FLT4_DRINT_Msk) >> \
     XBAR_XBARFLG4_SD2FLT4_DRINT_Pos) /*!< SD2FLT4_DRINT Get Value            */


#define XBAR_XBARFLG4_SD2FLT4_COMPZ_Pos (6U) /*!< SD2FLT4_COMPZ Postion   6          */
#define XBAR_XBARFLG4_SD2FLT4_COMPZ_Msk \
    (0x1U << XBAR_XBARFLG4_SD2FLT4_COMPZ_Pos) /*!< SD2FLT4_COMPZ Mask      0x00000040 */
#define XBAR_XBARFLG4_SD2FLT4_COMPZ_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG4_SD2FLT4_COMPZ_Pos) & \
     XBAR_XBARFLG4_SD2FLT4_COMPZ_Msk) /*!< SD2FLT4_COMPZ Set Value            */
#define XBAR_XBARFLG4_SD2FLT4_COMPZ_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG4_SD2FLT4_COMPZ_Msk) >> \
     XBAR_XBARFLG4_SD2FLT4_COMPZ_Pos) /*!< SD2FLT4_COMPZ Get Value            */


#define XBAR_XBARFLG4_SD2FLT3_DRINT_Pos (5U) /*!< SD2FLT3_DRINT Postion   5          */
#define XBAR_XBARFLG4_SD2FLT3_DRINT_Msk \
    (0x1U << XBAR_XBARFLG4_SD2FLT3_DRINT_Pos) /*!< SD2FLT3_DRINT Mask      0x00000020 */
#define XBAR_XBARFLG4_SD2FLT3_DRINT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG4_SD2FLT3_DRINT_Pos) & \
     XBAR_XBARFLG4_SD2FLT3_DRINT_Msk) /*!< SD2FLT3_DRINT Set Value            */
#define XBAR_XBARFLG4_SD2FLT3_DRINT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG4_SD2FLT3_DRINT_Msk) >> \
     XBAR_XBARFLG4_SD2FLT3_DRINT_Pos) /*!< SD2FLT3_DRINT Get Value            */


#define XBAR_XBARFLG4_SD2FLT3_COMPZ_Pos (4U) /*!< SD2FLT3_COMPZ Postion   4          */
#define XBAR_XBARFLG4_SD2FLT3_COMPZ_Msk \
    (0x1U << XBAR_XBARFLG4_SD2FLT3_COMPZ_Pos) /*!< SD2FLT3_COMPZ Mask      0x00000010 */
#define XBAR_XBARFLG4_SD2FLT3_COMPZ_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG4_SD2FLT3_COMPZ_Pos) & \
     XBAR_XBARFLG4_SD2FLT3_COMPZ_Msk) /*!< SD2FLT3_COMPZ Set Value            */
#define XBAR_XBARFLG4_SD2FLT3_COMPZ_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG4_SD2FLT3_COMPZ_Msk) >> \
     XBAR_XBARFLG4_SD2FLT3_COMPZ_Pos) /*!< SD2FLT3_COMPZ Get Value            */


#define XBAR_XBARFLG4_SD2FLT2_DRINT_Pos (3U) /*!< SD2FLT2_DRINT Postion   3          */
#define XBAR_XBARFLG4_SD2FLT2_DRINT_Msk \
    (0x1U << XBAR_XBARFLG4_SD2FLT2_DRINT_Pos) /*!< SD2FLT2_DRINT Mask      0x00000008 */
#define XBAR_XBARFLG4_SD2FLT2_DRINT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG4_SD2FLT2_DRINT_Pos) & \
     XBAR_XBARFLG4_SD2FLT2_DRINT_Msk) /*!< SD2FLT2_DRINT Set Value            */
#define XBAR_XBARFLG4_SD2FLT2_DRINT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG4_SD2FLT2_DRINT_Msk) >> \
     XBAR_XBARFLG4_SD2FLT2_DRINT_Pos) /*!< SD2FLT2_DRINT Get Value            */


#define XBAR_XBARFLG4_SD2FLT2_COMPZ_Pos (2U) /*!< SD2FLT2_COMPZ Postion   2          */
#define XBAR_XBARFLG4_SD2FLT2_COMPZ_Msk \
    (0x1U << XBAR_XBARFLG4_SD2FLT2_COMPZ_Pos) /*!< SD2FLT2_COMPZ Mask      0x00000004 */
#define XBAR_XBARFLG4_SD2FLT2_COMPZ_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG4_SD2FLT2_COMPZ_Pos) & \
     XBAR_XBARFLG4_SD2FLT2_COMPZ_Msk) /*!< SD2FLT2_COMPZ Set Value            */
#define XBAR_XBARFLG4_SD2FLT2_COMPZ_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG4_SD2FLT2_COMPZ_Msk) >> \
     XBAR_XBARFLG4_SD2FLT2_COMPZ_Pos) /*!< SD2FLT2_COMPZ Get Value            */


#define XBAR_XBARFLG4_SD2FLT1_DRINT_Pos (1U) /*!< SD2FLT1_DRINT Postion   1          */
#define XBAR_XBARFLG4_SD2FLT1_DRINT_Msk \
    (0x1U << XBAR_XBARFLG4_SD2FLT1_DRINT_Pos) /*!< SD2FLT1_DRINT Mask      0x00000002 */
#define XBAR_XBARFLG4_SD2FLT1_DRINT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG4_SD2FLT1_DRINT_Pos) & \
     XBAR_XBARFLG4_SD2FLT1_DRINT_Msk) /*!< SD2FLT1_DRINT Set Value            */
#define XBAR_XBARFLG4_SD2FLT1_DRINT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG4_SD2FLT1_DRINT_Msk) >> \
     XBAR_XBARFLG4_SD2FLT1_DRINT_Pos) /*!< SD2FLT1_DRINT Get Value            */


#define XBAR_XBARFLG4_SD2FLT1_COMPZ_Pos (0U) /*!< SD2FLT1_COMPZ Postion   0          */
#define XBAR_XBARFLG4_SD2FLT1_COMPZ_Msk \
    (0x1U << XBAR_XBARFLG4_SD2FLT1_COMPZ_Pos) /*!< SD2FLT1_COMPZ Mask      0x00000001 */
#define XBAR_XBARFLG4_SD2FLT1_COMPZ_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG4_SD2FLT1_COMPZ_Pos) & \
     XBAR_XBARFLG4_SD2FLT1_COMPZ_Msk) /*!< SD2FLT1_COMPZ Set Value            */
#define XBAR_XBARFLG4_SD2FLT1_COMPZ_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG4_SD2FLT1_COMPZ_Msk) >> \
     XBAR_XBARFLG4_SD2FLT1_COMPZ_Pos) /*!< SD2FLT1_COMPZ Get Value            */


/* XBARCLR1 bitfield */
#define XBAR_XBARCLR1_CMPSS8_CTRIPOUTH_Pos (31U) /*!< CMPSS8_CTRIPOUTH Postion   31         */
#define XBAR_XBARCLR1_CMPSS8_CTRIPOUTH_Msk \
    (0x1U << XBAR_XBARCLR1_CMPSS8_CTRIPOUTH_Pos) /*!< CMPSS8_CTRIPOUTH Mask      0x80000000 */
#define XBAR_XBARCLR1_CMPSS8_CTRIPOUTH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR1_CMPSS8_CTRIPOUTH_Pos) & \
     XBAR_XBARCLR1_CMPSS8_CTRIPOUTH_Msk) /*!< CMPSS8_CTRIPOUTH Set Value            */
#define XBAR_XBARCLR1_CMPSS8_CTRIPOUTH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR1_CMPSS8_CTRIPOUTH_Msk) >> \
     XBAR_XBARCLR1_CMPSS8_CTRIPOUTH_Pos) /*!< CMPSS8_CTRIPOUTH Get Value            */


#define XBAR_XBARCLR1_CMPSS8_CTRIPOUTL_Pos (30U) /*!< CMPSS8_CTRIPOUTL Postion   30         */
#define XBAR_XBARCLR1_CMPSS8_CTRIPOUTL_Msk \
    (0x1U << XBAR_XBARCLR1_CMPSS8_CTRIPOUTL_Pos) /*!< CMPSS8_CTRIPOUTL Mask      0x40000000 */
#define XBAR_XBARCLR1_CMPSS8_CTRIPOUTL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR1_CMPSS8_CTRIPOUTL_Pos) & \
     XBAR_XBARCLR1_CMPSS8_CTRIPOUTL_Msk) /*!< CMPSS8_CTRIPOUTL Set Value            */
#define XBAR_XBARCLR1_CMPSS8_CTRIPOUTL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR1_CMPSS8_CTRIPOUTL_Msk) >> \
     XBAR_XBARCLR1_CMPSS8_CTRIPOUTL_Pos) /*!< CMPSS8_CTRIPOUTL Get Value            */


#define XBAR_XBARCLR1_CMPSS7_CTRIPOUTH_Pos (29U) /*!< CMPSS7_CTRIPOUTH Postion   29         */
#define XBAR_XBARCLR1_CMPSS7_CTRIPOUTH_Msk \
    (0x1U << XBAR_XBARCLR1_CMPSS7_CTRIPOUTH_Pos) /*!< CMPSS7_CTRIPOUTH Mask      0x20000000 */
#define XBAR_XBARCLR1_CMPSS7_CTRIPOUTH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR1_CMPSS7_CTRIPOUTH_Pos) & \
     XBAR_XBARCLR1_CMPSS7_CTRIPOUTH_Msk) /*!< CMPSS7_CTRIPOUTH Set Value            */
#define XBAR_XBARCLR1_CMPSS7_CTRIPOUTH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR1_CMPSS7_CTRIPOUTH_Msk) >> \
     XBAR_XBARCLR1_CMPSS7_CTRIPOUTH_Pos) /*!< CMPSS7_CTRIPOUTH Get Value            */


#define XBAR_XBARCLR1_CMPSS7_CTRIPOUTL_Pos (28U) /*!< CMPSS7_CTRIPOUTL Postion   28         */
#define XBAR_XBARCLR1_CMPSS7_CTRIPOUTL_Msk \
    (0x1U << XBAR_XBARCLR1_CMPSS7_CTRIPOUTL_Pos) /*!< CMPSS7_CTRIPOUTL Mask      0x10000000 */
#define XBAR_XBARCLR1_CMPSS7_CTRIPOUTL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR1_CMPSS7_CTRIPOUTL_Pos) & \
     XBAR_XBARCLR1_CMPSS7_CTRIPOUTL_Msk) /*!< CMPSS7_CTRIPOUTL Set Value            */
#define XBAR_XBARCLR1_CMPSS7_CTRIPOUTL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR1_CMPSS7_CTRIPOUTL_Msk) >> \
     XBAR_XBARCLR1_CMPSS7_CTRIPOUTL_Pos) /*!< CMPSS7_CTRIPOUTL Get Value            */


#define XBAR_XBARCLR1_CMPSS6_CTRIPOUTH_Pos (27U) /*!< CMPSS6_CTRIPOUTH Postion   27         */
#define XBAR_XBARCLR1_CMPSS6_CTRIPOUTH_Msk \
    (0x1U << XBAR_XBARCLR1_CMPSS6_CTRIPOUTH_Pos) /*!< CMPSS6_CTRIPOUTH Mask      0x08000000 */
#define XBAR_XBARCLR1_CMPSS6_CTRIPOUTH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR1_CMPSS6_CTRIPOUTH_Pos) & \
     XBAR_XBARCLR1_CMPSS6_CTRIPOUTH_Msk) /*!< CMPSS6_CTRIPOUTH Set Value            */
#define XBAR_XBARCLR1_CMPSS6_CTRIPOUTH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR1_CMPSS6_CTRIPOUTH_Msk) >> \
     XBAR_XBARCLR1_CMPSS6_CTRIPOUTH_Pos) /*!< CMPSS6_CTRIPOUTH Get Value            */


#define XBAR_XBARCLR1_CMPSS6_CTRIPOUTL_Pos (26U) /*!< CMPSS6_CTRIPOUTL Postion   26         */
#define XBAR_XBARCLR1_CMPSS6_CTRIPOUTL_Msk \
    (0x1U << XBAR_XBARCLR1_CMPSS6_CTRIPOUTL_Pos) /*!< CMPSS6_CTRIPOUTL Mask      0x04000000 */
#define XBAR_XBARCLR1_CMPSS6_CTRIPOUTL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR1_CMPSS6_CTRIPOUTL_Pos) & \
     XBAR_XBARCLR1_CMPSS6_CTRIPOUTL_Msk) /*!< CMPSS6_CTRIPOUTL Set Value            */
#define XBAR_XBARCLR1_CMPSS6_CTRIPOUTL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR1_CMPSS6_CTRIPOUTL_Msk) >> \
     XBAR_XBARCLR1_CMPSS6_CTRIPOUTL_Pos) /*!< CMPSS6_CTRIPOUTL Get Value            */


#define XBAR_XBARCLR1_CMPSS5_CTRIPOUTH_Pos (25U) /*!< CMPSS5_CTRIPOUTH Postion   25         */
#define XBAR_XBARCLR1_CMPSS5_CTRIPOUTH_Msk \
    (0x1U << XBAR_XBARCLR1_CMPSS5_CTRIPOUTH_Pos) /*!< CMPSS5_CTRIPOUTH Mask      0x02000000 */
#define XBAR_XBARCLR1_CMPSS5_CTRIPOUTH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR1_CMPSS5_CTRIPOUTH_Pos) & \
     XBAR_XBARCLR1_CMPSS5_CTRIPOUTH_Msk) /*!< CMPSS5_CTRIPOUTH Set Value            */
#define XBAR_XBARCLR1_CMPSS5_CTRIPOUTH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR1_CMPSS5_CTRIPOUTH_Msk) >> \
     XBAR_XBARCLR1_CMPSS5_CTRIPOUTH_Pos) /*!< CMPSS5_CTRIPOUTH Get Value            */


#define XBAR_XBARCLR1_CMPSS5_CTRIPOUTL_Pos (24U) /*!< CMPSS5_CTRIPOUTL Postion   24         */
#define XBAR_XBARCLR1_CMPSS5_CTRIPOUTL_Msk \
    (0x1U << XBAR_XBARCLR1_CMPSS5_CTRIPOUTL_Pos) /*!< CMPSS5_CTRIPOUTL Mask      0x01000000 */
#define XBAR_XBARCLR1_CMPSS5_CTRIPOUTL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR1_CMPSS5_CTRIPOUTL_Pos) & \
     XBAR_XBARCLR1_CMPSS5_CTRIPOUTL_Msk) /*!< CMPSS5_CTRIPOUTL Set Value            */
#define XBAR_XBARCLR1_CMPSS5_CTRIPOUTL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR1_CMPSS5_CTRIPOUTL_Msk) >> \
     XBAR_XBARCLR1_CMPSS5_CTRIPOUTL_Pos) /*!< CMPSS5_CTRIPOUTL Get Value            */


#define XBAR_XBARCLR1_CMPSS4_CTRIPOUTH_Pos (23U) /*!< CMPSS4_CTRIPOUTH Postion   23         */
#define XBAR_XBARCLR1_CMPSS4_CTRIPOUTH_Msk \
    (0x1U << XBAR_XBARCLR1_CMPSS4_CTRIPOUTH_Pos) /*!< CMPSS4_CTRIPOUTH Mask      0x00800000 */
#define XBAR_XBARCLR1_CMPSS4_CTRIPOUTH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR1_CMPSS4_CTRIPOUTH_Pos) & \
     XBAR_XBARCLR1_CMPSS4_CTRIPOUTH_Msk) /*!< CMPSS4_CTRIPOUTH Set Value            */
#define XBAR_XBARCLR1_CMPSS4_CTRIPOUTH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR1_CMPSS4_CTRIPOUTH_Msk) >> \
     XBAR_XBARCLR1_CMPSS4_CTRIPOUTH_Pos) /*!< CMPSS4_CTRIPOUTH Get Value            */


#define XBAR_XBARCLR1_CMPSS4_CTRIPOUTL_Pos (22U) /*!< CMPSS4_CTRIPOUTL Postion   22         */
#define XBAR_XBARCLR1_CMPSS4_CTRIPOUTL_Msk \
    (0x1U << XBAR_XBARCLR1_CMPSS4_CTRIPOUTL_Pos) /*!< CMPSS4_CTRIPOUTL Mask      0x00400000 */
#define XBAR_XBARCLR1_CMPSS4_CTRIPOUTL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR1_CMPSS4_CTRIPOUTL_Pos) & \
     XBAR_XBARCLR1_CMPSS4_CTRIPOUTL_Msk) /*!< CMPSS4_CTRIPOUTL Set Value            */
#define XBAR_XBARCLR1_CMPSS4_CTRIPOUTL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR1_CMPSS4_CTRIPOUTL_Msk) >> \
     XBAR_XBARCLR1_CMPSS4_CTRIPOUTL_Pos) /*!< CMPSS4_CTRIPOUTL Get Value            */


#define XBAR_XBARCLR1_CMPSS3_CTRIPOUTH_Pos (21U) /*!< CMPSS3_CTRIPOUTH Postion   21         */
#define XBAR_XBARCLR1_CMPSS3_CTRIPOUTH_Msk \
    (0x1U << XBAR_XBARCLR1_CMPSS3_CTRIPOUTH_Pos) /*!< CMPSS3_CTRIPOUTH Mask      0x00200000 */
#define XBAR_XBARCLR1_CMPSS3_CTRIPOUTH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR1_CMPSS3_CTRIPOUTH_Pos) & \
     XBAR_XBARCLR1_CMPSS3_CTRIPOUTH_Msk) /*!< CMPSS3_CTRIPOUTH Set Value            */
#define XBAR_XBARCLR1_CMPSS3_CTRIPOUTH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR1_CMPSS3_CTRIPOUTH_Msk) >> \
     XBAR_XBARCLR1_CMPSS3_CTRIPOUTH_Pos) /*!< CMPSS3_CTRIPOUTH Get Value            */


#define XBAR_XBARCLR1_CMPSS3_CTRIPOUTL_Pos (20U) /*!< CMPSS3_CTRIPOUTL Postion   20         */
#define XBAR_XBARCLR1_CMPSS3_CTRIPOUTL_Msk \
    (0x1U << XBAR_XBARCLR1_CMPSS3_CTRIPOUTL_Pos) /*!< CMPSS3_CTRIPOUTL Mask      0x00100000 */
#define XBAR_XBARCLR1_CMPSS3_CTRIPOUTL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR1_CMPSS3_CTRIPOUTL_Pos) & \
     XBAR_XBARCLR1_CMPSS3_CTRIPOUTL_Msk) /*!< CMPSS3_CTRIPOUTL Set Value            */
#define XBAR_XBARCLR1_CMPSS3_CTRIPOUTL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR1_CMPSS3_CTRIPOUTL_Msk) >> \
     XBAR_XBARCLR1_CMPSS3_CTRIPOUTL_Pos) /*!< CMPSS3_CTRIPOUTL Get Value            */


#define XBAR_XBARCLR1_CMPSS2_CTRIPOUTH_Pos (19U) /*!< CMPSS2_CTRIPOUTH Postion   19         */
#define XBAR_XBARCLR1_CMPSS2_CTRIPOUTH_Msk \
    (0x1U << XBAR_XBARCLR1_CMPSS2_CTRIPOUTH_Pos) /*!< CMPSS2_CTRIPOUTH Mask      0x00080000 */
#define XBAR_XBARCLR1_CMPSS2_CTRIPOUTH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR1_CMPSS2_CTRIPOUTH_Pos) & \
     XBAR_XBARCLR1_CMPSS2_CTRIPOUTH_Msk) /*!< CMPSS2_CTRIPOUTH Set Value            */
#define XBAR_XBARCLR1_CMPSS2_CTRIPOUTH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR1_CMPSS2_CTRIPOUTH_Msk) >> \
     XBAR_XBARCLR1_CMPSS2_CTRIPOUTH_Pos) /*!< CMPSS2_CTRIPOUTH Get Value            */


#define XBAR_XBARCLR1_CMPSS2_CTRIPOUTL_Pos (18U) /*!< CMPSS2_CTRIPOUTL Postion   18         */
#define XBAR_XBARCLR1_CMPSS2_CTRIPOUTL_Msk \
    (0x1U << XBAR_XBARCLR1_CMPSS2_CTRIPOUTL_Pos) /*!< CMPSS2_CTRIPOUTL Mask      0x00040000 */
#define XBAR_XBARCLR1_CMPSS2_CTRIPOUTL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR1_CMPSS2_CTRIPOUTL_Pos) & \
     XBAR_XBARCLR1_CMPSS2_CTRIPOUTL_Msk) /*!< CMPSS2_CTRIPOUTL Set Value            */
#define XBAR_XBARCLR1_CMPSS2_CTRIPOUTL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR1_CMPSS2_CTRIPOUTL_Msk) >> \
     XBAR_XBARCLR1_CMPSS2_CTRIPOUTL_Pos) /*!< CMPSS2_CTRIPOUTL Get Value            */


#define XBAR_XBARCLR1_CMPSS1_CTRIPOUTH_Pos (17U) /*!< CMPSS1_CTRIPOUTH Postion   17         */
#define XBAR_XBARCLR1_CMPSS1_CTRIPOUTH_Msk \
    (0x1U << XBAR_XBARCLR1_CMPSS1_CTRIPOUTH_Pos) /*!< CMPSS1_CTRIPOUTH Mask      0x00020000 */
#define XBAR_XBARCLR1_CMPSS1_CTRIPOUTH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR1_CMPSS1_CTRIPOUTH_Pos) & \
     XBAR_XBARCLR1_CMPSS1_CTRIPOUTH_Msk) /*!< CMPSS1_CTRIPOUTH Set Value            */
#define XBAR_XBARCLR1_CMPSS1_CTRIPOUTH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR1_CMPSS1_CTRIPOUTH_Msk) >> \
     XBAR_XBARCLR1_CMPSS1_CTRIPOUTH_Pos) /*!< CMPSS1_CTRIPOUTH Get Value            */


#define XBAR_XBARCLR1_CMPSS1_CTRIPOUTL_Pos (16U) /*!< CMPSS1_CTRIPOUTL Postion   16         */
#define XBAR_XBARCLR1_CMPSS1_CTRIPOUTL_Msk \
    (0x1U << XBAR_XBARCLR1_CMPSS1_CTRIPOUTL_Pos) /*!< CMPSS1_CTRIPOUTL Mask      0x00010000 */
#define XBAR_XBARCLR1_CMPSS1_CTRIPOUTL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR1_CMPSS1_CTRIPOUTL_Pos) & \
     XBAR_XBARCLR1_CMPSS1_CTRIPOUTL_Msk) /*!< CMPSS1_CTRIPOUTL Set Value            */
#define XBAR_XBARCLR1_CMPSS1_CTRIPOUTL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR1_CMPSS1_CTRIPOUTL_Msk) >> \
     XBAR_XBARCLR1_CMPSS1_CTRIPOUTL_Pos) /*!< CMPSS1_CTRIPOUTL Get Value            */


#define XBAR_XBARCLR1_CMPSS8_CTRIPH_Pos (15U) /*!< CMPSS8_CTRIPH Postion   15         */
#define XBAR_XBARCLR1_CMPSS8_CTRIPH_Msk \
    (0x1U << XBAR_XBARCLR1_CMPSS8_CTRIPH_Pos) /*!< CMPSS8_CTRIPH Mask      0x00008000 */
#define XBAR_XBARCLR1_CMPSS8_CTRIPH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR1_CMPSS8_CTRIPH_Pos) & \
     XBAR_XBARCLR1_CMPSS8_CTRIPH_Msk) /*!< CMPSS8_CTRIPH Set Value            */
#define XBAR_XBARCLR1_CMPSS8_CTRIPH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR1_CMPSS8_CTRIPH_Msk) >> \
     XBAR_XBARCLR1_CMPSS8_CTRIPH_Pos) /*!< CMPSS8_CTRIPH Get Value            */


#define XBAR_XBARCLR1_CMPSS8_CTRIPL_Pos (14U) /*!< CMPSS8_CTRIPL Postion   14         */
#define XBAR_XBARCLR1_CMPSS8_CTRIPL_Msk \
    (0x1U << XBAR_XBARCLR1_CMPSS8_CTRIPL_Pos) /*!< CMPSS8_CTRIPL Mask      0x00004000 */
#define XBAR_XBARCLR1_CMPSS8_CTRIPL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR1_CMPSS8_CTRIPL_Pos) & \
     XBAR_XBARCLR1_CMPSS8_CTRIPL_Msk) /*!< CMPSS8_CTRIPL Set Value            */
#define XBAR_XBARCLR1_CMPSS8_CTRIPL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR1_CMPSS8_CTRIPL_Msk) >> \
     XBAR_XBARCLR1_CMPSS8_CTRIPL_Pos) /*!< CMPSS8_CTRIPL Get Value            */


#define XBAR_XBARCLR1_CMPSS7_CTRIPH_Pos (13U) /*!< CMPSS7_CTRIPH Postion   13         */
#define XBAR_XBARCLR1_CMPSS7_CTRIPH_Msk \
    (0x1U << XBAR_XBARCLR1_CMPSS7_CTRIPH_Pos) /*!< CMPSS7_CTRIPH Mask      0x00002000 */
#define XBAR_XBARCLR1_CMPSS7_CTRIPH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR1_CMPSS7_CTRIPH_Pos) & \
     XBAR_XBARCLR1_CMPSS7_CTRIPH_Msk) /*!< CMPSS7_CTRIPH Set Value            */
#define XBAR_XBARCLR1_CMPSS7_CTRIPH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR1_CMPSS7_CTRIPH_Msk) >> \
     XBAR_XBARCLR1_CMPSS7_CTRIPH_Pos) /*!< CMPSS7_CTRIPH Get Value            */


#define XBAR_XBARCLR1_CMPSS7_CTRIPL_Pos (12U) /*!< CMPSS7_CTRIPL Postion   12         */
#define XBAR_XBARCLR1_CMPSS7_CTRIPL_Msk \
    (0x1U << XBAR_XBARCLR1_CMPSS7_CTRIPL_Pos) /*!< CMPSS7_CTRIPL Mask      0x00001000 */
#define XBAR_XBARCLR1_CMPSS7_CTRIPL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR1_CMPSS7_CTRIPL_Pos) & \
     XBAR_XBARCLR1_CMPSS7_CTRIPL_Msk) /*!< CMPSS7_CTRIPL Set Value            */
#define XBAR_XBARCLR1_CMPSS7_CTRIPL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR1_CMPSS7_CTRIPL_Msk) >> \
     XBAR_XBARCLR1_CMPSS7_CTRIPL_Pos) /*!< CMPSS7_CTRIPL Get Value            */


#define XBAR_XBARCLR1_CMPSS6_CTRIPH_Pos (11U) /*!< CMPSS6_CTRIPH Postion   11         */
#define XBAR_XBARCLR1_CMPSS6_CTRIPH_Msk \
    (0x1U << XBAR_XBARCLR1_CMPSS6_CTRIPH_Pos) /*!< CMPSS6_CTRIPH Mask      0x00000800 */
#define XBAR_XBARCLR1_CMPSS6_CTRIPH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR1_CMPSS6_CTRIPH_Pos) & \
     XBAR_XBARCLR1_CMPSS6_CTRIPH_Msk) /*!< CMPSS6_CTRIPH Set Value            */
#define XBAR_XBARCLR1_CMPSS6_CTRIPH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR1_CMPSS6_CTRIPH_Msk) >> \
     XBAR_XBARCLR1_CMPSS6_CTRIPH_Pos) /*!< CMPSS6_CTRIPH Get Value            */


#define XBAR_XBARCLR1_CMPSS6_CTRIPL_Pos (10U) /*!< CMPSS6_CTRIPL Postion   10         */
#define XBAR_XBARCLR1_CMPSS6_CTRIPL_Msk \
    (0x1U << XBAR_XBARCLR1_CMPSS6_CTRIPL_Pos) /*!< CMPSS6_CTRIPL Mask      0x00000400 */
#define XBAR_XBARCLR1_CMPSS6_CTRIPL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR1_CMPSS6_CTRIPL_Pos) & \
     XBAR_XBARCLR1_CMPSS6_CTRIPL_Msk) /*!< CMPSS6_CTRIPL Set Value            */
#define XBAR_XBARCLR1_CMPSS6_CTRIPL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR1_CMPSS6_CTRIPL_Msk) >> \
     XBAR_XBARCLR1_CMPSS6_CTRIPL_Pos) /*!< CMPSS6_CTRIPL Get Value            */


#define XBAR_XBARCLR1_CMPSS5_CTRIPH_Pos (9U) /*!< CMPSS5_CTRIPH Postion   9          */
#define XBAR_XBARCLR1_CMPSS5_CTRIPH_Msk \
    (0x1U << XBAR_XBARCLR1_CMPSS5_CTRIPH_Pos) /*!< CMPSS5_CTRIPH Mask      0x00000200 */
#define XBAR_XBARCLR1_CMPSS5_CTRIPH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR1_CMPSS5_CTRIPH_Pos) & \
     XBAR_XBARCLR1_CMPSS5_CTRIPH_Msk) /*!< CMPSS5_CTRIPH Set Value            */
#define XBAR_XBARCLR1_CMPSS5_CTRIPH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR1_CMPSS5_CTRIPH_Msk) >> \
     XBAR_XBARCLR1_CMPSS5_CTRIPH_Pos) /*!< CMPSS5_CTRIPH Get Value            */


#define XBAR_XBARCLR1_CMPSS5_CTRIPL_Pos (8U) /*!< CMPSS5_CTRIPL Postion   8          */
#define XBAR_XBARCLR1_CMPSS5_CTRIPL_Msk \
    (0x1U << XBAR_XBARCLR1_CMPSS5_CTRIPL_Pos) /*!< CMPSS5_CTRIPL Mask      0x00000100 */
#define XBAR_XBARCLR1_CMPSS5_CTRIPL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR1_CMPSS5_CTRIPL_Pos) & \
     XBAR_XBARCLR1_CMPSS5_CTRIPL_Msk) /*!< CMPSS5_CTRIPL Set Value            */
#define XBAR_XBARCLR1_CMPSS5_CTRIPL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR1_CMPSS5_CTRIPL_Msk) >> \
     XBAR_XBARCLR1_CMPSS5_CTRIPL_Pos) /*!< CMPSS5_CTRIPL Get Value            */


#define XBAR_XBARCLR1_CMPSS4_CTRIPH_Pos (7U) /*!< CMPSS4_CTRIPH Postion   7          */
#define XBAR_XBARCLR1_CMPSS4_CTRIPH_Msk \
    (0x1U << XBAR_XBARCLR1_CMPSS4_CTRIPH_Pos) /*!< CMPSS4_CTRIPH Mask      0x00000080 */
#define XBAR_XBARCLR1_CMPSS4_CTRIPH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR1_CMPSS4_CTRIPH_Pos) & \
     XBAR_XBARCLR1_CMPSS4_CTRIPH_Msk) /*!< CMPSS4_CTRIPH Set Value            */
#define XBAR_XBARCLR1_CMPSS4_CTRIPH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR1_CMPSS4_CTRIPH_Msk) >> \
     XBAR_XBARCLR1_CMPSS4_CTRIPH_Pos) /*!< CMPSS4_CTRIPH Get Value            */


#define XBAR_XBARCLR1_CMPSS4_CTRIPL_Pos (6U) /*!< CMPSS4_CTRIPL Postion   6          */
#define XBAR_XBARCLR1_CMPSS4_CTRIPL_Msk \
    (0x1U << XBAR_XBARCLR1_CMPSS4_CTRIPL_Pos) /*!< CMPSS4_CTRIPL Mask      0x00000040 */
#define XBAR_XBARCLR1_CMPSS4_CTRIPL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR1_CMPSS4_CTRIPL_Pos) & \
     XBAR_XBARCLR1_CMPSS4_CTRIPL_Msk) /*!< CMPSS4_CTRIPL Set Value            */
#define XBAR_XBARCLR1_CMPSS4_CTRIPL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR1_CMPSS4_CTRIPL_Msk) >> \
     XBAR_XBARCLR1_CMPSS4_CTRIPL_Pos) /*!< CMPSS4_CTRIPL Get Value            */


#define XBAR_XBARCLR1_CMPSS3_CTRIPH_Pos (5U) /*!< CMPSS3_CTRIPH Postion   5          */
#define XBAR_XBARCLR1_CMPSS3_CTRIPH_Msk \
    (0x1U << XBAR_XBARCLR1_CMPSS3_CTRIPH_Pos) /*!< CMPSS3_CTRIPH Mask      0x00000020 */
#define XBAR_XBARCLR1_CMPSS3_CTRIPH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR1_CMPSS3_CTRIPH_Pos) & \
     XBAR_XBARCLR1_CMPSS3_CTRIPH_Msk) /*!< CMPSS3_CTRIPH Set Value            */
#define XBAR_XBARCLR1_CMPSS3_CTRIPH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR1_CMPSS3_CTRIPH_Msk) >> \
     XBAR_XBARCLR1_CMPSS3_CTRIPH_Pos) /*!< CMPSS3_CTRIPH Get Value            */


#define XBAR_XBARCLR1_CMPSS3_CTRIPL_Pos (4U) /*!< CMPSS3_CTRIPL Postion   4          */
#define XBAR_XBARCLR1_CMPSS3_CTRIPL_Msk \
    (0x1U << XBAR_XBARCLR1_CMPSS3_CTRIPL_Pos) /*!< CMPSS3_CTRIPL Mask      0x00000010 */
#define XBAR_XBARCLR1_CMPSS3_CTRIPL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR1_CMPSS3_CTRIPL_Pos) & \
     XBAR_XBARCLR1_CMPSS3_CTRIPL_Msk) /*!< CMPSS3_CTRIPL Set Value            */
#define XBAR_XBARCLR1_CMPSS3_CTRIPL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR1_CMPSS3_CTRIPL_Msk) >> \
     XBAR_XBARCLR1_CMPSS3_CTRIPL_Pos) /*!< CMPSS3_CTRIPL Get Value            */


#define XBAR_XBARCLR1_CMPSS2_CTRIPH_Pos (3U) /*!< CMPSS2_CTRIPH Postion   3          */
#define XBAR_XBARCLR1_CMPSS2_CTRIPH_Msk \
    (0x1U << XBAR_XBARCLR1_CMPSS2_CTRIPH_Pos) /*!< CMPSS2_CTRIPH Mask      0x00000008 */
#define XBAR_XBARCLR1_CMPSS2_CTRIPH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR1_CMPSS2_CTRIPH_Pos) & \
     XBAR_XBARCLR1_CMPSS2_CTRIPH_Msk) /*!< CMPSS2_CTRIPH Set Value            */
#define XBAR_XBARCLR1_CMPSS2_CTRIPH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR1_CMPSS2_CTRIPH_Msk) >> \
     XBAR_XBARCLR1_CMPSS2_CTRIPH_Pos) /*!< CMPSS2_CTRIPH Get Value            */


#define XBAR_XBARCLR1_CMPSS2_CTRIPL_Pos (2U) /*!< CMPSS2_CTRIPL Postion   2          */
#define XBAR_XBARCLR1_CMPSS2_CTRIPL_Msk \
    (0x1U << XBAR_XBARCLR1_CMPSS2_CTRIPL_Pos) /*!< CMPSS2_CTRIPL Mask      0x00000004 */
#define XBAR_XBARCLR1_CMPSS2_CTRIPL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR1_CMPSS2_CTRIPL_Pos) & \
     XBAR_XBARCLR1_CMPSS2_CTRIPL_Msk) /*!< CMPSS2_CTRIPL Set Value            */
#define XBAR_XBARCLR1_CMPSS2_CTRIPL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR1_CMPSS2_CTRIPL_Msk) >> \
     XBAR_XBARCLR1_CMPSS2_CTRIPL_Pos) /*!< CMPSS2_CTRIPL Get Value            */


#define XBAR_XBARCLR1_CMPSS1_CTRIPH_Pos (1U) /*!< CMPSS1_CTRIPH Postion   1          */
#define XBAR_XBARCLR1_CMPSS1_CTRIPH_Msk \
    (0x1U << XBAR_XBARCLR1_CMPSS1_CTRIPH_Pos) /*!< CMPSS1_CTRIPH Mask      0x00000002 */
#define XBAR_XBARCLR1_CMPSS1_CTRIPH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR1_CMPSS1_CTRIPH_Pos) & \
     XBAR_XBARCLR1_CMPSS1_CTRIPH_Msk) /*!< CMPSS1_CTRIPH Set Value            */
#define XBAR_XBARCLR1_CMPSS1_CTRIPH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR1_CMPSS1_CTRIPH_Msk) >> \
     XBAR_XBARCLR1_CMPSS1_CTRIPH_Pos) /*!< CMPSS1_CTRIPH Get Value            */


#define XBAR_XBARCLR1_CMPSS1_CTRIPL_Pos (0U) /*!< CMPSS1_CTRIPL Postion   0          */
#define XBAR_XBARCLR1_CMPSS1_CTRIPL_Msk \
    (0x1U << XBAR_XBARCLR1_CMPSS1_CTRIPL_Pos) /*!< CMPSS1_CTRIPL Mask      0x00000001 */
#define XBAR_XBARCLR1_CMPSS1_CTRIPL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR1_CMPSS1_CTRIPL_Pos) & \
     XBAR_XBARCLR1_CMPSS1_CTRIPL_Msk) /*!< CMPSS1_CTRIPL Set Value            */
#define XBAR_XBARCLR1_CMPSS1_CTRIPL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR1_CMPSS1_CTRIPL_Msk) >> \
     XBAR_XBARCLR1_CMPSS1_CTRIPL_Pos) /*!< CMPSS1_CTRIPL Get Value            */


/* XBARCLR2 bitfield */
#define XBAR_XBARCLR2_ADCCEVT1_Pos (31U)                                /*!< ADCCEVT1 Postion   31         */
#define XBAR_XBARCLR2_ADCCEVT1_Msk (0x1U << XBAR_XBARCLR2_ADCCEVT1_Pos) /*!< ADCCEVT1 Mask      0x80000000 */
#define XBAR_XBARCLR2_ADCCEVT1_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR2_ADCCEVT1_Pos) & XBAR_XBARCLR2_ADCCEVT1_Msk) /*!< ADCCEVT1 Set Value */
#define XBAR_XBARCLR2_ADCCEVT1_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR2_ADCCEVT1_Msk) >> XBAR_XBARCLR2_ADCCEVT1_Pos) /*!< ADCCEVT1 Get Value            */


#define XBAR_XBARCLR2_ADCBEVT4_Pos (30U)                                /*!< ADCBEVT4 Postion   30         */
#define XBAR_XBARCLR2_ADCBEVT4_Msk (0x1U << XBAR_XBARCLR2_ADCBEVT4_Pos) /*!< ADCBEVT4 Mask      0x40000000 */
#define XBAR_XBARCLR2_ADCBEVT4_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR2_ADCBEVT4_Pos) & XBAR_XBARCLR2_ADCBEVT4_Msk) /*!< ADCBEVT4 Set Value */
#define XBAR_XBARCLR2_ADCBEVT4_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR2_ADCBEVT4_Msk) >> XBAR_XBARCLR2_ADCBEVT4_Pos) /*!< ADCBEVT4 Get Value            */


#define XBAR_XBARCLR2_ADCBEVT3_Pos (29U)                                /*!< ADCBEVT3 Postion   29         */
#define XBAR_XBARCLR2_ADCBEVT3_Msk (0x1U << XBAR_XBARCLR2_ADCBEVT3_Pos) /*!< ADCBEVT3 Mask      0x20000000 */
#define XBAR_XBARCLR2_ADCBEVT3_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR2_ADCBEVT3_Pos) & XBAR_XBARCLR2_ADCBEVT3_Msk) /*!< ADCBEVT3 Set Value */
#define XBAR_XBARCLR2_ADCBEVT3_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR2_ADCBEVT3_Msk) >> XBAR_XBARCLR2_ADCBEVT3_Pos) /*!< ADCBEVT3 Get Value            */


#define XBAR_XBARCLR2_ADCBEVT2_Pos (28U)                                /*!< ADCBEVT2 Postion   28         */
#define XBAR_XBARCLR2_ADCBEVT2_Msk (0x1U << XBAR_XBARCLR2_ADCBEVT2_Pos) /*!< ADCBEVT2 Mask      0x10000000 */
#define XBAR_XBARCLR2_ADCBEVT2_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR2_ADCBEVT2_Pos) & XBAR_XBARCLR2_ADCBEVT2_Msk) /*!< ADCBEVT2 Set Value */
#define XBAR_XBARCLR2_ADCBEVT2_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR2_ADCBEVT2_Msk) >> XBAR_XBARCLR2_ADCBEVT2_Pos) /*!< ADCBEVT2 Get Value            */


#define XBAR_XBARCLR2_ADCBEVT1_Pos (27U)                                /*!< ADCBEVT1 Postion   27         */
#define XBAR_XBARCLR2_ADCBEVT1_Msk (0x1U << XBAR_XBARCLR2_ADCBEVT1_Pos) /*!< ADCBEVT1 Mask      0x08000000 */
#define XBAR_XBARCLR2_ADCBEVT1_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR2_ADCBEVT1_Pos) & XBAR_XBARCLR2_ADCBEVT1_Msk) /*!< ADCBEVT1 Set Value */
#define XBAR_XBARCLR2_ADCBEVT1_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR2_ADCBEVT1_Msk) >> XBAR_XBARCLR2_ADCBEVT1_Pos) /*!< ADCBEVT1 Get Value            */


#define XBAR_XBARCLR2_ADCAEVT4_Pos (26U)                                /*!< ADCAEVT4 Postion   26         */
#define XBAR_XBARCLR2_ADCAEVT4_Msk (0x1U << XBAR_XBARCLR2_ADCAEVT4_Pos) /*!< ADCAEVT4 Mask      0x04000000 */
#define XBAR_XBARCLR2_ADCAEVT4_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR2_ADCAEVT4_Pos) & XBAR_XBARCLR2_ADCAEVT4_Msk) /*!< ADCAEVT4 Set Value */
#define XBAR_XBARCLR2_ADCAEVT4_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR2_ADCAEVT4_Msk) >> XBAR_XBARCLR2_ADCAEVT4_Pos) /*!< ADCAEVT4 Get Value            */


#define XBAR_XBARCLR2_ADCAEVT3_Pos (25U)                                /*!< ADCAEVT3 Postion   25         */
#define XBAR_XBARCLR2_ADCAEVT3_Msk (0x1U << XBAR_XBARCLR2_ADCAEVT3_Pos) /*!< ADCAEVT3 Mask      0x02000000 */
#define XBAR_XBARCLR2_ADCAEVT3_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR2_ADCAEVT3_Pos) & XBAR_XBARCLR2_ADCAEVT3_Msk) /*!< ADCAEVT3 Set Value */
#define XBAR_XBARCLR2_ADCAEVT3_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR2_ADCAEVT3_Msk) >> XBAR_XBARCLR2_ADCAEVT3_Pos) /*!< ADCAEVT3 Get Value            */


#define XBAR_XBARCLR2_ADCAEVT2_Pos (24U)                                /*!< ADCAEVT2 Postion   24         */
#define XBAR_XBARCLR2_ADCAEVT2_Msk (0x1U << XBAR_XBARCLR2_ADCAEVT2_Pos) /*!< ADCAEVT2 Mask      0x01000000 */
#define XBAR_XBARCLR2_ADCAEVT2_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR2_ADCAEVT2_Pos) & XBAR_XBARCLR2_ADCAEVT2_Msk) /*!< ADCAEVT2 Set Value */
#define XBAR_XBARCLR2_ADCAEVT2_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR2_ADCAEVT2_Msk) >> XBAR_XBARCLR2_ADCAEVT2_Pos) /*!< ADCAEVT2 Get Value            */


#define XBAR_XBARCLR2_ADCAEVT1_Pos (23U)                                /*!< ADCAEVT1 Postion   23         */
#define XBAR_XBARCLR2_ADCAEVT1_Msk (0x1U << XBAR_XBARCLR2_ADCAEVT1_Pos) /*!< ADCAEVT1 Mask      0x00800000 */
#define XBAR_XBARCLR2_ADCAEVT1_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR2_ADCAEVT1_Pos) & XBAR_XBARCLR2_ADCAEVT1_Msk) /*!< ADCAEVT1 Set Value */
#define XBAR_XBARCLR2_ADCAEVT1_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR2_ADCAEVT1_Msk) >> XBAR_XBARCLR2_ADCAEVT1_Pos) /*!< ADCAEVT1 Get Value            */


#define XBAR_XBARCLR2_EXTSYNCOUT_Pos (22U)                                  /*!< EXTSYNCOUT Postion   22         */
#define XBAR_XBARCLR2_EXTSYNCOUT_Msk (0x1U << XBAR_XBARCLR2_EXTSYNCOUT_Pos) /*!< EXTSYNCOUT Mask      0x00400000 */
#define XBAR_XBARCLR2_EXTSYNCOUT_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR2_EXTSYNCOUT_Pos) & XBAR_XBARCLR2_EXTSYNCOUT_Msk) /*!< EXTSYNCOUT Set Value */
#define XBAR_XBARCLR2_EXTSYNCOUT_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR2_EXTSYNCOUT_Msk) >> XBAR_XBARCLR2_EXTSYNCOUT_Pos) /*!< EXTSYNCOUT Get Value */


#define XBAR_XBARCLR2_ECAP6_OUT_Pos (21U)                                 /*!< ECAP6_OUT Postion   21         */
#define XBAR_XBARCLR2_ECAP6_OUT_Msk (0x1U << XBAR_XBARCLR2_ECAP6_OUT_Pos) /*!< ECAP6_OUT Mask      0x00200000 */
#define XBAR_XBARCLR2_ECAP6_OUT_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR2_ECAP6_OUT_Pos) & XBAR_XBARCLR2_ECAP6_OUT_Msk) /*!< ECAP6_OUT Set Value */
#define XBAR_XBARCLR2_ECAP6_OUT_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR2_ECAP6_OUT_Msk) >> XBAR_XBARCLR2_ECAP6_OUT_Pos) /*!< ECAP6_OUT Get Value */


#define XBAR_XBARCLR2_ECAP5_OUT_Pos (20U)                                 /*!< ECAP5_OUT Postion   20         */
#define XBAR_XBARCLR2_ECAP5_OUT_Msk (0x1U << XBAR_XBARCLR2_ECAP5_OUT_Pos) /*!< ECAP5_OUT Mask      0x00100000 */
#define XBAR_XBARCLR2_ECAP5_OUT_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR2_ECAP5_OUT_Pos) & XBAR_XBARCLR2_ECAP5_OUT_Msk) /*!< ECAP5_OUT Set Value */
#define XBAR_XBARCLR2_ECAP5_OUT_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR2_ECAP5_OUT_Msk) >> XBAR_XBARCLR2_ECAP5_OUT_Pos) /*!< ECAP5_OUT Get Value */


#define XBAR_XBARCLR2_ECAP4_OUT_Pos (19U)                                 /*!< ECAP4_OUT Postion   19         */
#define XBAR_XBARCLR2_ECAP4_OUT_Msk (0x1U << XBAR_XBARCLR2_ECAP4_OUT_Pos) /*!< ECAP4_OUT Mask      0x00080000 */
#define XBAR_XBARCLR2_ECAP4_OUT_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR2_ECAP4_OUT_Pos) & XBAR_XBARCLR2_ECAP4_OUT_Msk) /*!< ECAP4_OUT Set Value */
#define XBAR_XBARCLR2_ECAP4_OUT_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR2_ECAP4_OUT_Msk) >> XBAR_XBARCLR2_ECAP4_OUT_Pos) /*!< ECAP4_OUT Get Value */


#define XBAR_XBARCLR2_ECAP3_OUT_Pos (18U)                                 /*!< ECAP3_OUT Postion   18         */
#define XBAR_XBARCLR2_ECAP3_OUT_Msk (0x1U << XBAR_XBARCLR2_ECAP3_OUT_Pos) /*!< ECAP3_OUT Mask      0x00040000 */
#define XBAR_XBARCLR2_ECAP3_OUT_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR2_ECAP3_OUT_Pos) & XBAR_XBARCLR2_ECAP3_OUT_Msk) /*!< ECAP3_OUT Set Value */
#define XBAR_XBARCLR2_ECAP3_OUT_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR2_ECAP3_OUT_Msk) >> XBAR_XBARCLR2_ECAP3_OUT_Pos) /*!< ECAP3_OUT Get Value */


#define XBAR_XBARCLR2_ECAP2_OUT_Pos (17U)                                 /*!< ECAP2_OUT Postion   17         */
#define XBAR_XBARCLR2_ECAP2_OUT_Msk (0x1U << XBAR_XBARCLR2_ECAP2_OUT_Pos) /*!< ECAP2_OUT Mask      0x00020000 */
#define XBAR_XBARCLR2_ECAP2_OUT_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR2_ECAP2_OUT_Pos) & XBAR_XBARCLR2_ECAP2_OUT_Msk) /*!< ECAP2_OUT Set Value */
#define XBAR_XBARCLR2_ECAP2_OUT_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR2_ECAP2_OUT_Msk) >> XBAR_XBARCLR2_ECAP2_OUT_Pos) /*!< ECAP2_OUT Get Value */


#define XBAR_XBARCLR2_ECAP1_OUT_Pos (16U)                                 /*!< ECAP1_OUT Postion   16         */
#define XBAR_XBARCLR2_ECAP1_OUT_Msk (0x1U << XBAR_XBARCLR2_ECAP1_OUT_Pos) /*!< ECAP1_OUT Mask      0x00010000 */
#define XBAR_XBARCLR2_ECAP1_OUT_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR2_ECAP1_OUT_Pos) & XBAR_XBARCLR2_ECAP1_OUT_Msk) /*!< ECAP1_OUT Set Value */
#define XBAR_XBARCLR2_ECAP1_OUT_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR2_ECAP1_OUT_Msk) >> XBAR_XBARCLR2_ECAP1_OUT_Pos) /*!< ECAP1_OUT Get Value */


#define XBAR_XBARCLR2_INPUT14_Pos (15U)                               /*!< INPUT14 Postion   15         */
#define XBAR_XBARCLR2_INPUT14_Msk (0x1U << XBAR_XBARCLR2_INPUT14_Pos) /*!< INPUT14 Mask      0x00008000 */
#define XBAR_XBARCLR2_INPUT14_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR2_INPUT14_Pos) & XBAR_XBARCLR2_INPUT14_Msk) /*!< INPUT14 Set Value            */
#define XBAR_XBARCLR2_INPUT14_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR2_INPUT14_Msk) >> XBAR_XBARCLR2_INPUT14_Pos) /*!< INPUT14 Get Value            */


#define XBAR_XBARCLR2_INPUT13_Pos (14U)                               /*!< INPUT13 Postion   14         */
#define XBAR_XBARCLR2_INPUT13_Msk (0x1U << XBAR_XBARCLR2_INPUT13_Pos) /*!< INPUT13 Mask      0x00004000 */
#define XBAR_XBARCLR2_INPUT13_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR2_INPUT13_Pos) & XBAR_XBARCLR2_INPUT13_Msk) /*!< INPUT13 Set Value            */
#define XBAR_XBARCLR2_INPUT13_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR2_INPUT13_Msk) >> XBAR_XBARCLR2_INPUT13_Pos) /*!< INPUT13 Get Value            */


#define XBAR_XBARCLR2_INPUT12_Pos (13U)                               /*!< INPUT12 Postion   13         */
#define XBAR_XBARCLR2_INPUT12_Msk (0x1U << XBAR_XBARCLR2_INPUT12_Pos) /*!< INPUT12 Mask      0x00002000 */
#define XBAR_XBARCLR2_INPUT12_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR2_INPUT12_Pos) & XBAR_XBARCLR2_INPUT12_Msk) /*!< INPUT12 Set Value            */
#define XBAR_XBARCLR2_INPUT12_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR2_INPUT12_Msk) >> XBAR_XBARCLR2_INPUT12_Pos) /*!< INPUT12 Get Value            */


#define XBAR_XBARCLR2_INPUT11_Pos (12U)                               /*!< INPUT11 Postion   12         */
#define XBAR_XBARCLR2_INPUT11_Msk (0x1U << XBAR_XBARCLR2_INPUT11_Pos) /*!< INPUT11 Mask      0x00001000 */
#define XBAR_XBARCLR2_INPUT11_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR2_INPUT11_Pos) & XBAR_XBARCLR2_INPUT11_Msk) /*!< INPUT11 Set Value            */
#define XBAR_XBARCLR2_INPUT11_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR2_INPUT11_Msk) >> XBAR_XBARCLR2_INPUT11_Pos) /*!< INPUT11 Get Value            */


#define XBAR_XBARCLR2_INPUT10_Pos (11U)                               /*!< INPUT10 Postion   11         */
#define XBAR_XBARCLR2_INPUT10_Msk (0x1U << XBAR_XBARCLR2_INPUT10_Pos) /*!< INPUT10 Mask      0x00000800 */
#define XBAR_XBARCLR2_INPUT10_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR2_INPUT10_Pos) & XBAR_XBARCLR2_INPUT10_Msk) /*!< INPUT10 Set Value            */
#define XBAR_XBARCLR2_INPUT10_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR2_INPUT10_Msk) >> XBAR_XBARCLR2_INPUT10_Pos) /*!< INPUT10 Get Value            */


#define XBAR_XBARCLR2_INPUT9_Pos (10U)                              /*!< INPUT9 Postion   10         */
#define XBAR_XBARCLR2_INPUT9_Msk (0x1U << XBAR_XBARCLR2_INPUT9_Pos) /*!< INPUT9 Mask      0x00000400 */
#define XBAR_XBARCLR2_INPUT9_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR2_INPUT9_Pos) & XBAR_XBARCLR2_INPUT9_Msk) /*!< INPUT9 Set Value            */
#define XBAR_XBARCLR2_INPUT9_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR2_INPUT9_Msk) >> XBAR_XBARCLR2_INPUT9_Pos) /*!< INPUT9 Get Value            */


#define XBAR_XBARCLR2_INPUT8_Pos (9U)                               /*!< INPUT8 Postion   9          */
#define XBAR_XBARCLR2_INPUT8_Msk (0x1U << XBAR_XBARCLR2_INPUT8_Pos) /*!< INPUT8 Mask      0x00000200 */
#define XBAR_XBARCLR2_INPUT8_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR2_INPUT8_Pos) & XBAR_XBARCLR2_INPUT8_Msk) /*!< INPUT8 Set Value            */
#define XBAR_XBARCLR2_INPUT8_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR2_INPUT8_Msk) >> XBAR_XBARCLR2_INPUT8_Pos) /*!< INPUT8 Get Value            */


#define XBAR_XBARCLR2_INPUT7_Pos (8U)                               /*!< INPUT7 Postion   8          */
#define XBAR_XBARCLR2_INPUT7_Msk (0x1U << XBAR_XBARCLR2_INPUT7_Pos) /*!< INPUT7 Mask      0x00000100 */
#define XBAR_XBARCLR2_INPUT7_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR2_INPUT7_Pos) & XBAR_XBARCLR2_INPUT7_Msk) /*!< INPUT7 Set Value            */
#define XBAR_XBARCLR2_INPUT7_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR2_INPUT7_Msk) >> XBAR_XBARCLR2_INPUT7_Pos) /*!< INPUT7 Get Value            */


#define XBAR_XBARCLR2_ADCSOCBO_Pos (7U)                                 /*!< ADCSOCBO Postion   7          */
#define XBAR_XBARCLR2_ADCSOCBO_Msk (0x1U << XBAR_XBARCLR2_ADCSOCBO_Pos) /*!< ADCSOCBO Mask      0x00000080 */
#define XBAR_XBARCLR2_ADCSOCBO_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR2_ADCSOCBO_Pos) & XBAR_XBARCLR2_ADCSOCBO_Msk) /*!< ADCSOCBO Set Value */
#define XBAR_XBARCLR2_ADCSOCBO_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR2_ADCSOCBO_Msk) >> XBAR_XBARCLR2_ADCSOCBO_Pos) /*!< ADCSOCBO Get Value            */


#define XBAR_XBARCLR2_ADCSOCAO_Pos (6U)                                 /*!< ADCSOCAO Postion   6          */
#define XBAR_XBARCLR2_ADCSOCAO_Msk (0x1U << XBAR_XBARCLR2_ADCSOCAO_Pos) /*!< ADCSOCAO Mask      0x00000040 */
#define XBAR_XBARCLR2_ADCSOCAO_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR2_ADCSOCAO_Pos) & XBAR_XBARCLR2_ADCSOCAO_Msk) /*!< ADCSOCAO Set Value */
#define XBAR_XBARCLR2_ADCSOCAO_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR2_ADCSOCAO_Msk) >> XBAR_XBARCLR2_ADCSOCAO_Pos) /*!< ADCSOCAO Get Value            */


#define XBAR_XBARCLR2_INPUT6_Pos (5U)                               /*!< INPUT6 Postion   5          */
#define XBAR_XBARCLR2_INPUT6_Msk (0x1U << XBAR_XBARCLR2_INPUT6_Pos) /*!< INPUT6 Mask      0x00000020 */
#define XBAR_XBARCLR2_INPUT6_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR2_INPUT6_Pos) & XBAR_XBARCLR2_INPUT6_Msk) /*!< INPUT6 Set Value            */
#define XBAR_XBARCLR2_INPUT6_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR2_INPUT6_Msk) >> XBAR_XBARCLR2_INPUT6_Pos) /*!< INPUT6 Get Value            */


#define XBAR_XBARCLR2_INPUT5_Pos (4U)                               /*!< INPUT5 Postion   4          */
#define XBAR_XBARCLR2_INPUT5_Msk (0x1U << XBAR_XBARCLR2_INPUT5_Pos) /*!< INPUT5 Mask      0x00000010 */
#define XBAR_XBARCLR2_INPUT5_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR2_INPUT5_Pos) & XBAR_XBARCLR2_INPUT5_Msk) /*!< INPUT5 Set Value            */
#define XBAR_XBARCLR2_INPUT5_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR2_INPUT5_Msk) >> XBAR_XBARCLR2_INPUT5_Pos) /*!< INPUT5 Get Value            */


#define XBAR_XBARCLR2_INPUT4_Pos (3U)                               /*!< INPUT4 Postion   3          */
#define XBAR_XBARCLR2_INPUT4_Msk (0x1U << XBAR_XBARCLR2_INPUT4_Pos) /*!< INPUT4 Mask      0x00000008 */
#define XBAR_XBARCLR2_INPUT4_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR2_INPUT4_Pos) & XBAR_XBARCLR2_INPUT4_Msk) /*!< INPUT4 Set Value            */
#define XBAR_XBARCLR2_INPUT4_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR2_INPUT4_Msk) >> XBAR_XBARCLR2_INPUT4_Pos) /*!< INPUT4 Get Value            */


#define XBAR_XBARCLR2_INPUT3_Pos (2U)                               /*!< INPUT3 Postion   2          */
#define XBAR_XBARCLR2_INPUT3_Msk (0x1U << XBAR_XBARCLR2_INPUT3_Pos) /*!< INPUT3 Mask      0x00000004 */
#define XBAR_XBARCLR2_INPUT3_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR2_INPUT3_Pos) & XBAR_XBARCLR2_INPUT3_Msk) /*!< INPUT3 Set Value            */
#define XBAR_XBARCLR2_INPUT3_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR2_INPUT3_Msk) >> XBAR_XBARCLR2_INPUT3_Pos) /*!< INPUT3 Get Value            */


#define XBAR_XBARCLR2_INPUT2_Pos (1U)                               /*!< INPUT2 Postion   1          */
#define XBAR_XBARCLR2_INPUT2_Msk (0x1U << XBAR_XBARCLR2_INPUT2_Pos) /*!< INPUT2 Mask      0x00000002 */
#define XBAR_XBARCLR2_INPUT2_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR2_INPUT2_Pos) & XBAR_XBARCLR2_INPUT2_Msk) /*!< INPUT2 Set Value            */
#define XBAR_XBARCLR2_INPUT2_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR2_INPUT2_Msk) >> XBAR_XBARCLR2_INPUT2_Pos) /*!< INPUT2 Get Value            */


#define XBAR_XBARCLR2_INPUT1_Pos (0U)                               /*!< INPUT1 Postion   0          */
#define XBAR_XBARCLR2_INPUT1_Msk (0x1U << XBAR_XBARCLR2_INPUT1_Pos) /*!< INPUT1 Mask      0x00000001 */
#define XBAR_XBARCLR2_INPUT1_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR2_INPUT1_Pos) & XBAR_XBARCLR2_INPUT1_Msk) /*!< INPUT1 Set Value            */
#define XBAR_XBARCLR2_INPUT1_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR2_INPUT1_Msk) >> XBAR_XBARCLR2_INPUT1_Pos) /*!< INPUT1 Get Value            */


/* XBARCLR3 bitfield */
#define XBAR_XBARCLR3_SD1FLT4_DRINT_Pos (31U) /*!< SD1FLT4_DRINT Postion   31         */
#define XBAR_XBARCLR3_SD1FLT4_DRINT_Msk \
    (0x1U << XBAR_XBARCLR3_SD1FLT4_DRINT_Pos) /*!< SD1FLT4_DRINT Mask      0x80000000 */
#define XBAR_XBARCLR3_SD1FLT4_DRINT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR3_SD1FLT4_DRINT_Pos) & \
     XBAR_XBARCLR3_SD1FLT4_DRINT_Msk) /*!< SD1FLT4_DRINT Set Value            */
#define XBAR_XBARCLR3_SD1FLT4_DRINT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR3_SD1FLT4_DRINT_Msk) >> \
     XBAR_XBARCLR3_SD1FLT4_DRINT_Pos) /*!< SD1FLT4_DRINT Get Value            */


#define XBAR_XBARCLR3_SD1FLT4_COMPZ_Pos (30U) /*!< SD1FLT4_COMPZ Postion   30         */
#define XBAR_XBARCLR3_SD1FLT4_COMPZ_Msk \
    (0x1U << XBAR_XBARCLR3_SD1FLT4_COMPZ_Pos) /*!< SD1FLT4_COMPZ Mask      0x40000000 */
#define XBAR_XBARCLR3_SD1FLT4_COMPZ_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR3_SD1FLT4_COMPZ_Pos) & \
     XBAR_XBARCLR3_SD1FLT4_COMPZ_Msk) /*!< SD1FLT4_COMPZ Set Value            */
#define XBAR_XBARCLR3_SD1FLT4_COMPZ_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR3_SD1FLT4_COMPZ_Msk) >> \
     XBAR_XBARCLR3_SD1FLT4_COMPZ_Pos) /*!< SD1FLT4_COMPZ Get Value            */


#define XBAR_XBARCLR3_SD1FLT3_DRINT_Pos (29U) /*!< SD1FLT3_DRINT Postion   29         */
#define XBAR_XBARCLR3_SD1FLT3_DRINT_Msk \
    (0x1U << XBAR_XBARCLR3_SD1FLT3_DRINT_Pos) /*!< SD1FLT3_DRINT Mask      0x20000000 */
#define XBAR_XBARCLR3_SD1FLT3_DRINT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR3_SD1FLT3_DRINT_Pos) & \
     XBAR_XBARCLR3_SD1FLT3_DRINT_Msk) /*!< SD1FLT3_DRINT Set Value            */
#define XBAR_XBARCLR3_SD1FLT3_DRINT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR3_SD1FLT3_DRINT_Msk) >> \
     XBAR_XBARCLR3_SD1FLT3_DRINT_Pos) /*!< SD1FLT3_DRINT Get Value            */


#define XBAR_XBARCLR3_SD1FLT3_COMPZ_Pos (28U) /*!< SD1FLT3_COMPZ Postion   28         */
#define XBAR_XBARCLR3_SD1FLT3_COMPZ_Msk \
    (0x1U << XBAR_XBARCLR3_SD1FLT3_COMPZ_Pos) /*!< SD1FLT3_COMPZ Mask      0x10000000 */
#define XBAR_XBARCLR3_SD1FLT3_COMPZ_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR3_SD1FLT3_COMPZ_Pos) & \
     XBAR_XBARCLR3_SD1FLT3_COMPZ_Msk) /*!< SD1FLT3_COMPZ Set Value            */
#define XBAR_XBARCLR3_SD1FLT3_COMPZ_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR3_SD1FLT3_COMPZ_Msk) >> \
     XBAR_XBARCLR3_SD1FLT3_COMPZ_Pos) /*!< SD1FLT3_COMPZ Get Value            */


#define XBAR_XBARCLR3_SD1FLT2_DRINT_Pos (27U) /*!< SD1FLT2_DRINT Postion   27         */
#define XBAR_XBARCLR3_SD1FLT2_DRINT_Msk \
    (0x1U << XBAR_XBARCLR3_SD1FLT2_DRINT_Pos) /*!< SD1FLT2_DRINT Mask      0x08000000 */
#define XBAR_XBARCLR3_SD1FLT2_DRINT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR3_SD1FLT2_DRINT_Pos) & \
     XBAR_XBARCLR3_SD1FLT2_DRINT_Msk) /*!< SD1FLT2_DRINT Set Value            */
#define XBAR_XBARCLR3_SD1FLT2_DRINT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR3_SD1FLT2_DRINT_Msk) >> \
     XBAR_XBARCLR3_SD1FLT2_DRINT_Pos) /*!< SD1FLT2_DRINT Get Value            */


#define XBAR_XBARCLR3_SD1FLT2_COMPZ_Pos (26U) /*!< SD1FLT2_COMPZ Postion   26         */
#define XBAR_XBARCLR3_SD1FLT2_COMPZ_Msk \
    (0x1U << XBAR_XBARCLR3_SD1FLT2_COMPZ_Pos) /*!< SD1FLT2_COMPZ Mask      0x04000000 */
#define XBAR_XBARCLR3_SD1FLT2_COMPZ_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR3_SD1FLT2_COMPZ_Pos) & \
     XBAR_XBARCLR3_SD1FLT2_COMPZ_Msk) /*!< SD1FLT2_COMPZ Set Value            */
#define XBAR_XBARCLR3_SD1FLT2_COMPZ_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR3_SD1FLT2_COMPZ_Msk) >> \
     XBAR_XBARCLR3_SD1FLT2_COMPZ_Pos) /*!< SD1FLT2_COMPZ Get Value            */


#define XBAR_XBARCLR3_SD1FLT1_DRINT_Pos (25U) /*!< SD1FLT1_DRINT Postion   25         */
#define XBAR_XBARCLR3_SD1FLT1_DRINT_Msk \
    (0x1U << XBAR_XBARCLR3_SD1FLT1_DRINT_Pos) /*!< SD1FLT1_DRINT Mask      0x02000000 */
#define XBAR_XBARCLR3_SD1FLT1_DRINT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR3_SD1FLT1_DRINT_Pos) & \
     XBAR_XBARCLR3_SD1FLT1_DRINT_Msk) /*!< SD1FLT1_DRINT Set Value            */
#define XBAR_XBARCLR3_SD1FLT1_DRINT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR3_SD1FLT1_DRINT_Msk) >> \
     XBAR_XBARCLR3_SD1FLT1_DRINT_Pos) /*!< SD1FLT1_DRINT Get Value            */


#define XBAR_XBARCLR3_SD1FLT1_COMPZ_Pos (24U) /*!< SD1FLT1_COMPZ Postion   24         */
#define XBAR_XBARCLR3_SD1FLT1_COMPZ_Msk \
    (0x1U << XBAR_XBARCLR3_SD1FLT1_COMPZ_Pos) /*!< SD1FLT1_COMPZ Mask      0x01000000 */
#define XBAR_XBARCLR3_SD1FLT1_COMPZ_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR3_SD1FLT1_COMPZ_Pos) & \
     XBAR_XBARCLR3_SD1FLT1_COMPZ_Msk) /*!< SD1FLT1_COMPZ Set Value            */
#define XBAR_XBARCLR3_SD1FLT1_COMPZ_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR3_SD1FLT1_COMPZ_Msk) >> \
     XBAR_XBARCLR3_SD1FLT1_COMPZ_Pos) /*!< SD1FLT1_COMPZ Get Value            */


#define XBAR_XBARCLR3_ECAP7_OUT_Pos (23U)                                 /*!< ECAP7_OUT Postion   23         */
#define XBAR_XBARCLR3_ECAP7_OUT_Msk (0x1U << XBAR_XBARCLR3_ECAP7_OUT_Pos) /*!< ECAP7_OUT Mask      0x00800000 */
#define XBAR_XBARCLR3_ECAP7_OUT_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR3_ECAP7_OUT_Pos) & XBAR_XBARCLR3_ECAP7_OUT_Msk) /*!< ECAP7_OUT Set Value */
#define XBAR_XBARCLR3_ECAP7_OUT_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR3_ECAP7_OUT_Msk) >> XBAR_XBARCLR3_ECAP7_OUT_Pos) /*!< ECAP7_OUT Get Value */


#define XBAR_XBARCLR3_SD2FLT4_COMPH_Pos (22U) /*!< SD2FLT4_COMPH Postion   22         */
#define XBAR_XBARCLR3_SD2FLT4_COMPH_Msk \
    (0x1U << XBAR_XBARCLR3_SD2FLT4_COMPH_Pos) /*!< SD2FLT4_COMPH Mask      0x00400000 */
#define XBAR_XBARCLR3_SD2FLT4_COMPH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR3_SD2FLT4_COMPH_Pos) & \
     XBAR_XBARCLR3_SD2FLT4_COMPH_Msk) /*!< SD2FLT4_COMPH Set Value            */
#define XBAR_XBARCLR3_SD2FLT4_COMPH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR3_SD2FLT4_COMPH_Msk) >> \
     XBAR_XBARCLR3_SD2FLT4_COMPH_Pos) /*!< SD2FLT4_COMPH Get Value            */


#define XBAR_XBARCLR3_SD2FLT4_COMPL_Pos (21U) /*!< SD2FLT4_COMPL Postion   21         */
#define XBAR_XBARCLR3_SD2FLT4_COMPL_Msk \
    (0x1U << XBAR_XBARCLR3_SD2FLT4_COMPL_Pos) /*!< SD2FLT4_COMPL Mask      0x00200000 */
#define XBAR_XBARCLR3_SD2FLT4_COMPL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR3_SD2FLT4_COMPL_Pos) & \
     XBAR_XBARCLR3_SD2FLT4_COMPL_Msk) /*!< SD2FLT4_COMPL Set Value            */
#define XBAR_XBARCLR3_SD2FLT4_COMPL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR3_SD2FLT4_COMPL_Msk) >> \
     XBAR_XBARCLR3_SD2FLT4_COMPL_Pos) /*!< SD2FLT4_COMPL Get Value            */


#define XBAR_XBARCLR3_SD2FLT3_COMPH_Pos (20U) /*!< SD2FLT3_COMPH Postion   20         */
#define XBAR_XBARCLR3_SD2FLT3_COMPH_Msk \
    (0x1U << XBAR_XBARCLR3_SD2FLT3_COMPH_Pos) /*!< SD2FLT3_COMPH Mask      0x00100000 */
#define XBAR_XBARCLR3_SD2FLT3_COMPH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR3_SD2FLT3_COMPH_Pos) & \
     XBAR_XBARCLR3_SD2FLT3_COMPH_Msk) /*!< SD2FLT3_COMPH Set Value            */
#define XBAR_XBARCLR3_SD2FLT3_COMPH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR3_SD2FLT3_COMPH_Msk) >> \
     XBAR_XBARCLR3_SD2FLT3_COMPH_Pos) /*!< SD2FLT3_COMPH Get Value            */


#define XBAR_XBARCLR3_SD2FLT3_COMPL_Pos (19U) /*!< SD2FLT3_COMPL Postion   19         */
#define XBAR_XBARCLR3_SD2FLT3_COMPL_Msk \
    (0x1U << XBAR_XBARCLR3_SD2FLT3_COMPL_Pos) /*!< SD2FLT3_COMPL Mask      0x00080000 */
#define XBAR_XBARCLR3_SD2FLT3_COMPL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR3_SD2FLT3_COMPL_Pos) & \
     XBAR_XBARCLR3_SD2FLT3_COMPL_Msk) /*!< SD2FLT3_COMPL Set Value            */
#define XBAR_XBARCLR3_SD2FLT3_COMPL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR3_SD2FLT3_COMPL_Msk) >> \
     XBAR_XBARCLR3_SD2FLT3_COMPL_Pos) /*!< SD2FLT3_COMPL Get Value            */


#define XBAR_XBARCLR3_SD2FLT2_COMPH_Pos (18U) /*!< SD2FLT2_COMPH Postion   18         */
#define XBAR_XBARCLR3_SD2FLT2_COMPH_Msk \
    (0x1U << XBAR_XBARCLR3_SD2FLT2_COMPH_Pos) /*!< SD2FLT2_COMPH Mask      0x00040000 */
#define XBAR_XBARCLR3_SD2FLT2_COMPH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR3_SD2FLT2_COMPH_Pos) & \
     XBAR_XBARCLR3_SD2FLT2_COMPH_Msk) /*!< SD2FLT2_COMPH Set Value            */
#define XBAR_XBARCLR3_SD2FLT2_COMPH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR3_SD2FLT2_COMPH_Msk) >> \
     XBAR_XBARCLR3_SD2FLT2_COMPH_Pos) /*!< SD2FLT2_COMPH Get Value            */


#define XBAR_XBARCLR3_SD2FLT2_COMPL_Pos (17U) /*!< SD2FLT2_COMPL Postion   17         */
#define XBAR_XBARCLR3_SD2FLT2_COMPL_Msk \
    (0x1U << XBAR_XBARCLR3_SD2FLT2_COMPL_Pos) /*!< SD2FLT2_COMPL Mask      0x00020000 */
#define XBAR_XBARCLR3_SD2FLT2_COMPL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR3_SD2FLT2_COMPL_Pos) & \
     XBAR_XBARCLR3_SD2FLT2_COMPL_Msk) /*!< SD2FLT2_COMPL Set Value            */
#define XBAR_XBARCLR3_SD2FLT2_COMPL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR3_SD2FLT2_COMPL_Msk) >> \
     XBAR_XBARCLR3_SD2FLT2_COMPL_Pos) /*!< SD2FLT2_COMPL Get Value            */


#define XBAR_XBARCLR3_SD2FLT1_COMPH_Pos (16U) /*!< SD2FLT1_COMPH Postion   16         */
#define XBAR_XBARCLR3_SD2FLT1_COMPH_Msk \
    (0x1U << XBAR_XBARCLR3_SD2FLT1_COMPH_Pos) /*!< SD2FLT1_COMPH Mask      0x00010000 */
#define XBAR_XBARCLR3_SD2FLT1_COMPH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR3_SD2FLT1_COMPH_Pos) & \
     XBAR_XBARCLR3_SD2FLT1_COMPH_Msk) /*!< SD2FLT1_COMPH Set Value            */
#define XBAR_XBARCLR3_SD2FLT1_COMPH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR3_SD2FLT1_COMPH_Msk) >> \
     XBAR_XBARCLR3_SD2FLT1_COMPH_Pos) /*!< SD2FLT1_COMPH Get Value            */


#define XBAR_XBARCLR3_SD2FLT1_COMPL_Pos (15U) /*!< SD2FLT1_COMPL Postion   15         */
#define XBAR_XBARCLR3_SD2FLT1_COMPL_Msk \
    (0x1U << XBAR_XBARCLR3_SD2FLT1_COMPL_Pos) /*!< SD2FLT1_COMPL Mask      0x00008000 */
#define XBAR_XBARCLR3_SD2FLT1_COMPL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR3_SD2FLT1_COMPL_Pos) & \
     XBAR_XBARCLR3_SD2FLT1_COMPL_Msk) /*!< SD2FLT1_COMPL Set Value            */
#define XBAR_XBARCLR3_SD2FLT1_COMPL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR3_SD2FLT1_COMPL_Msk) >> \
     XBAR_XBARCLR3_SD2FLT1_COMPL_Pos) /*!< SD2FLT1_COMPL Get Value            */


#define XBAR_XBARCLR3_SD1FLT4_COMPH_Pos (14U) /*!< SD1FLT4_COMPH Postion   14         */
#define XBAR_XBARCLR3_SD1FLT4_COMPH_Msk \
    (0x1U << XBAR_XBARCLR3_SD1FLT4_COMPH_Pos) /*!< SD1FLT4_COMPH Mask      0x00004000 */
#define XBAR_XBARCLR3_SD1FLT4_COMPH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR3_SD1FLT4_COMPH_Pos) & \
     XBAR_XBARCLR3_SD1FLT4_COMPH_Msk) /*!< SD1FLT4_COMPH Set Value            */
#define XBAR_XBARCLR3_SD1FLT4_COMPH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR3_SD1FLT4_COMPH_Msk) >> \
     XBAR_XBARCLR3_SD1FLT4_COMPH_Pos) /*!< SD1FLT4_COMPH Get Value            */


#define XBAR_XBARCLR3_SD1FLT4_COMPL_Pos (13U) /*!< SD1FLT4_COMPL Postion   13         */
#define XBAR_XBARCLR3_SD1FLT4_COMPL_Msk \
    (0x1U << XBAR_XBARCLR3_SD1FLT4_COMPL_Pos) /*!< SD1FLT4_COMPL Mask      0x00002000 */
#define XBAR_XBARCLR3_SD1FLT4_COMPL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR3_SD1FLT4_COMPL_Pos) & \
     XBAR_XBARCLR3_SD1FLT4_COMPL_Msk) /*!< SD1FLT4_COMPL Set Value            */
#define XBAR_XBARCLR3_SD1FLT4_COMPL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR3_SD1FLT4_COMPL_Msk) >> \
     XBAR_XBARCLR3_SD1FLT4_COMPL_Pos) /*!< SD1FLT4_COMPL Get Value            */


#define XBAR_XBARCLR3_SD1FLT3_COMPH_Pos (12U) /*!< SD1FLT3_COMPH Postion   12         */
#define XBAR_XBARCLR3_SD1FLT3_COMPH_Msk \
    (0x1U << XBAR_XBARCLR3_SD1FLT3_COMPH_Pos) /*!< SD1FLT3_COMPH Mask      0x00001000 */
#define XBAR_XBARCLR3_SD1FLT3_COMPH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR3_SD1FLT3_COMPH_Pos) & \
     XBAR_XBARCLR3_SD1FLT3_COMPH_Msk) /*!< SD1FLT3_COMPH Set Value            */
#define XBAR_XBARCLR3_SD1FLT3_COMPH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR3_SD1FLT3_COMPH_Msk) >> \
     XBAR_XBARCLR3_SD1FLT3_COMPH_Pos) /*!< SD1FLT3_COMPH Get Value            */


#define XBAR_XBARCLR3_SD1FLT3_COMPL_Pos (11U) /*!< SD1FLT3_COMPL Postion   11         */
#define XBAR_XBARCLR3_SD1FLT3_COMPL_Msk \
    (0x1U << XBAR_XBARCLR3_SD1FLT3_COMPL_Pos) /*!< SD1FLT3_COMPL Mask      0x00000800 */
#define XBAR_XBARCLR3_SD1FLT3_COMPL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR3_SD1FLT3_COMPL_Pos) & \
     XBAR_XBARCLR3_SD1FLT3_COMPL_Msk) /*!< SD1FLT3_COMPL Set Value            */
#define XBAR_XBARCLR3_SD1FLT3_COMPL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR3_SD1FLT3_COMPL_Msk) >> \
     XBAR_XBARCLR3_SD1FLT3_COMPL_Pos) /*!< SD1FLT3_COMPL Get Value            */


#define XBAR_XBARCLR3_SD1FLT2_COMPH_Pos (10U) /*!< SD1FLT2_COMPH Postion   10         */
#define XBAR_XBARCLR3_SD1FLT2_COMPH_Msk \
    (0x1U << XBAR_XBARCLR3_SD1FLT2_COMPH_Pos) /*!< SD1FLT2_COMPH Mask      0x00000400 */
#define XBAR_XBARCLR3_SD1FLT2_COMPH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR3_SD1FLT2_COMPH_Pos) & \
     XBAR_XBARCLR3_SD1FLT2_COMPH_Msk) /*!< SD1FLT2_COMPH Set Value            */
#define XBAR_XBARCLR3_SD1FLT2_COMPH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR3_SD1FLT2_COMPH_Msk) >> \
     XBAR_XBARCLR3_SD1FLT2_COMPH_Pos) /*!< SD1FLT2_COMPH Get Value            */


#define XBAR_XBARCLR3_SD1FLT2_COMPL_Pos (9U) /*!< SD1FLT2_COMPL Postion   9          */
#define XBAR_XBARCLR3_SD1FLT2_COMPL_Msk \
    (0x1U << XBAR_XBARCLR3_SD1FLT2_COMPL_Pos) /*!< SD1FLT2_COMPL Mask      0x00000200 */
#define XBAR_XBARCLR3_SD1FLT2_COMPL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR3_SD1FLT2_COMPL_Pos) & \
     XBAR_XBARCLR3_SD1FLT2_COMPL_Msk) /*!< SD1FLT2_COMPL Set Value            */
#define XBAR_XBARCLR3_SD1FLT2_COMPL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR3_SD1FLT2_COMPL_Msk) >> \
     XBAR_XBARCLR3_SD1FLT2_COMPL_Pos) /*!< SD1FLT2_COMPL Get Value            */


#define XBAR_XBARCLR3_SD1FLT1_COMPH_Pos (8U) /*!< SD1FLT1_COMPH Postion   8          */
#define XBAR_XBARCLR3_SD1FLT1_COMPH_Msk \
    (0x1U << XBAR_XBARCLR3_SD1FLT1_COMPH_Pos) /*!< SD1FLT1_COMPH Mask      0x00000100 */
#define XBAR_XBARCLR3_SD1FLT1_COMPH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR3_SD1FLT1_COMPH_Pos) & \
     XBAR_XBARCLR3_SD1FLT1_COMPH_Msk) /*!< SD1FLT1_COMPH Set Value            */
#define XBAR_XBARCLR3_SD1FLT1_COMPH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR3_SD1FLT1_COMPH_Msk) >> \
     XBAR_XBARCLR3_SD1FLT1_COMPH_Pos) /*!< SD1FLT1_COMPH Get Value            */


#define XBAR_XBARCLR3_SD1FLT1_COMPL_Pos (7U) /*!< SD1FLT1_COMPL Postion   7          */
#define XBAR_XBARCLR3_SD1FLT1_COMPL_Msk \
    (0x1U << XBAR_XBARCLR3_SD1FLT1_COMPL_Pos) /*!< SD1FLT1_COMPL Mask      0x00000080 */
#define XBAR_XBARCLR3_SD1FLT1_COMPL_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR3_SD1FLT1_COMPL_Pos) & \
     XBAR_XBARCLR3_SD1FLT1_COMPL_Msk) /*!< SD1FLT1_COMPL Set Value            */
#define XBAR_XBARCLR3_SD1FLT1_COMPL_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR3_SD1FLT1_COMPL_Msk) >> \
     XBAR_XBARCLR3_SD1FLT1_COMPL_Pos) /*!< SD1FLT1_COMPL Get Value            */


#define XBAR_XBARCLR3_ADCDEVT4_Pos (6U)                                 /*!< ADCDEVT4 Postion   6          */
#define XBAR_XBARCLR3_ADCDEVT4_Msk (0x1U << XBAR_XBARCLR3_ADCDEVT4_Pos) /*!< ADCDEVT4 Mask      0x00000040 */
#define XBAR_XBARCLR3_ADCDEVT4_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR3_ADCDEVT4_Pos) & XBAR_XBARCLR3_ADCDEVT4_Msk) /*!< ADCDEVT4 Set Value */
#define XBAR_XBARCLR3_ADCDEVT4_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR3_ADCDEVT4_Msk) >> XBAR_XBARCLR3_ADCDEVT4_Pos) /*!< ADCDEVT4 Get Value            */


#define XBAR_XBARCLR3_ADCDEVT3_Pos (5U)                                 /*!< ADCDEVT3 Postion   5          */
#define XBAR_XBARCLR3_ADCDEVT3_Msk (0x1U << XBAR_XBARCLR3_ADCDEVT3_Pos) /*!< ADCDEVT3 Mask      0x00000020 */
#define XBAR_XBARCLR3_ADCDEVT3_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR3_ADCDEVT3_Pos) & XBAR_XBARCLR3_ADCDEVT3_Msk) /*!< ADCDEVT3 Set Value */
#define XBAR_XBARCLR3_ADCDEVT3_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR3_ADCDEVT3_Msk) >> XBAR_XBARCLR3_ADCDEVT3_Pos) /*!< ADCDEVT3 Get Value            */


#define XBAR_XBARCLR3_ADCDEVT2_Pos (4U)                                 /*!< ADCDEVT2 Postion   4          */
#define XBAR_XBARCLR3_ADCDEVT2_Msk (0x1U << XBAR_XBARCLR3_ADCDEVT2_Pos) /*!< ADCDEVT2 Mask      0x00000010 */
#define XBAR_XBARCLR3_ADCDEVT2_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR3_ADCDEVT2_Pos) & XBAR_XBARCLR3_ADCDEVT2_Msk) /*!< ADCDEVT2 Set Value */
#define XBAR_XBARCLR3_ADCDEVT2_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR3_ADCDEVT2_Msk) >> XBAR_XBARCLR3_ADCDEVT2_Pos) /*!< ADCDEVT2 Get Value            */


#define XBAR_XBARCLR3_ADCDEVT1_Pos (3U)                                 /*!< ADCDEVT1 Postion   3          */
#define XBAR_XBARCLR3_ADCDEVT1_Msk (0x1U << XBAR_XBARCLR3_ADCDEVT1_Pos) /*!< ADCDEVT1 Mask      0x00000008 */
#define XBAR_XBARCLR3_ADCDEVT1_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR3_ADCDEVT1_Pos) & XBAR_XBARCLR3_ADCDEVT1_Msk) /*!< ADCDEVT1 Set Value */
#define XBAR_XBARCLR3_ADCDEVT1_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR3_ADCDEVT1_Msk) >> XBAR_XBARCLR3_ADCDEVT1_Pos) /*!< ADCDEVT1 Get Value            */


#define XBAR_XBARCLR3_ADCCEVT4_Pos (2U)                                 /*!< ADCCEVT4 Postion   2          */
#define XBAR_XBARCLR3_ADCCEVT4_Msk (0x1U << XBAR_XBARCLR3_ADCCEVT4_Pos) /*!< ADCCEVT4 Mask      0x00000004 */
#define XBAR_XBARCLR3_ADCCEVT4_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR3_ADCCEVT4_Pos) & XBAR_XBARCLR3_ADCCEVT4_Msk) /*!< ADCCEVT4 Set Value */
#define XBAR_XBARCLR3_ADCCEVT4_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR3_ADCCEVT4_Msk) >> XBAR_XBARCLR3_ADCCEVT4_Pos) /*!< ADCCEVT4 Get Value            */


#define XBAR_XBARCLR3_ADCCEVT3_Pos (1U)                                 /*!< ADCCEVT3 Postion   1          */
#define XBAR_XBARCLR3_ADCCEVT3_Msk (0x1U << XBAR_XBARCLR3_ADCCEVT3_Pos) /*!< ADCCEVT3 Mask      0x00000002 */
#define XBAR_XBARCLR3_ADCCEVT3_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR3_ADCCEVT3_Pos) & XBAR_XBARCLR3_ADCCEVT3_Msk) /*!< ADCCEVT3 Set Value */
#define XBAR_XBARCLR3_ADCCEVT3_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR3_ADCCEVT3_Msk) >> XBAR_XBARCLR3_ADCCEVT3_Pos) /*!< ADCCEVT3 Get Value            */


#define XBAR_XBARCLR3_ADCCEVT2_Pos (0U)                                 /*!< ADCCEVT2 Postion   0          */
#define XBAR_XBARCLR3_ADCCEVT2_Msk (0x1U << XBAR_XBARCLR3_ADCCEVT2_Pos) /*!< ADCCEVT2 Mask      0x00000001 */
#define XBAR_XBARCLR3_ADCCEVT2_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR3_ADCCEVT2_Pos) & XBAR_XBARCLR3_ADCCEVT2_Msk) /*!< ADCCEVT2 Set Value */
#define XBAR_XBARCLR3_ADCCEVT2_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR3_ADCCEVT2_Msk) >> XBAR_XBARCLR3_ADCCEVT2_Pos) /*!< ADCCEVT2 Get Value            */


/* XBARCLR4 bitfield */
#define XBAR_XBARCLR4_CLAHALT_Pos (31U)                               /*!< CLAHALT Postion   31         */
#define XBAR_XBARCLR4_CLAHALT_Msk (0x1U << XBAR_XBARCLR4_CLAHALT_Pos) /*!< CLAHALT Mask      0x80000000 */
#define XBAR_XBARCLR4_CLAHALT_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR4_CLAHALT_Pos) & XBAR_XBARCLR4_CLAHALT_Msk) /*!< CLAHALT Set Value            */
#define XBAR_XBARCLR4_CLAHALT_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR4_CLAHALT_Msk) >> XBAR_XBARCLR4_CLAHALT_Pos) /*!< CLAHALT Get Value            */


#define XBAR_XBARCLR4_ECATSYNC1_Pos (30U)                                 /*!< ECATSYNC1 Postion   30         */
#define XBAR_XBARCLR4_ECATSYNC1_Msk (0x1U << XBAR_XBARCLR4_ECATSYNC1_Pos) /*!< ECATSYNC1 Mask      0x40000000 */
#define XBAR_XBARCLR4_ECATSYNC1_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR4_ECATSYNC1_Pos) & XBAR_XBARCLR4_ECATSYNC1_Msk) /*!< ECATSYNC1 Set Value */
#define XBAR_XBARCLR4_ECATSYNC1_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR4_ECATSYNC1_Msk) >> XBAR_XBARCLR4_ECATSYNC1_Pos) /*!< ECATSYNC1 Get Value */


#define XBAR_XBARCLR4_ECATSYNC0_Pos (29U)                                 /*!< ECATSYNC0 Postion   29         */
#define XBAR_XBARCLR4_ECATSYNC0_Msk (0x1U << XBAR_XBARCLR4_ECATSYNC0_Pos) /*!< ECATSYNC0 Mask      0x20000000 */
#define XBAR_XBARCLR4_ECATSYNC0_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR4_ECATSYNC0_Pos) & XBAR_XBARCLR4_ECATSYNC0_Msk) /*!< ECATSYNC0 Set Value */
#define XBAR_XBARCLR4_ECATSYNC0_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR4_ECATSYNC0_Msk) >> XBAR_XBARCLR4_ECATSYNC0_Pos) /*!< ECATSYNC0 Get Value */


#define XBAR_XBARCLR4_ERRORSTS_ERROR_Pos (28U) /*!< ERRORSTS_ERROR Postion   28         */
#define XBAR_XBARCLR4_ERRORSTS_ERROR_Msk \
    (0x1U << XBAR_XBARCLR4_ERRORSTS_ERROR_Pos) /*!< ERRORSTS_ERROR Mask      0x10000000 */
#define XBAR_XBARCLR4_ERRORSTS_ERROR_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR4_ERRORSTS_ERROR_Pos) & \
     XBAR_XBARCLR4_ERRORSTS_ERROR_Msk) /*!< ERRORSTS_ERROR Set Value            */
#define XBAR_XBARCLR4_ERRORSTS_ERROR_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR4_ERRORSTS_ERROR_Msk) >> \
     XBAR_XBARCLR4_ERRORSTS_ERROR_Pos) /*!< ERRORSTS_ERROR Get Value            */


#define XBAR_XBARCLR4_CLB6_OUT5_Pos (27U)                                 /*!< CLB6_OUT5 Postion   27         */
#define XBAR_XBARCLR4_CLB6_OUT5_Msk (0x1U << XBAR_XBARCLR4_CLB6_OUT5_Pos) /*!< CLB6_OUT5 Mask      0x08000000 */
#define XBAR_XBARCLR4_CLB6_OUT5_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR4_CLB6_OUT5_Pos) & XBAR_XBARCLR4_CLB6_OUT5_Msk) /*!< CLB6_OUT5 Set Value */
#define XBAR_XBARCLR4_CLB6_OUT5_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR4_CLB6_OUT5_Msk) >> XBAR_XBARCLR4_CLB6_OUT5_Pos) /*!< CLB6_OUT5 Get Value */


#define XBAR_XBARCLR4_CLB6_OUT4_Pos (26U)                                 /*!< CLB6_OUT4 Postion   26         */
#define XBAR_XBARCLR4_CLB6_OUT4_Msk (0x1U << XBAR_XBARCLR4_CLB6_OUT4_Pos) /*!< CLB6_OUT4 Mask      0x04000000 */
#define XBAR_XBARCLR4_CLB6_OUT4_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR4_CLB6_OUT4_Pos) & XBAR_XBARCLR4_CLB6_OUT4_Msk) /*!< CLB6_OUT4 Set Value */
#define XBAR_XBARCLR4_CLB6_OUT4_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR4_CLB6_OUT4_Msk) >> XBAR_XBARCLR4_CLB6_OUT4_Pos) /*!< CLB6_OUT4 Get Value */


#define XBAR_XBARCLR4_CLB5_OUT5_Pos (25U)                                 /*!< CLB5_OUT5 Postion   25         */
#define XBAR_XBARCLR4_CLB5_OUT5_Msk (0x1U << XBAR_XBARCLR4_CLB5_OUT5_Pos) /*!< CLB5_OUT5 Mask      0x02000000 */
#define XBAR_XBARCLR4_CLB5_OUT5_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR4_CLB5_OUT5_Pos) & XBAR_XBARCLR4_CLB5_OUT5_Msk) /*!< CLB5_OUT5 Set Value */
#define XBAR_XBARCLR4_CLB5_OUT5_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR4_CLB5_OUT5_Msk) >> XBAR_XBARCLR4_CLB5_OUT5_Pos) /*!< CLB5_OUT5 Get Value */


#define XBAR_XBARCLR4_CLB5_OUT4_Pos (24U)                                 /*!< CLB5_OUT4 Postion   24         */
#define XBAR_XBARCLR4_CLB5_OUT4_Msk (0x1U << XBAR_XBARCLR4_CLB5_OUT4_Pos) /*!< CLB5_OUT4 Mask      0x01000000 */
#define XBAR_XBARCLR4_CLB5_OUT4_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR4_CLB5_OUT4_Pos) & XBAR_XBARCLR4_CLB5_OUT4_Msk) /*!< CLB5_OUT4 Set Value */
#define XBAR_XBARCLR4_CLB5_OUT4_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR4_CLB5_OUT4_Msk) >> XBAR_XBARCLR4_CLB5_OUT4_Pos) /*!< CLB5_OUT4 Get Value */


#define XBAR_XBARCLR4_CLB4_OUT5_Pos (23U)                                 /*!< CLB4_OUT5 Postion   23         */
#define XBAR_XBARCLR4_CLB4_OUT5_Msk (0x1U << XBAR_XBARCLR4_CLB4_OUT5_Pos) /*!< CLB4_OUT5 Mask      0x00800000 */
#define XBAR_XBARCLR4_CLB4_OUT5_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR4_CLB4_OUT5_Pos) & XBAR_XBARCLR4_CLB4_OUT5_Msk) /*!< CLB4_OUT5 Set Value */
#define XBAR_XBARCLR4_CLB4_OUT5_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR4_CLB4_OUT5_Msk) >> XBAR_XBARCLR4_CLB4_OUT5_Pos) /*!< CLB4_OUT5 Get Value */


#define XBAR_XBARCLR4_CLB4_OUT4_Pos (22U)                                 /*!< CLB4_OUT4 Postion   22         */
#define XBAR_XBARCLR4_CLB4_OUT4_Msk (0x1U << XBAR_XBARCLR4_CLB4_OUT4_Pos) /*!< CLB4_OUT4 Mask      0x00400000 */
#define XBAR_XBARCLR4_CLB4_OUT4_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR4_CLB4_OUT4_Pos) & XBAR_XBARCLR4_CLB4_OUT4_Msk) /*!< CLB4_OUT4 Set Value */
#define XBAR_XBARCLR4_CLB4_OUT4_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR4_CLB4_OUT4_Msk) >> XBAR_XBARCLR4_CLB4_OUT4_Pos) /*!< CLB4_OUT4 Get Value */


#define XBAR_XBARCLR4_CLB3_OUT5_Pos (21U)                                 /*!< CLB3_OUT5 Postion   21         */
#define XBAR_XBARCLR4_CLB3_OUT5_Msk (0x1U << XBAR_XBARCLR4_CLB3_OUT5_Pos) /*!< CLB3_OUT5 Mask      0x00200000 */
#define XBAR_XBARCLR4_CLB3_OUT5_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR4_CLB3_OUT5_Pos) & XBAR_XBARCLR4_CLB3_OUT5_Msk) /*!< CLB3_OUT5 Set Value */
#define XBAR_XBARCLR4_CLB3_OUT5_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR4_CLB3_OUT5_Msk) >> XBAR_XBARCLR4_CLB3_OUT5_Pos) /*!< CLB3_OUT5 Get Value */


#define XBAR_XBARCLR4_CLB3_OUT4_Pos (20U)                                 /*!< CLB3_OUT4 Postion   20         */
#define XBAR_XBARCLR4_CLB3_OUT4_Msk (0x1U << XBAR_XBARCLR4_CLB3_OUT4_Pos) /*!< CLB3_OUT4 Mask      0x00100000 */
#define XBAR_XBARCLR4_CLB3_OUT4_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR4_CLB3_OUT4_Pos) & XBAR_XBARCLR4_CLB3_OUT4_Msk) /*!< CLB3_OUT4 Set Value */
#define XBAR_XBARCLR4_CLB3_OUT4_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR4_CLB3_OUT4_Msk) >> XBAR_XBARCLR4_CLB3_OUT4_Pos) /*!< CLB3_OUT4 Get Value */


#define XBAR_XBARCLR4_CLB2_OUT5_Pos (19U)                                 /*!< CLB2_OUT5 Postion   19         */
#define XBAR_XBARCLR4_CLB2_OUT5_Msk (0x1U << XBAR_XBARCLR4_CLB2_OUT5_Pos) /*!< CLB2_OUT5 Mask      0x00080000 */
#define XBAR_XBARCLR4_CLB2_OUT5_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR4_CLB2_OUT5_Pos) & XBAR_XBARCLR4_CLB2_OUT5_Msk) /*!< CLB2_OUT5 Set Value */
#define XBAR_XBARCLR4_CLB2_OUT5_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR4_CLB2_OUT5_Msk) >> XBAR_XBARCLR4_CLB2_OUT5_Pos) /*!< CLB2_OUT5 Get Value */


#define XBAR_XBARCLR4_CLB2_OUT4_Pos (18U)                                 /*!< CLB2_OUT4 Postion   18         */
#define XBAR_XBARCLR4_CLB2_OUT4_Msk (0x1U << XBAR_XBARCLR4_CLB2_OUT4_Pos) /*!< CLB2_OUT4 Mask      0x00040000 */
#define XBAR_XBARCLR4_CLB2_OUT4_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR4_CLB2_OUT4_Pos) & XBAR_XBARCLR4_CLB2_OUT4_Msk) /*!< CLB2_OUT4 Set Value */
#define XBAR_XBARCLR4_CLB2_OUT4_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR4_CLB2_OUT4_Msk) >> XBAR_XBARCLR4_CLB2_OUT4_Pos) /*!< CLB2_OUT4 Get Value */


#define XBAR_XBARCLR4_CLB1_OUT5_Pos (17U)                                 /*!< CLB1_OUT5 Postion   17         */
#define XBAR_XBARCLR4_CLB1_OUT5_Msk (0x1U << XBAR_XBARCLR4_CLB1_OUT5_Pos) /*!< CLB1_OUT5 Mask      0x00020000 */
#define XBAR_XBARCLR4_CLB1_OUT5_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR4_CLB1_OUT5_Pos) & XBAR_XBARCLR4_CLB1_OUT5_Msk) /*!< CLB1_OUT5 Set Value */
#define XBAR_XBARCLR4_CLB1_OUT5_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR4_CLB1_OUT5_Msk) >> XBAR_XBARCLR4_CLB1_OUT5_Pos) /*!< CLB1_OUT5 Get Value */


#define XBAR_XBARCLR4_CLB1_OUT4_Pos (16U)                                 /*!< CLB1_OUT4 Postion   16         */
#define XBAR_XBARCLR4_CLB1_OUT4_Msk (0x1U << XBAR_XBARCLR4_CLB1_OUT4_Pos) /*!< CLB1_OUT4 Mask      0x00010000 */
#define XBAR_XBARCLR4_CLB1_OUT4_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR4_CLB1_OUT4_Pos) & XBAR_XBARCLR4_CLB1_OUT4_Msk) /*!< CLB1_OUT4 Set Value */
#define XBAR_XBARCLR4_CLB1_OUT4_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR4_CLB1_OUT4_Msk) >> XBAR_XBARCLR4_CLB1_OUT4_Pos) /*!< CLB1_OUT4 Get Value */


#define XBAR_XBARCLR4_CLB8_OUT5_Pos (15U)                                 /*!< CLB8_OUT5 Postion   15         */
#define XBAR_XBARCLR4_CLB8_OUT5_Msk (0x1U << XBAR_XBARCLR4_CLB8_OUT5_Pos) /*!< CLB8_OUT5 Mask      0x00008000 */
#define XBAR_XBARCLR4_CLB8_OUT5_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR4_CLB8_OUT5_Pos) & XBAR_XBARCLR4_CLB8_OUT5_Msk) /*!< CLB8_OUT5 Set Value */
#define XBAR_XBARCLR4_CLB8_OUT5_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR4_CLB8_OUT5_Msk) >> XBAR_XBARCLR4_CLB8_OUT5_Pos) /*!< CLB8_OUT5 Get Value */


#define XBAR_XBARCLR4_CLB8_OUT4_Pos (14U)                                 /*!< CLB8_OUT4 Postion   14         */
#define XBAR_XBARCLR4_CLB8_OUT4_Msk (0x1U << XBAR_XBARCLR4_CLB8_OUT4_Pos) /*!< CLB8_OUT4 Mask      0x00004000 */
#define XBAR_XBARCLR4_CLB8_OUT4_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR4_CLB8_OUT4_Pos) & XBAR_XBARCLR4_CLB8_OUT4_Msk) /*!< CLB8_OUT4 Set Value */
#define XBAR_XBARCLR4_CLB8_OUT4_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR4_CLB8_OUT4_Msk) >> XBAR_XBARCLR4_CLB8_OUT4_Pos) /*!< CLB8_OUT4 Get Value */


#define XBAR_XBARCLR4_CLB7_OUT5_Pos (13U)                                 /*!< CLB7_OUT5 Postion   13         */
#define XBAR_XBARCLR4_CLB7_OUT5_Msk (0x1U << XBAR_XBARCLR4_CLB7_OUT5_Pos) /*!< CLB7_OUT5 Mask      0x00002000 */
#define XBAR_XBARCLR4_CLB7_OUT5_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR4_CLB7_OUT5_Pos) & XBAR_XBARCLR4_CLB7_OUT5_Msk) /*!< CLB7_OUT5 Set Value */
#define XBAR_XBARCLR4_CLB7_OUT5_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR4_CLB7_OUT5_Msk) >> XBAR_XBARCLR4_CLB7_OUT5_Pos) /*!< CLB7_OUT5 Get Value */


#define XBAR_XBARCLR4_CLB7_OUT4_Pos (12U)                                 /*!< CLB7_OUT4 Postion   12         */
#define XBAR_XBARCLR4_CLB7_OUT4_Msk (0x1U << XBAR_XBARCLR4_CLB7_OUT4_Pos) /*!< CLB7_OUT4 Mask      0x00001000 */
#define XBAR_XBARCLR4_CLB7_OUT4_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR4_CLB7_OUT4_Pos) & XBAR_XBARCLR4_CLB7_OUT4_Msk) /*!< CLB7_OUT4 Set Value */
#define XBAR_XBARCLR4_CLB7_OUT4_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR4_CLB7_OUT4_Msk) >> XBAR_XBARCLR4_CLB7_OUT4_Pos) /*!< CLB7_OUT4 Get Value */


#define XBAR_XBARCLR4_MCANA_FEVT2_Pos (11U)                                   /*!< MCANA_FEVT2 Postion   11         */
#define XBAR_XBARCLR4_MCANA_FEVT2_Msk (0x1U << XBAR_XBARCLR4_MCANA_FEVT2_Pos) /*!< MCANA_FEVT2 Mask      0x00000800 */
#define XBAR_XBARCLR4_MCANA_FEVT2_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR4_MCANA_FEVT2_Pos) & XBAR_XBARCLR4_MCANA_FEVT2_Msk) /*!< MCANA_FEVT2 Set Value */
#define XBAR_XBARCLR4_MCANA_FEVT2_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR4_MCANA_FEVT2_Msk) >> XBAR_XBARCLR4_MCANA_FEVT2_Pos) /*!< MCANA_FEVT2 Get Value */


#define XBAR_XBARCLR4_MCANA_FEVT1_Pos (10U)                                   /*!< MCANA_FEVT1 Postion   10         */
#define XBAR_XBARCLR4_MCANA_FEVT1_Msk (0x1U << XBAR_XBARCLR4_MCANA_FEVT1_Pos) /*!< MCANA_FEVT1 Mask      0x00000400 */
#define XBAR_XBARCLR4_MCANA_FEVT1_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR4_MCANA_FEVT1_Pos) & XBAR_XBARCLR4_MCANA_FEVT1_Msk) /*!< MCANA_FEVT1 Set Value */
#define XBAR_XBARCLR4_MCANA_FEVT1_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR4_MCANA_FEVT1_Msk) >> XBAR_XBARCLR4_MCANA_FEVT1_Pos) /*!< MCANA_FEVT1 Get Value */


#define XBAR_XBARCLR4_MCANA_FEVT0_Pos (9U)                                    /*!< MCANA_FEVT0 Postion   9          */
#define XBAR_XBARCLR4_MCANA_FEVT0_Msk (0x1U << XBAR_XBARCLR4_MCANA_FEVT0_Pos) /*!< MCANA_FEVT0 Mask      0x00000200 */
#define XBAR_XBARCLR4_MCANA_FEVT0_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR4_MCANA_FEVT0_Pos) & XBAR_XBARCLR4_MCANA_FEVT0_Msk) /*!< MCANA_FEVT0 Set Value */
#define XBAR_XBARCLR4_MCANA_FEVT0_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR4_MCANA_FEVT0_Msk) >> XBAR_XBARCLR4_MCANA_FEVT0_Pos) /*!< MCANA_FEVT0 Get Value */


#define XBAR_XBARCLR4_EMAC_PPS0_Pos (8U)                                  /*!< EMAC_PPS0 Postion   8          */
#define XBAR_XBARCLR4_EMAC_PPS0_Msk (0x1U << XBAR_XBARCLR4_EMAC_PPS0_Pos) /*!< EMAC_PPS0 Mask      0x00000100 */
#define XBAR_XBARCLR4_EMAC_PPS0_Set(x) \
    (((uint32_t) (x) << XBAR_XBARCLR4_EMAC_PPS0_Pos) & XBAR_XBARCLR4_EMAC_PPS0_Msk) /*!< EMAC_PPS0 Set Value */
#define XBAR_XBARCLR4_EMAC_PPS0_Get(x) \
    (((uint32_t) (x) &XBAR_XBARCLR4_EMAC_PPS0_Msk) >> XBAR_XBARCLR4_EMAC_PPS0_Pos) /*!< EMAC_PPS0 Get Value */


#define XBAR_XBARCLR4_SD2FLT4_DRINT_Pos (7U) /*!< SD2FLT4_DRINT Postion   7          */
#define XBAR_XBARCLR4_SD2FLT4_DRINT_Msk \
    (0x1U << XBAR_XBARCLR4_SD2FLT4_DRINT_Pos) /*!< SD2FLT4_DRINT Mask      0x00000080 */
#define XBAR_XBARCLR4_SD2FLT4_DRINT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR4_SD2FLT4_DRINT_Pos) & \
     XBAR_XBARCLR4_SD2FLT4_DRINT_Msk) /*!< SD2FLT4_DRINT Set Value            */
#define XBAR_XBARCLR4_SD2FLT4_DRINT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR4_SD2FLT4_DRINT_Msk) >> \
     XBAR_XBARCLR4_SD2FLT4_DRINT_Pos) /*!< SD2FLT4_DRINT Get Value            */


#define XBAR_XBARCLR4_SD2FLT4_COMPZ_Pos (6U) /*!< SD2FLT4_COMPZ Postion   6          */
#define XBAR_XBARCLR4_SD2FLT4_COMPZ_Msk \
    (0x1U << XBAR_XBARCLR4_SD2FLT4_COMPZ_Pos) /*!< SD2FLT4_COMPZ Mask      0x00000040 */
#define XBAR_XBARCLR4_SD2FLT4_COMPZ_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR4_SD2FLT4_COMPZ_Pos) & \
     XBAR_XBARCLR4_SD2FLT4_COMPZ_Msk) /*!< SD2FLT4_COMPZ Set Value            */
#define XBAR_XBARCLR4_SD2FLT4_COMPZ_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR4_SD2FLT4_COMPZ_Msk) >> \
     XBAR_XBARCLR4_SD2FLT4_COMPZ_Pos) /*!< SD2FLT4_COMPZ Get Value            */


#define XBAR_XBARCLR4_SD2FLT3_DRINT_Pos (5U) /*!< SD2FLT3_DRINT Postion   5          */
#define XBAR_XBARCLR4_SD2FLT3_DRINT_Msk \
    (0x1U << XBAR_XBARCLR4_SD2FLT3_DRINT_Pos) /*!< SD2FLT3_DRINT Mask      0x00000020 */
#define XBAR_XBARCLR4_SD2FLT3_DRINT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR4_SD2FLT3_DRINT_Pos) & \
     XBAR_XBARCLR4_SD2FLT3_DRINT_Msk) /*!< SD2FLT3_DRINT Set Value            */
#define XBAR_XBARCLR4_SD2FLT3_DRINT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR4_SD2FLT3_DRINT_Msk) >> \
     XBAR_XBARCLR4_SD2FLT3_DRINT_Pos) /*!< SD2FLT3_DRINT Get Value            */


#define XBAR_XBARCLR4_SD2FLT3_COMPZ_Pos (4U) /*!< SD2FLT3_COMPZ Postion   4          */
#define XBAR_XBARCLR4_SD2FLT3_COMPZ_Msk \
    (0x1U << XBAR_XBARCLR4_SD2FLT3_COMPZ_Pos) /*!< SD2FLT3_COMPZ Mask      0x00000010 */
#define XBAR_XBARCLR4_SD2FLT3_COMPZ_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR4_SD2FLT3_COMPZ_Pos) & \
     XBAR_XBARCLR4_SD2FLT3_COMPZ_Msk) /*!< SD2FLT3_COMPZ Set Value            */
#define XBAR_XBARCLR4_SD2FLT3_COMPZ_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR4_SD2FLT3_COMPZ_Msk) >> \
     XBAR_XBARCLR4_SD2FLT3_COMPZ_Pos) /*!< SD2FLT3_COMPZ Get Value            */


#define XBAR_XBARCLR4_SD2FLT2_DRINT_Pos (3U) /*!< SD2FLT2_DRINT Postion   3          */
#define XBAR_XBARCLR4_SD2FLT2_DRINT_Msk \
    (0x1U << XBAR_XBARCLR4_SD2FLT2_DRINT_Pos) /*!< SD2FLT2_DRINT Mask      0x00000008 */
#define XBAR_XBARCLR4_SD2FLT2_DRINT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR4_SD2FLT2_DRINT_Pos) & \
     XBAR_XBARCLR4_SD2FLT2_DRINT_Msk) /*!< SD2FLT2_DRINT Set Value            */
#define XBAR_XBARCLR4_SD2FLT2_DRINT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR4_SD2FLT2_DRINT_Msk) >> \
     XBAR_XBARCLR4_SD2FLT2_DRINT_Pos) /*!< SD2FLT2_DRINT Get Value            */


#define XBAR_XBARCLR4_SD2FLT2_COMPZ_Pos (2U) /*!< SD2FLT2_COMPZ Postion   2          */
#define XBAR_XBARCLR4_SD2FLT2_COMPZ_Msk \
    (0x1U << XBAR_XBARCLR4_SD2FLT2_COMPZ_Pos) /*!< SD2FLT2_COMPZ Mask      0x00000004 */
#define XBAR_XBARCLR4_SD2FLT2_COMPZ_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR4_SD2FLT2_COMPZ_Pos) & \
     XBAR_XBARCLR4_SD2FLT2_COMPZ_Msk) /*!< SD2FLT2_COMPZ Set Value            */
#define XBAR_XBARCLR4_SD2FLT2_COMPZ_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR4_SD2FLT2_COMPZ_Msk) >> \
     XBAR_XBARCLR4_SD2FLT2_COMPZ_Pos) /*!< SD2FLT2_COMPZ Get Value            */


#define XBAR_XBARCLR4_SD2FLT1_DRINT_Pos (1U) /*!< SD2FLT1_DRINT Postion   1          */
#define XBAR_XBARCLR4_SD2FLT1_DRINT_Msk \
    (0x1U << XBAR_XBARCLR4_SD2FLT1_DRINT_Pos) /*!< SD2FLT1_DRINT Mask      0x00000002 */
#define XBAR_XBARCLR4_SD2FLT1_DRINT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR4_SD2FLT1_DRINT_Pos) & \
     XBAR_XBARCLR4_SD2FLT1_DRINT_Msk) /*!< SD2FLT1_DRINT Set Value            */
#define XBAR_XBARCLR4_SD2FLT1_DRINT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR4_SD2FLT1_DRINT_Msk) >> \
     XBAR_XBARCLR4_SD2FLT1_DRINT_Pos) /*!< SD2FLT1_DRINT Get Value            */


#define XBAR_XBARCLR4_SD2FLT1_COMPZ_Pos (0U) /*!< SD2FLT1_COMPZ Postion   0          */
#define XBAR_XBARCLR4_SD2FLT1_COMPZ_Msk \
    (0x1U << XBAR_XBARCLR4_SD2FLT1_COMPZ_Pos) /*!< SD2FLT1_COMPZ Mask      0x00000001 */
#define XBAR_XBARCLR4_SD2FLT1_COMPZ_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR4_SD2FLT1_COMPZ_Pos) & \
     XBAR_XBARCLR4_SD2FLT1_COMPZ_Msk) /*!< SD2FLT1_COMPZ Set Value            */
#define XBAR_XBARCLR4_SD2FLT1_COMPZ_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR4_SD2FLT1_COMPZ_Msk) >> \
     XBAR_XBARCLR4_SD2FLT1_COMPZ_Pos) /*!< SD2FLT1_COMPZ Get Value            */


/* XBARFLG5 bitfield */
#define XBAR_XBARFLG5_SD2FLT4_CEVT1OUT_Pos (31U) /*!< SD2FLT4_CEVT1OUT Postion   31         */
#define XBAR_XBARFLG5_SD2FLT4_CEVT1OUT_Msk \
    (0x1U << XBAR_XBARFLG5_SD2FLT4_CEVT1OUT_Pos) /*!< SD2FLT4_CEVT1OUT Mask      0x80000000 */
#define XBAR_XBARFLG5_SD2FLT4_CEVT1OUT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG5_SD2FLT4_CEVT1OUT_Pos) & \
     XBAR_XBARFLG5_SD2FLT4_CEVT1OUT_Msk) /*!< SD2FLT4_CEVT1OUT Set Value            */
#define XBAR_XBARFLG5_SD2FLT4_CEVT1OUT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG5_SD2FLT4_CEVT1OUT_Msk) >> \
     XBAR_XBARFLG5_SD2FLT4_CEVT1OUT_Pos) /*!< SD2FLT4_CEVT1OUT Get Value            */


#define XBAR_XBARFLG5_SD2FLT4_CEVT2OUT_Pos (30U) /*!< SD2FLT4_CEVT2OUT Postion   30         */
#define XBAR_XBARFLG5_SD2FLT4_CEVT2OUT_Msk \
    (0x1U << XBAR_XBARFLG5_SD2FLT4_CEVT2OUT_Pos) /*!< SD2FLT4_CEVT2OUT Mask      0x40000000 */
#define XBAR_XBARFLG5_SD2FLT4_CEVT2OUT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG5_SD2FLT4_CEVT2OUT_Pos) & \
     XBAR_XBARFLG5_SD2FLT4_CEVT2OUT_Msk) /*!< SD2FLT4_CEVT2OUT Set Value            */
#define XBAR_XBARFLG5_SD2FLT4_CEVT2OUT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG5_SD2FLT4_CEVT2OUT_Msk) >> \
     XBAR_XBARFLG5_SD2FLT4_CEVT2OUT_Pos) /*!< SD2FLT4_CEVT2OUT Get Value            */


#define XBAR_XBARFLG5_SD2FLT3_CEVT1OUT_Pos (29U) /*!< SD2FLT3_CEVT1OUT Postion   29         */
#define XBAR_XBARFLG5_SD2FLT3_CEVT1OUT_Msk \
    (0x1U << XBAR_XBARFLG5_SD2FLT3_CEVT1OUT_Pos) /*!< SD2FLT3_CEVT1OUT Mask      0x20000000 */
#define XBAR_XBARFLG5_SD2FLT3_CEVT1OUT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG5_SD2FLT3_CEVT1OUT_Pos) & \
     XBAR_XBARFLG5_SD2FLT3_CEVT1OUT_Msk) /*!< SD2FLT3_CEVT1OUT Set Value            */
#define XBAR_XBARFLG5_SD2FLT3_CEVT1OUT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG5_SD2FLT3_CEVT1OUT_Msk) >> \
     XBAR_XBARFLG5_SD2FLT3_CEVT1OUT_Pos) /*!< SD2FLT3_CEVT1OUT Get Value            */


#define XBAR_XBARFLG5_SD2FLT3_CEVT2OUT_Pos (28U) /*!< SD2FLT3_CEVT2OUT Postion   28         */
#define XBAR_XBARFLG5_SD2FLT3_CEVT2OUT_Msk \
    (0x1U << XBAR_XBARFLG5_SD2FLT3_CEVT2OUT_Pos) /*!< SD2FLT3_CEVT2OUT Mask      0x10000000 */
#define XBAR_XBARFLG5_SD2FLT3_CEVT2OUT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG5_SD2FLT3_CEVT2OUT_Pos) & \
     XBAR_XBARFLG5_SD2FLT3_CEVT2OUT_Msk) /*!< SD2FLT3_CEVT2OUT Set Value            */
#define XBAR_XBARFLG5_SD2FLT3_CEVT2OUT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG5_SD2FLT3_CEVT2OUT_Msk) >> \
     XBAR_XBARFLG5_SD2FLT3_CEVT2OUT_Pos) /*!< SD2FLT3_CEVT2OUT Get Value            */


#define XBAR_XBARFLG5_SD2FLT2_CEVT1OUT_Pos (27U) /*!< SD2FLT2_CEVT1OUT Postion   27         */
#define XBAR_XBARFLG5_SD2FLT2_CEVT1OUT_Msk \
    (0x1U << XBAR_XBARFLG5_SD2FLT2_CEVT1OUT_Pos) /*!< SD2FLT2_CEVT1OUT Mask      0x08000000 */
#define XBAR_XBARFLG5_SD2FLT2_CEVT1OUT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG5_SD2FLT2_CEVT1OUT_Pos) & \
     XBAR_XBARFLG5_SD2FLT2_CEVT1OUT_Msk) /*!< SD2FLT2_CEVT1OUT Set Value            */
#define XBAR_XBARFLG5_SD2FLT2_CEVT1OUT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG5_SD2FLT2_CEVT1OUT_Msk) >> \
     XBAR_XBARFLG5_SD2FLT2_CEVT1OUT_Pos) /*!< SD2FLT2_CEVT1OUT Get Value            */


#define XBAR_XBARFLG5_SD2FLT2_CEVT2OUT_Pos (26U) /*!< SD2FLT2_CEVT2OUT Postion   26         */
#define XBAR_XBARFLG5_SD2FLT2_CEVT2OUT_Msk \
    (0x1U << XBAR_XBARFLG5_SD2FLT2_CEVT2OUT_Pos) /*!< SD2FLT2_CEVT2OUT Mask      0x04000000 */
#define XBAR_XBARFLG5_SD2FLT2_CEVT2OUT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG5_SD2FLT2_CEVT2OUT_Pos) & \
     XBAR_XBARFLG5_SD2FLT2_CEVT2OUT_Msk) /*!< SD2FLT2_CEVT2OUT Set Value            */
#define XBAR_XBARFLG5_SD2FLT2_CEVT2OUT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG5_SD2FLT2_CEVT2OUT_Msk) >> \
     XBAR_XBARFLG5_SD2FLT2_CEVT2OUT_Pos) /*!< SD2FLT2_CEVT2OUT Get Value            */


#define XBAR_XBARFLG5_SD2FLT1_CEVT1OUT_Pos (25U) /*!< SD2FLT1_CEVT1OUT Postion   25         */
#define XBAR_XBARFLG5_SD2FLT1_CEVT1OUT_Msk \
    (0x1U << XBAR_XBARFLG5_SD2FLT1_CEVT1OUT_Pos) /*!< SD2FLT1_CEVT1OUT Mask      0x02000000 */
#define XBAR_XBARFLG5_SD2FLT1_CEVT1OUT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG5_SD2FLT1_CEVT1OUT_Pos) & \
     XBAR_XBARFLG5_SD2FLT1_CEVT1OUT_Msk) /*!< SD2FLT1_CEVT1OUT Set Value            */
#define XBAR_XBARFLG5_SD2FLT1_CEVT1OUT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG5_SD2FLT1_CEVT1OUT_Msk) >> \
     XBAR_XBARFLG5_SD2FLT1_CEVT1OUT_Pos) /*!< SD2FLT1_CEVT1OUT Get Value            */


#define XBAR_XBARFLG5_SD2FLT1_CEVT2OUT_Pos (24U) /*!< SD2FLT1_CEVT2OUT Postion   24         */
#define XBAR_XBARFLG5_SD2FLT1_CEVT2OUT_Msk \
    (0x1U << XBAR_XBARFLG5_SD2FLT1_CEVT2OUT_Pos) /*!< SD2FLT1_CEVT2OUT Mask      0x01000000 */
#define XBAR_XBARFLG5_SD2FLT1_CEVT2OUT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG5_SD2FLT1_CEVT2OUT_Pos) & \
     XBAR_XBARFLG5_SD2FLT1_CEVT2OUT_Msk) /*!< SD2FLT1_CEVT2OUT Set Value            */
#define XBAR_XBARFLG5_SD2FLT1_CEVT2OUT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG5_SD2FLT1_CEVT2OUT_Msk) >> \
     XBAR_XBARFLG5_SD2FLT1_CEVT2OUT_Pos) /*!< SD2FLT1_CEVT2OUT Get Value            */


#define XBAR_XBARFLG5_SD1FLT4_CEVT1OUT_Pos (23U) /*!< SD1FLT4_CEVT1OUT Postion   23         */
#define XBAR_XBARFLG5_SD1FLT4_CEVT1OUT_Msk \
    (0x1U << XBAR_XBARFLG5_SD1FLT4_CEVT1OUT_Pos) /*!< SD1FLT4_CEVT1OUT Mask      0x00800000 */
#define XBAR_XBARFLG5_SD1FLT4_CEVT1OUT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG5_SD1FLT4_CEVT1OUT_Pos) & \
     XBAR_XBARFLG5_SD1FLT4_CEVT1OUT_Msk) /*!< SD1FLT4_CEVT1OUT Set Value            */
#define XBAR_XBARFLG5_SD1FLT4_CEVT1OUT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG5_SD1FLT4_CEVT1OUT_Msk) >> \
     XBAR_XBARFLG5_SD1FLT4_CEVT1OUT_Pos) /*!< SD1FLT4_CEVT1OUT Get Value            */


#define XBAR_XBARFLG5_SD1FLT4_CEVT2OUT_Pos (22U) /*!< SD1FLT4_CEVT2OUT Postion   22         */
#define XBAR_XBARFLG5_SD1FLT4_CEVT2OUT_Msk \
    (0x1U << XBAR_XBARFLG5_SD1FLT4_CEVT2OUT_Pos) /*!< SD1FLT4_CEVT2OUT Mask      0x00400000 */
#define XBAR_XBARFLG5_SD1FLT4_CEVT2OUT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG5_SD1FLT4_CEVT2OUT_Pos) & \
     XBAR_XBARFLG5_SD1FLT4_CEVT2OUT_Msk) /*!< SD1FLT4_CEVT2OUT Set Value            */
#define XBAR_XBARFLG5_SD1FLT4_CEVT2OUT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG5_SD1FLT4_CEVT2OUT_Msk) >> \
     XBAR_XBARFLG5_SD1FLT4_CEVT2OUT_Pos) /*!< SD1FLT4_CEVT2OUT Get Value            */


#define XBAR_XBARFLG5_SD1FLT3_CEVT1OUT_Pos (21U) /*!< SD1FLT3_CEVT1OUT Postion   21         */
#define XBAR_XBARFLG5_SD1FLT3_CEVT1OUT_Msk \
    (0x1U << XBAR_XBARFLG5_SD1FLT3_CEVT1OUT_Pos) /*!< SD1FLT3_CEVT1OUT Mask      0x00200000 */
#define XBAR_XBARFLG5_SD1FLT3_CEVT1OUT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG5_SD1FLT3_CEVT1OUT_Pos) & \
     XBAR_XBARFLG5_SD1FLT3_CEVT1OUT_Msk) /*!< SD1FLT3_CEVT1OUT Set Value            */
#define XBAR_XBARFLG5_SD1FLT3_CEVT1OUT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG5_SD1FLT3_CEVT1OUT_Msk) >> \
     XBAR_XBARFLG5_SD1FLT3_CEVT1OUT_Pos) /*!< SD1FLT3_CEVT1OUT Get Value            */


#define XBAR_XBARFLG5_SD1FLT3_CEVT2OUT_Pos (20U) /*!< SD1FLT3_CEVT2OUT Postion   20         */
#define XBAR_XBARFLG5_SD1FLT3_CEVT2OUT_Msk \
    (0x1U << XBAR_XBARFLG5_SD1FLT3_CEVT2OUT_Pos) /*!< SD1FLT3_CEVT2OUT Mask      0x00100000 */
#define XBAR_XBARFLG5_SD1FLT3_CEVT2OUT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG5_SD1FLT3_CEVT2OUT_Pos) & \
     XBAR_XBARFLG5_SD1FLT3_CEVT2OUT_Msk) /*!< SD1FLT3_CEVT2OUT Set Value            */
#define XBAR_XBARFLG5_SD1FLT3_CEVT2OUT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG5_SD1FLT3_CEVT2OUT_Msk) >> \
     XBAR_XBARFLG5_SD1FLT3_CEVT2OUT_Pos) /*!< SD1FLT3_CEVT2OUT Get Value            */


#define XBAR_XBARFLG5_SD1FLT2_CEVT1OUT_Pos (19U) /*!< SD1FLT2_CEVT1OUT Postion   19         */
#define XBAR_XBARFLG5_SD1FLT2_CEVT1OUT_Msk \
    (0x1U << XBAR_XBARFLG5_SD1FLT2_CEVT1OUT_Pos) /*!< SD1FLT2_CEVT1OUT Mask      0x00080000 */
#define XBAR_XBARFLG5_SD1FLT2_CEVT1OUT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG5_SD1FLT2_CEVT1OUT_Pos) & \
     XBAR_XBARFLG5_SD1FLT2_CEVT1OUT_Msk) /*!< SD1FLT2_CEVT1OUT Set Value            */
#define XBAR_XBARFLG5_SD1FLT2_CEVT1OUT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG5_SD1FLT2_CEVT1OUT_Msk) >> \
     XBAR_XBARFLG5_SD1FLT2_CEVT1OUT_Pos) /*!< SD1FLT2_CEVT1OUT Get Value            */


#define XBAR_XBARFLG5_SD1FLT2_CEVT2OUT_Pos (18U) /*!< SD1FLT2_CEVT2OUT Postion   18         */
#define XBAR_XBARFLG5_SD1FLT2_CEVT2OUT_Msk \
    (0x1U << XBAR_XBARFLG5_SD1FLT2_CEVT2OUT_Pos) /*!< SD1FLT2_CEVT2OUT Mask      0x00040000 */
#define XBAR_XBARFLG5_SD1FLT2_CEVT2OUT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG5_SD1FLT2_CEVT2OUT_Pos) & \
     XBAR_XBARFLG5_SD1FLT2_CEVT2OUT_Msk) /*!< SD1FLT2_CEVT2OUT Set Value            */
#define XBAR_XBARFLG5_SD1FLT2_CEVT2OUT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG5_SD1FLT2_CEVT2OUT_Msk) >> \
     XBAR_XBARFLG5_SD1FLT2_CEVT2OUT_Pos) /*!< SD1FLT2_CEVT2OUT Get Value            */


#define XBAR_XBARFLG5_SD1FLT1_CEVT1OUT_Pos (17U) /*!< SD1FLT1_CEVT1OUT Postion   17         */
#define XBAR_XBARFLG5_SD1FLT1_CEVT1OUT_Msk \
    (0x1U << XBAR_XBARFLG5_SD1FLT1_CEVT1OUT_Pos) /*!< SD1FLT1_CEVT1OUT Mask      0x00020000 */
#define XBAR_XBARFLG5_SD1FLT1_CEVT1OUT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG5_SD1FLT1_CEVT1OUT_Pos) & \
     XBAR_XBARFLG5_SD1FLT1_CEVT1OUT_Msk) /*!< SD1FLT1_CEVT1OUT Set Value            */
#define XBAR_XBARFLG5_SD1FLT1_CEVT1OUT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG5_SD1FLT1_CEVT1OUT_Msk) >> \
     XBAR_XBARFLG5_SD1FLT1_CEVT1OUT_Pos) /*!< SD1FLT1_CEVT1OUT Get Value            */


#define XBAR_XBARFLG5_SD1FLT1_CEVT2OUT_Pos (16U) /*!< SD1FLT1_CEVT2OUT Postion   16         */
#define XBAR_XBARFLG5_SD1FLT1_CEVT2OUT_Msk \
    (0x1U << XBAR_XBARFLG5_SD1FLT1_CEVT2OUT_Pos) /*!< SD1FLT1_CEVT2OUT Mask      0x00010000 */
#define XBAR_XBARFLG5_SD1FLT1_CEVT2OUT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG5_SD1FLT1_CEVT2OUT_Pos) & \
     XBAR_XBARFLG5_SD1FLT1_CEVT2OUT_Msk) /*!< SD1FLT1_CEVT2OUT Set Value            */
#define XBAR_XBARFLG5_SD1FLT1_CEVT2OUT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG5_SD1FLT1_CEVT2OUT_Msk) >> \
     XBAR_XBARFLG5_SD1FLT1_CEVT2OUT_Pos) /*!< SD1FLT1_CEVT2OUT Get Value            */


#define XBAR_XBARFLG5_SD2FLT4_COMPH2_Pos (15U) /*!< SD2FLT4_COMPH2 Postion   15         */
#define XBAR_XBARFLG5_SD2FLT4_COMPH2_Msk \
    (0x1U << XBAR_XBARFLG5_SD2FLT4_COMPH2_Pos) /*!< SD2FLT4_COMPH2 Mask      0x00008000 */
#define XBAR_XBARFLG5_SD2FLT4_COMPH2_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG5_SD2FLT4_COMPH2_Pos) & \
     XBAR_XBARFLG5_SD2FLT4_COMPH2_Msk) /*!< SD2FLT4_COMPH2 Set Value            */
#define XBAR_XBARFLG5_SD2FLT4_COMPH2_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG5_SD2FLT4_COMPH2_Msk) >> \
     XBAR_XBARFLG5_SD2FLT4_COMPH2_Pos) /*!< SD2FLT4_COMPH2 Get Value            */


#define XBAR_XBARFLG5_SD2FLT4_COMPL2_Pos (14U) /*!< SD2FLT4_COMPL2 Postion   14         */
#define XBAR_XBARFLG5_SD2FLT4_COMPL2_Msk \
    (0x1U << XBAR_XBARFLG5_SD2FLT4_COMPL2_Pos) /*!< SD2FLT4_COMPL2 Mask      0x00004000 */
#define XBAR_XBARFLG5_SD2FLT4_COMPL2_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG5_SD2FLT4_COMPL2_Pos) & \
     XBAR_XBARFLG5_SD2FLT4_COMPL2_Msk) /*!< SD2FLT4_COMPL2 Set Value            */
#define XBAR_XBARFLG5_SD2FLT4_COMPL2_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG5_SD2FLT4_COMPL2_Msk) >> \
     XBAR_XBARFLG5_SD2FLT4_COMPL2_Pos) /*!< SD2FLT4_COMPL2 Get Value            */


#define XBAR_XBARFLG5_SD2FLT3_COMPH2_Pos (13U) /*!< SD2FLT3_COMPH2 Postion   13         */
#define XBAR_XBARFLG5_SD2FLT3_COMPH2_Msk \
    (0x1U << XBAR_XBARFLG5_SD2FLT3_COMPH2_Pos) /*!< SD2FLT3_COMPH2 Mask      0x00002000 */
#define XBAR_XBARFLG5_SD2FLT3_COMPH2_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG5_SD2FLT3_COMPH2_Pos) & \
     XBAR_XBARFLG5_SD2FLT3_COMPH2_Msk) /*!< SD2FLT3_COMPH2 Set Value            */
#define XBAR_XBARFLG5_SD2FLT3_COMPH2_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG5_SD2FLT3_COMPH2_Msk) >> \
     XBAR_XBARFLG5_SD2FLT3_COMPH2_Pos) /*!< SD2FLT3_COMPH2 Get Value            */


#define XBAR_XBARFLG5_SD2FLT3_COMPL2_Pos (12U) /*!< SD2FLT3_COMPL2 Postion   12         */
#define XBAR_XBARFLG5_SD2FLT3_COMPL2_Msk \
    (0x1U << XBAR_XBARFLG5_SD2FLT3_COMPL2_Pos) /*!< SD2FLT3_COMPL2 Mask      0x00001000 */
#define XBAR_XBARFLG5_SD2FLT3_COMPL2_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG5_SD2FLT3_COMPL2_Pos) & \
     XBAR_XBARFLG5_SD2FLT3_COMPL2_Msk) /*!< SD2FLT3_COMPL2 Set Value            */
#define XBAR_XBARFLG5_SD2FLT3_COMPL2_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG5_SD2FLT3_COMPL2_Msk) >> \
     XBAR_XBARFLG5_SD2FLT3_COMPL2_Pos) /*!< SD2FLT3_COMPL2 Get Value            */


#define XBAR_XBARFLG5_SD2FLT2_COMPH2_Pos (11U) /*!< SD2FLT2_COMPH2 Postion   11         */
#define XBAR_XBARFLG5_SD2FLT2_COMPH2_Msk \
    (0x1U << XBAR_XBARFLG5_SD2FLT2_COMPH2_Pos) /*!< SD2FLT2_COMPH2 Mask      0x00000800 */
#define XBAR_XBARFLG5_SD2FLT2_COMPH2_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG5_SD2FLT2_COMPH2_Pos) & \
     XBAR_XBARFLG5_SD2FLT2_COMPH2_Msk) /*!< SD2FLT2_COMPH2 Set Value            */
#define XBAR_XBARFLG5_SD2FLT2_COMPH2_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG5_SD2FLT2_COMPH2_Msk) >> \
     XBAR_XBARFLG5_SD2FLT2_COMPH2_Pos) /*!< SD2FLT2_COMPH2 Get Value            */


#define XBAR_XBARFLG5_SD2FLT2_COMPL2_Pos (10U) /*!< SD2FLT2_COMPL2 Postion   10         */
#define XBAR_XBARFLG5_SD2FLT2_COMPL2_Msk \
    (0x1U << XBAR_XBARFLG5_SD2FLT2_COMPL2_Pos) /*!< SD2FLT2_COMPL2 Mask      0x00000400 */
#define XBAR_XBARFLG5_SD2FLT2_COMPL2_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG5_SD2FLT2_COMPL2_Pos) & \
     XBAR_XBARFLG5_SD2FLT2_COMPL2_Msk) /*!< SD2FLT2_COMPL2 Set Value            */
#define XBAR_XBARFLG5_SD2FLT2_COMPL2_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG5_SD2FLT2_COMPL2_Msk) >> \
     XBAR_XBARFLG5_SD2FLT2_COMPL2_Pos) /*!< SD2FLT2_COMPL2 Get Value            */


#define XBAR_XBARFLG5_SD2FLT1_COMPH2_Pos (9U) /*!< SD2FLT1_COMPH2 Postion   9          */
#define XBAR_XBARFLG5_SD2FLT1_COMPH2_Msk \
    (0x1U << XBAR_XBARFLG5_SD2FLT1_COMPH2_Pos) /*!< SD2FLT1_COMPH2 Mask      0x00000200 */
#define XBAR_XBARFLG5_SD2FLT1_COMPH2_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG5_SD2FLT1_COMPH2_Pos) & \
     XBAR_XBARFLG5_SD2FLT1_COMPH2_Msk) /*!< SD2FLT1_COMPH2 Set Value            */
#define XBAR_XBARFLG5_SD2FLT1_COMPH2_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG5_SD2FLT1_COMPH2_Msk) >> \
     XBAR_XBARFLG5_SD2FLT1_COMPH2_Pos) /*!< SD2FLT1_COMPH2 Get Value            */


#define XBAR_XBARFLG5_SD2FLT1_COMPL2_Pos (8U) /*!< SD2FLT1_COMPL2 Postion   8          */
#define XBAR_XBARFLG5_SD2FLT1_COMPL2_Msk \
    (0x1U << XBAR_XBARFLG5_SD2FLT1_COMPL2_Pos) /*!< SD2FLT1_COMPL2 Mask      0x00000100 */
#define XBAR_XBARFLG5_SD2FLT1_COMPL2_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG5_SD2FLT1_COMPL2_Pos) & \
     XBAR_XBARFLG5_SD2FLT1_COMPL2_Msk) /*!< SD2FLT1_COMPL2 Set Value            */
#define XBAR_XBARFLG5_SD2FLT1_COMPL2_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG5_SD2FLT1_COMPL2_Msk) >> \
     XBAR_XBARFLG5_SD2FLT1_COMPL2_Pos) /*!< SD2FLT1_COMPL2 Get Value            */


#define XBAR_XBARFLG5_SD1FLT4_COMPH2_Pos (7U) /*!< SD1FLT4_COMPH2 Postion   7          */
#define XBAR_XBARFLG5_SD1FLT4_COMPH2_Msk \
    (0x1U << XBAR_XBARFLG5_SD1FLT4_COMPH2_Pos) /*!< SD1FLT4_COMPH2 Mask      0x00000080 */
#define XBAR_XBARFLG5_SD1FLT4_COMPH2_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG5_SD1FLT4_COMPH2_Pos) & \
     XBAR_XBARFLG5_SD1FLT4_COMPH2_Msk) /*!< SD1FLT4_COMPH2 Set Value            */
#define XBAR_XBARFLG5_SD1FLT4_COMPH2_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG5_SD1FLT4_COMPH2_Msk) >> \
     XBAR_XBARFLG5_SD1FLT4_COMPH2_Pos) /*!< SD1FLT4_COMPH2 Get Value            */


#define XBAR_XBARFLG5_SD1FLT4_COMPL2_Pos (6U) /*!< SD1FLT4_COMPL2 Postion   6          */
#define XBAR_XBARFLG5_SD1FLT4_COMPL2_Msk \
    (0x1U << XBAR_XBARFLG5_SD1FLT4_COMPL2_Pos) /*!< SD1FLT4_COMPL2 Mask      0x00000040 */
#define XBAR_XBARFLG5_SD1FLT4_COMPL2_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG5_SD1FLT4_COMPL2_Pos) & \
     XBAR_XBARFLG5_SD1FLT4_COMPL2_Msk) /*!< SD1FLT4_COMPL2 Set Value            */
#define XBAR_XBARFLG5_SD1FLT4_COMPL2_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG5_SD1FLT4_COMPL2_Msk) >> \
     XBAR_XBARFLG5_SD1FLT4_COMPL2_Pos) /*!< SD1FLT4_COMPL2 Get Value            */


#define XBAR_XBARFLG5_SD1FLT3_COMPH2_Pos (5U) /*!< SD1FLT3_COMPH2 Postion   5          */
#define XBAR_XBARFLG5_SD1FLT3_COMPH2_Msk \
    (0x1U << XBAR_XBARFLG5_SD1FLT3_COMPH2_Pos) /*!< SD1FLT3_COMPH2 Mask      0x00000020 */
#define XBAR_XBARFLG5_SD1FLT3_COMPH2_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG5_SD1FLT3_COMPH2_Pos) & \
     XBAR_XBARFLG5_SD1FLT3_COMPH2_Msk) /*!< SD1FLT3_COMPH2 Set Value            */
#define XBAR_XBARFLG5_SD1FLT3_COMPH2_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG5_SD1FLT3_COMPH2_Msk) >> \
     XBAR_XBARFLG5_SD1FLT3_COMPH2_Pos) /*!< SD1FLT3_COMPH2 Get Value            */


#define XBAR_XBARFLG5_SD1FLT3_COMPL2_Pos (4U) /*!< SD1FLT3_COMPL2 Postion   4          */
#define XBAR_XBARFLG5_SD1FLT3_COMPL2_Msk \
    (0x1U << XBAR_XBARFLG5_SD1FLT3_COMPL2_Pos) /*!< SD1FLT3_COMPL2 Mask      0x00000010 */
#define XBAR_XBARFLG5_SD1FLT3_COMPL2_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG5_SD1FLT3_COMPL2_Pos) & \
     XBAR_XBARFLG5_SD1FLT3_COMPL2_Msk) /*!< SD1FLT3_COMPL2 Set Value            */
#define XBAR_XBARFLG5_SD1FLT3_COMPL2_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG5_SD1FLT3_COMPL2_Msk) >> \
     XBAR_XBARFLG5_SD1FLT3_COMPL2_Pos) /*!< SD1FLT3_COMPL2 Get Value            */


#define XBAR_XBARFLG5_SD1FLT2_COMPH2_Pos (3U) /*!< SD1FLT2_COMPH2 Postion   3          */
#define XBAR_XBARFLG5_SD1FLT2_COMPH2_Msk \
    (0x1U << XBAR_XBARFLG5_SD1FLT2_COMPH2_Pos) /*!< SD1FLT2_COMPH2 Mask      0x00000008 */
#define XBAR_XBARFLG5_SD1FLT2_COMPH2_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG5_SD1FLT2_COMPH2_Pos) & \
     XBAR_XBARFLG5_SD1FLT2_COMPH2_Msk) /*!< SD1FLT2_COMPH2 Set Value            */
#define XBAR_XBARFLG5_SD1FLT2_COMPH2_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG5_SD1FLT2_COMPH2_Msk) >> \
     XBAR_XBARFLG5_SD1FLT2_COMPH2_Pos) /*!< SD1FLT2_COMPH2 Get Value            */


#define XBAR_XBARFLG5_SD1FLT2_COMPL2_Pos (2U) /*!< SD1FLT2_COMPL2 Postion   2          */
#define XBAR_XBARFLG5_SD1FLT2_COMPL2_Msk \
    (0x1U << XBAR_XBARFLG5_SD1FLT2_COMPL2_Pos) /*!< SD1FLT2_COMPL2 Mask      0x00000004 */
#define XBAR_XBARFLG5_SD1FLT2_COMPL2_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG5_SD1FLT2_COMPL2_Pos) & \
     XBAR_XBARFLG5_SD1FLT2_COMPL2_Msk) /*!< SD1FLT2_COMPL2 Set Value            */
#define XBAR_XBARFLG5_SD1FLT2_COMPL2_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG5_SD1FLT2_COMPL2_Msk) >> \
     XBAR_XBARFLG5_SD1FLT2_COMPL2_Pos) /*!< SD1FLT2_COMPL2 Get Value            */


#define XBAR_XBARFLG5_SD1FLT1_COMPH2_Pos (1U) /*!< SD1FLT1_COMPH2 Postion   1          */
#define XBAR_XBARFLG5_SD1FLT1_COMPH2_Msk \
    (0x1U << XBAR_XBARFLG5_SD1FLT1_COMPH2_Pos) /*!< SD1FLT1_COMPH2 Mask      0x00000002 */
#define XBAR_XBARFLG5_SD1FLT1_COMPH2_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG5_SD1FLT1_COMPH2_Pos) & \
     XBAR_XBARFLG5_SD1FLT1_COMPH2_Msk) /*!< SD1FLT1_COMPH2 Set Value            */
#define XBAR_XBARFLG5_SD1FLT1_COMPH2_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG5_SD1FLT1_COMPH2_Msk) >> \
     XBAR_XBARFLG5_SD1FLT1_COMPH2_Pos) /*!< SD1FLT1_COMPH2 Get Value            */


#define XBAR_XBARFLG5_SD1FLT1_COMPL2_Pos (0U) /*!< SD1FLT1_COMPL2 Postion   0          */
#define XBAR_XBARFLG5_SD1FLT1_COMPL2_Msk \
    (0x1U << XBAR_XBARFLG5_SD1FLT1_COMPL2_Pos) /*!< SD1FLT1_COMPL2 Mask      0x00000001 */
#define XBAR_XBARFLG5_SD1FLT1_COMPL2_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARFLG5_SD1FLT1_COMPL2_Pos) & \
     XBAR_XBARFLG5_SD1FLT1_COMPL2_Msk) /*!< SD1FLT1_COMPL2 Set Value            */
#define XBAR_XBARFLG5_SD1FLT1_COMPL2_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARFLG5_SD1FLT1_COMPL2_Msk) >> \
     XBAR_XBARFLG5_SD1FLT1_COMPL2_Pos) /*!< SD1FLT1_COMPL2 Get Value            */


/* XBARCLR5 bitfield */
#define XBAR_XBARCLR5_SD2FLT4_CEVT1OUT_Pos (31U) /*!< SD2FLT4_CEVT1OUT Postion   31         */
#define XBAR_XBARCLR5_SD2FLT4_CEVT1OUT_Msk \
    (0x1U << XBAR_XBARCLR5_SD2FLT4_CEVT1OUT_Pos) /*!< SD2FLT4_CEVT1OUT Mask      0x80000000 */
#define XBAR_XBARCLR5_SD2FLT4_CEVT1OUT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR5_SD2FLT4_CEVT1OUT_Pos) & \
     XBAR_XBARCLR5_SD2FLT4_CEVT1OUT_Msk) /*!< SD2FLT4_CEVT1OUT Set Value            */
#define XBAR_XBARCLR5_SD2FLT4_CEVT1OUT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR5_SD2FLT4_CEVT1OUT_Msk) >> \
     XBAR_XBARCLR5_SD2FLT4_CEVT1OUT_Pos) /*!< SD2FLT4_CEVT1OUT Get Value            */


#define XBAR_XBARCLR5_SD2FLT4_CEVT2OUT_Pos (30U) /*!< SD2FLT4_CEVT2OUT Postion   30         */
#define XBAR_XBARCLR5_SD2FLT4_CEVT2OUT_Msk \
    (0x1U << XBAR_XBARCLR5_SD2FLT4_CEVT2OUT_Pos) /*!< SD2FLT4_CEVT2OUT Mask      0x40000000 */
#define XBAR_XBARCLR5_SD2FLT4_CEVT2OUT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR5_SD2FLT4_CEVT2OUT_Pos) & \
     XBAR_XBARCLR5_SD2FLT4_CEVT2OUT_Msk) /*!< SD2FLT4_CEVT2OUT Set Value            */
#define XBAR_XBARCLR5_SD2FLT4_CEVT2OUT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR5_SD2FLT4_CEVT2OUT_Msk) >> \
     XBAR_XBARCLR5_SD2FLT4_CEVT2OUT_Pos) /*!< SD2FLT4_CEVT2OUT Get Value            */


#define XBAR_XBARCLR5_SD2FLT3_CEVT1OUT_Pos (29U) /*!< SD2FLT3_CEVT1OUT Postion   29         */
#define XBAR_XBARCLR5_SD2FLT3_CEVT1OUT_Msk \
    (0x1U << XBAR_XBARCLR5_SD2FLT3_CEVT1OUT_Pos) /*!< SD2FLT3_CEVT1OUT Mask      0x20000000 */
#define XBAR_XBARCLR5_SD2FLT3_CEVT1OUT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR5_SD2FLT3_CEVT1OUT_Pos) & \
     XBAR_XBARCLR5_SD2FLT3_CEVT1OUT_Msk) /*!< SD2FLT3_CEVT1OUT Set Value            */
#define XBAR_XBARCLR5_SD2FLT3_CEVT1OUT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR5_SD2FLT3_CEVT1OUT_Msk) >> \
     XBAR_XBARCLR5_SD2FLT3_CEVT1OUT_Pos) /*!< SD2FLT3_CEVT1OUT Get Value            */


#define XBAR_XBARCLR5_SD2FLT3_CEVT2OUT_Pos (28U) /*!< SD2FLT3_CEVT2OUT Postion   28         */
#define XBAR_XBARCLR5_SD2FLT3_CEVT2OUT_Msk \
    (0x1U << XBAR_XBARCLR5_SD2FLT3_CEVT2OUT_Pos) /*!< SD2FLT3_CEVT2OUT Mask      0x10000000 */
#define XBAR_XBARCLR5_SD2FLT3_CEVT2OUT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR5_SD2FLT3_CEVT2OUT_Pos) & \
     XBAR_XBARCLR5_SD2FLT3_CEVT2OUT_Msk) /*!< SD2FLT3_CEVT2OUT Set Value            */
#define XBAR_XBARCLR5_SD2FLT3_CEVT2OUT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR5_SD2FLT3_CEVT2OUT_Msk) >> \
     XBAR_XBARCLR5_SD2FLT3_CEVT2OUT_Pos) /*!< SD2FLT3_CEVT2OUT Get Value            */


#define XBAR_XBARCLR5_SD2FLT2_CEVT1OUT_Pos (27U) /*!< SD2FLT2_CEVT1OUT Postion   27         */
#define XBAR_XBARCLR5_SD2FLT2_CEVT1OUT_Msk \
    (0x1U << XBAR_XBARCLR5_SD2FLT2_CEVT1OUT_Pos) /*!< SD2FLT2_CEVT1OUT Mask      0x08000000 */
#define XBAR_XBARCLR5_SD2FLT2_CEVT1OUT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR5_SD2FLT2_CEVT1OUT_Pos) & \
     XBAR_XBARCLR5_SD2FLT2_CEVT1OUT_Msk) /*!< SD2FLT2_CEVT1OUT Set Value            */
#define XBAR_XBARCLR5_SD2FLT2_CEVT1OUT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR5_SD2FLT2_CEVT1OUT_Msk) >> \
     XBAR_XBARCLR5_SD2FLT2_CEVT1OUT_Pos) /*!< SD2FLT2_CEVT1OUT Get Value            */


#define XBAR_XBARCLR5_SD2FLT2_CEVT2OUT_Pos (26U) /*!< SD2FLT2_CEVT2OUT Postion   26         */
#define XBAR_XBARCLR5_SD2FLT2_CEVT2OUT_Msk \
    (0x1U << XBAR_XBARCLR5_SD2FLT2_CEVT2OUT_Pos) /*!< SD2FLT2_CEVT2OUT Mask      0x04000000 */
#define XBAR_XBARCLR5_SD2FLT2_CEVT2OUT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR5_SD2FLT2_CEVT2OUT_Pos) & \
     XBAR_XBARCLR5_SD2FLT2_CEVT2OUT_Msk) /*!< SD2FLT2_CEVT2OUT Set Value            */
#define XBAR_XBARCLR5_SD2FLT2_CEVT2OUT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR5_SD2FLT2_CEVT2OUT_Msk) >> \
     XBAR_XBARCLR5_SD2FLT2_CEVT2OUT_Pos) /*!< SD2FLT2_CEVT2OUT Get Value            */


#define XBAR_XBARCLR5_SD2FLT1_CEVT1OUT_Pos (25U) /*!< SD2FLT1_CEVT1OUT Postion   25         */
#define XBAR_XBARCLR5_SD2FLT1_CEVT1OUT_Msk \
    (0x1U << XBAR_XBARCLR5_SD2FLT1_CEVT1OUT_Pos) /*!< SD2FLT1_CEVT1OUT Mask      0x02000000 */
#define XBAR_XBARCLR5_SD2FLT1_CEVT1OUT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR5_SD2FLT1_CEVT1OUT_Pos) & \
     XBAR_XBARCLR5_SD2FLT1_CEVT1OUT_Msk) /*!< SD2FLT1_CEVT1OUT Set Value            */
#define XBAR_XBARCLR5_SD2FLT1_CEVT1OUT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR5_SD2FLT1_CEVT1OUT_Msk) >> \
     XBAR_XBARCLR5_SD2FLT1_CEVT1OUT_Pos) /*!< SD2FLT1_CEVT1OUT Get Value            */


#define XBAR_XBARCLR5_SD2FLT1_CEVT2OUT_Pos (24U) /*!< SD2FLT1_CEVT2OUT Postion   24         */
#define XBAR_XBARCLR5_SD2FLT1_CEVT2OUT_Msk \
    (0x1U << XBAR_XBARCLR5_SD2FLT1_CEVT2OUT_Pos) /*!< SD2FLT1_CEVT2OUT Mask      0x01000000 */
#define XBAR_XBARCLR5_SD2FLT1_CEVT2OUT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR5_SD2FLT1_CEVT2OUT_Pos) & \
     XBAR_XBARCLR5_SD2FLT1_CEVT2OUT_Msk) /*!< SD2FLT1_CEVT2OUT Set Value            */
#define XBAR_XBARCLR5_SD2FLT1_CEVT2OUT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR5_SD2FLT1_CEVT2OUT_Msk) >> \
     XBAR_XBARCLR5_SD2FLT1_CEVT2OUT_Pos) /*!< SD2FLT1_CEVT2OUT Get Value            */


#define XBAR_XBARCLR5_SD1FLT4_CEVT1OUT_Pos (23U) /*!< SD1FLT4_CEVT1OUT Postion   23         */
#define XBAR_XBARCLR5_SD1FLT4_CEVT1OUT_Msk \
    (0x1U << XBAR_XBARCLR5_SD1FLT4_CEVT1OUT_Pos) /*!< SD1FLT4_CEVT1OUT Mask      0x00800000 */
#define XBAR_XBARCLR5_SD1FLT4_CEVT1OUT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR5_SD1FLT4_CEVT1OUT_Pos) & \
     XBAR_XBARCLR5_SD1FLT4_CEVT1OUT_Msk) /*!< SD1FLT4_CEVT1OUT Set Value            */
#define XBAR_XBARCLR5_SD1FLT4_CEVT1OUT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR5_SD1FLT4_CEVT1OUT_Msk) >> \
     XBAR_XBARCLR5_SD1FLT4_CEVT1OUT_Pos) /*!< SD1FLT4_CEVT1OUT Get Value            */


#define XBAR_XBARCLR5_SD1FLT4_CEVT2OUT_Pos (22U) /*!< SD1FLT4_CEVT2OUT Postion   22         */
#define XBAR_XBARCLR5_SD1FLT4_CEVT2OUT_Msk \
    (0x1U << XBAR_XBARCLR5_SD1FLT4_CEVT2OUT_Pos) /*!< SD1FLT4_CEVT2OUT Mask      0x00400000 */
#define XBAR_XBARCLR5_SD1FLT4_CEVT2OUT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR5_SD1FLT4_CEVT2OUT_Pos) & \
     XBAR_XBARCLR5_SD1FLT4_CEVT2OUT_Msk) /*!< SD1FLT4_CEVT2OUT Set Value            */
#define XBAR_XBARCLR5_SD1FLT4_CEVT2OUT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR5_SD1FLT4_CEVT2OUT_Msk) >> \
     XBAR_XBARCLR5_SD1FLT4_CEVT2OUT_Pos) /*!< SD1FLT4_CEVT2OUT Get Value            */


#define XBAR_XBARCLR5_SD1FLT3_CEVT1OUT_Pos (21U) /*!< SD1FLT3_CEVT1OUT Postion   21         */
#define XBAR_XBARCLR5_SD1FLT3_CEVT1OUT_Msk \
    (0x1U << XBAR_XBARCLR5_SD1FLT3_CEVT1OUT_Pos) /*!< SD1FLT3_CEVT1OUT Mask      0x00200000 */
#define XBAR_XBARCLR5_SD1FLT3_CEVT1OUT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR5_SD1FLT3_CEVT1OUT_Pos) & \
     XBAR_XBARCLR5_SD1FLT3_CEVT1OUT_Msk) /*!< SD1FLT3_CEVT1OUT Set Value            */
#define XBAR_XBARCLR5_SD1FLT3_CEVT1OUT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR5_SD1FLT3_CEVT1OUT_Msk) >> \
     XBAR_XBARCLR5_SD1FLT3_CEVT1OUT_Pos) /*!< SD1FLT3_CEVT1OUT Get Value            */


#define XBAR_XBARCLR5_SD1FLT3_CEVT2OUT_Pos (20U) /*!< SD1FLT3_CEVT2OUT Postion   20         */
#define XBAR_XBARCLR5_SD1FLT3_CEVT2OUT_Msk \
    (0x1U << XBAR_XBARCLR5_SD1FLT3_CEVT2OUT_Pos) /*!< SD1FLT3_CEVT2OUT Mask      0x00100000 */
#define XBAR_XBARCLR5_SD1FLT3_CEVT2OUT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR5_SD1FLT3_CEVT2OUT_Pos) & \
     XBAR_XBARCLR5_SD1FLT3_CEVT2OUT_Msk) /*!< SD1FLT3_CEVT2OUT Set Value            */
#define XBAR_XBARCLR5_SD1FLT3_CEVT2OUT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR5_SD1FLT3_CEVT2OUT_Msk) >> \
     XBAR_XBARCLR5_SD1FLT3_CEVT2OUT_Pos) /*!< SD1FLT3_CEVT2OUT Get Value            */


#define XBAR_XBARCLR5_SD1FLT2_CEVT1OUT_Pos (19U) /*!< SD1FLT2_CEVT1OUT Postion   19         */
#define XBAR_XBARCLR5_SD1FLT2_CEVT1OUT_Msk \
    (0x1U << XBAR_XBARCLR5_SD1FLT2_CEVT1OUT_Pos) /*!< SD1FLT2_CEVT1OUT Mask      0x00080000 */
#define XBAR_XBARCLR5_SD1FLT2_CEVT1OUT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR5_SD1FLT2_CEVT1OUT_Pos) & \
     XBAR_XBARCLR5_SD1FLT2_CEVT1OUT_Msk) /*!< SD1FLT2_CEVT1OUT Set Value            */
#define XBAR_XBARCLR5_SD1FLT2_CEVT1OUT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR5_SD1FLT2_CEVT1OUT_Msk) >> \
     XBAR_XBARCLR5_SD1FLT2_CEVT1OUT_Pos) /*!< SD1FLT2_CEVT1OUT Get Value            */


#define XBAR_XBARCLR5_SD1FLT2_CEVT2OUT_Pos (18U) /*!< SD1FLT2_CEVT2OUT Postion   18         */
#define XBAR_XBARCLR5_SD1FLT2_CEVT2OUT_Msk \
    (0x1U << XBAR_XBARCLR5_SD1FLT2_CEVT2OUT_Pos) /*!< SD1FLT2_CEVT2OUT Mask      0x00040000 */
#define XBAR_XBARCLR5_SD1FLT2_CEVT2OUT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR5_SD1FLT2_CEVT2OUT_Pos) & \
     XBAR_XBARCLR5_SD1FLT2_CEVT2OUT_Msk) /*!< SD1FLT2_CEVT2OUT Set Value            */
#define XBAR_XBARCLR5_SD1FLT2_CEVT2OUT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR5_SD1FLT2_CEVT2OUT_Msk) >> \
     XBAR_XBARCLR5_SD1FLT2_CEVT2OUT_Pos) /*!< SD1FLT2_CEVT2OUT Get Value            */


#define XBAR_XBARCLR5_SD1FLT1_CEVT1OUT_Pos (17U) /*!< SD1FLT1_CEVT1OUT Postion   17         */
#define XBAR_XBARCLR5_SD1FLT1_CEVT1OUT_Msk \
    (0x1U << XBAR_XBARCLR5_SD1FLT1_CEVT1OUT_Pos) /*!< SD1FLT1_CEVT1OUT Mask      0x00020000 */
#define XBAR_XBARCLR5_SD1FLT1_CEVT1OUT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR5_SD1FLT1_CEVT1OUT_Pos) & \
     XBAR_XBARCLR5_SD1FLT1_CEVT1OUT_Msk) /*!< SD1FLT1_CEVT1OUT Set Value            */
#define XBAR_XBARCLR5_SD1FLT1_CEVT1OUT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR5_SD1FLT1_CEVT1OUT_Msk) >> \
     XBAR_XBARCLR5_SD1FLT1_CEVT1OUT_Pos) /*!< SD1FLT1_CEVT1OUT Get Value            */


#define XBAR_XBARCLR5_SD1FLT1_CEVT2OUT_Pos (16U) /*!< SD1FLT1_CEVT2OUT Postion   16         */
#define XBAR_XBARCLR5_SD1FLT1_CEVT2OUT_Msk \
    (0x1U << XBAR_XBARCLR5_SD1FLT1_CEVT2OUT_Pos) /*!< SD1FLT1_CEVT2OUT Mask      0x00010000 */
#define XBAR_XBARCLR5_SD1FLT1_CEVT2OUT_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR5_SD1FLT1_CEVT2OUT_Pos) & \
     XBAR_XBARCLR5_SD1FLT1_CEVT2OUT_Msk) /*!< SD1FLT1_CEVT2OUT Set Value            */
#define XBAR_XBARCLR5_SD1FLT1_CEVT2OUT_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR5_SD1FLT1_CEVT2OUT_Msk) >> \
     XBAR_XBARCLR5_SD1FLT1_CEVT2OUT_Pos) /*!< SD1FLT1_CEVT2OUT Get Value            */


#define XBAR_XBARCLR5_SD2FLT4_COMPH2_Pos (15U) /*!< SD2FLT4_COMPH2 Postion   15         */
#define XBAR_XBARCLR5_SD2FLT4_COMPH2_Msk \
    (0x1U << XBAR_XBARCLR5_SD2FLT4_COMPH2_Pos) /*!< SD2FLT4_COMPH2 Mask      0x00008000 */
#define XBAR_XBARCLR5_SD2FLT4_COMPH2_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR5_SD2FLT4_COMPH2_Pos) & \
     XBAR_XBARCLR5_SD2FLT4_COMPH2_Msk) /*!< SD2FLT4_COMPH2 Set Value            */
#define XBAR_XBARCLR5_SD2FLT4_COMPH2_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR5_SD2FLT4_COMPH2_Msk) >> \
     XBAR_XBARCLR5_SD2FLT4_COMPH2_Pos) /*!< SD2FLT4_COMPH2 Get Value            */


#define XBAR_XBARCLR5_SD2FLT4_COMPL2_Pos (14U) /*!< SD2FLT4_COMPL2 Postion   14         */
#define XBAR_XBARCLR5_SD2FLT4_COMPL2_Msk \
    (0x1U << XBAR_XBARCLR5_SD2FLT4_COMPL2_Pos) /*!< SD2FLT4_COMPL2 Mask      0x00004000 */
#define XBAR_XBARCLR5_SD2FLT4_COMPL2_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR5_SD2FLT4_COMPL2_Pos) & \
     XBAR_XBARCLR5_SD2FLT4_COMPL2_Msk) /*!< SD2FLT4_COMPL2 Set Value            */
#define XBAR_XBARCLR5_SD2FLT4_COMPL2_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR5_SD2FLT4_COMPL2_Msk) >> \
     XBAR_XBARCLR5_SD2FLT4_COMPL2_Pos) /*!< SD2FLT4_COMPL2 Get Value            */


#define XBAR_XBARCLR5_SD2FLT3_COMPH2_Pos (13U) /*!< SD2FLT3_COMPH2 Postion   13         */
#define XBAR_XBARCLR5_SD2FLT3_COMPH2_Msk \
    (0x1U << XBAR_XBARCLR5_SD2FLT3_COMPH2_Pos) /*!< SD2FLT3_COMPH2 Mask      0x00002000 */
#define XBAR_XBARCLR5_SD2FLT3_COMPH2_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR5_SD2FLT3_COMPH2_Pos) & \
     XBAR_XBARCLR5_SD2FLT3_COMPH2_Msk) /*!< SD2FLT3_COMPH2 Set Value            */
#define XBAR_XBARCLR5_SD2FLT3_COMPH2_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR5_SD2FLT3_COMPH2_Msk) >> \
     XBAR_XBARCLR5_SD2FLT3_COMPH2_Pos) /*!< SD2FLT3_COMPH2 Get Value            */


#define XBAR_XBARCLR5_SD2FLT3_COMPL2_Pos (12U) /*!< SD2FLT3_COMPL2 Postion   12         */
#define XBAR_XBARCLR5_SD2FLT3_COMPL2_Msk \
    (0x1U << XBAR_XBARCLR5_SD2FLT3_COMPL2_Pos) /*!< SD2FLT3_COMPL2 Mask      0x00001000 */
#define XBAR_XBARCLR5_SD2FLT3_COMPL2_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR5_SD2FLT3_COMPL2_Pos) & \
     XBAR_XBARCLR5_SD2FLT3_COMPL2_Msk) /*!< SD2FLT3_COMPL2 Set Value            */
#define XBAR_XBARCLR5_SD2FLT3_COMPL2_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR5_SD2FLT3_COMPL2_Msk) >> \
     XBAR_XBARCLR5_SD2FLT3_COMPL2_Pos) /*!< SD2FLT3_COMPL2 Get Value            */


#define XBAR_XBARCLR5_SD2FLT2_COMPH2_Pos (11U) /*!< SD2FLT2_COMPH2 Postion   11         */
#define XBAR_XBARCLR5_SD2FLT2_COMPH2_Msk \
    (0x1U << XBAR_XBARCLR5_SD2FLT2_COMPH2_Pos) /*!< SD2FLT2_COMPH2 Mask      0x00000800 */
#define XBAR_XBARCLR5_SD2FLT2_COMPH2_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR5_SD2FLT2_COMPH2_Pos) & \
     XBAR_XBARCLR5_SD2FLT2_COMPH2_Msk) /*!< SD2FLT2_COMPH2 Set Value            */
#define XBAR_XBARCLR5_SD2FLT2_COMPH2_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR5_SD2FLT2_COMPH2_Msk) >> \
     XBAR_XBARCLR5_SD2FLT2_COMPH2_Pos) /*!< SD2FLT2_COMPH2 Get Value            */


#define XBAR_XBARCLR5_SD2FLT2_COMPL2_Pos (10U) /*!< SD2FLT2_COMPL2 Postion   10         */
#define XBAR_XBARCLR5_SD2FLT2_COMPL2_Msk \
    (0x1U << XBAR_XBARCLR5_SD2FLT2_COMPL2_Pos) /*!< SD2FLT2_COMPL2 Mask      0x00000400 */
#define XBAR_XBARCLR5_SD2FLT2_COMPL2_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR5_SD2FLT2_COMPL2_Pos) & \
     XBAR_XBARCLR5_SD2FLT2_COMPL2_Msk) /*!< SD2FLT2_COMPL2 Set Value            */
#define XBAR_XBARCLR5_SD2FLT2_COMPL2_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR5_SD2FLT2_COMPL2_Msk) >> \
     XBAR_XBARCLR5_SD2FLT2_COMPL2_Pos) /*!< SD2FLT2_COMPL2 Get Value            */


#define XBAR_XBARCLR5_SD2FLT1_COMPH2_Pos (9U) /*!< SD2FLT1_COMPH2 Postion   9          */
#define XBAR_XBARCLR5_SD2FLT1_COMPH2_Msk \
    (0x1U << XBAR_XBARCLR5_SD2FLT1_COMPH2_Pos) /*!< SD2FLT1_COMPH2 Mask      0x00000200 */
#define XBAR_XBARCLR5_SD2FLT1_COMPH2_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR5_SD2FLT1_COMPH2_Pos) & \
     XBAR_XBARCLR5_SD2FLT1_COMPH2_Msk) /*!< SD2FLT1_COMPH2 Set Value            */
#define XBAR_XBARCLR5_SD2FLT1_COMPH2_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR5_SD2FLT1_COMPH2_Msk) >> \
     XBAR_XBARCLR5_SD2FLT1_COMPH2_Pos) /*!< SD2FLT1_COMPH2 Get Value            */


#define XBAR_XBARCLR5_SD2FLT1_COMPL2_Pos (8U) /*!< SD2FLT1_COMPL2 Postion   8          */
#define XBAR_XBARCLR5_SD2FLT1_COMPL2_Msk \
    (0x1U << XBAR_XBARCLR5_SD2FLT1_COMPL2_Pos) /*!< SD2FLT1_COMPL2 Mask      0x00000100 */
#define XBAR_XBARCLR5_SD2FLT1_COMPL2_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR5_SD2FLT1_COMPL2_Pos) & \
     XBAR_XBARCLR5_SD2FLT1_COMPL2_Msk) /*!< SD2FLT1_COMPL2 Set Value            */
#define XBAR_XBARCLR5_SD2FLT1_COMPL2_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR5_SD2FLT1_COMPL2_Msk) >> \
     XBAR_XBARCLR5_SD2FLT1_COMPL2_Pos) /*!< SD2FLT1_COMPL2 Get Value            */


#define XBAR_XBARCLR5_SD1FLT4_COMPH2_Pos (7U) /*!< SD1FLT4_COMPH2 Postion   7          */
#define XBAR_XBARCLR5_SD1FLT4_COMPH2_Msk \
    (0x1U << XBAR_XBARCLR5_SD1FLT4_COMPH2_Pos) /*!< SD1FLT4_COMPH2 Mask      0x00000080 */
#define XBAR_XBARCLR5_SD1FLT4_COMPH2_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR5_SD1FLT4_COMPH2_Pos) & \
     XBAR_XBARCLR5_SD1FLT4_COMPH2_Msk) /*!< SD1FLT4_COMPH2 Set Value            */
#define XBAR_XBARCLR5_SD1FLT4_COMPH2_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR5_SD1FLT4_COMPH2_Msk) >> \
     XBAR_XBARCLR5_SD1FLT4_COMPH2_Pos) /*!< SD1FLT4_COMPH2 Get Value            */


#define XBAR_XBARCLR5_SD1FLT4_COMPL2_Pos (6U) /*!< SD1FLT4_COMPL2 Postion   6          */
#define XBAR_XBARCLR5_SD1FLT4_COMPL2_Msk \
    (0x1U << XBAR_XBARCLR5_SD1FLT4_COMPL2_Pos) /*!< SD1FLT4_COMPL2 Mask      0x00000040 */
#define XBAR_XBARCLR5_SD1FLT4_COMPL2_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR5_SD1FLT4_COMPL2_Pos) & \
     XBAR_XBARCLR5_SD1FLT4_COMPL2_Msk) /*!< SD1FLT4_COMPL2 Set Value            */
#define XBAR_XBARCLR5_SD1FLT4_COMPL2_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR5_SD1FLT4_COMPL2_Msk) >> \
     XBAR_XBARCLR5_SD1FLT4_COMPL2_Pos) /*!< SD1FLT4_COMPL2 Get Value            */


#define XBAR_XBARCLR5_SD1FLT3_COMPH2_Pos (5U) /*!< SD1FLT3_COMPH2 Postion   5          */
#define XBAR_XBARCLR5_SD1FLT3_COMPH2_Msk \
    (0x1U << XBAR_XBARCLR5_SD1FLT3_COMPH2_Pos) /*!< SD1FLT3_COMPH2 Mask      0x00000020 */
#define XBAR_XBARCLR5_SD1FLT3_COMPH2_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR5_SD1FLT3_COMPH2_Pos) & \
     XBAR_XBARCLR5_SD1FLT3_COMPH2_Msk) /*!< SD1FLT3_COMPH2 Set Value            */
#define XBAR_XBARCLR5_SD1FLT3_COMPH2_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR5_SD1FLT3_COMPH2_Msk) >> \
     XBAR_XBARCLR5_SD1FLT3_COMPH2_Pos) /*!< SD1FLT3_COMPH2 Get Value            */


#define XBAR_XBARCLR5_SD1FLT3_COMPL2_Pos (4U) /*!< SD1FLT3_COMPL2 Postion   4          */
#define XBAR_XBARCLR5_SD1FLT3_COMPL2_Msk \
    (0x1U << XBAR_XBARCLR5_SD1FLT3_COMPL2_Pos) /*!< SD1FLT3_COMPL2 Mask      0x00000010 */
#define XBAR_XBARCLR5_SD1FLT3_COMPL2_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR5_SD1FLT3_COMPL2_Pos) & \
     XBAR_XBARCLR5_SD1FLT3_COMPL2_Msk) /*!< SD1FLT3_COMPL2 Set Value            */
#define XBAR_XBARCLR5_SD1FLT3_COMPL2_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR5_SD1FLT3_COMPL2_Msk) >> \
     XBAR_XBARCLR5_SD1FLT3_COMPL2_Pos) /*!< SD1FLT3_COMPL2 Get Value            */


#define XBAR_XBARCLR5_SD1FLT2_COMPH2_Pos (3U) /*!< SD1FLT2_COMPH2 Postion   3          */
#define XBAR_XBARCLR5_SD1FLT2_COMPH2_Msk \
    (0x1U << XBAR_XBARCLR5_SD1FLT2_COMPH2_Pos) /*!< SD1FLT2_COMPH2 Mask      0x00000008 */
#define XBAR_XBARCLR5_SD1FLT2_COMPH2_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR5_SD1FLT2_COMPH2_Pos) & \
     XBAR_XBARCLR5_SD1FLT2_COMPH2_Msk) /*!< SD1FLT2_COMPH2 Set Value            */
#define XBAR_XBARCLR5_SD1FLT2_COMPH2_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR5_SD1FLT2_COMPH2_Msk) >> \
     XBAR_XBARCLR5_SD1FLT2_COMPH2_Pos) /*!< SD1FLT2_COMPH2 Get Value            */


#define XBAR_XBARCLR5_SD1FLT2_COMPL2_Pos (2U) /*!< SD1FLT2_COMPL2 Postion   2          */
#define XBAR_XBARCLR5_SD1FLT2_COMPL2_Msk \
    (0x1U << XBAR_XBARCLR5_SD1FLT2_COMPL2_Pos) /*!< SD1FLT2_COMPL2 Mask      0x00000004 */
#define XBAR_XBARCLR5_SD1FLT2_COMPL2_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR5_SD1FLT2_COMPL2_Pos) & \
     XBAR_XBARCLR5_SD1FLT2_COMPL2_Msk) /*!< SD1FLT2_COMPL2 Set Value            */
#define XBAR_XBARCLR5_SD1FLT2_COMPL2_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR5_SD1FLT2_COMPL2_Msk) >> \
     XBAR_XBARCLR5_SD1FLT2_COMPL2_Pos) /*!< SD1FLT2_COMPL2 Get Value            */


#define XBAR_XBARCLR5_SD1FLT1_COMPH2_Pos (1U) /*!< SD1FLT1_COMPH2 Postion   1          */
#define XBAR_XBARCLR5_SD1FLT1_COMPH2_Msk \
    (0x1U << XBAR_XBARCLR5_SD1FLT1_COMPH2_Pos) /*!< SD1FLT1_COMPH2 Mask      0x00000002 */
#define XBAR_XBARCLR5_SD1FLT1_COMPH2_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR5_SD1FLT1_COMPH2_Pos) & \
     XBAR_XBARCLR5_SD1FLT1_COMPH2_Msk) /*!< SD1FLT1_COMPH2 Set Value            */
#define XBAR_XBARCLR5_SD1FLT1_COMPH2_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR5_SD1FLT1_COMPH2_Msk) >> \
     XBAR_XBARCLR5_SD1FLT1_COMPH2_Pos) /*!< SD1FLT1_COMPH2 Get Value            */


#define XBAR_XBARCLR5_SD1FLT1_COMPL2_Pos (0U) /*!< SD1FLT1_COMPL2 Postion   0          */
#define XBAR_XBARCLR5_SD1FLT1_COMPL2_Msk \
    (0x1U << XBAR_XBARCLR5_SD1FLT1_COMPL2_Pos) /*!< SD1FLT1_COMPL2 Mask      0x00000001 */
#define XBAR_XBARCLR5_SD1FLT1_COMPL2_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARCLR5_SD1FLT1_COMPL2_Pos) & \
     XBAR_XBARCLR5_SD1FLT1_COMPL2_Msk) /*!< SD1FLT1_COMPL2 Set Value            */
#define XBAR_XBARCLR5_SD1FLT1_COMPL2_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARCLR5_SD1FLT1_COMPL2_Msk) >> \
     XBAR_XBARCLR5_SD1FLT1_COMPL2_Pos) /*!< SD1FLT1_COMPL2 Get Value            */


/* XBARMISC bitfield */
#define XBAR_XBARMISC_MUXCFG_SWITCH_Pos (0U) /*!< MUXCFG_SWITCH Postion   0          */
#define XBAR_XBARMISC_MUXCFG_SWITCH_Msk \
    (0x1U << XBAR_XBARMISC_MUXCFG_SWITCH_Pos) /*!< MUXCFG_SWITCH Mask      0x00000001 */
#define XBAR_XBARMISC_MUXCFG_SWITCH_Set(x)                 \
    (((uint32_t) (x) << XBAR_XBARMISC_MUXCFG_SWITCH_Pos) & \
     XBAR_XBARMISC_MUXCFG_SWITCH_Msk) /*!< MUXCFG_SWITCH Set Value            */
#define XBAR_XBARMISC_MUXCFG_SWITCH_Get(x)                \
    (((uint32_t) (x) &XBAR_XBARMISC_MUXCFG_SWITCH_Msk) >> \
     XBAR_XBARMISC_MUXCFG_SWITCH_Pos) /*!< MUXCFG_SWITCH Get Value            */


/* TRIPMUX_MUX0TO15CFG bitfield */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX15_Pos (30U) /*!< MUX15 Postion   30         */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX15_Msk \
    (0x3U << EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX15_Pos) /*!< MUX15 Mask      0xC0000000 */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX15_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX15_Pos) & \
     EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX15_Msk) /*!< MUX15 Set Value            */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX15_Get(x)                \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX15_Msk) >> \
     EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX15_Pos) /*!< MUX15 Get Value            */


#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX14_Pos (28U) /*!< MUX14 Postion   28         */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX14_Msk \
    (0x3U << EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX14_Pos) /*!< MUX14 Mask      0x30000000 */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX14_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX14_Pos) & \
     EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX14_Msk) /*!< MUX14 Set Value            */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX14_Get(x)                \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX14_Msk) >> \
     EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX14_Pos) /*!< MUX14 Get Value            */


#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX13_Pos (26U) /*!< MUX13 Postion   26         */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX13_Msk \
    (0x3U << EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX13_Pos) /*!< MUX13 Mask      0x0C000000 */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX13_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX13_Pos) & \
     EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX13_Msk) /*!< MUX13 Set Value            */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX13_Get(x)                \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX13_Msk) >> \
     EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX13_Pos) /*!< MUX13 Get Value            */


#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX12_Pos (24U) /*!< MUX12 Postion   24         */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX12_Msk \
    (0x3U << EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX12_Pos) /*!< MUX12 Mask      0x03000000 */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX12_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX12_Pos) & \
     EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX12_Msk) /*!< MUX12 Set Value            */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX12_Get(x)                \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX12_Msk) >> \
     EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX12_Pos) /*!< MUX12 Get Value            */


#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX11_Pos (22U) /*!< MUX11 Postion   22         */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX11_Msk \
    (0x3U << EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX11_Pos) /*!< MUX11 Mask      0x00C00000 */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX11_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX11_Pos) & \
     EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX11_Msk) /*!< MUX11 Set Value            */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX11_Get(x)                \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX11_Msk) >> \
     EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX11_Pos) /*!< MUX11 Get Value            */


#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX10_Pos (20U) /*!< MUX10 Postion   20         */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX10_Msk \
    (0x3U << EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX10_Pos) /*!< MUX10 Mask      0x00300000 */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX10_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX10_Pos) & \
     EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX10_Msk) /*!< MUX10 Set Value            */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX10_Get(x)                \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX10_Msk) >> \
     EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX10_Pos) /*!< MUX10 Get Value            */


#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX9_Pos (18U) /*!< MUX9 Postion   18         */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX9_Msk \
    (0x3U << EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX9_Pos) /*!< MUX9 Mask      0x000C0000 */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX9_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX9_Pos) & \
     EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX9_Msk) /*!< MUX9 Set Value            */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX9_Get(x)                \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX9_Msk) >> \
     EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX9_Pos) /*!< MUX9 Get Value            */


#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX8_Pos (16U) /*!< MUX8 Postion   16         */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX8_Msk \
    (0x3U << EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX8_Pos) /*!< MUX8 Mask      0x00030000 */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX8_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX8_Pos) & \
     EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX8_Msk) /*!< MUX8 Set Value            */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX8_Get(x)                \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX8_Msk) >> \
     EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX8_Pos) /*!< MUX8 Get Value            */


#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX7_Pos (14U) /*!< MUX7 Postion   14         */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX7_Msk \
    (0x3U << EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX7_Pos) /*!< MUX7 Mask      0x0000C000 */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX7_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX7_Pos) & \
     EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX7_Msk) /*!< MUX7 Set Value            */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX7_Get(x)                \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX7_Msk) >> \
     EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX7_Pos) /*!< MUX7 Get Value            */


#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX6_Pos (12U) /*!< MUX6 Postion   12         */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX6_Msk \
    (0x3U << EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX6_Pos) /*!< MUX6 Mask      0x00003000 */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX6_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX6_Pos) & \
     EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX6_Msk) /*!< MUX6 Set Value            */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX6_Get(x)                \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX6_Msk) >> \
     EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX6_Pos) /*!< MUX6 Get Value            */


#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX5_Pos (10U) /*!< MUX5 Postion   10         */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX5_Msk \
    (0x3U << EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX5_Pos) /*!< MUX5 Mask      0x00000C00 */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX5_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX5_Pos) & \
     EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX5_Msk) /*!< MUX5 Set Value            */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX5_Get(x)                \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX5_Msk) >> \
     EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX5_Pos) /*!< MUX5 Get Value            */


#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX4_Pos (8U) /*!< MUX4 Postion   8          */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX4_Msk \
    (0x3U << EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX4_Pos) /*!< MUX4 Mask      0x00000300 */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX4_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX4_Pos) & \
     EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX4_Msk) /*!< MUX4 Set Value            */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX4_Get(x)                \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX4_Msk) >> \
     EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX4_Pos) /*!< MUX4 Get Value            */


#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX3_Pos (6U) /*!< MUX3 Postion   6          */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX3_Msk \
    (0x3U << EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX3_Pos) /*!< MUX3 Mask      0x000000C0 */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX3_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX3_Pos) & \
     EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX3_Msk) /*!< MUX3 Set Value            */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX3_Get(x)                \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX3_Msk) >> \
     EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX3_Pos) /*!< MUX3 Get Value            */


#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX2_Pos (4U) /*!< MUX2 Postion   4          */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX2_Msk \
    (0x3U << EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX2_Pos) /*!< MUX2 Mask      0x00000030 */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX2_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX2_Pos) & \
     EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX2_Msk) /*!< MUX2 Set Value            */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX2_Get(x)                \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX2_Msk) >> \
     EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX2_Pos) /*!< MUX2 Get Value            */


#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX1_Pos (2U) /*!< MUX1 Postion   2          */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX1_Msk \
    (0x3U << EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX1_Pos) /*!< MUX1 Mask      0x0000000C */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX1_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX1_Pos) & \
     EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX1_Msk) /*!< MUX1 Set Value            */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX1_Get(x)                \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX1_Msk) >> \
     EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX1_Pos) /*!< MUX1 Get Value            */


#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX0_Pos (0U) /*!< MUX0 Postion   0          */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX0_Msk \
    (0x3U << EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX0_Pos) /*!< MUX0 Mask      0x00000003 */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX0_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX0_Pos) & \
     EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX0_Msk) /*!< MUX0 Set Value            */
#define EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX0_Get(x)                \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX0_Msk) >> \
     EPWM_XBAR_TRIPMUX_MUX0TO15CFG_MUX0_Pos) /*!< MUX0 Get Value            */


/* TRIPMUX_MUX16TO31CFG bitfield */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX31_Pos (30U) /*!< MUX31 Postion   30         */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX31_Msk \
    (0x3U << EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX31_Pos) /*!< MUX31 Mask      0xC0000000 */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX31_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX31_Pos) & \
     EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX31_Msk) /*!< MUX31 Set Value            */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX31_Get(x)                \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX31_Msk) >> \
     EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX31_Pos) /*!< MUX31 Get Value            */


#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX30_Pos (28U) /*!< MUX30 Postion   28         */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX30_Msk \
    (0x3U << EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX30_Pos) /*!< MUX30 Mask      0x30000000 */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX30_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX30_Pos) & \
     EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX30_Msk) /*!< MUX30 Set Value            */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX30_Get(x)                \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX30_Msk) >> \
     EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX30_Pos) /*!< MUX30 Get Value            */


#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX29_Pos (26U) /*!< MUX29 Postion   26         */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX29_Msk \
    (0x3U << EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX29_Pos) /*!< MUX29 Mask      0x0C000000 */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX29_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX29_Pos) & \
     EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX29_Msk) /*!< MUX29 Set Value            */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX29_Get(x)                \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX29_Msk) >> \
     EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX29_Pos) /*!< MUX29 Get Value            */


#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX28_Pos (24U) /*!< MUX28 Postion   24         */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX28_Msk \
    (0x3U << EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX28_Pos) /*!< MUX28 Mask      0x03000000 */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX28_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX28_Pos) & \
     EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX28_Msk) /*!< MUX28 Set Value            */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX28_Get(x)                \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX28_Msk) >> \
     EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX28_Pos) /*!< MUX28 Get Value            */


#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX27_Pos (22U) /*!< MUX27 Postion   22         */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX27_Msk \
    (0x3U << EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX27_Pos) /*!< MUX27 Mask      0x00C00000 */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX27_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX27_Pos) & \
     EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX27_Msk) /*!< MUX27 Set Value            */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX27_Get(x)                \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX27_Msk) >> \
     EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX27_Pos) /*!< MUX27 Get Value            */


#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX26_Pos (20U) /*!< MUX26 Postion   20         */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX26_Msk \
    (0x3U << EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX26_Pos) /*!< MUX26 Mask      0x00300000 */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX26_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX26_Pos) & \
     EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX26_Msk) /*!< MUX26 Set Value            */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX26_Get(x)                \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX26_Msk) >> \
     EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX26_Pos) /*!< MUX26 Get Value            */


#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX25_Pos (18U) /*!< MUX25 Postion   18         */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX25_Msk \
    (0x3U << EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX25_Pos) /*!< MUX25 Mask      0x000C0000 */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX25_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX25_Pos) & \
     EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX25_Msk) /*!< MUX25 Set Value            */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX25_Get(x)                \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX25_Msk) >> \
     EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX25_Pos) /*!< MUX25 Get Value            */


#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX24_Pos (16U) /*!< MUX24 Postion   16         */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX24_Msk \
    (0x3U << EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX24_Pos) /*!< MUX24 Mask      0x00030000 */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX24_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX24_Pos) & \
     EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX24_Msk) /*!< MUX24 Set Value            */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX24_Get(x)                \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX24_Msk) >> \
     EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX24_Pos) /*!< MUX24 Get Value            */


#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX23_Pos (14U) /*!< MUX23 Postion   14         */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX23_Msk \
    (0x3U << EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX23_Pos) /*!< MUX23 Mask      0x0000C000 */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX23_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX23_Pos) & \
     EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX23_Msk) /*!< MUX23 Set Value            */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX23_Get(x)                \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX23_Msk) >> \
     EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX23_Pos) /*!< MUX23 Get Value            */


#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX22_Pos (12U) /*!< MUX22 Postion   12         */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX22_Msk \
    (0x3U << EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX22_Pos) /*!< MUX22 Mask      0x00003000 */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX22_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX22_Pos) & \
     EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX22_Msk) /*!< MUX22 Set Value            */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX22_Get(x)                \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX22_Msk) >> \
     EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX22_Pos) /*!< MUX22 Get Value            */


#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX21_Pos (10U) /*!< MUX21 Postion   10         */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX21_Msk \
    (0x3U << EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX21_Pos) /*!< MUX21 Mask      0x00000C00 */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX21_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX21_Pos) & \
     EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX21_Msk) /*!< MUX21 Set Value            */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX21_Get(x)                \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX21_Msk) >> \
     EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX21_Pos) /*!< MUX21 Get Value            */


#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX20_Pos (8U) /*!< MUX20 Postion   8          */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX20_Msk \
    (0x3U << EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX20_Pos) /*!< MUX20 Mask      0x00000300 */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX20_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX20_Pos) & \
     EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX20_Msk) /*!< MUX20 Set Value            */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX20_Get(x)                \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX20_Msk) >> \
     EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX20_Pos) /*!< MUX20 Get Value            */


#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX19_Pos (6U) /*!< MUX19 Postion   6          */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX19_Msk \
    (0x3U << EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX19_Pos) /*!< MUX19 Mask      0x000000C0 */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX19_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX19_Pos) & \
     EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX19_Msk) /*!< MUX19 Set Value            */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX19_Get(x)                \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX19_Msk) >> \
     EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX19_Pos) /*!< MUX19 Get Value            */


#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX18_Pos (4U) /*!< MUX18 Postion   4          */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX18_Msk \
    (0x3U << EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX18_Pos) /*!< MUX18 Mask      0x00000030 */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX18_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX18_Pos) & \
     EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX18_Msk) /*!< MUX18 Set Value            */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX18_Get(x)                \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX18_Msk) >> \
     EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX18_Pos) /*!< MUX18 Get Value            */


#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX17_Pos (2U) /*!< MUX17 Postion   2          */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX17_Msk \
    (0x3U << EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX17_Pos) /*!< MUX17 Mask      0x0000000C */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX17_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX17_Pos) & \
     EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX17_Msk) /*!< MUX17 Set Value            */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX17_Get(x)                \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX17_Msk) >> \
     EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX17_Pos) /*!< MUX17 Get Value            */


#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX16_Pos (0U) /*!< MUX16 Postion   0          */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX16_Msk \
    (0x3U << EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX16_Pos) /*!< MUX16 Mask      0x00000003 */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX16_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX16_Pos) & \
     EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX16_Msk) /*!< MUX16 Set Value            */
#define EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX16_Get(x)                \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX16_Msk) >> \
     EPWM_XBAR_TRIPMUX_MUX16TO31CFG_MUX16_Pos) /*!< MUX16 Get Value            */


/* TRIPMUXENABLE bitfield */
#define EPWM_XBAR_TRIPMUXENABLE_MUX31_Pos (31U) /*!< MUX31 Postion   31         */
#define EPWM_XBAR_TRIPMUXENABLE_MUX31_Msk                                       \
    (0x1U << EPWM_XBAR_TRIPMUXENABLE_MUX31_Pos) /*!< MUX31 Mask      0x80000000 \
                                                 */
#define EPWM_XBAR_TRIPMUXENABLE_MUX31_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUXENABLE_MUX31_Pos) & \
     EPWM_XBAR_TRIPMUXENABLE_MUX31_Msk) /*!< MUX31 Set Value            */
#define EPWM_XBAR_TRIPMUXENABLE_MUX31_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUXENABLE_MUX31_Msk) >> EPWM_XBAR_TRIPMUXENABLE_MUX31_Pos) /*!< MUX31 Get Value */


#define EPWM_XBAR_TRIPMUXENABLE_MUX30_Pos (30U) /*!< MUX30 Postion   30         */
#define EPWM_XBAR_TRIPMUXENABLE_MUX30_Msk                                       \
    (0x1U << EPWM_XBAR_TRIPMUXENABLE_MUX30_Pos) /*!< MUX30 Mask      0x40000000 \
                                                 */
#define EPWM_XBAR_TRIPMUXENABLE_MUX30_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUXENABLE_MUX30_Pos) & \
     EPWM_XBAR_TRIPMUXENABLE_MUX30_Msk) /*!< MUX30 Set Value            */
#define EPWM_XBAR_TRIPMUXENABLE_MUX30_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUXENABLE_MUX30_Msk) >> EPWM_XBAR_TRIPMUXENABLE_MUX30_Pos) /*!< MUX30 Get Value */


#define EPWM_XBAR_TRIPMUXENABLE_MUX29_Pos (29U) /*!< MUX29 Postion   29         */
#define EPWM_XBAR_TRIPMUXENABLE_MUX29_Msk                                       \
    (0x1U << EPWM_XBAR_TRIPMUXENABLE_MUX29_Pos) /*!< MUX29 Mask      0x20000000 \
                                                 */
#define EPWM_XBAR_TRIPMUXENABLE_MUX29_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUXENABLE_MUX29_Pos) & \
     EPWM_XBAR_TRIPMUXENABLE_MUX29_Msk) /*!< MUX29 Set Value            */
#define EPWM_XBAR_TRIPMUXENABLE_MUX29_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUXENABLE_MUX29_Msk) >> EPWM_XBAR_TRIPMUXENABLE_MUX29_Pos) /*!< MUX29 Get Value */


#define EPWM_XBAR_TRIPMUXENABLE_MUX28_Pos (28U) /*!< MUX28 Postion   28         */
#define EPWM_XBAR_TRIPMUXENABLE_MUX28_Msk                                       \
    (0x1U << EPWM_XBAR_TRIPMUXENABLE_MUX28_Pos) /*!< MUX28 Mask      0x10000000 \
                                                 */
#define EPWM_XBAR_TRIPMUXENABLE_MUX28_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUXENABLE_MUX28_Pos) & \
     EPWM_XBAR_TRIPMUXENABLE_MUX28_Msk) /*!< MUX28 Set Value            */
#define EPWM_XBAR_TRIPMUXENABLE_MUX28_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUXENABLE_MUX28_Msk) >> EPWM_XBAR_TRIPMUXENABLE_MUX28_Pos) /*!< MUX28 Get Value */


#define EPWM_XBAR_TRIPMUXENABLE_MUX27_Pos (27U) /*!< MUX27 Postion   27         */
#define EPWM_XBAR_TRIPMUXENABLE_MUX27_Msk                                       \
    (0x1U << EPWM_XBAR_TRIPMUXENABLE_MUX27_Pos) /*!< MUX27 Mask      0x08000000 \
                                                 */
#define EPWM_XBAR_TRIPMUXENABLE_MUX27_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUXENABLE_MUX27_Pos) & \
     EPWM_XBAR_TRIPMUXENABLE_MUX27_Msk) /*!< MUX27 Set Value            */
#define EPWM_XBAR_TRIPMUXENABLE_MUX27_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUXENABLE_MUX27_Msk) >> EPWM_XBAR_TRIPMUXENABLE_MUX27_Pos) /*!< MUX27 Get Value */


#define EPWM_XBAR_TRIPMUXENABLE_MUX26_Pos (26U) /*!< MUX26 Postion   26         */
#define EPWM_XBAR_TRIPMUXENABLE_MUX26_Msk                                       \
    (0x1U << EPWM_XBAR_TRIPMUXENABLE_MUX26_Pos) /*!< MUX26 Mask      0x04000000 \
                                                 */
#define EPWM_XBAR_TRIPMUXENABLE_MUX26_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUXENABLE_MUX26_Pos) & \
     EPWM_XBAR_TRIPMUXENABLE_MUX26_Msk) /*!< MUX26 Set Value            */
#define EPWM_XBAR_TRIPMUXENABLE_MUX26_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUXENABLE_MUX26_Msk) >> EPWM_XBAR_TRIPMUXENABLE_MUX26_Pos) /*!< MUX26 Get Value */


#define EPWM_XBAR_TRIPMUXENABLE_MUX25_Pos (25U) /*!< MUX25 Postion   25         */
#define EPWM_XBAR_TRIPMUXENABLE_MUX25_Msk                                       \
    (0x1U << EPWM_XBAR_TRIPMUXENABLE_MUX25_Pos) /*!< MUX25 Mask      0x02000000 \
                                                 */
#define EPWM_XBAR_TRIPMUXENABLE_MUX25_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUXENABLE_MUX25_Pos) & \
     EPWM_XBAR_TRIPMUXENABLE_MUX25_Msk) /*!< MUX25 Set Value            */
#define EPWM_XBAR_TRIPMUXENABLE_MUX25_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUXENABLE_MUX25_Msk) >> EPWM_XBAR_TRIPMUXENABLE_MUX25_Pos) /*!< MUX25 Get Value */


#define EPWM_XBAR_TRIPMUXENABLE_MUX24_Pos (24U) /*!< MUX24 Postion   24         */
#define EPWM_XBAR_TRIPMUXENABLE_MUX24_Msk                                       \
    (0x1U << EPWM_XBAR_TRIPMUXENABLE_MUX24_Pos) /*!< MUX24 Mask      0x01000000 \
                                                 */
#define EPWM_XBAR_TRIPMUXENABLE_MUX24_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUXENABLE_MUX24_Pos) & \
     EPWM_XBAR_TRIPMUXENABLE_MUX24_Msk) /*!< MUX24 Set Value            */
#define EPWM_XBAR_TRIPMUXENABLE_MUX24_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUXENABLE_MUX24_Msk) >> EPWM_XBAR_TRIPMUXENABLE_MUX24_Pos) /*!< MUX24 Get Value */


#define EPWM_XBAR_TRIPMUXENABLE_MUX23_Pos (23U) /*!< MUX23 Postion   23         */
#define EPWM_XBAR_TRIPMUXENABLE_MUX23_Msk                                       \
    (0x1U << EPWM_XBAR_TRIPMUXENABLE_MUX23_Pos) /*!< MUX23 Mask      0x00800000 \
                                                 */
#define EPWM_XBAR_TRIPMUXENABLE_MUX23_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUXENABLE_MUX23_Pos) & \
     EPWM_XBAR_TRIPMUXENABLE_MUX23_Msk) /*!< MUX23 Set Value            */
#define EPWM_XBAR_TRIPMUXENABLE_MUX23_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUXENABLE_MUX23_Msk) >> EPWM_XBAR_TRIPMUXENABLE_MUX23_Pos) /*!< MUX23 Get Value */


#define EPWM_XBAR_TRIPMUXENABLE_MUX22_Pos (22U) /*!< MUX22 Postion   22         */
#define EPWM_XBAR_TRIPMUXENABLE_MUX22_Msk                                       \
    (0x1U << EPWM_XBAR_TRIPMUXENABLE_MUX22_Pos) /*!< MUX22 Mask      0x00400000 \
                                                 */
#define EPWM_XBAR_TRIPMUXENABLE_MUX22_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUXENABLE_MUX22_Pos) & \
     EPWM_XBAR_TRIPMUXENABLE_MUX22_Msk) /*!< MUX22 Set Value            */
#define EPWM_XBAR_TRIPMUXENABLE_MUX22_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUXENABLE_MUX22_Msk) >> EPWM_XBAR_TRIPMUXENABLE_MUX22_Pos) /*!< MUX22 Get Value */


#define EPWM_XBAR_TRIPMUXENABLE_MUX21_Pos (21U) /*!< MUX21 Postion   21         */
#define EPWM_XBAR_TRIPMUXENABLE_MUX21_Msk                                       \
    (0x1U << EPWM_XBAR_TRIPMUXENABLE_MUX21_Pos) /*!< MUX21 Mask      0x00200000 \
                                                 */
#define EPWM_XBAR_TRIPMUXENABLE_MUX21_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUXENABLE_MUX21_Pos) & \
     EPWM_XBAR_TRIPMUXENABLE_MUX21_Msk) /*!< MUX21 Set Value            */
#define EPWM_XBAR_TRIPMUXENABLE_MUX21_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUXENABLE_MUX21_Msk) >> EPWM_XBAR_TRIPMUXENABLE_MUX21_Pos) /*!< MUX21 Get Value */


#define EPWM_XBAR_TRIPMUXENABLE_MUX20_Pos (20U) /*!< MUX20 Postion   20         */
#define EPWM_XBAR_TRIPMUXENABLE_MUX20_Msk                                       \
    (0x1U << EPWM_XBAR_TRIPMUXENABLE_MUX20_Pos) /*!< MUX20 Mask      0x00100000 \
                                                 */
#define EPWM_XBAR_TRIPMUXENABLE_MUX20_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUXENABLE_MUX20_Pos) & \
     EPWM_XBAR_TRIPMUXENABLE_MUX20_Msk) /*!< MUX20 Set Value            */
#define EPWM_XBAR_TRIPMUXENABLE_MUX20_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUXENABLE_MUX20_Msk) >> EPWM_XBAR_TRIPMUXENABLE_MUX20_Pos) /*!< MUX20 Get Value */


#define EPWM_XBAR_TRIPMUXENABLE_MUX19_Pos (19U) /*!< MUX19 Postion   19         */
#define EPWM_XBAR_TRIPMUXENABLE_MUX19_Msk                                       \
    (0x1U << EPWM_XBAR_TRIPMUXENABLE_MUX19_Pos) /*!< MUX19 Mask      0x00080000 \
                                                 */
#define EPWM_XBAR_TRIPMUXENABLE_MUX19_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUXENABLE_MUX19_Pos) & \
     EPWM_XBAR_TRIPMUXENABLE_MUX19_Msk) /*!< MUX19 Set Value            */
#define EPWM_XBAR_TRIPMUXENABLE_MUX19_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUXENABLE_MUX19_Msk) >> EPWM_XBAR_TRIPMUXENABLE_MUX19_Pos) /*!< MUX19 Get Value */


#define EPWM_XBAR_TRIPMUXENABLE_MUX18_Pos (18U) /*!< MUX18 Postion   18         */
#define EPWM_XBAR_TRIPMUXENABLE_MUX18_Msk                                       \
    (0x1U << EPWM_XBAR_TRIPMUXENABLE_MUX18_Pos) /*!< MUX18 Mask      0x00040000 \
                                                 */
#define EPWM_XBAR_TRIPMUXENABLE_MUX18_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUXENABLE_MUX18_Pos) & \
     EPWM_XBAR_TRIPMUXENABLE_MUX18_Msk) /*!< MUX18 Set Value            */
#define EPWM_XBAR_TRIPMUXENABLE_MUX18_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUXENABLE_MUX18_Msk) >> EPWM_XBAR_TRIPMUXENABLE_MUX18_Pos) /*!< MUX18 Get Value */


#define EPWM_XBAR_TRIPMUXENABLE_MUX17_Pos (17U) /*!< MUX17 Postion   17         */
#define EPWM_XBAR_TRIPMUXENABLE_MUX17_Msk                                       \
    (0x1U << EPWM_XBAR_TRIPMUXENABLE_MUX17_Pos) /*!< MUX17 Mask      0x00020000 \
                                                 */
#define EPWM_XBAR_TRIPMUXENABLE_MUX17_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUXENABLE_MUX17_Pos) & \
     EPWM_XBAR_TRIPMUXENABLE_MUX17_Msk) /*!< MUX17 Set Value            */
#define EPWM_XBAR_TRIPMUXENABLE_MUX17_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUXENABLE_MUX17_Msk) >> EPWM_XBAR_TRIPMUXENABLE_MUX17_Pos) /*!< MUX17 Get Value */


#define EPWM_XBAR_TRIPMUXENABLE_MUX16_Pos (16U) /*!< MUX16 Postion   16         */
#define EPWM_XBAR_TRIPMUXENABLE_MUX16_Msk                                       \
    (0x1U << EPWM_XBAR_TRIPMUXENABLE_MUX16_Pos) /*!< MUX16 Mask      0x00010000 \
                                                 */
#define EPWM_XBAR_TRIPMUXENABLE_MUX16_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUXENABLE_MUX16_Pos) & \
     EPWM_XBAR_TRIPMUXENABLE_MUX16_Msk) /*!< MUX16 Set Value            */
#define EPWM_XBAR_TRIPMUXENABLE_MUX16_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUXENABLE_MUX16_Msk) >> EPWM_XBAR_TRIPMUXENABLE_MUX16_Pos) /*!< MUX16 Get Value */


#define EPWM_XBAR_TRIPMUXENABLE_MUX15_Pos (15U) /*!< MUX15 Postion   15         */
#define EPWM_XBAR_TRIPMUXENABLE_MUX15_Msk                                       \
    (0x1U << EPWM_XBAR_TRIPMUXENABLE_MUX15_Pos) /*!< MUX15 Mask      0x00008000 \
                                                 */
#define EPWM_XBAR_TRIPMUXENABLE_MUX15_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUXENABLE_MUX15_Pos) & \
     EPWM_XBAR_TRIPMUXENABLE_MUX15_Msk) /*!< MUX15 Set Value            */
#define EPWM_XBAR_TRIPMUXENABLE_MUX15_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUXENABLE_MUX15_Msk) >> EPWM_XBAR_TRIPMUXENABLE_MUX15_Pos) /*!< MUX15 Get Value */


#define EPWM_XBAR_TRIPMUXENABLE_MUX14_Pos (14U) /*!< MUX14 Postion   14         */
#define EPWM_XBAR_TRIPMUXENABLE_MUX14_Msk                                       \
    (0x1U << EPWM_XBAR_TRIPMUXENABLE_MUX14_Pos) /*!< MUX14 Mask      0x00004000 \
                                                 */
#define EPWM_XBAR_TRIPMUXENABLE_MUX14_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUXENABLE_MUX14_Pos) & \
     EPWM_XBAR_TRIPMUXENABLE_MUX14_Msk) /*!< MUX14 Set Value            */
#define EPWM_XBAR_TRIPMUXENABLE_MUX14_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUXENABLE_MUX14_Msk) >> EPWM_XBAR_TRIPMUXENABLE_MUX14_Pos) /*!< MUX14 Get Value */


#define EPWM_XBAR_TRIPMUXENABLE_MUX13_Pos (13U) /*!< MUX13 Postion   13         */
#define EPWM_XBAR_TRIPMUXENABLE_MUX13_Msk                                       \
    (0x1U << EPWM_XBAR_TRIPMUXENABLE_MUX13_Pos) /*!< MUX13 Mask      0x00002000 \
                                                 */
#define EPWM_XBAR_TRIPMUXENABLE_MUX13_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUXENABLE_MUX13_Pos) & \
     EPWM_XBAR_TRIPMUXENABLE_MUX13_Msk) /*!< MUX13 Set Value            */
#define EPWM_XBAR_TRIPMUXENABLE_MUX13_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUXENABLE_MUX13_Msk) >> EPWM_XBAR_TRIPMUXENABLE_MUX13_Pos) /*!< MUX13 Get Value */


#define EPWM_XBAR_TRIPMUXENABLE_MUX12_Pos (12U) /*!< MUX12 Postion   12         */
#define EPWM_XBAR_TRIPMUXENABLE_MUX12_Msk                                       \
    (0x1U << EPWM_XBAR_TRIPMUXENABLE_MUX12_Pos) /*!< MUX12 Mask      0x00001000 \
                                                 */
#define EPWM_XBAR_TRIPMUXENABLE_MUX12_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUXENABLE_MUX12_Pos) & \
     EPWM_XBAR_TRIPMUXENABLE_MUX12_Msk) /*!< MUX12 Set Value            */
#define EPWM_XBAR_TRIPMUXENABLE_MUX12_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUXENABLE_MUX12_Msk) >> EPWM_XBAR_TRIPMUXENABLE_MUX12_Pos) /*!< MUX12 Get Value */


#define EPWM_XBAR_TRIPMUXENABLE_MUX11_Pos (11U) /*!< MUX11 Postion   11         */
#define EPWM_XBAR_TRIPMUXENABLE_MUX11_Msk                                       \
    (0x1U << EPWM_XBAR_TRIPMUXENABLE_MUX11_Pos) /*!< MUX11 Mask      0x00000800 \
                                                 */
#define EPWM_XBAR_TRIPMUXENABLE_MUX11_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUXENABLE_MUX11_Pos) & \
     EPWM_XBAR_TRIPMUXENABLE_MUX11_Msk) /*!< MUX11 Set Value            */
#define EPWM_XBAR_TRIPMUXENABLE_MUX11_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUXENABLE_MUX11_Msk) >> EPWM_XBAR_TRIPMUXENABLE_MUX11_Pos) /*!< MUX11 Get Value */


#define EPWM_XBAR_TRIPMUXENABLE_MUX10_Pos (10U) /*!< MUX10 Postion   10         */
#define EPWM_XBAR_TRIPMUXENABLE_MUX10_Msk                                       \
    (0x1U << EPWM_XBAR_TRIPMUXENABLE_MUX10_Pos) /*!< MUX10 Mask      0x00000400 \
                                                 */
#define EPWM_XBAR_TRIPMUXENABLE_MUX10_Set(x)                 \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUXENABLE_MUX10_Pos) & \
     EPWM_XBAR_TRIPMUXENABLE_MUX10_Msk) /*!< MUX10 Set Value            */
#define EPWM_XBAR_TRIPMUXENABLE_MUX10_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUXENABLE_MUX10_Msk) >> EPWM_XBAR_TRIPMUXENABLE_MUX10_Pos) /*!< MUX10 Get Value */


#define EPWM_XBAR_TRIPMUXENABLE_MUX9_Pos (9U)                                       /*!< MUX9 Postion   9          */
#define EPWM_XBAR_TRIPMUXENABLE_MUX9_Msk (0x1U << EPWM_XBAR_TRIPMUXENABLE_MUX9_Pos) /*!< MUX9 Mask      0x00000200 */
#define EPWM_XBAR_TRIPMUXENABLE_MUX9_Set(x) \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUXENABLE_MUX9_Pos) & EPWM_XBAR_TRIPMUXENABLE_MUX9_Msk) /*!< MUX9 Set Value */
#define EPWM_XBAR_TRIPMUXENABLE_MUX9_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUXENABLE_MUX9_Msk) >> EPWM_XBAR_TRIPMUXENABLE_MUX9_Pos) /*!< MUX9 Get Value */


#define EPWM_XBAR_TRIPMUXENABLE_MUX8_Pos (8U)                                       /*!< MUX8 Postion   8          */
#define EPWM_XBAR_TRIPMUXENABLE_MUX8_Msk (0x1U << EPWM_XBAR_TRIPMUXENABLE_MUX8_Pos) /*!< MUX8 Mask      0x00000100 */
#define EPWM_XBAR_TRIPMUXENABLE_MUX8_Set(x) \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUXENABLE_MUX8_Pos) & EPWM_XBAR_TRIPMUXENABLE_MUX8_Msk) /*!< MUX8 Set Value */
#define EPWM_XBAR_TRIPMUXENABLE_MUX8_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUXENABLE_MUX8_Msk) >> EPWM_XBAR_TRIPMUXENABLE_MUX8_Pos) /*!< MUX8 Get Value */


#define EPWM_XBAR_TRIPMUXENABLE_MUX7_Pos (7U)                                       /*!< MUX7 Postion   7          */
#define EPWM_XBAR_TRIPMUXENABLE_MUX7_Msk (0x1U << EPWM_XBAR_TRIPMUXENABLE_MUX7_Pos) /*!< MUX7 Mask      0x00000080 */
#define EPWM_XBAR_TRIPMUXENABLE_MUX7_Set(x) \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUXENABLE_MUX7_Pos) & EPWM_XBAR_TRIPMUXENABLE_MUX7_Msk) /*!< MUX7 Set Value */
#define EPWM_XBAR_TRIPMUXENABLE_MUX7_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUXENABLE_MUX7_Msk) >> EPWM_XBAR_TRIPMUXENABLE_MUX7_Pos) /*!< MUX7 Get Value */


#define EPWM_XBAR_TRIPMUXENABLE_MUX6_Pos (6U)                                       /*!< MUX6 Postion   6          */
#define EPWM_XBAR_TRIPMUXENABLE_MUX6_Msk (0x1U << EPWM_XBAR_TRIPMUXENABLE_MUX6_Pos) /*!< MUX6 Mask      0x00000040 */
#define EPWM_XBAR_TRIPMUXENABLE_MUX6_Set(x) \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUXENABLE_MUX6_Pos) & EPWM_XBAR_TRIPMUXENABLE_MUX6_Msk) /*!< MUX6 Set Value */
#define EPWM_XBAR_TRIPMUXENABLE_MUX6_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUXENABLE_MUX6_Msk) >> EPWM_XBAR_TRIPMUXENABLE_MUX6_Pos) /*!< MUX6 Get Value */


#define EPWM_XBAR_TRIPMUXENABLE_MUX5_Pos (5U)                                       /*!< MUX5 Postion   5          */
#define EPWM_XBAR_TRIPMUXENABLE_MUX5_Msk (0x1U << EPWM_XBAR_TRIPMUXENABLE_MUX5_Pos) /*!< MUX5 Mask      0x00000020 */
#define EPWM_XBAR_TRIPMUXENABLE_MUX5_Set(x) \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUXENABLE_MUX5_Pos) & EPWM_XBAR_TRIPMUXENABLE_MUX5_Msk) /*!< MUX5 Set Value */
#define EPWM_XBAR_TRIPMUXENABLE_MUX5_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUXENABLE_MUX5_Msk) >> EPWM_XBAR_TRIPMUXENABLE_MUX5_Pos) /*!< MUX5 Get Value */


#define EPWM_XBAR_TRIPMUXENABLE_MUX4_Pos (4U)                                       /*!< MUX4 Postion   4          */
#define EPWM_XBAR_TRIPMUXENABLE_MUX4_Msk (0x1U << EPWM_XBAR_TRIPMUXENABLE_MUX4_Pos) /*!< MUX4 Mask      0x00000010 */
#define EPWM_XBAR_TRIPMUXENABLE_MUX4_Set(x) \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUXENABLE_MUX4_Pos) & EPWM_XBAR_TRIPMUXENABLE_MUX4_Msk) /*!< MUX4 Set Value */
#define EPWM_XBAR_TRIPMUXENABLE_MUX4_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUXENABLE_MUX4_Msk) >> EPWM_XBAR_TRIPMUXENABLE_MUX4_Pos) /*!< MUX4 Get Value */


#define EPWM_XBAR_TRIPMUXENABLE_MUX3_Pos (3U)                                       /*!< MUX3 Postion   3          */
#define EPWM_XBAR_TRIPMUXENABLE_MUX3_Msk (0x1U << EPWM_XBAR_TRIPMUXENABLE_MUX3_Pos) /*!< MUX3 Mask      0x00000008 */
#define EPWM_XBAR_TRIPMUXENABLE_MUX3_Set(x) \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUXENABLE_MUX3_Pos) & EPWM_XBAR_TRIPMUXENABLE_MUX3_Msk) /*!< MUX3 Set Value */
#define EPWM_XBAR_TRIPMUXENABLE_MUX3_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUXENABLE_MUX3_Msk) >> EPWM_XBAR_TRIPMUXENABLE_MUX3_Pos) /*!< MUX3 Get Value */


#define EPWM_XBAR_TRIPMUXENABLE_MUX2_Pos (2U)                                       /*!< MUX2 Postion   2          */
#define EPWM_XBAR_TRIPMUXENABLE_MUX2_Msk (0x1U << EPWM_XBAR_TRIPMUXENABLE_MUX2_Pos) /*!< MUX2 Mask      0x00000004 */
#define EPWM_XBAR_TRIPMUXENABLE_MUX2_Set(x) \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUXENABLE_MUX2_Pos) & EPWM_XBAR_TRIPMUXENABLE_MUX2_Msk) /*!< MUX2 Set Value */
#define EPWM_XBAR_TRIPMUXENABLE_MUX2_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUXENABLE_MUX2_Msk) >> EPWM_XBAR_TRIPMUXENABLE_MUX2_Pos) /*!< MUX2 Get Value */


#define EPWM_XBAR_TRIPMUXENABLE_MUX1_Pos (1U)                                       /*!< MUX1 Postion   1          */
#define EPWM_XBAR_TRIPMUXENABLE_MUX1_Msk (0x1U << EPWM_XBAR_TRIPMUXENABLE_MUX1_Pos) /*!< MUX1 Mask      0x00000002 */
#define EPWM_XBAR_TRIPMUXENABLE_MUX1_Set(x) \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUXENABLE_MUX1_Pos) & EPWM_XBAR_TRIPMUXENABLE_MUX1_Msk) /*!< MUX1 Set Value */
#define EPWM_XBAR_TRIPMUXENABLE_MUX1_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUXENABLE_MUX1_Msk) >> EPWM_XBAR_TRIPMUXENABLE_MUX1_Pos) /*!< MUX1 Get Value */


#define EPWM_XBAR_TRIPMUXENABLE_MUX0_Pos (0U)                                       /*!< MUX0 Postion   0          */
#define EPWM_XBAR_TRIPMUXENABLE_MUX0_Msk (0x1U << EPWM_XBAR_TRIPMUXENABLE_MUX0_Pos) /*!< MUX0 Mask      0x00000001 */
#define EPWM_XBAR_TRIPMUXENABLE_MUX0_Set(x) \
    (((uint32_t) (x) << EPWM_XBAR_TRIPMUXENABLE_MUX0_Pos) & EPWM_XBAR_TRIPMUXENABLE_MUX0_Msk) /*!< MUX0 Set Value */
#define EPWM_XBAR_TRIPMUXENABLE_MUX0_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPMUXENABLE_MUX0_Msk) >> EPWM_XBAR_TRIPMUXENABLE_MUX0_Pos) /*!< MUX0 Get Value */


/* TRIPOUTINV bitfield */
#define EPWM_XBAR_TRIPOUTINV_TRIP12_Pos (7U)                                      /*!< TRIP12 Postion   7          */
#define EPWM_XBAR_TRIPOUTINV_TRIP12_Msk (0x1U << EPWM_XBAR_TRIPOUTINV_TRIP12_Pos) /*!< TRIP12 Mask      0x00000080 */
#define EPWM_XBAR_TRIPOUTINV_TRIP12_Set(x) \
    (((uint32_t) (x) << EPWM_XBAR_TRIPOUTINV_TRIP12_Pos) & EPWM_XBAR_TRIPOUTINV_TRIP12_Msk) /*!< TRIP12 Set Value */
#define EPWM_XBAR_TRIPOUTINV_TRIP12_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPOUTINV_TRIP12_Msk) >> EPWM_XBAR_TRIPOUTINV_TRIP12_Pos) /*!< TRIP12 Get Value */


#define EPWM_XBAR_TRIPOUTINV_TRIP11_Pos (6U)                                      /*!< TRIP11 Postion   6          */
#define EPWM_XBAR_TRIPOUTINV_TRIP11_Msk (0x1U << EPWM_XBAR_TRIPOUTINV_TRIP11_Pos) /*!< TRIP11 Mask      0x00000040 */
#define EPWM_XBAR_TRIPOUTINV_TRIP11_Set(x) \
    (((uint32_t) (x) << EPWM_XBAR_TRIPOUTINV_TRIP11_Pos) & EPWM_XBAR_TRIPOUTINV_TRIP11_Msk) /*!< TRIP11 Set Value */
#define EPWM_XBAR_TRIPOUTINV_TRIP11_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPOUTINV_TRIP11_Msk) >> EPWM_XBAR_TRIPOUTINV_TRIP11_Pos) /*!< TRIP11 Get Value */


#define EPWM_XBAR_TRIPOUTINV_TRIP10_Pos (5U)                                      /*!< TRIP10 Postion   5          */
#define EPWM_XBAR_TRIPOUTINV_TRIP10_Msk (0x1U << EPWM_XBAR_TRIPOUTINV_TRIP10_Pos) /*!< TRIP10 Mask      0x00000020 */
#define EPWM_XBAR_TRIPOUTINV_TRIP10_Set(x) \
    (((uint32_t) (x) << EPWM_XBAR_TRIPOUTINV_TRIP10_Pos) & EPWM_XBAR_TRIPOUTINV_TRIP10_Msk) /*!< TRIP10 Set Value */
#define EPWM_XBAR_TRIPOUTINV_TRIP10_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPOUTINV_TRIP10_Msk) >> EPWM_XBAR_TRIPOUTINV_TRIP10_Pos) /*!< TRIP10 Get Value */


#define EPWM_XBAR_TRIPOUTINV_TRIP9_Pos (4U)                                     /*!< TRIP9 Postion   4          */
#define EPWM_XBAR_TRIPOUTINV_TRIP9_Msk (0x1U << EPWM_XBAR_TRIPOUTINV_TRIP9_Pos) /*!< TRIP9 Mask      0x00000010 */
#define EPWM_XBAR_TRIPOUTINV_TRIP9_Set(x) \
    (((uint32_t) (x) << EPWM_XBAR_TRIPOUTINV_TRIP9_Pos) & EPWM_XBAR_TRIPOUTINV_TRIP9_Msk) /*!< TRIP9 Set Value */
#define EPWM_XBAR_TRIPOUTINV_TRIP9_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPOUTINV_TRIP9_Msk) >> EPWM_XBAR_TRIPOUTINV_TRIP9_Pos) /*!< TRIP9 Get Value */


#define EPWM_XBAR_TRIPOUTINV_TRIP8_Pos (3U)                                     /*!< TRIP8 Postion   3          */
#define EPWM_XBAR_TRIPOUTINV_TRIP8_Msk (0x1U << EPWM_XBAR_TRIPOUTINV_TRIP8_Pos) /*!< TRIP8 Mask      0x00000008 */
#define EPWM_XBAR_TRIPOUTINV_TRIP8_Set(x) \
    (((uint32_t) (x) << EPWM_XBAR_TRIPOUTINV_TRIP8_Pos) & EPWM_XBAR_TRIPOUTINV_TRIP8_Msk) /*!< TRIP8 Set Value */
#define EPWM_XBAR_TRIPOUTINV_TRIP8_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPOUTINV_TRIP8_Msk) >> EPWM_XBAR_TRIPOUTINV_TRIP8_Pos) /*!< TRIP8 Get Value */


#define EPWM_XBAR_TRIPOUTINV_TRIP7_Pos (2U)                                     /*!< TRIP7 Postion   2          */
#define EPWM_XBAR_TRIPOUTINV_TRIP7_Msk (0x1U << EPWM_XBAR_TRIPOUTINV_TRIP7_Pos) /*!< TRIP7 Mask      0x00000004 */
#define EPWM_XBAR_TRIPOUTINV_TRIP7_Set(x) \
    (((uint32_t) (x) << EPWM_XBAR_TRIPOUTINV_TRIP7_Pos) & EPWM_XBAR_TRIPOUTINV_TRIP7_Msk) /*!< TRIP7 Set Value */
#define EPWM_XBAR_TRIPOUTINV_TRIP7_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPOUTINV_TRIP7_Msk) >> EPWM_XBAR_TRIPOUTINV_TRIP7_Pos) /*!< TRIP7 Get Value */


#define EPWM_XBAR_TRIPOUTINV_TRIP5_Pos (1U)                                     /*!< TRIP5 Postion   1          */
#define EPWM_XBAR_TRIPOUTINV_TRIP5_Msk (0x1U << EPWM_XBAR_TRIPOUTINV_TRIP5_Pos) /*!< TRIP5 Mask      0x00000002 */
#define EPWM_XBAR_TRIPOUTINV_TRIP5_Set(x) \
    (((uint32_t) (x) << EPWM_XBAR_TRIPOUTINV_TRIP5_Pos) & EPWM_XBAR_TRIPOUTINV_TRIP5_Msk) /*!< TRIP5 Set Value */
#define EPWM_XBAR_TRIPOUTINV_TRIP5_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPOUTINV_TRIP5_Msk) >> EPWM_XBAR_TRIPOUTINV_TRIP5_Pos) /*!< TRIP5 Get Value */


#define EPWM_XBAR_TRIPOUTINV_TRIP4_Pos (0U)                                     /*!< TRIP4 Postion   0          */
#define EPWM_XBAR_TRIPOUTINV_TRIP4_Msk (0x1U << EPWM_XBAR_TRIPOUTINV_TRIP4_Pos) /*!< TRIP4 Mask      0x00000001 */
#define EPWM_XBAR_TRIPOUTINV_TRIP4_Set(x) \
    (((uint32_t) (x) << EPWM_XBAR_TRIPOUTINV_TRIP4_Pos) & EPWM_XBAR_TRIPOUTINV_TRIP4_Msk) /*!< TRIP4 Set Value */
#define EPWM_XBAR_TRIPOUTINV_TRIP4_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPOUTINV_TRIP4_Msk) >> EPWM_XBAR_TRIPOUTINV_TRIP4_Pos) /*!< TRIP4 Get Value */


/* TRIPLOCK bitfield */
#define EPWM_XBAR_TRIPLOCK_KEY_Pos (16U)                                   /*!< KEY Postion   16         */
#define EPWM_XBAR_TRIPLOCK_KEY_Msk (0xffffU << EPWM_XBAR_TRIPLOCK_KEY_Pos) /*!< KEY Mask      0xFFFF0000 */
#define EPWM_XBAR_TRIPLOCK_KEY_Set(x) \
    (((uint32_t) (x) << EPWM_XBAR_TRIPLOCK_KEY_Pos) & EPWM_XBAR_TRIPLOCK_KEY_Msk) /*!< KEY Set Value            */
#define EPWM_XBAR_TRIPLOCK_KEY_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPLOCK_KEY_Msk) >> EPWM_XBAR_TRIPLOCK_KEY_Pos) /*!< KEY Get Value            */


#define EPWM_XBAR_TRIPLOCK_LOCK_Pos (0U)                                  /*!< LOCK Postion   0          */
#define EPWM_XBAR_TRIPLOCK_LOCK_Msk (0x1U << EPWM_XBAR_TRIPLOCK_LOCK_Pos) /*!< LOCK Mask      0x00000001 */
#define EPWM_XBAR_TRIPLOCK_LOCK_Set(x) \
    (((uint32_t) (x) << EPWM_XBAR_TRIPLOCK_LOCK_Pos) & EPWM_XBAR_TRIPLOCK_LOCK_Msk) /*!< LOCK Set Value            */
#define EPWM_XBAR_TRIPLOCK_LOCK_Get(x) \
    (((uint32_t) (x) &EPWM_XBAR_TRIPLOCK_LOCK_Msk) >> EPWM_XBAR_TRIPLOCK_LOCK_Pos) /*!< LOCK Get Value            */


/* AUXSIGMUX_MUX0TO15CFG bitfield */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX15_Pos (30U) /*!< MUX15 Postion   30         */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX15_Msk \
    (0x3U << CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX15_Pos) /*!< MUX15 Mask      0xC0000000 */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX15_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX15_Pos) & \
     CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX15_Msk) /*!< MUX15 Set Value            */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX15_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX15_Msk) >> \
     CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX15_Pos) /*!< MUX15 Get Value            */


#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX14_Pos (28U) /*!< MUX14 Postion   28         */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX14_Msk \
    (0x3U << CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX14_Pos) /*!< MUX14 Mask      0x30000000 */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX14_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX14_Pos) & \
     CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX14_Msk) /*!< MUX14 Set Value            */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX14_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX14_Msk) >> \
     CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX14_Pos) /*!< MUX14 Get Value            */


#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX13_Pos (26U) /*!< MUX13 Postion   26         */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX13_Msk \
    (0x3U << CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX13_Pos) /*!< MUX13 Mask      0x0C000000 */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX13_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX13_Pos) & \
     CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX13_Msk) /*!< MUX13 Set Value            */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX13_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX13_Msk) >> \
     CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX13_Pos) /*!< MUX13 Get Value            */


#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX12_Pos (24U) /*!< MUX12 Postion   24         */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX12_Msk \
    (0x3U << CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX12_Pos) /*!< MUX12 Mask      0x03000000 */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX12_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX12_Pos) & \
     CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX12_Msk) /*!< MUX12 Set Value            */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX12_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX12_Msk) >> \
     CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX12_Pos) /*!< MUX12 Get Value            */


#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX11_Pos (22U) /*!< MUX11 Postion   22         */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX11_Msk \
    (0x3U << CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX11_Pos) /*!< MUX11 Mask      0x00C00000 */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX11_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX11_Pos) & \
     CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX11_Msk) /*!< MUX11 Set Value            */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX11_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX11_Msk) >> \
     CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX11_Pos) /*!< MUX11 Get Value            */


#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX10_Pos (20U) /*!< MUX10 Postion   20         */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX10_Msk \
    (0x3U << CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX10_Pos) /*!< MUX10 Mask      0x00300000 */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX10_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX10_Pos) & \
     CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX10_Msk) /*!< MUX10 Set Value            */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX10_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX10_Msk) >> \
     CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX10_Pos) /*!< MUX10 Get Value            */


#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX9_Pos (18U) /*!< MUX9 Postion   18         */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX9_Msk \
    (0x3U << CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX9_Pos) /*!< MUX9 Mask      0x000C0000 */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX9_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX9_Pos) & \
     CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX9_Msk) /*!< MUX9 Set Value            */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX9_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX9_Msk) >> \
     CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX9_Pos) /*!< MUX9 Get Value            */


#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX8_Pos (16U) /*!< MUX8 Postion   16         */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX8_Msk \
    (0x3U << CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX8_Pos) /*!< MUX8 Mask      0x00030000 */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX8_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX8_Pos) & \
     CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX8_Msk) /*!< MUX8 Set Value            */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX8_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX8_Msk) >> \
     CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX8_Pos) /*!< MUX8 Get Value            */


#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX7_Pos (14U) /*!< MUX7 Postion   14         */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX7_Msk \
    (0x3U << CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX7_Pos) /*!< MUX7 Mask      0x0000C000 */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX7_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX7_Pos) & \
     CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX7_Msk) /*!< MUX7 Set Value            */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX7_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX7_Msk) >> \
     CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX7_Pos) /*!< MUX7 Get Value            */


#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX6_Pos (12U) /*!< MUX6 Postion   12         */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX6_Msk \
    (0x3U << CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX6_Pos) /*!< MUX6 Mask      0x00003000 */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX6_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX6_Pos) & \
     CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX6_Msk) /*!< MUX6 Set Value            */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX6_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX6_Msk) >> \
     CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX6_Pos) /*!< MUX6 Get Value            */


#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX5_Pos (10U) /*!< MUX5 Postion   10         */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX5_Msk \
    (0x3U << CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX5_Pos) /*!< MUX5 Mask      0x00000C00 */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX5_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX5_Pos) & \
     CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX5_Msk) /*!< MUX5 Set Value            */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX5_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX5_Msk) >> \
     CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX5_Pos) /*!< MUX5 Get Value            */


#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX4_Pos (8U) /*!< MUX4 Postion   8          */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX4_Msk \
    (0x3U << CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX4_Pos) /*!< MUX4 Mask      0x00000300 */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX4_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX4_Pos) & \
     CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX4_Msk) /*!< MUX4 Set Value            */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX4_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX4_Msk) >> \
     CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX4_Pos) /*!< MUX4 Get Value            */


#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX3_Pos (6U) /*!< MUX3 Postion   6          */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX3_Msk \
    (0x3U << CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX3_Pos) /*!< MUX3 Mask      0x000000C0 */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX3_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX3_Pos) & \
     CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX3_Msk) /*!< MUX3 Set Value            */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX3_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX3_Msk) >> \
     CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX3_Pos) /*!< MUX3 Get Value            */


#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX2_Pos (4U) /*!< MUX2 Postion   4          */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX2_Msk \
    (0x3U << CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX2_Pos) /*!< MUX2 Mask      0x00000030 */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX2_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX2_Pos) & \
     CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX2_Msk) /*!< MUX2 Set Value            */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX2_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX2_Msk) >> \
     CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX2_Pos) /*!< MUX2 Get Value            */


#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX1_Pos (2U) /*!< MUX1 Postion   2          */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX1_Msk \
    (0x3U << CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX1_Pos) /*!< MUX1 Mask      0x0000000C */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX1_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX1_Pos) & \
     CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX1_Msk) /*!< MUX1 Set Value            */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX1_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX1_Msk) >> \
     CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX1_Pos) /*!< MUX1 Get Value            */


#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX0_Pos (0U) /*!< MUX0 Postion   0          */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX0_Msk \
    (0x3U << CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX0_Pos) /*!< MUX0 Mask      0x00000003 */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX0_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX0_Pos) & \
     CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX0_Msk) /*!< MUX0 Set Value            */
#define CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX0_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX0_Msk) >> \
     CLB_XBAR_AUXSIGMUX_MUX0TO15CFG_MUX0_Pos) /*!< MUX0 Get Value            */


/* AUXSIGMUX_MUX16TO31CFG bitfield */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX31_Pos (30U) /*!< MUX31 Postion   30         */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX31_Msk \
    (0x3U << CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX31_Pos) /*!< MUX31 Mask      0xC0000000 */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX31_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX31_Pos) & \
     CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX31_Msk) /*!< MUX31 Set Value            */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX31_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX31_Msk) >> \
     CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX31_Pos) /*!< MUX31 Get Value            */


#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX30_Pos (28U) /*!< MUX30 Postion   28         */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX30_Msk \
    (0x3U << CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX30_Pos) /*!< MUX30 Mask      0x30000000 */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX30_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX30_Pos) & \
     CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX30_Msk) /*!< MUX30 Set Value            */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX30_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX30_Msk) >> \
     CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX30_Pos) /*!< MUX30 Get Value            */


#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX29_Pos (26U) /*!< MUX29 Postion   26         */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX29_Msk \
    (0x3U << CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX29_Pos) /*!< MUX29 Mask      0x0C000000 */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX29_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX29_Pos) & \
     CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX29_Msk) /*!< MUX29 Set Value            */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX29_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX29_Msk) >> \
     CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX29_Pos) /*!< MUX29 Get Value            */


#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX28_Pos (24U) /*!< MUX28 Postion   24         */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX28_Msk \
    (0x3U << CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX28_Pos) /*!< MUX28 Mask      0x03000000 */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX28_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX28_Pos) & \
     CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX28_Msk) /*!< MUX28 Set Value            */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX28_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX28_Msk) >> \
     CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX28_Pos) /*!< MUX28 Get Value            */


#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX27_Pos (22U) /*!< MUX27 Postion   22         */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX27_Msk \
    (0x3U << CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX27_Pos) /*!< MUX27 Mask      0x00C00000 */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX27_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX27_Pos) & \
     CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX27_Msk) /*!< MUX27 Set Value            */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX27_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX27_Msk) >> \
     CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX27_Pos) /*!< MUX27 Get Value            */


#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX26_Pos (20U) /*!< MUX26 Postion   20         */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX26_Msk \
    (0x3U << CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX26_Pos) /*!< MUX26 Mask      0x00300000 */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX26_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX26_Pos) & \
     CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX26_Msk) /*!< MUX26 Set Value            */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX26_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX26_Msk) >> \
     CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX26_Pos) /*!< MUX26 Get Value            */


#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX25_Pos (18U) /*!< MUX25 Postion   18         */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX25_Msk \
    (0x3U << CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX25_Pos) /*!< MUX25 Mask      0x000C0000 */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX25_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX25_Pos) & \
     CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX25_Msk) /*!< MUX25 Set Value            */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX25_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX25_Msk) >> \
     CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX25_Pos) /*!< MUX25 Get Value            */


#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX24_Pos (16U) /*!< MUX24 Postion   16         */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX24_Msk \
    (0x3U << CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX24_Pos) /*!< MUX24 Mask      0x00030000 */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX24_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX24_Pos) & \
     CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX24_Msk) /*!< MUX24 Set Value            */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX24_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX24_Msk) >> \
     CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX24_Pos) /*!< MUX24 Get Value            */


#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX23_Pos (14U) /*!< MUX23 Postion   14         */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX23_Msk \
    (0x3U << CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX23_Pos) /*!< MUX23 Mask      0x0000C000 */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX23_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX23_Pos) & \
     CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX23_Msk) /*!< MUX23 Set Value            */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX23_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX23_Msk) >> \
     CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX23_Pos) /*!< MUX23 Get Value            */


#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX22_Pos (12U) /*!< MUX22 Postion   12         */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX22_Msk \
    (0x3U << CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX22_Pos) /*!< MUX22 Mask      0x00003000 */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX22_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX22_Pos) & \
     CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX22_Msk) /*!< MUX22 Set Value            */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX22_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX22_Msk) >> \
     CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX22_Pos) /*!< MUX22 Get Value            */


#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX21_Pos (10U) /*!< MUX21 Postion   10         */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX21_Msk \
    (0x3U << CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX21_Pos) /*!< MUX21 Mask      0x00000C00 */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX21_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX21_Pos) & \
     CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX21_Msk) /*!< MUX21 Set Value            */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX21_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX21_Msk) >> \
     CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX21_Pos) /*!< MUX21 Get Value            */


#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX20_Pos (8U) /*!< MUX20 Postion   8          */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX20_Msk \
    (0x3U << CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX20_Pos) /*!< MUX20 Mask      0x00000300 */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX20_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX20_Pos) & \
     CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX20_Msk) /*!< MUX20 Set Value            */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX20_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX20_Msk) >> \
     CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX20_Pos) /*!< MUX20 Get Value            */


#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX19_Pos (6U) /*!< MUX19 Postion   6          */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX19_Msk \
    (0x3U << CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX19_Pos) /*!< MUX19 Mask      0x000000C0 */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX19_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX19_Pos) & \
     CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX19_Msk) /*!< MUX19 Set Value            */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX19_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX19_Msk) >> \
     CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX19_Pos) /*!< MUX19 Get Value            */


#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX18_Pos (4U) /*!< MUX18 Postion   4          */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX18_Msk \
    (0x3U << CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX18_Pos) /*!< MUX18 Mask      0x00000030 */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX18_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX18_Pos) & \
     CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX18_Msk) /*!< MUX18 Set Value            */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX18_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX18_Msk) >> \
     CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX18_Pos) /*!< MUX18 Get Value            */


#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX17_Pos (2U) /*!< MUX17 Postion   2          */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX17_Msk \
    (0x3U << CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX17_Pos) /*!< MUX17 Mask      0x0000000C */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX17_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX17_Pos) & \
     CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX17_Msk) /*!< MUX17 Set Value            */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX17_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX17_Msk) >> \
     CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX17_Pos) /*!< MUX17 Get Value            */


#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX16_Pos (0U) /*!< MUX16 Postion   0          */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX16_Msk \
    (0x3U << CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX16_Pos) /*!< MUX16 Mask      0x00000003 */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX16_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX16_Pos) & \
     CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX16_Msk) /*!< MUX16 Set Value            */
#define CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX16_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX16_Msk) >> \
     CLB_XBAR_AUXSIGMUX_MUX16TO31CFG_MUX16_Pos) /*!< MUX16 Get Value            */


/* AUXSIGMUXENABLE bitfield */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX31_Pos (31U) /*!< MUX31 Postion   31         */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX31_Msk \
    (0x1U << CLB_XBAR_AUXSIGMUXENABLE_MUX31_Pos) /*!< MUX31 Mask      0x80000000 */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX31_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUXENABLE_MUX31_Pos) & \
     CLB_XBAR_AUXSIGMUXENABLE_MUX31_Msk) /*!< MUX31 Set Value            */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX31_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUXENABLE_MUX31_Msk) >> \
     CLB_XBAR_AUXSIGMUXENABLE_MUX31_Pos) /*!< MUX31 Get Value            */


#define CLB_XBAR_AUXSIGMUXENABLE_MUX30_Pos (30U) /*!< MUX30 Postion   30         */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX30_Msk \
    (0x1U << CLB_XBAR_AUXSIGMUXENABLE_MUX30_Pos) /*!< MUX30 Mask      0x40000000 */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX30_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUXENABLE_MUX30_Pos) & \
     CLB_XBAR_AUXSIGMUXENABLE_MUX30_Msk) /*!< MUX30 Set Value            */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX30_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUXENABLE_MUX30_Msk) >> \
     CLB_XBAR_AUXSIGMUXENABLE_MUX30_Pos) /*!< MUX30 Get Value            */


#define CLB_XBAR_AUXSIGMUXENABLE_MUX29_Pos (29U) /*!< MUX29 Postion   29         */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX29_Msk \
    (0x1U << CLB_XBAR_AUXSIGMUXENABLE_MUX29_Pos) /*!< MUX29 Mask      0x20000000 */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX29_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUXENABLE_MUX29_Pos) & \
     CLB_XBAR_AUXSIGMUXENABLE_MUX29_Msk) /*!< MUX29 Set Value            */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX29_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUXENABLE_MUX29_Msk) >> \
     CLB_XBAR_AUXSIGMUXENABLE_MUX29_Pos) /*!< MUX29 Get Value            */


#define CLB_XBAR_AUXSIGMUXENABLE_MUX28_Pos (28U) /*!< MUX28 Postion   28         */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX28_Msk \
    (0x1U << CLB_XBAR_AUXSIGMUXENABLE_MUX28_Pos) /*!< MUX28 Mask      0x10000000 */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX28_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUXENABLE_MUX28_Pos) & \
     CLB_XBAR_AUXSIGMUXENABLE_MUX28_Msk) /*!< MUX28 Set Value            */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX28_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUXENABLE_MUX28_Msk) >> \
     CLB_XBAR_AUXSIGMUXENABLE_MUX28_Pos) /*!< MUX28 Get Value            */


#define CLB_XBAR_AUXSIGMUXENABLE_MUX27_Pos (27U) /*!< MUX27 Postion   27         */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX27_Msk \
    (0x1U << CLB_XBAR_AUXSIGMUXENABLE_MUX27_Pos) /*!< MUX27 Mask      0x08000000 */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX27_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUXENABLE_MUX27_Pos) & \
     CLB_XBAR_AUXSIGMUXENABLE_MUX27_Msk) /*!< MUX27 Set Value            */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX27_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUXENABLE_MUX27_Msk) >> \
     CLB_XBAR_AUXSIGMUXENABLE_MUX27_Pos) /*!< MUX27 Get Value            */


#define CLB_XBAR_AUXSIGMUXENABLE_MUX26_Pos (26U) /*!< MUX26 Postion   26         */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX26_Msk \
    (0x1U << CLB_XBAR_AUXSIGMUXENABLE_MUX26_Pos) /*!< MUX26 Mask      0x04000000 */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX26_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUXENABLE_MUX26_Pos) & \
     CLB_XBAR_AUXSIGMUXENABLE_MUX26_Msk) /*!< MUX26 Set Value            */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX26_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUXENABLE_MUX26_Msk) >> \
     CLB_XBAR_AUXSIGMUXENABLE_MUX26_Pos) /*!< MUX26 Get Value            */


#define CLB_XBAR_AUXSIGMUXENABLE_MUX25_Pos (25U) /*!< MUX25 Postion   25         */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX25_Msk \
    (0x1U << CLB_XBAR_AUXSIGMUXENABLE_MUX25_Pos) /*!< MUX25 Mask      0x02000000 */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX25_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUXENABLE_MUX25_Pos) & \
     CLB_XBAR_AUXSIGMUXENABLE_MUX25_Msk) /*!< MUX25 Set Value            */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX25_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUXENABLE_MUX25_Msk) >> \
     CLB_XBAR_AUXSIGMUXENABLE_MUX25_Pos) /*!< MUX25 Get Value            */


#define CLB_XBAR_AUXSIGMUXENABLE_MUX24_Pos (24U) /*!< MUX24 Postion   24         */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX24_Msk \
    (0x1U << CLB_XBAR_AUXSIGMUXENABLE_MUX24_Pos) /*!< MUX24 Mask      0x01000000 */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX24_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUXENABLE_MUX24_Pos) & \
     CLB_XBAR_AUXSIGMUXENABLE_MUX24_Msk) /*!< MUX24 Set Value            */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX24_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUXENABLE_MUX24_Msk) >> \
     CLB_XBAR_AUXSIGMUXENABLE_MUX24_Pos) /*!< MUX24 Get Value            */


#define CLB_XBAR_AUXSIGMUXENABLE_MUX23_Pos (23U) /*!< MUX23 Postion   23         */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX23_Msk \
    (0x1U << CLB_XBAR_AUXSIGMUXENABLE_MUX23_Pos) /*!< MUX23 Mask      0x00800000 */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX23_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUXENABLE_MUX23_Pos) & \
     CLB_XBAR_AUXSIGMUXENABLE_MUX23_Msk) /*!< MUX23 Set Value            */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX23_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUXENABLE_MUX23_Msk) >> \
     CLB_XBAR_AUXSIGMUXENABLE_MUX23_Pos) /*!< MUX23 Get Value            */


#define CLB_XBAR_AUXSIGMUXENABLE_MUX22_Pos (22U) /*!< MUX22 Postion   22         */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX22_Msk \
    (0x1U << CLB_XBAR_AUXSIGMUXENABLE_MUX22_Pos) /*!< MUX22 Mask      0x00400000 */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX22_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUXENABLE_MUX22_Pos) & \
     CLB_XBAR_AUXSIGMUXENABLE_MUX22_Msk) /*!< MUX22 Set Value            */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX22_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUXENABLE_MUX22_Msk) >> \
     CLB_XBAR_AUXSIGMUXENABLE_MUX22_Pos) /*!< MUX22 Get Value            */


#define CLB_XBAR_AUXSIGMUXENABLE_MUX21_Pos (21U) /*!< MUX21 Postion   21         */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX21_Msk \
    (0x1U << CLB_XBAR_AUXSIGMUXENABLE_MUX21_Pos) /*!< MUX21 Mask      0x00200000 */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX21_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUXENABLE_MUX21_Pos) & \
     CLB_XBAR_AUXSIGMUXENABLE_MUX21_Msk) /*!< MUX21 Set Value            */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX21_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUXENABLE_MUX21_Msk) >> \
     CLB_XBAR_AUXSIGMUXENABLE_MUX21_Pos) /*!< MUX21 Get Value            */


#define CLB_XBAR_AUXSIGMUXENABLE_MUX20_Pos (20U) /*!< MUX20 Postion   20         */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX20_Msk \
    (0x1U << CLB_XBAR_AUXSIGMUXENABLE_MUX20_Pos) /*!< MUX20 Mask      0x00100000 */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX20_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUXENABLE_MUX20_Pos) & \
     CLB_XBAR_AUXSIGMUXENABLE_MUX20_Msk) /*!< MUX20 Set Value            */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX20_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUXENABLE_MUX20_Msk) >> \
     CLB_XBAR_AUXSIGMUXENABLE_MUX20_Pos) /*!< MUX20 Get Value            */


#define CLB_XBAR_AUXSIGMUXENABLE_MUX19_Pos (19U) /*!< MUX19 Postion   19         */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX19_Msk \
    (0x1U << CLB_XBAR_AUXSIGMUXENABLE_MUX19_Pos) /*!< MUX19 Mask      0x00080000 */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX19_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUXENABLE_MUX19_Pos) & \
     CLB_XBAR_AUXSIGMUXENABLE_MUX19_Msk) /*!< MUX19 Set Value            */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX19_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUXENABLE_MUX19_Msk) >> \
     CLB_XBAR_AUXSIGMUXENABLE_MUX19_Pos) /*!< MUX19 Get Value            */


#define CLB_XBAR_AUXSIGMUXENABLE_MUX18_Pos (18U) /*!< MUX18 Postion   18         */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX18_Msk \
    (0x1U << CLB_XBAR_AUXSIGMUXENABLE_MUX18_Pos) /*!< MUX18 Mask      0x00040000 */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX18_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUXENABLE_MUX18_Pos) & \
     CLB_XBAR_AUXSIGMUXENABLE_MUX18_Msk) /*!< MUX18 Set Value            */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX18_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUXENABLE_MUX18_Msk) >> \
     CLB_XBAR_AUXSIGMUXENABLE_MUX18_Pos) /*!< MUX18 Get Value            */


#define CLB_XBAR_AUXSIGMUXENABLE_MUX17_Pos (17U) /*!< MUX17 Postion   17         */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX17_Msk \
    (0x1U << CLB_XBAR_AUXSIGMUXENABLE_MUX17_Pos) /*!< MUX17 Mask      0x00020000 */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX17_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUXENABLE_MUX17_Pos) & \
     CLB_XBAR_AUXSIGMUXENABLE_MUX17_Msk) /*!< MUX17 Set Value            */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX17_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUXENABLE_MUX17_Msk) >> \
     CLB_XBAR_AUXSIGMUXENABLE_MUX17_Pos) /*!< MUX17 Get Value            */


#define CLB_XBAR_AUXSIGMUXENABLE_MUX16_Pos (16U) /*!< MUX16 Postion   16         */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX16_Msk \
    (0x1U << CLB_XBAR_AUXSIGMUXENABLE_MUX16_Pos) /*!< MUX16 Mask      0x00010000 */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX16_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUXENABLE_MUX16_Pos) & \
     CLB_XBAR_AUXSIGMUXENABLE_MUX16_Msk) /*!< MUX16 Set Value            */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX16_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUXENABLE_MUX16_Msk) >> \
     CLB_XBAR_AUXSIGMUXENABLE_MUX16_Pos) /*!< MUX16 Get Value            */


#define CLB_XBAR_AUXSIGMUXENABLE_MUX15_Pos (15U) /*!< MUX15 Postion   15         */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX15_Msk \
    (0x1U << CLB_XBAR_AUXSIGMUXENABLE_MUX15_Pos) /*!< MUX15 Mask      0x00008000 */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX15_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUXENABLE_MUX15_Pos) & \
     CLB_XBAR_AUXSIGMUXENABLE_MUX15_Msk) /*!< MUX15 Set Value            */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX15_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUXENABLE_MUX15_Msk) >> \
     CLB_XBAR_AUXSIGMUXENABLE_MUX15_Pos) /*!< MUX15 Get Value            */


#define CLB_XBAR_AUXSIGMUXENABLE_MUX14_Pos (14U) /*!< MUX14 Postion   14         */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX14_Msk \
    (0x1U << CLB_XBAR_AUXSIGMUXENABLE_MUX14_Pos) /*!< MUX14 Mask      0x00004000 */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX14_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUXENABLE_MUX14_Pos) & \
     CLB_XBAR_AUXSIGMUXENABLE_MUX14_Msk) /*!< MUX14 Set Value            */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX14_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUXENABLE_MUX14_Msk) >> \
     CLB_XBAR_AUXSIGMUXENABLE_MUX14_Pos) /*!< MUX14 Get Value            */


#define CLB_XBAR_AUXSIGMUXENABLE_MUX13_Pos (13U) /*!< MUX13 Postion   13         */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX13_Msk \
    (0x1U << CLB_XBAR_AUXSIGMUXENABLE_MUX13_Pos) /*!< MUX13 Mask      0x00002000 */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX13_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUXENABLE_MUX13_Pos) & \
     CLB_XBAR_AUXSIGMUXENABLE_MUX13_Msk) /*!< MUX13 Set Value            */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX13_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUXENABLE_MUX13_Msk) >> \
     CLB_XBAR_AUXSIGMUXENABLE_MUX13_Pos) /*!< MUX13 Get Value            */


#define CLB_XBAR_AUXSIGMUXENABLE_MUX12_Pos (12U) /*!< MUX12 Postion   12         */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX12_Msk \
    (0x1U << CLB_XBAR_AUXSIGMUXENABLE_MUX12_Pos) /*!< MUX12 Mask      0x00001000 */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX12_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUXENABLE_MUX12_Pos) & \
     CLB_XBAR_AUXSIGMUXENABLE_MUX12_Msk) /*!< MUX12 Set Value            */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX12_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUXENABLE_MUX12_Msk) >> \
     CLB_XBAR_AUXSIGMUXENABLE_MUX12_Pos) /*!< MUX12 Get Value            */


#define CLB_XBAR_AUXSIGMUXENABLE_MUX11_Pos (11U) /*!< MUX11 Postion   11         */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX11_Msk \
    (0x1U << CLB_XBAR_AUXSIGMUXENABLE_MUX11_Pos) /*!< MUX11 Mask      0x00000800 */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX11_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUXENABLE_MUX11_Pos) & \
     CLB_XBAR_AUXSIGMUXENABLE_MUX11_Msk) /*!< MUX11 Set Value            */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX11_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUXENABLE_MUX11_Msk) >> \
     CLB_XBAR_AUXSIGMUXENABLE_MUX11_Pos) /*!< MUX11 Get Value            */


#define CLB_XBAR_AUXSIGMUXENABLE_MUX10_Pos (10U) /*!< MUX10 Postion   10         */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX10_Msk \
    (0x1U << CLB_XBAR_AUXSIGMUXENABLE_MUX10_Pos) /*!< MUX10 Mask      0x00000400 */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX10_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUXENABLE_MUX10_Pos) & \
     CLB_XBAR_AUXSIGMUXENABLE_MUX10_Msk) /*!< MUX10 Set Value            */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX10_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUXENABLE_MUX10_Msk) >> \
     CLB_XBAR_AUXSIGMUXENABLE_MUX10_Pos) /*!< MUX10 Get Value            */


#define CLB_XBAR_AUXSIGMUXENABLE_MUX9_Pos (9U) /*!< MUX9 Postion   9          */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX9_Msk                                      \
    (0x1U << CLB_XBAR_AUXSIGMUXENABLE_MUX9_Pos) /*!< MUX9 Mask      0x00000200 \
                                                 */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX9_Set(x) \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUXENABLE_MUX9_Pos) & CLB_XBAR_AUXSIGMUXENABLE_MUX9_Msk) /*!< MUX9 Set Value */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX9_Get(x) \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUXENABLE_MUX9_Msk) >> CLB_XBAR_AUXSIGMUXENABLE_MUX9_Pos) /*!< MUX9 Get Value */


#define CLB_XBAR_AUXSIGMUXENABLE_MUX8_Pos (8U) /*!< MUX8 Postion   8          */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX8_Msk                                      \
    (0x1U << CLB_XBAR_AUXSIGMUXENABLE_MUX8_Pos) /*!< MUX8 Mask      0x00000100 \
                                                 */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX8_Set(x) \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUXENABLE_MUX8_Pos) & CLB_XBAR_AUXSIGMUXENABLE_MUX8_Msk) /*!< MUX8 Set Value */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX8_Get(x) \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUXENABLE_MUX8_Msk) >> CLB_XBAR_AUXSIGMUXENABLE_MUX8_Pos) /*!< MUX8 Get Value */


#define CLB_XBAR_AUXSIGMUXENABLE_MUX7_Pos (7U) /*!< MUX7 Postion   7          */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX7_Msk                                      \
    (0x1U << CLB_XBAR_AUXSIGMUXENABLE_MUX7_Pos) /*!< MUX7 Mask      0x00000080 \
                                                 */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX7_Set(x) \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUXENABLE_MUX7_Pos) & CLB_XBAR_AUXSIGMUXENABLE_MUX7_Msk) /*!< MUX7 Set Value */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX7_Get(x) \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUXENABLE_MUX7_Msk) >> CLB_XBAR_AUXSIGMUXENABLE_MUX7_Pos) /*!< MUX7 Get Value */


#define CLB_XBAR_AUXSIGMUXENABLE_MUX6_Pos (6U) /*!< MUX6 Postion   6          */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX6_Msk                                      \
    (0x1U << CLB_XBAR_AUXSIGMUXENABLE_MUX6_Pos) /*!< MUX6 Mask      0x00000040 \
                                                 */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX6_Set(x) \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUXENABLE_MUX6_Pos) & CLB_XBAR_AUXSIGMUXENABLE_MUX6_Msk) /*!< MUX6 Set Value */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX6_Get(x) \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUXENABLE_MUX6_Msk) >> CLB_XBAR_AUXSIGMUXENABLE_MUX6_Pos) /*!< MUX6 Get Value */


#define CLB_XBAR_AUXSIGMUXENABLE_MUX5_Pos (5U) /*!< MUX5 Postion   5          */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX5_Msk                                      \
    (0x1U << CLB_XBAR_AUXSIGMUXENABLE_MUX5_Pos) /*!< MUX5 Mask      0x00000020 \
                                                 */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX5_Set(x) \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUXENABLE_MUX5_Pos) & CLB_XBAR_AUXSIGMUXENABLE_MUX5_Msk) /*!< MUX5 Set Value */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX5_Get(x) \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUXENABLE_MUX5_Msk) >> CLB_XBAR_AUXSIGMUXENABLE_MUX5_Pos) /*!< MUX5 Get Value */


#define CLB_XBAR_AUXSIGMUXENABLE_MUX4_Pos (4U) /*!< MUX4 Postion   4          */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX4_Msk                                      \
    (0x1U << CLB_XBAR_AUXSIGMUXENABLE_MUX4_Pos) /*!< MUX4 Mask      0x00000010 \
                                                 */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX4_Set(x) \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUXENABLE_MUX4_Pos) & CLB_XBAR_AUXSIGMUXENABLE_MUX4_Msk) /*!< MUX4 Set Value */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX4_Get(x) \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUXENABLE_MUX4_Msk) >> CLB_XBAR_AUXSIGMUXENABLE_MUX4_Pos) /*!< MUX4 Get Value */


#define CLB_XBAR_AUXSIGMUXENABLE_MUX3_Pos (3U) /*!< MUX3 Postion   3          */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX3_Msk                                      \
    (0x1U << CLB_XBAR_AUXSIGMUXENABLE_MUX3_Pos) /*!< MUX3 Mask      0x00000008 \
                                                 */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX3_Set(x) \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUXENABLE_MUX3_Pos) & CLB_XBAR_AUXSIGMUXENABLE_MUX3_Msk) /*!< MUX3 Set Value */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX3_Get(x) \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUXENABLE_MUX3_Msk) >> CLB_XBAR_AUXSIGMUXENABLE_MUX3_Pos) /*!< MUX3 Get Value */


#define CLB_XBAR_AUXSIGMUXENABLE_MUX2_Pos (2U) /*!< MUX2 Postion   2          */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX2_Msk                                      \
    (0x1U << CLB_XBAR_AUXSIGMUXENABLE_MUX2_Pos) /*!< MUX2 Mask      0x00000004 \
                                                 */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX2_Set(x) \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUXENABLE_MUX2_Pos) & CLB_XBAR_AUXSIGMUXENABLE_MUX2_Msk) /*!< MUX2 Set Value */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX2_Get(x) \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUXENABLE_MUX2_Msk) >> CLB_XBAR_AUXSIGMUXENABLE_MUX2_Pos) /*!< MUX2 Get Value */


#define CLB_XBAR_AUXSIGMUXENABLE_MUX1_Pos (1U) /*!< MUX1 Postion   1          */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX1_Msk                                      \
    (0x1U << CLB_XBAR_AUXSIGMUXENABLE_MUX1_Pos) /*!< MUX1 Mask      0x00000002 \
                                                 */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX1_Set(x) \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUXENABLE_MUX1_Pos) & CLB_XBAR_AUXSIGMUXENABLE_MUX1_Msk) /*!< MUX1 Set Value */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX1_Get(x) \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUXENABLE_MUX1_Msk) >> CLB_XBAR_AUXSIGMUXENABLE_MUX1_Pos) /*!< MUX1 Get Value */


#define CLB_XBAR_AUXSIGMUXENABLE_MUX0_Pos (0U) /*!< MUX0 Postion   0          */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX0_Msk                                      \
    (0x1U << CLB_XBAR_AUXSIGMUXENABLE_MUX0_Pos) /*!< MUX0 Mask      0x00000001 \
                                                 */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX0_Set(x) \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGMUXENABLE_MUX0_Pos) & CLB_XBAR_AUXSIGMUXENABLE_MUX0_Msk) /*!< MUX0 Set Value */
#define CLB_XBAR_AUXSIGMUXENABLE_MUX0_Get(x) \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGMUXENABLE_MUX0_Msk) >> CLB_XBAR_AUXSIGMUXENABLE_MUX0_Pos) /*!< MUX0 Get Value */


/* AUXSIGOUTINV bitfield */
#define CLB_XBAR_AUXSIGOUTINV_AUXSIG7_Pos (7U) /*!< AUXSIG7 Postion   7          */
#define CLB_XBAR_AUXSIGOUTINV_AUXSIG7_Msk \
    (0x1U << CLB_XBAR_AUXSIGOUTINV_AUXSIG7_Pos) /*!< AUXSIG7 Mask      0x00000080 */
#define CLB_XBAR_AUXSIGOUTINV_AUXSIG7_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGOUTINV_AUXSIG7_Pos) & \
     CLB_XBAR_AUXSIGOUTINV_AUXSIG7_Msk) /*!< AUXSIG7 Set Value            */
#define CLB_XBAR_AUXSIGOUTINV_AUXSIG7_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGOUTINV_AUXSIG7_Msk) >> \
     CLB_XBAR_AUXSIGOUTINV_AUXSIG7_Pos) /*!< AUXSIG7 Get Value            */


#define CLB_XBAR_AUXSIGOUTINV_AUXSIG6_Pos (6U) /*!< AUXSIG6 Postion   6          */
#define CLB_XBAR_AUXSIGOUTINV_AUXSIG6_Msk \
    (0x1U << CLB_XBAR_AUXSIGOUTINV_AUXSIG6_Pos) /*!< AUXSIG6 Mask      0x00000040 */
#define CLB_XBAR_AUXSIGOUTINV_AUXSIG6_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGOUTINV_AUXSIG6_Pos) & \
     CLB_XBAR_AUXSIGOUTINV_AUXSIG6_Msk) /*!< AUXSIG6 Set Value            */
#define CLB_XBAR_AUXSIGOUTINV_AUXSIG6_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGOUTINV_AUXSIG6_Msk) >> \
     CLB_XBAR_AUXSIGOUTINV_AUXSIG6_Pos) /*!< AUXSIG6 Get Value            */


#define CLB_XBAR_AUXSIGOUTINV_AUXSIG5_Pos (5U) /*!< AUXSIG5 Postion   5          */
#define CLB_XBAR_AUXSIGOUTINV_AUXSIG5_Msk \
    (0x1U << CLB_XBAR_AUXSIGOUTINV_AUXSIG5_Pos) /*!< AUXSIG5 Mask      0x00000020 */
#define CLB_XBAR_AUXSIGOUTINV_AUXSIG5_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGOUTINV_AUXSIG5_Pos) & \
     CLB_XBAR_AUXSIGOUTINV_AUXSIG5_Msk) /*!< AUXSIG5 Set Value            */
#define CLB_XBAR_AUXSIGOUTINV_AUXSIG5_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGOUTINV_AUXSIG5_Msk) >> \
     CLB_XBAR_AUXSIGOUTINV_AUXSIG5_Pos) /*!< AUXSIG5 Get Value            */


#define CLB_XBAR_AUXSIGOUTINV_AUXSIG4_Pos (4U) /*!< AUXSIG4 Postion   4          */
#define CLB_XBAR_AUXSIGOUTINV_AUXSIG4_Msk \
    (0x1U << CLB_XBAR_AUXSIGOUTINV_AUXSIG4_Pos) /*!< AUXSIG4 Mask      0x00000010 */
#define CLB_XBAR_AUXSIGOUTINV_AUXSIG4_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGOUTINV_AUXSIG4_Pos) & \
     CLB_XBAR_AUXSIGOUTINV_AUXSIG4_Msk) /*!< AUXSIG4 Set Value            */
#define CLB_XBAR_AUXSIGOUTINV_AUXSIG4_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGOUTINV_AUXSIG4_Msk) >> \
     CLB_XBAR_AUXSIGOUTINV_AUXSIG4_Pos) /*!< AUXSIG4 Get Value            */


#define CLB_XBAR_AUXSIGOUTINV_AUXSIG3_Pos (3U) /*!< AUXSIG3 Postion   3          */
#define CLB_XBAR_AUXSIGOUTINV_AUXSIG3_Msk \
    (0x1U << CLB_XBAR_AUXSIGOUTINV_AUXSIG3_Pos) /*!< AUXSIG3 Mask      0x00000008 */
#define CLB_XBAR_AUXSIGOUTINV_AUXSIG3_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGOUTINV_AUXSIG3_Pos) & \
     CLB_XBAR_AUXSIGOUTINV_AUXSIG3_Msk) /*!< AUXSIG3 Set Value            */
#define CLB_XBAR_AUXSIGOUTINV_AUXSIG3_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGOUTINV_AUXSIG3_Msk) >> \
     CLB_XBAR_AUXSIGOUTINV_AUXSIG3_Pos) /*!< AUXSIG3 Get Value            */


#define CLB_XBAR_AUXSIGOUTINV_AUXSIG2_Pos (2U) /*!< AUXSIG2 Postion   2          */
#define CLB_XBAR_AUXSIGOUTINV_AUXSIG2_Msk \
    (0x1U << CLB_XBAR_AUXSIGOUTINV_AUXSIG2_Pos) /*!< AUXSIG2 Mask      0x00000004 */
#define CLB_XBAR_AUXSIGOUTINV_AUXSIG2_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGOUTINV_AUXSIG2_Pos) & \
     CLB_XBAR_AUXSIGOUTINV_AUXSIG2_Msk) /*!< AUXSIG2 Set Value            */
#define CLB_XBAR_AUXSIGOUTINV_AUXSIG2_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGOUTINV_AUXSIG2_Msk) >> \
     CLB_XBAR_AUXSIGOUTINV_AUXSIG2_Pos) /*!< AUXSIG2 Get Value            */


#define CLB_XBAR_AUXSIGOUTINV_AUXSIG1_Pos (1U) /*!< AUXSIG1 Postion   1          */
#define CLB_XBAR_AUXSIGOUTINV_AUXSIG1_Msk \
    (0x1U << CLB_XBAR_AUXSIGOUTINV_AUXSIG1_Pos) /*!< AUXSIG1 Mask      0x00000002 */
#define CLB_XBAR_AUXSIGOUTINV_AUXSIG1_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGOUTINV_AUXSIG1_Pos) & \
     CLB_XBAR_AUXSIGOUTINV_AUXSIG1_Msk) /*!< AUXSIG1 Set Value            */
#define CLB_XBAR_AUXSIGOUTINV_AUXSIG1_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGOUTINV_AUXSIG1_Msk) >> \
     CLB_XBAR_AUXSIGOUTINV_AUXSIG1_Pos) /*!< AUXSIG1 Get Value            */


#define CLB_XBAR_AUXSIGOUTINV_AUXSIG0_Pos (0U) /*!< AUXSIG0 Postion   0          */
#define CLB_XBAR_AUXSIGOUTINV_AUXSIG0_Msk \
    (0x1U << CLB_XBAR_AUXSIGOUTINV_AUXSIG0_Pos) /*!< AUXSIG0 Mask      0x00000001 */
#define CLB_XBAR_AUXSIGOUTINV_AUXSIG0_Set(x)                 \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGOUTINV_AUXSIG0_Pos) & \
     CLB_XBAR_AUXSIGOUTINV_AUXSIG0_Msk) /*!< AUXSIG0 Set Value            */
#define CLB_XBAR_AUXSIGOUTINV_AUXSIG0_Get(x)                \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGOUTINV_AUXSIG0_Msk) >> \
     CLB_XBAR_AUXSIGOUTINV_AUXSIG0_Pos) /*!< AUXSIG0 Get Value            */


/* AUXSIGLOCK bitfield */
#define CLB_XBAR_AUXSIGLOCK_KEY_Pos (16U)                                    /*!< KEY Postion   16         */
#define CLB_XBAR_AUXSIGLOCK_KEY_Msk (0xffffU << CLB_XBAR_AUXSIGLOCK_KEY_Pos) /*!< KEY Mask      0xFFFF0000 */
#define CLB_XBAR_AUXSIGLOCK_KEY_Set(x) \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGLOCK_KEY_Pos) & CLB_XBAR_AUXSIGLOCK_KEY_Msk) /*!< KEY Set Value            */
#define CLB_XBAR_AUXSIGLOCK_KEY_Get(x) \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGLOCK_KEY_Msk) >> CLB_XBAR_AUXSIGLOCK_KEY_Pos) /*!< KEY Get Value            */


#define CLB_XBAR_AUXSIGLOCK_LOCK_Pos (0U)                                   /*!< LOCK Postion   0          */
#define CLB_XBAR_AUXSIGLOCK_LOCK_Msk (0x1U << CLB_XBAR_AUXSIGLOCK_LOCK_Pos) /*!< LOCK Mask      0x00000001 */
#define CLB_XBAR_AUXSIGLOCK_LOCK_Set(x) \
    (((uint32_t) (x) << CLB_XBAR_AUXSIGLOCK_LOCK_Pos) & CLB_XBAR_AUXSIGLOCK_LOCK_Msk) /*!< LOCK Set Value */
#define CLB_XBAR_AUXSIGLOCK_LOCK_Get(x) \
    (((uint32_t) (x) &CLB_XBAR_AUXSIGLOCK_LOCK_Msk) >> CLB_XBAR_AUXSIGLOCK_LOCK_Pos) /*!< LOCK Get Value            */


/* OUTPUTMUX_MUX0TO15CFG bitfield */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX15_Pos (30U) /*!< MUX15 Postion   30         */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX15_Msk \
    (0x3U << OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX15_Pos) /*!< MUX15 Mask      0xC0000000 */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX15_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX15_Pos) & \
     OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX15_Msk) /*!< MUX15 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX15_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX15_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX15_Pos) /*!< MUX15 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX14_Pos (28U) /*!< MUX14 Postion   28         */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX14_Msk \
    (0x3U << OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX14_Pos) /*!< MUX14 Mask      0x30000000 */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX14_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX14_Pos) & \
     OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX14_Msk) /*!< MUX14 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX14_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX14_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX14_Pos) /*!< MUX14 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX13_Pos (26U) /*!< MUX13 Postion   26         */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX13_Msk \
    (0x3U << OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX13_Pos) /*!< MUX13 Mask      0x0C000000 */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX13_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX13_Pos) & \
     OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX13_Msk) /*!< MUX13 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX13_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX13_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX13_Pos) /*!< MUX13 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX12_Pos (24U) /*!< MUX12 Postion   24         */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX12_Msk \
    (0x3U << OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX12_Pos) /*!< MUX12 Mask      0x03000000 */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX12_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX12_Pos) & \
     OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX12_Msk) /*!< MUX12 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX12_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX12_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX12_Pos) /*!< MUX12 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX11_Pos (22U) /*!< MUX11 Postion   22         */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX11_Msk \
    (0x3U << OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX11_Pos) /*!< MUX11 Mask      0x00C00000 */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX11_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX11_Pos) & \
     OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX11_Msk) /*!< MUX11 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX11_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX11_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX11_Pos) /*!< MUX11 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX10_Pos (20U) /*!< MUX10 Postion   20         */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX10_Msk \
    (0x3U << OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX10_Pos) /*!< MUX10 Mask      0x00300000 */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX10_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX10_Pos) & \
     OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX10_Msk) /*!< MUX10 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX10_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX10_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX10_Pos) /*!< MUX10 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX9_Pos (18U) /*!< MUX9 Postion   18         */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX9_Msk \
    (0x3U << OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX9_Pos) /*!< MUX9 Mask      0x000C0000 */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX9_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX9_Pos) & \
     OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX9_Msk) /*!< MUX9 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX9_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX9_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX9_Pos) /*!< MUX9 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX8_Pos (16U) /*!< MUX8 Postion   16         */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX8_Msk \
    (0x3U << OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX8_Pos) /*!< MUX8 Mask      0x00030000 */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX8_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX8_Pos) & \
     OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX8_Msk) /*!< MUX8 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX8_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX8_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX8_Pos) /*!< MUX8 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX7_Pos (14U) /*!< MUX7 Postion   14         */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX7_Msk \
    (0x3U << OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX7_Pos) /*!< MUX7 Mask      0x0000C000 */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX7_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX7_Pos) & \
     OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX7_Msk) /*!< MUX7 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX7_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX7_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX7_Pos) /*!< MUX7 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX6_Pos (12U) /*!< MUX6 Postion   12         */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX6_Msk \
    (0x3U << OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX6_Pos) /*!< MUX6 Mask      0x00003000 */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX6_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX6_Pos) & \
     OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX6_Msk) /*!< MUX6 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX6_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX6_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX6_Pos) /*!< MUX6 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX5_Pos (10U) /*!< MUX5 Postion   10         */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX5_Msk \
    (0x3U << OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX5_Pos) /*!< MUX5 Mask      0x00000C00 */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX5_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX5_Pos) & \
     OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX5_Msk) /*!< MUX5 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX5_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX5_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX5_Pos) /*!< MUX5 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX4_Pos (8U) /*!< MUX4 Postion   8          */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX4_Msk \
    (0x3U << OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX4_Pos) /*!< MUX4 Mask      0x00000300 */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX4_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX4_Pos) & \
     OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX4_Msk) /*!< MUX4 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX4_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX4_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX4_Pos) /*!< MUX4 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX3_Pos (6U) /*!< MUX3 Postion   6          */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX3_Msk \
    (0x3U << OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX3_Pos) /*!< MUX3 Mask      0x000000C0 */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX3_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX3_Pos) & \
     OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX3_Msk) /*!< MUX3 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX3_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX3_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX3_Pos) /*!< MUX3 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX2_Pos (4U) /*!< MUX2 Postion   4          */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX2_Msk \
    (0x3U << OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX2_Pos) /*!< MUX2 Mask      0x00000030 */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX2_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX2_Pos) & \
     OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX2_Msk) /*!< MUX2 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX2_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX2_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX2_Pos) /*!< MUX2 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX1_Pos (2U) /*!< MUX1 Postion   2          */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX1_Msk \
    (0x3U << OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX1_Pos) /*!< MUX1 Mask      0x0000000C */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX1_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX1_Pos) & \
     OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX1_Msk) /*!< MUX1 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX1_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX1_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX1_Pos) /*!< MUX1 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX0_Pos (0U) /*!< MUX0 Postion   0          */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX0_Msk \
    (0x3U << OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX0_Pos) /*!< MUX0 Mask      0x00000003 */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX0_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX0_Pos) & \
     OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX0_Msk) /*!< MUX0 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX0_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX0_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUX_MUX0TO15CFG_MUX0_Pos) /*!< MUX0 Get Value            */


/* OUTPUTMUXENABLE bitfield */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX31_Pos (31U) /*!< MUX31 Postion   31         */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX31_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX31_Pos) /*!< MUX31 Mask      0x80000000 */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX31_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX31_Pos) & \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX31_Msk) /*!< MUX31 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX31_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUXENABLE_MUX31_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX31_Pos) /*!< MUX31 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX30_Pos (30U) /*!< MUX30 Postion   30         */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX30_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX30_Pos) /*!< MUX30 Mask      0x40000000 */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX30_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX30_Pos) & \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX30_Msk) /*!< MUX30 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX30_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUXENABLE_MUX30_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX30_Pos) /*!< MUX30 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX29_Pos (29U) /*!< MUX29 Postion   29         */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX29_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX29_Pos) /*!< MUX29 Mask      0x20000000 */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX29_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX29_Pos) & \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX29_Msk) /*!< MUX29 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX29_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUXENABLE_MUX29_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX29_Pos) /*!< MUX29 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX28_Pos (28U) /*!< MUX28 Postion   28         */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX28_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX28_Pos) /*!< MUX28 Mask      0x10000000 */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX28_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX28_Pos) & \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX28_Msk) /*!< MUX28 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX28_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUXENABLE_MUX28_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX28_Pos) /*!< MUX28 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX27_Pos (27U) /*!< MUX27 Postion   27         */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX27_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX27_Pos) /*!< MUX27 Mask      0x08000000 */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX27_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX27_Pos) & \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX27_Msk) /*!< MUX27 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX27_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUXENABLE_MUX27_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX27_Pos) /*!< MUX27 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX26_Pos (26U) /*!< MUX26 Postion   26         */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX26_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX26_Pos) /*!< MUX26 Mask      0x04000000 */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX26_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX26_Pos) & \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX26_Msk) /*!< MUX26 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX26_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUXENABLE_MUX26_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX26_Pos) /*!< MUX26 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX25_Pos (25U) /*!< MUX25 Postion   25         */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX25_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX25_Pos) /*!< MUX25 Mask      0x02000000 */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX25_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX25_Pos) & \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX25_Msk) /*!< MUX25 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX25_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUXENABLE_MUX25_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX25_Pos) /*!< MUX25 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX24_Pos (24U) /*!< MUX24 Postion   24         */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX24_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX24_Pos) /*!< MUX24 Mask      0x01000000 */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX24_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX24_Pos) & \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX24_Msk) /*!< MUX24 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX24_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUXENABLE_MUX24_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX24_Pos) /*!< MUX24 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX23_Pos (23U) /*!< MUX23 Postion   23         */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX23_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX23_Pos) /*!< MUX23 Mask      0x00800000 */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX23_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX23_Pos) & \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX23_Msk) /*!< MUX23 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX23_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUXENABLE_MUX23_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX23_Pos) /*!< MUX23 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX22_Pos (22U) /*!< MUX22 Postion   22         */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX22_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX22_Pos) /*!< MUX22 Mask      0x00400000 */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX22_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX22_Pos) & \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX22_Msk) /*!< MUX22 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX22_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUXENABLE_MUX22_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX22_Pos) /*!< MUX22 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX21_Pos (21U) /*!< MUX21 Postion   21         */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX21_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX21_Pos) /*!< MUX21 Mask      0x00200000 */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX21_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX21_Pos) & \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX21_Msk) /*!< MUX21 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX21_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUXENABLE_MUX21_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX21_Pos) /*!< MUX21 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX20_Pos (20U) /*!< MUX20 Postion   20         */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX20_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX20_Pos) /*!< MUX20 Mask      0x00100000 */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX20_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX20_Pos) & \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX20_Msk) /*!< MUX20 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX20_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUXENABLE_MUX20_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX20_Pos) /*!< MUX20 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX19_Pos (19U) /*!< MUX19 Postion   19         */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX19_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX19_Pos) /*!< MUX19 Mask      0x00080000 */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX19_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX19_Pos) & \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX19_Msk) /*!< MUX19 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX19_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUXENABLE_MUX19_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX19_Pos) /*!< MUX19 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX18_Pos (18U) /*!< MUX18 Postion   18         */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX18_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX18_Pos) /*!< MUX18 Mask      0x00040000 */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX18_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX18_Pos) & \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX18_Msk) /*!< MUX18 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX18_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUXENABLE_MUX18_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX18_Pos) /*!< MUX18 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX17_Pos (17U) /*!< MUX17 Postion   17         */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX17_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX17_Pos) /*!< MUX17 Mask      0x00020000 */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX17_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX17_Pos) & \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX17_Msk) /*!< MUX17 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX17_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUXENABLE_MUX17_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX17_Pos) /*!< MUX17 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX16_Pos (16U) /*!< MUX16 Postion   16         */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX16_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX16_Pos) /*!< MUX16 Mask      0x00010000 */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX16_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX16_Pos) & \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX16_Msk) /*!< MUX16 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX16_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUXENABLE_MUX16_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX16_Pos) /*!< MUX16 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX15_Pos (15U) /*!< MUX15 Postion   15         */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX15_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX15_Pos) /*!< MUX15 Mask      0x00008000 */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX15_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX15_Pos) & \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX15_Msk) /*!< MUX15 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX15_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUXENABLE_MUX15_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX15_Pos) /*!< MUX15 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX14_Pos (14U) /*!< MUX14 Postion   14         */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX14_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX14_Pos) /*!< MUX14 Mask      0x00004000 */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX14_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX14_Pos) & \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX14_Msk) /*!< MUX14 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX14_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUXENABLE_MUX14_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX14_Pos) /*!< MUX14 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX13_Pos (13U) /*!< MUX13 Postion   13         */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX13_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX13_Pos) /*!< MUX13 Mask      0x00002000 */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX13_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX13_Pos) & \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX13_Msk) /*!< MUX13 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX13_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUXENABLE_MUX13_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX13_Pos) /*!< MUX13 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX12_Pos (12U) /*!< MUX12 Postion   12         */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX12_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX12_Pos) /*!< MUX12 Mask      0x00001000 */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX12_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX12_Pos) & \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX12_Msk) /*!< MUX12 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX12_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUXENABLE_MUX12_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX12_Pos) /*!< MUX12 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX11_Pos (11U) /*!< MUX11 Postion   11         */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX11_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX11_Pos) /*!< MUX11 Mask      0x00000800 */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX11_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX11_Pos) & \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX11_Msk) /*!< MUX11 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX11_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUXENABLE_MUX11_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX11_Pos) /*!< MUX11 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX10_Pos (10U) /*!< MUX10 Postion   10         */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX10_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX10_Pos) /*!< MUX10 Mask      0x00000400 */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX10_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX10_Pos) & \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX10_Msk) /*!< MUX10 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX10_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUXENABLE_MUX10_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX10_Pos) /*!< MUX10 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX9_Pos (9U) /*!< MUX9 Postion   9          */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX9_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX9_Pos) /*!< MUX9 Mask      0x00000200 */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX9_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX9_Pos) & \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX9_Msk) /*!< MUX9 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX9_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUXENABLE_MUX9_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX9_Pos) /*!< MUX9 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX8_Pos (8U) /*!< MUX8 Postion   8          */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX8_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX8_Pos) /*!< MUX8 Mask      0x00000100 */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX8_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX8_Pos) & \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX8_Msk) /*!< MUX8 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX8_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUXENABLE_MUX8_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX8_Pos) /*!< MUX8 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX7_Pos (7U) /*!< MUX7 Postion   7          */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX7_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX7_Pos) /*!< MUX7 Mask      0x00000080 */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX7_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX7_Pos) & \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX7_Msk) /*!< MUX7 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX7_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUXENABLE_MUX7_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX7_Pos) /*!< MUX7 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX6_Pos (6U) /*!< MUX6 Postion   6          */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX6_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX6_Pos) /*!< MUX6 Mask      0x00000040 */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX6_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX6_Pos) & \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX6_Msk) /*!< MUX6 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX6_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUXENABLE_MUX6_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX6_Pos) /*!< MUX6 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX5_Pos (5U) /*!< MUX5 Postion   5          */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX5_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX5_Pos) /*!< MUX5 Mask      0x00000020 */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX5_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX5_Pos) & \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX5_Msk) /*!< MUX5 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX5_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUXENABLE_MUX5_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX5_Pos) /*!< MUX5 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX4_Pos (4U) /*!< MUX4 Postion   4          */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX4_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX4_Pos) /*!< MUX4 Mask      0x00000010 */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX4_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX4_Pos) & \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX4_Msk) /*!< MUX4 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX4_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUXENABLE_MUX4_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX4_Pos) /*!< MUX4 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX3_Pos (3U) /*!< MUX3 Postion   3          */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX3_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX3_Pos) /*!< MUX3 Mask      0x00000008 */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX3_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX3_Pos) & \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX3_Msk) /*!< MUX3 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX3_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUXENABLE_MUX3_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX3_Pos) /*!< MUX3 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX2_Pos (2U) /*!< MUX2 Postion   2          */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX2_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX2_Pos) /*!< MUX2 Mask      0x00000004 */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX2_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX2_Pos) & \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX2_Msk) /*!< MUX2 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX2_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUXENABLE_MUX2_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX2_Pos) /*!< MUX2 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX1_Pos (1U) /*!< MUX1 Postion   1          */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX1_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX1_Pos) /*!< MUX1 Mask      0x00000002 */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX1_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX1_Pos) & \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX1_Msk) /*!< MUX1 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX1_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUXENABLE_MUX1_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX1_Pos) /*!< MUX1 Get Value            */


#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX0_Pos (0U) /*!< MUX0 Postion   0          */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX0_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX0_Pos) /*!< MUX0 Mask      0x00000001 */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX0_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTMUXENABLE_MUX0_Pos) & \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX0_Msk) /*!< MUX0 Set Value            */
#define OUTPUT_XBAR_OUTPUTMUXENABLE_MUX0_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTMUXENABLE_MUX0_Msk) >> \
     OUTPUT_XBAR_OUTPUTMUXENABLE_MUX0_Pos) /*!< MUX0 Get Value            */


/* OUTPUTLATCH bitfield */
#define OUTPUT_XBAR_OUTPUTLATCH_OUTPUT8_Pos (7U) /*!< OUTPUT8 Postion   7          */
#define OUTPUT_XBAR_OUTPUTLATCH_OUTPUT8_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTLATCH_OUTPUT8_Pos) /*!< OUTPUT8 Mask      0x00000080 */
#define OUTPUT_XBAR_OUTPUTLATCH_OUTPUT8_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTLATCH_OUTPUT8_Pos) & \
     OUTPUT_XBAR_OUTPUTLATCH_OUTPUT8_Msk) /*!< OUTPUT8 Set Value            */
#define OUTPUT_XBAR_OUTPUTLATCH_OUTPUT8_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTLATCH_OUTPUT8_Msk) >> \
     OUTPUT_XBAR_OUTPUTLATCH_OUTPUT8_Pos) /*!< OUTPUT8 Get Value            */


#define OUTPUT_XBAR_OUTPUTLATCH_OUTPUT7_Pos (6U) /*!< OUTPUT7 Postion   6          */
#define OUTPUT_XBAR_OUTPUTLATCH_OUTPUT7_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTLATCH_OUTPUT7_Pos) /*!< OUTPUT7 Mask      0x00000040 */
#define OUTPUT_XBAR_OUTPUTLATCH_OUTPUT7_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTLATCH_OUTPUT7_Pos) & \
     OUTPUT_XBAR_OUTPUTLATCH_OUTPUT7_Msk) /*!< OUTPUT7 Set Value            */
#define OUTPUT_XBAR_OUTPUTLATCH_OUTPUT7_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTLATCH_OUTPUT7_Msk) >> \
     OUTPUT_XBAR_OUTPUTLATCH_OUTPUT7_Pos) /*!< OUTPUT7 Get Value            */


#define OUTPUT_XBAR_OUTPUTLATCH_OUTPUT6_Pos (5U) /*!< OUTPUT6 Postion   5          */
#define OUTPUT_XBAR_OUTPUTLATCH_OUTPUT6_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTLATCH_OUTPUT6_Pos) /*!< OUTPUT6 Mask      0x00000020 */
#define OUTPUT_XBAR_OUTPUTLATCH_OUTPUT6_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTLATCH_OUTPUT6_Pos) & \
     OUTPUT_XBAR_OUTPUTLATCH_OUTPUT6_Msk) /*!< OUTPUT6 Set Value            */
#define OUTPUT_XBAR_OUTPUTLATCH_OUTPUT6_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTLATCH_OUTPUT6_Msk) >> \
     OUTPUT_XBAR_OUTPUTLATCH_OUTPUT6_Pos) /*!< OUTPUT6 Get Value            */


#define OUTPUT_XBAR_OUTPUTLATCH_OUTPUT5_Pos (4U) /*!< OUTPUT5 Postion   4          */
#define OUTPUT_XBAR_OUTPUTLATCH_OUTPUT5_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTLATCH_OUTPUT5_Pos) /*!< OUTPUT5 Mask      0x00000010 */
#define OUTPUT_XBAR_OUTPUTLATCH_OUTPUT5_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTLATCH_OUTPUT5_Pos) & \
     OUTPUT_XBAR_OUTPUTLATCH_OUTPUT5_Msk) /*!< OUTPUT5 Set Value            */
#define OUTPUT_XBAR_OUTPUTLATCH_OUTPUT5_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTLATCH_OUTPUT5_Msk) >> \
     OUTPUT_XBAR_OUTPUTLATCH_OUTPUT5_Pos) /*!< OUTPUT5 Get Value            */


#define OUTPUT_XBAR_OUTPUTLATCH_OUTPUT4_Pos (3U) /*!< OUTPUT4 Postion   3          */
#define OUTPUT_XBAR_OUTPUTLATCH_OUTPUT4_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTLATCH_OUTPUT4_Pos) /*!< OUTPUT4 Mask      0x00000008 */
#define OUTPUT_XBAR_OUTPUTLATCH_OUTPUT4_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTLATCH_OUTPUT4_Pos) & \
     OUTPUT_XBAR_OUTPUTLATCH_OUTPUT4_Msk) /*!< OUTPUT4 Set Value            */
#define OUTPUT_XBAR_OUTPUTLATCH_OUTPUT4_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTLATCH_OUTPUT4_Msk) >> \
     OUTPUT_XBAR_OUTPUTLATCH_OUTPUT4_Pos) /*!< OUTPUT4 Get Value            */


#define OUTPUT_XBAR_OUTPUTLATCH_OUTPUT3_Pos (2U) /*!< OUTPUT3 Postion   2          */
#define OUTPUT_XBAR_OUTPUTLATCH_OUTPUT3_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTLATCH_OUTPUT3_Pos) /*!< OUTPUT3 Mask      0x00000004 */
#define OUTPUT_XBAR_OUTPUTLATCH_OUTPUT3_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTLATCH_OUTPUT3_Pos) & \
     OUTPUT_XBAR_OUTPUTLATCH_OUTPUT3_Msk) /*!< OUTPUT3 Set Value            */
#define OUTPUT_XBAR_OUTPUTLATCH_OUTPUT3_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTLATCH_OUTPUT3_Msk) >> \
     OUTPUT_XBAR_OUTPUTLATCH_OUTPUT3_Pos) /*!< OUTPUT3 Get Value            */


#define OUTPUT_XBAR_OUTPUTLATCH_OUTPUT2_Pos (1U) /*!< OUTPUT2 Postion   1          */
#define OUTPUT_XBAR_OUTPUTLATCH_OUTPUT2_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTLATCH_OUTPUT2_Pos) /*!< OUTPUT2 Mask      0x00000002 */
#define OUTPUT_XBAR_OUTPUTLATCH_OUTPUT2_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTLATCH_OUTPUT2_Pos) & \
     OUTPUT_XBAR_OUTPUTLATCH_OUTPUT2_Msk) /*!< OUTPUT2 Set Value            */
#define OUTPUT_XBAR_OUTPUTLATCH_OUTPUT2_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTLATCH_OUTPUT2_Msk) >> \
     OUTPUT_XBAR_OUTPUTLATCH_OUTPUT2_Pos) /*!< OUTPUT2 Get Value            */


#define OUTPUT_XBAR_OUTPUTLATCH_OUTPUT1_Pos (0U) /*!< OUTPUT1 Postion   0          */
#define OUTPUT_XBAR_OUTPUTLATCH_OUTPUT1_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTLATCH_OUTPUT1_Pos) /*!< OUTPUT1 Mask      0x00000001 */
#define OUTPUT_XBAR_OUTPUTLATCH_OUTPUT1_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTLATCH_OUTPUT1_Pos) & \
     OUTPUT_XBAR_OUTPUTLATCH_OUTPUT1_Msk) /*!< OUTPUT1 Set Value            */
#define OUTPUT_XBAR_OUTPUTLATCH_OUTPUT1_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTLATCH_OUTPUT1_Msk) >> \
     OUTPUT_XBAR_OUTPUTLATCH_OUTPUT1_Pos) /*!< OUTPUT1 Get Value            */


/* OUTPUTLATCHCLR bitfield */
#define OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT8_Pos (7U) /*!< OUTPUT8 Postion   7          */
#define OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT8_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT8_Pos) /*!< OUTPUT8 Mask      0x00000080 */
#define OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT8_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT8_Pos) & \
     OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT8_Msk) /*!< OUTPUT8 Set Value            */
#define OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT8_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT8_Msk) >> \
     OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT8_Pos) /*!< OUTPUT8 Get Value            */


#define OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT7_Pos (6U) /*!< OUTPUT7 Postion   6          */
#define OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT7_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT7_Pos) /*!< OUTPUT7 Mask      0x00000040 */
#define OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT7_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT7_Pos) & \
     OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT7_Msk) /*!< OUTPUT7 Set Value            */
#define OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT7_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT7_Msk) >> \
     OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT7_Pos) /*!< OUTPUT7 Get Value            */


#define OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT6_Pos (5U) /*!< OUTPUT6 Postion   5          */
#define OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT6_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT6_Pos) /*!< OUTPUT6 Mask      0x00000020 */
#define OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT6_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT6_Pos) & \
     OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT6_Msk) /*!< OUTPUT6 Set Value            */
#define OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT6_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT6_Msk) >> \
     OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT6_Pos) /*!< OUTPUT6 Get Value            */


#define OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT5_Pos (4U) /*!< OUTPUT5 Postion   4          */
#define OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT5_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT5_Pos) /*!< OUTPUT5 Mask      0x00000010 */
#define OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT5_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT5_Pos) & \
     OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT5_Msk) /*!< OUTPUT5 Set Value            */
#define OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT5_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT5_Msk) >> \
     OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT5_Pos) /*!< OUTPUT5 Get Value            */


#define OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT4_Pos (3U) /*!< OUTPUT4 Postion   3          */
#define OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT4_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT4_Pos) /*!< OUTPUT4 Mask      0x00000008 */
#define OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT4_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT4_Pos) & \
     OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT4_Msk) /*!< OUTPUT4 Set Value            */
#define OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT4_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT4_Msk) >> \
     OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT4_Pos) /*!< OUTPUT4 Get Value            */


#define OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT3_Pos (2U) /*!< OUTPUT3 Postion   2          */
#define OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT3_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT3_Pos) /*!< OUTPUT3 Mask      0x00000004 */
#define OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT3_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT3_Pos) & \
     OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT3_Msk) /*!< OUTPUT3 Set Value            */
#define OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT3_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT3_Msk) >> \
     OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT3_Pos) /*!< OUTPUT3 Get Value            */


#define OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT2_Pos (1U) /*!< OUTPUT2 Postion   1          */
#define OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT2_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT2_Pos) /*!< OUTPUT2 Mask      0x00000002 */
#define OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT2_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT2_Pos) & \
     OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT2_Msk) /*!< OUTPUT2 Set Value            */
#define OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT2_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT2_Msk) >> \
     OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT2_Pos) /*!< OUTPUT2 Get Value            */


#define OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT1_Pos (0U) /*!< OUTPUT1 Postion   0          */
#define OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT1_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT1_Pos) /*!< OUTPUT1 Mask      0x00000001 */
#define OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT1_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT1_Pos) & \
     OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT1_Msk) /*!< OUTPUT1 Set Value            */
#define OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT1_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT1_Msk) >> \
     OUTPUT_XBAR_OUTPUTLATCHCLR_OUTPUT1_Pos) /*!< OUTPUT1 Get Value            */


/* OUTPUTLATCHFRC bitfield */
#define OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT8_Pos (7U) /*!< OUTPUT8 Postion   7          */
#define OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT8_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT8_Pos) /*!< OUTPUT8 Mask      0x00000080 */
#define OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT8_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT8_Pos) & \
     OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT8_Msk) /*!< OUTPUT8 Set Value            */
#define OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT8_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT8_Msk) >> \
     OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT8_Pos) /*!< OUTPUT8 Get Value            */


#define OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT7_Pos (6U) /*!< OUTPUT7 Postion   6          */
#define OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT7_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT7_Pos) /*!< OUTPUT7 Mask      0x00000040 */
#define OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT7_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT7_Pos) & \
     OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT7_Msk) /*!< OUTPUT7 Set Value            */
#define OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT7_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT7_Msk) >> \
     OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT7_Pos) /*!< OUTPUT7 Get Value            */


#define OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT6_Pos (5U) /*!< OUTPUT6 Postion   5          */
#define OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT6_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT6_Pos) /*!< OUTPUT6 Mask      0x00000020 */
#define OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT6_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT6_Pos) & \
     OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT6_Msk) /*!< OUTPUT6 Set Value            */
#define OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT6_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT6_Msk) >> \
     OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT6_Pos) /*!< OUTPUT6 Get Value            */


#define OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT5_Pos (4U) /*!< OUTPUT5 Postion   4          */
#define OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT5_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT5_Pos) /*!< OUTPUT5 Mask      0x00000010 */
#define OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT5_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT5_Pos) & \
     OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT5_Msk) /*!< OUTPUT5 Set Value            */
#define OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT5_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT5_Msk) >> \
     OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT5_Pos) /*!< OUTPUT5 Get Value            */


#define OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT4_Pos (3U) /*!< OUTPUT4 Postion   3          */
#define OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT4_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT4_Pos) /*!< OUTPUT4 Mask      0x00000008 */
#define OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT4_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT4_Pos) & \
     OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT4_Msk) /*!< OUTPUT4 Set Value            */
#define OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT4_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT4_Msk) >> \
     OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT4_Pos) /*!< OUTPUT4 Get Value            */


#define OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT3_Pos (2U) /*!< OUTPUT3 Postion   2          */
#define OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT3_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT3_Pos) /*!< OUTPUT3 Mask      0x00000004 */
#define OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT3_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT3_Pos) & \
     OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT3_Msk) /*!< OUTPUT3 Set Value            */
#define OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT3_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT3_Msk) >> \
     OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT3_Pos) /*!< OUTPUT3 Get Value            */


#define OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT2_Pos (1U) /*!< OUTPUT2 Postion   1          */
#define OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT2_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT2_Pos) /*!< OUTPUT2 Mask      0x00000002 */
#define OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT2_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT2_Pos) & \
     OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT2_Msk) /*!< OUTPUT2 Set Value            */
#define OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT2_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT2_Msk) >> \
     OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT2_Pos) /*!< OUTPUT2 Get Value            */


#define OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT1_Pos (0U) /*!< OUTPUT1 Postion   0          */
#define OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT1_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT1_Pos) /*!< OUTPUT1 Mask      0x00000001 */
#define OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT1_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT1_Pos) & \
     OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT1_Msk) /*!< OUTPUT1 Set Value            */
#define OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT1_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT1_Msk) >> \
     OUTPUT_XBAR_OUTPUTLATCHFRC_OUTPUT1_Pos) /*!< OUTPUT1 Get Value            */


/* OUTPUTLATCHENABLE bitfield */
#define OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT8_Pos (7U) /*!< OUTPUT8 Postion   7          */
#define OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT8_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT8_Pos) /*!< OUTPUT8 Mask      0x00000080 */
#define OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT8_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT8_Pos) & \
     OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT8_Msk) /*!< OUTPUT8 Set Value            */
#define OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT8_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT8_Msk) >> \
     OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT8_Pos) /*!< OUTPUT8 Get Value            */


#define OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT7_Pos (6U) /*!< OUTPUT7 Postion   6          */
#define OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT7_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT7_Pos) /*!< OUTPUT7 Mask      0x00000040 */
#define OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT7_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT7_Pos) & \
     OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT7_Msk) /*!< OUTPUT7 Set Value            */
#define OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT7_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT7_Msk) >> \
     OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT7_Pos) /*!< OUTPUT7 Get Value            */


#define OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT6_Pos (5U) /*!< OUTPUT6 Postion   5          */
#define OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT6_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT6_Pos) /*!< OUTPUT6 Mask      0x00000020 */
#define OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT6_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT6_Pos) & \
     OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT6_Msk) /*!< OUTPUT6 Set Value            */
#define OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT6_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT6_Msk) >> \
     OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT6_Pos) /*!< OUTPUT6 Get Value            */


#define OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT5_Pos (4U) /*!< OUTPUT5 Postion   4          */
#define OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT5_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT5_Pos) /*!< OUTPUT5 Mask      0x00000010 */
#define OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT5_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT5_Pos) & \
     OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT5_Msk) /*!< OUTPUT5 Set Value            */
#define OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT5_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT5_Msk) >> \
     OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT5_Pos) /*!< OUTPUT5 Get Value            */


#define OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT4_Pos (3U) /*!< OUTPUT4 Postion   3          */
#define OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT4_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT4_Pos) /*!< OUTPUT4 Mask      0x00000008 */
#define OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT4_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT4_Pos) & \
     OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT4_Msk) /*!< OUTPUT4 Set Value            */
#define OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT4_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT4_Msk) >> \
     OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT4_Pos) /*!< OUTPUT4 Get Value            */


#define OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT3_Pos (2U) /*!< OUTPUT3 Postion   2          */
#define OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT3_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT3_Pos) /*!< OUTPUT3 Mask      0x00000004 */
#define OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT3_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT3_Pos) & \
     OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT3_Msk) /*!< OUTPUT3 Set Value            */
#define OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT3_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT3_Msk) >> \
     OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT3_Pos) /*!< OUTPUT3 Get Value            */


#define OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT2_Pos (1U) /*!< OUTPUT2 Postion   1          */
#define OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT2_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT2_Pos) /*!< OUTPUT2 Mask      0x00000002 */
#define OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT2_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT2_Pos) & \
     OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT2_Msk) /*!< OUTPUT2 Set Value            */
#define OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT2_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT2_Msk) >> \
     OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT2_Pos) /*!< OUTPUT2 Get Value            */


#define OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT1_Pos (0U) /*!< OUTPUT1 Postion   0          */
#define OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT1_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT1_Pos) /*!< OUTPUT1 Mask      0x00000001 */
#define OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT1_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT1_Pos) & \
     OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT1_Msk) /*!< OUTPUT1 Set Value            */
#define OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT1_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT1_Msk) >> \
     OUTPUT_XBAR_OUTPUTLATCHENABLE_OUTPUT1_Pos) /*!< OUTPUT1 Get Value            */


/* OUTPUTINV bitfield */
#define OUTPUT_XBAR_OUTPUTINV_OUTPUT8_Pos (7U) /*!< OUTPUT8 Postion   7          */
#define OUTPUT_XBAR_OUTPUTINV_OUTPUT8_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTINV_OUTPUT8_Pos) /*!< OUTPUT8 Mask      0x00000080 */
#define OUTPUT_XBAR_OUTPUTINV_OUTPUT8_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTINV_OUTPUT8_Pos) & \
     OUTPUT_XBAR_OUTPUTINV_OUTPUT8_Msk) /*!< OUTPUT8 Set Value            */
#define OUTPUT_XBAR_OUTPUTINV_OUTPUT8_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTINV_OUTPUT8_Msk) >> \
     OUTPUT_XBAR_OUTPUTINV_OUTPUT8_Pos) /*!< OUTPUT8 Get Value            */


#define OUTPUT_XBAR_OUTPUTINV_OUTPUT7_Pos (6U) /*!< OUTPUT7 Postion   6          */
#define OUTPUT_XBAR_OUTPUTINV_OUTPUT7_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTINV_OUTPUT7_Pos) /*!< OUTPUT7 Mask      0x00000040 */
#define OUTPUT_XBAR_OUTPUTINV_OUTPUT7_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTINV_OUTPUT7_Pos) & \
     OUTPUT_XBAR_OUTPUTINV_OUTPUT7_Msk) /*!< OUTPUT7 Set Value            */
#define OUTPUT_XBAR_OUTPUTINV_OUTPUT7_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTINV_OUTPUT7_Msk) >> \
     OUTPUT_XBAR_OUTPUTINV_OUTPUT7_Pos) /*!< OUTPUT7 Get Value            */


#define OUTPUT_XBAR_OUTPUTINV_OUTPUT6_Pos (5U) /*!< OUTPUT6 Postion   5          */
#define OUTPUT_XBAR_OUTPUTINV_OUTPUT6_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTINV_OUTPUT6_Pos) /*!< OUTPUT6 Mask      0x00000020 */
#define OUTPUT_XBAR_OUTPUTINV_OUTPUT6_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTINV_OUTPUT6_Pos) & \
     OUTPUT_XBAR_OUTPUTINV_OUTPUT6_Msk) /*!< OUTPUT6 Set Value            */
#define OUTPUT_XBAR_OUTPUTINV_OUTPUT6_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTINV_OUTPUT6_Msk) >> \
     OUTPUT_XBAR_OUTPUTINV_OUTPUT6_Pos) /*!< OUTPUT6 Get Value            */


#define OUTPUT_XBAR_OUTPUTINV_OUTPUT5_Pos (4U) /*!< OUTPUT5 Postion   4          */
#define OUTPUT_XBAR_OUTPUTINV_OUTPUT5_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTINV_OUTPUT5_Pos) /*!< OUTPUT5 Mask      0x00000010 */
#define OUTPUT_XBAR_OUTPUTINV_OUTPUT5_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTINV_OUTPUT5_Pos) & \
     OUTPUT_XBAR_OUTPUTINV_OUTPUT5_Msk) /*!< OUTPUT5 Set Value            */
#define OUTPUT_XBAR_OUTPUTINV_OUTPUT5_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTINV_OUTPUT5_Msk) >> \
     OUTPUT_XBAR_OUTPUTINV_OUTPUT5_Pos) /*!< OUTPUT5 Get Value            */


#define OUTPUT_XBAR_OUTPUTINV_OUTPUT4_Pos (3U) /*!< OUTPUT4 Postion   3          */
#define OUTPUT_XBAR_OUTPUTINV_OUTPUT4_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTINV_OUTPUT4_Pos) /*!< OUTPUT4 Mask      0x00000008 */
#define OUTPUT_XBAR_OUTPUTINV_OUTPUT4_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTINV_OUTPUT4_Pos) & \
     OUTPUT_XBAR_OUTPUTINV_OUTPUT4_Msk) /*!< OUTPUT4 Set Value            */
#define OUTPUT_XBAR_OUTPUTINV_OUTPUT4_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTINV_OUTPUT4_Msk) >> \
     OUTPUT_XBAR_OUTPUTINV_OUTPUT4_Pos) /*!< OUTPUT4 Get Value            */


#define OUTPUT_XBAR_OUTPUTINV_OUTPUT3_Pos (2U) /*!< OUTPUT3 Postion   2          */
#define OUTPUT_XBAR_OUTPUTINV_OUTPUT3_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTINV_OUTPUT3_Pos) /*!< OUTPUT3 Mask      0x00000004 */
#define OUTPUT_XBAR_OUTPUTINV_OUTPUT3_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTINV_OUTPUT3_Pos) & \
     OUTPUT_XBAR_OUTPUTINV_OUTPUT3_Msk) /*!< OUTPUT3 Set Value            */
#define OUTPUT_XBAR_OUTPUTINV_OUTPUT3_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTINV_OUTPUT3_Msk) >> \
     OUTPUT_XBAR_OUTPUTINV_OUTPUT3_Pos) /*!< OUTPUT3 Get Value            */


#define OUTPUT_XBAR_OUTPUTINV_OUTPUT2_Pos (1U) /*!< OUTPUT2 Postion   1          */
#define OUTPUT_XBAR_OUTPUTINV_OUTPUT2_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTINV_OUTPUT2_Pos) /*!< OUTPUT2 Mask      0x00000002 */
#define OUTPUT_XBAR_OUTPUTINV_OUTPUT2_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTINV_OUTPUT2_Pos) & \
     OUTPUT_XBAR_OUTPUTINV_OUTPUT2_Msk) /*!< OUTPUT2 Set Value            */
#define OUTPUT_XBAR_OUTPUTINV_OUTPUT2_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTINV_OUTPUT2_Msk) >> \
     OUTPUT_XBAR_OUTPUTINV_OUTPUT2_Pos) /*!< OUTPUT2 Get Value            */


#define OUTPUT_XBAR_OUTPUTINV_OUTPUT1_Pos (0U) /*!< OUTPUT1 Postion   0          */
#define OUTPUT_XBAR_OUTPUTINV_OUTPUT1_Msk \
    (0x1U << OUTPUT_XBAR_OUTPUTINV_OUTPUT1_Pos) /*!< OUTPUT1 Mask      0x00000001 */
#define OUTPUT_XBAR_OUTPUTINV_OUTPUT1_Set(x)                 \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTINV_OUTPUT1_Pos) & \
     OUTPUT_XBAR_OUTPUTINV_OUTPUT1_Msk) /*!< OUTPUT1 Set Value            */
#define OUTPUT_XBAR_OUTPUTINV_OUTPUT1_Get(x)                \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTINV_OUTPUT1_Msk) >> \
     OUTPUT_XBAR_OUTPUTINV_OUTPUT1_Pos) /*!< OUTPUT1 Get Value            */


/* OUTPUTLOCK bitfield */
#define OUTPUT_XBAR_OUTPUTLOCK_KEY_Pos (16U)                                       /*!< KEY Postion   16         */
#define OUTPUT_XBAR_OUTPUTLOCK_KEY_Msk (0xffffU << OUTPUT_XBAR_OUTPUTLOCK_KEY_Pos) /*!< KEY Mask      0xFFFF0000 */
#define OUTPUT_XBAR_OUTPUTLOCK_KEY_Set(x) \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTLOCK_KEY_Pos) & OUTPUT_XBAR_OUTPUTLOCK_KEY_Msk) /*!< KEY Set Value */
#define OUTPUT_XBAR_OUTPUTLOCK_KEY_Get(x) \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTLOCK_KEY_Msk) >> OUTPUT_XBAR_OUTPUTLOCK_KEY_Pos) /*!< KEY Get Value */


#define OUTPUT_XBAR_OUTPUTLOCK_LOCK_Pos (0U)                                      /*!< LOCK Postion   0          */
#define OUTPUT_XBAR_OUTPUTLOCK_LOCK_Msk (0x1U << OUTPUT_XBAR_OUTPUTLOCK_LOCK_Pos) /*!< LOCK Mask      0x00000001 */
#define OUTPUT_XBAR_OUTPUTLOCK_LOCK_Set(x) \
    (((uint32_t) (x) << OUTPUT_XBAR_OUTPUTLOCK_LOCK_Pos) & OUTPUT_XBAR_OUTPUTLOCK_LOCK_Msk) /*!< LOCK Set Value */
#define OUTPUT_XBAR_OUTPUTLOCK_LOCK_Get(x) \
    (((uint32_t) (x) &OUTPUT_XBAR_OUTPUTLOCK_LOCK_Msk) >> OUTPUT_XBAR_OUTPUTLOCK_LOCK_Pos) /*!< LOCK Get Value */


/*!
 * @}
 */


/*!
 * @}
 */ /* end of HS32F7D377_XBAR_REGISTER */

#endif /* HS32F7D377_XBAR_H */
