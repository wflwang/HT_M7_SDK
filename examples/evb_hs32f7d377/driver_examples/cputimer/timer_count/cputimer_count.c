/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*!
 * \file hello_world.c
 * \brief Example of SDK debug console
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "board.h"
#include "clock_config.h"
#include "hte_cputimer.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! \brief cpu timer prescaler value */
#define EXAMPLE_TIMER_PRESCALER_VALUE (0U)

/*! \brief cpu timer period value, elment is usec */
#define EXAMPLE_TIMER_PERIOD_VALUE (2000000U)

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/* No Prototypes */

/*******************************************************************************
 * Variables
 ******************************************************************************/
extern CPUTIMER_Vars_t cpuTimer0;
uint8_t                ticks = 0;

/*******************************************************************************
 * Codes
 ******************************************************************************/
void cpu_timer0_irq_handler(void)
{
    ticks++;
    PRINTF("timer0 intr occurs : %d\r\n", ticks);
    if (ticks == 5)
    {
        PRINTF("timer0 intr done!!\r\n");
        CPUTIMER_disableInterrupt(CPUTIMER_REGS0);
    }
}

int main(void)
{
    /* Board initialization */
    BOARD_init();

    /* Cputimer initialization */
    CPUTIMER_registerCallback(kCPUTIMER_0, cpu_timer0_irq_handler, 0x05);
    InitCpuTimers();

    CPUTIMER_setIntMode(CPUTIMER_REGS0, kCPUTIMER_INT_PULSE);
    CPUTIMER_clearOverflowFlag(CPUTIMER_REGS0);
    CPUTIMER_enableInterrupt(CPUTIMER_REGS0);

    CPUTIMER_setHaltMode(CPUTIMER_REGS0, kCPUTIMER_FREE_RUN);
    ConfigCpuTimer(cpuTimer0, BOARD_getSysPclk(), EXAMPLE_TIMER_PERIOD_VALUE);
    CPUTIMER_setPrescaler(CPUTIMER_REGS0, EXAMPLE_TIMER_PRESCALER_VALUE);
    CPUTIMER_startTimer(CPUTIMER_REGS0);


    /* Print the example banner */
    PRINTF("\r\n");
    PRINTF("CPU TIMER Example:\r\n");
    PRINTF("2S count to enter interrupt, for 5 timers......\r\n");

    while (ticks < 5)
        ;
    CPUTIMER_stopTimer(CPUTIMER_REGS0);

    while (1)
        ;
}
