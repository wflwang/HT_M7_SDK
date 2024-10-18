/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file HS32F7D377_gpio_data.h
 * \brief HS32F7D377 GPIO DATA register file
 * \version 1.0.0
 */

#ifndef HS32F7D377_GPIO_DATA_H
#define HS32F7D377_GPIO_DATA_H

/*!
 * \addtogroup HS32F7D377_GPIO_DATA_REGISTER HS32F7D377 GPIO_DATA Register
 * \ingroup HS32F7D377_REGISTER
 *
 * \brief GPIO DATA register layout, bitfield and address definitions
 *
 * @{
 */

/*!
 * \name GPIO DATA Register Layout
 *
 * @{
 */

/*! \brief GPIO DATA register layout */
typedef struct
{
    struct
    {
        union
        {
            __IOM uint32_t DAT; /*!< Offset: 0x00, GPIO Data Register */

            struct
            {
                __IOM uint32_t DAT0  : 1; /*!< [0:0] : Data Register for this pin, Reset type: SYSRSn */
                __IOM uint32_t DAT1  : 1; /*!< [1:1] : Data Register for this pin, Reset type: SYSRSn */
                __IOM uint32_t DAT2  : 1; /*!< [2:2] : Data Register for this pin, Reset type: SYSRSn */
                __IOM uint32_t DAT3  : 1; /*!< [3:3] : Data Register for this pin, Reset type: SYSRSn */
                __IOM uint32_t DAT4  : 1; /*!< [4:4] : Data Register for this pin, Reset type: SYSRSn */
                __IOM uint32_t DAT5  : 1; /*!< [5:5] : Data Register for this pin, Reset type: SYSRSn */
                __IOM uint32_t DAT6  : 1; /*!< [6:6] : Data Register for this pin, Reset type: SYSRSn */
                __IOM uint32_t DAT7  : 1; /*!< [7:7] : Data Register for this pin, Reset type: SYSRSn */
                __IOM uint32_t DAT8  : 1; /*!< [8:8] : Data Register for this pin, Reset type: SYSRSn */
                __IOM uint32_t DAT9  : 1; /*!< [9:9] : Data Register for this pin, Reset type: SYSRSn */
                __IOM uint32_t DAT10 : 1; /*!< [10:10] : Data Register for this pin, Reset type: SYSRSn */
                __IOM uint32_t DAT11 : 1; /*!< [11:11] : Data Register for this pin, Reset type: SYSRSn */
                __IOM uint32_t DAT12 : 1; /*!< [12:12] : Data Register for this pin, Reset type: SYSRSn */
                __IOM uint32_t DAT13 : 1; /*!< [13:13] : Data Register for this pin, Reset type: SYSRSn */
                __IOM uint32_t DAT14 : 1; /*!< [14:14] : Data Register for this pin, Reset type: SYSRSn */
                __IOM uint32_t DAT15 : 1; /*!< [15:15] : Data Register for this pin, Reset type: SYSRSn */
                __IOM uint32_t DAT16 : 1; /*!< [16:16] : Data Register for this pin, Reset type: SYSRSn */
                __IOM uint32_t DAT17 : 1; /*!< [17:17] : Data Register for this pin, Reset type: SYSRSn */
                __IOM uint32_t DAT18 : 1; /*!< [18:18] : Data Register for this pin, Reset type: SYSRSn */
                __IOM uint32_t DAT19 : 1; /*!< [19:19] : Data Register for this pin, Reset type: SYSRSn */
                __IOM uint32_t DAT20 : 1; /*!< [20:20] : Data Register for this pin, Reset type: SYSRSn */
                __IOM uint32_t DAT21 : 1; /*!< [21:21] : Data Register for this pin, Reset type: SYSRSn */
                __IOM uint32_t DAT22 : 1; /*!< [22:22] : Data Register for this pin, Reset type: SYSRSn */
                __IOM uint32_t DAT23 : 1; /*!< [23:23] : Data Register for this pin, Reset type: SYSRSn */
                __IOM uint32_t DAT24 : 1; /*!< [24:24] : Data Register for this pin, Reset type: SYSRSn */
                __IOM uint32_t DAT25 : 1; /*!< [25:25] : Data Register for this pin, Reset type: SYSRSn */
                __IOM uint32_t DAT26 : 1; /*!< [26:26] : Data Register for this pin, Reset type: SYSRSn */
                __IOM uint32_t DAT27 : 1; /*!< [27:27] : Data Register for this pin, Reset type: SYSRSn */
                __IOM uint32_t DAT28 : 1; /*!< [28:28] : Data Register for this pin, Reset type: SYSRSn */
                __IOM uint32_t DAT29 : 1; /*!< [29:29] : Data Register for this pin, Reset type: SYSRSn */
                __IOM uint32_t DAT30 : 1; /*!< [30:30] : Data Register for this pin, Reset type: SYSRSn */
                __IOM uint32_t DAT31 : 1; /*!< [31:31] : Data Register for this pin, Reset type: SYSRSn */
            } DATb;
        };

        union
        {
            __OM uint32_t SET; /*!< Offset: 0x04, GPIO Data Set Register */

            struct
            {
                __OM uint32_t SET0  : 1; /*!< [0:0] : Output Set bit for this pin, Reset type: SYSRSn */
                __OM uint32_t SET1  : 1; /*!< [1:1] : Output Set bit for this pin, Reset type: SYSRSn */
                __OM uint32_t SET2  : 1; /*!< [2:2] : Output Set bit for this pin, Reset type: SYSRSn */
                __OM uint32_t SET3  : 1; /*!< [3:3] : Output Set bit for this pin, Reset type: SYSRSn */
                __OM uint32_t SET4  : 1; /*!< [4:4] : Output Set bit for this pin, Reset type: SYSRSn */
                __OM uint32_t SET5  : 1; /*!< [5:5] : Output Set bit for this pin, Reset type: SYSRSn */
                __OM uint32_t SET6  : 1; /*!< [6:6] : Output Set bit for this pin, Reset type: SYSRSn */
                __OM uint32_t SET7  : 1; /*!< [7:7] : Output Set bit for this pin, Reset type: SYSRSn */
                __OM uint32_t SET8  : 1; /*!< [8:8] : Output Set bit for this pin, Reset type: SYSRSn */
                __OM uint32_t SET9  : 1; /*!< [9:9] : Output Set bit for this pin, Reset type: SYSRSn */
                __OM uint32_t SET10 : 1; /*!< [10:10] : Output Set bit for this pin, Reset type: SYSRSn */
                __OM uint32_t SET11 : 1; /*!< [11:11] : Output Set bit for this pin, Reset type: SYSRSn */
                __OM uint32_t SET12 : 1; /*!< [12:12] : Output Set bit for this pin, Reset type: SYSRSn */
                __OM uint32_t SET13 : 1; /*!< [13:13] : Output Set bit for this pin, Reset type: SYSRSn */
                __OM uint32_t SET14 : 1; /*!< [14:14] : Output Set bit for this pin, Reset type: SYSRSn */
                __OM uint32_t SET15 : 1; /*!< [15:15] : Output Set bit for this pin, Reset type: SYSRSn */
                __OM uint32_t SET16 : 1; /*!< [16:16] : Output Set bit for this pin, Reset type: SYSRSn */
                __OM uint32_t SET17 : 1; /*!< [17:17] : Output Set bit for this pin, Reset type: SYSRSn */
                __OM uint32_t SET18 : 1; /*!< [18:18] : Output Set bit for this pin, Reset type: SYSRSn */
                __OM uint32_t SET19 : 1; /*!< [19:19] : Output Set bit for this pin, Reset type: SYSRSn */
                __OM uint32_t SET20 : 1; /*!< [20:20] : Output Set bit for this pin, Reset type: SYSRSn */
                __OM uint32_t SET21 : 1; /*!< [21:21] : Output Set bit for this pin, Reset type: SYSRSn */
                __OM uint32_t SET22 : 1; /*!< [22:22] : Output Set bit for this pin, Reset type: SYSRSn */
                __OM uint32_t SET23 : 1; /*!< [23:23] : Output Set bit for this pin, Reset type: SYSRSn */
                __OM uint32_t SET24 : 1; /*!< [24:24] : Output Set bit for this pin, Reset type: SYSRSn */
                __OM uint32_t SET25 : 1; /*!< [25:25] : Output Set bit for this pin, Reset type: SYSRSn */
                __OM uint32_t SET26 : 1; /*!< [26:26] : Output Set bit for this pin, Reset type: SYSRSn */
                __OM uint32_t SET27 : 1; /*!< [27:27] : Output Set bit for this pin, Reset type: SYSRSn */
                __OM uint32_t SET28 : 1; /*!< [28:28] : Output Set bit for this pin, Reset type: SYSRSn */
                __OM uint32_t SET29 : 1; /*!< [29:29] : Output Set bit for this pin, Reset type: SYSRSn */
                __OM uint32_t SET30 : 1; /*!< [30:30] : Output Set bit for this pin, Reset type: SYSRSn */
                __OM uint32_t SET31 : 1; /*!< [31:31] : Output Set bit for this pin, Reset type: SYSRSn */
            } SETb;
        };

        union
        {
            __OM uint32_t CLEAR; /*!< Offset: 0x08, GPIO Data Clear Register */

            struct
            {
                __OM uint32_t CLEAR0  : 1; /*!< [0:0] : Output Clear bit for this pin, Reset type : SYSRSn */
                __OM uint32_t CLEAR1  : 1; /*!< [1:1] : Output Clear bit for this pin, Reset type : SYSRSn */
                __OM uint32_t CLEAR2  : 1; /*!< [2:2] : Output Clear bit for this pin, Reset type : SYSRSn */
                __OM uint32_t CLEAR3  : 1; /*!< [3:3] : Output Clear bit for this pin, Reset type : SYSRSn */
                __OM uint32_t CLEAR4  : 1; /*!< [4:4] : Output Clear bit for this pin, Reset type : SYSRSn */
                __OM uint32_t CLEAR5  : 1; /*!< [5:5] : Output Clear bit for this pin, Reset type : SYSRSn */
                __OM uint32_t CLEAR6  : 1; /*!< [6:6] : Output Clear bit for this pin, Reset type : SYSRSn */
                __OM uint32_t CLEAR7  : 1; /*!< [7:7] : Output Clear bit for this pin, Reset type : SYSRSn */
                __OM uint32_t CLEAR8  : 1; /*!< [8:8] : Output Clear bit for this pin, Reset type : SYSRSn */
                __OM uint32_t CLEAR9  : 1; /*!< [9:9] : Output Clear bit for this pin, Reset type : SYSRSn */
                __OM uint32_t CLEAR10 : 1; /*!< [10:10] : Output Clear bit for this pin, Reset type : SYSRSn */
                __OM uint32_t CLEAR11 : 1; /*!< [11:11] : Output Clear bit for this pin, Reset type : SYSRSn */
                __OM uint32_t CLEAR12 : 1; /*!< [12:12] : Output Clear bit for this pin, Reset type : SYSRSn */
                __OM uint32_t CLEAR13 : 1; /*!< [13:13] : Output Clear bit for this pin, Reset type : SYSRSn */
                __OM uint32_t CLEAR14 : 1; /*!< [14:14] : Output Clear bit for this pin, Reset type : SYSRSn */
                __OM uint32_t CLEAR15 : 1; /*!< [15:15] : Output Clear bit for this pin, Reset type : SYSRSn */
                __OM uint32_t CLEAR16 : 1; /*!< [16:16] : Output Clear bit for this pin, Reset type : SYSRSn */
                __OM uint32_t CLEAR17 : 1; /*!< [17:17] : Output Clear bit for this pin, Reset type : SYSRSn */
                __OM uint32_t CLEAR18 : 1; /*!< [18:18] : Output Clear bit for this pin, Reset type : SYSRSn */
                __OM uint32_t CLEAR19 : 1; /*!< [19:19] : Output Clear bit for this pin, Reset type : SYSRSn */
                __OM uint32_t CLEAR20 : 1; /*!< [20:20] : Output Clear bit for this pin, Reset type : SYSRSn */
                __OM uint32_t CLEAR21 : 1; /*!< [21:21] : Output Clear bit for this pin, Reset type : SYSRSn */
                __OM uint32_t CLEAR22 : 1; /*!< [22:22] : Output Clear bit for this pin, Reset type : SYSRSn */
                __OM uint32_t CLEAR23 : 1; /*!< [23:23] : Output Clear bit for this pin, Reset type : SYSRSn */
                __OM uint32_t CLEAR24 : 1; /*!< [24:24] : Output Clear bit for this pin, Reset type : SYSRSn */
                __OM uint32_t CLEAR25 : 1; /*!< [25:25] : Output Clear bit for this pin, Reset type : SYSRSn */
                __OM uint32_t CLEAR26 : 1; /*!< [26:26] : Output Clear bit for this pin, Reset type : SYSRSn */
                __OM uint32_t CLEAR27 : 1; /*!< [27:27] : Output Clear bit for this pin, Reset type : SYSRSn */
                __OM uint32_t CLEAR28 : 1; /*!< [28:28] : Output Clear bit for this pin, Reset type : SYSRSn */
                __OM uint32_t CLEAR29 : 1; /*!< [29:29] : Output Clear bit for this pin, Reset type : SYSRSn */
                __OM uint32_t CLEAR30 : 1; /*!< [30:30] : Output Clear bit for this pin, Reset type : SYSRSn */
                __OM uint32_t CLEAR31 : 1; /*!< [31:31] : Output Clear bit for this pin, Reset type : SYSRSn */
            } CLEARb;
        };

        union
        {
            __OM uint32_t TOGGLE; /*!< Offset: 0x0c, GPIO Data Toggle Register */

            struct
            {
                __OM uint32_t TOGGLE0  : 1; /*!< [0:0] : Output togger bit for this pin, Reset type : SYSRSn */
                __OM uint32_t TOGGLE1  : 1; /*!< [1:1] : Output togger bit for this pin, Reset type : SYSRSn */
                __OM uint32_t TOGGLE2  : 1; /*!< [2:2] : Output togger bit for this pin, Reset type : SYSRSn */
                __OM uint32_t TOGGLE3  : 1; /*!< [3:3] : Output togger bit for this pin, Reset type : SYSRSn */
                __OM uint32_t TOGGLE4  : 1; /*!< [4:4] : Output togger bit for this pin, Reset type : SYSRSn */
                __OM uint32_t TOGGLE5  : 1; /*!< [5:5] : Output togger bit for this pin, Reset type : SYSRSn */
                __OM uint32_t TOGGLE6  : 1; /*!< [6:6] : Output togger bit for this pin, Reset type : SYSRSn */
                __OM uint32_t TOGGLE7  : 1; /*!< [7:7] : Output togger bit for this pin, Reset type : SYSRSn */
                __OM uint32_t TOGGLE8  : 1; /*!< [8:8] : Output togger bit for this pin, Reset type : SYSRSn */
                __OM uint32_t TOGGLE9  : 1; /*!< [9:9] : Output togger bit for this pin, Reset type : SYSRSn */
                __OM uint32_t TOGGLE10 : 1; /*!< [10:10] : Output togger bit for this pin, Reset type : SYSRSn */
                __OM uint32_t TOGGLE11 : 1; /*!< [11:11] : Output togger bit for this pin, Reset type : SYSRSn */
                __OM uint32_t TOGGLE12 : 1; /*!< [12:12] : Output togger bit for this pin, Reset type : SYSRSn */
                __OM uint32_t TOGGLE13 : 1; /*!< [13:13] : Output togger bit for this pin, Reset type : SYSRSn */
                __OM uint32_t TOGGLE14 : 1; /*!< [14:14] : Output togger bit for this pin, Reset type : SYSRSn */
                __OM uint32_t TOGGLE15 : 1; /*!< [15:15] : Output togger bit for this pin, Reset type : SYSRSn */
                __OM uint32_t TOGGLE16 : 1; /*!< [16:16] : Output togger bit for this pin, Reset type : SYSRSn */
                __OM uint32_t TOGGLE17 : 1; /*!< [17:17] : Output togger bit for this pin, Reset type : SYSRSn */
                __OM uint32_t TOGGLE18 : 1; /*!< [18:18] : Output togger bit for this pin, Reset type : SYSRSn */
                __OM uint32_t TOGGLE19 : 1; /*!< [19:19] : Output togger bit for this pin, Reset type : SYSRSn */
                __OM uint32_t TOGGLE20 : 1; /*!< [20:20] : Output togger bit for this pin, Reset type : SYSRSn */
                __OM uint32_t TOGGLE21 : 1; /*!< [21:21] : Output togger bit for this pin, Reset type : SYSRSn */
                __OM uint32_t TOGGLE22 : 1; /*!< [22:22] : Output togger bit for this pin, Reset type : SYSRSn */
                __OM uint32_t TOGGLE23 : 1; /*!< [23:23] : Output togger bit for this pin, Reset type : SYSRSn */
                __OM uint32_t TOGGLE24 : 1; /*!< [24:24] : Output togger bit for this pin, Reset type : SYSRSn */
                __OM uint32_t TOGGLE25 : 1; /*!< [25:25] : Output togger bit for this pin, Reset type : SYSRSn */
                __OM uint32_t TOGGLE26 : 1; /*!< [26:26] : Output togger bit for this pin, Reset type : SYSRSn */
                __OM uint32_t TOGGLE27 : 1; /*!< [27:27] : Output togger bit for this pin, Reset type : SYSRSn */
                __OM uint32_t TOGGLE28 : 1; /*!< [28:28] : Output togger bit for this pin, Reset type : SYSRSn */
                __OM uint32_t TOGGLE29 : 1; /*!< [29:29] : Output togger bit for this pin, Reset type : SYSRSn */
                __OM uint32_t TOGGLE30 : 1; /*!< [30:30] : Output togger bit for this pin, Reset type : SYSRSn */
                __OM uint32_t TOGGLE31 : 1; /*!< [31:31] : Output togger bit for this pin, Reset type : SYSRSn */
            } TOGGLEb;
        };
    } PORT[6]; /*!< Offset: 0x0 + 0x80 * n, GPIO Port */
} GPIO_DATA_Type;

