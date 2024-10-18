/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_hcd.c
 * \brief SDK USB host controller driver source file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_common.h"
#include "hte_debug_console.h"
#include "hte_hcd.h"
#include "hte_ll_usb.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* No Definitions */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * \brief  Handle Host Channel IN interrupt requests.
 * \param[in]  hhcd HCD handle
 * \param[in]  channelNum Channel number.
 *         This parameter can be a value from 1 to 15
 *
 */
static void HCD_hostChannelInIRQHandler(HCD_HandleTypeDef_t *hhcd, uint8_t channelNum);
/*!
 * \brief  Handle Host Channel OUT interrupt requests.
 * \param[in]  hhcd HCD handle
 * \param[in]  channelNum Channel number.
 *         This parameter can be a value from 1 to 15
 *
 */
static void HCD_hostChannelOutIRQHandler(HCD_HandleTypeDef_t *hhcd, uint8_t channelNum);
/*!
 * \brief  Handle Rx Queue Level interrupt requests.
 * \param[in]  hhcd HCD handle
 *
 */
static void HCD_RXQLVLIRQHandler(HCD_HandleTypeDef_t *hhcd);
/*!
 * \brief  Handle Host Port interrupt requests.
 * \param[in]  hhcd HCD handle
 *
 */
static void HCD_portIRQHandler(HCD_HandleTypeDef_t *hhcd);

/*******************************************************************************
 * Variables
 ******************************************************************************/
HCD_HandleTypeDef_t g_hcdHandle;
/*******************************************************************************
 * Codes
 ******************************************************************************/
status_t HCD_init(HCD_HandleTypeDef_t *hhcd)
{
    /* Check the HCD handle allocation */
    if (hhcd == NULL)
    {
        return kSTATUS_FAIL;
    }

    if (hhcd->state == kHCD_STATE_RESET)
    {
        /* Allocate lock resource and initialize it */
        hhcd->lock = kHTE_UNLOCKED;

        /* Init the low level hardware : GPIO, CLOCK, NVIC... */
        HCD_mspInit(hhcd);
    }

    hhcd->state = kHCD_STATE_BUSY;

    /* Disable the Interrupts */
    HCD_DISABLE(hhcd);

    /* Init the Core (common init.) */
    (void)USB_coreInit(hhcd->instance, hhcd->init);

    /* Force Host Mode*/
    (void)USB_setCurrentMode(hhcd->instance, kUSB_HOST_MODE);

    /* Init Host */
    (void)USB_hostInit(hhcd->instance, hhcd->init);

    hhcd->state = kHCD_STATE_READY;

    return kSTATUS_SUCCESS;
}

status_t HCD_hostChanneInit(HCD_HandleTypeDef_t *hhcd, uint8_t channelNum, uint8_t epnum, uint8_t devAddress,
                            uint8_t speed, uint8_t epType, uint16_t mps)
{
    status_t status;

    HTE_LOCK(hhcd);
    hhcd->hc[channelNum].doPing     = 0U;
    hhcd->hc[channelNum].devAddr    = devAddress;
    hhcd->hc[channelNum].maxPacket  = mps;
    hhcd->hc[channelNum].channelNum = channelNum;
    hhcd->hc[channelNum].epType     = epType;
    hhcd->hc[channelNum].epNum      = epnum & 0x7FU;

    if ((epnum & 0x80U) == 0x80U)
    {
        hhcd->hc[channelNum].epIsIn = 1U;
    }
    else
    {
        hhcd->hc[channelNum].epIsIn = 0U;
    }

    hhcd->hc[channelNum].speed = speed;

    status = USB_hostChannelInit(hhcd->instance, channelNum, epnum, devAddress, speed, epType, mps);
    HTE_UNLOCK(hhcd);

    return status;
}

status_t HCD_hostChanneHalt(HCD_HandleTypeDef_t *hhcd, uint8_t channelNum)
{
    status_t status = kSTATUS_SUCCESS;

    HTE_LOCK(hhcd);
    (void)USB_hostChannelHalt(hhcd->instance, (uint8_t)channelNum);
    HTE_UNLOCK(hhcd);

    return status;
}

status_t HCD_deinit(HCD_HandleTypeDef_t *hhcd)
{
    /* Check the HCD handle allocation */
    if (hhcd == NULL)
    {
        return kSTATUS_FAIL;
    }

    hhcd->state = kHCD_STATE_BUSY;

    /* DeInit the low level hardware: CLOCK, NVIC.*/
    HCD_mspDeinit(hhcd);

    HCD_DISABLE(hhcd);

    hhcd->state = kHCD_STATE_RESET;

    return kSTATUS_SUCCESS;
}

__WEAK void HCD_mspInit(HCD_HandleTypeDef_t *hhcd)
{
    /* Prevent unused argument(s) compilation warning */
    USB_UNUSED(hhcd);

    /* NOTE : This function should not be modified, when the callback is needed,
              the HCD_mspInit could be implemented in the user file
     */
}

