/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_dma.c
 * \brief SDK DMA driver source file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "hte_dma.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* No Definitions*/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/* No Prototypes */

/*******************************************************************************
 * Variables
 ******************************************************************************/
static DMA_Int_Callback_t s_dmaISR = { 0 }; /*!<dma int callback function */

/*! \brief Array of DMA IRQ number */
static const IRQn_Type s_dmaIRQ[] = DMA_IRQS; /*!<dma int req num */

/*******************************************************************************
 * Codes
 ******************************************************************************/

void DMA_initialize(void)
{
    DMA_initController();
    DMA_setEmulationMode(kDMA_EMULATION_FREE_RUN);
}

void DMA_configAddresses(DMA_Index_t index, const void *destAddr, const void *srcAddr)
{
    //
    // Check the arguments.
    //
    assert(DMA_isChValid(index));
    //
    // Set up SOURCE address.
    //
    DMA->CHANNEL[index].CH_SRC_BEG_ADDR_SHADOW = (uint32_t)srcAddr;
    DMA->CHANNEL[index].CH_SRC_ADDR_SHADOW     = (uint32_t)srcAddr;

    //
    // Set up DESTINATION address.
    //
    DMA->CHANNEL[index].CH_DST_BEG_ADDR_SHADOW = (uint32_t)destAddr;
    DMA->CHANNEL[index].CH_DST_ADDR_SHADOW     = (uint32_t)destAddr;
}

void DMA_configBurst(DMA_Index_t index, uint16_t size, int16_t srcStep, int16_t destStep)
{
    //
    // Check the arguments.
    //
    assert(DMA_isChValid(index));
    assert((size >= 1U) || (size <= 32U));
    //
    // Set up BURST registers.
    //
    DMA->CHANNEL[index].CH_BURST_SET &= ~DMA_CH_BURST_SET_BURST_SIZE_Msk;
    DMA->CHANNEL[index].CH_BURST_SET |= DMA_CH_BURST_SET_BURST_SIZE_Set(size - 1U);

    DMA->CHANNEL[index].CH_SRC_BURST_STEP &= ~DMA_CH_SRC_BURST_STEP_SRC_BURST_STEP_Msk;
    DMA->CHANNEL[index].CH_SRC_BURST_STEP |= DMA_CH_SRC_BURST_STEP_SRC_BURST_STEP_Set(srcStep);

    DMA->CHANNEL[index].CH_DST_BURST_STEP &= ~DMA_CH_DST_BURST_STEP_DST_BURST_STEP_Msk;
    DMA->CHANNEL[index].CH_DST_BURST_STEP |= DMA_CH_DST_BURST_STEP_DST_BURST_STEP_Set(destStep);
}

void DMA_configTransfer(DMA_Index_t index, uint32_t transferSize, int16_t srcStep, int16_t destStep)
{
    //
    // Check the arguments.
    //
    assert(DMA_isChValid(index));
    assert(transferSize <= DMA_SIZE_MAX);

    //
    // Set up TRANSFER registers.
    //
    DMA->CHANNEL[index].CH_TRANSFER_SET &= ~DMA_CH_TRANSFER_SET_TRANS_SIZE_Msk;
    DMA->CHANNEL[index].CH_TRANSFER_SET |= DMA_CH_TRANSFER_SET_TRANS_SIZE_Set(transferSize - 1U);

    DMA->CHANNEL[index].CH_SRC_TRANSFER_STEP &= ~DMA_CH_SRC_TRANSFER_STEP_SRC_TRANS_STEP_Msk;
    DMA->CHANNEL[index].CH_SRC_TRANSFER_STEP |= DMA_CH_SRC_TRANSFER_STEP_SRC_TRANS_STEP_Set(srcStep);

    DMA->CHANNEL[index].CH_DST_TRANSFER_STEP &= ~DMA_CH_DST_TRANSFER_STEP_DST_TRANS_STEP_Msk;
    DMA->CHANNEL[index].CH_DST_TRANSFER_STEP |= DMA_CH_DST_TRANSFER_STEP_DST_TRANS_STEP_Set(destStep);
}

void DMA_configWrap(DMA_Index_t index, uint32_t srcWrapSize, int16_t srcStep, uint32_t destWrapSize, int16_t destStep)
{
    //
    // Check the arguments.
    //
    assert(DMA_isChValid(index));
    assert((srcWrapSize <= MAX_DMA_WRAP_LEN) || (destWrapSize <= MAX_DMA_WRAP_LEN));
    //
    // Set up WRAP registers.
    //
    DMA->CHANNEL[index].CH_SRC_WRAP_SET &= ~DMA_CH_SRC_WRAP_SET_SRC_WRAP_SIZE_Msk;
    DMA->CHANNEL[index].CH_SRC_WRAP_SET |= DMA_CH_SRC_WRAP_SET_SRC_WRAP_SIZE_Set(srcWrapSize - 1U);

    DMA->CHANNEL[index].CH_SRC_WRAP_STEP &= ~DMA_CH_SRC_WRAP_STEP_SRC_WRAP_STEP_Msk;
    DMA->CHANNEL[index].CH_SRC_WRAP_STEP |= DMA_CH_SRC_WRAP_STEP_SRC_WRAP_STEP_Set(srcStep);

    DMA->CHANNEL[index].CH_DST_WRAP_SET &= ~DMA_CH_DST_WRAP_SET_DST_WRAP_SIZE_Msk;
    DMA->CHANNEL[index].CH_DST_WRAP_SET |= DMA_CH_DST_WRAP_SET_DST_WRAP_SIZE_Set(destWrapSize - 1U);

    DMA->CHANNEL[index].CH_DST_WRAP_STEP &= ~DMA_CH_DST_WRAP_STEP_DST_WRAP_STEP_Msk;
    DMA->CHANNEL[index].CH_DST_WRAP_STEP |= DMA_CH_DST_WRAP_STEP_DST_WRAP_STEP_Set(destStep);
}

