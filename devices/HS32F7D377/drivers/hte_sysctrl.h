/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_sysctrl.h
 * \brief HS32F7D377 SYSCTRL driver header file
 * \version 1.0.0
 */

#ifndef HTE_SYSCTRL_H
#define HTE_SYSCTRL_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_common.h"

/*!
 * \addtogroup DRV_HS32F7D377_SYSCTRL HS32F7D377 SYSCTRL Driver
 *
 * \brief HS32F7D377 SYSCTRL driver
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#if defined(HTE_DEVICE_HS32F7D377_CPU1)
/*! \brief CPU2 RESET handle flag */
#define CPU2_RESET_CLEAN (0xA5A50000) /*!< Define reset clean value */
#define CPU2_RESET_HOLD  (0xA5A50001) /*!< Define reset hold value */
#endif

/*! \brief softres reg offset */
#define SYSC_SOFTPRES0_OFFSET (0x0104U)
/*! \brief cpusel reg offset */
#define SYSC_CPUSEL0_OFFSET (0x01ACU)
/*! \brief pclkcr reg offset */
#define SYSC_PCLKCR0_OFFSET (0x0044U)
/*! \brief clk cfg reg offset */
#define SYSC_CLKSRCCTL1_OFFSET (0x0010U)

/*! \brief Values to help decode peripheral parameter */
#define SYSCTL_PERIPH_REG_M (0x001FU) /*!< Define periph reg mask value */
#define SYSCTL_PERIPH_REG_S (0x0002U) /*!< Define periph reg shift value */
#define SYSCTL_PERIPH_BIT_M (0x1F00U) /*!< Define periph bit mask value */
#define SYSCTL_PERIPH_BIT_S (0x0008U) /*!< Define periph bit shift value */

#define SYSCTL_CLKSEM_KEY (0xA5A50000U) /*!< Define clock sem key value */


/*! \brief Default internal oscillator frequency, 10 MHz */
#define SYSCTL_DEFAULT_OSC_FREQ 10000000U /*!< Define internal oscillator frequency */


/*! \brief enable for sysctrl */
typedef enum
{
    kSYSC_DISABLE = 0, /*!< Type disable */
    kSYSC_ENABLE  = 1, /*!< Type enable */
} SYSCTRL_En_t;

/*! \brief WDT clk div definition */
typedef enum
{
    kWDT_IOSC_DIV_512_1 = 0, /*!< WDT CLK multiply 1 */
    kWDT_IOSC_DIV_512X1,     /*!< WDT CLK multiply 1 */
    kWDT_IOSC_DIV_512X2 = 2, /*!< WDT CLK multiply 2 */
    kWDT_IOSC_DIV_512X4,     /*!< WDT CLK multiply 4 */
    kWDT_IOSC_DIV_512X8,     /*!< WDT CLK multiply 8 */
    kWDT_IOSC_DIV_512X16,    /*!< WDT CLK multiply 16 */
    kWDT_IOSC_DIV_512X32,    /*!< WDT CLK multiply 32 */
    kWDT_IOSC_DIV_512X64     /*!< WDT CLK multiply 64 */
} SYSCTRL_Wdps_t;

/*! \brief NMI FLAG definition */
typedef enum
{
    kNMI_INT = 0,             /*!< NMI INT occur */
    kNMI_CLOCK_FAIL,          /*!< NMI INT clock fail */
    kNMI_RAM_UNCORRECT_ERR,   /*!< NMI INT ram unerr */
    kNMI_FLASH_UNCORRECT_ERR, /*!< NMI INT flash unerr */
    kNMI_CLB = 8,             /*!< NMI INT clb */
    kNMI_CPU2_WD_RESET,       /*!< NMI INT wdt reset */
    kNMI_CPU2_NMIWD_RESET     /*!< NMI INT nmi wdt */
} SYSCTRL_NmiFlag_t;

/*! \brief NMI CLB trigger definition */
typedef enum
{
    kALL_CLB_TRIGGER_NMI = 0,   /*!< All NMI triggered by clb */
    kCLB_IN_SUBSYS_TRIGGER_NMI, /*!< NMI triggered by clb in */
} SYSCTRL_ClbTrigger_t;

/*! \brief GPIO port XINT definition */
typedef enum
{
    kXINT_1 = 0, /*!< XINT1 index */
    kXINT_2,     /*!< XINT2 index */
    kXINT_3,     /*!< XINT3 index */
    kXINT_4,     /*!< XINT4 index */
    kXINT_5      /*!< XINT5 index */
} SYSCTRL_Xint_t;

/*! \brief GPIO XINT polarity definition */
typedef enum
{
    kPOSITIVE_EDGE_TRIGGER = 1,     /*!< XINT positive edge trigger */
    kNEGATIVE_EDGE_TRIGGER,         /*!< XINT negative edge trigger */
    kPOSITIVE_NEGATIVE_EDGE_TRIGGER /*!< XINT both edge trigger */
} SYSCTRL_XintPolarity_t;

//*****************************************************************************
//
//! The following values define the \e syncSrc parameter for
//! SysCtl_setSyncOutputConfig().
//
//*****************************************************************************
typedef enum
{
    SYSCTL_SYNC_OUT_SRC_EPWM1SYNCOUT  = 0X0U,  //!< EPWM1SYNCOUT --> EXTSYNCOUT
    SYSCTL_SYNC_OUT_SRC_EPWM2SYNCOUT  = 0X1U,  //!< EPWM2SYNCOUT --> EXTSYNCOUT
    SYSCTL_SYNC_OUT_SRC_EPWM3SYNCOUT  = 0X2U,  //!< EPWM3SYNCOUT --> EXTSYNCOUT
    SYSCTL_SYNC_OUT_SRC_EPWM4SYNCOUT  = 0X3U,  //!< EPWM4SYNCOUT --> EXTSYNCOUT
    SYSCTL_SYNC_OUT_SRC_EPWM5SYNCOUT  = 0X4U,  //!< EPWM5SYNCOUT --> EXTSYNCOUT
    SYSCTL_SYNC_OUT_SRC_EPWM6SYNCOUT  = 0X5U,  //!< EPWM6SYNCOUT --> EXTSYNCOUT
    SYSCTL_SYNC_OUT_SRC_EPWM7SYNCOUT  = 0X6U,  //!< EPWM7SYNCOUT --> EXTSYNCOUT
    SYSCTL_SYNC_OUT_SRC_EPWM8SYNCOUT  = 0X7U,  //!< EPWM8SYNCOUT --> EXTSYNCOUT
    SYSCTL_SYNC_OUT_SRC_EPWM9SYNCOUT  = 0X8U,  //!< EPWM9SYNCOUT --> EXTSYNCOUT
    SYSCTL_SYNC_OUT_SRC_EPWM10SYNCOUT = 0X9U,  //!< EPWM10SYNCOUT --> EXTSYNCOUT
    SYSCTL_SYNC_OUT_SRC_EPWM11SYNCOUT = 0XAU,  //!< EPWM11SYNCOUT --> EXTSYNCOUT
    SYSCTL_SYNC_OUT_SRC_EPWM12SYNCOUT = 0XBU,  //!< EPWM12SYNCOUT --> EXTSYNCOUT
    SYSCTL_SYNC_OUT_SRC_EPWM13SYNCOUT = 0XCU,  //!< EPWM13SYNCOUT --> EXTSYNCOUT
    SYSCTL_SYNC_OUT_SRC_EPWM14SYNCOUT = 0XDU,  //!< EPWM14SYNCOUT --> EXTSYNCOUT
    SYSCTL_SYNC_OUT_SRC_EPWM15SYNCOUT = 0XEU,  //!< EPWM15SYNCOUT --> EXTSYNCOUT
    SYSCTL_SYNC_OUT_SRC_EPWM16SYNCOUT = 0XFU,  //!< EPWM16SYNCOUT --> EXTSYNCOUT
    SYSCTL_SYNC_OUT_SRC_ECAP1SYNCOUT  = 0x18,  //!< ECAP1SYNCOUT --> EXTSYNCOUT
    SYSCTL_SYNC_OUT_SRC_ECAP2SYNCOUT  = 0x19,  //!< ECAP2SYNCOUT --> EXTSYNCOUT
    SYSCTL_SYNC_OUT_SRC_ECAP3SYNCOUT  = 0x20,  //!< ECAP3SYNCOUT --> EXTSYNCOUT
    SYSCTL_SYNC_OUT_SRC_ECAP4SYNCOUT  = 0x21,  //!< ECAP4SYNCOUT --> EXTSYNCOUT
    SYSCTL_SYNC_OUT_SRC_ECAP5SYNCOUT  = 0x22,  //!< ECAP5SYNCOUT --> EXTSYNCOUT
    SYSCTL_SYNC_OUT_SRC_ECAP6SYNCOUT  = 0x23   //!< ECAP6SYNCOUT --> EXTSYNCOUT
} SysCtl_SyncOutputSource;

#if defined(HTE_DEVICE_HS32F7D377_CPU1)
/*! \brief peripheral reset port definition */
typedef enum
{
    kSYSCTL_PERIPH_RES_TFU    = 0x0000, /*!< Reset TFU clock */
    kSYSCTL_PERIPH_RES_CRC    = 0x0800, /*!< Reset CRC clock */
    kSYSCTL_PERIPH_RES_EMIF1  = 0x0001, /*!< Reset EMIF1 clock */
    kSYSCTL_PERIPH_RES_EPWM1  = 0x0002, /*!< Reset EPWM1 clock */
    kSYSCTL_PERIPH_RES_EPWM2  = 0x0102, /*!< Reset EPWM2 clock */
    kSYSCTL_PERIPH_RES_EPWM3  = 0x0202, /*!< Reset EPWM3 clock */
    kSYSCTL_PERIPH_RES_EPWM4  = 0x0302, /*!< Reset EPWM4 clock */
    kSYSCTL_PERIPH_RES_EPWM5  = 0x0402, /*!< Reset EPWM5 clock */
    kSYSCTL_PERIPH_RES_EPWM6  = 0x0502, /*!< Reset EPWM6 clock */
    kSYSCTL_PERIPH_RES_EPWM7  = 0x0602, /*!< Reset EPWM7 clock */
    kSYSCTL_PERIPH_RES_EPWM8  = 0x0702, /*!< Reset EPWM8 clock */
    kSYSCTL_PERIPH_RES_EPWM9  = 0x0802, /*!< Reset EPWM9 clock */
    kSYSCTL_PERIPH_RES_EPWM10 = 0x0902, /*!< Reset EPWM10 clock */
    kSYSCTL_PERIPH_RES_EPWM11 = 0x0A02, /*!< Reset EPWM11 clock */
    kSYSCTL_PERIPH_RES_EPWM12 = 0x0B02, /*!< Reset EPWM12 clock */
    kSYSCTL_PERIPH_RES_ECAP1  = 0x0003, /*!< Reset ECAP1 clock */
    kSYSCTL_PERIPH_RES_ECAP2  = 0x0103, /*!< Reset ECAP2 clock */
    kSYSCTL_PERIPH_RES_ECAP3  = 0x0203, /*!< Reset ECAP3 clock */
    kSYSCTL_PERIPH_RES_ECAP4  = 0x0303, /*!< Reset ECAP4 clock */
    kSYSCTL_PERIPH_RES_ECAP5  = 0x0403, /*!< Reset ECAP5 clock */
    kSYSCTL_PERIPH_RES_ECAP6  = 0x0503, /*!< Reset ECAP6 clock */
    kSYSCTL_PERIPH_RES_EQEP1  = 0x0004, /*!< Reset EQEP1 clock */
    kSYSCTL_PERIPH_RES_EQEP2  = 0x0104, /*!< Reset EQEP2 clock */
    kSYSCTL_PERIPH_RES_EQEP3  = 0x0204, /*!< Reset EQEP3 clock */
    kSYSCTL_PERIPH_RES_SDFM1  = 0x0006, /*!< Reset SDFM1 clock */
    kSYSCTL_PERIPH_RES_SDFM2  = 0x0106, /*!< Reset SDFM2 clock */
    kSYSCTL_PERIPH_RES_UARTA  = 0x0007, /*!< Reset UARTA clock */
    kSYSCTL_PERIPH_RES_UARTB  = 0x0107, /*!< Reset UARTB clock */
    kSYSCTL_PERIPH_RES_UARTC  = 0x0207, /*!< Reset UARTC clock */
    kSYSCTL_PERIPH_RES_UARTD  = 0x0307, /*!< Reset UARTD clock */
    kSYSCTL_PERIPH_RES_SPIA   = 0x0008, /*!< Reset SPIA clock */
    kSYSCTL_PERIPH_RES_SPIB   = 0x0108, /*!< Reset SPIB clock */
    kSYSCTL_PERIPH_RES_SPIC   = 0x0208, /*!< Reset SPIC clock */
    kSYSCTL_PERIPH_RES_I2CA   = 0x0009, /*!< Reset I2CA clock */
    kSYSCTL_PERIPH_RES_I2CB   = 0x0109, /*!< Reset I2CB clock */
    kSYSCTL_PERIPH_RES_PMBUSA = 0x1009, /*!< Reset PMBUSA clock */
    kSYSCTL_PERIPH_RES_MCANA  = 0x000A, /*!< Reset CANA clock */
    kSYSCTL_PERIPH_RES_MCANB  = 0x010A, /*!< Reset CANB clock */
    kSYSCTL_PERIPH_RES_MCANC  = 0x020A, /*!< Reset CANC clock */
    kSYSCTL_PERIPH_RES_USB    = 0x100B, /*!< Reset USB clock */
    kSYSCTL_PERIPH_RES_ADCA   = 0x000D, /*!< Reset ADCA clock */
    kSYSCTL_PERIPH_RES_ADCB   = 0x010D, /*!< Reset ADCB clock */
    kSYSCTL_PERIPH_RES_ADCC   = 0x020D, /*!< Reset ADCC clock */
    kSYSCTL_PERIPH_RES_ADCD   = 0x030D, /*!< Reset ADCD clock */
    kSYSCTL_PERIPH_RES_CMPSS1 = 0x000E, /*!< Reset CMPSS1 clock */
    kSYSCTL_PERIPH_RES_CMPSS2 = 0x010E, /*!< Reset CMPSS2 clock */
    kSYSCTL_PERIPH_RES_CMPSS3 = 0x020E, /*!< Reset CMPSS3 clock */
    kSYSCTL_PERIPH_RES_CMPSS4 = 0x030E, /*!< Reset CMPSS4 clock */
    kSYSCTL_PERIPH_RES_CMPSS5 = 0x040E, /*!< Reset CMPSS5 clock */
    kSYSCTL_PERIPH_RES_CMPSS6 = 0x050E, /*!< Reset CMPSS6 clock */
    kSYSCTL_PERIPH_RES_CMPSS7 = 0x060E, /*!< Reset CMPSS7 clock */
    kSYSCTL_PERIPH_RES_CMPSS8 = 0x070E, /*!< Reset CMPSS8 clock */
    kSYSCTL_PERIPH_RES_DACA   = 0x1010, /*!< Reset DACA clock */
    kSYSCTL_PERIPH_RES_DACB   = 0x1110, /*!< Reset DACB clock */
    kSYSCTL_PERIPH_RES_DACC   = 0x1210, /*!< Reset DACC clock */
    kSYSCTL_PERIPH_RES_CLB1   = 0x0011, /*!< Reset CLB1 clock */
    kSYSCTL_PERIPH_RES_CLB2   = 0x0111, /*!< Reset CLB2 clock */
    kSYSCTL_PERIPH_RES_CLB3   = 0x0211, /*!< Reset CLB3 clock */
    kSYSCTL_PERIPH_RES_CLB4   = 0x0311, /*!< Reset CLB4 clock */
    kSYSCTL_PERIPH_RES_CLB5   = 0x0411, /*!< Reset CLB5 clock */
    kSYSCTL_PERIPH_RES_CLB6   = 0x0511, /*!< Reset CLB6 clock */
    kSYSCTL_PERIPH_RES_CLB7   = 0x0611, /*!< Reset CLB7 clock */
    kSYSCTL_PERIPH_RES_CLB8   = 0x0711  /*!< Reset CLB8 clock */
} SYSCTRL_PeripheralSOFTPRES_t;

