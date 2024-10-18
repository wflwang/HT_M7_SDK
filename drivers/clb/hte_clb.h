/*
 * Copyright 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_clb.h
 * \brief SDK CLB driver header file
 * \version 1.0.0
 */

#ifndef HTE_CLB_H
#define HTE_CLB_H


/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_common.h"

/*!
 * \addtogroup DRV_HTE_CLB CLB Driver
 *
 * \brief SDK CLB driver
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! \brief Address offsets from LOGICCFG to LOGICCTL and DATAEXCH register memory maps */

/*! \brief filter mask value */
#define CLB_INPUT_FILTER_FIN_M 0x3U // Input filter control 0

/*! \brief filter sync shift value */
#define CLB_INPUT_FILTER_SYNC_S 16U // Input filter SYNC shift


/*! \brief IN MUX GP IN mask value */
#define CLB_IN_MUX_SEL_GP_IN_MASK 0x1U // Select GP register 0

/*! \brief GPREG release ctrl mask value */
#define CLB_GPREG_RLS_CTRL_MASK  0x1000000U /*!< CLB GPREG release ctrl mask*/
#define CLB_GPREG_RLS_CTRL_SHIFT 24U        /*!< CLB GPREG release ctrl shift*/

/*! \brief GPREG gate ctrl mask value */
#define CLB_GPREG_GATE_CTRL_MASK  0x10000U /*!< CLB GPREG gate ctrl mask*/
#define CLB_GPREG_GATE_CTRL_SHIFT 16U      /*!< CLB GPREG gate ctrl shift*/


/*! \brief LCL IN MUX SEL IN SHIFT value */
#define CLB_LCL_MUX_SEL_IN_SHIFT 5U
/*! \brief LCL IN MUX SEL IN MASK value */
#define CLB_LCL_MUX_SEL_IN_MASK 0x1FU // Local Mux select 0

#define CLB_MISC_INPUT_SEL_SHIFT 28U /*! \brief MISC INPUT SEL IN SHIFT value */


/*! \brief GLBL IN MUX SEL IN SHIFT value */
#define CLB_GLBL_MUX_SEL_IN_SHIFT 7U
/*! \brief GLBL IN MUX SEL IN MASK value */
#define CLB_GLBL_MUX_SEL_IN_MASK 0x7FU // Local Mux select 0


/*! \brief Address offsets for CLB-internal memory space */
#define CLB_ADDR_COUNTER_0_LOAD 0x0U /*!< CLB counter0 load addr index*/
#define CLB_ADDR_COUNTER_1_LOAD 0x1U /*!< CLB counter1 load addr index*/
#define CLB_ADDR_COUNTER_2_LOAD 0x2U /*!< CLB counter2 load addr index*/

#define CLB_ADDR_COUNTER_0_MATCH1 0x4U /*!< CLB counter0 match1 addr index*/
#define CLB_ADDR_COUNTER_1_MATCH1 0x5U /*!< CLB counter1 match1 addr index*/
#define CLB_ADDR_COUNTER_2_MATCH1 0x6U /*!< CLB counter2 match1 addr index*/

#define CLB_ADDR_COUNTER_0_MATCH2 0x8U /*!< CLB counter0 match2 addr index*/
#define CLB_ADDR_COUNTER_1_MATCH2 0x9U /*!< CLB counter1 match2 addr index*/
#define CLB_ADDR_COUNTER_2_MATCH2 0xAU /*!< CLB counter2 match2 addr index*/

#define CLB_ADDR_HLC_R0 0xCU /*!< CLB R0 addr index*/
#define CLB_ADDR_HLC_R1 0xDU /*!< CLB R1 addr index*/
#define CLB_ADDR_HLC_R2 0xEU /*!< CLB R2 addr index*/
#define CLB_ADDR_HLC_R3 0xFU /*!< CLB R3 addr index*/

/*! \brief DEC INSTR max num */
#define CLB_NUM_HLC_INSTR 31U

/*! \brief DEC INSTR offset value */
#define CLB_HLC_INSTR_OFFSET 0x20U // Local Mux select 0


/*! \brief PUSH/PULL FIFO size (32-bit registers) */
#define CLB_FIFO_SIZE 4U


/*! \brief Key to enable writes to the CLB registers */
#define CLB_LOCK_KEY   0x5A5AU /*!< CLB lock key*/
#define CLB_LOCK_LOCK  0x1U    /*!< CLB lock enable*/
#define CLB_LOCK_KEY_S 16U     /*!< CLB lock key */


/*! \brief Shift and masks needed by the API for Input selection */
#define CLB_LCL_MUX_SEL_MISC_INPUT_SEL_M    0x20U        /*!< CLB muxsel misc sel m*/
#define CLB_LCL_MUX_SEL_MISC_INPUT_SEL_S    28U          /*!< CLB muxsel misc sel s*/
#define CLB_LCL_MUX_SEL_MISC_INPUT_SEL_BITM (uint32_t)1U /*!< CLB muxsel misc sel bitm*/

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/*! \brief type definition for CLB callback  */
typedef void (*CLB_Callback_t)();

/*!
 *  \brief    Enum to select the CLB IRQ source
 */
typedef enum
{
    kCLB_INT1 = 0, /*!< CLB IRQ source 1 */
    kCLB_INT2 = 1, /*!< CLB IRQ source 2 */
    kCLB_INT3 = 2, /*!< CLB IRQ source 3 */
    kCLB_INT4 = 3, /*!< CLB IRQ source 4 */
    kCLB_INT_MAX,  /*!< CLB IRQ max */
} CLB_IntSrc_t;

/*! \brief type definition for clb interrupt callback  */
typedef struct
{
    CLB_Callback_t func[kCLB_INT_MAX]; /*!< CLB IRQ callback function */
} CLB_Int_Callback_t;


/*! \brief Values that can be passed to select CLB input signalValues that can be passed to select CLB input signal */
typedef enum
{
    kCLB_IN0 = 0, //!< Input 0
    kCLB_IN1 = 1, //!< Input 1
    kCLB_IN2 = 2, //!< Input 2
    kCLB_IN3 = 3, //!< Input 3
    kCLB_IN4 = 4, //!< Input 4
    kCLB_IN5 = 5, //!< Input 5
    kCLB_IN6 = 6, //!< Input 6
    kCLB_IN7 = 7  //!< Input 7
} CLB_Input_t;

/*! \brief Values that can be passed to select CLB output signal*/
typedef enum
{
    kCLB_OUT0 = 0, //!< Output 0
    kCLB_OUT1 = 1, //!< Output 1
    kCLB_OUT2 = 2, //!< Output 2
    kCLB_OUT3 = 3, //!< Output 3
    kCLB_OUT4 = 4, //!< Output 4
    kCLB_OUT5 = 5, //!< Output 5
    kCLB_OUT6 = 6, //!< Output 6
    kCLB_OUT7 = 7  //!< Output 7
} CLB_Output_t;

/*! \brief CLB counter  */
typedef enum
{
    kCLB_CTR0 = 0, //!< Counter 0
    kCLB_CTR1 = 1, //!< Counter 1
    kCLB_CTR2 = 2  //!< Counter 2
} CLB_Counter_t;

