/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file clock_config.c
 * \brief HS32F7D377 EVB clock configuration source file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "board.h"
#include "clock_config.h"
#include "hte_debug_console.h"
#include "hte_sysctrl.h"
#include "pin_config.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! \brief Tag to indicate if the clock infomation is valid or not */
#define CLOCK_INFO_TAG (0x5a5aa5a5U)

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/* No Prototypes */

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! \brief the clock information location which is defined in the linker configuration file */
#if defined(__CC_ARM) || defined(__ARMCC_VERSION)
extern uint32_t Image$$CLOCK_INFO$$Base[];
#define CLOCK_INFO_ADDR Image$$CLOCK_INFO$$Base
#elif defined(__ICCARM__)
extern uint32_t __CLOCK_INFO__[];
#define CLOCK_INFO_ADDR __CLOCK_INFO__
#elif defined(__GNUC__)
extern uint32_t __clock_info[];
#define CLOCK_INFO_ADDR __clock_info
#else
#error Unknown toolchain
#endif

/*! \brief clock globe config struct */
SYSTEM_Clock_t g_clockConfig;
/*! \brief global tick var */
volatile uint32_t gSystick = 0;
/*! \brief 1KHz tick freq */
SYSTICK_Freq_t gSystickFreq = kHAL_TICK_FREQ_1KHZ;

/*******************************************************************************
 * Codes
 ******************************************************************************/
/*!
 * \brief sysctick int function
 *
 * \details This function is systick int function
 *
 */
void SysTick_DriverHandler(void)
{
    gSystick += (uint32_t)gSystickFreq;

    ISR_EXIT_BARRIER();
}

__WEAK status_t BOARD_initTick(void)
{
    /* Check uwTickFreq for MisraC 2012 (even if uwTickFreq is a enum type that don't take the value zero)*/
    if ((uint32_t)gSystickFreq == 0UL)
    {
        return kSTATUS_FAIL;
    }

    /* Configure the SysTick to have interrupt in 1ms time basis*/
    if (SysTick_Config(g_clockConfig.sysClk / (1000UL / (uint32_t)gSystickFreq)) > 0U)
    {
        return kSTATUS_FAIL;
    }

    /* Configure the SysTick IRQ priority */

    NVIC_SetPriority(SysTick_IRQn, TICK_INT_PRIORITY);

    /* Return function status */
    return kSTATUS_SUCCESS;
}

__WEAK uint32_t BOARD_getTick(void)
{
    return gSystick;
}

status_t BOARD_setSystickFreq(SYSTICK_Freq_t freq)
{
    status_t       status = kSTATUS_SUCCESS;
    SYSTICK_Freq_t prevTickFreq;

    assert(IS_TICKFREQ(freq));

    if (gSystickFreq != freq)
    {
        /* Back up uwTickFreq frequency */
        prevTickFreq = gSystickFreq;

        /* Update uwTickFreq global variable used by HAL_InitTick() */
        gSystickFreq = freq;

        /* Apply the new tick Freq  */
        status = BOARD_initTick();
        if (status != kSTATUS_SUCCESS)
        {
            /* Restore previous tick frequency */
            gSystickFreq = prevTickFreq;
        }
    }

    return status;
}

SYSTICK_Freq_t BOARD_getSystickFreq(void)
{
    return gSystickFreq;
}

void BOARD_clockInfStore(void)
{
    uint32_t  size = sizeof(g_clockConfig);
    uint32_t *src  = (uint32_t *)&g_clockConfig;
    uint32_t *dst  = CLOCK_INFO_ADDR;

    memcpy(dst, src, size);
}

void BOARD_clockInfGet(void)
{
    uint32_t  size = sizeof(g_clockConfig);
    uint32_t *src  = CLOCK_INFO_ADDR;
    uint32_t *dst  = (uint32_t *)&g_clockConfig;

    memcpy(dst, src, size);
}


