/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*!
 * \file adc_soc_epwm.c
 * \brief ADC example file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "board.h"
#include "hte_adc.h"
#include "hte_epwm.h"
#include "hte_gpio.h"
#include "hte_pinmux.h"
#include "hte_sysctrl.h"
//
// Function Prototypes
//
//
// Defines
//
/*! \brief ADC used by CPU1 in this example */
#define EXAMPLE_ADC_CPU1 (ADCA)
/*! \brief ADC result used by CPU1 in this example */
#define EXAMPLE_ADC_RESULT_CPU1 (ADC_RESULTA)
/*! \brief EPWM used by CPU1 to trigger ADC sampling in this example */
#define EXAMPLE_EPWM_SAMPLE_CPU1 (EPWM1)
/*! \brief CPU1 ADC_TRIGGER */
#define EXAMPLE_ADC_TRIGGER_CPU1 (kADC_TRIGGER_EPWM1_SOCA)
/*! \brief EPWM used by CPU2 to trigger ADC sampling in this example */
#define EXAMPLE_EPWM_SAMPLE_CPU2 (EPWM3)
/*! \brief CPU2 ADC_TRIGGER */
#define EXAMPLE_ADC_TRIGGER_CPU2 (kADC_TRIGGER_EPWM3_SOCA)
/*! \brief ADC used by CPU2 in this example */
#define EXAMPLE_ADC_CPU2 (ADCB)
/*! \brief ADC result used by CPU2 in this example */
#define EXAMPLE_ADC_RESULT_CPU2 (ADC_RESULTB)
/*! \brief EPWM used by CPU2 to trigger ADC sampling in this example */
#define EXAMPLE_EPWM_SAMPLE_CPU2 (EPWM3)
/*! \brief EPWM time base clock divider */
#define EXAMPLE_EPWM_CLKDIV (EPWM_CLOCK_DIVIDER_2)
/*! \brief EPWM high speed time base clock divider */
#define EXAMPLE_EPWM_HSPCLKDIV (EPWM_HSCLOCK_DIVIDER_1)

#if defined(BOARD_USE_CPU1)
/*! \brief ADC used in this example */
#define EXAMPLE_ADC_MODULE EXAMPLE_ADC_CPU1
/*! \brief ADC result in this example */
#define EXAMPLE_ADC_RESULTB EXAMPLE_ADC_RESULT_CPU1
/*! \brief EPWM used to trigger ADC sampling in this example */
#define EXAMPLE_EPWM_SAMPLE EXAMPLE_EPWM_SAMPLE_CPU1
/*! \brief ADC_TRIGGER */
#define EXAMPLE_ADC_TRIGGER EXAMPLE_ADC_TRIGGER_CPU1
#elif defined(BOARD_USE_CPU2)
/*! \brief ADC used in this example */
#define EXAMPLE_ADC_MODULE  EXAMPLE_ADC_CPU2
/*! \brief ADC result in this example */
#define EXAMPLE_ADC_RESULTB EXAMPLE_ADC_RESULT_CPU2
/*! \brief EPWM used to trigger ADC sampling in this example */
#define EXAMPLE_EPWM_SAMPLE EXAMPLE_EPWM_SAMPLE_CPU2
/*! \brief ADC_TRIGGER */
#define EXAMPLE_ADC_TRIGGER EXAMPLE_ADC_TRIGGER_CPU2
#endif

#define EXAMPLE_ADC_EPWM_IRQHANDLER // get the result value from the interrupt handler function
#define EXAMPLE_ADC_CHANNEL2        (kADC_CH_ADCIN2)
#define EXAMPLE_ADC_CHANNEL3        (kADC_CH_ADCIN3)
#define RESULTS_BUFFER_SIZE         (480U) // buffer for storing conversion results(size must be multiple of 16)
#define EXAMPLE_ADC_RESOLUTION      kADC_RESOLUTION_12BIT
#define EXAMPLE_ADC_ACQPS           (0x190) //(0xB0) //20KHZ SINE PWM20kHZ  40KHZ 0xB0
#define EXAMPLE_ADC_CONVERTTIME     (0x28)

volatile uint16_t g_bufferFULL = 0;

