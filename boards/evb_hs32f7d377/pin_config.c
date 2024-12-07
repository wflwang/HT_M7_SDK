/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file pin_config.c
 * \brief HS32F7D377 EVB Pin configuration source file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "board.h"
#include "hte_gpio.h"
#include "hte_pinmux.h"
#include "hte_sysctrl.h"
#include "hte_xbar.h"
#include "hte_xbarmux.h"
#include "pin_config.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define INPUT_XBAR_XINT1 (kXBAR_INPUT4)  /*!< Pick INPUTXBAR4 as XINT1 input */
#define INPUT_XBAR_XINT2 (kXBAR_INPUT5)  /*!< Pick INPUTXBAR5 as XINT2 input */
#define INPUT_XBAR_XINT3 (kXBAR_INPUT6)  /*!< Pick INPUTXBAR6 as XINT3 input */
#define INPUT_XBAR_ECAPx (kXBAR_INPUT7)  /*!< Pick INPUTXBAR7 as ECAPx input */
#define INPUT_XBAR_ECAPy (kXBAR_INPUT8)  /*!< Pick INPUTXBAR8 as ECAPy input */
#define INPUT_XBAR_XINT4 (kXBAR_INPUT13) /*!< Pick INPUTXBAR13 as XINT4 input */
#define INPUT_XBAR_XINT5 (kXBAR_INPUT14) /*!< Pick INPUTXBAR14 as XINT5 input */

#define OUTPUT_XBAR_ECAP1 (kXBAR_OUTPUT1) /*!< Pick OUTPUTXBAR1 as ECAP1 output */
#define OUTPUT_XBAR_ECAP2 (kXBAR_OUTPUT2) /*!< Pick OUTPUTXBAR2 as ECAP2 output */
#define OUTPUT_XBAR_ECAP3 (kXBAR_OUTPUT3) /*!< Pick OUTPUTXBAR3 as ECAP3 output */
#define OUTPUT_XBAR_ECAP4 (kXBAR_OUTPUT4) /*!< Pick OUTPUTXBAR4 as ECAP4 output */
#define OUTPUT_XBAR_ECAP5 (kXBAR_OUTPUT5) /*!< Pick OUTPUTXBAR5 as ECAP5 output */
#define OUTPUT_XBAR_ECAP6 (kXBAR_OUTPUT6) /*!< Pick OUTPUTXBAR6 as ECAP6 output */

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
void BOARD_ledPinConfig(uint32_t instance)
{
    switch (instance)
    {
        case 0:
            GPIO_setPinConfig(BOARD_GPIO_LED0_PINMUX);
            GPIO_setPadConfig(BOARD_GPIO_LED0, kGPIO_PADCONFIG_STD);
            break;
        case 1:
            GPIO_setPinConfig(BOARD_GPIO_LED1_PINMUX);
            GPIO_setPadConfig(BOARD_GPIO_LED1, kGPIO_PADCONFIG_STD);
            break;
        case 2:
            GPIO_setPinConfig(BOARD_GPIO_LED2_PINMUX);
            GPIO_setPadConfig(BOARD_GPIO_LED2, kGPIO_PADCONFIG_STD);
            break;
        case 3:
            GPIO_setPinConfig(BOARD_GPIO_LED3_PINMUX);
            GPIO_setPadConfig(BOARD_GPIO_LED3, kGPIO_PADCONFIG_STD);
            break;
        default:
            /* No operation */
            break;
    }
}

void BOARD_buttonPinConfig(uint32_t instance)
{
    switch (instance)
    {
        case 0:
            GPIO_setPinConfig(BOARD_GPIO_BUTTON0_PINMUX);
            GPIO_setPadConfig(BOARD_GPIO_BUTTON0, kGPIO_PADCONFIG_STD);
            break;
        case 1:
            GPIO_setPinConfig(BOARD_GPIO_BUTTON1_PINMUX);
            GPIO_setPadConfig(BOARD_GPIO_BUTTON1, kGPIO_PADCONFIG_STD);
            break;
        case 2:
            GPIO_setPinConfig(BOARD_GPIO_BUTTON2_PINMUX);
            GPIO_setPadConfig(BOARD_GPIO_BUTTON2, kGPIO_PADCONFIG_STD);
            break;
        case 3:
            GPIO_setPinConfig(BOARD_GPIO_BUTTON3_PINMUX);
            GPIO_setPadConfig(BOARD_GPIO_BUTTON3, kGPIO_PADCONFIG_STD);
            break;
        default:
            /* No operation */
            break;
    }
}

