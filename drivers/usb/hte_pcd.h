/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_pcd.h
 * \brief SDK USB peripheral control driver header file
 * \version 1.0.0
 */

#ifndef HTE_PCD_H
#define HTE_PCD_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_ll_usb.h"

/*!
 * \addtogroup DRV_HTE_USB_PCD USB Peripheral Control Driver
 *
 * \brief SDK USB peripheral control driver
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* PCD state */
typedef enum
{
    kPCD_STATE_RESET   = 0x00,
    kPCD_STATE_READY   = 0x01,
    kPCD_STATE_ERROR   = 0x02,
    kPCD_STATE_BUSY    = 0x03,
    kPCD_STATE_TIMEOUT = 0x04
} PCD_StateTypeDef_t;

/* Device LPM suspend state */
typedef enum
{
    kLPM_L0 = 0x00, /* on */
    kLPM_L1 = 0x01, /* LPM L1 sleep */
    kLPM_L2 = 0x02, /* suspend */
    kLPM_L3 = 0x03, /* off */
} PCD_LPM_StateTypeDef_t;

typedef enum
{
    kPCD_LPM_L0_ACTIVE = 0x00, /* on */
    kPCD_LPM_L1_ACTIVE = 0x01, /* LPM L1 sleep */
} PCD_LPM_MsgTypeDef_t;

typedef enum
{
    kPCD_BCD_ERROR                    = 0xFF,
    kPCD_BCD_CONTACT_DETECTION        = 0xFE,
    kPCD_BCD_STD_DOWNSTREAM_PORT      = 0xFD,
    kPCD_BCD_CHARGING_DOWNSTREAM_PORT = 0xFC,
    kPCD_BCD_DEDICATED_CHARGING_PORT  = 0xFB,
    kPCD_BCD_DISCOVERY_COMPLETED      = 0x00,
} PCD_BCD_MsgTypeDef_t;

typedef USB_Type             PCD_TypeDef;
typedef USB_OTG_CfgTypeDef_t PCD_InitTypeDef;
typedef USB_OTG_EPTypeDef_t  PCD_EPTypeDef;

/*!
 * \brief  PCD Handle Structure definition
 */
typedef struct
{
    PCD_TypeDef            *instance;   /*!< Register base address             */
    PCD_InitTypeDef         init;       /*!< PCD required parameters           */
    __IO uint8_t            usbAddress; /*!< USB Address                       */
    PCD_EPTypeDef           inEp[16];   /*!< IN endpoint parameters            */
    PCD_EPTypeDef           outEp[16];  /*!< OUT endpoint parameters           */
    USB_OTG_LockTypeDef_t   lock;       /*!< PCD peripheral status             */
    __IO PCD_StateTypeDef_t state;      /*!< PCD communication state           */
    __IO uint32_t           errorCode;  /*!< PCD Error code                    */
    uint32_t                setup[12];  /*!< Setup packet buffer               */
    PCD_LPM_StateTypeDef_t  lpmState;   /*!< LPM State                         */
    uint32_t                BESL;
    uint32_t                frameNumber; /*!< Store Current Frame number        */


    uint32_t lpmActive; /*!< Enable or disable the Link Power Management .
                         This parameter can be set to ENABLE or DISABLE        */

    uint32_t batteryChargingActive; /*!< Enable or disable Battery charging.
                                      This parameter can be set to ENABLE or DISABLE        */
    void *pData;                    /*!< Pointer to upper stack Handler */
} PCD_HandleTypeDef_t;

/* Include PCD HAL Extended module */
#include "hte_pcd_ex.h"

#define PCD_SPEED_HIGH         USBD_HS_SPEED
#define PCD_SPEED_HIGH_IN_FULL USBD_HSINFS_SPEED
#define PCD_SPEED_FULL         USBD_FS_SPEED

/*! \defgroup PCD_PHY_Module PCD PHY Module
 */
#define PCD_PHY_ULPI     1U
#define PCD_PHY_EMBEDDED 2U
#define PCD_PHY_UTMI     3U

/*! \defgroup PCD_Exported_Macros PCD Exported Macros
 *  \brief macros to handle interrupts and specific clock configurations
 */