/*! \brief CLB reg  */
typedef enum
{
    kCLB_REG_HLC_R0, //!< HLC R0 register
    kCLB_REG_HLC_R1, //!< HLC R1 register
    kCLB_REG_HLC_R2, //!< HLC R2 register
    kCLB_REG_HLC_R3, //!< HLC R3 register
    kCLB_REG_CTR_C0, //!< Counter 0 register
    kCLB_REG_CTR_C1, //!< Counter 1 register
    kCLB_REG_CTR_C2  //!< Counter 2 register
} CLB_Register_t;

/*! \brief  Values that can be passed to set/clear CLB SW release signals  */
typedef enum
{
    kCLB_SW_RLS_CTRL0 = 0, //!< SW RLS CTRL 0
    kCLB_SW_RLS_CTRL1 = 1, //!< SW RLS CTRL 1
    kCLB_SW_RLS_CTRL2 = 2, //!< SW RLS CTRL 2
    kCLB_SW_RLS_CTRL3 = 3, //!< SW RLS CTRL 3
    kCLB_SW_RLS_CTRL4 = 4, //!< SW RLS CTRL 4
    kCLB_SW_RLS_CTRL5 = 5, //!< SW RLS CTRL 5
    kCLB_SW_RLS_CTRL6 = 6, //!< SW RLS CTRL 6
    kCLB_SW_RLS_CTRL7 = 7  //!< SW RLS CTRL 7
} CLB_SWReleaseCtrl_t;

/*! \brief Values that can be passed to set/clear CLB SW release signals */
typedef enum
{
    kCLB_SW_GATE_CTRL0 = 0, //!< SW GATE CTRL 0
    kCLB_SW_GATE_CTRL1 = 1, //!< SW GATE CTRL 1
    kCLB_SW_GATE_CTRL2 = 2, //!< SW GATE CTRL 2
    kCLB_SW_GATE_CTRL3 = 3, //!< SW GATE CTRL 3
    kCLB_SW_GATE_CTRL4 = 4, //!< SW GATE CTRL 4
    kCLB_SW_GATE_CTRL5 = 5, //!< SW GATE CTRL 5
    kCLB_SW_GATE_CTRL6 = 6, //!< SW GATE CTRL 6
    kCLB_SW_GATE_CTRL7 = 7  //!< SW GATE CTRL 7
} CLB_SWGateCtrl_t;

/*! \brief Values that can be passed to CLB_selectInputFilter  */
typedef enum
{
    kCLB_FILTER_NONE         = 0, //!< No filtering
    kCLB_FILTER_RISING_EDGE  = 1, //!< Rising edge detect
    kCLB_FILTER_FALLING_EDGE = 2, //!< Falling edge detect
    kCLB_FILTER_ANY_EDGE     = 3  //!< Any edge detect
} CLB_FilterType_t;

/*! \brief Values that can be passed to CLB_configGPInputMux  */
typedef enum
{
    kCLB_GP_IN_MUX_EXTERNAL = 0, //!< Use external input path
    kCLB_GP_IN_MUX_GP_REG   = 1  //!< Use CLB_GP_REG bit value as input
} CLB_GPInputMux_t;

/*! \brief Values that can be passed to select CLB AOC signal  */
typedef enum
{
    kCLB_AOC0 = 0, //!< AOC 0
    kCLB_AOC1 = 1, //!< AOC 1
    kCLB_AOC2 = 2, //!< AOC 2
    kCLB_AOC3 = 3, //!< AOC 3
    kCLB_AOC4 = 4, //!< AOC 4
    kCLB_AOC5 = 5, //!< AOC 5
    kCLB_AOC6 = 6, //!< AOC 6
    kCLB_AOC7 = 7  //!< AOC 7
} CLB_AOC_t;

/*! \brief Values that can be passed to CLB_configLocalInputMux  */
typedef enum
{
    kCLB_LOCAL_IN_MUX_GLOBAL_IN        = 0,  //!< Global input mux selection
    kCLB_LOCAL_IN_MUX_EPWM_DCAEVT1     = 1,  //!< EPWMx DCAEVT1
    kCLB_LOCAL_IN_MUX_EPWM_DCAEVT2     = 2,  //!< EPWMx DCAEVT2
    kCLB_LOCAL_IN_MUX_EPWM_DCBEVT1     = 3,  //!< EPWMx DCBEVT1
    kCLB_LOCAL_IN_MUX_EPWM_DCBEVT2     = 4,  //!< EPWMx DCBEVT2
    kCLB_LOCAL_IN_MUX_EPWM_DCAH        = 5,  //!< EPWMx DCAH
    kCLB_LOCAL_IN_MUX_EPWM_DCAL        = 6,  //!< EPWMx DCAL
    kCLB_LOCAL_IN_MUX_EPWM_DCBH        = 7,  //!< EPWMx DCBH
    kCLB_LOCAL_IN_MUX_EPWM_DCBL        = 8,  //!< EPWMx DCBL
    kCLB_LOCAL_IN_MUX_EPWM_OST         = 9,  //!< EPWMx OST
    kCLB_LOCAL_IN_MUX_EPWM_CBC         = 10, //!< EPWMx CBC
    kCLB_LOCAL_IN_MUX_ECAP_ECAPIN      = 11, //!< ECAPx ECAPIN
    kCLB_LOCAL_IN_MUX_ECAP_ECAP_OUT    = 12, //!< ECAPx ECAP_OUT
    kCLB_LOCAL_IN_MUX_ECAP_ECAP_OUT_EN = 13, //!< ECAPx ECAP_OUT_EN
    kCLB_LOCAL_IN_MUX_ECAP_CEVT1       = 14, //!< ECAPx CEVT1
    kCLB_LOCAL_IN_MUX_ECAP_CEVT2       = 15, //!< ECAPx CEVT2
    kCLB_LOCAL_IN_MUX_ECAP_CEVT3       = 16, //!< ECAPx CEVT3
    kCLB_LOCAL_IN_MUX_ECAP_CEVT4       = 17, //!< ECAPx CEVT4
    kCLB_LOCAL_IN_MUX_EQEP_EQEPA       = 18, //!< EQEPx EQEPA
    kCLB_LOCAL_IN_MUX_EQEP_EQEPB       = 19, //!< EQEPx EQEPB
    kCLB_LOCAL_IN_MUX_EQEP_EQEPI       = 20, //!< EQEPx EQEPI
    kCLB_LOCAL_IN_MUX_EQEP_EQEPS       = 21, //!< EQEPx EQEPS
    kCLB_LOCAL_IN_MUX_CPU1_TBCLKSYNC   = 22, //!< CPU1.TBCLKSYNC
    kCLB_LOCAL_IN_MUX_CPU2_TBCLKSYNC   = 23, //!< CPU2.TBCLKSYNC
    kCLB_LOCAL_IN_MUX_CPU1_HALT        = 24, //!< CPU1.HALT
    kCLB_LOCAL_IN_MUX_CPU2_HALT        = 25, //!< CPU2.HALT
} CLB_LocalInputMux_t;

