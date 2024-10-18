/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_adc.h
 * \brief SDK ADC driver header file
 * \version 1.0.0
 */

#ifndef HTE_ADC_H
#define HTE_ADC_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_common.h"

/*!
 * \addtogroup DRV_HTE_ADC ADC Driver
 *
 * \brief SDK ADC driver
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! \brief ADC read register */
#ifndef REG32_RD
#define REG32_RD(addr) (*((volatile unsigned int *)(addr)))
#endif

/*! \brief ADC PPB Event style*/
#define ADC_EVT_TRIPHI              (0x0001U) /*!< Trip High Event */
#define ADC_EVT_TRIPLO              (0x0002U) /*!< Trip Low Event */
#define ADC_EVT_ZERO                (0x0004U) /*!< Zero Crossing Event */


/*! \brief ADC PPB count, threshould max min value */
#define ADC_PPB_REG_NUM_OFFSET(x) ((uint32_t)(x)*4U)
#define PPB_LIMIT_MIN             (-65536) /*!< PPB Min Value */
#define PPB_LIMIT_MAX             (65535)  /*!< PPB max Value */


/*! \brief ADC index */
typedef enum
{
    kADCA    = 0U, /*!< ADC Module A */
    kADCB    = 1U, /*!< ADC Module B */
    kADCC    = 2U, /*!< ADC Module C */
    kADCD    = 3U, /*!< ADC Module D */
    kADC_MAX = 4U, /*!< ADC Module MAX */
} ADC_Idx_t;

/*! \brief ADC function enable or disable */
typedef enum
{
    kADC_DISABLE = 0U, /*!< ADC Function disable */
    kADC_ENABLE  = 1U, /*!< ADC Function enable */
} ADC_En_t;

/*! \brief ADC interrupt channel */
typedef enum
{
    kADCA_INT1  = 0, /*!< ADCA INT1 source */
    kADCA_INT2  = 1, /*!< ADCA INT2 source */
    kADCA_INT3  = 2, /*!< ADCA INT3 source */
    kADCA_INT4  = 3, /*!< ADCA INT4 source */
    kADCB_INT1  = 4, /*!< ADCB INT1 source */
    kADCB_INT2  = 5, /*!< ADCB INT2 source */
    kADCB_INT3  = 6, /*!< ADCB INT3 source */
    kADCB_INT4  = 7, /*!< ADCB INT4 source */
    kADCC_INT1  = 8, /*!< ADCC INT1 source */
    kADCC_INT2  = 9, /*!< ADCC INT2 source */
    kADCC_INT3  = 10, /*!< ADCC INT3 source */
    kADCC_INT4  = 11, /*!< ADCC INT4 source */
    kADCD_INT1  = 12, /*!< ADCD INT1 source */
    kADCD_INT2  = 13, /*!< ADCD INT2 source */
    kADCD_INT3  = 14, /*!< ADCD INT3 source */
    kADCD_INT4  = 15, /*!< ADCD INT4 source */
    kADC_INTMAX = 16, /*!< ADCD INT MAX */
} ADCIntSrc_t;

/*! \brief ADC resolution mode*/
typedef enum
{
    kADC_RESOLUTION_12BIT = 0U, /*!< 12-bit conversion resolution */
    kADC_RESOLUTION_16BIT = 1U  /*!< 16-bit conversion resolution */
} ADC_Resolution_t;

/*! \brief ADC signal mode*/
typedef enum
{
    kADC_MODE_SINGLE_ENDED = 0U, /*!< Sample on single pin with VREFLO */
    kADC_MODE_DIFFERENTIAL = 1U, /*!< Sample on pair of pins */
} ADC_SignalMode_t;

/*! \brief that can be as the trigger parameter to specify the event
 * that will trigger a conversion to start.*/
typedef enum
{
    kADC_TRIGGER_SW_ONLY     = 0U,  /*!< Software only */
    kADC_TRIGGER_CPU1_TINT0  = 1U,  /*!< CPU1 Timer 0, TINT0 */
    kADC_TRIGGER_CPU1_TINT1  = 2U,  /*!< CPU1 Timer 1, TINT1 */
    kADC_TRIGGER_CPU1_TINT2  = 3U,  /*!< CPU1 Timer 2, TINT2 */
    kADC_TRIGGER_GPIO        = 4U,  /*!< GPIO, ADCEXTSOC */
    kADC_TRIGGER_EPWM1_SOCA  = 5U,  /*!< ePWM1, ADCSOCA */
    kADC_TRIGGER_EPWM1_SOCB  = 6U,  /*!< ePWM1, ADCSOCB */
    kADC_TRIGGER_EPWM2_SOCA  = 7U,  /*!< ePWM2, ADCSOCA */
    kADC_TRIGGER_EPWM2_SOCB  = 8U,  /*!< ePWM2, ADCSOCB */
    kADC_TRIGGER_EPWM3_SOCA  = 9U,  /*!< ePWM3, ADCSOCA */
    kADC_TRIGGER_EPWM3_SOCB  = 10U, /*!< ePWM3, ADCSOCB */
    kADC_TRIGGER_EPWM4_SOCA  = 11U, /*!< ePWM4, ADCSOCA */
    kADC_TRIGGER_EPWM4_SOCB  = 12U, /*!< ePWM4, ADCSOCB */
    kADC_TRIGGER_EPWM5_SOCA  = 13U, /*!< ePWM5, ADCSOCA */
    kADC_TRIGGER_EPWM5_SOCB  = 14U, /*!< ePWM5, ADCSOCB */
    kADC_TRIGGER_EPWM6_SOCA  = 15U, /*!< ePWM6, ADCSOCA */
    kADC_TRIGGER_EPWM6_SOCB  = 16U, /*!< ePWM6, ADCSOCB */
    kADC_TRIGGER_EPWM7_SOCA  = 17U, /*!< ePWM7, ADCSOCA */
    kADC_TRIGGER_EPWM7_SOCB  = 18U, /*!< ePWM7, ADCSOCB */
    kADC_TRIGGER_EPWM8_SOCA  = 19U, /*!< ePWM8, ADCSOCA */
    kADC_TRIGGER_EPWM8_SOCB  = 20U, /*!< ePWM8, ADCSOCB */
    kADC_TRIGGER_EPWM9_SOCA  = 21U, /*!< ePWM9, ADCSOCA */
    kADC_TRIGGER_EPWM9_SOCB  = 22U, /*!< ePWM9, ADCSOCB */
    kADC_TRIGGER_EPWM10_SOCA = 23U, /*!< ePWM10, ADCSOCA */
    kADC_TRIGGER_EPWM10_SOCB = 24U, /*!< ePWM10, ADCSOCB */
    kADC_TRIGGER_EPWM11_SOCA = 25U, /*!< ePWM11, ADCSOCA */
    kADC_TRIGGER_EPWM11_SOCB = 26U, /*!< ePWM11, ADCSOCB */
    kADC_TRIGGER_EPWM12_SOCA = 27U, /*!< ePWM12, ADCSOCA */
    kADC_TRIGGER_EPWM12_SOCB = 28U, /*!< ePWM12, ADCSOCB */
    kADC_TRIGGER_CPU2_TINT0  = 29U, /*!< CPU2 Timer 0, TINT0 */
    kADC_TRIGGER_CPU2_TINT1  = 30U, /*!< CPU2 Timer 1, TINT1 */
    kADC_TRIGGER_CPU2_TINT2  = 31U, /*!< CPU2 Timer 2, TINT2 */
} ADC_Trigger_t;

/*! \brief that can be passed to ADC_setupSOC() as the channel parameter.
 * This is the input pin on which the signal to be converted is located.
 */
typedef enum
{
    kADC_CH_ADCIN0          = 0U,  /*!< single-ended, ADCIN0 */
    kADC_CH_ADCIN1          = 1U,  /*!< single-ended, ADCIN1 */
    kADC_CH_ADCIN2          = 2U,  /*!< single-ended, ADCIN2 */
    kADC_CH_ADCIN3          = 3U,  /*!< single-ended, ADCIN3 */
    kADC_CH_ADCIN4          = 4U,  /*!< single-ended, ADCIN4 */
    kADC_CH_ADCIN5          = 5U,  /*!< single-ended, ADCIN5 */
    kADC_CH_ADCIN6          = 6U,  /*!< single-ended, ADCIN6 */
    kADC_CH_ADCIN7          = 7U,  /*!< single-ended, ADCIN7 */
    kADC_CH_ADCIN8          = 8U,  /*!< single-ended, ADCIN8 */
    kADC_CH_ADCIN9          = 9U,  /*!< single-ended, ADCIN9 */
    kADC_CH_ADCIN10         = 10U, /*!< single-ended, ADCIN10 */
    kADC_CH_ADCIN11         = 11U, /*!< single-ended, ADCIN11 */
    kADC_CH_ADCIN12         = 12U, /*!< single-ended, ADCIN12 */
    kADC_CH_ADCIN13         = 13U, /*!< single-ended, ADCIN13 */
    kADC_CH_ADCIN14         = 14U, /*!< single-ended, ADCIN14 */
    kADC_CH_ADCIN15         = 15U, /*!< single-ended, ADCIN15 */
    kADC_CH_ADCIN0_ADCIN1   = 0U,  /*!< differential, ADCIN0 and ADCIN1 */
    kADC_CH_ADCIN2_ADCIN3   = 2U,  /*!< differential, ADCIN2 and ADCIN3 */
    kADC_CH_ADCIN4_ADCIN5   = 4U,  /*!< differential, ADCIN4 and ADCIN5 */
    kADC_CH_ADCIN6_ADCIN7   = 6U,  /*!< differential, ADCIN6 and ADCIN7 */
    kADC_CH_ADCIN8_ADCIN9   = 8U,  /*!< differential, ADCIN8 and ADCIN9 */
    kADC_CH_ADCIN10_ADCIN11 = 10U, /*!< differential, ADCIN10 and ADCIN11 */
    kADC_CH_ADCIN12_ADCIN13 = 12U, /*!< differential, ADCIN12 and ADCIN13 */
    kADC_CH_ADCIN14_ADCIN15 = 14U  /*!< differential, ADCIN14 and ADCIN15 */
} ADC_Channel_t;

