/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


/*!
 * \file   HS32F7D377_stimer.h
 * \brief  HS32F7D377 STIMER register file
 * \version V1.0_20230831
 */

#ifndef HS32F7D377_STIMER_H
#define HS32F7D377_STIMER_H

/*!
 * \addtogroup   HS32F7D377_STIMER_REGISTER HS32F7D377 STIMER Register
 * \ingroup HS32F7D377_REGISTER
 *
 * \brief  STIMER register layout, bitfield and address definitions
 *
 * @{
 */

/*!
 * \name STIMER Register Layout
 *
 *
 * @{
 */

/*! \brief STIMER register layout */
typedef struct {
    /*!< 0x00000000~0x0000003b : register for each timer unit */
    struct
    {
        union
        {
            __IOM uint32_t LOAD_COUNT          ;  /*!< 0x00000000 : value to be loaded into Timer N */
        
            struct
            {
                __IOM uint32_t LOAD_COUNT                : 32;     /*!< [31: 0] : Value to be loaded into Timer N. */
            } LOAD_COUNTb;
        };
    
        union
        {
            __IOM uint32_t CURRENT_VALUE       ;  /*!< 0x00000004 : Current value of Timer N */
        
            struct
            {
                __IOM uint32_t CURRENT_VALUE             : 32;     /*!< [31: 0] : Current Value of Timer N. */
            } CURRENT_VALUEb;
        };
    
        union
        {
            __IOM uint32_t CONTROL_REG         ;  /*!< 0x00000008 : Timer N Control Register */
        
            struct
            {
                __IOM uint32_t TIM_EN                    : 1 ;     /*!< [ 0: 0] : Optional. */
                __IOM uint32_t MODE                      : 1 ;     /*!< [ 1: 1] : Timer mode for Timer N. */
                __IOM uint32_t INT_MASK                  : 1 ;     /*!< [ 2: 2] : Timer interrupt mask for Timer N. */
                __IOM uint32_t PWM                       : 1 ;     /*!< [ 3: 3] : Pulse Width Modulation of timer_N_toggle output. */
                __IOM uint32_t PWM0N100_EN               : 1 ;     /*!< [ 4: 4] : Optional. */
                      uint32_t RSV_0                     : 27;     /*!< [31: 5] : reserved. */
            } CONTROL_REGb;
        };
    
        union
        {
            __IM  uint32_t EOI                 ;  /*!< 0x0000000c : Timer N End-of-Interrupt Register */
        
            struct
            {
                __IM  uint32_t EOI                       : 32;     /*!< [31: 0] : Reading from this register returns all zeroes (0) and clears the interrupt from Timer N. */
            } EOIb;
        };
    
        union
        {
            __IM  uint32_t INT_STATUS          ;  /*!< 0x00000010 : Timer N Interrupt Status Register */
        
            struct
            {
                __IM  uint32_t INT_STATUS                : 32;     /*!< [31: 0] : Contains the interrupt status for Timer N. */
            } INT_STATUSb;
        };
    
    } T_UNIT[3];

    uint8_t    RSV_0X3C[100];   /*!< 0x0000003c~0x0000009f : reserved */

    union
    {
        __IM  uint32_t TIMERS_INT_STATUS   ;  /*!< 0x000000a0 : Timers Interrupt Status Register */
    
        struct
        {
            __IM  uint32_t TIMERS_INT_STATUS         : 32;     /*!< [31: 0] : Contains the interrupt status of all timers in the component. */
        } TIMERS_INT_STATUSb;
    };

    union
    {
        __IM  uint32_t TIMERS_EOI          ;  /*!< 0x000000a4 : Timers End-of-Interrupt Register */
    
        struct
        {
            __IM  uint32_t TIMERS_EOI                : 32;     /*!< [31: 0] : Reading this register returns all zeroes (0) and clears all active interrupts. */
        } TIMERS_EOIb;
    };

    union
    {
        __IM  uint32_t RAW_INT_STATUS      ;  /*!< 0x000000a8 : Timers Raw Interrupt Status Register */
    
        struct
        {
            __IM  uint32_t RAW_INT_STATUS            : 32;     /*!< [31: 0] : The register contains the unmasked interrupt status of all timers in the component. */
        } RAW_INT_STATUSb;
    };

    union
    {
        __IM  uint32_t COMP_VERSION        ;  /*!< 0x000000ac : Timers Component Version */
    
        struct
        {
            __IM  uint32_t COMP_VERSION              : 32;     /*!< [31: 0] : Current revision number of the DW_apb_timers component. */
        } COMP_VERSIONb;
    };

    union
    {
        __IOM uint32_t LOAD_COUNT2         ;  /*!< 0x000000b0 : Timer N Load Count2 Register */
    
        struct
        {
            __IOM uint32_t LOAD_COUNT2               : 32;     /*!< [31: 0] : Value to be loaded into Timer N when timer_N_toggle output changes from 0 to 1. */
        } LOAD_COUNT2b;
    };

    uint8_t    RSV_0XB4[28];   /*!< 0x000000b4~0x000000cf : reserved */

    union
    {
        __IOM uint32_t PROT_LEVEL          ;  /*!< 0x000000d0 : Timer_N Protection level */
    
        struct
        {
            __IOM uint32_t PROT_LEVEL_FIELD          : 32;     /*!< [31: 0] : This field holds protection value of TIMER_N_PROT_LEVEL register. */
        } PROT_LEVELb;
    };

} STIMER_Type;

