/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_adc.c
 * \brief SDK ADC driver source file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_adc.h"
#include "hte_calib.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! \brief ADC linear default value*/
uint32_t linearDefault[6]  = {0x20005800, 0x02000800, 0x30040040, 0x08040100, 0x00002010, 0x0};

/*! \brief ADC Calibration value from Eflash */
ADC_EflashTrimValue_t adcEflashTrimValue = {0};

/*! \brief ADC IRQ ARRAY */
static const IRQn_Type ADC_IRQ[kADC_MAX][kADC_IRQ_MAX_NUM] = {
    { ADCA_EVT_IRQn, ADCA_INT1_IRQn, ADCA_INT2_IRQn, ADCA_INT3_IRQn, ADCA_INT4_IRQn },
    { ADCB_EVT_IRQn, ADCB_INT1_IRQn, ADCB_INT2_IRQn, ADCB_INT3_IRQn, ADCB_INT4_IRQn },
    { ADCC_EVT_IRQn, ADCC_INT1_IRQn, ADCC_INT2_IRQn, ADCC_INT3_IRQn, ADCC_INT4_IRQn },
    { ADCD_EVT_IRQn, ADCD_INT1_IRQn, ADCD_INT2_IRQn, ADCD_INT3_IRQn, ADCD_INT4_IRQn },
};
/*! \brief ADC Interrupt Callback function */
static ADC_Int_Callback_t s_adcISR = { NULL };

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void GetAdcTrimBaseEflash(ADC_Type *base)
{
    /* Check the arguments. */
    assert(ADC_isBaseValid(base));

#ifdef BOARD_CALIBRATION
    uint32_t baseoffset = 0;
    uint32_t checkdata  = 0;

    CALIB_getAdcCalibration((uint8_t *)&checkdata, 0, sizeof(uint32_t));

    if(checkdata == 0x55aa55aa)
    {
        if(base == ADCA)
        {
            baseoffset = 4;
        }
        else if(base == ADCB)
        {
            baseoffset = 4+ sizeof(ADC_EflashTrimValue_t);
        }
        else if(base == ADCC)
        {
            baseoffset = 4 + sizeof(ADC_EflashTrimValue_t) * 2;
        }
        else if(base == ADCD)
        {
            baseoffset = 4 + sizeof(ADC_EflashTrimValue_t) * 3;
        }
        CALIB_getAdcCalibration((uint8_t *)&adcEflashTrimValue, baseoffset, sizeof(ADC_EflashTrimValue_t));
    }
    else
#endif
    {
        adcEflashTrimValue.gainerrSingle12bit = 0;
        adcEflashTrimValue.offsetSingle12bit = 0;
        adcEflashTrimValue.gainerrSingle16bit = 0;
        adcEflashTrimValue.offsetSingle16bit = 0;
        adcEflashTrimValue.gainerrDiff16bit = 0;
        adcEflashTrimValue.offsetDiff16bit = 0;
        adcEflashTrimValue.linearValue0 = 0;
        adcEflashTrimValue.linearValue1 = 0;
        adcEflashTrimValue.linearValue2 = 0;
        adcEflashTrimValue.linearValue3 = 0;
        adcEflashTrimValue.linearValue4 = 0;
    }
}

ADC_Idx_t adc_getInstance(ADC_Type *adc_base)
{
    ADC_Idx_t instance;

    assert(ADC_isBaseValid(adc_base));
    if (adc_base == ADCA)
    {
        instance = kADCA;
    }
    else if (adc_base == ADCB)
    {
        instance = kADCB;
    }
    else if (adc_base == ADCC)
    {
        instance = kADCC;
    }
    else
    {
        instance = kADCD;
    }

    return instance;
}