__WEAK void HCD_mspDeinit(HCD_HandleTypeDef_t *hhcd)
{
    /* Prevent unused argument(s) compilation warning */
    USB_UNUSED(hhcd);

    /* NOTE : This function should not be modified, when the callback is needed,
              the HCD_mspDeinit could be implemented in the user file
     */
}

status_t HCD_hostChannelSubmitRequest(HCD_HandleTypeDef_t *hhcd, uint8_t channelNum, uint8_t direction, uint8_t epType,
                                      uint8_t token, uint8_t *pbuff, uint16_t length, uint8_t doPing)
{
    hhcd->hc[channelNum].epIsIn = direction;
    hhcd->hc[channelNum].epType = epType;

    if (token == 0U)
    {
        hhcd->hc[channelNum].dataPid = HC_PID_SETUP;
        hhcd->hc[channelNum].doPing  = doPing;
    }
    else
    {
        hhcd->hc[channelNum].dataPid = HC_PID_DATA1;
    }

    /* Manage Data Toggle */
    switch (epType)
    {
        case EP_TYPE_CTRL:
            if ((token == 1U) && (direction == 0U)) /*send data */
            {
                if (length == 0U)
                {
                    /* For Status OUT stage, Length==0, Status Out PID = 1 */
                    hhcd->hc[channelNum].toggleOut = 1U;
                }

                /* Set the Data Toggle bit as per the Flag */
                if (hhcd->hc[channelNum].toggleOut == 0U)
                {
                    /* Put the PID 0 */
                    hhcd->hc[channelNum].dataPid = HC_PID_DATA0;
                }
                else
                {
                    /* Put the PID 1 */
                    hhcd->hc[channelNum].dataPid = HC_PID_DATA1;
                }
            }
            break;

        case EP_TYPE_BULK:
            if (direction == 0U)
            {
                /* Set the Data Toggle bit as per the Flag */
                if (hhcd->hc[channelNum].toggleOut == 0U)
                {
                    /* Put the PID 0 */
                    hhcd->hc[channelNum].dataPid = HC_PID_DATA0;
                }
                else
                {
                    /* Put the PID 1 */
                    hhcd->hc[channelNum].dataPid = HC_PID_DATA1;
                }
            }
            else
            {
                if (hhcd->hc[channelNum].toggleIn == 0U)
                {
                    hhcd->hc[channelNum].dataPid = HC_PID_DATA0;
                }
                else
                {
                    hhcd->hc[channelNum].dataPid = HC_PID_DATA1;
                }
            }

            break;
        case EP_TYPE_INTR:
            if (direction == 0U)
            {
                /* Set the Data Toggle bit as per the Flag */
                if (hhcd->hc[channelNum].toggleOut == 0U)
                {
                    /* Put the PID 0 */
                    hhcd->hc[channelNum].dataPid = HC_PID_DATA0;
                }
                else
                {
                    /* Put the PID 1 */
                    hhcd->hc[channelNum].dataPid = HC_PID_DATA1;
                }
            }
            else
            {
                if (hhcd->hc[channelNum].toggleIn == 0U)
                {
                    hhcd->hc[channelNum].dataPid = HC_PID_DATA0;
                }
                else
                {
                    hhcd->hc[channelNum].dataPid = HC_PID_DATA1;
                }
            }
            break;

        case EP_TYPE_ISOC:
            hhcd->hc[channelNum].dataPid = HC_PID_DATA0;
            break;

        default:
            break;
    }

    hhcd->hc[channelNum].xferBuff   = pbuff;
    hhcd->hc[channelNum].xferLen    = length;
    hhcd->hc[channelNum].urbState   = kURB_IDLE;
    hhcd->hc[channelNum].xferCount  = 0U;
    hhcd->hc[channelNum].channelNum = channelNum;
    hhcd->hc[channelNum].state      = kHC_IDLE;

    return USB_hostChannelStartXfer(hhcd->instance, &hhcd->hc[channelNum], (uint8_t)hhcd->init.dmaEnable);
}