/*! \brief that can be passed to ADC_setInterruptPulseMode() as the
 * pulseMode parameter.
 */
typedef enum
{
    kADC_PULSE_END_OF_ACQ_WIN = 0U, /*!< Occurs at the end of the acquisition window */
    kADC_PULSE_END_OF_CONV    = 1U, /*!< Occurs at the end of the conversion */
} ADC_PulseMode_t;

/*! \brief that can be passed to ADC_enableInterrupt(), ADC_disableInterrupt(),
 * and ADC_getInterruptStatus() as the adcIntNum parameter.
 */
typedef enum
{
    kADC_INT_NUMBER1 = 0U, /*!< ADCINT1 Interrupt */
    kADC_INT_NUMBER2 = 1U, /*!< ADCINT2 Interrupt */
    kADC_INT_NUMBER3 = 2U, /*!< ADCINT3 Interrupt */
    kADC_INT_NUMBER4 = 3U, /*!< ADCINT4 Interrupt */
    kADC_INT_MAX     = 4U  /*!< ADCINT MAX */
} ADC_IntNumber_t;

/*! \brief that can be passed in as the ppbNumber parameter for several
 * functions.
 */
typedef enum
{
    kADC_PPB_NUMBER1 = 0U, /*!< Post-processing block 1 */
    kADC_PPB_NUMBER2 = 1U, /*!< Post-processing block 2 */
    kADC_PPB_NUMBER3 = 2U, /*!< Post-processing block 3 */
    kADC_PPB_NUMBER4 = 3U  /*!< Post-processing block 4 */
} ADC_PPBNumber_t;

/*! \brief that can be passed in as the socNumber parameter for several
 * functions. This value identifies the start-of-conversion (SOC) that a
 * function is configuring or accessing. Note that in some cases (for example,
 * ADC_setInterruptSource()) socNumber is used to refer to the
 * corresponding end-of-conversion (EOC).
 */
typedef enum
{
    kADC_SOC_NUMBER0  = 0U,  /*!< SOC/EOC number 0 */
    kADC_SOC_NUMBER1  = 1U,  /*!< SOC/EOC number 1 */
    kADC_SOC_NUMBER2  = 2U,  /*!< SOC/EOC number 2 */
    kADC_SOC_NUMBER3  = 3U,  /*!< SOC/EOC number 3 */
    kADC_SOC_NUMBER4  = 4U,  /*!< SOC/EOC number 4 */
    kADC_SOC_NUMBER5  = 5U,  /*!< SOC/EOC number 5 */
    kADC_SOC_NUMBER6  = 6U,  /*!< SOC/EOC number 6 */
    kADC_SOC_NUMBER7  = 7U,  /*!< SOC/EOC number 7 */
    kADC_SOC_NUMBER8  = 8U,  /*!< SOC/EOC number 8 */
    kADC_SOC_NUMBER9  = 9U,  /*!< SOC/EOC number 9 */
    kADC_SOC_NUMBER10 = 10U, /*!< SOC/EOC number 10 */
    kADC_SOC_NUMBER11 = 11U, /*!< SOC/EOC number 11 */
    kADC_SOC_NUMBER12 = 12U, /*!< SOC/EOC number 12 */
    kADC_SOC_NUMBER13 = 13U, /*!< SOC/EOC number 13 */
    kADC_SOC_NUMBER14 = 14U, /*!< SOC/EOC number 14 */
    kADC_SOC_NUMBER15 = 15U, /*!< SOC/EOC number 15 */
} ADC_SOCNumber_t;

/*! \brief that can be passed in as the trigger parameter for the
 * ADC_setInterruptSOCTrigger() function.
 */
typedef enum
{
    kADC_INT_SOC_TRIGGER_NONE    = 0U, /*!< No ADCINT will trigger the SOC */
    kADC_INT_SOC_TRIGGER_ADCINT1 = 1U, /*!< ADCINT1 will trigger the SOC */
    kADC_INT_SOC_TRIGGER_ADCINT2 = 2U  /*!< ADCINT2 will trigger the SOC */
} ADC_IntSOCTrigger_t;

/*! \brief that can be passed to ADC_setSOCPriority() as the priMode parameter.
 */
typedef enum
{
    kADC_PRI_ALL_ROUND_ROBIN  = 0U,  /*!< Round robin mode is used for all */
    kADC_PRI_SOC0_HIPRI       = 1U,  /*!< SOC 0 hi pri, others in round robin */
    kADC_PRI_THRU_SOC1_HIPRI  = 2U,  /*!< SOC 0-1 hi pri, others in round robin */
    kADC_PRI_THRU_SOC2_HIPRI  = 3U,  /*!< SOC 0-2 hi pri, others in round robin */
    kADC_PRI_THRU_SOC3_HIPRI  = 4U,  /*!< SOC 0-3 hi pri, others in round robin */
    kADC_PRI_THRU_SOC4_HIPRI  = 5U,  /*!< SOC 0-4 hi pri, others in round robin */
    kADC_PRI_THRU_SOC5_HIPRI  = 6U,  /*!< SOC 0-5 hi pri, others in round robin */
    kADC_PRI_THRU_SOC6_HIPRI  = 7U,  /*!< SOC 0-6 hi pri, others in round robin */
    kADC_PRI_THRU_SOC7_HIPRI  = 8U,  /*!< SOC 0-7 hi pri, others in round robin */
    kADC_PRI_THRU_SOC8_HIPRI  = 9U,  /*!< SOC 0-8 hi pri, others in round robin */
    kADC_PRI_THRU_SOC9_HIPRI  = 10U, /*!< SOC 0-9 hi pri, others in round robin */
    kADC_PRI_THRU_SOC10_HIPRI = 11U, /*!< SOC 0-10 hi pri, others in round robin */
    kADC_PRI_THRU_SOC11_HIPRI = 12U, /*!< SOC 0-11 hi pri, others in round robin */
    kADC_PRI_THRU_SOC12_HIPRI = 13U, /*!< SOC 0-12 hi pri, others in round robin */
    kADC_PRI_THRU_SOC13_HIPRI = 14U, /*!< SOC 0-13 hi pri, others in round robin */
    kADC_PRI_THRU_SOC14_HIPRI = 15U, /*!< SOC 0-14 hi pri, SOC15 in round robin */
    kADC_PRI_ALL_HIPRI        = 16U  /*!< All priorities based on SOC number */
} ADC_PriorityMode_t;

/*! \brief that can be passed to ADC_configOSDetectMode() as the modeVal parameter.
 */
typedef enum
{
    kADC_OSDETECT_MODE_DISABLED = 0x0U,            /*!< Open/Shorts detection cir-
                                                    * cuit(O/S DC) is disabled */
    kADC_OSDETECT_MODE_VSSA = 0x1U,                /*!< O/S DC is enabled at zero
                                                    * scale */
    kADC_OSDETECT_MODE_VDDA = 0x2U,                /*!< O/S DC is enabled at full
                                                    * scale */
    kADC_OSDETECT_MODE_5BY12_VDDA = 0x3U,          /*!< O/S DC is enabled at 5/12
                                                    * scale */
    kADC_OSDETECT_MODE_7BY12_VDDA = 0x4U,          /*!< O/S DC is enabled at 7/12
                                                    * scale */
    kADC_OSDETECT_MODE_5K_PULLDOWN_TO_VSSA = 0x5U, /*!< O/S DC is enabled at 5K
                                                    * pulldown to VSSA */
    kADC_OSDETECT_MODE_5K_PULLUP_TO_VDDA = 0x6U,   /*!< O/S DC is enabled at 5K
                                                    * pullup to VDDA */
    kADC_OSDETECT_MODE_7K_PULLDOWN_TO_VSSA = 0x7U  /*!< O/S DC is enabled at 7K
                                                    * pulldown to VSSA */
} ADC_OSDetectMode_t;

/*! \brief ADC Trim Value form Eflash */
typedef struct
{
    uint32_t gainerrSingle12bit; /*!< 12 bit single gainerr */
    uint32_t offsetSingle12bit;  /*!< 12 bit single offset */
    uint32_t gainerrSingle16bit; /*!< 16 bit single gainerr */
    uint32_t offsetSingle16bit;  /*!< 16 bit single offset */
    uint32_t gainerrDiff16bit;   /*!< 16 bit diff gainerr */
    uint32_t offsetDiff16bit;    /*!< 16 bit diff offset */
    uint32_t linearValue0;       /*!< linear value0 */
    uint32_t linearValue1;       /*!< linear value1 */
    uint32_t linearValue2;       /*!< linear value2 */
    uint32_t linearValue3;       /*!< linear value3 */
    uint32_t linearValue4;       /*!< linear value4 */
} ADC_EflashTrimValue_t;

