/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_xbar.h
 * \brief SDK XBAR driver header file
 * \version 1.0.0
 */

#ifndef HTE_XBAR_H
#define HTE_XBAR_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_common.h"

/*!
 * \addtogroup DRV_HTE_XBAR XBAR Driver
 *
 * \brief SDK XBAR driver
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! \brief XBAR driver version */
#define XBAR_DRIVER_VERSION MAKE_VERSION('V', 1U, 0U, 0U)

/*! \brief The input index number of the INPUT XBAR */
typedef enum
{
    kXBAR_INPUT1  = 0U,  /*!< INPUT1 of the INPUT XBAR */
    kXBAR_INPUT2  = 1U,  /*!< INPUT2 of the INPUT XBAR */
    kXBAR_INPUT3  = 2U,  /*!< INPUT3 of the INPUT XBAR */
    kXBAR_INPUT4  = 3U,  /*!< INPUT4 of the INPUT XBAR */
    kXBAR_INPUT5  = 4U,  /*!< INPUT5 of the INPUT XBAR */
    kXBAR_INPUT6  = 5U,  /*!< INPUT6 of the INPUT XBAR */
    kXBAR_INPUT7  = 6U,  /*!< INPUT7 of the INPUT XBAR */
    kXBAR_INPUT8  = 7U,  /*!< INPUT8 of the INPUT XBAR */
    kXBAR_INPUT9  = 8U,  /*!< INPUT9 of the INPUT XBAR */
    kXBAR_INPUT10 = 9U,  /*!< INPUT10 of the INPUT XBAR */
    kXBAR_INPUT11 = 10U, /*!< INPUT11 of the INPUT XBAR */
    kXBAR_INPUT12 = 11U, /*!< INPUT12 of the INPUT XBAR */
    kXBAR_INPUT13 = 12U, /*!< INPUT13 of the INPUT XBAR */
    kXBAR_INPUT14 = 13U, /*!< INPUT14 of the INPUT XBAR */
    kXBAR_INPUT15 = 14U, /*!< INPUT15 of the INPUT XBAR */
    kXBAR_INPUT16 = 15U, /*!< INPUT16 of the INPUT XBAR */
} XBAR_InputNum_t;

/*! \brief The definition of the input flag selection word */
typedef union
{
    uint32_t U; /*!< The flag word */

    struct
    {
        uint32_t shift    : 8;  /*!< The shift position of the input flag */
        uint32_t index    : 4;  /*!< The register index of the input flag */
        uint32_t reserved : 20; /*!< Reserved */
    } B;                        /*!< The flag bitfield */
} XBAR_InputFlag_t;

#define XBAR_INPUTFLAG_SHIFT_Pos (0U)                                /*!< Shift Position 0 */
#define XBAR_INPUTFLAG_SHIFT_Msk (0xFFU << XBAR_INPUTFLAG_SHIFT_Pos) /*!< Shift Mask 0x000000FF */
#define XBAR_INPUTFLAG_SHIFT_Set(x) \
    ((((uint32_t)(x)) << XBAR_INPUTFLAG_SHIFT_Pos) & XBAR_INPUTFLAG_SHIFT_Msk) /*!< Shift Set Value */
#define XBAR_INPUTFLAG_SHIFT_Get(x) \
    ((((uint32_t)(x)) & XBAR_INPUTFLAG_SHIFT_Msk) >> XBAR_INPUTFLAG_SHIFT_Pos) /*!< Shift Get Value */

#define XBAR_INPUTFLAG_INDEX_Pos (8U)                               /*!< Index Position 8 */
#define XBAR_INPUTFLAG_INDEX_Msk (0xFU << XBAR_INPUTFLAG_INDEX_Pos) /*!< Index Mask 0x00000F00 */
#define XBAR_INPUTFLAG_INDEX_Set(x) \
    ((((uint32_t)(x)) << XBAR_INPUTFLAG_INDEX_Pos) & XBAR_INPUTFLAG_INDEX_Msk) /*!< Index Set Value */