/*! \brief Values that can be passed to CLB_configLocalInputMux  */
typedef enum
{
    kCLB_MISC_INPUT_DISABLE = 0, //!< MISC input disable
    kCLB_MISC_INPUT_ENABLE  = 1, //!< MISC input enable
} CLB_MiscInput_t;

/*! \brief Values that can be passed to CLB_configLocalInputMux  */
typedef enum
{
    kCLB_GLOBAL_IN_MUX_EPWM1A         = 0,  //!< EPWM1A
    kCLB_GLOBAL_IN_MUX_EPWM1A_OE      = 1,  //!< EPWM1A trip output
    kCLB_GLOBAL_IN_MUX_EPWM1B         = 2,  //!< EPWM1B
    kCLB_GLOBAL_IN_MUX_EPWM1B_OE      = 3,  //!< EPWM1B trip output
    kCLB_GLOBAL_IN_MUX_EPWM1_CTR_ZERO = 4,  //!< EPWM1 TBCTR = Zero
    kCLB_GLOBAL_IN_MUX_EPWM1_CTR_PRD  = 5,  //!< EPWM1 TBCTR = TBPRD
    kCLB_GLOBAL_IN_MUX_EPWM1_CTRDIR   = 6,  //!< EPWM1 CTRDIR
    kCLB_GLOBAL_IN_MUX_EPWM1_TBCLK    = 7,  //!< EPWM1 TBCLK
    kCLB_GLOBAL_IN_MUX_EPWM1_CTR_CMPA = 8,  //!< EPWM1 TBCTR = CMPA
    kCLB_GLOBAL_IN_MUX_EPWM1_CTR_CMPB = 9,  //!< EPWM1 TBCTR = CMPB
    kCLB_GLOBAL_IN_MUX_EPWM1_CTR_CMPC = 10, //!< EPWM1 TBCTR = CMPC
    kCLB_GLOBAL_IN_MUX_EPWM1_CTR_CMPD = 11, //!< EPWM1 TBCTR = CMPD
    kCLB_GLOBAL_IN_MUX_EPWM1A_AQ      = 12, //!< EPWM1A AQ submodule output
    kCLB_GLOBAL_IN_MUX_EPWM1B_AQ      = 13, //!< EPWM1B AQ submodule output
    kCLB_GLOBAL_IN_MUX_EPWM1A_DB      = 14, //!< EPWM1A DB submodule output
    kCLB_GLOBAL_IN_MUX_EPWM1B_DB      = 15, //!< EPWM1B DB submodule output

    kCLB_GLOBAL_IN_MUX_EPWM2A         = 16, //!< EPWM2A
    kCLB_GLOBAL_IN_MUX_EPWM2A_OE      = 17, //!< EPWM2A trip output
    kCLB_GLOBAL_IN_MUX_EPWM2B         = 18, //!< EPWM2B
    kCLB_GLOBAL_IN_MUX_EPWM2B_OE      = 19, //!< EPWM2B trip output
    kCLB_GLOBAL_IN_MUX_EPWM2_CTR_ZERO = 20, //!< EPWM2 TBCTR = Zero
    kCLB_GLOBAL_IN_MUX_EPWM2_CTR_PRD  = 21, //!< EPWM2 TBCTR = TBPRD
    kCLB_GLOBAL_IN_MUX_EPWM2_CTRDIR   = 22, //!< EPWM2 CTRDIR
    kCLB_GLOBAL_IN_MUX_EPWM2_TBCLK    = 23, //!< EPWM2 TBCLK
    kCLB_GLOBAL_IN_MUX_EPWM2_CTR_CMPA = 24, //!< EPWM2 TBCTR = CMPA
    kCLB_GLOBAL_IN_MUX_EPWM2_CTR_CMPB = 25, //!< EPWM2 TBCTR = CMPB
    kCLB_GLOBAL_IN_MUX_EPWM2_CTR_CMPC = 26, //!< EPWM2 TBCTR = CMPC
    kCLB_GLOBAL_IN_MUX_EPWM2_CTR_CMPD = 27, //!< EPWM2 TBCTR = CMPD
    kCLB_GLOBAL_IN_MUX_EPWM2A_AQ      = 28, //!< EPWM2A AQ submodule output
    kCLB_GLOBAL_IN_MUX_EPWM2B_AQ      = 29, //!< EPWM2B AQ submodule output
    kCLB_GLOBAL_IN_MUX_EPWM2A_DB      = 30, //!< EPWM2A DB submodule output
    kCLB_GLOBAL_IN_MUX_EPWM2B_DB      = 31, //!< EPWM2B DB submodule output

    kCLB_GLOBAL_IN_MUX_EPWM3A         = 32, //!< EPWM3A
    kCLB_GLOBAL_IN_MUX_EPWM3A_OE      = 33, //!< EPWM3A trip output
    kCLB_GLOBAL_IN_MUX_EPWM3B         = 34, //!< EPWM3B
    kCLB_GLOBAL_IN_MUX_EPWM3B_OE      = 35, //!< EPWM3B trip output
    kCLB_GLOBAL_IN_MUX_EPWM3_CTR_ZERO = 36, //!< EPWM3 TBCTR = Zero
    kCLB_GLOBAL_IN_MUX_EPWM3_CTR_PRD  = 37, //!< EPWM3 TBCTR = TBPRD
    kCLB_GLOBAL_IN_MUX_EPWM3_CTRDIR   = 38, //!< EPWM3 CTRDIR
    kCLB_GLOBAL_IN_MUX_EPWM3_TBCLK    = 39, //!< EPWM3 TBCLK
    kCLB_GLOBAL_IN_MUX_EPWM3_CTR_CMPA = 40, //!< EPWM3 TBCTR = CMPA
    kCLB_GLOBAL_IN_MUX_EPWM3_CTR_CMPB = 41, //!< EPWM3 TBCTR = CMPB
    kCLB_GLOBAL_IN_MUX_EPWM3_CTR_CMPC = 42, //!< EPWM3 TBCTR = CMPC
    kCLB_GLOBAL_IN_MUX_EPWM3_CTR_CMPD = 43, //!< EPWM3 TBCTR = CMPD
    kCLB_GLOBAL_IN_MUX_EPWM3A_AQ      = 44, //!< EPWM3A AQ submodule output
    kCLB_GLOBAL_IN_MUX_EPWM3B_AQ      = 45, //!< EPWM3B AQ submodule output
    kCLB_GLOBAL_IN_MUX_EPWM3A_DB      = 46, //!< EPWM3A DB submodule output
    kCLB_GLOBAL_IN_MUX_EPWM3B_DB      = 47, //!< EPWM3B DB submodule output

    kCLB_GLOBAL_IN_MUX_EPWM4A         = 48, //!< EPWM4A
    kCLB_GLOBAL_IN_MUX_EPWM4A_OE      = 49, //!< EPWM4A trip output
    kCLB_GLOBAL_IN_MUX_EPWM4B         = 50, //!< EPWM4B
    kCLB_GLOBAL_IN_MUX_EPWM4B_OE      = 51, //!< EPWM4B trip output
    kCLB_GLOBAL_IN_MUX_EPWM4_CTR_ZERO = 52, //!< EPWM4 TBCTR = Zero
    kCLB_GLOBAL_IN_MUX_EPWM4_CTR_PRD  = 53, //!< EPWM4 TBCTR = TBPRD
    kCLB_GLOBAL_IN_MUX_EPWM4_CTRDIR   = 54, //!< EPWM4 CTRDIR
    kCLB_GLOBAL_IN_MUX_EPWM4_TBCLK    = 55, //!< EPWM4 TBCLK
    kCLB_GLOBAL_IN_MUX_EPWM4_CTR_CMPA = 56, //!< EPWM4 TBCTR = CMPA
    kCLB_GLOBAL_IN_MUX_EPWM4_CTR_CMPB = 57, //!< EPWM4 TBCTR = CMPB
    kCLB_GLOBAL_IN_MUX_EPWM4_CTR_CMPC = 58, //!< EPWM4 TBCTR = CMPC
    kCLB_GLOBAL_IN_MUX_EPWM4_CTR_CMPD = 59, //!< EPWM4 TBCTR = CMPD
    kCLB_GLOBAL_IN_MUX_EPWM4A_AQ      = 60, //!< EPWM4A AQ submodule output
    kCLB_GLOBAL_IN_MUX_EPWM4B_AQ      = 61, //!< EPWM4B AQ submodule output
    kCLB_GLOBAL_IN_MUX_EPWM4A_DB      = 62, //!< EPWM4A DB submodule output
    kCLB_GLOBAL_IN_MUX_EPWM4B_DB      = 63, //!< EPWM4B DB submodule output

    kCLB_GLOBAL_IN_MUX_CLB_AUXSIG0 = 64, //!< CLB XBAR AUXSIG0
    kCLB_GLOBAL_IN_MUX_CLB_AUXSIG1 = 65, //!< CLB XBAR AUXSIG1
    kCLB_GLOBAL_IN_MUX_CLB_AUXSIG2 = 66, //!< CLB XBAR AUXSIG2
    kCLB_GLOBAL_IN_MUX_CLB_AUXSIG3 = 67, //!< CLB XBAR AUXSIG3
    kCLB_GLOBAL_IN_MUX_CLB_AUXSIG4 = 68, //!< CLB XBAR AUXSIG4
    kCLB_GLOBAL_IN_MUX_CLB_AUXSIG5 = 69, //!< CLB XBAR AUXSIG5
    kCLB_GLOBAL_IN_MUX_CLB_AUXSIG6 = 70, //!< CLB XBAR AUXSIG6
    kCLB_GLOBAL_IN_MUX_CLB_AUXSIG7 = 71, //!< CLB XBAR AUXSIG7
} CLB_GlobalInputMux_t;

