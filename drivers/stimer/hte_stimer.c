/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_stimer.c
 * \brief SDK STIMER driver source file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_stimer.h"

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
static STIMER_Int_Callback_t s_stimerISR = { 0 }; /*!<stimer int callback function */
/*! \brief Array of STIMER IRQ number */
static const IRQn_Type s_stimerIRQ[] = STIMER_IRQS; /*!<stimer int req num */

/*******************************************************************************
 * Codes
 ******************************************************************************/ 
void STIMER2_selectClockSource(SYSCTRL_TimerClockSource_t source,
                                SYSCTRL_TimerPrescaler_t prescaler)
{
    CPU_SYS_REGS->DWTMR2CLKCTL &= ~CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKSRCSEL_Msk;
    CPU_SYS_REGS->DWTMR2CLKCTL |= CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKSRCSEL_Set(source);
    //
    // Set Clock Prescaler
    //
    CPU_SYS_REGS->DWTMR2CLKCTL &= ~CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKPRESCALE_Msk;
    CPU_SYS_REGS->DWTMR2CLKCTL |= CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKPRESCALE_Set(prescaler);
}

void STIMER_config(STIMER_Idx_t index, STIMER_Mode_t mode, uint32_t freq, uint32_t period)
{
    uint32_t temp;
    /*disable timerx*/
    STIMER->T_UNIT[index].CONTROL_REG &= ~STIMER_CONTROL_REG_TIM_EN_Msk;
    
    /*setup timer work mode*/
    if(mode == kTIMER_MODE_USER_DEFINED)
    {
        STIMER->T_UNIT[index].CONTROL_REG |= STIMER_CONTROL_REG_MODE_Set(1U);
        temp                               = ((freq / MHZ_CARDINAL_NUM) * period);
        STIMER->T_UNIT[index].LOAD_COUNT = temp;
    }
    else
    {
        STIMER->T_UNIT[index].CONTROL_REG &= ~STIMER_CONTROL_REG_MODE_Msk;
        STIMER->T_UNIT[index].LOAD_COUNT = 0xFFFFFFFF;
    }

    /*enable timerx*/
    STIMER->T_UNIT[index].CONTROL_REG |=  STIMER_CONTROL_REG_TIM_EN_Set(1U);
    
}

void STIMER_setCount2(uint32_t freq, uint32_t period)
{
    uint32_t temp;

    temp                = ((freq / MHZ_CARDINAL_NUM) * period);
    STIMER->LOAD_COUNT2 = temp;
}

void STIMER_stop(STIMER_Idx_t index)
{
    /*disable timerx*/
    STIMER->T_UNIT[index].CONTROL_REG &= ~STIMER_CONTROL_REG_TIM_EN_Msk;     

}

uint32_t STIMER_getCnt(STIMER_Idx_t index)
{
    uint32_t timerCount;

    timerCount = STIMER->T_UNIT[index].CURRENT_VALUE;
    
    return timerCount;
}

void STIMER_setCnt(STIMER_Idx_t index, uint32_t cnt)
{

    STIMER->T_UNIT[index].CONTROL_REG &= ~ STIMER_CONTROL_REG_TIM_EN_Set(1U);//disable timerx
    STIMER->T_UNIT[index].CURRENT_VALUE = cnt;
    STIMER->T_UNIT[index].CONTROL_REG |=  STIMER_CONTROL_REG_TIM_EN_Set(1U);//enable timerx        
}

void STIMER_disableInterrupt(STIMER_Idx_t index)
{
      STIMER->T_UNIT[index].CONTROL_REG |= STIMER_CONTROL_REG_INT_MASK_Set(1U);//mask int
}

void STIMER_enableInterrupt(STIMER_Idx_t index)
{
    STIMER->T_UNIT[index].CONTROL_REG &= ~STIMER_CONTROL_REG_INT_MASK_Msk;//unmask int
}

void STIMER_enablePwm(STIMER_Idx_t index)
{
    STIMER->T_UNIT[index].CONTROL_REG |= STIMER_CONTROL_REG_PWM_Set(1U);
}

void STIMER_disablePwm(STIMER_Idx_t index)
{
    STIMER->T_UNIT[index].CONTROL_REG &= ~STIMER_CONTROL_REG_PWM_Msk;
}

void STIMER_clearIntPending(STIMER_Idx_t index)
{
    STIMER->T_UNIT[index].EOI;
}

uint32_t STIMER_getIntStatus(STIMER_Idx_t index)
{
    return STIMER->T_UNIT[index].INT_STATUS;
}

void STIMER_clearAllInt(void)
{
    STIMER->TIMERS_EOI;
}

uint32_t STIMER_getAllIntStatus(void)
{
    return STIMER->TIMERS_INT_STATUS;
}

uint32_t STIMER_getAllRawIntStatus(void)
{
    return STIMER->RAW_INT_STATUS;
}

status_t STIMER_registerCallback(STIMER_Idx_t intsrc, STIMER_Callback_t func, uint32_t priority)
{
    assert(intsrc < kSTIMER_MAX_NUM);
    assert(func);

    if (s_stimerISR.func[intsrc] != NULL)
    {
        /* DMA ISR callback has been registered already, return failure */
        return kSTATUS_FAIL;
    }

    /* Enable the driver interrupt service */
    s_stimerISR.func[intsrc] = func;

    /* Set interrupt priority and enable the interrupt */    
    NVIC_SetPriority(s_stimerIRQ[intsrc], priority);
    NVIC_EnableIRQ(s_stimerIRQ[intsrc]);

    return kSTATUS_SUCCESS;
}

status_t STIMER_unregisterCallback(STIMER_Idx_t intsrc)
{
    assert(intsrc < kSTIMER_MAX_NUM);

    if (s_stimerISR.func[intsrc] == NULL)
    {
        /* UART instance hasn't been registered, return failure */
        return kSTATUS_INVALID_ARGUMENT;
    }

    /* Restore interrupt priority and disable the interrupt */
    NVIC_SetPriority(s_stimerIRQ[intsrc], 0U);
    NVIC_DisableIRQ(s_stimerIRQ[intsrc]);

    /* Clear the interrupt service and handle */
    s_stimerISR.func[intsrc] = NULL;

    return kSTATUS_SUCCESS;
}

/*!
 * \brief call the user callback function
 *
 * \details This function call the registered user callback function
 *
 * \param[in] intsrc the CPUTIMER INT index
 */
void STIMER_handlerIRQ(STIMER_Idx_t intsrc)
{
    if (s_stimerISR.func[intsrc] != NULL)
    {
        s_stimerISR.func[intsrc]();
    }
}

/*!
 * \brief call the stimer0 callback function
 *
 * \details This function call the registered stimer0 callback function
 *
 */
void DWTIMER_CH0_DriverHandler(void)
{
    STIMER_handlerIRQ(kSTIMER_0);
    ISR_EXIT_BARRIER();
}

/*!
 * \brief call the stimer1 callback function
 *
 * \details This function call the registered stimer1 callback function
 *
 */
void DWTIMER_CH1_DriverHandler(void)
{
    STIMER_handlerIRQ(kSTIMER_1);
    ISR_EXIT_BARRIER();
}

/*!
 * \brief call the stimer2 callback function
 *
 * \details This function call the registered stimer2 callback function
 *
 */
void DWTIMER_CH2_DriverHandler(void)
{
    STIMER_handlerIRQ(kSTIMER_2);
    ISR_EXIT_BARRIER();
}
