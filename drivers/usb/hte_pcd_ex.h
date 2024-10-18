/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_pcd_ex.h
 * \brief SDK USB peripheral control extended driver header file
 * \version 1.0.0
 */

#ifndef HTE_PCD_EX_H
#define HTE_PCD_EX_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_pcd.h"

/*!
 * \addtogroup DRV_HTE_USB_PCD_EX USB Peripheral Control Extended Driver
 *
 * \brief SDK USB peripheral control extended driver
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
#endif /* __cplusplus */

/*!
 * \brief  Set Tx FIFO
 * \param[in] hpcd PCD handle
 * \param[in] fifo The number of Tx fifo
 * \param[in] size Fifo size
 * \return  HAL status
 */
status_t PCDEx_setTxFiFo(PCD_HandleTypeDef_t *hpcd, uint8_t fifo, uint16_t size);
/*!
 * \brief  Set Rx FIFO
 * \param[in]  hpcd PCD handle
 * \param[in]  size Size of Rx fifo
 * \return  HAL status
 */
status_t PCDEx_setRxFiFo(PCD_HandleTypeDef_t *hpcd, uint16_t size);
/*!
 * \brief  Activate LPM feature.
 * \param[in]  hpcd PCD handle
 * \return  HAL status
 */
status_t PCDEx_activateLPM(PCD_HandleTypeDef_t *hpcd);
/*!
 * \brief  Deactivate LPM feature.
 * \param[in]  hpcd PCD handle
 * \return  HAL status
 */
status_t PCDEx_deActivateLPM(PCD_HandleTypeDef_t *hpcd);

/*!
 * \brief  Activate BatteryCharging feature.
 * \param[in]  hpcd PCD handle
 * \return  HAL status
 */
status_t PCDEx_activateBCD(PCD_HandleTypeDef_t *hpcd);
/*!
 * \brief  Deactivate BatteryCharging feature.
 * \param[in]  hpcd PCD handle
 * \return  HAL status
 */
status_t PCDEx_deactivateBCD(PCD_HandleTypeDef_t *hpcd);
/*!
 * \brief  Handle BatteryCharging Process.
 * \param[in]  hpcd PCD handle
 * \return  HAL status
 */
void PCDEx_BCD_vbusDetect(PCD_HandleTypeDef_t *hpcd);
/*!
 * \brief  Send LPM message to user layer callback.
 * \param[in]  hpcd PCD handle
 * \param[in]  msg LPM message
 * \return  HAL status
 */
void PCDEx_LPM_callback(PCD_HandleTypeDef_t *hpcd, PCD_LPM_MsgTypeDef_t msg);
/*!
 * \brief  Send BatteryCharging message to user layer callback.
 * \param[in]  hpcd PCD handle
 * \param[in]  msg LPM message
 * \return  HAL status
 */
void PCDEx_BCD_callback(PCD_HandleTypeDef_t *hpcd, PCD_BCD_MsgTypeDef_t msg);

#ifdef __cplusplus
}
#endif /* __cplusplus */

/*!
 * @}
 */ /* end of DRV_HTE_USB_PCD_EX */

#endif /* HTE_PCD_EX_H */