void HCD_IRQHandler(HCD_HandleTypeDef_t *hhcd)
{
    USB_Type *usbBase = hhcd->instance;
    uint32_t  i, interrupt;

    /* Ensure that we are in device mode */
    if (USB_getMode(hhcd->instance) == USB_OTG_MODE_HOST)
    {
        /* Avoid spurious interrupt */
        if (HCD_IS_INVALID_INTERRUPT(hhcd))
        {
            return;
        }

        if (HCD_GET_FLAG(hhcd, USB_GINTSTS_INCOMPL_P_Msk))
        {
            /* Incorrect mode, acknowledge the interrupt */
            HCD_CLEAR_FLAG(hhcd, USB_GINTSTS_INCOMPL_P_Msk);
        }

        if (HCD_GET_FLAG(hhcd, USB_GINTSTS_INCOMP_ISO_IN_Msk))
        {
            /* Incorrect mode, acknowledge the interrupt */
            HCD_CLEAR_FLAG(hhcd, USB_GINTSTS_INCOMP_ISO_IN_Msk);
        }

        if (HCD_GET_FLAG(hhcd, USB_GINTSTS_PTXF_EMP_Msk))
        {
            /* Incorrect mode, acknowledge the interrupt */
            HCD_CLEAR_FLAG(hhcd, USB_GINTSTS_PTXF_EMP_Msk);
        }

        if (HCD_GET_FLAG(hhcd, USB_GINTSTS_MODE_MIS_Msk))
        {
            /* Incorrect mode, acknowledge the interrupt */
            HCD_CLEAR_FLAG(hhcd, USB_GINTSTS_MODE_MIS_Msk);
        }

        /* Handle Host Disconnect Interrupts */
        if (HCD_GET_FLAG(hhcd, USB_GINTSTS_DISCONN_INT_Msk))
        {
            HCD_CLEAR_FLAG(hhcd, USB_GINTSTS_DISCONN_INT_Msk);

            if ((usbBase->HPRT & USB_HPRT_PRT_CONN_STS_Msk) == 0U)
            {
                /* Flush USB Fifo */
                (void)USB_flushTxFifo(usbBase, 0x10U);
                (void)USB_flushRxFifo(usbBase);

                /* Restore FS Clock */
                (void)USB_initFSLSPClkSel(hhcd->instance, HCFG_48_MHZ);

                /* Handle Host Port Disconnect Interrupt */
                HCD_disconnectCallback(hhcd);
            }
        }

        /* Handle Host Port Interrupts */
        if (HCD_GET_FLAG(hhcd, USB_GINTSTS_PRT_INT_Msk))
        {
            HCD_portIRQHandler(hhcd);
        }

        /* Handle Host SOF Interrupt */
        if (HCD_GET_FLAG(hhcd, USB_GINTSTS_SOF_Msk))
        {
            HCD_sofCallback(hhcd);

            HCD_CLEAR_FLAG(hhcd, USB_GINTSTS_SOF_Msk);
        }

        /* Handle Rx Queue Level Interrupts */
        if ((HCD_GET_FLAG(hhcd, USB_GINTSTS_RXF_LVL_Msk)) != 0U)
        {
            USB_MASK_INTERRUPT(hhcd->instance, USB_GINTSTS_RXF_LVL_Msk);

            HCD_RXQLVLIRQHandler(hhcd);

            USB_UNMASK_INTERRUPT(hhcd->instance, USB_GINTSTS_RXF_LVL_Msk);
        }

        /* Handle Host channel Interrupt */
        if (HCD_GET_FLAG(hhcd, USB_GINTSTS_HCH_INT_Msk))
        {
            interrupt = USB_hostChannelReadInterrupt(hhcd->instance);
            for (i = 0U; i < hhcd->init.hostChannels; i++)
            {
                if ((interrupt & (1UL << (i & 0xFU))) != 0U)
                {
                    if (USB_HCCHAR_N_HCCHAR_N_EP_DIR_Get(usbBase->HC_GRPb[i].HCCHAR_N))
                    {
                        HCD_hostChannelInIRQHandler(hhcd, (uint8_t)i);
                    }
                    else
                    {
                        HCD_hostChannelOutIRQHandler(hhcd, (uint8_t)i);
                    }
                }
            }
            HCD_CLEAR_FLAG(hhcd, USB_GINTSTS_HCH_INT_Msk);
        }
    }
}

__WEAK void HCD_sofCallback(HCD_HandleTypeDef_t *hhcd)
{
    /* Prevent unused argument(s) compilation warning */
    USB_UNUSED(hhcd);

    /* NOTE : This function should not be modified, when the callback is needed,
              the HCD_sofCallback could be implemented in the user file
     */
}

__WEAK void HCD_connectCallback(HCD_HandleTypeDef_t *hhcd)
{
    /* Prevent unused argument(s) compilation warning */
    USB_UNUSED(hhcd);

    /* NOTE : This function should not be modified, when the callback is needed,
              the HCD_connectCallback could be implemented in the user file
     */
}

__WEAK void HCD_disconnectCallback(HCD_HandleTypeDef_t *hhcd)
{
    /* Prevent unused argument(s) compilation warning */
    USB_UNUSED(hhcd);

    /* NOTE : This function should not be modified, when the callback is needed,
              the HCD_disconnectCallback could be implemented in the user file
     */
}

__WEAK void HCD_portEnabledCallback(HCD_HandleTypeDef_t *hhcd)
{
    /* Prevent unused argument(s) compilation warning */
    USB_UNUSED(hhcd);

    /* NOTE : This function should not be modified, when the callback is needed,
              the HCD_disconnectCallback could be implemented in the user file
     */
}