/*!
 * @}
 */


/*!
 * \name STIMER Base Address Definitions
 *
 * @{
 */

/*! \brief STIMER base address */
#define STIMER_BASE (0x41010000UL)
/*! \brief STIMER base pointer */
#define STIMER ((STIMER_Type *) STIMER_BASE)

/*!
 * @}
 */


/*!
 * \name STIMER Register Bitfield Definitions
 *
 * @{
 */

/* LOAD_COUNT bitfield */
#define STIMER_LOAD_COUNT_LOAD_COUNT_Pos    (0U)                                                                                  /*!< LOAD_COUNT Position  0          */ 
#define STIMER_LOAD_COUNT_LOAD_COUNT_Msk    (0xffffffffU << STIMER_LOAD_COUNT_LOAD_COUNT_Pos)                                     /*!< LOAD_COUNT Mask      0xFFFFFFFF */
#define STIMER_LOAD_COUNT_LOAD_COUNT_Set(x) (((uint32_t) (x) << STIMER_LOAD_COUNT_LOAD_COUNT_Pos) & STIMER_LOAD_COUNT_LOAD_COUNT_Msk) /*!< LOAD_COUNT Set Value            */
#define STIMER_LOAD_COUNT_LOAD_COUNT_Get(x) (((uint32_t) (x) & STIMER_LOAD_COUNT_LOAD_COUNT_Msk) >> STIMER_LOAD_COUNT_LOAD_COUNT_Pos) /*!< LOAD_COUNT Get Value            */

/* CURRENT_VALUE bitfield */
#define STIMER_CURRENT_VALUE_CURRENT_VALUE_Pos    (0U)                                                                                  /*!< CURRENT_VALUE Position  0          */ 
#define STIMER_CURRENT_VALUE_CURRENT_VALUE_Msk    (0xffffffffU << STIMER_CURRENT_VALUE_CURRENT_VALUE_Pos)                               /*!< CURRENT_VALUE Mask      0xFFFFFFFF */
#define STIMER_CURRENT_VALUE_CURRENT_VALUE_Set(x) (((uint32_t) (x) << STIMER_CURRENT_VALUE_CURRENT_VALUE_Pos) & STIMER_CURRENT_VALUE_CURRENT_VALUE_Msk) /*!< CURRENT_VALUE Set Value            */
#define STIMER_CURRENT_VALUE_CURRENT_VALUE_Get(x) (((uint32_t) (x) & STIMER_CURRENT_VALUE_CURRENT_VALUE_Msk) >> STIMER_CURRENT_VALUE_CURRENT_VALUE_Pos) /*!< CURRENT_VALUE Get Value            */

