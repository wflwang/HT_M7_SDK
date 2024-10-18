/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file HS32F7D377_gpio_ctrl.h
 * \brief HS32F7D377 GPIO CTRL register file
 * \version 1.0.0
 */

#ifndef HS32F7D377_GPIO_CTRL_H
#define HS32F7D377_GPIO_CTRL_H

/*!
 * \addtogroup HS32F7D377_GPIO_CTRL_REGISTER HS32F7D377 GPIO_CTRL Register
 * \ingroup HS32F7D377_REGISTER
 *
 * \brief GPIO CTRL register layout, bitfield and address definitions
 *
 * @{
 */

/*!
 * \name GPIO CTRL Register Layout
 *
 * @{
 */

/*! \brief GPIO CTRL register layout */
typedef struct
{
    struct
    {
        union
        {
            __IOM uint32_t CTRL; /*!< Offset 0x00, GPIO Qualification Sampling Period Control Register */

            struct
            {
                __IOM uint32_t QUALPRD0 : 8; /*!< [7:0] : Qualification sampling period for GPIO8 to GPIO0  0x0 RW
                                                0x00,QUALPRDx = PLLSYSCLK          0x0             RW 0x01,QUALPRDx =
                                                PLLSYSCLK/2        0x0             RW               0x02,QUALPRDx =
                                                PLLSYSCLK/4        0x0             RW               .... 0x0 RW
                                                0xFF,QUALPRDx = PLLSYSCLK/510      0x0             RW Reset type: SYSRSn
                                              */
                __IOM uint32_t QUALPRD1 : 8; /*!< [15:8] : Qualification sampling period for GPIO16 to GPIO8  0x0 RW
                                                0x00,QUALPRDx = PLLSYSCLK          0x0             RW 0x01,QUALPRDx =
                                                PLLSYSCLK/2        0x0             RW               0x02,QUALPRDx =
                                                PLLSYSCLK/4        0x0             RW               .... 0x0 RW
                                                0xFF,QUALPRDx = PLLSYSCLK/510      0x0             RW Reset type: SYSRSn
                                              */
                __IOM uint32_t QUALPRD2 : 8; /*!< [23:16] : Qualification sampling period for GPIO24 to GPIO16  0x0 RW
                                                0x00,QUALPRDx = PLLSYSCLK          0x0             RW 0x01,QUALPRDx =
                                                PLLSYSCLK/2        0x0             RW               0x02,QUALPRDx =
                                                PLLSYSCLK/4        0x0             RW               .... 0x0 RW
                                                0xFF,QUALPRDx = PLLSYSCLK/510      0x0             RW Reset type: SYSRSn
                                              */
                __IOM uint32_t QUALPRD3 : 8; /*!< [31:24] : Qualification sampling period for GPIO32 to GPIO24  0x0 RW
                                                0x00,QUALPRDx = PLLSYSCLK          0x0             RW 0x01,QUALPRDx =
                                                PLLSYSCLK/2        0x0             RW               0x02,QUALPRDx =
                                                PLLSYSCLK/4        0x0             RW               .... 0x0 RW
                                                0xFF,QUALPRDx = PLLSYSCLK/510      0x0             RW Reset type: SYSRSn
                                              */
            } CTRLb;
        };

        union
        {
            __IOM uint32_t QSEL[2]; /*!< Offset 0x04, GPIO Qualifier Select Register */

            struct
            {
                __IOM uint32_t QSEL0  : 2; /*!< [1:0] : Input qualification type, Reset type: SYSRSn */
                __IOM uint32_t QSEL1  : 2; /*!< [3:2] : Input qualification type, Reset type: SYSRSn */
                __IOM uint32_t QSEL2  : 2; /*!< [5:4] : Input qualification type, Reset type: SYSRSn */
                __IOM uint32_t QSEL3  : 2; /*!< [7:6] : Input qualification type, Reset type: SYSRSn */
                __IOM uint32_t QSEL4  : 2; /*!< [9:8] : Input qualification type, Reset type: SYSRSn */
                __IOM uint32_t QSEL5  : 2; /*!< [11:10] : Input qualification type, Reset type: SYSRSn */
                __IOM uint32_t QSEL6  : 2; /*!< [13:12] : Input qualification type, Reset type: SYSRSn */
                __IOM uint32_t QSEL7  : 2; /*!< [15:14] : Input qualification type, Reset type: SYSRSn */
                __IOM uint32_t QSEL8  : 2; /*!< [17:16] : Input qualification type, Reset type: SYSRSn */
                __IOM uint32_t QSEL9  : 2; /*!< [19:18] : Input qualification type, Reset type: SYSRSn */
                __IOM uint32_t QSEL10 : 2; /*!< [21:20] : Input qualification type, Reset type: SYSRSn */
                __IOM uint32_t QSEL11 : 2; /*!< [23:22] : Input qualification type, Reset type: SYSRSn */
                __IOM uint32_t QSEL12 : 2; /*!< [25:24] : Input qualification type, Reset type: SYSRSn */
                __IOM uint32_t QSEL13 : 2; /*!< [27:26] : Input qualification type, Reset type: SYSRSn */
                __IOM uint32_t QSEL14 : 2; /*!< [29:28] : Input qualification type, Reset type: SYSRSn */
                __IOM uint32_t QSEL15 : 2; /*!< [31:30] : Input qualification type, Reset type: SYSRSn */
            } QSELb[2];
        };

        union
        {
            __IOM uint32_t MUX[2]; /*!< Offset: 0x0c, GPIO Mux Register */

            struct
            {
                __IOM uint32_t MUX0  : 2; /*!< [1:0] : Defines pin-mux selection for GPIO, Reset type: SYSRSn */
                __IOM uint32_t MUX1  : 2; /*!< [3:2] : Defines pin-mux selection for GPIO, Reset type: SYSRSn */
                __IOM uint32_t MUX2  : 2; /*!< [5:4] : Defines pin-mux selection for GPIO, Reset type: SYSRSn */
                __IOM uint32_t MUX3  : 2; /*!< [7:6] : Defines pin-mux selection for GPIO, Reset type: SYSRSn */
                __IOM uint32_t MUX4  : 2; /*!< [9:8] : Defines pin-mux selection for GPIO, Reset type: SYSRSn */
                __IOM uint32_t MUX5  : 2; /*!< [11:10] : Defines pin-mux selection for GPIO, Reset type: SYSRSn */
                __IOM uint32_t MUX6  : 2; /*!< [13:12] : Defines pin-mux selection for GPIO, Reset type: SYSRSn */
                __IOM uint32_t MUX7  : 2; /*!< [15:14] : Defines pin-mux selection for GPIO, Reset type: SYSRSn */
                __IOM uint32_t MUX8  : 2; /*!< [17:16] : Defines pin-mux selection for GPIO, Reset type: SYSRSn */
                __IOM uint32_t MUX9  : 2; /*!< [19:18] : Defines pin-mux selection for GPIO, Reset type: SYSRSn */
                __IOM uint32_t MUX10 : 2; /*!< [21:20] : Defines pin-mux selection for GPIO, Reset type: SYSRSn */
                __IOM uint32_t MUX11 : 2; /*!< [23:22] : Defines pin-mux selection for GPIO, Reset type: SYSRSn */
                __IOM uint32_t MUX12 : 2; /*!< [25:24] : Defines pin-mux selection for GPIO, Reset type: SYSRSn */
                __IOM uint32_t MUX13 : 2; /*!< [27:26] : Defines pin-mux selection for GPIO, Reset type: SYSRSn */
                __IOM uint32_t MUX14 : 2; /*!< [29:28] : Defines pin-mux selection for GPIO, Reset type: SYSRSn */
                __IOM uint32_t MUX15 : 2; /*!< [31:30] : Defines pin-mux selection for GPIO, Reset type: SYSRSn */
            } MUXb[2];
        };

        union
        {
            __IOM uint32_t DIR; /*!< Offset: 0x14, GPIO Direction Register */

            struct
            {
                __IOM uint32_t DIR0  : 1; /*!< [0:0] : Defines direction for this pin in GPIO, Reset type: SYSRSn */
                __IOM uint32_t DIR1  : 1; /*!< [1:1] : Defines direction for this pin in GPIO, Reset type: SYSRSn */
                __IOM uint32_t DIR2  : 1; /*!< [2:2] : Defines direction for this pin in GPIO, Reset type: SYSRSn */
                __IOM uint32_t DIR3  : 1; /*!< [3:3] : Defines direction for this pin in GPIO, Reset type: SYSRSn */
                __IOM uint32_t DIR4  : 1; /*!< [4:4] : Defines direction for this pin in GPIO, Reset type: SYSRSn */
                __IOM uint32_t DIR5  : 1; /*!< [5:5] : Defines direction for this pin in GPIO, Reset type: SYSRSn */
                __IOM uint32_t DIR6  : 1; /*!< [6:6] : Defines direction for this pin in GPIO, Reset type: SYSRSn */
                __IOM uint32_t DIR7  : 1; /*!< [7:7] : Defines direction for this pin in GPIO, Reset type: SYSRSn */
                __IOM uint32_t DIR8  : 1; /*!< [8:8] : Defines direction for this pin in GPIO, Reset type: SYSRSn */
                __IOM uint32_t DIR9  : 1; /*!< [9:9] : Defines direction for this pin in GPIO, Reset type: SYSRSn */
                __IOM uint32_t DIR10 : 1; /*!< [10:10] : Defines direction for this pin in GPIO, Reset type: SYSRSn */
                __IOM uint32_t DIR11 : 1; /*!< [11:11] : Defines direction for this pin in GPIO, Reset type: SYSRSn */
                __IOM uint32_t DIR12 : 1; /*!< [12:12] : Defines direction for this pin in GPIO, Reset type: SYSRSn */
                __IOM uint32_t DIR13 : 1; /*!< [13:13] : Defines direction for this pin in GPIO, Reset type: SYSRSn */
                __IOM uint32_t DIR14 : 1; /*!< [14:14] : Defines direction for this pin in GPIO, Reset type: SYSRSn */
                __IOM uint32_t DIR15 : 1; /*!< [15:15] : Defines direction for this pin in GPIO, Reset type: SYSRSn */
                __IOM uint32_t DIR16 : 1; /*!< [16:16] : Defines direction for this pin in GPIO, Reset type: SYSRSn */
                __IOM uint32_t DIR17 : 1; /*!< [17:17] : Defines direction for this pin in GPIO, Reset type: SYSRSn */
                __IOM uint32_t DIR18 : 1; /*!< [18:18] : Defines direction for this pin in GPIO, Reset type: SYSRSn */
                __IOM uint32_t DIR19 : 1; /*!< [19:19] : Defines direction for this pin in GPIO, Reset type: SYSRSn */
                __IOM uint32_t DIR20 : 1; /*!< [20:20] : Defines direction for this pin in GPIO, Reset type: SYSRSn */
                __IOM uint32_t DIR21 : 1; /*!< [21:21] : Defines direction for this pin in GPIO, Reset type: SYSRSn */
                __IOM uint32_t DIR22 : 1; /*!< [22:22] : Defines direction for this pin in GPIO, Reset type: SYSRSn */
                __IOM uint32_t DIR23 : 1; /*!< [23:23] : Defines direction for this pin in GPIO, Reset type: SYSRSn */
                __IOM uint32_t DIR24 : 1; /*!< [24:24] : Defines direction for this pin in GPIO, Reset type: SYSRSn */
                __IOM uint32_t DIR25 : 1; /*!< [25:25] : Defines direction for this pin in GPIO, Reset type: SYSRSn */
                __IOM uint32_t DIR26 : 1; /*!< [26:26] : Defines direction for this pin in GPIO, Reset type: SYSRSn */
                __IOM uint32_t DIR27 : 1; /*!< [27:27] : Defines direction for this pin in GPIO, Reset type: SYSRSn */
                __IOM uint32_t DIR28 : 1; /*!< [28:28] : Defines direction for this pin in GPIO, Reset type: SYSRSn */
                __IOM uint32_t DIR29 : 1; /*!< [29:29] : Defines direction for this pin in GPIO, Reset type: SYSRSn */
                __IOM uint32_t DIR30 : 1; /*!< [30:30] : Defines direction for this pin in GPIO, Reset type: SYSRSn */
                __IOM uint32_t DIR31 : 1; /*!< [31:31] : Defines direction for this pin in GPIO, Reset type: SYSRSn */
            } DIRb;
        };

        union
        {
            __IOM uint32_t PUD; /*!< Offset: 0x18, GPIO Logic H Pull Up Disable Register */

            struct
            {
                __IOM uint32_t
                    PUD0 : 1; /*!< [0:0] : Pull-Up Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PUD1 : 1; /*!< [1:1] : Pull-Up Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PUD2 : 1; /*!< [2:2] : Pull-Up Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PUD3 : 1; /*!< [3:3] : Pull-Up Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PUD4 : 1; /*!< [4:4] : Pull-Up Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PUD5 : 1; /*!< [5:5] : Pull-Up Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PUD6 : 1; /*!< [6:6] : Pull-Up Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PUD7 : 1; /*!< [7:7] : Pull-Up Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PUD8 : 1; /*!< [8:8] : Pull-Up Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PUD9 : 1; /*!< [9:9] : Pull-Up Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PUD10 : 1; /*!< [10:10] : Pull-Up Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PUD11 : 1; /*!< [11:11] : Pull-Up Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PUD12 : 1; /*!< [12:12] : Pull-Up Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PUD13 : 1; /*!< [13:13] : Pull-Up Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PUD14 : 1; /*!< [14:14] : Pull-Up Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PUD15 : 1; /*!< [15:15] : Pull-Up Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PUD16 : 1; /*!< [16:16] : Pull-Up Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PUD17 : 1; /*!< [17:17] : Pull-Up Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PUD18 : 1; /*!< [18:18] : Pull-Up Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PUD19 : 1; /*!< [19:19] : Pull-Up Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PUD20 : 1; /*!< [20:20] : Pull-Up Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PUD21 : 1; /*!< [21:21] : Pull-Up Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PUD22 : 1; /*!< [22:22] : Pull-Up Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PUD23 : 1; /*!< [23:23] : Pull-Up Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PUD24 : 1; /*!< [24:24] : Pull-Up Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PUD25 : 1; /*!< [25:25] : Pull-Up Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PUD26 : 1; /*!< [26:26] : Pull-Up Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PUD27 : 1; /*!< [27:27] : Pull-Up Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PUD28 : 1; /*!< [28:28] : Pull-Up Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PUD29 : 1; /*!< [29:29] : Pull-Up Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PUD30 : 1; /*!< [30:30] : Pull-Up Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PUD31 : 1; /*!< [31:31] : Pull-Up Disable control for this pin. Default is H, Reset type: SYSRSn */
            } PUDb;
        };

        uint8_t RSV_0X1C[4]; /*!< Offset: 0x1c~0x1f, reserved */

        union
        {
            __IOM uint32_t INV; /*!< Offset: 0x20, GPIO Input Polarity Invert Registers */

            struct
            {
                __IOM uint32_t INV0  : 1; /*!< [0:0] : Input inversion control for this pin, Reset type: SYSRSn */
                __IOM uint32_t INV1  : 1; /*!< [1:1] : Input inversion control for this pin, Reset type: SYSRSn */
                __IOM uint32_t INV2  : 1; /*!< [2:2] : Input inversion control for this pin, Reset type: SYSRSn */
                __IOM uint32_t INV3  : 1; /*!< [3:3] : Input inversion control for this pin, Reset type: SYSRSn */
                __IOM uint32_t INV4  : 1; /*!< [4:4] : Input inversion control for this pin, Reset type: SYSRSn */
                __IOM uint32_t INV5  : 1; /*!< [5:5] : Input inversion control for this pin, Reset type: SYSRSn */
                __IOM uint32_t INV6  : 1; /*!< [6:6] : Input inversion control for this pin, Reset type: SYSRSn */
                __IOM uint32_t INV7  : 1; /*!< [7:7] : Input inversion control for this pin, Reset type: SYSRSn */
                __IOM uint32_t INV8  : 1; /*!< [8:8] : Input inversion control for this pin, Reset type: SYSRSn */
                __IOM uint32_t INV9  : 1; /*!< [9:9] : Input inversion control for this pin, Reset type: SYSRSn */
                __IOM uint32_t INV10 : 1; /*!< [10:10] : Input inversion control for this pin, Reset type: SYSRSn */
                __IOM uint32_t INV11 : 1; /*!< [11:11] : Input inversion control for this pin, Reset type: SYSRSn */
                __IOM uint32_t INV12 : 1; /*!< [12:12] : Input inversion control for this pin, Reset type: SYSRSn */
                __IOM uint32_t INV13 : 1; /*!< [13:13] : Input inversion control for this pin, Reset type: SYSRSn */
                __IOM uint32_t INV14 : 1; /*!< [14:14] : Input inversion control for this pin, Reset type: SYSRSn */
                __IOM uint32_t INV15 : 1; /*!< [15:15] : Input inversion control for this pin, Reset type: SYSRSn */
                __IOM uint32_t INV16 : 1; /*!< [16:16] : Input inversion control for this pin, Reset type: SYSRSn */
                __IOM uint32_t INV17 : 1; /*!< [17:17] : Input inversion control for this pin, Reset type: SYSRSn */
                __IOM uint32_t INV18 : 1; /*!< [18:18] : Input inversion control for this pin, Reset type: SYSRSn */
                __IOM uint32_t INV19 : 1; /*!< [19:19] : Input inversion control for this pin, Reset type: SYSRSn */
                __IOM uint32_t INV20 : 1; /*!< [20:20] : Input inversion control for this pin, Reset type: SYSRSn */
                __IOM uint32_t INV21 : 1; /*!< [21:21] : Input inversion control for this pin, Reset type: SYSRSn */
                __IOM uint32_t INV22 : 1; /*!< [22:22] : Input inversion control for this pin, Reset type: SYSRSn */
                __IOM uint32_t INV23 : 1; /*!< [23:23] : Input inversion control for this pin, Reset type: SYSRSn */
                __IOM uint32_t INV24 : 1; /*!< [24:24] : Input inversion control for this pin, Reset type: SYSRSn */
                __IOM uint32_t INV25 : 1; /*!< [25:25] : Input inversion control for this pin, Reset type: SYSRSn */
                __IOM uint32_t INV26 : 1; /*!< [26:26] : Input inversion control for this pin, Reset type: SYSRSn */
                __IOM uint32_t INV27 : 1; /*!< [27:27] : Input inversion control for this pin, Reset type: SYSRSn */
                __IOM uint32_t INV28 : 1; /*!< [28:28] : Input inversion control for this pin, Reset type: SYSRSn */
                __IOM uint32_t INV29 : 1; /*!< [29:29] : Input inversion control for this pin, Reset type: SYSRSn */
                __IOM uint32_t INV30 : 1; /*!< [30:30] : Input inversion control for this pin, Reset type: SYSRSn */
                __IOM uint32_t INV31 : 1; /*!< [31:31] : Input inversion control for this pin, Reset type: SYSRSn */
            } INVb;
        };

        uint8_t RSV_0x24[4]; /*!< Offset: 0x24, reserved */

        union
        {
            __IOM uint32_t ECTRL; /*!< Offset: 0x28 : GPIO Extend Qualifier Select Register */

            struct
            {
                __IOM uint32_t
                    QUALPRD0 : 8; /*!< [7:0] : Qualification sampling period for GPIO8 to GPIO0  0x0             RW Qual
                                     Period Extended Counter High Parts, Period = PLLSYSCLK/(2*(GPxECTRL[QUALPRD0]*256 +
                                     GPxCTRL[QUALPRD0]))   0x0             RW               Reset type: SYSRSn */
                __IOM uint32_t QUALPRD1 : 8; /*!< [15:8] : Qualification sampling period for GPIO16 to GPIO8  0x0 RW
                                                Qual Period Extended Counter High Parts, Period =
                                                PLLSYSCLK/(2*(GPxECTRL[QUALPRD1]*256 + GPxCTRL[QUALPRD1]))   0x0 RW
                                                Reset type: SYSRSn */
                __IOM uint32_t QUALPRD2 : 8; /*!< [23:16] : Qualification sampling period for GPIO24 to GPIO16  0x0 RW
                                                Qual Period Extended Counter High Parts, Period =
                                                PLLSYSCLK/(2*(GPxECTRL[QUALPRD2]*256 + GPxCTRL[QUALPRD2]))   0x0 RW
                                                Reset type: SYSRSn */
                __IOM uint32_t QUALPRD3 : 8; /*!< [31:24] : Qualification sampling period for GPIO32 to GPIO24  0x0 RW
                                                Qual Period Extended Counter High Parts, Period =
                                                PLLSYSCLK/(2*(GPxECTRL[QUALPRD3]*256 + GPxCTRL[QUALPRD3]))   0x0 RW
                                                Reset type: SYSRSn */
            } ECTRLb;
        };

        uint8_t RSV_0X2C[20]; /*!< Offset: 0x2c~0x3f, reserved */

        union
        {
            __IOM uint32_t GMUX[2]; /*!< Offset: 0x40, GPIO Peripheral Group Mux Register */

            struct
            {
                __IOM uint32_t GMUX0 : 2; /*!< [1:0] : Defines Group pin-mux selection for GPIO, Reset Type : SYSRSn */
                __IOM uint32_t GMUX1 : 2; /*!< [3:2] : Defines Group pin-mux selection for GPIO, Reset Type : SYSRSn */
                __IOM uint32_t GMUX2 : 2; /*!< [5:4] : Defines Group pin-mux selection for GPIO, Reset Type : SYSRSn */
                __IOM uint32_t GMUX3 : 2; /*!< [7:6] : Defines Group pin-mux selection for GPIO, Reset Type : SYSRSn */
                __IOM uint32_t GMUX4 : 2; /*!< [9:8] : Defines Group pin-mux selection for GPIO, Reset Type : SYSRSn */
                __IOM uint32_t
                    GMUX5 : 2; /*!< [11:10] : Defines Group pin-mux selection for GPIO, Reset Type : SYSRSn */
                __IOM uint32_t
                    GMUX6 : 2; /*!< [13:12] : Defines Group pin-mux selection for GPIO, Reset Type : SYSRSn */
                __IOM uint32_t
                    GMUX7 : 2; /*!< [15:14] : Defines Group pin-mux selection for GPIO, Reset Type : SYSRSn */
                __IOM uint32_t
                    GMUX8 : 2; /*!< [17:16] : Defines Group pin-mux selection for GPIO, Reset Type : SYSRSn */
                __IOM uint32_t
                    GMUX9 : 2; /*!< [19:18] : Defines Group pin-mux selection for GPIO, Reset Type : SYSRSn */
                __IOM uint32_t
                    GMUX10 : 2; /*!< [21:20] : Defines Group pin-mux selection for GPIO, Reset Type : SYSRSn */
                __IOM uint32_t
                    GMUX11 : 2; /*!< [23:22] : Defines Group pin-mux selection for GPIO, Reset Type : SYSRSn */
                __IOM uint32_t
                    GMUX12 : 2; /*!< [25:24] : Defines Group pin-mux selection for GPIO, Reset Type : SYSRSn */
                __IOM uint32_t
                    GMUX13 : 2; /*!< [27:26] : Defines Group pin-mux selection for GPIO, Reset Type : SYSRSn */
                __IOM uint32_t
                    GMUX14 : 2; /*!< [29:28] : Defines Group pin-mux selection for GPIO, Reset Type : SYSRSn */
                __IOM uint32_t
                    GMUX15 : 2; /*!< [31:30] : Defines Group pin-mux selection for GPIO, Reset Type : SYSRSn */
            } GMUXb[2];
        };

        uint8_t RSV_0X48[8]; /*!< Offset: 0x48~0x4f, reserved */

        union
        {
            __IOM uint32_t CSEL[4]; /*!< Offset: 0x50, GPIO Core Select Register */

            struct
            {
                __IOM uint32_t CSEL0 : 4; /*!< [3:0] : Select which master's GPIODAT/SET/CLEAR/TOGGLE register control
                                             this GPIO Pins */
                __IOM uint32_t CSEL1 : 4; /*!< [7:4] : Select which master's GPIODAT/SET/CLEAR/TOGGLE register control
                                             this GPIO Pins */
                __IOM uint32_t CSEL2 : 4; /*!< [11:8] : Select which master's GPIODAT/SET/CLEAR/TOGGLE register control
                                             this GPIO Pins */
                __IOM uint32_t CSEL3 : 4; /*!< [15:12] : Select which master's GPIODAT/SET/CLEAR/TOGGLE register control
                                             this GPIO Pins */
                __IOM uint32_t CSEL4 : 4; /*!< [19:16] : Select which master's GPIODAT/SET/CLEAR/TOGGLE register control
                                             this GPIO Pins */
                __IOM uint32_t CSEL5 : 4; /*!< [23:20] : Select which master's GPIODAT/SET/CLEAR/TOGGLE register control
                                             this GPIO Pins */
                __IOM uint32_t CSEL6 : 4; /*!< [27:24] : Select which master's GPIODAT/SET/CLEAR/TOGGLE register control
                                             this GPIO Pins */
                __IOM uint32_t CSEL7 : 4; /*!< [31:28] : Select which master's GPIODAT/SET/CLEAR/TOGGLE register control
                                             this GPIO Pins */
            } CSELb[4];
        };

        union
        {
            __IOM uint32_t DS[2]; /*!< Offset: 0x60, GPIO Transmitter Driver Strength Low Bit Register */

            struct
            {
                __IOM uint32_t DS0  : 2; /*!< [1:0] : Transmitter drive strength for this pin, Reset type : SYSRSn */
                __IOM uint32_t DS1  : 2; /*!< [3:2] : Transmitter drive strength for this pin, Reset type : SYSRSn */
                __IOM uint32_t DS2  : 2; /*!< [5:4] : Transmitter drive strength for this pin, Reset type : SYSRSn */
                __IOM uint32_t DS3  : 2; /*!< [7:6] : Transmitter drive strength for this pin, Reset type : SYSRSn */
                __IOM uint32_t DS4  : 2; /*!< [9:8] : Transmitter drive strength for this pin, Reset type : SYSRSn */
                __IOM uint32_t DS5  : 2; /*!< [11:10] : Transmitter drive strength for this pin, Reset type : SYSRSn */
                __IOM uint32_t DS6  : 2; /*!< [13:12] : Transmitter drive strength for this pin, Reset type : SYSRSn */
                __IOM uint32_t DS7  : 2; /*!< [15:14] : Transmitter drive strength for this pin, Reset type : SYSRSn */
                __IOM uint32_t DS8  : 2; /*!< [17:16] : Transmitter drive strength for this pin, Reset type : SYSRSn */
                __IOM uint32_t DS9  : 2; /*!< [19:18] : Transmitter drive strength for this pin, Reset type : SYSRSn */
                __IOM uint32_t DS10 : 2; /*!< [21:20] : Transmitter drive strength for this pin, Reset type : SYSRSn */
                __IOM uint32_t DS11 : 2; /*!< [23:22] : Transmitter drive strength for this pin, Reset type : SYSRSn */
                __IOM uint32_t DS12 : 2; /*!< [25:24] : Transmitter drive strength for this pin, Reset type : SYSRSn */
                __IOM uint32_t DS13 : 2; /*!< [27:26] : Transmitter drive strength for this pin, Reset type : SYSRSn */
                __IOM uint32_t DS14 : 2; /*!< [29:28] : Transmitter drive strength for this pin, Reset type : SYSRSn */
                __IOM uint32_t DS15 : 2; /*!< [31:30] : Transmitter drive strength for this pin, Reset type : SYSRSn */
            } DSb[2];
        };

        union
        {
            __IOM uint32_t PDD; /*!< Offset: 0x68, GPIO Logic L Pull Down Disable Register */

            struct
            {
                __IOM uint32_t
                    PDD0 : 1; /*!< [0:0] : Pull-Down Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PDD1 : 1; /*!< [1:1] : Pull-Down Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PDD2 : 1; /*!< [2:2] : Pull-Down Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PDD3 : 1; /*!< [3:3] : Pull-Down Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PDD4 : 1; /*!< [4:4] : Pull-Down Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PDD5 : 1; /*!< [5:5] : Pull-Down Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PDD6 : 1; /*!< [6:6] : Pull-Down Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PDD7 : 1; /*!< [7:7] : Pull-Down Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PDD8 : 1; /*!< [8:8] : Pull-Down Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t
                    PDD9 : 1; /*!< [9:9] : Pull-Down Disable control for this pin. Default is H, Reset type: SYSRSn */
                __IOM uint32_t PDD10 : 1; /*!< [10:10] : Pull-Down Disable control for this pin. Default is H, Reset
                                             type: SYSRSn */
                __IOM uint32_t PDD11 : 1; /*!< [11:11] : Pull-Down Disable control for this pin. Default is H, Reset
                                             type: SYSRSn */
                __IOM uint32_t PDD12 : 1; /*!< [12:12] : Pull-Down Disable control for this pin. Default is H, Reset
                                             type: SYSRSn */
                __IOM uint32_t PDD13 : 1; /*!< [13:13] : Pull-Down Disable control for this pin. Default is H, Reset
                                             type: SYSRSn */
                __IOM uint32_t PDD14 : 1; /*!< [14:14] : Pull-Down Disable control for this pin. Default is H, Reset
                                             type: SYSRSn */
                __IOM uint32_t PDD15 : 1; /*!< [15:15] : Pull-Down Disable control for this pin. Default is H, Reset
                                             type: SYSRSn */
                __IOM uint32_t PDD16 : 1; /*!< [16:16] : Pull-Down Disable control for this pin. Default is H, Reset
                                             type: SYSRSn */
                __IOM uint32_t PDD17 : 1; /*!< [17:17] : Pull-Down Disable control for this pin. Default is H, Reset
                                             type: SYSRSn */
                __IOM uint32_t PDD18 : 1; /*!< [18:18] : Pull-Down Disable control for this pin. Default is H, Reset
                                             type: SYSRSn */
                __IOM uint32_t PDD19 : 1; /*!< [19:19] : Pull-Down Disable control for this pin. Default is H, Reset
                                             type: SYSRSn */
                __IOM uint32_t PDD20 : 1; /*!< [20:20] : Pull-Down Disable control for this pin. Default is H, Reset
                                             type: SYSRSn */
                __IOM uint32_t PDD21 : 1; /*!< [21:21] : Pull-Down Disable control for this pin. Default is H, Reset
                                             type: SYSRSn */
                __IOM uint32_t PDD22 : 1; /*!< [22:22] : Pull-Down Disable control for this pin. Default is H, Reset
                                             type: SYSRSn */
                __IOM uint32_t PDD23 : 1; /*!< [23:23] : Pull-Down Disable control for this pin. Default is H, Reset
                                             type: SYSRSn */
                __IOM uint32_t PDD24 : 1; /*!< [24:24] : Pull-Down Disable control for this pin. Default is H, Reset
                                             type: SYSRSn */
                __IOM uint32_t PDD25 : 1; /*!< [25:25] : Pull-Down Disable control for this pin. Default is H, Reset
                                             type: SYSRSn */
                __IOM uint32_t PDD26 : 1; /*!< [26:26] : Pull-Down Disable control for this pin. Default is H, Reset
                                             type: SYSRSn */
                __IOM uint32_t PDD27 : 1; /*!< [27:27] : Pull-Down Disable control for this pin. Default is H, Reset
                                             type: SYSRSn */
                __IOM uint32_t PDD28 : 1; /*!< [28:28] : Pull-Down Disable control for this pin. Default is H, Reset
                                             type: SYSRSn */
                __IOM uint32_t PDD29 : 1; /*!< [29:29] : Pull-Down Disable control for this pin. Default is H, Reset
                                             type: SYSRSn */
                __IOM uint32_t PDD30 : 1; /*!< [30:30] : Pull-Down Disable control for this pin. Default is H, Reset
                                             type: SYSRSn */
                __IOM uint32_t PDD31 : 1; /*!< [31:31] : Pull-Down Disable control for this pin. Default is H, Reset
                                             type: SYSRSn */
            } PDDb;
        };

        union
        {
            __IOM uint32_t FID; /*!< Offset: 0x6c, GPIO Force the IE follow the Function Dir */

            struct
            {
                __IOM uint32_t FID0 : 1; /*!< [0:0] :   Force the IE follow the function dir. Default IE is always H, to
                                            improve the robust of the design, IE can be controlled by function. 0: IE is
                                            always H. 1: When function is setup as Output, IE is low */
                __IOM uint32_t FID1 : 1; /*!< [1:1] :   Force the IE follow the function dir. Default IE is always H, to
                                            improve the robust of the design, IE can be controlled by function. 0: IE is
                                            always H. 1: When function is setup as Output, IE is low */
                __IOM uint32_t FID2 : 1; /*!< [2:2] :   Force the IE follow the function dir. Default IE is always H, to
                                            improve the robust of the design, IE can be controlled by function. 0: IE is
                                            always H. 1: When function is setup as Output, IE is low */
                __IOM uint32_t FID3 : 1; /*!< [3:3] :   Force the IE follow the function dir. Default IE is always H, to
                                            improve the robust of the design, IE can be controlled by function. 0: IE is
                                            always H. 1: When function is setup as Output, IE is low */
                __IOM uint32_t FID4 : 1; /*!< [4:4] :   Force the IE follow the function dir. Default IE is always H, to
                                            improve the robust of the design, IE can be controlled by function. 0: IE is
                                            always H. 1: When function is setup as Output, IE is low */
                __IOM uint32_t FID5 : 1; /*!< [5:5] :   Force the IE follow the function dir. Default IE is always H, to
                                            improve the robust of the design, IE can be controlled by function. 0: IE is
                                            always H. 1: When function is setup as Output, IE is low */
                __IOM uint32_t FID6 : 1; /*!< [6:6] :   Force the IE follow the function dir. Default IE is always H, to
                                            improve the robust of the design, IE can be controlled by function. 0: IE is
                                            always H. 1: When function is setup as Output, IE is low */
                __IOM uint32_t FID7 : 1; /*!< [7:7] :   Force the IE follow the function dir. Default IE is always H, to
                                            improve the robust of the design, IE can be controlled by function. 0: IE is
                                            always H. 1: When function is setup as Output, IE is low */
                __IOM uint32_t FID8 : 1; /*!< [8:8] :   Force the IE follow the function dir. Default IE is always H, to
                                            improve the robust of the design, IE can be controlled by function. 0: IE is
                                            always H. 1: When function is setup as Output, IE is low */
                __IOM uint32_t FID9 : 1; /*!< [9:9] :   Force the IE follow the function dir. Default IE is always H, to
                                            improve the robust of the design, IE can be controlled by function. 0: IE is
                                            always H. 1: When function is setup as Output, IE is low */
                __IOM uint32_t FID10 : 1; /*!< [10:10] : Force the IE follow the function dir. Default IE is always H,
                                             to improve the robust of the design, IE can be controlled by function. 0:
                                             IE is always H. 1: When function is setup as Output, IE is low */
                __IOM uint32_t FID11 : 1; /*!< [11:11] : Force the IE follow the function dir. Default IE is always H,
                                             to improve the robust of the design, IE can be controlled by function. 0:
                                             IE is always H. 1: When function is setup as Output, IE is low */
                __IOM uint32_t FID12 : 1; /*!< [12:12] : Force the IE follow the function dir. Default IE is always H,
                                             to improve the robust of the design, IE can be controlled by function. 0:
                                             IE is always H. 1: When function is setup as Output, IE is low */
                __IOM uint32_t FID13 : 1; /*!< [13:13] : Force the IE follow the function dir. Default IE is always H,
                                             to improve the robust of the design, IE can be controlled by function. 0:
                                             IE is always H. 1: When function is setup as Output, IE is low */
                __IOM uint32_t FID14 : 1; /*!< [14:14] : Force the IE follow the function dir. Default IE is always H,
                                             to improve the robust of the design, IE can be controlled by function. 0:
                                             IE is always H. 1: When function is setup as Output, IE is low */
                __IOM uint32_t FID15 : 1; /*!< [15:15] : Force the IE follow the function dir. Default IE is always H,
                                             to improve the robust of the design, IE can be controlled by function. 0:
                                             IE is always H. 1: When function is setup as Output, IE is low */
                __IOM uint32_t FID16 : 1; /*!< [16:16] : Force the IE follow the function dir. Default IE is always H,
                                             to improve the robust of the design, IE can be controlled by function. 0:
                                             IE is always H. 1: When function is setup as Output, IE is low */
                __IOM uint32_t FID17 : 1; /*!< [17:17] : Force the IE follow the function dir. Default IE is always H,
                                             to improve the robust of the design, IE can be controlled by function. 0:
                                             IE is always H. 1: When function is setup as Output, IE is low */
                __IOM uint32_t FID18 : 1; /*!< [18:18] : Force the IE follow the function dir. Default IE is always H,
                                             to improve the robust of the design, IE can be controlled by function. 0:
                                             IE is always H. 1: When function is setup as Output, IE is low */
                __IOM uint32_t FID19 : 1; /*!< [19:19] : Force the IE follow the function dir. Default IE is always H,
                                             to improve the robust of the design, IE can be controlled by function. 0:
                                             IE is always H. 1: When function is setup as Output, IE is low */
                __IOM uint32_t FID20 : 1; /*!< [20:20] : Force the IE follow the function dir. Default IE is always H,
                                             to improve the robust of the design, IE can be controlled by function. 0:
                                             IE is always H. 1: When function is setup as Output, IE is low */
                __IOM uint32_t FID21 : 1; /*!< [21:21] : Force the IE follow the function dir. Default IE is always H,
                                             to improve the robust of the design, IE can be controlled by function. 0:
                                             IE is always H. 1: When function is setup as Output, IE is low */
                __IOM uint32_t FID22 : 1; /*!< [22:22] : Force the IE follow the function dir. Default IE is always H,
                                             to improve the robust of the design, IE can be controlled by function. 0:
                                             IE is always H. 1: When function is setup as Output, IE is low */
                __IOM uint32_t FID23 : 1; /*!< [23:23] : Force the IE follow the function dir. Default IE is always H,
                                             to improve the robust of the design, IE can be controlled by function. 0:
                                             IE is always H. 1: When function is setup as Output, IE is low */
                __IOM uint32_t FID24 : 1; /*!< [24:24] : Force the IE follow the function dir. Default IE is always H,
                                             to improve the robust of the design, IE can be controlled by function. 0:
                                             IE is always H. 1: When function is setup as Output, IE is low */
                __IOM uint32_t FID25 : 1; /*!< [25:25] : Force the IE follow the function dir. Default IE is always H,
                                             to improve the robust of the design, IE can be controlled by function. 0:
                                             IE is always H. 1: When function is setup as Output, IE is low */
                __IOM uint32_t FID26 : 1; /*!< [26:26] : Force the IE follow the function dir. Default IE is always H,
                                             to improve the robust of the design, IE can be controlled by function. 0:
                                             IE is always H. 1: When function is setup as Output, IE is low */
                __IOM uint32_t FID27 : 1; /*!< [27:27] : Force the IE follow the function dir. Default IE is always H,
                                             to improve the robust of the design, IE can be controlled by function. 0:
                                             IE is always H. 1: When function is setup as Output, IE is low */
                __IOM uint32_t FID28 : 1; /*!< [28:28] : Force the IE follow the function dir. Default IE is always H,
                                             to improve the robust of the design, IE can be controlled by function. 0:
                                             IE is always H. 1: When function is setup as Output, IE is low */
                __IOM uint32_t FID29 : 1; /*!< [29:29] : Force the IE follow the function dir. Default IE is always H,
                                             to improve the robust of the design, IE can be controlled by function. 0:
                                             IE is always H. 1: When function is setup as Output, IE is low */
                __IOM uint32_t FID30 : 1; /*!< [30:30] : Force the IE follow the function dir. Default IE is always H,
                                             to improve the robust of the design, IE can be controlled by function. 0:
                                             IE is always H. 1: When function is setup as Output, IE is low */
                __IOM uint32_t FID31 : 1; /*!< [31:31] : Force the IE follow the function dir. Default IE is always H,
                                             to improve the robust of the design, IE can be controlled by function. 0:
                                             IE is always H. 1: When function is setup as Output, IE is low */
            } FIDb;
        };

        union
        {
            __IOM uint32_t ST; /*!< Offset: 0x70, GPIO Logic H enables Schmitt-trigger */

            struct
            {
                __IOM uint32_t ST0  : 1; /*!< [0:0] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t ST1  : 1; /*!< [1:1] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t ST2  : 1; /*!< [2:2] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t ST3  : 1; /*!< [3:3] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t ST4  : 1; /*!< [4:4] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t ST5  : 1; /*!< [5:5] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t ST6  : 1; /*!< [6:6] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t ST7  : 1; /*!< [7:7] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t ST8  : 1; /*!< [8:8] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t ST9  : 1; /*!< [9:9] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t ST10 : 1; /*!< [10:10] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t ST11 : 1; /*!< [11:11] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t ST12 : 1; /*!< [12:12] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t ST13 : 1; /*!< [13:13] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t ST14 : 1; /*!< [14:14] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t ST15 : 1; /*!< [15:15] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t ST16 : 1; /*!< [16:16] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t ST17 : 1; /*!< [17:17] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t ST18 : 1; /*!< [18:18] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t ST19 : 1; /*!< [19:19] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t ST20 : 1; /*!< [20:20] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t ST21 : 1; /*!< [21:21] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t ST22 : 1; /*!< [22:22] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t ST23 : 1; /*!< [23:23] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t ST24 : 1; /*!< [24:24] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t ST25 : 1; /*!< [25:25] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t ST26 : 1; /*!< [26:26] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t ST27 : 1; /*!< [27:27] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t ST28 : 1; /*!< [28:28] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t ST29 : 1; /*!< [29:29] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t ST30 : 1; /*!< [30:30] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t ST31 : 1; /*!< [31:31] : Logic H Enable Schmitt input, Reset type: SYSRSn */
            } STb;
        };

        union
        {
            __IOM uint32_t LPB; /*!< Offset: 0x74, GPIO Logic H enables LoopBack */

            struct
            {
                __IOM uint32_t LPB0  : 1; /*!< [0:0] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t LPB1  : 1; /*!< [1:1] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t LPB2  : 1; /*!< [2:2] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t LPB3  : 1; /*!< [3:3] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t LPB4  : 1; /*!< [4:4] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t LPB5  : 1; /*!< [5:5] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t LPB6  : 1; /*!< [6:6] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t LPB7  : 1; /*!< [7:7] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t LPB8  : 1; /*!< [8:8] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t LPB9  : 1; /*!< [9:9] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t LPB10 : 1; /*!< [10:10] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t LPB11 : 1; /*!< [11:11] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t LPB12 : 1; /*!< [12:12] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t LPB13 : 1; /*!< [13:13] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t LPB14 : 1; /*!< [14:14] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t LPB15 : 1; /*!< [15:15] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t LPB16 : 1; /*!< [16:16] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t LPB17 : 1; /*!< [17:17] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t LPB18 : 1; /*!< [18:18] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t LPB19 : 1; /*!< [19:19] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t LPB20 : 1; /*!< [20:20] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t LPB21 : 1; /*!< [21:21] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t LPB22 : 1; /*!< [22:22] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t LPB23 : 1; /*!< [23:23] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t LPB24 : 1; /*!< [24:24] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t LPB25 : 1; /*!< [25:25] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t LPB26 : 1; /*!< [26:26] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t LPB27 : 1; /*!< [27:27] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t LPB28 : 1; /*!< [28:28] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t LPB29 : 1; /*!< [29:29] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t LPB30 : 1; /*!< [30:30] : Logic H Enable Schmitt input, Reset type: SYSRSn */
                __IOM uint32_t LPB31 : 1; /*!< [31:31] : Logic H Enable Schmitt input, Reset type: SYSRSn */
            } LPBb;
        };

        union
        {
            __IOM uint32_t LOCK; /*!< Offset: 0x78, GPIO Lock Configuration Register */

            struct
            {
                __IOM uint32_t LOCK0  : 1; /*!< [0:0] : Configuration Lock bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t LOCK1  : 1; /*!< [1:1] : Configuration Lock bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t LOCK2  : 1; /*!< [2:2] : Configuration Lock bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t LOCK3  : 1; /*!< [3:3] : Configuration Lock bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t LOCK4  : 1; /*!< [4:4] : Configuration Lock bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t LOCK5  : 1; /*!< [5:5] : Configuration Lock bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t LOCK6  : 1; /*!< [6:6] : Configuration Lock bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t LOCK7  : 1; /*!< [7:7] : Configuration Lock bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t LOCK8  : 1; /*!< [8:8] : Configuration Lock bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t LOCK9  : 1; /*!< [9:9] : Configuration Lock bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t LOCK10 : 1; /*!< [10:10] : Configuration Lock bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t LOCK11 : 1; /*!< [11:11] : Configuration Lock bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t LOCK12 : 1; /*!< [12:12] : Configuration Lock bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t LOCK13 : 1; /*!< [13:13] : Configuration Lock bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t LOCK14 : 1; /*!< [14:14] : Configuration Lock bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t LOCK15 : 1; /*!< [15:15] : Configuration Lock bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t LOCK16 : 1; /*!< [16:16] : Configuration Lock bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t LOCK17 : 1; /*!< [17:17] : Configuration Lock bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t LOCK18 : 1; /*!< [18:18] : Configuration Lock bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t LOCK19 : 1; /*!< [19:19] : Configuration Lock bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t LOCK20 : 1; /*!< [20:20] : Configuration Lock bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t LOCK21 : 1; /*!< [21:21] : Configuration Lock bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t LOCK22 : 1; /*!< [22:22] : Configuration Lock bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t LOCK23 : 1; /*!< [23:23] : Configuration Lock bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t LOCK24 : 1; /*!< [24:24] : Configuration Lock bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t LOCK25 : 1; /*!< [25:25] : Configuration Lock bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t LOCK26 : 1; /*!< [26:26] : Configuration Lock bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t LOCK27 : 1; /*!< [27:27] : Configuration Lock bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t LOCK28 : 1; /*!< [28:28] : Configuration Lock bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t LOCK29 : 1; /*!< [29:29] : Configuration Lock bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t LOCK30 : 1; /*!< [30:30] : Configuration Lock bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t LOCK31 : 1; /*!< [31:31] : Configuration Lock bit for this pin, Reset type: SYSRSn */
            } LOCKb;
        };

        union
        {
            __IOM uint32_t CR; /*!< Offset: 0x7c, GPIO Lock Commit Register */

            struct
            {
                __IOM uint32_t CR0 : 1; /*!< [0:0] : Configuration lock commit bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t CR1 : 1; /*!< [1:1] : Configuration lock commit bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t CR2 : 1; /*!< [2:2] : Configuration lock commit bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t CR3 : 1; /*!< [3:3] : Configuration lock commit bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t CR4 : 1; /*!< [4:4] : Configuration lock commit bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t CR5 : 1; /*!< [5:5] : Configuration lock commit bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t CR6 : 1; /*!< [6:6] : Configuration lock commit bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t CR7 : 1; /*!< [7:7] : Configuration lock commit bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t CR8 : 1; /*!< [8:8] : Configuration lock commit bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t CR9 : 1; /*!< [9:9] : Configuration lock commit bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t
                    CR10 : 1; /*!< [10:10] : Configuration lock commit bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t
                    CR11 : 1; /*!< [11:11] : Configuration lock commit bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t
                    CR12 : 1; /*!< [12:12] : Configuration lock commit bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t
                    CR13 : 1; /*!< [13:13] : Configuration lock commit bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t
                    CR14 : 1; /*!< [14:14] : Configuration lock commit bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t
                    CR15 : 1; /*!< [15:15] : Configuration lock commit bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t
                    CR16 : 1; /*!< [16:16] : Configuration lock commit bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t
                    CR17 : 1; /*!< [17:17] : Configuration lock commit bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t
                    CR18 : 1; /*!< [18:18] : Configuration lock commit bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t
                    CR19 : 1; /*!< [19:19] : Configuration lock commit bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t
                    CR20 : 1; /*!< [20:20] : Configuration lock commit bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t
                    CR21 : 1; /*!< [21:21] : Configuration lock commit bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t
                    CR22 : 1; /*!< [22:22] : Configuration lock commit bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t
                    CR23 : 1; /*!< [23:23] : Configuration lock commit bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t
                    CR24 : 1; /*!< [24:24] : Configuration lock commit bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t
                    CR25 : 1; /*!< [25:25] : Configuration lock commit bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t
                    CR26 : 1; /*!< [26:26] : Configuration lock commit bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t
                    CR27 : 1; /*!< [27:27] : Configuration lock commit bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t
                    CR28 : 1; /*!< [28:28] : Configuration lock commit bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t
                    CR29 : 1; /*!< [29:29] : Configuration lock commit bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t
                    CR30 : 1; /*!< [30:30] : Configuration lock commit bit for this pin, Reset type: SYSRSn */
                __IOM uint32_t
                    CR31 : 1; /*!< [31:31] : Configuration lock commit bit for this pin, Reset type: SYSRSn */
            } CRb;
        };
    } PORT[6]; /*!< Offset: 0x0 + 0x80 * n, GPIO Port */
} GPIO_CTRL_Type;