void DMA_configMode(DMA_Index_t index, DMA_CfgMode_t mode)
{
    //
    // Check the arguments.
    //
    assert(DMA_isChValid(index));

    DMA->CHANNEL[index].CH_CFG &= ~DMA_CH_CFG_ONESHOT_Msk;
    DMA->CHANNEL[index].CH_CFG &= ~DMA_CH_CFG_CONTINUOUS_Msk;

    if ((mode == kDMA_MODE_ONESHOT) || (mode == kDMA_MODE_ONESHOT_CONTINUOUS))
        DMA->CHANNEL[index].CH_CFG |= DMA_CH_CFG_ONESHOT_Set(0x01U);

    if ((mode == kDMA_MODE_CONTINUOUS) || (mode == kDMA_MODE_ONESHOT_CONTINUOUS))
        DMA->CHANNEL[index].CH_CFG |= DMA_CH_CFG_CONTINUOUS_Set(0x01U);
}

status_t DMA_registerCallback(DMA_IntSrc_t intsrc, DMA_Callback_t callback, uint32_t priority)
{
    assert(intsrc < kDMA_CH_INT_MAX);
    assert(callback);

    if (s_dmaISR.func[intsrc] != NULL)
    {
        /* DMA ISR callback has been registered already, return failure */
        return kSTATUS_FAIL;
    }

    /* Enable the driver interrupt service */
    s_dmaISR.func[intsrc] = callback;

    /* Set interrupt priority and enable the interrupt */
    NVIC_SetPriority(s_dmaIRQ[intsrc], priority);
    NVIC_EnableIRQ(s_dmaIRQ[intsrc]);

    return kSTATUS_SUCCESS;
}

status_t DMA_unregisterCallback(DMA_IntSrc_t intsrc)
{
    assert(intsrc < kDMA_CH_INT_MAX);

    if (s_dmaISR.func[intsrc] == NULL)
    {
        /* UART instance hasn't been registered, return failure */
        return kSTATUS_INVALID_ARGUMENT;
    }

    /* Restore interrupt priority and disable the interrupt */
    NVIC_SetPriority(s_dmaIRQ[intsrc], 0U);
    NVIC_DisableIRQ(s_dmaIRQ[intsrc]);

    /* Clear the interrupt service and handle */
    s_dmaISR.func[intsrc] = NULL;

    return kSTATUS_SUCCESS;
}

/*!
 * \brief call the user callback function
 *
 * \details This function call the registered user callback function
 *
 * \param[in] intsrc the DMA INT index
 * \param[in] index the DMA index
 */
static void DMA_handlerIRQ(DMA_IntSrc_t intsrc, DMA_Index_t index)
{
    if (s_dmaISR.func[intsrc] != NULL)
    {
        s_dmaISR.func[intsrc](index);
    }
}

/*!
 * \brief call the dma ch1 callback function
 *
 * \details This function call the registered dma ch1 callback function
 *
 */
void DMA_CH1_DriverHandler(void)
{
    DMA_handlerIRQ(kDMA_CH1_INT, kDMA_INDEX_CH1);
    ISR_EXIT_BARRIER();
}

/*!
 * \brief call the dma ch2 callback function
 *
 * \details This function call the registered dma ch2 callback function
 *
 */
void DMA_CH2_DriverHandler(void)
{
    DMA_handlerIRQ(kDMA_CH2_INT, kDMA_INDEX_CH2);
    ISR_EXIT_BARRIER();
}

/*!
 * \brief call the dma ch3 callback function
 *
 * \details This function call the registered dma ch3 callback function
 *
 */
void DMA_CH3_DriverHandler(void)
{
    DMA_handlerIRQ(kDMA_CH3_INT, kDMA_INDEX_CH3);
    ISR_EXIT_BARRIER();
}

/*!
 * \brief call the dma ch4 callback function
 *
 * \details This function call the registered dma ch4 callback function
 *
 */
void DMA_CH4_DriverHandler(void)
{
    DMA_handlerIRQ(kDMA_CH4_INT, kDMA_INDEX_CH4);
    ISR_EXIT_BARRIER();
}

/*!
 * \brief call the dma ch5 callback function
 *
 * \details This function call the registered dma ch5 callback function
 *
 */
void DMA_CH5_DriverHandler(void)
{
    DMA_handlerIRQ(kDMA_CH5_INT, kDMA_INDEX_CH5);
    ISR_EXIT_BARRIER();
}

/*!
 * \brief call the dma ch6 callback function
 *
 * \details This function call the registered dma ch6 callback function
 *
 */
void DMA_CH6_DriverHandler(void)
{
    DMA_handlerIRQ(kDMA_CH6_INT, kDMA_INDEX_CH6);
    ISR_EXIT_BARRIER();
}
