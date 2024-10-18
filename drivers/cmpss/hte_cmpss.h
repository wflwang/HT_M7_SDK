/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_cmpss.h
 * \brief SDK CMPSS driver header file
 * \version 1.0.0
 */
#ifndef HTE_CMPSS_H
#define HTE_CMPSS_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_common.h"

/*!
 * \addtogroup DRV_HTE_CMPSS CMPSS Driver
 *
 * \brief SDK CMPSS driver
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*!
 * \brief Values that can be passed to CMPSS_configDAC() the config parameter.
 *
 *
 * When is DAC value loaded from shadow register
 */
#define CMPSS_RAMPDLYS_DELAY_M 0x1FFFU /* Ramp Delay Value */

/*!
 * \brief Values that can be passed to CMPSS_configLowComparator() and
 * CMPSS_configHighComparator() as the config parameter.
 */
/*!< Input driven by internal DAC */
#define CMPSS_INSRC_DAC 0x0000U

/*!< Input driven by external pin */
#define CMPSS_INSRC_PIN 0x0001U

/*!< Comparator output is inverted */
#define CMPSS_INV_INVERTED 0x0002U
/*!< Asynch comparator output feeds into OR with latched digital filter output */
#define CMPSS_OR_ASYNC_OUT_W_FILT 0x0040U /*!< digital filter */

/*!
 * \brief Values that can be passed to CMPSS_configOutputsLow() and
 * CMPSS_configOutputsHigh() as the config parameter.
 */
#define CMPSS_TRIPOUT_ASYNC_COMP 0x0000U /*!< Asynchronous comparator output drives CTRIPOUT */
#define CMPSS_TRIPOUT_SYNC_COMP  0x0010U /*!< Synchronous comparator output drives CTRIPOUT */
#define CMPSS_TRIPOUT_FILTER     0x0020U /*!< Filter output drives CTRIPOUT */
#define CMPSS_TRIPOUT_LATCH      0x0030U /*!< Latched filter output drives CTRIPOUT */

/*!
 * \brief Signal driving CTRIP
 */
#define CMPSS_TRIP_ASYNC_COMP 0x0000U /*!< Asynchronous comparator output drives CTRIP */
#define CMPSS_TRIP_SYNC_COMP  0x0004U /*!< Synchronous comparator output drives CTRIP */
#define CMPSS_TRIP_FILTER     0x0008U /*!< Filter output drives CTRIP */
#define CMPSS_TRIP_LATCH      0x000CU /*!< Latched filter output drives CTRIP */

/*!
 * \brief Values that can be returned by CMPSS_getStatus().
 */
#define CMPSS_STS_HI_FILTOUT      0x0001U /*!< High digital filter output */
#define CMPSS_STS_HI_LATCHFILTOUT 0x0002U /*!< Latched value of high digital filter output */
#define CMPSS_STS_LO_FILTOUT      0x0100U /*!< Low digital filter output */
#define CMPSS_STS_LO_LATCHFILTOUT 0x0200U /*!< Latched value of low digital filter output */

/*!
 * \brief Values that can be passed to CMPSS_configDAC() the config parameter.
 */
/* When is DAC value loaded from shadow register */
#define CMPSS_DACVAL_SYSCLK  0x0000U /*!< DAC value updated from SYSCLK */
#define CMPSS_DACVAL_PWMSYNC 0x0080U /*!< DAC value updated from PWMSYNC */

/*!
 * \brief DAC reference voltage
 */
#define CMPSS_DACREF_VDDA 0x0000U /*!< VDDA is the voltage reference */
#define CMPSS_DACREF_VDAC 0x0020U /*!< VDAC is the voltage reference */

/* DAC value source */
#define CMPSS_DACSRC_SHDW 0x0000U /*!< DAC value updated from shadow register */
#define CMPSS_DACSRC_RAMP 0x0001U /*!< DAC value is updated from the ramp register */

/*!
 * \brief Values that can be passed to CMPSS_configRamp()
 * as the pwmSyncSrc parameter.
 */
#define CMPSS_PWMSYNC1  1U  /*!< PWMSYNC1 */
#define CMPSS_PWMSYNC2  2U  /*!< PWMSYNC2 */
#define CMPSS_PWMSYNC3  3U  /*!< PWMSYNC3 */
#define CMPSS_PWMSYNC4  4U  /*!< PWMSYNC4 */
#define CMPSS_PWMSYNC5  5U  /*!< PWMSYNC5 */
#define CMPSS_PWMSYNC6  6U  /*!< PWMSYNC6 */
#define CMPSS_PWMSYNC7  7U  /*!< PWMSYNC7 */
#define CMPSS_PWMSYNC8  8U  /*!< PWMSYNC8 */
#define CMPSS_PWMSYNC9  9U  /*!< PWMSYNC9 */
#define CMPSS_PWMSYNC10 10U /*!< PWMSYNC10 */
#define CMPSS_PWMSYNC11 11U /*!< PWMSYNC11 */
#define CMPSS_PWMSYNC12 12U /*!< PWMSYNC12 */
#define CMPSS_PWMSYNC13 13U /*!< PWMSYNC13 */
#define CMPSS_PWMSYNC14 14U /*!< PWMSYNC14 */
#define CMPSS_PWMSYNC15 15U /*!< PWMSYNC15 */
#define CMPSS_PWMSYNC16 16U /*!< PWMSYNC16 */

/*! \brief CMPSS trim check data */
#define CMPSS_TRIM_CHECK_DATA 0x55aa55aa