#define PCD_ENABLE(__HANDLE__)  (void)USB_enableGlobalInt((__HANDLE__)->instance)
#define PCD_DISABLE(__HANDLE__) (void)USB_disableGlobalInt((__HANDLE__)->instance)

#define PCD_GET_FLAG(__HANDLE__, __INTERRUPT__) \
    ((USB_readInterrupts((__HANDLE__)->instance) & (__INTERRUPT__)) == (__INTERRUPT__))

#define PCD_CLEAR_FLAG(__HANDLE__, __INTERRUPT__) (((__HANDLE__)->instance->GINTSTS) &= (__INTERRUPT__))
#define PCD_IS_INVALID_INTERRUPT(__HANDLE__)      (USB_readInterrupts((__HANDLE__)->instance) == 0U)

#define PCD_UNGATE_PHYCLOCK(__HANDLE__) \
    *(__IO uint32_t *)((uint32_t)((__HANDLE__)->instance) + (0xE00UL)) &= ~(USB_PCGCCTL_STOP_PCLK_Set(1U))

#define PCD_GATE_PHYCLOCK(__HANDLE__) \
    *(__IO uint32_t *)((uint32_t)((__HANDLE__)->instance) + (0xE00UL)) |= USB_PCGCCTL_STOP_PCLK_Set(1U)

#define PCD_IS_PHY_SUSPENDED(__HANDLE__) ((*(__IO uint32_t *)((uint32_t)((__HANDLE__)->instance) + (0xE00UL))) & 0x10U)

#ifndef USB_OTG_DOEPINT_OTEPSPR
#define USB_OTG_DOEPINT_OTEPSPR (0x1UL << 5) /*!< Status Phase Received interrupt */
#endif                                       /* defined USB_OTG_DOEPINT_OTEPSPR */

#ifndef USB_OTG_DOEPMSK_OTEPSPRM
#define USB_OTG_DOEPMSK_OTEPSPRM (0x1UL << 5) /*!< Setup Packet Received interrupt mask */
#endif                                        /* defined USB_OTG_DOEPMSK_OTEPSPRM */

#ifndef USB_OTG_DOEPINT_NAK
#define USB_OTG_DOEPINT_NAK (0x1UL << 13) /*!< NAK interrupt */
#endif                                    /* defined USB_OTG_DOEPINT_NAK */

#ifndef USB_OTG_DOEPMSK_NAKM
#define USB_OTG_DOEPMSK_NAKM (0x1UL << 13) /*!< OUT Packet NAK interrupt mask */
#endif                                     /* defined USB_OTG_DOEPMSK_NAKM */

#ifndef USB_OTG_DOEPINT_STPKTRX
#define USB_OTG_DOEPINT_STPKTRX (0x1UL << 15) /*!< Setup Packet Received interrupt */
#endif                                        /* defined USB_OTG_DOEPINT_STPKTRX */

#ifndef USB_OTG_DOEPMSK_NYETM
#define USB_OTG_DOEPMSK_NYETM (0x1UL << 14) /*!< Setup Packet Received interrupt mask */
#endif                                      /* defined USB_OTG_DOEPMSK_NYETM */

/*******************************************************************************
 * Variables
 ******************************************************************************/
extern PCD_HandleTypeDef_t g_pcdHandle;

/*******************************************************************************
 * APIs
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief  Initializes the PCD according to the specified
 *         parameters in the PCD_InitTypeDef and initialize the associated handle.
 * \param[in]  hpcd PCD handle
 * \return  status_t
 */
status_t PCD_init(PCD_HandleTypeDef_t *hpcd);
/*!
 * \brief  DeInitializes the PCD peripheral.
 * \param[in]  hpcd PCD handle
 * \return  status_t
 */
status_t PCD_deInit(PCD_HandleTypeDef_t *hpcd);
/*!
 * \brief  Initializes the PCD MSP.
 * \param[in]  hpcd PCD handle
 * \return  None
 */
void PCD_mspInit(PCD_HandleTypeDef_t *hpcd);
/*!
 * \brief  DeInitializes PCD MSP.
 * \param[in]  hpcd PCD handle
 * \return  None
 */
