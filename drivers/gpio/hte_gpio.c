/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_gpio.c
 * \brief SDK GPIO driver source file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_gpio.h"
#if defined(HTE_FEATURE_INPUT_XBAR_COUNT) && HTE_FEATURE_INPUT_XBAR_COUNT
#include "hte_xbar.h"
#endif

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
#if defined(HTE_FEATURE_XINT_COUNT) && HTE_FEATURE_XINT_COUNT
#if defined(HTE_FEATURE_INPUT_XBAR_COUNT) && HTE_FEATURE_INPUT_XBAR_COUNT
/*! \brief The table to get the Input XBAR number for a specified XINT number */
const XBAR_InputNum_t s_xinInputXbarTable[HTE_FEATURE_XIN_CHANNEL_COUNT] = { kXBAR_INPUT4, kXBAR_INPUT5, kXBAR_INPUT6,
                                                                             kXBAR_INPUT13, kXBAR_INPUT14 };
#endif /* HTE_FEATURE_INPUT_XBAR_COUNT */
#if defined(HTE_FEATURE_XIN_COUNTER_HAS_NON_CONTINUOUS_ADDRESS) && HTE_FEATURE_XIN_COUNTER_HAS_NON_CONTINUOUS_ADDRESS
/*! \brief The table to get the Counter Register Address for a specified XINT number */
__IM uint16_t * const s_xintCtrAddrTable[HTE_FEATURE_XIN_COUNTER_COUNT] = { &XINT->CTR1, &XINT->CTR2, &XINT->CTR3,
                                                                            &XINT->CTR4, &XINT->CTR5 };
#endif /* HTE_FEATURE_XIN_COUNTER_HAS_NON_CONTINUOUS_ADDRESS */
#endif /* HTE_FEATURE_XINT_COUNT */

/*******************************************************************************
 * Codes
 ******************************************************************************/
#if defined(HTE_FEATURE_GPIO_CTRL_COUNT) && HTE_FEATURE_GPIO_CTRL_COUNT
void GPIO_setMasterCore(uint32_t pin, GPIO_Core_t core)
{
    GPIO_Port_t port      = GPIO_getPort(pin);
    uint32_t    pinPerReg = GPIO_CTRL_PIN_COUNT_PER_PORT / GPIO_CTRL_CSEL_CSEL1_Pos;
    uint32_t    cselIndex = (pin % GPIO_CTRL_PIN_COUNT_PER_PORT) / pinPerReg;
    uint32_t    cselShift = ((pin % GPIO_CTRL_PIN_COUNT_PER_PORT) % pinPerReg) * GPIO_CTRL_CSEL_CSEL1_Pos;

    GPIO_CTRL->PORT[port].CSEL[cselIndex] &= ~(GPIO_CTRL_CSEL_CSEL0_Msk << cselShift);
    GPIO_CTRL->PORT[port].CSEL[cselIndex] |= (core & GPIO_CTRL_CSEL_CSEL0_Msk) << cselShift;
}

void GPIO_setQualificationMode(uint32_t pin, GPIO_QualificationMode_t qualification)
{
    GPIO_Port_t port      = GPIO_getPort(pin);
    uint32_t    pinPerReg = GPIO_CTRL_PIN_COUNT_PER_PORT / GPIO_CTRL_QSEL_QSEL1_Pos;
    uint32_t    qselIndex = (pin % GPIO_CTRL_PIN_COUNT_PER_PORT) / pinPerReg;
    uint32_t    qselShift = ((pin % GPIO_CTRL_PIN_COUNT_PER_PORT) % pinPerReg) * GPIO_CTRL_QSEL_QSEL1_Pos;

    GPIO_CTRL->PORT[port].QSEL[qselIndex] &= ~(GPIO_CTRL_QSEL_QSEL0_Msk << qselShift);
    GPIO_CTRL->PORT[port].QSEL[qselIndex] |= (qualification & GPIO_CTRL_QSEL_QSEL0_Msk) << qselShift;
}

