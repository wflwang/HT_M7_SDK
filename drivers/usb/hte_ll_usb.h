/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_ll_usb.h
 * \brief SDK USB low-level driver header file
 * \version 1.0.0
 */

#ifndef HTE_LL_USB_H
#define HTE_LL_USB_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_common.h"

/*!
 * \addtogroup DRV_HTE_USB_LL USB Low-level Driver
 *
 * \brief SDK USB low-level driver
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*!
 * \brief  USB lock status
 */
typedef enum
{
    kHTE_UNLOCKED = 0x00,
    kHTE_LOCKED   = 0x01
} USB_OTG_LockTypeDef_t;

/*!
 * \brief  USB Mode
 */
typedef enum
{
    kUSB_DEVICE_MODE = 0,
    kUSB_HOST_MODE   = 1,
    kUSB_DRD_MODE    = 2
} USB_OTG_ModeTypeDef_t;

/*!
 * \brief  URB States definition
 */
typedef enum
{
    kURB_IDLE = 0,
    kURB_DONE,
    kURB_NOTREADY,
    kURB_NYET,
    kURB_ERROR,
    kURB_STALL
} USB_OTG_URBStateTypeDef_t;

/*!
 * \brief  Host channel States  definition
 */
typedef enum
{
    kHC_IDLE = 0,
    kHC_XFRC,
    kHC_HALTED,
    kHC_NAK,
    kHC_NYET,
    kHC_STALL,
    kHC_XACTERR,
    kHC_BBLERR,
    kHC_DATATGLERR
} USB_OTG_HCStateTypeDef_t;

/*!
 * \brief  USB Instance Initialization Structure definition
 */
typedef struct
{
    uint32_t devEndpoints; /*!< Device Endpoints number.
                                 This parameter depends on the used USB core.
                                 This parameter must be a number between Min_Data = 1 and Max_Data = 15 */

    uint32_t hostChannels; /*!< Host Channels number.
                                 This parameter Depends on the used USB core.
                                 This parameter must be a number between Min_Data = 1 and Max_Data = 15 */

    uint32_t speed; /*!< USB Core speed.
                         This parameter can be any value of  PCD_Speed/HCD_Speed
                                                                 (HCD_SPEED_xxx, HCD_SPEED_xxx) */

    uint32_t dmaEnable; /*!< Enable or disable of the USB embedded DMA used only for OTG HS.        */

    uint32_t ep0Mps; /*!< Set the Endpoint 0 Max Packet size.                                    */

    uint32_t phyItface; /*!< Select the used PHY interface.
                              This parameter can be any value of  PCD_PHY_Module/HCD_PHY_Module  */

    uint32_t sofEnable; /*!< Enable or disable the output of the SOF signal.                        */

    uint32_t lowPowerEnable; /*!< Enable or disable the low power mode.                                  */

    uint32_t lpmEnable; /*!< Enable or disable Link Power Management.                               */

    uint32_t batteryChargingEnable; /*!< Enable or disable Battery charging.                                    */

    uint32_t vbusSensingEnable; /*!< Enable or disable the VBUS Sensing feature.                            */

    uint32_t useDedicatedEp1; /*!< Enable or disable the use of the dedicated EP1 interrupt.              */

    uint32_t useExternalVbus; /*!< Enable or disable the use of the external VBUS.                        */

} USB_OTG_CfgTypeDef_t;

typedef struct
{
    uint8_t num; /*!< Endpoint number
                      This parameter must be a number between Min_Data = 1 and Max_Data = 15   */

    uint8_t isIn; /*!< Endpoint direction
                        This parameter must be a number between Min_Data = 0 and Max_Data = 1    */

    uint8_t isStall; /*!< Endpoint stall condition
                           This parameter must be a number between Min_Data = 0 and Max_Data = 1    */

    uint8_t isIsoIncomplete; /*!< Endpoint isoc condition
                                    This parameter must be a number between Min_Data = 0 and Max_Data = 1    */

    uint8_t type; /*!< Endpoint type
                       This parameter can be any value of  USB_LL_EP_Type                   */

    uint8_t dataPidStart; /*!< Initial data PID
                                 This parameter must be a number between Min_Data = 0 and Max_Data = 1    */

    uint8_t evenOddFrame; /*!< IFrame parity
                                 This parameter must be a number between Min_Data = 0 and Max_Data = 1    */

    uint16_t txFifoNum; /*!< Transmission FIFO number
                               This parameter must be a number between Min_Data = 1 and Max_Data = 15   */

    uint32_t maxPacket; /*!< Endpoint Max packet size
                             This parameter must be a number between Min_Data = 0 and Max_Data = 64KB */

    uint8_t *xferBuff; /*!< Pointer to transfer buffer                                               */

    uint32_t dmaAddr; /*!< 32 bits aligned transfer buffer address                                  */

    uint32_t xferLen; /*!< Current transfer length                                                  */

    uint32_t xferSize; /*!< requested transfer size                                                  */

    uint32_t xferCount; /*!< Partial transfer length in case of multi packet transfer                 */
} USB_OTG_EPTypeDef_t;

