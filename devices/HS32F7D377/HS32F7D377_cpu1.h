/*
 * Copyright 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file HS32F7D377_cpu1.h
 * \brief HS32F7D377 CPU1 header file
 * \version 1.0.1
 */

#ifndef HS32F7D377_CPU1_H
#define HS32F7D377_CPU1_H

/*!
 * \addtogroup HS32F7D377_CPU1_DEVICE HS32F7D377 CPU1 Device
 *
 * \brief HS32F7D377 CPU1 device definitions
 *
 * @{
 */

/* clang-format off */

/*!
 * \addtogroup HS32F7D377_CPU1_INTERRUPT HS32F7D377 CPU1 Interrupt
 *
 * \brief Interrupt number definitions
 *
 * @{
 */

/*! \brief Interrupt number definitions */
typedef enum IRQn
{
    /* Processor Exceptions Numbers */
    Reset_IRQn               = -15,    /*!<   1 Reset Interrupt */
    NonMaskableInt_IRQn      = -14,    /*!<   2 Non Maskable Interrupt */
    HardFault_IRQn           = -13,    /*!<   3 HardFault Interrupt */
    MemoryManagement_IRQn    = -12,    /*!<   4 Memory Management Interrupt */
    BusFault_IRQn            = -11,    /*!<   5 Bus Fault Interrupt */
    UsageFault_IRQn          = -10,    /*!<   6 Usage Fault Interrupt */
    SVCall_IRQn              =  -5,    /*!<  11 SV Call Interrupt */
    DebugMonitor_IRQn        =  -4,    /*!<  12 Debug Monitor Interrupt */
    PendSV_IRQn              =  -2,    /*!<  14 Pend SV Interrupt */
    SysTick_IRQn             =  -1,    /*!<  15 System Tick Interrupt */

    /* Processor Interrupt Numbers */
    WDT_IRQn                 =   0,    /*!<  16 WDT */
    CPUTIMER0_IRQn           =   1,    /*!<  17 CPU TIMER0 */
    CPUTIMER1_IRQn           =   2,    /*!<  18 CPU TIMER1 */
    CPUTIMER2_IRQn           =   3,    /*!<  19 CPU TIMER2 */
    DWTIMER_CH0_IRQn         =   4,    /*!<  20 DWTIMER Channel0 */
    DWTIMER_CH1_IRQn         =   5,    /*!<  21 DWTIMER Channel1 */
    DWTIMER_CH2_IRQn         =   6,    /*!<  22 DWTIMER Channel2 */
    RESERVED23_IRQn          =   7,    /*!<  23 RESERVED */
    IPC_INT0_IRQn            =   8,    /*!<  24 IPC INT0 */
    IPC_INT1_IRQn            =   9,    /*!<  25 IPC INT1 */
    IPC_INT2_IRQn            =  10,    /*!<  26 IPC INT2 */
    IPC_INT3_IRQn            =  11,    /*!<  27 IPC INT3 */
    ADCA_EVT_IRQn            =  12,    /*!<  28 ADCA Event */
    ADCB_EVT_IRQn            =  13,    /*!<  29 ADCB Event */
    ADCC_EVT_IRQn            =  14,    /*!<  30 ADCC Event */
    ADCD_EVT_IRQn            =  15,    /*!<  31 ADCD Event */
    ADCA_INT1_IRQn           =  16,    /*!<  32 ADCA INT1 */
    ADCA_INT2_IRQn           =  17,    /*!<  33 ADCA INT2 */
    ADCA_INT3_IRQn           =  18,    /*!<  34 ADCA INT3 */
    ADCA_INT4_IRQn           =  19,    /*!<  35 ADCA INT4 */
    ADCB_INT1_IRQn           =  20,    /*!<  36 ADCB INT1 */
    ADCB_INT2_IRQn           =  21,    /*!<  37 ADCB INT2 */
    ADCB_INT3_IRQn           =  22,    /*!<  38 ADCB INT3 */
    ADCB_INT4_IRQn           =  23,    /*!<  39 ADCB INT4 */
    ADCC_INT1_IRQn           =  24,    /*!<  40 ADCC INT1 */
    ADCC_INT2_IRQn           =  25,    /*!<  41 ADCC INT2 */
    ADCC_INT3_IRQn           =  26,    /*!<  42 ADCC INT3 */
    ADCC_INT4_IRQn           =  27,    /*!<  43 ADCC INT4 */
    ADCD_INT1_IRQn           =  28,    /*!<  44 ADCD INT1 */
    ADCD_INT2_IRQn           =  29,    /*!<  45 ADCD INT2 */
    ADCD_INT3_IRQn           =  30,    /*!<  46 ADCD INT3 */
    ADCD_INT4_IRQn           =  31,    /*!<  47 ADCD INT4 */
    XINT1_IRQn               =  32,    /*!<  48 XINT1 */
    XINT2_IRQn               =  33,    /*!<  49 XINT2 */
    XINT3_IRQn               =  34,    /*!<  50 XINT3 */
    XINT4_IRQn               =  35,    /*!<  51 XINT4 */
    XINT5_IRQn               =  36,    /*!<  52 XINT5 */
    RESERVED53_IRQn          =  37,    /*!<  53 RESERVED */
    RESERVED54_IRQn          =  38,    /*!<  54 RESERVED */
    EPWM_HRCAL_IRQn          =  39,    /*!<  55 EPWM High-Resolution Calibration */
    EPWM1_TZ_IRQn            =  40,    /*!<  56 EPWM1 Trip-Zone */
    EPWM2_TZ_IRQn            =  41,    /*!<  57 EPWM2 Trip-Zone */
    EPWM3_TZ_IRQn            =  42,    /*!<  58 EPWM3 Trip-Zone */
    EPWM4_TZ_IRQn            =  43,    /*!<  59 EPWM4 Trip-Zone */
    EPWM5_TZ_IRQn            =  44,    /*!<  60 EPWM5 Trip-Zone */
    EPWM6_TZ_IRQn            =  45,    /*!<  61 EPWM6 Trip-Zone */
    EPWM7_TZ_IRQn            =  46,    /*!<  62 EPWM7 Trip-Zone */
    EPWM8_TZ_IRQn            =  47,    /*!<  63 EPWM8 Trip-Zone */
    EPWM9_TZ_IRQn            =  48,    /*!<  64 EPWM9 Trip-Zone */
    EPWM10_TZ_IRQn           =  49,    /*!<  65 EPWM10 Trip-Zone */
    EPWM11_TZ_IRQn           =  50,    /*!<  66 EPWM11 Trip-Zone */
    EPWM12_TZ_IRQn           =  51,    /*!<  67 EPWM12 Trip-Zone */
    RESERVED68_IRQn          =  52,    /*!<  68 RESERVED */
    RESERVED69_IRQn          =  53,    /*!<  69 RESERVED */
    RESERVED70_IRQn          =  54,    /*!<  70 RESERVED */
    RESERVED71_IRQn          =  55,    /*!<  71 RESERVED */
    EPWM1_IRQn               =  56,    /*!<  72 EPWM1 */
    EPWM2_IRQn               =  57,    /*!<  73 EPWM2 */
    EPWM3_IRQn               =  58,    /*!<  74 EPWM3 */
    EPWM4_IRQn               =  59,    /*!<  75 EPWM4 */
    EPWM5_IRQn               =  60,    /*!<  76 EPWM5 */
    EPWM6_IRQn               =  61,    /*!<  77 EPWM6 */
    EPWM7_IRQn               =  62,    /*!<  78 EPWM7 */
    EPWM8_IRQn               =  63,    /*!<  79 EPWM8 */
    EPWM9_IRQn               =  64,    /*!<  80 EPWM9 */
    EPWM10_IRQn              =  65,    /*!<  81 EPWM10 */
    EPWM11_IRQn              =  66,    /*!<  82 EPWM11 */
    EPWM12_IRQn              =  67,    /*!<  83 EPWM12 */
    RESERVED84_IRQn          =  68,    /*!<  84 RESERVED */
    RESERVED85_IRQn          =  69,    /*!<  85 RESERVED */
    RESERVED86_IRQn          =  70,    /*!<  86 RESERVED */
    RESERVED87_IRQn          =  71,    /*!<  87 RESERVED */
    ECAP1_IRQn               =  72,    /*!<  88 ECAP1 */
    ECAP2_IRQn               =  73,    /*!<  89 ECAP2 */
    ECAP3_IRQn               =  74,    /*!<  90 ECAP3 */
    ECAP4_IRQn               =  75,    /*!<  91 ECAP4 */
    ECAP5_IRQn               =  76,    /*!<  92 ECAP5 */
    ECAP6_IRQn               =  77,    /*!<  93 ECAP6 */
    RESERVED94_IRQn          =  78,    /*!<  94 RESERVED */
    RESERVED95_IRQn          =  79,    /*!<  95 RESERVED */
    EQEP1_IRQn               =  80,    /*!<  96 EQEP1 */
    EQEP2_IRQn               =  81,    /*!<  97 EQEP2 */
    EQEP3_IRQn               =  82,    /*!<  98 EQEP3 */
    RESERVED99_IRQn          =  83,    /*!<  99 RESERVED */
    CLB1_IRQn                =  84,    /*!< 100 CLB1 */
    CLB2_IRQn                =  85,    /*!< 101 CLB2 */
    CLB3_IRQn                =  86,    /*!< 102 CLB3 */
    CLB4_IRQn                =  87,    /*!< 103 CLB4 */
    CLB5_IRQn                =  88,    /*!< 104 CLB5 */
    CLB6_IRQn                =  89,    /*!< 105 CLB6 */
    CLB7_IRQn                =  90,    /*!< 106 CLB7 */
    CLB8_IRQn                =  91,    /*!< 107 CLB8 */
    RESERVED108_IRQn         =  92,    /*!< 108 RESERVED */
    RESERVED109_IRQn         =  93,    /*!< 109 RESERVED */
    RESERVED110_IRQn         =  94,    /*!< 110 RESERVED */
    RESERVED111_IRQn         =  95,    /*!< 111 RESERVED */
    SDFM1_IRQn               =  96,    /*!< 112 SDFM1 */
    SDFM1_FLT1DR_IRQn        =  97,    /*!< 113 SDFM1 Filter1 Data Ready */
    SDFM1_FLT2DR_IRQn        =  98,    /*!< 114 SDFM1 Filter2 Data Ready */
    SDFM1_FLT3DR_IRQn        =  99,    /*!< 115 SDFM1 Filter3 Data Ready */
    SDFM1_FLT4DR_IRQn        = 100,    /*!< 116 SDFM1 Filter4 Data Ready */
    SDFM2_IRQn               = 101,    /*!< 117 SDFM2 */
    SDFM2_FLT1DR_IRQn        = 102,    /*!< 118 SDFM2 Filter1 Data Ready */
    SDFM2_FLT2DR_IRQn        = 103,    /*!< 119 SDFM2 Filter2 Data Ready */
    SDFM2_FLT3DR_IRQn        = 104,    /*!< 120 SDFM2 Filter3 Data Ready */
    SDFM2_FLT4DR_IRQn        = 105,    /*!< 121 SDFM2 Filter4 Data Ready */
    RESERVED122_IRQn         = 106,    /*!< 122 RESERVED */
    RESERVED123_IRQn         = 107,    /*!< 123 RESERVED */
    RESERVED124_IRQn         = 108,    /*!< 124 RESERVED */
    RESERVED125_IRQn         = 109,    /*!< 125 RESERVED */
    RESERVED126_IRQn         = 110,    /*!< 126 RESERVED */
    RESERVED127_IRQn         = 111,    /*!< 127 RESERVED */
    DMA_CH1_IRQn             = 112,    /*!< 128 DMA Channel1 */
    DMA_CH2_IRQn             = 113,    /*!< 129 DMA Channel2 */
    DMA_CH3_IRQn             = 114,    /*!< 130 DMA Channel3 */
    DMA_CH4_IRQn             = 115,    /*!< 131 DMA Channel4 */
    DMA_CH5_IRQn             = 116,    /*!< 132 DMA Channel5 */
    DMA_CH6_IRQn             = 117,    /*!< 133 DMA Channel6 */
    RESERVED134_IRQn         = 118,    /*!< 134 RESERVED */
    RESERVED135_IRQn         = 119,    /*!< 135 RESERVED */
    RESERVED136_IRQn         = 120,    /*!< 136 RESERVED */
    RESERVED137_IRQn         = 121,    /*!< 137 RESERVED */
    RESERVED138_IRQn         = 122,    /*!< 138 RESERVED */
    RESERVED139_IRQn         = 123,    /*!< 139 RESERVED */
    RESERVED140_IRQn         = 124,    /*!< 140 RESERVED */
    RESERVED141_IRQn         = 125,    /*!< 141 RESERVED */
    USBA_IRQn                = 126,    /*!< 142 USBA */
    USBA_EP_MP_IRQn          = 127,    /*!< 143 USBA EP MP */
    USBA_EP0_IRQn            = 128,    /*!< 144 USBA EP0 */
    USBA_EP1_IRQn            = 129,    /*!< 145 USBA EP1 */
    USBA_EP2_IRQn            = 130,    /*!< 146 USBA EP2 */
    USBA_EP3_IRQn            = 131,    /*!< 147 USBA EP3 */
    USBA_EP4_IRQn            = 132,    /*!< 148 USBA EP4 */
    USBA_EP5_IRQn            = 133,    /*!< 149 USBA EP5 */
    USBA_EP6_IRQn            = 134,    /*!< 150 USBA EP6 */
    USBA_EP7_IRQn            = 135,    /*!< 151 USBA EP7 */
    USBA_EP8_IRQn            = 136,    /*!< 152 USBA EP8 */
    USBA_EP9_IRQn            = 137,    /*!< 153 USBA EP9 */
    USBA_EP10_IRQn           = 138,    /*!< 154 USBA EP10 */
    USBA_EP11_IRQn           = 139,    /*!< 155 USBA EP11 */
    USBA_EP12_IRQn           = 140,    /*!< 156 USBA EP12 */
    USBA_EP13_IRQn           = 141,    /*!< 157 USBA EP13 */
    USBA_EP14_IRQn           = 142,    /*!< 158 USBA EP14 */
    USBA_EP15_IRQn           = 143,    /*!< 159 USBA EP15 */
    USBA_EP16_IRQn           = 144,    /*!< 160 USBA EP16 */
    USBA_EP17_IRQn           = 145,    /*!< 161 USBA EP17 */
    USBA_EP18_IRQn           = 146,    /*!< 162 USBA EP18 */
    USBA_EP19_IRQn           = 147,    /*!< 163 USBA EP19 */
    USBA_EP20_IRQn           = 148,    /*!< 164 USBA EP20 */
    USBA_EP21_IRQn           = 149,    /*!< 165 USBA EP21 */
    USBA_EP22_IRQn           = 150,    /*!< 166 USBA EP22 */
    USBA_EP23_IRQn           = 151,    /*!< 167 USBA EP23 */
    USBA_EP24_IRQn           = 152,    /*!< 168 USBA EP24 */
    USBA_EP25_IRQn           = 153,    /*!< 169 USBA EP25 */
    USBA_EP26_IRQn           = 154,    /*!< 170 USBA EP26 */
    USBA_EP27_IRQn           = 155,    /*!< 171 USBA EP27 */
    USBA_EP28_IRQn           = 156,    /*!< 172 USBA EP28 */
    USBA_EP29_IRQn           = 157,    /*!< 173 USBA EP29 */
    USBA_EP30_IRQn           = 158,    /*!< 174 USBA EP30 */
    USBA_EP31_IRQn           = 159,    /*!< 175 USBA EP31 */
    MCANA_INT0_IRQn          = 160,    /*!< 176 MCANA INT0 */
    MCANA_INT1_IRQn          = 161,    /*!< 177 MCANA INT1 */
    MCANB_INT0_IRQn          = 162,    /*!< 178 MCANB INT0 */
    MCANB_INT1_IRQn          = 163,    /*!< 179 MCANB INT1 */
    MCANC_INT0_IRQn          = 164,    /*!< 180 MCANC INT0 */
    MCANC_INT1_IRQn          = 165,    /*!< 181 MCANC INT1 */
    RESERVED182_IRQn         = 166,    /*!< 182 RESERVED */
    RESERVED183_IRQn         = 167,    /*!< 183 RESERVED */
    I2CA_IRQn                = 168,    /*!< 184 I2CA */
    I2CB_IRQn                = 169,    /*!< 185 I2CB */
    RESERVED186_IRQn         = 170,    /*!< 186 RESERVED */
    RESERVED187_IRQn         = 171,    /*!< 187 RESERVED */
    PMBUSA_IRQn              = 172,    /*!< 188 PMBUSA */
    RESERVED189_IRQn         = 173,    /*!< 189 RESERVED */
    RESERVED190_IRQn         = 174,    /*!< 190 RESERVED */
    RESERVED191_IRQn         = 175,    /*!< 191 RESERVED */
    UARTA_IRQn               = 176,    /*!< 192 UARTA */
    UARTB_IRQn               = 177,    /*!< 193 UARTB */
    UARTC_IRQn               = 178,    /*!< 194 UARTC */
    UARTD_IRQn               = 179,    /*!< 195 UARTD */
    SPIA_IRQn                = 180,    /*!< 196 SPIA */
    SPIB_IRQn                = 181,    /*!< 197 SPIB */
    SPIC_IRQn                = 182,    /*!< 198 SPIC */
    RESERVED199_IRQn         = 183,    /*!< 199 RESERVED */
    SRAM_ECC_ERR_IRQn        = 184,    /*!< 200 SRAM Correctable ECC Error */
    EFLASH_IRQn              = 185,    /*!< 201 EFLASH */
    SRAM_ACC_VIO_IRQn        = 186,    /*!< 202 SRAM Access Violation */
    EMIF1_ERR_IRQn           = 187,    /*!< 203 EMIF1 Error */
    WAKEUP_IRQn              = 188,    /*!< 204 WAKEUP */
    RESERVED205_IRQn         = 189,    /*!< 205 RESERVED */
    RESERVED206_IRQn         = 190,    /*!< 206 RESERVED */
    RESERVED207_IRQn         = 191,    /*!< 207 RESERVED */
    TFU_IRQn                 = 192,    /*!< 208 TFU */
    IPC_RAM_ERR_IRQn         = 193,    /*!< 209 IPC RAM Error */
} IRQn_Type;

