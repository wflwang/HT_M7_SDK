/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_ll_usb.c
 * \brief SDK USB low-level driver source file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_ll_usb.h"
#include "hte_debug_console.h"
#include "hte_gpio.h"
#include "hte_hcd.h"
#include "hte_pcd.h"
#include "hte_pcd_ex.h"

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * \brief  Reset the USB Core (needed after USB clock settings change)
 * \param[in]  usbBase  Selected device
 * \return  status_t
 */
static status_t USB_coreReset(USB_Type *usbBase);

/*******************************************************************************
 * Variables
 ******************************************************************************/


/*******************************************************************************
 * Codes
 ******************************************************************************/
void USBA_EP_MP_Handler(void)
{
    if (USB_getMode(USBA) == (uint32_t)kUSB_HOST_MODE)
    {
        HCD_IRQHandler(&g_hcdHandle);
    }
    else if (USB_getMode(USBA) == (uint32_t)kUSB_DEVICE_MODE)
    {
        PCD_IRQHandler(&g_pcdHandle);
    }
    else
    {
        USB_errorHandler();
    }
    ISR_EXIT_BARRIER();
}

void USBA_Handler(void)
{
    if (USB_getMode(USBA) == (uint32_t)kUSB_HOST_MODE)
    {
        HCD_IRQHandler(&g_hcdHandle);
    }
    else if (USB_getMode(USBA) == (uint32_t)kUSB_DEVICE_MODE)
    {
        PCD_IRQHandler(&g_pcdHandle);
    }
    else
    {
        USB_errorHandler();
    }
    ISR_EXIT_BARRIER();
}

status_t USB_coreInit(USB_Type *usbBase, USB_OTG_CfgTypeDef_t cfg)
{
    status_t ret;

    /* Select FS Embedded PHY */
    usbBase->GUSBCFG |= USB_GUSBCFG_PHY_SEL_Set(1U);

    /* Reset after a PHY select */
    ret = USB_coreReset(usbBase);

    if (cfg.dmaEnable == 1U)
    {
        /* make sure to reserve 128 fifo Locations for DMA buffers */
        usbBase->GDFIFOCFG &= ~(0xFFFFU << 16);
        usbBase->GDFIFOCFG |= 0x380U << 16;
        usbBase->GAHBCFG   |= USB_GAHBCFG_HBST_LEN_Set(0x3);
        usbBase->GAHBCFG |= USB_GAHBCFG_DMA_EN_Set(1U);
    }

    return ret;
}

status_t USB_setTurnaroundTime(USB_Type *usbBase, uint32_t hclk, uint8_t speed)
{
    uint32_t usbTrd;

    /* The USBTRD is configured according to the tables below, depending on AHB frequency
    used by application. In the low AHB frequency range it is used to stretch enough the USB response
    time to IN tokens, the USB turnaround time, so to compensate for the longer AHB read access
    latency to the Data FIFO */
    if (speed == USBD_FS_SPEED)
    {
        if ((hclk >= 14200000U) && (hclk < 15000000U))
        {
            /* hclk Clock Range between 14.2-15 MHz */
            usbTrd = 0xFU;
        }
        else if ((hclk >= 15000000U) && (hclk < 16000000U))
        {
            /* hclk Clock Range between 15-16 MHz */
            usbTrd = 0xEU;
        }
        else if ((hclk >= 16000000U) && (hclk < 17200000U))
        {
            /* hclk Clock Range between 16-17.2 MHz */
            usbTrd = 0xDU;
        }
        else if ((hclk >= 17200000U) && (hclk < 18500000U))
        {
            /* hclk Clock Range between 17.2-18.5 MHz */
            usbTrd = 0xCU;
        }
        else if ((hclk >= 18500000U) && (hclk < 20000000U))
        {
            /* hclk Clock Range between 18.5-20 MHz */
            usbTrd = 0xBU;
        }
        else if ((hclk >= 20000000U) && (hclk < 21800000U))
        {
            /* hclk Clock Range between 20-21.8 MHz */
            usbTrd = 0xAU;
        }
        else if ((hclk >= 21800000U) && (hclk < 24000000U))
        {
            /* hclk Clock Range between 21.8-24 MHz */
            usbTrd = 0x9U;
        }
        else if ((hclk >= 24000000U) && (hclk < 27700000U))
        {
            /* hclk Clock Range between 24-27.7 MHz */
            usbTrd = 0x8U;
        }
        else if ((hclk >= 27700000U) && (hclk < 32000000U))
        {
            /* hclk Clock Range between 27.7-32 MHz */
            usbTrd = 0x7U;
        }
        else /* if(hclk >= 32000000) */
        {
            /* hclk Clock Range between 32-200 MHz */
            usbTrd = 0x6U;
        }
    }
    else if (speed == USBD_HS_SPEED)
    {
        usbTrd = USBD_HS_TRDT_VALUE;
    }
    else
    {
        usbTrd = USBD_DEFAULT_TRDT_VALUE;
    }

    usbBase->GUSBCFG &= ~USB_GUSBCFG_USB_TRD_TIM_Set(0x0F);
    usbBase->GUSBCFG |= (uint32_t)(USB_GUSBCFG_USB_TRD_TIM_Set(usbTrd));

    return kSTATUS_SUCCESS;
}

status_t USB_enableGlobalInt(USB_Type *usbBase)
{
    usbBase->GAHBCFG |= USB_GAHBCFG_GLBL_INTR_MSK_Set(1U);

    return kSTATUS_SUCCESS;
}

status_t USB_disableGlobalInt(USB_Type *usbBase)
{
    usbBase->GAHBCFG &= ~USB_GAHBCFG_GLBL_INTR_MSK_Set(1U);
    return kSTATUS_SUCCESS;
}

status_t USB_setCurrentMode(USB_Type *usbBase, USB_OTG_ModeTypeDef_t mode)
{
    uint32_t ms = 0U;

    usbBase->GUSBCFG &= ~(USB_GUSBCFG_FORCE_HST_MODE_Set(1U) | USB_GUSBCFG_FORCE_DEV_MODE_Set(1U));

    if (mode == kUSB_HOST_MODE)
    {
        usbBase->GUSBCFG |= USB_GUSBCFG_FORCE_HST_MODE_Set(1U);

        do
        {
            DELAY(1U);
            ms++;
        } while ((USB_getMode(usbBase) != (uint32_t)kUSB_HOST_MODE) && (ms < 50U));
    }
    else if (mode == kUSB_DEVICE_MODE)
    {
        usbBase->GUSBCFG |= USB_GUSBCFG_FORCE_DEV_MODE_Set(1U);

        do
        {
            DELAY(1U);
            ms++;
        } while ((USB_getMode(usbBase) != (uint32_t)kUSB_DEVICE_MODE) && (ms < 50U));
    }
    else
    {
        return kSTATUS_FAIL;
    }

    if (ms == 50U)
    {
        return kSTATUS_FAIL;
    }

    return kSTATUS_SUCCESS;
}