typedef struct
{
    uint8_t devAddr; /*!< USB device address.
                           This parameter must be a number between Min_Data = 1 and Max_Data = 255    */

    uint8_t channelNum; /*!< Host channel number.
                         This parameter must be a number between Min_Data = 1 and Max_Data = 15     */

    uint8_t epNum; /*!< Endpoint number.
                         This parameter must be a number between Min_Data = 1 and Max_Data = 15     */

    uint8_t epIsIn; /*!< Endpoint direction
                           This parameter must be a number between Min_Data = 0 and Max_Data = 1      */

    uint8_t speed; /*!< USB Host Channel speed.
                        This parameter can be any value of HCD_Device_Speed:
                                                                (HCD_DEVICE_SPEED_xxx)             */

    uint8_t doPing; /*!< Enable or disable the use of the PING protocol for HS mode.                */

    uint8_t processPing; /*!< Execute the PING protocol for HS mode.                                     */

    uint8_t epType; /*!< Endpoint Type.
                          This parameter can be any value of  USB_LL_EP_Type                     */

    uint16_t maxPacket; /*!< Endpoint Max packet size.
                              This parameter must be a number between Min_Data = 0 and Max_Data = 64KB   */

    uint8_t dataPid; /*!< Initial data PID.
                           This parameter must be a number between Min_Data = 0 and Max_Data = 1      */

    uint8_t *xferBuff; /*!< Pointer to transfer buffer.                                                */

    uint32_t xferSize; /*!< OTG Channel transfer size.                                               */

    uint32_t xferLen; /*!< Current transfer length.                                                   */

    uint32_t xferCount; /*!< Partial transfer length in case of multi packet transfer.                  */

    uint8_t toggleIn; /*!< IN transfer current toggle flag.
                            This parameter must be a number between Min_Data = 0 and Max_Data = 1      */

    uint8_t toggleOut; /*!< OUT transfer current toggle flag
                             This parameter must be a number between Min_Data = 0 and Max_Data = 1      */

    uint32_t dmaAddr; /*!< 32 bits aligned transfer buffer address.                                   */

    uint32_t errCnt; /*!< Host channel error count.                                                  */

    USB_OTG_URBStateTypeDef_t urbState; /*!< URB state.
                                             This parameter can be any value of  USB_OTG_URBStateTypeDef_t */

    USB_OTG_HCStateTypeDef_t state; /*!< Host Channel state.
                                        This parameter can be any value of USB_OTG_HCStateTypeDef_t  */
} USB_OTG_HCTypeDef_t;

/*!
 * \defgroup USB_OTG_CORE VERSION ID
 */
#define USB_OTG_CORE_ID_300A 0x4F54300AU
#define USB_OTG_CORE_ID_310A 0x4F54310AU
#define USB_OTG_CORE_ID_400A 0x4F54400AU /* USE */


/*!
 *\defgroup USB_Core_Mode_ USB Core Mode
 */
#define USB_OTG_MODE_DEVICE 0U
#define USB_OTG_MODE_HOST   1U
#define USB_OTG_MODE_DRD    2U


/*!
 *\defgroup USB_LL Device Speed
 */
#define USBD_HS_SPEED     0U
#define USBD_HSINFS_SPEED 1U
#define USBH_HS_SPEED     0U
#define USBD_FS_SPEED     2U
#define USBH_FSLS_SPEED   1U

/*!
 * \defgroup USB_LL_Core_Speed USB Low Layer Core Speed
 */