/*!
 * @}
 */

/*!
 * \name GPIO DATA Base Address Definitions
 *
 * @{
 */

/*! \brief GPIO DATA base address. */
#define GPIO_DATA_BASE (0x41301000UL)
/*! \brief GPIO DATA base pointer. */
#define GPIO_DATA ((GPIO_DATA_Type *) GPIO_DATA_BASE)

/*!
 * @}
 */

/*!
 * \name GPIO DATA Register Bitfield Definitions
 *
 * @{
 */

/* DAT bitfield */
#define GPIO_DATA_DAT_DAT31_Pos (31U)                             /*!< DAT31 Postion   */
#define GPIO_DATA_DAT_DAT31_Msk (0x1U << GPIO_DATA_DAT_DAT31_Pos) /*!< DAT31 Mask      */
#define GPIO_DATA_DAT_DAT31_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_DAT_DAT31_Pos) & GPIO_DATA_DAT_DAT31_Msk) /*!< DAT31 Set Value */
#define GPIO_DATA_DAT_DAT31_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_DAT_DAT31_Msk) >> GPIO_DATA_DAT_DAT31_Pos) /*!< DAT31 Get Value */

#define GPIO_DATA_DAT_DAT30_Pos (30U)                             /*!< DAT30 Postion   */
#define GPIO_DATA_DAT_DAT30_Msk (0x1U << GPIO_DATA_DAT_DAT30_Pos) /*!< DAT30 Mask      */
#define GPIO_DATA_DAT_DAT30_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_DAT_DAT30_Pos) & GPIO_DATA_DAT_DAT30_Msk) /*!< DAT30 Set Value */
#define GPIO_DATA_DAT_DAT30_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_DAT_DAT30_Msk) >> GPIO_DATA_DAT_DAT30_Pos) /*!< DAT30 Get Value */

#define GPIO_DATA_DAT_DAT29_Pos (29U)                             /*!< DAT29 Postion   */
#define GPIO_DATA_DAT_DAT29_Msk (0x1U << GPIO_DATA_DAT_DAT29_Pos) /*!< DAT29 Mask      */
#define GPIO_DATA_DAT_DAT29_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_DAT_DAT29_Pos) & GPIO_DATA_DAT_DAT29_Msk) /*!< DAT29 Set Value */
#define GPIO_DATA_DAT_DAT29_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_DAT_DAT29_Msk) >> GPIO_DATA_DAT_DAT29_Pos) /*!< DAT29 Get Value */

#define GPIO_DATA_DAT_DAT28_Pos (28U)                             /*!< DAT28 Postion   */
#define GPIO_DATA_DAT_DAT28_Msk (0x1U << GPIO_DATA_DAT_DAT28_Pos) /*!< DAT28 Mask      */
#define GPIO_DATA_DAT_DAT28_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_DAT_DAT28_Pos) & GPIO_DATA_DAT_DAT28_Msk) /*!< DAT28 Set Value */
#define GPIO_DATA_DAT_DAT28_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_DAT_DAT28_Msk) >> GPIO_DATA_DAT_DAT28_Pos) /*!< DAT28 Get Value */

#define GPIO_DATA_DAT_DAT27_Pos (27U)                             /*!< DAT27 Postion   */
#define GPIO_DATA_DAT_DAT27_Msk (0x1U << GPIO_DATA_DAT_DAT27_Pos) /*!< DAT27 Mask      */
#define GPIO_DATA_DAT_DAT27_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_DAT_DAT27_Pos) & GPIO_DATA_DAT_DAT27_Msk) /*!< DAT27 Set Value */
#define GPIO_DATA_DAT_DAT27_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_DAT_DAT27_Msk) >> GPIO_DATA_DAT_DAT27_Pos) /*!< DAT27 Get Value */

#define GPIO_DATA_DAT_DAT26_Pos (26U)                             /*!< DAT26 Postion   */
#define GPIO_DATA_DAT_DAT26_Msk (0x1U << GPIO_DATA_DAT_DAT26_Pos) /*!< DAT26 Mask      */
#define GPIO_DATA_DAT_DAT26_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_DAT_DAT26_Pos) & GPIO_DATA_DAT_DAT26_Msk) /*!< DAT26 Set Value */
#define GPIO_DATA_DAT_DAT26_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_DAT_DAT26_Msk) >> GPIO_DATA_DAT_DAT26_Pos) /*!< DAT26 Get Value */

#define GPIO_DATA_DAT_DAT25_Pos (25U)                             /*!< DAT25 Postion   */
#define GPIO_DATA_DAT_DAT25_Msk (0x1U << GPIO_DATA_DAT_DAT25_Pos) /*!< DAT25 Mask      */
#define GPIO_DATA_DAT_DAT25_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_DAT_DAT25_Pos) & GPIO_DATA_DAT_DAT25_Msk) /*!< DAT25 Set Value */
#define GPIO_DATA_DAT_DAT25_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_DAT_DAT25_Msk) >> GPIO_DATA_DAT_DAT25_Pos) /*!< DAT25 Get Value */

#define GPIO_DATA_DAT_DAT24_Pos (24U)                             /*!< DAT24 Postion   */
#define GPIO_DATA_DAT_DAT24_Msk (0x1U << GPIO_DATA_DAT_DAT24_Pos) /*!< DAT24 Mask      */
#define GPIO_DATA_DAT_DAT24_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_DAT_DAT24_Pos) & GPIO_DATA_DAT_DAT24_Msk) /*!< DAT24 Set Value */
#define GPIO_DATA_DAT_DAT24_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_DAT_DAT24_Msk) >> GPIO_DATA_DAT_DAT24_Pos) /*!< DAT24 Get Value */

#define GPIO_DATA_DAT_DAT23_Pos (23U)                             /*!< DAT23 Postion   */
#define GPIO_DATA_DAT_DAT23_Msk (0x1U << GPIO_DATA_DAT_DAT23_Pos) /*!< DAT23 Mask      */
#define GPIO_DATA_DAT_DAT23_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_DAT_DAT23_Pos) & GPIO_DATA_DAT_DAT23_Msk) /*!< DAT23 Set Value */
#define GPIO_DATA_DAT_DAT23_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_DAT_DAT23_Msk) >> GPIO_DATA_DAT_DAT23_Pos) /*!< DAT23 Get Value */

#define GPIO_DATA_DAT_DAT22_Pos (22U)                             /*!< DAT22 Postion   */
#define GPIO_DATA_DAT_DAT22_Msk (0x1U << GPIO_DATA_DAT_DAT22_Pos) /*!< DAT22 Mask      */
#define GPIO_DATA_DAT_DAT22_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_DAT_DAT22_Pos) & GPIO_DATA_DAT_DAT22_Msk) /*!< DAT22 Set Value */
#define GPIO_DATA_DAT_DAT22_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_DAT_DAT22_Msk) >> GPIO_DATA_DAT_DAT22_Pos) /*!< DAT22 Get Value */

#define GPIO_DATA_DAT_DAT21_Pos (21U)                             /*!< DAT21 Postion   */
#define GPIO_DATA_DAT_DAT21_Msk (0x1U << GPIO_DATA_DAT_DAT21_Pos) /*!< DAT21 Mask      */
#define GPIO_DATA_DAT_DAT21_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_DAT_DAT21_Pos) & GPIO_DATA_DAT_DAT21_Msk) /*!< DAT21 Set Value */
#define GPIO_DATA_DAT_DAT21_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_DAT_DAT21_Msk) >> GPIO_DATA_DAT_DAT21_Pos) /*!< DAT21 Get Value */

#define GPIO_DATA_DAT_DAT20_Pos (20U)                             /*!< DAT20 Postion   */
#define GPIO_DATA_DAT_DAT20_Msk (0x1U << GPIO_DATA_DAT_DAT20_Pos) /*!< DAT20 Mask      */
#define GPIO_DATA_DAT_DAT20_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_DAT_DAT20_Pos) & GPIO_DATA_DAT_DAT20_Msk) /*!< DAT20 Set Value */
#define GPIO_DATA_DAT_DAT20_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_DAT_DAT20_Msk) >> GPIO_DATA_DAT_DAT20_Pos) /*!< DAT20 Get Value */

#define GPIO_DATA_DAT_DAT19_Pos (19U)                             /*!< DAT19 Postion   */
#define GPIO_DATA_DAT_DAT19_Msk (0x1U << GPIO_DATA_DAT_DAT19_Pos) /*!< DAT19 Mask      */
#define GPIO_DATA_DAT_DAT19_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_DAT_DAT19_Pos) & GPIO_DATA_DAT_DAT19_Msk) /*!< DAT19 Set Value */
#define GPIO_DATA_DAT_DAT19_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_DAT_DAT19_Msk) >> GPIO_DATA_DAT_DAT19_Pos) /*!< DAT19 Get Value */