GPIO_QualificationMode_t GPIO_getQualificationMode(uint32_t pin)
{
    GPIO_Port_t port      = GPIO_getPort(pin);
    uint32_t    pinPerReg = GPIO_CTRL_PIN_COUNT_PER_PORT / GPIO_CTRL_QSEL_QSEL1_Pos;
    uint32_t    qselIndex = (pin % GPIO_CTRL_PIN_COUNT_PER_PORT) / pinPerReg;
    uint32_t    qselShift = ((pin % GPIO_CTRL_PIN_COUNT_PER_PORT) % pinPerReg) * GPIO_CTRL_QSEL_QSEL1_Pos;

    return (GPIO_QualificationMode_t)((GPIO_CTRL->PORT[port].QSEL[qselIndex] >> qselShift) & GPIO_CTRL_QSEL_QSEL0_Msk);
}

void GPIO_setQualificationPeriod(uint32_t pin, uint32_t divider)
{
    GPIO_Port_t port = GPIO_getPort(pin);
    uint32_t    qualShift =
        (pin % GPIO_CTRL_PIN_COUNT_PER_PORT) / GPIO_CTRL_PIN_COUNT_PER_QUAL * GPIO_CTRL_CTRL_QUALPRD1_Pos;
    uint32_t dividerLow  = (divider & GPIO_CTRL_CTRL_QUALPRD0_Msk);
    uint32_t dividerHigh = ((divider >> GPIO_CTRL_CTRL_QUALPRD1_Pos) & GPIO_CTRL_ECTRL_QUALPRD0_Msk);

    /* Clear CTRL and ECTRL before setting to avoid potential glitches */
    GPIO_CTRL->PORT[port].CTRL  &= ~(GPIO_CTRL_CTRL_QUALPRD0_Msk << qualShift);
    GPIO_CTRL->PORT[port].ECTRL &= ~(GPIO_CTRL_ECTRL_QUALPRD0_Msk << qualShift);

    /* Configure CTRL and ECTRL */
    GPIO_CTRL->PORT[port].CTRL  |= dividerLow << qualShift;
    GPIO_CTRL->PORT[port].ECTRL |= dividerHigh << qualShift;
}

void GPIO_setDirectionMode(uint32_t pin, GPIO_Direction_t dir)
{
    GPIO_Port_t port    = GPIO_getPort(pin);
    uint32_t    pinMask = 0x1U << (pin % GPIO_CTRL_PIN_COUNT_PER_PORT);

    if (dir == kGPIO_DIR_INPUT)
    {
        GPIO_CTRL->PORT[port].DIR &= ~pinMask;
    }
    else
    {
        GPIO_CTRL->PORT[port].DIR |= pinMask;
    }
}

GPIO_Direction_t GPIO_getDirectionMode(uint32_t pin)
{
    GPIO_Port_t port    = GPIO_getPort(pin);
    uint32_t    pinMask = 0x1U << (pin % GPIO_CTRL_PIN_COUNT_PER_PORT);

    return (GPIO_CTRL->PORT[port].DIR & pinMask) ? kGPIO_DIR_OUTPUT : kGPIO_DIR_INPUT;
}

void GPIO_setPinConfig(uint32_t config)
{
    uint32_t    pin       = GPIO_PINCONFIG_PIN_Get(config);
    GPIO_Port_t port      = GPIO_getPort(pin);
    uint32_t    pinPerReg = GPIO_CTRL_PIN_COUNT_PER_PORT / GPIO_CTRL_MUX_MUX1_Pos;
    uint32_t    muxIndex  = (pin % GPIO_CTRL_PIN_COUNT_PER_PORT) / pinPerReg;
    uint32_t    muxShift  = ((pin % GPIO_CTRL_PIN_COUNT_PER_PORT) % pinPerReg) * GPIO_CTRL_MUX_MUX1_Pos;

    uint32_t mux  = GPIO_PINCONFIG_MUX_Get(config);
    uint32_t gmux = GPIO_PINCONFIG_GMUX_Get(config);

    /* Clear MUX to avoid glitches */
    GPIO_CTRL->PORT[port].MUX[muxIndex] &= ~(GPIO_CTRL_MUX_MUX0_Msk << muxShift);

    /* GMUX must be configured prior to MUX to avoid intermediate peripheral selects */
    GPIO_CTRL->PORT[port].GMUX[muxIndex] =
        (GPIO_CTRL->PORT[port].GMUX[muxIndex] & (~(GPIO_CTRL_GMUX_GMUX0_Msk << muxShift))) | (gmux << muxShift);

    /* Configure MUX */
    GPIO_CTRL->PORT[port].MUX[muxIndex] |= mux << muxShift;
}

