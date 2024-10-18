/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_common.c
 * \brief SDK Common driver source file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_common.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* No Definitions */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * \brief A software delay loop written by assembly
 *
 * \details Run numbers of software loops using assembly
 *
 * \param[in] count Delay loop count
 */
static inline void SDK_asmLoopDelay(uint32_t count);

/*!
 * \brief A SysTick delay loop
 *
 * \details Run numbers of SysTick count
 *
 * \param[in] count SysTick count
 */
static void SDK_sysTickLoopDelay(uint32_t count);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/* No Variables */

/*******************************************************************************
 * Codes
 ******************************************************************************/
void SDK_swLoopDelay(uint32_t microseconds, uint32_t coreClockInHz)
{
    uint64_t ticks = SDK_DELAY_USEC_TO_TICK(microseconds, coreClockInHz);

    assert(ticks <= UINT32_MAX);

    /*
     * SDK_asmLoopDelay has 3 instructions per loop
     * For Cortex-M7, 2 instructions of SDK_asmLoopDelay can be executed by one CPU tick.
     */

#if (__CORTEX_M == 7)
    SDK_asmLoopDelay(ticks / 3U * 2U);
#else
    SDK_asmLoopDelay(ticks / 3U);
#endif
}

static inline void SDK_asmLoopDelay(uint32_t count)
{
#if defined(__CC_ARM)
    __ASM volatile("loop:                       \n"
                   "    SUB    count, count, #1 \n"
                   "    CMP    count, #0        \n"
                   "    BNE    loop             \n");
#elif defined(__ARMCC_VERSION) || defined(__ICCARM__) || defined(__GNUC__)
    __ASM volatile("    MOV    R0, %0" : : "r"(count));
    __ASM volatile("loop:                 \n"
                   "    SUB    R0, R0, #1 \n"
                   "    CMP    R0, #0     \n"
                   "    BNE    loop       \n"
                   :
                   :
                   : "r0");
#endif
}

void SDK_sysTickDelay(uint32_t microseconds, uint32_t coreClockInHz)
{
    /* Covert microseconds to CPU ticks */
    uint64_t ticks = SDK_DELAY_USEC_TO_TICK(microseconds, coreClockInHz);

    /* SysTick is a 24bit timer, need to separate it into multiple loops to support the 32bit ticks */
    if (ticks <= (SysTick_LOAD_RELOAD_Msk + 1U))
    {
        /* One delay loop is enough */
        SDK_sysTickLoopDelay(ticks);
    }
    else
    {
        /* Delay the remainder */
        SDK_sysTickLoopDelay(ticks & SysTick_LOAD_RELOAD_Msk);

        /* Calculate the loop count */
        uint32_t loop = ticks / (SysTick_LOAD_RELOAD_Msk + 1U);

        /* Perform delay loops */
        for (; loop > 0; loop--)
        {
            SDK_sysTickLoopDelay(SysTick_LOAD_RELOAD_Msk + 1U);
        }
    }
}

static void SDK_sysTickLoopDelay(uint32_t count)
{
    /* Make sure the ticks cannot over the max supported range */
    assert(count <= (SysTick_LOAD_RELOAD_Msk + 1U));

    /* Set reload and counter value */
    SysTick->LOAD = (uint32_t)(count - 1U);
    SysTick->VAL  = 0U;

    /* Pick core clock as SysTick clock source, and enable SysTick timer, */
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;

    while (!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk))
        ;

    /* Disable the SysTick */
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}

void SDK_dwtDelay(uint32_t microseconds, uint32_t coreClockInHz)
{
    /* Covert microseconds to CPU ticks */
    uint64_t ticks = SDK_DELAY_USEC_TO_TICK(microseconds, coreClockInHz);
    /* Make sure the ticks cannot over the max supported range */
    assert(ticks <= UINT32_MAX);

    /* Enable all DWT and ITM features. */
#if (__CM_CMSIS_VERSION >= 0x60000) /* CMSIS above 6.0.0 */
    DCB->DEMCR |= DCB_DEMCR_TRCENA_Msk;
#else
    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
#endif

    /* Cycle counter not supported on this device. */
    assert(!(DWT->CTRL & DWT_CTRL_NOCYCCNT_Msk));

    /* Clear the cycle counter */
    DWT->CYCCNT = 0U;
    /* Enable the cycle counter */
    DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;

    while (DWT->CYCCNT < ticks)
        ;

    /* Disable the cycle counter */
    DWT->CTRL &= ~DWT_CTRL_CYCCNTENA_Msk;
}