#define GPIO_DATA_DAT_DAT18_Pos (18U)                             /*!< DAT18 Postion   */
#define GPIO_DATA_DAT_DAT18_Msk (0x1U << GPIO_DATA_DAT_DAT18_Pos) /*!< DAT18 Mask      */
#define GPIO_DATA_DAT_DAT18_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_DAT_DAT18_Pos) & GPIO_DATA_DAT_DAT18_Msk) /*!< DAT18 Set Value */
#define GPIO_DATA_DAT_DAT18_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_DAT_DAT18_Msk) >> GPIO_DATA_DAT_DAT18_Pos) /*!< DAT18 Get Value */

#define GPIO_DATA_DAT_DAT17_Pos (17U)                             /*!< DAT17 Postion   */
#define GPIO_DATA_DAT_DAT17_Msk (0x1U << GPIO_DATA_DAT_DAT17_Pos) /*!< DAT17 Mask      */
#define GPIO_DATA_DAT_DAT17_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_DAT_DAT17_Pos) & GPIO_DATA_DAT_DAT17_Msk) /*!< DAT17 Set Value */
#define GPIO_DATA_DAT_DAT17_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_DAT_DAT17_Msk) >> GPIO_DATA_DAT_DAT17_Pos) /*!< DAT17 Get Value */

#define GPIO_DATA_DAT_DAT16_Pos (16U)                             /*!< DAT16 Postion   */
#define GPIO_DATA_DAT_DAT16_Msk (0x1U << GPIO_DATA_DAT_DAT16_Pos) /*!< DAT16 Mask      */
#define GPIO_DATA_DAT_DAT16_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_DAT_DAT16_Pos) & GPIO_DATA_DAT_DAT16_Msk) /*!< DAT16 Set Value */
#define GPIO_DATA_DAT_DAT16_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_DAT_DAT16_Msk) >> GPIO_DATA_DAT_DAT16_Pos) /*!< DAT16 Get Value */

#define GPIO_DATA_DAT_DAT15_Pos (15U)                             /*!< DAT15 Postion   */
#define GPIO_DATA_DAT_DAT15_Msk (0x1U << GPIO_DATA_DAT_DAT15_Pos) /*!< DAT15 Mask      */
#define GPIO_DATA_DAT_DAT15_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_DAT_DAT15_Pos) & GPIO_DATA_DAT_DAT15_Msk) /*!< DAT15 Set Value */
#define GPIO_DATA_DAT_DAT15_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_DAT_DAT15_Msk) >> GPIO_DATA_DAT_DAT15_Pos) /*!< DAT15 Get Value */

#define GPIO_DATA_DAT_DAT14_Pos (14U)                             /*!< DAT14 Postion   */
#define GPIO_DATA_DAT_DAT14_Msk (0x1U << GPIO_DATA_DAT_DAT14_Pos) /*!< DAT14 Mask      */
#define GPIO_DATA_DAT_DAT14_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_DAT_DAT14_Pos) & GPIO_DATA_DAT_DAT14_Msk) /*!< DAT14 Set Value */
#define GPIO_DATA_DAT_DAT14_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_DAT_DAT14_Msk) >> GPIO_DATA_DAT_DAT14_Pos) /*!< DAT14 Get Value */

#define GPIO_DATA_DAT_DAT13_Pos (13U)                             /*!< DAT13 Postion   */
#define GPIO_DATA_DAT_DAT13_Msk (0x1U << GPIO_DATA_DAT_DAT13_Pos) /*!< DAT13 Mask      */
#define GPIO_DATA_DAT_DAT13_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_DAT_DAT13_Pos) & GPIO_DATA_DAT_DAT13_Msk) /*!< DAT13 Set Value */
#define GPIO_DATA_DAT_DAT13_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_DAT_DAT13_Msk) >> GPIO_DATA_DAT_DAT13_Pos) /*!< DAT13 Get Value */

#define GPIO_DATA_DAT_DAT12_Pos (12U)                             /*!< DAT12 Postion   */
#define GPIO_DATA_DAT_DAT12_Msk (0x1U << GPIO_DATA_DAT_DAT12_Pos) /*!< DAT12 Mask      */
#define GPIO_DATA_DAT_DAT12_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_DAT_DAT12_Pos) & GPIO_DATA_DAT_DAT12_Msk) /*!< DAT12 Set Value */
#define GPIO_DATA_DAT_DAT12_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_DAT_DAT12_Msk) >> GPIO_DATA_DAT_DAT12_Pos) /*!< DAT12 Get Value */

#define GPIO_DATA_DAT_DAT11_Pos (11U)                             /*!< DAT11 Postion   */
#define GPIO_DATA_DAT_DAT11_Msk (0x1U << GPIO_DATA_DAT_DAT11_Pos) /*!< DAT11 Mask      */
#define GPIO_DATA_DAT_DAT11_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_DAT_DAT11_Pos) & GPIO_DATA_DAT_DAT11_Msk) /*!< DAT11 Set Value */
#define GPIO_DATA_DAT_DAT11_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_DAT_DAT11_Msk) >> GPIO_DATA_DAT_DAT11_Pos) /*!< DAT11 Get Value */

#define GPIO_DATA_DAT_DAT10_Pos (10U)                             /*!< DAT10 Postion   */
#define GPIO_DATA_DAT_DAT10_Msk (0x1U << GPIO_DATA_DAT_DAT10_Pos) /*!< DAT10 Mask      */
#define GPIO_DATA_DAT_DAT10_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_DAT_DAT10_Pos) & GPIO_DATA_DAT_DAT10_Msk) /*!< DAT10 Set Value */
#define GPIO_DATA_DAT_DAT10_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_DAT_DAT10_Msk) >> GPIO_DATA_DAT_DAT10_Pos) /*!< DAT10 Get Value */

#define GPIO_DATA_DAT_DAT9_Pos (9U)                             /*!< DAT9 Postion   */
#define GPIO_DATA_DAT_DAT9_Msk (0x1U << GPIO_DATA_DAT_DAT9_Pos) /*!< DAT9 Mask      */
#define GPIO_DATA_DAT_DAT9_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_DAT_DAT9_Pos) & GPIO_DATA_DAT_DAT9_Msk) /*!< DAT9 Set Value */
#define GPIO_DATA_DAT_DAT9_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_DAT_DAT9_Msk) >> GPIO_DATA_DAT_DAT9_Pos) /*!< DAT9 Get Value */

#define GPIO_DATA_DAT_DAT8_Pos (8U)                             /*!< DAT8 Postion   */
#define GPIO_DATA_DAT_DAT8_Msk (0x1U << GPIO_DATA_DAT_DAT8_Pos) /*!< DAT8 Mask      */
#define GPIO_DATA_DAT_DAT8_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_DAT_DAT8_Pos) & GPIO_DATA_DAT_DAT8_Msk) /*!< DAT8 Set Value */
#define GPIO_DATA_DAT_DAT8_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_DAT_DAT8_Msk) >> GPIO_DATA_DAT_DAT8_Pos) /*!< DAT8 Get Value */

#define GPIO_DATA_DAT_DAT7_Pos (7U)                             /*!< DAT7 Postion   */
#define GPIO_DATA_DAT_DAT7_Msk (0x1U << GPIO_DATA_DAT_DAT7_Pos) /*!< DAT7 Mask      */
#define GPIO_DATA_DAT_DAT7_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_DAT_DAT7_Pos) & GPIO_DATA_DAT_DAT7_Msk) /*!< DAT7 Set Value */
#define GPIO_DATA_DAT_DAT7_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_DAT_DAT7_Msk) >> GPIO_DATA_DAT_DAT7_Pos) /*!< DAT7 Get Value */

#define GPIO_DATA_DAT_DAT6_Pos (6U)                             /*!< DAT6 Postion   */
#define GPIO_DATA_DAT_DAT6_Msk (0x1U << GPIO_DATA_DAT_DAT6_Pos) /*!< DAT6 Mask      */
#define GPIO_DATA_DAT_DAT6_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_DAT_DAT6_Pos) & GPIO_DATA_DAT_DAT6_Msk) /*!< DAT6 Set Value */
#define GPIO_DATA_DAT_DAT6_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_DAT_DAT6_Msk) >> GPIO_DATA_DAT_DAT6_Pos) /*!< DAT6 Get Value */

#define GPIO_DATA_DAT_DAT5_Pos (5U)                             /*!< DAT5 Postion   */
#define GPIO_DATA_DAT_DAT5_Msk (0x1U << GPIO_DATA_DAT_DAT5_Pos) /*!< DAT5 Mask      */
#define GPIO_DATA_DAT_DAT5_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_DAT_DAT5_Pos) & GPIO_DATA_DAT_DAT5_Msk) /*!< DAT5 Set Value */
#define GPIO_DATA_DAT_DAT5_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_DAT_DAT5_Msk) >> GPIO_DATA_DAT_DAT5_Pos) /*!< DAT5 Get Value */

#define GPIO_DATA_DAT_DAT4_Pos (4U)                             /*!< DAT4 Postion   */
#define GPIO_DATA_DAT_DAT4_Msk (0x1U << GPIO_DATA_DAT_DAT4_Pos) /*!< DAT4 Mask      */
#define GPIO_DATA_DAT_DAT4_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_DAT_DAT4_Pos) & GPIO_DATA_DAT_DAT4_Msk) /*!< DAT4 Set Value */
#define GPIO_DATA_DAT_DAT4_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_DAT_DAT4_Msk) >> GPIO_DATA_DAT_DAT4_Pos) /*!< DAT4 Get Value */

#define GPIO_DATA_DAT_DAT3_Pos (3U)                             /*!< DAT3 Postion   */
#define GPIO_DATA_DAT_DAT3_Msk (0x1U << GPIO_DATA_DAT_DAT3_Pos) /*!< DAT3 Mask      */
#define GPIO_DATA_DAT_DAT3_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_DAT_DAT3_Pos) & GPIO_DATA_DAT_DAT3_Msk) /*!< DAT3 Set Value */
#define GPIO_DATA_DAT_DAT3_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_DAT_DAT3_Msk) >> GPIO_DATA_DAT_DAT3_Pos) /*!< DAT3 Get Value */

#define GPIO_DATA_DAT_DAT2_Pos (2U)                             /*!< DAT2 Postion   */
#define GPIO_DATA_DAT_DAT2_Msk (0x1U << GPIO_DATA_DAT_DAT2_Pos) /*!< DAT2 Mask      */
#define GPIO_DATA_DAT_DAT2_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_DAT_DAT2_Pos) & GPIO_DATA_DAT_DAT2_Msk) /*!< DAT2 Set Value */
#define GPIO_DATA_DAT_DAT2_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_DAT_DAT2_Msk) >> GPIO_DATA_DAT_DAT2_Pos) /*!< DAT2 Get Value */

#define GPIO_DATA_DAT_DAT1_Pos (1U)                             /*!< DAT1 Postion   */
#define GPIO_DATA_DAT_DAT1_Msk (0x1U << GPIO_DATA_DAT_DAT1_Pos) /*!< DAT1 Mask      */
#define GPIO_DATA_DAT_DAT1_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_DAT_DAT1_Pos) & GPIO_DATA_DAT_DAT1_Msk) /*!< DAT1 Set Value */
#define GPIO_DATA_DAT_DAT1_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_DAT_DAT1_Msk) >> GPIO_DATA_DAT_DAT1_Pos) /*!< DAT1 Get Value */

#define GPIO_DATA_DAT_DAT0_Pos (0U)                             /*!< DAT0 Postion   */
#define GPIO_DATA_DAT_DAT0_Msk (0x1U << GPIO_DATA_DAT_DAT0_Pos) /*!< DAT0 Mask      */
#define GPIO_DATA_DAT_DAT0_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_DAT_DAT0_Pos) & GPIO_DATA_DAT_DAT0_Msk) /*!< DAT0 Set Value */
#define GPIO_DATA_DAT_DAT0_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_DAT_DAT0_Msk) >> GPIO_DATA_DAT_DAT0_Pos) /*!< DAT0 Get Value */

/* SET bitfield */
#define GPIO_DATA_SET_SET31_Pos (31U)                             /*!< SET31 Postion   */
#define GPIO_DATA_SET_SET31_Msk (0x1U << GPIO_DATA_SET_SET31_Pos) /*!< SET31 Mask      */
#define GPIO_DATA_SET_SET31_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_SET_SET31_Pos) & GPIO_DATA_SET_SET31_Msk) /*!< SET31 Set Value */
#define GPIO_DATA_SET_SET31_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_SET_SET31_Msk) >> GPIO_DATA_SET_SET31_Pos) /*!< SET31 Get Value */

#define GPIO_DATA_SET_SET30_Pos (30U)                             /*!< SET30 Postion   */
#define GPIO_DATA_SET_SET30_Msk (0x1U << GPIO_DATA_SET_SET30_Pos) /*!< SET30 Mask      */
#define GPIO_DATA_SET_SET30_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_SET_SET30_Pos) & GPIO_DATA_SET_SET30_Msk) /*!< SET30 Set Value */
#define GPIO_DATA_SET_SET30_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_SET_SET30_Msk) >> GPIO_DATA_SET_SET30_Pos) /*!< SET30 Get Value */