/*!
 * @}
 */

/*!
 * \name GPIO CTRL Base Address Definitions
 *
 * @{
 */

/*! \brief GPIO CTRL base address. */
#define GPIO_CTRL_BASE (0x41300000UL)
/*! \brief GPIO CTRL base pointer. */
#define GPIO_CTRL ((GPIO_CTRL_Type *) GPIO_CTRL_BASE)

/*!
 * @}
 */

/*!
 * \name GPIO CTRL Register Bitfield Definitions
 *
 * @{
 */

/* CTRL bitfield */
#define GPIO_CTRL_CTRL_QUALPRD3_Pos    (24U)                                            /*!< QUALPRD3 Postion   */
#define GPIO_CTRL_CTRL_QUALPRD3_Msk    (0xffU << GPIO_CTRL_CTRL_QUALPRD3_Pos)           /*!< QUALPRD3 Mask      */
#define GPIO_CTRL_CTRL_QUALPRD3_Set(x) (((uint{ 0 } _t)(x) << { 1 } _Pos) & { 1 } _Msk) /*!< QUALPRD3 Set Value */
#define GPIO_CTRL_CTRL_QUALPRD3_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_CTRL_QUALPRD3_Msk) >> GPIO_CTRL_CTRL_QUALPRD3_Pos) /*!< QUALPRD3 Get Value */

#define GPIO_CTRL_CTRL_QUALPRD2_Pos    (16U)                                            /*!< QUALPRD2 Postion   */
#define GPIO_CTRL_CTRL_QUALPRD2_Msk    (0xffU << GPIO_CTRL_CTRL_QUALPRD2_Pos)           /*!< QUALPRD2 Mask      */
#define GPIO_CTRL_CTRL_QUALPRD2_Set(x) (((uint{ 0 } _t)(x) << { 1 } _Pos) & { 1 } _Msk) /*!< QUALPRD2 Set Value */
#define GPIO_CTRL_CTRL_QUALPRD2_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_CTRL_QUALPRD2_Msk) >> GPIO_CTRL_CTRL_QUALPRD2_Pos) /*!< QUALPRD2 Get Value */

#define GPIO_CTRL_CTRL_QUALPRD1_Pos    (8U)                                             /*!< QUALPRD1 Postion   */
#define GPIO_CTRL_CTRL_QUALPRD1_Msk    (0xffU << GPIO_CTRL_CTRL_QUALPRD1_Pos)           /*!< QUALPRD1 Mask      */
#define GPIO_CTRL_CTRL_QUALPRD1_Set(x) (((uint{ 0 } _t)(x) << { 1 } _Pos) & { 1 } _Msk) /*!< QUALPRD1 Set Value */
#define GPIO_CTRL_CTRL_QUALPRD1_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_CTRL_QUALPRD1_Msk) >> GPIO_CTRL_CTRL_QUALPRD1_Pos) /*!< QUALPRD1 Get Value */

#define GPIO_CTRL_CTRL_QUALPRD0_Pos    (0U)                                             /*!< QUALPRD0 Postion   */
#define GPIO_CTRL_CTRL_QUALPRD0_Msk    (0xffU << GPIO_CTRL_CTRL_QUALPRD0_Pos)           /*!< QUALPRD0 Mask      */
#define GPIO_CTRL_CTRL_QUALPRD0_Set(x) (((uint{ 0 } _t)(x) << { 1 } _Pos) & { 1 } _Msk) /*!< QUALPRD0 Set Value */
#define GPIO_CTRL_CTRL_QUALPRD0_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_CTRL_QUALPRD0_Msk) >> GPIO_CTRL_CTRL_QUALPRD0_Pos) /*!< QUALPRD0 Get Value */

/* QSEL bitfield */
#define GPIO_CTRL_QSEL_QSEL15_Pos (30U)                               /*!< QSEL15 Postion   */
#define GPIO_CTRL_QSEL_QSEL15_Msk (0x3U << GPIO_CTRL_QSEL_QSEL15_Pos) /*!< QSEL15 Mask      */
#define GPIO_CTRL_QSEL_QSEL15_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_QSEL_QSEL15_Pos) & GPIO_CTRL_QSEL_QSEL15_Msk) /*!< QSEL15 Set Value */
#define GPIO_CTRL_QSEL_QSEL15_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_QSEL_QSEL15_Msk) >> GPIO_CTRL_QSEL_QSEL15_Pos) /*!< QSEL15 Get Value */

#define GPIO_CTRL_QSEL_QSEL14_Pos (28U)                               /*!< QSEL14 Postion   */
#define GPIO_CTRL_QSEL_QSEL14_Msk (0x3U << GPIO_CTRL_QSEL_QSEL14_Pos) /*!< QSEL14 Mask      */
#define GPIO_CTRL_QSEL_QSEL14_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_QSEL_QSEL14_Pos) & GPIO_CTRL_QSEL_QSEL14_Msk) /*!< QSEL14 Set Value */
#define GPIO_CTRL_QSEL_QSEL14_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_QSEL_QSEL14_Msk) >> GPIO_CTRL_QSEL_QSEL14_Pos) /*!< QSEL14 Get Value */

#define GPIO_CTRL_QSEL_QSEL13_Pos (26U)                               /*!< QSEL13 Postion   */
#define GPIO_CTRL_QSEL_QSEL13_Msk (0x3U << GPIO_CTRL_QSEL_QSEL13_Pos) /*!< QSEL13 Mask      */
#define GPIO_CTRL_QSEL_QSEL13_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_QSEL_QSEL13_Pos) & GPIO_CTRL_QSEL_QSEL13_Msk) /*!< QSEL13 Set Value */
#define GPIO_CTRL_QSEL_QSEL13_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_QSEL_QSEL13_Msk) >> GPIO_CTRL_QSEL_QSEL13_Pos) /*!< QSEL13 Get Value */

#define GPIO_CTRL_QSEL_QSEL12_Pos (24U)                               /*!< QSEL12 Postion   */
#define GPIO_CTRL_QSEL_QSEL12_Msk (0x3U << GPIO_CTRL_QSEL_QSEL12_Pos) /*!< QSEL12 Mask      */
#define GPIO_CTRL_QSEL_QSEL12_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_QSEL_QSEL12_Pos) & GPIO_CTRL_QSEL_QSEL12_Msk) /*!< QSEL12 Set Value */
#define GPIO_CTRL_QSEL_QSEL12_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_QSEL_QSEL12_Msk) >> GPIO_CTRL_QSEL_QSEL12_Pos) /*!< QSEL12 Get Value */

#define GPIO_CTRL_QSEL_QSEL11_Pos (22U)                               /*!< QSEL11 Postion   */
#define GPIO_CTRL_QSEL_QSEL11_Msk (0x3U << GPIO_CTRL_QSEL_QSEL11_Pos) /*!< QSEL11 Mask      */
#define GPIO_CTRL_QSEL_QSEL11_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_QSEL_QSEL11_Pos) & GPIO_CTRL_QSEL_QSEL11_Msk) /*!< QSEL11 Set Value */
#define GPIO_CTRL_QSEL_QSEL11_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_QSEL_QSEL11_Msk) >> GPIO_CTRL_QSEL_QSEL11_Pos) /*!< QSEL11 Get Value */

#define GPIO_CTRL_QSEL_QSEL10_Pos (20U)                               /*!< QSEL10 Postion   */
#define GPIO_CTRL_QSEL_QSEL10_Msk (0x3U << GPIO_CTRL_QSEL_QSEL10_Pos) /*!< QSEL10 Mask      */
#define GPIO_CTRL_QSEL_QSEL10_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_QSEL_QSEL10_Pos) & GPIO_CTRL_QSEL_QSEL10_Msk) /*!< QSEL10 Set Value */
#define GPIO_CTRL_QSEL_QSEL10_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_QSEL_QSEL10_Msk) >> GPIO_CTRL_QSEL_QSEL10_Pos) /*!< QSEL10 Get Value */

#define GPIO_CTRL_QSEL_QSEL9_Pos (18U)                              /*!< QSEL9 Postion   */
#define GPIO_CTRL_QSEL_QSEL9_Msk (0x3U << GPIO_CTRL_QSEL_QSEL9_Pos) /*!< QSEL9 Mask      */
#define GPIO_CTRL_QSEL_QSEL9_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_QSEL_QSEL9_Pos) & GPIO_CTRL_QSEL_QSEL9_Msk) /*!< QSEL9 Set Value */
#define GPIO_CTRL_QSEL_QSEL9_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_QSEL_QSEL9_Msk) >> GPIO_CTRL_QSEL_QSEL9_Pos) /*!< QSEL9 Get Value */

#define GPIO_CTRL_QSEL_QSEL8_Pos (16U)                              /*!< QSEL8 Postion   */
#define GPIO_CTRL_QSEL_QSEL8_Msk (0x3U << GPIO_CTRL_QSEL_QSEL8_Pos) /*!< QSEL8 Mask      */
#define GPIO_CTRL_QSEL_QSEL8_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_QSEL_QSEL8_Pos) & GPIO_CTRL_QSEL_QSEL8_Msk) /*!< QSEL8 Set Value */
#define GPIO_CTRL_QSEL_QSEL8_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_QSEL_QSEL8_Msk) >> GPIO_CTRL_QSEL_QSEL8_Pos) /*!< QSEL8 Get Value */

#define GPIO_CTRL_QSEL_QSEL7_Pos (14U)                              /*!< QSEL7 Postion   */
#define GPIO_CTRL_QSEL_QSEL7_Msk (0x3U << GPIO_CTRL_QSEL_QSEL7_Pos) /*!< QSEL7 Mask      */
#define GPIO_CTRL_QSEL_QSEL7_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_QSEL_QSEL7_Pos) & GPIO_CTRL_QSEL_QSEL7_Msk) /*!< QSEL7 Set Value */
#define GPIO_CTRL_QSEL_QSEL7_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_QSEL_QSEL7_Msk) >> GPIO_CTRL_QSEL_QSEL7_Pos) /*!< QSEL7 Get Value */

#define GPIO_CTRL_QSEL_QSEL6_Pos (12U)                              /*!< QSEL6 Postion   */
#define GPIO_CTRL_QSEL_QSEL6_Msk (0x3U << GPIO_CTRL_QSEL_QSEL6_Pos) /*!< QSEL6 Mask      */
#define GPIO_CTRL_QSEL_QSEL6_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_QSEL_QSEL6_Pos) & GPIO_CTRL_QSEL_QSEL6_Msk) /*!< QSEL6 Set Value */
#define GPIO_CTRL_QSEL_QSEL6_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_QSEL_QSEL6_Msk) >> GPIO_CTRL_QSEL_QSEL6_Pos) /*!< QSEL6 Get Value */

#define GPIO_CTRL_QSEL_QSEL5_Pos (10U)                              /*!< QSEL5 Postion   */
#define GPIO_CTRL_QSEL_QSEL5_Msk (0x3U << GPIO_CTRL_QSEL_QSEL5_Pos) /*!< QSEL5 Mask      */
#define GPIO_CTRL_QSEL_QSEL5_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_QSEL_QSEL5_Pos) & GPIO_CTRL_QSEL_QSEL5_Msk) /*!< QSEL5 Set Value */
#define GPIO_CTRL_QSEL_QSEL5_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_QSEL_QSEL5_Msk) >> GPIO_CTRL_QSEL_QSEL5_Pos) /*!< QSEL5 Get Value */

#define GPIO_CTRL_QSEL_QSEL4_Pos (8U)                               /*!< QSEL4 Postion   */
#define GPIO_CTRL_QSEL_QSEL4_Msk (0x3U << GPIO_CTRL_QSEL_QSEL4_Pos) /*!< QSEL4 Mask      */
#define GPIO_CTRL_QSEL_QSEL4_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_QSEL_QSEL4_Pos) & GPIO_CTRL_QSEL_QSEL4_Msk) /*!< QSEL4 Set Value */
#define GPIO_CTRL_QSEL_QSEL4_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_QSEL_QSEL4_Msk) >> GPIO_CTRL_QSEL_QSEL4_Pos) /*!< QSEL4 Get Value */

#define GPIO_CTRL_QSEL_QSEL3_Pos (6U)                               /*!< QSEL3 Postion   */
#define GPIO_CTRL_QSEL_QSEL3_Msk (0x3U << GPIO_CTRL_QSEL_QSEL3_Pos) /*!< QSEL3 Mask      */
#define GPIO_CTRL_QSEL_QSEL3_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_QSEL_QSEL3_Pos) & GPIO_CTRL_QSEL_QSEL3_Msk) /*!< QSEL3 Set Value */
#define GPIO_CTRL_QSEL_QSEL3_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_QSEL_QSEL3_Msk) >> GPIO_CTRL_QSEL_QSEL3_Pos) /*!< QSEL3 Get Value */

#define GPIO_CTRL_QSEL_QSEL2_Pos (4U)                               /*!< QSEL2 Postion   */
#define GPIO_CTRL_QSEL_QSEL2_Msk (0x3U << GPIO_CTRL_QSEL_QSEL2_Pos) /*!< QSEL2 Mask      */
#define GPIO_CTRL_QSEL_QSEL2_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_QSEL_QSEL2_Pos) & GPIO_CTRL_QSEL_QSEL2_Msk) /*!< QSEL2 Set Value */
#define GPIO_CTRL_QSEL_QSEL2_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_QSEL_QSEL2_Msk) >> GPIO_CTRL_QSEL_QSEL2_Pos) /*!< QSEL2 Get Value */

#define GPIO_CTRL_QSEL_QSEL1_Pos (2U)                               /*!< QSEL1 Postion   */
#define GPIO_CTRL_QSEL_QSEL1_Msk (0x3U << GPIO_CTRL_QSEL_QSEL1_Pos) /*!< QSEL1 Mask      */
#define GPIO_CTRL_QSEL_QSEL1_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_QSEL_QSEL1_Pos) & GPIO_CTRL_QSEL_QSEL1_Msk) /*!< QSEL1 Set Value */
#define GPIO_CTRL_QSEL_QSEL1_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_QSEL_QSEL1_Msk) >> GPIO_CTRL_QSEL_QSEL1_Pos) /*!< QSEL1 Get Value */

#define GPIO_CTRL_QSEL_QSEL0_Pos (0U)                               /*!< QSEL0 Postion   */
#define GPIO_CTRL_QSEL_QSEL0_Msk (0x3U << GPIO_CTRL_QSEL_QSEL0_Pos) /*!< QSEL0 Mask      */
#define GPIO_CTRL_QSEL_QSEL0_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_QSEL_QSEL0_Pos) & GPIO_CTRL_QSEL_QSEL0_Msk) /*!< QSEL0 Set Value */
#define GPIO_CTRL_QSEL_QSEL0_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_QSEL_QSEL0_Msk) >> GPIO_CTRL_QSEL_QSEL0_Pos) /*!< QSEL0 Get Value */

/* MUX bitfield */
#define GPIO_CTRL_MUX_MUX15_Pos (30U)                             /*!< MUX15 Postion   */
#define GPIO_CTRL_MUX_MUX15_Msk (0x3U << GPIO_CTRL_MUX_MUX15_Pos) /*!< MUX15 Mask      */
#define GPIO_CTRL_MUX_MUX15_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_MUX_MUX15_Pos) & GPIO_CTRL_MUX_MUX15_Msk) /*!< MUX15 Set Value */
#define GPIO_CTRL_MUX_MUX15_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_MUX_MUX15_Msk) >> GPIO_CTRL_MUX_MUX15_Pos) /*!< MUX15 Get Value */

#define GPIO_CTRL_MUX_MUX14_Pos (28U)                             /*!< MUX14 Postion   */
#define GPIO_CTRL_MUX_MUX14_Msk (0x3U << GPIO_CTRL_MUX_MUX14_Pos) /*!< MUX14 Mask      */
#define GPIO_CTRL_MUX_MUX14_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_MUX_MUX14_Pos) & GPIO_CTRL_MUX_MUX14_Msk) /*!< MUX14 Set Value */
#define GPIO_CTRL_MUX_MUX14_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_MUX_MUX14_Msk) >> GPIO_CTRL_MUX_MUX14_Pos) /*!< MUX14 Get Value */

#define GPIO_CTRL_MUX_MUX13_Pos (26U)                             /*!< MUX13 Postion   */
#define GPIO_CTRL_MUX_MUX13_Msk (0x3U << GPIO_CTRL_MUX_MUX13_Pos) /*!< MUX13 Mask      */
#define GPIO_CTRL_MUX_MUX13_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_MUX_MUX13_Pos) & GPIO_CTRL_MUX_MUX13_Msk) /*!< MUX13 Set Value */
#define GPIO_CTRL_MUX_MUX13_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_MUX_MUX13_Msk) >> GPIO_CTRL_MUX_MUX13_Pos) /*!< MUX13 Get Value */

#define GPIO_CTRL_MUX_MUX12_Pos (24U)                             /*!< MUX12 Postion   */
#define GPIO_CTRL_MUX_MUX12_Msk (0x3U << GPIO_CTRL_MUX_MUX12_Pos) /*!< MUX12 Mask      */
#define GPIO_CTRL_MUX_MUX12_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_MUX_MUX12_Pos) & GPIO_CTRL_MUX_MUX12_Msk) /*!< MUX12 Set Value */
#define GPIO_CTRL_MUX_MUX12_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_MUX_MUX12_Msk) >> GPIO_CTRL_MUX_MUX12_Pos) /*!< MUX12 Get Value */

#define GPIO_CTRL_MUX_MUX11_Pos (22U)                             /*!< MUX11 Postion   */
#define GPIO_CTRL_MUX_MUX11_Msk (0x3U << GPIO_CTRL_MUX_MUX11_Pos) /*!< MUX11 Mask      */
#define GPIO_CTRL_MUX_MUX11_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_MUX_MUX11_Pos) & GPIO_CTRL_MUX_MUX11_Msk) /*!< MUX11 Set Value */
#define GPIO_CTRL_MUX_MUX11_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_MUX_MUX11_Msk) >> GPIO_CTRL_MUX_MUX11_Pos) /*!< MUX11 Get Value */

#define GPIO_CTRL_MUX_MUX10_Pos (20U)                             /*!< MUX10 Postion   */
#define GPIO_CTRL_MUX_MUX10_Msk (0x3U << GPIO_CTRL_MUX_MUX10_Pos) /*!< MUX10 Mask      */
#define GPIO_CTRL_MUX_MUX10_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_MUX_MUX10_Pos) & GPIO_CTRL_MUX_MUX10_Msk) /*!< MUX10 Set Value */
#define GPIO_CTRL_MUX_MUX10_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_MUX_MUX10_Msk) >> GPIO_CTRL_MUX_MUX10_Pos) /*!< MUX10 Get Value */

#define GPIO_CTRL_MUX_MUX9_Pos (18U)                            /*!< MUX9 Postion   */
#define GPIO_CTRL_MUX_MUX9_Msk (0x3U << GPIO_CTRL_MUX_MUX9_Pos) /*!< MUX9 Mask      */
#define GPIO_CTRL_MUX_MUX9_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_MUX_MUX9_Pos) & GPIO_CTRL_MUX_MUX9_Msk) /*!< MUX9 Set Value */
#define GPIO_CTRL_MUX_MUX9_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_MUX_MUX9_Msk) >> GPIO_CTRL_MUX_MUX9_Pos) /*!< MUX9 Get Value */

#define GPIO_CTRL_MUX_MUX8_Pos (16U)                            /*!< MUX8 Postion   */
#define GPIO_CTRL_MUX_MUX8_Msk (0x3U << GPIO_CTRL_MUX_MUX8_Pos) /*!< MUX8 Mask      */
#define GPIO_CTRL_MUX_MUX8_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_MUX_MUX8_Pos) & GPIO_CTRL_MUX_MUX8_Msk) /*!< MUX8 Set Value */
#define GPIO_CTRL_MUX_MUX8_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_MUX_MUX8_Msk) >> GPIO_CTRL_MUX_MUX8_Pos) /*!< MUX8 Get Value */

#define GPIO_CTRL_MUX_MUX7_Pos (14U)                            /*!< MUX7 Postion   */
#define GPIO_CTRL_MUX_MUX7_Msk (0x3U << GPIO_CTRL_MUX_MUX7_Pos) /*!< MUX7 Mask      */
#define GPIO_CTRL_MUX_MUX7_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_MUX_MUX7_Pos) & GPIO_CTRL_MUX_MUX7_Msk) /*!< MUX7 Set Value */
#define GPIO_CTRL_MUX_MUX7_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_MUX_MUX7_Msk) >> GPIO_CTRL_MUX_MUX7_Pos) /*!< MUX7 Get Value */

#define GPIO_CTRL_MUX_MUX6_Pos (12U)                            /*!< MUX6 Postion   */
#define GPIO_CTRL_MUX_MUX6_Msk (0x3U << GPIO_CTRL_MUX_MUX6_Pos) /*!< MUX6 Mask      */
#define GPIO_CTRL_MUX_MUX6_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_MUX_MUX6_Pos) & GPIO_CTRL_MUX_MUX6_Msk) /*!< MUX6 Set Value */
#define GPIO_CTRL_MUX_MUX6_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_MUX_MUX6_Msk) >> GPIO_CTRL_MUX_MUX6_Pos) /*!< MUX6 Get Value */

#define GPIO_CTRL_MUX_MUX5_Pos (10U)                            /*!< MUX5 Postion   */
#define GPIO_CTRL_MUX_MUX5_Msk (0x3U << GPIO_CTRL_MUX_MUX5_Pos) /*!< MUX5 Mask      */
#define GPIO_CTRL_MUX_MUX5_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_MUX_MUX5_Pos) & GPIO_CTRL_MUX_MUX5_Msk) /*!< MUX5 Set Value */
#define GPIO_CTRL_MUX_MUX5_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_MUX_MUX5_Msk) >> GPIO_CTRL_MUX_MUX5_Pos) /*!< MUX5 Get Value */

#define GPIO_CTRL_MUX_MUX4_Pos (8U)                             /*!< MUX4 Postion   */
#define GPIO_CTRL_MUX_MUX4_Msk (0x3U << GPIO_CTRL_MUX_MUX4_Pos) /*!< MUX4 Mask      */
#define GPIO_CTRL_MUX_MUX4_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_MUX_MUX4_Pos) & GPIO_CTRL_MUX_MUX4_Msk) /*!< MUX4 Set Value */
#define GPIO_CTRL_MUX_MUX4_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_MUX_MUX4_Msk) >> GPIO_CTRL_MUX_MUX4_Pos) /*!< MUX4 Get Value */

#define GPIO_CTRL_MUX_MUX3_Pos (6U)                             /*!< MUX3 Postion   */
#define GPIO_CTRL_MUX_MUX3_Msk (0x3U << GPIO_CTRL_MUX_MUX3_Pos) /*!< MUX3 Mask      */
#define GPIO_CTRL_MUX_MUX3_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_MUX_MUX3_Pos) & GPIO_CTRL_MUX_MUX3_Msk) /*!< MUX3 Set Value */
#define GPIO_CTRL_MUX_MUX3_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_MUX_MUX3_Msk) >> GPIO_CTRL_MUX_MUX3_Pos) /*!< MUX3 Get Value */

