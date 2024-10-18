/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_eqep.h
 * \brief SDK EQEP driver header file
 * \version 1.0.0
 */

#ifndef HTE_EQEP_H
#define HTE_EQEP_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_common.h"

/*!
 * \addtogroup DRV_HTE_EQEP EQEP Driver
 *
 * \brief SDK EQEP driver
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define EQEP_CONFIG_QUADRATURE (0x0000U) /*!< Operation Mode : Quadrature-clock mode */
#define EQEP_CONFIG_CLOCK_DIR  (0x4000U) /*!< Operation Mode : Direction-count mode */
#define EQEP_CONFIG_UP_COUNT   (0x8000U) /*!< Operation Mode : Up-count mode, QDIR = 1 */
#define EQEP_CONFIG_DOWN_COUNT (0xC000U) /*!< Operation Mode : Down-count mode, QDIR = 0 */

#define EQEP_CONFIG_2X_RESOLUTION (0x0000U) /*!< Resolution : Count rising and falling edge */
#define EQEP_CONFIG_1X_RESOLUTION (0x0800U) /*!< Resolution : Count rising edge only */


#define EQEP_CONFIG_NO_SWAP (0x0000U) /*!< Swap : Do not swap QEPA and QEPB */
#define EQEP_CONFIG_SWAP    (0x0400U) /*!< Swap : Swap QEPA and QEPB */


#define EQEP_CONFIG_IGATE_DISABLE (0x0000U) /*!< Disable gating of Index pulse */
#define EQEP_CONFIG_IGATE_ENABLE  (0x0200U) /*!< Gate the index pin with strobe */


#define EQEP_COMPARE_NO_SYNC_OUT     (0x0000U) /*!< Disable sync output */
#define EQEP_COMPARE_IDX_SYNC_OUT    (0x2000U) /*!< Sync output on index pin */
#define EQEP_COMPARE_STROBE_SYNC_OUT (0x3000U) /*!< Sync output on strobe pin */


#define EQEP_COMPARE_NO_SHADOW     (0x0000U) /*!< Disable shadow of QPOSCMP */
#define EQEP_COMPARE_LOAD_ON_ZERO  (0x8000U) /*!< Load on QPOSCNT = 0 */
#define EQEP_COMPARE_LOAD_ON_MATCH (0xC000U) /*!< Load on QPOSCNT = QPOSCMP */


#define EQEP_INT_GLOBAL            (0x0001U) /*!< Global interrupt flag */
#define EQEP_INT_POS_CNT_ERROR     (0x0002U) /*!< Position counter error */
#define EQEP_INT_PHASE_ERROR       (0x0004U) /*!< Quadrature phase error */
#define EQEP_INT_DIR_CHANGE        (0x0008U) /*!< Quadrature direction change */
#define EQEP_INT_WATCHDOG          (0x0010U) /*!< Watchdog time-out */
#define EQEP_INT_UNDERFLOW         (0x0020U) /*!< Position counter underflow */
#define EQEP_INT_OVERFLOW          (0x0040U) /*!< Position counter overflow */
#define EQEP_INT_POS_COMP_READY    (0x0080U) /*!< Position-compare ready */
#define EQEP_INT_POS_COMP_MATCH    (0x0100U) /*!< Position-compare match */
#define EQEP_INT_STROBE_EVNT_LATCH (0x0200U) /*!< Strobe event latch */
#define EQEP_INT_INDEX_EVNT_LATCH  (0x0400U) /*!< Index event latch */
#define EQEP_INT_UNIT_TIME_OUT     (0x0800U) /*!< Unit time-out */
#define EQEP_INT_QMA_ERROR         (0x1000U) /*!< QMA error */


#define EQEP_STS_UNIT_POS_EVNT    (0x0080U) /*!< Unit position event detected */
#define EQEP_STS_DIR_ON_1ST_IDX   (0x0040U) /*!< Direction was clockwise on first index event */
#define EQEP_STS_DIR_FLAG         (0x0020U) /*!< Direction is CW (forward) */
#define EQEP_STS_DIR_LATCH        (0x0010U) /*!< Direction was CW on index */
#define EQEP_STS_CAP_OVRFLW_ERROR (0x0008U) /*!< Capture timer overflow */
#define EQEP_STS_CAP_DIR_ERROR    (0x0004U) /*!< Direction changed between position capture events */
#define EQEP_STS_1ST_IDX_FLAG     (0x0002U) /*!< First index pulse occurred */
#define EQEP_STS_POS_CNT_ERROR    (0x0001U) /*!< Position counter error */


#define EQEP_LATCH_CNT_READ_BY_CPU (0x0000U) /*!< On position counter read */
#define EQEP_LATCH_UNIT_TIME_OUT   (0x0004U) /*!< On unit time-out event */
#define EQEP_LATCH_RISING_STROBE   (0x0000U) /*!< On rising edge of strobe */
#define EQEP_LATCH_EDGE_DIR_STROBE (0x0040U) /*!< On rising edge when clockwise, on falling when counter clockwise */
#define EQEP_LATCH_RISING_INDEX    (0x0010U) /*!< On rising edge of index */
#define EQEP_LATCH_FALLING_INDEX   (0x0020U) /*!< On falling edge of index */
#define EQEP_LATCH_SW_INDEX_MARKER (0x0030U) /*!< On software index marker */


#define EQEP_INIT_DO_NOTHING      (0x0000U) /*!< Action is disabled */
#define EQEP_INIT_RISING_STROBE   (0x0800U) /*!< On rising edge of strobe */
#define EQEP_INIT_EDGE_DIR_STROBE (0x0C00U) /*!< On rising edge when clockwise, on falling when counter clockwise */
#define EQEP_INIT_RISING_INDEX    (0x0200U) /*!< On rising edge of index */
#define EQEP_INIT_FALLING_INDEX   (0x0300U) /*!< On falling edge of index */


/*! \brief type definition for EQEP callback  */
typedef void (*EQEP_Callback_t)(EQEP_REGS_Type *base);

/*!
 *  \brief    Enum to select the EQEP IRQ source
 */
typedef enum
{
    kEQEP1_INT   = 0,  /*!< EQEP1 IRQ */
    kEQEP2_INT   = 1,  /*!< EQEP2 IRQ */
    kEQEP3_INT   = 2,  /*!< EQEP3 IRQ */
    kEQEP_INT_MAX,     /*!< MAX IRQ */
} EQEP_IntSrc_t;

/*! \brief type definition for eqep interrupt callback  */
typedef struct
{
    EQEP_Callback_t func[kEQEP_INT_MAX];    /*!< Array of callback functions for EQEP interrupts */
} EQEP_Int_Callback_t;


/*!
 * \brief Values that can be passed to EQEP_setPositionCounterConfig() as the \e mode
 * parameter.
 */
typedef enum
{
    kEQEP_POSITION_RESET_IDX           = 0x0000, /*!< Reset position on index pulse */
    kEQEP_POSITION_RESET_MAX_POS       = 0x1000, /*!< Reset position on maximum position */
    kEQEP_POSITION_RESET_1ST_IDX       = 0x2000, /*!< Reset position on the first index pulse */
    kEQEP_POSITION_RESET_UNIT_TIME_OUT = 0x3000, /*!< Reset position on a unit time event */
} EQEP_PositionResetMode_t;