#define GPIO_DATA_SET_SET29_Pos (29U)                             /*!< SET29 Postion   */
#define GPIO_DATA_SET_SET29_Msk (0x1U << GPIO_DATA_SET_SET29_Pos) /*!< SET29 Mask      */
#define GPIO_DATA_SET_SET29_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_SET_SET29_Pos) & GPIO_DATA_SET_SET29_Msk) /*!< SET29 Set Value */
#define GPIO_DATA_SET_SET29_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_SET_SET29_Msk) >> GPIO_DATA_SET_SET29_Pos) /*!< SET29 Get Value */

#define GPIO_DATA_SET_SET28_Pos (28U)                             /*!< SET28 Postion   */
#define GPIO_DATA_SET_SET28_Msk (0x1U << GPIO_DATA_SET_SET28_Pos) /*!< SET28 Mask      */
#define GPIO_DATA_SET_SET28_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_SET_SET28_Pos) & GPIO_DATA_SET_SET28_Msk) /*!< SET28 Set Value */
#define GPIO_DATA_SET_SET28_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_SET_SET28_Msk) >> GPIO_DATA_SET_SET28_Pos) /*!< SET28 Get Value */

#define GPIO_DATA_SET_SET27_Pos (27U)                             /*!< SET27 Postion   */
#define GPIO_DATA_SET_SET27_Msk (0x1U << GPIO_DATA_SET_SET27_Pos) /*!< SET27 Mask      */
#define GPIO_DATA_SET_SET27_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_SET_SET27_Pos) & GPIO_DATA_SET_SET27_Msk) /*!< SET27 Set Value */
#define GPIO_DATA_SET_SET27_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_SET_SET27_Msk) >> GPIO_DATA_SET_SET27_Pos) /*!< SET27 Get Value */

#define GPIO_DATA_SET_SET26_Pos (26U)                             /*!< SET26 Postion   */
#define GPIO_DATA_SET_SET26_Msk (0x1U << GPIO_DATA_SET_SET26_Pos) /*!< SET26 Mask      */
#define GPIO_DATA_SET_SET26_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_SET_SET26_Pos) & GPIO_DATA_SET_SET26_Msk) /*!< SET26 Set Value */
#define GPIO_DATA_SET_SET26_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_SET_SET26_Msk) >> GPIO_DATA_SET_SET26_Pos) /*!< SET26 Get Value */

#define GPIO_DATA_SET_SET25_Pos (25U)                             /*!< SET25 Postion   */
#define GPIO_DATA_SET_SET25_Msk (0x1U << GPIO_DATA_SET_SET25_Pos) /*!< SET25 Mask      */
#define GPIO_DATA_SET_SET25_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_SET_SET25_Pos) & GPIO_DATA_SET_SET25_Msk) /*!< SET25 Set Value */
#define GPIO_DATA_SET_SET25_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_SET_SET25_Msk) >> GPIO_DATA_SET_SET25_Pos) /*!< SET25 Get Value */

#define GPIO_DATA_SET_SET24_Pos (24U)                             /*!< SET24 Postion   */
#define GPIO_DATA_SET_SET24_Msk (0x1U << GPIO_DATA_SET_SET24_Pos) /*!< SET24 Mask      */
#define GPIO_DATA_SET_SET24_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_SET_SET24_Pos) & GPIO_DATA_SET_SET24_Msk) /*!< SET24 Set Value */
#define GPIO_DATA_SET_SET24_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_SET_SET24_Msk) >> GPIO_DATA_SET_SET24_Pos) /*!< SET24 Get Value */

#define GPIO_DATA_SET_SET23_Pos (23U)                             /*!< SET23 Postion   */
#define GPIO_DATA_SET_SET23_Msk (0x1U << GPIO_DATA_SET_SET23_Pos) /*!< SET23 Mask      */
#define GPIO_DATA_SET_SET23_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_SET_SET23_Pos) & GPIO_DATA_SET_SET23_Msk) /*!< SET23 Set Value */
#define GPIO_DATA_SET_SET23_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_SET_SET23_Msk) >> GPIO_DATA_SET_SET23_Pos) /*!< SET23 Get Value */

#define GPIO_DATA_SET_SET22_Pos (22U)                             /*!< SET22 Postion   */
#define GPIO_DATA_SET_SET22_Msk (0x1U << GPIO_DATA_SET_SET22_Pos) /*!< SET22 Mask      */
#define GPIO_DATA_SET_SET22_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_SET_SET22_Pos) & GPIO_DATA_SET_SET22_Msk) /*!< SET22 Set Value */
#define GPIO_DATA_SET_SET22_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_SET_SET22_Msk) >> GPIO_DATA_SET_SET22_Pos) /*!< SET22 Get Value */

#define GPIO_DATA_SET_SET21_Pos (21U)                             /*!< SET21 Postion   */
#define GPIO_DATA_SET_SET21_Msk (0x1U << GPIO_DATA_SET_SET21_Pos) /*!< SET21 Mask      */
#define GPIO_DATA_SET_SET21_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_SET_SET21_Pos) & GPIO_DATA_SET_SET21_Msk) /*!< SET21 Set Value */
#define GPIO_DATA_SET_SET21_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_SET_SET21_Msk) >> GPIO_DATA_SET_SET21_Pos) /*!< SET21 Get Value */

#define GPIO_DATA_SET_SET20_Pos (20U)                             /*!< SET20 Postion   */
#define GPIO_DATA_SET_SET20_Msk (0x1U << GPIO_DATA_SET_SET20_Pos) /*!< SET20 Mask      */
#define GPIO_DATA_SET_SET20_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_SET_SET20_Pos) & GPIO_DATA_SET_SET20_Msk) /*!< SET20 Set Value */
#define GPIO_DATA_SET_SET20_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_SET_SET20_Msk) >> GPIO_DATA_SET_SET20_Pos) /*!< SET20 Get Value */

#define GPIO_DATA_SET_SET19_Pos (19U)                             /*!< SET19 Postion   */
#define GPIO_DATA_SET_SET19_Msk (0x1U << GPIO_DATA_SET_SET19_Pos) /*!< SET19 Mask      */
#define GPIO_DATA_SET_SET19_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_SET_SET19_Pos) & GPIO_DATA_SET_SET19_Msk) /*!< SET19 Set Value */
#define GPIO_DATA_SET_SET19_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_SET_SET19_Msk) >> GPIO_DATA_SET_SET19_Pos) /*!< SET19 Get Value */

#define GPIO_DATA_SET_SET18_Pos (18U)                             /*!< SET18 Postion   */
#define GPIO_DATA_SET_SET18_Msk (0x1U << GPIO_DATA_SET_SET18_Pos) /*!< SET18 Mask      */
#define GPIO_DATA_SET_SET18_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_SET_SET18_Pos) & GPIO_DATA_SET_SET18_Msk) /*!< SET18 Set Value */
#define GPIO_DATA_SET_SET18_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_SET_SET18_Msk) >> GPIO_DATA_SET_SET18_Pos) /*!< SET18 Get Value */

#define GPIO_DATA_SET_SET17_Pos (17U)                             /*!< SET17 Postion   */
#define GPIO_DATA_SET_SET17_Msk (0x1U << GPIO_DATA_SET_SET17_Pos) /*!< SET17 Mask      */
#define GPIO_DATA_SET_SET17_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_SET_SET17_Pos) & GPIO_DATA_SET_SET17_Msk) /*!< SET17 Set Value */
#define GPIO_DATA_SET_SET17_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_SET_SET17_Msk) >> GPIO_DATA_SET_SET17_Pos) /*!< SET17 Get Value */

#define GPIO_DATA_SET_SET16_Pos (16U)                             /*!< SET16 Postion   */
#define GPIO_DATA_SET_SET16_Msk (0x1U << GPIO_DATA_SET_SET16_Pos) /*!< SET16 Mask      */
#define GPIO_DATA_SET_SET16_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_SET_SET16_Pos) & GPIO_DATA_SET_SET16_Msk) /*!< SET16 Set Value */
#define GPIO_DATA_SET_SET16_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_SET_SET16_Msk) >> GPIO_DATA_SET_SET16_Pos) /*!< SET16 Get Value */

#define GPIO_DATA_SET_SET15_Pos (15U)                             /*!< SET15 Postion   */
#define GPIO_DATA_SET_SET15_Msk (0x1U << GPIO_DATA_SET_SET15_Pos) /*!< SET15 Mask      */
#define GPIO_DATA_SET_SET15_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_SET_SET15_Pos) & GPIO_DATA_SET_SET15_Msk) /*!< SET15 Set Value */
#define GPIO_DATA_SET_SET15_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_SET_SET15_Msk) >> GPIO_DATA_SET_SET15_Pos) /*!< SET15 Get Value */

#define GPIO_DATA_SET_SET14_Pos (14U)                             /*!< SET14 Postion   */
#define GPIO_DATA_SET_SET14_Msk (0x1U << GPIO_DATA_SET_SET14_Pos) /*!< SET14 Mask      */
#define GPIO_DATA_SET_SET14_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_SET_SET14_Pos) & GPIO_DATA_SET_SET14_Msk) /*!< SET14 Set Value */
#define GPIO_DATA_SET_SET14_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_SET_SET14_Msk) >> GPIO_DATA_SET_SET14_Pos) /*!< SET14 Get Value */

#define GPIO_DATA_SET_SET13_Pos (13U)                             /*!< SET13 Postion   */
#define GPIO_DATA_SET_SET13_Msk (0x1U << GPIO_DATA_SET_SET13_Pos) /*!< SET13 Mask      */
#define GPIO_DATA_SET_SET13_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_SET_SET13_Pos) & GPIO_DATA_SET_SET13_Msk) /*!< SET13 Set Value */
#define GPIO_DATA_SET_SET13_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_SET_SET13_Msk) >> GPIO_DATA_SET_SET13_Pos) /*!< SET13 Get Value */

#define GPIO_DATA_SET_SET12_Pos (12U)                             /*!< SET12 Postion   */
#define GPIO_DATA_SET_SET12_Msk (0x1U << GPIO_DATA_SET_SET12_Pos) /*!< SET12 Mask      */
#define GPIO_DATA_SET_SET12_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_SET_SET12_Pos) & GPIO_DATA_SET_SET12_Msk) /*!< SET12 Set Value */
#define GPIO_DATA_SET_SET12_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_SET_SET12_Msk) >> GPIO_DATA_SET_SET12_Pos) /*!< SET12 Get Value */

#define GPIO_DATA_SET_SET11_Pos (11U)                             /*!< SET11 Postion   */
#define GPIO_DATA_SET_SET11_Msk (0x1U << GPIO_DATA_SET_SET11_Pos) /*!< SET11 Mask      */
#define GPIO_DATA_SET_SET11_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_SET_SET11_Pos) & GPIO_DATA_SET_SET11_Msk) /*!< SET11 Set Value */
#define GPIO_DATA_SET_SET11_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_SET_SET11_Msk) >> GPIO_DATA_SET_SET11_Pos) /*!< SET11 Get Value */

#define GPIO_DATA_SET_SET10_Pos (10U)                             /*!< SET10 Postion   */
#define GPIO_DATA_SET_SET10_Msk (0x1U << GPIO_DATA_SET_SET10_Pos) /*!< SET10 Mask      */
#define GPIO_DATA_SET_SET10_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_SET_SET10_Pos) & GPIO_DATA_SET_SET10_Msk) /*!< SET10 Set Value */
#define GPIO_DATA_SET_SET10_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_SET_SET10_Msk) >> GPIO_DATA_SET_SET10_Pos) /*!< SET10 Get Value */

#define GPIO_DATA_SET_SET9_Pos (9U)                             /*!< SET9 Postion   */
#define GPIO_DATA_SET_SET9_Msk (0x1U << GPIO_DATA_SET_SET9_Pos) /*!< SET9 Mask      */
#define GPIO_DATA_SET_SET9_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_SET_SET9_Pos) & GPIO_DATA_SET_SET9_Msk) /*!< SET9 Set Value */
#define GPIO_DATA_SET_SET9_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_SET_SET9_Msk) >> GPIO_DATA_SET_SET9_Pos) /*!< SET9 Get Value */

#define GPIO_DATA_SET_SET8_Pos (8U)                             /*!< SET8 Postion   */
#define GPIO_DATA_SET_SET8_Msk (0x1U << GPIO_DATA_SET_SET8_Pos) /*!< SET8 Mask      */
#define GPIO_DATA_SET_SET8_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_SET_SET8_Pos) & GPIO_DATA_SET_SET8_Msk) /*!< SET8 Set Value */
#define GPIO_DATA_SET_SET8_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_SET_SET8_Msk) >> GPIO_DATA_SET_SET8_Pos) /*!< SET8 Get Value */

#define GPIO_DATA_SET_SET7_Pos (7U)                             /*!< SET7 Postion   */
#define GPIO_DATA_SET_SET7_Msk (0x1U << GPIO_DATA_SET_SET7_Pos) /*!< SET7 Mask      */
#define GPIO_DATA_SET_SET7_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_SET_SET7_Pos) & GPIO_DATA_SET_SET7_Msk) /*!< SET7 Set Value */
#define GPIO_DATA_SET_SET7_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_SET_SET7_Msk) >> GPIO_DATA_SET_SET7_Pos) /*!< SET7 Get Value */