//
// Globals
//
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Size of Transmission buffer */
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/* No Prototypes */
uint16_t g_adcResults[RESULTS_BUFFER_SIZE];

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*******************************************************************************
 * Codes
 ******************************************************************************/

/*!
 * \brief Configure ADC module
 *
 * \details This function is used to configure the ADC module. It initializes the ADC hardware and sets
 * up the necessary parameters for ADC operations, such as resolution.
 *
 * \param[in] adcBase Pointer to the base address of the ADC module
 *   - A pointer to the base address structure of the ADC module, providing access to ADC-specific registers.
 *
 * \return None
 */
void ADC_configure(ADC_Type *adcBase)
{
    ADC_setMode(adcBase, EXAMPLE_ADC_RESOLUTION, kADC_MODE_SINGLE_ENDED);
    ADC_setInterruptPulseMode(adcBase, kADC_PULSE_END_OF_CONV);
    ADC_enableConverter(adcBase);
    DELAY(1000);
}

/*!
 * \brief Set up ADC for EPWM (Enhanced Pulse Width Modulation)
 *
 * \details This function configures the ADC module for use with an EPWM (Enhanced Pulse Width Modulation)
 * system. It initializes the ADC with parameters specific to EPWM applications, such as trigger sources,
 * sampling rates, and synchronization settings.
 *
 * \param[in] adcBase Pointer to the base address of the ADC module
 *   - A pointer to the base address structure of the ADC module, allowing access to ADC-specific registers.
 *
 * \return None
 */