#define XBAR_INPUTFLAG_INDEX_Get(x) \
    ((((uint32_t)(x)) & XBAR_INPUTFLAG_INDEX_Msk) >> XBAR_INPUTFLAG_INDEX_Pos) /*!< Index Get Value */

/*! \brief Generate an input flag word */
#define XBAR_INPUTFLAG(idx, sft) ((XBAR_InputFlag_t){ .B = { .shift = (sft), .index = (idx) } })

/*! \brief The flag index number of the XBAR */
typedef enum
{
    kXBAR_FLAG1 = 0U, /*!< FLAG1 of the XBAR */
    kXBAR_FLAG2 = 1U, /*!< FLAG2 of the XBAR */
    kXBAR_FLAG3 = 2U, /*!< FLAG3 of the XBAR */
    kXBAR_FLAG4 = 3U, /*!< FLAG4 of the XBAR */
    kXBAR_FLAG5 = 4U, /*!< FLAG5 of the XBAR */
} XBAR_FlagNum_t;

/*! \brief The MUX Mode of the XBAR*/
typedef enum
{
    kXBAR_MUX_MODE_38x = 0U, /*!< The MUX aligned with 2838x */
    kXBAR_MUX_MODE_37x = 1U, /*!< The MUX aligned with 2837x */
} XBAR_MuxMode_t;

/*!
 * \brief The mask for XBAR MUX
 *
 * \details The definitions of the XBAR MUX masks which can be used by the following functions
 *  - \ref XBAR_enableEPWMMux(), \ref XBAR_disableEPWMMux()
 *  - \ref XBAR_enableCLBMux(), \ref XBAR_disableCLBMux()
 *  - \ref XBAR_enableOutputMux(), \ref XBAR_disableOutputMux()
 */
typedef enum
{
    kXBAR_MUX00 = (0x1U << 0U),  /*!< The mask for XBAR MUX 0 */
    kXBAR_MUX01 = (0x1U << 1U),  /*!< The mask for XBAR MUX 1 */
    kXBAR_MUX02 = (0x1U << 2U),  /*!< The mask for XBAR MUX 2 */
    kXBAR_MUX03 = (0x1U << 3U),  /*!< The mask for XBAR MUX 3 */
    kXBAR_MUX04 = (0x1U << 4U),  /*!< The mask for XBAR MUX 4 */
    kXBAR_MUX05 = (0x1U << 5U),  /*!< The mask for XBAR MUX 5 */
    kXBAR_MUX06 = (0x1U << 6U),  /*!< The mask for XBAR MUX 6 */
    kXBAR_MUX07 = (0x1U << 7U),  /*!< The mask for XBAR MUX 7 */
    kXBAR_MUX08 = (0x1U << 8U),  /*!< The mask for XBAR MUX 8 */
    kXBAR_MUX09 = (0x1U << 9U),  /*!< The mask for XBAR MUX 9 */
    kXBAR_MUX10 = (0x1U << 10),  /*!< The mask for XBAR MUX 10 */
    kXBAR_MUX11 = (0x1U << 11U), /*!< The mask for XBAR MUX 11 */
    kXBAR_MUX12 = (0x1U << 12U), /*!< The mask for XBAR MUX 12 */
    kXBAR_MUX13 = (0x1U << 13U), /*!< The mask for XBAR MUX 13 */
    kXBAR_MUX14 = (0x1U << 14U), /*!< The mask for XBAR MUX 14 */
    kXBAR_MUX15 = (0x1U << 15U), /*!< The mask for XBAR MUX 15 */
    kXBAR_MUX16 = (0x1U << 16U), /*!< The mask for XBAR MUX 16 */
    kXBAR_MUX17 = (0x1U << 17U), /*!< The mask for XBAR MUX 17 */
    kXBAR_MUX18 = (0x1U << 18U), /*!< The mask for XBAR MUX 18 */
    kXBAR_MUX19 = (0x1U << 19U), /*!< The mask for XBAR MUX 19 */
    kXBAR_MUX20 = (0x1U << 20U), /*!< The mask for XBAR MUX 20 */
    kXBAR_MUX21 = (0x1U << 21U), /*!< The mask for XBAR MUX 21 */
    kXBAR_MUX22 = (0x1U << 22U), /*!< The mask for XBAR MUX 22 */
    kXBAR_MUX23 = (0x1U << 23U), /*!< The mask for XBAR MUX 23 */
    kXBAR_MUX24 = (0x1U << 24U), /*!< The mask for XBAR MUX 24 */
    kXBAR_MUX25 = (0x1U << 25U), /*!< The mask for XBAR MUX 25 */
    kXBAR_MUX26 = (0x1U << 26U), /*!< The mask for XBAR MUX 26 */
    kXBAR_MUX27 = (0x1U << 27U), /*!< The mask for XBAR MUX 27 */
    kXBAR_MUX28 = (0x1U << 28U), /*!< The mask for XBAR MUX 28 */
    kXBAR_MUX29 = (0x1U << 29U), /*!< The mask for XBAR MUX 29 */
    kXBAR_MUX30 = (0x1U << 30U), /*!< The mask for XBAR MUX 30 */
#if defined(__CC_ARM)
#pragma push
#pragma diag_suppress 66
#endif
    kXBAR_MUX31 = (0x1U << 31U), /*!< The mask for XBAR MUX 31 */
#if defined(__CC_ARM)
#pragma pop
#endif
} XBAR_MUX_t;

