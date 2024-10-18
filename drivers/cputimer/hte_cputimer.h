/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_cputimer.h
 * \brief SDK CPUTIMER driver header file
 * \version 1.0.0
 */

#ifndef HTE_CPUTIMER_H
#define HTE_CPUTIMER_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_common.h"
#include "hte_sysctrl.h"

/*!
 * \addtogroup DRV_HTE_CPUTIMER CPUTIMER Driver
 *
 * \brief SDK CPUTIMER driver
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! \brief index for cputimer emulation mode */
typedef enum
{
    //! Denotes that the timer will stop after the next decrement
    kCPUTIMER_EMULATIONMODE_STOPAFTERNEXTDECREMENT = 0x0000,
    //! Denotes that the timer will stop when it reaches zero
    kCPUTIMER_EMULATIONMODE_STOPATZERO = 0x0400,
    //! Denotes that the timer will run free
    kCPUTIMER_EMULATIONMODE_RUNFREE = 0x0800
} CPUTIMER_EmulationMode_t;

/*! \brief index for cputimer halt mode */
typedef enum
{
    kCPUTIMER_FREE_RUN,       /*!< free run mode*/
    kCPUTIMER_HALT_HARD_STOP, /*!< hard stop mode*/
    kCPUTIMER_HALT_SOFT_STOP  /*!< soft stop mode*/
} CPUTIMER_HaltMode_t;

/*! \brief index for cputimer int mode */
typedef enum
{
    kCPUTIMER_INT_PULSE, /*!< pulse int mode*/
    kCPUTIMER_INT_LEVEL  /*!< level int mode*/
} CPUTIMER_IntMode_t;

/*! \brief struct for cputimer vars */
typedef struct
{
    uint32_t            cpuFreqInMHz; /*!< cputimer cpu freq var*/
    uint32_t            periodInUSec; /*!< cputimer period var*/
    CPUTIMER_REGS_Type *regsAddr;     /*!< cputimer reg addr var*/
} CPUTIMER_Vars_t;

/*! \brief index for cputimer */
typedef enum
{
    kCPUTIMER_0 = 0,  /*!< cputimer 0 index*/
    kCPUTIMER_1,      /*!< cputimer 1 index*/
    kCPUTIMER_2,      /*!< cputimer 2 index*/
    kCPUTIMER_MAX_NUM /*!< cputimer max index*/
} CPUTIMER_Idx_t;

/*! \brief type definition for DMA callback  */
typedef void (*CPUTIMER_Callback_t)();

/*! \brief type definition for cputimer interrupt callback  */
typedef struct
{
    CPUTIMER_Callback_t func[kCPUTIMER_MAX_NUM]; /*!< cputimer int callback function*/
} CPUTIMER_Int_Callback_t;

/*! \brief type definition for bit fields in the TPR register */
#define CPUTIMER_TPR_TDDR_S 0U      /*!< CPU-Timer Divide-Down shift*/
#define CPUTIMER_TPR_TDDR_M 0xFFU   /*!< CPU-Timer Divide-Down mask*/
#define CPUTIMER_TPR_PSC_S  8U      /*!< CPU-Timer Prescale Counter shift*/
#define CPUTIMER_TPR_PSC_M  0xFF00U /*!< CPU-Timer Prescale Counter mask*/

/*! \brief type definition for bit fields in the TPRH register */
#define CPUTIMER_TPRH_TDDRH_S 0U      /*!< CPU-Timer High Divide-Down shift*/
#define CPUTIMER_TPRH_TDDRH_M 0xFFU   /*!< CPU-Timer High Divide-Down mask*/
#define CPUTIMER_TPRH_PSCH_S  8U      /*!< CPU-Timer High Prescale Counter shift*/
#define CPUTIMER_TPRH_PSCH_M  0xFF00U /*!< CPU-Timer High Prescale Counter mask*/

/*******************************************************************************
 * APIs
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Checks CPU timer base address
 *
 * \details This function determines if a CPU timer module base address is valid
 *
 * \param[in] base specifies the Timer module base address.
 * \return Return \b true if the base address is valid and \b false otherwise.
 *
 */
static inline bool CPUTIMER_isValid(CPUTIMER_REGS_Type *base)
{
    return ((base == CPUTIMER_REGS0) || (base == CPUTIMER_REGS1) || (base == CPUTIMER_REGS2));
}

/*!
 * \brief Clears CPU timer overflow flag
 *
 * \details This function clears the CPU timer overflow flag
 *
 * \param[in] base is the base address of the timer module.
 *
 */