void ADC_setupEPWM(ADC_Type *adcBase)
{
    ADC_setupSOC(adcBase, kADC_SOC_NUMBER0, EXAMPLE_ADC_TRIGGER, EXAMPLE_ADC_CHANNEL2, EXAMPLE_ADC_ACQPS);
    ADC_setupSOC(adcBase, kADC_SOC_NUMBER1, EXAMPLE_ADC_TRIGGER, EXAMPLE_ADC_CHANNEL3, EXAMPLE_ADC_ACQPS);
    ADC_setupSOC(adcBase, kADC_SOC_NUMBER2, EXAMPLE_ADC_TRIGGER, EXAMPLE_ADC_CHANNEL2, EXAMPLE_ADC_ACQPS);
    ADC_setupSOC(adcBase, kADC_SOC_NUMBER3, EXAMPLE_ADC_TRIGGER, EXAMPLE_ADC_CHANNEL3, EXAMPLE_ADC_ACQPS);
    ADC_setupSOC(adcBase, kADC_SOC_NUMBER4, EXAMPLE_ADC_TRIGGER, EXAMPLE_ADC_CHANNEL2, EXAMPLE_ADC_ACQPS);
    ADC_setupSOC(adcBase, kADC_SOC_NUMBER5, EXAMPLE_ADC_TRIGGER, EXAMPLE_ADC_CHANNEL3, EXAMPLE_ADC_ACQPS);
    ADC_setupSOC(adcBase, kADC_SOC_NUMBER6, EXAMPLE_ADC_TRIGGER, EXAMPLE_ADC_CHANNEL2, EXAMPLE_ADC_ACQPS);
    ADC_setupSOC(adcBase, kADC_SOC_NUMBER7, EXAMPLE_ADC_TRIGGER, EXAMPLE_ADC_CHANNEL3, EXAMPLE_ADC_ACQPS);
    ADC_setupSOC(adcBase, kADC_SOC_NUMBER8, EXAMPLE_ADC_TRIGGER, EXAMPLE_ADC_CHANNEL2, EXAMPLE_ADC_ACQPS);
    ADC_setupSOC(adcBase, kADC_SOC_NUMBER9, EXAMPLE_ADC_TRIGGER, EXAMPLE_ADC_CHANNEL3, EXAMPLE_ADC_ACQPS);
    ADC_setupSOC(adcBase, kADC_SOC_NUMBER10, EXAMPLE_ADC_TRIGGER, EXAMPLE_ADC_CHANNEL2, EXAMPLE_ADC_ACQPS);
    ADC_setupSOC(adcBase, kADC_SOC_NUMBER11, EXAMPLE_ADC_TRIGGER, EXAMPLE_ADC_CHANNEL3, EXAMPLE_ADC_ACQPS);
    ADC_setupSOC(adcBase, kADC_SOC_NUMBER12, EXAMPLE_ADC_TRIGGER, EXAMPLE_ADC_CHANNEL2, EXAMPLE_ADC_ACQPS);
    ADC_setupSOC(adcBase, kADC_SOC_NUMBER13, EXAMPLE_ADC_TRIGGER, EXAMPLE_ADC_CHANNEL3, EXAMPLE_ADC_ACQPS);
    ADC_setupSOC(adcBase, kADC_SOC_NUMBER14, EXAMPLE_ADC_TRIGGER, EXAMPLE_ADC_CHANNEL2, EXAMPLE_ADC_ACQPS);
    ADC_setupSOC(adcBase, kADC_SOC_NUMBER15, EXAMPLE_ADC_TRIGGER, EXAMPLE_ADC_CHANNEL3, EXAMPLE_ADC_ACQPS);

    ADC_setSocConvertTime(adcBase, kADC_SOC_NUMBER0, EXAMPLE_ADC_CONVERTTIME);
    ADC_setSocConvertTime(adcBase, kADC_SOC_NUMBER1, EXAMPLE_ADC_CONVERTTIME);
    ADC_setSocConvertTime(adcBase, kADC_SOC_NUMBER2, EXAMPLE_ADC_CONVERTTIME);
    ADC_setSocConvertTime(adcBase, kADC_SOC_NUMBER3, EXAMPLE_ADC_CONVERTTIME);
    ADC_setSocConvertTime(adcBase, kADC_SOC_NUMBER4, EXAMPLE_ADC_CONVERTTIME);
    ADC_setSocConvertTime(adcBase, kADC_SOC_NUMBER5, EXAMPLE_ADC_CONVERTTIME);
    ADC_setSocConvertTime(adcBase, kADC_SOC_NUMBER6, EXAMPLE_ADC_CONVERTTIME);
    ADC_setSocConvertTime(adcBase, kADC_SOC_NUMBER7, EXAMPLE_ADC_CONVERTTIME);
    ADC_setSocConvertTime(adcBase, kADC_SOC_NUMBER8, EXAMPLE_ADC_CONVERTTIME);
    ADC_setSocConvertTime(adcBase, kADC_SOC_NUMBER9, EXAMPLE_ADC_CONVERTTIME);
    ADC_setSocConvertTime(adcBase, kADC_SOC_NUMBER10, EXAMPLE_ADC_CONVERTTIME);
    ADC_setSocConvertTime(adcBase, kADC_SOC_NUMBER11, EXAMPLE_ADC_CONVERTTIME);
    ADC_setSocConvertTime(adcBase, kADC_SOC_NUMBER12, EXAMPLE_ADC_CONVERTTIME);
    ADC_setSocConvertTime(adcBase, kADC_SOC_NUMBER13, EXAMPLE_ADC_CONVERTTIME);
    ADC_setSocConvertTime(adcBase, kADC_SOC_NUMBER14, EXAMPLE_ADC_CONVERTTIME);
    ADC_setSocConvertTime(adcBase, kADC_SOC_NUMBER15, EXAMPLE_ADC_CONVERTTIME);

    ADC_disableInterrupt(adcBase, kADC_INT_NUMBER1);
    ADC_setInterruptSource(adcBase, kADC_INT_NUMBER1, kADC_SOC_NUMBER15);
    ADC_enableInterrupt(adcBase, kADC_INT_NUMBER1);
    ADC_clearInterruptStatus(adcBase, kADC_INT_NUMBER1);
}

/*!
 * \brief adc callback
 *
 * \details This function configures the ADC module for use with an EPWM (Enhanced Pulse Width Modulation)
 * system. It initializes the ADC with parameters specific to EPWM applications, such as trigger sources,
 * sampling rates, and synchronization settings.
 *
 * \param[in] adc_idx the ADC module index
 * \param[in] irq_idx the ADC IRQ index
 *
 * \return None
 */
void adc_Int1_Callback(ADC_Idx_t adc_idx, ADC_Irq_Idx_t irq_idx)
{
    static uint32_t s_index = 0;

    if (s_index == RESULTS_BUFFER_SIZE / 16)
    {
        g_bufferFULL = 1;
    }
    else
    {
        for (int i = 0; i < 16; i++)
        {
            g_adcResults[i + s_index * 16] = ADC_readResult(EXAMPLE_ADC_RESULTB, (ADC_SOCNumber_t)i);
        }
        s_index++;
    }
    ADC_clearInterruptStatus(EXAMPLE_ADC_MODULE, kADC_INT_NUMBER1);
}

