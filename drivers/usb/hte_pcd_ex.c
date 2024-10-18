/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_pcd_ex.c
 * \brief SDK USB peripheral control extended driver source file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_pcd_ex.h"
#include "hte_ll_usb.h"
#include "hte_pcd.h"

/*******************************************************************************
 * Codes
 ******************************************************************************/
status_t PCDEx_setTxFiFo(PCD_HandleTypeDef_t *hpcd, uint8_t fifo, uint16_t size)
{
    uint32_t txOffset;

    /*  TXn min size = 16 words. (n  : Transmit FIFO index)
        When a TxFIFO is not used, the Configuration should be as follows:
            case 1 :  n > m    and Txn is not used    (n,m  : Transmit FIFO indexes)
           --> Txm can use the space allocated for Txn.
           case2  :  n < m    and Txn is not used    (n,m  : Transmit FIFO indexes)
           --> Txn should be configured with the minimum space of 16 words
       The FIFO is used optimally when used TxFIFOs are allocated in the top
           of the FIFO.Ex: use EP1 and EP2 as IN instead of EP1 and EP3 as IN ones.
       When DMA is used 3n * FIFO locations should be reserved for internal DMA registers */

    txOffset = hpcd->instance->GRXFSIZ;

    if (fifo == 0U)
    {
        hpcd->instance->GNPTXFSIZ = ((uint32_t)size << 16) | txOffset;
    }
    else
    {
        txOffset += (hpcd->instance->GNPTXFSIZ) >> 16;
        for (uint8_t i = 0U; i < (fifo - 1U); i++)
        {
            txOffset += (hpcd->instance->DIEPTXF_N[i] >> 16);
        }

        /* Multiply Tx_Size by 2 to get higher performance */
        hpcd->instance->DIEPTXF_N[fifo - 1U] = ((uint32_t)size << 16) | txOffset;
    }

    return kSTATUS_SUCCESS;
}

status_t PCDEx_setRxFiFo(PCD_HandleTypeDef_t *hpcd, uint16_t size)
{
    hpcd->instance->GRXFSIZ = size;

    return kSTATUS_SUCCESS;
}

status_t PCDEx_activateLPM(PCD_HandleTypeDef_t *hpcd)
{
    hpcd->lpmActive = 1U;
    hpcd->lpmState  = kLPM_L0;

    return kSTATUS_SUCCESS;
}

status_t PCDEx_deActivateLPM(PCD_HandleTypeDef_t *hpcd)
{
    hpcd->lpmActive = 0U;

    return kSTATUS_SUCCESS;
}

void PCDEx_BCD_vbusDetect(PCD_HandleTypeDef_t *hpcd) {}

status_t PCDEx_activateBCD(PCD_HandleTypeDef_t *hpcd)
{
    hpcd->batteryChargingActive = 1U;

    return kSTATUS_SUCCESS;
}

status_t PCDEx_deactivateBCD(PCD_HandleTypeDef_t *hpcd)
{
    hpcd->batteryChargingActive = 0U;

    return kSTATUS_SUCCESS;
}

__WEAK void PCDEx_LPM_callback(PCD_HandleTypeDef_t *hpcd, PCD_LPM_MsgTypeDef_t msg)
{
    /* Prevent unused argument(s) compilation warning */
    USB_UNUSED(hpcd);
    USB_UNUSED(msg);

    /* NOTE : This function should not be modified, when the callback is needed,
              the PCDEx_LPM_callback could be implemented in the user file
     */
}

__WEAK void PCDEx_BCD_callback(PCD_HandleTypeDef_t *hpcd, PCD_BCD_MsgTypeDef_t msg)
{
    /* Prevent unused argument(s) compilation warning */
    USB_UNUSED(hpcd);
    USB_UNUSED(msg);

    /* NOTE : This function should not be modified, when the callback is needed,
              the PCDEx_BCD_callback could be implemented in the user file
     */
}