static inline void CPUTIMER_clearOverflowFlag(CPUTIMER_REGS_Type *base)
{
    assert(CPUTIMER_isValid(base));
    //
    // Set TIF bit of TCR register
    //
    base->TCR |= CPUTIMER_REGS_TCR_TIF_Set(0x01U);
}

/*!
 * \brief Return the CPU timer overflow status
 *
 * \details This function returns the CPU timer overflow status.
 *
 * \param[in] base is the base address of the timer module.
 * \return Returns true if the CPU timer has overflowed, false if not.
 *
 */
static inline bool CPUTIMER_getOverflowStatus(CPUTIMER_REGS_Type *base)
{
    bool flag;
    assert(CPUTIMER_isValid(base));

    flag = CPUTIMER_REGS_TCR_TIF_Get(base->TCR);

    return flag;
}

/*!
 * \brief Disables CPU timer interrupt
 *
 * \details This function disables the CPU timer interrupt.
 *
 * \param[in] base is the base address of the timer module.
 *
 */
static inline void CPUTIMER_disableInterrupt(CPUTIMER_REGS_Type *base)
{
    assert(CPUTIMER_isValid(base));

    base->TCR &= ~CPUTIMER_REGS_TCR_TIE_Msk;
}

/*!
 * \brief Enables CPU timer interrupt.
 *
 * \details This function enables the CPU timer interrupt.
 *
 * \param[in] base is the base address of the timer module.
 *
 */
static inline void CPUTIMER_enableInterrupt(CPUTIMER_REGS_Type *base)
{
    assert(CPUTIMER_isValid(base));
    base->TCR |= CPUTIMER_REGS_TCR_TIE_Set(0x01U);
}

/*!
 * \brief Reloads CPU timer counter.
 *
 * \details  This function reloads the CPU timer counter with the values contained in
 *  the CPU timer period register.
 * \param[in] base is the base address of the timer module.
 *
 */
static inline void CPUTIMER_reloadTimerCounter(CPUTIMER_REGS_Type *base)
{
    assert(CPUTIMER_isValid(base));

    base->TCR |= CPUTIMER_REGS_TCR_TRB_Set(0x01U);
}

/*!
 * \brief Stops CPU timer.
 *
 * \details This function stops the CPU timer.
 *
 * \param[in] base is the base address of the timer module.
 *
 */
static inline void CPUTIMER_stopTimer(CPUTIMER_REGS_Type *base)
{
    assert(CPUTIMER_isValid(base));

    base->TCR |= CPUTIMER_REGS_TCR_TSS_Set(0x01U);
}

/*!
 * \brief resume CPU timer.
 *
 * \details This function resume the CPU timer.
 *
 * \param[in] base is the base address of the timer module.
 *
 */
static inline void CPUTIMER_resumeTimer(CPUTIMER_REGS_Type *base)
{
    assert(CPUTIMER_isValid(base));

    base->TCR &= ~CPUTIMER_REGS_TCR_TSS_Msk;
}

/*!
 * \brief Starts(restarts) CPU timer.
 *
 * \details This function starts (restarts) the CPU timer.
 *
 * \param[in] base is the base address of the timer module.
 *
 */
static inline void CPUTIMER_startTimer(CPUTIMER_REGS_Type *base)
{
    assert(CPUTIMER_isValid(base));

    base->TCR |= CPUTIMER_REGS_TCR_TRB_Set(0x01U);
    base->TCR &= ~CPUTIMER_REGS_TCR_TSS_Msk;
}

/*!
 * \brief halt mode CPU timer.
 *
 * \details This function set halt mode.
 *
 * \param[in] base is the base address of the timer module
 * \param[in] mode is timer halt mode
 *
 */
static inline void CPUTIMER_setHaltMode(CPUTIMER_REGS_Type *base, CPUTIMER_HaltMode_t mode)
{
    assert(CPUTIMER_isValid(base));

    if (mode == kCPUTIMER_FREE_RUN)
        base->TCR |= CPUTIMER_REGS_TCR_FREE_Set(0x01U);
    else if (mode == kCPUTIMER_HALT_HARD_STOP)
    {
        base->TCR &= ~CPUTIMER_REGS_TCR_FREE_Msk;
        base->TCR &= ~CPUTIMER_REGS_TCR_TIM_SOFT_Msk;
    }

    else if (mode == kCPUTIMER_HALT_SOFT_STOP)
    {
        base->TCR &= ~CPUTIMER_REGS_TCR_FREE_Msk;
        base->TCR |= CPUTIMER_REGS_TCR_TIM_SOFT_Set(0x01U);
    }
}

