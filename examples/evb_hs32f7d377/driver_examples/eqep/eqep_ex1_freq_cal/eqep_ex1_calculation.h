/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
 
/*
 *
 * \file eqep_ex1_calculation.h
 *
 * \brief Frequency Measurement Using eQEP (Calculations)
 *
 */


#ifndef EQEP_EX1_CALCULATION_H
#define EQEP_EX1_CALCULATION_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_common.h"
#include "hte_eqep.h"
#include "IQmathLib.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
 
typedef struct
{
    uint32_t freqScalerPR;  /* Parameter: Scaler converting 1/N cycles to a     */
                            /* GLOBAL_Q freq (Q0) - independently with global Q */
    uint32_t freqScalerFR;  /* Parameter: Scaler converting 1/N cycles to a     */
                            /* GLOBAL_Q freq (Q0) - independently with global Q */
    uint32_t baseFreq;      /* Parameter: Maximum freq                          */
   
    _iq freqPR;             /* Output: Freq in per-unit using capture unit      */
    int32_t freqHzPR;       /* Output: Freq in Hz, measured using Capture unit  */
    uint32_t oldPos; 

    _iq freqFR;             /* Output: Freq in per-unit using position counter  */
    int32_t freqHzFR;       /* Output: Freq in Hz, measured using Capture unit  */

} FreqCal_Object;

typedef FreqCal_Object *FreqCal_Handle;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
 
void FreqCal_calculate(FreqCal_Handle,uint32_t*);

#endif 
