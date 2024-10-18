/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*!
 * \file hte_eqep.c
 * \brief SDK EQEP driver source file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_eqep.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* No Definitions */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!  
 * \brief Handles the interrupt request for the EQEP module  
 *  
 * \param[in] intsrc Interrupt source enumeration value that indicates the Index of EQEP module.
 * \param[in] base is the base address of the EQEP module.
 *
 */
static void EQEP_handlerIRQ(EQEP_IntSrc_t intsrc,EQEP_REGS_Type *base);


/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! \brief Array of EQEP ISR */
static EQEP_Int_Callback_t s_eqepISR = { 0 };
/*! \brief Array of EQEP IRQ number */
static const IRQn_Type s_eqepIRQ[kEQEP_INT_MAX] = EQEP_IRQS;

/*******************************************************************************
 * Codes
 ******************************************************************************/

void EQEP_setCompareConfig(EQEP_REGS_Type *base, uint16_t config, uint32_t compareValue, uint16_t cycles)
{
    uint16_t regValue;

    /* Check the arguments.*/
    assert(EQEP_isBaseValid(base));
    assert(cycles <= (EQEP_QPOSCTL_PCSPW_Msk + 1U));

    /* Set the compare match value*/
    base->QPOSCMP = compareValue;

    /* Set the shadow register settings and pulse width. */
    regValue = (config & (uint16_t)(EQEP_QPOSCTL_PCSHDW_Msk | EQEP_QPOSCTL_PCLOAD_Msk)) | (cycles - 1U);

    base->QPOSCTL =
        (base->QPOSCTL & ~(EQEP_QPOSCTL_PCSPW_Msk | EQEP_QPOSCTL_PCLOAD_Msk | EQEP_QPOSCTL_PCSHDW_Msk)) | regValue;

    /* Set position compare sync-output mode.*/
    regValue = config & (uint16_t)(EQEP_QDECCTL_SOEN_Msk | EQEP_QDECCTL_SPSEL_Msk);

    base->QDECCTL = (base->QDECCTL & ~(EQEP_QDECCTL_SOEN_Msk | EQEP_QDECCTL_SPSEL_Msk)) | regValue;
}

void EQEP_setInputPolarity(EQEP_REGS_Type *base, bool invertQEPA, bool invertQEPB, bool invertIndex, bool invertStrobe)
{
    /* Check the arguments.*/
    assert(EQEP_isBaseValid(base));

    /* Configure QEPA signal*/
    if (invertQEPA)
    {
        base->QDECCTL |= EQEP_QDECCTL_QAP_Msk;
    }
    else
    {
        base->QDECCTL &= ~EQEP_QDECCTL_QAP_Msk;
    }

    /* Configure QEPB signal*/
    if (invertQEPB)
    {
        base->QDECCTL |= EQEP_QDECCTL_QBP_Msk;
    }
    else
    {
        base->QDECCTL &= ~EQEP_QDECCTL_QBP_Msk;
    }

    /* Configure index signal*/
    if (invertIndex)
    {
        base->QDECCTL |= EQEP_QDECCTL_QIP_Msk;
    }
    else
    {
        base->QDECCTL &= ~EQEP_QDECCTL_QIP_Msk;
    }

    /* Configure strobe signal*/
    if (invertStrobe)
    {
        base->QDECCTL |= EQEP_QDECCTL_QSP_Msk;
    }
    else
    {
        base->QDECCTL &= ~EQEP_QDECCTL_QSP_Msk;
    }
}


status_t EQEP_registerCallback(EQEP_REGS_Type *base, EQEP_Callback_t func, uint32_t priority)
{
    EQEP_IntSrc_t intsrc = kEQEP1_INT;
        
    assert(intsrc < kEQEP_INT_MAX);
    assert(func);

    if(base == EQEP1)
    {
        intsrc = kEQEP1_INT;
    }
    else if(base == EQEP2)
    {
        intsrc  = kEQEP2_INT;
    }
    else
    {
        intsrc = kEQEP3_INT;
    }

    if (s_eqepISR.func[intsrc] != NULL)
    {
        /* EQEP ISR callback has been registered already, return failure */
        return kSTATUS_FAIL;
    }

    /* Enable the driver interrupt service */
    s_eqepISR.func[intsrc] = func;
    
    /* Set interrupt priority and enable the interrupt */
    NVIC_SetPriority(s_eqepIRQ[intsrc], priority);
    NVIC_EnableIRQ(s_eqepIRQ[intsrc]);

    return kSTATUS_SUCCESS;
}

status_t EQEP_unregisterCallback(EQEP_REGS_Type *base)
{
    EQEP_IntSrc_t intsrc = kEQEP1_INT;

    assert(intsrc < kEQEP_INT_MAX);

    if(base == EQEP1)
    {
        intsrc = kEQEP1_INT;
    }
    else if(base == EQEP2)
    {
        intsrc  = kEQEP2_INT;
    }
    else
    {
        intsrc = kEQEP3_INT;
    }

    if (s_eqepISR.func[intsrc] == NULL)
    {
        /* EQEP instance hasn't been registered, return failure */
        return kSTATUS_INVALID_ARGUMENT;
    }

    /* Restore interrupt priority and disable the interrupt */
    NVIC_SetPriority(s_eqepIRQ[intsrc], 0U);
    NVIC_DisableIRQ(s_eqepIRQ[intsrc]);

    /* Clear the interrupt service and handle */
    s_eqepISR.func[intsrc] = NULL;

    return kSTATUS_SUCCESS;
}

static void EQEP_handlerIRQ(EQEP_IntSrc_t intsrc,EQEP_REGS_Type *base)
{
    if (s_eqepISR.func[intsrc] != NULL)
    {
        s_eqepISR.func[intsrc](base);
    }
}

#if defined(EQEP1)
void EQEP1_DriverHandler(void)
{
    EQEP_handlerIRQ(kEQEP1_INT,EQEP1);
    ISR_EXIT_BARRIER();
}
#endif

#if defined(EQEP2)
void EQEP2_DriverHandler(void)
{
    EQEP_handlerIRQ(kEQEP2_INT,EQEP2);
    ISR_EXIT_BARRIER();
}
#endif

#if defined(EQEP3)
void EQEP3_DriverHandler(void)
{
    EQEP_handlerIRQ(kEQEP3_INT,EQEP3);
    ISR_EXIT_BARRIER();
}
#endif