#define USB_OTG_SPEED_HIGH         0U
#define USB_OTG_SPEED_HIGH_IN_FULL 1U
#define USB_OTG_SPEED_FULL         3U

/*!
 * \defgroup USB_LL_Core_PHY USB Low Layer Core PHY
 */
#define USB_OTG_ULPI_PHY     1U /*not USE*/
#define USB_OTG_EMBEDDED_PHY 2U

/*!
 * \defgroup USB_LL_Turnaround_Timeout Turnaround Timeout Value
 */
#ifndef USBD_HS_TRDT_VALUE
#define USBD_HS_TRDT_VALUE 9U
#endif /* USBD_HS_TRDT_VALUE */
#ifndef USBD_FS_TRDT_VALUE
#define USBD_FS_TRDT_VALUE      5U
#define USBD_DEFAULT_TRDT_VALUE 9U
#endif /* USBD_HS_TRDT_VALUE */
/*!
 * \defgroup USB_LL_Core_MPS USB Low Layer Core MPS
 */
#define USB_OTG_HS_MAX_PACKET_SIZE 512U
#define USB_OTG_FS_MAX_PACKET_SIZE 64U
#define USB_OTG_MAX_EP0_SIZE       64U
/*!
 * \defgroup USB_LL_Core_PHY_Frequency USB Low Layer Core PHY Frequency
 */
#define DSTS_ENUMSPD_HS_PHY_30MHZ_OR_60MHZ (0U << 1)
#define DSTS_ENUMSPD_FS_PHY_30MHZ_OR_60MHZ (1U << 1)
#define DSTS_ENUMSPD_FS_PHY_48MHZ          (3U << 1)

/*!
 * \defgroup USB_LL_CORE_Frame_Interval USB Low Layer Core Frame Interval
 */
#define DCFG_FRAME_INTERVAL_80 0U
#define DCFG_FRAME_INTERVAL_85 1U
#define DCFG_FRAME_INTERVAL_90 2U
#define DCFG_FRAME_INTERVAL_95 3U

/*!
 * \defgroup USB_LL_EP0_MPS USB Low Layer EP0 MPS
 */
#define EP_MPS_64 0U
#define EP_MPS_32 1U
#define EP_MPS_16 2U
#define EP_MPS_8  3U

/*!
 * \defgroup USB_LL_EP_Speed USB Low Layer EP Speed
 */
#define EP_SPEED_LOW  0U
#define EP_SPEED_FULL 1U
#define EP_SPEED_HIGH 2U

/*!
 * \defgroup USB_LL_EP_Type USB Low Layer EP Type
 */
#define EP_TYPE_CTRL 0U
#define EP_TYPE_ISOC 1U
#define EP_TYPE_BULK 2U
#define EP_TYPE_INTR 3U
#define EP_TYPE_MSK  3U
/*!
 * \defgroup USB_LL_STS_Defines USB Low Layer STS Defines
 */
#define STS_GOUT_NAK   1U
#define STS_DATA_UPDT  2U
#define STS_XFER_COMP  3U
#define STS_SETUP_COMP 4U
#define STS_SETUP_UPDT 6U

/*!
 * \defgroup USB_LL_HCFG_SPEED_Defines USB Low Layer HCFG Speed Defines
 */
#define HCFG_30_60_MHZ 0U
#define HCFG_48_MHZ    1U
#define HCFG_6_MHZ     2U

/*!
 * \defgroup USB_LL_HPRT0_PRTSPD_SPEED_Defines USB Low Layer HPRT0 PRTSPD Speed Defines
 */
#define HPRT0_PRTSPD_HIGH_SPEED 0U
#define HPRT0_PRTSPD_FULL_SPEED 1U
#define HPRT0_PRTSPD_LOW_SPEED  2U

#define HCCHAR_CTRL 0U
#define HCCHAR_ISOC 1U
#define HCCHAR_BULK 2U
#define HCCHAR_INTR 3U

#define HC_PID_DATA0 0U
#define HC_PID_DATA2 1U
#define HC_PID_DATA1 2U
#define HC_PID_SETUP 3U

#define GRXSTS_PKTSTS_IN              2U
#define GRXSTS_PKTSTS_IN_XFER_COMP    3U
#define GRXSTS_PKTSTS_DATA_TOGGLE_ERR 5U
#define GRXSTS_PKTSTS_CH_HALTED       7U

