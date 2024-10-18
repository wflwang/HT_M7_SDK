/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*!
 * \file crc_test.c
 * \brief Example of CRC polling functions
 * \version 1.0.0
 */


/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "sw_crc.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define CRC_MAX_BYTE    1024

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/* No Prototypes */


/*******************************************************************************
 * Variables
 ******************************************************************************/
static uint32_t recoder = 0,crcInitVal = 0;
static uint8_t  scdata[CRC_MAX_BYTE] = { 0 };

/*******************************************************************************
 * Codes
 ******************************************************************************/

static uint32_t revbitX(uint32_t data, uint8_t len)
{
    uint32_t temp = 0, i = 0;

    for (i = 0; i < len; i++)
    {
        if ((data & 0x1) != 0)
        {
            temp |= 1;
        }
        if (i == len - 1)
            break;
        data = data >> 1;
        temp = temp << 1;
    }

    return temp;
}

static void CRC_byte_reverse(uint8_t data[], uint32_t datalen)
{
    uint32_t num;
    uint8_t  tmp[CRC_MAX_BYTE];
    memcpy(tmp, data, datalen);
    for (num = 0; num < datalen; num++)
    {
        data[num] = tmp[datalen - num - 1];
    }
}

static uint32_t CRC7_calculate(CRC_Type *crcx, uint8_t *data, uint32_t datalen,bool acc)
{
    uint8_t num;
    uint8_t crc = (crcInitVal) << 1; // Initial value

//    if (crcx->CRC_CFGb.CRC_REV_OUT == 1)
//    {
//        crc = (uint8_t)revbitX((uint32_t)crc, 8) << 1;
//    }
    if(acc == 0)
    {
        crc = (uint8_t)crcInitVal<<1;
    }
    else
    {
        crc = (uint8_t)recoder<<1;
    }
    
    
    while (datalen--)
    {
        crc ^= *data++; // crc ^= *data; data++;data^init
        for (num = 0; num < 8; num++)
        {
            if (crc & 0x80)
            {
                crc = (crc << 1) ^ ((crcx->CRC_POLYb.CRC_POLY) << 1);
            }
            else
            {
                crc <<= 1;
            }
        }
    }
    return crc >> 1;
}

static uint32_t CRC8_calculate(CRC_Type *crcx, uint8_t *data, uint32_t datalen,bool acc)
{
    uint8_t num;
    uint8_t crc = crcInitVal; // Initial value

//    if (crcx->CRC_CFGb.CRC_REV_OUT == 1)
//    {
//        crc = (uint8_t)revbitX((uint32_t)crc, 8);
//    }
    if(acc == 0)
    {
        crc = (uint8_t)crcInitVal;
    }
    else
    {
        crc = (uint8_t)recoder;
    }
    
    while (datalen--)
    {
        crc ^= *data++; // crc ^= *data; data++;data^init
        for (num = 0; num < 8; num++)
        {
            if (crc & 0x80)
            {
                crc = (crc << 1) ^ (crcx->CRC_POLYb.CRC_POLY);
            }
            else
            {
                crc <<= 1;
            }
        }
    }
    return crc;
}

static uint32_t CRC16_calculate(CRC_Type *crcx, uint8_t *data, uint32_t datalen,bool acc)
{
    uint8_t  num;
    uint16_t crc = crcInitVal; // Initial value

    if(acc == 0)
    {
        crc = (uint16_t)crcInitVal;
    }
    else
    {
        crc = (uint16_t)recoder;
    }

    while (datalen--)
    {
        crc ^= (uint16_t)(*data++) << 8; // crc ^= (uint16_t)(*data)<<8; data++;data^init
        for (num = 0; num < 8; num++)
        {
            if (crc & 0x8000)
            {
                crc = (crc << 1) ^ (crcx->CRC_POLYb.CRC_POLY);
            }
            else
            {
                crc <<= 1;
            }
        }
    }
    return crc;
}

static uint32_t CRC24_calculate(CRC_Type *crcx, uint8_t *data, uint32_t datalen,bool acc)
{
    uint8_t  num;
    uint32_t crc = crcInitVal; // Initial value

    if(acc == 0)
    {
        crc = crcInitVal;
    }
    else
    {
        crc = recoder;
    }

    while (datalen--)
    {
        crc ^= (uint32_t)(*data++) << 16; // crc ^= (uint16_t)(*data)<<16; data++;data^init
        for (num = 0; num < 8; num++)
        {
            if (crc & 0x800000)
            {
                crc = (crc << 1) ^ (crcx->CRC_POLYb.CRC_POLY);
            }
            else
            {
                crc <<= 1;
            }
        }
    }
    return (crc & 0xFFFFFF);
}