/*! \brief CMPSS Enable state */
typedef enum
{
    kCMP_DISABLE = 0U, /*!< CMP Module Enable */
    kCMP_ENABLE  = 1U, /*!< CMP Module Disable */
} CMP_En_t;

/*! \brief CMPSS Index */
typedef enum
{
    kCMP_1   = 0U, /*!< CMP Module 0 */
    kCMP_2   = 1U, /*!< CMP Module 1 */
    kCMP_3   = 2U, /*!< CMP Module 2 */
    kCMP_4   = 3U, /*!< CMP Module 3 */
    kCMP_5   = 4U, /*!< CMP Module 4 */
    kCMP_6   = 5U, /*!< CMP Module 5 */
    kCMP_7   = 6U, /*!< CMP Module 6 */
    kCMP_8   = 7U, /*!< CMP Module 7 */
    kCMP_MAX = 8U, /*!< CMP Module MAX */
} CMP_Idx_t;

/*! \brief CMPSS Ramp geneator state */
typedef enum
{
    kRG_STOP_IMME = 0U, /*!< Ramp generator stops immediately */
    kRG_STOP_NEXT = 1U, /*!< Ramp generator stops at next EPWMSYNCPER */
    kRG_FREE      = 2U  /*!< Ramp generator no stops */
} CMP_RampFreesoftSel_t;

/*! \brief CMPSS output state */
typedef enum
{
    kCMPSS_OUT_ASYNC_COMP = 0U, /*!< Asynchronous comparator output */
    kCMPSS_OUT_SYNC_COMP  = 1U, /*!< Synchronous comparator output */
    kCMPSS_OUT_FILTER     = 2U, /*!< Output of digital filter */
    kCMPSS_OUT_LATCH      = 3U, /*!< Latched output of digital filter */
} CMP_OutputSel_t;

/*! \brief CMPSS trim data */
typedef struct
{
    uint32_t cmpssCheckData;          /*!< CMPSS check data */
    int8_t   cmpssTrim[kCMP_MAX * 2]; /*!< CMPSS1 H, CMPSS1 L, CMPSS 2 H, ..., CMPSS8 H, CMPSS8 L */
} CMPSS_EflashTrimValue_t;
/*******************************************************************************
 * APIs
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Check if the Comparator Subsystem (CMPSS) base address is valid
 *
 * \details This static inline function verifies whether the provided CMPSS module base address
 *          points to a valid CMPSS peripheral instance in the system. It is a runtime check
 *          used to prevent incorrect usage of memory addresses.
 *
 * \param[in] base Pointer to the CMPSS_Type struct representing the CMPSS module base address
 *
 * \return true if the base address is valid, false otherwise
 */
static inline bool CMPSS_isBaseValid(CMPSS_Type *base)
{
    return ((base == CMPSS1) || (base == CMPSS2) || (base == CMPSS3) || (base == CMPSS4) || (base == CMPSS5) ||
            (base == CMPSS6) || (base == CMPSS7) || (base == CMPSS8));
}

/*!
 * \brief Enables the CMPSS module.
 *
 * \param[in] base is the base address of the CMPSS module.
 *
 * \details This function enables the CMPSS module passed into the base parameter.
 *
 *
 */
static inline void CMPSS_enableModule(CMPSS_Type *base)
{
    /* Check the arguments.*/
    assert(CMPSS_isBaseValid(base));

    /* Set the bit that enables the CMPSS module. */
    base->COMPCTL |= CMPSS_COMPCTL_COMPDACE_Set(kCMP_ENABLE);
}

/*!
 * \brief Disables the CMPSS module.
 *
 * \param[in] base is the base address of the CMPSS module.
 *
 * \details This function disables the CMPSS module passed into the base parameter.
 *
 *
 */
static inline void CMPSS_disableModule(CMPSS_Type *base)
{
    /* Check the arguments.*/
    assert(CMPSS_isBaseValid(base));

    /* Clear the bit that enables the CMPSS module. */
    base->COMPCTL &= ~CMPSS_COMPCTL_COMPDACE_Msk;
}

/*!
 * \brief Sets the configuration for the high comparator.
 *
 * \param[in] base is the base address of the CMPSS module.
 * \param[in] config is the configuration of the high comparator.
 *
 * \details This function configures a comparator.  The config parameter is the
 * result of a logical OR operation between a CMPSS_INSRC_xxx value and if
 * desired, CMPSS_INV_INVERTED and CMPSS_OR_ASYNC_OUT_W_FILT values.
 *
 * The CMPSS_INSRC_xxx term can take on the following values to specify
 * the high comparator negative input source:
 *                   -  CMPSS_INSRC_DAC - The internal DAC.
 *                   - CMPSS_INSRC_PIN - An external pin.
 *
 * CMPSS_INV_INVERTED may be ORed into config if the comparator output
 * should be inverted.
 *
 * CMPSS_OR_ASYNC_OUT_W_FILT may be ORed into config if the
 * asynchronous comparator output should be fed into an OR gate with the
 * latched digital filter output before it is made available for CTRIPH or
 * CTRIPOUTH.
 *
 */
static inline void CMPSS_configHighComparator(CMPSS_Type *base, uint16_t config)
{
    /* Check the arguments.*/
    assert(CMPSS_isBaseValid(base));

    /* Write the high comparator configuration to the appropriate register. */
    uint32_t msk = CMPSS_COMPCTL_COMPHSOURCE_Msk | CMPSS_COMPCTL_COMPHINV_Msk | CMPSS_COMPCTL_ASYNCHEN_Msk;

    base->COMPCTL = (base->COMPCTL & (~msk)) | config;
}