/*! \brief index for ADC IRQ */
typedef enum
{
    kADC_EVT_IRQn = 0, /*!< ADC Event */
    kADC_INT1_IRQn,    /*!< ADC INT1 */
    kADC_INT2_IRQn,    /*!< ADC INT2 */
    kADC_INT3_IRQn,    /*!< ADC INT3 */
    kADC_INT4_IRQn,    /*!< ADC INT4 */
    kADC_IRQ_MAX_NUM   /*!< ADC IRQ Max */
} ADC_Irq_Idx_t;

/*! \brief type definition for ADC callback  */
typedef void (*ADC_Callback_t)(ADC_Idx_t adc_idx, ADC_Irq_Idx_t irq_idx);

/*! \brief type definition for adc interrupt callback  */
typedef struct
{
    ADC_Callback_t func[kADC_MAX][kADC_IRQ_MAX_NUM]; /*!< ADC Callback func */
} ADC_Int_Callback_t;

/*******************************************************************************
 * APIs
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Checks an ADC base address.
 *
 * \details This function checks an ADC base address.
 *
 * \param[in] base ADC base address
 *
 * \return ADC Base address
 *
 */
static inline bool ADC_isBaseValid(ADC_Type *base)
{
    return ((base == ADCA) || (base == ADCB) || (base == ADCC) || (base == ADCD));
}

/*!
 * \brief Checks an ADC resultbase address.
 *
 * \details This function checks an ADC result base address.
 *
 * \param[in] base ADC result base address
 *
 * \return ADC RESULT address
 *
 */
static inline bool ADC_isResultbaseValid(ADC_RESULT_Type *base)
{
    return ((base == ADC_RESULTA) || (base == ADC_RESULTB)
             || (base == ADC_RESULTC) || (base == ADC_RESULTD));
}

/*!
 * \brief Configures a start-of-conversion (SOC) in the ADC.
 *
 * \details This function setup ADC SOC number, ADC trig source, acqp sample window
 *
 * \param[in] base ADC base address
 *
 * \param[in] socNumber The socNumber number is a value ADC_SOC_NUMBERX where X is a number
 * from 0 to 15 specifying which SOC is to be configured on the ADC module
 * specified by base.
 *
 * \param[in] trigger The trigger specifies the event that causes the SOC such as software, a
 * timer interrupt, an ePWM event, or an ADC interrupt. It should be a value
 * in the format of ADC_TRIGGER_XXXX where XXXX is the event such as
 * ADC_TRIGGER_SW_ONLY, ADC_TRIGGER_CPU1_TINT0, ADC_TRIGGER_GPIO,
 * ADC_TRIGGER_EPWM1_SOCA, and so on.
 *
 * \param[in] channel The channel parameter specifies the channel to be converted. In
 * single-ended mode this is a single pin given by ADC_CH_ADCINx where x is
 * the number identifying the pin between 0 and 15 inclusive. In differential
 * mode, two pins are used as inputs and are passed in the channel
 * parameter as ADC_CH_ADCIN0_ADCIN1, ADC_CH_ADCIN2_ADCIN3, ..., or
 * ADC_CH_ADCIN14_ADCIN15.
 *
 * \param[in] sampleWindow parameter is the acquisition window duration in SYSCLK
 * cycles. It should be a value between 1 and 512 cycles inclusive. The
 * selected duration must be at least as long as one ADCCLK cycle. Also, the
 * datasheet will specify a minimum window duration requirement in
 * nanoseconds.
 */
static inline void ADC_setupSOC(ADC_Type *base, ADC_SOCNumber_t socNumber,
ADC_Trigger_t trigger, ADC_Channel_t channel, uint32_t sampleWindow)
{
    /*!< Check the arguments. */
    assert(ADC_isBaseValid(base));
    assert((sampleWindow >= 1U) && (sampleWindow <= 512U));

    /*!< Set the configuration of the specified SOC. */
    uint32_t data =
        ADC_ADCSOCCTL_CHSEL_Set(channel) | ADC_ADCSOCCTL_TRIGSEL_Set(trigger) 
        | ADC_ADCSOCCTL_ACQPS_Set(sampleWindow);

    base->ADCSOCCTL[socNumber].ADCSOCCTL = data;
}

/*!
 * \brief Configures the interrupt SOC trigger of an SOC.
 *
 * \details This function configures the interrupt start-of-conversion trigger in
 * the ADC module.
 *
 * \param[in] base ADC base address
 * 
 * \param[in] socNumber The socNumber number is a value ADC_SOC_NUMBERX where X is a number
 * from 0 to 15 specifying which SOC is to be configured on the ADC module
 * specified by base.
 * 
 * \param[in] trigger The trigger specifies the interrupt that causes a start of conversion or
 * none. It should be one of the following values.
 */
static inline void ADC_setInterruptSOCTrigger(ADC_Type *base, 
                           ADC_SOCNumber_t socNumber, ADC_IntSOCTrigger_t trigger)
{
    /*!< Check the arguments. */
    assert(ADC_isBaseValid(base));

    uint32_t msk   = 0;
    uint32_t value = 0;

    /*!< Each SOC has a 2-bit field in this register.
     * Set the configuration of the specified SOC. Not that we're treating
     * ADCINTSOCSEL1 and ADCINTSOCSEL2 as one 32-bit register here. */
    if (socNumber < kADC_SOC_NUMBER8)
    {
        msk                 = 3U << (socNumber * 2U);
        value               = trigger << (socNumber * 2U);
        base->ADCINTSOCSEL1 = (base->ADCINTSOCSEL1 & (~msk)) | value;
    }
    else
    {
        msk                 = 3U << ((socNumber - 8) * 2U);
        value               = trigger << ((socNumber - 8) * 2U);
        base->ADCINTSOCSEL2 = (base->ADCINTSOCSEL2 & (~msk)) | value;
    }
}

/*!
 * \brief Sets the timing of the end-of-conversion pulse
 *
 * \details This function configures the end-of-conversion (EOC) pulse generated by ADC.
 *
 * \param[in] base ADC base address
 * 
 * \param[in] pulseMode This pulse will be generated either at the end of the acquisition window
 * (pass ADC_PULSE_END_OF_ACQ_WIN into pulseMode) or at the end of the
 * voltage conversion, one cycle prior to the ADC result latching into it's
 * result register (pass ADC_PULSE_END_OF_CONV into pulseMode).
 */
static inline void ADC_setInterruptPulseMode(ADC_Type *base, ADC_PulseMode_t pulseMode)
{
    /*!< Check the arguments. */
    assert(ADC_isBaseValid(base));

    /*!< Set the position of the pulse. */
    base->ADCCTL1 = (base->ADCCTL1 & (~ADC_ADCCTL1_INTPULSEPOS_Msk)) 
                    | ADC_ADCCTL1_INTPULSEPOS_Set(pulseMode);
}

/*!
 * \brief Powers up the analog-to-digital converter core.
 *
 * \details This function powers up the analog circuitry inside the analog core.
 *
 * \param[in] base ADC base address
 */
static inline void ADC_enableConverter(ADC_Type *base)
{
    /*!< Check the arguments. */
    assert(ADC_isBaseValid(base));

    /*!< Set the bit that powers up the analog circuitry. */
    base->ADCCTL1 |= ADC_ADCCTL1_ADCPWDNZ_Set(kADC_ENABLE);
}

/*!
 * \brief Powers down the analog-to-digital converter module.
 *
 * \details This function powers down the analog circuitry inside the analog core.
 *
 * \param[in] base ADC base address
 */
static inline void ADC_disableConverter(ADC_Type *base)
{
    /*!< Check the arguments. */
    assert(ADC_isBaseValid(base));

    /*!< Clear the bit that powers down the analog circuitry. */
    base->ADCCTL1 &= ~(ADC_ADCCTL1_ADCPWDNZ_Set(kADC_ENABLE));
}

/*!
 * \brief Forces a SOC flag to a 1 in the analog-to-digital converter.
 *
 * \details This function forces the SOC flag associated with the SOC specified by
 * socNumber. This initiates a conversion once that SOC is given
 * priority. This software trigger can be used whether or not the SOC has been
 * configured to accept some other specific trigger.
 * 
 * \param[in] base ADC base address
 * 
 * \param[in] socNumber socNumber is the number of the start-of-conversion.
 */
static inline void ADC_forceSOC(ADC_Type *base, ADC_SOCNumber_t socNumber)
{
    /*!< Check the arguments. */
    assert(ADC_isBaseValid(base));

    uint32_t value = 0;

    value = kADC_ENABLE << (socNumber * 1U);

    /*!< Write to the register that will force a 1 to the corresponding SOC flag */
    base->ADCSOCFRC1 |= value;
}

