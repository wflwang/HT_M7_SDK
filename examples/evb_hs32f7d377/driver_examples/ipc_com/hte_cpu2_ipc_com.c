/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "hte_cpu2_ipc_com.h"
#include "clock_config.h"
#include "hte_cpu2_ipc.h"
#include "hte_sysctrl.h"

#define IPC_SYSCTRL_SOFTPRES0_REG       0x41001904
#define IPC_SYSCTRL_CPUSEL0_REG         0x410019AC
#define IPC_SYSCTRL_CANSRAMINIT_REG     0x41002924
#define IPC_SYSCTRL_CANSRAMINITDONE_REG 0x41002928

#define IPC_SYSCTRL_CRCCR_REG 0x41002544


bool IPC_com_setReg(uint32_t regAddr, uint32_t val)
{
    volatile bool     remote_flag  = false;
    volatile uint32_t remote_reply = 0x0;

    if (IPC_sendCommand(kHAL_IPC0, IPC_COM_WRITE, regAddr, val) == false)
    {
        return false;
    }

    /*get remote flag have been set*/
    while (remote_flag == false)
    {
        remote_flag = IPC_isFlagBusyLtoR(kHAL_IPC0);
    }
    /*wait remote ok reply*/
    IPC_waitForAck(kHAL_IPC0);

    remote_reply = IPC_getResponse();
    if (remote_reply == IPC_COM_DONE)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool IPC_com_getReg(uint32_t regAddr, uint32_t *val)
{
    volatile bool remote_flag = false;
    uint32_t      dat         = 0x0;

    if (IPC_sendCommand(kHAL_IPC0, IPC_COM_READ, regAddr, dat) == false)
    {
        return false;
    }

    /*get remote flag have been set*/
    while (remote_flag == false)
    {
        remote_flag = IPC_isFlagBusyLtoR(kHAL_IPC0);
    }
    /*wait remote ok reply*/
    IPC_waitForAck(kHAL_IPC0);

    *val = IPC_getResponse();

    return true;
}

bool IPC_com_getClkParam(void)
{
    volatile bool  remote_flag = false;
//    uint32_t      *srcAddr;

    if (IPC_sendCommand(kHAL_IPC0, IPC_COM_CLK_PARAM, 0x0, 0x0) == false)
    {
//        MSG_ERR("IPC CPU SEND FAIL!\r\n");
        return false;
    }

    /*get remote flag have been set*/
    while (remote_flag == false)
    {
        remote_flag = IPC_isFlagBusyLtoR(kHAL_IPC0);
    }
    /*wait remote ok reply*/
    IPC_waitForAck(kHAL_IPC0);

 //   srcAddr = (uint32_t *)IPC_getResponse();
    BOARD_clockInfGet();

    return true;
}

void IPC_com_resetPeripheral(IPC_SYSCTRL_PeripheralSOFTPRES_t peripheral)
{
    uint32_t regIndex;
    uint32_t bitIndex;
    uint32_t regAddr = 0;
    uint32_t regVal = 0;


    // Decode the peripheral variable.
    regIndex = ((uint32_t)peripheral & (uint32_t)IPC_SYSCTL_PERIPH_REG_M) << IPC_SYSCTL_PERIPH_REG_S;
    bitIndex = ((uint32_t)peripheral & (uint32_t)IPC_SYSCTL_PERIPH_BIT_M) >> IPC_SYSCTL_PERIPH_BIT_S;

    regAddr = (uint32_t)(IPC_SYSCTRL_SOFTPRES0_REG + regIndex);

    if (IPC_com_getReg(regAddr, &regVal))
    {
        regVal |= (0x01UL << bitIndex);
        IPC_com_setReg(regAddr, regVal);
        regVal &= ~(0x01UL << bitIndex);
        IPC_com_setReg(regAddr, regVal);
    }
}

void IPC_com_selectCPUForPeripheral(IPC_SYSCTRL_PeripheralCpusel_t peripheral, IPC_SYSCTRL_CpuSel_t cpuSel)
{
    uint32_t regIndex;
    uint32_t bitIndex;
    uint32_t regAddr = 0;
    uint32_t regVal = 0;


    // Decode the peripheral variable.
    regIndex = ((uint32_t)peripheral & (uint32_t)IPC_SYSCTL_PERIPH_REG_M) << IPC_SYSCTL_PERIPH_REG_S;
    bitIndex = ((uint32_t)peripheral & (uint32_t)IPC_SYSCTL_PERIPH_BIT_M) >> IPC_SYSCTL_PERIPH_BIT_S;

    regAddr = (uint32_t)(IPC_SYSCTRL_CPUSEL0_REG + regIndex);

    if (IPC_com_getReg(regAddr, &regVal))
    {
        if (cpuSel == kIPC_SYSCTRL_CPUSEL_CPU1)
        {
            regVal &= ~(1U << bitIndex);
        }
        else
        {
            regVal |= 1U << bitIndex;
        }
        IPC_com_setReg(regAddr, regVal);
    }
}

void IPC_com_SYSCTRL_enablePeripheral(IPC_SYSCTRL_PeripheralPclockCr_t peripheral)
{
    uint32_t           regIndex;
    uint32_t           bitIndex;
    uint32_t regAddr = 0;
    uint32_t regVal = 0;

    // Decode the peripheral variable.
    regIndex = ((uint32_t)peripheral & (uint32_t)SYSCTL_PERIPH_REG_M) << SYSCTL_PERIPH_REG_S;
    bitIndex = ((uint32_t)peripheral & (uint32_t)SYSCTL_PERIPH_BIT_M) >> SYSCTL_PERIPH_BIT_S;

    regAddr = (uint32_t)(CPU_SYS_REGS_BASE + SYSC_PCLKCR0_OFFSET + regIndex);

    if (IPC_com_getReg(regAddr, &regVal))
    {

        regVal |= (0x01UL << bitIndex);

        IPC_com_setReg(regAddr, regVal);
    }
}


void IPC_com_SYSCTRL_initCANSram(void)
{
    uint32_t regAddr = 0;
    uint32_t regVal = 0;

    regAddr = (uint32_t)IPC_SYSCTRL_CANSRAMINIT_REG;

    if (IPC_com_getReg(regAddr, &regVal))
    {

        regVal |= 0x1;

        IPC_com_setReg(regAddr, regVal);
    }
}

bool IPC_com_SYSCTRL_getCANSramInitDone(void)
{
    uint32_t regAddr = 0;
    uint32_t regVal = 0;

    regAddr = (uint32_t)IPC_SYSCTRL_CANSRAMINITDONE_REG;

    if (IPC_com_getReg(regAddr, &regVal))
    {

        if ((regVal&0x1) == 1)
            return true;
        else
            return false;
    }
    return false;
}

void IPC_com_SYSCTRL_enableCRC(void)
{
    uint32_t regAddr = 0;
    uint32_t regVal = 0;

    regAddr = (uint32_t)IPC_SYSCTRL_CRCCR_REG;

    if (IPC_com_getReg(regAddr, &regVal))
    {
        regVal |= 0x01U;

        IPC_com_setReg(regAddr, regVal);
    }
}


#if 1

void IPC_com_GPIO_setMasterCore(uint32_t pin, GPIO_Core_t core)
{
    GPIO_Port_t port      = GPIO_getPort(pin);
    uint32_t    pinPerReg = GPIO_CTRL_PIN_COUNT_PER_PORT / GPIO_CTRL_CSEL_CSEL1_Pos;
    uint32_t    cselIndex = (pin % GPIO_CTRL_PIN_COUNT_PER_PORT) / pinPerReg;
    uint32_t    cselShift = ((pin % GPIO_CTRL_PIN_COUNT_PER_PORT) % pinPerReg) * GPIO_CTRL_CSEL_CSEL1_Pos;
    uint32_t regAddr = 0;
    uint32_t regVal = 0;

    regAddr = (uint32_t)&GPIO_CTRL->PORT[port].CSEL[cselIndex];

    if (IPC_com_getReg(regAddr, &regVal))
    {
        regVal &= ~(GPIO_CTRL_CSEL_CSEL0_Msk << cselShift);
        regVal |= (core & GPIO_CTRL_CSEL_CSEL0_Msk) << cselShift;

        IPC_com_setReg(regAddr, regVal);
    }
}

void IPC_com_GPIO_setQualificationMode(uint32_t pin, GPIO_QualificationMode_t qualification)
{
    GPIO_Port_t port      = GPIO_getPort(pin);
    uint32_t    pinPerReg = GPIO_CTRL_PIN_COUNT_PER_PORT / GPIO_CTRL_QSEL_QSEL1_Pos;
    uint32_t    qselIndex = (pin % GPIO_CTRL_PIN_COUNT_PER_PORT) / pinPerReg;
    uint32_t    qselShift = ((pin % GPIO_CTRL_PIN_COUNT_PER_PORT) % pinPerReg) * GPIO_CTRL_QSEL_QSEL1_Pos;
    uint32_t regAddr = 0;
    uint32_t regVal = 0;

    regAddr = (uint32_t)&GPIO_CTRL->PORT[port].QSEL[qselIndex];

    if (IPC_com_getReg(regAddr, &regVal))
    {
        regVal &=  ~(GPIO_CTRL_QSEL_QSEL0_Msk << qselShift);
        regVal |= (qualification & GPIO_CTRL_QSEL_QSEL0_Msk) << qselShift;

        IPC_com_setReg(regAddr, regVal);
    }
}

GPIO_QualificationMode_t IPC_com_GPIO_getQualificationMode(uint32_t pin)
{
    GPIO_Port_t port      = GPIO_getPort(pin);
    uint32_t    pinPerReg = GPIO_CTRL_PIN_COUNT_PER_PORT / GPIO_CTRL_QSEL_QSEL1_Pos;
    uint32_t    qselIndex = (pin % GPIO_CTRL_PIN_COUNT_PER_PORT) / pinPerReg;
    uint32_t    qselShift = ((pin % GPIO_CTRL_PIN_COUNT_PER_PORT) % pinPerReg) * GPIO_CTRL_QSEL_QSEL1_Pos;
    uint32_t regAddr = 0;
    uint32_t regVal = 0;

    regAddr = (uint32_t)&GPIO_CTRL->PORT[port].QSEL[qselIndex];

    IPC_com_getReg(regAddr, &regVal);

    return (GPIO_QualificationMode_t)((regVal >> qselShift) & GPIO_CTRL_QSEL_QSEL0_Msk);
}

void IPC_com_GPIO_setQualificationPeriod(uint32_t pin, uint32_t divider)
{
    GPIO_Port_t port = GPIO_getPort(pin);
    uint32_t    qualShift =
        (pin % GPIO_CTRL_PIN_COUNT_PER_PORT) / GPIO_CTRL_PIN_COUNT_PER_QUAL * GPIO_CTRL_CTRL_QUALPRD1_Pos;
    uint32_t dividerLow  = (divider & GPIO_CTRL_CTRL_QUALPRD0_Msk);
    uint32_t dividerHigh = ((divider >> GPIO_CTRL_CTRL_QUALPRD1_Pos) & GPIO_CTRL_ECTRL_QUALPRD0_Msk);
    uint32_t regAddr = 0,regAddr2 = 0;
    uint32_t regVal = 0,regVal2 = 0;

    regAddr = (uint32_t)&GPIO_CTRL->PORT[port].CTRL;
    regAddr2 = (uint32_t)&GPIO_CTRL->PORT[port].ECTRL;

    if (IPC_com_getReg(regAddr, &regVal) && IPC_com_getReg(regAddr2, &regVal2))
    {
        regVal &= ~(GPIO_CTRL_CTRL_QUALPRD0_Msk << qualShift);
        regVal2 &= ~(GPIO_CTRL_ECTRL_QUALPRD0_Msk << qualShift);
            
        regVal  |= dividerLow << qualShift;
        regVal2 |= dividerHigh << qualShift;
        
        IPC_com_setReg(regAddr, regVal);
        IPC_com_setReg(regAddr2, regVal2);
    }
}

void IPC_com_GPIO_setDirectionMode(uint32_t pin, GPIO_Direction_t dir)
{
    GPIO_Port_t port    = GPIO_getPort(pin);
    uint32_t    pinMask = 0x1U << (pin % GPIO_CTRL_PIN_COUNT_PER_PORT);
    uint32_t regAddr = 0;
    uint32_t regVal = 0;

    regAddr = (uint32_t)&GPIO_CTRL->PORT[port].DIR;

    if (IPC_com_getReg(regAddr, &regVal))
    {
        
        if (dir == kGPIO_DIR_INPUT)
        {
            regVal &= ~pinMask;
        }
        else
        {
            regVal |= pinMask;
        }
        
        IPC_com_setReg(regAddr, regVal);
    }
}

GPIO_Direction_t IPC_com_GPIO_getDirectionMode(uint32_t pin)
{
    GPIO_Port_t port    = GPIO_getPort(pin);
    uint32_t    pinMask = 0x1U << (pin % GPIO_CTRL_PIN_COUNT_PER_PORT);
    uint32_t regAddr = 0;
    uint32_t regVal = 0;

    regAddr = (uint32_t)&GPIO_CTRL->PORT[port].DIR;

    IPC_com_getReg(regAddr, &regVal);

    return (regVal & pinMask) ? kGPIO_DIR_OUTPUT : kGPIO_DIR_INPUT;
}

void IPC_com_GPIO_setPinConfig(uint32_t config)
{
    uint32_t    pin       = GPIO_PINCONFIG_PIN_Get(config);
    GPIO_Port_t port      = GPIO_getPort(pin);
    uint32_t    pinPerReg = GPIO_CTRL_PIN_COUNT_PER_PORT / GPIO_CTRL_MUX_MUX1_Pos;
    uint32_t    muxIndex  = (pin % GPIO_CTRL_PIN_COUNT_PER_PORT) / pinPerReg;
    uint32_t    muxShift  = ((pin % GPIO_CTRL_PIN_COUNT_PER_PORT) % pinPerReg) * GPIO_CTRL_MUX_MUX1_Pos;

    uint32_t mux  = GPIO_PINCONFIG_MUX_Get(config);
    uint32_t gmux = GPIO_PINCONFIG_GMUX_Get(config);

    uint32_t regAddr = 0,regAddr2 = 0;
    uint32_t regVal = 0,regVal2 = 0;

    regAddr = (uint32_t)&GPIO_CTRL->PORT[port].MUX[muxIndex];
    regAddr2 = (uint32_t)&GPIO_CTRL->PORT[port].GMUX[muxIndex];

    if (IPC_com_getReg(regAddr, &regVal) && IPC_com_getReg(regAddr2, &regVal2))
    {
        regVal = (regVal & (~(GPIO_CTRL_MUX_MUX0_Msk << muxShift))) | (mux << muxShift);
        regVal2 = (regVal2 & (~(GPIO_CTRL_GMUX_GMUX0_Msk << muxShift))) | (gmux << muxShift);

        /* GMUX must be configured prior to MUX to avoid intermediate peripheral selects */
        IPC_com_setReg(regAddr2, regVal2);
        IPC_com_setReg(regAddr, regVal);
    }
}

void IPC_com_GPIO_setPadConfig(uint32_t pin, uint32_t config)
{
    GPIO_Port_t port    = GPIO_getPort(pin);
    uint32_t    pinMask = 0x1U << (pin % GPIO_CTRL_PIN_COUNT_PER_PORT);
    uint32_t regAddr = 0;
    uint32_t regVal = 0;

    if (config & kGPIO_PADCONFIG_PULLUP)
    {
        regAddr = (uint32_t)&GPIO_CTRL->PORT[port].PUD;
        
        if (IPC_com_getReg(regAddr, &regVal))
        {
            regVal &= ~pinMask;
            IPC_com_setReg(regAddr, regVal);
        }
    }
    else
    {
        regAddr = (uint32_t)&GPIO_CTRL->PORT[port].PUD;
        
        if (IPC_com_getReg(regAddr, &regVal))
        {
            regVal |= pinMask;
            IPC_com_setReg(regAddr, regVal);
        }
    }

    if (config & kGPIO_PADCONFIG_INPUT_INVERT)
    {
        regAddr = (uint32_t)&GPIO_CTRL->PORT[port].INV;
        
        if (IPC_com_getReg(regAddr, &regVal))
        {
            regVal |= pinMask;
            IPC_com_setReg(regAddr, regVal);
        }
    }
    else
    {
        regAddr = (uint32_t)&GPIO_CTRL->PORT[port].INV;
        
        if (IPC_com_getReg(regAddr, &regVal))
        {
            regVal &= ~pinMask;
            IPC_com_setReg(regAddr, regVal);
        }
    }

    if (config & kGPIO_PADCONFIG_PULLDOWN)
    {
        regAddr = (uint32_t)&GPIO_CTRL->PORT[port].PDD;
        
        if (IPC_com_getReg(regAddr, &regVal))
        {
            regVal &= ~pinMask;
            IPC_com_setReg(regAddr, regVal);
        }
    }
    else
    {
        regAddr = (uint32_t)&GPIO_CTRL->PORT[port].PDD;
        
        if (IPC_com_getReg(regAddr, &regVal))
        {
            regVal |= pinMask;
            IPC_com_setReg(regAddr, regVal);
        }
    }

    if (config & kGPIO_PADCONFIG_NO_FORCE_INPUT)
    {
        regAddr = (uint32_t)&GPIO_CTRL->PORT[port].FID;
        
        if (IPC_com_getReg(regAddr, &regVal))
        {
            regVal |= pinMask;
            IPC_com_setReg(regAddr, regVal);
        }
    }
    else
    {
        regAddr = (uint32_t)&GPIO_CTRL->PORT[port].FID;
        
        if (IPC_com_getReg(regAddr, &regVal))
        {
            regVal &= ~pinMask;
            IPC_com_setReg(regAddr, regVal);
        }
    }

    if (config & kGPIO_PADCONFIG_SCHMITT)
    {
        regAddr = (uint32_t)&GPIO_CTRL->PORT[port].ST;
        
        if (IPC_com_getReg(regAddr, &regVal))
        {
            regVal |= pinMask;
            IPC_com_setReg(regAddr, regVal);
        }
    }
    else
    {
        regAddr = (uint32_t)&GPIO_CTRL->PORT[port].ST;
        
        if (IPC_com_getReg(regAddr, &regVal))
        {
            regVal &= ~pinMask;
            IPC_com_setReg(regAddr, regVal);
        }
    }

    if (config & kGPIO_PADCONFIG_LOOPBACK)
    {
        regAddr = (uint32_t)&GPIO_CTRL->PORT[port].LPB;
        
        if (IPC_com_getReg(regAddr, &regVal))
        {
            regVal |= pinMask;
            IPC_com_setReg(regAddr, regVal);
        }
    }
    else
    {
        regAddr = (uint32_t)&GPIO_CTRL->PORT[port].LPB;
        
        if (IPC_com_getReg(regAddr, &regVal))
        {
            regVal &= ~pinMask;
            IPC_com_setReg(regAddr, regVal);
        }
    }
}

uint32_t IPC_com_GPIO_getPadConfig(uint32_t pin)
{
    GPIO_Port_t port      = GPIO_getPort(pin);
    uint32_t    pinMask   = 0x1U << (pin % GPIO_CTRL_PIN_COUNT_PER_PORT);
    uint32_t    padConfig = 0U;
    uint32_t regAddr = 0;
    uint32_t regVal = 0;

    regAddr = (uint32_t)&GPIO_CTRL->PORT[port].PUD;
    IPC_com_getReg(regAddr, &regVal);

    if (!(regVal & pinMask))
    {
        padConfig |= kGPIO_PADCONFIG_PULLUP;
    }

    regAddr = (uint32_t)&GPIO_CTRL->PORT[port].INV;
    IPC_com_getReg(regAddr, &regVal);

    if (regVal & pinMask)
    {
        padConfig |= kGPIO_PADCONFIG_INPUT_INVERT;
    }

    regAddr = (uint32_t)&GPIO_CTRL->PORT[port].PDD;
    IPC_com_getReg(regAddr, &regVal);

    if (!(regVal & pinMask))
    {
        padConfig |= kGPIO_PADCONFIG_PULLDOWN;
    }

    regAddr = (uint32_t)&GPIO_CTRL->PORT[port].FID;
    IPC_com_getReg(regAddr, &regVal);

    if (regVal & pinMask)
    {
        padConfig |= kGPIO_PADCONFIG_NO_FORCE_INPUT;
    }

    regAddr = (uint32_t)&GPIO_CTRL->PORT[port].ST;
    IPC_com_getReg(regAddr, &regVal);

    if (regVal & pinMask)
    {
        padConfig |= kGPIO_PADCONFIG_SCHMITT;
    }

    regAddr = (uint32_t)&GPIO_CTRL->PORT[port].LPB;
    IPC_com_getReg(regAddr, &regVal);

    if (regVal & pinMask)
    {
        padConfig |= kGPIO_PADCONFIG_LOOPBACK;
    }

    return padConfig;
}

void IPC_com_GPIO_setDriverStrength(uint32_t pin, GPIO_DriverStrength_t str)
{
    GPIO_Port_t port      = GPIO_getPort(pin);
    uint32_t    pinPerReg = GPIO_CTRL_PIN_COUNT_PER_PORT / GPIO_CTRL_DS_DS1_Pos;
    uint32_t    dsIndex   = (pin % GPIO_CTRL_PIN_COUNT_PER_PORT) / pinPerReg;
    uint32_t    dsShift   = ((pin % GPIO_CTRL_PIN_COUNT_PER_PORT) % pinPerReg) * GPIO_CTRL_DS_DS1_Pos;

    uint32_t regAddr = 0;
    uint32_t regVal = 0;

    regAddr = (uint32_t)&GPIO_CTRL->PORT[port].DS[dsIndex];

    if (IPC_com_getReg(regAddr, &regVal))
    {
        regVal &=  ~(GPIO_CTRL_DS_DS0_Msk << dsShift);
        regVal |= str << dsShift;

        IPC_com_setReg(regAddr, regVal);
    }
}

GPIO_DriverStrength_t IPC_com_GPIO_getDriverStrength(uint32_t pin)
{
    GPIO_Port_t port      = GPIO_getPort(pin);
    uint32_t    pinPerReg = GPIO_CTRL_PIN_COUNT_PER_PORT / GPIO_CTRL_DS_DS1_Pos;
    uint32_t    dsIndex   = (pin % GPIO_CTRL_PIN_COUNT_PER_PORT) / pinPerReg;
    uint32_t    dsShift   = ((pin % GPIO_CTRL_PIN_COUNT_PER_PORT) % pinPerReg) * GPIO_CTRL_DS_DS1_Pos;

    uint32_t regAddr = 0;
    uint32_t regVal = 0;

    regAddr = (uint32_t)&GPIO_CTRL->PORT[port].DS[dsIndex];

    IPC_com_getReg(regAddr, &regVal);

    return (GPIO_DriverStrength_t)((regVal >> dsShift) & GPIO_CTRL_DS_DS0_Msk);
}

void IPC_com_XBAR_enableEPWMMux(EPWM_XBAR_Type *base, XBAR_TripNum_t trip, uint32_t muxes)
{
    assert(base);

    uint32_t regAddr = 0;
    uint32_t regVal = 0;

    regAddr = (uint32_t)&base->TRIPMUXENABLE[trip];

    if (IPC_com_getReg(regAddr, &regVal))
    {
        //MSG_INFO("IPC get addr:0x%x, val: 0x%x !\r\n", regAddr, regVal);
        regVal |= muxes;
        IPC_com_setReg(regAddr, regVal);
    }
}

void IPC_com_XBAR_setInputPin(INPUT_XBAR_Type *base, XBAR_InputNum_t input, uint32_t pin)
{
    assert(base);
    assert(pin < HTE_FEATURE_GPIO_PIN_COUNT);

    uint32_t regAddr = 0;
    uint32_t regVal = 0;

    regAddr = (uint32_t)&base->INPUTSELECT[input];

    if (IPC_com_getReg(regAddr, &regVal))
    {
        //MSG_INFO("IPC get addr:0x%x, val: 0x%x !\r\n", regAddr, regVal);
        regVal = pin;
        IPC_com_setReg(regAddr, regVal);
    }
}

void IPC_com_XBAR_setEPWMMuxConfig(EPWM_XBAR_Type *base, XBAR_TripNum_t trip, XBAR_EPWMMuxConfig_t muxConfig)
{
    assert(base);

    uint32_t           index = XBAR_MUXCONFIG_INDEX_Get(muxConfig.U);
    uint32_t           mux, mask;
    uint32_t regAddr = 0;
    uint32_t regVal = 0;


    if (index < XBAR_EPWM_MUX_PER_WORD)
    {
        mux    = XBAR_MUXCONFIG_MUX_Get(muxConfig.U) << (index * 2U);
        mask   = 0x3U << (index * 2U);
        regAddr = (uint32_t)&base->TRIPMUX[trip].MUX0TO15CFG;
    }
    else
    {
        mux    = XBAR_MUXCONFIG_MUX_Get(muxConfig.U) << ((index - XBAR_EPWM_MUX_PER_WORD) * 2U);
        mask   = 0x3U << ((index - XBAR_EPWM_MUX_PER_WORD) * 2U);
        regAddr = (uint32_t)&base->TRIPMUX[trip].MUX16TO31CFG;
    }

    if (IPC_com_getReg(regAddr, &regVal))
    {
        //MSG_INFO("IPC get addr:0x%x, val: 0x%x !\r\n", regAddr, regVal);
        regVal = (regVal & (~mask)) | mux;
    }
    IPC_com_setReg(regAddr, regVal);
    
}

#endif