/*!
 * \brief Sets the configuration for the low comparator.
 *
 * \param[in] base is the base address of the CMPSS module.
 * \param[in] config is the configuration of the low comparator.
 *
 * \details This function configures a comparator.  The config parameter is the
 * result of a logical OR operation between a CMPSS_INSRC_xxx value and if
 * desired, CMPSS_INV_INVERTED and CMPSS_OR_ASYNC_OUT_W_FILT values.
 *
 * The CMPSS_INSRC_xxx term can take on the following values to specify
 * the low comparator negative input source:
 *                    - CMPSS_INSRC_DAC - The internal DAC.
 *                    - CMPSS_INSRC_PIN - An external pin.
 *
 * CMPSS_INV_INVERTED may be ORed into config if the comparator output
 * should be inverted.
 *
 * CMPSS_OR_ASYNC_OUT_W_FILT may be ORed into config if the
 * asynchronous comparator output should be fed into an OR gate with the
 * latched digital filter output before it is made available for CTRIPL or
 * CTRIPOUTL.
 *
 */
static inline void CMPSS_configLowComparator(CMPSS_Type *base, uint16_t config)
{
    /* Check the arguments.*/
    assert(CMPSS_isBaseValid(base));

    /* Write the low comparator configuration to the appropriate register. */
    uint32_t msk  = CMPSS_COMPCTL_COMPLSOURCE_Msk | CMPSS_COMPCTL_COMPLINV_Msk | CMPSS_COMPCTL_ASYNCLEN_Msk;
    base->COMPCTL = (base->COMPCTL & (~msk)) | (config << 8U);
}

/*!
 * \brief Sets the output signal configuration for the high comparator.
 *
 * \param[in] base is the base address of the CMPSS module.
 * \param[in] config is the configuration of the high comparator output signals.
 *
 * \details This function configures a comparator's output signals CTRIP and CTRIPOUT.
 * The config parameter is the result of a logical OR operation between the
 * CMPSS_TRIPOUT_xxx and CMPSS_TRIP_xxx values.
 *
 * The CMPSS_TRIPOUT_xxx term can take on the following values to specify
 * which signal drives CTRIPOUTH:
 *                    - CMPSS_TRIPOUT_ASYNC_COMP - The asynchronous comparator output.
 *                    - CMPSS_TRIPOUT_SYNC_COMP - The synchronous comparator output.
 *                    - CMPSS_TRIPOUT_FILTER - The output of the digital filter.
 *                    - CMPSS_TRIPOUT_LATCH - The latched output of the digital filter.
 *
 * The CMPSS_TRIP_xxx term can take on the following values to specify
 * which signal drives CTRIPH:
 *                    - CMPSS_TRIP_ASYNC_COMP - The asynchronous comparator output.
 *                    - CMPSS_TRIP_SYNC_COMP - The synchronous comparator output.
 *                    - CMPSS_TRIP_FILTER - The output of the digital filter.
 *                    - CMPSS_TRIP_LATCH - The latched output of the digital filter.
 *
 */
static inline void CMPSS_configOutputsHigh(CMPSS_Type *base, uint16_t config)
{
    /* Check the arguments.*/
    assert(CMPSS_isBaseValid(base));

    /* Write the high comparator output settings to the appropriate register. */
    uint32_t msk  = CMPSS_COMPCTL_CTRIPHSEL_Msk | CMPSS_COMPCTL_CTRIPOUTHSEL_Msk;
    base->COMPCTL = (base->COMPCTL & (~msk)) | config;
}

/*!
 * \brief Sets the output signal configuration for the low comparator.
 *
 * \param[in] base is the base address of the CMPSS module.
 * \param[in] config is the configuration of the low comparator output signals.
 *
 * \details This function configures a comparator's output signals CTRIP and CTRIPOUT.
 * The config parameter is the result of a logical OR operation between the
 * CMPSS_TRIPOUT_xxx and CMPSS_TRIP_xxx values.
 *
 * The CMPSS_TRIPOUT_xxx term can take on the following values to specify
 * which signal drives CTRIPOUTL:
 *                    - CMPSS_TRIPOUT_ASYNC_COMP - The asynchronous comparator output.
 *                    - CMPSS_TRIPOUT_SYNC_COMP - The synchronous comparator output.
 *                    - CMPSS_TRIPOUT_FILTER - The output of the digital filter.
 *                    - CMPSS_TRIPOUT_LATCH - The latched output of the digital filter.
 *
 * The CMPSS_TRIP_xxx term can take on the following values to specify
 * which signal drives CTRIPL:
 *                    - CMPSS_TRIP_ASYNC_COMP - The asynchronous comparator output.
 *                    -  CMPSS_TRIP_SYNC_COMP - The synchronous comparator output.
 *                    - CMPSS_TRIP_FILTER - The output of the digital filter.
 *                    - CMPSS_TRIP_LATCH - The latched output of the digital filter.
 *
 */
static inline void CMPSS_configOutputsLow(CMPSS_Type *base, uint16_t config)
{
    /* Check the arguments.*/
    assert(CMPSS_isBaseValid(base));

    /* Write the low comparator output settings to the appropriate register. */
    uint32_t msk  = CMPSS_COMPCTL_CTRIPLSEL_Msk | CMPSS_COMPCTL_CTRIPOUTLSEL_Msk;
    base->COMPCTL = (base->COMPCTL & (~msk)) | (config << 8U);
}

