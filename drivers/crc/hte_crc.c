/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*!
 * \file hte_crc.c
 * \brief SDK CRC driver source file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_crc.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! Static var to store CRC input data format for sharing across program parts */
static CRC_Input_t inputDataFormat;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
#ifdef DEBUG
/*!  
 * \brief Check if the CRC base address is valid  
 *  
 * \details This function checks if the provided CRC base address pointer is equal to the predefined  
 * CRC base address. It is used to validate the pointer to ensure correct access to the CRC hardware.  
 *  
 * \param[in] base Pointer to the CRC base address  
 *  
 * \return true if the base address is valid, false otherwise  
 */  
static bool CRC_isBaseValid(CRC_Type *base);
#endif

/*!  
 * \brief Set the CRC input data format  
 *  
 * \details This function sets the input data format for the CRC operation.  
 * The input data format specifies how the data is fed into the CRC algorithm.  
 *  
 * \param[in] format CRC input data format enumeration value  
 *  
 * \note This function assumes that there is a global or static variable named 'inputDataFormat'  
 *       to store the input data format setting.  
 */  
static void CRC_setInputDataFormat(CRC_Input_t format);

/*!  
 * \brief Handle CRC calculation for 8-bit data  
 *  
 * \details This function handles the CRC calculation for an array of 8-bit data.  
 * It feeds the data into the CRC hardware in 32-bit chunks (if possible) and  
 * handles any remaining bytes less than 32 bits.  
 *  
 * \param[in] base Pointer to the CRC hardware base address  
 * \param[in] data Pointer to the data array to be processed by the CRC  
 * \param[in] length Length of the data array in bytes  
 *  
 * \return The calculated CRC value  
 *  
 * \note This function assumes that the CRC hardware is already properly initialized  
 *       and that the CRC_DR and CRC_RR registers are accessible through the provided base pointer.  
 */
static uint32_t CRC_Handle_8(CRC_Type *base, uint8_t *data, uint32_t length);

/*!  
 * \brief Handle CRC calculation for 16-bit data  
 *  
 * \details This function handles the CRC calculation for an array of 16-bit data.  
 * It feeds the data into the CRC hardware in 32-bit chunks (if possible) and  
 * handles any remaining 16-bit data.  
 *  
 * \param[in] base Pointer to the CRC hardware base address  
 * \param[in] data Pointer to the data array to be processed by the CRC  
 * \param[in] length Length of the data array in 16-bit words  
 *  
 * \return The calculated CRC value  
 *  
 * \note This function assumes that the CRC hardware is already properly initialized  
 *       and that the CRC_DR and CRC_RR registers are accessible through the provided base pointer.  
 *       Additionally, it uses the 'bswap_16' function to byte-swap the 16-bit data before feeding it to the CRC algorithm.  
 *       This is typically done if the CRC algorithm expects data in a different endianness than the source data.  
 */
static uint32_t CRC_Handle_16(CRC_Type *base, uint16_t *data, uint32_t length);

/*******************************************************************************
 * Variables
 ******************************************************************************/


/*******************************************************************************
 * Codes
 ******************************************************************************/
#ifdef DEBUG
static bool CRC_isBaseValid(CRC_Type *base)  
{  
    return (base == CRC); // Assuming 'CRC' is a predefined global variable or macro representing the CRC base address  
}
#endif

static void CRC_setInputDataFormat(CRC_Input_t format)  
{  
    inputDataFormat = format;  
}


static uint32_t CRC_Handle_8(CRC_Type *base, uint8_t *data, uint32_t length)
{
    uint32_t       i;
    uint16_t       temp;
    __IO uint16_t *pReg;


    for (i = 0U; i < (length / 4U); i++)
    {
        base->CRC_DR = ((uint32_t)data[4U * i]) | ((uint32_t)data[(4U * i) + 1U] << 8U) |
                       ((uint32_t)data[(4U * i) + 2U] << 16U) | ((uint32_t)data[(4U * i) + 3U] << 24U);
    }

    if ((length % 4U) != 0U)
    {
        if ((length % 4U) == 1U)
        {
            *(__IO uint8_t *)(__IO void *)(&base->CRC_DR) = data[4U * i];
        }
        if ((length % 4U) == 2U)
        {
            temp  = ((uint16_t)(data[4U * i])) | ((uint16_t)data[(4U * i) + 1U] << 8U);
            pReg  = (__IO uint16_t *)(__IO void *)(&base->CRC_DR);
            *pReg = temp;
        }
        if ((length % 4U) == 3U)
        {
            temp  = ((uint16_t)(data[4U * i])) | ((uint16_t)data[(4U * i) + 1U] << 8U);
            pReg  = (__IO uint16_t *)(__IO void *)(&base->CRC_DR);
            *pReg = temp;

            *(__IO uint8_t *)(__IO void *)(&base->CRC_DR) = data[(4U * i) + 2U];
        }
    }

    return base->CRC_RR;
}