/*! \brief peripheral cpusel definition */
typedef enum
{
    kSYSCTL_PERIPH_CPUSEL_EPWM1  = 0x0000, //!< CPUSEL EPWM1
    kSYSCTL_PERIPH_CPUSEL_EPWM2  = 0x0100, //!< CPUSEL EPWM2
    kSYSCTL_PERIPH_CPUSEL_EPWM3  = 0x0200, //!< CPUSEL EPWM3
    kSYSCTL_PERIPH_CPUSEL_EPWM4  = 0x0300, //!< CPUSEL EPWM4
    kSYSCTL_PERIPH_CPUSEL_EPWM5  = 0x0400, //!< CPUSEL EPWM5
    kSYSCTL_PERIPH_CPUSEL_EPWM6  = 0x0500, //!< CPUSEL EPWM6
    kSYSCTL_PERIPH_CPUSEL_EPWM7  = 0x0600, //!< CPUSEL EPWM7
    kSYSCTL_PERIPH_CPUSEL_EPWM8  = 0x0700, //!< CPUSEL EPWM8
    kSYSCTL_PERIPH_CPUSEL_EPWM9  = 0x0800, //!< CPUSEL EPWM9
    kSYSCTL_PERIPH_CPUSEL_EPWM10 = 0x0900, //!< CPUSEL EPWM10
    kSYSCTL_PERIPH_CPUSEL_EPWM11 = 0x0A00, //!< CPUSEL EPWM11
    kSYSCTL_PERIPH_CPUSEL_EPWM12 = 0x0B00, //!< CPUSEL EPWM12
    kSYSCTL_PERIPH_CPUSEL_ECAP1  = 0x0001, //!< CPUSEL ECAP1
    kSYSCTL_PERIPH_CPUSEL_ECAP2  = 0x0101, //!< CPUSEL ECAP2
    kSYSCTL_PERIPH_CPUSEL_ECAP3  = 0x0201, //!< CPUSEL ECAP3
    kSYSCTL_PERIPH_CPUSEL_ECAP4  = 0x0301, //!< CPUSEL ECAP4
    kSYSCTL_PERIPH_CPUSEL_ECAP5  = 0x0401, //!< CPUSEL ECAP5
    kSYSCTL_PERIPH_CPUSEL_ECAP6  = 0x0501, //!< CPUSEL ECAP6
    kSYSCTL_PERIPH_CPUSEL_EQEP1  = 0x0002, //!< CPUSEL EQEP1
    kSYSCTL_PERIPH_CPUSEL_EQEP2  = 0x0102, //!< CPUSEL EQEP2
    kSYSCTL_PERIPH_CPUSEL_EQEP3  = 0x0202, //!< CPUSEL EQEP3
    kSYSCTL_PERIPH_CPUSEL_SDFM1  = 0x0004, //!< CPUSEL SDFM1
    kSYSCTL_PERIPH_CPUSEL_SDFM2  = 0x0104, //!< CPUSEL SDFM2
    kSYSCTL_PERIPH_CPUSEL_UARTA  = 0x0005, //!< CPUSEL UARTA
    kSYSCTL_PERIPH_CPUSEL_UARTB  = 0x0105, //!< CPUSEL UARTB
    kSYSCTL_PERIPH_CPUSEL_UARTC  = 0x0205, //!< CPUSEL UARTC
    kSYSCTL_PERIPH_CPUSEL_UARTD  = 0x0305, //!< CPUSEL UARTD
    kSYSCTL_PERIPH_CPUSEL_SPIA   = 0x0006, //!< CPUSEL SPIA
    kSYSCTL_PERIPH_CPUSEL_SPIB   = 0x0106, //!< CPUSEL SPIB
    kSYSCTL_PERIPH_CPUSEL_SPIC   = 0x0206, //!< CPUSEL SPIC
    kSYSCTL_PERIPH_CPUSEL_I2CA   = 0x0007, //!< CPUSEL I2CA
    kSYSCTL_PERIPH_CPUSEL_I2CB   = 0x0107, //!< CPUSEL I2CB
    kSYSCTL_PERIPH_CPUSEL_PMBUSA = 0x1007, //!< CPUSEL PMBUSA
    kSYSCTL_PERIPH_CPUSEL_MCANA  = 0x0008, //!< CPUSEL CANA
    kSYSCTL_PERIPH_CPUSEL_MCANB  = 0x0108, //!< CPUSEL CANB
    kSYSCTL_PERIPH_CPUSEL_MCANC  = 0x0208, //!< CPUSEL CANC
    kSYSCTL_PERIPH_CPUSEL_USB    = 0x1008, //!< CPUSEL USB
    kSYSCTL_PERIPH_CPUSEL_ADCA   = 0x000B, //!< CPUSEL ADCA
    kSYSCTL_PERIPH_CPUSEL_ADCB   = 0x010B, //!< CPUSEL ADCB
    kSYSCTL_PERIPH_CPUSEL_ADCC   = 0x020B, //!< CPUSEL ADCC
    kSYSCTL_PERIPH_CPUSEL_ADCD   = 0x030B, //!< CPUSEL ADCD
    kSYSCTL_PERIPH_CPUSEL_CMPSS1 = 0x000C, //!< CPUSEL CMPSS1
    kSYSCTL_PERIPH_CPUSEL_CMPSS2 = 0x010C, //!< CPUSEL CMPSS2
    kSYSCTL_PERIPH_CPUSEL_CMPSS3 = 0x020C, //!< CPUSEL CMPSS3
    kSYSCTL_PERIPH_CPUSEL_CMPSS4 = 0x030C, //!< CPUSEL CMPSS4
    kSYSCTL_PERIPH_CPUSEL_CMPSS5 = 0x040C, //!< CPUSEL CMPSS5
    kSYSCTL_PERIPH_CPUSEL_CMPSS6 = 0x050C, //!< CPUSEL CMPSS6
    kSYSCTL_PERIPH_CPUSEL_CMPSS7 = 0x060C, //!< CPUSEL CMPSS7
    kSYSCTL_PERIPH_CPUSEL_CMPSS8 = 0x070C, //!< CPUSEL CMPSS8
    kSYSCTL_PERIPH_CPUSEL_DACA   = 0x100E, //!< CPUSEL DACA
    kSYSCTL_PERIPH_CPUSEL_DACB   = 0x110E, //!< CPUSEL DACB
    kSYSCTL_PERIPH_CPUSEL_DACC   = 0x120E, //!< CPUSEL DACC
    kSYSCTL_PERIPH_CPUSEL_CLB1   = 0x000F, //!< CPUSEL CLB1
    kSYSCTL_PERIPH_CPUSEL_CLB2   = 0x010F, //!< CPUSEL CLB2
    kSYSCTL_PERIPH_CPUSEL_CLB3   = 0x020F, //!< CPUSEL CLB3
    kSYSCTL_PERIPH_CPUSEL_CLB4   = 0x030F, //!< CPUSEL CLB4
    kSYSCTL_PERIPH_CPUSEL_CLB5   = 0x040F, //!< CPUSEL CLB5
    kSYSCTL_PERIPH_CPUSEL_CLB6   = 0x050F, //!< CPUSEL CLB6
    kSYSCTL_PERIPH_CPUSEL_CLB7   = 0x060F, //!< CPUSEL CLB7
    kSYSCTL_PERIPH_CPUSEL_CLB8   = 0x070F  //!< CPUSEL CLB8
} SYSCTRL_PeripheralCpusel_t;

/*! \brief The CPU selection index */
typedef enum
{
    kSYSC_CPUSEL0 = 0,   /*!< CPU sel reg index0 */
    kSYSC_CPUSEL1,       /*!< CPU sel reg index1 */
    kSYSC_CPUSEL2,       /*!< CPU sel reg index2 */
    kSYSC_CPUSEL4 = 4,   /*!< CPU sel reg index4 */
    kSYSC_CPUSEL5,       /*!< CPU sel reg index5 */
    kSYSC_CPUSEL6,       /*!< CPU sel reg index6 */
    kSYSC_CPUSEL7,       /*!< CPU sel reg index7 */
    kSYSC_CPUSEL8,       /*!< CPU sel reg index8 */
    kSYSC_CPUSEL11 = 11, /*!< CPU sel reg index11 */
    kSYSC_CPUSEL12,      /*!< CPU sel reg index12 */
    kSYSC_CPUSEL14 = 14, /*!< CPU sel reg index14 */
    kSYSC_CPUSEL15,      /*!< CPU sel reg index15 */
    kSYSC_CPUSELMAX,     /*!< CPU sel reg max */
} SYSCTRL_CpuSelIndex_t;


/*! \brief The CPU selection */
typedef enum
{
    kSYSCTRL_CPUSEL_CPU1 = 0x0U, /*!< CPU1 is selected */
    kSYSCTRL_CPUSEL_CPU2 = 0x1U, /*!< CPU1 is selected */
} SYSCTRL_CpuSel_t;


/*! \brief cpu2 reset handle definition */
typedef enum
{
    kSYSC_CPU2_RELEASE = 0, /*!< CPU2 release*/
    kSYSC_CPU2_HOLD    = 1  /*!< CPU2 hold*/
} SYSCTRL_CPU2Reset_t;

/*! \brief cpu2 reset status definition */
typedef enum
{
    kSYSC_CPU2_ACTIVE       = 0, /*!< CPU2 status active*/
    kSYSC_CPU2_IDLE         = 1, /*!< CPU2 status idle*/
    kSYSC_CPU2_STANDBY      = 2, /*!< CPU2 status standby*/
    kSYSC_CPU2_STS_RESERVED = 3  /*!< CPU2 status reserved*/
} SYSCTRL_CPU2LpmStatus_t;
#endif

/*! \brief clk sem */
typedef enum
{
    kSYSC_SEM_CPU0_T0 = 0, /*!< CLK sem T0 for CPU0*/
    kSYSC_SEM_CPU1    = 1, /*!< CLK sem for CPU1*/
    kSYSC_SEM_CPU0    = 2, /*!< CLK sem for CPU0*/
    kSYSC_SEM_CPU0_T1 = 3  /*!< CLK sem T1 for CPU1*/
} SYSCTRL_ClkSem_t;

/*! \brief clk lock */
typedef enum
{
    kSYSC_LOCK_CLKSRCCTL1 = 0,  /*!< Lock reg CLKSRCCTL1*/
    kSYSC_LOCK_CLKSRCCTL2,      /*!< Lock reg CLKSRCCTL2*/
    kSYSC_LOCK_CLKSRCCTL3,      /*!< Lock reg CLKSRCCTL3*/
    kSYSC_LOCK_SYSPLLCTL1,      /*!< Lock reg SYSPLLCTL1*/
    kSYSC_LOCK_SYSPLLMULT = 6,  /*!< Lock reg SYSPLLMULT*/
    kSYSC_LOCK_AUXPLLCTL1,      /*!< Lock reg AUXPLLCTL1*/
    kSYSC_LOCK_AUXPLLMULT = 10, /*!< Lock reg AUXPLLMULT*/
    kSYSC_LOCK_SYSCLKDIVSEL,    /*!< Lock reg SYSCLKDIVSEL*/
    kSYSC_LOCK_AUXCLKDIVSEL,    /*!< Lock reg AUXCLKDIVSEL*/
    kSYSC_LOCK_PERCLKDIVSEL,    /*!< Lock reg PERCLKDIVSEL*/
    kSYSC_LOCK_LOSPCP = 15,     /*!< Lock reg LOSPCP*/
    kSYSC_LOCK_CLKCFGLOCKMAX,   /*!< Lock reg ALL*/
} SYSCTRL_ClkCfgLock_t;

/*! \brief clk lock */
typedef enum
{
    kSYSC_CLKSRCCTL1 = 0,    /*!< reg CLKSRCCTL1 index*/
    kSYSC_CLKSRCCTL2,        /*!< reg CLKSRCCTL2 index*/
    kSYSC_CLKSRCCTL3,        /*!< reg CLKSRCCTL3 index*/
    kSYSC_SYSPLLCTL1,        /*!< reg SYSPLLCTL1 index*/
    kSYSC_SYSPLLMULT   = 6,  /*!< reg SYSPLLMULT index*/
    kSYSC_AUXPLLCTL1   = 8,  /*!< reg AUXPLLCTL1 index*/
    kSYSC_AUXPLLMULT   = 11, /*!< reg AUXPLLMULT index*/
    kSYSC_SYSCLKDIVSEL = 13, /*!< reg SYSCLKDIVSEL index*/
    kSYSC_AUXCLKDIVSEL,      /*!< reg AUXCLKDIVSEL index*/
    kSYSC_PERCLKDIVSEL,      /*!< reg PERCLKDIVSEL index*/
    kSYSC_LOSPCP = 18,       /*!< reg LOSPCP index*/
    kSYSC_CLKCFGLOCKMAX,     /*!< reg all index*/
} SYSCTRL_ClkCfgReg_t;

/*! \brief clk source */
typedef enum
{
    kSYSC_OSCSRC_INTOSC2 = 0, /*!< Osc source intosc2*/
    kSYSC_OSCSRC_XTAL    = 1, /*!< Osc source xtal*/
    kSYSC_OSCSRC_INTOSC1 = 2, /*!< Osc source intosc1*/
    kSYSC_OSCSRC_RESV         /*!< Osc source resv*/
} SYSCTRL_OscSrcSel_t;

/*! \brief clk AUX src */
typedef enum
{
    kSYSC_AUXSRC_INTOSC2  = 0, /*!<Aux Osc source intosc2*/
    kSYSC_AUXSRC_XTAL     = 1, /*!<Aux Osc source xtal*/
    kSYSC_AUXSRC_AUXCLKIN = 2, /*!<Aux Osc source auxclkin*/
    kSYSC_AUXSRC_RESV          /*!<Aux Osc source resv*/
} SYSCTRL_AuxSrcSel_t;

/*! \brief clk CAN src */
typedef enum
{
    kSYSC_CANSRC_PSYSCLK  = 0, /*!<Can source syspclk*/
    kSYSC_CANSRC_XTAL     = 1, /*!<Can source xtal*/
    kSYSC_CANSRC_AUXCLKIN = 2, /*!<Can source auxclkin*/
    kSYSC_CANSRC_RESV          /*!<Can source resv*/
} SYSCTRL_CANBclkSrcSel_t;

/*! \brief clk SPI src */
typedef enum
{
    kSYSC_SPISRC_PSYSCLK = 0, /*!<Spi source syspclk*/
    kSYSC_SPISRC_SYSCLK  = 1, /*!<Spi source sysclk*/
} SYSCTRL_SPIclkSrcSel_t;

/*! \brief CAN INDEX */
typedef enum
{
    kSYSC_INDEX_CANA = 0, /*!<Can A index*/
    kSYSC_INDEX_CANB = 1, /*!<Can B index*/
    kSYSC_INDEX_CANC = 2, /*!<Can C index*/
} SYSCTRL_CANIndex_t;

/*! \brief CAN INDEX */
typedef enum
{
    kSYSC_INDEX_SPIA = 0, /*!<SPI A index*/
    kSYSC_INDEX_SPIB = 1, /*!<SPI B index*/
    kSYSC_INDEX_SPIC = 2, /*!<SPI C index*/
} SYSCTRL_SPIIndex_t;

/*! \brief xclkout sel */
typedef enum
{
    kSYSC_XCLKOUT_PSYSCLK      = 0, /*!<Xclkout PSYSCLK*/
    kSYSC_XCLKOUT_PLLRAWSCLK   = 1, /*!<Xclkout PLLRAWSCLK*/
    kSYSC_XCLKOUT_CPU1SYSCLK   = 2, /*!<Xclkout CPU1SYSCLK*/
    kSYSC_XCLKOUT_CPU2SYSCLK   = 3, /*!<Xclkout CPU2SYSCLK*/
    kSYSC_XCLKOUT_AUXPLLRAMCLK = 4, /*!<Xclkout AUXPLLRAMCLK*/
    kSYSC_XCLKOUT_INTOSC1      = 5, /*!<Xclkout INTOSC1*/
    kSYSC_XCLKOUT_INTOSC2      = 6, /*!<Xclkout INTOSC2*/
    kSYSC_XCLKOUT_RESV              /*!<Xclkout RESV*/
} SYSCTRL_XCLKOutSel_t;

/*! \brief FCW SSC DEC point */
typedef enum
{
    kSYSC_DEC_POINT4 = 0, /*!<FCW set for 4 bit decpoint*/
    kSYSC_DEC_POINT5 = 1, /*!<FCW set for 5 bit decpoint*/
    kSYSC_DEC_POINT6 = 2, /*!<FCW set for 6 bit decpoint*/
    kSYSC_DEC_POINT7 = 3, /*!<FCW set for 7 bit decpoint*/
    kSYSC_DEC_POINT8 = 4, /*!<FCW set for 8 bit decpoint*/
} SYSCTRL_FCWDecPoint_t;

/*! \brief emif SSC DEC point */
typedef enum
{
    kSYSC_EMIF_CLK_DIV1 = 0, /*!<EMIF clk div 1*/
    kSYSC_EMIF_CLK_DIV2 = 1, /*!<EMIF clk div 2*/
} SYSCTRL_EmifClkDiv_t;

/*! \brief FCW SSC DEC point */
typedef enum
{
    kSYSC_XCLKOUT_DIV1 = 0, /*!<XCLKOUT clk div 1*/
    kSYSC_XCLKOUT_DIV2 = 1, /*!<XCLKOUT clk div 2*/
    kSYSC_XCLKOUT_DIV4 = 2, /*!<XCLKOUT clk div 4*/
    kSYSC_XCLKOUT_DIV8 = 3, /*!<XCLKOUT clk div 8*/
} SYSCTRL_XclkOutDiv_t;

/*! \brief cpu sys reg lock */
typedef enum
{
    kSYSC_CPUSYS_LOCK_PCLKCR0 = 3, /*!<Lock pclk cr0 index*/
    kSYSC_CPUSYS_LOCK_PCLKCR1,     /*!<Lock pclk cr1 index*/
    kSYSC_CPUSYS_LOCK_PCLKCR2,     /*!<Lock pclk cr2 index*/
    kSYSC_CPUSYS_LOCK_PCLKCR3,     /*!<Lock pclk cr3 index*/
    kSYSC_CPUSYS_LOCK_PCLKCR4,     /*!<Lock pclk cr4 index*/
    kSYSC_CPUSYS_LOCK_PCLKCR5,     /*!<Lock pclk cr5 index*/
    kSYSC_CPUSYS_LOCK_PCLKCR6,     /*!<Lock pclk cr6 index*/
    kSYSC_CPUSYS_LOCK_PCLKCR7,     /*!<Lock pclk cr7 index*/
    kSYSC_CPUSYS_LOCK_PCLKCR8,     /*!<Lock pclk cr8 index*/
    kSYSC_CPUSYS_LOCK_PCLKCR9,     /*!<Lock pclk cr9 index*/
    kSYSC_CPUSYS_LOCK_PCLKCR10,    /*!<Lock pclk cr10 index*/
    kSYSC_CPUSYS_LOCK_PCLKCR11,    /*!<Lock pclk cr11 index*/
    kSYSC_CPUSYS_LOCK_PCLKCR12,    /*!<Lock pclk cr12 index*/
    kSYSC_CPUSYS_LOCK_PCLKCR13,    /*!<Lock pclk cr13 index*/
    kSYSC_CPUSYS_LOCK_PCLKCR14,    /*!<Lock pclk cr14 index*/
    kSYSC_CPUSYS_LOCK_PCLKCR15,    /*!<Lock pclk cr15 index*/
    kSYSC_CPUSYS_LOCK_PCLKCR16,    /*!<Lock pclk cr16 index*/
    kSYSC_CPUSYS_LOCK_LPMCR = 21,  /*!<Lock pclk lpmcr index*/
    kSYSC_CPUSYS_LOCK_GPIOLPMSEL0, /*!<Lock pclk gpiolpm sel0 index*/
    kSYSC_CPUSYS_LOCK_GPIOLPMSEL1, /*!<Lock pclk gpiolpm sel0 index*/
    kSYSC_CPUSYS_LOCK_PCLKCR17,    /*!<Lock pclk cr17 index*/
    kSYSC_CPUSYS_LOCK_MAX          /*!<Lock all index*/
} SYSCTRL_CpuSysLock_t;


