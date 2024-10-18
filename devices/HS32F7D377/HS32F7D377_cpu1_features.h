/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file HS32F7D377_cpu1_features.h
 * \brief HS32F7D377 CPU1 feature file
 * \version 1.0.0
 */

#ifndef HS32F7D377_CPU1_FEATURES_H
#define HS32F7D377_CPU1_FEATURES_H

/*!
 * \addtogroup HS32F7D377_CPU1_FEATURES HS32F7D377 CPU1 Feature
 *
 * \brief HS32F7D377 CPU1 device feature definitions
 *
 * @{
 */

/*!
 * \name Device Feature
 *
 * @{
 */

/*! \brief ADC availability on the device*/
#define HTE_FEATURE_ADC_COUNT (1)
/*! \brief CLB availability on the device*/
#define HTE_FEATURE_CLB_COUNT (1)
/*! \brief CLB XBAR availability on the device */
#define HTE_FEATURE_CLB_XBAR_COUNT (1)
/*! \brief CMPSS availability on the device*/
#define HTE_FEATURE_CMPSS_COUNT (1)
/*! \brief CRC availability on the device*/
#define HTE_FEATURE_CRC_COUNT (1)
/*! \brief DAC availability on the device*/
#define HTE_FEATURE_DAC_COUNT (1)
/*! \brief DMA availability on the device*/
#define HTE_FEATURE_DMA_COUNT (1)
/*! \brief ECAP availability on the device*/
#define HTE_FEATURE_ECAP_COUNT (1)
/*! \brief EFLASH availability on the device*/
#define HTE_FEATURE_EFLASH_COUNT (1)
/*! \brief EMIF availability on the device*/
#define HTE_FEATURE_EMIF_COUNT (1)
/*! \brief EPWM availability on the device*/
#define HTE_FEATURE_EPWM_COUNT (12)
/*! \brief EPWM XBAR availability on the device */
#define HTE_FEATURE_EPWM_XBAR_COUNT (1)
/*! \brief EQEP availability on the device*/
#define HTE_FEATURE_EQEP_COUNT (3)
/*! \brief GPIO CTRL availability on the device */
#define HTE_FEATURE_GPIO_CTRL_COUNT (1)
/*! \brief GPIO DATA availability on the device */
#define HTE_FEATURE_GPIO_DATA_COUNT (1)
/*! \brief I2C availability on the device*/
#define HTE_FEATURE_I2C_COUNT (2)
/*! \brief INPUT XBAR availability on the device */
#define HTE_FEATURE_INPUT_XBAR_COUNT (2)
/*! \brief MCAN availability on the device*/
#define HTE_FEATURE_MCAN_COUNT (3)
/*! \brief OUTPUT XBAR availability on the device */
#define HTE_FEATURE_OUTPUT_XBAR_COUNT (2)
/*! \brief PMBUS availability on the device*/
#define HTE_FEATURE_PMBUS_COUNT (1)
/*! \brief SDFM availability on the device*/
#define HTE_FEATURE_SDFM_COUNT (2)
/*! \brief I2C availability on the device */
#define HTE_FEATURE_SPI_COUNT (3)
/*! \brief STIMER availability on the device*/
#define HTE_FEATURE_STIMER_COUNT (1)
/*! \brief TFU availability on the device*/
#define HTE_FEATURE_TFU_COUNT (1)
/*! \brief UART availability on the device*/
#define HTE_FEATURE_UART_COUNT (4)
/*! \brief USB availability on the device*/
#define HTE_FEATURE_USB_COUNT (1)
/*! \brief WDT availability on the device*/
#define HTE_FEATURE_WDT_COUNT (1)
/*! \brief XBAR availability on the device*/
#define HTE_FEATURE_XBAR_COUNT (1)
/*! \brief XINT availability on the device */
#define HTE_FEATURE_XINT_COUNT (1)


/*!
 * @}
 */

/*!
 * \name GPIO Module Feature
 *
 * @{
 */

/*! \brief GPIO pin count on the device */
#define HTE_FEATURE_GPIO_PIN_COUNT (168)
/*! \brief GPIO doesn't support open-drain mode */
#define HTE_FEATURE_GPIO_NOT_SUPPORT_OPEN_DRAIN (1)

/*!
 * @}
 */

/*!
 * \name SDFM Module Feature
 *
 * @{
 */

/*! \brief SDFM channel count on the device */
#define HTE_FEATURE_SDFM_CHANNEL_COUNT (5)

/*!
 * @}
 */

/*!
 * \name UART Module Feature
 *
 * @{
 */

/*! \brief UART TX and RX FIFO depth in bytes */
#define HTE_FEATURE_UART_FIFO_MAX_LEVEL (128)

/*!
 * @}
 */

/*!
 * \name XBAR Module Feature
 *
 * @{
 */

/*! \brief XBAR Flag locates at non-continuous addresses */
#define HTE_FEATURE_XBAR_FLAG_HAS_NON_CONTINUOUS_ADDRESS (1)

/*!
 * @}
 */

/*!
 * \name XINT Module Feature
 *
 * @{
 */

/*! \brief XIN channel count on the device */
#define HTE_FEATURE_XIN_CHANNEL_COUNT (5)
/*! \brief XIN counter count on the device */
#define HTE_FEATURE_XIN_COUNTER_COUNT (5)
/*! \brief XIN counter register locates at non-continuous addresses */
#define HTE_FEATURE_XIN_COUNTER_HAS_NON_CONTINUOUS_ADDRESS (1)
/*! \brief XIN flag register contains pending interrupt which is caught before the interrupt is enabled */
#define HTE_FEATURE_XIN_FLAG_HAS_PENDING_IRQ (1)

/*!
 * @}
 */

/*!
 * @}
 */ /* end of HS32F7D377_CPU1_FEATURES */

#endif /* HS32F7D377_CPU1_FEATURES_H */