/*!
 * \brief Forces multiple SOC flags to 1 in the analog-to-digital converter.
 *
 * \details This function forces the SOCFRC1 flags associated with the SOCs specified
 * by socMask. This initiates a conversion once the desired SOCs are given
 * priority. This software trigger can be used whether or not the SOC has been
 * configured to accept some other specific trigger.
 * Valid values for socMask parameter can be any of the individual
 * ADC_FORCE_SOCx values or any of their OR'd combination to trigger multiple
 * SOCs.note To trigger SOC0, SOC1 and SOC2, value (ADC_FORCE_SOC0 |
 * ADC_FORCE_SOC1 | ADC_FORCE_SOC2) should be passed as socMask.
 * 
 * \param[in] base ADC base address
 * 
 * \param[in] socMask is the SOCs to be forced through software
 */
static inline void ADC_forceMultipleSOC(ADC_Type *base, uint16_t socMask)
{
    //
    /*!< Check the arguments. */
    //
    assert(ADC_isBaseValid(base));

    /*!< Write to the register that will force a 1 to desired SOCs */
    base->ADCSOCFRC1 |= socMask;
}

/*!
 * \brief Gets the current ADC interrupt status.
 *
 * \details This function returns the interrupt status for the analog-to-digital
 * converter.
 * 
 * \param[in] base ADC base address
 * 
 * \param[in] adcIntNum adcIntNum takes a one of the values ADC_INT_NUMBER1,
 * ADC_INT_NUMBER2, ADC_INT_NUMBER3 or ADC_INT_NUMBER4 to get
 * the interrupt status for the given interrupt number of the ADC module.
 * 
 * \return true if the interrupt flag for the specified interrupt number is
 * set and false if it is not.
 */
static inline bool ADC_getInterruptStatus(ADC_Type *base, ADC_IntNumber_t adcIntNum)
{
    bool     adc_intflg_status;
    uint32_t adc_msk = 1U << adcIntNum;

    /*!< Check the arguments. */
    assert(ADC_isBaseValid(base));

    /*!< Get the specified ADC interrupt status. */
    adc_intflg_status = (bool)((base->ADCINTFLG & adc_msk) >> adcIntNum);
    return adc_intflg_status;
}

/*!
 * \brief Clears ADC interrupt sources.
 *
 * \details This function clears the specified ADC interrupt sources so that they no
 * longer assert. If not in continuous mode, \details This function must be called
 * before any further interrupt pulses may occur.
 * 
 * \param[in] base ADC base address
 * 
 * \param[in] adcIntNum adcIntNum takes a one of the values ADC_INT_NUMBER1,
 * ADC_INT_NUMBER2, ADC_INT_NUMBER3 or ADC_INT_NUMBER4 to get
 * the interrupt status for the given interrupt number of the ADC module.
 */
static inline void ADC_clearInterruptStatus(ADC_Type *base, ADC_IntNumber_t adcIntNum)
{
    /*!< Check the arguments. */
    assert(ADC_isBaseValid(base));

    uint32_t adc_value = kADC_ENABLE << adcIntNum;

    base->ADCINTFLGCLR |= adc_value;
}

/*!
 * \brief Gets the current ADC interrupt overflow status.
 *
 * \details This function returns the interrupt overflow status for the
 * analog-to-digital converter. An overflow condition is generated
 * irrespective of the continuous mode.
 * 
 * \param[in] base ADC base address
 * 
 * \param[in] adcIntNum adcIntNum takes a one of the values ADC_INT_NUMBER1,
 * ADC_INT_NUMBER2, ADC_INT_NUMBER3 or ADC_INT_NUMBER4 to get
 * the interrupt overflow status for the given interrupt number.
 * 
 * \return true if the interrupt overflow flag for the specified interrupt
 * number is set and false if it is not.
 */
static inline bool ADC_getInterruptOverflowStatus(ADC_Type *base, ADC_IntNumber_t adcIntNum)
{
    /*!< Check the arguments. */
    assert(ADC_isBaseValid(base));

    bool     adc_intovf_status;
    uint32_t adc_msk = 1U << adcIntNum;

    /*!< Get the specified ADC interrupt status. */
    adc_intovf_status = (bool)((base->ADCINTOVF & adc_msk) >> adcIntNum);
    return adc_intovf_status;
}

/*!
 * \brief Clears ADC interrupt overflow sources.
 *
 * \details This function clears the specified ADC interrupt overflow sources so that
 * they no longer assert. If software tries to clear the overflow in the same
 * cycle that hardware tries to set the overflow, then hardware has priority.
 * 
 * \param[in] base ADC base address
 * 
 * \param[in] adcIntNum adcIntNum takes a one of the values ADC_INT_NUMBER1,
 * ADC_INT_NUMBER2, ADC_INT_NUMBER3 or ADC_INT_NUMBER4 to express
 * which of the four interrupt overflow status of the ADC module
 * should be cleared.
 */
static inline void ADC_clearInterruptOverflowStatus(ADC_Type *base, ADC_IntNumber_t adcIntNum)
{
    /*!< Check the arguments. */
    assert(ADC_isBaseValid(base));

    uint32_t adc_value = kADC_ENABLE << adcIntNum;

    /*!< Clear the specified interrupt overflow bit. */
    base->ADCINTOVFCLR |= adc_value;
}

/*!
 * \brief Reads the conversion result.
 *
 * \details This function returns the conversion result that corresponds to the base
 * address passed into resultBase and the SOC passed into socNumber.
 *
 * \note Take care that you are using a base address for the result registers
 * (ADCxRESULT_BASE) and not a base address for the control registers.
 *
 * \param[in] resultBase ADC result base address
 *
 * \param[in] socNumber The socNumber number is a value ADC_SOC_NUMBERX where X is a number
 * from 0 to 15 specifying which SOC's result is to be read.
 *
 * \return Returns the conversion result.
 *
 */
static inline uint16_t ADC_readResult(ADC_RESULT_Type *resultBase, ADC_SOCNumber_t socNumber)
{
    /*!< Check the arguments. */
    assert(ADC_isResultbaseValid(resultBase));

    /*!< Return the ADC result for the selected SOC. */
    return (resultBase->ADCRESULT[socNumber].ADCRESULT);
}

/*!
 * \brief Determines whether the ADC is busy or not.
 *
 * \details This function allows the caller to determine whether or not the ADC is
 * busy and can sample another channel.
 * 
 * \param[in] base ADC base address
 * 
 * \return Returns true if the ADC is sampling or false if all
 * samples are complete.
 * 
 */
static inline bool ADC_isBusy(ADC_Type *base)
{
    /*!< Check the arguments. */
    assert(ADC_isBaseValid(base));

    /*!< Determine if the ADC is busy. */
    return ((bool)(ADC_ADCCTL1_ADCBSY_Get(base->ADCCTL1)));
}

/*!
 * \brief Set SOC burst mode.
 *
 * \details This function configures the burst trigger and burstSize of an ADC module.
 * Burst mode allows a single trigger to walk through the round-robin SOCs one
 * or more at a time. When burst mode is enabled, the trigger selected by the
 * ADC_setupSOC() API will no longer have an effect on the SOCs in round-robin
 * mode. Instead, the source specified through the trigger parameter will
 * cause a burst of burstSize conversions to occur.
 * 
 * \param[in] base ADC base address
 * 
 * \param[in] trigger the source that will cause the burst conversion sequence.
 * 
 * \param[in] burstSize is the number of SOCs converted during a burst sequence.
 */
static inline void ADC_setBurstModeConfig(ADC_Type *base, ADC_Trigger_t trigger, uint16_t burstSize)
{
    /*!< Check the arguments. */
    assert(ADC_isBaseValid(base));
    assert(trigger <= kADC_TRIGGER_CPU2_TINT2);
    assert((burstSize >= 1U) && (burstSize <= 16U));

    uint32_t msk  = ADC_ADCBURSTCTL_BURSTTRIGSEL_Msk | ADC_ADCBURSTCTL_BURSTSIZE_Msk;
    uint32_t data = ADC_ADCBURSTCTL_BURSTTRIGSEL_Set(trigger)
                  | ADC_ADCBURSTCTL_BURSTSIZE_Set(burstSize - 1U);

    /*!< Write the burst mode configuration to the register. */
    base->ADCBURSTCTL = (base->ADCBURSTCTL & (~msk)) | data;
}

/*!
 * \brief Enables SOC burst mode.
 *
 * \details This function enables SOC burst mode operation of the ADC. Burst mode
 * allows a single trigger to walk through the round-robin SOCs one or more at
 * a time. When burst mode is enabled, the trigger selected by the
 * ADC_setupSOC() API will no longer have an effect on the SOCs in round-robin
 * mode. Use ADC_setBurstMode() to configure the burst trigger and size.
 *
 * \param[in] base ADC base address
 *
 */
static inline void ADC_enableBurstMode(ADC_Type *base)
{
    //
    /*!< Check the arguments. */
    //
    assert(ADC_isBaseValid(base));

    //
    /*!< Enable burst mode. */
    //
    base->ADCBURSTCTL |= ADC_ADCBURSTCTL_BURSTEN_Set(kADC_ENABLE);
}

/*! 
 * \brief Disables SOC burst mode.
 *
 * \details This function disables SOC burst mode operation of the ADC. SOCs in
 * round-robin mode will be triggered by the trigger configured using the
 * ADC_setupSOC() API.
 *
 * \param[in] base is the base address of the ADC.
 *
 */