#define GPIO_DATA_SET_SET6_Pos (6U)                             /*!< SET6 Postion   */
#define GPIO_DATA_SET_SET6_Msk (0x1U << GPIO_DATA_SET_SET6_Pos) /*!< SET6 Mask      */
#define GPIO_DATA_SET_SET6_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_SET_SET6_Pos) & GPIO_DATA_SET_SET6_Msk) /*!< SET6 Set Value */
#define GPIO_DATA_SET_SET6_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_SET_SET6_Msk) >> GPIO_DATA_SET_SET6_Pos) /*!< SET6 Get Value */

#define GPIO_DATA_SET_SET5_Pos (5U)                             /*!< SET5 Postion   */
#define GPIO_DATA_SET_SET5_Msk (0x1U << GPIO_DATA_SET_SET5_Pos) /*!< SET5 Mask      */
#define GPIO_DATA_SET_SET5_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_SET_SET5_Pos) & GPIO_DATA_SET_SET5_Msk) /*!< SET5 Set Value */
#define GPIO_DATA_SET_SET5_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_SET_SET5_Msk) >> GPIO_DATA_SET_SET5_Pos) /*!< SET5 Get Value */

#define GPIO_DATA_SET_SET4_Pos (4U)                             /*!< SET4 Postion   */
#define GPIO_DATA_SET_SET4_Msk (0x1U << GPIO_DATA_SET_SET4_Pos) /*!< SET4 Mask      */
#define GPIO_DATA_SET_SET4_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_SET_SET4_Pos) & GPIO_DATA_SET_SET4_Msk) /*!< SET4 Set Value */
#define GPIO_DATA_SET_SET4_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_SET_SET4_Msk) >> GPIO_DATA_SET_SET4_Pos) /*!< SET4 Get Value */

#define GPIO_DATA_SET_SET3_Pos (3U)                             /*!< SET3 Postion   */
#define GPIO_DATA_SET_SET3_Msk (0x1U << GPIO_DATA_SET_SET3_Pos) /*!< SET3 Mask      */
#define GPIO_DATA_SET_SET3_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_SET_SET3_Pos) & GPIO_DATA_SET_SET3_Msk) /*!< SET3 Set Value */
#define GPIO_DATA_SET_SET3_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_SET_SET3_Msk) >> GPIO_DATA_SET_SET3_Pos) /*!< SET3 Get Value */

#define GPIO_DATA_SET_SET2_Pos (2U)                             /*!< SET2 Postion   */
#define GPIO_DATA_SET_SET2_Msk (0x1U << GPIO_DATA_SET_SET2_Pos) /*!< SET2 Mask      */
#define GPIO_DATA_SET_SET2_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_SET_SET2_Pos) & GPIO_DATA_SET_SET2_Msk) /*!< SET2 Set Value */
#define GPIO_DATA_SET_SET2_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_SET_SET2_Msk) >> GPIO_DATA_SET_SET2_Pos) /*!< SET2 Get Value */

#define GPIO_DATA_SET_SET1_Pos (1U)                             /*!< SET1 Postion   */
#define GPIO_DATA_SET_SET1_Msk (0x1U << GPIO_DATA_SET_SET1_Pos) /*!< SET1 Mask      */
#define GPIO_DATA_SET_SET1_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_SET_SET1_Pos) & GPIO_DATA_SET_SET1_Msk) /*!< SET1 Set Value */
#define GPIO_DATA_SET_SET1_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_SET_SET1_Msk) >> GPIO_DATA_SET_SET1_Pos) /*!< SET1 Get Value */

#define GPIO_DATA_SET_SET0_Pos (0U)                             /*!< SET0 Postion   */
#define GPIO_DATA_SET_SET0_Msk (0x1U << GPIO_DATA_SET_SET0_Pos) /*!< SET0 Mask      */
#define GPIO_DATA_SET_SET0_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_SET_SET0_Pos) & GPIO_DATA_SET_SET0_Msk) /*!< SET0 Set Value */
#define GPIO_DATA_SET_SET0_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_SET_SET0_Msk) >> GPIO_DATA_SET_SET0_Pos) /*!< SET0 Get Value */

/* CLEAR bitfield */
#define GPIO_DATA_CLEAR_CLEAR31_Pos (31U)                                 /*!< CLEAR31 Postion   */
#define GPIO_DATA_CLEAR_CLEAR31_Msk (0x1U << GPIO_DATA_CLEAR_CLEAR31_Pos) /*!< CLEAR31 Mask      */
#define GPIO_DATA_CLEAR_CLEAR31_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_CLEAR_CLEAR31_Pos) & GPIO_DATA_CLEAR_CLEAR31_Msk) /*!< CLEAR31 Set Value */
#define GPIO_DATA_CLEAR_CLEAR31_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_CLEAR_CLEAR31_Msk) >> GPIO_DATA_CLEAR_CLEAR31_Pos) /*!< CLEAR31 Get Value */

#define GPIO_DATA_CLEAR_CLEAR30_Pos (30U)                                 /*!< CLEAR30 Postion   */
#define GPIO_DATA_CLEAR_CLEAR30_Msk (0x1U << GPIO_DATA_CLEAR_CLEAR30_Pos) /*!< CLEAR30 Mask      */
#define GPIO_DATA_CLEAR_CLEAR30_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_CLEAR_CLEAR30_Pos) & GPIO_DATA_CLEAR_CLEAR30_Msk) /*!< CLEAR30 Set Value */
#define GPIO_DATA_CLEAR_CLEAR30_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_CLEAR_CLEAR30_Msk) >> GPIO_DATA_CLEAR_CLEAR30_Pos) /*!< CLEAR30 Get Value */

#define GPIO_DATA_CLEAR_CLEAR29_Pos (29U)                                 /*!< CLEAR29 Postion   */
#define GPIO_DATA_CLEAR_CLEAR29_Msk (0x1U << GPIO_DATA_CLEAR_CLEAR29_Pos) /*!< CLEAR29 Mask      */
#define GPIO_DATA_CLEAR_CLEAR29_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_CLEAR_CLEAR29_Pos) & GPIO_DATA_CLEAR_CLEAR29_Msk) /*!< CLEAR29 Set Value */
#define GPIO_DATA_CLEAR_CLEAR29_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_CLEAR_CLEAR29_Msk) >> GPIO_DATA_CLEAR_CLEAR29_Pos) /*!< CLEAR29 Get Value */

#define GPIO_DATA_CLEAR_CLEAR28_Pos (28U)                                 /*!< CLEAR28 Postion   */
#define GPIO_DATA_CLEAR_CLEAR28_Msk (0x1U << GPIO_DATA_CLEAR_CLEAR28_Pos) /*!< CLEAR28 Mask      */
#define GPIO_DATA_CLEAR_CLEAR28_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_CLEAR_CLEAR28_Pos) & GPIO_DATA_CLEAR_CLEAR28_Msk) /*!< CLEAR28 Set Value */
#define GPIO_DATA_CLEAR_CLEAR28_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_CLEAR_CLEAR28_Msk) >> GPIO_DATA_CLEAR_CLEAR28_Pos) /*!< CLEAR28 Get Value */

#define GPIO_DATA_CLEAR_CLEAR27_Pos (27U)                                 /*!< CLEAR27 Postion   */
#define GPIO_DATA_CLEAR_CLEAR27_Msk (0x1U << GPIO_DATA_CLEAR_CLEAR27_Pos) /*!< CLEAR27 Mask      */
#define GPIO_DATA_CLEAR_CLEAR27_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_CLEAR_CLEAR27_Pos) & GPIO_DATA_CLEAR_CLEAR27_Msk) /*!< CLEAR27 Set Value */
#define GPIO_DATA_CLEAR_CLEAR27_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_CLEAR_CLEAR27_Msk) >> GPIO_DATA_CLEAR_CLEAR27_Pos) /*!< CLEAR27 Get Value */

#define GPIO_DATA_CLEAR_CLEAR26_Pos (26U)                                 /*!< CLEAR26 Postion   */
#define GPIO_DATA_CLEAR_CLEAR26_Msk (0x1U << GPIO_DATA_CLEAR_CLEAR26_Pos) /*!< CLEAR26 Mask      */
#define GPIO_DATA_CLEAR_CLEAR26_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_CLEAR_CLEAR26_Pos) & GPIO_DATA_CLEAR_CLEAR26_Msk) /*!< CLEAR26 Set Value */
#define GPIO_DATA_CLEAR_CLEAR26_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_CLEAR_CLEAR26_Msk) >> GPIO_DATA_CLEAR_CLEAR26_Pos) /*!< CLEAR26 Get Value */

#define GPIO_DATA_CLEAR_CLEAR25_Pos (25U)                                 /*!< CLEAR25 Postion   */
#define GPIO_DATA_CLEAR_CLEAR25_Msk (0x1U << GPIO_DATA_CLEAR_CLEAR25_Pos) /*!< CLEAR25 Mask      */
#define GPIO_DATA_CLEAR_CLEAR25_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_CLEAR_CLEAR25_Pos) & GPIO_DATA_CLEAR_CLEAR25_Msk) /*!< CLEAR25 Set Value */
#define GPIO_DATA_CLEAR_CLEAR25_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_CLEAR_CLEAR25_Msk) >> GPIO_DATA_CLEAR_CLEAR25_Pos) /*!< CLEAR25 Get Value */

#define GPIO_DATA_CLEAR_CLEAR24_Pos (24U)                                 /*!< CLEAR24 Postion   */
#define GPIO_DATA_CLEAR_CLEAR24_Msk (0x1U << GPIO_DATA_CLEAR_CLEAR24_Pos) /*!< CLEAR24 Mask      */
#define GPIO_DATA_CLEAR_CLEAR24_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_CLEAR_CLEAR24_Pos) & GPIO_DATA_CLEAR_CLEAR24_Msk) /*!< CLEAR24 Set Value */
#define GPIO_DATA_CLEAR_CLEAR24_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_CLEAR_CLEAR24_Msk) >> GPIO_DATA_CLEAR_CLEAR24_Pos) /*!< CLEAR24 Get Value */

#define GPIO_DATA_CLEAR_CLEAR23_Pos (23U)                                 /*!< CLEAR23 Postion   */
#define GPIO_DATA_CLEAR_CLEAR23_Msk (0x1U << GPIO_DATA_CLEAR_CLEAR23_Pos) /*!< CLEAR23 Mask      */
#define GPIO_DATA_CLEAR_CLEAR23_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_CLEAR_CLEAR23_Pos) & GPIO_DATA_CLEAR_CLEAR23_Msk) /*!< CLEAR23 Set Value */
#define GPIO_DATA_CLEAR_CLEAR23_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_CLEAR_CLEAR23_Msk) >> GPIO_DATA_CLEAR_CLEAR23_Pos) /*!< CLEAR23 Get Value */

#define GPIO_DATA_CLEAR_CLEAR22_Pos (22U)                                 /*!< CLEAR22 Postion   */
#define GPIO_DATA_CLEAR_CLEAR22_Msk (0x1U << GPIO_DATA_CLEAR_CLEAR22_Pos) /*!< CLEAR22 Mask      */
#define GPIO_DATA_CLEAR_CLEAR22_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_CLEAR_CLEAR22_Pos) & GPIO_DATA_CLEAR_CLEAR22_Msk) /*!< CLEAR22 Set Value */
#define GPIO_DATA_CLEAR_CLEAR22_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_CLEAR_CLEAR22_Msk) >> GPIO_DATA_CLEAR_CLEAR22_Pos) /*!< CLEAR22 Get Value */

#define GPIO_DATA_CLEAR_CLEAR21_Pos (21U)                                 /*!< CLEAR21 Postion   */
#define GPIO_DATA_CLEAR_CLEAR21_Msk (0x1U << GPIO_DATA_CLEAR_CLEAR21_Pos) /*!< CLEAR21 Mask      */
#define GPIO_DATA_CLEAR_CLEAR21_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_CLEAR_CLEAR21_Pos) & GPIO_DATA_CLEAR_CLEAR21_Msk) /*!< CLEAR21 Set Value */
#define GPIO_DATA_CLEAR_CLEAR21_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_CLEAR_CLEAR21_Msk) >> GPIO_DATA_CLEAR_CLEAR21_Pos) /*!< CLEAR21 Get Value */

#define GPIO_DATA_CLEAR_CLEAR20_Pos (20U)                                 /*!< CLEAR20 Postion   */
#define GPIO_DATA_CLEAR_CLEAR20_Msk (0x1U << GPIO_DATA_CLEAR_CLEAR20_Pos) /*!< CLEAR20 Mask      */
#define GPIO_DATA_CLEAR_CLEAR20_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_CLEAR_CLEAR20_Pos) & GPIO_DATA_CLEAR_CLEAR20_Msk) /*!< CLEAR20 Set Value */
#define GPIO_DATA_CLEAR_CLEAR20_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_CLEAR_CLEAR20_Msk) >> GPIO_DATA_CLEAR_CLEAR20_Pos) /*!< CLEAR20 Get Value */

#define GPIO_DATA_CLEAR_CLEAR19_Pos (19U)                                 /*!< CLEAR19 Postion   */
#define GPIO_DATA_CLEAR_CLEAR19_Msk (0x1U << GPIO_DATA_CLEAR_CLEAR19_Pos) /*!< CLEAR19 Mask      */
#define GPIO_DATA_CLEAR_CLEAR19_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_CLEAR_CLEAR19_Pos) & GPIO_DATA_CLEAR_CLEAR19_Msk) /*!< CLEAR19 Set Value */
#define GPIO_DATA_CLEAR_CLEAR19_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_CLEAR_CLEAR19_Msk) >> GPIO_DATA_CLEAR_CLEAR19_Pos) /*!< CLEAR19 Get Value */

