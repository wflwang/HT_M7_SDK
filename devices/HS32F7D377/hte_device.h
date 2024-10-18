/*
 * Copyright 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_device.h
 * \brief Device header file
 * \version 1.0.1
 */

#ifndef HTE_DEVICE_H
#define HTE_DEVICE_H

/*!
 * \addtogroup HS32F7D377 HS32F7D377
 *
 * \brief HS32F7D377 device definition
 *
 * @{
 */


#if defined(HTE_DEVICE_HS32F7D377_CPU1)

/* CMSIS-style register definitions */
#include "HS32F7D377_cpu1.h"
/* Device-specific feature definitions */
#include "HS32F7D377_cpu1_features.h"
/* Device-specific array definitions */
#include "HS32F7D377_cpu1_arrays.h"

#elif defined(HTE_DEVICE_HS32F7D377_CPU2)

/* CMSIS-style register definitions */
#include "HS32F7D377_cpu2.h"
/* Device-specific feature definitions */
#include "HS32F7D377_cpu2_features.h"
/* Device-specific array definitions */
#include "HS32F7D377_cpu2_arrays.h"

#else
#error "Invalid Watech Electronics device defined"
#endif

/*!
 * @}
 */ /* end of HS32F7D377 */

#endif /* HTE_DEVICE_H */