#define TEST_J        1U
#define TEST_K        2U
#define TEST_SE0_NAK  3U
#define TEST_PACKET   4U
#define TEST_FORCE_EN 5U

#define USBx_PCGCCTL *(__IO uint32_t *)((uint32_t)USBx_BASE + (0xE00UL))
#define USBx_HPRT0   *(__IO uint32_t *)((uint32_t)USBx_BASE + (0x440UL))

#define USBx_DEVICE  ((USB_OTG_DeviceTypeDef *)(USBx_BASE + USB_OTG_DEVICE_BASE))
#define USBx_INEP(i) ((USB_OTG_INEndpointTypeDef *)(USBx_BASE + (0x900UL) + ((i) * (0x20UL))))

#define USBx_OUTEP(i) ((USB_OTG_OUTEndpointTypeDef *)(USBx_BASE + (0xB00UL) + ((i) * (0x20UL))))

#define USBx_DFIFO(i) *(__IO uint32_t *)(USBx_BASE + (0x1000UL) + ((i) * (0x1000UL)))

#define USBx_HOST  ((USB_OTG_HostTypeDef *)(USBx_BASE + (0x400UL)))
#define USBx_HC(i) ((USB_OTG_HostChannelTypeDef *)(USBx_BASE + (0x500UL) + ((i) * (0x20UL))))


#define EP_ADDR_MSK 0xFU

#ifndef USE_USB_DOUBLE_BUFFER
#define USE_USB_DOUBLE_BUFFER 1U
#endif /* USE_USB_DOUBLE_BUFFER */

/*!
 * \defgroup USB_LL_Exported_Macros USB Low Layer Exported Macros
 */
#define USB_MASK_INTERRUPT(__INSTANCE__, __INTERRUPT__)   ((__INSTANCE__)->GINTMSK &= ~(__INTERRUPT__))
#define USB_UNMASK_INTERRUPT(__INSTANCE__, __INTERRUPT__) ((__INSTANCE__)->GINTMSK |= (__INTERRUPT__))

#define CLEAR_IN_EP_INTR(__EPNUM__, __INTERRUPT__)  (USBA->DIEP_GRPb[__EPNUM__].DIEPINT_N = (__INTERRUPT__))
#define CLEAR_OUT_EP_INTR(__EPNUM__, __INTERRUPT__) (USBA->DOEP_GRPb[__EPNUM__].DOEPINT_N = (__INTERRUPT__))

#define HTE_LOCK(__HANDLE__)                   \
    do                                         \
    {                                          \
        if ((__HANDLE__)->lock == kHTE_LOCKED) \
        {                                      \
            return kSTATUS_INVALID_ARGUMENT;   \
        }                                      \
        else                                   \
        {                                      \
            (__HANDLE__)->lock = kHTE_LOCKED;  \
        }                                      \
    } while (0)

#define HTE_UNLOCK(__HANDLE__)              \
    do                                      \
    {                                       \
        (__HANDLE__)->lock = kHTE_UNLOCKED; \
    } while (0)

/* USB UNUSED functio */
#define USB_UNUSED(var) \
    do                  \
    {                   \
        (void)var;      \
    } while (0)

/* USB enable status */
#define USB_DISABLE 0
#define USB_ENABLE  1

/*******************************************************************************
 * APIs
 ******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*!
 * \brief  handle usb  error
 *
 *
 */
static inline void USB_errorHandler(void)
{
    while (1)
    {
    }
}

/*!
 * \brief  handle usb  irq
 *
 *
 */
void USBA_Handler(void);

/*!
 * \brief  handle usb ep mp irq
 *
 *
 */
void USBA_EP_MP_Handler(void);

/*!
 * \brief  Initializes the USB Core
 * \param[in]  usbBase USB Instance
 * \param[in]  cfg pointer to a USB_OTG_CfgTypeDef_t structure that contains
 *         the configuration information for the specified USBx peripheral.
 * \return  status_t
 */
status_t USB_coreInit(USB_Type *usbBase, USB_OTG_CfgTypeDef_t cfg);