static uint32_t CRC32_calculate(CRC_Type *crcx, uint8_t *data, uint32_t datalen,bool acc)
{
    uint8_t  num;
    uint32_t crc; // Initial value
    
    if(acc == 0)
    {
        crc = crcInitVal;
    }
    else
    {
        crc = recoder;
    }
    
    while (datalen--)
    {
        crc ^= (uint32_t)(*data++) << 24; // crc ^= (uint16_t)(*data)<<24; data++;data^init
        for (num = 0; num < 8; num++)
        {
            if (crc & 0x80000000)
            {
                crc = (crc << 1) ^ (crcx->CRC_POLYb.CRC_POLY);
            }
            else
            {
                crc <<= 1;
            }
        }
    }
    return crc;
}

static void CRC_input_reverse(CRC_Type *crcx, uint8_t data[], uint32_t datalen)
{
    uint32_t  num, len;
    uint16_t *hwdata;
    uint32_t *wdata;

    len = datalen;

    {
        switch (crcx->CRC_CFGb.CRC_REV_IN) // input bit reverse
        {
            case kCRC_REVINPUT_FORMAT_BYTE:
                for (num = 0; num < len; num++)
                {
                    data[num] = (uint8_t)revbitX((uint8_t)data[num], 8);
                }
                break;
            case kCRC_REVINPUT_FORMAT_HALFWORD:
                hwdata = (uint16_t *)data;

                if (datalen % 2 != 0)
                {
                    len = datalen + 1;
                }

                for (num = 0; num < len / 2; num++)
                {
                    hwdata[num] = (uint16_t)revbitX((uint16_t)hwdata[num], 16);
                }
                break;
            case kCRC_REVINPUT_FORMAT_WORD:
                wdata = (uint32_t *)data;
                if (datalen % 4 != 0)
                {
                    len = datalen + 3;
                }
                for (num = 0; num < len / 4; num++)
                {
                    wdata[num] = revbitX(wdata[num], 32);
                }
                break;
            default: // no bit reverse
                break;
        }
        if (crcx->CRC_CFGb.CRC_REV_BYTE != 0) // input byte reverse
        {
            CRC_byte_reverse(data, datalen);
        }
    }
}

static uint32_t CRC_output_reverse(CRC_Type *crcx, uint32_t crc)
{
    uint32_t crcsize;
    if (crcx->CRC_CFGb.CRC_POLYSIZE == kCRC_POLY32_SIZE)
    {
        crcsize = 32;
    }
    else if (crcx->CRC_CFGb.CRC_POLYSIZE == kCRC_POLY24_SIZE)
    {
        crcsize = 24;
    }
    else if (crcx->CRC_CFGb.CRC_POLYSIZE == kCRC_POLY16_SIZE)
    {
        crcsize = 16;
    }
    else if (crcx->CRC_CFGb.CRC_POLYSIZE == kCRC_POLY8_SIZE)
    {
        crcsize = 8;
    }
    else if (crcx->CRC_CFGb.CRC_POLYSIZE == kCRC_POLY7_SIZE)
    {
        crcsize = 7;
    }
    else
    {
    	crcsize = 32;
    }

    if (crcx->CRC_CFGb.CRC_REV_OUT) // output bit reverse
    {
        return revbitX(crc, crcsize);
    }
    return crc;
}

void CRC_swSetInitVal(uint32_t val)
{
    crcInitVal = val;
}


uint32_t CRC_software_calculate(CRC_Type *crcx, uint8_t indata[], uint32_t datalen,bool acc)
{
    uint32_t crc = 0;
    memcpy(scdata, indata, datalen);
    
    CRC_input_reverse(crcx, (uint8_t *)scdata, datalen); 
    switch (crcx->CRC_CFGb.CRC_POLYSIZE)
    {
        case kCRC_POLY32_SIZE:
            crc = CRC32_calculate(crcx, (uint8_t *)scdata, datalen,acc);
            break;
        case kCRC_POLY24_SIZE:
            crc = CRC24_calculate(crcx, (uint8_t *)scdata, datalen,acc);
            break;
        case kCRC_POLY16_SIZE:
            crc = CRC16_calculate(crcx, (uint8_t *)scdata, datalen,acc);
            break;
        case kCRC_POLY8_SIZE:
            crc = CRC8_calculate(crcx, (uint8_t *)scdata, datalen,acc);
            break;
        case kCRC_POLY7_SIZE:
            crc = CRC7_calculate(crcx, (uint8_t *)scdata, datalen,acc);
            break;
        default:
            break;
    }
    recoder = crc;
    memset(scdata, 0, CRC_MAX_BYTE);
    return CRC_output_reverse(crcx, crc);
}
