/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_gpio.h
 * \brief SDK GPIO driver header file
 * \version 1.0.0
 */

#ifndef HTE_GPIO_H
#define HTE_GPIO_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_common.h"

/*!
 * \addtogroup DRV_HTE_GPIO GPIO Driver
 *
 * \brief SDK GPIO driver
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! \brief GPIO driver version */
#define GPIO_DRIVER_VERSION MAKE_VERSION('V', 1U, 0U, 0U)

/*! \brief GPIO pin count per GPIO port */
#define GPIO_CTRL_PIN_COUNT_PER_PORT (32U)

/*! \brief GPIO pin count per Qualification sampling period */
#define GPIO_CTRL_PIN_COUNT_PER_QUAL (8U)

/*! \brief GPIO port definition */
typedef enum
{
    kGPIO_PORT_A = 0U, /*!< GPIO PORT A */
    kGPIO_PORT_B = 1U, /*!< GPIO PORT B */
    kGPIO_PORT_C = 2U, /*!< GPIO PORT C */
    kGPIO_PORT_D = 3U, /*!< GPIO PORT D */
    kGPIO_PORT_E = 4U, /*!< GPIO PORT E */
    kGPIO_PORT_F = 5U, /*!< GPIO PORT F */
} GPIO_Port_t;

/*! \brief Core selection for a GPIO */
typedef enum
{
    kGPIO_CORE_CPU1 = 0U, /*!< CPU1 */
    kGPIO_CORE_CPU2 = 2U, /*!< CPU2 */
} GPIO_Core_t;

/*! \brief Direction of a GPIO */
typedef enum
{
    kGPIO_DIR_INPUT  = 0U, /*!< Pin is an input */
    kGPIO_DIR_OUTPUT = 1U, /*!< Pin is an output */
} GPIO_Direction_t;

/*! \brief GPIO input qualification mode */
typedef enum
{
    kGPIO_QUAL_SYNC    = 0U, /*!< Synchronization */
    kGPIO_QUAL_3SAMPLE = 1U, /*!< Qualified with 3 samples */
    kGPIO_QUAL_6SAMPLE = 2U, /*!< Qualifier with 6 samples */
    kGPIO_QUAL_ASYNC   = 3U, /*!< No Synchronization and Qualification */
} GPIO_QualificationMode_t;

/*! \brief The definition of the pin configuration word which is used by \ref GPIO_setPinConfig() */
typedef union
{
    uint32_t U; /*!< The configuration word */

    struct
    {
        uint32_t mux      : 2;  /*!< The MUX value */
        uint32_t gmux     : 2;  /*!< The GMUX value */
        uint32_t reserved : 12; /*!< Reserved */
        uint32_t pin      : 16; /*!< The pin index */
    } B;                        /*!< The configuration bitfield */
} GPIO_PinConfig_t;

#define GPIO_PINCONFIG_MUX_Pos (0U)                             /*!< MUX Position 0 */
#define GPIO_PINCONFIG_MUX_Msk (0x3U << GPIO_PINCONFIG_MUX_Pos) /*!< MUX Mask 0x00000003 */
#define GPIO_PINCONFIG_MUX_Set(x) \
    ((((uint32_t)(x)) << GPIO_PINCONFIG_MUX_Pos) & GPIO_PINCONFIG_MUX_Msk) /*!< MUX Set Value */
#define GPIO_PINCONFIG_MUX_Get(x) \
    ((((uint32_t)(x)) & GPIO_PINCONFIG_MUX_Msk) >> GPIO_PINCONFIG_MUX_Pos) /*!< MUX Get Value */

#define GPIO_PINCONFIG_GMUX_Pos (2U)                              /*!< GMUX Position 2 */
#define GPIO_PINCONFIG_GMUX_Msk (0x3U << GPIO_PINCONFIG_GMUX_Pos) /*!< GMUX Mask 0x0000000C */
#define GPIO_PINCONFIG_GMUX_Set(x) \
    ((((uint32_t)(x)) << GPIO_PINCONFIG_GMUX_Pos) & GPIO_PINCONFIG_GMUX_Msk) /*!< GMUX Set Value */
