/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_wdt.h
 * \brief SDK WDT driver header file
 * \version 1.0.0
 */
#ifndef HTE_WDT_H
#define HTE_WDT_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_common.h"

/*!
 * \addtogroup DRV_HTE_WDT WDT Driver
 *
 * \brief SDK WDT driver
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! \brief index for wdt restart */
#define WDT_RSTART_CNT 0x76
/*! \brief define for wdt run mode */
#define WDT_RUN_INT_MODE        1
/*! \brief define for wdt normal mode */
#define WDT_RUN_NORMAL_MODE     0
/*! \brief define for wdt int priority */
#define WDT_INT_PRIORITY  3

/*! \brief index for wdt rpl cnt */
typedef enum
{
    WDT_RPL_2PCLKS = 0, /*!< wdt rpl for 2 clks */
    WDT_RPL_4PCLK,      /*!< wdt rpl for 4 clks */
    WDT_RPL_8PCLKS,     /*!< wdt rpl for 8 clks */
    WDT_RPL_16PCLKS,    /*!< wdt rpl for 16 clks */
    WDT_RPL_32PCLKS,    /*!< wdt rpl for 32 clks */
    WDT_RPL_64PCLKS,    /*!< wdt rpl for 64 clks */
    WDT_RPL_128PCLKS,   /*!< wdt rpl for 128 clks */
    WDT_RPL_256PCLKS,   /*!< wdt rpl for 256 clks */
    WDT_RPL_NULL,       /*!< wdt rpl null */
}WDT_Rpl_t;


/*root pclk=50Mhz*/
/*
typedef enum
{
    WDT_PERIOD_1_3MS = 0, 		    //1.3MS
    WDT_PERIOD_2_5MS,           	//2.6MS
    WDT_PERIOD_5MS,             	//5MS
    WDT_PERIOD_10MS,            	//10MS
    WDT_PERIOD_20MS,           	    //20MS
    WDT_PERIOD_40MS,            	//40MS
    WDT_PERIOD_80MS,            	//80MS
    WDT_PERIOD_160MS,          	    //160MS
    WDT_PERIOD_320MS,          	    //320MS
    WDT_PERIOD_640MS,    		    //640MS
    WDT_PERIOD_1_3SEC,        	    //1.3SEC
    WDT_PERIOD_2_5SEC,              //2.5SEC
    WDT_PERIOD_5SEC,                //5SEC
    WDT_PERIOD_10SEC,         	    //10SEC
    WDT_PERIOD_20SEC,               //20SEC
    WDT_PERIOD_41SEC,      		    //41SEC
    WDT_PERIOD_NULL,
}wdt_top_t;
*/

/*! \brief index for wdt torr cnt */
//root pclk=10Mhz, but sysctrl wdt clk div 512!!!!!
typedef enum
{
    WDT_PERIOD_6_5MS = 0, /*!< wdt period for 6.5ms */
    WDT_PERIOD_13MS,      /*!< wdt period for 13ms */
    WDT_PERIOD_25MS,      /*!< wdt period for 25ms */
    WDT_PERIOD_50MS,      /*!< wdt period for 50ms */
    WDT_PERIOD_100MS,     /*!< wdt period for 100ms */
    WDT_PERIOD_200MS,     /*!< wdt period for 200ms */
    WDT_PERIOD_400MS,     /*!< wdt period for 400ms */
    WDT_PERIOD_800MS,     /*!< wdt period for 800ms */
    WDT_PERIOD_1_6SEC,    /*!< wdt period for 1.6s */
    WDT_PERIOD_3_2SEC,    /*!< wdt period for 3.2s */
    WDT_PERIOD_6_5SEC,    /*!< wdt period for 6.5s */
    WDT_PERIOD_12_5SEC,   /*!< wdt period for 12.5s */
    WDT_PERIOD_25SEC,     /*!< wdt period for 25s */
    WDT_PERIOD_50SEC,     /*!< wdt period for 50s */
    WDT_PERIOD_100SEC,    /*!< wdt period for 100s */
    WDT_PERIOD_200SEC,    /*!< wdt period for 200s */
    WDT_PERIOD_NULL,      /*!< wdt period null */
}WDT_Ttop_t;

/*! \brief index for wdt mode */
typedef enum
{
    NORMAL_RMOD = 0, /*!< wdt normal rmode */
    INT_RMOD,        /*!< dt int rmode */
}WDT_Rmod_t;

/*! \brief index for wdt enable */
typedef enum
{
    WDT_DISABLE = 0, /*!< wdt disable */
    WDT_ENABLE,      /*!< wdt enable */
}WDT_Enable_t;

/*! \brief struct for wdt coonfig */
typedef struct
{
    WDT_Enable_t setEnable;   /*!< wdt enable var */
    WDT_Rpl_t    rstPulseLen; /*!< wdt reset pulse len var */
    WDT_Ttop_t   toPeriod;    /*!< wdt period var */
    WDT_Rmod_t   rmod;        /*!< romd 0:generate sys rst   1:fisrt generate int */
}WDT_Cfg_t;

/*******************************************************************************
 * APIs
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Init a wdt.
 *
 * \details This function config the wdt.
 *
 * \param[in] wdtCfg the wdt configuration
 *
 */
extern void WDT_init(WDT_Cfg_t *wdtCfg);

/*!
 * \brief get wdt enable.
 *
 * \details This function get wdt enable or not.
 *
 * \return Returns wdt enable flag
 *
 */
extern bool WDT_getEnable(void);

/*!
 * \brief restart the wdt cnt.
 *
 * \details This function restart the wdt cnt, fit the dog
 *
 *
 */
extern void WDT_rstCnt(void);

/*!
 * \brief get current wdt cnt.
 *
 * \details This functionget current wdt cnt.
 *
 * \return Returns wdt cnt value
 *
 */
extern uint32_t WDT_getCurCnt(void);

/*!
 * \brief get wdt int status.
 *
 * \details This function get int status.
 *
 * \return Returns wdt status value
 *
 */
extern uint32_t WDT_getIntStatus(void);

/*!
 * \brief clean wdt int status.
 *
 * \details This function clean wdt int status.
 *
 *
 */
extern void WDT_clearIntPending(void);


/*!
 * \brief power up wdt init.
 *
 * \details This function is a example init wdt when power up.
 */
extern void WDT_powerUpInit(void);

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */ /* end of DRV_HTE_WDT */

#endif /* HTE_WDT_H */
