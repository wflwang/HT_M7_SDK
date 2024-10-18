/*
 * Copyright 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*!
 * \file rfft_adc_f32.c
 * \brief Example of SDK debug console
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "arm_math.h"
#include "board.h"
#include "hte_adc.h"
#include "hte_epwm.h"
#include "hte_sysctrl.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! \brief FFT size in this example, must be power of 2 */
#define EXAMPLE_FFT_SIZE 256

/*! \brief ADC used by CPU1 in this example */
#define EXAMPLE_ADC_CPU1 (ADCA)
/*! \brief ADC result used by CPU1 in this example */
#define EXAMPLE_ADC_RESULT_CPU1 (ADC_RESULTA)
/*! \brief ADC IRQ index used by CPU1 in this example */
#define EXAMPLE_ADC_IRQ_CPU1 (ADCA_INT1_IRQn)
/*! \brief ADC Interrupt service handler used by CPU1 in this example */
#define EXAMPLE_ADC_ISR_CPU1 (ADCA_INT1_Handler)
/*! \brief ADC SOC trigger source used by CPU1 in this example */
#define EXAMPLE_ADC_TRIGGER_CPU1 (kADC_TRIGGER_EPWM1_SOCA)
/*! \brief EPWM used by CPU1 to trigger ADC sampling in this example */
#define EXAMPLE_EPWM_SAMPLE_CPU1 (EPWM1)
/*! \brief EPWM used by CPU1 to output a square wave to be sampled by ADC in this example */
#define EXAMPLE_EPWM_SQUARE_CPU1 (EPWM2)
/*! \brief ADC used by CPU2 in this example */
#define EXAMPLE_ADC_CPU2 (ADCB)
/*! \brief ADC result used by CPU2 in this example */
#define EXAMPLE_ADC_RESULT_CPU2 (ADC_RESULTB)
/*! \brief ADC IRQ index used by CPU2 in this example */
#define EXAMPLE_ADC_IRQ_CPU2 (ADCB_INT1_IRQn)
/*! \brief ADC Interrupt service handler used by CPU2 in this example */
#define EXAMPLE_ADC_ISR_CPU2 (ADCB_INT1_Handler)
/*! \brief ADC SOC trigger source used by CPU2 in this example */
#define EXAMPLE_ADC_TRIGGER_CPU2 (kADC_TRIGGER_EPWM3_SOCA)
/*! \brief EPWM used by CPU2 to trigger ADC sampling in this example */
#define EXAMPLE_EPWM_SAMPLE_CPU2 (EPWM3)
/*! \brief EPWM used by CPU2 to output a square wave to be sampled by ADC in this example */
#define EXAMPLE_EPWM_SQUARE_CPU2 (EPWM4)

/*! \brief EPWM output wave frequency to be sampled by ADC */
#define EXAMPLE_EPWM_SQUARE_FREQ (1000U)
/*! \brief EPWM SOC event frequency used as ADC sampling frequency */
#define EXAMPLE_EPWM_SAMPLE_FREQ (EXAMPLE_EPWM_SQUARE_FREQ * 10)

/*! \brief RFFT initialization function used in this example */
#define _EXAMPLE_RFFT_INIT_F32(s, len) arm_rfft_fast_init_##len##_f32(s)
/*! \brief RFFT initialization function used in this example */
#define EXAMPLE_RFFT_INIT_F32(s, len) _EXAMPLE_RFFT_INIT_F32(s, len)

#if defined(BOARD_USE_CPU1)
/*! \brief ADC used in this example */
#define EXAMPLE_ADC (EXAMPLE_ADC_CPU1)
/*! \brief ADC result in this example */
#define EXAMPLE_ADC_RESULT (EXAMPLE_ADC_RESULT_CPU1)
/*! \brief ADC IRQ index used in this example */
#define EXAMPLE_ADC_IRQ (EXAMPLE_ADC_IRQ_CPU1)
/*! \brief ADC Interrupt service handler used in this example */
#define EXAMPLE_ADC_ISR (EXAMPLE_ADC_ISR_CPU1)
/*! \brief ADC SOC trigger source used in this example */
#define EXAMPLE_ADC_TRIGGER (EXAMPLE_ADC_TRIGGER_CPU1)
/*! \brief EPWM used to trigger ADC sampling in this example */
#define EXAMPLE_EPWM_SAMPLE (EXAMPLE_EPWM_SAMPLE_CPU1)
/*! \brief EPWM used to output a square wave to be sampled by ADC in this example */
#define EXAMPLE_EPWM_SQUARE (EXAMPLE_EPWM_SQUARE_CPU1)