/*! \brief peripheral pclkcr definition */
typedef enum
{
    kSYSCTL_PERIPH_CLK_DMA         = 0x0200, //!< DMA clock
    kSYSCTL_PERIPH_CLK_CPUTIMER0   = 0x0300, //!< CPUTIMER0 clock
    kSYSCTL_PERIPH_CLK_CPUTIMER1   = 0x0400, //!< CPUTIMER1 clock
    kSYSCTL_PERIPH_CLK_CPUTIMER2   = 0x0500, //!< CPUTIMER2 clock
    kSYSCTL_PERIPH_CLK_DWTIMER_CH0 = 0x0800, //!< DWTIMER Channel0 clock
    kSYSCTL_PERIPH_CLK_DWTIMER_CH1 = 0x0900, //!< DWTIMER Channel1 clock
    kSYSCTL_PERIPH_CLK_DWTIMER_CH2 = 0x0A00, //!< DWTIMER Channel2 clock
    kSYSCTL_PERIPH_CLK_TBCLKSYNC   = 0x1200, //!< TBCLKSYNC clock
    kSYSCTL_PERIPH_CLK_GTBCLKSYNC  = 0x1300, //!< GTBCLKSYNC clock
    kSYSCTL_PERIPH_CLK_EMIF1       = 0x0001, //!< EMIF1 clock
    kSYSCTL_PERIPH_CLK_EPWM1       = 0x0002, //!< EPWM1 clock
    kSYSCTL_PERIPH_CLK_EPWM2       = 0x0102, //!< EPWM2 clock
    kSYSCTL_PERIPH_CLK_EPWM3       = 0x0202, //!< EPWM3 clock
    kSYSCTL_PERIPH_CLK_EPWM4       = 0x0302, //!< EPWM4 clock
    kSYSCTL_PERIPH_CLK_EPWM5       = 0x0402, //!< EPWM5 clock
    kSYSCTL_PERIPH_CLK_EPWM6       = 0x0502, //!< EPWM6 clock
    kSYSCTL_PERIPH_CLK_EPWM7       = 0x0602, //!< EPWM7 clock
    kSYSCTL_PERIPH_CLK_EPWM8       = 0x0702, //!< EPWM8 clock
    kSYSCTL_PERIPH_CLK_EPWM9       = 0x0802, //!< EPWM9 clock
    kSYSCTL_PERIPH_CLK_EPWM10      = 0x0902, //!< EPWM10 clock
    kSYSCTL_PERIPH_CLK_EPWM11      = 0x0A02, //!< EPWM11 clock
    kSYSCTL_PERIPH_CLK_EPWM12      = 0x0B02, //!< EPWM12 clock
    kSYSCTL_PERIPH_CLK_ECAP1       = 0x0003, //!< ECAP1 clock
    kSYSCTL_PERIPH_CLK_ECAP2       = 0x0103, //!< ECAP2 clock
    kSYSCTL_PERIPH_CLK_ECAP3       = 0x0203, //!< ECAP3 clock
    kSYSCTL_PERIPH_CLK_ECAP4       = 0x0303, //!< ECAP4 clock
    kSYSCTL_PERIPH_CLK_ECAP5       = 0x0403, //!< ECAP5 clock
    kSYSCTL_PERIPH_CLK_ECAP6       = 0x0503, //!< ECAP6 clock
    kSYSCTL_PERIPH_CLK_EQEP1       = 0x0004, //!< EQEP1 clock
    kSYSCTL_PERIPH_CLK_EQEP2       = 0x0104, //!< EQEP2 clock
    kSYSCTL_PERIPH_CLK_EQEP3       = 0x0204, //!< EQEP3 clock
    kSYSCTL_PERIPH_CLK_SDFM1       = 0x0006, //!< SDFM1 clock
    kSYSCTL_PERIPH_CLK_SDFM2       = 0x0106, //!< SDFM2 clock
    kSYSCTL_PERIPH_CLK_UARTA       = 0x0007, //!< UARTA clock
    kSYSCTL_PERIPH_CLK_UARTB       = 0x0107, //!< UARTB clock
    kSYSCTL_PERIPH_CLK_UARTC       = 0x0207, //!< UARTC clock
    kSYSCTL_PERIPH_CLK_UARTD       = 0x0307, //!< UARTD clock
    kSYSCTL_PERIPH_CLK_SPIA        = 0x0008, //!< SPIA clock
    kSYSCTL_PERIPH_CLK_SPIB        = 0x0108, //!< SPIB clock
    kSYSCTL_PERIPH_CLK_SPIC        = 0x0208, //!< SPIC clock
    kSYSCTL_PERIPH_CLK_I2CA        = 0x0009, //!< I2CA clock
    kSYSCTL_PERIPH_CLK_I2CB        = 0x0109, //!< I2CB clock
    kSYSCTL_PERIPH_CLK_PMBUSA      = 0x1009, //!< PMBUSA clock
    kSYSCTL_PERIPH_CLK_MCANA       = 0x000A, //!< MCANA clock
    kSYSCTL_PERIPH_CLK_MCANB       = 0x010A, //!< MCANB clock
    kSYSCTL_PERIPH_CLK_MCANC       = 0x020A, //!< MCANB clock
    kSYSCTL_PERIPH_CLK_USBA        = 0x100B, //!< USBA clock
    kSYSCTL_PERIPH_CLK_ADCA        = 0x000D, //!< ADCA clock
    kSYSCTL_PERIPH_CLK_ADCB        = 0x010D, //!< ADCB clock
    kSYSCTL_PERIPH_CLK_ADCC        = 0x020D, //!< ADCC clock
    kSYSCTL_PERIPH_CLK_ADCD        = 0x030D, //!< ADCD clock
    kSYSCTL_PERIPH_CLK_CMPSS1      = 0x000E, //!< CMPSS1 clock
    kSYSCTL_PERIPH_CLK_CMPSS2      = 0x010E, //!< CMPSS2 clock
    kSYSCTL_PERIPH_CLK_CMPSS3      = 0x020E, //!< CMPSS3 clock
    kSYSCTL_PERIPH_CLK_CMPSS4      = 0x030E, //!< CMPSS4 clock
    kSYSCTL_PERIPH_CLK_CMPSS5      = 0x040E, //!< CMPSS5 clock
    kSYSCTL_PERIPH_CLK_CMPSS6      = 0x050E, //!< CMPSS6 clock
    kSYSCTL_PERIPH_CLK_CMPSS7      = 0x060E, //!< CMPSS7 clock
    kSYSCTL_PERIPH_CLK_CMPSS8      = 0x070E, //!< CMPSS8 clock
    kSYSCTL_PERIPH_CLK_DACA        = 0x1010, //!< DACA clock
    kSYSCTL_PERIPH_CLK_DACB        = 0x1110, //!< DACB clock
    kSYSCTL_PERIPH_CLK_DACC        = 0x1210, //!< DACC clock
    kSYSCTL_PERIPH_CLK_CLB1        = 0x0011, //!< CMPSS1 clock
    kSYSCTL_PERIPH_CLK_CLB2        = 0x0111, //!< CMPSS2 clock
    kSYSCTL_PERIPH_CLK_CLB3        = 0x0211, //!< CMPSS3 clock
    kSYSCTL_PERIPH_CLK_CLB4        = 0x0311, //!< CMPSS4 clock
    kSYSCTL_PERIPH_CLK_CLB5        = 0x0411, //!< CMPSS5 clock
    kSYSCTL_PERIPH_CLK_CLB6        = 0x0511, //!< CMPSS6 clock
    kSYSCTL_PERIPH_CLK_CLB7        = 0x0611, //!< CMPSS7 clock
    kSYSCTL_PERIPH_CLK_CLB8        = 0x0711  //!< CMPSS8 clock
} SYSCTRL_PeripheralPclockCr_t;

#if defined(HTE_DEVICE_HS32F7D377_CPU1)
/*! \brief gsram index definition */
typedef enum
{
    kSRAM_GS0 = 0, /*!<Sram 0 index*/
    kSRAM_GS1,     /*!<Sram 1 index*/
    kSRAM_GS2,     /*!<Sram 2 index*/
    kSRAM_GS3,     /*!<Sram 3 index*/
    kSRAM_GS4,     /*!<Sram 4 index*/
    kSRAM_GS5,     /*!<Sram 5 index*/
    kSRAM_GS6,     /*!<Sram 6 index*/
    kSRAM_GS7,     /*!<Sram 7 index*/
    kSRAM_GS8,     /*!<Sram 8 index*/
    kSRAM_GS9,     /*!<Sram 9 index*/
    kSRAM_GS10,    /*!<Sram 10 index*/
    kSRAM_GS11,    /*!<Sram 11 index*/
    kSRAM_GS12,    /*!<Sram 12 index*/
    kSRAM_GS13,    /*!<Sram 13 index*/
    kSRAM_GS14,    /*!<Sram 14 index*/
    kSRAM_GS15,    /*!<Sram 15 index*/
    kSRAM_GSMAX    /*!<Sram max index*/
} SYSCTRL_SramGs_t;

/*! \brief gsram select definition */
typedef enum
{
    kCPU1_MASTER = 0, /*!<Cpu1 master for SRAM*/
    kCPU2_MASTER = 1, /*!<Cpu2 master for SRAM*/
    kUSB_MASTER  = 2, /*!<USB master for SRAM*/
    kALL_MASTER  = 3, /*!<ALL master for SRAM*/
} SYSCTRL_GsxmSel_t;

/*! \brief peripeheral halt definition */
typedef enum
{
    kSYSC_HALT_PERIPEHERAL = 0, /*!<Halt PERIPEHERAL index */
    kSYSC_HALT_TIM,             /*!<Halt TIM index */
    kSYSC_HALT_DMA,             /*!<Halt DMA index */
    kSYSC_HALT_EPWM,            /*!<Halt EPWM index */
    kSYSC_HALT_CAP,             /*!<Halt CAP index */
    kSYSC_HALT_QEP,             /*!<Halt QEP index */
    kSYSC_HALT_CMPSS,           /*!<Halt CMPSS index */
    kSYSC_HALT_MAX              /*!<Halt ALL index */
} SYSCTRL_HaltPeripheral_t;

/*! \brief halt enable definition */
typedef enum
{
    kSYSC_HALT_ENABLE = 0, /*!<Halt enable */
    kSYSC_HALT_DISABLE     /*!<Halt disable */
} SYSCTRL_HaltEn_t;

#endif


/*! \brief reset cause definition */
typedef enum
{
    kRESET_CAUSE_POR = 0,  /*!<Power Reset */
    kRESET_CAUSE_XRSN,     /*!<XRSN Reset */
    kRESET_CAUSE_WDRSN,    /*!<WDT Reset */
    kRESET_CAUSE_NMIWDSN,  /*!<NMI WDT Reset */
    kRESET_CAUSE_XRSN_PIN, /*!<XRSN PIN Status */
    kRESET_CAUSE_TRST,     /*!<TSRT status */
    kRESET_CAUSE_MAX       /*!<Power max index */
} SYSCTRL_ResetCause_t;

/*! \brief asscess mode definition */
typedef enum
{
    kGS_ASSCESS_CPU, /*!<Gsram cpu asscess */
    kGS_ASSCESS_DMA  /*!<Gsram dma asscess */
} SYSCTRL_AccMode_t;

/*! \brief asscess enable definition */
typedef enum
{
    kGS_ASSCESS_ALLOW = 0, /*!<Gsram asscess allow*/
    kGS_ASSCESS_BLOCK      /*!<Gsram asscess block*/
} SYSCTRL_AccEn_t;

/*! \brief TCM definition */
typedef enum
{
    kSYS_ITCM = 0, /*!<ITCM index*/
    kSYS_DTCM,     /*!<DTCM index*/
    kSYS_TCM_MAX   /*!<TCM MAX index*/
} SYSCTRL_Tcm_t;

/*! \brief no master asscess mode definition */
typedef enum
{
    kNO_MASTER_ACC_CPUW     = 1, /*!<Gsram no master cpu write */
    kNO_MASTER_ACC_DMAW     = 3, /*!<Gsram no master dma write */
    kNO_MASTER_ACC_USBA_DMA = 7, /*!<Gsram no master usb dma write */
    kNO_MASTER_ACC_MAX           /*!<Gsram no master cpu write */
} SYSCTRL_NoMasterAcc_t;

/*! \brief master asscess mode definition */
typedef enum
{
    kMASTER_ACC_CPUW = 1, /*!<Gsram master cpu write */
    kMASTER_ACC_DMAW = 2, /*!<Gsram master cpu write */
    kMASTER_ACC_MAX       /*!<Gsram master all write */
} SYSCTRL_MasterAcc_t;

/*! \brief crc error source definition */
typedef enum
{
    kCRC_ERROR_CPUR     = 0, /*!<crc error for cpu read */
    kCRC_ERROR_DMAR     = 1, /*!<crc error for dma read */
    kCRC_ERROR_USBA_DMA = 3, /*!<crc error for usb dma read */
    kCRC_ERROR_MAX           /*!<crc error max index */
} SYSCTRL_CrcError_t;

/*! \brief timer clk Source definition */
typedef enum
{
    //! System Clock Source
    kSYSCTRL_TIMER_CLOCK_SOURCE_SYS = 0x0,
    //! Internal Oscillator 1 Clock Source
    kSYSCTRL_TIMER_CLOCK_SOURCE_INTOSC1 = 0x1,
    //! Internal Oscillator 2 Clock Source
    kSYSCTRL_TIMER_CLOCK_SOURCE_INTOSC2 = 0x2,
    //! External Clock Source
    kSYSCTRL_TIMER_CLOCK_SOURCE_XTAL = 0x3,
    //! Auxiliary PLL Clock Source
    kSYSCTRL_TIMER_CLOCK_SOURCE_AUX = 0x6
} SYSCTRL_TimerClockSource_t;

/*! \brief timer clk Prescaler definition */
typedef enum
{
    kSYSCTRL_TIMER_CLOCK_PRESCALER_1  = 0, //!< Prescaler value of / 1
    kSYSCTRL_TIMER_CLOCK_PRESCALER_2  = 1, //!< Prescaler value of / 2
    kSYSCTRL_TIMER_CLOCK_PRESCALER_4  = 2, //!< Prescaler value of / 4
    kSYSCTRL_TIMER_CLOCK_PRESCALER_8  = 3, //!< Prescaler value of / 8
    kSYSCTRL_TIMER_CLOCK_PRESCALER_16 = 4  //!< Prescaler value of / 16
} SYSCTRL_TimerPrescaler_t;

/*! \brief epwm clk Prescaler definition */
typedef enum
{
    kSYSCTL_EPWMCLK_DIV_1, //!< EPWMCLK = PLLSYSCLK / 1
    kSYSCTL_EPWMCLK_DIV_2  //!< EPWMCLK = PLLSYSCLK / 2
} SYSCTRL_EpwmClkDiv_t;

/*! \brief cpu id definition */
typedef enum
{
    kSYSCTL_ID_CPU1 = 0x01, /*!<id for cpu1 */
    kSYSCTL_ID_CPU2         /*!<id for cpu2 */
} SYSCTL_CpuId_t;

/*! \brief device parameteric definition */
typedef enum
{
    kSYSCTL_DEVICE_REVID,    //!< Device REVID
    kSYSCTL_DEVICE_CPUID,    //!< Device CPUID
    kSYSCTL_DEVICE_PINCOUNT, //!< Device Pin Count
    kSYSCTL_DEVICE_FLASH,    //!< Device Flash size (KB)
    kSYSCTL_DEVICE_PARTID,   //!< Device Part ID Format Revision
    kSYSCTL_DEVICE_FAMILY,   //!< Device Family
    kSYSCTL_DEVICE_PARTNO,   //!< Device Part Number
    kSYSCTL_DEVICE_CLASSID   //!< Device Class ID
} SYSCTL_DeviceParametric_t;

// #if defined(HTE_DEVICE_HS32F7D377_CPU1)
/*! \brief type definition for sys clk config */
typedef struct
{
    SYSCTRL_OscSrcSel_t oscSrc;     /*!<sysclk config for osc source */
    uint32_t            oscFreq;    /*!<sysclk config for osc freq */
    bool                pllEN;      /*!<sysclk config for pll enable */
    uint8_t             srcClkdiv;  /*!<sysclk config for source clk div */
    uint32_t            pllClkFreq; /*!<sysclk config for pll clk freq */
    uint32_t            sysClkDiv;  /*!<sysclk config for sysclk div */
} SYSCTL_SysClk_Config_t;

/*! \brief type definition for aux clk config */
typedef struct
{
    SYSCTRL_AuxSrcSel_t oscSrc;     /*!<auxclk config for osc source */
    uint32_t            oscFreq;    /*!<auxclk config for osc freq */
    bool                pllEN;      /*!<auxclk config for pll enable */
    uint8_t             srcClkdiv;  /*!<auxclk config for source clk div */
    uint32_t            pllClkFreq; /*!<auxclk config for pll clk freq */
    uint32_t            auxClkDiv;  /*!<auxclk config for sysclk div */
} SYSCTL_AuxClk_Config_t;

// #endif

/*******************************************************************************
 * APIs
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Configure the watchdog counter clock
 *
 * \details This function configure the watchdog counter clock (WDCLK) rate relative to INTOSC1/512
 *
 * \param[in] div INTOSC DIV value
 *
 */
static inline void SYSCTRL_wdtClkSet(SYSCTRL_Wdps_t div)
{
    WD_REGS->WDCR = div;
}

/*!
 * \brief Configure the NMI Globe int enable
 *
 * \details This function When set to 1 any condition will generate an NMI interrupt to the CPU and
 * kick off the NMI watchdog counter
 *
 * \param[in] nmiEn nmi enable or disable
 *
 */
static inline void SYSCTRL_setNMIGlobalInterrupt(bool nmiEn)
{
    NMI_INTRUPT_REGS->NMICFG &= ~NMI_INTRUPT_REGS_NMICFG_NMIE_Msk;
    NMI_INTRUPT_REGS->NMICFG |= NMI_INTRUPT_REGS_NMICFG_NMIE_Set(nmiEn);
}

/*!
 * \brief Get the NMI Globe int enable flag
 *
 * \details This function get the NMI globe interrupt enable flag
 *
 * \return  return nmie value
 *
 */
static inline uint16_t SYSCTRL_getNMIFlag(void)
{
    return NMI_INTRUPT_REGS->NMIFLG;
}

/*!
 * \brief Get the NMI shadow int enable flag
 *
 * \details This function get the NMI shadow interrupt enable flag
 *
 * \return  return shadow flag value
 *
 */
static inline uint32_t SYSCTRL_getShadowNMIFlag(void)
{
    return NMI_INTRUPT_REGS->NMISHDFLG;
}

/*!
 * \brief Clear the NMI shadow int enable flag
 *
 * \details This function clear the NMI shadow interrupt enable flag
 *
 * \param[in] nmiFlag The nmi interrupt flag index
 *
 */
static inline void SYSCTRL_clearNMIFlag(SYSCTRL_NmiFlag_t nmiFlag)
{
    // pregs->NMIFLGCLR.all |= ((0x01UL << NMI_INT)|(0x01UL << nmi_flag));
    NMI_INTRUPT_REGS->NMIFLGCLR |= (0x01UL << nmiFlag);
    NMI_INTRUPT_REGS->NMIFLGCLR |= (0x01UL << kNMI_INT);
}

/*!
 * \brief Force the NMI shadow int enable flag
 *
 * \details This function force the NMI shadow interrupt,
 *  Writing a 1 to these flag bits will set the respective FAIL flag in the NMIFLG and NMISHDFLG registers
 *
 * \param[in] nmi_flag The nmi interrupt flag index
 *
 */
static inline void SYSCTRL_forceNMIInt(SYSCTRL_NmiFlag_t nmi_flag)
{
    NMI_INTRUPT_REGS->NMIFLGFRC |= (0x01UL << nmi_flag);
}

/*!
 * \brief Set the NMI WDT period
 *
 * \details This function set the NMI wdt period,
 *  This 16-bit value contains the period value at which a reset is generated when the watchdog counter matches
 *
 * \param[in] period The nmi wdt period value
 *
 */
static inline void SYSCTRL_setNMIWdtPeriod(uint16_t period)
{
    NMI_INTRUPT_REGS->NMIWDPRD = period;
}

/*!
 * \brief Get the NMI Globe NMI wdt count value
 *
 * \details This function get the NMI globe NMI wdt count value
 *
 * \return  return wdt cnt value
 *
 */
static inline uint16_t SYSCTRL_getNMIWdtCnt(void)
{
    return NMI_INTRUPT_REGS->NMIWDCNT;
}


/*!
 * \brief Set the NMI wdt int enable
 *
 * \details This function set the NMI wdt interrupt enable
 *
 * \param[in] nmiwdtEn The nmi wdt interrupt enable flag
 *
 */