__WEAK void HCD_portDisabledCallback(HCD_HandleTypeDef_t *hhcd)
{
    /* Prevent unused argument(s) compilation warning */
    USB_UNUSED(hhcd);

    /* NOTE : This function should not be modified, when the callback is needed,
              the HCD_disconnectCallback could be implemented in the user file
     */
}

__WEAK void HCD_hostChannelNotifyURBChangeCallback(HCD_HandleTypeDef_t *hhcd, uint8_t channelNum,
                                                   HCD_URBStateTypeDef urbState)
{
    /* Prevent unused argument(s) compilation warning */
    USB_UNUSED(hhcd);
    USB_UNUSED(channelNum);
    USB_UNUSED(urbState);

    /* NOTE : This function should not be modified, when the callback is needed,
              the HCD_hostChannelNotifyURBChangeCallback could be implemented in the user file
     */
}

status_t HCD_start(HCD_HandleTypeDef_t *hhcd)
{
    HTE_LOCK(hhcd);
    /* Enable port power */
    (void)USB_driveVbus(hhcd->instance, 1U);

    /* Enable global interrupt */
    HCD_ENABLE(hhcd);
    HTE_UNLOCK(hhcd);

    return kSTATUS_SUCCESS;
}

status_t HCD_stop(HCD_HandleTypeDef_t *hhcd)
{
    HTE_LOCK(hhcd);
    (void)USB_stopHost(hhcd->instance);
    HTE_UNLOCK(hhcd);

    return kSTATUS_SUCCESS;
}

status_t HCD_resetPort(HCD_HandleTypeDef_t *hhcd)
{
    return (USB_resetPort(hhcd->instance));
}

HCD_StateTypeDef_t HCD_getState(HCD_HandleTypeDef_t *hhcd)
{
    return hhcd->state;
}

HCD_URBStateTypeDef HCD_hostChannelGetURBState(HCD_HandleTypeDef_t *hhcd, uint8_t channelNum)
{
    return hhcd->hc[channelNum].urbState;
}

uint32_t HCD_hostChannelGetXferCount(HCD_HandleTypeDef_t *hhcd, uint8_t channelNum)
{
    return hhcd->hc[channelNum].xferCount;
}

HCD_HCStateTypeDef HCD_hostChanneGetState(HCD_HandleTypeDef_t *hhcd, uint8_t channelNum)
{
    return hhcd->hc[channelNum].state;
}

uint32_t HCD_getCurrentFrame(HCD_HandleTypeDef_t *hhcd)
{
    return (USB_getCurrentFrame(hhcd->instance));
}

uint32_t HCD_getCurrentSpeed(HCD_HandleTypeDef_t *hhcd)
{
    return (USB_getHostSpeed(hhcd->instance));
}