#elif defined(BOARD_USE_CPU2)
/*! \brief ADC used in this example */
#define EXAMPLE_ADC         (EXAMPLE_ADC_CPU2)
/*! \brief ADC result in this example */
#define EXAMPLE_ADC_RESULT  (EXAMPLE_ADC_RESULT_CPU2)
/*! \brief ADC IRQ index used in this example */
#define EXAMPLE_ADC_IRQ     (EXAMPLE_ADC_IRQ_CPU2)
/*! \brief ADC Interrupt service handler used in this example */
#define EXAMPLE_ADC_ISR     (EXAMPLE_ADC_ISR_CPU2)
/*! \brief ADC SOC trigger source used in this example */
#define EXAMPLE_ADC_TRIGGER (EXAMPLE_ADC_TRIGGER_CPU2)
/*! \brief EPWM used to trigger ADC sampling in this example */
#define EXAMPLE_EPWM_SAMPLE (EXAMPLE_EPWM_SAMPLE_CPU2)
/*! \brief EPWM used to output a square wave to be sampled by ADC in this example */
#define EXAMPLE_EPWM_SQUARE (EXAMPLE_EPWM_SQUARE_CPU2)
#endif

/*! \brief EPWM frequency in this example */
#define EXAMPLE_EPWM_CLK BOARD_getSysclk()
/*! \brief EPWM time base clock divider */
#define EXAMPLE_EPWM_CLKDIV (EPWM_CLOCK_DIVIDER_4)
/*! \brief EPWM high speed time base clock divider */
#define EXAMPLE_EPWM_HSPCLKDIV (EPWM_HSCLOCK_DIVIDER_8)
/*! \brief EPWM square wave period */
#define EXAMPLE_EPWM_SQUARE_PERIOD \
    (EXAMPLE_EPWM_CLK / ((1 << EXAMPLE_EPWM_CLKDIV) * (1 << EXAMPLE_EPWM_HSPCLKDIV) * (EXAMPLE_EPWM_SQUARE_FREQ)))
/*!
 * \brief EPWM sample period, which is also called as EPWM SOC event period
 *
 * \note The SOC event is triggered when the EPWM timebase counter hits zero. So Freq(sample) = Freq(ewpm) * 2. The
 * period need to be multiplied by 2
 */
#define EXAMPLE_EPWM_SAMPLE_PERIOD                                                                                    \
    ((EXAMPLE_EPWM_CLK / ((1 << EXAMPLE_EPWM_CLKDIV) * (1 << EXAMPLE_EPWM_HSPCLKDIV) * (EXAMPLE_EPWM_SAMPLE_FREQ))) * \
     2U)

/*!
 * \brief The reference index at which fundamental frequency occurs
 *
 * \note The index can be calculated by the following formula:
 *     Index = Length(rfft) * Freq(wave) / Freq(sample)
 * To handle the rounding, the formula shall be:
 *     Index = (Length(rfft) * Freq(wave) + (Freq(sample) / 2) / Freq(sample)
 */