/*!
 * @}
 */ /* end of HS32F7D377_CPU1_INTERRUPT */

/* Start of section using anonymous unions and disabling warnings */
#if   defined (__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined (__ICCARM__)
  #pragma language=extended
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wc11-extensions"
  #pragma clang diagnostic ignored "-Wreserved-id-macro"
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning 586
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif

/*!
 * \addtogroup HS32F7D377_CPU1_CORE_CONFIGURATION HS32F7D377 CPU1 Core Configuration
 *
 * \brief Cortex-M7 processor configurations
 *
 * @{
 */

#define __CM7_REV                 0x0102U    /*!< Core revision r1p2 */
#define __MPU_PRESENT             1U         /*!< MPU is present */
#define __VTOR_PRESENT            1U         /*!< VTOR is present */
#define __NVIC_PRIO_BITS          3U         /*!< Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig    0U         /*!< Set to 1 if different SysTick Config is used */
#define __FPU_PRESENT             1U         /*!< FPU is present */
#define __FPU_DP                  0U         /*!< Single precision FPU */
#define __ICACHE_PRESENT          1U         /*!< Instruction Cache is present */
#define __DCACHE_PRESENT          0U         /*!< Data Cache is not present */
#define __DTCM_PRESENT            1U         /*!< DTCM is present */

