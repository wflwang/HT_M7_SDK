/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*!
 * \file hte_sdfm.c
 * \brief SDK SDFM driver source file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_sdfm.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! \brief Get filter oversampling ratio */
#define SDFM_GET_OSR(C) ((C) >> 8U)

/*! \brief Maximum acceptable comparator filter oversampling ratio */
#define SDFM_MAX_COMP_FILTER_OSR 31U

/*! \brief Maximum acceptable data filter oversampling ratio */
#define SDFM_MAX_DATA_FILTER_OSR 255U

/*! \brief Get the filter type */
#define SDFM_GET_FILTER_TYPE(C) ((C)&0x30U)

/*! \brief Get the filter number */
#define SDFM_GET_FILTER_NUMBER(C) ((C)&0x3U)

/*! \brief Get the zero-crossing high threshold */
#define SDFM_GET_ZHIGH_THRESHOLD(C)  ((C) & 0x7FFFU))

/*! \brief Mask for enabling the zero-crossing high threshold */
#define SDFM_ZHIGH_ENABLE_MASK 0x8000U

/*! \brief Get data shift value */
#define SDFM_GET_SHIFT_VALUE(C) (((C) >> 2U) & 0x1FU)

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*!  
 * \brief SDFM Interrupt Handler  
 *  
 * \param[in] idx The index of the SDFM device.  
 * \param[in] intsrc The interrupt source that triggered the ISR.
 * \param[in] base specifies the SDFM module base address.
 *
 */
static void SDFM_handlerIRQ(SDFM_Idx_t idx,SDFM_IntSrc_t intsrc,SDFM_REGS_Type *base);


/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! \brief Array of SDFM ISR */
static SDFM_Int_Callback_t s_sdfmISR = { 0 };
/*! \brief Array of SDFM IRQ number */
static const IRQn_Type s_sdfmIRQ[kSDFM_IDX_MAX][kSDFM_INT_MAX] = SDFM_IRQS;



/*******************************************************************************
 * Codes
 ******************************************************************************/


void SDFM_configComparatorAll(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber, SDFM_Comparator_t *pcfg_cmp)
{
    SDFM_setComparatorFilterType(base, filterNumber, pcfg_cmp->type);

    SDFM_setCompFilterOverSamplingRatio(base, filterNumber, pcfg_cmp->cosr);

    /* Set the comparator high threshold value */
    SDFM_setCompFilterHighThreshold(base, filterNumber, pcfg_cmp->hthresh.all);

    /* Set the comparator low threshold value */
    SDFM_setCompFilterLowThreshold(base, filterNumber, pcfg_cmp->lthresh.all);

    /* If requested, enable and set the zero-cross high threshold value */
    if (pcfg_cmp->zcrsthreshold.b.en == 1)
    {
        SDFM_setCompFilterZeroCrossThreshold(base, filterNumber, pcfg_cmp->zcrsthreshold.b.zcth);
        SDFM_enableZeroCrossEdgeDetect(base, filterNumber);
    }
}

void SDFM_configDataFilterAll(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber, SDFM_Datafilter_t *pcfg_data)
{
    /* Set the filter type */
    SDFM_setFilterType(base, filterNumber, pcfg_data->type);

    /* Set the comparator filter type */
    SDFM_setupModulatorClock(base, filterNumber, pcfg_data->mod);

    /* Set the comparator filter over sampling ratio */
    SDFM_setFilterOverSamplingRatio(base, filterNumber, pcfg_data->dosr);

    /* If filter switch on */
    if (pcfg_data->flten == 1U)
    {
        SDFM_enableFilter(base, filterNumber);
    }
    else
    {
        SDFM_disableFilter(base, filterNumber);
    }

    /* Set output data format */
    SDFM_setOutputDataFormat(base, filterNumber, pcfg_data->format);

    /* Set the shift value if data is in 16-bit 2's complement format */
    if (pcfg_data->format == kSDFM_DATA_FORMAT_16_BIT)
    {
        SDFM_setDataShiftValue(base, filterNumber, pcfg_data->shift);
    }
}

