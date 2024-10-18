/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_common.h
 * \brief SDK Common driver header file
 * \version 1.0.0
 */

#ifndef HTE_COMMON_H
#define HTE_COMMON_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "hte_device.h"

/*!
 * \addtogroup DRV_HTE_COMMON Common Driver
 *
 * \brief SDK common driver
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! \brief Generate a version code */
#define MAKE_VERSION(tag, major, minor, bugfix) (((tag) << 24U) | ((major) << 16U) | ((minor) << 8U) | (bugfix))

/*! \brief Common driver version */
#define COMMON_DRIVER_VERSION MAKE_VERSION('V', 1U, 0U, 0U)

/*! \brief Compare and return the max one of two values */
#ifndef MAX
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif

/*! \brief Compare and return the min one of two values */
#ifndef MIN
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif

/*! \brief Computes the number of elements in an array */
#ifndef ARRAY_SIZE
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#endif

/*! \brief Get the offset of a member in a structure */
#ifndef offsetof
#define offsetof(type, member) ((size_t)(&(((type *)NULL)->member)))
#endif

/*! \brief Unused parameter or variable */
#ifndef UNUSED
#define UNUSED(x) ((void)(x))
#endif

/*! \brief Type used for all return status */
typedef uint32_t status_t;

/*! \brief Construct a status code using a group number and a status code */
#define MAKE_STATUS(group, code) (((group) << 8U) | (code))

/*! \brief Status group number list */
enum
{
    /* General Group. */
    kSTATUSGROUP_GENERAL = 0U, /*!< General */

    /* IP Driver Group. */
    kSTATUSGROUP_UART = 1U, /*!< UART */

    /* IP Driver Group. */
    kSTATUSGROUP_SPI = 2U, /*!< SPI */

    /* HAL(Hardware Abstraction Layer) Group. */
    kSTATUSGROUP_HAL_UART = 1000U, /*!< UART HAL */

    /* Component Group. */
    kSTATUSGROUP_COMP_OSAL = 2000U, /*!< OSAL(Operation System Abstraction Layer) */

    /* Middleware Group. */
    kSTATUSGROUP_MW_USB = 3000U, /*!< USB middleware */

    /* Application Group. */
    kSTATUSGROUP_APP_LED = 8000U, /*!< LED application */
};

/*! \brief Common status codes */
enum
{
    kSTATUS_SUCCESS          = MAKE_STATUS(kSTATUSGROUP_GENERAL, 0U), /*!< Success */
    kSTATUS_FAIL             = MAKE_STATUS(kSTATUSGROUP_GENERAL, 1U), /*!< General failure */
    kSTATUS_INVALID_ARGUMENT = MAKE_STATUS(kSTATUSGROUP_GENERAL, 2U), /*!< Invalid argument */
    kSTATUS_NOT_SUPPORTED    = MAKE_STATUS(kSTATUSGROUP_GENERAL, 3U), /*!< Not Supported */
    kSTATUS_TIMEOUT          = MAKE_STATUS(kSTATUSGROUP_GENERAL, 4U), /*!< Timeout */

    kSTATUS_INVALID =
        MAKE_STATUS(kSTATUSGROUP_GENERAL, 255U), /*!< Invalid Status used as the initial value of a status.*/
};

#define SDK_DELAY_USE_DWT     (0U) /*!< Use the Debug Watchpoint and Trace to delay some time */
#define SDK_DELAY_USE_SYSTICK (1U) /*!< Use SysTick to delay some time */
/*! \note Please note that software loop cannot offer a precise delay */
#define SDK_DELAY_USE_SWLOOP (2U) /*!< Use software loop to delay some time */

#ifndef SDK_DELAY_FUNC
#define SDK_DELAY_FUNC (SDK_DELAY_USE_DWT) /*!< Use DWT as default, which has precious delay period */
#endif

/*! \brief Delay a period in microseconds */
#if SDK_DELAY_FUNC == SDK_DELAY_USE_DWT
#define DELAY(microseconds) SDK_dwtDelay(microseconds, SystemCoreClock);
#elif SDK_DELAY_FUNC == SDK_DELAY_USE_SYSTICK
#define DELAY(microseconds) SDK_sysTickDelay(microseconds, SystemCoreClock);
#elif SDK_DELAY_FUNC == SDK_DELAY_USE_SWLOOP
#define DELAY(microseconds) SDK_swLoopDelay(microseconds, SystemCoreClock);
#else
#error Unknown delay function option
#endif