/* CONTROL_REG bitfield */
#define STIMER_CONTROL_REG_PWM0N100_EN_Pos    (4U)                                                                                  /*!< PWM0N100_EN Position  4          */ 
#define STIMER_CONTROL_REG_PWM0N100_EN_Msk    (0x1U << STIMER_CONTROL_REG_PWM0N100_EN_Pos)                                          /*!< PWM0N100_EN Mask      0x00000010 */
#define STIMER_CONTROL_REG_PWM0N100_EN_Set(x) (((uint32_t) (x) << STIMER_CONTROL_REG_PWM0N100_EN_Pos) & STIMER_CONTROL_REG_PWM0N100_EN_Msk) /*!< PWM0N100_EN Set Value            */
#define STIMER_CONTROL_REG_PWM0N100_EN_Get(x) (((uint32_t) (x) & STIMER_CONTROL_REG_PWM0N100_EN_Msk) >> STIMER_CONTROL_REG_PWM0N100_EN_Pos) /*!< PWM0N100_EN Get Value            */

#define STIMER_CONTROL_REG_PWM_Pos    (3U)                                                                                  /*!< PWM Position  3          */ 
#define STIMER_CONTROL_REG_PWM_Msk    (0x1U << STIMER_CONTROL_REG_PWM_Pos)                                                  /*!< PWM Mask      0x00000008 */
#define STIMER_CONTROL_REG_PWM_Set(x) (((uint32_t) (x) << STIMER_CONTROL_REG_PWM_Pos) & STIMER_CONTROL_REG_PWM_Msk)         /*!< PWM Set Value            */
#define STIMER_CONTROL_REG_PWM_Get(x) (((uint32_t) (x) & STIMER_CONTROL_REG_PWM_Msk) >> STIMER_CONTROL_REG_PWM_Pos)         /*!< PWM Get Value            */

#define STIMER_CONTROL_REG_INT_MASK_Pos    (2U)                                                                                  /*!< INT_MASK Position  2          */ 
#define STIMER_CONTROL_REG_INT_MASK_Msk    (0x1U << STIMER_CONTROL_REG_INT_MASK_Pos)                                             /*!< INT_MASK Mask      0x00000004 */
#define STIMER_CONTROL_REG_INT_MASK_Set(x) (((uint32_t) (x) << STIMER_CONTROL_REG_INT_MASK_Pos) & STIMER_CONTROL_REG_INT_MASK_Msk) /*!< INT_MASK Set Value            */
#define STIMER_CONTROL_REG_INT_MASK_Get(x) (((uint32_t) (x) & STIMER_CONTROL_REG_INT_MASK_Msk) >> STIMER_CONTROL_REG_INT_MASK_Pos) /*!< INT_MASK Get Value            */

#define STIMER_CONTROL_REG_MODE_Pos    (1U)                                                                                  /*!< MODE Position  1          */ 
#define STIMER_CONTROL_REG_MODE_Msk    (0x1U << STIMER_CONTROL_REG_MODE_Pos)                                                 /*!< MODE Mask      0x00000002 */
#define STIMER_CONTROL_REG_MODE_Set(x) (((uint32_t) (x) << STIMER_CONTROL_REG_MODE_Pos) & STIMER_CONTROL_REG_MODE_Msk)       /*!< MODE Set Value            */
#define STIMER_CONTROL_REG_MODE_Get(x) (((uint32_t) (x) & STIMER_CONTROL_REG_MODE_Msk) >> STIMER_CONTROL_REG_MODE_Pos)       /*!< MODE Get Value            */

#define STIMER_CONTROL_REG_TIM_EN_Pos    (0U)                                                                                  /*!< TIM_EN Position  0          */ 
#define STIMER_CONTROL_REG_TIM_EN_Msk    (0x1U << STIMER_CONTROL_REG_TIM_EN_Pos)                                               /*!< TIM_EN Mask      0x00000001 */
#define STIMER_CONTROL_REG_TIM_EN_Set(x) (((uint32_t) (x) << STIMER_CONTROL_REG_TIM_EN_Pos) & STIMER_CONTROL_REG_TIM_EN_Msk)   /*!< TIM_EN Set Value            */
#define STIMER_CONTROL_REG_TIM_EN_Get(x) (((uint32_t) (x) & STIMER_CONTROL_REG_TIM_EN_Msk) >> STIMER_CONTROL_REG_TIM_EN_Pos)   /*!< TIM_EN Get Value            */

