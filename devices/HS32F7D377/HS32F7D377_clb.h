/*
 * Copyright 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


/*!
 * \file HS32F7D377_clb.h
 * \brief HS32F7D377 CLB register file
 * \version V1.0_20240313
 */

#ifndef HS32F7D377_CLB_H
#define HS32F7D377_CLB_H

/*!
 * \addtogroup HS32F7D377_CLB_REGISTER HS32F7D377 CLB Register
 * \ingroup HS32F7D377_REGISTER
 *
 * \brief CLB register layout, bitfield and address definitions
 *
 * @{
 */

/* clang-format off */

/*!
 * \name CLB Register Layout
 *
 *
 * @{
 */

/*! \brief CLB_TILE register */
typedef struct {
    uint8_t    RSV_0X0[4]                                ;
    union
    {
        __IOM uint32_t CLB_COUNT_RESET                   ;  /*!< 0x00000004 : Counter Block RESET */

        struct
        {
            __IOM uint32_t SEL_0                     : 5 ;  /*!< [ 4: 0] : Counter reset select inputs for unit 0. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SEL_1                     : 5 ;  /*!< [ 9: 5] : Counter reset select inputs for unit 1. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SEL_2                     : 5 ;  /*!< [14:10] : Counter reset select inputs for unit 2. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 17;  /*!< [31:15] : reserved. */
        } CLB_COUNT_RESETb;
    };

    union
    {
        __IOM uint32_t CLB_COUNT_MODE_1                  ;  /*!< 0x00000008 : Counter Block MODE_1 */

        struct
        {
            __IOM uint32_t SEL_0                     : 5 ;  /*!< [ 4: 0] : Counter MODE_1 select inputs for unit 0. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SEL_1                     : 5 ;  /*!< [ 9: 5] : Counter MODE_1 select inputs for unit 1. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SEL_2                     : 5 ;  /*!< [14:10] : Counter MODE_1 select inputs for unit 2. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 17;  /*!< [31:15] : reserved. */
        } CLB_COUNT_MODE_1b;
    };

    union
    {
        __IOM uint32_t CLB_COUNT_MODE_0                  ;  /*!< 0x0000000c : Counter Block MODE_0 */

        struct
        {
            __IOM uint32_t SEL_0                     : 5 ;  /*!< [ 4: 0] : Counter MODE_0 select inputs for unit 0. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SEL_1                     : 5 ;  /*!< [ 9: 5] : Counter MODE_0 select inputs for unit 1. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SEL_2                     : 5 ;  /*!< [14:10] : Counter MODE_0 select inputs for unit 2. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 17;  /*!< [31:15] : reserved. */
        } CLB_COUNT_MODE_0b;
    };

    union
    {
        __IOM uint32_t CLB_COUNT_EVENT                   ;  /*!< 0x00000010 : Counter Block EVENT */

        struct
        {
            __IOM uint32_t SEL_0                     : 5 ;  /*!< [ 4: 0] : Counter event select inputs for unit 0. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SEL_1                     : 5 ;  /*!< [ 9: 5] : Counter event select inputs for unit 1. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SEL_2                     : 5 ;  /*!< [14:10] : Counter event select inputs for unit 2. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 17;  /*!< [31:15] : reserved. */
        } CLB_COUNT_EVENTb;
    };

    union
    {
        __IOM uint32_t CLB_FSM_EXTRA_IN0                 ;  /*!< 0x00000014 : FSM Extra EXT_IN0 */

        struct
        {
            __IOM uint32_t SEL_0                     : 5 ;  /*!< [ 4: 0] : FSM block extra external IN0 select inputs for unit 0. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SEL_1                     : 5 ;  /*!< [ 9: 5] : FSM block extra external IN0 select inputs for unit 1. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SEL_2                     : 5 ;  /*!< [14:10] : FSM block extra external IN0 select inputs for unit 2. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 17;  /*!< [31:15] : reserved. */
        } CLB_FSM_EXTRA_IN0b;
    };

    union
    {
        __IOM uint32_t CLB_FSM_EXTERNAL_IN0              ;  /*!< 0x00000018 : FSM EXT_IN0 */

        struct
        {
            __IOM uint32_t SEL_0                     : 5 ;  /*!< [ 4: 0] : FSM block EXT_IN0 select input for unit 0. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SEL_1                     : 5 ;  /*!< [ 9: 5] : FSM block EXT_IN0 select input for unit 1. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SEL_2                     : 5 ;  /*!< [14:10] : FSM block EXT_IN0 select input for unit 2. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 17;  /*!< [31:15] : reserved. */
        } CLB_FSM_EXTERNAL_IN0b;
    };

    union
    {
        __IOM uint32_t CLB_FSM_EXTERNAL_IN1              ;  /*!< 0x0000001c : FSM_EXT_IN1 */

        struct
        {
            __IOM uint32_t SEL_0                     : 5 ;  /*!< [ 4: 0] : FSM block EXT_IN1 select input for unit 0. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SEL_1                     : 5 ;  /*!< [ 9: 5] : FSM block EXT_IN1 select input for unit 1. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SEL_2                     : 5 ;  /*!< [14:10] : FSM block EXT_IN1 select input for unit 2. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 17;  /*!< [31:15] : reserved. */
        } CLB_FSM_EXTERNAL_IN1b;
    };

    union
    {
        __IOM uint32_t CLB_FSM_EXTRA_IN1                 ;  /*!< 0x00000020 : FSM Extra_EXT_IN1 */

        struct
        {
            __IOM uint32_t SEL_0                     : 5 ;  /*!< [ 4: 0] : FSM block extra external IN1 select inputs for unit 0. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SEL_1                     : 5 ;  /*!< [ 9: 5] : FSM block extra external IN1 select inputs for unit 1. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SEL_2                     : 5 ;  /*!< [14:10] : FSM block extra external IN1 select inputs for unit 2. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 17;  /*!< [31:15] : reserved. */
        } CLB_FSM_EXTRA_IN1b;
    };

    union
    {
        __IOM uint32_t CLB_LUT4_IN0                      ;  /*!< 0x00000024 : LUT4_0/1/2 IN0 input source */

        struct
        {
            __IOM uint32_t SEL_0                     : 5 ;  /*!< [ 4: 0] : LUT4 block IN0 select inputs for unit 0. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SEL_1                     : 5 ;  /*!< [ 9: 5] : LUT4 block IN0 select inputs for unit 1. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SEL_2                     : 5 ;  /*!< [14:10] : LUT4 block IN0 select inputs for unit 2. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 17;  /*!< [31:15] : reserved. */
        } CLB_LUT4_IN0b;
    };

    union
    {
        __IOM uint32_t CLB_LUT4_IN1                      ;  /*!< 0x00000028 : LUT4_0/1/2 IN1 input source */

        struct
        {
            __IOM uint32_t SEL_0                     : 5 ;  /*!< [ 4: 0] : LUT4 block IN1 select inputs for unit 0. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SEL_1                     : 5 ;  /*!< [ 9: 5] : LUT4 block IN1 select inputs for unit 1. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SEL_2                     : 5 ;  /*!< [14:10] : LUT4 block IN1 select inputs for unit 2. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 17;  /*!< [31:15] : reserved. */
        } CLB_LUT4_IN1b;
    };

    union
    {
        __IOM uint32_t CLB_LUT4_IN2                      ;  /*!< 0x0000002c : LUT4_0/1/2 IN2 input source */

        struct
        {
            __IOM uint32_t SEL_0                     : 5 ;  /*!< [ 4: 0] : LUT4 block IN2 select inputs for unit 0. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SEL_1                     : 5 ;  /*!< [ 9: 5] : LUT4 block IN2 select inputs for unit 1. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SEL_2                     : 5 ;  /*!< [14:10] : LUT4 block IN2 select inputs for unit 2. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 17;  /*!< [31:15] : reserved. */
        } CLB_LUT4_IN2b;
    };

    union
    {
        __IOM uint32_t CLB_LUT4_IN3                      ;  /*!< 0x00000030 : LUT4_0/1/2 IN3 input source */

        struct
        {
            __IOM uint32_t SEL_0                     : 5 ;  /*!< [ 4: 0] : LUT4 block IN3 select inputs for unit 0. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SEL_1                     : 5 ;  /*!< [ 9: 5] : LUT4 block IN3 select inputs for unit 1. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SEL_2                     : 5 ;  /*!< [14:10] : LUT4 block IN3 select inputs for unit 2. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 17;  /*!< [31:15] : reserved. */
        } CLB_LUT4_IN3b;
    };

    uint8_t    RSV_0X34[4]                               ;
    union
    {
        __IOM uint32_t CLB_FSM_LUT_FN1_0                 ;  /*!< 0x00000038 : LUT function for FSM Unit 1 and Unit 0 */

        struct
        {
            __IOM uint32_t FN0                       : 16;  /*!< [15: 0] : FSM block LUT output function for unit 0 Reset type: SYSRSn. */
            __IOM uint32_t FN1                       : 16;  /*!< [31:16] : FSM block LUT output function for unit 1 Reset type: SYSRSn. */
        } CLB_FSM_LUT_FN1_0b;
    };

    union
    {
        __IOM uint32_t CLB_FSM_LUT_FN2                   ;  /*!< 0x0000003c : LUT function for FSM Unit 2 */

        struct
        {
            __IOM uint32_t FN1                       : 16;  /*!< [15: 0] : LUT4 output function for unit 2 Reset type: SYSRSn. */
                  uint32_t RSV_0                     : 16;  /*!< [31:16] : reserved. */
        } CLB_FSM_LUT_FN2b;
    };

    union
    {
        __IOM uint32_t CLB_LUT4_FN1_0                    ;  /*!< 0x00000040 : LUT function for LUT4 block of Unit 1 and 0 */

        struct
        {
            __IOM uint32_t FN0                       : 16;  /*!< [15: 0] : LUT4 output function for unit 0 Reset type: SYSRSn. */
            __IOM uint32_t FN1                       : 16;  /*!< [31:16] : LUT4 output function for unit 1 Reset type: SYSRSn. */
        } CLB_LUT4_FN1_0b;
    };

    union
    {
        __IOM uint32_t CLB_LUT4_FN2                      ;  /*!< 0x00000044 : LUT function for LUT4 block of Unit 2 */

        struct
        {
            __IOM uint32_t FN1                       : 16;  /*!< [15: 0] : LUT4 output function for unit 2 Reset type: SYSRSn. */
                  uint32_t RSV_0                     : 16;  /*!< [31:16] : reserved. */
        } CLB_LUT4_FN2b;
    };

    union
    {
        __IOM uint32_t CLB_FSM_NEXT_STATE_0              ;  /*!< 0x00000048 : FSM Next state equations for Unit 0 */

        struct
        {
            __IOM uint32_t S0                        : 16;  /*!< [15: 0] : FSM next state function for S0, unit0 Reset type: SYSRSn. */
            __IOM uint32_t S1                        : 16;  /*!< [31:16] : FSM next state function for S1, unit0 Reset type: SYSRSn. */
        } CLB_FSM_NEXT_STATE_0b;
    };

    union
    {
        __IOM uint32_t CLB_FSM_NEXT_STATE_1              ;  /*!< 0x0000004c : FSM Next state equations for Unit 1 */

        struct
        {
            __IOM uint32_t S0                        : 16;  /*!< [15: 0] : FSM next state function for S0, unit1 Reset type: SYSRSn. */
            __IOM uint32_t S1                        : 16;  /*!< [31:16] : FSM next state function for S1, unit1 Reset type: SYSRSn. */
        } CLB_FSM_NEXT_STATE_1b;
    };

    union
    {
        __IOM uint32_t CLB_FSM_NEXT_STATE_2              ;  /*!< 0x00000050 : FSM Next state equations for Unit 2 */

        struct
        {
            __IOM uint32_t S0                        : 16;  /*!< [15: 0] : FSM next state function for S0, unit2 Reset type: SYSRSn. */
            __IOM uint32_t S1                        : 16;  /*!< [31:16] : FSM next state function for S1, unit2 Reset type: SYSRSn. */
        } CLB_FSM_NEXT_STATE_2b;
    };

    union
    {
        __IOM uint32_t CLB_MISC_CONTROL                  ;  /*!< 0x00000054 : Static controls for Ctr,FSM */

        struct
        {
            __IOM uint32_t COUNT_ADD_SHIFT_0         : 1 ;  /*!< [ 0: 0] : Controls whether the UNIT 0 counter will do an ADD or a SHIFT on an EVENT.
                                                                           0 = Shift
                                                                           1 = ADD
                                                                           Reset type: SYSRSn */
            __IOM uint32_t COUNT_DIR_0               : 1 ;  /*!< [ 1: 1] : Controls add/shift direction for UNIT 0 0 = right shift or subtract
                                                                           1 = left shift or add Reset type: SYSRSn */
            __IOM uint32_t COUNT_EVENT_CTRL_0        : 1 ;  /*!< [ 2: 2] : Controls the actions on an EVENT for UNIT1.
                                                                           0 = No add or shift, but load the predefined value
                                                                           1 = Based on other bits, add/shift with the predefined value Reset type: SYSRSn */
            __IOM uint32_t COUNT_ADD_SHIFT_1         : 1 ;  /*!< [ 3: 3] : Controls whether the UNIT 1 counter will do an ADD or a SHIFT on an EVENT.
                                                                           0 = Shift
                                                                           1 = ADD
                                                                           Reset type: SYSRSn */
            __IOM uint32_t COUNT_DIR_1               : 1 ;  /*!< [ 4: 4] : Controls add/shift direction for UNIT 1 0 = right shift or subtract
                                                                           1 = left shift or add Reset type: SYSRSn */
            __IOM uint32_t COUNT_EVENT_CTRL_1        : 1 ;  /*!< [ 5: 5] : Controls the actions on an EVENT for UNIT1.
                                                                           0 = No add or shift, but load the predefined value
                                                                           1 = Based on other bits, add/shift with the predefined value Reset type: SYSRSn */
            __IOM uint32_t COUNT_ADD_SHIFT_2         : 1 ;  /*!< [ 6: 6] : Controls whether the UNIT 2 counter will do an ADD or a SHIFT on an EVENT.
                                                                           0 =Shift
                                                                           1 = ADD
                                                                           Reset type: SYSRSn */
            __IOM uint32_t COUNT_DIR_2               : 1 ;  /*!< [ 7: 7] : Controls add/shift direction for UNIT 2 0 = right shift or subtract
                                                                           1 = left shift or add Reset type: SYSRSn */
            __IOM uint32_t COUNT_EVENT_CTRL_2        : 1 ;  /*!< [ 8: 8] : Controls the actions on an EVENT for UNIT2.
                                                                           0 = No add or shift, but load the predefined value
                                                                           1 = Based on other bits, add/shift with the predefined value Reset type: SYSRSn */
            __IOM uint32_t COUNT_SERIALIZER_0        : 1 ;  /*!< [ 9: 9] : Controls if the Counter of UNIT 0 is the Serialzer mode or not. 0 = Normal mode
                                                                           1 = Serializer mode Reset type: SYSRSn */
            __IOM uint32_t COUNT_SERIALIZER_1        : 1 ;  /*!< [10:10] : Controls if the Counter of UNIT 1 is the Serialzer mode or not. 0 = Normal mode
                                                                           1 = Serializer mode Reset type: SYSRSn */
            __IOM uint32_t COUNT_SERIALIZER_2        : 1 ;  /*!< [11:11] : Controls if the Counter of UNIT 2 is the Serialzer mode or not. 0 = Normal mode
                                                                           1 = Serializer mode Reset type: SYSRSn */
            __IOM uint32_t FSM_EXTRA_SEL0_0          : 1 ;  /*!< [12:12] : Defines which input should be selected for the FSM LUT of UNIT 0 0 = Selects State S0 for the FSM LUT
                                                                           1 = Selects EXTRA_EXT_IN0 for the FSM LUT Reset type: SYSRSn */
            __IOM uint32_t FSM_EXTRA_SEL1_0          : 1 ;  /*!< [13:13] : Defines which input should be selected for the FSM LUT of UNIT 0 0 = Selects State S1 for the FSM LUT
                                                                           1 = Selects EXTRA_EXT_IN1 for the FSM LUT Reset type: SYSRSn */
            __IOM uint32_t FSM_EXTRA_SEL0_1          : 1 ;  /*!< [14:14] : Defines which input should be selected for the FSM LUT of UNIT 1 0 = Selects State S0 for the FSM LUT
                                                                           1 = Selects EXTRA_EXT_IN0 for the FSM LUT Reset type: SYSRSn */
            __IOM uint32_t FSM_EXTRA_SEL1_1          : 1 ;  /*!< [15:15] : Defines which input should be selected for the FSM LUT of UNIT 1 0 = Selects State S1 for the FSM LUT
                                                                           1 = Selects EXTRA_EXT_IN1 for the FSM LUT Reset type: SYSRSn */
            __IOM uint32_t FSM_EXTRA_SEL0_2          : 1 ;  /*!< [16:16] : Defines which input should be selected for the FSM LUT of UNIT 2 0 = Selects State S0 for the FSM LUT
                                                                           1 = Selects EXTRA_EXT_IN0 for the FSM LUT Reset type: SYSRSn */
            __IOM uint32_t FSM_EXTRA_SEL1_2          : 1 ;  /*!< [17:17] : Defines which input should be selected for the FSM LUT of UNIT 2 0 = Selects State S1 for the FSM LUT
                                                                           1 = Selects EXTRA_EXT_IN1 for the FSM LUT Reset type: SYSRSn */
            __IOM uint32_t COUNT0_MATCH1_TAP_EN      : 1 ;  /*!< [18:18] : Defines if the Match1 output should come from the match unit or tapped from a bit position of the counter
                                                                           0 = Selects Match1 comaprison output
                                                                           1 = Selects Bit position defined by Match1_Tap_val Reset type: SYSRSn */
            __IOM uint32_t COUNT1_MATCH1_TAP_EN      : 1 ;  /*!< [19:19] : Defines if the Match1 output should come from the match unit or tapped from a bit position of the counter
                                                                           0 = Selects Match1 comaprison output
                                                                           1 = Selects Bit position defined by Match1_Tap_val Reset type: SYSRSn */
            __IOM uint32_t COUNT2_MATCH1_TAP_EN      : 1 ;  /*!< [20:20] : Defines if the Match1 output should come from the match unit or tapped from a bit position of the counter
                                                                           0 = Selects Match1 comaprison output
                                                                           1 = Selects Bit position defined by Match1_Tap_val Reset type: SYSRSn */
            __IOM uint32_t COUNT0_MATCH2_TAP_EN      : 1 ;  /*!< [21:21] : Defines if the Match2 output should come from the match unit or tapped from a bit position of the counter
                                                                           0 = Selects Match2 comaprison output
                                                                           1 = Selects Bit position defined by Match2_Tap_val Reset type: SYSRSn */
            __IOM uint32_t COUNT1_MATCH2_TAP_EN      : 1 ;  /*!< [22:22] : Defines if the Match2 output should come from the match unit or tapped from a bit position of the counter
                                                                           0 = Selects Match2 comaprison output
                                                                           1 = Selects Bit position defined by Match2_Tap_val Reset type: SYSRSn */
            __IOM uint32_t COUNT2_MATCH2_TAP_EN      : 1 ;  /*!< [23:23] : Defines if the Match2 output should come from the match unit or tapped from a bit position of the counter
                                                                           0 = Selects Match2 comaprison output
                                                                           1 = Selects Bit position defined by Match2_Tap_val Reset type: SYSRSn */
            __IOM uint32_t COUNT0_LFSR_EN            : 1 ;  /*!< [24:24] : Defines if Counter 0 should operate in LFSR mode. This should be set to 1 only if it is in the SERIALIZER mode.
                                                                           0 = Selects normal serializer operation 1 = Selects LFSR mode of operation Reset type: SYSRSn */
            __IOM uint32_t COUNT1_LFSR_EN            : 1 ;  /*!< [25:25] : Defines if Counter 1 should operate in LFSR mode. This should be set to 1 only if it is in the SERIALIZER mode.
                                                                           0 = Selects normal serializer operation 1 = Selects LFSR mode of operation Reset type: SYSRSn */
            __IOM uint32_t COUNT2_LFSR_EN            : 1 ;  /*!< [26:26] : Defines if Counter 2 should operate in LFSR mode. This should be set to 1 only if it is in the SERIALIZER mode.
                                                                           0 = Selects normal serializer operation 1 = Selects LFSR mode of operation Reset type: SYSRSn */
                  uint32_t RSV_0                     : 5 ;  /*!< [31:27] : reserved. */
        } CLB_MISC_CONTROLb;
    };

    union
    {
        __IOM uint32_t CLB_OUTPUT_LUT_0                  ;  /*!< 0x00000058 : Inp Sel, LUT fns for Out0 */

        struct
        {
            __IOM uint32_t IN0                       : 5 ;  /*!< [ 4: 0] : Select value for IN0 of output LUT. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t IN1                       : 5 ;  /*!< [ 9: 5] : Select value for IN1 of output LUT. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t IN2                       : 5 ;  /*!< [14:10] : Select value for IN2 of output LUT. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t FN                        : 8 ;  /*!< [22:15] : Output function for output LUT Reset type: SYSRSn. */
                  uint32_t RSV_0                     : 9 ;  /*!< [31:23] : reserved. */
        } CLB_OUTPUT_LUT_0b;
    };

    union
    {
        __IOM uint32_t CLB_OUTPUT_LUT_1                  ;  /*!< 0x0000005c : Inp Sel, LUT fns for Out1 */

        struct
        {
            __IOM uint32_t IN0                       : 5 ;  /*!< [ 4: 0] : Select value for IN0 of output LUT. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t IN1                       : 5 ;  /*!< [ 9: 5] : Select value for IN1 of output LUT. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t IN2                       : 5 ;  /*!< [14:10] : Select value for IN2 of output LUT. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t FN                        : 8 ;  /*!< [22:15] : Output function for output LUT Reset type: SYSRSn. */
                  uint32_t RSV_0                     : 9 ;  /*!< [31:23] : reserved. */
        } CLB_OUTPUT_LUT_1b;
    };

    union
    {
        __IOM uint32_t CLB_OUTPUT_LUT_2                  ;  /*!< 0x00000060 : Inp Sel, LUT fns for Out2 */

        struct
        {
            __IOM uint32_t IN0                       : 5 ;  /*!< [ 4: 0] : Select value for IN0 of output LUT. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t IN1                       : 5 ;  /*!< [ 9: 5] : Select value for IN1 of output LUT. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t IN2                       : 5 ;  /*!< [14:10] : Select value for IN2 of output LUT. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t FN                        : 8 ;  /*!< [22:15] : Output function for output LUT Reset type: SYSRSn. */
                  uint32_t RSV_0                     : 9 ;  /*!< [31:23] : reserved. */
        } CLB_OUTPUT_LUT_2b;
    };

    union
    {
        __IOM uint32_t CLB_OUTPUT_LUT_3                  ;  /*!< 0x00000064 : Inp Sel, LUT fns for Out3 */

        struct
        {
            __IOM uint32_t IN0                       : 5 ;  /*!< [ 4: 0] : Select value for IN0 of output LUT. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t IN1                       : 5 ;  /*!< [ 9: 5] : Select value for IN1 of output LUT. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t IN2                       : 5 ;  /*!< [14:10] : Select value for IN2 of output LUT. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t FN                        : 8 ;  /*!< [22:15] : Output function for output LUT Reset type: SYSRSn. */
                  uint32_t RSV_0                     : 9 ;  /*!< [31:23] : reserved. */
        } CLB_OUTPUT_LUT_3b;
    };

    union
    {
        __IOM uint32_t CLB_OUTPUT_LUT_4                  ;  /*!< 0x00000068 : Inp Sel, LUT fns for Out4 */

        struct
        {
            __IOM uint32_t IN0                       : 5 ;  /*!< [ 4: 0] : Select value for IN0 of output LUT. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t IN1                       : 5 ;  /*!< [ 9: 5] : Select value for IN1 of output LUT. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t IN2                       : 5 ;  /*!< [14:10] : Select value for IN2 of output LUT. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t FN                        : 8 ;  /*!< [22:15] : Output function for output LUT Reset type: SYSRSn. */
                  uint32_t RSV_0                     : 9 ;  /*!< [31:23] : reserved. */
        } CLB_OUTPUT_LUT_4b;
    };

    union
    {
        __IOM uint32_t CLB_OUTPUT_LUT_5                  ;  /*!< 0x0000006c : Inp Sel, LUT fns for Out5 */

        struct
        {
            __IOM uint32_t IN0                       : 5 ;  /*!< [ 4: 0] : Select value for IN0 of output LUT. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t IN1                       : 5 ;  /*!< [ 9: 5] : Select value for IN1 of output LUT. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t IN2                       : 5 ;  /*!< [14:10] : Select value for IN2 of output LUT. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t FN                        : 8 ;  /*!< [22:15] : Output function for output LUT Reset type: SYSRSn. */
                  uint32_t RSV_0                     : 9 ;  /*!< [31:23] : reserved. */
        } CLB_OUTPUT_LUT_5b;
    };

    union
    {
        __IOM uint32_t CLB_OUTPUT_LUT_6                  ;  /*!< 0x00000070 : Inp Sel, LUT fns for Out6 */

        struct
        {
            __IOM uint32_t IN0                       : 5 ;  /*!< [ 4: 0] : Select value for IN0 of output LUT. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t IN1                       : 5 ;  /*!< [ 9: 5] : Select value for IN1 of output LUT. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t IN2                       : 5 ;  /*!< [14:10] : Select value for IN2 of output LUT. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t FN                        : 8 ;  /*!< [22:15] : Output function for output LUT Reset type: SYSRSn. */
                  uint32_t RSV_0                     : 9 ;  /*!< [31:23] : reserved. */
        } CLB_OUTPUT_LUT_6b;
    };

    union
    {
        __IOM uint32_t CLB_OUTPUT_LUT_7                  ;  /*!< 0x00000074 : Inp Sel, LUT fns for Out7 */

        struct
        {
            __IOM uint32_t IN0                       : 5 ;  /*!< [ 4: 0] : Select value for IN0 of output LUT. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t IN1                       : 5 ;  /*!< [ 9: 5] : Select value for IN1 of output LUT. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t IN2                       : 5 ;  /*!< [14:10] : Select value for IN2 of output LUT. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t FN                        : 8 ;  /*!< [22:15] : Output function for output LUT Reset type: SYSRSn. */
                  uint32_t RSV_0                     : 9 ;  /*!< [31:23] : reserved. */
        } CLB_OUTPUT_LUT_7b;
    };

    union
    {
        __IOM uint32_t CLB_HLC_EVENT_SEL                 ;  /*!< 0x00000078 : Event Selector register for the High Level controller */

        struct
        {
            __IOM uint32_t EVENT0_SEL                : 5 ;  /*!< [ 4: 0] : 5 bit select value for EVENT0 of the High Level Controller. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t EVENT1_SEL                : 5 ;  /*!< [ 9: 5] : 5 bit select value for EVENT1 of the High Level Controller. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t EVENT2_SEL                : 5 ;  /*!< [14:10] : 5 bit select value for EVENT2 of the High Level Controller. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t EVENT3_SEL                : 5 ;  /*!< [19:15] : 5 bit select value for EVENT3 of the High Level Controller. See the Static Switch Block Output Mux Table.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 12;  /*!< [31:20] : reserved. */
        } CLB_HLC_EVENT_SELb;
    };

    union
    {
        __IOM uint32_t CLB_COUNT_MATCH_TAP_SEL           ;  /*!< 0x0000007c : Counter tap values for match1 and match2 outputs */

        struct
        {
            __IOM uint32_t COUNT0_MATCH1             : 5 ;  /*!< [ 4: 0] : 5 bit MUX Select for Match1 Tap for Counter Unit 0 Reset type: SYSRSn. */
            __IOM uint32_t COUNT1_MATCH1             : 5 ;  /*!< [ 9: 5] : 5 bit MUX Select for Match1 Tap for Counter Unit 1 Reset type: SYSRSn. */
            __IOM uint32_t COUNT2_MATCH1             : 5 ;  /*!< [14:10] : 5 bit MUX Select for Match1 Tap for Counter Unit 2 Reset type: SYSRSn. */
                  uint32_t RSV_0                     : 1 ;  /*!< [15:15] : reserved. */
            __IOM uint32_t COUNT0_MATCH2             : 5 ;  /*!< [20:16] : 5 bit MUX Select for Match2 Tap for Counter Unit 0 Reset type: SYSRSn. */
            __IOM uint32_t COUNT1_MATCH2             : 5 ;  /*!< [25:21] : 5 bit MUX Select for Match2 Tap for Counter Unit 1 Reset type: SYSRSn. */
            __IOM uint32_t COUNT2_MATCH2             : 5 ;  /*!< [30:26] : 5 bit MUX Select for Match2 Tap for Counter Unit 2 Reset type: SYSRSn. */
                  uint32_t RSV_1                     : 1 ;  /*!< [31:31] : reserved. */
        } CLB_COUNT_MATCH_TAP_SELb;
    };

    union
    {
        __IOM uint32_t CLB_OUTPUT_COND_CTRL_0            ;  /*!< 0x00000080 : Output conditioning control for output 0 */

        struct
        {
            __IOM uint32_t LEVEL_1_SEL               : 1 ;  /*!< [ 0: 0] : First level MUX select value
                                                                           0 Direct signal sent as output to next level
                                                                           1 Inverted signal sent as output to the next level Reset type: SYSRSn */
            __IOM uint32_t LEVEL_2_SEL               : 2 ;  /*!< [ 2: 1] : Controls Second level Mux select
                                                                           00 Input Signal sent as output to next level
                                                                           01 Input Signal AND Gating_control sent as output to next level 10 Input Signal OR Gating_control sent as output to next level 11 Input Signal XOR Gating_control sent as output to next level Reset type: SYSRSn */
            __IOM uint32_t LEVEL_3_SEL               : 2 ;  /*!< [ 4: 3] : Controls Third level Mux select
                                                                           00 Input Signal will be sent as is to the output
                                                                           01 Rising edge of Input signal will cause asynchronous CLEAR of the output
                                                                           10 Rising edge of Input signal will cause asynchronous SET of the output
                                                                           11 Input Signal delayed by 1 clock cycle will be sent to the output Reset type: SYSRSn */
            __IOM uint32_t SEL_GATING_CTRL           : 3 ;  /*!< [ 7: 5] : 3 bit MUX selects which will select one of the 8 CELL outputs for Gating control.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SEL_RELEASE_CTRL          : 3 ;  /*!< [10: 8] : 3 bit MUX selects which will select one of the 8 CELL outputs for Release control.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t HW_GATING_CTRL_SEL        : 1 ;  /*!< [11:11] : Controls whether the HW (CELL outputs) or software (GP_REG) will act as the gating control
                                                                           0 SW register value will act as gating control
                                                                           1 Selected CELL output will act as gating control Reset type: SYSRSn */
            __IOM uint32_t HW_RLS_CTRL_SEL           : 1 ;  /*!< [12:12] : Controls whether the HW (CELL outputs) or software (GP_REG) will act as the release control
                                                                           0 SW register value will act as release control
                                                                           1 Selected CELL output will act as release control Reset type: SYSRSn */
            __IOM uint32_t SEL_RAW_IN                : 1 ;  /*!< [13:13] : Controls whether the CELL outputs or inputs are sent to the output conditioning block logic.
                                                                           0 = CELL output (internally delayed by 1 cycle) is used. 1 = CELL input (raw) is used.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t ASYNC_COND_EN             : 1 ;  /*!< [14:14] : Controls whether the output will pass through the asynchronous conditioning block or bypass it.
                                                                           0 Bypass the asynchronous conditioning block 1 Enable the asynchronous conditioning path Reset type: SYSRSn */
                  uint32_t RSV_0                     : 17;  /*!< [31:15] : reserved. */
        } CLB_OUTPUT_COND_CTRL_0b;
    };

    union
    {
        __IOM uint32_t CLB_OUTPUT_COND_CTRL_1            ;  /*!< 0x00000084 : Output conditioning control for output 1 */

        struct
        {
            __IOM uint32_t LEVEL_1_SEL               : 1 ;  /*!< [ 0: 0] : First level MUX select value
                                                                           0 Direct signal sent as output to next level
                                                                           1 Inverted signal sent as output to the next level Reset type: SYSRSn */
            __IOM uint32_t LEVEL_2_SEL               : 2 ;  /*!< [ 2: 1] : Controls Second level Mux select
                                                                           00 Input Signal sent as output to next level
                                                                           01 Input Signal AND Gating_control sent as output to next level 10 Input Signal OR Gating_control sent as output to next level 11 Input Signal XOR Gating_control sent as output to next level Reset type: SYSRSn */
            __IOM uint32_t LEVEL_3_SEL               : 2 ;  /*!< [ 4: 3] : Controls Third level Mux select
                                                                           00 Input Signal will be sent as is to the output
                                                                           01 Rising edge of Input signal will cause asynchronous CLEAR of the output
                                                                           10 Rising edge of Input signal will cause asynchronous SET of the output
                                                                           11 Input Signal delayed by 1 clock cycle will be sent to the output Reset type: SYSRSn */
            __IOM uint32_t SEL_GATING_CTRL           : 3 ;  /*!< [ 7: 5] : 3 bit MUX selects which will select one of the 8 CELL outputs for Gating control.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SEL_RELEASE_CTRL          : 3 ;  /*!< [10: 8] : 3 bit MUX selects which will select one of the 8 CELL outputs for Release control.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t HW_GATING_CTRL_SEL        : 1 ;  /*!< [11:11] : Controls whether the HW (CELL outputs) or software (GP_REG) will act as the gating control
                                                                           0 SW register value will act as gating control
                                                                           1 Selected CELL output will act as gating control Reset type: SYSRSn */
            __IOM uint32_t HW_RLS_CTRL_SEL           : 1 ;  /*!< [12:12] : Controls whether the HW (CELL outputs) or software (GP_REG) will act as the release control
                                                                           0 SW register value will act as release control
                                                                           1 Selected CELL output will act as release control Reset type: SYSRSn */
            __IOM uint32_t SEL_RAW_IN                : 1 ;  /*!< [13:13] : Controls whether the CELL outputs or inputs are sent to the output conditioning block logic.
                                                                           0 = CELL output (internally delayed by 1 cycle) is used. 1 = CELL input (raw) is used.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t ASYNC_COND_EN             : 1 ;  /*!< [14:14] : Controls whether the output will pass through the asynchronous conditioning block or bypass it.
                                                                           0 Bypass the asynchronous conditioning block 1 Enable the asynchronous conditioning path Reset type: SYSRSn */
                  uint32_t RSV_0                     : 17;  /*!< [31:15] : reserved. */
        } CLB_OUTPUT_COND_CTRL_1b;
    };

    union
    {
        __IOM uint32_t CLB_OUTPUT_COND_CTRL_2            ;  /*!< 0x00000088 : Output conditioning control for output 2 */

        struct
        {
            __IOM uint32_t LEVEL_1_SEL               : 1 ;  /*!< [ 0: 0] : First level MUX select value
                                                                           0 Direct signal sent as output to next level
                                                                           1 Inverted signal sent as output to the next level Reset type: SYSRSn */
            __IOM uint32_t LEVEL_2_SEL               : 2 ;  /*!< [ 2: 1] : Controls Second level Mux select
                                                                           00 Input Signal sent as output to next level
                                                                           01 Input Signal AND Gating_control sent as output to next level 10 Input Signal OR Gating_control sent as output to next level 11 Input Signal XOR Gating_control sent as output to next level Reset type: SYSRSn */
            __IOM uint32_t LEVEL_3_SEL               : 2 ;  /*!< [ 4: 3] : Controls Third level Mux select
                                                                           00 Input Signal will be sent as is to the output
                                                                           01 Rising edge of Input signal will cause asynchronous CLEAR of the output
                                                                           10 Rising edge of Input signal will cause asynchronous SET of the output
                                                                           11 Input Signal delayed by 1 clock cycle will be sent to the output Reset type: SYSRSn */
            __IOM uint32_t SEL_GATING_CTRL           : 3 ;  /*!< [ 7: 5] : 3 bit MUX selects which will select one of the 8 CELL outputs for Gating control.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SEL_RELEASE_CTRL          : 3 ;  /*!< [10: 8] : 3 bit MUX selects which will select one of the 8 CELL outputs for Release control.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t HW_GATING_CTRL_SEL        : 1 ;  /*!< [11:11] : Controls whether the HW (CELL outputs) or software (GP_REG) will act as the gating control
                                                                           0 SW register value will act as gating control
                                                                           1 Selected CELL output will act as gating control Reset type: SYSRSn */
            __IOM uint32_t HW_RLS_CTRL_SEL           : 1 ;  /*!< [12:12] : Controls whether the HW (CELL outputs) or software (GP_REG) will act as the release control
                                                                           0 SW register value will act as release control
                                                                           1 Selected CELL output will act as release control Reset type: SYSRSn */
            __IOM uint32_t SEL_RAW_IN                : 1 ;  /*!< [13:13] : Controls whether the CELL outputs or inputs are sent to the output conditioning block logic.
                                                                           0 = CELL output (internally delayed by 1 cycle) is used. 1 = CELL input (raw) is used.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t ASYNC_COND_EN             : 1 ;  /*!< [14:14] : Controls whether the output will pass through the asynchronous conditioning block or bypass it.
                                                                           0 Bypass the asynchronous conditioning block 1 Enable the asynchronous conditioning path Reset type: SYSRSn */
                  uint32_t RSV_0                     : 17;  /*!< [31:15] : reserved. */
        } CLB_OUTPUT_COND_CTRL_2b;
    };

    union
    {
        __IOM uint32_t CLB_OUTPUT_COND_CTRL_3            ;  /*!< 0x0000008c : Output conditioning control for output 3 */

        struct
        {
            __IOM uint32_t LEVEL_1_SEL               : 1 ;  /*!< [ 0: 0] : First level MUX select value
                                                                           0 Direct signal sent as output to next level
                                                                           1 Inverted signal sent as output to the next level Reset type: SYSRSn */
            __IOM uint32_t LEVEL_2_SEL               : 2 ;  /*!< [ 2: 1] : Controls Second level Mux select
                                                                           00 Input Signal sent as output to next level
                                                                           01 Input Signal AND Gating_control sent as output to next level 10 Input Signal OR Gating_control sent as output to next level 11 Input Signal XOR Gating_control sent as output to next level Reset type: SYSRSn */
            __IOM uint32_t LEVEL_3_SEL               : 2 ;  /*!< [ 4: 3] : Controls Third level Mux select
                                                                           00 Input Signal will be sent as is to the output
                                                                           01 Rising edge of Input signal will cause asynchronous CLEAR of the output
                                                                           10 Rising edge of Input signal will cause asynchronous SET of the output
                                                                           11 Input Signal delayed by 1 clock cycle will be sent to the output Reset type: SYSRSn */
            __IOM uint32_t SEL_GATING_CTRL           : 3 ;  /*!< [ 7: 5] : 3 bit MUX selects which will select one of the 8 CELL outputs for Gating control.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SEL_RELEASE_CTRL          : 3 ;  /*!< [10: 8] : 3 bit MUX selects which will select one of the 8 CELL outputs for Release control.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t HW_GATING_CTRL_SEL        : 1 ;  /*!< [11:11] : Controls whether the HW (CELL outputs) or software (GP_REG) will act as the gating control
                                                                           0 SW register value will act as gating control
                                                                           1 Selected CELL output will act as gating control Reset type: SYSRSn */
            __IOM uint32_t HW_RLS_CTRL_SEL           : 1 ;  /*!< [12:12] : Controls whether the HW (CELL outputs) or software (GP_REG) will act as the release control
                                                                           0 SW register value will act as release control
                                                                           1 Selected CELL output will act as release control Reset type: SYSRSn */
            __IOM uint32_t SEL_RAW_IN                : 1 ;  /*!< [13:13] : Controls whether the CELL outputs or inputs are sent to the output conditioning block logic.
                                                                           0 = CELL output (internally delayed by 1 cycle) is used. 1 = CELL input (raw) is used.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t ASYNC_COND_EN             : 1 ;  /*!< [14:14] : Controls whether the output will pass through the asynchronous conditioning block or bypass it.
                                                                           0 Bypass the asynchronous conditioning block 1 Enable the asynchronous conditioning path Reset type: SYSRSn */
                  uint32_t RSV_0                     : 17;  /*!< [31:15] : reserved. */
        } CLB_OUTPUT_COND_CTRL_3b;
    };

    union
    {
        __IOM uint32_t CLB_OUTPUT_COND_CTRL_4            ;  /*!< 0x00000090 : Output conditioning control for output 4 */

        struct
        {
            __IOM uint32_t LEVEL_1_SEL               : 1 ;  /*!< [ 0: 0] : First level MUX select value
                                                                           0 Direct signal sent as output to next level
                                                                           1 Inverted signal sent as output to the next level Reset type: SYSRSn */
            __IOM uint32_t LEVEL_2_SEL               : 2 ;  /*!< [ 2: 1] : Controls Second level Mux select
                                                                           00 Input Signal sent as output to next level
                                                                           01 Input Signal AND Gating_control sent as output to next level 10 Input Signal OR Gating_control sent as output to next level 11 Input Signal XOR Gating_control sent as output to next level Reset type: SYSRSn */
            __IOM uint32_t LEVEL_3_SEL               : 2 ;  /*!< [ 4: 3] : Controls Third level Mux select
                                                                           00 Input Signal will be sent as is to the output
                                                                           01 Rising edge of Input signal will cause asynchronous CLEAR of the output
                                                                           10 Rising edge of Input signal will cause asynchronous SET of the output
                                                                           11 Input Signal delayed by 1 clock cycle will be sent to the output Reset type: SYSRSn */
            __IOM uint32_t SEL_GATING_CTRL           : 3 ;  /*!< [ 7: 5] : 3 bit MUX selects which will select one of the 8 CELL outputs for Gating control.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SEL_RELEASE_CTRL          : 3 ;  /*!< [10: 8] : 3 bit MUX selects which will select one of the 8 CELL outputs for Release control.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t HW_GATING_CTRL_SEL        : 1 ;  /*!< [11:11] : Controls whether the HW (CELL outputs) or software (GP_REG) will act as the gating control
                                                                           0 SW register value will act as gating control
                                                                           1 Selected CELL output will act as gating control Reset type: SYSRSn */
            __IOM uint32_t HW_RLS_CTRL_SEL           : 1 ;  /*!< [12:12] : Controls whether the HW (CELL outputs) or software (GP_REG) will act as the release control
                                                                           0 SW register value will act as release control
                                                                           1 Selected CELL output will act as release control Reset type: SYSRSn */
            __IOM uint32_t SEL_RAW_IN                : 1 ;  /*!< [13:13] : Controls whether the CELL outputs or inputs are sent to the output conditioning block logic.
                                                                           0 = CELL output (internally delayed by 1 cycle) is used. 1 = CELL input (raw) is used.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t ASYNC_COND_EN             : 1 ;  /*!< [14:14] : Controls whether the output will pass through the asynchronous conditioning block or bypass it.
                                                                           0 Bypass the asynchronous conditioning block 1 Enable the asynchronous conditioning path Reset type: SYSRSn */
                  uint32_t RSV_0                     : 17;  /*!< [31:15] : reserved. */
        } CLB_OUTPUT_COND_CTRL_4b;
    };

    union
    {
        __IOM uint32_t CLB_OUTPUT_COND_CTRL_5            ;  /*!< 0x00000094 : Output conditioning control for output 5 */

        struct
        {
            __IOM uint32_t LEVEL_1_SEL               : 1 ;  /*!< [ 0: 0] : First level MUX select value
                                                                           0 Direct signal sent as output to next level
                                                                           1 Inverted signal sent as output to the next level Reset type: SYSRSn */
            __IOM uint32_t LEVEL_2_SEL               : 2 ;  /*!< [ 2: 1] : Controls Second level Mux select
                                                                           00 Input Signal sent as output to next level
                                                                           01 Input Signal AND Gating_control sent as output to next level 10 Input Signal OR Gating_control sent as output to next level 11 Input Signal XOR Gating_control sent as output to next level Reset type: SYSRSn */
            __IOM uint32_t LEVEL_3_SEL               : 2 ;  /*!< [ 4: 3] : Controls Third level Mux select
                                                                           00 Input Signal will be sent as is to the output
                                                                           01 Rising edge of Input signal will cause asynchronous CLEAR of the output
                                                                           10 Rising edge of Input signal will cause asynchronous SET of the output
                                                                           11 Input Signal delayed by 1 clock cycle will be sent to the output Reset type: SYSRSn */
            __IOM uint32_t SEL_GATING_CTRL           : 3 ;  /*!< [ 7: 5] : 3 bit MUX selects which will select one of the 8 CELL outputs for Gating control.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SEL_RELEASE_CTRL          : 3 ;  /*!< [10: 8] : 3 bit MUX selects which will select one of the 8 CELL outputs for Release control.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t HW_GATING_CTRL_SEL        : 1 ;  /*!< [11:11] : Controls whether the HW (CELL outputs) or software (GP_REG) will act as the gating control
                                                                           0 SW register value will act as gating control
                                                                           1 Selected CELL output will act as gating control Reset type: SYSRSn */
            __IOM uint32_t HW_RLS_CTRL_SEL           : 1 ;  /*!< [12:12] : Controls whether the HW (CELL outputs) or software (GP_REG) will act as the release control
                                                                           0 SW register value will act as release control
                                                                           1 Selected CELL output will act as release control Reset type: SYSRSn */
            __IOM uint32_t SEL_RAW_IN                : 1 ;  /*!< [13:13] : Controls whether the CELL outputs or inputs are sent to the output conditioning block logic.
                                                                           0 = CELL output (internally delayed by 1 cycle) is used. 1 = CELL input (raw) is used.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t ASYNC_COND_EN             : 1 ;  /*!< [14:14] : Controls whether the output will pass through the asynchronous conditioning block or bypass it.
                                                                           0 Bypass the asynchronous conditioning block 1 Enable the asynchronous conditioning path Reset type: SYSRSn */
                  uint32_t RSV_0                     : 17;  /*!< [31:15] : reserved. */
        } CLB_OUTPUT_COND_CTRL_5b;
    };

    union
    {
        __IOM uint32_t CLB_OUTPUT_COND_CTRL_6            ;  /*!< 0x00000098 : Output conditioning control for output 6 */

        struct
        {
            __IOM uint32_t LEVEL_1_SEL               : 1 ;  /*!< [ 0: 0] : First level MUX select value
                                                                           0 Direct signal sent as output to next level
                                                                           1 Inverted signal sent as output to the next level Reset type: SYSRSn */
            __IOM uint32_t LEVEL_2_SEL               : 2 ;  /*!< [ 2: 1] : Controls Second level Mux select
                                                                           00 Input Signal sent as output to next level
                                                                           01 Input Signal AND Gating_control sent as output to next level 10 Input Signal OR Gating_control sent as output to next level 11 Input Signal XOR Gating_control sent as output to next level Reset type: SYSRSn */
            __IOM uint32_t LEVEL_3_SEL               : 2 ;  /*!< [ 4: 3] : Controls Third level Mux select
                                                                           00 Input Signal will be sent as is to the output
                                                                           01 Rising edge of Input signal will cause asynchronous CLEAR of the output
                                                                           10 Rising edge of Input signal will cause asynchronous SET of the output
                                                                           11 Input Signal delayed by 1 clock cycle will be sent to the output Reset type: SYSRSn */
            __IOM uint32_t SEL_GATING_CTRL           : 3 ;  /*!< [ 7: 5] : 3 bit MUX selects which will select one of the 8 CELL outputs for Gating control.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SEL_RELEASE_CTRL          : 3 ;  /*!< [10: 8] : 3 bit MUX selects which will select one of the 8 CELL outputs for Release control.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t HW_GATING_CTRL_SEL        : 1 ;  /*!< [11:11] : Controls whether the HW (CELL outputs) or software (GP_REG) will act as the gating control
                                                                           0 SW register value will act as gating control
                                                                           1 Selected CELL output will act as gating control Reset type: SYSRSn */
            __IOM uint32_t HW_RLS_CTRL_SEL           : 1 ;  /*!< [12:12] : Controls whether the HW (CELL outputs) or software (GP_REG) will act as the release control
                                                                           0 SW register value will act as release control
                                                                           1 Selected CELL output will act as release control Reset type: SYSRSn */
            __IOM uint32_t SEL_RAW_IN                : 1 ;  /*!< [13:13] : Controls whether the CELL outputs or inputs are sent to the output conditioning block logic.
                                                                           0 = CELL output (internally delayed by 1 cycle) is used. 1 = CELL input (raw) is used.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t ASYNC_COND_EN             : 1 ;  /*!< [14:14] : Controls whether the output will pass through the asynchronous conditioning block or bypass it.
                                                                           0 Bypass the asynchronous conditioning block 1 Enable the asynchronous conditioning path Reset type: SYSRSn */
                  uint32_t RSV_0                     : 17;  /*!< [31:15] : reserved. */
        } CLB_OUTPUT_COND_CTRL_6b;
    };

    union
    {
        __IOM uint32_t CLB_OUTPUT_COND_CTRL_7            ;  /*!< 0x0000009c : Output conditioning control for output 7 */

        struct
        {
            __IOM uint32_t LEVEL_1_SEL               : 1 ;  /*!< [ 0: 0] : First level MUX select value
                                                                           0 Direct signal sent as output to next level
                                                                           1 Inverted signal sent as output to the next level Reset type: SYSRSn */
            __IOM uint32_t LEVEL_2_SEL               : 2 ;  /*!< [ 2: 1] : Controls Second level Mux select
                                                                           00 Input Signal sent as output to next level
                                                                           01 Input Signal AND Gating_control sent as output to next level 10 Input Signal OR Gating_control sent as output to next level 11 Input Signal XOR Gating_control sent as output to next level Reset type: SYSRSn */
            __IOM uint32_t LEVEL_3_SEL               : 2 ;  /*!< [ 4: 3] : Controls Third level Mux select
                                                                           00 Input Signal will be sent as is to the output
                                                                           01 Rising edge of Input signal will cause asynchronous CLEAR of the output
                                                                           10 Rising edge of Input signal will cause asynchronous SET of the output
                                                                           11 Input Signal delayed by 1 clock cycle will be sent to the output Reset type: SYSRSn */
            __IOM uint32_t SEL_GATING_CTRL           : 3 ;  /*!< [ 7: 5] : 3 bit MUX selects which will select one of the 8 CELL outputs for Gating control.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SEL_RELEASE_CTRL          : 3 ;  /*!< [10: 8] : 3 bit MUX selects which will select one of the 8 CELL outputs for Release control.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t HW_GATING_CTRL_SEL        : 1 ;  /*!< [11:11] : Controls whether the HW (CELL outputs) or software (GP_REG) will act as the gating control
                                                                           0 SW register value will act as gating control
                                                                           1 Selected CELL output will act as gating control Reset type: SYSRSn */
            __IOM uint32_t HW_RLS_CTRL_SEL           : 1 ;  /*!< [12:12] : Controls whether the HW (CELL outputs) or software (GP_REG) will act as the release control
                                                                           0 SW register value will act as release control
                                                                           1 Selected CELL output will act as release control Reset type: SYSRSn */
            __IOM uint32_t SEL_RAW_IN                : 1 ;  /*!< [13:13] : Controls whether the CELL outputs or inputs are sent to the output conditioning block logic.
                                                                           0 = CELL output (internally delayed by 1 cycle) is used. 1 = CELL input (raw) is used.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t ASYNC_COND_EN             : 1 ;  /*!< [14:14] : Controls whether the output will pass through the asynchronous conditioning block or bypass it.
                                                                           0 Bypass the asynchronous conditioning block 1 Enable the asynchronous conditioning path Reset type: SYSRSn */
                  uint32_t RSV_0                     : 17;  /*!< [31:15] : reserved. */
        } CLB_OUTPUT_COND_CTRL_7b;
    };

    union
    {
        __IOM uint16_t CLB_MISC_ACCESS_CTRL              ;  /*!< 0x000000a0 : Miscellaneous Access and enable control */

        struct
        {
                  uint16_t RSV_0                     : 1 ;  /*!< [ 0: 0] : reserved. */
            __IOM uint16_t BLKEN                     : 1 ;  /*!< [ 1: 1] : This bit is used to block writes to CLB_OUT_EN 0 Writes to CLB_OUT_EN are allowed
                                                                           1 Writes to CLB_OUT_EN are blocked Reset type: SYSRSn */
                  uint16_t RSV_1                     : 14;  /*!< [15: 2] : reserved. */
        } CLB_MISC_ACCESS_CTRLb;
    };

    uint8_t    RSV_0XA2[862]                             ;
    union
    {
        __IOM uint32_t CLB_LOAD_EN                       ;  /*!< 0x00000400 : Global enable & indirect load enable control */

        struct
        {
            __IOM uint32_t LOAD_EN                   : 1 ;  /*!< [ 0: 0] : A write with this bit set to 1 will pulse the Load Enable signal for the indirect register loads in the CELL.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GLOBAL_EN                 : 1 ;  /*!< [ 1: 1] : This bit is a global enable signal for the logic in the CELL. This also acts as a soft reset for the CELL logic. This bit is normally set after all the other configuration settings are completed. This bit is LOCK protected.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 30;  /*!< [31: 2] : reserved. */
        } CLB_LOAD_ENb;
    };

    union
    {
        __IOM uint32_t CLB_LOAD_ADDR                     ;  /*!< 0x00000404 : Indirect address */

        struct
        {
            __IOM uint32_t ADDR                      : 6 ;  /*!< [ 5: 0] : These are the address bits used for writing to the indirect address space of the CELL.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 26;  /*!< [31: 6] : reserved. */
        } CLB_LOAD_ADDRb;
    };

    union
    {
        __IOM uint32_t CLB_LOAD_DATA                     ;  /*!< 0x00000408 : Data for indirect loads */

        struct
        {
            __IOM uint32_t DATA                      : 32;  /*!< [31: 0] : This register holds the 32-bit data for writing to the indirect address space of the CELL.
                                                                           Reset type: SYSRSn */
        } CLB_LOAD_DATAb;
    };

    union
    {
        __IOM uint32_t CLB_INPUT_FILTER                  ;  /*!< 0x0000040c : Input filter selection for both edge detection and synchronizers */

        struct
        {
            __IOM uint32_t FIN0                      : 2 ;  /*!< [ 1: 0] : Input filter selection for CELL Input 0
                                                                           2 bits are used to define the edge filtering . 00 : No filtering
                                                                           01 : Rising edge detect 10 : Falling edge detect 11 : Any edge detect Reset type: SYSRSn */
            __IOM uint32_t FIN1                      : 2 ;  /*!< [ 3: 2] : Input filter selection for CELL Input 1
                                                                           2 bits are used to define the edge filtering . 00 : No filtering
                                                                           01 : Rising edge detect 10 : Falling edge detect 11 : Any edge detect Reset type: SYSRSn */
            __IOM uint32_t FIN2                      : 2 ;  /*!< [ 5: 4] : Input filter selection for CELL Input 2
                                                                           2 bits are used to define the edge filtering . 00 : No filtering
                                                                           01 : Rising edge detect 10 : Falling edge detect 11 : Any edge detect Reset type: SYSRSn */
            __IOM uint32_t FIN3                      : 2 ;  /*!< [ 7: 6] : Input filter selection for CELL Input 3
                                                                           2 bits are used to define the edge filtering . 00 : No filtering
                                                                           01 : Rising edge detect 10 : Falling edge detect 11 : Any edge detect Reset type: SYSRSn */
            __IOM uint32_t FIN4                      : 2 ;  /*!< [ 9: 8] : Input filter selection for CELL Input 4
                                                                           2 bits are used to define the edge filtering . 00 : No filtering
                                                                           01 : Rising edge detect 10 : Falling edge detect 11 : Any edge detect Reset type: SYSRSn */
            __IOM uint32_t FIN5                      : 2 ;  /*!< [11:10] : Input filter selection for CELL Input 5
                                                                           2 bits are used to define the edge filtering . 00 : No filtering
                                                                           01 : Rising edge detect 10 : Falling edge detect 11 : Any edge detect Reset type: SYSRSn */
            __IOM uint32_t FIN6                      : 2 ;  /*!< [13:12] : Input filter selection for CELL Input 6
                                                                           2 bits are used to define the edge filtering . 00 : No filtering
                                                                           01 : Rising edge detect 10 : Falling edge detect 11 : Any edge detect Reset type: SYSRSn */
            __IOM uint32_t FIN7                      : 2 ;  /*!< [15:14] : Input filter selection for CELL Input 7
                                                                           2 bits are used to define the edge filtering . 00 : No filtering
                                                                           01 : Rising edge detect 10 : Falling edge detect 11 : Any edge detect Reset type: SYSRSn */
            __IOM uint32_t SYNC0                     : 1 ;  /*!< [16:16] : Synchronizer Select Control for Input 0 Reset type: SYSRSn. */
            __IOM uint32_t SYNC1                     : 1 ;  /*!< [17:17] : Synchronizer Select Control for Input 1 Reset type: SYSRSn. */
            __IOM uint32_t SYNC2                     : 1 ;  /*!< [18:18] : Synchronizer Select Control for Input 2 Reset type: SYSRSn. */
            __IOM uint32_t SYNC3                     : 1 ;  /*!< [19:19] : Synchronizer Select Control for Input 3 Reset type: SYSRSn. */
            __IOM uint32_t SYNC4                     : 1 ;  /*!< [20:20] : Synchronizer Select Control for Input 4 Reset type: SYSRSn. */
            __IOM uint32_t SYNC5                     : 1 ;  /*!< [21:21] : Synchronizer Select Control for Input 5 Reset type: SYSRSn. */
            __IOM uint32_t SYNC6                     : 1 ;  /*!< [22:22] : Synchronizer Select Control for Input 6 Reset type: SYSRSn. */
            __IOM uint32_t SYNC7                     : 1 ;  /*!< [23:23] : Synchronizer Select Control for Input 7 Reset type: SYSRSn. */
                  uint32_t RSV_0                     : 8 ;  /*!< [31:24] : reserved. */
        } CLB_INPUT_FILTERb;
    };

    union
    {
        __IOM uint32_t CLB_IN_MUX_SEL_0                  ;  /*!< 0x00000410 : Input selection to decide between Signals and GP register */

        struct
        {
            __IOM uint32_t SEL_GP_IN_0               : 1 ;  /*!< [ 0: 0] : Select control for Input 0 to decide between external input and CLB_GP_REG[0]
                                                                           0 : Input comes from selected external input 1 : Input comes from CLB_GP_REG[0] Reset type: SYSRSn */
            __IOM uint32_t SEL_GP_IN_1               : 1 ;  /*!< [ 1: 1] : Select control for Input 1 to decide between external input and CLB_GP_REG[1]
                                                                           0 : Input comes from selected external input 1 : Input comes from CLB_GP_REG[1] Reset type: SYSRSn */
            __IOM uint32_t SEL_GP_IN_2               : 1 ;  /*!< [ 2: 2] : Select control for Input 2 to decide between external input and CLB_GP_REG[2]
                                                                           0 : Input comes from selected external input 1 : Input comes from CLB_GP_REG[2] Reset type: SYSRSn */
            __IOM uint32_t SEL_GP_IN_3               : 1 ;  /*!< [ 3: 3] : Select control for Input 3 to decide between external input and CLB_GP_REG[3]
                                                                           0 : Input comes from selected external input 1 : Input comes from CLB_GP_REG[3] Reset type: SYSRSn */
            __IOM uint32_t SEL_GP_IN_4               : 1 ;  /*!< [ 4: 4] : Select control for Input 4 to decide between external input and CLB_GP_REG[4]
                                                                           0 : Input comes from selected external input 1 : Input comes from CLB_GP_REG[4] Reset type: SYSRSn */
            __IOM uint32_t SEL_GP_IN_5               : 1 ;  /*!< [ 5: 5] : Select control for Input 5 to decide between external input and CLB_GP_REG[5]
                                                                           0 : Input comes from selected external input 1 : Input comes from CLB_GP_REG[5] Reset type: SYSRSn */
            __IOM uint32_t SEL_GP_IN_6               : 1 ;  /*!< [ 6: 6] : Select control for Input 6 to decide between external input and CLB_GP_REG[6]
                                                                           0 : Input comes from selected external input 1 : Input comes from CLB_GP_REG[6] Reset type: SYSRSn */
            __IOM uint32_t SEL_GP_IN_7               : 1 ;  /*!< [ 7: 7] : Select control for Input 7 to decide between external input and CLB_GP_REG[7]
                                                                           0 : Input comes from selected external input 1 : Input comes from CLB_GP_REG[7] Reset type: SYSRSn */
                  uint32_t RSV_0                     : 24;  /*!< [31: 8] : reserved. */
        } CLB_IN_MUX_SEL_0b;
    };

    union
    {
        __IOM uint32_t CLB_LCL_MUX_SEL_1                 ;  /*!< 0x00000414 : Input Mux selection for local mux */

        struct
        {
            __IOM uint32_t LCL_MUX_SEL_IN_0          : 5 ;  /*!< [ 4: 0] : 5 bit MUX Select for Local MUX control for Input 0 See Local Signals and Mux Selection Table
                                                                           Reset type: SYSRSn */
            __IOM uint32_t LCL_MUX_SEL_IN_1          : 5 ;  /*!< [ 9: 5] : 5 bit MUX Select for Local MUX control for Input 1 See Local Signals and Mux Selection Table
                                                                           Reset type: SYSRSn */
            __IOM uint32_t LCL_MUX_SEL_IN_2          : 5 ;  /*!< [14:10] : 5 bit MUX Select for Local MUX control for Input 2 See Local Signals and Mux Selection Table
                                                                           Reset type: SYSRSn */
            __IOM uint32_t LCL_MUX_SEL_IN_3          : 5 ;  /*!< [19:15] : 5 bit MUX Select for Local MUX control for Input 3 See Local Signals and Mux Selection Table
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 8 ;  /*!< [27:20] : reserved. */
            __IOM uint32_t MISC_INPUT_SEL_0          : 1 ;  /*!< [28:28] : Setting this bit to 1 will select MISC_INPUT instead of Local Mux for Input 0
                                                                           Reset type: SYSRSn */
            __IOM uint32_t MISC_INPUT_SEL_1          : 1 ;  /*!< [29:29] : Setting this bit to 1 will select MISC_INPUT instead of Local Mux for Input 1
                                                                           Reset type: SYSRSn */
            __IOM uint32_t MISC_INPUT_SEL_2          : 1 ;  /*!< [30:30] : Setting this bit to 1 will select MISC_INPUT instead of Local Mux for Input 2
                                                                           Reset type: SYSRSn */
            __IOM uint32_t MISC_INPUT_SEL_3          : 1 ;  /*!< [31:31] : Setting this bit to 1 will select MISC_INPUT instead of Local Mux for Input 3
                                                                           Reset type: SYSRSn */
        } CLB_LCL_MUX_SEL_1b;
    };

    union
    {
        __IOM uint32_t CLB_LCL_MUX_SEL_2                 ;  /*!< 0x00000418 : Input Mux selection for local mux */

        struct
        {
            __IOM uint32_t LCL_MUX_SEL_IN_4          : 5 ;  /*!< [ 4: 0] : 5 bit MUX Select for Local MUX control for Input 4 See Local Signals and Mux Selection Table
                                                                           Reset type: SYSRSn */
            __IOM uint32_t LCL_MUX_SEL_IN_5          : 5 ;  /*!< [ 9: 5] : 5 bit MUX Select for Local MUX control for Input 5 See Local Signals and Mux Selection Table
                                                                           Reset type: SYSRSn */
            __IOM uint32_t LCL_MUX_SEL_IN_6          : 5 ;  /*!< [14:10] : 5 bit MUX Select for Local MUX control for Input 6 See Local Signals and Mux Selection Table
                                                                           Reset type: SYSRSn */
            __IOM uint32_t LCL_MUX_SEL_IN_7          : 5 ;  /*!< [19:15] : 5 bit MUX Select for Local MUX control for Input 7 See Local Signals and Mux Selection Table
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 8 ;  /*!< [27:20] : reserved. */
            __IOM uint32_t MISC_INPUT_SEL_4          : 1 ;  /*!< [28:28] : Setting this bit to 1 will select MISC_INPUT instead of Local Mux for Input 4
                                                                           Reset type: SYSRSn */
            __IOM uint32_t MISC_INPUT_SEL_5          : 1 ;  /*!< [29:29] : Setting this bit to 1 will select MISC_INPUT instead of Local Mux for Input 5
                                                                           Reset type: SYSRSn */
            __IOM uint32_t MISC_INPUT_SEL_6          : 1 ;  /*!< [30:30] : Setting this bit to 1 will select MISC_INPUT instead of Local Mux for Input 6
                                                                           Reset type: SYSRSn */
            __IOM uint32_t MISC_INPUT_SEL_7          : 1 ;  /*!< [31:31] : Setting this bit to 1 will select MISC_INPUT instead of Local Mux for Input 7
                                                                           Reset type: SYSRSn */
        } CLB_LCL_MUX_SEL_2b;
    };

    union
    {
        __IOM uint32_t CLB_BUF_PTR                       ;  /*!< 0x0000041c : PUSH and PULL pointers */

        struct
        {
            __IOM uint32_t PULL                      : 8 ;  /*!< [ 7: 0] : 8 bit pointer which indicates the number of data values that have been written by the High Level controller into the buffer. */
                  uint32_t RSV_0                     : 8 ;  /*!< [15: 8] : reserved. */
            __IOM uint32_t PUSH                      : 8 ;  /*!< [23:16] : 8 bit pointer which indicates the number of data values which have been pulled from the buffer by the High Level Controller. This counter will wrap around after 0xff. The Least significant 2 bits are used as the actual pointer for the operation.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_1                     : 8 ;  /*!< [31:24] : reserved. */
        } CLB_BUF_PTRb;
    };

    union
    {
        __IOM uint32_t CLB_GP_REG                        ;  /*!< 0x00000420 : General purpose register for CELL inputs */

        struct
        {
            __IOM uint32_t REG_INPUT                 : 8 ;  /*!< [ 7: 0] : 8 bits which are directly connected to the 8 inputs of the CELL if that corresponding bit is selected in the CLB_IN_MUX_SEL_0 register Reset type: SYSRSn. */
                  uint32_t RSV_0                     : 8 ;  /*!< [15: 8] : reserved. */
            __IOM uint32_t SW_GATING_CTRL_0          : 1 ;  /*!< [16:16] : Software gating control for output 0 of the asynchronous output conditioning block
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SW_GATING_CTRL_1          : 1 ;  /*!< [17:17] : Software gating control for output 1 of the asynchronous output conditioning block
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SW_GATING_CTRL_2          : 1 ;  /*!< [18:18] : Software gating control for output 2 of the asynchronous output conditioning block
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SW_GATING_CTRL_3          : 1 ;  /*!< [19:19] : Software gating control for output 3 of the asynchronous output conditioning block
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SW_GATING_CTRL_4          : 1 ;  /*!< [20:20] : Software gating control for output 4 of the asynchronous output conditioning block
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SW_GATING_CTRL_5          : 1 ;  /*!< [21:21] : Software gating control for output 5 of the asynchronous output conditioning block
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SW_GATING_CTRL_6          : 1 ;  /*!< [22:22] : Software gating control for output 6 of the asynchronous output conditioning block
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SW_GATING_CTRL_7          : 1 ;  /*!< [23:23] : Software gating control for output 7 of the asynchronous output conditioning block
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SW_RLS_CTRL_0             : 1 ;  /*!< [24:24] : Software release control for output 0 of the asynchronous output conditioning block
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SW_RLS_CTRL_1             : 1 ;  /*!< [25:25] : Software release control for output 1 of the asynchronous output conditioning block
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SW_RLS_CTRL_2             : 1 ;  /*!< [26:26] : Software release control for output 2 of the asynchronous output conditioning block
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SW_RLS_CTRL_3             : 1 ;  /*!< [27:27] : Software release control for output 3 of the asynchronous output conditioning block
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SW_RLS_CTRL_4             : 1 ;  /*!< [28:28] : Software release control for output 4 of the asynchronous output conditioning block
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SW_RLS_CTRL_5             : 1 ;  /*!< [29:29] : Software release control for output 5 of the asynchronous output conditioning block
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SW_RLS_CTRL_6             : 1 ;  /*!< [30:30] : Software release control for output 6 of the asynchronous output conditioning block
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SW_RLS_CTRL_7             : 1 ;  /*!< [31:31] : Software release control for output 7 of the asynchronous output conditioning block
                                                                           Reset type: SYSRSn */
        } CLB_GP_REGb;
    };

    union
    {
        __IOM uint32_t CLB_OUT_EN                        ;  /*!< 0x00000424 : CELL output enable register */

        struct
        {
            __IOM uint32_t OUT0                      : 32;  /*!< [31: 0] : 32 bits which are directly driven out as OUTPUT_EN signals. Enabling bit x (x = 0:31) will override the corresponding peripheral signal muxed on the CLB OUTx.
                                                                           Reset type: SYSRSn */
        } CLB_OUT_ENb;
    };

    union
    {
        __IOM uint32_t CLB_GLBL_MUX_SEL_1                ;  /*!< 0x00000428 : Global Mux select for CELL inputs */

        struct
        {
            __IOM uint32_t GLBL_MUX_SEL_IN_0         : 7 ;  /*!< [ 6: 0] : 7 bit MUX Select for Global MUX control for Input 0 See Global Signals and Mux Selection Table
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GLBL_MUX_SEL_IN_1         : 7 ;  /*!< [13: 7] : 7 bit MUX Select for Global MUX control for Input 1 See Global Signals and Mux Selection Table
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GLBL_MUX_SEL_IN_2         : 7 ;  /*!< [20:14] : 7 bit MUX Select for Global MUX control for Input 2 See Global Signals and Mux Selection Table
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GLBL_MUX_SEL_IN_3         : 7 ;  /*!< [27:21] : 7 bit MUX Select for Global MUX control for Input 3 See Global Signals and Mux Selection Table
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 4 ;  /*!< [31:28] : reserved. */
        } CLB_GLBL_MUX_SEL_1b;
    };

    union
    {
        __IOM uint32_t CLB_GLBL_MUX_SEL_2                ;  /*!< 0x0000042c : Global Mux select for CELL inputs */

        struct
        {
            __IOM uint32_t GLBL_MUX_SEL_IN_4         : 7 ;  /*!< [ 6: 0] : 7 bit MUX Select for Global MUX control for Input 4 See Global Signals and Mux Selection Table
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GLBL_MUX_SEL_IN_5         : 7 ;  /*!< [13: 7] : 7 bit MUX Select for Global MUX control for Input 5 See Global Signals and Mux Selection Table
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GLBL_MUX_SEL_IN_6         : 7 ;  /*!< [20:14] : 7 bit MUX Select for Global MUX control for Input 6 See Global Signals and Mux Selection Table
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GLBL_MUX_SEL_IN_7         : 7 ;  /*!< [27:21] : 7 bit MUX Select for Global MUX control for Input 7 See Global Signals and Mux Selection Table
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 4 ;  /*!< [31:28] : reserved. */
        } CLB_GLBL_MUX_SEL_2b;
    };

    uint8_t    RSV_0X430[16]                             ;
    union
    {
        __IM  uint32_t CLB_INTR_TAG_REG                  ;  /*!< 0x00000440 : Interrupt Tag register */

        struct
        {
            __IM  uint32_t TAG                       : 6 ;  /*!< [ 5: 0] : 6 bits which are used by the High Level Controller to set a tag value on flagging interrupts. . This can be cleared through the VBUS interface since it is writeable through the VBUS.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 26;  /*!< [31: 6] : reserved. */
        } CLB_INTR_TAG_REGb;
    };

    union
    {
        __IOM uint32_t CLB_LOCK                          ;  /*!< 0x00000444 : Lock control register */

        struct
        {
            __IOM uint32_t LOCK                      : 1 ;  /*!< [ 0: 0] : This bit is used as a one-time write bit (Set Once). Once it is set to '1', only a reset (SYSRSN 0) will clear this bit back to 0.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 15;  /*!< [15: 1] : reserved. */
            __IM  uint32_t KEY                       : 16;  /*!< [31:16] : These 16 bits act as a key to enable writes to Bit 0 of this register. */
        } CLB_LOCKb;
    };

    union
    {
        __IOM uint32_t CLB_HLC_INSTR_READ_PTR            ;  /*!< 0x00000448 : HLC instruction read pointer */

        struct
        {
            __IOM uint32_t READ_PTR                  : 5 ;  /*!< [ 4: 0] : This is a 5 bit value which will be used as an address pointer to read out HLC instruction memory.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 27;  /*!< [31: 5] : reserved. */
        } CLB_HLC_INSTR_READ_PTRb;
    };

    union
    {
        __IM  uint32_t CLB_HLC_INSTR_VALUE               ;  /*!< 0x0000044c : HLC instruction read value */

        struct
        {
            __IM  uint32_t INSTR                     : 12;  /*!< [11: 0] : This is a 12 bit value which will read the content of the HLC instruction memory address pointed by CLB_HLC_INSTR_READ_PTR register.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 20;  /*!< [31:12] : reserved. */
        } CLB_HLC_INSTR_VALUEb;
    };

    uint8_t    RSV_0X450[12]                             ;
    union
    {
        __IM  uint32_t CLB_DBG_OUT_2                     ;  /*!< 0x0000045c : Visibility for CLB inputs and final asynchronous outputs */

        struct
        {
            __IM  uint32_t OUT                       : 8 ;  /*!< [ 7: 0] : These bits reflect the state of the 8 outputs of the Output Conditioning Block.
                                                                           Reset type: SYSRSn */
            __IM  uint32_t IN                        : 8 ;  /*!< [15: 8] : These bits reflect the state of the 8 inputs finally going to the CELL after selection and input conditioning.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 16;  /*!< [31:16] : reserved. */
        } CLB_DBG_OUT_2b;
    };

    union
    {
        __IM  uint32_t CLB_DBG_R0                        ;  /*!< 0x00000460 : R0 of High level Controller */

        struct
        {
            __IM  uint32_t DBG                       : 32;  /*!< [31: 0] : CLB_DBG_R0
                                                                           Reset type: SYSRSn */
        } CLB_DBG_R0b;
    };

    union
    {
        __IM  uint32_t CLB_DBG_R1                        ;  /*!< 0x00000464 : R1 of High level Controller */

        struct
        {
            __IM  uint32_t DBG                       : 32;  /*!< [31: 0] : CLB_DBG_R1
                                                                           Reset type: SYSRSn */
        } CLB_DBG_R1b;
    };

    union
    {
        __IM  uint32_t CLB_DBG_R2                        ;  /*!< 0x00000468 : R2 of High level Controller */

        struct
        {
            __IM  uint32_t DBG                       : 32;  /*!< [31: 0] : CLB_DBG_R2
                                                                           Reset type: SYSRSn */
        } CLB_DBG_R2b;
    };

    union
    {
        __IM  uint32_t CLB_DBG_R3                        ;  /*!< 0x0000046c : R3 of High level Controller */

        struct
        {
            __IM  uint32_t DBG                       : 32;  /*!< [31: 0] : CLB_DBG_R3
                                                                           Reset type: SYSRSn */
        } CLB_DBG_R3b;
    };

    union
    {
        __IM  uint32_t CLB_DBG_C0                        ;  /*!< 0x00000470 : Count of Unit 0 */

        struct
        {
            __IM  uint32_t DBG                       : 32;  /*!< [31: 0] : CLB_DBG_C0
                                                                           Reset type: SYSRSn */
        } CLB_DBG_C0b;
    };

    union
    {
        __IM  uint32_t CLB_DBG_C1                        ;  /*!< 0x00000474 : Count of Unit 1 */

        struct
        {
            __IM  uint32_t DBG                       : 32;  /*!< [31: 0] : CLB_DBG_C1
                                                                           Reset type: SYSRSn */
        } CLB_DBG_C1b;
    };

    union
    {
        __IM  uint32_t CLB_DBG_C2                        ;  /*!< 0x00000478 : Count of Unit 2 */

        struct
        {
            __IM  uint32_t DBG                       : 32;  /*!< [31: 0] : CLB_DBG_C2
                                                                           Reset type: SYSRSn */
        } CLB_DBG_C2b;
    };

    union
    {
        __IM  uint32_t CLB_DBG_OUT                       ;  /*!< 0x0000047c : Outputs of various units in the Cell */

        struct
        {
                  uint32_t RSV_0                     : 1 ;  /*!< [ 0: 0] : reserved. */
            __IM  uint32_t COUNT0_MATCH2             : 1 ;  /*!< [ 1: 1] : COUNT_MATCH2 UNIT 0
                                                                           Reset type: SYSRSn */
            __IM  uint32_t COUNT0_ZERO               : 1 ;  /*!< [ 2: 2] : COUNT_ZERO UNIT 0
                                                                           Reset type: SYSRSn */
            __IM  uint32_t COUNT0_MATCH1             : 1 ;  /*!< [ 3: 3] : COUNT_MATCH1 UNIT 0
                                                                           Reset type: SYSRSn */
            __IM  uint32_t FSM0_S0                   : 1 ;  /*!< [ 4: 4] : FSM_S0 UNIT 0
                                                                           Reset type: SYSRSn */
            __IM  uint32_t FSM0_S1                   : 1 ;  /*!< [ 5: 5] : FSM_S1 UNIT 0
                                                                           Reset type: SYSRSn */
            __IM  uint32_t FSM0_LUTOUT               : 1 ;  /*!< [ 6: 6] : FSM_LUT_OUT UNIT 0
                                                                           Reset type: SYSRSn */
            __IM  uint32_t LUT40_OUT                 : 1 ;  /*!< [ 7: 7] : LUT4_OUT UNIT 0
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_1                     : 1 ;  /*!< [ 8: 8] : reserved. */
            __IM  uint32_t COUNT1_MATCH2             : 1 ;  /*!< [ 9: 9] : COUNT_MATCH2 UNIT 1
                                                                           Reset type: SYSRSn */
            __IM  uint32_t COUNT1_ZERO               : 1 ;  /*!< [10:10] : COUNT_ZERO UNIT 1
                                                                           Reset type: SYSRSn */
            __IM  uint32_t COUNT1_MATCH1             : 1 ;  /*!< [11:11] : COUNT_MATCH1 UNIT 1
                                                                           Reset type: SYSRSn */
            __IM  uint32_t FSM1_S0                   : 1 ;  /*!< [12:12] : FSM_S0 UNIT 1
                                                                           Reset type: SYSRSn */
            __IM  uint32_t FSM1_S1                   : 1 ;  /*!< [13:13] : FSM_S1 UNIT 1
                                                                           Reset type: SYSRSn */
            __IM  uint32_t FSM1_LUTOUT               : 1 ;  /*!< [14:14] : FSM_LUT_OUT UNIT 1
                                                                           Reset type: SYSRSn */
            __IM  uint32_t LUT41_OUT                 : 1 ;  /*!< [15:15] : LUT4_OUT UNIT 1
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_2                     : 1 ;  /*!< [16:16] : reserved. */
            __IM  uint32_t COUNT2_MATCH2             : 1 ;  /*!< [17:17] : COUNT_MATCH2 UNIT 2
                                                                           Reset type: SYSRSn */
            __IM  uint32_t COUNT2_ZERO               : 1 ;  /*!< [18:18] : COUNT_ZERO UNIT 2
                                                                           Reset type: SYSRSn */
            __IM  uint32_t COUNT2_MATCH1             : 1 ;  /*!< [19:19] : COUNT_MATCH1 UNIT 2
                                                                           Reset type: SYSRSn */
            __IM  uint32_t FSM2_S0                   : 1 ;  /*!< [20:20] : FSM_S0 UNIT 2
                                                                           Reset type: SYSRSn */
            __IM  uint32_t FSM2_S1                   : 1 ;  /*!< [21:21] : FSM_S1 UNIT 2
                                                                           Reset type: SYSRSn */
            __IM  uint32_t FSM2_LUTOUT               : 1 ;  /*!< [22:22] : FSM_LUT_OUT UNIT 2
                                                                           Reset type: SYSRSn */
            __IM  uint32_t LUT42_OUT                 : 1 ;  /*!< [23:23] : LUT4_OUT UNIT 2
                                                                           Reset type: SYSRSn */
            __IM  uint32_t OUT0                      : 1 ;  /*!< [24:24] : CELL Output 0 Reset type: SYSRSn. */
            __IM  uint32_t OUT1                      : 1 ;  /*!< [25:25] : CELL Output 1 Reset type: SYSRSn. */
            __IM  uint32_t OUT2                      : 1 ;  /*!< [26:26] : CELL Output 2 Reset type: SYSRSn. */
            __IM  uint32_t OUT3                      : 1 ;  /*!< [27:27] : CELL Output 3 Reset type: SYSRSn. */
            __IM  uint32_t OUT4                      : 1 ;  /*!< [28:28] : CELL Output 4 Reset type: SYSRSn. */
            __IM  uint32_t OUT5                      : 1 ;  /*!< [29:29] : CELL Output 5 Reset type: SYSRSn. */
            __IM  uint32_t OUT6                      : 1 ;  /*!< [30:30] : CELL Output 6 Reset type: SYSRSn. */
            __IM  uint32_t OUT7                      : 1 ;  /*!< [31:31] : CELL Output 7 Reset type: SYSRSn. */
        } CLB_DBG_OUTb;
    };

    uint8_t    RSV_0X480[896]                            ;
    union
    {
        __IM  uint32_t CLB_PUSH_0                        ;  /*!< 0x00000800 : CLB_PUSH FIFO Registers (from HLC) */

        struct
        {
            __IM  uint32_t PUSH                      : 32;  /*!< [31: 0] : FIFO TO System From CLB Reset type: SYSRSn. */
        } CLB_PUSH_0b;
    };

    union
    {
        __IM  uint32_t CLB_PUSH_1                        ;  /*!< 0x00000804 : CLB_PUSH FIFO Registers (from HLC) */

        struct
        {
            __IM  uint32_t PUSH                      : 32;  /*!< [31: 0] : FIFO TO System From CLB Reset type: SYSRSn. */
        } CLB_PUSH_1b;
    };

    union
    {
        __IM  uint32_t CLB_PUSH_2                        ;  /*!< 0x00000808 : CLB_PUSH FIFO Registers (from HLC) */

        struct
        {
            __IM  uint32_t PUSH                      : 32;  /*!< [31: 0] : FIFO TO System From CLB Reset type: SYSRSn. */
        } CLB_PUSH_2b;
    };

    union
    {
        __IM  uint32_t CLB_PUSH_3                        ;  /*!< 0x0000080c : CLB_PUSH FIFO Registers (from HLC) */

        struct
        {
            __IM  uint32_t PUSH                      : 32;  /*!< [31: 0] : FIFO TO System From CLB Reset type: SYSRSn. */
        } CLB_PUSH_3b;
    };

    uint8_t    RSV_0X810[496]                            ;
    union
    {
        __IOM uint32_t CLB_PULL_0                        ;  /*!< 0x00000a00 : CLB_PULL FIFO Registers (TO HLC) */

        struct
        {
            __IOM uint32_t PULL                      : 32;  /*!< [31: 0] : FIFO From system TO CLB Reset type: SYSRSn. */
        } CLB_PULL_0b;
    };

    union
    {
        __IOM uint32_t CLB_PULL_1                        ;  /*!< 0x00000a04 : CLB_PULL FIFO Registers (TO HLC) */

        struct
        {
            __IOM uint32_t PULL                      : 32;  /*!< [31: 0] : FIFO From system TO CLB Reset type: SYSRSn. */
        } CLB_PULL_1b;
    };

    union
    {
        __IOM uint32_t CLB_PULL_2                        ;  /*!< 0x00000a08 : CLB_PULL FIFO Registers (TO HLC) */

        struct
        {
            __IOM uint32_t PULL                      : 32;  /*!< [31: 0] : FIFO From system TO CLB Reset type: SYSRSn. */
        } CLB_PULL_2b;
    };

    union
    {
        __IOM uint32_t CLB_PULL_3                        ;  /*!< 0x00000a0c : CLB_PULL FIFO Registers (TO HLC) */

        struct
        {
            __IOM uint32_t PULL                      : 32;  /*!< [31: 0] : FIFO From system TO CLB Reset type: SYSRSn. */
        } CLB_PULL_3b;
    };

    uint8_t    RSV_0XA10[496]                            ;
} CLB_TILE_Type;


/*!
 * @}
 */

/*!
 * \name CLB Base Address Definitions
 *
 * @{
 */

/*! \brief CLB_TILE1 base address */
#define CLB_TILE1_BASE (0x40400000UL)
/*! \brief CLB_TILE2 base address */
#define CLB_TILE2_BASE (0x40400c00UL)
/*! \brief CLB_TILE3 base address */
#define CLB_TILE3_BASE (0x40401800UL)
/*! \brief CLB_TILE4 base address */
#define CLB_TILE4_BASE (0x40402400UL)
/*! \brief CLB_TILE1 base pointer */
#define CLB_TILE1 ((CLB_TILE_Type *) CLB_TILE1_BASE)
/*! \brief CLB_TILE2 base pointer */
#define CLB_TILE2 ((CLB_TILE_Type *) CLB_TILE2_BASE)
/*! \brief CLB_TILE3 base pointer */
#define CLB_TILE3 ((CLB_TILE_Type *) CLB_TILE3_BASE)
/*! \brief CLB_TILE4 base pointer */
#define CLB_TILE4 ((CLB_TILE_Type *) CLB_TILE4_BASE)


/*!
 * @}
 */


/*!
 * \name CLB Register Bitfield Definitions
 *
 * @{
 */

/* CLB_COUNT_RESET bitfield */
#define CLB_TILE_CLB_COUNT_RESET_SEL_2_Pos     (10U)                                                                                           /*!< SEL_2 Position 10 */
#define CLB_TILE_CLB_COUNT_RESET_SEL_2_Msk     (0x1fU << CLB_TILE_CLB_COUNT_RESET_SEL_2_Pos)                                                   /*!< SEL_2 Mask 0x00007C00 */
#define CLB_TILE_CLB_COUNT_RESET_SEL_2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_COUNT_RESET_SEL_2_Pos) & CLB_TILE_CLB_COUNT_RESET_SEL_2_Msk)   /*!< SEL_2 Set Value */
#define CLB_TILE_CLB_COUNT_RESET_SEL_2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_COUNT_RESET_SEL_2_Msk) >> CLB_TILE_CLB_COUNT_RESET_SEL_2_Pos)   /*!< SEL_2 Get Value */

#define CLB_TILE_CLB_COUNT_RESET_SEL_1_Pos     (5U)                                                                                            /*!< SEL_1 Position 5 */
#define CLB_TILE_CLB_COUNT_RESET_SEL_1_Msk     (0x1fU << CLB_TILE_CLB_COUNT_RESET_SEL_1_Pos)                                                   /*!< SEL_1 Mask 0x000003E0 */
#define CLB_TILE_CLB_COUNT_RESET_SEL_1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_COUNT_RESET_SEL_1_Pos) & CLB_TILE_CLB_COUNT_RESET_SEL_1_Msk)   /*!< SEL_1 Set Value */
#define CLB_TILE_CLB_COUNT_RESET_SEL_1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_COUNT_RESET_SEL_1_Msk) >> CLB_TILE_CLB_COUNT_RESET_SEL_1_Pos)   /*!< SEL_1 Get Value */

#define CLB_TILE_CLB_COUNT_RESET_SEL_0_Pos     (0U)                                                                                            /*!< SEL_0 Position 0 */
#define CLB_TILE_CLB_COUNT_RESET_SEL_0_Msk     (0x1fU << CLB_TILE_CLB_COUNT_RESET_SEL_0_Pos)                                                   /*!< SEL_0 Mask 0x0000001F */
#define CLB_TILE_CLB_COUNT_RESET_SEL_0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_COUNT_RESET_SEL_0_Pos) & CLB_TILE_CLB_COUNT_RESET_SEL_0_Msk)   /*!< SEL_0 Set Value */
#define CLB_TILE_CLB_COUNT_RESET_SEL_0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_COUNT_RESET_SEL_0_Msk) >> CLB_TILE_CLB_COUNT_RESET_SEL_0_Pos)   /*!< SEL_0 Get Value */

/* CLB_COUNT_MODE_1 bitfield */
#define CLB_TILE_CLB_COUNT_MODE_1_SEL_2_Pos     (10U)                                                                                             /*!< SEL_2 Position 10 */
#define CLB_TILE_CLB_COUNT_MODE_1_SEL_2_Msk     (0x1fU << CLB_TILE_CLB_COUNT_MODE_1_SEL_2_Pos)                                                    /*!< SEL_2 Mask 0x00007C00 */
#define CLB_TILE_CLB_COUNT_MODE_1_SEL_2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_COUNT_MODE_1_SEL_2_Pos) & CLB_TILE_CLB_COUNT_MODE_1_SEL_2_Msk)   /*!< SEL_2 Set Value */
#define CLB_TILE_CLB_COUNT_MODE_1_SEL_2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_COUNT_MODE_1_SEL_2_Msk) >> CLB_TILE_CLB_COUNT_MODE_1_SEL_2_Pos)   /*!< SEL_2 Get Value */

#define CLB_TILE_CLB_COUNT_MODE_1_SEL_1_Pos     (5U)                                                                                              /*!< SEL_1 Position 5 */
#define CLB_TILE_CLB_COUNT_MODE_1_SEL_1_Msk     (0x1fU << CLB_TILE_CLB_COUNT_MODE_1_SEL_1_Pos)                                                    /*!< SEL_1 Mask 0x000003E0 */
#define CLB_TILE_CLB_COUNT_MODE_1_SEL_1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_COUNT_MODE_1_SEL_1_Pos) & CLB_TILE_CLB_COUNT_MODE_1_SEL_1_Msk)   /*!< SEL_1 Set Value */
#define CLB_TILE_CLB_COUNT_MODE_1_SEL_1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_COUNT_MODE_1_SEL_1_Msk) >> CLB_TILE_CLB_COUNT_MODE_1_SEL_1_Pos)   /*!< SEL_1 Get Value */

#define CLB_TILE_CLB_COUNT_MODE_1_SEL_0_Pos     (0U)                                                                                              /*!< SEL_0 Position 0 */
#define CLB_TILE_CLB_COUNT_MODE_1_SEL_0_Msk     (0x1fU << CLB_TILE_CLB_COUNT_MODE_1_SEL_0_Pos)                                                    /*!< SEL_0 Mask 0x0000001F */
#define CLB_TILE_CLB_COUNT_MODE_1_SEL_0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_COUNT_MODE_1_SEL_0_Pos) & CLB_TILE_CLB_COUNT_MODE_1_SEL_0_Msk)   /*!< SEL_0 Set Value */
#define CLB_TILE_CLB_COUNT_MODE_1_SEL_0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_COUNT_MODE_1_SEL_0_Msk) >> CLB_TILE_CLB_COUNT_MODE_1_SEL_0_Pos)   /*!< SEL_0 Get Value */

/* CLB_COUNT_MODE_0 bitfield */
#define CLB_TILE_CLB_COUNT_MODE_0_SEL_2_Pos     (10U)                                                                                             /*!< SEL_2 Position 10 */
#define CLB_TILE_CLB_COUNT_MODE_0_SEL_2_Msk     (0x1fU << CLB_TILE_CLB_COUNT_MODE_0_SEL_2_Pos)                                                    /*!< SEL_2 Mask 0x00007C00 */
#define CLB_TILE_CLB_COUNT_MODE_0_SEL_2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_COUNT_MODE_0_SEL_2_Pos) & CLB_TILE_CLB_COUNT_MODE_0_SEL_2_Msk)   /*!< SEL_2 Set Value */
#define CLB_TILE_CLB_COUNT_MODE_0_SEL_2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_COUNT_MODE_0_SEL_2_Msk) >> CLB_TILE_CLB_COUNT_MODE_0_SEL_2_Pos)   /*!< SEL_2 Get Value */

#define CLB_TILE_CLB_COUNT_MODE_0_SEL_1_Pos     (5U)                                                                                              /*!< SEL_1 Position 5 */
#define CLB_TILE_CLB_COUNT_MODE_0_SEL_1_Msk     (0x1fU << CLB_TILE_CLB_COUNT_MODE_0_SEL_1_Pos)                                                    /*!< SEL_1 Mask 0x000003E0 */
#define CLB_TILE_CLB_COUNT_MODE_0_SEL_1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_COUNT_MODE_0_SEL_1_Pos) & CLB_TILE_CLB_COUNT_MODE_0_SEL_1_Msk)   /*!< SEL_1 Set Value */
#define CLB_TILE_CLB_COUNT_MODE_0_SEL_1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_COUNT_MODE_0_SEL_1_Msk) >> CLB_TILE_CLB_COUNT_MODE_0_SEL_1_Pos)   /*!< SEL_1 Get Value */

#define CLB_TILE_CLB_COUNT_MODE_0_SEL_0_Pos     (0U)                                                                                              /*!< SEL_0 Position 0 */
#define CLB_TILE_CLB_COUNT_MODE_0_SEL_0_Msk     (0x1fU << CLB_TILE_CLB_COUNT_MODE_0_SEL_0_Pos)                                                    /*!< SEL_0 Mask 0x0000001F */
#define CLB_TILE_CLB_COUNT_MODE_0_SEL_0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_COUNT_MODE_0_SEL_0_Pos) & CLB_TILE_CLB_COUNT_MODE_0_SEL_0_Msk)   /*!< SEL_0 Set Value */
#define CLB_TILE_CLB_COUNT_MODE_0_SEL_0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_COUNT_MODE_0_SEL_0_Msk) >> CLB_TILE_CLB_COUNT_MODE_0_SEL_0_Pos)   /*!< SEL_0 Get Value */

/* CLB_COUNT_EVENT bitfield */
#define CLB_TILE_CLB_COUNT_EVENT_SEL_2_Pos     (10U)                                                                                           /*!< SEL_2 Position 10 */
#define CLB_TILE_CLB_COUNT_EVENT_SEL_2_Msk     (0x1fU << CLB_TILE_CLB_COUNT_EVENT_SEL_2_Pos)                                                   /*!< SEL_2 Mask 0x00007C00 */
#define CLB_TILE_CLB_COUNT_EVENT_SEL_2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_COUNT_EVENT_SEL_2_Pos) & CLB_TILE_CLB_COUNT_EVENT_SEL_2_Msk)   /*!< SEL_2 Set Value */
#define CLB_TILE_CLB_COUNT_EVENT_SEL_2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_COUNT_EVENT_SEL_2_Msk) >> CLB_TILE_CLB_COUNT_EVENT_SEL_2_Pos)   /*!< SEL_2 Get Value */

#define CLB_TILE_CLB_COUNT_EVENT_SEL_1_Pos     (5U)                                                                                            /*!< SEL_1 Position 5 */
#define CLB_TILE_CLB_COUNT_EVENT_SEL_1_Msk     (0x1fU << CLB_TILE_CLB_COUNT_EVENT_SEL_1_Pos)                                                   /*!< SEL_1 Mask 0x000003E0 */
#define CLB_TILE_CLB_COUNT_EVENT_SEL_1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_COUNT_EVENT_SEL_1_Pos) & CLB_TILE_CLB_COUNT_EVENT_SEL_1_Msk)   /*!< SEL_1 Set Value */
#define CLB_TILE_CLB_COUNT_EVENT_SEL_1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_COUNT_EVENT_SEL_1_Msk) >> CLB_TILE_CLB_COUNT_EVENT_SEL_1_Pos)   /*!< SEL_1 Get Value */

#define CLB_TILE_CLB_COUNT_EVENT_SEL_0_Pos     (0U)                                                                                            /*!< SEL_0 Position 0 */
#define CLB_TILE_CLB_COUNT_EVENT_SEL_0_Msk     (0x1fU << CLB_TILE_CLB_COUNT_EVENT_SEL_0_Pos)                                                   /*!< SEL_0 Mask 0x0000001F */
#define CLB_TILE_CLB_COUNT_EVENT_SEL_0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_COUNT_EVENT_SEL_0_Pos) & CLB_TILE_CLB_COUNT_EVENT_SEL_0_Msk)   /*!< SEL_0 Set Value */
#define CLB_TILE_CLB_COUNT_EVENT_SEL_0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_COUNT_EVENT_SEL_0_Msk) >> CLB_TILE_CLB_COUNT_EVENT_SEL_0_Pos)   /*!< SEL_0 Get Value */

/* CLB_FSM_EXTRA_IN0 bitfield */
#define CLB_TILE_CLB_FSM_EXTRA_IN0_SEL_2_Pos     (10U)                                                                                               /*!< SEL_2 Position 10 */
#define CLB_TILE_CLB_FSM_EXTRA_IN0_SEL_2_Msk     (0x1fU << CLB_TILE_CLB_FSM_EXTRA_IN0_SEL_2_Pos)                                                     /*!< SEL_2 Mask 0x00007C00 */
#define CLB_TILE_CLB_FSM_EXTRA_IN0_SEL_2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_FSM_EXTRA_IN0_SEL_2_Pos) & CLB_TILE_CLB_FSM_EXTRA_IN0_SEL_2_Msk)   /*!< SEL_2 Set Value */
#define CLB_TILE_CLB_FSM_EXTRA_IN0_SEL_2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_FSM_EXTRA_IN0_SEL_2_Msk) >> CLB_TILE_CLB_FSM_EXTRA_IN0_SEL_2_Pos)   /*!< SEL_2 Get Value */

#define CLB_TILE_CLB_FSM_EXTRA_IN0_SEL_1_Pos     (5U)                                                                                                /*!< SEL_1 Position 5 */
#define CLB_TILE_CLB_FSM_EXTRA_IN0_SEL_1_Msk     (0x1fU << CLB_TILE_CLB_FSM_EXTRA_IN0_SEL_1_Pos)                                                     /*!< SEL_1 Mask 0x000003E0 */
#define CLB_TILE_CLB_FSM_EXTRA_IN0_SEL_1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_FSM_EXTRA_IN0_SEL_1_Pos) & CLB_TILE_CLB_FSM_EXTRA_IN0_SEL_1_Msk)   /*!< SEL_1 Set Value */
#define CLB_TILE_CLB_FSM_EXTRA_IN0_SEL_1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_FSM_EXTRA_IN0_SEL_1_Msk) >> CLB_TILE_CLB_FSM_EXTRA_IN0_SEL_1_Pos)   /*!< SEL_1 Get Value */

#define CLB_TILE_CLB_FSM_EXTRA_IN0_SEL_0_Pos     (0U)                                                                                                /*!< SEL_0 Position 0 */
#define CLB_TILE_CLB_FSM_EXTRA_IN0_SEL_0_Msk     (0x1fU << CLB_TILE_CLB_FSM_EXTRA_IN0_SEL_0_Pos)                                                     /*!< SEL_0 Mask 0x0000001F */
#define CLB_TILE_CLB_FSM_EXTRA_IN0_SEL_0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_FSM_EXTRA_IN0_SEL_0_Pos) & CLB_TILE_CLB_FSM_EXTRA_IN0_SEL_0_Msk)   /*!< SEL_0 Set Value */
#define CLB_TILE_CLB_FSM_EXTRA_IN0_SEL_0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_FSM_EXTRA_IN0_SEL_0_Msk) >> CLB_TILE_CLB_FSM_EXTRA_IN0_SEL_0_Pos)   /*!< SEL_0 Get Value */

/* CLB_FSM_EXTERNAL_IN0 bitfield */
#define CLB_TILE_CLB_FSM_EXTERNAL_IN0_SEL_2_Pos     (10U)                                                                                                     /*!< SEL_2 Position 10 */
#define CLB_TILE_CLB_FSM_EXTERNAL_IN0_SEL_2_Msk     (0x1fU << CLB_TILE_CLB_FSM_EXTERNAL_IN0_SEL_2_Pos)                                                        /*!< SEL_2 Mask 0x00007C00 */
#define CLB_TILE_CLB_FSM_EXTERNAL_IN0_SEL_2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_FSM_EXTERNAL_IN0_SEL_2_Pos) & CLB_TILE_CLB_FSM_EXTERNAL_IN0_SEL_2_Msk)   /*!< SEL_2 Set Value */
#define CLB_TILE_CLB_FSM_EXTERNAL_IN0_SEL_2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_FSM_EXTERNAL_IN0_SEL_2_Msk) >> CLB_TILE_CLB_FSM_EXTERNAL_IN0_SEL_2_Pos)   /*!< SEL_2 Get Value */

#define CLB_TILE_CLB_FSM_EXTERNAL_IN0_SEL_1_Pos     (5U)                                                                                                      /*!< SEL_1 Position 5 */
#define CLB_TILE_CLB_FSM_EXTERNAL_IN0_SEL_1_Msk     (0x1fU << CLB_TILE_CLB_FSM_EXTERNAL_IN0_SEL_1_Pos)                                                        /*!< SEL_1 Mask 0x000003E0 */
#define CLB_TILE_CLB_FSM_EXTERNAL_IN0_SEL_1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_FSM_EXTERNAL_IN0_SEL_1_Pos) & CLB_TILE_CLB_FSM_EXTERNAL_IN0_SEL_1_Msk)   /*!< SEL_1 Set Value */
#define CLB_TILE_CLB_FSM_EXTERNAL_IN0_SEL_1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_FSM_EXTERNAL_IN0_SEL_1_Msk) >> CLB_TILE_CLB_FSM_EXTERNAL_IN0_SEL_1_Pos)   /*!< SEL_1 Get Value */

#define CLB_TILE_CLB_FSM_EXTERNAL_IN0_SEL_0_Pos     (0U)                                                                                                      /*!< SEL_0 Position 0 */
#define CLB_TILE_CLB_FSM_EXTERNAL_IN0_SEL_0_Msk     (0x1fU << CLB_TILE_CLB_FSM_EXTERNAL_IN0_SEL_0_Pos)                                                        /*!< SEL_0 Mask 0x0000001F */
#define CLB_TILE_CLB_FSM_EXTERNAL_IN0_SEL_0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_FSM_EXTERNAL_IN0_SEL_0_Pos) & CLB_TILE_CLB_FSM_EXTERNAL_IN0_SEL_0_Msk)   /*!< SEL_0 Set Value */
#define CLB_TILE_CLB_FSM_EXTERNAL_IN0_SEL_0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_FSM_EXTERNAL_IN0_SEL_0_Msk) >> CLB_TILE_CLB_FSM_EXTERNAL_IN0_SEL_0_Pos)   /*!< SEL_0 Get Value */

/* CLB_FSM_EXTERNAL_IN1 bitfield */
#define CLB_TILE_CLB_FSM_EXTERNAL_IN1_SEL_2_Pos     (10U)                                                                                                     /*!< SEL_2 Position 10 */
#define CLB_TILE_CLB_FSM_EXTERNAL_IN1_SEL_2_Msk     (0x1fU << CLB_TILE_CLB_FSM_EXTERNAL_IN1_SEL_2_Pos)                                                        /*!< SEL_2 Mask 0x00007C00 */
#define CLB_TILE_CLB_FSM_EXTERNAL_IN1_SEL_2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_FSM_EXTERNAL_IN1_SEL_2_Pos) & CLB_TILE_CLB_FSM_EXTERNAL_IN1_SEL_2_Msk)   /*!< SEL_2 Set Value */
#define CLB_TILE_CLB_FSM_EXTERNAL_IN1_SEL_2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_FSM_EXTERNAL_IN1_SEL_2_Msk) >> CLB_TILE_CLB_FSM_EXTERNAL_IN1_SEL_2_Pos)   /*!< SEL_2 Get Value */

#define CLB_TILE_CLB_FSM_EXTERNAL_IN1_SEL_1_Pos     (5U)                                                                                                      /*!< SEL_1 Position 5 */
#define CLB_TILE_CLB_FSM_EXTERNAL_IN1_SEL_1_Msk     (0x1fU << CLB_TILE_CLB_FSM_EXTERNAL_IN1_SEL_1_Pos)                                                        /*!< SEL_1 Mask 0x000003E0 */
#define CLB_TILE_CLB_FSM_EXTERNAL_IN1_SEL_1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_FSM_EXTERNAL_IN1_SEL_1_Pos) & CLB_TILE_CLB_FSM_EXTERNAL_IN1_SEL_1_Msk)   /*!< SEL_1 Set Value */
#define CLB_TILE_CLB_FSM_EXTERNAL_IN1_SEL_1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_FSM_EXTERNAL_IN1_SEL_1_Msk) >> CLB_TILE_CLB_FSM_EXTERNAL_IN1_SEL_1_Pos)   /*!< SEL_1 Get Value */

#define CLB_TILE_CLB_FSM_EXTERNAL_IN1_SEL_0_Pos     (0U)                                                                                                      /*!< SEL_0 Position 0 */
#define CLB_TILE_CLB_FSM_EXTERNAL_IN1_SEL_0_Msk     (0x1fU << CLB_TILE_CLB_FSM_EXTERNAL_IN1_SEL_0_Pos)                                                        /*!< SEL_0 Mask 0x0000001F */
#define CLB_TILE_CLB_FSM_EXTERNAL_IN1_SEL_0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_FSM_EXTERNAL_IN1_SEL_0_Pos) & CLB_TILE_CLB_FSM_EXTERNAL_IN1_SEL_0_Msk)   /*!< SEL_0 Set Value */
#define CLB_TILE_CLB_FSM_EXTERNAL_IN1_SEL_0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_FSM_EXTERNAL_IN1_SEL_0_Msk) >> CLB_TILE_CLB_FSM_EXTERNAL_IN1_SEL_0_Pos)   /*!< SEL_0 Get Value */

/* CLB_FSM_EXTRA_IN1 bitfield */
#define CLB_TILE_CLB_FSM_EXTRA_IN1_SEL_2_Pos     (10U)                                                                                               /*!< SEL_2 Position 10 */
#define CLB_TILE_CLB_FSM_EXTRA_IN1_SEL_2_Msk     (0x1fU << CLB_TILE_CLB_FSM_EXTRA_IN1_SEL_2_Pos)                                                     /*!< SEL_2 Mask 0x00007C00 */
#define CLB_TILE_CLB_FSM_EXTRA_IN1_SEL_2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_FSM_EXTRA_IN1_SEL_2_Pos) & CLB_TILE_CLB_FSM_EXTRA_IN1_SEL_2_Msk)   /*!< SEL_2 Set Value */
#define CLB_TILE_CLB_FSM_EXTRA_IN1_SEL_2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_FSM_EXTRA_IN1_SEL_2_Msk) >> CLB_TILE_CLB_FSM_EXTRA_IN1_SEL_2_Pos)   /*!< SEL_2 Get Value */

#define CLB_TILE_CLB_FSM_EXTRA_IN1_SEL_1_Pos     (5U)                                                                                                /*!< SEL_1 Position 5 */
#define CLB_TILE_CLB_FSM_EXTRA_IN1_SEL_1_Msk     (0x1fU << CLB_TILE_CLB_FSM_EXTRA_IN1_SEL_1_Pos)                                                     /*!< SEL_1 Mask 0x000003E0 */
#define CLB_TILE_CLB_FSM_EXTRA_IN1_SEL_1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_FSM_EXTRA_IN1_SEL_1_Pos) & CLB_TILE_CLB_FSM_EXTRA_IN1_SEL_1_Msk)   /*!< SEL_1 Set Value */
#define CLB_TILE_CLB_FSM_EXTRA_IN1_SEL_1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_FSM_EXTRA_IN1_SEL_1_Msk) >> CLB_TILE_CLB_FSM_EXTRA_IN1_SEL_1_Pos)   /*!< SEL_1 Get Value */

#define CLB_TILE_CLB_FSM_EXTRA_IN1_SEL_0_Pos     (0U)                                                                                                /*!< SEL_0 Position 0 */
#define CLB_TILE_CLB_FSM_EXTRA_IN1_SEL_0_Msk     (0x1fU << CLB_TILE_CLB_FSM_EXTRA_IN1_SEL_0_Pos)                                                     /*!< SEL_0 Mask 0x0000001F */
#define CLB_TILE_CLB_FSM_EXTRA_IN1_SEL_0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_FSM_EXTRA_IN1_SEL_0_Pos) & CLB_TILE_CLB_FSM_EXTRA_IN1_SEL_0_Msk)   /*!< SEL_0 Set Value */
#define CLB_TILE_CLB_FSM_EXTRA_IN1_SEL_0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_FSM_EXTRA_IN1_SEL_0_Msk) >> CLB_TILE_CLB_FSM_EXTRA_IN1_SEL_0_Pos)   /*!< SEL_0 Get Value */

/* CLB_LUT4_IN0 bitfield */
#define CLB_TILE_CLB_LUT4_IN0_SEL_2_Pos     (10U)                                                                                     /*!< SEL_2 Position 10 */
#define CLB_TILE_CLB_LUT4_IN0_SEL_2_Msk     (0x1fU << CLB_TILE_CLB_LUT4_IN0_SEL_2_Pos)                                                /*!< SEL_2 Mask 0x00007C00 */
#define CLB_TILE_CLB_LUT4_IN0_SEL_2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_LUT4_IN0_SEL_2_Pos) & CLB_TILE_CLB_LUT4_IN0_SEL_2_Msk)   /*!< SEL_2 Set Value */
#define CLB_TILE_CLB_LUT4_IN0_SEL_2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_LUT4_IN0_SEL_2_Msk) >> CLB_TILE_CLB_LUT4_IN0_SEL_2_Pos)   /*!< SEL_2 Get Value */

#define CLB_TILE_CLB_LUT4_IN0_SEL_1_Pos     (5U)                                                                                      /*!< SEL_1 Position 5 */
#define CLB_TILE_CLB_LUT4_IN0_SEL_1_Msk     (0x1fU << CLB_TILE_CLB_LUT4_IN0_SEL_1_Pos)                                                /*!< SEL_1 Mask 0x000003E0 */
#define CLB_TILE_CLB_LUT4_IN0_SEL_1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_LUT4_IN0_SEL_1_Pos) & CLB_TILE_CLB_LUT4_IN0_SEL_1_Msk)   /*!< SEL_1 Set Value */
#define CLB_TILE_CLB_LUT4_IN0_SEL_1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_LUT4_IN0_SEL_1_Msk) >> CLB_TILE_CLB_LUT4_IN0_SEL_1_Pos)   /*!< SEL_1 Get Value */

#define CLB_TILE_CLB_LUT4_IN0_SEL_0_Pos     (0U)                                                                                      /*!< SEL_0 Position 0 */
#define CLB_TILE_CLB_LUT4_IN0_SEL_0_Msk     (0x1fU << CLB_TILE_CLB_LUT4_IN0_SEL_0_Pos)                                                /*!< SEL_0 Mask 0x0000001F */
#define CLB_TILE_CLB_LUT4_IN0_SEL_0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_LUT4_IN0_SEL_0_Pos) & CLB_TILE_CLB_LUT4_IN0_SEL_0_Msk)   /*!< SEL_0 Set Value */
#define CLB_TILE_CLB_LUT4_IN0_SEL_0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_LUT4_IN0_SEL_0_Msk) >> CLB_TILE_CLB_LUT4_IN0_SEL_0_Pos)   /*!< SEL_0 Get Value */

/* CLB_LUT4_IN1 bitfield */
#define CLB_TILE_CLB_LUT4_IN1_SEL_2_Pos     (10U)                                                                                     /*!< SEL_2 Position 10 */
#define CLB_TILE_CLB_LUT4_IN1_SEL_2_Msk     (0x1fU << CLB_TILE_CLB_LUT4_IN1_SEL_2_Pos)                                                /*!< SEL_2 Mask 0x00007C00 */
#define CLB_TILE_CLB_LUT4_IN1_SEL_2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_LUT4_IN1_SEL_2_Pos) & CLB_TILE_CLB_LUT4_IN1_SEL_2_Msk)   /*!< SEL_2 Set Value */
#define CLB_TILE_CLB_LUT4_IN1_SEL_2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_LUT4_IN1_SEL_2_Msk) >> CLB_TILE_CLB_LUT4_IN1_SEL_2_Pos)   /*!< SEL_2 Get Value */

#define CLB_TILE_CLB_LUT4_IN1_SEL_1_Pos     (5U)                                                                                      /*!< SEL_1 Position 5 */
#define CLB_TILE_CLB_LUT4_IN1_SEL_1_Msk     (0x1fU << CLB_TILE_CLB_LUT4_IN1_SEL_1_Pos)                                                /*!< SEL_1 Mask 0x000003E0 */
#define CLB_TILE_CLB_LUT4_IN1_SEL_1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_LUT4_IN1_SEL_1_Pos) & CLB_TILE_CLB_LUT4_IN1_SEL_1_Msk)   /*!< SEL_1 Set Value */
#define CLB_TILE_CLB_LUT4_IN1_SEL_1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_LUT4_IN1_SEL_1_Msk) >> CLB_TILE_CLB_LUT4_IN1_SEL_1_Pos)   /*!< SEL_1 Get Value */

#define CLB_TILE_CLB_LUT4_IN1_SEL_0_Pos     (0U)                                                                                      /*!< SEL_0 Position 0 */
#define CLB_TILE_CLB_LUT4_IN1_SEL_0_Msk     (0x1fU << CLB_TILE_CLB_LUT4_IN1_SEL_0_Pos)                                                /*!< SEL_0 Mask 0x0000001F */
#define CLB_TILE_CLB_LUT4_IN1_SEL_0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_LUT4_IN1_SEL_0_Pos) & CLB_TILE_CLB_LUT4_IN1_SEL_0_Msk)   /*!< SEL_0 Set Value */
#define CLB_TILE_CLB_LUT4_IN1_SEL_0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_LUT4_IN1_SEL_0_Msk) >> CLB_TILE_CLB_LUT4_IN1_SEL_0_Pos)   /*!< SEL_0 Get Value */

/* CLB_LUT4_IN2 bitfield */
#define CLB_TILE_CLB_LUT4_IN2_SEL_2_Pos     (10U)                                                                                     /*!< SEL_2 Position 10 */
#define CLB_TILE_CLB_LUT4_IN2_SEL_2_Msk     (0x1fU << CLB_TILE_CLB_LUT4_IN2_SEL_2_Pos)                                                /*!< SEL_2 Mask 0x00007C00 */
#define CLB_TILE_CLB_LUT4_IN2_SEL_2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_LUT4_IN2_SEL_2_Pos) & CLB_TILE_CLB_LUT4_IN2_SEL_2_Msk)   /*!< SEL_2 Set Value */
#define CLB_TILE_CLB_LUT4_IN2_SEL_2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_LUT4_IN2_SEL_2_Msk) >> CLB_TILE_CLB_LUT4_IN2_SEL_2_Pos)   /*!< SEL_2 Get Value */

#define CLB_TILE_CLB_LUT4_IN2_SEL_1_Pos     (5U)                                                                                      /*!< SEL_1 Position 5 */
#define CLB_TILE_CLB_LUT4_IN2_SEL_1_Msk     (0x1fU << CLB_TILE_CLB_LUT4_IN2_SEL_1_Pos)                                                /*!< SEL_1 Mask 0x000003E0 */
#define CLB_TILE_CLB_LUT4_IN2_SEL_1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_LUT4_IN2_SEL_1_Pos) & CLB_TILE_CLB_LUT4_IN2_SEL_1_Msk)   /*!< SEL_1 Set Value */
#define CLB_TILE_CLB_LUT4_IN2_SEL_1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_LUT4_IN2_SEL_1_Msk) >> CLB_TILE_CLB_LUT4_IN2_SEL_1_Pos)   /*!< SEL_1 Get Value */

#define CLB_TILE_CLB_LUT4_IN2_SEL_0_Pos     (0U)                                                                                      /*!< SEL_0 Position 0 */
#define CLB_TILE_CLB_LUT4_IN2_SEL_0_Msk     (0x1fU << CLB_TILE_CLB_LUT4_IN2_SEL_0_Pos)                                                /*!< SEL_0 Mask 0x0000001F */
#define CLB_TILE_CLB_LUT4_IN2_SEL_0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_LUT4_IN2_SEL_0_Pos) & CLB_TILE_CLB_LUT4_IN2_SEL_0_Msk)   /*!< SEL_0 Set Value */
#define CLB_TILE_CLB_LUT4_IN2_SEL_0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_LUT4_IN2_SEL_0_Msk) >> CLB_TILE_CLB_LUT4_IN2_SEL_0_Pos)   /*!< SEL_0 Get Value */

/* CLB_LUT4_IN3 bitfield */
#define CLB_TILE_CLB_LUT4_IN3_SEL_2_Pos     (10U)                                                                                     /*!< SEL_2 Position 10 */
#define CLB_TILE_CLB_LUT4_IN3_SEL_2_Msk     (0x1fU << CLB_TILE_CLB_LUT4_IN3_SEL_2_Pos)                                                /*!< SEL_2 Mask 0x00007C00 */
#define CLB_TILE_CLB_LUT4_IN3_SEL_2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_LUT4_IN3_SEL_2_Pos) & CLB_TILE_CLB_LUT4_IN3_SEL_2_Msk)   /*!< SEL_2 Set Value */
#define CLB_TILE_CLB_LUT4_IN3_SEL_2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_LUT4_IN3_SEL_2_Msk) >> CLB_TILE_CLB_LUT4_IN3_SEL_2_Pos)   /*!< SEL_2 Get Value */

#define CLB_TILE_CLB_LUT4_IN3_SEL_1_Pos     (5U)                                                                                      /*!< SEL_1 Position 5 */
#define CLB_TILE_CLB_LUT4_IN3_SEL_1_Msk     (0x1fU << CLB_TILE_CLB_LUT4_IN3_SEL_1_Pos)                                                /*!< SEL_1 Mask 0x000003E0 */
#define CLB_TILE_CLB_LUT4_IN3_SEL_1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_LUT4_IN3_SEL_1_Pos) & CLB_TILE_CLB_LUT4_IN3_SEL_1_Msk)   /*!< SEL_1 Set Value */
#define CLB_TILE_CLB_LUT4_IN3_SEL_1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_LUT4_IN3_SEL_1_Msk) >> CLB_TILE_CLB_LUT4_IN3_SEL_1_Pos)   /*!< SEL_1 Get Value */

#define CLB_TILE_CLB_LUT4_IN3_SEL_0_Pos     (0U)                                                                                      /*!< SEL_0 Position 0 */
#define CLB_TILE_CLB_LUT4_IN3_SEL_0_Msk     (0x1fU << CLB_TILE_CLB_LUT4_IN3_SEL_0_Pos)                                                /*!< SEL_0 Mask 0x0000001F */
#define CLB_TILE_CLB_LUT4_IN3_SEL_0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_LUT4_IN3_SEL_0_Pos) & CLB_TILE_CLB_LUT4_IN3_SEL_0_Msk)   /*!< SEL_0 Set Value */
#define CLB_TILE_CLB_LUT4_IN3_SEL_0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_LUT4_IN3_SEL_0_Msk) >> CLB_TILE_CLB_LUT4_IN3_SEL_0_Pos)   /*!< SEL_0 Get Value */

/* CLB_FSM_LUT_FN1_0 bitfield */
#define CLB_TILE_CLB_FSM_LUT_FN1_0_FN1_Pos     (16U)                                                                                           /*!< FN1 Position 16 */
#define CLB_TILE_CLB_FSM_LUT_FN1_0_FN1_Msk     (0xffffU << CLB_TILE_CLB_FSM_LUT_FN1_0_FN1_Pos)                                                 /*!< FN1 Mask 0xFFFF0000 */
#define CLB_TILE_CLB_FSM_LUT_FN1_0_FN1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_FSM_LUT_FN1_0_FN1_Pos) & CLB_TILE_CLB_FSM_LUT_FN1_0_FN1_Msk)   /*!< FN1 Set Value */
#define CLB_TILE_CLB_FSM_LUT_FN1_0_FN1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_FSM_LUT_FN1_0_FN1_Msk) >> CLB_TILE_CLB_FSM_LUT_FN1_0_FN1_Pos)   /*!< FN1 Get Value */

#define CLB_TILE_CLB_FSM_LUT_FN1_0_FN0_Pos     (0U)                                                                                            /*!< FN0 Position 0 */
#define CLB_TILE_CLB_FSM_LUT_FN1_0_FN0_Msk     (0xffffU << CLB_TILE_CLB_FSM_LUT_FN1_0_FN0_Pos)                                                 /*!< FN0 Mask 0x0000FFFF */
#define CLB_TILE_CLB_FSM_LUT_FN1_0_FN0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_FSM_LUT_FN1_0_FN0_Pos) & CLB_TILE_CLB_FSM_LUT_FN1_0_FN0_Msk)   /*!< FN0 Set Value */
#define CLB_TILE_CLB_FSM_LUT_FN1_0_FN0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_FSM_LUT_FN1_0_FN0_Msk) >> CLB_TILE_CLB_FSM_LUT_FN1_0_FN0_Pos)   /*!< FN0 Get Value */

/* CLB_FSM_LUT_FN2 bitfield */
#define CLB_TILE_CLB_FSM_LUT_FN2_FN1_Pos     (0U)                                                                                        /*!< FN1 Position 0 */
#define CLB_TILE_CLB_FSM_LUT_FN2_FN1_Msk     (0xffffU << CLB_TILE_CLB_FSM_LUT_FN2_FN1_Pos)                                               /*!< FN1 Mask 0x0000FFFF */
#define CLB_TILE_CLB_FSM_LUT_FN2_FN1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_FSM_LUT_FN2_FN1_Pos) & CLB_TILE_CLB_FSM_LUT_FN2_FN1_Msk)   /*!< FN1 Set Value */
#define CLB_TILE_CLB_FSM_LUT_FN2_FN1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_FSM_LUT_FN2_FN1_Msk) >> CLB_TILE_CLB_FSM_LUT_FN2_FN1_Pos)   /*!< FN1 Get Value */

/* CLB_LUT4_FN1_0 bitfield */
#define CLB_TILE_CLB_LUT4_FN1_0_FN1_Pos     (16U)                                                                                     /*!< FN1 Position 16 */
#define CLB_TILE_CLB_LUT4_FN1_0_FN1_Msk     (0xffffU << CLB_TILE_CLB_LUT4_FN1_0_FN1_Pos)                                              /*!< FN1 Mask 0xFFFF0000 */
#define CLB_TILE_CLB_LUT4_FN1_0_FN1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_LUT4_FN1_0_FN1_Pos) & CLB_TILE_CLB_LUT4_FN1_0_FN1_Msk)   /*!< FN1 Set Value */
#define CLB_TILE_CLB_LUT4_FN1_0_FN1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_LUT4_FN1_0_FN1_Msk) >> CLB_TILE_CLB_LUT4_FN1_0_FN1_Pos)   /*!< FN1 Get Value */

#define CLB_TILE_CLB_LUT4_FN1_0_FN0_Pos     (0U)                                                                                      /*!< FN0 Position 0 */
#define CLB_TILE_CLB_LUT4_FN1_0_FN0_Msk     (0xffffU << CLB_TILE_CLB_LUT4_FN1_0_FN0_Pos)                                              /*!< FN0 Mask 0x0000FFFF */
#define CLB_TILE_CLB_LUT4_FN1_0_FN0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_LUT4_FN1_0_FN0_Pos) & CLB_TILE_CLB_LUT4_FN1_0_FN0_Msk)   /*!< FN0 Set Value */
#define CLB_TILE_CLB_LUT4_FN1_0_FN0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_LUT4_FN1_0_FN0_Msk) >> CLB_TILE_CLB_LUT4_FN1_0_FN0_Pos)   /*!< FN0 Get Value */

/* CLB_LUT4_FN2 bitfield */
#define CLB_TILE_CLB_LUT4_FN2_FN1_Pos     (0U)                                                                                  /*!< FN1 Position 0 */
#define CLB_TILE_CLB_LUT4_FN2_FN1_Msk     (0xffffU << CLB_TILE_CLB_LUT4_FN2_FN1_Pos)                                            /*!< FN1 Mask 0x0000FFFF */
#define CLB_TILE_CLB_LUT4_FN2_FN1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_LUT4_FN2_FN1_Pos) & CLB_TILE_CLB_LUT4_FN2_FN1_Msk)   /*!< FN1 Set Value */
#define CLB_TILE_CLB_LUT4_FN2_FN1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_LUT4_FN2_FN1_Msk) >> CLB_TILE_CLB_LUT4_FN2_FN1_Pos)   /*!< FN1 Get Value */

/* CLB_FSM_NEXT_STATE_0 bitfield */
#define CLB_TILE_CLB_FSM_NEXT_STATE_0_S1_Pos     (16U)                                                                                               /*!< S1 Position 16 */
#define CLB_TILE_CLB_FSM_NEXT_STATE_0_S1_Msk     (0xffffU << CLB_TILE_CLB_FSM_NEXT_STATE_0_S1_Pos)                                                   /*!< S1 Mask 0xFFFF0000 */
#define CLB_TILE_CLB_FSM_NEXT_STATE_0_S1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_FSM_NEXT_STATE_0_S1_Pos) & CLB_TILE_CLB_FSM_NEXT_STATE_0_S1_Msk)   /*!< S1 Set Value */
#define CLB_TILE_CLB_FSM_NEXT_STATE_0_S1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_FSM_NEXT_STATE_0_S1_Msk) >> CLB_TILE_CLB_FSM_NEXT_STATE_0_S1_Pos)   /*!< S1 Get Value */

#define CLB_TILE_CLB_FSM_NEXT_STATE_0_S0_Pos     (0U)                                                                                                /*!< S0 Position 0 */
#define CLB_TILE_CLB_FSM_NEXT_STATE_0_S0_Msk     (0xffffU << CLB_TILE_CLB_FSM_NEXT_STATE_0_S0_Pos)                                                   /*!< S0 Mask 0x0000FFFF */
#define CLB_TILE_CLB_FSM_NEXT_STATE_0_S0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_FSM_NEXT_STATE_0_S0_Pos) & CLB_TILE_CLB_FSM_NEXT_STATE_0_S0_Msk)   /*!< S0 Set Value */
#define CLB_TILE_CLB_FSM_NEXT_STATE_0_S0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_FSM_NEXT_STATE_0_S0_Msk) >> CLB_TILE_CLB_FSM_NEXT_STATE_0_S0_Pos)   /*!< S0 Get Value */

/* CLB_FSM_NEXT_STATE_1 bitfield */
#define CLB_TILE_CLB_FSM_NEXT_STATE_1_S1_Pos     (16U)                                                                                               /*!< S1 Position 16 */
#define CLB_TILE_CLB_FSM_NEXT_STATE_1_S1_Msk     (0xffffU << CLB_TILE_CLB_FSM_NEXT_STATE_1_S1_Pos)                                                   /*!< S1 Mask 0xFFFF0000 */
#define CLB_TILE_CLB_FSM_NEXT_STATE_1_S1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_FSM_NEXT_STATE_1_S1_Pos) & CLB_TILE_CLB_FSM_NEXT_STATE_1_S1_Msk)   /*!< S1 Set Value */
#define CLB_TILE_CLB_FSM_NEXT_STATE_1_S1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_FSM_NEXT_STATE_1_S1_Msk) >> CLB_TILE_CLB_FSM_NEXT_STATE_1_S1_Pos)   /*!< S1 Get Value */

#define CLB_TILE_CLB_FSM_NEXT_STATE_1_S0_Pos     (0U)                                                                                                /*!< S0 Position 0 */
#define CLB_TILE_CLB_FSM_NEXT_STATE_1_S0_Msk     (0xffffU << CLB_TILE_CLB_FSM_NEXT_STATE_1_S0_Pos)                                                   /*!< S0 Mask 0x0000FFFF */
#define CLB_TILE_CLB_FSM_NEXT_STATE_1_S0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_FSM_NEXT_STATE_1_S0_Pos) & CLB_TILE_CLB_FSM_NEXT_STATE_1_S0_Msk)   /*!< S0 Set Value */
#define CLB_TILE_CLB_FSM_NEXT_STATE_1_S0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_FSM_NEXT_STATE_1_S0_Msk) >> CLB_TILE_CLB_FSM_NEXT_STATE_1_S0_Pos)   /*!< S0 Get Value */

/* CLB_FSM_NEXT_STATE_2 bitfield */
#define CLB_TILE_CLB_FSM_NEXT_STATE_2_S1_Pos     (16U)                                                                                               /*!< S1 Position 16 */
#define CLB_TILE_CLB_FSM_NEXT_STATE_2_S1_Msk     (0xffffU << CLB_TILE_CLB_FSM_NEXT_STATE_2_S1_Pos)                                                   /*!< S1 Mask 0xFFFF0000 */
#define CLB_TILE_CLB_FSM_NEXT_STATE_2_S1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_FSM_NEXT_STATE_2_S1_Pos) & CLB_TILE_CLB_FSM_NEXT_STATE_2_S1_Msk)   /*!< S1 Set Value */
#define CLB_TILE_CLB_FSM_NEXT_STATE_2_S1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_FSM_NEXT_STATE_2_S1_Msk) >> CLB_TILE_CLB_FSM_NEXT_STATE_2_S1_Pos)   /*!< S1 Get Value */

#define CLB_TILE_CLB_FSM_NEXT_STATE_2_S0_Pos     (0U)                                                                                                /*!< S0 Position 0 */
#define CLB_TILE_CLB_FSM_NEXT_STATE_2_S0_Msk     (0xffffU << CLB_TILE_CLB_FSM_NEXT_STATE_2_S0_Pos)                                                   /*!< S0 Mask 0x0000FFFF */
#define CLB_TILE_CLB_FSM_NEXT_STATE_2_S0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_FSM_NEXT_STATE_2_S0_Pos) & CLB_TILE_CLB_FSM_NEXT_STATE_2_S0_Msk)   /*!< S0 Set Value */
#define CLB_TILE_CLB_FSM_NEXT_STATE_2_S0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_FSM_NEXT_STATE_2_S0_Msk) >> CLB_TILE_CLB_FSM_NEXT_STATE_2_S0_Pos)   /*!< S0 Get Value */

/* CLB_MISC_CONTROL bitfield */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT2_LFSR_EN_Pos     (26U)                                                                                                               /*!< COUNT2_LFSR_EN Position 26 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT2_LFSR_EN_Msk     (0x1U << CLB_TILE_CLB_MISC_CONTROL_COUNT2_LFSR_EN_Pos)                                                              /*!< COUNT2_LFSR_EN Mask 0x04000000 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT2_LFSR_EN_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_MISC_CONTROL_COUNT2_LFSR_EN_Pos) & CLB_TILE_CLB_MISC_CONTROL_COUNT2_LFSR_EN_Msk)   /*!< COUNT2_LFSR_EN Set Value */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT2_LFSR_EN_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_MISC_CONTROL_COUNT2_LFSR_EN_Msk) >> CLB_TILE_CLB_MISC_CONTROL_COUNT2_LFSR_EN_Pos)   /*!< COUNT2_LFSR_EN Get Value */

#define CLB_TILE_CLB_MISC_CONTROL_COUNT1_LFSR_EN_Pos     (25U)                                                                                                               /*!< COUNT1_LFSR_EN Position 25 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT1_LFSR_EN_Msk     (0x1U << CLB_TILE_CLB_MISC_CONTROL_COUNT1_LFSR_EN_Pos)                                                              /*!< COUNT1_LFSR_EN Mask 0x02000000 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT1_LFSR_EN_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_MISC_CONTROL_COUNT1_LFSR_EN_Pos) & CLB_TILE_CLB_MISC_CONTROL_COUNT1_LFSR_EN_Msk)   /*!< COUNT1_LFSR_EN Set Value */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT1_LFSR_EN_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_MISC_CONTROL_COUNT1_LFSR_EN_Msk) >> CLB_TILE_CLB_MISC_CONTROL_COUNT1_LFSR_EN_Pos)   /*!< COUNT1_LFSR_EN Get Value */

#define CLB_TILE_CLB_MISC_CONTROL_COUNT0_LFSR_EN_Pos     (24U)                                                                                                               /*!< COUNT0_LFSR_EN Position 24 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT0_LFSR_EN_Msk     (0x1U << CLB_TILE_CLB_MISC_CONTROL_COUNT0_LFSR_EN_Pos)                                                              /*!< COUNT0_LFSR_EN Mask 0x01000000 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT0_LFSR_EN_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_MISC_CONTROL_COUNT0_LFSR_EN_Pos) & CLB_TILE_CLB_MISC_CONTROL_COUNT0_LFSR_EN_Msk)   /*!< COUNT0_LFSR_EN Set Value */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT0_LFSR_EN_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_MISC_CONTROL_COUNT0_LFSR_EN_Msk) >> CLB_TILE_CLB_MISC_CONTROL_COUNT0_LFSR_EN_Pos)   /*!< COUNT0_LFSR_EN Get Value */

#define CLB_TILE_CLB_MISC_CONTROL_COUNT2_MATCH2_TAP_EN_Pos     (23U)                                                                                                                           /*!< COUNT2_MATCH2_TAP_EN Position 23 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT2_MATCH2_TAP_EN_Msk     (0x1U << CLB_TILE_CLB_MISC_CONTROL_COUNT2_MATCH2_TAP_EN_Pos)                                                                    /*!< COUNT2_MATCH2_TAP_EN Mask 0x00800000 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT2_MATCH2_TAP_EN_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_MISC_CONTROL_COUNT2_MATCH2_TAP_EN_Pos) & CLB_TILE_CLB_MISC_CONTROL_COUNT2_MATCH2_TAP_EN_Msk)   /*!< COUNT2_MATCH2_TAP_EN Set Value */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT2_MATCH2_TAP_EN_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_MISC_CONTROL_COUNT2_MATCH2_TAP_EN_Msk) >> CLB_TILE_CLB_MISC_CONTROL_COUNT2_MATCH2_TAP_EN_Pos)   /*!< COUNT2_MATCH2_TAP_EN Get Value */

#define CLB_TILE_CLB_MISC_CONTROL_COUNT1_MATCH2_TAP_EN_Pos     (22U)                                                                                                                           /*!< COUNT1_MATCH2_TAP_EN Position 22 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT1_MATCH2_TAP_EN_Msk     (0x1U << CLB_TILE_CLB_MISC_CONTROL_COUNT1_MATCH2_TAP_EN_Pos)                                                                    /*!< COUNT1_MATCH2_TAP_EN Mask 0x00400000 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT1_MATCH2_TAP_EN_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_MISC_CONTROL_COUNT1_MATCH2_TAP_EN_Pos) & CLB_TILE_CLB_MISC_CONTROL_COUNT1_MATCH2_TAP_EN_Msk)   /*!< COUNT1_MATCH2_TAP_EN Set Value */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT1_MATCH2_TAP_EN_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_MISC_CONTROL_COUNT1_MATCH2_TAP_EN_Msk) >> CLB_TILE_CLB_MISC_CONTROL_COUNT1_MATCH2_TAP_EN_Pos)   /*!< COUNT1_MATCH2_TAP_EN Get Value */

#define CLB_TILE_CLB_MISC_CONTROL_COUNT0_MATCH2_TAP_EN_Pos     (21U)                                                                                                                           /*!< COUNT0_MATCH2_TAP_EN Position 21 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT0_MATCH2_TAP_EN_Msk     (0x1U << CLB_TILE_CLB_MISC_CONTROL_COUNT0_MATCH2_TAP_EN_Pos)                                                                    /*!< COUNT0_MATCH2_TAP_EN Mask 0x00200000 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT0_MATCH2_TAP_EN_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_MISC_CONTROL_COUNT0_MATCH2_TAP_EN_Pos) & CLB_TILE_CLB_MISC_CONTROL_COUNT0_MATCH2_TAP_EN_Msk)   /*!< COUNT0_MATCH2_TAP_EN Set Value */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT0_MATCH2_TAP_EN_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_MISC_CONTROL_COUNT0_MATCH2_TAP_EN_Msk) >> CLB_TILE_CLB_MISC_CONTROL_COUNT0_MATCH2_TAP_EN_Pos)   /*!< COUNT0_MATCH2_TAP_EN Get Value */

#define CLB_TILE_CLB_MISC_CONTROL_COUNT2_MATCH1_TAP_EN_Pos     (20U)                                                                                                                           /*!< COUNT2_MATCH1_TAP_EN Position 20 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT2_MATCH1_TAP_EN_Msk     (0x1U << CLB_TILE_CLB_MISC_CONTROL_COUNT2_MATCH1_TAP_EN_Pos)                                                                    /*!< COUNT2_MATCH1_TAP_EN Mask 0x00100000 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT2_MATCH1_TAP_EN_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_MISC_CONTROL_COUNT2_MATCH1_TAP_EN_Pos) & CLB_TILE_CLB_MISC_CONTROL_COUNT2_MATCH1_TAP_EN_Msk)   /*!< COUNT2_MATCH1_TAP_EN Set Value */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT2_MATCH1_TAP_EN_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_MISC_CONTROL_COUNT2_MATCH1_TAP_EN_Msk) >> CLB_TILE_CLB_MISC_CONTROL_COUNT2_MATCH1_TAP_EN_Pos)   /*!< COUNT2_MATCH1_TAP_EN Get Value */

#define CLB_TILE_CLB_MISC_CONTROL_COUNT1_MATCH1_TAP_EN_Pos     (19U)                                                                                                                           /*!< COUNT1_MATCH1_TAP_EN Position 19 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT1_MATCH1_TAP_EN_Msk     (0x1U << CLB_TILE_CLB_MISC_CONTROL_COUNT1_MATCH1_TAP_EN_Pos)                                                                    /*!< COUNT1_MATCH1_TAP_EN Mask 0x00080000 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT1_MATCH1_TAP_EN_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_MISC_CONTROL_COUNT1_MATCH1_TAP_EN_Pos) & CLB_TILE_CLB_MISC_CONTROL_COUNT1_MATCH1_TAP_EN_Msk)   /*!< COUNT1_MATCH1_TAP_EN Set Value */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT1_MATCH1_TAP_EN_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_MISC_CONTROL_COUNT1_MATCH1_TAP_EN_Msk) >> CLB_TILE_CLB_MISC_CONTROL_COUNT1_MATCH1_TAP_EN_Pos)   /*!< COUNT1_MATCH1_TAP_EN Get Value */

#define CLB_TILE_CLB_MISC_CONTROL_COUNT0_MATCH1_TAP_EN_Pos     (18U)                                                                                                                           /*!< COUNT0_MATCH1_TAP_EN Position 18 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT0_MATCH1_TAP_EN_Msk     (0x1U << CLB_TILE_CLB_MISC_CONTROL_COUNT0_MATCH1_TAP_EN_Pos)                                                                    /*!< COUNT0_MATCH1_TAP_EN Mask 0x00040000 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT0_MATCH1_TAP_EN_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_MISC_CONTROL_COUNT0_MATCH1_TAP_EN_Pos) & CLB_TILE_CLB_MISC_CONTROL_COUNT0_MATCH1_TAP_EN_Msk)   /*!< COUNT0_MATCH1_TAP_EN Set Value */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT0_MATCH1_TAP_EN_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_MISC_CONTROL_COUNT0_MATCH1_TAP_EN_Msk) >> CLB_TILE_CLB_MISC_CONTROL_COUNT0_MATCH1_TAP_EN_Pos)   /*!< COUNT0_MATCH1_TAP_EN Get Value */

#define CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL1_2_Pos     (17U)                                                                                                                   /*!< FSM_EXTRA_SEL1_2 Position 17 */
#define CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL1_2_Msk     (0x1U << CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL1_2_Pos)                                                                /*!< FSM_EXTRA_SEL1_2 Mask 0x00020000 */
#define CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL1_2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL1_2_Pos) & CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL1_2_Msk)   /*!< FSM_EXTRA_SEL1_2 Set Value */
#define CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL1_2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL1_2_Msk) >> CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL1_2_Pos)   /*!< FSM_EXTRA_SEL1_2 Get Value */

#define CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL0_2_Pos     (16U)                                                                                                                   /*!< FSM_EXTRA_SEL0_2 Position 16 */
#define CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL0_2_Msk     (0x1U << CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL0_2_Pos)                                                                /*!< FSM_EXTRA_SEL0_2 Mask 0x00010000 */
#define CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL0_2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL0_2_Pos) & CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL0_2_Msk)   /*!< FSM_EXTRA_SEL0_2 Set Value */
#define CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL0_2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL0_2_Msk) >> CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL0_2_Pos)   /*!< FSM_EXTRA_SEL0_2 Get Value */

#define CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL1_1_Pos     (15U)                                                                                                                   /*!< FSM_EXTRA_SEL1_1 Position 15 */
#define CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL1_1_Msk     (0x1U << CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL1_1_Pos)                                                                /*!< FSM_EXTRA_SEL1_1 Mask 0x00008000 */
#define CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL1_1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL1_1_Pos) & CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL1_1_Msk)   /*!< FSM_EXTRA_SEL1_1 Set Value */
#define CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL1_1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL1_1_Msk) >> CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL1_1_Pos)   /*!< FSM_EXTRA_SEL1_1 Get Value */

#define CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL0_1_Pos     (14U)                                                                                                                   /*!< FSM_EXTRA_SEL0_1 Position 14 */
#define CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL0_1_Msk     (0x1U << CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL0_1_Pos)                                                                /*!< FSM_EXTRA_SEL0_1 Mask 0x00004000 */
#define CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL0_1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL0_1_Pos) & CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL0_1_Msk)   /*!< FSM_EXTRA_SEL0_1 Set Value */
#define CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL0_1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL0_1_Msk) >> CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL0_1_Pos)   /*!< FSM_EXTRA_SEL0_1 Get Value */

#define CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL1_0_Pos     (13U)                                                                                                                   /*!< FSM_EXTRA_SEL1_0 Position 13 */
#define CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL1_0_Msk     (0x1U << CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL1_0_Pos)                                                                /*!< FSM_EXTRA_SEL1_0 Mask 0x00002000 */
#define CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL1_0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL1_0_Pos) & CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL1_0_Msk)   /*!< FSM_EXTRA_SEL1_0 Set Value */
#define CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL1_0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL1_0_Msk) >> CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL1_0_Pos)   /*!< FSM_EXTRA_SEL1_0 Get Value */

#define CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL0_0_Pos     (12U)                                                                                                                   /*!< FSM_EXTRA_SEL0_0 Position 12 */
#define CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL0_0_Msk     (0x1U << CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL0_0_Pos)                                                                /*!< FSM_EXTRA_SEL0_0 Mask 0x00001000 */
#define CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL0_0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL0_0_Pos) & CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL0_0_Msk)   /*!< FSM_EXTRA_SEL0_0 Set Value */
#define CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL0_0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL0_0_Msk) >> CLB_TILE_CLB_MISC_CONTROL_FSM_EXTRA_SEL0_0_Pos)   /*!< FSM_EXTRA_SEL0_0 Get Value */

#define CLB_TILE_CLB_MISC_CONTROL_COUNT_SERIALIZER_2_Pos     (11U)                                                                                                                       /*!< COUNT_SERIALIZER_2 Position 11 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT_SERIALIZER_2_Msk     (0x1U << CLB_TILE_CLB_MISC_CONTROL_COUNT_SERIALIZER_2_Pos)                                                                  /*!< COUNT_SERIALIZER_2 Mask 0x00000800 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT_SERIALIZER_2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_MISC_CONTROL_COUNT_SERIALIZER_2_Pos) & CLB_TILE_CLB_MISC_CONTROL_COUNT_SERIALIZER_2_Msk)   /*!< COUNT_SERIALIZER_2 Set Value */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT_SERIALIZER_2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_MISC_CONTROL_COUNT_SERIALIZER_2_Msk) >> CLB_TILE_CLB_MISC_CONTROL_COUNT_SERIALIZER_2_Pos)   /*!< COUNT_SERIALIZER_2 Get Value */

#define CLB_TILE_CLB_MISC_CONTROL_COUNT_SERIALIZER_1_Pos     (10U)                                                                                                                       /*!< COUNT_SERIALIZER_1 Position 10 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT_SERIALIZER_1_Msk     (0x1U << CLB_TILE_CLB_MISC_CONTROL_COUNT_SERIALIZER_1_Pos)                                                                  /*!< COUNT_SERIALIZER_1 Mask 0x00000400 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT_SERIALIZER_1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_MISC_CONTROL_COUNT_SERIALIZER_1_Pos) & CLB_TILE_CLB_MISC_CONTROL_COUNT_SERIALIZER_1_Msk)   /*!< COUNT_SERIALIZER_1 Set Value */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT_SERIALIZER_1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_MISC_CONTROL_COUNT_SERIALIZER_1_Msk) >> CLB_TILE_CLB_MISC_CONTROL_COUNT_SERIALIZER_1_Pos)   /*!< COUNT_SERIALIZER_1 Get Value */

#define CLB_TILE_CLB_MISC_CONTROL_COUNT_SERIALIZER_0_Pos     (9U)                                                                                                                        /*!< COUNT_SERIALIZER_0 Position 9 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT_SERIALIZER_0_Msk     (0x1U << CLB_TILE_CLB_MISC_CONTROL_COUNT_SERIALIZER_0_Pos)                                                                  /*!< COUNT_SERIALIZER_0 Mask 0x00000200 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT_SERIALIZER_0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_MISC_CONTROL_COUNT_SERIALIZER_0_Pos) & CLB_TILE_CLB_MISC_CONTROL_COUNT_SERIALIZER_0_Msk)   /*!< COUNT_SERIALIZER_0 Set Value */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT_SERIALIZER_0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_MISC_CONTROL_COUNT_SERIALIZER_0_Msk) >> CLB_TILE_CLB_MISC_CONTROL_COUNT_SERIALIZER_0_Pos)   /*!< COUNT_SERIALIZER_0 Get Value */

#define CLB_TILE_CLB_MISC_CONTROL_COUNT_EVENT_CTRL_2_Pos     (8U)                                                                                                                        /*!< COUNT_EVENT_CTRL_2 Position 8 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT_EVENT_CTRL_2_Msk     (0x1U << CLB_TILE_CLB_MISC_CONTROL_COUNT_EVENT_CTRL_2_Pos)                                                                  /*!< COUNT_EVENT_CTRL_2 Mask 0x00000100 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT_EVENT_CTRL_2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_MISC_CONTROL_COUNT_EVENT_CTRL_2_Pos) & CLB_TILE_CLB_MISC_CONTROL_COUNT_EVENT_CTRL_2_Msk)   /*!< COUNT_EVENT_CTRL_2 Set Value */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT_EVENT_CTRL_2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_MISC_CONTROL_COUNT_EVENT_CTRL_2_Msk) >> CLB_TILE_CLB_MISC_CONTROL_COUNT_EVENT_CTRL_2_Pos)   /*!< COUNT_EVENT_CTRL_2 Get Value */

#define CLB_TILE_CLB_MISC_CONTROL_COUNT_DIR_2_Pos     (7U)                                                                                                          /*!< COUNT_DIR_2 Position 7 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT_DIR_2_Msk     (0x1U << CLB_TILE_CLB_MISC_CONTROL_COUNT_DIR_2_Pos)                                                           /*!< COUNT_DIR_2 Mask 0x00000080 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT_DIR_2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_MISC_CONTROL_COUNT_DIR_2_Pos) & CLB_TILE_CLB_MISC_CONTROL_COUNT_DIR_2_Msk)   /*!< COUNT_DIR_2 Set Value */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT_DIR_2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_MISC_CONTROL_COUNT_DIR_2_Msk) >> CLB_TILE_CLB_MISC_CONTROL_COUNT_DIR_2_Pos)   /*!< COUNT_DIR_2 Get Value */

#define CLB_TILE_CLB_MISC_CONTROL_COUNT_ADD_SHIFT_2_Pos     (6U)                                                                                                                      /*!< COUNT_ADD_SHIFT_2 Position 6 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT_ADD_SHIFT_2_Msk     (0x1U << CLB_TILE_CLB_MISC_CONTROL_COUNT_ADD_SHIFT_2_Pos)                                                                 /*!< COUNT_ADD_SHIFT_2 Mask 0x00000040 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT_ADD_SHIFT_2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_MISC_CONTROL_COUNT_ADD_SHIFT_2_Pos) & CLB_TILE_CLB_MISC_CONTROL_COUNT_ADD_SHIFT_2_Msk)   /*!< COUNT_ADD_SHIFT_2 Set Value */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT_ADD_SHIFT_2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_MISC_CONTROL_COUNT_ADD_SHIFT_2_Msk) >> CLB_TILE_CLB_MISC_CONTROL_COUNT_ADD_SHIFT_2_Pos)   /*!< COUNT_ADD_SHIFT_2 Get Value */

#define CLB_TILE_CLB_MISC_CONTROL_COUNT_EVENT_CTRL_1_Pos     (5U)                                                                                                                        /*!< COUNT_EVENT_CTRL_1 Position 5 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT_EVENT_CTRL_1_Msk     (0x1U << CLB_TILE_CLB_MISC_CONTROL_COUNT_EVENT_CTRL_1_Pos)                                                                  /*!< COUNT_EVENT_CTRL_1 Mask 0x00000020 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT_EVENT_CTRL_1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_MISC_CONTROL_COUNT_EVENT_CTRL_1_Pos) & CLB_TILE_CLB_MISC_CONTROL_COUNT_EVENT_CTRL_1_Msk)   /*!< COUNT_EVENT_CTRL_1 Set Value */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT_EVENT_CTRL_1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_MISC_CONTROL_COUNT_EVENT_CTRL_1_Msk) >> CLB_TILE_CLB_MISC_CONTROL_COUNT_EVENT_CTRL_1_Pos)   /*!< COUNT_EVENT_CTRL_1 Get Value */

#define CLB_TILE_CLB_MISC_CONTROL_COUNT_DIR_1_Pos     (4U)                                                                                                          /*!< COUNT_DIR_1 Position 4 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT_DIR_1_Msk     (0x1U << CLB_TILE_CLB_MISC_CONTROL_COUNT_DIR_1_Pos)                                                           /*!< COUNT_DIR_1 Mask 0x00000010 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT_DIR_1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_MISC_CONTROL_COUNT_DIR_1_Pos) & CLB_TILE_CLB_MISC_CONTROL_COUNT_DIR_1_Msk)   /*!< COUNT_DIR_1 Set Value */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT_DIR_1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_MISC_CONTROL_COUNT_DIR_1_Msk) >> CLB_TILE_CLB_MISC_CONTROL_COUNT_DIR_1_Pos)   /*!< COUNT_DIR_1 Get Value */

#define CLB_TILE_CLB_MISC_CONTROL_COUNT_ADD_SHIFT_1_Pos     (3U)                                                                                                                      /*!< COUNT_ADD_SHIFT_1 Position 3 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT_ADD_SHIFT_1_Msk     (0x1U << CLB_TILE_CLB_MISC_CONTROL_COUNT_ADD_SHIFT_1_Pos)                                                                 /*!< COUNT_ADD_SHIFT_1 Mask 0x00000008 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT_ADD_SHIFT_1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_MISC_CONTROL_COUNT_ADD_SHIFT_1_Pos) & CLB_TILE_CLB_MISC_CONTROL_COUNT_ADD_SHIFT_1_Msk)   /*!< COUNT_ADD_SHIFT_1 Set Value */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT_ADD_SHIFT_1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_MISC_CONTROL_COUNT_ADD_SHIFT_1_Msk) >> CLB_TILE_CLB_MISC_CONTROL_COUNT_ADD_SHIFT_1_Pos)   /*!< COUNT_ADD_SHIFT_1 Get Value */

#define CLB_TILE_CLB_MISC_CONTROL_COUNT_EVENT_CTRL_0_Pos     (2U)                                                                                                                        /*!< COUNT_EVENT_CTRL_0 Position 2 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT_EVENT_CTRL_0_Msk     (0x1U << CLB_TILE_CLB_MISC_CONTROL_COUNT_EVENT_CTRL_0_Pos)                                                                  /*!< COUNT_EVENT_CTRL_0 Mask 0x00000004 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT_EVENT_CTRL_0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_MISC_CONTROL_COUNT_EVENT_CTRL_0_Pos) & CLB_TILE_CLB_MISC_CONTROL_COUNT_EVENT_CTRL_0_Msk)   /*!< COUNT_EVENT_CTRL_0 Set Value */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT_EVENT_CTRL_0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_MISC_CONTROL_COUNT_EVENT_CTRL_0_Msk) >> CLB_TILE_CLB_MISC_CONTROL_COUNT_EVENT_CTRL_0_Pos)   /*!< COUNT_EVENT_CTRL_0 Get Value */

#define CLB_TILE_CLB_MISC_CONTROL_COUNT_DIR_0_Pos     (1U)                                                                                                          /*!< COUNT_DIR_0 Position 1 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT_DIR_0_Msk     (0x1U << CLB_TILE_CLB_MISC_CONTROL_COUNT_DIR_0_Pos)                                                           /*!< COUNT_DIR_0 Mask 0x00000002 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT_DIR_0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_MISC_CONTROL_COUNT_DIR_0_Pos) & CLB_TILE_CLB_MISC_CONTROL_COUNT_DIR_0_Msk)   /*!< COUNT_DIR_0 Set Value */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT_DIR_0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_MISC_CONTROL_COUNT_DIR_0_Msk) >> CLB_TILE_CLB_MISC_CONTROL_COUNT_DIR_0_Pos)   /*!< COUNT_DIR_0 Get Value */

#define CLB_TILE_CLB_MISC_CONTROL_COUNT_ADD_SHIFT_0_Pos     (0U)                                                                                                                      /*!< COUNT_ADD_SHIFT_0 Position 0 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT_ADD_SHIFT_0_Msk     (0x1U << CLB_TILE_CLB_MISC_CONTROL_COUNT_ADD_SHIFT_0_Pos)                                                                 /*!< COUNT_ADD_SHIFT_0 Mask 0x00000001 */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT_ADD_SHIFT_0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_MISC_CONTROL_COUNT_ADD_SHIFT_0_Pos) & CLB_TILE_CLB_MISC_CONTROL_COUNT_ADD_SHIFT_0_Msk)   /*!< COUNT_ADD_SHIFT_0 Set Value */
#define CLB_TILE_CLB_MISC_CONTROL_COUNT_ADD_SHIFT_0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_MISC_CONTROL_COUNT_ADD_SHIFT_0_Msk) >> CLB_TILE_CLB_MISC_CONTROL_COUNT_ADD_SHIFT_0_Pos)   /*!< COUNT_ADD_SHIFT_0 Get Value */

/* CLB_OUTPUT_LUT_0 bitfield */
#define CLB_TILE_CLB_OUTPUT_LUT_0_FN_Pos     (15U)                                                                                       /*!< FN Position 15 */
#define CLB_TILE_CLB_OUTPUT_LUT_0_FN_Msk     (0xffU << CLB_TILE_CLB_OUTPUT_LUT_0_FN_Pos)                                                 /*!< FN Mask 0x007F8000 */
#define CLB_TILE_CLB_OUTPUT_LUT_0_FN_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_LUT_0_FN_Pos) & CLB_TILE_CLB_OUTPUT_LUT_0_FN_Msk)   /*!< FN Set Value */
#define CLB_TILE_CLB_OUTPUT_LUT_0_FN_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_LUT_0_FN_Msk) >> CLB_TILE_CLB_OUTPUT_LUT_0_FN_Pos)   /*!< FN Get Value */

#define CLB_TILE_CLB_OUTPUT_LUT_0_IN2_Pos     (10U)                                                                                         /*!< IN2 Position 10 */
#define CLB_TILE_CLB_OUTPUT_LUT_0_IN2_Msk     (0x1fU << CLB_TILE_CLB_OUTPUT_LUT_0_IN2_Pos)                                                  /*!< IN2 Mask 0x00007C00 */
#define CLB_TILE_CLB_OUTPUT_LUT_0_IN2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_LUT_0_IN2_Pos) & CLB_TILE_CLB_OUTPUT_LUT_0_IN2_Msk)   /*!< IN2 Set Value */
#define CLB_TILE_CLB_OUTPUT_LUT_0_IN2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_LUT_0_IN2_Msk) >> CLB_TILE_CLB_OUTPUT_LUT_0_IN2_Pos)   /*!< IN2 Get Value */

#define CLB_TILE_CLB_OUTPUT_LUT_0_IN1_Pos     (5U)                                                                                          /*!< IN1 Position 5 */
#define CLB_TILE_CLB_OUTPUT_LUT_0_IN1_Msk     (0x1fU << CLB_TILE_CLB_OUTPUT_LUT_0_IN1_Pos)                                                  /*!< IN1 Mask 0x000003E0 */
#define CLB_TILE_CLB_OUTPUT_LUT_0_IN1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_LUT_0_IN1_Pos) & CLB_TILE_CLB_OUTPUT_LUT_0_IN1_Msk)   /*!< IN1 Set Value */
#define CLB_TILE_CLB_OUTPUT_LUT_0_IN1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_LUT_0_IN1_Msk) >> CLB_TILE_CLB_OUTPUT_LUT_0_IN1_Pos)   /*!< IN1 Get Value */

#define CLB_TILE_CLB_OUTPUT_LUT_0_IN0_Pos     (0U)                                                                                          /*!< IN0 Position 0 */
#define CLB_TILE_CLB_OUTPUT_LUT_0_IN0_Msk     (0x1fU << CLB_TILE_CLB_OUTPUT_LUT_0_IN0_Pos)                                                  /*!< IN0 Mask 0x0000001F */
#define CLB_TILE_CLB_OUTPUT_LUT_0_IN0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_LUT_0_IN0_Pos) & CLB_TILE_CLB_OUTPUT_LUT_0_IN0_Msk)   /*!< IN0 Set Value */
#define CLB_TILE_CLB_OUTPUT_LUT_0_IN0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_LUT_0_IN0_Msk) >> CLB_TILE_CLB_OUTPUT_LUT_0_IN0_Pos)   /*!< IN0 Get Value */

/* CLB_OUTPUT_LUT_1 bitfield */
#define CLB_TILE_CLB_OUTPUT_LUT_1_FN_Pos     (15U)                                                                                       /*!< FN Position 15 */
#define CLB_TILE_CLB_OUTPUT_LUT_1_FN_Msk     (0xffU << CLB_TILE_CLB_OUTPUT_LUT_1_FN_Pos)                                                 /*!< FN Mask 0x007F8000 */
#define CLB_TILE_CLB_OUTPUT_LUT_1_FN_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_LUT_1_FN_Pos) & CLB_TILE_CLB_OUTPUT_LUT_1_FN_Msk)   /*!< FN Set Value */
#define CLB_TILE_CLB_OUTPUT_LUT_1_FN_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_LUT_1_FN_Msk) >> CLB_TILE_CLB_OUTPUT_LUT_1_FN_Pos)   /*!< FN Get Value */

#define CLB_TILE_CLB_OUTPUT_LUT_1_IN2_Pos     (10U)                                                                                         /*!< IN2 Position 10 */
#define CLB_TILE_CLB_OUTPUT_LUT_1_IN2_Msk     (0x1fU << CLB_TILE_CLB_OUTPUT_LUT_1_IN2_Pos)                                                  /*!< IN2 Mask 0x00007C00 */
#define CLB_TILE_CLB_OUTPUT_LUT_1_IN2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_LUT_1_IN2_Pos) & CLB_TILE_CLB_OUTPUT_LUT_1_IN2_Msk)   /*!< IN2 Set Value */
#define CLB_TILE_CLB_OUTPUT_LUT_1_IN2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_LUT_1_IN2_Msk) >> CLB_TILE_CLB_OUTPUT_LUT_1_IN2_Pos)   /*!< IN2 Get Value */

#define CLB_TILE_CLB_OUTPUT_LUT_1_IN1_Pos     (5U)                                                                                          /*!< IN1 Position 5 */
#define CLB_TILE_CLB_OUTPUT_LUT_1_IN1_Msk     (0x1fU << CLB_TILE_CLB_OUTPUT_LUT_1_IN1_Pos)                                                  /*!< IN1 Mask 0x000003E0 */
#define CLB_TILE_CLB_OUTPUT_LUT_1_IN1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_LUT_1_IN1_Pos) & CLB_TILE_CLB_OUTPUT_LUT_1_IN1_Msk)   /*!< IN1 Set Value */
#define CLB_TILE_CLB_OUTPUT_LUT_1_IN1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_LUT_1_IN1_Msk) >> CLB_TILE_CLB_OUTPUT_LUT_1_IN1_Pos)   /*!< IN1 Get Value */

#define CLB_TILE_CLB_OUTPUT_LUT_1_IN0_Pos     (0U)                                                                                          /*!< IN0 Position 0 */
#define CLB_TILE_CLB_OUTPUT_LUT_1_IN0_Msk     (0x1fU << CLB_TILE_CLB_OUTPUT_LUT_1_IN0_Pos)                                                  /*!< IN0 Mask 0x0000001F */
#define CLB_TILE_CLB_OUTPUT_LUT_1_IN0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_LUT_1_IN0_Pos) & CLB_TILE_CLB_OUTPUT_LUT_1_IN0_Msk)   /*!< IN0 Set Value */
#define CLB_TILE_CLB_OUTPUT_LUT_1_IN0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_LUT_1_IN0_Msk) >> CLB_TILE_CLB_OUTPUT_LUT_1_IN0_Pos)   /*!< IN0 Get Value */

/* CLB_OUTPUT_LUT_2 bitfield */
#define CLB_TILE_CLB_OUTPUT_LUT_2_FN_Pos     (15U)                                                                                       /*!< FN Position 15 */
#define CLB_TILE_CLB_OUTPUT_LUT_2_FN_Msk     (0xffU << CLB_TILE_CLB_OUTPUT_LUT_2_FN_Pos)                                                 /*!< FN Mask 0x007F8000 */
#define CLB_TILE_CLB_OUTPUT_LUT_2_FN_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_LUT_2_FN_Pos) & CLB_TILE_CLB_OUTPUT_LUT_2_FN_Msk)   /*!< FN Set Value */
#define CLB_TILE_CLB_OUTPUT_LUT_2_FN_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_LUT_2_FN_Msk) >> CLB_TILE_CLB_OUTPUT_LUT_2_FN_Pos)   /*!< FN Get Value */

#define CLB_TILE_CLB_OUTPUT_LUT_2_IN2_Pos     (10U)                                                                                         /*!< IN2 Position 10 */
#define CLB_TILE_CLB_OUTPUT_LUT_2_IN2_Msk     (0x1fU << CLB_TILE_CLB_OUTPUT_LUT_2_IN2_Pos)                                                  /*!< IN2 Mask 0x00007C00 */
#define CLB_TILE_CLB_OUTPUT_LUT_2_IN2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_LUT_2_IN2_Pos) & CLB_TILE_CLB_OUTPUT_LUT_2_IN2_Msk)   /*!< IN2 Set Value */
#define CLB_TILE_CLB_OUTPUT_LUT_2_IN2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_LUT_2_IN2_Msk) >> CLB_TILE_CLB_OUTPUT_LUT_2_IN2_Pos)   /*!< IN2 Get Value */

#define CLB_TILE_CLB_OUTPUT_LUT_2_IN1_Pos     (5U)                                                                                          /*!< IN1 Position 5 */
#define CLB_TILE_CLB_OUTPUT_LUT_2_IN1_Msk     (0x1fU << CLB_TILE_CLB_OUTPUT_LUT_2_IN1_Pos)                                                  /*!< IN1 Mask 0x000003E0 */
#define CLB_TILE_CLB_OUTPUT_LUT_2_IN1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_LUT_2_IN1_Pos) & CLB_TILE_CLB_OUTPUT_LUT_2_IN1_Msk)   /*!< IN1 Set Value */
#define CLB_TILE_CLB_OUTPUT_LUT_2_IN1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_LUT_2_IN1_Msk) >> CLB_TILE_CLB_OUTPUT_LUT_2_IN1_Pos)   /*!< IN1 Get Value */

#define CLB_TILE_CLB_OUTPUT_LUT_2_IN0_Pos     (0U)                                                                                          /*!< IN0 Position 0 */
#define CLB_TILE_CLB_OUTPUT_LUT_2_IN0_Msk     (0x1fU << CLB_TILE_CLB_OUTPUT_LUT_2_IN0_Pos)                                                  /*!< IN0 Mask 0x0000001F */
#define CLB_TILE_CLB_OUTPUT_LUT_2_IN0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_LUT_2_IN0_Pos) & CLB_TILE_CLB_OUTPUT_LUT_2_IN0_Msk)   /*!< IN0 Set Value */
#define CLB_TILE_CLB_OUTPUT_LUT_2_IN0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_LUT_2_IN0_Msk) >> CLB_TILE_CLB_OUTPUT_LUT_2_IN0_Pos)   /*!< IN0 Get Value */

/* CLB_OUTPUT_LUT_3 bitfield */
#define CLB_TILE_CLB_OUTPUT_LUT_3_FN_Pos     (15U)                                                                                       /*!< FN Position 15 */
#define CLB_TILE_CLB_OUTPUT_LUT_3_FN_Msk     (0xffU << CLB_TILE_CLB_OUTPUT_LUT_3_FN_Pos)                                                 /*!< FN Mask 0x007F8000 */
#define CLB_TILE_CLB_OUTPUT_LUT_3_FN_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_LUT_3_FN_Pos) & CLB_TILE_CLB_OUTPUT_LUT_3_FN_Msk)   /*!< FN Set Value */
#define CLB_TILE_CLB_OUTPUT_LUT_3_FN_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_LUT_3_FN_Msk) >> CLB_TILE_CLB_OUTPUT_LUT_3_FN_Pos)   /*!< FN Get Value */

#define CLB_TILE_CLB_OUTPUT_LUT_3_IN2_Pos     (10U)                                                                                         /*!< IN2 Position 10 */
#define CLB_TILE_CLB_OUTPUT_LUT_3_IN2_Msk     (0x1fU << CLB_TILE_CLB_OUTPUT_LUT_3_IN2_Pos)                                                  /*!< IN2 Mask 0x00007C00 */
#define CLB_TILE_CLB_OUTPUT_LUT_3_IN2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_LUT_3_IN2_Pos) & CLB_TILE_CLB_OUTPUT_LUT_3_IN2_Msk)   /*!< IN2 Set Value */
#define CLB_TILE_CLB_OUTPUT_LUT_3_IN2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_LUT_3_IN2_Msk) >> CLB_TILE_CLB_OUTPUT_LUT_3_IN2_Pos)   /*!< IN2 Get Value */

#define CLB_TILE_CLB_OUTPUT_LUT_3_IN1_Pos     (5U)                                                                                          /*!< IN1 Position 5 */
#define CLB_TILE_CLB_OUTPUT_LUT_3_IN1_Msk     (0x1fU << CLB_TILE_CLB_OUTPUT_LUT_3_IN1_Pos)                                                  /*!< IN1 Mask 0x000003E0 */
#define CLB_TILE_CLB_OUTPUT_LUT_3_IN1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_LUT_3_IN1_Pos) & CLB_TILE_CLB_OUTPUT_LUT_3_IN1_Msk)   /*!< IN1 Set Value */
#define CLB_TILE_CLB_OUTPUT_LUT_3_IN1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_LUT_3_IN1_Msk) >> CLB_TILE_CLB_OUTPUT_LUT_3_IN1_Pos)   /*!< IN1 Get Value */

#define CLB_TILE_CLB_OUTPUT_LUT_3_IN0_Pos     (0U)                                                                                          /*!< IN0 Position 0 */
#define CLB_TILE_CLB_OUTPUT_LUT_3_IN0_Msk     (0x1fU << CLB_TILE_CLB_OUTPUT_LUT_3_IN0_Pos)                                                  /*!< IN0 Mask 0x0000001F */
#define CLB_TILE_CLB_OUTPUT_LUT_3_IN0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_LUT_3_IN0_Pos) & CLB_TILE_CLB_OUTPUT_LUT_3_IN0_Msk)   /*!< IN0 Set Value */
#define CLB_TILE_CLB_OUTPUT_LUT_3_IN0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_LUT_3_IN0_Msk) >> CLB_TILE_CLB_OUTPUT_LUT_3_IN0_Pos)   /*!< IN0 Get Value */

/* CLB_OUTPUT_LUT_4 bitfield */
#define CLB_TILE_CLB_OUTPUT_LUT_4_FN_Pos     (15U)                                                                                       /*!< FN Position 15 */
#define CLB_TILE_CLB_OUTPUT_LUT_4_FN_Msk     (0xffU << CLB_TILE_CLB_OUTPUT_LUT_4_FN_Pos)                                                 /*!< FN Mask 0x007F8000 */
#define CLB_TILE_CLB_OUTPUT_LUT_4_FN_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_LUT_4_FN_Pos) & CLB_TILE_CLB_OUTPUT_LUT_4_FN_Msk)   /*!< FN Set Value */
#define CLB_TILE_CLB_OUTPUT_LUT_4_FN_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_LUT_4_FN_Msk) >> CLB_TILE_CLB_OUTPUT_LUT_4_FN_Pos)   /*!< FN Get Value */

#define CLB_TILE_CLB_OUTPUT_LUT_4_IN2_Pos     (10U)                                                                                         /*!< IN2 Position 10 */
#define CLB_TILE_CLB_OUTPUT_LUT_4_IN2_Msk     (0x1fU << CLB_TILE_CLB_OUTPUT_LUT_4_IN2_Pos)                                                  /*!< IN2 Mask 0x00007C00 */
#define CLB_TILE_CLB_OUTPUT_LUT_4_IN2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_LUT_4_IN2_Pos) & CLB_TILE_CLB_OUTPUT_LUT_4_IN2_Msk)   /*!< IN2 Set Value */
#define CLB_TILE_CLB_OUTPUT_LUT_4_IN2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_LUT_4_IN2_Msk) >> CLB_TILE_CLB_OUTPUT_LUT_4_IN2_Pos)   /*!< IN2 Get Value */

#define CLB_TILE_CLB_OUTPUT_LUT_4_IN1_Pos     (5U)                                                                                          /*!< IN1 Position 5 */
#define CLB_TILE_CLB_OUTPUT_LUT_4_IN1_Msk     (0x1fU << CLB_TILE_CLB_OUTPUT_LUT_4_IN1_Pos)                                                  /*!< IN1 Mask 0x000003E0 */
#define CLB_TILE_CLB_OUTPUT_LUT_4_IN1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_LUT_4_IN1_Pos) & CLB_TILE_CLB_OUTPUT_LUT_4_IN1_Msk)   /*!< IN1 Set Value */
#define CLB_TILE_CLB_OUTPUT_LUT_4_IN1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_LUT_4_IN1_Msk) >> CLB_TILE_CLB_OUTPUT_LUT_4_IN1_Pos)   /*!< IN1 Get Value */

#define CLB_TILE_CLB_OUTPUT_LUT_4_IN0_Pos     (0U)                                                                                          /*!< IN0 Position 0 */
#define CLB_TILE_CLB_OUTPUT_LUT_4_IN0_Msk     (0x1fU << CLB_TILE_CLB_OUTPUT_LUT_4_IN0_Pos)                                                  /*!< IN0 Mask 0x0000001F */
#define CLB_TILE_CLB_OUTPUT_LUT_4_IN0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_LUT_4_IN0_Pos) & CLB_TILE_CLB_OUTPUT_LUT_4_IN0_Msk)   /*!< IN0 Set Value */
#define CLB_TILE_CLB_OUTPUT_LUT_4_IN0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_LUT_4_IN0_Msk) >> CLB_TILE_CLB_OUTPUT_LUT_4_IN0_Pos)   /*!< IN0 Get Value */

/* CLB_OUTPUT_LUT_5 bitfield */
#define CLB_TILE_CLB_OUTPUT_LUT_5_FN_Pos     (15U)                                                                                       /*!< FN Position 15 */
#define CLB_TILE_CLB_OUTPUT_LUT_5_FN_Msk     (0xffU << CLB_TILE_CLB_OUTPUT_LUT_5_FN_Pos)                                                 /*!< FN Mask 0x007F8000 */
#define CLB_TILE_CLB_OUTPUT_LUT_5_FN_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_LUT_5_FN_Pos) & CLB_TILE_CLB_OUTPUT_LUT_5_FN_Msk)   /*!< FN Set Value */
#define CLB_TILE_CLB_OUTPUT_LUT_5_FN_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_LUT_5_FN_Msk) >> CLB_TILE_CLB_OUTPUT_LUT_5_FN_Pos)   /*!< FN Get Value */

#define CLB_TILE_CLB_OUTPUT_LUT_5_IN2_Pos     (10U)                                                                                         /*!< IN2 Position 10 */
#define CLB_TILE_CLB_OUTPUT_LUT_5_IN2_Msk     (0x1fU << CLB_TILE_CLB_OUTPUT_LUT_5_IN2_Pos)                                                  /*!< IN2 Mask 0x00007C00 */
#define CLB_TILE_CLB_OUTPUT_LUT_5_IN2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_LUT_5_IN2_Pos) & CLB_TILE_CLB_OUTPUT_LUT_5_IN2_Msk)   /*!< IN2 Set Value */
#define CLB_TILE_CLB_OUTPUT_LUT_5_IN2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_LUT_5_IN2_Msk) >> CLB_TILE_CLB_OUTPUT_LUT_5_IN2_Pos)   /*!< IN2 Get Value */

#define CLB_TILE_CLB_OUTPUT_LUT_5_IN1_Pos     (5U)                                                                                          /*!< IN1 Position 5 */
#define CLB_TILE_CLB_OUTPUT_LUT_5_IN1_Msk     (0x1fU << CLB_TILE_CLB_OUTPUT_LUT_5_IN1_Pos)                                                  /*!< IN1 Mask 0x000003E0 */
#define CLB_TILE_CLB_OUTPUT_LUT_5_IN1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_LUT_5_IN1_Pos) & CLB_TILE_CLB_OUTPUT_LUT_5_IN1_Msk)   /*!< IN1 Set Value */
#define CLB_TILE_CLB_OUTPUT_LUT_5_IN1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_LUT_5_IN1_Msk) >> CLB_TILE_CLB_OUTPUT_LUT_5_IN1_Pos)   /*!< IN1 Get Value */

#define CLB_TILE_CLB_OUTPUT_LUT_5_IN0_Pos     (0U)                                                                                          /*!< IN0 Position 0 */
#define CLB_TILE_CLB_OUTPUT_LUT_5_IN0_Msk     (0x1fU << CLB_TILE_CLB_OUTPUT_LUT_5_IN0_Pos)                                                  /*!< IN0 Mask 0x0000001F */
#define CLB_TILE_CLB_OUTPUT_LUT_5_IN0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_LUT_5_IN0_Pos) & CLB_TILE_CLB_OUTPUT_LUT_5_IN0_Msk)   /*!< IN0 Set Value */
#define CLB_TILE_CLB_OUTPUT_LUT_5_IN0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_LUT_5_IN0_Msk) >> CLB_TILE_CLB_OUTPUT_LUT_5_IN0_Pos)   /*!< IN0 Get Value */

/* CLB_OUTPUT_LUT_6 bitfield */
#define CLB_TILE_CLB_OUTPUT_LUT_6_FN_Pos     (15U)                                                                                       /*!< FN Position 15 */
#define CLB_TILE_CLB_OUTPUT_LUT_6_FN_Msk     (0xffU << CLB_TILE_CLB_OUTPUT_LUT_6_FN_Pos)                                                 /*!< FN Mask 0x007F8000 */
#define CLB_TILE_CLB_OUTPUT_LUT_6_FN_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_LUT_6_FN_Pos) & CLB_TILE_CLB_OUTPUT_LUT_6_FN_Msk)   /*!< FN Set Value */
#define CLB_TILE_CLB_OUTPUT_LUT_6_FN_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_LUT_6_FN_Msk) >> CLB_TILE_CLB_OUTPUT_LUT_6_FN_Pos)   /*!< FN Get Value */

#define CLB_TILE_CLB_OUTPUT_LUT_6_IN2_Pos     (10U)                                                                                         /*!< IN2 Position 10 */
#define CLB_TILE_CLB_OUTPUT_LUT_6_IN2_Msk     (0x1fU << CLB_TILE_CLB_OUTPUT_LUT_6_IN2_Pos)                                                  /*!< IN2 Mask 0x00007C00 */
#define CLB_TILE_CLB_OUTPUT_LUT_6_IN2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_LUT_6_IN2_Pos) & CLB_TILE_CLB_OUTPUT_LUT_6_IN2_Msk)   /*!< IN2 Set Value */
#define CLB_TILE_CLB_OUTPUT_LUT_6_IN2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_LUT_6_IN2_Msk) >> CLB_TILE_CLB_OUTPUT_LUT_6_IN2_Pos)   /*!< IN2 Get Value */

#define CLB_TILE_CLB_OUTPUT_LUT_6_IN1_Pos     (5U)                                                                                          /*!< IN1 Position 5 */
#define CLB_TILE_CLB_OUTPUT_LUT_6_IN1_Msk     (0x1fU << CLB_TILE_CLB_OUTPUT_LUT_6_IN1_Pos)                                                  /*!< IN1 Mask 0x000003E0 */
#define CLB_TILE_CLB_OUTPUT_LUT_6_IN1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_LUT_6_IN1_Pos) & CLB_TILE_CLB_OUTPUT_LUT_6_IN1_Msk)   /*!< IN1 Set Value */
#define CLB_TILE_CLB_OUTPUT_LUT_6_IN1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_LUT_6_IN1_Msk) >> CLB_TILE_CLB_OUTPUT_LUT_6_IN1_Pos)   /*!< IN1 Get Value */

#define CLB_TILE_CLB_OUTPUT_LUT_6_IN0_Pos     (0U)                                                                                          /*!< IN0 Position 0 */
#define CLB_TILE_CLB_OUTPUT_LUT_6_IN0_Msk     (0x1fU << CLB_TILE_CLB_OUTPUT_LUT_6_IN0_Pos)                                                  /*!< IN0 Mask 0x0000001F */
#define CLB_TILE_CLB_OUTPUT_LUT_6_IN0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_LUT_6_IN0_Pos) & CLB_TILE_CLB_OUTPUT_LUT_6_IN0_Msk)   /*!< IN0 Set Value */
#define CLB_TILE_CLB_OUTPUT_LUT_6_IN0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_LUT_6_IN0_Msk) >> CLB_TILE_CLB_OUTPUT_LUT_6_IN0_Pos)   /*!< IN0 Get Value */

/* CLB_OUTPUT_LUT_7 bitfield */
#define CLB_TILE_CLB_OUTPUT_LUT_7_FN_Pos     (15U)                                                                                       /*!< FN Position 15 */
#define CLB_TILE_CLB_OUTPUT_LUT_7_FN_Msk     (0xffU << CLB_TILE_CLB_OUTPUT_LUT_7_FN_Pos)                                                 /*!< FN Mask 0x007F8000 */
#define CLB_TILE_CLB_OUTPUT_LUT_7_FN_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_LUT_7_FN_Pos) & CLB_TILE_CLB_OUTPUT_LUT_7_FN_Msk)   /*!< FN Set Value */
#define CLB_TILE_CLB_OUTPUT_LUT_7_FN_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_LUT_7_FN_Msk) >> CLB_TILE_CLB_OUTPUT_LUT_7_FN_Pos)   /*!< FN Get Value */

#define CLB_TILE_CLB_OUTPUT_LUT_7_IN2_Pos     (10U)                                                                                         /*!< IN2 Position 10 */
#define CLB_TILE_CLB_OUTPUT_LUT_7_IN2_Msk     (0x1fU << CLB_TILE_CLB_OUTPUT_LUT_7_IN2_Pos)                                                  /*!< IN2 Mask 0x00007C00 */
#define CLB_TILE_CLB_OUTPUT_LUT_7_IN2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_LUT_7_IN2_Pos) & CLB_TILE_CLB_OUTPUT_LUT_7_IN2_Msk)   /*!< IN2 Set Value */
#define CLB_TILE_CLB_OUTPUT_LUT_7_IN2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_LUT_7_IN2_Msk) >> CLB_TILE_CLB_OUTPUT_LUT_7_IN2_Pos)   /*!< IN2 Get Value */

#define CLB_TILE_CLB_OUTPUT_LUT_7_IN1_Pos     (5U)                                                                                          /*!< IN1 Position 5 */
#define CLB_TILE_CLB_OUTPUT_LUT_7_IN1_Msk     (0x1fU << CLB_TILE_CLB_OUTPUT_LUT_7_IN1_Pos)                                                  /*!< IN1 Mask 0x000003E0 */
#define CLB_TILE_CLB_OUTPUT_LUT_7_IN1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_LUT_7_IN1_Pos) & CLB_TILE_CLB_OUTPUT_LUT_7_IN1_Msk)   /*!< IN1 Set Value */
#define CLB_TILE_CLB_OUTPUT_LUT_7_IN1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_LUT_7_IN1_Msk) >> CLB_TILE_CLB_OUTPUT_LUT_7_IN1_Pos)   /*!< IN1 Get Value */

#define CLB_TILE_CLB_OUTPUT_LUT_7_IN0_Pos     (0U)                                                                                          /*!< IN0 Position 0 */
#define CLB_TILE_CLB_OUTPUT_LUT_7_IN0_Msk     (0x1fU << CLB_TILE_CLB_OUTPUT_LUT_7_IN0_Pos)                                                  /*!< IN0 Mask 0x0000001F */
#define CLB_TILE_CLB_OUTPUT_LUT_7_IN0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_LUT_7_IN0_Pos) & CLB_TILE_CLB_OUTPUT_LUT_7_IN0_Msk)   /*!< IN0 Set Value */
#define CLB_TILE_CLB_OUTPUT_LUT_7_IN0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_LUT_7_IN0_Msk) >> CLB_TILE_CLB_OUTPUT_LUT_7_IN0_Pos)   /*!< IN0 Get Value */

/* CLB_HLC_EVENT_SEL bitfield */
#define CLB_TILE_CLB_HLC_EVENT_SEL_EVENT3_SEL_Pos     (15U)                                                                                                         /*!< EVENT3_SEL Position 15 */
#define CLB_TILE_CLB_HLC_EVENT_SEL_EVENT3_SEL_Msk     (0x1fU << CLB_TILE_CLB_HLC_EVENT_SEL_EVENT3_SEL_Pos)                                                          /*!< EVENT3_SEL Mask 0x000F8000 */
#define CLB_TILE_CLB_HLC_EVENT_SEL_EVENT3_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_HLC_EVENT_SEL_EVENT3_SEL_Pos) & CLB_TILE_CLB_HLC_EVENT_SEL_EVENT3_SEL_Msk)   /*!< EVENT3_SEL Set Value */
#define CLB_TILE_CLB_HLC_EVENT_SEL_EVENT3_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_HLC_EVENT_SEL_EVENT3_SEL_Msk) >> CLB_TILE_CLB_HLC_EVENT_SEL_EVENT3_SEL_Pos)   /*!< EVENT3_SEL Get Value */

#define CLB_TILE_CLB_HLC_EVENT_SEL_EVENT2_SEL_Pos     (10U)                                                                                                         /*!< EVENT2_SEL Position 10 */
#define CLB_TILE_CLB_HLC_EVENT_SEL_EVENT2_SEL_Msk     (0x1fU << CLB_TILE_CLB_HLC_EVENT_SEL_EVENT2_SEL_Pos)                                                          /*!< EVENT2_SEL Mask 0x00007C00 */
#define CLB_TILE_CLB_HLC_EVENT_SEL_EVENT2_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_HLC_EVENT_SEL_EVENT2_SEL_Pos) & CLB_TILE_CLB_HLC_EVENT_SEL_EVENT2_SEL_Msk)   /*!< EVENT2_SEL Set Value */
#define CLB_TILE_CLB_HLC_EVENT_SEL_EVENT2_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_HLC_EVENT_SEL_EVENT2_SEL_Msk) >> CLB_TILE_CLB_HLC_EVENT_SEL_EVENT2_SEL_Pos)   /*!< EVENT2_SEL Get Value */

#define CLB_TILE_CLB_HLC_EVENT_SEL_EVENT1_SEL_Pos     (5U)                                                                                                          /*!< EVENT1_SEL Position 5 */
#define CLB_TILE_CLB_HLC_EVENT_SEL_EVENT1_SEL_Msk     (0x1fU << CLB_TILE_CLB_HLC_EVENT_SEL_EVENT1_SEL_Pos)                                                          /*!< EVENT1_SEL Mask 0x000003E0 */
#define CLB_TILE_CLB_HLC_EVENT_SEL_EVENT1_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_HLC_EVENT_SEL_EVENT1_SEL_Pos) & CLB_TILE_CLB_HLC_EVENT_SEL_EVENT1_SEL_Msk)   /*!< EVENT1_SEL Set Value */
#define CLB_TILE_CLB_HLC_EVENT_SEL_EVENT1_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_HLC_EVENT_SEL_EVENT1_SEL_Msk) >> CLB_TILE_CLB_HLC_EVENT_SEL_EVENT1_SEL_Pos)   /*!< EVENT1_SEL Get Value */

#define CLB_TILE_CLB_HLC_EVENT_SEL_EVENT0_SEL_Pos     (0U)                                                                                                          /*!< EVENT0_SEL Position 0 */
#define CLB_TILE_CLB_HLC_EVENT_SEL_EVENT0_SEL_Msk     (0x1fU << CLB_TILE_CLB_HLC_EVENT_SEL_EVENT0_SEL_Pos)                                                          /*!< EVENT0_SEL Mask 0x0000001F */
#define CLB_TILE_CLB_HLC_EVENT_SEL_EVENT0_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_HLC_EVENT_SEL_EVENT0_SEL_Pos) & CLB_TILE_CLB_HLC_EVENT_SEL_EVENT0_SEL_Msk)   /*!< EVENT0_SEL Set Value */
#define CLB_TILE_CLB_HLC_EVENT_SEL_EVENT0_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_HLC_EVENT_SEL_EVENT0_SEL_Msk) >> CLB_TILE_CLB_HLC_EVENT_SEL_EVENT0_SEL_Pos)   /*!< EVENT0_SEL Get Value */

/* CLB_COUNT_MATCH_TAP_SEL bitfield */
#define CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT2_MATCH2_Pos     (26U)                                                                                                                           /*!< COUNT2_MATCH2 Position 26 */
#define CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT2_MATCH2_Msk     (0x1fU << CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT2_MATCH2_Pos)                                                                   /*!< COUNT2_MATCH2 Mask 0x7C000000 */
#define CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT2_MATCH2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT2_MATCH2_Pos) & CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT2_MATCH2_Msk)   /*!< COUNT2_MATCH2 Set Value */
#define CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT2_MATCH2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT2_MATCH2_Msk) >> CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT2_MATCH2_Pos)   /*!< COUNT2_MATCH2 Get Value */

#define CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT1_MATCH2_Pos     (21U)                                                                                                                           /*!< COUNT1_MATCH2 Position 21 */
#define CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT1_MATCH2_Msk     (0x1fU << CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT1_MATCH2_Pos)                                                                   /*!< COUNT1_MATCH2 Mask 0x03E00000 */
#define CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT1_MATCH2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT1_MATCH2_Pos) & CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT1_MATCH2_Msk)   /*!< COUNT1_MATCH2 Set Value */
#define CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT1_MATCH2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT1_MATCH2_Msk) >> CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT1_MATCH2_Pos)   /*!< COUNT1_MATCH2 Get Value */

#define CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT0_MATCH2_Pos     (16U)                                                                                                                           /*!< COUNT0_MATCH2 Position 16 */
#define CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT0_MATCH2_Msk     (0x1fU << CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT0_MATCH2_Pos)                                                                   /*!< COUNT0_MATCH2 Mask 0x001F0000 */
#define CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT0_MATCH2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT0_MATCH2_Pos) & CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT0_MATCH2_Msk)   /*!< COUNT0_MATCH2 Set Value */
#define CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT0_MATCH2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT0_MATCH2_Msk) >> CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT0_MATCH2_Pos)   /*!< COUNT0_MATCH2 Get Value */

#define CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT2_MATCH1_Pos     (10U)                                                                                                                           /*!< COUNT2_MATCH1 Position 10 */
#define CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT2_MATCH1_Msk     (0x1fU << CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT2_MATCH1_Pos)                                                                   /*!< COUNT2_MATCH1 Mask 0x00007C00 */
#define CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT2_MATCH1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT2_MATCH1_Pos) & CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT2_MATCH1_Msk)   /*!< COUNT2_MATCH1 Set Value */
#define CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT2_MATCH1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT2_MATCH1_Msk) >> CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT2_MATCH1_Pos)   /*!< COUNT2_MATCH1 Get Value */

#define CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT1_MATCH1_Pos     (5U)                                                                                                                            /*!< COUNT1_MATCH1 Position 5 */
#define CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT1_MATCH1_Msk     (0x1fU << CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT1_MATCH1_Pos)                                                                   /*!< COUNT1_MATCH1 Mask 0x000003E0 */
#define CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT1_MATCH1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT1_MATCH1_Pos) & CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT1_MATCH1_Msk)   /*!< COUNT1_MATCH1 Set Value */
#define CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT1_MATCH1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT1_MATCH1_Msk) >> CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT1_MATCH1_Pos)   /*!< COUNT1_MATCH1 Get Value */

#define CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT0_MATCH1_Pos     (0U)                                                                                                                            /*!< COUNT0_MATCH1 Position 0 */
#define CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT0_MATCH1_Msk     (0x1fU << CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT0_MATCH1_Pos)                                                                   /*!< COUNT0_MATCH1 Mask 0x0000001F */
#define CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT0_MATCH1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT0_MATCH1_Pos) & CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT0_MATCH1_Msk)   /*!< COUNT0_MATCH1 Set Value */
#define CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT0_MATCH1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT0_MATCH1_Msk) >> CLB_TILE_CLB_COUNT_MATCH_TAP_SEL_COUNT0_MATCH1_Pos)   /*!< COUNT0_MATCH1 Get Value */

/* CLB_OUTPUT_COND_CTRL_0 bitfield */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_0_ASYNC_COND_EN_Pos     (14U)                                                                                                                         /*!< ASYNC_COND_EN Position 14 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_0_ASYNC_COND_EN_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_0_ASYNC_COND_EN_Pos)                                                                   /*!< ASYNC_COND_EN Mask 0x00004000 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_0_ASYNC_COND_EN_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_0_ASYNC_COND_EN_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_0_ASYNC_COND_EN_Msk)   /*!< ASYNC_COND_EN Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_0_ASYNC_COND_EN_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_0_ASYNC_COND_EN_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_0_ASYNC_COND_EN_Pos)   /*!< ASYNC_COND_EN Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_0_SEL_RAW_IN_Pos     (13U)                                                                                                                   /*!< SEL_RAW_IN Position 13 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_0_SEL_RAW_IN_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_0_SEL_RAW_IN_Pos)                                                                /*!< SEL_RAW_IN Mask 0x00002000 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_0_SEL_RAW_IN_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_0_SEL_RAW_IN_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_0_SEL_RAW_IN_Msk)   /*!< SEL_RAW_IN Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_0_SEL_RAW_IN_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_0_SEL_RAW_IN_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_0_SEL_RAW_IN_Pos)   /*!< SEL_RAW_IN Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_0_HW_RLS_CTRL_SEL_Pos     (12U)                                                                                                                             /*!< HW_RLS_CTRL_SEL Position 12 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_0_HW_RLS_CTRL_SEL_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_0_HW_RLS_CTRL_SEL_Pos)                                                                     /*!< HW_RLS_CTRL_SEL Mask 0x00001000 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_0_HW_RLS_CTRL_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_0_HW_RLS_CTRL_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_0_HW_RLS_CTRL_SEL_Msk)   /*!< HW_RLS_CTRL_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_0_HW_RLS_CTRL_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_0_HW_RLS_CTRL_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_0_HW_RLS_CTRL_SEL_Pos)   /*!< HW_RLS_CTRL_SEL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_0_HW_GATING_CTRL_SEL_Pos     (11U)                                                                                                                                   /*!< HW_GATING_CTRL_SEL Position 11 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_0_HW_GATING_CTRL_SEL_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_0_HW_GATING_CTRL_SEL_Pos)                                                                        /*!< HW_GATING_CTRL_SEL Mask 0x00000800 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_0_HW_GATING_CTRL_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_0_HW_GATING_CTRL_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_0_HW_GATING_CTRL_SEL_Msk)   /*!< HW_GATING_CTRL_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_0_HW_GATING_CTRL_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_0_HW_GATING_CTRL_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_0_HW_GATING_CTRL_SEL_Pos)   /*!< HW_GATING_CTRL_SEL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_0_SEL_RELEASE_CTRL_Pos     (8U)                                                                                                                                /*!< SEL_RELEASE_CTRL Position 8 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_0_SEL_RELEASE_CTRL_Msk     (0x7U << CLB_TILE_CLB_OUTPUT_COND_CTRL_0_SEL_RELEASE_CTRL_Pos)                                                                      /*!< SEL_RELEASE_CTRL Mask 0x00000700 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_0_SEL_RELEASE_CTRL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_0_SEL_RELEASE_CTRL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_0_SEL_RELEASE_CTRL_Msk)   /*!< SEL_RELEASE_CTRL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_0_SEL_RELEASE_CTRL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_0_SEL_RELEASE_CTRL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_0_SEL_RELEASE_CTRL_Pos)   /*!< SEL_RELEASE_CTRL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_0_SEL_GATING_CTRL_Pos     (5U)                                                                                                                              /*!< SEL_GATING_CTRL Position 5 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_0_SEL_GATING_CTRL_Msk     (0x7U << CLB_TILE_CLB_OUTPUT_COND_CTRL_0_SEL_GATING_CTRL_Pos)                                                                     /*!< SEL_GATING_CTRL Mask 0x000000E0 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_0_SEL_GATING_CTRL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_0_SEL_GATING_CTRL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_0_SEL_GATING_CTRL_Msk)   /*!< SEL_GATING_CTRL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_0_SEL_GATING_CTRL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_0_SEL_GATING_CTRL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_0_SEL_GATING_CTRL_Pos)   /*!< SEL_GATING_CTRL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_0_LEVEL_3_SEL_Pos     (3U)                                                                                                                      /*!< LEVEL_3_SEL Position 3 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_0_LEVEL_3_SEL_Msk     (0x3U << CLB_TILE_CLB_OUTPUT_COND_CTRL_0_LEVEL_3_SEL_Pos)                                                                 /*!< LEVEL_3_SEL Mask 0x00000018 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_0_LEVEL_3_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_0_LEVEL_3_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_0_LEVEL_3_SEL_Msk)   /*!< LEVEL_3_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_0_LEVEL_3_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_0_LEVEL_3_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_0_LEVEL_3_SEL_Pos)   /*!< LEVEL_3_SEL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_0_LEVEL_2_SEL_Pos     (1U)                                                                                                                      /*!< LEVEL_2_SEL Position 1 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_0_LEVEL_2_SEL_Msk     (0x3U << CLB_TILE_CLB_OUTPUT_COND_CTRL_0_LEVEL_2_SEL_Pos)                                                                 /*!< LEVEL_2_SEL Mask 0x00000006 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_0_LEVEL_2_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_0_LEVEL_2_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_0_LEVEL_2_SEL_Msk)   /*!< LEVEL_2_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_0_LEVEL_2_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_0_LEVEL_2_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_0_LEVEL_2_SEL_Pos)   /*!< LEVEL_2_SEL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_0_LEVEL_1_SEL_Pos     (0U)                                                                                                                      /*!< LEVEL_1_SEL Position 0 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_0_LEVEL_1_SEL_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_0_LEVEL_1_SEL_Pos)                                                                 /*!< LEVEL_1_SEL Mask 0x00000001 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_0_LEVEL_1_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_0_LEVEL_1_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_0_LEVEL_1_SEL_Msk)   /*!< LEVEL_1_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_0_LEVEL_1_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_0_LEVEL_1_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_0_LEVEL_1_SEL_Pos)   /*!< LEVEL_1_SEL Get Value */

/* CLB_OUTPUT_COND_CTRL_1 bitfield */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_1_ASYNC_COND_EN_Pos     (14U)                                                                                                                         /*!< ASYNC_COND_EN Position 14 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_1_ASYNC_COND_EN_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_1_ASYNC_COND_EN_Pos)                                                                   /*!< ASYNC_COND_EN Mask 0x00004000 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_1_ASYNC_COND_EN_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_1_ASYNC_COND_EN_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_1_ASYNC_COND_EN_Msk)   /*!< ASYNC_COND_EN Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_1_ASYNC_COND_EN_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_1_ASYNC_COND_EN_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_1_ASYNC_COND_EN_Pos)   /*!< ASYNC_COND_EN Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_1_SEL_RAW_IN_Pos     (13U)                                                                                                                   /*!< SEL_RAW_IN Position 13 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_1_SEL_RAW_IN_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_1_SEL_RAW_IN_Pos)                                                                /*!< SEL_RAW_IN Mask 0x00002000 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_1_SEL_RAW_IN_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_1_SEL_RAW_IN_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_1_SEL_RAW_IN_Msk)   /*!< SEL_RAW_IN Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_1_SEL_RAW_IN_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_1_SEL_RAW_IN_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_1_SEL_RAW_IN_Pos)   /*!< SEL_RAW_IN Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_1_HW_RLS_CTRL_SEL_Pos     (12U)                                                                                                                             /*!< HW_RLS_CTRL_SEL Position 12 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_1_HW_RLS_CTRL_SEL_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_1_HW_RLS_CTRL_SEL_Pos)                                                                     /*!< HW_RLS_CTRL_SEL Mask 0x00001000 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_1_HW_RLS_CTRL_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_1_HW_RLS_CTRL_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_1_HW_RLS_CTRL_SEL_Msk)   /*!< HW_RLS_CTRL_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_1_HW_RLS_CTRL_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_1_HW_RLS_CTRL_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_1_HW_RLS_CTRL_SEL_Pos)   /*!< HW_RLS_CTRL_SEL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_1_HW_GATING_CTRL_SEL_Pos     (11U)                                                                                                                                   /*!< HW_GATING_CTRL_SEL Position 11 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_1_HW_GATING_CTRL_SEL_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_1_HW_GATING_CTRL_SEL_Pos)                                                                        /*!< HW_GATING_CTRL_SEL Mask 0x00000800 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_1_HW_GATING_CTRL_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_1_HW_GATING_CTRL_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_1_HW_GATING_CTRL_SEL_Msk)   /*!< HW_GATING_CTRL_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_1_HW_GATING_CTRL_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_1_HW_GATING_CTRL_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_1_HW_GATING_CTRL_SEL_Pos)   /*!< HW_GATING_CTRL_SEL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_1_SEL_RELEASE_CTRL_Pos     (8U)                                                                                                                                /*!< SEL_RELEASE_CTRL Position 8 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_1_SEL_RELEASE_CTRL_Msk     (0x7U << CLB_TILE_CLB_OUTPUT_COND_CTRL_1_SEL_RELEASE_CTRL_Pos)                                                                      /*!< SEL_RELEASE_CTRL Mask 0x00000700 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_1_SEL_RELEASE_CTRL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_1_SEL_RELEASE_CTRL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_1_SEL_RELEASE_CTRL_Msk)   /*!< SEL_RELEASE_CTRL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_1_SEL_RELEASE_CTRL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_1_SEL_RELEASE_CTRL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_1_SEL_RELEASE_CTRL_Pos)   /*!< SEL_RELEASE_CTRL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_1_SEL_GATING_CTRL_Pos     (5U)                                                                                                                              /*!< SEL_GATING_CTRL Position 5 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_1_SEL_GATING_CTRL_Msk     (0x7U << CLB_TILE_CLB_OUTPUT_COND_CTRL_1_SEL_GATING_CTRL_Pos)                                                                     /*!< SEL_GATING_CTRL Mask 0x000000E0 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_1_SEL_GATING_CTRL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_1_SEL_GATING_CTRL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_1_SEL_GATING_CTRL_Msk)   /*!< SEL_GATING_CTRL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_1_SEL_GATING_CTRL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_1_SEL_GATING_CTRL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_1_SEL_GATING_CTRL_Pos)   /*!< SEL_GATING_CTRL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_1_LEVEL_3_SEL_Pos     (3U)                                                                                                                      /*!< LEVEL_3_SEL Position 3 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_1_LEVEL_3_SEL_Msk     (0x3U << CLB_TILE_CLB_OUTPUT_COND_CTRL_1_LEVEL_3_SEL_Pos)                                                                 /*!< LEVEL_3_SEL Mask 0x00000018 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_1_LEVEL_3_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_1_LEVEL_3_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_1_LEVEL_3_SEL_Msk)   /*!< LEVEL_3_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_1_LEVEL_3_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_1_LEVEL_3_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_1_LEVEL_3_SEL_Pos)   /*!< LEVEL_3_SEL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_1_LEVEL_2_SEL_Pos     (1U)                                                                                                                      /*!< LEVEL_2_SEL Position 1 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_1_LEVEL_2_SEL_Msk     (0x3U << CLB_TILE_CLB_OUTPUT_COND_CTRL_1_LEVEL_2_SEL_Pos)                                                                 /*!< LEVEL_2_SEL Mask 0x00000006 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_1_LEVEL_2_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_1_LEVEL_2_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_1_LEVEL_2_SEL_Msk)   /*!< LEVEL_2_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_1_LEVEL_2_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_1_LEVEL_2_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_1_LEVEL_2_SEL_Pos)   /*!< LEVEL_2_SEL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_1_LEVEL_1_SEL_Pos     (0U)                                                                                                                      /*!< LEVEL_1_SEL Position 0 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_1_LEVEL_1_SEL_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_1_LEVEL_1_SEL_Pos)                                                                 /*!< LEVEL_1_SEL Mask 0x00000001 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_1_LEVEL_1_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_1_LEVEL_1_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_1_LEVEL_1_SEL_Msk)   /*!< LEVEL_1_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_1_LEVEL_1_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_1_LEVEL_1_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_1_LEVEL_1_SEL_Pos)   /*!< LEVEL_1_SEL Get Value */

/* CLB_OUTPUT_COND_CTRL_2 bitfield */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_2_ASYNC_COND_EN_Pos     (14U)                                                                                                                         /*!< ASYNC_COND_EN Position 14 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_2_ASYNC_COND_EN_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_2_ASYNC_COND_EN_Pos)                                                                   /*!< ASYNC_COND_EN Mask 0x00004000 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_2_ASYNC_COND_EN_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_2_ASYNC_COND_EN_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_2_ASYNC_COND_EN_Msk)   /*!< ASYNC_COND_EN Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_2_ASYNC_COND_EN_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_2_ASYNC_COND_EN_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_2_ASYNC_COND_EN_Pos)   /*!< ASYNC_COND_EN Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_2_SEL_RAW_IN_Pos     (13U)                                                                                                                   /*!< SEL_RAW_IN Position 13 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_2_SEL_RAW_IN_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_2_SEL_RAW_IN_Pos)                                                                /*!< SEL_RAW_IN Mask 0x00002000 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_2_SEL_RAW_IN_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_2_SEL_RAW_IN_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_2_SEL_RAW_IN_Msk)   /*!< SEL_RAW_IN Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_2_SEL_RAW_IN_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_2_SEL_RAW_IN_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_2_SEL_RAW_IN_Pos)   /*!< SEL_RAW_IN Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_2_HW_RLS_CTRL_SEL_Pos     (12U)                                                                                                                             /*!< HW_RLS_CTRL_SEL Position 12 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_2_HW_RLS_CTRL_SEL_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_2_HW_RLS_CTRL_SEL_Pos)                                                                     /*!< HW_RLS_CTRL_SEL Mask 0x00001000 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_2_HW_RLS_CTRL_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_2_HW_RLS_CTRL_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_2_HW_RLS_CTRL_SEL_Msk)   /*!< HW_RLS_CTRL_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_2_HW_RLS_CTRL_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_2_HW_RLS_CTRL_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_2_HW_RLS_CTRL_SEL_Pos)   /*!< HW_RLS_CTRL_SEL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_2_HW_GATING_CTRL_SEL_Pos     (11U)                                                                                                                                   /*!< HW_GATING_CTRL_SEL Position 11 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_2_HW_GATING_CTRL_SEL_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_2_HW_GATING_CTRL_SEL_Pos)                                                                        /*!< HW_GATING_CTRL_SEL Mask 0x00000800 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_2_HW_GATING_CTRL_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_2_HW_GATING_CTRL_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_2_HW_GATING_CTRL_SEL_Msk)   /*!< HW_GATING_CTRL_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_2_HW_GATING_CTRL_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_2_HW_GATING_CTRL_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_2_HW_GATING_CTRL_SEL_Pos)   /*!< HW_GATING_CTRL_SEL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_2_SEL_RELEASE_CTRL_Pos     (8U)                                                                                                                                /*!< SEL_RELEASE_CTRL Position 8 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_2_SEL_RELEASE_CTRL_Msk     (0x7U << CLB_TILE_CLB_OUTPUT_COND_CTRL_2_SEL_RELEASE_CTRL_Pos)                                                                      /*!< SEL_RELEASE_CTRL Mask 0x00000700 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_2_SEL_RELEASE_CTRL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_2_SEL_RELEASE_CTRL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_2_SEL_RELEASE_CTRL_Msk)   /*!< SEL_RELEASE_CTRL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_2_SEL_RELEASE_CTRL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_2_SEL_RELEASE_CTRL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_2_SEL_RELEASE_CTRL_Pos)   /*!< SEL_RELEASE_CTRL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_2_SEL_GATING_CTRL_Pos     (5U)                                                                                                                              /*!< SEL_GATING_CTRL Position 5 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_2_SEL_GATING_CTRL_Msk     (0x7U << CLB_TILE_CLB_OUTPUT_COND_CTRL_2_SEL_GATING_CTRL_Pos)                                                                     /*!< SEL_GATING_CTRL Mask 0x000000E0 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_2_SEL_GATING_CTRL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_2_SEL_GATING_CTRL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_2_SEL_GATING_CTRL_Msk)   /*!< SEL_GATING_CTRL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_2_SEL_GATING_CTRL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_2_SEL_GATING_CTRL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_2_SEL_GATING_CTRL_Pos)   /*!< SEL_GATING_CTRL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_2_LEVEL_3_SEL_Pos     (3U)                                                                                                                      /*!< LEVEL_3_SEL Position 3 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_2_LEVEL_3_SEL_Msk     (0x3U << CLB_TILE_CLB_OUTPUT_COND_CTRL_2_LEVEL_3_SEL_Pos)                                                                 /*!< LEVEL_3_SEL Mask 0x00000018 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_2_LEVEL_3_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_2_LEVEL_3_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_2_LEVEL_3_SEL_Msk)   /*!< LEVEL_3_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_2_LEVEL_3_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_2_LEVEL_3_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_2_LEVEL_3_SEL_Pos)   /*!< LEVEL_3_SEL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_2_LEVEL_2_SEL_Pos     (1U)                                                                                                                      /*!< LEVEL_2_SEL Position 1 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_2_LEVEL_2_SEL_Msk     (0x3U << CLB_TILE_CLB_OUTPUT_COND_CTRL_2_LEVEL_2_SEL_Pos)                                                                 /*!< LEVEL_2_SEL Mask 0x00000006 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_2_LEVEL_2_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_2_LEVEL_2_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_2_LEVEL_2_SEL_Msk)   /*!< LEVEL_2_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_2_LEVEL_2_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_2_LEVEL_2_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_2_LEVEL_2_SEL_Pos)   /*!< LEVEL_2_SEL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_2_LEVEL_1_SEL_Pos     (0U)                                                                                                                      /*!< LEVEL_1_SEL Position 0 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_2_LEVEL_1_SEL_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_2_LEVEL_1_SEL_Pos)                                                                 /*!< LEVEL_1_SEL Mask 0x00000001 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_2_LEVEL_1_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_2_LEVEL_1_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_2_LEVEL_1_SEL_Msk)   /*!< LEVEL_1_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_2_LEVEL_1_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_2_LEVEL_1_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_2_LEVEL_1_SEL_Pos)   /*!< LEVEL_1_SEL Get Value */

/* CLB_OUTPUT_COND_CTRL_3 bitfield */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_3_ASYNC_COND_EN_Pos     (14U)                                                                                                                         /*!< ASYNC_COND_EN Position 14 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_3_ASYNC_COND_EN_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_3_ASYNC_COND_EN_Pos)                                                                   /*!< ASYNC_COND_EN Mask 0x00004000 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_3_ASYNC_COND_EN_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_3_ASYNC_COND_EN_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_3_ASYNC_COND_EN_Msk)   /*!< ASYNC_COND_EN Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_3_ASYNC_COND_EN_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_3_ASYNC_COND_EN_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_3_ASYNC_COND_EN_Pos)   /*!< ASYNC_COND_EN Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_3_SEL_RAW_IN_Pos     (13U)                                                                                                                   /*!< SEL_RAW_IN Position 13 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_3_SEL_RAW_IN_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_3_SEL_RAW_IN_Pos)                                                                /*!< SEL_RAW_IN Mask 0x00002000 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_3_SEL_RAW_IN_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_3_SEL_RAW_IN_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_3_SEL_RAW_IN_Msk)   /*!< SEL_RAW_IN Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_3_SEL_RAW_IN_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_3_SEL_RAW_IN_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_3_SEL_RAW_IN_Pos)   /*!< SEL_RAW_IN Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_3_HW_RLS_CTRL_SEL_Pos     (12U)                                                                                                                             /*!< HW_RLS_CTRL_SEL Position 12 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_3_HW_RLS_CTRL_SEL_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_3_HW_RLS_CTRL_SEL_Pos)                                                                     /*!< HW_RLS_CTRL_SEL Mask 0x00001000 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_3_HW_RLS_CTRL_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_3_HW_RLS_CTRL_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_3_HW_RLS_CTRL_SEL_Msk)   /*!< HW_RLS_CTRL_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_3_HW_RLS_CTRL_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_3_HW_RLS_CTRL_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_3_HW_RLS_CTRL_SEL_Pos)   /*!< HW_RLS_CTRL_SEL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_3_HW_GATING_CTRL_SEL_Pos     (11U)                                                                                                                                   /*!< HW_GATING_CTRL_SEL Position 11 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_3_HW_GATING_CTRL_SEL_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_3_HW_GATING_CTRL_SEL_Pos)                                                                        /*!< HW_GATING_CTRL_SEL Mask 0x00000800 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_3_HW_GATING_CTRL_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_3_HW_GATING_CTRL_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_3_HW_GATING_CTRL_SEL_Msk)   /*!< HW_GATING_CTRL_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_3_HW_GATING_CTRL_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_3_HW_GATING_CTRL_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_3_HW_GATING_CTRL_SEL_Pos)   /*!< HW_GATING_CTRL_SEL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_3_SEL_RELEASE_CTRL_Pos     (8U)                                                                                                                                /*!< SEL_RELEASE_CTRL Position 8 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_3_SEL_RELEASE_CTRL_Msk     (0x7U << CLB_TILE_CLB_OUTPUT_COND_CTRL_3_SEL_RELEASE_CTRL_Pos)                                                                      /*!< SEL_RELEASE_CTRL Mask 0x00000700 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_3_SEL_RELEASE_CTRL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_3_SEL_RELEASE_CTRL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_3_SEL_RELEASE_CTRL_Msk)   /*!< SEL_RELEASE_CTRL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_3_SEL_RELEASE_CTRL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_3_SEL_RELEASE_CTRL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_3_SEL_RELEASE_CTRL_Pos)   /*!< SEL_RELEASE_CTRL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_3_SEL_GATING_CTRL_Pos     (5U)                                                                                                                              /*!< SEL_GATING_CTRL Position 5 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_3_SEL_GATING_CTRL_Msk     (0x7U << CLB_TILE_CLB_OUTPUT_COND_CTRL_3_SEL_GATING_CTRL_Pos)                                                                     /*!< SEL_GATING_CTRL Mask 0x000000E0 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_3_SEL_GATING_CTRL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_3_SEL_GATING_CTRL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_3_SEL_GATING_CTRL_Msk)   /*!< SEL_GATING_CTRL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_3_SEL_GATING_CTRL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_3_SEL_GATING_CTRL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_3_SEL_GATING_CTRL_Pos)   /*!< SEL_GATING_CTRL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_3_LEVEL_3_SEL_Pos     (3U)                                                                                                                      /*!< LEVEL_3_SEL Position 3 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_3_LEVEL_3_SEL_Msk     (0x3U << CLB_TILE_CLB_OUTPUT_COND_CTRL_3_LEVEL_3_SEL_Pos)                                                                 /*!< LEVEL_3_SEL Mask 0x00000018 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_3_LEVEL_3_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_3_LEVEL_3_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_3_LEVEL_3_SEL_Msk)   /*!< LEVEL_3_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_3_LEVEL_3_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_3_LEVEL_3_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_3_LEVEL_3_SEL_Pos)   /*!< LEVEL_3_SEL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_3_LEVEL_2_SEL_Pos     (1U)                                                                                                                      /*!< LEVEL_2_SEL Position 1 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_3_LEVEL_2_SEL_Msk     (0x3U << CLB_TILE_CLB_OUTPUT_COND_CTRL_3_LEVEL_2_SEL_Pos)                                                                 /*!< LEVEL_2_SEL Mask 0x00000006 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_3_LEVEL_2_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_3_LEVEL_2_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_3_LEVEL_2_SEL_Msk)   /*!< LEVEL_2_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_3_LEVEL_2_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_3_LEVEL_2_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_3_LEVEL_2_SEL_Pos)   /*!< LEVEL_2_SEL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_3_LEVEL_1_SEL_Pos     (0U)                                                                                                                      /*!< LEVEL_1_SEL Position 0 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_3_LEVEL_1_SEL_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_3_LEVEL_1_SEL_Pos)                                                                 /*!< LEVEL_1_SEL Mask 0x00000001 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_3_LEVEL_1_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_3_LEVEL_1_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_3_LEVEL_1_SEL_Msk)   /*!< LEVEL_1_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_3_LEVEL_1_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_3_LEVEL_1_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_3_LEVEL_1_SEL_Pos)   /*!< LEVEL_1_SEL Get Value */

/* CLB_OUTPUT_COND_CTRL_4 bitfield */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_4_ASYNC_COND_EN_Pos     (14U)                                                                                                                         /*!< ASYNC_COND_EN Position 14 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_4_ASYNC_COND_EN_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_4_ASYNC_COND_EN_Pos)                                                                   /*!< ASYNC_COND_EN Mask 0x00004000 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_4_ASYNC_COND_EN_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_4_ASYNC_COND_EN_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_4_ASYNC_COND_EN_Msk)   /*!< ASYNC_COND_EN Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_4_ASYNC_COND_EN_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_4_ASYNC_COND_EN_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_4_ASYNC_COND_EN_Pos)   /*!< ASYNC_COND_EN Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_4_SEL_RAW_IN_Pos     (13U)                                                                                                                   /*!< SEL_RAW_IN Position 13 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_4_SEL_RAW_IN_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_4_SEL_RAW_IN_Pos)                                                                /*!< SEL_RAW_IN Mask 0x00002000 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_4_SEL_RAW_IN_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_4_SEL_RAW_IN_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_4_SEL_RAW_IN_Msk)   /*!< SEL_RAW_IN Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_4_SEL_RAW_IN_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_4_SEL_RAW_IN_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_4_SEL_RAW_IN_Pos)   /*!< SEL_RAW_IN Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_4_HW_RLS_CTRL_SEL_Pos     (12U)                                                                                                                             /*!< HW_RLS_CTRL_SEL Position 12 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_4_HW_RLS_CTRL_SEL_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_4_HW_RLS_CTRL_SEL_Pos)                                                                     /*!< HW_RLS_CTRL_SEL Mask 0x00001000 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_4_HW_RLS_CTRL_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_4_HW_RLS_CTRL_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_4_HW_RLS_CTRL_SEL_Msk)   /*!< HW_RLS_CTRL_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_4_HW_RLS_CTRL_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_4_HW_RLS_CTRL_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_4_HW_RLS_CTRL_SEL_Pos)   /*!< HW_RLS_CTRL_SEL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_4_HW_GATING_CTRL_SEL_Pos     (11U)                                                                                                                                   /*!< HW_GATING_CTRL_SEL Position 11 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_4_HW_GATING_CTRL_SEL_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_4_HW_GATING_CTRL_SEL_Pos)                                                                        /*!< HW_GATING_CTRL_SEL Mask 0x00000800 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_4_HW_GATING_CTRL_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_4_HW_GATING_CTRL_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_4_HW_GATING_CTRL_SEL_Msk)   /*!< HW_GATING_CTRL_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_4_HW_GATING_CTRL_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_4_HW_GATING_CTRL_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_4_HW_GATING_CTRL_SEL_Pos)   /*!< HW_GATING_CTRL_SEL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_4_SEL_RELEASE_CTRL_Pos     (8U)                                                                                                                                /*!< SEL_RELEASE_CTRL Position 8 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_4_SEL_RELEASE_CTRL_Msk     (0x7U << CLB_TILE_CLB_OUTPUT_COND_CTRL_4_SEL_RELEASE_CTRL_Pos)                                                                      /*!< SEL_RELEASE_CTRL Mask 0x00000700 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_4_SEL_RELEASE_CTRL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_4_SEL_RELEASE_CTRL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_4_SEL_RELEASE_CTRL_Msk)   /*!< SEL_RELEASE_CTRL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_4_SEL_RELEASE_CTRL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_4_SEL_RELEASE_CTRL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_4_SEL_RELEASE_CTRL_Pos)   /*!< SEL_RELEASE_CTRL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_4_SEL_GATING_CTRL_Pos     (5U)                                                                                                                              /*!< SEL_GATING_CTRL Position 5 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_4_SEL_GATING_CTRL_Msk     (0x7U << CLB_TILE_CLB_OUTPUT_COND_CTRL_4_SEL_GATING_CTRL_Pos)                                                                     /*!< SEL_GATING_CTRL Mask 0x000000E0 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_4_SEL_GATING_CTRL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_4_SEL_GATING_CTRL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_4_SEL_GATING_CTRL_Msk)   /*!< SEL_GATING_CTRL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_4_SEL_GATING_CTRL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_4_SEL_GATING_CTRL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_4_SEL_GATING_CTRL_Pos)   /*!< SEL_GATING_CTRL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_4_LEVEL_3_SEL_Pos     (3U)                                                                                                                      /*!< LEVEL_3_SEL Position 3 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_4_LEVEL_3_SEL_Msk     (0x3U << CLB_TILE_CLB_OUTPUT_COND_CTRL_4_LEVEL_3_SEL_Pos)                                                                 /*!< LEVEL_3_SEL Mask 0x00000018 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_4_LEVEL_3_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_4_LEVEL_3_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_4_LEVEL_3_SEL_Msk)   /*!< LEVEL_3_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_4_LEVEL_3_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_4_LEVEL_3_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_4_LEVEL_3_SEL_Pos)   /*!< LEVEL_3_SEL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_4_LEVEL_2_SEL_Pos     (1U)                                                                                                                      /*!< LEVEL_2_SEL Position 1 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_4_LEVEL_2_SEL_Msk     (0x3U << CLB_TILE_CLB_OUTPUT_COND_CTRL_4_LEVEL_2_SEL_Pos)                                                                 /*!< LEVEL_2_SEL Mask 0x00000006 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_4_LEVEL_2_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_4_LEVEL_2_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_4_LEVEL_2_SEL_Msk)   /*!< LEVEL_2_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_4_LEVEL_2_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_4_LEVEL_2_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_4_LEVEL_2_SEL_Pos)   /*!< LEVEL_2_SEL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_4_LEVEL_1_SEL_Pos     (0U)                                                                                                                      /*!< LEVEL_1_SEL Position 0 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_4_LEVEL_1_SEL_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_4_LEVEL_1_SEL_Pos)                                                                 /*!< LEVEL_1_SEL Mask 0x00000001 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_4_LEVEL_1_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_4_LEVEL_1_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_4_LEVEL_1_SEL_Msk)   /*!< LEVEL_1_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_4_LEVEL_1_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_4_LEVEL_1_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_4_LEVEL_1_SEL_Pos)   /*!< LEVEL_1_SEL Get Value */

/* CLB_OUTPUT_COND_CTRL_5 bitfield */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_5_ASYNC_COND_EN_Pos     (14U)                                                                                                                         /*!< ASYNC_COND_EN Position 14 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_5_ASYNC_COND_EN_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_5_ASYNC_COND_EN_Pos)                                                                   /*!< ASYNC_COND_EN Mask 0x00004000 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_5_ASYNC_COND_EN_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_5_ASYNC_COND_EN_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_5_ASYNC_COND_EN_Msk)   /*!< ASYNC_COND_EN Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_5_ASYNC_COND_EN_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_5_ASYNC_COND_EN_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_5_ASYNC_COND_EN_Pos)   /*!< ASYNC_COND_EN Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_5_SEL_RAW_IN_Pos     (13U)                                                                                                                   /*!< SEL_RAW_IN Position 13 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_5_SEL_RAW_IN_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_5_SEL_RAW_IN_Pos)                                                                /*!< SEL_RAW_IN Mask 0x00002000 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_5_SEL_RAW_IN_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_5_SEL_RAW_IN_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_5_SEL_RAW_IN_Msk)   /*!< SEL_RAW_IN Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_5_SEL_RAW_IN_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_5_SEL_RAW_IN_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_5_SEL_RAW_IN_Pos)   /*!< SEL_RAW_IN Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_5_HW_RLS_CTRL_SEL_Pos     (12U)                                                                                                                             /*!< HW_RLS_CTRL_SEL Position 12 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_5_HW_RLS_CTRL_SEL_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_5_HW_RLS_CTRL_SEL_Pos)                                                                     /*!< HW_RLS_CTRL_SEL Mask 0x00001000 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_5_HW_RLS_CTRL_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_5_HW_RLS_CTRL_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_5_HW_RLS_CTRL_SEL_Msk)   /*!< HW_RLS_CTRL_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_5_HW_RLS_CTRL_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_5_HW_RLS_CTRL_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_5_HW_RLS_CTRL_SEL_Pos)   /*!< HW_RLS_CTRL_SEL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_5_HW_GATING_CTRL_SEL_Pos     (11U)                                                                                                                                   /*!< HW_GATING_CTRL_SEL Position 11 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_5_HW_GATING_CTRL_SEL_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_5_HW_GATING_CTRL_SEL_Pos)                                                                        /*!< HW_GATING_CTRL_SEL Mask 0x00000800 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_5_HW_GATING_CTRL_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_5_HW_GATING_CTRL_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_5_HW_GATING_CTRL_SEL_Msk)   /*!< HW_GATING_CTRL_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_5_HW_GATING_CTRL_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_5_HW_GATING_CTRL_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_5_HW_GATING_CTRL_SEL_Pos)   /*!< HW_GATING_CTRL_SEL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_5_SEL_RELEASE_CTRL_Pos     (8U)                                                                                                                                /*!< SEL_RELEASE_CTRL Position 8 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_5_SEL_RELEASE_CTRL_Msk     (0x7U << CLB_TILE_CLB_OUTPUT_COND_CTRL_5_SEL_RELEASE_CTRL_Pos)                                                                      /*!< SEL_RELEASE_CTRL Mask 0x00000700 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_5_SEL_RELEASE_CTRL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_5_SEL_RELEASE_CTRL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_5_SEL_RELEASE_CTRL_Msk)   /*!< SEL_RELEASE_CTRL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_5_SEL_RELEASE_CTRL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_5_SEL_RELEASE_CTRL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_5_SEL_RELEASE_CTRL_Pos)   /*!< SEL_RELEASE_CTRL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_5_SEL_GATING_CTRL_Pos     (5U)                                                                                                                              /*!< SEL_GATING_CTRL Position 5 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_5_SEL_GATING_CTRL_Msk     (0x7U << CLB_TILE_CLB_OUTPUT_COND_CTRL_5_SEL_GATING_CTRL_Pos)                                                                     /*!< SEL_GATING_CTRL Mask 0x000000E0 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_5_SEL_GATING_CTRL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_5_SEL_GATING_CTRL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_5_SEL_GATING_CTRL_Msk)   /*!< SEL_GATING_CTRL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_5_SEL_GATING_CTRL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_5_SEL_GATING_CTRL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_5_SEL_GATING_CTRL_Pos)   /*!< SEL_GATING_CTRL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_5_LEVEL_3_SEL_Pos     (3U)                                                                                                                      /*!< LEVEL_3_SEL Position 3 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_5_LEVEL_3_SEL_Msk     (0x3U << CLB_TILE_CLB_OUTPUT_COND_CTRL_5_LEVEL_3_SEL_Pos)                                                                 /*!< LEVEL_3_SEL Mask 0x00000018 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_5_LEVEL_3_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_5_LEVEL_3_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_5_LEVEL_3_SEL_Msk)   /*!< LEVEL_3_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_5_LEVEL_3_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_5_LEVEL_3_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_5_LEVEL_3_SEL_Pos)   /*!< LEVEL_3_SEL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_5_LEVEL_2_SEL_Pos     (1U)                                                                                                                      /*!< LEVEL_2_SEL Position 1 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_5_LEVEL_2_SEL_Msk     (0x3U << CLB_TILE_CLB_OUTPUT_COND_CTRL_5_LEVEL_2_SEL_Pos)                                                                 /*!< LEVEL_2_SEL Mask 0x00000006 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_5_LEVEL_2_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_5_LEVEL_2_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_5_LEVEL_2_SEL_Msk)   /*!< LEVEL_2_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_5_LEVEL_2_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_5_LEVEL_2_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_5_LEVEL_2_SEL_Pos)   /*!< LEVEL_2_SEL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_5_LEVEL_1_SEL_Pos     (0U)                                                                                                                      /*!< LEVEL_1_SEL Position 0 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_5_LEVEL_1_SEL_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_5_LEVEL_1_SEL_Pos)                                                                 /*!< LEVEL_1_SEL Mask 0x00000001 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_5_LEVEL_1_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_5_LEVEL_1_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_5_LEVEL_1_SEL_Msk)   /*!< LEVEL_1_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_5_LEVEL_1_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_5_LEVEL_1_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_5_LEVEL_1_SEL_Pos)   /*!< LEVEL_1_SEL Get Value */

/* CLB_OUTPUT_COND_CTRL_6 bitfield */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_6_ASYNC_COND_EN_Pos     (14U)                                                                                                                         /*!< ASYNC_COND_EN Position 14 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_6_ASYNC_COND_EN_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_6_ASYNC_COND_EN_Pos)                                                                   /*!< ASYNC_COND_EN Mask 0x00004000 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_6_ASYNC_COND_EN_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_6_ASYNC_COND_EN_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_6_ASYNC_COND_EN_Msk)   /*!< ASYNC_COND_EN Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_6_ASYNC_COND_EN_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_6_ASYNC_COND_EN_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_6_ASYNC_COND_EN_Pos)   /*!< ASYNC_COND_EN Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_6_SEL_RAW_IN_Pos     (13U)                                                                                                                   /*!< SEL_RAW_IN Position 13 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_6_SEL_RAW_IN_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_6_SEL_RAW_IN_Pos)                                                                /*!< SEL_RAW_IN Mask 0x00002000 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_6_SEL_RAW_IN_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_6_SEL_RAW_IN_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_6_SEL_RAW_IN_Msk)   /*!< SEL_RAW_IN Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_6_SEL_RAW_IN_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_6_SEL_RAW_IN_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_6_SEL_RAW_IN_Pos)   /*!< SEL_RAW_IN Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_6_HW_RLS_CTRL_SEL_Pos     (12U)                                                                                                                             /*!< HW_RLS_CTRL_SEL Position 12 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_6_HW_RLS_CTRL_SEL_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_6_HW_RLS_CTRL_SEL_Pos)                                                                     /*!< HW_RLS_CTRL_SEL Mask 0x00001000 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_6_HW_RLS_CTRL_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_6_HW_RLS_CTRL_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_6_HW_RLS_CTRL_SEL_Msk)   /*!< HW_RLS_CTRL_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_6_HW_RLS_CTRL_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_6_HW_RLS_CTRL_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_6_HW_RLS_CTRL_SEL_Pos)   /*!< HW_RLS_CTRL_SEL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_6_HW_GATING_CTRL_SEL_Pos     (11U)                                                                                                                                   /*!< HW_GATING_CTRL_SEL Position 11 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_6_HW_GATING_CTRL_SEL_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_6_HW_GATING_CTRL_SEL_Pos)                                                                        /*!< HW_GATING_CTRL_SEL Mask 0x00000800 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_6_HW_GATING_CTRL_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_6_HW_GATING_CTRL_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_6_HW_GATING_CTRL_SEL_Msk)   /*!< HW_GATING_CTRL_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_6_HW_GATING_CTRL_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_6_HW_GATING_CTRL_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_6_HW_GATING_CTRL_SEL_Pos)   /*!< HW_GATING_CTRL_SEL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_6_SEL_RELEASE_CTRL_Pos     (8U)                                                                                                                                /*!< SEL_RELEASE_CTRL Position 8 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_6_SEL_RELEASE_CTRL_Msk     (0x7U << CLB_TILE_CLB_OUTPUT_COND_CTRL_6_SEL_RELEASE_CTRL_Pos)                                                                      /*!< SEL_RELEASE_CTRL Mask 0x00000700 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_6_SEL_RELEASE_CTRL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_6_SEL_RELEASE_CTRL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_6_SEL_RELEASE_CTRL_Msk)   /*!< SEL_RELEASE_CTRL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_6_SEL_RELEASE_CTRL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_6_SEL_RELEASE_CTRL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_6_SEL_RELEASE_CTRL_Pos)   /*!< SEL_RELEASE_CTRL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_6_SEL_GATING_CTRL_Pos     (5U)                                                                                                                              /*!< SEL_GATING_CTRL Position 5 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_6_SEL_GATING_CTRL_Msk     (0x7U << CLB_TILE_CLB_OUTPUT_COND_CTRL_6_SEL_GATING_CTRL_Pos)                                                                     /*!< SEL_GATING_CTRL Mask 0x000000E0 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_6_SEL_GATING_CTRL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_6_SEL_GATING_CTRL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_6_SEL_GATING_CTRL_Msk)   /*!< SEL_GATING_CTRL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_6_SEL_GATING_CTRL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_6_SEL_GATING_CTRL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_6_SEL_GATING_CTRL_Pos)   /*!< SEL_GATING_CTRL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_6_LEVEL_3_SEL_Pos     (3U)                                                                                                                      /*!< LEVEL_3_SEL Position 3 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_6_LEVEL_3_SEL_Msk     (0x3U << CLB_TILE_CLB_OUTPUT_COND_CTRL_6_LEVEL_3_SEL_Pos)                                                                 /*!< LEVEL_3_SEL Mask 0x00000018 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_6_LEVEL_3_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_6_LEVEL_3_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_6_LEVEL_3_SEL_Msk)   /*!< LEVEL_3_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_6_LEVEL_3_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_6_LEVEL_3_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_6_LEVEL_3_SEL_Pos)   /*!< LEVEL_3_SEL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_6_LEVEL_2_SEL_Pos     (1U)                                                                                                                      /*!< LEVEL_2_SEL Position 1 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_6_LEVEL_2_SEL_Msk     (0x3U << CLB_TILE_CLB_OUTPUT_COND_CTRL_6_LEVEL_2_SEL_Pos)                                                                 /*!< LEVEL_2_SEL Mask 0x00000006 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_6_LEVEL_2_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_6_LEVEL_2_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_6_LEVEL_2_SEL_Msk)   /*!< LEVEL_2_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_6_LEVEL_2_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_6_LEVEL_2_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_6_LEVEL_2_SEL_Pos)   /*!< LEVEL_2_SEL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_6_LEVEL_1_SEL_Pos     (0U)                                                                                                                      /*!< LEVEL_1_SEL Position 0 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_6_LEVEL_1_SEL_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_6_LEVEL_1_SEL_Pos)                                                                 /*!< LEVEL_1_SEL Mask 0x00000001 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_6_LEVEL_1_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_6_LEVEL_1_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_6_LEVEL_1_SEL_Msk)   /*!< LEVEL_1_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_6_LEVEL_1_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_6_LEVEL_1_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_6_LEVEL_1_SEL_Pos)   /*!< LEVEL_1_SEL Get Value */

/* CLB_OUTPUT_COND_CTRL_7 bitfield */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_7_ASYNC_COND_EN_Pos     (14U)                                                                                                                         /*!< ASYNC_COND_EN Position 14 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_7_ASYNC_COND_EN_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_7_ASYNC_COND_EN_Pos)                                                                   /*!< ASYNC_COND_EN Mask 0x00004000 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_7_ASYNC_COND_EN_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_7_ASYNC_COND_EN_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_7_ASYNC_COND_EN_Msk)   /*!< ASYNC_COND_EN Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_7_ASYNC_COND_EN_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_7_ASYNC_COND_EN_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_7_ASYNC_COND_EN_Pos)   /*!< ASYNC_COND_EN Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_7_SEL_RAW_IN_Pos     (13U)                                                                                                                   /*!< SEL_RAW_IN Position 13 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_7_SEL_RAW_IN_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_7_SEL_RAW_IN_Pos)                                                                /*!< SEL_RAW_IN Mask 0x00002000 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_7_SEL_RAW_IN_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_7_SEL_RAW_IN_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_7_SEL_RAW_IN_Msk)   /*!< SEL_RAW_IN Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_7_SEL_RAW_IN_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_7_SEL_RAW_IN_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_7_SEL_RAW_IN_Pos)   /*!< SEL_RAW_IN Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_7_HW_RLS_CTRL_SEL_Pos     (12U)                                                                                                                             /*!< HW_RLS_CTRL_SEL Position 12 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_7_HW_RLS_CTRL_SEL_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_7_HW_RLS_CTRL_SEL_Pos)                                                                     /*!< HW_RLS_CTRL_SEL Mask 0x00001000 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_7_HW_RLS_CTRL_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_7_HW_RLS_CTRL_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_7_HW_RLS_CTRL_SEL_Msk)   /*!< HW_RLS_CTRL_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_7_HW_RLS_CTRL_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_7_HW_RLS_CTRL_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_7_HW_RLS_CTRL_SEL_Pos)   /*!< HW_RLS_CTRL_SEL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_7_HW_GATING_CTRL_SEL_Pos     (11U)                                                                                                                                   /*!< HW_GATING_CTRL_SEL Position 11 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_7_HW_GATING_CTRL_SEL_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_7_HW_GATING_CTRL_SEL_Pos)                                                                        /*!< HW_GATING_CTRL_SEL Mask 0x00000800 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_7_HW_GATING_CTRL_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_7_HW_GATING_CTRL_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_7_HW_GATING_CTRL_SEL_Msk)   /*!< HW_GATING_CTRL_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_7_HW_GATING_CTRL_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_7_HW_GATING_CTRL_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_7_HW_GATING_CTRL_SEL_Pos)   /*!< HW_GATING_CTRL_SEL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_7_SEL_RELEASE_CTRL_Pos     (8U)                                                                                                                                /*!< SEL_RELEASE_CTRL Position 8 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_7_SEL_RELEASE_CTRL_Msk     (0x7U << CLB_TILE_CLB_OUTPUT_COND_CTRL_7_SEL_RELEASE_CTRL_Pos)                                                                      /*!< SEL_RELEASE_CTRL Mask 0x00000700 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_7_SEL_RELEASE_CTRL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_7_SEL_RELEASE_CTRL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_7_SEL_RELEASE_CTRL_Msk)   /*!< SEL_RELEASE_CTRL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_7_SEL_RELEASE_CTRL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_7_SEL_RELEASE_CTRL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_7_SEL_RELEASE_CTRL_Pos)   /*!< SEL_RELEASE_CTRL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_7_SEL_GATING_CTRL_Pos     (5U)                                                                                                                              /*!< SEL_GATING_CTRL Position 5 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_7_SEL_GATING_CTRL_Msk     (0x7U << CLB_TILE_CLB_OUTPUT_COND_CTRL_7_SEL_GATING_CTRL_Pos)                                                                     /*!< SEL_GATING_CTRL Mask 0x000000E0 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_7_SEL_GATING_CTRL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_7_SEL_GATING_CTRL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_7_SEL_GATING_CTRL_Msk)   /*!< SEL_GATING_CTRL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_7_SEL_GATING_CTRL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_7_SEL_GATING_CTRL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_7_SEL_GATING_CTRL_Pos)   /*!< SEL_GATING_CTRL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_7_LEVEL_3_SEL_Pos     (3U)                                                                                                                      /*!< LEVEL_3_SEL Position 3 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_7_LEVEL_3_SEL_Msk     (0x3U << CLB_TILE_CLB_OUTPUT_COND_CTRL_7_LEVEL_3_SEL_Pos)                                                                 /*!< LEVEL_3_SEL Mask 0x00000018 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_7_LEVEL_3_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_7_LEVEL_3_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_7_LEVEL_3_SEL_Msk)   /*!< LEVEL_3_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_7_LEVEL_3_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_7_LEVEL_3_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_7_LEVEL_3_SEL_Pos)   /*!< LEVEL_3_SEL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_7_LEVEL_2_SEL_Pos     (1U)                                                                                                                      /*!< LEVEL_2_SEL Position 1 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_7_LEVEL_2_SEL_Msk     (0x3U << CLB_TILE_CLB_OUTPUT_COND_CTRL_7_LEVEL_2_SEL_Pos)                                                                 /*!< LEVEL_2_SEL Mask 0x00000006 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_7_LEVEL_2_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_7_LEVEL_2_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_7_LEVEL_2_SEL_Msk)   /*!< LEVEL_2_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_7_LEVEL_2_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_7_LEVEL_2_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_7_LEVEL_2_SEL_Pos)   /*!< LEVEL_2_SEL Get Value */

#define CLB_TILE_CLB_OUTPUT_COND_CTRL_7_LEVEL_1_SEL_Pos     (0U)                                                                                                                      /*!< LEVEL_1_SEL Position 0 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_7_LEVEL_1_SEL_Msk     (0x1U << CLB_TILE_CLB_OUTPUT_COND_CTRL_7_LEVEL_1_SEL_Pos)                                                                 /*!< LEVEL_1_SEL Mask 0x00000001 */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_7_LEVEL_1_SEL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUTPUT_COND_CTRL_7_LEVEL_1_SEL_Pos) & CLB_TILE_CLB_OUTPUT_COND_CTRL_7_LEVEL_1_SEL_Msk)   /*!< LEVEL_1_SEL Set Value */
#define CLB_TILE_CLB_OUTPUT_COND_CTRL_7_LEVEL_1_SEL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUTPUT_COND_CTRL_7_LEVEL_1_SEL_Msk) >> CLB_TILE_CLB_OUTPUT_COND_CTRL_7_LEVEL_1_SEL_Pos)   /*!< LEVEL_1_SEL Get Value */

/* CLB_MISC_ACCESS_CTRL bitfield */
#define CLB_TILE_CLB_MISC_ACCESS_CTRL_BLKEN_Pos     (1U)                                                                                                      /*!< BLKEN Position 1 */
#define CLB_TILE_CLB_MISC_ACCESS_CTRL_BLKEN_Msk     (0x1U << CLB_TILE_CLB_MISC_ACCESS_CTRL_BLKEN_Pos)                                                         /*!< BLKEN Mask 0x00000002 */
#define CLB_TILE_CLB_MISC_ACCESS_CTRL_BLKEN_Set(x)  (((uint16_t) (x) << CLB_TILE_CLB_MISC_ACCESS_CTRL_BLKEN_Pos) & CLB_TILE_CLB_MISC_ACCESS_CTRL_BLKEN_Msk)   /*!< BLKEN Set Value */
#define CLB_TILE_CLB_MISC_ACCESS_CTRL_BLKEN_Get(x)  (((uint16_t) (x) & CLB_TILE_CLB_MISC_ACCESS_CTRL_BLKEN_Msk) >> CLB_TILE_CLB_MISC_ACCESS_CTRL_BLKEN_Pos)   /*!< BLKEN Get Value */

/* CLB_LOAD_EN bitfield */
#define CLB_TILE_CLB_LOAD_EN_GLOBAL_EN_Pos     (1U)                                                                                            /*!< GLOBAL_EN Position 1 */
#define CLB_TILE_CLB_LOAD_EN_GLOBAL_EN_Msk     (0x1U << CLB_TILE_CLB_LOAD_EN_GLOBAL_EN_Pos)                                                    /*!< GLOBAL_EN Mask 0x00000002 */
#define CLB_TILE_CLB_LOAD_EN_GLOBAL_EN_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_LOAD_EN_GLOBAL_EN_Pos) & CLB_TILE_CLB_LOAD_EN_GLOBAL_EN_Msk)   /*!< GLOBAL_EN Set Value */
#define CLB_TILE_CLB_LOAD_EN_GLOBAL_EN_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_LOAD_EN_GLOBAL_EN_Msk) >> CLB_TILE_CLB_LOAD_EN_GLOBAL_EN_Pos)   /*!< GLOBAL_EN Get Value */

#define CLB_TILE_CLB_LOAD_EN_LOAD_EN_Pos     (0U)                                                                                        /*!< LOAD_EN Position 0 */
#define CLB_TILE_CLB_LOAD_EN_LOAD_EN_Msk     (0x1U << CLB_TILE_CLB_LOAD_EN_LOAD_EN_Pos)                                                  /*!< LOAD_EN Mask 0x00000001 */
#define CLB_TILE_CLB_LOAD_EN_LOAD_EN_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_LOAD_EN_LOAD_EN_Pos) & CLB_TILE_CLB_LOAD_EN_LOAD_EN_Msk)   /*!< LOAD_EN Set Value */
#define CLB_TILE_CLB_LOAD_EN_LOAD_EN_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_LOAD_EN_LOAD_EN_Msk) >> CLB_TILE_CLB_LOAD_EN_LOAD_EN_Pos)   /*!< LOAD_EN Get Value */

/* CLB_LOAD_ADDR bitfield */
#define CLB_TILE_CLB_LOAD_ADDR_ADDR_Pos     (0U)                                                                                      /*!< ADDR Position 0 */
#define CLB_TILE_CLB_LOAD_ADDR_ADDR_Msk     (0x3fU << CLB_TILE_CLB_LOAD_ADDR_ADDR_Pos)                                                /*!< ADDR Mask 0x0000003F */
#define CLB_TILE_CLB_LOAD_ADDR_ADDR_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_LOAD_ADDR_ADDR_Pos) & CLB_TILE_CLB_LOAD_ADDR_ADDR_Msk)   /*!< ADDR Set Value */
#define CLB_TILE_CLB_LOAD_ADDR_ADDR_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_LOAD_ADDR_ADDR_Msk) >> CLB_TILE_CLB_LOAD_ADDR_ADDR_Pos)   /*!< ADDR Get Value */

/* CLB_LOAD_DATA bitfield */
#define CLB_TILE_CLB_LOAD_DATA_DATA_Pos     (0U)                                                                                      /*!< DATA Position 0 */
#define CLB_TILE_CLB_LOAD_DATA_DATA_Msk     (0xffffffffU << CLB_TILE_CLB_LOAD_DATA_DATA_Pos)                                          /*!< DATA Mask 0xFFFFFFFF */
#define CLB_TILE_CLB_LOAD_DATA_DATA_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_LOAD_DATA_DATA_Pos) & CLB_TILE_CLB_LOAD_DATA_DATA_Msk)   /*!< DATA Set Value */
#define CLB_TILE_CLB_LOAD_DATA_DATA_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_LOAD_DATA_DATA_Msk) >> CLB_TILE_CLB_LOAD_DATA_DATA_Pos)   /*!< DATA Get Value */

/* CLB_INPUT_FILTER bitfield */
#define CLB_TILE_CLB_INPUT_FILTER_SYNC7_Pos     (23U)                                                                                             /*!< SYNC7 Position 23 */
#define CLB_TILE_CLB_INPUT_FILTER_SYNC7_Msk     (0x1U << CLB_TILE_CLB_INPUT_FILTER_SYNC7_Pos)                                                     /*!< SYNC7 Mask 0x00800000 */
#define CLB_TILE_CLB_INPUT_FILTER_SYNC7_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_INPUT_FILTER_SYNC7_Pos) & CLB_TILE_CLB_INPUT_FILTER_SYNC7_Msk)   /*!< SYNC7 Set Value */
#define CLB_TILE_CLB_INPUT_FILTER_SYNC7_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_INPUT_FILTER_SYNC7_Msk) >> CLB_TILE_CLB_INPUT_FILTER_SYNC7_Pos)   /*!< SYNC7 Get Value */

#define CLB_TILE_CLB_INPUT_FILTER_SYNC6_Pos     (22U)                                                                                             /*!< SYNC6 Position 22 */
#define CLB_TILE_CLB_INPUT_FILTER_SYNC6_Msk     (0x1U << CLB_TILE_CLB_INPUT_FILTER_SYNC6_Pos)                                                     /*!< SYNC6 Mask 0x00400000 */
#define CLB_TILE_CLB_INPUT_FILTER_SYNC6_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_INPUT_FILTER_SYNC6_Pos) & CLB_TILE_CLB_INPUT_FILTER_SYNC6_Msk)   /*!< SYNC6 Set Value */
#define CLB_TILE_CLB_INPUT_FILTER_SYNC6_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_INPUT_FILTER_SYNC6_Msk) >> CLB_TILE_CLB_INPUT_FILTER_SYNC6_Pos)   /*!< SYNC6 Get Value */

#define CLB_TILE_CLB_INPUT_FILTER_SYNC5_Pos     (21U)                                                                                             /*!< SYNC5 Position 21 */
#define CLB_TILE_CLB_INPUT_FILTER_SYNC5_Msk     (0x1U << CLB_TILE_CLB_INPUT_FILTER_SYNC5_Pos)                                                     /*!< SYNC5 Mask 0x00200000 */
#define CLB_TILE_CLB_INPUT_FILTER_SYNC5_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_INPUT_FILTER_SYNC5_Pos) & CLB_TILE_CLB_INPUT_FILTER_SYNC5_Msk)   /*!< SYNC5 Set Value */
#define CLB_TILE_CLB_INPUT_FILTER_SYNC5_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_INPUT_FILTER_SYNC5_Msk) >> CLB_TILE_CLB_INPUT_FILTER_SYNC5_Pos)   /*!< SYNC5 Get Value */

#define CLB_TILE_CLB_INPUT_FILTER_SYNC4_Pos     (20U)                                                                                             /*!< SYNC4 Position 20 */
#define CLB_TILE_CLB_INPUT_FILTER_SYNC4_Msk     (0x1U << CLB_TILE_CLB_INPUT_FILTER_SYNC4_Pos)                                                     /*!< SYNC4 Mask 0x00100000 */
#define CLB_TILE_CLB_INPUT_FILTER_SYNC4_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_INPUT_FILTER_SYNC4_Pos) & CLB_TILE_CLB_INPUT_FILTER_SYNC4_Msk)   /*!< SYNC4 Set Value */
#define CLB_TILE_CLB_INPUT_FILTER_SYNC4_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_INPUT_FILTER_SYNC4_Msk) >> CLB_TILE_CLB_INPUT_FILTER_SYNC4_Pos)   /*!< SYNC4 Get Value */

#define CLB_TILE_CLB_INPUT_FILTER_SYNC3_Pos     (19U)                                                                                             /*!< SYNC3 Position 19 */
#define CLB_TILE_CLB_INPUT_FILTER_SYNC3_Msk     (0x1U << CLB_TILE_CLB_INPUT_FILTER_SYNC3_Pos)                                                     /*!< SYNC3 Mask 0x00080000 */
#define CLB_TILE_CLB_INPUT_FILTER_SYNC3_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_INPUT_FILTER_SYNC3_Pos) & CLB_TILE_CLB_INPUT_FILTER_SYNC3_Msk)   /*!< SYNC3 Set Value */
#define CLB_TILE_CLB_INPUT_FILTER_SYNC3_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_INPUT_FILTER_SYNC3_Msk) >> CLB_TILE_CLB_INPUT_FILTER_SYNC3_Pos)   /*!< SYNC3 Get Value */

#define CLB_TILE_CLB_INPUT_FILTER_SYNC2_Pos     (18U)                                                                                             /*!< SYNC2 Position 18 */
#define CLB_TILE_CLB_INPUT_FILTER_SYNC2_Msk     (0x1U << CLB_TILE_CLB_INPUT_FILTER_SYNC2_Pos)                                                     /*!< SYNC2 Mask 0x00040000 */
#define CLB_TILE_CLB_INPUT_FILTER_SYNC2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_INPUT_FILTER_SYNC2_Pos) & CLB_TILE_CLB_INPUT_FILTER_SYNC2_Msk)   /*!< SYNC2 Set Value */
#define CLB_TILE_CLB_INPUT_FILTER_SYNC2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_INPUT_FILTER_SYNC2_Msk) >> CLB_TILE_CLB_INPUT_FILTER_SYNC2_Pos)   /*!< SYNC2 Get Value */

#define CLB_TILE_CLB_INPUT_FILTER_SYNC1_Pos     (17U)                                                                                             /*!< SYNC1 Position 17 */
#define CLB_TILE_CLB_INPUT_FILTER_SYNC1_Msk     (0x1U << CLB_TILE_CLB_INPUT_FILTER_SYNC1_Pos)                                                     /*!< SYNC1 Mask 0x00020000 */
#define CLB_TILE_CLB_INPUT_FILTER_SYNC1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_INPUT_FILTER_SYNC1_Pos) & CLB_TILE_CLB_INPUT_FILTER_SYNC1_Msk)   /*!< SYNC1 Set Value */
#define CLB_TILE_CLB_INPUT_FILTER_SYNC1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_INPUT_FILTER_SYNC1_Msk) >> CLB_TILE_CLB_INPUT_FILTER_SYNC1_Pos)   /*!< SYNC1 Get Value */

#define CLB_TILE_CLB_INPUT_FILTER_SYNC0_Pos     (16U)                                                                                             /*!< SYNC0 Position 16 */
#define CLB_TILE_CLB_INPUT_FILTER_SYNC0_Msk     (0x1U << CLB_TILE_CLB_INPUT_FILTER_SYNC0_Pos)                                                     /*!< SYNC0 Mask 0x00010000 */
#define CLB_TILE_CLB_INPUT_FILTER_SYNC0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_INPUT_FILTER_SYNC0_Pos) & CLB_TILE_CLB_INPUT_FILTER_SYNC0_Msk)   /*!< SYNC0 Set Value */
#define CLB_TILE_CLB_INPUT_FILTER_SYNC0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_INPUT_FILTER_SYNC0_Msk) >> CLB_TILE_CLB_INPUT_FILTER_SYNC0_Pos)   /*!< SYNC0 Get Value */

#define CLB_TILE_CLB_INPUT_FILTER_FIN7_Pos     (14U)                                                                                           /*!< FIN7 Position 14 */
#define CLB_TILE_CLB_INPUT_FILTER_FIN7_Msk     (0x3U << CLB_TILE_CLB_INPUT_FILTER_FIN7_Pos)                                                    /*!< FIN7 Mask 0x0000C000 */
#define CLB_TILE_CLB_INPUT_FILTER_FIN7_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_INPUT_FILTER_FIN7_Pos) & CLB_TILE_CLB_INPUT_FILTER_FIN7_Msk)   /*!< FIN7 Set Value */
#define CLB_TILE_CLB_INPUT_FILTER_FIN7_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_INPUT_FILTER_FIN7_Msk) >> CLB_TILE_CLB_INPUT_FILTER_FIN7_Pos)   /*!< FIN7 Get Value */

#define CLB_TILE_CLB_INPUT_FILTER_FIN6_Pos     (12U)                                                                                           /*!< FIN6 Position 12 */
#define CLB_TILE_CLB_INPUT_FILTER_FIN6_Msk     (0x3U << CLB_TILE_CLB_INPUT_FILTER_FIN6_Pos)                                                    /*!< FIN6 Mask 0x00003000 */
#define CLB_TILE_CLB_INPUT_FILTER_FIN6_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_INPUT_FILTER_FIN6_Pos) & CLB_TILE_CLB_INPUT_FILTER_FIN6_Msk)   /*!< FIN6 Set Value */
#define CLB_TILE_CLB_INPUT_FILTER_FIN6_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_INPUT_FILTER_FIN6_Msk) >> CLB_TILE_CLB_INPUT_FILTER_FIN6_Pos)   /*!< FIN6 Get Value */

#define CLB_TILE_CLB_INPUT_FILTER_FIN5_Pos     (10U)                                                                                           /*!< FIN5 Position 10 */
#define CLB_TILE_CLB_INPUT_FILTER_FIN5_Msk     (0x3U << CLB_TILE_CLB_INPUT_FILTER_FIN5_Pos)                                                    /*!< FIN5 Mask 0x00000C00 */
#define CLB_TILE_CLB_INPUT_FILTER_FIN5_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_INPUT_FILTER_FIN5_Pos) & CLB_TILE_CLB_INPUT_FILTER_FIN5_Msk)   /*!< FIN5 Set Value */
#define CLB_TILE_CLB_INPUT_FILTER_FIN5_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_INPUT_FILTER_FIN5_Msk) >> CLB_TILE_CLB_INPUT_FILTER_FIN5_Pos)   /*!< FIN5 Get Value */

#define CLB_TILE_CLB_INPUT_FILTER_FIN4_Pos     (8U)                                                                                            /*!< FIN4 Position 8 */
#define CLB_TILE_CLB_INPUT_FILTER_FIN4_Msk     (0x3U << CLB_TILE_CLB_INPUT_FILTER_FIN4_Pos)                                                    /*!< FIN4 Mask 0x00000300 */
#define CLB_TILE_CLB_INPUT_FILTER_FIN4_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_INPUT_FILTER_FIN4_Pos) & CLB_TILE_CLB_INPUT_FILTER_FIN4_Msk)   /*!< FIN4 Set Value */
#define CLB_TILE_CLB_INPUT_FILTER_FIN4_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_INPUT_FILTER_FIN4_Msk) >> CLB_TILE_CLB_INPUT_FILTER_FIN4_Pos)   /*!< FIN4 Get Value */

#define CLB_TILE_CLB_INPUT_FILTER_FIN3_Pos     (6U)                                                                                            /*!< FIN3 Position 6 */
#define CLB_TILE_CLB_INPUT_FILTER_FIN3_Msk     (0x3U << CLB_TILE_CLB_INPUT_FILTER_FIN3_Pos)                                                    /*!< FIN3 Mask 0x000000C0 */
#define CLB_TILE_CLB_INPUT_FILTER_FIN3_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_INPUT_FILTER_FIN3_Pos) & CLB_TILE_CLB_INPUT_FILTER_FIN3_Msk)   /*!< FIN3 Set Value */
#define CLB_TILE_CLB_INPUT_FILTER_FIN3_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_INPUT_FILTER_FIN3_Msk) >> CLB_TILE_CLB_INPUT_FILTER_FIN3_Pos)   /*!< FIN3 Get Value */

#define CLB_TILE_CLB_INPUT_FILTER_FIN2_Pos     (4U)                                                                                            /*!< FIN2 Position 4 */
#define CLB_TILE_CLB_INPUT_FILTER_FIN2_Msk     (0x3U << CLB_TILE_CLB_INPUT_FILTER_FIN2_Pos)                                                    /*!< FIN2 Mask 0x00000030 */
#define CLB_TILE_CLB_INPUT_FILTER_FIN2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_INPUT_FILTER_FIN2_Pos) & CLB_TILE_CLB_INPUT_FILTER_FIN2_Msk)   /*!< FIN2 Set Value */
#define CLB_TILE_CLB_INPUT_FILTER_FIN2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_INPUT_FILTER_FIN2_Msk) >> CLB_TILE_CLB_INPUT_FILTER_FIN2_Pos)   /*!< FIN2 Get Value */

#define CLB_TILE_CLB_INPUT_FILTER_FIN1_Pos     (2U)                                                                                            /*!< FIN1 Position 2 */
#define CLB_TILE_CLB_INPUT_FILTER_FIN1_Msk     (0x3U << CLB_TILE_CLB_INPUT_FILTER_FIN1_Pos)                                                    /*!< FIN1 Mask 0x0000000C */
#define CLB_TILE_CLB_INPUT_FILTER_FIN1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_INPUT_FILTER_FIN1_Pos) & CLB_TILE_CLB_INPUT_FILTER_FIN1_Msk)   /*!< FIN1 Set Value */
#define CLB_TILE_CLB_INPUT_FILTER_FIN1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_INPUT_FILTER_FIN1_Msk) >> CLB_TILE_CLB_INPUT_FILTER_FIN1_Pos)   /*!< FIN1 Get Value */

#define CLB_TILE_CLB_INPUT_FILTER_FIN0_Pos     (0U)                                                                                            /*!< FIN0 Position 0 */
#define CLB_TILE_CLB_INPUT_FILTER_FIN0_Msk     (0x3U << CLB_TILE_CLB_INPUT_FILTER_FIN0_Pos)                                                    /*!< FIN0 Mask 0x00000003 */
#define CLB_TILE_CLB_INPUT_FILTER_FIN0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_INPUT_FILTER_FIN0_Pos) & CLB_TILE_CLB_INPUT_FILTER_FIN0_Msk)   /*!< FIN0 Set Value */
#define CLB_TILE_CLB_INPUT_FILTER_FIN0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_INPUT_FILTER_FIN0_Msk) >> CLB_TILE_CLB_INPUT_FILTER_FIN0_Pos)   /*!< FIN0 Get Value */

/* CLB_IN_MUX_SEL_0 bitfield */
#define CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_7_Pos     (7U)                                                                                                          /*!< SEL_GP_IN_7 Position 7 */
#define CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_7_Msk     (0x1U << CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_7_Pos)                                                           /*!< SEL_GP_IN_7 Mask 0x00000080 */
#define CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_7_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_7_Pos) & CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_7_Msk)   /*!< SEL_GP_IN_7 Set Value */
#define CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_7_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_7_Msk) >> CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_7_Pos)   /*!< SEL_GP_IN_7 Get Value */

#define CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_6_Pos     (6U)                                                                                                          /*!< SEL_GP_IN_6 Position 6 */
#define CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_6_Msk     (0x1U << CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_6_Pos)                                                           /*!< SEL_GP_IN_6 Mask 0x00000040 */
#define CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_6_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_6_Pos) & CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_6_Msk)   /*!< SEL_GP_IN_6 Set Value */
#define CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_6_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_6_Msk) >> CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_6_Pos)   /*!< SEL_GP_IN_6 Get Value */

#define CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_5_Pos     (5U)                                                                                                          /*!< SEL_GP_IN_5 Position 5 */
#define CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_5_Msk     (0x1U << CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_5_Pos)                                                           /*!< SEL_GP_IN_5 Mask 0x00000020 */
#define CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_5_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_5_Pos) & CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_5_Msk)   /*!< SEL_GP_IN_5 Set Value */
#define CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_5_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_5_Msk) >> CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_5_Pos)   /*!< SEL_GP_IN_5 Get Value */

#define CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_4_Pos     (4U)                                                                                                          /*!< SEL_GP_IN_4 Position 4 */
#define CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_4_Msk     (0x1U << CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_4_Pos)                                                           /*!< SEL_GP_IN_4 Mask 0x00000010 */
#define CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_4_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_4_Pos) & CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_4_Msk)   /*!< SEL_GP_IN_4 Set Value */
#define CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_4_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_4_Msk) >> CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_4_Pos)   /*!< SEL_GP_IN_4 Get Value */

#define CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_3_Pos     (3U)                                                                                                          /*!< SEL_GP_IN_3 Position 3 */
#define CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_3_Msk     (0x1U << CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_3_Pos)                                                           /*!< SEL_GP_IN_3 Mask 0x00000008 */
#define CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_3_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_3_Pos) & CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_3_Msk)   /*!< SEL_GP_IN_3 Set Value */
#define CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_3_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_3_Msk) >> CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_3_Pos)   /*!< SEL_GP_IN_3 Get Value */

#define CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_2_Pos     (2U)                                                                                                          /*!< SEL_GP_IN_2 Position 2 */
#define CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_2_Msk     (0x1U << CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_2_Pos)                                                           /*!< SEL_GP_IN_2 Mask 0x00000004 */
#define CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_2_Pos) & CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_2_Msk)   /*!< SEL_GP_IN_2 Set Value */
#define CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_2_Msk) >> CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_2_Pos)   /*!< SEL_GP_IN_2 Get Value */

#define CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_1_Pos     (1U)                                                                                                          /*!< SEL_GP_IN_1 Position 1 */
#define CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_1_Msk     (0x1U << CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_1_Pos)                                                           /*!< SEL_GP_IN_1 Mask 0x00000002 */
#define CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_1_Pos) & CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_1_Msk)   /*!< SEL_GP_IN_1 Set Value */
#define CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_1_Msk) >> CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_1_Pos)   /*!< SEL_GP_IN_1 Get Value */

#define CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_0_Pos     (0U)                                                                                                          /*!< SEL_GP_IN_0 Position 0 */
#define CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_0_Msk     (0x1U << CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_0_Pos)                                                           /*!< SEL_GP_IN_0 Mask 0x00000001 */
#define CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_0_Pos) & CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_0_Msk)   /*!< SEL_GP_IN_0 Set Value */
#define CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_0_Msk) >> CLB_TILE_CLB_IN_MUX_SEL_0_SEL_GP_IN_0_Pos)   /*!< SEL_GP_IN_0 Get Value */

/* CLB_LCL_MUX_SEL_1 bitfield */
#define CLB_TILE_CLB_LCL_MUX_SEL_1_MISC_INPUT_SEL_3_Pos     (31U)                                                                                                                     /*!< MISC_INPUT_SEL_3 Position 31 */
#define CLB_TILE_CLB_LCL_MUX_SEL_1_MISC_INPUT_SEL_3_Msk     (0x1U << CLB_TILE_CLB_LCL_MUX_SEL_1_MISC_INPUT_SEL_3_Pos)                                                                 /*!< MISC_INPUT_SEL_3 Mask 0x80000000 */
#define CLB_TILE_CLB_LCL_MUX_SEL_1_MISC_INPUT_SEL_3_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_LCL_MUX_SEL_1_MISC_INPUT_SEL_3_Pos) & CLB_TILE_CLB_LCL_MUX_SEL_1_MISC_INPUT_SEL_3_Msk)   /*!< MISC_INPUT_SEL_3 Set Value */
#define CLB_TILE_CLB_LCL_MUX_SEL_1_MISC_INPUT_SEL_3_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_LCL_MUX_SEL_1_MISC_INPUT_SEL_3_Msk) >> CLB_TILE_CLB_LCL_MUX_SEL_1_MISC_INPUT_SEL_3_Pos)   /*!< MISC_INPUT_SEL_3 Get Value */

#define CLB_TILE_CLB_LCL_MUX_SEL_1_MISC_INPUT_SEL_2_Pos     (30U)                                                                                                                     /*!< MISC_INPUT_SEL_2 Position 30 */
#define CLB_TILE_CLB_LCL_MUX_SEL_1_MISC_INPUT_SEL_2_Msk     (0x1U << CLB_TILE_CLB_LCL_MUX_SEL_1_MISC_INPUT_SEL_2_Pos)                                                                 /*!< MISC_INPUT_SEL_2 Mask 0x40000000 */
#define CLB_TILE_CLB_LCL_MUX_SEL_1_MISC_INPUT_SEL_2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_LCL_MUX_SEL_1_MISC_INPUT_SEL_2_Pos) & CLB_TILE_CLB_LCL_MUX_SEL_1_MISC_INPUT_SEL_2_Msk)   /*!< MISC_INPUT_SEL_2 Set Value */
#define CLB_TILE_CLB_LCL_MUX_SEL_1_MISC_INPUT_SEL_2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_LCL_MUX_SEL_1_MISC_INPUT_SEL_2_Msk) >> CLB_TILE_CLB_LCL_MUX_SEL_1_MISC_INPUT_SEL_2_Pos)   /*!< MISC_INPUT_SEL_2 Get Value */

#define CLB_TILE_CLB_LCL_MUX_SEL_1_MISC_INPUT_SEL_1_Pos     (29U)                                                                                                                     /*!< MISC_INPUT_SEL_1 Position 29 */
#define CLB_TILE_CLB_LCL_MUX_SEL_1_MISC_INPUT_SEL_1_Msk     (0x1U << CLB_TILE_CLB_LCL_MUX_SEL_1_MISC_INPUT_SEL_1_Pos)                                                                 /*!< MISC_INPUT_SEL_1 Mask 0x20000000 */
#define CLB_TILE_CLB_LCL_MUX_SEL_1_MISC_INPUT_SEL_1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_LCL_MUX_SEL_1_MISC_INPUT_SEL_1_Pos) & CLB_TILE_CLB_LCL_MUX_SEL_1_MISC_INPUT_SEL_1_Msk)   /*!< MISC_INPUT_SEL_1 Set Value */
#define CLB_TILE_CLB_LCL_MUX_SEL_1_MISC_INPUT_SEL_1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_LCL_MUX_SEL_1_MISC_INPUT_SEL_1_Msk) >> CLB_TILE_CLB_LCL_MUX_SEL_1_MISC_INPUT_SEL_1_Pos)   /*!< MISC_INPUT_SEL_1 Get Value */

#define CLB_TILE_CLB_LCL_MUX_SEL_1_MISC_INPUT_SEL_0_Pos     (28U)                                                                                                                     /*!< MISC_INPUT_SEL_0 Position 28 */
#define CLB_TILE_CLB_LCL_MUX_SEL_1_MISC_INPUT_SEL_0_Msk     (0x1U << CLB_TILE_CLB_LCL_MUX_SEL_1_MISC_INPUT_SEL_0_Pos)                                                                 /*!< MISC_INPUT_SEL_0 Mask 0x10000000 */
#define CLB_TILE_CLB_LCL_MUX_SEL_1_MISC_INPUT_SEL_0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_LCL_MUX_SEL_1_MISC_INPUT_SEL_0_Pos) & CLB_TILE_CLB_LCL_MUX_SEL_1_MISC_INPUT_SEL_0_Msk)   /*!< MISC_INPUT_SEL_0 Set Value */
#define CLB_TILE_CLB_LCL_MUX_SEL_1_MISC_INPUT_SEL_0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_LCL_MUX_SEL_1_MISC_INPUT_SEL_0_Msk) >> CLB_TILE_CLB_LCL_MUX_SEL_1_MISC_INPUT_SEL_0_Pos)   /*!< MISC_INPUT_SEL_0 Get Value */

#define CLB_TILE_CLB_LCL_MUX_SEL_1_LCL_MUX_SEL_IN_3_Pos     (15U)                                                                                                                     /*!< LCL_MUX_SEL_IN_3 Position 15 */
#define CLB_TILE_CLB_LCL_MUX_SEL_1_LCL_MUX_SEL_IN_3_Msk     (0x1fU << CLB_TILE_CLB_LCL_MUX_SEL_1_LCL_MUX_SEL_IN_3_Pos)                                                                /*!< LCL_MUX_SEL_IN_3 Mask 0x000F8000 */
#define CLB_TILE_CLB_LCL_MUX_SEL_1_LCL_MUX_SEL_IN_3_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_LCL_MUX_SEL_1_LCL_MUX_SEL_IN_3_Pos) & CLB_TILE_CLB_LCL_MUX_SEL_1_LCL_MUX_SEL_IN_3_Msk)   /*!< LCL_MUX_SEL_IN_3 Set Value */
#define CLB_TILE_CLB_LCL_MUX_SEL_1_LCL_MUX_SEL_IN_3_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_LCL_MUX_SEL_1_LCL_MUX_SEL_IN_3_Msk) >> CLB_TILE_CLB_LCL_MUX_SEL_1_LCL_MUX_SEL_IN_3_Pos)   /*!< LCL_MUX_SEL_IN_3 Get Value */

#define CLB_TILE_CLB_LCL_MUX_SEL_1_LCL_MUX_SEL_IN_2_Pos     (10U)                                                                                                                     /*!< LCL_MUX_SEL_IN_2 Position 10 */
#define CLB_TILE_CLB_LCL_MUX_SEL_1_LCL_MUX_SEL_IN_2_Msk     (0x1fU << CLB_TILE_CLB_LCL_MUX_SEL_1_LCL_MUX_SEL_IN_2_Pos)                                                                /*!< LCL_MUX_SEL_IN_2 Mask 0x00007C00 */
#define CLB_TILE_CLB_LCL_MUX_SEL_1_LCL_MUX_SEL_IN_2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_LCL_MUX_SEL_1_LCL_MUX_SEL_IN_2_Pos) & CLB_TILE_CLB_LCL_MUX_SEL_1_LCL_MUX_SEL_IN_2_Msk)   /*!< LCL_MUX_SEL_IN_2 Set Value */
#define CLB_TILE_CLB_LCL_MUX_SEL_1_LCL_MUX_SEL_IN_2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_LCL_MUX_SEL_1_LCL_MUX_SEL_IN_2_Msk) >> CLB_TILE_CLB_LCL_MUX_SEL_1_LCL_MUX_SEL_IN_2_Pos)   /*!< LCL_MUX_SEL_IN_2 Get Value */

#define CLB_TILE_CLB_LCL_MUX_SEL_1_LCL_MUX_SEL_IN_1_Pos     (5U)                                                                                                                      /*!< LCL_MUX_SEL_IN_1 Position 5 */
#define CLB_TILE_CLB_LCL_MUX_SEL_1_LCL_MUX_SEL_IN_1_Msk     (0x1fU << CLB_TILE_CLB_LCL_MUX_SEL_1_LCL_MUX_SEL_IN_1_Pos)                                                                /*!< LCL_MUX_SEL_IN_1 Mask 0x000003E0 */
#define CLB_TILE_CLB_LCL_MUX_SEL_1_LCL_MUX_SEL_IN_1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_LCL_MUX_SEL_1_LCL_MUX_SEL_IN_1_Pos) & CLB_TILE_CLB_LCL_MUX_SEL_1_LCL_MUX_SEL_IN_1_Msk)   /*!< LCL_MUX_SEL_IN_1 Set Value */
#define CLB_TILE_CLB_LCL_MUX_SEL_1_LCL_MUX_SEL_IN_1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_LCL_MUX_SEL_1_LCL_MUX_SEL_IN_1_Msk) >> CLB_TILE_CLB_LCL_MUX_SEL_1_LCL_MUX_SEL_IN_1_Pos)   /*!< LCL_MUX_SEL_IN_1 Get Value */

#define CLB_TILE_CLB_LCL_MUX_SEL_1_LCL_MUX_SEL_IN_0_Pos     (0U)                                                                                                                      /*!< LCL_MUX_SEL_IN_0 Position 0 */
#define CLB_TILE_CLB_LCL_MUX_SEL_1_LCL_MUX_SEL_IN_0_Msk     (0x1fU << CLB_TILE_CLB_LCL_MUX_SEL_1_LCL_MUX_SEL_IN_0_Pos)                                                                /*!< LCL_MUX_SEL_IN_0 Mask 0x0000001F */
#define CLB_TILE_CLB_LCL_MUX_SEL_1_LCL_MUX_SEL_IN_0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_LCL_MUX_SEL_1_LCL_MUX_SEL_IN_0_Pos) & CLB_TILE_CLB_LCL_MUX_SEL_1_LCL_MUX_SEL_IN_0_Msk)   /*!< LCL_MUX_SEL_IN_0 Set Value */
#define CLB_TILE_CLB_LCL_MUX_SEL_1_LCL_MUX_SEL_IN_0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_LCL_MUX_SEL_1_LCL_MUX_SEL_IN_0_Msk) >> CLB_TILE_CLB_LCL_MUX_SEL_1_LCL_MUX_SEL_IN_0_Pos)   /*!< LCL_MUX_SEL_IN_0 Get Value */

/* CLB_LCL_MUX_SEL_2 bitfield */
#define CLB_TILE_CLB_LCL_MUX_SEL_2_MISC_INPUT_SEL_7_Pos     (31U)                                                                                                                     /*!< MISC_INPUT_SEL_7 Position 31 */
#define CLB_TILE_CLB_LCL_MUX_SEL_2_MISC_INPUT_SEL_7_Msk     (0x1U << CLB_TILE_CLB_LCL_MUX_SEL_2_MISC_INPUT_SEL_7_Pos)                                                                 /*!< MISC_INPUT_SEL_7 Mask 0x80000000 */
#define CLB_TILE_CLB_LCL_MUX_SEL_2_MISC_INPUT_SEL_7_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_LCL_MUX_SEL_2_MISC_INPUT_SEL_7_Pos) & CLB_TILE_CLB_LCL_MUX_SEL_2_MISC_INPUT_SEL_7_Msk)   /*!< MISC_INPUT_SEL_7 Set Value */
#define CLB_TILE_CLB_LCL_MUX_SEL_2_MISC_INPUT_SEL_7_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_LCL_MUX_SEL_2_MISC_INPUT_SEL_7_Msk) >> CLB_TILE_CLB_LCL_MUX_SEL_2_MISC_INPUT_SEL_7_Pos)   /*!< MISC_INPUT_SEL_7 Get Value */

#define CLB_TILE_CLB_LCL_MUX_SEL_2_MISC_INPUT_SEL_6_Pos     (30U)                                                                                                                     /*!< MISC_INPUT_SEL_6 Position 30 */
#define CLB_TILE_CLB_LCL_MUX_SEL_2_MISC_INPUT_SEL_6_Msk     (0x1U << CLB_TILE_CLB_LCL_MUX_SEL_2_MISC_INPUT_SEL_6_Pos)                                                                 /*!< MISC_INPUT_SEL_6 Mask 0x40000000 */
#define CLB_TILE_CLB_LCL_MUX_SEL_2_MISC_INPUT_SEL_6_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_LCL_MUX_SEL_2_MISC_INPUT_SEL_6_Pos) & CLB_TILE_CLB_LCL_MUX_SEL_2_MISC_INPUT_SEL_6_Msk)   /*!< MISC_INPUT_SEL_6 Set Value */
#define CLB_TILE_CLB_LCL_MUX_SEL_2_MISC_INPUT_SEL_6_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_LCL_MUX_SEL_2_MISC_INPUT_SEL_6_Msk) >> CLB_TILE_CLB_LCL_MUX_SEL_2_MISC_INPUT_SEL_6_Pos)   /*!< MISC_INPUT_SEL_6 Get Value */

#define CLB_TILE_CLB_LCL_MUX_SEL_2_MISC_INPUT_SEL_5_Pos     (29U)                                                                                                                     /*!< MISC_INPUT_SEL_5 Position 29 */
#define CLB_TILE_CLB_LCL_MUX_SEL_2_MISC_INPUT_SEL_5_Msk     (0x1U << CLB_TILE_CLB_LCL_MUX_SEL_2_MISC_INPUT_SEL_5_Pos)                                                                 /*!< MISC_INPUT_SEL_5 Mask 0x20000000 */
#define CLB_TILE_CLB_LCL_MUX_SEL_2_MISC_INPUT_SEL_5_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_LCL_MUX_SEL_2_MISC_INPUT_SEL_5_Pos) & CLB_TILE_CLB_LCL_MUX_SEL_2_MISC_INPUT_SEL_5_Msk)   /*!< MISC_INPUT_SEL_5 Set Value */
#define CLB_TILE_CLB_LCL_MUX_SEL_2_MISC_INPUT_SEL_5_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_LCL_MUX_SEL_2_MISC_INPUT_SEL_5_Msk) >> CLB_TILE_CLB_LCL_MUX_SEL_2_MISC_INPUT_SEL_5_Pos)   /*!< MISC_INPUT_SEL_5 Get Value */

#define CLB_TILE_CLB_LCL_MUX_SEL_2_MISC_INPUT_SEL_4_Pos     (28U)                                                                                                                     /*!< MISC_INPUT_SEL_4 Position 28 */
#define CLB_TILE_CLB_LCL_MUX_SEL_2_MISC_INPUT_SEL_4_Msk     (0x1U << CLB_TILE_CLB_LCL_MUX_SEL_2_MISC_INPUT_SEL_4_Pos)                                                                 /*!< MISC_INPUT_SEL_4 Mask 0x10000000 */
#define CLB_TILE_CLB_LCL_MUX_SEL_2_MISC_INPUT_SEL_4_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_LCL_MUX_SEL_2_MISC_INPUT_SEL_4_Pos) & CLB_TILE_CLB_LCL_MUX_SEL_2_MISC_INPUT_SEL_4_Msk)   /*!< MISC_INPUT_SEL_4 Set Value */
#define CLB_TILE_CLB_LCL_MUX_SEL_2_MISC_INPUT_SEL_4_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_LCL_MUX_SEL_2_MISC_INPUT_SEL_4_Msk) >> CLB_TILE_CLB_LCL_MUX_SEL_2_MISC_INPUT_SEL_4_Pos)   /*!< MISC_INPUT_SEL_4 Get Value */

#define CLB_TILE_CLB_LCL_MUX_SEL_2_LCL_MUX_SEL_IN_7_Pos     (15U)                                                                                                                     /*!< LCL_MUX_SEL_IN_7 Position 15 */
#define CLB_TILE_CLB_LCL_MUX_SEL_2_LCL_MUX_SEL_IN_7_Msk     (0x1fU << CLB_TILE_CLB_LCL_MUX_SEL_2_LCL_MUX_SEL_IN_7_Pos)                                                                /*!< LCL_MUX_SEL_IN_7 Mask 0x000F8000 */
#define CLB_TILE_CLB_LCL_MUX_SEL_2_LCL_MUX_SEL_IN_7_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_LCL_MUX_SEL_2_LCL_MUX_SEL_IN_7_Pos) & CLB_TILE_CLB_LCL_MUX_SEL_2_LCL_MUX_SEL_IN_7_Msk)   /*!< LCL_MUX_SEL_IN_7 Set Value */
#define CLB_TILE_CLB_LCL_MUX_SEL_2_LCL_MUX_SEL_IN_7_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_LCL_MUX_SEL_2_LCL_MUX_SEL_IN_7_Msk) >> CLB_TILE_CLB_LCL_MUX_SEL_2_LCL_MUX_SEL_IN_7_Pos)   /*!< LCL_MUX_SEL_IN_7 Get Value */

#define CLB_TILE_CLB_LCL_MUX_SEL_2_LCL_MUX_SEL_IN_6_Pos     (10U)                                                                                                                     /*!< LCL_MUX_SEL_IN_6 Position 10 */
#define CLB_TILE_CLB_LCL_MUX_SEL_2_LCL_MUX_SEL_IN_6_Msk     (0x1fU << CLB_TILE_CLB_LCL_MUX_SEL_2_LCL_MUX_SEL_IN_6_Pos)                                                                /*!< LCL_MUX_SEL_IN_6 Mask 0x00007C00 */
#define CLB_TILE_CLB_LCL_MUX_SEL_2_LCL_MUX_SEL_IN_6_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_LCL_MUX_SEL_2_LCL_MUX_SEL_IN_6_Pos) & CLB_TILE_CLB_LCL_MUX_SEL_2_LCL_MUX_SEL_IN_6_Msk)   /*!< LCL_MUX_SEL_IN_6 Set Value */
#define CLB_TILE_CLB_LCL_MUX_SEL_2_LCL_MUX_SEL_IN_6_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_LCL_MUX_SEL_2_LCL_MUX_SEL_IN_6_Msk) >> CLB_TILE_CLB_LCL_MUX_SEL_2_LCL_MUX_SEL_IN_6_Pos)   /*!< LCL_MUX_SEL_IN_6 Get Value */

#define CLB_TILE_CLB_LCL_MUX_SEL_2_LCL_MUX_SEL_IN_5_Pos     (5U)                                                                                                                      /*!< LCL_MUX_SEL_IN_5 Position 5 */
#define CLB_TILE_CLB_LCL_MUX_SEL_2_LCL_MUX_SEL_IN_5_Msk     (0x1fU << CLB_TILE_CLB_LCL_MUX_SEL_2_LCL_MUX_SEL_IN_5_Pos)                                                                /*!< LCL_MUX_SEL_IN_5 Mask 0x000003E0 */
#define CLB_TILE_CLB_LCL_MUX_SEL_2_LCL_MUX_SEL_IN_5_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_LCL_MUX_SEL_2_LCL_MUX_SEL_IN_5_Pos) & CLB_TILE_CLB_LCL_MUX_SEL_2_LCL_MUX_SEL_IN_5_Msk)   /*!< LCL_MUX_SEL_IN_5 Set Value */
#define CLB_TILE_CLB_LCL_MUX_SEL_2_LCL_MUX_SEL_IN_5_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_LCL_MUX_SEL_2_LCL_MUX_SEL_IN_5_Msk) >> CLB_TILE_CLB_LCL_MUX_SEL_2_LCL_MUX_SEL_IN_5_Pos)   /*!< LCL_MUX_SEL_IN_5 Get Value */

#define CLB_TILE_CLB_LCL_MUX_SEL_2_LCL_MUX_SEL_IN_4_Pos     (0U)                                                                                                                      /*!< LCL_MUX_SEL_IN_4 Position 0 */
#define CLB_TILE_CLB_LCL_MUX_SEL_2_LCL_MUX_SEL_IN_4_Msk     (0x1fU << CLB_TILE_CLB_LCL_MUX_SEL_2_LCL_MUX_SEL_IN_4_Pos)                                                                /*!< LCL_MUX_SEL_IN_4 Mask 0x0000001F */
#define CLB_TILE_CLB_LCL_MUX_SEL_2_LCL_MUX_SEL_IN_4_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_LCL_MUX_SEL_2_LCL_MUX_SEL_IN_4_Pos) & CLB_TILE_CLB_LCL_MUX_SEL_2_LCL_MUX_SEL_IN_4_Msk)   /*!< LCL_MUX_SEL_IN_4 Set Value */
#define CLB_TILE_CLB_LCL_MUX_SEL_2_LCL_MUX_SEL_IN_4_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_LCL_MUX_SEL_2_LCL_MUX_SEL_IN_4_Msk) >> CLB_TILE_CLB_LCL_MUX_SEL_2_LCL_MUX_SEL_IN_4_Pos)   /*!< LCL_MUX_SEL_IN_4 Get Value */

/* CLB_BUF_PTR bitfield */
#define CLB_TILE_CLB_BUF_PTR_PUSH_Pos     (16U)                                                                                 /*!< PUSH Position 16 */
#define CLB_TILE_CLB_BUF_PTR_PUSH_Msk     (0xffU << CLB_TILE_CLB_BUF_PTR_PUSH_Pos)                                              /*!< PUSH Mask 0x00FF0000 */
#define CLB_TILE_CLB_BUF_PTR_PUSH_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_BUF_PTR_PUSH_Pos) & CLB_TILE_CLB_BUF_PTR_PUSH_Msk)   /*!< PUSH Set Value */
#define CLB_TILE_CLB_BUF_PTR_PUSH_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_BUF_PTR_PUSH_Msk) >> CLB_TILE_CLB_BUF_PTR_PUSH_Pos)   /*!< PUSH Get Value */

#define CLB_TILE_CLB_BUF_PTR_PULL_Pos     (0U)                                                                                  /*!< PULL Position 0 */
#define CLB_TILE_CLB_BUF_PTR_PULL_Msk     (0xffU << CLB_TILE_CLB_BUF_PTR_PULL_Pos)                                              /*!< PULL Mask 0x000000FF */
#define CLB_TILE_CLB_BUF_PTR_PULL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_BUF_PTR_PULL_Pos) & CLB_TILE_CLB_BUF_PTR_PULL_Msk)   /*!< PULL Set Value */
#define CLB_TILE_CLB_BUF_PTR_PULL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_BUF_PTR_PULL_Msk) >> CLB_TILE_CLB_BUF_PTR_PULL_Pos)   /*!< PULL Get Value */

/* CLB_GP_REG bitfield */
#define CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_7_Pos     (31U)                                                                                                 /*!< SW_RLS_CTRL_7 Position 31 */
#define CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_7_Msk     (0x1U << CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_7_Pos)                                                       /*!< SW_RLS_CTRL_7 Mask 0x80000000 */
#define CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_7_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_7_Pos) & CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_7_Msk)   /*!< SW_RLS_CTRL_7 Set Value */
#define CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_7_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_7_Msk) >> CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_7_Pos)   /*!< SW_RLS_CTRL_7 Get Value */

#define CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_6_Pos     (30U)                                                                                                 /*!< SW_RLS_CTRL_6 Position 30 */
#define CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_6_Msk     (0x1U << CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_6_Pos)                                                       /*!< SW_RLS_CTRL_6 Mask 0x40000000 */
#define CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_6_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_6_Pos) & CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_6_Msk)   /*!< SW_RLS_CTRL_6 Set Value */
#define CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_6_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_6_Msk) >> CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_6_Pos)   /*!< SW_RLS_CTRL_6 Get Value */

#define CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_5_Pos     (29U)                                                                                                 /*!< SW_RLS_CTRL_5 Position 29 */
#define CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_5_Msk     (0x1U << CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_5_Pos)                                                       /*!< SW_RLS_CTRL_5 Mask 0x20000000 */
#define CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_5_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_5_Pos) & CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_5_Msk)   /*!< SW_RLS_CTRL_5 Set Value */
#define CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_5_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_5_Msk) >> CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_5_Pos)   /*!< SW_RLS_CTRL_5 Get Value */

#define CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_4_Pos     (28U)                                                                                                 /*!< SW_RLS_CTRL_4 Position 28 */
#define CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_4_Msk     (0x1U << CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_4_Pos)                                                       /*!< SW_RLS_CTRL_4 Mask 0x10000000 */
#define CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_4_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_4_Pos) & CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_4_Msk)   /*!< SW_RLS_CTRL_4 Set Value */
#define CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_4_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_4_Msk) >> CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_4_Pos)   /*!< SW_RLS_CTRL_4 Get Value */

#define CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_3_Pos     (27U)                                                                                                 /*!< SW_RLS_CTRL_3 Position 27 */
#define CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_3_Msk     (0x1U << CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_3_Pos)                                                       /*!< SW_RLS_CTRL_3 Mask 0x08000000 */
#define CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_3_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_3_Pos) & CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_3_Msk)   /*!< SW_RLS_CTRL_3 Set Value */
#define CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_3_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_3_Msk) >> CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_3_Pos)   /*!< SW_RLS_CTRL_3 Get Value */

#define CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_2_Pos     (26U)                                                                                                 /*!< SW_RLS_CTRL_2 Position 26 */
#define CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_2_Msk     (0x1U << CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_2_Pos)                                                       /*!< SW_RLS_CTRL_2 Mask 0x04000000 */
#define CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_2_Pos) & CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_2_Msk)   /*!< SW_RLS_CTRL_2 Set Value */
#define CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_2_Msk) >> CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_2_Pos)   /*!< SW_RLS_CTRL_2 Get Value */

#define CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_1_Pos     (25U)                                                                                                 /*!< SW_RLS_CTRL_1 Position 25 */
#define CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_1_Msk     (0x1U << CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_1_Pos)                                                       /*!< SW_RLS_CTRL_1 Mask 0x02000000 */
#define CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_1_Pos) & CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_1_Msk)   /*!< SW_RLS_CTRL_1 Set Value */
#define CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_1_Msk) >> CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_1_Pos)   /*!< SW_RLS_CTRL_1 Get Value */

#define CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_0_Pos     (24U)                                                                                                 /*!< SW_RLS_CTRL_0 Position 24 */
#define CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_0_Msk     (0x1U << CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_0_Pos)                                                       /*!< SW_RLS_CTRL_0 Mask 0x01000000 */
#define CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_0_Pos) & CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_0_Msk)   /*!< SW_RLS_CTRL_0 Set Value */
#define CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_0_Msk) >> CLB_TILE_CLB_GP_REG_SW_RLS_CTRL_0_Pos)   /*!< SW_RLS_CTRL_0 Get Value */

#define CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_7_Pos     (23U)                                                                                                       /*!< SW_GATING_CTRL_7 Position 23 */
#define CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_7_Msk     (0x1U << CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_7_Pos)                                                          /*!< SW_GATING_CTRL_7 Mask 0x00800000 */
#define CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_7_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_7_Pos) & CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_7_Msk)   /*!< SW_GATING_CTRL_7 Set Value */
#define CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_7_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_7_Msk) >> CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_7_Pos)   /*!< SW_GATING_CTRL_7 Get Value */

#define CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_6_Pos     (22U)                                                                                                       /*!< SW_GATING_CTRL_6 Position 22 */
#define CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_6_Msk     (0x1U << CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_6_Pos)                                                          /*!< SW_GATING_CTRL_6 Mask 0x00400000 */
#define CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_6_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_6_Pos) & CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_6_Msk)   /*!< SW_GATING_CTRL_6 Set Value */
#define CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_6_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_6_Msk) >> CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_6_Pos)   /*!< SW_GATING_CTRL_6 Get Value */

#define CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_5_Pos     (21U)                                                                                                       /*!< SW_GATING_CTRL_5 Position 21 */
#define CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_5_Msk     (0x1U << CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_5_Pos)                                                          /*!< SW_GATING_CTRL_5 Mask 0x00200000 */
#define CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_5_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_5_Pos) & CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_5_Msk)   /*!< SW_GATING_CTRL_5 Set Value */
#define CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_5_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_5_Msk) >> CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_5_Pos)   /*!< SW_GATING_CTRL_5 Get Value */

#define CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_4_Pos     (20U)                                                                                                       /*!< SW_GATING_CTRL_4 Position 20 */
#define CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_4_Msk     (0x1U << CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_4_Pos)                                                          /*!< SW_GATING_CTRL_4 Mask 0x00100000 */
#define CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_4_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_4_Pos) & CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_4_Msk)   /*!< SW_GATING_CTRL_4 Set Value */
#define CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_4_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_4_Msk) >> CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_4_Pos)   /*!< SW_GATING_CTRL_4 Get Value */

#define CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_3_Pos     (19U)                                                                                                       /*!< SW_GATING_CTRL_3 Position 19 */
#define CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_3_Msk     (0x1U << CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_3_Pos)                                                          /*!< SW_GATING_CTRL_3 Mask 0x00080000 */
#define CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_3_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_3_Pos) & CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_3_Msk)   /*!< SW_GATING_CTRL_3 Set Value */
#define CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_3_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_3_Msk) >> CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_3_Pos)   /*!< SW_GATING_CTRL_3 Get Value */

#define CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_2_Pos     (18U)                                                                                                       /*!< SW_GATING_CTRL_2 Position 18 */
#define CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_2_Msk     (0x1U << CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_2_Pos)                                                          /*!< SW_GATING_CTRL_2 Mask 0x00040000 */
#define CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_2_Pos) & CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_2_Msk)   /*!< SW_GATING_CTRL_2 Set Value */
#define CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_2_Msk) >> CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_2_Pos)   /*!< SW_GATING_CTRL_2 Get Value */

#define CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_1_Pos     (17U)                                                                                                       /*!< SW_GATING_CTRL_1 Position 17 */
#define CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_1_Msk     (0x1U << CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_1_Pos)                                                          /*!< SW_GATING_CTRL_1 Mask 0x00020000 */
#define CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_1_Pos) & CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_1_Msk)   /*!< SW_GATING_CTRL_1 Set Value */
#define CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_1_Msk) >> CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_1_Pos)   /*!< SW_GATING_CTRL_1 Get Value */

#define CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_0_Pos     (16U)                                                                                                       /*!< SW_GATING_CTRL_0 Position 16 */
#define CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_0_Msk     (0x1U << CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_0_Pos)                                                          /*!< SW_GATING_CTRL_0 Mask 0x00010000 */
#define CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_0_Pos) & CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_0_Msk)   /*!< SW_GATING_CTRL_0 Set Value */
#define CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_0_Msk) >> CLB_TILE_CLB_GP_REG_SW_GATING_CTRL_0_Pos)   /*!< SW_GATING_CTRL_0 Get Value */

#define CLB_TILE_CLB_GP_REG_REG_INPUT_Pos     (0U)                                                                                          /*!< REG_INPUT Position 0 */
#define CLB_TILE_CLB_GP_REG_REG_INPUT_Msk     (0xffU << CLB_TILE_CLB_GP_REG_REG_INPUT_Pos)                                                  /*!< REG_INPUT Mask 0x000000FF */
#define CLB_TILE_CLB_GP_REG_REG_INPUT_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_GP_REG_REG_INPUT_Pos) & CLB_TILE_CLB_GP_REG_REG_INPUT_Msk)   /*!< REG_INPUT Set Value */
#define CLB_TILE_CLB_GP_REG_REG_INPUT_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_GP_REG_REG_INPUT_Msk) >> CLB_TILE_CLB_GP_REG_REG_INPUT_Pos)   /*!< REG_INPUT Get Value */

/* CLB_OUT_EN bitfield */
#define CLB_TILE_CLB_OUT_EN_OUT0_Pos     (0U)                                                                                /*!< OUT0 Position 0 */
#define CLB_TILE_CLB_OUT_EN_OUT0_Msk     (0xffffffffU << CLB_TILE_CLB_OUT_EN_OUT0_Pos)                                       /*!< OUT0 Mask 0xFFFFFFFF */
#define CLB_TILE_CLB_OUT_EN_OUT0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_OUT_EN_OUT0_Pos) & CLB_TILE_CLB_OUT_EN_OUT0_Msk)   /*!< OUT0 Set Value */
#define CLB_TILE_CLB_OUT_EN_OUT0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_OUT_EN_OUT0_Msk) >> CLB_TILE_CLB_OUT_EN_OUT0_Pos)   /*!< OUT0 Get Value */

/* CLB_GLBL_MUX_SEL_1 bitfield */
#define CLB_TILE_CLB_GLBL_MUX_SEL_1_GLBL_MUX_SEL_IN_3_Pos     (21U)                                                                                                                         /*!< GLBL_MUX_SEL_IN_3 Position 21 */
#define CLB_TILE_CLB_GLBL_MUX_SEL_1_GLBL_MUX_SEL_IN_3_Msk     (0x7fU << CLB_TILE_CLB_GLBL_MUX_SEL_1_GLBL_MUX_SEL_IN_3_Pos)                                                                  /*!< GLBL_MUX_SEL_IN_3 Mask 0x0FE00000 */
#define CLB_TILE_CLB_GLBL_MUX_SEL_1_GLBL_MUX_SEL_IN_3_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_GLBL_MUX_SEL_1_GLBL_MUX_SEL_IN_3_Pos) & CLB_TILE_CLB_GLBL_MUX_SEL_1_GLBL_MUX_SEL_IN_3_Msk)   /*!< GLBL_MUX_SEL_IN_3 Set Value */
#define CLB_TILE_CLB_GLBL_MUX_SEL_1_GLBL_MUX_SEL_IN_3_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_GLBL_MUX_SEL_1_GLBL_MUX_SEL_IN_3_Msk) >> CLB_TILE_CLB_GLBL_MUX_SEL_1_GLBL_MUX_SEL_IN_3_Pos)   /*!< GLBL_MUX_SEL_IN_3 Get Value */

#define CLB_TILE_CLB_GLBL_MUX_SEL_1_GLBL_MUX_SEL_IN_2_Pos     (14U)                                                                                                                         /*!< GLBL_MUX_SEL_IN_2 Position 14 */
#define CLB_TILE_CLB_GLBL_MUX_SEL_1_GLBL_MUX_SEL_IN_2_Msk     (0x7fU << CLB_TILE_CLB_GLBL_MUX_SEL_1_GLBL_MUX_SEL_IN_2_Pos)                                                                  /*!< GLBL_MUX_SEL_IN_2 Mask 0x001FC000 */
#define CLB_TILE_CLB_GLBL_MUX_SEL_1_GLBL_MUX_SEL_IN_2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_GLBL_MUX_SEL_1_GLBL_MUX_SEL_IN_2_Pos) & CLB_TILE_CLB_GLBL_MUX_SEL_1_GLBL_MUX_SEL_IN_2_Msk)   /*!< GLBL_MUX_SEL_IN_2 Set Value */
#define CLB_TILE_CLB_GLBL_MUX_SEL_1_GLBL_MUX_SEL_IN_2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_GLBL_MUX_SEL_1_GLBL_MUX_SEL_IN_2_Msk) >> CLB_TILE_CLB_GLBL_MUX_SEL_1_GLBL_MUX_SEL_IN_2_Pos)   /*!< GLBL_MUX_SEL_IN_2 Get Value */

#define CLB_TILE_CLB_GLBL_MUX_SEL_1_GLBL_MUX_SEL_IN_1_Pos     (7U)                                                                                                                          /*!< GLBL_MUX_SEL_IN_1 Position 7 */
#define CLB_TILE_CLB_GLBL_MUX_SEL_1_GLBL_MUX_SEL_IN_1_Msk     (0x7fU << CLB_TILE_CLB_GLBL_MUX_SEL_1_GLBL_MUX_SEL_IN_1_Pos)                                                                  /*!< GLBL_MUX_SEL_IN_1 Mask 0x00003F80 */
#define CLB_TILE_CLB_GLBL_MUX_SEL_1_GLBL_MUX_SEL_IN_1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_GLBL_MUX_SEL_1_GLBL_MUX_SEL_IN_1_Pos) & CLB_TILE_CLB_GLBL_MUX_SEL_1_GLBL_MUX_SEL_IN_1_Msk)   /*!< GLBL_MUX_SEL_IN_1 Set Value */
#define CLB_TILE_CLB_GLBL_MUX_SEL_1_GLBL_MUX_SEL_IN_1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_GLBL_MUX_SEL_1_GLBL_MUX_SEL_IN_1_Msk) >> CLB_TILE_CLB_GLBL_MUX_SEL_1_GLBL_MUX_SEL_IN_1_Pos)   /*!< GLBL_MUX_SEL_IN_1 Get Value */

#define CLB_TILE_CLB_GLBL_MUX_SEL_1_GLBL_MUX_SEL_IN_0_Pos     (0U)                                                                                                                          /*!< GLBL_MUX_SEL_IN_0 Position 0 */
#define CLB_TILE_CLB_GLBL_MUX_SEL_1_GLBL_MUX_SEL_IN_0_Msk     (0x7fU << CLB_TILE_CLB_GLBL_MUX_SEL_1_GLBL_MUX_SEL_IN_0_Pos)                                                                  /*!< GLBL_MUX_SEL_IN_0 Mask 0x0000007F */
#define CLB_TILE_CLB_GLBL_MUX_SEL_1_GLBL_MUX_SEL_IN_0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_GLBL_MUX_SEL_1_GLBL_MUX_SEL_IN_0_Pos) & CLB_TILE_CLB_GLBL_MUX_SEL_1_GLBL_MUX_SEL_IN_0_Msk)   /*!< GLBL_MUX_SEL_IN_0 Set Value */
#define CLB_TILE_CLB_GLBL_MUX_SEL_1_GLBL_MUX_SEL_IN_0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_GLBL_MUX_SEL_1_GLBL_MUX_SEL_IN_0_Msk) >> CLB_TILE_CLB_GLBL_MUX_SEL_1_GLBL_MUX_SEL_IN_0_Pos)   /*!< GLBL_MUX_SEL_IN_0 Get Value */

/* CLB_GLBL_MUX_SEL_2 bitfield */
#define CLB_TILE_CLB_GLBL_MUX_SEL_2_GLBL_MUX_SEL_IN_7_Pos     (21U)                                                                                                                         /*!< GLBL_MUX_SEL_IN_7 Position 21 */
#define CLB_TILE_CLB_GLBL_MUX_SEL_2_GLBL_MUX_SEL_IN_7_Msk     (0x7fU << CLB_TILE_CLB_GLBL_MUX_SEL_2_GLBL_MUX_SEL_IN_7_Pos)                                                                  /*!< GLBL_MUX_SEL_IN_7 Mask 0x0FE00000 */
#define CLB_TILE_CLB_GLBL_MUX_SEL_2_GLBL_MUX_SEL_IN_7_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_GLBL_MUX_SEL_2_GLBL_MUX_SEL_IN_7_Pos) & CLB_TILE_CLB_GLBL_MUX_SEL_2_GLBL_MUX_SEL_IN_7_Msk)   /*!< GLBL_MUX_SEL_IN_7 Set Value */
#define CLB_TILE_CLB_GLBL_MUX_SEL_2_GLBL_MUX_SEL_IN_7_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_GLBL_MUX_SEL_2_GLBL_MUX_SEL_IN_7_Msk) >> CLB_TILE_CLB_GLBL_MUX_SEL_2_GLBL_MUX_SEL_IN_7_Pos)   /*!< GLBL_MUX_SEL_IN_7 Get Value */

#define CLB_TILE_CLB_GLBL_MUX_SEL_2_GLBL_MUX_SEL_IN_6_Pos     (14U)                                                                                                                         /*!< GLBL_MUX_SEL_IN_6 Position 14 */
#define CLB_TILE_CLB_GLBL_MUX_SEL_2_GLBL_MUX_SEL_IN_6_Msk     (0x7fU << CLB_TILE_CLB_GLBL_MUX_SEL_2_GLBL_MUX_SEL_IN_6_Pos)                                                                  /*!< GLBL_MUX_SEL_IN_6 Mask 0x001FC000 */
#define CLB_TILE_CLB_GLBL_MUX_SEL_2_GLBL_MUX_SEL_IN_6_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_GLBL_MUX_SEL_2_GLBL_MUX_SEL_IN_6_Pos) & CLB_TILE_CLB_GLBL_MUX_SEL_2_GLBL_MUX_SEL_IN_6_Msk)   /*!< GLBL_MUX_SEL_IN_6 Set Value */
#define CLB_TILE_CLB_GLBL_MUX_SEL_2_GLBL_MUX_SEL_IN_6_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_GLBL_MUX_SEL_2_GLBL_MUX_SEL_IN_6_Msk) >> CLB_TILE_CLB_GLBL_MUX_SEL_2_GLBL_MUX_SEL_IN_6_Pos)   /*!< GLBL_MUX_SEL_IN_6 Get Value */

#define CLB_TILE_CLB_GLBL_MUX_SEL_2_GLBL_MUX_SEL_IN_5_Pos     (7U)                                                                                                                          /*!< GLBL_MUX_SEL_IN_5 Position 7 */
#define CLB_TILE_CLB_GLBL_MUX_SEL_2_GLBL_MUX_SEL_IN_5_Msk     (0x7fU << CLB_TILE_CLB_GLBL_MUX_SEL_2_GLBL_MUX_SEL_IN_5_Pos)                                                                  /*!< GLBL_MUX_SEL_IN_5 Mask 0x00003F80 */
#define CLB_TILE_CLB_GLBL_MUX_SEL_2_GLBL_MUX_SEL_IN_5_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_GLBL_MUX_SEL_2_GLBL_MUX_SEL_IN_5_Pos) & CLB_TILE_CLB_GLBL_MUX_SEL_2_GLBL_MUX_SEL_IN_5_Msk)   /*!< GLBL_MUX_SEL_IN_5 Set Value */
#define CLB_TILE_CLB_GLBL_MUX_SEL_2_GLBL_MUX_SEL_IN_5_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_GLBL_MUX_SEL_2_GLBL_MUX_SEL_IN_5_Msk) >> CLB_TILE_CLB_GLBL_MUX_SEL_2_GLBL_MUX_SEL_IN_5_Pos)   /*!< GLBL_MUX_SEL_IN_5 Get Value */

#define CLB_TILE_CLB_GLBL_MUX_SEL_2_GLBL_MUX_SEL_IN_4_Pos     (0U)                                                                                                                          /*!< GLBL_MUX_SEL_IN_4 Position 0 */
#define CLB_TILE_CLB_GLBL_MUX_SEL_2_GLBL_MUX_SEL_IN_4_Msk     (0x7fU << CLB_TILE_CLB_GLBL_MUX_SEL_2_GLBL_MUX_SEL_IN_4_Pos)                                                                  /*!< GLBL_MUX_SEL_IN_4 Mask 0x0000007F */
#define CLB_TILE_CLB_GLBL_MUX_SEL_2_GLBL_MUX_SEL_IN_4_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_GLBL_MUX_SEL_2_GLBL_MUX_SEL_IN_4_Pos) & CLB_TILE_CLB_GLBL_MUX_SEL_2_GLBL_MUX_SEL_IN_4_Msk)   /*!< GLBL_MUX_SEL_IN_4 Set Value */
#define CLB_TILE_CLB_GLBL_MUX_SEL_2_GLBL_MUX_SEL_IN_4_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_GLBL_MUX_SEL_2_GLBL_MUX_SEL_IN_4_Msk) >> CLB_TILE_CLB_GLBL_MUX_SEL_2_GLBL_MUX_SEL_IN_4_Pos)   /*!< GLBL_MUX_SEL_IN_4 Get Value */

/* CLB_INTR_TAG_REG bitfield */
#define CLB_TILE_CLB_INTR_TAG_REG_TAG_Pos     (0U)                                                                                          /*!< TAG Position 0 */
#define CLB_TILE_CLB_INTR_TAG_REG_TAG_Msk     (0x3fU << CLB_TILE_CLB_INTR_TAG_REG_TAG_Pos)                                                  /*!< TAG Mask 0x0000003F */
#define CLB_TILE_CLB_INTR_TAG_REG_TAG_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_INTR_TAG_REG_TAG_Pos) & CLB_TILE_CLB_INTR_TAG_REG_TAG_Msk)   /*!< TAG Set Value */
#define CLB_TILE_CLB_INTR_TAG_REG_TAG_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_INTR_TAG_REG_TAG_Msk) >> CLB_TILE_CLB_INTR_TAG_REG_TAG_Pos)   /*!< TAG Get Value */

/* CLB_LOCK bitfield */
#define CLB_TILE_CLB_LOCK_KEY_Pos     (16U)                                                                         /*!< KEY Position 16 */
#define CLB_TILE_CLB_LOCK_KEY_Msk     (0xffffU << CLB_TILE_CLB_LOCK_KEY_Pos)                                        /*!< KEY Mask 0xFFFF0000 */
#define CLB_TILE_CLB_LOCK_KEY_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_LOCK_KEY_Pos) & CLB_TILE_CLB_LOCK_KEY_Msk)   /*!< KEY Set Value */
#define CLB_TILE_CLB_LOCK_KEY_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_LOCK_KEY_Msk) >> CLB_TILE_CLB_LOCK_KEY_Pos)   /*!< KEY Get Value */

#define CLB_TILE_CLB_LOCK_LOCK_Pos     (0U)                                                                            /*!< LOCK Position 0 */
#define CLB_TILE_CLB_LOCK_LOCK_Msk     (0x1U << CLB_TILE_CLB_LOCK_LOCK_Pos)                                            /*!< LOCK Mask 0x00000001 */
#define CLB_TILE_CLB_LOCK_LOCK_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_LOCK_LOCK_Pos) & CLB_TILE_CLB_LOCK_LOCK_Msk)   /*!< LOCK Set Value */
#define CLB_TILE_CLB_LOCK_LOCK_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_LOCK_LOCK_Msk) >> CLB_TILE_CLB_LOCK_LOCK_Pos)   /*!< LOCK Get Value */

/* CLB_HLC_INSTR_READ_PTR bitfield */
#define CLB_TILE_CLB_HLC_INSTR_READ_PTR_READ_PTR_Pos     (0U)                                                                                                                /*!< READ_PTR Position 0 */
#define CLB_TILE_CLB_HLC_INSTR_READ_PTR_READ_PTR_Msk     (0x1fU << CLB_TILE_CLB_HLC_INSTR_READ_PTR_READ_PTR_Pos)                                                             /*!< READ_PTR Mask 0x0000001F */
#define CLB_TILE_CLB_HLC_INSTR_READ_PTR_READ_PTR_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_HLC_INSTR_READ_PTR_READ_PTR_Pos) & CLB_TILE_CLB_HLC_INSTR_READ_PTR_READ_PTR_Msk)   /*!< READ_PTR Set Value */
#define CLB_TILE_CLB_HLC_INSTR_READ_PTR_READ_PTR_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_HLC_INSTR_READ_PTR_READ_PTR_Msk) >> CLB_TILE_CLB_HLC_INSTR_READ_PTR_READ_PTR_Pos)   /*!< READ_PTR Get Value */

/* CLB_HLC_INSTR_VALUE bitfield */
#define CLB_TILE_CLB_HLC_INSTR_VALUE_INSTR_Pos     (0U)                                                                                                    /*!< INSTR Position 0 */
#define CLB_TILE_CLB_HLC_INSTR_VALUE_INSTR_Msk     (0xfffU << CLB_TILE_CLB_HLC_INSTR_VALUE_INSTR_Pos)                                                      /*!< INSTR Mask 0x00000FFF */
#define CLB_TILE_CLB_HLC_INSTR_VALUE_INSTR_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_HLC_INSTR_VALUE_INSTR_Pos) & CLB_TILE_CLB_HLC_INSTR_VALUE_INSTR_Msk)   /*!< INSTR Set Value */
#define CLB_TILE_CLB_HLC_INSTR_VALUE_INSTR_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_HLC_INSTR_VALUE_INSTR_Msk) >> CLB_TILE_CLB_HLC_INSTR_VALUE_INSTR_Pos)   /*!< INSTR Get Value */

/* CLB_DBG_OUT_2 bitfield */
#define CLB_TILE_CLB_DBG_OUT_2_IN_Pos     (8U)                                                                                  /*!< IN Position 8 */
#define CLB_TILE_CLB_DBG_OUT_2_IN_Msk     (0xffU << CLB_TILE_CLB_DBG_OUT_2_IN_Pos)                                              /*!< IN Mask 0x0000FF00 */
#define CLB_TILE_CLB_DBG_OUT_2_IN_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_DBG_OUT_2_IN_Pos) & CLB_TILE_CLB_DBG_OUT_2_IN_Msk)   /*!< IN Set Value */
#define CLB_TILE_CLB_DBG_OUT_2_IN_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_DBG_OUT_2_IN_Msk) >> CLB_TILE_CLB_DBG_OUT_2_IN_Pos)   /*!< IN Get Value */

#define CLB_TILE_CLB_DBG_OUT_2_OUT_Pos     (0U)                                                                                    /*!< OUT Position 0 */
#define CLB_TILE_CLB_DBG_OUT_2_OUT_Msk     (0xffU << CLB_TILE_CLB_DBG_OUT_2_OUT_Pos)                                               /*!< OUT Mask 0x000000FF */
#define CLB_TILE_CLB_DBG_OUT_2_OUT_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_DBG_OUT_2_OUT_Pos) & CLB_TILE_CLB_DBG_OUT_2_OUT_Msk)   /*!< OUT Set Value */
#define CLB_TILE_CLB_DBG_OUT_2_OUT_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_DBG_OUT_2_OUT_Msk) >> CLB_TILE_CLB_DBG_OUT_2_OUT_Pos)   /*!< OUT Get Value */

/* CLB_DBG_R0 bitfield */
#define CLB_TILE_CLB_DBG_R0_DBG_Pos     (0U)                                                                              /*!< DBG Position 0 */
#define CLB_TILE_CLB_DBG_R0_DBG_Msk     (0xffffffffU << CLB_TILE_CLB_DBG_R0_DBG_Pos)                                      /*!< DBG Mask 0xFFFFFFFF */
#define CLB_TILE_CLB_DBG_R0_DBG_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_DBG_R0_DBG_Pos) & CLB_TILE_CLB_DBG_R0_DBG_Msk)   /*!< DBG Set Value */
#define CLB_TILE_CLB_DBG_R0_DBG_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_DBG_R0_DBG_Msk) >> CLB_TILE_CLB_DBG_R0_DBG_Pos)   /*!< DBG Get Value */

/* CLB_DBG_R1 bitfield */
#define CLB_TILE_CLB_DBG_R1_DBG_Pos     (0U)                                                                              /*!< DBG Position 0 */
#define CLB_TILE_CLB_DBG_R1_DBG_Msk     (0xffffffffU << CLB_TILE_CLB_DBG_R1_DBG_Pos)                                      /*!< DBG Mask 0xFFFFFFFF */
#define CLB_TILE_CLB_DBG_R1_DBG_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_DBG_R1_DBG_Pos) & CLB_TILE_CLB_DBG_R1_DBG_Msk)   /*!< DBG Set Value */
#define CLB_TILE_CLB_DBG_R1_DBG_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_DBG_R1_DBG_Msk) >> CLB_TILE_CLB_DBG_R1_DBG_Pos)   /*!< DBG Get Value */

/* CLB_DBG_R2 bitfield */
#define CLB_TILE_CLB_DBG_R2_DBG_Pos     (0U)                                                                              /*!< DBG Position 0 */
#define CLB_TILE_CLB_DBG_R2_DBG_Msk     (0xffffffffU << CLB_TILE_CLB_DBG_R2_DBG_Pos)                                      /*!< DBG Mask 0xFFFFFFFF */
#define CLB_TILE_CLB_DBG_R2_DBG_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_DBG_R2_DBG_Pos) & CLB_TILE_CLB_DBG_R2_DBG_Msk)   /*!< DBG Set Value */
#define CLB_TILE_CLB_DBG_R2_DBG_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_DBG_R2_DBG_Msk) >> CLB_TILE_CLB_DBG_R2_DBG_Pos)   /*!< DBG Get Value */

/* CLB_DBG_R3 bitfield */
#define CLB_TILE_CLB_DBG_R3_DBG_Pos     (0U)                                                                              /*!< DBG Position 0 */
#define CLB_TILE_CLB_DBG_R3_DBG_Msk     (0xffffffffU << CLB_TILE_CLB_DBG_R3_DBG_Pos)                                      /*!< DBG Mask 0xFFFFFFFF */
#define CLB_TILE_CLB_DBG_R3_DBG_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_DBG_R3_DBG_Pos) & CLB_TILE_CLB_DBG_R3_DBG_Msk)   /*!< DBG Set Value */
#define CLB_TILE_CLB_DBG_R3_DBG_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_DBG_R3_DBG_Msk) >> CLB_TILE_CLB_DBG_R3_DBG_Pos)   /*!< DBG Get Value */

/* CLB_DBG_C0 bitfield */
#define CLB_TILE_CLB_DBG_C0_DBG_Pos     (0U)                                                                              /*!< DBG Position 0 */
#define CLB_TILE_CLB_DBG_C0_DBG_Msk     (0xffffffffU << CLB_TILE_CLB_DBG_C0_DBG_Pos)                                      /*!< DBG Mask 0xFFFFFFFF */
#define CLB_TILE_CLB_DBG_C0_DBG_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_DBG_C0_DBG_Pos) & CLB_TILE_CLB_DBG_C0_DBG_Msk)   /*!< DBG Set Value */
#define CLB_TILE_CLB_DBG_C0_DBG_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_DBG_C0_DBG_Msk) >> CLB_TILE_CLB_DBG_C0_DBG_Pos)   /*!< DBG Get Value */

/* CLB_DBG_C1 bitfield */
#define CLB_TILE_CLB_DBG_C1_DBG_Pos     (0U)                                                                              /*!< DBG Position 0 */
#define CLB_TILE_CLB_DBG_C1_DBG_Msk     (0xffffffffU << CLB_TILE_CLB_DBG_C1_DBG_Pos)                                      /*!< DBG Mask 0xFFFFFFFF */
#define CLB_TILE_CLB_DBG_C1_DBG_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_DBG_C1_DBG_Pos) & CLB_TILE_CLB_DBG_C1_DBG_Msk)   /*!< DBG Set Value */
#define CLB_TILE_CLB_DBG_C1_DBG_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_DBG_C1_DBG_Msk) >> CLB_TILE_CLB_DBG_C1_DBG_Pos)   /*!< DBG Get Value */

/* CLB_DBG_C2 bitfield */
#define CLB_TILE_CLB_DBG_C2_DBG_Pos     (0U)                                                                              /*!< DBG Position 0 */
#define CLB_TILE_CLB_DBG_C2_DBG_Msk     (0xffffffffU << CLB_TILE_CLB_DBG_C2_DBG_Pos)                                      /*!< DBG Mask 0xFFFFFFFF */
#define CLB_TILE_CLB_DBG_C2_DBG_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_DBG_C2_DBG_Pos) & CLB_TILE_CLB_DBG_C2_DBG_Msk)   /*!< DBG Set Value */
#define CLB_TILE_CLB_DBG_C2_DBG_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_DBG_C2_DBG_Msk) >> CLB_TILE_CLB_DBG_C2_DBG_Pos)   /*!< DBG Get Value */

/* CLB_DBG_OUT bitfield */
#define CLB_TILE_CLB_DBG_OUT_OUT7_Pos     (31U)                                                                                 /*!< OUT7 Position 31 */
#define CLB_TILE_CLB_DBG_OUT_OUT7_Msk     (0x1U << CLB_TILE_CLB_DBG_OUT_OUT7_Pos)                                               /*!< OUT7 Mask 0x80000000 */
#define CLB_TILE_CLB_DBG_OUT_OUT7_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_DBG_OUT_OUT7_Pos) & CLB_TILE_CLB_DBG_OUT_OUT7_Msk)   /*!< OUT7 Set Value */
#define CLB_TILE_CLB_DBG_OUT_OUT7_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_DBG_OUT_OUT7_Msk) >> CLB_TILE_CLB_DBG_OUT_OUT7_Pos)   /*!< OUT7 Get Value */

#define CLB_TILE_CLB_DBG_OUT_OUT6_Pos     (30U)                                                                                 /*!< OUT6 Position 30 */
#define CLB_TILE_CLB_DBG_OUT_OUT6_Msk     (0x1U << CLB_TILE_CLB_DBG_OUT_OUT6_Pos)                                               /*!< OUT6 Mask 0x40000000 */
#define CLB_TILE_CLB_DBG_OUT_OUT6_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_DBG_OUT_OUT6_Pos) & CLB_TILE_CLB_DBG_OUT_OUT6_Msk)   /*!< OUT6 Set Value */
#define CLB_TILE_CLB_DBG_OUT_OUT6_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_DBG_OUT_OUT6_Msk) >> CLB_TILE_CLB_DBG_OUT_OUT6_Pos)   /*!< OUT6 Get Value */

#define CLB_TILE_CLB_DBG_OUT_OUT5_Pos     (29U)                                                                                 /*!< OUT5 Position 29 */
#define CLB_TILE_CLB_DBG_OUT_OUT5_Msk     (0x1U << CLB_TILE_CLB_DBG_OUT_OUT5_Pos)                                               /*!< OUT5 Mask 0x20000000 */
#define CLB_TILE_CLB_DBG_OUT_OUT5_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_DBG_OUT_OUT5_Pos) & CLB_TILE_CLB_DBG_OUT_OUT5_Msk)   /*!< OUT5 Set Value */
#define CLB_TILE_CLB_DBG_OUT_OUT5_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_DBG_OUT_OUT5_Msk) >> CLB_TILE_CLB_DBG_OUT_OUT5_Pos)   /*!< OUT5 Get Value */

#define CLB_TILE_CLB_DBG_OUT_OUT4_Pos     (28U)                                                                                 /*!< OUT4 Position 28 */
#define CLB_TILE_CLB_DBG_OUT_OUT4_Msk     (0x1U << CLB_TILE_CLB_DBG_OUT_OUT4_Pos)                                               /*!< OUT4 Mask 0x10000000 */
#define CLB_TILE_CLB_DBG_OUT_OUT4_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_DBG_OUT_OUT4_Pos) & CLB_TILE_CLB_DBG_OUT_OUT4_Msk)   /*!< OUT4 Set Value */
#define CLB_TILE_CLB_DBG_OUT_OUT4_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_DBG_OUT_OUT4_Msk) >> CLB_TILE_CLB_DBG_OUT_OUT4_Pos)   /*!< OUT4 Get Value */

#define CLB_TILE_CLB_DBG_OUT_OUT3_Pos     (27U)                                                                                 /*!< OUT3 Position 27 */
#define CLB_TILE_CLB_DBG_OUT_OUT3_Msk     (0x1U << CLB_TILE_CLB_DBG_OUT_OUT3_Pos)                                               /*!< OUT3 Mask 0x08000000 */
#define CLB_TILE_CLB_DBG_OUT_OUT3_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_DBG_OUT_OUT3_Pos) & CLB_TILE_CLB_DBG_OUT_OUT3_Msk)   /*!< OUT3 Set Value */
#define CLB_TILE_CLB_DBG_OUT_OUT3_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_DBG_OUT_OUT3_Msk) >> CLB_TILE_CLB_DBG_OUT_OUT3_Pos)   /*!< OUT3 Get Value */

#define CLB_TILE_CLB_DBG_OUT_OUT2_Pos     (26U)                                                                                 /*!< OUT2 Position 26 */
#define CLB_TILE_CLB_DBG_OUT_OUT2_Msk     (0x1U << CLB_TILE_CLB_DBG_OUT_OUT2_Pos)                                               /*!< OUT2 Mask 0x04000000 */
#define CLB_TILE_CLB_DBG_OUT_OUT2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_DBG_OUT_OUT2_Pos) & CLB_TILE_CLB_DBG_OUT_OUT2_Msk)   /*!< OUT2 Set Value */
#define CLB_TILE_CLB_DBG_OUT_OUT2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_DBG_OUT_OUT2_Msk) >> CLB_TILE_CLB_DBG_OUT_OUT2_Pos)   /*!< OUT2 Get Value */

#define CLB_TILE_CLB_DBG_OUT_OUT1_Pos     (25U)                                                                                 /*!< OUT1 Position 25 */
#define CLB_TILE_CLB_DBG_OUT_OUT1_Msk     (0x1U << CLB_TILE_CLB_DBG_OUT_OUT1_Pos)                                               /*!< OUT1 Mask 0x02000000 */
#define CLB_TILE_CLB_DBG_OUT_OUT1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_DBG_OUT_OUT1_Pos) & CLB_TILE_CLB_DBG_OUT_OUT1_Msk)   /*!< OUT1 Set Value */
#define CLB_TILE_CLB_DBG_OUT_OUT1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_DBG_OUT_OUT1_Msk) >> CLB_TILE_CLB_DBG_OUT_OUT1_Pos)   /*!< OUT1 Get Value */

#define CLB_TILE_CLB_DBG_OUT_OUT0_Pos     (24U)                                                                                 /*!< OUT0 Position 24 */
#define CLB_TILE_CLB_DBG_OUT_OUT0_Msk     (0x1U << CLB_TILE_CLB_DBG_OUT_OUT0_Pos)                                               /*!< OUT0 Mask 0x01000000 */
#define CLB_TILE_CLB_DBG_OUT_OUT0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_DBG_OUT_OUT0_Pos) & CLB_TILE_CLB_DBG_OUT_OUT0_Msk)   /*!< OUT0 Set Value */
#define CLB_TILE_CLB_DBG_OUT_OUT0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_DBG_OUT_OUT0_Msk) >> CLB_TILE_CLB_DBG_OUT_OUT0_Pos)   /*!< OUT0 Get Value */

#define CLB_TILE_CLB_DBG_OUT_LUT42_OUT_Pos     (23U)                                                                                           /*!< LUT42_OUT Position 23 */
#define CLB_TILE_CLB_DBG_OUT_LUT42_OUT_Msk     (0x1U << CLB_TILE_CLB_DBG_OUT_LUT42_OUT_Pos)                                                    /*!< LUT42_OUT Mask 0x00800000 */
#define CLB_TILE_CLB_DBG_OUT_LUT42_OUT_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_DBG_OUT_LUT42_OUT_Pos) & CLB_TILE_CLB_DBG_OUT_LUT42_OUT_Msk)   /*!< LUT42_OUT Set Value */
#define CLB_TILE_CLB_DBG_OUT_LUT42_OUT_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_DBG_OUT_LUT42_OUT_Msk) >> CLB_TILE_CLB_DBG_OUT_LUT42_OUT_Pos)   /*!< LUT42_OUT Get Value */

#define CLB_TILE_CLB_DBG_OUT_FSM2_LUTOUT_Pos     (22U)                                                                                               /*!< FSM2_LUTOUT Position 22 */
#define CLB_TILE_CLB_DBG_OUT_FSM2_LUTOUT_Msk     (0x1U << CLB_TILE_CLB_DBG_OUT_FSM2_LUTOUT_Pos)                                                      /*!< FSM2_LUTOUT Mask 0x00400000 */
#define CLB_TILE_CLB_DBG_OUT_FSM2_LUTOUT_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_DBG_OUT_FSM2_LUTOUT_Pos) & CLB_TILE_CLB_DBG_OUT_FSM2_LUTOUT_Msk)   /*!< FSM2_LUTOUT Set Value */
#define CLB_TILE_CLB_DBG_OUT_FSM2_LUTOUT_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_DBG_OUT_FSM2_LUTOUT_Msk) >> CLB_TILE_CLB_DBG_OUT_FSM2_LUTOUT_Pos)   /*!< FSM2_LUTOUT Get Value */

#define CLB_TILE_CLB_DBG_OUT_FSM2_S1_Pos     (21U)                                                                                       /*!< FSM2_S1 Position 21 */
#define CLB_TILE_CLB_DBG_OUT_FSM2_S1_Msk     (0x1U << CLB_TILE_CLB_DBG_OUT_FSM2_S1_Pos)                                                  /*!< FSM2_S1 Mask 0x00200000 */
#define CLB_TILE_CLB_DBG_OUT_FSM2_S1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_DBG_OUT_FSM2_S1_Pos) & CLB_TILE_CLB_DBG_OUT_FSM2_S1_Msk)   /*!< FSM2_S1 Set Value */
#define CLB_TILE_CLB_DBG_OUT_FSM2_S1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_DBG_OUT_FSM2_S1_Msk) >> CLB_TILE_CLB_DBG_OUT_FSM2_S1_Pos)   /*!< FSM2_S1 Get Value */

#define CLB_TILE_CLB_DBG_OUT_FSM2_S0_Pos     (20U)                                                                                       /*!< FSM2_S0 Position 20 */
#define CLB_TILE_CLB_DBG_OUT_FSM2_S0_Msk     (0x1U << CLB_TILE_CLB_DBG_OUT_FSM2_S0_Pos)                                                  /*!< FSM2_S0 Mask 0x00100000 */
#define CLB_TILE_CLB_DBG_OUT_FSM2_S0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_DBG_OUT_FSM2_S0_Pos) & CLB_TILE_CLB_DBG_OUT_FSM2_S0_Msk)   /*!< FSM2_S0 Set Value */
#define CLB_TILE_CLB_DBG_OUT_FSM2_S0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_DBG_OUT_FSM2_S0_Msk) >> CLB_TILE_CLB_DBG_OUT_FSM2_S0_Pos)   /*!< FSM2_S0 Get Value */

#define CLB_TILE_CLB_DBG_OUT_COUNT2_MATCH1_Pos     (19U)                                                                                                   /*!< COUNT2_MATCH1 Position 19 */
#define CLB_TILE_CLB_DBG_OUT_COUNT2_MATCH1_Msk     (0x1U << CLB_TILE_CLB_DBG_OUT_COUNT2_MATCH1_Pos)                                                        /*!< COUNT2_MATCH1 Mask 0x00080000 */
#define CLB_TILE_CLB_DBG_OUT_COUNT2_MATCH1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_DBG_OUT_COUNT2_MATCH1_Pos) & CLB_TILE_CLB_DBG_OUT_COUNT2_MATCH1_Msk)   /*!< COUNT2_MATCH1 Set Value */
#define CLB_TILE_CLB_DBG_OUT_COUNT2_MATCH1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_DBG_OUT_COUNT2_MATCH1_Msk) >> CLB_TILE_CLB_DBG_OUT_COUNT2_MATCH1_Pos)   /*!< COUNT2_MATCH1 Get Value */

#define CLB_TILE_CLB_DBG_OUT_COUNT2_ZERO_Pos     (18U)                                                                                               /*!< COUNT2_ZERO Position 18 */
#define CLB_TILE_CLB_DBG_OUT_COUNT2_ZERO_Msk     (0x1U << CLB_TILE_CLB_DBG_OUT_COUNT2_ZERO_Pos)                                                      /*!< COUNT2_ZERO Mask 0x00040000 */
#define CLB_TILE_CLB_DBG_OUT_COUNT2_ZERO_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_DBG_OUT_COUNT2_ZERO_Pos) & CLB_TILE_CLB_DBG_OUT_COUNT2_ZERO_Msk)   /*!< COUNT2_ZERO Set Value */
#define CLB_TILE_CLB_DBG_OUT_COUNT2_ZERO_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_DBG_OUT_COUNT2_ZERO_Msk) >> CLB_TILE_CLB_DBG_OUT_COUNT2_ZERO_Pos)   /*!< COUNT2_ZERO Get Value */

#define CLB_TILE_CLB_DBG_OUT_COUNT2_MATCH2_Pos     (17U)                                                                                                   /*!< COUNT2_MATCH2 Position 17 */
#define CLB_TILE_CLB_DBG_OUT_COUNT2_MATCH2_Msk     (0x1U << CLB_TILE_CLB_DBG_OUT_COUNT2_MATCH2_Pos)                                                        /*!< COUNT2_MATCH2 Mask 0x00020000 */
#define CLB_TILE_CLB_DBG_OUT_COUNT2_MATCH2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_DBG_OUT_COUNT2_MATCH2_Pos) & CLB_TILE_CLB_DBG_OUT_COUNT2_MATCH2_Msk)   /*!< COUNT2_MATCH2 Set Value */
#define CLB_TILE_CLB_DBG_OUT_COUNT2_MATCH2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_DBG_OUT_COUNT2_MATCH2_Msk) >> CLB_TILE_CLB_DBG_OUT_COUNT2_MATCH2_Pos)   /*!< COUNT2_MATCH2 Get Value */

#define CLB_TILE_CLB_DBG_OUT_LUT41_OUT_Pos     (15U)                                                                                           /*!< LUT41_OUT Position 15 */
#define CLB_TILE_CLB_DBG_OUT_LUT41_OUT_Msk     (0x1U << CLB_TILE_CLB_DBG_OUT_LUT41_OUT_Pos)                                                    /*!< LUT41_OUT Mask 0x00008000 */
#define CLB_TILE_CLB_DBG_OUT_LUT41_OUT_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_DBG_OUT_LUT41_OUT_Pos) & CLB_TILE_CLB_DBG_OUT_LUT41_OUT_Msk)   /*!< LUT41_OUT Set Value */
#define CLB_TILE_CLB_DBG_OUT_LUT41_OUT_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_DBG_OUT_LUT41_OUT_Msk) >> CLB_TILE_CLB_DBG_OUT_LUT41_OUT_Pos)   /*!< LUT41_OUT Get Value */

#define CLB_TILE_CLB_DBG_OUT_FSM1_LUTOUT_Pos     (14U)                                                                                               /*!< FSM1_LUTOUT Position 14 */
#define CLB_TILE_CLB_DBG_OUT_FSM1_LUTOUT_Msk     (0x1U << CLB_TILE_CLB_DBG_OUT_FSM1_LUTOUT_Pos)                                                      /*!< FSM1_LUTOUT Mask 0x00004000 */
#define CLB_TILE_CLB_DBG_OUT_FSM1_LUTOUT_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_DBG_OUT_FSM1_LUTOUT_Pos) & CLB_TILE_CLB_DBG_OUT_FSM1_LUTOUT_Msk)   /*!< FSM1_LUTOUT Set Value */
#define CLB_TILE_CLB_DBG_OUT_FSM1_LUTOUT_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_DBG_OUT_FSM1_LUTOUT_Msk) >> CLB_TILE_CLB_DBG_OUT_FSM1_LUTOUT_Pos)   /*!< FSM1_LUTOUT Get Value */

#define CLB_TILE_CLB_DBG_OUT_FSM1_S1_Pos     (13U)                                                                                       /*!< FSM1_S1 Position 13 */
#define CLB_TILE_CLB_DBG_OUT_FSM1_S1_Msk     (0x1U << CLB_TILE_CLB_DBG_OUT_FSM1_S1_Pos)                                                  /*!< FSM1_S1 Mask 0x00002000 */
#define CLB_TILE_CLB_DBG_OUT_FSM1_S1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_DBG_OUT_FSM1_S1_Pos) & CLB_TILE_CLB_DBG_OUT_FSM1_S1_Msk)   /*!< FSM1_S1 Set Value */
#define CLB_TILE_CLB_DBG_OUT_FSM1_S1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_DBG_OUT_FSM1_S1_Msk) >> CLB_TILE_CLB_DBG_OUT_FSM1_S1_Pos)   /*!< FSM1_S1 Get Value */

#define CLB_TILE_CLB_DBG_OUT_FSM1_S0_Pos     (12U)                                                                                       /*!< FSM1_S0 Position 12 */
#define CLB_TILE_CLB_DBG_OUT_FSM1_S0_Msk     (0x1U << CLB_TILE_CLB_DBG_OUT_FSM1_S0_Pos)                                                  /*!< FSM1_S0 Mask 0x00001000 */
#define CLB_TILE_CLB_DBG_OUT_FSM1_S0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_DBG_OUT_FSM1_S0_Pos) & CLB_TILE_CLB_DBG_OUT_FSM1_S0_Msk)   /*!< FSM1_S0 Set Value */
#define CLB_TILE_CLB_DBG_OUT_FSM1_S0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_DBG_OUT_FSM1_S0_Msk) >> CLB_TILE_CLB_DBG_OUT_FSM1_S0_Pos)   /*!< FSM1_S0 Get Value */

#define CLB_TILE_CLB_DBG_OUT_COUNT1_MATCH1_Pos     (11U)                                                                                                   /*!< COUNT1_MATCH1 Position 11 */
#define CLB_TILE_CLB_DBG_OUT_COUNT1_MATCH1_Msk     (0x1U << CLB_TILE_CLB_DBG_OUT_COUNT1_MATCH1_Pos)                                                        /*!< COUNT1_MATCH1 Mask 0x00000800 */
#define CLB_TILE_CLB_DBG_OUT_COUNT1_MATCH1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_DBG_OUT_COUNT1_MATCH1_Pos) & CLB_TILE_CLB_DBG_OUT_COUNT1_MATCH1_Msk)   /*!< COUNT1_MATCH1 Set Value */
#define CLB_TILE_CLB_DBG_OUT_COUNT1_MATCH1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_DBG_OUT_COUNT1_MATCH1_Msk) >> CLB_TILE_CLB_DBG_OUT_COUNT1_MATCH1_Pos)   /*!< COUNT1_MATCH1 Get Value */

#define CLB_TILE_CLB_DBG_OUT_COUNT1_ZERO_Pos     (10U)                                                                                               /*!< COUNT1_ZERO Position 10 */
#define CLB_TILE_CLB_DBG_OUT_COUNT1_ZERO_Msk     (0x1U << CLB_TILE_CLB_DBG_OUT_COUNT1_ZERO_Pos)                                                      /*!< COUNT1_ZERO Mask 0x00000400 */
#define CLB_TILE_CLB_DBG_OUT_COUNT1_ZERO_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_DBG_OUT_COUNT1_ZERO_Pos) & CLB_TILE_CLB_DBG_OUT_COUNT1_ZERO_Msk)   /*!< COUNT1_ZERO Set Value */
#define CLB_TILE_CLB_DBG_OUT_COUNT1_ZERO_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_DBG_OUT_COUNT1_ZERO_Msk) >> CLB_TILE_CLB_DBG_OUT_COUNT1_ZERO_Pos)   /*!< COUNT1_ZERO Get Value */

#define CLB_TILE_CLB_DBG_OUT_COUNT1_MATCH2_Pos     (9U)                                                                                                    /*!< COUNT1_MATCH2 Position 9 */
#define CLB_TILE_CLB_DBG_OUT_COUNT1_MATCH2_Msk     (0x1U << CLB_TILE_CLB_DBG_OUT_COUNT1_MATCH2_Pos)                                                        /*!< COUNT1_MATCH2 Mask 0x00000200 */
#define CLB_TILE_CLB_DBG_OUT_COUNT1_MATCH2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_DBG_OUT_COUNT1_MATCH2_Pos) & CLB_TILE_CLB_DBG_OUT_COUNT1_MATCH2_Msk)   /*!< COUNT1_MATCH2 Set Value */
#define CLB_TILE_CLB_DBG_OUT_COUNT1_MATCH2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_DBG_OUT_COUNT1_MATCH2_Msk) >> CLB_TILE_CLB_DBG_OUT_COUNT1_MATCH2_Pos)   /*!< COUNT1_MATCH2 Get Value */

#define CLB_TILE_CLB_DBG_OUT_LUT40_OUT_Pos     (7U)                                                                                            /*!< LUT40_OUT Position 7 */
#define CLB_TILE_CLB_DBG_OUT_LUT40_OUT_Msk     (0x1U << CLB_TILE_CLB_DBG_OUT_LUT40_OUT_Pos)                                                    /*!< LUT40_OUT Mask 0x00000080 */
#define CLB_TILE_CLB_DBG_OUT_LUT40_OUT_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_DBG_OUT_LUT40_OUT_Pos) & CLB_TILE_CLB_DBG_OUT_LUT40_OUT_Msk)   /*!< LUT40_OUT Set Value */
#define CLB_TILE_CLB_DBG_OUT_LUT40_OUT_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_DBG_OUT_LUT40_OUT_Msk) >> CLB_TILE_CLB_DBG_OUT_LUT40_OUT_Pos)   /*!< LUT40_OUT Get Value */

#define CLB_TILE_CLB_DBG_OUT_FSM0_LUTOUT_Pos     (6U)                                                                                                /*!< FSM0_LUTOUT Position 6 */
#define CLB_TILE_CLB_DBG_OUT_FSM0_LUTOUT_Msk     (0x1U << CLB_TILE_CLB_DBG_OUT_FSM0_LUTOUT_Pos)                                                      /*!< FSM0_LUTOUT Mask 0x00000040 */
#define CLB_TILE_CLB_DBG_OUT_FSM0_LUTOUT_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_DBG_OUT_FSM0_LUTOUT_Pos) & CLB_TILE_CLB_DBG_OUT_FSM0_LUTOUT_Msk)   /*!< FSM0_LUTOUT Set Value */
#define CLB_TILE_CLB_DBG_OUT_FSM0_LUTOUT_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_DBG_OUT_FSM0_LUTOUT_Msk) >> CLB_TILE_CLB_DBG_OUT_FSM0_LUTOUT_Pos)   /*!< FSM0_LUTOUT Get Value */

#define CLB_TILE_CLB_DBG_OUT_FSM0_S1_Pos     (5U)                                                                                        /*!< FSM0_S1 Position 5 */
#define CLB_TILE_CLB_DBG_OUT_FSM0_S1_Msk     (0x1U << CLB_TILE_CLB_DBG_OUT_FSM0_S1_Pos)                                                  /*!< FSM0_S1 Mask 0x00000020 */
#define CLB_TILE_CLB_DBG_OUT_FSM0_S1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_DBG_OUT_FSM0_S1_Pos) & CLB_TILE_CLB_DBG_OUT_FSM0_S1_Msk)   /*!< FSM0_S1 Set Value */
#define CLB_TILE_CLB_DBG_OUT_FSM0_S1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_DBG_OUT_FSM0_S1_Msk) >> CLB_TILE_CLB_DBG_OUT_FSM0_S1_Pos)   /*!< FSM0_S1 Get Value */

#define CLB_TILE_CLB_DBG_OUT_FSM0_S0_Pos     (4U)                                                                                        /*!< FSM0_S0 Position 4 */
#define CLB_TILE_CLB_DBG_OUT_FSM0_S0_Msk     (0x1U << CLB_TILE_CLB_DBG_OUT_FSM0_S0_Pos)                                                  /*!< FSM0_S0 Mask 0x00000010 */
#define CLB_TILE_CLB_DBG_OUT_FSM0_S0_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_DBG_OUT_FSM0_S0_Pos) & CLB_TILE_CLB_DBG_OUT_FSM0_S0_Msk)   /*!< FSM0_S0 Set Value */
#define CLB_TILE_CLB_DBG_OUT_FSM0_S0_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_DBG_OUT_FSM0_S0_Msk) >> CLB_TILE_CLB_DBG_OUT_FSM0_S0_Pos)   /*!< FSM0_S0 Get Value */

#define CLB_TILE_CLB_DBG_OUT_COUNT0_MATCH1_Pos     (3U)                                                                                                    /*!< COUNT0_MATCH1 Position 3 */
#define CLB_TILE_CLB_DBG_OUT_COUNT0_MATCH1_Msk     (0x1U << CLB_TILE_CLB_DBG_OUT_COUNT0_MATCH1_Pos)                                                        /*!< COUNT0_MATCH1 Mask 0x00000008 */
#define CLB_TILE_CLB_DBG_OUT_COUNT0_MATCH1_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_DBG_OUT_COUNT0_MATCH1_Pos) & CLB_TILE_CLB_DBG_OUT_COUNT0_MATCH1_Msk)   /*!< COUNT0_MATCH1 Set Value */
#define CLB_TILE_CLB_DBG_OUT_COUNT0_MATCH1_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_DBG_OUT_COUNT0_MATCH1_Msk) >> CLB_TILE_CLB_DBG_OUT_COUNT0_MATCH1_Pos)   /*!< COUNT0_MATCH1 Get Value */

#define CLB_TILE_CLB_DBG_OUT_COUNT0_ZERO_Pos     (2U)                                                                                                /*!< COUNT0_ZERO Position 2 */
#define CLB_TILE_CLB_DBG_OUT_COUNT0_ZERO_Msk     (0x1U << CLB_TILE_CLB_DBG_OUT_COUNT0_ZERO_Pos)                                                      /*!< COUNT0_ZERO Mask 0x00000004 */
#define CLB_TILE_CLB_DBG_OUT_COUNT0_ZERO_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_DBG_OUT_COUNT0_ZERO_Pos) & CLB_TILE_CLB_DBG_OUT_COUNT0_ZERO_Msk)   /*!< COUNT0_ZERO Set Value */
#define CLB_TILE_CLB_DBG_OUT_COUNT0_ZERO_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_DBG_OUT_COUNT0_ZERO_Msk) >> CLB_TILE_CLB_DBG_OUT_COUNT0_ZERO_Pos)   /*!< COUNT0_ZERO Get Value */

#define CLB_TILE_CLB_DBG_OUT_COUNT0_MATCH2_Pos     (1U)                                                                                                    /*!< COUNT0_MATCH2 Position 1 */
#define CLB_TILE_CLB_DBG_OUT_COUNT0_MATCH2_Msk     (0x1U << CLB_TILE_CLB_DBG_OUT_COUNT0_MATCH2_Pos)                                                        /*!< COUNT0_MATCH2 Mask 0x00000002 */
#define CLB_TILE_CLB_DBG_OUT_COUNT0_MATCH2_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_DBG_OUT_COUNT0_MATCH2_Pos) & CLB_TILE_CLB_DBG_OUT_COUNT0_MATCH2_Msk)   /*!< COUNT0_MATCH2 Set Value */
#define CLB_TILE_CLB_DBG_OUT_COUNT0_MATCH2_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_DBG_OUT_COUNT0_MATCH2_Msk) >> CLB_TILE_CLB_DBG_OUT_COUNT0_MATCH2_Pos)   /*!< COUNT0_MATCH2 Get Value */

/* CLB_PUSH_0 bitfield */
#define CLB_TILE_CLB_PUSH_0_PUSH_Pos     (0U)                                                                                /*!< PUSH Position 0 */
#define CLB_TILE_CLB_PUSH_0_PUSH_Msk     (0xffffffffU << CLB_TILE_CLB_PUSH_0_PUSH_Pos)                                       /*!< PUSH Mask 0xFFFFFFFF */
#define CLB_TILE_CLB_PUSH_0_PUSH_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_PUSH_0_PUSH_Pos) & CLB_TILE_CLB_PUSH_0_PUSH_Msk)   /*!< PUSH Set Value */
#define CLB_TILE_CLB_PUSH_0_PUSH_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_PUSH_0_PUSH_Msk) >> CLB_TILE_CLB_PUSH_0_PUSH_Pos)   /*!< PUSH Get Value */

/* CLB_PUSH_1 bitfield */
#define CLB_TILE_CLB_PUSH_1_PUSH_Pos     (0U)                                                                                /*!< PUSH Position 0 */
#define CLB_TILE_CLB_PUSH_1_PUSH_Msk     (0xffffffffU << CLB_TILE_CLB_PUSH_1_PUSH_Pos)                                       /*!< PUSH Mask 0xFFFFFFFF */
#define CLB_TILE_CLB_PUSH_1_PUSH_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_PUSH_1_PUSH_Pos) & CLB_TILE_CLB_PUSH_1_PUSH_Msk)   /*!< PUSH Set Value */
#define CLB_TILE_CLB_PUSH_1_PUSH_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_PUSH_1_PUSH_Msk) >> CLB_TILE_CLB_PUSH_1_PUSH_Pos)   /*!< PUSH Get Value */

/* CLB_PUSH_2 bitfield */
#define CLB_TILE_CLB_PUSH_2_PUSH_Pos     (0U)                                                                                /*!< PUSH Position 0 */
#define CLB_TILE_CLB_PUSH_2_PUSH_Msk     (0xffffffffU << CLB_TILE_CLB_PUSH_2_PUSH_Pos)                                       /*!< PUSH Mask 0xFFFFFFFF */
#define CLB_TILE_CLB_PUSH_2_PUSH_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_PUSH_2_PUSH_Pos) & CLB_TILE_CLB_PUSH_2_PUSH_Msk)   /*!< PUSH Set Value */
#define CLB_TILE_CLB_PUSH_2_PUSH_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_PUSH_2_PUSH_Msk) >> CLB_TILE_CLB_PUSH_2_PUSH_Pos)   /*!< PUSH Get Value */

/* CLB_PUSH_3 bitfield */
#define CLB_TILE_CLB_PUSH_3_PUSH_Pos     (0U)                                                                                /*!< PUSH Position 0 */
#define CLB_TILE_CLB_PUSH_3_PUSH_Msk     (0xffffffffU << CLB_TILE_CLB_PUSH_3_PUSH_Pos)                                       /*!< PUSH Mask 0xFFFFFFFF */
#define CLB_TILE_CLB_PUSH_3_PUSH_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_PUSH_3_PUSH_Pos) & CLB_TILE_CLB_PUSH_3_PUSH_Msk)   /*!< PUSH Set Value */
#define CLB_TILE_CLB_PUSH_3_PUSH_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_PUSH_3_PUSH_Msk) >> CLB_TILE_CLB_PUSH_3_PUSH_Pos)   /*!< PUSH Get Value */

/* CLB_PULL_0 bitfield */
#define CLB_TILE_CLB_PULL_0_PULL_Pos     (0U)                                                                                /*!< PULL Position 0 */
#define CLB_TILE_CLB_PULL_0_PULL_Msk     (0xffffffffU << CLB_TILE_CLB_PULL_0_PULL_Pos)                                       /*!< PULL Mask 0xFFFFFFFF */
#define CLB_TILE_CLB_PULL_0_PULL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_PULL_0_PULL_Pos) & CLB_TILE_CLB_PULL_0_PULL_Msk)   /*!< PULL Set Value */
#define CLB_TILE_CLB_PULL_0_PULL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_PULL_0_PULL_Msk) >> CLB_TILE_CLB_PULL_0_PULL_Pos)   /*!< PULL Get Value */

/* CLB_PULL_1 bitfield */
#define CLB_TILE_CLB_PULL_1_PULL_Pos     (0U)                                                                                /*!< PULL Position 0 */
#define CLB_TILE_CLB_PULL_1_PULL_Msk     (0xffffffffU << CLB_TILE_CLB_PULL_1_PULL_Pos)                                       /*!< PULL Mask 0xFFFFFFFF */
#define CLB_TILE_CLB_PULL_1_PULL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_PULL_1_PULL_Pos) & CLB_TILE_CLB_PULL_1_PULL_Msk)   /*!< PULL Set Value */
#define CLB_TILE_CLB_PULL_1_PULL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_PULL_1_PULL_Msk) >> CLB_TILE_CLB_PULL_1_PULL_Pos)   /*!< PULL Get Value */

/* CLB_PULL_2 bitfield */
#define CLB_TILE_CLB_PULL_2_PULL_Pos     (0U)                                                                                /*!< PULL Position 0 */
#define CLB_TILE_CLB_PULL_2_PULL_Msk     (0xffffffffU << CLB_TILE_CLB_PULL_2_PULL_Pos)                                       /*!< PULL Mask 0xFFFFFFFF */
#define CLB_TILE_CLB_PULL_2_PULL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_PULL_2_PULL_Pos) & CLB_TILE_CLB_PULL_2_PULL_Msk)   /*!< PULL Set Value */
#define CLB_TILE_CLB_PULL_2_PULL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_PULL_2_PULL_Msk) >> CLB_TILE_CLB_PULL_2_PULL_Pos)   /*!< PULL Get Value */

/* CLB_PULL_3 bitfield */
#define CLB_TILE_CLB_PULL_3_PULL_Pos     (0U)                                                                                /*!< PULL Position 0 */
#define CLB_TILE_CLB_PULL_3_PULL_Msk     (0xffffffffU << CLB_TILE_CLB_PULL_3_PULL_Pos)                                       /*!< PULL Mask 0xFFFFFFFF */
#define CLB_TILE_CLB_PULL_3_PULL_Set(x)  (((uint32_t) (x) << CLB_TILE_CLB_PULL_3_PULL_Pos) & CLB_TILE_CLB_PULL_3_PULL_Msk)   /*!< PULL Set Value */
#define CLB_TILE_CLB_PULL_3_PULL_Get(x)  (((uint32_t) (x) & CLB_TILE_CLB_PULL_3_PULL_Msk) >> CLB_TILE_CLB_PULL_3_PULL_Pos)   /*!< PULL Get Value */

/*!
 * @}
 */

/* clang-format on */

/*!
 * @}
 */ /* end of HS32F7D377_CLB_REGISTER */

#endif /* HS32F7D377_CLB_H */