/*! \brief Convert microseconds to CPU tick value */
#define SDK_DELAY_USEC_TO_TICK(us, coreClockInHz) (uint64_t)(((uint64_t)(us) * (coreClockInHz)) / 1000000U)
/*! \brief Convert a CPU tick value to microseconds */
#define SDK_DELAY_TICK_TO_USEC(tick, coreClockInHz) (uint64_t)((uint64_t)(tick)*1000000U / (coreClockInHz))

/*! \brief Convert milliseconds to CPU tick value */
#define SDK_DELAY_MSEC_TO_TICK(ms, coreClockInHz) (uint64_t)(((uint64_t)(ms) * (coreClockInHz)) / 1000U)
/*! \brief Convert a CPU tick value to milliseconds */
#define SDK_DELAY_TICK_TO_MSEC(tick, coreClockInHz) (uint64_t)((uint64_t)(tick)*1000U / (coreClockInHz))

/*!
 * \brief ARM Cortex-M Series ISR exit barrier
 *
 * \note For Cortex-M4 and Cortex-M4F, the barrier is required to fix the ARM errata 838869 - Store immediate
 * overlapping exception return operation might vector to incorrect interrupt. For Cortex-M7, the barrier is required
 * too if core speed is much faster than the peripheral register write speed, the peripheral interrupt flags may be
 * still set after exiting ISR
 */
#if (defined __CORTEX_M) && ((__CORTEX_M == 4U) || (__CORTEX_M == 7U))
#define ISR_EXIT_BARRIER() __DSB()
#else
#define ISR_EXIT_BARRIER()
#endif

#if ((defined(__ARM_ARCH_7M__) && (__ARM_ARCH_7M__ == 1)) || (defined(__ARM_ARCH_7EM__) && (__ARM_ARCH_7EM__ == 1)) || \
     (defined(__ARM_ARCH_8M_MAIN__) && (__ARM_ARCH_8M_MAIN__ == 1)) ||                                                 \
     (defined(__ARM_ARCH_8M_BASE__) && (__ARM_ARCH_8M_BASE__ == 1)))
/*! \brief Macro to pick correct LDREX command for different pointer type */
#define SDK_LDREX(ptr)                               \
    ((sizeof(*(ptr)) == 1UL)                         \
         ? (uint32_t)__LDREXB((__IO uint8_t *)(ptr)) \
         : ((sizeof(*(ptr)) == 2UL) ? (uint32_t)__LDREXH((__IO uint16_t *)(ptr)) : __LDREXW((__IO uint32_t *)(ptr))))
/*! \brief Macro to pick correct STREX command for different pointer type */
#define SDK_STREX(value, ptr)                                                                                 \
    ((sizeof(*(ptr)) == 1UL) ? __STREXB((uint8_t)(value), (__IO uint8_t *)(ptr))                              \
                             : ((sizeof(*(ptr)) == 2UL) ? __STREXH((uint16_t)(value), (__IO uint16_t *)(ptr)) \
                                                        : __STREXW((uint32_t)(value), (__IO uint32_t *)(ptr))))

/*! \brief Atomic access macro to set one or several bit(s) */
#define ATOMIC_SET_BITS(var, bitMask)               \
    do                                              \
    {                                               \
        uint32_t value;                             \
        do                                          \
        {                                           \
            value  = SDK_LDREX(&(var));             \
            value |= (uint32_t)(bitMask);           \
        } while ((SDK_STREX(value, &(var))) != 0U); \
    } while (0)

/*! \brief Atomic access macro to clear one or several bit(s) */
#define ATOMIC_CLEAR_BITS(var, bitMask)             \
    do                                              \
    {                                               \
        uint32_t value;                             \
        do                                          \
        {                                           \
            value  = SDK_LDREX(&(var));             \
            value &= ~((uint32_t)(bitMask));        \
        } while ((SDK_STREX(value, &(var))) != 0U); \
    } while (0)

/*! \brief Atomic access macro to toggle one or several bit(s) */
#define ATOMIC_TOGGLE_BITS(var, bitMask)            \
    do                                              \
    {                                               \
        uint32_t value;                             \
        do                                          \
        {                                           \
            value  = SDK_LDREX(&(var));             \
            value ^= (uint32_t)(bitMask);           \
        } while ((SDK_STREX(value, &(var))) != 0U); \
    } while (0)

