/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_dac.h
 * \brief SDK DAC driver header file
 * \version 1.0.0
 */

#ifndef HTE_DAC_H
#define HTE_DAC_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_common.h"

/*!
 * \brief SDK DAC driver
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

//
// A 8-bit register mask
//
#define DAC_REG_BYTE_MASK       (0xFFU)   /*!< Register Byte Mask */

//
// Lock Key
//
#define DAC_LOCK_KEY            (0xA000U) /*!< DAC Lock Key */
#ifndef DOXYGEN_PDF_IGNORE

/*!
 * The following are defines for the reg parameter of the
 * DAC_lockRegister() and DAC_isRegisterLocked() functions.
 */
#define DAC_LOCK_CONTROL        (0x1U)    /*!< Lock the control register */
#define DAC_LOCK_SHADOW         (0x2U)    /*!< Lock the shadow value register */
#define DAC_LOCK_OUTPUT         (0x4U)    /*!< Lock the output enable register */

#endif // DOXYGEN_PDF_IGNORE

/*!
 * \brief Defines the mask for the DAC value setting.
 */
#define DAC_VALS_DACVALS_M      (0xFFFU)

/*!
 * \brief Defines the data size for the DAC calibration.
 */
#define DAC_CALIB_DATA_SIZE     (0x5U)

/*!
 *  Enumeration defining indices for multiple DAC channels.
 */
typedef enum
{
    kDAC_IDX_1   = 0U,          /*!< Index for the 1 DAC channel. */
    kDAC_IDX_2   = 1U,          /*!< Index for the 2 DAC channel. */
    kDAC_IDX_3   = 2U,          /*!< Index for the 3 DAC channel. */
    kDAC_IDX_MAX,               /*!< Index for the max number. */
} DAC_Idx_t;

/*!
 *  Values that can be passed to DAC_setReferenceVoltage() as the \e source
 *  parameter.
 */
typedef enum
{
    DAC_REF_VDAC        = 0,  /*!< VDAC reference voltage */
    DAC_REF_ADC_VREFHI  = 1   /*!< ADC VREFHI reference voltage */
} DAC_ReferenceVoltage;

/*!
 *  Values that can be passed to DAC_setLoadMode() as the \e mode parameter.
 */
typedef enum
{
    DAC_LOAD_SYSCLK  = 0,     /*!< Load on next SYSCLK */
    DAC_LOAD_PWMSYNC = 4      /*!< Load on next PWMSYNC specified by SYNCSEL */
} DAC_LoadMode;

/*******************************************************************************
 * APIs
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*!
 *  Checks DAC base address.
 * 
 *  \param base specifies the DAC module base address.
 * 
 *  This function determines if an DAC module base address is valid.
 * 
 *  \return Returns \b true if the base address is valid and \b false
 *  otherwise.
 */
static inline bool
DAC_isBaseValid(DAC_REGS_Type *base)
{
    return(
           (base == DACA) ||
           (base == DACB) ||
           (base == DACC)
          );
}

/*!
 *  Get the DAC Revision value
 * 
 *  \param base is the DAC module base address
 * 
 *  This function gets the DAC revision value.
 * 
 *  \return Returns the DAC revision value.
 */
static inline uint16_t
DAC_getRevision(DAC_REGS_Type *base)
{
    /* Check the arguments. */
    assert(DAC_isBaseValid(base));

    /* Get the revision value. */
    return DAC_REGS_DACREV_REV_Get(base->DACREV);
}

/*!
 *  Sets the DAC Reference Voltage
 * 
 *  \param base is the DAC module base address
 *  \param source is the selected reference voltage
 * 
 *  This function sets the DAC reference voltage.
 * 
 *  The \e source parameter can have one of two values:
 *  - \b DAC_REF_VDAC       - The VDAC reference voltage
 *  - \b DAC_REF_ADC_VREFHI - The ADC VREFHI reference voltage
 */
static inline void
DAC_setReferenceVoltage(DAC_REGS_Type *base, DAC_ReferenceVoltage source)
{
    /* Check the arguments. */
    assert(DAC_isBaseValid(base));

    /* Set the reference  voltage */
    base->DACCTL = (base->DACCTL & ~DAC_REGS_DACCTL_DACREFSEL_Msk) | source;
}

