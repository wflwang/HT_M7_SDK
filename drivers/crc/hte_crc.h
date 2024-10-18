/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_crc.h
 * \brief SDK CRC driver header file
 * \version 1.0.0
 */

#ifndef HTE_CRC_H
#define HTE_CRC_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_common.h"

/*!
 * \addtogroup DRV_HTE_CRC CRC Driver
 *
 * \brief SDK CRC drivers
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * \brief Values that can be passed to CRC_setPositionCounterConfig() as the \e mode
 * parameter.
 */

/*!
 * \brief Enum to represent the sizes of CRC polynomials
 */
typedef enum
{
    kCRC_POLY32_SIZE = 0x0, /*!< 32-bit CRC polynomial size */
    kCRC_POLY24_SIZE = 0x1, /*!< 24-bit CRC polynomial size */
    kCRC_POLY16_SIZE = 0x2, /*!< 16-bit CRC polynomial size */
    kCRC_POLY8_SIZE  = 0x4, /*!< 8-bit CRC polynomial size */
    kCRC_POLY7_SIZE  = 0x6, /*!< 7-bit CRC polynomial size */
} CRC_PolySize_t;


/*!
 * \brief Enum to represent the input data reversal formats for CRC calculation  
 */
typedef enum
{
    kCRC_REVINPUT_FORMAT_UNDEFINED = 0x0, /*!< Undefined input data reversal format */
    kCRC_REVINPUT_FORMAT_BYTE      = 0x1, /*!< Byte-wise input data reversal format */
    kCRC_REVINPUT_FORMAT_HALFWORD  = 0x2, /*!< Half-word-wise input data reversal format */
    kCRC_REVINPUT_FORMAT_WORD      = 0x3, /*!< Word-wise input data reversal format */
} CRC_RevInput_t;


/*!
 * \brief Enum to enable or disable byte-wise reversal for CRC calculation  
 */
typedef enum
{
    kCRC_BYTE_REVERSE_DISABLE = 0x0, /*!< Disable byte-wise reversal for CRC input data */
    kCRC_BYTE_REVERSE_ENABLE  = 0x1, /*!< Enable byte-wise reversal for CRC input data */
} CRC_RevByte_t;


/*!
 * \brief Enum to enable or disable the reversal of the CRC output  
 */
typedef enum
{
    kCRC_OUT_REVERSE_DISABLE = 0x0, /*!< Disable reversal of the CRC output */
    kCRC_OUT_REVERSE_ENABLE  = 0x1, /*!< Enable reversal of the CRC output */
} CRC_RevOut_t;

/*!
 * \brief Enum to represent the input data formats for CRC calculation
 */
typedef enum  
{
    kCRC_INPUT_FORMAT_BYTE     = 0x1, /*!< Byte-wise input data format for CRC calculation */
    kCRC_INPUT_FORMAT_HALFWORD = 0x2, /*!< Half-word-wise input data format for CRC calculation */
    kCRC_INPUT_FORMAT_WORD     = 0x3, /*!< Word-wise input data format for CRC calculation */
} CRC_Input_t;

/*!
 * \brief Structure to hold the initialization parameters for CRC calculation
 */
typedef struct  
{
    uint32_t       initValue;       /*!< Initial value for the CRC calculation */
    uint32_t       poly;            /*!< Polynomial value used for the CRC calculation */
    CRC_PolySize_t polySize;        /*!< Size of the CRC polynomial */
    CRC_RevInput_t revInput;        /*!< Format for reversing the input data */
    CRC_RevByte_t  revByte;         /*!< Enable/disable byte-wise reversal of the input data */
    CRC_RevOut_t   revOut;          /*!< Enable/disable reversal of the CRC output */
    CRC_Input_t    inputDataFormat; /*!< Format of the input data for CRC calculation */
} CRC_InitParams_t;

/*******************************************************************************
 * APIs
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*!  
 * \brief Byte swap a 16-bit unsigned integer  
 *  
 * \details This function swaps the byte order of a 16-bit unsigned integer.  
 *           It is useful for converting between big-endian and little-endian formats.  
 *  
 * \param[in] x The 16-bit unsigned integer to be byte swapped  
 *  
 * \return The byte swapped 16-bit unsigned integer  
 */ 
static inline uint16_t bswap_16(uint16_t x)
{
    return ((x & 0x00FF) << 8) | ((x & 0xFF00) >> 8);
}