#define GPIO_CTRL_MUX_MUX2_Pos (4U)                             /*!< MUX2 Postion   */
#define GPIO_CTRL_MUX_MUX2_Msk (0x3U << GPIO_CTRL_MUX_MUX2_Pos) /*!< MUX2 Mask      */
#define GPIO_CTRL_MUX_MUX2_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_MUX_MUX2_Pos) & GPIO_CTRL_MUX_MUX2_Msk) /*!< MUX2 Set Value */
#define GPIO_CTRL_MUX_MUX2_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_MUX_MUX2_Msk) >> GPIO_CTRL_MUX_MUX2_Pos) /*!< MUX2 Get Value */

#define GPIO_CTRL_MUX_MUX1_Pos (2U)                             /*!< MUX1 Postion   */
#define GPIO_CTRL_MUX_MUX1_Msk (0x3U << GPIO_CTRL_MUX_MUX1_Pos) /*!< MUX1 Mask      */
#define GPIO_CTRL_MUX_MUX1_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_MUX_MUX1_Pos) & GPIO_CTRL_MUX_MUX1_Msk) /*!< MUX1 Set Value */
#define GPIO_CTRL_MUX_MUX1_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_MUX_MUX1_Msk) >> GPIO_CTRL_MUX_MUX1_Pos) /*!< MUX1 Get Value */

#define GPIO_CTRL_MUX_MUX0_Pos (0U)                             /*!< MUX0 Postion   */
#define GPIO_CTRL_MUX_MUX0_Msk (0x3U << GPIO_CTRL_MUX_MUX0_Pos) /*!< MUX0 Mask      */
#define GPIO_CTRL_MUX_MUX0_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_MUX_MUX0_Pos) & GPIO_CTRL_MUX_MUX0_Msk) /*!< MUX0 Set Value */
#define GPIO_CTRL_MUX_MUX0_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_MUX_MUX0_Msk) >> GPIO_CTRL_MUX_MUX0_Pos) /*!< MUX0 Get Value */

/* DIR bitfield */
#define GPIO_CTRL_DIR_DIR31_Pos (31U)                             /*!< DIR31 Postion   */
#define GPIO_CTRL_DIR_DIR31_Msk (0x1U << GPIO_CTRL_DIR_DIR31_Pos) /*!< DIR31 Mask      */
#define GPIO_CTRL_DIR_DIR31_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_DIR_DIR31_Pos) & GPIO_CTRL_DIR_DIR31_Msk) /*!< DIR31 Set Value */
#define GPIO_CTRL_DIR_DIR31_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_DIR_DIR31_Msk) >> GPIO_CTRL_DIR_DIR31_Pos) /*!< DIR31 Get Value */

#define GPIO_CTRL_DIR_DIR30_Pos (30U)                             /*!< DIR30 Postion   */
#define GPIO_CTRL_DIR_DIR30_Msk (0x1U << GPIO_CTRL_DIR_DIR30_Pos) /*!< DIR30 Mask      */
#define GPIO_CTRL_DIR_DIR30_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_DIR_DIR30_Pos) & GPIO_CTRL_DIR_DIR30_Msk) /*!< DIR30 Set Value */
#define GPIO_CTRL_DIR_DIR30_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_DIR_DIR30_Msk) >> GPIO_CTRL_DIR_DIR30_Pos) /*!< DIR30 Get Value */

#define GPIO_CTRL_DIR_DIR29_Pos (29U)                             /*!< DIR29 Postion   */
#define GPIO_CTRL_DIR_DIR29_Msk (0x1U << GPIO_CTRL_DIR_DIR29_Pos) /*!< DIR29 Mask      */
#define GPIO_CTRL_DIR_DIR29_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_DIR_DIR29_Pos) & GPIO_CTRL_DIR_DIR29_Msk) /*!< DIR29 Set Value */
#define GPIO_CTRL_DIR_DIR29_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_DIR_DIR29_Msk) >> GPIO_CTRL_DIR_DIR29_Pos) /*!< DIR29 Get Value */

#define GPIO_CTRL_DIR_DIR28_Pos (28U)                             /*!< DIR28 Postion   */
#define GPIO_CTRL_DIR_DIR28_Msk (0x1U << GPIO_CTRL_DIR_DIR28_Pos) /*!< DIR28 Mask      */
#define GPIO_CTRL_DIR_DIR28_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_DIR_DIR28_Pos) & GPIO_CTRL_DIR_DIR28_Msk) /*!< DIR28 Set Value */
#define GPIO_CTRL_DIR_DIR28_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_DIR_DIR28_Msk) >> GPIO_CTRL_DIR_DIR28_Pos) /*!< DIR28 Get Value */

#define GPIO_CTRL_DIR_DIR27_Pos (27U)                             /*!< DIR27 Postion   */
#define GPIO_CTRL_DIR_DIR27_Msk (0x1U << GPIO_CTRL_DIR_DIR27_Pos) /*!< DIR27 Mask      */
#define GPIO_CTRL_DIR_DIR27_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_DIR_DIR27_Pos) & GPIO_CTRL_DIR_DIR27_Msk) /*!< DIR27 Set Value */
#define GPIO_CTRL_DIR_DIR27_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_DIR_DIR27_Msk) >> GPIO_CTRL_DIR_DIR27_Pos) /*!< DIR27 Get Value */

#define GPIO_CTRL_DIR_DIR26_Pos (26U)                             /*!< DIR26 Postion   */
#define GPIO_CTRL_DIR_DIR26_Msk (0x1U << GPIO_CTRL_DIR_DIR26_Pos) /*!< DIR26 Mask      */
#define GPIO_CTRL_DIR_DIR26_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_DIR_DIR26_Pos) & GPIO_CTRL_DIR_DIR26_Msk) /*!< DIR26 Set Value */
#define GPIO_CTRL_DIR_DIR26_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_DIR_DIR26_Msk) >> GPIO_CTRL_DIR_DIR26_Pos) /*!< DIR26 Get Value */

#define GPIO_CTRL_DIR_DIR25_Pos (25U)                             /*!< DIR25 Postion   */
#define GPIO_CTRL_DIR_DIR25_Msk (0x1U << GPIO_CTRL_DIR_DIR25_Pos) /*!< DIR25 Mask      */
#define GPIO_CTRL_DIR_DIR25_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_DIR_DIR25_Pos) & GPIO_CTRL_DIR_DIR25_Msk) /*!< DIR25 Set Value */
#define GPIO_CTRL_DIR_DIR25_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_DIR_DIR25_Msk) >> GPIO_CTRL_DIR_DIR25_Pos) /*!< DIR25 Get Value */

#define GPIO_CTRL_DIR_DIR24_Pos (24U)                             /*!< DIR24 Postion   */
#define GPIO_CTRL_DIR_DIR24_Msk (0x1U << GPIO_CTRL_DIR_DIR24_Pos) /*!< DIR24 Mask      */
#define GPIO_CTRL_DIR_DIR24_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_DIR_DIR24_Pos) & GPIO_CTRL_DIR_DIR24_Msk) /*!< DIR24 Set Value */
#define GPIO_CTRL_DIR_DIR24_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_DIR_DIR24_Msk) >> GPIO_CTRL_DIR_DIR24_Pos) /*!< DIR24 Get Value */

#define GPIO_CTRL_DIR_DIR23_Pos (23U)                             /*!< DIR23 Postion   */
#define GPIO_CTRL_DIR_DIR23_Msk (0x1U << GPIO_CTRL_DIR_DIR23_Pos) /*!< DIR23 Mask      */
#define GPIO_CTRL_DIR_DIR23_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_DIR_DIR23_Pos) & GPIO_CTRL_DIR_DIR23_Msk) /*!< DIR23 Set Value */
#define GPIO_CTRL_DIR_DIR23_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_DIR_DIR23_Msk) >> GPIO_CTRL_DIR_DIR23_Pos) /*!< DIR23 Get Value */

#define GPIO_CTRL_DIR_DIR22_Pos (22U)                             /*!< DIR22 Postion   */
#define GPIO_CTRL_DIR_DIR22_Msk (0x1U << GPIO_CTRL_DIR_DIR22_Pos) /*!< DIR22 Mask      */
#define GPIO_CTRL_DIR_DIR22_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_DIR_DIR22_Pos) & GPIO_CTRL_DIR_DIR22_Msk) /*!< DIR22 Set Value */
#define GPIO_CTRL_DIR_DIR22_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_DIR_DIR22_Msk) >> GPIO_CTRL_DIR_DIR22_Pos) /*!< DIR22 Get Value */

#define GPIO_CTRL_DIR_DIR21_Pos (21U)                             /*!< DIR21 Postion   */
#define GPIO_CTRL_DIR_DIR21_Msk (0x1U << GPIO_CTRL_DIR_DIR21_Pos) /*!< DIR21 Mask      */
#define GPIO_CTRL_DIR_DIR21_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_DIR_DIR21_Pos) & GPIO_CTRL_DIR_DIR21_Msk) /*!< DIR21 Set Value */
#define GPIO_CTRL_DIR_DIR21_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_DIR_DIR21_Msk) >> GPIO_CTRL_DIR_DIR21_Pos) /*!< DIR21 Get Value */

#define GPIO_CTRL_DIR_DIR20_Pos (20U)                             /*!< DIR20 Postion   */
#define GPIO_CTRL_DIR_DIR20_Msk (0x1U << GPIO_CTRL_DIR_DIR20_Pos) /*!< DIR20 Mask      */
#define GPIO_CTRL_DIR_DIR20_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_DIR_DIR20_Pos) & GPIO_CTRL_DIR_DIR20_Msk) /*!< DIR20 Set Value */
#define GPIO_CTRL_DIR_DIR20_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_DIR_DIR20_Msk) >> GPIO_CTRL_DIR_DIR20_Pos) /*!< DIR20 Get Value */

#define GPIO_CTRL_DIR_DIR19_Pos (19U)                             /*!< DIR19 Postion   */
#define GPIO_CTRL_DIR_DIR19_Msk (0x1U << GPIO_CTRL_DIR_DIR19_Pos) /*!< DIR19 Mask      */
#define GPIO_CTRL_DIR_DIR19_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_DIR_DIR19_Pos) & GPIO_CTRL_DIR_DIR19_Msk) /*!< DIR19 Set Value */
#define GPIO_CTRL_DIR_DIR19_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_DIR_DIR19_Msk) >> GPIO_CTRL_DIR_DIR19_Pos) /*!< DIR19 Get Value */

#define GPIO_CTRL_DIR_DIR18_Pos (18U)                             /*!< DIR18 Postion   */
#define GPIO_CTRL_DIR_DIR18_Msk (0x1U << GPIO_CTRL_DIR_DIR18_Pos) /*!< DIR18 Mask      */
#define GPIO_CTRL_DIR_DIR18_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_DIR_DIR18_Pos) & GPIO_CTRL_DIR_DIR18_Msk) /*!< DIR18 Set Value */
#define GPIO_CTRL_DIR_DIR18_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_DIR_DIR18_Msk) >> GPIO_CTRL_DIR_DIR18_Pos) /*!< DIR18 Get Value */

#define GPIO_CTRL_DIR_DIR17_Pos (17U)                             /*!< DIR17 Postion   */
#define GPIO_CTRL_DIR_DIR17_Msk (0x1U << GPIO_CTRL_DIR_DIR17_Pos) /*!< DIR17 Mask      */
#define GPIO_CTRL_DIR_DIR17_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_DIR_DIR17_Pos) & GPIO_CTRL_DIR_DIR17_Msk) /*!< DIR17 Set Value */
#define GPIO_CTRL_DIR_DIR17_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_DIR_DIR17_Msk) >> GPIO_CTRL_DIR_DIR17_Pos) /*!< DIR17 Get Value */

#define GPIO_CTRL_DIR_DIR16_Pos (16U)                             /*!< DIR16 Postion   */
#define GPIO_CTRL_DIR_DIR16_Msk (0x1U << GPIO_CTRL_DIR_DIR16_Pos) /*!< DIR16 Mask      */
#define GPIO_CTRL_DIR_DIR16_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_DIR_DIR16_Pos) & GPIO_CTRL_DIR_DIR16_Msk) /*!< DIR16 Set Value */
#define GPIO_CTRL_DIR_DIR16_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_DIR_DIR16_Msk) >> GPIO_CTRL_DIR_DIR16_Pos) /*!< DIR16 Get Value */

#define GPIO_CTRL_DIR_DIR15_Pos (15U)                             /*!< DIR15 Postion   */
#define GPIO_CTRL_DIR_DIR15_Msk (0x1U << GPIO_CTRL_DIR_DIR15_Pos) /*!< DIR15 Mask      */
#define GPIO_CTRL_DIR_DIR15_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_DIR_DIR15_Pos) & GPIO_CTRL_DIR_DIR15_Msk) /*!< DIR15 Set Value */
#define GPIO_CTRL_DIR_DIR15_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_DIR_DIR15_Msk) >> GPIO_CTRL_DIR_DIR15_Pos) /*!< DIR15 Get Value */

#define GPIO_CTRL_DIR_DIR14_Pos (14U)                             /*!< DIR14 Postion   */
#define GPIO_CTRL_DIR_DIR14_Msk (0x1U << GPIO_CTRL_DIR_DIR14_Pos) /*!< DIR14 Mask      */
#define GPIO_CTRL_DIR_DIR14_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_DIR_DIR14_Pos) & GPIO_CTRL_DIR_DIR14_Msk) /*!< DIR14 Set Value */
#define GPIO_CTRL_DIR_DIR14_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_DIR_DIR14_Msk) >> GPIO_CTRL_DIR_DIR14_Pos) /*!< DIR14 Get Value */

#define GPIO_CTRL_DIR_DIR13_Pos (13U)                             /*!< DIR13 Postion   */
#define GPIO_CTRL_DIR_DIR13_Msk (0x1U << GPIO_CTRL_DIR_DIR13_Pos) /*!< DIR13 Mask      */
#define GPIO_CTRL_DIR_DIR13_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_DIR_DIR13_Pos) & GPIO_CTRL_DIR_DIR13_Msk) /*!< DIR13 Set Value */
#define GPIO_CTRL_DIR_DIR13_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_DIR_DIR13_Msk) >> GPIO_CTRL_DIR_DIR13_Pos) /*!< DIR13 Get Value */

#define GPIO_CTRL_DIR_DIR12_Pos (12U)                             /*!< DIR12 Postion   */
#define GPIO_CTRL_DIR_DIR12_Msk (0x1U << GPIO_CTRL_DIR_DIR12_Pos) /*!< DIR12 Mask      */
#define GPIO_CTRL_DIR_DIR12_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_DIR_DIR12_Pos) & GPIO_CTRL_DIR_DIR12_Msk) /*!< DIR12 Set Value */
#define GPIO_CTRL_DIR_DIR12_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_DIR_DIR12_Msk) >> GPIO_CTRL_DIR_DIR12_Pos) /*!< DIR12 Get Value */

#define GPIO_CTRL_DIR_DIR11_Pos (11U)                             /*!< DIR11 Postion   */
#define GPIO_CTRL_DIR_DIR11_Msk (0x1U << GPIO_CTRL_DIR_DIR11_Pos) /*!< DIR11 Mask      */
#define GPIO_CTRL_DIR_DIR11_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_DIR_DIR11_Pos) & GPIO_CTRL_DIR_DIR11_Msk) /*!< DIR11 Set Value */
#define GPIO_CTRL_DIR_DIR11_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_DIR_DIR11_Msk) >> GPIO_CTRL_DIR_DIR11_Pos) /*!< DIR11 Get Value */

#define GPIO_CTRL_DIR_DIR10_Pos (10U)                             /*!< DIR10 Postion   */
#define GPIO_CTRL_DIR_DIR10_Msk (0x1U << GPIO_CTRL_DIR_DIR10_Pos) /*!< DIR10 Mask      */
#define GPIO_CTRL_DIR_DIR10_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_DIR_DIR10_Pos) & GPIO_CTRL_DIR_DIR10_Msk) /*!< DIR10 Set Value */
#define GPIO_CTRL_DIR_DIR10_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_DIR_DIR10_Msk) >> GPIO_CTRL_DIR_DIR10_Pos) /*!< DIR10 Get Value */

#define GPIO_CTRL_DIR_DIR9_Pos (9U)                             /*!< DIR9 Postion   */
#define GPIO_CTRL_DIR_DIR9_Msk (0x1U << GPIO_CTRL_DIR_DIR9_Pos) /*!< DIR9 Mask      */
#define GPIO_CTRL_DIR_DIR9_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_DIR_DIR9_Pos) & GPIO_CTRL_DIR_DIR9_Msk) /*!< DIR9 Set Value */
#define GPIO_CTRL_DIR_DIR9_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_DIR_DIR9_Msk) >> GPIO_CTRL_DIR_DIR9_Pos) /*!< DIR9 Get Value */

#define GPIO_CTRL_DIR_DIR8_Pos (8U)                             /*!< DIR8 Postion   */
#define GPIO_CTRL_DIR_DIR8_Msk (0x1U << GPIO_CTRL_DIR_DIR8_Pos) /*!< DIR8 Mask      */
#define GPIO_CTRL_DIR_DIR8_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_DIR_DIR8_Pos) & GPIO_CTRL_DIR_DIR8_Msk) /*!< DIR8 Set Value */
#define GPIO_CTRL_DIR_DIR8_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_DIR_DIR8_Msk) >> GPIO_CTRL_DIR_DIR8_Pos) /*!< DIR8 Get Value */

#define GPIO_CTRL_DIR_DIR7_Pos (7U)                             /*!< DIR7 Postion   */
#define GPIO_CTRL_DIR_DIR7_Msk (0x1U << GPIO_CTRL_DIR_DIR7_Pos) /*!< DIR7 Mask      */
#define GPIO_CTRL_DIR_DIR7_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_DIR_DIR7_Pos) & GPIO_CTRL_DIR_DIR7_Msk) /*!< DIR7 Set Value */
#define GPIO_CTRL_DIR_DIR7_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_DIR_DIR7_Msk) >> GPIO_CTRL_DIR_DIR7_Pos) /*!< DIR7 Get Value */

#define GPIO_CTRL_DIR_DIR6_Pos (6U)                             /*!< DIR6 Postion   */
#define GPIO_CTRL_DIR_DIR6_Msk (0x1U << GPIO_CTRL_DIR_DIR6_Pos) /*!< DIR6 Mask      */
#define GPIO_CTRL_DIR_DIR6_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_DIR_DIR6_Pos) & GPIO_CTRL_DIR_DIR6_Msk) /*!< DIR6 Set Value */
#define GPIO_CTRL_DIR_DIR6_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_DIR_DIR6_Msk) >> GPIO_CTRL_DIR_DIR6_Pos) /*!< DIR6 Get Value */

#define GPIO_CTRL_DIR_DIR5_Pos (5U)                             /*!< DIR5 Postion   */
#define GPIO_CTRL_DIR_DIR5_Msk (0x1U << GPIO_CTRL_DIR_DIR5_Pos) /*!< DIR5 Mask      */
#define GPIO_CTRL_DIR_DIR5_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_DIR_DIR5_Pos) & GPIO_CTRL_DIR_DIR5_Msk) /*!< DIR5 Set Value */
#define GPIO_CTRL_DIR_DIR5_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_DIR_DIR5_Msk) >> GPIO_CTRL_DIR_DIR5_Pos) /*!< DIR5 Get Value */

#define GPIO_CTRL_DIR_DIR4_Pos (4U)                             /*!< DIR4 Postion   */
#define GPIO_CTRL_DIR_DIR4_Msk (0x1U << GPIO_CTRL_DIR_DIR4_Pos) /*!< DIR4 Mask      */
#define GPIO_CTRL_DIR_DIR4_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_DIR_DIR4_Pos) & GPIO_CTRL_DIR_DIR4_Msk) /*!< DIR4 Set Value */
#define GPIO_CTRL_DIR_DIR4_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_DIR_DIR4_Msk) >> GPIO_CTRL_DIR_DIR4_Pos) /*!< DIR4 Get Value */

#define GPIO_CTRL_DIR_DIR3_Pos (3U)                             /*!< DIR3 Postion   */
#define GPIO_CTRL_DIR_DIR3_Msk (0x1U << GPIO_CTRL_DIR_DIR3_Pos) /*!< DIR3 Mask      */
#define GPIO_CTRL_DIR_DIR3_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_DIR_DIR3_Pos) & GPIO_CTRL_DIR_DIR3_Msk) /*!< DIR3 Set Value */
#define GPIO_CTRL_DIR_DIR3_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_DIR_DIR3_Msk) >> GPIO_CTRL_DIR_DIR3_Pos) /*!< DIR3 Get Value */

#define GPIO_CTRL_DIR_DIR2_Pos (2U)                             /*!< DIR2 Postion   */
#define GPIO_CTRL_DIR_DIR2_Msk (0x1U << GPIO_CTRL_DIR_DIR2_Pos) /*!< DIR2 Mask      */
#define GPIO_CTRL_DIR_DIR2_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_DIR_DIR2_Pos) & GPIO_CTRL_DIR_DIR2_Msk) /*!< DIR2 Set Value */
#define GPIO_CTRL_DIR_DIR2_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_DIR_DIR2_Msk) >> GPIO_CTRL_DIR_DIR2_Pos) /*!< DIR2 Get Value */

#define GPIO_CTRL_DIR_DIR1_Pos (1U)                             /*!< DIR1 Postion   */
#define GPIO_CTRL_DIR_DIR1_Msk (0x1U << GPIO_CTRL_DIR_DIR1_Pos) /*!< DIR1 Mask      */
#define GPIO_CTRL_DIR_DIR1_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_DIR_DIR1_Pos) & GPIO_CTRL_DIR_DIR1_Msk) /*!< DIR1 Set Value */
#define GPIO_CTRL_DIR_DIR1_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_DIR_DIR1_Msk) >> GPIO_CTRL_DIR_DIR1_Pos) /*!< DIR1 Get Value */

#define GPIO_CTRL_DIR_DIR0_Pos (0U)                             /*!< DIR0 Postion   */
#define GPIO_CTRL_DIR_DIR0_Msk (0x1U << GPIO_CTRL_DIR_DIR0_Pos) /*!< DIR0 Mask      */
#define GPIO_CTRL_DIR_DIR0_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_DIR_DIR0_Pos) & GPIO_CTRL_DIR_DIR0_Msk) /*!< DIR0 Set Value */
#define GPIO_CTRL_DIR_DIR0_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_DIR_DIR0_Msk) >> GPIO_CTRL_DIR_DIR0_Pos) /*!< DIR0 Get Value */

/* PUD bitfield */
#define GPIO_CTRL_PUD_PUD31_Pos (31U)                             /*!< PUD31 Postion   */
#define GPIO_CTRL_PUD_PUD31_Msk (0x1U << GPIO_CTRL_PUD_PUD31_Pos) /*!< PUD31 Mask      */
#define GPIO_CTRL_PUD_PUD31_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PUD_PUD31_Pos) & GPIO_CTRL_PUD_PUD31_Msk) /*!< PUD31 Set Value */
#define GPIO_CTRL_PUD_PUD31_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PUD_PUD31_Msk) >> GPIO_CTRL_PUD_PUD31_Pos) /*!< PUD31 Get Value */

#define GPIO_CTRL_PUD_PUD30_Pos (30U)                             /*!< PUD30 Postion   */
#define GPIO_CTRL_PUD_PUD30_Msk (0x1U << GPIO_CTRL_PUD_PUD30_Pos) /*!< PUD30 Mask      */
#define GPIO_CTRL_PUD_PUD30_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PUD_PUD30_Pos) & GPIO_CTRL_PUD_PUD30_Msk) /*!< PUD30 Set Value */
#define GPIO_CTRL_PUD_PUD30_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PUD_PUD30_Msk) >> GPIO_CTRL_PUD_PUD30_Pos) /*!< PUD30 Get Value */

#define GPIO_CTRL_PUD_PUD29_Pos (29U)                             /*!< PUD29 Postion   */
#define GPIO_CTRL_PUD_PUD29_Msk (0x1U << GPIO_CTRL_PUD_PUD29_Pos) /*!< PUD29 Mask      */
#define GPIO_CTRL_PUD_PUD29_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PUD_PUD29_Pos) & GPIO_CTRL_PUD_PUD29_Msk) /*!< PUD29 Set Value */
#define GPIO_CTRL_PUD_PUD29_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PUD_PUD29_Msk) >> GPIO_CTRL_PUD_PUD29_Pos) /*!< PUD29 Get Value */

#define GPIO_CTRL_PUD_PUD28_Pos (28U)                             /*!< PUD28 Postion   */
#define GPIO_CTRL_PUD_PUD28_Msk (0x1U << GPIO_CTRL_PUD_PUD28_Pos) /*!< PUD28 Mask      */
#define GPIO_CTRL_PUD_PUD28_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PUD_PUD28_Pos) & GPIO_CTRL_PUD_PUD28_Msk) /*!< PUD28 Set Value */
#define GPIO_CTRL_PUD_PUD28_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PUD_PUD28_Msk) >> GPIO_CTRL_PUD_PUD28_Pos) /*!< PUD28 Get Value */

#define GPIO_CTRL_PUD_PUD27_Pos (27U)                             /*!< PUD27 Postion   */
#define GPIO_CTRL_PUD_PUD27_Msk (0x1U << GPIO_CTRL_PUD_PUD27_Pos) /*!< PUD27 Mask      */
#define GPIO_CTRL_PUD_PUD27_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PUD_PUD27_Pos) & GPIO_CTRL_PUD_PUD27_Msk) /*!< PUD27 Set Value */
#define GPIO_CTRL_PUD_PUD27_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PUD_PUD27_Msk) >> GPIO_CTRL_PUD_PUD27_Pos) /*!< PUD27 Get Value */

#define GPIO_CTRL_PUD_PUD26_Pos (26U)                             /*!< PUD26 Postion   */
#define GPIO_CTRL_PUD_PUD26_Msk (0x1U << GPIO_CTRL_PUD_PUD26_Pos) /*!< PUD26 Mask      */
#define GPIO_CTRL_PUD_PUD26_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PUD_PUD26_Pos) & GPIO_CTRL_PUD_PUD26_Msk) /*!< PUD26 Set Value */
#define GPIO_CTRL_PUD_PUD26_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PUD_PUD26_Msk) >> GPIO_CTRL_PUD_PUD26_Pos) /*!< PUD26 Get Value */

#define GPIO_CTRL_PUD_PUD25_Pos (25U)                             /*!< PUD25 Postion   */
#define GPIO_CTRL_PUD_PUD25_Msk (0x1U << GPIO_CTRL_PUD_PUD25_Pos) /*!< PUD25 Mask      */
#define GPIO_CTRL_PUD_PUD25_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PUD_PUD25_Pos) & GPIO_CTRL_PUD_PUD25_Msk) /*!< PUD25 Set Value */
#define GPIO_CTRL_PUD_PUD25_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PUD_PUD25_Msk) >> GPIO_CTRL_PUD_PUD25_Pos) /*!< PUD25 Get Value */

#define GPIO_CTRL_PUD_PUD24_Pos (24U)                             /*!< PUD24 Postion   */
#define GPIO_CTRL_PUD_PUD24_Msk (0x1U << GPIO_CTRL_PUD_PUD24_Pos) /*!< PUD24 Mask      */
#define GPIO_CTRL_PUD_PUD24_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PUD_PUD24_Pos) & GPIO_CTRL_PUD_PUD24_Msk) /*!< PUD24 Set Value */
#define GPIO_CTRL_PUD_PUD24_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PUD_PUD24_Msk) >> GPIO_CTRL_PUD_PUD24_Pos) /*!< PUD24 Get Value */

#define GPIO_CTRL_PUD_PUD23_Pos (23U)                             /*!< PUD23 Postion   */
#define GPIO_CTRL_PUD_PUD23_Msk (0x1U << GPIO_CTRL_PUD_PUD23_Pos) /*!< PUD23 Mask      */
#define GPIO_CTRL_PUD_PUD23_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PUD_PUD23_Pos) & GPIO_CTRL_PUD_PUD23_Msk) /*!< PUD23 Set Value */
#define GPIO_CTRL_PUD_PUD23_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PUD_PUD23_Msk) >> GPIO_CTRL_PUD_PUD23_Pos) /*!< PUD23 Get Value */

#define GPIO_CTRL_PUD_PUD22_Pos (22U)                             /*!< PUD22 Postion   */
#define GPIO_CTRL_PUD_PUD22_Msk (0x1U << GPIO_CTRL_PUD_PUD22_Pos) /*!< PUD22 Mask      */
#define GPIO_CTRL_PUD_PUD22_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PUD_PUD22_Pos) & GPIO_CTRL_PUD_PUD22_Msk) /*!< PUD22 Set Value */
#define GPIO_CTRL_PUD_PUD22_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PUD_PUD22_Msk) >> GPIO_CTRL_PUD_PUD22_Pos) /*!< PUD22 Get Value */

#define GPIO_CTRL_PUD_PUD21_Pos (21U)                             /*!< PUD21 Postion   */
#define GPIO_CTRL_PUD_PUD21_Msk (0x1U << GPIO_CTRL_PUD_PUD21_Pos) /*!< PUD21 Mask      */
#define GPIO_CTRL_PUD_PUD21_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PUD_PUD21_Pos) & GPIO_CTRL_PUD_PUD21_Msk) /*!< PUD21 Set Value */
#define GPIO_CTRL_PUD_PUD21_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PUD_PUD21_Msk) >> GPIO_CTRL_PUD_PUD21_Pos) /*!< PUD21 Get Value */

#define GPIO_CTRL_PUD_PUD20_Pos (20U)                             /*!< PUD20 Postion   */
#define GPIO_CTRL_PUD_PUD20_Msk (0x1U << GPIO_CTRL_PUD_PUD20_Pos) /*!< PUD20 Mask      */
#define GPIO_CTRL_PUD_PUD20_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PUD_PUD20_Pos) & GPIO_CTRL_PUD_PUD20_Msk) /*!< PUD20 Set Value */
#define GPIO_CTRL_PUD_PUD20_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PUD_PUD20_Msk) >> GPIO_CTRL_PUD_PUD20_Pos) /*!< PUD20 Get Value */

#define GPIO_CTRL_PUD_PUD19_Pos (19U)                             /*!< PUD19 Postion   */
#define GPIO_CTRL_PUD_PUD19_Msk (0x1U << GPIO_CTRL_PUD_PUD19_Pos) /*!< PUD19 Mask      */
#define GPIO_CTRL_PUD_PUD19_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PUD_PUD19_Pos) & GPIO_CTRL_PUD_PUD19_Msk) /*!< PUD19 Set Value */
#define GPIO_CTRL_PUD_PUD19_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PUD_PUD19_Msk) >> GPIO_CTRL_PUD_PUD19_Pos) /*!< PUD19 Get Value */

#define GPIO_CTRL_PUD_PUD18_Pos (18U)                             /*!< PUD18 Postion   */
#define GPIO_CTRL_PUD_PUD18_Msk (0x1U << GPIO_CTRL_PUD_PUD18_Pos) /*!< PUD18 Mask      */
#define GPIO_CTRL_PUD_PUD18_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PUD_PUD18_Pos) & GPIO_CTRL_PUD_PUD18_Msk) /*!< PUD18 Set Value */
#define GPIO_CTRL_PUD_PUD18_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PUD_PUD18_Msk) >> GPIO_CTRL_PUD_PUD18_Pos) /*!< PUD18 Get Value */

#define GPIO_CTRL_PUD_PUD17_Pos (17U)                             /*!< PUD17 Postion   */
#define GPIO_CTRL_PUD_PUD17_Msk (0x1U << GPIO_CTRL_PUD_PUD17_Pos) /*!< PUD17 Mask      */
#define GPIO_CTRL_PUD_PUD17_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PUD_PUD17_Pos) & GPIO_CTRL_PUD_PUD17_Msk) /*!< PUD17 Set Value */
#define GPIO_CTRL_PUD_PUD17_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PUD_PUD17_Msk) >> GPIO_CTRL_PUD_PUD17_Pos) /*!< PUD17 Get Value */

#define GPIO_CTRL_PUD_PUD16_Pos (16U)                             /*!< PUD16 Postion   */
#define GPIO_CTRL_PUD_PUD16_Msk (0x1U << GPIO_CTRL_PUD_PUD16_Pos) /*!< PUD16 Mask      */
#define GPIO_CTRL_PUD_PUD16_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PUD_PUD16_Pos) & GPIO_CTRL_PUD_PUD16_Msk) /*!< PUD16 Set Value */
#define GPIO_CTRL_PUD_PUD16_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PUD_PUD16_Msk) >> GPIO_CTRL_PUD_PUD16_Pos) /*!< PUD16 Get Value */

#define GPIO_CTRL_PUD_PUD15_Pos (15U)                             /*!< PUD15 Postion   */
#define GPIO_CTRL_PUD_PUD15_Msk (0x1U << GPIO_CTRL_PUD_PUD15_Pos) /*!< PUD15 Mask      */
#define GPIO_CTRL_PUD_PUD15_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PUD_PUD15_Pos) & GPIO_CTRL_PUD_PUD15_Msk) /*!< PUD15 Set Value */
#define GPIO_CTRL_PUD_PUD15_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PUD_PUD15_Msk) >> GPIO_CTRL_PUD_PUD15_Pos) /*!< PUD15 Get Value */

#define GPIO_CTRL_PUD_PUD14_Pos (14U)                             /*!< PUD14 Postion   */
#define GPIO_CTRL_PUD_PUD14_Msk (0x1U << GPIO_CTRL_PUD_PUD14_Pos) /*!< PUD14 Mask      */
#define GPIO_CTRL_PUD_PUD14_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PUD_PUD14_Pos) & GPIO_CTRL_PUD_PUD14_Msk) /*!< PUD14 Set Value */
#define GPIO_CTRL_PUD_PUD14_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PUD_PUD14_Msk) >> GPIO_CTRL_PUD_PUD14_Pos) /*!< PUD14 Get Value */

#define GPIO_CTRL_PUD_PUD13_Pos (13U)                             /*!< PUD13 Postion   */
#define GPIO_CTRL_PUD_PUD13_Msk (0x1U << GPIO_CTRL_PUD_PUD13_Pos) /*!< PUD13 Mask      */
#define GPIO_CTRL_PUD_PUD13_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PUD_PUD13_Pos) & GPIO_CTRL_PUD_PUD13_Msk) /*!< PUD13 Set Value */
#define GPIO_CTRL_PUD_PUD13_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PUD_PUD13_Msk) >> GPIO_CTRL_PUD_PUD13_Pos) /*!< PUD13 Get Value */

#define GPIO_CTRL_PUD_PUD12_Pos (12U)                             /*!< PUD12 Postion   */
#define GPIO_CTRL_PUD_PUD12_Msk (0x1U << GPIO_CTRL_PUD_PUD12_Pos) /*!< PUD12 Mask      */
#define GPIO_CTRL_PUD_PUD12_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PUD_PUD12_Pos) & GPIO_CTRL_PUD_PUD12_Msk) /*!< PUD12 Set Value */
#define GPIO_CTRL_PUD_PUD12_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PUD_PUD12_Msk) >> GPIO_CTRL_PUD_PUD12_Pos) /*!< PUD12 Get Value */

#define GPIO_CTRL_PUD_PUD11_Pos (11U)                             /*!< PUD11 Postion   */
#define GPIO_CTRL_PUD_PUD11_Msk (0x1U << GPIO_CTRL_PUD_PUD11_Pos) /*!< PUD11 Mask      */
#define GPIO_CTRL_PUD_PUD11_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PUD_PUD11_Pos) & GPIO_CTRL_PUD_PUD11_Msk) /*!< PUD11 Set Value */
#define GPIO_CTRL_PUD_PUD11_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PUD_PUD11_Msk) >> GPIO_CTRL_PUD_PUD11_Pos) /*!< PUD11 Get Value */