/*!
 * \brief Gets the current comparator status.
 *
 * \param[in] base is the base address of the comparator module.
 *
 * \details This function returns the current status for the comparator, specifically
 * the digital filter output and latched digital filter output.
 *
 * \return Returns the current interrupt status, enumerated as a bit field of
 * the following values:
 *                    - CMPSS_STS_HI_FILTOUT - High digital filter output
 *                    - CMPSS_STS_HI_LATCHFILTOUT - Latched value of high digital filter
 *                                                  output
 *                    - CMPSS_STS_LO_FILTOUT - Low digital filter output
 *                    - CMPSS_STS_LO_LATCHFILTOUT - Latched value of low digital filter output
 */
static inline uint16_t CMPSS_getStatus(CMPSS_Type *base)
{
    /* Check the arguments.*/
    assert(CMPSS_isBaseValid(base));

    /* Return contents of the status register. */
    return (base->COMPSTS);
}

/*!
 * \brief Sets the configuration for the internal comparator DACs.
 *
 * \param[in] base is the base address of the CMPSS module.
 * \param[in] config is the configuration of the internal DAC.
 *
 * \details This function configures the comparator's internal DAC.  The config
 * parameter is the result of a logical OR operation between the
 * CMPSS_DACVAL_xxx, CMPSS_DACREF_xxx, and CMPSS_DACSRC_xxx.
 *
 * The CMPSS_DACVAL_xxx term can take on the following values to specify
 * when the DAC value is loaded from its shadow register:
 *                    - CMPSS_DACVAL_SYSCLK - Value register updated on system clock.
 *                    - CMPSS_DACVAL_PWMSYNC - Value register updated on PWM sync.
 *
 * The CMPSS_DACREF_xxx term can take on the following values to specify
 * which voltage supply is used as reference for the DACs:
 *                    - CMPSS_DACREF_VDDA - VDDA is the voltage reference for the DAC.
 *                    - CMPSS_DACREF_VDAC - VDAC is the voltage reference for the DAC.
 *
 * The CMPSS_DACSRC_xxx term can take on the following values to specify
 * the DAC value source for the high comparator's internal DAC:
 *                    - CMPSS_DACSRC_SHDW - The user-programmed DACVALS register.
 *                    - CMPSS_DACSRC_RAMP - The ramp generator RAMPSTS register
 *
 * \note The CMPSS_DACVAL_xxx and CMPSS_DACREF_xxx terms apply to
 * both the high and low comparators. CMPSS_DACSRC_xxx will only affect
 * the high comparator's internal DAC.
 *
 *
 */
static inline void CMPSS_configDAC(CMPSS_Type *base, uint16_t config)
{
    /* Check the arguments.*/
    assert(CMPSS_isBaseValid(base));

    /* Write the DAC configuration to the appropriate register. */
    uint32_t msk     = CMPSS_COMPDACCTL_SWLOADSEL_Msk | CMPSS_COMPDACCTL_SELREF_Msk | CMPSS_COMPDACCTL_DACSOURCE_Msk;
    base->COMPDACCTL = (base->COMPDACCTL & (~msk)) | config;
}

/*!
 * \brief Sets the value of the internal DAC of the high comparator.
 *
 * \param[in] base is the base address of the comparator module.
 * \param[in] value is the value actively driven by the DAC.
 *
 * \details This function sets the 12-bit value driven by the internal DAC of the high
 * comparator. This function will load the value into the shadow register from
 * which the actual DAC value register will be loaded. To configure which
 * event causes this shadow load to take place, use CMPSS_configDAC().
 *
 */
static inline void CMPSS_setDACValueHigh(CMPSS_Type *base, uint16_t value)
{
    /* Check the arguments.*/
    assert(CMPSS_isBaseValid(base));
    assert(value < 4096U);

    /* Write the DAC value to the DAC value shadow register. */
    base->DACHVALS = value;
}

/*!
 * \brief Sets the value of the internal DAC of the low comparator.
 *
 * \param[in] base is the base address of the comparator module.
 * \param[in] value is the value actively driven by the DAC.
 *
 * \details This function sets the 12-bit value driven by the internal DAC of the low
 * comparator. This function will load the value into the shadow register from
 * which the actual DAC value register will be loaded. To configure which
 * event causes this shadow load to take place, use CMPSS_configDAC().
 *
 */
static inline void CMPSS_setDACValueLow(CMPSS_Type *base, uint16_t value)
{
    /* Check the arguments.*/
    assert(CMPSS_isBaseValid(base));
    assert(value < 4096U);

    /* Write the DAC value to the DAC value shadow register. */
    base->DACLVALS = value;
}

/*!
 * \brief Initializes the digital filter of the high comparator.
 *
 * \param[in] base is the base address of the comparator module.
 *
 * \details This function initializes all the samples in the high comparator digital
 * filter to the filter input value.
 *
 * \note See CMPSS_configFilterHigh() for the proper initialization sequence
 * to avoid glitches.
 *
 */
static inline void CMPSS_initFilterHigh(CMPSS_Type *base)
{
    /* Check the arguments.*/
    assert(CMPSS_isBaseValid(base));

    /* Set the high comparator filter initialization bit. */
    base->CTRIPHFILCTL =
        (base->CTRIPHFILCTL & (~CMPSS_CTRIPHFILCTL_FILINIT_Msk)) | CMPSS_CTRIPHFILCTL_FILINIT_Set(kCMP_ENABLE);
}

/*!
 * \brief Initializes the digital filter of the low comparator.
 *
 * \param[in] base is the base address of the comparator module.
 *
 * \details This function initializes all the samples in the low comparator digital
 * filter to the filter input value.
 *
 * \note See CMPSS_configFilterLow() for the proper initialization sequence
 * to avoid glitches.
 *
 */