/*! \brief The definition of the configuration word for XBAR MUX */
typedef union
{
    uint32_t U; /*!< The flag word */

    struct
    {
        uint32_t mux       : 2;  /*!< The value of the MUX selection */
        uint32_t reserved0 : 6;  /*!< Reserved */
        uint32_t index     : 8;  /*!< The index of the MUX bitfield */
        uint32_t reserved1 : 16; /*!< Reserved */
    } B;                         /*!< The flag bitfield */
} XBAR_MuxConfig_t;

#define XBAR_MUXCONFIG_MUX_Pos (0U)                             /*!< Mux Position 0 */
#define XBAR_MUXCONFIG_MUX_Msk (0x3U << XBAR_MUXCONFIG_MUX_Pos) /*!< Mux Mask 0x00000003 */
#define XBAR_MUXCONFIG_MUX_Set(x) \
    ((((uint32_t)(x)) << XBAR_MUXCONFIG_MUX_Pos) & XBAR_MUXCONFIG_MUX_Msk) /*!< Mux Set Value */
#define XBAR_MUXCONFIG_MUX_Get(x) \
    ((((uint32_t)(x)) & XBAR_MUXCONFIG_MUX_Msk) >> XBAR_MUXCONFIG_MUX_Pos) /*!< Mux Get Value */

#define XBAR_MUXCONFIG_INDEX_Pos (8U)                                /*!< Index Position 8 */
#define XBAR_MUXCONFIG_INDEX_Msk (0xFFU << XBAR_MUXCONFIG_INDEX_Pos) /*!< Index Mask 0x0000FF00 */
#define XBAR_MUXCONFIG_INDEX_Set(x) \
    ((((uint32_t)(x)) << XBAR_MUXCONFIG_INDEX_Pos) & XBAR_MUXCONFIG_INDEX_Msk) /*!< Index Set Value */
#define XBAR_MUXCONFIG_INDEX_Get(x) \
    ((((uint32_t)(x)) & XBAR_MUXCONFIG_INDEX_Msk) >> XBAR_MUXCONFIG_INDEX_Pos) /*!< Index Get Value */

/*! \brief Generate an input flag word */
#define XBAR_MUXCONFIG(idx, mx) ((XBAR_MuxConfig_t){ .B = { .mux = mx, .index = idx } })

/*! \brief The trip index number of the ePWM XBAR*/
typedef enum
{
    kXBAR_TRIP4  = 0U, /*!< TRIP4 of the ePWM XBAR */
    kXBAR_TRIP5  = 1U, /*!< TRIP5 of the ePWM XBAR */
    kXBAR_TRIP7  = 2U, /*!< TRIP7 of the ePWM XBAR */
    kXBAR_TRIP8  = 3U, /*!< TRIP8 of the ePWM XBAR */
    kXBAR_TRIP9  = 4U, /*!< TRIP9 of the ePWM XBAR */
    kXBAR_TRIP10 = 5U, /*!< TRIP10 of the ePWM XBAR */
    kXBAR_TRIP11 = 6U, /*!< TRIP11 of the ePWM XBAR */
    kXBAR_TRIP12 = 7U, /*!< TRIP12 of the ePWM XBAR */
} XBAR_TripNum_t;