static inline void SYSCTRL_setNMIWdtEn(bool nmiwdtEn)
{
    NMI_INTRUPT_REGS->NMIWDCFG &= ~NMI_INTRUPT_REGS_NMIWDCFG_NMIWD_EN_Msk;
    NMI_INTRUPT_REGS->NMIWDCFG |= NMI_INTRUPT_REGS_NMIWDCFG_NMIWD_EN_Set(nmiwdtEn);
}

/*!
 * \brief Set the NMI CLB int enable
 *
 * \details This function set the NMI CLB interrupt enable
 *
 * \param[in] clbTrigger The nmi clb interrupt enable flag
 *
 */
static inline void SYSCTRL_setNMIClbEn(SYSCTRL_ClbTrigger_t clbTrigger)
{
    NMI_INTRUPT_REGS->NMICLBCFG &= ~NMI_INTRUPT_REGS_NMICLBCFG_CLBNMISELECT_Msk;
    NMI_INTRUPT_REGS->NMICLBCFG |= NMI_INTRUPT_REGS_NMICLBCFG_CLBNMISELECT_Set(clbTrigger);
}

#if defined(HTE_DEVICE_HS32F7D377_CPU1)

/*!
 * \brief Lock Peripheral CPU sel
 *
 * \details this function is lock cpu sel register
 *
 * \param[in] selNum The cpusel index Num
 *
 */

static inline void SYSCTRL_lockCpuSel(SYSCTRL_CpuSelIndex_t selNum)
{
    if (selNum == kSYSC_CPUSELMAX)
        DEV_CFG_REGS->DEVCFGLOCK1 = 0x4D9F7;
    else
        DEV_CFG_REGS->DEVCFGLOCK1 |= (0x01UL << selNum);
}


/*!
 * \brief Reset Peripheral function
 *
 * \details This function reset Peripheral module, set 1 to reset module, then clean it to release
 *
 * \param[in] peripheral The peripheral Num
 *
 */
static inline void SYSCTRL_resetPeripheral(SYSCTRL_PeripheralSOFTPRES_t peripheral)
{
    uint32_t           regIndex;
    uint32_t           bitIndex;
    volatile uint32_t *regAddr;


    // Decode the peripheral variable.
    regIndex = ((uint32_t)peripheral & (uint32_t)SYSCTL_PERIPH_REG_M) << SYSCTL_PERIPH_REG_S;
    bitIndex = ((uint32_t)peripheral & (uint32_t)SYSCTL_PERIPH_BIT_M) >> SYSCTL_PERIPH_BIT_S;

    regAddr = (volatile uint32_t *)(DEV_CFG_REGS_BASE + SYSC_SOFTPRES0_OFFSET + regIndex);

    *regAddr |= (0x01UL << bitIndex);
    *regAddr &= ~(0x01UL << bitIndex);
}

/*!
 * \brief set percnf1 reg
 *
 * \details This function set percnf1 reg function
 *
 * \param[in] value is The percnf1 value
 *
 */
static inline void SYSCTRL_setPercnf1(uint32_t value)
{
    DEV_CFG_REGS->PERCNF1 = value;
}

/*!
 * \brief get percnf1 reg
 *
 * \details This function get percnf1 reg function
 *
 * \return The percnf1 value
 *
 */
static inline uint32_t SYSCTRL_getPercnf1(void)
{
    return DEV_CFG_REGS->PERCNF1;
}

/*!
 * \brief  Select CPU for a peripheral
 *
 * \details This function assign a CPU to control the peripheral
 *
 * \param[in] peripheral Peripheral instance
 * \param[in] cpuSel The selected CPU for the peripheral, refer \ref SYSCTRL_CpuSel_t for details
 */
static inline void SYSCTRL_selectCPUForPeripheral(SYSCTRL_PeripheralCpusel_t peripheral, SYSCTRL_CpuSel_t cpuSel)
{
    uint32_t           regIndex;
    uint32_t           bitIndex;
    volatile uint32_t *regAddr;

    // Decode the peripheral variable.
    regIndex = ((uint32_t)peripheral & (uint32_t)SYSCTL_PERIPH_REG_M) << SYSCTL_PERIPH_REG_S;
    bitIndex = ((uint32_t)peripheral & (uint32_t)SYSCTL_PERIPH_BIT_M) >> SYSCTL_PERIPH_BIT_S;

    regAddr = (volatile uint32_t *)(DEV_CFG_REGS_BASE + SYSC_CPUSEL0_OFFSET + regIndex);

    if (cpuSel == kSYSCTRL_CPUSEL_CPU1)
    {
        *regAddr &= ~(1U << bitIndex);
    }
    else
    {
        *regAddr |= 1U << bitIndex;
    }
}


/*!
 * \brief Config CPU2 reset function
 *
 * \details This function config cpu2 reset status, set 0 to release cpu2 core
 *
 * \param[in] resetFlag The cpu2 reset flag
 *
 */
static inline void SYSCTRL_cfgCPU2Reset(SYSCTRL_CPU2Reset_t resetFlag)
{
    if (resetFlag == kSYSC_CPU2_RELEASE)
        DEV_CFG_REGS->CPU2RESCTL = CPU2_RESET_CLEAN;
    else
        DEV_CFG_REGS->CPU2RESCTL = CPU2_RESET_HOLD;
}

/*!
 * \brief Get CPU2 reset status function
 *
 * \details This function get cpu2 reset status
 *
 * \return Return The cpu2 reset status
 *
 */
static inline bool SYSCTRL_getCPU2ResetStatus(void)
{
    if (DEV_CFG_REGS->RSTSTAT & DEV_CFG_REGS_RSTSTAT_CPU2RES_Msk)
        return true;
    else
        return false;
}

/*!
 * \brief Get CPU2 NMI WDT reset status function
 *
 * \details This function get cpu2  NMI WDT reset status
 *
 * \return Return The cpu2  NMI WDT reset status
 *
 */
static inline bool SYSCTRL_getCPU2NmiwdResetStatus(void)
{
    if (DEV_CFG_REGS->RSTSTAT & DEV_CFG_REGS_RSTSTAT_CPU2NMIWDRST_Msk)
        return true;
    else
        return false;
}

/*!
 * \brief Clear CPU2 NMI WDT reset status function
 *
 * \details This function clean cpu2  NMI WDT reset status
 *
 *
 */
static inline void SYSCTRL_clearCPU2NmiwdResetStatus(void)
{
    DEV_CFG_REGS->RSTSTAT |= DEV_CFG_REGS_RSTSTAT_CPU2NMIWDRST_Set(0x01U);
}

/*!
 * \brief Get CPU2 LPM status function
 *
 * \details This function get cpu2  LPM status
 *
 * \return Return The cpu2 LPM status
 *
 */
static inline SYSCTRL_CPU2LpmStatus_t SYSCTRL_getCPU2LpmStatus(void)
{
    SYSCTRL_CPU2LpmStatus_t status;
    status = (SYSCTRL_CPU2LpmStatus_t)DEV_CFG_REGS_LPMSTAT_CPU2LPMSTAT_Get(DEV_CFG_REGS->LPMSTAT);
    return status;
}

/*!
 * \brief Set CPU2 vtor function
 *
 * \details This function set cpu2 vtor, cpu2 start at these address
 *
 * \param[in] addr The cpu2 reset addr
 *
 */
static inline void SYSCTRL_setCPU2Vtor(uint32_t addr)
{
    DEV_CFG_REGS->CPU2INITVTOR = addr;
}

/*!
 * \brief Set SpiXip enable function
 *
 * \details This function set SpiXip enable
 *
 * \param[in] index The spi index
 * \param[in] xipEn The SpiXip enable or disable
 *
 */
static inline void SYSCTRL_setSpiXipEn(SYSCTRL_SPIIndex_t index, SYSCTRL_En_t xipEn)
{
    uint32_t regval;

    regval = DEV_CFG_REGS->SPIXIPENABLE;
    if (index == kSYSC_INDEX_SPIA)
    {
        regval &= ~DEV_CFG_REGS_SPIXIPENABLE_SPI_A_XIP_EN_Msk;
        regval |= DEV_CFG_REGS_SPIXIPENABLE_SPI_A_XIP_EN_Set(xipEn);
    }
    else if (index == kSYSC_INDEX_SPIB)
    {
        regval &= ~DEV_CFG_REGS_SPIXIPENABLE_SPI_B_XIP_EN_Msk;
        regval |= DEV_CFG_REGS_SPIXIPENABLE_SPI_B_XIP_EN_Set(xipEn);
    }
    else if (index == kSYSC_INDEX_SPIC)
    {
        regval &= ~DEV_CFG_REGS_SPIXIPENABLE_SPI_C_XIP_EN_Msk;
        regval |= DEV_CFG_REGS_SPIXIPENABLE_SPI_C_XIP_EN_Set(xipEn);
    }
    DEV_CFG_REGS->SPIXIPENABLE = regval;
}


/*!
 * \brief set intosc1trim
 *
 * \details this function is set intosc1trim.
 *
 * \param[in] data The trim data
 *
 */
static inline void SYSCTRL_setIntOsc1Trim(uint32_t data)
{
    ANALOG_SUBSYS_REGS->INTOSC1TRIM = data;
}

/*!
 * \brief set intosc2trim
 *
 * \details this function is set intosc2trim.
 *
 * \param[in] data The trim data
 *
 */
static inline void SYSCTRL_setIntOsc2Trim(uint32_t data)
{
    ANALOG_SUBSYS_REGS->INTOSC2TRIM = data;
}

/*!
 * \brief Set TSNSCTL function
 *
 * \details This function set TSNSCTL
 *
 * \param[in] en The TSNSCTL enable or disable
 *
 */
static inline void SYSCTRL_setTSNSCTL(SYSCTRL_En_t en)
{
    if (en == kSYSC_DISABLE)
        ANALOG_SUBSYS_REGS->TSNSCTL &= ~ANALOG_SUBSYS_REGS_TSNSCTL_TS_ENABLE_Msk;
    else
        ANALOG_SUBSYS_REGS->TSNSCTL |= ANALOG_SUBSYS_REGS_TSNSCTL_TS_ENABLE_Set(0x01U);
}

/*!
 * \brief Get TSNSCTL status function
 *
 * \details This function get cTSNSCTL status
 *
 * \return Return The TSNSCTL status
 *
 */
static inline bool SYSCTRL_getTSNSCTL(void)
{
    if (ANALOG_SUBSYS_REGS->TSNSCTL & ANALOG_SUBSYS_REGS_TSNSCTL_TS_ENABLE_Msk)
        return true;
    else
        return false;
}

/*!
 * \brief Set TSNLock function
 *
 * \details This function set TSNLock
 *
 * \param[in] en The TSNLock enable or disable
 *
 */
static inline void SYSCTRL_setTSNLock(SYSCTRL_En_t en)
{
    if (en == kSYSC_DISABLE)
        ANALOG_SUBSYS_REGS->LOCK &= ~ANALOG_SUBSYS_REGS_LOCK_TSNSCTL_Msk;
    else
        ANALOG_SUBSYS_REGS->LOCK |= ANALOG_SUBSYS_REGS_LOCK_TSNSCTL_Set(0x01U);
}
#endif

/*!
 * \brief set clk sem value
 *
 * \details this function is set clk sem value, provides a mechanism to acquire
 *     all the CLKCFG registers (except this register) by CPU0 or CPU1.
 *
 * \param[in] sem The sem data, A value of 00, 10, 11 gives ownership to CPU0.
 *     A value of 01 gives ownership to CPU1.
 *
 */
static inline void SYSCTRL_setClkSem(SYSCTRL_ClkSem_t sem)
{
    uint32_t reg_val;
    reg_val              = SYSCTL_CLKSEM_KEY | (uint32_t)sem;
    CLK_CFG_REGS->CLKSEM = reg_val;
}

/*!
 * \brief Lock clk config
 *
 * \details this function is lock clk config
 *
 * \param[in] regNum The reg index Num
 *
 */

static inline void SYSCTRL_lockClkCfg(SYSCTRL_ClkCfgLock_t regNum)
{
    if (regNum == kSYSC_LOCK_CLKCFGLOCKMAX)
        CLK_CFG_REGS->CLKCFGLOCK1 = 0xBCCF;
    else
        CLK_CFG_REGS->CLKCFGLOCK1 |= (0x01UL << regNum);
}


/*!
 * \brief Turns on the specified oscillator sources.
 *
 * \details This function turns on the oscillator specified by the \e oscSource
 *    parameter which may take a value of  \b SYSCTL_OSCSRC_XTAL
 *
 * \param[in] oscSource is the oscillator source to be configured.
 *
 */
static inline void SYSCTRL_turnOnOsc(SYSCTRL_OscSrcSel_t oscSource)
{
    switch (oscSource)
    {
        case kSYSC_OSCSRC_INTOSC2:
            //
            // Turn on INTOSC2
            //
            CLK_CFG_REGS->CLKSRCCTL1 &= ~CLK_CFG_REGS_CLKSRCCTL1_INTOSC2OFF_Msk;
            break;

        case kSYSC_OSCSRC_XTAL:
            //
            // Turn on XTALOSC
            //
            CLK_CFG_REGS->CLKSRCCTL1 &= ~CLK_CFG_REGS_CLKSRCCTL1_XTALOFF_Msk;
            break;
        default:
            //
            // Do nothing. Not a valid oscSource value.
            //
            break;
    }
}

/*!
 * \brief Turns off the specified oscillator sources.
 *
 * \details This function turns off the oscillator specified by the \e oscSource
 *    parameter which may take a value of  \b SYSCTL_OSCSRC_XTAL
 *
 * \param[in] oscSource is the oscillator source to be configured.
 *
 */
static inline void SYSCTRL_turnOffOsc(SYSCTRL_OscSrcSel_t oscSource)
{
    switch (oscSource)
    {
        case kSYSC_OSCSRC_INTOSC2:
            //
            // Turn on INTOSC2
            //
            CLK_CFG_REGS->CLKSRCCTL1 |= CLK_CFG_REGS_CLKSRCCTL1_INTOSC2OFF_Set(0x01U);
            break;

        case kSYSC_OSCSRC_XTAL:
            //
            // Turn on XTALOSC
            //
            CLK_CFG_REGS->CLKSRCCTL1 |= CLK_CFG_REGS_CLKSRCCTL1_XTALOFF_Set(0x01U);
            break;
        default:
            //
            // Do nothing. Not a valid oscSource value.
            //
            break;
    }
}

/*!
 * \brief select the specified oscillator sources.
 *
 * \details This function select the oscillator
 *
 * \param[in] oscSource is the oscillator source to be configured.
 *
 */
static inline void SYSCTRL_selOscClkSrc(SYSCTRL_OscSrcSel_t oscSource)
{
    uint32_t regval;

    regval                    = CLK_CFG_REGS->CLKSRCCTL1;
    regval                   &= ~CLK_CFG_REGS_CLKSRCCTL1_OSCCLKSRCSEL_Msk;
    regval                   |= CLK_CFG_REGS_CLKSRCCTL1_OSCCLKSRCSEL_Set(oscSource);
    CLK_CFG_REGS->CLKSRCCTL1  = regval;
}

/*!
 * \brief get the specified oscillator sources.
 *
 * \details This function get the oscillator
 *
 *\return oscSource is the oscillator source.
 */
static inline SYSCTRL_OscSrcSel_t SYSCTRL_getOscClkSrc(void)
{
    SYSCTRL_OscSrcSel_t oscSource;
    oscSource = (SYSCTRL_OscSrcSel_t)(CLK_CFG_REGS_CLKSRCCTL1_OSCCLKSRCSEL_Get(CLK_CFG_REGS->CLKSRCCTL1));
    return oscSource;
}

/*!
 * \brief select the xtal driver.
 *
 * \details This function set xtal driver
 *
 * \param[in] value is the xtal driver value.
 *
 */
static inline void SYSCTRL_setXTALDriver(uint8_t value)
{
    uint32_t regval;

    regval                    = CLK_CFG_REGS->CLKSRCCTL1;
    regval                   &= ~CLK_CFG_REGS_CLKSRCCTL1_XTAL_DS_Msk;
    regval                   |= CLK_CFG_REGS_CLKSRCCTL1_XTAL_DS_Set(value);
    CLK_CFG_REGS->CLKSRCCTL1  = regval;
}

/*!
 * \brief select the aux oscillator sources.
 *
 * \details This function select the aux osc source.
 *
 * \param[in] auxSrc is the oscillator source to be configured.
 *
 */
static inline void SYSCTRL_selAuxClkSrc(SYSCTRL_AuxSrcSel_t auxSrc)
{
    uint32_t regval;

    regval                    = CLK_CFG_REGS->CLKSRCCTL2;
    regval                   &= ~CLK_CFG_REGS_CLKSRCCTL2_AUXOSCCLKSRCSEL_Msk;
    regval                   |= CLK_CFG_REGS_CLKSRCCTL2_AUXOSCCLKSRCSEL_Set(auxSrc);
    CLK_CFG_REGS->CLKSRCCTL2  = regval;
}

/*!
 * \brief get the aux oscillator sources.
 *
 * \details This function get the aux osc source.
 *
 * \return auxSrc is the oscillator source to be configured.
 *
 */
static inline SYSCTRL_AuxSrcSel_t SYSCTRL_gelAuxClkSrc(void)
{
    SYSCTRL_AuxSrcSel_t srcSel;

    srcSel = (SYSCTRL_AuxSrcSel_t)CLK_CFG_REGS_CLKSRCCTL2_AUXOSCCLKSRCSEL_Set(CLK_CFG_REGS->CLKSRCCTL2);
    return srcSel;
}

/*!
 * \brief select the CAN BCLK sources.
 *
 * \details This function select CAN BCLK sources
 *
 * \param[in] index is the can index.
 * \param[in] src is the oscillator source.
 *
 */
static inline void SYSCTRL_selCANBClkSrc(SYSCTRL_CANIndex_t index, SYSCTRL_CANBclkSrcSel_t src)
{
    uint32_t regval;

    regval = CLK_CFG_REGS->CLKSRCCTL2;
    if (index == kSYSC_INDEX_CANA)
    {
        regval &= ~CLK_CFG_REGS_CLKSRCCTL2_CANABCLKSEL_Msk;
        regval |= CLK_CFG_REGS_CLKSRCCTL2_CANABCLKSEL_Set(src);
    }
    else if (index == kSYSC_INDEX_CANB)
    {
        regval &= ~CLK_CFG_REGS_CLKSRCCTL2_CANBBCLKSEL_Msk;
        regval |= CLK_CFG_REGS_CLKSRCCTL2_CANBBCLKSEL_Set(src);
    }
    else if (index == kSYSC_INDEX_CANC)
    {
        regval &= ~CLK_CFG_REGS_CLKSRCCTL2_CANCBCLKSEL_Msk;
        regval |= CLK_CFG_REGS_CLKSRCCTL2_CANCBCLKSEL_Set(src);
    }
    CLK_CFG_REGS->CLKSRCCTL2 = regval;
}

/*!
 * \brief select the SPI CLK sources.
 *
 * \details This function select SPI CLK sources
 *
 * \param[in] index is the spi index.
 * \param[in] src is the oscillator source.
 *
 */
