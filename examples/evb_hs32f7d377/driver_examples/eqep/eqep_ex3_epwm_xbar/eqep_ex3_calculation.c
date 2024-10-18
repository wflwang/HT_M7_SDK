/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*
 *
 * \file eqep_ex3_calculation.c
 *
 * \brief Frequency Measurement Using eQEP (Calculations)
 *
 * This file includes the eQEP frequency calculation function called by
 * eqep_ex1_freq_cal.c.  The frequency calculation steps performed by
 * FreqCal_calculate() are described below:
 *
 * 1. This program calculates: **freqHzFR**
 *
 *      freqHzFR or v = (x2 - x1) / T                               -Equation 1
 *
 * If max/base freq = 10kHz:
 *
 *      10kHz = (x2 - x1) / (2 / 100Hz)                             -Equation 2
 *      max (x2 - x1) = 200 counts = freqScalerFR
 *
 * Note: T = 2 / 100Hz. 2 is from (x2 - x1) / 2 because QPOSCNT counts 2 edges
 *       per cycle.
 *
 * If both sides of Equation 2 are divided by 10 kHz, then:
 *
 *      1 = (x2 - x1) / [10kHz * (2 / 100Hz)] where [10kHz * (2 / 100Hz)] = 200
 *
 * Because (x2 - x1) must be < 200 (max), (x2 - x1) / 200 < 1 for all
 * frequencies less than max.
 *
 *      freqFR = (x2 - x1) / 200
 *             = (x2 - x1) / [10kHz * (2 / 100Hz)]                  -Equation 3
 *
 * To get back to original velocity equation, Equation 1, multiply Equation 3
 * by 10 kHz:
 *
 *      freqHzFR = 10kHz * (x2 - x1) / [10kHz * (2 / 100Hz)]
 *               = (x2 - x1) / (2 / 100Hz)                      -Final Equation
 *
 * 2. **min freq** = 1 count / (2 / 100Hz) = 50 Hz
 *
 * 3. **freqHzPR**
 *
 *      freqHzPR or v = X / (t2 - t1)                               -Equation 4
 *
 * If max/base freq = 10kHz:
 *
 *      10kHz = (8 / 2) / T = 8 / 2T
 *
 * where 8 = prescaler selected by QCAPCTL.UPPS (unit time out every 8 edges)
 *       2 = divide by 2 because QPOSCNT counts 2 edges per cycle
 *       T = time in seconds = t2 - t1 / (SYSCLKFREQ / 128)
 *       t2 - t1 = # of QCAPCLK cycles
 *       1 QCAPCLK cycle = 1 / (SYSCLKFREQ / 128) = QCPRDLAT
 *
 * Note: 128 is the prescaler selected by QCAPCTL.CCPS
 *
 * So:
 *
 *      10 kHz  = 8(SYSCLKFREQ / 128) / 2(t2 - t1)
 *      t2 - t1 = 8(SYSCLKFREQ / 128) / (10kHz * 2)
 *              = (SYSCLKFREQ / 128) / (2 * 10kHz / 8)              -Equation 5
 *              = maximum (t2 - t1) = freqScalerPR
 *
 * Divide both sides by (t2 - t1) and:
 *
 *     1 = freqScalerPR / (t2 - t1)
 *       = [(SYSCLKFREQ / 128) / (2 * 10kHz / 8)] / (t2 - t1)
 *
 * Because (t2 - t1) must be < freqScalerPR (max), freqScalerPR / (t2 - t1) < 1
 * for all frequencies less than max.
 *
 *      freqPR = freqScalerPR / (t2 - t1)
 *             = [(SYSCLKFREQ / 128) / (2 * 10kHz / 8)] / (t2 - t1) -Equation 6
 *
 * Now within velocity limits, to get back to original velocity equation,
 * Equation 1, multiply Equation 6 by 10 kHz:
 *
 *      freqHzFR = 10kHz * [(SYSCLKFREQ / 128) / (2 * 10kHz / 8)] / (t2 - t1)
 *               = (SYSCLKFREQ / 128) * 8 / [2 * (t2 - t1)]
 *               = 8 / [2 * (t2 - t1) * QCPRDLAT]               -Final Equation
 *
 *
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "eqep_ex3_calculation.h"