#define GPIO_PINCONFIG_GMUX_Get(x) \
    ((((uint32_t)(x)) & GPIO_PINCONFIG_GMUX_Msk) >> GPIO_PINCONFIG_GMUX_Pos) /*!< GMUX Get Value */

#define GPIO_PINCONFIG_ALLMUX_Pos (0U)                                /*!< ALLMUX Position 0 */
#define GPIO_PINCONFIG_ALLMUX_Msk (0xFU << GPIO_PINCONFIG_ALLMUX_Pos) /*!< ALLMUX Mask 0x0000000F */
#define GPIO_PINCONFIG_ALLMUX_Set(x) \
    ((((uint32_t)(x)) << GPIO_PINCONFIG_ALLMUX_Pos) & GPIO_PINCONFIG_ALLMUX_Msk) /*!< ALLMUX Set Value */
#define GPIO_PINCONFIG_ALLMUX_Get(x) \
    ((((uint32_t)(x)) & GPIO_PINCONFIG_ALLMUX_Msk) >> GPIO_PINCONFIG_ALLMUX_Pos) /*!< ALLMUX Get Value */

#define GPIO_PINCONFIG_PIN_Pos (16U)                               /*!< PIN Position 16 */
#define GPIO_PINCONFIG_PIN_Msk (0xFFFFU << GPIO_PINCONFIG_PIN_Pos) /*!< PIN Mask 0xFFFF0000 */
#define GPIO_PINCONFIG_PIN_Set(x) \
    ((((uint32_t)(x)) << GPIO_PINCONFIG_PIN_Pos) & GPIO_PINCONFIG_PIN_Msk) /*!< PIN Set Value */
#define GPIO_PINCONFIG_PIN_Get(x) \
    ((((uint32_t)(x)) & GPIO_PINCONFIG_PIN_Msk) >> GPIO_PINCONFIG_PIN_Pos) /*!< PIN Get Value */

/*! \brief Generate a pin configuration word */
#define GPIO_PINCONFIG(pin, allmux) (GPIO_PINCONFIG_PIN_Set(pin) | GPIO_PINCONFIG_ALLMUX_Set(allmux))

/*! \brief The definitions of the pad configuration which is used by \ref GPIO_setPadConfig(). They are bit mask values
 * which can be ORed to make the configuration word */
enum
{
    kGPIO_PADCONFIG_STD          = 0U,        /*!< Push-pull mode */
    kGPIO_PADCONFIG_PULLUP       = (1U << 0), /*!< Enable pull-up */
    kGPIO_PADCONFIG_INPUT_INVERT = (1U << 1), /*!< Enable input polarity invert */
#if !(defined(HTE_FEATURE_GPIO_NOT_SUPPORT_OPEN_DRAIN) && HTE_FEATURE_GPIO_NOT_SUPPORT_OPEN_DRAIN)
    kGPIO_PADCONFIG_OPEN_DRAIN = (1U << 2), /*!< Enable open-drain */
#endif
    kGPIO_PADCONFIG_PULLDOWN       = (1U << 3), /*!< Enable pull-down res */
    kGPIO_PADCONFIG_NO_FORCE_INPUT = (1U << 4), /*!< Disable force input. The pad signal cannot be read by
                                                   \ref GPIO_readPin(), when it is output */
    kGPIO_PADCONFIG_SCHMITT  = (1U << 5),       /*!< Enable Schmitt-trigger */
    kGPIO_PADCONFIG_LOOPBACK       = (1U << 6), /*!< Enable output loop back. The GPIO will always work at OUTPUT plus
                                                   FORCE INPUT mode, discard the direction setting */
};