static inline void CMPSS_initFilterLow(CMPSS_Type *base)
{
    /* Check the arguments.*/
    assert(CMPSS_isBaseValid(base));

    /* Set the low comparator filter initialization bit. */
    base->CTRIPLFILCTL =
        (base->CTRIPLFILCTL & (~CMPSS_CTRIPLFILCTL_FILINIT_Msk)) | CMPSS_CTRIPLFILCTL_FILINIT_Set(kCMP_ENABLE);
}

/*!
 * \brief Gets the value of the internal DAC of the high comparator.
 *
 * \param[in] base is the base address of the comparator module.
 *
 * \details This function gets the value of the internal DAC of the high comparator.
 * The value is read from the active register--not the shadow register to
 * which CMPSS_setDACValueHigh() writes.
 *
 * \return Returns the value driven by the internal DAC of the high comparator.
 */
static inline uint16_t CMPSS_getDACValueHigh(CMPSS_Type *base)
{
    /* Check the arguments.*/
    assert(CMPSS_isBaseValid(base));

    /* Write the DAC value to the DAC value shadow register. */
    return (base->DACHVALA);
}

/*!
 * \brief Gets the value of the internal DAC of the low comparator.
 *
 * \param[in] base is the base address of the comparator module.
 *
 * \details This function gets the value of the internal DAC of the low comparator.
 * The value is read from the active register--not the shadow register to
 * which CMPSS_setDACValueLow() writes.
 *
 * \return Returns the value driven by the internal DAC of the low comparator.
 */
static inline uint16_t CMPSS_getDACValueLow(CMPSS_Type *base)
{
    /* Check the arguments.*/
    assert(CMPSS_isBaseValid(base));

    /* Write the DAC value to the DAC value shadow register. */
    return (base->DACLVALA);
}

/*!
 * \brief Causes a software reset of the high comparator digital filter output latch.
 *
 * \param[in] base is the base address of the comparator module.
 *
 * \details This function causes a software reset of the high comparator digital filter
 * output latch. It will generate a single pulse of the latch reset signal.
 *
 */
static inline void CMPSS_clearFilterLatchHigh(CMPSS_Type *base)
{
    /* Check the arguments.*/
    assert(CMPSS_isBaseValid(base));

    /* Set the bit that generates a reset pulse to the digital filter latch. */
    base->COMPSTSCLR |= CMPSS_COMPSTSCLR_HLATCHCLR_Set(kCMP_ENABLE);
}

/*!
 * \brief Causes a software reset of the low comparator digital filter output latch.
 *
 * \param[in] base is the base address of the comparator module.
 *
 * \details This function causes a software reset of the low comparator digital filter
 * output latch. It will generate a single pulse of the latch reset signal.
 *
 */
static inline void CMPSS_clearFilterLatchLow(CMPSS_Type *base)
{
    /* Check the arguments.*/
    assert(CMPSS_isBaseValid(base));

    /* Set the bit that generates a reset pulse to the digital filter latch. */
    base->COMPSTSCLR |= CMPSS_COMPSTSCLR_LLATCHCLR_Set(kCMP_ENABLE);
}

/*!
 * \brief Sets the ramp generator maximum reference value.
 *
 * \param[in] base is the base address of the comparator module.
 * \param[in] value the ramp maximum reference value.
 *
 * \details This function sets the ramp maximum reference value that will be loaded
 * into the ramp generator.
 *
 */
static inline void CMPSS_setMaxRampValue(CMPSS_Type *base, uint32_t value)
{
    /* Check the arguments.*/
    assert(CMPSS_isBaseValid(base));

    /* Write the maximum ramp value to the shadow register. */
    base->RAMPMAXREFS = value;
}

/*!
 * \brief Gets the ramp generator maximum reference value.
 *
 * \param[in] base is the base address of the comparator module.
 *
 * \return Returns the latched ramp maximum reference value that will be
 * loaded into the ramp generator.
 */
static inline uint32_t CMPSS_getMaxRampValue(CMPSS_Type *base)
{
    /* Check the arguments.*/
    assert(CMPSS_isBaseValid(base));

    /* Read the maximum ramp value from the register. */
    return (base->RAMPMAXREFA);
}

/*!
 * \brief Sets the ramp generator decrement value.
 *
 * \param[in] base is the base address of the comparator module.
 * \param[in] value is the ramp decrement value.
 *
 * \details This function sets the value that is subtracted from the ramp value on
 * every system clock cycle.
 *
 */
static inline void CMPSS_setRampDecValue(CMPSS_Type *base, uint32_t value)
{
    /* Check the arguments.*/
    assert(CMPSS_isBaseValid(base));

    /* Write the ramp decrement value to the shadow register. */
    base->RAMPDECVALS = value;
}

/*!
 * \brief Gets the ramp generator decrement value.
 *
 * \param[in] base is the base address of the comparator module.
 *
 * \return Returns the latched ramp decrement value that is subtracted from
 * the ramp value on every system clock cycle.
 */
static inline uint32_t CMPSS_getRampDecValue(CMPSS_Type *base)
{
    /* Check the arguments.*/
    assert(CMPSS_isBaseValid(base));

    /* Read the ramp decrement value from the register. */
    return (base->RAMPDECVALA);
}

/*!
 * \brief Sets the ramp generator delay value.
 *
 * \param[in] base is the base address of the comparator module.
 * \param[in] value is the 13-bit ramp delay value.
 *
 * \details This function sets the value that configures the number of system clock
 * cycles to delay the start of the ramp generator decrementer after a PWMSYNC
 * event is received. Delay value can be no greater than 8191.
 *
 */