static void HCD_hostChannelInIRQHandler(HCD_HandleTypeDef_t *hhcd, uint8_t channelNum)
{
    USB_Type *usbBase = hhcd->instance;
    uint32_t  chNum   = (uint32_t)channelNum;

    uint32_t tmpreg;

    if (USB_HCINT_N_HCIN_T_N_AHB_ERR_Get(usbBase->HC_GRPb[chNum].HCINT_N))
    {
        HCD_CLEAR_HC_INT(chNum, USB_HCINT_N_HCIN_T_N_AHB_ERR_Msk);
        hhcd->hc[chNum].state = kHC_XACTERR;
        (void)USB_hostChannelHalt(hhcd->instance, (uint8_t)chNum);
    }
    else if (USB_HCINT_N_BBL_ERR_Get(usbBase->HC_GRPb[chNum].HCINT_N))
    {
        HCD_CLEAR_HC_INT(chNum, USB_HCINT_N_BBL_ERR_Msk);
        hhcd->hc[chNum].state = kHC_BBLERR;
        (void)USB_hostChannelHalt(hhcd->instance, (uint8_t)chNum);
    }
    else if (USB_HCINT_N_ACK_Get(usbBase->HC_GRPb[chNum].HCINT_N))
    {
        HCD_CLEAR_HC_INT(chNum, USB_HCINT_N_ACK_Msk);
    }
    else if (USB_HCINT_N_STALL_Get(usbBase->HC_GRPb[chNum].HCINT_N))
    {
        HCD_CLEAR_HC_INT(chNum, USB_HCINT_N_STALL_Msk);
        hhcd->hc[chNum].state = kHC_STALL;
        (void)USB_hostChannelHalt(hhcd->instance, (uint8_t)chNum);
    }
    else if (USB_HCINT_N_DATA_TGL_ERR_Get(usbBase->HC_GRPb[chNum].HCINT_N))
    {
        HCD_CLEAR_HC_INT(chNum, USB_HCINT_N_DATA_TGL_ERR_Msk);
        hhcd->hc[chNum].state = kHC_DATATGLERR;
        (void)USB_hostChannelHalt(hhcd->instance, (uint8_t)chNum);
    }
    else if (USB_HCINT_N_XACT_ERR_Get(usbBase->HC_GRPb[chNum].HCINT_N))
    {
        HCD_CLEAR_HC_INT(chNum, USB_HCINT_N_XACT_ERR_Msk);
        hhcd->hc[chNum].state = kHC_XACTERR;
        (void)USB_hostChannelHalt(hhcd->instance, (uint8_t)chNum);
    }
    else
    {
        /* ... */
    }

    if (USB_HCINT_N_FRM_OVRUN_Get(usbBase->HC_GRPb[chNum].HCINT_N))
    {
        (void)USB_hostChannelHalt(hhcd->instance, (uint8_t)chNum);
        HCD_CLEAR_HC_INT(chNum, USB_HCINT_N_FRM_OVRUN_Msk);
    }
    else if (USB_HCINT_N_HCIN_T_N_XFER_COMPL_Get(usbBase->HC_GRPb[chNum].HCINT_N))
    {
        if (hhcd->init.dmaEnable != 0U)
        {
            hhcd->hc[chNum].xferCount =
                hhcd->hc[chNum].xferSize - (USB_HCTSIZ_N_HCTSIZ_N_XFER_SIZE_Get(usbBase->HC_GRPb[chNum].HCTSIZ_N));
        }

        hhcd->hc[chNum].state  = kHC_XFRC;
        hhcd->hc[chNum].errCnt = 0U;
        HCD_CLEAR_HC_INT(chNum, USB_HCINT_N_HCIN_T_N_XFER_COMPL_Msk);

        if ((hhcd->hc[chNum].epType == EP_TYPE_CTRL) || (hhcd->hc[chNum].epType == EP_TYPE_BULK))
        {
            (void)USB_hostChannelHalt(hhcd->instance, (uint8_t)chNum);
            HCD_CLEAR_HC_INT(chNum, USB_HCINT_N_NAK_Msk);
        }
        else if ((hhcd->hc[chNum].epType == EP_TYPE_INTR) || (hhcd->hc[chNum].epType == EP_TYPE_ISOC))
        {
            usbBase->HC_GRPb[chNum].HCCHAR_N |= USB_HCCHAR_N_ODD_FRM_Msk;
            hhcd->hc[chNum].urbState          = kURB_DONE;
            HCD_hostChannelNotifyURBChangeCallback(hhcd, (uint8_t)chNum, hhcd->hc[chNum].urbState);
        }
        else
        {
            /* ... */
        }

        if (hhcd->init.dmaEnable == 1U)
        {
            if (((hhcd->hc[chNum].xferSize / hhcd->hc[chNum].maxPacket) & 1U) != 0U)
            {
                hhcd->hc[chNum].toggleIn ^= 1U;
            }
        }
        else
        {
            hhcd->hc[chNum].toggleIn ^= 1U;
        }
    }
    else if (USB_HCINT_N_CH_HLTD_Get(usbBase->HC_GRPb[chNum].HCINT_N))
    {
        if (hhcd->hc[chNum].state == kHC_XFRC)
        {
            hhcd->hc[chNum].urbState = kURB_DONE;
        }
        else if (hhcd->hc[chNum].state == kHC_STALL)
        {
            hhcd->hc[chNum].urbState = kURB_STALL;
        }
        else if ((hhcd->hc[chNum].state == kHC_XACTERR) || (hhcd->hc[chNum].state == kHC_DATATGLERR))
        {
            hhcd->hc[chNum].errCnt++;
            if (hhcd->hc[chNum].errCnt > 2U)
            {
                hhcd->hc[chNum].errCnt   = 0U;
                hhcd->hc[chNum].urbState = kURB_ERROR;
            }
            else
            {
                hhcd->hc[chNum].urbState = kURB_NOTREADY;

                /* re-activate the channel */
                tmpreg                            = usbBase->HC_GRPb[chNum].HCCHAR_N;
                tmpreg                           &= ~USB_HCCHAR_N_CH_DIS_Msk;
                tmpreg                           |= USB_HCCHAR_N_CH_ENA_Msk;
                usbBase->HC_GRPb[chNum].HCCHAR_N  = tmpreg;
            }
        }
        else if (hhcd->hc[chNum].state == kHC_NAK)
        {
            hhcd->hc[chNum].urbState = kURB_NOTREADY;

            /* re-activate the channel */
            tmpreg                            = usbBase->HC_GRPb[chNum].HCCHAR_N;
            tmpreg                           &= ~USB_HCCHAR_N_CH_DIS_Msk;
            tmpreg                           |= USB_HCCHAR_N_CH_ENA_Msk;
            usbBase->HC_GRPb[chNum].HCCHAR_N  = tmpreg;
        }
        else if (hhcd->hc[chNum].state == kHC_BBLERR)
        {
            hhcd->hc[chNum].errCnt++;
            hhcd->hc[chNum].urbState = kURB_ERROR;
        }
        else
        {
            /* ... */
        }
        HCD_CLEAR_HC_INT(chNum, USB_HCINT_N_CH_HLTD_Msk);

        HCD_hostChannelNotifyURBChangeCallback(hhcd, (uint8_t)chNum, hhcd->hc[chNum].urbState);
    }
    else if (USB_HCINT_N_NAK_Get(usbBase->HC_GRPb[chNum].HCINT_N))
    {
        if (hhcd->hc[chNum].epType == EP_TYPE_INTR)
        {
            hhcd->hc[chNum].errCnt = 0U;
            (void)USB_hostChannelHalt(hhcd->instance, (uint8_t)chNum);
        }
        else if ((hhcd->hc[chNum].epType == EP_TYPE_CTRL) || (hhcd->hc[chNum].epType == EP_TYPE_BULK))
        {
            hhcd->hc[chNum].errCnt = 0U;

            if (hhcd->init.dmaEnable == 0U)
            {
                hhcd->hc[chNum].state = kHC_NAK;
                (void)USB_hostChannelHalt(hhcd->instance, (uint8_t)chNum);
            }
        }
        else
        {
            /* ... */
        }
        HCD_CLEAR_HC_INT(chNum, USB_HCINT_N_NAK_Msk);
    }
    else
    {
        /* ... */
    }
}

