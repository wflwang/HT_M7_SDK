/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_calib.c
 * \brief HS32F7D377 calibration library source file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_calib.h"
#include "hte_eflash.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* No Definitions */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
#ifdef HTE_DEVICE_HS32F7D377_CPU1
/*!  
 * \brief  Calibration CRC-16 CCITT checksum  
 *  
 * \details This function calculates the CRC-16 CCITT checksum of a given buffer.
 *          The initial checksum value can be provided as an input parameter.  
 *  
 * \param[in] cksum   Initial CRC-16 checksum value  
 * \param[in] buf     Pointer to the buffer for which the checksum is to be calculated  
 * \param[in] len     Length of the buffer in bytes  
 *  
 * \retval uint16_t Calibration CRC-16 CCITT checksum  
 */
static uint16_t calib_crc16_ccitt(uint16_t cksum, const unsigned char *buf, int len);
#endif
/**  
 * \brief  Write calibration variables to the embedded flash  
 *  
 * \details This function writes calibration variables to a specific sector of the  
 *          embedded flash memory. The operation is specific to the HTE_DEVICE_HS32F7D377_CPU1  
 *          platform.  
 *  
 *          The function first erases the specified sector and then writes 16 bytes of data  
 *          starting at the beginning of the sector.  
 *  
 * \note   This function is only available for the HTE_DEVICE_HS32F7D377_CPU1 platform.  
 */
void CALIB_vartalWrite(void);

/**  
 * \brief  Write calibration data to an embedded flash sector  
 *  
 * \details This function writes calibration data to a specific sector of the embedded  
 *          flash memory. The operation is specific to the FT_TEST configuration.  
 *  
 *          The function first reads the entire calibration buffer from the flash,  
 *          updates the requested range with the new data, erases the sector, and  
 *          then writes the updated buffer back to the flash.  
 *  
 *          The function also writes the updated calibration buffer to a second  
 *          flash bank (EFLASH1) for redundancy or backup purposes.  
 *  
 * \param[in] buffer  Pointer to the buffer containing the new calibration data  
 * \param[in] addr    Address within the calibration buffer to start writing  
 * \param[in] size    Size of the data to be written  
 *  
 * \retval int        CALIB_OK on success, CALIB_ERR on error (e.g., if buffer is NULL)  
 *  
 * \note   This function is only available for the FT_TEST configuration.  
 */  
static int CALIB_writeEflashSector(uint8_t *buffer, uint16_t addr, uint8_t size);