static inline void CMPSS_setRampDelayValue(CMPSS_Type *base, uint16_t value)
{
    /* Check the arguments.*/
    assert(CMPSS_isBaseValid(base));
    assert(value < 8192U);

    /* Write the ramp delay value to the shadow register. */
    base->RAMPDLYS = value;
}

/*!
 * \brief Sets the ramp generator prescale value.
 *
 * \param[in] base is the base address of the comparator module.
 * \param[in] value is 0 or 1.
 *
 *
 */
static inline void CMPSS_setRampPrescale(CMPSS_Type *base, uint16_t value)
{
    /* Check the arguments.*/
    assert(CMPSS_isBaseValid(base));

    base->COMPDACCTL = (base->COMPDACCTL & (~CMPSS_COMPDACCTL_PRESCALE_Msk)) | CMPSS_COMPDACCTL_PRESCALE_Set(value);
}

/*!
 * \brief Gets the ramp generator prescale value.
 *
 * \param[in] base is the base address of the comparator module.
 *
 * \return CMPSS ramp prescale
 */
static inline uint16_t CMPSS_getRampPrescale(CMPSS_Type *base)
{
    /* Check the arguments.*/
    assert(CMPSS_isBaseValid(base));

    return ((base->COMPDACCTL >> (CMPSS_COMPDACCTL_PRESCALE_Pos)) & 0x01);
}

/*!
 * \brief Gets the ramp generator delay value.
 *
 * \param[in] base is the base address of the comparator module.
 *
 * \return Returns the latched ramp delay value that is subtracted from
 * the ramp value on every system clock cycle.
 */
static inline uint16_t CMPSS_getRampDelayValue(CMPSS_Type *base)
{
    /* Check the arguments.*/
    assert(CMPSS_isBaseValid(base));

    return (base->RAMPDLYA);
}

/*!
 * \brief Sets the comparator hysteresis settings.
 *
 * \param[in] base is the base address of the comparator module.
 * \param[in] value is the amount of hysteresis on the comparator inputs.
 *
 * \details This function sets the amount of hysteresis on the comparator inputs. The
 * value parameter indicates the amount of hysteresis desired. Passing in 0
 * results in none, passing in 1 results in typical hysteresis, passing in 2
 * results in 2x of typical hysteresis, and so on where value x of typical
 * hysteresis is the amount configured.
 *
 */
static inline void CMPSS_setHysteresis(CMPSS_Type *base, uint16_t value)
{
    /* Check the arguments.*/
    assert(CMPSS_isBaseValid(base));
    assert(value <= 4U);

    /* Set the Hysteresis value  */
    base->COMPHYSCTL = value;
}

/*!
 * \brief Enables reset of HIGH comparator digital filter output latch on PWMSYNC
 *
 * \param[in] base is the base address of the comparator module.
 *
 * \details This function enables EPWMSYNCPER reset of High comparator digital filter
 * output latch
 *
 */
static inline void CMPSS_enableLatchResetOnPWMSYNCHigh(CMPSS_Type *base)
{
    /* Check the arguments.*/
    assert(CMPSS_isBaseValid(base));

    base->COMPSTSCLR |= CMPSS_COMPSTSCLR_HSYNCCLREN_Set(kCMP_ENABLE);
}

/*!
 * \brief Disables reset of HIGH comparator digital filter output latch on PWMSYNC
 *
 * \param[in] base is the base address of the comparator module.
 *
 * \details This function disables EPWMSYNCPER reset of High comparator digital filter
 * output latch
 *
 */
static inline void CMPSS_disableLatchResetOnPWMSYNCHigh(CMPSS_Type *base)
{
    /* Check the arguments.*/
    assert(CMPSS_isBaseValid(base));

    base->COMPSTSCLR &= ~CMPSS_COMPSTSCLR_HSYNCCLREN_Msk;
}

/*!
 * \brief Enables reset of LOW comparator digital filter output latch on PWMSYNC
 *
 * \param[in] base is the base address of the comparator module.
 *
 * \details This function enables EPWMSYNCPER reset of Low comparator digital filter
 * output latch
 *
 */
static inline void CMPSS_enableLatchResetOnPWMSYNCLow(CMPSS_Type *base)
{
    /* Check the arguments.*/
    assert(CMPSS_isBaseValid(base));

    base->COMPSTSCLR |= CMPSS_COMPSTSCLR_LSYNCCLREN_Set(kCMP_ENABLE);
}

/*!
 * \brief Disables reset of LOW comparator digital filter output latch on PWMSYNC
 *
 * \param[in] base is the base address of the comparator module.
 *
 * \details This function disables EPWMSYNCPER reset of Low comparator digital filter
 * output latch
 *
 */
static inline void CMPSS_disableLatchResetOnPWMSYNCLow(CMPSS_Type *base)
{
    /* Check the arguments.*/
    assert(CMPSS_isBaseValid(base));

    base->COMPSTSCLR &= ~CMPSS_COMPSTSCLR_LSYNCCLREN_Msk;
}

/*!
 * \brief Sets the ePWM module blanking signal that holds trip in reset.
 *
 * \param[in] base is the base address of the comparator module.
 * \param[in] pwmBlankSrc is the number of the PWMBLANK source.
 *
 * \details This function configures which PWMBLANK signal from the ePWM module will
 * hold trip in reset when blanking is enabled.
 * The number of the PWMBLANK signal to be used to reset the ramp generator
 * should be specified by passing it into the pwmBlankSrc parameter. For
 * instance, passing a 2 into pwmBlankSrc will select PWMBLANK2.
 *
 */