static inline void SYSCTRL_selSPIClkSrc(SYSCTRL_SPIIndex_t index, SYSCTRL_SPIclkSrcSel_t src)
{
    uint32_t regval;

    regval = CLK_CFG_REGS->CLKSRCCTL2;
    if (index == kSYSC_INDEX_SPIA)
    {
        regval &= ~CLK_CFG_REGS_CLKSRCCTL2_SPIACLKSEL_Msk;
        regval |= CLK_CFG_REGS_CLKSRCCTL2_SPIACLKSEL_Set(src);
    }
    else if (index == kSYSC_INDEX_SPIB)
    {
        regval &= ~CLK_CFG_REGS_CLKSRCCTL2_SPIBCLKSEL_Msk;
        regval |= CLK_CFG_REGS_CLKSRCCTL2_SPIBCLKSEL_Set(src);
    }
    else if (index == kSYSC_INDEX_SPIC)
    {
        regval &= ~CLK_CFG_REGS_CLKSRCCTL2_SPICCLKSEL_Msk;
        regval |= CLK_CFG_REGS_CLKSRCCTL2_SPICCLKSEL_Set(src);
    }
    CLK_CFG_REGS->CLKSRCCTL2 = regval;
}

/*!
 * \brief Selects a clock source to mux to an external GPIO pin (XCLKOUT).
 *
 * \details This function configures the specified clock source to be muxed to an
 *     external clock out (XCLKOUT) GPIO pin. The \e source parameter may take a
 *     value of one of the following values:
 *
 * \param[in] source is the internal clock source to be configured.
 *
 */
static inline void SYSCTRL_selectClockOutSource(SYSCTRL_XCLKOutSel_t source)
{
    uint32_t regval;

    regval                    = CLK_CFG_REGS->CLKSRCCTL3;
    regval                   &= ~CLK_CFG_REGS_CLKSRCCTL3_XCLKOUTSEL_Msk;
    regval                   |= CLK_CFG_REGS_CLKSRCCTL3_XCLKOUTSEL_Set(source);
    CLK_CFG_REGS->CLKSRCCTL3  = regval;
}

/*!
 * \brief Set pll en .
 *
 * \details This function set pll enable.
 *
 *
 * \param[in] pllEn is the enable flag
 *
 */
static inline void SYSCTRL_setPLLEn(SYSCTRL_En_t pllEn)
{
    if (pllEn == kSYSC_DISABLE)
        CLK_CFG_REGS->SYSPLLCTL1 &= ~CLK_CFG_REGS_SYSPLLCTL1_PLLEN_Msk;
    else
        CLK_CFG_REGS->SYSPLLCTL1 |= CLK_CFG_REGS_SYSPLLCTL1_PLLEN_Set(0x01U);
}

/*!
 * \brief Set pll sys en .
 *
 * \details This function set pll sys enable.
 *
 *
 * \param[in] pllsysEn is the enable flag
 *
 */
static inline void SYSCTRL_setPLLClkEn(SYSCTRL_En_t pllsysEn)
{
    if (pllsysEn == kSYSC_DISABLE)
        CLK_CFG_REGS->SYSPLLCTL1 &= ~CLK_CFG_REGS_SYSPLLCTL1_PLLCLKEN_Msk;
    else
        CLK_CFG_REGS->SYSPLLCTL1 |= CLK_CFG_REGS_SYSPLLCTL1_PLLCLKEN_Set(0x01U);
}

/*!
 * \brief Get pll en .
 *
 * \details This function get pll enable.
 *
 *
 * \return Return The pll enable status
 *
 */
static inline bool SYSCTRL_getPLLEn(void)
{
    if (CLK_CFG_REGS_SYSPLLCTL1_PLLEN_Set(CLK_CFG_REGS->SYSPLLCTL1))
        return true;
    else
        return false;
}

/*!
 * \brief Get pll clk en .
 *
 * \details This function get pll clk enable.
 *
 *
 * \return Return The sys pll enable status
 *
 */
static inline bool SYSCTRL_getPLLClkEn(void)
{
    if (CLK_CFG_REGS_SYSPLLCTL1_PLLCLKEN_Get(CLK_CFG_REGS->SYSPLLCTL1))
        return true;
    else
        return false;
}

/*!
 * \brief Set pll ldo en .
 *
 * \details This function set pll ldo enable.
 *
 *
 * \param[in] pllLdoEn is the enable flag
 *
 */
static inline void SYSCTRL_setPLLLDOEn(SYSCTRL_En_t pllLdoEn)
{
    if (pllLdoEn == kSYSC_DISABLE)
        CLK_CFG_REGS->SYSPLLCTL1 &= ~CLK_CFG_REGS_SYSPLLCTL1_PLL_LDO_EN_Msk;
    else
        CLK_CFG_REGS->SYSPLLCTL1 |= CLK_CFG_REGS_SYSPLLCTL1_PLL_LDO_EN_Set(0x01U);
}

/*!
 * \brief Set pll lpf .
 *
 * \details This function set pll lpf.
 *
 *
 * \param[in] value is the pll lpf value
 *
 */
static inline void SYSCTRL_setPLLLpf(uint32_t value)
{
    CLK_CFG_REGS->SYSPLLCTL1 &= ~CLK_CFG_REGS_SYSPLLCTL1_PLL_LPF_Msk;
    CLK_CFG_REGS->SYSPLLCTL1 |= CLK_CFG_REGS_SYSPLLCTL1_PLL_LPF_Set(value);
}

/*!
 * \brief Set pll icp .
 *
 * \details This function set pll icp.
 *
 *
 * \param[in] value is the pll icp value
 *
 */
static inline void SYSCTRL_setPLLIcp(uint32_t value)
{
    CLK_CFG_REGS->SYSPLLCTL1 &= ~CLK_CFG_REGS_SYSPLLCTL1_PLL_ICP_Msk;
    CLK_CFG_REGS->SYSPLLCTL1 |= CLK_CFG_REGS_SYSPLLCTL1_PLL_ICP_Set(value);
}

/*!
 * \brief Set high freq band .
 *
 * \details This function set pll high frequecy band.
 *
 *
 * \param[in] setEn is the enable flag
 *
 */
static inline void SYSCTRL_setPLLHighFreqBand(SYSCTRL_En_t setEn)
{
    if (setEn == kSYSC_DISABLE)
        CLK_CFG_REGS->SYSPLLCTL1 &= ~CLK_CFG_REGS_SYSPLLCTL1_PLL_VCO_BAND_Msk;
    else
        CLK_CFG_REGS->SYSPLLCTL1 |= CLK_CFG_REGS_SYSPLLCTL1_PLL_VCO_BAND_Set(0x01U);
}

/*!
 * \brief Set pll CLKREF div .
 *
 * \details This function set pll CLKREF DIV.
 *
 *
 * \param[in] value is the pll ref value
 *
 */
static inline void SYSCTRL_setPLLClkRefDiv(uint32_t value)
{
    CLK_CFG_REGS->SYSPLLCTL1 &= ~CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_DIV_Msk;
    CLK_CFG_REGS->SYSPLLCTL1 |= CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_DIV_Set(value);
}

/*!
 * \brief Set fref .
 *
 * \details This function set pll fref div.
 *
 *
 * \param[in] setEn is the enable flag
 *
 */
static inline void SYSCTRL_setPLLCkRefSel(SYSCTRL_En_t setEn)
{
    if (setEn == kSYSC_DISABLE)
        CLK_CFG_REGS->SYSPLLCTL1 &= ~CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_SEL_Msk;
    else
        CLK_CFG_REGS->SYSPLLCTL1 |= CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_SEL_Set(0x01U);
}

/*!
 * \brief get pll CLKREF div .
 *
 * \details This function Get pll CLKREF DIV.
 *
 *
 * \return Return The pll ref divide value
 *
 */
static inline uint32_t SYSCTRL_getPLLClkRefDiv(void)
{
    return CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_DIV_Get(CLK_CFG_REGS->SYSPLLCTL1);
}

/*!
 * \brief Get fref .
 *
 * \details This function get pll fref div.
 *
 *
 * \return Return The pll ref sel status
 *
 */
static inline bool SYSCTRL_getPLLCkRefSel(void)
{
    if (CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_SEL_Get(CLK_CFG_REGS->SYSPLLCTL1))
        return true;
    else
        return false;
}

/*!
 * \brief set pll reset .
 *
 * \details This function set pll reset.
 * \param[in] setEn is the enable flag
 */
static inline void SYSCTRL_resetPLL(SYSCTRL_En_t setEn)
{
    if (setEn == kSYSC_ENABLE)
        CLK_CFG_REGS->SYSPLLCTL1 &= ~CLK_CFG_REGS_SYSPLLCTL1_LDO_RSTB_Msk;
    else
        CLK_CFG_REGS->SYSPLLCTL1 |= CLK_CFG_REGS_SYSPLLCTL1_LDO_RSTB_Set(0x01U);
}

/*!
 * \brief set pll order sel .
 *
 * \details This function set pll order sel.
 * \param[in] setEn is the enable flag
 */
static inline void SYSCTRL_setPLLOrderSel(SYSCTRL_En_t setEn)
{
    if (setEn == kSYSC_DISABLE)
        CLK_CFG_REGS->SYSPLLMULT &= ~CLK_CFG_REGS_SYSPLLMULT_ORDER_Msk;
    else
        CLK_CFG_REGS->SYSPLLMULT |= CLK_CFG_REGS_SYSPLLMULT_ORDER_Set(0x01U);
}

/*!
 * \brief bypass pi .
 *
 * \details This function bypass pll pi.
 * \param[in] setEn is the enable flag
 */
static inline void SYSCTRL_bypassPLLPi(SYSCTRL_En_t setEn)
{
    if (setEn == kSYSC_DISABLE)
        CLK_CFG_REGS->SYSPLLMULT &= ~CLK_CFG_REGS_SYSPLLMULT_BYPASS_PI_Msk;
    else
        CLK_CFG_REGS->SYSPLLMULT |= CLK_CFG_REGS_SYSPLLMULT_BYPASS_PI_Set(0x01U);
}

/*!
 * \brief get bypass pi .
 *
 * \details This function get pll pi.
 * \return Return the pll pi value
 */
static inline uint32_t SYSCTRL_getPLLPi(void)
{
    return CLK_CFG_REGS_SYSPLLMULT_BYPASS_PI_Get(CLK_CFG_REGS->SYSPLLMULT);
}

/*!
 * \brief Set FCW_SSC Dec point.
 *
 * \details This function Set FCW_SSC Decimal point
 *
 * \param[in] decValue is the decimal point value
 *
 */
static inline void SYSCTRL_setPLLFcwSscDecPoint(SYSCTRL_FCWDecPoint_t decValue)
{
    uint32_t regval;

    regval                    = CLK_CFG_REGS->SYSPLLMULT;
    regval                   &= ~CLK_CFG_REGS_SYSPLLMULT_REG_DOT_FCW_Msk;
    regval                   |= CLK_CFG_REGS_SYSPLLMULT_REG_DOT_FCW_Set(decValue);
    CLK_CFG_REGS->SYSPLLMULT  = regval;
}

/*!
 * \brief Get FCW_SSC dec point value.
 *
 * \details This function Get FCW_SSC dec point value
 *
 * \return Return the FCW_SSC dec point value
 *
 */
static inline uint32_t SYSCTRL_getPLLFcwSscDecPoint(void)
{
    return CLK_CFG_REGS_SYSPLLMULT_REG_DOT_FCW_Get(CLK_CFG_REGS->SYSPLLMULT);
}

/*!
 * \brief Set FCW_SSC value.
 *
 * \details This function Set FCW_SSC value
 *
 * \param[in] value is the FCW_SSC value
 *
 */
static inline void SYSCTRL_setPLLFcwSsc(uint32_t value)
{
    uint32_t regval;

    regval                    = CLK_CFG_REGS->SYSPLLMULT;
    regval                   &= ~CLK_CFG_REGS_SYSPLLMULT_FCW_SSC_Msk;
    regval                    |= CLK_CFG_REGS_SYSPLLMULT_FCW_SSC_Set(value);
    CLK_CFG_REGS->SYSPLLMULT  = regval;
}

/*!
 * \brief Get FCW_SSC value.
 *
 * \details This function Get FCW_SSC value
 *
 * \return Return the FCW_SSC value
 *
 */
static inline uint32_t SYSCTRL_getPLLFcwSsc(void)
{
    return CLK_CFG_REGS_SYSPLLMULT_FCW_SSC_Set(CLK_CFG_REGS->SYSPLLMULT);
}

/*!
 * \brief Get SYS PLL lock status
 *
 * \details This function get sys pll lock status
 *
 * \return Return The sys pll lock status
 *
 */
static inline bool SYSCTRL_getPLLLockStatus(void)
{
    if (CLK_CFG_REGS_SYSPLLSTS_LOCKS_Get(CLK_CFG_REGS->SYSPLLSTS))
        return true;
    else
        return false;
}

/*!
 * \brief Set aux pll en .
 *
 * \details This function set aux pll enable.
 *
 *
 * \param[in] pllEn is the enable flag
 *
 */
static inline void SYSCTRL_setAuxPLLEn(SYSCTRL_En_t pllEn)
{
    if (pllEn == kSYSC_DISABLE)
        CLK_CFG_REGS->AUXPLLCTL1 &= ~CLK_CFG_REGS_AUXPLLCTL1_PLLEN_Msk;
    else
        CLK_CFG_REGS->AUXPLLCTL1 |= CLK_CFG_REGS_AUXPLLCTL1_PLLEN_Set(0x01U);
}

/*!
 * \brief Set aux pll sys en .
 *
 * \details This function set aux pll sys enable.
 *
 *
 * \param[in] pllsysEn is the enable flag
 *
 */
static inline void SYSCTRL_setAuxPLLClkEn(SYSCTRL_En_t pllsysEn)
{
    if (pllsysEn == kSYSC_DISABLE)
        CLK_CFG_REGS->AUXPLLCTL1 &= ~CLK_CFG_REGS_AUXPLLCTL1_PLLCLKEN_Msk;
    else
        CLK_CFG_REGS->AUXPLLCTL1 |= CLK_CFG_REGS_AUXPLLCTL1_PLLCLKEN_Set(0x01U);
}

/*!
 * \brief Get Aux pll en .
 *
 * \details This function get Aux pll enable.
 *
 *
 * \return Return The pll enable status
 *
 */
static inline bool SYSCTRL_getAuxPLLEn(void)
{
    if (CLK_CFG_REGS_AUXPLLCTL1_PLLEN_Set(CLK_CFG_REGS->AUXPLLCTL1))
        return true;
    else
        return false;
}

/*!
 * \brief Get pll Aux clk en .
 *
 * \details This function get aux pll clk enable.
 *
 *
 * \return Return The sys pll enable status
 *
 */
static inline bool SYSCTRL_getAuxPLLClkEn(void)
{
    if (CLK_CFG_REGS_AUXPLLCTL1_PLLCLKEN_Get(CLK_CFG_REGS->AUXPLLCTL1))
        return true;
    else
        return false;
}

/*!
 * \brief Set aux pll ldo en .
 *
 * \details This function set aux pll ldo enable.
 *
 *
 * \param[in] pllLdoEn is the enable flag
 *
 */
static inline void SYSCTRL_setAuxPLLLDOEn(SYSCTRL_En_t pllLdoEn)
{
    if (pllLdoEn == kSYSC_DISABLE)
        CLK_CFG_REGS->AUXPLLCTL1 &= ~CLK_CFG_REGS_AUXPLLCTL1_PLL_LDO_EN_Msk;
    else
        CLK_CFG_REGS->AUXPLLCTL1 |= CLK_CFG_REGS_AUXPLLCTL1_PLL_LDO_EN_Set(0x01U);
}

/*!
 * \brief Set aux pll lpf .
 *
 * \details This function set aux pll lpf.
 *
 *
 * \param[in] value is the aux pll lpf value
 *
 */
static inline void SYSCTRL_setAuxPLLLpf(uint32_t value)
{
    CLK_CFG_REGS->AUXPLLCTL1 &= ~CLK_CFG_REGS_AUXPLLCTL1_PLL_LPF_Msk;
    CLK_CFG_REGS->AUXPLLCTL1 |= CLK_CFG_REGS_AUXPLLCTL1_PLL_LPF_Set(value);
}

/*!
 * \brief Set aux pll icp .
 *
 * \details This function set aux pll icp.
 *
 *
 * \param[in] value is the aux pll icp value
 *
 */
static inline void SYSCTRL_setAuxPLLIcp(uint32_t value)
{
    CLK_CFG_REGS->AUXPLLCTL1 &= ~CLK_CFG_REGS_AUXPLLCTL1_PLL_ICP_Msk;
    CLK_CFG_REGS->AUXPLLCTL1 |= CLK_CFG_REGS_AUXPLLCTL1_PLL_ICP_Set(value);
}

/*!
 * \brief Set high freq band .
 *
 * \details This function set aux pll high frequecy band.
 *
 *
 * \param[in] setEn is the enable flag
 *
 */
static inline void SYSCTRL_setAuxPLLHighFreqBand(SYSCTRL_En_t setEn)
{
    if (setEn == kSYSC_DISABLE)
        CLK_CFG_REGS->AUXPLLCTL1 &= ~CLK_CFG_REGS_AUXPLLCTL1_PLL_VCO_BAND_Msk;
    else
        CLK_CFG_REGS->AUXPLLCTL1 |= CLK_CFG_REGS_AUXPLLCTL1_PLL_VCO_BAND_Set(0x01U);
}

/*!
 * \brief Set aux pll CLKREF div .
 *
 * \details This function set aux pll CLKREF DIV.
 *
 *
 * \param[in] value is the aux pll ref value
 *
 */
static inline void SYSCTRL_setAuxPLLClkRefDiv(uint32_t value)
{
    CLK_CFG_REGS->AUXPLLCTL1 &= ~CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_DIV_Msk;
    CLK_CFG_REGS->AUXPLLCTL1 |= CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_DIV_Set(value);
}

/*!
 * \brief Set fref .
 *
 * \details This function set aux pll fref div.
 *
 *
 * \param[in] setEn is the enable flag
 *
 */
static inline void SYSCTRL_setAuxPLLCkRefSel(SYSCTRL_En_t setEn)
{
    if (setEn == kSYSC_DISABLE)
        CLK_CFG_REGS->AUXPLLCTL1 &= ~CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_SEL_Msk;
    else
        CLK_CFG_REGS->AUXPLLCTL1 |= CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_SEL_Set(0x01U);
}

/*!
 * \brief get Aux pll CLKREF div .
 *
 * \details This function Get Aux pll CLKREF DIV.
 *
 *
 * \return Return The Aux pll ref divide value
 *
 */
static inline uint32_t SYSCTRL_getAuxPLLClkRefDiv(void)
{
    return CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_DIV_Get(CLK_CFG_REGS->SYSPLLCTL1);
}

/*!
 * \brief Get Aux fref .
 *
 * \details This function get Aux pll fref div.
 *
 *
 * \return Return The Aux pll ref sel status
 *
 */