static inline void ADC_disableBurstMode(ADC_Type *base)
{
    /*!< Check the arguments. */
    assert(ADC_isBaseValid(base));

    /*!< Disable burst mode. */
    base->ADCBURSTCTL &= ~(ADC_ADCBURSTCTL_BURSTEN_Set(kADC_ENABLE));
}

/*!
 * \brief Sets the priority mode of the SOCs.
 *
 * \details This function sets the priority mode of the SOCs. There are three main
 * modes that can be passed in the priMode parameter.
 * All priorities are in high priority mode. This means that the priority of
 * the SOC is determined by its SOC number. This option is selected by passing
 * in the value ADC_PRI_ALL_HIPRI.
 * A range of SOCs are assigned high priority, with all others in round
 * robin mode. High priority mode means that an SOC with high priority will
 * interrupt the round robin wheel and insert itself as the next conversion.
 * Passing in the value ADC_PRI_SOC0_HIPRI will make SOC0 highest priority,
 * ADC_PRI_THRU_SOC1_HIPRI will put SOC0 and SOC 1 in high priority, and so
 * on up to ADC_PRI_THRU_SOC14_HIPRI where SOCs 0 through 14 are in high
 * priority.
 *
 * \param[in] base is the base address of the ADC.
 * \param[in] priMode is the priority mode of the SOCs.
 */
static inline void ADC_setSOCPriority(ADC_Type *base, ADC_PriorityMode_t priMode)
{
    //
    /*!< Check the arguments. */
    //
    assert(ADC_isBaseValid(base));

    base->ADCSOCPRICTL =
        (base->ADCSOCPRICTL & (~ADC_ADCSOCPRICTL_SOCPRIORITY_Msk)) | ADC_ADCSOCPRICTL_SOCPRIORITY_Set(priMode);
}

/*!
 * Values that can be passed to ADC_enablePPBEvent(), ADC_disablePPBEvent(),
 * ADC_enablePPBEventInterrupt(), ADC_disablePPBEventInterrupt(), and
 * ADC_clearPPBEventStatus() as the intFlags and evtFlags parameters. They also
 * make up the enumerated bit field returned by ADC_getPPBEventStatus().
*/


/*!
 * \brief Configures a post-processing block (PPB) in the ADC.
 *
 * \details This function associates a post-processing block with a SOC.
 * The ppbNumber is a value ADC_PPB_NUMBERX where X is a value from 1 to
 * 4 inclusive that identifies a PPB to be configured.  The socNumber
 * number is a value ADC_SOC_NUMBERX where X is a number from 0 to 15
 * specifying which SOC is to be configured on the ADC module specified by
 * base.
 *
 * \note You can have more that one PPB associated with the same SOC, but a
 * PPB can only be configured to correspond to one SOC at a time. Also note
 * that when you have multiple PPBs for the same SOC, the calibration offset
 * that actually gets applied will be that of the PPB with the highest number.
 * Since SOC0 is the default for all PPBs, look out for unintentional
 * overwriting of a lower numbered PPB's offset.
 *
 * \param[in] base is the base address of the ADC module.
 *
 * \param[in] ppbNumber is the number of the post-processing block.
 *
 * \param[in] socNumber is the number of the start-of-conversion.
 *
 */

static inline void ADC_setupPPB(ADC_Type *base, ADC_PPBNumber_t ppbNumber, ADC_SOCNumber_t socNumber)
{
    /*!< Check the arguments. */
    assert(ADC_isBaseValid(base));

    /*!< Get the offset to the appropriate PPB configuration register. */
    base->ADCPPBCREG[ppbNumber].PPBCFG =
        (base->ADCPPBCREG[ppbNumber].PPBCFG & (~ADC_PPBCFG_PPB1CONFIG_Msk)) 
        | ADC_PPBCFG_PPB1CONFIG_Set(socNumber);
}

/*!
 * \brief Enables individual ADC PPB event sources.
 *
 * \details This function enables the indicated ADC PPB event sources.  This will allow
 * the specified events to propagate through the XBAR to a pin or to an ePWM
 * module.  The evtFlags parameter can be any of the ADC_EVT_TRIPHI,
 * ADC_EVT_TRIPLO, or ADC_EVT_ZERO values.
 *
 * \param[in] base is the base address of the ADC module.
 *
 * \param[in] ppbNumber is the number of the post-processing block.
 *
 * \param[in] evtFlags is a bit mask of the event sources to be enabled.
 */
static inline void ADC_enablePPBEvent(ADC_Type *base, ADC_PPBNumber_t ppbNumber, uint16_t evtFlags)
{
    /*!< Check the arguments. */
    assert(ADC_isBaseValid(base));
    assert((evtFlags & ~0x7U) == 0U);

    /*!< Enable the specified event. */
    uint32_t data   = evtFlags << ADC_PPB_REG_NUM_OFFSET(ppbNumber);
    base->ADCEVTSEL |= data;
}

/*!
 * \brief Disables individual ADC PPB event sources.
 *
 * \details This function disables the indicated ADC PPB event sources.  This will stop
 * the specified events from propagating through the XBAR to other modules.
 * The evtFlags parameter can be any of the ADC_EVT_TRIPHI,
 * ADC_EVT_TRIPLO, or ADC_EVT_ZERO values.
 *
 * \param[in] base is the base address of the ADC module.
 *
 * \param[in] ppbNumber is the number of the post-processing block.
 *
 * \param[in] evtFlags is a bit mask of the event sources to be enabled.
 */
static inline void ADC_disablePPBEvent(ADC_Type *base, ADC_PPBNumber_t ppbNumber, uint16_t evtFlags)
{
    /*!< Check the arguments. */
    assert(ADC_isBaseValid(base));
    assert((evtFlags & ~0x7U) == 0U);

    /*!< Disable the specified event. */
    uint32_t data   = evtFlags << ADC_PPB_REG_NUM_OFFSET(ppbNumber);
    base->ADCEVTSEL &= ~data;
}

/*!
 * \brief Enables individual ADC PPB event interrupt sources.
 *
 * \details This function enables the indicated ADC PPB interrupt sources.  Only the
 * sources that are enabled can be reflected to the processor interrupt.
 * Disabled sources have no effect on the processor.  The intFlags
 * parameter can be any of the ADC_EVT_TRIPHI, ADC_EVT_TRIPLO, or
 * ADC_EVT_ZERO values.
 *
 * \param[in] base is the base address of the ADC module.
 *
 * \param[in] ppbNumber is the number of the post-processing block.
 *
 * \param[in] intFlags is a bit mask of the interrupt sources to be enabled.
 */
static inline void ADC_enablePPBEventInterrupt(ADC_Type *base, ADC_PPBNumber_t ppbNumber, uint16_t intFlags)
{
    /*!< Check the arguments. */
    assert(ADC_isBaseValid(base));
    assert((intFlags & ~0x7U) == 0U);

    /*!< Enable the specified event interrupts. */
    uint32_t data       = intFlags << ADC_PPB_REG_NUM_OFFSET(ppbNumber);
    base->ADCEVTINTSEL |= data;
}

/*!
 * \brief Disables individual ADC PPB event interrupt sources.
 *
 * \details This function disables the indicated ADC PPB interrupt sources.  Only the
 * sources that are enabled can be reflected to the processor interrupt.
 * Disabled sources have no effect on the processor.  The intFlags
 * parameter can be any of the ADC_EVT_TRIPHI, ADC_EVT_TRIPLO, or
 * ADC_EVT_ZERO values.
 *
 * \param[in] base is the base address of the ADC module.
 *
 * \param[in] ppbNumber is the number of the post-processing block.
 *
 * \param[in] intFlags is a bit mask of the interrupt source to be disabled.
 */
static inline void ADC_disablePPBEventInterrupt(ADC_Type *base, ADC_PPBNumber_t ppbNumber, uint16_t intFlags)
{
    /*!< Check the arguments. */
    assert(ADC_isBaseValid(base));
    assert((intFlags & ~0x7U) == 0U);

    /*!< Enable the specified event interrupts. */
    uint32_t data = intFlags << ADC_PPB_REG_NUM_OFFSET(ppbNumber);
    base->ADCEVTINTSEL &= ~data;
}

/*!
 * \brief Gets the current ADC event status.
 *
 * \details This function returns the event status for the analog-to-digital converter.
 *
 * \param[in] base is the base address of the ADC module.
 *
 * \param[in] ppbNumber is the number of the post-processing block.
 *
 * \return Returns the current event status, enumerated as a bit field of
 * ADC_EVT_TRIPHI, ADC_EVT_TRIPLO, and ADC_EVT_ZERO.
*/
static inline uint16_t ADC_getPPBEventStatus(ADC_Type *base, ADC_PPBNumber_t ppbNumber)
{
    /*!< Check the arguments. */
    assert(ADC_isBaseValid(base));

    /*!< Get the event status for the specified post-processing block. */
    uint32_t adc_msk = (ADC_ADCEVTSTAT_PPB1TRIPHI_Msk | ADC_ADCEVTSTAT_PPB1TRIPLO_Msk | ADC_ADCEVTSTAT_PPB1ZERO_Msk)
                       << ADC_PPB_REG_NUM_OFFSET(ppbNumber);
    uint16_t adc_evtstatus = ((base->ADCEVTSTAT & adc_msk) >> ADC_PPB_REG_NUM_OFFSET(ppbNumber));
    return adc_evtstatus;
}