static inline void CMPSS_configBlanking(CMPSS_Type *base, uint16_t pwmBlankSrc)
{
    /* Check the arguments.*/
    assert(CMPSS_isBaseValid(base));
    assert((pwmBlankSrc >= 1U) && (pwmBlankSrc <= 16U));

    /* Write the blank source number to the appropriate register. */
    base->COMPDACCTL =
        (base->COMPDACCTL & (~CMPSS_COMPDACCTL_BLANKSOURCE_Msk)) | CMPSS_COMPDACCTL_BLANKSOURCE_Set(pwmBlankSrc - 1U);
}

/*!
 * \brief Enables an ePWM blanking signal to hold trip in reset.
 *
 * \param[in] base is the base address of the comparator module.
 *
 * \details This function enables a selected ePWM blanking signal to hold trip in
 * reset.
 *
 */
static inline void CMPSS_enableBlanking(CMPSS_Type *base)
{
    /* Check the arguments.*/
    assert(CMPSS_isBaseValid(base));

    /* Set the bit that enables the PWMBLANK signal. */
    base->COMPDACCTL |= CMPSS_COMPDACCTL_BLANKEN_Set(kCMP_ENABLE);
}

/*!
 * \brief Disables an ePWM blanking signal from holding trip in reset.
 *
 * \param[in] base is the base address of the comparator module.
 *
 * \details This function disables a selected ePWM blanking signal from holding trip in
 * reset.
 *
 */
static inline void CMPSS_disableBlanking(CMPSS_Type *base)
{
    /* Check the arguments.*/
    assert(CMPSS_isBaseValid(base));

    /* Clear the bit that disables the PWMBLANK signal. */
    base->COMPDACCTL &= ~CMPSS_COMPDACCTL_BLANKEN_Msk;
}

/*!
 * \brief Enable Invert an ePWM blanking signal.
 *
 * \param[in] base is the base address of the comparator module.
 *
 * \details This function enable invert a selected ePWM blanking signal
 *
 */
static inline void CMPSS_enableInvertBlankSource(CMPSS_Type *base)
{
    /* Check the arguments.*/
    assert(CMPSS_isBaseValid(base));

    /* Set invert bit */
    base->COMPCTL = (base->COMPCTL & (~CMPSS_COMPCTL_BLANKINV_Msk)) | CMPSS_COMPCTL_BLANKINV_Set(1U);
}

/*!
 * \brief Disables invert an ePWM blanking signal.
 *
 * \param[in] base is the base address of the comparator module.
 *
 * \details This function disables invert a selected ePWM blanking signal
 *
 */
static inline void CMPSS_disableInvertBlankSource(CMPSS_Type *base)
{
    /* Check the arguments.*/
    assert(CMPSS_isBaseValid(base));

    /* Clear invert bit */
    base->COMPCTL &= ~CMPSS_COMPCTL_BLANKINV_Msk;
}

/*!
 * \brief Config freesoft value
 *
 * \param[in] base is the base address of the comparator module.
 *
 * \param[in] sel is CMP_RampFreesoftSel_t
 *
 * \details This function Config freesoft value
 *
 */
static inline void CMPSS_configFreesoft(CMPSS_Type *base, CMP_RampFreesoftSel_t sel)
{
    /* Check the arguments.*/
    assert(CMPSS_isBaseValid(base));

    /* Set the sel mode. */
    base->COMPDACCTL = (base->COMPDACCTL & (~CMPSS_COMPDACCTL_FREESOFT_Msk)) | CMPSS_COMPDACCTL_FREESOFT_Set(sel);
}

/*!
 * \brief Get the CMPSS instance
 *
 * \param[in] base is the base address of the comparator module.
 *
 * \return Returns the instance number
 *
 */
uint32_t CMPSS_getInstance(CMPSS_Type *base);

/*!
 * \brief Configures the digital filter of the high comparator.
 *
 * \param[in] base is the base address of the comparator module.
 * \param[in] samplePrescale is the number of system clock cycles between samples.
 * \param[in] sampleWindow is the number of FIFO samples to monitor.
 * \param[in] threshold is the majority threshold of samples to change state.
 *
 * \details This function configures the operation of the digital filter of the high
 * comparator.
 *
 * The samplePrescale parameter specifies the number of system clock cycles
 * between samples. It is a 10-bit value so a number higher than 1023 should
 * not be passed as this parameter. The prescaler used by digital filter is 1
 * more than samplePrescale value. So, the input provided should be 1 less
 * than the expected prescaler.
 *
 * The sampleWindow parameter configures the size of the window of FIFO
 * samples taken from the input that will be monitored to determine when to
 * change the filter output. This sample window may be no larger than 32
 * samples.
 *
 * The threshold parameter configures the threshold value to be used by
 * the digital filter.
 *
 * The filter output resolves to the majority value of the sample window where
 * majority is defined by the value passed into the threshold parameter.
 * For proper operation, the value of threshold must be greater than
 * sampleWindow / 2.
 *
 * To ensure proper operation of the filter, the following is the recommended
 * function call sequence for initialization:
 *
 * -# Configure and enable the comparator using CMPSS_configHighComparator()
 *    and CMPSS_enableModule()
 * -# Configure the digital filter using CMPSS_configFilterHigh()
 * -# Initialize the sample values using CMPSS_initFilterHigh()
 * -# Configure the module output signals CTRIP and CTRIPOUT using
 *    CMPSS_configOutputsHigh()
 *
 *
 */