void ADC_setOffsetTrim(ADC_Type *base)
{
    uint32_t gain = 0;
    uint32_t offset = 0;
    uint32_t resolution = 0;
    uint32_t adcmode = 0;

    /* Check the arguments. */
    assert(ADC_isBaseValid(base));

    resolution = ADC_ADCCTL2_RESOLUTION_Get(base->ADCCTL2);
    adcmode = ADC_ADCCTL2_SIGNALMODE_Get(base->ADCCTL2);

    if(adcEflashTrimValue.gainerrSingle12bit != 0)
    {
        if((resolution + adcmode) == 0)
        {
            gain = adcEflashTrimValue.gainerrSingle12bit;
            offset = adcEflashTrimValue.offsetSingle12bit & 0xffff; 
        }
        else if((resolution + adcmode) == 1)
        {
            gain = adcEflashTrimValue.gainerrSingle16bit;
            offset = adcEflashTrimValue.offsetSingle16bit & 0xffff; 
        }
        else if((resolution + adcmode) == 2)
        {
            gain = adcEflashTrimValue.gainerrDiff16bit;
            offset = adcEflashTrimValue.offsetDiff16bit & 0xffff; 
        }
        else
        {
            gain = adcEflashTrimValue.gainerrSingle12bit;
            offset = adcEflashTrimValue.offsetSingle12bit & 0xffff; 
        }
    }
    else
    {
        gain = 0x10000;
        offset = 0;
    }
    assert((gain > 0 * 65536) && (gain < 2 * 65536));

    base->ADCGAINERR = ADC_ADCGAINERR_GAINERR_Set(gain);
    base->ADCOFFTRIM = ADC_ADCOFFTRIM_OFFTRIM_Set(offset);

}

void ADC_setINLTrim(ADC_Type *base)
{
    uint32_t linear[6] = {0};
    uint32_t i;


    /* Check the arguments. */
    assert(ADC_isBaseValid(base));

    /* Calculate the index into eflash table of offset trims
     * load the correct linear trim */
    if(adcEflashTrimValue.linearValue0 != 0)
    {
        linear[0] = adcEflashTrimValue.linearValue0;
        linear[1] = adcEflashTrimValue.linearValue1;
        linear[2] = adcEflashTrimValue.linearValue2;
        linear[3] = adcEflashTrimValue.linearValue3;
        linear[4] = adcEflashTrimValue.linearValue4;
    }
    else
    {
        for(i = 0; i < 6; i++)
        {
            linear[i] = linearDefault[i];
        }
    }
        base->ADCINLTRIM1 = ADC_ADCINLTRIM1_INLTRIM31TO0_Set(linear[0]);
        base->ADCINLTRIM2 = ADC_ADCINLTRIM2_INLTRIM63TO32_Set(linear[1]);
        base->ADCINLTRIM3 = ADC_ADCINLTRIM3_INLTRIM95TO64_Set(linear[2]);
        base->ADCINLTRIM4 = ADC_ADCINLTRIM4_INLTRIM127TO96_Set(linear[3]);
        base->ADCINLTRIM5 = ADC_ADCINLTRIM5_INLTRIM159TO128_Set(linear[4]);
        base->ADCINLTRIM6 = ADC_ADCINLTRIM6_INLTRIM191TO160_Set(0);
}

void ADC_setMode(ADC_Type *base, ADC_Resolution_t resolution, ADC_SignalMode_t signalMode)
{
    uint32_t data;

    /* Check the arguments. */
    assert(ADC_isBaseValid(base));

    /* Check for correct signal mode & resolution. In this device:
     * Single ended signal conversions are supported in 12-bit mode only
     * Differential signal conversions are supported in 16-bit mode only */
    if (signalMode == kADC_MODE_DIFFERENTIAL)
    {
        assert(resolution == kADC_RESOLUTION_16BIT);
    }

    /* Apply the resolution and signalMode to the specified ADC. */
    data          = ADC_ADCCTL2_RESOLUTION_Set(resolution)
                   | ADC_ADCCTL2_SIGNALMODE_Set(signalMode);
    base->ADCCTL2 = data;

    /* Apply INL and offset trims */
    GetAdcTrimBaseEflash(base);
    ADC_setINLTrim(base);
    ADC_setOffsetTrim(base);
}

void ADC_setPPBTripLimits(ADC_Type *base, ADC_PPBNumber_t ppbNumber, int32_t tripHiLimit, int32_t tripLoLimit)
{
    /* Check the arguments. */
    assert(ADC_isBaseValid(base));
    assert((tripHiLimit <= PPB_LIMIT_MAX) && (tripHiLimit >= PPB_LIMIT_MIN));
    assert((tripLoLimit <= PPB_LIMIT_MAX) && (tripLoLimit >= PPB_LIMIT_MIN));

    /* Set the trip high limit. */
    base->ADCPPBCREG[ppbNumber].PPBTRIPHI =
        (base->ADCPPBCREG[ppbNumber].PPBTRIPHI & (~ADC_PPBTRIPHI_LIMITHI_Msk)) | ADC_PPBTRIPHI_LIMITHI_Set(tripHiLimit);

    /* Set the trip low limit. */
    base->ADCPPBCREG[ppbNumber].PPBTRIPLO =
        (base->ADCPPBCREG[ppbNumber].PPBTRIPLO & (~ADC_PPBTRIPLO_LIMITLO_Msk)) | ADC_PPBTRIPLO_LIMITLO_Set(tripLoLimit);
}

