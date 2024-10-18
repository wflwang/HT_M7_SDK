/*
 * Copyright 2023 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_emif.c
 * \brief SDK EMIF driver source file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_emif.h"

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! \brief EMIF IRQ ARRAY */
static const IRQn_Type EMIF_IRQ[kEMIF_MAX][kEMIF_IRQ_MAX_NUM] = {EMIF1_ERR_IRQn};
/*! \brief EMIF Interrupt Callback function */
static EMIF_Int_Callback_t s_emifISR = { NULL };


/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * \brief EMIF get instance
 *
 * \details get emif instance index
 *
 * \param[in] emif_base EMIF base address 
 */
EMIF_Idx_t EMIF_getInstance(EMIF_Type *emif_base)
{
    uint32_t instance = 0U;

    assert(EMIF_isBaseValid(emif_base));
    if (emif_base ==EMIF1)
    {
        instance = kEMIF1;
    }
    else
    {
        instance = kEMIF1;
    }

    return instance;
}

/*!
 * \brief EMIF Handler IRQ
 *
 * \details called the handler func depending on the intsrc
 *
 * \param[in] EMIF_idx is the index for EMIF
 *
 * \param[in] intsrc is the index for EMIF IRQ
 */
void EMIF_handlerIRQ(EMIF_Idx_t EMIF_idx, EMIF_Irq_Idx_t intsrc)
{
    if (s_emifISR.func[EMIF_idx][intsrc] != NULL)
    {
        s_emifISR.func[EMIF_idx][intsrc]();
    }
}

/*!
 * \brief  EMIF Event DriverHandler
 *
 * \details EMIF Event DriverHandler function
 *
 */
void EMIF_EVT_DriverHandler(void)
{
    EMIF_handlerIRQ(kEMIF1, kEMIF1_EVT_IRQn);
    ISR_EXIT_BARRIER();
}

status_t EMIF_registerCallback(EMIF_Type *base, EMIF_Irq_Idx_t intsrc, EMIF_Callback_t func, uint32_t priority)
{
    EMIF_Idx_t EMIF_index = 0;

    assert(EMIF_isBaseValid(base));
    assert(intsrc < kEMIF_IRQ_MAX_NUM);
    assert(func);

    EMIF_index = EMIF_getInstance(base);

    if (s_emifISR.func[EMIF_index][intsrc] != NULL)
    {
        /* EMIF ISR callback has been registered already, return failure */
        return kSTATUS_FAIL;
    }

    /* Enable the driver interrupt service */
    s_emifISR.func[EMIF_index][intsrc] = func;

    /* Set interrupt priority and enable the interrupt */
    NVIC_SetPriority(EMIF_IRQ[EMIF_index][intsrc], priority);
    NVIC_EnableIRQ(EMIF_IRQ[EMIF_index][intsrc]);

    return kSTATUS_SUCCESS;
}

status_t EMIF_unregisterCallback(EMIF_Type *base, EMIF_Irq_Idx_t intsrc)
{
    EMIF_Idx_t EMIF_index = 0;

    assert(EMIF_isBaseValid(base));
    assert(intsrc < kEMIF_IRQ_MAX_NUM);
    EMIF_index = EMIF_getInstance(base);

    if (s_emifISR.func[EMIF_index][intsrc] == NULL)
    {
        /* EMIF callback hasn't been registered, return failure */
        return kSTATUS_INVALID_ARGUMENT;
    }

    /* Restore interrupt priority and disable the interrupt */
    NVIC_SetPriority(EMIF_IRQ[EMIF_index][intsrc], 0U);
    NVIC_DisableIRQ(EMIF_IRQ[EMIF_index][intsrc]);

    /* Clear the interrupt service and handle */
    s_emifISR.func[EMIF_index][intsrc] = NULL;

    return kSTATUS_SUCCESS;
}

