/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file clock_config.h
 * \brief HS32F7D377 EVB clock configuration header file
 * \version 1.0.0
 */

#ifndef CLOCK_CONFIG_H
#define CLOCK_CONFIG_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_common.h"

/*!
 * \addtogroup EVB_HS32F7D377_CLOCK_CONFIG HS32F7D377 EVB Clock Configuration
 *
 * \brief HS32F7D377 EVB clock configuration driver
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define SRC_CLKDIV_1 (1U) /*!< source clk div 1 */
#define SRC_CLKDIV_2 (2U) /*!< source clk div 2 */
#define SRC_CLKDIV_3 (3U) /*!< source clk div 3 */
#define SRC_CLKDIV_4 (4U) /*!< source clk div 4 */
#define SRC_CLKDIV_6 (6U) /*!< source clk div 6 */
#define SRC_CLKDIV_8 (8U) /*!< source clk div 8 */


#define SYSOUT_CLKDIV_1   (0U)  /*!< sys clk out div 1 */
#define SYSOUT_CLKDIV_2   (1U)  /*!< sys clk out div 2 */
#define SYSOUT_CLKDIV_4   (2U)  /*!< sys clk out div 4 */
#define SYSOUT_CLKDIV_6   (3U)  /*!< sys clk out div 6 */
#define SYSOUT_CLKDIV_8   (4U)  /*!< sys clk out div 8 */
#define SYSOUT_CLKDIV_10  (5U)  /*!< sys clk out div 10 */
#define SYSOUT_CLKDIV_16  (8U)  /*!< sys clk out div 16 */
#define SYSOUT_CLKDIV_32  (16U) /*!< sys clk out div 32 */
#define SYSOUT_CLKDIV_64  (32U) /*!< sys clk out div 64 */
#define SYSOUT_CLKDIV_128 (64U) /*!< sys clk out div 128 */

#define OSC_XTALIN   (8000000U) //(20000000U)  /*!< xtal in freq */
#define OSC_OSC2IN   (10000000U)  /*!< osc2 in freq */
#define OSC_AUXCLKIN (20000000U)  /*!< aux clk in freq */
#define SRC_CLKDIV   SRC_CLKDIV_1   //SRC_CLKDIV_2 /*!< source clk div */

#define PLL_CLKOUT    (300000000U) /*!< pll clk out freq */
#define AUXPLL_CLKOUT (192000000U) /*!< aux pll clk out freq */

#define SYS_CLKDIV SYSOUT_CLKDIV_1 /*!< sysclk out div */
#define AUX_CLKDIV SYSOUT_CLKDIV_4 /*!< auxclk out div */

#define PLL_ENABLE  true  /*!< pll enable */
#define PLL_DISABLE false /*!< pll disable */

/*! \brief Enable the XCLKOUT to test clk if set to 1 */
#define TEST_CLK 0

/*! \brief Tick interrupt priority */
#define TICK_INT_PRIORITY 4

/*! \brief Check tick frequency value */
#define IS_TICKFREQ(FREQ) \
    (((FREQ) == kHAL_TICK_FREQ_10HZ) || ((FREQ) == kHAL_TICK_FREQ_100HZ) || ((FREQ) == kHAL_TICK_FREQ_1KHZ))

/*! \brief Definition of SysTick frequency */
typedef enum
{
    kHAL_TICK_FREQ_10HZ  = 100U, /*!< 10Hz for tick */
    kHAL_TICK_FREQ_100HZ = 10U,  /*!< 100Hz for tick */
    kHAL_TICK_FREQ_1KHZ  = 1U,   /*!< 1KHz for tick */
} SYSTICK_Freq_t;

/*! \brief structure definition of MCU clocks */
typedef struct
{
    uint32_t tag;          /*!< clock inf tag to indicate the value is valid or not */
    uint32_t xtalClkIn;    /*!< clock inf for XTAL clock input */
    uint32_t sysClk;       /*!< clock inf for SYSCLK */
    uint32_t sysPclk;      /*!< clock inf for SYSPCLK */
    uint32_t periphClk;    /*!< clock inf for peripheral clock */
    uint32_t auxClkIn;     /*!< clock inf for AUX clock input */
    uint32_t auxPllRawClk; /*!< clock inf for AUXPLL Raw clock */
    uint32_t auxPllClk;    /*!< clock inf for AUXPLL clock */
} SYSTEM_Clock_t;

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! \brief Global clk config variable */
extern SYSTEM_Clock_t g_clockConfig;

/*******************************************************************************
 * APIs
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Store clock information to CPU1TOCPU2 MSGRAM
 *
 * \note This function shall be executed by CPU1 which is the main core, not CPU2
 */
void BOARD_clockInfStore(void);

/*!
 * \brief Get clock information from CPU1TOCPU2 MSGRAM
 *
 * \note This function shall be executed by CPU2 which is the secondary core, not CPU1
 */
void BOARD_clockInfGet(void);

/*!
 * \brief Configure clocks of the MCU
 */
void BOARD_clockConfig(void);

/*!
 * \brief Configure clocks of the MCU for CPU2
 *
 * \note This function shall be executed by CPU1 which is the main core, not CPU2
 */
void BOARD_clockConfigForCPU2(void);

/*!
 * \brief Enable UART clock
 *
 * \param[in] base the UART base address
 */