/*! \brief Driver strength of a pad */
typedef enum
{
    kGPIO_DRV_STR_9P5MA  = 0U, /*!<  9.5mA */
    kGPIO_DRV_STR_29P5MA = 1U, /*!< 29.5mA */
    kGPIO_DRV_STR_40P1MA = 2U, /*!< 40.1mA */
    kGPIO_DRV_STR_60P5MA = 3U, /*!< 60.5mA */
} GPIO_DriverStrength_t;

/*! \brief GPIO external interrupt number */
typedef enum
{
    kGPIO_XINT1 = 0U, /*!< External interrupt 1 */
    kGPIO_XINT2 = 1U, /*!< External interrupt 2 */
    kGPIO_XINT3 = 2U, /*!< External interrupt 3 */
    kGPIO_XINT4 = 3U, /*!< External interrupt 4 */
    kGPIO_XINT5 = 4U, /*!< External interrupt 5 */
} GPIO_ExternalIntNum_t;

/*! \brief GPIO external interrupt type */
typedef enum
{
    kGPIO_INT_TYPE_RISING_EDGE  = 0x01, /*!< Interrupt on rising edge */
    kGPIO_INT_TYPE_FALLING_EDGE = 0x02, /*!< Interrupt on falling edge */
    kGPIO_INT_TYPE_BOTH_EDGES   = 0x03  /*!< Interrupt on both edges */
} GPIO_IntType_t;

/*******************************************************************************
 * APIs
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Check if a pin number is valid or not
 *
 * \details This function checks if a given pin number is valid
 *
 * \note This function checks the highest possible value of the pin number on the device. But it might not exist on all
 * packages. Please check the datasheet or the technical reference manual to identify the actual valid pin number on a
 * specific package
 *
 * \param[in] pin The pin's numerical value
 *
 * \return Return the valid status of the pin number
 *         - True : Valid
 *         - False : Invalid
 */
static inline bool GPIO_isPinValid(uint32_t pin)
{
    return (pin <= HTE_FEATURE_GPIO_PIN_COUNT);
}

/*!
 * \brief Get the port of the specific pin
 *
 * \details This function returns the port which the pin belongs to. If the pin number is an invalid value, and assert
 * is enabled, this function will run into a breakpoint to inform the error
 *
 * \param[in] pin The pin's numerical value
 *
 * \return Return the Port index number
 */
static inline GPIO_Port_t GPIO_getPort(uint32_t pin)
{
    assert(GPIO_isPinValid(pin));
    return (GPIO_Port_t)(pin / GPIO_CTRL_PIN_COUNT_PER_PORT);
}

#if defined(HTE_FEATURE_GPIO_CTRL_COUNT) && HTE_FEATURE_GPIO_CTRL_COUNT
/*!
 * \brief Select the master core of the specified pin
 *
 * \details This function selects which master core can control the GPIO data registers(DATA, SET, CLEAR and TOGGLE) of
 * the specified pin. If the pin's other peripheral is selected by the pinmux, this function has effect to select which
 * master core owns the peripheral, please use \ref SYSCTRL_selectCPUForPeripheral() instead
 *
 * \param[in] pin The pin's numerical value
 * \param[in] core The master core enumerator
 */
void GPIO_setMasterCore(uint32_t pin, GPIO_Core_t core);

/*!
 * \brief Set the qualification mode of the specified pin
 *
 * \details This function sets the qualification mode for the specified pin's input, no matter which peripheral is
 * selected by the pinmux. The qualification mode only take effect for the pin's input path
 *
 * \param[in] pin The pin's numerical value
 * \param[in] qualification The qualification mode of the pin
 *
 */
void GPIO_setQualificationMode(uint32_t pin, GPIO_QualificationMode_t qualification);

/*!
 * \brief Get the qualification mode of the specified pin
 *
 * \details This function returns the qualification mode of the specified pin
 *
 * \param[in] pin The pin's numerical value
 *
 * \return Return The qualification mode of the pin
 *
 */
