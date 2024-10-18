/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_xbar.c
 * \brief SDK XBAR driver source file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_xbar.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* No Definitions */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/* No Prototypes */

/*******************************************************************************
 * Variables
 ******************************************************************************/
/* No Variables */

/*******************************************************************************
 * Codes
 ******************************************************************************/
#if defined(HTE_FEATURE_XBAR_COUNT) && HTE_FEATURE_XBAR_COUNT
bool XBAR_getInputFlagStatus(XBAR_Type *base, XBAR_InputFlag_t inputFlag)
{
    assert(base);

    volatile uint32_t *flagReg = NULL;

    switch (XBAR_INPUTFLAG_INDEX_Get(inputFlag.U))
    {
        case kXBAR_FLAG1:
            flagReg = &base->XBARFLG1;
            break;
        case kXBAR_FLAG2:
            flagReg = &base->XBARFLG2;
            break;
        case kXBAR_FLAG3:
            flagReg = &base->XBARFLG3;
            break;
        case kXBAR_FLAG4:
            flagReg = &base->XBARFLG4;
            break;
        case kXBAR_FLAG5:
            flagReg = &base->XBARFLG5;
            break;
        default:
            /* Invalid argument */
            assert(0);
            break;
    }

    if (flagReg != NULL)
    {
        return ((*flagReg & (1U << XBAR_INPUTFLAG_SHIFT_Get(inputFlag.U))) != 0U);
    }
    else
    {
        /* return false for invalid argument */
        return false;
    }
}

void XBAR_clearInputFlag(XBAR_Type *base, XBAR_InputFlag_t inputFlag)
{
    assert(base);

    volatile uint32_t *clrReg = NULL;

    switch (XBAR_INPUTFLAG_INDEX_Get(inputFlag.U))
    {
        case kXBAR_FLAG1:
            clrReg = &base->XBARCLR1;
            break;
        case kXBAR_FLAG2:
            clrReg = &base->XBARCLR2;
            break;
        case kXBAR_FLAG3:
            clrReg = &base->XBARCLR3;
            break;
        case kXBAR_FLAG4:
            clrReg = &base->XBARCLR4;
            break;
        case kXBAR_FLAG5:
            clrReg = &base->XBARCLR5;
            break;
        default:
            /* Invalid argument */
            assert(0);
            break;
    }

    if (clrReg != NULL)
    {
        *clrReg |= 1U << XBAR_INPUTFLAG_SHIFT_Get(inputFlag.U);
    }
}
#endif /* HTE_FEATURE_XBAR_COUNT */

#if defined(HTE_FEATURE_EPWM_XBAR_COUNT) && HTE_FEATURE_EPWM_XBAR_COUNT
void XBAR_setEPWMMuxConfig(EPWM_XBAR_Type *base, XBAR_TripNum_t trip, XBAR_EPWMMuxConfig_t muxConfig)
{
    assert(base);

    uint32_t           index = XBAR_MUXCONFIG_INDEX_Get(muxConfig.U);
    uint32_t           mux, mask;
    volatile uint32_t *muxReg;

    if (index < XBAR_EPWM_MUX_PER_WORD)
    {
        mux    = XBAR_MUXCONFIG_MUX_Get(muxConfig.U) << (index * 2U);
        mask   = 0x3U << (index * 2U);
        muxReg = &base->TRIPMUX[trip].MUX0TO15CFG;
    }
    else
    {
        mux    = XBAR_MUXCONFIG_MUX_Get(muxConfig.U) << ((index - XBAR_EPWM_MUX_PER_WORD) * 2U);
        mask   = 0x3U << ((index - XBAR_EPWM_MUX_PER_WORD) * 2U);
        muxReg = &base->TRIPMUX[trip].MUX16TO31CFG;
    }

    *muxReg = (*muxReg & (~mask)) | mux;
}
#endif /* HTE_FEATURE_EPWM_XBAR_COUNT */

#if defined(HTE_FEATURE_CLB_XBAR_COUNT) && HTE_FEATURE_CLB_XBAR_COUNT
void XBAR_setCLBMuxConfig(CLB_XBAR_Type *base, XBAR_AuxSigNum_t aux, XBAR_CLBMuxConfig_t muxConfig)
{
    assert(base);

    uint32_t           index = XBAR_MUXCONFIG_INDEX_Get(muxConfig.U);
    uint32_t           mux, mask;
    volatile uint32_t *muxReg;

    if (index < XBAR_CLB_MUX_PER_WORD)
    {
        mux    = XBAR_MUXCONFIG_MUX_Get(muxConfig.U) << (index * 2U);
        mask   = 0x3U << (index * 2U);
        muxReg = &base->AUXSIGMUX[aux].MUX0TO15CFG;
    }
    else
    {
        mux    = XBAR_MUXCONFIG_MUX_Get(muxConfig.U) << ((index - XBAR_EPWM_MUX_PER_WORD) * 2U);
        mask   = 0x3U << ((index - XBAR_EPWM_MUX_PER_WORD) * 2U);
        muxReg = &base->AUXSIGMUX[aux].MUX16TO31CFG;
    }

    *muxReg = (*muxReg & (~mask)) | mux;
}
#endif /* HTE_FEATURE_CLB_XBAR_COUNT */

#if defined(HTE_FEATURE_OUTPUT_XBAR_COUNT) && HTE_FEATURE_OUTPUT_XBAR_COUNT
void XBAR_setOutputMuxConfig(OUTPUT_XBAR_Type *base, XBAR_OutputNum_t output, XBAR_OutputMuxConfig_t muxConfig)
{
    assert(base);

    uint32_t           index = XBAR_MUXCONFIG_INDEX_Get(muxConfig.U);
    uint32_t           mux, mask;
    volatile uint32_t *muxReg;

    if (index < XBAR_OUTPUT_MUX_PER_WORD)
    {
        mux    = XBAR_MUXCONFIG_MUX_Get(muxConfig.U) << (index * 2U);
        mask   = 0x3U << (index * 2U);
        muxReg = &base->OUTPUTMUX[output].MUX0TO15CFG;
    }
    else
    {
        mux    = XBAR_MUXCONFIG_MUX_Get(muxConfig.U) << ((index - XBAR_EPWM_MUX_PER_WORD) * 2U);
        mask   = 0x3U << ((index - XBAR_EPWM_MUX_PER_WORD) * 2U);
        muxReg = &base->OUTPUTMUX[output].MUX16TO31CFG;
    }

    *muxReg = (*muxReg & (~mask)) | mux;
}
#endif /* HTE_FEATURE_OUTPUT_XBAR_COUNT */