/*!
 * \brief Values that can be passed to EQEP_setCaptureConfig() as the \e capPrescale
 * parameter. CAPCLK is the capture timer clock frequency.
 */
typedef enum
{
    kEQEP_CAPTURE_CLK_DIV_1   = 0x00, /*!< CAPCLK = SYSCLKOUT/1 */
    kEQEP_CAPTURE_CLK_DIV_2   = 0x10, /*!< CAPCLK = SYSCLKOUT/2 */
    kEQEP_CAPTURE_CLK_DIV_4   = 0x20, /*!< CAPCLK = SYSCLKOUT/4 */
    kEQEP_CAPTURE_CLK_DIV_8   = 0x30, /*!< CAPCLK = SYSCLKOUT/8 */
    kEQEP_CAPTURE_CLK_DIV_16  = 0x40, /*!< CAPCLK = SYSCLKOUT/16 */
    kEQEP_CAPTURE_CLK_DIV_32  = 0x50, /*!< CAPCLK = SYSCLKOUT/32 */
    kEQEP_CAPTURE_CLK_DIV_64  = 0x60, /*!< CAPCLK = SYSCLKOUT/64 */
    kEQEP_CAPTURE_CLK_DIV_128 = 0x70, /*!< CAPCLK = SYSCLKOUT/128 */
} EQEP_CAPCLKPrescale_t;

/*!
 * \brief Values that can be passed to EQEP_setCaptureConfig() as the \e evntPrescale
 * parameter. UPEVNT is the unit position event frequency.
 */
typedef enum
{
    kEQEP_UNIT_POS_EVNT_DIV_1    = 0U,  /*!< UPEVNT = QCLK/1 */
    kEQEP_UNIT_POS_EVNT_DIV_2    = 1U,  /*!< UPEVNT = QCLK/2 */
    kEQEP_UNIT_POS_EVNT_DIV_4    = 2U,  /*!< UPEVNT = QCLK/4 */
    kEQEP_UNIT_POS_EVNT_DIV_8    = 3U,  /*!< UPEVNT = QCLK/8 */
    kEQEP_UNIT_POS_EVNT_DIV_16   = 4U,  /*!< UPEVNT = QCLK/16 */
    kEQEP_UNIT_POS_EVNT_DIV_32   = 5U,  /*!< UPEVNT = QCLK/32 */
    kEQEP_UNIT_POS_EVNT_DIV_64   = 6U,  /*!< UPEVNT = QCLK/64 */
    kEQEP_UNIT_POS_EVNT_DIV_128  = 7U,  /*!< UPEVNT = QCLK/128 */
    kEQEP_UNIT_POS_EVNT_DIV_256  = 8U,  /*!< UPEVNT = QCLK/256 */
    kEQEP_UNIT_POS_EVNT_DIV_512  = 9U,  /*!< UPEVNT = QCLK/512 */
    kEQEP_UNIT_POS_EVNT_DIV_1024 = 10U, /*!< UPEVNT = QCLK/1024 */
    kEQEP_UNIT_POS_EVNT_DIV_2048 = 11U, /*!< UPEVNT = QCLK/2048 */
} EQEP_UPEVNTPrescale_t;

/*!
 * \brief Values that can be passed to EQEP_setStrobeSource() as the \e strobeSrc
 * parameter.
 */
typedef enum
{
    kEQEP_STROBE_FROM_GPIO  = 0U, /*!< Strobe signal comes from GPIO */
    kEQEP_STROBE_OR_ADCSOCA = 2U, /*!< Strobe signal is OR'd with ADCSOCA */
    kEQEP_STROBE_OR_ADCSOCB = 3U, /*!< Strobe signal is OR'd with ADCSOCB */
} EQEP_StrobeSource_t;

/*!
 * \brief Values that can be passed to EQEP_setQMAModuleMode() as the \e qmaMode
 * parameter.
 */
typedef enum
{
    kEQEP_QMA_MODE_BYPASS = 0U, /*!< QMA module is bypassed */
    kEQEP_QMA_MODE_1      = 1U, /*!< QMA mode-1 operation is selected */
    kEQEP_QMA_MODE_2      = 2U, /*!< QMA mode-2 operation is selected */
    kEQEP_BIN_MODE        = 3U, /*!< BIN mode operation is selected */
} EQEP_QMAMode_t;

/*!
 * \brief Possible values of sources for QEPA,QEPB and Index signal which are passed
 * as a structure to EQEP_selectSource() as \e sourceConfig
 */
typedef enum
{
    kEQEP_SOURCE_DEVICE_PIN = 0x0000U, /*!<  signal comes from Device Pin */
    kEQEP_SOURCE_CMPSS1     = 0x0001U, /*!<  signal comes from CMPSS1 */
    kEQEP_SOURCE_CMPSS2     = 0x0002U, /*!<  signal comes from CMPSS2 */
    kEQEP_SOURCE_CMPSS3     = 0x0003U, /*!<  signal comes from CMPSS3 */
    kEQEP_SOURCE_CMPSS4     = 0x0004U, /*!<  signal comes from CMPSS4 */
    kEQEP_SOURCE_CMPSS5     = 0x0005U, /*!<  signal comes from CMPSS5 */
    kEQEP_SOURCE_CMPSS6     = 0x0006U, /*!<  signal comes from CMPSS6 */
    kEQEP_SOURCE_CMPSS7     = 0x0007U, /*!<  signal comes from CMPSS7 */
    kEQEP_SOURCE_CMPSS8     = 0x0008U, /*!<  signal comes from CMPSS8 */
    kEQEP_SOURCE_EPWMXBAR1  = 0x0009U, /*!<  signal comes from EPWMXBAR1 */
    kEQEP_SOURCE_EPWMXBAR2  = 0x000AU, /*!<  signal comes from EPWMXBAR2 */
    kEQEP_SOURCE_EPWMXBAR3  = 0x000BU, /*!<  signal comes from EPWMXBAR3 */
    kEQEP_SOURCE_EPWMXBAR4  = 0x000CU, /*!<  signal comes from EPWMXBAR4 */
    kEQEP_SOURCE_EPWMXBAR5  = 0x000DU, /*!<  signal comes from EPWMXBAR5 */
    kEQEP_SOURCE_EPWMXBAR6  = 0x000EU, /*!<  signal comes from EPWMXBAR6 */
    kEQEP_SOURCE_EPWMXBAR7  = 0x000FU, /*!<  signal comes from EPWMXBAR7 */
} EQEP_Source_t;

/*!
 * \brief Values that can be passed to EQEP_setEmulationMode() as the \e emuMode
 * parameter.
 */
typedef enum
{
    kEQEP_EMULATIONMODE_STOPIMMEDIATELY = 0U, /*!< Counters stop immediately */
    kEQEP_EMULATIONMODE_STOPATROLLOVER  = 1U, /*!< Counters stop at period rollover */
    kEQEP_EMULATIONMODE_RUNFREE         = 2U, /*!< Counter unaffected by suspend */
} EQEP_EmulationMode_t;

/*!
 * \brief Structure to be passed to EQEP_selectSource() as \e sourceConfig
 */
