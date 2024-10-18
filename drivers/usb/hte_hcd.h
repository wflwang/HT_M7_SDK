/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_hcd.h
 * \brief SDK USB host controller driver header file
 * \version 1.0.0
 */

#ifndef HTE_HCD_H
#define HTE_HCD_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_ll_usb.h"

/*!
 * \addtogroup DRV_HTE_USB_HCD USB Host Controller Driver
 *
 * \brief SDK USB host controller driver
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* HCD state */
typedef enum
{
    kHCD_STATE_RESET   = 0x00,
    kHCD_STATE_READY   = 0x01,
    kHCD_STATE_ERROR   = 0x02,
    kHCD_STATE_BUSY    = 0x03,
    kHCD_STATE_TIMEOUT = 0x04
} HCD_StateTypeDef_t;

typedef USB_Type HCD_TypeDef;

typedef USB_OTG_CfgTypeDef_t      HCD_InitTypeDef;
typedef USB_OTG_HCTypeDef_t       HCD_HCTypeDef;
typedef USB_OTG_URBStateTypeDef_t HCD_URBStateTypeDef;
typedef USB_OTG_HCStateTypeDef_t  HCD_HCStateTypeDef;

typedef struct
{
    HCD_TypeDef            *instance;  /*!< Register base address    */
    HCD_InitTypeDef         init;      /*!< HCD required parameters  */
    HCD_HCTypeDef           hc[16];    /*!< Host channels parameters */
    USB_OTG_LockTypeDef_t   lock;      /*!< HCD peripheral status    */
    __IO HCD_StateTypeDef_t state;     /*!< HCD communication state  */
    __IO uint32_t           errorCode; /*!< HCD Error code           */
    void                   *pData;     /*!< Pointer Stack Handler    */
} HCD_HandleTypeDef_t;

#define HCD_SPEED_HIGH USBH_HS_SPEED
#define HCD_SPEED_FULL USBH_FSLS_SPEED
#define HCD_SPEED_LOW  USBH_FSLS_SPEED

#define HCD_DEVICE_SPEED_HIGH 0U
#define HCD_DEVICE_SPEED_FULL 1U
#define HCD_DEVICE_SPEED_LOW  2U

#define HCD_PHY_ULPI     1U
#define HCD_PHY_EMBEDDED 2U

#define HCD_ENABLE(__HANDLE__)  (void)USB_enableGlobalInt((__HANDLE__)->instance)
#define HCD_DISABLE(__HANDLE__) (void)USB_disableGlobalInt((__HANDLE__)->instance)

#define HCD_GET_FLAG(__HANDLE__, __INTERRUPT__) \
    ((USB_readInterrupts((__HANDLE__)->instance) & (__INTERRUPT__)) == (__INTERRUPT__))
#define HCD_CLEAR_FLAG(__HANDLE__, __INTERRUPT__) (((__HANDLE__)->instance->GINTSTS) = (__INTERRUPT__))
#define HCD_IS_INVALID_INTERRUPT(__HANDLE__)      (USB_readInterrupts((__HANDLE__)->instance) == 0U)

#define HCD_CLEAR_HC_INT(channelNum, __INTERRUPT__) (usbBase->HC_GRPb[channelNum].HCINT_N = (__INTERRUPT__))
#define HCD_MASK_HALT_HC_INT(channelNum)            (usbBase->HC_GRPb[channelNum].HCINTMSK_N &= ~USB_HCINTMSK_N_CH_HLTD_MSK_Msk)
#define HCD_UNMASK_HALT_HC_INT(channelNum)          (usbBase->HC_GRPb[channelNum].HCINTMSK_N |= USB_HCINTMSK_N_CH_HLTD_MSK_Msk)

/*******************************************************************************
 * Variables
 ******************************************************************************/
extern HCD_HandleTypeDef_t g_hcdHandle;

/*******************************************************************************
 * APIs
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief  Initialize the host driver.
 * \param[in]  hhcd HCD handle
 * \return  status
 */
status_t HCD_init(HCD_HandleTypeDef_t *hhcd);

/*!
 * \brief  DeInitialize the host driver.
 * \param[in]  hhcd HCD handle
 * \return  status
 */
status_t HCD_deinit(HCD_HandleTypeDef_t *hhcd);

