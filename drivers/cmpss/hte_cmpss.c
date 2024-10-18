/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_cmpss.c
 * \brief SDK CMPSS driver source file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_cmpss.h"
#include "hte_calib.h"

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
/*! \brief Array of CMPSS peripheral base address */
CMPSS_Type * const s_cmpssBases[] = CMPSS_BASES;

/*! \brief CMPSS trim data */
CMPSS_EflashTrimValue_t s_cmpssTrimData = { 0 };

/*******************************************************************************
 * Codes
 ******************************************************************************/
uint32_t CMPSS_getInstance(CMPSS_Type *base)
{
    uint32_t instance = 0U;
    for (; instance < ARRAY_SIZE(s_cmpssBases); instance++)
    {
        if (base == s_cmpssBases[instance])
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_cmpssBases));
    return instance;
}

void CMPSS_configFilterHigh(CMPSS_Type *base, uint16_t samplePrescale, uint16_t sampleWindow, uint16_t threshold)
{
    uint16_t regValue;
    uint16_t msk;

    /* Check the arguments.*/
    assert(CMPSS_isBaseValid(base));
    assert(samplePrescale <= 1023U);
    assert((sampleWindow >= 1U) && (sampleWindow <= 32U));
    assert((threshold - 1U) >= ((sampleWindow - 1U) / 2U));

    /* Shift the sample window and threshold values into the correct positions
        and write them to the appropriate register. */
    msk      = CMPSS_CTRIPHFILCTL_SAMPWIN_Msk | CMPSS_CTRIPHFILCTL_THRESH_Msk;
    regValue = CMPSS_CTRIPHFILCTL_SAMPWIN_Set(sampleWindow - 1U) | CMPSS_CTRIPHFILCTL_THRESH_Set(threshold - 1U);

    base->CTRIPHFILCTL = (base->CTRIPHFILCTL & (~msk)) | regValue;

    /*Set the filter sample clock prescale for the high comparator.*/
    base->CTRIPHFILCLKCTL = (samplePrescale > 0) ? (samplePrescale - 1) : (samplePrescale);
}

void CMPSS_configFilterLow(CMPSS_Type *base, uint16_t samplePrescale, uint16_t sampleWindow, uint16_t threshold)
{
    uint16_t regValue;
    uint16_t msk;

    /* Check the arguments.*/
    assert(CMPSS_isBaseValid(base));
    assert(samplePrescale <= 1023U);
    assert((sampleWindow >= 1U) && (sampleWindow <= 32U));
    assert((threshold - 1U) >= ((sampleWindow - 1U) / 2U));

    /* Shift the sample window and threshold values into the correct positions
        and write them to the appropriate register. */
    msk      = CMPSS_CTRIPLFILCTL_SAMPWIN_Msk | CMPSS_CTRIPLFILCTL_THRESH_Msk;
    regValue = CMPSS_CTRIPLFILCTL_SAMPWIN_Set(sampleWindow - 1U) | CMPSS_CTRIPLFILCTL_THRESH_Set(threshold - 1U);

    base->CTRIPLFILCTL = (base->CTRIPLFILCTL & (~msk)) | regValue;

    /* Set the filter sample clock prescale for the low comparator.*/
    base->CTRIPLFILCLKCTL = (samplePrescale > 0) ? (samplePrescale - 1) : (samplePrescale);
}

void CMPSS_configLatchOnPWMSYNC(CMPSS_Type *base, bool highEnable, bool lowEnable)
{
    /* Check the arguments.*/
    assert(CMPSS_isBaseValid(base));

    /* If the highEnable is true, set the bit that will enable PWMSYNC to reset
      the high comparator digital filter latch. If not, clear the bit.*/
    if (highEnable)
    {
        base->COMPSTSCLR |= CMPSS_COMPSTSCLR_HSYNCCLREN_Set(kCMP_ENABLE);
    }
    else
    {
        base->COMPSTSCLR &= ~CMPSS_COMPSTSCLR_HSYNCCLREN_Msk;
    }

    /* If the lowEnable is true, set the bit that will enable PWMSYNC to reset
         the low comparator digital filter latch. If not, clear the bit.*/
    if (lowEnable)
    {
        base->COMPSTSCLR |= CMPSS_COMPSTSCLR_LSYNCCLREN_Set(kCMP_ENABLE);
    }
    else
    {
        base->COMPSTSCLR &= ~CMPSS_COMPSTSCLR_LSYNCCLREN_Msk;
    }
}