/*!
 * \brief  USB_devInit Initializes the USB_OTG controller registers
 *         for device mode
 * \param[in]  usbBase  Selected device
 * \param[in]  cfg   pointer to a USB_OTG_CfgTypeDef_t structure that contains
 *         the configuration information for the specified USBx peripheral.
 * \return  status_t
 */
status_t USB_devInit(USB_Type *usbBase, USB_OTG_CfgTypeDef_t cfg);

/*!
 * \brief  USB_enableGlobalInt
 *         Enables the controller's Global Int in the AHB Config reg
 * \param[in]  usbBase  Selected device
 * \return  status_t
 */
status_t USB_enableGlobalInt(USB_Type *usbBase);

/*!
 * \brief  USB_disableGlobalInt
 *         Disable the controller's Global Int in the AHB Config reg
 * \param[in]  usbBase  Selected device
 * \return  status_t
 */
status_t USB_disableGlobalInt(USB_Type *usbBase);

/*!
 * \brief  Set the USB turnaround time
 * \param[in]  usbBase USB Instance
 * \param[in]  hclk: AHB clock frequency
 * \return  USB turnaround time In PHY Clocks number
 */
status_t USB_setTurnaroundTime(USB_Type *usbBase, uint32_t hclk, uint8_t speed);

/*!
 * \brief  USB_setCurrentMode Set functional mode
 * \param[in]  usbBase  Selected device
 * \param[in]  mode  current core mode
 *          This parameter can be one of these values:
 *            \arg kUSB_DEVICE_MODE Peripheral mode
 *            \arg kUSB_HOST_MODE Host mode
 * \return  status_t
 */
status_t USB_setCurrentMode(USB_Type *usbBase, USB_OTG_ModeTypeDef_t mode);

/*!
 * \brief  USB_setDevSpeed  Initializes the DevSpd field of DCFG register
 *         depending the PHY type and the enumeration speed of the device.
 * \param[in]  usbBase  Selected device
 * \param[in]  speed  device speed
 *          This parameter can be one of these values:
 *            \arg USB_OTG_SPEED_HIGH: High speed mode
 *            \arg USB_OTG_SPEED_HIGH_IN_FULL: High speed core in Full Speed mode
 *            \arg USB_OTG_SPEED_FULL: Full speed mode
 * \return   Hal status
 */
status_t USB_setDevSpeed(USB_Type *usbBase, uint8_t speed);

/*!
 * \brief  USB_flushRxFifo  Flush Rx FIFO
 * \param[in]  usbBase  Selected device
 * \return  status_t
 */
status_t USB_flushRxFifo(USB_Type *usbBase);

/*!
  * \brief  USB_flushTxFifo Flush a Tx FIFO
  * \param[in]  usbBase  Selected device
  * \param[in]  num  FIFO number
  *         This parameter can be a value from 1 to 15
            15 means Flush all Tx FIFOs
  * \return  status_t
  */
status_t USB_flushTxFifo(USB_Type *usbBase, uint32_t num);

/*!
 * \brief  Activate and configure an endpoint
 * \param[in]  usbBase  Selected device
 * \param[in]  ep pointer to endpoint structure
 * \return  status_t
 */
status_t USB_activateEndpoint(USB_Type *usbBase, USB_OTG_EPTypeDef_t *ep);

/*!
 * \brief  De-activate and de-initialize an endpoint
 * \param[in]  usbBase  Selected device
 * \param[in]  ep pointer to endpoint structure
 * \return  status_t
 */
status_t USB_deactivateEndpoint(USB_Type *usbBase, USB_OTG_EPTypeDef_t *ep);

/*!
 * \brief  Activate and configure a dedicated endpoint
 * \param[in]  usbBase  Selected device
 * \param[in]  ep pointer to endpoint structure
 * \return  status_t
 */
status_t USB_activateDedicatedEndpoint(USB_Type *usbBase, USB_OTG_EPTypeDef_t *ep);

/*!
 * \brief  De-activate and de-initialize a dedicated endpoint
 * \param[in]  usbBase  Selected device
 * \param[in]  ep pointer to endpoint structure
 * \return  status_t
 */
status_t USB_deactivateDedicatedEndpoint(USB_Type *usbBase, USB_OTG_EPTypeDef_t *ep);

