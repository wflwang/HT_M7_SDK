/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_assert.c
 * \brief SDK Assert driver source file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_common.h"
#include "hte_debug_console.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! \brief Assert driver version */
#define ASSERT_DRIVER_VERSION MAKE_VERSION('V', 1U, 0U, 0U)

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
#if defined(__CC_ARM) || defined(__ARMCC_VERSION) || defined(__ICCARM__)
void __aeabi_assert(const char *expr, const char *file, int line)
{
    PRINTF("Assert ERROR\r\n");
    PRINTF("\tExpr : %s\r\n", expr);
    PRINTF("\tFile : %s\r\n", file);
    PRINTF("\tLine : %d\r\n", line);

    for (;;)
    {
        __BKPT(0);
    }
}
#elif defined(__GNUC__)
void __assert_func(const char *file, int line, const char *func, const char *expr)
{
    PRINTF("Assert ERROR\r\n");
    PRINTF("\tExpr : %s\r\n", expr);
    PRINTF("\tFile : %s\r\n", file);
    PRINTF("\tLine : %d\r\n", line);
    PRINTF("\tFunc : %s\r\n", func);

    for (;;)
    {
        __BKPT(0);
    }
}
#else
#error Unknown toolchain
#endif /* defined(__CC_ARM) || defined(__ARMCC_VERSION) || defined(__ICCARM__) */
