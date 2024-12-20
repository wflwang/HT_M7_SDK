/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*!
 * \file hte_epwm.c
 * \brief SDK EPWM driver source file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_epwm.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* No Definitions */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/* No Prototypes */

/*******************************************************************************
 * Variables
 ******************************************************************************/
/* No Variables */

/*******************************************************************************
 * Codes
 ******************************************************************************/
//*****************************************************************************
//
// EPWM_setEmulationMode
//
//*****************************************************************************
void EPWM_setEmulationMode(EPWM_REGS_Type *base, EPWM_EmulationMode emulationMode)
{
   /* Check the arguments. */
   assert(EPWM_isBaseValid(base));

   /* Write to FREE_SOFT bits */
   base->TBCTL = EPWM_REGS_TBCTL_FREE_SOFT_Set(emulationMode);
}