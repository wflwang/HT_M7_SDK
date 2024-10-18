/*
 * Copyright 2023 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_debug_console.h
 * \brief SDK Debug Console driver header file
 * \version 1.0.0
 */

#ifndef HTE_DEBUG_CONSOLE_H
#define HTE_DEBUG_CONSOLE_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_common.h"

/*!
 * \addtogroup COMP_HTE_DEBUG_CONSOLE Debug Console Component
 *
 * \brief SDK debug console component
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! \brief Debug console driver version */
#define DEBUG_CONSOLE_DRIVER_VERSION MAKE_VERSION('V', 1U, 0U, 0U)

#define DEBUG_CONSOLE_DISABLE   (0U) /*!< Disable debug console */
#define DEBUG_CONSOLE_TOOLCHAIN (1U) /*!< Use the debug console offered by Toolchain */
#define DEBUG_CONSOLE_SDK       (2U) /*!< Use the debug console offered by SDK */

#ifndef DEBUG_CONSOLE
#define DEBUG_CONSOLE (DEBUG_CONSOLE_TOOLCHAIN) /*!< Use Toolchain debug console */
#endif

#if DEBUG_CONSOLE == DEBUG_CONSOLE_DISABLE
#define PRINTF(...)  (void)0 /*!< Empty printf */
#define SCANF(...)   (void)0 /*!< Empty scanf */
#define PUTCHAR(...) (void)0 /*!< Empty putchar */
#define GETCHAR(...) (void)0 /*!< Empty getchar */
#define TSTCHAR()    (void)0 /*!< Empty tstchar */
#elif DEBUG_CONSOLE == DEBUG_CONSOLE_TOOLCHAIN
#include <stdio.h>
#define PRINTF(...)  printf(__VA_ARGS__)     /*!< Use Toolchain printf */
#define SCANF(...)   scanf(__VA_ARGS__)      /*!< Use Toolchain scanf */
#define PUTCHAR(...) putchar(__VA_ARGS__)    /*!< Use Toolchain putchar */
#define GETCHAR(...) getchar(__VA_ARGS__)    /*!< Use Toolchain getchar */
#define TSTCHAR()    DEBUG_CONSOLE_tstchar() /*!< Use SDK tstchar which is not available in Toolchain */
#elif DEBUG_CONSOLE == DEBUG_CONSOLE_SDK
#define PRINTF(...)  DEBUG_CONSOLE_printf(__VA_ARGS__)  /*!< Use SDK printf */
#define SCANF(...)   DEBUG_CONSOLE_scanf(__VA_ARGS__)   /*!< Use SDK scanf */
#define PUTCHAR(...) DEBUG_CONSOLE_putchar(__VA_ARGS__) /*!< Use SDK putchar */
#define GETCHAR(...) DEBUG_CONSOLE_getchar(__VA_ARGS__) /*!< Use SDK getchar */
#define TSTCHAR()    DEBUG_CONSOLE_tstchar()            /*!< Use SDK tstchar */
#else
#error Unknown debug console option
#endif

/*! \brief The type of the debug console */
typedef enum
{
    kDEBUG_CONSOLE_TYPE_INVALID  = 0U, /*!< Invalid */
    kDEBUG_CONSOLE_TYPE_UART     = 1U, /*!< UART */
} DEBUG_CONSOLE_Type_t;

/*! \brief The configuration of the debug console */
typedef struct
{
    DEBUG_CONSOLE_Type_t type; /*!< The type of the debug_console */

    uint32_t base;        /*!< The base address of the module used as debug console */
    uint32_t baudRate;    /*!< The baud rate of the debug console */
    uint32_t periphClock; /*!< The frequency of the module */
} DEBUG_CONSOLE_Config_t;

/*******************************************************************************
 * APIs
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

#if DEBUG_CONSOLE != DEBUG_CONSOLE_DISABLE
/*!
 * \brief  Debug Console initialization
 *
 * \details Initialize Debug Console with the configuration
 *
 * \param[in] config Debug Console configuration
 *
 * \retval kStatus_Success Success to initialize Debug Console
 * \retval kStatus_InvalidArugment Invalid options in the config
 * \retval kStatus_NotSupported Unsupported options in the config
 */
status_t DEBUG_CONSOLE_init(DEBUG_CONSOLE_Config_t *config);

/*!
 * \brief  Debug Console deinitialization
 *
 * \details Deinitialize Debug Console
 *
 * \retval kStatus_Success Success to deinitialize Debug Console
 */
status_t DEBUG_CONSOLE_deinit(void);

#else
/*!
 * \brief  Dummy Debug Console initialization when SDK debug console is disabled
 *
 * \param[in] config Debug Console configuration
 *
 * \retval kStatus_Fail    Fail to initialize Debug Console
 */
static inline status_t DEBUG_CONSOLE_init(DEBUG_CONSOLE_Config_t *config)
{
    (void)config;
    return kSTATUS_FAIL;
}

/*!
 * \brief  Dummy Debug Console deinitialization when SDK debug console is disabled
 *
 * \retval kStatus_Fail    Fail to deinitialize Debug Console
 */
static inline status_t DEBUG_CONSOLE_deinit(void)
{
    return kSTATUS_FAIL;
}

#endif

/*!
 * \brief Write formatted output to the stdout
 *
 * \details Write output to the stdout, under control of the string pointed to by format that specifies how subsequent
 * arguments are converted for output.
 *
 * \param[in] format The format string
 *
 * \return The number of characters transmitted, or a negative value if an error
 * occurred
 */
int DEBUG_CONSOLE_printf(const char *format, ...);

/*!
 * \brief Read formatted input from the stdin
 *
 * \details Read input from the stdin, under control of the string pointed to by format that specifies the admissible
 * input sequences and how they are to be converted for assignment, using subsequent arguments as pointers to the
 * objects to receive the converted input
 *
 * \param[in] format The format string
 *
 * \return The number of input items assigned, which can be fewer than provided for, or even zero, in the event of an
 * early matching failure
 */
int DEBUG_CONSOLE_scanf(const char *format, ...);

/*!
 * \brief Write a character to the stdout
 *
 * \details Write one character to the output stream pointed to by stdout
 *
 * \param[in] ch The character to write
 *
 * \return The character written, or an EOF if an error occurred
 */
int DEBUG_CONSOLE_putchar(int ch);

/*!
 * \brief Read a character from the stdin
 *
 * \details Read one character from the input stream pointed to by stdin
 *
 * \return The character read, or an EOF if an error occurred
 */
int DEBUG_CONSOLE_getchar(void);

/*!
 * \brief Test if a character is available in the stdin
 *
 * \details Test if there is one character at least in the input stream pointed to by stdin
 *
 * \return The status of the input stream
           - True: One character at least in the input stream
           - False: No character available in the input stream
 */
bool DEBUG_CONSOLE_tstchar(void);

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */ /* end of COMP_HTE_DEBUG_CONSOLE */

#endif /* HTE_DEBUG_CONSOLE_H */