typedef struct
{
    EQEP_Source_t sourceA;    /*!< Source for QEPA signal */  
    EQEP_Source_t sourceB;    /*!< Source for QEPB signal */  
    EQEP_Source_t sourceIndex; /*!< Source for Index signal */ 
} EQEP_SourceSelect_t;

/*******************************************************************************
 * APIs
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif


#ifdef DEBUG

/*!
 *
 * \brief Checks an EQEP base address.
 *
 * \param[in] base is the base address of the EQEP module.
 *
 * This function determines if a EQEP module base address is valid.
 *
 * \return Returns \b true if is valid and \b false otherwise.
 *
 */
static inline bool EQEP_isBaseValid(EQEP_REGS_Type *base)
{
    return ((base == EQEP1) || (base == EQEP2) || (base == EQEP3));
}
#endif

/*!
 *
 * \brief Enables the EQEP module.
 *
 * This function enables operation of the quadrature pulse encoder pulse
 * (EQEP) module.  The module must be configured before it is enabled.
 *
 * \param[in] base is the base address of the EQEP module.
 *
 */
static inline void EQEP_enableModule(EQEP_REGS_Type *base)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Enable the EQEP module. */
    base->QEPCTL |= EQEP_QEPCTL_QPEN_Set(1U);
}

/*!
 *
 * \brief Disables the EQEP module.
 *
 * This function disables operation of the EQEP module.
 *
 * \param[in] base is the base address of the EQEP module.
 *
 */
static inline void EQEP_disableModule(EQEP_REGS_Type *base)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Disable the EQEP module. */
    base->QEPCTL &= ~((uint16_t)EQEP_QEPCTL_QPEN_Set(1U));
}

/*!
 *
 * \brief Configures EQEP module's quadrature decoder unit.
 *
 * \param[in] base is the base address of the EQEP module.
 * \param[in] config is the configuration for the EQEP module decoder unit.
 *
 * This function configures the operation of the EQEP module's quadrature
 * decoder unit.  The \e config parameter provides the configuration
 * of the decoder and is the logical OR of several values:
 *
 * - \b EQEP_CONFIG_2X_RESOLUTION or \b EQEP_CONFIG_1X_RESOLUTION specify
 *   if both rising and falling edges should be counted or just rising edges.
 * - \b EQEP_CONFIG_QUADRATURE, \b EQEP_CONFIG_CLOCK_DIR,
 *   \b EQEP_CONFIG_UP_COUNT, or \b EQEP_CONFIG_DOWN_COUNT specify if
 *   quadrature signals are being provided on QEPA and QEPB, if a direction
 *   signal and a clock are being provided, or if the direction should be
 *   hard-wired for a single direction with QEPA used for input.
 * - \b EQEP_CONFIG_NO_SWAP or \b EQEP_CONFIG_SWAP to specify if the
 *   signals provided on QEPA and QEPB should be swapped before being
 *   processed.
 * - \b EQEP_CONFIG_IGATE_DISABLE or \b EQEP_CONFIG_IGATE_ENABLE to specify
 *   if the gating of the index pulse should be enabled or disabled
 */
static inline void EQEP_setDecoderConfig(EQEP_REGS_Type *base, uint16_t config)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Write the new decoder configuration to the hardware. */
    base->QDECCTL = (base->QDECCTL &
                     ~(EQEP_QDECCTL_SWAP_Msk | EQEP_QDECCTL_XCR_Msk | EQEP_QDECCTL_QSRC_Msk | EQEP_QDECCTL_IGATE_Msk)) |
                    config;
}

/*!
 *
 * \brief Configures EQEP module position counter unit.
 *
 * \param[in] base is the base address of the EQEP module.
 * \param[in] mode is the configuration for the EQEP module position counter.
 * \param[in] maxPosition specifies the maximum position value.
 *
 * This function configures the operation of the EQEP module position
 * counter.  The \e mode parameter determines the event on which the position
 * counter gets reset. It should be passed one of the following values:
 * \b EQEP_POSITION_RESET_IDX, \b EQEP_POSITION_RESET_MAX_POS,
 * \b EQEP_POSITION_RESET_1ST_IDX, or \b EQEP_POSITION_RESET_UNIT_TIME_OUT.
 *
 * \e maxPosition is the maximum value of the position counter and is
 * the value used to reset the position capture when moving in the reverse
 * (negative) direction.
 */
static inline void EQEP_setPositionCounterConfig(EQEP_REGS_Type *base, EQEP_PositionResetMode_t mode,
                                                 uint32_t maxPosition)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Write the position counter reset configuration to the hardware. */
    base->QEPCTL = (base->QEPCTL & ~EQEP_QEPCTL_PCRM_Msk) | (uint16_t)mode;

    /* Set the maximum position. */
    base->QPOSMAX = maxPosition;
}

/*!
 *
 * \brief Gets the current encoder position.
 *
 * \param[in] base is the base address of the EQEP module.
 *
 * This function returns the current position of the encoder.  Depending upon
 * the configuration of the encoder, and the incident of an index pulse, this
 * value may or may not contain the expected data (that is, if in reset on
 * index mode, if an index pulse has not been encountered, the position
 * counter is not yet aligned with the index pulse).
 *
 * \return The current position of the encoder.
 *
 */
static inline uint32_t EQEP_getPosition(EQEP_REGS_Type *base)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Return the current position counter. */
    return (base->QPOSCNT);
}

/*!
 *
 * \brief Sets the current encoder position.
 *
 * \param[in] base is the base address of the EQEP module.
 * \param[in] position is the new position for the encoder.
 *
 * This function sets the current position of the encoder; the encoder
 * position is then measured relative to this value.
 */
static inline void EQEP_setPosition(EQEP_REGS_Type *base, uint32_t position)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Set the position counter. */
    base->QPOSCNT = position;
}

/*!
 *
 * \brief Gets the current direction of rotation.
 *
 * \param[in] base is the base address of the EQEP module.
 *
 * This function returns the current direction of rotation.  In this case,
 * current means the most recently detected direction of the encoder; it may
 * not be presently moving but this is the direction it last moved before it
 * stopped.
 *
 * \return Returns 1 if moving in the forward direction or -1 if moving in the
 * reverse direction.
 *
 */
static inline int16_t EQEP_getDirection(EQEP_REGS_Type *base)
{
    int16_t direction;

    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Return the direction of rotation.*/
    if ((base->QEPSTS & EQEP_QEPSTS_QDF_Msk) != 0U)
    {
        direction = 1;
    }
    else
    {
        direction = -1;
    }

    return (direction);
}