#define GPIO_CTRL_PUD_PUD10_Pos (10U)                             /*!< PUD10 Postion   */
#define GPIO_CTRL_PUD_PUD10_Msk (0x1U << GPIO_CTRL_PUD_PUD10_Pos) /*!< PUD10 Mask      */
#define GPIO_CTRL_PUD_PUD10_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PUD_PUD10_Pos) & GPIO_CTRL_PUD_PUD10_Msk) /*!< PUD10 Set Value */
#define GPIO_CTRL_PUD_PUD10_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PUD_PUD10_Msk) >> GPIO_CTRL_PUD_PUD10_Pos) /*!< PUD10 Get Value */

#define GPIO_CTRL_PUD_PUD9_Pos (9U)                             /*!< PUD9 Postion   */
#define GPIO_CTRL_PUD_PUD9_Msk (0x1U << GPIO_CTRL_PUD_PUD9_Pos) /*!< PUD9 Mask      */
#define GPIO_CTRL_PUD_PUD9_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PUD_PUD9_Pos) & GPIO_CTRL_PUD_PUD9_Msk) /*!< PUD9 Set Value */
#define GPIO_CTRL_PUD_PUD9_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PUD_PUD9_Msk) >> GPIO_CTRL_PUD_PUD9_Pos) /*!< PUD9 Get Value */

#define GPIO_CTRL_PUD_PUD8_Pos (8U)                             /*!< PUD8 Postion   */
#define GPIO_CTRL_PUD_PUD8_Msk (0x1U << GPIO_CTRL_PUD_PUD8_Pos) /*!< PUD8 Mask      */
#define GPIO_CTRL_PUD_PUD8_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PUD_PUD8_Pos) & GPIO_CTRL_PUD_PUD8_Msk) /*!< PUD8 Set Value */
#define GPIO_CTRL_PUD_PUD8_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PUD_PUD8_Msk) >> GPIO_CTRL_PUD_PUD8_Pos) /*!< PUD8 Get Value */

#define GPIO_CTRL_PUD_PUD7_Pos (7U)                             /*!< PUD7 Postion   */
#define GPIO_CTRL_PUD_PUD7_Msk (0x1U << GPIO_CTRL_PUD_PUD7_Pos) /*!< PUD7 Mask      */
#define GPIO_CTRL_PUD_PUD7_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PUD_PUD7_Pos) & GPIO_CTRL_PUD_PUD7_Msk) /*!< PUD7 Set Value */
#define GPIO_CTRL_PUD_PUD7_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PUD_PUD7_Msk) >> GPIO_CTRL_PUD_PUD7_Pos) /*!< PUD7 Get Value */

#define GPIO_CTRL_PUD_PUD6_Pos (6U)                             /*!< PUD6 Postion   */
#define GPIO_CTRL_PUD_PUD6_Msk (0x1U << GPIO_CTRL_PUD_PUD6_Pos) /*!< PUD6 Mask      */
#define GPIO_CTRL_PUD_PUD6_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PUD_PUD6_Pos) & GPIO_CTRL_PUD_PUD6_Msk) /*!< PUD6 Set Value */
#define GPIO_CTRL_PUD_PUD6_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PUD_PUD6_Msk) >> GPIO_CTRL_PUD_PUD6_Pos) /*!< PUD6 Get Value */

#define GPIO_CTRL_PUD_PUD5_Pos (5U)                             /*!< PUD5 Postion   */
#define GPIO_CTRL_PUD_PUD5_Msk (0x1U << GPIO_CTRL_PUD_PUD5_Pos) /*!< PUD5 Mask      */
#define GPIO_CTRL_PUD_PUD5_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PUD_PUD5_Pos) & GPIO_CTRL_PUD_PUD5_Msk) /*!< PUD5 Set Value */
#define GPIO_CTRL_PUD_PUD5_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PUD_PUD5_Msk) >> GPIO_CTRL_PUD_PUD5_Pos) /*!< PUD5 Get Value */

#define GPIO_CTRL_PUD_PUD4_Pos (4U)                             /*!< PUD4 Postion   */
#define GPIO_CTRL_PUD_PUD4_Msk (0x1U << GPIO_CTRL_PUD_PUD4_Pos) /*!< PUD4 Mask      */
#define GPIO_CTRL_PUD_PUD4_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PUD_PUD4_Pos) & GPIO_CTRL_PUD_PUD4_Msk) /*!< PUD4 Set Value */
#define GPIO_CTRL_PUD_PUD4_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PUD_PUD4_Msk) >> GPIO_CTRL_PUD_PUD4_Pos) /*!< PUD4 Get Value */

#define GPIO_CTRL_PUD_PUD3_Pos (3U)                             /*!< PUD3 Postion   */
#define GPIO_CTRL_PUD_PUD3_Msk (0x1U << GPIO_CTRL_PUD_PUD3_Pos) /*!< PUD3 Mask      */
#define GPIO_CTRL_PUD_PUD3_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PUD_PUD3_Pos) & GPIO_CTRL_PUD_PUD3_Msk) /*!< PUD3 Set Value */
#define GPIO_CTRL_PUD_PUD3_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PUD_PUD3_Msk) >> GPIO_CTRL_PUD_PUD3_Pos) /*!< PUD3 Get Value */

#define GPIO_CTRL_PUD_PUD2_Pos (2U)                             /*!< PUD2 Postion   */
#define GPIO_CTRL_PUD_PUD2_Msk (0x1U << GPIO_CTRL_PUD_PUD2_Pos) /*!< PUD2 Mask      */
#define GPIO_CTRL_PUD_PUD2_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PUD_PUD2_Pos) & GPIO_CTRL_PUD_PUD2_Msk) /*!< PUD2 Set Value */
#define GPIO_CTRL_PUD_PUD2_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PUD_PUD2_Msk) >> GPIO_CTRL_PUD_PUD2_Pos) /*!< PUD2 Get Value */

#define GPIO_CTRL_PUD_PUD1_Pos (1U)                             /*!< PUD1 Postion   */
#define GPIO_CTRL_PUD_PUD1_Msk (0x1U << GPIO_CTRL_PUD_PUD1_Pos) /*!< PUD1 Mask      */
#define GPIO_CTRL_PUD_PUD1_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PUD_PUD1_Pos) & GPIO_CTRL_PUD_PUD1_Msk) /*!< PUD1 Set Value */
#define GPIO_CTRL_PUD_PUD1_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PUD_PUD1_Msk) >> GPIO_CTRL_PUD_PUD1_Pos) /*!< PUD1 Get Value */

#define GPIO_CTRL_PUD_PUD0_Pos (0U)                             /*!< PUD0 Postion   */
#define GPIO_CTRL_PUD_PUD0_Msk (0x1U << GPIO_CTRL_PUD_PUD0_Pos) /*!< PUD0 Mask      */
#define GPIO_CTRL_PUD_PUD0_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PUD_PUD0_Pos) & GPIO_CTRL_PUD_PUD0_Msk) /*!< PUD0 Set Value */
#define GPIO_CTRL_PUD_PUD0_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PUD_PUD0_Msk) >> GPIO_CTRL_PUD_PUD0_Pos) /*!< PUD0 Get Value */

/* INV bitfield */
#define GPIO_CTRL_INV_INV31_Pos (31U)                             /*!< INV31 Postion   */
#define GPIO_CTRL_INV_INV31_Msk (0x1U << GPIO_CTRL_INV_INV31_Pos) /*!< INV31 Mask      */
#define GPIO_CTRL_INV_INV31_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_INV_INV31_Pos) & GPIO_CTRL_INV_INV31_Msk) /*!< INV31 Set Value */
#define GPIO_CTRL_INV_INV31_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_INV_INV31_Msk) >> GPIO_CTRL_INV_INV31_Pos) /*!< INV31 Get Value */

#define GPIO_CTRL_INV_INV30_Pos (30U)                             /*!< INV30 Postion   */
#define GPIO_CTRL_INV_INV30_Msk (0x1U << GPIO_CTRL_INV_INV30_Pos) /*!< INV30 Mask      */
#define GPIO_CTRL_INV_INV30_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_INV_INV30_Pos) & GPIO_CTRL_INV_INV30_Msk) /*!< INV30 Set Value */
#define GPIO_CTRL_INV_INV30_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_INV_INV30_Msk) >> GPIO_CTRL_INV_INV30_Pos) /*!< INV30 Get Value */

#define GPIO_CTRL_INV_INV29_Pos (29U)                             /*!< INV29 Postion   */
#define GPIO_CTRL_INV_INV29_Msk (0x1U << GPIO_CTRL_INV_INV29_Pos) /*!< INV29 Mask      */
#define GPIO_CTRL_INV_INV29_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_INV_INV29_Pos) & GPIO_CTRL_INV_INV29_Msk) /*!< INV29 Set Value */
#define GPIO_CTRL_INV_INV29_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_INV_INV29_Msk) >> GPIO_CTRL_INV_INV29_Pos) /*!< INV29 Get Value */

#define GPIO_CTRL_INV_INV28_Pos (28U)                             /*!< INV28 Postion   */
#define GPIO_CTRL_INV_INV28_Msk (0x1U << GPIO_CTRL_INV_INV28_Pos) /*!< INV28 Mask      */
#define GPIO_CTRL_INV_INV28_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_INV_INV28_Pos) & GPIO_CTRL_INV_INV28_Msk) /*!< INV28 Set Value */
#define GPIO_CTRL_INV_INV28_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_INV_INV28_Msk) >> GPIO_CTRL_INV_INV28_Pos) /*!< INV28 Get Value */

#define GPIO_CTRL_INV_INV27_Pos (27U)                             /*!< INV27 Postion   */
#define GPIO_CTRL_INV_INV27_Msk (0x1U << GPIO_CTRL_INV_INV27_Pos) /*!< INV27 Mask      */
#define GPIO_CTRL_INV_INV27_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_INV_INV27_Pos) & GPIO_CTRL_INV_INV27_Msk) /*!< INV27 Set Value */
#define GPIO_CTRL_INV_INV27_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_INV_INV27_Msk) >> GPIO_CTRL_INV_INV27_Pos) /*!< INV27 Get Value */

#define GPIO_CTRL_INV_INV26_Pos (26U)                             /*!< INV26 Postion   */
#define GPIO_CTRL_INV_INV26_Msk (0x1U << GPIO_CTRL_INV_INV26_Pos) /*!< INV26 Mask      */
#define GPIO_CTRL_INV_INV26_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_INV_INV26_Pos) & GPIO_CTRL_INV_INV26_Msk) /*!< INV26 Set Value */
#define GPIO_CTRL_INV_INV26_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_INV_INV26_Msk) >> GPIO_CTRL_INV_INV26_Pos) /*!< INV26 Get Value */

#define GPIO_CTRL_INV_INV25_Pos (25U)                             /*!< INV25 Postion   */
#define GPIO_CTRL_INV_INV25_Msk (0x1U << GPIO_CTRL_INV_INV25_Pos) /*!< INV25 Mask      */
#define GPIO_CTRL_INV_INV25_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_INV_INV25_Pos) & GPIO_CTRL_INV_INV25_Msk) /*!< INV25 Set Value */
#define GPIO_CTRL_INV_INV25_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_INV_INV25_Msk) >> GPIO_CTRL_INV_INV25_Pos) /*!< INV25 Get Value */

#define GPIO_CTRL_INV_INV24_Pos (24U)                             /*!< INV24 Postion   */
#define GPIO_CTRL_INV_INV24_Msk (0x1U << GPIO_CTRL_INV_INV24_Pos) /*!< INV24 Mask      */
#define GPIO_CTRL_INV_INV24_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_INV_INV24_Pos) & GPIO_CTRL_INV_INV24_Msk) /*!< INV24 Set Value */
#define GPIO_CTRL_INV_INV24_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_INV_INV24_Msk) >> GPIO_CTRL_INV_INV24_Pos) /*!< INV24 Get Value */

#define GPIO_CTRL_INV_INV23_Pos (23U)                             /*!< INV23 Postion   */
#define GPIO_CTRL_INV_INV23_Msk (0x1U << GPIO_CTRL_INV_INV23_Pos) /*!< INV23 Mask      */
#define GPIO_CTRL_INV_INV23_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_INV_INV23_Pos) & GPIO_CTRL_INV_INV23_Msk) /*!< INV23 Set Value */
#define GPIO_CTRL_INV_INV23_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_INV_INV23_Msk) >> GPIO_CTRL_INV_INV23_Pos) /*!< INV23 Get Value */

#define GPIO_CTRL_INV_INV22_Pos (22U)                             /*!< INV22 Postion   */
#define GPIO_CTRL_INV_INV22_Msk (0x1U << GPIO_CTRL_INV_INV22_Pos) /*!< INV22 Mask      */
#define GPIO_CTRL_INV_INV22_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_INV_INV22_Pos) & GPIO_CTRL_INV_INV22_Msk) /*!< INV22 Set Value */
#define GPIO_CTRL_INV_INV22_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_INV_INV22_Msk) >> GPIO_CTRL_INV_INV22_Pos) /*!< INV22 Get Value */

#define GPIO_CTRL_INV_INV21_Pos (21U)                             /*!< INV21 Postion   */
#define GPIO_CTRL_INV_INV21_Msk (0x1U << GPIO_CTRL_INV_INV21_Pos) /*!< INV21 Mask      */
#define GPIO_CTRL_INV_INV21_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_INV_INV21_Pos) & GPIO_CTRL_INV_INV21_Msk) /*!< INV21 Set Value */
#define GPIO_CTRL_INV_INV21_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_INV_INV21_Msk) >> GPIO_CTRL_INV_INV21_Pos) /*!< INV21 Get Value */

#define GPIO_CTRL_INV_INV20_Pos (20U)                             /*!< INV20 Postion   */
#define GPIO_CTRL_INV_INV20_Msk (0x1U << GPIO_CTRL_INV_INV20_Pos) /*!< INV20 Mask      */
#define GPIO_CTRL_INV_INV20_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_INV_INV20_Pos) & GPIO_CTRL_INV_INV20_Msk) /*!< INV20 Set Value */
#define GPIO_CTRL_INV_INV20_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_INV_INV20_Msk) >> GPIO_CTRL_INV_INV20_Pos) /*!< INV20 Get Value */

#define GPIO_CTRL_INV_INV19_Pos (19U)                             /*!< INV19 Postion   */
#define GPIO_CTRL_INV_INV19_Msk (0x1U << GPIO_CTRL_INV_INV19_Pos) /*!< INV19 Mask      */
#define GPIO_CTRL_INV_INV19_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_INV_INV19_Pos) & GPIO_CTRL_INV_INV19_Msk) /*!< INV19 Set Value */
#define GPIO_CTRL_INV_INV19_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_INV_INV19_Msk) >> GPIO_CTRL_INV_INV19_Pos) /*!< INV19 Get Value */

#define GPIO_CTRL_INV_INV18_Pos (18U)                             /*!< INV18 Postion   */
#define GPIO_CTRL_INV_INV18_Msk (0x1U << GPIO_CTRL_INV_INV18_Pos) /*!< INV18 Mask      */
#define GPIO_CTRL_INV_INV18_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_INV_INV18_Pos) & GPIO_CTRL_INV_INV18_Msk) /*!< INV18 Set Value */
#define GPIO_CTRL_INV_INV18_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_INV_INV18_Msk) >> GPIO_CTRL_INV_INV18_Pos) /*!< INV18 Get Value */

#define GPIO_CTRL_INV_INV17_Pos (17U)                             /*!< INV17 Postion   */
#define GPIO_CTRL_INV_INV17_Msk (0x1U << GPIO_CTRL_INV_INV17_Pos) /*!< INV17 Mask      */
#define GPIO_CTRL_INV_INV17_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_INV_INV17_Pos) & GPIO_CTRL_INV_INV17_Msk) /*!< INV17 Set Value */
#define GPIO_CTRL_INV_INV17_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_INV_INV17_Msk) >> GPIO_CTRL_INV_INV17_Pos) /*!< INV17 Get Value */

#define GPIO_CTRL_INV_INV16_Pos (16U)                             /*!< INV16 Postion   */
#define GPIO_CTRL_INV_INV16_Msk (0x1U << GPIO_CTRL_INV_INV16_Pos) /*!< INV16 Mask      */
#define GPIO_CTRL_INV_INV16_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_INV_INV16_Pos) & GPIO_CTRL_INV_INV16_Msk) /*!< INV16 Set Value */
#define GPIO_CTRL_INV_INV16_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_INV_INV16_Msk) >> GPIO_CTRL_INV_INV16_Pos) /*!< INV16 Get Value */

#define GPIO_CTRL_INV_INV15_Pos (15U)                             /*!< INV15 Postion   */
#define GPIO_CTRL_INV_INV15_Msk (0x1U << GPIO_CTRL_INV_INV15_Pos) /*!< INV15 Mask      */
#define GPIO_CTRL_INV_INV15_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_INV_INV15_Pos) & GPIO_CTRL_INV_INV15_Msk) /*!< INV15 Set Value */
#define GPIO_CTRL_INV_INV15_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_INV_INV15_Msk) >> GPIO_CTRL_INV_INV15_Pos) /*!< INV15 Get Value */

#define GPIO_CTRL_INV_INV14_Pos (14U)                             /*!< INV14 Postion   */
#define GPIO_CTRL_INV_INV14_Msk (0x1U << GPIO_CTRL_INV_INV14_Pos) /*!< INV14 Mask      */
#define GPIO_CTRL_INV_INV14_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_INV_INV14_Pos) & GPIO_CTRL_INV_INV14_Msk) /*!< INV14 Set Value */
#define GPIO_CTRL_INV_INV14_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_INV_INV14_Msk) >> GPIO_CTRL_INV_INV14_Pos) /*!< INV14 Get Value */

#define GPIO_CTRL_INV_INV13_Pos (13U)                             /*!< INV13 Postion   */
#define GPIO_CTRL_INV_INV13_Msk (0x1U << GPIO_CTRL_INV_INV13_Pos) /*!< INV13 Mask      */
#define GPIO_CTRL_INV_INV13_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_INV_INV13_Pos) & GPIO_CTRL_INV_INV13_Msk) /*!< INV13 Set Value */
#define GPIO_CTRL_INV_INV13_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_INV_INV13_Msk) >> GPIO_CTRL_INV_INV13_Pos) /*!< INV13 Get Value */

#define GPIO_CTRL_INV_INV12_Pos (12U)                             /*!< INV12 Postion   */
#define GPIO_CTRL_INV_INV12_Msk (0x1U << GPIO_CTRL_INV_INV12_Pos) /*!< INV12 Mask      */
#define GPIO_CTRL_INV_INV12_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_INV_INV12_Pos) & GPIO_CTRL_INV_INV12_Msk) /*!< INV12 Set Value */
#define GPIO_CTRL_INV_INV12_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_INV_INV12_Msk) >> GPIO_CTRL_INV_INV12_Pos) /*!< INV12 Get Value */

#define GPIO_CTRL_INV_INV11_Pos (11U)                             /*!< INV11 Postion   */
#define GPIO_CTRL_INV_INV11_Msk (0x1U << GPIO_CTRL_INV_INV11_Pos) /*!< INV11 Mask      */
#define GPIO_CTRL_INV_INV11_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_INV_INV11_Pos) & GPIO_CTRL_INV_INV11_Msk) /*!< INV11 Set Value */
#define GPIO_CTRL_INV_INV11_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_INV_INV11_Msk) >> GPIO_CTRL_INV_INV11_Pos) /*!< INV11 Get Value */

#define GPIO_CTRL_INV_INV10_Pos (10U)                             /*!< INV10 Postion   */
#define GPIO_CTRL_INV_INV10_Msk (0x1U << GPIO_CTRL_INV_INV10_Pos) /*!< INV10 Mask      */
#define GPIO_CTRL_INV_INV10_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_INV_INV10_Pos) & GPIO_CTRL_INV_INV10_Msk) /*!< INV10 Set Value */
#define GPIO_CTRL_INV_INV10_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_INV_INV10_Msk) >> GPIO_CTRL_INV_INV10_Pos) /*!< INV10 Get Value */

#define GPIO_CTRL_INV_INV9_Pos (9U)                             /*!< INV9 Postion   */
#define GPIO_CTRL_INV_INV9_Msk (0x1U << GPIO_CTRL_INV_INV9_Pos) /*!< INV9 Mask      */
#define GPIO_CTRL_INV_INV9_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_INV_INV9_Pos) & GPIO_CTRL_INV_INV9_Msk) /*!< INV9 Set Value */
#define GPIO_CTRL_INV_INV9_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_INV_INV9_Msk) >> GPIO_CTRL_INV_INV9_Pos) /*!< INV9 Get Value */

#define GPIO_CTRL_INV_INV8_Pos (8U)                             /*!< INV8 Postion   */
#define GPIO_CTRL_INV_INV8_Msk (0x1U << GPIO_CTRL_INV_INV8_Pos) /*!< INV8 Mask      */
#define GPIO_CTRL_INV_INV8_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_INV_INV8_Pos) & GPIO_CTRL_INV_INV8_Msk) /*!< INV8 Set Value */
#define GPIO_CTRL_INV_INV8_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_INV_INV8_Msk) >> GPIO_CTRL_INV_INV8_Pos) /*!< INV8 Get Value */

#define GPIO_CTRL_INV_INV7_Pos (7U)                             /*!< INV7 Postion   */
#define GPIO_CTRL_INV_INV7_Msk (0x1U << GPIO_CTRL_INV_INV7_Pos) /*!< INV7 Mask      */
#define GPIO_CTRL_INV_INV7_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_INV_INV7_Pos) & GPIO_CTRL_INV_INV7_Msk) /*!< INV7 Set Value */
#define GPIO_CTRL_INV_INV7_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_INV_INV7_Msk) >> GPIO_CTRL_INV_INV7_Pos) /*!< INV7 Get Value */

#define GPIO_CTRL_INV_INV6_Pos (6U)                             /*!< INV6 Postion   */
#define GPIO_CTRL_INV_INV6_Msk (0x1U << GPIO_CTRL_INV_INV6_Pos) /*!< INV6 Mask      */
#define GPIO_CTRL_INV_INV6_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_INV_INV6_Pos) & GPIO_CTRL_INV_INV6_Msk) /*!< INV6 Set Value */
#define GPIO_CTRL_INV_INV6_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_INV_INV6_Msk) >> GPIO_CTRL_INV_INV6_Pos) /*!< INV6 Get Value */

#define GPIO_CTRL_INV_INV5_Pos (5U)                             /*!< INV5 Postion   */
#define GPIO_CTRL_INV_INV5_Msk (0x1U << GPIO_CTRL_INV_INV5_Pos) /*!< INV5 Mask      */
#define GPIO_CTRL_INV_INV5_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_INV_INV5_Pos) & GPIO_CTRL_INV_INV5_Msk) /*!< INV5 Set Value */
#define GPIO_CTRL_INV_INV5_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_INV_INV5_Msk) >> GPIO_CTRL_INV_INV5_Pos) /*!< INV5 Get Value */

#define GPIO_CTRL_INV_INV4_Pos (4U)                             /*!< INV4 Postion   */
#define GPIO_CTRL_INV_INV4_Msk (0x1U << GPIO_CTRL_INV_INV4_Pos) /*!< INV4 Mask      */
#define GPIO_CTRL_INV_INV4_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_INV_INV4_Pos) & GPIO_CTRL_INV_INV4_Msk) /*!< INV4 Set Value */
#define GPIO_CTRL_INV_INV4_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_INV_INV4_Msk) >> GPIO_CTRL_INV_INV4_Pos) /*!< INV4 Get Value */

#define GPIO_CTRL_INV_INV3_Pos (3U)                             /*!< INV3 Postion   */
#define GPIO_CTRL_INV_INV3_Msk (0x1U << GPIO_CTRL_INV_INV3_Pos) /*!< INV3 Mask      */
#define GPIO_CTRL_INV_INV3_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_INV_INV3_Pos) & GPIO_CTRL_INV_INV3_Msk) /*!< INV3 Set Value */
#define GPIO_CTRL_INV_INV3_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_INV_INV3_Msk) >> GPIO_CTRL_INV_INV3_Pos) /*!< INV3 Get Value */

#define GPIO_CTRL_INV_INV2_Pos (2U)                             /*!< INV2 Postion   */
#define GPIO_CTRL_INV_INV2_Msk (0x1U << GPIO_CTRL_INV_INV2_Pos) /*!< INV2 Mask      */
#define GPIO_CTRL_INV_INV2_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_INV_INV2_Pos) & GPIO_CTRL_INV_INV2_Msk) /*!< INV2 Set Value */
#define GPIO_CTRL_INV_INV2_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_INV_INV2_Msk) >> GPIO_CTRL_INV_INV2_Pos) /*!< INV2 Get Value */

#define GPIO_CTRL_INV_INV1_Pos (1U)                             /*!< INV1 Postion   */
#define GPIO_CTRL_INV_INV1_Msk (0x1U << GPIO_CTRL_INV_INV1_Pos) /*!< INV1 Mask      */
#define GPIO_CTRL_INV_INV1_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_INV_INV1_Pos) & GPIO_CTRL_INV_INV1_Msk) /*!< INV1 Set Value */
#define GPIO_CTRL_INV_INV1_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_INV_INV1_Msk) >> GPIO_CTRL_INV_INV1_Pos) /*!< INV1 Get Value */

#define GPIO_CTRL_INV_INV0_Pos (0U)                             /*!< INV0 Postion   */
#define GPIO_CTRL_INV_INV0_Msk (0x1U << GPIO_CTRL_INV_INV0_Pos) /*!< INV0 Mask      */
#define GPIO_CTRL_INV_INV0_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_INV_INV0_Pos) & GPIO_CTRL_INV_INV0_Msk) /*!< INV0 Set Value */
#define GPIO_CTRL_INV_INV0_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_INV_INV0_Msk) >> GPIO_CTRL_INV_INV0_Pos) /*!< INV0 Get Value */

/* ECTRL bitfield */
#define GPIO_CTRL_ECTRL_QUALPRD3_Pos    (24U)                                            /*!< QUALPRD3 Postion   */
#define GPIO_CTRL_ECTRL_QUALPRD3_Msk    (0xffU << GPIO_CTRL_ECTRL_QUALPRD3_Pos)          /*!< QUALPRD3 Mask      */
#define GPIO_CTRL_ECTRL_QUALPRD3_Set(x) (((uint{ 0 } _t)(x) << { 1 } _Pos) & { 1 } _Msk) /*!< QUALPRD3 Set Value */
#define GPIO_CTRL_ECTRL_QUALPRD3_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_ECTRL_QUALPRD3_Msk) >> GPIO_CTRL_ECTRL_QUALPRD3_Pos) /*!< QUALPRD3 Get Value */

#define GPIO_CTRL_ECTRL_QUALPRD2_Pos    (16U)                                            /*!< QUALPRD2 Postion   */
#define GPIO_CTRL_ECTRL_QUALPRD2_Msk    (0xffU << GPIO_CTRL_ECTRL_QUALPRD2_Pos)          /*!< QUALPRD2 Mask      */
#define GPIO_CTRL_ECTRL_QUALPRD2_Set(x) (((uint{ 0 } _t)(x) << { 1 } _Pos) & { 1 } _Msk) /*!< QUALPRD2 Set Value */
#define GPIO_CTRL_ECTRL_QUALPRD2_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_ECTRL_QUALPRD2_Msk) >> GPIO_CTRL_ECTRL_QUALPRD2_Pos) /*!< QUALPRD2 Get Value */

#define GPIO_CTRL_ECTRL_QUALPRD1_Pos    (8U)                                             /*!< QUALPRD1 Postion   */
#define GPIO_CTRL_ECTRL_QUALPRD1_Msk    (0xffU << GPIO_CTRL_ECTRL_QUALPRD1_Pos)          /*!< QUALPRD1 Mask      */
#define GPIO_CTRL_ECTRL_QUALPRD1_Set(x) (((uint{ 0 } _t)(x) << { 1 } _Pos) & { 1 } _Msk) /*!< QUALPRD1 Set Value */
#define GPIO_CTRL_ECTRL_QUALPRD1_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_ECTRL_QUALPRD1_Msk) >> GPIO_CTRL_ECTRL_QUALPRD1_Pos) /*!< QUALPRD1 Get Value */

#define GPIO_CTRL_ECTRL_QUALPRD0_Pos    (0U)                                             /*!< QUALPRD0 Postion   */
#define GPIO_CTRL_ECTRL_QUALPRD0_Msk    (0xffU << GPIO_CTRL_ECTRL_QUALPRD0_Pos)          /*!< QUALPRD0 Mask      */
#define GPIO_CTRL_ECTRL_QUALPRD0_Set(x) (((uint{ 0 } _t)(x) << { 1 } _Pos) & { 1 } _Msk) /*!< QUALPRD0 Set Value */
#define GPIO_CTRL_ECTRL_QUALPRD0_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_ECTRL_QUALPRD0_Msk) >> GPIO_CTRL_ECTRL_QUALPRD0_Pos) /*!< QUALPRD0 Get Value */

/* GMUX bitfield */
#define GPIO_CTRL_GMUX_GMUX15_Pos (30U)                               /*!< GMUX15 Postion   */
#define GPIO_CTRL_GMUX_GMUX15_Msk (0x3U << GPIO_CTRL_GMUX_GMUX15_Pos) /*!< GMUX15 Mask      */
#define GPIO_CTRL_GMUX_GMUX15_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_GMUX_GMUX15_Pos) & GPIO_CTRL_GMUX_GMUX15_Msk) /*!< GMUX15 Set Value */
#define GPIO_CTRL_GMUX_GMUX15_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_GMUX_GMUX15_Msk) >> GPIO_CTRL_GMUX_GMUX15_Pos) /*!< GMUX15 Get Value */

#define GPIO_CTRL_GMUX_GMUX14_Pos (28U)                               /*!< GMUX14 Postion   */
#define GPIO_CTRL_GMUX_GMUX14_Msk (0x3U << GPIO_CTRL_GMUX_GMUX14_Pos) /*!< GMUX14 Mask      */
#define GPIO_CTRL_GMUX_GMUX14_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_GMUX_GMUX14_Pos) & GPIO_CTRL_GMUX_GMUX14_Msk) /*!< GMUX14 Set Value */
#define GPIO_CTRL_GMUX_GMUX14_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_GMUX_GMUX14_Msk) >> GPIO_CTRL_GMUX_GMUX14_Pos) /*!< GMUX14 Get Value */

#define GPIO_CTRL_GMUX_GMUX13_Pos (26U)                               /*!< GMUX13 Postion   */
#define GPIO_CTRL_GMUX_GMUX13_Msk (0x3U << GPIO_CTRL_GMUX_GMUX13_Pos) /*!< GMUX13 Mask      */
#define GPIO_CTRL_GMUX_GMUX13_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_GMUX_GMUX13_Pos) & GPIO_CTRL_GMUX_GMUX13_Msk) /*!< GMUX13 Set Value */
#define GPIO_CTRL_GMUX_GMUX13_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_GMUX_GMUX13_Msk) >> GPIO_CTRL_GMUX_GMUX13_Pos) /*!< GMUX13 Get Value */

#define GPIO_CTRL_GMUX_GMUX12_Pos (24U)                               /*!< GMUX12 Postion   */
#define GPIO_CTRL_GMUX_GMUX12_Msk (0x3U << GPIO_CTRL_GMUX_GMUX12_Pos) /*!< GMUX12 Mask      */
#define GPIO_CTRL_GMUX_GMUX12_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_GMUX_GMUX12_Pos) & GPIO_CTRL_GMUX_GMUX12_Msk) /*!< GMUX12 Set Value */
#define GPIO_CTRL_GMUX_GMUX12_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_GMUX_GMUX12_Msk) >> GPIO_CTRL_GMUX_GMUX12_Pos) /*!< GMUX12 Get Value */

#define GPIO_CTRL_GMUX_GMUX11_Pos (22U)                               /*!< GMUX11 Postion   */
#define GPIO_CTRL_GMUX_GMUX11_Msk (0x3U << GPIO_CTRL_GMUX_GMUX11_Pos) /*!< GMUX11 Mask      */
#define GPIO_CTRL_GMUX_GMUX11_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_GMUX_GMUX11_Pos) & GPIO_CTRL_GMUX_GMUX11_Msk) /*!< GMUX11 Set Value */
#define GPIO_CTRL_GMUX_GMUX11_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_GMUX_GMUX11_Msk) >> GPIO_CTRL_GMUX_GMUX11_Pos) /*!< GMUX11 Get Value */

#define GPIO_CTRL_GMUX_GMUX10_Pos (20U)                               /*!< GMUX10 Postion   */
#define GPIO_CTRL_GMUX_GMUX10_Msk (0x3U << GPIO_CTRL_GMUX_GMUX10_Pos) /*!< GMUX10 Mask      */
#define GPIO_CTRL_GMUX_GMUX10_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_GMUX_GMUX10_Pos) & GPIO_CTRL_GMUX_GMUX10_Msk) /*!< GMUX10 Set Value */
#define GPIO_CTRL_GMUX_GMUX10_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_GMUX_GMUX10_Msk) >> GPIO_CTRL_GMUX_GMUX10_Pos) /*!< GMUX10 Get Value */

#define GPIO_CTRL_GMUX_GMUX9_Pos (18U)                              /*!< GMUX9 Postion   */
#define GPIO_CTRL_GMUX_GMUX9_Msk (0x3U << GPIO_CTRL_GMUX_GMUX9_Pos) /*!< GMUX9 Mask      */
#define GPIO_CTRL_GMUX_GMUX9_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_GMUX_GMUX9_Pos) & GPIO_CTRL_GMUX_GMUX9_Msk) /*!< GMUX9 Set Value */
#define GPIO_CTRL_GMUX_GMUX9_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_GMUX_GMUX9_Msk) >> GPIO_CTRL_GMUX_GMUX9_Pos) /*!< GMUX9 Get Value */

#define GPIO_CTRL_GMUX_GMUX8_Pos (16U)                              /*!< GMUX8 Postion   */
#define GPIO_CTRL_GMUX_GMUX8_Msk (0x3U << GPIO_CTRL_GMUX_GMUX8_Pos) /*!< GMUX8 Mask      */
#define GPIO_CTRL_GMUX_GMUX8_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_GMUX_GMUX8_Pos) & GPIO_CTRL_GMUX_GMUX8_Msk) /*!< GMUX8 Set Value */
#define GPIO_CTRL_GMUX_GMUX8_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_GMUX_GMUX8_Msk) >> GPIO_CTRL_GMUX_GMUX8_Pos) /*!< GMUX8 Get Value */

#define GPIO_CTRL_GMUX_GMUX7_Pos (14U)                              /*!< GMUX7 Postion   */
#define GPIO_CTRL_GMUX_GMUX7_Msk (0x3U << GPIO_CTRL_GMUX_GMUX7_Pos) /*!< GMUX7 Mask      */
#define GPIO_CTRL_GMUX_GMUX7_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_GMUX_GMUX7_Pos) & GPIO_CTRL_GMUX_GMUX7_Msk) /*!< GMUX7 Set Value */
#define GPIO_CTRL_GMUX_GMUX7_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_GMUX_GMUX7_Msk) >> GPIO_CTRL_GMUX_GMUX7_Pos) /*!< GMUX7 Get Value */

#define GPIO_CTRL_GMUX_GMUX6_Pos (12U)                              /*!< GMUX6 Postion   */
#define GPIO_CTRL_GMUX_GMUX6_Msk (0x3U << GPIO_CTRL_GMUX_GMUX6_Pos) /*!< GMUX6 Mask      */
#define GPIO_CTRL_GMUX_GMUX6_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_GMUX_GMUX6_Pos) & GPIO_CTRL_GMUX_GMUX6_Msk) /*!< GMUX6 Set Value */
#define GPIO_CTRL_GMUX_GMUX6_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_GMUX_GMUX6_Msk) >> GPIO_CTRL_GMUX_GMUX6_Pos) /*!< GMUX6 Get Value */