void BOARD_clockConfig(void)
{
#if defined(BOARD_USE_CPU1) && BOARD_USE_CPU1
#if defined(TEST_CLK) && TEST_CLK
    SYSCTRL_setXclkOutDiv(kSYSC_XCLKOUT_DIV4);
    SYSCTRL_selectClockOutSource(kSYSC_XCLKOUT_PLLRAWSCLK);
    BOARD_xclkoutPinConfig();
#endif
    //old config
    SYSCTL_SysClk_Config_t clkCfg = { kSYSC_OSCSRC_XTAL, OSC_XTALIN, PLL_ENABLE, SRC_CLKDIV, PLL_CLKOUT, SYS_CLKDIV };
    //new config
    //SYSCTL_SysClk_Config_t clkCfg = { kSYSC_OSCSRC_INTOSC2, OSC_OSC2IN, PLL_ENABLE, SRC_CLKDIV, PLL_CLKOUT, SYS_CLKDIV };

    SYSCTL_AuxClk_Config_t auxCfg = {    kSYSC_AUXSRC_XTAL, OSC_AUXCLKIN, PLL_ENABLE, SRC_CLKDIV, AUXPLL_CLKOUT, AUX_CLKDIV};
    //SYSCTL_AuxClk_Config_t auxCfg = {    kSYSC_AUXSRC_INTOSC2, OSC_AUXCLKIN, PLL_ENABLE, SRC_CLKDIV, AUXPLL_CLKOUT, AUX_CLKDIV};

    g_clockConfig.xtalClkIn = OSC_XTALIN;
    //g_clockConfig.xtalClkIn = OSC_OSC2IN;    //OSC_XTALIN;
    g_clockConfig.auxClkIn  = OSC_AUXCLKIN;
    /* Disable the PLL before configure it */
    SYSCTRL_setPLLClkEn(kSYSC_DISABLE);
    /* Configure SysPLL */
    SYSCTRL_setClock(clkCfg);
    /* Configure AuxPLL*/
    SYSCTRL_setAuxClock(auxCfg);
    /* Store all clock information into a variable */
    g_clockConfig.sysClk    = SYSCTRL_getClock(g_clockConfig.xtalClkIn);
    g_clockConfig.auxPllRawClk = AUXPLL_CLKOUT;
    g_clockConfig.auxPllClk = SYSCTRL_getAuxClock(g_clockConfig.auxClkIn);
    g_clockConfig.sysPclk   = g_clockConfig.sysClk / 2;
    g_clockConfig.periphClk = g_clockConfig.sysClk / 2;
    g_clockConfig.tag          = CLOCK_INFO_TAG;
    /* Update SystemCoreClock */
    SystemCoreClock = g_clockConfig.sysClk;
#else
    /*
     * CPU2 cannot neither configure clock, nor read the clock configurations.
     * Get the clock configurations from MSGRAM, which are stored by CPU1
     */
    BOARD_clockInfGet();
    if (g_clockConfig.tag != CLOCK_INFO_TAG)
    {
        while (1)
        {
            ;
        }
    }
    SystemCoreClock = g_clockConfig.sysClk;
#endif /* BOARD_USE_CPU1 */
}

void BOARD_clockConfigForCPU2(void)
{
    /* Init MSGRAM */
    SYSCTRL_initMsgram();
    while (SYSCTRL_getMsgramInitDone() == false)
        ;

    /* Send clock information to CPU2 via MSGRAM */
    BOARD_clockInfStore();
}

void BOARD_uartClockEnable(UART_Type *base)
{
    SYSCTRL_PeripheralPclockCr_t peri;

    if (base == UARTA)
    {
        peri = kSYSCTL_PERIPH_CLK_UARTA;
    }
    else if (base == UARTB)
    {
        peri = kSYSCTL_PERIPH_CLK_UARTB;
    }
    else if (base == UARTC)
    {
        peri = kSYSCTL_PERIPH_CLK_UARTC;
    }
    else if (base == UARTD)
    {
        peri = kSYSCTL_PERIPH_CLK_UARTD;
    }
    else
    {
        return;
    }

    SYSCTRL_enablePeripheral(peri);
}

void BOARD_i2cClockEnable(I2C_Type *base)
{
    SYSCTRL_PeripheralPclockCr_t peri;

    if (base == I2CA)
    {
        peri = kSYSCTL_PERIPH_CLK_I2CA;
    }
    else if (base == I2CB)
    {
        peri = kSYSCTL_PERIPH_CLK_I2CB;
    }
    else
    {
        return;
    }

    SYSCTRL_enablePeripheral(peri);
}

void BOARD_pmbusClockEnable(PMBUS_Type *base)
{
    SYSCTRL_PeripheralPclockCr_t peri;

    if (base == PMBUSA)
    {
        peri = kSYSCTL_PERIPH_CLK_PMBUSA;
    }
    else
    {
        return;
    }

    SYSCTRL_enablePeripheral(peri);
}

void BOARD_spiClockEnable(SPI_Type *base)
{
    SYSCTRL_PeripheralPclockCr_t peri;

    if (base == SPIA)
    {
        peri = kSYSCTL_PERIPH_CLK_SPIA;
    }
    else if (base == SPIB)
    {
        peri = kSYSCTL_PERIPH_CLK_SPIB;
    }
    else if (base == SPIC)
    {
        peri = kSYSCTL_PERIPH_CLK_SPIC;
    }
    else
    {
        return;
    }

    SYSCTRL_enablePeripheral(peri);
}