/*!
 *
 * \brief Enables individual EQEP module interrupt sources.
 *
 * \param[in] base is the base address of the EQEP module.
 * \param[in] intFlags is a bit mask of the interrupt sources to be enabled.
 *
 * This function enables EQEP module interrupt sources. The \e intFlags
 * parameter can be any of the following values OR'd together:
 * - \b EQEP_INT_POS_CNT_ERROR - Position counter error
 * - \b EQEP_INT_PHASE_ERROR - Quadrature phase error
 * - \b EQEP_INT_DIR_CHANGE - Quadrature direction change
 * - \b EQEP_INT_WATCHDOG - Watchdog time-out
 * - \b EQEP_INT_UNDERFLOW - Position counter underflow
 * - \b EQEP_INT_OVERFLOW - Position counter overflow
 * - \b EQEP_INT_POS_COMP_READY - Position-compare ready
 * - \b EQEP_INT_POS_COMP_MATCH - Position-compare match
 * - \b EQEP_INT_STROBE_EVNT_LATCH - Strobe event latch
 * - \b EQEP_INT_INDEX_EVNT_LATCH - Index event latch
 * - \b EQEP_INT_UNIT_TIME_OUT - Unit time-out
 *   \b EQEP_INT_QMA_ERROR - QMA error
 */
static inline void EQEP_enableInterrupt(EQEP_REGS_Type *base, uint16_t intFlags)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Enable the specified interrupts. */
    base->QEINT |= intFlags;
}

/*!
 *
 * \brief Disables individual EQEP module interrupt sources.
 *
 * \param[in] base is the base address of the EQEP module.
 * \param[in] intFlags is a bit mask of the interrupt sources to be disabled.
 *
 * This function disables EQEP module interrupt sources. The \e intFlags
 * parameter can be any of the following values OR'd together:
 * - \b EQEP_INT_POS_CNT_ERROR - Position counter error
 * - \b EQEP_INT_PHASE_ERROR - Quadrature phase error
 * - \b EQEP_INT_DIR_CHANGE - Quadrature direction change
 * - \b EQEP_INT_WATCHDOG - Watchdog time-out
 * - \b EQEP_INT_UNDERFLOW - Position counter underflow
 * - \b EQEP_INT_OVERFLOW - Position counter overflow
 * - \b EQEP_INT_POS_COMP_READY - Position-compare ready
 * - \b EQEP_INT_POS_COMP_MATCH - Position-compare match
 * - \b EQEP_INT_STROBE_EVNT_LATCH - Strobe event latch
 * - \b EQEP_INT_INDEX_EVNT_LATCH - Index event latch
 * - \b EQEP_INT_UNIT_TIME_OUT - Unit time-out
 *   \b EQEP_INT_QMA_ERROR - QMA error
 */
static inline void EQEP_disableInterrupt(EQEP_REGS_Type *base, uint16_t intFlags)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Disable the specified interrupts. */
    base->QEINT &= ~(intFlags);
}

/*!
 *
 * \brief Gets the current interrupt status.
 *
 * \param[in] base is the base address of the EQEP module.
 *
 * This function returns the interrupt status for the EQEP module
 * module.
 *
 * \return Returns the current interrupt status, enumerated as a bit field of
 * the following values:
 * - \b EQEP_INT_GLOBAL - Global interrupt flag
 * - \b EQEP_INT_POS_CNT_ERROR - Position counter error
 * - \b EQEP_INT_PHASE_ERROR - Quadrature phase error
 * - \b EQEP_INT_DIR_CHANGE - Quadrature direction change
 * - \b EQEP_INT_WATCHDOG - Watchdog time-out
 * - \b EQEP_INT_UNDERFLOW - Position counter underflow
 * - \b EQEP_INT_OVERFLOW - Position counter overflow
 * - \b EQEP_INT_POS_COMP_READY - Position-compare ready
 * - \b EQEP_INT_POS_COMP_MATCH - Position-compare match
 * - \b EQEP_INT_STROBE_EVNT_LATCH - Strobe event latch
 * - \b EQEP_INT_INDEX_EVNT_LATCH - Index event latch
 * - \b EQEP_INT_UNIT_TIME_OUT - Unit time-out
 *   \b EQEP_INT_QMA_ERROR - QMA error
 *
 */
static inline uint16_t EQEP_getInterruptStatus(EQEP_REGS_Type *base)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    return (base->QFLG);
}

/*!
 *
 * \brief Clears EQEP module interrupt sources.
 *
 * \param[in] base is the base address of the EQEP module.
 * \param[in] intFlags is a bit mask of the interrupt sources to be cleared.
 *
 * This function clears EQEP module interrupt flags. The \e intFlags
 * parameter can be any of the following values OR'd together:
 * - \b EQEP_INT_GLOBAL - Global interrupt flag
 * - \b EQEP_INT_POS_CNT_ERROR - Position counter error
 * - \b EQEP_INT_PHASE_ERROR - Quadrature phase error
 * - \b EQEP_INT_DIR_CHANGE - Quadrature direction change
 * - \b EQEP_INT_WATCHDOG - Watchdog time-out
 * - \b EQEP_INT_UNDERFLOW - Position counter underflow
 * - \b EQEP_INT_OVERFLOW - Position counter overflow
 * - \b EQEP_INT_POS_COMP_READY - Position-compare ready
 * - \b EQEP_INT_POS_COMP_MATCH - Position-compare match
 * - \b EQEP_INT_STROBE_EVNT_LATCH - Strobe event latch
 * - \b EQEP_INT_INDEX_EVNT_LATCH - Index event latch
 * - \b EQEP_INT_UNIT_TIME_OUT - Unit time-out
 *   \b EQEP_INT_QMA_ERROR - QMA error
 *
 * Note that the \b EQEP_INT_GLOBAL value is the global interrupt flag. In
 * order to get any further EQEP interrupts, this flag must be cleared.
 */
static inline void EQEP_clearInterruptStatus(EQEP_REGS_Type *base, uint16_t intFlags)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Clear the requested interrupt sources.*/
    base->QCLR = intFlags;
}

/*!
 *
 * \brief Forces individual EQEP module interrupts.
 *
 * \param[in] base is the base address of the EQEP module.
 * \param[in] intFlags is a bit mask of the interrupt sources to be forced.
 *
 * This function forces EQEP module interrupt flags. The \e intFlags
 * parameter can be any of the following values OR'd together:
 * - \b EQEP_INT_POS_CNT_ERROR
 * - \b EQEP_INT_PHASE_ERROR
 * - \b EQEP_INT_DIR_CHANGE
 * - \b EQEP_INT_WATCHDOG
 * - \b EQEP_INT_UNDERFLOW
 * - \b EQEP_INT_OVERFLOW
 * - \b EQEP_INT_POS_COMP_READY
 * - \b EQEP_INT_POS_COMP_MATCH
 * - \b EQEP_INT_STROBE_EVNT_LATCH
 * - \b EQEP_INT_INDEX_EVNT_LATCH
 * - \b EQEP_INT_UNIT_TIME_OUT
 * - \b EQEP_INT_QMA_ERROR
 */
static inline void EQEP_forceInterrupt(EQEP_REGS_Type *base, uint16_t intFlags)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Force the specified interrupts. */
    base->QFRC |= intFlags;
}

/*!
 *
 * \brief Gets the encoder error indicator.
 *
 * \param[in] base is the base address of the EQEP module.
 *
 * This function returns the error indicator for the EQEP module.  It is an
 * error for both of the signals of the quadrature input to change at the same
 * time.
 *
 * \return Returns \b true if an error has occurred and \b false otherwise.
 *
 */
static inline bool EQEP_getError(EQEP_REGS_Type *base)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Return the error indicator. */
    return ((base->QFLG & EQEP_QFLG_PHE_Msk) != 0U);
}