#define GPIO_CTRL_GMUX_GMUX5_Pos (10U)                              /*!< GMUX5 Postion   */
#define GPIO_CTRL_GMUX_GMUX5_Msk (0x3U << GPIO_CTRL_GMUX_GMUX5_Pos) /*!< GMUX5 Mask      */
#define GPIO_CTRL_GMUX_GMUX5_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_GMUX_GMUX5_Pos) & GPIO_CTRL_GMUX_GMUX5_Msk) /*!< GMUX5 Set Value */
#define GPIO_CTRL_GMUX_GMUX5_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_GMUX_GMUX5_Msk) >> GPIO_CTRL_GMUX_GMUX5_Pos) /*!< GMUX5 Get Value */

#define GPIO_CTRL_GMUX_GMUX4_Pos (8U)                               /*!< GMUX4 Postion   */
#define GPIO_CTRL_GMUX_GMUX4_Msk (0x3U << GPIO_CTRL_GMUX_GMUX4_Pos) /*!< GMUX4 Mask      */
#define GPIO_CTRL_GMUX_GMUX4_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_GMUX_GMUX4_Pos) & GPIO_CTRL_GMUX_GMUX4_Msk) /*!< GMUX4 Set Value */
#define GPIO_CTRL_GMUX_GMUX4_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_GMUX_GMUX4_Msk) >> GPIO_CTRL_GMUX_GMUX4_Pos) /*!< GMUX4 Get Value */

#define GPIO_CTRL_GMUX_GMUX3_Pos (6U)                               /*!< GMUX3 Postion   */
#define GPIO_CTRL_GMUX_GMUX3_Msk (0x3U << GPIO_CTRL_GMUX_GMUX3_Pos) /*!< GMUX3 Mask      */
#define GPIO_CTRL_GMUX_GMUX3_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_GMUX_GMUX3_Pos) & GPIO_CTRL_GMUX_GMUX3_Msk) /*!< GMUX3 Set Value */
#define GPIO_CTRL_GMUX_GMUX3_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_GMUX_GMUX3_Msk) >> GPIO_CTRL_GMUX_GMUX3_Pos) /*!< GMUX3 Get Value */

#define GPIO_CTRL_GMUX_GMUX2_Pos (4U)                               /*!< GMUX2 Postion   */
#define GPIO_CTRL_GMUX_GMUX2_Msk (0x3U << GPIO_CTRL_GMUX_GMUX2_Pos) /*!< GMUX2 Mask      */
#define GPIO_CTRL_GMUX_GMUX2_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_GMUX_GMUX2_Pos) & GPIO_CTRL_GMUX_GMUX2_Msk) /*!< GMUX2 Set Value */
#define GPIO_CTRL_GMUX_GMUX2_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_GMUX_GMUX2_Msk) >> GPIO_CTRL_GMUX_GMUX2_Pos) /*!< GMUX2 Get Value */

#define GPIO_CTRL_GMUX_GMUX1_Pos (2U)                               /*!< GMUX1 Postion   */
#define GPIO_CTRL_GMUX_GMUX1_Msk (0x3U << GPIO_CTRL_GMUX_GMUX1_Pos) /*!< GMUX1 Mask      */
#define GPIO_CTRL_GMUX_GMUX1_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_GMUX_GMUX1_Pos) & GPIO_CTRL_GMUX_GMUX1_Msk) /*!< GMUX1 Set Value */
#define GPIO_CTRL_GMUX_GMUX1_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_GMUX_GMUX1_Msk) >> GPIO_CTRL_GMUX_GMUX1_Pos) /*!< GMUX1 Get Value */

#define GPIO_CTRL_GMUX_GMUX0_Pos (0U)                               /*!< GMUX0 Postion   */
#define GPIO_CTRL_GMUX_GMUX0_Msk (0x3U << GPIO_CTRL_GMUX_GMUX0_Pos) /*!< GMUX0 Mask      */
#define GPIO_CTRL_GMUX_GMUX0_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_GMUX_GMUX0_Pos) & GPIO_CTRL_GMUX_GMUX0_Msk) /*!< GMUX0 Set Value */
#define GPIO_CTRL_GMUX_GMUX0_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_GMUX_GMUX0_Msk) >> GPIO_CTRL_GMUX_GMUX0_Pos) /*!< GMUX0 Get Value */

/* CSEL bitfield */
#define GPIO_CTRL_CSEL_CSEL7_Pos (28U)                              /*!< CSEL7 Postion   */
#define GPIO_CTRL_CSEL_CSEL7_Msk (0xfU << GPIO_CTRL_CSEL_CSEL7_Pos) /*!< CSEL7 Mask      */
#define GPIO_CTRL_CSEL_CSEL7_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_CSEL_CSEL7_Pos) & GPIO_CTRL_CSEL_CSEL7_Msk) /*!< CSEL7 Set Value */
#define GPIO_CTRL_CSEL_CSEL7_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_CSEL_CSEL7_Msk) >> GPIO_CTRL_CSEL_CSEL7_Pos) /*!< CSEL7 Get Value */

#define GPIO_CTRL_CSEL_CSEL6_Pos (24U)                              /*!< CSEL6 Postion   */
#define GPIO_CTRL_CSEL_CSEL6_Msk (0xfU << GPIO_CTRL_CSEL_CSEL6_Pos) /*!< CSEL6 Mask      */
#define GPIO_CTRL_CSEL_CSEL6_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_CSEL_CSEL6_Pos) & GPIO_CTRL_CSEL_CSEL6_Msk) /*!< CSEL6 Set Value */
#define GPIO_CTRL_CSEL_CSEL6_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_CSEL_CSEL6_Msk) >> GPIO_CTRL_CSEL_CSEL6_Pos) /*!< CSEL6 Get Value */

#define GPIO_CTRL_CSEL_CSEL5_Pos (20U)                              /*!< CSEL5 Postion   */
#define GPIO_CTRL_CSEL_CSEL5_Msk (0xfU << GPIO_CTRL_CSEL_CSEL5_Pos) /*!< CSEL5 Mask      */
#define GPIO_CTRL_CSEL_CSEL5_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_CSEL_CSEL5_Pos) & GPIO_CTRL_CSEL_CSEL5_Msk) /*!< CSEL5 Set Value */
#define GPIO_CTRL_CSEL_CSEL5_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_CSEL_CSEL5_Msk) >> GPIO_CTRL_CSEL_CSEL5_Pos) /*!< CSEL5 Get Value */

#define GPIO_CTRL_CSEL_CSEL4_Pos (16U)                              /*!< CSEL4 Postion   */
#define GPIO_CTRL_CSEL_CSEL4_Msk (0xfU << GPIO_CTRL_CSEL_CSEL4_Pos) /*!< CSEL4 Mask      */
#define GPIO_CTRL_CSEL_CSEL4_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_CSEL_CSEL4_Pos) & GPIO_CTRL_CSEL_CSEL4_Msk) /*!< CSEL4 Set Value */
#define GPIO_CTRL_CSEL_CSEL4_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_CSEL_CSEL4_Msk) >> GPIO_CTRL_CSEL_CSEL4_Pos) /*!< CSEL4 Get Value */

#define GPIO_CTRL_CSEL_CSEL3_Pos (12U)                              /*!< CSEL3 Postion   */
#define GPIO_CTRL_CSEL_CSEL3_Msk (0xfU << GPIO_CTRL_CSEL_CSEL3_Pos) /*!< CSEL3 Mask      */
#define GPIO_CTRL_CSEL_CSEL3_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_CSEL_CSEL3_Pos) & GPIO_CTRL_CSEL_CSEL3_Msk) /*!< CSEL3 Set Value */
#define GPIO_CTRL_CSEL_CSEL3_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_CSEL_CSEL3_Msk) >> GPIO_CTRL_CSEL_CSEL3_Pos) /*!< CSEL3 Get Value */

#define GPIO_CTRL_CSEL_CSEL2_Pos (8U)                               /*!< CSEL2 Postion   */
#define GPIO_CTRL_CSEL_CSEL2_Msk (0xfU << GPIO_CTRL_CSEL_CSEL2_Pos) /*!< CSEL2 Mask      */
#define GPIO_CTRL_CSEL_CSEL2_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_CSEL_CSEL2_Pos) & GPIO_CTRL_CSEL_CSEL2_Msk) /*!< CSEL2 Set Value */
#define GPIO_CTRL_CSEL_CSEL2_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_CSEL_CSEL2_Msk) >> GPIO_CTRL_CSEL_CSEL2_Pos) /*!< CSEL2 Get Value */

#define GPIO_CTRL_CSEL_CSEL1_Pos (4U)                               /*!< CSEL1 Postion   */
#define GPIO_CTRL_CSEL_CSEL1_Msk (0xfU << GPIO_CTRL_CSEL_CSEL1_Pos) /*!< CSEL1 Mask      */
#define GPIO_CTRL_CSEL_CSEL1_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_CSEL_CSEL1_Pos) & GPIO_CTRL_CSEL_CSEL1_Msk) /*!< CSEL1 Set Value */
#define GPIO_CTRL_CSEL_CSEL1_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_CSEL_CSEL1_Msk) >> GPIO_CTRL_CSEL_CSEL1_Pos) /*!< CSEL1 Get Value */

#define GPIO_CTRL_CSEL_CSEL0_Pos (0U)                               /*!< CSEL0 Postion   */
#define GPIO_CTRL_CSEL_CSEL0_Msk (0xfU << GPIO_CTRL_CSEL_CSEL0_Pos) /*!< CSEL0 Mask      */
#define GPIO_CTRL_CSEL_CSEL0_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_CSEL_CSEL0_Pos) & GPIO_CTRL_CSEL_CSEL0_Msk) /*!< CSEL0 Set Value */
#define GPIO_CTRL_CSEL_CSEL0_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_CSEL_CSEL0_Msk) >> GPIO_CTRL_CSEL_CSEL0_Pos) /*!< CSEL0 Get Value */

/* DS bitfield */
#define GPIO_CTRL_DS_DS15_Pos (30U)                           /*!< DS15 Postion   */
#define GPIO_CTRL_DS_DS15_Msk (0x3U << GPIO_CTRL_DS_DS15_Pos) /*!< DS15 Mask      */
#define GPIO_CTRL_DS_DS15_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_DS_DS15_Pos) & GPIO_CTRL_DS_DS15_Msk) /*!< DS15 Set Value */
#define GPIO_CTRL_DS_DS15_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_DS_DS15_Msk) >> GPIO_CTRL_DS_DS15_Pos) /*!< DS15 Get Value */

#define GPIO_CTRL_DS_DS14_Pos (28U)                           /*!< DS14 Postion   */
#define GPIO_CTRL_DS_DS14_Msk (0x3U << GPIO_CTRL_DS_DS14_Pos) /*!< DS14 Mask      */
#define GPIO_CTRL_DS_DS14_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_DS_DS14_Pos) & GPIO_CTRL_DS_DS14_Msk) /*!< DS14 Set Value */
#define GPIO_CTRL_DS_DS14_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_DS_DS14_Msk) >> GPIO_CTRL_DS_DS14_Pos) /*!< DS14 Get Value */

#define GPIO_CTRL_DS_DS13_Pos (26U)                           /*!< DS13 Postion   */
#define GPIO_CTRL_DS_DS13_Msk (0x3U << GPIO_CTRL_DS_DS13_Pos) /*!< DS13 Mask      */
#define GPIO_CTRL_DS_DS13_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_DS_DS13_Pos) & GPIO_CTRL_DS_DS13_Msk) /*!< DS13 Set Value */
#define GPIO_CTRL_DS_DS13_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_DS_DS13_Msk) >> GPIO_CTRL_DS_DS13_Pos) /*!< DS13 Get Value */

#define GPIO_CTRL_DS_DS12_Pos (24U)                           /*!< DS12 Postion   */
#define GPIO_CTRL_DS_DS12_Msk (0x3U << GPIO_CTRL_DS_DS12_Pos) /*!< DS12 Mask      */
#define GPIO_CTRL_DS_DS12_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_DS_DS12_Pos) & GPIO_CTRL_DS_DS12_Msk) /*!< DS12 Set Value */
#define GPIO_CTRL_DS_DS12_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_DS_DS12_Msk) >> GPIO_CTRL_DS_DS12_Pos) /*!< DS12 Get Value */

#define GPIO_CTRL_DS_DS11_Pos (22U)                           /*!< DS11 Postion   */
#define GPIO_CTRL_DS_DS11_Msk (0x3U << GPIO_CTRL_DS_DS11_Pos) /*!< DS11 Mask      */
#define GPIO_CTRL_DS_DS11_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_DS_DS11_Pos) & GPIO_CTRL_DS_DS11_Msk) /*!< DS11 Set Value */
#define GPIO_CTRL_DS_DS11_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_DS_DS11_Msk) >> GPIO_CTRL_DS_DS11_Pos) /*!< DS11 Get Value */

#define GPIO_CTRL_DS_DS10_Pos (20U)                           /*!< DS10 Postion   */
#define GPIO_CTRL_DS_DS10_Msk (0x3U << GPIO_CTRL_DS_DS10_Pos) /*!< DS10 Mask      */
#define GPIO_CTRL_DS_DS10_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_DS_DS10_Pos) & GPIO_CTRL_DS_DS10_Msk) /*!< DS10 Set Value */
#define GPIO_CTRL_DS_DS10_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_DS_DS10_Msk) >> GPIO_CTRL_DS_DS10_Pos) /*!< DS10 Get Value */

#define GPIO_CTRL_DS_DS9_Pos (18U)                          /*!< DS9 Postion   */
#define GPIO_CTRL_DS_DS9_Msk (0x3U << GPIO_CTRL_DS_DS9_Pos) /*!< DS9 Mask      */
#define GPIO_CTRL_DS_DS9_Set(x)                                                                                     \
    (((uint32_t) (x) << GPIO_CTRL_DS_DS9_Pos) & GPIO_CTRL_DS_DS9_Msk)                            /*!< DS9 Set Value \
                                                                                                  */
#define GPIO_CTRL_DS_DS9_Get(x) (((uint32_t) (x) &GPIO_CTRL_DS_DS9_Msk) >> GPIO_CTRL_DS_DS9_Pos) /*!< DS9 Get Value */

#define GPIO_CTRL_DS_DS8_Pos (16U)                          /*!< DS8 Postion   */
#define GPIO_CTRL_DS_DS8_Msk (0x3U << GPIO_CTRL_DS_DS8_Pos) /*!< DS8 Mask      */
#define GPIO_CTRL_DS_DS8_Set(x)                                                                                     \
    (((uint32_t) (x) << GPIO_CTRL_DS_DS8_Pos) & GPIO_CTRL_DS_DS8_Msk)                            /*!< DS8 Set Value \
                                                                                                  */
#define GPIO_CTRL_DS_DS8_Get(x) (((uint32_t) (x) &GPIO_CTRL_DS_DS8_Msk) >> GPIO_CTRL_DS_DS8_Pos) /*!< DS8 Get Value */

#define GPIO_CTRL_DS_DS7_Pos (14U)                          /*!< DS7 Postion   */
#define GPIO_CTRL_DS_DS7_Msk (0x3U << GPIO_CTRL_DS_DS7_Pos) /*!< DS7 Mask      */
#define GPIO_CTRL_DS_DS7_Set(x)                                                                                     \
    (((uint32_t) (x) << GPIO_CTRL_DS_DS7_Pos) & GPIO_CTRL_DS_DS7_Msk)                            /*!< DS7 Set Value \
                                                                                                  */
#define GPIO_CTRL_DS_DS7_Get(x) (((uint32_t) (x) &GPIO_CTRL_DS_DS7_Msk) >> GPIO_CTRL_DS_DS7_Pos) /*!< DS7 Get Value */

#define GPIO_CTRL_DS_DS6_Pos (12U)                          /*!< DS6 Postion   */
#define GPIO_CTRL_DS_DS6_Msk (0x3U << GPIO_CTRL_DS_DS6_Pos) /*!< DS6 Mask      */
#define GPIO_CTRL_DS_DS6_Set(x)                                                                                     \
    (((uint32_t) (x) << GPIO_CTRL_DS_DS6_Pos) & GPIO_CTRL_DS_DS6_Msk)                            /*!< DS6 Set Value \
                                                                                                  */
#define GPIO_CTRL_DS_DS6_Get(x) (((uint32_t) (x) &GPIO_CTRL_DS_DS6_Msk) >> GPIO_CTRL_DS_DS6_Pos) /*!< DS6 Get Value */

#define GPIO_CTRL_DS_DS5_Pos (10U)                          /*!< DS5 Postion   */
#define GPIO_CTRL_DS_DS5_Msk (0x3U << GPIO_CTRL_DS_DS5_Pos) /*!< DS5 Mask      */
#define GPIO_CTRL_DS_DS5_Set(x)                                                                                     \
    (((uint32_t) (x) << GPIO_CTRL_DS_DS5_Pos) & GPIO_CTRL_DS_DS5_Msk)                            /*!< DS5 Set Value \
                                                                                                  */
#define GPIO_CTRL_DS_DS5_Get(x) (((uint32_t) (x) &GPIO_CTRL_DS_DS5_Msk) >> GPIO_CTRL_DS_DS5_Pos) /*!< DS5 Get Value */

#define GPIO_CTRL_DS_DS4_Pos (8U)                           /*!< DS4 Postion   */
#define GPIO_CTRL_DS_DS4_Msk (0x3U << GPIO_CTRL_DS_DS4_Pos) /*!< DS4 Mask      */
#define GPIO_CTRL_DS_DS4_Set(x)                                                                                     \
    (((uint32_t) (x) << GPIO_CTRL_DS_DS4_Pos) & GPIO_CTRL_DS_DS4_Msk)                            /*!< DS4 Set Value \
                                                                                                  */
#define GPIO_CTRL_DS_DS4_Get(x) (((uint32_t) (x) &GPIO_CTRL_DS_DS4_Msk) >> GPIO_CTRL_DS_DS4_Pos) /*!< DS4 Get Value */

#define GPIO_CTRL_DS_DS3_Pos (6U)                           /*!< DS3 Postion   */
#define GPIO_CTRL_DS_DS3_Msk (0x3U << GPIO_CTRL_DS_DS3_Pos) /*!< DS3 Mask      */
#define GPIO_CTRL_DS_DS3_Set(x)                                                                                     \
    (((uint32_t) (x) << GPIO_CTRL_DS_DS3_Pos) & GPIO_CTRL_DS_DS3_Msk)                            /*!< DS3 Set Value \
                                                                                                  */
#define GPIO_CTRL_DS_DS3_Get(x) (((uint32_t) (x) &GPIO_CTRL_DS_DS3_Msk) >> GPIO_CTRL_DS_DS3_Pos) /*!< DS3 Get Value */

#define GPIO_CTRL_DS_DS2_Pos (4U)                           /*!< DS2 Postion   */
#define GPIO_CTRL_DS_DS2_Msk (0x3U << GPIO_CTRL_DS_DS2_Pos) /*!< DS2 Mask      */
#define GPIO_CTRL_DS_DS2_Set(x)                                                                                     \
    (((uint32_t) (x) << GPIO_CTRL_DS_DS2_Pos) & GPIO_CTRL_DS_DS2_Msk)                            /*!< DS2 Set Value \
                                                                                                  */
#define GPIO_CTRL_DS_DS2_Get(x) (((uint32_t) (x) &GPIO_CTRL_DS_DS2_Msk) >> GPIO_CTRL_DS_DS2_Pos) /*!< DS2 Get Value */

#define GPIO_CTRL_DS_DS1_Pos (2U)                           /*!< DS1 Postion   */
#define GPIO_CTRL_DS_DS1_Msk (0x3U << GPIO_CTRL_DS_DS1_Pos) /*!< DS1 Mask      */
#define GPIO_CTRL_DS_DS1_Set(x)                                                                                     \
    (((uint32_t) (x) << GPIO_CTRL_DS_DS1_Pos) & GPIO_CTRL_DS_DS1_Msk)                            /*!< DS1 Set Value \
                                                                                                  */
#define GPIO_CTRL_DS_DS1_Get(x) (((uint32_t) (x) &GPIO_CTRL_DS_DS1_Msk) >> GPIO_CTRL_DS_DS1_Pos) /*!< DS1 Get Value */

#define GPIO_CTRL_DS_DS0_Pos (0U)                           /*!< DS0 Postion   */
#define GPIO_CTRL_DS_DS0_Msk (0x3U << GPIO_CTRL_DS_DS0_Pos) /*!< DS0 Mask      */
#define GPIO_CTRL_DS_DS0_Set(x)                                                                                     \
    (((uint32_t) (x) << GPIO_CTRL_DS_DS0_Pos) & GPIO_CTRL_DS_DS0_Msk)                            /*!< DS0 Set Value \
                                                                                                  */
#define GPIO_CTRL_DS_DS0_Get(x) (((uint32_t) (x) &GPIO_CTRL_DS_DS0_Msk) >> GPIO_CTRL_DS_DS0_Pos) /*!< DS0 Get Value */

/* PDD bitfield */
#define GPIO_CTRL_PDD_PDD31_Pos (31U)                             /*!< PDD31 Postion   */
#define GPIO_CTRL_PDD_PDD31_Msk (0x1U << GPIO_CTRL_PDD_PDD31_Pos) /*!< PDD31 Mask      */
#define GPIO_CTRL_PDD_PDD31_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PDD_PDD31_Pos) & GPIO_CTRL_PDD_PDD31_Msk) /*!< PDD31 Set Value */
#define GPIO_CTRL_PDD_PDD31_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PDD_PDD31_Msk) >> GPIO_CTRL_PDD_PDD31_Pos) /*!< PDD31 Get Value */

#define GPIO_CTRL_PDD_PDD30_Pos (30U)                             /*!< PDD30 Postion   */
#define GPIO_CTRL_PDD_PDD30_Msk (0x1U << GPIO_CTRL_PDD_PDD30_Pos) /*!< PDD30 Mask      */
#define GPIO_CTRL_PDD_PDD30_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PDD_PDD30_Pos) & GPIO_CTRL_PDD_PDD30_Msk) /*!< PDD30 Set Value */
#define GPIO_CTRL_PDD_PDD30_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PDD_PDD30_Msk) >> GPIO_CTRL_PDD_PDD30_Pos) /*!< PDD30 Get Value */

#define GPIO_CTRL_PDD_PDD29_Pos (29U)                             /*!< PDD29 Postion   */
#define GPIO_CTRL_PDD_PDD29_Msk (0x1U << GPIO_CTRL_PDD_PDD29_Pos) /*!< PDD29 Mask      */
#define GPIO_CTRL_PDD_PDD29_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PDD_PDD29_Pos) & GPIO_CTRL_PDD_PDD29_Msk) /*!< PDD29 Set Value */
#define GPIO_CTRL_PDD_PDD29_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PDD_PDD29_Msk) >> GPIO_CTRL_PDD_PDD29_Pos) /*!< PDD29 Get Value */

#define GPIO_CTRL_PDD_PDD28_Pos (28U)                             /*!< PDD28 Postion   */
#define GPIO_CTRL_PDD_PDD28_Msk (0x1U << GPIO_CTRL_PDD_PDD28_Pos) /*!< PDD28 Mask      */
#define GPIO_CTRL_PDD_PDD28_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PDD_PDD28_Pos) & GPIO_CTRL_PDD_PDD28_Msk) /*!< PDD28 Set Value */
#define GPIO_CTRL_PDD_PDD28_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PDD_PDD28_Msk) >> GPIO_CTRL_PDD_PDD28_Pos) /*!< PDD28 Get Value */

#define GPIO_CTRL_PDD_PDD27_Pos (27U)                             /*!< PDD27 Postion   */
#define GPIO_CTRL_PDD_PDD27_Msk (0x1U << GPIO_CTRL_PDD_PDD27_Pos) /*!< PDD27 Mask      */
#define GPIO_CTRL_PDD_PDD27_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PDD_PDD27_Pos) & GPIO_CTRL_PDD_PDD27_Msk) /*!< PDD27 Set Value */
#define GPIO_CTRL_PDD_PDD27_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PDD_PDD27_Msk) >> GPIO_CTRL_PDD_PDD27_Pos) /*!< PDD27 Get Value */

#define GPIO_CTRL_PDD_PDD26_Pos (26U)                             /*!< PDD26 Postion   */
#define GPIO_CTRL_PDD_PDD26_Msk (0x1U << GPIO_CTRL_PDD_PDD26_Pos) /*!< PDD26 Mask      */
#define GPIO_CTRL_PDD_PDD26_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PDD_PDD26_Pos) & GPIO_CTRL_PDD_PDD26_Msk) /*!< PDD26 Set Value */
#define GPIO_CTRL_PDD_PDD26_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PDD_PDD26_Msk) >> GPIO_CTRL_PDD_PDD26_Pos) /*!< PDD26 Get Value */

#define GPIO_CTRL_PDD_PDD25_Pos (25U)                             /*!< PDD25 Postion   */
#define GPIO_CTRL_PDD_PDD25_Msk (0x1U << GPIO_CTRL_PDD_PDD25_Pos) /*!< PDD25 Mask      */
#define GPIO_CTRL_PDD_PDD25_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PDD_PDD25_Pos) & GPIO_CTRL_PDD_PDD25_Msk) /*!< PDD25 Set Value */
#define GPIO_CTRL_PDD_PDD25_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PDD_PDD25_Msk) >> GPIO_CTRL_PDD_PDD25_Pos) /*!< PDD25 Get Value */

#define GPIO_CTRL_PDD_PDD24_Pos (24U)                             /*!< PDD24 Postion   */
#define GPIO_CTRL_PDD_PDD24_Msk (0x1U << GPIO_CTRL_PDD_PDD24_Pos) /*!< PDD24 Mask      */
#define GPIO_CTRL_PDD_PDD24_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PDD_PDD24_Pos) & GPIO_CTRL_PDD_PDD24_Msk) /*!< PDD24 Set Value */
#define GPIO_CTRL_PDD_PDD24_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PDD_PDD24_Msk) >> GPIO_CTRL_PDD_PDD24_Pos) /*!< PDD24 Get Value */

#define GPIO_CTRL_PDD_PDD23_Pos (23U)                             /*!< PDD23 Postion   */
#define GPIO_CTRL_PDD_PDD23_Msk (0x1U << GPIO_CTRL_PDD_PDD23_Pos) /*!< PDD23 Mask      */
#define GPIO_CTRL_PDD_PDD23_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PDD_PDD23_Pos) & GPIO_CTRL_PDD_PDD23_Msk) /*!< PDD23 Set Value */
#define GPIO_CTRL_PDD_PDD23_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PDD_PDD23_Msk) >> GPIO_CTRL_PDD_PDD23_Pos) /*!< PDD23 Get Value */

#define GPIO_CTRL_PDD_PDD22_Pos (22U)                             /*!< PDD22 Postion   */
#define GPIO_CTRL_PDD_PDD22_Msk (0x1U << GPIO_CTRL_PDD_PDD22_Pos) /*!< PDD22 Mask      */
#define GPIO_CTRL_PDD_PDD22_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PDD_PDD22_Pos) & GPIO_CTRL_PDD_PDD22_Msk) /*!< PDD22 Set Value */
#define GPIO_CTRL_PDD_PDD22_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PDD_PDD22_Msk) >> GPIO_CTRL_PDD_PDD22_Pos) /*!< PDD22 Get Value */

#define GPIO_CTRL_PDD_PDD21_Pos (21U)                             /*!< PDD21 Postion   */
#define GPIO_CTRL_PDD_PDD21_Msk (0x1U << GPIO_CTRL_PDD_PDD21_Pos) /*!< PDD21 Mask      */
#define GPIO_CTRL_PDD_PDD21_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PDD_PDD21_Pos) & GPIO_CTRL_PDD_PDD21_Msk) /*!< PDD21 Set Value */
#define GPIO_CTRL_PDD_PDD21_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PDD_PDD21_Msk) >> GPIO_CTRL_PDD_PDD21_Pos) /*!< PDD21 Get Value */

#define GPIO_CTRL_PDD_PDD20_Pos (20U)                             /*!< PDD20 Postion   */
#define GPIO_CTRL_PDD_PDD20_Msk (0x1U << GPIO_CTRL_PDD_PDD20_Pos) /*!< PDD20 Mask      */
#define GPIO_CTRL_PDD_PDD20_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PDD_PDD20_Pos) & GPIO_CTRL_PDD_PDD20_Msk) /*!< PDD20 Set Value */
#define GPIO_CTRL_PDD_PDD20_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PDD_PDD20_Msk) >> GPIO_CTRL_PDD_PDD20_Pos) /*!< PDD20 Get Value */

#define GPIO_CTRL_PDD_PDD19_Pos (19U)                             /*!< PDD19 Postion   */
#define GPIO_CTRL_PDD_PDD19_Msk (0x1U << GPIO_CTRL_PDD_PDD19_Pos) /*!< PDD19 Mask      */
#define GPIO_CTRL_PDD_PDD19_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PDD_PDD19_Pos) & GPIO_CTRL_PDD_PDD19_Msk) /*!< PDD19 Set Value */
#define GPIO_CTRL_PDD_PDD19_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PDD_PDD19_Msk) >> GPIO_CTRL_PDD_PDD19_Pos) /*!< PDD19 Get Value */

#define GPIO_CTRL_PDD_PDD18_Pos (18U)                             /*!< PDD18 Postion   */
#define GPIO_CTRL_PDD_PDD18_Msk (0x1U << GPIO_CTRL_PDD_PDD18_Pos) /*!< PDD18 Mask      */
#define GPIO_CTRL_PDD_PDD18_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PDD_PDD18_Pos) & GPIO_CTRL_PDD_PDD18_Msk) /*!< PDD18 Set Value */
#define GPIO_CTRL_PDD_PDD18_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PDD_PDD18_Msk) >> GPIO_CTRL_PDD_PDD18_Pos) /*!< PDD18 Get Value */

#define GPIO_CTRL_PDD_PDD17_Pos (17U)                             /*!< PDD17 Postion   */
#define GPIO_CTRL_PDD_PDD17_Msk (0x1U << GPIO_CTRL_PDD_PDD17_Pos) /*!< PDD17 Mask      */
#define GPIO_CTRL_PDD_PDD17_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PDD_PDD17_Pos) & GPIO_CTRL_PDD_PDD17_Msk) /*!< PDD17 Set Value */
#define GPIO_CTRL_PDD_PDD17_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PDD_PDD17_Msk) >> GPIO_CTRL_PDD_PDD17_Pos) /*!< PDD17 Get Value */

#define GPIO_CTRL_PDD_PDD16_Pos (16U)                             /*!< PDD16 Postion   */
#define GPIO_CTRL_PDD_PDD16_Msk (0x1U << GPIO_CTRL_PDD_PDD16_Pos) /*!< PDD16 Mask      */
#define GPIO_CTRL_PDD_PDD16_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PDD_PDD16_Pos) & GPIO_CTRL_PDD_PDD16_Msk) /*!< PDD16 Set Value */
#define GPIO_CTRL_PDD_PDD16_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PDD_PDD16_Msk) >> GPIO_CTRL_PDD_PDD16_Pos) /*!< PDD16 Get Value */

#define GPIO_CTRL_PDD_PDD15_Pos (15U)                             /*!< PDD15 Postion   */
#define GPIO_CTRL_PDD_PDD15_Msk (0x1U << GPIO_CTRL_PDD_PDD15_Pos) /*!< PDD15 Mask      */
#define GPIO_CTRL_PDD_PDD15_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PDD_PDD15_Pos) & GPIO_CTRL_PDD_PDD15_Msk) /*!< PDD15 Set Value */
#define GPIO_CTRL_PDD_PDD15_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PDD_PDD15_Msk) >> GPIO_CTRL_PDD_PDD15_Pos) /*!< PDD15 Get Value */

#define GPIO_CTRL_PDD_PDD14_Pos (14U)                             /*!< PDD14 Postion   */
#define GPIO_CTRL_PDD_PDD14_Msk (0x1U << GPIO_CTRL_PDD_PDD14_Pos) /*!< PDD14 Mask      */
#define GPIO_CTRL_PDD_PDD14_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PDD_PDD14_Pos) & GPIO_CTRL_PDD_PDD14_Msk) /*!< PDD14 Set Value */
#define GPIO_CTRL_PDD_PDD14_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PDD_PDD14_Msk) >> GPIO_CTRL_PDD_PDD14_Pos) /*!< PDD14 Get Value */

#define GPIO_CTRL_PDD_PDD13_Pos (13U)                             /*!< PDD13 Postion   */
#define GPIO_CTRL_PDD_PDD13_Msk (0x1U << GPIO_CTRL_PDD_PDD13_Pos) /*!< PDD13 Mask      */
#define GPIO_CTRL_PDD_PDD13_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PDD_PDD13_Pos) & GPIO_CTRL_PDD_PDD13_Msk) /*!< PDD13 Set Value */
#define GPIO_CTRL_PDD_PDD13_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PDD_PDD13_Msk) >> GPIO_CTRL_PDD_PDD13_Pos) /*!< PDD13 Get Value */

#define GPIO_CTRL_PDD_PDD12_Pos (12U)                             /*!< PDD12 Postion   */
#define GPIO_CTRL_PDD_PDD12_Msk (0x1U << GPIO_CTRL_PDD_PDD12_Pos) /*!< PDD12 Mask      */
#define GPIO_CTRL_PDD_PDD12_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PDD_PDD12_Pos) & GPIO_CTRL_PDD_PDD12_Msk) /*!< PDD12 Set Value */
#define GPIO_CTRL_PDD_PDD12_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PDD_PDD12_Msk) >> GPIO_CTRL_PDD_PDD12_Pos) /*!< PDD12 Get Value */

#define GPIO_CTRL_PDD_PDD11_Pos (11U)                             /*!< PDD11 Postion   */
#define GPIO_CTRL_PDD_PDD11_Msk (0x1U << GPIO_CTRL_PDD_PDD11_Pos) /*!< PDD11 Mask      */
#define GPIO_CTRL_PDD_PDD11_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PDD_PDD11_Pos) & GPIO_CTRL_PDD_PDD11_Msk) /*!< PDD11 Set Value */
#define GPIO_CTRL_PDD_PDD11_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PDD_PDD11_Msk) >> GPIO_CTRL_PDD_PDD11_Pos) /*!< PDD11 Get Value */

#define GPIO_CTRL_PDD_PDD10_Pos (10U)                             /*!< PDD10 Postion   */
#define GPIO_CTRL_PDD_PDD10_Msk (0x1U << GPIO_CTRL_PDD_PDD10_Pos) /*!< PDD10 Mask      */
#define GPIO_CTRL_PDD_PDD10_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PDD_PDD10_Pos) & GPIO_CTRL_PDD_PDD10_Msk) /*!< PDD10 Set Value */
#define GPIO_CTRL_PDD_PDD10_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PDD_PDD10_Msk) >> GPIO_CTRL_PDD_PDD10_Pos) /*!< PDD10 Get Value */

#define GPIO_CTRL_PDD_PDD9_Pos (9U)                             /*!< PDD9 Postion   */
#define GPIO_CTRL_PDD_PDD9_Msk (0x1U << GPIO_CTRL_PDD_PDD9_Pos) /*!< PDD9 Mask      */
#define GPIO_CTRL_PDD_PDD9_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PDD_PDD9_Pos) & GPIO_CTRL_PDD_PDD9_Msk) /*!< PDD9 Set Value */
#define GPIO_CTRL_PDD_PDD9_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PDD_PDD9_Msk) >> GPIO_CTRL_PDD_PDD9_Pos) /*!< PDD9 Get Value */

#define GPIO_CTRL_PDD_PDD8_Pos (8U)                             /*!< PDD8 Postion   */
#define GPIO_CTRL_PDD_PDD8_Msk (0x1U << GPIO_CTRL_PDD_PDD8_Pos) /*!< PDD8 Mask      */
#define GPIO_CTRL_PDD_PDD8_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PDD_PDD8_Pos) & GPIO_CTRL_PDD_PDD8_Msk) /*!< PDD8 Set Value */
#define GPIO_CTRL_PDD_PDD8_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PDD_PDD8_Msk) >> GPIO_CTRL_PDD_PDD8_Pos) /*!< PDD8 Get Value */

