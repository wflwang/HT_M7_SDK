/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*!
 * \file adc_soc_software.c
 * \brief adc_soc_software example file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "board.h"
#include "hte_adc.h"
#include "hte_sysctrl.h"

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void configureADC(ADC_Type *adcBase);
void configureSOC(ADC_Type *adcBase, ADC_SOCNumber_t socNumber, ADC_Channel_t adcChannel);

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! \brief ADC used by CPU1 in this example */
#define EXAMPLE_ADC0_CPU1 (ADCA)
/*! \brief ADC result used by CPU1 in this example */
#define EXAMPLE_ADC0_RESULT_CPU1 (ADC_RESULTA)
/*! \brief ADC used by CPU1 in this example */
#define EXAMPLE_ADC1_CPU1 (ADCC)
/*! \brief ADC result used by CPU1 in this example */
#define EXAMPLE_ADC1_RESULT_CPU1 (ADC_RESULTC)

/*! \brief ADC used by CPU2 in this example */
#define EXAMPLE_ADC0_CPU2 (ADCB)
/*! \brief ADC result used by CPU2 in this example */
#define EXAMPLE_ADC0_RESULT_CPU2 (ADC_RESULTB)
/*! \brief EPWM used by CPU2 to trigger ADC sampling in this example */
/*! \brief ADC used by CPU2 in this example */
#define EXAMPLE_ADC1_CPU2 (ADCD)
/*! \brief ADC result used by CPU2 in this example */
#define EXAMPLE_ADC1_RESULT_CPU2 (ADC_RESULTD)


#if defined(BOARD_USE_CPU1)
/*! \brief ADC used in this example */
#define EXAMPLE_ADC0_MODULE EXAMPLE_ADC0_CPU1
/*! \brief ADC result in this example */
#define EXAMPLE_ADC0_RESULT EXAMPLE_ADC0_RESULT_CPU1
/*! \brief ADC used in this example */
#define EXAMPLE_ADC1_MODULE EXAMPLE_ADC1_CPU1
/*! \brief ADC result in this example */
#define EXAMPLE_ADC1_RESULT EXAMPLE_ADC1_RESULT_CPU1

#elif defined(BOARD_USE_CPU2)
/*! \brief ADC used in this example */
#define EXAMPLE_ADC0_MODULE EXAMPLE_ADC0_CPU2
/*! \brief ADC result in this example */
#define EXAMPLE_ADC0_RESULT EXAMPLE_ADC0_RESULT_CPU2
/*! \brief ADC used in this example */
#define EXAMPLE_ADC1_MODULE EXAMPLE_ADC1_CPU2
/*! \brief ADC result in this example */
#define EXAMPLE_ADC1_RESULT EXAMPLE_ADC1_RESULT_CPU2
#endif

/* result size definition*/
#define RESULTS_BUFFER_SIZE 256U // buffer for storing conversion results
//(size must be multiple of 16)
/* ADC resolution definition*/
#define EX_ADC_RESOLUTION 12U

/* SOC force trigger msk*/
#define ADC_FORCE_SOC0  0x0001U //!< SW trigger ADC SOC 0
#define ADC_FORCE_SOC1  0x0002U //!< SW trigger ADC SOC 1
#define ADC_FORCE_SOC2  0x0004U //!< SW trigger ADC SOC 2
#define ADC_FORCE_SOC3  0x0008U //!< SW trigger ADC SOC 3
#define ADC_FORCE_SOC4  0x0010U //!< SW trigger ADC SOC 4
#define ADC_FORCE_SOC5  0x0020U //!< SW trigger ADC SOC 5
#define ADC_FORCE_SOC6  0x0040U //!< SW trigger ADC SOC 6
#define ADC_FORCE_SOC7  0x0080U //!< SW trigger ADC SOC 7
#define ADC_FORCE_SOC8  0x0100U //!< SW trigger ADC SOC 8
#define ADC_FORCE_SOC9  0x0200U //!< SW trigger ADC SOC 9
#define ADC_FORCE_SOC10 0x0400U //!< SW trigger ADC SOC 10
#define ADC_FORCE_SOC11 0x0800U //!< SW trigger ADC SOC 11
#define ADC_FORCE_SOC12 0x1000U //!< SW trigger ADC SOC 12
#define ADC_FORCE_SOC13 0x2000U //!< SW trigger ADC SOC 13
#define ADC_FORCE_SOC14 0x4000U //!< SW trigger ADC SOC 14
#define ADC_FORCE_SOC15 0x8000U //!< SW trigger ADC SOC 15

/*******************************************************************************
 * Variables
 ******************************************************************************/
/* Globals*/
uint16_t adcAResult0;
uint16_t adcAResult1;
uint16_t adcDResult0;
uint16_t adcDResult1;

/*******************************************************************************
 * Codes
 ******************************************************************************/

