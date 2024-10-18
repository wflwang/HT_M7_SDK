/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_sysctrl.c
 * \brief HS32F7D377 SYSCTRL driver source file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_sysctrl.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define XTAL_CPUTIMER_PERIOD 1023U /*!< Define cputimer period */
#define CLK_DOT_FCW_LEN      15U   /*!< Define FCW len */
#define CLK_DOT_FCW_POINT    kSYSC_DEC_POINT8 /*!< Define FCW point */

#define MAX_PLL_CLK      550000000U /*!< Max pll clk */
#define MIN_PLL_CLK      160000000U /*!< Min pll clk */
#define HIGH_FQ_BANK_CLK 300000000U /*!< high freq bank clk */


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
// #if defined(HTE_DEVICE_HS32F7D377_CPU1)
uint32_t SYSCTRL_getClock(uint32_t clockInHz)
{
    float               tempClk, fcwSscVal;
    SYSCTRL_OscSrcSel_t oscSource;
    uint32_t            clockOut;

    uint32_t decPoint, decNum, fcwTmp, intSsc, decSsc;

    /* Don't proceed if an MCD failure is detected.*/
    if (SYSCTRL_isMCDClockFailureDetected())
    {
        /* OSCCLKSRC2 failure detected. Returning the INTOSC1 rate. You need
           to handle the MCD and clear the failure.*/
        clockOut = SYSCTL_DEFAULT_OSC_FREQ;
    }
    else
    {
        /* If one of the internal oscillators is being used, start from the
          known default frequency.  Otherwise, use clockInHz parameter.*/
        oscSource = SYSCTRL_getOscClkSrc();
        if ((oscSource == kSYSC_OSCSRC_INTOSC2) || (oscSource == kSYSC_OSCSRC_INTOSC1))
        {
            clockOut = SYSCTL_DEFAULT_OSC_FREQ;
        }
        else
        {
            clockOut = clockInHz;
        }
        /* If the PLL is enabled calculate its effect on the clock */
        if (SYSCTRL_getPLLEn() && SYSCTRL_getPLLClkEn())
        {
            /* Calculate portion from fractional multiplier */
            if (SYSCTRL_getPLLCkRefSel())
            {
                tempClk = (float)clockOut / (float)(SYSCTRL_getPLLClkRefDiv() + 2);
            }
            else
            {
                tempClk = (float)clockOut;
            }

            /* PLL = OSC*(fcwssc +2)/2       PLL = OSC + OSC*fcwssc/2 */
            decPoint = SYSCTRL_getPLLFcwSscDecPoint();
            decNum   = CLK_DOT_FCW_LEN - decPoint;
            fcwTmp = SYSCTRL_getPLLFcwSsc();

            intSsc = fcwTmp >> decNum;
            decSsc = fcwTmp % (0x1U << decNum);
            if (SYSCTRL_getPLLPi())
            {
                fcwSscVal = (float)intSsc;
            }
            else
            {
                fcwSscVal = (float)intSsc + (float)decSsc / (float)(0x1U << decNum);
            }
            clockOut  = (uint32_t)(tempClk + (tempClk * fcwSscVal / 2));
        }
        if (SYSCTRL_getSysClkDivSel())
        {
            clockOut = clockOut / (SYSCTRL_getSysClkDivSel() * 2);
        }
    }

    return clockOut;
}

uint32_t SYSCTRL_getAuxClock(uint32_t clockInHz)
{
    float               tempClk, fcwSscVal;
    SYSCTRL_AuxSrcSel_t oscSource;
    uint32_t            clockOut;

    uint32_t decPoint, decNum, fcwTmp, intSsc, decSsc;


    oscSource = SYSCTRL_gelAuxClkSrc();
    if (oscSource == kSYSC_AUXSRC_INTOSC2)
    {
        clockOut = SYSCTL_DEFAULT_OSC_FREQ;
    }
    else
    {
        clockOut = clockInHz;
    }
    /* If the PLL is enabled calculate its effect on the clock */
    if (SYSCTRL_getAuxPLLEn() && SYSCTRL_getAuxPLLClkEn())
    {
        /* Calculate portion from fractional multiplier */
        if (SYSCTRL_getAuxPLLCkRefSel())
        {
            tempClk = (float)clockOut / (float)(SYSCTRL_getAuxPLLClkRefDiv() + 2);
        }
        else
        {
            tempClk = (float)clockOut;
        }

        /* PLL = OSC*(fcwssc +2)/2       PLL = OSC + OSC*fcwssc/2 */
        decPoint = SYSCTRL_getAuxPLLFcwSscDecPoint();
        decNum   = CLK_DOT_FCW_LEN - decPoint;
        fcwTmp = SYSCTRL_getAuxPLLFcwSsc();

        intSsc = fcwTmp >> decNum;
        decSsc = fcwTmp % (0x1U << decNum);

        fcwSscVal = (float)intSsc + (float)decSsc / (float)(0x1U << decNum);
        clockOut  = (uint32_t)(tempClk + (tempClk * fcwSscVal / 2));
    }

    clockOut = clockOut / (1U << SYSCTRL_getAuxClkDivSel());

    return clockOut;
}