/*! \brief Atomic access macro to clear and set one or several bit(s) */
#define ATOMIC_CLEAR_AND_SET_BITS(var, clrBitMask, setBitMask)                        \
    do                                                                                \
    {                                                                                 \
        uint32_t value;                                                               \
        do                                                                            \
        {                                                                             \
            value = SDK_LDREX(&(var));                                                \
            value = (value & (~((uint32_t)(clrBitMask)))) | ((uint32_t)(setBitMask)); \
        } while ((SDK_STREX(value, &(var))) != 0U);                                   \
    } while (0)
#else
/*! \brief Atomic access macro to set one or several bit(s) */
#define ATOMIC_SET_BITS(var, bitMask)           \
    do                                          \
    {                                           \
        uint32_t priMask  = disableGlobalIRQ(); \
        (var)            |= (bitMask);          \
        enableGlobalIRQ(priMask);               \
    } while (0)

/*! \brief Atomic access macro to clear one or several bit(s) */
#define ATOMIC_CLEAR_BITS(var, bitMask)         \
    do                                          \
    {                                           \
        uint32_t priMask  = disableGlobalIRQ(); \
        (var)            &= ~(bitMask);         \
        enableGlobalIRQ(priMask);               \
    } while (0)

/*! \brief Atomic access macro to toggle one or several bit(s) */
#define ATOMIC_TOGGLE_BITS(var, bitMask)        \
    do                                          \
    {                                           \
        uint32_t priMask  = disableGlobalIRQ(); \
        (var)            ^= (bitMask);          \
        enableGlobalIRQ(priMask);               \
    } while (0)

/*! \brief Atomic access macro to clear and set one or several bit(s) */
#define ATOMIC_CLEAR_AND_SET_BITS(var, clrBitMask, setBitMask)       \
    do                                                               \
    {                                                                \
        uint32_t priMask = disableGlobalIRQ();                       \
        (var)            = ((var) & (~(clrBitMask))) | (setBitMask); \
        enableGlobalIRQ(priMask);                                    \
    } while (0)
#endif /* ((defined(__ARM_ARCH_7M__) && (__ARM_ARCH_7M__ == 1)) ||           \
           (defined(__ARM_ARCH_7EM__) && (__ARM_ARCH_7EM__ == 1)) ||         \
           (defined(__ARM_ARCH_8M_MAIN__) && (__ARM_ARCH_8M_MAIN__ == 1)) || \
           (defined(__ARM_ARCH_8M_BASE__) && (__ARM_ARCH_8M_BASE__ == 1))) */

/*! \brief Macro to define a variable with a specified alignment */
#if defined(__ALIGNED)
#define ALIGN(x) __ALIGNED(x)
#else
#if defined(__CC_ARM)
#define ALIGN(x) __attribute__((aligned(x)))
#elif defined(__ARMCC_VERSION)
#define ALIGN(x) __attribute__((aligned(x)))
#elif defined(__GNUC__)
#define ALIGN(x) __attribute__((aligned(x)))
#elif defined(__ICCARM__)
#if (__VER__ >= 7080000)
#define ALIGN(x) __attribute__((aligned(x)))
#else
#warning No compiler solution for variable alignment
#define ALIGN(x)
#endif /* (__VER__ >= 7080000) */
#else
#error Unknown toolchain
#endif
#endif /* defined(__ALIGNED) */