/*!
 * \brief Clears ADC event flags.
 *
 * \details This function clears the indicated ADC PPB event flags. After an event
 * occurs. This function must be called to allow additional events to be
 * produced. The evtFlags parameter can be any of the ADC_EVT_TRIPHI,
 * ADC_EVT_TRIPLO, or ADC_EVT_ZERO values.
 *
 * \param[in] base is the base address of the ADC module.
 *
 * \param[in] ppbNumber is the number of the post-processing block.
 *
 * \param[in] evtFlags is a bit mask of the event source to be cleared.
 *
 */
static inline void ADC_clearPPBEventStatus(ADC_Type *base, ADC_PPBNumber_t ppbNumber, uint16_t evtFlags)
{
    /*!< Check the arguments. */
    assert(ADC_isBaseValid(base));

    /*!< Clear the specified event interrupts. */
    uint32_t adc_value = evtFlags << ADC_PPB_REG_NUM_OFFSET(ppbNumber);
    base->ADCEVTCLR    |= adc_value;
}

/*!
 * \brief Reads the processed conversion result from the PPB.
 *
 * \details This function returns the processed conversion result that corresponds to
 * the base address passed into resultBase and the PPB passed into ppbNumber.
 *
 * \note Take care that you are using a base address for the result registers
 * (ADCxRESULT_BASE) and not a base address for the control registers.
 *
 * \param[in] resultBase is the base address of the ADC results.
 *
 * \param[in] ppbNumber is the number of the post-processing block.
 *
 * \return ADC PPB result
 */
static inline int32_t ADC_readPPBResult(ADC_RESULT_Type *resultBase, ADC_PPBNumber_t ppbNumber)
{
    /*!< Check the arguments. */
    assert(ADC_isResultbaseValid(resultBase));

    /*!< Return the result of selected PPB. */
    return (resultBase->ADCPPBRESULT[ppbNumber].ADCPPBRESULT);
}

/*!
 * \brief Reads sample delay time stamp from a PPB.
 *
 * \details This function returns the sample delay time stamp. This delay is the number
 * of system clock cycles between the SOC being triggered and when it began
 * converting.
 *
 * \param[in] base is the base address of the ADC module.
 *
 * \param[in] ppbNumber is the number of the post-processing block.
 *
 * \return ADC PPB Delay Time Stamp
 */
static inline uint16_t ADC_getPPBDelayTimeStamp(ADC_Type *base, ADC_PPBNumber_t ppbNumber)
{
    /*!< Check the arguments. */
    assert(ADC_isBaseValid(base));

    /*!< Get the offset to the appropriate delay. */
    return (base->ADCPPBCREG[ppbNumber].PPBSTAMP);
}

/*!
 * \brief Sets the post processing block offset correction.
 *
 * \details This function sets the PPB offset correction value.  This value can be used
 * to digitally remove any system-level offset inherent in the ADCIN circuit
 * before it is stored in the appropriate result register. The offset
 * parameter is subtracted from the ADC output and is a signed value from
 * -512 to 511 inclusive. For example, when offset = 1, ADCRESULT = ADC
 * output - 1. When offset = -512, ADCRESULT = ADC output - (-512) or ADC
 * output + 512.
 * Passing a zero in to the offset parameter will effectively disable the
 * calculation, allowing the raw ADC result to be passed unchanged into the
 * result register.
 *
 * \note If multiple PPBs are applied to the same SOC, the offset that will be
 * applied will be that of the PPB with the highest number.
 *
 * \param[in] base is the base address of the ADC module.
 *
 * \param[in] ppbNumber is the number of the post-processing block.
 *
 * \param[in] offset is the 10-bit signed value subtracted from ADC the output.
 */
static inline void ADC_setPPBCalibrationOffset(ADC_Type *base, ADC_PPBNumber_t ppbNumber, int16_t offset)
{
    /*!< Check the arguments. */
    assert(ADC_isBaseValid(base));

    /*!< Write the offset amount. */
    base->ADCPPBCREG[ppbNumber].PPBOFFCAL = ADC_PPBOFFCAL_OFFCAL_Set(offset);
}

/*!
 * \brief Sets the post processing block reference offset.
 *
 * \details This function sets the PPB reference offset value. This can be used to
 * either calculate the feedback error or convert a unipolar signal to bipolar
 * by subtracting a reference value. The result will be stored in the
 * appropriate PPB result register which can be read using ADC_readPPBResult().
 * Passing a zero in to the offset parameter will effectively disable the
 * calculation and will pass the ADC result to the PPB result register unchanged.
 *
 * \note If in 12-bit mode, you may only pass a 12-bit value into the offset
 * parameter.
 *
 * \param[in] base is the base address of the ADC module.
 *
 * \param[in] ppbNumber is the number of the post-processing block.
 *
 * \param[in] offset is the 16-bit unsigned value subtracted from ADC the output.
 */
static inline void ADC_setPPBReferenceOffset(ADC_Type *base, ADC_PPBNumber_t ppbNumber, uint16_t offset)
{
    /*!< Check the arguments. */
    assert(ADC_isBaseValid(base));

    /*!< Write the offset amount. */
    base->ADCPPBCREG[ppbNumber].PPBOFFREF = ADC_PPBOFFREF_OFFREF_Set(offset);
}

/*!
 * \brief Enables two's complement capability in the PPB.
 *
 * \details This function enables two's complement in the post-processing block
 * specified by the ppbNumber parameter. When enabled, a two's complement
 * will be performed on the output of the offset subtraction before it is
 * stored in the appropriate PPB result register. In other words, the PPB
 * result will be the reference offset value minus the the ADC result value
 * (ADCPPBxRESULT = ADCSOCxOFFREF - ADCRESULTx).
 *
 * \param[in] base is the base address of the ADC module.
 *
 * \param[in] ppbNumber is the number of the post-processing block.
 */
static inline void ADC_enablePPBTwosComplement(ADC_Type *base, ADC_PPBNumber_t ppbNumber)
{
    /*!< Check the arguments. */
    assert(ADC_isBaseValid(base));

    /*!< Enable PPB two's complement. */
    base->ADCPPBCREG[ppbNumber].PPBCFG |= ADC_PPBCFG_TWOSCOMPEN_Set(kADC_ENABLE);
}

/*!
 * \brief Disables two's complement capability in the PPB.
 *
 * \details This function disables two's complement in the post-processing block
 * specified by the ppbNumber parameter. When disabled, a two's complement
 * will NOT be performed on the output of the offset subtraction before it
 * is stored in the appropriate PPB result register. In other words, the PPB
 * result will be the ADC result value minus the reference offset value
 * (ADCPPBxRESULT = ADCRESULTx - ADCSOCxOFFREF).
 *
 * \param[in] base is the base address of the ADC module.
 *
 * \param[in] ppbNumber is the number of the post-processing block.
 */
static inline void ADC_disablePPBTwosComplement(ADC_Type *base, ADC_PPBNumber_t ppbNumber)
{
    /*!< Check the arguments. */
    assert(ADC_isBaseValid(base));

    /*!< Enable PPB two's complement. */
    base->ADCPPBCREG[ppbNumber].PPBCFG &= ~(ADC_PPBCFG_TWOSCOMPEN_Set(kADC_ENABLE));
}

/*!
 * \brief Enables an ADC interrupt source.
 *
 * \details This function enables the indicated ADC interrupt source.  Only the
 * sources that are enabled can be reflected to the processor interrupt.
 * Disabled sources have no effect on the processor.
 *
 * \param[in] base is the base address of the ADC module.
 *
 * \param[in] adcIntNum is interrupt number within the ADC wrapper.
 * adcIntNum can take the value ADC_INT_NUMBER1,
 * ADC_INT_NUMBER2, ADC_INT_NUMBER3 or ADC_INT_NUMBER4 to express
 * which of the four interrupts of the ADC module should be enabled.
 */
static inline void ADC_enableInterrupt(ADC_Type *base, ADC_IntNumber_t adcIntNum)
{
    /*!< Check the arguments. */
    assert(ADC_isBaseValid(base));

    /*!< Enable the specified ADC interrupt. */
    switch (adcIntNum)
    {
        case kADC_INT_NUMBER1:
            base->ADCINTSEL1N2 |= ADC_ADCINTSEL1N2_INT1E_Set(kADC_ENABLE);
            break;
        case kADC_INT_NUMBER2:
            base->ADCINTSEL1N2 |= ADC_ADCINTSEL1N2_INT2E_Set(kADC_ENABLE);
            break;
        case kADC_INT_NUMBER3:
            base->ADCINTSEL3N4 |= ADC_ADCINTSEL3N4_INT3E_Set(kADC_ENABLE);
            break;
        case kADC_INT_NUMBER4:
            base->ADCINTSEL3N4 |= ADC_ADCINTSEL3N4_INT4E_Set(kADC_ENABLE);
            break;
        default:
            break;
    }
}

