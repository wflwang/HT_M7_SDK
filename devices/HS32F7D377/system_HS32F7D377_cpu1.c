/*
 * Copyright 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file system_HS32F7D377_cpu1.c
 * \brief HS32F7D377 CPU1 system source file
 * \version 1.0.1
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdint.h>
#include "hte_device.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! brief Default system core clock after system reset */
#define DEFAULT_SYSTEM_CLOCK (10000000UL)

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*! \brief Manually initialize relocated text region */
void RelocatedTextInit(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! \brief System Clock Frequency (Core Clock) */
uint32_t SystemCoreClock = DEFAULT_SYSTEM_CLOCK;

/*******************************************************************************
 * Codes
 ******************************************************************************/
void SystemCoreClockUpdate(void) {}

void SystemInit(void)
{
#if (defined(__FPU_USED) && (__FPU_USED == 1U))
    SCB->CPACR |= ((3U << 10U * 2U) | /* enable CP10 Full Access */
                   (3U << 11U * 2U)); /* enable CP11 Full Access */
#endif

#ifdef UNALIGNED_SUPPORT_DISABLE
    SCB->CCR |= SCB_CCR_UNALIGN_TRP_Msk;
#endif

    RelocatedTextInit();
}

void RelocatedTextInit(void)
{
#if (defined(__ICCARM__))
#pragma section = ".RamRelocated.text"
#pragma section = ".RamRelocated.text_init"
    uint32_t  textSize = __section_size(".RamRelocated.text_init");
    uint32_t *textInit = __section_begin(".RamRelocated.text_init");
    uint32_t *text     = __section_begin(".RamRelocated.text");

    if (textSize)
    {
        uint32_t words          = textSize / 4U;
        uint32_t unalignedBytes = textSize % 4U;

        while (words)
        {
            *text++ = *textInit++;
            words--;
        }

        if (unalignedBytes != 0U)
        {
            uint32_t word     = *text;
            uint8_t *byte     = (uint8_t *)&word;
            uint8_t *byteInit = (uint8_t *)textInit;
            while (unalignedBytes != 0U)
            {
                *byte++ = *byteInit++;
                unalignedBytes--;
            }
            *text = word;
        }
    }

#pragma section = ".textrw"
#pragma section = ".textrw_init"
    uint32_t  textrwSize = __section_size(".textrw_init");
    uint32_t *textrwInit = __section_begin(".textrw_init");
    uint32_t *textrw     = __section_begin(".textrw");

    if (textrwSize)
    {
        uint32_t words          = textrwSize / 4U;
        uint32_t unalignedBytes = textrwSize % 4U;

        while (words)
        {
            *textrw++ = *textrwInit++;
            words--;
        }

        if (unalignedBytes != 0U)
        {
            uint32_t word     = *textrw;
            uint8_t *byte     = (uint8_t *)&word;
            uint8_t *byteInit = (uint8_t *)textrwInit;
            while (unalignedBytes != 0U)
            {
                *byte++ = *byteInit++;
                unalignedBytes--;
            }
            *textrw = word;
        }
    }
#endif
}