/*! \brief The number of ePWM XBAR MUX per MUX word */
#define XBAR_EPWM_MUX_PER_WORD (16U)

/*! \brief Redefine the configuration word for ePWM XBAR MUX */
typedef XBAR_MuxConfig_t XBAR_EPWMMuxConfig_t;

/*! \brief The identification key to lock the ePWM XBAR */
#define XBAR_EPWM_LOCK_KEY (0x5A5AU)

/*! \brief The AUXSIG index number for CLB XBAR */
typedef enum
{
    kXBAR_AUXSIG0 = 0U, /*!< AUXSIG0 of the CLB XBAR */
    kXBAR_AUXSIG1 = 1U, /*!< AUXSIG1 of the CLB XBAR */
    kXBAR_AUXSIG2 = 2U, /*!< AUXSIG2 of the CLB XBAR */
    kXBAR_AUXSIG3 = 3U, /*!< AUXSIG3 of the CLB XBAR */
    kXBAR_AUXSIG4 = 4U, /*!< AUXSIG4 of the CLB XBAR */
    kXBAR_AUXSIG5 = 5U, /*!< AUXSIG5 of the CLB XBAR */
    kXBAR_AUXSIG6 = 6U, /*!< AUXSIG6 of the CLB XBAR */
    kXBAR_AUXSIG7 = 7U, /*!< AUXSIG7 of the CLB XBAR */
} XBAR_AuxSigNum_t;

/*! \brief The number of CLB XBAR MUX per MUX word */
#define XBAR_CLB_MUX_PER_WORD (16U)

/*! \brief Redefine the configuration word for CLB XBAR MUX */
typedef XBAR_MuxConfig_t XBAR_CLBMuxConfig_t;

/*! \brief The identification key to lock the CLB XBAR */
#define XBAR_CLB_LOCK_KEY (0x5A5AU)

/*! \brief The output index number for OUTPUT XBAR */
typedef enum
{
    kXBAR_OUTPUT1 = 0U, /*!< OUTPUT1 of the OUTPUT XBAR */
    kXBAR_OUTPUT2 = 1U, /*!< OUTPUT2 of the OUTPUT XBAR */
    kXBAR_OUTPUT3 = 2U, /*!< OUTPUT3 of the OUTPUT XBAR */
    kXBAR_OUTPUT4 = 3U, /*!< OUTPUT4 of the OUTPUT XBAR */
    kXBAR_OUTPUT5 = 4U, /*!< OUTPUT5 of the OUTPUT XBAR */
    kXBAR_OUTPUT6 = 5U, /*!< OUTPUT6 of the OUTPUT XBAR */
    kXBAR_OUTPUT7 = 6U, /*!< OUTPUT7 of the OUTPUT XBAR */
    kXBAR_OUTPUT8 = 7U, /*!< OUTPUT8 of the OUTPUT XBAR */
} XBAR_OutputNum_t;

/*! \brief The number of OUTPUT XBAR MUX per MUX word */
#define XBAR_OUTPUT_MUX_PER_WORD (16U)

/*! \brief Redefine the configuration word for OUTPUT XBAR MUX */
typedef XBAR_MuxConfig_t XBAR_OutputMuxConfig_t;

/*! \brief The identification key to lock the OUTPUT XBAR */
#define XBAR_OUTPUT_LOCK_KEY (0x5A5AU)

/*******************************************************************************
 * APIs
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

#if defined(HTE_FEATURE_INPUT_XBAR_COUNT) && HTE_FEATURE_INPUT_XBAR_COUNT
/*!
 * \brief Set a pin for the Input XBAR input
 *
 * \details This function configures which pin is assigned to the Input XBAR input
 *
 * \param[in] base The Input XBAR base address
 * \param[in] input The Input XBAR input number
 * \param[in] pin The pin's numerical value
 */