#define GPIO_DATA_CLEAR_CLEAR18_Pos (18U)                                 /*!< CLEAR18 Postion   */
#define GPIO_DATA_CLEAR_CLEAR18_Msk (0x1U << GPIO_DATA_CLEAR_CLEAR18_Pos) /*!< CLEAR18 Mask      */
#define GPIO_DATA_CLEAR_CLEAR18_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_CLEAR_CLEAR18_Pos) & GPIO_DATA_CLEAR_CLEAR18_Msk) /*!< CLEAR18 Set Value */
#define GPIO_DATA_CLEAR_CLEAR18_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_CLEAR_CLEAR18_Msk) >> GPIO_DATA_CLEAR_CLEAR18_Pos) /*!< CLEAR18 Get Value */

#define GPIO_DATA_CLEAR_CLEAR17_Pos (17U)                                 /*!< CLEAR17 Postion   */
#define GPIO_DATA_CLEAR_CLEAR17_Msk (0x1U << GPIO_DATA_CLEAR_CLEAR17_Pos) /*!< CLEAR17 Mask      */
#define GPIO_DATA_CLEAR_CLEAR17_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_CLEAR_CLEAR17_Pos) & GPIO_DATA_CLEAR_CLEAR17_Msk) /*!< CLEAR17 Set Value */
#define GPIO_DATA_CLEAR_CLEAR17_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_CLEAR_CLEAR17_Msk) >> GPIO_DATA_CLEAR_CLEAR17_Pos) /*!< CLEAR17 Get Value */

#define GPIO_DATA_CLEAR_CLEAR16_Pos (16U)                                 /*!< CLEAR16 Postion   */
#define GPIO_DATA_CLEAR_CLEAR16_Msk (0x1U << GPIO_DATA_CLEAR_CLEAR16_Pos) /*!< CLEAR16 Mask      */
#define GPIO_DATA_CLEAR_CLEAR16_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_CLEAR_CLEAR16_Pos) & GPIO_DATA_CLEAR_CLEAR16_Msk) /*!< CLEAR16 Set Value */
#define GPIO_DATA_CLEAR_CLEAR16_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_CLEAR_CLEAR16_Msk) >> GPIO_DATA_CLEAR_CLEAR16_Pos) /*!< CLEAR16 Get Value */

#define GPIO_DATA_CLEAR_CLEAR15_Pos (15U)                                 /*!< CLEAR15 Postion   */
#define GPIO_DATA_CLEAR_CLEAR15_Msk (0x1U << GPIO_DATA_CLEAR_CLEAR15_Pos) /*!< CLEAR15 Mask      */
#define GPIO_DATA_CLEAR_CLEAR15_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_CLEAR_CLEAR15_Pos) & GPIO_DATA_CLEAR_CLEAR15_Msk) /*!< CLEAR15 Set Value */
#define GPIO_DATA_CLEAR_CLEAR15_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_CLEAR_CLEAR15_Msk) >> GPIO_DATA_CLEAR_CLEAR15_Pos) /*!< CLEAR15 Get Value */

#define GPIO_DATA_CLEAR_CLEAR14_Pos (14U)                                 /*!< CLEAR14 Postion   */
#define GPIO_DATA_CLEAR_CLEAR14_Msk (0x1U << GPIO_DATA_CLEAR_CLEAR14_Pos) /*!< CLEAR14 Mask      */
#define GPIO_DATA_CLEAR_CLEAR14_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_CLEAR_CLEAR14_Pos) & GPIO_DATA_CLEAR_CLEAR14_Msk) /*!< CLEAR14 Set Value */
#define GPIO_DATA_CLEAR_CLEAR14_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_CLEAR_CLEAR14_Msk) >> GPIO_DATA_CLEAR_CLEAR14_Pos) /*!< CLEAR14 Get Value */

#define GPIO_DATA_CLEAR_CLEAR13_Pos (13U)                                 /*!< CLEAR13 Postion   */
#define GPIO_DATA_CLEAR_CLEAR13_Msk (0x1U << GPIO_DATA_CLEAR_CLEAR13_Pos) /*!< CLEAR13 Mask      */
#define GPIO_DATA_CLEAR_CLEAR13_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_CLEAR_CLEAR13_Pos) & GPIO_DATA_CLEAR_CLEAR13_Msk) /*!< CLEAR13 Set Value */
#define GPIO_DATA_CLEAR_CLEAR13_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_CLEAR_CLEAR13_Msk) >> GPIO_DATA_CLEAR_CLEAR13_Pos) /*!< CLEAR13 Get Value */

#define GPIO_DATA_CLEAR_CLEAR12_Pos (12U)                                 /*!< CLEAR12 Postion   */
#define GPIO_DATA_CLEAR_CLEAR12_Msk (0x1U << GPIO_DATA_CLEAR_CLEAR12_Pos) /*!< CLEAR12 Mask      */
#define GPIO_DATA_CLEAR_CLEAR12_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_CLEAR_CLEAR12_Pos) & GPIO_DATA_CLEAR_CLEAR12_Msk) /*!< CLEAR12 Set Value */
#define GPIO_DATA_CLEAR_CLEAR12_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_CLEAR_CLEAR12_Msk) >> GPIO_DATA_CLEAR_CLEAR12_Pos) /*!< CLEAR12 Get Value */

#define GPIO_DATA_CLEAR_CLEAR11_Pos (11U)                                 /*!< CLEAR11 Postion   */
#define GPIO_DATA_CLEAR_CLEAR11_Msk (0x1U << GPIO_DATA_CLEAR_CLEAR11_Pos) /*!< CLEAR11 Mask      */
#define GPIO_DATA_CLEAR_CLEAR11_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_CLEAR_CLEAR11_Pos) & GPIO_DATA_CLEAR_CLEAR11_Msk) /*!< CLEAR11 Set Value */
#define GPIO_DATA_CLEAR_CLEAR11_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_CLEAR_CLEAR11_Msk) >> GPIO_DATA_CLEAR_CLEAR11_Pos) /*!< CLEAR11 Get Value */

#define GPIO_DATA_CLEAR_CLEAR10_Pos (10U)                                 /*!< CLEAR10 Postion   */
#define GPIO_DATA_CLEAR_CLEAR10_Msk (0x1U << GPIO_DATA_CLEAR_CLEAR10_Pos) /*!< CLEAR10 Mask      */
#define GPIO_DATA_CLEAR_CLEAR10_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_CLEAR_CLEAR10_Pos) & GPIO_DATA_CLEAR_CLEAR10_Msk) /*!< CLEAR10 Set Value */
#define GPIO_DATA_CLEAR_CLEAR10_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_CLEAR_CLEAR10_Msk) >> GPIO_DATA_CLEAR_CLEAR10_Pos) /*!< CLEAR10 Get Value */

#define GPIO_DATA_CLEAR_CLEAR9_Pos (9U)                                 /*!< CLEAR9 Postion   */
#define GPIO_DATA_CLEAR_CLEAR9_Msk (0x1U << GPIO_DATA_CLEAR_CLEAR9_Pos) /*!< CLEAR9 Mask      */
#define GPIO_DATA_CLEAR_CLEAR9_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_CLEAR_CLEAR9_Pos) & GPIO_DATA_CLEAR_CLEAR9_Msk) /*!< CLEAR9 Set Value */
#define GPIO_DATA_CLEAR_CLEAR9_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_CLEAR_CLEAR9_Msk) >> GPIO_DATA_CLEAR_CLEAR9_Pos) /*!< CLEAR9 Get Value */

#define GPIO_DATA_CLEAR_CLEAR8_Pos (8U)                                 /*!< CLEAR8 Postion   */
#define GPIO_DATA_CLEAR_CLEAR8_Msk (0x1U << GPIO_DATA_CLEAR_CLEAR8_Pos) /*!< CLEAR8 Mask      */
#define GPIO_DATA_CLEAR_CLEAR8_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_CLEAR_CLEAR8_Pos) & GPIO_DATA_CLEAR_CLEAR8_Msk) /*!< CLEAR8 Set Value */
#define GPIO_DATA_CLEAR_CLEAR8_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_CLEAR_CLEAR8_Msk) >> GPIO_DATA_CLEAR_CLEAR8_Pos) /*!< CLEAR8 Get Value */

#define GPIO_DATA_CLEAR_CLEAR7_Pos (7U)                                 /*!< CLEAR7 Postion   */
#define GPIO_DATA_CLEAR_CLEAR7_Msk (0x1U << GPIO_DATA_CLEAR_CLEAR7_Pos) /*!< CLEAR7 Mask      */
#define GPIO_DATA_CLEAR_CLEAR7_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_CLEAR_CLEAR7_Pos) & GPIO_DATA_CLEAR_CLEAR7_Msk) /*!< CLEAR7 Set Value */
#define GPIO_DATA_CLEAR_CLEAR7_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_CLEAR_CLEAR7_Msk) >> GPIO_DATA_CLEAR_CLEAR7_Pos) /*!< CLEAR7 Get Value */

#define GPIO_DATA_CLEAR_CLEAR6_Pos (6U)                                 /*!< CLEAR6 Postion   */
#define GPIO_DATA_CLEAR_CLEAR6_Msk (0x1U << GPIO_DATA_CLEAR_CLEAR6_Pos) /*!< CLEAR6 Mask      */
#define GPIO_DATA_CLEAR_CLEAR6_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_CLEAR_CLEAR6_Pos) & GPIO_DATA_CLEAR_CLEAR6_Msk) /*!< CLEAR6 Set Value */
#define GPIO_DATA_CLEAR_CLEAR6_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_CLEAR_CLEAR6_Msk) >> GPIO_DATA_CLEAR_CLEAR6_Pos) /*!< CLEAR6 Get Value */

#define GPIO_DATA_CLEAR_CLEAR5_Pos (5U)                                 /*!< CLEAR5 Postion   */
#define GPIO_DATA_CLEAR_CLEAR5_Msk (0x1U << GPIO_DATA_CLEAR_CLEAR5_Pos) /*!< CLEAR5 Mask      */
#define GPIO_DATA_CLEAR_CLEAR5_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_CLEAR_CLEAR5_Pos) & GPIO_DATA_CLEAR_CLEAR5_Msk) /*!< CLEAR5 Set Value */
#define GPIO_DATA_CLEAR_CLEAR5_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_CLEAR_CLEAR5_Msk) >> GPIO_DATA_CLEAR_CLEAR5_Pos) /*!< CLEAR5 Get Value */

#define GPIO_DATA_CLEAR_CLEAR4_Pos (4U)                                 /*!< CLEAR4 Postion   */
#define GPIO_DATA_CLEAR_CLEAR4_Msk (0x1U << GPIO_DATA_CLEAR_CLEAR4_Pos) /*!< CLEAR4 Mask      */
#define GPIO_DATA_CLEAR_CLEAR4_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_CLEAR_CLEAR4_Pos) & GPIO_DATA_CLEAR_CLEAR4_Msk) /*!< CLEAR4 Set Value */
#define GPIO_DATA_CLEAR_CLEAR4_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_CLEAR_CLEAR4_Msk) >> GPIO_DATA_CLEAR_CLEAR4_Pos) /*!< CLEAR4 Get Value */

#define GPIO_DATA_CLEAR_CLEAR3_Pos (3U)                                 /*!< CLEAR3 Postion   */
#define GPIO_DATA_CLEAR_CLEAR3_Msk (0x1U << GPIO_DATA_CLEAR_CLEAR3_Pos) /*!< CLEAR3 Mask      */
#define GPIO_DATA_CLEAR_CLEAR3_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_CLEAR_CLEAR3_Pos) & GPIO_DATA_CLEAR_CLEAR3_Msk) /*!< CLEAR3 Set Value */
#define GPIO_DATA_CLEAR_CLEAR3_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_CLEAR_CLEAR3_Msk) >> GPIO_DATA_CLEAR_CLEAR3_Pos) /*!< CLEAR3 Get Value */

#define GPIO_DATA_CLEAR_CLEAR2_Pos (2U)                                 /*!< CLEAR2 Postion   */
#define GPIO_DATA_CLEAR_CLEAR2_Msk (0x1U << GPIO_DATA_CLEAR_CLEAR2_Pos) /*!< CLEAR2 Mask      */
#define GPIO_DATA_CLEAR_CLEAR2_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_CLEAR_CLEAR2_Pos) & GPIO_DATA_CLEAR_CLEAR2_Msk) /*!< CLEAR2 Set Value */
#define GPIO_DATA_CLEAR_CLEAR2_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_CLEAR_CLEAR2_Msk) >> GPIO_DATA_CLEAR_CLEAR2_Pos) /*!< CLEAR2 Get Value */

#define GPIO_DATA_CLEAR_CLEAR1_Pos (1U)                                 /*!< CLEAR1 Postion   */
#define GPIO_DATA_CLEAR_CLEAR1_Msk (0x1U << GPIO_DATA_CLEAR_CLEAR1_Pos) /*!< CLEAR1 Mask      */
#define GPIO_DATA_CLEAR_CLEAR1_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_CLEAR_CLEAR1_Pos) & GPIO_DATA_CLEAR_CLEAR1_Msk) /*!< CLEAR1 Set Value */
#define GPIO_DATA_CLEAR_CLEAR1_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_CLEAR_CLEAR1_Msk) >> GPIO_DATA_CLEAR_CLEAR1_Pos) /*!< CLEAR1 Get Value */