static inline bool SYSCTRL_getAuxPLLCkRefSel(void)
{
    if (CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_SEL_Set(CLK_CFG_REGS->SYSPLLCTL1))
        return true;
    else
        return false;
}

/*!
 * \brief set aux pll reset .
 *
 * \details This function set pll reset.
 * \param[in] setEn is the enable flag
 */
static inline void SYSCTRL_resetAuxPLL(SYSCTRL_En_t setEn)
{
    if (setEn == kSYSC_ENABLE)
        CLK_CFG_REGS->AUXPLLCTL1 &= ~CLK_CFG_REGS_AUXPLLCTL1_LDO_RSTB_Msk;
    else
        CLK_CFG_REGS->AUXPLLCTL1 |= CLK_CFG_REGS_AUXPLLCTL1_LDO_RSTB_Set(0x01U);
}

/*!
 * \brief set aux pll order sel .
 *
 * \details This function set aux pll order sel.
 * \param[in] setEn is the enable flag
 */
static inline void SYSCTRL_setAuxPLLOrderSel(SYSCTRL_En_t setEn)
{
    if (setEn == kSYSC_DISABLE)
        CLK_CFG_REGS->AUXPLLMULT &= ~CLK_CFG_REGS_AUXPLLMULT_ORDER_Msk;
    else
        CLK_CFG_REGS->AUXPLLMULT |= CLK_CFG_REGS_AUXPLLMULT_ORDER_Set(0x01U);
}

/*!
 * \brief bypass pi .
 *
 * \details This function bypass aux pll pi.
 * \param[in] setEn is the enable flag
 */
static inline void SYSCTRL_bypassAuxPLLPi(SYSCTRL_En_t setEn)
{
    if (setEn == kSYSC_DISABLE)
        CLK_CFG_REGS->AUXPLLMULT &= ~CLK_CFG_REGS_AUXPLLMULT_BYPASS_PI_Msk;
    else
        CLK_CFG_REGS->AUXPLLMULT |= CLK_CFG_REGS_AUXPLLMULT_BYPASS_PI_Set(0x01U);
}

/*!
 * \brief get bypass pi .
 *
 * \details This function get pll pi.
 * \return Return the pll pi value
 */
static inline uint32_t SYSCTRL_geAuxtPLLPi(void)
{
    return CLK_CFG_REGS_AUXPLLMULT_BYPASS_PI_Get(CLK_CFG_REGS->AUXPLLMULT);
}

/*!
 * \brief Set aux FCW_SSC Dec point.
 *
 * \details This function Set aux FCW_SSC Decimal point
 *
 * \param[in] decValue is the decimal point value
 *
 */
static inline void SYSCTRL_setAuxPLLFcwSscDecPoint(SYSCTRL_FCWDecPoint_t decValue)
{
    uint32_t regval;

    regval                    = CLK_CFG_REGS->AUXPLLMULT;
    regval                   &= ~CLK_CFG_REGS_AUXPLLMULT_REG_DOT_FCW_Msk;
    regval                   |= CLK_CFG_REGS_AUXPLLMULT_REG_DOT_FCW_Set(decValue);
    CLK_CFG_REGS->AUXPLLMULT  = regval;
}

/*!
 * \brief Get FCW_SSC dec point value.
 *
 * \details This function Get FCW_SSC dec point value
 *
 * \return Return the FCW_SSC dec point value
 *
 */
static inline uint32_t SYSCTRL_getAuxPLLFcwSscDecPoint(void)
{
    return CLK_CFG_REGS_AUXPLLMULT_REG_DOT_FCW_Get(CLK_CFG_REGS->AUXPLLMULT);
}


/*!
 * \brief Set aux FCW_SSC value.
 *
 * \details This function Set aux FCW_SSC value
 *
 * \param[in] value is the FCW_SSC value
 *
 */
static inline void SYSCTRL_setAuxPLLFcwSsc(uint32_t value)
{
    uint32_t regval;

    regval                    = CLK_CFG_REGS->AUXPLLMULT;
    regval                   &= ~CLK_CFG_REGS_AUXPLLMULT_FCW_SSC_Msk;
    regval                    |= CLK_CFG_REGS_AUXPLLMULT_FCW_SSC_Set(value);
    CLK_CFG_REGS->AUXPLLMULT  = regval;
}

/*!
 * \brief Get AUX FCW_SSC value.
 *
 * \details This function Get AUX FCW_SSC value
 *
 * \return Return the FCW_SSC value
 *
 */
static inline uint32_t SYSCTRL_getAuxPLLFcwSsc(void)
{
    return CLK_CFG_REGS_AUXPLLMULT_FCW_SSC_Set(CLK_CFG_REGS->AUXPLLMULT);
}

/*!
 * \brief Get aux PLL lock status
 *
 * \details This function get aux pll lock status
 *
 * \return Return The sys pll lock status
 *
 */
static inline bool SYSCTRL_getAuxPLLLockStatus(void)
{
    if (CLK_CFG_REGS_AUXPLLSTS_LOCKS_Get(CLK_CFG_REGS->AUXPLLSTS))
        return true;
    else
        return false;
}

/*!
 * \brief Set sys clk div sel.
 *
 * \details This function set sys clk div sel
 *
 * \param[in] value is the div value
 *
 */
static inline void SYSCTRL_setSysClkDivSel(uint32_t value)
{
    CLK_CFG_REGS->SYSCLKDIVSEL = value;
}

/*!
 * \brief Get sys clk div sel.
 *
 * \details This function get sys clk div sel
 *
 * \return value is the div value
 *
 */
static inline uint32_t SYSCTRL_getSysClkDivSel(void)
{
    return CLK_CFG_REGS_SYSCLKDIVSEL_PLLSYSCLKDIV_Get(CLK_CFG_REGS->SYSCLKDIVSEL);
}

/*!
 * \brief Set aux clk div sel.
 *
 * \details This function set aux clk div sel
 *
 * \param[in] value is the div value
 *
 */
static inline void SYSCTRL_setAuxClkDivSel(uint32_t value)
{
    CLK_CFG_REGS->AUXCLKDIVSEL = value;
}

/*!
 * \brief Get Aux clk div sel.
 *
 * \details This function get Aux clk div sel
 *
 * \return value is the div value
 *
 */
static inline uint32_t SYSCTRL_getAuxClkDivSel(void)
{
    return CLK_CFG_REGS_AUXCLKDIVSEL_AUXPLLDIV_Get(CLK_CFG_REGS->AUXCLKDIVSEL);
}

/*!
 * \brief Set emif clk div sel.
 *
 * \details This function set emif clk div sel
 *
 * \param[in] div is the div value
 *
 */
static inline void SYSCTRL_setEmifClkDiv(SYSCTRL_EmifClkDiv_t div)
{
    CLK_CFG_REGS->PERCLKDIVSEL &= ~CLK_CFG_REGS_PERCLKDIVSEL_EMIF1CLKDIV_Msk;
    CLK_CFG_REGS->PERCLKDIVSEL |= CLK_CFG_REGS_PERCLKDIVSEL_EMIF1CLKDIV_Set(div);
}

/*!
 * \brief Set XclkOut div sel.
 *
 * \details This function set XclkOut div sel
 *
 * \param[in] div is the div value
 *
 */
static inline void SYSCTRL_setXclkOutDiv(SYSCTRL_XclkOutDiv_t div)
{
    CLK_CFG_REGS->XCLKOUTDIVSEL &= ~CLK_CFG_REGS_XCLKOUTDIVSEL_XCLKOUTDIV_Msk;
    CLK_CFG_REGS->XCLKOUTDIVSEL |= CLK_CFG_REGS_XCLKOUTDIVSEL_XCLKOUTDIV_Set(div);
}

/*!
 * \brief Enable MCD check.
 *
 * \details This function enable MCD circuit enable
 *
 *
 */
static inline void SYSCTRL_enableMCD(void)
{
    CLK_CFG_REGS->MCDCR &= ~CLK_CFG_REGS_MCDCR_MCLKOFF_Msk;
}

/*!
 * \brief Disable MCD check.
 *
 * \details This function disable MCD circuit enable
 *
 *
 */
static inline void SYSCTRL_disableMCD(void)
{
    CLK_CFG_REGS->MCDCR |= CLK_CFG_REGS_MCDCR_MCLKOFF_Set(0x01U);
}

/*!
 * \brief Get mcd clock fail status
 *
 * \details This function get mcd clock fail status
 *
 * \return Return The mcd clock fail status
 *
 */
static inline bool SYSCTRL_isMCDClockFailureDetected(void)
{
    //
    //  Check the status bit to determine failure
    //
    return (CLK_CFG_REGS_MCDCR_MCLKSTS_Get(CLK_CFG_REGS->MCDCR) != 0U);
}

/*!
 * \brief clean MCD status
 *
 * \details This function Reset the missing clock detection logic after clock failure
 *
 *
 */
static inline void SYSCTRL_resetMCD(void)
{
    CLK_CFG_REGS->MCDCR |= CLK_CFG_REGS_MCDCR_MCLKCLR_Set(0x01U);
}

/*!
 * \brief connect mcd clock source
 *
 * \details This function Re-connect missing clock detection clock source to
 *  stop simulating clock failure
 *
 *
 */
static inline void SYSCTRL_connectMCDClockSource(void)
{
    CLK_CFG_REGS->MCDCR &= ~CLK_CFG_REGS_MCDCR_OSCOFF_Msk;
}

/*!
 * \brief disconnect mcd clock source
 *
 * \details This function disconnect missing clock detection clock source to
 *  stop simulating clock failure
 *
 *
 */
static inline void SYSCTRL_disconnectMCDClockSource(void)
{
    CLK_CFG_REGS->MCDCR |= CLK_CFG_REGS_MCDCR_OSCOFF_Set(0x01U);
}

/*!
 * \brief Get x1clk count
 *
 * \details This function get x1clk count
 *
 * \return Return The x1clk count
 *
 */
static inline uint32_t SYSCTRL_getX1ClkCnt(void)
{
    uint32_t regVal;
    regVal = CLK_CFG_REGS_X1CNT_X1CNT_Get(CLK_CFG_REGS->X1CNT);
    return regVal;
}


/*!
 * \brief lock cpu system Peripheral module function
 *
 * \details This function lock cpu system Peripheral module function
 *
 * \param[in] module The peripheral module item
 *
 */
static inline void SYSCTRL_lockCpuSys(SYSCTRL_CpuSysLock_t module)
{
    if (module == kSYSC_CPUSYS_LOCK_MAX)
    {
        CPU_SYS_REGS->CPUSYSLOCK1 = 0x1EFFFF8;
    }
    else
    {
        CPU_SYS_REGS->CPUSYSLOCK1 |= (0x01UL << module);
    }
}


/*!
 * \brief Enable Peripheral module function
 *
 * \details This function enable Peripheral pclkcr to enable Peripheral
 *
 * \param[in] peripheral The peripheral module value
 *
 */
static inline void SYSCTRL_enablePeripheral(SYSCTRL_PeripheralPclockCr_t peripheral)
{
    uint32_t           regIndex;
    uint32_t           bitIndex;
    volatile uint32_t *regAddr;


    // Decode the peripheral variable.
    regIndex = ((uint32_t)peripheral & (uint32_t)SYSCTL_PERIPH_REG_M) << SYSCTL_PERIPH_REG_S;
    bitIndex = ((uint32_t)peripheral & (uint32_t)SYSCTL_PERIPH_BIT_M) >> SYSCTL_PERIPH_BIT_S;

    regAddr = (volatile uint32_t *)(CPU_SYS_REGS_BASE + SYSC_PCLKCR0_OFFSET + regIndex);

    *regAddr |= (0x01UL << bitIndex);
}

/*!
 * \brief Disable Peripheral module function
 *
 * \details This function disable Peripheral pclkcr to disable Peripheral
 *
 * \param[in] peripheral The peripheral module value
 *
 */
static inline void SYSCTRL_disablePeripheral(SYSCTRL_PeripheralPclockCr_t peripheral)
{
    uint32_t           regIndex;
    uint32_t           bitIndex;
    volatile uint32_t *regAddr;


    // Decode the peripheral variable.
    regIndex = ((uint32_t)peripheral & (uint32_t)SYSCTL_PERIPH_REG_M) << SYSCTL_PERIPH_REG_S;
    bitIndex = ((uint32_t)peripheral & (uint32_t)SYSCTL_PERIPH_BIT_M) >> SYSCTL_PERIPH_BIT_S;

    regAddr = (volatile uint32_t *)(CPU_SYS_REGS_BASE + SYSC_PCLKCR0_OFFSET + regIndex);

    *regAddr &= ~(0x01UL << bitIndex);
}

/*!
 * \brief Set LPM wakeup clk num
 *
 * \details This function set clk num to wakeup from LPM
 *
 * \param[in] clkNum The wakeup clk num
 *
 */
static inline void SYSCTRL_setLpmWakeClkNum(uint32_t clkNum)
{
    CPU_SYS_REGS->LPMCR &= ~CPU_SYS_REGS_LPMCR_QUALSTDBY_Msk;
    CPU_SYS_REGS->LPMCR |= CPU_SYS_REGS_LPMCR_QUALSTDBY_Set(clkNum);
}

/*!
 * \brief Get LPM wakeup clk num
 *
 * \details This function get clk num to wakeup from LPM
 *
 * \return Return the clkNum The wakeup clk num
 *
 */
static inline uint32_t SYSCTRL_getLpmWakeClkNum(void)
{
    return CPU_SYS_REGS->LPMCR;
}


/*!
 * \brief Set LPM wakeup gpio pin
 *
 * \details This function set GPIO pin to wakeup from LPM
 *
 * \param[in] pinNum The wakeup gpio
 *
 */
static inline void SYSCTRL_setLpmWakePin(uint32_t pinNum)
{
    if (pinNum < 32)
    {
        CPU_SYS_REGS->GPIOLPMSEL0 |= (0x01UL << pinNum);
    }
    else if (pinNum < 64)
    {
        CPU_SYS_REGS->GPIOLPMSEL1 |= (0x01UL << (pinNum - 32));
    }
}

/*!
 * \brief Select CPUTIMER source
 *
 * \details This function select Cputimer clk source
 *
 * \param[in] source Cputimer clk source
 *
 */
static inline void SYSCTRL_selectCpuTimer2Source(SYSCTRL_TimerClockSource_t source)
{
    //
    // Set source for CPU Timer 2
    //
    // Set Clock Source
    //
    CPU_SYS_REGS->TMR2CLKCTL &= ~CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKSRCSEL_Msk;
    CPU_SYS_REGS->TMR2CLKCTL |= CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKSRCSEL_Set(source);
}

/*!
 * \brief Select CPUTIMER source div
 *
 * \details This function select Cputimer clk source div
 *
 * \param[in] prescaler The clk div
 *
 */
static inline void SYSCTRL_selectCpuTimer2Prescaler(SYSCTRL_TimerPrescaler_t prescaler)
{
    //
    // Set prescaler for CPU Timer 2
    //
    // Set Clock Prescaler
    //
    CPU_SYS_REGS->TMR2CLKCTL &= ~CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKPRESCALE_Msk;
    CPU_SYS_REGS->TMR2CLKCTL |= CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKPRESCALE_Set(prescaler);
}

/*!
 * \brief Select DW source
 *
 * \details This function select DW clk source
 *
 * \param[in] source DW clk source
 *
 */
static inline void SYSCTRL_selectDwTimer2Source(SYSCTRL_TimerClockSource_t source)
{
    //
    // Set source for DW Timer 2
    //
    // Set Clock Source
    //
    CPU_SYS_REGS->DWTMR2CLKCTL &= ~CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKSRCSEL_Msk;
    CPU_SYS_REGS->DWTMR2CLKCTL |= CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKSRCSEL_Set(source);
}

/*!
 * \brief Select DW source div
 *
 * \details This function select DW clk source div
 *
 * \param[in] prescaler The clk div
 *
 */
static inline void SYSCTRL_selectDwTimer2Prescaler(SYSCTRL_TimerPrescaler_t prescaler)
{
    //
    // Set prescaler for DW Timer 2
    //
    // Set Clock Prescaler
    //
    CPU_SYS_REGS->DWTMR2CLKCTL &= ~CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKPRESCALE_Msk;
    CPU_SYS_REGS->DWTMR2CLKCTL |= CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKPRESCALE_Set(prescaler);
}


/*!
 * \brief Get CPU reset cause function
 *
 * \details This function get cpu reset cause
 *
 * \return Return The cpu reset cause value
 *
 */
static inline uint32_t SYSCTRL_getResetCause(void)
{
    return CPU_SYS_REGS->RESC;
}

/*!
 * \brief Clear CPU reset cause function
 *
 * \details This function clean cpu reset cause
 *
 * \param[in] flag The reset cause flag
 *
 */
static inline void SYSCTRL_clearResetFlag(SYSCTRL_ResetCause_t flag)
{
    CPU_SYS_REGS->RESC |= (0x01UL << flag);
}

#if defined(HTE_DEVICE_HS32F7D377_CPU1)
/*!
 * \brief Enable TFU PCLKCR function
 *
 * \details This function enable TFU module
 *
 *
 */
static inline void SYSCTRL_enableTFU(void)
{
    CPU_SYS_REGS->TFUCR |= CPU_SYS_REGS_TFUCR_TFU_Set(0x01U);
}

/*!
 * \brief Disable TFU PCLKCR function
 *
 * \details This function disable TFU module
 *
 *
 */
static inline void SYSCTRL_disableTFU(void)
{
    CPU_SYS_REGS->TFUCR &= ~CPU_SYS_REGS_TFUCR_TFU_Set(0x01U);
}

/*!
 * \brief Enable CRC PCLKCR function
 *
 * \details This function enable CRC module
 *
 *
 */
static inline void SYSCTRL_enableCRC(void)
{
    CPU_SYS_REGS->CRCCR |= CPU_SYS_REGS_CRCCR_CRC_Set(0x01U);
}

/*!
 * \brief Disable CRC PCLKCR function
 *
 * \details This function disable CRC module
 *
 *
 */
static inline void SYSCTRL_disableCRC(void)
{
    CPU_SYS_REGS->CRCCR &= ~CPU_SYS_REGS_CRCCR_CRC_Set(0x01U);
}

/*!
 * \brief Lock gsram cfg register function
 *
 * \details This function lock gsram cfg register
 *
 * \param[in] gsramId The gram num ID
 * \param[in] lockEn The lock status
 *
 */
static inline void SYSCTRL_lockGsRamCfg(SYSCTRL_SramGs_t gsramId, SYSCTRL_En_t lockEn)
{
    uint32_t regVal = 0x00;

    if (gsramId == kSRAM_GSMAX)
    {
        if (lockEn == kSYSC_ENABLE)
            MEM_CFG_REGS->GSXLOCK = 0xFFFF;
        else
            MEM_CFG_REGS->GSXLOCK = 0x0;
    }
    else
    {
        regVal                 = MEM_CFG_REGS->GSXLOCK;
        regVal                &= (~(0x01UL << gsramId));
        regVal                |= (((uint32_t)lockEn) << gsramId);
        MEM_CFG_REGS->GSXLOCK  = regVal;
    }
}