static inline void XBAR_setInputPin(INPUT_XBAR_Type *base, XBAR_InputNum_t input, uint32_t pin)
{
    assert(base);
    assert(pin < HTE_FEATURE_GPIO_PIN_COUNT);
    base->INPUTSELECT[input] = pin;
}

/*!
 * \brief Lock the configuration of the Input XBAR input
 *
 * \details This function locks the configuration register of the Input XBAR input. Once set, the locked state cannot
 * be cleared until next system reset
 *
 * \param[in] base The Input XBAR base address
 * \param[in] input The Input XBAR input number
 */
static inline void XBAR_lockInput(INPUT_XBAR_Type *base, XBAR_InputNum_t input)
{
    assert(base);
    base->INPUTSELECTLOCK |= 0x1U << input;
}
#endif /* HTE_FEATURE_INPUT_XBAR_COUNT */

#if defined(HTE_FEATURE_XBAR_COUNT) && HTE_FEATURE_XBAR_COUNT
/*!
 * \brief Get the status of the input flag
 *
 * \details This function returns the status of the input flag which has been triggered by the corresponding XBAR input
 *
 * \param[in] base The XBAR base address
 * \param[in] inputFlag The input flag location word, which is defined in \ref hte_xbarmux.h
 *
 * \return Return the status of the input flag
 *         - True: Input has been triggered
 *         - False: Input hasn't been triggered
 */
bool XBAR_getInputFlagStatus(XBAR_Type *base, XBAR_InputFlag_t inputFlag);

/*!
 * \brief Clear the status of the input flag
 *
 * \details This function clears the status of the input flag which has been triggered by the corresponding XBAR input
 *
 * \param[in] base The XBAR base address
 * \param[in] inputFlag The input location word, which is defined in \ref hte_xbarmux.h
 */
void XBAR_clearInputFlag(XBAR_Type *base, XBAR_InputFlag_t inputFlag);

/*!
 * \brief Switch the XBAR MUX mode
 *
 * \details This function switches the XBAR MUX mode. Each MUX mode has a different MUX selection to offer more
 * flexibility
 *
 * \param[in] base The XBAR base address
 * \param[in] mode The MUX mode
 */
static inline void XBAR_switchMuxMode(XBAR_Type *base, XBAR_MuxMode_t mode)
{
    assert(base);
    base->XBARMISC = XBAR_XBARMISC_MUXCFG_SWITCH_Set(mode);
}
#endif /* HTE_FEATURE_XBAR_COUNT */

#if defined(HTE_FEATURE_EPWM_XBAR_COUNT) && HTE_FEATURE_EPWM_XBAR_COUNT
/*!
 * \brief Configure the ePWM XBAR MUX to select the signals to be passed to an ePWM Module
 *
 * \details This function configures the ePWM XBAR MUX. The MUX determines which signals can be passed to an ePWM
 * module via the ePWM XBAR trip.
 *
 * \param[in] base The ePWM XBAR base address
 * \param[in] trip The ePWM XBAR trip signal number
 * \param[in] muxConfig The MUX configuration word, which is defined in \ref hte_xbarmux.h
 */
void XBAR_setEPWMMuxConfig(EPWM_XBAR_Type *base, XBAR_TripNum_t trip, XBAR_EPWMMuxConfig_t muxConfig);

/*!
 * \brief Enable the ePWM XBAR MUX signals to be passed to an ePWM module
 *
 * \details This function enables the ePWM XBAR MUX signals. The selected signals will be logically ORed and then
 * passed to an ePWM module via the ePWM XBAR trip
 *
 * \param[in] base The ePWM XBAR base address
 * \param[in] trip The ePWM XBAR trip signal number
 * \param[in] muxes The bit field of the MUXes to be enabled, which can be logically ORed items defined in \ref
 * XBAR_MUX_t
 */