/*******************************************************************************
 * Codes
 ******************************************************************************/
/*
 * FreqCal_calculate - Function to calculate the frequency of the input signal using both the unit
 * timer and the quadrature capture units.
 *
 * For a more detailed explanation of the calculations, read the description at
 * the top of this file.
 */
void
FreqCal_calculate(FreqCal_Object *p, uint32_t *c)
{
    uint32_t temp;
    float ftemp;
    uint32_t newPosCnt, oldPosCnt;

    /*
     *  Frequency calculation using eQEP position counter 
     *
     *  Check for unit time out event
     */
    if((EQEP_getInterruptStatus(EQEP1) & EQEP_INT_UNIT_TIME_OUT) != 0)
    {
        (*c)++; /* Incrementing the count value */
        
        /* Get latched POSCNT value */
        newPosCnt = EQEP_getPositionLatch(EQEP1);
        oldPosCnt = p->oldPos;

        if(newPosCnt > oldPosCnt)
        {
            /* x2 - x1 in v = (x2 - x1) / T equation */
            temp = newPosCnt - oldPosCnt;
        }
        else
        {
            temp = (0xFFFFFFFF - oldPosCnt) + newPosCnt;
        }

        /* p->freqFR = (x2 - x1) / (T * 10kHz) */
        p->freqFR = _IQdiv(temp, p->freqScalerFR);
        ftemp=p->freqFR;

        /* Is freq greater than max freq (10kHz for this example)? */
        if(ftemp >= _IQ(1))
        {
            p->freqFR = _IQ(1);
        }
        else
        {
            p->freqFR = ftemp;
        }

        /*
         * Q0 = Q0 * GLOBAL_Q => _IQXmpy(), X = GLOBAL_Q
         * p->freqHzFR = (p->freqFR) * 10kHz = (x2 - x1) / T
         */
        p->freqHzFR = (int32_t)_IQmpy(p->baseFreq,p->freqFR);

        /* Update old position counter value and clear unit time out flag */
        p->oldPos = newPosCnt;
        EQEP_clearInterruptStatus(EQEP1, EQEP_INT_UNIT_TIME_OUT);
    }

    /*
     * **** Frequency calculation using eQEP capture counter ****
     *
     * Check for unit position event
     */
    if((EQEP_getStatus(EQEP1) & EQEP_STS_UNIT_POS_EVNT) != 0)
    {

        /* No capture overflow */
        if((EQEP_getStatus(EQEP1) & EQEP_STS_CAP_OVRFLW_ERROR) == 0)
        {
            temp = (uint32_t)EQEP_getCapturePeriodLatch(EQEP1);
        }
        else
        {
            /* Capture overflow, saturate the result */
            temp = 0xFFFF;
        }

        /* p->freqPR = X / [(t2 - t1) * 10kHz] */
        p->freqPR = _IQdiv(p->freqScalerPR, temp);
        ftemp = p->freqPR;

        if(ftemp > _IQ(1))
        {
            p->freqPR = _IQ(1);
        }
        else
        {
            p->freqPR = ftemp;
        }

        /*
         * Q0 = Q0 * GLOBAL_Q => _IQXmpy(), X = GLOBAL_Q
         * p->freqHzPR = (p->freqPR) * 10kHz = X / (t2 - t1)
         */
        p->freqHzPR = (int32_t)_IQmpy(p->baseFreq, p->freqPR);

        /* Clear unit position event flag and overflow error flag */
        EQEP_clearStatus(EQEP1, (EQEP_STS_UNIT_POS_EVNT |
                                      EQEP_STS_CAP_OVRFLW_ERROR));
    }
}

/*
 * End of File
 */