/*!
 * \brief  Initialize a host channel.
 * \param[in]  hhcd HCD handle
 * \param[in]  channelNum Channel number.
 *         This parameter can be a value from 1 to 15
 * \param[in]  epnum Endpoint number.
 *          This parameter can be a value from 1 to 15
 * \param[in]  devAddress Current device address
 *          This parameter can be a value from 0 to 255
 * \param[in]  speed Current device speed.
 *          This parameter can be one of these values:
 *            HCD_DEVICE_SPEED_HIGH: High speed mode,
 *            HCD_DEVICE_SPEED_FULL: Full speed mode,
 *            HCD_DEVICE_SPEED_LOW: Low speed mode
 * \param[in]  epType Endpoint Type.
 *          This parameter can be one of these values:
 *            EP_TYPE_CTRL: Control type,
 *            EP_TYPE_ISOC: Isochronous type,
 *            EP_TYPE_BULK: Bulk type,
 *            EP_TYPE_INTR: Interrupt type
 * \param[in]  mps Max Packet Size.
 *          This parameter can be a value from 0 to32K
 * \return  status
 */
status_t HCD_hostChanneInit(HCD_HandleTypeDef_t *hhcd, uint8_t channelNum, uint8_t epnum, uint8_t devAddress,
                            uint8_t speed, uint8_t epType, uint16_t mps);

/*!
 * \brief  Halt a host channel.
 * \param[in]  hhcd HCD handle
 * \param[in]  channelNum Channel number.
 *         This parameter can be a value from 1 to 15
 * \return  status
 */
status_t HCD_hostChanneHalt(HCD_HandleTypeDef_t *hhcd, uint8_t channelNum);
/*!
 * \brief  Initialize the HCD MSP.
 * \param[in]  hhcd HCD handle
 * \return  None
 */
void HCD_mspInit(HCD_HandleTypeDef_t *hhcd);
/*!
 * \brief  DeInitialize the HCD MSP.
 * \param[in]  hhcd HCD handle
 * \return  None
 */
void HCD_mspDeinit(HCD_HandleTypeDef_t *hhcd);

/*!
 * \brief  Submit a new URB for processing.
 * \param[in]  hhcd HCD handle
 * \param[in]  channelNum Channel number.
 *         This parameter can be a value from 1 to 15
 * \param[in]  direction Channel number.
 *          This parameter can be one of these values:
 *           0 : Output / 1 : Input
 * \param[in]  epType Endpoint Type.
 *          This parameter can be one of these values:
 *            EP_TYPE_CTRL: Control type/
 *            EP_TYPE_ISOC: Isochronous type/
 *            EP_TYPE_BULK: Bulk type/
 *            EP_TYPE_INTR: Interrupt type/
 * \param[in]  token Endpoint Type.
 *          This parameter can be one of these values:
 *            0: HC_PID_SETUP / 1: HC_PID_DATA1
 * \param[in]  pbuff pointer to URB data
 * \param[in]  length Length of URB data
 * \param[in]  doPing activate do ping protocol (for high speed only).
 *          This parameter can be one of these values:
 *           0 : do ping inactive / 1 : do ping active
 * \return  status
 */
status_t HCD_hostChannelSubmitRequest(HCD_HandleTypeDef_t *hhcd, uint8_t channelNum, uint8_t direction, uint8_t epType,
                                      uint8_t token, uint8_t *pbuff, uint16_t length, uint8_t doPing);

/*!
 * \brief  Handle HCD interrupt request.
 *         Non-Blocking mode: Interrupt
 * \param[in]  hhcd HCD handle
 * \return  None
 */
void HCD_IRQHandler(HCD_HandleTypeDef_t *hhcd);
/*!
 * \brief  SOF callback.
 * \param[in]  hhcd: HCD handle
 * \return  None
 */
void HCD_sofCallback(HCD_HandleTypeDef_t *hhcd);
/*!
 * \brief  SOF callback.
 * \param[in]  hhcd: HCD handle
 * \return  None
 */
void HCD_connectCallback(HCD_HandleTypeDef_t *hhcd);
/*!
 * \brief  SOF callback.
 * \param[in]  hhcd: HCD handle
 * \return  None
 */