/*!
 *
 * \brief Returns content of the EQEP module status register
 *
 * \param[in] base is the base address of the EQEP module.
 *
 * This function returns the contents of the status register.  The value it
 * returns is an OR of the following values:
 *
 * - \b EQEP_STS_UNIT_POS_EVNT - Unit position event detected
 * - \b EQEP_STS_DIR_ON_1ST_IDX - If set, clockwise rotation (forward
 *   movement) occurred on the first index event
 * - \b EQEP_STS_DIR_FLAG - If set, movement is clockwise rotation
 * - \b EQEP_STS_DIR_LATCH - If set, clockwise rotation occurred on last
 *   index event marker
 * - \b EQEP_STS_CAP_OVRFLW_ERROR - Overflow occurred in EQEP capture timer
 * - \b EQEP_STS_CAP_DIR_ERROR - Direction change occurred between position
 *   capture events
 * - \b EQEP_STS_1ST_IDX_FLAG - Set by the occurrence of the first index
 *   pulse
 * - \b EQEP_STS_POS_CNT_ERROR - Position counter error occurred
 *
 * \return Returns the value of the QEP status register.
 *
 */
static inline uint16_t EQEP_getStatus(EQEP_REGS_Type *base)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Return the status register.*/
    return (base->QEPSTS & 0x00FFU);
}

/*!
 *
 * \brief Clears selected fields of the EQEP module status register
 *
 * \param[in] base is the base address of the EQEP module.
 * \param[in] statusFlags is the bit mask of the status flags to be cleared.
 *
 * This function clears the status register fields indicated by
 * \e statusFlags. The \e statusFlags parameter is the logical OR of any of
 * the following:
 *
 * - \b EQEP_STS_UNIT_POS_EVNT - Unit position event detected
 * - \b EQEP_STS_CAP_OVRFLW_ERROR - Overflow occurred in EQEP capture timer
 * - \b EQEP_STS_CAP_DIR_ERROR - Direction change occurred between position
 *   capture events
 * - \b EQEP_STS_1ST_IDX_FLAG - Set by the occurrence of the first index
 *   pulse
 *
 * \note Only the above status fields can be cleared. All others are
 * read-only, non-sticky fields.
 */
static inline void EQEP_clearStatus(EQEP_REGS_Type *base, uint16_t statusFlags)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Clear the requested interrupt sources.*/
    base->QEPSTS = statusFlags;
}

/*!
 *
 * \brief Configures EQEP module edge-capture unit.
 *
 * \param[in] base is the base address of the EQEP module.
 * \param[in] capPrescale is the prescaler setting of the EQEP capture timer clk.
 * \param[in] evntPrescale is the prescaler setting of the unit position event
 * frequency.
 *
 * This function configures the operation of the EQEP module edge-capture
 * unit.  The \e capPrescale parameter provides the configuration of the EQEP
 * capture timer clock rate. It determines by which power of 2 between 1 and
 * 128 inclusive SYSCLKOUT is divided. The macros for this parameter are in
 * the format of EQEP_CAPTURE_CLK_DIV_X, where X is the divide value. For
 * example, \b EQEP_CAPTURE_CLK_DIV_32 will give a capture timer clock
 * frequency that is SYSCLKOUT/32.
 *
 * The \e evntPrescale parameter determines how frequently a unit position
 * event occurs. The macro that can be passed this parameter is in the format
 * EQEP_UNIT_POS_EVNT_DIV_X, where X is the number of quadrature clock
 * periods between unit position events. For example,
 * \b EQEP_UNIT_POS_EVNT_DIV_16 will result in a unit position event
 * frequency of QCLK/16.
 */
static inline void EQEP_setCaptureConfig(EQEP_REGS_Type *base, EQEP_CAPCLKPrescale_t capPrescale,
                                         EQEP_UPEVNTPrescale_t evntPrescale)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Write new prescaler configurations to the appropriate registers.*/
    base->QCAPCTL = (base->QCAPCTL & ~(EQEP_QCAPCTL_UPPS_Msk | EQEP_QCAPCTL_CCPS_Msk)) |
                    ((uint16_t)evntPrescale | (uint16_t)capPrescale);
}

/*!
 *
 * \brief Enables the EQEP module edge-capture unit.
 *
 * \param[in] base is the base address of the EQEP module.
 *
 * This function enables operation of the EQEP module's edge-capture unit.
 */
static inline void EQEP_enableCapture(EQEP_REGS_Type *base)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Enable edge capture. */
    base->QCAPCTL |= EQEP_QCAPCTL_CEN_Set(1U);
}

/*!
 *
 * \brief Disables the EQEP module edge-capture unit.
 *
 * \param[in] base is the base address of the EQEP module.
 *
 * This function disables operation of the EQEP module's edge-capture unit.
 */
static inline void EQEP_disableCapture(EQEP_REGS_Type *base)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Disable edge capture. */
    base->QCAPCTL &= ~(EQEP_QCAPCTL_CEN_Set(1U));
}

/*!
 *
 * \brief Gets the encoder capture period.
 *
 * \param[in] base is the base address of the EQEP module.
 *
 * This function returns the period count value between the last successive
 * EQEP position events.
 *
 * \return The period count value between the last successive position events.
 *
 */
static inline uint16_t EQEP_getCapturePeriod(EQEP_REGS_Type *base)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Return the capture period. */
    return (base->QCPRD);
}

/*!
 *
 * \brief Gets the encoder capture timer value.
 *
 * \param[in] base is the base address of the EQEP module.
 *
 * This function returns the time base for the edge capture unit.
 *
 * \return The capture timer value.
 *
 */
static inline uint16_t EQEP_getCaptureTimer(EQEP_REGS_Type *base)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Return the capture timer value. */
    return base->QCTMR;
}

/*!
 *
 * \brief Enables the EQEP module position-compare unit.
 *
 * \param[in] base is the base address of the EQEP module.
 *
 * This function enables operation of the EQEP module's position-compare unit.
 */
static inline void EQEP_enableCompare(EQEP_REGS_Type *base)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Enable position compare. */
    base->QPOSCTL |= EQEP_QPOSCTL_PCE_Set(1);
}

/*!
 *
 * \brief Disables the EQEP module position-compare unit.
 *
 * \param[in] base is the base address of the EQEP module.
 *
 * This function disables operation of the EQEP module's position-compare
 * unit.
 */
static inline void EQEP_disableCompare(EQEP_REGS_Type *base)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Disable position compare. */
    base->QPOSCTL &= ~(EQEP_QPOSCTL_PCE_Set(1));
}

/*!
 *
 * \brief Configures the position-compare unit's sync output pulse width.
 *
 * \param[in] base is the base address of the EQEP module.
 * \param[in] cycles is the width of the pulse that can be generated on a
 * position-compare event.  It is in units of 4 SYSCLKOUT cycles.
 *
 * This function configures the width of the sync output pulse.  The width of
 * the pulse will be \e cycles * 4 * the width of a SYSCLKOUT cycle.  The
 * maximum width is 4096 * 4 * SYSCLKOUT cycles.
 */