/*!
 * \brief Disables an ADC interrupt source.
 *
 * \details This function disables the indicated ADC interrupt source.
 * Only the sources that are enabled can be reflected to the processor
 * interrupt. Disabled sources have no effect on the processor.
 *
 * \param[in] base is the base address of the ADC module.
 *
 * \param[in] adcIntNum is interrupt number within the ADC wrapper.
 * adcIntNum can take the value ADC_INT_NUMBER1,
 * ADC_INT_NUMBER2, ADC_INT_NUMBER3 or ADC_INT_NUMBER4 to express
 * which of the four interrupts of the ADC module should be disabled.
 */
static inline void ADC_disableInterrupt(ADC_Type *base, ADC_IntNumber_t adcIntNum)
{
    /*!< Check the arguments. */
    assert(ADC_isBaseValid(base));

    /*!< Disable the specified ADC interrupt. */
    switch (adcIntNum)
    {
        case kADC_INT_NUMBER1:
            base->ADCINTSEL1N2 &= ~(ADC_ADCINTSEL1N2_INT1E_Set(kADC_ENABLE));
            break;
        case kADC_INT_NUMBER2:
            base->ADCINTSEL1N2 &= ~(ADC_ADCINTSEL1N2_INT2E_Set(kADC_ENABLE));
            break;
        case kADC_INT_NUMBER3:
            base->ADCINTSEL3N4 &= ~(ADC_ADCINTSEL3N4_INT3E_Set(kADC_ENABLE));
            break;
        case kADC_INT_NUMBER4:
            base->ADCINTSEL3N4 &= ~(ADC_ADCINTSEL3N4_INT4E_Set(kADC_ENABLE));
            break;
        default:
            break;
    }
}

/*!
 * \brief Sets the source EOC for an analog-to-digital converter interrupt.
 *
 * \details This function sets which conversion is the source of an ADC interrupt.
 *
 * \param[in] base is the base address of the ADC module.
 *
 * \param[in] adcIntNum is interrupt number within the ADC wrapper.
 * adcIntNum can take the value ADC_INT_NUMBER1,
 * ADC_INT_NUMBER2, ADC_INT_NUMBER3 or ADC_INT_NUMBER4 to express
 * which of the four interrupts of the ADC module is being configured.
 *
 * \param[in] intTrigger is the number of the start-of-conversion.
 * The intTrigger number is a value ADC_SOC_NUMBERX where X is a number
 * from 0 to 15 specifying which EOC is to be configured on the ADC module
 * specified by base. Refer ADC_SOCNumber enum for valid values for
 * this input.
 */
static inline void ADC_setInterruptSource(ADC_Type *base, ADC_IntNumber_t adcIntNum, uint16_t intTrigger)
{
    /*!< Check the arguments. */
    assert(ADC_isBaseValid(base));

    /*!< Set the specified ADC interrupt source. */
    switch (adcIntNum)
    {
        case kADC_INT_NUMBER1:
            base->ADCINTSEL1N2 =
                (base->ADCINTSEL1N2 & (~ADC_ADCINTSEL1N2_INT1SEL_Msk)) | ADC_ADCINTSEL1N2_INT1SEL_Set(intTrigger);
            break;
        case kADC_INT_NUMBER2:
            base->ADCINTSEL1N2 =
                (base->ADCINTSEL1N2 & (~ADC_ADCINTSEL1N2_INT2SEL_Msk)) | ADC_ADCINTSEL1N2_INT2SEL_Set(intTrigger);
            break;
        case kADC_INT_NUMBER3:
            base->ADCINTSEL3N4 =
                (base->ADCINTSEL3N4 & (~ADC_ADCINTSEL3N4_INT3SEL_Msk)) | ADC_ADCINTSEL3N4_INT3SEL_Set(intTrigger);
            break;
        case kADC_INT_NUMBER4:
            base->ADCINTSEL3N4 =
                (base->ADCINTSEL3N4 & (~ADC_ADCINTSEL3N4_INT4SEL_Msk)) | ADC_ADCINTSEL3N4_INT4SEL_Set(intTrigger);
            break;
        default:
            break;
    }
}

/*!
 * \brief Enables continuous mode for an ADC interrupt.
 *
 * \details This function enables continuous mode for the ADC interrupt passed into
 * adcIntNum. This means that pulses will be generated for the specified
 * ADC interrupt whenever an EOC pulse is generated irrespective of whether or
 * not the flag bit is set.
 *
 * \param[in] base is the base address of the ADC.
 *
 * \param[in] adcIntNum is interrupt number within the ADC wrapper.
 * adcIntNum can take the value ADC_INT_NUMBER1,
 * ADC_INT_NUMBER2, ADC_INT_NUMBER3 or ADC_INT_NUMBER4 to express
 * which of the four interrupts of the ADC module is being configured.
 */
static inline void ADC_enableContinuousMode(ADC_Type *base, ADC_IntNumber_t adcIntNum)
{
    /*!< Check the arguments. */
    assert(ADC_isBaseValid(base));

    /*!< Enable continuous mode for the specified ADC interrupt. */
    switch (adcIntNum)
    {
        case kADC_INT_NUMBER1:
            base->ADCINTSEL1N2 |= ADC_ADCINTSEL1N2_INT1CONT_Set(kADC_ENABLE);
            break;
        case kADC_INT_NUMBER2:
            base->ADCINTSEL1N2 |= ADC_ADCINTSEL1N2_INT2CONT_Set(kADC_ENABLE);
            break;
        case kADC_INT_NUMBER3:
            base->ADCINTSEL3N4 |= ADC_ADCINTSEL3N4_INT3CONT_Set(kADC_ENABLE);
            break;
        case kADC_INT_NUMBER4:
            base->ADCINTSEL3N4 |= ADC_ADCINTSEL3N4_INT4CONT_Set(kADC_ENABLE);
            break;
        default:
            break;
    }
}

/*!
 * \brief Disables continuous mode for an ADC interrupt.
 *
 * \details This function disables continuous mode for the ADC interrupt passed into
 * adcIntNum. This means that pulses will not be generated for the
 * specified ADC interrupt until the corresponding interrupt flag for the
 * previous interrupt occurrence has been cleared using ADC_clearInterruptStatus().
 *
 * \param[in] base is the base address of the ADC.
 *
 * \param[in] adcIntNum is interrupt number within the ADC wrapper.
 * adcIntNum can take the value ADC_INT_NUMBER1,
 * ADC_INT_NUMBER2, ADC_INT_NUMBER3 or ADC_INT_NUMBER4 to express
 * which of the four interrupts of the ADC module is being configured.
 */
static inline void ADC_disableContinuousMode(ADC_Type *base, ADC_IntNumber_t adcIntNum)
{
    /*!< Check the arguments. */
    assert(ADC_isBaseValid(base));

    /*!< Disable continuous mode for the specified ADC interrupt. */
    switch (adcIntNum)
    {
        case kADC_INT_NUMBER1:
            base->ADCINTSEL1N2 &= ~ADC_ADCINTSEL1N2_INT1CONT_Msk;
            break;
        case kADC_INT_NUMBER2:
            base->ADCINTSEL1N2 &= ~ADC_ADCINTSEL1N2_INT2CONT_Msk;
            break;
        case kADC_INT_NUMBER3:
            base->ADCINTSEL3N4 &= ~ADC_ADCINTSEL3N4_INT3CONT_Msk;
            break;
        case kADC_INT_NUMBER4:
            base->ADCINTSEL3N4 &= ~ADC_ADCINTSEL3N4_INT4CONT_Msk;
            break;
        default:
            break;
    }
}

/*!
 * \brief Converts temperature from sensor reading to degrees C
 *
 * \details This function converts temperature from temp sensor reading to degrees C.
 * Temp sensor values in production test are derived with 2.5V reference.
 * The vref argument in the function is used to scale the temp sensor
 * reading accordingly if temp sensor value is read at a different VREF
 * setting.
 *
 * \param[in] tempResult is the raw ADC A conversion result from the temp sensor.
 *
 * \param[in] vref is the reference voltage being used (for example 3.3 for 3.3V).
 *
 * \return Returns the temperature sensor reading converted to degrees C.
*/
static inline int16_t ADC_getTemperatureC(uint16_t tempResult, uint16_t vref)
{
    /*!< Check the device revision */
    uint16_t temperature_data;

    /*!< For production devices (Rev. C), pull the slope and offset from OTP */
    temperature_data = (uint16_t)((tempResult * vref / 4096.0 - 1030.0) * 10000.0 / 37486.0);

    return temperature_data;
}

/*!
 * \brief Get the PPB event select status
 *
 * \details This function gets the PPB event select high or low or zero limit.
 *
 * \param[in] base is the base address of the ADC module.
 *
 * \param[in] ppbNumber is the number of the post-processing block.
 *
 * \return the ppbNumber's event select configuration.
 */
static inline uint16_t ADC_getPPBevtintsel(ADC_Type *base, ADC_PPBNumber_t ppbNumber)
{
    /*!< Check the arguments. */
    assert(ADC_isBaseValid(base));

    /*!< Get the event status for the specified post-processing block. */
    uint32_t adc_msk =
        (ADC_ADCEVTINTSEL_PPB1TRIPHI_Msk | ADC_ADCEVTINTSEL_PPB1TRIPLO_Msk | ADC_ADCEVTINTSEL_PPB1ZERO_Msk)
        << ADC_PPB_REG_NUM_OFFSET(ppbNumber);
    uint16_t adc_evtints = (base->ADCEVTINTSEL & adc_msk) >> ADC_PPB_REG_NUM_OFFSET(ppbNumber);

    return adc_evtints;
}

