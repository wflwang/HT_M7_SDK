/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*
 *
 * \file eqep_ex2_calculation.h
 *
 * \brief Position and Speed Measurement Using eQEP (Calculations)
 *
 */


#ifndef EQEP_EX2_CALCULATION_H
#define EQEP_EX2_CALCULATION_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_common.h"
#include "hte_eqep.h"
#include "IQmathLib.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
typedef struct {
    int16_t thetaElec;      // Output: Motor electrical angle (Q15)
    int16_t thetaMech;      // Output: Motor mechanical angle (Q15)
    int16_t directionQEP;   // Output: Motor rotation direction (Q0)
    int16_t thetaRaw;       // Variable: Raw angle from timer 2 (Q0)
    int16_t mechScaler;     // Parameter: 0.9999 / total count,
                            //            total count = 4000 (Q26)
    int16_t polePairs;      // Parameter: Number of pole pairs (Q0)
    int16_t calAngle;       // Parameter: Raw angular offset between encoder
                            //            and Phase A (Q0)

    uint32_t speedScaler;   // Parameter: Scaler converting 1/N cycles to a
                            //            GLOBAL_Q speed (Q0) - independently
                            //            with global Q
    _iq speedPR;            // Output: Speed in per-unit
    uint32_t baseRPM;       // Parameter: Scaler converting GLOBAL_Q speed to
                            //            rpm (Q0) speed - independently with
                            //            global Q
    int16_t speedRPMPR;     // Output: Speed in rpm (Q0) - independently with
                            //         global Q

    _iq oldPos;
    _iq speedFR;            // Output: Speed in per-unit
    int16_t speedRPMFR;     // Output: Speed in rpm (Q0) - independently with
                            //         global Q
} PosSpeed_Object;

typedef PosSpeed_Object *PosSpeed_Handle;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void PosSpeed_calculate(PosSpeed_Handle, uint32_t*);

#endif  /* EQEP_EX2_CALCULATION_H */