static inline void EQEP_setComparePulseWidth(EQEP_REGS_Type *base, uint16_t cycles)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));
    assert(cycles <= (EQEP_QPOSCTL_PCSPW_Msk + 1U));

    /* Set the pulse width. */
    base->QPOSCTL = (base->QPOSCTL & ~(uint16_t)EQEP_QPOSCTL_PCSPW_Msk) | (cycles - 1U);
}

/*!
 *
 * \brief Loads the EQEP module unit timer period as number of SYSCLK cycles.
 *
 * \param[in] base is the base address of the EQEP module.
 * \param[in] period is period value at which a unit time-out interrupt is set.
 *
 * This function sets the unit time-out interrupt when it matches the value
 * specified by \e period
 * The unit timer is clocked by SYSCLKOUT
 */
static inline void EQEP_loadUnitTimer(EQEP_REGS_Type *base, uint32_t period)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Set the period of the unit timer. */
    base->QUPRD = period;
}

/*!
 *
 * \brief Enables the EQEP module unit timer.
 *
 * \param[in] base is the base address of the EQEP module.
 * \param[in] period is period value at which a unit time-out interrupt is set.
 *
 * This function enables operation of the EQEP module's peripheral unit timer.
 * The unit timer is clocked by SYSCLKOUT and will set the unit time-out
 * interrupt when it matches the value specified by \e period.
 */
static inline void EQEP_enableUnitTimer(EQEP_REGS_Type *base, uint32_t period)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Set the period of the unit timer. */
    base->QUPRD = period;

    /* Enable peripheral unit timer. */
    base->QEPCTL |= EQEP_QEPCTL_UTE_Set(1);
}

/*!
 *
 * \brief Disables the EQEP module unit timer.
 *
 * \param[in] base is the base address of the EQEP module.
 *
 * This function disables operation of the EQEP module's peripheral
 * unit timer.
 */
static inline void EQEP_disableUnitTimer(EQEP_REGS_Type *base)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Disable peripheral unit timer. */
    base->QEPCTL &= ~(EQEP_QEPCTL_UTE_Set(1));
}

/*!
 *
 * \brief Enables the EQEP module watchdog timer.
 *
 * \param[in] base is the base address of the EQEP module.
 * \param[in] period is watchdog period value at which a time-out will occur if
 * no quadrature-clock event is detected.
 *
 * This function enables operation of the EQEP module's peripheral watchdog
 * timer.
 *
 * \note When selecting \e period, note that the watchdog timer is clocked
 * from SYSCLKOUT/64.
 */
static inline void EQEP_enableWatchdog(EQEP_REGS_Type *base, uint16_t period)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Set the timeout count for the EQEP peripheral watchdog timer. */
    base->QWDPRD = period;

    /* Enable peripheral watchdog. */
    base->QEPCTL |= EQEP_QEPCTL_WDE_Set(1);
}

/*!
 *
 * \brief Disables the EQEP module watchdog timer.
 *
 * \param[in] base is the base address of the EQEP module.
 *
 * This function disables operation of the EQEP module's peripheral watchdog
 * timer.
 */
static inline void EQEP_disableWatchdog(EQEP_REGS_Type *base)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Disable peripheral watchdog. */
    base->QEPCTL &= ~(EQEP_QEPCTL_WDE_Set(1));
}

/*!
 *
 * \brief Sets the EQEP module watchdog timer value.
 *
 * \param[in] base is the base address of the EQEP module.
 * \param[in] value is the value to be written to the watchdog timer.
 *
 * This function sets the EQEP module's watchdog timer value.
 */
static inline void EQEP_setWatchdogTimerValue(EQEP_REGS_Type *base, uint16_t value)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Write the value to the watchdog timer register. */
    base->QWDTMR = value;
}

/*!
 *
 * \brief Gets the EQEP module watchdog timer value.
 *
 * \param[in] base is the base address of the EQEP module.
 *
 * \return Returns the current watchdog timer value.
 *
 */
static inline uint16_t EQEP_getWatchdogTimerValue(EQEP_REGS_Type *base)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Read the value from the watchdog timer register. */
    return (base->QWDTMR);
}

/*!
 *
 * \brief Configures the mode in which the position counter is initialized.
 *
 * \param[in] base is the base address of the EQEP module.
 * \param[in] initMode is the configuration for initializing the position count.
 * See below for a description of this parameter.
 *
 * This function configures the events on which the position count can be
 * initialized.  The \e initMode parameter provides the mode as either
 * \b EQEP_INIT_DO_NOTHING (no action configured) or one of the following
 * strobe events, index events, or a logical OR of both a strobe event and an
 * index event.
 *
 * - \b EQEP_INIT_RISING_STROBE or \b EQEP_INIT_EDGE_DIR_STROBE specify
 *   which strobe event will initialize the position counter.
 * - \b EQEP_INIT_RISING_INDEX or \b EQEP_INIT_FALLING_INDEX specify
 *   which index event will initialize the position counter.
 *
 * Use EQEP_setSWPositionInit() to cause a software initialization and
 * EQEP_setInitialPosition() to set the value that gets loaded into the
 * position counter upon initialization.
 */
static inline void EQEP_setPositionInitMode(EQEP_REGS_Type *base, uint16_t initMode)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Set the init mode in the QEP Control register. */
    base->QEPCTL = (base->QEPCTL & ~(EQEP_QEPCTL_IEI_Msk | EQEP_QEPCTL_SEI_Msk)) | initMode;
}

/*!
 *
 * \brief Sets the software initialization of the encoder position counter.
 *
 * \param[in] base is the base address of the EQEP module.
 * \param[in] initialize is a flag to specify if software initialization of the
 * position counter is enabled.
 *
 * This function does a software initialization of the position counter when
 * the \e initialize parameter is \b true. When \b false, the QEPCTL[SWI] bit
 * is cleared and no action is taken.
 *
 * The init value to be loaded into the position counter can be set with
 * EQEP_setInitialPosition().  Additional initialization causes can be
 * configured with EQEP_setPositionInitMode().
 */
static inline void EQEP_setSWPositionInit(EQEP_REGS_Type *base, bool initialize)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Set or clear the software initialization bit. */
    if (initialize)
    {
        base->QEPCTL |= EQEP_QEPCTL_SWI_Set(1U);
    }
    else
    {
        base->QEPCTL &= ~(EQEP_QEPCTL_SWI_Set(1U));
    }
}

/*!
 *
 * \brief Sets the init value for the encoder position counter.
 *
 * \param[in] base is the base address of the EQEP module.
 * \param[in] position is the value to be written to the position counter upon.
 * initialization.
 *
 * This function sets the init value for position of the encoder. See
 * EQEP_setPositionInitMode() to set the initialization cause or
 * EQEP_setSWPositionInit() to cause a software initialization.
 */
static inline void EQEP_setInitialPosition(EQEP_REGS_Type *base, uint32_t position)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Write position to position counter init register */
    base->QPOSINIT = position;
}