void SDFM_configFIFO(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber, SDFM_FIFO_t *pcfg_fifo)
{
    /* Set the FIFO level */
    if (pcfg_fifo->en == 1U)
    {
        SDFM_setFIFOInterruptLevel(base, filterNumber, pcfg_fifo->ilevel);
        SDFM_enableFIFOBuffer(base, filterNumber);
    }
    else
    {
        SDFM_disableFIFOBuffer(base, filterNumber);
    }
}

void SDFM_configDma(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber, SDFM_Dma_t *pcfg_dma)
{
    if (pcfg_dma->en == 1U)
    {
        if (pcfg_dma->dmasrc == kSDFM_DATA_READY_DMA_SOURCE_DIRECT)
        {
            SDFM_enableDMA(base, filterNumber);
        }
        else
        {
            SDFM_enableFIFODMA(base, filterNumber);
        }
        SDFM_setDataReadyDMASource(base, filterNumber, pcfg_dma->dmasrc);
    }
    else
    {
        if (pcfg_dma->dmasrc == kSDFM_DATA_READY_DMA_SOURCE_DIRECT)
        {
            SDFM_disableDMA(base, filterNumber);
        }
        else
        {
            SDFM_disableFIFODMA(base, filterNumber);
        }
    }
}

void SDFM_configCompEventFilter(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber,
                                SDFM_CpeventFilter_t *pcfg_cpevent_flt)
{
    uint16_t *ptr;

    if (pcfg_cpevent_flt->en == 0U)
    {
        return;
    }

    assert(SDFM_isBaseValid(base));
    assert(pcfg_cpevent_flt->clkPrescale <= SDFM_SDCOMP1EVT1FLTCLKCTL_CLKPRESCALE_Msk);
    assert((pcfg_cpevent_flt->sampWin - 1U) <=
           (SDFM_SDCOMP1EVT1FLTCTL_SAMPWIN_Msk >> SDFM_SDCOMP1EVT1FLTCTL_SAMPWIN_Pos));
    assert(pcfg_cpevent_flt->threshold <= (SDFM_SDCOMP1EVT1FLTCTL_THRESH_Msk >> SDFM_SDCOMP1EVT1FLTCTL_THRESH_Pos));
    assert(pcfg_cpevent_flt->threshold > ((pcfg_cpevent_flt->sampWin - 1U) / 2U));

    if (pcfg_cpevent_flt->event == kSDFM_COMP_LOWEVENT)
    {
        ptr = (uint16_t *)&(base->SDCOMP1EVT2FLTCTL) + ((uint32_t)filterNumber * 8U);

        /* Configure sample window & threshold. */
        *ptr = (*ptr & ~(SDFM_COMPEVT_FILTER_CONFIG_M)) |
               (((pcfg_cpevent_flt->sampWin - 1U) << SDFM_SDCOMP1EVT2FLTCTL_SAMPWIN_Pos) |
                (pcfg_cpevent_flt->threshold << SDFM_SDCOMP1EVT2FLTCTL_THRESH_Pos));

        /* Configure clock pre-scale. */
        ptr  = (uint16_t *)&(base->SDCOMP1EVT2FLTCLKCTL) + ((uint32_t)filterNumber * 8U);
        *ptr = (*ptr & ~(SDFM_SDCOMP1EVT2FLTCLKCTL_CLKPRESCALE_Msk)) | (pcfg_cpevent_flt->clkPrescale);
    }

    if (pcfg_cpevent_flt->event == kSDFM_COMP_HIGHEVENT)
    {
        ptr = (uint16_t *)&(base->SDCOMP1EVT1FLTCTL) + ((uint32_t)filterNumber * 8U);

        /* Configure sample window & threshold. */
        *ptr = (*ptr & ~(SDFM_COMPEVT_FILTER_CONFIG_M)) |
               (((pcfg_cpevent_flt->sampWin - 1U) << SDFM_SDCOMP1EVT1FLTCTL_SAMPWIN_Pos) |
                (pcfg_cpevent_flt->threshold << SDFM_SDCOMP1EVT1FLTCTL_THRESH_Pos));

        /* Configure clock pre-scale. */
        ptr  = (uint16_t *)&(base->SDCOMP1EVT1FLTCLKCTL) + ((uint32_t)filterNumber * 8U);
        *ptr = (*ptr & ~(SDFM_SDCOMP1EVT1FLTCLKCTL_CLKPRESCALE_Msk)) | (pcfg_cpevent_flt->clkPrescale);
    }
}

