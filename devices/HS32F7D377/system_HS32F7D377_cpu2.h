/*
 * Copyright 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file system_HS32F7D377_cpu2.h
 * \brief HS32F7D377 CPU2 system header file
 * \version 1.0.1
 */

#ifndef SYSTEM_HS32F7D377_CPU2_H
#define SYSTEM_HS32F7D377_CPU2_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdint.h>

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! \brief Exception / Interrupt Handler Function Prototype */
typedef void (*VECTOR_TABLE_Type)(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! \brief System Clock Frequency (Core Clock) */
extern uint32_t SystemCoreClock;

/*******************************************************************************
 * APIs
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/*!
 * \brief Setup the microcontroller system
 *
 * \details Initialize the System and update the SystemCoreClock variable
 */
void SystemInit(void);

/*!
 * \brief Update SystemCoreClock variable
 *
 * \details Updates the SystemCoreClock with current core Clock retrieved from CPU registers
 */
void SystemCoreClockUpdate(void);

#ifdef __cplusplus
}
#endif

#endif /* SYSTEM_HS32F7D377_CPU2_H */