void HCD_disconnectCallback(HCD_HandleTypeDef_t *hhcd);
/*!
 * \brief  Port Port Enabled callback.
 * \param[in]  hhcd: HCD handle
 * \return  None
 */
void HCD_portEnabledCallback(HCD_HandleTypeDef_t *hhcd);
/*!
 * \brief  Port Port Disabled callback.
 * \param[in]  hhcd: HCD handle
 * \return  None
 */
void HCD_portDisabledCallback(HCD_HandleTypeDef_t *hhcd);
/*!
 * \brief  Notify URB state change callback.
 * \param[in]  hhcd HCD handle
 * \param[in]  channelNum Channel number.
 *         This parameter can be a value from 1 to 15
 * \param[in]  urbState:
 *          This parameter can be one of these values:
 *            kURB_IDLE/
 *            kURB_DONE/
 *            kURB_NOTREADY/
 *            URB_NYET/
 *            kURB_ERROR/
 *            kURB_STALL/
 * \return  None
 */
void HCD_hostChannelNotifyURBChangeCallback(HCD_HandleTypeDef_t *hhcd, uint8_t channelNum,
                                            HCD_URBStateTypeDef urbState);
/*!
 * \brief  Reset the host port.
 * \param[in]  hhcd HCD handle
 * \return  status
 */
status_t HCD_resetPort(HCD_HandleTypeDef_t *hhcd);
/*!
 * \brief  Start the host driver.
 * \param[in]  hhcd HCD handle
 * \return  status
 */
status_t HCD_start(HCD_HandleTypeDef_t *hhcd);
/*!
 * \brief  Stop the host driver.
 * \param[in]  hhcd HCD handle
 * \return  status
 */
status_t HCD_stop(HCD_HandleTypeDef_t *hhcd);
/*!
 * \brief  Return the HCD handle state.
 * \param[in]  hhcd HCD handle
 * \return  HAL state
 */
HCD_StateTypeDef_t HCD_getState(HCD_HandleTypeDef_t *hhcd);
/*!
 * \brief  Return  URB state for a channel.
 * \param[in]  hhcd HCD handle
 * \param[in]  channelNum Channel number.
 *         This parameter can be a value from 1 to 15
 * \return  URB state.
 *          This parameter can be one of these values:
 *            kURB_IDLE/
 *            kURB_DONE/
 *            kURB_NOTREADY/
 *            URB_NYET/
 *            kURB_ERROR/
 *            kURB_STALL
 */
HCD_URBStateTypeDef HCD_hostChannelGetURBState(HCD_HandleTypeDef_t *hhcd, uint8_t channelNum);
/*!
 * \brief  Return the Host Channel state.
 * \param[in]  hhcd HCD handle
 * \param[in]  channelNum Channel number.
 *         This parameter can be a value from 1 to 15
 * \return  Host channel state
 *          This parameter can be one of these values:
 *            kHC_IDLE/
 *            kHC_XFRC/
 *            HC_HALTED/
 *            kHC_NYET/
 *            kHC_NAK/
 *            kHC_STALL/
 *            kHC_XACTERR/
 *            kHC_BBLERR/
 *            kHC_DATATGLERR
 */
HCD_HCStateTypeDef HCD_hostChanneGetState(HCD_HandleTypeDef_t *hhcd, uint8_t channelNum);
/*!
 * \brief  Return the last host transfer size.
 * \param[in]  hhcd HCD handle
 * \param[in]  channelNum Channel number.
 *         This parameter can be a value from 1 to 15
 * \return  last transfer size in byte
 */
uint32_t HCD_hostChannelGetXferCount(HCD_HandleTypeDef_t *hhcd, uint8_t channelNum);
/*!
 * \brief  Return the current Host frame number.
 * \param[in]  hhcd HCD handle
 * \return  Current Host frame number
 */
uint32_t HCD_getCurrentFrame(HCD_HandleTypeDef_t *hhcd);
/*!
 * \brief  Return the Host enumeration speed.
 * \param[in]  hhcd HCD handle
 * \return  Enumeration speed
 */
uint32_t HCD_getCurrentSpeed(HCD_HandleTypeDef_t *hhcd);

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */ /* end of DRV_HTE_USB_HCD */

#endif /* HTE_HCD_H */