void SYSCTRL_selectXTAL(void)
{
    /* Turn on XTAL */
    SYSCTRL_turnOnOsc(kSYSC_OSCSRC_XTAL);

    /* Wait for the X1 clock to overflow cpu timer 2 */
    DELAY(300);

    /* Select XTAL as the oscillator source */
    SYSCTRL_selOscClkSrc(kSYSC_OSCSRC_XTAL);

    /* If a missing clock failure was detected, try waiting for the cpu timer 2
       to overflow again. */
    while (SYSCTRL_isMCDClockFailureDetected())
    {
        /* Clear the MCD failure */
        SYSCTRL_resetMCD();

        /* Wait for the X1 clock to overflow cpu timer 2 */
        DELAY(300);

        /* Select XTAL as the oscillator source */
        SYSCTRL_selOscClkSrc(kSYSC_OSCSRC_XTAL);
    }
}

void SYSCTRL_selectOscSource(SYSCTRL_OscSrcSel_t oscSource)
{
    /* Select the specified source. */
    switch (oscSource)
    {
        case kSYSC_OSCSRC_INTOSC2:
            /* Turn on INTOSC2 */
            SYSCTRL_turnOnOsc(kSYSC_OSCSRC_INTOSC2);

            DELAY(300);

            /* Clk Src = INTOSC2 */
            SYSCTRL_selOscClkSrc(kSYSC_OSCSRC_INTOSC2);

            DELAY(300);

            /* Turn off XTALOSC */
            SYSCTRL_turnOffOsc(kSYSC_OSCSRC_XTAL);

            break;

        case kSYSC_OSCSRC_XTAL:
            /* Select XTAL in crystal mode and wait for it to power up */
            SYSCTRL_selectXTAL();
            break;

        case kSYSC_OSCSRC_INTOSC1:
            /* Clk Src = INTOSC1 */
            SYSCTRL_selOscClkSrc(kSYSC_OSCSRC_INTOSC1);

            DELAY(300);

            /* Turn off XTALOSC */
            SYSCTRL_turnOffOsc(kSYSC_OSCSRC_XTAL);

            break;

        default:
            /* Do nothing. Not a valid oscSource value. */
            break;
    }
}

void SYSCTRL_selectOscSourceAuxPLL(SYSCTRL_AuxSrcSel_t oscSource)
{
    switch (oscSource)
    {
        case kSYSC_AUXSRC_INTOSC2:
            /* Turn on INTOSC2 */
            SYSCTRL_turnOnOsc(kSYSC_OSCSRC_INTOSC2);

            /* Clk Src = INTOSC2 */
            SYSCTRL_selAuxClkSrc(kSYSC_AUXSRC_INTOSC2);
            break;

        case kSYSC_AUXSRC_XTAL:
            /* Turn on XTALOSC */
            SYSCTRL_turnOnOsc(kSYSC_OSCSRC_XTAL);

            /* Clk Src = XTAL */
            SYSCTRL_selAuxClkSrc(kSYSC_AUXSRC_XTAL);
            break;

        case kSYSC_AUXSRC_AUXCLKIN:
            /* Clk Src = AUXCLKIN */
            SYSCTRL_selAuxClkSrc(kSYSC_AUXSRC_AUXCLKIN);
            break;

        default:
            /* Do nothing. Not a valid clock source value. */
            break;
    }
}