void BOARD_uartClockEnable(UART_Type *base);

/*!
 * \brief Enable I2C clock
 *
 * \param[in] base the I2C base address
 */
void BOARD_i2cClockEnable(I2C_Type *base);

/*!
 * \brief Enable PMBUS clock
 *
 * \param[in] base the PMBUS base address
 */
void BOARD_pmbusClockEnable(PMBUS_Type *base);

/*!
 * \brief Enable SPI clock
 *
 * \param[in] base the SPI base address
 */
void BOARD_spiClockEnable(SPI_Type *base);

/*!
 * \brief Enable MCAN clock
 *
 * \param[in] base the MCAN base address
 */
void BOARD_mcanClockEnable(MCAN_Type *base);

/*!
 * \brief Enable EPWM clock
 *
 * \param[in] base the EPWM base address
 */
void BOARD_epwmClockEnable(EPWM_REGS_Type *base);

/*!
 * \brief Enable ECAP clock
 *
 * \param[in] base the ECAP base address
 */
void BOARD_ecapClockEnable(ECAP_Type *base);

/*!
 * \brief Enable EQEP clock
 *
 * \param[in] base the EQEP base address
 */
void BOARD_eqepClockEnable(EQEP_REGS_Type *base);

/*!
 * \brief Enable EMIF clock
 *
 * \param[in] base the EMIF base address
 */
void BOARD_emifClockEnable(EMIF_Type *base);

/*!
 * \brief Enable SDFM clock
 *
 * \param[in] base the SDFM base address
 */
void BOARD_sdfmClockEnable(SDFM_REGS_Type *base);

/*!
 * \brief Enable USB clock
 *
 * \param[in] base the USB base address
 */
void BOARD_usbClockEnable(USB_Type *base);

/*!
 * \brief Enable ADC clock
 *
 * \param[in] base the ADC base address
 */
void BOARD_adcClockEnable(ADC_Type *base);

/*!
 * \brief Enable DAC clock
 *
 * \param[in] base the DAC base address
 */
void BOARD_dacClockEnable(DAC_REGS_Type *base);

/*!
 * \brief Enable DMA clock
 *
 * \param[in] base the DMA base address
 */
void BOARD_dmaClockEnable(DMA_Type *base);

/*!
 * \brief Enable CPUTIMER clock
 *
 * \param[in] base the CPUTIMER base address
 */
void BOARD_cputimerClockEnable(CPUTIMER_REGS_Type *base);

/*!
 * \brief Enable stimer clock
 *
 * \param[in] base the STIMER base address
 */
void BOARD_stimerClockEnable(STIMER_Type *base, uint32_t channel);

/*!
 * \brief Enable CMPSS clock
 *
 * \param[in] base the CMPSS base address
 */
void BOARD_cmpssClockEnable(CMPSS_Type *base);

/*!
 * \brief Enable CLB clock
 *
 * \param[in] base the CLK base address
 */
void BOARD_clbClockEnable(CLB_TILE_Type *base);

/*!
 * \brief Initialize SysTick as tick timer
 *
 * \return status
 */
status_t BOARD_initTick(void);

/*!
 * \brief Get current SysTick tick value
 *
 * \return SysTick tick value
 */
uint32_t BOARD_getTick(void);

/*!
 * \brief Set SysTick frequency
 *
 * \param[in] freq the SysTick base address
 *
 * \return status
 */
status_t BOARD_setSystickFreq(SYSTICK_Freq_t freq);

/*!
 * \brief Get SysTick frequency
 *
 * \return SysTick frequency in Hz
 */
SYSTICK_Freq_t BOARD_getSystickFreq(void);

/*!
 * \brief get XTAL clock input frequency
 *
 * \return XTAL clock input frequency in Hz
 */
static inline uint32_t BOARD_getXtalClkIn(void)
{
    return g_clockConfig.xtalClkIn;
}

/*!
 * \brief Get SYSCLK frequency
 *
 * \return SYSCLK frequency in Hz
 */
static inline uint32_t BOARD_getSysclk(void)
{
    return g_clockConfig.sysClk;
}

/*!
 * \brief Get SYSPCLK frequency
 *
 * \return SYSPCLK frequency in Hz
 */
static inline uint32_t BOARD_getSysPclk(void)
{
    return g_clockConfig.sysPclk;
}

/*!
 * \brief Get peripheral clock frequency
 *
 * \return Peripheral clock frequency in Hz
 */
static inline uint32_t BOARD_getPeripheralClk(void)
{
    return g_clockConfig.periphClk;
}

/*!
 * \brief Get AUX clock input frequency
 *
 * \return AUX clock input frequency in Hz
 */
static inline uint32_t BOARD_getAuxClkIn(void)
{
    return g_clockConfig.auxClkIn;
}

/*!
 * \brief get AUX RAW clock frequency
 *
 * \return AUX RAW clock frequency in Hz
 */
static inline uint32_t BOARD_getAuxRawClk(void)
{
    return g_clockConfig.auxPllRawClk;
}

/*!
 * \brief Get AUX CLK frequency
 *
 * \return AUX CLK frequency in Hz
 */
static inline uint32_t BOARD_getAuxClk(void)
{
    return g_clockConfig.auxPllClk;
}

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */ /*end of EVB_HS32F7D377_CLOCK_CONFIG */

#endif /* CLOCK_CONFIG_H */
