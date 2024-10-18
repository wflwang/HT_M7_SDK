/*
 * Copyright 2023 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*!
 * \file hte_dac.c
 * \brief SDK DAC driver source file
 * \version 1.0.0
 */

#include "hte_dac.h"
#include "hte_calib.h"
//*****************************************************************************
//
// DAC_tuneOffsetTrim()
//
//*****************************************************************************

void
DAC_tuneOffsetTrim(DAC_REGS_Type *base, float referenceVoltage)
{
    /* Check the arguments. */
    assert(DAC_isBaseValid(base));
    assert(referenceVoltage > 0U);

    uint16_t oldOffsetTrim;
    uint8_t dacOffset[DAC_CALIB_DATA_SIZE] = {0};
    uint16_t validData = 0;
    float newOffsetTrim;

    /* Get the sign-extended offset trim value */
    if (CALIB_getDacCalibration(dacOffset, DAC_CALIB_DATA_SIZE))
    {
        validData = *(uint16_t *)dacOffset;
        if (validData != 0x5A5A)
        {
            oldOffsetTrim = 0;
        }
        else
        {
            if (base == DACA)
            {
                oldOffsetTrim = dacOffset[2];
            } 
            else if (base == DACB)
            {
                oldOffsetTrim = dacOffset[3];
            }
            else if (base == DACC)
            {
                oldOffsetTrim = dacOffset[4];
            }       
        }
    }

    /* Calculate new offset trim value if DAC is operating at a reference
       voltage other than 2.5v. */
    newOffsetTrim = ((float)(2.5 / referenceVoltage) *
                     (int16_t)oldOffsetTrim);

    /* Check if the new offset trim value is valid */
    assert(((int16_t)newOffsetTrim > -129) && ((int16_t)newOffsetTrim < 128));

    /* Set the new offset trim value */
    DAC_setOffsetTrim(base, (int16_t)newOffsetTrim);
}