GPIO_QualificationMode_t GPIO_getQualificationMode(uint32_t pin);

/*!
 * \brief Set the qualification period for a set of pins
 *
 * \details This function set the qualification period for a set of 8 pins which shares the same register bit field to
 * configure the divider of the qualification period
 *
 * \param[in] pin The pin's numerical value
 * \param[in] divider The divider by which the frequency of SYSCLKOUT is divided. The range is 0x0 to 0xFFFF
 *
 */
void GPIO_setQualificationPeriod(uint32_t pin, uint32_t divider);

/*!
 * \brief Set the direction mode of the specified pin
 *
 * \details This function sets the specified pin's GPIO function as either input or output. If the pin's other
 * peripheral is selected by the pinmux, this function is not required to configure the direction
 *
 * \param[in] pin The pin's numerical value
 * \param[in] dir The pin direction mode
 */
void GPIO_setDirectionMode(uint32_t pin, GPIO_Direction_t dir);

/*!
 * \brief Get the direction mode of the specified pin
 *
 * \details This function returns the direction mode for the specified pin
 *
 * \param[in] pin The pin's numerical value
 *
 * \return Return the pin's direction mode
 */
GPIO_Direction_t GPIO_getDirectionMode(uint32_t pin);

/*!
 * \brief Select the alternate function of the specified pin
 *
 * \details This function sets the pin mux to select the peripheral which is associated with the pin. Only one
 * peripheral can be selected with the pin at one time
 *
 * \param[in] config The pin configuration value, the format is defined by \ref GPIO_PinConfig_t. All available
 * selections are supplied in \ref hte_pinmux.h
 */
void GPIO_setPinConfig(uint32_t config);

/*!
 * \brief Set the pad configurations of the specified pin
 *
 * \details This function sets the pad configurations of the specified pin. The configuration can be a word which may be
 * OR-ed with multiple enumerators (\ref kGPIO_PADCONFIG_STD and relative enumerators)
 *
 * \param[in] pin The pin's numerical value
 * \param[in] config The pad configuration word
 */
void GPIO_setPadConfig(uint32_t pin, uint32_t config);

/*!
 * \brief Get the pad configuration of the specified pin
 *
 * \details This function returns the pad configurations of the specified pin. The configuration is a word which is
 * OR-ed with multiple enumerators ( \ref kGPIO_PADCONFIG_STD and relative enumerators )
 *
 * \param[in] pin The pin's numerical value
 *
 * \return Return the pad configuration word
 */
uint32_t GPIO_getPadConfig(uint32_t pin);

/*!
 * \brief Set the driver strength of the specified pin
 *
 * \details This function sets the drier strength of the specified pin, no matter which peripheral is selected with the
 * pin
 *
 * \param[in] pin The pin's numerical value
 * \param[in] str The pin's driver strength
 */
void GPIO_setDriverStrength(uint32_t pin, GPIO_DriverStrength_t str);

/*!
 * \brief Get the driver strength of the specified pin
 *
 * \details This function returns the drier strength of the specified pin
 *
 * \param[in] pin The pin's numerical value
 * \return Return the pin's driver strength
 */
GPIO_DriverStrength_t GPIO_getDriverStrength(uint32_t pin);

/*!
 * \brief Lock the configuration of the specified pins
 *
 * \details This function locks the configuration registers of the specified pins. The registers include MUX1, MUX2,
 * GMUX1, GMUX2, CSEL1, CSEL2, CSEL3, CSEL4, DIR, PUD, INV, ODR, DS, PDD, FID, ST and LBP
 *
 * \param[in] port The port which the pin belongs to
 * \param[in] pinMask The bit-packed value in which each bit identifies the pin to be locked
 */
static inline void GPIO_lockPortConfig(GPIO_Port_t port, uint32_t pinMask)
{
    GPIO_CTRL->PORT[port].LOCK |= pinMask;
}