void CMPSS_configRamp(CMPSS_Type *base, uint32_t maxRampVal, uint32_t decrementVal, uint16_t delayVal,
                      uint16_t pwmSyncSrc, bool useRampValShdw)
{
    /* Check the arguments.*/
    assert(CMPSS_isBaseValid(base));
    assert(delayVal <= CMPSS_RAMPDLYS_DELAY_M);
    assert((pwmSyncSrc >= 1U) && (pwmSyncSrc <= 16U));

    /* Write the ramp generator source to the register */
    base->COMPDACCTL =
        (base->COMPDACCTL & (~CMPSS_COMPDACCTL_RAMPSOURCE_Msk)) | CMPSS_COMPDACCTL_RAMPSOURCE_Set(pwmSyncSrc - 1U);

    /* Set or clear the bit that determines from where the max ramp value
       should be loaded.*/
    if (useRampValShdw)
    {
        base->COMPDACCTL |= CMPSS_COMPDACCTL_RAMPLOADSEL_Set(kCMP_ENABLE);
    }
    else
    {
        base->COMPDACCTL &= ~CMPSS_COMPDACCTL_RAMPLOADSEL_Msk;
    }

    /* Write the maximum ramp value to the shadow register. */
    base->RAMPMAXREFS = maxRampVal;

    /* Write the ramp decrement value to the shadow register.*/
    base->RAMPDECVALS = decrementVal;

    /* Write the ramp delay value to the shadow register.*/
    base->RAMPDLYS = delayVal;
}

status_t CMPSS_setHOffsetTrim(CMPSS_Type *base)
{
    int8_t trimValue = 0;

    /* Check the arguments. */
    assert(CMPSS_isBaseValid(base));

    if (CALIB_ERR == CALIB_getCmpCalibration((uint8_t *)&s_cmpssTrimData, sizeof(s_cmpssTrimData)))
    {
        return kSTATUS_FAIL;
    }

    if (s_cmpssTrimData.cmpssCheckData == CMPSS_TRIM_CHECK_DATA)
    {
        trimValue = s_cmpssTrimData.cmpssTrim[CMPSS_getInstance(base) * 2];

        /* Clear High trim and set new data. */
        base->CMPSSTRIM = (base->CMPSSTRIM & (~CMPSS_CMPSSTRIM_HOFFTRIM_Msk)) | CMPSS_CMPSSTRIM_HOFFTRIM_Set(trimValue);
        return kSTATUS_SUCCESS;
    }
    else
    {
        memset((void *)&s_cmpssTrimData, 0, sizeof(s_cmpssTrimData));
        return kSTATUS_FAIL;
    }
}

status_t CMPSS_setLOffsetTrim(CMPSS_Type *base)
{
    int8_t trimValue = 0;

    /* Check the arguments. */
    assert(CMPSS_isBaseValid(base));

    if (CALIB_ERR == CALIB_getCmpCalibration((uint8_t *)&s_cmpssTrimData, sizeof(s_cmpssTrimData)))
    {
        return kSTATUS_FAIL;
    }

    if (s_cmpssTrimData.cmpssCheckData == CMPSS_TRIM_CHECK_DATA)
    {
        trimValue = s_cmpssTrimData.cmpssTrim[CMPSS_getInstance(base) * 2 + 1];

        /* Clear High trim and set new data. */
        base->CMPSSTRIM = (base->CMPSSTRIM & (~CMPSS_CMPSSTRIM_LOFFTRIM_Msk)) | CMPSS_CMPSSTRIM_LOFFTRIM_Set(trimValue);
        return kSTATUS_SUCCESS;
    }
    else
    {
        memset((void *)&s_cmpssTrimData, 0, sizeof(s_cmpssTrimData));
        return kSTATUS_FAIL;
    }
}