/*!
 *
 * \brief Configures the quadrature modes in which the position count can be latched.
 *
 * \param[in] base is the base address of the EQEP module.
 * \param[in] latchMode is the configuration for latching of the position count
 * and several other registers.  See below for a description of this
 * parameter.
 *
 * This function configures the events on which the position count and several
 * other registers can be latched.  The \e latchMode parameter provides the
 * mode as the logical OR of several values.
 *
 * - \b EQEP_LATCH_CNT_READ_BY_CPU or \b EQEP_LATCH_UNIT_TIME_OUT specify
 *   the event that latches the position counter.  This latch register can be
 *   read using EQEP_getPositionLatch(). The capture timer and capture
 *   period are also latched based on this setting, and can be read using
 *   EQEP_getCaptureTimerLatch() and EQEP_getCapturePeriodLatch().
 * - \b EQEP_LATCH_RISING_STROBE or \b EQEP_LATCH_EDGE_DIR_STROBE
 *   specify which strobe event will latch the position counter into the
 *   strobe position latch register.  This register can be read with
 *    EQEP_getStrobePositionLatch().
 * - \b EQEP_LATCH_RISING_INDEX, \b EQEP_LATCH_FALLING_INDEX, or
 *   \b EQEP_LATCH_SW_INDEX_MARKER specify which index event will latch the
 *   position counter into the index position latch register.  This register
 *   can be read with EQEP_getIndexPositionLatch().
 */
static inline void EQEP_setLatchMode(EQEP_REGS_Type *base, uint32_t latchMode)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Set the latch mode in the QEP Control register. */
    base->QEPCTL = (base->QEPCTL & ~(EQEP_QEPCTL_QCLM_Msk | EQEP_QEPCTL_IEL_Msk | EQEP_QEPCTL_SEL_Msk)) | latchMode;
}

/*!
 *
 * \brief Gets the encoder position that was latched on an index event.
 *
 * \param[in] base is the base address of the EQEP module.
 *
 * This function returns the value in the index position latch register. The
 * position counter is latched into this register on either a rising index
 * edge, a falling index edge, or a software index marker. This is configured
 * using EQEP_setLatchMode().
 *
 * \return The position count latched on an index event.
 *
 */
static inline uint32_t EQEP_getIndexPositionLatch(EQEP_REGS_Type *base)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Return the current position counter. */
    return (base->QPOSILAT);
}

/*!
 *
 * \brief Gets the encoder position that was latched on a strobe event.
 *
 * \param[in] base is the base address of the EQEP module.
 *
 * This function returns the value in the strobe position latch register. The
 * position counter can be configured to be latched into this register on
 * rising strobe edges only or on rising strobe edges while moving clockwise
 * and falling strobe edges while moving counter-clockwise. This is configured
 * using EQEP_setLatchMode().
 *
 * \return The position count latched on a strobe event.
 *
 */
static inline uint32_t EQEP_getStrobePositionLatch(EQEP_REGS_Type *base)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Return the current position counter. */
    return (base->QPOSSLAT);
}

/*!
 *
 * \brief Gets the encoder position that was latched on a unit time-out event.
 *
 * \param[in] base is the base address of the EQEP module.
 *
 * This function returns the value in the position latch register. The
 * position counter is latched into this register either on a unit time-out
 * event.
 *
 * \return The position count latch register value.
 *
 */
static inline uint32_t EQEP_getPositionLatch(EQEP_REGS_Type *base)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Return the current position counter. */
    return (base->QPOSLAT);
}

/*!
 *
 * \brief Gets the encoder capture timer latch.
 *
 * \param[in] base is the base address of the EQEP module.
 *
 * This function returns the value in the capture timer latch register.  The
 * capture timer value is latched into this register either on a unit time-out
 * event or upon the CPU reading the EQEP position counter. This is configured
 * using EQEP_setLatchMode().
 *
 * \return The edge-capture timer latch value.
 *
 */
static inline uint16_t EQEP_getCaptureTimerLatch(EQEP_REGS_Type *base)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Return the current position counter. */
    return (base->QCTMRLAT);
}

/*!
 *
 * \brief Gets the encoder capture period latch.
 *
 * \param[in] base is the base address of the EQEP module.
 *
 * This function returns the value in the capture period latch register.  The
 * capture period value is latched into this register either on a unit
 * time-out event or upon the CPU reading the EQEP position counter. This is
 * configured using EQEP_setLatchMode().
 *
 * \return The edge-capture period latch value.
 *
 */
static inline uint16_t EQEP_getCapturePeriodLatch(EQEP_REGS_Type *base)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Return the current position counter. */
    return (base->QCPRDLAT);
}

/*!
 *
 * \brief Set the quadrature mode adapter (QMA) module mode
 *
 * \param[in] base is the base address of the EQEP module.
 * \param[in] qmaMode is the mode in which the QMA module will operate.
 *
 * This function sets the quadrature mode adapter module mode. The possible
 * modes are passed to the function through the \e qmaMode parameter which
 * can take the values EQEP_QMA_MODE_BYPASS, EQEP_QMA_MODE_1, or
 * EQEP_QMA_MODE_2.
 *
 * To use the QMA module, you must first put the EQEP module into
 * direction-count mode (\b EQEP_CONFIG_CLOCK_DIR) using EQEP_setDecoderConfig().
 */
static inline void EQEP_setQMAModuleMode(EQEP_REGS_Type *base, EQEP_QMAMode_t qmaMode)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    if(qmaMode == kEQEP_BIN_MODE)
    {
        base->QMACTRL = (base->QMACTRL & ~EQEP_QMACTRL_MODE_Msk) | EQEP_QMACTRL_BIN_MODE_Msk;
    }
    else
    {
        /* Write the QMA module mode into the appropriate register. */
        base->QMACTRL = (base->QMACTRL & ~(EQEP_QMACTRL_MODE_Msk|EQEP_QMACTRL_BIN_MODE_Msk)) | (uint16_t)qmaMode;
    }
}

/*!
 *
 * \brief Set the strobe input source of the EQEP module.
 *
 * \param[in] base is the base address of the EQEP module.
 * \param[in] strobeSrc is the source of the strobe signal.
 *
 * This function sets the source of the EQEP module's strobe signal. The
 * possible values of the \e strobeSrc parameter are
 * - \b EQEP_STROBE_FROM_GPIO - The strobe is used as-is after passing through
 *   the polarity select logic.
 * - \b EQEP_STROBE_OR_ADCSOCA - The strobe is OR'd with the ADCSOCA signal
 *   after passing through the polarity select logic.
 * - \b EQEP_STROBE_OR_ADCSOCB - The strobe is OR'd with the ADCSOCB signal
 *   after passing through the polarity select logic.
 */
static inline void EQEP_setStrobeSource(EQEP_REGS_Type *base, EQEP_StrobeSource_t strobeSrc)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Write the strobe source selection into the appropriate register. */
    base->QEPSTROBESEL = (base->QEPSTROBESEL & ~EQEP_QEPSTROBESEL_STROBESEL_Msk) | (uint16_t)strobeSrc;
    base->QEPSRCSEL = (base->QEPSRCSEL & ~EQEP_QEPSRCSEL_QEPSSEL_Msk) | (EQEP_QEPSRCSEL_QEPSSEL_Set(strobeSrc));
}

/*!
 *
 * \brief Enables the index direction enhancement mode of the EQEP module
 *
 * \param[in] base is the base address of the EQEP module.
 *
 * This function enables the enhancement mode for direction change
 * during Index event
 *
 */