void CMPSS_configFilterHigh(CMPSS_Type *base, uint16_t samplePrescale, uint16_t sampleWindow, uint16_t threshold);

/*!
 * \brief Configures the digital filter of the low comparator.
 *
 * \param[in] base is the base address of the comparator module.
 * \param[in] samplePrescale is the number of system clock cycles between samples.
 * \param[in] sampleWindow is the number of FIFO samples to monitor.
 * \param[in] threshold is the majority threshold of samples to change state.
 *
 * \details This function configures the operation of the digital filter of the low
 * comparator.
 *
 * The samplePrescale parameter specifies the number of system clock cycles
 * between samples. It is a 10-bit value so a number higher than 1023 should
 * not be passed as this parameter. The prescaler used by digital filter is 1
 * more than samplePrescale value. So, the input provided should be 1 less
 * than the expected prescaler.
 *
 * The sampleWindow parameter configures the size of the window of FIFO
 * samples taken from the input that will be monitored to determine when to
 * change the filter output. This sample window may be no larger than 32
 * samples.
 *
 * The threshold parameter configures the threshold value to be used by
 * the digital filter.
 *
 * The filter output resolves to the majority value of the sample window where
 * majority is defined by the value passed into the threshold parameter.
 * For proper operation, the value of threshold must be greater than
 * sampleWindow / 2.
 *
 * To ensure proper operation of the filter, the following is the recommended
 * function call sequence for initialization:
 *
 * -# Configure and enable the comparator using CMPSS_configLowComparator()
 *    and CMPSS_enableModule()
 * -# Configure the digital filter using CMPSS_configFilterLow()
 * -# Initialize the sample values using CMPSS_initFilterLow()
 * -# Configure the module output signals CTRIP and CTRIPOUT using
 *    CMPSS_configOutputsLow()
 *
 *
 */
void CMPSS_configFilterLow(CMPSS_Type *base, uint16_t samplePrescale, uint16_t sampleWindow, uint16_t threshold);

/*!
 * \brief Configures whether or not the digital filter latches are reset by PWMSYNC
 *
 * \param[in] base is the base address of the comparator module.
 * \param[in] highEnable indicates filter latch settings in the high comparator.
 * \param[in] lowEnable indicates filter latch settings in the low comparator.
 *
 * \details This function configures whether or not the digital filter latches in both
 * the high and low comparators should be reset by PWMSYNC. If the
 * highEnable parameter is true, the PWMSYNC will be allowed to reset
 * the high comparator's digital filter latch. If it is false, the ability of
 * the PWMSYNC to reset the latch will be disabled. The lowEnable parameter
 * has the same effect on the low comparator's digital filter latch.
 *
 *
 */
void CMPSS_configLatchOnPWMSYNC(CMPSS_Type *base, bool highEnable, bool lowEnable);

/*!
 * \brief Configures the comparator subsystem's ramp generator.
 *
 * \param[in] base is the base address of the comparator module.
 * \param[in] maxRampVal is the ramp maximum reference value.
 * \param[in] decrementVal value is the ramp decrement value.
 * \param[in] delayVal is the ramp delay value.
 * \param[in] pwmSyncSrc is the number of the PWMSYNC source.
 * \param[in] useRampValShdw indicates if the max ramp shadow should be used.
 *
 * \details This function configures many of the main settings of the comparator
 * subsystem's ramp generator. The maxRampVal parameter should be passed
 * the ramp maximum reference value that will be loaded into the ramp
 * generator. The decrementVal parameter should be passed the decrement
 * value that will be subtracted from the ramp generator on each system clock
 * cycle. The delayVal parameter should be passed the 13-bit number of
 * system clock cycles the ramp generator should delay before beginning to
 * decrement the ramp generator after a PWMSYNC signal is received.
 *
 * These three values may be be set individually using the
 * CMPSS_setMaxRampValue(), CMPSS_setRampDecValue(), and
 * CMPSS_setRampDelayValue() APIs.
 *
 * The number of the PWMSYNC signal to be used to reset the ramp generator
 * should be specified by passing it into the pwmSyncSrc parameter. For
 * instance, passing a CMPSS_PWMSYNCx into pwmSyncSrc will select PWMSYNCx.
 *
 * To indicate whether the ramp generator should reset with the value from the
 * ramp max reference value shadow register or with the latched ramp max
 * reference value, use the useRampValShdw parameter. Passing it true
 * will result in the latched value being bypassed. The ramp generator will be
 * loaded right from the shadow register. A value of false will load the
 * ramp generator from the latched value.
 *
 *
 */
void CMPSS_configRamp(CMPSS_Type *base, uint32_t maxRampVal, uint32_t decrementVal, uint16_t delayVal,
                      uint16_t pwmSyncSrc, bool useRampValShdw);

/*!
 * \brief Set High offset trim data to reg
 *
 * \details Set High offset trim data to reg
 *
 * \param[in] base Pointer to the CMPSS_Type struct representing the CMPSS module base address
 *
 * \return true if set high offset trim pass
 */
status_t CMPSS_setHOffsetTrim(CMPSS_Type *base);

/*!
 * \brief Set Low offset trim data to reg
 *
 * \details Set Low offset trim data to reg
 *
 * \param[in] base Pointer to the CMPSS_Type struct representing the CMPSS module base address
 *
 * \return true if set low offset trim pass
 */
status_t CMPSS_setLOffsetTrim(CMPSS_Type *base);

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */ /* end of DRV_HTE_CMPSS */


#endif // HTE_CMPSS_H