static void HCD_hostChannelOutIRQHandler(HCD_HandleTypeDef_t *hhcd, uint8_t channelNum)
{
    USB_Type *usbBase = hhcd->instance;
    uint32_t  chNum   = (uint32_t)channelNum;
    uint32_t  tmpreg, num_packets;

    if (USB_HCINT_N_HCIN_T_N_AHB_ERR_Get(usbBase->HC_GRPb[chNum].HCINT_N))
    {
        HCD_CLEAR_HC_INT(chNum, USB_HCINT_N_HCIN_T_N_AHB_ERR_Msk);
        hhcd->hc[chNum].state = kHC_XACTERR;
        (void)USB_hostChannelHalt(hhcd->instance, (uint8_t)chNum);
    }
    else if (USB_HCINT_N_ACK_Get(usbBase->HC_GRPb[chNum].HCINT_N))
    {
        HCD_CLEAR_HC_INT(chNum, USB_HCINT_N_ACK_Msk);

        if (hhcd->hc[chNum].doPing == 1U)
        {
            hhcd->hc[chNum].doPing   = 0U;
            hhcd->hc[chNum].urbState = kURB_NOTREADY;
            (void)USB_hostChannelHalt(hhcd->instance, (uint8_t)chNum);
        }
    }
    else if (USB_HCINT_N_FRM_OVRUN_Get(usbBase->HC_GRPb[chNum].HCINT_N))
    {
        HCD_CLEAR_HC_INT(chNum, USB_HCINT_N_FRM_OVRUN_Msk);
        (void)USB_hostChannelHalt(hhcd->instance, (uint8_t)chNum);
    }
    else if (USB_HCINT_N_HCIN_T_N_XFER_COMPL_Get(usbBase->HC_GRPb[chNum].HCINT_N))
    {
        hhcd->hc[chNum].errCnt = 0U;

        /* transaction completed with NYET state, update do ping state */
        if (USB_HCINT_N_NYET_Get(usbBase->HC_GRPb[chNum].HCINT_N))
        {
            hhcd->hc[chNum].doPing = 1U;
            HCD_CLEAR_HC_INT(chNum, USB_HCINT_N_NYET_Msk);
        }
        HCD_CLEAR_HC_INT(chNum, USB_HCINT_N_HCIN_T_N_XFER_COMPL_Msk);
        hhcd->hc[chNum].state = kHC_XFRC;
        (void)USB_hostChannelHalt(hhcd->instance, (uint8_t)chNum);
    }
    else if (USB_HCINT_N_NYET_Get(usbBase->HC_GRPb[chNum].HCINT_N))
    {
        hhcd->hc[chNum].state  = kHC_NYET;
        hhcd->hc[chNum].doPing = 1U;
        hhcd->hc[chNum].errCnt = 0U;
        (void)USB_hostChannelHalt(hhcd->instance, (uint8_t)chNum);
        HCD_CLEAR_HC_INT(chNum, USB_HCINT_N_NYET_Msk);
    }
    else if (USB_HCINT_N_STALL_Get(usbBase->HC_GRPb[chNum].HCINT_N))
    {
        HCD_CLEAR_HC_INT(chNum, USB_HCINT_N_STALL_Msk);
        hhcd->hc[chNum].state = kHC_STALL;
        (void)USB_hostChannelHalt(hhcd->instance, (uint8_t)chNum);
    }
    else if (USB_HCINT_N_NAK_Get(usbBase->HC_GRPb[chNum].HCINT_N))
    {
        hhcd->hc[chNum].errCnt = 0U;
        hhcd->hc[chNum].state  = kHC_NAK;

        if (hhcd->hc[chNum].doPing == 0U)
        {
            if (hhcd->hc[chNum].speed == HCD_DEVICE_SPEED_HIGH)
            {
                hhcd->hc[chNum].doPing = 1U;
            }
        }

        (void)USB_hostChannelHalt(hhcd->instance, (uint8_t)chNum);
        HCD_CLEAR_HC_INT(chNum, USB_HCINT_N_NAK_Msk);
    }
    else if (USB_HCINT_N_XACT_ERR_Get(usbBase->HC_GRPb[chNum].HCINT_N))
    {
        if (hhcd->init.dmaEnable == 0U)
        {
            /* kHC_XACTERR  kCTRL_ERROR */
            hhcd->hc[chNum].state = kHC_XACTERR;
            (void)USB_hostChannelHalt(hhcd->instance, (uint8_t)chNum);
        }
        else
        {
            hhcd->hc[chNum].errCnt++;
            if (hhcd->hc[chNum].errCnt > 2U)
            {
                hhcd->hc[chNum].errCnt   = 0U;
                hhcd->hc[chNum].urbState = kURB_ERROR;

                HCD_hostChannelNotifyURBChangeCallback(hhcd, (uint8_t)chNum, hhcd->hc[chNum].urbState);
            }
            else
            {
                hhcd->hc[chNum].urbState = kURB_NOTREADY;
            }
        }
        HCD_CLEAR_HC_INT(chNum, USB_HCINT_N_XACT_ERR_Msk);
    }
    else if (USB_HCINT_N_DATA_TGL_ERR_Get(usbBase->HC_GRPb[chNum].HCINT_N))
    {
        hhcd->hc[chNum].state = kHC_DATATGLERR;
        (void)USB_hostChannelHalt(hhcd->instance, (uint8_t)chNum);
        HCD_CLEAR_HC_INT(chNum, USB_HCINT_N_DATA_TGL_ERR_Msk);
    }
    else if (USB_HCINT_N_CH_HLTD_Get(usbBase->HC_GRPb[chNum].HCINT_N))
    {
        if (hhcd->hc[chNum].state == kHC_XFRC)
        {
            hhcd->hc[chNum].urbState = kURB_DONE;
            if ((hhcd->hc[chNum].epType == EP_TYPE_BULK) || (hhcd->hc[chNum].epType == EP_TYPE_INTR))
            {
                if (hhcd->init.dmaEnable == 0U)
                {
                    hhcd->hc[chNum].toggleOut ^= 1U;
                }

                if ((hhcd->init.dmaEnable == 1U) && (hhcd->hc[chNum].xferLen > 0U))
                {
                    num_packets =
                        (hhcd->hc[chNum].xferLen + hhcd->hc[chNum].maxPacket - 1U) / hhcd->hc[chNum].maxPacket;

                    if ((num_packets & 1U) != 0U)
                    {
                        hhcd->hc[chNum].toggleOut ^= 1U;
                    }
                }
            }
        }
        else if (hhcd->hc[chNum].state == kHC_NAK)
        {
            hhcd->hc[chNum].urbState = kURB_NOTREADY;
        }
        else if (hhcd->hc[chNum].state == kHC_NYET)
        {
            hhcd->hc[chNum].urbState = kURB_NOTREADY;
        }
        else if (hhcd->hc[chNum].state == kHC_STALL)
        {
            hhcd->hc[chNum].urbState = kURB_STALL;
        }
        else if ((hhcd->hc[chNum].state == kHC_XACTERR) || (hhcd->hc[chNum].state == kHC_DATATGLERR))
        {
            hhcd->hc[chNum].errCnt++;
            if (hhcd->hc[chNum].errCnt > 2U)
            {
                hhcd->hc[chNum].errCnt   = 0U;
                hhcd->hc[chNum].urbState = kURB_ERROR;
            }
            else
            {
                /* kHC_XACTERR */
                hhcd->hc[chNum].urbState = kURB_NOTREADY;

                /* re-activate the channel  */
                tmpreg                            = usbBase->HC_GRPb[chNum].HCCHAR_N;
                tmpreg                           &= ~USB_HCCHAR_N_CH_DIS_Msk;
                tmpreg                           |= USB_HCCHAR_N_CH_ENA_Msk;
                usbBase->HC_GRPb[chNum].HCCHAR_N  = tmpreg;
            }
        }
        else
        {
            /* ... */
        }

        HCD_CLEAR_HC_INT(chNum, USB_HCINT_N_CH_HLTD_Msk);

        HCD_hostChannelNotifyURBChangeCallback(hhcd, (uint8_t)chNum, hhcd->hc[chNum].urbState);
    }
    else
    {
        /* ... */
    }
}