#define EXAMPLE_REF_MAX_VALUE_INDEX \
    (((EXAMPLE_FFT_SIZE * EXAMPLE_EPWM_SQUARE_FREQ) + (EXAMPLE_EPWM_SAMPLE_FREQ / 2U)) / EXAMPLE_EPWM_SAMPLE_FREQ)

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*! \brief Initialize ADC to sample a signal */
void initAdc(ADC_Type *base);
/*! \brief Initialize EPWM as sample frequency to trigger ADC sampling */
void initEpwmAsSampleClk(EPWM_REGS_Type *base);
/*! \brief Initialize EPWM to output a square wave to be sampled by ADC */
void initEpwmAsSquareWave(EPWM_REGS_Type *base);
/*! \brief Set ADC Gain trim value */
void ADC_setADCGain(ADC_Type *base, uint32_t gain);
/*! \brief Set ADC offset trim value */
void ADC_setADCOffset(ADC_Type *base, uint32_t offtrim);
/*! \brief Set ADC bit weight trim values */
void ADC_setBitWeight(ADC_Type *base, uint16_t *bit_weight_array);
/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! \brief Buffer to store the samples */
float32_t sampleInput[EXAMPLE_FFT_SIZE * 2];
/*! \brief Buffer to store the RFFT result */
float32_t sampleOutput[EXAMPLE_FFT_SIZE];
/*! \brief Buffer to store the RFFT result magnitude */
float32_t sampleOutputMag[EXAMPLE_FFT_SIZE / 2];
/*! \brief Index of the sample input buffer. */
volatile uint32_t sampleIndex = 0U;
/*! \brief Flag to show if the ADC has finished sampling */
volatile bool sampleCompleted = false;

/*! \brief Instance variable for the Single Precision Floating-point RFFT/RIFFT function */
arm_rfft_fast_instance_f32 rfftFastInstF32;

/*! \brief The calculated index at which max magnitude occurs */
uint32_t maxValueIndex = 0U;
/*! \brief The calculated max magnitude */
float32_t maxValue = 0.0f;

/*! \brief default bit weight values */
const uint16_t bitWeightDefault[24] = { 22528, 16384, 8192, 8192, 4096, 2048, 1536, 1024, 512, 256, 256, 256,
                                        0,     128,   128,  64,   32,   32,   16,   10,   6,   4,   2,   1 };
/*! \brief default bit weight width */
const uint16_t bitWeightWidth[12] = { 15, 15, 14, 14, 13, 12, 11, 11, 10, 9, 9, 9 };


/*******************************************************************************
 * Codes
 ******************************************************************************/
int main(void)
{
    uint8_t ch = 0;
    arm_status rfftStatus;

    /* Board initialization */
    BOARD_init();

    /* Pinmux configuration and Pad configuration */
#if defined(BOARD_USE_CPU1)
    BOARD_epwmPinConfig(EXAMPLE_EPWM_SQUARE_CPU1);
#endif
#if defined(BOARD_CONFIG_CPU2)
    BOARD_epwmPinConfig(EXAMPLE_EPWM_SQUARE_CPU2);

    BOARD_adcAssign2CPU2(EXAMPLE_ADC_CPU2);
    BOARD_epwmAssign2CPU2(EXAMPLE_EPWM_SQUARE_CPU2);
    BOARD_epwmAssign2CPU2(EXAMPLE_EPWM_SAMPLE_CPU2);
#endif

    /* Peripheral clock configuration */
    BOARD_adcClockEnable(EXAMPLE_ADC);
    BOARD_epwmClockEnable(EXAMPLE_EPWM_SQUARE);
    BOARD_epwmClockEnable(EXAMPLE_EPWM_SAMPLE);

    /* Setup ADC */
    initAdc(EXAMPLE_ADC);

    /* Disable sync and clock to EPWM */
    SYSCTRL_disablePeripheral(kSYSCTL_PERIPH_CLK_TBCLKSYNC);
    /* Setup EPWM which is used as sampling clock */
    initEpwmAsSampleClk(EXAMPLE_EPWM_SAMPLE);
    /* Setup EPWM which is used as the square wave to be sampled */
    initEpwmAsSquareWave(EXAMPLE_EPWM_SQUARE);
    /* Enable sync and clock to EPWM after the configuration */
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_TBCLKSYNC);

    /* Print the example banner */
    PRINTF("\r\n");
    PRINTF("RFFT ADC Float32 Example:\r\n");
    PRINTF("\tPlease connect EPWM output to ADC Input, and then press any key to start the RFFT\r\n");
    PRINTF("Please input:");

    while (1)
    {
        ch = GETCHAR();
        /* Echo the char back */
        PUTCHAR(ch);

        /* wait the sample completed */
        while (!sampleCompleted)
        {
            ;
        }

        /* Initialize instance structure for the floating-point RFFT/RIFFT function */
        rfftStatus = EXAMPLE_RFFT_INIT_F32(&rfftFastInstF32, EXAMPLE_FFT_SIZE);
        assert(rfftStatus == ARM_MATH_SUCCESS);

        /* Perform RFFT function */
        arm_rfft_fast_f32(&rfftFastInstF32, sampleInput, sampleOutput, 0U);

        /* Calculating the magnitude */
        arm_cmplx_mag_f32(sampleOutput, sampleOutputMag, EXAMPLE_FFT_SIZE / 2U);

        /* DC component is at index 0, calculate maxValue from index 1 to get the index of the fundamental
         * frequency */
        arm_max_f32(&sampleOutputMag[1U], EXAMPLE_FFT_SIZE / 2U - 1U, &maxValue, &maxValueIndex);
        /* Correct the index due to index 0 is not calculated */
        maxValueIndex++;
        /* Check if the fundamental frequency is at the expected index */
        rfftStatus = (maxValueIndex != EXAMPLE_REF_MAX_VALUE_INDEX) ? ARM_MATH_TEST_FAILURE : ARM_MATH_SUCCESS;
        if (rfftStatus != ARM_MATH_SUCCESS)
        {
            PRINTF("\r\n");
            PRINTF("\tRFFT is failed: fundamental frequency is detected at index %lu which should be at index %u, \r\n",
                   maxValueIndex, EXAMPLE_REF_MAX_VALUE_INDEX);
        }
        else
        {
            PRINTF("\r\n");
            PRINTF("\tRFFT is completed successfully: fundamental frequency is detected at index %lu\r\n",
                   maxValueIndex);
        }

        /* Print the banner */
        PRINTF("\tPress any key to restart the RFFT example\r\n");
        PRINTF("Please input:");

        sampleCompleted = false;
    }
}