/* EOI bitfield */
#define STIMER_EOI_EOI_Pos    (0U)                                                                                  /*!< EOI Position  0          */ 
#define STIMER_EOI_EOI_Msk    (0xffffffffU << STIMER_EOI_EOI_Pos)                                                   /*!< EOI Mask      0xFFFFFFFF */
#define STIMER_EOI_EOI_Set(x) (((uint32_t) (x) << STIMER_EOI_EOI_Pos) & STIMER_EOI_EOI_Msk)                         /*!< EOI Set Value            */
#define STIMER_EOI_EOI_Get(x) (((uint32_t) (x) & STIMER_EOI_EOI_Msk) >> STIMER_EOI_EOI_Pos)                         /*!< EOI Get Value            */

/* INT_STATUS bitfield */
#define STIMER_INT_STATUS_INT_STATUS_Pos    (0U)                                                                                  /*!< INT_STATUS Position  0          */ 
#define STIMER_INT_STATUS_INT_STATUS_Msk    (0xffffffffU << STIMER_INT_STATUS_INT_STATUS_Pos)                                     /*!< INT_STATUS Mask      0xFFFFFFFF */
#define STIMER_INT_STATUS_INT_STATUS_Set(x) (((uint32_t) (x) << STIMER_INT_STATUS_INT_STATUS_Pos) & STIMER_INT_STATUS_INT_STATUS_Msk) /*!< INT_STATUS Set Value            */
#define STIMER_INT_STATUS_INT_STATUS_Get(x) (((uint32_t) (x) & STIMER_INT_STATUS_INT_STATUS_Msk) >> STIMER_INT_STATUS_INT_STATUS_Pos) /*!< INT_STATUS Get Value            */

/* TIMERS_INT_STATUS bitfield */
#define STIMER_TIMERS_INT_STATUS_TIMERS_INT_STATUS_Pos    (0U)                                                                                  /*!< TIMERS_INT_STATUS Position  0          */ 
#define STIMER_TIMERS_INT_STATUS_TIMERS_INT_STATUS_Msk    (0xffffffffU << STIMER_TIMERS_INT_STATUS_TIMERS_INT_STATUS_Pos)                       /*!< TIMERS_INT_STATUS Mask      0xFFFFFFFF */
#define STIMER_TIMERS_INT_STATUS_TIMERS_INT_STATUS_Set(x) (((uint32_t) (x) << STIMER_TIMERS_INT_STATUS_TIMERS_INT_STATUS_Pos) & STIMER_TIMERS_INT_STATUS_TIMERS_INT_STATUS_Msk) /*!< TIMERS_INT_STATUS Set Value            */
#define STIMER_TIMERS_INT_STATUS_TIMERS_INT_STATUS_Get(x) (((uint32_t) (x) & STIMER_TIMERS_INT_STATUS_TIMERS_INT_STATUS_Msk) >> STIMER_TIMERS_INT_STATUS_TIMERS_INT_STATUS_Pos) /*!< TIMERS_INT_STATUS Get Value            */

/* TIMERS_EOI bitfield */
#define STIMER_TIMERS_EOI_TIMERS_EOI_Pos    (0U)                                                                                  /*!< TIMERS_EOI Position  0          */ 
#define STIMER_TIMERS_EOI_TIMERS_EOI_Msk    (0xffffffffU << STIMER_TIMERS_EOI_TIMERS_EOI_Pos)                                     /*!< TIMERS_EOI Mask      0xFFFFFFFF */
#define STIMER_TIMERS_EOI_TIMERS_EOI_Set(x) (((uint32_t) (x) << STIMER_TIMERS_EOI_TIMERS_EOI_Pos) & STIMER_TIMERS_EOI_TIMERS_EOI_Msk) /*!< TIMERS_EOI Set Value            */
#define STIMER_TIMERS_EOI_TIMERS_EOI_Get(x) (((uint32_t) (x) & STIMER_TIMERS_EOI_TIMERS_EOI_Msk) >> STIMER_TIMERS_EOI_TIMERS_EOI_Pos) /*!< TIMERS_EOI Get Value            */