/*!
 * \brief ADC Handler IRQ
 *
 * \details called the handler func depending on the intsrc
 *
 * \param[in] adc_idx is the index for ADC
 *
 * \param[in] intsrc is the index for ADC IRQ
 */
void ADC_handlerIRQ(ADC_Idx_t adc_idx, ADC_Irq_Idx_t intsrc)
{
    if (s_adcISR.func[adc_idx][intsrc] != NULL)
    {
        s_adcISR.func[adc_idx][intsrc](adc_idx, intsrc);
    }
}

/*!
 * \brief  ADCA Event DriverHandler
 *
 * \details ADCA Event DriverHandler function
 *
 */
void ADCA_EVT_DriverHandler(void)
{
    ADC_handlerIRQ(kADCA, kADC_EVT_IRQn);
    ISR_EXIT_BARRIER();
}

/*!
 * \brief  ADCB Event DriverHandler
 *
 * \details ADCB Event DriverHandler function
 *
 */
void ADCB_EVT_DriverHandler(void)
{
    ADC_handlerIRQ(kADCB, kADC_EVT_IRQn);
    ISR_EXIT_BARRIER();
}

/*!
 * \brief  ADCC Event DriverHandler
 *
 * \details ADCC Event DriverHandler function
 *
 */
void ADCC_EVT_DriverHandler(void)
{
    ADC_handlerIRQ(kADCC, kADC_EVT_IRQn);
    ISR_EXIT_BARRIER();
}

/*!
 * \brief  ADCD Event DriverHandler
 *
 * \details ADCD Event DriverHandler function
 *
 */
void ADCD_EVT_DriverHandler(void)
{
    ADC_handlerIRQ(kADCD, kADC_EVT_IRQn);
    ISR_EXIT_BARRIER();
}

/*!
 * \brief  ADCA INT1 DriverHandler
 *
 * \details ADCA INT1 DriverHandler function
 *
 */
void ADCA_INT1_DriverHandler(void)
{
    ADC_handlerIRQ(kADCA, kADC_INT1_IRQn);
    ISR_EXIT_BARRIER();
}

/*!
 * \brief  ADCA INT2 DriverHandler
 *
 * \details ADCA INT2 DriverHandler function
 *
 */
void ADCA_INT2_DriverHandler(void)
{
    ADC_handlerIRQ(kADCA, kADC_INT2_IRQn);
    ISR_EXIT_BARRIER();
}

/*!
 * \brief  ADCA INT3 DriverHandler
 *
 * \details ADCA INT3 DriverHandler function
 *
 */
void ADCA_INT3_DriverHandler(void)
{
    ADC_handlerIRQ(kADCA, kADC_INT3_IRQn);
    ISR_EXIT_BARRIER();
}

/*!
 * \brief  ADCA INT4 DriverHandler
 *
 * \details ADCA INT4 DriverHandler function
 *
 */
void ADCA_INT4_DriverHandler(void)
{
    ADC_handlerIRQ(kADCA, kADC_INT4_IRQn);
    ISR_EXIT_BARRIER();
}

/*!
 * \brief  ADCB INT1 DriverHandler
 *
 * \details ADCB INT1 DriverHandler function
 *
 */
void ADCB_INT1_DriverHandler(void)
{
    ADC_handlerIRQ(kADCB, kADC_INT1_IRQn);
    ISR_EXIT_BARRIER();
}

/*!
 * \brief  ADCB INT2 DriverHandler
 *
 * \details ADCB INT2 DriverHandler function
 *
 */
void ADCB_INT2_DriverHandler(void)
{
    ADC_handlerIRQ(kADCB, kADC_INT2_IRQn);
    ISR_EXIT_BARRIER();
}

/*!
 * \brief  ADCB INT3 DriverHandler
 *
 * \details ADCB INT3 DriverHandler function
 *
 */
void ADCB_INT3_DriverHandler(void)
{
    ADC_handlerIRQ(kADCB, kADC_INT3_IRQn);
    ISR_EXIT_BARRIER();
}

/*!
 * \brief  ADCB INT4 DriverHandler
 *
 * \details ADCB INT4 DriverHandler function
 *
 */