/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! \brief  Buffer to store calibration value */
uint8_t calibration_buffer[TOTAL_CALIB_SIZE] = { 0 };
#ifdef HTE_DEVICE_HS32F7D377_CPU1
/*! \brief Table of CRC constants - implements x^16+x^12+x^5+1 */
static const uint16_t crc16_tab[] = {
    0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50a5, 0x60c6, 0x70e7, 0x8108, 0x9129, 0xa14a, 0xb16b, 0xc18c, 0xd1ad,
    0xe1ce, 0xf1ef, 0x1231, 0x0210, 0x3273, 0x2252, 0x52b5, 0x4294, 0x72f7, 0x62d6, 0x9339, 0x8318, 0xb37b, 0xa35a,
    0xd3bd, 0xc39c, 0xf3ff, 0xe3de, 0x2462, 0x3443, 0x0420, 0x1401, 0x64e6, 0x74c7, 0x44a4, 0x5485, 0xa56a, 0xb54b,
    0x8528, 0x9509, 0xe5ee, 0xf5cf, 0xc5ac, 0xd58d, 0x3653, 0x2672, 0x1611, 0x0630, 0x76d7, 0x66f6, 0x5695, 0x46b4,
    0xb75b, 0xa77a, 0x9719, 0x8738, 0xf7df, 0xe7fe, 0xd79d, 0xc7bc, 0x48c4, 0x58e5, 0x6886, 0x78a7, 0x0840, 0x1861,
    0x2802, 0x3823, 0xc9cc, 0xd9ed, 0xe98e, 0xf9af, 0x8948, 0x9969, 0xa90a, 0xb92b, 0x5af5, 0x4ad4, 0x7ab7, 0x6a96,
    0x1a71, 0x0a50, 0x3a33, 0x2a12, 0xdbfd, 0xcbdc, 0xfbbf, 0xeb9e, 0x9b79, 0x8b58, 0xbb3b, 0xab1a, 0x6ca6, 0x7c87,
    0x4ce4, 0x5cc5, 0x2c22, 0x3c03, 0x0c60, 0x1c41, 0xedae, 0xfd8f, 0xcdec, 0xddcd, 0xad2a, 0xbd0b, 0x8d68, 0x9d49,
    0x7e97, 0x6eb6, 0x5ed5, 0x4ef4, 0x3e13, 0x2e32, 0x1e51, 0x0e70, 0xff9f, 0xefbe, 0xdfdd, 0xcffc, 0xbf1b, 0xaf3a,
    0x9f59, 0x8f78, 0x9188, 0x81a9, 0xb1ca, 0xa1eb, 0xd10c, 0xc12d, 0xf14e, 0xe16f, 0x1080, 0x00a1, 0x30c2, 0x20e3,
    0x5004, 0x4025, 0x7046, 0x6067, 0x83b9, 0x9398, 0xa3fb, 0xb3da, 0xc33d, 0xd31c, 0xe37f, 0xf35e, 0x02b1, 0x1290,
    0x22f3, 0x32d2, 0x4235, 0x5214, 0x6277, 0x7256, 0xb5ea, 0xa5cb, 0x95a8, 0x8589, 0xf56e, 0xe54f, 0xd52c, 0xc50d,
    0x34e2, 0x24c3, 0x14a0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405, 0xa7db, 0xb7fa, 0x8799, 0x97b8, 0xe75f, 0xf77e,
    0xc71d, 0xd73c, 0x26d3, 0x36f2, 0x0691, 0x16b0, 0x6657, 0x7676, 0x4615, 0x5634, 0xd94c, 0xc96d, 0xf90e, 0xe92f,
    0x99c8, 0x89e9, 0xb98a, 0xa9ab, 0x5844, 0x4865, 0x7806, 0x6827, 0x18c0, 0x08e1, 0x3882, 0x28a3, 0xcb7d, 0xdb5c,
    0xeb3f, 0xfb1e, 0x8bf9, 0x9bd8, 0xabbb, 0xbb9a, 0x4a75, 0x5a54, 0x6a37, 0x7a16, 0x0af1, 0x1ad0, 0x2ab3, 0x3a92,
    0xfd2e, 0xed0f, 0xdd6c, 0xcd4d, 0xbdaa, 0xad8b, 0x9de8, 0x8dc9, 0x7c26, 0x6c07, 0x5c64, 0x4c45, 0x3ca2, 0x2c83,
    0x1ce0, 0x0cc1, 0xef1f, 0xff3e, 0xcf5d, 0xdf7c, 0xaf9b, 0xbfba, 0x8fd9, 0x9ff8, 0x6e17, 0x7e36, 0x4e55, 0x5e74,
    0x2e93, 0x3eb2, 0x0ed1, 0x1ef0,
};


/*******************************************************************************
 * Codes
 ******************************************************************************/

static uint16_t calib_crc16_ccitt(uint16_t cksum, const unsigned char *buf, int len)
{
    for (int i = 0; i < len; i++)
        cksum = crc16_tab[((cksum >> 8) ^ *buf++) & 0xff] ^ (cksum << 8);

    return cksum;
}
#endif
int CALIB_getAdcCalibration(uint8_t *buffer, uint32_t offset, uint32_t size)
{
    EFLASH_Type *base;

#ifdef HTE_DEVICE_HS32F7D377_CPU1
    base = EFLASH0;
#else
    base = EFLASH1;
#endif

    if ((buffer == NULL) || (size >= ADC_CALIB_MAX_SIZE))
    {
        return CALIB_ERR;
    }

    EFLASH_ahbReadBytes(base, kEFLASH_NVR_SECTOR, calibration_buffer, STORE_ADDR / 8, TOTAL_CALIB_SIZE);
    memcpy(buffer, (calibration_buffer + ADC_CALIB_START + offset), size);

    return CALIB_OK;
}

