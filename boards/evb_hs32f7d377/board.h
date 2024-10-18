/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file board.h
 * \brief HS32F7D377 EVB board configuration header file
 * \version 1.0.0
 */

#ifndef BOARD_H
#define BOARD_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "clock_config.h"
#include "hte_common.h"
#include "hte_debug_console.h"
#include "pin_config.h"

/*!
 * \addtogroup EVB_HS32F7D377_BOARD HS32F7D377 EVB Board Configuration
 *
 * \brief HS32F7D377 EVB board configuration driver
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#if defined(HTE_DEVICE_HS32F7D377_CPU1)
#define BOARD_USE_CPU1 (1) /*!< Select CPU1 to run the software */
#elif defined(HTE_DEVICE_HS32F7D377_CPU2)
#define BOARD_USE_CPU2 (1) /*!< Select CPU2 to run the software */
#endif

#define BOARD_DEBUG_CONSOLE_TYPE                      (kDEBUG_CONSOLE_TYPE_UART) /*!< Select UART as debug console */
#define BOARD_DEBUG_CONSOLE_BASE_CPU1                 (UARTA_BASE) /*!< Select UARTA as CPU1 debug console */
#define BOARD_DEBUG_CONSOLE_SYSCTL_PERIPH_CPUSEL_CPU1 (kSYSCTL_PERIPH_CPUSEL_UARTA) /*!< Assign UARTA to CPU1 */
#define BOARD_DEBUG_CONSOLE_SYSCTL_PERIPH_CLK_CPU1    (kSYSCTL_PERIPH_CLK_UARTA) /*!< Enable UARTA clock on CPU1 side */
#define BOARD_DEBUG_CONSOLE_BASE_CPU2                 (UARTB_BASE) /*!< Select UARTB as CPU2 debug console */
#define BOARD_DEBUG_CONSOLE_SYSCTL_PERIPH_CPUSEL_CPU2 (kSYSCTL_PERIPH_CPUSEL_UARTB) /*!< Assign UARTB to CPU2 */
#define BOARD_DEBUG_CONSOLE_SYSCTL_PERIPH_CLK_CPU2    (kSYSCTL_PERIPH_CLK_UARTB) /*!< Enable UARTB clock on CPU2 side */

#if defined(BOARD_USE_CPU1)
#define BOARD_DEBUG_CONSOLE_BASE (BOARD_DEBUG_CONSOLE_BASE_CPU1) /*!< Select CPU1 debug console */
#define BOARD_DEBUG_CONSOLE_SYSCTL_PERIPH_CLK \
    (BOARD_DEBUG_CONSOLE_SYSCTL_PERIPH_CLK_CPU1) /*!< Enable CPU1 debug console clock */
#elif defined(BOARD_USE_CPU2)
#define BOARD_DEBUG_CONSOLE_BASE (BOARD_DEBUG_CONSOLE_BASE_CPU2) /*!< Select CPU2 debug console */
#define BOARD_DEBUG_CONSOLE_SYSCTL_PERIPH_CLK \
    (BOARD_DEBUG_CONSOLE_SYSCTL_PERIPH_CLK_CPU2) /*!< Enable CPU2 debug console clock */
#endif
#define BOARD_DEBUG_CONSOLE_BAUDRATE (115200U)                  /*!< Set debug console baud rate to 115200 */
#define BOARD_DEBUG_CONSOLE_CLOCK (BOARD_getPeripheralClk()) /*!< UART peripheral clock */

/*!< \brief GPIO active state */
enum
{
    kBOARD_GPIO_ACTIVE_LOW  = 0U, /*!< Active when GPIO input/output is low */
    kBOARD_GPIO_ACTIVE_HIGH = 1U, /*!< Active when GPIO input/output is high */
};

#define BOARD_GPIO_LED0                (82U)                    /*!< GPIO82 is used to control LED0 */
#define BOARD_GPIO_LED0_PINMUX         (GPIO_82_GPIO82)         /*!< GPIO82 pinmux to control LED0 */
#define BOARD_GPIO_LED1                (88U)                    /*!< GPIO88 is used to control LED1 */
#define BOARD_GPIO_LED1_PINMUX         (GPIO_88_GPIO88)         /*!< GPIO88 pinmux to control LED1 */
#define BOARD_GPIO_LED2                (93U)                    /*!< GPIO93 is used to control LED2 */
#define BOARD_GPIO_LED2_PINMUX         (GPIO_93_GPIO93)         /*!< GPIO93 pinmux to control LED2 */
#define BOARD_GPIO_LED3                (94U)                    /*!< GPIO94 is used to control LED3 */
#define BOARD_GPIO_LED3_PINMUX         (GPIO_94_GPIO94)         /*!< GPIO94 pinmux to control LED3 */
#define BOARD_GPIO_LED_ACTIVE_POLARITY (kBOARD_GPIO_ACTIVE_LOW) /*!< LED is lighten up when GPIO output is low */