void GPIO_setPadConfig(uint32_t pin, uint32_t config)
{
    GPIO_Port_t port    = GPIO_getPort(pin);
    uint32_t    pinMask = 0x1U << (pin % GPIO_CTRL_PIN_COUNT_PER_PORT);

    if (config & kGPIO_PADCONFIG_PULLUP)
    {
        /* Enable pull up resister */
        GPIO_CTRL->PORT[port].PUD &= ~pinMask;
    }
    else
    {
        /* Disable pull up resister */
        GPIO_CTRL->PORT[port].PUD |= pinMask;
    }

    if (config & kGPIO_PADCONFIG_INPUT_INVERT)
    {
        /* Enable input logic inverter */
        GPIO_CTRL->PORT[port].INV |= pinMask;
    }
    else
    {
        /* Disable input logic inverter */
        GPIO_CTRL->PORT[port].INV &= ~pinMask;
    }

#if !(defined(HTE_FEATURE_GPIO_NOT_SUPPORT_OPEN_DRAIN) && HTE_FEATURE_GPIO_NOT_SUPPORT_OPEN_DRAIN)
    if (config & kGPIO_PADCONFIG_OPEN_DRAIN)
    {
        /* Enable open drain drive */
        GPIO_CTRL->PORT[port].ODR |= pinMask;
    }
    else
    {
        /* Disable open drain drive */
        GPIO_CTRL->PORT[port].ODR &= ~pinMask;
    }
#endif

    if (config & kGPIO_PADCONFIG_PULLDOWN)
    {
        /* Enable pull up resister */
        GPIO_CTRL->PORT[port].PDD &= ~pinMask;
    }
    else
    {
        /* Disable pull up resister */
        GPIO_CTRL->PORT[port].PDD |= pinMask;
    }

    if (config & kGPIO_PADCONFIG_NO_FORCE_INPUT)
    {
        /* Enable force input */
        GPIO_CTRL->PORT[port].FID |= pinMask;
    }
    else
    {
        /* Disable force input */
        GPIO_CTRL->PORT[port].FID &= ~pinMask;
    }

    if (config & kGPIO_PADCONFIG_SCHMITT)
    {
        /* Enable Schmitt trigger */
        GPIO_CTRL->PORT[port].ST |= pinMask;
    }
    else
    {
        /* Disable Schmitt trigger */
        GPIO_CTRL->PORT[port].ST &= ~pinMask;
    }

    if (config & kGPIO_PADCONFIG_LOOPBACK)
    {
        /* Enable loop back */
        GPIO_CTRL->PORT[port].LPB |= pinMask;
    }
    else
    {
        /* Disable loop back */
        GPIO_CTRL->PORT[port].LPB &= ~pinMask;
    }
}

uint32_t GPIO_getPadConfig(uint32_t pin)
{
    GPIO_Port_t port      = GPIO_getPort(pin);
    uint32_t    pinMask   = 0x1U << (pin % GPIO_CTRL_PIN_COUNT_PER_PORT);
    uint32_t    padConfig = 0U;

    if (!(GPIO_CTRL->PORT[port].PUD & pinMask))
    {
        padConfig |= kGPIO_PADCONFIG_PULLUP;
    }

    if (GPIO_CTRL->PORT[port].INV & pinMask)
    {
        padConfig |= kGPIO_PADCONFIG_INPUT_INVERT;
    }

#if !(defined(HTE_FEATURE_GPIO_NOT_SUPPORT_OPEN_DRAIN) && HTE_FEATURE_GPIO_NOT_SUPPORT_OPEN_DRAIN)
    if (GPIO_CTRL->PORT[port].ODR & pinMask)
    {
        padConfig |= kGPIO_PADCONFIG_OPEN_DRAIN;
    }
#endif

    if (!(GPIO_CTRL->PORT[port].PDD & pinMask))
    {
        padConfig |= kGPIO_PADCONFIG_PULLDOWN;
    }

    if (GPIO_CTRL->PORT[port].FID & pinMask)
    {
        padConfig |= kGPIO_PADCONFIG_NO_FORCE_INPUT;
    }

    if (GPIO_CTRL->PORT[port].ST & pinMask)
    {
        padConfig |= kGPIO_PADCONFIG_SCHMITT;
    }

    if (GPIO_CTRL->PORT[port].LPB & pinMask)
    {
        padConfig |= kGPIO_PADCONFIG_LOOPBACK;
    }

    return padConfig;
}

