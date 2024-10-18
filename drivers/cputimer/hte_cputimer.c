/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_cputimer.c
 * \brief SDK CPUTIMER driver source file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_cputimer.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define MHZ_CARDINAL_NUM 1000000U /* freq mhz cardinal number */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/* No Prototypes */

/*******************************************************************************
 * Variables
 ******************************************************************************/
static CPUTIMER_Int_Callback_t s_cputimerISR = { 0 }; /*!<timer int callback function */
/*! \brief Array of CPUTIMER IRQ number */
static const IRQn_Type s_cputimerIRQ[] = CPUTIMER_IRQS; /*!<timer int req num */

/*! \brief vars of cputimer number */
CPUTIMER_Vars_t cpuTimer0; /*!<timer0 var */
CPUTIMER_Vars_t cpuTimer1; /*!<timer1 var */
CPUTIMER_Vars_t cpuTimer2; /*!<timer2 var */

/*******************************************************************************
 * Codes
 ******************************************************************************/
void CPUTIMER_selectClockSource(CPUTIMER_REGS_Type *base, SYSCTRL_TimerClockSource_t source,
                                SYSCTRL_TimerPrescaler_t prescaler)
{
    assert(base == CPUTIMER_REGS2);

    //
    // Set source and prescaler for CPU Timer 2
    //
    if (base == CPUTIMER_REGS2)
    {
        // EALLOW;
        //
        //  Set Clock Source
        //
        CPU_SYS_REGS->TMR2CLKCTL &= ~CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKSRCSEL_Msk;
        CPU_SYS_REGS->TMR2CLKCTL |= CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKSRCSEL_Set(source);
        //
        // Set Clock Prescaler
        //
        CPU_SYS_REGS->TMR2CLKCTL &= ~CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKPRESCALE_Msk;
        CPU_SYS_REGS->TMR2CLKCTL |= CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKPRESCALE_Set(prescaler);

        // EDIS;
    }
}

void InitCpuTimers(void)
{
    //
    // Initialize address pointers to respective timer registers:
    //
    cpuTimer0.regsAddr = CPUTIMER_REGS0;
    cpuTimer1.regsAddr = CPUTIMER_REGS1;
    cpuTimer2.regsAddr = CPUTIMER_REGS2;
    //
    // Initialize timer period to maximum
    //
    CPUTIMER_setPeriod(CPUTIMER_REGS0, 0xFFFFFFFF);
    CPUTIMER_setPeriod(CPUTIMER_REGS1, 0xFFFFFFFF);
    CPUTIMER_setPeriod(CPUTIMER_REGS2, 0xFFFFFFFF);

    CPUTIMER_setPeriodx(CPUTIMER_REGS0, 0x0);
    CPUTIMER_setPeriodx(CPUTIMER_REGS1, 0x0);
    CPUTIMER_setPeriodx(CPUTIMER_REGS2, 0x0);

    //
    // Initialize pre-scale counter to divide by 1 (SYSCLKOUT)
    //
    CPUTIMER_setPrescaler(CPUTIMER_REGS0, 0);
    CPUTIMER_setPrescaler(CPUTIMER_REGS1, 0);
    CPUTIMER_setPrescaler(CPUTIMER_REGS2, 0);

    //
    // Make sure timer is stopped
    //
    CPUTIMER_stopTimer(CPUTIMER_REGS0);
    CPUTIMER_stopTimer(CPUTIMER_REGS1);
    CPUTIMER_stopTimer(CPUTIMER_REGS2);

    //
    // Reload all counter register with period value
    //
    CPUTIMER_reloadTimerCounter(CPUTIMER_REGS0);
    CPUTIMER_reloadTimerCounter(CPUTIMER_REGS1);
    CPUTIMER_reloadTimerCounter(CPUTIMER_REGS2);

    //
    // Reset interrupt counter
    //
    // cpuTimer0IntCount = 0;
    // cpuTimer1IntCount = 0;
    // cpuTimer2IntCount = 0;
}