/* RAW_INT_STATUS bitfield */
#define STIMER_RAW_INT_STATUS_RAW_INT_STATUS_Pos    (0U)                                                                                  /*!< RAW_INT_STATUS Position  0          */ 
#define STIMER_RAW_INT_STATUS_RAW_INT_STATUS_Msk    (0xffffffffU << STIMER_RAW_INT_STATUS_RAW_INT_STATUS_Pos)                             /*!< RAW_INT_STATUS Mask      0xFFFFFFFF */
#define STIMER_RAW_INT_STATUS_RAW_INT_STATUS_Set(x) (((uint32_t) (x) << STIMER_RAW_INT_STATUS_RAW_INT_STATUS_Pos) & STIMER_RAW_INT_STATUS_RAW_INT_STATUS_Msk) /*!< RAW_INT_STATUS Set Value            */
#define STIMER_RAW_INT_STATUS_RAW_INT_STATUS_Get(x) (((uint32_t) (x) & STIMER_RAW_INT_STATUS_RAW_INT_STATUS_Msk) >> STIMER_RAW_INT_STATUS_RAW_INT_STATUS_Pos) /*!< RAW_INT_STATUS Get Value            */

/* COMP_VERSION bitfield */
#define STIMER_COMP_VERSION_COMP_VERSION_Pos    (0U)                                                                                  /*!< COMP_VERSION Position  0          */ 
#define STIMER_COMP_VERSION_COMP_VERSION_Msk    (0xffffffffU << STIMER_COMP_VERSION_COMP_VERSION_Pos)                                 /*!< COMP_VERSION Mask      0xFFFFFFFF */
#define STIMER_COMP_VERSION_COMP_VERSION_Set(x) (((uint32_t) (x) << STIMER_COMP_VERSION_COMP_VERSION_Pos) & STIMER_COMP_VERSION_COMP_VERSION_Msk) /*!< COMP_VERSION Set Value            */
#define STIMER_COMP_VERSION_COMP_VERSION_Get(x) (((uint32_t) (x) & STIMER_COMP_VERSION_COMP_VERSION_Msk) >> STIMER_COMP_VERSION_COMP_VERSION_Pos) /*!< COMP_VERSION Get Value            */

/* LOAD_COUNT2 bitfield */
#define STIMER_LOAD_COUNT2_LOAD_COUNT2_Pos    (0U)                                                                                  /*!< LOAD_COUNT2 Position  0          */ 
#define STIMER_LOAD_COUNT2_LOAD_COUNT2_Msk    (0xffffffffU << STIMER_LOAD_COUNT2_LOAD_COUNT2_Pos)                                   /*!< LOAD_COUNT2 Mask      0xFFFFFFFF */
#define STIMER_LOAD_COUNT2_LOAD_COUNT2_Set(x) (((uint32_t) (x) << STIMER_LOAD_COUNT2_LOAD_COUNT2_Pos) & STIMER_LOAD_COUNT2_LOAD_COUNT2_Msk) /*!< LOAD_COUNT2 Set Value            */
#define STIMER_LOAD_COUNT2_LOAD_COUNT2_Get(x) (((uint32_t) (x) & STIMER_LOAD_COUNT2_LOAD_COUNT2_Msk) >> STIMER_LOAD_COUNT2_LOAD_COUNT2_Pos) /*!< LOAD_COUNT2 Get Value            */

/* PROT_LEVEL bitfield */
#define STIMER_PROT_LEVEL_PROT_LEVEL_FIELD_Pos    (0U)                                                                                  /*!< PROT_LEVEL_FIELD Position  0          */ 
#define STIMER_PROT_LEVEL_PROT_LEVEL_FIELD_Msk    (0xffffffffU << STIMER_PROT_LEVEL_PROT_LEVEL_FIELD_Pos)                               /*!< PROT_LEVEL_FIELD Mask      0xFFFFFFFF */
#define STIMER_PROT_LEVEL_PROT_LEVEL_FIELD_Set(x) (((uint32_t) (x) << STIMER_PROT_LEVEL_PROT_LEVEL_FIELD_Pos) & STIMER_PROT_LEVEL_PROT_LEVEL_FIELD_Msk) /*!< PROT_LEVEL_FIELD Set Value            */
#define STIMER_PROT_LEVEL_PROT_LEVEL_FIELD_Get(x) (((uint32_t) (x) & STIMER_PROT_LEVEL_PROT_LEVEL_FIELD_Msk) >> STIMER_PROT_LEVEL_PROT_LEVEL_FIELD_Pos) /*!< PROT_LEVEL_FIELD Get Value            */

/*!
 * @}
 */

/*!
 * @}
 */ /* end of HS32F7D377_STIMER_REGISTER */

#endif /* HS32F7D377_STIMER_H */