/*!
 * \brief Unlock the configuration of the specified pins
 *
 * \details This function unlocks the configuration registers of the specified pins. The registers include MUX1, MUX2,
 * GMUX1, GMUX2, CSEL1, CSEL2, CSEL3, CSEL4, DIR, PUD, INV, ODR, DS, PDD, FID, ST and LBP
 *
 * \param[in] port The port which the pin belongs to
 * \param[in] pinMask The bit-packed value in which each bit identifies the pin to be unlocked
 */
static inline void GPIO_unlockPortConfig(GPIO_Port_t port, uint32_t pinMask)
{
    GPIO_CTRL->PORT[port].LOCK &= ~pinMask;
}

/*!
 * \brief Commit the lock configurations of the specified pins
 *
 * \details This function commits the lock register configuration of the specified pins. One the lock configuration is
 * committed, the value of the Lock register relative to the specified pins cannot be changed until next system reset.
 * \ref GPIO_lockPortConfig() and \ref GPIO_unlockPortConfig() will no longer have any real effect on the specified pins
 *
 * \param[in] port The port which the pin belongs to
 * \param[in] pinMask The bit-packed value in which each bit identifies the pin lock configuration to be committed
 */
static inline void GPIO_commitPortConfig(GPIO_Port_t port, uint32_t pinMask)
{
    GPIO_CTRL->PORT[port].CR |= pinMask;
}
#endif /* HTE_FEATURE_GPIO_CTRL_COUNT */

/*!
 * \brief Read the GPIO data register value of the specified pin
 *
 * \details This function returns the GPIO data register value of the specified pin. The value can be read for both
 * input and output GPIO pins, and presents the signal state of the GPIO pins
 *
 * \param[in] pin The pin's numerical value
 *
 * \return Return the GPIO data register value of the specified pin
 */
static inline uint32_t GPIO_readPin(uint32_t pin)
{
    GPIO_Port_t port     = GPIO_getPort(pin);
    uint32_t    pinShift = pin % GPIO_CTRL_PIN_COUNT_PER_PORT;

    return ((GPIO_DATA->PORT[port].DAT >> pinShift) & 0x1U);
}

/*!
 * \brief Read the GPIO data register value of the specified pin
 *
 * \details This function returns the GPIO data register value of the specified pin. The value can be read for both
 * input and output GPIO pins, and presents the signal state of the GPIO pins
 *
 * \deprecated This function has been replaced with \ref GPIO_readPin()
 *
 * \param[in] pin The pin's numerical value
 *
 * \return Return the GPIO data register value of the specified pin
 */
static inline uint32_t GPIO_readPinDataRegister(uint32_t pin)
{
    return GPIO_readPin(pin);
}

/*!
 * \brief Write a value to the GPIO data register of the specified pin
 *
 * \details This function writes a bit value to the GPIO data register of the specified pin. Writing to a pin configured
 * as an input GPIO pin has no effect
 *
 * \param[in] pin The pin's numerical value
 * \param[in] outVal The value to write to the pin
 */
static inline void GPIO_writePin(uint32_t pin, uint32_t outVal)
{
    GPIO_Port_t port    = GPIO_getPort(pin);
    uint32_t    pinMask = 0x1U << (pin % GPIO_CTRL_PIN_COUNT_PER_PORT);

    if (outVal == 0U)
    {
        GPIO_DATA->PORT[port].CLEAR |= pinMask;
    }
    else
    {
        GPIO_DATA->PORT[port].SET |= pinMask;
    }
}

/*!
 * \brief Toggles the value in the GPIO data register of the specified pin
 *
 * \details This function toggles the bit value in the GPIO data register of the specified pin. Toggling the value of a
 * pin configured as an input GPIO pin has no effect
 *
 * \param[in] pin The pin's numerical value
 */
static inline void GPIO_togglePin(uint32_t pin)
{
    GPIO_Port_t port    = GPIO_getPort(pin);
    uint32_t    pinMask = 0x1U << (pin % GPIO_CTRL_PIN_COUNT_PER_PORT);

    GPIO_DATA->PORT[port].TOGGLE |= pinMask;
}

