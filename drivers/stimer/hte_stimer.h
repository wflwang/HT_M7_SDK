/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_stimer.h
 * \brief SDK STIMER driver header file
 * \version 1.0.0
 */

#ifndef HTE_STIMER_H
#define HTE_STIMER_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_common.h"
#include "hte_sysctrl.h"

/*!
 * \addtogroup DRV_HTE_STIMER STIMER Driver
 *
 * \brief SDK STIMER driver
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! \brief index for timer int enable */
#define TIMER_INT_ENABLE  1 /*!< timer int enable*/
#define TIMER_INT_DISABLE 0 /*!< timer int disable*/

/*! \brief count for timer load */
#define TIMER_LOAD_CNT_1S  APB_CLOCK      /*!< timer 1s count value*/
#define TIMER_LOAD_CNT_2S  APB_CLOCK * 2  /*!< timer 2s count value*/
#define TIMER_LOAD_CNT_5S  APB_CLOCK * 5  /*!< timer 5s count value*/
#define TIMER_LOAD_CNT_10S APB_CLOCK * 10 /*!< timer 10s count value*/

/*! \brief index for stimer */
typedef enum
{
    kSTIMER_0 = 0,  /*!< timer0 index*/
    kSTIMER_1,      /*!< timer1 index*/
    kSTIMER_2,      /*!< timer2 index*/
    kSTIMER_MAX_NUM /*!< timer max index*/
} STIMER_Idx_t;

/*! \brief mode for timer */
typedef enum
{
    kTIMER_MODE_FREE_RUNNING = 0, /*!< timer free run mode*/
    kTIMER_MODE_USER_DEFINED = 1, /*!< timer user define mode*/
} STIMER_Mode_t;

/*! \brief type definition for TIMER callback  */
typedef void (*STIMER_Callback_t)();

/*! \brief type definition for stimer interrupt callback  */
typedef struct
{
    STIMER_Callback_t func[kSTIMER_MAX_NUM]; /*!< timer int callback function*/
} STIMER_Int_Callback_t;

/*******************************************************************************
 * APIs
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Select STimer 2 Clock Source and Prescaler
 *
 * \details This function selects the specified clock source and prescaler value
 *  for the stimer (CPU timer 2 only).
 *
 * \param[in] source parameter can be any one of the following:
 * - \b STIMER_CLOCK_SOURCE_SYS     - System Clock
 * - \b STIMER_CLOCK_SOURCE_INTOSC1 - Internal Oscillator 1 Clock
 * - \b STIMER_CLOCK_SOURCE_INTOSC2 - Internal Oscillator 2 Clock
 * - \b STIMER_CLOCK_SOURCE_XTAL    - External Clock
 * - \b STIMER_CLOCK_SOURCE_AUX     - Auxiliary PLL Clock
 * \param[in] prescaler parameter can be any one of the following:
 * - \b STIMER_CLOCK_PRESCALER_1  - Prescaler value of / 1
 * - \b STIMER_CLOCK_PRESCALER_2  - Prescaler value of / 2
 * - \b STIMER_CLOCK_PRESCALER_4  - Prescaler value of / 4
 * - \b STIMER_CLOCK_PRESCALER_8  - Prescaler value of / 8
 * - \b STIMER_CLOCK_PRESCALER_16 - Prescaler value of / 16
 *
 */
extern void STIMER2_selectClockSource(SYSCTRL_TimerClockSource_t source,
                                SYSCTRL_TimerPrescaler_t prescaler);

/*!
 * \brief config STimer
 *
 * \details This function initializes the selected timer to the
 *  eriod specified by the "freq" and "period" variables
 *
 * \param[in] index is the index of the timer module.
 * \param[in] mode is the mode of the timer.
 * \param[in] freq is the timer clk value.
 * \param[in] period is the CPU timerperiod value.
 *
 */                                
extern void STIMER_config(STIMER_Idx_t index, STIMER_Mode_t mode, uint32_t freq, uint32_t period);