/*!  
 * \brief Byte swap a 32-bit unsigned integer
 *  
 * \details This function swaps the byte order of a 32-bit unsigned integer.
 *           It is useful for converting between big-endian and little-endian formats.
 *  
 * \param[in] x The 32-bit unsigned integer to be byte swapped  
 *  
 * \return The byte swapped 32-bit unsigned integer  
 */
static inline uint32_t bswap_32(uint32_t x)
{
    return ((x & 0xFF000000) >> 24) | ((x & 0x00FF0000) >> 8) | ((x & 0x0000FF00) << 8) | ((x & 0x000000FF) << 24);
}


/*!  
 * \brief Reset CRC
 *  
 * \details This function resets the CRC to its initial state, clearing any previously computed CRC value.
 *  
 * \param[in] base CRC base address  
 */ 
void     CRC_reset(CRC_Type *base);


/*!
 * \brief Initialize CRC
 *
 * \details This function initialize the CRC according to the specified parameters in the CRC_InitParams_t.
 *
 * \param[in] base CRC base address
 * \param[in] initPara CRC configuration
 */
void     CRC_init(CRC_Type *base, CRC_InitParams_t *initPara);


/*!
 * \brief Compute the CRC value of a data buffer with previously computed CRC value
 *
 * \details Compute the 7, 8, 16,24 or 32-bit CRC value of an 8, 16 or 32-bit data buffer
 *         starting with the previously computed CRC as initialization value.
 *
 * \param[in] base CRC base address
 * \param[in] data ointer to the input data buffer, exact input data format is
 *         provided by initPara->inputDataFormat.
 * \param[in] length input data buffer length (number of bytes if pBuffer
 *         type is * uint8_t, number of half-words if pBuffer type is * uint16_t,
 *         number of words if pBuffer type is * uint32_t).
 *
 * \retval uint32_t CRC (returned value LSBs for CRC shorter than 32 bits)
 */
uint32_t CRC_accumulate(CRC_Type *base, uint32_t *data, uint32_t length);


/*!
 * \brief Compute the CRC value of a data buffer
 *
 * \details Compute the 7, 8, 16,24 or 32-bit CRC value of an 8, 16 or 32-bit data buffer
 *         starting with base->CRC_INIT as initialization value.
 *
 * \param[in] base CRC base address
 * \param[in] data ointer to the input data buffer, exact input data format is
 *         provided by initPara->inputDataFormat.
 * \param[in] length input data buffer length (number of bytes if pBuffer
 *         type is * uint8_t, number of half-words if pBuffer type is * uint16_t,
 *         number of words if pBuffer type is * uint32_t).
 *
 * \retval uint32_t CRC (returned value LSBs for CRC shorter than 32 bits)
 */
uint32_t CRC_calculte(CRC_Type *base, uint32_t *data, uint32_t length);

/*!
 * \brief Similar to CRC_accumulate(), but with faster execution speed.
 *
 * \details Compute 32-bit CRC value of an 32-bit data buffer
 *         starting with the previously computed CRC as initialization value.
 *
 * \param[in] base CRC base address
 * \param[in] data ointer to the input data buffer, Only supports input data of type uint32_t.
 * \param[in] length input data buffer length (number of words when pBuffer type is * uint32_t).
 *
 * \retval uint32_t CRC (returned value LSBs for CRC shorter than 32 bits)
 */
uint32_t CRC_accumulate_fast(CRC_Type *base, uint32_t *data, uint32_t length);

/*!
 * \brief Similar to CRC_calculate(), but with faster execution speed.
 *
 * \details Compute 32-bit CRC value of an 32-bit data buffer
 *         starting with the previously computed CRC as initialization value.
 *
 * \param[in] base CRC base address
 * \param[in] data ointer to the input data buffer, Only supports input data of type uint32_t.
 * \param[in] length input data buffer length (number of words when pBuffer type is * uint32_t).
 *
 * \retval uint32_t CRC (returned value LSBs for CRC shorter than 32 bits)
 */
uint32_t CRC_calculte_fast(CRC_Type *base, uint32_t *data, uint32_t length);

 
#ifdef __cplusplus
}
#endif

/*!
 * @}
 */ /* end of DRV_HTE_CRC */

#endif /* HTE_CRC_H */