/*!
 * \brief Configure SOC convertion time.
 *
 * \details This function configure the SOC convertion time to makesure ADC stable convert.
 *
 * \param[in] base is the base address of the ADC module.
 *
 * \param[in] socNumber The socNumber number is a value ADC_SOC_NUMBERX where X is a number
 * from 0 to 15.
 *
 * \param[in] socCNV The socCNV number is the convert time to be setup. cnv time = (socCNV + 1)*clk
 */
static inline void ADC_setSocConvertTime(ADC_Type *base, ADC_SOCNumber_t socNumber, uint32_t socCNV)
{
    assert(ADC_isBaseValid(base));

    /*!< Calculate address for the SOC control register. */
    base->ADCSOCCNV[socNumber].ADCSOCCNV = ADC_ADCSOCCNV_SOCCNV_Set(socCNV);
}

/*!
 * \brief Configure SOC mux change delay time.
 *
 * \param[in] base is the base address of the ADC module.
 *
 * \param[in] delay The delay number is a value to setup mux delay time.
 */
static inline void ADC_setMuxDelay(ADC_Type *base, uint16_t delay)
{
    /*!< Check the arguments. */
    assert(ADC_isBaseValid(base));

    /*!< Load in the muxdelay number. */
    base->ADCCTL3 = ADC_ADCCTL3_MUXDELAY_Set(delay);
}

/*!
 * \brief Clear SOC OVF flag.
 *
 * \details This function is clearing the soc number's overflow flag.
 *
 * \param[in] base is the base address of the ADC module.
 *
 * \param[in] socNumber The socNumber number is a value ADC_SOC_NUMBERX where X is a number
 * from 0 to 15.
 */
static inline void ADC_setConvertionOVFClear(ADC_Type *base, ADC_SOCNumber_t socNumber)
{
    uint32_t data;

    /*!< Check the arguments. */
    assert(ADC_isBaseValid(base));

    /*!< Clear the soc number overflow flag. */
    data                 = kADC_ENABLE << socNumber;
    base->ADCSOCOVFCLR1 |= data;
}

/*!
 * \brief Enable PPB cycle by cycle function.
 *
 * \details This function enables the post conversion hardware processing circuit to
 * automatically clear the ADCEVTSTAT on a conversion if the event
 * condition is no longer present.
 *
 * \param[in] base is the base address of the ADC module.
 *
 * \param[in] ppbNumber is the number of the post-processing block.
 */
static inline void ADC_enablePPBEventCBCClear(ADC_Type *base, ADC_PPBNumber_t ppbNumber)
{
    /*!< Check the arguments. */
    assert(ADC_isBaseValid(base));

    /*!< Enable the CBCEN of ppb number. */
    base->ADCPPBCREG[ppbNumber].PPBCFG |= ADC_PPBCFG_CBCEN_Set(kADC_ENABLE);
}

/*!
 * \brief Disable PPB cycle by cycle function.
 *
 * \details This function disables the post conversion hardware processing circuit to
 * automatically clear the ADCEVTSTAT on a conversion if the event
 * condition is no longer present.
 *
 * \param[in] base is the base address of the ADC module.
 *
 * \param[in] ppbNumber is the number of the post-processing block.
 */
static inline void ADC_disablePPBEventCBCClear(ADC_Type *base, ADC_PPBNumber_t ppbNumber)
{
    /*!< Check the arguments. */
    assert(ADC_isBaseValid(base));

    /*!< Disable the CBCEN of ppb number. */
    base->ADCPPBCREG[ppbNumber].PPBCFG &= ~ADC_PPBCFG_CBCEN_Msk;
}

/*!
 * \brief Setup interrupt delay times.
 *
 * \details This function setup the interrupt delay times.Int delay = delay * clk
 *
 * \param[in] base is the base address of the ADC module.
 *
 * \param[in] delay is the number of the int delat cycles.
 */
static inline void ADC_setInterruptCycleOffset(ADC_Type *base, uint32_t delay)
{
    /*!< Check the arguments. */
    assert(ADC_isBaseValid(base));

    /*!< Set interrupt delay time. */
    base->ADCINTCYCLE = ADC_ADCINTCYCLE_DELAY_Set(delay);
}

/*!
 * \brief Configures the analog-to-digital converter resolution and signal mode.
 *
 * \details This function configures the ADC module's conversion resolution and input
 * signal mode and ensures that the corresponding trims are loaded.
 *
 * \note In this device, single-ended signal conversions are supported
 *          only in 12-bit resolution mode and differential signal
 *          conversions are supported only in 16-bit resolution mode.
 *
 * \param[in] base is the base address of the ADC module.
 *
 * \param[in] resolution is the resolution of the converter (12 or 16 bits).
 * The resolution parameter specifies the resolution of the conversion.
 * It can be 12-bit or 16-bit specified by ADC_RESOLUTION_12BIT
 * or ADC_RESOLUTION_16BIT.
 *
 * \param[in] signalMode is the input signal mode of the converter.
 * The signalMode parameter specifies the signal mode. In single-ended
 * mode, which is indicated by ADC_MODE_SINGLE_ENDED, the input voltage is
 * sampled on a single pin referenced to VREFLO. In differential mode, which
 * is indicated by ADC_MODE_DIFFERENTIAL, the input voltage to the
 * converter is sampled on a pair of input pins, a positive and a negative.
 */
extern void ADC_setMode(ADC_Type *base, ADC_Resolution_t resolution, ADC_SignalMode_t signalMode);

/*!
 * \brief Configures the offset trim for the desired ADC instance
 *
 * \details This function loads the offset trims for the desired ADC instance.
 *
 * \param[in] base is the base address of the ADC module.
 */
extern void ADC_setOffsetTrim(ADC_Type *base);

/*!
 * \brief Configures the INL trim for the desired ADC instance
 *
 * \details This function loads the INL trims for the desired ADC instance.
 *
 * \param[in] base is the base address of the ADC module.
 */
extern void ADC_setINLTrim(ADC_Type *base);

/*!
 * \brief Sets the windowed trip limits for a PPB.
 *
 * \details This function sets the windowed trip limits for a PPB. These values set
 * the digital comparator so that when one of the values is exceeded, either a
 * high or low trip event will occur.
 *
 * \note On some devices, signed trip values do not work properly. See the
 * silicon errata for details.
 * If using 16-bit mode, you may pass a 17-bit number into the tripHiLimit
 * and tripLoLimit parameters where the 17th bit is the sign bit (that is
 * a value from -65536 and 65535). In 12-bit mode, only bits 12:0 will be
 * compared against bits 12:0 of the PPB result.
 *
 * \param[in] base is the base address of the ADC module.
 *
 * \param[in] ppbNumber is the number of the post-processing block.
 * The ppbNumber is a value ADC_PPB_NUMBERX where X is a value from 1 to
 * 4 inclusive that identifies a PPB to be configured.
 *
 * \param[in] tripHiLimit is the value is the digital comparator trip high limit.
 *
 * \param[in] tripLoLimit is the value is the digital comparator trip low limit.
 */
extern void ADC_setPPBTripLimits(ADC_Type *base, ADC_PPBNumber_t ppbNumber, int32_t tripHiLimit, int32_t tripLoLimit);

/*!
 * \brief get ADC trim value base address.
 *
 * \details This function gets ADC different module the different trim base address.
 *
 * \param[in] base is the base address of the ADC module.
 */
extern void GetAdcTrimBaseEflash(ADC_Type *base);

/*!
 * \brief Register user callback function to a specified ADC
 *
 * \details This function registers user callback function for ADC which uses IRQ. The relative IRQ
 will be enabled in the NVIC and the priority will be configured at the same time
 * \param[in] base is the ADC base address
 * \param[in] intsrc is the ADC INT index
 * \param[in] func is the ADC user callback
 * \param[in] priority is the IRQ priority
 *
 * \retval kSTATUS_SUCESS Success to the operation
 * \retval kSTATUS_FAIL Register to a ADC which has been registered already. Need to call \ref
 ADC_unregisterCallback() before the re-registration
 */
status_t ADC_registerCallback(ADC_Type *base, ADC_Irq_Idx_t intsrc, ADC_Callback_t func, uint32_t priority);

/*!
 * \brief Unregister user callback function to ADC transfer
 *
 * \details This function clears the registered user callback function, and disable the relative IRQ in the NVIC
 *
 * \param[in] base is the ADC base address
 * \param[in] intsrc is the ADC INT index
 * \retval kSTATUS_SUCESS Success to the operation
 * \retval kSTATUS_INVALID_ARGUMENT The ADC hasn't been registered to a callback
 */
status_t ADC_unregisterCallback(ADC_Type *base, ADC_Irq_Idx_t intsrc);

/*!
 * \brief Get ADC instance using the base address
 *
 * \details This function converts ADC base address to ADC instance which is an unsigned integer value. 0,1,2,3,...
 * stands for the peripheral with suffix A,B,C,D
 *
 * \param[in] adc_base ADC base address
 *
 * \return The ADC instance
 */
ADC_Idx_t adc_getInstance(ADC_Type *adc_base);

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */ /* end of DRV_HTE_ADC */

#endif /*!< _ADC_H_ */
