/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_pcd.c
 * \brief SDK USB peripheral control driver source file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_common.h"
#include "hte_ll_usb.h"
#include "hte_pcd.h"
#include "hte_pcd_ex.h"

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * \brief  Check FIFO for the next packet to be loaded.
 * \param[in]  hpcd PCD handle
 * \param[in]  epnum endpoint number
 * \return  status_t
 */
static status_t PCD_writeEmptyTxFifo(PCD_HandleTypeDef_t *hpcd, uint32_t epnum);
/*!
 * \brief  process EP OUT transfer complete interrupt.
 * \param[in]  hpcd PCD handle
 * \param[in]  epnum endpoint number
 * \return  status_t
 */
static status_t PCD_EP_outXfrCompleteInt(PCD_HandleTypeDef_t *hpcd, uint32_t epnum);
/*!
 * \brief  process EP OUT setup packet received interrupt.
 * \param[in]  hpcd PCD handle
 * \param[in]  epnum endpoint number
 * \return  status_t
 */
static status_t PCD_EP_outSetupPacketInt(PCD_HandleTypeDef_t *hpcd, uint32_t epnum);

/*******************************************************************************
 * Variables
 ******************************************************************************/
PCD_HandleTypeDef_t g_pcdHandle;

/*******************************************************************************
 * Codes
 ******************************************************************************/
status_t PCD_init(PCD_HandleTypeDef_t *hpcd)
{
    /* Check the PCD handle allocation */
    if (hpcd == NULL)
    {
        return kSTATUS_FAIL;
    }

    if (hpcd->state == kPCD_STATE_RESET)
    {
        /* Allocate lock resource and initialize it */
        hpcd->lock = kHTE_UNLOCKED;

        /* Init the low level hardware : GPIO, CLOCK, NVIC... */
        PCD_mspInit(hpcd);
    }

    hpcd->state = kPCD_STATE_BUSY;

    /* Disable the Interrupts */
    PCD_DISABLE(hpcd);

    /*Init the Core (common init.) */
    if (USB_coreInit(hpcd->instance, hpcd->init) != kSTATUS_SUCCESS)
    {
        hpcd->state = kPCD_STATE_ERROR;
        return kSTATUS_FAIL;
    }

    /* Force Device Mode*/
    (void)USB_setCurrentMode(hpcd->instance, kUSB_DEVICE_MODE);

    /* Init endpoints structures */
    for (uint8_t i = 0U; i < hpcd->init.devEndpoints; i++)
    {
        /* Init ep structure */
        hpcd->inEp[i].isIn      = 1U;
        hpcd->inEp[i].num       = i;
        hpcd->inEp[i].txFifoNum = i;
        /* Control until ep is activated */
        hpcd->inEp[i].type      = EP_TYPE_CTRL;
        hpcd->inEp[i].maxPacket = 0U;
        hpcd->inEp[i].xferBuff  = 0U;
        hpcd->inEp[i].xferLen   = 0U;
    }

    for (uint8_t i = 0U; i < hpcd->init.devEndpoints; i++)
    {
        hpcd->outEp[i].isIn = 0U;
        hpcd->outEp[i].num  = i;
        /* Control until ep is activated */
        hpcd->outEp[i].type      = EP_TYPE_CTRL;
        hpcd->outEp[i].maxPacket = 0U;
        hpcd->outEp[i].xferBuff  = 0U;
        hpcd->outEp[i].xferLen   = 0U;
    }

    /* Init Device */
    if (USB_devInit(hpcd->instance, hpcd->init) != kSTATUS_SUCCESS)
    {
        hpcd->state = kPCD_STATE_ERROR;
        return kSTATUS_FAIL;
    }

    hpcd->usbAddress = 0U;
    hpcd->state      = kPCD_STATE_READY;

    /* Activate LPM */
    if (hpcd->init.lpmEnable == 1U)
    {
        (void)PCDEx_activateLPM(hpcd);
    }

    (void)USB_devDisconnect(hpcd->instance);

    return kSTATUS_SUCCESS;
}

status_t PCD_deInit(PCD_HandleTypeDef_t *hpcd)
{
    /* Check the PCD handle allocation */
    if (hpcd == NULL)
    {
        return kSTATUS_FAIL;
    }

    hpcd->state = kPCD_STATE_BUSY;

    /* Stop Device */
    if (USB_stopDevice(hpcd->instance) != kSTATUS_SUCCESS)
    {
        return kSTATUS_FAIL;
    }

    /* DeInit the low level hardware: CLOCK, NVIC.*/
    PCD_mspDeInit(hpcd);

    hpcd->state = kPCD_STATE_RESET;

    return kSTATUS_SUCCESS;
}

__WEAK void PCD_mspInit(PCD_HandleTypeDef_t *hpcd)
{
    /* Prevent unused argument(s) compilation warning */
    USB_UNUSED(hpcd);

    /* NOTE : This function should not be modified, when the callback is needed,
              the PCD_mspInit could be implemented in the user file
     */
}

__WEAK void PCD_mspDeInit(PCD_HandleTypeDef_t *hpcd)
{
    /* Prevent unused argument(s) compilation warning */
    USB_UNUSED(hpcd);

    /* NOTE : This function should not be modified, when the callback is needed,
              the PCD_mspDeInit could be implemented in the user file
     */
}

status_t PCD_start(PCD_HandleTypeDef_t *hpcd)
{
    HTE_LOCK(hpcd);
    PCD_ENABLE(hpcd);
    (void)USB_devConnect(hpcd->instance);
    HTE_UNLOCK(hpcd);

    return kSTATUS_SUCCESS;
}

