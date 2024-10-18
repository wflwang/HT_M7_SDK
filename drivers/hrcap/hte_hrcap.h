/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_hrcap.h
 * \brief SDK HRCAP driver header file
 * \version 1.0.0
 */

#ifndef HTE_HRCAP_H
#define HTE_HRCAP_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_common.h"

/*!
 * \addtogroup DRV_HTE_HRCAP HRCAP Driver
 *
 * \brief SDK HRCAP drivers
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * \brief Values that can be passed to HRCAP_setCalibrationMode(),
 * as the \e mode parameter.
 */
typedef enum
{
    kHRCAP_ONESHOT = 0x0, /*!< One-shot calibration triggered by software. */
    kHRCAP_PRD     = 0x1, /*!< Periodical calibration triggered by hardware. */
    kHRCAP_AUTO    = 0x2  /*!< Auto calibration when an input edge is detected. */
} HRCAP_CalibrationMode_t;

/*******************************************************************************
 * APIs
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Checks HRCAP base address.
 *
 * \details This function determines if an HRCAP module base address is valid.
 *
 * \param[in] base specifies the HRCAP module base address.
 *
 * \retval true if the base address is valid.
 * \retval false if the base address is invalid.
 *
 */
static inline bool HRCAP_isBaseValid(HRCAP_Type *base)
{
    return ((base == HRCAP1) || (base == HRCAP2));
}

/*!
 * \brief enables HRCAP.
 *
 * \details This function enables High Resolution Capture module.
 *
 * \note High resolution clock must be enabled before High Resolution Module
 *       is enabled.
 *
 * \param[in] base is the base address of the HRCAP instance used.
 *
 *
 */
static inline void HRCAP_enableHighResolution(HRCAP_Type *base)
{
    assert(HRCAP_isBaseValid(base));

    /* Set HRCAP_EN bit. */
    base->HRCTL |= HRCAP_HRCTL_HRCAP_EN_Set(1);
}

/*!
 * \brief Disables HRCAP.
 *
 * \details This function disable High Resolution Capture module.
 *
 * \param[in] base is the base address of the HRCAP instance used.
 *
 *
 */
static inline void HRCAP_disableHighResolution(HRCAP_Type *base)
{
    assert(HRCAP_isBaseValid(base));

    /* Set HRCAP_EN bit. */
    base->HRCTL &= ~(HRCAP_HRCTL_HRCAP_EN_Set(1));
}

/*!
 * \brief enables calibration.
 *
 *
 * \details This function enables calibration.
 *
 * \param[in] base is the base address of the HRCAP instance used.
 *
 */
static inline void HRCAP_enableCalibration(HRCAP_Type *base)
{
    assert(HRCAP_isBaseValid(base));

    /* Set CALI_EN bit. */
    base->HRCALICTL |= HRCAP_HRCALICTL_CALI_EN_Set(1);
}

/*!
 * \brief disables calibration.
 *
 * \details This function disables calibration.
 *
 * \param[in] base is the base address of the HRCAP instance used.
 *
 *
 */
static inline void HRCAP_disableCalibration(HRCAP_Type *base)
{
    assert(HRCAP_isBaseValid(base));

    /* Set CALI_EN bit. */
    base->HRCALICTL &= ~(HRCAP_HRCALICTL_CALI_EN_Set(1));
}

/*!
 * \brief Sets the calibration mode.
 *
 * \details This function sets the the calibration mode.
 *
 * \param[in] base is the base address of the HRCAP instance used.
 * \param[in] mode is the calibration mode.
 *
 *
 */
static inline void HRCAP_setCalibrationMode(HRCAP_Type *base, HRCAP_CalibrationMode_t mode)
{
    assert(HRCAP_isBaseValid(base));

    /* Write to CALI_MOD bits. */
    base->HRCALICTL = ((base->HRCALICTL) & (~HRCAP_HRCALICTL_CALI_MOD_Msk)) | HRCAP_HRCALICTL_CALI_MOD_Set(mode);
}

/*!
 * \brief starts a calibration.
 *
 * \details This function starts a calibration when the oneshot
 * calibration mode is set.
 *
 * \param[in] base is the base address of the HRCAP instance used.
 *
 *
 */
static inline void HRCAP_startOneshotCalibration(HRCAP_Type *base)
{
    assert(HRCAP_isBaseValid(base));
    assert(HRCAP_HRCALICTL_CALI_MOD_Get(base->HRCALICTL) == 0);

    base->HRCALICTL |= HRCAP_HRCALICTL_CALI_TRIG_Set(1);
}

/*!
 * \brief sets the calibration interval cycle.
 *
 * \details This function sets the interval between two calibrations when the
 * periodical calibration mode is set.
 *
 * \param[in] base is the base address of the HRCAP instance used.
 * \param[in] period is the interval between two calibrations.
 *
 *
 */