/*!
 * \brief  USB_epStartXfer : setup and starts a transfer over an EP
 * \param[in]  usbBase  Selected device
 * \param[in]  ep pointer to endpoint structure
 * \param[in]  dma USB dma enabled or disabled
 *          This parameter can be one of these values:
 *           0 : DMA feature not used
 *           1 : DMA feature used
 * \return  status_t
 */
status_t USB_epStartXfer(USB_Type *usbBase, USB_OTG_EPTypeDef_t *ep, uint8_t dma);

/*!
 * \brief  USB_ep0StartXfer : setup and starts a transfer over the EP  0
 * \param[in]  usbBase  Selected device
 * \param[in]  ep pointer to endpoint structure
 * \param[in]  dma USB dma enabled or disabled
 *          This parameter can be one of these values:
 *           0 : DMA feature not used
 *           1 : DMA feature used
 * \return  status_t
 */
status_t USB_ep0StartXfer(USB_Type *usbBase, USB_OTG_EPTypeDef_t *ep, uint8_t dma);

/*!
 * \brief  USB_writePacket : Writes a packet into the Tx FIFO associated
 *         with the EP/channel
 * \param[in]  usbBase  Selected device
 * \param[in]  src   pointer to source buffer
 * \param[in]  channelEpNum  endpoint or host channel number
 * \param[in]  len  Number of bytes to write
 * \param[in]  dma USB dma enabled or disabled
 *          This parameter can be one of these values:
 *           0 : DMA feature not used
 *           1 : DMA feature used
 * \return  status_t
 */
status_t USB_writePacket(USB_Type *usbBase, uint8_t *src, uint8_t channelEpNum, uint16_t len, uint8_t dma);

/*!
 * \brief  USB_readPacket : read a packet from the RX FIFO
 * \param[in]  usbBase  Selected device
 * \param[in]  dest  source pointer
 * \param[in]  len  Number of bytes to read
 * \return  pointer to destination buffer
 */
void *USB_readPacket(USB_Type *usbBase, uint8_t *dest, uint16_t len);

/*!
 * \brief  USB_epSetStall : set a stall condition over an EP
 * \param[in]  usbBase  Selected device
 * \param[in]  ep pointer to endpoint structure
 * \return  status_t
 */
status_t USB_epSetStall(USB_Type *usbBase, USB_OTG_EPTypeDef_t *ep);

/*!
 * \brief  USB_epClearStall : Clear a stall condition over an EP
 * \param[in]  usbBase  Selected device
 * \param[in]  ep pointer to endpoint structure
 * \return  status_t
 */
status_t USB_epClearStall(USB_Type *usbBase, USB_OTG_EPTypeDef_t *ep);

/*!
 * \brief  USB_EPStoptXfer  Stop transfer on an EP
 * \param[in]  usbBase  usb device instance
 * \param[in]  ep pointer to endpoint structure
 * \return  status_t
 */
status_t USB_epStopXfer(USB_Type *usbBase, USB_OTG_EPTypeDef_t *ep);

/*!
 * \brief  USB_setDevAddress : Stop the usb device mode
 * \param[in]  usbBase  Selected device
 * \param[in]  address  new device address to be assigned
 *          This parameter can be a value from 0 to 255
 * \return  status_t
 */
status_t USB_setDevAddress(USB_Type *usbBase, uint8_t address);

/*!
 * \brief  USB_devConnect : Connect the USB device by enabling Rpu
 * \param[in]  usbBase  Selected device
 * \return  status_t
 */
status_t USB_devConnect(USB_Type *usbBase);

/*!
 * \brief  USB_devDisconnect : Disconnect the USB device by disabling Rpu
 * \param[in]  usbBase  Selected device
 * \return  status_t
 */
status_t USB_devDisconnect(USB_Type *usbBase);

/*!
 * \brief  USB_stopDevice : Stop the usb device mode
 * \param[in]  usbBase  Selected device
 * \return  status_t
 */
status_t USB_stopDevice(USB_Type *usbBase);
/*!
 * \brief  Activate EP0 for Setup transactions
 * \param[in]  usbBase  Selected device
 * \return  status_t
 */
status_t USB_activateSetup(USB_Type *usbBase);