status_t PCD_stop(PCD_HandleTypeDef_t *hpcd)
{
    HTE_LOCK(hpcd);
    PCD_DISABLE(hpcd);
    (void)USB_devDisconnect(hpcd->instance);
    (void)USB_flushTxFifo(hpcd->instance, 0x10U);
    HTE_UNLOCK(hpcd);

    return kSTATUS_SUCCESS;
}

void PCD_IRQHandler(PCD_HandleTypeDef_t *hpcd)
{
    USB_Type            *usbBase = hpcd->instance;
    USB_OTG_EPTypeDef_t *ep;
    uint32_t             i, RegVal, ep_intr, epint, epnum, fifoemptymsk;

    /* ensure that we are in device mode */
    if (USB_getMode(hpcd->instance) == USB_OTG_MODE_DEVICE)
    {
        /* avoid spurious interrupt */
        if (PCD_IS_INVALID_INTERRUPT(hpcd))
        {
            return;
        }

        /* store current frame number */
        hpcd->frameNumber = USB_DSTS_SOFFN_Get(usbBase->DSTS);

        if (PCD_GET_FLAG(hpcd, USB_GINTSTS_MODE_MIS_Msk))
        {
            /* incorrect mode, acknowledge the interrupt */
            PCD_CLEAR_FLAG(hpcd, USB_GINTSTS_MODE_MIS_Msk);
        }

        /* Handle RxQLevel Interrupt */
        if (PCD_GET_FLAG(hpcd, USB_GINTSTS_RXF_LVL_Msk))
        {
            USB_MASK_INTERRUPT(hpcd->instance, USB_GINTSTS_RXF_LVL_Msk);
            RegVal = usbBase->GRXSTSP;

            ep = &hpcd->outEp[RegVal & USB_GRXSTSP_GRXSTSP_CH_NUM_Msk];

            if ((USB_GRXSTSP_GRXSTSP_PKT_STS_Get(RegVal)) == STS_DATA_UPDT)
            {
                if ((RegVal & USB_GRXSTSP_GRXSTSP_BCNT_Msk) != 0U)
                {
                    (void)USB_readPacket(usbBase, ep->xferBuff, (uint16_t)(USB_GRXSTSP_GRXSTSP_BCNT_Get(RegVal)));

                    ep->xferBuff  += USB_GRXSTSP_GRXSTSP_BCNT_Get(RegVal);
                    ep->xferCount += USB_GRXSTSP_GRXSTSP_BCNT_Get(RegVal);
                }
            }
            else if ((USB_GRXSTSP_GRXSTSP_PKT_STS_Get(RegVal)) == STS_SETUP_UPDT)
            {
                (void)USB_readPacket(usbBase, (uint8_t *)hpcd->setup, 8U);
                ep->xferCount += USB_GRXSTSP_GRXSTSP_BCNT_Get(RegVal);
            }
            else
            {
                /* ... */
            }

            USB_UNMASK_INTERRUPT(hpcd->instance, USB_GINTSTS_RXF_LVL_Msk);
        }

        if (PCD_GET_FLAG(hpcd, USB_GINTSTS_OEP_INT_Msk))
        {
            epnum = 0U;

            /* Read in the device interrupt bits */
            ep_intr = USB_readDevAllOutEpInterrupt(hpcd->instance);

            while (ep_intr != 0U)
            {
                if ((ep_intr & 0x1U) != 0U)
                {
                    epint = USB_readDevOutEPInterrupt(hpcd->instance, (uint8_t)epnum);

                    if (USB_DOEPINT_N_DOEP_IN_T_N_XFER_COMPL_Get(epint))
                    {
                        CLEAR_OUT_EP_INTR(epnum, USB_DOEPINT_N_DOEP_IN_T_N_XFER_COMPL_Msk);

                        (void)PCD_EP_outXfrCompleteInt(hpcd, epnum);
                    }

                    if (USB_DOEPINT_N_DOEP_IN_T_N_SET_UP_Get(epint))
                    {
                        CLEAR_OUT_EP_INTR(epnum, USB_DOEPINT_N_DOEP_IN_T_N_SET_UP_Msk);


                        /* Class B setup phase done for previous decoded setup */
                        (void)PCD_EP_outSetupPacketInt(hpcd, epnum);
                    }

                    if (USB_DOEPINT_N_DOEP_IN_T_N_OUT_TKN_EP_DIS_Get(epint))
                    {
                        CLEAR_OUT_EP_INTR(epnum, USB_DOEPINT_N_DOEP_IN_T_N_OUT_TKN_EP_DIS_Msk);
                    }

                    /* Clear OUT Endpoint disable interrupt */
                    if (USB_DOEPINT_N_DOEP_IN_T_N_EP_DISBLD_Get(epint))
                    {
                        if (USB_GINTSTS_GOUT_NAK_EFF_Get(usbBase->GINTSTS))
                        {
                            usbBase->DCTL |= USB_DCTL_CGOUT_NAK_Set(1U);
                        }

                        ep = &hpcd->outEp[epnum];

                        if (ep->isIsoIncomplete == 1U)
                        {
                            ep->isIsoIncomplete = 0U;

                            PCD_ISOOUTIncompleteCallback(hpcd, (uint8_t)epnum);
                        }

                        CLEAR_OUT_EP_INTR(epnum, USB_DOEPINT_N_DOEP_IN_T_N_EP_DISBLD_Msk);
                    }

                    /* Clear Status Phase Received interrupt */
                    if (USB_DOEPINT_N_DOEP_IN_T_N_STS_PHSE_RCVD_Get(epint))
                    {
                        CLEAR_OUT_EP_INTR(epnum, USB_DOEPINT_N_DOEP_IN_T_N_STS_PHSE_RCVD_Msk);
                    }

                    /* Clear OUT NAK interrupt */
                    if (USB_DOEPINT_N_DOEP_IN_T_N_NAKINTRPT_Get(epint))
                    {
                        CLEAR_OUT_EP_INTR(epnum, USB_DOEPINT_N_DOEP_IN_T_N_NAKINTRPT_Msk);
                    }
                }
                epnum++;
                ep_intr >>= 1U;
            }
        }

        if (PCD_GET_FLAG(hpcd, USB_GINTSTS_IEP_INT_Msk))
        {
            /* Read in the device interrupt bits */
            ep_intr = USB_readDevAllInEpInterrupt(hpcd->instance);

            epnum = 0U;

            while (ep_intr != 0U)
            {
                if ((ep_intr & 0x1U) != 0U) /* In ITR */
                {
                    epint = USB_readDevInEPInterrupt(hpcd->instance, (uint8_t)epnum);

                    if (USB_DIEPINT_N_DIEP_IN_T_N_XFER_COMPL_Get(epint))
                    {
                        fifoemptymsk         = (uint32_t)(0x1UL << (epnum & EP_ADDR_MSK));
                        usbBase->DIEPEMPMSK &= ~fifoemptymsk;

                        CLEAR_IN_EP_INTR(epnum, USB_DIEPINT_N_DIEP_IN_T_N_XFER_COMPL_Msk);

                        if (hpcd->init.dmaEnable == 1U)
                        {
                            hpcd->inEp[epnum].xferBuff += hpcd->inEp[epnum].maxPacket;

                            /* this is ZLP, so prepare EP0 for next setup */
                            if ((epnum == 0U) && (hpcd->inEp[epnum].xferLen == 0U))
                            {
                                /* prepare to rx more setup packets */
                                (void)USB_ep0OutStart(hpcd->instance, 1U, (uint8_t *)hpcd->setup);
                            }
                        }
                        PCD_dataInStageCallback(hpcd, (uint8_t)epnum);
                    }

                    if (USB_DIEPINT_N_DIEP_IN_T_N_TIME_OUT_Get(epint))
                    {
                        CLEAR_IN_EP_INTR(epnum, USB_DIEPINT_N_DIEP_IN_T_N_TIME_OUT_Msk);
                    }

                    if (USB_DIEPINT_N_DIEP_IN_T_N_IN_TKN_TXFEMP_Get(epint))
                    {
                        CLEAR_IN_EP_INTR(epnum, USB_DIEPINT_N_DIEP_IN_T_N_IN_TKN_TXFEMP_Msk);
                    }

                    if (USB_DIEPINT_N_DIEP_IN_T_N_IN_EP_NAK_EFF_Get(epint))
                    {
                        CLEAR_IN_EP_INTR(epnum, USB_DIEPINT_N_DIEP_IN_T_N_IN_EP_NAK_EFF_Msk);
                    }

                    if (USB_DIEPINT_N_DIEP_IN_T_N_EP_DISBLD_Get(epint))
                    {
                        (void)USB_flushTxFifo(usbBase, epnum);

                        ep = &hpcd->inEp[epnum];

                        if (ep->isIsoIncomplete == 1U)
                        {
                            ep->isIsoIncomplete = 0U;

                            PCD_ISOINIncompleteCallback(hpcd, (uint8_t)epnum);
                        }

                        CLEAR_IN_EP_INTR(epnum, USB_DIEPINT_N_DIEP_IN_T_N_EP_DISBLD_Msk);
                    }
                    if (USB_DIEPINT_N_DIEP_IN_T_N_TXF_EMP_Get(epint))
                    {
                        (void)PCD_writeEmptyTxFifo(hpcd, epnum);
                    }
                }
                epnum++;
                ep_intr >>= 1U;
            }
        }

        /* Handle Resume Interrupt */
        if (PCD_GET_FLAG(hpcd, USB_GINTSTS_WK_UP_INT_Msk))
        {
            /* Clear the Remote Wake-up Signaling */
            usbBase->DCTL &= ~USB_DCTL_RMT_WK_UP_SIG_Set(1U);

            if (hpcd->lpmState == kLPM_L1)
            {
                hpcd->lpmState = kLPM_L0;

                PCDEx_LPM_callback(hpcd, kPCD_LPM_L0_ACTIVE);
            }
            else
            {
                PCD_resumeCallback(hpcd);
            }

            PCD_CLEAR_FLAG(hpcd, USB_GINTSTS_WK_UP_INT_Msk);
        }

        /* Handle Suspend Interrupt */
        if (PCD_GET_FLAG(hpcd, USB_GINTSTS_USB_SUSP_Msk))
        {
            if (USB_DSTS_SUSP_STS_Get(usbBase))
            {
                PCD_suspendCallback(hpcd);
            }
            PCD_CLEAR_FLAG(hpcd, USB_GINTSTS_USB_SUSP_Msk);
        }

        /* Handle Reset Interrupt */
        if (PCD_GET_FLAG(hpcd, USB_GINTSTS_USB_RST_Msk))
        {
            usbBase->DCTL &= ~USB_DCTL_RMT_WK_UP_SIG_Set(1U);
            (void)USB_flushTxFifo(hpcd->instance, 0x10U);

            for (i = 0U; i < hpcd->init.devEndpoints; i++)
            {
                usbBase->DIEP_GRPb[i].DIEPINT_N  = 0xFB7FU;
                usbBase->DIEP_GRPb[i].DIEPCTL_N &= ~USB_DIEPCTL_N_DIEP_CTL_N_STALL_Set(1U);
                usbBase->DOEP_GRPb[i].DOEPINT_N  = 0xFB7FU;
                usbBase->DOEP_GRPb[i].DOEPCTL_N &= ~USB_DOEPCTL_N_DOEP_CTL_N_STALL_Set(1U);
                usbBase->DOEP_GRPb[i].DOEPCTL_N |= USB_DOEPCTL_N_DOEP_CTL_N_SNAK_Set(1U);
            }
            usbBase->DAINTMSK |= 0x10001U;

            if (hpcd->init.useDedicatedEp1 != 0U)
            {
                usbBase->DOEPEACHMSK_N[0] |= USB_DOEPMSK_DOEP_MSK_SET_UPMSK_Set(1U) |
                                             USB_DOEPMSK_DOEP_MSK_XFER_COMPL_MSK_Set(1U) |
                                             USB_DOEPMSK_DOEP_MSK_EP_DISBLD_MSK_Set(1U);

                usbBase->DIEPEACHMSK_N[0] |= USB_DIEPMSK_DIEP_MSK_TIME_OUT_MSK_Set(1U) |
                                             USB_DIEPMSK_DIEP_MSK_XFER_COMPL_MSK_Set(1U) |
                                             USB_DIEPMSK_DIEP_MSK_EP_DISBLD_MSK_Set(1U);
            }
            else /* in */
            {
                usbBase->DOEPMSK |=
                    USB_DOEPMSK_DOEP_MSK_SET_UPMSK_Set(1U) | USB_DOEPMSK_DOEP_MSK_XFER_COMPL_MSK_Set(1U) |
                    USB_DOEPMSK_DOEP_MSK_EP_DISBLD_MSK_Set(1U) | USB_DOEPMSK_DOEP_MSK_STS_PHSE_RCVD_MSK_Set(1U) |
                    USB_DOEPMSK_DOEP_MSK_NAKMSK_Set(1U);

                usbBase->DIEPMSK |= USB_DIEPMSK_DIEP_MSK_TIME_OUT_MSK_Set(1U) |
                                    USB_DIEPMSK_DIEP_MSK_XFER_COMPL_MSK_Set(1U) |
                                    USB_DIEPMSK_DIEP_MSK_EP_DISBLD_MSK_Set(1U);
            }

            /* Set Default Address to 0 */
            usbBase->DCFG &= ~USB_DCFG_DCFG_DEV_ADDR_Msk;

            /* setup EP0 to receive SETUP packets */
            (void)USB_ep0OutStart(hpcd->instance, (uint8_t)hpcd->init.dmaEnable, (uint8_t *)hpcd->setup);

            PCD_CLEAR_FLAG(hpcd, USB_GINTSTS_USB_RST_Msk);
        }

        /* Handle Enumeration done Interrupt */
        if (PCD_GET_FLAG(hpcd, USB_GINTSTS_ENUM_DONE_Msk))
        {
            (void)USB_activateSetup(hpcd->instance);
            hpcd->init.speed = USB_getDevSpeed(hpcd->instance);

            /* Set USB Turnaround time */
            PCD_resetCallback(hpcd);

            PCD_CLEAR_FLAG(hpcd, USB_GINTSTS_ENUM_DONE_Msk);
        }

        /* Handle SOF Interrupt */
        if (PCD_GET_FLAG(hpcd, USB_GINTSTS_SOF_Msk))
        {
            PCD_sofCallback(hpcd);

            PCD_CLEAR_FLAG(hpcd, USB_GINTSTS_SOF_Msk);
        }

        /* Handle Global OUT NAK effective Interrupt */
        if (PCD_GET_FLAG(hpcd, USB_GINTSTS_GOUT_NAK_EFF_Msk))
        {
            usbBase->GINTMSK &= ~USB_GINTMSK_GOUT_NAK_EFF_MSK_Set(1U);

            for (epnum = 1U; epnum < hpcd->init.devEndpoints; epnum++)
            {
                if (hpcd->outEp[epnum].isIsoIncomplete == 1U)
                {
                    /* Abort current transaction and disable the EP */
                    (void)PCD_EP_abort(hpcd, (uint8_t)epnum);
                }
            }
        }

        /* Handle Incomplete ISO IN Interrupt */
        if (PCD_GET_FLAG(hpcd, USB_GINTSTS_INCOMP_ISO_IN_Msk))
        {
            for (epnum = 1U; epnum < hpcd->init.devEndpoints; epnum++)
            {
                RegVal = usbBase->DIEP_GRPb[epnum].DIEPCTL_N;

                if ((hpcd->inEp[epnum].type == EP_TYPE_ISOC) && (USB_DIEPCTL_N_DIEP_CTL_N_EP_ENA_Get(RegVal)))
                {
                    hpcd->inEp[epnum].isIsoIncomplete = 1U;

                    /* Abort current transaction and disable the EP */
                    (void)PCD_EP_abort(hpcd, (uint8_t)(epnum | 0x80U));
                }
            }

            PCD_CLEAR_FLAG(hpcd, USB_GINTSTS_INCOMP_ISO_IN_Msk);
        }

        /* Handle Incomplete ISO OUT Interrupt */
        if (PCD_GET_FLAG(hpcd, USB_GINTSTS_INCOMPL_P_Msk))
        {
            for (epnum = 1U; epnum < hpcd->init.devEndpoints; epnum++)
            {
                RegVal = usbBase->DOEP_GRPb[epnum].DOEPCTL_N;

                if ((hpcd->outEp[epnum].type == EP_TYPE_ISOC) && (USB_DOEPCTL_N_DOEP_CTL_N_EP_ENA_Get(RegVal)) &&
                    ((RegVal & (0x1U << 16)) == (hpcd->frameNumber & 0x1U)))
                {
                    hpcd->outEp[epnum].isIsoIncomplete = 1U;

                    usbBase->GINTMSK |= USB_GINTMSK_GOUT_NAK_EFF_MSK_Set(1U);

                    if (USB_GINTSTS_GOUT_NAK_EFF_Get(usbBase->GINTSTS) == 0U)
                    {
                        usbBase->DCTL |= USB_DCTL_SGOUT_NAK_Set(1U);
                        break;
                    }
                }
            }

            PCD_CLEAR_FLAG(hpcd, USB_GINTSTS_INCOMPL_P_Msk);
        }

        /* Handle Connection event Interrupt */
        if (PCD_GET_FLAG(hpcd, USB_GINTSTS_SESS_REQ_INT_Msk))
        {
            PCD_connectCallback(hpcd);

            PCD_CLEAR_FLAG(hpcd, USB_GINTSTS_SESS_REQ_INT_Msk);
        }

        /* Handle Disconnection event Interrupt */
        if (PCD_GET_FLAG(hpcd, USB_GINTSTS_OTG_INT_Msk))
        {
            RegVal = hpcd->instance->GOTGINT;

            if (USB_GOTGINT_SES_END_DET_Get(RegVal))
            {
                PCD_disconnectCallback(hpcd);
            }
            hpcd->instance->GOTGINT |= RegVal;
        }
    }
}