void initAdc(ADC_Type *base)
{
    /* Write the gain data */
    ADC_setADCGain(base, 0x10000U);
    /* Write the offtrim data */
    ADC_setADCOffset(base, 0x0U);
    /* Write the bit weight */
    ADC_setBitWeight(base, NULL);

    /* Configure the ADC working mode */
    ADC_setMode(base, kADC_RESOLUTION_12BIT, kADC_MODE_SINGLE_ENDED);

    /* Set interrupt pulse positions */
    ADC_setInterruptPulseMode(base, kADC_PULSE_END_OF_CONV);

    /* Power up the ADC */
    ADC_enableConverter(base);
    /* Delay 1ms to ensure the ADC is power up */
    DELAY(1000);

    /* Configure ADC SOC0 to be triggered by EPWM Sample SOCA */
    ADC_setupSOC(base, kADC_SOC_NUMBER0, EXAMPLE_ADC_TRIGGER, kADC_CH_ADCIN0, 100U);
    /* SOC0 will sample on each trigger regardless of the interrupt flag */
    ADC_enableContinuousMode(base, kADC_INT_NUMBER1);

    /* Set SOC0 to trigger the interrupt 1 flag */
    ADC_setInterruptSource(base, kADC_INT_NUMBER1, kADC_SOC_NUMBER0);
    /* Enable interrupt and make sure the flag is cleared */
    ADC_enableInterrupt(base, kADC_INT_NUMBER1);
    ADC_clearInterruptStatus(base, kADC_INT_NUMBER1);
    NVIC_EnableIRQ(EXAMPLE_ADC_IRQ);
}