/*!
 *  Sets the DAC Load Mode
 * 
 *  \param base is the DAC module base address
 *  \param mode is the selected load mode
 * 
 *  This function sets the DAC load mode.
 * 
 *  The \e mode parameter can have one of two values:
 *  - \b DAC_LOAD_SYSCLK   - Load on next SYSCLK
 *  - \b DAC_LOAD_PWMSYNC  - Load on next PWMSYNC specified by SYNCSEL
 */
static inline void
DAC_setLoadMode(DAC_REGS_Type *base, DAC_LoadMode mode)
{
    /* Check the arguments. */
    assert(DAC_isBaseValid(base));

    /* Set the load mode */
    base->DACCTL = (base->DACCTL & ~DAC_REGS_DACCTL_LOADMODE_Msk) | mode;
}

/*!
 *  Sets the DAC PWMSYNC Signal
 * 
 *  \param base is the DAC module base address
 *  \param signal is the selected PWM signal
 * 
 *  This function sets the DAC PWMSYNC signal.
 * 
 *  The \e signal parameter must be set to a number that represents the PWM
 *  signal that will be set. For instance, passing 2 into \e signal will
 *  select PWM sync signal 2.
 * 
 */
static inline void
DAC_setPWMSyncSignal(DAC_REGS_Type *base, uint16_t signal)
{
    /* Check the arguments. */
    assert(DAC_isBaseValid(base));
    assert((signal > 0U) && (signal < 17U));

    /* Set the PWM sync signal */
    base->DACCTL = (base->DACCTL & ~DAC_REGS_DACCTL_SYNCSEL_Msk) | 
                    DAC_REGS_DACCTL_SYNCSEL_Set(signal - 1U);
}

/*!
 *  Get the DAC Active Output Value
 * 
 *  \param base is the DAC module base address
 * 
 *  This function gets the DAC active output value.
 * 
 *  \return Returns the DAC active output value.
 */
static inline uint16_t
DAC_getActiveValue(DAC_REGS_Type *base)
{
    /* Check the arguments. */
    assert(DAC_isBaseValid(base));

    /* Get the active value */
    return DAC_REGS_DACVALA_DACVALA_Get(base->DACVALA);
}

/*!
 *  Set the DAC Shadow Output Value
 * 
 *  \param base is the DAC module base address
 *  \param value is the 12-bit code to be loaded into the active value register
 * 
 *  This function sets the DAC shadow output value.
 * 
 */
static inline void
DAC_setShadowValue(DAC_REGS_Type *base, uint16_t value)
{
    /* Check the arguments. */
    assert(DAC_isBaseValid(base));
    assert(value <= DAC_VALS_DACVALS_M);

    /* Set the shadow value */
    base->DACVALS = (base->DACVALS & ~DAC_REGS_DACVALS_DACVALS_Msk) |
                        DAC_REGS_DACVALS_DACVALS_Set(value);
}

/*!
 *  Get the DAC Shadow Output Value
 * 
 *  \param base is the DAC module base address
 * 
 *  This function gets the DAC shadow output value.
 * 
 *  \return Returns the DAC shadow output value.
 */
static inline uint16_t
DAC_getShadowValue(DAC_REGS_Type *base)
{
    /* Check the arguments. */
    assert(DAC_isBaseValid(base));

    /* Get the shadow value */
    return DAC_REGS_DACVALS_DACVALS_Get(base->DACVALS);
}

/*!
 *  Enable the DAC Output
 * 
 *  \param base is the DAC module base address
 * 
 *  This function enables the DAC output.
 * 
 *  \note A delay is required after enabling the DAC. Further details
 *  regarding the exact delay time length can be found in the device datasheet.
 * 
 */
static inline void
DAC_enableOutput(DAC_REGS_Type *base)
{
    /* Check the arguments. */
    assert(DAC_isBaseValid(base));

    /* Enable the output */
    base->DACOUTEN |= DAC_REGS_DACOUTEN_DACOUTEN_Set(1);
}

/*!
 *  Disable the DAC Output
 * 
 *  \param base is the DAC module base address
 * 
 *  This function disables the DAC output.
 * 
 */
static inline void
DAC_disableOutput(DAC_REGS_Type *base)
{
    /* Check the arguments. */
    assert(DAC_isBaseValid(base));

    /* Disable the output */
    base->DACOUTEN &= ~DAC_REGS_DACOUTEN_DACOUTEN_Set(1);
}

/*!
 *  Set DAC Offset Trim
 * 
 *  \param base is the DAC module base address
 *  \param offset is the specified value for the offset trim
 * 
 *  This function sets the DAC offset trim. The \e offset value should be a
 *  signed number in the range of -128 to 127.
 * 
 *  \note The offset should not be modified unless specifically indicated by
 *  Watech Errata or other documentation. Modifying the offset value could cause
 *  this module to operate outside of the datasheet specifications.
 * 
 */