void BOARD_uartPinConfig(UART_Type *base)
{
    if (base == UARTA)
    {
        //GPIO_setPinConfig(GPIO_84_UARTA_TXD);
        //GPIO_setPinConfig(GPIO_42_UARTA_TXD);
        //GPIO_setPadConfig(84U, kGPIO_PADCONFIG_PULLUP);
        //GPIO_setPadConfig(42U, kGPIO_PADCONFIG_PULLUP);
        //GPIO_setPinConfig(GPIO_85_UARTA_RXD);
        //GPIO_setPinConfig(GPIO_43_UARTA_RXD);
        //GPIO_setPadConfig(85U, kGPIO_PADCONFIG_PULLUP);
        //GPIO_setPadConfig(43U, kGPIO_PADCONFIG_PULLUP);
        GPIO_setPinConfig(GPIO_8_UARTA_TXD);
        GPIO_setPadConfig(8U, kGPIO_PADCONFIG_PULLUP);
        GPIO_setPinConfig(GPIO_9_UARTA_RXD);
        GPIO_setPadConfig(9U, kGPIO_PADCONFIG_PULLUP);
    }
    else if (base == UARTB)
    {
        GPIO_setPinConfig(GPIO_86_UARTB_TXD);
        GPIO_setPadConfig(86U, kGPIO_PADCONFIG_PULLUP);
        GPIO_setPinConfig(GPIO_87_UARTB_RXD);
        GPIO_setPadConfig(87U, kGPIO_PADCONFIG_PULLUP);
    }
    else if (base == UARTC)
    {
        GPIO_setPinConfig(GPIO_89_UARTC_TXD);
        GPIO_setPadConfig(89U, kGPIO_PADCONFIG_PULLUP);
        GPIO_setPinConfig(GPIO_90_UARTC_RXD);
        GPIO_setPadConfig(90U, kGPIO_PADCONFIG_PULLUP);
    }
    else if (base == UARTD)
    {
        GPIO_setPinConfig(GPIO_76_UARTD_TXD);
        GPIO_setPadConfig(76U, kGPIO_PADCONFIG_PULLUP);
        GPIO_setPinConfig(GPIO_77_UARTD_RXD);
        GPIO_setPadConfig(77U, kGPIO_PADCONFIG_PULLUP);
    }
}

void BOARD_i2cPinConfig(I2C_Type *base)
{
    if (base == I2CA)
    {
        GPIO_setPinConfig(GPIO_91_I2CA_SDA);
        GPIO_setPadConfig(91U, kGPIO_PADCONFIG_PULLUP);
        GPIO_setPinConfig(GPIO_92_I2CA_SCL);
        GPIO_setPadConfig(92U, kGPIO_PADCONFIG_PULLUP);
    }
    else if (base == I2CB)
    {
        GPIO_setPinConfig(GPIO_40_I2CB_SDA);
        GPIO_setPadConfig(40U, kGPIO_PADCONFIG_PULLUP);
        GPIO_setPinConfig(GPIO_41_I2CB_SCL);
        GPIO_setPadConfig(41U, kGPIO_PADCONFIG_PULLUP);
    }
}

void BOARD_pmbusPinConfig(PMBUS_Type *base)
{
    if (base == PMBUSA)
    {
        GPIO_setPinConfig(GPIO_25_PMBUSA_SDA);
        GPIO_setPadConfig(25U, kGPIO_PADCONFIG_PULLUP);
        GPIO_setPinConfig(GPIO_24_PMBUSA_SCL);
        GPIO_setPadConfig(24U, kGPIO_PADCONFIG_PULLUP);
        GPIO_setPinConfig(GPIO_26_PMBUSA_ALERT);
        GPIO_setPadConfig(26U, kGPIO_PADCONFIG_PULLUP);
        GPIO_setPinConfig(GPIO_27_PMBUSA_CTL);
        GPIO_setPadConfig(27U, kGPIO_PADCONFIG_PULLUP);
    }
}