/*!
 * \brief  Prepare the EP0 to start the first control setup
 * \param[in]  usbBase  Selected device
 * \param[in]  dma USB dma enabled or disabled
 *          This parameter can be one of these values:
 *           0 : DMA feature not used
 *           1 : DMA feature used
 * \param[in]  psetup  pointer to setup packet
 * \return  status_t
 */
status_t USB_ep0OutStart(USB_Type *usbBase, uint8_t dma, uint8_t *psetup);

/*!
 * \brief  USB_getDevSpeed  Return the Dev Speed
 * \param[in]  usbBase  Selected device
 * \return  speed  device speed
 *          This parameter can be one of these values:
 *            \arg USBD_HS_SPEED: High speed mode
 *            \arg USBD_FS_SPEED: Full speed mode
 */
uint8_t USB_getDevSpeed(USB_Type *usbBase);

/*!
 * \brief  Returns USB core mode
 * \param[in]  usbBase  Selected device
 * \return  return core mode : Host or Device
 *          This parameter can be one of these values:
 *           0 : Host
 *           1 : Device
 */
uint32_t USB_getMode(USB_Type *usbBase);

/*!
 * \brief  USB_readInterrupts: return the global USB interrupt status
 * \param[in]  usbBase  Selected device
 * \return  status_t
 */
uint32_t USB_readInterrupts(USB_Type *usbBase);

/*!
 * \brief  USB_readDevAllOutEpInterrupt: return the USB device OUT endpoints interrupt status
 * \param[in]  usbBase  Selected device
 * \return  status_t
 */
uint32_t USB_readDevAllOutEpInterrupt(USB_Type *usbBase);

/*!
 * \brief  Returns Device OUT EP Interrupt register
 * \param[in]  usbBase  Selected device
 * \param[in]  epnum  endpoint number
 *          This parameter can be a value from 0 to 15
 * \return  Device OUT EP Interrupt register
 */
uint32_t USB_readDevOutEPInterrupt(USB_Type *usbBase, uint8_t epnum);

/*!
 * \brief  USB_readDevAllInEpInterrupt: return the USB device IN endpoints interrupt status
 * \param[in]  usbBase  Selected device
 * \return  status_t
 */
uint32_t USB_readDevAllInEpInterrupt(USB_Type *usbBase);

/*!
 * \brief  Returns Device IN EP Interrupt register
 * \param[in]  usbBase  Selected device
 * \param[in]  epnum  endpoint number
 *          This parameter can be a value from 0 to 15
 * \return  Device IN EP Interrupt register
 */
uint32_t USB_readDevInEPInterrupt(USB_Type *usbBase, uint8_t epnum);

/*!
 * \brief  USB_clearInterrupts: clear a USB interrupt
 * \param[in]  usbBase  Selected device
 * \param[in]  interrupt  flag
 *
 */
void USB_clearInterrupts(USB_Type *usbBase, uint32_t interrupt);

/*!
 * \brief  USB_hostInit : Initializes the USB OTG controller registers
 *         for Host mode
 * \param[in]  usbBase  Selected device
 * \param[in]  cfg   pointer to a USB_OTG_CfgTypeDef_t structure that contains
 *         the configuration information for the specified USBx peripheral.
 * \return  status_t
 */
status_t USB_hostInit(USB_Type *usbBase, USB_OTG_CfgTypeDef_t cfg);

/*!
 * \brief  USB_initFSLSPClkSel : Initializes the FSLSPClkSel field of the
 *         HCFG register on the PHY type and set the right frame interval
 * \param[in]  usbBase  Selected device
 * \param[in]  freq  clock frequency
 *          This parameter can be one of these values:
 *           HCFG_48_MHZ : Full Speed 48 MHz Clock
 *           HCFG_6_MHZ : Low Speed 6 MHz Clock
 * \return  status_t
 */
status_t USB_initFSLSPClkSel(USB_Type *usbBase, uint8_t freq);

/*!
 * \brief  USB_OTG_ResetPort : Reset Host Port
 * \param[in]  usbBase  Selected device
 * \return  status_t
 * \note (1)The application must wait at least 10 ms
 *   before clearing the reset bit.
 */
status_t USB_resetPort(USB_Type *usbBase);

/*!
 * \brief  USB_driveVbus : activate or de-activate vbus
 * \param[in]  state  VBUS state
 *          This parameter can be one of these values:
 *           0 : Deactivate VBUS
 *           1 : Activate VBUS
 * \return  status_t
 */