__WEAK void PCD_dataOutStageCallback(PCD_HandleTypeDef_t *hpcd, uint8_t epnum)
{
    /* Prevent unused argument(s) compilation warning */
    USB_UNUSED(hpcd);
    USB_UNUSED(epnum);

    /* NOTE : This function should not be modified, when the callback is needed,
              the PCD_dataOutStageCallback could be implemented in the user file
     */
}

__WEAK void PCD_dataInStageCallback(PCD_HandleTypeDef_t *hpcd, uint8_t epnum)
{
    /* Prevent unused argument(s) compilation warning */
    USB_UNUSED(hpcd);
    USB_UNUSED(epnum);

    /* NOTE : This function should not be modified, when the callback is needed,
              the PCD_dataInStageCallback could be implemented in the user file
     */
}

__WEAK void PCD_setupStageCallback(PCD_HandleTypeDef_t *hpcd)
{
    /* Prevent unused argument(s) compilation warning */
    USB_UNUSED(hpcd);

    /* NOTE : This function should not be modified, when the callback is needed,
              the PCD_setupStageCallback could be implemented in the user file
     */
}

__WEAK void PCD_sofCallback(PCD_HandleTypeDef_t *hpcd)
{
    /* Prevent unused argument(s) compilation warning */
    USB_UNUSED(hpcd);

    /* NOTE : This function should not be modified, when the callback is needed,
              the PCD_sofCallback could be implemented in the user file
     */
}