/*******************************************************************************
 * APIs
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Checks the CLB internal memory address.
 *
 * \details This function determines if a CLB base address is valid.
 *
 * \param[in] address is the base address of a CLB tile's logic config register.
 * \return Returns \b true if the base address is valid and \b false otherwise
 *
 */
static inline bool CLB_isAddressValid(uint32_t address)
{
    return (address <= (CLB_NUM_HLC_INSTR + CLB_HLC_INSTR_OFFSET));
}

/*!
 * \brief Checks the CLB base address
 *
 * \details This function determines if a CLB base address is valid
 *
 * \param[in] base is the base address of a CLB tile's logic config register.
 * \return Return \b true if the base address is valid and \b false otherwise.
 *
 */
static inline bool CLB_isBaseValid(CLB_TILE_Type *base)
{
    return ((base == CLB_TILE1) || (base == CLB_TILE2) || (base == CLB_TILE3) || (base == CLB_TILE4));
}

/*!
 * \brief Set global enable.
 *
 * \details This function enables the CLB via global enable register.
 * \param[in] base is the base address of a CLB tile's logic config register.
 *
 */
static inline void CLB_enableCLB(CLB_TILE_Type *base)
{
    assert(CLB_isBaseValid(base));

    base->CLB_LOAD_EN |= CLB_TILE_CLB_LOAD_EN_GLOBAL_EN_Set(1U);
}

/*!
 * \brief Clear global enable.
 *
 * \details This function disables the CLB via global enable register.
 * \param[in] base is the base address of a CLB tile's logic config register.
 *
 */
static inline void CLB_disableCLB(CLB_TILE_Type *base)
{
    assert(CLB_isBaseValid(base));

    base->CLB_LOAD_EN &= ~CLB_TILE_CLB_LOAD_EN_GLOBAL_EN_Set(1U);
    ;
}

/*!
 * \brief Enable CLB lock.
 *
 * \details This function enables the lock bit of the lock register.
 * \param[in] base is the base address of a CLB tile's logic config register.
 *
 */
static inline void CLB_enableLock(CLB_TILE_Type *base)
{
    assert(CLB_isBaseValid(base));

    //
    // Setting the lock bit requires key 0x5A5A to be written at the same time
    //
    base->CLB_LOCK = (uint32_t)CLB_LOCK_LOCK | ((uint32_t)CLB_LOCK_KEY << CLB_LOCK_KEY_S);
}

/*!
 * \brief Write value to address.
 *
 * \details This function writes the specified value to CLB internal memory.
 * \param[in] base is the base address of a CLB tile's logic config register.
 * \param[in] address is the address of CLB internal memory.
 * \param[in] value is the value to write to specified address.
 *
 */
static inline void CLB_writeInterface(CLB_TILE_Type *base, uint32_t address, uint32_t value)
{
    assert(CLB_isBaseValid(base));
    assert(CLB_isAddressValid(address));

    base->CLB_LOAD_ADDR  = address;
    base->CLB_LOAD_DATA  = value;
    base->CLB_LOAD_EN   |= CLB_TILE_CLB_LOAD_EN_LOAD_EN_Set(1U);
}

/*!
 * \brief Select input filter type.
 *
 * \details This function configures the filter selection for the specified input.
 * \param[in] base is the base address of a CLB tile's logic config register.
 * \param[in] inID is the specified CLB tile input signal.
 * \param[in] filterType is the selected type of filter applied to the input.
 *
 */
static inline void CLB_selectInputFilter(CLB_TILE_Type *base, CLB_Input_t inID, CLB_FilterType_t filterType)
{
    uint32_t shiftVal;
    uint32_t regVal;

    assert(CLB_isBaseValid(base));

    //
    // Each input has a 2-bit field in this register so need to calculate
    // shift amount accordingly.
    //
    shiftVal = (uint32_t)inID << 1;

    regVal                  = base->CLB_INPUT_FILTER;
    regVal                 &= ~(CLB_INPUT_FILTER_FIN_M << shiftVal);
    regVal                 |= ((uint32_t)filterType << shiftVal);
    base->CLB_INPUT_FILTER  = regVal;
}

/*!
 * \brief Enables synchronization of an input signal.
 *
 * \details This function enables synchronization on the specified input signal.
 * \param[in] base is the base address of a CLB tile's logic config register.
 * \param[in] inID is the specified CLB tile input signal.
 *
 */
