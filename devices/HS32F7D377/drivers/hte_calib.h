/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_calib.h
 * \brief HS32F7D377 calibration library header file
 * \version 1.0.0
 */

#ifndef HTE_CALIB_H
#define HTE_CALIB_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_common.h"

/*!
 * \addtogroup DRV_HS32F7D377_CALIB HS32F7D377 Calibration Library
 *
 * \brief HS32F7D377 Calibration Library
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define SECTOR_SIZE (4096) /*!< Defines the size of each sector as 4096 bytes. */
#define SECTOR_NO   (0)    /*!< Specifies the number of sectors as 0. */
#define STORE_ADDR                                                                                                   \
    (SECTOR_NO * SECTOR_SIZE) /*!< Calculates the starting address for storing data by multiplying the sector number \
                                 with the sector size. */

#define OSC_CALIB_MAX_SIZE (256) /*!< The maximum allocation space for OSC calibration is 256 bytes. */
#define ADC_CALIB_MAX_SIZE (256) /*!< The maximum allocation space for ADC calibration is 256 bytes. */
#define DAC_CALIB_MAX_SIZE (256) /*!< The maximum allocation space for DAC calibration is 256 bytes. */
#define CMP_CALIB_MAX_SIZE (256) /*!< The maximum allocation space for CMP calibration is 256 bytes. */

#define TOTAL_CALIB_SIZE \
    (ADC_CALIB_MAX_SIZE + DAC_CALIB_MAX_SIZE + CMP_CALIB_MAX_SIZE + OSC_CALIB_MAX_SIZE) /*!< The total maximum allocation space for all calibrations. */

#define OSC_CALIB_START (0) /*!< The starting address for OSC calibration values. */
#define ADC_CALIB_START                                                                          \
    (OSC_CALIB_START + OSC_CALIB_MAX_SIZE) /*!< The starting address for ADC calibration values. \
                                            */
#define DAC_CALIB_START                                                                          \
    (ADC_CALIB_START + ADC_CALIB_MAX_SIZE) /*!< The starting address for DAC calibration values. \
                                            */
#define CMP_CALIB_START                                                                          \
    (DAC_CALIB_START + DAC_CALIB_MAX_SIZE) /*!< The starting address for DAC calibration values. \
                                            */

#define SECTOR0_RD_SIZE TOTAL_CALIB_SIZE /*!< The OSC TRM actual read data size */
#define OSC_DATA_SIZE   132 /*!< The OSC Total read data size */
#define DC_CRC_SIZE     128 /*!< The OSC TRM CRC val address */
#define OSC_TRM_BASE    4   /*!< The OSC TRM base address */

#define CALIB_OK  1         /*!< The return val of sucess */
#define CALIB_ERR -1        /*!< The return val of error */

/*******************************************************************************
 * API
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Get ADC calibration data
 *
 * \details Reads ADC calibration data from the eflash memory and copies it to the provided buffer.
 *
 * \param[out] buffer Pointer to the buffer where calibration data will be stored
 * \param[in] offset Offset address of adcX (X is a,b,c,d)
 * \param[in] size Size of the buffer in bytes
 *
 * \retval 0 Success
 * \retval -1 Failure
 */
int CALIB_getAdcCalibration(uint8_t *buffer, uint32_t offset, uint32_t size);

/**
 * \brief Get DAC calibration data
 *
 * \details Reads DAC calibration data from the eflash memory and copies it to the provided buffer.
 *
 * \param[out] buffer Pointer to the buffer where calibration data will be stored
 * \param[in] size Size of the buffer in bytes
 *
 * \retval 0 Success
 * \retval -1 Failure
 */
int CALIB_getDacCalibration(uint8_t *buffer, uint32_t size);

/**
 * \brief Get oscillator calibration data
 *
 * \details Reads oscillator calibration data from the eflash memory and copies it to the provided buffer.
 *
 * \param[out] buffer Pointer to the buffer where calibration data will be stored
 *
 * \retval 0 Success
 * \retval -1 Failure
 */
int CALIB_getOscCalibration(uint8_t *buffer);


/**
 * \brief Get cmpss calibration data
 *
 * \details Reads cmpss calibration data from the eflash memory and copies it to the provided buffer.
 *
 * \param[out] buffer Pointer to the buffer where calibration data will be stored
 * \param[in] size Size of the buffer in bytes
 *
 * \retval 0 Success
 * \retval -1 Failure
 */
int CALIB_getCmpCalibration(uint8_t *buffer, uint32_t size);



/**
 * \brief Get vendor info from chip
 *
 * \details Reads vendor info data from the eflash memory and copies it to the provided buffer.
 *  this info include coordx(buffer[6:7]),coordy(buffer[4:5]),waferId(buffer[8:15]).
 *
 * \param[out] buffer Pointer to the buffer where calibration data will be stored
 *
 * \retval 0 Success
 * \retval -1 Failure
 */
int CALIB_getVendorInfo(uint8_t *buffer);


/**
 * \brief Set ADC calibration data
 *
 * \details Copies ADC calibration data from the provided buffer to the eflash memory.
 *
 * \param[in] buffer Pointer to the buffer containing calibration data to be set
 * \param[in] size Size of the calibration data in bytes
 *
 * \retval 0 Success
 * \retval -1 Failure
 */
int CALIB_setAdcCalibration(uint8_t *buffer, uint32_t size);

/**
 * \brief Set DAC calibration data
 *
 * \details Copies DAC calibration data from the provided buffer to the internal calibration buffer.
 *
 * \param[in] buffer Pointer to the buffer containing calibration data to be set
 * \param[in] size Size of the calibration data in bytes
 *
 * \retval 0 Success
 * \retval -1 Failure
 */
int CALIB_setDacCalibration(uint8_t *buffer, uint32_t size);

/**
 * \brief Set oscillator calibration data
 *
 * \details Copies oscillator calibration data from the provided buffer to the internal calibration buffer.
 *
 * \param[in] buffer Pointer to the buffer containing calibration data to be set
 * \param[in] dft write default OSC val to memory.
 *
 * \retval 0 Success
 * \retval -1 Failure
 */
int CALIB_setOscCalibration(uint8_t *buffer, uint8_t dft);

/**
 * \brief Set cmpss calibration data
 *
 * \details Copies cmpss calibration data from the provided buffer to the internal calibration buffer.
 *
 * \param[in] buffer Pointer to the buffer containing calibration data to be set
 * \param[in] size Size of the calibration data in bytes
 *
 * \retval 0 Success
 * \retval -1 Failure
 */
int CALIB_setCmpCalibration(uint8_t *buffer, uint32_t size);

/**
 * \brief Erase a sector in eflash memory
 *
 * \details Erases the specified sector in the eflash memory where calibration data is stored.
 *
 * \note This function assumes that the eflash driver (EFLASH_Type and its related functions) has been properly
 *       initialized and is ready for use.
 */
void CALIB_eraseSector(void);


/**
 * \brief Initialize the eflash controller
 *
 * \details Initializes the eflash controller with the provided system clock speed.
 *
 * \param[in] sysPclk is system pclk.
 *
 * \retval  0 success
 * \retval -1 Failure
 */
int CALIB_eflashInit(uint32_t sysPclk);

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */ /* end of DRV_HS32F7D377_CALIB */

#endif /* HTE_CALIB_H */