static uint32_t CRC_Handle_16(CRC_Type *base, uint16_t *data, uint32_t length)
{
    uint32_t       i; /* input data buffer index */
    __IO uint16_t *pReg;

    for (i = 0U; i < (length / 2U); i++)
    {
        base->CRC_DR = ((uint32_t)bswap_16(data[2U * i])) | ((uint32_t)bswap_16(data[(2U * i) + 1U]) << 16U);
    }
    if ((length % 2U) != 0U)
    {
        pReg  = (__IO uint16_t *)(__IO void *)(&base->CRC_DR);
        *pReg = bswap_16(data[2U * i]);
    }

    return base->CRC_RR;
}


void CRC_reset(CRC_Type *base)
{
    assert(CRC_isBaseValid(base));

    base->CRC_CFG |= CRC_CRC_CFG_CRC_RESET_Msk;
}

void CRC_init(CRC_Type *base, CRC_InitParams_t *initPara)
{
    assert(CRC_isBaseValid(base));

    CRC_reset(base);

    base->CRC_INIT = initPara->initValue;
    base->CRC_POLY = initPara->poly;

    base->CRC_CFG = (base->CRC_CFG & ~(CRC_CRC_CFG_CRC_REV_OUT_Msk | CRC_CRC_CFG_CRC_REV_BYTE_Msk |
                                       CRC_CRC_CFG_CRC_REV_IN_Msk | CRC_CRC_CFG_CRC_POLYSIZE_Msk)) |
                    CRC_CRC_CFG_CRC_REV_OUT_Set(initPara->revOut) | CRC_CRC_CFG_CRC_REV_BYTE_Set(initPara->revByte) |
                    CRC_CRC_CFG_CRC_REV_IN_Set(initPara->revInput) | CRC_CRC_CFG_CRC_POLYSIZE_Set(initPara->polySize);

    CRC_setInputDataFormat(initPara->inputDataFormat);
}

uint32_t CRC_accumulate(CRC_Type *base, uint32_t *data, uint32_t length)
{
    uint32_t index;     /* CRC input data buffer index */
    uint32_t temp = 0U; /* CRC output (read from base->CRC_DR register) */

    switch (inputDataFormat)
    {
        case kCRC_INPUT_FORMAT_HALFWORD:
            temp = CRC_Handle_16(base, (uint16_t *)(void *)data, length);
            break;

        case kCRC_INPUT_FORMAT_WORD:
            for (index = 0U; index < length; index++)
            {
                base->CRC_DR = bswap_32(data[index]);
            }
            temp = base->CRC_RR;
            break;

        case kCRC_INPUT_FORMAT_BYTE:
            temp = CRC_Handle_8(base, (uint8_t *)data, length);
            break;

        default:
            break;
    }

    return temp;
}

uint32_t CRC_calculte(CRC_Type *base, uint32_t *data, uint32_t length)
{
    uint32_t index;
    uint32_t temp = 0U;

    CRC_reset(base);

    switch (inputDataFormat)
    {
        case kCRC_INPUT_FORMAT_BYTE:
            temp = CRC_Handle_8(base, (uint8_t *)data, length);
            break;

        case kCRC_INPUT_FORMAT_HALFWORD:
            temp = CRC_Handle_16(base, (uint16_t *)(void *)data, length);
            break;
        case kCRC_INPUT_FORMAT_WORD:
            for (index = 0U; index < length; index++)
            {
                temp = bswap_32(data[index]);
                base->CRC_DR = temp;
            }
            temp = base->CRC_RR;
            break;

        default:
            break;
    }

    return temp;
}

uint32_t CRC_accumulate_fast(CRC_Type *base, uint32_t *data, uint32_t length)
{
    uint32_t index;
    uint32_t temp = 0U, regback;

    regback        = base->CRC_CFG;
    base->CRC_CFG |= CRC_CRC_CFG_CRC_REV_BYTE_Msk;

    for (index = 0U; index < length; index++)
    {
        base->CRC_DR = data[index];
    }

    temp          = base->CRC_RR;
    base->CRC_CFG = regback;

    return temp;
}

uint32_t CRC_calculte_fast(CRC_Type *base, uint32_t *data, uint32_t length)
{
    uint32_t index;
    uint32_t temp = 0U, regback;

    regback        = base->CRC_CFG;
    base->CRC_CFG |= CRC_CRC_CFG_CRC_REV_BYTE_Msk;
    CRC_reset(base);

    for (index = 0U; index < length; index++)
    {
        base->CRC_DR = data[index];
    }

    temp          = base->CRC_RR;
    base->CRC_CFG = regback;

    return temp;
}