status_t USB_devInit(USB_Type *usbBase, USB_OTG_CfgTypeDef_t cfg)
{
    status_t ret = kSTATUS_SUCCESS;

    for (uint32_t i = 0U; i < 8U; i++)
    {
        usbBase->DIEPTXF_N[i] = 0U;
    }

    /* VBUS Sensing setup */
    if (cfg.vbusSensingEnable == 0U)
    {
        usbBase->DCTL |= USB_DCTL_SFT_DISCON_Set(1U);

        /* B-peripheral session valid override enable */
        usbBase->GOTGCTL |= USB_GOTGCTL_BVALID_OV_EN_Set(1U);
        usbBase->GOTGCTL |= USB_GOTGCTL_BVALID_OV_VAL_Set(1U);
    }


    /* Restart the Phy Clock */
    usbBase->PCGCCTL = 0;

    /* Device mode configuration */
    usbBase->DCFG |= DCFG_FRAME_INTERVAL_80;


    if (cfg.phyItface == USB_OTG_ULPI_PHY)
    {
        if (cfg.speed == USBD_HS_SPEED)
        {
            /* Set Core speed to High speed mode */
            (void)USB_setDevSpeed(usbBase, USB_OTG_SPEED_HIGH);
        }
        else
        {
            /* Set Core speed to Full speed mode */
            (void)USB_setDevSpeed(usbBase, USB_OTG_SPEED_HIGH_IN_FULL);
        }
    }
    else
    {
        /* Set Core speed to Full speed mode */
        (void)USB_setDevSpeed(usbBase, USB_OTG_SPEED_FULL);
    }

    /* Flush the FIFOs */
    if (USB_flushTxFifo(usbBase, 0x10U) != kSTATUS_SUCCESS) /* all Tx FIFOs */
    {
        ret = kSTATUS_FAIL;
    }

    if (USB_flushRxFifo(usbBase) != kSTATUS_SUCCESS)
    {
        ret = kSTATUS_FAIL;
    }

    /* Clear all pending Device Interrupts */
    usbBase->DIEPMSK  = 0U;
    usbBase->DOEPMSK  = 0U;
    usbBase->DAINTMSK = 0U;

    for (uint32_t i = 0U; i < cfg.devEndpoints; i++)
    {
        if (USB_DIEPCTL_N_DIEP_CTL_N_EP_ENA_Get(usbBase->DIEP_GRPb[i].DIEPCTL_N))
        {
            if (i == 0U)
            {
                usbBase->DIEP_GRPb[i].DIEPCTL_N = USB_DIEPCTL_N_DIEP_CTL_N_SNAK_Set(1U);
            }
            else
            {
                usbBase->DIEP_GRPb[i].DIEPCTL_N =
                    USB_DIEPCTL_N_DIEP_CTL_N_EP_DIS_Set(1U) | USB_DIEPCTL_N_DIEP_CTL_N_SNAK_Set(1U);
            }
        }
        else
        {
            usbBase->DIEP_GRPb[i].DIEPCTL_N = 0U;
        }

        usbBase->DIEP_GRPb[i].DIEPTSIZ_N = 0U;
        usbBase->DIEP_GRPb[i].DIEPINT_N  = 0xFB7FU;
    }

    for (uint32_t i = 0U; i < cfg.devEndpoints; i++)
    {
        if (USB_DOEPCTL_N_DOEP_CTL_N_EP_ENA_Get(usbBase->DOEP_GRPb[i].DOEPCTL_N))
        {
            if (i == 0U)
            {
                usbBase->DOEP_GRPb[i].DOEPCTL_N = USB_DOEPCTL_N_DOEP_CTL_N_SNAK_Set(1U);
            }
            else
            {
                usbBase->DOEP_GRPb[i].DOEPCTL_N =
                    USB_DOEPCTL_N_DOEP_CTL_N_EP_DIS_Set(1U) | USB_DOEPCTL_N_DOEP_CTL_N_SNAK_Set(1U);
            }
        }
        else
        {
            usbBase->DOEP_GRPb[i].DOEPCTL_N = 0;
        }

        usbBase->DOEP_GRPb[i].DOEPTSIZ_N = 0U;
        usbBase->DOEP_GRPb[i].DOEPINT_N  = 0xFB7FU;
    }

    usbBase->DIEPMSK &= ~(USB_DIEPMSK_DIEP_MSK_TXFIFO_UNDRN_MSK_Set(1U));

    usbBase->DIEPMSK = 0xFB7FU;

    /* Disable all interrupts. */
    usbBase->GINTMSK = 0U;

    /* Clear any pending interrupts */
    usbBase->GINTSTS = 0xBFFFFFFFU;

    /* Enable the common interrupts */
    if (cfg.dmaEnable == 0U)
    {
        usbBase->GINTMSK |= USB_GINTMSK_RXF_LVL_MSK_Set(1U);
    }

    /* Enable interrupts matching to the Device mode ONLY */
    usbBase->GINTMSK |= USB_GINTMSK_USB_SUSP_MSK_Set(1U) | USB_GINTMSK_USB_RST_MSK_Set(1U) |
                        USB_GINTMSK_ENUM_DONE_MSK_Set(1U) | USB_GINTMSK_IEP_INT_MSK_Set(1U) |
                        USB_GINTMSK_OEP_INT_MSK_Set(1U) | USB_GINTMSK_INCOMPL_PMS_K_Set(1U) |
                        USB_GINTMSK_WK_UP_INT_MSK_Set(1U);

    if (cfg.sofEnable != 0U)
    {
        usbBase->GINTMSK |= USB_GINTMSK_SOF_MSK_Set(1U);
    }

    if (cfg.vbusSensingEnable == 1U)
    {
        usbBase->GINTMSK |= (USB_GINTMSK_SESS_REQ_INT_MSK_Set(1U) | USB_GINTMSK_OTG_INT_MSK_Set(1U));
    }

    return ret;
}

status_t USB_flushTxFifo(USB_Type *usbBase, uint32_t num)
{
    __IO uint32_t count = 0U;

    /* Wait for AHB master IDLE state. */
    do
    {
        count++;

        if (count > 200000U)
        {
            return kSTATUS_NOT_SUPPORTED;
        }
    } while (USB_GRSTCTL_AHB_IDLE_Get(usbBase->GRSTCTL) == 0U);

    /* Flush TX Fifo */
    count            = 0U;
    usbBase->GRSTCTL = (USB_GRSTCTL_TXF_FLSH_Set(1U) | (num << 6));

    do
    {
        count++;

        if (count > 200000U)
        {
            return kSTATUS_NOT_SUPPORTED;
        }
    } while (USB_GRSTCTL_TXF_FLSH_Get(usbBase->GRSTCTL));

    return kSTATUS_SUCCESS;
}

status_t USB_flushRxFifo(USB_Type *usbBase)
{
    __IO uint32_t count = 0U;

    /* Wait for AHB master IDLE state. */
    do
    {
        count++;

        if (count > 200000U)
        {
            return kSTATUS_NOT_SUPPORTED;
        }
    } while (USB_GRSTCTL_AHB_IDLE_Get(usbBase->GRSTCTL) == 0U);

    /* Flush RX Fifo */
    count            = 0U;
    usbBase->GRSTCTL = USB_GRSTCTL_RXF_FLSH_Set(1U);

    do
    {
        count++;

        if (count > 200000U)
        {
            return kSTATUS_NOT_SUPPORTED;
        }
    } while (USB_GRSTCTL_RXF_FLSH_Get(usbBase->GRSTCTL));

    return kSTATUS_SUCCESS;
}

status_t USB_setDevSpeed(USB_Type *usbBase, uint8_t speed)
{
    usbBase->DCFG |= speed;
    return kSTATUS_SUCCESS;
}

uint8_t USB_getDevSpeed(USB_Type *usbBase)
{
    uint8_t  speed;
    uint32_t devEnumSpeed = usbBase->DSTS & USB_DSTS_ENUM_SPD_Msk;

    if (devEnumSpeed == DSTS_ENUMSPD_HS_PHY_30MHZ_OR_60MHZ)
    {
        speed = USBD_HS_SPEED;
    }
    else if ((devEnumSpeed == DSTS_ENUMSPD_FS_PHY_30MHZ_OR_60MHZ) || (devEnumSpeed == DSTS_ENUMSPD_FS_PHY_48MHZ))
    {
        speed = USBD_FS_SPEED;
    }
    else
    {
        speed = 0xFU;
    }

    return speed;
}

status_t USB_activateEndpoint(USB_Type *usbBase, USB_OTG_EPTypeDef_t *ep)
{
    uint32_t epnum = (uint32_t)ep->num;

    if (ep->isIn == 1U)
    {
        usbBase->DAINTMSK |= USB_DAINTMSK_IEPM & (uint32_t)(1UL << (ep->num & EP_ADDR_MSK));

        if (USB_DIEPCTL_N_DIEP_CTL_N_USB_ACT_EP_Get(usbBase->DIEP_GRPb[epnum].DIEPCTL_N) == 0U)
        {
            usbBase->DIEP_GRPb[epnum].DIEPCTL_N |=
                (USB_DIEPCTL_N_DIEP_CTL_N_MPS_Set(ep->maxPacket)) | ((uint32_t)ep->type << 18) | (epnum << 22) |
                USB_DIEPCTL_N_DIEP_CTL_N_SET_D0PID_Set(1U) | USB_DIEPCTL_N_DIEP_CTL_N_USB_ACT_EP_Set(1U);
        }
    }
    else
    {
        usbBase->DAINTMSK |= USB_DAINTMSK_OEPM & ((uint32_t)(1UL << (ep->num & EP_ADDR_MSK)) << 16);

        if ((USB_DOEPCTL_N_DOEP_CTL_N_USB_ACT_EP_Get(usbBase->DOEP_GRPb[epnum].DOEPCTL_N)) == 0U)
        {
            usbBase->DOEP_GRPb[epnum].DOEPCTL_N |=
                (ep->maxPacket & USB_DOEPCTL_N_DOEP_CTL_N_MPS_Msk) | ((uint32_t)ep->type << 18) |
                USB_DIEPCTL_N_DIEP_CTL_N_SET_D0PID_Set(1U) | USB_DOEPCTL_N_DOEP_CTL_N_USB_ACT_EP_Set(1U);
        }
    }
    return kSTATUS_SUCCESS;
}