void ConfigCpuTimer(CPUTIMER_Vars_t cpuTimer, uint32_t freq, uint32_t period)
{
    uint32_t temp;

    //
    // Initialize timer period:
    //
    cpuTimer.cpuFreqInMHz = freq / MHZ_CARDINAL_NUM;
    cpuTimer.periodInUSec = period;

    temp = ((freq / MHZ_CARDINAL_NUM) * period);
    CPUTIMER_setPeriod(cpuTimer.regsAddr, temp);
    CPUTIMER_setPeriodx(cpuTimer.regsAddr, 0x0);

    //
    // Set pre-scale counter to divide by 1 (SYSCLKOUT):
    //
    CPUTIMER_setPrescaler(cpuTimer.regsAddr, 0);

    //
    // Initializes timer control register. The timer is stopped, reloaded,
    // free run disabled, and interrupt enabled.
    // Additionally, the free and soft bits are set
    //
    CPUTIMER_stopTimer(cpuTimer.regsAddr);
    CPUTIMER_reloadTimerCounter(cpuTimer.regsAddr);
}

void ConfigCpuTimer64bit(CPUTIMER_Vars_t cpuTimer, uint32_t freq, uint64_t period)
{
    uint64_t temp;

    //
    // Initialize timer period:
    //
    cpuTimer.cpuFreqInMHz = freq / MHZ_CARDINAL_NUM;
    cpuTimer.periodInUSec = period;

    temp = ((freq / MHZ_CARDINAL_NUM) * period);
    CPUTIMER_setPeriod(cpuTimer.regsAddr, (uint32_t)temp);
    CPUTIMER_setPeriodx(cpuTimer.regsAddr, (uint32_t)(temp >> 32));

    //
    // Set pre-scale counter to divide by 1 (SYSCLKOUT):
    //
    CPUTIMER_setPrescaler(cpuTimer.regsAddr, 0);

    //
    // Initializes timer control register. The timer is stopped, reloaded,
    // free run disabled, and interrupt enabled.
    // Additionally, the free and soft bits are set
    //
    CPUTIMER_stopTimer(cpuTimer.regsAddr);
    CPUTIMER_reloadTimerCounter(cpuTimer.regsAddr);
}


status_t CPUTIMER_registerCallback(CPUTIMER_Idx_t intsrc, CPUTIMER_Callback_t func, uint32_t priority)
{
    assert(intsrc < kCPUTIMER_MAX_NUM);
    assert(func);

    if (s_cputimerISR.func[intsrc] != NULL)
    {
        /* DMA ISR callback has been registered already, return failure */
        return kSTATUS_FAIL;
    }

    /* Enable the driver interrupt service */
    s_cputimerISR.func[intsrc] = func;

    /* Set interrupt priority and enable the interrupt */
    NVIC_SetPriority(s_cputimerIRQ[intsrc], priority);
    NVIC_EnableIRQ(s_cputimerIRQ[intsrc]);

    return kSTATUS_SUCCESS;
}

status_t CPUTIMER_unregisterCallback(CPUTIMER_Idx_t intsrc)
{
    assert(intsrc < kCPUTIMER_MAX_NUM);

    if (s_cputimerISR.func[intsrc] == NULL)
    {
        /* UART instance hasn't been registered, return failure */
        return kSTATUS_INVALID_ARGUMENT;
    }

    /* Restore interrupt priority and disable the interrupt */
    NVIC_SetPriority(s_cputimerIRQ[intsrc], 0U);
    NVIC_DisableIRQ(s_cputimerIRQ[intsrc]);

    /* Clear the interrupt service and handle */
    s_cputimerISR.func[intsrc] = NULL;

    return kSTATUS_SUCCESS;
}

/*!
 * \brief call the user callback function
 *
 * \details This function call the registered user callback function
 *
 * \param[in] intsrc the CPUTIMER INT index
 */
void CPUTIMER_handlerIRQ(CPUTIMER_Idx_t intsrc)
{
    if (s_cputimerISR.func[intsrc] != NULL)
    {
        s_cputimerISR.func[intsrc]();
    }
}

/*!
 * \brief call the cputimer0 callback function
 *
 * \details This function call the registered cputimer0 callback function
 *
 */
void CPUTIMER0_DriverHandler(void)
{
    CPUTIMER_handlerIRQ(kCPUTIMER_0);
    ISR_EXIT_BARRIER();
}

/*!
 * \brief call the cputimer1 callback function
 *
 * \details This function call the registered cputimer1 callback function
 *
 */
void CPUTIMER1_DriverHandler(void)
{
    CPUTIMER_handlerIRQ(kCPUTIMER_1);
    ISR_EXIT_BARRIER();
}

/*!
 * \brief call the cputimer2 callback function
 *
 * \details This function call the registered cputimer2 callback function
 *
 */
void CPUTIMER2_DriverHandler(void)
{
    CPUTIMER_handlerIRQ(kCPUTIMER_2);
    ISR_EXIT_BARRIER();
}
