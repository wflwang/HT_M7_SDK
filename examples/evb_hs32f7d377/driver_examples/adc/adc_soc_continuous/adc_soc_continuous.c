/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*!
 * \file adc_soc_continous.c
 * \brief adc_soc_continous example file
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
void setupADCContinuous(ADC_Type *adcBase, uint32_t channel);

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! \brief ADC used by CPU1 in this example */
#define EXAMPLE_ADC_CPU1 (ADCA)
/*! \brief ADC result used by CPU1 in this example */
#define EXAMPLE_ADC_RESULT_CPU1 (ADC_RESULTA)
/*! \brief ADC used by CPU2 in this example */
#define EXAMPLE_ADC_CPU2 (ADCB)
/*! \brief ADC result used by CPU2 in this example */
#define EXAMPLE_ADC_RESULT_CPU2 (ADC_RESULTB)

#if defined(BOARD_USE_CPU1)
/*! \brief ADC used in this example */
#define EXAMPLE_ADC_MODULE EXAMPLE_ADC_CPU1
/*! \brief ADC result in this example */
#define EXAMPLE_ADC_RESULTB EXAMPLE_ADC_RESULT_CPU1
#elif defined(BOARD_USE_CPU2)
/*! \brief ADC used in this example */
#define EXAMPLE_ADC_MODULE  EXAMPLE_ADC_CPU2
/*! \brief ADC result in this example */
#define EXAMPLE_ADC_RESULTB EXAMPLE_ADC_RESULT_CPU2
#endif
/* result size definition*/
#define RESULTS_BUFFER_SIZE \
    256U // buffer for storing conversion results
         //(size must be multiple of 16)
/* ADC resolution definition*/
#define EX_ADC_RESOLUTION       kADC_RESOLUTION_12BIT
#define EXAMPLE_ADC_ACQPS       (0x32) //(0xB0) //20KHZ SINE PWM20kHZ  40KHZ 0xB0
#define EXAMPLE_ADC_CONVERTTIME (0x28)
/*******************************************************************************
 * Variables
 ******************************************************************************/
/* ADC result buffer*/
uint16_t adcAResults[RESULTS_BUFFER_SIZE];
uint16_t resultsIndex;

/*******************************************************************************
 * Codes
 ******************************************************************************/