static inline void EQEP_enableDirectionChangeDuringIndex(EQEP_REGS_Type *base)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /*Sets the index direction enhancement bit */
    base->QDECCTL |= EQEP_QDECCTL_QIDIRE_Set(1U);
}

/*!
 *
 * \brief Disables the index direction enhancement mode of the EQEP module
 *
 * \param[in] base is the base address of the EQEP module.
 *
 * This function disables the enhancement mode for direction change
 * during Index event
 */
static inline void EQEP_disableDirectionChangeDuringIndex(EQEP_REGS_Type *base)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /*Clears the index direction enhancement bit */
    base->QDECCTL &= ~(EQEP_QDECCTL_QIDIRE_Set(1U));
}

/*!
 * \brief Selects the source for EQEPA/B/I signals
 *
 * \param[in] base is the base address of the EQEP module.
 * \param[in] sourceConfig is the structure that contains source configuration
 *
 * This function configures the sources for QEPA,QEPB and Index of EQEP module
 */
static inline void EQEP_selectSource(EQEP_REGS_Type *base, EQEP_SourceSelect_t sourceConfig)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Selecting sources for EQEP signals */
    base->QEPSRCSEL =
        (base->QEPSRCSEL & ~(EQEP_QEPSRCSEL_QEPASEL_Msk | EQEP_QEPSRCSEL_QEPBSEL_Msk | EQEP_QEPSRCSEL_QEPISEL_Msk)) |
        ((uint32_t)((uint32_t)(sourceConfig.sourceA) << EQEP_QEPSRCSEL_QEPASEL_Pos) |
         (uint32_t)((uint32_t)(sourceConfig.sourceB) << EQEP_QEPSRCSEL_QEPBSEL_Pos) |
         (uint32_t)((uint32_t)(sourceConfig.sourceIndex) << EQEP_QEPSRCSEL_QEPISEL_Pos));
}

/*!
 *
 * \brief Set the emulation mode of the EQEP module.
 *
 * \param[in] base is the base address of the EQEP module.
 * \param[in] emuMode is the mode operation upon an emulation suspend.
 *
 * This function sets the EQEP module's emulation mode. This mode determines
 * how the timers are affected by an emulation suspend. Valid values for the
 * \e emuMode parameter are the following:
 *
 * - \b EQEP_EMULATIONMODE_STOPIMMEDIATELY - The position counter, watchdog
 *   counter, unit timer, and capture timer all stop immediately.
 * - \b EQEP_EMULATIONMODE_STOPATROLLOVER - The position counter, watchdog
 *   counter, unit timer all count until period rollover. The capture timer
 *   counts until the next unit period event.
 * - \b EQEP_EMULATIONMODE_RUNFREE - The position counter, watchdog counter,
 *   unit timer, and capture timer are all unaffected by an emulation suspend.
 */
static inline void EQEP_setEmulationMode(EQEP_REGS_Type *base, EQEP_EmulationMode_t emuMode)
{
    /* Check the arguments. */
    assert(EQEP_isBaseValid(base));

    /* Write the emulation mode to the FREE_SOFT bits. */
    base->QEPCTL = (base->QEPCTL & ~EQEP_QEPCTL_FREE_SOFT_Msk) | ((uint16_t)emuMode << EQEP_QEPCTL_FREE_SOFT_Pos);
}

/*!
 *
 * \brief Configures EQEP module position-compare unit.
 *
 * \param[in] base is the base address of the EQEP module.
 * \param[in] config is the configuration for the EQEP module
 * position-compare unit.  See below for a description of this parameter.
 * \param[in] compareValue is the value to which the position count value is
 * compared for a position-compare event.
 * \param[in] cycles is the width of the pulse that can be generated on a
 * position-compare event.  It is in units of 4 SYSCLKOUT cycles.
 *
 * This function configures the operation of the EQEP module position-compare
 * unit.  The \e config parameter provides the configuration of the
 * position-compare unit and is the logical OR of several values:
 *
 * - \b EQEP_COMPARE_NO_SYNC_OUT, \b EQEP_COMPARE_IDX_SYNC_OUT, or
 *   \b EQEP_COMPARE_STROBE_SYNC_OUT specify if there is a sync output pulse
 *   and which pin should be used.
 * - \b EQEP_COMPARE_NO_SHADOW, \b EQEP_COMPARE_LOAD_ON_ZERO, or
 *   \b EQEP_COMPARE_LOAD_ON_MATCH specify if a shadow is enabled and when
 *   should the load should occur--QPOSCNT = 0 or QPOSCNT = QPOSCOMP.
 *
 * The \e cycles is used to select the width of the sync output pulse. The
 * width of the resulting pulse will be \e cycles * 4 * the width of a
 * SYSCLKOUT cycle. The maximum width is 4096 * 4 * SYSCLKOUT cycles.
 *
 * \note You can set the sync pulse width independently using the
 * EQEP_setComparePulseWidth() function.
 */
extern void EQEP_setCompareConfig(EQEP_REGS_Type *base, uint16_t config, uint32_t compareValue, uint16_t cycles);

/*!
 *
 * \brief Sets the polarity of the EQEP module's input signals.
 *
 * \param[in] base is the base address of the EQEP module.
 * \param[in] invertQEPA is the flag to negate the QEPA input.
 * \param[in] invertQEPB is the flag to negate the QEPA input.
 * \param[in] invertIndex is the flag to negate the index input.
 * \param[in] invertStrobe is the flag to negate the strobe input.
 *
 * This function configures the polarity of the inputs to the EQEP module. To
 * negate the polarity of any of the input signals, pass \b true into its
 * corresponding parameter in this function. Pass \b false to leave it as-is.
 */
extern void EQEP_setInputPolarity(EQEP_REGS_Type *base, bool invertQEPA, bool invertQEPB, bool invertIndex,
                                  bool invertStrobe);



/*!
 * \brief Register user callback function to eqep interrupt handler.
 *
 * \details This function registers user callback function for eqep interrupt handler which uses IRQ. The relative IRQ
 * will be enabled in the NVIC and the priority will be configured at the same time
 *
 * \param[in] base is the base address of the EQEP module.
 * \param[in] func EQEP user callback
 * \param[in] priority IRQ priority
 *
 * \retval kSTATUS_SUCCESS Success to the operation
 * \retval kSTATUS_FAIL Register to a EQEP which has been registered already. Need to call \ref
 *         EQEP_unregisterCallback() before the re-registration
 */
status_t EQEP_registerCallback(EQEP_REGS_Type *base, EQEP_Callback_t func, uint32_t priority);


/*!
 * \brief Unregister user callback function to eqep interrupt handler.
 *
 * \details This function clears the registered user callback function, and disable the relative IRQ in the NVIC
 *
 * \param[in] base is the base address of the EQEP module.
 *
 * \retval kSTATUS_SUCCESS Success to the operation
 * \retval kSTATUS_FAIL The EQEP hasn't been registered to a callback
 */
status_t EQEP_unregisterCallback(EQEP_REGS_Type *base);
 
#ifdef __cplusplus
}
#endif

/*!
 * @}
 */ /* end of DRV_HTE_EQEP */

#endif /* HTE_EQEP_H */