status_t USB_activateDedicatedEndpoint(USB_Type *usbBase, USB_OTG_EPTypeDef_t *ep)
{
    uint32_t epnum = (uint32_t)ep->num;

    /* Read DEPCTLn register */
    if (ep->isIn == 1U)
    {
        if (USB_DIEPCTL_N_DIEP_CTL_N_USB_ACT_EP_Get(usbBase->DIEP_GRPb[epnum].DIEPCTL_N) == 0U)
        {
            usbBase->DIEP_GRPb[epnum].DIEPCTL_N |=
                (USB_DIEPCTL_N_DIEP_CTL_N_MPS_Set(ep->maxPacket)) | ((uint32_t)ep->type << 18) | (epnum << 22) |
                USB_DIEPCTL_N_DIEP_CTL_N_SET_D0PID_Set(1U) | USB_DIEPCTL_N_DIEP_CTL_N_USB_ACT_EP_Set(1U);
        }

        usbBase->DEACHINTMSK |= USB_DAINTMSK_IEPM & (uint32_t)(1UL << (ep->num & EP_ADDR_MSK));
    }
    else
    {
        if ((USB_DOEPCTL_N_DOEP_CTL_N_USB_ACT_EP_Get(usbBase->DOEP_GRPb[epnum].DOEPCTL_N)) == 0U)
        {
            usbBase->DOEP_GRPb[epnum].DOEPCTL_N |= (USB_DOEPCTL_N_DOEP_CTL_N_MPS_Set(ep->maxPacket)) |
                                                   ((uint32_t)ep->type << 18) | (epnum << 22) |
                                                   USB_DOEPCTL_N_DOEP_CTL_N_USB_ACT_EP_Set(1U);
        }

        usbBase->DEACHINTMSK |= USB_DAINTMSK_OEPM & ((uint32_t)(1UL << (ep->num & EP_ADDR_MSK)) << 16);
    }

    return kSTATUS_SUCCESS;
}

status_t USB_deactivateEndpoint(USB_Type *usbBase, USB_OTG_EPTypeDef_t *ep)
{
    uint32_t epnum = (uint32_t)ep->num;

    /* Read DEPCTLn register */
    if (ep->isIn == 1U)
    {
        if (USB_DIEPCTL_N_DIEP_CTL_N_EP_ENA_Get(usbBase->DIEP_GRPb[epnum].DIEPCTL_N))
        {
            usbBase->DIEP_GRPb[epnum].DIEPCTL_N |= USB_DIEPCTL_N_DIEP_CTL_N_SNAK_Set(1U);
            usbBase->DIEP_GRPb[epnum].DIEPCTL_N |= USB_DIEPCTL_N_DIEP_CTL_N_EP_DIS_Set(1U);
        }

        usbBase->DEACHINTMSK &= ~(USB_DAINTMSK_IEPM & (uint32_t)(1UL << (ep->num & EP_ADDR_MSK)));
        usbBase->DAINTMSK    &= ~(USB_DAINTMSK_IEPM & (uint32_t)(1UL << (ep->num & EP_ADDR_MSK)));
        usbBase->DIEP_GRPb[epnum].DIEPCTL_N &=
            ~(USB_DIEPCTL_N_DIEP_CTL_N_USB_ACT_EP_Set(1U) | USB_DIEPCTL_N_DIEP_CTL_N_MPS_Set(1U) |
              USB_DIEPCTL_N_DIEP_CTL_N_TXF_NUM_Set(1U) | USB_DIEPCTL_N_DIEP_CTL_N_SET_D0PID_Set(1U) |
              USB_DIEPCTL_N_DIEP_CTL_N_EP_TYPE_Set(1U));
    }
    else
    {
        if (USB_DOEPCTL_N_DOEP_CTL_N_EP_ENA_Get(usbBase->DOEP_GRPb[epnum].DOEPCTL_N))
        {
            usbBase->DOEP_GRPb[epnum].DOEPCTL_N |= USB_DOEPCTL_N_DOEP_CTL_N_SNAK_Set(1U);
            usbBase->DOEP_GRPb[epnum].DOEPCTL_N |= USB_DOEPCTL_N_DOEP_CTL_N_EP_DIS_Set(1U);
        }

        usbBase->DEACHINTMSK &= ~(USB_DAINTMSK_OEPM & ((uint32_t)(1UL << (ep->num & EP_ADDR_MSK)) << 16));
        usbBase->DAINTMSK    &= ~(USB_DAINTMSK_OEPM & ((uint32_t)(1UL << (ep->num & EP_ADDR_MSK)) << 16));
        usbBase->DOEP_GRPb[epnum].DOEPCTL_N &=
            ~(USB_DOEPCTL_N_DOEP_CTL_N_USB_ACT_EP_Set(1U) | USB_DOEPCTL_N_DOEP_CTL_N_MPS_Set(1U) |
              USB_DOEPCTL_N_DOEP_CTL_N_SET_D0PID_Set(1U) | USB_DOEPCTL_N_DOEP_CTL_N_EP_TYPE_Set(1U));
    }

    return kSTATUS_SUCCESS;
}

status_t USB_deactivateDedicatedEndpoint(USB_Type *usbBase, USB_OTG_EPTypeDef_t *ep)
{
    uint32_t epnum = (uint32_t)ep->num;

    /* Read DEPCTLn register */
    if (ep->isIn == 1U)
    {
        if (USB_DIEPCTL_N_DIEP_CTL_N_EP_ENA_Get(usbBase->DIEP_GRPb[epnum].DIEPCTL_N))
        {
            usbBase->DIEP_GRPb[epnum].DIEPCTL_N |= USB_DIEPCTL_N_DIEP_CTL_N_SNAK_Set(1U);
            usbBase->DIEP_GRPb[epnum].DIEPCTL_N |= USB_DIEPCTL_N_DIEP_CTL_N_EP_DIS_Set(1U);
        }

        usbBase->DIEP_GRPb[epnum].DIEPCTL_N &= ~USB_DIEPCTL_N_DIEP_CTL_N_USB_ACT_EP_Set(1U);
        usbBase->DAINTMSK                   &= ~(USB_DAINTMSK_IEPM & (uint32_t)(1UL << (ep->num & EP_ADDR_MSK)));
    }
    else
    {
        if (USB_DOEPCTL_N_DOEP_CTL_N_EP_ENA_Get(usbBase->DOEP_GRPb[epnum].DOEPCTL_N))
        {
            usbBase->DOEP_GRPb[epnum].DOEPCTL_N |= USB_DOEPCTL_N_DOEP_CTL_N_SNAK_Set(1U);
            usbBase->DOEP_GRPb[epnum].DOEPCTL_N |= USB_DOEPCTL_N_DOEP_CTL_N_EP_DIS_Set(1U);
        }

        usbBase->DOEP_GRPb[epnum].DOEPCTL_N &= ~USB_DOEPCTL_N_DOEP_CTL_N_USB_ACT_EP_Set(1U);
        usbBase->DAINTMSK &= ~(USB_DAINTMSK_OEPM & ((uint32_t)(1UL << (ep->num & EP_ADDR_MSK)) << 16));
    }

    return kSTATUS_SUCCESS;
}