bool SYSCTRL_setClock(SYSCTL_SysClk_Config_t config)
{
    uint32_t decNum, intSsc, decSsc, fcwSscVal;
    float    oscInFreq, fcwSscTmp1, fcwSscTmp2;
    /* Don't proceed to the PLL initialization if an MCD failure is detected. */
    if (SYSCTRL_isMCDClockFailureDetected())
    {
        /* OSCCLKSRC2 failure detected. Returning false. You'll need to clear
          the MCD error. */
        return false;
    }
    else
    {
        /* Configure oscillator source */
        SYSCTRL_selectOscSource(config.oscSrc);
        SYSCTRL_setSysClkDivSel(config.sysClkDiv);

        /* Bypass PLL */
        SYSCTRL_setPLLClkEn(kSYSC_DISABLE);


        if (config.pllEN == true)
        {
            if ((config.srcClkdiv == 0x0) || (config.pllClkFreq < config.oscFreq))
            {
                return false;
            }
            /* adjust pll clk config */
            if ((config.pllClkFreq < MIN_PLL_CLK) || (config.pllClkFreq > MAX_PLL_CLK))
            {
                return false;
            }
            if (config.pllClkFreq > HIGH_FQ_BANK_CLK)
                SYSCTRL_setPLLHighFreqBand(kSYSC_ENABLE);
            else
                SYSCTRL_setPLLHighFreqBand(kSYSC_DISABLE);

            /* Set dividers to /1 */
            SYSCTRL_setSysClkDivSel(0x0);
            // Close SYSPLL
            SYSCTRL_resetPLL(kSYSC_ENABLE);
            SYSCTRL_setPLLEn(kSYSC_DISABLE);
            SYSCTRL_setPLLLDOEn(kSYSC_DISABLE);
            /* set clk ref and div value */
            if (config.srcClkdiv == 0x1)
            {
                SYSCTRL_setPLLCkRefSel(kSYSC_DISABLE);
            }
            else
            {
                SYSCTRL_setPLLCkRefSel(kSYSC_ENABLE);
                SYSCTRL_setPLLClkRefDiv(config.srcClkdiv - 2);
            }

            /* calculate the fcwSSC value */
            decNum = CLK_DOT_FCW_LEN - CLK_DOT_FCW_POINT;
            SYSCTRL_setPLLFcwSscDecPoint(CLK_DOT_FCW_POINT);

            oscInFreq  = (float)(config.oscFreq) / (float)(config.srcClkdiv);
            fcwSscTmp1 = (float)(2 * config.pllClkFreq) / oscInFreq - 2;

            intSsc     = (uint32_t)fcwSscTmp1;
            fcwSscTmp2 = fcwSscTmp1 - (float)intSsc;
            decSsc     = (uint32_t)(fcwSscTmp2 * (1U << decNum));

            if (intSsc > 255)
            {
                return false;
            }

            fcwSscVal = (intSsc << decNum) | decSsc;
            SYSCTRL_setPLLFcwSsc(fcwSscVal);

            if (decSsc == 0)
                SYSCTRL_bypassPLLPi(kSYSC_ENABLE);
            else
                SYSCTRL_bypassPLLPi(kSYSC_DISABLE);


            // open ldo
            SYSCTRL_setPLLLDOEn(kSYSC_ENABLE);
            DELAY(10);
            SYSCTRL_setPLLEn(kSYSC_ENABLE);
            DELAY(2);
            SYSCTRL_resetPLL(kSYSC_DISABLE);
            DELAY(40);
            while (SYSCTRL_getPLLLockStatus() == 0)
                ;

            SYSCTRL_setSysClkDivSel(config.sysClkDiv);
            SYSCTRL_setPLLClkEn(kSYSC_ENABLE);
        }
        return true;
    }
}

bool SYSCTRL_setAuxClock(SYSCTL_AuxClk_Config_t config)
{
    uint32_t decNum, intSsc, decSsc, fcwSscVal;
    float    oscInFreq, fcwSscTmp1, fcwSscTmp2;


    /* Configure oscillator source */
    SYSCTRL_selAuxClkSrc(config.oscSrc);
    SYSCTRL_setAuxClkDivSel(config.auxClkDiv);

    /* Bypass PLL */
    SYSCTRL_setAuxPLLClkEn(kSYSC_DISABLE);


    if (config.pllEN == true)
    {
        if ((config.srcClkdiv == 0x0) || (config.pllClkFreq < config.oscFreq))
        {
            return false;
        }
        /* adjust pll clk config */
        if ((config.pllClkFreq < MIN_PLL_CLK) || (config.pllClkFreq > MAX_PLL_CLK))
        {
            return false;
        }
        if (config.pllClkFreq > HIGH_FQ_BANK_CLK)
            SYSCTRL_setAuxPLLHighFreqBand(kSYSC_ENABLE);
        else
            SYSCTRL_setAuxPLLHighFreqBand(kSYSC_DISABLE);

        /* Set dividers to /1 */
        SYSCTRL_setAuxClkDivSel(0x0);
        /* Close SYSPLL */
        SYSCTRL_resetAuxPLL(kSYSC_ENABLE);
        SYSCTRL_setAuxPLLEn(kSYSC_DISABLE);
        SYSCTRL_setAuxPLLLDOEn(kSYSC_DISABLE);
        /* set clk ref and div value */
        if (config.srcClkdiv == 0x1)
        {
            SYSCTRL_setAuxPLLCkRefSel(kSYSC_DISABLE);
        }
        else
        {
            SYSCTRL_setAuxPLLCkRefSel(kSYSC_ENABLE);
            SYSCTRL_setAuxPLLClkRefDiv(config.srcClkdiv - 2);
        }

        /* calculate the fcwSSC value */
        decNum = CLK_DOT_FCW_LEN - CLK_DOT_FCW_POINT;
        SYSCTRL_setAuxPLLFcwSscDecPoint(CLK_DOT_FCW_POINT);

        oscInFreq  = (float)(config.oscFreq) / (float)(config.srcClkdiv);
        fcwSscTmp1 = (float)(2 * config.pllClkFreq) / oscInFreq - 2;

        intSsc     = (uint32_t)fcwSscTmp1;
        fcwSscTmp2 = fcwSscTmp1 - (float)intSsc;
        decSsc     = (uint32_t)(fcwSscTmp2 * (1U << decNum));

        if (intSsc > 255)
        {
            return false;
        }

        fcwSscVal = (intSsc << decNum) | decSsc;
        SYSCTRL_setAuxPLLFcwSsc(fcwSscVal);

        if (decSsc == 0)
            SYSCTRL_bypassAuxPLLPi(kSYSC_ENABLE);
        else
            SYSCTRL_bypassAuxPLLPi(kSYSC_DISABLE);


        /* open ldo */
        SYSCTRL_setAuxPLLLDOEn(kSYSC_ENABLE);
        DELAY(10);
        SYSCTRL_setAuxPLLEn(kSYSC_ENABLE);
        DELAY(2);
        SYSCTRL_resetAuxPLL(kSYSC_DISABLE);
        DELAY(40);
        while (SYSCTRL_getAuxPLLLockStatus() == 0)
            ;

        SYSCTRL_setAuxClkDivSel(config.auxClkDiv);
        SYSCTRL_setAuxPLLClkEn(kSYSC_ENABLE);
    }
    return true;
}