/*!
 * \brief Read the GPIO data register value of the specified port
 *
 * \details This function returns the values of all pins in the specified port
 *
 * \param[in] port The port which the pin belongs to
 *
 * \return Return the GPIO data register value of the specified port
 */
static inline uint32_t GPIO_readPortData(GPIO_Port_t port)
{
    return GPIO_DATA->PORT[port].DAT;
}

/*!
 * \brief Read the GPIO data register value of the specified port
 *
 * \details This function returns the values of all pins in the specified port
 *
 * \deprecated This function has been replaced with \ref GPIO_readPortData()
 *
 * \param[in] port The port which the pin belongs to
 *
 * \return Return the GPIO data register value of the specified port
 */
static inline uint32_t GPIO_readPortDataRegister(GPIO_Port_t port)
{
    return GPIO_readPortData(port);
}

/*!
 * \brief Write a value to the GPIO data register of the specified port
 *
 * \details This function writes values to GPIO data registers of all pins in the specified port
 *
 * \param[in] port The port which the pin belongs to
 * \param[in] outVal The value to write to the port
 */
static inline void GPIO_writePortData(GPIO_Port_t port, uint32_t outVal)
{
    GPIO_DATA->PORT[port].DAT = outVal;
}

/*!
 * \brief Set the GPIO data register of a set of pins on the specified port
 *
 * \details This function sets the GPIO data register of a set of pins on the specified port. The pins are specified by
 * the pinMask parameter
 *
 * \param[in] port The port which the pin belongs to
 * \param[in] pinMask The mask of which of the pins on the port are affected
 */
static inline void GPIO_setPortPins(GPIO_Port_t port, uint32_t pinMask)
{
    GPIO_DATA->PORT[port].SET = pinMask;
}

/*!
 * \brief Clear the GPIO data register of a set of pins on the specified port
 *
 * \details This function clears the GPIO data register of a set of pins on the specified port. The pins are specified
 * by the pinMask parameter
 *
 * \param[in] port The port which the pin belongs to
 * \param[in] pinMask The mask of which of the pins on the port are affected
 */
static inline void GPIO_clearPortPins(GPIO_Port_t port, uint32_t pinMask)
{
    GPIO_DATA->PORT[port].CLEAR = pinMask;
}

/*!
 * \brief Toggle the GPIO data register of a set of pins on the specified port
 *
 * \details This function toggles the GPIO data register of a set of pins on the specified port. The pins are specified
 * by the pinMask parameter
 *
 * \param[in] port The port which the pin belongs to
 * \param[in] pinMask The mask of which of the pins on the port are affected
 */
static inline void GPIO_togglePortPins(GPIO_Port_t port, uint32_t pinMask)
{
    GPIO_DATA->PORT[port].TOGGLE = pinMask;
}

#if defined(HTE_FEATURE_XINT_COUNT) && HTE_FEATURE_XINT_COUNT
#if defined(HTE_FEATURE_INPUT_XBAR_COUNT) && HTE_FEATURE_INPUT_XBAR_COUNT
/*!
 * \brief Set the pin for the specified external interrupt
 *
 * \details This function sets the pin which triggers the selected external interrupt
 *
 * \param[in] pin The pin's numerical value
 * \param[in] num The external interrupt index number
 */
void GPIO_setInterruptPin(uint32_t pin, GPIO_ExternalIntNum_t num);
#endif /* HTE_FEATURE_INPUT_XBAR_COUNT */

/*!
 * \brief Set the trigger type for the specified external interrupt
 *
 * \details This function sets the trigger type of the specified external interrupt by modifying the corresponding bits
 * in the XINT register
 *
 * \param[in] num The external interrupt index number
 * \param[in] type The trigger type of the interrupt, which can be failing-edge, rising-edge or both-edges
 */