#define GPIO_CTRL_PDD_PDD7_Pos (7U)                             /*!< PDD7 Postion   */
#define GPIO_CTRL_PDD_PDD7_Msk (0x1U << GPIO_CTRL_PDD_PDD7_Pos) /*!< PDD7 Mask      */
#define GPIO_CTRL_PDD_PDD7_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PDD_PDD7_Pos) & GPIO_CTRL_PDD_PDD7_Msk) /*!< PDD7 Set Value */
#define GPIO_CTRL_PDD_PDD7_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PDD_PDD7_Msk) >> GPIO_CTRL_PDD_PDD7_Pos) /*!< PDD7 Get Value */

#define GPIO_CTRL_PDD_PDD6_Pos (6U)                             /*!< PDD6 Postion   */
#define GPIO_CTRL_PDD_PDD6_Msk (0x1U << GPIO_CTRL_PDD_PDD6_Pos) /*!< PDD6 Mask      */
#define GPIO_CTRL_PDD_PDD6_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PDD_PDD6_Pos) & GPIO_CTRL_PDD_PDD6_Msk) /*!< PDD6 Set Value */
#define GPIO_CTRL_PDD_PDD6_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PDD_PDD6_Msk) >> GPIO_CTRL_PDD_PDD6_Pos) /*!< PDD6 Get Value */

#define GPIO_CTRL_PDD_PDD5_Pos (5U)                             /*!< PDD5 Postion   */
#define GPIO_CTRL_PDD_PDD5_Msk (0x1U << GPIO_CTRL_PDD_PDD5_Pos) /*!< PDD5 Mask      */
#define GPIO_CTRL_PDD_PDD5_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PDD_PDD5_Pos) & GPIO_CTRL_PDD_PDD5_Msk) /*!< PDD5 Set Value */
#define GPIO_CTRL_PDD_PDD5_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PDD_PDD5_Msk) >> GPIO_CTRL_PDD_PDD5_Pos) /*!< PDD5 Get Value */

#define GPIO_CTRL_PDD_PDD4_Pos (4U)                             /*!< PDD4 Postion   */
#define GPIO_CTRL_PDD_PDD4_Msk (0x1U << GPIO_CTRL_PDD_PDD4_Pos) /*!< PDD4 Mask      */
#define GPIO_CTRL_PDD_PDD4_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PDD_PDD4_Pos) & GPIO_CTRL_PDD_PDD4_Msk) /*!< PDD4 Set Value */
#define GPIO_CTRL_PDD_PDD4_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PDD_PDD4_Msk) >> GPIO_CTRL_PDD_PDD4_Pos) /*!< PDD4 Get Value */

#define GPIO_CTRL_PDD_PDD3_Pos (3U)                             /*!< PDD3 Postion   */
#define GPIO_CTRL_PDD_PDD3_Msk (0x1U << GPIO_CTRL_PDD_PDD3_Pos) /*!< PDD3 Mask      */
#define GPIO_CTRL_PDD_PDD3_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PDD_PDD3_Pos) & GPIO_CTRL_PDD_PDD3_Msk) /*!< PDD3 Set Value */
#define GPIO_CTRL_PDD_PDD3_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PDD_PDD3_Msk) >> GPIO_CTRL_PDD_PDD3_Pos) /*!< PDD3 Get Value */

#define GPIO_CTRL_PDD_PDD2_Pos (2U)                             /*!< PDD2 Postion   */
#define GPIO_CTRL_PDD_PDD2_Msk (0x1U << GPIO_CTRL_PDD_PDD2_Pos) /*!< PDD2 Mask      */
#define GPIO_CTRL_PDD_PDD2_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PDD_PDD2_Pos) & GPIO_CTRL_PDD_PDD2_Msk) /*!< PDD2 Set Value */
#define GPIO_CTRL_PDD_PDD2_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PDD_PDD2_Msk) >> GPIO_CTRL_PDD_PDD2_Pos) /*!< PDD2 Get Value */

#define GPIO_CTRL_PDD_PDD1_Pos (1U)                             /*!< PDD1 Postion   */
#define GPIO_CTRL_PDD_PDD1_Msk (0x1U << GPIO_CTRL_PDD_PDD1_Pos) /*!< PDD1 Mask      */
#define GPIO_CTRL_PDD_PDD1_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PDD_PDD1_Pos) & GPIO_CTRL_PDD_PDD1_Msk) /*!< PDD1 Set Value */
#define GPIO_CTRL_PDD_PDD1_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PDD_PDD1_Msk) >> GPIO_CTRL_PDD_PDD1_Pos) /*!< PDD1 Get Value */

#define GPIO_CTRL_PDD_PDD0_Pos (0U)                             /*!< PDD0 Postion   */
#define GPIO_CTRL_PDD_PDD0_Msk (0x1U << GPIO_CTRL_PDD_PDD0_Pos) /*!< PDD0 Mask      */
#define GPIO_CTRL_PDD_PDD0_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_PDD_PDD0_Pos) & GPIO_CTRL_PDD_PDD0_Msk) /*!< PDD0 Set Value */
#define GPIO_CTRL_PDD_PDD0_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_PDD_PDD0_Msk) >> GPIO_CTRL_PDD_PDD0_Pos) /*!< PDD0 Get Value */

/* FID bitfield */
#define GPIO_CTRL_FID_FID31_Pos (31U)                             /*!< FID31 Postion   */
#define GPIO_CTRL_FID_FID31_Msk (0x1U << GPIO_CTRL_FID_FID31_Pos) /*!< FID31 Mask      */
#define GPIO_CTRL_FID_FID31_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_FID_FID31_Pos) & GPIO_CTRL_FID_FID31_Msk) /*!< FID31 Set Value */
#define GPIO_CTRL_FID_FID31_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_FID_FID31_Msk) >> GPIO_CTRL_FID_FID31_Pos) /*!< FID31 Get Value */

#define GPIO_CTRL_FID_FID30_Pos (30U)                             /*!< FID30 Postion   */
#define GPIO_CTRL_FID_FID30_Msk (0x1U << GPIO_CTRL_FID_FID30_Pos) /*!< FID30 Mask      */
#define GPIO_CTRL_FID_FID30_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_FID_FID30_Pos) & GPIO_CTRL_FID_FID30_Msk) /*!< FID30 Set Value */
#define GPIO_CTRL_FID_FID30_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_FID_FID30_Msk) >> GPIO_CTRL_FID_FID30_Pos) /*!< FID30 Get Value */

#define GPIO_CTRL_FID_FID29_Pos (29U)                             /*!< FID29 Postion   */
#define GPIO_CTRL_FID_FID29_Msk (0x1U << GPIO_CTRL_FID_FID29_Pos) /*!< FID29 Mask      */
#define GPIO_CTRL_FID_FID29_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_FID_FID29_Pos) & GPIO_CTRL_FID_FID29_Msk) /*!< FID29 Set Value */
#define GPIO_CTRL_FID_FID29_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_FID_FID29_Msk) >> GPIO_CTRL_FID_FID29_Pos) /*!< FID29 Get Value */

#define GPIO_CTRL_FID_FID28_Pos (28U)                             /*!< FID28 Postion   */
#define GPIO_CTRL_FID_FID28_Msk (0x1U << GPIO_CTRL_FID_FID28_Pos) /*!< FID28 Mask      */
#define GPIO_CTRL_FID_FID28_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_FID_FID28_Pos) & GPIO_CTRL_FID_FID28_Msk) /*!< FID28 Set Value */
#define GPIO_CTRL_FID_FID28_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_FID_FID28_Msk) >> GPIO_CTRL_FID_FID28_Pos) /*!< FID28 Get Value */

#define GPIO_CTRL_FID_FID27_Pos (27U)                             /*!< FID27 Postion   */
#define GPIO_CTRL_FID_FID27_Msk (0x1U << GPIO_CTRL_FID_FID27_Pos) /*!< FID27 Mask      */
#define GPIO_CTRL_FID_FID27_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_FID_FID27_Pos) & GPIO_CTRL_FID_FID27_Msk) /*!< FID27 Set Value */
#define GPIO_CTRL_FID_FID27_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_FID_FID27_Msk) >> GPIO_CTRL_FID_FID27_Pos) /*!< FID27 Get Value */

#define GPIO_CTRL_FID_FID26_Pos (26U)                             /*!< FID26 Postion   */
#define GPIO_CTRL_FID_FID26_Msk (0x1U << GPIO_CTRL_FID_FID26_Pos) /*!< FID26 Mask      */
#define GPIO_CTRL_FID_FID26_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_FID_FID26_Pos) & GPIO_CTRL_FID_FID26_Msk) /*!< FID26 Set Value */
#define GPIO_CTRL_FID_FID26_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_FID_FID26_Msk) >> GPIO_CTRL_FID_FID26_Pos) /*!< FID26 Get Value */

#define GPIO_CTRL_FID_FID25_Pos (25U)                             /*!< FID25 Postion   */
#define GPIO_CTRL_FID_FID25_Msk (0x1U << GPIO_CTRL_FID_FID25_Pos) /*!< FID25 Mask      */
#define GPIO_CTRL_FID_FID25_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_FID_FID25_Pos) & GPIO_CTRL_FID_FID25_Msk) /*!< FID25 Set Value */
#define GPIO_CTRL_FID_FID25_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_FID_FID25_Msk) >> GPIO_CTRL_FID_FID25_Pos) /*!< FID25 Get Value */

#define GPIO_CTRL_FID_FID24_Pos (24U)                             /*!< FID24 Postion   */
#define GPIO_CTRL_FID_FID24_Msk (0x1U << GPIO_CTRL_FID_FID24_Pos) /*!< FID24 Mask      */
#define GPIO_CTRL_FID_FID24_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_FID_FID24_Pos) & GPIO_CTRL_FID_FID24_Msk) /*!< FID24 Set Value */
#define GPIO_CTRL_FID_FID24_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_FID_FID24_Msk) >> GPIO_CTRL_FID_FID24_Pos) /*!< FID24 Get Value */

#define GPIO_CTRL_FID_FID23_Pos (23U)                             /*!< FID23 Postion   */
#define GPIO_CTRL_FID_FID23_Msk (0x1U << GPIO_CTRL_FID_FID23_Pos) /*!< FID23 Mask      */
#define GPIO_CTRL_FID_FID23_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_FID_FID23_Pos) & GPIO_CTRL_FID_FID23_Msk) /*!< FID23 Set Value */
#define GPIO_CTRL_FID_FID23_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_FID_FID23_Msk) >> GPIO_CTRL_FID_FID23_Pos) /*!< FID23 Get Value */

#define GPIO_CTRL_FID_FID22_Pos (22U)                             /*!< FID22 Postion   */
#define GPIO_CTRL_FID_FID22_Msk (0x1U << GPIO_CTRL_FID_FID22_Pos) /*!< FID22 Mask      */
#define GPIO_CTRL_FID_FID22_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_FID_FID22_Pos) & GPIO_CTRL_FID_FID22_Msk) /*!< FID22 Set Value */
#define GPIO_CTRL_FID_FID22_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_FID_FID22_Msk) >> GPIO_CTRL_FID_FID22_Pos) /*!< FID22 Get Value */

#define GPIO_CTRL_FID_FID21_Pos (21U)                             /*!< FID21 Postion   */
#define GPIO_CTRL_FID_FID21_Msk (0x1U << GPIO_CTRL_FID_FID21_Pos) /*!< FID21 Mask      */
#define GPIO_CTRL_FID_FID21_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_FID_FID21_Pos) & GPIO_CTRL_FID_FID21_Msk) /*!< FID21 Set Value */
#define GPIO_CTRL_FID_FID21_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_FID_FID21_Msk) >> GPIO_CTRL_FID_FID21_Pos) /*!< FID21 Get Value */

#define GPIO_CTRL_FID_FID20_Pos (20U)                             /*!< FID20 Postion   */
#define GPIO_CTRL_FID_FID20_Msk (0x1U << GPIO_CTRL_FID_FID20_Pos) /*!< FID20 Mask      */
#define GPIO_CTRL_FID_FID20_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_FID_FID20_Pos) & GPIO_CTRL_FID_FID20_Msk) /*!< FID20 Set Value */
#define GPIO_CTRL_FID_FID20_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_FID_FID20_Msk) >> GPIO_CTRL_FID_FID20_Pos) /*!< FID20 Get Value */

#define GPIO_CTRL_FID_FID19_Pos (19U)                             /*!< FID19 Postion   */
#define GPIO_CTRL_FID_FID19_Msk (0x1U << GPIO_CTRL_FID_FID19_Pos) /*!< FID19 Mask      */
#define GPIO_CTRL_FID_FID19_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_FID_FID19_Pos) & GPIO_CTRL_FID_FID19_Msk) /*!< FID19 Set Value */
#define GPIO_CTRL_FID_FID19_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_FID_FID19_Msk) >> GPIO_CTRL_FID_FID19_Pos) /*!< FID19 Get Value */

#define GPIO_CTRL_FID_FID18_Pos (18U)                             /*!< FID18 Postion   */
#define GPIO_CTRL_FID_FID18_Msk (0x1U << GPIO_CTRL_FID_FID18_Pos) /*!< FID18 Mask      */
#define GPIO_CTRL_FID_FID18_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_FID_FID18_Pos) & GPIO_CTRL_FID_FID18_Msk) /*!< FID18 Set Value */
#define GPIO_CTRL_FID_FID18_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_FID_FID18_Msk) >> GPIO_CTRL_FID_FID18_Pos) /*!< FID18 Get Value */

#define GPIO_CTRL_FID_FID17_Pos (17U)                             /*!< FID17 Postion   */
#define GPIO_CTRL_FID_FID17_Msk (0x1U << GPIO_CTRL_FID_FID17_Pos) /*!< FID17 Mask      */
#define GPIO_CTRL_FID_FID17_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_FID_FID17_Pos) & GPIO_CTRL_FID_FID17_Msk) /*!< FID17 Set Value */
#define GPIO_CTRL_FID_FID17_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_FID_FID17_Msk) >> GPIO_CTRL_FID_FID17_Pos) /*!< FID17 Get Value */

#define GPIO_CTRL_FID_FID16_Pos (16U)                             /*!< FID16 Postion   */
#define GPIO_CTRL_FID_FID16_Msk (0x1U << GPIO_CTRL_FID_FID16_Pos) /*!< FID16 Mask      */
#define GPIO_CTRL_FID_FID16_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_FID_FID16_Pos) & GPIO_CTRL_FID_FID16_Msk) /*!< FID16 Set Value */
#define GPIO_CTRL_FID_FID16_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_FID_FID16_Msk) >> GPIO_CTRL_FID_FID16_Pos) /*!< FID16 Get Value */

#define GPIO_CTRL_FID_FID15_Pos (15U)                             /*!< FID15 Postion   */
#define GPIO_CTRL_FID_FID15_Msk (0x1U << GPIO_CTRL_FID_FID15_Pos) /*!< FID15 Mask      */
#define GPIO_CTRL_FID_FID15_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_FID_FID15_Pos) & GPIO_CTRL_FID_FID15_Msk) /*!< FID15 Set Value */
#define GPIO_CTRL_FID_FID15_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_FID_FID15_Msk) >> GPIO_CTRL_FID_FID15_Pos) /*!< FID15 Get Value */

#define GPIO_CTRL_FID_FID14_Pos (14U)                             /*!< FID14 Postion   */
#define GPIO_CTRL_FID_FID14_Msk (0x1U << GPIO_CTRL_FID_FID14_Pos) /*!< FID14 Mask      */
#define GPIO_CTRL_FID_FID14_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_FID_FID14_Pos) & GPIO_CTRL_FID_FID14_Msk) /*!< FID14 Set Value */
#define GPIO_CTRL_FID_FID14_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_FID_FID14_Msk) >> GPIO_CTRL_FID_FID14_Pos) /*!< FID14 Get Value */

#define GPIO_CTRL_FID_FID13_Pos (13U)                             /*!< FID13 Postion   */
#define GPIO_CTRL_FID_FID13_Msk (0x1U << GPIO_CTRL_FID_FID13_Pos) /*!< FID13 Mask      */
#define GPIO_CTRL_FID_FID13_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_FID_FID13_Pos) & GPIO_CTRL_FID_FID13_Msk) /*!< FID13 Set Value */
#define GPIO_CTRL_FID_FID13_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_FID_FID13_Msk) >> GPIO_CTRL_FID_FID13_Pos) /*!< FID13 Get Value */

#define GPIO_CTRL_FID_FID12_Pos (12U)                             /*!< FID12 Postion   */
#define GPIO_CTRL_FID_FID12_Msk (0x1U << GPIO_CTRL_FID_FID12_Pos) /*!< FID12 Mask      */
#define GPIO_CTRL_FID_FID12_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_FID_FID12_Pos) & GPIO_CTRL_FID_FID12_Msk) /*!< FID12 Set Value */
#define GPIO_CTRL_FID_FID12_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_FID_FID12_Msk) >> GPIO_CTRL_FID_FID12_Pos) /*!< FID12 Get Value */

#define GPIO_CTRL_FID_FID11_Pos (11U)                             /*!< FID11 Postion   */
#define GPIO_CTRL_FID_FID11_Msk (0x1U << GPIO_CTRL_FID_FID11_Pos) /*!< FID11 Mask      */
#define GPIO_CTRL_FID_FID11_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_FID_FID11_Pos) & GPIO_CTRL_FID_FID11_Msk) /*!< FID11 Set Value */
#define GPIO_CTRL_FID_FID11_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_FID_FID11_Msk) >> GPIO_CTRL_FID_FID11_Pos) /*!< FID11 Get Value */

#define GPIO_CTRL_FID_FID10_Pos (10U)                             /*!< FID10 Postion   */
#define GPIO_CTRL_FID_FID10_Msk (0x1U << GPIO_CTRL_FID_FID10_Pos) /*!< FID10 Mask      */
#define GPIO_CTRL_FID_FID10_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_FID_FID10_Pos) & GPIO_CTRL_FID_FID10_Msk) /*!< FID10 Set Value */
#define GPIO_CTRL_FID_FID10_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_FID_FID10_Msk) >> GPIO_CTRL_FID_FID10_Pos) /*!< FID10 Get Value */

#define GPIO_CTRL_FID_FID9_Pos (9U)                             /*!< FID9 Postion   */
#define GPIO_CTRL_FID_FID9_Msk (0x1U << GPIO_CTRL_FID_FID9_Pos) /*!< FID9 Mask      */
#define GPIO_CTRL_FID_FID9_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_FID_FID9_Pos) & GPIO_CTRL_FID_FID9_Msk) /*!< FID9 Set Value */
#define GPIO_CTRL_FID_FID9_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_FID_FID9_Msk) >> GPIO_CTRL_FID_FID9_Pos) /*!< FID9 Get Value */

#define GPIO_CTRL_FID_FID8_Pos (8U)                             /*!< FID8 Postion   */
#define GPIO_CTRL_FID_FID8_Msk (0x1U << GPIO_CTRL_FID_FID8_Pos) /*!< FID8 Mask      */
#define GPIO_CTRL_FID_FID8_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_FID_FID8_Pos) & GPIO_CTRL_FID_FID8_Msk) /*!< FID8 Set Value */
#define GPIO_CTRL_FID_FID8_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_FID_FID8_Msk) >> GPIO_CTRL_FID_FID8_Pos) /*!< FID8 Get Value */

#define GPIO_CTRL_FID_FID7_Pos (7U)                             /*!< FID7 Postion   */
#define GPIO_CTRL_FID_FID7_Msk (0x1U << GPIO_CTRL_FID_FID7_Pos) /*!< FID7 Mask      */
#define GPIO_CTRL_FID_FID7_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_FID_FID7_Pos) & GPIO_CTRL_FID_FID7_Msk) /*!< FID7 Set Value */
#define GPIO_CTRL_FID_FID7_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_FID_FID7_Msk) >> GPIO_CTRL_FID_FID7_Pos) /*!< FID7 Get Value */

#define GPIO_CTRL_FID_FID6_Pos (6U)                             /*!< FID6 Postion   */
#define GPIO_CTRL_FID_FID6_Msk (0x1U << GPIO_CTRL_FID_FID6_Pos) /*!< FID6 Mask      */
#define GPIO_CTRL_FID_FID6_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_FID_FID6_Pos) & GPIO_CTRL_FID_FID6_Msk) /*!< FID6 Set Value */
#define GPIO_CTRL_FID_FID6_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_FID_FID6_Msk) >> GPIO_CTRL_FID_FID6_Pos) /*!< FID6 Get Value */

#define GPIO_CTRL_FID_FID5_Pos (5U)                             /*!< FID5 Postion   */
#define GPIO_CTRL_FID_FID5_Msk (0x1U << GPIO_CTRL_FID_FID5_Pos) /*!< FID5 Mask      */
#define GPIO_CTRL_FID_FID5_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_FID_FID5_Pos) & GPIO_CTRL_FID_FID5_Msk) /*!< FID5 Set Value */
#define GPIO_CTRL_FID_FID5_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_FID_FID5_Msk) >> GPIO_CTRL_FID_FID5_Pos) /*!< FID5 Get Value */

#define GPIO_CTRL_FID_FID4_Pos (4U)                             /*!< FID4 Postion   */
#define GPIO_CTRL_FID_FID4_Msk (0x1U << GPIO_CTRL_FID_FID4_Pos) /*!< FID4 Mask      */
#define GPIO_CTRL_FID_FID4_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_FID_FID4_Pos) & GPIO_CTRL_FID_FID4_Msk) /*!< FID4 Set Value */
#define GPIO_CTRL_FID_FID4_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_FID_FID4_Msk) >> GPIO_CTRL_FID_FID4_Pos) /*!< FID4 Get Value */

#define GPIO_CTRL_FID_FID3_Pos (3U)                             /*!< FID3 Postion   */
#define GPIO_CTRL_FID_FID3_Msk (0x1U << GPIO_CTRL_FID_FID3_Pos) /*!< FID3 Mask      */
#define GPIO_CTRL_FID_FID3_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_FID_FID3_Pos) & GPIO_CTRL_FID_FID3_Msk) /*!< FID3 Set Value */
#define GPIO_CTRL_FID_FID3_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_FID_FID3_Msk) >> GPIO_CTRL_FID_FID3_Pos) /*!< FID3 Get Value */

#define GPIO_CTRL_FID_FID2_Pos (2U)                             /*!< FID2 Postion   */
#define GPIO_CTRL_FID_FID2_Msk (0x1U << GPIO_CTRL_FID_FID2_Pos) /*!< FID2 Mask      */
#define GPIO_CTRL_FID_FID2_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_FID_FID2_Pos) & GPIO_CTRL_FID_FID2_Msk) /*!< FID2 Set Value */
#define GPIO_CTRL_FID_FID2_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_FID_FID2_Msk) >> GPIO_CTRL_FID_FID2_Pos) /*!< FID2 Get Value */

#define GPIO_CTRL_FID_FID1_Pos (1U)                             /*!< FID1 Postion   */
#define GPIO_CTRL_FID_FID1_Msk (0x1U << GPIO_CTRL_FID_FID1_Pos) /*!< FID1 Mask      */
#define GPIO_CTRL_FID_FID1_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_FID_FID1_Pos) & GPIO_CTRL_FID_FID1_Msk) /*!< FID1 Set Value */
#define GPIO_CTRL_FID_FID1_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_FID_FID1_Msk) >> GPIO_CTRL_FID_FID1_Pos) /*!< FID1 Get Value */

#define GPIO_CTRL_FID_FID0_Pos (0U)                             /*!< FID0 Postion   */
#define GPIO_CTRL_FID_FID0_Msk (0x1U << GPIO_CTRL_FID_FID0_Pos) /*!< FID0 Mask      */
#define GPIO_CTRL_FID_FID0_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_FID_FID0_Pos) & GPIO_CTRL_FID_FID0_Msk) /*!< FID0 Set Value */
#define GPIO_CTRL_FID_FID0_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_FID_FID0_Msk) >> GPIO_CTRL_FID_FID0_Pos) /*!< FID0 Get Value */

/* ST bitfield */
#define GPIO_CTRL_ST_ST31_Pos (31U)                           /*!< ST31 Postion   */
#define GPIO_CTRL_ST_ST31_Msk (0x1U << GPIO_CTRL_ST_ST31_Pos) /*!< ST31 Mask      */
#define GPIO_CTRL_ST_ST31_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_ST_ST31_Pos) & GPIO_CTRL_ST_ST31_Msk) /*!< ST31 Set Value */
#define GPIO_CTRL_ST_ST31_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_ST_ST31_Msk) >> GPIO_CTRL_ST_ST31_Pos) /*!< ST31 Get Value */

#define GPIO_CTRL_ST_ST30_Pos (30U)                           /*!< ST30 Postion   */
#define GPIO_CTRL_ST_ST30_Msk (0x1U << GPIO_CTRL_ST_ST30_Pos) /*!< ST30 Mask      */
#define GPIO_CTRL_ST_ST30_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_ST_ST30_Pos) & GPIO_CTRL_ST_ST30_Msk) /*!< ST30 Set Value */
#define GPIO_CTRL_ST_ST30_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_ST_ST30_Msk) >> GPIO_CTRL_ST_ST30_Pos) /*!< ST30 Get Value */

#define GPIO_CTRL_ST_ST29_Pos (29U)                           /*!< ST29 Postion   */
#define GPIO_CTRL_ST_ST29_Msk (0x1U << GPIO_CTRL_ST_ST29_Pos) /*!< ST29 Mask      */
#define GPIO_CTRL_ST_ST29_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_ST_ST29_Pos) & GPIO_CTRL_ST_ST29_Msk) /*!< ST29 Set Value */
#define GPIO_CTRL_ST_ST29_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_ST_ST29_Msk) >> GPIO_CTRL_ST_ST29_Pos) /*!< ST29 Get Value */

#define GPIO_CTRL_ST_ST28_Pos (28U)                           /*!< ST28 Postion   */
#define GPIO_CTRL_ST_ST28_Msk (0x1U << GPIO_CTRL_ST_ST28_Pos) /*!< ST28 Mask      */
#define GPIO_CTRL_ST_ST28_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_ST_ST28_Pos) & GPIO_CTRL_ST_ST28_Msk) /*!< ST28 Set Value */
#define GPIO_CTRL_ST_ST28_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_ST_ST28_Msk) >> GPIO_CTRL_ST_ST28_Pos) /*!< ST28 Get Value */

#define GPIO_CTRL_ST_ST27_Pos (27U)                           /*!< ST27 Postion   */
#define GPIO_CTRL_ST_ST27_Msk (0x1U << GPIO_CTRL_ST_ST27_Pos) /*!< ST27 Mask      */
#define GPIO_CTRL_ST_ST27_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_ST_ST27_Pos) & GPIO_CTRL_ST_ST27_Msk) /*!< ST27 Set Value */
#define GPIO_CTRL_ST_ST27_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_ST_ST27_Msk) >> GPIO_CTRL_ST_ST27_Pos) /*!< ST27 Get Value */

#define GPIO_CTRL_ST_ST26_Pos (26U)                           /*!< ST26 Postion   */
#define GPIO_CTRL_ST_ST26_Msk (0x1U << GPIO_CTRL_ST_ST26_Pos) /*!< ST26 Mask      */
#define GPIO_CTRL_ST_ST26_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_ST_ST26_Pos) & GPIO_CTRL_ST_ST26_Msk) /*!< ST26 Set Value */
#define GPIO_CTRL_ST_ST26_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_ST_ST26_Msk) >> GPIO_CTRL_ST_ST26_Pos) /*!< ST26 Get Value */

#define GPIO_CTRL_ST_ST25_Pos (25U)                           /*!< ST25 Postion   */
#define GPIO_CTRL_ST_ST25_Msk (0x1U << GPIO_CTRL_ST_ST25_Pos) /*!< ST25 Mask      */
#define GPIO_CTRL_ST_ST25_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_ST_ST25_Pos) & GPIO_CTRL_ST_ST25_Msk) /*!< ST25 Set Value */
#define GPIO_CTRL_ST_ST25_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_ST_ST25_Msk) >> GPIO_CTRL_ST_ST25_Pos) /*!< ST25 Get Value */

#define GPIO_CTRL_ST_ST24_Pos (24U)                           /*!< ST24 Postion   */
#define GPIO_CTRL_ST_ST24_Msk (0x1U << GPIO_CTRL_ST_ST24_Pos) /*!< ST24 Mask      */
#define GPIO_CTRL_ST_ST24_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_ST_ST24_Pos) & GPIO_CTRL_ST_ST24_Msk) /*!< ST24 Set Value */
#define GPIO_CTRL_ST_ST24_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_ST_ST24_Msk) >> GPIO_CTRL_ST_ST24_Pos) /*!< ST24 Get Value */

#define GPIO_CTRL_ST_ST23_Pos (23U)                           /*!< ST23 Postion   */
#define GPIO_CTRL_ST_ST23_Msk (0x1U << GPIO_CTRL_ST_ST23_Pos) /*!< ST23 Mask      */
#define GPIO_CTRL_ST_ST23_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_ST_ST23_Pos) & GPIO_CTRL_ST_ST23_Msk) /*!< ST23 Set Value */
#define GPIO_CTRL_ST_ST23_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_ST_ST23_Msk) >> GPIO_CTRL_ST_ST23_Pos) /*!< ST23 Get Value */

#define GPIO_CTRL_ST_ST22_Pos (22U)                           /*!< ST22 Postion   */
#define GPIO_CTRL_ST_ST22_Msk (0x1U << GPIO_CTRL_ST_ST22_Pos) /*!< ST22 Mask      */
#define GPIO_CTRL_ST_ST22_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_ST_ST22_Pos) & GPIO_CTRL_ST_ST22_Msk) /*!< ST22 Set Value */
#define GPIO_CTRL_ST_ST22_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_ST_ST22_Msk) >> GPIO_CTRL_ST_ST22_Pos) /*!< ST22 Get Value */

#define GPIO_CTRL_ST_ST21_Pos (21U)                           /*!< ST21 Postion   */
#define GPIO_CTRL_ST_ST21_Msk (0x1U << GPIO_CTRL_ST_ST21_Pos) /*!< ST21 Mask      */
#define GPIO_CTRL_ST_ST21_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_ST_ST21_Pos) & GPIO_CTRL_ST_ST21_Msk) /*!< ST21 Set Value */
#define GPIO_CTRL_ST_ST21_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_ST_ST21_Msk) >> GPIO_CTRL_ST_ST21_Pos) /*!< ST21 Get Value */

#define GPIO_CTRL_ST_ST20_Pos (20U)                           /*!< ST20 Postion   */
#define GPIO_CTRL_ST_ST20_Msk (0x1U << GPIO_CTRL_ST_ST20_Pos) /*!< ST20 Mask      */
#define GPIO_CTRL_ST_ST20_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_ST_ST20_Pos) & GPIO_CTRL_ST_ST20_Msk) /*!< ST20 Set Value */
#define GPIO_CTRL_ST_ST20_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_ST_ST20_Msk) >> GPIO_CTRL_ST_ST20_Pos) /*!< ST20 Get Value */

#define GPIO_CTRL_ST_ST19_Pos (19U)                           /*!< ST19 Postion   */
#define GPIO_CTRL_ST_ST19_Msk (0x1U << GPIO_CTRL_ST_ST19_Pos) /*!< ST19 Mask      */
#define GPIO_CTRL_ST_ST19_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_ST_ST19_Pos) & GPIO_CTRL_ST_ST19_Msk) /*!< ST19 Set Value */
#define GPIO_CTRL_ST_ST19_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_ST_ST19_Msk) >> GPIO_CTRL_ST_ST19_Pos) /*!< ST19 Get Value */

#define GPIO_CTRL_ST_ST18_Pos (18U)                           /*!< ST18 Postion   */
#define GPIO_CTRL_ST_ST18_Msk (0x1U << GPIO_CTRL_ST_ST18_Pos) /*!< ST18 Mask      */
#define GPIO_CTRL_ST_ST18_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_ST_ST18_Pos) & GPIO_CTRL_ST_ST18_Msk) /*!< ST18 Set Value */
#define GPIO_CTRL_ST_ST18_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_ST_ST18_Msk) >> GPIO_CTRL_ST_ST18_Pos) /*!< ST18 Get Value */

#define GPIO_CTRL_ST_ST17_Pos (17U)                           /*!< ST17 Postion   */
#define GPIO_CTRL_ST_ST17_Msk (0x1U << GPIO_CTRL_ST_ST17_Pos) /*!< ST17 Mask      */
#define GPIO_CTRL_ST_ST17_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_ST_ST17_Pos) & GPIO_CTRL_ST_ST17_Msk) /*!< ST17 Set Value */
#define GPIO_CTRL_ST_ST17_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_ST_ST17_Msk) >> GPIO_CTRL_ST_ST17_Pos) /*!< ST17 Get Value */

#define GPIO_CTRL_ST_ST16_Pos (16U)                           /*!< ST16 Postion   */
#define GPIO_CTRL_ST_ST16_Msk (0x1U << GPIO_CTRL_ST_ST16_Pos) /*!< ST16 Mask      */
#define GPIO_CTRL_ST_ST16_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_ST_ST16_Pos) & GPIO_CTRL_ST_ST16_Msk) /*!< ST16 Set Value */
#define GPIO_CTRL_ST_ST16_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_ST_ST16_Msk) >> GPIO_CTRL_ST_ST16_Pos) /*!< ST16 Get Value */

#define GPIO_CTRL_ST_ST15_Pos (15U)                           /*!< ST15 Postion   */
#define GPIO_CTRL_ST_ST15_Msk (0x1U << GPIO_CTRL_ST_ST15_Pos) /*!< ST15 Mask      */
#define GPIO_CTRL_ST_ST15_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_ST_ST15_Pos) & GPIO_CTRL_ST_ST15_Msk) /*!< ST15 Set Value */
#define GPIO_CTRL_ST_ST15_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_ST_ST15_Msk) >> GPIO_CTRL_ST_ST15_Pos) /*!< ST15 Get Value */

#define GPIO_CTRL_ST_ST14_Pos (14U)                           /*!< ST14 Postion   */
#define GPIO_CTRL_ST_ST14_Msk (0x1U << GPIO_CTRL_ST_ST14_Pos) /*!< ST14 Mask      */
#define GPIO_CTRL_ST_ST14_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_ST_ST14_Pos) & GPIO_CTRL_ST_ST14_Msk) /*!< ST14 Set Value */
#define GPIO_CTRL_ST_ST14_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_ST_ST14_Msk) >> GPIO_CTRL_ST_ST14_Pos) /*!< ST14 Get Value */

#define GPIO_CTRL_ST_ST13_Pos (13U)                           /*!< ST13 Postion   */
#define GPIO_CTRL_ST_ST13_Msk (0x1U << GPIO_CTRL_ST_ST13_Pos) /*!< ST13 Mask      */
#define GPIO_CTRL_ST_ST13_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_ST_ST13_Pos) & GPIO_CTRL_ST_ST13_Msk) /*!< ST13 Set Value */
#define GPIO_CTRL_ST_ST13_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_ST_ST13_Msk) >> GPIO_CTRL_ST_ST13_Pos) /*!< ST13 Get Value */

#define GPIO_CTRL_ST_ST12_Pos (12U)                           /*!< ST12 Postion   */
#define GPIO_CTRL_ST_ST12_Msk (0x1U << GPIO_CTRL_ST_ST12_Pos) /*!< ST12 Mask      */
#define GPIO_CTRL_ST_ST12_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_ST_ST12_Pos) & GPIO_CTRL_ST_ST12_Msk) /*!< ST12 Set Value */
#define GPIO_CTRL_ST_ST12_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_ST_ST12_Msk) >> GPIO_CTRL_ST_ST12_Pos) /*!< ST12 Get Value */