void main(void)
{
    /* Initialize device clock and peripherals */
    BOARD_init();

    /* ASSIGN  ADC to CPU2 */
#if defined(BOARD_CONFIG_CPU2)
    BOARD_adcAssign2CPU2(EXAMPLE_ADC0_CPU2);
    BOARD_adcAssign2CPU2(EXAMPLE_ADC1_CPU2);
#endif

    /* Enable the clock for the ADC peripheral  */
    BOARD_adcClockEnable(EXAMPLE_ADC0_MODULE);
    BOARD_adcClockEnable(EXAMPLE_ADC1_MODULE);


    /* Configure the ADC and power it up  */
    configureADC(EXAMPLE_ADC0_MODULE);
    configureADC(EXAMPLE_ADC1_MODULE);

    /* initADCSOC - Function to configure ADCA's SOC0 to be triggered by software. */
    configureSOC(EXAMPLE_ADC0_MODULE, kADC_SOC_NUMBER0, kADC_CH_ADCIN2);
    configureSOC(EXAMPLE_ADC0_MODULE, kADC_SOC_NUMBER1, kADC_CH_ADCIN3);
    configureSOC(EXAMPLE_ADC1_MODULE, kADC_SOC_NUMBER0, kADC_CH_ADCIN2);
    configureSOC(EXAMPLE_ADC1_MODULE, kADC_SOC_NUMBER1, kADC_CH_ADCIN3);

    /* Loop indefinitely */
    while (1)
    {
        /* Convert, wait for completion, and store results */
        ADC_forceMultipleSOC(EXAMPLE_ADC0_MODULE, (ADC_FORCE_SOC0 | ADC_FORCE_SOC1));

        /* Wait for ADCA to complete, then acknowledge flag */
        while (ADC_getInterruptStatus(EXAMPLE_ADC0_MODULE, kADC_INT_NUMBER1) == false)
        {
        }
        ADC_clearInterruptStatus(EXAMPLE_ADC0_MODULE, kADC_INT_NUMBER1);

        ADC_forceMultipleSOC(EXAMPLE_ADC1_MODULE, (ADC_FORCE_SOC0 | ADC_FORCE_SOC1));

        /* Wait for ADCD to complete, then acknowledge flag*/
        while (ADC_getInterruptStatus(EXAMPLE_ADC1_MODULE, kADC_INT_NUMBER1) == false)
        {
        }
        ADC_clearInterruptStatus(EXAMPLE_ADC1_MODULE, kADC_INT_NUMBER1);

        /* Store results */
        adcAResult0 = ADC_readResult(EXAMPLE_ADC0_RESULT, kADC_SOC_NUMBER0);
        adcAResult1 = ADC_readResult(EXAMPLE_ADC0_RESULT, kADC_SOC_NUMBER1);
        adcDResult0 = ADC_readResult(EXAMPLE_ADC1_RESULT, kADC_SOC_NUMBER0);
        adcDResult1 = ADC_readResult(EXAMPLE_ADC1_RESULT, kADC_SOC_NUMBER1);

        /* Software breakpoint. At this point, conversion results are stored in
         * adcAResult0, adcAResult1, adcDResult0, and adcDResult1.
         */
    }
}

/*!
 * \brief Configures the ADC module.
 *
 * \details This function sets up the ADC module according to the specified configuration.
 * It loads linear calibration data, sets the ADC resolution and signal mode,
 * loads gain calibration data, sets the interrupt pulse mode,
 * powers up the ADCs, and waits for the ADC to power up.
 *
 * \param[in] adcBase A pointer to the ADC base address.
 *
 */
void configureADC(ADC_Type *adcBase)
{
    /* Set resolution and signal mode (see #defines above) and load */
    /* corresponding trims. */

    /* Load gain calibration data */
#if (EX_ADC_RESOLUTION == 12)
    ADC_setMode(adcBase, kADC_RESOLUTION_12BIT, kADC_MODE_SINGLE_ENDED);
#elif (EX_ADC_RESOLUTION == 16)
    ADC_setMode(adcBase, kADC_RESOLUTION_16BIT, kADC_MODE_DIFFERENTIAL);
#endif

    /* Set pulse positions to late */
    ADC_setInterruptPulseMode(adcBase, kADC_PULSE_END_OF_CONV);

    /* Power up the ADCs and then delay for 1 ms */
    ADC_enableConverter(adcBase);

    /* Delay for 1ms to allow ADC time to power up */
    DELAY(1000);
}

/*!
 * \brief Configures ADC's SOC number to be triggered by software
 *
 * \details This function sets up the SOC module according to the specified configuration.
 * It configures the SOC0 as ADCIN13 channel converter, INT1 is trigged by EOC0
 *
 * \param[in] adcBase A pointer to the ADC base address.
 *
 */
void configureSOC(ADC_Type *adcBase, ADC_SOCNumber_t socNumber, ADC_Channel_t adcChannel)
{
    /* Configure socNumber to be triggered by software. */
    ADC_setupSOC(adcBase, socNumber, kADC_TRIGGER_SW_ONLY, adcChannel, 140);

    /* Set socNumber to set the interrupt 1 flag. Enable the interrupt and make
     * sure its flag is cleared.
     */
    ADC_setInterruptSource(adcBase, kADC_INT_NUMBER1, socNumber);
    ADC_enableInterrupt(adcBase, kADC_INT_NUMBER1);
    ADC_clearInterruptStatus(adcBase, kADC_INT_NUMBER1);
}