status_t USB_epStartXfer(USB_Type *usbBase, USB_OTG_EPTypeDef_t *ep, uint8_t dma)
{
    uint32_t epnum = (uint32_t)ep->num;
    uint16_t pktcnt;

    /* IN endpoint */
    if (ep->isIn == 1U)
    {
        /* Zero Length Packet? */
        if (ep->xferLen == 0U)
        {
            usbBase->DIEP_GRPb[epnum].DIEPTSIZ_N &= ~(USB_DIEPTSIZ_N_DIEP_TSIZ_N_PKT_CNT_Set(0x3ffU));
            usbBase->DIEP_GRPb[epnum].DIEPTSIZ_N |= (USB_DIEPTSIZ_N_DIEP_TSIZ_N_PKT_CNT_Set(1U));
            usbBase->DIEP_GRPb[epnum].DIEPTSIZ_N &= ~(USB_DIEPTSIZ_N_DIEP_TSIZ_N_XFER_SIZE_Set(0x3ffU));
        }
        else
        {
            /* Program the transfer size and packet count
             * as follows: xferSize = N * maxpacket +
             * short_packet pktcnt = N + (short_packet
             * exist ? 1 : 0)
             */
            usbBase->DIEP_GRPb[epnum].DIEPTSIZ_N &= ~(USB_DIEPTSIZ_N_DIEP_TSIZ_N_XFER_SIZE_Set(0x3ffU));
            usbBase->DIEP_GRPb[epnum].DIEPTSIZ_N &= ~(USB_DIEPTSIZ_N_DIEP_TSIZ_N_PKT_CNT_Set(0x3ffU));
            usbBase->DIEP_GRPb[epnum].DIEPTSIZ_N |= (USB_DIEPTSIZ_N_DIEP_TSIZ_N_PKT_CNT_Set(0x3ffU) &
                                                     (((ep->xferLen + ep->maxPacket - 1U) / ep->maxPacket) << 19));

            usbBase->DIEP_GRPb[epnum].DIEPTSIZ_N |= (USB_DIEPTSIZ_N_DIEP_TSIZ_N_XFER_SIZE_Set(ep->xferLen));

            if (ep->type == EP_TYPE_ISOC)
            {
                usbBase->DIEP_GRPb[epnum].DIEPTSIZ_N &= ~(USB_DIEPTSIZ_N_MC_Set(0x3U));
                usbBase->DIEP_GRPb[epnum].DIEPTSIZ_N |= (USB_DIEPTSIZ_N_MC_Set(1U));
            }
        }

        if (dma == 1U)
        {
            if ((uint32_t)ep->dmaAddr != 0U)
            {
                usbBase->DIEP_GRPb[epnum].DIEPDMA_N = (uint32_t)(ep->dmaAddr);
            }

            if (ep->type == EP_TYPE_ISOC)
            {
                if ((usbBase->DSTS & (1U << 8)) == 0U)
                {
                    usbBase->DIEP_GRPb[epnum].DIEPCTL_N |= USB_DIEPCTL_N_DIEP_CTL_N_SET_D1PID_Set(1U);
                }
                else
                {
                    usbBase->DIEP_GRPb[epnum].DIEPCTL_N |= USB_DIEPCTL_N_DIEP_CTL_N_SET_D0PID_Set(1U);
                }
            }

            /* EP enable, IN data in FIFO */
            usbBase->DIEP_GRPb[epnum].DIEPCTL_N |=
                (USB_DIEPCTL_N_DIEP_CTL_N_CNAK_Set(1U) | USB_DIEPCTL_N_DIEP_CTL_N_EP_ENA_Set(1U));
        }
        else
        {
            /* EP enable, IN data in FIFO */
            usbBase->DIEP_GRPb[epnum].DIEPCTL_N |=
                (USB_DIEPCTL_N_DIEP_CTL_N_CNAK_Set(1U) | USB_DIEPCTL_N_DIEP_CTL_N_EP_ENA_Set(1U));

            if (ep->type != EP_TYPE_ISOC)
            {
                /* Enable the Tx FIFO Empty Interrupt for this EP */
                if (ep->xferLen > 0U)
                {
                    usbBase->DIEPEMPMSK |= 1UL << (ep->num & EP_ADDR_MSK);
                }
            }
            else
            {
                if ((usbBase->DSTS & (1U << 8)) == 0U)
                {
                    usbBase->DIEP_GRPb[epnum].DIEPCTL_N |= USB_DIEPCTL_N_DIEP_CTL_N_SET_D1PID_Set(1U);
                }
                else
                {
                    usbBase->DIEP_GRPb[epnum].DIEPCTL_N |= USB_DIEPCTL_N_DIEP_CTL_N_SET_D0PID_Set(1U);
                }

                (void)USB_writePacket(usbBase, ep->xferBuff, ep->num, (uint16_t)ep->xferLen, dma);
            }
        }
    }
    else /* OUT endpoint */
    {
        /* Program the transfer size and packet count as follows:
         * pktcnt = N
         * xferSize = N * maxpacket
         */
        usbBase->DOEP_GRPb[epnum].DOEPTSIZ_N &= ~(USB_DOEPTSIZ_N_DOEP_TSIZ_N_XFER_SIZE_Set(0x7ffffU));
        usbBase->DOEP_GRPb[epnum].DOEPTSIZ_N &= ~(USB_DOEPTSIZ_N_DOEP_TSIZ_N_PKT_CNT_Set(0x3ffU));

        if (ep->xferLen == 0U)
        {
            usbBase->DOEP_GRPb[epnum].DOEPTSIZ_N |= (USB_DOEPTSIZ_N_DOEP_TSIZ_N_XFER_SIZE_Set(ep->maxPacket));
            usbBase->DOEP_GRPb[epnum].DOEPTSIZ_N |= (USB_DOEPTSIZ_N_DOEP_TSIZ_N_PKT_CNT_Set(1U));
        }
        else
        {
            pktcnt       = (uint16_t)((ep->xferLen + ep->maxPacket - 1U) / ep->maxPacket);
            ep->xferSize = ep->maxPacket * pktcnt;

            usbBase->DOEP_GRPb[epnum].DOEPTSIZ_N |= USB_DOEPTSIZ_N_DOEP_TSIZ_N_PKT_CNT_Set((uint32_t)pktcnt);
            usbBase->DOEP_GRPb[epnum].DOEPTSIZ_N |= USB_DOEPTSIZ_N_DOEP_TSIZ_N_XFER_SIZE_Set(ep->xferSize);
        }

        if (dma == 1U)
        {
            if ((uint32_t)ep->xferBuff != 0U)
            {
                usbBase->DOEP_GRPb[epnum].DOEPDMA_N = (uint32_t)(ep->xferBuff);
            }
        }

        if (ep->type == EP_TYPE_ISOC)
        {
            if ((usbBase->DSTS & (1U << 8)) == 0U)
            {
                usbBase->DOEP_GRPb[epnum].DOEPCTL_N |= USB_DOEPCTL_N_DOEP_CTL_N_SET_D1PID_Set(1U);
            }
            else
            {
                usbBase->DOEP_GRPb[epnum].DOEPCTL_N |= USB_DOEPCTL_N_DOEP_CTL_N_SET_D0PID_Set(1U);
            }
        }
        /* EP enable */
        usbBase->DOEP_GRPb[epnum].DOEPCTL_N |=
            (USB_DOEPCTL_N_DOEP_CTL_N_CNAK_Set(1U) | USB_DOEPCTL_N_DOEP_CTL_N_EP_ENA_Set(1U));
    }

    return kSTATUS_SUCCESS;
}

status_t USB_ep0StartXfer(USB_Type *usbBase, USB_OTG_EPTypeDef_t *ep, uint8_t dma)
{
    uint32_t epnum = (uint32_t)ep->num;

    /* IN endpoint */
    if (ep->isIn == 1U)
    {
        /* Zero Length Packet? */
        if (ep->xferLen == 0U)
        {
            usbBase->DIEP_GRPb[epnum].DIEPTSIZ_N &= ~(USB_DIEPTSIZ_N_DIEP_TSIZ_N_PKT_CNT_Set(0x3ffU));
            usbBase->DIEP_GRPb[epnum].DIEPTSIZ_N |= (USB_DIEPTSIZ_N_DIEP_TSIZ_N_PKT_CNT_Set(1U));
            usbBase->DIEP_GRPb[epnum].DIEPTSIZ_N &= ~(USB_DIEPTSIZ_N_DIEP_TSIZ_N_XFER_SIZE_Set(0x3ffU));
        }
        else
        {
            /* Program the transfer size and packet count
             * as follows: xferSize = N * maxpacket +
             * short_packet pktcnt = N + (short_packet
             * exist ? 1 : 0)
             */
            usbBase->DIEP_GRPb[epnum].DIEPTSIZ_N &= ~(USB_DIEPTSIZ_N_DIEP_TSIZ_N_XFER_SIZE_Set(0x3ffU));
            usbBase->DIEP_GRPb[epnum].DIEPTSIZ_N &= ~(USB_DIEPTSIZ_N_DIEP_TSIZ_N_PKT_CNT_Set(0x3ffU));

            if (ep->xferLen > ep->maxPacket)
            {
                ep->xferLen = ep->maxPacket;
            }
            usbBase->DIEP_GRPb[epnum].DIEPTSIZ_N |= (USB_DIEPTSIZ_N_DIEP_TSIZ_N_PKT_CNT_Set(1U));
            usbBase->DIEP_GRPb[epnum].DIEPTSIZ_N |= (USB_DIEPTSIZ_N_DIEP_TSIZ_N_XFER_SIZE_Set(0x3ffU) & ep->xferLen);
        }

        if (dma == 1U)
        {
            if ((uint32_t)ep->dmaAddr != 0U)
            {
                usbBase->DIEP_GRPb[epnum].DIEPDMA_N = (uint32_t)(ep->dmaAddr);
            }

            /* EP enable, IN data in FIFO */
            usbBase->DIEP_GRPb[epnum].DIEPCTL_N |=
                (USB_DIEPCTL_N_DIEP_CTL_N_CNAK_Set(1U) | USB_DIEPCTL_N_DIEP_CTL_N_EP_ENA_Set(1U));
        }
        else
        {
            /* EP enable, IN data in FIFO */
            usbBase->DIEP_GRPb[epnum].DIEPCTL_N |=
                (USB_DIEPCTL_N_DIEP_CTL_N_CNAK_Set(1U) | USB_DIEPCTL_N_DIEP_CTL_N_EP_ENA_Set(1U));

            /* Enable the Tx FIFO Empty Interrupt for this EP */
            if (ep->xferLen > 0U)
            {
                usbBase->DIEPEMPMSK |= 1UL << (ep->num & EP_ADDR_MSK);
            }
        }
    }
    else /* OUT endpoint */
    {
        /* Program the transfer size and packet count as follows:
         * pktcnt = N
         * xferSize = N * maxpacket
         */
        usbBase->DOEP_GRPb[epnum].DOEPTSIZ_N &= ~(USB_DOEPTSIZ_N_DOEP_TSIZ_N_XFER_SIZE_Set(0x7ffffU));
        usbBase->DOEP_GRPb[epnum].DOEPTSIZ_N &= ~(USB_DOEPTSIZ_N_DOEP_TSIZ_N_PKT_CNT_Set(0x3ffU));

        if (ep->xferLen > 0U)
        {
            ep->xferLen = ep->maxPacket;
        }

        /* Store transfer size, for EP0 this is equal to endpoint max packet size */
        ep->xferSize = ep->maxPacket;

        usbBase->DOEP_GRPb[epnum].DOEPTSIZ_N |= (USB_DOEPTSIZ_N_DOEP_TSIZ_N_PKT_CNT_Set(1U));
        usbBase->DOEP_GRPb[epnum].DOEPTSIZ_N |= (USB_DOEPTSIZ_N_DOEP_TSIZ_N_XFER_SIZE_Set(0x7ffffU) & ep->xferSize);

        if (dma == 1U)
        {
            if ((uint32_t)ep->xferBuff != 0U)
            {
                usbBase->DOEP_GRPb[epnum].DOEPDMA_N = (uint32_t)(ep->xferBuff);
            }
        }

        /* EP enable */
        usbBase->DOEP_GRPb[epnum].DOEPCTL_N |=
            (USB_DOEPCTL_N_DOEP_CTL_N_CNAK_Set(1U) | USB_DOEPCTL_N_DOEP_CTL_N_EP_ENA_Set(1U));
    }

    return kSTATUS_SUCCESS;
}

