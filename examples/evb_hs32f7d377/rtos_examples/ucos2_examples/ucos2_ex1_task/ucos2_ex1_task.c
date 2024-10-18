/*
 * Copyright 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*!
 * \file ucos2_ex1_task.c
 * \brief ucos2 ex1 task source file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "board.h"
#include "hte_epwm.h"
#include "hte_gpio.h"
#include "hte_pinmux.h"
#include "hte_sysctrl.h"
#include "hte_xbar.h"
#include "ucos_ii.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define EPWM_TIMER_TBPRD 12000U
#define EPWM_CMPA_VALUE  3000U
#define EPWM_CMPB_VALUE  (EPWM_TIMER_TBPRD - EPWM_CMPA_VALUE)

#define EXAMPLE_EPWM_CPU1 EPWM12
#define EXAMPLE_EPWM_CPU2 EPWM11

#if defined(BOARD_USE_CPU1)
#define EXAMPLE_EPWM EXAMPLE_EPWM_CPU1
#elif defined(BOARD_USE_CPU2)
#define EXAMPLE_EPWM EXAMPLE_EPWM_CPU2
#endif

#define DECREASE_FREQUENCY 0
#define INCREASE_FREQUENCY 1
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/* No Prototypes */

/*******************************************************************************
 * Variables
 ******************************************************************************/
static OS_STK task_pwm_stk[512 - 1];
static OS_STK task_led_stk[128 - 1];
static OS_STK task_chk_stk[256 - 1];

/*******************************************************************************
 * Codes
 ******************************************************************************/
void EPWM_init()
{
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_EPWM12);
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_EPWM11);

    EPWM_setTimeBasePeriod(EXAMPLE_EPWM, EPWM_TIMER_TBPRD);
    EPWM_setTimeBaseCounterMode(EXAMPLE_EPWM, EPWM_COUNTER_MODE_UP); // 0, up

    EPWM_setCounterCompareValue(EXAMPLE_EPWM, EPWM_COUNTER_COMPARE_A, EPWM_CMPA_VALUE);
    EPWM_setCounterCompareValue(EXAMPLE_EPWM, EPWM_COUNTER_COMPARE_B, EPWM_CMPB_VALUE);

    // Set actions
    EPWM_setActionQualifierAction(EXAMPLE_EPWM, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    EPWM_setActionQualifierAction(EXAMPLE_EPWM, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(EXAMPLE_EPWM, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    EPWM_setActionQualifierAction(EXAMPLE_EPWM, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
}

void task_epwm(void *pada)
{
#if defined(BOARD_USE_CPU1)
    /* GPIO2: OUTPUT XBAR1 - ECAP1.OUT */
    BOARD_epwmPinConfig(EPWM12);

    GPIO_setPinConfig(GPIO_0_GPIO0);
    GPIO_setDirectionMode(0, kGPIO_DIR_INPUT);
    GPIO_setQualificationMode(0, kGPIO_QUAL_ASYNC);
    XBAR_setInputPin(INPUT_XBAR, kXBAR_INPUT1, 0);
#endif
#if defined(BOARD_CONFIG_CPU2)
    BOARD_epwmPinConfig(EPWM11);
    BOARD_epwmAssign2CPU2(EPWM11);
#endif

    SYSCTRL_disablePeripheral(kSYSCTL_PERIPH_CLK_TBCLKSYNC);

    EPWM_init();

    /* Enable the ePWM TBCLK peripheral */
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_TBCLKSYNC);

    EPWM_enableTripZoneSignals(EXAMPLE_EPWM_CPU1, EPWM_TZ_SIGNAL_CBC1);
    EPWM_setTripZoneAction(EXAMPLE_EPWM_CPU1, EPWM_TZ_ACTION_EVENT_TZA, EPWM_TZ_ACTION_HIGH);

    while (1)
    {
        OSTimeDly(300);
    }
}

void task_led(void *pada)
{
    GPIO_setPinConfig(GPIO_PINCONFIG(88, 0x0U));
    GPIO_setPadConfig(88, kGPIO_PADCONFIG_STD);
    GPIO_setDirectionMode(88, kGPIO_DIR_OUTPUT);

    GPIO_writePin(88, 0);

    while (1)
    {
        GPIO_togglePin(88);
        OSTimeDly(500);
    }
}

#ifdef DISPLAY_STACK
void task_check(void *pada)
{
    INT8U       err;
    OS_STK_DATA data;
    char        s[80];
    INT16S      time = 6;

    while (1)
    {
        OSTimeDly(1500);
        for (uint8_t i = 4; i < 7; i++)
        {
            err = OSTaskStkChk(i, &data);
            if (err == OS_ERR_NONE)
            {
                sprintf(s, "%4ld %4ld %4ld %6d", data.OSFree + data.OSUsed, data.OSFree, data.OSUsed, time);
            }
            PRINTF("%s", s);
        }
    }
}
#endif

int main(void)
{
    BOARD_init();
    BOARD_initTick();

    OSInit();
    OSTaskCreate(task_epwm, (void *)0, &task_pwm_stk[512 - 1], 4);
    OSTaskCreate(task_led, (void *)0, &task_led_stk[128 - 1], 5);
#ifdef DISPLAY_STACK
    OSTaskCreate(task_check, (void *)0, &task_chk_stk[256 - 1], 6);
#endif
    OSStart();

    return 0;
}

void PendSV_Handler(void)
{
    OS_CPU_PendSVHandler();
    ISR_EXIT_BARRIER();
}