/*!
 * \brief Lock gsram cfg register permanent function
 *
 * \details This function permanent lock gsram cfg register
 *
 * \param[in] gsramId The gram num ID
 *
 */
static inline void SYSCTRL_lockGsRamPermanent(SYSCTRL_SramGs_t gsramId)
{
    if (gsramId == kSRAM_GSMAX)
        MEM_CFG_REGS->GSXCOMMIT = 0xFFFF;
    else
        MEM_CFG_REGS->GSXCOMMIT |= (0x1UL << gsramId);
}

/*!
 * \brief Set gsram master sel function
 *
 * \details This function select core master to gsram
 *
 * \param[in] gsramId The gram num ID
 * \param[in] sel The core master select
 *
 */
static inline void SYSCTRL_setGsxMSel(SYSCTRL_SramGs_t gsramId, SYSCTRL_GsxmSel_t sel)
{
    uint32_t         regval = 0x00;
    uint8_t          offset;
    SYSCTRL_SramGs_t i;

    if (gsramId == kSRAM_GSMAX)
    {
        for (i = kSRAM_GS0; i < kSRAM_GSMAX; i++)
        {
            regval |= (((uint32_t)sel) << (i * 2));
        }
        MEM_CFG_REGS->GSXMSEL = regval;
    }
    else
    {
        offset                 = ((uint8_t)gsramId) * 2;
        regval                 = MEM_CFG_REGS->GSXMSEL;
        regval                &= (~(0x03UL << offset));
        regval                |= (((uint32_t)sel) << offset);
        MEM_CFG_REGS->GSXMSEL  = regval;
    }
}

/*!
 * \brief Get gsram master sel function
 *
 * \details This function get core master to gsram
 *
 * \param[in] gsramId The gram num ID
 * \return Return The Gsramx core master
 *
 */
static inline SYSCTRL_GsxmSel_t SYSCTRL_getGsxMSel(SYSCTRL_SramGs_t gsramId)
{
    uint32_t          regval = 0x00;
    uint8_t           offset;
    SYSCTRL_GsxmSel_t ret;

    if (gsramId == kSRAM_GSMAX)
    {
        ret = kCPU1_MASTER;
    }
    else
    {
        offset  = ((uint8_t)gsramId) * 2;
        regval  = MEM_CFG_REGS->GSXMSEL;
        regval &= (0x03UL << offset);
        ret     = (SYSCTRL_GsxmSel_t)(regval >> offset);
    }
    return ret;
}

/*!
 * \brief Config gsram access right
 *
 * \details This function Config gsram DMA/CPU access right
 *
 * \param[in] gsramId The gram num ID
 * \param[in] mode The gsram access mode
 * \param[in] permission The gsram access enable
 *
 */
static inline void SYSCTRL_cfgGsramAccess(SYSCTRL_SramGs_t gsramId, SYSCTRL_AccMode_t mode, SYSCTRL_AccEn_t permission)
{
    uint32_t regval = 0x00;
    uint8_t  gs_cnt, offset, reg_num;

    if (mode == kGS_ASSCESS_DMA)
        gs_cnt = 8 * gsramId + 2;
    else
        gs_cnt = 8 * gsramId + 1;

    offset  = gs_cnt % 32;
    reg_num = gs_cnt / 32;

    switch (reg_num)
    {
        case 0:
            regval                     = MEM_CFG_REGS->GSXACCPROT0;
            regval                    &= (~(0x01UL << offset));
            regval                    |= (((uint32_t)permission) << offset);
            MEM_CFG_REGS->GSXACCPROT0  = regval;
            break;
        case 1:
            regval                     = MEM_CFG_REGS->GSXACCPROT1;
            regval                    &= (~(0x01UL << offset));
            regval                    |= (((uint32_t)permission) << offset);
            MEM_CFG_REGS->GSXACCPROT1  = regval;
            break;
        case 2:
            regval                     = MEM_CFG_REGS->GSXACCPROT2;
            regval                    &= (~(0x01UL << offset));
            regval                    |= (((uint32_t)permission) << offset);
            MEM_CFG_REGS->GSXACCPROT2  = regval;
            break;
        case 3:
            regval                     = MEM_CFG_REGS->GSXACCPROT3;
            regval                    &= (~(0x01UL << offset));
            regval                    |= (((uint32_t)permission) << offset);
            MEM_CFG_REGS->GSXACCPROT3  = regval;
            break;
    }
}

/*!
 * \brief Get gsram access right
 *
 * \details This function get gsram DMA/CPU access right
 *
 * \param[in] gsramId The gram num ID
 * \param[in] mode The gsram access mode
 * \return Return The gsram access enable
 *
 */
static inline SYSCTRL_AccEn_t SYSCTRL_getGsramAccessStatus(SYSCTRL_SramGs_t gsramId, SYSCTRL_AccMode_t mode)
{
    uint32_t        regval = 0x00;
    uint8_t         gs_cnt, offset, reg_num;
    SYSCTRL_AccEn_t ret;

    if (gsramId == kSRAM_GSMAX)
    {
        return kGS_ASSCESS_ALLOW;
    }

    if (mode == kGS_ASSCESS_DMA)
        gs_cnt = 8 * gsramId + 2;
    else
        gs_cnt = 8 * gsramId + 1;

    offset  = gs_cnt % 32;
    reg_num = gs_cnt / 32;

    switch (reg_num)
    {
        case 0:
            regval = MEM_CFG_REGS->GSXACCPROT0;
            break;
        case 1:
            regval = MEM_CFG_REGS->GSXACCPROT1;
            break;
        case 2:
            regval = MEM_CFG_REGS->GSXACCPROT2;
            break;
        case 3:
            regval = MEM_CFG_REGS->GSXACCPROT3;
            break;
    }
    regval &= (0x01UL << offset);
    ret     = (SYSCTRL_AccEn_t)(regval >> offset);
    return ret;
}

/*!
 * \brief Init gsram
 *
 * \details This function init gsram for DMA/CPU access
 *
 * \param[in] gsramId The gram num ID
 *
 */
static inline void SYSCTRL_initSramBlock(SYSCTRL_SramGs_t gsramId)
{
    MEM_CFG_REGS->GSXINIT |= (0x1UL << gsramId);
}

/*!
 * \brief Get gsram init done status
 *
 * \details This function get gsram init status for DMA/CPU access
 *
 * \param[in] gsramId The gram num ID
 * \return Return The gsram init status
 *
 */
static inline bool SYSCTRL_getSramInitDone(SYSCTRL_SramGs_t gsramId)
{
    if (MEM_CFG_REGS->GSXINITDONE & (0x1UL << gsramId))
        return true;
    else
        return false;
}

#endif

/*!
 * \brief Init msgram
 *
 * \details This function init msgram for IPC function
 *
 *
 */
static inline void SYSCTRL_initMsgram(void)
{
    MEM_CFG_REGS->MSGXINIT |= MEM_CFG_REGS_MSGXINIT_INIT_CPUTOCPU_Set(0x01U);
}

/*!
 * \brief Get msgram init done status
 *
 * \details This function get msgram init status for IPC
 *
 * \return Return The gsram init status
 *
 */
static inline bool SYSCTRL_getMsgramInitDone(void)
{
    if (MEM_CFG_REGS_MSGXINITDONE_INITDONE_CPUTOCPU_Get(MEM_CFG_REGS->MSGXINITDONE))
        return true;
    else
        return false;
}

/*!
 * \brief Init TCM
 *
 * \details This function init TCM for DMA/CPU access
 *
 * \param[in] tcmId The tcm num ID
 *
 */
static inline void SYSCTRL_initTCM(SYSCTRL_Tcm_t tcmId)
{
    if (tcmId == kSYS_TCM_MAX)
    {
        MEM_CFG_REGS->TCMXINIT |= MEM_CFG_REGS_TCMXINIT_INIT_DTCM_Set(0x01U);
        MEM_CFG_REGS->TCMXINIT |= MEM_CFG_REGS_TCMXINIT_INIT_ITCM_Set(0x01U);
    }
    else
        MEM_CFG_REGS->TCMXINIT |= (0x1UL << tcmId);
}

/*!
 * \brief Get tcm init done status
 *
 * \details This function get tcm init status for DMA/CPU access
 *
 * \param[in] tcmId The tcm num ID
 * \return Return The tcm init status
 *
 */
static inline bool SYSCTRL_getTCMInitDone(SYSCTRL_Tcm_t tcmId)
{
    if (tcmId >= kSYS_TCM_MAX)
        return false;
    if (MEM_CFG_REGS->TCMXINITDONE & (0x1UL << tcmId))
        return true;
    else
        return false;
}

#if defined(HTE_DEVICE_HS32F7D377_CPU1)
/*!
 * \brief Init msgram
 *
 * \details This function init msgram for IPC function
 *
 *
 */
static inline void SYSCTRL_initCANSram(void)
{
    MEM_CFG_REGS->CANSRAMINIT |= MEM_CFG_REGS_CANSRAMINIT_INIT_CANSRAM_Set(0x01U);
}

/*!
 * \brief Get msgram init done status
 *
 * \details This function get msgram init status for IPC
 *
 * \return Return The gsram init status
 *
 */
static inline bool SYSCTRL_getCANSramInitDone(void)
{
    if (MEM_CFG_REGS_CANSRAMINITDONE_INITDONE_CANSRAM_Get(MEM_CFG_REGS->CANSRAMINITDONE))
        return true;
    else
        return false;
}
#endif

/*!
 * \brief Get nma flag
 *
 * \details This function get nma flag for Int
 *
 * \param[in] nmaId The nma num ID
 * \return Return The nma flag status
 *
 */
static inline bool SYSCTRL_getNmaFlag(SYSCTRL_NoMasterAcc_t nmaId)
{
    if (ACCESS_PROTECTION_REGS->NMAVFLG & (0x1UL << nmaId))
        return true;
    else
        return false;
}

/*!
 * \brief Set nma flag
 *
 * \details This function set nma flag for Int
 *
 * \param[in] nmaId The nma num ID
 *
 */
static inline void SYSCTRL_setNmaInt(SYSCTRL_NoMasterAcc_t nmaId)
{
    if (nmaId == kNO_MASTER_ACC_MAX)
    {
        ACCESS_PROTECTION_REGS->NMAVSET |= ACCESS_PROTECTION_REGS_NMAVSET_CPUWRITE_Set(0x01U);
        ACCESS_PROTECTION_REGS->NMAVSET |= ACCESS_PROTECTION_REGS_NMAVSET_DMAWRITE_Set(0x01U);
#if defined(HTE_DEVICE_HS32F7D377_CPU1)
        ACCESS_PROTECTION_REGS->NMAVSET |= ACCESS_PROTECTION_REGS_NMAVSET_USBADMAWRITE_Set(0x01U);
#endif
    }
    else
        ACCESS_PROTECTION_REGS->NMAVSET |= (0x1UL << nmaId);
}

/*!
 * \brief Clean nma flag
 *
 * \details This function clean nma flag for Int
 *
 * \param[in] nmaId The nma num ID
 *
 */
static inline void SYSCTRL_cleanNmaFlag(SYSCTRL_NoMasterAcc_t nmaId)
{
    if (nmaId == kNO_MASTER_ACC_MAX)
    {
#if defined(HTE_DEVICE_HS32F7D377_CPU1)
        ACCESS_PROTECTION_REGS->NMAVCLR |= ACCESS_PROTECTION_REGS_NMAVCLR_USBADMAWRITE_Set(0x01U);
#endif
        ACCESS_PROTECTION_REGS->NMAVCLR |= ACCESS_PROTECTION_REGS_NMAVCLR_DMAWRITE_Set(0x01U);
        ACCESS_PROTECTION_REGS->NMAVCLR |= ACCESS_PROTECTION_REGS_NMAVCLR_CPUWRITE_Set(0x01U);
    }
    else
        ACCESS_PROTECTION_REGS->NMAVCLR |= (0x1UL << nmaId);
}

/*!
 * \brief Set nma flag enable
 *
 * \details This function Set nma enable for Int
 *
 * \param[in] nmaId The nma num ID
 *
 */
static inline void SYSCTRL_setNmaIntEn(SYSCTRL_NoMasterAcc_t nmaId)
{
    if (nmaId == kNO_MASTER_ACC_MAX)
    {
#if defined(HTE_DEVICE_HS32F7D377_CPU1)
        ACCESS_PROTECTION_REGS->NMAVINTEN |= ACCESS_PROTECTION_REGS_NMAVINTEN_USBADMAWRITE_Set(0x01U);
#endif
        ACCESS_PROTECTION_REGS->NMAVINTEN |= ACCESS_PROTECTION_REGS_NMAVINTEN_DMAWRITE_Set(0x01U);
        ACCESS_PROTECTION_REGS->NMAVINTEN |= ACCESS_PROTECTION_REGS_NMAVINTEN_CPUWRITE_Set(0x01U);
    }
    else
        ACCESS_PROTECTION_REGS->NMAVINTEN |= (0x1UL << nmaId);
}

/*!
 * \brief Get nma addr
 *
 * \details This function get nma addr for Int
 *
 * \param[in] nmaId The nma num ID
 * \return Return The nma ACC ADDR
 *
 */
static inline uint32_t SYSCTRL_getNmaAccAddr(SYSCTRL_NoMasterAcc_t nmaId)
{
    if (nmaId == kNO_MASTER_ACC_CPUW)
        return ACCESS_PROTECTION_REGS->NMCPUWRAVADDR;
    else if (nmaId == kNO_MASTER_ACC_DMAW)
        return ACCESS_PROTECTION_REGS->NMDMAWRAVADDR;
    else if (nmaId == kNO_MASTER_ACC_USBA_DMA)
        return ACCESS_PROTECTION_REGS->NMUSBADMAWRAVADDR;

    return 0;
}

/*!
 * \brief Get ma flag
 *
 * \details This function get ma flag for Int
 *
 * \param[in] maId The ma num ID
 * \return Return The ma flag status
 *
 */
static inline bool SYSCTRL_getMaFlag(SYSCTRL_MasterAcc_t maId)
{
    if (ACCESS_PROTECTION_REGS->MAVFLG & (0x1UL << maId))
        return true;
    else
        return false;
}

/*!
 * \brief Set nma flag
 *
 * \details This function set nma flag for Int
 *
 * \param[in] maId The ma num ID
 *
 */
static inline void SYSCTRL_setMaInt(SYSCTRL_MasterAcc_t maId)
{
    if (maId == kMASTER_ACC_MAX)
    {
        ACCESS_PROTECTION_REGS->MAVSET |= ACCESS_PROTECTION_REGS_MAVSET_CPUWRITE_Set(0x01U);
        ACCESS_PROTECTION_REGS->MAVSET |= ACCESS_PROTECTION_REGS_MAVSET_DMAWRITE_Set(0x01U);
    }
    else
        ACCESS_PROTECTION_REGS->MAVSET |= (0x1UL << maId);
}

/*!
 * \brief Clean ma flag
 *
 * \details This function clean ma flag for Int
 *
 * \param[in] maId The ma num ID
 *
 */
static inline void SYSCTRL_cleanMaFlag(SYSCTRL_MasterAcc_t maId)
{
    if (maId == kMASTER_ACC_MAX)
    {
        ACCESS_PROTECTION_REGS->MAVCLR |= ACCESS_PROTECTION_REGS_MAVCLR_DMAWRITE_Set(0x01U);
        ACCESS_PROTECTION_REGS->MAVCLR |= ACCESS_PROTECTION_REGS_MAVCLR_CPUWRITE_Set(0x01U);
    }
    else
        ACCESS_PROTECTION_REGS->MAVCLR |= (0x1UL << maId);
}

/*!
 * \brief Set ma enable
 *
 * \details This function set ma enable for Int
 *
 * \param[in] maId The ma num ID
 *
 */
static inline void SYSCTRL_setMaIntEn(SYSCTRL_MasterAcc_t maId)
{
    if (maId == kMASTER_ACC_MAX)
    {
        ACCESS_PROTECTION_REGS->MAVINTEN |= ACCESS_PROTECTION_REGS_MAVINTEN_DMAWRITE_Set(0x01U);
        ACCESS_PROTECTION_REGS->MAVINTEN |= ACCESS_PROTECTION_REGS_MAVINTEN_CPUWRITE_Set(0x01U);
    }
    else
        ACCESS_PROTECTION_REGS->MAVINTEN |= (0x1UL << maId);
}

/*!
 * \brief Get ma addr
 *
 * \details This function get ma addr for Int
 *
 * \param[in] maId The ma num ID
 * \return Return The ma flag addr
 *
 */
static inline uint32_t SYSCTRL_getMaAccAddr(SYSCTRL_MasterAcc_t maId)
{
    if (maId == kMASTER_ACC_CPUW)
        return ACCESS_PROTECTION_REGS->MCPUWRAVADDR;
    else if (maId == kMASTER_ACC_DMAW)
        return ACCESS_PROTECTION_REGS->MDMAWRAVADDR;

    return 0;
}

/*!
 * \brief Get uncrt err flag
 *
 * \details This function get uncrt err flag for Int
 *
 * \param[in] errId The err num ID
 * \return Return The uncrt err status
 *
 */
static inline bool SYSCTRL_getUncrtErrFlag(SYSCTRL_CrcError_t errId)
{
    if (MEMORY_ERROR_REGS->UCERRFLG & (0x1UL << errId))
        return true;
    else
        return false;
}

/*!
 * \brief Set uncrt err int
 *
 * \details This function Set uncrt err for Int
 *
 * \param[in] errId The err num ID
 *
 */
static inline void SYSCTRL_setUncrtErrInt(SYSCTRL_CrcError_t errId)
{
    if (errId == kCRC_ERROR_MAX)
    {
        MEMORY_ERROR_REGS->UCERRSET |= MEMORY_ERROR_REGS_UCERRSET_USBADMARDERR_Set(0x01U);
        MEMORY_ERROR_REGS->UCERRSET |= MEMORY_ERROR_REGS_UCERRSET_DMARDERR_Set(0x01U);
        MEMORY_ERROR_REGS->UCERRSET |= MEMORY_ERROR_REGS_UCERRSET_CPURDERR_Set(0x01U);
    }
    else
        MEMORY_ERROR_REGS->UCERRSET |= (0x1UL << errId);
}

/*!
 * \brief Clean uncrt err flag
 *
 * \details This function clean uncrt err flag for Int
 *
 * \param[in] errId The err num ID
 *
 */
static inline void SYSCTRL_cleanUncrtErrFlag(SYSCTRL_CrcError_t errId)
{
    if (errId == kCRC_ERROR_MAX)
    {
        MEMORY_ERROR_REGS->UCERRCLR |= MEMORY_ERROR_REGS_UCERRCLR_USBADMARDERR_Set(0x01U);
        MEMORY_ERROR_REGS->UCERRCLR |= MEMORY_ERROR_REGS_UCERRCLR_DMARDERR_Set(0x01U);
        MEMORY_ERROR_REGS->UCERRCLR |= MEMORY_ERROR_REGS_UCERRCLR_CPURDERR_Set(0x01U);
    }
    else
        MEMORY_ERROR_REGS->UCERRCLR |= (0x1UL << errId);
}