static inline void XBAR_enableEPWMMux(EPWM_XBAR_Type *base, XBAR_TripNum_t trip, uint32_t muxes)
{
    assert(base);
    base->TRIPMUXENABLE[trip] |= muxes;
}

/*!
 * \brief Disable the ePWM XBAR MUX signals
 *
 * \details This function disables the ePWM XBAR MUX signals. The selected signal will not be passed to the ePWM module
 * via the ePWM XBAR trip
 *
 * \param[in] base The ePWM XBAR base address
 * \param[in] trip The ePWM XBAR trip signal number
 * \param[in] muxes The bit field of the MUXes to be enabled, which can be logically ORed items defined in \ref
 * XBAR_MUX_t
 */
static inline void XBAR_disableEPWMMux(EPWM_XBAR_Type *base, XBAR_TripNum_t trip, uint32_t muxes)
{
    assert(base);
    base->TRIPMUXENABLE[trip] &= ~muxes;
}

/*!
 * \brief Invert the output signal of the ePWM XBAR trip
 *
 * \details This function inverts the signal before being passed to an ePWM module via the ePWM XBAR trip
 *
 * \param[in] base The ePWM XBAR base address
 * \param[in] trip The ePWM XBAR trip signal number
 * \param[in] invert Invert the signal or not
 *                   - True: Invert the signal
 *                   - False: Pass as it is
 */
static inline void XBAR_invertEPWMSignal(EPWM_XBAR_Type *base, XBAR_TripNum_t trip, bool invert)
{
    assert(base);

    if (invert)
    {
        base->TRIPOUTINV |= 0x1U << trip;
    }
    else
    {
        base->TRIPOUTINV &= ~(0x1U << trip);
    }
}

/*!
 * \brief Lock an ePWM XBAR configuration
 *
 * \details This function locks the configuration of the ePWM XBAR. Once set, the locked state cannot be cleared until
 * next system reset
 *
 * \param[in] base The ePWM XBAR base address
 */
static inline void XBAR_lockEPWM(EPWM_XBAR_Type *base)
{
    assert(base);
    base->TRIPLOCK = EPWM_XBAR_TRIPLOCK_KEY_Set(XBAR_EPWM_LOCK_KEY) | EPWM_XBAR_TRIPLOCK_LOCK_Msk;
}
#endif /* HTE_FEATURE_EPWM_XBAR_COUNT */

#if defined(HTE_FEATURE_CLB_XBAR_COUNT) && HTE_FEATURE_CLB_XBAR_COUNT
/*!
 * \brief Configure the CLB XBAR MUX to select the signals to be passed to a CLB Module
 *
 * \details This functions configures the CLB XBAR MUX. The MUX determines which signals can be passed to a CLB module
 * via the CLB XBAR trip.
 *
 * \param[in] base The CLB XBAR base address
 * \param[in] aux The CLB XBAR aux signal number
 * \param[in] muxConfig The MUX configuration word, which is defined in \ref hte_xbarmux.h
 */
void XBAR_setCLBMuxConfig(CLB_XBAR_Type *base, XBAR_AuxSigNum_t aux, XBAR_CLBMuxConfig_t muxConfig);

/*!
 * \brief Enable the CLB XBAR MUX signals to be passed to an CLB module
 *
 * \details This function enables the CLB XBAR MUX signals. The selected signal will be logically ORed and then passed
 * to a CLB module via the CLB XBAR aux
 *
 * \param[in] base The CLB XBAR base address
 * \param[in] aux The CLB XBAR aux signal number
 * \param[in] muxes The bit field of the MUXes to be enabled, which can be logically ORed items defined in \ref
 * XBAR_MUX_t
 */
static inline void XBAR_enableCLBMux(CLB_XBAR_Type *base, XBAR_AuxSigNum_t aux, uint32_t muxes)
{
    assert(base);
    base->AUXSIGMUXENABLE[aux] |= muxes;
}

/*!
 * \brief Disable the CLB XBAR MUX signals
 *
 * \details This function disables the CLB XBAR MUX signals. The selected signal will not be passed to a CLB module via
 * the CLB XBAR aux
 *
 * \param[in] base The CLB XBAR base address
 * \param[in] aux The CLB XBAR aux signal number
 * \param[in] muxes The bit field of the MUXes to be enabled, which can be logically ORed items defined in \ref
 * XBAR_MUX_t
 */