static inline void CLB_enableSynchronization(CLB_TILE_Type *base, CLB_Input_t inID)
{
    assert(CLB_isBaseValid(base));

    uint32_t shiftVal;

    shiftVal = (uint32_t)inID + CLB_INPUT_FILTER_SYNC_S;

    base->CLB_INPUT_FILTER |= (0x1U << shiftVal);
}

/*!
 * \brief Disables synchronization of an input signal.
 *
 * \details This function disables synchronization on the specified input signal.
 * \param[in] base is the base address of a CLB tile's logic config register.
 * \param[in] inID is the specified CLB tile input signal.
 *
 */
static inline void CLB_disableSynchronization(CLB_TILE_Type *base, CLB_Input_t inID)
{
    assert(CLB_isBaseValid(base));

    uint32_t shiftVal;

    shiftVal = (uint32_t)inID + CLB_INPUT_FILTER_SYNC_S;

    base->CLB_INPUT_FILTER &= ~(0x1U << shiftVal);
}

/*!
 * \brief Configures the general purpose input mux.
 *
 * \details This function configures the general purpose input mux.
 * \param[in] base is the base address of a CLB tile's logic config register.
 * \param[in] inID is the specified CLB tile input signal.
 * \param[in] gpMuxCfg is the mux selection for the general purpose input mux.
 *
 */
static inline void CLB_configGPInputMux(CLB_TILE_Type *base, CLB_Input_t inID, CLB_GPInputMux_t gpMuxCfg)
{
    uint32_t regVal;

    assert(CLB_isBaseValid(base));


    regVal                  = base->CLB_IN_MUX_SEL_0;
    regVal                 &= ~(CLB_IN_MUX_SEL_GP_IN_MASK << inID);
    regVal                 |= ((uint32_t)gpMuxCfg << inID);
    base->CLB_IN_MUX_SEL_0  = regVal;
}

/*!
 * \brief Sets the CLB_GP_REG register value.
 *
 * \details This function writes to the CLB_GP_REG register. When the general purpose
 *       input mux is configured to use CLB_GP_REG
 *
 * \param[in] base is the base address of a CLB tile's logic config register.
 * \param[in] gpregVal is the value to be written to CLB_GP_REG.
 *
 */
static inline void CLB_setGPREG(CLB_TILE_Type *base, uint32_t gpregVal)
{
    assert(CLB_isBaseValid(base));

    base->CLB_GP_REG = gpregVal;
}

/*!
 * \brief Gets the CLB_GP_REG register value.
 *
 * \details This function writes to the CLB_GP_REG register. When the general purpose
 *       input mux is configured to use CLB_GP_REG
 *
 * \param[in] base is the base address of a CLB tile's logic config register.
 * \return CLB_GP_REG value.
 */
static inline uint32_t CLB_getGPREG(CLB_TILE_Type *base)
{
    assert(CLB_isBaseValid(base));

    return (base->CLB_GP_REG);
}

/*!
 * \brief Configures the general purpose SW release control value.
 *
 * \details This function configures the general purpose SW release control value.
 * \param[in] base is the base address of a CLB tile's logic config register.
 * \param[in] inID is the specified CLB SW Release input signal.
 * \param[in] val is the value of the SW RLS control.
 *
 */
static inline void CLB_writeSWReleaseControl(CLB_TILE_Type *base, CLB_SWReleaseCtrl_t inID, bool val)
{
    uint32_t regVal;
    assert(CLB_isBaseValid(base));

    regVal            = base->CLB_GP_REG;
    regVal           &= ~(CLB_GPREG_RLS_CTRL_MASK << inID);
    regVal            |= ((uint32_t)val) << (CLB_GPREG_RLS_CTRL_SHIFT + inID);
    base->CLB_GP_REG  = regVal;
}

/*!
 * \brief Configures the general purpose SW gate control value.
 *
 * \details This function configures the general purpose SW gate control value.
 * \param[in] base is the base address of a CLB tile's logic config register.
 * \param[in] inID is the specified CLB SW Release input signal.
 * \param[in] val is the value of the SW GATE control.
 *
 */
static inline void CLB_writeSWGateControl(CLB_TILE_Type *base, CLB_SWGateCtrl_t inID, bool val)
{
    uint32_t regVal;
    assert(CLB_isBaseValid(base));

    regVal            = base->CLB_GP_REG;
    regVal           &= ~(CLB_GPREG_GATE_CTRL_MASK << inID);
    regVal            |= ((uint32_t)val) << (CLB_GPREG_GATE_CTRL_SHIFT + inID);
    base->CLB_GP_REG  = regVal;
}

/*!
 * \brief Configures the local input mux.
 *
 * \details This function configures the local input mux for the specified input signal.
 * \param[in] base is the base address of a CLB tile's logic config register.
 * \param[in] inID is the specified CLB tile input signal.
 * \param[in] localMuxCfg is the mux selection for the local input mux.
 *
 */
static inline void CLB_configLocalInputMux(CLB_TILE_Type *base, CLB_Input_t inID, CLB_LocalInputMux_t localMuxCfg)
{
    uint16_t shiftVal;
    uint32_t regVal;

    assert(CLB_isBaseValid(base));

    //
    // Each local input has a 5-bit field in this register so need to calculate
    // shift amount accordingly.
    //
    shiftVal = (uint16_t)inID * CLB_LCL_MUX_SEL_IN_SHIFT;

    if (inID < kCLB_IN4)
    {
        regVal                   = base->CLB_LCL_MUX_SEL_1;
        regVal                  &= ~((uint32_t)CLB_LCL_MUX_SEL_IN_MASK << shiftVal);
        regVal                  |= ((uint32_t)localMuxCfg << shiftVal);
        base->CLB_LCL_MUX_SEL_1  = regVal;
    }
    else
    {
        //
        // Calculating shift amount for inputs > input3
        //
        shiftVal -= 4U * CLB_LCL_MUX_SEL_IN_SHIFT;

        regVal                   = base->CLB_LCL_MUX_SEL_2;
        regVal                  &= ~((uint32_t)CLB_LCL_MUX_SEL_IN_MASK << shiftVal);
        regVal                  |= ((uint32_t)localMuxCfg << shiftVal);
        base->CLB_LCL_MUX_SEL_2  = regVal;
    }
}

/*!
 * \brief Configures the misc input mux.
 *
 * \details This function configures the local input mux for the specified input signal.
 * \param[in] base is the base address of a CLB tile's logic config register.
 * \param[in] inID is the specified CLB tile input signal.
 * \param[in] miscInputCfg is the mux selection for the local input mux.
 *
 */
static inline void CLB_configMiscInput(CLB_TILE_Type *base, CLB_Input_t inID, CLB_MiscInput_t miscInputCfg)
{
    uint16_t shiftVal;
    uint32_t regVal;

    assert(CLB_isBaseValid(base));

    //
    // Each local input has a 5-bit field in this register so need to calculate
    // shift amount accordingly.
    //
    shiftVal = (uint16_t)inID + CLB_MISC_INPUT_SEL_SHIFT;

    if (inID < kCLB_IN4)
    {
        regVal                   = base->CLB_LCL_MUX_SEL_1;
        regVal                  &= ~(0x1U << shiftVal);
        regVal                  |= ((uint32_t)miscInputCfg << shiftVal);
        base->CLB_LCL_MUX_SEL_1  = regVal;
    }
    else
    {
        //
        // Calculating shift amount for inputs > input3
        //
        shiftVal -= 4U;

        regVal                   = base->CLB_LCL_MUX_SEL_2;
        regVal                  &= ~(0x1U << shiftVal);
        regVal                  |= ((uint32_t)miscInputCfg << shiftVal);
        base->CLB_LCL_MUX_SEL_2  = regVal;
    }
}