/*!
 * \brief Get uncrt err addr
 *
 * \details This function get uncrt err addr
 *
 * \param[in] errId The err num ID
 * \return Return The uncrt err addr
 *
 */
static inline uint32_t SYSCTRL_getUncrtErrAddr(SYSCTRL_CrcError_t errId)
{
    if (errId == kCRC_ERROR_CPUR)
        return MEMORY_ERROR_REGS->UCCPUREADDR;
    else if (errId == kCRC_ERROR_DMAR)
        return MEMORY_ERROR_REGS->UCDMAREADDR;
    else if (errId == kCRC_ERROR_USBA_DMA)
        return MEMORY_ERROR_REGS->UCUSBADMAREADDR;

    return 0;
}

/*!
 * \brief Get crt err flag
 *
 * \details This function get crt err flag for Int
 *
 * \param[in] errId The err num ID
 * \return Return The crt err flag status
 *
 */
static inline bool SYSCTRL_getCrtErrFlag(SYSCTRL_CrcError_t errId)
{
    if (MEMORY_ERROR_REGS->CERRFLG & (0x1UL << errId))
        return true;
    else
        return false;
}

/*!
 * \brief Set crt err int
 *
 * \details This function Set crt err int for Int
 *
 * \param[in] errId The err num ID
 *
 */
static inline void SYSCTRL_setCrtErrInt(SYSCTRL_CrcError_t errId)
{
    if (errId == kCRC_ERROR_MAX)
    {
        MEMORY_ERROR_REGS->CERRSET |= MEMORY_ERROR_REGS_CERRSET_USBADMARDERR_Set(0x01U);
        MEMORY_ERROR_REGS->CERRSET |= MEMORY_ERROR_REGS_CERRSET_DMARDERR_Set(0x01U);
        MEMORY_ERROR_REGS->CERRSET |= MEMORY_ERROR_REGS_CERRSET_CPURDERR_Set(0x01U);
    }
    else
        MEMORY_ERROR_REGS->CERRSET |= (0x1UL << errId);
}

/*!
 * \brief Clean crt err flag
 *
 * \details This function clean crt err flag
 *
 * \param[in] errId The err num ID
 *
 */
static inline void SYSCTRL_cleanCrtErrFlag(SYSCTRL_CrcError_t errId)
{
    if (errId == kCRC_ERROR_MAX)
    {
        MEMORY_ERROR_REGS->CERRCLR |= MEMORY_ERROR_REGS_CERRCLR_USBADMARDERR_Set(0x01U);
        MEMORY_ERROR_REGS->CERRCLR |= MEMORY_ERROR_REGS_CERRCLR_DMARDERR_Set(0x01U);
        MEMORY_ERROR_REGS->CERRCLR |= MEMORY_ERROR_REGS_CERRCLR_CPURDERR_Set(0x01U);
    }
    else
        MEMORY_ERROR_REGS->CERRCLR |= (0x1UL << errId);
}

/*!
 * \brief Get crt err addr
 *
 * \details This function get crt err addr
 *
 * \param[in] errId The err num ID
 * \return Return The crt err addr
 *
 */
static inline uint32_t SYSCTRL_getCrtErrAddr(SYSCTRL_CrcError_t errId)
{
    if (errId == kCRC_ERROR_CPUR)
        return MEMORY_ERROR_REGS->CCPUREADDR;
    else if (errId == kCRC_ERROR_DMAR)
        return MEMORY_ERROR_REGS->CDMAREADDR;
    else if (errId == kCRC_ERROR_USBA_DMA)
        return MEMORY_ERROR_REGS->CUSBADMAREADDR;

    return 0;
}

/*!
 * \brief Get crt err cnt
 *
 * \details This function get crt err cnt for Int
 *
 * \return Return The crt err cnt
 *
 */
static inline uint32_t SYSCTRL_getCrtErrCnt(void)
{
    return MEMORY_ERROR_REGS->CERRCNT;
}

/*!
 * \brief Set crt err threshold
 *
 * \details This function set crt err threshold for Int
 *
 * \param[in] cnt The crt err threshold cnt
 *
 */
static inline void SYSCTRL_setCrtErrThreshold(uint32_t cnt)
{
    MEMORY_ERROR_REGS->CERRTHRES = cnt;
}

/*!
 * \brief Get crt int flag
 *
 * \details This function get crt int flag for Int
 *
 * \return Return The crt int flag status
 *
 */
static inline bool SYSCTRL_getCrtIntFlag(void)
{
    if (MEMORY_ERROR_REGS_CEINTFLG_CEINTFLAG_Get(MEMORY_ERROR_REGS->CEINTFLG))
        return true;
    else
        return false;
}

/*!
 * \brief Clean crt int flag
 *
 * \details This function clean crt int flag for Int
 *
 *
 */
static inline void SYSCTRL_cleanCrtIntFlag(void)
{
    MEMORY_ERROR_REGS->CEINTCLR |= MEMORY_ERROR_REGS_CEINTCLR_CEINTCLR_Set(0x01U);
}

/*!
 * \brief Set crt int enabale
 *
 * \details This function set crt int enabale for Int
 *
 * \param[in] intEn The enable flag
 *
 */
static inline void SYSCTRL_setCrtIntEn(SYSCTRL_En_t intEn)
{
    MEMORY_ERROR_REGS->CEINTEN |= MEMORY_ERROR_REGS_CEINTEN_CEINTEN_Set(0x01U);
}

/*!
 * \brief Set crt err int eable
 *
 * \details This function Set crt err int eable
 *
 * \param[in] errId The err num ID
 * \param[in] intEn The enable flag
 *
 */
static inline void SYSCTRL_setCrtErrIntEn(SYSCTRL_CrcError_t errId, SYSCTRL_En_t intEn)
{
    if (errId == kCRC_ERROR_MAX)
    {
        MEMORY_ERROR_REGS->CERRINTEN &= ~MEMORY_ERROR_REGS_CERRINTEN_USBADMARDERRINTEN_Msk;
        MEMORY_ERROR_REGS->CERRINTEN |= MEMORY_ERROR_REGS_CERRINTEN_USBADMARDERRINTEN_Set(intEn);
        MEMORY_ERROR_REGS->CERRINTEN &= ~MEMORY_ERROR_REGS_CERRINTEN_DMARDERRINTEN_Msk;
        MEMORY_ERROR_REGS->CERRINTEN |= MEMORY_ERROR_REGS_CERRINTEN_DMARDERRINTEN_Set(intEn);
        MEMORY_ERROR_REGS->CERRINTEN &= ~MEMORY_ERROR_REGS_CERRINTEN_CPURDERRINTEN_Msk;
        MEMORY_ERROR_REGS->CERRINTEN |= MEMORY_ERROR_REGS_CERRINTEN_CPURDERRINTEN_Set(intEn);
    }
    else
    {
        if (errId == kCRC_ERROR_CPUR)
        {
            MEMORY_ERROR_REGS->CERRINTEN &= ~MEMORY_ERROR_REGS_CERRINTEN_CPURDERRINTEN_Msk;
            MEMORY_ERROR_REGS->CERRINTEN |= MEMORY_ERROR_REGS_CERRINTEN_CPURDERRINTEN_Set(intEn);
        }
        else if (errId == kCRC_ERROR_DMAR)
        {
            MEMORY_ERROR_REGS->CERRINTEN &= ~MEMORY_ERROR_REGS_CERRINTEN_DMARDERRINTEN_Msk;
            MEMORY_ERROR_REGS->CERRINTEN |= MEMORY_ERROR_REGS_CERRINTEN_DMARDERRINTEN_Set(intEn);
        }
        else if (errId == kCRC_ERROR_USBA_DMA)
        {
            MEMORY_ERROR_REGS->CERRINTEN &= ~MEMORY_ERROR_REGS_CERRINTEN_USBADMARDERRINTEN_Msk;
            MEMORY_ERROR_REGS->CERRINTEN |= MEMORY_ERROR_REGS_CERRINTEN_USBADMARDERRINTEN_Set(intEn);
        }
    }
}

/*!
 * \brief Set uncrt err int eable
 *
 * \details This function Set uncrt err int eable
 *
 * \param[in] errId The err num ID
 * \param[in] intEn The enable flag
 *
 */
static inline void SYSCTRL_setUncrtErrIntEn(SYSCTRL_CrcError_t errId, SYSCTRL_En_t intEn)
{
    if (errId == kCRC_ERROR_MAX)
    {
        MEMORY_ERROR_REGS->UCERRINTEN &= ~MEMORY_ERROR_REGS_UCERRINTEN_USBADMARDERRINTEN_Msk;
        MEMORY_ERROR_REGS->UCERRINTEN |= MEMORY_ERROR_REGS_UCERRINTEN_USBADMARDERRINTEN_Set(intEn);
        MEMORY_ERROR_REGS->UCERRINTEN &= ~MEMORY_ERROR_REGS_UCERRINTEN_DMARDERRINTEN_Msk;
        MEMORY_ERROR_REGS->UCERRINTEN |= MEMORY_ERROR_REGS_UCERRINTEN_DMARDERRINTEN_Set(intEn);
        MEMORY_ERROR_REGS->UCERRINTEN &= ~MEMORY_ERROR_REGS_UCERRINTEN_CPURDERRINTEN_Msk;
        MEMORY_ERROR_REGS->UCERRINTEN |= MEMORY_ERROR_REGS_UCERRINTEN_CPURDERRINTEN_Set(intEn);
    }
    else
    {
        if (errId == kCRC_ERROR_CPUR)
        {
            MEMORY_ERROR_REGS->UCERRINTEN &= ~MEMORY_ERROR_REGS_UCERRINTEN_CPURDERRINTEN_Msk;
            MEMORY_ERROR_REGS->UCERRINTEN |= MEMORY_ERROR_REGS_UCERRINTEN_CPURDERRINTEN_Set(intEn);
        }
        else if (errId == kCRC_ERROR_DMAR)
        {
            MEMORY_ERROR_REGS->UCERRINTEN &= ~MEMORY_ERROR_REGS_UCERRINTEN_DMARDERRINTEN_Msk;
            MEMORY_ERROR_REGS->UCERRINTEN |= MEMORY_ERROR_REGS_UCERRINTEN_DMARDERRINTEN_Set(intEn);
        }
        else if (errId == kCRC_ERROR_USBA_DMA)
        {
            MEMORY_ERROR_REGS->UCERRINTEN &= ~MEMORY_ERROR_REGS_UCERRINTEN_USBADMARDERRINTEN_Msk;
            MEMORY_ERROR_REGS->UCERRINTEN |= MEMORY_ERROR_REGS_UCERRINTEN_USBADMARDERRINTEN_Set(intEn);
        }
    }
}


/*!
 * \brief Get CPU id
 *
 * \details This function get cpu id for dual core identify
 *
 * \return Return The cpu id
 *
 */
static inline SYSCTL_CpuId_t SYSCTRL_getCPUIdentify(void)
{
    uint32_t       value;
    SYSCTL_CpuId_t id = kSYSCTL_ID_CPU1;

    value = CPU_ID_REGS_CPUID_CPUID_Get(CPU_ID_REGS->CPUID);

    if (value == 0x1)
    {
        id = kSYSCTL_ID_CPU1;
    }
    else if (value == 0x2)
    {
        id = kSYSCTL_ID_CPU2;
    }

    return id;
}


/*!
 * \brief Set dummy buffer value
 *
 * \details This function set dummy buffer register value
 *
 * \param[in] dummyId The dummy num ID
 * \param[in] value The reg value
 *
 */
static inline void SYSCTRL_setDummyReg(uint8_t dummyId, uint32_t value)
{
    volatile uint32_t *pregs;
    uint8_t            addr_offset;

    if (dummyId > 63)
    {
        return;
    }

    addr_offset = 4 * dummyId;
    pregs       = (volatile uint32_t *)(DUMMY_REGS_BASE + addr_offset);
    *pregs      = value;
}

/*!
 * \brief Get dummy buffer value
 *
 * \details This function get dummy buffer register value
 *
 * \param[in] dummyId The dummy num ID
 * \return Return The reg value
 *
 */
static inline uint32_t SYSCTRL_getDummyReg(uint8_t dummyId)
{
    volatile uint32_t *pregs;
    uint8_t            addr_offset;
    uint32_t           value;

    if (dummyId > 63)
    {
        return 0;
    }

    addr_offset = 4 * dummyId;
    pregs       = (volatile uint32_t *)(DUMMY_REGS_BASE + addr_offset);
    value       = *pregs;
    return value;
}

/*!
 * Configures the sync output source.
 *
 * \param syncSrc is sync output source selection.
 * \param base is sync soc reg base.
 *
 * This function configures the sync output source from the ePWM modules. The
 * \e syncSrc parameter is a value \b SYSCTL_SYNC_OUT_SRC_XXXX, where XXXX is
 * a sync signal coming from an ePWM such as SYSCTL_SYNC_OUT_SRC_EPWM1SYNCOUT
 *
 */
static inline void
SysCtl_setSyncOutputConfig(SYNC_SOC_Type *base, SysCtl_SyncOutputSource syncSrc)
{
    // Write the sync output source selection to the appropriate register.
    base->SYNCSELECT =
        (base->SYNCSELECT & ~SYNC_SOC_SYNCSELECT_SYNCOUT_Msk) | ((uint32_t)syncSrc << SYNC_SOC_SYNCSELECT_SYNCOUT_Pos);
}

/*!
 * Enables ePWM SOC signals to drive an external (off-chip) ADCSOC signal.
 *
 * \param adcsocSrc is a bit field of the selected signals to be enabled
 *
 * This function configures which ePWM SOC signals are enabled as a source for
 * either ADCSOCAO or ADCSOCBO. The \e adcsocSrc parameter takes a logical OR
 * of \b SYSCTL_ADCSOC_SRC_PWMxSOCA/B values that correspond to different
 * signals.
 *
 */
static inline void
SysCtl_enableExtADCSOCSource(uint32_t adcsocSrc)
{
    //
    // Set the bits that correspond to signal to be enabled.
    //
    SYNC_SOC->ADCSOCOUTSELECT |= adcsocSrc;
}

// #if defined(HTE_DEVICE_HS32F7D377_CPU1)
/*!
 * \brief Calculates the system clock frequency (SYSCLK).
 *
 * \details This function determines the frequency of the system clock based on the
 *          frequency of the oscillator clock source (from \e clockInHz) and the PLL
 *          and clock divider configuration registers.
 *
 * \param[in] clockInHz is the frequency of the oscillator clock source (OSCCLK).
 * \return Returns the system clock frequency
 *
 */
extern uint32_t SYSCTRL_getClock(uint32_t clockInHz);

/*!
 * \brief Calculates the auxiliary clock frequency.
 *
 * \details This function determines the frequency of the auxiliary clock based on the
 *          frequency of the auxiliary clock source (from \e clockInHz) and the PLL
 *          and clock divider configuration registers.
 *
 * \param[in] clockInHz is the frequency of the auxiliary clock source.
 * \return Returns the auxiliary clock frequency
 *
 */
extern uint32_t SYSCTRL_getAuxClock(uint32_t clockInHz);

/*!
 * \brief Configures the external oscillator for the clocking of the device.
 *
 * \details This function configures the external oscillator (XTAL) to be used for the
 *          clocking of the device in crystal mode.
 *
 *
 */
extern void SYSCTRL_selectXTAL(void);

/*!
 * \brief Selects the oscillator to be used for the clocking of the device.
 *
 * \details This function configures the oscillator to be used in the clocking of the
 *          device. The \e oscSource parameter may take a value of
 *          \b SYSCTL_OSCSRC_OSC2, \b SYSCTL_OSCSRC_XTAL, or \b SYSCTL_OSCSRC_OSC1.
 *
 * \param[in] oscSource is the oscillator source to be configured.
 *
 */
extern void SYSCTRL_selectOscSource(SYSCTRL_OscSrcSel_t oscSource);

/*!
 * \brief Selects the oscillator to be used for the AUXPLL.
 *
 * \details This function configures the oscillator to be used in the clocking of the
 *          AUXPLL. The \e oscSource parameter may take a value of
 *          \b SYSCTL_OSCSRC_OSC2, \b SYSCTL_OSCSRC_XTAL, or \b SYSCTL_OSCSRC_OSC1.
 *
 * \param[in] oscSource is the oscillator source to be configured.
 *
 */
extern void SYSCTRL_selectOscSourceAuxPLL(SYSCTRL_AuxSrcSel_t oscSource);

/*!
 * \brief Configures the clocking of the device.
 *
 * \details This function configures the clocking of the device. The input crystal
 *          frequency, oscillator to be used, use of the PLL, and the system clock
 *          divider are all configured with this function.
 *
 * \param[in] config parameter is the struct contain:
 *   oscSrc                    is the source osc clock input;
 *   oscFreq                   is the freq of osc clock;
 *   pllEN                     is the setting for pll enable;
 *   srcClkdiv                 is the divide count for source clock use for PLL;
 *   pllClkFreq                is the pll output freq;
 *   sysClkDiv                 is the sys clk divide count;
 *
 * \return status
 */
extern bool SYSCTRL_setClock(SYSCTL_SysClk_Config_t config);

/*!
 * \brief Configures the aux clocking of the device.
 *
 * \details This function configures the aux clocking of the device. The input crystal
 *          frequency, aux clock to be used, use of the PLL, and the system clock
 *          divider are all configured with this function.
 *
 * \param[in] config parameter is the struct contain:
 *   oscSrc                    is the source aux clock input;
 *   oscFreq                   is the freq of aux clock;
 *   pllEN                     is the setting for pll enable;
 *   srcClkdiv                 is the divide count for source clock use for PLL;
 *   pllClkFreq                is the pll output freq;
 *   sysClkDiv                 is the sys clk divide count;
 *
 * \return status
 */
extern bool SYSCTRL_setAuxClock(SYSCTL_AuxClk_Config_t config);

#if defined(HTE_DEVICE_HS32F7D377_CPU1)
/*!
 * \brief Get the device part parametric value
 *
 * \details This function gets the device part parametric value.
 *
 * \param[in] parametric is the requested device parametric value contain:
 *   REVID                    is the device rev id;
 *   CPUID                    is the CPU id;
 *   PINCOUNT                 is the Device Pin Count;
 *   FlASH                    is the Device Flash size (KB);
 *   PARTID                   is the Device Part ID Format Revision
 *   FAMILY                   is the Device Family
 *   PARTNO                   is the Device Part Number
 *   CLASSID                  is the Device Class ID
 *
 * \return device parametric
 */
extern uint32_t SYSCTRL_getDeviceParametric(SYSCTL_DeviceParametric_t parametric);

/*!
 * \brief release_cpu2_reset
 *
 * \details this function is release cpu2 reset.
 *
 *
 */
extern void SYSCTR_releaseCpu2(void);

/*!
 * \brief sysctrl_init_sram
 *
 * \details this function is init gsram.
 *
 * \param[in] gsramId is the sram block id
 *
 */
extern void SYSCTRL_init_sram(SYSCTRL_SramGs_t gsramId);

#endif

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */ /* end of DRV_HS32F7D377_SYSCTRL */

#endif /* HTE_SYSCTRL_H */