/*!
 * \brief INT mode CPU timer.
 *
 * \details This function set int mode.
 *
 * \param[in] base is the base address of the timer module.
 * \param[in] int_mode is the timer int mode.
 *
 */
static inline void CPUTIMER_setIntMode(CPUTIMER_REGS_Type *base, CPUTIMER_IntMode_t int_mode)
{
    assert(CPUTIMER_isValid(base));

    if (int_mode == kCPUTIMER_INT_PULSE)
        base->TCR &= ~CPUTIMER_REGS_TCR_INTR_OP_Msk;
    else if (int_mode == kCPUTIMER_INT_LEVEL)
        base->TCR |= CPUTIMER_REGS_TCR_INTR_OP_Set(0x01U);
}

/*!
 * \brief Sets CPU timer period.
 *
 * \details This function sets the CPU timer period count.
 *
 * \param[in] base is the base address of the timer module.
 * \param[in] period_count is the CPU timer period count.
 *
 */
static inline void CPUTIMER_setPeriod(CPUTIMER_REGS_Type *base, uint32_t period_count)
{
    assert(CPUTIMER_isValid(base));

    base->PRD = period_count;
}

/*!
 * \brief Sets CPU timer periodx.
 *
 * \details This function sets the CPU timer period count.
 *
 * \param[in] base is the base address of the timer module.
 * \param[in] period_count is the CPU timer period count.
 *
 */
static inline void CPUTIMER_setPeriodx(CPUTIMER_REGS_Type *base, uint32_t period_count)
{
    assert(CPUTIMER_isValid(base));

    base->PRDEX = period_count;
}

/*!
 * \brief Sets CPU timer 64bit period.
 *
 * \details This function sets the CPU timer period count.
 *
 * \param[in] base is the base address of the timer module.
 * \param[in] period_count is the CPU timer period count.
 *
 */
static inline void CPUTIMER_set64bitPeriod(CPUTIMER_REGS_Type *base, uint64_t period_count)
{
    uint32_t period_h, period_l;
    assert(CPUTIMER_isValid(base));

    period_l = (uint32_t)period_count;
    period_h = (uint32_t)(period_count >> 32);

    base->PRD   = period_l;
    base->PRDEX = period_h;
}

/*!
 * \brief Returns the current CPU timer counter value.
 *
 * \details  This function returns the current CPU timer counter value.
 *
 * \param[in] base is the base address of the timer module.
 * \return Returns the current CPU timer count value.
 *
 */
static inline uint32_t CPUTIMER_getTimerCount(CPUTIMER_REGS_Type *base)
{
    uint32_t time_count;
    assert(CPUTIMER_isValid(base));

    time_count = base->TIM;
    return time_count;
}

/*!
 * \brief Returns the current CPU timer counter value.
 *
 * \details This function returns the current CPU timer counter value.
 *
 * \param[in] base is the base address of the timer module.
 * \return Returns the current CPU timer count value.
 *
 */
static inline uint64_t CPUTIMER_get64bitTimerCount(CPUTIMER_REGS_Type *base)
{
    uint64_t time_count;
    uint32_t count_l, count_h;
    assert(CPUTIMER_isValid(base));

    count_l    = base->TIM;
    count_h    = base->TIMEX;
    time_count = ((uint64_t)count_h << 32U) | (uint64_t)count_l;

    return time_count;
}

/*!
 * \brief SET CPU timer counter value.
 *
 * \details This function SET  CPU timer counter value.
 *
 * \param[in] base is the base address of the timer module.
 * \param[in] time_count is the CPU timer count.
 *
 */
static inline void CPUTIMERr_setTimerCount(CPUTIMER_REGS_Type *base, uint32_t time_count)
{
    assert(CPUTIMER_isValid(base));

    base->TIM = time_count;
}

/*!
 * \brief Set CPU timer pre-scaler value.
 *
 * \details This function sets the pre-scaler value for the CPU timer. For every value
 *  of (prescaler + 1), the CPU timer counter decrements by 1.
 *
 * \param[in] base is the base address of the timer module.
 * \param[in] prescaler is the CPU timer pre-scaler value.
 *
 */