int CALIB_getDacCalibration(uint8_t *buffer, uint32_t size)
{
    EFLASH_Type *base;
#ifdef HTE_DEVICE_HS32F7D377_CPU1
    base = EFLASH0;
#else
    base = EFLASH1;
#endif

    if ((buffer == NULL) || (size >= DAC_CALIB_MAX_SIZE))
    {
        return CALIB_ERR;
    }

    EFLASH_ahbReadBytes(base, kEFLASH_NVR_SECTOR, calibration_buffer, STORE_ADDR / 8, TOTAL_CALIB_SIZE);
    memcpy(buffer, (calibration_buffer + DAC_CALIB_START), size);

    return CALIB_OK;
}

int CALIB_getCmpCalibration(uint8_t *buffer, uint32_t size)
{
    EFLASH_Type *base;
#ifdef HTE_DEVICE_HS32F7D377_CPU1
    base = EFLASH0;
#else
    base = EFLASH1;
#endif

    if ((buffer == NULL) || (size >= CMP_CALIB_MAX_SIZE))
    {
        return CALIB_ERR;
    }

    EFLASH_ahbReadBytes(base, kEFLASH_NVR_SECTOR, calibration_buffer, STORE_ADDR / 8, TOTAL_CALIB_SIZE);
    memcpy(buffer, (calibration_buffer + CMP_CALIB_START), size);

    return CALIB_OK;
}

int CALIB_getOscCalibration(uint8_t *buffer)
{
#ifdef HTE_DEVICE_HS32F7D377_CPU1

    EFLASH_Type *base                     = EFLASH0;
    uint8_t *temp;
    uint16_t     crc, crc_check;
    uint32_t     header;

    EFLASH_ahbReadBytes(base, kEFLASH_NVR_SECTOR, calibration_buffer, STORE_ADDR/8, SECTOR0_RD_SIZE);
    temp = calibration_buffer + OSC_CALIB_START;

    header = *(uint32_t *)temp;
    if (header == 0x5A5A5A5A)
    {
        crc       = *(uint16_t *)(temp + DC_CRC_SIZE);
        crc_check = calib_crc16_ccitt(0, temp, DC_CRC_SIZE);
        if (crc_check == crc)
        {
            memcpy(buffer, temp + OSC_TRM_BASE, 8);
            return CALIB_OK;
        }
    }
#endif
    return CALIB_ERR;
}

int CALIB_getVendorInfo(uint8_t *buffer)
{
#ifdef HTE_DEVICE_HS32F7D377_CPU1

    EFLASH_Type *base = EFLASH0;
    uint64_t temp[2] = {0};

    if (buffer == NULL)
    {
        return CALIB_ERR;
    }

    EFLASH_ahbReadDwords(base, kEFLASH_NVR_CFG_SECTOR, temp, 0x100, 2);

    memcpy(buffer, (uint8_t *)temp, 16);
#endif
    return CALIB_OK;
}

void CALIB_vartalWrite(void)
{
#ifdef HTE_DEVICE_HS32F7D377_CPU1
    uint8_t temp[16] = {0x01,0x00,0xff,0xff,0x05,0x00,0x0f,0x00,0x05,0x00,0x55,0x50,0x45,0x33,0x34,0x39};
    EFLASH_Type *base = EFLASH0;

    EFLASH_eraseSector(base, kEFLASH_NVR_CFG_SECTOR, 0);
    EFLASH_ahbWriteBytes(base, kEFLASH_NVR_CFG_SECTOR, temp, 0x100, 16);
#endif
}