#define BOARD_GPIO_BUTTON0                (78U)                    /*!< GPIO78 is used to control BUTTON0 */
#define BOARD_GPIO_BUTTON0_PINMUX         (GPIO_78_GPIO78)         /*!< GPIO78 pinmux to control BUTTON0 */
#define BOARD_GPIO_BUTTON1                (79U)                    /*!< GPIO79 is used to control BUTTON1 */
#define BOARD_GPIO_BUTTON1_PINMUX         (GPIO_79_GPIO79)         /*!< GPIO79 pinmux to control BUTTON1 */
#define BOARD_GPIO_BUTTON2                (80U)                    /*!< GPIO80 is used to control BUTTON2 */
#define BOARD_GPIO_BUTTON2_PINMUX         (GPIO_80_GPIO80)         /*!< GPIO80 pinmux to control BUTTON2 */
#define BOARD_GPIO_BUTTON3                (81U)                    /*!< GPIO81 is used to control BUTTON3 */
#define BOARD_GPIO_BUTTON3_PINMUX         (GPIO_81_GPIO81)         /*!< GPIO81 pinmux to control BUTTON3 */
#define BOARD_GPIO_BUTTON_ACTIVE_POLARITY (kBOARD_GPIO_ACTIVE_LOW) /*!< GPIO input is low when button is pressed */

/*******************************************************************************
 * API
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Execute default initialization of board
 */
void BOARD_init(void);

/*!
 * \brief Execute default configuration of mpu
 */
void BOARD_mpuConfig(void);

/*!
 * \brief Debug Console initialization
 */
void BOARD_debugConsoleInit(void);

/*!
 * \brief Debug Console deinitialization
 */
void BOARD_debugConsoleDeinit(void);

/*!
 * \brief Execute default initialization of board for CPU2
 *
 * \note This function shall be executed by CPU1 which is the main core, not CPU2
 */
void BOARD_initForCPU2(void);

/*!
 * \brief Execute Debug Console initialization for CPU2
 *
 * \note This function shall be executed by CPU1 which is the main core, not CPU2
 */
void BOARD_debugConsoleInitForCPU2(void);

/*!
 * \brief Assign an UART to CPU2
 *
 * \note This function shall be executed by CPU1 which is the main core, not CPU2
 *
 * \param[in] base UART base address
 */
void BOARD_uartAssign2CPU2(UART_Type *base);

/*!
 * \brief Assign an ECAP to CPU2
 *
 * \note This function shall be executed by CPU1 which is the main core, not CPU2
 *
 * \param[in] base ECAP base address
 */
void BOARD_ecapAssign2CPU2(ECAP_Type *base);

/*!
 * \brief Assign an EPWM to CPU2
 *
 * \note This function shall be executed by CPU1 which is the main core, not CPU2
 *
 * \param[in] base EPWM base address
 */
void BOARD_epwmAssign2CPU2(EPWM_REGS_Type *base);

/*!
 * \brief Assign an I2C to CPU2
 *
 * \note This function shall be executed by CPU1 which is the main core, not CPU2
 *
 * \param[in] base I2C base address
 */
void BOARD_i2cAssign2CPU2(I2C_Type *base);

/*!
 * \brief Assign a PMBUS to CPU2
 *
 * \note This function shall be executed by CPU1 which is the main core, not CPU2
 *
 * \param[in] base SMBUS/PMBUS base address
 */
void BOARD_pmbusAssign2CPU2(PMBUS_Type *base);

/*!
 * \brief Assign an ADC to CPU2
 *
 * \note This function shall be executed by CPU1 which is the main core, not CPU2
 *
 * \param[in] base ADC base address
 */
void BOARD_adcAssign2CPU2(ADC_Type *base);

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */ /* end of EVB_HS32F7D377_BOARD */

#endif /* BOARD_H */
