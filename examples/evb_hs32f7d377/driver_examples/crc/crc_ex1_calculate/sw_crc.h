/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
 
/*!
 * \file sw_crc.h
 * \brief SDK CRC software header file
 * \version 1.0.0
 */

#ifndef SW_CRC_H
#define SW_CRC_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_crc.h"

/*!
 * \addtogroup SW_CRC
 *
 * \brief CRC TEST
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * APIs
 ******************************************************************************/
void CRC_swSetInitVal(uint32_t val);
uint32_t CRC_software_calculate(CRC_Type *crcx, uint8_t indata[], uint32_t datalen,bool acc);

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif

/*
 * @}
 */ /* end of SW_CRC_H */

#endif /* HTE_COMMON_H */