#include "core_cm7.h"                        /*!< Processor and core peripherals */
#include "system_HS32F7D377_cpu1.h"          /*!< System Header */

/*!
 * @}
 */ /* end of HS32F7D377_CPU1_CORE_CONFIGURATION */

/*!
 * \addtogroup HS32F7D377_CPU1_REGISTER HS32F7D377 CPU1 Register
 *
 * \brief HS32F7D377 CPU1 register layout, bitfield and address definitions
 *
 * @{
 */

#include "HS32F7D377_sysctrl_cpu1.h"
#include "HS32F7D377_adc.h"
#include "HS32F7D377_clb.h"
#include "HS32F7D377_crc.h"
#include "HS32F7D377_cmpss.h"
#include "HS32F7D377_dac.h"
#include "HS32F7D377_dma.h"
#include "HS32F7D377_ecap.h"
#include "HS32F7D377_eflash.h"
#include "HS32F7D377_emif.h"
#include "HS32F7D377_epwm.h"
#include "HS32F7D377_eqep.h"
#include "HS32F7D377_gpio_ctrl.h"
#include "HS32F7D377_gpio_data.h"
#include "HS32F7D377_hrpwm.h"
#include "HS32F7D377_i2c_pmbus.h"
#include "HS32F7D377_ipc_cpu1.h"
#include "HS32F7D377_mcan.h"
#include "HS32F7D377_tfu.h"
#include "HS32F7D377_sdfm.h"
#include "HS32F7D377_stimer.h"
#include "HS32F7D377_spi.h"
#include "HS32F7D377_syncsoc.h"
#include "HS32F7D377_uart.h"
#include "HS32F7D377_usb.h"
#include "HS32F7D377_wdt.h"
#include "HS32F7D377_xbar.h"
#include "HS32F7D377_xint.h"