status_t USB_epStopXfer(USB_Type *usbBase, USB_OTG_EPTypeDef_t *ep)
{
    __IO uint32_t count = 0U;
    status_t      ret   = kSTATUS_SUCCESS;

    /* IN endpoint */
    if (ep->isIn == 1U)
    {
        /* EP enable, IN data in FIFO */
        if ((USB_DIEPCTL_N_DIEP_CTL_N_EP_ENA_Get(usbBase->DIEP_GRPb[ep->num].DIEPCTL_N)))
        {
            usbBase->DIEP_GRPb[ep->num].DIEPCTL_N |= (USB_DIEPCTL_N_DIEP_CTL_N_SNAK_Set(1U));
            usbBase->DIEP_GRPb[ep->num].DIEPCTL_N |= (USB_DIEPCTL_N_DIEP_CTL_N_EP_DIS_Set(1U));

            do
            {
                count++;

                if (count > 10000U)
                {
                    ret = kSTATUS_FAIL;
                    break;
                }
            } while ((USB_DIEPCTL_N_DIEP_CTL_N_EP_ENA_Get(usbBase->DIEP_GRPb[ep->num].DIEPCTL_N)));
        }
    }
    else /* OUT endpoint */
    {
        if ((USB_DOEPCTL_N_DOEP_CTL_N_EP_ENA_Get(usbBase->DOEP_GRPb[ep->num].DOEPCTL_N)))
        {
            usbBase->DOEP_GRPb[ep->num].DOEPCTL_N |= (USB_DOEPCTL_N_DOEP_CTL_N_SNAK_Set(1U));
            usbBase->DOEP_GRPb[ep->num].DOEPCTL_N |= (USB_DOEPCTL_N_DOEP_CTL_N_EP_DIS_Set(1U));

            do
            {
                count++;

                if (count > 10000U)
                {
                    ret = kSTATUS_FAIL;
                    break;
                }
            } while ((USB_DOEPCTL_N_DOEP_CTL_N_EP_ENA_Get(usbBase->DOEP_GRPb[ep->num].DOEPCTL_N)));
        }
    }

    return ret;
}

status_t USB_writePacket(USB_Type *usbBase, uint8_t *src, uint8_t chEpNum, uint16_t len, uint8_t dma)
{
    uint32_t USBx_BASE = (uint32_t)usbBase;
    uint8_t *pSrc      = src;
    uint32_t count32b;

    if (dma == 0U)
    {
        count32b = ((uint32_t)len + 3U) / 4U;
        for (uint32_t i = 0U; i < count32b; i++)
        {
            USBx_DFIFO((uint32_t)chEpNum) = __UNALIGNED_UINT32_READ(pSrc);

            pSrc++;
            pSrc++;
            pSrc++;
            pSrc++;
        }
    }

    return kSTATUS_SUCCESS;
}

void *USB_readPacket(USB_Type *usbBase, uint8_t *dest, uint16_t len)
{
    uint32_t USBx_BASE = (uint32_t)usbBase;
    uint8_t *pDest     = dest;
    uint32_t pData, i;
    uint32_t count32b        = (uint32_t)len >> 2U;
    uint16_t remaining_bytes = len % 4U;

    for (i = 0U; i < count32b; i++)
    {
        __UNALIGNED_UINT32_WRITE(pDest, USBx_DFIFO(0U));
        pDest++;
        pDest++;
        pDest++;
        pDest++;
    }

    /* When Number of data is not word aligned, read the remaining byte */
    if (remaining_bytes != 0U)
    {
        i = 0U;
        __UNALIGNED_UINT32_WRITE(&pData, USBx_DFIFO(0U));

        do
        {
            *(uint8_t *)pDest = (uint8_t)(pData >> (8U * (uint8_t)(i)));
            i++;
            pDest++;
            remaining_bytes--;
        } while (remaining_bytes != 0U);
    }

    return ((void *)pDest);
}

status_t USB_epSetStall(USB_Type *usbBase, USB_OTG_EPTypeDef_t *ep)
{
    uint32_t epnum = (uint32_t)ep->num;

    if (ep->isIn == 1U)
    {
        if ((USB_DIEPCTL_N_DIEP_CTL_N_EP_ENA_Get(usbBase->DIEP_GRPb[epnum].DIEPCTL_N) == 0U) && (epnum != 0U))
        {
            usbBase->DIEP_GRPb[epnum].DIEPCTL_N &= ~(USB_DIEPCTL_N_DIEP_CTL_N_EP_DIS_Set(1U));
        }
        usbBase->DIEP_GRPb[epnum].DIEPCTL_N |= USB_DIEPCTL_N_DIEP_CTL_N_STALL_Set(1U);
    }
    else
    {
        if ((USB_DOEPCTL_N_DOEP_CTL_N_EP_ENA_Get(usbBase->DOEP_GRPb[epnum].DOEPCTL_N) == 0U) && (epnum != 0U))
        {
            usbBase->DOEP_GRPb[epnum].DOEPCTL_N &= ~(USB_DOEPCTL_N_DOEP_CTL_N_EP_DIS_Set(1U));
        }
        usbBase->DOEP_GRPb[epnum].DOEPCTL_N |= USB_DOEPCTL_N_DOEP_CTL_N_STALL_Set(1U);
    }

    return kSTATUS_SUCCESS;
}

status_t USB_epClearStall(USB_Type *usbBase, USB_OTG_EPTypeDef_t *ep)
{
    uint32_t epnum = (uint32_t)ep->num;

    if (ep->isIn == 1U)
    {
        usbBase->DIEP_GRPb[epnum].DIEPCTL_N &= ~USB_DIEPCTL_N_DIEP_CTL_N_STALL_Set(1U);
        if ((ep->type == EP_TYPE_INTR) || (ep->type == EP_TYPE_BULK))
        {
            usbBase->DIEP_GRPb[epnum].DIEPCTL_N |= USB_DIEPCTL_N_DIEP_CTL_N_SET_D0PID_Set(1U); /* DATA0 */
        }
    }
    else
    {
        usbBase->DOEP_GRPb[epnum].DOEPCTL_N &= ~USB_DOEPCTL_N_DOEP_CTL_N_STALL_Set(1U);
        if ((ep->type == EP_TYPE_INTR) || (ep->type == EP_TYPE_BULK))
        {
            usbBase->DOEP_GRPb[epnum].DOEPCTL_N |= USB_DOEPCTL_N_DOEP_CTL_N_SET_D0PID_Set(1U); /* DATA0 */
        }
    }
    return kSTATUS_SUCCESS;
}

status_t USB_stopDevice(USB_Type *usbBase)
{
    status_t ret;

    /* Clear Pending interrupt */
    for (uint32_t i = 0U; i < 15U; i++)
    {
        usbBase->DIEP_GRPb[i].DIEPINT_N = 0xFB7FU;
        usbBase->DOEP_GRPb[i].DOEPINT_N = 0xFB7FU;
    }

    /* Clear interrupt masks */
    usbBase->DIEPMSK  = 0U;
    usbBase->DOEPMSK  = 0U;
    usbBase->DAINTMSK = 0U;

    /* Flush the FIFO */
    ret = USB_flushRxFifo(usbBase);
    if (ret != kSTATUS_SUCCESS)
    {
        return ret;
    }

    ret = USB_flushTxFifo(usbBase, 0x10U);
    if (ret != kSTATUS_SUCCESS)
    {
        return ret;
    }

    return ret;
}

status_t USB_setDevAddress(USB_Type *usbBase, uint8_t address)
{
    usbBase->DCFG &= ~(USB_DCFG_DCFG_DEV_ADDR_Set(0x7fU));
    usbBase->DCFG |= ((uint32_t)USB_DCFG_DCFG_DEV_ADDR_Set(address));

    return kSTATUS_SUCCESS;
}