#define GPIO_CTRL_ST_ST11_Pos (11U)                           /*!< ST11 Postion   */
#define GPIO_CTRL_ST_ST11_Msk (0x1U << GPIO_CTRL_ST_ST11_Pos) /*!< ST11 Mask      */
#define GPIO_CTRL_ST_ST11_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_ST_ST11_Pos) & GPIO_CTRL_ST_ST11_Msk) /*!< ST11 Set Value */
#define GPIO_CTRL_ST_ST11_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_ST_ST11_Msk) >> GPIO_CTRL_ST_ST11_Pos) /*!< ST11 Get Value */

#define GPIO_CTRL_ST_ST10_Pos (10U)                           /*!< ST10 Postion   */
#define GPIO_CTRL_ST_ST10_Msk (0x1U << GPIO_CTRL_ST_ST10_Pos) /*!< ST10 Mask      */
#define GPIO_CTRL_ST_ST10_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_ST_ST10_Pos) & GPIO_CTRL_ST_ST10_Msk) /*!< ST10 Set Value */
#define GPIO_CTRL_ST_ST10_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_ST_ST10_Msk) >> GPIO_CTRL_ST_ST10_Pos) /*!< ST10 Get Value */

#define GPIO_CTRL_ST_ST9_Pos (9U)                           /*!< ST9 Postion   */
#define GPIO_CTRL_ST_ST9_Msk (0x1U << GPIO_CTRL_ST_ST9_Pos) /*!< ST9 Mask      */
#define GPIO_CTRL_ST_ST9_Set(x)                                                                                     \
    (((uint32_t) (x) << GPIO_CTRL_ST_ST9_Pos) & GPIO_CTRL_ST_ST9_Msk)                            /*!< ST9 Set Value \
                                                                                                  */
#define GPIO_CTRL_ST_ST9_Get(x) (((uint32_t) (x) &GPIO_CTRL_ST_ST9_Msk) >> GPIO_CTRL_ST_ST9_Pos) /*!< ST9 Get Value */

#define GPIO_CTRL_ST_ST8_Pos (8U)                           /*!< ST8 Postion   */
#define GPIO_CTRL_ST_ST8_Msk (0x1U << GPIO_CTRL_ST_ST8_Pos) /*!< ST8 Mask      */
#define GPIO_CTRL_ST_ST8_Set(x)                                                                                     \
    (((uint32_t) (x) << GPIO_CTRL_ST_ST8_Pos) & GPIO_CTRL_ST_ST8_Msk)                            /*!< ST8 Set Value \
                                                                                                  */
#define GPIO_CTRL_ST_ST8_Get(x) (((uint32_t) (x) &GPIO_CTRL_ST_ST8_Msk) >> GPIO_CTRL_ST_ST8_Pos) /*!< ST8 Get Value */

#define GPIO_CTRL_ST_ST7_Pos (7U)                           /*!< ST7 Postion   */
#define GPIO_CTRL_ST_ST7_Msk (0x1U << GPIO_CTRL_ST_ST7_Pos) /*!< ST7 Mask      */
#define GPIO_CTRL_ST_ST7_Set(x)                                                                                     \
    (((uint32_t) (x) << GPIO_CTRL_ST_ST7_Pos) & GPIO_CTRL_ST_ST7_Msk)                            /*!< ST7 Set Value \
                                                                                                  */
#define GPIO_CTRL_ST_ST7_Get(x) (((uint32_t) (x) &GPIO_CTRL_ST_ST7_Msk) >> GPIO_CTRL_ST_ST7_Pos) /*!< ST7 Get Value */

#define GPIO_CTRL_ST_ST6_Pos (6U)                           /*!< ST6 Postion   */
#define GPIO_CTRL_ST_ST6_Msk (0x1U << GPIO_CTRL_ST_ST6_Pos) /*!< ST6 Mask      */
#define GPIO_CTRL_ST_ST6_Set(x)                                                                                     \
    (((uint32_t) (x) << GPIO_CTRL_ST_ST6_Pos) & GPIO_CTRL_ST_ST6_Msk)                            /*!< ST6 Set Value \
                                                                                                  */
#define GPIO_CTRL_ST_ST6_Get(x) (((uint32_t) (x) &GPIO_CTRL_ST_ST6_Msk) >> GPIO_CTRL_ST_ST6_Pos) /*!< ST6 Get Value */

#define GPIO_CTRL_ST_ST5_Pos (5U)                           /*!< ST5 Postion   */
#define GPIO_CTRL_ST_ST5_Msk (0x1U << GPIO_CTRL_ST_ST5_Pos) /*!< ST5 Mask      */
#define GPIO_CTRL_ST_ST5_Set(x)                                                                                     \
    (((uint32_t) (x) << GPIO_CTRL_ST_ST5_Pos) & GPIO_CTRL_ST_ST5_Msk)                            /*!< ST5 Set Value \
                                                                                                  */
#define GPIO_CTRL_ST_ST5_Get(x) (((uint32_t) (x) &GPIO_CTRL_ST_ST5_Msk) >> GPIO_CTRL_ST_ST5_Pos) /*!< ST5 Get Value */

#define GPIO_CTRL_ST_ST4_Pos (4U)                           /*!< ST4 Postion   */
#define GPIO_CTRL_ST_ST4_Msk (0x1U << GPIO_CTRL_ST_ST4_Pos) /*!< ST4 Mask      */
#define GPIO_CTRL_ST_ST4_Set(x)                                                                                     \
    (((uint32_t) (x) << GPIO_CTRL_ST_ST4_Pos) & GPIO_CTRL_ST_ST4_Msk)                            /*!< ST4 Set Value \
                                                                                                  */
#define GPIO_CTRL_ST_ST4_Get(x) (((uint32_t) (x) &GPIO_CTRL_ST_ST4_Msk) >> GPIO_CTRL_ST_ST4_Pos) /*!< ST4 Get Value */

#define GPIO_CTRL_ST_ST3_Pos (3U)                           /*!< ST3 Postion   */
#define GPIO_CTRL_ST_ST3_Msk (0x1U << GPIO_CTRL_ST_ST3_Pos) /*!< ST3 Mask      */
#define GPIO_CTRL_ST_ST3_Set(x)                                                                                     \
    (((uint32_t) (x) << GPIO_CTRL_ST_ST3_Pos) & GPIO_CTRL_ST_ST3_Msk)                            /*!< ST3 Set Value \
                                                                                                  */
#define GPIO_CTRL_ST_ST3_Get(x) (((uint32_t) (x) &GPIO_CTRL_ST_ST3_Msk) >> GPIO_CTRL_ST_ST3_Pos) /*!< ST3 Get Value */

#define GPIO_CTRL_ST_ST2_Pos (2U)                           /*!< ST2 Postion   */
#define GPIO_CTRL_ST_ST2_Msk (0x1U << GPIO_CTRL_ST_ST2_Pos) /*!< ST2 Mask      */
#define GPIO_CTRL_ST_ST2_Set(x)                                                                                     \
    (((uint32_t) (x) << GPIO_CTRL_ST_ST2_Pos) & GPIO_CTRL_ST_ST2_Msk)                            /*!< ST2 Set Value \
                                                                                                  */
#define GPIO_CTRL_ST_ST2_Get(x) (((uint32_t) (x) &GPIO_CTRL_ST_ST2_Msk) >> GPIO_CTRL_ST_ST2_Pos) /*!< ST2 Get Value */

#define GPIO_CTRL_ST_ST1_Pos (1U)                           /*!< ST1 Postion   */
#define GPIO_CTRL_ST_ST1_Msk (0x1U << GPIO_CTRL_ST_ST1_Pos) /*!< ST1 Mask      */
#define GPIO_CTRL_ST_ST1_Set(x)                                                                                     \
    (((uint32_t) (x) << GPIO_CTRL_ST_ST1_Pos) & GPIO_CTRL_ST_ST1_Msk)                            /*!< ST1 Set Value \
                                                                                                  */
#define GPIO_CTRL_ST_ST1_Get(x) (((uint32_t) (x) &GPIO_CTRL_ST_ST1_Msk) >> GPIO_CTRL_ST_ST1_Pos) /*!< ST1 Get Value */

#define GPIO_CTRL_ST_ST0_Pos (0U)                           /*!< ST0 Postion   */
#define GPIO_CTRL_ST_ST0_Msk (0x1U << GPIO_CTRL_ST_ST0_Pos) /*!< ST0 Mask      */
#define GPIO_CTRL_ST_ST0_Set(x)                                                                                     \
    (((uint32_t) (x) << GPIO_CTRL_ST_ST0_Pos) & GPIO_CTRL_ST_ST0_Msk)                            /*!< ST0 Set Value \
                                                                                                  */
#define GPIO_CTRL_ST_ST0_Get(x) (((uint32_t) (x) &GPIO_CTRL_ST_ST0_Msk) >> GPIO_CTRL_ST_ST0_Pos) /*!< ST0 Get Value */

/* LPB bitfield */
#define GPIO_CTRL_LPB_LPB31_Pos (31U)                             /*!< LPB31 Postion   */
#define GPIO_CTRL_LPB_LPB31_Msk (0x1U << GPIO_CTRL_LPB_LPB31_Pos) /*!< LPB31 Mask      */
#define GPIO_CTRL_LPB_LPB31_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LPB_LPB31_Pos) & GPIO_CTRL_LPB_LPB31_Msk) /*!< LPB31 Set Value */
#define GPIO_CTRL_LPB_LPB31_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LPB_LPB31_Msk) >> GPIO_CTRL_LPB_LPB31_Pos) /*!< LPB31 Get Value */

#define GPIO_CTRL_LPB_LPB30_Pos (30U)                             /*!< LPB30 Postion   */
#define GPIO_CTRL_LPB_LPB30_Msk (0x1U << GPIO_CTRL_LPB_LPB30_Pos) /*!< LPB30 Mask      */
#define GPIO_CTRL_LPB_LPB30_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LPB_LPB30_Pos) & GPIO_CTRL_LPB_LPB30_Msk) /*!< LPB30 Set Value */
#define GPIO_CTRL_LPB_LPB30_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LPB_LPB30_Msk) >> GPIO_CTRL_LPB_LPB30_Pos) /*!< LPB30 Get Value */

#define GPIO_CTRL_LPB_LPB29_Pos (29U)                             /*!< LPB29 Postion   */
#define GPIO_CTRL_LPB_LPB29_Msk (0x1U << GPIO_CTRL_LPB_LPB29_Pos) /*!< LPB29 Mask      */
#define GPIO_CTRL_LPB_LPB29_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LPB_LPB29_Pos) & GPIO_CTRL_LPB_LPB29_Msk) /*!< LPB29 Set Value */
#define GPIO_CTRL_LPB_LPB29_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LPB_LPB29_Msk) >> GPIO_CTRL_LPB_LPB29_Pos) /*!< LPB29 Get Value */

#define GPIO_CTRL_LPB_LPB28_Pos (28U)                             /*!< LPB28 Postion   */
#define GPIO_CTRL_LPB_LPB28_Msk (0x1U << GPIO_CTRL_LPB_LPB28_Pos) /*!< LPB28 Mask      */
#define GPIO_CTRL_LPB_LPB28_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LPB_LPB28_Pos) & GPIO_CTRL_LPB_LPB28_Msk) /*!< LPB28 Set Value */
#define GPIO_CTRL_LPB_LPB28_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LPB_LPB28_Msk) >> GPIO_CTRL_LPB_LPB28_Pos) /*!< LPB28 Get Value */

#define GPIO_CTRL_LPB_LPB27_Pos (27U)                             /*!< LPB27 Postion   */
#define GPIO_CTRL_LPB_LPB27_Msk (0x1U << GPIO_CTRL_LPB_LPB27_Pos) /*!< LPB27 Mask      */
#define GPIO_CTRL_LPB_LPB27_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LPB_LPB27_Pos) & GPIO_CTRL_LPB_LPB27_Msk) /*!< LPB27 Set Value */
#define GPIO_CTRL_LPB_LPB27_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LPB_LPB27_Msk) >> GPIO_CTRL_LPB_LPB27_Pos) /*!< LPB27 Get Value */

#define GPIO_CTRL_LPB_LPB26_Pos (26U)                             /*!< LPB26 Postion   */
#define GPIO_CTRL_LPB_LPB26_Msk (0x1U << GPIO_CTRL_LPB_LPB26_Pos) /*!< LPB26 Mask      */
#define GPIO_CTRL_LPB_LPB26_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LPB_LPB26_Pos) & GPIO_CTRL_LPB_LPB26_Msk) /*!< LPB26 Set Value */
#define GPIO_CTRL_LPB_LPB26_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LPB_LPB26_Msk) >> GPIO_CTRL_LPB_LPB26_Pos) /*!< LPB26 Get Value */

#define GPIO_CTRL_LPB_LPB25_Pos (25U)                             /*!< LPB25 Postion   */
#define GPIO_CTRL_LPB_LPB25_Msk (0x1U << GPIO_CTRL_LPB_LPB25_Pos) /*!< LPB25 Mask      */
#define GPIO_CTRL_LPB_LPB25_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LPB_LPB25_Pos) & GPIO_CTRL_LPB_LPB25_Msk) /*!< LPB25 Set Value */
#define GPIO_CTRL_LPB_LPB25_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LPB_LPB25_Msk) >> GPIO_CTRL_LPB_LPB25_Pos) /*!< LPB25 Get Value */

#define GPIO_CTRL_LPB_LPB24_Pos (24U)                             /*!< LPB24 Postion   */
#define GPIO_CTRL_LPB_LPB24_Msk (0x1U << GPIO_CTRL_LPB_LPB24_Pos) /*!< LPB24 Mask      */
#define GPIO_CTRL_LPB_LPB24_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LPB_LPB24_Pos) & GPIO_CTRL_LPB_LPB24_Msk) /*!< LPB24 Set Value */
#define GPIO_CTRL_LPB_LPB24_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LPB_LPB24_Msk) >> GPIO_CTRL_LPB_LPB24_Pos) /*!< LPB24 Get Value */

#define GPIO_CTRL_LPB_LPB23_Pos (23U)                             /*!< LPB23 Postion   */
#define GPIO_CTRL_LPB_LPB23_Msk (0x1U << GPIO_CTRL_LPB_LPB23_Pos) /*!< LPB23 Mask      */
#define GPIO_CTRL_LPB_LPB23_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LPB_LPB23_Pos) & GPIO_CTRL_LPB_LPB23_Msk) /*!< LPB23 Set Value */
#define GPIO_CTRL_LPB_LPB23_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LPB_LPB23_Msk) >> GPIO_CTRL_LPB_LPB23_Pos) /*!< LPB23 Get Value */

#define GPIO_CTRL_LPB_LPB22_Pos (22U)                             /*!< LPB22 Postion   */
#define GPIO_CTRL_LPB_LPB22_Msk (0x1U << GPIO_CTRL_LPB_LPB22_Pos) /*!< LPB22 Mask      */
#define GPIO_CTRL_LPB_LPB22_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LPB_LPB22_Pos) & GPIO_CTRL_LPB_LPB22_Msk) /*!< LPB22 Set Value */
#define GPIO_CTRL_LPB_LPB22_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LPB_LPB22_Msk) >> GPIO_CTRL_LPB_LPB22_Pos) /*!< LPB22 Get Value */

#define GPIO_CTRL_LPB_LPB21_Pos (21U)                             /*!< LPB21 Postion   */
#define GPIO_CTRL_LPB_LPB21_Msk (0x1U << GPIO_CTRL_LPB_LPB21_Pos) /*!< LPB21 Mask      */
#define GPIO_CTRL_LPB_LPB21_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LPB_LPB21_Pos) & GPIO_CTRL_LPB_LPB21_Msk) /*!< LPB21 Set Value */
#define GPIO_CTRL_LPB_LPB21_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LPB_LPB21_Msk) >> GPIO_CTRL_LPB_LPB21_Pos) /*!< LPB21 Get Value */

#define GPIO_CTRL_LPB_LPB20_Pos (20U)                             /*!< LPB20 Postion   */
#define GPIO_CTRL_LPB_LPB20_Msk (0x1U << GPIO_CTRL_LPB_LPB20_Pos) /*!< LPB20 Mask      */
#define GPIO_CTRL_LPB_LPB20_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LPB_LPB20_Pos) & GPIO_CTRL_LPB_LPB20_Msk) /*!< LPB20 Set Value */
#define GPIO_CTRL_LPB_LPB20_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LPB_LPB20_Msk) >> GPIO_CTRL_LPB_LPB20_Pos) /*!< LPB20 Get Value */

#define GPIO_CTRL_LPB_LPB19_Pos (19U)                             /*!< LPB19 Postion   */
#define GPIO_CTRL_LPB_LPB19_Msk (0x1U << GPIO_CTRL_LPB_LPB19_Pos) /*!< LPB19 Mask      */
#define GPIO_CTRL_LPB_LPB19_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LPB_LPB19_Pos) & GPIO_CTRL_LPB_LPB19_Msk) /*!< LPB19 Set Value */
#define GPIO_CTRL_LPB_LPB19_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LPB_LPB19_Msk) >> GPIO_CTRL_LPB_LPB19_Pos) /*!< LPB19 Get Value */

#define GPIO_CTRL_LPB_LPB18_Pos (18U)                             /*!< LPB18 Postion   */
#define GPIO_CTRL_LPB_LPB18_Msk (0x1U << GPIO_CTRL_LPB_LPB18_Pos) /*!< LPB18 Mask      */
#define GPIO_CTRL_LPB_LPB18_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LPB_LPB18_Pos) & GPIO_CTRL_LPB_LPB18_Msk) /*!< LPB18 Set Value */
#define GPIO_CTRL_LPB_LPB18_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LPB_LPB18_Msk) >> GPIO_CTRL_LPB_LPB18_Pos) /*!< LPB18 Get Value */

#define GPIO_CTRL_LPB_LPB17_Pos (17U)                             /*!< LPB17 Postion   */
#define GPIO_CTRL_LPB_LPB17_Msk (0x1U << GPIO_CTRL_LPB_LPB17_Pos) /*!< LPB17 Mask      */
#define GPIO_CTRL_LPB_LPB17_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LPB_LPB17_Pos) & GPIO_CTRL_LPB_LPB17_Msk) /*!< LPB17 Set Value */
#define GPIO_CTRL_LPB_LPB17_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LPB_LPB17_Msk) >> GPIO_CTRL_LPB_LPB17_Pos) /*!< LPB17 Get Value */

#define GPIO_CTRL_LPB_LPB16_Pos (16U)                             /*!< LPB16 Postion   */
#define GPIO_CTRL_LPB_LPB16_Msk (0x1U << GPIO_CTRL_LPB_LPB16_Pos) /*!< LPB16 Mask      */
#define GPIO_CTRL_LPB_LPB16_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LPB_LPB16_Pos) & GPIO_CTRL_LPB_LPB16_Msk) /*!< LPB16 Set Value */
#define GPIO_CTRL_LPB_LPB16_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LPB_LPB16_Msk) >> GPIO_CTRL_LPB_LPB16_Pos) /*!< LPB16 Get Value */

#define GPIO_CTRL_LPB_LPB15_Pos (15U)                             /*!< LPB15 Postion   */
#define GPIO_CTRL_LPB_LPB15_Msk (0x1U << GPIO_CTRL_LPB_LPB15_Pos) /*!< LPB15 Mask      */
#define GPIO_CTRL_LPB_LPB15_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LPB_LPB15_Pos) & GPIO_CTRL_LPB_LPB15_Msk) /*!< LPB15 Set Value */
#define GPIO_CTRL_LPB_LPB15_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LPB_LPB15_Msk) >> GPIO_CTRL_LPB_LPB15_Pos) /*!< LPB15 Get Value */

#define GPIO_CTRL_LPB_LPB14_Pos (14U)                             /*!< LPB14 Postion   */
#define GPIO_CTRL_LPB_LPB14_Msk (0x1U << GPIO_CTRL_LPB_LPB14_Pos) /*!< LPB14 Mask      */
#define GPIO_CTRL_LPB_LPB14_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LPB_LPB14_Pos) & GPIO_CTRL_LPB_LPB14_Msk) /*!< LPB14 Set Value */
#define GPIO_CTRL_LPB_LPB14_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LPB_LPB14_Msk) >> GPIO_CTRL_LPB_LPB14_Pos) /*!< LPB14 Get Value */

#define GPIO_CTRL_LPB_LPB13_Pos (13U)                             /*!< LPB13 Postion   */
#define GPIO_CTRL_LPB_LPB13_Msk (0x1U << GPIO_CTRL_LPB_LPB13_Pos) /*!< LPB13 Mask      */
#define GPIO_CTRL_LPB_LPB13_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LPB_LPB13_Pos) & GPIO_CTRL_LPB_LPB13_Msk) /*!< LPB13 Set Value */
#define GPIO_CTRL_LPB_LPB13_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LPB_LPB13_Msk) >> GPIO_CTRL_LPB_LPB13_Pos) /*!< LPB13 Get Value */

#define GPIO_CTRL_LPB_LPB12_Pos (12U)                             /*!< LPB12 Postion   */
#define GPIO_CTRL_LPB_LPB12_Msk (0x1U << GPIO_CTRL_LPB_LPB12_Pos) /*!< LPB12 Mask      */
#define GPIO_CTRL_LPB_LPB12_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LPB_LPB12_Pos) & GPIO_CTRL_LPB_LPB12_Msk) /*!< LPB12 Set Value */
#define GPIO_CTRL_LPB_LPB12_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LPB_LPB12_Msk) >> GPIO_CTRL_LPB_LPB12_Pos) /*!< LPB12 Get Value */

#define GPIO_CTRL_LPB_LPB11_Pos (11U)                             /*!< LPB11 Postion   */
#define GPIO_CTRL_LPB_LPB11_Msk (0x1U << GPIO_CTRL_LPB_LPB11_Pos) /*!< LPB11 Mask      */
#define GPIO_CTRL_LPB_LPB11_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LPB_LPB11_Pos) & GPIO_CTRL_LPB_LPB11_Msk) /*!< LPB11 Set Value */
#define GPIO_CTRL_LPB_LPB11_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LPB_LPB11_Msk) >> GPIO_CTRL_LPB_LPB11_Pos) /*!< LPB11 Get Value */

#define GPIO_CTRL_LPB_LPB10_Pos (10U)                             /*!< LPB10 Postion   */
#define GPIO_CTRL_LPB_LPB10_Msk (0x1U << GPIO_CTRL_LPB_LPB10_Pos) /*!< LPB10 Mask      */
#define GPIO_CTRL_LPB_LPB10_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LPB_LPB10_Pos) & GPIO_CTRL_LPB_LPB10_Msk) /*!< LPB10 Set Value */
#define GPIO_CTRL_LPB_LPB10_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LPB_LPB10_Msk) >> GPIO_CTRL_LPB_LPB10_Pos) /*!< LPB10 Get Value */

#define GPIO_CTRL_LPB_LPB9_Pos (9U)                             /*!< LPB9 Postion   */
#define GPIO_CTRL_LPB_LPB9_Msk (0x1U << GPIO_CTRL_LPB_LPB9_Pos) /*!< LPB9 Mask      */
#define GPIO_CTRL_LPB_LPB9_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LPB_LPB9_Pos) & GPIO_CTRL_LPB_LPB9_Msk) /*!< LPB9 Set Value */
#define GPIO_CTRL_LPB_LPB9_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LPB_LPB9_Msk) >> GPIO_CTRL_LPB_LPB9_Pos) /*!< LPB9 Get Value */

#define GPIO_CTRL_LPB_LPB8_Pos (8U)                             /*!< LPB8 Postion   */
#define GPIO_CTRL_LPB_LPB8_Msk (0x1U << GPIO_CTRL_LPB_LPB8_Pos) /*!< LPB8 Mask      */
#define GPIO_CTRL_LPB_LPB8_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LPB_LPB8_Pos) & GPIO_CTRL_LPB_LPB8_Msk) /*!< LPB8 Set Value */
#define GPIO_CTRL_LPB_LPB8_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LPB_LPB8_Msk) >> GPIO_CTRL_LPB_LPB8_Pos) /*!< LPB8 Get Value */

#define GPIO_CTRL_LPB_LPB7_Pos (7U)                             /*!< LPB7 Postion   */
#define GPIO_CTRL_LPB_LPB7_Msk (0x1U << GPIO_CTRL_LPB_LPB7_Pos) /*!< LPB7 Mask      */
#define GPIO_CTRL_LPB_LPB7_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LPB_LPB7_Pos) & GPIO_CTRL_LPB_LPB7_Msk) /*!< LPB7 Set Value */
#define GPIO_CTRL_LPB_LPB7_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LPB_LPB7_Msk) >> GPIO_CTRL_LPB_LPB7_Pos) /*!< LPB7 Get Value */

#define GPIO_CTRL_LPB_LPB6_Pos (6U)                             /*!< LPB6 Postion   */
#define GPIO_CTRL_LPB_LPB6_Msk (0x1U << GPIO_CTRL_LPB_LPB6_Pos) /*!< LPB6 Mask      */
#define GPIO_CTRL_LPB_LPB6_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LPB_LPB6_Pos) & GPIO_CTRL_LPB_LPB6_Msk) /*!< LPB6 Set Value */
#define GPIO_CTRL_LPB_LPB6_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LPB_LPB6_Msk) >> GPIO_CTRL_LPB_LPB6_Pos) /*!< LPB6 Get Value */

#define GPIO_CTRL_LPB_LPB5_Pos (5U)                             /*!< LPB5 Postion   */
#define GPIO_CTRL_LPB_LPB5_Msk (0x1U << GPIO_CTRL_LPB_LPB5_Pos) /*!< LPB5 Mask      */
#define GPIO_CTRL_LPB_LPB5_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LPB_LPB5_Pos) & GPIO_CTRL_LPB_LPB5_Msk) /*!< LPB5 Set Value */
#define GPIO_CTRL_LPB_LPB5_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LPB_LPB5_Msk) >> GPIO_CTRL_LPB_LPB5_Pos) /*!< LPB5 Get Value */

#define GPIO_CTRL_LPB_LPB4_Pos (4U)                             /*!< LPB4 Postion   */
#define GPIO_CTRL_LPB_LPB4_Msk (0x1U << GPIO_CTRL_LPB_LPB4_Pos) /*!< LPB4 Mask      */
#define GPIO_CTRL_LPB_LPB4_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LPB_LPB4_Pos) & GPIO_CTRL_LPB_LPB4_Msk) /*!< LPB4 Set Value */
#define GPIO_CTRL_LPB_LPB4_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LPB_LPB4_Msk) >> GPIO_CTRL_LPB_LPB4_Pos) /*!< LPB4 Get Value */

#define GPIO_CTRL_LPB_LPB3_Pos (3U)                             /*!< LPB3 Postion   */
#define GPIO_CTRL_LPB_LPB3_Msk (0x1U << GPIO_CTRL_LPB_LPB3_Pos) /*!< LPB3 Mask      */
#define GPIO_CTRL_LPB_LPB3_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LPB_LPB3_Pos) & GPIO_CTRL_LPB_LPB3_Msk) /*!< LPB3 Set Value */
#define GPIO_CTRL_LPB_LPB3_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LPB_LPB3_Msk) >> GPIO_CTRL_LPB_LPB3_Pos) /*!< LPB3 Get Value */

#define GPIO_CTRL_LPB_LPB2_Pos (2U)                             /*!< LPB2 Postion   */
#define GPIO_CTRL_LPB_LPB2_Msk (0x1U << GPIO_CTRL_LPB_LPB2_Pos) /*!< LPB2 Mask      */
#define GPIO_CTRL_LPB_LPB2_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LPB_LPB2_Pos) & GPIO_CTRL_LPB_LPB2_Msk) /*!< LPB2 Set Value */
#define GPIO_CTRL_LPB_LPB2_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LPB_LPB2_Msk) >> GPIO_CTRL_LPB_LPB2_Pos) /*!< LPB2 Get Value */

#define GPIO_CTRL_LPB_LPB1_Pos (1U)                             /*!< LPB1 Postion   */
#define GPIO_CTRL_LPB_LPB1_Msk (0x1U << GPIO_CTRL_LPB_LPB1_Pos) /*!< LPB1 Mask      */
#define GPIO_CTRL_LPB_LPB1_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LPB_LPB1_Pos) & GPIO_CTRL_LPB_LPB1_Msk) /*!< LPB1 Set Value */
#define GPIO_CTRL_LPB_LPB1_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LPB_LPB1_Msk) >> GPIO_CTRL_LPB_LPB1_Pos) /*!< LPB1 Get Value */

#define GPIO_CTRL_LPB_LPB0_Pos (0U)                             /*!< LPB0 Postion   */
#define GPIO_CTRL_LPB_LPB0_Msk (0x1U << GPIO_CTRL_LPB_LPB0_Pos) /*!< LPB0 Mask      */
#define GPIO_CTRL_LPB_LPB0_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LPB_LPB0_Pos) & GPIO_CTRL_LPB_LPB0_Msk) /*!< LPB0 Set Value */
#define GPIO_CTRL_LPB_LPB0_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LPB_LPB0_Msk) >> GPIO_CTRL_LPB_LPB0_Pos) /*!< LPB0 Get Value */

/* LOCK bitfield */
#define GPIO_CTRL_LOCK_LOCK31_Pos (31U)                               /*!< LOCK31 Postion   */
#define GPIO_CTRL_LOCK_LOCK31_Msk (0x1U << GPIO_CTRL_LOCK_LOCK31_Pos) /*!< LOCK31 Mask      */
#define GPIO_CTRL_LOCK_LOCK31_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LOCK_LOCK31_Pos) & GPIO_CTRL_LOCK_LOCK31_Msk) /*!< LOCK31 Set Value */
#define GPIO_CTRL_LOCK_LOCK31_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LOCK_LOCK31_Msk) >> GPIO_CTRL_LOCK_LOCK31_Pos) /*!< LOCK31 Get Value */

#define GPIO_CTRL_LOCK_LOCK30_Pos (30U)                               /*!< LOCK30 Postion   */
#define GPIO_CTRL_LOCK_LOCK30_Msk (0x1U << GPIO_CTRL_LOCK_LOCK30_Pos) /*!< LOCK30 Mask      */
#define GPIO_CTRL_LOCK_LOCK30_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LOCK_LOCK30_Pos) & GPIO_CTRL_LOCK_LOCK30_Msk) /*!< LOCK30 Set Value */
#define GPIO_CTRL_LOCK_LOCK30_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LOCK_LOCK30_Msk) >> GPIO_CTRL_LOCK_LOCK30_Pos) /*!< LOCK30 Get Value */

#define GPIO_CTRL_LOCK_LOCK29_Pos (29U)                               /*!< LOCK29 Postion   */
#define GPIO_CTRL_LOCK_LOCK29_Msk (0x1U << GPIO_CTRL_LOCK_LOCK29_Pos) /*!< LOCK29 Mask      */
#define GPIO_CTRL_LOCK_LOCK29_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LOCK_LOCK29_Pos) & GPIO_CTRL_LOCK_LOCK29_Msk) /*!< LOCK29 Set Value */
#define GPIO_CTRL_LOCK_LOCK29_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LOCK_LOCK29_Msk) >> GPIO_CTRL_LOCK_LOCK29_Pos) /*!< LOCK29 Get Value */

#define GPIO_CTRL_LOCK_LOCK28_Pos (28U)                               /*!< LOCK28 Postion   */
#define GPIO_CTRL_LOCK_LOCK28_Msk (0x1U << GPIO_CTRL_LOCK_LOCK28_Pos) /*!< LOCK28 Mask      */
#define GPIO_CTRL_LOCK_LOCK28_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LOCK_LOCK28_Pos) & GPIO_CTRL_LOCK_LOCK28_Msk) /*!< LOCK28 Set Value */
#define GPIO_CTRL_LOCK_LOCK28_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LOCK_LOCK28_Msk) >> GPIO_CTRL_LOCK_LOCK28_Pos) /*!< LOCK28 Get Value */

#define GPIO_CTRL_LOCK_LOCK27_Pos (27U)                               /*!< LOCK27 Postion   */
#define GPIO_CTRL_LOCK_LOCK27_Msk (0x1U << GPIO_CTRL_LOCK_LOCK27_Pos) /*!< LOCK27 Mask      */
#define GPIO_CTRL_LOCK_LOCK27_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LOCK_LOCK27_Pos) & GPIO_CTRL_LOCK_LOCK27_Msk) /*!< LOCK27 Set Value */
#define GPIO_CTRL_LOCK_LOCK27_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LOCK_LOCK27_Msk) >> GPIO_CTRL_LOCK_LOCK27_Pos) /*!< LOCK27 Get Value */

#define GPIO_CTRL_LOCK_LOCK26_Pos (26U)                               /*!< LOCK26 Postion   */
#define GPIO_CTRL_LOCK_LOCK26_Msk (0x1U << GPIO_CTRL_LOCK_LOCK26_Pos) /*!< LOCK26 Mask      */
#define GPIO_CTRL_LOCK_LOCK26_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LOCK_LOCK26_Pos) & GPIO_CTRL_LOCK_LOCK26_Msk) /*!< LOCK26 Set Value */
#define GPIO_CTRL_LOCK_LOCK26_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LOCK_LOCK26_Msk) >> GPIO_CTRL_LOCK_LOCK26_Pos) /*!< LOCK26 Get Value */

#define GPIO_CTRL_LOCK_LOCK25_Pos (25U)                               /*!< LOCK25 Postion   */
#define GPIO_CTRL_LOCK_LOCK25_Msk (0x1U << GPIO_CTRL_LOCK_LOCK25_Pos) /*!< LOCK25 Mask      */
#define GPIO_CTRL_LOCK_LOCK25_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LOCK_LOCK25_Pos) & GPIO_CTRL_LOCK_LOCK25_Msk) /*!< LOCK25 Set Value */
#define GPIO_CTRL_LOCK_LOCK25_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LOCK_LOCK25_Msk) >> GPIO_CTRL_LOCK_LOCK25_Pos) /*!< LOCK25 Get Value */

#define GPIO_CTRL_LOCK_LOCK24_Pos (24U)                               /*!< LOCK24 Postion   */
#define GPIO_CTRL_LOCK_LOCK24_Msk (0x1U << GPIO_CTRL_LOCK_LOCK24_Pos) /*!< LOCK24 Mask      */
#define GPIO_CTRL_LOCK_LOCK24_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LOCK_LOCK24_Pos) & GPIO_CTRL_LOCK_LOCK24_Msk) /*!< LOCK24 Set Value */
#define GPIO_CTRL_LOCK_LOCK24_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LOCK_LOCK24_Msk) >> GPIO_CTRL_LOCK_LOCK24_Pos) /*!< LOCK24 Get Value */

#define GPIO_CTRL_LOCK_LOCK23_Pos (23U)                               /*!< LOCK23 Postion   */
#define GPIO_CTRL_LOCK_LOCK23_Msk (0x1U << GPIO_CTRL_LOCK_LOCK23_Pos) /*!< LOCK23 Mask      */
#define GPIO_CTRL_LOCK_LOCK23_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LOCK_LOCK23_Pos) & GPIO_CTRL_LOCK_LOCK23_Msk) /*!< LOCK23 Set Value */
#define GPIO_CTRL_LOCK_LOCK23_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LOCK_LOCK23_Msk) >> GPIO_CTRL_LOCK_LOCK23_Pos) /*!< LOCK23 Get Value */

#define GPIO_CTRL_LOCK_LOCK22_Pos (22U)                               /*!< LOCK22 Postion   */
#define GPIO_CTRL_LOCK_LOCK22_Msk (0x1U << GPIO_CTRL_LOCK_LOCK22_Pos) /*!< LOCK22 Mask      */
#define GPIO_CTRL_LOCK_LOCK22_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LOCK_LOCK22_Pos) & GPIO_CTRL_LOCK_LOCK22_Msk) /*!< LOCK22 Set Value */
#define GPIO_CTRL_LOCK_LOCK22_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LOCK_LOCK22_Msk) >> GPIO_CTRL_LOCK_LOCK22_Pos) /*!< LOCK22 Get Value */