static inline void HRCAP_setCalibrationPeriod(HRCAP_Type *base, uint32_t period)
{
    assert(HRCAP_isBaseValid(base));

    base->CALI_INTERVAL = period;
}

/*!
 * \brief gets the data in the register HRCAP_DATA_H.
 *
 * \details This function gets the data in the register HRCAP_DATA_H.
 *
 * \param[in] base is the base address of the HRCAP module.
 *
 * \retval the data in the register HRCAP_DATA_H
 *
 */
static inline uint32_t HRCAP_getCapDataH(HRCAP_Type *base)
{
    assert(HRCAP_isBaseValid(base));
    return HRCAP_HRCAP_DATA_H_HRCAP_CAP_DATA_H_Get(base->HRCAP_DATA_H);
}

/*!
 * \brief gets the data in the register HRCAP_DATA_L.
 *
 * \details This function gets the data in the register HRCAP_DATA_L.
 *
 * \param[in] base is the base address of the HRCAP module.
 *
 * \retval the data in the register HRCAP_DATA_L
 *
 */
static inline uint32_t HRCAP_getCapDataL(HRCAP_Type *base)
{
    assert(HRCAP_isBaseValid(base));
    return HRCAP_HRCAP_DATA_L_HRCAP_CAP_DATA_L_Get(base->HRCAP_DATA_L);
}

/*!
 * \brief gets the data in the register CALI_DATA_H.
 *
 * \details This function gets the data in the register CALI_DATA_H.
 *
 * \param[in] base is the base address of the HRCAP module.
 *
 * \retval the data in the register CALI_DATA_H
 *
 */
static inline uint32_t HRCAP_getCaliDataH(HRCAP_Type *base)
{
    assert(HRCAP_isBaseValid(base));
    return HRCAP_CALI_DATA_H_HRCAP_CALI_DATA_H_Get(base->CALI_DATA_H);
}

/*!
 * \brief gets the data in the register CALI_DATA_L.
 *
 * \details This function gets the data in the register CALI_DATA_L.
 *
 * \param[in] base is the base address of the HRCAP module.
 *
 * \retval the data in the register CALI_DATA_L
 *
 */
static inline uint32_t HRCAP_getCaliDataL(HRCAP_Type *base)
{
    assert(HRCAP_isBaseValid(base));
    return HRCAP_CALI_DATA_L_HRCAP_CALI_DATA_L_Get(base->CALI_DATA_L);
}

/*!
 *
 * \brief Enables calibration done interrupt.
 *
 * \details This function enables HRCAP calibration done interrupt.
 *
 * \param[in] base is the base address of the HRCAP module.
 *
 *
 */
static inline void HRCAP_enableCalibrationInterrupt(HRCAP_Type *base)
{
    assert(HRCAP_isBaseValid(base));

    /* Set CALI_DONE. */
    base->HRCAP_IE |= HRCAP_HRCAP_IE_HRCAP_CALI_DONE_IE_Set(1);
}

/*!
 * \brief Disables calibration done interrupt.
 *
 * \details This function disables HRCAP calibration done interrupt flag.
 *
 * \param[in] base is the base address of the HRCAP module.
 *
 *
 */
static inline void HRCAP_disableCalibrationInterrupt(HRCAP_Type *base)
{
    assert(HRCAP_isBaseValid(base));

    /* Clear CALIB_DONE. */
    base->HRCAP_IE &= ~(HRCAP_HRCAP_IE_HRCAP_CALI_DONE_IE_Set(1));
}

/*!
 * \brief Returns the calibration done flag.
 *
 * \details This function returns the HRCAP calibration done flag.
 *
 * \param[in] base is the base address of the HRCAP module.
 *
 * \retval true if the calibration is done.
 * \retval false if the calibration is not done.
 */
static inline bool HRCAP_getCalibrationDoneFlag(HRCAP_Type *base)
{
    assert(HRCAP_isBaseValid(base));

    /* Return contents of HRCAP_FLG register. */
    return ((bool)(HRCAP_HRCAP_FLG_HRCAP_CALI_DONE_Get(base->HRCAP_FLG)));
}

/*!
 * \brief Clears calibration done flags.
 *
 * \details This function clears HRCAP calibration done flag.
 *
 * \param[in] base is the base address of the HRCAP module.
 *
 *
 */
static inline void HRCAP_clearCalibrationDoneFlag(HRCAP_Type *base)
{
    assert(HRCAP_isBaseValid(base));

    /* Write to HRCLR register. */
    base->HRCAP_FLG_CLR |= HRCAP_HRCAP_FLG_CLR_HRCAP_CALI_DONE_CLR_Set(1);
}

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */ /* end of DRV_HTE_HRCAP */

#endif /* HTE_HRCAP_H */