/*!
 * \brief Configures the global input mux.
 *
 * \details This function configures the global input mux for the specified input signal.
 * \param[in] base is the base address of a CLB tile's logic config register.
 * \param[in] inID is the specified CLB tile input signal.
 * \param[in] globalMuxCfg is the mux selection for the global input mux.
 *
 */
static inline void CLB_configGlobalInputMux(CLB_TILE_Type *base, CLB_Input_t inID, CLB_GlobalInputMux_t globalMuxCfg)
{
    uint16_t shiftVal;
    uint32_t regVal;

    assert(CLB_isBaseValid(base));

    //
    // Each local input has a 5-bit field in this register so need to calculate
    // shift amount accordingly.
    //
    shiftVal = (uint16_t)inID * CLB_GLBL_MUX_SEL_IN_SHIFT;

    if (inID < kCLB_IN4)
    {
        regVal                    = base->CLB_GLBL_MUX_SEL_1;
        regVal                   &= ~((uint32_t)CLB_GLBL_MUX_SEL_IN_MASK << shiftVal);
        regVal                   |= ((uint32_t)globalMuxCfg << shiftVal);
        base->CLB_GLBL_MUX_SEL_1  = regVal;
    }
    else
    {
        //
        // Calculating shift amount for inputs > input3
        //
        shiftVal -= 4U * CLB_GLBL_MUX_SEL_IN_SHIFT;

        regVal                    = base->CLB_GLBL_MUX_SEL_2;
        regVal                   &= ~((uint32_t)CLB_GLBL_MUX_SEL_IN_MASK << shiftVal);
        regVal                   |= ((uint32_t)globalMuxCfg << shiftVal);
        base->CLB_GLBL_MUX_SEL_2  = regVal;
    }
}

/*!
 * \brief Controls the output enable.
 *
 * \details  This function is used to enable and disable CLB outputs by writing a mask
 *           to CLB_OUT_EN. Each bit corresponds to a CLB output. When a bit is 1, the
 *           corresponding output is enabled; when a bit is 0, the output is disabled.
 * \param[in] base is the base address of a CLB tile's logic config register.
 * \param[in] outputMask is a mask of the outputs to be enabled.
 * \param[in] enable is a switch to decide if the CLB outputs need to be enabled or not
 *
 */
static inline void CLB_setOutputMask(CLB_TILE_Type *base, uint32_t outputMask, bool enable)
{
    assert(CLB_isBaseValid(base));

    if (enable == true)
    {
        base->CLB_OUT_EN |= outputMask;
    }
    else
    {
        base->CLB_OUT_EN &= ~outputMask;
    }
}

/*!
 * \brief Reads the interrupt tag register.
 *
 * \details This function get the interrupt tag register.
 *
 * \param[in] base is the base address of a CLB tile's logic config register.
 *
 * \return Returns the value in the interrupt tag register which is a 6-bit
 *         constant set by the HLC.
 */
static inline uint16_t CLB_getInterruptTag(CLB_TILE_Type *base)
{
    assert(CLB_isBaseValid(base));

    return (base->CLB_INTR_TAG_REG);
}

/*!
 * \brief Clears the interrupt tag register.
 *
 * \details This function clears the interrupt tag register, setting it to 0.
 * \param[in] base is the base address of a CLB tile's logic config register.
 *
 */
static inline void CLB_clearInterruptTag(CLB_TILE_Type *base)
{
    assert(CLB_isBaseValid(base));

    //   base->CLB_INTR_TAG_REG = 0U;
}

/*!
 * \brief Selects LUT4 inputs.
 *
 * \details  This function configures the LUT4 block's input signals.
 * \param[in] base is the base address of a CLB tile's logic config register.
 * \param[in] lut4In0 is the value for LUT4 input signal 0.
 * \param[in] lut4In1 is the value for LUT4 input signal 1.
 * \param[in] lut4In2 is the value for LUT4 input signal 2.
 * \param[in] lut4In3 is the value for LUT4 input signal 3.
 *
 */
static inline void CLB_selectLUT4Inputs(CLB_TILE_Type *base, uint32_t lut4In0, uint32_t lut4In1, uint32_t lut4In2,
                                        uint32_t lut4In3)
{
    assert(CLB_isBaseValid(base));

    base->CLB_LUT4_IN0 = lut4In0;
    base->CLB_LUT4_IN1 = lut4In1;
    base->CLB_LUT4_IN2 = lut4In2;
    base->CLB_LUT4_IN3 = lut4In3;
}

/*!
 * \brief Configures LUT4 functions.
 *
 * \details  This function configures the LUT4 block's equations.
 * \param[in] base is the base address of a CLB tile's logic config register.
 * \param[in] lut4Fn10 is the equation value for LUT4 blocks 0 and 1.
 * \param[in] lut4Fn2 is the equation value for LUT4 block2.
 *
 */
static inline void CLB_configLUT4Function(CLB_TILE_Type *base, uint32_t lut4Fn10, uint32_t lut4Fn2)
{
    assert(CLB_isBaseValid(base));

    base->CLB_LUT4_FN1_0 = lut4Fn10;
    base->CLB_LUT4_FN2   = lut4Fn2;
}

/*!
 * \brief Selects FSM inputs.
 *
 * \details  This function configures the FSM block's external inputs and extra external
 *            inputs.
 * \param[in] base is the base address of a CLB tile's logic config register.
 * \param[in] external0 is the value for FSM external 0 input.
 * \param[in] external1 is the value for FSM external 1 input.
 * \param[in] extra0 is the value for FSM extra 0 input.
 * \param[in] extra1 is the value for FSM extra 1 input.
 *
 */
static inline void CLB_selectFSMInputs(CLB_TILE_Type *base, uint32_t external0, uint32_t external1, uint32_t extra0,
                                       uint32_t extra1)
{
    assert(CLB_isBaseValid(base));

    base->CLB_FSM_EXTERNAL_IN0 = external0;
    base->CLB_FSM_EXTERNAL_IN1 = external1;
    base->CLB_FSM_EXTRA_IN0    = extra0;
    base->CLB_FSM_EXTRA_IN1    = extra1;
}

/*!
 * \brief Configures FSM LUT function.
 *
 * \details  This function configures the FSM block's LUT equations.
 * \param[in] base is the base address of a CLB tile's logic config register.
 * \param[in] fsmLutFn10 is the value for FSM 0 & FSM 1 LUT function.
 * \param[in] fsmLutFn2 is the value for FSM 2 LUT function.
 *
 */