void ADCB_INT4_DriverHandler(void)
{
    ADC_handlerIRQ(kADCB, kADC_INT4_IRQn);
    ISR_EXIT_BARRIER();
}

/*!
 * \brief  ADCC INT1 DriverHandler
 *
 * \details ADCC INT1 DriverHandler function
 *
 */
void ADCC_INT1_DriverHandler(void)
{
    ADC_handlerIRQ(kADCC, kADC_INT1_IRQn);
    ISR_EXIT_BARRIER();
}

/*!
 * \brief  ADCC INT2 DriverHandler
 *
 * \details ADCC INT2 DriverHandler function
 *
 */
void ADCC_INT2_DriverHandler(void)
{
    ADC_handlerIRQ(kADCC, kADC_INT2_IRQn);
    ISR_EXIT_BARRIER();
}

/*!
 * \brief  ADCC INT3 DriverHandler
 *
 * \details ADCC INT3 DriverHandler function
 *
 */
void ADCC_INT3_DriverHandler(void)
{
    ADC_handlerIRQ(kADCC, kADC_INT3_IRQn);
    ISR_EXIT_BARRIER();
}

/*!
 * \brief  ADCC INT4 DriverHandler
 *
 * \details ADCC INT4 DriverHandler function
 *
 */
void ADCC_INT4_DriverHandler(void)
{
    ADC_handlerIRQ(kADCC, kADC_INT4_IRQn);
    ISR_EXIT_BARRIER();
}

/*!
 * \brief  ADCD INT1 DriverHandler
 *
 * \details ADCD INT1 DriverHandler function
 *
 */
void ADCD_INT1_DriverHandler(void)
{
    ADC_handlerIRQ(kADCD, kADC_INT1_IRQn);
    ISR_EXIT_BARRIER();
}

/*!
 * \brief  ADCD INT2 DriverHandler
 *
 * \details ADCD INT2 DriverHandler function
 *
 */
void ADCD_INT2_DriverHandler(void)
{
    ADC_handlerIRQ(kADCD, kADC_INT2_IRQn);
    ISR_EXIT_BARRIER();
}

/*!
 * \brief  ADCD INT3 DriverHandler
 *
 * \details ADCD INT3 DriverHandler function
 *
 */
void ADCD_INT3_DriverHandler(void)
{
    ADC_handlerIRQ(kADCD, kADC_INT3_IRQn);
    ISR_EXIT_BARRIER();
}

/*!
 * \brief  ADCD INT4 DriverHandler
 *
 * \details ADCD INT4 DriverHandler function
 *
 */
void ADCD_INT4_DriverHandler(void)
{
    ADC_handlerIRQ(kADCD, kADC_INT4_IRQn);
    ISR_EXIT_BARRIER();
}

status_t ADC_registerCallback(ADC_Type *base, ADC_Irq_Idx_t intsrc, ADC_Callback_t func, uint32_t priority)
{
    ADC_Idx_t adc_index;

    assert(ADC_isBaseValid(base));
    assert(intsrc < kADC_IRQ_MAX_NUM);
    assert(func);

    adc_index = adc_getInstance(base);

    if (s_adcISR.func[adc_index][intsrc] != NULL)
    {
        /* ADC ISR callback has been registered already, return failure */
        return kSTATUS_FAIL;
    }

    /* Enable the driver interrupt service */
    s_adcISR.func[adc_index][intsrc] = func;

    /* Set interrupt priority and enable the interrupt */
    NVIC_SetPriority(ADC_IRQ[adc_index][intsrc], priority);
    NVIC_EnableIRQ(ADC_IRQ[adc_index][intsrc]);

    return kSTATUS_SUCCESS;
}

status_t ADC_unregisterCallback(ADC_Type *base, ADC_Irq_Idx_t intsrc)
{
    ADC_Idx_t adc_index;

    assert(ADC_isBaseValid(base));
    assert(intsrc < kADC_IRQ_MAX_NUM);
    adc_index = adc_getInstance(base);

    if (s_adcISR.func[adc_index][intsrc] == NULL)
    {
        /* ADC callback hasn't been registered, return failure */
        return kSTATUS_INVALID_ARGUMENT;
    }

    /* Restore interrupt priority and disable the interrupt */
    NVIC_SetPriority(ADC_IRQ[adc_index][intsrc], 0U);
    NVIC_DisableIRQ(ADC_IRQ[adc_index][intsrc]);

    /* Clear the interrupt service and handle */
    s_adcISR.func[adc_index][intsrc] = NULL;

    return kSTATUS_SUCCESS;
}