__WEAK void PCD_resetCallback(PCD_HandleTypeDef_t *hpcd)
{
    /* Prevent unused argument(s) compilation warning */
    USB_UNUSED(hpcd);

    /* NOTE : This function should not be modified, when the callback is needed,
              the PCD_resetCallback could be implemented in the user file
     */
}

__WEAK void PCD_suspendCallback(PCD_HandleTypeDef_t *hpcd)
{
    /* Prevent unused argument(s) compilation warning */
    USB_UNUSED(hpcd);

    /* NOTE : This function should not be modified, when the callback is needed,
              the PCD_suspendCallback could be implemented in the user file
     */
}

__WEAK void PCD_resumeCallback(PCD_HandleTypeDef_t *hpcd)
{
    /* Prevent unused argument(s) compilation warning */
    USB_UNUSED(hpcd);

    /* NOTE : This function should not be modified, when the callback is needed,
              the PCD_resumeCallback could be implemented in the user file
     */
}

__WEAK void PCD_ISOOUTIncompleteCallback(PCD_HandleTypeDef_t *hpcd, uint8_t epnum)
{
    /* Prevent unused argument(s) compilation warning */
    USB_UNUSED(hpcd);
    USB_UNUSED(epnum);

    /* NOTE : This function should not be modified, when the callback is needed,
              the PCD_ISOOUTIncompleteCallback could be implemented in the user file
     */
}