void BOARD_mcanClockEnable(MCAN_Type *base)
{
    SYSCTRL_PeripheralPclockCr_t peri;

    if (base == MCANA)
    {
        peri = kSYSCTL_PERIPH_CLK_MCANA;
    }
    else if (base == MCANB)
    {
        peri = kSYSCTL_PERIPH_CLK_MCANB;
    }
    else if (base == MCANC)
    {
        peri = kSYSCTL_PERIPH_CLK_MCANC;
    }
    else
    {
        return;
    }

    SYSCTRL_enablePeripheral(peri);
}

void BOARD_epwmClockEnable(EPWM_REGS_Type *base)
{
    SYSCTRL_PeripheralPclockCr_t peri;

    if (base == EPWM1)
    {
        peri = kSYSCTL_PERIPH_CLK_EPWM1;
    }
    else if (base == EPWM2)
    {
        peri = kSYSCTL_PERIPH_CLK_EPWM2;
    }
    else if (base == EPWM3)
    {
        peri = kSYSCTL_PERIPH_CLK_EPWM3;
    }
    else if (base == EPWM4)
    {
        peri = kSYSCTL_PERIPH_CLK_EPWM4;
    }
    else if (base == EPWM5)
    {
        peri = kSYSCTL_PERIPH_CLK_EPWM5;
    }
    else if (base == EPWM6)
    {
        peri = kSYSCTL_PERIPH_CLK_EPWM6;
    }
    else if (base == EPWM7)
    {
        peri = kSYSCTL_PERIPH_CLK_EPWM7;
    }
    else if (base == EPWM8)
    {
        peri = kSYSCTL_PERIPH_CLK_EPWM8;
    }
    else if (base == EPWM9)
    {
        peri = kSYSCTL_PERIPH_CLK_EPWM9;
    }
    else if (base == EPWM10)
    {
        peri = kSYSCTL_PERIPH_CLK_EPWM10;
    }
    else if (base == EPWM11)
    {
        peri = kSYSCTL_PERIPH_CLK_EPWM11;
    }
    else if (base == EPWM12)
    {
        peri = kSYSCTL_PERIPH_CLK_EPWM12;
    }
    else
    {
        return;
    }
    SYSCTRL_enablePeripheral(peri);
}

void BOARD_ecapClockEnable(ECAP_Type *base)
{
    SYSCTRL_PeripheralPclockCr_t peri;

    if (base == ECAP1)
    {
        peri = kSYSCTL_PERIPH_CLK_ECAP1;
    }
    else if (base == ECAP2)
    {
        peri = kSYSCTL_PERIPH_CLK_ECAP2;
    }
    else if (base == ECAP3)
    {
        peri = kSYSCTL_PERIPH_CLK_ECAP3;
    }
    else if (base == ECAP4)
    {
        peri = kSYSCTL_PERIPH_CLK_ECAP4;
    }
    else if (base == ECAP5)
    {
        peri = kSYSCTL_PERIPH_CLK_ECAP5;
    }
    else if (base == ECAP6)
    {
        peri = kSYSCTL_PERIPH_CLK_ECAP6;
    }
    else
    {
        return;
    }

    SYSCTRL_enablePeripheral(peri);
}

void BOARD_eqepClockEnable(EQEP_REGS_Type *base)
{
    SYSCTRL_PeripheralPclockCr_t peri;

    if (base == EQEP1)
    {
        peri = kSYSCTL_PERIPH_CLK_EQEP1;
    }
    else if (base == EQEP2)
    {
        peri = kSYSCTL_PERIPH_CLK_EQEP2;
    }
    else if (base == EQEP3)
    {
        peri = kSYSCTL_PERIPH_CLK_EQEP3;
    }
    else
    {
        return;
    }

    SYSCTRL_enablePeripheral(peri);
}

void BOARD_emifClockEnable(EMIF_Type *base)
{
    SYSCTRL_PeripheralPclockCr_t peri;

    if (base == EMIF1)
    {
        peri = kSYSCTL_PERIPH_CLK_EMIF1;
    }
    else
    {
        return;
    }

    SYSCTRL_enablePeripheral(peri);
}

void BOARD_sdfmClockEnable(SDFM_REGS_Type *base)
{
    SYSCTRL_PeripheralPclockCr_t peri;

    if (base == SDFM1)
    {
        peri = kSYSCTL_PERIPH_CLK_SDFM1;
    }
    else if (base == SDFM2)
    {
        peri = kSYSCTL_PERIPH_CLK_SDFM2;
    }
    else
    {
        return;
    }

    SYSCTRL_enablePeripheral(peri);
}

void BOARD_usbClockEnable(USB_Type *base)
{
    SYSCTRL_PeripheralPclockCr_t peri;

    if (base == USBA)
    {
        peri = kSYSCTL_PERIPH_CLK_USBA;
    }
    else
    {
        return;
    }

    SYSCTRL_enablePeripheral(peri);
}

