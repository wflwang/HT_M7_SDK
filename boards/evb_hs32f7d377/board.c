/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file board.c
 * \brief HS32F7D377 EVB board configuration source file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "board.h"
#include "hte_sysctrl.h"
#if BOARD_CONFIG_CPU2
#include "hte_cpu1_ipc.h"
#endif
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* No Definitions */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/* No Prototypes */

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! \brief MPU region tables */
ARM_MPU_Region_t s_mpuRegions[] = {
#if defined(BOARD_USE_CPU1)
    /*
     * Note:
     * 1. Add execute-never and inaccessible region to cover all unmapped memory.
     *    Refer to Arm errata 1013783 for more details.
     * 2. CPU2 ITCM and DTCM cannot be accessed by CPU1 due to the following MPU configuration.
     *    It is suggested to use MSGRAM for communication between the CPUs, instead of CPU2 ITCM and DTCM.
     */
    /* Region 0: [0x00000000 - 0xFFFFFFFF], No instruction access, No data access */
    { ARM_MPU_RBAR(0U, 0x00000000U), ARM_MPU_RASR(1U, ARM_MPU_AP_NONE, 0U, 0U, 0U, 0U, 0U, ARM_MPU_REGION_SIZE_4GB) },
    /* Region 1: [0x00000000 - 0x0001FFFF], Instruction access, Full data access, Normal, Outer and inner write-back,
       write and read allocate, Non-shared */
    { ARM_MPU_RBAR(1U, 0x00000000U), ARM_MPU_RASR(0U, ARM_MPU_AP_FULL, 1U, 0U, 1U, 1U, 0U, ARM_MPU_REGION_SIZE_128KB) },
    /* Region 2: [0x00200000 - 0x0021FFFF], Instruction access, Full data access, Normal, Outer and inner non-cacheable,
       Shared */
    { ARM_MPU_RBAR(2U, 0x00200000U), ARM_MPU_RASR(0U, ARM_MPU_AP_FULL, 1U, 1U, 0U, 0U, 0U, ARM_MPU_REGION_SIZE_128KB) },
    /* Region 3: [0x00300000 - 0x003FFFFF], Instruction access, Full data access, Normal, Outer and inner write-through,
       Non-shared */
    { ARM_MPU_RBAR(3U, 0x00300000U), ARM_MPU_RASR(0U, ARM_MPU_AP_FULL, 0U, 0U, 1U, 0U, 0U, ARM_MPU_REGION_SIZE_1MB) },
    /* Region 4: [0x10200000 - 0x1021FFFF], Instruction access, Privileged data access, Normal, Outer and inner
       non-cacheable, Shared */
    { ARM_MPU_RBAR(4U, 0x10200000U), ARM_MPU_RASR(0U, ARM_MPU_AP_PRIV, 1U, 1U, 0U, 0U, 0U, ARM_MPU_REGION_SIZE_128KB) },
    /* Region 5: [0x20000000 - 0x2001FFFF], Instruction access, Full data access, Normal, Outer and inner write-back,
       write and read allocate, Non-shared */
    { ARM_MPU_RBAR(5U, 0x20000000U), ARM_MPU_RASR(0U, ARM_MPU_AP_FULL, 1U, 0U, 1U, 1U, 0U, ARM_MPU_REGION_SIZE_128KB) },
    /* Region 6: [0x40000000 - 0x5FFFFFFF], No instruction access, Full data access, Device, Non-shared */
    { ARM_MPU_RBAR(6U, 0x40000000U), ARM_MPU_RASR(1U, ARM_MPU_AP_FULL, 2U, 0U, 0U, 0U, 0U, ARM_MPU_REGION_SIZE_512MB) }
#elif defined(BOARD_USE_CPU2)
    /* Add execute-never and inaccessible region to cover all unmapped memory. Refer to Arm errata 1013783 for more
       details. */
    /* Region 0: [0x00000000 - 0xFFFFFFFF], No instruction access, No data access */
    { ARM_MPU_RBAR(0U, 0x00000000U), ARM_MPU_RASR(1U, ARM_MPU_AP_NONE, 0U, 0U, 0U, 0U, 0U, ARM_MPU_REGION_SIZE_4GB) },
    /* Region 1: [0x00000000 - 0x0001FFFF], Instruction access, Full data access, Normal, Outer and inner write-back,
       write and read allocate, Non-shared */
    { ARM_MPU_RBAR(1U, 0x00000000U), ARM_MPU_RASR(0U, ARM_MPU_AP_FULL, 1U, 0U, 1U, 1U, 0U, ARM_MPU_REGION_SIZE_128KB) },
    /* Region 2: [0x00200000 - 0x0021FFFF], Instruction access, Full data access, Normal, Outer and inner non-cacheable,
       Shared */
    { ARM_MPU_RBAR(2U, 0x00200000U), ARM_MPU_RASR(0U, ARM_MPU_AP_FULL, 1U, 1U, 0U, 0U, 0U, ARM_MPU_REGION_SIZE_128KB) },
    /* Region 3: [0x10200000 - 0x1021FFFF], Instruction access, Privileged data access, Normal, Outer and inner
       non-cacheable, Shared */
    { ARM_MPU_RBAR(3U, 0x10200000U), ARM_MPU_RASR(0U, ARM_MPU_AP_PRIV, 1U, 1U, 0U, 0U, 0U, ARM_MPU_REGION_SIZE_128KB) },
    /* Region 4: [0x10300000 - 0x103FFFFF], Instruction access, Full data access, Normal, Outer and inner write-through,
       Non-shared */
    { ARM_MPU_RBAR(4U, 0x10300000U), ARM_MPU_RASR(0U, ARM_MPU_AP_FULL, 0U, 0U, 1U, 0U, 0U, ARM_MPU_REGION_SIZE_1MB) },
    /* Region 5: [0x20000000 - 0x2001FFFF], Instruction access, Full data access, Normal, Outer and inner write-back,
       write and read allocate, Non-shared */
    { ARM_MPU_RBAR(5U, 0x20000000U), ARM_MPU_RASR(0U, ARM_MPU_AP_FULL, 1U, 0U, 1U, 1U, 0U, ARM_MPU_REGION_SIZE_128KB) },
    /* Region 6: [0x40000000 - 0x5FFFFFFF], No instruction access, Full data access, Device, Non-shared */
    { ARM_MPU_RBAR(6U, 0x40000000U), ARM_MPU_RASR(1U, ARM_MPU_AP_FULL, 2U, 0U, 0U, 0U, 0U, ARM_MPU_REGION_SIZE_512MB) }
#endif
};