static inline void XBAR_disableCLBMux(CLB_XBAR_Type *base, XBAR_AuxSigNum_t aux, uint32_t muxes)
{
    assert(base);
    base->AUXSIGMUXENABLE[aux] &= ~muxes;
}

/*!
 * \brief Invert the output signal of a CLB XBAR aux
 *
 * \details This function inverts the signal before being passed to a CLB module via the CLB XBAR aux
 *
 * \param[in] base The CLB XBAR base address
 * \param[in] aux The CLB XBAR aux signal number
 * \param[in] invert Invert the signal or not
 *                   - True: Invert the signal
 *                   - False: Pass as it is
 */
static inline void XBAR_invertCLBSignal(CLB_XBAR_Type *base, XBAR_AuxSigNum_t aux, bool invert)
{
    assert(base);

    if (invert)
    {
        base->AUXSIGOUTINV |= 0x1U << aux;
    }
    else
    {
        base->AUXSIGOUTINV &= ~(0x1U << aux);
    }
}

/*!
 * \brief Lock a CLB XBAR configuration
 *
 * \details This function locks the configuration of a CLB XBAR. Once set, the locked state cannot be cleared until
 * next system reset
 *
 * \param[in] base The Output XBAR base address
 */
static inline void XBAR_lockCLB(CLB_XBAR_Type *base)
{
    assert(base);
    base->AUXSIGLOCK = CLB_XBAR_AUXSIGLOCK_KEY_Set(XBAR_CLB_LOCK_KEY) | CLB_XBAR_AUXSIGLOCK_LOCK_Msk;
}
#endif /* HTE_FEATURE_CLB_XBAR_COUNT */

#if defined(HTE_FEATURE_OUTPUT_XBAR_COUNT) && HTE_FEATURE_OUTPUT_XBAR_COUNT
/*!
 * \brief Configure the OUTPUT XBAR MUX to select the signals to be passed to a pin
 *
 * \details This functions configures the OUTPUT XBAR MUX. The MUX determines which signals can be passed to a pin via
 * the OUTPUT XBAR trip.
 *
 * \param[in] base The OUTPUT XBAR base address
 * \param[in] output The OUTPUT XBAR number
 * \param[in] muxConfig The MUX configuration word, which is defined in \ref hte_xbarmux.h
 */
void XBAR_setOutputMuxConfig(OUTPUT_XBAR_Type *base, XBAR_OutputNum_t output, XBAR_OutputMuxConfig_t muxConfig);

/*!
 * \brief Enable the OUTPUT XBAR MUX signals to be passed to a pin
 *
 * \details This function enables the OUTPUT XBAR MUX signals. The selected signal will be logically ORed and then
 * passed to a pin via the OUTPUT XBAR
 *
 * \param[in] base The OUTPUT XBAR base address
 * \param[in] output The OUTPUT XBAR number
 * \param[in] muxes The bit field of the MUXes to be enabled, which can be logically ORed items defined in \ref
 * XBAR_MUX_t
 */
static inline void XBAR_enableOutputMux(OUTPUT_XBAR_Type *base, XBAR_OutputNum_t output, uint32_t muxes)
{
    assert(base);
    base->OUTPUTMUXENABLE[output] |= muxes;
}

/*!
 * \brief Disable the OUTPUT XBAR MUX signals
 *
 * \details This function disables the OUTPUT XBAR MUX signals. The selected signal will not be passed to a pin via the
 * OUTPUT XBAR
 *
 * \param[in] base The OUTPUT XBAR base address
 * \param[in] output The OUTPUT XBAR number
 * \param[in] muxes The bit field of the MUXes to be enabled, which can be logically ORed items defined in \ref
 * XBAR_MUX_t
 */
static inline void XBAR_disableOutputMux(OUTPUT_XBAR_Type *base, XBAR_OutputNum_t output, uint32_t muxes)
{
    assert(base);
    base->OUTPUTMUXENABLE[output] &= ~muxes;
}