/*!
 * \brief Initilize EPWM as sample frequency to trigger ADC sampling
 *
 * \details This function configures the EPWM as sample frequency to trigger ADC sampling
 *
 * \param[in] base Pointer to the base address of the EPWM module
 *
 * \return None
 */
void initEpwmAsSampleClk(EPWM_REGS_Type *base)
{
    /* Set EWPM time base clock */
    EPWM_setClockPrescaler(base, EXAMPLE_EPWM_CLKDIV, EXAMPLE_EPWM_HSPCLKDIV);

    /* EPWM run in count up mode */
    EPWM_setTimeBaseCounterMode(base, EPWM_COUNTER_MODE_UP);

    /* Set EPWM period */
    EPWM_setTimeBasePeriod(base, 7500); // 3750:40KHZ  7500:20KHZ

    /* Set EPWM initial counter to zero */
    EPWM_setTimeBaseCounter(base, 0U);

    /* EPWM should toggle each time its counter hits zero */
    EPWM_setActionQualifierAction(base, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_TOGGLE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);

    /* Enable SOC-A. It asserts on every event */
    EPWM_enableADCTrigger(base, EPWM_SOC_A);

    /* SOC-A asserts when the counter hits zero*/
    EPWM_setADCTriggerSource(base, EPWM_SOC_A, EPWM_SOC_TBCTR_ZERO);

    /* SOC-A asserts on every event */
    EPWM_setADCTriggerEventPrescale(base, EPWM_SOC_A, 1U);
}

void main(void)
{
    BOARD_init();

#if defined(BOARD_CONFIG_CPU2)
    BOARD_adcAssign2CPU2(EXAMPLE_ADC_CPU2);
    BOARD_epwmAssign2CPU2(EXAMPLE_EPWM_SAMPLE_CPU2);
#endif

    BOARD_adcClockEnable(EXAMPLE_ADC_MODULE);
    BOARD_epwmClockEnable(EXAMPLE_EPWM_SAMPLE);

    /* Disable sync and clock to EPWM */
    SYSCTRL_disablePeripheral(kSYSCTL_PERIPH_CLK_TBCLKSYNC);

    /* Setup EPWM which is used as sampling clock */
    initEpwmAsSampleClk(EXAMPLE_EPWM_SAMPLE);
    /* Setup EPWM which is used as the square wave to be sampled */

    /* Enable sync and clock to EPWM after the configuration */
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_TBCLKSYNC);

#ifdef EXAMPLE_ADC_EPWM_IRQHANDLER
    ADC_registerCallback(EXAMPLE_ADC_MODULE, kADC_INT1_IRQn, (ADC_Callback_t)adc_Int1_Callback, 5);
#endif

    /* Configure the ADC and power it up */
    ADC_configure(EXAMPLE_ADC_MODULE);
    ADC_setupEPWM(EXAMPLE_ADC_MODULE);
    while (1)
    {
#ifndef EXAMPLE_ADC_EPWM_IRQHANDLER
        for (int loopindex = 0; loopindex < RESULTS_BUFFER_SIZE / 16; loopindex++)
        {
            while (ADC_getInterruptStatus(EXAMPLE_ADC_MODULE, kADC_INT_NUMBER1) == false)
                ;
            ADC_clearInterruptStatus(EXAMPLE_ADC_MODULE, kADC_INT_NUMBER1);
            for (int i = 0; i < 16; i++)
            {
                g_adcResults[i + loopindex * 16] = ADC_readResult(EXAMPLE_ADC_RESULTB, (ADC_SOCNumber_t)i);
            }
        }
        g_bufferFULL = 1;
#endif
        if (g_bufferFULL)
        {
            EPWM_disableADCTrigger(EXAMPLE_EPWM_SAMPLE, EPWM_SOC_A);
            for (int i = 0; i < RESULTS_BUFFER_SIZE / 2; i++)
            {
                PRINTF("%d %d\r\n", g_adcResults[2 * i], g_adcResults[2 * i + 1]);
            }
            g_bufferFULL = 0;
        }
    }
}