/*******************************************************************************
 * Codes
 ******************************************************************************/
void BOARD_init(void)
{
    BOARD_clockConfig();

    BOARD_mpuConfig();

#if !(defined(DEBUG_CONSOLE) && (DEBUG_CONSOLE == DEBUG_CONSOLE_DISABLE))
    BOARD_debugConsoleInit();
#endif

#if BOARD_CONFIG_CPU2
    BOARD_initForCPU2();
#endif
}

void BOARD_mpuConfig(void)
{
    /* Disable Cache */
#if defined(__ICACHE_PRESENT) && (__ICACHE_PRESENT == 1U)
    SCB_DisableICache();
#endif

    /* Disable MPU */
    ARM_MPU_Disable();

    /* Configure MPU */
    ARM_MPU_Load(s_mpuRegions, ARRAY_SIZE(s_mpuRegions));

    /* Enable MPU with the default memory map */
    ARM_MPU_Enable(MPU_CTRL_PRIVDEFENA_Msk);

    /* Enable Cache */
#if defined(__ICACHE_PRESENT) && (__ICACHE_PRESENT == 1U)
    SCB_EnableICache();
#endif
}

void BOARD_debugConsoleInit(void)
{
#if defined(BOARD_USE_CPU1) && BOARD_USE_CPU1
    BOARD_uartPinConfig((UART_Type *)BOARD_DEBUG_CONSOLE_BASE_CPU1);
    SYSCTRL_selectCPUForPeripheral(BOARD_DEBUG_CONSOLE_SYSCTL_PERIPH_CPUSEL_CPU1, kSYSCTRL_CPUSEL_CPU1);
#endif

    /* Enable the clock */
    SYSCTRL_enablePeripheral(BOARD_DEBUG_CONSOLE_SYSCTL_PERIPH_CLK);

    /* Debug console initialization */
    DEBUG_CONSOLE_Config_t config = {
        .type        = kDEBUG_CONSOLE_TYPE_UART,
        .base        = BOARD_DEBUG_CONSOLE_BASE,
        .baudRate    = BOARD_DEBUG_CONSOLE_BAUDRATE,
        .periphClock = BOARD_DEBUG_CONSOLE_CLOCK,
    };
    status_t status = DEBUG_CONSOLE_init(&config);
    if (status != kSTATUS_SUCCESS)
    {
        while (1)
        {
            ;
        }
    }
}

void BOARD_debugConsoleDeinit(void)
{
    (void)DEBUG_CONSOLE_deinit();
}

#if defined(BOARD_CONFIG_CPU2)
void BOARD_initForCPU2(void)
{
    BOARD_clockConfigForCPU2();

#if !(defined(DEBUG_CONSOLE) && (DEBUG_CONSOLE == DEBUG_CONSOLE_DISABLE))
    BOARD_debugConsoleInitForCPU2();
#endif
}

void BOARD_debugConsoleInitForCPU2(void)
{
    /* Config Uart for CPU2 debug console */
    BOARD_uartPinConfig((UART_Type *)BOARD_DEBUG_CONSOLE_BASE_CPU2);
    SYSCTRL_selectCPUForPeripheral(BOARD_DEBUG_CONSOLE_SYSCTL_PERIPH_CPUSEL_CPU2, kSYSCTRL_CPUSEL_CPU2);

    /* The left initialization will be done by CPU2 */
}