static inline void CLB_configFSMLUTFunction(CLB_TILE_Type *base, uint32_t fsmLutFn10, uint32_t fsmLutFn2)
{
    assert(CLB_isBaseValid(base));

    base->CLB_FSM_LUT_FN1_0 = fsmLutFn10;
    base->CLB_FSM_LUT_FN2   = fsmLutFn2;
}

/*!
 * \brief Configures FSM next state.
 *
 * \details  This function configures the FSM's next state equation.
 * \param[in] base is the base address of a CLB tile's logic config register.
 * \param[in] nextState0 is the value for FSM 0's next state.
 * \param[in] nextState1 is the value for FSM 1's next state.
 * \param[in] nextState2 is the value for FSM 2's next state.
 *
 */
static inline void CLB_configFSMNextState(CLB_TILE_Type *base, uint32_t nextState0, uint32_t nextState1,
                                          uint32_t nextState2)
{
    assert(CLB_isBaseValid(base));

    base->CLB_FSM_NEXT_STATE_0 = nextState0;
    base->CLB_FSM_NEXT_STATE_1 = nextState1;
    base->CLB_FSM_NEXT_STATE_2 = nextState2;
}

/*!
 * \brief Selects Counter inputs.
 *
 * \details  This function selects the input signals to the counter block.
 * \param[in] base is the base address of a CLB tile's logic config register.
 * \param[in] reset is the value for counter's reset inputs.
 * \param[in] event is the value for counter's event inputs.
 * \param[in] mode0 is the value for counter's mode 0 inputs.
 * \param[in] mode1 is the value for counter's mode 1 inputs.
 *
 */
static inline void CLB_selectCounterInputs(CLB_TILE_Type *base, uint32_t reset, uint32_t event, uint32_t mode0,
                                           uint32_t mode1)
{
    assert(CLB_isBaseValid(base));

    base->CLB_COUNT_RESET  = reset;
    base->CLB_COUNT_EVENT  = event;
    base->CLB_COUNT_MODE_0 = mode0;
    base->CLB_COUNT_MODE_1 = mode1;
}

/*!
 * \brief Configures Counter and FSM modes.
 *
 * \details  This function configures the counter mode, particularly add/shift, load
 *           modes. The function also configures whether the FSM should use state inputs
 *           or an extra external input.
 * \param[in] base is the base address of a CLB tile's logic config register.
 * \param[in] miscCtrl is the value to represent counter and FSM modes.
 *
 */
static inline void CLB_configMiscCtrlModes(CLB_TILE_Type *base, uint32_t miscCtrl)
{
    assert(CLB_isBaseValid(base));

    base->CLB_MISC_CONTROL = miscCtrl;
}

/*!
 * \brief Configures Output LUT functions.
 *
 * \details This function configures the input signals and equations of the output LUT
 *          corresponding to the /e outID parameter.
 *
 * \param[in] base is the base address of a CLB tile's logic config register.
 * \param[in] outID is the specified CLB tile output signal.
 * \param[in] outputCfg is the value for the output LUT signal function and input
 *            signal selections.
 *
 */
static inline void CLB_configOutputLUT(CLB_TILE_Type *base, CLB_Output_t outID, uint32_t outputCfg)
{
    assert(CLB_isBaseValid(base));

    switch (outID)
    {
        case kCLB_OUT0:
            base->CLB_OUTPUT_LUT_0 = outputCfg;
            break;
        case kCLB_OUT1:
            base->CLB_OUTPUT_LUT_1 = outputCfg;
            break;
        case kCLB_OUT2:
            base->CLB_OUTPUT_LUT_2 = outputCfg;
            break;
        case kCLB_OUT3:
            base->CLB_OUTPUT_LUT_3 = outputCfg;
            break;
        case kCLB_OUT4:
            base->CLB_OUTPUT_LUT_4 = outputCfg;
            break;
        case kCLB_OUT5:
            base->CLB_OUTPUT_LUT_5 = outputCfg;
            break;
        case kCLB_OUT6:
            base->CLB_OUTPUT_LUT_6 = outputCfg;
            break;
        case kCLB_OUT7:
            base->CLB_OUTPUT_LUT_7 = outputCfg;
            break;
        default:
            break;
    }
}

/*!
 * \brief Configures Counter TAP Selects.
 *
 * \details This function configures the counter tap selects.
 *
 * \param[in] base is the base address of a CLB tile's logic config register.
 * \param[in] tapSel is the value to represent counter tap selects.
 *
 */
static inline void CLB_configCounterTapSelects(CLB_TILE_Type *base, uint32_t tapSel)
{
    assert(CLB_isBaseValid(base));

    base->CLB_COUNT_MATCH_TAP_SEL = tapSel;
}

/*!
 * \brief Configures AOC (Asynchronous Output Conditioning) functions.
 *
 * \details This function configures the input signals and equations of the aoc LUT
 *          corresponding to the /e aocID parameter.
 *
 * \param[in] base is the base address of a CLB tile's logic config register.
 * \param[in] aocID is the specified CLB tile AOC signal.
 * \param[in] aocCfg is the value for the AOC signal function and input signal selections.
 *
 */
static inline void CLB_configAOC(CLB_TILE_Type *base, CLB_AOC_t aocID, uint32_t aocCfg)
{
    assert(CLB_isBaseValid(base));

    switch (aocID)
    {
        case kCLB_AOC0:
            base->CLB_OUTPUT_COND_CTRL_0 = aocCfg;
            break;
        case kCLB_AOC1:
            base->CLB_OUTPUT_COND_CTRL_1 = aocCfg;
            break;
        case kCLB_AOC2:
            base->CLB_OUTPUT_COND_CTRL_2 = aocCfg;
            break;
        case kCLB_AOC3:
            base->CLB_OUTPUT_COND_CTRL_3 = aocCfg;
            break;
        case kCLB_AOC4:
            base->CLB_OUTPUT_COND_CTRL_4 = aocCfg;
            break;
        case kCLB_AOC5:
            base->CLB_OUTPUT_COND_CTRL_5 = aocCfg;
            break;
        case kCLB_AOC6:
            base->CLB_OUTPUT_COND_CTRL_6 = aocCfg;
            break;
        case kCLB_AOC7:
            base->CLB_OUTPUT_COND_CTRL_7 = aocCfg;
            break;
        default:
            break;
    }
}

/*!
 * \brief Configures HLC event selection.
 *
 * \details  This function configures the event selection for the High Level Controller.
 *
 * \param[in] base is the base address of a CLB tile's logic config register.
 * \param[in] eventSel is the value for HLC event selection.
 *
 */
static inline void CLB_configHLCEventSelect(CLB_TILE_Type *base, uint32_t eventSel)
{
    assert(CLB_isBaseValid(base));

    base->CLB_HLC_EVENT_SEL = eventSel;
}

/*!
 * \brief Program HLC instruction.
 *
 * \details This function configures the CLB internal memory corresponding to the
 *          specified HLC instruction number with the given instruction.
 *
 * \param[in] base is the base address of a CLB tile's logic config register.
 * \param[in] instructionNum is the index into the HLC instruction memory.
 * \param[in] instruction is the instruction to be programmed.
 *
 */