void initEpwmAsSampleClk(EPWM_REGS_Type *base)
{
    /* Set EPWM time base clock */
    EPWM_setClockPrescaler(base, EXAMPLE_EPWM_CLKDIV, EXAMPLE_EPWM_HSPCLKDIV);

    /* EPWM run in count up mode */
    EPWM_setTimeBaseCounterMode(base, EPWM_COUNTER_MODE_UP);
    /* Set EPWM period */
    EPWM_setTimeBasePeriod(base, EXAMPLE_EPWM_SAMPLE_PERIOD);
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

void initEpwmAsSquareWave(EPWM_REGS_Type *base)
{
    /* Set EPWM time base clock */
    EPWM_setClockPrescaler(base, EXAMPLE_EPWM_CLKDIV, EXAMPLE_EPWM_HSPCLKDIV);

    /* EPWM run in count up/down mode */
    EPWM_setTimeBaseCounterMode(base, EPWM_COUNTER_MODE_UP_DOWN);
    /* Set EPWM period */
    EPWM_setTimeBasePeriod(base, EXAMPLE_EPWM_SQUARE_PERIOD);
    /* Set EPWM initial counter to zero */
    EPWM_setTimeBaseCounter(base, 0U);
    /* Set EPWM CMPA value for a 50% duty cycle */
    EPWM_setCounterCompareValue(base, EPWM_COUNTER_COMPARE_A, EXAMPLE_EPWM_SQUARE_PERIOD / 2U);

    /* On compare A, when counting up, pull the EPWM A output high */
    EPWM_setActionQualifierAction(base, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    /* On compare A, when counting down, pull the EPWM A output low */
    EPWM_setActionQualifierAction(base, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
}

void ADC_setADCGain(ADC_Type *base, uint32_t gain)
{
    assert(ADC_isBaseValid(base));
    assert((gain > 0 * 65536) && (gain < 2 * 65536));

    base->ADCGAINERR = ADC_ADCGAINERR_GAINERR_Set(gain);
}

void ADC_setADCOffset(ADC_Type *base, uint32_t offtrim)
{
    assert(ADC_isBaseValid(base));

    base->ADCOFFTRIM = ADC_ADCOFFTRIM_OFFTRIM_Set(offtrim);
}

void ADC_setBitWeight(ADC_Type *base, uint16_t *bit_weight_array)
{
    uint32_t reg_data       = 0;
    uint32_t bit_offset     = 0;
    uint32_t trim_data[6]   = { 0 };
    uint32_t i              = 0;
    uint32_t weight         = 0;
    uint32_t remaining_bits = 0;
    uint32_t num            = 0;

    for (num = 0; num < 12; num++)
    {
        weight = (bit_weight_array == NULL) ? bitWeightDefault[num] : bit_weight_array[num];

        if (bit_offset + bitWeightWidth[num] <= 32)
        {
            reg_data     |= (weight << bit_offset);
            bit_offset   += bitWeightWidth[num];
            trim_data[i]  = reg_data;
        }
        else
        {
            remaining_bits  = 32 - bit_offset;
            reg_data       |= (weight & ((1 << remaining_bits) - 1)) << bit_offset;
            trim_data[i++]  = reg_data;
            reg_data        = weight >> remaining_bits;
            bit_offset      = bitWeightWidth[num] - remaining_bits;
        }
    }

    base->ADCINLTRIM1 = ADC_ADCINLTRIM1_INLTRIM31TO0_Set(trim_data[0]);
    base->ADCINLTRIM2 = ADC_ADCINLTRIM2_INLTRIM63TO32_Set(trim_data[1]);
    base->ADCINLTRIM3 = ADC_ADCINLTRIM3_INLTRIM95TO64_Set(trim_data[2]);
    base->ADCINLTRIM4 = ADC_ADCINLTRIM4_INLTRIM127TO96_Set(trim_data[3]);
    base->ADCINLTRIM5 = ADC_ADCINLTRIM5_INLTRIM159TO128_Set(trim_data[4]);
    base->ADCINLTRIM6 = ADC_ADCINLTRIM6_INLTRIM191TO160_Set(trim_data[5]);
}

void EXAMPLE_ADC_ISR(void)
{
    if (!sampleCompleted)
    {
        sampleInput[sampleIndex++] = (float32_t)ADC_readResult(EXAMPLE_ADC_RESULT, kADC_SOC_NUMBER0);

        if (sampleIndex == EXAMPLE_FFT_SIZE)
        {
            sampleIndex     = 0U;
            sampleCompleted = true;
        }
    }

    ADC_clearInterruptStatus(EXAMPLE_ADC, kADC_INT_NUMBER1);
}