void BOARD_uartAssign2CPU2(UART_Type *base)
{
    SYSCTRL_PeripheralCpusel_t peri;
    if (base == UARTA)
    {
        peri = kSYSCTL_PERIPH_CPUSEL_UARTA;
    }
    else if (base == UARTB)
    {
        peri = kSYSCTL_PERIPH_CPUSEL_UARTB;
    }
    else if (base == UARTC)
    {
        peri = kSYSCTL_PERIPH_CPUSEL_UARTC;
    }
    else if (base == UARTD)
    {
        peri = kSYSCTL_PERIPH_CPUSEL_UARTD;
    }
    else
    {
        return;
    }

    SYSCTRL_selectCPUForPeripheral(peri, kSYSCTRL_CPUSEL_CPU2);
}

void BOARD_ecapAssign2CPU2(ECAP_Type *base)
{
    SYSCTRL_PeripheralCpusel_t peri;
    if (base == ECAP1)
    {
        peri = kSYSCTL_PERIPH_CPUSEL_ECAP1;
    }
    else if (base == ECAP2)
    {
        peri = kSYSCTL_PERIPH_CPUSEL_ECAP2;
    }
    else if (base == ECAP3)
    {
        peri = kSYSCTL_PERIPH_CPUSEL_ECAP3;
    }
    else if (base == ECAP4)
    {
        peri = kSYSCTL_PERIPH_CPUSEL_ECAP4;
    }
    else if (base == ECAP5)
    {
        peri = kSYSCTL_PERIPH_CPUSEL_ECAP5;
    }
    else if (base == ECAP6)
    {
        peri = kSYSCTL_PERIPH_CPUSEL_ECAP6;
    }
    else
    {
        return;
    }

    SYSCTRL_selectCPUForPeripheral(peri, kSYSCTRL_CPUSEL_CPU2);

}

void BOARD_i2cAssign2CPU2(I2C_Type *base)
{
    SYSCTRL_PeripheralCpusel_t peri;
    if (base == I2CA)
    {
        peri = kSYSCTL_PERIPH_CPUSEL_I2CA;
    }
    else if (base == I2CB)
    {
        peri = kSYSCTL_PERIPH_CPUSEL_I2CB;
    }
    else
    {
        return;
    }
    SYSCTRL_selectCPUForPeripheral(peri, kSYSCTRL_CPUSEL_CPU2);
}

void BOARD_pmbusAssign2CPU2(PMBUS_Type *base)
{
    SYSCTRL_PeripheralCpusel_t peri;
    if (base == PMBUSA)
    {
        peri = kSYSCTL_PERIPH_CPUSEL_PMBUSA;
    }
    else
    {
        return;
    }
    SYSCTRL_selectCPUForPeripheral(peri, kSYSCTRL_CPUSEL_CPU2);
}
void BOARD_epwmAssign2CPU2(EPWM_REGS_Type *base)
{
    SYSCTRL_PeripheralCpusel_t peri;
    if (base == EPWM1)
    {
        peri = kSYSCTL_PERIPH_CPUSEL_EPWM1;
    }
    else if (base == EPWM2)
    {
        peri = kSYSCTL_PERIPH_CPUSEL_EPWM2;
    }
    else if (base == EPWM3)
    {
        peri = kSYSCTL_PERIPH_CPUSEL_EPWM3;
    }
    else if (base == EPWM4)
    {
        peri = kSYSCTL_PERIPH_CPUSEL_EPWM4;
    }
    else if (base == EPWM5)
    {
        peri = kSYSCTL_PERIPH_CPUSEL_EPWM5;
    }
    else if (base == EPWM6)
    {
        peri = kSYSCTL_PERIPH_CPUSEL_EPWM6;
    }
    else if (base == EPWM7)
    {
        peri = kSYSCTL_PERIPH_CPUSEL_EPWM7;
    }
    else if (base == EPWM8)
    {
        peri = kSYSCTL_PERIPH_CPUSEL_EPWM8;
    }
    else if (base == EPWM9)
    {
        peri = kSYSCTL_PERIPH_CPUSEL_EPWM9;
    }
    else if (base == EPWM10)
    {
        peri = kSYSCTL_PERIPH_CPUSEL_EPWM10;
    }
    else if (base == EPWM11)
    {
        peri = kSYSCTL_PERIPH_CPUSEL_EPWM11;
    }
    else if (base == EPWM12)
    {
        peri = kSYSCTL_PERIPH_CPUSEL_EPWM12;
    }
    else
    {
        return;
    }

    SYSCTRL_selectCPUForPeripheral(peri, kSYSCTRL_CPUSEL_CPU2);
}

void BOARD_adcAssign2CPU2(ADC_Type *base)
{
    SYSCTRL_PeripheralCpusel_t peri;
    if (base == ADCA)
    {
        peri = kSYSCTL_PERIPH_CPUSEL_ADCA;
    }
    else if (base == ADCB)
    {
        peri = kSYSCTL_PERIPH_CPUSEL_ADCB;
    }
    else if (base == ADCC)
    {
        peri = kSYSCTL_PERIPH_CPUSEL_ADCC;
    }
    else if (base == ADCD)
    {
        peri = kSYSCTL_PERIPH_CPUSEL_ADCD;
    }
    else
    {
        return;
    }

    SYSCTRL_selectCPUForPeripheral(peri, kSYSCTRL_CPUSEL_CPU2);
}
#endif