static inline void GPIO_setInterruptType(GPIO_ExternalIntNum_t num, GPIO_IntType_t type)
{
    XINT->CR[num] = (XINT->CR[num] & (uint16_t)(~XINT_CR_POLARITY_Msk)) | XINT_CR_POLARITY_Set(type);
}

/*!
 * \brief Get the trigger type of the specified external interrupt
 *
 * \details This function returns the trigger type of the specified external interrupt
 *
 * \param[in] num The external interrupt index number
 *
 * \return Return the trigger type of the specified external interrupt
 */
static inline GPIO_IntType_t GPIO_getInterruptType(GPIO_ExternalIntNum_t num)
{
    return (GPIO_IntType_t)XINT_CR_POLARITY_Get(XINT->CR[num]);
}

/*!
 * \brief Enable the specified external interrupt
 *
 * \details This function enables the specified external interrupt, which can be reflected to the CPU interrupt
 *
 * \param[in] num The external interrupt index number
 */
#if defined(HTE_FEATURE_XIN_FLAG_HAS_PENDING_IRQ) && HTE_FEATURE_XIN_FLAG_HAS_PENDING_IRQ
void GPIO_enableInterrupt(GPIO_ExternalIntNum_t num);
#else
static inline void GPIO_enableInterrupt(GPIO_ExternalIntNum_t num)
{
    XINT->CR[num] |= XINT_CR_ENABLE_Msk;
}
#endif /* HTE_FEATURE_XIN_FLAG_HAS_PENDING_IRQ */

/*!
 * \brief Disable the specified external interrupt
 *
 * \details This function disables the specified external interrupt. Once it is disabled, the interrupt cannot be
 * reflected to the CPU interrupt
 *
 * \param[in] num The external interrupt index number
 */
static inline void GPIO_disableInterrupt(GPIO_ExternalIntNum_t num)
{
    XINT->CR[num] &= ~XINT_CR_ENABLE_Msk;
}

/*!
 * \brief Get the value of the external interrupt counter
 *
 * \details This function returns the value of the external interrupt counter. The counter value is reset to 0x0 when a
 * valid interrupt edge is detected, and continues counting until the next valid interrupt edge is detected.
 *
 * \param[in] num The external interrupt index number
 *
 * \return Return the value of the external interrupt counter
 */
#if defined(HTE_FEATURE_XIN_COUNTER_HAS_NON_CONTINUOUS_ADDRESS) && HTE_FEATURE_XIN_COUNTER_HAS_NON_CONTINUOUS_ADDRESS
uint16_t GPIO_getInterruptCounter(GPIO_ExternalIntNum_t num);
#else
static inline uint16_t GPIO_getInterruptCounter(GPIO_ExternalIntNum_t num);
{
    return XINT->CTR[num];
}
#endif /* HTE_FEATURE_XIN_COUNTER_HAS_NON_CONTINUOUS_ADDRESS */

/*!
 * \brief Get the flag of the specified external interrupt
 *
 * \details This function retrieves the interrupt flag of the specified external interrupt number
 *
 * \param[in] num The external interrupt index number
 *
 * \return Return the flag of the specified external interrupt
 */
static inline uint32_t GPIO_getInterruptFlag(GPIO_ExternalIntNum_t num)
{
    return XINT_FLG_FLG_Get(XINT->FLG[num]);
}

/*!
 * \brief Clear the flag of the specified external interrupt
 *
 * \details This function clears the interrupt flag of the specified external interrupt number
 *
 * \param[in] num The external interrupt index number
 */
static inline void GPIO_clearInterruptFlag(GPIO_ExternalIntNum_t num)
{
    /* Write 1 to clear the flag */
    XINT->CLR[num] = XINT_CLR_CLR_Msk;
}
#endif /* HTE_FEATURE_XINT_CONT */

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */ /* end of DRV_HTE_GPIO */

#endif /* HTE_GPIO_H */