static inline void
DAC_setOffsetTrim(DAC_REGS_Type *base, int16_t offset)
{
    /* Check the arguments. */
    assert(DAC_isBaseValid(base));
    assert((offset > -129) && (offset < 128));

    /* Set the offset trim value */
    base->DACTRIM = (base->DACTRIM & ~DAC_REGS_DACTRIM_OFFSET_TRIM_Msk) |
                        (int16_t)offset;
}

/*!
 *  Get DAC Offset Trim
 * 
 *  \param base is the DAC module base address
 * 
 *  This function gets the DAC offset trim value.
 * 
 *  \return int16_t number.
 */
static inline int16_t 
DAC_getOffsetTrim(DAC_REGS_Type *base)
{
    uint16_t value;

    /* Check the arguments. */
    assert(DAC_isBaseValid(base));

    /* Get the sign-extended offset trim value */
    value = base->DACTRIM & DAC_REGS_DACTRIM_OFFSET_TRIM_Msk;
    value = ((value & (uint16_t)DAC_REG_BYTE_MASK) ^ (uint16_t)0x80) -
            (uint16_t)0x80;

    return((int16_t)value);
}

/*!
 *  Lock write-access to DAC Register
 * 
 *  \param base is the DAC module base address
 *  \param reg is the selected DAC registers
 * 
 *  This function locks the write-access to the specified DAC register. Only a
 *  system reset can unlock the register once locked.
 * 
 *  The \e reg parameter can be an ORed combination of any of the following
 *  values:
 *  - \b DAC_LOCK_CONTROL  - Lock the DAC control register
 *  - \b DAC_LOCK_SHADOW   - Lock the DAC shadow value register
 *  - \b DAC_LOCK_OUTPUT   - Lock the DAC output enable/disable register
 * 
 */
static inline void
DAC_lockRegister(DAC_REGS_Type *base, uint16_t reg)
{
    /* Check the arguments. */
    assert(DAC_isBaseValid(base));
    assert((reg & ~(DAC_LOCK_CONTROL | DAC_LOCK_SHADOW |
                    DAC_LOCK_OUTPUT)) == 0U);

    /* Lock the specified registers */
    base->DACLOCK |= (DAC_LOCK_KEY | reg);
}

/*!
 *  Check if DAC Register is locked
 * 
 *  \param base is the DAC module base address
 *  \param reg is the selected DAC register locks to check
 * 
 *  This function checks if write-access has been locked on the specified DAC
 *  register.
 * 
 *  The \e reg parameter can be an ORed combination of any of the following
 *  values:
 *  - \b DAC_LOCK_CONTROL  - Lock the DAC control register
 *  - \b DAC_LOCK_SHADOW   - Lock the DAC shadow value register
 *  - \b DAC_LOCK_OUTPUT   - Lock the DAC output enable/disable register
 * 
 *  \return Returns \b true if any of the registers specified are locked, and
 *  \b false if all specified registers aren't locked.
 */
static inline bool
DAC_isRegisterLocked(DAC_REGS_Type *base, uint16_t reg)
{
    /* Check the arguments. */
    assert(DAC_isBaseValid(base));
    assert((reg & ~(DAC_LOCK_CONTROL | DAC_LOCK_SHADOW |
                    DAC_LOCK_OUTPUT)) == 0U);

    /* Return the lock status on the specified registers */
    return ((bool)((base->DACLOCK & reg) != 0U));
}

/*!
 *  Tune DAC Offset Trim
 * 
 *  \param base is the DAC module base address
 *  \param referenceVoltage is the reference voltage the DAC
 *  module is operating at.
 * 
 *  This function adjusts/tunes the DAC offset trim. The \e referenceVoltage
 *  value should be a floating point number in the range specified in the
 *  device data manual.
 * 
 *  \note Use this function to adjust the DAC offset trim if operating
 *  at a reference voltage other than 2.5v. Since this function modifies
 *  the DAC offset trim register, it should only be called once after
 *  Device_cal. If it is called multiple times after Device_cal, the offset
 *  value scaled would be the wrong value.
 * 
 */
extern void
DAC_tuneOffsetTrim(DAC_REGS_Type *base, float referenceVoltage);

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */ 

#endif // HTE_DAC_H