void BOARD_spiPinConfig(SPI_Type *base)
{
    if (base == SPIA)
    {
        GPIO_setPinConfig(GPIO_58_SPIA_SIMO);
        GPIO_setPadConfig(58U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_59_SPIA_SOMI);
        /* Pull-up is suggested on SOMI to make sure the pin is not floating when slave is not selected */
        GPIO_setPadConfig(59U, kGPIO_PADCONFIG_PULLUP);
        GPIO_setPinConfig(GPIO_60_SPIA_CLK);
        GPIO_setPadConfig(60U, kGPIO_PADCONFIG_STD);
        /* Pull-up is suggested on STEN to make sure the slave is not selected by default */
        GPIO_setPinConfig(GPIO_61_SPIA_STEN);
        GPIO_setPadConfig(61U, kGPIO_PADCONFIG_PULLUP);
    }
    else if (base == SPIB)
    {
        GPIO_setPinConfig(GPIO_63_SPIB_SIMO);
        GPIO_setPadConfig(63U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_64_SPIB_SOMI);
        /* Pull-up is suggested on SOMI to make sure the pin is not floating when slave is not selected */
        GPIO_setPadConfig(64U, kGPIO_PADCONFIG_PULLUP);
        GPIO_setPinConfig(GPIO_65_SPIB_CLK);
        GPIO_setPadConfig(65U, kGPIO_PADCONFIG_STD);
        /* Pull-up is suggested on STEN to make sure the slave is not selected by default */
        GPIO_setPinConfig(GPIO_66_SPIB_STEN);
        GPIO_setPadConfig(66U, kGPIO_PADCONFIG_PULLUP);
    }
    else if (base == SPIC)
    {
        GPIO_setPinConfig(GPIO_50_SPIC_SIMO);
        GPIO_setPadConfig(50U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_51_SPIC_SOMI);
        /* Pull-up is suggested on SOMI to make sure the pin is not floating when slave is not selected */
        GPIO_setPadConfig(51U, kGPIO_PADCONFIG_PULLUP);
        GPIO_setPinConfig(GPIO_52_SPIC_CLK);
        GPIO_setPadConfig(52U, kGPIO_PADCONFIG_STD);
        /* Pull-up is suggested on STEN to make sure the slave is not selected by default */
        GPIO_setPinConfig(GPIO_53_SPIC_STEN);
        GPIO_setPadConfig(53U, kGPIO_PADCONFIG_PULLUP);
    }
}
void BOARD_mcanPinConfig(MCAN_Type *base)
{
    if (base == MCANA)
    {
        GPIO_setPinConfig(GPIO_128_MCANA_TX);
        GPIO_setPadConfig(128U, kGPIO_PADCONFIG_PULLUP);
        GPIO_setPinConfig(GPIO_129_MCANA_RX);
        GPIO_setPadConfig(129U, kGPIO_PADCONFIG_PULLUP);
    }
    else if (base == MCANB)
    {
        //GPIO_setPinConfig(GPIO_72_MCANB_TX);
        //GPIO_setPadConfig(72U, kGPIO_PADCONFIG_PULLUP);
        //GPIO_setPinConfig(GPIO_73_MCANB_RX);
        //GPIO_setPadConfig(73U, kGPIO_PADCONFIG_PULLUP);
        GPIO_setPinConfig(GPIO_6_MCANB_TX);
        GPIO_setPadConfig(6U, kGPIO_PADCONFIG_PULLUP);
        GPIO_setPinConfig(GPIO_7_MCANB_RX);
        GPIO_setPadConfig(7U, kGPIO_PADCONFIG_PULLUP);
    }
    else if (base == MCANC)
    {
        GPIO_setPinConfig(GPIO_74_MCANC_TX);
        GPIO_setPadConfig(74U, kGPIO_PADCONFIG_PULLUP);
        GPIO_setPinConfig(GPIO_75_MCANC_RX);
        GPIO_setPadConfig(75U, kGPIO_PADCONFIG_PULLUP);
    }
}