#define GPIO_DATA_CLEAR_CLEAR0_Pos (0U)                                 /*!< CLEAR0 Postion   */
#define GPIO_DATA_CLEAR_CLEAR0_Msk (0x1U << GPIO_DATA_CLEAR_CLEAR0_Pos) /*!< CLEAR0 Mask      */
#define GPIO_DATA_CLEAR_CLEAR0_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_CLEAR_CLEAR0_Pos) & GPIO_DATA_CLEAR_CLEAR0_Msk) /*!< CLEAR0 Set Value */
#define GPIO_DATA_CLEAR_CLEAR0_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_CLEAR_CLEAR0_Msk) >> GPIO_DATA_CLEAR_CLEAR0_Pos) /*!< CLEAR0 Get Value */

/* TOGGLE bitfield */
#define GPIO_DATA_TOGGLE_TOGGLE31_Pos (31U)                                   /*!< TOGGLE31 Postion   */
#define GPIO_DATA_TOGGLE_TOGGLE31_Msk (0x1U << GPIO_DATA_TOGGLE_TOGGLE31_Pos) /*!< TOGGLE31 Mask      */
#define GPIO_DATA_TOGGLE_TOGGLE31_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_TOGGLE_TOGGLE31_Pos) & GPIO_DATA_TOGGLE_TOGGLE31_Msk) /*!< TOGGLE31 Set Value */
#define GPIO_DATA_TOGGLE_TOGGLE31_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_TOGGLE_TOGGLE31_Msk) >> GPIO_DATA_TOGGLE_TOGGLE31_Pos) /*!< TOGGLE31 Get Value */

#define GPIO_DATA_TOGGLE_TOGGLE30_Pos (30U)                                   /*!< TOGGLE30 Postion   */
#define GPIO_DATA_TOGGLE_TOGGLE30_Msk (0x1U << GPIO_DATA_TOGGLE_TOGGLE30_Pos) /*!< TOGGLE30 Mask      */
#define GPIO_DATA_TOGGLE_TOGGLE30_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_TOGGLE_TOGGLE30_Pos) & GPIO_DATA_TOGGLE_TOGGLE30_Msk) /*!< TOGGLE30 Set Value */
#define GPIO_DATA_TOGGLE_TOGGLE30_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_TOGGLE_TOGGLE30_Msk) >> GPIO_DATA_TOGGLE_TOGGLE30_Pos) /*!< TOGGLE30 Get Value */

#define GPIO_DATA_TOGGLE_TOGGLE29_Pos (29U)                                   /*!< TOGGLE29 Postion   */
#define GPIO_DATA_TOGGLE_TOGGLE29_Msk (0x1U << GPIO_DATA_TOGGLE_TOGGLE29_Pos) /*!< TOGGLE29 Mask      */
#define GPIO_DATA_TOGGLE_TOGGLE29_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_TOGGLE_TOGGLE29_Pos) & GPIO_DATA_TOGGLE_TOGGLE29_Msk) /*!< TOGGLE29 Set Value */
#define GPIO_DATA_TOGGLE_TOGGLE29_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_TOGGLE_TOGGLE29_Msk) >> GPIO_DATA_TOGGLE_TOGGLE29_Pos) /*!< TOGGLE29 Get Value */

#define GPIO_DATA_TOGGLE_TOGGLE28_Pos (28U)                                   /*!< TOGGLE28 Postion   */
#define GPIO_DATA_TOGGLE_TOGGLE28_Msk (0x1U << GPIO_DATA_TOGGLE_TOGGLE28_Pos) /*!< TOGGLE28 Mask      */
#define GPIO_DATA_TOGGLE_TOGGLE28_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_TOGGLE_TOGGLE28_Pos) & GPIO_DATA_TOGGLE_TOGGLE28_Msk) /*!< TOGGLE28 Set Value */
#define GPIO_DATA_TOGGLE_TOGGLE28_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_TOGGLE_TOGGLE28_Msk) >> GPIO_DATA_TOGGLE_TOGGLE28_Pos) /*!< TOGGLE28 Get Value */

#define GPIO_DATA_TOGGLE_TOGGLE27_Pos (27U)                                   /*!< TOGGLE27 Postion   */
#define GPIO_DATA_TOGGLE_TOGGLE27_Msk (0x1U << GPIO_DATA_TOGGLE_TOGGLE27_Pos) /*!< TOGGLE27 Mask      */
#define GPIO_DATA_TOGGLE_TOGGLE27_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_TOGGLE_TOGGLE27_Pos) & GPIO_DATA_TOGGLE_TOGGLE27_Msk) /*!< TOGGLE27 Set Value */
#define GPIO_DATA_TOGGLE_TOGGLE27_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_TOGGLE_TOGGLE27_Msk) >> GPIO_DATA_TOGGLE_TOGGLE27_Pos) /*!< TOGGLE27 Get Value */

#define GPIO_DATA_TOGGLE_TOGGLE26_Pos (26U)                                   /*!< TOGGLE26 Postion   */
#define GPIO_DATA_TOGGLE_TOGGLE26_Msk (0x1U << GPIO_DATA_TOGGLE_TOGGLE26_Pos) /*!< TOGGLE26 Mask      */
#define GPIO_DATA_TOGGLE_TOGGLE26_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_TOGGLE_TOGGLE26_Pos) & GPIO_DATA_TOGGLE_TOGGLE26_Msk) /*!< TOGGLE26 Set Value */
#define GPIO_DATA_TOGGLE_TOGGLE26_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_TOGGLE_TOGGLE26_Msk) >> GPIO_DATA_TOGGLE_TOGGLE26_Pos) /*!< TOGGLE26 Get Value */

#define GPIO_DATA_TOGGLE_TOGGLE25_Pos (25U)                                   /*!< TOGGLE25 Postion   */
#define GPIO_DATA_TOGGLE_TOGGLE25_Msk (0x1U << GPIO_DATA_TOGGLE_TOGGLE25_Pos) /*!< TOGGLE25 Mask      */
#define GPIO_DATA_TOGGLE_TOGGLE25_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_TOGGLE_TOGGLE25_Pos) & GPIO_DATA_TOGGLE_TOGGLE25_Msk) /*!< TOGGLE25 Set Value */
#define GPIO_DATA_TOGGLE_TOGGLE25_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_TOGGLE_TOGGLE25_Msk) >> GPIO_DATA_TOGGLE_TOGGLE25_Pos) /*!< TOGGLE25 Get Value */

#define GPIO_DATA_TOGGLE_TOGGLE24_Pos (24U)                                   /*!< TOGGLE24 Postion   */
#define GPIO_DATA_TOGGLE_TOGGLE24_Msk (0x1U << GPIO_DATA_TOGGLE_TOGGLE24_Pos) /*!< TOGGLE24 Mask      */
#define GPIO_DATA_TOGGLE_TOGGLE24_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_TOGGLE_TOGGLE24_Pos) & GPIO_DATA_TOGGLE_TOGGLE24_Msk) /*!< TOGGLE24 Set Value */
#define GPIO_DATA_TOGGLE_TOGGLE24_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_TOGGLE_TOGGLE24_Msk) >> GPIO_DATA_TOGGLE_TOGGLE24_Pos) /*!< TOGGLE24 Get Value */

#define GPIO_DATA_TOGGLE_TOGGLE23_Pos (23U)                                   /*!< TOGGLE23 Postion   */
#define GPIO_DATA_TOGGLE_TOGGLE23_Msk (0x1U << GPIO_DATA_TOGGLE_TOGGLE23_Pos) /*!< TOGGLE23 Mask      */
#define GPIO_DATA_TOGGLE_TOGGLE23_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_TOGGLE_TOGGLE23_Pos) & GPIO_DATA_TOGGLE_TOGGLE23_Msk) /*!< TOGGLE23 Set Value */
#define GPIO_DATA_TOGGLE_TOGGLE23_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_TOGGLE_TOGGLE23_Msk) >> GPIO_DATA_TOGGLE_TOGGLE23_Pos) /*!< TOGGLE23 Get Value */

#define GPIO_DATA_TOGGLE_TOGGLE22_Pos (22U)                                   /*!< TOGGLE22 Postion   */
#define GPIO_DATA_TOGGLE_TOGGLE22_Msk (0x1U << GPIO_DATA_TOGGLE_TOGGLE22_Pos) /*!< TOGGLE22 Mask      */
#define GPIO_DATA_TOGGLE_TOGGLE22_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_TOGGLE_TOGGLE22_Pos) & GPIO_DATA_TOGGLE_TOGGLE22_Msk) /*!< TOGGLE22 Set Value */
#define GPIO_DATA_TOGGLE_TOGGLE22_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_TOGGLE_TOGGLE22_Msk) >> GPIO_DATA_TOGGLE_TOGGLE22_Pos) /*!< TOGGLE22 Get Value */

#define GPIO_DATA_TOGGLE_TOGGLE21_Pos (21U)                                   /*!< TOGGLE21 Postion   */
#define GPIO_DATA_TOGGLE_TOGGLE21_Msk (0x1U << GPIO_DATA_TOGGLE_TOGGLE21_Pos) /*!< TOGGLE21 Mask      */
#define GPIO_DATA_TOGGLE_TOGGLE21_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_TOGGLE_TOGGLE21_Pos) & GPIO_DATA_TOGGLE_TOGGLE21_Msk) /*!< TOGGLE21 Set Value */
#define GPIO_DATA_TOGGLE_TOGGLE21_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_TOGGLE_TOGGLE21_Msk) >> GPIO_DATA_TOGGLE_TOGGLE21_Pos) /*!< TOGGLE21 Get Value */

#define GPIO_DATA_TOGGLE_TOGGLE20_Pos (20U)                                   /*!< TOGGLE20 Postion   */
#define GPIO_DATA_TOGGLE_TOGGLE20_Msk (0x1U << GPIO_DATA_TOGGLE_TOGGLE20_Pos) /*!< TOGGLE20 Mask      */
#define GPIO_DATA_TOGGLE_TOGGLE20_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_TOGGLE_TOGGLE20_Pos) & GPIO_DATA_TOGGLE_TOGGLE20_Msk) /*!< TOGGLE20 Set Value */
#define GPIO_DATA_TOGGLE_TOGGLE20_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_TOGGLE_TOGGLE20_Msk) >> GPIO_DATA_TOGGLE_TOGGLE20_Pos) /*!< TOGGLE20 Get Value */

#define GPIO_DATA_TOGGLE_TOGGLE19_Pos (19U)                                   /*!< TOGGLE19 Postion   */
#define GPIO_DATA_TOGGLE_TOGGLE19_Msk (0x1U << GPIO_DATA_TOGGLE_TOGGLE19_Pos) /*!< TOGGLE19 Mask      */
#define GPIO_DATA_TOGGLE_TOGGLE19_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_TOGGLE_TOGGLE19_Pos) & GPIO_DATA_TOGGLE_TOGGLE19_Msk) /*!< TOGGLE19 Set Value */
#define GPIO_DATA_TOGGLE_TOGGLE19_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_TOGGLE_TOGGLE19_Msk) >> GPIO_DATA_TOGGLE_TOGGLE19_Pos) /*!< TOGGLE19 Get Value */

#define GPIO_DATA_TOGGLE_TOGGLE18_Pos (18U)                                   /*!< TOGGLE18 Postion   */
#define GPIO_DATA_TOGGLE_TOGGLE18_Msk (0x1U << GPIO_DATA_TOGGLE_TOGGLE18_Pos) /*!< TOGGLE18 Mask      */
#define GPIO_DATA_TOGGLE_TOGGLE18_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_TOGGLE_TOGGLE18_Pos) & GPIO_DATA_TOGGLE_TOGGLE18_Msk) /*!< TOGGLE18 Set Value */
#define GPIO_DATA_TOGGLE_TOGGLE18_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_TOGGLE_TOGGLE18_Msk) >> GPIO_DATA_TOGGLE_TOGGLE18_Pos) /*!< TOGGLE18 Get Value */

#define GPIO_DATA_TOGGLE_TOGGLE17_Pos (17U)                                   /*!< TOGGLE17 Postion   */
#define GPIO_DATA_TOGGLE_TOGGLE17_Msk (0x1U << GPIO_DATA_TOGGLE_TOGGLE17_Pos) /*!< TOGGLE17 Mask      */
#define GPIO_DATA_TOGGLE_TOGGLE17_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_TOGGLE_TOGGLE17_Pos) & GPIO_DATA_TOGGLE_TOGGLE17_Msk) /*!< TOGGLE17 Set Value */
#define GPIO_DATA_TOGGLE_TOGGLE17_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_TOGGLE_TOGGLE17_Msk) >> GPIO_DATA_TOGGLE_TOGGLE17_Pos) /*!< TOGGLE17 Get Value */

#define GPIO_DATA_TOGGLE_TOGGLE16_Pos (16U)                                   /*!< TOGGLE16 Postion   */
#define GPIO_DATA_TOGGLE_TOGGLE16_Msk (0x1U << GPIO_DATA_TOGGLE_TOGGLE16_Pos) /*!< TOGGLE16 Mask      */
#define GPIO_DATA_TOGGLE_TOGGLE16_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_TOGGLE_TOGGLE16_Pos) & GPIO_DATA_TOGGLE_TOGGLE16_Msk) /*!< TOGGLE16 Set Value */
#define GPIO_DATA_TOGGLE_TOGGLE16_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_TOGGLE_TOGGLE16_Msk) >> GPIO_DATA_TOGGLE_TOGGLE16_Pos) /*!< TOGGLE16 Get Value */