void main(void)
{
    BOARD_init();

    /* ASSIGN  ADC to CPU2 */
#if defined(BOARD_CONFIG_CPU2)
    BOARD_adcAssign2CPU2(EXAMPLE_ADC_CPU2);
#endif
    /* Enable the clock for the ADC peripheral  */
    BOARD_adcClockEnable(EXAMPLE_ADC_MODULE);

    /* Configure the ADC and power it up  */
    configureADC(EXAMPLE_ADC_MODULE); // Configure the ADC module

    /* Setup the ADC for continuous conversions on channel 2  */
    setupADCContinuous(EXAMPLE_ADC_MODULE, kADC_CH_ADCIN2);

    /* Initialize results buffer  */ 
    for(resultsIndex = 0; resultsIndex < RESULTS_BUFFER_SIZE; resultsIndex++)  
    {  
        adcAResults[resultsIndex] = 0;
    }  
     /* Reset the index for the results buffer  */ 
    resultsIndex = 0;

    /* Take conversions indefinitely in loop  */
    do
    {
        /* Enable ADC interrupts  */
        ADC_enableInterrupt(EXAMPLE_ADC_MODULE, kADC_INT_NUMBER1);
        ADC_enableInterrupt(EXAMPLE_ADC_MODULE, kADC_INT_NUMBER2);
        ADC_enableInterrupt(EXAMPLE_ADC_MODULE, kADC_INT_NUMBER3);
        ADC_enableInterrupt(EXAMPLE_ADC_MODULE, kADC_INT_NUMBER4);

        /* Clear all interrupt flags (INT1-4)  */
        EXAMPLE_ADC_MODULE->ADCSOCOVFCLR1 = 0x000F;

        /* Initialize results index  */ 
        resultsIndex = 0;

        /* Software force start SOC0 to SOC7  */
        EXAMPLE_ADC_MODULE->ADCSOCFRC1 = 0x00FF;

        /* Keep taking samples until the results buffer is full
         * Iterate until the results buffer is full  */
        while (resultsIndex < RESULTS_BUFFER_SIZE)
        {
            /* Block until the first set of 8 conversions completes  */
            while (false == ADC_getInterruptStatus(EXAMPLE_ADC_MODULE, kADC_INT_NUMBER3))
                ;

            /* Clear the interrupt flag to indicate that the conversions have been processed */
            ADC_clearInterruptStatus(EXAMPLE_ADC_MODULE, kADC_INT_NUMBER3);

            /* Retrieve and store the results of the first 8 conversions
             * Note: While these results are being saved, the second set of 8 conversions has
             * already been initiated by EOC6->ADCIN1 and is actively converting */
            adcAResults[resultsIndex++] = ADC_readResult(EXAMPLE_ADC_RESULTB, kADC_SOC_NUMBER0);
            adcAResults[resultsIndex++] = ADC_readResult(EXAMPLE_ADC_RESULTB, kADC_SOC_NUMBER1);
            adcAResults[resultsIndex++] = ADC_readResult(EXAMPLE_ADC_RESULTB, kADC_SOC_NUMBER2);
            adcAResults[resultsIndex++] = ADC_readResult(EXAMPLE_ADC_RESULTB, kADC_SOC_NUMBER3);
            adcAResults[resultsIndex++] = ADC_readResult(EXAMPLE_ADC_RESULTB, kADC_SOC_NUMBER4);
            adcAResults[resultsIndex++] = ADC_readResult(EXAMPLE_ADC_RESULTB, kADC_SOC_NUMBER5);
            adcAResults[resultsIndex++] = ADC_readResult(EXAMPLE_ADC_RESULTB, kADC_SOC_NUMBER6);
            adcAResults[resultsIndex++] = ADC_readResult(EXAMPLE_ADC_RESULTB, kADC_SOC_NUMBER7);

            /* Wait for the second set of 8 conversions to complete */
            while (false == ADC_getInterruptStatus(EXAMPLE_ADC_MODULE, kADC_INT_NUMBER4))
                ;

            /* Clear the interrupt flag */
            ADC_clearInterruptStatus(EXAMPLE_ADC_MODULE, kADC_INT_NUMBER4);

            /* Save results for second 8 conversions
             * Note that during this time, the first 8 conversions have
             * already been triggered by EOC14->ADCIN2 and will be actively
             * converting while second 8 results are being saved
             */
            adcAResults[resultsIndex++] = ADC_readResult(EXAMPLE_ADC_RESULTB, kADC_SOC_NUMBER8);
            adcAResults[resultsIndex++] = ADC_readResult(EXAMPLE_ADC_RESULTB, kADC_SOC_NUMBER9);
            adcAResults[resultsIndex++] = ADC_readResult(EXAMPLE_ADC_RESULTB, kADC_SOC_NUMBER10);
            adcAResults[resultsIndex++] = ADC_readResult(EXAMPLE_ADC_RESULTB, kADC_SOC_NUMBER11);
            adcAResults[resultsIndex++] = ADC_readResult(EXAMPLE_ADC_RESULTB, kADC_SOC_NUMBER12);
            adcAResults[resultsIndex++] = ADC_readResult(EXAMPLE_ADC_RESULTB, kADC_SOC_NUMBER13);
            adcAResults[resultsIndex++] = ADC_readResult(EXAMPLE_ADC_RESULTB, kADC_SOC_NUMBER14);
            adcAResults[resultsIndex++] = ADC_readResult(EXAMPLE_ADC_RESULTB, kADC_SOC_NUMBER15);
        }

        /* Disable all ADCINT flags to stop sampling */
        ADC_disableInterrupt(EXAMPLE_ADC_MODULE, kADC_INT_NUMBER1);
        ADC_disableInterrupt(EXAMPLE_ADC_MODULE, kADC_INT_NUMBER2);
        ADC_disableInterrupt(EXAMPLE_ADC_MODULE, kADC_INT_NUMBER3);
        ADC_disableInterrupt(EXAMPLE_ADC_MODULE, kADC_INT_NUMBER4);

        /* At this point, adcAResults[] contains a sequence of conversions
         * from the selected channel */
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
    ADC_setMode(adcBase, EX_ADC_RESOLUTION, kADC_MODE_SINGLE_ENDED);

    /* Set pulse positions to late */
    ADC_setInterruptPulseMode(adcBase, kADC_PULSE_END_OF_CONV);

    /* Power up the ADCs and then delay for 1 ms */
    ADC_enableConverter(adcBase);

    /* Delay for 1ms to allow ADC time to power up */
    DELAY(1000);
}

/*!
 * \brief Sets up the ADC for continuous conversion on a specified channel.  
 *  
 * \details This function configures the ADC for continuous conversion on a given channel.  
 * It determines the acquisition window (in SYSCLKS) based on the ADC resolution.  
 * It then configures the SOC (Sample-and-Hold) channel number and acquisition window.  
 *  
 * \param[in] adcBase A pointer to the ADC base address.  
 * \param[in] channel The ADC channel number to configure for continuous conversion.  
 *  
 */
void setupADCContinuous(ADC_Type *adcBase, uint32_t channel)
{
    /* NOTE: A longer sampling window will be required if the ADC driving
     * source is less than ideal (an ideal source would be a high bandwidth
     * op-amp with a small series resistance).
     * NOTE: A slightly longer S+H window is used with 12-bit resolution to
     * ensure the data collection loop can keep up with the ADC */

    /* Configure SOCs channel no. & acquisition window. */
    ADC_setupSOC(adcBase, kADC_SOC_NUMBER0, kADC_TRIGGER_SW_ONLY, (ADC_Channel_t)channel, EXAMPLE_ADC_ACQPS);
    ADC_setupSOC(adcBase, kADC_SOC_NUMBER1, kADC_TRIGGER_SW_ONLY, (ADC_Channel_t)channel, EXAMPLE_ADC_ACQPS);
    ADC_setupSOC(adcBase, kADC_SOC_NUMBER2, kADC_TRIGGER_SW_ONLY, (ADC_Channel_t)channel, EXAMPLE_ADC_ACQPS);
    ADC_setupSOC(adcBase, kADC_SOC_NUMBER3, kADC_TRIGGER_SW_ONLY, (ADC_Channel_t)channel, EXAMPLE_ADC_ACQPS);
    ADC_setupSOC(adcBase, kADC_SOC_NUMBER4, kADC_TRIGGER_SW_ONLY, (ADC_Channel_t)channel, EXAMPLE_ADC_ACQPS);
    ADC_setupSOC(adcBase, kADC_SOC_NUMBER5, kADC_TRIGGER_SW_ONLY, (ADC_Channel_t)channel, EXAMPLE_ADC_ACQPS);
    ADC_setupSOC(adcBase, kADC_SOC_NUMBER6, kADC_TRIGGER_SW_ONLY, (ADC_Channel_t)channel, EXAMPLE_ADC_ACQPS);
    ADC_setupSOC(adcBase, kADC_SOC_NUMBER7, kADC_TRIGGER_SW_ONLY, (ADC_Channel_t)channel, EXAMPLE_ADC_ACQPS);
    ADC_setupSOC(adcBase, kADC_SOC_NUMBER8, kADC_TRIGGER_SW_ONLY, (ADC_Channel_t)channel, EXAMPLE_ADC_ACQPS);
    ADC_setupSOC(adcBase, kADC_SOC_NUMBER9, kADC_TRIGGER_SW_ONLY, (ADC_Channel_t)channel, EXAMPLE_ADC_ACQPS);
    ADC_setupSOC(adcBase, kADC_SOC_NUMBER10, kADC_TRIGGER_SW_ONLY, (ADC_Channel_t)channel, EXAMPLE_ADC_ACQPS);
    ADC_setupSOC(adcBase, kADC_SOC_NUMBER11, kADC_TRIGGER_SW_ONLY, (ADC_Channel_t)channel, EXAMPLE_ADC_ACQPS);
    ADC_setupSOC(adcBase, kADC_SOC_NUMBER12, kADC_TRIGGER_SW_ONLY, (ADC_Channel_t)channel, EXAMPLE_ADC_ACQPS);
    ADC_setupSOC(adcBase, kADC_SOC_NUMBER13, kADC_TRIGGER_SW_ONLY, (ADC_Channel_t)channel, EXAMPLE_ADC_ACQPS);
    ADC_setupSOC(adcBase, kADC_SOC_NUMBER14, kADC_TRIGGER_SW_ONLY, (ADC_Channel_t)channel, EXAMPLE_ADC_ACQPS);
    ADC_setupSOC(adcBase, kADC_SOC_NUMBER15, kADC_TRIGGER_SW_ONLY, (ADC_Channel_t)channel, EXAMPLE_ADC_ACQPS);

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
    /* Setup interrupt trigger for SOCs. ADCINT2 will trigger first 8 SOCs.
     * ADCINT1 will trigger next 8 SOCs */

    /* ADCINT2 trigger for SOC0-SOC7 */
    ADC_setInterruptSOCTrigger(adcBase, kADC_SOC_NUMBER0,
                               kADC_INT_SOC_TRIGGER_ADCINT2);
    ADC_setInterruptSOCTrigger(adcBase, kADC_SOC_NUMBER1,
                               kADC_INT_SOC_TRIGGER_ADCINT2);
    ADC_setInterruptSOCTrigger(adcBase, kADC_SOC_NUMBER2,
                               kADC_INT_SOC_TRIGGER_ADCINT2);
    ADC_setInterruptSOCTrigger(adcBase, kADC_SOC_NUMBER3,
                               kADC_INT_SOC_TRIGGER_ADCINT2);
    ADC_setInterruptSOCTrigger(adcBase, kADC_SOC_NUMBER4,
                               kADC_INT_SOC_TRIGGER_ADCINT2);
    ADC_setInterruptSOCTrigger(adcBase, kADC_SOC_NUMBER5,
                               kADC_INT_SOC_TRIGGER_ADCINT2);
    ADC_setInterruptSOCTrigger(adcBase, kADC_SOC_NUMBER6,
                               kADC_INT_SOC_TRIGGER_ADCINT2);
    ADC_setInterruptSOCTrigger(adcBase, kADC_SOC_NUMBER7,
                               kADC_INT_SOC_TRIGGER_ADCINT2);

    /* ADCINT1 trigger for SOC8-SOC15 */
    ADC_setInterruptSOCTrigger(adcBase, kADC_SOC_NUMBER8,
                               kADC_INT_SOC_TRIGGER_ADCINT1);
    ADC_setInterruptSOCTrigger(adcBase, kADC_SOC_NUMBER9,
                               kADC_INT_SOC_TRIGGER_ADCINT1);
    ADC_setInterruptSOCTrigger(adcBase, kADC_SOC_NUMBER10,
                               kADC_INT_SOC_TRIGGER_ADCINT1);
    ADC_setInterruptSOCTrigger(adcBase, kADC_SOC_NUMBER11,
                               kADC_INT_SOC_TRIGGER_ADCINT1);
    ADC_setInterruptSOCTrigger(adcBase, kADC_SOC_NUMBER12,
                               kADC_INT_SOC_TRIGGER_ADCINT1);
    ADC_setInterruptSOCTrigger(adcBase, kADC_SOC_NUMBER13,
                               kADC_INT_SOC_TRIGGER_ADCINT1);
    ADC_setInterruptSOCTrigger(adcBase, kADC_SOC_NUMBER14,
                               kADC_INT_SOC_TRIGGER_ADCINT1);
    ADC_setInterruptSOCTrigger(adcBase, kADC_SOC_NUMBER15,
                               kADC_INT_SOC_TRIGGER_ADCINT1);

    /* Disable Interrupt flags */
    ADC_disableInterrupt(adcBase, kADC_INT_NUMBER1);
    ADC_disableInterrupt(adcBase, kADC_INT_NUMBER2);
    ADC_disableInterrupt(adcBase, kADC_INT_NUMBER3);
    ADC_disableInterrupt(adcBase, kADC_INT_NUMBER4);

    /* Enable continuous mode */
    ADC_enableContinuousMode(adcBase, kADC_INT_NUMBER1);
    ADC_enableContinuousMode(adcBase, kADC_INT_NUMBER2);
    ADC_enableContinuousMode(adcBase, kADC_INT_NUMBER3);
    ADC_enableContinuousMode(adcBase, kADC_INT_NUMBER4);

    /* Configure interrupt triggers */
    ADC_setInterruptSource(adcBase, kADC_INT_NUMBER1, kADC_SOC_NUMBER6);
    ADC_setInterruptSource(adcBase, kADC_INT_NUMBER2, kADC_SOC_NUMBER14);
    ADC_setInterruptSource(adcBase, kADC_INT_NUMBER3, kADC_SOC_NUMBER7);
    ADC_setInterruptSource(adcBase, kADC_INT_NUMBER4, kADC_SOC_NUMBER15);
}
