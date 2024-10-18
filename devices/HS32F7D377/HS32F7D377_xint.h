/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file HS32F7D377_xint.h
 * \brief HS32F7D377 XINT register file
 * \version 1.0.0
 */

#ifndef HS32F7D377_XINT_H
#define HS32F7D377_XINT_H

/*!
 * \addtogroup HS32F7D377_XINT_REGISTER HS32F7D377 XINT Register
 * \ingroup HS32F7D377_REGISTER
 *
 * \brief XINT register layout, bitfield and address definitions
 *
 * @{
 */

/*!
 * \name XINT Register Layout
 *
 * @{
 */

/*! \brief XINT register layout */
typedef struct
{
    union
    {
        __IOM uint16_t CR[5]; /*!< Offset: 0x00, Configuration register */

        struct
        {
            __IOM uint16_t INTR_ENABLE : 1; /*!< [0:0] : - 0: Interrupt Disabled - 1: Interrupt Enabled */
            uint16_t       RSV_0       : 1; /*!< [1:1] : reserved */
            __IOM uint16_t POLARITY    : 2; /*!< [3:2] : - 00: Interrupt is selected as negative edge triggered
                                                         - 01: Interrupt is selected as positive edge triggered
                                                         - 10: Interrupt is selected as negative edge triggered
                                                         - 11: Interrupt is selected as positive or negative edge
                                                         triggered */
            uint16_t RSV_1 : 12;            /*!< [15:4] : reserved */
        } CRb[5];
    };

    uint8_t RSV_0X0A[6]; /*!< Offset: 0x0a~0x0f, reserved */

    union
    {
        __IM uint16_t CTR1; /*!< Offset: 0x10, Counter1 register */

        struct
        {
            __IM uint16_t INTCTR : 16; /*!< [15:0] : This is a free running 16-bit up-counter that is clocked at the
                 SYSCLKOUT rate. The counter value is reset to 0x0000 when a valid interrupt edge is detected and
                 then continues counting until the next valid interrupt edge is detected. The counter must only be
                 reset by the selected POLARITY edge as selected in the respective interrupt control register. When
                 the interrupt is disabled, the counter will stop. The counter is a free-running counter and will
                 wrap around to zero when the max value is reached. The counter is a read only register and can only
                 be reset to zero by a valid interrupt edge or by reset */
        } CTR1b;
    };

    union
    {
        __IM uint16_t CTR2; /*!< Offset: 0x12, Counter2 register */

        struct
        {
            __IM uint16_t INTCTR : 16; /*!< [15:0] : This is a free running 16-bit up-counter that is clocked at
                                the SYSCLKOUT rate. The counter value is reset to 0x0000 when a valid interrupt
                                edge is detected and then continues counting until the next valid interrupt edge
                                is detected. The counter must only be reset by the selected POLARITY edge as
                                selected in the respective interrupt control register. When the interrupt is
                                disabled, the counter will stop. The counter is a free-running counter and will
                                wrap around to zero when the max value is reached. The counter is a read only
                                register and can only be reset to zero by a valid interrupt edge or by reset */
        } CTR2b;
    };

    union
    {
        __IM uint16_t CTR3; /*!< Offset: 0x14, Counter3 register */

        struct
        {
            __IM uint16_t INTCTR : 16; /*!< [15:0] : This is a free running 16-bit up-counter that is clocked at
                                the SYSCLKOUT rate. The counter value is reset to 0x0000 when a valid interrupt
                                edge is detected and then continues counting until the next valid interrupt edge
                                is detected. The counter must only be reset by the selected POLARITY edge as
                                selected in the respective interrupt control register. When the interrupt is
                                disabled, the counter will stop. The counter is a free-running counter and will
                                wrap around to zero when the max value is reached. The counter is a read only
                                register and can only be reset to zero by a valid interrupt edge or by reset */
        } CTR3b;
    };

    uint8_t RSV_0X16[2]; /*!< Offset: 0x16, reserved */

    union
    {
        __IM uint16_t CTR4; /*!< Offset: 0x18, Counter4 register */

        struct
        {
            __IM uint16_t INTCTR : 16; /*!< [15:0] : This is a free running 16-bit up-counter that is clocked at
                                the SYSCLKOUT rate. The counter value is reset to 0x0000 when a valid interrupt
                                edge is detected and then continues counting until the next valid interrupt edge
                                is detected. The counter must only be reset by the selected POLARITY edge as
                                selected in the respective interrupt control register. When the interrupt is
                                disabled, the counter will stop. The counter is a free-running counter and will
                                wrap around to zero when the max value is reached. The counter is a read only
                                register and can only be reset to zero by a valid interrupt edge or by reset */
        } CTR4b;
    };

    uint8_t RSV_0X1A[2]; /*!< Offset: 0x1a, reserved */

    union
    {
        __IM uint16_t CTR5; /*!< Offset: 0x1c, Counter5 register */

        struct
        {
            __IM uint16_t INTCTR : 16; /*!< [15:0] : This is a free running 16-bit up-counter that is clocked at
                                the SYSCLKOUT rate. The counter value is reset to 0x0000 when a valid interrupt
                                edge is detected and then continues counting until the next valid interrupt edge
                                is detected. The counter must only be reset by the selected POLARITY edge as
                                selected in the respective interrupt control register. When the interrupt is
                                disabled, the counter will stop. The counter is a free-running counter and will
                                wrap around to zero when the max value is reached. The counter is a read only
                                register and can only be reset to zero by a valid interrupt edge or by reset */
        } CTR5b;
    };

    uint8_t RSV_0X1E[2]; /*!< Offset: 0x1e, reserved */

    union
    {
        __IM uint32_t FLG[5]; /*!< Offset: 0x20 : Flag register */

        struct
        {
            __IM uint32_t FLG : 1; /*!< [0:0] : Writing a 1 to the respective bit clears the corresponding
                                      external interrupt flag. Writes of 0 are ignored. Always reads back 0 */
            uint32_t RSV_2 : 31;   /*!< [31:1] : reserved */
        } FLGb[5];
    };

    uint8_t RSV_0X34[12]; /*!< Offset: 0x34~0x3f, reserved */

    union
    {
        __IOM uint32_t CLR[5]; /*!< Offset: 0x40, Flag clear register */

        struct
        {
            __IOM uint32_t CLR : 1; /*!< [0:0] : Writing a 1 to the respective bit clears the corresponding
                                       external interrupt flag. Writes of 0 are ignored. Always reads back 0 */
            uint32_t RSV_37 : 31;   /*!< [31:1] : reserved */
        } CLRb[5];
    };
} XINT_Type;