#define GPIO_DATA_TOGGLE_TOGGLE15_Pos (15U)                                   /*!< TOGGLE15 Postion   */
#define GPIO_DATA_TOGGLE_TOGGLE15_Msk (0x1U << GPIO_DATA_TOGGLE_TOGGLE15_Pos) /*!< TOGGLE15 Mask      */
#define GPIO_DATA_TOGGLE_TOGGLE15_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_TOGGLE_TOGGLE15_Pos) & GPIO_DATA_TOGGLE_TOGGLE15_Msk) /*!< TOGGLE15 Set Value */
#define GPIO_DATA_TOGGLE_TOGGLE15_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_TOGGLE_TOGGLE15_Msk) >> GPIO_DATA_TOGGLE_TOGGLE15_Pos) /*!< TOGGLE15 Get Value */

#define GPIO_DATA_TOGGLE_TOGGLE14_Pos (14U)                                   /*!< TOGGLE14 Postion   */
#define GPIO_DATA_TOGGLE_TOGGLE14_Msk (0x1U << GPIO_DATA_TOGGLE_TOGGLE14_Pos) /*!< TOGGLE14 Mask      */
#define GPIO_DATA_TOGGLE_TOGGLE14_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_TOGGLE_TOGGLE14_Pos) & GPIO_DATA_TOGGLE_TOGGLE14_Msk) /*!< TOGGLE14 Set Value */
#define GPIO_DATA_TOGGLE_TOGGLE14_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_TOGGLE_TOGGLE14_Msk) >> GPIO_DATA_TOGGLE_TOGGLE14_Pos) /*!< TOGGLE14 Get Value */

#define GPIO_DATA_TOGGLE_TOGGLE13_Pos (13U)                                   /*!< TOGGLE13 Postion   */
#define GPIO_DATA_TOGGLE_TOGGLE13_Msk (0x1U << GPIO_DATA_TOGGLE_TOGGLE13_Pos) /*!< TOGGLE13 Mask      */
#define GPIO_DATA_TOGGLE_TOGGLE13_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_TOGGLE_TOGGLE13_Pos) & GPIO_DATA_TOGGLE_TOGGLE13_Msk) /*!< TOGGLE13 Set Value */
#define GPIO_DATA_TOGGLE_TOGGLE13_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_TOGGLE_TOGGLE13_Msk) >> GPIO_DATA_TOGGLE_TOGGLE13_Pos) /*!< TOGGLE13 Get Value */

#define GPIO_DATA_TOGGLE_TOGGLE12_Pos (12U)                                   /*!< TOGGLE12 Postion   */
#define GPIO_DATA_TOGGLE_TOGGLE12_Msk (0x1U << GPIO_DATA_TOGGLE_TOGGLE12_Pos) /*!< TOGGLE12 Mask      */
#define GPIO_DATA_TOGGLE_TOGGLE12_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_TOGGLE_TOGGLE12_Pos) & GPIO_DATA_TOGGLE_TOGGLE12_Msk) /*!< TOGGLE12 Set Value */
#define GPIO_DATA_TOGGLE_TOGGLE12_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_TOGGLE_TOGGLE12_Msk) >> GPIO_DATA_TOGGLE_TOGGLE12_Pos) /*!< TOGGLE12 Get Value */

#define GPIO_DATA_TOGGLE_TOGGLE11_Pos (11U)                                   /*!< TOGGLE11 Postion   */
#define GPIO_DATA_TOGGLE_TOGGLE11_Msk (0x1U << GPIO_DATA_TOGGLE_TOGGLE11_Pos) /*!< TOGGLE11 Mask      */
#define GPIO_DATA_TOGGLE_TOGGLE11_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_TOGGLE_TOGGLE11_Pos) & GPIO_DATA_TOGGLE_TOGGLE11_Msk) /*!< TOGGLE11 Set Value */
#define GPIO_DATA_TOGGLE_TOGGLE11_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_TOGGLE_TOGGLE11_Msk) >> GPIO_DATA_TOGGLE_TOGGLE11_Pos) /*!< TOGGLE11 Get Value */

#define GPIO_DATA_TOGGLE_TOGGLE10_Pos (10U)                                   /*!< TOGGLE10 Postion   */
#define GPIO_DATA_TOGGLE_TOGGLE10_Msk (0x1U << GPIO_DATA_TOGGLE_TOGGLE10_Pos) /*!< TOGGLE10 Mask      */
#define GPIO_DATA_TOGGLE_TOGGLE10_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_TOGGLE_TOGGLE10_Pos) & GPIO_DATA_TOGGLE_TOGGLE10_Msk) /*!< TOGGLE10 Set Value */
#define GPIO_DATA_TOGGLE_TOGGLE10_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_TOGGLE_TOGGLE10_Msk) >> GPIO_DATA_TOGGLE_TOGGLE10_Pos) /*!< TOGGLE10 Get Value */

#define GPIO_DATA_TOGGLE_TOGGLE9_Pos (9U)                                   /*!< TOGGLE9 Postion   */
#define GPIO_DATA_TOGGLE_TOGGLE9_Msk (0x1U << GPIO_DATA_TOGGLE_TOGGLE9_Pos) /*!< TOGGLE9 Mask      */
#define GPIO_DATA_TOGGLE_TOGGLE9_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_TOGGLE_TOGGLE9_Pos) & GPIO_DATA_TOGGLE_TOGGLE9_Msk) /*!< TOGGLE9 Set Value */
#define GPIO_DATA_TOGGLE_TOGGLE9_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_TOGGLE_TOGGLE9_Msk) >> GPIO_DATA_TOGGLE_TOGGLE9_Pos) /*!< TOGGLE9 Get Value */

#define GPIO_DATA_TOGGLE_TOGGLE8_Pos (8U)                                   /*!< TOGGLE8 Postion   */
#define GPIO_DATA_TOGGLE_TOGGLE8_Msk (0x1U << GPIO_DATA_TOGGLE_TOGGLE8_Pos) /*!< TOGGLE8 Mask      */
#define GPIO_DATA_TOGGLE_TOGGLE8_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_TOGGLE_TOGGLE8_Pos) & GPIO_DATA_TOGGLE_TOGGLE8_Msk) /*!< TOGGLE8 Set Value */
#define GPIO_DATA_TOGGLE_TOGGLE8_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_TOGGLE_TOGGLE8_Msk) >> GPIO_DATA_TOGGLE_TOGGLE8_Pos) /*!< TOGGLE8 Get Value */

#define GPIO_DATA_TOGGLE_TOGGLE7_Pos (7U)                                   /*!< TOGGLE7 Postion   */
#define GPIO_DATA_TOGGLE_TOGGLE7_Msk (0x1U << GPIO_DATA_TOGGLE_TOGGLE7_Pos) /*!< TOGGLE7 Mask      */
#define GPIO_DATA_TOGGLE_TOGGLE7_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_TOGGLE_TOGGLE7_Pos) & GPIO_DATA_TOGGLE_TOGGLE7_Msk) /*!< TOGGLE7 Set Value */
#define GPIO_DATA_TOGGLE_TOGGLE7_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_TOGGLE_TOGGLE7_Msk) >> GPIO_DATA_TOGGLE_TOGGLE7_Pos) /*!< TOGGLE7 Get Value */

#define GPIO_DATA_TOGGLE_TOGGLE6_Pos (6U)                                   /*!< TOGGLE6 Postion   */
#define GPIO_DATA_TOGGLE_TOGGLE6_Msk (0x1U << GPIO_DATA_TOGGLE_TOGGLE6_Pos) /*!< TOGGLE6 Mask      */
#define GPIO_DATA_TOGGLE_TOGGLE6_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_TOGGLE_TOGGLE6_Pos) & GPIO_DATA_TOGGLE_TOGGLE6_Msk) /*!< TOGGLE6 Set Value */
#define GPIO_DATA_TOGGLE_TOGGLE6_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_TOGGLE_TOGGLE6_Msk) >> GPIO_DATA_TOGGLE_TOGGLE6_Pos) /*!< TOGGLE6 Get Value */

#define GPIO_DATA_TOGGLE_TOGGLE5_Pos (5U)                                   /*!< TOGGLE5 Postion   */
#define GPIO_DATA_TOGGLE_TOGGLE5_Msk (0x1U << GPIO_DATA_TOGGLE_TOGGLE5_Pos) /*!< TOGGLE5 Mask      */
#define GPIO_DATA_TOGGLE_TOGGLE5_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_TOGGLE_TOGGLE5_Pos) & GPIO_DATA_TOGGLE_TOGGLE5_Msk) /*!< TOGGLE5 Set Value */
#define GPIO_DATA_TOGGLE_TOGGLE5_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_TOGGLE_TOGGLE5_Msk) >> GPIO_DATA_TOGGLE_TOGGLE5_Pos) /*!< TOGGLE5 Get Value */

#define GPIO_DATA_TOGGLE_TOGGLE4_Pos (4U)                                   /*!< TOGGLE4 Postion   */
#define GPIO_DATA_TOGGLE_TOGGLE4_Msk (0x1U << GPIO_DATA_TOGGLE_TOGGLE4_Pos) /*!< TOGGLE4 Mask      */
#define GPIO_DATA_TOGGLE_TOGGLE4_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_TOGGLE_TOGGLE4_Pos) & GPIO_DATA_TOGGLE_TOGGLE4_Msk) /*!< TOGGLE4 Set Value */
#define GPIO_DATA_TOGGLE_TOGGLE4_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_TOGGLE_TOGGLE4_Msk) >> GPIO_DATA_TOGGLE_TOGGLE4_Pos) /*!< TOGGLE4 Get Value */

#define GPIO_DATA_TOGGLE_TOGGLE3_Pos (3U)                                   /*!< TOGGLE3 Postion   */
#define GPIO_DATA_TOGGLE_TOGGLE3_Msk (0x1U << GPIO_DATA_TOGGLE_TOGGLE3_Pos) /*!< TOGGLE3 Mask      */
#define GPIO_DATA_TOGGLE_TOGGLE3_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_TOGGLE_TOGGLE3_Pos) & GPIO_DATA_TOGGLE_TOGGLE3_Msk) /*!< TOGGLE3 Set Value */
#define GPIO_DATA_TOGGLE_TOGGLE3_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_TOGGLE_TOGGLE3_Msk) >> GPIO_DATA_TOGGLE_TOGGLE3_Pos) /*!< TOGGLE3 Get Value */

#define GPIO_DATA_TOGGLE_TOGGLE2_Pos (2U)                                   /*!< TOGGLE2 Postion   */
#define GPIO_DATA_TOGGLE_TOGGLE2_Msk (0x1U << GPIO_DATA_TOGGLE_TOGGLE2_Pos) /*!< TOGGLE2 Mask      */
#define GPIO_DATA_TOGGLE_TOGGLE2_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_TOGGLE_TOGGLE2_Pos) & GPIO_DATA_TOGGLE_TOGGLE2_Msk) /*!< TOGGLE2 Set Value */
#define GPIO_DATA_TOGGLE_TOGGLE2_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_TOGGLE_TOGGLE2_Msk) >> GPIO_DATA_TOGGLE_TOGGLE2_Pos) /*!< TOGGLE2 Get Value */

#define GPIO_DATA_TOGGLE_TOGGLE1_Pos (1U)                                   /*!< TOGGLE1 Postion   */
#define GPIO_DATA_TOGGLE_TOGGLE1_Msk (0x1U << GPIO_DATA_TOGGLE_TOGGLE1_Pos) /*!< TOGGLE1 Mask      */
#define GPIO_DATA_TOGGLE_TOGGLE1_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_TOGGLE_TOGGLE1_Pos) & GPIO_DATA_TOGGLE_TOGGLE1_Msk) /*!< TOGGLE1 Set Value */
#define GPIO_DATA_TOGGLE_TOGGLE1_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_TOGGLE_TOGGLE1_Msk) >> GPIO_DATA_TOGGLE_TOGGLE1_Pos) /*!< TOGGLE1 Get Value */

#define GPIO_DATA_TOGGLE_TOGGLE0_Pos (0U)                                   /*!< TOGGLE0 Postion   */
#define GPIO_DATA_TOGGLE_TOGGLE0_Msk (0x1U << GPIO_DATA_TOGGLE_TOGGLE0_Pos) /*!< TOGGLE0 Mask      */
#define GPIO_DATA_TOGGLE_TOGGLE0_Set(x) \
    (((uint32_t) (x) << GPIO_DATA_TOGGLE_TOGGLE0_Pos) & GPIO_DATA_TOGGLE_TOGGLE0_Msk) /*!< TOGGLE0 Set Value */
#define GPIO_DATA_TOGGLE_TOGGLE0_Get(x) \
    (((uint32_t) (x) &GPIO_DATA_TOGGLE_TOGGLE0_Msk) >> GPIO_DATA_TOGGLE_TOGGLE0_Pos) /*!< TOGGLE0 Get Value */

/*!
 * @}
 */

/*!
 * @}
 */ /* end of HS32F7D377_GPIO_DATA_REGISTER */

#endif // HS32F7D377_GPIO_DATA_H