void PCD_mspDeInit(PCD_HandleTypeDef_t *hpcd);

/*!
 * \brief  Start the USB device
 * \param[in]  hpcd PCD handle
 * \return  status_t
 */
status_t PCD_start(PCD_HandleTypeDef_t *hpcd);
/*!
 * \brief  Stop the USB device.
 * \param[in]  hpcd PCD handle
 * \return  status_t
 */
status_t PCD_stop(PCD_HandleTypeDef_t *hpcd);

/*!
 * \brief  Handles PCD interrupt request.
 * \param[in]  hpcd PCD handle
 * \return  None
 */
void PCD_IRQHandler(PCD_HandleTypeDef_t *hpcd);
/*!
 * \brief  SOF callback.
 * \param[in]  hpcd: PCD handle
 * \return  None
 */
void PCD_sofCallback(PCD_HandleTypeDef_t *hpcd);
/*!
 * \brief  Setup stage callback
 * \param[in]  hpcd: PCD handle
 * \return  None
 */
void PCD_setupStageCallback(PCD_HandleTypeDef_t *hpcd);
/*!
 * \brief  Reset callback.
 * \param[in]  hpcd: PCD handle
 * \return  None
 */
void PCD_resetCallback(PCD_HandleTypeDef_t *hpcd);
/*!
 * \brief  Suspend callback.
 * When Low power mode is enabled the debug cannot be used (IAR, Keil doesn't support it)
 * \param[in]  hpcd: PCD handle
 * \return  None
 */
void PCD_suspendCallback(PCD_HandleTypeDef_t *hpcd);
/*!
 * \brief  Resume callback.
 * When Low power mode is enabled the debug cannot be used (IAR, Keil doesn't support it)
 * \param[in]  hpcd: PCD handle
 * \return  None
 */
void PCD_resumeCallback(PCD_HandleTypeDef_t *hpcd);
/*!
 * \brief  Connect callback.
 * \param[in]  hpcd: PCD handle
 * \return  None
 */
void PCD_connectCallback(PCD_HandleTypeDef_t *hpcd);
/*!
 * \brief  Disconnect callback.
 * \param[in]  hpcd: PCD handle
 * \return  None
 */
void PCD_disconnectCallback(PCD_HandleTypeDef_t *hpcd);
/*!
 * \brief  Data Out stage callback.
 * \param[in]  hpcd: PCD handle
 * \param[in]  epnum: Endpoint number
 * \return  None
 */
void PCD_dataOutStageCallback(PCD_HandleTypeDef_t *hpcd, uint8_t epnum);
/*!
 * \brief  Data In stage callback.
 * \param[in]  hpcd: PCD handle
 * \param[in]  epnum: Endpoint number
 * \return  None
 */
void PCD_dataInStageCallback(PCD_HandleTypeDef_t *hpcd, uint8_t epnum);
/*!
 * \brief  Incomplete ISO OUT callback.
 * \param[in]  hpcd PCD handle
 * \param[in]  epnum endpoint number
 * \return  None
 */
void PCD_ISOOUTIncompleteCallback(PCD_HandleTypeDef_t *hpcd, uint8_t epnum);
/*!
 * \brief  Incomplete ISO IN callback.
 * \param[in]  hpcd PCD handle
 * \param[in]  epnum endpoint number
 * \return  None
 */
void PCD_ISOINIncompleteCallback(PCD_HandleTypeDef_t *hpcd, uint8_t epnum);

/*!
 * \brief  Connect the USB device
 * \param[in]  hpcd PCD handle
 * \return  status_t
 */
status_t PCD_devConnect(PCD_HandleTypeDef_t *hpcd);
/*!
 * \brief  Disconnect the USB device.
 * \param[in]  hpcd PCD handle
 * \return  status_t
 */
status_t PCD_devDisconnect(PCD_HandleTypeDef_t *hpcd);
/*!
 * \brief  Set the USB Device address.
 * \param[in]  hpcd PCD handle
 * \param[in]  address new device address
 * \return  status_t
 */