static void HCD_RXQLVLIRQHandler(HCD_HandleTypeDef_t *hhcd)
{
    USB_Type *usbBase = hhcd->instance;
    uint32_t  pktsts, pktcnt, grxstspReg, xferSizePktCnt;
    uint32_t  tmpreg, chNum;

    grxstspReg = hhcd->instance->GRXSTSP;
    chNum      = USB_GRXSTSP_GRXSTSP_CH_NUM_Get(grxstspReg);
    pktsts     = USB_GRXSTSP_GRXSTSP_PKT_STS_Get(grxstspReg);
    pktcnt     = USB_GRXSTSP_GRXSTSP_BCNT_Get(grxstspReg);

    switch (pktsts)
    {
        case GRXSTS_PKTSTS_IN:
            /* Read the data into the host buffer. */
            if ((pktcnt > 0U) && (hhcd->hc[chNum].xferBuff != (void *)0))
            {
                if ((hhcd->hc[chNum].xferCount + pktcnt) <= hhcd->hc[chNum].xferLen)
                {
                    (void)USB_readPacket(hhcd->instance, hhcd->hc[chNum].xferBuff, (uint16_t)pktcnt);

                    /* manage multiple Xfer */
                    hhcd->hc[chNum].xferBuff  += pktcnt;
                    hhcd->hc[chNum].xferCount += pktcnt;

                    /* get transfer size packet count */
                    xferSizePktCnt = USB_HCTSIZ_N_HCTSIZ_N_PKT_CNT_Get(usbBase->HC_GRPb[chNum].HCTSIZ_N);

                    if ((hhcd->hc[chNum].maxPacket == pktcnt) && (xferSizePktCnt > 0U))
                    {
                        /* re-activate the channel when more packets are expected */
                        tmpreg                            = usbBase->HC_GRPb[chNum].HCCHAR_N;
                        tmpreg                           &= ~USB_HCCHAR_N_CH_DIS_Msk;
                        tmpreg                           |= USB_HCCHAR_N_CH_ENA_Msk;
                        usbBase->HC_GRPb[chNum].HCCHAR_N  = tmpreg;
                        hhcd->hc[chNum].toggleIn         ^= 1U;
                    }
                }
                else
                {
                    hhcd->hc[chNum].urbState = kURB_ERROR;
                }
            }
            break;

        case GRXSTS_PKTSTS_DATA_TOGGLE_ERR:
            break;

        case GRXSTS_PKTSTS_IN_XFER_COMP:
        case GRXSTS_PKTSTS_CH_HALTED:
        default:
            break;
    }
}