status_t USB_devConnect(USB_Type *usbBase)
{
    /* In case phy is stopped, ensure to ungate and restore the phy CLK */
    usbBase->PCGCCTL &= ~(USB_PCGCCTL_STOP_PCLK_Set(1U) | USB_PCGCCTL_GATE_HCLK_Set(1U));

    usbBase->DCTL &= ~USB_DCTL_SFT_DISCON_Set(1U);

    return kSTATUS_SUCCESS;
}

status_t USB_devDisconnect(USB_Type *usbBase)
{
    /* In case phy is stopped, ensure to ungate and restore the phy CLK */
    usbBase->PCGCCTL &= ~(USB_PCGCCTL_STOP_PCLK_Set(1U) | USB_PCGCCTL_GATE_HCLK_Set(1U));

    usbBase->DCTL |= USB_DCTL_SFT_DISCON_Set(1U);

    return kSTATUS_SUCCESS;
}

uint32_t USB_readInterrupts(USB_Type *usbBase)
{
    uint32_t tmpReg;

    tmpReg  = usbBase->GINTSTS;
    tmpReg &= usbBase->GINTMSK;

    return tmpReg;
}

uint32_t USB_readDevAllOutEpInterrupt(USB_Type *usbBase)
{
    uint32_t tmpReg;

    tmpReg  = usbBase->DAINT;
    tmpReg &= usbBase->DAINTMSK;

    return ((tmpReg & 0xffff0000U) >> 16);
}

uint32_t USB_readDevAllInEpInterrupt(USB_Type *usbBase)
{
    uint32_t tmpReg;

    tmpReg  = usbBase->DAINT;
    tmpReg &= usbBase->DAINTMSK;

    return ((tmpReg & 0xFFFFU));
}

uint32_t USB_readDevOutEPInterrupt(USB_Type *usbBase, uint8_t epnum)
{
    uint32_t tmpReg;

    tmpReg  = usbBase->DOEP_GRPb[(uint32_t)epnum].DOEPINT_N;
    tmpReg &= usbBase->DOEPMSK;

    return tmpReg;
}

uint32_t USB_readDevInEPInterrupt(USB_Type *usbBase, uint8_t epnum)
{
    uint32_t tmpReg, msk, emp;

    msk     = usbBase->DIEPMSK;
    emp     = usbBase->DIEPEMPMSK;
    msk    |= ((emp >> (epnum & EP_ADDR_MSK)) & 0x1U) << 7;
    tmpReg  = usbBase->DIEP_GRPb[(uint32_t)epnum].DIEPINT_N & msk;

    return tmpReg;
}

void USB_clearInterrupts(USB_Type *usbBase, uint32_t interrupt)
{
    usbBase->GINTSTS |= interrupt;
}

uint32_t USB_getMode(USB_Type *usbBase)
{
    return ((usbBase->GINTSTS) & 0x1U);
}

status_t USB_activateSetup(USB_Type *usbBase)
{
    /* Set the MPS of the IN EP0 to 64 bytes */
    usbBase->DIEP_GRPb[0U].DIEPCTL_N &= ~USB_DIEPCTL_N_DIEP_CTL_N_MPS_Set(0x7ffU);

    usbBase->DCTL |= USB_DCTL_CGNP_IN_NAK_Set(1U);

    return kSTATUS_SUCCESS;
}

status_t USB_ep0OutStart(USB_Type *usbBase, uint8_t dma, uint8_t *psetup)
{
    uint32_t gSNPSiD = usbBase->GSNPSID;

    if (gSNPSiD > USB_OTG_CORE_ID_300A)
    {
        if (USB_DOEPCTL_N_DOEP_CTL_N_EP_ENA_Get(usbBase->DOEP_GRPb[0U].DOEPCTL_N))
        {
            return kSTATUS_SUCCESS;
        }
    }

    usbBase->DOEP_GRPb[0U].DOEPTSIZ_N  = 0U;
    usbBase->DOEP_GRPb[0U].DOEPTSIZ_N |= (USB_DOEPTSIZ_N_DOEP_TSIZ_N_PKT_CNT_Set(0x1U));
    usbBase->DOEP_GRPb[0U].DOEPTSIZ_N |= (3U * 8U);
    usbBase->DOEP_GRPb[0U].DOEPTSIZ_N |= USB_DOEPTSIZ_N_RX_DPID_Set(0x3U);

    if (dma == 1U)
    {
        usbBase->DOEP_GRPb[0U].DOEPDMA_N = (uint32_t)psetup;
        /* EP enable */
        usbBase->DOEP_GRPb[0U].DOEPCTL_N |=
            USB_DOEPCTL_N_DOEP_CTL_N_EP_ENA_Set(1U) | USB_DOEPCTL_N_DOEP_CTL_N_USB_ACT_EP_Set(1U);
    }

    return kSTATUS_SUCCESS;
}

static status_t USB_coreReset(USB_Type *usbBase)
{
    __IO uint32_t count = 0U;

    /* Wait for AHB master IDLE state. */
    do
    {
        count++;

        if (count > 200000U)
        {
            return kSTATUS_NOT_SUPPORTED;
        }
    } while (USB_GRSTCTL_AHB_IDLE_Get(usbBase->GRSTCTL) == 0U);

    /* Core Soft Reset */
    count             = 0U;
    usbBase->GRSTCTL |= USB_GRSTCTL_CSFT_RST_Set(1U);

    do
    {
        count++;

        if (count > 200000U)
        {
            return kSTATUS_NOT_SUPPORTED;
        }
    } while (USB_GRSTCTL_CSFT_RST_Get(usbBase->GRSTCTL));

    return kSTATUS_SUCCESS;
}

status_t USB_hostInit(USB_Type *usbBase, USB_OTG_CfgTypeDef_t cfg)
{
    status_t ret = kSTATUS_SUCCESS;

    /* Restart the Phy Clock */
    usbBase->PCGCCTL = 0U;

    /* Set default Max speed support */
    usbBase->HCFG &= ~(USB_HCFG_FS_LSSUPP_Set(1U));

    /* Make sure the FIFOs are flushed. */
    if (USB_flushTxFifo(usbBase, 0x10U) != kSTATUS_SUCCESS) /* all Tx FIFOs */
    {
        ret = kSTATUS_FAIL;
    }

    if (USB_flushRxFifo(usbBase) != kSTATUS_SUCCESS)
    {
        ret = kSTATUS_FAIL;
    }

    /* Clear all pending HC Interrupts */
    for (uint32_t i = 0U; i < cfg.hostChannels; i++)
    {
        usbBase->HC_GRPb[i].HCINT_N    = 0xFFFFFFFFU;
        usbBase->HC_GRPb[i].HCINTMSK_N = 0U;
    }

    /* Disable all interrupts. */
    usbBase->GINTMSK = 0U;

    /* Clear any pending interrupts */
    usbBase->GINTSTS = 0xFFFFFFFFU;

    /* set Rx FIFO size */
    usbBase->GRXFSIZ   = 0x80U;
    usbBase->GNPTXFSIZ = (uint32_t)((USB_GNPTXFSIZ_NP_TXF_DEP_Set(0x60U)) | 0x80U);
    usbBase->HPTXFSIZ  = (uint32_t)((USB_HPTXFSIZ_PTXF_SIZE_Set(0x40U)) | 0xE0U);

    /* Enable the common interrupts */
    if (cfg.dmaEnable == 0U)
    {
        usbBase->GINTMSK |= USB_GINTMSK_RXF_LVL_MSK_Set(1U);
    }

    /* Enable interrupts matching to the Host mode ONLY */
    usbBase->GINTMSK |=
        (USB_GINTMSK_PRT_INT_MSK_Set(1U) | USB_GINTMSK_HCH_INT_MSK_Set(1U) | USB_GINTMSK_SOF_MSK_Set(1U) |
         USB_GINTMSK_DISCONN_INT_MSK_Set(1U) | USB_GINTMSK_INCOMPL_PMS_K_Set(1U) | USB_GINTMSK_WK_UP_INT_MSK_Set(1U));

    return ret;
}

status_t USB_initFSLSPClkSel(USB_Type *usbBase, uint8_t freq)
{
    usbBase->HCFG &= ~(USB_HCFG_FS_LSPCLK_SEL_Set(0x3U));
    usbBase->HCFG |= (uint32_t)freq & USB_HCFG_FS_LSPCLK_SEL_Set(0x3U);

    if (freq == HCFG_48_MHZ)
    {
        usbBase->HFIR = 48000U;
    }
    else if (freq == HCFG_6_MHZ)
    {
        usbBase->HFIR = 6000U;
    }
    else
    {
        /* ... */
    }

    return kSTATUS_SUCCESS;
}

status_t USB_resetPort(USB_Type *usbBase)
{
    __IO uint32_t hprtReg = 0U;

    hprtReg = usbBase->HPRT;

    hprtReg &= ~(USB_HPRT_PRT_ENA_Set(1U) | USB_HPRT_PRT_CONN_DET_Set(1U) | USB_HPRT_PRT_EN_CHNG_Set(1U) |
                 USB_HPRT_PRT_OVR_CURR_CHNG_Set(1U));

    usbBase->HPRT = (USB_HPRT_PRT_RST_Set(1U) | hprtReg);
    DELAY(100 * 1000U); /* See Note #1 */
    usbBase->HPRT = ((~USB_HPRT_PRT_RST_Set(1U)) & hprtReg);
    DELAY(10 * 1000U);

    return kSTATUS_SUCCESS;
}