__WEAK void PCD_ISOINIncompleteCallback(PCD_HandleTypeDef_t *hpcd, uint8_t epnum)
{
    /* Prevent unused argument(s) compilation warning */
    USB_UNUSED(hpcd);
    USB_UNUSED(epnum);

    /* NOTE : This function should not be modified, when the callback is needed,
              the PCD_ISOINIncompleteCallback could be implemented in the user file
     */
}

__WEAK void PCD_connectCallback(PCD_HandleTypeDef_t *hpcd)
{
    /* Prevent unused argument(s) compilation warning */
    USB_UNUSED(hpcd);

    /* NOTE : This function should not be modified, when the callback is needed,
              the PCD_connectCallback could be implemented in the user file
     */
}

__WEAK void PCD_disconnectCallback(PCD_HandleTypeDef_t *hpcd)
{
    /* Prevent unused argument(s) compilation warning */
    USB_UNUSED(hpcd);

    /* NOTE : This function should not be modified, when the callback is needed,
              the PCD_disconnectCallback could be implemented in the user file
     */
}

status_t PCD_devConnect(PCD_HandleTypeDef_t *hpcd)
{
    HTE_LOCK(hpcd);
    (void)USB_devConnect(hpcd->instance);
    HTE_UNLOCK(hpcd);

    return kSTATUS_SUCCESS;
}

