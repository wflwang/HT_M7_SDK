/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file HS32F7D377_cpu2_features.h
 * \brief HS32F7D377 CPU2 feature file
 * \version 1.0.0
 */

#ifndef HS32F7D377_CPU2_FEATURES_H
#define HS32F7D377_CPU2_FEATURES_H

/*!
 * \addtogroup HS32F7D377_CPU2_FEATURES HS32F7D377 CPU2 Feature
 *
 * \brief HS32F7D377 CPU2 device feature definitions
 *
 * @{
 */

/*!
 * \name Device Feature
 *
 * @{
 */

/*! \brief UART availability on the device. */
#define HTE_FEATURE_UART_COUNT (4)
/*! \brief I2C availability on the device. */
#define HTE_FEATURE_SPI_COUNT (3)
/*! \brief GPIO ctrl availability on the device. */
#define HTE_FEATURE_GPIO_CTRL_COUNT (0)
/*! \brief GPIO data availability on the device. */
#define HTE_FEATURE_GPIO_DATA_COUNT (1)
/*! \brief XINT availability on the device. */
#define HTE_FEATURE_XINT_COUNT (1)
/*! \brief INPUT XBAR availability on the device */
#define HTE_FEATURE_INPUT_XBAR_COUNT (0)
/*! \brief XBAR availability on the device */
#define HTE_FEATURE_XBAR_COUNT (0)
/*! \brief EPWM XBAR availability on the device */
#define HTE_FEATURE_EPWM_XBAR_COUNT (0)
/*! \brief CLB XBAR availability on the device */
#define HTE_FEATURE_CLB_XBAR_COUNT (0)
/*! \brief OUTPUT XBAR availability on the device */
#define HTE_FEATURE_OUTPUT_XBAR_COUNT (0)

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
 * \name SPI Module Feature
 *
 * @{
 */

/* No feature definitions */

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
 */ /* end of HS32F7D377_CPU2_FEATURES */

#endif /* HS32F7D377_CPU2_FEATURES_H */