void SDFM_configComparator(SDFM_REGS_Type *base, uint16_t config1, uint32_t config2, uint16_t config3)
{
    SDFM_FilterNumber_t filter;
    uint16_t            ratio;
    SDFM_FilterType_t   filterType;

    filter     = (SDFM_FilterNumber_t)(SDFM_GET_FILTER_NUMBER(config1));
    ratio      = SDFM_GET_OSR(config1);
    filterType = (SDFM_FilterType_t)SDFM_GET_FILTER_TYPE(config1);

    /* Limit the oversampling ratio */
    if (ratio > SDFM_MAX_COMP_FILTER_OSR)
    {
        ratio = SDFM_MAX_COMP_FILTER_OSR;
    }

    /* Set the comparator filter type */
    SDFM_setComparatorFilterType(base, filter, filterType);

    /* Set the comparator filter over sampling ratio */
    SDFM_setCompFilterOverSamplingRatio(base, filter, ratio);

    /* Set the comparator high threshold value */
    SDFM_setCompFilterHighThreshold(base, filter, SDFM_GET_HIGH_THRESHOLD(config2));

    /* Set the comparator low threshold value */
    SDFM_setCompFilterLowThreshold(base, filter, SDFM_GET_LOW_THRESHOLD(config2));


    /* If requested, enable and set the zero-cross high threshold value */
    if ((config3 & SDFM_ZHIGH_ENABLE_MASK) != 0U)
    {
        SDFM_setCompFilterZeroCrossThreshold(base, filter,
                                             SDFM_GET_ZHIGH_THRESHOLD(config3);
        SDFM_enableZeroCrossEdgeDetect(base, filter);
    }
}

void SDFM_configEnhancedComparator(SDFM_REGS_Type *base, uint16_t filterConfig, uint32_t highLowThreshold1,
                                   uint32_t highLowThreshold2, uint16_t zeroCrossThreshold)
{
    SDFM_FilterNumber_t filter;
    uint16_t            ratio;
    SDFM_FilterType_t   filterType;

    filter     = (SDFM_FilterNumber_t)(SDFM_GET_FILTER_NUMBER(filterConfig));
    ratio      = SDFM_GET_OSR(filterConfig);
    filterType = (SDFM_FilterType_t)SDFM_GET_FILTER_TYPE(filterConfig);

    /* Limit the oversampling ratio */
    if (ratio > SDFM_MAX_COMP_FILTER_OSR)
    {
        ratio = SDFM_MAX_COMP_FILTER_OSR;
    }

    /* Set the comparator filter type */
    SDFM_setComparatorFilterType(base, filter, filterType);

    /* Set the comparator filter over sampling ratio */
    SDFM_setCompFilterOverSamplingRatio(base, filter, ratio);

    /* Set the comparator high threshold value */
    SDFM_setCompFilterHighThreshold(base, filter, SDFM_GET_HIGH_THRESHOLD_BOTH(highLowThreshold1, highLowThreshold2));

    /* Set the comparator low threshold value */
    SDFM_setCompFilterLowThreshold(base, filter, SDFM_GET_LOW_THRESHOLD_BOTH(highLowThreshold1, highLowThreshold2));

    /* If requested, enable and set the zero-cross high threshold value */
    if ((zeroCrossThreshold & SDFM_ZHIGH_ENABLE_MASK) != 0U)
    {
        SDFM_setCompFilterZeroCrossThreshold(base, filter,
                                  SDFM_GET_ZHIGH_THRESHOLD(zeroCrossThreshold);
        SDFM_enableZeroCrossEdgeDetect(base, filter);
    }
}

void SDFM_configDataFilter(SDFM_REGS_Type *base, uint16_t config1, uint16_t config2)
{
    SDFM_FilterNumber_t filter;
    uint16_t            ratio;
    SDFM_FilterType_t   filterType;

    filter     = (SDFM_FilterNumber_t)(SDFM_GET_FILTER_NUMBER(config1));
    ratio      = SDFM_GET_OSR(config1);
    filterType = (SDFM_FilterType_t)SDFM_GET_FILTER_TYPE(config1);

    /* Limit the oversampling ratio */
    if (ratio > SDFM_MAX_DATA_FILTER_OSR)
    {
        ratio = SDFM_MAX_DATA_FILTER_OSR;
    }

    /* Set the comparator filter type */
    SDFM_setFilterType(base, filter, filterType);

    /* Set the comparator filter over sampling ratio */
    SDFM_setFilterOverSamplingRatio(base, filter, ratio);

    /* If filter switch on */
    if ((config2 & SDFM_FILTER_ENABLE) == SDFM_FILTER_ENABLE)
    {
        SDFM_enableFilter(base, filter);
    }
    else
    {
        SDFM_disableFilter(base, filter);
    }

    /* Set output data format */
    SDFM_setOutputDataFormat(base, filter, (SDFM_OutputDataFormat_t)(config2 & 0x1U));

    /* Set the shift value if data is in 16-bit 2's complement format */
    if ((config2 & 0x1U) == (uint16_t)(kSDFM_DATA_FORMAT_16_BIT))
    {
        SDFM_setDataShiftValue(base, filter, SDFM_GET_SHIFT_VALUE(config2));
    }
}

void SDFM_configZeroCrossComparator(SDFM_REGS_Type *base, uint16_t config1, uint16_t config2)
{
    SDFM_FilterNumber_t filter;
    uint16_t            ratio;
    SDFM_FilterType_t   filterType;

    filter     = (SDFM_FilterNumber_t)(SDFM_GET_FILTER_NUMBER(config1));
    ratio      = SDFM_GET_OSR(config1);
    filterType = (SDFM_FilterType_t)SDFM_GET_FILTER_TYPE(config1);

    /* Limit the oversampling ratio */
    if (ratio > SDFM_MAX_COMP_FILTER_OSR)
    {
        ratio = SDFM_MAX_COMP_FILTER_OSR;
    }

    /* Set the comparator filter type */
    SDFM_setComparatorFilterType(base, filter, filterType);

    /* Set the comparator filter over sampling ratio */
    SDFM_setCompFilterOverSamplingRatio(base, filter, ratio);

    /* Set the zero cross threshold value */
    SDFM_setCompFilterZeroCrossThreshold(base, filter, config2);
}

void SDFM_configDataFilterFIFO(SDFM_REGS_Type *base, uint16_t config1, uint16_t config2)
{
    SDFM_FilterNumber_t filter;
    uint16_t            ratio;
    uint16_t            fifoLevel;
    SDFM_FilterType_t   filterType;

    filter     = (SDFM_FilterNumber_t)(SDFM_GET_FILTER_NUMBER(config1));
    fifoLevel  = ((config2 >> 7U) & 0x1FU);
    ratio      = SDFM_GET_OSR(config1);
    filterType = (SDFM_FilterType_t)SDFM_GET_FILTER_TYPE(config1);

    /* Limit the oversampling ratio */
    if (ratio > SDFM_MAX_DATA_FILTER_OSR)
    {
        ratio = SDFM_MAX_DATA_FILTER_OSR;
    }

    /* Set the comparator filter type */
    SDFM_setFilterType(base, filter, filterType);

    /* Set the comparator filter over sampling ratio */
    SDFM_setFilterOverSamplingRatio(base, filter, ratio);

    /* If filter switch on */
    if ((config2 & SDFM_FILTER_ENABLE) == SDFM_FILTER_ENABLE)
    {
        SDFM_enableFilter(base, filter);
    }
    else
    {
        SDFM_disableFilter(base, filter);
    }

    /* Set output data format */
    SDFM_setOutputDataFormat(base, filter, (SDFM_OutputDataFormat_t)(config2 & 0x1U));

    /* Set the shift value if data is in 16bit 2's complement format */
    if ((config2 & 0x1U) == (uint16_t)(kSDFM_DATA_FORMAT_16_BIT))
    {
        SDFM_setDataShiftValue(base, filter, SDFM_GET_SHIFT_VALUE(config2));
    }

    /* Set the FIFO level */
    SDFM_setFIFOInterruptLevel(base, filter, fifoLevel);
    SDFM_enableFIFOBuffer(base, filter);
}

void SDFM_configCompEventLowFilter(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber,
                                   const SDFM_CompEventFilterConfig_t *config)
{
    uint16_t *ptr;
    assert(SDFM_isBaseValid(base));
    assert(config->clkPrescale <= SDFM_SDCOMP1EVT2FLTCLKCTL_CLKPRESCALE_Msk);
    assert((config->sampleWindow - 1U) <= (SDFM_SDCOMP1EVT2FLTCTL_SAMPWIN_Msk >> SDFM_SDCOMP1EVT2FLTCTL_SAMPWIN_Pos));
    assert(config->threshold <= (SDFM_SDCOMP1EVT2FLTCTL_THRESH_Msk >> SDFM_SDCOMP1EVT2FLTCTL_THRESH_Pos));
    assert(config->threshold > ((config->sampleWindow - 1U) / 2U));

    ptr = (uint16_t *)&(base->SDCOMP1EVT2FLTCTL) + ((uint32_t)filterNumber * 8U);

    /* Configure sample window & threshold. */
    *ptr = (*ptr & ~(SDFM_COMPEVT_FILTER_CONFIG_M)) |
           (((config->sampleWindow - 1U) << SDFM_SDCOMP1EVT2FLTCTL_SAMPWIN_Pos) |
            (config->threshold << SDFM_SDCOMP1EVT2FLTCTL_THRESH_Pos));

    /* Configure clock pre-scale. */
    ptr  = (uint16_t *)&(base->SDCOMP1EVT2FLTCLKCTL) + ((uint32_t)filterNumber * 8U);
    *ptr = (*ptr & ~(SDFM_SDCOMP1EVT2FLTCLKCTL_CLKPRESCALE_Msk)) | (config->clkPrescale);
}

void SDFM_configCompEventHighFilter(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber,
                                    const SDFM_CompEventFilterConfig_t *config)
{
    uint16_t *ptr;
    assert(SDFM_isBaseValid(base));
    assert(config->clkPrescale <= SDFM_SDCOMP1EVT1FLTCLKCTL_CLKPRESCALE_Msk);
    assert((config->sampleWindow - 1U) <= (SDFM_SDCOMP1EVT1FLTCTL_SAMPWIN_Msk >> SDFM_SDCOMP1EVT1FLTCTL_SAMPWIN_Pos));
    assert(config->threshold <= (SDFM_SDCOMP1EVT1FLTCTL_THRESH_Msk >> SDFM_SDCOMP1EVT1FLTCTL_THRESH_Pos));
    assert(config->threshold > ((config->sampleWindow - 1U) / 2U));

    ptr = (uint16_t *)&(base->SDCOMP1EVT1FLTCTL) + ((uint32_t)filterNumber * 8U);

    /* Configure sample window & threshold. */
    *ptr = (*ptr & ~(SDFM_COMPEVT_FILTER_CONFIG_M)) |
           (((config->sampleWindow - 1U) << SDFM_SDCOMP1EVT1FLTCTL_SAMPWIN_Pos) |
            (config->threshold << SDFM_SDCOMP1EVT1FLTCTL_THRESH_Pos));

    /* Configure clock pre-scale. */
    ptr  = (uint16_t *)&(base->SDCOMP1EVT1FLTCLKCTL) + ((uint32_t)filterNumber * 8U);
    *ptr = (*ptr & ~(SDFM_SDCOMP1EVT1FLTCLKCTL_CLKPRESCALE_Msk)) | (config->clkPrescale);
}


status_t SDFM_registerCallback(SDFM_REGS_Type *base,SDFM_IntSrc_t intsrc, SDFM_Callback_t func, uint32_t priority)
{
    SDFM_Idx_t idx = kSDFM_IDX_1;
    
    assert(intsrc < kSDFM_INT_MAX);
    assert(func);

    idx = ((base == SDFM2)?kSDFM_IDX_2:kSDFM_IDX_1);

    if (s_sdfmISR.func[idx][intsrc] != NULL)
    {
        /* SDFM ISR callback has been registered already, return failure */
        return kSTATUS_FAIL;
    }

    /* Enable the driver interrupt service */
    s_sdfmISR.func[idx][intsrc] = func;
    
    /* Set interrupt priority and enable the interrupt */
    NVIC_SetPriority(s_sdfmIRQ[idx][intsrc], priority);
    NVIC_EnableIRQ(s_sdfmIRQ[idx][intsrc]);

    return kSTATUS_SUCCESS;
}

status_t SDFM_unregisterCallback(SDFM_REGS_Type *base,SDFM_IntSrc_t intsrc)
{
    SDFM_Idx_t idx = kSDFM_IDX_1;

    assert(intsrc < kSDFM_INT_MAX);

    idx = ((base == SDFM2)?kSDFM_IDX_2:kSDFM_IDX_1);

    if (s_sdfmISR.func[idx][intsrc] == NULL)
    {
        /* SDFM instance hasn't been registered, return failure */
        return kSTATUS_INVALID_ARGUMENT;
    }

    /* Restore interrupt priority and disable the interrupt */
    NVIC_SetPriority(s_sdfmIRQ[idx][intsrc], 0U);
    NVIC_DisableIRQ(s_sdfmIRQ[idx][intsrc]);

    /* Clear the interrupt service and handle */
    s_sdfmISR.func[idx][intsrc] = NULL;

    return kSTATUS_SUCCESS;
}

static void SDFM_handlerIRQ(SDFM_Idx_t idx,SDFM_IntSrc_t intsrc,SDFM_REGS_Type *base)
{
    if (s_sdfmISR.func[idx][intsrc] != NULL)
    {
        s_sdfmISR.func[idx][intsrc](base);
    }
}


#if defined(SDFM1)
void SDFM1_DriverHandler(void)
{
    SDFM_handlerIRQ(kSDFM_IDX_1,kSDFM_INT,SDFM1);
    ISR_EXIT_BARRIER();
}

void SDFM1_FLT1DR_DriverHandler(void)
{
    SDFM_handlerIRQ(kSDFM_IDX_1,kSDFM_DR_INT1,SDFM1);

    ISR_EXIT_BARRIER();
}

void SDFM1_FLT2DR_DriverHandler(void)
{
    SDFM_handlerIRQ(kSDFM_IDX_1,kSDFM_DR_INT2,SDFM1);
    ISR_EXIT_BARRIER();
}

void SDFM1_FLT3DR_DriverHandler(void)
{
    SDFM_handlerIRQ(kSDFM_IDX_1,kSDFM_DR_INT3,SDFM1);
    ISR_EXIT_BARRIER();
}

void SDFM1_FLT4DR_DriverHandler(void)
{
    SDFM_handlerIRQ(kSDFM_IDX_1,kSDFM_DR_INT4,SDFM1);
    ISR_EXIT_BARRIER();
}
#endif

#if defined(SDFM2)
void SDFM2_DriverHandler(void)
{
    SDFM_handlerIRQ(kSDFM_IDX_2,kSDFM_INT,SDFM2);
    ISR_EXIT_BARRIER();
}

void SDFM2_FLT1DR_DriverHandler(void)
{
    SDFM_handlerIRQ(kSDFM_IDX_2,kSDFM_DR_INT1,SDFM2);
    ISR_EXIT_BARRIER();
}

void SDFM2_FLT2DR_DriverHandler(void)
{
    SDFM_handlerIRQ(kSDFM_IDX_2,kSDFM_DR_INT2,SDFM2);
    ISR_EXIT_BARRIER();
}

void SDFM2_FLT3DR_DriverHandler(void)
{
    SDFM_handlerIRQ(kSDFM_IDX_2,kSDFM_DR_INT3,SDFM2);
    ISR_EXIT_BARRIER();
}

void SDFM2_FLT4DR_DriverHandler(void)
{
    SDFM_handlerIRQ(kSDFM_IDX_2,kSDFM_DR_INT4,SDFM2);
    ISR_EXIT_BARRIER();
}
#endif