status_t PCD_devDisconnect(PCD_HandleTypeDef_t *hpcd)
{
    HTE_LOCK(hpcd);
    (void)USB_devDisconnect(hpcd->instance);
    HTE_UNLOCK(hpcd);

    return kSTATUS_SUCCESS;
}

status_t PCD_setAddress(PCD_HandleTypeDef_t *hpcd, uint8_t address)
{
    HTE_LOCK(hpcd);
    hpcd->usbAddress = address;
    (void)USB_setDevAddress(hpcd->instance, address);
    HTE_UNLOCK(hpcd);

    return kSTATUS_SUCCESS;
}

status_t PCD_EP_open(PCD_HandleTypeDef_t *hpcd, uint8_t epAddr, uint16_t epMps, uint8_t epType)
{
    status_t       ret = kSTATUS_SUCCESS;
    PCD_EPTypeDef *ep;

    if ((epAddr & 0x80U) == 0x80U)
    {
        ep       = &hpcd->inEp[epAddr & EP_ADDR_MSK];
        ep->isIn = 1U;
    }
    else
    {
        ep       = &hpcd->outEp[epAddr & EP_ADDR_MSK];
        ep->isIn = 0U;
    }

    ep->num       = epAddr & EP_ADDR_MSK;
    ep->maxPacket = epMps;
    ep->type      = epType;

    if (ep->isIn != 0U)
    {
        /* Assign a Tx FIFO */
        ep->txFifoNum = ep->num;
    }
    /* Set initial data PID. */
    if (epType == EP_TYPE_BULK)
    {
        ep->dataPidStart = 0U;
    }

    HTE_LOCK(hpcd);
    (void)USB_activateEndpoint(hpcd->instance, ep);
    HTE_UNLOCK(hpcd);

    return ret;
}

status_t PCD_EP_close(PCD_HandleTypeDef_t *hpcd, uint8_t epAddr)
{
    PCD_EPTypeDef *ep;

    if ((epAddr & 0x80U) == 0x80U)
    {
        ep       = &hpcd->inEp[epAddr & EP_ADDR_MSK];
        ep->isIn = 1U;
    }
    else
    {
        ep       = &hpcd->outEp[epAddr & EP_ADDR_MSK];
        ep->isIn = 0U;
    }
    ep->num = epAddr & EP_ADDR_MSK;

    HTE_LOCK(hpcd);
    (void)USB_deactivateEndpoint(hpcd->instance, ep);
    HTE_UNLOCK(hpcd);
    return kSTATUS_SUCCESS;
}

status_t PCD_EP_receive(PCD_HandleTypeDef_t *hpcd, uint8_t epAddr, uint8_t *pBuf, uint32_t len)
{
    PCD_EPTypeDef *ep;

    ep = &hpcd->outEp[epAddr & EP_ADDR_MSK];

    /*setup and start the Xfer */
    ep->xferBuff  = pBuf;
    ep->xferLen   = len;
    ep->xferCount = 0U;
    ep->isIn      = 0U;
    ep->num       = epAddr & EP_ADDR_MSK;

    if (hpcd->init.dmaEnable == 1U)
    {
        ep->dmaAddr = (uint32_t)pBuf;
    }

    if ((epAddr & EP_ADDR_MSK) == 0U)
    {
        (void)USB_ep0StartXfer(hpcd->instance, ep, (uint8_t)hpcd->init.dmaEnable);
    }
    else
    {
        (void)USB_epStartXfer(hpcd->instance, ep, (uint8_t)hpcd->init.dmaEnable);
    }

    return kSTATUS_SUCCESS;
}

uint32_t PCD_EP_getRxCount(PCD_HandleTypeDef_t *hpcd, uint8_t epAddr)
{
    return hpcd->outEp[epAddr & EP_ADDR_MSK].xferCount;
}

status_t PCD_EP_transmit(PCD_HandleTypeDef_t *hpcd, uint8_t epAddr, uint8_t *pBuf, uint32_t len)
{
    PCD_EPTypeDef *ep;

    ep = &hpcd->inEp[epAddr & EP_ADDR_MSK];

    /*setup and start the Xfer */
    ep->xferBuff  = pBuf;
    ep->xferLen   = len;
    ep->xferCount = 0U;
    ep->isIn      = 1U;
    ep->num       = epAddr & EP_ADDR_MSK;

    if (hpcd->init.dmaEnable == 1U)
    {
        ep->dmaAddr = (uint32_t)pBuf;
    }

    if ((epAddr & EP_ADDR_MSK) == 0U)
    {
        (void)USB_ep0StartXfer(hpcd->instance, ep, (uint8_t)hpcd->init.dmaEnable);
    }
    else
    {
        (void)USB_epStartXfer(hpcd->instance, ep, (uint8_t)hpcd->init.dmaEnable);
    }

    return kSTATUS_SUCCESS;
}