// write calibration information into eflash NVR sector0
static int CALIB_writeEflashSector(uint8_t *buffer,uint16_t addr, uint8_t size)
{
#ifdef FT_TEST
    EFLASH_Type *base;
    uint8_t *temp;

    if (buffer == NULL)
    {
        return CALIB_ERR;
    }
    
    base = EFLASH0;
    EFLASH_ahbReadBytes(base, kEFLASH_NVR_SECTOR, calibration_buffer, STORE_ADDR/8, TOTAL_CALIB_SIZE);

    temp = calibration_buffer;
    memcpy(temp + addr, buffer, size);
    EFLASH_eraseSector(base, kEFLASH_NVR_SECTOR, STORE_ADDR/8);
    EFLASH_ahbWriteBytes(base, kEFLASH_NVR_SECTOR, temp, STORE_ADDR/8, TOTAL_CALIB_SIZE);

    base = EFLASH1;
    EFLASH_eraseSector(base, kEFLASH_NVR_SECTOR, STORE_ADDR/8);
    EFLASH_ahbWriteBytes(base, kEFLASH_NVR_SECTOR, temp, STORE_ADDR/8, TOTAL_CALIB_SIZE);

#endif

    return CALIB_OK;
}


// The function interfaces for each module to obtain calibration values
int CALIB_setAdcCalibration(uint8_t *buffer, uint32_t size)
{
    if ((buffer == NULL) || (size >= ADC_CALIB_MAX_SIZE))
    {
        return CALIB_ERR;
    }

    return CALIB_writeEflashSector(buffer,ADC_CALIB_START,size);
}

int CALIB_setDacCalibration(uint8_t *buffer, uint32_t size)
{
    if ((buffer == NULL) || (size >= DAC_CALIB_MAX_SIZE))
    {
        return CALIB_ERR;
    }

    return CALIB_writeEflashSector(buffer,DAC_CALIB_START,size);
}

int CALIB_setCmpCalibration(uint8_t *buffer, uint32_t size)
{
    if ((buffer == NULL) || (size >= CMP_CALIB_MAX_SIZE))
    {
        return CALIB_ERR;
    }

    return CALIB_writeEflashSector(buffer,CMP_CALIB_START,size);
}

int CALIB_setOscCalibration(uint8_t *buffer, uint8_t dft)
{
#ifdef FT_TEST
    EFLASH_Type *base                     = EFLASH0;
    uint8_t temp[OSC_DATA_SIZE] = {0};
    uint32_t     header;

    if (buffer == NULL)
    {
        return CALIB_ERR;
    }

    EFLASH_ahbReadBytes(base, kEFLASH_NVR_SECTOR, calibration_buffer, 0, SECTOR0_RD_SIZE);

    memcpy(temp,calibration_buffer + OSC_CALIB_START,OSC_DATA_SIZE);
    header = *(uint32_t *)temp;
    if ((header == 0x5A5A5A5A) && (dft == 0))
    {
        uint16_t     crc;
        memcpy(temp + OSC_TRM_BASE, buffer, 8);
        crc = calib_crc16_ccitt(0, temp, DC_CRC_SIZE);
        *(uint32_t *)(temp + DC_CRC_SIZE) = crc;

        return CALIB_writeEflashSector(temp,OSC_CALIB_START,OSC_DATA_SIZE);
    }
    else if (dft == 1)
    {
        return CALIB_writeEflashSector(buffer,OSC_CALIB_START,OSC_DATA_SIZE);
    }
    else
#endif
    {
        return CALIB_OK;
    }
}

// ERASE eflash NVR sector 3
void CALIB_eraseSector(void)
{
#ifdef FT_TEST
//    EFLASH_Type *base = EFLASH0;
//    EFLASH_eraseSector(base, EFLASH_NVR_SECTOR, STORE_ADDR/8);
//
//    base = EFLASH1;
//    EFLASH_eraseSector(base, EFLASH_NVR_SECTOR, STORE_ADDR/8);
#endif
}

int CALIB_eflashInit(uint32_t sysPclk)
{
    EFLASH_Type *base;

    if (sysPclk == 0)
    {
        return CALIB_ERR;
    }

#ifdef HTE_DEVICE_HS32F7D377_CPU1
    base = EFLASH0;
    EFLASH_initClock(base, sysPclk);

#ifdef FT_TEST
    base = EFLASH1;
    EFLASH_initClock(base, sysPclk);
#endif

#else
    base = EFLASH1;
    EFLASH_initClock(base, sysPclk);
#endif

    return CALIB_OK;
}

