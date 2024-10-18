/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file pin_config.h
 * \brief HS32F7D377 EVB Pin configuration header file
 * \version 1.0.0
 */

#ifndef PIN_CONFIG_H
#define PIN_CONFIG_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_common.h"

/*!
 * \addtogroup EVB_HS32F7D377_PIN_CONFIG HS32F7D377 EVB Pin Configuration
 *
 * \brief HS32F7D377 EVB pin configuration driver
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* No Definitions */

/*******************************************************************************
 * APIs
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief LED pin configuration
 *
 * \param[in] instance LED instance
 */
void BOARD_ledPinConfig(uint32_t instance);

/*!
 * \brief Button pin configuration
 *
 * \param[in] instance Button instance
 */
void BOARD_buttonPinConfig(uint32_t instance);

/*!
 * \brief UART pin configuration
 *
 * \param[in] base UART base address
 */
void BOARD_uartPinConfig(UART_Type *base);

/*!
 * \brief I2C pin configuration
 *
 * \param[in] base I2C base address
 */
void BOARD_i2cPinConfig(I2C_Type *base);

/*!
 * \brief PMBUS pin configuration
 *
 * \param[in] base PMBUS base address
 */
void BOARD_pmbusPinConfig(PMBUS_Type *base);

/*!
 * \brief SPI pin configuration
 *
 * \param[in] base SPI base address
 */
void BOARD_spiPinConfig(SPI_Type *base);

/*!
 * \brief MCAN pin configuration
 *
 * \param[in] base MCAN base address
 */
void BOARD_mcanPinConfig(MCAN_Type *base);

/*!
 * \brief EPWM pin configuration
 *
 * \param[in] base EPWM base address
 */
void BOARD_epwmPinConfig(EPWM_REGS_Type *base);

/*!
 * \brief ECAP pin configuration
 *
 * \param[in] base ECAP base address
 */
void BOARD_ecapPinConfig(ECAP_Type *base);

/*!
 * \brief EQEP pin configuration
 *
 * \param[in] base EQEP base address
 */
void BOARD_eqepPinConfig(EQEP_REGS_Type *base);

/*!
 * \brief EMIF pin configuration for SDRAM
 *
 * \param[in] base EMIF base address
 */
void BOARD_sdramPinConfig(EMIF_Type *base);

/*!
 * \brief EMIF pin configuration for SRAM
 *
 * \param[in] base EMIF base address
 */
void BOARD_sramPinConfig(EMIF_Type *base);

/*!
 * \brief SDFM pin configuration
 *
 * \param[in] base SDFM base address
 */
void BOARD_sdfmPinConfig(SDFM_REGS_Type *base);

/*!
 * \brief USB pin configuration
 *
 * \param[in] base USB base address
 */
void BOARD_usbPinConfig(USB_Type *base);

/*!
 * \brief XCLKOUT pin configuration
 */
void BOARD_xclkoutPinConfig(void);

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */ /* end of EVB_HS32F7D377_PIN_CONFIG */

#endif /* PIN_CONFIG_H */