status_t PCD_EP_setStall(PCD_HandleTypeDef_t *hpcd, uint8_t epAddr)
{
    PCD_EPTypeDef *ep;

    if (((uint32_t)epAddr & EP_ADDR_MSK) > hpcd->init.devEndpoints)
    {
        return kSTATUS_FAIL;
    }

    if ((0x80U & epAddr) == 0x80U)
    {
        ep       = &hpcd->inEp[epAddr & EP_ADDR_MSK];
        ep->isIn = 1U;
    }
    else
    {
        ep       = &hpcd->outEp[epAddr];
        ep->isIn = 0U;
    }

    ep->isStall = 1U;
    ep->num     = epAddr & EP_ADDR_MSK;

    HTE_LOCK(hpcd);

    (void)USB_epSetStall(hpcd->instance, ep);

    if ((epAddr & EP_ADDR_MSK) == 0U)
    {
        (void)USB_ep0OutStart(hpcd->instance, (uint8_t)hpcd->init.dmaEnable, (uint8_t *)hpcd->setup);
    }

    HTE_UNLOCK(hpcd);

    return kSTATUS_SUCCESS;
}

status_t PCD_EP_clrStall(PCD_HandleTypeDef_t *hpcd, uint8_t epAddr)
{
    PCD_EPTypeDef *ep;

    if (((uint32_t)epAddr & 0x0FU) > hpcd->init.devEndpoints)
    {
        return kSTATUS_FAIL;
    }

    if ((0x80U & epAddr) == 0x80U)
    {
        ep       = &hpcd->inEp[epAddr & EP_ADDR_MSK];
        ep->isIn = 1U;
    }
    else
    {
        ep       = &hpcd->outEp[epAddr & EP_ADDR_MSK];
        ep->isIn = 0U;
    }

    ep->isStall = 0U;
    ep->num     = epAddr & EP_ADDR_MSK;

    HTE_LOCK(hpcd);
    (void)USB_epClearStall(hpcd->instance, ep);
    HTE_UNLOCK(hpcd);

    return kSTATUS_SUCCESS;
}

status_t PCD_EP_abort(PCD_HandleTypeDef_t *hpcd, uint8_t epAddr)
{
    status_t       ret;
    PCD_EPTypeDef *ep;

    if ((0x80U & epAddr) == 0x80U)
    {
        ep = &hpcd->inEp[epAddr & EP_ADDR_MSK];
    }
    else
    {
        ep = &hpcd->outEp[epAddr & EP_ADDR_MSK];
    }

    /* Stop Xfer */
    ret = USB_epStopXfer(hpcd->instance, ep);

    return ret;
}

status_t PCD_EP_flush(PCD_HandleTypeDef_t *hpcd, uint8_t epAddr)
{
    HTE_LOCK(hpcd);

    if ((epAddr & 0x80U) == 0x80U)
    {
        (void)USB_flushTxFifo(hpcd->instance, (uint32_t)epAddr & EP_ADDR_MSK);
    }
    else
    {
        (void)USB_flushRxFifo(hpcd->instance);
    }

    HTE_UNLOCK(hpcd);

    return kSTATUS_SUCCESS;
}

status_t PCD_activateRemoteWakeup(PCD_HandleTypeDef_t *hpcd)
{
    return (USB_activateRemoteWakeup(hpcd->instance));
}

status_t PCD_deactivateRemoteWakeup(PCD_HandleTypeDef_t *hpcd)
{
    return (USB_deactivateRemoteWakeup(hpcd->instance));
}

PCD_StateTypeDef_t PCD_getState(PCD_HandleTypeDef_t *hpcd)
{
    return hpcd->state;
}

status_t PCD_setTestMode(PCD_HandleTypeDef_t *hpcd, uint8_t testMode)
{
    USB_Type *usbBase = hpcd->instance;

    switch (testMode)
    {
        case TEST_J:
        case TEST_K:
        case TEST_SE0_NAK:
        case TEST_PACKET:
        case TEST_FORCE_EN:
            usbBase->DCTL |= (uint32_t)testMode << 4;
            break;

        default:
            break;
    }

    return kSTATUS_SUCCESS;
}

static status_t PCD_writeEmptyTxFifo(PCD_HandleTypeDef_t *hpcd, uint32_t epnum)
{
    USB_Type            *usbBase = hpcd->instance;
    USB_OTG_EPTypeDef_t *ep;
    uint32_t             len, len32b, fifoemptymsk;

    ep = &hpcd->inEp[epnum];

    if (ep->xferCount > ep->xferLen)
    {
        return kSTATUS_FAIL;
    }

    len = ep->xferLen - ep->xferCount;

    if (len > ep->maxPacket)
    {
        len = ep->maxPacket;
    }

    len32b = (len + 3U) / 4U;

    while (((usbBase->DIEP_GRPb[epnum].DTXFSTS_N & USB_DTXFSTS_N_IN_EP_TXF_SPC_AVAIL_Msk) >= len32b) &&
           (ep->xferCount < ep->xferLen) && (ep->xferLen != 0U))
    {
        /* Write the FIFO */
        len = ep->xferLen - ep->xferCount;

        if (len > ep->maxPacket)
        {
            len = ep->maxPacket;
        }
        len32b = (len + 3U) / 4U;

        (void)USB_writePacket(usbBase, ep->xferBuff, (uint8_t)epnum, (uint16_t)len, (uint8_t)hpcd->init.dmaEnable);

        ep->xferBuff  += len;
        ep->xferCount += len;
    }

    if (ep->xferLen <= ep->xferCount)
    {
        fifoemptymsk         = (uint32_t)(0x1UL << (epnum & EP_ADDR_MSK));
        usbBase->DIEPEMPMSK &= ~fifoemptymsk;
    }

    return kSTATUS_SUCCESS;
}