status_t USB_driveVbus(USB_Type *usbBase, uint8_t state)
{
    __IO uint32_t hprtReg = 0U;

    hprtReg = usbBase->HPRT;

    hprtReg &= ~(USB_HPRT_PRT_ENA_Set(1U) | USB_HPRT_PRT_CONN_DET_Set(1U) | USB_HPRT_PRT_EN_CHNG_Set(1U) |
                 USB_HPRT_PRT_OVR_CURR_CHNG_Set(1U));

    if ((USB_HPRT_PRT_PWR_Get(hprtReg) == 0U) && (state == 1U))
    {
        usbBase->HPRT = (USB_HPRT_PRT_PWR_Set(1U) | hprtReg);
    }
    if ((USB_HPRT_PRT_PWR_Get(hprtReg)) && (state == 0U))
    {
        usbBase->HPRT = ((~USB_HPRT_PRT_PWR_Set(1U)) & hprtReg);
    }
    return kSTATUS_SUCCESS;
}

uint32_t USB_getHostSpeed(USB_Type *usbBase)
{
    return (USB_HPRT_PRT_SPD_Get(usbBase->HPRT));
}

uint32_t USB_getCurrentFrame(USB_Type *usbBase)
{
    return (USB_HFNUM_FR_NUM_Get(usbBase->HFNUM));
}

status_t USB_hostChannelInit(USB_Type *usbBase, uint8_t channelNum, uint8_t epnum, uint8_t dev_address, uint8_t speed,
                             uint8_t ep_type, uint16_t mps)
{
    status_t ret = kSTATUS_SUCCESS;
    uint32_t hostCharEpDir, hostCharLowSpeed, hostCoreSpeed;

    /* Clear old interrupt conditions for this host channel. */
    usbBase->HC_GRPb[(uint32_t)channelNum].HCINT_N = 0xFFFFFFFFU;

    /* Enable channel interrupts required for this transfer. */
    switch (ep_type)
    {
        case EP_TYPE_CTRL:
        case EP_TYPE_BULK:
            usbBase->HC_GRPb[(uint32_t)channelNum].HCINTMSK_N =
                USB_HCINTMSK_N_HCIN_TMSK_N_XFER_COMPL_MSK_Set(1U) | USB_HCINTMSK_N_STALLM_Set(1U) |
                USB_HCINTMSK_N_TXERRM_Set(1U) | USB_HCINTMSK_N_DTERRM_Set(1U) |
                USB_HCINTMSK_N_HCIN_TMSK_N_AHB_ERR_MSK_Set(1U) | USB_HCINTMSK_N_NAKM_Set(1U);

            if ((epnum & 0x80U) == 0x80U)
            {
                usbBase->HC_GRPb[(uint32_t)channelNum].HCINTMSK_N |= USB_HCINTMSK_N_BBERRM_Set(1U);
            }
            break;

        case EP_TYPE_INTR:
            usbBase->HC_GRPb[(uint32_t)channelNum].HCINTMSK_N =
                USB_HCINTMSK_N_HCIN_TMSK_N_XFER_COMPL_MSK_Set(1U) | USB_HCINTMSK_N_STALLM_Set(1U) |
                USB_HCINTMSK_N_TXERRM_Set(1U) | USB_HCINTMSK_N_DTERRM_Set(1U) | USB_HCINTMSK_N_NAKM_Set(1U) |
                USB_HCINTMSK_N_HCIN_TMSK_N_AHB_ERR_MSK_Set(1U) | USB_HCINTMSK_N_FRMORM_Set(1U);

            if ((epnum & 0x80U) == 0x80U)
            {
                usbBase->HC_GRPb[(uint32_t)channelNum].HCINTMSK_N |= USB_HCINTMSK_N_BBERRM_Set(1U);
            }

            break;

        case EP_TYPE_ISOC:
            usbBase->HC_GRPb[(uint32_t)channelNum].HCINTMSK_N =
                USB_HCINTMSK_N_HCIN_TMSK_N_XFER_COMPL_MSK_Set(1U) | USB_HCINTMSK_N_ACKM_Set(1U) |
                USB_HCINTMSK_N_HCIN_TMSK_N_AHB_ERR_MSK_Set(1U) | USB_HCINTMSK_N_FRMORM_Set(1U);

            if ((epnum & 0x80U) == 0x80U)
            {
                usbBase->HC_GRPb[(uint32_t)channelNum].HCINTMSK_N |=
                    (USB_HCINTMSK_N_TXERRM_Set(1U) | USB_HCINTMSK_N_BBERRM_Set(1U));
            }
            break;
    }

    /* Enable host channel Halt interrupt */
    usbBase->HC_GRPb[(uint32_t)channelNum].HCINTMSK_N |= USB_HCINTMSK_N_CH_HLTD_MSK_Set(1U);

    /* Enable the top level host channel interrupt. */
    usbBase->HAINTMSK |= 1UL << (channelNum & 0xFU);

    /* Make sure host channel interrupts are enabled. */
    usbBase->GINTMSK |= USB_GINTMSK_HCH_INT_MSK_Set(1U);

    /* Program the HCCHAR register */
    if ((epnum & 0x80U) == 0x80U)
    {
        hostCharEpDir = USB_HCCHAR_N_HCCHAR_N_EP_DIR_Set(1U);
    }
    else
    {
        hostCharEpDir = 0U;
    }

    hostCoreSpeed = USB_getHostSpeed(usbBase);

    /* LS device plugged to HUB */
    if ((speed == HPRT0_PRTSPD_LOW_SPEED) && (hostCoreSpeed != HPRT0_PRTSPD_LOW_SPEED))
    {
        hostCharLowSpeed = (0x1U << 17) & USB_HCCHAR_N_LSPD_DEV_Set(1U);
    }
    else
    {
        hostCharLowSpeed = 0U;
    }

    usbBase->HC_GRPb[(uint32_t)channelNum].HCCHAR_N =
        (USB_HCCHAR_N_HCCHAR_N_DEV_ADDR_Set((uint32_t)dev_address)) |
        (USB_HCCHAR_N_EP_NUM_Set(((uint32_t)epnum & 0x7FU))) | (USB_HCCHAR_N_EP_TYPE_Set((uint32_t)ep_type)) |
        ((uint32_t)mps & USB_HCCHAR_N_MPS_Msk) | hostCharEpDir | hostCharLowSpeed;

    if ((ep_type == EP_TYPE_INTR) || (ep_type == EP_TYPE_ISOC))
    {
        usbBase->HC_GRPb[(uint32_t)channelNum].HCCHAR_N |= USB_HCCHAR_N_ODD_FRM_Set(1U);
    }

    return ret;
}