#if defined(HTE_DEVICE_HS32F7D377_CPU1)

uint32_t SYSCTRL_getDeviceParametric(SYSCTL_DeviceParametric_t parametric)
{
    uint32_t value;

    /* Get requested parametric value */
    switch (parametric)
    {
        case kSYSCTL_DEVICE_REVID:
            /* Qualification Status */
            value = DEV_CFG_REGS->REVID;
            break;

        case kSYSCTL_DEVICE_PINCOUNT:
            /* Pin Count */
            value = DEV_CFG_REGS_PARTIDL_PIN_COUNT_Get(DEV_CFG_REGS->PARTIDL);
            break;

        case kSYSCTL_DEVICE_CPUID:
            /* InstaSPIN Feature Set */
            value = CPU_ID_REGS->CPUID;
            break;

        case kSYSCTL_DEVICE_FLASH:
            /* Flash Size (KB) */
            value = DEV_CFG_REGS_PARTIDL_FLASH_SIZE_Get(DEV_CFG_REGS->PARTIDL);
            break;

        case kSYSCTL_DEVICE_PARTID:
            /* PARTID Format Revision */
            value = DEV_CFG_REGS_PARTIDL_PARTID_FORMAT_REVISION_Get(DEV_CFG_REGS->PARTIDL);
            break;

        case kSYSCTL_DEVICE_FAMILY:
            /* Device Family */
            value = DEV_CFG_REGS_PARTIDH_FAMILY_Get(DEV_CFG_REGS->PARTIDH);
            break;

        case kSYSCTL_DEVICE_PARTNO:
            /* Part Number */
            value = DEV_CFG_REGS_PARTIDH_PARTNO_Get(DEV_CFG_REGS->PARTIDH);
            break;

        case kSYSCTL_DEVICE_CLASSID:
            /* Class ID */
            value = DEV_CFG_REGS_PARTIDH_DEVICE_CLASS_ID_Get(DEV_CFG_REGS->PARTIDH);
            break;

        default:
            /* Not a valid value for PARTID register */
            value = 0U;
            break;
    }

    return (value);
}

void SYSCTR_releaseCpu2(void)
{
    SYSCTRL_cfgCPU2Reset(kSYSC_CPU2_RELEASE);
    while (SYSCTRL_getCPU2ResetStatus() == false)
        ;
}


void SYSCTRL_init_sram(SYSCTRL_SramGs_t gsramId)
{
    SYSCTRL_SramGs_t i;
    if (gsramId == kSRAM_GSMAX)
    {
        for (i = kSRAM_GS0; i < kSRAM_GSMAX; i++)
        {
            SYSCTRL_initSramBlock(i);
            while (SYSCTRL_getSramInitDone(i) == false)
                ;
        }
    }
    else
    {
        SYSCTRL_initSramBlock(gsramId);
        while (SYSCTRL_getSramInitDone(gsramId) == false)
            ;
    }
}
#endif