void GPIO_setDriverStrength(uint32_t pin, GPIO_DriverStrength_t str)
{
    GPIO_Port_t port      = GPIO_getPort(pin);
    uint32_t    pinPerReg = GPIO_CTRL_PIN_COUNT_PER_PORT / GPIO_CTRL_DS_DS1_Pos;
    uint32_t    dsIndex   = (pin % GPIO_CTRL_PIN_COUNT_PER_PORT) / pinPerReg;
    uint32_t    dsShift   = ((pin % GPIO_CTRL_PIN_COUNT_PER_PORT) % pinPerReg) * GPIO_CTRL_DS_DS1_Pos;

    /* Clear MUX to avoid glitches */
    GPIO_CTRL->PORT[port].DS[dsIndex] &= ~(GPIO_CTRL_DS_DS0_Msk << dsShift);

    /* Configure MUX */
    GPIO_CTRL->PORT[port].DS[dsIndex] |= str << dsShift;
}

GPIO_DriverStrength_t GPIO_getDriverStrength(uint32_t pin)
{
    GPIO_Port_t port      = GPIO_getPort(pin);
    uint32_t    pinPerReg = GPIO_CTRL_PIN_COUNT_PER_PORT / GPIO_CTRL_DS_DS1_Pos;
    uint32_t    dsIndex   = (pin % GPIO_CTRL_PIN_COUNT_PER_PORT) / pinPerReg;
    uint32_t    dsShift   = ((pin % GPIO_CTRL_PIN_COUNT_PER_PORT) % pinPerReg) * GPIO_CTRL_DS_DS1_Pos;

    return (GPIO_DriverStrength_t)((GPIO_CTRL->PORT[port].DS[dsIndex] >> dsShift) & GPIO_CTRL_DS_DS0_Msk);
}
#endif /* HTE_FEATURE_GPIO_CTRL_COUNT */

#if defined(HTE_FEATURE_XINT_COUNT) && HTE_FEATURE_XINT_COUNT
#if defined(HTE_FEATURE_INPUT_XBAR_COUNT) && HTE_FEATURE_INPUT_XBAR_COUNT
void GPIO_setInterruptPin(uint32_t pin, GPIO_ExternalIntNum_t num)
{
    assert(GPIO_isPinValid(pin));
    assert(num < ARRAY_SIZE(s_xinInputXbarTable));

    XBAR_setInputPin(INPUT_XBAR, s_xinInputXbarTable[num], pin);
}
#endif /* HTE_FEATURE_INPUT_XBAR_COUNT */

#if defined(HTE_FEATURE_XIN_FLAG_HAS_PENDING_IRQ) && HTE_FEATURE_XIN_FLAG_HAS_PENDING_IRQ
void GPIO_enableInterrupt(GPIO_ExternalIntNum_t num)
{
    /* Disable all IRQs to avoid the clear and enable operation to be interrupted */
    uint32_t priMask = disableGlobalIRQ();

    /* Clear the interrupt flag to ignore the pending interrupts */
    GPIO_clearInterruptFlag(num);
    /* Enable the interrupt */
    XINT->CR[num] |= XINT_CR_ENABLE_Msk;

    /* Restore the IRQs */
    enableGlobalIRQ(priMask);
}
#endif /* HTE_FEATURE_XIN_FLAG_HAS_PENDING_IRQ */

#if defined(HTE_FEATURE_XIN_COUNTER_HAS_NON_CONTINUOUS_ADDRESS) && HTE_FEATURE_XIN_COUNTER_HAS_NON_CONTINUOUS_ADDRESS
uint16_t GPIO_getInterruptCounter(GPIO_ExternalIntNum_t num)
{
    assert(num < ARRAY_SIZE(s_xintCtrAddrTable));

    return *s_xintCtrAddrTable[num];
}
#endif /* HTE_FEATURE_XIN_COUNTER_HAS_NON_CONTINUOUS_ADDRESS */
#endif /* HTE_FEATURE_XINT_COUNT */