static inline void CLB_programHLCInstruction(CLB_TILE_Type *base, uint32_t instructionNum, uint32_t instruction)
{
    assert(CLB_isBaseValid(base));

    CLB_writeInterface(base, CLB_HLC_INSTR_OFFSET + instructionNum, instruction);
}

/*!
 * \brief Set HLC registers.
 *
 * \details This function configures the CLB internal memory corresponding to the HLC
 *           registers R0-R3 with the specified values.
 * \param[in] base is the base address of a CLB tile's logic config register.
 * \param[in] r0Init is the value to write to HLC register R0.
 * \param[in] r1Init is the value to write to HLC register R1.
 * \param[in] r2Init is the value to write to HLC register R2.
 * \param[in] r3Init is the value to write to HLC register R3.
 *
 */
static inline void CLB_setHLCRegisters(CLB_TILE_Type *base, uint32_t r0Init, uint32_t r1Init, uint32_t r2Init,
                                       uint32_t r3Init)
{
    assert(CLB_isBaseValid(base));

    CLB_writeInterface(base, CLB_ADDR_HLC_R0, r0Init);
    CLB_writeInterface(base, CLB_ADDR_HLC_R1, r1Init);
    CLB_writeInterface(base, CLB_ADDR_HLC_R2, r2Init);
    CLB_writeInterface(base, CLB_ADDR_HLC_R3, r3Init);
}

/*!
 * \brief Get HLC or counter register values.
 *
 * \details This function Get HLC or counter register values.
 *
 * \param[in] base is the base address of a CLB tile's logic config register.
 * \param[in] registerID is the internal register from which to read.
 *
 * \return Returns the value in the specified HLC register or counter.
 */
static inline uint32_t CLB_getRegister(CLB_TILE_Type *base, CLB_Register_t registerID)
{
    assert(CLB_isBaseValid(base));

    uint32_t regVal;

    switch (registerID)
    {
        case kCLB_REG_HLC_R0:
            regVal = base->CLB_DBG_R0;
            break;
        case kCLB_REG_HLC_R1:
            regVal = base->CLB_DBG_R1;
            break;
        case kCLB_REG_HLC_R2:
            regVal = base->CLB_DBG_R2;
            break;
        case kCLB_REG_HLC_R3:
            regVal = base->CLB_DBG_R3;
            break;
        case kCLB_REG_CTR_C0:
            regVal = base->CLB_DBG_C0;
            break;
        case kCLB_REG_CTR_C1:
            regVal = base->CLB_DBG_C1;
            break;
        case kCLB_REG_CTR_C2:
            regVal = base->CLB_DBG_C2;
            break;
        default:
            break;
    }

    return regVal;
}

/*!
 * \brief Get output status.
 *
 * \details This function Get output status.
 *
 * \param[in] base is the base address of a CLB tile's logic config register.
 * \return Returns the output status of various components within the CLB tile
 *
 */
static inline uint32_t CLB_getOutputStatus(CLB_TILE_Type *base)
{
    assert(CLB_isBaseValid(base));

    return (base->CLB_DBG_OUT);
}

/*!
 * \brief disable output mask updates.
 *
 * \details This function disable output mask updates.
 *
 * \param[in] base is the base address of a CLB tile's logic config register.
 *
 */
static inline void CLB_disableOutputMaskUpdates(CLB_TILE_Type *base)
{
    assert(CLB_isBaseValid(base));

    base->CLB_MISC_ACCESS_CTRL |= CLB_TILE_CLB_MISC_ACCESS_CTRL_BLKEN_Set(1U);
}

/*!
 * \brief enable output mask updates.
 *
 * \details This function enable output mask updates.
 *
 * \param[in] base is the base address of a CLB tile's logic config register.
 *
 */
static inline void CLB_enableOutputMaskUpdates(CLB_TILE_Type *base)
{
    assert(CLB_isBaseValid(base));

    base->CLB_MISC_ACCESS_CTRL &= ~CLB_TILE_CLB_MISC_ACCESS_CTRL_BLKEN_Set(1U);
}


/*!
 * \brief Configures Counter load and match.
 *
 * \details This function configures the CLB internal memory corresponding to the
 *          counter block's load and match values.
 *
 * \param[in] base is the base address of a CLB tile's logic config register.
 * \param[in] counterID is the specified counter unit.
 * \param[in] load is the value for counter's load mode.
 * \param[in] match1 is the value for counter's match 1.
 * \param[in] match2 is the value for counter's match 2.
 *
 */
extern void CLB_configCounterLoadMatch(CLB_TILE_Type *base, CLB_Counter_t counterID, uint32_t load, uint32_t match1,
                                       uint32_t match2);


/*!
 * \brief Clear FIFO registers.
 *
 * \details This function clears the PUSH/PULL FIFOs as well as its pointers.
 *
 * \param[in] base is the base address of a CLB tile's logic config register.
 *
 */
extern void CLB_clearFIFOs(CLB_TILE_Type *base);


/*!
 * \brief Configure the FIFO registers.
 *
 * \details This function writes to the PULL FIFO. This also clears the FIFOs and
 *          its pointer using the CLB_clearFIFOs() API prior to writing to the FIFO
 *
 * \param[in] base is the base address of a CLB tile's logic config register.
 * \param[in] pullData[] is a pointer to an array of bytes which needs to be
 *            written into the FIFO. The 0th FIFO data is in the 0th index.
 *
 */
extern void CLB_writeFIFOs(CLB_TILE_Type *base, const uint32_t pullData[]);


/*!
 * \brief Read FIFO registers.
 * \details This function reads from the PUSH FIFO. The 0th FIFO data would be in
 *          the 0th index.
 *
 * \param[in] base is the base address of a CLB tile's logic config register.
 * \param[in] pushData[] is a pointer to an array of bytes which needs to be
 *            read from the FIFO.
 *
 */
extern void CLB_readFIFOs(CLB_TILE_Type *base, uint32_t pushData[]);

/*!
 * \brief Register user callback function to a specified CLB
 *
 * \details This function registers user callback function for CLB which uses IRQ. The relative IRQ
 will be enabled in the NVIC and the priority will be configured at the same time

 * \param[in] intsrc CLB index
 * \param[in] callback CLB user callback
 * \param[in] priority IRQ priority
 *
 * \retval kSTATUS_SUCESS Success to the operation
 * \retval kSTATUS_FAIL Register to a CLB CH which has been registered already. Need to call \ref
 CLB_unregisterCallback() before the re-registration
 */
status_t CLB_registerCallback(CLB_IntSrc_t intsrc, CLB_Callback_t callback, uint32_t priority);


/*!
 * \brief Unregister user callback function to CLB transfer
 *
 * \details This function clears the registered user callback function, and disable the relative IRQ in the NVIC
 *
 * \param[in] intsrc the CLB INT index
 * \retval kSTATUS_SUCESS Success to the operation
 * \retval kSTATUS_INVALID_ARGUMENT The CLB hasn't been registered to a callback
 */
status_t CLB_unregisterCallback(CLB_IntSrc_t intsrc);

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */ /* end of DRV_HTE_CLB */

#endif /* HTE_CLB_H */