status_t PCD_setAddress(PCD_HandleTypeDef_t *hpcd, uint8_t address);
/*!
 * \brief  Open and configure an endpoint.
 * \param[in]  hpcd PCD handle
 * \param[in]  epAddr endpoint address
 * \param[in]  epMps endpoint max packet size
 * \param[in]  epType endpoint type
 * \return  status_t
 */
status_t PCD_EP_open(PCD_HandleTypeDef_t *hpcd, uint8_t epAddr, uint16_t epMps, uint8_t epType);
/*!
 * \brief  Deactivate an endpoint.
 * \param[in]  hpcd PCD handle
 * \param[in]  epAddr endpoint address
 * \return  status_t
 */
status_t PCD_EP_close(PCD_HandleTypeDef_t *hpcd, uint8_t epAddr);
/*!
 * \brief  Receive an amount of data.
 * \param[in]  hpcd PCD handle
 * \param[in]  epAddr endpoint address
 * \param[in]  pBuf pointer to the reception buffer
 * \param[in]  len amount of data to be received
 * \return  status_t
 */
status_t PCD_EP_receive(PCD_HandleTypeDef_t *hpcd, uint8_t epAddr, uint8_t *pBuf, uint32_t len);
/*!
 * \brief  Send an amount of data
 * \param[in]  hpcd PCD handle
 * \param[in]  epAddr endpoint address
 * \param[in]  pBuf pointer to the transmission buffer
 * \param[in]  len amount of data to be sent
 * \return  status_t
 */
status_t PCD_EP_transmit(PCD_HandleTypeDef_t *hpcd, uint8_t epAddr, uint8_t *pBuf, uint32_t len);
/*!
 * \brief  Set a STALL condition over an endpoint
 * \param[in]  hpcd PCD handle
 * \param[in]  epAddr endpoint address
 * \return  status_t
 */
status_t PCD_EP_setStall(PCD_HandleTypeDef_t *hpcd, uint8_t epAddr);
/*!
 * \brief  Clear a STALL condition over in an endpoint
 * \param[in]  hpcd PCD handle
 * \param[in]  epAddr endpoint address
 * \return  status_t
 */
status_t PCD_EP_clrStall(PCD_HandleTypeDef_t *hpcd, uint8_t epAddr);
/*!
 * \brief  Flush an endpoint
 * \param[in]  hpcd PCD handle
 * \param[in]  epAddr endpoint address
 * \return  status_t
 */
status_t PCD_EP_flush(PCD_HandleTypeDef_t *hpcd, uint8_t epAddr);
/*!
 * \brief  Abort an USB EP transaction.
 * \param[in]  hpcd PCD handle
 * \param[in]  epAddr endpoint address
 * \return  status_t
 */
status_t PCD_EP_abort(PCD_HandleTypeDef_t *hpcd, uint8_t epAddr);
/*!
 * \brief  Activate remote wakeup signalling
 * \param[in]  hpcd PCD handle
 * \return  status_t
 */
status_t PCD_activateRemoteWakeup(PCD_HandleTypeDef_t *hpcd);
/*!
 * \brief  De-activate remote wakeup signalling.
 * \param[in]  hpcd PCD handle
 * \return  status_t
 */
status_t PCD_deactivateRemoteWakeup(PCD_HandleTypeDef_t *hpcd);
/*!
 * \brief  Set the USB Device high speed test mode.
 * \param[in]  hpcd PCD handle
 * \param[in]  testMode USB Device high speed test mode
 * \return  status_t
 */
status_t PCD_setTestMode(PCD_HandleTypeDef_t *hpcd, uint8_t testMode);
/*!
 * \brief  Get Received Data Size
 * \param[in]  hpcd PCD handle
 * \param[in]  epAddr endpoint address
 * \return  Data Size
 */
uint32_t PCD_EP_getRxCount(PCD_HandleTypeDef_t *hpcd, uint8_t epAddr);
/*!
 * \brief  Return the PCD handle state.
 * \param[in]  hpcd PCD handle
 * \return  PCD_StateTypeDef_t
 */
PCD_StateTypeDef_t PCD_getState(PCD_HandleTypeDef_t *hpcd);

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */ /* end of DRV_HTE_USB_PCD */

#endif /* HTE_PCD_H */