static inline void CPUTIMER_setPrescaler(CPUTIMER_REGS_Type *base, uint16_t prescaler)
{
    assert(CPUTIMER_isValid(base));

    base->TPRH &= ~CPUTIMER_REGS_TPRH_TDDRH_Msk;
    base->TPRH |= CPUTIMER_REGS_TPRH_TDDRH_Set(prescaler >> 8U);

    base->TPR &= ~CPUTIMER_REGS_TPR_TDDR_Msk;
    base->TPR |= CPUTIMER_REGS_TPR_TDDR_Set(prescaler & CPUTIMER_TPR_TDDR_M);
}

/*!
 * \brief Select CPU Timer 2 Clock Source and Prescaler
 *
 * \details This function selects the specified clock source and prescaler value
 *  for the CPU timer (CPU timer 2 only).
 *
 * \param[in] base is the base address of the timer module.
 * \param[in] source parameter can be any one of the following:
 * - \b CPUTIMER_CLOCK_SOURCE_SYS     - System Clock
 * - \b CPUTIMER_CLOCK_SOURCE_INTOSC1 - Internal Oscillator 1 Clock
 * - \b CPUTIMER_CLOCK_SOURCE_INTOSC2 - Internal Oscillator 2 Clock
 * - \b CPUTIMER_CLOCK_SOURCE_XTAL    - External Clock
 * - \b CPUTIMER_CLOCK_SOURCE_AUX     - Auxiliary PLL Clock
 * \param[in] prescaler parameter can be any one of the following:
 * - \b CPUTIMER_CLOCK_PRESCALER_1  - Prescaler value of / 1
 * - \b CPUTIMER_CLOCK_PRESCALER_2  - Prescaler value of / 2
 * - \b CPUTIMER_CLOCK_PRESCALER_4  - Prescaler value of / 4
 * - \b CPUTIMER_CLOCK_PRESCALER_8  - Prescaler value of / 8
 * - \b CPUTIMER_CLOCK_PRESCALER_16 - Prescaler value of / 16
 *
 */
extern void CPUTIMER_selectClockSource(CPUTIMER_REGS_Type *base, SYSCTRL_TimerClockSource_t source,
                                       SYSCTRL_TimerPrescaler_t prescaler);

/*!
 * \brief init CPUTimers
 *
 * \details This function initializes all three CPU timers to a known state.
 *
 */
extern void InitCpuTimers(void);

/*!
 * \brief config CPUTimer
 *
 * \details This function initializes the selected timer to the
 *  eriod specified by the "freq" and "period" variables
 *
 * \param[in] cpuTimer is the index of the timer module.
 * \param[in] freq is the base address of the timer freq.
 * \param[in] period is the CPU timerperiod value.
 *
 */
extern void ConfigCpuTimer(CPUTIMER_Vars_t cpuTimer, uint32_t freq, uint32_t period);

/*!
 * \brief config CPUTimer 64bit
 *
 * \details This function initializes the selected timer to the
 *  eriod specified by the "freq" and "period" variables
 *
 * \param[in] cpuTimer is the index of the timer module.
 * \param[in] period is the CPU timerperiod 64bit value.
 * \param[in] freq is the base address of the timer freq.
 *
 */
extern void ConfigCpuTimer64bit(CPUTIMER_Vars_t cpuTimer, uint32_t freq, uint64_t period);


/*!
 * \brief Register user callback function to a specified CPUTIMER
 *
 * \details This function registers user callback function for CPUTIMER which uses IRQ. The relative IRQ
 will be enabled in the NVIC and the priority will be configured at the same time

 * \param[in] intsrc is CPUTIMER index
 * \param[in] func is CPUTIMER user callback
 * \param[in] priority is IRQ priority
 *
 * \retval kSTATUS_SUCESS Success to the operation
 * \retval kSTATUS_FAIL Register to a CPUTIMER which has been registered already. Need to call \ref
 CPUTIMER_unregisterCallback() before the re-registration
 */
status_t CPUTIMER_registerCallback(CPUTIMER_Idx_t intsrc, CPUTIMER_Callback_t func, uint32_t priority);


/*!
 * \brief Unregister user callback function to CPUTIMER transfer
 *
 * \details This function clears the registered user callback function, and disable the relative IRQ in the NVIC
 *
 * \param[in] intsrc the CPUTIMER INT index
 * \retval kSTATUS_SUCESS Success to the operation
 * \retval kSTATUS_INVALID_ARGUMENT The CPUTIMER hasn't been registered to a callback
 */
status_t CPUTIMER_unregisterCallback(CPUTIMER_Idx_t intsrc);

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */ /* end of DRV_HTE_CPUTIMER */

#endif /* HTE_CPUTIMER_H */