/*!
 * \brief Enable or disable the OUTPUT XBAR output latch mode
 *
 * \details This function enables or disable the output latch to drive the OUTPUT XBAR output.
 *
 * \param[in] base The OUTPUT XBAR base address
 * \param[in] output The OUTPUT XBAR number
 * \param[in] enable Enable the latch mode or not
 *                   - True: Enable the latch mode
 *                   - False: Disable the latch mode
 */
static inline void XBAR_setOutputLatchMode(OUTPUT_XBAR_Type *base, XBAR_OutputNum_t output, bool enable)
{
    assert(base);

    if (enable)
    {
        base->OUTPUTLATCHENABLE |= 0x1U << output;
    }
    else
    {
        base->OUTPUTLATCHENABLE &= ~(0x1U << output);
    }
}

/*!
 * \brief Get the status of the OUTPUT XBAR output latch
 *
 * \details This function returns the status of the OUTPUT XBAR output latch
 *
 * \param[in] base The OUTPUT XBAR base address
 * \param[in] output The OUTPUT XBAR number
 *
 * \return Return the status of the OUTPUT XBAR output latch
 *         - True: The output latch is triggered
 *         - False: The output latch is not triggered
 */
static inline bool XBAR_getOutputLatchStat(OUTPUT_XBAR_Type *base, XBAR_OutputNum_t output)
{
    assert(base);
    return ((base->OUTPUTLATCH & (0x1U << output)) != 0U);
}

/*!
 * \brief Clear the status of the OUTPUT XBAR output latch
 *
 * \details This function clears the status of the OUTPUT XBAR output latch
 *
 * \param[in] base The OUTPUT XBAR base address
 * \param[in] output The OUTPUT XBAR number
 */
static inline void XBAR_clearOutputLatch(OUTPUT_XBAR_Type *base, XBAR_OutputNum_t output)
{
    assert(base);
    base->OUTPUTLATCHCLR |= (0x1U << output);
}

/*!
 * \brief Force the output latch to be set
 *
 * \details This function forces the OUTPUT XBAR output latch to be set
 *
 * \param[in] base The OUTPUT XBAR base address
 * \param[in] output The OUTPUT XBAR number
 */
static inline void XBAR_forceOutputLatch(OUTPUT_XBAR_Type *base, XBAR_OutputNum_t output)
{
    assert(base);
    base->OUTPUTLATCHFRC |= (0x1U << output);
}

/*!
 * \brief Invert the output signal of an OUTPUT XBAR
 *
 * \details This function inverts the signal before being passed to a pin via the OUTPUT XBAR
 *
 * \param[in] base The OUTPUT XBAR base address
 * \param[in] output The OUTPUT XBAR aux signal number
 * \param[in] invert Invert the signal or not
 *                   - True: Invert the signal
 *                   - False: Pass as it is
 */
static inline void XBAR_invertOutputSignal(OUTPUT_XBAR_Type *base, XBAR_OutputNum_t output, bool invert)
{
    assert(base);

    if (invert)
    {
        base->OUTPUTINV |= 0x1U << output;
    }
    else
    {
        base->OUTPUTINV &= ~(0x1U << output);
    }
}

/*!
 * \brief Lock an OUTPUT XBAR configuration
 *
 * \details This function locks the configuration of an OUTPUT XBAR. Once set, the locked state cannot be cleared until
 * next system reset
 *
 * \param[in] base The OUTPUT XBAR base address
 */
static inline void XBAR_lockOutput(OUTPUT_XBAR_Type *base)
{
    assert(base);
    base->OUTPUTLOCK = OUTPUT_XBAR_OUTPUTLOCK_KEY_Set(XBAR_OUTPUT_LOCK_KEY) | OUTPUT_XBAR_OUTPUTLOCK_LOCK_Msk;
}
#endif /* HTE_FEATURE_OUTPUT_XBAR_COUNT */

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */ /* end of DRV_HTE_XBAR */

#endif /* HTE_XBAR_H */