status_t USB_hostChannelStartXfer(USB_Type *usbBase, USB_OTG_HCTypeDef_t *hc, uint8_t dma)
{
    uint32_t      channelNum = (uint32_t)hc->channelNum;
    __IO uint32_t tmpReg;
    uint8_t       isOddFrame;
    uint16_t      lenWords, numPackets;
    uint16_t      maxHcPktCount = 256U;

    /* Compute the expected number of packets associated to the transfer */
    if (hc->xferLen > 0U)
    {
        numPackets = (uint16_t)((hc->xferLen + hc->maxPacket - 1U) / hc->maxPacket);

        if (numPackets > maxHcPktCount)
        {
            numPackets   = maxHcPktCount;
            hc->xferSize = (uint32_t)numPackets * hc->maxPacket;
        }
    }
    else
    {
        numPackets = 1U;
    }

    /*
     * For IN channel HCTSIZ.xferSize is expected to be an integer multiple of
     * maxPacket size.
     */
    if (hc->epIsIn != 0U)
    {
        hc->xferSize = (uint32_t)numPackets * hc->maxPacket;
    }
    else
    {
        hc->xferSize = hc->xferLen;
    }

    /* Initialize the HCTSIZn register */
    usbBase->HC_GRPb[channelNum].HCTSIZ_N = (USB_HCTSIZ_N_HCTSIZ_N_XFER_SIZE_Set(hc->xferSize)) |
                                            (USB_HCTSIZ_N_HCTSIZ_N_PKT_CNT_Set((uint32_t)numPackets)) |
                                            (USB_HCTSIZ_N_PID_Set((uint32_t)hc->dataPid));

    if (dma != 0U)
    {
        /* xferBuff MUST be 32-bits aligned */
        usbBase->HC_GRPb[channelNum].HCDMA_N = (uint32_t)hc->xferBuff;
    }

    isOddFrame                             = (((uint32_t)usbBase->HFNUM & 0x01U) != 0U) ? 0U : 1U;
    usbBase->HC_GRPb[channelNum].HCCHAR_N &= ~USB_HCCHAR_N_ODD_FRM_Set(1U);
    usbBase->HC_GRPb[channelNum].HCCHAR_N |= (uint32_t)isOddFrame << 29;

    /* Set host channel enable */
    tmpReg  = usbBase->HC_GRPb[channelNum].HCCHAR_N;
    tmpReg &= ~USB_HCCHAR_N_CH_DIS_Set(1U);

    /* make sure to set the correct ep direction */
    if (hc->epIsIn != 0U)
    {
        tmpReg |= USB_HCCHAR_N_HCCHAR_N_EP_DIR_Set(1U);
    }
    else
    {
        tmpReg &= ~USB_HCCHAR_N_HCCHAR_N_EP_DIR_Set(1U);
    }
    tmpReg                                |= USB_HCCHAR_N_CH_ENA_Set(1U);
    usbBase->HC_GRPb[channelNum].HCCHAR_N  = tmpReg;

    if (dma != 0U) /* dma mode */
    {
        return kSTATUS_SUCCESS;
    }

    if ((hc->epIsIn == 0U) && (hc->xferLen > 0U))
    {
        switch (hc->epType)
        {
            /* Non periodic transfer */
            case EP_TYPE_CTRL:
            case EP_TYPE_BULK:

                lenWords = (uint16_t)((hc->xferLen + 3U) / 4U);

                /* check if there is enough space in FIFO space */
                if (lenWords > (usbBase->GNPTXSTS & 0xFFFFU))
                {
                    /* need to process data in nptxfempty interrupt */
                    usbBase->GINTMSK |= USB_GINTMSK_NP_TXF_EMP_MSK_Set(1U);
                }
                break;

            /* Periodic transfer */
            case EP_TYPE_INTR:
            case EP_TYPE_ISOC:
                lenWords = (uint16_t)((hc->xferLen + 3U) / 4U);
                /* check if there is enough space in FIFO space */
                if (lenWords > (usbBase->HPTXSTS & 0xFFFFU)) /* split the transfer */
                {
                    /* need to process data in ptxfempty interrupt */
                    usbBase->GINTMSK |= USB_GINTMSK_PTXF_EMP_MSK_Set(1U);
                }
                break;

            default:
                break;
        }

        /* Write packet into the Tx FIFO. */
        (void)USB_writePacket(usbBase, hc->xferBuff, hc->channelNum, (uint16_t)hc->xferLen, 0);
    }

    return kSTATUS_SUCCESS;
}

uint32_t USB_hostChannelReadInterrupt(USB_Type *usbBase)
{
    return ((usbBase->HAINT) & 0xFFFFU);
}

status_t USB_hostChannelHalt(USB_Type *usbBase, uint8_t hc_num)
{
    uint32_t      hcnum      = (uint32_t)hc_num;
    __IO uint32_t count      = 0U;
    uint32_t      hcEpType   = USB_HCCHAR_N_EP_TYPE_Get(usbBase->HC_GRPb[hcnum].HCCHAR_N);
    uint32_t      channelEna = USB_HCCHAR_N_CH_ENA_Get(usbBase->HC_GRPb[hcnum].HCCHAR_N);

    if ((USB_GAHBCFG_DMA_EN_Get(usbBase->GAHBCFG)) && (channelEna == 0U))
    {
        return kSTATUS_SUCCESS;
    }

    /* Check for space in the request queue to issue the halt. */
    if ((hcEpType == HCCHAR_CTRL) || (hcEpType == HCCHAR_BULK))
    {
        usbBase->HC_GRPb[hcnum].HCCHAR_N |= USB_HCCHAR_N_CH_DIS_Set(1U);

        if (USB_GAHBCFG_DMA_EN_Get(usbBase->GAHBCFG) == 0U)
        {
            if ((usbBase->GNPTXSTS & (0xFFU << 16)) == 0U)
            {
                usbBase->HC_GRPb[hcnum].HCCHAR_N &= ~USB_HCCHAR_N_CH_ENA_Set(1U);
                usbBase->HC_GRPb[hcnum].HCCHAR_N |= USB_HCCHAR_N_CH_ENA_Set(1U);
                do
                {
                    count++;

                    if (count > 1000U)
                    {
                        break;
                    }
                } while (USB_HCCHAR_N_CH_ENA_Get(usbBase->HC_GRPb[hcnum].HCCHAR_N));
            }
            else
            {
                usbBase->HC_GRPb[hcnum].HCCHAR_N |= USB_HCCHAR_N_CH_ENA_Set(1U);
            }
        }
    }
    else
    {
        usbBase->HC_GRPb[hcnum].HCCHAR_N |= USB_HCCHAR_N_CH_DIS_Set(1U);

        if ((usbBase->HPTXSTS & (0xFFU << 16)) == 0U)
        {
            usbBase->HC_GRPb[hcnum].HCCHAR_N &= ~USB_HCCHAR_N_CH_ENA_Set(1U);
            usbBase->HC_GRPb[hcnum].HCCHAR_N |= USB_HCCHAR_N_CH_ENA_Set(1U);
            do
            {
                count++;

                if (count > 1000U)
                {
                    break;
                }
            } while (USB_HCCHAR_N_CH_ENA_Get(usbBase->HC_GRPb[hcnum].HCCHAR_N));
        }
        else
        {
            usbBase->HC_GRPb[hcnum].HCCHAR_N |= USB_HCCHAR_N_CH_ENA_Set(1U);
        }
    }

    return kSTATUS_SUCCESS;
}

status_t USB_doPing(USB_Type *usbBase, uint8_t channelNum)
{
    uint32_t chnum      = (uint32_t)channelNum;
    uint32_t numPackets = 1U;
    uint32_t tmpReg;

    usbBase->HC_GRPb[chnum].HCTSIZ_N = (USB_HCTSIZ_N_HCTSIZ_N_PKT_CNT_Set(numPackets)) | USB_HCTSIZ_N_DO_PNG_Set(1U);

    /* Set host channel enable */
    tmpReg                            = usbBase->HC_GRPb[chnum].HCCHAR_N;
    tmpReg                           &= ~USB_HCCHAR_N_CH_DIS_Set(1U);
    tmpReg                           |= USB_HCCHAR_N_CH_ENA_Set(1U);
    usbBase->HC_GRPb[chnum].HCCHAR_N  = tmpReg;

    return kSTATUS_SUCCESS;
}

status_t USB_stopHost(USB_Type *usbBase)
{
    status_t      ret   = kSTATUS_SUCCESS;
    __IO uint32_t count = 0U;
    uint32_t      value;

    (void)USB_disableGlobalInt(usbBase);

    /* Flush USB FIFO */
    if (USB_flushTxFifo(usbBase, 0x10U) != kSTATUS_SUCCESS) /* all Tx FIFOs */
    {
        ret = kSTATUS_FAIL;
    }

    if (USB_flushRxFifo(usbBase) != kSTATUS_SUCCESS)
    {
        ret = kSTATUS_FAIL;
    }

    /* Flush out any leftover queued requests. */
    for (uint32_t i = 0U; i <= 15U; i++)
    {
        value                         = usbBase->HC_GRPb[i].HCCHAR_N;
        value                        |= USB_HCCHAR_N_CH_DIS_Set(1U);
        value                        &= ~USB_HCCHAR_N_CH_ENA_Set(1U);
        value                        &= ~USB_HCCHAR_N_HCCHAR_N_EP_DIR_Set(1U);
        usbBase->HC_GRPb[i].HCCHAR_N  = value;
    }

    /* Halt all channels to put them into a known state. */
    for (uint32_t i = 0U; i <= 15U; i++)
    {
        value                         = usbBase->HC_GRPb[i].HCCHAR_N;
        value                        |= USB_HCCHAR_N_CH_DIS_Set(1U);
        value                        |= USB_HCCHAR_N_CH_ENA_Set(1U);
        value                        &= ~USB_HCCHAR_N_HCCHAR_N_EP_DIR_Set(1U);
        usbBase->HC_GRPb[i].HCCHAR_N  = value;

        do
        {
            count++;

            if (count > 1000U)
            {
                break;
            }
        } while (USB_HCCHAR_N_CH_ENA_Get(usbBase->HC_GRPb[i].HCCHAR_N));
    }

    /* Clear any pending Host interrupts */
    usbBase->HAINT   = 0xFFFFFFFFU;
    usbBase->GINTSTS = 0xFFFFFFFFU;

    (void)USB_enableGlobalInt(usbBase);

    return ret;
}

status_t USB_activateRemoteWakeup(USB_Type *usbBase)
{
    if (USB_DSTS_SUSP_STS_Get(usbBase->DSTS))
    {
        /* active Remote wakeup signalling */
        usbBase->DCTL |= USB_DCTL_RMT_WK_UP_SIG_Set(1U);
    }

    return kSTATUS_SUCCESS;
}

status_t USB_deactivateRemoteWakeup(USB_Type *usbBase)
{
    /* active Remote wakeup signalling */
    usbBase->DCTL &= ~(USB_DCTL_RMT_WK_UP_SIG_Set(1U));

    return kSTATUS_SUCCESS;
}