/*!
 * @}
 */

/*!
 * \name XINT Base Address Definitions
 *
 * @{
 */

/*! \brief XINT base address. */
#define XINT_BASE (0x41001400UL)
/*! \brief XINT base pointer. */
#define XINT ((XINT_Type *) XINT_BASE)

/*!
 * @}
 */

/*!
 * \name XINT Register Bitfield Definitions
 *
 * @{
 */

/* CR bitfield*/
#define XINT_CR_ENABLE_Pos    (0U)                         /*!< ENABLE Position 0 */
#define XINT_CR_ENABLE_Msk    (0x1U << XINT_CR_ENABLE_Pos) /*!< ENABLE Mask 0x00000001 */
#define XINT_CR_ENABLE_Set(x) ((((uint16_t) (x)) << XINT_CR_ENABLE_Pos) & XINT_CR_ENABLE_Msk) /*!< ENABLE Set Value */
#define XINT_CR_ENABLE_Get(x) ((((uint16_t) (x)) & XINT_CR_ENABLE_Msk) >> XINT_CR_ENABLE_Pos) /*!< ENABLE Get Value */

#define XINT_CR_POLARITY_Pos (2U)                           /*!< DLL Position 2 */
#define XINT_CR_POLARITY_Msk (0x3U << XINT_CR_POLARITY_Pos) /*!< DLL Mask 0x0000000C */
#define XINT_CR_POLARITY_Set(x) \
    ((((uint16_t) (x)) << XINT_CR_POLARITY_Pos) & XINT_CR_POLARITY_Msk) /*!< DLL Set Value */
#define XINT_CR_POLARITY_Get(x) \
    ((((uint16_t) (x)) & XINT_CR_POLARITY_Msk) >> XINT_CR_POLARITY_Pos) /*!< DLL Get Value */

/* CTR bitfield*/
#define XINT_CTR_CTR_Pos    (0U)                                                        /*!< DLL Position 0 */
#define XINT_CTR_CTR_Msk    (0xFFFFU << XINT_CTR_CTR_Pos)                               /*!< DLL Mask 0x0000FFFF */
#define XINT_CTR_CTR_Set(x) ((((uint16_t) (x)) << XINT_CTR_CTR_Pos) & XINT_CTR_CTR_Msk) /*!< DLL Set Value */
#define XINT_CTR_CTR_Get(x) ((((uint16_t) (x)) & XINT_CTR_CTR_Msk) >> XINT_CTR_CTR_Pos) /*!< DLL Get Value */

/* FLG bitfield*/
#define XINT_FLG_FLG_Pos    (0U)                                                        /*!< DLL Position 0 */
#define XINT_FLG_FLG_Msk    (0x1U << XINT_FLG_FLG_Pos)                                  /*!< DLL Mask 0x00000001 */
#define XINT_FLG_FLG_Set(x) ((((uint32_t) (x)) << XINT_FLG_FLG_Pos) & XINT_FLG_FLG_Msk) /*!< DLL Set Value */
#define XINT_FLG_FLG_Get(x) ((((uint32_t) (x)) & XINT_FLG_FLG_Msk) >> XINT_FLG_FLG_Pos) /*!< DLL Get Value */

/* CLR bitfield*/
#define XINT_CLR_CLR_Pos    (0U)                                                        /*!< DLL Position 0 */
#define XINT_CLR_CLR_Msk    (0x1U << XINT_CLR_CLR_Pos)                                  /*!< DLL Mask 0x00000001 */
#define XINT_CLR_CLR_Set(x) ((((uint32_t) (x)) << XINT_CLR_CLR_Pos) & XINT_CLR_CLR_Msk) /*!< DLL Set Value */
#define XINT_CLR_CLR_Get(x) ((((uint32_t) (x)) & XINT_CLR_CLR_Msk) >> XINT_CLR_CLR_Pos) /*!< DLL Get Value */

/*!
 * @}
 */

/*!
 * @}
 */ /* end of HS32F7D377_XINT_REGISTER */

#endif /* HS32F7D377_XINT_H */
