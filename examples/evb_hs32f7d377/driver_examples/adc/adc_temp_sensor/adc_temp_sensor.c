/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*!
 * \file adc_temp_sensor.c
 * \brief adc_temp_sensor example file
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
void configureSOC(ADC_Type *adcBase);

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* VREF Voltage*/
#define VREF 2500

/*! \brief ADC used by CPU1 in this example */
#define EXAMPLE_ADC_CPU1 (ADCA)
/*! \brief ADC result used by CPU1 in this example */
#define EXAMPLE_ADC_RESULT_CPU1 (ADC_RESULTA)
/*! \brief ADC used by CPU2 in this example */
#define EXAMPLE_ADC_CPU2 (ADCA)
/*! \brief ADC result used by CPU2 in this example */
#define EXAMPLE_ADC_RESULT_CPU2 (ADC_RESULTA)


#if defined(BOARD_USE_CPU1)
/*! \brief ADC used in this example */
#define EXAMPLE_ADC_MODULE EXAMPLE_ADC_CPU1
/*! \brief ADC result in this example */
#define EXAMPLE_ADC_RESULT EXAMPLE_ADC_RESULT_CPU1
#elif defined(BOARD_USE_CPU2)
/*! \brief ADC used in this example */
#define EXAMPLE_ADC_MODULE EXAMPLE_ADC_CPU2
/*! \brief ADC result in this example */
#define EXAMPLE_ADC_RESULT EXAMPLE_ADC_RESULT_CPU2
#endif


/*******************************************************************************
 * Variables
 ******************************************************************************/
/* ADC temperature value */
uint16_t sensorSample;
int16_t  sensorTemp;

/* If you want to use the temperature sensor in CPU2, you need to define TEMP_USE_CPU2,
 * otherwise not defined */
// #define TEMP_USE_CPU2
/*******************************************************************************
 * Codes
 ******************************************************************************/
void main(void)
{
    BOARD_init();

    /* ASSIGN  ADC to CPU2 */
#if defined(BOARD_CONFIG_CPU2) && defined(TEMP_USE_CPU2)
    BOARD_adcAssign2CPU2(EXAMPLE_ADC_CPU2);
#endif
    /* Enable the clock for the ADC peripheral  */
    BOARD_adcClockEnable(EXAMPLE_ADC_MODULE);

    /* Configure the ADC and power it up  */
    configureADC(EXAMPLE_ADC_MODULE); // Configure the ADC module

    /* initADCSOC - Function to configure ADCA's SOC0 to be triggered by software. */
    configureSOC(EXAMPLE_ADC_MODULE);

    /* Enable the temperature sensor and give it 500 us to power up */
#if defined(BOARD_USE_CPU1)
    SYSCTRL_setTSNSCTL(kSYSC_ENABLE);
#endif

    DELAY(500);

    /* Take conversions indefinitely in loop  */
    do
    {
        /* Clear all interrupt flags (INT1)  */
        EXAMPLE_ADC_MODULE->ADCSOCOVFCLR1 = 0x0001;

        /* Initialize temperature sensor value  */
        sensorSample = 0;

        /* Software force start SOC0 */
        EXAMPLE_ADC_MODULE->ADCSOCFRC1 = 0x0001;

        /* Block until the first set of SOC0 conversions completes  */
        while (false == ADC_getInterruptStatus(EXAMPLE_ADC_MODULE, kADC_INT_NUMBER1))
            ;

        /* read temperature code */
        sensorSample = ADC_readResult(EXAMPLE_ADC_RESULT, kADC_SOC_NUMBER0);

        /* Clear the interrupt flag to indicate that the conversions have been processed */
        ADC_clearInterruptStatus(EXAMPLE_ADC_MODULE, kADC_INT_NUMBER1);

        /* Convert the result to a temperature in degrees C */
        sensorTemp = ADC_getTemperatureC(sensorSample, VREF);

        /* At this point, temperature degree has been calcuted, and saved in sensorTemp */
    } while (1);
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
    ADC_setMode(adcBase, kADC_RESOLUTION_12BIT, kADC_MODE_SINGLE_ENDED);

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
void configureSOC(ADC_Type *adcBase)
{
    /* Configure SOC0. The temperature sensor is internally connected to A13
     * and requires an acquisition time of at least 700 ns.
     */
    ADC_setupSOC(ADCA, kADC_SOC_NUMBER0, kADC_TRIGGER_SW_ONLY, kADC_CH_ADCIN13, 140);

    /* Set SOC0 to set the interrupt 1 flag. Enable the interrupt and make
     * sure its flag is cleared.
     */
    ADC_setInterruptSource(ADCA, kADC_INT_NUMBER1, kADC_SOC_NUMBER0);
    ADC_enableInterrupt(ADCA, kADC_INT_NUMBER1);
    ADC_clearInterruptStatus(ADCA, kADC_INT_NUMBER1);
}