status_t USB_driveVbus(USB_Type *usbBase, uint8_t state);

/*!
 * \brief  Return Host Core speed
 * \param[in]  usbBase  Selected device
 * \return  speed : Host speed
 *          This parameter can be one of these values:
 *            \arg HCD_SPEED_HIGH: High speed mode
 *            \arg HCD_SPEED_FULL: Full speed mode
 *            \arg HCD_SPEED_LOW: Low speed mode
 */
uint32_t USB_getHostSpeed(USB_Type *usbBase);

/*!
 * \brief  Return Host Current Frame number
 * \param[in]  usbBase  Selected device
 * \return  current frame number
 */
uint32_t USB_getCurrentFrame(USB_Type *usbBase);

/*!
 * \brief  Initialize a host channel
 * \param[in]  usbBase  Selected device
 * \param[in]  ch_num  Channel number
 *         This parameter can be a value from 1 to 15
 * \param[in]  epnum  Endpoint number
 *          This parameter can be a value from 1 to 15
 * \param[in]  dev_address  Current device address
 *          This parameter can be a value from 0 to 255
 * \param[in]  speed  Current device speed
 *          This parameter can be one of these values:
 *            \arg USB_OTG_SPEED_HIGH: High speed mode
 *            \arg USB_OTG_SPEED_FULL: Full speed mode
 *            \arg USB_OTG_SPEED_LOW: Low speed mode
 * \param[in]  epType  Endpoint Type
 *          This parameter can be one of these values:
 *            \arg EP_TYPE_CTRL: Control type
 *            \arg EP_TYPE_ISOC: Isochronous type
 *            \arg EP_TYPE_BULK: Bulk type
 *            \arg EP_TYPE_INTR: Interrupt type
 * \param[in]  mps  Max Packet Size
 *          This parameter can be a value from 0 to 32K
 * \return  status_t
 */
status_t USB_hostChannelInit(USB_Type *usbBase, uint8_t ch_num, uint8_t epnum, uint8_t dev_address, uint8_t speed,
                             uint8_t epType, uint16_t mps);

/*!
 * \brief  Start a transfer over a host channel
 * \param[in]  usbBase  Selected device
 * \param[in]  hc  pointer to host channel structure
 * \param[in]  dma USB dma enabled or disabled
 *          This parameter can be one of these values:
 *           0 : DMA feature not used
 *           1 : DMA feature used
 * \return  status_t
 */
status_t USB_hostChannelStartXfer(USB_Type *usbBase, USB_OTG_HCTypeDef_t *hc, uint8_t dma);

/*!
 * \brief Read all host channel interrupts status
 * \param[in]  usbBase  Selected device
 * \return  status_t
 */
uint32_t USB_hostChannelReadInterrupt(USB_Type *usbBase);

/*!
 * \brief  Halt a host channel
 * \param[in]  usbBase  Selected device
 * \param[in]  hc_num  Host Channel number
 *         This parameter can be a value from 1 to 15
 * \return  status_t
 */
status_t USB_hostChannelHalt(USB_Type *usbBase, uint8_t hc_num);

/*!
 * \brief  Initiate Do Ping protocol
 * \param[in]  usbBase  Selected device
 * \param[in]  hc_num  Host Channel number
 *         This parameter can be a value from 1 to 15
 * \return  status_t
 */
status_t USB_doPing(USB_Type *usbBase, uint8_t ch_num);

/*!
 * \brief  Stop Host Core
 * \param[in]  usbBase  Selected device
 * \return  status_t
 */
status_t USB_stopHost(USB_Type *usbBase);

/*!
 * \brief  USB_activateRemoteWakeup active remote wakeup signalling
 * \param[in]  usbBase Selected device
 * \return  status_t
 */
status_t USB_activateRemoteWakeup(USB_Type *usbBase);

/*!
 * \brief  USB_deActivateRemoteWakeup de-active remote wakeup signalling
 * \param[in]  usbBase Selected device
 * \return  status_t
 */
status_t USB_deactivateRemoteWakeup(USB_Type *usbBase);

#ifdef __cplusplus
}
#endif /* __cplusplus */

/*!
 * @}
 */ /* end of DRV_HTE_USB_LL */

#endif /* HTE_LL_USB_H */