#define GPIO_CTRL_LOCK_LOCK21_Pos (21U)                               /*!< LOCK21 Postion   */
#define GPIO_CTRL_LOCK_LOCK21_Msk (0x1U << GPIO_CTRL_LOCK_LOCK21_Pos) /*!< LOCK21 Mask      */
#define GPIO_CTRL_LOCK_LOCK21_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LOCK_LOCK21_Pos) & GPIO_CTRL_LOCK_LOCK21_Msk) /*!< LOCK21 Set Value */
#define GPIO_CTRL_LOCK_LOCK21_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LOCK_LOCK21_Msk) >> GPIO_CTRL_LOCK_LOCK21_Pos) /*!< LOCK21 Get Value */

#define GPIO_CTRL_LOCK_LOCK20_Pos (20U)                               /*!< LOCK20 Postion   */
#define GPIO_CTRL_LOCK_LOCK20_Msk (0x1U << GPIO_CTRL_LOCK_LOCK20_Pos) /*!< LOCK20 Mask      */
#define GPIO_CTRL_LOCK_LOCK20_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LOCK_LOCK20_Pos) & GPIO_CTRL_LOCK_LOCK20_Msk) /*!< LOCK20 Set Value */
#define GPIO_CTRL_LOCK_LOCK20_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LOCK_LOCK20_Msk) >> GPIO_CTRL_LOCK_LOCK20_Pos) /*!< LOCK20 Get Value */

#define GPIO_CTRL_LOCK_LOCK19_Pos (19U)                               /*!< LOCK19 Postion   */
#define GPIO_CTRL_LOCK_LOCK19_Msk (0x1U << GPIO_CTRL_LOCK_LOCK19_Pos) /*!< LOCK19 Mask      */
#define GPIO_CTRL_LOCK_LOCK19_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LOCK_LOCK19_Pos) & GPIO_CTRL_LOCK_LOCK19_Msk) /*!< LOCK19 Set Value */
#define GPIO_CTRL_LOCK_LOCK19_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LOCK_LOCK19_Msk) >> GPIO_CTRL_LOCK_LOCK19_Pos) /*!< LOCK19 Get Value */

#define GPIO_CTRL_LOCK_LOCK18_Pos (18U)                               /*!< LOCK18 Postion   */
#define GPIO_CTRL_LOCK_LOCK18_Msk (0x1U << GPIO_CTRL_LOCK_LOCK18_Pos) /*!< LOCK18 Mask      */
#define GPIO_CTRL_LOCK_LOCK18_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LOCK_LOCK18_Pos) & GPIO_CTRL_LOCK_LOCK18_Msk) /*!< LOCK18 Set Value */
#define GPIO_CTRL_LOCK_LOCK18_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LOCK_LOCK18_Msk) >> GPIO_CTRL_LOCK_LOCK18_Pos) /*!< LOCK18 Get Value */

#define GPIO_CTRL_LOCK_LOCK17_Pos (17U)                               /*!< LOCK17 Postion   */
#define GPIO_CTRL_LOCK_LOCK17_Msk (0x1U << GPIO_CTRL_LOCK_LOCK17_Pos) /*!< LOCK17 Mask      */
#define GPIO_CTRL_LOCK_LOCK17_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LOCK_LOCK17_Pos) & GPIO_CTRL_LOCK_LOCK17_Msk) /*!< LOCK17 Set Value */
#define GPIO_CTRL_LOCK_LOCK17_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LOCK_LOCK17_Msk) >> GPIO_CTRL_LOCK_LOCK17_Pos) /*!< LOCK17 Get Value */

#define GPIO_CTRL_LOCK_LOCK16_Pos (16U)                               /*!< LOCK16 Postion   */
#define GPIO_CTRL_LOCK_LOCK16_Msk (0x1U << GPIO_CTRL_LOCK_LOCK16_Pos) /*!< LOCK16 Mask      */
#define GPIO_CTRL_LOCK_LOCK16_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LOCK_LOCK16_Pos) & GPIO_CTRL_LOCK_LOCK16_Msk) /*!< LOCK16 Set Value */
#define GPIO_CTRL_LOCK_LOCK16_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LOCK_LOCK16_Msk) >> GPIO_CTRL_LOCK_LOCK16_Pos) /*!< LOCK16 Get Value */

#define GPIO_CTRL_LOCK_LOCK15_Pos (15U)                               /*!< LOCK15 Postion   */
#define GPIO_CTRL_LOCK_LOCK15_Msk (0x1U << GPIO_CTRL_LOCK_LOCK15_Pos) /*!< LOCK15 Mask      */
#define GPIO_CTRL_LOCK_LOCK15_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LOCK_LOCK15_Pos) & GPIO_CTRL_LOCK_LOCK15_Msk) /*!< LOCK15 Set Value */
#define GPIO_CTRL_LOCK_LOCK15_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LOCK_LOCK15_Msk) >> GPIO_CTRL_LOCK_LOCK15_Pos) /*!< LOCK15 Get Value */

#define GPIO_CTRL_LOCK_LOCK14_Pos (14U)                               /*!< LOCK14 Postion   */
#define GPIO_CTRL_LOCK_LOCK14_Msk (0x1U << GPIO_CTRL_LOCK_LOCK14_Pos) /*!< LOCK14 Mask      */
#define GPIO_CTRL_LOCK_LOCK14_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LOCK_LOCK14_Pos) & GPIO_CTRL_LOCK_LOCK14_Msk) /*!< LOCK14 Set Value */
#define GPIO_CTRL_LOCK_LOCK14_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LOCK_LOCK14_Msk) >> GPIO_CTRL_LOCK_LOCK14_Pos) /*!< LOCK14 Get Value */

#define GPIO_CTRL_LOCK_LOCK13_Pos (13U)                               /*!< LOCK13 Postion   */
#define GPIO_CTRL_LOCK_LOCK13_Msk (0x1U << GPIO_CTRL_LOCK_LOCK13_Pos) /*!< LOCK13 Mask      */
#define GPIO_CTRL_LOCK_LOCK13_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LOCK_LOCK13_Pos) & GPIO_CTRL_LOCK_LOCK13_Msk) /*!< LOCK13 Set Value */
#define GPIO_CTRL_LOCK_LOCK13_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LOCK_LOCK13_Msk) >> GPIO_CTRL_LOCK_LOCK13_Pos) /*!< LOCK13 Get Value */

#define GPIO_CTRL_LOCK_LOCK12_Pos (12U)                               /*!< LOCK12 Postion   */
#define GPIO_CTRL_LOCK_LOCK12_Msk (0x1U << GPIO_CTRL_LOCK_LOCK12_Pos) /*!< LOCK12 Mask      */
#define GPIO_CTRL_LOCK_LOCK12_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LOCK_LOCK12_Pos) & GPIO_CTRL_LOCK_LOCK12_Msk) /*!< LOCK12 Set Value */
#define GPIO_CTRL_LOCK_LOCK12_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LOCK_LOCK12_Msk) >> GPIO_CTRL_LOCK_LOCK12_Pos) /*!< LOCK12 Get Value */

#define GPIO_CTRL_LOCK_LOCK11_Pos (11U)                               /*!< LOCK11 Postion   */
#define GPIO_CTRL_LOCK_LOCK11_Msk (0x1U << GPIO_CTRL_LOCK_LOCK11_Pos) /*!< LOCK11 Mask      */
#define GPIO_CTRL_LOCK_LOCK11_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LOCK_LOCK11_Pos) & GPIO_CTRL_LOCK_LOCK11_Msk) /*!< LOCK11 Set Value */
#define GPIO_CTRL_LOCK_LOCK11_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LOCK_LOCK11_Msk) >> GPIO_CTRL_LOCK_LOCK11_Pos) /*!< LOCK11 Get Value */

#define GPIO_CTRL_LOCK_LOCK10_Pos (10U)                               /*!< LOCK10 Postion   */
#define GPIO_CTRL_LOCK_LOCK10_Msk (0x1U << GPIO_CTRL_LOCK_LOCK10_Pos) /*!< LOCK10 Mask      */
#define GPIO_CTRL_LOCK_LOCK10_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LOCK_LOCK10_Pos) & GPIO_CTRL_LOCK_LOCK10_Msk) /*!< LOCK10 Set Value */
#define GPIO_CTRL_LOCK_LOCK10_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LOCK_LOCK10_Msk) >> GPIO_CTRL_LOCK_LOCK10_Pos) /*!< LOCK10 Get Value */

#define GPIO_CTRL_LOCK_LOCK9_Pos (9U)                               /*!< LOCK9 Postion   */
#define GPIO_CTRL_LOCK_LOCK9_Msk (0x1U << GPIO_CTRL_LOCK_LOCK9_Pos) /*!< LOCK9 Mask      */
#define GPIO_CTRL_LOCK_LOCK9_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LOCK_LOCK9_Pos) & GPIO_CTRL_LOCK_LOCK9_Msk) /*!< LOCK9 Set Value */
#define GPIO_CTRL_LOCK_LOCK9_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LOCK_LOCK9_Msk) >> GPIO_CTRL_LOCK_LOCK9_Pos) /*!< LOCK9 Get Value */

#define GPIO_CTRL_LOCK_LOCK8_Pos (8U)                               /*!< LOCK8 Postion   */
#define GPIO_CTRL_LOCK_LOCK8_Msk (0x1U << GPIO_CTRL_LOCK_LOCK8_Pos) /*!< LOCK8 Mask      */
#define GPIO_CTRL_LOCK_LOCK8_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LOCK_LOCK8_Pos) & GPIO_CTRL_LOCK_LOCK8_Msk) /*!< LOCK8 Set Value */
#define GPIO_CTRL_LOCK_LOCK8_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LOCK_LOCK8_Msk) >> GPIO_CTRL_LOCK_LOCK8_Pos) /*!< LOCK8 Get Value */

#define GPIO_CTRL_LOCK_LOCK7_Pos (7U)                               /*!< LOCK7 Postion   */
#define GPIO_CTRL_LOCK_LOCK7_Msk (0x1U << GPIO_CTRL_LOCK_LOCK7_Pos) /*!< LOCK7 Mask      */
#define GPIO_CTRL_LOCK_LOCK7_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LOCK_LOCK7_Pos) & GPIO_CTRL_LOCK_LOCK7_Msk) /*!< LOCK7 Set Value */
#define GPIO_CTRL_LOCK_LOCK7_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LOCK_LOCK7_Msk) >> GPIO_CTRL_LOCK_LOCK7_Pos) /*!< LOCK7 Get Value */

#define GPIO_CTRL_LOCK_LOCK6_Pos (6U)                               /*!< LOCK6 Postion   */
#define GPIO_CTRL_LOCK_LOCK6_Msk (0x1U << GPIO_CTRL_LOCK_LOCK6_Pos) /*!< LOCK6 Mask      */
#define GPIO_CTRL_LOCK_LOCK6_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LOCK_LOCK6_Pos) & GPIO_CTRL_LOCK_LOCK6_Msk) /*!< LOCK6 Set Value */
#define GPIO_CTRL_LOCK_LOCK6_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LOCK_LOCK6_Msk) >> GPIO_CTRL_LOCK_LOCK6_Pos) /*!< LOCK6 Get Value */

#define GPIO_CTRL_LOCK_LOCK5_Pos (5U)                               /*!< LOCK5 Postion   */
#define GPIO_CTRL_LOCK_LOCK5_Msk (0x1U << GPIO_CTRL_LOCK_LOCK5_Pos) /*!< LOCK5 Mask      */
#define GPIO_CTRL_LOCK_LOCK5_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LOCK_LOCK5_Pos) & GPIO_CTRL_LOCK_LOCK5_Msk) /*!< LOCK5 Set Value */
#define GPIO_CTRL_LOCK_LOCK5_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LOCK_LOCK5_Msk) >> GPIO_CTRL_LOCK_LOCK5_Pos) /*!< LOCK5 Get Value */

#define GPIO_CTRL_LOCK_LOCK4_Pos (4U)                               /*!< LOCK4 Postion   */
#define GPIO_CTRL_LOCK_LOCK4_Msk (0x1U << GPIO_CTRL_LOCK_LOCK4_Pos) /*!< LOCK4 Mask      */
#define GPIO_CTRL_LOCK_LOCK4_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LOCK_LOCK4_Pos) & GPIO_CTRL_LOCK_LOCK4_Msk) /*!< LOCK4 Set Value */
#define GPIO_CTRL_LOCK_LOCK4_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LOCK_LOCK4_Msk) >> GPIO_CTRL_LOCK_LOCK4_Pos) /*!< LOCK4 Get Value */

#define GPIO_CTRL_LOCK_LOCK3_Pos (3U)                               /*!< LOCK3 Postion   */
#define GPIO_CTRL_LOCK_LOCK3_Msk (0x1U << GPIO_CTRL_LOCK_LOCK3_Pos) /*!< LOCK3 Mask      */
#define GPIO_CTRL_LOCK_LOCK3_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LOCK_LOCK3_Pos) & GPIO_CTRL_LOCK_LOCK3_Msk) /*!< LOCK3 Set Value */
#define GPIO_CTRL_LOCK_LOCK3_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LOCK_LOCK3_Msk) >> GPIO_CTRL_LOCK_LOCK3_Pos) /*!< LOCK3 Get Value */

#define GPIO_CTRL_LOCK_LOCK2_Pos (2U)                               /*!< LOCK2 Postion   */
#define GPIO_CTRL_LOCK_LOCK2_Msk (0x1U << GPIO_CTRL_LOCK_LOCK2_Pos) /*!< LOCK2 Mask      */
#define GPIO_CTRL_LOCK_LOCK2_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LOCK_LOCK2_Pos) & GPIO_CTRL_LOCK_LOCK2_Msk) /*!< LOCK2 Set Value */
#define GPIO_CTRL_LOCK_LOCK2_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LOCK_LOCK2_Msk) >> GPIO_CTRL_LOCK_LOCK2_Pos) /*!< LOCK2 Get Value */

#define GPIO_CTRL_LOCK_LOCK1_Pos (1U)                               /*!< LOCK1 Postion   */
#define GPIO_CTRL_LOCK_LOCK1_Msk (0x1U << GPIO_CTRL_LOCK_LOCK1_Pos) /*!< LOCK1 Mask      */
#define GPIO_CTRL_LOCK_LOCK1_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LOCK_LOCK1_Pos) & GPIO_CTRL_LOCK_LOCK1_Msk) /*!< LOCK1 Set Value */
#define GPIO_CTRL_LOCK_LOCK1_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LOCK_LOCK1_Msk) >> GPIO_CTRL_LOCK_LOCK1_Pos) /*!< LOCK1 Get Value */

#define GPIO_CTRL_LOCK_LOCK0_Pos (0U)                               /*!< LOCK0 Postion   */
#define GPIO_CTRL_LOCK_LOCK0_Msk (0x1U << GPIO_CTRL_LOCK_LOCK0_Pos) /*!< LOCK0 Mask      */
#define GPIO_CTRL_LOCK_LOCK0_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_LOCK_LOCK0_Pos) & GPIO_CTRL_LOCK_LOCK0_Msk) /*!< LOCK0 Set Value */
#define GPIO_CTRL_LOCK_LOCK0_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_LOCK_LOCK0_Msk) >> GPIO_CTRL_LOCK_LOCK0_Pos) /*!< LOCK0 Get Value */

/* CR bitfield */
#define GPIO_CTRL_CR_CR31_Pos (31U)                           /*!< CR31 Postion   */
#define GPIO_CTRL_CR_CR31_Msk (0x1U << GPIO_CTRL_CR_CR31_Pos) /*!< CR31 Mask      */
#define GPIO_CTRL_CR_CR31_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_CR_CR31_Pos) & GPIO_CTRL_CR_CR31_Msk) /*!< CR31 Set Value */
#define GPIO_CTRL_CR_CR31_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_CR_CR31_Msk) >> GPIO_CTRL_CR_CR31_Pos) /*!< CR31 Get Value */

#define GPIO_CTRL_CR_CR30_Pos (30U)                           /*!< CR30 Postion   */
#define GPIO_CTRL_CR_CR30_Msk (0x1U << GPIO_CTRL_CR_CR30_Pos) /*!< CR30 Mask      */
#define GPIO_CTRL_CR_CR30_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_CR_CR30_Pos) & GPIO_CTRL_CR_CR30_Msk) /*!< CR30 Set Value */
#define GPIO_CTRL_CR_CR30_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_CR_CR30_Msk) >> GPIO_CTRL_CR_CR30_Pos) /*!< CR30 Get Value */

#define GPIO_CTRL_CR_CR29_Pos (29U)                           /*!< CR29 Postion   */
#define GPIO_CTRL_CR_CR29_Msk (0x1U << GPIO_CTRL_CR_CR29_Pos) /*!< CR29 Mask      */
#define GPIO_CTRL_CR_CR29_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_CR_CR29_Pos) & GPIO_CTRL_CR_CR29_Msk) /*!< CR29 Set Value */
#define GPIO_CTRL_CR_CR29_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_CR_CR29_Msk) >> GPIO_CTRL_CR_CR29_Pos) /*!< CR29 Get Value */

#define GPIO_CTRL_CR_CR28_Pos (28U)                           /*!< CR28 Postion   */
#define GPIO_CTRL_CR_CR28_Msk (0x1U << GPIO_CTRL_CR_CR28_Pos) /*!< CR28 Mask      */
#define GPIO_CTRL_CR_CR28_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_CR_CR28_Pos) & GPIO_CTRL_CR_CR28_Msk) /*!< CR28 Set Value */
#define GPIO_CTRL_CR_CR28_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_CR_CR28_Msk) >> GPIO_CTRL_CR_CR28_Pos) /*!< CR28 Get Value */

#define GPIO_CTRL_CR_CR27_Pos (27U)                           /*!< CR27 Postion   */
#define GPIO_CTRL_CR_CR27_Msk (0x1U << GPIO_CTRL_CR_CR27_Pos) /*!< CR27 Mask      */
#define GPIO_CTRL_CR_CR27_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_CR_CR27_Pos) & GPIO_CTRL_CR_CR27_Msk) /*!< CR27 Set Value */
#define GPIO_CTRL_CR_CR27_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_CR_CR27_Msk) >> GPIO_CTRL_CR_CR27_Pos) /*!< CR27 Get Value */

#define GPIO_CTRL_CR_CR26_Pos (26U)                           /*!< CR26 Postion   */
#define GPIO_CTRL_CR_CR26_Msk (0x1U << GPIO_CTRL_CR_CR26_Pos) /*!< CR26 Mask      */
#define GPIO_CTRL_CR_CR26_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_CR_CR26_Pos) & GPIO_CTRL_CR_CR26_Msk) /*!< CR26 Set Value */
#define GPIO_CTRL_CR_CR26_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_CR_CR26_Msk) >> GPIO_CTRL_CR_CR26_Pos) /*!< CR26 Get Value */

#define GPIO_CTRL_CR_CR25_Pos (25U)                           /*!< CR25 Postion   */
#define GPIO_CTRL_CR_CR25_Msk (0x1U << GPIO_CTRL_CR_CR25_Pos) /*!< CR25 Mask      */
#define GPIO_CTRL_CR_CR25_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_CR_CR25_Pos) & GPIO_CTRL_CR_CR25_Msk) /*!< CR25 Set Value */
#define GPIO_CTRL_CR_CR25_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_CR_CR25_Msk) >> GPIO_CTRL_CR_CR25_Pos) /*!< CR25 Get Value */

#define GPIO_CTRL_CR_CR24_Pos (24U)                           /*!< CR24 Postion   */
#define GPIO_CTRL_CR_CR24_Msk (0x1U << GPIO_CTRL_CR_CR24_Pos) /*!< CR24 Mask      */
#define GPIO_CTRL_CR_CR24_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_CR_CR24_Pos) & GPIO_CTRL_CR_CR24_Msk) /*!< CR24 Set Value */
#define GPIO_CTRL_CR_CR24_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_CR_CR24_Msk) >> GPIO_CTRL_CR_CR24_Pos) /*!< CR24 Get Value */

#define GPIO_CTRL_CR_CR23_Pos (23U)                           /*!< CR23 Postion   */
#define GPIO_CTRL_CR_CR23_Msk (0x1U << GPIO_CTRL_CR_CR23_Pos) /*!< CR23 Mask      */
#define GPIO_CTRL_CR_CR23_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_CR_CR23_Pos) & GPIO_CTRL_CR_CR23_Msk) /*!< CR23 Set Value */
#define GPIO_CTRL_CR_CR23_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_CR_CR23_Msk) >> GPIO_CTRL_CR_CR23_Pos) /*!< CR23 Get Value */

#define GPIO_CTRL_CR_CR22_Pos (22U)                           /*!< CR22 Postion   */
#define GPIO_CTRL_CR_CR22_Msk (0x1U << GPIO_CTRL_CR_CR22_Pos) /*!< CR22 Mask      */
#define GPIO_CTRL_CR_CR22_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_CR_CR22_Pos) & GPIO_CTRL_CR_CR22_Msk) /*!< CR22 Set Value */
#define GPIO_CTRL_CR_CR22_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_CR_CR22_Msk) >> GPIO_CTRL_CR_CR22_Pos) /*!< CR22 Get Value */

#define GPIO_CTRL_CR_CR21_Pos (21U)                           /*!< CR21 Postion   */
#define GPIO_CTRL_CR_CR21_Msk (0x1U << GPIO_CTRL_CR_CR21_Pos) /*!< CR21 Mask      */
#define GPIO_CTRL_CR_CR21_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_CR_CR21_Pos) & GPIO_CTRL_CR_CR21_Msk) /*!< CR21 Set Value */
#define GPIO_CTRL_CR_CR21_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_CR_CR21_Msk) >> GPIO_CTRL_CR_CR21_Pos) /*!< CR21 Get Value */

#define GPIO_CTRL_CR_CR20_Pos (20U)                           /*!< CR20 Postion   */
#define GPIO_CTRL_CR_CR20_Msk (0x1U << GPIO_CTRL_CR_CR20_Pos) /*!< CR20 Mask      */
#define GPIO_CTRL_CR_CR20_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_CR_CR20_Pos) & GPIO_CTRL_CR_CR20_Msk) /*!< CR20 Set Value */
#define GPIO_CTRL_CR_CR20_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_CR_CR20_Msk) >> GPIO_CTRL_CR_CR20_Pos) /*!< CR20 Get Value */

#define GPIO_CTRL_CR_CR19_Pos (19U)                           /*!< CR19 Postion   */
#define GPIO_CTRL_CR_CR19_Msk (0x1U << GPIO_CTRL_CR_CR19_Pos) /*!< CR19 Mask      */
#define GPIO_CTRL_CR_CR19_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_CR_CR19_Pos) & GPIO_CTRL_CR_CR19_Msk) /*!< CR19 Set Value */
#define GPIO_CTRL_CR_CR19_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_CR_CR19_Msk) >> GPIO_CTRL_CR_CR19_Pos) /*!< CR19 Get Value */

#define GPIO_CTRL_CR_CR18_Pos (18U)                           /*!< CR18 Postion   */
#define GPIO_CTRL_CR_CR18_Msk (0x1U << GPIO_CTRL_CR_CR18_Pos) /*!< CR18 Mask      */
#define GPIO_CTRL_CR_CR18_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_CR_CR18_Pos) & GPIO_CTRL_CR_CR18_Msk) /*!< CR18 Set Value */
#define GPIO_CTRL_CR_CR18_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_CR_CR18_Msk) >> GPIO_CTRL_CR_CR18_Pos) /*!< CR18 Get Value */

#define GPIO_CTRL_CR_CR17_Pos (17U)                           /*!< CR17 Postion   */
#define GPIO_CTRL_CR_CR17_Msk (0x1U << GPIO_CTRL_CR_CR17_Pos) /*!< CR17 Mask      */
#define GPIO_CTRL_CR_CR17_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_CR_CR17_Pos) & GPIO_CTRL_CR_CR17_Msk) /*!< CR17 Set Value */
#define GPIO_CTRL_CR_CR17_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_CR_CR17_Msk) >> GPIO_CTRL_CR_CR17_Pos) /*!< CR17 Get Value */

#define GPIO_CTRL_CR_CR16_Pos (16U)                           /*!< CR16 Postion   */
#define GPIO_CTRL_CR_CR16_Msk (0x1U << GPIO_CTRL_CR_CR16_Pos) /*!< CR16 Mask      */
#define GPIO_CTRL_CR_CR16_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_CR_CR16_Pos) & GPIO_CTRL_CR_CR16_Msk) /*!< CR16 Set Value */
#define GPIO_CTRL_CR_CR16_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_CR_CR16_Msk) >> GPIO_CTRL_CR_CR16_Pos) /*!< CR16 Get Value */

#define GPIO_CTRL_CR_CR15_Pos (15U)                           /*!< CR15 Postion   */
#define GPIO_CTRL_CR_CR15_Msk (0x1U << GPIO_CTRL_CR_CR15_Pos) /*!< CR15 Mask      */
#define GPIO_CTRL_CR_CR15_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_CR_CR15_Pos) & GPIO_CTRL_CR_CR15_Msk) /*!< CR15 Set Value */
#define GPIO_CTRL_CR_CR15_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_CR_CR15_Msk) >> GPIO_CTRL_CR_CR15_Pos) /*!< CR15 Get Value */

#define GPIO_CTRL_CR_CR14_Pos (14U)                           /*!< CR14 Postion   */
#define GPIO_CTRL_CR_CR14_Msk (0x1U << GPIO_CTRL_CR_CR14_Pos) /*!< CR14 Mask      */
#define GPIO_CTRL_CR_CR14_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_CR_CR14_Pos) & GPIO_CTRL_CR_CR14_Msk) /*!< CR14 Set Value */
#define GPIO_CTRL_CR_CR14_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_CR_CR14_Msk) >> GPIO_CTRL_CR_CR14_Pos) /*!< CR14 Get Value */

#define GPIO_CTRL_CR_CR13_Pos (13U)                           /*!< CR13 Postion   */
#define GPIO_CTRL_CR_CR13_Msk (0x1U << GPIO_CTRL_CR_CR13_Pos) /*!< CR13 Mask      */
#define GPIO_CTRL_CR_CR13_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_CR_CR13_Pos) & GPIO_CTRL_CR_CR13_Msk) /*!< CR13 Set Value */
#define GPIO_CTRL_CR_CR13_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_CR_CR13_Msk) >> GPIO_CTRL_CR_CR13_Pos) /*!< CR13 Get Value */

#define GPIO_CTRL_CR_CR12_Pos (12U)                           /*!< CR12 Postion   */
#define GPIO_CTRL_CR_CR12_Msk (0x1U << GPIO_CTRL_CR_CR12_Pos) /*!< CR12 Mask      */
#define GPIO_CTRL_CR_CR12_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_CR_CR12_Pos) & GPIO_CTRL_CR_CR12_Msk) /*!< CR12 Set Value */
#define GPIO_CTRL_CR_CR12_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_CR_CR12_Msk) >> GPIO_CTRL_CR_CR12_Pos) /*!< CR12 Get Value */

#define GPIO_CTRL_CR_CR11_Pos (11U)                           /*!< CR11 Postion   */
#define GPIO_CTRL_CR_CR11_Msk (0x1U << GPIO_CTRL_CR_CR11_Pos) /*!< CR11 Mask      */
#define GPIO_CTRL_CR_CR11_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_CR_CR11_Pos) & GPIO_CTRL_CR_CR11_Msk) /*!< CR11 Set Value */
#define GPIO_CTRL_CR_CR11_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_CR_CR11_Msk) >> GPIO_CTRL_CR_CR11_Pos) /*!< CR11 Get Value */

#define GPIO_CTRL_CR_CR10_Pos (10U)                           /*!< CR10 Postion   */
#define GPIO_CTRL_CR_CR10_Msk (0x1U << GPIO_CTRL_CR_CR10_Pos) /*!< CR10 Mask      */
#define GPIO_CTRL_CR_CR10_Set(x) \
    (((uint32_t) (x) << GPIO_CTRL_CR_CR10_Pos) & GPIO_CTRL_CR_CR10_Msk) /*!< CR10 Set Value */
#define GPIO_CTRL_CR_CR10_Get(x) \
    (((uint32_t) (x) &GPIO_CTRL_CR_CR10_Msk) >> GPIO_CTRL_CR_CR10_Pos) /*!< CR10 Get Value */

#define GPIO_CTRL_CR_CR9_Pos (9U)                           /*!< CR9 Postion   */
#define GPIO_CTRL_CR_CR9_Msk (0x1U << GPIO_CTRL_CR_CR9_Pos) /*!< CR9 Mask      */
#define GPIO_CTRL_CR_CR9_Set(x)                                                                                     \
    (((uint32_t) (x) << GPIO_CTRL_CR_CR9_Pos) & GPIO_CTRL_CR_CR9_Msk)                            /*!< CR9 Set Value \
                                                                                                  */
#define GPIO_CTRL_CR_CR9_Get(x) (((uint32_t) (x) &GPIO_CTRL_CR_CR9_Msk) >> GPIO_CTRL_CR_CR9_Pos) /*!< CR9 Get Value */

#define GPIO_CTRL_CR_CR8_Pos (8U)                           /*!< CR8 Postion   */
#define GPIO_CTRL_CR_CR8_Msk (0x1U << GPIO_CTRL_CR_CR8_Pos) /*!< CR8 Mask      */
#define GPIO_CTRL_CR_CR8_Set(x)                                                                                     \
    (((uint32_t) (x) << GPIO_CTRL_CR_CR8_Pos) & GPIO_CTRL_CR_CR8_Msk)                            /*!< CR8 Set Value \
                                                                                                  */
#define GPIO_CTRL_CR_CR8_Get(x) (((uint32_t) (x) &GPIO_CTRL_CR_CR8_Msk) >> GPIO_CTRL_CR_CR8_Pos) /*!< CR8 Get Value */

#define GPIO_CTRL_CR_CR7_Pos (7U)                           /*!< CR7 Postion   */
#define GPIO_CTRL_CR_CR7_Msk (0x1U << GPIO_CTRL_CR_CR7_Pos) /*!< CR7 Mask      */
#define GPIO_CTRL_CR_CR7_Set(x)                                                                                     \
    (((uint32_t) (x) << GPIO_CTRL_CR_CR7_Pos) & GPIO_CTRL_CR_CR7_Msk)                            /*!< CR7 Set Value \
                                                                                                  */
#define GPIO_CTRL_CR_CR7_Get(x) (((uint32_t) (x) &GPIO_CTRL_CR_CR7_Msk) >> GPIO_CTRL_CR_CR7_Pos) /*!< CR7 Get Value */

#define GPIO_CTRL_CR_CR6_Pos (6U)                           /*!< CR6 Postion   */
#define GPIO_CTRL_CR_CR6_Msk (0x1U << GPIO_CTRL_CR_CR6_Pos) /*!< CR6 Mask      */
#define GPIO_CTRL_CR_CR6_Set(x)                                                                                     \
    (((uint32_t) (x) << GPIO_CTRL_CR_CR6_Pos) & GPIO_CTRL_CR_CR6_Msk)                            /*!< CR6 Set Value \
                                                                                                  */
#define GPIO_CTRL_CR_CR6_Get(x) (((uint32_t) (x) &GPIO_CTRL_CR_CR6_Msk) >> GPIO_CTRL_CR_CR6_Pos) /*!< CR6 Get Value */

#define GPIO_CTRL_CR_CR5_Pos (5U)                           /*!< CR5 Postion   */
#define GPIO_CTRL_CR_CR5_Msk (0x1U << GPIO_CTRL_CR_CR5_Pos) /*!< CR5 Mask      */
#define GPIO_CTRL_CR_CR5_Set(x)                                                                                     \
    (((uint32_t) (x) << GPIO_CTRL_CR_CR5_Pos) & GPIO_CTRL_CR_CR5_Msk)                            /*!< CR5 Set Value \
                                                                                                  */
#define GPIO_CTRL_CR_CR5_Get(x) (((uint32_t) (x) &GPIO_CTRL_CR_CR5_Msk) >> GPIO_CTRL_CR_CR5_Pos) /*!< CR5 Get Value */

#define GPIO_CTRL_CR_CR4_Pos (4U)                           /*!< CR4 Postion   */
#define GPIO_CTRL_CR_CR4_Msk (0x1U << GPIO_CTRL_CR_CR4_Pos) /*!< CR4 Mask      */
#define GPIO_CTRL_CR_CR4_Set(x)                                                                                     \
    (((uint32_t) (x) << GPIO_CTRL_CR_CR4_Pos) & GPIO_CTRL_CR_CR4_Msk)                            /*!< CR4 Set Value \
                                                                                                  */
#define GPIO_CTRL_CR_CR4_Get(x) (((uint32_t) (x) &GPIO_CTRL_CR_CR4_Msk) >> GPIO_CTRL_CR_CR4_Pos) /*!< CR4 Get Value */

#define GPIO_CTRL_CR_CR3_Pos (3U)                           /*!< CR3 Postion   */
#define GPIO_CTRL_CR_CR3_Msk (0x1U << GPIO_CTRL_CR_CR3_Pos) /*!< CR3 Mask      */
#define GPIO_CTRL_CR_CR3_Set(x)                                                                                     \
    (((uint32_t) (x) << GPIO_CTRL_CR_CR3_Pos) & GPIO_CTRL_CR_CR3_Msk)                            /*!< CR3 Set Value \
                                                                                                  */
#define GPIO_CTRL_CR_CR3_Get(x) (((uint32_t) (x) &GPIO_CTRL_CR_CR3_Msk) >> GPIO_CTRL_CR_CR3_Pos) /*!< CR3 Get Value */

#define GPIO_CTRL_CR_CR2_Pos (2U)                           /*!< CR2 Postion   */
#define GPIO_CTRL_CR_CR2_Msk (0x1U << GPIO_CTRL_CR_CR2_Pos) /*!< CR2 Mask      */
#define GPIO_CTRL_CR_CR2_Set(x)                                                                                     \
    (((uint32_t) (x) << GPIO_CTRL_CR_CR2_Pos) & GPIO_CTRL_CR_CR2_Msk)                            /*!< CR2 Set Value \
                                                                                                  */
#define GPIO_CTRL_CR_CR2_Get(x) (((uint32_t) (x) &GPIO_CTRL_CR_CR2_Msk) >> GPIO_CTRL_CR_CR2_Pos) /*!< CR2 Get Value */

#define GPIO_CTRL_CR_CR1_Pos (1U)                           /*!< CR1 Postion   */
#define GPIO_CTRL_CR_CR1_Msk (0x1U << GPIO_CTRL_CR_CR1_Pos) /*!< CR1 Mask      */
#define GPIO_CTRL_CR_CR1_Set(x)                                                                                     \
    (((uint32_t) (x) << GPIO_CTRL_CR_CR1_Pos) & GPIO_CTRL_CR_CR1_Msk)                            /*!< CR1 Set Value \
                                                                                                  */
#define GPIO_CTRL_CR_CR1_Get(x) (((uint32_t) (x) &GPIO_CTRL_CR_CR1_Msk) >> GPIO_CTRL_CR_CR1_Pos) /*!< CR1 Get Value */

#define GPIO_CTRL_CR_CR0_Pos (0U)                           /*!< CR0 Postion   */
#define GPIO_CTRL_CR_CR0_Msk (0x1U << GPIO_CTRL_CR_CR0_Pos) /*!< CR0 Mask      */
#define GPIO_CTRL_CR_CR0_Set(x)                                                                                     \
    (((uint32_t) (x) << GPIO_CTRL_CR_CR0_Pos) & GPIO_CTRL_CR_CR0_Msk)                            /*!< CR0 Set Value \
                                                                                                  */
#define GPIO_CTRL_CR_CR0_Get(x) (((uint32_t) (x) &GPIO_CTRL_CR_CR0_Msk) >> GPIO_CTRL_CR_CR0_Pos) /*!< CR0 Get Value */

/*!
 * @}
 */

/*!
 * @}
 */ /* end of HS32F7D377_GPIO_CTRL_REGISTER */

#endif // HS32F7D377_GPIO_CTRL_H