/*!
 * @}
 */ /* end of HS32F7D377_CPU1_REGISTER */

/*!
 * \addtogroup HS32F7D377_CPU1_MEMORY HS32F7D377 CPU1 Memory
 *
 * \brief Memory definitions
 *
 * @{
 */

#define ITCM_BASE                 (0x00000000UL)    /*!< CPU1 ITCM Base Address */
#define ITCM_SIZE                 (0x00020000UL)    /*!< CPU1 ITCM Size In Bytes: 128KB */
#define SRAM0_BASE                (0x00200000UL)    /*!< SRAM0 Base Address */
#define SRAM0_SIZE                (0x00020000UL)    /*!< SRAM0 Size In Bytes: 128KB */
#define CPU2_ITCM_BASE            (0x01000000UL)    /*!< CPU2 ITCM Remap Base Address */
#define CPU2_ITCM_SIZE            (0x00020000UL)    /*!< CPU2 ITCM Remap Size In Bytes: 128KB */
#define SRAM1_BASE                (0x10200000UL)    /*!< SRAM1 Base Address */
#define SRAM1_SIZE                (0x00020000UL)    /*!< SRAM1 Size In Bytes: 128KB */
#define DTCM_BASE                 (0x20000000UL)    /*!< CPU1 DTCM Base Address */
#define DTCM_SIZE                 (0x00020000UL)    /*!< CPU1 DTCM Size In Bytes: 128KB */
#define CPU2_DTCM_BASE            (0x21000000UL)    /*!< CPU2 DTCM Remap Base Address */
#define CPU2_DTCM_SIZE            (0x00020000UL)    /*!< CPU2 DTCM Remap Size In Bytes: 128KB */
#define ROM_BASE                  (0x00100000UL)    /*!< CPU1 ROM Base Address */
#define ROM_SIZE                  (0x00008000UL)    /*!< CPU1 ROM Size In Bytes: 32KB */
#define CPU2_ROM_BASE             (0x10100000UL)    /*!< CPU2 ROM Base Address */
#define CPU2_ROM_SIZE             (0x00004000UL)    /*!< CPU2 ROM Size In Bytes: 16KB */
#define EFLASH0_MEM_BASE          (0x00300000UL)    /*!< EFLASH0 Memory Base Address */
#define EFLASH0_MEM_SIZE          (0x00100000UL)    /*!< EFLASH0 Memory Size In Bytes: 1MB */
#define EFLASH1_MEM_BASE          (0x10300000UL)    /*!< EFLASH1 Memory Base Address */
#define EFLASH1_MEM_SIZE          (0x00100000UL)    /*!< EFLASH1 Memory Size In Bytes: 1MB */
#define CPU1TOCPU2_MSGRAM_BASE    (0x40001000UL)    /*!< CPU1 TO CPU2 Message RAM Base Address */
#define CPU1TOCPU2_MSGRAM_SIZE    (0x00001000UL)    /*!< CPU1 TO CPU2 Message RAM Size In Bytes: 4KB */
#define CPU2TOCPU1_MSGRAM_BASE    (0x40002000UL)    /*!< CPU2 TO CPU1 Message RAM Base Address */
#define CPU2TOCPU1_MSGRAM_SIZE    (0x00001000UL)    /*!< CPU2 TO CPU1 Message RAM Size In Bytes: 4KB */

/*!
 * @}
 */ /* end of HS32F7D377_CPU1_MEMORY */

/* End of section using anonymous unions and disabling warnings */
#if   defined (__CC_ARM)
  #pragma pop
#elif defined (__ICCARM__)
  /* leave anonymous unions enabled */
#elif (defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050))
  #pragma clang diagnostic pop
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning restore
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif

/* clang-format on */

/*!
 * @}
 */ /* end of HS32F7D377_CPU1_DEVICE */

#endif /* HS32F7D377_CPU1_H */