void BOARD_adcClockEnable(ADC_Type *base)
{
    SYSCTRL_PeripheralPclockCr_t peri;

    if (base == ADCA)
    {
        peri = kSYSCTL_PERIPH_CLK_ADCA;
    }
    else if (base == ADCB)
    {
        peri = kSYSCTL_PERIPH_CLK_ADCB;
    }
    else if (base == ADCC)
    {
        peri = kSYSCTL_PERIPH_CLK_ADCC;
    }
    else if (base == ADCD)
    {
        peri = kSYSCTL_PERIPH_CLK_ADCD;
    }
    else
    {
        return;
    }

    SYSCTRL_enablePeripheral(peri);
}

void BOARD_dacClockEnable(DAC_REGS_Type *base)
{
    SYSCTRL_PeripheralPclockCr_t peri;

    if (base == DACA)
    {
        peri = kSYSCTL_PERIPH_CLK_DACA;
    }
    else if (base == DACB)
    {
        peri = kSYSCTL_PERIPH_CLK_DACB;
    }
    else if (base == DACC)
    {
        peri = kSYSCTL_PERIPH_CLK_DACC;
    }
    else
    {
        return;
    }

    SYSCTRL_enablePeripheral(peri);
}

void BOARD_dmaClockEnable(DMA_Type *base)
{
    SYSCTRL_PeripheralPclockCr_t peri;

    if (base == DMA)
    {
        peri = kSYSCTL_PERIPH_CLK_DMA;
    }
    else
    {
        return;
    }

    SYSCTRL_enablePeripheral(peri);
}

void BOARD_cputimerClockEnable(CPUTIMER_REGS_Type *base)
{
    SYSCTRL_PeripheralPclockCr_t peri;

    if (base == CPUTIMER_REGS0)
    {
        peri = kSYSCTL_PERIPH_CLK_CPUTIMER0;
    }
    else if (base == CPUTIMER_REGS1)
    {
        peri = kSYSCTL_PERIPH_CLK_CPUTIMER1;
    }
    else if (base == CPUTIMER_REGS2)
    {
        peri = kSYSCTL_PERIPH_CLK_CPUTIMER2;
    }
    else
    {
        return;
    }

    SYSCTRL_enablePeripheral(peri);
}

void BOARD_stimerClockEnable(STIMER_Type *base, uint32_t channel)
{
    SYSCTRL_PeripheralPclockCr_t peri;

    if (base == STIMER)
    {
        if (channel == 0U)
        {
            peri = kSYSCTL_PERIPH_CLK_DWTIMER_CH0;
        }
        else if (channel == 1U)
        {
            peri = kSYSCTL_PERIPH_CLK_DWTIMER_CH1;
        }
        else if (channel == 2U)
        {
            peri = kSYSCTL_PERIPH_CLK_DWTIMER_CH2;
        }
        else
        {
            return;
        }
    }
    else
    {
        return;
    }

    SYSCTRL_enablePeripheral(peri);
}

void BOARD_cmpssClockEnable(CMPSS_Type *base)
{
    SYSCTRL_PeripheralPclockCr_t peri;

    if (base == CMPSS1)
    {
        peri = kSYSCTL_PERIPH_CLK_CMPSS1;
    }
    else if (base == CMPSS2)
    {
        peri = kSYSCTL_PERIPH_CLK_CMPSS2;
    }
    else if (base == CMPSS3)
    {
        peri = kSYSCTL_PERIPH_CLK_CMPSS3;
    }
    else if (base == CMPSS4)
    {
        peri = kSYSCTL_PERIPH_CLK_CMPSS4;
    }
    else if (base == CMPSS5)
    {
        peri = kSYSCTL_PERIPH_CLK_CMPSS5;
    }
    else if (base == CMPSS6)
    {
        peri = kSYSCTL_PERIPH_CLK_CMPSS6;
    }
    else if (base == CMPSS7)
    {
        peri = kSYSCTL_PERIPH_CLK_CMPSS7;
    }
    else if (base == CMPSS8)
    {
        peri = kSYSCTL_PERIPH_CLK_CMPSS8;
    }
    else
    {
        return;
    }

    SYSCTRL_enablePeripheral(peri);
}

void BOARD_clbClockEnable(CLB_TILE_Type *base)
{
    SYSCTRL_PeripheralPclockCr_t peri;

    if (base == CLB_TILE1)
    {
        peri = kSYSCTL_PERIPH_CLK_CLB1;
    }
    else if (base == CLB_TILE2)
    {
        peri = kSYSCTL_PERIPH_CLK_CLB2;
    }
    else if (base == CLB_TILE3)
    {
        peri = kSYSCTL_PERIPH_CLK_CLB3;
    }
    else if (base == CLB_TILE4)
    {
        peri = kSYSCTL_PERIPH_CLK_CLB4;
    }
    else
    {
        return;
    }

    SYSCTRL_enablePeripheral(peri);
}