static status_t PCD_EP_outXfrCompleteInt(PCD_HandleTypeDef_t *hpcd, uint32_t epnum)
{
    USB_OTG_EPTypeDef_t *ep;
    USB_Type            *usbBase    = hpcd->instance;
    uint32_t             gSNPSiD    = usbBase->GSNPSID; //*(__IO uint32_t *)(&usbBase->CID + 0x1U);
    uint32_t             doEpIntReg = usbBase->DOEP_GRPb[epnum].DOEPINT_N;

    if (hpcd->init.dmaEnable == 1U)
    {
        if (USB_DOEPINT_N_DOEP_IN_T_N_SET_UP_Get(doEpIntReg)) /* Class C */
        {
            /* StupPktRcvd = 1 this is a setup packet */
            if ((gSNPSiD > USB_OTG_CORE_ID_300A) && (USB_DOEPINT_N_DOEP_IN_T_N_STUP_PKT_RCVD_Get(doEpIntReg)))
            {
                CLEAR_OUT_EP_INTR(epnum, USB_DOEPINT_N_DOEP_IN_T_N_STUP_PKT_RCVD_Msk);
            }
        }
        else if (USB_DOEPINT_N_DOEP_IN_T_N_STS_PHSE_RCVD_Get(doEpIntReg)) /* Class E */
        {
            CLEAR_OUT_EP_INTR(epnum, USB_DOEPINT_N_DOEP_IN_T_N_STS_PHSE_RCVD_Msk);
        }
        else if ((doEpIntReg & (USB_DOEPINT_N_DOEP_IN_T_N_SET_UP_Msk | USB_DOEPINT_N_DOEP_IN_T_N_STS_PHSE_RCVD_Msk)) ==
                 0U)
        {
            /* StupPktRcvd = 1 this is a setup packet */
            if ((gSNPSiD > USB_OTG_CORE_ID_300A) && (USB_DOEPINT_N_DOEP_IN_T_N_STUP_PKT_RCVD_Get(doEpIntReg)))
            {
                CLEAR_OUT_EP_INTR(epnum, USB_DOEPINT_N_DOEP_IN_T_N_STUP_PKT_RCVD_Msk);
            }
            else
            {
                ep = &hpcd->outEp[epnum];

                /* out data packet received over EP */
                ep->xferCount =
                    ep->xferSize - (usbBase->DOEP_GRPb[epnum].DOEPTSIZ_N & USB_DOEPTSIZ_N_DOEP_TSIZ_N_XFER_SIZE_Msk);

                if (epnum == 0U)
                {
                    if (ep->xferLen == 0U)
                    {
                        /* this is ZLP, so prepare EP0 for next setup */
                        (void)USB_ep0OutStart(hpcd->instance, 1U, (uint8_t *)hpcd->setup);
                    }
                    else
                    {
                        ep->xferBuff += ep->xferCount;
                    }
                }

                PCD_dataOutStageCallback(hpcd, (uint8_t)epnum);
            }
        }
        else
        {
            /* ... */
        }
    }
    else
    {
        if (gSNPSiD == USB_OTG_CORE_ID_310A)
        {
            /* StupPktRcvd = 1 this is a setup packet */
            if (USB_DOEPINT_N_DOEP_IN_T_N_STUP_PKT_RCVD_Get(doEpIntReg))
            {
                CLEAR_OUT_EP_INTR(epnum, USB_DOEPINT_N_DOEP_IN_T_N_STUP_PKT_RCVD_Msk);
            }
            else
            {
                if (USB_DOEPINT_N_DOEP_IN_T_N_STS_PHSE_RCVD_Get(doEpIntReg))
                {
                    CLEAR_OUT_EP_INTR(epnum, USB_DOEPINT_N_DOEP_IN_T_N_STS_PHSE_RCVD_Msk);
                }

                PCD_dataOutStageCallback(hpcd, (uint8_t)epnum);
            }
        }
        else
        {
            if ((epnum == 0U) && (hpcd->outEp[epnum].xferLen == 0U))
            {
                /* this is ZLP, so prepare EP0 for next setup */
                (void)USB_ep0OutStart(hpcd->instance, 0U, (uint8_t *)hpcd->setup);
            }

            PCD_dataOutStageCallback(hpcd, (uint8_t)epnum);
        }
    }

    return kSTATUS_SUCCESS;
}

static status_t PCD_EP_outSetupPacketInt(PCD_HandleTypeDef_t *hpcd, uint32_t epnum)
{
    USB_Type *usbBase    = hpcd->instance;
    uint32_t  gSNPSiD    = usbBase->GSNPSID;
    uint32_t  doEpIntReg = usbBase->DOEP_GRPb[epnum].DOEPINT_N;

    if ((gSNPSiD > USB_OTG_CORE_ID_300A) && (USB_DOEPINT_N_DOEP_IN_T_N_STUP_PKT_RCVD_Get(doEpIntReg)))
    {
        CLEAR_OUT_EP_INTR(epnum, USB_DOEPINT_N_DOEP_IN_T_N_STUP_PKT_RCVD_Msk);
    }

    /* Inform the upper layer that a setup packet is available */
    PCD_setupStageCallback(hpcd);

    if ((gSNPSiD > USB_OTG_CORE_ID_300A) && (hpcd->init.dmaEnable == 1U))
    {
        (void)USB_ep0OutStart(hpcd->instance, 1U, (uint8_t *)hpcd->setup);
    }

    return kSTATUS_SUCCESS;
}
