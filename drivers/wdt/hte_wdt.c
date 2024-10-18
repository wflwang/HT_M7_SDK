/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_wdt.c
 * \brief SDK WDT driver source file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_wdt.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* No Definitions */


/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/* No Prototypes */

/*******************************************************************************
 * Variables
 ******************************************************************************/
/* No Variables */

/*******************************************************************************
 * Codes
 ******************************************************************************/

void WDT_init(WDT_Cfg_t *wdtCfg)
{  
    WDT->CR &= ~ WDT_CR_WDT_EN_Set(1U);//disable wdt

    if(wdtCfg->setEnable == WDT_DISABLE)
    {
        WDT->CR &= ~WDT_CR_WDT_EN_Pos;//enable wdt
        return;
    }
    //set reset pluse len
    WDT->CR &= ~WDT_CR_RPL_Msk;
    WDT->CR |= WDT_CR_RPL_Set(wdtCfg->rstPulseLen);

    //timeout period
    WDT->TORR = (wdtCfg->toPeriod << 4) |wdtCfg->toPeriod;

    
    WDT->CR &= ~WDT_CR_RMOD_Msk;
    if(wdtCfg->rmod == INT_RMOD)
    {
        WDT->CR |= WDT_CR_RMOD_Set(WDT_RUN_INT_MODE);
        NVIC_SetPriority(WDT_IRQn, WDT_INT_PRIORITY);
        NVIC_EnableIRQ(WDT_IRQn);        
    }
    else
    {
        WDT->CR |= WDT_CR_RMOD_Set(WDT_RUN_NORMAL_MODE);
        NVIC_DisableIRQ(WDT_IRQn);   
    }

    WDT->CR |= WDT_CR_WDT_EN_Set(1U);//enable wdt
    //must reset first time after enable!!!
    WDT->CRR = WDT_RSTART_CNT; 
    
    return;
}

bool WDT_getEnable(void)
{
    bool wdt_status;

    wdt_status = WDT_CR_WDT_EN_Get(WDT->CR);
        
    return wdt_status;
}

void WDT_rstCnt(void)
{        
    WDT->CRR = WDT_RSTART_CNT;    
    return;
}


uint32_t WDT_getCurCnt(void)
{
    uint32_t cnt = 0;
    cnt = WDT->CCVR;

    return cnt;
}

uint32_t WDT_getIntStatus(void)
{
    uint32_t status = 0;
    status          = WDT->STAT;

    return status;
}

void WDT_clearIntPending(void)
{
    WDT->EOI;
}

void WDT_powerUpInit(void)
{
    WDT_Cfg_t wdtIntCfg = {WDT_DISABLE, WDT_RPL_256PCLKS, WDT_PERIOD_25MS, NORMAL_RMOD};  
    WDT_init(&wdtIntCfg);
}