#if defined(__CC_ARM) || defined(__ARMCC_VERSION) || defined(__GNUC__)
/*! \brief Macro to put a variable to non-cacheable data section */
#define AT_NONCACHEABLE_DATA_SECTION(var) __attribute__((section(".NonCacheable.data"))) var
/*! \brief Macro to put a variable to non-cacheable bss section */
#if defined(__CC_ARAM)
#define AT_NONCACHEABLE_BSS_SECTION(var) __attribute__((section(".NonCacheable.bss"), zero_init)) var
#elif defined(__ARMCC_VERSION)
/* ARMCC requires ".bss" prefix for a BSS section */
#define AT_NONCACHEABLE_BSS_SECTION(var) __attribute__((section(".bss.NonCacheable"))) var
#elif defined(__GNUC__)
#define AT_NONCACHEABLE_BSS_SECTION(var) __attribute__((section(".NonCacheable.bss,\"aw\",%nobits @"))) var
#endif /* defined(__CC_ARAM) */
/*! \brief Macro to put a function to relocated text section */
#define AT_RELOCATED_TEXT_SECTION(func) __attribute__((section(".RamRelocated.text"), __noinline__)) func
/*! \brief Macro to put a function to relocated data section */
#define AT_RELOCATED_DATA_SECTION(var) __attribute__((section(".RamRelocated.data"))) var
/*! \brief Macro to put a function to relocated bss section */
#if defined(__CC_ARAM)
#define AT_RELOCATED_BSS_SECTION(var) __attribute__((section(".RamRelocated.bss"), zero_init)) var
#elif defined(__ARMCC_VERSION)
/* ARMCC requires ".bss" prefix for a BSS section */
#define AT_RELOCATED_BSS_SECTION(var) __attribute__((section(".bss.RamRelocated"))) var
#elif defined(__GNUC__)
#define AT_RELOCATED_BSS_SECTION(var) __attribute__((section(".RamRelocated.bss,\"aw\",%nobits @"))) var
#endif /* defined(__CC_ARAM) */
#elif defined(__ICCARM__)
/*! \brief Macro to put a variable to non-cacheable data section */
#define AT_NONCACHEABLE_DATA_SECTION(var) var @".NonCacheable.data"
/*! \brief Macro to put a variable to non-cacheable bss section */
#define AT_NONCACHEABLE_BSS_SECTION(var) var @".NonCacheable.bss"
/*! \brief Macro to put a function to relocated text section */
#define AT_RELOCATED_TEXT_SECTION(func) __attribute__((noinline)) func @".RamRelocated.text"
/*! \brief Macro to put a function to relocated data section */
#define AT_RELOCATED_DATA_SECTION(var) var @".RamRelocated.data"
/*! \brief Macro to put a function to relocated bss section */
#define AT_RELOCATED_BSS_SECTION(var) var @".RamRelocated.bss"
#else
#error Unknown toolchain
#endif /* defined(__CC_ARM) || defined(__ARMCC_VERSION) */

/*******************************************************************************
 * APIs
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Delay a imprecise period in microseconds
 *
 * \details This function uses software loop to perform the delay which cannot offer a precise delay period
 *
 * \note Please note that software loop cannot offer a precise delay
 *
 * \param[in] microseconds The microseconds to delay
 * \param[in] coreClockInHz The core clock
 */
void SDK_swLoopDelay(uint32_t microseconds, uint32_t coreClockInHz);

/*!
 * \brief Delay a precise period in microseconds
 *
 * \details This function uses SysTick to perform the delay
 *
 * \param[in] microseconds The microseconds to delay
 * \param[in] coreClockInHz The core clock
 */
void SDK_sysTickDelay(uint32_t microseconds, uint32_t coreClockInHz);

/*!
 * \brief Delay a imprecise period in microseconds
 *
 * \details This function uses DWT to perform the delay
 *
 * \param[in] microseconds The microseconds to delay
 * \param[in] coreClockInHz The core clock
 */
void SDK_dwtDelay(uint32_t microseconds, uint32_t coreClockInHz);

/*!
 * \brief Disable global interrupt and return the original global interrupt setting
 *
 * \details This function sets the PRIMASK to disable all interrupts which have a priority higher than/equal to 0. And
 * return the original PRIMASK which can be used by \ref enableGlobalIRQ() to restore the settings
 *
 * \return The original PRIMASK before the set operation
 */
static inline uint32_t disableGlobalIRQ(void)
{
    /* Backup the PRIMASK */
    uint32_t mask = __get_PRIMASK();
    /* Set PRIMASK to mask all interrupts */
    __set_PRIMASK(1U);
    return mask;
}

/*!
 * \brief Enable global interrupt based on the input PRIMASK
 *
 * \details This function restores the PRIMASK with the PRIMASK value got by \ref disableGlobalIRQ()
 *
 * \note This function DO NOT always enable the global interrupt. Instead, it restores the PRIMASK with the value got by
 * \ref disableGlobalIRQ(). With this feature, it is safe for nest calls to \ref disableGlobalIRQ() and \ref
 * enableGlobalIRQ().
 *
 * \param[in] priMask The PRIMASK value to restore
 */
static inline void enableGlobalIRQ(uint32_t priMask)
{
    /* Restore the PRIMASK */
    __set_PRIMASK(priMask);
}

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */ /* end of DRV_HTE_COMMON */

#endif /* HTE_COMMON_H */