/*!
 * \brief config STimer count2
 *
 * \details This function the selected timer cnt2 to the
 *  eriod specified by the "freq" and "period" variables
 *
 * \param[in] freq is the timer clk value.
 * \param[in] period is the CPU timerperiod value.
 *
 */
extern void STIMER_setCount2(uint32_t freq, uint32_t period);


/*!
 * \brief deinit STimer
 *
 * \details this function is used to uninit timer.
 * 
 *
 * \param[in] index is the index of the timer module.
 *
 */  
extern void STIMER_stop(STIMER_Idx_t index);

/*!
 * \brief get STimer count
 *
 * \details this function is used to get timer count.
 * 
 *
 * \param[in] index is the index of the timer module.
 * \return Returns the current timer count value.
 *
 */  
extern uint32_t STIMER_getCnt(STIMER_Idx_t index);

/*!
 * \brief set STimer count
 *
 * \details this function is used to set timer count.
 * 
 *
 * \param[in] index is the index of the timer module.
 * \param[in] cnt is the count value of the timer.
 *
 */
extern void STIMER_setCnt(STIMER_Idx_t index, uint32_t cnt);

/*!
 * \brief Disables stimer interrupt
 *
 * \details This function disables the stimer interrupt.
 *
 * \param[in] index is the index of the timer module.
 *
 */
extern void STIMER_disableInterrupt(STIMER_Idx_t index);

/*!
 * \brief Enables stimer interrupt
 *
 * \details This function enables the stimer interrupt.
 *
 * \param[in] index is the index of the timer module.
 *
 */
extern void STIMER_enableInterrupt(STIMER_Idx_t index);

/*!
 * \brief Enables stimer pwm
 *
 * \details This function enables the stimer pwm.
 *
 * \param[in] index is the index of the timer module.
 *
 */
extern void STIMER_enablePwm(STIMER_Idx_t index);

/*!
 * \brief Disables stimer pwm
 *
 * \details This function Disables the stimer pwm.
 *
 * \param[in] index is the index of the timer module.
 *
 */
extern void STIMER_disablePwm(STIMER_Idx_t index);

/*!
 * \brief clear STimer int pending
 *
 * \details this function is used to clear timerx intr pending.
 * 
 *
 * \param[in] index is the index of the timer module.
 *
 */
extern void STIMER_clearIntPending(STIMER_Idx_t index);

/*!
 * \brief GET STimer int status
 *
 * \details this function is used to get timerx intr pending.
 *
 *
 * \param[in] index is the index of the timer module.
 * \return Returns the current timer status value.
 */
extern uint32_t STIMER_getIntStatus(STIMER_Idx_t index);

/*!
 * \brief clear STimerx int pending
 *
 * \details this function is used to clear timerx intr pending.
 *
 *
 *
 */
extern void STIMER_clearAllInt(void);

/*!
 * \brief GET STimerx int status
 *
 * \details this function is used to get timerx intr status.
 *
 *
 * \return Returns the current timer status value.
 */
extern uint32_t STIMER_getAllIntStatus(void);

/*!
 * \brief GET STimerx raw int status
 *
 * \details this function is used to get timerx raw intr status.
 *
 *
 * \return Returns the current timer status value.
 */
extern uint32_t STIMER_getAllRawIntStatus(void);

/*!
 * \brief register STimer int callback function
 *
 * \details this function is register STimer int callback function.
 * 
 *
 * \param[in] intsrc is the index of the timer module.
 * \param[in] func is the function of the timer int callback.
 * \param[in] priority is the function of the timer int priority. 
 * \return Returns the register status.
 *
 */  
extern status_t STIMER_registerCallback(STIMER_Idx_t intsrc, STIMER_Callback_t func, uint32_t priority);

/*!
 * \brief unregister STimer int callback function
 *
 * \details this function is unregister STimer int callback function.
 * 
 *
 * \param[in] intsrc is the index of the timer module. 
 * \return Returns the register status.
 *
 */
extern status_t STIMER_unregisterCallback(STIMER_Idx_t intsrc);

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */ /* end of DRV_HTE_STIMER */

#endif // HTE_STIMER_H