void BOARD_epwmPinConfig(EPWM_REGS_Type *base)
{
    if (base == EPWM1)
    {
        GPIO_setPinConfig(GPIO_0_EPWM1_A);
        GPIO_setPadConfig(0U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(0U, kGPIO_QUAL_ASYNC);
        GPIO_setPinConfig(GPIO_1_EPWM1_B);
        GPIO_setPadConfig(1U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(1U, kGPIO_QUAL_ASYNC);
    }
    else if (base == EPWM2)
    {
        GPIO_setPinConfig(GPIO_2_EPWM2_A);
        GPIO_setPadConfig(2U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(2U, kGPIO_QUAL_ASYNC);
        GPIO_setPinConfig(GPIO_3_EPWM2_B);
        GPIO_setPadConfig(3U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(3U, kGPIO_QUAL_ASYNC);
    }
    else if (base == EPWM3)
    {
        GPIO_setPinConfig(GPIO_4_EPWM3_A);
        GPIO_setPadConfig(4U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(4U, kGPIO_QUAL_ASYNC);
        GPIO_setPinConfig(GPIO_5_EPWM3_B);
        GPIO_setPadConfig(5U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(5U, kGPIO_QUAL_ASYNC);
    }
    else if (base == EPWM4)
    {
        GPIO_setPinConfig(GPIO_6_EPWM4_A);
        GPIO_setPadConfig(6U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(6U, kGPIO_QUAL_ASYNC);
        GPIO_setPinConfig(GPIO_7_EPWM4_B);
        GPIO_setPadConfig(7U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(7U, kGPIO_QUAL_ASYNC);
    }
    else if (base == EPWM5)
    {
        GPIO_setPinConfig(GPIO_8_EPWM5_A);
        GPIO_setPadConfig(8U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(8U, kGPIO_QUAL_ASYNC);
        GPIO_setPinConfig(GPIO_9_EPWM5_B);
        GPIO_setPadConfig(9U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(9U, kGPIO_QUAL_ASYNC);
    }
    else if (base == EPWM6)
    {
        GPIO_setPinConfig(GPIO_10_EPWM6_A);
        GPIO_setPadConfig(10U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(10U, kGPIO_QUAL_ASYNC);
        GPIO_setPinConfig(GPIO_11_EPWM6_B);
        GPIO_setPadConfig(11U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(11U, kGPIO_QUAL_ASYNC);
    }
    else if (base == EPWM7)
    {
        GPIO_setPinConfig(GPIO_12_EPWM7_A);
        GPIO_setPadConfig(12U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(12U, kGPIO_QUAL_ASYNC);
        GPIO_setPinConfig(GPIO_13_EPWM7_B);
        GPIO_setPadConfig(13U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(13U, kGPIO_QUAL_ASYNC);
    }
    else if (base == EPWM8)
    {
        GPIO_setPinConfig(GPIO_14_EPWM8_A);
        GPIO_setPadConfig(14U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(14U, kGPIO_QUAL_ASYNC);
        GPIO_setPinConfig(GPIO_15_EPWM8_B);
        GPIO_setPadConfig(15U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(15U, kGPIO_QUAL_ASYNC);
    }
    else if (base == EPWM9)
    {
        GPIO_setPinConfig(GPIO_16_EPWM9_A);
        GPIO_setPadConfig(16U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(16U, kGPIO_QUAL_ASYNC);
        GPIO_setPinConfig(GPIO_17_EPWM9_B);
        GPIO_setPadConfig(17U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(17U, kGPIO_QUAL_ASYNC);
    }
    else if (base == EPWM10)
    {
        GPIO_setPinConfig(GPIO_18_EPWM10_A);
        GPIO_setPadConfig(18U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(18U, kGPIO_QUAL_ASYNC);
        GPIO_setPinConfig(GPIO_19_EPWM10_B);
        GPIO_setPadConfig(19U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(19U, kGPIO_QUAL_ASYNC);
    }
    else if (base == EPWM11)
    {
        GPIO_setPinConfig(GPIO_20_EPWM11_A);
        GPIO_setPadConfig(20U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(20U, kGPIO_QUAL_ASYNC);
        GPIO_setPinConfig(GPIO_21_EPWM11_B);
        GPIO_setPadConfig(21U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(21U, kGPIO_QUAL_ASYNC);
    }
    else if (base == EPWM12)
    {
        GPIO_setPinConfig(GPIO_22_EPWM12_A);
        GPIO_setPadConfig(22U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(22U, kGPIO_QUAL_ASYNC);
        GPIO_setPinConfig(GPIO_23_EPWM12_B);
        GPIO_setPadConfig(23U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(23U, kGPIO_QUAL_ASYNC);
    }
}

void BOARD_ecapPinConfig(ECAP_Type *base)
{
    GPIO_setPinConfig(GPIO_44_GPIO44);
    GPIO_setPadConfig(44U, kGPIO_PADCONFIG_STD);
    GPIO_setQualificationMode(44U, kGPIO_QUAL_ASYNC);
    XBAR_setInputPin(INPUT_XBAR, INPUT_XBAR_ECAPx, 44U);

    GPIO_setPinConfig(GPIO_45_GPIO45);
    GPIO_setPadConfig(45U, kGPIO_PADCONFIG_STD);
    GPIO_setQualificationMode(45U, kGPIO_QUAL_ASYNC);
    XBAR_setInputPin(INPUT_XBAR, INPUT_XBAR_ECAPy, 45U);

    if (base == ECAP1)
    {
        GPIO_setPinConfig(GPIO_2_OUTPUTXBAR1);
        GPIO_setPadConfig(2U, kGPIO_PADCONFIG_STD);
        XBAR_setOutputLatchMode(OUTPUT_XBAR, OUTPUT_XBAR_ECAP1, false);
        XBAR_invertOutputSignal(OUTPUT_XBAR, OUTPUT_XBAR_ECAP1, false);
        XBAR_setOutputMuxConfig(OUTPUT_XBAR, OUTPUT_XBAR_ECAP1, XBAR_EPWM_MUX00_ECAP1_OUT);
        XBAR_enableOutputMux(OUTPUT_XBAR, OUTPUT_XBAR_ECAP1, kXBAR_MUX00);
    }
    else if (base == ECAP2)
    {
        GPIO_setPinConfig(GPIO_3_OUTPUTXBAR2);
        GPIO_setPadConfig(3U, kGPIO_PADCONFIG_STD);
        XBAR_setOutputLatchMode(OUTPUT_XBAR, OUTPUT_XBAR_ECAP2, false);
        XBAR_invertOutputSignal(OUTPUT_XBAR, OUTPUT_XBAR_ECAP2, false);
        XBAR_setOutputMuxConfig(OUTPUT_XBAR, OUTPUT_XBAR_ECAP2, XBAR_EPWM_MUX02_ECAP2_OUT);
        XBAR_enableOutputMux(OUTPUT_XBAR, OUTPUT_XBAR_ECAP2, kXBAR_MUX02);
    }
    else if (base == ECAP3)
    {
        GPIO_setPinConfig(GPIO_4_OUTPUTXBAR3);
        GPIO_setPadConfig(4U, kGPIO_PADCONFIG_STD);
        XBAR_setOutputLatchMode(OUTPUT_XBAR, OUTPUT_XBAR_ECAP3, false);
        XBAR_invertOutputSignal(OUTPUT_XBAR, OUTPUT_XBAR_ECAP3, false);
        XBAR_setOutputMuxConfig(OUTPUT_XBAR, OUTPUT_XBAR_ECAP3, XBAR_EPWM_MUX04_ECAP3_OUT);
        XBAR_enableOutputMux(OUTPUT_XBAR, OUTPUT_XBAR_ECAP3, kXBAR_MUX04);
    }
    else if (base == ECAP4)
    {
        GPIO_setPinConfig(GPIO_27_OUTPUTXBAR4);
        GPIO_setPadConfig(27U, kGPIO_PADCONFIG_STD);
        XBAR_setOutputLatchMode(OUTPUT_XBAR, OUTPUT_XBAR_ECAP4, false);
        XBAR_invertOutputSignal(OUTPUT_XBAR, OUTPUT_XBAR_ECAP4, false);
        XBAR_setOutputMuxConfig(OUTPUT_XBAR, OUTPUT_XBAR_ECAP4, XBAR_EPWM_MUX06_ECAP4_OUT);
        XBAR_enableOutputMux(OUTPUT_XBAR, OUTPUT_XBAR_ECAP4, kXBAR_MUX06);
    }
    else if (base == ECAP5)
    {
        GPIO_setPinConfig(GPIO_28_OUTPUTXBAR5);
        GPIO_setPadConfig(28U, kGPIO_PADCONFIG_STD);
        XBAR_setOutputLatchMode(OUTPUT_XBAR, OUTPUT_XBAR_ECAP5, false);
        XBAR_invertOutputSignal(OUTPUT_XBAR, OUTPUT_XBAR_ECAP5, false);
        XBAR_setOutputMuxConfig(OUTPUT_XBAR, OUTPUT_XBAR_ECAP5, XBAR_EPWM_MUX08_ECAP5_OUT);
        XBAR_enableOutputMux(OUTPUT_XBAR, OUTPUT_XBAR_ECAP5, kXBAR_MUX08);
    }
    else if (base == ECAP6)
    {
        GPIO_setPinConfig(GPIO_29_OUTPUTXBAR6);
        GPIO_setPadConfig(29U, kGPIO_PADCONFIG_STD);
        XBAR_setOutputLatchMode(OUTPUT_XBAR, OUTPUT_XBAR_ECAP6, false);
        XBAR_invertOutputSignal(OUTPUT_XBAR, OUTPUT_XBAR_ECAP6, false);
        XBAR_setOutputMuxConfig(OUTPUT_XBAR, OUTPUT_XBAR_ECAP6, XBAR_EPWM_MUX10_ECAP6_OUT);
        XBAR_enableOutputMux(OUTPUT_XBAR, OUTPUT_XBAR_ECAP6, kXBAR_MUX10);
    }
}

void BOARD_eqepPinConfig(EQEP_REGS_Type *base)
{
    if (base == EQEP1)
    {
        GPIO_setPinConfig(GPIO_20_EQEP1_A);
        GPIO_setPadConfig(20U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(20U, kGPIO_QUAL_SYNC);
        GPIO_setPinConfig(GPIO_21_EQEP1_B);
        GPIO_setPadConfig(21U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(21U, kGPIO_QUAL_SYNC);
        GPIO_setPinConfig(GPIO_22_EQEP1_STROBE);
        GPIO_setPadConfig(22U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(22U, kGPIO_QUAL_SYNC);
        GPIO_setPinConfig(GPIO_23_EQEP1_INDEX);
        GPIO_setPadConfig(23U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(23U, kGPIO_QUAL_SYNC);
    }
    else if (base == EQEP2)
    {
        GPIO_setPinConfig(GPIO_24_EQEP2_A);
        GPIO_setPadConfig(24U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(24U, kGPIO_QUAL_SYNC);
        GPIO_setPinConfig(GPIO_25_EQEP2_B);
        GPIO_setPadConfig(25U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(25U, kGPIO_QUAL_SYNC);
        GPIO_setPinConfig(GPIO_27_EQEP2_STROBE);
        GPIO_setPadConfig(27U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(27U, kGPIO_QUAL_SYNC);
        GPIO_setPinConfig(GPIO_26_EQEP2_INDEX);
        GPIO_setPadConfig(26U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(26U, kGPIO_QUAL_SYNC);
    }
    else if (base == EQEP3)
    {
        GPIO_setPinConfig(GPIO_28_EQEP3_A);
        GPIO_setPadConfig(28U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(28U, kGPIO_QUAL_SYNC);
        GPIO_setPinConfig(GPIO_29_EQEP3_B);
        GPIO_setPadConfig(29U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(29U, kGPIO_QUAL_SYNC);
        GPIO_setPinConfig(GPIO_30_EQEP3_STROBE);
        GPIO_setPadConfig(30U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(30U, kGPIO_QUAL_SYNC);
        GPIO_setPinConfig(GPIO_31_EQEP3_INDEX);
        GPIO_setPadConfig(31U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(31U, kGPIO_QUAL_SYNC);
    }
}

void BOARD_sdramPinConfig(EMIF_Type *base)
{
    if (base == EMIF1)
    {
        GPIO_setPinConfig(GPIO_69_EMIF1_D15);
        GPIO_setPadConfig(69U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_70_EMIF1_D14);
        GPIO_setPadConfig(70U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_71_EMIF1_D13);
        GPIO_setPadConfig(71U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_72_EMIF1_D12);
        GPIO_setPadConfig(72U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_73_EMIF1_D11);
        GPIO_setPadConfig(73U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_74_EMIF1_D10);
        GPIO_setPadConfig(74U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_75_EMIF1_D9);
        GPIO_setPadConfig(75U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_76_EMIF1_D8);
        GPIO_setPadConfig(76U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_77_EMIF1_D7);
        GPIO_setPadConfig(77U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_78_EMIF1_D6);
        GPIO_setPadConfig(78U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_79_EMIF1_D5);
        GPIO_setPadConfig(79U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_80_EMIF1_D4);
        GPIO_setPadConfig(80U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_81_EMIF1_D3);
        GPIO_setPadConfig(81U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_82_EMIF1_D2);
        GPIO_setPadConfig(82U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_83_EMIF1_D1);
        GPIO_setPadConfig(83U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_85_EMIF1_D0);
        GPIO_setPadConfig(85U, kGPIO_PADCONFIG_STD);

        GPIO_setPinConfig(GPIO_38_EMIF1_A0);
        GPIO_setPadConfig(38U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_39_EMIF1_A1);
        GPIO_setPadConfig(39U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_40_EMIF1_A2);
        GPIO_setPadConfig(40U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_41_EMIF1_A3);
        GPIO_setPadConfig(41U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_44_EMIF1_A4);
        GPIO_setPadConfig(44U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_45_EMIF1_A5);
        GPIO_setPadConfig(45U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_46_EMIF1_A6);
        GPIO_setPadConfig(46U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_47_EMIF1_A7);
        GPIO_setPadConfig(47U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_48_EMIF1_A8);
        GPIO_setPadConfig(48U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_49_EMIF1_A9);
        GPIO_setPadConfig(49U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_50_EMIF1_A10);
        GPIO_setPadConfig(50U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_51_EMIF1_A11);
        GPIO_setPadConfig(51U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_52_EMIF1_A12);
        GPIO_setPadConfig(52U, kGPIO_PADCONFIG_STD);

        GPIO_setPinConfig(GPIO_29_EMIF1_SDCKE);
        GPIO_setPadConfig(29U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_30_EMIF1_CLK);
        GPIO_setPadConfig(30U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_31_EMIF1_WEN);
        GPIO_setPadConfig(31U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_32_EMIF1_CS0N);
        GPIO_setPadConfig(32U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_86_EMIF1_CAS);
        GPIO_setPadConfig(86U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_87_EMIF1_RAS);
        GPIO_setPadConfig(87U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_88_EMIF1_DQM0);
        GPIO_setPadConfig(88U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_89_EMIF1_DQM1);
        GPIO_setPadConfig(89U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_92_EMIF1_BA1);
        GPIO_setPadConfig(92U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_93_EMIF1_BA0);
        GPIO_setPadConfig(93U, kGPIO_PADCONFIG_STD);
    }
}

void BOARD_sramPinConfig(EMIF_Type *base)
{
    if (base == EMIF1)
    {
        GPIO_setPinConfig(GPIO_69_EMIF1_D15);
        GPIO_setPadConfig(69U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_70_EMIF1_D14);
        GPIO_setPadConfig(70U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_71_EMIF1_D13);
        GPIO_setPadConfig(71U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_72_EMIF1_D12);
        GPIO_setPadConfig(72U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_73_EMIF1_D11);
        GPIO_setPadConfig(73U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_74_EMIF1_D10);
        GPIO_setPadConfig(74U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_75_EMIF1_D9);
        GPIO_setPadConfig(75U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_76_EMIF1_D8);
        GPIO_setPadConfig(76U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_77_EMIF1_D7);
        GPIO_setPadConfig(77U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_78_EMIF1_D6);
        GPIO_setPadConfig(78U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_79_EMIF1_D5);
        GPIO_setPadConfig(79U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_80_EMIF1_D4);
        GPIO_setPadConfig(80U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_81_EMIF1_D3);
        GPIO_setPadConfig(81U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_82_EMIF1_D2);
        GPIO_setPadConfig(82U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_83_EMIF1_D1);
        GPIO_setPadConfig(83U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_85_EMIF1_D0);
        GPIO_setPadConfig(85U, kGPIO_PADCONFIG_STD);

        GPIO_setPinConfig(GPIO_38_EMIF1_A0);
        GPIO_setPadConfig(38U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_39_EMIF1_A1);
        GPIO_setPadConfig(39U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_40_EMIF1_A2);
        GPIO_setPadConfig(40U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_41_EMIF1_A3);
        GPIO_setPadConfig(41U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_44_EMIF1_A4);
        GPIO_setPadConfig(44U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_45_EMIF1_A5);
        GPIO_setPadConfig(45U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_46_EMIF1_A6);
        GPIO_setPadConfig(46U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_47_EMIF1_A7);
        GPIO_setPadConfig(47U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_48_EMIF1_A8);
        GPIO_setPadConfig(48U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_49_EMIF1_A9);
        GPIO_setPadConfig(49U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_50_EMIF1_A10);
        GPIO_setPadConfig(50U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_51_EMIF1_A11);
        GPIO_setPadConfig(51U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_52_EMIF1_A12);
        GPIO_setPadConfig(52U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_86_EMIF1_A13);
        GPIO_setPadConfig(86U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_87_EMIF1_A14);
        GPIO_setPadConfig(87U, kGPIO_PADCONFIG_STD);

        GPIO_setPinConfig(GPIO_31_EMIF1_WEN);
        GPIO_setPadConfig(31U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_34_EMIF1_CS2N);
        GPIO_setPadConfig(34U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_37_EMIF1_OEN);
        GPIO_setPadConfig(37U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_88_EMIF1_DQM0);
        GPIO_setPadConfig(88U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_89_EMIF1_DQM1);
        GPIO_setPadConfig(89U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_92_EMIF1_BA1);
        GPIO_setPadConfig(92U, kGPIO_PADCONFIG_STD);
    }
}

void BOARD_sdfmPinConfig(SDFM_REGS_Type *base)
{
    if (base == SDFM1)
    {
        GPIO_setPinConfig(GPIO_48_SD1_D1);
        GPIO_setPadConfig(48U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(48U, kGPIO_QUAL_ASYNC);
        GPIO_setPinConfig(GPIO_49_SD1_C1);
        GPIO_setPadConfig(49U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(49U, kGPIO_QUAL_ASYNC);
    }
    else if (base == SDFM2)
    {
        GPIO_setPinConfig(GPIO_56_SD2_D1);
        GPIO_setPadConfig(56U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(56U, kGPIO_QUAL_ASYNC);
        GPIO_setPinConfig(GPIO_57_SD2_C1);
        GPIO_setPadConfig(57U, kGPIO_PADCONFIG_STD);
        GPIO_setQualificationMode(57U, kGPIO_QUAL_ASYNC);
    }
}

void BOARD_usbPinConfig(USB_Type *base)
{
    if (base == USBA)
    {
        GPIO_setPinConfig(GPIO_43_USBA_DP);
        GPIO_setPadConfig(43U, kGPIO_PADCONFIG_STD);
        GPIO_setPinConfig(GPIO_42_USBA_DM);
        GPIO_setPadConfig(42U, kGPIO_PADCONFIG_STD);
    }
}

void BOARD_xclkoutPinConfig(void)
{
    GPIO_setPinConfig(GPIO_73_XCLKOUT);
    GPIO_setPadConfig(73U, kGPIO_PADCONFIG_STD);
}