static void HCD_portIRQHandler(HCD_HandleTypeDef_t *hhcd)
{
    USB_Type     *usbBase = hhcd->instance;
    __IO uint32_t hprt;
    __IO uint32_t hprtDup;

    /* Handle Host Port Interrupts */
    hprt    = usbBase->HPRT;
    hprtDup = usbBase->HPRT;

    hprtDup &=
        ~(USB_HPRT_PRT_ENA_Msk | USB_HPRT_PRT_CONN_DET_Msk | USB_HPRT_PRT_EN_CHNG_Msk | USB_HPRT_PRT_OVR_CURR_CHNG_Msk);

    /* Check whether Port Connect detected */
    if (USB_HPRT_PRT_CONN_DET_Get(hprt))
    {
        if (USB_HPRT_PRT_CONN_STS_Get(hprt))
        {
            HCD_connectCallback(hhcd);
        }
        hprtDup |= USB_HPRT_PRT_CONN_DET_Msk;
    }

    /* Check whether Port Enable Changed */
    if (USB_HPRT_PRT_EN_CHNG_Get(hprt))
    {
        hprtDup |= USB_HPRT_PRT_EN_CHNG_Msk;

        if (USB_HPRT_PRT_ENA_Get(hprt))
        {
            if (hhcd->init.phyItface == USB_OTG_EMBEDDED_PHY)
            {
                if ((hprt & USB_HPRT_PRT_SPD_Msk) == (HPRT0_PRTSPD_LOW_SPEED << 17))
                {
                    (void)USB_initFSLSPClkSel(hhcd->instance, HCFG_6_MHZ);
                }
                else
                {
                    (void)USB_initFSLSPClkSel(hhcd->instance, HCFG_48_MHZ);
                }
            }
            else
            {
                if (hhcd->init.speed == HCD_SPEED_FULL)
                {
                    usbBase->HFIR = 60000U;
                }
            }

            HCD_portEnabledCallback(hhcd);
        }
        else
        {
            HCD_portDisabledCallback(hhcd);
        }
    }

    /* Check for an overcurrent */
    if (USB_HPRT_PRT_OVR_CURR_CHNG_Get(hprt))
    {
        hprtDup |= USB_HPRT_PRT_OVR_CURR_CHNG_Msk;
    }

    /* Clear Port Interrupts */
    usbBase->HPRT = hprtDup;
}
