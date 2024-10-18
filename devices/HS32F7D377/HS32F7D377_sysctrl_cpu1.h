/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


/*!
 * \file   HS32F7D377_sysctrl_cpu1.h
 * \brief  HS32F7D377 SYSCTRL_CPU1 register file
 * \version V1.0_20230807
 */

#ifndef HS32F7D377_SYSCTRL_CPU1_H
#define HS32F7D377_SYSCTRL_CPU1_H

/*!
 * \addtogroup   HS32F7D377_SYSCTRL_CPU1_REGISTER HS32F7D377 SYSCTRL_CPU1 Register
 * \ingroup HS32F7D377_REGISTER
 *
 * \brief  SYSCTRL_CPU1 register layout, bitfield and address definitions
 *
 * @{
 */

/*!
 * \name SYSCTRL_CPU1 Register Layout
 *
 *
 * @{
 */

/*! \brief CPUTIMER_REGS register */
typedef struct {
    union
    {
        __IOM uint32_t TIM;  /*!< 0x00000000 */ 
       
        struct
        {
            __IOM uint32_t LSW                       : 16;     /*!< [15:0] : CPU-Timer Counter Registers                                     <br>  The TIM register holds the low 16 bits of the current 32-bit count of the timer. */
            __IOM uint32_t MSW                       : 16;     /*!< [31:16] : CPU-Timer Counter Registers                                     <br>  The TIMH register holds the high 16 bits of the current 32-bit count of the timer. */
        } TIMb;
    };

    union
    {
        __IOM uint32_t PRD;  /*!< 0x00000004 */ 
       
        struct
        {
            __IOM uint32_t LSW                       : 16;     /*!< [15:0] : CPU-Timer Period Registers                                      <br>  The PRD register holds the low 16 bits of the 32-bit period. */
            __IOM uint32_t MSW                       : 16;     /*!< [31:16] : CPU-Timer Period Registers                                      <br>  The PRDH register holds the high 16 bits of the 32-bit period. */
        } PRDb;
    };

    union
    {
        __IOM uint32_t TCR;  /*!< 0x00000008 */ 
       
        struct
        {
                  uint32_t RSV_3                     : 3 ;     /*!< [2:0] : reserved. */
            __IOM uint32_t INTR_OP                   : 1 ;     /*!< [3:3] : Interrupt option. */
            __IOM uint32_t TSS                       : 1 ;     /*!< [4:4] : CPU-Timer stop status bit. */
            __IOM uint32_t TRB                       : 1 ;     /*!< [5:5] : Timer reload                                                    <br>  Reset type: SYSRSn                                              <br>  0h (R/W) = The TRB bit is always read as zero. */
                  uint32_t RSV_2                     : 4 ;     /*!< [9:6] : reserved. */
            __IOM uint32_t TIM_SOFT                  : 1 ;     /*!< [10:10] : If the FREE bit is set to 1, then, upon a software breakpoint, the timer continues to run (that is, free runs). */
            __IOM uint32_t FREE                      : 1 ;     /*!< [11:11] : If the FREE bit is set to 1, then, upon a software breakpoint, the timer continues to run. */
                  uint32_t RSV_1                     : 2 ;     /*!< [13:12] : reserved. */
            __IOM uint32_t TIE                       : 1 ;     /*!< [14:14] : CPU-Timer Interrupt Enable. */
            __IOM uint32_t TIF                       : 1 ;     /*!< [15:15] : CPU-Timer Overflow Flag. */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } TCRb;
    };

    union
    {
        __IOM uint16_t TPR;  /*!< 0x0000000c */ 
       
        struct
        {
            __IOM uint16_t TDDR                      : 8 ;     /*!< [7:0] : CPU-Timer Divide-Down. */
            __IM  uint16_t PSC                       : 8 ;     /*!< [15:8] : CPU-Timer Prescale Counter. */
        } TPRb;
    };

    union
    {
        __IOM uint16_t TPRH;  /*!< 0x0000000e */ 
       
        struct
        {
            __IOM uint16_t TDDRH                     : 8 ;     /*!< [7:0] : See description of TIMERxTPR. */
            __IM  uint16_t PSCH                      : 8 ;     /*!< [15:8] : See description of TIMERxTPR. */
        } TPRHb;
    };

    uint8_t    RSV_0X10[16];   /*!< 0x00000010~0x0000001f : reserved */

    union
    {
        __IOM uint32_t TIMEX;  /*!< 0x00000020 */ 
       
        struct
        {
            __IOM uint32_t TIMEX                     : 32;     /*!< [31:0] : CPU-Timer Counter Registers high 32bit, extend to 64bit         <br>  Reset type: SYSRSn                                              <br>. */
        } TIMEXb;
    };

    union
    {
        __IOM uint32_t PRDEX;  /*!< 0x00000024 */ 
       
        struct
        {
            __IOM uint32_t PRDEX                     : 32;     /*!< [31:0] : CPU-Timer Period Registers high 32bit, extend to 64bit          <br>  Reset type: SYSRSn                                              <br>. */
        } PRDEXb;
    };
} CPUTIMER_REGS_Type;

/*! \brief WD_REGS register */
typedef struct {
    uint8_t    RSV_0XC00[82];   /*!< 0x00000c00~0x00000c51 : reserved */

    union
    {
        __IOM uint16_t WDCR;  /*!< 0x00000c52 */ 
       
        struct
        {
            __IOM uint16_t WDPS                      : 3 ;     /*!< [2:0] : These bits configure the watchdog counter clock (WDCLK) rate relative to INTOSC1/512:<br>  000 WDCLK = INTOSC1/512/1                                       <br>  001 WDCLK = INTOSC1/512/1                                       <br>  010 WDCLK = INTOSC1/512/2                                       <br>  011 WDCLK = INTOSC1/512/4                                       <br>  100 WDCLK = INTOSC1/512/8                                       <br>  101 WDCLK = INTOSC1/512/16                                      <br>  110 WDCLK = INTOSC1/512/32                                      <br>  111 WDCLK = INTOSC1/512/64                                      <br>  Reset type: IORSn                                               <br>. */
                  uint16_t RSV_0                     : 13;     /*!< [15:3] : reserved. */
        } WDCRb;
    };
} WD_REGS_Type;

/*! \brief NMI_INTRUPT_REGS register */
typedef struct {
    union
    {
        __IOM uint16_t NMICFG;  /*!< 0x00001000 */ 
       
        struct
        {
            __IOM uint16_t NMIE                      : 1 ;     /*!< [0:0] : When set to 1 any condition will generate an NMI interrupt to the C28 CPU and kick off the NMI watchdog counter. */
                  uint16_t RSV_0                     : 15;     /*!< [15:1] : reserved. */
        } NMICFGb;
    };

    union
    {
        __IM uint16_t NMIFLG;  /*!< 0x00001002 */ 
       
        struct
        {
            __IM  uint16_t NMIINT                    : 1 ;     /*!< [0:0] : NMI Interrupt Flag: This bit indicates if an NMI interrupt was generated. */
            __IM  uint16_t CLOCKFAIL                 : 1 ;     /*!< [1:1] : Clock Fail Interrupt Flag: These bits indicates if the CLOCKFAIL condition is latched. */
            __IM  uint16_t RAMUNCERR                 : 1 ;     /*!< [2:2] : RAM Uncorrectable Error NMI Flag: This bit indicates if an uncorrectable error occurred on a RAM access (by any master) and that condition is latched. */
            __IM  uint16_t FLUNCERR                  : 1 ;     /*!< [3:3] : Flash Uncorrectable Error NMI Flag: This bit indicates if an uncorrectable error occurred on a C28 Flash access and that condition is latched. */
                  uint16_t RSV_1                     : 4 ;     /*!< [7:4] : reserved. */
            __IM  uint16_t CLBNMI                    : 1 ;     /*!< [8:8] : Configurable Logic Block NMI Flag: This bit indicates if an NMI was generated by the Configurable Logic Block. */
            __IM  uint16_t CPU2WDRSN                 : 1 ;     /*!< [9:9] : CPU2 WDRSn Reset Indication Flag: This bits indicates if CPU2s WDRSn was fired or not. */
            __IM  uint16_t CPU2NMIWDRSN              : 1 ;     /*!< [10:10] : CPU2 NMIWDRSn Reset Indication Flag: This bits indicates if CPU2s NMIWDRSn was fired or not. */
                  uint16_t RSV_0                     : 5 ;     /*!< [15:11] : reserved. */
        } NMIFLGb;
    };

    union
    {
        __IOM uint16_t NMIFLGCLR;  /*!< 0x00001004 */ 
       
        struct
        {
            __IOM uint16_t NMIINT                    : 1 ;     /*!< [0:0] : Writing a 1 to the respective bit clears the corresponding flag bit in the NMIFLG and NMISHDFLG registers. */
            __IOM uint16_t CLOCKFAIL                 : 1 ;     /*!< [1:1] : Writing a 1 to the respective bit clears the corresponding flag bit in the NMIFLG and NMISHDFLG registers. */
            __IOM uint16_t RAMUNCERR                 : 1 ;     /*!< [2:2] : Writing a 1 to the respective bit clears the corresponding flag bit in the NMIFLG and NMISHDFLG registers. */
            __IOM uint16_t FLUNCERR                  : 1 ;     /*!< [3:3] : Writing a 1 to the respective bit clears the corresponding flag bit in the NMIFLG and NMISHDFLG registers. */
                  uint16_t RSV_1                     : 4 ;     /*!< [7:4] : reserved. */
            __IOM uint16_t CLBNMI                    : 1 ;     /*!< [8:8] : Writing a 1 to the respective bit clears the corresponding flag bit in the NMIFLG and NMISHDFLG registers. */
            __IOM uint16_t CPU2WDRSN                 : 1 ;     /*!< [9:9] : Writing a 1 to the respective bit clears the corresponding flag bit in the NMIFLG and NMISHDFLG registers. */
            __IOM uint16_t CPU2NMIWDRSN              : 1 ;     /*!< [10:10] : Writing a 1 to the respective bit clears the corresponding flag bit in the NMIFLG and NMISHDFLG registers. */
                  uint16_t RSV_0                     : 5 ;     /*!< [15:11] : reserved. */
        } NMIFLGCLRb;
    };

    union
    {
        __IOM uint16_t NMIFLGFRC;  /*!< 0x00001006 */ 
       
        struct
        {
                  uint16_t RSV_2                     : 1 ;     /*!< [0:0] : reserved. */
            __IOM uint16_t CLOCKFAIL                 : 1 ;     /*!< [1:1] : Writing a 1 to these bits will set the respective FAIL flag in the NMIFLG and NMISHDFLG registers. */
            __IOM uint16_t RAMUNCERR                 : 1 ;     /*!< [2:2] : Writing a 1 to these bits will set the respective FAIL flag in the NMIFLG and NMISHDFLG registers. */
            __IOM uint16_t FLUNCERR                  : 1 ;     /*!< [3:3] : Writing a 1 to these bits will set the respective FAIL flag in the NMIFLG and NMISHDFLG registers. */
                  uint16_t RSV_1                     : 4 ;     /*!< [7:4] : reserved. */
            __IOM uint16_t CLBNMI                    : 1 ;     /*!< [8:8] : Writing a 1 to these bits will set the respective FAIL flag in the NMIFLG and NMISHDFLG registers. */
            __IOM uint16_t CPU2WDRSN                 : 1 ;     /*!< [9:9] : Writing a 1 to these bits will set the respective FAIL flag in the NMIFLG and NMISHDFLG registers. */
            __IOM uint16_t CPU2NMIWDRSN              : 1 ;     /*!< [10:10] : Writing a 1 to these bits will set the respective FAIL flag in the NMIFLG and NMISHDFLG registers. */
                  uint16_t RSV_0                     : 5 ;     /*!< [15:11] : reserved. */
        } NMIFLGFRCb;
    };

    union
    {
        __IM uint16_t NMIWDCNT;  /*!< 0x00001008 */ 
       
        struct
        {
            __IM  uint16_t NMIWDCNT                  : 16;     /*!< [15:0] : NMI Watchdog Counter: This 16-bit incremental counter will start incrementing whenever any one of the enabled FAIL flags are set. */
        } NMIWDCNTb;
    };

    union
    {
        __IOM uint16_t NMIWDPRD;  /*!< 0x0000100a */ 
       
        struct
        {
            __IOM uint16_t NMIWDPRD                  : 16;     /*!< [15:0] : NMI Watchdog Period: This 16-bit value contains the period value at which a reset is generated when the watchdog counter matches. */
        } NMIWDPRDb;
    };

    union
    {
        __IM uint32_t NMISHDFLG;  /*!< 0x0000100c */ 
       
        struct
        {
                  uint32_t RSV_2                     : 1 ;     /*!< [0:0] : reserved. */
            __IM  uint32_t CLOCKFAIL                 : 1 ;     /*!< [1:1] : Shadow NMI Flags: When an NMIFLG bit is set due to any of the possible NMI source in the device, the corresponding bit in this register is also set. */
            __IM  uint32_t RAMUNCERR                 : 1 ;     /*!< [2:2] : Shadow NMI Flags: When an NMIFLG bit is set due to any of the possible NMI source in the device, the corresponding bit in this register is also set. */
            __IM  uint32_t FLUNCERR                  : 1 ;     /*!< [3:3] : Shadow NMI Flags: When an NMIFLG bit is set due to any of the possible NMI source in the device, the corresponding bit in this register is also set. */
                  uint32_t RSV_1                     : 4 ;     /*!< [7:4] : reserved. */
            __IM  uint32_t CLBNMI                    : 1 ;     /*!< [8:8] : Shadow NMI Flags: When an NMIFLG bit is set due to any of the possible NMI source in the device, the corresponding bit in this register is also set. */
            __IM  uint32_t CPU2WDRSN                 : 1 ;     /*!< [9:9] : Shadow NMI Flags: When an NMIFLG bit is set due to any of the possible NMI source in the device, the corresponding bit in this register is also set. */
            __IM  uint32_t CPU2NMIWDRSN              : 1 ;     /*!< [10:10] : Shadow NMI Flags: When an NMIFLG bit is set due to any of the possible NMI source in the device, the corresponding bit in this register is also set. */
                  uint32_t RSV_0                     : 21;     /*!< [31:11] : reserved. */
        } NMISHDFLGb;
    };

    uint8_t    RSV_0X1010[16];   /*!< 0x00001010~0x0000101f : reserved */

    union
    {
        __IOM uint32_t NMIWDCFG;  /*!< 0x00001020 */ 
       
        struct
        {
            __IOM uint32_t NMIWD_EN                  : 1 ;     /*!< [0:0] : nmi watchdog enable                                             <br>  0: disable                                                      <br>  1: enable                                                       <br>  Reset type: SYSRSn                                              <br>. */
                  uint32_t RSV_0                     : 31;     /*!< [31:1] : reserved. */
        } NMIWDCFGb;
    };

    union
    {
        __IOM uint32_t NMICLBCFG;  /*!< 0x00001024 */ 
       
        struct
        {
            __IOM uint32_t CLBNMISELECT              : 1 ;     /*!< [0:0] : CLB NMI Select                                                  <br>  0: all CLB NMI trigger this CPU NMI                             <br>  1: only CLB in CPU Subsystem trigger this CPU NMI               <br>  Reset type: SYSRSn                                              <br>. */
                  uint32_t RSV_0                     : 31;     /*!< [31:1] : reserved. */
        } NMICLBCFGb;
    };
} NMI_INTRUPT_REGS_Type;

/*! \brief XINT_REGS register */
typedef struct {
    union
    {
        __IOM uint16_t XINT1CR;  /*!< 0x00001400 */ 
       
        struct
        {
            __IOM uint16_t INTR_ENABLE               : 1 ;     /*!< [0:0] : 0: Interrupt Disabled                                           <br>  1: Interrupt Enabled Reset type: SYSRSn                         <br>. */
                  uint16_t RSV_1                     : 1 ;     /*!< [1:1] : reserved. */
            __IOM uint16_t POLARITY                  : 2 ;     /*!< [3:2] : 00: Interrupt is selected as negative edge triggered 01: Interrupt is selected as positive edge triggered 10: Interrupt is selected as negative edge triggered<br>  11: Interrupt is selected as positive or negative edge triggered<br>  Reset type: SYSRSn                                              <br>. */
                  uint16_t RSV_0                     : 12;     /*!< [15:4] : reserved. */
        } XINT1CRb;
    };

    union
    {
        __IOM uint16_t XINT2CR;  /*!< 0x00001402 */ 
       
        struct
        {
            __IOM uint16_t INTR_ENABLE               : 1 ;     /*!< [0:0] : 0: Interrupt Disabled                                           <br>  1: Interrupt Enabled Reset type: SYSRSn                         <br>. */
                  uint16_t RSV_1                     : 1 ;     /*!< [1:1] : reserved. */
            __IOM uint16_t POLARITY                  : 2 ;     /*!< [3:2] : 00: Interrupt is selected as negative edge triggered 01: Interrupt is selected as positive edge triggered 10: Interrupt is selected as negative edge triggered<br>  11: Interrupt is selected as positive or negative edge triggered<br>  Reset type: SYSRSn                                              <br>. */
                  uint16_t RSV_0                     : 12;     /*!< [15:4] : reserved. */
        } XINT2CRb;
    };

    union
    {
        __IOM uint16_t XINT3CR;  /*!< 0x00001404 */ 
       
        struct
        {
            __IOM uint16_t INTR_ENABLE               : 1 ;     /*!< [0:0] : 0: Interrupt Disabled                                           <br>  1: Interrupt Enabled Reset type: SYSRSn                         <br>. */
                  uint16_t RSV_1                     : 1 ;     /*!< [1:1] : reserved. */
            __IOM uint16_t POLARITY                  : 2 ;     /*!< [3:2] : 00: Interrupt is selected as negative edge triggered 01: Interrupt is selected as positive edge triggered 10: Interrupt is selected as negative edge triggered<br>  11: Interrupt is selected as positive or negative edge triggered<br>  Reset type: SYSRSn                                              <br>. */
                  uint16_t RSV_0                     : 12;     /*!< [15:4] : reserved. */
        } XINT3CRb;
    };

    union
    {
        __IOM uint16_t XINT4CR;  /*!< 0x00001406 */ 
       
        struct
        {
            __IOM uint16_t INTR_ENABLE               : 1 ;     /*!< [0:0] : 0: Interrupt Disabled                                           <br>  1: Interrupt Enabled Reset type: SYSRSn                         <br>. */
                  uint16_t RSV_1                     : 1 ;     /*!< [1:1] : reserved. */
            __IOM uint16_t POLARITY                  : 2 ;     /*!< [3:2] : 00: Interrupt is selected as negative edge triggered 01: Interrupt is selected as positive edge triggered 10: Interrupt is selected as negative edge triggered<br>  11: Interrupt is selected as positive or negative edge triggered<br>  Reset type: SYSRSn                                              <br>. */
                  uint16_t RSV_0                     : 12;     /*!< [15:4] : reserved. */
        } XINT4CRb;
    };

    union
    {
        __IOM uint32_t XINT5CR;  /*!< 0x00001408 */ 
       
        struct
        {
            __IOM uint32_t INTR_ENABLE               : 1 ;     /*!< [0:0] : 0: Interrupt Disabled                                           <br>  1: Interrupt Enabled Reset type: SYSRSn                         <br>. */
                  uint32_t RSV_1                     : 1 ;     /*!< [1:1] : reserved. */
            __IOM uint32_t POLARITY                  : 2 ;     /*!< [3:2] : 00: Interrupt is selected as negative edge triggered 01: Interrupt is selected as positive edge triggered 10: Interrupt is selected as negative edge triggered<br>  11: Interrupt is selected as positive or negative edge triggered<br>  Reset type: SYSRSn                                              <br>. */
                  uint32_t RSV_0                     : 28;     /*!< [31:4] : reserved. */
        } XINT5CRb;
    };

    uint8_t    RSV_0X140C[4];   /*!< 0x0000140c~0x0000140f : reserved */

    union
    {
        __IM uint16_t XINT1CTR;  /*!< 0x00001410 */ 
       
        struct
        {
            __IM  uint16_t INTCTR                    : 16;     /*!< [15:0] : This is a free running 16-bit up-counter that is clocked at the SYSCLKOUT rate. */
        } XINT1CTRb;
    };

    union
    {
        __IM uint16_t XINT2CTR;  /*!< 0x00001412 */ 
       
        struct
        {
            __IM  uint16_t INTCTR                    : 16;     /*!< [15:0] : This is a free running 16-bit up-counter that is clocked at the SYSCLKOUT rate. */
        } XINT2CTRb;
    };

    union
    {
        __IM uint32_t XINT3CTR;  /*!< 0x00001414 */ 
       
        struct
        {
            __IM  uint32_t INTCTR                    : 16;     /*!< [15:0] : This is a free running 16-bit up-counter that is clocked at the SYSCLKOUT rate. */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } XINT3CTRb;
    };

    union
    {
        __IM uint32_t XINT4CTR;  /*!< 0x00001418 */ 
       
        struct
        {
            __IM  uint32_t INTCTR                    : 16;     /*!< [15:0] : This is a free running 16-bit up-counter that is clocked at the SYSCLKOUT rate. */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } XINT4CTRb;
    };

    union
    {
        __IM uint32_t XINT5CTR;  /*!< 0x0000141c */ 
       
        struct
        {
            __IM  uint32_t INTCTR                    : 16;     /*!< [15:0] : This is a free running 16-bit up-counter that is clocked at the SYSCLKOUT rate. */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } XINT5CTRb;
    };

    union
    {
        __IM uint32_t XINT1FLG;  /*!< 0x00001420 */ 
       
        struct
        {
            __IM  uint32_t XINTFLG                   : 1 ;     /*!< [0:0] : Writing a 1 to the respective bit clears the corresponding external interrupt flag. */
                  uint32_t RSV_0                     : 31;     /*!< [31:1] : reserved. */
        } XINT1FLGb;
    };

    union
    {
        __IM uint32_t XINT2FLG;  /*!< 0x00001424 */ 
       
        struct
        {
            __IM  uint32_t XINTFLG                   : 1 ;     /*!< [0:0] : Writing a 1 to the respective bit clears the corresponding external interrupt flag. */
                  uint32_t RSV_0                     : 31;     /*!< [31:1] : reserved. */
        } XINT2FLGb;
    };

    union
    {
        __IM uint32_t XINT3FLG;  /*!< 0x00001428 */ 
       
        struct
        {
            __IM  uint32_t XINTFLG                   : 1 ;     /*!< [0:0] : Writing a 1 to the respective bit clears the corresponding external interrupt flag. */
                  uint32_t RSV_0                     : 31;     /*!< [31:1] : reserved. */
        } XINT3FLGb;
    };

    union
    {
        __IM uint32_t XINT4FLG;  /*!< 0x0000142c */ 
       
        struct
        {
            __IM  uint32_t XINTFLG                   : 1 ;     /*!< [0:0] : Writing a 1 to the respective bit clears the corresponding external interrupt flag. */
                  uint32_t RSV_0                     : 31;     /*!< [31:1] : reserved. */
        } XINT4FLGb;
    };

    union
    {
        __IM uint32_t XINT5FLG;  /*!< 0x00001430 */ 
       
        struct
        {
            __IM  uint32_t XINTFLG                   : 1 ;     /*!< [0:0] : Writing a 1 to the respective bit clears the corresponding external interrupt flag. */
                  uint32_t RSV_0                     : 31;     /*!< [31:1] : reserved. */
        } XINT5FLGb;
    };

    uint8_t    RSV_0X1434[12];   /*!< 0x00001434~0x0000143f : reserved */

    union
    {
        __IOM uint32_t XINT1CLR;  /*!< 0x00001440 */ 
       
        struct
        {
            __IOM uint32_t XINTCLR                   : 1 ;     /*!< [0:0] : Writing a 1 to the respective bit clears the corresponding external interrupt flag. */
                  uint32_t RSV_0                     : 31;     /*!< [31:1] : reserved. */
        } XINT1CLRb;
    };

    union
    {
        __IOM uint32_t XINT2CLR;  /*!< 0x00001444 */ 
       
        struct
        {
            __IOM uint32_t XINTCLR                   : 1 ;     /*!< [0:0] : Writing a 1 to the respective bit clears the corresponding external interrupt flag. */
                  uint32_t RSV_0                     : 31;     /*!< [31:1] : reserved. */
        } XINT2CLRb;
    };

    union
    {
        __IOM uint32_t XINT3CLR;  /*!< 0x00001448 */ 
       
        struct
        {
            __IOM uint32_t XINTCLR                   : 1 ;     /*!< [0:0] : Writing a 1 to the respective bit clears the corresponding external interrupt flag. */
                  uint32_t RSV_0                     : 31;     /*!< [31:1] : reserved. */
        } XINT3CLRb;
    };

    union
    {
        __IOM uint32_t XINT4CLR;  /*!< 0x0000144c */ 
       
        struct
        {
            __IOM uint32_t XINTCLR                   : 1 ;     /*!< [0:0] : Writing a 1 to the respective bit clears the corresponding external interrupt flag. */
                  uint32_t RSV_0                     : 31;     /*!< [31:1] : reserved. */
        } XINT4CLRb;
    };

    union
    {
        __IOM uint32_t XINT5CLR;  /*!< 0x00001450 */ 
       
        struct
        {
            __IOM uint32_t XINTCLR                   : 1 ;     /*!< [0:0] : Writing a 1 to the respective bit clears the corresponding external interrupt flag. */
                  uint32_t RSV_0                     : 31;     /*!< [31:1] : reserved. */
        } XINT5CLRb;
    };
} XINT_REGS_Type;

/*! \brief DEV_CFG_REGS register */
typedef struct {
    union
    {
        __IOM uint32_t DEVCFGLOCK1;  /*!< 0x00001800 */ 
       
        struct
        {
            __IOM uint32_t CPUSEL0                   : 1 ;     /*!< [0:0] : Lock bit for CPUSEL0 register: 0: Register is not locked        <br>  1: Register is locked                                           <br>  Reset type: CPU1. */
            __IOM uint32_t CPUSEL1                   : 1 ;     /*!< [1:1] : Lock bit for CPUSEL1 register: 0: Register is not locked        <br>  1: Register is locked                                           <br>  Reset type: CPU1. */
            __IOM uint32_t CPUSEL2                   : 1 ;     /*!< [2:2] : Lock bit for CPUSEL2 register: 0: Register is not locked        <br>  1: Register is locked                                           <br>  Reset type: CPU1. */
                  uint32_t RSV_4                     : 1 ;     /*!< [3:3] : reserved. */
            __IOM uint32_t CPUSEL4                   : 1 ;     /*!< [4:4] : Lock bit for CPUSEL4 register: 0: Register is not locked        <br>  1: Register is locked                                           <br>  Reset type: CPU1. */
            __IOM uint32_t CPUSEL5                   : 1 ;     /*!< [5:5] : Lock bit for CPUSEL5 register: 0: Register is not locked        <br>  1: Register is locked                                           <br>  Reset type: CPU1. */
            __IOM uint32_t CPUSEL6                   : 1 ;     /*!< [6:6] : Lock bit for CPUSEL6 register: 0: Register is not locked        <br>  1: Register is locked                                           <br>  Reset type: CPU1. */
            __IOM uint32_t CPUSEL7                   : 1 ;     /*!< [7:7] : Lock bit for CPUSEL7 register: 0: Register is not locked        <br>  1: Register is locked                                           <br>  Reset type: CPU1. */
            __IOM uint32_t CPUSEL8                   : 1 ;     /*!< [8:8] : Lock bit for CPUSEL8 register: 0: Register is not locked        <br>  1: Register is locked                                           <br>  Reset type: CPU1. */
                  uint32_t RSV_3                     : 2 ;     /*!< [10:9] : reserved. */
            __IOM uint32_t CPUSEL11                  : 1 ;     /*!< [11:11] : Lock bit for CPUSEL11 register: 0: Register is not locked       <br>  1: Register is locked                                           <br>  Reset type: CPU1. */
            __IOM uint32_t CPUSEL12                  : 1 ;     /*!< [12:12] : Lock bit for CPUSEL12 register: 0: Register is not locked       <br>  1: Register is locked                                           <br>  Reset type: CPU1. */
                  uint32_t RSV_2                     : 1 ;     /*!< [13:13] : reserved. */
            __IOM uint32_t CPUSEL14                  : 1 ;     /*!< [14:14] : Lock bit for CPUSEL14 register: 0: Register is not locked       <br>  1: Register is locked                                           <br>  Reset type: CPU1. */
            __IOM uint32_t CPUSEL15                  : 1 ;     /*!< [15:15] : Lock bit for CPUSEL15 register: 0: Register is not locked       <br>  1: Register is locked                                           <br>  Reset type: CPU1. */
                  uint32_t RSV_1                     : 2 ;     /*!< [17:16] : reserved. */
            __IOM uint32_t CPUSEL18                  : 1 ;     /*!< [18:18] : Lock bit for CPUSEL18 register: 0: Register is not locked       <br>  1: Register is locked                                           <br>  Reset type: CPU1. */
                  uint32_t RSV_0                     : 13;     /*!< [31:19] : reserved. */
        } DEVCFGLOCK1b;
    };

    uint8_t    RSV_0X1804[12];   /*!< 0x00001804~0x0000180f : reserved */

    union
    {
        __IOM uint32_t PARTIDL;  /*!< 0x00001810 */ 
       
        struct
        {
                  uint32_t RSV_2                     : 8 ;     /*!< [7:0] : reserved. */
            __IOM uint32_t PIN_COUNT                 : 3 ;     /*!< [10:8] : 0 = reserved for future                                         <br>  1 = reserved for future                                         <br>  2 = reserved for future                                         <br>  3 = reserved for future                                         <br>  4 = reserved for future                                         <br>  5 = 100 pin                                                     <br>  6 = 176 pin                                                     <br>  7 = 337 pin                                                     <br>  Reset type: XRSn                                                <br>. */
                  uint32_t RSV_1                     : 5 ;     /*!< [15:11] : reserved. */
            __IOM uint32_t FLASH_SIZE                : 8 ;     /*!< [23:16] : 0x9 - 2048KB                                                    <br>  0x8 - 1024KB                                                    <br>  Note: This field shows flash size on CPU1 (see datasheet for flash size available)<br>  Reset type: XRSn                                                <br>. */
                  uint32_t RSV_0                     : 4 ;     /*!< [27:24] : reserved. */
            __IOM uint32_t PARTID_FORMAT_REVISION    : 4 ;     /*!< [31:28] : Revision of the PARTID format                                   <br>  Reset type: XRSn                                                <br>. */
        } PARTIDLb;
    };

    union
    {
        __IOM uint32_t PARTIDH;  /*!< 0x00001814 */ 
       
        struct
        {
                  uint32_t RSV_0                     : 8 ;     /*!< [7:0] : reserved. */
            __IOM uint32_t FAMILY                    : 8 ;     /*!< [15:8] : Device Family                                                   <br>  0x3 - DUAL CORE                                                 <br>  0x4 - SINGLE CORE                                               <br>  0x5 - SINGLE CORE                                               <br>  Other values Reserved Reset type: XRSn                          <br>. */
            __IOM uint32_t PARTNO                    : 8 ;     /*!< [23:16] : Refer to Datasheet for Device Part Number Reset type: XRSn. */
            __IOM uint32_t DEVICE_CLASS_ID           : 8 ;     /*!< [31:24] : Reserved                                                        <br>  Reset type: XRSn                                                <br>. */
        } PARTIDHb;
    };

    union
    {
        __IOM uint32_t REVID;  /*!< 0x00001818 */ 
       
        struct
        {
            __IOM uint32_t REVID                     : 32;     /*!< [31:0] : These 32-bits specify the silicon revision. */
        } REVIDb;
    };

    uint8_t    RSV_0X181C[4];   /*!< 0x0000181c~0x0000181f : reserved */

    union
    {
        __IOM uint32_t DC0;  /*!< 0x00001820 */ 
       
        struct
        {
            __IOM uint32_t SINGLE_CORE               : 1 ;     /*!< [0:0] : Single Core vs Dual Core                                        <br>  0: Single Core                                                  <br>  1: Dual Core                                                    <br>  Reset type: XRSn                                                <br>. */
                  uint32_t RSV_0                     : 31;     /*!< [31:1] : reserved. */
        } DC0b;
    };

    union
    {
        __IOM uint32_t DC1;  /*!< 0x00001824 */ 
       
        struct
        {
            __IOM uint32_t TFU                       : 1 ;     /*!< [0:0] : TFU :                                                           <br>  0: Feature not present on the device                            <br>  1: Feature present on the device                                <br>  Reset type: XRSn                                                <br>. */
                  uint32_t RSV_1                     : 7 ;     /*!< [7:1] : reserved. */
            __IOM uint32_t CRC                       : 1 ;     /*!< [8:8] : CRC :                                                           <br>  0: Feature not present on the device                            <br>  1: Feature present on the device                                <br>  Reset type: XRSn                                                <br>. */
                  uint32_t RSV_0                     : 23;     /*!< [31:9] : reserved. */
        } DC1b;
    };

    union
    {
        __IOM uint32_t DC2;  /*!< 0x00001828 */ 
       
        struct
        {
            __IOM uint32_t EMIF1                     : 1 ;     /*!< [0:0] : EMIF1 :                                                         <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t EMIF2                     : 1 ;     /*!< [1:1] : EMIF2 :                                                         <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
                  uint32_t RSV_0                     : 30;     /*!< [31:2] : reserved. */
        } DC2b;
    };

    union
    {
        __IOM uint32_t DC3;  /*!< 0x0000182c */ 
       
        struct
        {
            __IOM uint32_t EPWM1                     : 1 ;     /*!< [0:0] : EPWM1 :                                                         <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t EPWM2                     : 1 ;     /*!< [1:1] : EPWM2 :                                                         <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t EPWM3                     : 1 ;     /*!< [2:2] : EPWM3 :                                                         <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t EPWM4                     : 1 ;     /*!< [3:3] : EPWM4 :                                                         <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t EPWM5                     : 1 ;     /*!< [4:4] : EPWM5 :                                                         <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t EPWM6                     : 1 ;     /*!< [5:5] : EPWM6 :                                                         <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t EPWM7                     : 1 ;     /*!< [6:6] : EPWM7 :                                                         <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t EPWM8                     : 1 ;     /*!< [7:7] : EPWM8 :                                                         <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t EPWM9                     : 1 ;     /*!< [8:8] : EPWM9 :                                                         <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t EPWM10                    : 1 ;     /*!< [9:9] : EPWM10 :                                                        <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t EPWM11                    : 1 ;     /*!< [10:10] : EPWM11 :                                                        <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t EPWM12                    : 1 ;     /*!< [11:11] : EPWM12 :                                                        <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
                  uint32_t RSV_0                     : 20;     /*!< [31:12] : reserved. */
        } DC3b;
    };

    union
    {
        __IOM uint32_t DC4;  /*!< 0x00001830 */ 
       
        struct
        {
            __IOM uint32_t ECAP1                     : 1 ;     /*!< [0:0] : ECAP1 :                                                         <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t ECAP2                     : 1 ;     /*!< [1:1] : ECAP2 :                                                         <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t ECAP3                     : 1 ;     /*!< [2:2] : ECAP3 :                                                         <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t ECAP4                     : 1 ;     /*!< [3:3] : ECAP4 :                                                         <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t ECAP5                     : 1 ;     /*!< [4:4] : ECAP5 :                                                         <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t ECAP6                     : 1 ;     /*!< [5:5] : ECAP6 :                                                         <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
                  uint32_t RSV_0                     : 26;     /*!< [31:6] : reserved. */
        } DC4b;
    };

    union
    {
        __IOM uint32_t DC5;  /*!< 0x00001834 */ 
       
        struct
        {
            __IOM uint32_t EQEP1                     : 1 ;     /*!< [0:0] : EQEP1 :                                                         <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t EQEP2                     : 1 ;     /*!< [1:1] : EQEP2 :                                                         <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t EQEP3                     : 1 ;     /*!< [2:2] : EQEP3 :                                                         <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
                  uint32_t RSV_0                     : 29;     /*!< [31:3] : reserved. */
        } DC5b;
    };

    union
    {
        __IOM uint32_t DC6;  /*!< 0x00001838 */ 
       
        struct
        {
            __IOM uint32_t CLB1                      : 1 ;     /*!< [0:0] : CLB1 :                                                          <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t CLB2                      : 1 ;     /*!< [1:1] : CLB2 :                                                          <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t CLB3                      : 1 ;     /*!< [2:2] : CLB3 :                                                          <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t CLB4                      : 1 ;     /*!< [3:3] : CLB4 :                                                          <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t CLB5                      : 1 ;     /*!< [4:4] : CLB1 :                                                          <br>  0: Feature not present on the device 0: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t CLB6                      : 1 ;     /*!< [5:5] : CLB2 :                                                          <br>  0: Feature not present on the device 0: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t CLB7                      : 1 ;     /*!< [6:6] : CLB3 :                                                          <br>  0: Feature not present on the device 0: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t CLB8                      : 1 ;     /*!< [7:7] : CLB4 :                                                          <br>  0: Feature not present on the device 0: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
                  uint32_t RSV_0                     : 24;     /*!< [31:8] : reserved. */
        } DC6b;
    };

    union
    {
        __IOM uint32_t DC7;  /*!< 0x0000183c */ 
       
        struct
        {
            __IOM uint32_t SD1                       : 1 ;     /*!< [0:0] : SD1 :                                                           <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t SD2                       : 1 ;     /*!< [1:1] : SD2 :                                                           <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
                  uint32_t RSV_0                     : 30;     /*!< [31:2] : reserved. */
        } DC7b;
    };

    union
    {
        __IOM uint32_t DC8;  /*!< 0x00001840 */ 
       
        struct
        {
            __IOM uint32_t SCI_A                     : 1 ;     /*!< [0:0] : SCI_A :                                                         <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t SCI_B                     : 1 ;     /*!< [1:1] : SCI_B :                                                         <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t SCI_C                     : 1 ;     /*!< [2:2] : SCI_C :                                                         <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t SCI_D                     : 1 ;     /*!< [3:3] : SCI_D :                                                         <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
                  uint32_t RSV_0                     : 28;     /*!< [31:4] : reserved. */
        } DC8b;
    };

    union
    {
        __IOM uint32_t DC9;  /*!< 0x00001844 */ 
       
        struct
        {
            __IOM uint32_t SPI_A                     : 1 ;     /*!< [0:0] : SPI_A :                                                         <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t SPI_B                     : 1 ;     /*!< [1:1] : SPI_B :                                                         <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t SPI_C                     : 1 ;     /*!< [2:2] : SPI_C :                                                         <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
                  uint32_t RSV_0                     : 29;     /*!< [31:3] : reserved. */
        } DC9b;
    };

    union
    {
        __IOM uint32_t DC10;  /*!< 0x00001848 */ 
       
        struct
        {
            __IOM uint32_t I2C_A                     : 1 ;     /*!< [0:0] : I2C_A :                                                         <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t I2C_B                     : 1 ;     /*!< [1:1] : I2C_B :                                                         <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
                  uint32_t RSV_1                     : 14;     /*!< [15:2] : reserved. */
            __IOM uint32_t PMBUS_A                   : 1 ;     /*!< [16:16] : PMBus_A :                                                       <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
                  uint32_t RSV_0                     : 15;     /*!< [31:17] : reserved. */
        } DC10b;
    };

    union
    {
        __IOM uint32_t DC11;  /*!< 0x0000184c */ 
       
        struct
        {
            __IOM uint32_t CAN_A                     : 1 ;     /*!< [0:0] : CAN_A :                                                         <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t CAN_B                     : 1 ;     /*!< [1:1] : CAN_B :                                                         <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t CAN_C                     : 1 ;     /*!< [2:2] : CAN_C :                                                         <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
                  uint32_t RSV_0                     : 29;     /*!< [31:3] : reserved. */
        } DC11b;
    };

    union
    {
        __IOM uint32_t DC12;  /*!< 0x00001850 */ 
       
        struct
        {
                  uint32_t RSV_1                     : 16;     /*!< [15:0] : reserved. */
            __IOM uint32_t USB_A                     : 2 ;     /*!< [17:16] : Capability of the USB_A Module:                                 <br>  2'b00: No USB function                                          <br>  2'b01: Device Only                                              <br>  2'b10: Device or Host                                           <br>  2'b11: Device or Host                                           <br>  Reset type: XRSn                                                <br>. */
                  uint32_t RSV_0                     : 14;     /*!< [31:18] : reserved. */
        } DC12b;
    };

    union
    {
         uint32_t DC13;  /*!< 0x00001854 */ 
       
        struct
        {
                  uint32_t RSV_0                     : 32;     /*!< [31:0] : reserved. */
        } DC13b;
    };

    union
    {
        __IOM uint32_t DC14;  /*!< 0x00001858 */ 
       
        struct
        {
            __IOM uint32_t ADC_A                     : 1 ;     /*!< [0:0] : ADC_A :                                                         <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t ADC_B                     : 1 ;     /*!< [1:1] : ADC_B :                                                         <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t ADC_C                     : 1 ;     /*!< [2:2] : ADC_C :                                                         <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t ADC_D                     : 1 ;     /*!< [3:3] : ADC_D :                                                         <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
                  uint32_t RSV_0                     : 28;     /*!< [31:4] : reserved. */
        } DC14b;
    };

    union
    {
        __IOM uint32_t DC15;  /*!< 0x0000185c */ 
       
        struct
        {
            __IOM uint32_t CMPSS1                    : 1 ;     /*!< [0:0] : CMPSS1 :                                                        <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t CMPSS2                    : 1 ;     /*!< [1:1] : CMPSS2 :                                                        <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t CMPSS3                    : 1 ;     /*!< [2:2] : CMPSS3 :                                                        <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t CMPSS4                    : 1 ;     /*!< [3:3] : CMPSS4 :                                                        <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t CMPSS5                    : 1 ;     /*!< [4:4] : CMPSS5 :                                                        <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t CMPSS6                    : 1 ;     /*!< [5:5] : CMPSS6 :                                                        <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t CMPSS7                    : 1 ;     /*!< [6:6] : CMPSS7 :                                                        <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t CMPSS8                    : 1 ;     /*!< [7:7] : CMPSS8 :                                                        <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
                  uint32_t RSV_0                     : 24;     /*!< [31:8] : reserved. */
        } DC15b;
    };

    uint8_t    RSV_0X1860[4];   /*!< 0x00001860~0x00001863 : reserved */

    union
    {
        __IOM uint32_t DC17;  /*!< 0x00001864 */ 
       
        struct
        {
                  uint32_t RSV_1                     : 16;     /*!< [15:0] : reserved. */
            __IOM uint32_t DAC_A                     : 1 ;     /*!< [16:16] : Buffered-DAC_A :                                                <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t DAC_B                     : 1 ;     /*!< [17:17] : Buffered-DAC_B :                                                <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t DAC_C                     : 1 ;     /*!< [18:18] : Buffered-DAC_C :                                                <br>  0: Feature not present on the device 1: Feature present on the device<br>  Reset type: XRSn                                                <br>. */
                  uint32_t RSV_0                     : 13;     /*!< [31:19] : reserved. */
        } DC17b;
    };

    union
    {
         uint32_t DC18;  /*!< 0x00001868 */ 
       
        struct
        {
                  uint32_t RSV_0                     : 32;     /*!< [31:0] : reserved. */
        } DC18b;
    };

    union
    {
         uint32_t DC19;  /*!< 0x0000186c */ 
       
        struct
        {
                  uint32_t RSV_0                     : 32;     /*!< [31:0] : reserved. */
        } DC19b;
    };

    union
    {
        __IOM uint32_t DC20;  /*!< 0x00001870 */ 
       
        struct
        {
            __IOM uint32_t GS0                       : 1 ;     /*!< [0:0] : 0: Feature not present on the device                            <br>  1: Feature present on the device                                <br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t GS1                       : 1 ;     /*!< [1:1] : 0: Feature not present on the device                            <br>  1: Feature present on the device                                <br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t GS2                       : 1 ;     /*!< [2:2] : 0: Feature not present on the device                            <br>  1: Feature present on the device                                <br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t GS3                       : 1 ;     /*!< [3:3] : 0: Feature not present on the device                            <br>  1: Feature present on the device                                <br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t GS4                       : 1 ;     /*!< [4:4] : 0: Feature not present on the device                            <br>  1: Feature present on the device                                <br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t GS5                       : 1 ;     /*!< [5:5] : 0: Feature not present on the device                            <br>  1: Feature present on the device                                <br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t GS6                       : 1 ;     /*!< [6:6] : 0: Feature not present on the device                            <br>  1: Feature present on the device                                <br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t GS7                       : 1 ;     /*!< [7:7] : 0: Feature not present on the device                            <br>  1: Feature present on the device                                <br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t GS8                       : 1 ;     /*!< [8:8] : 0: Feature not present on the device                            <br>  1: Feature present on the device                                <br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t GS9                       : 1 ;     /*!< [9:9] : 0: Feature not present on the device                            <br>  1: Feature present on the device                                <br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t GS10                      : 1 ;     /*!< [10:10] : 0: Feature not present on the device                            <br>  1: Feature present on the device                                <br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t GS11                      : 1 ;     /*!< [11:11] : 0: Feature not present on the device                            <br>  1: Feature present on the device                                <br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t GS12                      : 1 ;     /*!< [12:12] : 0: Feature not present on the device                            <br>  1: Feature present on the device                                <br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t GS13                      : 1 ;     /*!< [13:13] : 0: Feature not present on the device                            <br>  1: Feature present on the device                                <br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t GS14                      : 1 ;     /*!< [14:14] : 0: Feature not present on the device                            <br>  1: Feature present on the device                                <br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t GS15                      : 1 ;     /*!< [15:15] : 0: Feature not present on the device                            <br>  1: Feature present on the device                                <br>  Reset type: XRSn                                                <br>. */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } DC20b;
    };

    uint8_t    RSV_0X1874[76];   /*!< 0x00001874~0x000018bf : reserved */

    union
    {
        __IOM uint32_t PERCNF1;  /*!< 0x000018c0 */ 
       
        struct
        {
            __IOM uint32_t ADC_A_MODE                : 1 ;     /*!< [0:0] : 0: 16-bit or 12-bit configurable in software 1: Only 12-bit operation available<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t ADC_B_MODE                : 1 ;     /*!< [1:1] : 0: 16-bit or 12-bit configurable in software 1: Only 12-bit operation available<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t ADC_C_MODE                : 1 ;     /*!< [2:2] : 0: 16-bit or 12-bit configurable in software 1: Only 12-bit operation available<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t ADC_D_MODE                : 1 ;     /*!< [3:3] : 0: 16-bit or 12-bit configurable in software 1: Only 12-bit operation available<br>  Reset type: XRSn                                                <br>. */
                  uint32_t RSV_1                     : 12;     /*!< [15:4] : reserved. */
            __IOM uint32_t USB_A_PHY                 : 1 ;     /*!< [16:16] : Internal PHY is present present or not for the USB_A module:    <br>  0: Internal USB PHY Module is not present 1: Internal USB PHY Module is present. */
                  uint32_t RSV_0                     : 15;     /*!< [31:17] : reserved. */
        } PERCNF1b;
    };

    uint8_t    RSV_0X18C4[64];   /*!< 0x000018c4~0x00001903 : reserved */

    union
    {
        __IOM uint32_t SOFTPRES0;  /*!< 0x00001904 */ 
       
        struct
        {
            __IOM uint32_t TFU                       : 1 ;     /*!< [0:0] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
                  uint32_t RSV_1                     : 7 ;     /*!< [7:1] : reserved. */
            __IOM uint32_t CRC                       : 1 ;     /*!< [8:8] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
                  uint32_t RSV_0                     : 23;     /*!< [31:9] : reserved. */
        } SOFTPRES0b;
    };

    union
    {
        __IOM uint32_t SOFTPRES1;  /*!< 0x00001908 */ 
       
        struct
        {
            __IOM uint32_t EMIF1                     : 1 ;     /*!< [0:0] : When this bit is set, only the control logic of the respective EMIF1 is reset. */
            __IOM uint32_t EMIF2                     : 1 ;     /*!< [1:1] : When this bit is set, only the control logic of the respective EMIF2 is reset. */
                  uint32_t RSV_0                     : 30;     /*!< [31:2] : reserved. */
        } SOFTPRES1b;
    };

    union
    {
        __IOM uint32_t SOFTPRES2;  /*!< 0x0000190c */ 
       
        struct
        {
            __IOM uint32_t EPWM1                     : 1 ;     /*!< [0:0] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t EPWM2                     : 1 ;     /*!< [1:1] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t EPWM3                     : 1 ;     /*!< [2:2] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t EPWM4                     : 1 ;     /*!< [3:3] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t EPWM5                     : 1 ;     /*!< [4:4] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t EPWM6                     : 1 ;     /*!< [5:5] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t EPWM7                     : 1 ;     /*!< [6:6] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t EPWM8                     : 1 ;     /*!< [7:7] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t EPWM9                     : 1 ;     /*!< [8:8] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t EPWM10                    : 1 ;     /*!< [9:9] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t EPWM11                    : 1 ;     /*!< [10:10] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t EPWM12                    : 1 ;     /*!< [11:11] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
                  uint32_t RSV_0                     : 20;     /*!< [31:12] : reserved. */
        } SOFTPRES2b;
    };

    union
    {
        __IOM uint32_t SOFTPRES3;  /*!< 0x00001910 */ 
       
        struct
        {
            __IOM uint32_t ECAP1                     : 1 ;     /*!< [0:0] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t ECAP2                     : 1 ;     /*!< [1:1] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t ECAP3                     : 1 ;     /*!< [2:2] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t ECAP4                     : 1 ;     /*!< [3:3] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t ECAP5                     : 1 ;     /*!< [4:4] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t ECAP6                     : 1 ;     /*!< [5:5] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
                  uint32_t RSV_0                     : 26;     /*!< [31:6] : reserved. */
        } SOFTPRES3b;
    };

    union
    {
        __IOM uint32_t SOFTPRES4;  /*!< 0x00001914 */ 
       
        struct
        {
            __IOM uint32_t EQEP1                     : 1 ;     /*!< [0:0] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t EQEP2                     : 1 ;     /*!< [1:1] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t EQEP3                     : 1 ;     /*!< [2:2] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
                  uint32_t RSV_0                     : 29;     /*!< [31:3] : reserved. */
        } SOFTPRES4b;
    };

    uint8_t    RSV_0X1918[4];   /*!< 0x00001918~0x0000191b : reserved */

    union
    {
        __IOM uint32_t SOFTPRES6;  /*!< 0x0000191c */ 
       
        struct
        {
            __IOM uint32_t SD1                       : 1 ;     /*!< [0:0] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t SD2                       : 1 ;     /*!< [1:1] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
                  uint32_t RSV_0                     : 30;     /*!< [31:2] : reserved. */
        } SOFTPRES6b;
    };

    union
    {
        __IOM uint32_t SOFTPRES7;  /*!< 0x00001920 */ 
       
        struct
        {
            __IOM uint32_t SCI_A                     : 1 ;     /*!< [0:0] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t SCI_B                     : 1 ;     /*!< [1:1] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t SCI_C                     : 1 ;     /*!< [2:2] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t SCI_D                     : 1 ;     /*!< [3:3] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
                  uint32_t RSV_0                     : 28;     /*!< [31:4] : reserved. */
        } SOFTPRES7b;
    };

    union
    {
        __IOM uint32_t SOFTPRES8;  /*!< 0x00001924 */ 
       
        struct
        {
            __IOM uint32_t SPI_A                     : 1 ;     /*!< [0:0] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t SPI_B                     : 1 ;     /*!< [1:1] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t SPI_C                     : 1 ;     /*!< [2:2] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
                  uint32_t RSV_0                     : 29;     /*!< [31:3] : reserved. */
        } SOFTPRES8b;
    };

    union
    {
        __IOM uint32_t SOFTPRES9;  /*!< 0x00001928 */ 
       
        struct
        {
            __IOM uint32_t I2C_A                     : 1 ;     /*!< [0:0] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t I2C_B                     : 1 ;     /*!< [1:1] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
                  uint32_t RSV_1                     : 14;     /*!< [15:2] : reserved. */
            __IOM uint32_t PMBUS_A                   : 1 ;     /*!< [16:16] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
                  uint32_t RSV_0                     : 15;     /*!< [31:17] : reserved. */
        } SOFTPRES9b;
    };

    union
    {
        __IOM uint32_t SOFTPRES10;  /*!< 0x0000192c */ 
       
        struct
        {
            __IOM uint32_t CAN_A                     : 1 ;     /*!< [0:0] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t CAN_B                     : 1 ;     /*!< [1:1] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t CAN_C                     : 1 ;     /*!< [2:2] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
                  uint32_t RSV_0                     : 29;     /*!< [31:3] : reserved. */
        } SOFTPRES10b;
    };

    union
    {
        __IOM uint32_t SOFTPRES11;  /*!< 0x00001930 */ 
       
        struct
        {
                  uint32_t RSV_1                     : 16;     /*!< [15:0] : reserved. */
            __IOM uint32_t USB_A                     : 1 ;     /*!< [16:16] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
                  uint32_t RSV_0                     : 15;     /*!< [31:17] : reserved. */
        } SOFTPRES11b;
    };

    uint8_t    RSV_0X1934[4];   /*!< 0x00001934~0x00001937 : reserved */

    union
    {
        __IOM uint32_t SOFTPRES13;  /*!< 0x00001938 */ 
       
        struct
        {
            __IOM uint32_t ADC_A                     : 1 ;     /*!< [0:0] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t ADC_B                     : 1 ;     /*!< [1:1] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t ADC_C                     : 1 ;     /*!< [2:2] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t ADC_D                     : 1 ;     /*!< [3:3] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
                  uint32_t RSV_0                     : 28;     /*!< [31:4] : reserved. */
        } SOFTPRES13b;
    };

    union
    {
        __IOM uint32_t SOFTPRES14;  /*!< 0x0000193c */ 
       
        struct
        {
            __IOM uint32_t CMPSS1                    : 1 ;     /*!< [0:0] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t CMPSS2                    : 1 ;     /*!< [1:1] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t CMPSS3                    : 1 ;     /*!< [2:2] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t CMPSS4                    : 1 ;     /*!< [3:3] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t CMPSS5                    : 1 ;     /*!< [4:4] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t CMPSS6                    : 1 ;     /*!< [5:5] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t CMPSS7                    : 1 ;     /*!< [6:6] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t CMPSS8                    : 1 ;     /*!< [7:7] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
                  uint32_t RSV_0                     : 24;     /*!< [31:8] : reserved. */
        } SOFTPRES14b;
    };

    uint8_t    RSV_0X1940[4];   /*!< 0x00001940~0x00001943 : reserved */

    union
    {
        __IOM uint32_t SOFTPRES16;  /*!< 0x00001944 */ 
       
        struct
        {
                  uint32_t RSV_1                     : 16;     /*!< [15:0] : reserved. */
            __IOM uint32_t DAC_A                     : 1 ;     /*!< [16:16] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t DAC_B                     : 1 ;     /*!< [17:17] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t DAC_C                     : 1 ;     /*!< [18:18] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
                  uint32_t RSV_0                     : 13;     /*!< [31:19] : reserved. */
        } SOFTPRES16b;
    };

    union
    {
        __IOM uint32_t SOFTPRES17;  /*!< 0x00001948 */ 
       
        struct
        {
            __IOM uint32_t CLB1                      : 1 ;     /*!< [0:0] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t CLB2                      : 1 ;     /*!< [1:1] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t CLB3                      : 1 ;     /*!< [2:2] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t CLB4                      : 1 ;     /*!< [3:3] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t CLB5                      : 1 ;     /*!< [4:4] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t CLB6                      : 1 ;     /*!< [5:5] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t CLB7                      : 1 ;     /*!< [6:6] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
            __IOM uint32_t CLB8                      : 1 ;     /*!< [7:7] : 1: Module is under reset                                        <br>  0: Module reset is determined by the normal device reset structure Reset type: CPU1. */
                  uint32_t RSV_0                     : 24;     /*!< [31:8] : reserved. */
        } SOFTPRES17b;
    };

    uint8_t    RSV_0X194C[96];   /*!< 0x0000194c~0x000019ab : reserved */

    union
    {
        __IOM uint32_t CPUSEL0;  /*!< 0x000019ac */ 
       
        struct
        {
            __IOM uint32_t EPWM1                     : 1 ;     /*!< [0:0] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t EPWM2                     : 1 ;     /*!< [1:1] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t EPWM3                     : 1 ;     /*!< [2:2] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t EPWM4                     : 1 ;     /*!< [3:3] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t EPWM5                     : 1 ;     /*!< [4:4] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t EPWM6                     : 1 ;     /*!< [5:5] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t EPWM7                     : 1 ;     /*!< [6:6] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t EPWM8                     : 1 ;     /*!< [7:7] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t EPWM9                     : 1 ;     /*!< [8:8] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t EPWM10                    : 1 ;     /*!< [9:9] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t EPWM11                    : 1 ;     /*!< [10:10] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t EPWM12                    : 1 ;     /*!< [11:11] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
                  uint32_t RSV_0                     : 20;     /*!< [31:12] : reserved. */
        } CPUSEL0b;
    };

    union
    {
        __IOM uint32_t CPUSEL1;  /*!< 0x000019b0 */ 
       
        struct
        {
            __IOM uint32_t ECAP1                     : 1 ;     /*!< [0:0] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t ECAP2                     : 1 ;     /*!< [1:1] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t ECAP3                     : 1 ;     /*!< [2:2] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t ECAP4                     : 1 ;     /*!< [3:3] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t ECAP5                     : 1 ;     /*!< [4:4] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t ECAP6                     : 1 ;     /*!< [5:5] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
                  uint32_t RSV_0                     : 26;     /*!< [31:6] : reserved. */
        } CPUSEL1b;
    };

    union
    {
        __IOM uint32_t CPUSEL2;  /*!< 0x000019b4 */ 
       
        struct
        {
            __IOM uint32_t EQEP1                     : 1 ;     /*!< [0:0] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t EQEP2                     : 1 ;     /*!< [1:1] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t EQEP3                     : 1 ;     /*!< [2:2] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
                  uint32_t RSV_0                     : 29;     /*!< [31:3] : reserved. */
        } CPUSEL2b;
    };

    uint8_t    RSV_0X19B8[4];   /*!< 0x000019b8~0x000019bb : reserved */

    union
    {
        __IOM uint32_t CPUSEL4;  /*!< 0x000019bc */ 
       
        struct
        {
            __IOM uint32_t SD1                       : 1 ;     /*!< [0:0] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t SD2                       : 1 ;     /*!< [1:1] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
                  uint32_t RSV_0                     : 30;     /*!< [31:2] : reserved. */
        } CPUSEL4b;
    };

    union
    {
        __IOM uint32_t CPUSEL5;  /*!< 0x000019c0 */ 
       
        struct
        {
            __IOM uint32_t SCI_A                     : 1 ;     /*!< [0:0] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t SCI_B                     : 1 ;     /*!< [1:1] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t SCI_C                     : 1 ;     /*!< [2:2] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t SCI_D                     : 1 ;     /*!< [3:3] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
                  uint32_t RSV_0                     : 28;     /*!< [31:4] : reserved. */
        } CPUSEL5b;
    };

    union
    {
        __IOM uint32_t CPUSEL6;  /*!< 0x000019c4 */ 
       
        struct
        {
            __IOM uint32_t SPI_A                     : 1 ;     /*!< [0:0] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t SPI_B                     : 1 ;     /*!< [1:1] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t SPI_C                     : 1 ;     /*!< [2:2] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
                  uint32_t RSV_0                     : 29;     /*!< [31:3] : reserved. */
        } CPUSEL6b;
    };

    union
    {
        __IOM uint32_t CPUSEL7;  /*!< 0x000019c8 */ 
       
        struct
        {
            __IOM uint32_t I2C_A                     : 1 ;     /*!< [0:0] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t I2C_B                     : 1 ;     /*!< [1:1] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
                  uint32_t RSV_1                     : 14;     /*!< [15:2] : reserved. */
            __IOM uint32_t PMBUS_A                   : 1 ;     /*!< [16:16] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
                  uint32_t RSV_0                     : 15;     /*!< [31:17] : reserved. */
        } CPUSEL7b;
    };

    union
    {
        __IOM uint32_t CPUSEL8;  /*!< 0x000019cc */ 
       
        struct
        {
            __IOM uint32_t CAN_A                     : 1 ;     /*!< [0:0] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t CAN_B                     : 1 ;     /*!< [1:1] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t CAN_C                     : 1 ;     /*!< [2:2] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
                  uint32_t RSV_1                     : 13;     /*!< [15:3] : reserved. */
            __IOM uint32_t USB_A                     : 1 ;     /*!< [16:16] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
                  uint32_t RSV_0                     : 15;     /*!< [31:17] : reserved. */
        } CPUSEL8b;
    };

    uint8_t    RSV_0X19D0[8];   /*!< 0x000019d0~0x000019d7 : reserved */

    union
    {
        __IOM uint32_t CPUSEL11;  /*!< 0x000019d8 */ 
       
        struct
        {
            __IOM uint32_t ADC_A                     : 1 ;     /*!< [0:0] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Note:                                                           <br>  [1] These CPUSEL bits affect the ownership of only ADC Configuration registers by CPU1 or CPU2 (which are mapped on the mapped to VBUS32). */
            __IOM uint32_t ADC_B                     : 1 ;     /*!< [1:1] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Note:                                                           <br>  [1] These CPUSEL bits affect the ownership of only ADC Configuration registers by CPU1 or CPU2 (which are mapped on the mapped to VBUS32). */
            __IOM uint32_t ADC_C                     : 1 ;     /*!< [2:2] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Note:                                                           <br>  [1] These CPUSEL bits affect the ownership of only ADC Configuration registers by CPU1 or CPU2 (which are mapped on the mapped to VBUS32). */
            __IOM uint32_t ADC_D                     : 1 ;     /*!< [3:3] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Note:                                                           <br>  [1] These CPUSEL bits affect the ownership of only ADC Configuration registers by CPU1 or CPU2 (which are mapped on the mapped to VBUS32). */
                  uint32_t RSV_0                     : 28;     /*!< [31:4] : reserved. */
        } CPUSEL11b;
    };

    union
    {
        __IOM uint32_t CPUSEL12;  /*!< 0x000019dc */ 
       
        struct
        {
            __IOM uint32_t CMPSS1                    : 1 ;     /*!< [0:0] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t CMPSS2                    : 1 ;     /*!< [1:1] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t CMPSS3                    : 1 ;     /*!< [2:2] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t CMPSS4                    : 1 ;     /*!< [3:3] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t CMPSS5                    : 1 ;     /*!< [4:4] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t CMPSS6                    : 1 ;     /*!< [5:5] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t CMPSS7                    : 1 ;     /*!< [6:6] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t CMPSS8                    : 1 ;     /*!< [7:7] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
                  uint32_t RSV_0                     : 24;     /*!< [31:8] : reserved. */
        } CPUSEL12b;
    };

    uint8_t    RSV_0X19E0[4];   /*!< 0x000019e0~0x000019e3 : reserved */

    union
    {
        __IOM uint32_t CPUSEL14;  /*!< 0x000019e4 */ 
       
        struct
        {
                  uint32_t RSV_1                     : 16;     /*!< [15:0] : reserved. */
            __IOM uint32_t DAC_A                     : 1 ;     /*!< [16:16] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t DAC_B                     : 1 ;     /*!< [17:17] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t DAC_C                     : 1 ;     /*!< [18:18] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
                  uint32_t RSV_0                     : 13;     /*!< [31:19] : reserved. */
        } CPUSEL14b;
    };

    union
    {
        __IOM uint32_t CPUSEL15;  /*!< 0x000019e8 */ 
       
        struct
        {
            __IOM uint32_t CLB1                      : 1 ;     /*!< [0:0] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t CLB2                      : 1 ;     /*!< [1:1] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t CLB3                      : 1 ;     /*!< [2:2] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t CLB4                      : 1 ;     /*!< [3:3] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t CLB5                      : 1 ;     /*!< [4:4] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t CLB6                      : 1 ;     /*!< [5:5] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t CLB7                      : 1 ;     /*!< [6:6] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
            __IOM uint32_t CLB8                      : 1 ;     /*!< [7:7] : 0: Connected to CPU1 1: Connected to CPU2                       <br>  Reset type: CPU1. */
                  uint32_t RSV_0                     : 24;     /*!< [31:8] : reserved. */
        } CPUSEL15b;
    };

    uint8_t    RSV_0X19EC[88];   /*!< 0x000019ec~0x00001a43 : reserved */

    union
    {
        __IOM uint32_t CPU2RESCTL;  /*!< 0x00001a44 */ 
       
        struct
        {
            __IOM uint32_t CPU2RESET                 : 1 ;     /*!< [0:0] : This bit controls the reset input of CPU2 core. */
                  uint32_t RSV_0                     : 15;     /*!< [15:1] : reserved. */
            __IM  uint32_t KEY                       : 16;     /*!< [31:16] : Write to this register succeeds only if this field is written with a value of 0xa5a5<br>  Note:                                                           <br>  [1] Due to this KEY, only 32-bit writes will succeed (provided the KEY matches). */
        } CPU2RESCTLb;
    };

    union
    {
        __IOM uint16_t RSTSTAT;  /*!< 0x00001a48 */ 
       
        struct
        {
            __IM  uint16_t CPU2RES                   : 1 ;     /*!< [0:0] : Reset status of CPU2 to CPU1                                    <br>  0: CPU2 core is in reset                                        <br>  1: CPU2 core is out of reset Reset type: CPU1. */
            __IOM uint16_t CPU2NMIWDRST              : 1 ;     /*!< [1:1] : Indicates whether a CPU2. */
                  uint16_t RSV_0                     : 14;     /*!< [15:2] : reserved. */
        } RSTSTATb;
    };

    union
    {
        __IM uint16_t LPMSTAT;  /*!< 0x00001a4a */ 
       
        struct
        {
            __IM  uint16_t CPU2LPMSTAT               : 2 ;     /*!< [1:0] : These bits indicate the power mode CPU2                         <br>  00: CPU2 is in ACTIVE mode                                      <br>  01: CPU2 is in IDLE mode                                        <br>  10: CPU2 is in STANDBY mode                                     <br>  11: Reserved                                                    <br>  Reset type: CPU1. */
                  uint16_t RSV_0                     : 14;     /*!< [15:2] : reserved. */
        } LPMSTATb;
    };

    uint8_t    RSV_0X1A4C[12];   /*!< 0x00001a4c~0x00001a57 : reserved */

    union
    {
         uint32_t SYSDBGCTL;  /*!< 0x00001a58 */ 
       
        struct
        {
                  uint32_t RSV_0                     : 32;     /*!< [31:0] : reserved. */
        } SYSDBGCTLb;
    };

    uint8_t    RSV_0X1A5C[36];   /*!< 0x00001a5c~0x00001a7f : reserved */

    union
    {
        __IOM uint32_t HALT2PERCTRL;  /*!< 0x00001a80 */ 
       
        struct
        {
            __IOM uint32_t HALT2PERBASESEL           : 1 ;     /*!< [0:0] : Halt to peripheral based on peripheral cpu_sel :                <br>  0 : cpu1 halt and cpu2 halt both affect the peripheral, dont care cpu_sel<br>  1 : select halt signal from cpu1 and cpu2 based on the peripheral's cpu_sel<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t HALT2TIM                  : 1 ;     /*!< [1:1] : Halt to TIM disable :                                           <br>  0 : halt signal enable                                          <br>  1 : halt signal disable (tie low)                               <br>  CPU1 TIM is on CPU1 subsystem, so CPU2 Halt cannot affect CPU1 TIM. */
            __IOM uint32_t HALT2DMA                  : 1 ;     /*!< [2:2] : Halt to DMA disable :                                           <br>  0 : halt signal enable                                          <br>  1 : halt signal disable (tie low)                               <br>  CPU1 DMA is on CPU1 subsystem, so CPU2 Halt cannot affect CPU1 DMA. */
            __IOM uint32_t HALT2PWM                  : 1 ;     /*!< [3:3] : Halt to PWM disable :                                           <br>  1 : halt signal disable (tie low)                               <br>  0 : halt signal enable                                          <br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t HALT2CAP                  : 1 ;     /*!< [4:4] : Halt to CAP disable :                                           <br>  1 : halt signal disable (tie low)                               <br>  0 : halt signal enable                                          <br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t HALT2QEP                  : 1 ;     /*!< [5:5] : Halt to QEP disable :                                           <br>  1 : halt signal disable (tie low)                               <br>  0 : halt signal enable                                          <br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t HALT2CMPSS                : 1 ;     /*!< [6:6] : Halt to CMPSS disable :                                         <br>  1 : halt signal disable (tie low)                               <br>  0 : halt signal enable                                          <br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t HALT2CPU1IPC              : 1 ;     /*!< [7:7] : Halt to CPU1toCPU2 IPC disable :                                <br>  1 : halt signal disable (tie low)                               <br>  0 : halt signal enable                                          <br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t HALT2CPU2IPC              : 1 ;     /*!< [8:8] : Halt to CPU2toCPU1 IPC disable :                                <br>  1 : halt signal disable (tie low)                               <br>  0 : halt signal enable                                          <br>  Reset type: XRSn                                                <br>. */
                  uint32_t RSV_0                     : 23;     /*!< [31:9] : reserved. */
        } HALT2PERCTRLb;
    };

    union
    {
        __IOM uint32_t EFLASH1PROT;  /*!< 0x00001a84 */ 
       
        struct
        {
            __IOM uint32_t EFLASH1PROT               : 1 ;     /*!< [0:0] : EFLASH1 Protection:                                             <br>  1 : EFLASH1 owner is based on PARTIDL. */
                  uint32_t RSV_0                     : 31;     /*!< [31:1] : reserved. */
        } EFLASH1PROTb;
    };

    union
    {
        __IOM uint32_t GS_SRAM_CFG0;  /*!< 0x00001a88 */ 
       
        struct
        {
            __IOM uint32_t GS_SRAM0_CFG              : 15;     /*!< [14:0] : 14:13 - RA                                                      <br>  12:10 - WA                                                      <br>  9:7      - WPULSE                                               <br>  6:3      - RM                                                   <br>  2         - RME                                                 <br>  1         - LS                                                  <br>  0         - TEST1                                               <br>. */
                  uint32_t RSV_1                     : 1 ;     /*!< [15:15] : reserved. */
            __IOM uint32_t GS_SRAM1_CFG              : 15;     /*!< [30:16] : 14:13 - RA                                                      <br>  12:10 - WA                                                      <br>  9:7      - WPULSE                                               <br>  6:3      - RM                                                   <br>  2         - RME                                                 <br>  1         - LS                                                  <br>  0         - TEST1                                               <br>. */
                  uint32_t RSV_0                     : 1 ;     /*!< [31:31] : reserved. */
        } GS_SRAM_CFG0b;
    };

    union
    {
        __IOM uint32_t GS_SRAM_CFG1;  /*!< 0x00001a8c */ 
       
        struct
        {
            __IOM uint32_t GS_SRAM2_CFG              : 15;     /*!< [14:0] : 14:13 - RA                                                      <br>  12:10 - WA                                                      <br>  9:7      - WPULSE                                               <br>  6:3      - RM                                                   <br>  2         - RME                                                 <br>  1         - LS                                                  <br>  0         - TEST1                                               <br>. */
                  uint32_t RSV_1                     : 1 ;     /*!< [15:15] : reserved. */
            __IOM uint32_t GS_SRAM3_CFG              : 15;     /*!< [30:16] : 14:13 - RA                                                      <br>  12:10 - WA                                                      <br>  9:7      - WPULSE                                               <br>  6:3      - RM                                                   <br>  2         - RME                                                 <br>  1         - LS                                                  <br>  0         - TEST1                                               <br>. */
                  uint32_t RSV_0                     : 1 ;     /*!< [31:31] : reserved. */
        } GS_SRAM_CFG1b;
    };

    union
    {
        __IOM uint32_t GS_SRAM_CFG2;  /*!< 0x00001a90 */ 
       
        struct
        {
            __IOM uint32_t GS_SRAM4_CFG              : 15;     /*!< [14:0] : 14:13 - RA                                                      <br>  12:10 - WA                                                      <br>  9:7      - WPULSE                                               <br>  6:3      - RM                                                   <br>  2         - RME                                                 <br>  1         - LS                                                  <br>  0         - TEST1                                               <br>. */
                  uint32_t RSV_1                     : 1 ;     /*!< [15:15] : reserved. */
            __IOM uint32_t GS_SRAM5_CFG              : 15;     /*!< [30:16] : 14:13 - RA                                                      <br>  12:10 - WA                                                      <br>  9:7      - WPULSE                                               <br>  6:3      - RM                                                   <br>  2         - RME                                                 <br>  1         - LS                                                  <br>  0         - TEST1                                               <br>. */
                  uint32_t RSV_0                     : 1 ;     /*!< [31:31] : reserved. */
        } GS_SRAM_CFG2b;
    };

    union
    {
        __IOM uint32_t GS_SRAM_CFG3;  /*!< 0x00001a94 */ 
       
        struct
        {
            __IOM uint32_t GS_SRAM6_CFG              : 15;     /*!< [14:0] : 14:13 - RA                                                      <br>  12:10 - WA                                                      <br>  9:7      - WPULSE                                               <br>  6:3      - RM                                                   <br>  2         - RME                                                 <br>  1         - LS                                                  <br>  0         - TEST1                                               <br>. */
                  uint32_t RSV_1                     : 1 ;     /*!< [15:15] : reserved. */
            __IOM uint32_t GS_SRAM7_CFG              : 15;     /*!< [30:16] : 14:13 - RA                                                      <br>  12:10 - WA                                                      <br>  9:7      - WPULSE                                               <br>  6:3      - RM                                                   <br>  2         - RME                                                 <br>  1         - LS                                                  <br>  0         - TEST1                                               <br>. */
                  uint32_t RSV_0                     : 1 ;     /*!< [31:31] : reserved. */
        } GS_SRAM_CFG3b;
    };

    union
    {
        __IOM uint32_t GS_SRAM_CFG4;  /*!< 0x00001a98 */ 
       
        struct
        {
            __IOM uint32_t GS_SRAM8_CFG              : 15;     /*!< [14:0] : 14:13 - RA                                                      <br>  12:10 - WA                                                      <br>  9:7      - WPULSE                                               <br>  6:3      - RM                                                   <br>  2         - RME                                                 <br>  1         - LS                                                  <br>  0         - TEST1                                               <br>. */
                  uint32_t RSV_1                     : 1 ;     /*!< [15:15] : reserved. */
            __IOM uint32_t GS_SRAM9_CFG              : 15;     /*!< [30:16] : 14:13 - RA                                                      <br>  12:10 - WA                                                      <br>  9:7      - WPULSE                                               <br>  6:3      - RM                                                   <br>  2         - RME                                                 <br>  1         - LS                                                  <br>  0         - TEST1                                               <br>. */
                  uint32_t RSV_0                     : 1 ;     /*!< [31:31] : reserved. */
        } GS_SRAM_CFG4b;
    };

    uint8_t    RSV_0X1A9C[4];   /*!< 0x00001a9c~0x00001a9f : reserved */

    union
    {
        __IOM uint32_t GS_SRAM_CFG5;  /*!< 0x00001aa0 */ 
       
        struct
        {
            __IOM uint32_t GS_SRAM10_CFG             : 15;     /*!< [14:0] : 14:13 - RA                                                      <br>  12:10 - WA                                                      <br>  9:7      - WPULSE                                               <br>  6:3      - RM                                                   <br>  2         - RME                                                 <br>  1         - LS                                                  <br>  0         - TEST1                                               <br>. */
                  uint32_t RSV_1                     : 1 ;     /*!< [15:15] : reserved. */
            __IOM uint32_t GS_SRAM11_CFG             : 15;     /*!< [30:16] : 14:13 - RA                                                      <br>  12:10 - WA                                                      <br>  9:7      - WPULSE                                               <br>  6:3      - RM                                                   <br>  2         - RME                                                 <br>  1         - LS                                                  <br>  0         - TEST1                                               <br>. */
                  uint32_t RSV_0                     : 1 ;     /*!< [31:31] : reserved. */
        } GS_SRAM_CFG5b;
    };

    union
    {
        __IOM uint32_t GS_SRAM_CFG6;  /*!< 0x00001aa4 */ 
       
        struct
        {
            __IOM uint32_t GS_SRAM12_CFG             : 15;     /*!< [14:0] : 14:13 - RA                                                      <br>  12:10 - WA                                                      <br>  9:7      - WPULSE                                               <br>  6:3      - RM                                                   <br>  2         - RME                                                 <br>  1         - LS                                                  <br>  0         - TEST1                                               <br>. */
                  uint32_t RSV_1                     : 1 ;     /*!< [15:15] : reserved. */
            __IOM uint32_t GS_SRAM13_CFG             : 15;     /*!< [30:16] : 14:13 - RA                                                      <br>  12:10 - WA                                                      <br>  9:7      - WPULSE                                               <br>  6:3      - RM                                                   <br>  2         - RME                                                 <br>  1         - LS                                                  <br>  0         - TEST1                                               <br>. */
                  uint32_t RSV_0                     : 1 ;     /*!< [31:31] : reserved. */
        } GS_SRAM_CFG6b;
    };

    union
    {
        __IOM uint32_t GS_SRAM_CFG7;  /*!< 0x00001aa8 */ 
       
        struct
        {
            __IOM uint32_t GS_SRAM14_CFG             : 15;     /*!< [14:0] : 14:13 - RA                                                      <br>  12:10 - WA                                                      <br>  9:7      - WPULSE                                               <br>  6:3      - RM                                                   <br>  2         - RME                                                 <br>  1         - LS                                                  <br>  0         - TEST1                                               <br>. */
                  uint32_t RSV_1                     : 1 ;     /*!< [15:15] : reserved. */
            __IOM uint32_t GS_SRAM15_CFG             : 15;     /*!< [30:16] : 14:13 - RA                                                      <br>  12:10 - WA                                                      <br>  9:7      - WPULSE                                               <br>  6:3      - RM                                                   <br>  2         - RME                                                 <br>  1         - LS                                                  <br>  0         - TEST1                                               <br>. */
                  uint32_t RSV_0                     : 1 ;     /*!< [31:31] : reserved. */
        } GS_SRAM_CFG7b;
    };

    union
    {
        __IOM uint32_t ROM_CFG;  /*!< 0x00001aac */ 
       
        struct
        {
            __IOM uint32_t CPU1_ROM_CFG              : 7 ;     /*!< [6:0] : 6:3      - RM                                                   <br>  2         - RME                                                 <br>  1         - LS                                                  <br>  0         - TEST1                                               <br>. */
                  uint32_t RSV_2                     : 1 ;     /*!< [7:7] : reserved. */
            __IOM uint32_t CPU2_ROM_CFG              : 7 ;     /*!< [14:8] : 6:3      - RM                                                   <br>  2         - RME                                                 <br>  1         - LS                                                  <br>  0         - TEST1                                               <br>. */
                  uint32_t RSV_1                     : 1 ;     /*!< [15:15] : reserved. */
            __IOM uint32_t CANC_MSGRAM_CFG           : 15;     /*!< [30:16] : 14:13 - RA                                                      <br>  12:10 - WA                                                      <br>  9:7      - WPULSE                                               <br>  6:3      - RM                                                   <br>  2         - RME                                                 <br>  1         - LS                                                  <br>  0         - TEST1                                               <br>. */
                  uint32_t RSV_0                     : 1 ;     /*!< [31:31] : reserved. */
        } ROM_CFGb;
    };

    union
    {
        __IOM uint32_t CAN_MSGRAM_CFG;  /*!< 0x00001ab0 */ 
       
        struct
        {
            __IOM uint32_t CANA_MSGRAM_CFG           : 15;     /*!< [14:0] : 14:13 - RA                                                      <br>  12:10 - WA                                                      <br>  9:7      - WPULSE                                               <br>  6:3      - RM                                                   <br>  2         - RME                                                 <br>  1         - LS                                                  <br>  0         - TEST1                                               <br>. */
                  uint32_t RSV_1                     : 1 ;     /*!< [15:15] : reserved. */
            __IOM uint32_t CANB_MSGRAM_CFG           : 15;     /*!< [30:16] : 14:13 - RA                                                      <br>  12:10 - WA                                                      <br>  9:7      - WPULSE                                               <br>  6:3      - RM                                                   <br>  2         - RME                                                 <br>  1         - LS                                                  <br>  0         - TEST1                                               <br>. */
                  uint32_t RSV_0                     : 1 ;     /*!< [31:31] : reserved. */
        } CAN_MSGRAM_CFGb;
    };

    union
    {
        __IOM uint32_t USB_SRAM_CFG;  /*!< 0x00001ab4 */ 
       
        struct
        {
            __IOM uint32_t USBA_SRAM_CFG             : 15;     /*!< [14:0] : 14:13 - RA                                                      <br>  12:10 - WA                                                      <br>  9:7      - WPULSE                                               <br>  6:3      - RM                                                   <br>  2         - RME                                                 <br>  1         - LS                                                  <br>  0         - TEST1                                               <br>. */
                  uint32_t RSV_0                     : 17;     /*!< [31:15] : reserved. */
        } USB_SRAM_CFGb;
    };

    union
    {
        __IOM uint32_t SRAM_ECC_CTRL;  /*!< 0x00001ab8 */ 
       
        struct
        {
            __IOM uint32_t SRAM_ECC_DIS              : 1 ;     /*!< [0:0] : when 1, ecc is disabled. */
                  uint32_t RSV_0                     : 31;     /*!< [31:1] : reserved. */
        } SRAM_ECC_CTRLb;
    };

    uint8_t    RSV_0X1ABC[4];   /*!< 0x00001abc~0x00001abf : reserved */

    union
    {
        __IOM uint32_t CPU1_MISC_CFG0;  /*!< 0x00001ac0 */ 
       
        struct
        {
            __IOM uint32_t CPU1_MISC_CFG0            : 32;     /*!< [31:0] : CPU1 misc configuration                                         <br>  0         - initahbpen                                          <br>  3:1      - cfgahbpsz                                            <br>  29:4    - cfgstcalib                                            <br>  31:30  - initcmen                                               <br>. */
        } CPU1_MISC_CFG0b;
    };

    union
    {
        __IOM uint32_t CPU1_MISC_CFG1;  /*!< 0x00001ac4 */ 
       
        struct
        {
            __IOM uint32_t CPU1_MISC_CFG1            : 32;     /*!< [31:0] : CPU1 misc configuration                                         <br>  1:0       - initrmwen，default 1h                                <br>  3:2       - initretryen，default 0h                              <br>  7:4       - reserved，default 0h                                 <br>  22:8     - itcm_misc，default 101Ch                              <br>  23        - reserved，default 0h                                 <br>  24        - wicenreq，default 0h                                 <br>  25        - edbgrq，default 0h                                   <br>  26        - dbgrestart，default 0h                               <br>  27        - niden，default 1h                                    <br>  28        - dbgen，default 1h                                    <br>  29        - sleepholdreqn，default 1h                            <br>  30        - genev，default 0h                                    <br>. */
        } CPU1_MISC_CFG1b;
    };

    union
    {
        __IOM uint32_t CPU1_MISC_CFG2;  /*!< 0x00001ac8 */ 
       
        struct
        {
            __IOM uint32_t CPU1_MISC_CFG2            : 32;     /*!< [31:0] : CPU1 misc configuration                                         <br>  14:0       - dtcm0_misc                                         <br>  30:16     - dtcm1_misc                                          <br>. */
        } CPU1_MISC_CFG2b;
    };

    union
    {
        __IOM uint32_t CPU1_MISC_CFG3;  /*!< 0x00001acc */ 
       
        struct
        {
            __IOM uint32_t CPU1_MISC_CFG3            : 32;     /*!< [31:0] : CPU1 misc configuration                                         <br>  14:0       - icache data bank0 misc                             <br>  30:16     - icache data bank1 misc                              <br>. */
        } CPU1_MISC_CFG3b;
    };

    union
    {
        __IOM uint32_t CPU1_MISC_CFG4;  /*!< 0x00001ad0 */ 
       
        struct
        {
            __IOM uint32_t CPU1_MISC_CFG4            : 32;     /*!< [31:0] : CPU1 misc configuration                                         <br>  14:0       - icache tag bank0 misc                              <br>  30:16     - icache tag bank1 misc                               <br>. */
        } CPU1_MISC_CFG4b;
    };

    union
    {
        __IOM uint32_t CPU2_MISC_CFG0;  /*!< 0x00001ad4 */ 
       
        struct
        {
            __IOM uint32_t CPU2_MISC_CFG0            : 32;     /*!< [31:0] : CPU2 misc configuration                                         <br>  0         - initahbpen                                          <br>  3:1      - cfgahbpsz                                            <br>  29:4    - cfgstcalib                                            <br>  31:30  - initcmen                                               <br>. */
        } CPU2_MISC_CFG0b;
    };

    union
    {
        __IOM uint32_t CPU2_MISC_CFG1;  /*!< 0x00001ad8 */ 
       
        struct
        {
            __IOM uint32_t CPU2_MISC_CFG1            : 32;     /*!< [31:0] : CPU2 misc configuration                                         <br>  1:0       - initrmwen，default 1h                                <br>  3:2       - initretryen，default 0h                              <br>  7:4       - reserved，default 0h                                 <br>  22:8     - itcm_misc，default 101Ch                              <br>  23        - reserved，default 0h                                 <br>  24        - wicenreq，default 0h                                 <br>  25        - edbgrq，default 0h                                   <br>  26        - dbgrestart，default 0h                               <br>  27        - niden，default 1h                                    <br>  28        - dbgen，default 1h                                    <br>  29        - sleepholdreqn，default 1h                            <br>  30        - genev，default 0h                                    <br>. */
        } CPU2_MISC_CFG1b;
    };

    uint8_t    RSV_0X1ADC[4];   /*!< 0x00001adc~0x00001adf : reserved */

    union
    {
        __IOM uint32_t CPU2_MISC_CFG2;  /*!< 0x00001ae0 */ 
       
        struct
        {
            __IOM uint32_t CPU2_MISC_CFG2            : 32;     /*!< [31:0] : CPU2 misc configuration                                         <br>  14:0       - dtcm0_misc                                         <br>  30:16     - dtcm1_misc                                          <br>. */
        } CPU2_MISC_CFG2b;
    };

    union
    {
        __IOM uint32_t CPU2_MISC_CFG3;  /*!< 0x00001ae4 */ 
       
        struct
        {
            __IOM uint32_t CPU2_MISC_CFG3            : 32;     /*!< [31:0] : CPU2 misc configuration                                         <br>  14:0       - icache data bank0 misc                             <br>  30:16     - icache data bank1 misc                              <br>. */
        } CPU2_MISC_CFG3b;
    };

    union
    {
        __IOM uint32_t CPU2_MISC_CFG4;  /*!< 0x00001ae8 */ 
       
        struct
        {
            __IOM uint32_t CPU2_MISC_CFG4            : 32;     /*!< [31:0] : CPU2 misc configuration                                         <br>  14:0       - icache tag bank0 misc                              <br>  30:16     - icache tag bank1 misc                               <br>. */
        } CPU2_MISC_CFG4b;
    };

    union
    {
        __IM uint32_t CPU1_MISC_STS;  /*!< 0x00001aec */ 
       
        struct
        {
            __IM  uint32_t CPU1_MISC_STS             : 12;     /*!< [11:0] : CPU1 misc status                                                <br>  0         - dbgrestarted                                        <br>  1         - halted                                              <br>  2         - lockup                                              <br>  3         - safetogatehclk                                      <br>  4         - sleepdeep                                           <br>  5         - sleepholdackn                                       <br>  6         - sleeping                                            <br>  7         - sysresetreq                                         <br>  8         - txev                                                <br>  9         - wakeup                                              <br>  10       - wicenack                                             <br>  11       - ahbsrdy                                              <br>. */
                  uint32_t RSV_0                     : 20;     /*!< [31:12] : reserved. */
        } CPU1_MISC_STSb;
    };

    union
    {
        __IM uint32_t CPU2_MISC_STS;  /*!< 0x00001af0 */ 
       
        struct
        {
            __IM  uint32_t CPU2_MISC_STS             : 12;     /*!< [11:0] : CPU2 misc status                                                <br>  0         - dbgrestarted                                        <br>  1         - halted                                              <br>  2         - lockup                                              <br>  3         - safetogatehclk                                      <br>  4         - sleepdeep                                           <br>  5         - sleepholdackn                                       <br>  6         - sleeping                                            <br>  7         - sysresetreq                                         <br>  8         - txev                                                <br>  9         - wakeup                                              <br>  10       - wicenack                                             <br>  11       - ahbsrdy                                              <br>. */
                  uint32_t RSV_0                     : 20;     /*!< [31:12] : reserved. */
        } CPU2_MISC_STSb;
    };

    union
    {
        __IOM uint32_t DAP_MISC;  /*!< 0x00001af4 */ 
       
        struct
        {
            __IOM uint32_t DAP_MISC_CFG              : 10;     /*!< [9:0] : 3:0 - INSTANCEID                                                <br>  4    - dbgen_ap_cpu1                                            <br>  5    - dbgen_ap_cpu2                                            <br>  6    - dbgen_ap_sys                                             <br>  7    - spiden_ap_cpu1                                           <br>  8    - spiden_ap_cpu2                                           <br>  9    - spiden_ap_sys                                            <br>. */
            __IM  uint32_t JTAGTOP                   : 1 ;     /*!< [10:10] : JTAGTOP. */
            __IM  uint32_t JTAGNSW                   : 1 ;     /*!< [11:11] : JTAGNSW. */
                  uint32_t RSV_0                     : 20;     /*!< [31:12] : reserved. */
        } DAP_MISCb;
    };

    uint8_t    RSV_0X1AF8[8];   /*!< 0x00001af8~0x00001aff : reserved */

    union
    {
        __IOM uint32_t HTDEVLOCK;  /*!< 0x00001b00 */ 
       
        struct
        {
            __IOM uint32_t HTDEVLOCK                 : 1 ;     /*!< [0:0] : Lock for ID, DC0~20 and PERCNF register:                        <br>  1 : Register is locked                                          <br>  0 : Register is unlocked                                        <br>  Reset type: XRSn                                                <br>. */
                  uint32_t RSV_0                     : 31;     /*!< [31:1] : reserved. */
        } HTDEVLOCKb;
    };

    union
    {
        __IOM uint32_t HTDBGSEL;  /*!< 0x00001b04 */ 
       
        struct
        {
            __IOM uint32_t DBGSEL                    : 16;     /*!< [15:0] : debug selection. */
            __IOM uint32_t NORMAL_DBG_ROTATE         : 4 ;     /*!< [19:16] : rotate control for normal debug port. */
            __IOM uint32_t EXTEND_DBG_ROTATE         : 4 ;     /*!< [23:20] : rotate control for extend debug port. */
                  uint32_t RSV_0                     : 8 ;     /*!< [31:24] : reserved. */
        } HTDBGSELb;
    };

    union
    {
        __IOM uint32_t CPURSTCTRL;  /*!< 0x00001b08 */ 
       
        struct
        {
            __IOM uint32_t CPU1_SYSRST_CNT           : 8 ;     /*!< [7:0] : counter for cpu1 system reset when cpu1 core request system reset. */
            __IOM uint32_t CPU2_SYSRST_CNT           : 8 ;     /*!< [15:8] : counter for cpu2 system reset when cpu2 core request system reset. */
            __IOM uint32_t CPU1_CORERST_CNT          : 8 ;     /*!< [23:16] : cpu1 core reset delay counter. */
            __IOM uint32_t CPU2_CORERST_CNT          : 8 ;     /*!< [31:24] : cpu2 core reset delay counter. */
        } CPURSTCTRLb;
    };

    union
    {
        __IOM uint32_t CANDEBUG;  /*!< 0x00001b0c */ 
       
        struct
        {
            __IOM uint32_t CAN_A_DIS_MODI            : 1 ;     /*!< [0:0] : disable modification on read for CAN. */
            __IOM uint32_t CAN_B_DIS_MODI            : 1 ;     /*!< [1:1] : disable modification on read for CAN. */
            __IOM uint32_t CAN_C_DIS_MODI            : 1 ;     /*!< [2:2] : disable modification on read for CAN. */
                  uint32_t RSV_0                     : 29;     /*!< [31:3] : reserved. */
        } CANDEBUGb;
    };

    union
    {
        __IOM uint32_t CPU2INITVTOR;  /*!< 0x00001b10 */ 
       
        struct
        {
            __IOM uint32_t CPU2INITVTOR              : 32;     /*!< [31:0] : Initial vector for CPU2 boot, default is CPU2 bootrom. */
        } CPU2INITVTORb;
    };

    union
    {
        __IOM uint32_t SPIXIPENABLE;  /*!< 0x00001b14 */ 
       
        struct
        {
            __IOM uint32_t SPI_A_XIP_EN              : 1 ;     /*!< [0:0] : XIP enable for SPI_A. */
            __IOM uint32_t SPI_B_XIP_EN              : 1 ;     /*!< [1:1] : XIP enable for SPI_B. */
            __IOM uint32_t SPI_C_XIP_EN              : 1 ;     /*!< [2:2] : XIP enable for SPI_C. */
                  uint32_t RSV_0                     : 29;     /*!< [31:3] : reserved. */
        } SPIXIPENABLEb;
    };

    union
    {
        __IOM uint32_t HTDBGSEL1;  /*!< 0x00001b18 */ 
       
        struct
        {
            __IOM uint32_t IOMUX_DBG_SEL             : 16;     /*!< [15:0] : iomux debug selection. */
            __IOM uint32_t GS0TO7_DBG_SEL            : 3 ;     /*!< [18:16] : gs0~8 debug selection. */
            __IOM uint32_t GS8TO15_DBG_SEL           : 3 ;     /*!< [21:19] : gs8~15 debug selection. */
                  uint32_t RSV_0                     : 2 ;     /*!< [23:22] : reserved. */
            __IOM uint32_t SYSCTRL_DBG_SEL           : 8 ;     /*!< [31:24] : sysctrl debug selection. */
        } HTDBGSEL1b;
    };

    union
    {
        __IOM uint32_t NMIWDTRSTCTRL;  /*!< 0x00001b1c */ 
       
        struct
        {
            __IOM uint32_t CPU1_NMIWDRS_CNT          : 8 ;     /*!< [7:0] : counter for cpu1 nmi wdt timeout reset. */
            __IOM uint32_t CPU2_NMIWDRS_CNT          : 8 ;     /*!< [15:8] : counter for cpu2 nmi wdt timeout reset. */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } NMIWDTRSTCTRLb;
    };
} DEV_CFG_REGS_Type;

/*! \brief ANALOG_SUBSYS_REGS register */
typedef struct {
    uint8_t    RSV_0X1C00[64];   /*!< 0x00001c00~0x00001c3f : reserved */

    union
    {
        __IOM uint32_t INTOSC1TRIM;  /*!< 0x00001c40 */ 
       
        struct
        {
            __IOM uint32_t VALFINETRIM               : 8 ;     /*!< [7:0] : Oscillator Value Fine Trim Bits. */
                  uint32_t RSV_0                     : 24;     /*!< [31:8] : reserved. */
        } INTOSC1TRIMb;
    };

    union
    {
        __IOM uint32_t INTOSC2TRIM;  /*!< 0x00001c44 */ 
       
        struct
        {
            __IOM uint32_t VALFINETRIM               : 8 ;     /*!< [7:0] : Oscillator Value Fine Trim Bits. */
                  uint32_t RSV_0                     : 24;     /*!< [31:8] : reserved. */
        } INTOSC2TRIMb;
    };

    uint8_t    RSV_0X1C48[4];   /*!< 0x00001c48~0x00001c4b : reserved */

    union
    {
        __IOM uint32_t TSNSCTL;  /*!< 0x00001c4c */ 
       
        struct
        {
            __IOM uint32_t TS_ENABLE                 : 1 ;     /*!< [0:0] : Temperature Sensor Enable. */
                  uint32_t RSV_0                     : 31;     /*!< [31:1] : reserved. */
        } TSNSCTLb;
    };

    uint8_t    RSV_0X1C50[12];   /*!< 0x00001c50~0x00001c5b : reserved */

    union
    {
        __IOM uint32_t LOCK;  /*!< 0x00001c5c */ 
       
        struct
        {
                  uint32_t RSV_1                     : 3 ;     /*!< [2:0] : reserved. */
            __IOM uint32_t TSNSCTL                   : 1 ;     /*!< [3:3] : Temperature Sensor Control Register Lock. */
                  uint32_t RSV_0                     : 28;     /*!< [31:4] : reserved. */
        } LOCKb;
    };

    union
    {
        __IOM uint32_t NVRLOCK;  /*!< 0x00001c60 */ 
       
        struct
        {
            __IOM uint32_t NVRLOCK                   : 32;     /*!< [31:0] : NVR LOCK                                                        <br>  when 32'h4E56_4C4B (NVLK)，the upper half NVR in eFlash is unlocked. */
        } NVRLOCKb;
    };
} ANALOG_SUBSYS_REGS_Type;

/*! \brief CLK_CFG_REGS register */
typedef struct {
    union
    {
        __IOM uint32_t CLKSEM;  /*!< 0x00002000 */ 
       
        struct
        {
            __IOM uint32_t SEM                       : 2 ;     /*!< [1:0] : This register provides a mechanism to acquire all the CLKCFG registers (except this register) by CPU1 or CPU2. */
                  uint32_t RSV_0                     : 14;     /*!< [15:2] : reserved. */
            __IM  uint32_t KEY                       : 16;     /*!< [31:16] : Writing the value 0xa5a5 will allow the writing of the SEM bits, else writes are ignored. */
        } CLKSEMb;
    };

    union
    {
        __IOM uint32_t CLKCFGLOCK1;  /*!< 0x00002004 */ 
       
        struct
        {
            __IOM uint32_t CLKSRCCTL1                : 1 ;     /*!< [0:0] : Lock bit for CLKSRCCTL1 register:                               <br>  0: Respective register is not locked                            <br>  1: Respective register is locked. */
            __IOM uint32_t CLKSRCCTL2                : 1 ;     /*!< [1:1] : Lock bit for CLKSRCCTL2 register: 0: Respective register is not locked 1: Respective register is locked. */
            __IOM uint32_t CLKSRCCTL3                : 1 ;     /*!< [2:2] : Lock bit for CLKSRCCTL3 register: 0: Respective register is not locked 1: Respective register is locked. */
            __IOM uint32_t SYSPLLCTL1                : 1 ;     /*!< [3:3] : Lock bit for SYSPLLCTL1 register: 0: Respective register is not locked 1: Respective register is locked. */
                  uint32_t RSV_3                     : 2 ;     /*!< [5:4] : reserved. */
            __IOM uint32_t SYSPLLMULT                : 1 ;     /*!< [6:6] : Lock bit for SYSPLLMULT register: 0: Respective register is not locked 1: Respective register is locked. */
            __IOM uint32_t AUXPLLCTL1                : 1 ;     /*!< [7:7] : Lock bit for AUXPLLCTL1 register: 0: Respective register is not locked 1: Respective register is locked. */
                  uint32_t RSV_2                     : 2 ;     /*!< [9:8] : reserved. */
            __IOM uint32_t AUXPLLMULT                : 1 ;     /*!< [10:10] : Lock bit for AUXPLLMULT register: 0: Respective register is not locked 1: Respective register is locked. */
            __IOM uint32_t SYSCLKDIVSEL              : 1 ;     /*!< [11:11] : Lock bit for SYSCLKDIVSEL register: 0: Respective register is not locked 1: Respective register is locked. */
            __IOM uint32_t AUXCLKDIVSEL              : 1 ;     /*!< [12:12] : Lock bit for AUXCLKDIVSEL register: 0: Respective register is not locked  1: Respective register is locked. */
            __IOM uint32_t PERCLKDIVSEL              : 1 ;     /*!< [13:13] : Lock bit for PERCLKDIVSEL register: 0: Respective register is not locked  1: Respective register is locked. */
                  uint32_t RSV_1                     : 1 ;     /*!< [14:14] : reserved. */
            __IOM uint32_t LOSPCP                    : 1 ;     /*!< [15:15] : Lock bit for LOSPCP register:                                   <br>  0: Respective register is not locked                            <br>  1: Respective register is locked. */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } CLKCFGLOCK1b;
    };

    uint8_t    RSV_0X2008[8];   /*!< 0x00002008~0x0000200f : reserved */

    union
    {
        __IOM uint32_t CLKSRCCTL1;  /*!< 0x00002010 */ 
       
        struct
        {
            __IOM uint32_t OSCCLKSRCSEL              : 2 ;     /*!< [1:0] : Oscillator Clock Source Select Bit: This bit selects the source for OSCCLK. */
                  uint32_t RSV_2                     : 1 ;     /*!< [2:2] : reserved. */
            __IOM uint32_t INTOSC2OFF                : 1 ;     /*!< [3:3] : Internal Oscillator 2 Off Bit: This bit turns oscillator 2 off: <br>  0 = Internal Oscillator 2 On (default on reset)                 <br>  1 = Internal Oscillator 2 Off                                   <br>  This bit could be used by the user to turn off the internal oscillator 2 if it is not used. */
            __IOM uint32_t XTALOFF                   : 1 ;     /*!< [4:4] : Crystal (External) Oscillator Off Bit: This bit turns external oscillator off:<br>  0 = Crystal (External) Oscillator On (default on reset)         <br>  1 = Crystal (External) Oscillator Off                           <br>  NOTE: Ensure no resources are using a clock source prior to disabling it. */
            __IOM uint32_t WDHALTI                   : 1 ;     /*!< [5:5] : Watchdog HALT Mode Ignore Bit: This bit determines if CPU1. */
                  uint32_t RSV_1                     : 10;     /*!< [15:6] : reserved. */
            __IOM uint32_t XTAL_DS                   : 2 ;     /*!< [17:16] : XTAL IO drive current select pins                               <br>  for 2MHz application, 2'b00 and 2'b01 are recommend             <br>  for 30MHz application, 2'b10 and 2'b11 are recommend for 1. */
                  uint32_t RSV_0                     : 14;     /*!< [31:18] : reserved. */
        } CLKSRCCTL1b;
    };

    union
    {
        __IOM uint32_t CLKSRCCTL2;  /*!< 0x00002014 */ 
       
        struct
        {
            __IOM uint32_t AUXOSCCLKSRCSEL           : 2 ;     /*!< [1:0] : Oscillator Clock Source Select Bit: This bit selects the source for AUXOSCCLK:<br>  00 = INTOSC2 (default on reset)                                 <br>  01 = External Oscillator (XTAL)                                 <br>  10 = AUXCLKIN (from GPIO)                                       <br>  11 = Reserved                                                   <br>  Whenever the user changes the clock source using these bits, the AUXPLLMULT register will be forced to zero and the PLL will be bypassed and powered down. */
            __IOM uint32_t CANABCLKSEL               : 2 ;     /*!< [3:2] : CANA Bit-Clock Source Select Bit:                               <br>  00 = PERx. */
            __IOM uint32_t CANBBCLKSEL               : 2 ;     /*!< [5:4] : CANB Bit-Clock Source Select Bit:                               <br>  00 = PERx. */
            __IOM uint32_t CANCBCLKSEL               : 2 ;     /*!< [7:6] : CANC Bit-Clock Source Select Bit:                               <br>  00 = PERx. */
                  uint32_t RSV_1                     : 8 ;     /*!< [15:8] : reserved. */
            __IOM uint32_t SPIACLKSEL                : 1 ;     /*!< [16:16] : SPIA Clock Source Select Bit:                                   <br>  0 = SYS_PCLK (default on reset)                                 <br>  1 = SYS_CLK                                                     <br>  Missing clock detect circuit doesnt have any impact on these bits. */
            __IOM uint32_t SPIBCLKSEL                : 1 ;     /*!< [17:17] : SPIB Clock Source Select Bit:                                   <br>  0 = SYS_PCLK (default on reset)                                 <br>  1 = SYS_CLK                                                     <br>  Missing clock detect circuit doesnt have any impact on these bits. */
            __IOM uint32_t SPICCLKSEL                : 1 ;     /*!< [18:18] : SPIC Clock Source Select Bit:                                   <br>  0 = SYS_PCLK (default on reset)                                 <br>  1 = SYS_CLK                                                     <br>  Missing clock detect circuit doesnt have any impact on these bits. */
                  uint32_t RSV_0                     : 13;     /*!< [31:19] : reserved. */
        } CLKSRCCTL2b;
    };

    union
    {
        __IOM uint32_t CLKSRCCTL3;  /*!< 0x00002018 */ 
       
        struct
        {
            __IOM uint32_t XCLKOUTSEL                : 3 ;     /*!< [2:0] : XCLKOUT Source Select Bit: This bit selects the source for XCLKOUT:<br>  000 = PLLSYSCLK (default on reset)                              <br>  001 = PLLRAWCLK                                                 <br>  010 = CPU1. */
                  uint32_t RSV_0                     : 29;     /*!< [31:3] : reserved. */
        } CLKSRCCTL3b;
    };

    union
    {
        __IOM uint32_t SYSPLLCTL1;  /*!< 0x0000201c */ 
       
        struct
        {
            __IOM uint32_t PLLEN                     : 1 ;     /*!< [0:0] : SYSPLL enabled or disabled: This bit decides if the SYSPLL is enabled or not<br>  1 = SYSPLL is enabled                                           <br>  0 = SYSPLL is powered off. */
            __IOM uint32_t PLLCLKEN                  : 1 ;     /*!< [1:1] : SYSPLL bypassed or included in the PLLSYSCLK path: This bit decides if the SYSPLL is bypassed when PLLSYSCLK is generated<br>  1 = PLLSYSCLK is fed from the SYSPLL clock output. */
                  uint32_t RSV_1                     : 14;     /*!< [15:2] : reserved. */
            __IOM uint32_t PLL_LDO_EN                : 1 ;     /*!< [16:16] : LDO enable control ; 1: enable  0:disable. */
            __IOM uint32_t PLL_LPF                   : 2 ;     /*!< [18:17] : PLL LPF  resistor adjust. */
            __IOM uint32_t PLL_ICP                   : 3 ;     /*!< [21:19] : PLL cp current adjust reg. */
            __IOM uint32_t PLL_VCO_BAND              : 1 ;     /*!< [22:22] : vco band sel  1: higher frequecy band. */
            __IOM uint32_t PLL_CKREF_DIV             : 3 ;     /*!< [25:23] : fckref_div=fref/(N+2). */
            __IOM uint32_t PLL_CKREF_SEL             : 1 ;     /*!< [26:26] : 0: fref_pll=fref  1:fref_pll=fckref_div. */
            __IOM uint32_t LDO_RSTB                  : 1 ;     /*!< [27:27] : 0 : SYSPLL is under reset. */
                  uint32_t RSV_0                     : 4 ;     /*!< [31:28] : reserved. */
        } SYSPLLCTL1b;
    };

    uint8_t    RSV_0X2020[8];   /*!< 0x00002020~0x00002027 : reserved */

    union
    {
        __IOM uint32_t SYSPLLMULT;  /*!< 0x00002028 */ 
       
        struct
        {
            __IOM uint32_t FCW_SSC                   : 19;     /*!< [18:0] : PLL divider ratio control word; Integer and Fractional. */
            __IOM uint32_t REG_DOT_FCW               : 3 ;     /*!< [21:19] : decimal point for FCW_SSC                                       <br>  3'b000 : 4. */
                  uint32_t RSV_0                     : 8 ;     /*!< [29:22] : reserved. */
            __IOM uint32_t BYPASS_PI                 : 1 ;     /*!< [30:30] : BYPASS PLL PI control                                           <br>  1:bypass PI                                                     <br>. */
            __IOM uint32_t ORDER                     : 1 ;     /*!< [31:31] : digital sigma delta modulator order sel                         <br>  1: order=2                                                      <br>  0: order=1                                                      <br>. */
        } SYSPLLMULTb;
    };

    union
    {
        __IM uint32_t SYSPLLSTS;  /*!< 0x0000202c */ 
       
        struct
        {
            __IM  uint32_t LOCKS                     : 1 ;     /*!< [0:0] : SYSPLL Lock Status Bit: This bit indicates whether the SYSPLL is locked or not<br>  0 = SYSPLL is not yet locked 1 = SYSPLL is locked               <br>  Reset type: XRSn                                                <br>. */
                  uint32_t RSV_0                     : 31;     /*!< [31:1] : reserved. */
        } SYSPLLSTSb;
    };

    union
    {
        __IOM uint32_t AUXPLLCTL1;  /*!< 0x00002030 */ 
       
        struct
        {
            __IOM uint32_t PLLEN                     : 1 ;     /*!< [0:0] : AUXPLL enabled or disabled: This bit decides if the AUXPLL is enabled or not<br>  1 = AUXPLL is enabled                                           <br>  0 = AUXPLL is powered off. */
            __IOM uint32_t PLLCLKEN                  : 1 ;     /*!< [1:1] : AUXPLL bypassed or included in the AUXPLLCLK path: This bit decides if the AUXPLL is bypassed when AUXPLLCLK is generated<br>  1 = AUXPLLCLK is fed from the AUXPLL clock output. */
                  uint32_t RSV_1                     : 14;     /*!< [15:2] : reserved. */
            __IOM uint32_t PLL_LDO_EN                : 1 ;     /*!< [16:16] : LDO enable control ; 1: enable  0:disable. */
            __IOM uint32_t PLL_LPF                   : 2 ;     /*!< [18:17] : PLL LPF  resistor adjust. */
            __IOM uint32_t PLL_ICP                   : 3 ;     /*!< [21:19] : PLL cp current adjust reg. */
            __IOM uint32_t PLL_VCO_BAND              : 1 ;     /*!< [22:22] : vco band sel  1: higher frequecy band. */
            __IOM uint32_t PLL_CKREF_DIV             : 3 ;     /*!< [25:23] : fckref_div=fref/(N+2). */
            __IOM uint32_t PLL_CKREF_SEL             : 1 ;     /*!< [26:26] : 0: fref_pll=fref  1:fref_pll=fckref_div. */
            __IOM uint32_t LDO_RSTB                  : 1 ;     /*!< [27:27] : 0 : AUXPLL is under reset. */
                  uint32_t RSV_0                     : 4 ;     /*!< [31:28] : reserved. */
        } AUXPLLCTL1b;
    };

    uint8_t    RSV_0X2034[8];   /*!< 0x00002034~0x0000203b : reserved */

    union
    {
        __IOM uint32_t AUXPLLMULT;  /*!< 0x0000203c */ 
       
        struct
        {
            __IOM uint32_t FCW_SSC                   : 19;     /*!< [18:0] : PLL divider ratio control word; Integer and Fractional. */
            __IOM uint32_t REG_DOT_FCW               : 3 ;     /*!< [21:19] : decimal point for FCW_SSC                                       <br>  3'b000 : 4. */
                  uint32_t RSV_0                     : 8 ;     /*!< [29:22] : reserved. */
            __IOM uint32_t BYPASS_PI                 : 1 ;     /*!< [30:30] : BYPASS PLL PI control                                           <br>  1:bypass PI                                                     <br>. */
            __IOM uint32_t ORDER                     : 1 ;     /*!< [31:31] : digital sigma delta modulator order sel                         <br>  1: order=2                                                      <br>  0: order=1                                                      <br>. */
        } AUXPLLMULTb;
    };

    union
    {
        __IM uint32_t AUXPLLSTS;  /*!< 0x00002040 */ 
       
        struct
        {
            __IM  uint32_t LOCKS                     : 1 ;     /*!< [0:0] : AUXPLL Lock Status Bit: This bit indicates whether the AUXPLL is<br>  locked or not                                                   <br>  0 = AUXPLL is not yet locked                                    <br>  1 = AUXPLL is locked                                            <br>  Reset type: XRSn                                                <br>. */
                  uint32_t RSV_0                     : 31;     /*!< [31:1] : reserved. */
        } AUXPLLSTSb;
    };

    union
    {
        __IOM uint32_t SYSCLKDIVSEL;  /*!< 0x00002044 */ 
       
        struct
        {
            __IOM uint32_t PLLSYSCLKDIV              : 6 ;     /*!< [5:0] : PLLSYSCLK Divide Select: This bit selects the divider setting for the PLLSYSCLK. */
                  uint32_t RSV_0                     : 26;     /*!< [31:6] : reserved. */
        } SYSCLKDIVSELb;
    };

    union
    {
        __IOM uint32_t AUXCLKDIVSEL;  /*!< 0x00002048 */ 
       
        struct
        {
            __IOM uint32_t AUXPLLDIV                 : 2 ;     /*!< [1:0] : AUXPLLCLK Divide Select: This bit selects the divider setting for the AUXPLLCK. */
                  uint32_t RSV_0                     : 30;     /*!< [31:2] : reserved. */
        } AUXCLKDIVSELb;
    };

    union
    {
        __IOM uint32_t PERCLKDIVSEL;  /*!< 0x0000204c */ 
       
        struct
        {
                  uint32_t RSV_1                     : 4 ;     /*!< [3:0] : reserved. */
            __IOM uint32_t EMIF1CLKDIV               : 1 ;     /*!< [4:4] : EMIF1 Clock Divide Select: This bit selects whether the EMIF1   <br>  module run with a /1 or /2 clock. */
                  uint32_t RSV_0                     : 27;     /*!< [31:5] : reserved. */
        } PERCLKDIVSELb;
    };

    union
    {
        __IOM uint32_t XCLKOUTDIVSEL;  /*!< 0x00002050 */ 
       
        struct
        {
            __IOM uint32_t XCLKOUTDIV                : 2 ;     /*!< [1:0] : XCLKOUT Divide Select: This bit selects the divider setting for the XCLKOUT. */
                  uint32_t RSV_0                     : 30;     /*!< [31:2] : reserved. */
        } XCLKOUTDIVSELb;
    };

    uint8_t    RSV_0X2054[4];   /*!< 0x00002054~0x00002057 : reserved */

    union
    {
         uint32_t LOSPCP;  /*!< 0x00002058 */ 
       
        struct
        {
                  uint32_t RSV_0                     : 32;     /*!< [31:0] : reserved. */
        } LOSPCPb;
    };

    union
    {
        __IOM uint32_t MCDCR;  /*!< 0x0000205c */ 
       
        struct
        {
            __IM  uint32_t MCLKSTS                   : 1 ;     /*!< [0:0] : Missing Clock Status Bit:                                       <br>  0 = OSCCLK Is OK                                                <br>  1 = OSCCLK Detected Missing, CLOCKFAILn Generated Reset type: XRSn<br>. */
            __IOM uint32_t MCLKCLR                   : 1 ;     /*!< [1:1] : Missing Clock Clear Bit:                                        <br>  Write 1" to this bit to clear MCLKSTS bit and reset the missing clock detect circuit. */
            __IOM uint32_t MCLKOFF                   : 1 ;     /*!< [2:2] : Missing Clock Detect Off Bit:                                   <br>  0 = Missing Clock Detect Circuit Enabled 1 = Missing Clock Detect Circuit Disabled<br>  Reset type: XRSn                                                <br>. */
            __IOM uint32_t OSCOFF                    : 1 ;     /*!< [3:3] : Oscillator Clock Off Bit:                                       <br>  0 = OSCCLK Connected to OSCCLK Counter in MCD module            <br>  1 = OSCCLK Disconnected to OSCCLK Counter in MCD module Reset type: XRSn<br>. */
                  uint32_t RSV_0                     : 28;     /*!< [31:4] : reserved. */
        } MCDCRb;
    };

    union
    {
        __IM uint32_t X1CNT;  /*!< 0x00002060 */ 
       
        struct
        {
            __IM  uint32_t X1CNT                     : 10;     /*!< [9:0] : X1 Counter:                                                     <br>  - This counter increments on every X1 CLOCKs positive-edge. */
                  uint32_t RSV_0                     : 22;     /*!< [31:10] : reserved. */
        } X1CNTb;
    };
} CLK_CFG_REGS_Type;

/*! \brief CPU_SYS_REGS register */
typedef struct {
    union
    {
        __IOM uint32_t CPUSYSLOCK1;  /*!< 0x00002400 */ 
       
        struct
        {
                  uint32_t RSV_2                     : 3 ;     /*!< [2:0] : reserved. */
            __IOM uint32_t PCLKCR0                   : 1 ;     /*!< [3:3] : Lock bit for PCLKCR0 Register:                                  <br>  0: Respective register is not locked 1: Respective register is locked. */
            __IOM uint32_t PCLKCR1                   : 1 ;     /*!< [4:4] : Lock bit for PCLKCR1 Register:                                  <br>  0: Respective register is not locked 1: Respective register is locked. */
            __IOM uint32_t PCLKCR2                   : 1 ;     /*!< [5:5] : Lock bit for PCLKCR2 Register:                                  <br>  0: Respective register is not locked 1: Respective register is locked. */
            __IOM uint32_t PCLKCR3                   : 1 ;     /*!< [6:6] : Lock bit for PCLKCR3 Register:                                  <br>  0: Respective register is not locked 1: Respective register is locked. */
            __IOM uint32_t PCLKCR4                   : 1 ;     /*!< [7:7] : Lock bit for PCLKCR4 Register:                                  <br>  0: Respective register is not locked 1: Respective register is locked. */
            __IOM uint32_t PCLKCR5                   : 1 ;     /*!< [8:8] : Lock bit for PCLKCR5 Register:                                  <br>  0: Respective register is not locked 1: Respective register is locked. */
            __IOM uint32_t PCLKCR6                   : 1 ;     /*!< [9:9] : Lock bit for PCLKCR6 Register:                                  <br>  0: Respective register is not locked 1: Respective register is locked. */
            __IOM uint32_t PCLKCR7                   : 1 ;     /*!< [10:10] : Lock bit for PCLKCR7 Register:                                  <br>  0: Respective register is not locked 1: Respective register is locked. */
            __IOM uint32_t PCLKCR8                   : 1 ;     /*!< [11:11] : Lock bit for PCLKCR8 Register:                                  <br>  0: Respective register is not locked 1: Respective register is locked. */
            __IOM uint32_t PCLKCR9                   : 1 ;     /*!< [12:12] : Lock bit for PCLKCR9 Register:                                  <br>  0: Respective register is not locked 1: Respective register is locked. */
            __IOM uint32_t PCLKCR10                  : 1 ;     /*!< [13:13] : Lock bit for PCLKCR10 Register: 0: Respective register is not locked 1: Respective register is locked. */
            __IOM uint32_t PCLKCR11                  : 1 ;     /*!< [14:14] : Lock bit for PCLKCR11 Register: 0: Respective register is not locked 1: Respective register is locked. */
            __IOM uint32_t PCLKCR12                  : 1 ;     /*!< [15:15] : Lock bit for PCLKCR12 Register: 0: Respective register is not locked 1: Respective register is locked. */
            __IOM uint32_t PCLKCR13                  : 1 ;     /*!< [16:16] : Lock bit for PCLKCR13 Register: 0: Respective register is not locked 1: Respective register is locked. */
            __IOM uint32_t PCLKCR14                  : 1 ;     /*!< [17:17] : Lock bit for PCLKCR14 Register: 0: Respective register is not locked 1: Respective register is locked. */
            __IOM uint32_t PCLKCR15                  : 1 ;     /*!< [18:18] : Lock bit for PCLKCR15 Register: 0: Respective register is not locked 1: Respective register is locked. */
            __IOM uint32_t PCLKCR16                  : 1 ;     /*!< [19:19] : Lock bit for PCLKCR16 Register: 0: Respective register is not locked 1: Respective register is locked. */
                  uint32_t RSV_1                     : 1 ;     /*!< [20:20] : reserved. */
            __IOM uint32_t LPMCR                     : 1 ;     /*!< [21:21] : Lock bit for LPMCR Register:                                    <br>  0: Respective register is not locked 1: Respective register is locked. */
            __IOM uint32_t GPIOLPMSEL0               : 1 ;     /*!< [22:22] : Lock bit for GPIOLPMSEL0 Register: 0: Respective register is not locked 1: Respective register is locked. */
            __IOM uint32_t GPIOLPMSEL1               : 1 ;     /*!< [23:23] : Lock bit for GPIOLPMSEL1 Register: 0: Respective register is not locked 1: Respective register is locked. */
            __IOM uint32_t PCLKCR17                  : 1 ;     /*!< [24:24] : Lock bit for PCLKCR17 Register: 0: Respective register is not locked 1: Respective register is locked. */
                  uint32_t RSV_0                     : 7 ;     /*!< [31:25] : reserved. */
        } CPUSYSLOCK1b;
    };

    uint8_t    RSV_0X2404[8];   /*!< 0x00002404~0x0000240b : reserved */

    union
    {
         uint32_t HIBBOOTMODE;  /*!< 0x0000240c */ 
       
        struct
        {
                  uint32_t RSV_0                     : 32;     /*!< [31:0] : reserved. */
        } HIBBOOTMODEb;
    };

    union
    {
         uint32_t IORESTOREADDR;  /*!< 0x00002410 */ 
       
        struct
        {
                  uint32_t RSV_0                     : 32;     /*!< [31:0] : reserved. */
        } IORESTOREADDRb;
    };

    union
    {
         uint32_t PIEVERRADDR;  /*!< 0x00002414 */ 
       
        struct
        {
                  uint32_t RSV_0                     : 32;     /*!< [31:0] : reserved. */
        } PIEVERRADDRb;
    };

    uint8_t    RSV_0X2418[44];   /*!< 0x00002418~0x00002443 : reserved */

    union
    {
        __IOM uint32_t PCLKCR0;  /*!< 0x00002444 */ 
       
        struct
        {
                  uint32_t RSV_3                     : 2 ;     /*!< [1:0] : reserved. */
            __IOM uint32_t DMA                       : 1 ;     /*!< [2:2] : DMA Clock Enable bit:                                           <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t CPUTIMER0                 : 1 ;     /*!< [3:3] : CPUTIMER0 Clock Enable bit:                                     <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t CPUTIMER1                 : 1 ;     /*!< [4:4] : CPUTIMER1 Clock Enable bit:                                     <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t CPUTIMER2                 : 1 ;     /*!< [5:5] : CPUTIMER2 Clock Enable bit:                                     <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
                  uint32_t RSV_2                     : 2 ;     /*!< [7:6] : reserved. */
            __IOM uint32_t DWCPUTIMER0               : 1 ;     /*!< [8:8] : DWCPUTIMER0 Clock Enable bit:                                   <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t DWCPUTIMER1               : 1 ;     /*!< [9:9] : DWCPUTIMER1 Clock Enable bit:                                   <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t DWCPUTIMER2               : 1 ;     /*!< [10:10] : DWCPUTIMER2 Clock Enable bit:                                   <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
                  uint32_t RSV_1                     : 7 ;     /*!< [17:11] : reserved. */
            __IOM uint32_t TBCLKSYNC                 : 1 ;     /*!< [18:18] : EPWM Time Base Clock sync: When set PWM time bases of all the PWM modules belonging to the same CPU-Subsystem (as partitioned using their CPUSEL bits) start counting. */
            __IOM uint32_t GTBCLKSYNC                : 1 ;     /*!< [19:19] : EPWM Time Base Clock Global sync: When set by CPU1, PWM time bases of all modules start counting. */
                  uint32_t RSV_0                     : 12;     /*!< [31:20] : reserved. */
        } PCLKCR0b;
    };

    union
    {
        __IOM uint32_t PCLKCR1;  /*!< 0x00002448 */ 
       
        struct
        {
            __IOM uint32_t EMIF1                     : 1 ;     /*!< [0:0] : EMIF1 Clock Enable bit:                                         <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Notes:                                                          <br>  [1] These bits are not used (R/W) in CPU2. */
            __IOM uint32_t EMIF2                     : 1 ;     /*!< [1:1] : EMIF2 Clock Enable bit:                                         <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Notes:                                                          <br>  [1] These bits are not used (R/W) in CPU2. */
                  uint32_t RSV_0                     : 30;     /*!< [31:2] : reserved. */
        } PCLKCR1b;
    };

    union
    {
        __IOM uint32_t PCLKCR2;  /*!< 0x0000244c */ 
       
        struct
        {
            __IOM uint32_t EPWM1                     : 1 ;     /*!< [0:0] : EPWM1 Clock Enable bit:                                         <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t EPWM2                     : 1 ;     /*!< [1:1] : EPWM2 Clock Enable bit:                                         <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t EPWM3                     : 1 ;     /*!< [2:2] : EPWM3 Clock Enable bit:                                         <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t EPWM4                     : 1 ;     /*!< [3:3] : EPWM4 Clock Enable bit:                                         <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t EPWM5                     : 1 ;     /*!< [4:4] : EPWM5 Clock Enable bit:                                         <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t EPWM6                     : 1 ;     /*!< [5:5] : EPWM6 Clock Enable bit:                                         <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t EPWM7                     : 1 ;     /*!< [6:6] : EPWM7 Clock Enable bit:                                         <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t EPWM8                     : 1 ;     /*!< [7:7] : EPWM8 Clock Enable bit:                                         <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t EPWM9                     : 1 ;     /*!< [8:8] : EPWM9 Clock Enable bit:                                         <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t EPWM10                    : 1 ;     /*!< [9:9] : EPWM10 Clock Enable bit:                                        <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t EPWM11                    : 1 ;     /*!< [10:10] : EPWM11 Clock Enable bit:                                        <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t EPWM12                    : 1 ;     /*!< [11:11] : EPWM12 Clock Enable bit:                                        <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
                  uint32_t RSV_0                     : 20;     /*!< [31:12] : reserved. */
        } PCLKCR2b;
    };

    union
    {
        __IOM uint32_t PCLKCR3;  /*!< 0x00002450 */ 
       
        struct
        {
            __IOM uint32_t ECAP1                     : 1 ;     /*!< [0:0] : ECAP1 Clock Enable bit:                                         <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t ECAP2                     : 1 ;     /*!< [1:1] : ECAP2 Clock Enable bit:                                         <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t ECAP3                     : 1 ;     /*!< [2:2] : ECAP3 Clock Enable bit:                                         <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t ECAP4                     : 1 ;     /*!< [3:3] : ECAP4 Clock Enable bit:                                         <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t ECAP5                     : 1 ;     /*!< [4:4] : ECAP5 Clock Enable bit:                                         <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t ECAP6                     : 1 ;     /*!< [5:5] : ECAP6 Clock Enable bit:                                         <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
                  uint32_t RSV_0                     : 26;     /*!< [31:6] : reserved. */
        } PCLKCR3b;
    };

    union
    {
        __IOM uint32_t PCLKCR4;  /*!< 0x00002454 */ 
       
        struct
        {
            __IOM uint32_t EQEP1                     : 1 ;     /*!< [0:0] : EQEP1 Clock Enable bit:                                         <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t EQEP2                     : 1 ;     /*!< [1:1] : EQEP2 Clock Enable bit:                                         <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t EQEP3                     : 1 ;     /*!< [2:2] : EQEP3 Clock Enable bit:                                         <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
                  uint32_t RSV_0                     : 29;     /*!< [31:3] : reserved. */
        } PCLKCR4b;
    };

    uint8_t    RSV_0X2458[4];   /*!< 0x00002458~0x0000245b : reserved */

    union
    {
        __IOM uint32_t PCLKCR6;  /*!< 0x0000245c */ 
       
        struct
        {
            __IOM uint32_t SD1                       : 1 ;     /*!< [0:0] : SD1 Clock Enable bit:                                           <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t SD2                       : 1 ;     /*!< [1:1] : SD2 Clock Enable bit:                                           <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
                  uint32_t RSV_0                     : 30;     /*!< [31:2] : reserved. */
        } PCLKCR6b;
    };

    union
    {
        __IOM uint32_t PCLKCR7;  /*!< 0x00002460 */ 
       
        struct
        {
            __IOM uint32_t SCI_A                     : 1 ;     /*!< [0:0] : SCI_A Clock Enable bit:                                         <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t SCI_B                     : 1 ;     /*!< [1:1] : SCI_B Clock Enable bit:                                         <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t SCI_C                     : 1 ;     /*!< [2:2] : SCI_C Clock Enable bit:                                         <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t SCI_D                     : 1 ;     /*!< [3:3] : SCI_D Clock Enable bit:                                         <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
                  uint32_t RSV_0                     : 28;     /*!< [31:4] : reserved. */
        } PCLKCR7b;
    };

    union
    {
        __IOM uint32_t PCLKCR8;  /*!< 0x00002464 */ 
       
        struct
        {
            __IOM uint32_t SPI_A                     : 1 ;     /*!< [0:0] : SPI_A Clock Enable bit:                                         <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t SPI_B                     : 1 ;     /*!< [1:1] : SPI_B Clock Enable bit:                                         <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t SPI_C                     : 1 ;     /*!< [2:2] : SPI_C Clock Enable bit:                                         <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
                  uint32_t RSV_0                     : 29;     /*!< [31:3] : reserved. */
        } PCLKCR8b;
    };

    union
    {
        __IOM uint32_t PCLKCR9;  /*!< 0x00002468 */ 
       
        struct
        {
            __IOM uint32_t I2C_A                     : 1 ;     /*!< [0:0] : I2C_A Clock Enable bit:                                         <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t I2C_B                     : 1 ;     /*!< [1:1] : I2C_B Clock Enable bit:                                         <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
                  uint32_t RSV_1                     : 14;     /*!< [15:2] : reserved. */
            __IOM uint32_t PMBUS_A                   : 1 ;     /*!< [16:16] : PMBus_A Clock Enable bit:                                       <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
                  uint32_t RSV_0                     : 15;     /*!< [31:17] : reserved. */
        } PCLKCR9b;
    };

    union
    {
        __IOM uint32_t PCLKCR10;  /*!< 0x0000246c */ 
       
        struct
        {
            __IOM uint32_t CAN_A                     : 1 ;     /*!< [0:0] : CAN_A Clock Enable bit:                                         <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t CAN_B                     : 1 ;     /*!< [1:1] : CAN_B Clock Enable bit:                                         <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t CAN_C                     : 1 ;     /*!< [2:2] : CAN_C Clock Enable bit:                                         <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
                  uint32_t RSV_0                     : 29;     /*!< [31:3] : reserved. */
        } PCLKCR10b;
    };

    union
    {
        __IOM uint32_t PCLKCR11;  /*!< 0x00002470 */ 
       
        struct
        {
                  uint32_t RSV_1                     : 16;     /*!< [15:0] : reserved. */
            __IOM uint32_t USB_A                     : 1 ;     /*!< [16:16] : USB_A Clock Enable bit:                                         <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Notes:                                                          <br>  [1] This bit is not used (R/W) in CPU2. */
                  uint32_t RSV_0                     : 15;     /*!< [31:17] : reserved. */
        } PCLKCR11b;
    };

    union
    {
         uint32_t PCLKCR12;  /*!< 0x00002474 */ 
       
        struct
        {
                  uint32_t RSV_0                     : 32;     /*!< [31:0] : reserved. */
        } PCLKCR12b;
    };

    union
    {
        __IOM uint32_t PCLKCR13;  /*!< 0x00002478 */ 
       
        struct
        {
            __IOM uint32_t ADC_A                     : 1 ;     /*!< [0:0] : ADC_A Clock Enable bit:                                         <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t ADC_B                     : 1 ;     /*!< [1:1] : ADC_B Clock Enable bit:                                         <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t ADC_C                     : 1 ;     /*!< [2:2] : ADC_C Clock Enable bit:                                         <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t ADC_D                     : 1 ;     /*!< [3:3] : ADC_D Clock Enable bit:                                         <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
                  uint32_t RSV_0                     : 28;     /*!< [31:4] : reserved. */
        } PCLKCR13b;
    };

    union
    {
        __IOM uint32_t PCLKCR14;  /*!< 0x0000247c */ 
       
        struct
        {
            __IOM uint32_t CMPSS1                    : 1 ;     /*!< [0:0] : CMPSS1 Clock Enable bit:                                        <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t CMPSS2                    : 1 ;     /*!< [1:1] : CMPSS2 Clock Enable bit:                                        <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t CMPSS3                    : 1 ;     /*!< [2:2] : CMPSS3 Clock Enable bit:                                        <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t CMPSS4                    : 1 ;     /*!< [3:3] : CMPSS4 Clock Enable bit:                                        <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t CMPSS5                    : 1 ;     /*!< [4:4] : CMPSS5 Clock Enable bit:                                        <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t CMPSS6                    : 1 ;     /*!< [5:5] : CMPSS6 Clock Enable bit:                                        <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t CMPSS7                    : 1 ;     /*!< [6:6] : CMPSS7 Clock Enable bit:                                        <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t CMPSS8                    : 1 ;     /*!< [7:7] : CMPSS8 Clock Enable bit:                                        <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
                  uint32_t RSV_0                     : 24;     /*!< [31:8] : reserved. */
        } PCLKCR14b;
    };

    uint8_t    RSV_0X2480[4];   /*!< 0x00002480~0x00002483 : reserved */

    union
    {
        __IOM uint32_t PCLKCR16;  /*!< 0x00002484 */ 
       
        struct
        {
                  uint32_t RSV_1                     : 16;     /*!< [15:0] : reserved. */
            __IOM uint32_t DAC_A                     : 1 ;     /*!< [16:16] : Buffered_DAC_A Clock Enable Bit:                                <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t DAC_B                     : 1 ;     /*!< [17:17] : Buffered_DAC_B Clock Enable Bit:                                <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t DAC_C                     : 1 ;     /*!< [18:18] : Buffered_DAC_C Clock Enable Bit:                                <br>  0: Module clock is gated-off 1: Module clock is turned-on       <br>  Reset type: SYSRSn                                              <br>. */
                  uint32_t RSV_0                     : 13;     /*!< [31:19] : reserved. */
        } PCLKCR16b;
    };

    union
    {
        __IOM uint32_t PCLKCR17;  /*!< 0x00002488 */ 
       
        struct
        {
            __IOM uint32_t CLB1                      : 1 ;     /*!< [0:0] : CLB1 Clock Enable bit:                                          <br>  0: Module clock is gated-off                                    <br>  1: Module clock is turned-on                                    <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t CLB2                      : 1 ;     /*!< [1:1] : CLB2 Clock Enable bit:                                          <br>  0: Module clock is gated-off                                    <br>  1: Module clock is turned-on                                    <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t CLB3                      : 1 ;     /*!< [2:2] : CLB3 Clock Enable bit:                                          <br>  0: Module clock is gated-off                                    <br>  1: Module clock is turned-on                                    <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t CLB4                      : 1 ;     /*!< [3:3] : CLB4 Clock Enable bit:                                          <br>  0: Module clock is gated-off                                    <br>  1: Module clock is turned-on                                    <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t CLB5                      : 1 ;     /*!< [4:4] : CLB1 Clock Enable bit:                                          <br>  0: Module clock is gated-off                                    <br>  0: Module clock is turned-on                                    <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t CLB6                      : 1 ;     /*!< [5:5] : CLB2 Clock Enable bit:                                          <br>  0: Module clock is gated-off                                    <br>  0: Module clock is turned-on                                    <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t CLB7                      : 1 ;     /*!< [6:6] : CLB3 Clock Enable bit:                                          <br>  0: Module clock is gated-off                                    <br>  0: Module clock is turned-on                                    <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t CLB8                      : 1 ;     /*!< [7:7] : CLB4 Clock Enable bit:                                          <br>  0: Module clock is gated-off                                    <br>  0: Module clock is turned-on                                    <br>  Reset type: SYSRSn                                              <br>. */
                  uint32_t RSV_0                     : 24;     /*!< [31:8] : reserved. */
        } PCLKCR17b;
    };

    uint8_t    RSV_0X248C[92];   /*!< 0x0000248c~0x000024e7 : reserved */

    union
    {
         uint32_t SECMSEL;  /*!< 0x000024e8 */ 
       
        struct
        {
                  uint32_t RSV_0                     : 32;     /*!< [31:0] : reserved. */
        } SECMSELb;
    };

    union
    {
        __IOM uint32_t LPMCR;  /*!< 0x000024ec */ 
       
        struct
        {
                  uint32_t RSV_1                     : 2 ;     /*!< [1:0] : reserved. */
            __IOM uint32_t QUALSTDBY                 : 6 ;     /*!< [7:2] : Select number of OSCCLK clock cycles to qualify the selected inputs when waking the from STANDBY mode:<br>  000000 = 2 OSCCLKs                                              <br>  000001 = 3 OSCCLKs                                              <br>  . */
                  uint32_t RSV_0                     : 24;     /*!< [31:8] : reserved. */
        } LPMCRb;
    };

    union
    {
        __IOM uint32_t GPIOLPMSEL0;  /*!< 0x000024f0 */ 
       
        struct
        {
            __IOM uint32_t GPIO0                     : 1 ;     /*!< [0:0] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO1                     : 1 ;     /*!< [1:1] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO2                     : 1 ;     /*!< [2:2] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO3                     : 1 ;     /*!< [3:3] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO4                     : 1 ;     /*!< [4:4] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO5                     : 1 ;     /*!< [5:5] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO6                     : 1 ;     /*!< [6:6] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO7                     : 1 ;     /*!< [7:7] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO8                     : 1 ;     /*!< [8:8] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO9                     : 1 ;     /*!< [9:9] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO10                    : 1 ;     /*!< [10:10] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO11                    : 1 ;     /*!< [11:11] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO12                    : 1 ;     /*!< [12:12] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO13                    : 1 ;     /*!< [13:13] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO14                    : 1 ;     /*!< [14:14] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO15                    : 1 ;     /*!< [15:15] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO16                    : 1 ;     /*!< [16:16] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO17                    : 1 ;     /*!< [17:17] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO18                    : 1 ;     /*!< [18:18] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO19                    : 1 ;     /*!< [19:19] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO20                    : 1 ;     /*!< [20:20] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO21                    : 1 ;     /*!< [21:21] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO22                    : 1 ;     /*!< [22:22] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO23                    : 1 ;     /*!< [23:23] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO24                    : 1 ;     /*!< [24:24] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO25                    : 1 ;     /*!< [25:25] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO26                    : 1 ;     /*!< [26:26] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO27                    : 1 ;     /*!< [27:27] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO28                    : 1 ;     /*!< [28:28] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO29                    : 1 ;     /*!< [29:29] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO30                    : 1 ;     /*!< [30:30] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO31                    : 1 ;     /*!< [31:31] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
        } GPIOLPMSEL0b;
    };

    union
    {
        __IOM uint32_t GPIOLPMSEL1;  /*!< 0x000024f4 */ 
       
        struct
        {
            __IOM uint32_t GPIO32                    : 1 ;     /*!< [0:0] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO33                    : 1 ;     /*!< [1:1] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO34                    : 1 ;     /*!< [2:2] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO35                    : 1 ;     /*!< [3:3] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO36                    : 1 ;     /*!< [4:4] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO37                    : 1 ;     /*!< [5:5] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO38                    : 1 ;     /*!< [6:6] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO39                    : 1 ;     /*!< [7:7] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO40                    : 1 ;     /*!< [8:8] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO41                    : 1 ;     /*!< [9:9] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO42                    : 1 ;     /*!< [10:10] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO43                    : 1 ;     /*!< [11:11] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO44                    : 1 ;     /*!< [12:12] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO45                    : 1 ;     /*!< [13:13] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO46                    : 1 ;     /*!< [14:14] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO47                    : 1 ;     /*!< [15:15] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO48                    : 1 ;     /*!< [16:16] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO49                    : 1 ;     /*!< [17:17] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO50                    : 1 ;     /*!< [18:18] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO51                    : 1 ;     /*!< [19:19] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO52                    : 1 ;     /*!< [20:20] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO53                    : 1 ;     /*!< [21:21] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO54                    : 1 ;     /*!< [22:22] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO55                    : 1 ;     /*!< [23:23] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO56                    : 1 ;     /*!< [24:24] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO57                    : 1 ;     /*!< [25:25] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO58                    : 1 ;     /*!< [26:26] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO59                    : 1 ;     /*!< [27:27] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO60                    : 1 ;     /*!< [28:28] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO61                    : 1 ;     /*!< [29:29] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO62                    : 1 ;     /*!< [30:30] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t GPIO63                    : 1 ;     /*!< [31:31] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit<br>  Reset type: SYSRSn                                              <br>. */
        } GPIOLPMSEL1b;
    };

    union
    {
        __IOM uint32_t TMR2CLKCTL;  /*!< 0x000024f8 */ 
       
        struct
        {
            __IOM uint32_t TMR2CLKSRCSEL             : 3 ;     /*!< [2:0] : CPU Timer 2 Clock Source Select Bit: This bit selects the source for CPU Timer 2:<br>  000 =SYSCLK Selected (default on reset, pre-scale is bypassed)  <br>  001 = INTOSC1                                                   <br>  010 = INTOSC2                                                   <br>  011 = XTAL                                                      <br>  100 = Reserved                                                  <br>  101 = Reserved                                                  <br>  110 = AUXPLLCLK                                                 <br>  111 = reserved                                                  <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t TMR2CLKPRESCALE           : 3 ;     /*!< [5:3] : CPU Timer 2 Clock Pre-Scale Value: These bits select the pre-scale value for the selected clock source for CPU Timer 2:<br>  0,0,0,/1 (default on reset)                                     <br>  0,0,1,/2,                                                       <br>  0,1,0,/4                                                        <br>  0,1,1,/8                                                        <br>  1,0,0,/16                                                       <br>  1,0,1,spare (defaults to /16)                                   <br>  1,1,0,spare (defaults to /16)                                   <br>  1,1,1,spare (defaults to /16)                                   <br>  Note:                                                           <br>  [1] The CPU Timer2s Clock sync logic detects an input clock edge when configured for any clock source other than SYSCLK and generates an appropriate clock pulse to the CPU timer2. */
                  uint32_t RSV_0                     : 26;     /*!< [31:6] : reserved. */
        } TMR2CLKCTLb;
    };

    uint8_t    RSV_0X24FC[4];   /*!< 0x000024fc~0x000024ff : reserved */

    union
    {
        __IOM uint32_t RESC;  /*!< 0x00002500 */ 
       
        struct
        {
            __IOM uint32_t POR                       : 1 ;     /*!< [0:0] : If this bit is set, indicates that the device was reset by PORn. */
            __IOM uint32_t XRSN                      : 1 ;     /*!< [1:1] : If this bit is set, indicates that the device was reset by XRSn. */
            __IOM uint32_t WDRSN                     : 1 ;     /*!< [2:2] : If this bit is set, indicates that the device was reset by WDRSn. */
            __IOM uint32_t NMIWDRSN                  : 1 ;     /*!< [3:3] : If this bit is set, indicates that the device was reset by NMIWDRSn. */
                  uint32_t RSV_0                     : 26;     /*!< [29:4] : reserved. */
            __IM  uint32_t XRSN_PIN_STATUS           : 1 ;     /*!< [30:30] : Reading this bit provides the current status of the XRSn pin. */
            __IM  uint32_t TRSTN_PIN_STATUS          : 1 ;     /*!< [31:31] : Reading this bit provides the current status of TRSTn at the respective C28x CPUs TRSTn input port. */
        } RESCb;
    };

    uint8_t    RSV_0X2504[28];   /*!< 0x00002504~0x0000251f : reserved */

    union
    {
        __IOM uint32_t DWTMR2CLKCTL;  /*!< 0x00002520 */ 
       
        struct
        {
            __IOM uint32_t DWTMR2CLKSRCSEL           : 3 ;     /*!< [2:0] : DW CPU Timer 2 Clock Source Select Bit: This bit selects the source for CPU Timer 2:<br>  000 =SYSCLK Selected (default on reset, pre-scale is bypassed)  <br>  001 = INTOSC1                                                   <br>  010 = INTOSC2                                                   <br>  011 = XTAL                                                      <br>  100 = Reserved                                                  <br>  101 = Reserved                                                  <br>  110 = AUXPLLCLK                                                 <br>  111 = reserved                                                  <br>  Reset type: SYSRSn                                              <br>. */
            __IOM uint32_t DWTMR2CLKPRESCALE         : 3 ;     /*!< [5:3] : DW CPU Timer 2 Clock Pre-Scale Value: These bits select the pre-scale value for the selected clock source for CPU Timer 2:<br>  0,0,0,/1 (default on reset)                                     <br>  0,0,1,/2,                                                       <br>  0,1,0,/4                                                        <br>  0,1,1,/8                                                        <br>  1,0,0,/16                                                       <br>  1,0,1,spare (defaults to /16)                                   <br>  1,1,0,spare (defaults to /16)                                   <br>  1,1,1,spare (defaults to /16)                                   <br>  Note:                                                           <br>  [1] The CPU Timer2s Clock sync logic detects an input clock edge when configured for any clock source other than SYSCLK and generates an appropriate clock pulse to the CPU timer2. */
                  uint32_t RSV_0                     : 26;     /*!< [31:6] : reserved. */
        } DWTMR2CLKCTLb;
    };

    uint8_t    RSV_0X2524[28];   /*!< 0x00002524~0x0000253f : reserved */

    union
    {
        __IOM uint32_t TFUCR;  /*!< 0x00002540 */ 
       
        struct
        {
            __IOM uint32_t TFU                       : 1 ;     /*!< [0:0] : TFU Clock Enable bit:                                           <br>  0: Module clock is gated-off                                    <br>  1: Module clock is turned-on                                    <br>  Notes:                                                          <br>  [1] These bits are not used (R/W) in CPU2 register. */
                  uint32_t RSV_0                     : 31;     /*!< [31:1] : reserved. */
        } TFUCRb;
    };

    union
    {
        __IOM uint32_t CRCCR;  /*!< 0x00002544 */ 
       
        struct
        {
            __IOM uint32_t CRC                       : 1 ;     /*!< [0:0] : CRC Clock Enable bit:                                           <br>  0: Module clock is gated-off                                    <br>  1: Module clock is turned-on                                    <br>  Notes:                                                          <br>  [1] These bits are not used (R/W) in CPU2 register. */
                  uint32_t RSV_0                     : 31;     /*!< [31:1] : reserved. */
        } CRCCRb;
    };
} CPU_SYS_REGS_Type;

/*! \brief MEM_CFG_REGS register */
typedef struct {
    uint8_t    RSV_0X2800[128];   /*!< 0x00002800~0x0000287f : reserved */

    union
    {
        __IOM uint32_t GSXLOCK;  /*!< 0x00002880 */ 
       
        struct
        {
            __IOM uint32_t LOCK_GS0                  : 1 ;     /*!< [0:0] : Locks the write to access protection and master select fields for GS0 RAM:<br>  0: Write to ACCPROT and Mselect fields are allowed. */
            __IOM uint32_t LOCK_GS1                  : 1 ;     /*!< [1:1] : Locks the write to access protection and master select fields for GS1 RAM:<br>  0: Write to ACCPROT and Mselect fields are allowed. */
            __IOM uint32_t LOCK_GS2                  : 1 ;     /*!< [2:2] : Locks the write to access protection and master select fields for GS2 RAM:<br>  0: Write to ACCPROT and Mselect fields are allowed. */
            __IOM uint32_t LOCK_GS3                  : 1 ;     /*!< [3:3] : Locks the write to access protection and master select fields for GS3 RAM:<br>  0: Write to ACCPROT and Mselect fields are allowed. */
            __IOM uint32_t LOCK_GS4                  : 1 ;     /*!< [4:4] : Locks the write to access protection and master select fields for GS4 RAM:<br>  0: Write to ACCPROT and Mselect fields are allowed. */
            __IOM uint32_t LOCK_GS5                  : 1 ;     /*!< [5:5] : Locks the write to access protection and master select fields for GS5 RAM:<br>  0: Write to ACCPROT and Mselect fields are allowed. */
            __IOM uint32_t LOCK_GS6                  : 1 ;     /*!< [6:6] : Locks the write to access protection and master select fields for GS6 RAM:<br>  0: Write to ACCPROT and Mselect fields are allowed. */
            __IOM uint32_t LOCK_GS7                  : 1 ;     /*!< [7:7] : Locks the write to access protection and master select fields for GS7 RAM:<br>  0: Write to ACCPROT and Mselect fields are allowed. */
            __IOM uint32_t LOCK_GS8                  : 1 ;     /*!< [8:8] : Locks the write to access protection and master select fields for GS8 RAM:<br>  0: Write to ACCPROT and Mselect fields are allowed. */
            __IOM uint32_t LOCK_GS9                  : 1 ;     /*!< [9:9] : Locks the write to access protection and master select fields for GS9 RAM:<br>  0: Write to ACCPROT and Mselect fields are allowed. */
            __IOM uint32_t LOCK_GS10                 : 1 ;     /*!< [10:10] : Locks the write to access protection and master select fields for GS10 RAM:<br>  0: Write to ACCPROT and Mselect fields are allowed. */
            __IOM uint32_t LOCK_GS11                 : 1 ;     /*!< [11:11] : Locks the write to access protection and master select fields for GS11 RAM:<br>  0: Write to ACCPROT and Mselect fields are allowed. */
            __IOM uint32_t LOCK_GS12                 : 1 ;     /*!< [12:12] : Locks the write to access protection and master select fields for GS12 RAM:<br>  0: Write to ACCPROT and Mselect fields are allowed. */
            __IOM uint32_t LOCK_GS13                 : 1 ;     /*!< [13:13] : Locks the write to access protection and master select fields for GS13 RAM:<br>  0: Write to ACCPROT and Mselect fields are allowed. */
            __IOM uint32_t LOCK_GS14                 : 1 ;     /*!< [14:14] : Locks the write to access protection and master select fields for GS14 RAM:<br>  0: Write to ACCPROT and Mselect fields are allowed. */
            __IOM uint32_t LOCK_GS15                 : 1 ;     /*!< [15:15] : Locks the write to access protection and master select fields for GS15 RAM:<br>  0: Write to ACCPROT and Mselect fields are allowed. */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } GSXLOCKb;
    };

    union
    {
        __IOM uint32_t GSXCOMMIT;  /*!< 0x00002884 */ 
       
        struct
        {
            __IOM uint32_t COMMIT_GS0                : 1 ;     /*!< [0:0] : Permanently Locks the write to access protection and master select fields for GS0 RAM:<br>  0: Write to ACCPROT and Mselect fields are allowed based on value of lock field in GSxLOCK register. */
            __IOM uint32_t COMMIT_GS1                : 1 ;     /*!< [1:1] : Permanently Locks the write to access protection and master select fields for GS1 RAM:<br>  0: Write to ACCPROT and Mselect fields are allowed based on value of lock field in GSxLOCK register. */
            __IOM uint32_t COMMIT_GS2                : 1 ;     /*!< [2:2] : Permanently Locks the write to access protection and master select fields for GS2 RAM:<br>  0: Write to ACCPROT and Mselect fields are allowed based on value of lock field in GSxLOCK register. */
            __IOM uint32_t COMMIT_GS3                : 1 ;     /*!< [3:3] : Permanently Locks the write to access protection and master select fields for GS3 RAM:<br>  0: Write to ACCPROT and Mselect fields are allowed based on value of lock field in GSxLOCK register. */
            __IOM uint32_t COMMIT_GS4                : 1 ;     /*!< [4:4] : Permanently Locks the write to access protection and master select fields for GS4 RAM:<br>  0: Write to ACCPROT and Mselect fields are allowed based on value of lock field in GSxLOCK register. */
            __IOM uint32_t COMMIT_GS5                : 1 ;     /*!< [5:5] : Permanently Locks the write to access protection and master select fields for GS5 RAM:<br>  0: Write to ACCPROT and Mselect fields are allowed based on value of lock field in GSxLOCK register. */
            __IOM uint32_t COMMIT_GS6                : 1 ;     /*!< [6:6] : Permanently Locks the write to access protection and master select fields for GS6 RAM:<br>  0: Write to ACCPROT and Mselect fields are allowed based on value of lock field in GSxLOCK register. */
            __IOM uint32_t COMMIT_GS7                : 1 ;     /*!< [7:7] : Permanently Locks the write to access protection and master select fields for GS7 RAM:<br>  0: Write to ACCPROT and Mselect fields are allowed based on value of lock field in GSxLOCK register. */
            __IOM uint32_t COMMIT_GS8                : 1 ;     /*!< [8:8] : Permanently Locks the write to access protection and master select fields for GS2 RAM:<br>  0: Write to ACCPROT and Mselect fields are allowed based on value of lock field in GSxLOCK register. */
            __IOM uint32_t COMMIT_GS9                : 1 ;     /*!< [9:9] : Permanently Locks the write to access protection and master select fields for GS9 RAM:<br>  0: Write to ACCPROT and Mselect fields are allowed based on value of lock field in GSxLOCK register. */
            __IOM uint32_t COMMIT_GS10               : 1 ;     /*!< [10:10] : Permanently Locks the write to access protection and master select fields for GS10 RAM:<br>  0: Write to ACCPROT and Mselect fields are allowed based on value of lock field in GSxLOCK register. */
            __IOM uint32_t COMMIT_GS11               : 1 ;     /*!< [11:11] : Permanently Locks the write to access protection and master select fields for GS11 RAM:<br>  0: Write to ACCPROT and Mselect fields are allowed based on value of lock field in GSxLOCK register. */
            __IOM uint32_t COMMIT_GS12               : 1 ;     /*!< [12:12] : Permanently Locks the write to access protection and master select fields for GS12 RAM:<br>  0: Write to ACCPROT and Mselect fields are allowed based on value of lock field in GSxLOCK register. */
            __IOM uint32_t COMMIT_GS13               : 1 ;     /*!< [13:13] : Permanently Locks the write to access protection and master select fields for GS13 RAM:<br>  0: Write to ACCPROT and Mselect fields are allowed based on value of lock field in GSxLOCK register. */
            __IOM uint32_t COMMIT_GS14               : 1 ;     /*!< [14:14] : Permanently Locks the write to access protection and master select fields for GS14 RAM:<br>  0: Write to ACCPROT and Mselect fields are allowed based on value of lock field in GSxLOCK register. */
            __IOM uint32_t COMMIT_GS15               : 1 ;     /*!< [15:15] : Permanently Locks the write to access protection and master select fields for GS15 RAM:<br>  0: Write to ACCPROT and Mselect fields are allowed based on value of lock field in GSxLOCK register. */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } GSXCOMMITb;
    };

    union
    {
        __IOM uint32_t GSXMSEL;  /*!< 0x00002888 */ 
       
        struct
        {
            __IOM uint32_t MSEL_GS0                  : 2 ;     /*!< [1:0] : Master Select for GS0 RAM:                                      <br>  00: CPU1 is master for this memory. */
            __IOM uint32_t MSEL_GS1                  : 2 ;     /*!< [3:2] : Master Select for GS1 RAM:                                      <br>  00: CPU1 is master for this memory. */
            __IOM uint32_t MSEL_GS2                  : 2 ;     /*!< [5:4] : Master Select for GS2 RAM:                                      <br>  00: CPU1 is master for this memory. */
            __IOM uint32_t MSEL_GS3                  : 2 ;     /*!< [7:6] : Master Select for GS3 RAM:                                      <br>  00: CPU1 is master for this memory. */
            __IOM uint32_t MSEL_GS4                  : 2 ;     /*!< [9:8] : Master Select for GS4 RAM:                                      <br>  00: CPU1 is master for this memory. */
            __IOM uint32_t MSEL_GS5                  : 2 ;     /*!< [11:10] : Master Select for GS5 RAM:                                      <br>  00: CPU1 is master for this memory. */
            __IOM uint32_t MSEL_GS6                  : 2 ;     /*!< [13:12] : Master Select for GS6 RAM:                                      <br>  00: CPU1 is master for this memory. */
            __IOM uint32_t MSEL_GS7                  : 2 ;     /*!< [15:14] : Master Select for GS7 RAM:                                      <br>  00: CPU1 is master for this memory. */
            __IOM uint32_t MSEL_GS8                  : 2 ;     /*!< [17:16] : Master Select for GS8 RAM:                                      <br>  00: CPU1 is master for this memory. */
            __IOM uint32_t MSEL_GS9                  : 2 ;     /*!< [19:18] : Master Select for GS9 RAM:                                      <br>  00: CPU1 is master for this memory. */
            __IOM uint32_t MSEL_GS10                 : 2 ;     /*!< [21:20] : Master Select for GS10 RAM:                                     <br>  00: CPU1 is master for this memory. */
            __IOM uint32_t MSEL_GS11                 : 2 ;     /*!< [23:22] : Master Select for GS11 RAM:                                     <br>  00: CPU1 is master for this memory. */
            __IOM uint32_t MSEL_GS12                 : 2 ;     /*!< [25:24] : Master Select for GS12 RAM:                                     <br>  00: CPU1 is master for this memory. */
            __IOM uint32_t MSEL_GS13                 : 2 ;     /*!< [27:26] : Master Select for GS13 RAM:                                     <br>  00: CPU1 is master for this memory. */
            __IOM uint32_t MSEL_GS14                 : 2 ;     /*!< [29:28] : Master Select for GS14 RAM:                                     <br>  00: CPU1 is master for this memory. */
            __IOM uint32_t MSEL_GS15                 : 2 ;     /*!< [31:30] : Master Select for GS15 RAM:                                     <br>  00: CPU1 is master for this memory. */
        } GSXMSELb;
    };

    uint8_t    RSV_0X288C[4];   /*!< 0x0000288c~0x0000288f : reserved */

    union
    {
        __IOM uint32_t GSXACCPROT0;  /*!< 0x00002890 */ 
       
        struct
        {
                  uint32_t RSV_4                     : 1 ;     /*!< [0:0] : reserved. */
            __IOM uint32_t CPUWRPROT_GS0             : 1 ;     /*!< [1:1] : CPU WR Protection For GS0 RAM:                                  <br>  0: CPU Writes are allowed. */
            __IOM uint32_t DMAWRPROT_GS0             : 1 ;     /*!< [2:2] : DMA WR Protection For GS0 RAM:                                  <br>  0: DMA Writes are allowed. */
                  uint32_t RSV_3                     : 6 ;     /*!< [8:3] : reserved. */
            __IOM uint32_t CPUWRPROT_GS1             : 1 ;     /*!< [9:9] : CPU WR Protection For GS1 RAM:                                  <br>  0: CPU Writes are allowed. */
            __IOM uint32_t DMAWRPROT_GS1             : 1 ;     /*!< [10:10] : DMA WR Protection For GS1 RAM:                                  <br>  0: DMA Writes are allowed. */
                  uint32_t RSV_2                     : 6 ;     /*!< [16:11] : reserved. */
            __IOM uint32_t CPUWRPROT_GS2             : 1 ;     /*!< [17:17] : CPU WR Protection For GS2 RAM:                                  <br>  0: CPU Writes are allowed. */
            __IOM uint32_t DMAWRPROT_GS2             : 1 ;     /*!< [18:18] : DMA WR Protection For GS2 RAM:                                  <br>  0: DMA Writes are allowed. */
                  uint32_t RSV_1                     : 6 ;     /*!< [24:19] : reserved. */
            __IOM uint32_t CPUWRPROT_GS3             : 1 ;     /*!< [25:25] : CPU WR Protection For GS3 RAM:                                  <br>  0: CPU Writes are allowed. */
            __IOM uint32_t DMAWRPROT_GS3             : 1 ;     /*!< [26:26] : DMA WR Protection For GS3 RAM:                                  <br>  0: DMA Writes are allowed. */
                  uint32_t RSV_0                     : 5 ;     /*!< [31:27] : reserved. */
        } GSXACCPROT0b;
    };

    union
    {
        __IOM uint32_t GSXACCPROT1;  /*!< 0x00002894 */ 
       
        struct
        {
                  uint32_t RSV_4                     : 1 ;     /*!< [0:0] : reserved. */
            __IOM uint32_t CPUWRPROT_GS4             : 1 ;     /*!< [1:1] : CPU WR Protection For GS4 RAM: 0: CPU Writes are allowed. */
            __IOM uint32_t DMAWRPROT_GS4             : 1 ;     /*!< [2:2] : DMA WR Protection For GS4 RAM: 0: DMA Writes are allowed. */
                  uint32_t RSV_3                     : 6 ;     /*!< [8:3] : reserved. */
            __IOM uint32_t CPUWRPROT_GS5             : 1 ;     /*!< [9:9] : CPU WR Protection For GS5 RAM: 0: CPU Writes are allowed. */
            __IOM uint32_t DMAWRPROT_GS5             : 1 ;     /*!< [10:10] : DMA WR Protection For GS5 RAM: 0: DMA Writes are allowed. */
                  uint32_t RSV_2                     : 6 ;     /*!< [16:11] : reserved. */
            __IOM uint32_t CPUWRPROT_GS6             : 1 ;     /*!< [17:17] : CPU WR Protection For GS6 RAM: 0: CPU Writes are allowed. */
            __IOM uint32_t DMAWRPROT_GS6             : 1 ;     /*!< [18:18] : DMA WR Protection For GS6 RAM: 0: DMA Writes are allowed. */
                  uint32_t RSV_1                     : 6 ;     /*!< [24:19] : reserved. */
            __IOM uint32_t CPUWRPROT_GS7             : 1 ;     /*!< [25:25] : CPU WR Protection For GS7 RAM: 0: CPU Writes are allowed. */
            __IOM uint32_t DMAWRPROT_GS7             : 1 ;     /*!< [26:26] : DMA WR Protection For GS7 RAM: 0: DMA Writes are allowed. */
                  uint32_t RSV_0                     : 5 ;     /*!< [31:27] : reserved. */
        } GSXACCPROT1b;
    };

    union
    {
        __IOM uint32_t GSXACCPROT2;  /*!< 0x00002898 */ 
       
        struct
        {
                  uint32_t RSV_4                     : 1 ;     /*!< [0:0] : reserved. */
            __IOM uint32_t CPUWRPROT_GS8             : 1 ;     /*!< [1:1] : CPU WR Protection For GS8 RAM: 0: CPU Writes are allowed. */
            __IOM uint32_t DMAWRPROT_GS8             : 1 ;     /*!< [2:2] : DMA WR Protection For GS8 RAM: 0: DMA Writes are allowed. */
                  uint32_t RSV_3                     : 6 ;     /*!< [8:3] : reserved. */
            __IOM uint32_t CPUWRPROT_GS9             : 1 ;     /*!< [9:9] : CPU WR Protection For GS9 RAM: 0: CPU Writes are allowed. */
            __IOM uint32_t DMAWRPROT_GS9             : 1 ;     /*!< [10:10] : DMA WR Protection For GS9 RAM: 0: DMA Writes are allowed. */
                  uint32_t RSV_2                     : 6 ;     /*!< [16:11] : reserved. */
            __IOM uint32_t CPUWRPROT_GS10            : 1 ;     /*!< [17:17] : CPU WR Protection For GS10 RAM: 0: CPU Writes are allowed. */
            __IOM uint32_t DMAWRPROT_GS10            : 1 ;     /*!< [18:18] : DMA WR Protection For GS10 RAM: 0: DMA Writes are allowed. */
                  uint32_t RSV_1                     : 6 ;     /*!< [24:19] : reserved. */
            __IOM uint32_t CPUWRPROT_GS11            : 1 ;     /*!< [25:25] : CPU WR Protection For GS11 RAM: 0: CPU Writes are allowed. */
            __IOM uint32_t DMAWRPROT_GS11            : 1 ;     /*!< [26:26] : DMA WR Protection For GS11 RAM: 0: DMA Writes are allowed. */
                  uint32_t RSV_0                     : 5 ;     /*!< [31:27] : reserved. */
        } GSXACCPROT2b;
    };

    union
    {
        __IOM uint32_t GSXACCPROT3;  /*!< 0x0000289c */ 
       
        struct
        {
                  uint32_t RSV_4                     : 1 ;     /*!< [0:0] : reserved. */
            __IOM uint32_t CPUWRPROT_GS12            : 1 ;     /*!< [1:1] : CPU WR Protection For GS12 RAM: 0: CPU Writes are allowed. */
            __IOM uint32_t DMAWRPROT_GS12            : 1 ;     /*!< [2:2] : DMA WR Protection For GS12 RAM: 0: DMA Writes are allowed. */
                  uint32_t RSV_3                     : 6 ;     /*!< [8:3] : reserved. */
            __IOM uint32_t CPUWRPROT_GS13            : 1 ;     /*!< [9:9] : CPU WR Protection For GS13 RAM: 0: CPU Writes are allowed. */
            __IOM uint32_t DMAWRPROT_GS13            : 1 ;     /*!< [10:10] : DMA WR Protection For GS13 RAM: 0: DMA Writes are allowed. */
                  uint32_t RSV_2                     : 6 ;     /*!< [16:11] : reserved. */
            __IOM uint32_t CPUWRPROT_GS14            : 1 ;     /*!< [17:17] : CPU WR Protection For GS14 RAM: 0: CPU Writes are allowed. */
            __IOM uint32_t DMAWRPROT_GS14            : 1 ;     /*!< [18:18] : DMA WR Protection For GS14 RAM: 0: DMA Writes are allowed. */
                  uint32_t RSV_1                     : 6 ;     /*!< [24:19] : reserved. */
            __IOM uint32_t CPUWRPROT_GS15            : 1 ;     /*!< [25:25] : CPU WR Protection For GS15 RAM: 0: CPU Writes are allowed. */
            __IOM uint32_t DMAWRPROT_GS15            : 1 ;     /*!< [26:26] : DMA WR Protection For GS15 RAM: 0: DMA Writes are allowed. */
                  uint32_t RSV_0                     : 5 ;     /*!< [31:27] : reserved. */
        } GSXACCPROT3b;
    };

    union
    {
        __IOM uint32_t GSXTEST;  /*!< 0x000028a0 */ 
       
        struct
        {
            __IOM uint32_t TEST_GS0                  : 2 ;     /*!< [1:0] : Selects the different modes for GS0 RAM:                        <br>  00: Functional Mode. */
            __IOM uint32_t TEST_GS1                  : 2 ;     /*!< [3:2] : Selects the different modes for GS1 RAM:                        <br>  00: Functional Mode. */
            __IOM uint32_t TEST_GS2                  : 2 ;     /*!< [5:4] : Selects the different modes for GS2 RAM:                        <br>  00: Functional Mode. */
            __IOM uint32_t TEST_GS3                  : 2 ;     /*!< [7:6] : Selects the different modes for GS3 RAM:                        <br>  00: Functional Mode. */
            __IOM uint32_t TEST_GS4                  : 2 ;     /*!< [9:8] : Selects the different modes for GS4 RAM:                        <br>  00: Functional Mode. */
            __IOM uint32_t TEST_GS5                  : 2 ;     /*!< [11:10] : Selects the different modes for GS5 RAM:                        <br>  00: Functional Mode. */
            __IOM uint32_t TEST_GS6                  : 2 ;     /*!< [13:12] : Selects the different modes for GS6 RAM:                        <br>  00: Functional Mode. */
            __IOM uint32_t TEST_GS7                  : 2 ;     /*!< [15:14] : Selects the different modes for GS7 RAM:                        <br>  00: Functional Mode. */
            __IOM uint32_t TEST_GS8                  : 2 ;     /*!< [17:16] : Selects the different modes for GS8 RAM:                        <br>  00: Functional Mode. */
            __IOM uint32_t TEST_GS9                  : 2 ;     /*!< [19:18] : Selects the different modes for GS9 RAM:                        <br>  00: Functional Mode. */
            __IOM uint32_t TEST_GS10                 : 2 ;     /*!< [21:20] : Selects the different modes for GS10 RAM:                       <br>  00: Functional Mode. */
            __IOM uint32_t TEST_GS11                 : 2 ;     /*!< [23:22] : Selects the different modes for GS11 RAM:                       <br>  00: Functional Mode. */
            __IOM uint32_t TEST_GS12                 : 2 ;     /*!< [25:24] : Selects the different modes for GS12 RAM:                       <br>  00: Functional Mode. */
            __IOM uint32_t TEST_GS13                 : 2 ;     /*!< [27:26] : Selects the different modes for GS13 RAM:                       <br>  00: Functional Mode. */
            __IOM uint32_t TEST_GS14                 : 2 ;     /*!< [29:28] : Selects the different modes for GS14 RAM:                       <br>  00: Functional Mode. */
            __IOM uint32_t TEST_GS15                 : 2 ;     /*!< [31:30] : Selects the different modes for GS15 RAM:                       <br>  00: Functional Mode. */
        } GSXTESTb;
    };

    union
    {
        __IOM uint32_t GSXINIT;  /*!< 0x000028a4 */ 
       
        struct
        {
            __IOM uint32_t INIT_GS0                  : 1 ;     /*!< [0:0] : RAM Initialization control for GS0 RAM: 0: None. */
            __IOM uint32_t INIT_GS1                  : 1 ;     /*!< [1:1] : RAM Initialization control for GS1 RAM: 0: None. */
            __IOM uint32_t INIT_GS2                  : 1 ;     /*!< [2:2] : RAM Initialization control for GS2 RAM: 0: None. */
            __IOM uint32_t INIT_GS3                  : 1 ;     /*!< [3:3] : RAM Initialization control for GS3 RAM: 0: None. */
            __IOM uint32_t INIT_GS4                  : 1 ;     /*!< [4:4] : RAM Initialization control for GS4 RAM: 0: None. */
            __IOM uint32_t INIT_GS5                  : 1 ;     /*!< [5:5] : RAM Initialization control for GS5 RAM: 0: None. */
            __IOM uint32_t INIT_GS6                  : 1 ;     /*!< [6:6] : RAM Initialization control for GS6 RAM: 0: None. */
            __IOM uint32_t INIT_GS7                  : 1 ;     /*!< [7:7] : RAM Initialization control for GS7 RAM: 0: None. */
            __IOM uint32_t INIT_GS8                  : 1 ;     /*!< [8:8] : RAM Initialization control for GS8 RAM: 0: None. */
            __IOM uint32_t INIT_GS9                  : 1 ;     /*!< [9:9] : RAM Initialization control for GS9 RAM: 0: None. */
            __IOM uint32_t INIT_GS10                 : 1 ;     /*!< [10:10] : RAM Initialization control for GS10 RAM: 0: None. */
            __IOM uint32_t INIT_GS11                 : 1 ;     /*!< [11:11] : RAM Initialization control for GS11 RAM: 0: None. */
            __IOM uint32_t INIT_GS12                 : 1 ;     /*!< [12:12] : RAM Initialization control for GS12 RAM: 0: None. */
            __IOM uint32_t INIT_GS13                 : 1 ;     /*!< [13:13] : RAM Initialization control for GS13 RAM: 0: None. */
            __IOM uint32_t INIT_GS14                 : 1 ;     /*!< [14:14] : RAM Initialization control for GS14 RAM: 0: None. */
            __IOM uint32_t INIT_GS15                 : 1 ;     /*!< [15:15] : RAM Initialization control for GS15 RAM: 0: None. */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } GSXINITb;
    };

    union
    {
        __IM uint32_t GSXINITDONE;  /*!< 0x000028a8 */ 
       
        struct
        {
            __IM  uint32_t INITDONE_GS0              : 1 ;     /*!< [0:0] : RAM Initialization status for GS0 RAM: 0: RAM Initialization is not done. */
            __IM  uint32_t INITDONE_GS1              : 1 ;     /*!< [1:1] : RAM Initialization status for GS1 RAM: 0: RAM Initialization is not done. */
            __IM  uint32_t INITDONE_GS2              : 1 ;     /*!< [2:2] : RAM Initialization status for GS2 RAM: 0: RAM Initialization is not done. */
            __IM  uint32_t INITDONE_GS3              : 1 ;     /*!< [3:3] : RAM Initialization status for GS3 RAM: 0: RAM Initialization is not done. */
            __IM  uint32_t INITDONE_GS4              : 1 ;     /*!< [4:4] : RAM Initialization status for GS4 RAM: 0: RAM Initialization is not done. */
            __IM  uint32_t INITDONE_GS5              : 1 ;     /*!< [5:5] : RAM Initialization status for GS5 RAM: 0: RAM Initialization is not done. */
            __IM  uint32_t INITDONE_GS6              : 1 ;     /*!< [6:6] : RAM Initialization status for GS6 RAM: 0: RAM Initialization is not done. */
            __IM  uint32_t INITDONE_GS7              : 1 ;     /*!< [7:7] : RAM Initialization status for GS7 RAM: 0: RAM Initialization is not done. */
            __IM  uint32_t INITDONE_GS8              : 1 ;     /*!< [8:8] : RAM Initialization status for GS8 RAM: 0: RAM Initialization is not done. */
            __IM  uint32_t INITDONE_GS9              : 1 ;     /*!< [9:9] : RAM Initialization status for GS9 RAM: 0: RAM Initialization is not done. */
            __IM  uint32_t INITDONE_GS10             : 1 ;     /*!< [10:10] : RAM Initialization status for GS10 RAM: 0: RAM Initialization is not done. */
            __IM  uint32_t INITDONE_GS11             : 1 ;     /*!< [11:11] : RAM Initialization status for GS11 RAM: 0: RAM Initialization is not done. */
            __IM  uint32_t INITDONE_GS12             : 1 ;     /*!< [12:12] : RAM Initialization status for GS12 RAM: 0: RAM Initialization is not done. */
            __IM  uint32_t INITDONE_GS13             : 1 ;     /*!< [13:13] : RAM Initialization status for GS13 RAM: 0: RAM Initialization is not done. */
            __IM  uint32_t INITDONE_GS14             : 1 ;     /*!< [14:14] : RAM Initialization status for GS14 RAM:                         <br>  0: RAM Initialization is not done. */
            __IM  uint32_t INITDONE_GS15             : 1 ;     /*!< [15:15] : RAM Initialization status for GS15 RAM:                         <br>  0: RAM Initialization is not done. */
                  uint32_t RSV_0                     : 16;     /*!< [31:16] : reserved. */
        } GSXINITDONEb;
    };

    uint8_t    RSV_0X28AC[52];   /*!< 0x000028ac~0x000028df : reserved */

    union
    {
        __IOM uint32_t MSGXTEST;  /*!< 0x000028e0 */ 
       
        struct
        {
            __IOM uint32_t TEST_CPUTOCPU             : 2 ;     /*!< [1:0] : Selects the different modes for CPUTOCPU MSG RAM:               <br>  00: Functional Mode. */
                  uint32_t RSV_0                     : 30;     /*!< [31:2] : reserved. */
        } MSGXTESTb;
    };

    union
    {
        __IOM uint32_t MSGXINIT;  /*!< 0x000028e4 */ 
       
        struct
        {
            __IOM uint32_t INIT_CPUTOCPU             : 1 ;     /*!< [0:0] : RAM Initialization control for CPUTOCPU MSG RAM: 0: None. */
                  uint32_t RSV_0                     : 31;     /*!< [31:1] : reserved. */
        } MSGXINITb;
    };

    union
    {
        __IM uint32_t MSGXINITDONE;  /*!< 0x000028e8 */ 
       
        struct
        {
            __IM  uint32_t INITDONE_CPUTOCPU         : 1 ;     /*!< [0:0] : RAM Initialization status for CPUTOCPU MSG RAM:                 <br>  0: RAM Initialization is not done. */
                  uint32_t RSV_0                     : 31;     /*!< [31:1] : reserved. */
        } MSGXINITDONEb;
    };

    uint8_t    RSV_0X28EC[20];   /*!< 0x000028ec~0x000028ff : reserved */

    union
    {
        __IOM uint32_t TCMXTEST;  /*!< 0x00002900 */ 
       
        struct
        {
            __IOM uint32_t TEST_ITCM                 : 2 ;     /*!< [1:0] : Selects the different modes for ITCM:                           <br>  00: Functional Mode. */
            __IOM uint32_t TEST_DTCM                 : 2 ;     /*!< [3:2] : Selects the different modes for DTCM:                           <br>  00: Functional Mode. */
                  uint32_t RSV_0                     : 28;     /*!< [31:4] : reserved. */
        } TCMXTESTb;
    };

    union
    {
        __IOM uint32_t TCMXINIT;  /*!< 0x00002904 */ 
       
        struct
        {
            __IOM uint32_t INIT_ITCM                 : 1 ;     /*!< [0:0] : RAM Initialization control for ITCM:                            <br>  0: None. */
            __IOM uint32_t INIT_DTCM                 : 1 ;     /*!< [1:1] : RAM Initialization control for DTCM:                            <br>  0: None. */
                  uint32_t RSV_0                     : 30;     /*!< [31:2] : reserved. */
        } TCMXINITb;
    };

    union
    {
        __IM uint32_t TCMXINITDONE;  /*!< 0x00002908 */ 
       
        struct
        {
            __IM  uint32_t INITDONE_ITCM             : 1 ;     /*!< [0:0] : RAM Initialization status for ITCM:                             <br>  0: RAM Initialization is not done. */
            __IM  uint32_t INITDONE_DTCM             : 1 ;     /*!< [1:1] : RAM Initialization status for DTCM:                             <br>  0: RAM Initialization is not done. */
                  uint32_t RSV_0                     : 30;     /*!< [31:2] : reserved. */
        } TCMXINITDONEb;
    };

    uint8_t    RSV_0X290C[20];   /*!< 0x0000290c~0x0000291f : reserved */

    union
    {
        __IOM uint32_t GSWRALLOWDBG;  /*!< 0x00002920 */ 
       
        struct
        {
            __IOM uint32_t GSWRALLOWDBG              : 1 ;     /*!< [0:0] : Write to GSx SRAM is allowed or not when in CPU debug mode:     <br>  0: Write GSx SRAM depend on GSxMSEL and GSxACCPROT. */
                  uint32_t RSV_0                     : 31;     /*!< [31:1] : reserved. */
        } GSWRALLOWDBGb;
    };

    union
    {
        __IOM uint32_t CANSRAMINIT;  /*!< 0x00002924 */ 
       
        struct
        {
            __IOM uint32_t INIT_CANSRAM              : 1 ;     /*!< [0:0] : RAM Initialization control for ITCM:                            <br>  0: None. */
                  uint32_t RSV_0                     : 31;     /*!< [31:1] : reserved. */
        } CANSRAMINITb;
    };

    union
    {
        __IM uint32_t CANSRAMINITDONE;  /*!< 0x00002928 */ 
       
        struct
        {
            __IM  uint32_t INITDONE_CANSRAM          : 1 ;     /*!< [0:0] : RAM Initialization status for ITCM:                             <br>  0: RAM Initialization is not done. */
                  uint32_t RSV_0                     : 31;     /*!< [31:1] : reserved. */
        } CANSRAMINITDONEb;
    };
} MEM_CFG_REGS_Type;

/*! \brief ACCESS_PROTECTION_REGS register */
typedef struct {
    union
    {
        __IM uint32_t NMAVFLG;  /*!< 0x00002c00 */ 
       
        struct
        {
                  uint32_t RSV_3                     : 1 ;     /*!< [0:0] : reserved. */
            __IM  uint32_t CPUWRITE                  : 1 ;     /*!< [1:1] : Non Master CPU Write Access Violation Flag: 0: No violation. */
                  uint32_t RSV_2                     : 1 ;     /*!< [2:2] : reserved. */
            __IM  uint32_t DMAWRITE                  : 1 ;     /*!< [3:3] : Non Master DMA Write Access Violation Flag: 0: No violation. */
                  uint32_t RSV_1                     : 3 ;     /*!< [6:4] : reserved. */
            __IM  uint32_t USBADMAWRITE              : 1 ;     /*!< [7:7] : Non Master USB_A DMA Write Access Violation Flag: 0: No violation. */
                  uint32_t RSV_0                     : 24;     /*!< [31:8] : reserved. */
        } NMAVFLGb;
    };

    union
    {
        __IOM uint32_t NMAVSET;  /*!< 0x00002c04 */ 
       
        struct
        {
                  uint32_t RSV_3                     : 1 ;     /*!< [0:0] : reserved. */
            __IOM uint32_t CPUWRITE                  : 1 ;     /*!< [1:1] : 0: No action. */
                  uint32_t RSV_2                     : 1 ;     /*!< [2:2] : reserved. */
            __IOM uint32_t DMAWRITE                  : 1 ;     /*!< [3:3] : 0: No action. */
                  uint32_t RSV_1                     : 3 ;     /*!< [6:4] : reserved. */
            __IOM uint32_t USBADMAWRITE              : 1 ;     /*!< [7:7] : 0: No action. */
                  uint32_t RSV_0                     : 24;     /*!< [31:8] : reserved. */
        } NMAVSETb;
    };

    union
    {
        __IOM uint32_t NMAVCLR;  /*!< 0x00002c08 */ 
       
        struct
        {
                  uint32_t RSV_3                     : 1 ;     /*!< [0:0] : reserved. */
            __IOM uint32_t CPUWRITE                  : 1 ;     /*!< [1:1] : 0: No action. */
                  uint32_t RSV_2                     : 1 ;     /*!< [2:2] : reserved. */
            __IOM uint32_t DMAWRITE                  : 1 ;     /*!< [3:3] : 0: No action. */
                  uint32_t RSV_1                     : 3 ;     /*!< [6:4] : reserved. */
            __IOM uint32_t USBADMAWRITE              : 1 ;     /*!< [7:7] : 0: No action. */
                  uint32_t RSV_0                     : 24;     /*!< [31:8] : reserved. */
        } NMAVCLRb;
    };

    union
    {
        __IOM uint32_t NMAVINTEN;  /*!< 0x00002c0c */ 
       
        struct
        {
                  uint32_t RSV_3                     : 1 ;     /*!< [0:0] : reserved. */
            __IOM uint32_t CPUWRITE                  : 1 ;     /*!< [1:1] : 0: CPU Non Master Write Access Violation Interrupt is disabled. */
                  uint32_t RSV_2                     : 1 ;     /*!< [2:2] : reserved. */
            __IOM uint32_t DMAWRITE                  : 1 ;     /*!< [3:3] : 0: DMA Non Master Write Access Violation Interrupt is disabled. */
                  uint32_t RSV_1                     : 3 ;     /*!< [6:4] : reserved. */
            __IOM uint32_t USBADMAWRITE              : 1 ;     /*!< [7:7] : 0: USB_A DMA Non Master Write Access Violation Interrupt is disabled. */
                  uint32_t RSV_0                     : 24;     /*!< [31:8] : reserved. */
        } NMAVINTENb;
    };

    union
    {
         uint32_t NMCPURDAVADDR;  /*!< 0x00002c10 */ 
       
        struct
        {
                  uint32_t RSV_0                     : 32;     /*!< [31:0] : reserved. */
        } NMCPURDAVADDRb;
    };

    union
    {
        __IM uint32_t NMCPUWRAVADDR;  /*!< 0x00002c14 */ 
       
        struct
        {
            __IM  uint32_t NMCPUWRAVADDR             : 32;     /*!< [31:0] : This register captures the address location for which non master CPU write access vaiolation occurred. */
        } NMCPUWRAVADDRb;
    };

    uint8_t    RSV_0X2C18[4];   /*!< 0x00002c18~0x00002c1b : reserved */

    union
    {
        __IM uint32_t NMDMAWRAVADDR;  /*!< 0x00002c1c */ 
       
        struct
        {
            __IM  uint32_t NMDMAWRAVADDR             : 32;     /*!< [31:0] : This register captures the address location for which non master DMA write access vaiolation occurred. */
        } NMDMAWRAVADDRb;
    };

    uint8_t    RSV_0X2C20[12];   /*!< 0x00002c20~0x00002c2b : reserved */

    union
    {
        __IM uint32_t NMUSBADMAWRAVADDR;  /*!< 0x00002c2c */ 
       
        struct
        {
            __IM  uint32_t NMUSBADMAWRAVADDR         : 32;     /*!< [31:0] : This register captures the address location for which non master USB_A DMA write access vaiolation occurred. */
        } NMUSBADMAWRAVADDRb;
    };

    uint8_t    RSV_0X2C30[16];   /*!< 0x00002c30~0x00002c3f : reserved */

    union
    {
        __IM uint32_t MAVFLG;  /*!< 0x00002c40 */ 
       
        struct
        {
                  uint32_t RSV_1                     : 1 ;     /*!< [0:0] : reserved. */
            __IM  uint32_t CPUWRITE                  : 1 ;     /*!< [1:1] : Master CPU Write Access Violation Flag: 0: No violation. */
            __IM  uint32_t DMAWRITE                  : 1 ;     /*!< [2:2] : Master DMA Write Access Violation Flag: 0: No violation. */
                  uint32_t RSV_0                     : 29;     /*!< [31:3] : reserved. */
        } MAVFLGb;
    };

    union
    {
        __IOM uint32_t MAVSET;  /*!< 0x00002c44 */ 
       
        struct
        {
                  uint32_t RSV_1                     : 1 ;     /*!< [0:0] : reserved. */
            __IOM uint32_t CPUWRITE                  : 1 ;     /*!< [1:1] : 0: No action. */
            __IOM uint32_t DMAWRITE                  : 1 ;     /*!< [2:2] : 0: No action. */
                  uint32_t RSV_0                     : 29;     /*!< [31:3] : reserved. */
        } MAVSETb;
    };

    union
    {
        __IOM uint32_t MAVCLR;  /*!< 0x00002c48 */ 
       
        struct
        {
                  uint32_t RSV_1                     : 1 ;     /*!< [0:0] : reserved. */
            __IOM uint32_t CPUWRITE                  : 1 ;     /*!< [1:1] : 0: No action. */
            __IOM uint32_t DMAWRITE                  : 1 ;     /*!< [2:2] : 0: No action. */
                  uint32_t RSV_0                     : 29;     /*!< [31:3] : reserved. */
        } MAVCLRb;
    };

    union
    {
        __IOM uint32_t MAVINTEN;  /*!< 0x00002c4c */ 
       
        struct
        {
                  uint32_t RSV_1                     : 1 ;     /*!< [0:0] : reserved. */
            __IOM uint32_t CPUWRITE                  : 1 ;     /*!< [1:1] : 0: CPU Write Access Violation Interrupt is disabled. */
            __IOM uint32_t DMAWRITE                  : 1 ;     /*!< [2:2] : 0: DMA Write Access Violation Interrupt is disabled. */
                  uint32_t RSV_0                     : 29;     /*!< [31:3] : reserved. */
        } MAVINTENb;
    };

    uint8_t    RSV_0X2C50[4];   /*!< 0x00002c50~0x00002c53 : reserved */

    union
    {
        __IM uint32_t MCPUWRAVADDR;  /*!< 0x00002c54 */ 
       
        struct
        {
            __IM  uint32_t MCPUWRAVADDR              : 32;     /*!< [31:0] : This register captures the address location for which master CPU write access vaiolation occurred. */
        } MCPUWRAVADDRb;
    };

    union
    {
        __IM uint32_t MDMAWRAVADDR;  /*!< 0x00002c58 */ 
       
        struct
        {
            __IM  uint32_t MDMAWRAVADDR              : 32;     /*!< [31:0] : This register captures the address location for which master DMA write access vaiolation occurred. */
        } MDMAWRAVADDRb;
    };
} ACCESS_PROTECTION_REGS_Type;

/*! \brief MEMORY_ERROR_REGS register */
typedef struct {
    union
    {
        __IM uint32_t UCERRFLG;  /*!< 0x00003000 */ 
       
        struct
        {
            __IM  uint32_t CPURDERR                  : 1 ;     /*!< [0:0] : CPU Uncorrectable Read Error Flag                               <br>  0: No Error. */
            __IM  uint32_t DMARDERR                  : 1 ;     /*!< [1:1] : DMA Uncorrectable Read Error Flag                               <br>  0: No Error. */
                  uint32_t RSV_1                     : 1 ;     /*!< [2:2] : reserved. */
            __IM  uint32_t USBADMARDERR              : 1 ;     /*!< [3:3] : USB_A DMA Uncorrectable Read Error Flag                         <br>  0: No Error. */
                  uint32_t RSV_0                     : 28;     /*!< [31:4] : reserved. */
        } UCERRFLGb;
    };

    union
    {
        __IOM uint32_t UCERRSET;  /*!< 0x00003004 */ 
       
        struct
        {
            __IOM uint32_t CPURDERR                  : 1 ;     /*!< [0:0] : 0: No action. */
            __IOM uint32_t DMARDERR                  : 1 ;     /*!< [1:1] : 0: No action. */
                  uint32_t RSV_1                     : 1 ;     /*!< [2:2] : reserved. */
            __IOM uint32_t USBADMARDERR              : 1 ;     /*!< [3:3] : 0: No action. */
                  uint32_t RSV_0                     : 28;     /*!< [31:4] : reserved. */
        } UCERRSETb;
    };

    union
    {
        __IOM uint32_t UCERRCLR;  /*!< 0x00003008 */ 
       
        struct
        {
            __IOM uint32_t CPURDERR                  : 1 ;     /*!< [0:0] : 0: No action. */
            __IOM uint32_t DMARDERR                  : 1 ;     /*!< [1:1] : 0: No action. */
                  uint32_t RSV_1                     : 1 ;     /*!< [2:2] : reserved. */
            __IOM uint32_t USBADMARDERR              : 1 ;     /*!< [3:3] : 0: No action. */
                  uint32_t RSV_0                     : 28;     /*!< [31:4] : reserved. */
        } UCERRCLRb;
    };

    union
    {
        __IM uint32_t UCCPUREADDR;  /*!< 0x0000300c */ 
       
        struct
        {
            __IM  uint32_t UCCPUREADDR               : 32;     /*!< [31:0] : This register captures the address location for which CPU read/fetch access resulted in uncorrectable ECC/Parity error. */
        } UCCPUREADDRb;
    };

    union
    {
        __IM uint32_t UCDMAREADDR;  /*!< 0x00003010 */ 
       
        struct
        {
            __IM  uint32_t UCDMAREADDR               : 32;     /*!< [31:0] : This register captures the address location for which DMA read access resulted in uncorrectable ECC/Parity error. */
        } UCDMAREADDRb;
    };

    uint8_t    RSV_0X3014[4];   /*!< 0x00003014~0x00003017 : reserved */

    union
    {
        __IM uint32_t UCUSBADMAREADDR;  /*!< 0x00003018 */ 
       
        struct
        {
            __IM  uint32_t UCUSBADMAREADDR           : 32;     /*!< [31:0] : This register captures the address location for which USB_A DMA read access resulted in uncorrectable ECC/Parity error. */
        } UCUSBADMAREADDRb;
    };

    uint8_t    RSV_0X301C[36];   /*!< 0x0000301c~0x0000303f : reserved */

    union
    {
        __IM uint32_t CERRFLG;  /*!< 0x00003040 */ 
       
        struct
        {
            __IM  uint32_t CPURDERR                  : 1 ;     /*!< [0:0] : CPU Correctable Read Error Flag 0: No Error. */
            __IM  uint32_t DMARDERR                  : 1 ;     /*!< [1:1] : DMA Correctable Read Error Flag 0: No Error. */
                  uint32_t RSV_1                     : 1 ;     /*!< [2:2] : reserved. */
            __IM  uint32_t USBADMARDERR              : 1 ;     /*!< [3:3] : USB_A DMA Correctable Read Error Flag 0: No Error. */
                  uint32_t RSV_0                     : 28;     /*!< [31:4] : reserved. */
        } CERRFLGb;
    };

    union
    {
        __IOM uint32_t CERRSET;  /*!< 0x00003044 */ 
       
        struct
        {
            __IOM uint32_t CPURDERR                  : 1 ;     /*!< [0:0] : 0: No action. */
            __IOM uint32_t DMARDERR                  : 1 ;     /*!< [1:1] : 0: No action. */
                  uint32_t RSV_1                     : 1 ;     /*!< [2:2] : reserved. */
            __IOM uint32_t USBADMARDERR              : 1 ;     /*!< [3:3] : 0: No action. */
                  uint32_t RSV_0                     : 28;     /*!< [31:4] : reserved. */
        } CERRSETb;
    };

    union
    {
        __IOM uint32_t CERRCLR;  /*!< 0x00003048 */ 
       
        struct
        {
            __IOM uint32_t CPURDERR                  : 1 ;     /*!< [0:0] : 0: No action. */
            __IOM uint32_t DMARDERR                  : 1 ;     /*!< [1:1] : 0: No action. */
                  uint32_t RSV_1                     : 1 ;     /*!< [2:2] : reserved. */
            __IOM uint32_t USBADMARDERR              : 1 ;     /*!< [3:3] : 0: No action. */
                  uint32_t RSV_0                     : 28;     /*!< [31:4] : reserved. */
        } CERRCLRb;
    };

    union
    {
        __IM uint32_t CCPUREADDR;  /*!< 0x0000304c */ 
       
        struct
        {
            __IM  uint32_t CCPUREADDR                : 32;     /*!< [31:0] : This register captures the address location for which CPU read/fetch access resulted in correctable ECC error. */
        } CCPUREADDRb;
    };

    union
    {
        __IM uint32_t CDMAREADDR;  /*!< 0x00003050 */ 
       
        struct
        {
            __IM  uint32_t CDMAREADDR                : 32;     /*!< [31:0] : This register captures the address location for which DMA read/fetch access resulted in correctable ECC error. */
        } CDMAREADDRb;
    };

    uint8_t    RSV_0X3054[4];   /*!< 0x00003054~0x00003057 : reserved */

    union
    {
        __IM uint32_t CUSBADMAREADDR;  /*!< 0x00003058 */ 
       
        struct
        {
            __IM  uint32_t CUSBADMAREADDR            : 32;     /*!< [31:0] : This register captures the address location for which USB_A DMA read/fetch access resulted in correctable ECC error. */
        } CUSBADMAREADDRb;
    };

    union
    {
        __IM uint32_t CERRCNT;  /*!< 0x0000305c */ 
       
        struct
        {
            __IM  uint32_t CERRCNT                   : 32;     /*!< [31:0] : This register holds the count of how many times correctable error occurred. */
        } CERRCNTb;
    };

    union
    {
        __IOM uint32_t CERRTHRES;  /*!< 0x00003060 */ 
       
        struct
        {
            __IOM uint32_t CERRTHRES                 : 32;     /*!< [31:0] : When value in CERRCNT register is greater or equal to than value configured in this register, corretable interrupt gets generated, if enabled. */
        } CERRTHRESb;
    };

    union
    {
        __IM uint32_t CEINTFLG;  /*!< 0x00003064 */ 
       
        struct
        {
            __IM  uint32_t CEINTFLAG                 : 1 ;     /*!< [0:0] : Total corrected error count exceeded threshold Flag             <br>  0: Total correctable errors < Threshold value configured in CERRTHRES register. */
                  uint32_t RSV_0                     : 31;     /*!< [31:1] : reserved. */
        } CEINTFLGb;
    };

    union
    {
        __IOM uint32_t CEINTCLR;  /*!< 0x00003068 */ 
       
        struct
        {
            __IOM uint32_t CEINTCLR                  : 1 ;     /*!< [0:0] : 0: No action. */
                  uint32_t RSV_0                     : 31;     /*!< [31:1] : reserved. */
        } CEINTCLRb;
    };

    union
    {
        __IOM uint32_t CEINTSET;  /*!< 0x0000306c */ 
       
        struct
        {
            __IOM uint32_t CEINTSET                  : 1 ;     /*!< [0:0] : 0: No action. */
                  uint32_t RSV_0                     : 31;     /*!< [31:1] : reserved. */
        } CEINTSETb;
    };

    union
    {
        __IOM uint32_t CEINTEN;  /*!< 0x00003070 */ 
       
        struct
        {
            __IOM uint32_t CEINTEN                   : 1 ;     /*!< [0:0] : 0: Correctable Error Interrupt is disabled. */
                  uint32_t RSV_0                     : 31;     /*!< [31:1] : reserved. */
        } CEINTENb;
    };

    uint8_t    RSV_0X3074[12];   /*!< 0x00003074~0x0000307f : reserved */

    union
    {
        __IOM uint32_t CERRINTEN;  /*!< 0x00003080 */ 
       
        struct
        {
            __IOM uint32_t CPURDERRINTEN             : 1 ;     /*!< [0:0] : 0: CPU Read Correctable Error Interrupt is disabled. */
            __IOM uint32_t DMARDERRINTEN             : 1 ;     /*!< [1:1] : 0: DMA Read Correctable Error Interrupt is disabled. */
                  uint32_t RSV_1                     : 1 ;     /*!< [2:2] : reserved. */
            __IOM uint32_t USBADMARDERRINTEN         : 1 ;     /*!< [3:3] : 0: USB_A DMA Read Correctable Error Interrupt is disabled. */
                  uint32_t RSV_0                     : 28;     /*!< [31:4] : reserved. */
        } CERRINTENb;
    };

    union
    {
        __IOM uint32_t UCERRINTEN;  /*!< 0x00003084 */ 
       
        struct
        {
            __IOM uint32_t CPURDERRINTEN             : 1 ;     /*!< [0:0] : 0: CPU Read Uncorrectable Error Interrupt is disabled. */
            __IOM uint32_t DMARDERRINTEN             : 1 ;     /*!< [1:1] : 0: DMA Read Uncorrectable Error Interrupt is disabled. */
                  uint32_t RSV_1                     : 1 ;     /*!< [2:2] : reserved. */
            __IOM uint32_t USBADMARDERRINTEN         : 1 ;     /*!< [3:3] : 0: USB_A DMA Read Uncorrectable Error Interrupt is disabled. */
                  uint32_t RSV_0                     : 28;     /*!< [31:4] : reserved. */
        } UCERRINTENb;
    };
} MEMORY_ERROR_REGS_Type;

/*! \brief CPU_ID_REGS register */
typedef struct {
    union
    {
        __IM uint32_t CPUID;  /*!< 0x00003400 */ 
       
        struct
        {
            __IM  uint32_t CPUID                     : 8 ;     /*!< [7:0] : CPUID = 1 for CPU1, 2 for CPU2                                  <br>  Reset type: N/A                                                 <br>. */
                  uint32_t RSV_0                     : 24;     /*!< [31:8] : reserved. */
        } CPUIDb;
    };
} CPU_ID_REGS_Type;

/*! \brief UID_REGS register */
typedef struct {
    union
    {
        __IOM uint32_t UID_PSRAND0;  /*!< 0x00003800 */ 
       
        struct
        {
            __IOM uint32_t RANDOMID                  : 32;     /*!< [31:0] : Psuedorandom portion of the UID Reset type: N/A. */
        } UID_PSRAND0b;
    };

    union
    {
        __IOM uint32_t UID_PSRAND1;  /*!< 0x00003804 */ 
       
        struct
        {
            __IOM uint32_t RANDOMID                  : 32;     /*!< [31:0] : Psuedorandom portion of the UID Reset type: N/A. */
        } UID_PSRAND1b;
    };

    union
    {
        __IOM uint32_t UID_PSRAND2;  /*!< 0x00003808 */ 
       
        struct
        {
            __IOM uint32_t RANDOMID                  : 32;     /*!< [31:0] : Psuedorandom portion of the UID Reset type: N/A. */
        } UID_PSRAND2b;
    };

    union
    {
        __IOM uint32_t UID_PSRAND3;  /*!< 0x0000380c */ 
       
        struct
        {
            __IOM uint32_t RANDOMID                  : 32;     /*!< [31:0] : Psuedorandom portion of the UID Reset type: N/A. */
        } UID_PSRAND3b;
    };

    union
    {
        __IOM uint32_t UID_PSRAND4;  /*!< 0x00003810 */ 
       
        struct
        {
            __IOM uint32_t RANDOMID                  : 32;     /*!< [31:0] : Psuedorandom portion of the UID Reset type: N/A. */
        } UID_PSRAND4b;
    };

    union
    {
        __IOM uint32_t UID_PSRAND5;  /*!< 0x00003814 */ 
       
        struct
        {
            __IOM uint32_t RANDOMID                  : 32;     /*!< [31:0] : Psuedorandom portion of the UID Reset type: N/A. */
        } UID_PSRAND5b;
    };

    union
    {
        __IOM uint32_t UID_UNIQUE;  /*!< 0x00003818 */ 
       
        struct
        {
            __IOM uint32_t UNIQUEID                  : 32;     /*!< [31:0] : Unique portion of the UID. */
        } UID_UNIQUEb;
    };

    union
    {
        __IOM uint32_t UID_CHECKSUM;  /*!< 0x0000381c */ 
       
        struct
        {
            __IOM uint32_t CHECKSUM                  : 32;     /*!< [31:0] : Fletcher checksum of UID_PSRANDx and UID_UINIQUE Reset type: N/A. */
        } UID_CHECKSUMb;
    };
} UID_REGS_Type;

/*! \brief DUMMY_REGS register */
typedef struct {
    union
    {
        __IOM uint32_t DUMMY_REG0;  /*!< 0x00003c00 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG0b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG1;  /*!< 0x00003c04 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG1b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG2;  /*!< 0x00003c08 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG2b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG3;  /*!< 0x00003c0c */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG3b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG4;  /*!< 0x00003c10 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG4b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG5;  /*!< 0x00003c14 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG5b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG6;  /*!< 0x00003c18 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG6b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG7;  /*!< 0x00003c1c */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG7b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG8;  /*!< 0x00003c20 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG8b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG9;  /*!< 0x00003c24 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG9b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG10;  /*!< 0x00003c28 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG10b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG11;  /*!< 0x00003c2c */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG11b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG12;  /*!< 0x00003c30 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG12b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG13;  /*!< 0x00003c34 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG13b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG14;  /*!< 0x00003c38 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG14b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG15;  /*!< 0x00003c3c */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG15b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG16;  /*!< 0x00003c40 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG16b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG17;  /*!< 0x00003c44 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG17b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG18;  /*!< 0x00003c48 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG18b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG19;  /*!< 0x00003c4c */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG19b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG20;  /*!< 0x00003c50 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG20b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG21;  /*!< 0x00003c54 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG21b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG22;  /*!< 0x00003c58 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG22b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG23;  /*!< 0x00003c5c */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG23b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG24;  /*!< 0x00003c60 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG24b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG25;  /*!< 0x00003c64 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG25b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG26;  /*!< 0x00003c68 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG26b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG27;  /*!< 0x00003c6c */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG27b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG28;  /*!< 0x00003c70 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG28b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG29;  /*!< 0x00003c74 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG29b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG30;  /*!< 0x00003c78 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG30b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG31;  /*!< 0x00003c7c */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG31b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG32;  /*!< 0x00003c80 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG32b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG33;  /*!< 0x00003c84 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG33b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG34;  /*!< 0x00003c88 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG34b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG35;  /*!< 0x00003c8c */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG35b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG36;  /*!< 0x00003c90 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG36b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG37;  /*!< 0x00003c94 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG37b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG38;  /*!< 0x00003c98 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG38b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG39;  /*!< 0x00003c9c */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG39b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG40;  /*!< 0x00003ca0 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG40b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG41;  /*!< 0x00003ca4 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG41b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG42;  /*!< 0x00003ca8 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG42b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG43;  /*!< 0x00003cac */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG43b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG44;  /*!< 0x00003cb0 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG44b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG45;  /*!< 0x00003cb4 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG45b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG46;  /*!< 0x00003cb8 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG46b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG47;  /*!< 0x00003cbc */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG47b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG48;  /*!< 0x00003cc0 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG48b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG49;  /*!< 0x00003cc4 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG49b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG50;  /*!< 0x00003cc8 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG50b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG51;  /*!< 0x00003ccc */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG51b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG52;  /*!< 0x00003cd0 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG52b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG53;  /*!< 0x00003cd4 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG53b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG54;  /*!< 0x00003cd8 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG54b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG55;  /*!< 0x00003cdc */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG55b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG56;  /*!< 0x00003ce0 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG56b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG57;  /*!< 0x00003ce4 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG57b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG58;  /*!< 0x00003ce8 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG58b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG59;  /*!< 0x00003cec */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG59b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG60;  /*!< 0x00003cf0 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG60b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG61;  /*!< 0x00003cf4 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG61b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG62;  /*!< 0x00003cf8 */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG62b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG63;  /*!< 0x00003cfc */ 
       
        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;     /*!< [31:0] : dummy register. */
        } DUMMY_REG63b;
    };
} DUMMY_REGS_Type;


/*!
 * @}
 */

/*!
 * \name SYSCTRL_CPU1 Base Address Definitions
 *
 * @{
 */

 /*! \brief CPUTIMER_REGS0 base address */
#define CPUTIMER_REGS0_BASE (0x41000000UL)
/*! \brief CPUTIMER_REGS1 base address */
#define CPUTIMER_REGS1_BASE (0x41000400UL)
/*! \brief CPUTIMER_REGS2 base address */
#define CPUTIMER_REGS2_BASE (0x41000800UL)
/*! \brief CPUTIMER_REGS0 base pointer */
#define CPUTIMER_REGS0 ((CPUTIMER_REGS_Type *) CPUTIMER_REGS0_BASE)
/*! \brief CPUTIMER_REGS1 base pointer */
#define CPUTIMER_REGS1 ((CPUTIMER_REGS_Type *) CPUTIMER_REGS1_BASE)
/*! \brief CPUTIMER_REGS2 base pointer */
#define CPUTIMER_REGS2 ((CPUTIMER_REGS_Type *) CPUTIMER_REGS2_BASE)

/*! \brief WD_REGS base address */
#define WD_REGS_BASE (0x41000c00UL)
/*! \brief WD_REGS base pointer */
#define WD_REGS ((WD_REGS_Type *) WD_REGS_BASE)

/*! \brief NMI_INTRUPT_REGS base address */
#define NMI_INTRUPT_REGS_BASE (0x41001000UL)
/*! \brief NMI_INTRUPT_REGS base pointer */
#define NMI_INTRUPT_REGS ((NMI_INTRUPT_REGS_Type *) NMI_INTRUPT_REGS_BASE)

/*! \brief XINT_REGS base address */
#define XINT_REGS_BASE (0x41001400UL)
/*! \brief XINT_REGS base pointer */
#define XINT_REGS ((XINT_REGS_Type *) XINT_REGS_BASE)

/*! \brief DEV_CFG_REGS base address */
#define DEV_CFG_REGS_BASE (0x41001800UL)
/*! \brief DEV_CFG_REGS base pointer */
#define DEV_CFG_REGS ((DEV_CFG_REGS_Type *) DEV_CFG_REGS_BASE)

/*! \brief ANALOG_SUBSYS_REGS base address */
#define ANALOG_SUBSYS_REGS_BASE (0x41001c00UL)
/*! \brief ANALOG_SUBSYS_REGS base pointer */
#define ANALOG_SUBSYS_REGS ((ANALOG_SUBSYS_REGS_Type *) ANALOG_SUBSYS_REGS_BASE)

/*! \brief CLK_CFG_REGS base address */
#define CLK_CFG_REGS_BASE (0x41002000UL)
/*! \brief CLK_CFG_REGS base pointer */
#define CLK_CFG_REGS ((CLK_CFG_REGS_Type *) CLK_CFG_REGS_BASE)

/*! \brief CPU_SYS_REGS base address */
#define CPU_SYS_REGS_BASE (0x41002400UL)
/*! \brief CPU_SYS_REGS base pointer */
#define CPU_SYS_REGS ((CPU_SYS_REGS_Type *) CPU_SYS_REGS_BASE)

/*! \brief MEM_CFG_REGS base address */
#define MEM_CFG_REGS_BASE (0x41002800UL)
/*! \brief MEM_CFG_REGS base pointer */
#define MEM_CFG_REGS ((MEM_CFG_REGS_Type *) MEM_CFG_REGS_BASE)

/*! \brief ACCESS_PROTECTION_REGS base address */
#define ACCESS_PROTECTION_REGS_BASE (0x41002c00UL)
/*! \brief ACCESS_PROTECTION_REGS base pointer */
#define ACCESS_PROTECTION_REGS ((ACCESS_PROTECTION_REGS_Type *) ACCESS_PROTECTION_REGS_BASE)

/*! \brief MEMORY_ERROR_REGS base address */
#define MEMORY_ERROR_REGS_BASE (0x41003000UL)
/*! \brief MEMORY_ERROR_REGS base pointer */
#define MEMORY_ERROR_REGS ((MEMORY_ERROR_REGS_Type *) MEMORY_ERROR_REGS_BASE)

/*! \brief CPU_ID_REGS base address */
#define CPU_ID_REGS_BASE (0x41003400UL)
/*! \brief CPU_ID_REGS base pointer */
#define CPU_ID_REGS ((CPU_ID_REGS_Type *) CPU_ID_REGS_BASE)

/*! \brief UID_REGS base address */
#define UID_REGS_BASE (0x41003800UL)
/*! \brief UID_REGS base pointer */
#define UID_REGS ((UID_REGS_Type *) UID_REGS_BASE)

/*! \brief DUMMY_REGS base address */
#define DUMMY_REGS_BASE (0x41003c00UL)
/*! \brief DUMMY_REGS base pointer */
#define DUMMY_REGS ((DUMMY_REGS_Type *) DUMMY_REGS_BASE)


/*!
 * @}
 */

 
/*!
 * \name SYSCTRL_CPU1 Register Bitfield Definitions
 *
 * @{
 */

 /* TIM bitfield */
#define CPUTIMER_REGS_TIM_MSW_Pos    (16U)                                                                                 /*!< MSW Postion   16         */ 
#define CPUTIMER_REGS_TIM_MSW_Msk    (0xffffU << CPUTIMER_REGS_TIM_MSW_Pos)                                                /*!< MSW Mask      0xFFFF0000 */
#define CPUTIMER_REGS_TIM_MSW_Set(x) (((uint32_t) (x) << CPUTIMER_REGS_TIM_MSW_Pos) & CPUTIMER_REGS_TIM_MSW_Msk)           /*!< MSW Set Value            */
#define CPUTIMER_REGS_TIM_MSW_Get(x) (((uint32_t) (x) & CPUTIMER_REGS_TIM_MSW_Msk) >> CPUTIMER_REGS_TIM_MSW_Pos)           /*!< MSW Get Value            */


#define CPUTIMER_REGS_TIM_LSW_Pos    (0U)                                                                                  /*!< LSW Postion   0          */ 
#define CPUTIMER_REGS_TIM_LSW_Msk    (0xffffU << CPUTIMER_REGS_TIM_LSW_Pos)                                                /*!< LSW Mask      0x0000FFFF */
#define CPUTIMER_REGS_TIM_LSW_Set(x) (((uint32_t) (x) << CPUTIMER_REGS_TIM_LSW_Pos) & CPUTIMER_REGS_TIM_LSW_Msk)           /*!< LSW Set Value            */
#define CPUTIMER_REGS_TIM_LSW_Get(x) (((uint32_t) (x) & CPUTIMER_REGS_TIM_LSW_Msk) >> CPUTIMER_REGS_TIM_LSW_Pos)           /*!< LSW Get Value            */


/* PRD bitfield */
#define CPUTIMER_REGS_PRD_MSW_Pos    (16U)                                                                                 /*!< MSW Postion   16         */ 
#define CPUTIMER_REGS_PRD_MSW_Msk    (0xffffU << CPUTIMER_REGS_PRD_MSW_Pos)                                                /*!< MSW Mask      0xFFFF0000 */
#define CPUTIMER_REGS_PRD_MSW_Set(x) (((uint32_t) (x) << CPUTIMER_REGS_PRD_MSW_Pos) & CPUTIMER_REGS_PRD_MSW_Msk)           /*!< MSW Set Value            */
#define CPUTIMER_REGS_PRD_MSW_Get(x) (((uint32_t) (x) & CPUTIMER_REGS_PRD_MSW_Msk) >> CPUTIMER_REGS_PRD_MSW_Pos)           /*!< MSW Get Value            */


#define CPUTIMER_REGS_PRD_LSW_Pos    (0U)                                                                                  /*!< LSW Postion   0          */ 
#define CPUTIMER_REGS_PRD_LSW_Msk    (0xffffU << CPUTIMER_REGS_PRD_LSW_Pos)                                                /*!< LSW Mask      0x0000FFFF */
#define CPUTIMER_REGS_PRD_LSW_Set(x) (((uint32_t) (x) << CPUTIMER_REGS_PRD_LSW_Pos) & CPUTIMER_REGS_PRD_LSW_Msk)           /*!< LSW Set Value            */
#define CPUTIMER_REGS_PRD_LSW_Get(x) (((uint32_t) (x) & CPUTIMER_REGS_PRD_LSW_Msk) >> CPUTIMER_REGS_PRD_LSW_Pos)           /*!< LSW Get Value            */


/* TCR bitfield */
#define CPUTIMER_REGS_TCR_TIF_Pos    (15U)                                                                                 /*!< TIF Postion   15         */ 
#define CPUTIMER_REGS_TCR_TIF_Msk    (0x1U << CPUTIMER_REGS_TCR_TIF_Pos)                                                   /*!< TIF Mask      0x00008000 */
#define CPUTIMER_REGS_TCR_TIF_Set(x) (((uint32_t) (x) << CPUTIMER_REGS_TCR_TIF_Pos) & CPUTIMER_REGS_TCR_TIF_Msk)           /*!< TIF Set Value            */
#define CPUTIMER_REGS_TCR_TIF_Get(x) (((uint32_t) (x) & CPUTIMER_REGS_TCR_TIF_Msk) >> CPUTIMER_REGS_TCR_TIF_Pos)           /*!< TIF Get Value            */


#define CPUTIMER_REGS_TCR_TIE_Pos    (14U)                                                                                 /*!< TIE Postion   14         */ 
#define CPUTIMER_REGS_TCR_TIE_Msk    (0x1U << CPUTIMER_REGS_TCR_TIE_Pos)                                                   /*!< TIE Mask      0x00004000 */
#define CPUTIMER_REGS_TCR_TIE_Set(x) (((uint32_t) (x) << CPUTIMER_REGS_TCR_TIE_Pos) & CPUTIMER_REGS_TCR_TIE_Msk)           /*!< TIE Set Value            */
#define CPUTIMER_REGS_TCR_TIE_Get(x) (((uint32_t) (x) & CPUTIMER_REGS_TCR_TIE_Msk) >> CPUTIMER_REGS_TCR_TIE_Pos)           /*!< TIE Get Value            */


#define CPUTIMER_REGS_TCR_FREE_Pos    (11U)                                                                                 /*!< FREE Postion   11         */ 
#define CPUTIMER_REGS_TCR_FREE_Msk    (0x1U << CPUTIMER_REGS_TCR_FREE_Pos)                                                  /*!< FREE Mask      0x00000800 */
#define CPUTIMER_REGS_TCR_FREE_Set(x) (((uint32_t) (x) << CPUTIMER_REGS_TCR_FREE_Pos) & CPUTIMER_REGS_TCR_FREE_Msk)         /*!< FREE Set Value            */
#define CPUTIMER_REGS_TCR_FREE_Get(x) (((uint32_t) (x) & CPUTIMER_REGS_TCR_FREE_Msk) >> CPUTIMER_REGS_TCR_FREE_Pos)         /*!< FREE Get Value            */


#define CPUTIMER_REGS_TCR_TIM_SOFT_Pos    (10U)                                                                                 /*!< TIM_SOFT Postion   10         */ 
#define CPUTIMER_REGS_TCR_TIM_SOFT_Msk    (0x1U << CPUTIMER_REGS_TCR_TIM_SOFT_Pos)                                              /*!< TIM_SOFT Mask      0x00000400 */
#define CPUTIMER_REGS_TCR_TIM_SOFT_Set(x) (((uint32_t) (x) << CPUTIMER_REGS_TCR_TIM_SOFT_Pos) & CPUTIMER_REGS_TCR_TIM_SOFT_Msk) /*!< TIM_SOFT Set Value            */
#define CPUTIMER_REGS_TCR_TIM_SOFT_Get(x) (((uint32_t) (x) & CPUTIMER_REGS_TCR_TIM_SOFT_Msk) >> CPUTIMER_REGS_TCR_TIM_SOFT_Pos) /*!< TIM_SOFT Get Value            */


#define CPUTIMER_REGS_TCR_TRB_Pos    (5U)                                                                                  /*!< TRB Postion   5          */ 
#define CPUTIMER_REGS_TCR_TRB_Msk    (0x1U << CPUTIMER_REGS_TCR_TRB_Pos)                                                   /*!< TRB Mask      0x00000020 */
#define CPUTIMER_REGS_TCR_TRB_Set(x) (((uint32_t) (x) << CPUTIMER_REGS_TCR_TRB_Pos) & CPUTIMER_REGS_TCR_TRB_Msk)           /*!< TRB Set Value            */
#define CPUTIMER_REGS_TCR_TRB_Get(x) (((uint32_t) (x) & CPUTIMER_REGS_TCR_TRB_Msk) >> CPUTIMER_REGS_TCR_TRB_Pos)           /*!< TRB Get Value            */


#define CPUTIMER_REGS_TCR_TSS_Pos    (4U)                                                                                  /*!< TSS Postion   4          */ 
#define CPUTIMER_REGS_TCR_TSS_Msk    (0x1U << CPUTIMER_REGS_TCR_TSS_Pos)                                                   /*!< TSS Mask      0x00000010 */
#define CPUTIMER_REGS_TCR_TSS_Set(x) (((uint32_t) (x) << CPUTIMER_REGS_TCR_TSS_Pos) & CPUTIMER_REGS_TCR_TSS_Msk)           /*!< TSS Set Value            */
#define CPUTIMER_REGS_TCR_TSS_Get(x) (((uint32_t) (x) & CPUTIMER_REGS_TCR_TSS_Msk) >> CPUTIMER_REGS_TCR_TSS_Pos)           /*!< TSS Get Value            */


#define CPUTIMER_REGS_TCR_INTR_OP_Pos    (3U)                                                                                  /*!< INTR_OP Postion   3          */ 
#define CPUTIMER_REGS_TCR_INTR_OP_Msk    (0x1U << CPUTIMER_REGS_TCR_INTR_OP_Pos)                                               /*!< INTR_OP Mask      0x00000008 */
#define CPUTIMER_REGS_TCR_INTR_OP_Set(x) (((uint32_t) (x) << CPUTIMER_REGS_TCR_INTR_OP_Pos) & CPUTIMER_REGS_TCR_INTR_OP_Msk)   /*!< INTR_OP Set Value            */
#define CPUTIMER_REGS_TCR_INTR_OP_Get(x) (((uint32_t) (x) & CPUTIMER_REGS_TCR_INTR_OP_Msk) >> CPUTIMER_REGS_TCR_INTR_OP_Pos)   /*!< INTR_OP Get Value            */


/* TPR bitfield */
#define CPUTIMER_REGS_TPR_PSC_Pos    (8U)                                                                                  /*!< PSC Postion   8          */ 
#define CPUTIMER_REGS_TPR_PSC_Msk    (0xffU << CPUTIMER_REGS_TPR_PSC_Pos)                                                  /*!< PSC Mask      0x0000FF00 */
#define CPUTIMER_REGS_TPR_PSC_Set(x) (((uint16_t) (x) << CPUTIMER_REGS_TPR_PSC_Pos) & CPUTIMER_REGS_TPR_PSC_Msk)           /*!< PSC Set Value            */
#define CPUTIMER_REGS_TPR_PSC_Get(x) (((uint16_t) (x) & CPUTIMER_REGS_TPR_PSC_Msk) >> CPUTIMER_REGS_TPR_PSC_Pos)           /*!< PSC Get Value            */


#define CPUTIMER_REGS_TPR_TDDR_Pos    (0U)                                                                                  /*!< TDDR Postion   0          */ 
#define CPUTIMER_REGS_TPR_TDDR_Msk    (0xffU << CPUTIMER_REGS_TPR_TDDR_Pos)                                                 /*!< TDDR Mask      0x000000FF */
#define CPUTIMER_REGS_TPR_TDDR_Set(x) (((uint16_t) (x) << CPUTIMER_REGS_TPR_TDDR_Pos) & CPUTIMER_REGS_TPR_TDDR_Msk)         /*!< TDDR Set Value            */
#define CPUTIMER_REGS_TPR_TDDR_Get(x) (((uint16_t) (x) & CPUTIMER_REGS_TPR_TDDR_Msk) >> CPUTIMER_REGS_TPR_TDDR_Pos)         /*!< TDDR Get Value            */


/* TPRH bitfield */
#define CPUTIMER_REGS_TPRH_PSCH_Pos    (8U)                                                                                  /*!< PSCH Postion   8          */ 
#define CPUTIMER_REGS_TPRH_PSCH_Msk    (0xffU << CPUTIMER_REGS_TPRH_PSCH_Pos)                                                /*!< PSCH Mask      0x0000FF00 */
#define CPUTIMER_REGS_TPRH_PSCH_Set(x) (((uint16_t) (x) << CPUTIMER_REGS_TPRH_PSCH_Pos) & CPUTIMER_REGS_TPRH_PSCH_Msk)       /*!< PSCH Set Value            */
#define CPUTIMER_REGS_TPRH_PSCH_Get(x) (((uint16_t) (x) & CPUTIMER_REGS_TPRH_PSCH_Msk) >> CPUTIMER_REGS_TPRH_PSCH_Pos)       /*!< PSCH Get Value            */


#define CPUTIMER_REGS_TPRH_TDDRH_Pos    (0U)                                                                                  /*!< TDDRH Postion   0          */ 
#define CPUTIMER_REGS_TPRH_TDDRH_Msk    (0xffU << CPUTIMER_REGS_TPRH_TDDRH_Pos)                                               /*!< TDDRH Mask      0x000000FF */
#define CPUTIMER_REGS_TPRH_TDDRH_Set(x) (((uint16_t) (x) << CPUTIMER_REGS_TPRH_TDDRH_Pos) & CPUTIMER_REGS_TPRH_TDDRH_Msk)     /*!< TDDRH Set Value            */
#define CPUTIMER_REGS_TPRH_TDDRH_Get(x) (((uint16_t) (x) & CPUTIMER_REGS_TPRH_TDDRH_Msk) >> CPUTIMER_REGS_TPRH_TDDRH_Pos)     /*!< TDDRH Get Value            */


/* TIMEX bitfield */
#define CPUTIMER_REGS_TIMEX_TIMEX_Pos    (0U)                                                                                  /*!< TIMEX Postion   0          */ 
#define CPUTIMER_REGS_TIMEX_TIMEX_Msk    (0xffffffffU << CPUTIMER_REGS_TIMEX_TIMEX_Pos)                                        /*!< TIMEX Mask      0xFFFFFFFF */
#define CPUTIMER_REGS_TIMEX_TIMEX_Set(x) (((uint32_t) (x) << CPUTIMER_REGS_TIMEX_TIMEX_Pos) & CPUTIMER_REGS_TIMEX_TIMEX_Msk)   /*!< TIMEX Set Value            */
#define CPUTIMER_REGS_TIMEX_TIMEX_Get(x) (((uint32_t) (x) & CPUTIMER_REGS_TIMEX_TIMEX_Msk) >> CPUTIMER_REGS_TIMEX_TIMEX_Pos)   /*!< TIMEX Get Value            */


/* PRDEX bitfield */
#define CPUTIMER_REGS_PRDEX_PRDEX_Pos    (0U)                                                                                  /*!< PRDEX Postion   0          */ 
#define CPUTIMER_REGS_PRDEX_PRDEX_Msk    (0xffffffffU << CPUTIMER_REGS_PRDEX_PRDEX_Pos)                                        /*!< PRDEX Mask      0xFFFFFFFF */
#define CPUTIMER_REGS_PRDEX_PRDEX_Set(x) (((uint32_t) (x) << CPUTIMER_REGS_PRDEX_PRDEX_Pos) & CPUTIMER_REGS_PRDEX_PRDEX_Msk)   /*!< PRDEX Set Value            */
#define CPUTIMER_REGS_PRDEX_PRDEX_Get(x) (((uint32_t) (x) & CPUTIMER_REGS_PRDEX_PRDEX_Msk) >> CPUTIMER_REGS_PRDEX_PRDEX_Pos)   /*!< PRDEX Get Value            */


/* WDCR bitfield */
#define WD_REGS_WDCR_WDPS_Pos    (0U)                                                                                  /*!< WDPS Postion   0          */ 
#define WD_REGS_WDCR_WDPS_Msk    (0x7U << WD_REGS_WDCR_WDPS_Pos)                                                       /*!< WDPS Mask      0x00000007 */
#define WD_REGS_WDCR_WDPS_Set(x) (((uint16_t) (x) << WD_REGS_WDCR_WDPS_Pos) & WD_REGS_WDCR_WDPS_Msk)                   /*!< WDPS Set Value            */
#define WD_REGS_WDCR_WDPS_Get(x) (((uint16_t) (x) & WD_REGS_WDCR_WDPS_Msk) >> WD_REGS_WDCR_WDPS_Pos)                   /*!< WDPS Get Value            */


/* NMICFG bitfield */
#define NMI_INTRUPT_REGS_NMICFG_NMIE_Pos    (0U)                                                                                  /*!< NMIE Postion   0          */ 
#define NMI_INTRUPT_REGS_NMICFG_NMIE_Msk    (0x1U << NMI_INTRUPT_REGS_NMICFG_NMIE_Pos)                                            /*!< NMIE Mask      0x00000001 */
#define NMI_INTRUPT_REGS_NMICFG_NMIE_Set(x) (((uint16_t) (x) << NMI_INTRUPT_REGS_NMICFG_NMIE_Pos) & NMI_INTRUPT_REGS_NMICFG_NMIE_Msk) /*!< NMIE Set Value            */
#define NMI_INTRUPT_REGS_NMICFG_NMIE_Get(x) (((uint16_t) (x) & NMI_INTRUPT_REGS_NMICFG_NMIE_Msk) >> NMI_INTRUPT_REGS_NMICFG_NMIE_Pos) /*!< NMIE Get Value            */


/* NMIFLG bitfield */
#define NMI_INTRUPT_REGS_NMIFLG_CPU2NMIWDRSN_Pos    (10U)                                                                                 /*!< CPU2NMIWDRSN Postion   10         */ 
#define NMI_INTRUPT_REGS_NMIFLG_CPU2NMIWDRSN_Msk    (0x1U << NMI_INTRUPT_REGS_NMIFLG_CPU2NMIWDRSN_Pos)                                    /*!< CPU2NMIWDRSN Mask      0x00000400 */
#define NMI_INTRUPT_REGS_NMIFLG_CPU2NMIWDRSN_Set(x) (((uint16_t) (x) << NMI_INTRUPT_REGS_NMIFLG_CPU2NMIWDRSN_Pos) & NMI_INTRUPT_REGS_NMIFLG_CPU2NMIWDRSN_Msk) /*!< CPU2NMIWDRSN Set Value            */
#define NMI_INTRUPT_REGS_NMIFLG_CPU2NMIWDRSN_Get(x) (((uint16_t) (x) & NMI_INTRUPT_REGS_NMIFLG_CPU2NMIWDRSN_Msk) >> NMI_INTRUPT_REGS_NMIFLG_CPU2NMIWDRSN_Pos) /*!< CPU2NMIWDRSN Get Value            */


#define NMI_INTRUPT_REGS_NMIFLG_CPU2WDRSN_Pos    (9U)                                                                                  /*!< CPU2WDRSN Postion   9          */ 
#define NMI_INTRUPT_REGS_NMIFLG_CPU2WDRSN_Msk    (0x1U << NMI_INTRUPT_REGS_NMIFLG_CPU2WDRSN_Pos)                                       /*!< CPU2WDRSN Mask      0x00000200 */
#define NMI_INTRUPT_REGS_NMIFLG_CPU2WDRSN_Set(x) (((uint16_t) (x) << NMI_INTRUPT_REGS_NMIFLG_CPU2WDRSN_Pos) & NMI_INTRUPT_REGS_NMIFLG_CPU2WDRSN_Msk) /*!< CPU2WDRSN Set Value            */
#define NMI_INTRUPT_REGS_NMIFLG_CPU2WDRSN_Get(x) (((uint16_t) (x) & NMI_INTRUPT_REGS_NMIFLG_CPU2WDRSN_Msk) >> NMI_INTRUPT_REGS_NMIFLG_CPU2WDRSN_Pos) /*!< CPU2WDRSN Get Value            */


#define NMI_INTRUPT_REGS_NMIFLG_CLBNMI_Pos    (8U)                                                                                  /*!< CLBNMI Postion   8          */ 
#define NMI_INTRUPT_REGS_NMIFLG_CLBNMI_Msk    (0x1U << NMI_INTRUPT_REGS_NMIFLG_CLBNMI_Pos)                                          /*!< CLBNMI Mask      0x00000100 */
#define NMI_INTRUPT_REGS_NMIFLG_CLBNMI_Set(x) (((uint16_t) (x) << NMI_INTRUPT_REGS_NMIFLG_CLBNMI_Pos) & NMI_INTRUPT_REGS_NMIFLG_CLBNMI_Msk) /*!< CLBNMI Set Value            */
#define NMI_INTRUPT_REGS_NMIFLG_CLBNMI_Get(x) (((uint16_t) (x) & NMI_INTRUPT_REGS_NMIFLG_CLBNMI_Msk) >> NMI_INTRUPT_REGS_NMIFLG_CLBNMI_Pos) /*!< CLBNMI Get Value            */


#define NMI_INTRUPT_REGS_NMIFLG_FLUNCERR_Pos    (3U)                                                                                  /*!< FLUNCERR Postion   3          */ 
#define NMI_INTRUPT_REGS_NMIFLG_FLUNCERR_Msk    (0x1U << NMI_INTRUPT_REGS_NMIFLG_FLUNCERR_Pos)                                        /*!< FLUNCERR Mask      0x00000008 */
#define NMI_INTRUPT_REGS_NMIFLG_FLUNCERR_Set(x) (((uint16_t) (x) << NMI_INTRUPT_REGS_NMIFLG_FLUNCERR_Pos) & NMI_INTRUPT_REGS_NMIFLG_FLUNCERR_Msk) /*!< FLUNCERR Set Value            */
#define NMI_INTRUPT_REGS_NMIFLG_FLUNCERR_Get(x) (((uint16_t) (x) & NMI_INTRUPT_REGS_NMIFLG_FLUNCERR_Msk) >> NMI_INTRUPT_REGS_NMIFLG_FLUNCERR_Pos) /*!< FLUNCERR Get Value            */


#define NMI_INTRUPT_REGS_NMIFLG_RAMUNCERR_Pos    (2U)                                                                                  /*!< RAMUNCERR Postion   2          */ 
#define NMI_INTRUPT_REGS_NMIFLG_RAMUNCERR_Msk    (0x1U << NMI_INTRUPT_REGS_NMIFLG_RAMUNCERR_Pos)                                       /*!< RAMUNCERR Mask      0x00000004 */
#define NMI_INTRUPT_REGS_NMIFLG_RAMUNCERR_Set(x) (((uint16_t) (x) << NMI_INTRUPT_REGS_NMIFLG_RAMUNCERR_Pos) & NMI_INTRUPT_REGS_NMIFLG_RAMUNCERR_Msk) /*!< RAMUNCERR Set Value            */
#define NMI_INTRUPT_REGS_NMIFLG_RAMUNCERR_Get(x) (((uint16_t) (x) & NMI_INTRUPT_REGS_NMIFLG_RAMUNCERR_Msk) >> NMI_INTRUPT_REGS_NMIFLG_RAMUNCERR_Pos) /*!< RAMUNCERR Get Value            */


#define NMI_INTRUPT_REGS_NMIFLG_CLOCKFAIL_Pos    (1U)                                                                                  /*!< CLOCKFAIL Postion   1          */ 
#define NMI_INTRUPT_REGS_NMIFLG_CLOCKFAIL_Msk    (0x1U << NMI_INTRUPT_REGS_NMIFLG_CLOCKFAIL_Pos)                                       /*!< CLOCKFAIL Mask      0x00000002 */
#define NMI_INTRUPT_REGS_NMIFLG_CLOCKFAIL_Set(x) (((uint16_t) (x) << NMI_INTRUPT_REGS_NMIFLG_CLOCKFAIL_Pos) & NMI_INTRUPT_REGS_NMIFLG_CLOCKFAIL_Msk) /*!< CLOCKFAIL Set Value            */
#define NMI_INTRUPT_REGS_NMIFLG_CLOCKFAIL_Get(x) (((uint16_t) (x) & NMI_INTRUPT_REGS_NMIFLG_CLOCKFAIL_Msk) >> NMI_INTRUPT_REGS_NMIFLG_CLOCKFAIL_Pos) /*!< CLOCKFAIL Get Value            */


#define NMI_INTRUPT_REGS_NMIFLG_NMIINT_Pos    (0U)                                                                                  /*!< NMIINT Postion   0          */ 
#define NMI_INTRUPT_REGS_NMIFLG_NMIINT_Msk    (0x1U << NMI_INTRUPT_REGS_NMIFLG_NMIINT_Pos)                                          /*!< NMIINT Mask      0x00000001 */
#define NMI_INTRUPT_REGS_NMIFLG_NMIINT_Set(x) (((uint16_t) (x) << NMI_INTRUPT_REGS_NMIFLG_NMIINT_Pos) & NMI_INTRUPT_REGS_NMIFLG_NMIINT_Msk) /*!< NMIINT Set Value            */
#define NMI_INTRUPT_REGS_NMIFLG_NMIINT_Get(x) (((uint16_t) (x) & NMI_INTRUPT_REGS_NMIFLG_NMIINT_Msk) >> NMI_INTRUPT_REGS_NMIFLG_NMIINT_Pos) /*!< NMIINT Get Value            */


/* NMIFLGCLR bitfield */
#define NMI_INTRUPT_REGS_NMIFLGCLR_CPU2NMIWDRSN_Pos    (10U)                                                                                 /*!< CPU2NMIWDRSN Postion   10         */ 
#define NMI_INTRUPT_REGS_NMIFLGCLR_CPU2NMIWDRSN_Msk    (0x1U << NMI_INTRUPT_REGS_NMIFLGCLR_CPU2NMIWDRSN_Pos)                                 /*!< CPU2NMIWDRSN Mask      0x00000400 */
#define NMI_INTRUPT_REGS_NMIFLGCLR_CPU2NMIWDRSN_Set(x) (((uint16_t) (x) << NMI_INTRUPT_REGS_NMIFLGCLR_CPU2NMIWDRSN_Pos) & NMI_INTRUPT_REGS_NMIFLGCLR_CPU2NMIWDRSN_Msk) /*!< CPU2NMIWDRSN Set Value            */
#define NMI_INTRUPT_REGS_NMIFLGCLR_CPU2NMIWDRSN_Get(x) (((uint16_t) (x) & NMI_INTRUPT_REGS_NMIFLGCLR_CPU2NMIWDRSN_Msk) >> NMI_INTRUPT_REGS_NMIFLGCLR_CPU2NMIWDRSN_Pos) /*!< CPU2NMIWDRSN Get Value            */


#define NMI_INTRUPT_REGS_NMIFLGCLR_CPU2WDRSN_Pos    (9U)                                                                                  /*!< CPU2WDRSN Postion   9          */ 
#define NMI_INTRUPT_REGS_NMIFLGCLR_CPU2WDRSN_Msk    (0x1U << NMI_INTRUPT_REGS_NMIFLGCLR_CPU2WDRSN_Pos)                                    /*!< CPU2WDRSN Mask      0x00000200 */
#define NMI_INTRUPT_REGS_NMIFLGCLR_CPU2WDRSN_Set(x) (((uint16_t) (x) << NMI_INTRUPT_REGS_NMIFLGCLR_CPU2WDRSN_Pos) & NMI_INTRUPT_REGS_NMIFLGCLR_CPU2WDRSN_Msk) /*!< CPU2WDRSN Set Value            */
#define NMI_INTRUPT_REGS_NMIFLGCLR_CPU2WDRSN_Get(x) (((uint16_t) (x) & NMI_INTRUPT_REGS_NMIFLGCLR_CPU2WDRSN_Msk) >> NMI_INTRUPT_REGS_NMIFLGCLR_CPU2WDRSN_Pos) /*!< CPU2WDRSN Get Value            */


#define NMI_INTRUPT_REGS_NMIFLGCLR_CLBNMI_Pos    (8U)                                                                                  /*!< CLBNMI Postion   8          */ 
#define NMI_INTRUPT_REGS_NMIFLGCLR_CLBNMI_Msk    (0x1U << NMI_INTRUPT_REGS_NMIFLGCLR_CLBNMI_Pos)                                       /*!< CLBNMI Mask      0x00000100 */
#define NMI_INTRUPT_REGS_NMIFLGCLR_CLBNMI_Set(x) (((uint16_t) (x) << NMI_INTRUPT_REGS_NMIFLGCLR_CLBNMI_Pos) & NMI_INTRUPT_REGS_NMIFLGCLR_CLBNMI_Msk) /*!< CLBNMI Set Value            */
#define NMI_INTRUPT_REGS_NMIFLGCLR_CLBNMI_Get(x) (((uint16_t) (x) & NMI_INTRUPT_REGS_NMIFLGCLR_CLBNMI_Msk) >> NMI_INTRUPT_REGS_NMIFLGCLR_CLBNMI_Pos) /*!< CLBNMI Get Value            */


#define NMI_INTRUPT_REGS_NMIFLGCLR_FLUNCERR_Pos    (3U)                                                                                  /*!< FLUNCERR Postion   3          */ 
#define NMI_INTRUPT_REGS_NMIFLGCLR_FLUNCERR_Msk    (0x1U << NMI_INTRUPT_REGS_NMIFLGCLR_FLUNCERR_Pos)                                     /*!< FLUNCERR Mask      0x00000008 */
#define NMI_INTRUPT_REGS_NMIFLGCLR_FLUNCERR_Set(x) (((uint16_t) (x) << NMI_INTRUPT_REGS_NMIFLGCLR_FLUNCERR_Pos) & NMI_INTRUPT_REGS_NMIFLGCLR_FLUNCERR_Msk) /*!< FLUNCERR Set Value            */
#define NMI_INTRUPT_REGS_NMIFLGCLR_FLUNCERR_Get(x) (((uint16_t) (x) & NMI_INTRUPT_REGS_NMIFLGCLR_FLUNCERR_Msk) >> NMI_INTRUPT_REGS_NMIFLGCLR_FLUNCERR_Pos) /*!< FLUNCERR Get Value            */


#define NMI_INTRUPT_REGS_NMIFLGCLR_RAMUNCERR_Pos    (2U)                                                                                  /*!< RAMUNCERR Postion   2          */ 
#define NMI_INTRUPT_REGS_NMIFLGCLR_RAMUNCERR_Msk    (0x1U << NMI_INTRUPT_REGS_NMIFLGCLR_RAMUNCERR_Pos)                                    /*!< RAMUNCERR Mask      0x00000004 */
#define NMI_INTRUPT_REGS_NMIFLGCLR_RAMUNCERR_Set(x) (((uint16_t) (x) << NMI_INTRUPT_REGS_NMIFLGCLR_RAMUNCERR_Pos) & NMI_INTRUPT_REGS_NMIFLGCLR_RAMUNCERR_Msk) /*!< RAMUNCERR Set Value            */
#define NMI_INTRUPT_REGS_NMIFLGCLR_RAMUNCERR_Get(x) (((uint16_t) (x) & NMI_INTRUPT_REGS_NMIFLGCLR_RAMUNCERR_Msk) >> NMI_INTRUPT_REGS_NMIFLGCLR_RAMUNCERR_Pos) /*!< RAMUNCERR Get Value            */


#define NMI_INTRUPT_REGS_NMIFLGCLR_CLOCKFAIL_Pos    (1U)                                                                                  /*!< CLOCKFAIL Postion   1          */ 
#define NMI_INTRUPT_REGS_NMIFLGCLR_CLOCKFAIL_Msk    (0x1U << NMI_INTRUPT_REGS_NMIFLGCLR_CLOCKFAIL_Pos)                                    /*!< CLOCKFAIL Mask      0x00000002 */
#define NMI_INTRUPT_REGS_NMIFLGCLR_CLOCKFAIL_Set(x) (((uint16_t) (x) << NMI_INTRUPT_REGS_NMIFLGCLR_CLOCKFAIL_Pos) & NMI_INTRUPT_REGS_NMIFLGCLR_CLOCKFAIL_Msk) /*!< CLOCKFAIL Set Value            */
#define NMI_INTRUPT_REGS_NMIFLGCLR_CLOCKFAIL_Get(x) (((uint16_t) (x) & NMI_INTRUPT_REGS_NMIFLGCLR_CLOCKFAIL_Msk) >> NMI_INTRUPT_REGS_NMIFLGCLR_CLOCKFAIL_Pos) /*!< CLOCKFAIL Get Value            */


#define NMI_INTRUPT_REGS_NMIFLGCLR_NMIINT_Pos    (0U)                                                                                  /*!< NMIINT Postion   0          */ 
#define NMI_INTRUPT_REGS_NMIFLGCLR_NMIINT_Msk    (0x1U << NMI_INTRUPT_REGS_NMIFLGCLR_NMIINT_Pos)                                       /*!< NMIINT Mask      0x00000001 */
#define NMI_INTRUPT_REGS_NMIFLGCLR_NMIINT_Set(x) (((uint16_t) (x) << NMI_INTRUPT_REGS_NMIFLGCLR_NMIINT_Pos) & NMI_INTRUPT_REGS_NMIFLGCLR_NMIINT_Msk) /*!< NMIINT Set Value            */
#define NMI_INTRUPT_REGS_NMIFLGCLR_NMIINT_Get(x) (((uint16_t) (x) & NMI_INTRUPT_REGS_NMIFLGCLR_NMIINT_Msk) >> NMI_INTRUPT_REGS_NMIFLGCLR_NMIINT_Pos) /*!< NMIINT Get Value            */


/* NMIFLGFRC bitfield */
#define NMI_INTRUPT_REGS_NMIFLGFRC_CPU2NMIWDRSN_Pos    (10U)                                                                                 /*!< CPU2NMIWDRSN Postion   10         */ 
#define NMI_INTRUPT_REGS_NMIFLGFRC_CPU2NMIWDRSN_Msk    (0x1U << NMI_INTRUPT_REGS_NMIFLGFRC_CPU2NMIWDRSN_Pos)                                 /*!< CPU2NMIWDRSN Mask      0x00000400 */
#define NMI_INTRUPT_REGS_NMIFLGFRC_CPU2NMIWDRSN_Set(x) (((uint16_t) (x) << NMI_INTRUPT_REGS_NMIFLGFRC_CPU2NMIWDRSN_Pos) & NMI_INTRUPT_REGS_NMIFLGFRC_CPU2NMIWDRSN_Msk) /*!< CPU2NMIWDRSN Set Value            */
#define NMI_INTRUPT_REGS_NMIFLGFRC_CPU2NMIWDRSN_Get(x) (((uint16_t) (x) & NMI_INTRUPT_REGS_NMIFLGFRC_CPU2NMIWDRSN_Msk) >> NMI_INTRUPT_REGS_NMIFLGFRC_CPU2NMIWDRSN_Pos) /*!< CPU2NMIWDRSN Get Value            */


#define NMI_INTRUPT_REGS_NMIFLGFRC_CPU2WDRSN_Pos    (9U)                                                                                  /*!< CPU2WDRSN Postion   9          */ 
#define NMI_INTRUPT_REGS_NMIFLGFRC_CPU2WDRSN_Msk    (0x1U << NMI_INTRUPT_REGS_NMIFLGFRC_CPU2WDRSN_Pos)                                    /*!< CPU2WDRSN Mask      0x00000200 */
#define NMI_INTRUPT_REGS_NMIFLGFRC_CPU2WDRSN_Set(x) (((uint16_t) (x) << NMI_INTRUPT_REGS_NMIFLGFRC_CPU2WDRSN_Pos) & NMI_INTRUPT_REGS_NMIFLGFRC_CPU2WDRSN_Msk) /*!< CPU2WDRSN Set Value            */
#define NMI_INTRUPT_REGS_NMIFLGFRC_CPU2WDRSN_Get(x) (((uint16_t) (x) & NMI_INTRUPT_REGS_NMIFLGFRC_CPU2WDRSN_Msk) >> NMI_INTRUPT_REGS_NMIFLGFRC_CPU2WDRSN_Pos) /*!< CPU2WDRSN Get Value            */


#define NMI_INTRUPT_REGS_NMIFLGFRC_CLBNMI_Pos    (8U)                                                                                  /*!< CLBNMI Postion   8          */ 
#define NMI_INTRUPT_REGS_NMIFLGFRC_CLBNMI_Msk    (0x1U << NMI_INTRUPT_REGS_NMIFLGFRC_CLBNMI_Pos)                                       /*!< CLBNMI Mask      0x00000100 */
#define NMI_INTRUPT_REGS_NMIFLGFRC_CLBNMI_Set(x) (((uint16_t) (x) << NMI_INTRUPT_REGS_NMIFLGFRC_CLBNMI_Pos) & NMI_INTRUPT_REGS_NMIFLGFRC_CLBNMI_Msk) /*!< CLBNMI Set Value            */
#define NMI_INTRUPT_REGS_NMIFLGFRC_CLBNMI_Get(x) (((uint16_t) (x) & NMI_INTRUPT_REGS_NMIFLGFRC_CLBNMI_Msk) >> NMI_INTRUPT_REGS_NMIFLGFRC_CLBNMI_Pos) /*!< CLBNMI Get Value            */


#define NMI_INTRUPT_REGS_NMIFLGFRC_FLUNCERR_Pos    (3U)                                                                                  /*!< FLUNCERR Postion   3          */ 
#define NMI_INTRUPT_REGS_NMIFLGFRC_FLUNCERR_Msk    (0x1U << NMI_INTRUPT_REGS_NMIFLGFRC_FLUNCERR_Pos)                                     /*!< FLUNCERR Mask      0x00000008 */
#define NMI_INTRUPT_REGS_NMIFLGFRC_FLUNCERR_Set(x) (((uint16_t) (x) << NMI_INTRUPT_REGS_NMIFLGFRC_FLUNCERR_Pos) & NMI_INTRUPT_REGS_NMIFLGFRC_FLUNCERR_Msk) /*!< FLUNCERR Set Value            */
#define NMI_INTRUPT_REGS_NMIFLGFRC_FLUNCERR_Get(x) (((uint16_t) (x) & NMI_INTRUPT_REGS_NMIFLGFRC_FLUNCERR_Msk) >> NMI_INTRUPT_REGS_NMIFLGFRC_FLUNCERR_Pos) /*!< FLUNCERR Get Value            */


#define NMI_INTRUPT_REGS_NMIFLGFRC_RAMUNCERR_Pos    (2U)                                                                                  /*!< RAMUNCERR Postion   2          */ 
#define NMI_INTRUPT_REGS_NMIFLGFRC_RAMUNCERR_Msk    (0x1U << NMI_INTRUPT_REGS_NMIFLGFRC_RAMUNCERR_Pos)                                    /*!< RAMUNCERR Mask      0x00000004 */
#define NMI_INTRUPT_REGS_NMIFLGFRC_RAMUNCERR_Set(x) (((uint16_t) (x) << NMI_INTRUPT_REGS_NMIFLGFRC_RAMUNCERR_Pos) & NMI_INTRUPT_REGS_NMIFLGFRC_RAMUNCERR_Msk) /*!< RAMUNCERR Set Value            */
#define NMI_INTRUPT_REGS_NMIFLGFRC_RAMUNCERR_Get(x) (((uint16_t) (x) & NMI_INTRUPT_REGS_NMIFLGFRC_RAMUNCERR_Msk) >> NMI_INTRUPT_REGS_NMIFLGFRC_RAMUNCERR_Pos) /*!< RAMUNCERR Get Value            */


#define NMI_INTRUPT_REGS_NMIFLGFRC_CLOCKFAIL_Pos    (1U)                                                                                  /*!< CLOCKFAIL Postion   1          */ 
#define NMI_INTRUPT_REGS_NMIFLGFRC_CLOCKFAIL_Msk    (0x1U << NMI_INTRUPT_REGS_NMIFLGFRC_CLOCKFAIL_Pos)                                    /*!< CLOCKFAIL Mask      0x00000002 */
#define NMI_INTRUPT_REGS_NMIFLGFRC_CLOCKFAIL_Set(x) (((uint16_t) (x) << NMI_INTRUPT_REGS_NMIFLGFRC_CLOCKFAIL_Pos) & NMI_INTRUPT_REGS_NMIFLGFRC_CLOCKFAIL_Msk) /*!< CLOCKFAIL Set Value            */
#define NMI_INTRUPT_REGS_NMIFLGFRC_CLOCKFAIL_Get(x) (((uint16_t) (x) & NMI_INTRUPT_REGS_NMIFLGFRC_CLOCKFAIL_Msk) >> NMI_INTRUPT_REGS_NMIFLGFRC_CLOCKFAIL_Pos) /*!< CLOCKFAIL Get Value            */


/* NMIWDCNT bitfield */
#define NMI_INTRUPT_REGS_NMIWDCNT_NMIWDCNT_Pos    (0U)                                                                                  /*!< NMIWDCNT Postion   0          */ 
#define NMI_INTRUPT_REGS_NMIWDCNT_NMIWDCNT_Msk    (0xffffU << NMI_INTRUPT_REGS_NMIWDCNT_NMIWDCNT_Pos)                                   /*!< NMIWDCNT Mask      0x0000FFFF */
#define NMI_INTRUPT_REGS_NMIWDCNT_NMIWDCNT_Set(x) (((uint16_t) (x) << NMI_INTRUPT_REGS_NMIWDCNT_NMIWDCNT_Pos) & NMI_INTRUPT_REGS_NMIWDCNT_NMIWDCNT_Msk) /*!< NMIWDCNT Set Value            */
#define NMI_INTRUPT_REGS_NMIWDCNT_NMIWDCNT_Get(x) (((uint16_t) (x) & NMI_INTRUPT_REGS_NMIWDCNT_NMIWDCNT_Msk) >> NMI_INTRUPT_REGS_NMIWDCNT_NMIWDCNT_Pos) /*!< NMIWDCNT Get Value            */


/* NMIWDPRD bitfield */
#define NMI_INTRUPT_REGS_NMIWDPRD_NMIWDPRD_Pos    (0U)                                                                                  /*!< NMIWDPRD Postion   0          */ 
#define NMI_INTRUPT_REGS_NMIWDPRD_NMIWDPRD_Msk    (0xffffU << NMI_INTRUPT_REGS_NMIWDPRD_NMIWDPRD_Pos)                                   /*!< NMIWDPRD Mask      0x0000FFFF */
#define NMI_INTRUPT_REGS_NMIWDPRD_NMIWDPRD_Set(x) (((uint16_t) (x) << NMI_INTRUPT_REGS_NMIWDPRD_NMIWDPRD_Pos) & NMI_INTRUPT_REGS_NMIWDPRD_NMIWDPRD_Msk) /*!< NMIWDPRD Set Value            */
#define NMI_INTRUPT_REGS_NMIWDPRD_NMIWDPRD_Get(x) (((uint16_t) (x) & NMI_INTRUPT_REGS_NMIWDPRD_NMIWDPRD_Msk) >> NMI_INTRUPT_REGS_NMIWDPRD_NMIWDPRD_Pos) /*!< NMIWDPRD Get Value            */


/* NMISHDFLG bitfield */
#define NMI_INTRUPT_REGS_NMISHDFLG_CPU2NMIWDRSN_Pos    (10U)                                                                                 /*!< CPU2NMIWDRSN Postion   10         */ 
#define NMI_INTRUPT_REGS_NMISHDFLG_CPU2NMIWDRSN_Msk    (0x1U << NMI_INTRUPT_REGS_NMISHDFLG_CPU2NMIWDRSN_Pos)                                 /*!< CPU2NMIWDRSN Mask      0x00000400 */
#define NMI_INTRUPT_REGS_NMISHDFLG_CPU2NMIWDRSN_Set(x) (((uint32_t) (x) << NMI_INTRUPT_REGS_NMISHDFLG_CPU2NMIWDRSN_Pos) & NMI_INTRUPT_REGS_NMISHDFLG_CPU2NMIWDRSN_Msk) /*!< CPU2NMIWDRSN Set Value            */
#define NMI_INTRUPT_REGS_NMISHDFLG_CPU2NMIWDRSN_Get(x) (((uint32_t) (x) & NMI_INTRUPT_REGS_NMISHDFLG_CPU2NMIWDRSN_Msk) >> NMI_INTRUPT_REGS_NMISHDFLG_CPU2NMIWDRSN_Pos) /*!< CPU2NMIWDRSN Get Value            */


#define NMI_INTRUPT_REGS_NMISHDFLG_CPU2WDRSN_Pos    (9U)                                                                                  /*!< CPU2WDRSN Postion   9          */ 
#define NMI_INTRUPT_REGS_NMISHDFLG_CPU2WDRSN_Msk    (0x1U << NMI_INTRUPT_REGS_NMISHDFLG_CPU2WDRSN_Pos)                                    /*!< CPU2WDRSN Mask      0x00000200 */
#define NMI_INTRUPT_REGS_NMISHDFLG_CPU2WDRSN_Set(x) (((uint32_t) (x) << NMI_INTRUPT_REGS_NMISHDFLG_CPU2WDRSN_Pos) & NMI_INTRUPT_REGS_NMISHDFLG_CPU2WDRSN_Msk) /*!< CPU2WDRSN Set Value            */
#define NMI_INTRUPT_REGS_NMISHDFLG_CPU2WDRSN_Get(x) (((uint32_t) (x) & NMI_INTRUPT_REGS_NMISHDFLG_CPU2WDRSN_Msk) >> NMI_INTRUPT_REGS_NMISHDFLG_CPU2WDRSN_Pos) /*!< CPU2WDRSN Get Value            */


#define NMI_INTRUPT_REGS_NMISHDFLG_CLBNMI_Pos    (8U)                                                                                  /*!< CLBNMI Postion   8          */ 
#define NMI_INTRUPT_REGS_NMISHDFLG_CLBNMI_Msk    (0x1U << NMI_INTRUPT_REGS_NMISHDFLG_CLBNMI_Pos)                                       /*!< CLBNMI Mask      0x00000100 */
#define NMI_INTRUPT_REGS_NMISHDFLG_CLBNMI_Set(x) (((uint32_t) (x) << NMI_INTRUPT_REGS_NMISHDFLG_CLBNMI_Pos) & NMI_INTRUPT_REGS_NMISHDFLG_CLBNMI_Msk) /*!< CLBNMI Set Value            */
#define NMI_INTRUPT_REGS_NMISHDFLG_CLBNMI_Get(x) (((uint32_t) (x) & NMI_INTRUPT_REGS_NMISHDFLG_CLBNMI_Msk) >> NMI_INTRUPT_REGS_NMISHDFLG_CLBNMI_Pos) /*!< CLBNMI Get Value            */


#define NMI_INTRUPT_REGS_NMISHDFLG_FLUNCERR_Pos    (3U)                                                                                  /*!< FLUNCERR Postion   3          */ 
#define NMI_INTRUPT_REGS_NMISHDFLG_FLUNCERR_Msk    (0x1U << NMI_INTRUPT_REGS_NMISHDFLG_FLUNCERR_Pos)                                     /*!< FLUNCERR Mask      0x00000008 */
#define NMI_INTRUPT_REGS_NMISHDFLG_FLUNCERR_Set(x) (((uint32_t) (x) << NMI_INTRUPT_REGS_NMISHDFLG_FLUNCERR_Pos) & NMI_INTRUPT_REGS_NMISHDFLG_FLUNCERR_Msk) /*!< FLUNCERR Set Value            */
#define NMI_INTRUPT_REGS_NMISHDFLG_FLUNCERR_Get(x) (((uint32_t) (x) & NMI_INTRUPT_REGS_NMISHDFLG_FLUNCERR_Msk) >> NMI_INTRUPT_REGS_NMISHDFLG_FLUNCERR_Pos) /*!< FLUNCERR Get Value            */


#define NMI_INTRUPT_REGS_NMISHDFLG_RAMUNCERR_Pos    (2U)                                                                                  /*!< RAMUNCERR Postion   2          */ 
#define NMI_INTRUPT_REGS_NMISHDFLG_RAMUNCERR_Msk    (0x1U << NMI_INTRUPT_REGS_NMISHDFLG_RAMUNCERR_Pos)                                    /*!< RAMUNCERR Mask      0x00000004 */
#define NMI_INTRUPT_REGS_NMISHDFLG_RAMUNCERR_Set(x) (((uint32_t) (x) << NMI_INTRUPT_REGS_NMISHDFLG_RAMUNCERR_Pos) & NMI_INTRUPT_REGS_NMISHDFLG_RAMUNCERR_Msk) /*!< RAMUNCERR Set Value            */
#define NMI_INTRUPT_REGS_NMISHDFLG_RAMUNCERR_Get(x) (((uint32_t) (x) & NMI_INTRUPT_REGS_NMISHDFLG_RAMUNCERR_Msk) >> NMI_INTRUPT_REGS_NMISHDFLG_RAMUNCERR_Pos) /*!< RAMUNCERR Get Value            */


#define NMI_INTRUPT_REGS_NMISHDFLG_CLOCKFAIL_Pos    (1U)                                                                                  /*!< CLOCKFAIL Postion   1          */ 
#define NMI_INTRUPT_REGS_NMISHDFLG_CLOCKFAIL_Msk    (0x1U << NMI_INTRUPT_REGS_NMISHDFLG_CLOCKFAIL_Pos)                                    /*!< CLOCKFAIL Mask      0x00000002 */
#define NMI_INTRUPT_REGS_NMISHDFLG_CLOCKFAIL_Set(x) (((uint32_t) (x) << NMI_INTRUPT_REGS_NMISHDFLG_CLOCKFAIL_Pos) & NMI_INTRUPT_REGS_NMISHDFLG_CLOCKFAIL_Msk) /*!< CLOCKFAIL Set Value            */
#define NMI_INTRUPT_REGS_NMISHDFLG_CLOCKFAIL_Get(x) (((uint32_t) (x) & NMI_INTRUPT_REGS_NMISHDFLG_CLOCKFAIL_Msk) >> NMI_INTRUPT_REGS_NMISHDFLG_CLOCKFAIL_Pos) /*!< CLOCKFAIL Get Value            */


/* NMIWDCFG bitfield */
#define NMI_INTRUPT_REGS_NMIWDCFG_NMIWD_EN_Pos    (0U)                                                                                  /*!< NMIWD_EN Postion   0          */ 
#define NMI_INTRUPT_REGS_NMIWDCFG_NMIWD_EN_Msk    (0x1U << NMI_INTRUPT_REGS_NMIWDCFG_NMIWD_EN_Pos)                                      /*!< NMIWD_EN Mask      0x00000001 */
#define NMI_INTRUPT_REGS_NMIWDCFG_NMIWD_EN_Set(x) (((uint32_t) (x) << NMI_INTRUPT_REGS_NMIWDCFG_NMIWD_EN_Pos) & NMI_INTRUPT_REGS_NMIWDCFG_NMIWD_EN_Msk) /*!< NMIWD_EN Set Value            */
#define NMI_INTRUPT_REGS_NMIWDCFG_NMIWD_EN_Get(x) (((uint32_t) (x) & NMI_INTRUPT_REGS_NMIWDCFG_NMIWD_EN_Msk) >> NMI_INTRUPT_REGS_NMIWDCFG_NMIWD_EN_Pos) /*!< NMIWD_EN Get Value            */


/* NMICLBCFG bitfield */
#define NMI_INTRUPT_REGS_NMICLBCFG_CLBNMISELECT_Pos    (0U)                                                                                  /*!< CLBNMISELECT Postion   0          */ 
#define NMI_INTRUPT_REGS_NMICLBCFG_CLBNMISELECT_Msk    (0x1U << NMI_INTRUPT_REGS_NMICLBCFG_CLBNMISELECT_Pos)                                 /*!< CLBNMISELECT Mask      0x00000001 */
#define NMI_INTRUPT_REGS_NMICLBCFG_CLBNMISELECT_Set(x) (((uint32_t) (x) << NMI_INTRUPT_REGS_NMICLBCFG_CLBNMISELECT_Pos) & NMI_INTRUPT_REGS_NMICLBCFG_CLBNMISELECT_Msk) /*!< CLBNMISELECT Set Value            */
#define NMI_INTRUPT_REGS_NMICLBCFG_CLBNMISELECT_Get(x) (((uint32_t) (x) & NMI_INTRUPT_REGS_NMICLBCFG_CLBNMISELECT_Msk) >> NMI_INTRUPT_REGS_NMICLBCFG_CLBNMISELECT_Pos) /*!< CLBNMISELECT Get Value            */


/* XINT1CR bitfield */
#define XINT_REGS_XINT1CR_POLARITY_Pos    (2U)                                                                                  /*!< POLARITY Postion   2          */ 
#define XINT_REGS_XINT1CR_POLARITY_Msk    (0x3U << XINT_REGS_XINT1CR_POLARITY_Pos)                                              /*!< POLARITY Mask      0x0000000C */
#define XINT_REGS_XINT1CR_POLARITY_Set(x) (((uint16_t) (x) << XINT_REGS_XINT1CR_POLARITY_Pos) & XINT_REGS_XINT1CR_POLARITY_Msk) /*!< POLARITY Set Value            */
#define XINT_REGS_XINT1CR_POLARITY_Get(x) (((uint16_t) (x) & XINT_REGS_XINT1CR_POLARITY_Msk) >> XINT_REGS_XINT1CR_POLARITY_Pos) /*!< POLARITY Get Value            */


#define XINT_REGS_XINT1CR_INTR_ENABLE_Pos    (0U)                                                                                  /*!< INTR_ENABLE Postion   0          */ 
#define XINT_REGS_XINT1CR_INTR_ENABLE_Msk    (0x1U << XINT_REGS_XINT1CR_INTR_ENABLE_Pos)                                           /*!< INTR_ENABLE Mask      0x00000001 */
#define XINT_REGS_XINT1CR_INTR_ENABLE_Set(x) (((uint16_t) (x) << XINT_REGS_XINT1CR_INTR_ENABLE_Pos) & XINT_REGS_XINT1CR_INTR_ENABLE_Msk) /*!< INTR_ENABLE Set Value            */
#define XINT_REGS_XINT1CR_INTR_ENABLE_Get(x) (((uint16_t) (x) & XINT_REGS_XINT1CR_INTR_ENABLE_Msk) >> XINT_REGS_XINT1CR_INTR_ENABLE_Pos) /*!< INTR_ENABLE Get Value            */


/* XINT2CR bitfield */
#define XINT_REGS_XINT2CR_POLARITY_Pos    (2U)                                                                                  /*!< POLARITY Postion   2          */ 
#define XINT_REGS_XINT2CR_POLARITY_Msk    (0x3U << XINT_REGS_XINT2CR_POLARITY_Pos)                                              /*!< POLARITY Mask      0x0000000C */
#define XINT_REGS_XINT2CR_POLARITY_Set(x) (((uint16_t) (x) << XINT_REGS_XINT2CR_POLARITY_Pos) & XINT_REGS_XINT2CR_POLARITY_Msk) /*!< POLARITY Set Value            */
#define XINT_REGS_XINT2CR_POLARITY_Get(x) (((uint16_t) (x) & XINT_REGS_XINT2CR_POLARITY_Msk) >> XINT_REGS_XINT2CR_POLARITY_Pos) /*!< POLARITY Get Value            */


#define XINT_REGS_XINT2CR_INTR_ENABLE_Pos    (0U)                                                                                  /*!< INTR_ENABLE Postion   0          */ 
#define XINT_REGS_XINT2CR_INTR_ENABLE_Msk    (0x1U << XINT_REGS_XINT2CR_INTR_ENABLE_Pos)                                           /*!< INTR_ENABLE Mask      0x00000001 */
#define XINT_REGS_XINT2CR_INTR_ENABLE_Set(x) (((uint16_t) (x) << XINT_REGS_XINT2CR_INTR_ENABLE_Pos) & XINT_REGS_XINT2CR_INTR_ENABLE_Msk) /*!< INTR_ENABLE Set Value            */
#define XINT_REGS_XINT2CR_INTR_ENABLE_Get(x) (((uint16_t) (x) & XINT_REGS_XINT2CR_INTR_ENABLE_Msk) >> XINT_REGS_XINT2CR_INTR_ENABLE_Pos) /*!< INTR_ENABLE Get Value            */


/* XINT3CR bitfield */
#define XINT_REGS_XINT3CR_POLARITY_Pos    (2U)                                                                                  /*!< POLARITY Postion   2          */ 
#define XINT_REGS_XINT3CR_POLARITY_Msk    (0x3U << XINT_REGS_XINT3CR_POLARITY_Pos)                                              /*!< POLARITY Mask      0x0000000C */
#define XINT_REGS_XINT3CR_POLARITY_Set(x) (((uint16_t) (x) << XINT_REGS_XINT3CR_POLARITY_Pos) & XINT_REGS_XINT3CR_POLARITY_Msk) /*!< POLARITY Set Value            */
#define XINT_REGS_XINT3CR_POLARITY_Get(x) (((uint16_t) (x) & XINT_REGS_XINT3CR_POLARITY_Msk) >> XINT_REGS_XINT3CR_POLARITY_Pos) /*!< POLARITY Get Value            */


#define XINT_REGS_XINT3CR_INTR_ENABLE_Pos    (0U)                                                                                  /*!< INTR_ENABLE Postion   0          */ 
#define XINT_REGS_XINT3CR_INTR_ENABLE_Msk    (0x1U << XINT_REGS_XINT3CR_INTR_ENABLE_Pos)                                           /*!< INTR_ENABLE Mask      0x00000001 */
#define XINT_REGS_XINT3CR_INTR_ENABLE_Set(x) (((uint16_t) (x) << XINT_REGS_XINT3CR_INTR_ENABLE_Pos) & XINT_REGS_XINT3CR_INTR_ENABLE_Msk) /*!< INTR_ENABLE Set Value            */
#define XINT_REGS_XINT3CR_INTR_ENABLE_Get(x) (((uint16_t) (x) & XINT_REGS_XINT3CR_INTR_ENABLE_Msk) >> XINT_REGS_XINT3CR_INTR_ENABLE_Pos) /*!< INTR_ENABLE Get Value            */


/* XINT4CR bitfield */
#define XINT_REGS_XINT4CR_POLARITY_Pos    (2U)                                                                                  /*!< POLARITY Postion   2          */ 
#define XINT_REGS_XINT4CR_POLARITY_Msk    (0x3U << XINT_REGS_XINT4CR_POLARITY_Pos)                                              /*!< POLARITY Mask      0x0000000C */
#define XINT_REGS_XINT4CR_POLARITY_Set(x) (((uint16_t) (x) << XINT_REGS_XINT4CR_POLARITY_Pos) & XINT_REGS_XINT4CR_POLARITY_Msk) /*!< POLARITY Set Value            */
#define XINT_REGS_XINT4CR_POLARITY_Get(x) (((uint16_t) (x) & XINT_REGS_XINT4CR_POLARITY_Msk) >> XINT_REGS_XINT4CR_POLARITY_Pos) /*!< POLARITY Get Value            */


#define XINT_REGS_XINT4CR_INTR_ENABLE_Pos    (0U)                                                                                  /*!< INTR_ENABLE Postion   0          */ 
#define XINT_REGS_XINT4CR_INTR_ENABLE_Msk    (0x1U << XINT_REGS_XINT4CR_INTR_ENABLE_Pos)                                           /*!< INTR_ENABLE Mask      0x00000001 */
#define XINT_REGS_XINT4CR_INTR_ENABLE_Set(x) (((uint16_t) (x) << XINT_REGS_XINT4CR_INTR_ENABLE_Pos) & XINT_REGS_XINT4CR_INTR_ENABLE_Msk) /*!< INTR_ENABLE Set Value            */
#define XINT_REGS_XINT4CR_INTR_ENABLE_Get(x) (((uint16_t) (x) & XINT_REGS_XINT4CR_INTR_ENABLE_Msk) >> XINT_REGS_XINT4CR_INTR_ENABLE_Pos) /*!< INTR_ENABLE Get Value            */


/* XINT5CR bitfield */
#define XINT_REGS_XINT5CR_POLARITY_Pos    (2U)                                                                                  /*!< POLARITY Postion   2          */ 
#define XINT_REGS_XINT5CR_POLARITY_Msk    (0x3U << XINT_REGS_XINT5CR_POLARITY_Pos)                                              /*!< POLARITY Mask      0x0000000C */
#define XINT_REGS_XINT5CR_POLARITY_Set(x) (((uint32_t) (x) << XINT_REGS_XINT5CR_POLARITY_Pos) & XINT_REGS_XINT5CR_POLARITY_Msk) /*!< POLARITY Set Value            */
#define XINT_REGS_XINT5CR_POLARITY_Get(x) (((uint32_t) (x) & XINT_REGS_XINT5CR_POLARITY_Msk) >> XINT_REGS_XINT5CR_POLARITY_Pos) /*!< POLARITY Get Value            */


#define XINT_REGS_XINT5CR_INTR_ENABLE_Pos    (0U)                                                                                  /*!< INTR_ENABLE Postion   0          */ 
#define XINT_REGS_XINT5CR_INTR_ENABLE_Msk    (0x1U << XINT_REGS_XINT5CR_INTR_ENABLE_Pos)                                           /*!< INTR_ENABLE Mask      0x00000001 */
#define XINT_REGS_XINT5CR_INTR_ENABLE_Set(x) (((uint32_t) (x) << XINT_REGS_XINT5CR_INTR_ENABLE_Pos) & XINT_REGS_XINT5CR_INTR_ENABLE_Msk) /*!< INTR_ENABLE Set Value            */
#define XINT_REGS_XINT5CR_INTR_ENABLE_Get(x) (((uint32_t) (x) & XINT_REGS_XINT5CR_INTR_ENABLE_Msk) >> XINT_REGS_XINT5CR_INTR_ENABLE_Pos) /*!< INTR_ENABLE Get Value            */


/* XINT1CTR bitfield */
#define XINT_REGS_XINT1CTR_INTCTR_Pos    (0U)                                                                                  /*!< INTCTR Postion   0          */ 
#define XINT_REGS_XINT1CTR_INTCTR_Msk    (0xffffU << XINT_REGS_XINT1CTR_INTCTR_Pos)                                            /*!< INTCTR Mask      0x0000FFFF */
#define XINT_REGS_XINT1CTR_INTCTR_Set(x) (((uint16_t) (x) << XINT_REGS_XINT1CTR_INTCTR_Pos) & XINT_REGS_XINT1CTR_INTCTR_Msk)   /*!< INTCTR Set Value            */
#define XINT_REGS_XINT1CTR_INTCTR_Get(x) (((uint16_t) (x) & XINT_REGS_XINT1CTR_INTCTR_Msk) >> XINT_REGS_XINT1CTR_INTCTR_Pos)   /*!< INTCTR Get Value            */


/* XINT2CTR bitfield */
#define XINT_REGS_XINT2CTR_INTCTR_Pos    (0U)                                                                                  /*!< INTCTR Postion   0          */ 
#define XINT_REGS_XINT2CTR_INTCTR_Msk    (0xffffU << XINT_REGS_XINT2CTR_INTCTR_Pos)                                            /*!< INTCTR Mask      0x0000FFFF */
#define XINT_REGS_XINT2CTR_INTCTR_Set(x) (((uint16_t) (x) << XINT_REGS_XINT2CTR_INTCTR_Pos) & XINT_REGS_XINT2CTR_INTCTR_Msk)   /*!< INTCTR Set Value            */
#define XINT_REGS_XINT2CTR_INTCTR_Get(x) (((uint16_t) (x) & XINT_REGS_XINT2CTR_INTCTR_Msk) >> XINT_REGS_XINT2CTR_INTCTR_Pos)   /*!< INTCTR Get Value            */


/* XINT3CTR bitfield */
#define XINT_REGS_XINT3CTR_INTCTR_Pos    (0U)                                                                                  /*!< INTCTR Postion   0          */ 
#define XINT_REGS_XINT3CTR_INTCTR_Msk    (0xffffU << XINT_REGS_XINT3CTR_INTCTR_Pos)                                            /*!< INTCTR Mask      0x0000FFFF */
#define XINT_REGS_XINT3CTR_INTCTR_Set(x) (((uint32_t) (x) << XINT_REGS_XINT3CTR_INTCTR_Pos) & XINT_REGS_XINT3CTR_INTCTR_Msk)   /*!< INTCTR Set Value            */
#define XINT_REGS_XINT3CTR_INTCTR_Get(x) (((uint32_t) (x) & XINT_REGS_XINT3CTR_INTCTR_Msk) >> XINT_REGS_XINT3CTR_INTCTR_Pos)   /*!< INTCTR Get Value            */


/* XINT4CTR bitfield */
#define XINT_REGS_XINT4CTR_INTCTR_Pos    (0U)                                                                                  /*!< INTCTR Postion   0          */ 
#define XINT_REGS_XINT4CTR_INTCTR_Msk    (0xffffU << XINT_REGS_XINT4CTR_INTCTR_Pos)                                            /*!< INTCTR Mask      0x0000FFFF */
#define XINT_REGS_XINT4CTR_INTCTR_Set(x) (((uint32_t) (x) << XINT_REGS_XINT4CTR_INTCTR_Pos) & XINT_REGS_XINT4CTR_INTCTR_Msk)   /*!< INTCTR Set Value            */
#define XINT_REGS_XINT4CTR_INTCTR_Get(x) (((uint32_t) (x) & XINT_REGS_XINT4CTR_INTCTR_Msk) >> XINT_REGS_XINT4CTR_INTCTR_Pos)   /*!< INTCTR Get Value            */


/* XINT5CTR bitfield */
#define XINT_REGS_XINT5CTR_INTCTR_Pos    (0U)                                                                                  /*!< INTCTR Postion   0          */ 
#define XINT_REGS_XINT5CTR_INTCTR_Msk    (0xffffU << XINT_REGS_XINT5CTR_INTCTR_Pos)                                            /*!< INTCTR Mask      0x0000FFFF */
#define XINT_REGS_XINT5CTR_INTCTR_Set(x) (((uint32_t) (x) << XINT_REGS_XINT5CTR_INTCTR_Pos) & XINT_REGS_XINT5CTR_INTCTR_Msk)   /*!< INTCTR Set Value            */
#define XINT_REGS_XINT5CTR_INTCTR_Get(x) (((uint32_t) (x) & XINT_REGS_XINT5CTR_INTCTR_Msk) >> XINT_REGS_XINT5CTR_INTCTR_Pos)   /*!< INTCTR Get Value            */


/* XINT1FLG bitfield */
#define XINT_REGS_XINT1FLG_XINTFLG_Pos    (0U)                                                                                  /*!< XINTFLG Postion   0          */ 
#define XINT_REGS_XINT1FLG_XINTFLG_Msk    (0x1U << XINT_REGS_XINT1FLG_XINTFLG_Pos)                                              /*!< XINTFLG Mask      0x00000001 */
#define XINT_REGS_XINT1FLG_XINTFLG_Set(x) (((uint32_t) (x) << XINT_REGS_XINT1FLG_XINTFLG_Pos) & XINT_REGS_XINT1FLG_XINTFLG_Msk) /*!< XINTFLG Set Value            */
#define XINT_REGS_XINT1FLG_XINTFLG_Get(x) (((uint32_t) (x) & XINT_REGS_XINT1FLG_XINTFLG_Msk) >> XINT_REGS_XINT1FLG_XINTFLG_Pos) /*!< XINTFLG Get Value            */


/* XINT2FLG bitfield */
#define XINT_REGS_XINT2FLG_XINTFLG_Pos    (0U)                                                                                  /*!< XINTFLG Postion   0          */ 
#define XINT_REGS_XINT2FLG_XINTFLG_Msk    (0x1U << XINT_REGS_XINT2FLG_XINTFLG_Pos)                                              /*!< XINTFLG Mask      0x00000001 */
#define XINT_REGS_XINT2FLG_XINTFLG_Set(x) (((uint32_t) (x) << XINT_REGS_XINT2FLG_XINTFLG_Pos) & XINT_REGS_XINT2FLG_XINTFLG_Msk) /*!< XINTFLG Set Value            */
#define XINT_REGS_XINT2FLG_XINTFLG_Get(x) (((uint32_t) (x) & XINT_REGS_XINT2FLG_XINTFLG_Msk) >> XINT_REGS_XINT2FLG_XINTFLG_Pos) /*!< XINTFLG Get Value            */


/* XINT3FLG bitfield */
#define XINT_REGS_XINT3FLG_XINTFLG_Pos    (0U)                                                                                  /*!< XINTFLG Postion   0          */ 
#define XINT_REGS_XINT3FLG_XINTFLG_Msk    (0x1U << XINT_REGS_XINT3FLG_XINTFLG_Pos)                                              /*!< XINTFLG Mask      0x00000001 */
#define XINT_REGS_XINT3FLG_XINTFLG_Set(x) (((uint32_t) (x) << XINT_REGS_XINT3FLG_XINTFLG_Pos) & XINT_REGS_XINT3FLG_XINTFLG_Msk) /*!< XINTFLG Set Value            */
#define XINT_REGS_XINT3FLG_XINTFLG_Get(x) (((uint32_t) (x) & XINT_REGS_XINT3FLG_XINTFLG_Msk) >> XINT_REGS_XINT3FLG_XINTFLG_Pos) /*!< XINTFLG Get Value            */


/* XINT4FLG bitfield */
#define XINT_REGS_XINT4FLG_XINTFLG_Pos    (0U)                                                                                  /*!< XINTFLG Postion   0          */ 
#define XINT_REGS_XINT4FLG_XINTFLG_Msk    (0x1U << XINT_REGS_XINT4FLG_XINTFLG_Pos)                                              /*!< XINTFLG Mask      0x00000001 */
#define XINT_REGS_XINT4FLG_XINTFLG_Set(x) (((uint32_t) (x) << XINT_REGS_XINT4FLG_XINTFLG_Pos) & XINT_REGS_XINT4FLG_XINTFLG_Msk) /*!< XINTFLG Set Value            */
#define XINT_REGS_XINT4FLG_XINTFLG_Get(x) (((uint32_t) (x) & XINT_REGS_XINT4FLG_XINTFLG_Msk) >> XINT_REGS_XINT4FLG_XINTFLG_Pos) /*!< XINTFLG Get Value            */


/* XINT5FLG bitfield */
#define XINT_REGS_XINT5FLG_XINTFLG_Pos    (0U)                                                                                  /*!< XINTFLG Postion   0          */ 
#define XINT_REGS_XINT5FLG_XINTFLG_Msk    (0x1U << XINT_REGS_XINT5FLG_XINTFLG_Pos)                                              /*!< XINTFLG Mask      0x00000001 */
#define XINT_REGS_XINT5FLG_XINTFLG_Set(x) (((uint32_t) (x) << XINT_REGS_XINT5FLG_XINTFLG_Pos) & XINT_REGS_XINT5FLG_XINTFLG_Msk) /*!< XINTFLG Set Value            */
#define XINT_REGS_XINT5FLG_XINTFLG_Get(x) (((uint32_t) (x) & XINT_REGS_XINT5FLG_XINTFLG_Msk) >> XINT_REGS_XINT5FLG_XINTFLG_Pos) /*!< XINTFLG Get Value            */


/* XINT1CLR bitfield */
#define XINT_REGS_XINT1CLR_XINTCLR_Pos    (0U)                                                                                  /*!< XINTCLR Postion   0          */ 
#define XINT_REGS_XINT1CLR_XINTCLR_Msk    (0x1U << XINT_REGS_XINT1CLR_XINTCLR_Pos)                                              /*!< XINTCLR Mask      0x00000001 */
#define XINT_REGS_XINT1CLR_XINTCLR_Set(x) (((uint32_t) (x) << XINT_REGS_XINT1CLR_XINTCLR_Pos) & XINT_REGS_XINT1CLR_XINTCLR_Msk) /*!< XINTCLR Set Value            */
#define XINT_REGS_XINT1CLR_XINTCLR_Get(x) (((uint32_t) (x) & XINT_REGS_XINT1CLR_XINTCLR_Msk) >> XINT_REGS_XINT1CLR_XINTCLR_Pos) /*!< XINTCLR Get Value            */


/* XINT2CLR bitfield */
#define XINT_REGS_XINT2CLR_XINTCLR_Pos    (0U)                                                                                  /*!< XINTCLR Postion   0          */ 
#define XINT_REGS_XINT2CLR_XINTCLR_Msk    (0x1U << XINT_REGS_XINT2CLR_XINTCLR_Pos)                                              /*!< XINTCLR Mask      0x00000001 */
#define XINT_REGS_XINT2CLR_XINTCLR_Set(x) (((uint32_t) (x) << XINT_REGS_XINT2CLR_XINTCLR_Pos) & XINT_REGS_XINT2CLR_XINTCLR_Msk) /*!< XINTCLR Set Value            */
#define XINT_REGS_XINT2CLR_XINTCLR_Get(x) (((uint32_t) (x) & XINT_REGS_XINT2CLR_XINTCLR_Msk) >> XINT_REGS_XINT2CLR_XINTCLR_Pos) /*!< XINTCLR Get Value            */


/* XINT3CLR bitfield */
#define XINT_REGS_XINT3CLR_XINTCLR_Pos    (0U)                                                                                  /*!< XINTCLR Postion   0          */ 
#define XINT_REGS_XINT3CLR_XINTCLR_Msk    (0x1U << XINT_REGS_XINT3CLR_XINTCLR_Pos)                                              /*!< XINTCLR Mask      0x00000001 */
#define XINT_REGS_XINT3CLR_XINTCLR_Set(x) (((uint32_t) (x) << XINT_REGS_XINT3CLR_XINTCLR_Pos) & XINT_REGS_XINT3CLR_XINTCLR_Msk) /*!< XINTCLR Set Value            */
#define XINT_REGS_XINT3CLR_XINTCLR_Get(x) (((uint32_t) (x) & XINT_REGS_XINT3CLR_XINTCLR_Msk) >> XINT_REGS_XINT3CLR_XINTCLR_Pos) /*!< XINTCLR Get Value            */


/* XINT4CLR bitfield */
#define XINT_REGS_XINT4CLR_XINTCLR_Pos    (0U)                                                                                  /*!< XINTCLR Postion   0          */ 
#define XINT_REGS_XINT4CLR_XINTCLR_Msk    (0x1U << XINT_REGS_XINT4CLR_XINTCLR_Pos)                                              /*!< XINTCLR Mask      0x00000001 */
#define XINT_REGS_XINT4CLR_XINTCLR_Set(x) (((uint32_t) (x) << XINT_REGS_XINT4CLR_XINTCLR_Pos) & XINT_REGS_XINT4CLR_XINTCLR_Msk) /*!< XINTCLR Set Value            */
#define XINT_REGS_XINT4CLR_XINTCLR_Get(x) (((uint32_t) (x) & XINT_REGS_XINT4CLR_XINTCLR_Msk) >> XINT_REGS_XINT4CLR_XINTCLR_Pos) /*!< XINTCLR Get Value            */


/* XINT5CLR bitfield */
#define XINT_REGS_XINT5CLR_XINTCLR_Pos    (0U)                                                                                  /*!< XINTCLR Postion   0          */ 
#define XINT_REGS_XINT5CLR_XINTCLR_Msk    (0x1U << XINT_REGS_XINT5CLR_XINTCLR_Pos)                                              /*!< XINTCLR Mask      0x00000001 */
#define XINT_REGS_XINT5CLR_XINTCLR_Set(x) (((uint32_t) (x) << XINT_REGS_XINT5CLR_XINTCLR_Pos) & XINT_REGS_XINT5CLR_XINTCLR_Msk) /*!< XINTCLR Set Value            */
#define XINT_REGS_XINT5CLR_XINTCLR_Get(x) (((uint32_t) (x) & XINT_REGS_XINT5CLR_XINTCLR_Msk) >> XINT_REGS_XINT5CLR_XINTCLR_Pos) /*!< XINTCLR Get Value            */


/* DEVCFGLOCK1 bitfield */
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL18_Pos    (18U)                                                                                 /*!< CPUSEL18 Postion   18         */ 
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL18_Msk    (0x1U << DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL18_Pos)                                       /*!< CPUSEL18 Mask      0x00040000 */
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL18_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL18_Pos) & DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL18_Msk) /*!< CPUSEL18 Set Value            */
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL18_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL18_Msk) >> DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL18_Pos) /*!< CPUSEL18 Get Value            */


#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL15_Pos    (15U)                                                                                 /*!< CPUSEL15 Postion   15         */ 
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL15_Msk    (0x1U << DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL15_Pos)                                       /*!< CPUSEL15 Mask      0x00008000 */
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL15_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL15_Pos) & DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL15_Msk) /*!< CPUSEL15 Set Value            */
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL15_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL15_Msk) >> DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL15_Pos) /*!< CPUSEL15 Get Value            */


#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL14_Pos    (14U)                                                                                 /*!< CPUSEL14 Postion   14         */ 
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL14_Msk    (0x1U << DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL14_Pos)                                       /*!< CPUSEL14 Mask      0x00004000 */
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL14_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL14_Pos) & DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL14_Msk) /*!< CPUSEL14 Set Value            */
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL14_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL14_Msk) >> DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL14_Pos) /*!< CPUSEL14 Get Value            */


#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL12_Pos    (12U)                                                                                 /*!< CPUSEL12 Postion   12         */ 
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL12_Msk    (0x1U << DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL12_Pos)                                       /*!< CPUSEL12 Mask      0x00001000 */
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL12_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL12_Pos) & DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL12_Msk) /*!< CPUSEL12 Set Value            */
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL12_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL12_Msk) >> DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL12_Pos) /*!< CPUSEL12 Get Value            */


#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL11_Pos    (11U)                                                                                 /*!< CPUSEL11 Postion   11         */ 
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL11_Msk    (0x1U << DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL11_Pos)                                       /*!< CPUSEL11 Mask      0x00000800 */
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL11_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL11_Pos) & DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL11_Msk) /*!< CPUSEL11 Set Value            */
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL11_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL11_Msk) >> DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL11_Pos) /*!< CPUSEL11 Get Value            */


#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL8_Pos    (8U)                                                                                  /*!< CPUSEL8 Postion   8          */ 
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL8_Msk    (0x1U << DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL8_Pos)                                        /*!< CPUSEL8 Mask      0x00000100 */
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL8_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL8_Pos) & DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL8_Msk) /*!< CPUSEL8 Set Value            */
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL8_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL8_Msk) >> DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL8_Pos) /*!< CPUSEL8 Get Value            */


#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL7_Pos    (7U)                                                                                  /*!< CPUSEL7 Postion   7          */ 
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL7_Msk    (0x1U << DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL7_Pos)                                        /*!< CPUSEL7 Mask      0x00000080 */
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL7_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL7_Pos) & DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL7_Msk) /*!< CPUSEL7 Set Value            */
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL7_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL7_Msk) >> DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL7_Pos) /*!< CPUSEL7 Get Value            */


#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL6_Pos    (6U)                                                                                  /*!< CPUSEL6 Postion   6          */ 
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL6_Msk    (0x1U << DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL6_Pos)                                        /*!< CPUSEL6 Mask      0x00000040 */
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL6_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL6_Pos) & DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL6_Msk) /*!< CPUSEL6 Set Value            */
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL6_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL6_Msk) >> DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL6_Pos) /*!< CPUSEL6 Get Value            */


#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL5_Pos    (5U)                                                                                  /*!< CPUSEL5 Postion   5          */ 
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL5_Msk    (0x1U << DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL5_Pos)                                        /*!< CPUSEL5 Mask      0x00000020 */
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL5_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL5_Pos) & DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL5_Msk) /*!< CPUSEL5 Set Value            */
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL5_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL5_Msk) >> DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL5_Pos) /*!< CPUSEL5 Get Value            */


#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL4_Pos    (4U)                                                                                  /*!< CPUSEL4 Postion   4          */ 
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL4_Msk    (0x1U << DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL4_Pos)                                        /*!< CPUSEL4 Mask      0x00000010 */
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL4_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL4_Pos) & DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL4_Msk) /*!< CPUSEL4 Set Value            */
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL4_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL4_Msk) >> DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL4_Pos) /*!< CPUSEL4 Get Value            */


#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL2_Pos    (2U)                                                                                  /*!< CPUSEL2 Postion   2          */ 
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL2_Msk    (0x1U << DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL2_Pos)                                        /*!< CPUSEL2 Mask      0x00000004 */
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL2_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL2_Pos) & DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL2_Msk) /*!< CPUSEL2 Set Value            */
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL2_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL2_Msk) >> DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL2_Pos) /*!< CPUSEL2 Get Value            */


#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL1_Pos    (1U)                                                                                  /*!< CPUSEL1 Postion   1          */ 
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL1_Msk    (0x1U << DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL1_Pos)                                        /*!< CPUSEL1 Mask      0x00000002 */
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL1_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL1_Pos) & DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL1_Msk) /*!< CPUSEL1 Set Value            */
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL1_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL1_Msk) >> DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL1_Pos) /*!< CPUSEL1 Get Value            */


#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL0_Pos    (0U)                                                                                  /*!< CPUSEL0 Postion   0          */ 
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL0_Msk    (0x1U << DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL0_Pos)                                        /*!< CPUSEL0 Mask      0x00000001 */
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL0_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL0_Pos) & DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL0_Msk) /*!< CPUSEL0 Set Value            */
#define DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL0_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL0_Msk) >> DEV_CFG_REGS_DEVCFGLOCK1_CPUSEL0_Pos) /*!< CPUSEL0 Get Value            */


/* PARTIDL bitfield */
#define DEV_CFG_REGS_PARTIDL_PARTID_FORMAT_REVISION_Pos    (28U)                                                                                 /*!< PARTID_FORMAT_REVISION Postion   28         */ 
#define DEV_CFG_REGS_PARTIDL_PARTID_FORMAT_REVISION_Msk    (0xfU << DEV_CFG_REGS_PARTIDL_PARTID_FORMAT_REVISION_Pos)                             /*!< PARTID_FORMAT_REVISION Mask      0xF0000000 */
#define DEV_CFG_REGS_PARTIDL_PARTID_FORMAT_REVISION_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_PARTIDL_PARTID_FORMAT_REVISION_Pos) & DEV_CFG_REGS_PARTIDL_PARTID_FORMAT_REVISION_Msk) /*!< PARTID_FORMAT_REVISION Set Value            */
#define DEV_CFG_REGS_PARTIDL_PARTID_FORMAT_REVISION_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_PARTIDL_PARTID_FORMAT_REVISION_Msk) >> DEV_CFG_REGS_PARTIDL_PARTID_FORMAT_REVISION_Pos) /*!< PARTID_FORMAT_REVISION Get Value            */


#define DEV_CFG_REGS_PARTIDL_FLASH_SIZE_Pos    (16U)                                                                                 /*!< FLASH_SIZE Postion   16         */ 
#define DEV_CFG_REGS_PARTIDL_FLASH_SIZE_Msk    (0xffU << DEV_CFG_REGS_PARTIDL_FLASH_SIZE_Pos)                                        /*!< FLASH_SIZE Mask      0x00FF0000 */
#define DEV_CFG_REGS_PARTIDL_FLASH_SIZE_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_PARTIDL_FLASH_SIZE_Pos) & DEV_CFG_REGS_PARTIDL_FLASH_SIZE_Msk) /*!< FLASH_SIZE Set Value            */
#define DEV_CFG_REGS_PARTIDL_FLASH_SIZE_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_PARTIDL_FLASH_SIZE_Msk) >> DEV_CFG_REGS_PARTIDL_FLASH_SIZE_Pos) /*!< FLASH_SIZE Get Value            */


#define DEV_CFG_REGS_PARTIDL_PIN_COUNT_Pos    (8U)                                                                                  /*!< PIN_COUNT Postion   8          */ 
#define DEV_CFG_REGS_PARTIDL_PIN_COUNT_Msk    (0x7U << DEV_CFG_REGS_PARTIDL_PIN_COUNT_Pos)                                          /*!< PIN_COUNT Mask      0x00000700 */
#define DEV_CFG_REGS_PARTIDL_PIN_COUNT_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_PARTIDL_PIN_COUNT_Pos) & DEV_CFG_REGS_PARTIDL_PIN_COUNT_Msk) /*!< PIN_COUNT Set Value            */
#define DEV_CFG_REGS_PARTIDL_PIN_COUNT_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_PARTIDL_PIN_COUNT_Msk) >> DEV_CFG_REGS_PARTIDL_PIN_COUNT_Pos) /*!< PIN_COUNT Get Value            */


/* PARTIDH bitfield */
#define DEV_CFG_REGS_PARTIDH_DEVICE_CLASS_ID_Pos    (24U)                                                                                 /*!< DEVICE_CLASS_ID Postion   24         */ 
#define DEV_CFG_REGS_PARTIDH_DEVICE_CLASS_ID_Msk    (0xffU << DEV_CFG_REGS_PARTIDH_DEVICE_CLASS_ID_Pos)                                   /*!< DEVICE_CLASS_ID Mask      0xFF000000 */
#define DEV_CFG_REGS_PARTIDH_DEVICE_CLASS_ID_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_PARTIDH_DEVICE_CLASS_ID_Pos) & DEV_CFG_REGS_PARTIDH_DEVICE_CLASS_ID_Msk) /*!< DEVICE_CLASS_ID Set Value            */
#define DEV_CFG_REGS_PARTIDH_DEVICE_CLASS_ID_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_PARTIDH_DEVICE_CLASS_ID_Msk) >> DEV_CFG_REGS_PARTIDH_DEVICE_CLASS_ID_Pos) /*!< DEVICE_CLASS_ID Get Value            */


#define DEV_CFG_REGS_PARTIDH_PARTNO_Pos    (16U)                                                                                 /*!< PARTNO Postion   16         */ 
#define DEV_CFG_REGS_PARTIDH_PARTNO_Msk    (0xffU << DEV_CFG_REGS_PARTIDH_PARTNO_Pos)                                            /*!< PARTNO Mask      0x00FF0000 */
#define DEV_CFG_REGS_PARTIDH_PARTNO_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_PARTIDH_PARTNO_Pos) & DEV_CFG_REGS_PARTIDH_PARTNO_Msk) /*!< PARTNO Set Value            */
#define DEV_CFG_REGS_PARTIDH_PARTNO_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_PARTIDH_PARTNO_Msk) >> DEV_CFG_REGS_PARTIDH_PARTNO_Pos) /*!< PARTNO Get Value            */


#define DEV_CFG_REGS_PARTIDH_FAMILY_Pos    (8U)                                                                                  /*!< FAMILY Postion   8          */ 
#define DEV_CFG_REGS_PARTIDH_FAMILY_Msk    (0xffU << DEV_CFG_REGS_PARTIDH_FAMILY_Pos)                                            /*!< FAMILY Mask      0x0000FF00 */
#define DEV_CFG_REGS_PARTIDH_FAMILY_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_PARTIDH_FAMILY_Pos) & DEV_CFG_REGS_PARTIDH_FAMILY_Msk) /*!< FAMILY Set Value            */
#define DEV_CFG_REGS_PARTIDH_FAMILY_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_PARTIDH_FAMILY_Msk) >> DEV_CFG_REGS_PARTIDH_FAMILY_Pos) /*!< FAMILY Get Value            */


/* REVID bitfield */
#define DEV_CFG_REGS_REVID_REVID_Pos    (0U)                                                                                  /*!< REVID Postion   0          */ 
#define DEV_CFG_REGS_REVID_REVID_Msk    (0xffffffffU << DEV_CFG_REGS_REVID_REVID_Pos)                                         /*!< REVID Mask      0xFFFFFFFF */
#define DEV_CFG_REGS_REVID_REVID_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_REVID_REVID_Pos) & DEV_CFG_REGS_REVID_REVID_Msk)     /*!< REVID Set Value            */
#define DEV_CFG_REGS_REVID_REVID_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_REVID_REVID_Msk) >> DEV_CFG_REGS_REVID_REVID_Pos)     /*!< REVID Get Value            */


/* DC0 bitfield */
#define DEV_CFG_REGS_DC0_SINGLE_CORE_Pos    (0U)                                                                                  /*!< SINGLE_CORE Postion   0          */ 
#define DEV_CFG_REGS_DC0_SINGLE_CORE_Msk    (0x1U << DEV_CFG_REGS_DC0_SINGLE_CORE_Pos)                                            /*!< SINGLE_CORE Mask      0x00000001 */
#define DEV_CFG_REGS_DC0_SINGLE_CORE_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC0_SINGLE_CORE_Pos) & DEV_CFG_REGS_DC0_SINGLE_CORE_Msk) /*!< SINGLE_CORE Set Value            */
#define DEV_CFG_REGS_DC0_SINGLE_CORE_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC0_SINGLE_CORE_Msk) >> DEV_CFG_REGS_DC0_SINGLE_CORE_Pos) /*!< SINGLE_CORE Get Value            */


/* DC1 bitfield */
#define DEV_CFG_REGS_DC1_CRC_Pos    (8U)                                                                                  /*!< CRC Postion   8          */ 
#define DEV_CFG_REGS_DC1_CRC_Msk    (0x1U << DEV_CFG_REGS_DC1_CRC_Pos)                                                    /*!< CRC Mask      0x00000100 */
#define DEV_CFG_REGS_DC1_CRC_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC1_CRC_Pos) & DEV_CFG_REGS_DC1_CRC_Msk)             /*!< CRC Set Value            */
#define DEV_CFG_REGS_DC1_CRC_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC1_CRC_Msk) >> DEV_CFG_REGS_DC1_CRC_Pos)             /*!< CRC Get Value            */


#define DEV_CFG_REGS_DC1_TFU_Pos    (0U)                                                                                  /*!< TFU Postion   0          */ 
#define DEV_CFG_REGS_DC1_TFU_Msk    (0x1U << DEV_CFG_REGS_DC1_TFU_Pos)                                                    /*!< TFU Mask      0x00000001 */
#define DEV_CFG_REGS_DC1_TFU_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC1_TFU_Pos) & DEV_CFG_REGS_DC1_TFU_Msk)             /*!< TFU Set Value            */
#define DEV_CFG_REGS_DC1_TFU_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC1_TFU_Msk) >> DEV_CFG_REGS_DC1_TFU_Pos)             /*!< TFU Get Value            */


/* DC2 bitfield */
#define DEV_CFG_REGS_DC2_EMIF2_Pos    (1U)                                                                                  /*!< EMIF2 Postion   1          */ 
#define DEV_CFG_REGS_DC2_EMIF2_Msk    (0x1U << DEV_CFG_REGS_DC2_EMIF2_Pos)                                                  /*!< EMIF2 Mask      0x00000002 */
#define DEV_CFG_REGS_DC2_EMIF2_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC2_EMIF2_Pos) & DEV_CFG_REGS_DC2_EMIF2_Msk)         /*!< EMIF2 Set Value            */
#define DEV_CFG_REGS_DC2_EMIF2_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC2_EMIF2_Msk) >> DEV_CFG_REGS_DC2_EMIF2_Pos)         /*!< EMIF2 Get Value            */


#define DEV_CFG_REGS_DC2_EMIF1_Pos    (0U)                                                                                  /*!< EMIF1 Postion   0          */ 
#define DEV_CFG_REGS_DC2_EMIF1_Msk    (0x1U << DEV_CFG_REGS_DC2_EMIF1_Pos)                                                  /*!< EMIF1 Mask      0x00000001 */
#define DEV_CFG_REGS_DC2_EMIF1_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC2_EMIF1_Pos) & DEV_CFG_REGS_DC2_EMIF1_Msk)         /*!< EMIF1 Set Value            */
#define DEV_CFG_REGS_DC2_EMIF1_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC2_EMIF1_Msk) >> DEV_CFG_REGS_DC2_EMIF1_Pos)         /*!< EMIF1 Get Value            */


/* DC3 bitfield */
#define DEV_CFG_REGS_DC3_EPWM12_Pos    (11U)                                                                                 /*!< EPWM12 Postion   11         */ 
#define DEV_CFG_REGS_DC3_EPWM12_Msk    (0x1U << DEV_CFG_REGS_DC3_EPWM12_Pos)                                                 /*!< EPWM12 Mask      0x00000800 */
#define DEV_CFG_REGS_DC3_EPWM12_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC3_EPWM12_Pos) & DEV_CFG_REGS_DC3_EPWM12_Msk)       /*!< EPWM12 Set Value            */
#define DEV_CFG_REGS_DC3_EPWM12_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC3_EPWM12_Msk) >> DEV_CFG_REGS_DC3_EPWM12_Pos)       /*!< EPWM12 Get Value            */


#define DEV_CFG_REGS_DC3_EPWM11_Pos    (10U)                                                                                 /*!< EPWM11 Postion   10         */ 
#define DEV_CFG_REGS_DC3_EPWM11_Msk    (0x1U << DEV_CFG_REGS_DC3_EPWM11_Pos)                                                 /*!< EPWM11 Mask      0x00000400 */
#define DEV_CFG_REGS_DC3_EPWM11_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC3_EPWM11_Pos) & DEV_CFG_REGS_DC3_EPWM11_Msk)       /*!< EPWM11 Set Value            */
#define DEV_CFG_REGS_DC3_EPWM11_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC3_EPWM11_Msk) >> DEV_CFG_REGS_DC3_EPWM11_Pos)       /*!< EPWM11 Get Value            */


#define DEV_CFG_REGS_DC3_EPWM10_Pos    (9U)                                                                                  /*!< EPWM10 Postion   9          */ 
#define DEV_CFG_REGS_DC3_EPWM10_Msk    (0x1U << DEV_CFG_REGS_DC3_EPWM10_Pos)                                                 /*!< EPWM10 Mask      0x00000200 */
#define DEV_CFG_REGS_DC3_EPWM10_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC3_EPWM10_Pos) & DEV_CFG_REGS_DC3_EPWM10_Msk)       /*!< EPWM10 Set Value            */
#define DEV_CFG_REGS_DC3_EPWM10_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC3_EPWM10_Msk) >> DEV_CFG_REGS_DC3_EPWM10_Pos)       /*!< EPWM10 Get Value            */


#define DEV_CFG_REGS_DC3_EPWM9_Pos    (8U)                                                                                  /*!< EPWM9 Postion   8          */ 
#define DEV_CFG_REGS_DC3_EPWM9_Msk    (0x1U << DEV_CFG_REGS_DC3_EPWM9_Pos)                                                  /*!< EPWM9 Mask      0x00000100 */
#define DEV_CFG_REGS_DC3_EPWM9_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC3_EPWM9_Pos) & DEV_CFG_REGS_DC3_EPWM9_Msk)         /*!< EPWM9 Set Value            */
#define DEV_CFG_REGS_DC3_EPWM9_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC3_EPWM9_Msk) >> DEV_CFG_REGS_DC3_EPWM9_Pos)         /*!< EPWM9 Get Value            */


#define DEV_CFG_REGS_DC3_EPWM8_Pos    (7U)                                                                                  /*!< EPWM8 Postion   7          */ 
#define DEV_CFG_REGS_DC3_EPWM8_Msk    (0x1U << DEV_CFG_REGS_DC3_EPWM8_Pos)                                                  /*!< EPWM8 Mask      0x00000080 */
#define DEV_CFG_REGS_DC3_EPWM8_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC3_EPWM8_Pos) & DEV_CFG_REGS_DC3_EPWM8_Msk)         /*!< EPWM8 Set Value            */
#define DEV_CFG_REGS_DC3_EPWM8_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC3_EPWM8_Msk) >> DEV_CFG_REGS_DC3_EPWM8_Pos)         /*!< EPWM8 Get Value            */


#define DEV_CFG_REGS_DC3_EPWM7_Pos    (6U)                                                                                  /*!< EPWM7 Postion   6          */ 
#define DEV_CFG_REGS_DC3_EPWM7_Msk    (0x1U << DEV_CFG_REGS_DC3_EPWM7_Pos)                                                  /*!< EPWM7 Mask      0x00000040 */
#define DEV_CFG_REGS_DC3_EPWM7_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC3_EPWM7_Pos) & DEV_CFG_REGS_DC3_EPWM7_Msk)         /*!< EPWM7 Set Value            */
#define DEV_CFG_REGS_DC3_EPWM7_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC3_EPWM7_Msk) >> DEV_CFG_REGS_DC3_EPWM7_Pos)         /*!< EPWM7 Get Value            */


#define DEV_CFG_REGS_DC3_EPWM6_Pos    (5U)                                                                                  /*!< EPWM6 Postion   5          */ 
#define DEV_CFG_REGS_DC3_EPWM6_Msk    (0x1U << DEV_CFG_REGS_DC3_EPWM6_Pos)                                                  /*!< EPWM6 Mask      0x00000020 */
#define DEV_CFG_REGS_DC3_EPWM6_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC3_EPWM6_Pos) & DEV_CFG_REGS_DC3_EPWM6_Msk)         /*!< EPWM6 Set Value            */
#define DEV_CFG_REGS_DC3_EPWM6_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC3_EPWM6_Msk) >> DEV_CFG_REGS_DC3_EPWM6_Pos)         /*!< EPWM6 Get Value            */


#define DEV_CFG_REGS_DC3_EPWM5_Pos    (4U)                                                                                  /*!< EPWM5 Postion   4          */ 
#define DEV_CFG_REGS_DC3_EPWM5_Msk    (0x1U << DEV_CFG_REGS_DC3_EPWM5_Pos)                                                  /*!< EPWM5 Mask      0x00000010 */
#define DEV_CFG_REGS_DC3_EPWM5_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC3_EPWM5_Pos) & DEV_CFG_REGS_DC3_EPWM5_Msk)         /*!< EPWM5 Set Value            */
#define DEV_CFG_REGS_DC3_EPWM5_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC3_EPWM5_Msk) >> DEV_CFG_REGS_DC3_EPWM5_Pos)         /*!< EPWM5 Get Value            */


#define DEV_CFG_REGS_DC3_EPWM4_Pos    (3U)                                                                                  /*!< EPWM4 Postion   3          */ 
#define DEV_CFG_REGS_DC3_EPWM4_Msk    (0x1U << DEV_CFG_REGS_DC3_EPWM4_Pos)                                                  /*!< EPWM4 Mask      0x00000008 */
#define DEV_CFG_REGS_DC3_EPWM4_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC3_EPWM4_Pos) & DEV_CFG_REGS_DC3_EPWM4_Msk)         /*!< EPWM4 Set Value            */
#define DEV_CFG_REGS_DC3_EPWM4_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC3_EPWM4_Msk) >> DEV_CFG_REGS_DC3_EPWM4_Pos)         /*!< EPWM4 Get Value            */


#define DEV_CFG_REGS_DC3_EPWM3_Pos    (2U)                                                                                  /*!< EPWM3 Postion   2          */ 
#define DEV_CFG_REGS_DC3_EPWM3_Msk    (0x1U << DEV_CFG_REGS_DC3_EPWM3_Pos)                                                  /*!< EPWM3 Mask      0x00000004 */
#define DEV_CFG_REGS_DC3_EPWM3_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC3_EPWM3_Pos) & DEV_CFG_REGS_DC3_EPWM3_Msk)         /*!< EPWM3 Set Value            */
#define DEV_CFG_REGS_DC3_EPWM3_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC3_EPWM3_Msk) >> DEV_CFG_REGS_DC3_EPWM3_Pos)         /*!< EPWM3 Get Value            */


#define DEV_CFG_REGS_DC3_EPWM2_Pos    (1U)                                                                                  /*!< EPWM2 Postion   1          */ 
#define DEV_CFG_REGS_DC3_EPWM2_Msk    (0x1U << DEV_CFG_REGS_DC3_EPWM2_Pos)                                                  /*!< EPWM2 Mask      0x00000002 */
#define DEV_CFG_REGS_DC3_EPWM2_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC3_EPWM2_Pos) & DEV_CFG_REGS_DC3_EPWM2_Msk)         /*!< EPWM2 Set Value            */
#define DEV_CFG_REGS_DC3_EPWM2_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC3_EPWM2_Msk) >> DEV_CFG_REGS_DC3_EPWM2_Pos)         /*!< EPWM2 Get Value            */


#define DEV_CFG_REGS_DC3_EPWM1_Pos    (0U)                                                                                  /*!< EPWM1 Postion   0          */ 
#define DEV_CFG_REGS_DC3_EPWM1_Msk    (0x1U << DEV_CFG_REGS_DC3_EPWM1_Pos)                                                  /*!< EPWM1 Mask      0x00000001 */
#define DEV_CFG_REGS_DC3_EPWM1_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC3_EPWM1_Pos) & DEV_CFG_REGS_DC3_EPWM1_Msk)         /*!< EPWM1 Set Value            */
#define DEV_CFG_REGS_DC3_EPWM1_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC3_EPWM1_Msk) >> DEV_CFG_REGS_DC3_EPWM1_Pos)         /*!< EPWM1 Get Value            */


/* DC4 bitfield */
#define DEV_CFG_REGS_DC4_ECAP6_Pos    (5U)                                                                                  /*!< ECAP6 Postion   5          */ 
#define DEV_CFG_REGS_DC4_ECAP6_Msk    (0x1U << DEV_CFG_REGS_DC4_ECAP6_Pos)                                                  /*!< ECAP6 Mask      0x00000020 */
#define DEV_CFG_REGS_DC4_ECAP6_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC4_ECAP6_Pos) & DEV_CFG_REGS_DC4_ECAP6_Msk)         /*!< ECAP6 Set Value            */
#define DEV_CFG_REGS_DC4_ECAP6_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC4_ECAP6_Msk) >> DEV_CFG_REGS_DC4_ECAP6_Pos)         /*!< ECAP6 Get Value            */


#define DEV_CFG_REGS_DC4_ECAP5_Pos    (4U)                                                                                  /*!< ECAP5 Postion   4          */ 
#define DEV_CFG_REGS_DC4_ECAP5_Msk    (0x1U << DEV_CFG_REGS_DC4_ECAP5_Pos)                                                  /*!< ECAP5 Mask      0x00000010 */
#define DEV_CFG_REGS_DC4_ECAP5_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC4_ECAP5_Pos) & DEV_CFG_REGS_DC4_ECAP5_Msk)         /*!< ECAP5 Set Value            */
#define DEV_CFG_REGS_DC4_ECAP5_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC4_ECAP5_Msk) >> DEV_CFG_REGS_DC4_ECAP5_Pos)         /*!< ECAP5 Get Value            */


#define DEV_CFG_REGS_DC4_ECAP4_Pos    (3U)                                                                                  /*!< ECAP4 Postion   3          */ 
#define DEV_CFG_REGS_DC4_ECAP4_Msk    (0x1U << DEV_CFG_REGS_DC4_ECAP4_Pos)                                                  /*!< ECAP4 Mask      0x00000008 */
#define DEV_CFG_REGS_DC4_ECAP4_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC4_ECAP4_Pos) & DEV_CFG_REGS_DC4_ECAP4_Msk)         /*!< ECAP4 Set Value            */
#define DEV_CFG_REGS_DC4_ECAP4_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC4_ECAP4_Msk) >> DEV_CFG_REGS_DC4_ECAP4_Pos)         /*!< ECAP4 Get Value            */


#define DEV_CFG_REGS_DC4_ECAP3_Pos    (2U)                                                                                  /*!< ECAP3 Postion   2          */ 
#define DEV_CFG_REGS_DC4_ECAP3_Msk    (0x1U << DEV_CFG_REGS_DC4_ECAP3_Pos)                                                  /*!< ECAP3 Mask      0x00000004 */
#define DEV_CFG_REGS_DC4_ECAP3_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC4_ECAP3_Pos) & DEV_CFG_REGS_DC4_ECAP3_Msk)         /*!< ECAP3 Set Value            */
#define DEV_CFG_REGS_DC4_ECAP3_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC4_ECAP3_Msk) >> DEV_CFG_REGS_DC4_ECAP3_Pos)         /*!< ECAP3 Get Value            */


#define DEV_CFG_REGS_DC4_ECAP2_Pos    (1U)                                                                                  /*!< ECAP2 Postion   1          */ 
#define DEV_CFG_REGS_DC4_ECAP2_Msk    (0x1U << DEV_CFG_REGS_DC4_ECAP2_Pos)                                                  /*!< ECAP2 Mask      0x00000002 */
#define DEV_CFG_REGS_DC4_ECAP2_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC4_ECAP2_Pos) & DEV_CFG_REGS_DC4_ECAP2_Msk)         /*!< ECAP2 Set Value            */
#define DEV_CFG_REGS_DC4_ECAP2_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC4_ECAP2_Msk) >> DEV_CFG_REGS_DC4_ECAP2_Pos)         /*!< ECAP2 Get Value            */


#define DEV_CFG_REGS_DC4_ECAP1_Pos    (0U)                                                                                  /*!< ECAP1 Postion   0          */ 
#define DEV_CFG_REGS_DC4_ECAP1_Msk    (0x1U << DEV_CFG_REGS_DC4_ECAP1_Pos)                                                  /*!< ECAP1 Mask      0x00000001 */
#define DEV_CFG_REGS_DC4_ECAP1_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC4_ECAP1_Pos) & DEV_CFG_REGS_DC4_ECAP1_Msk)         /*!< ECAP1 Set Value            */
#define DEV_CFG_REGS_DC4_ECAP1_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC4_ECAP1_Msk) >> DEV_CFG_REGS_DC4_ECAP1_Pos)         /*!< ECAP1 Get Value            */


/* DC5 bitfield */
#define DEV_CFG_REGS_DC5_EQEP3_Pos    (2U)                                                                                  /*!< EQEP3 Postion   2          */ 
#define DEV_CFG_REGS_DC5_EQEP3_Msk    (0x1U << DEV_CFG_REGS_DC5_EQEP3_Pos)                                                  /*!< EQEP3 Mask      0x00000004 */
#define DEV_CFG_REGS_DC5_EQEP3_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC5_EQEP3_Pos) & DEV_CFG_REGS_DC5_EQEP3_Msk)         /*!< EQEP3 Set Value            */
#define DEV_CFG_REGS_DC5_EQEP3_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC5_EQEP3_Msk) >> DEV_CFG_REGS_DC5_EQEP3_Pos)         /*!< EQEP3 Get Value            */


#define DEV_CFG_REGS_DC5_EQEP2_Pos    (1U)                                                                                  /*!< EQEP2 Postion   1          */ 
#define DEV_CFG_REGS_DC5_EQEP2_Msk    (0x1U << DEV_CFG_REGS_DC5_EQEP2_Pos)                                                  /*!< EQEP2 Mask      0x00000002 */
#define DEV_CFG_REGS_DC5_EQEP2_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC5_EQEP2_Pos) & DEV_CFG_REGS_DC5_EQEP2_Msk)         /*!< EQEP2 Set Value            */
#define DEV_CFG_REGS_DC5_EQEP2_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC5_EQEP2_Msk) >> DEV_CFG_REGS_DC5_EQEP2_Pos)         /*!< EQEP2 Get Value            */


#define DEV_CFG_REGS_DC5_EQEP1_Pos    (0U)                                                                                  /*!< EQEP1 Postion   0          */ 
#define DEV_CFG_REGS_DC5_EQEP1_Msk    (0x1U << DEV_CFG_REGS_DC5_EQEP1_Pos)                                                  /*!< EQEP1 Mask      0x00000001 */
#define DEV_CFG_REGS_DC5_EQEP1_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC5_EQEP1_Pos) & DEV_CFG_REGS_DC5_EQEP1_Msk)         /*!< EQEP1 Set Value            */
#define DEV_CFG_REGS_DC5_EQEP1_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC5_EQEP1_Msk) >> DEV_CFG_REGS_DC5_EQEP1_Pos)         /*!< EQEP1 Get Value            */


/* DC6 bitfield */
#define DEV_CFG_REGS_DC6_CLB8_Pos    (7U)                                                                                  /*!< CLB8 Postion   7          */ 
#define DEV_CFG_REGS_DC6_CLB8_Msk    (0x1U << DEV_CFG_REGS_DC6_CLB8_Pos)                                                   /*!< CLB8 Mask      0x00000080 */
#define DEV_CFG_REGS_DC6_CLB8_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC6_CLB8_Pos) & DEV_CFG_REGS_DC6_CLB8_Msk)           /*!< CLB8 Set Value            */
#define DEV_CFG_REGS_DC6_CLB8_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC6_CLB8_Msk) >> DEV_CFG_REGS_DC6_CLB8_Pos)           /*!< CLB8 Get Value            */


#define DEV_CFG_REGS_DC6_CLB7_Pos    (6U)                                                                                  /*!< CLB7 Postion   6          */ 
#define DEV_CFG_REGS_DC6_CLB7_Msk    (0x1U << DEV_CFG_REGS_DC6_CLB7_Pos)                                                   /*!< CLB7 Mask      0x00000040 */
#define DEV_CFG_REGS_DC6_CLB7_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC6_CLB7_Pos) & DEV_CFG_REGS_DC6_CLB7_Msk)           /*!< CLB7 Set Value            */
#define DEV_CFG_REGS_DC6_CLB7_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC6_CLB7_Msk) >> DEV_CFG_REGS_DC6_CLB7_Pos)           /*!< CLB7 Get Value            */


#define DEV_CFG_REGS_DC6_CLB6_Pos    (5U)                                                                                  /*!< CLB6 Postion   5          */ 
#define DEV_CFG_REGS_DC6_CLB6_Msk    (0x1U << DEV_CFG_REGS_DC6_CLB6_Pos)                                                   /*!< CLB6 Mask      0x00000020 */
#define DEV_CFG_REGS_DC6_CLB6_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC6_CLB6_Pos) & DEV_CFG_REGS_DC6_CLB6_Msk)           /*!< CLB6 Set Value            */
#define DEV_CFG_REGS_DC6_CLB6_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC6_CLB6_Msk) >> DEV_CFG_REGS_DC6_CLB6_Pos)           /*!< CLB6 Get Value            */


#define DEV_CFG_REGS_DC6_CLB5_Pos    (4U)                                                                                  /*!< CLB5 Postion   4          */ 
#define DEV_CFG_REGS_DC6_CLB5_Msk    (0x1U << DEV_CFG_REGS_DC6_CLB5_Pos)                                                   /*!< CLB5 Mask      0x00000010 */
#define DEV_CFG_REGS_DC6_CLB5_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC6_CLB5_Pos) & DEV_CFG_REGS_DC6_CLB5_Msk)           /*!< CLB5 Set Value            */
#define DEV_CFG_REGS_DC6_CLB5_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC6_CLB5_Msk) >> DEV_CFG_REGS_DC6_CLB5_Pos)           /*!< CLB5 Get Value            */


#define DEV_CFG_REGS_DC6_CLB4_Pos    (3U)                                                                                  /*!< CLB4 Postion   3          */ 
#define DEV_CFG_REGS_DC6_CLB4_Msk    (0x1U << DEV_CFG_REGS_DC6_CLB4_Pos)                                                   /*!< CLB4 Mask      0x00000008 */
#define DEV_CFG_REGS_DC6_CLB4_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC6_CLB4_Pos) & DEV_CFG_REGS_DC6_CLB4_Msk)           /*!< CLB4 Set Value            */
#define DEV_CFG_REGS_DC6_CLB4_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC6_CLB4_Msk) >> DEV_CFG_REGS_DC6_CLB4_Pos)           /*!< CLB4 Get Value            */


#define DEV_CFG_REGS_DC6_CLB3_Pos    (2U)                                                                                  /*!< CLB3 Postion   2          */ 
#define DEV_CFG_REGS_DC6_CLB3_Msk    (0x1U << DEV_CFG_REGS_DC6_CLB3_Pos)                                                   /*!< CLB3 Mask      0x00000004 */
#define DEV_CFG_REGS_DC6_CLB3_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC6_CLB3_Pos) & DEV_CFG_REGS_DC6_CLB3_Msk)           /*!< CLB3 Set Value            */
#define DEV_CFG_REGS_DC6_CLB3_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC6_CLB3_Msk) >> DEV_CFG_REGS_DC6_CLB3_Pos)           /*!< CLB3 Get Value            */


#define DEV_CFG_REGS_DC6_CLB2_Pos    (1U)                                                                                  /*!< CLB2 Postion   1          */ 
#define DEV_CFG_REGS_DC6_CLB2_Msk    (0x1U << DEV_CFG_REGS_DC6_CLB2_Pos)                                                   /*!< CLB2 Mask      0x00000002 */
#define DEV_CFG_REGS_DC6_CLB2_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC6_CLB2_Pos) & DEV_CFG_REGS_DC6_CLB2_Msk)           /*!< CLB2 Set Value            */
#define DEV_CFG_REGS_DC6_CLB2_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC6_CLB2_Msk) >> DEV_CFG_REGS_DC6_CLB2_Pos)           /*!< CLB2 Get Value            */


#define DEV_CFG_REGS_DC6_CLB1_Pos    (0U)                                                                                  /*!< CLB1 Postion   0          */ 
#define DEV_CFG_REGS_DC6_CLB1_Msk    (0x1U << DEV_CFG_REGS_DC6_CLB1_Pos)                                                   /*!< CLB1 Mask      0x00000001 */
#define DEV_CFG_REGS_DC6_CLB1_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC6_CLB1_Pos) & DEV_CFG_REGS_DC6_CLB1_Msk)           /*!< CLB1 Set Value            */
#define DEV_CFG_REGS_DC6_CLB1_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC6_CLB1_Msk) >> DEV_CFG_REGS_DC6_CLB1_Pos)           /*!< CLB1 Get Value            */


/* DC7 bitfield */
#define DEV_CFG_REGS_DC7_SD2_Pos    (1U)                                                                                  /*!< SD2 Postion   1          */ 
#define DEV_CFG_REGS_DC7_SD2_Msk    (0x1U << DEV_CFG_REGS_DC7_SD2_Pos)                                                    /*!< SD2 Mask      0x00000002 */
#define DEV_CFG_REGS_DC7_SD2_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC7_SD2_Pos) & DEV_CFG_REGS_DC7_SD2_Msk)             /*!< SD2 Set Value            */
#define DEV_CFG_REGS_DC7_SD2_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC7_SD2_Msk) >> DEV_CFG_REGS_DC7_SD2_Pos)             /*!< SD2 Get Value            */


#define DEV_CFG_REGS_DC7_SD1_Pos    (0U)                                                                                  /*!< SD1 Postion   0          */ 
#define DEV_CFG_REGS_DC7_SD1_Msk    (0x1U << DEV_CFG_REGS_DC7_SD1_Pos)                                                    /*!< SD1 Mask      0x00000001 */
#define DEV_CFG_REGS_DC7_SD1_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC7_SD1_Pos) & DEV_CFG_REGS_DC7_SD1_Msk)             /*!< SD1 Set Value            */
#define DEV_CFG_REGS_DC7_SD1_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC7_SD1_Msk) >> DEV_CFG_REGS_DC7_SD1_Pos)             /*!< SD1 Get Value            */


/* DC8 bitfield */
#define DEV_CFG_REGS_DC8_SCI_D_Pos    (3U)                                                                                  /*!< SCI_D Postion   3          */ 
#define DEV_CFG_REGS_DC8_SCI_D_Msk    (0x1U << DEV_CFG_REGS_DC8_SCI_D_Pos)                                                  /*!< SCI_D Mask      0x00000008 */
#define DEV_CFG_REGS_DC8_SCI_D_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC8_SCI_D_Pos) & DEV_CFG_REGS_DC8_SCI_D_Msk)         /*!< SCI_D Set Value            */
#define DEV_CFG_REGS_DC8_SCI_D_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC8_SCI_D_Msk) >> DEV_CFG_REGS_DC8_SCI_D_Pos)         /*!< SCI_D Get Value            */


#define DEV_CFG_REGS_DC8_SCI_C_Pos    (2U)                                                                                  /*!< SCI_C Postion   2          */ 
#define DEV_CFG_REGS_DC8_SCI_C_Msk    (0x1U << DEV_CFG_REGS_DC8_SCI_C_Pos)                                                  /*!< SCI_C Mask      0x00000004 */
#define DEV_CFG_REGS_DC8_SCI_C_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC8_SCI_C_Pos) & DEV_CFG_REGS_DC8_SCI_C_Msk)         /*!< SCI_C Set Value            */
#define DEV_CFG_REGS_DC8_SCI_C_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC8_SCI_C_Msk) >> DEV_CFG_REGS_DC8_SCI_C_Pos)         /*!< SCI_C Get Value            */


#define DEV_CFG_REGS_DC8_SCI_B_Pos    (1U)                                                                                  /*!< SCI_B Postion   1          */ 
#define DEV_CFG_REGS_DC8_SCI_B_Msk    (0x1U << DEV_CFG_REGS_DC8_SCI_B_Pos)                                                  /*!< SCI_B Mask      0x00000002 */
#define DEV_CFG_REGS_DC8_SCI_B_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC8_SCI_B_Pos) & DEV_CFG_REGS_DC8_SCI_B_Msk)         /*!< SCI_B Set Value            */
#define DEV_CFG_REGS_DC8_SCI_B_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC8_SCI_B_Msk) >> DEV_CFG_REGS_DC8_SCI_B_Pos)         /*!< SCI_B Get Value            */


#define DEV_CFG_REGS_DC8_SCI_A_Pos    (0U)                                                                                  /*!< SCI_A Postion   0          */ 
#define DEV_CFG_REGS_DC8_SCI_A_Msk    (0x1U << DEV_CFG_REGS_DC8_SCI_A_Pos)                                                  /*!< SCI_A Mask      0x00000001 */
#define DEV_CFG_REGS_DC8_SCI_A_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC8_SCI_A_Pos) & DEV_CFG_REGS_DC8_SCI_A_Msk)         /*!< SCI_A Set Value            */
#define DEV_CFG_REGS_DC8_SCI_A_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC8_SCI_A_Msk) >> DEV_CFG_REGS_DC8_SCI_A_Pos)         /*!< SCI_A Get Value            */


/* DC9 bitfield */
#define DEV_CFG_REGS_DC9_SPI_C_Pos    (2U)                                                                                  /*!< SPI_C Postion   2          */ 
#define DEV_CFG_REGS_DC9_SPI_C_Msk    (0x1U << DEV_CFG_REGS_DC9_SPI_C_Pos)                                                  /*!< SPI_C Mask      0x00000004 */
#define DEV_CFG_REGS_DC9_SPI_C_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC9_SPI_C_Pos) & DEV_CFG_REGS_DC9_SPI_C_Msk)         /*!< SPI_C Set Value            */
#define DEV_CFG_REGS_DC9_SPI_C_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC9_SPI_C_Msk) >> DEV_CFG_REGS_DC9_SPI_C_Pos)         /*!< SPI_C Get Value            */


#define DEV_CFG_REGS_DC9_SPI_B_Pos    (1U)                                                                                  /*!< SPI_B Postion   1          */ 
#define DEV_CFG_REGS_DC9_SPI_B_Msk    (0x1U << DEV_CFG_REGS_DC9_SPI_B_Pos)                                                  /*!< SPI_B Mask      0x00000002 */
#define DEV_CFG_REGS_DC9_SPI_B_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC9_SPI_B_Pos) & DEV_CFG_REGS_DC9_SPI_B_Msk)         /*!< SPI_B Set Value            */
#define DEV_CFG_REGS_DC9_SPI_B_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC9_SPI_B_Msk) >> DEV_CFG_REGS_DC9_SPI_B_Pos)         /*!< SPI_B Get Value            */


#define DEV_CFG_REGS_DC9_SPI_A_Pos    (0U)                                                                                  /*!< SPI_A Postion   0          */ 
#define DEV_CFG_REGS_DC9_SPI_A_Msk    (0x1U << DEV_CFG_REGS_DC9_SPI_A_Pos)                                                  /*!< SPI_A Mask      0x00000001 */
#define DEV_CFG_REGS_DC9_SPI_A_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC9_SPI_A_Pos) & DEV_CFG_REGS_DC9_SPI_A_Msk)         /*!< SPI_A Set Value            */
#define DEV_CFG_REGS_DC9_SPI_A_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC9_SPI_A_Msk) >> DEV_CFG_REGS_DC9_SPI_A_Pos)         /*!< SPI_A Get Value            */


/* DC10 bitfield */
#define DEV_CFG_REGS_DC10_PMBUS_A_Pos    (16U)                                                                                 /*!< PMBUS_A Postion   16         */ 
#define DEV_CFG_REGS_DC10_PMBUS_A_Msk    (0x1U << DEV_CFG_REGS_DC10_PMBUS_A_Pos)                                               /*!< PMBUS_A Mask      0x00010000 */
#define DEV_CFG_REGS_DC10_PMBUS_A_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC10_PMBUS_A_Pos) & DEV_CFG_REGS_DC10_PMBUS_A_Msk)   /*!< PMBUS_A Set Value            */
#define DEV_CFG_REGS_DC10_PMBUS_A_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC10_PMBUS_A_Msk) >> DEV_CFG_REGS_DC10_PMBUS_A_Pos)   /*!< PMBUS_A Get Value            */


#define DEV_CFG_REGS_DC10_I2C_B_Pos    (1U)                                                                                  /*!< I2C_B Postion   1          */ 
#define DEV_CFG_REGS_DC10_I2C_B_Msk    (0x1U << DEV_CFG_REGS_DC10_I2C_B_Pos)                                                 /*!< I2C_B Mask      0x00000002 */
#define DEV_CFG_REGS_DC10_I2C_B_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC10_I2C_B_Pos) & DEV_CFG_REGS_DC10_I2C_B_Msk)       /*!< I2C_B Set Value            */
#define DEV_CFG_REGS_DC10_I2C_B_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC10_I2C_B_Msk) >> DEV_CFG_REGS_DC10_I2C_B_Pos)       /*!< I2C_B Get Value            */


#define DEV_CFG_REGS_DC10_I2C_A_Pos    (0U)                                                                                  /*!< I2C_A Postion   0          */ 
#define DEV_CFG_REGS_DC10_I2C_A_Msk    (0x1U << DEV_CFG_REGS_DC10_I2C_A_Pos)                                                 /*!< I2C_A Mask      0x00000001 */
#define DEV_CFG_REGS_DC10_I2C_A_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC10_I2C_A_Pos) & DEV_CFG_REGS_DC10_I2C_A_Msk)       /*!< I2C_A Set Value            */
#define DEV_CFG_REGS_DC10_I2C_A_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC10_I2C_A_Msk) >> DEV_CFG_REGS_DC10_I2C_A_Pos)       /*!< I2C_A Get Value            */


/* DC11 bitfield */
#define DEV_CFG_REGS_DC11_CAN_C_Pos    (2U)                                                                                  /*!< CAN_C Postion   2          */ 
#define DEV_CFG_REGS_DC11_CAN_C_Msk    (0x1U << DEV_CFG_REGS_DC11_CAN_C_Pos)                                                 /*!< CAN_C Mask      0x00000004 */
#define DEV_CFG_REGS_DC11_CAN_C_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC11_CAN_C_Pos) & DEV_CFG_REGS_DC11_CAN_C_Msk)       /*!< CAN_C Set Value            */
#define DEV_CFG_REGS_DC11_CAN_C_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC11_CAN_C_Msk) >> DEV_CFG_REGS_DC11_CAN_C_Pos)       /*!< CAN_C Get Value            */


#define DEV_CFG_REGS_DC11_CAN_B_Pos    (1U)                                                                                  /*!< CAN_B Postion   1          */ 
#define DEV_CFG_REGS_DC11_CAN_B_Msk    (0x1U << DEV_CFG_REGS_DC11_CAN_B_Pos)                                                 /*!< CAN_B Mask      0x00000002 */
#define DEV_CFG_REGS_DC11_CAN_B_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC11_CAN_B_Pos) & DEV_CFG_REGS_DC11_CAN_B_Msk)       /*!< CAN_B Set Value            */
#define DEV_CFG_REGS_DC11_CAN_B_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC11_CAN_B_Msk) >> DEV_CFG_REGS_DC11_CAN_B_Pos)       /*!< CAN_B Get Value            */


#define DEV_CFG_REGS_DC11_CAN_A_Pos    (0U)                                                                                  /*!< CAN_A Postion   0          */ 
#define DEV_CFG_REGS_DC11_CAN_A_Msk    (0x1U << DEV_CFG_REGS_DC11_CAN_A_Pos)                                                 /*!< CAN_A Mask      0x00000001 */
#define DEV_CFG_REGS_DC11_CAN_A_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC11_CAN_A_Pos) & DEV_CFG_REGS_DC11_CAN_A_Msk)       /*!< CAN_A Set Value            */
#define DEV_CFG_REGS_DC11_CAN_A_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC11_CAN_A_Msk) >> DEV_CFG_REGS_DC11_CAN_A_Pos)       /*!< CAN_A Get Value            */


/* DC12 bitfield */
#define DEV_CFG_REGS_DC12_USB_A_Pos    (16U)                                                                                 /*!< USB_A Postion   16         */ 
#define DEV_CFG_REGS_DC12_USB_A_Msk    (0x3U << DEV_CFG_REGS_DC12_USB_A_Pos)                                                 /*!< USB_A Mask      0x00030000 */
#define DEV_CFG_REGS_DC12_USB_A_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC12_USB_A_Pos) & DEV_CFG_REGS_DC12_USB_A_Msk)       /*!< USB_A Set Value            */
#define DEV_CFG_REGS_DC12_USB_A_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC12_USB_A_Msk) >> DEV_CFG_REGS_DC12_USB_A_Pos)       /*!< USB_A Get Value            */


/* DC13 bitfield */
/* DC14 bitfield */
#define DEV_CFG_REGS_DC14_ADC_D_Pos    (3U)                                                                                  /*!< ADC_D Postion   3          */ 
#define DEV_CFG_REGS_DC14_ADC_D_Msk    (0x1U << DEV_CFG_REGS_DC14_ADC_D_Pos)                                                 /*!< ADC_D Mask      0x00000008 */
#define DEV_CFG_REGS_DC14_ADC_D_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC14_ADC_D_Pos) & DEV_CFG_REGS_DC14_ADC_D_Msk)       /*!< ADC_D Set Value            */
#define DEV_CFG_REGS_DC14_ADC_D_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC14_ADC_D_Msk) >> DEV_CFG_REGS_DC14_ADC_D_Pos)       /*!< ADC_D Get Value            */


#define DEV_CFG_REGS_DC14_ADC_C_Pos    (2U)                                                                                  /*!< ADC_C Postion   2          */ 
#define DEV_CFG_REGS_DC14_ADC_C_Msk    (0x1U << DEV_CFG_REGS_DC14_ADC_C_Pos)                                                 /*!< ADC_C Mask      0x00000004 */
#define DEV_CFG_REGS_DC14_ADC_C_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC14_ADC_C_Pos) & DEV_CFG_REGS_DC14_ADC_C_Msk)       /*!< ADC_C Set Value            */
#define DEV_CFG_REGS_DC14_ADC_C_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC14_ADC_C_Msk) >> DEV_CFG_REGS_DC14_ADC_C_Pos)       /*!< ADC_C Get Value            */


#define DEV_CFG_REGS_DC14_ADC_B_Pos    (1U)                                                                                  /*!< ADC_B Postion   1          */ 
#define DEV_CFG_REGS_DC14_ADC_B_Msk    (0x1U << DEV_CFG_REGS_DC14_ADC_B_Pos)                                                 /*!< ADC_B Mask      0x00000002 */
#define DEV_CFG_REGS_DC14_ADC_B_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC14_ADC_B_Pos) & DEV_CFG_REGS_DC14_ADC_B_Msk)       /*!< ADC_B Set Value            */
#define DEV_CFG_REGS_DC14_ADC_B_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC14_ADC_B_Msk) >> DEV_CFG_REGS_DC14_ADC_B_Pos)       /*!< ADC_B Get Value            */


#define DEV_CFG_REGS_DC14_ADC_A_Pos    (0U)                                                                                  /*!< ADC_A Postion   0          */ 
#define DEV_CFG_REGS_DC14_ADC_A_Msk    (0x1U << DEV_CFG_REGS_DC14_ADC_A_Pos)                                                 /*!< ADC_A Mask      0x00000001 */
#define DEV_CFG_REGS_DC14_ADC_A_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC14_ADC_A_Pos) & DEV_CFG_REGS_DC14_ADC_A_Msk)       /*!< ADC_A Set Value            */
#define DEV_CFG_REGS_DC14_ADC_A_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC14_ADC_A_Msk) >> DEV_CFG_REGS_DC14_ADC_A_Pos)       /*!< ADC_A Get Value            */


/* DC15 bitfield */
#define DEV_CFG_REGS_DC15_CMPSS8_Pos    (7U)                                                                                  /*!< CMPSS8 Postion   7          */ 
#define DEV_CFG_REGS_DC15_CMPSS8_Msk    (0x1U << DEV_CFG_REGS_DC15_CMPSS8_Pos)                                                /*!< CMPSS8 Mask      0x00000080 */
#define DEV_CFG_REGS_DC15_CMPSS8_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC15_CMPSS8_Pos) & DEV_CFG_REGS_DC15_CMPSS8_Msk)     /*!< CMPSS8 Set Value            */
#define DEV_CFG_REGS_DC15_CMPSS8_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC15_CMPSS8_Msk) >> DEV_CFG_REGS_DC15_CMPSS8_Pos)     /*!< CMPSS8 Get Value            */


#define DEV_CFG_REGS_DC15_CMPSS7_Pos    (6U)                                                                                  /*!< CMPSS7 Postion   6          */ 
#define DEV_CFG_REGS_DC15_CMPSS7_Msk    (0x1U << DEV_CFG_REGS_DC15_CMPSS7_Pos)                                                /*!< CMPSS7 Mask      0x00000040 */
#define DEV_CFG_REGS_DC15_CMPSS7_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC15_CMPSS7_Pos) & DEV_CFG_REGS_DC15_CMPSS7_Msk)     /*!< CMPSS7 Set Value            */
#define DEV_CFG_REGS_DC15_CMPSS7_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC15_CMPSS7_Msk) >> DEV_CFG_REGS_DC15_CMPSS7_Pos)     /*!< CMPSS7 Get Value            */


#define DEV_CFG_REGS_DC15_CMPSS6_Pos    (5U)                                                                                  /*!< CMPSS6 Postion   5          */ 
#define DEV_CFG_REGS_DC15_CMPSS6_Msk    (0x1U << DEV_CFG_REGS_DC15_CMPSS6_Pos)                                                /*!< CMPSS6 Mask      0x00000020 */
#define DEV_CFG_REGS_DC15_CMPSS6_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC15_CMPSS6_Pos) & DEV_CFG_REGS_DC15_CMPSS6_Msk)     /*!< CMPSS6 Set Value            */
#define DEV_CFG_REGS_DC15_CMPSS6_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC15_CMPSS6_Msk) >> DEV_CFG_REGS_DC15_CMPSS6_Pos)     /*!< CMPSS6 Get Value            */


#define DEV_CFG_REGS_DC15_CMPSS5_Pos    (4U)                                                                                  /*!< CMPSS5 Postion   4          */ 
#define DEV_CFG_REGS_DC15_CMPSS5_Msk    (0x1U << DEV_CFG_REGS_DC15_CMPSS5_Pos)                                                /*!< CMPSS5 Mask      0x00000010 */
#define DEV_CFG_REGS_DC15_CMPSS5_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC15_CMPSS5_Pos) & DEV_CFG_REGS_DC15_CMPSS5_Msk)     /*!< CMPSS5 Set Value            */
#define DEV_CFG_REGS_DC15_CMPSS5_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC15_CMPSS5_Msk) >> DEV_CFG_REGS_DC15_CMPSS5_Pos)     /*!< CMPSS5 Get Value            */


#define DEV_CFG_REGS_DC15_CMPSS4_Pos    (3U)                                                                                  /*!< CMPSS4 Postion   3          */ 
#define DEV_CFG_REGS_DC15_CMPSS4_Msk    (0x1U << DEV_CFG_REGS_DC15_CMPSS4_Pos)                                                /*!< CMPSS4 Mask      0x00000008 */
#define DEV_CFG_REGS_DC15_CMPSS4_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC15_CMPSS4_Pos) & DEV_CFG_REGS_DC15_CMPSS4_Msk)     /*!< CMPSS4 Set Value            */
#define DEV_CFG_REGS_DC15_CMPSS4_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC15_CMPSS4_Msk) >> DEV_CFG_REGS_DC15_CMPSS4_Pos)     /*!< CMPSS4 Get Value            */


#define DEV_CFG_REGS_DC15_CMPSS3_Pos    (2U)                                                                                  /*!< CMPSS3 Postion   2          */ 
#define DEV_CFG_REGS_DC15_CMPSS3_Msk    (0x1U << DEV_CFG_REGS_DC15_CMPSS3_Pos)                                                /*!< CMPSS3 Mask      0x00000004 */
#define DEV_CFG_REGS_DC15_CMPSS3_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC15_CMPSS3_Pos) & DEV_CFG_REGS_DC15_CMPSS3_Msk)     /*!< CMPSS3 Set Value            */
#define DEV_CFG_REGS_DC15_CMPSS3_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC15_CMPSS3_Msk) >> DEV_CFG_REGS_DC15_CMPSS3_Pos)     /*!< CMPSS3 Get Value            */


#define DEV_CFG_REGS_DC15_CMPSS2_Pos    (1U)                                                                                  /*!< CMPSS2 Postion   1          */ 
#define DEV_CFG_REGS_DC15_CMPSS2_Msk    (0x1U << DEV_CFG_REGS_DC15_CMPSS2_Pos)                                                /*!< CMPSS2 Mask      0x00000002 */
#define DEV_CFG_REGS_DC15_CMPSS2_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC15_CMPSS2_Pos) & DEV_CFG_REGS_DC15_CMPSS2_Msk)     /*!< CMPSS2 Set Value            */
#define DEV_CFG_REGS_DC15_CMPSS2_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC15_CMPSS2_Msk) >> DEV_CFG_REGS_DC15_CMPSS2_Pos)     /*!< CMPSS2 Get Value            */


#define DEV_CFG_REGS_DC15_CMPSS1_Pos    (0U)                                                                                  /*!< CMPSS1 Postion   0          */ 
#define DEV_CFG_REGS_DC15_CMPSS1_Msk    (0x1U << DEV_CFG_REGS_DC15_CMPSS1_Pos)                                                /*!< CMPSS1 Mask      0x00000001 */
#define DEV_CFG_REGS_DC15_CMPSS1_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC15_CMPSS1_Pos) & DEV_CFG_REGS_DC15_CMPSS1_Msk)     /*!< CMPSS1 Set Value            */
#define DEV_CFG_REGS_DC15_CMPSS1_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC15_CMPSS1_Msk) >> DEV_CFG_REGS_DC15_CMPSS1_Pos)     /*!< CMPSS1 Get Value            */


/* DC17 bitfield */
#define DEV_CFG_REGS_DC17_DAC_C_Pos    (18U)                                                                                 /*!< DAC_C Postion   18         */ 
#define DEV_CFG_REGS_DC17_DAC_C_Msk    (0x1U << DEV_CFG_REGS_DC17_DAC_C_Pos)                                                 /*!< DAC_C Mask      0x00040000 */
#define DEV_CFG_REGS_DC17_DAC_C_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC17_DAC_C_Pos) & DEV_CFG_REGS_DC17_DAC_C_Msk)       /*!< DAC_C Set Value            */
#define DEV_CFG_REGS_DC17_DAC_C_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC17_DAC_C_Msk) >> DEV_CFG_REGS_DC17_DAC_C_Pos)       /*!< DAC_C Get Value            */


#define DEV_CFG_REGS_DC17_DAC_B_Pos    (17U)                                                                                 /*!< DAC_B Postion   17         */ 
#define DEV_CFG_REGS_DC17_DAC_B_Msk    (0x1U << DEV_CFG_REGS_DC17_DAC_B_Pos)                                                 /*!< DAC_B Mask      0x00020000 */
#define DEV_CFG_REGS_DC17_DAC_B_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC17_DAC_B_Pos) & DEV_CFG_REGS_DC17_DAC_B_Msk)       /*!< DAC_B Set Value            */
#define DEV_CFG_REGS_DC17_DAC_B_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC17_DAC_B_Msk) >> DEV_CFG_REGS_DC17_DAC_B_Pos)       /*!< DAC_B Get Value            */


#define DEV_CFG_REGS_DC17_DAC_A_Pos    (16U)                                                                                 /*!< DAC_A Postion   16         */ 
#define DEV_CFG_REGS_DC17_DAC_A_Msk    (0x1U << DEV_CFG_REGS_DC17_DAC_A_Pos)                                                 /*!< DAC_A Mask      0x00010000 */
#define DEV_CFG_REGS_DC17_DAC_A_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC17_DAC_A_Pos) & DEV_CFG_REGS_DC17_DAC_A_Msk)       /*!< DAC_A Set Value            */
#define DEV_CFG_REGS_DC17_DAC_A_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC17_DAC_A_Msk) >> DEV_CFG_REGS_DC17_DAC_A_Pos)       /*!< DAC_A Get Value            */


/* DC18 bitfield */
/* DC19 bitfield */
/* DC20 bitfield */
#define DEV_CFG_REGS_DC20_GS15_Pos    (15U)                                                                                 /*!< GS15 Postion   15         */ 
#define DEV_CFG_REGS_DC20_GS15_Msk    (0x1U << DEV_CFG_REGS_DC20_GS15_Pos)                                                  /*!< GS15 Mask      0x00008000 */
#define DEV_CFG_REGS_DC20_GS15_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC20_GS15_Pos) & DEV_CFG_REGS_DC20_GS15_Msk)         /*!< GS15 Set Value            */
#define DEV_CFG_REGS_DC20_GS15_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC20_GS15_Msk) >> DEV_CFG_REGS_DC20_GS15_Pos)         /*!< GS15 Get Value            */


#define DEV_CFG_REGS_DC20_GS14_Pos    (14U)                                                                                 /*!< GS14 Postion   14         */ 
#define DEV_CFG_REGS_DC20_GS14_Msk    (0x1U << DEV_CFG_REGS_DC20_GS14_Pos)                                                  /*!< GS14 Mask      0x00004000 */
#define DEV_CFG_REGS_DC20_GS14_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC20_GS14_Pos) & DEV_CFG_REGS_DC20_GS14_Msk)         /*!< GS14 Set Value            */
#define DEV_CFG_REGS_DC20_GS14_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC20_GS14_Msk) >> DEV_CFG_REGS_DC20_GS14_Pos)         /*!< GS14 Get Value            */


#define DEV_CFG_REGS_DC20_GS13_Pos    (13U)                                                                                 /*!< GS13 Postion   13         */ 
#define DEV_CFG_REGS_DC20_GS13_Msk    (0x1U << DEV_CFG_REGS_DC20_GS13_Pos)                                                  /*!< GS13 Mask      0x00002000 */
#define DEV_CFG_REGS_DC20_GS13_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC20_GS13_Pos) & DEV_CFG_REGS_DC20_GS13_Msk)         /*!< GS13 Set Value            */
#define DEV_CFG_REGS_DC20_GS13_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC20_GS13_Msk) >> DEV_CFG_REGS_DC20_GS13_Pos)         /*!< GS13 Get Value            */


#define DEV_CFG_REGS_DC20_GS12_Pos    (12U)                                                                                 /*!< GS12 Postion   12         */ 
#define DEV_CFG_REGS_DC20_GS12_Msk    (0x1U << DEV_CFG_REGS_DC20_GS12_Pos)                                                  /*!< GS12 Mask      0x00001000 */
#define DEV_CFG_REGS_DC20_GS12_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC20_GS12_Pos) & DEV_CFG_REGS_DC20_GS12_Msk)         /*!< GS12 Set Value            */
#define DEV_CFG_REGS_DC20_GS12_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC20_GS12_Msk) >> DEV_CFG_REGS_DC20_GS12_Pos)         /*!< GS12 Get Value            */


#define DEV_CFG_REGS_DC20_GS11_Pos    (11U)                                                                                 /*!< GS11 Postion   11         */ 
#define DEV_CFG_REGS_DC20_GS11_Msk    (0x1U << DEV_CFG_REGS_DC20_GS11_Pos)                                                  /*!< GS11 Mask      0x00000800 */
#define DEV_CFG_REGS_DC20_GS11_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC20_GS11_Pos) & DEV_CFG_REGS_DC20_GS11_Msk)         /*!< GS11 Set Value            */
#define DEV_CFG_REGS_DC20_GS11_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC20_GS11_Msk) >> DEV_CFG_REGS_DC20_GS11_Pos)         /*!< GS11 Get Value            */


#define DEV_CFG_REGS_DC20_GS10_Pos    (10U)                                                                                 /*!< GS10 Postion   10         */ 
#define DEV_CFG_REGS_DC20_GS10_Msk    (0x1U << DEV_CFG_REGS_DC20_GS10_Pos)                                                  /*!< GS10 Mask      0x00000400 */
#define DEV_CFG_REGS_DC20_GS10_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC20_GS10_Pos) & DEV_CFG_REGS_DC20_GS10_Msk)         /*!< GS10 Set Value            */
#define DEV_CFG_REGS_DC20_GS10_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC20_GS10_Msk) >> DEV_CFG_REGS_DC20_GS10_Pos)         /*!< GS10 Get Value            */


#define DEV_CFG_REGS_DC20_GS9_Pos    (9U)                                                                                  /*!< GS9 Postion   9          */ 
#define DEV_CFG_REGS_DC20_GS9_Msk    (0x1U << DEV_CFG_REGS_DC20_GS9_Pos)                                                   /*!< GS9 Mask      0x00000200 */
#define DEV_CFG_REGS_DC20_GS9_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC20_GS9_Pos) & DEV_CFG_REGS_DC20_GS9_Msk)           /*!< GS9 Set Value            */
#define DEV_CFG_REGS_DC20_GS9_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC20_GS9_Msk) >> DEV_CFG_REGS_DC20_GS9_Pos)           /*!< GS9 Get Value            */


#define DEV_CFG_REGS_DC20_GS8_Pos    (8U)                                                                                  /*!< GS8 Postion   8          */ 
#define DEV_CFG_REGS_DC20_GS8_Msk    (0x1U << DEV_CFG_REGS_DC20_GS8_Pos)                                                   /*!< GS8 Mask      0x00000100 */
#define DEV_CFG_REGS_DC20_GS8_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC20_GS8_Pos) & DEV_CFG_REGS_DC20_GS8_Msk)           /*!< GS8 Set Value            */
#define DEV_CFG_REGS_DC20_GS8_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC20_GS8_Msk) >> DEV_CFG_REGS_DC20_GS8_Pos)           /*!< GS8 Get Value            */


#define DEV_CFG_REGS_DC20_GS7_Pos    (7U)                                                                                  /*!< GS7 Postion   7          */ 
#define DEV_CFG_REGS_DC20_GS7_Msk    (0x1U << DEV_CFG_REGS_DC20_GS7_Pos)                                                   /*!< GS7 Mask      0x00000080 */
#define DEV_CFG_REGS_DC20_GS7_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC20_GS7_Pos) & DEV_CFG_REGS_DC20_GS7_Msk)           /*!< GS7 Set Value            */
#define DEV_CFG_REGS_DC20_GS7_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC20_GS7_Msk) >> DEV_CFG_REGS_DC20_GS7_Pos)           /*!< GS7 Get Value            */


#define DEV_CFG_REGS_DC20_GS6_Pos    (6U)                                                                                  /*!< GS6 Postion   6          */ 
#define DEV_CFG_REGS_DC20_GS6_Msk    (0x1U << DEV_CFG_REGS_DC20_GS6_Pos)                                                   /*!< GS6 Mask      0x00000040 */
#define DEV_CFG_REGS_DC20_GS6_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC20_GS6_Pos) & DEV_CFG_REGS_DC20_GS6_Msk)           /*!< GS6 Set Value            */
#define DEV_CFG_REGS_DC20_GS6_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC20_GS6_Msk) >> DEV_CFG_REGS_DC20_GS6_Pos)           /*!< GS6 Get Value            */


#define DEV_CFG_REGS_DC20_GS5_Pos    (5U)                                                                                  /*!< GS5 Postion   5          */ 
#define DEV_CFG_REGS_DC20_GS5_Msk    (0x1U << DEV_CFG_REGS_DC20_GS5_Pos)                                                   /*!< GS5 Mask      0x00000020 */
#define DEV_CFG_REGS_DC20_GS5_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC20_GS5_Pos) & DEV_CFG_REGS_DC20_GS5_Msk)           /*!< GS5 Set Value            */
#define DEV_CFG_REGS_DC20_GS5_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC20_GS5_Msk) >> DEV_CFG_REGS_DC20_GS5_Pos)           /*!< GS5 Get Value            */


#define DEV_CFG_REGS_DC20_GS4_Pos    (4U)                                                                                  /*!< GS4 Postion   4          */ 
#define DEV_CFG_REGS_DC20_GS4_Msk    (0x1U << DEV_CFG_REGS_DC20_GS4_Pos)                                                   /*!< GS4 Mask      0x00000010 */
#define DEV_CFG_REGS_DC20_GS4_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC20_GS4_Pos) & DEV_CFG_REGS_DC20_GS4_Msk)           /*!< GS4 Set Value            */
#define DEV_CFG_REGS_DC20_GS4_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC20_GS4_Msk) >> DEV_CFG_REGS_DC20_GS4_Pos)           /*!< GS4 Get Value            */


#define DEV_CFG_REGS_DC20_GS3_Pos    (3U)                                                                                  /*!< GS3 Postion   3          */ 
#define DEV_CFG_REGS_DC20_GS3_Msk    (0x1U << DEV_CFG_REGS_DC20_GS3_Pos)                                                   /*!< GS3 Mask      0x00000008 */
#define DEV_CFG_REGS_DC20_GS3_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC20_GS3_Pos) & DEV_CFG_REGS_DC20_GS3_Msk)           /*!< GS3 Set Value            */
#define DEV_CFG_REGS_DC20_GS3_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC20_GS3_Msk) >> DEV_CFG_REGS_DC20_GS3_Pos)           /*!< GS3 Get Value            */


#define DEV_CFG_REGS_DC20_GS2_Pos    (2U)                                                                                  /*!< GS2 Postion   2          */ 
#define DEV_CFG_REGS_DC20_GS2_Msk    (0x1U << DEV_CFG_REGS_DC20_GS2_Pos)                                                   /*!< GS2 Mask      0x00000004 */
#define DEV_CFG_REGS_DC20_GS2_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC20_GS2_Pos) & DEV_CFG_REGS_DC20_GS2_Msk)           /*!< GS2 Set Value            */
#define DEV_CFG_REGS_DC20_GS2_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC20_GS2_Msk) >> DEV_CFG_REGS_DC20_GS2_Pos)           /*!< GS2 Get Value            */


#define DEV_CFG_REGS_DC20_GS1_Pos    (1U)                                                                                  /*!< GS1 Postion   1          */ 
#define DEV_CFG_REGS_DC20_GS1_Msk    (0x1U << DEV_CFG_REGS_DC20_GS1_Pos)                                                   /*!< GS1 Mask      0x00000002 */
#define DEV_CFG_REGS_DC20_GS1_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC20_GS1_Pos) & DEV_CFG_REGS_DC20_GS1_Msk)           /*!< GS1 Set Value            */
#define DEV_CFG_REGS_DC20_GS1_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC20_GS1_Msk) >> DEV_CFG_REGS_DC20_GS1_Pos)           /*!< GS1 Get Value            */


#define DEV_CFG_REGS_DC20_GS0_Pos    (0U)                                                                                  /*!< GS0 Postion   0          */ 
#define DEV_CFG_REGS_DC20_GS0_Msk    (0x1U << DEV_CFG_REGS_DC20_GS0_Pos)                                                   /*!< GS0 Mask      0x00000001 */
#define DEV_CFG_REGS_DC20_GS0_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DC20_GS0_Pos) & DEV_CFG_REGS_DC20_GS0_Msk)           /*!< GS0 Set Value            */
#define DEV_CFG_REGS_DC20_GS0_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DC20_GS0_Msk) >> DEV_CFG_REGS_DC20_GS0_Pos)           /*!< GS0 Get Value            */


/* PERCNF1 bitfield */
#define DEV_CFG_REGS_PERCNF1_USB_A_PHY_Pos    (16U)                                                                                 /*!< USB_A_PHY Postion   16         */ 
#define DEV_CFG_REGS_PERCNF1_USB_A_PHY_Msk    (0x1U << DEV_CFG_REGS_PERCNF1_USB_A_PHY_Pos)                                          /*!< USB_A_PHY Mask      0x00010000 */
#define DEV_CFG_REGS_PERCNF1_USB_A_PHY_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_PERCNF1_USB_A_PHY_Pos) & DEV_CFG_REGS_PERCNF1_USB_A_PHY_Msk) /*!< USB_A_PHY Set Value            */
#define DEV_CFG_REGS_PERCNF1_USB_A_PHY_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_PERCNF1_USB_A_PHY_Msk) >> DEV_CFG_REGS_PERCNF1_USB_A_PHY_Pos) /*!< USB_A_PHY Get Value            */


#define DEV_CFG_REGS_PERCNF1_ADC_D_MODE_Pos    (3U)                                                                                  /*!< ADC_D_MODE Postion   3          */ 
#define DEV_CFG_REGS_PERCNF1_ADC_D_MODE_Msk    (0x1U << DEV_CFG_REGS_PERCNF1_ADC_D_MODE_Pos)                                         /*!< ADC_D_MODE Mask      0x00000008 */
#define DEV_CFG_REGS_PERCNF1_ADC_D_MODE_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_PERCNF1_ADC_D_MODE_Pos) & DEV_CFG_REGS_PERCNF1_ADC_D_MODE_Msk) /*!< ADC_D_MODE Set Value            */
#define DEV_CFG_REGS_PERCNF1_ADC_D_MODE_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_PERCNF1_ADC_D_MODE_Msk) >> DEV_CFG_REGS_PERCNF1_ADC_D_MODE_Pos) /*!< ADC_D_MODE Get Value            */


#define DEV_CFG_REGS_PERCNF1_ADC_C_MODE_Pos    (2U)                                                                                  /*!< ADC_C_MODE Postion   2          */ 
#define DEV_CFG_REGS_PERCNF1_ADC_C_MODE_Msk    (0x1U << DEV_CFG_REGS_PERCNF1_ADC_C_MODE_Pos)                                         /*!< ADC_C_MODE Mask      0x00000004 */
#define DEV_CFG_REGS_PERCNF1_ADC_C_MODE_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_PERCNF1_ADC_C_MODE_Pos) & DEV_CFG_REGS_PERCNF1_ADC_C_MODE_Msk) /*!< ADC_C_MODE Set Value            */
#define DEV_CFG_REGS_PERCNF1_ADC_C_MODE_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_PERCNF1_ADC_C_MODE_Msk) >> DEV_CFG_REGS_PERCNF1_ADC_C_MODE_Pos) /*!< ADC_C_MODE Get Value            */


#define DEV_CFG_REGS_PERCNF1_ADC_B_MODE_Pos    (1U)                                                                                  /*!< ADC_B_MODE Postion   1          */ 
#define DEV_CFG_REGS_PERCNF1_ADC_B_MODE_Msk    (0x1U << DEV_CFG_REGS_PERCNF1_ADC_B_MODE_Pos)                                         /*!< ADC_B_MODE Mask      0x00000002 */
#define DEV_CFG_REGS_PERCNF1_ADC_B_MODE_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_PERCNF1_ADC_B_MODE_Pos) & DEV_CFG_REGS_PERCNF1_ADC_B_MODE_Msk) /*!< ADC_B_MODE Set Value            */
#define DEV_CFG_REGS_PERCNF1_ADC_B_MODE_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_PERCNF1_ADC_B_MODE_Msk) >> DEV_CFG_REGS_PERCNF1_ADC_B_MODE_Pos) /*!< ADC_B_MODE Get Value            */


#define DEV_CFG_REGS_PERCNF1_ADC_A_MODE_Pos    (0U)                                                                                  /*!< ADC_A_MODE Postion   0          */ 
#define DEV_CFG_REGS_PERCNF1_ADC_A_MODE_Msk    (0x1U << DEV_CFG_REGS_PERCNF1_ADC_A_MODE_Pos)                                         /*!< ADC_A_MODE Mask      0x00000001 */
#define DEV_CFG_REGS_PERCNF1_ADC_A_MODE_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_PERCNF1_ADC_A_MODE_Pos) & DEV_CFG_REGS_PERCNF1_ADC_A_MODE_Msk) /*!< ADC_A_MODE Set Value            */
#define DEV_CFG_REGS_PERCNF1_ADC_A_MODE_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_PERCNF1_ADC_A_MODE_Msk) >> DEV_CFG_REGS_PERCNF1_ADC_A_MODE_Pos) /*!< ADC_A_MODE Get Value            */


/* SOFTPRES0 bitfield */
#define DEV_CFG_REGS_SOFTPRES0_CRC_Pos    (8U)                                                                                  /*!< CRC Postion   8          */ 
#define DEV_CFG_REGS_SOFTPRES0_CRC_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES0_CRC_Pos)                                              /*!< CRC Mask      0x00000100 */
#define DEV_CFG_REGS_SOFTPRES0_CRC_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES0_CRC_Pos) & DEV_CFG_REGS_SOFTPRES0_CRC_Msk) /*!< CRC Set Value            */
#define DEV_CFG_REGS_SOFTPRES0_CRC_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES0_CRC_Msk) >> DEV_CFG_REGS_SOFTPRES0_CRC_Pos) /*!< CRC Get Value            */


#define DEV_CFG_REGS_SOFTPRES0_TFU_Pos    (0U)                                                                                  /*!< TFU Postion   0          */ 
#define DEV_CFG_REGS_SOFTPRES0_TFU_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES0_TFU_Pos)                                              /*!< TFU Mask      0x00000001 */
#define DEV_CFG_REGS_SOFTPRES0_TFU_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES0_TFU_Pos) & DEV_CFG_REGS_SOFTPRES0_TFU_Msk) /*!< TFU Set Value            */
#define DEV_CFG_REGS_SOFTPRES0_TFU_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES0_TFU_Msk) >> DEV_CFG_REGS_SOFTPRES0_TFU_Pos) /*!< TFU Get Value            */


/* SOFTPRES1 bitfield */
#define DEV_CFG_REGS_SOFTPRES1_EMIF2_Pos    (1U)                                                                                  /*!< EMIF2 Postion   1          */ 
#define DEV_CFG_REGS_SOFTPRES1_EMIF2_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES1_EMIF2_Pos)                                            /*!< EMIF2 Mask      0x00000002 */
#define DEV_CFG_REGS_SOFTPRES1_EMIF2_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES1_EMIF2_Pos) & DEV_CFG_REGS_SOFTPRES1_EMIF2_Msk) /*!< EMIF2 Set Value            */
#define DEV_CFG_REGS_SOFTPRES1_EMIF2_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES1_EMIF2_Msk) >> DEV_CFG_REGS_SOFTPRES1_EMIF2_Pos) /*!< EMIF2 Get Value            */


#define DEV_CFG_REGS_SOFTPRES1_EMIF1_Pos    (0U)                                                                                  /*!< EMIF1 Postion   0          */ 
#define DEV_CFG_REGS_SOFTPRES1_EMIF1_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES1_EMIF1_Pos)                                            /*!< EMIF1 Mask      0x00000001 */
#define DEV_CFG_REGS_SOFTPRES1_EMIF1_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES1_EMIF1_Pos) & DEV_CFG_REGS_SOFTPRES1_EMIF1_Msk) /*!< EMIF1 Set Value            */
#define DEV_CFG_REGS_SOFTPRES1_EMIF1_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES1_EMIF1_Msk) >> DEV_CFG_REGS_SOFTPRES1_EMIF1_Pos) /*!< EMIF1 Get Value            */


/* SOFTPRES2 bitfield */
#define DEV_CFG_REGS_SOFTPRES2_EPWM12_Pos    (11U)                                                                                 /*!< EPWM12 Postion   11         */ 
#define DEV_CFG_REGS_SOFTPRES2_EPWM12_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES2_EPWM12_Pos)                                           /*!< EPWM12 Mask      0x00000800 */
#define DEV_CFG_REGS_SOFTPRES2_EPWM12_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES2_EPWM12_Pos) & DEV_CFG_REGS_SOFTPRES2_EPWM12_Msk) /*!< EPWM12 Set Value            */
#define DEV_CFG_REGS_SOFTPRES2_EPWM12_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES2_EPWM12_Msk) >> DEV_CFG_REGS_SOFTPRES2_EPWM12_Pos) /*!< EPWM12 Get Value            */


#define DEV_CFG_REGS_SOFTPRES2_EPWM11_Pos    (10U)                                                                                 /*!< EPWM11 Postion   10         */ 
#define DEV_CFG_REGS_SOFTPRES2_EPWM11_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES2_EPWM11_Pos)                                           /*!< EPWM11 Mask      0x00000400 */
#define DEV_CFG_REGS_SOFTPRES2_EPWM11_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES2_EPWM11_Pos) & DEV_CFG_REGS_SOFTPRES2_EPWM11_Msk) /*!< EPWM11 Set Value            */
#define DEV_CFG_REGS_SOFTPRES2_EPWM11_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES2_EPWM11_Msk) >> DEV_CFG_REGS_SOFTPRES2_EPWM11_Pos) /*!< EPWM11 Get Value            */


#define DEV_CFG_REGS_SOFTPRES2_EPWM10_Pos    (9U)                                                                                  /*!< EPWM10 Postion   9          */ 
#define DEV_CFG_REGS_SOFTPRES2_EPWM10_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES2_EPWM10_Pos)                                           /*!< EPWM10 Mask      0x00000200 */
#define DEV_CFG_REGS_SOFTPRES2_EPWM10_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES2_EPWM10_Pos) & DEV_CFG_REGS_SOFTPRES2_EPWM10_Msk) /*!< EPWM10 Set Value            */
#define DEV_CFG_REGS_SOFTPRES2_EPWM10_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES2_EPWM10_Msk) >> DEV_CFG_REGS_SOFTPRES2_EPWM10_Pos) /*!< EPWM10 Get Value            */


#define DEV_CFG_REGS_SOFTPRES2_EPWM9_Pos    (8U)                                                                                  /*!< EPWM9 Postion   8          */ 
#define DEV_CFG_REGS_SOFTPRES2_EPWM9_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES2_EPWM9_Pos)                                            /*!< EPWM9 Mask      0x00000100 */
#define DEV_CFG_REGS_SOFTPRES2_EPWM9_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES2_EPWM9_Pos) & DEV_CFG_REGS_SOFTPRES2_EPWM9_Msk) /*!< EPWM9 Set Value            */
#define DEV_CFG_REGS_SOFTPRES2_EPWM9_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES2_EPWM9_Msk) >> DEV_CFG_REGS_SOFTPRES2_EPWM9_Pos) /*!< EPWM9 Get Value            */


#define DEV_CFG_REGS_SOFTPRES2_EPWM8_Pos    (7U)                                                                                  /*!< EPWM8 Postion   7          */ 
#define DEV_CFG_REGS_SOFTPRES2_EPWM8_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES2_EPWM8_Pos)                                            /*!< EPWM8 Mask      0x00000080 */
#define DEV_CFG_REGS_SOFTPRES2_EPWM8_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES2_EPWM8_Pos) & DEV_CFG_REGS_SOFTPRES2_EPWM8_Msk) /*!< EPWM8 Set Value            */
#define DEV_CFG_REGS_SOFTPRES2_EPWM8_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES2_EPWM8_Msk) >> DEV_CFG_REGS_SOFTPRES2_EPWM8_Pos) /*!< EPWM8 Get Value            */


#define DEV_CFG_REGS_SOFTPRES2_EPWM7_Pos    (6U)                                                                                  /*!< EPWM7 Postion   6          */ 
#define DEV_CFG_REGS_SOFTPRES2_EPWM7_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES2_EPWM7_Pos)                                            /*!< EPWM7 Mask      0x00000040 */
#define DEV_CFG_REGS_SOFTPRES2_EPWM7_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES2_EPWM7_Pos) & DEV_CFG_REGS_SOFTPRES2_EPWM7_Msk) /*!< EPWM7 Set Value            */
#define DEV_CFG_REGS_SOFTPRES2_EPWM7_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES2_EPWM7_Msk) >> DEV_CFG_REGS_SOFTPRES2_EPWM7_Pos) /*!< EPWM7 Get Value            */


#define DEV_CFG_REGS_SOFTPRES2_EPWM6_Pos    (5U)                                                                                  /*!< EPWM6 Postion   5          */ 
#define DEV_CFG_REGS_SOFTPRES2_EPWM6_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES2_EPWM6_Pos)                                            /*!< EPWM6 Mask      0x00000020 */
#define DEV_CFG_REGS_SOFTPRES2_EPWM6_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES2_EPWM6_Pos) & DEV_CFG_REGS_SOFTPRES2_EPWM6_Msk) /*!< EPWM6 Set Value            */
#define DEV_CFG_REGS_SOFTPRES2_EPWM6_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES2_EPWM6_Msk) >> DEV_CFG_REGS_SOFTPRES2_EPWM6_Pos) /*!< EPWM6 Get Value            */


#define DEV_CFG_REGS_SOFTPRES2_EPWM5_Pos    (4U)                                                                                  /*!< EPWM5 Postion   4          */ 
#define DEV_CFG_REGS_SOFTPRES2_EPWM5_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES2_EPWM5_Pos)                                            /*!< EPWM5 Mask      0x00000010 */
#define DEV_CFG_REGS_SOFTPRES2_EPWM5_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES2_EPWM5_Pos) & DEV_CFG_REGS_SOFTPRES2_EPWM5_Msk) /*!< EPWM5 Set Value            */
#define DEV_CFG_REGS_SOFTPRES2_EPWM5_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES2_EPWM5_Msk) >> DEV_CFG_REGS_SOFTPRES2_EPWM5_Pos) /*!< EPWM5 Get Value            */


#define DEV_CFG_REGS_SOFTPRES2_EPWM4_Pos    (3U)                                                                                  /*!< EPWM4 Postion   3          */ 
#define DEV_CFG_REGS_SOFTPRES2_EPWM4_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES2_EPWM4_Pos)                                            /*!< EPWM4 Mask      0x00000008 */
#define DEV_CFG_REGS_SOFTPRES2_EPWM4_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES2_EPWM4_Pos) & DEV_CFG_REGS_SOFTPRES2_EPWM4_Msk) /*!< EPWM4 Set Value            */
#define DEV_CFG_REGS_SOFTPRES2_EPWM4_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES2_EPWM4_Msk) >> DEV_CFG_REGS_SOFTPRES2_EPWM4_Pos) /*!< EPWM4 Get Value            */


#define DEV_CFG_REGS_SOFTPRES2_EPWM3_Pos    (2U)                                                                                  /*!< EPWM3 Postion   2          */ 
#define DEV_CFG_REGS_SOFTPRES2_EPWM3_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES2_EPWM3_Pos)                                            /*!< EPWM3 Mask      0x00000004 */
#define DEV_CFG_REGS_SOFTPRES2_EPWM3_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES2_EPWM3_Pos) & DEV_CFG_REGS_SOFTPRES2_EPWM3_Msk) /*!< EPWM3 Set Value            */
#define DEV_CFG_REGS_SOFTPRES2_EPWM3_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES2_EPWM3_Msk) >> DEV_CFG_REGS_SOFTPRES2_EPWM3_Pos) /*!< EPWM3 Get Value            */


#define DEV_CFG_REGS_SOFTPRES2_EPWM2_Pos    (1U)                                                                                  /*!< EPWM2 Postion   1          */ 
#define DEV_CFG_REGS_SOFTPRES2_EPWM2_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES2_EPWM2_Pos)                                            /*!< EPWM2 Mask      0x00000002 */
#define DEV_CFG_REGS_SOFTPRES2_EPWM2_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES2_EPWM2_Pos) & DEV_CFG_REGS_SOFTPRES2_EPWM2_Msk) /*!< EPWM2 Set Value            */
#define DEV_CFG_REGS_SOFTPRES2_EPWM2_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES2_EPWM2_Msk) >> DEV_CFG_REGS_SOFTPRES2_EPWM2_Pos) /*!< EPWM2 Get Value            */


#define DEV_CFG_REGS_SOFTPRES2_EPWM1_Pos    (0U)                                                                                  /*!< EPWM1 Postion   0          */ 
#define DEV_CFG_REGS_SOFTPRES2_EPWM1_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES2_EPWM1_Pos)                                            /*!< EPWM1 Mask      0x00000001 */
#define DEV_CFG_REGS_SOFTPRES2_EPWM1_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES2_EPWM1_Pos) & DEV_CFG_REGS_SOFTPRES2_EPWM1_Msk) /*!< EPWM1 Set Value            */
#define DEV_CFG_REGS_SOFTPRES2_EPWM1_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES2_EPWM1_Msk) >> DEV_CFG_REGS_SOFTPRES2_EPWM1_Pos) /*!< EPWM1 Get Value            */


/* SOFTPRES3 bitfield */
#define DEV_CFG_REGS_SOFTPRES3_ECAP6_Pos    (5U)                                                                                  /*!< ECAP6 Postion   5          */ 
#define DEV_CFG_REGS_SOFTPRES3_ECAP6_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES3_ECAP6_Pos)                                            /*!< ECAP6 Mask      0x00000020 */
#define DEV_CFG_REGS_SOFTPRES3_ECAP6_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES3_ECAP6_Pos) & DEV_CFG_REGS_SOFTPRES3_ECAP6_Msk) /*!< ECAP6 Set Value            */
#define DEV_CFG_REGS_SOFTPRES3_ECAP6_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES3_ECAP6_Msk) >> DEV_CFG_REGS_SOFTPRES3_ECAP6_Pos) /*!< ECAP6 Get Value            */


#define DEV_CFG_REGS_SOFTPRES3_ECAP5_Pos    (4U)                                                                                  /*!< ECAP5 Postion   4          */ 
#define DEV_CFG_REGS_SOFTPRES3_ECAP5_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES3_ECAP5_Pos)                                            /*!< ECAP5 Mask      0x00000010 */
#define DEV_CFG_REGS_SOFTPRES3_ECAP5_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES3_ECAP5_Pos) & DEV_CFG_REGS_SOFTPRES3_ECAP5_Msk) /*!< ECAP5 Set Value            */
#define DEV_CFG_REGS_SOFTPRES3_ECAP5_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES3_ECAP5_Msk) >> DEV_CFG_REGS_SOFTPRES3_ECAP5_Pos) /*!< ECAP5 Get Value            */


#define DEV_CFG_REGS_SOFTPRES3_ECAP4_Pos    (3U)                                                                                  /*!< ECAP4 Postion   3          */ 
#define DEV_CFG_REGS_SOFTPRES3_ECAP4_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES3_ECAP4_Pos)                                            /*!< ECAP4 Mask      0x00000008 */
#define DEV_CFG_REGS_SOFTPRES3_ECAP4_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES3_ECAP4_Pos) & DEV_CFG_REGS_SOFTPRES3_ECAP4_Msk) /*!< ECAP4 Set Value            */
#define DEV_CFG_REGS_SOFTPRES3_ECAP4_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES3_ECAP4_Msk) >> DEV_CFG_REGS_SOFTPRES3_ECAP4_Pos) /*!< ECAP4 Get Value            */


#define DEV_CFG_REGS_SOFTPRES3_ECAP3_Pos    (2U)                                                                                  /*!< ECAP3 Postion   2          */ 
#define DEV_CFG_REGS_SOFTPRES3_ECAP3_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES3_ECAP3_Pos)                                            /*!< ECAP3 Mask      0x00000004 */
#define DEV_CFG_REGS_SOFTPRES3_ECAP3_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES3_ECAP3_Pos) & DEV_CFG_REGS_SOFTPRES3_ECAP3_Msk) /*!< ECAP3 Set Value            */
#define DEV_CFG_REGS_SOFTPRES3_ECAP3_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES3_ECAP3_Msk) >> DEV_CFG_REGS_SOFTPRES3_ECAP3_Pos) /*!< ECAP3 Get Value            */


#define DEV_CFG_REGS_SOFTPRES3_ECAP2_Pos    (1U)                                                                                  /*!< ECAP2 Postion   1          */ 
#define DEV_CFG_REGS_SOFTPRES3_ECAP2_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES3_ECAP2_Pos)                                            /*!< ECAP2 Mask      0x00000002 */
#define DEV_CFG_REGS_SOFTPRES3_ECAP2_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES3_ECAP2_Pos) & DEV_CFG_REGS_SOFTPRES3_ECAP2_Msk) /*!< ECAP2 Set Value            */
#define DEV_CFG_REGS_SOFTPRES3_ECAP2_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES3_ECAP2_Msk) >> DEV_CFG_REGS_SOFTPRES3_ECAP2_Pos) /*!< ECAP2 Get Value            */


#define DEV_CFG_REGS_SOFTPRES3_ECAP1_Pos    (0U)                                                                                  /*!< ECAP1 Postion   0          */ 
#define DEV_CFG_REGS_SOFTPRES3_ECAP1_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES3_ECAP1_Pos)                                            /*!< ECAP1 Mask      0x00000001 */
#define DEV_CFG_REGS_SOFTPRES3_ECAP1_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES3_ECAP1_Pos) & DEV_CFG_REGS_SOFTPRES3_ECAP1_Msk) /*!< ECAP1 Set Value            */
#define DEV_CFG_REGS_SOFTPRES3_ECAP1_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES3_ECAP1_Msk) >> DEV_CFG_REGS_SOFTPRES3_ECAP1_Pos) /*!< ECAP1 Get Value            */


/* SOFTPRES4 bitfield */
#define DEV_CFG_REGS_SOFTPRES4_EQEP3_Pos    (2U)                                                                                  /*!< EQEP3 Postion   2          */ 
#define DEV_CFG_REGS_SOFTPRES4_EQEP3_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES4_EQEP3_Pos)                                            /*!< EQEP3 Mask      0x00000004 */
#define DEV_CFG_REGS_SOFTPRES4_EQEP3_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES4_EQEP3_Pos) & DEV_CFG_REGS_SOFTPRES4_EQEP3_Msk) /*!< EQEP3 Set Value            */
#define DEV_CFG_REGS_SOFTPRES4_EQEP3_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES4_EQEP3_Msk) >> DEV_CFG_REGS_SOFTPRES4_EQEP3_Pos) /*!< EQEP3 Get Value            */


#define DEV_CFG_REGS_SOFTPRES4_EQEP2_Pos    (1U)                                                                                  /*!< EQEP2 Postion   1          */ 
#define DEV_CFG_REGS_SOFTPRES4_EQEP2_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES4_EQEP2_Pos)                                            /*!< EQEP2 Mask      0x00000002 */
#define DEV_CFG_REGS_SOFTPRES4_EQEP2_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES4_EQEP2_Pos) & DEV_CFG_REGS_SOFTPRES4_EQEP2_Msk) /*!< EQEP2 Set Value            */
#define DEV_CFG_REGS_SOFTPRES4_EQEP2_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES4_EQEP2_Msk) >> DEV_CFG_REGS_SOFTPRES4_EQEP2_Pos) /*!< EQEP2 Get Value            */


#define DEV_CFG_REGS_SOFTPRES4_EQEP1_Pos    (0U)                                                                                  /*!< EQEP1 Postion   0          */ 
#define DEV_CFG_REGS_SOFTPRES4_EQEP1_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES4_EQEP1_Pos)                                            /*!< EQEP1 Mask      0x00000001 */
#define DEV_CFG_REGS_SOFTPRES4_EQEP1_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES4_EQEP1_Pos) & DEV_CFG_REGS_SOFTPRES4_EQEP1_Msk) /*!< EQEP1 Set Value            */
#define DEV_CFG_REGS_SOFTPRES4_EQEP1_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES4_EQEP1_Msk) >> DEV_CFG_REGS_SOFTPRES4_EQEP1_Pos) /*!< EQEP1 Get Value            */


/* SOFTPRES6 bitfield */
#define DEV_CFG_REGS_SOFTPRES6_SD2_Pos    (1U)                                                                                  /*!< SD2 Postion   1          */ 
#define DEV_CFG_REGS_SOFTPRES6_SD2_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES6_SD2_Pos)                                              /*!< SD2 Mask      0x00000002 */
#define DEV_CFG_REGS_SOFTPRES6_SD2_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES6_SD2_Pos) & DEV_CFG_REGS_SOFTPRES6_SD2_Msk) /*!< SD2 Set Value            */
#define DEV_CFG_REGS_SOFTPRES6_SD2_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES6_SD2_Msk) >> DEV_CFG_REGS_SOFTPRES6_SD2_Pos) /*!< SD2 Get Value            */


#define DEV_CFG_REGS_SOFTPRES6_SD1_Pos    (0U)                                                                                  /*!< SD1 Postion   0          */ 
#define DEV_CFG_REGS_SOFTPRES6_SD1_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES6_SD1_Pos)                                              /*!< SD1 Mask      0x00000001 */
#define DEV_CFG_REGS_SOFTPRES6_SD1_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES6_SD1_Pos) & DEV_CFG_REGS_SOFTPRES6_SD1_Msk) /*!< SD1 Set Value            */
#define DEV_CFG_REGS_SOFTPRES6_SD1_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES6_SD1_Msk) >> DEV_CFG_REGS_SOFTPRES6_SD1_Pos) /*!< SD1 Get Value            */


/* SOFTPRES7 bitfield */
#define DEV_CFG_REGS_SOFTPRES7_SCI_D_Pos    (3U)                                                                                  /*!< SCI_D Postion   3          */ 
#define DEV_CFG_REGS_SOFTPRES7_SCI_D_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES7_SCI_D_Pos)                                            /*!< SCI_D Mask      0x00000008 */
#define DEV_CFG_REGS_SOFTPRES7_SCI_D_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES7_SCI_D_Pos) & DEV_CFG_REGS_SOFTPRES7_SCI_D_Msk) /*!< SCI_D Set Value            */
#define DEV_CFG_REGS_SOFTPRES7_SCI_D_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES7_SCI_D_Msk) >> DEV_CFG_REGS_SOFTPRES7_SCI_D_Pos) /*!< SCI_D Get Value            */


#define DEV_CFG_REGS_SOFTPRES7_SCI_C_Pos    (2U)                                                                                  /*!< SCI_C Postion   2          */ 
#define DEV_CFG_REGS_SOFTPRES7_SCI_C_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES7_SCI_C_Pos)                                            /*!< SCI_C Mask      0x00000004 */
#define DEV_CFG_REGS_SOFTPRES7_SCI_C_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES7_SCI_C_Pos) & DEV_CFG_REGS_SOFTPRES7_SCI_C_Msk) /*!< SCI_C Set Value            */
#define DEV_CFG_REGS_SOFTPRES7_SCI_C_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES7_SCI_C_Msk) >> DEV_CFG_REGS_SOFTPRES7_SCI_C_Pos) /*!< SCI_C Get Value            */


#define DEV_CFG_REGS_SOFTPRES7_SCI_B_Pos    (1U)                                                                                  /*!< SCI_B Postion   1          */ 
#define DEV_CFG_REGS_SOFTPRES7_SCI_B_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES7_SCI_B_Pos)                                            /*!< SCI_B Mask      0x00000002 */
#define DEV_CFG_REGS_SOFTPRES7_SCI_B_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES7_SCI_B_Pos) & DEV_CFG_REGS_SOFTPRES7_SCI_B_Msk) /*!< SCI_B Set Value            */
#define DEV_CFG_REGS_SOFTPRES7_SCI_B_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES7_SCI_B_Msk) >> DEV_CFG_REGS_SOFTPRES7_SCI_B_Pos) /*!< SCI_B Get Value            */


#define DEV_CFG_REGS_SOFTPRES7_SCI_A_Pos    (0U)                                                                                  /*!< SCI_A Postion   0          */ 
#define DEV_CFG_REGS_SOFTPRES7_SCI_A_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES7_SCI_A_Pos)                                            /*!< SCI_A Mask      0x00000001 */
#define DEV_CFG_REGS_SOFTPRES7_SCI_A_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES7_SCI_A_Pos) & DEV_CFG_REGS_SOFTPRES7_SCI_A_Msk) /*!< SCI_A Set Value            */
#define DEV_CFG_REGS_SOFTPRES7_SCI_A_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES7_SCI_A_Msk) >> DEV_CFG_REGS_SOFTPRES7_SCI_A_Pos) /*!< SCI_A Get Value            */


/* SOFTPRES8 bitfield */
#define DEV_CFG_REGS_SOFTPRES8_SPI_C_Pos    (2U)                                                                                  /*!< SPI_C Postion   2          */ 
#define DEV_CFG_REGS_SOFTPRES8_SPI_C_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES8_SPI_C_Pos)                                            /*!< SPI_C Mask      0x00000004 */
#define DEV_CFG_REGS_SOFTPRES8_SPI_C_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES8_SPI_C_Pos) & DEV_CFG_REGS_SOFTPRES8_SPI_C_Msk) /*!< SPI_C Set Value            */
#define DEV_CFG_REGS_SOFTPRES8_SPI_C_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES8_SPI_C_Msk) >> DEV_CFG_REGS_SOFTPRES8_SPI_C_Pos) /*!< SPI_C Get Value            */


#define DEV_CFG_REGS_SOFTPRES8_SPI_B_Pos    (1U)                                                                                  /*!< SPI_B Postion   1          */ 
#define DEV_CFG_REGS_SOFTPRES8_SPI_B_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES8_SPI_B_Pos)                                            /*!< SPI_B Mask      0x00000002 */
#define DEV_CFG_REGS_SOFTPRES8_SPI_B_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES8_SPI_B_Pos) & DEV_CFG_REGS_SOFTPRES8_SPI_B_Msk) /*!< SPI_B Set Value            */
#define DEV_CFG_REGS_SOFTPRES8_SPI_B_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES8_SPI_B_Msk) >> DEV_CFG_REGS_SOFTPRES8_SPI_B_Pos) /*!< SPI_B Get Value            */


#define DEV_CFG_REGS_SOFTPRES8_SPI_A_Pos    (0U)                                                                                  /*!< SPI_A Postion   0          */ 
#define DEV_CFG_REGS_SOFTPRES8_SPI_A_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES8_SPI_A_Pos)                                            /*!< SPI_A Mask      0x00000001 */
#define DEV_CFG_REGS_SOFTPRES8_SPI_A_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES8_SPI_A_Pos) & DEV_CFG_REGS_SOFTPRES8_SPI_A_Msk) /*!< SPI_A Set Value            */
#define DEV_CFG_REGS_SOFTPRES8_SPI_A_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES8_SPI_A_Msk) >> DEV_CFG_REGS_SOFTPRES8_SPI_A_Pos) /*!< SPI_A Get Value            */


/* SOFTPRES9 bitfield */
#define DEV_CFG_REGS_SOFTPRES9_PMBUS_A_Pos    (16U)                                                                                 /*!< PMBUS_A Postion   16         */ 
#define DEV_CFG_REGS_SOFTPRES9_PMBUS_A_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES9_PMBUS_A_Pos)                                          /*!< PMBUS_A Mask      0x00010000 */
#define DEV_CFG_REGS_SOFTPRES9_PMBUS_A_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES9_PMBUS_A_Pos) & DEV_CFG_REGS_SOFTPRES9_PMBUS_A_Msk) /*!< PMBUS_A Set Value            */
#define DEV_CFG_REGS_SOFTPRES9_PMBUS_A_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES9_PMBUS_A_Msk) >> DEV_CFG_REGS_SOFTPRES9_PMBUS_A_Pos) /*!< PMBUS_A Get Value            */


#define DEV_CFG_REGS_SOFTPRES9_I2C_B_Pos    (1U)                                                                                  /*!< I2C_B Postion   1          */ 
#define DEV_CFG_REGS_SOFTPRES9_I2C_B_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES9_I2C_B_Pos)                                            /*!< I2C_B Mask      0x00000002 */
#define DEV_CFG_REGS_SOFTPRES9_I2C_B_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES9_I2C_B_Pos) & DEV_CFG_REGS_SOFTPRES9_I2C_B_Msk) /*!< I2C_B Set Value            */
#define DEV_CFG_REGS_SOFTPRES9_I2C_B_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES9_I2C_B_Msk) >> DEV_CFG_REGS_SOFTPRES9_I2C_B_Pos) /*!< I2C_B Get Value            */


#define DEV_CFG_REGS_SOFTPRES9_I2C_A_Pos    (0U)                                                                                  /*!< I2C_A Postion   0          */ 
#define DEV_CFG_REGS_SOFTPRES9_I2C_A_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES9_I2C_A_Pos)                                            /*!< I2C_A Mask      0x00000001 */
#define DEV_CFG_REGS_SOFTPRES9_I2C_A_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES9_I2C_A_Pos) & DEV_CFG_REGS_SOFTPRES9_I2C_A_Msk) /*!< I2C_A Set Value            */
#define DEV_CFG_REGS_SOFTPRES9_I2C_A_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES9_I2C_A_Msk) >> DEV_CFG_REGS_SOFTPRES9_I2C_A_Pos) /*!< I2C_A Get Value            */


/* SOFTPRES10 bitfield */
#define DEV_CFG_REGS_SOFTPRES10_CAN_C_Pos    (2U)                                                                                  /*!< CAN_C Postion   2          */ 
#define DEV_CFG_REGS_SOFTPRES10_CAN_C_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES10_CAN_C_Pos)                                           /*!< CAN_C Mask      0x00000004 */
#define DEV_CFG_REGS_SOFTPRES10_CAN_C_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES10_CAN_C_Pos) & DEV_CFG_REGS_SOFTPRES10_CAN_C_Msk) /*!< CAN_C Set Value            */
#define DEV_CFG_REGS_SOFTPRES10_CAN_C_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES10_CAN_C_Msk) >> DEV_CFG_REGS_SOFTPRES10_CAN_C_Pos) /*!< CAN_C Get Value            */


#define DEV_CFG_REGS_SOFTPRES10_CAN_B_Pos    (1U)                                                                                  /*!< CAN_B Postion   1          */ 
#define DEV_CFG_REGS_SOFTPRES10_CAN_B_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES10_CAN_B_Pos)                                           /*!< CAN_B Mask      0x00000002 */
#define DEV_CFG_REGS_SOFTPRES10_CAN_B_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES10_CAN_B_Pos) & DEV_CFG_REGS_SOFTPRES10_CAN_B_Msk) /*!< CAN_B Set Value            */
#define DEV_CFG_REGS_SOFTPRES10_CAN_B_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES10_CAN_B_Msk) >> DEV_CFG_REGS_SOFTPRES10_CAN_B_Pos) /*!< CAN_B Get Value            */


#define DEV_CFG_REGS_SOFTPRES10_CAN_A_Pos    (0U)                                                                                  /*!< CAN_A Postion   0          */ 
#define DEV_CFG_REGS_SOFTPRES10_CAN_A_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES10_CAN_A_Pos)                                           /*!< CAN_A Mask      0x00000001 */
#define DEV_CFG_REGS_SOFTPRES10_CAN_A_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES10_CAN_A_Pos) & DEV_CFG_REGS_SOFTPRES10_CAN_A_Msk) /*!< CAN_A Set Value            */
#define DEV_CFG_REGS_SOFTPRES10_CAN_A_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES10_CAN_A_Msk) >> DEV_CFG_REGS_SOFTPRES10_CAN_A_Pos) /*!< CAN_A Get Value            */


/* SOFTPRES11 bitfield */
#define DEV_CFG_REGS_SOFTPRES11_USB_A_Pos    (16U)                                                                                 /*!< USB_A Postion   16         */ 
#define DEV_CFG_REGS_SOFTPRES11_USB_A_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES11_USB_A_Pos)                                           /*!< USB_A Mask      0x00010000 */
#define DEV_CFG_REGS_SOFTPRES11_USB_A_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES11_USB_A_Pos) & DEV_CFG_REGS_SOFTPRES11_USB_A_Msk) /*!< USB_A Set Value            */
#define DEV_CFG_REGS_SOFTPRES11_USB_A_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES11_USB_A_Msk) >> DEV_CFG_REGS_SOFTPRES11_USB_A_Pos) /*!< USB_A Get Value            */


/* SOFTPRES13 bitfield */
#define DEV_CFG_REGS_SOFTPRES13_ADC_D_Pos    (3U)                                                                                  /*!< ADC_D Postion   3          */ 
#define DEV_CFG_REGS_SOFTPRES13_ADC_D_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES13_ADC_D_Pos)                                           /*!< ADC_D Mask      0x00000008 */
#define DEV_CFG_REGS_SOFTPRES13_ADC_D_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES13_ADC_D_Pos) & DEV_CFG_REGS_SOFTPRES13_ADC_D_Msk) /*!< ADC_D Set Value            */
#define DEV_CFG_REGS_SOFTPRES13_ADC_D_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES13_ADC_D_Msk) >> DEV_CFG_REGS_SOFTPRES13_ADC_D_Pos) /*!< ADC_D Get Value            */


#define DEV_CFG_REGS_SOFTPRES13_ADC_C_Pos    (2U)                                                                                  /*!< ADC_C Postion   2          */ 
#define DEV_CFG_REGS_SOFTPRES13_ADC_C_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES13_ADC_C_Pos)                                           /*!< ADC_C Mask      0x00000004 */
#define DEV_CFG_REGS_SOFTPRES13_ADC_C_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES13_ADC_C_Pos) & DEV_CFG_REGS_SOFTPRES13_ADC_C_Msk) /*!< ADC_C Set Value            */
#define DEV_CFG_REGS_SOFTPRES13_ADC_C_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES13_ADC_C_Msk) >> DEV_CFG_REGS_SOFTPRES13_ADC_C_Pos) /*!< ADC_C Get Value            */


#define DEV_CFG_REGS_SOFTPRES13_ADC_B_Pos    (1U)                                                                                  /*!< ADC_B Postion   1          */ 
#define DEV_CFG_REGS_SOFTPRES13_ADC_B_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES13_ADC_B_Pos)                                           /*!< ADC_B Mask      0x00000002 */
#define DEV_CFG_REGS_SOFTPRES13_ADC_B_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES13_ADC_B_Pos) & DEV_CFG_REGS_SOFTPRES13_ADC_B_Msk) /*!< ADC_B Set Value            */
#define DEV_CFG_REGS_SOFTPRES13_ADC_B_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES13_ADC_B_Msk) >> DEV_CFG_REGS_SOFTPRES13_ADC_B_Pos) /*!< ADC_B Get Value            */


#define DEV_CFG_REGS_SOFTPRES13_ADC_A_Pos    (0U)                                                                                  /*!< ADC_A Postion   0          */ 
#define DEV_CFG_REGS_SOFTPRES13_ADC_A_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES13_ADC_A_Pos)                                           /*!< ADC_A Mask      0x00000001 */
#define DEV_CFG_REGS_SOFTPRES13_ADC_A_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES13_ADC_A_Pos) & DEV_CFG_REGS_SOFTPRES13_ADC_A_Msk) /*!< ADC_A Set Value            */
#define DEV_CFG_REGS_SOFTPRES13_ADC_A_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES13_ADC_A_Msk) >> DEV_CFG_REGS_SOFTPRES13_ADC_A_Pos) /*!< ADC_A Get Value            */


/* SOFTPRES14 bitfield */
#define DEV_CFG_REGS_SOFTPRES14_CMPSS8_Pos    (7U)                                                                                  /*!< CMPSS8 Postion   7          */ 
#define DEV_CFG_REGS_SOFTPRES14_CMPSS8_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES14_CMPSS8_Pos)                                          /*!< CMPSS8 Mask      0x00000080 */
#define DEV_CFG_REGS_SOFTPRES14_CMPSS8_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES14_CMPSS8_Pos) & DEV_CFG_REGS_SOFTPRES14_CMPSS8_Msk) /*!< CMPSS8 Set Value            */
#define DEV_CFG_REGS_SOFTPRES14_CMPSS8_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES14_CMPSS8_Msk) >> DEV_CFG_REGS_SOFTPRES14_CMPSS8_Pos) /*!< CMPSS8 Get Value            */


#define DEV_CFG_REGS_SOFTPRES14_CMPSS7_Pos    (6U)                                                                                  /*!< CMPSS7 Postion   6          */ 
#define DEV_CFG_REGS_SOFTPRES14_CMPSS7_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES14_CMPSS7_Pos)                                          /*!< CMPSS7 Mask      0x00000040 */
#define DEV_CFG_REGS_SOFTPRES14_CMPSS7_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES14_CMPSS7_Pos) & DEV_CFG_REGS_SOFTPRES14_CMPSS7_Msk) /*!< CMPSS7 Set Value            */
#define DEV_CFG_REGS_SOFTPRES14_CMPSS7_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES14_CMPSS7_Msk) >> DEV_CFG_REGS_SOFTPRES14_CMPSS7_Pos) /*!< CMPSS7 Get Value            */


#define DEV_CFG_REGS_SOFTPRES14_CMPSS6_Pos    (5U)                                                                                  /*!< CMPSS6 Postion   5          */ 
#define DEV_CFG_REGS_SOFTPRES14_CMPSS6_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES14_CMPSS6_Pos)                                          /*!< CMPSS6 Mask      0x00000020 */
#define DEV_CFG_REGS_SOFTPRES14_CMPSS6_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES14_CMPSS6_Pos) & DEV_CFG_REGS_SOFTPRES14_CMPSS6_Msk) /*!< CMPSS6 Set Value            */
#define DEV_CFG_REGS_SOFTPRES14_CMPSS6_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES14_CMPSS6_Msk) >> DEV_CFG_REGS_SOFTPRES14_CMPSS6_Pos) /*!< CMPSS6 Get Value            */


#define DEV_CFG_REGS_SOFTPRES14_CMPSS5_Pos    (4U)                                                                                  /*!< CMPSS5 Postion   4          */ 
#define DEV_CFG_REGS_SOFTPRES14_CMPSS5_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES14_CMPSS5_Pos)                                          /*!< CMPSS5 Mask      0x00000010 */
#define DEV_CFG_REGS_SOFTPRES14_CMPSS5_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES14_CMPSS5_Pos) & DEV_CFG_REGS_SOFTPRES14_CMPSS5_Msk) /*!< CMPSS5 Set Value            */
#define DEV_CFG_REGS_SOFTPRES14_CMPSS5_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES14_CMPSS5_Msk) >> DEV_CFG_REGS_SOFTPRES14_CMPSS5_Pos) /*!< CMPSS5 Get Value            */


#define DEV_CFG_REGS_SOFTPRES14_CMPSS4_Pos    (3U)                                                                                  /*!< CMPSS4 Postion   3          */ 
#define DEV_CFG_REGS_SOFTPRES14_CMPSS4_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES14_CMPSS4_Pos)                                          /*!< CMPSS4 Mask      0x00000008 */
#define DEV_CFG_REGS_SOFTPRES14_CMPSS4_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES14_CMPSS4_Pos) & DEV_CFG_REGS_SOFTPRES14_CMPSS4_Msk) /*!< CMPSS4 Set Value            */
#define DEV_CFG_REGS_SOFTPRES14_CMPSS4_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES14_CMPSS4_Msk) >> DEV_CFG_REGS_SOFTPRES14_CMPSS4_Pos) /*!< CMPSS4 Get Value            */


#define DEV_CFG_REGS_SOFTPRES14_CMPSS3_Pos    (2U)                                                                                  /*!< CMPSS3 Postion   2          */ 
#define DEV_CFG_REGS_SOFTPRES14_CMPSS3_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES14_CMPSS3_Pos)                                          /*!< CMPSS3 Mask      0x00000004 */
#define DEV_CFG_REGS_SOFTPRES14_CMPSS3_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES14_CMPSS3_Pos) & DEV_CFG_REGS_SOFTPRES14_CMPSS3_Msk) /*!< CMPSS3 Set Value            */
#define DEV_CFG_REGS_SOFTPRES14_CMPSS3_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES14_CMPSS3_Msk) >> DEV_CFG_REGS_SOFTPRES14_CMPSS3_Pos) /*!< CMPSS3 Get Value            */


#define DEV_CFG_REGS_SOFTPRES14_CMPSS2_Pos    (1U)                                                                                  /*!< CMPSS2 Postion   1          */ 
#define DEV_CFG_REGS_SOFTPRES14_CMPSS2_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES14_CMPSS2_Pos)                                          /*!< CMPSS2 Mask      0x00000002 */
#define DEV_CFG_REGS_SOFTPRES14_CMPSS2_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES14_CMPSS2_Pos) & DEV_CFG_REGS_SOFTPRES14_CMPSS2_Msk) /*!< CMPSS2 Set Value            */
#define DEV_CFG_REGS_SOFTPRES14_CMPSS2_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES14_CMPSS2_Msk) >> DEV_CFG_REGS_SOFTPRES14_CMPSS2_Pos) /*!< CMPSS2 Get Value            */


#define DEV_CFG_REGS_SOFTPRES14_CMPSS1_Pos    (0U)                                                                                  /*!< CMPSS1 Postion   0          */ 
#define DEV_CFG_REGS_SOFTPRES14_CMPSS1_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES14_CMPSS1_Pos)                                          /*!< CMPSS1 Mask      0x00000001 */
#define DEV_CFG_REGS_SOFTPRES14_CMPSS1_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES14_CMPSS1_Pos) & DEV_CFG_REGS_SOFTPRES14_CMPSS1_Msk) /*!< CMPSS1 Set Value            */
#define DEV_CFG_REGS_SOFTPRES14_CMPSS1_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES14_CMPSS1_Msk) >> DEV_CFG_REGS_SOFTPRES14_CMPSS1_Pos) /*!< CMPSS1 Get Value            */


/* SOFTPRES16 bitfield */
#define DEV_CFG_REGS_SOFTPRES16_DAC_C_Pos    (18U)                                                                                 /*!< DAC_C Postion   18         */ 
#define DEV_CFG_REGS_SOFTPRES16_DAC_C_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES16_DAC_C_Pos)                                           /*!< DAC_C Mask      0x00040000 */
#define DEV_CFG_REGS_SOFTPRES16_DAC_C_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES16_DAC_C_Pos) & DEV_CFG_REGS_SOFTPRES16_DAC_C_Msk) /*!< DAC_C Set Value            */
#define DEV_CFG_REGS_SOFTPRES16_DAC_C_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES16_DAC_C_Msk) >> DEV_CFG_REGS_SOFTPRES16_DAC_C_Pos) /*!< DAC_C Get Value            */


#define DEV_CFG_REGS_SOFTPRES16_DAC_B_Pos    (17U)                                                                                 /*!< DAC_B Postion   17         */ 
#define DEV_CFG_REGS_SOFTPRES16_DAC_B_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES16_DAC_B_Pos)                                           /*!< DAC_B Mask      0x00020000 */
#define DEV_CFG_REGS_SOFTPRES16_DAC_B_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES16_DAC_B_Pos) & DEV_CFG_REGS_SOFTPRES16_DAC_B_Msk) /*!< DAC_B Set Value            */
#define DEV_CFG_REGS_SOFTPRES16_DAC_B_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES16_DAC_B_Msk) >> DEV_CFG_REGS_SOFTPRES16_DAC_B_Pos) /*!< DAC_B Get Value            */


#define DEV_CFG_REGS_SOFTPRES16_DAC_A_Pos    (16U)                                                                                 /*!< DAC_A Postion   16         */ 
#define DEV_CFG_REGS_SOFTPRES16_DAC_A_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES16_DAC_A_Pos)                                           /*!< DAC_A Mask      0x00010000 */
#define DEV_CFG_REGS_SOFTPRES16_DAC_A_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES16_DAC_A_Pos) & DEV_CFG_REGS_SOFTPRES16_DAC_A_Msk) /*!< DAC_A Set Value            */
#define DEV_CFG_REGS_SOFTPRES16_DAC_A_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES16_DAC_A_Msk) >> DEV_CFG_REGS_SOFTPRES16_DAC_A_Pos) /*!< DAC_A Get Value            */


/* SOFTPRES17 bitfield */
#define DEV_CFG_REGS_SOFTPRES17_CLB8_Pos    (7U)                                                                                  /*!< CLB8 Postion   7          */ 
#define DEV_CFG_REGS_SOFTPRES17_CLB8_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES17_CLB8_Pos)                                            /*!< CLB8 Mask      0x00000080 */
#define DEV_CFG_REGS_SOFTPRES17_CLB8_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES17_CLB8_Pos) & DEV_CFG_REGS_SOFTPRES17_CLB8_Msk) /*!< CLB8 Set Value            */
#define DEV_CFG_REGS_SOFTPRES17_CLB8_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES17_CLB8_Msk) >> DEV_CFG_REGS_SOFTPRES17_CLB8_Pos) /*!< CLB8 Get Value            */


#define DEV_CFG_REGS_SOFTPRES17_CLB7_Pos    (6U)                                                                                  /*!< CLB7 Postion   6          */ 
#define DEV_CFG_REGS_SOFTPRES17_CLB7_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES17_CLB7_Pos)                                            /*!< CLB7 Mask      0x00000040 */
#define DEV_CFG_REGS_SOFTPRES17_CLB7_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES17_CLB7_Pos) & DEV_CFG_REGS_SOFTPRES17_CLB7_Msk) /*!< CLB7 Set Value            */
#define DEV_CFG_REGS_SOFTPRES17_CLB7_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES17_CLB7_Msk) >> DEV_CFG_REGS_SOFTPRES17_CLB7_Pos) /*!< CLB7 Get Value            */


#define DEV_CFG_REGS_SOFTPRES17_CLB6_Pos    (5U)                                                                                  /*!< CLB6 Postion   5          */ 
#define DEV_CFG_REGS_SOFTPRES17_CLB6_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES17_CLB6_Pos)                                            /*!< CLB6 Mask      0x00000020 */
#define DEV_CFG_REGS_SOFTPRES17_CLB6_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES17_CLB6_Pos) & DEV_CFG_REGS_SOFTPRES17_CLB6_Msk) /*!< CLB6 Set Value            */
#define DEV_CFG_REGS_SOFTPRES17_CLB6_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES17_CLB6_Msk) >> DEV_CFG_REGS_SOFTPRES17_CLB6_Pos) /*!< CLB6 Get Value            */


#define DEV_CFG_REGS_SOFTPRES17_CLB5_Pos    (4U)                                                                                  /*!< CLB5 Postion   4          */ 
#define DEV_CFG_REGS_SOFTPRES17_CLB5_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES17_CLB5_Pos)                                            /*!< CLB5 Mask      0x00000010 */
#define DEV_CFG_REGS_SOFTPRES17_CLB5_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES17_CLB5_Pos) & DEV_CFG_REGS_SOFTPRES17_CLB5_Msk) /*!< CLB5 Set Value            */
#define DEV_CFG_REGS_SOFTPRES17_CLB5_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES17_CLB5_Msk) >> DEV_CFG_REGS_SOFTPRES17_CLB5_Pos) /*!< CLB5 Get Value            */


#define DEV_CFG_REGS_SOFTPRES17_CLB4_Pos    (3U)                                                                                  /*!< CLB4 Postion   3          */ 
#define DEV_CFG_REGS_SOFTPRES17_CLB4_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES17_CLB4_Pos)                                            /*!< CLB4 Mask      0x00000008 */
#define DEV_CFG_REGS_SOFTPRES17_CLB4_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES17_CLB4_Pos) & DEV_CFG_REGS_SOFTPRES17_CLB4_Msk) /*!< CLB4 Set Value            */
#define DEV_CFG_REGS_SOFTPRES17_CLB4_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES17_CLB4_Msk) >> DEV_CFG_REGS_SOFTPRES17_CLB4_Pos) /*!< CLB4 Get Value            */


#define DEV_CFG_REGS_SOFTPRES17_CLB3_Pos    (2U)                                                                                  /*!< CLB3 Postion   2          */ 
#define DEV_CFG_REGS_SOFTPRES17_CLB3_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES17_CLB3_Pos)                                            /*!< CLB3 Mask      0x00000004 */
#define DEV_CFG_REGS_SOFTPRES17_CLB3_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES17_CLB3_Pos) & DEV_CFG_REGS_SOFTPRES17_CLB3_Msk) /*!< CLB3 Set Value            */
#define DEV_CFG_REGS_SOFTPRES17_CLB3_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES17_CLB3_Msk) >> DEV_CFG_REGS_SOFTPRES17_CLB3_Pos) /*!< CLB3 Get Value            */


#define DEV_CFG_REGS_SOFTPRES17_CLB2_Pos    (1U)                                                                                  /*!< CLB2 Postion   1          */ 
#define DEV_CFG_REGS_SOFTPRES17_CLB2_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES17_CLB2_Pos)                                            /*!< CLB2 Mask      0x00000002 */
#define DEV_CFG_REGS_SOFTPRES17_CLB2_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES17_CLB2_Pos) & DEV_CFG_REGS_SOFTPRES17_CLB2_Msk) /*!< CLB2 Set Value            */
#define DEV_CFG_REGS_SOFTPRES17_CLB2_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES17_CLB2_Msk) >> DEV_CFG_REGS_SOFTPRES17_CLB2_Pos) /*!< CLB2 Get Value            */


#define DEV_CFG_REGS_SOFTPRES17_CLB1_Pos    (0U)                                                                                  /*!< CLB1 Postion   0          */ 
#define DEV_CFG_REGS_SOFTPRES17_CLB1_Msk    (0x1U << DEV_CFG_REGS_SOFTPRES17_CLB1_Pos)                                            /*!< CLB1 Mask      0x00000001 */
#define DEV_CFG_REGS_SOFTPRES17_CLB1_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SOFTPRES17_CLB1_Pos) & DEV_CFG_REGS_SOFTPRES17_CLB1_Msk) /*!< CLB1 Set Value            */
#define DEV_CFG_REGS_SOFTPRES17_CLB1_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SOFTPRES17_CLB1_Msk) >> DEV_CFG_REGS_SOFTPRES17_CLB1_Pos) /*!< CLB1 Get Value            */


/* CPUSEL0 bitfield */
#define DEV_CFG_REGS_CPUSEL0_EPWM12_Pos    (11U)                                                                                 /*!< EPWM12 Postion   11         */ 
#define DEV_CFG_REGS_CPUSEL0_EPWM12_Msk    (0x1U << DEV_CFG_REGS_CPUSEL0_EPWM12_Pos)                                             /*!< EPWM12 Mask      0x00000800 */
#define DEV_CFG_REGS_CPUSEL0_EPWM12_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL0_EPWM12_Pos) & DEV_CFG_REGS_CPUSEL0_EPWM12_Msk) /*!< EPWM12 Set Value            */
#define DEV_CFG_REGS_CPUSEL0_EPWM12_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL0_EPWM12_Msk) >> DEV_CFG_REGS_CPUSEL0_EPWM12_Pos) /*!< EPWM12 Get Value            */


#define DEV_CFG_REGS_CPUSEL0_EPWM11_Pos    (10U)                                                                                 /*!< EPWM11 Postion   10         */ 
#define DEV_CFG_REGS_CPUSEL0_EPWM11_Msk    (0x1U << DEV_CFG_REGS_CPUSEL0_EPWM11_Pos)                                             /*!< EPWM11 Mask      0x00000400 */
#define DEV_CFG_REGS_CPUSEL0_EPWM11_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL0_EPWM11_Pos) & DEV_CFG_REGS_CPUSEL0_EPWM11_Msk) /*!< EPWM11 Set Value            */
#define DEV_CFG_REGS_CPUSEL0_EPWM11_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL0_EPWM11_Msk) >> DEV_CFG_REGS_CPUSEL0_EPWM11_Pos) /*!< EPWM11 Get Value            */


#define DEV_CFG_REGS_CPUSEL0_EPWM10_Pos    (9U)                                                                                  /*!< EPWM10 Postion   9          */ 
#define DEV_CFG_REGS_CPUSEL0_EPWM10_Msk    (0x1U << DEV_CFG_REGS_CPUSEL0_EPWM10_Pos)                                             /*!< EPWM10 Mask      0x00000200 */
#define DEV_CFG_REGS_CPUSEL0_EPWM10_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL0_EPWM10_Pos) & DEV_CFG_REGS_CPUSEL0_EPWM10_Msk) /*!< EPWM10 Set Value            */
#define DEV_CFG_REGS_CPUSEL0_EPWM10_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL0_EPWM10_Msk) >> DEV_CFG_REGS_CPUSEL0_EPWM10_Pos) /*!< EPWM10 Get Value            */


#define DEV_CFG_REGS_CPUSEL0_EPWM9_Pos    (8U)                                                                                  /*!< EPWM9 Postion   8          */ 
#define DEV_CFG_REGS_CPUSEL0_EPWM9_Msk    (0x1U << DEV_CFG_REGS_CPUSEL0_EPWM9_Pos)                                              /*!< EPWM9 Mask      0x00000100 */
#define DEV_CFG_REGS_CPUSEL0_EPWM9_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL0_EPWM9_Pos) & DEV_CFG_REGS_CPUSEL0_EPWM9_Msk) /*!< EPWM9 Set Value            */
#define DEV_CFG_REGS_CPUSEL0_EPWM9_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL0_EPWM9_Msk) >> DEV_CFG_REGS_CPUSEL0_EPWM9_Pos) /*!< EPWM9 Get Value            */


#define DEV_CFG_REGS_CPUSEL0_EPWM8_Pos    (7U)                                                                                  /*!< EPWM8 Postion   7          */ 
#define DEV_CFG_REGS_CPUSEL0_EPWM8_Msk    (0x1U << DEV_CFG_REGS_CPUSEL0_EPWM8_Pos)                                              /*!< EPWM8 Mask      0x00000080 */
#define DEV_CFG_REGS_CPUSEL0_EPWM8_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL0_EPWM8_Pos) & DEV_CFG_REGS_CPUSEL0_EPWM8_Msk) /*!< EPWM8 Set Value            */
#define DEV_CFG_REGS_CPUSEL0_EPWM8_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL0_EPWM8_Msk) >> DEV_CFG_REGS_CPUSEL0_EPWM8_Pos) /*!< EPWM8 Get Value            */


#define DEV_CFG_REGS_CPUSEL0_EPWM7_Pos    (6U)                                                                                  /*!< EPWM7 Postion   6          */ 
#define DEV_CFG_REGS_CPUSEL0_EPWM7_Msk    (0x1U << DEV_CFG_REGS_CPUSEL0_EPWM7_Pos)                                              /*!< EPWM7 Mask      0x00000040 */
#define DEV_CFG_REGS_CPUSEL0_EPWM7_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL0_EPWM7_Pos) & DEV_CFG_REGS_CPUSEL0_EPWM7_Msk) /*!< EPWM7 Set Value            */
#define DEV_CFG_REGS_CPUSEL0_EPWM7_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL0_EPWM7_Msk) >> DEV_CFG_REGS_CPUSEL0_EPWM7_Pos) /*!< EPWM7 Get Value            */


#define DEV_CFG_REGS_CPUSEL0_EPWM6_Pos    (5U)                                                                                  /*!< EPWM6 Postion   5          */ 
#define DEV_CFG_REGS_CPUSEL0_EPWM6_Msk    (0x1U << DEV_CFG_REGS_CPUSEL0_EPWM6_Pos)                                              /*!< EPWM6 Mask      0x00000020 */
#define DEV_CFG_REGS_CPUSEL0_EPWM6_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL0_EPWM6_Pos) & DEV_CFG_REGS_CPUSEL0_EPWM6_Msk) /*!< EPWM6 Set Value            */
#define DEV_CFG_REGS_CPUSEL0_EPWM6_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL0_EPWM6_Msk) >> DEV_CFG_REGS_CPUSEL0_EPWM6_Pos) /*!< EPWM6 Get Value            */


#define DEV_CFG_REGS_CPUSEL0_EPWM5_Pos    (4U)                                                                                  /*!< EPWM5 Postion   4          */ 
#define DEV_CFG_REGS_CPUSEL0_EPWM5_Msk    (0x1U << DEV_CFG_REGS_CPUSEL0_EPWM5_Pos)                                              /*!< EPWM5 Mask      0x00000010 */
#define DEV_CFG_REGS_CPUSEL0_EPWM5_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL0_EPWM5_Pos) & DEV_CFG_REGS_CPUSEL0_EPWM5_Msk) /*!< EPWM5 Set Value            */
#define DEV_CFG_REGS_CPUSEL0_EPWM5_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL0_EPWM5_Msk) >> DEV_CFG_REGS_CPUSEL0_EPWM5_Pos) /*!< EPWM5 Get Value            */


#define DEV_CFG_REGS_CPUSEL0_EPWM4_Pos    (3U)                                                                                  /*!< EPWM4 Postion   3          */ 
#define DEV_CFG_REGS_CPUSEL0_EPWM4_Msk    (0x1U << DEV_CFG_REGS_CPUSEL0_EPWM4_Pos)                                              /*!< EPWM4 Mask      0x00000008 */
#define DEV_CFG_REGS_CPUSEL0_EPWM4_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL0_EPWM4_Pos) & DEV_CFG_REGS_CPUSEL0_EPWM4_Msk) /*!< EPWM4 Set Value            */
#define DEV_CFG_REGS_CPUSEL0_EPWM4_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL0_EPWM4_Msk) >> DEV_CFG_REGS_CPUSEL0_EPWM4_Pos) /*!< EPWM4 Get Value            */


#define DEV_CFG_REGS_CPUSEL0_EPWM3_Pos    (2U)                                                                                  /*!< EPWM3 Postion   2          */ 
#define DEV_CFG_REGS_CPUSEL0_EPWM3_Msk    (0x1U << DEV_CFG_REGS_CPUSEL0_EPWM3_Pos)                                              /*!< EPWM3 Mask      0x00000004 */
#define DEV_CFG_REGS_CPUSEL0_EPWM3_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL0_EPWM3_Pos) & DEV_CFG_REGS_CPUSEL0_EPWM3_Msk) /*!< EPWM3 Set Value            */
#define DEV_CFG_REGS_CPUSEL0_EPWM3_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL0_EPWM3_Msk) >> DEV_CFG_REGS_CPUSEL0_EPWM3_Pos) /*!< EPWM3 Get Value            */


#define DEV_CFG_REGS_CPUSEL0_EPWM2_Pos    (1U)                                                                                  /*!< EPWM2 Postion   1          */ 
#define DEV_CFG_REGS_CPUSEL0_EPWM2_Msk    (0x1U << DEV_CFG_REGS_CPUSEL0_EPWM2_Pos)                                              /*!< EPWM2 Mask      0x00000002 */
#define DEV_CFG_REGS_CPUSEL0_EPWM2_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL0_EPWM2_Pos) & DEV_CFG_REGS_CPUSEL0_EPWM2_Msk) /*!< EPWM2 Set Value            */
#define DEV_CFG_REGS_CPUSEL0_EPWM2_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL0_EPWM2_Msk) >> DEV_CFG_REGS_CPUSEL0_EPWM2_Pos) /*!< EPWM2 Get Value            */


#define DEV_CFG_REGS_CPUSEL0_EPWM1_Pos    (0U)                                                                                  /*!< EPWM1 Postion   0          */ 
#define DEV_CFG_REGS_CPUSEL0_EPWM1_Msk    (0x1U << DEV_CFG_REGS_CPUSEL0_EPWM1_Pos)                                              /*!< EPWM1 Mask      0x00000001 */
#define DEV_CFG_REGS_CPUSEL0_EPWM1_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL0_EPWM1_Pos) & DEV_CFG_REGS_CPUSEL0_EPWM1_Msk) /*!< EPWM1 Set Value            */
#define DEV_CFG_REGS_CPUSEL0_EPWM1_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL0_EPWM1_Msk) >> DEV_CFG_REGS_CPUSEL0_EPWM1_Pos) /*!< EPWM1 Get Value            */


/* CPUSEL1 bitfield */
#define DEV_CFG_REGS_CPUSEL1_ECAP6_Pos    (5U)                                                                                  /*!< ECAP6 Postion   5          */ 
#define DEV_CFG_REGS_CPUSEL1_ECAP6_Msk    (0x1U << DEV_CFG_REGS_CPUSEL1_ECAP6_Pos)                                              /*!< ECAP6 Mask      0x00000020 */
#define DEV_CFG_REGS_CPUSEL1_ECAP6_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL1_ECAP6_Pos) & DEV_CFG_REGS_CPUSEL1_ECAP6_Msk) /*!< ECAP6 Set Value            */
#define DEV_CFG_REGS_CPUSEL1_ECAP6_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL1_ECAP6_Msk) >> DEV_CFG_REGS_CPUSEL1_ECAP6_Pos) /*!< ECAP6 Get Value            */


#define DEV_CFG_REGS_CPUSEL1_ECAP5_Pos    (4U)                                                                                  /*!< ECAP5 Postion   4          */ 
#define DEV_CFG_REGS_CPUSEL1_ECAP5_Msk    (0x1U << DEV_CFG_REGS_CPUSEL1_ECAP5_Pos)                                              /*!< ECAP5 Mask      0x00000010 */
#define DEV_CFG_REGS_CPUSEL1_ECAP5_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL1_ECAP5_Pos) & DEV_CFG_REGS_CPUSEL1_ECAP5_Msk) /*!< ECAP5 Set Value            */
#define DEV_CFG_REGS_CPUSEL1_ECAP5_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL1_ECAP5_Msk) >> DEV_CFG_REGS_CPUSEL1_ECAP5_Pos) /*!< ECAP5 Get Value            */


#define DEV_CFG_REGS_CPUSEL1_ECAP4_Pos    (3U)                                                                                  /*!< ECAP4 Postion   3          */ 
#define DEV_CFG_REGS_CPUSEL1_ECAP4_Msk    (0x1U << DEV_CFG_REGS_CPUSEL1_ECAP4_Pos)                                              /*!< ECAP4 Mask      0x00000008 */
#define DEV_CFG_REGS_CPUSEL1_ECAP4_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL1_ECAP4_Pos) & DEV_CFG_REGS_CPUSEL1_ECAP4_Msk) /*!< ECAP4 Set Value            */
#define DEV_CFG_REGS_CPUSEL1_ECAP4_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL1_ECAP4_Msk) >> DEV_CFG_REGS_CPUSEL1_ECAP4_Pos) /*!< ECAP4 Get Value            */


#define DEV_CFG_REGS_CPUSEL1_ECAP3_Pos    (2U)                                                                                  /*!< ECAP3 Postion   2          */ 
#define DEV_CFG_REGS_CPUSEL1_ECAP3_Msk    (0x1U << DEV_CFG_REGS_CPUSEL1_ECAP3_Pos)                                              /*!< ECAP3 Mask      0x00000004 */
#define DEV_CFG_REGS_CPUSEL1_ECAP3_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL1_ECAP3_Pos) & DEV_CFG_REGS_CPUSEL1_ECAP3_Msk) /*!< ECAP3 Set Value            */
#define DEV_CFG_REGS_CPUSEL1_ECAP3_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL1_ECAP3_Msk) >> DEV_CFG_REGS_CPUSEL1_ECAP3_Pos) /*!< ECAP3 Get Value            */


#define DEV_CFG_REGS_CPUSEL1_ECAP2_Pos    (1U)                                                                                  /*!< ECAP2 Postion   1          */ 
#define DEV_CFG_REGS_CPUSEL1_ECAP2_Msk    (0x1U << DEV_CFG_REGS_CPUSEL1_ECAP2_Pos)                                              /*!< ECAP2 Mask      0x00000002 */
#define DEV_CFG_REGS_CPUSEL1_ECAP2_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL1_ECAP2_Pos) & DEV_CFG_REGS_CPUSEL1_ECAP2_Msk) /*!< ECAP2 Set Value            */
#define DEV_CFG_REGS_CPUSEL1_ECAP2_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL1_ECAP2_Msk) >> DEV_CFG_REGS_CPUSEL1_ECAP2_Pos) /*!< ECAP2 Get Value            */


#define DEV_CFG_REGS_CPUSEL1_ECAP1_Pos    (0U)                                                                                  /*!< ECAP1 Postion   0          */ 
#define DEV_CFG_REGS_CPUSEL1_ECAP1_Msk    (0x1U << DEV_CFG_REGS_CPUSEL1_ECAP1_Pos)                                              /*!< ECAP1 Mask      0x00000001 */
#define DEV_CFG_REGS_CPUSEL1_ECAP1_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL1_ECAP1_Pos) & DEV_CFG_REGS_CPUSEL1_ECAP1_Msk) /*!< ECAP1 Set Value            */
#define DEV_CFG_REGS_CPUSEL1_ECAP1_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL1_ECAP1_Msk) >> DEV_CFG_REGS_CPUSEL1_ECAP1_Pos) /*!< ECAP1 Get Value            */


/* CPUSEL2 bitfield */
#define DEV_CFG_REGS_CPUSEL2_EQEP3_Pos    (2U)                                                                                  /*!< EQEP3 Postion   2          */ 
#define DEV_CFG_REGS_CPUSEL2_EQEP3_Msk    (0x1U << DEV_CFG_REGS_CPUSEL2_EQEP3_Pos)                                              /*!< EQEP3 Mask      0x00000004 */
#define DEV_CFG_REGS_CPUSEL2_EQEP3_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL2_EQEP3_Pos) & DEV_CFG_REGS_CPUSEL2_EQEP3_Msk) /*!< EQEP3 Set Value            */
#define DEV_CFG_REGS_CPUSEL2_EQEP3_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL2_EQEP3_Msk) >> DEV_CFG_REGS_CPUSEL2_EQEP3_Pos) /*!< EQEP3 Get Value            */


#define DEV_CFG_REGS_CPUSEL2_EQEP2_Pos    (1U)                                                                                  /*!< EQEP2 Postion   1          */ 
#define DEV_CFG_REGS_CPUSEL2_EQEP2_Msk    (0x1U << DEV_CFG_REGS_CPUSEL2_EQEP2_Pos)                                              /*!< EQEP2 Mask      0x00000002 */
#define DEV_CFG_REGS_CPUSEL2_EQEP2_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL2_EQEP2_Pos) & DEV_CFG_REGS_CPUSEL2_EQEP2_Msk) /*!< EQEP2 Set Value            */
#define DEV_CFG_REGS_CPUSEL2_EQEP2_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL2_EQEP2_Msk) >> DEV_CFG_REGS_CPUSEL2_EQEP2_Pos) /*!< EQEP2 Get Value            */


#define DEV_CFG_REGS_CPUSEL2_EQEP1_Pos    (0U)                                                                                  /*!< EQEP1 Postion   0          */ 
#define DEV_CFG_REGS_CPUSEL2_EQEP1_Msk    (0x1U << DEV_CFG_REGS_CPUSEL2_EQEP1_Pos)                                              /*!< EQEP1 Mask      0x00000001 */
#define DEV_CFG_REGS_CPUSEL2_EQEP1_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL2_EQEP1_Pos) & DEV_CFG_REGS_CPUSEL2_EQEP1_Msk) /*!< EQEP1 Set Value            */
#define DEV_CFG_REGS_CPUSEL2_EQEP1_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL2_EQEP1_Msk) >> DEV_CFG_REGS_CPUSEL2_EQEP1_Pos) /*!< EQEP1 Get Value            */


/* CPUSEL4 bitfield */
#define DEV_CFG_REGS_CPUSEL4_SD2_Pos    (1U)                                                                                  /*!< SD2 Postion   1          */ 
#define DEV_CFG_REGS_CPUSEL4_SD2_Msk    (0x1U << DEV_CFG_REGS_CPUSEL4_SD2_Pos)                                                /*!< SD2 Mask      0x00000002 */
#define DEV_CFG_REGS_CPUSEL4_SD2_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL4_SD2_Pos) & DEV_CFG_REGS_CPUSEL4_SD2_Msk)     /*!< SD2 Set Value            */
#define DEV_CFG_REGS_CPUSEL4_SD2_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL4_SD2_Msk) >> DEV_CFG_REGS_CPUSEL4_SD2_Pos)     /*!< SD2 Get Value            */


#define DEV_CFG_REGS_CPUSEL4_SD1_Pos    (0U)                                                                                  /*!< SD1 Postion   0          */ 
#define DEV_CFG_REGS_CPUSEL4_SD1_Msk    (0x1U << DEV_CFG_REGS_CPUSEL4_SD1_Pos)                                                /*!< SD1 Mask      0x00000001 */
#define DEV_CFG_REGS_CPUSEL4_SD1_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL4_SD1_Pos) & DEV_CFG_REGS_CPUSEL4_SD1_Msk)     /*!< SD1 Set Value            */
#define DEV_CFG_REGS_CPUSEL4_SD1_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL4_SD1_Msk) >> DEV_CFG_REGS_CPUSEL4_SD1_Pos)     /*!< SD1 Get Value            */


/* CPUSEL5 bitfield */
#define DEV_CFG_REGS_CPUSEL5_SCI_D_Pos    (3U)                                                                                  /*!< SCI_D Postion   3          */ 
#define DEV_CFG_REGS_CPUSEL5_SCI_D_Msk    (0x1U << DEV_CFG_REGS_CPUSEL5_SCI_D_Pos)                                              /*!< SCI_D Mask      0x00000008 */
#define DEV_CFG_REGS_CPUSEL5_SCI_D_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL5_SCI_D_Pos) & DEV_CFG_REGS_CPUSEL5_SCI_D_Msk) /*!< SCI_D Set Value            */
#define DEV_CFG_REGS_CPUSEL5_SCI_D_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL5_SCI_D_Msk) >> DEV_CFG_REGS_CPUSEL5_SCI_D_Pos) /*!< SCI_D Get Value            */


#define DEV_CFG_REGS_CPUSEL5_SCI_C_Pos    (2U)                                                                                  /*!< SCI_C Postion   2          */ 
#define DEV_CFG_REGS_CPUSEL5_SCI_C_Msk    (0x1U << DEV_CFG_REGS_CPUSEL5_SCI_C_Pos)                                              /*!< SCI_C Mask      0x00000004 */
#define DEV_CFG_REGS_CPUSEL5_SCI_C_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL5_SCI_C_Pos) & DEV_CFG_REGS_CPUSEL5_SCI_C_Msk) /*!< SCI_C Set Value            */
#define DEV_CFG_REGS_CPUSEL5_SCI_C_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL5_SCI_C_Msk) >> DEV_CFG_REGS_CPUSEL5_SCI_C_Pos) /*!< SCI_C Get Value            */


#define DEV_CFG_REGS_CPUSEL5_SCI_B_Pos    (1U)                                                                                  /*!< SCI_B Postion   1          */ 
#define DEV_CFG_REGS_CPUSEL5_SCI_B_Msk    (0x1U << DEV_CFG_REGS_CPUSEL5_SCI_B_Pos)                                              /*!< SCI_B Mask      0x00000002 */
#define DEV_CFG_REGS_CPUSEL5_SCI_B_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL5_SCI_B_Pos) & DEV_CFG_REGS_CPUSEL5_SCI_B_Msk) /*!< SCI_B Set Value            */
#define DEV_CFG_REGS_CPUSEL5_SCI_B_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL5_SCI_B_Msk) >> DEV_CFG_REGS_CPUSEL5_SCI_B_Pos) /*!< SCI_B Get Value            */


#define DEV_CFG_REGS_CPUSEL5_SCI_A_Pos    (0U)                                                                                  /*!< SCI_A Postion   0          */ 
#define DEV_CFG_REGS_CPUSEL5_SCI_A_Msk    (0x1U << DEV_CFG_REGS_CPUSEL5_SCI_A_Pos)                                              /*!< SCI_A Mask      0x00000001 */
#define DEV_CFG_REGS_CPUSEL5_SCI_A_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL5_SCI_A_Pos) & DEV_CFG_REGS_CPUSEL5_SCI_A_Msk) /*!< SCI_A Set Value            */
#define DEV_CFG_REGS_CPUSEL5_SCI_A_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL5_SCI_A_Msk) >> DEV_CFG_REGS_CPUSEL5_SCI_A_Pos) /*!< SCI_A Get Value            */


/* CPUSEL6 bitfield */
#define DEV_CFG_REGS_CPUSEL6_SPI_C_Pos    (2U)                                                                                  /*!< SPI_C Postion   2          */ 
#define DEV_CFG_REGS_CPUSEL6_SPI_C_Msk    (0x1U << DEV_CFG_REGS_CPUSEL6_SPI_C_Pos)                                              /*!< SPI_C Mask      0x00000004 */
#define DEV_CFG_REGS_CPUSEL6_SPI_C_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL6_SPI_C_Pos) & DEV_CFG_REGS_CPUSEL6_SPI_C_Msk) /*!< SPI_C Set Value            */
#define DEV_CFG_REGS_CPUSEL6_SPI_C_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL6_SPI_C_Msk) >> DEV_CFG_REGS_CPUSEL6_SPI_C_Pos) /*!< SPI_C Get Value            */


#define DEV_CFG_REGS_CPUSEL6_SPI_B_Pos    (1U)                                                                                  /*!< SPI_B Postion   1          */ 
#define DEV_CFG_REGS_CPUSEL6_SPI_B_Msk    (0x1U << DEV_CFG_REGS_CPUSEL6_SPI_B_Pos)                                              /*!< SPI_B Mask      0x00000002 */
#define DEV_CFG_REGS_CPUSEL6_SPI_B_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL6_SPI_B_Pos) & DEV_CFG_REGS_CPUSEL6_SPI_B_Msk) /*!< SPI_B Set Value            */
#define DEV_CFG_REGS_CPUSEL6_SPI_B_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL6_SPI_B_Msk) >> DEV_CFG_REGS_CPUSEL6_SPI_B_Pos) /*!< SPI_B Get Value            */


#define DEV_CFG_REGS_CPUSEL6_SPI_A_Pos    (0U)                                                                                  /*!< SPI_A Postion   0          */ 
#define DEV_CFG_REGS_CPUSEL6_SPI_A_Msk    (0x1U << DEV_CFG_REGS_CPUSEL6_SPI_A_Pos)                                              /*!< SPI_A Mask      0x00000001 */
#define DEV_CFG_REGS_CPUSEL6_SPI_A_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL6_SPI_A_Pos) & DEV_CFG_REGS_CPUSEL6_SPI_A_Msk) /*!< SPI_A Set Value            */
#define DEV_CFG_REGS_CPUSEL6_SPI_A_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL6_SPI_A_Msk) >> DEV_CFG_REGS_CPUSEL6_SPI_A_Pos) /*!< SPI_A Get Value            */


/* CPUSEL7 bitfield */
#define DEV_CFG_REGS_CPUSEL7_PMBUS_A_Pos    (16U)                                                                                 /*!< PMBUS_A Postion   16         */ 
#define DEV_CFG_REGS_CPUSEL7_PMBUS_A_Msk    (0x1U << DEV_CFG_REGS_CPUSEL7_PMBUS_A_Pos)                                            /*!< PMBUS_A Mask      0x00010000 */
#define DEV_CFG_REGS_CPUSEL7_PMBUS_A_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL7_PMBUS_A_Pos) & DEV_CFG_REGS_CPUSEL7_PMBUS_A_Msk) /*!< PMBUS_A Set Value            */
#define DEV_CFG_REGS_CPUSEL7_PMBUS_A_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL7_PMBUS_A_Msk) >> DEV_CFG_REGS_CPUSEL7_PMBUS_A_Pos) /*!< PMBUS_A Get Value            */


#define DEV_CFG_REGS_CPUSEL7_I2C_B_Pos    (1U)                                                                                  /*!< I2C_B Postion   1          */ 
#define DEV_CFG_REGS_CPUSEL7_I2C_B_Msk    (0x1U << DEV_CFG_REGS_CPUSEL7_I2C_B_Pos)                                              /*!< I2C_B Mask      0x00000002 */
#define DEV_CFG_REGS_CPUSEL7_I2C_B_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL7_I2C_B_Pos) & DEV_CFG_REGS_CPUSEL7_I2C_B_Msk) /*!< I2C_B Set Value            */
#define DEV_CFG_REGS_CPUSEL7_I2C_B_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL7_I2C_B_Msk) >> DEV_CFG_REGS_CPUSEL7_I2C_B_Pos) /*!< I2C_B Get Value            */


#define DEV_CFG_REGS_CPUSEL7_I2C_A_Pos    (0U)                                                                                  /*!< I2C_A Postion   0          */ 
#define DEV_CFG_REGS_CPUSEL7_I2C_A_Msk    (0x1U << DEV_CFG_REGS_CPUSEL7_I2C_A_Pos)                                              /*!< I2C_A Mask      0x00000001 */
#define DEV_CFG_REGS_CPUSEL7_I2C_A_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL7_I2C_A_Pos) & DEV_CFG_REGS_CPUSEL7_I2C_A_Msk) /*!< I2C_A Set Value            */
#define DEV_CFG_REGS_CPUSEL7_I2C_A_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL7_I2C_A_Msk) >> DEV_CFG_REGS_CPUSEL7_I2C_A_Pos) /*!< I2C_A Get Value            */


/* CPUSEL8 bitfield */
#define DEV_CFG_REGS_CPUSEL8_USB_A_Pos    (16U)                                                                                 /*!< USB_A Postion   16         */ 
#define DEV_CFG_REGS_CPUSEL8_USB_A_Msk    (0x1U << DEV_CFG_REGS_CPUSEL8_USB_A_Pos)                                              /*!< USB_A Mask      0x00010000 */
#define DEV_CFG_REGS_CPUSEL8_USB_A_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL8_USB_A_Pos) & DEV_CFG_REGS_CPUSEL8_USB_A_Msk) /*!< USB_A Set Value            */
#define DEV_CFG_REGS_CPUSEL8_USB_A_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL8_USB_A_Msk) >> DEV_CFG_REGS_CPUSEL8_USB_A_Pos) /*!< USB_A Get Value            */


#define DEV_CFG_REGS_CPUSEL8_CAN_C_Pos    (2U)                                                                                  /*!< CAN_C Postion   2          */ 
#define DEV_CFG_REGS_CPUSEL8_CAN_C_Msk    (0x1U << DEV_CFG_REGS_CPUSEL8_CAN_C_Pos)                                              /*!< CAN_C Mask      0x00000004 */
#define DEV_CFG_REGS_CPUSEL8_CAN_C_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL8_CAN_C_Pos) & DEV_CFG_REGS_CPUSEL8_CAN_C_Msk) /*!< CAN_C Set Value            */
#define DEV_CFG_REGS_CPUSEL8_CAN_C_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL8_CAN_C_Msk) >> DEV_CFG_REGS_CPUSEL8_CAN_C_Pos) /*!< CAN_C Get Value            */


#define DEV_CFG_REGS_CPUSEL8_CAN_B_Pos    (1U)                                                                                  /*!< CAN_B Postion   1          */ 
#define DEV_CFG_REGS_CPUSEL8_CAN_B_Msk    (0x1U << DEV_CFG_REGS_CPUSEL8_CAN_B_Pos)                                              /*!< CAN_B Mask      0x00000002 */
#define DEV_CFG_REGS_CPUSEL8_CAN_B_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL8_CAN_B_Pos) & DEV_CFG_REGS_CPUSEL8_CAN_B_Msk) /*!< CAN_B Set Value            */
#define DEV_CFG_REGS_CPUSEL8_CAN_B_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL8_CAN_B_Msk) >> DEV_CFG_REGS_CPUSEL8_CAN_B_Pos) /*!< CAN_B Get Value            */


#define DEV_CFG_REGS_CPUSEL8_CAN_A_Pos    (0U)                                                                                  /*!< CAN_A Postion   0          */ 
#define DEV_CFG_REGS_CPUSEL8_CAN_A_Msk    (0x1U << DEV_CFG_REGS_CPUSEL8_CAN_A_Pos)                                              /*!< CAN_A Mask      0x00000001 */
#define DEV_CFG_REGS_CPUSEL8_CAN_A_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL8_CAN_A_Pos) & DEV_CFG_REGS_CPUSEL8_CAN_A_Msk) /*!< CAN_A Set Value            */
#define DEV_CFG_REGS_CPUSEL8_CAN_A_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL8_CAN_A_Msk) >> DEV_CFG_REGS_CPUSEL8_CAN_A_Pos) /*!< CAN_A Get Value            */


/* CPUSEL11 bitfield */
#define DEV_CFG_REGS_CPUSEL11_ADC_D_Pos    (3U)                                                                                  /*!< ADC_D Postion   3          */ 
#define DEV_CFG_REGS_CPUSEL11_ADC_D_Msk    (0x1U << DEV_CFG_REGS_CPUSEL11_ADC_D_Pos)                                             /*!< ADC_D Mask      0x00000008 */
#define DEV_CFG_REGS_CPUSEL11_ADC_D_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL11_ADC_D_Pos) & DEV_CFG_REGS_CPUSEL11_ADC_D_Msk) /*!< ADC_D Set Value            */
#define DEV_CFG_REGS_CPUSEL11_ADC_D_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL11_ADC_D_Msk) >> DEV_CFG_REGS_CPUSEL11_ADC_D_Pos) /*!< ADC_D Get Value            */


#define DEV_CFG_REGS_CPUSEL11_ADC_C_Pos    (2U)                                                                                  /*!< ADC_C Postion   2          */ 
#define DEV_CFG_REGS_CPUSEL11_ADC_C_Msk    (0x1U << DEV_CFG_REGS_CPUSEL11_ADC_C_Pos)                                             /*!< ADC_C Mask      0x00000004 */
#define DEV_CFG_REGS_CPUSEL11_ADC_C_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL11_ADC_C_Pos) & DEV_CFG_REGS_CPUSEL11_ADC_C_Msk) /*!< ADC_C Set Value            */
#define DEV_CFG_REGS_CPUSEL11_ADC_C_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL11_ADC_C_Msk) >> DEV_CFG_REGS_CPUSEL11_ADC_C_Pos) /*!< ADC_C Get Value            */


#define DEV_CFG_REGS_CPUSEL11_ADC_B_Pos    (1U)                                                                                  /*!< ADC_B Postion   1          */ 
#define DEV_CFG_REGS_CPUSEL11_ADC_B_Msk    (0x1U << DEV_CFG_REGS_CPUSEL11_ADC_B_Pos)                                             /*!< ADC_B Mask      0x00000002 */
#define DEV_CFG_REGS_CPUSEL11_ADC_B_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL11_ADC_B_Pos) & DEV_CFG_REGS_CPUSEL11_ADC_B_Msk) /*!< ADC_B Set Value            */
#define DEV_CFG_REGS_CPUSEL11_ADC_B_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL11_ADC_B_Msk) >> DEV_CFG_REGS_CPUSEL11_ADC_B_Pos) /*!< ADC_B Get Value            */


#define DEV_CFG_REGS_CPUSEL11_ADC_A_Pos    (0U)                                                                                  /*!< ADC_A Postion   0          */ 
#define DEV_CFG_REGS_CPUSEL11_ADC_A_Msk    (0x1U << DEV_CFG_REGS_CPUSEL11_ADC_A_Pos)                                             /*!< ADC_A Mask      0x00000001 */
#define DEV_CFG_REGS_CPUSEL11_ADC_A_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL11_ADC_A_Pos) & DEV_CFG_REGS_CPUSEL11_ADC_A_Msk) /*!< ADC_A Set Value            */
#define DEV_CFG_REGS_CPUSEL11_ADC_A_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL11_ADC_A_Msk) >> DEV_CFG_REGS_CPUSEL11_ADC_A_Pos) /*!< ADC_A Get Value            */


/* CPUSEL12 bitfield */
#define DEV_CFG_REGS_CPUSEL12_CMPSS8_Pos    (7U)                                                                                  /*!< CMPSS8 Postion   7          */ 
#define DEV_CFG_REGS_CPUSEL12_CMPSS8_Msk    (0x1U << DEV_CFG_REGS_CPUSEL12_CMPSS8_Pos)                                            /*!< CMPSS8 Mask      0x00000080 */
#define DEV_CFG_REGS_CPUSEL12_CMPSS8_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL12_CMPSS8_Pos) & DEV_CFG_REGS_CPUSEL12_CMPSS8_Msk) /*!< CMPSS8 Set Value            */
#define DEV_CFG_REGS_CPUSEL12_CMPSS8_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL12_CMPSS8_Msk) >> DEV_CFG_REGS_CPUSEL12_CMPSS8_Pos) /*!< CMPSS8 Get Value            */


#define DEV_CFG_REGS_CPUSEL12_CMPSS7_Pos    (6U)                                                                                  /*!< CMPSS7 Postion   6          */ 
#define DEV_CFG_REGS_CPUSEL12_CMPSS7_Msk    (0x1U << DEV_CFG_REGS_CPUSEL12_CMPSS7_Pos)                                            /*!< CMPSS7 Mask      0x00000040 */
#define DEV_CFG_REGS_CPUSEL12_CMPSS7_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL12_CMPSS7_Pos) & DEV_CFG_REGS_CPUSEL12_CMPSS7_Msk) /*!< CMPSS7 Set Value            */
#define DEV_CFG_REGS_CPUSEL12_CMPSS7_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL12_CMPSS7_Msk) >> DEV_CFG_REGS_CPUSEL12_CMPSS7_Pos) /*!< CMPSS7 Get Value            */


#define DEV_CFG_REGS_CPUSEL12_CMPSS6_Pos    (5U)                                                                                  /*!< CMPSS6 Postion   5          */ 
#define DEV_CFG_REGS_CPUSEL12_CMPSS6_Msk    (0x1U << DEV_CFG_REGS_CPUSEL12_CMPSS6_Pos)                                            /*!< CMPSS6 Mask      0x00000020 */
#define DEV_CFG_REGS_CPUSEL12_CMPSS6_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL12_CMPSS6_Pos) & DEV_CFG_REGS_CPUSEL12_CMPSS6_Msk) /*!< CMPSS6 Set Value            */
#define DEV_CFG_REGS_CPUSEL12_CMPSS6_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL12_CMPSS6_Msk) >> DEV_CFG_REGS_CPUSEL12_CMPSS6_Pos) /*!< CMPSS6 Get Value            */


#define DEV_CFG_REGS_CPUSEL12_CMPSS5_Pos    (4U)                                                                                  /*!< CMPSS5 Postion   4          */ 
#define DEV_CFG_REGS_CPUSEL12_CMPSS5_Msk    (0x1U << DEV_CFG_REGS_CPUSEL12_CMPSS5_Pos)                                            /*!< CMPSS5 Mask      0x00000010 */
#define DEV_CFG_REGS_CPUSEL12_CMPSS5_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL12_CMPSS5_Pos) & DEV_CFG_REGS_CPUSEL12_CMPSS5_Msk) /*!< CMPSS5 Set Value            */
#define DEV_CFG_REGS_CPUSEL12_CMPSS5_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL12_CMPSS5_Msk) >> DEV_CFG_REGS_CPUSEL12_CMPSS5_Pos) /*!< CMPSS5 Get Value            */


#define DEV_CFG_REGS_CPUSEL12_CMPSS4_Pos    (3U)                                                                                  /*!< CMPSS4 Postion   3          */ 
#define DEV_CFG_REGS_CPUSEL12_CMPSS4_Msk    (0x1U << DEV_CFG_REGS_CPUSEL12_CMPSS4_Pos)                                            /*!< CMPSS4 Mask      0x00000008 */
#define DEV_CFG_REGS_CPUSEL12_CMPSS4_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL12_CMPSS4_Pos) & DEV_CFG_REGS_CPUSEL12_CMPSS4_Msk) /*!< CMPSS4 Set Value            */
#define DEV_CFG_REGS_CPUSEL12_CMPSS4_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL12_CMPSS4_Msk) >> DEV_CFG_REGS_CPUSEL12_CMPSS4_Pos) /*!< CMPSS4 Get Value            */


#define DEV_CFG_REGS_CPUSEL12_CMPSS3_Pos    (2U)                                                                                  /*!< CMPSS3 Postion   2          */ 
#define DEV_CFG_REGS_CPUSEL12_CMPSS3_Msk    (0x1U << DEV_CFG_REGS_CPUSEL12_CMPSS3_Pos)                                            /*!< CMPSS3 Mask      0x00000004 */
#define DEV_CFG_REGS_CPUSEL12_CMPSS3_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL12_CMPSS3_Pos) & DEV_CFG_REGS_CPUSEL12_CMPSS3_Msk) /*!< CMPSS3 Set Value            */
#define DEV_CFG_REGS_CPUSEL12_CMPSS3_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL12_CMPSS3_Msk) >> DEV_CFG_REGS_CPUSEL12_CMPSS3_Pos) /*!< CMPSS3 Get Value            */


#define DEV_CFG_REGS_CPUSEL12_CMPSS2_Pos    (1U)                                                                                  /*!< CMPSS2 Postion   1          */ 
#define DEV_CFG_REGS_CPUSEL12_CMPSS2_Msk    (0x1U << DEV_CFG_REGS_CPUSEL12_CMPSS2_Pos)                                            /*!< CMPSS2 Mask      0x00000002 */
#define DEV_CFG_REGS_CPUSEL12_CMPSS2_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL12_CMPSS2_Pos) & DEV_CFG_REGS_CPUSEL12_CMPSS2_Msk) /*!< CMPSS2 Set Value            */
#define DEV_CFG_REGS_CPUSEL12_CMPSS2_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL12_CMPSS2_Msk) >> DEV_CFG_REGS_CPUSEL12_CMPSS2_Pos) /*!< CMPSS2 Get Value            */


#define DEV_CFG_REGS_CPUSEL12_CMPSS1_Pos    (0U)                                                                                  /*!< CMPSS1 Postion   0          */ 
#define DEV_CFG_REGS_CPUSEL12_CMPSS1_Msk    (0x1U << DEV_CFG_REGS_CPUSEL12_CMPSS1_Pos)                                            /*!< CMPSS1 Mask      0x00000001 */
#define DEV_CFG_REGS_CPUSEL12_CMPSS1_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL12_CMPSS1_Pos) & DEV_CFG_REGS_CPUSEL12_CMPSS1_Msk) /*!< CMPSS1 Set Value            */
#define DEV_CFG_REGS_CPUSEL12_CMPSS1_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL12_CMPSS1_Msk) >> DEV_CFG_REGS_CPUSEL12_CMPSS1_Pos) /*!< CMPSS1 Get Value            */


/* CPUSEL14 bitfield */
#define DEV_CFG_REGS_CPUSEL14_DAC_C_Pos    (18U)                                                                                 /*!< DAC_C Postion   18         */ 
#define DEV_CFG_REGS_CPUSEL14_DAC_C_Msk    (0x1U << DEV_CFG_REGS_CPUSEL14_DAC_C_Pos)                                             /*!< DAC_C Mask      0x00040000 */
#define DEV_CFG_REGS_CPUSEL14_DAC_C_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL14_DAC_C_Pos) & DEV_CFG_REGS_CPUSEL14_DAC_C_Msk) /*!< DAC_C Set Value            */
#define DEV_CFG_REGS_CPUSEL14_DAC_C_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL14_DAC_C_Msk) >> DEV_CFG_REGS_CPUSEL14_DAC_C_Pos) /*!< DAC_C Get Value            */


#define DEV_CFG_REGS_CPUSEL14_DAC_B_Pos    (17U)                                                                                 /*!< DAC_B Postion   17         */ 
#define DEV_CFG_REGS_CPUSEL14_DAC_B_Msk    (0x1U << DEV_CFG_REGS_CPUSEL14_DAC_B_Pos)                                             /*!< DAC_B Mask      0x00020000 */
#define DEV_CFG_REGS_CPUSEL14_DAC_B_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL14_DAC_B_Pos) & DEV_CFG_REGS_CPUSEL14_DAC_B_Msk) /*!< DAC_B Set Value            */
#define DEV_CFG_REGS_CPUSEL14_DAC_B_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL14_DAC_B_Msk) >> DEV_CFG_REGS_CPUSEL14_DAC_B_Pos) /*!< DAC_B Get Value            */


#define DEV_CFG_REGS_CPUSEL14_DAC_A_Pos    (16U)                                                                                 /*!< DAC_A Postion   16         */ 
#define DEV_CFG_REGS_CPUSEL14_DAC_A_Msk    (0x1U << DEV_CFG_REGS_CPUSEL14_DAC_A_Pos)                                             /*!< DAC_A Mask      0x00010000 */
#define DEV_CFG_REGS_CPUSEL14_DAC_A_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL14_DAC_A_Pos) & DEV_CFG_REGS_CPUSEL14_DAC_A_Msk) /*!< DAC_A Set Value            */
#define DEV_CFG_REGS_CPUSEL14_DAC_A_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL14_DAC_A_Msk) >> DEV_CFG_REGS_CPUSEL14_DAC_A_Pos) /*!< DAC_A Get Value            */


/* CPUSEL15 bitfield */
#define DEV_CFG_REGS_CPUSEL15_CLB8_Pos    (7U)                                                                                  /*!< CLB8 Postion   7          */ 
#define DEV_CFG_REGS_CPUSEL15_CLB8_Msk    (0x1U << DEV_CFG_REGS_CPUSEL15_CLB8_Pos)                                              /*!< CLB8 Mask      0x00000080 */
#define DEV_CFG_REGS_CPUSEL15_CLB8_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL15_CLB8_Pos) & DEV_CFG_REGS_CPUSEL15_CLB8_Msk) /*!< CLB8 Set Value            */
#define DEV_CFG_REGS_CPUSEL15_CLB8_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL15_CLB8_Msk) >> DEV_CFG_REGS_CPUSEL15_CLB8_Pos) /*!< CLB8 Get Value            */


#define DEV_CFG_REGS_CPUSEL15_CLB7_Pos    (6U)                                                                                  /*!< CLB7 Postion   6          */ 
#define DEV_CFG_REGS_CPUSEL15_CLB7_Msk    (0x1U << DEV_CFG_REGS_CPUSEL15_CLB7_Pos)                                              /*!< CLB7 Mask      0x00000040 */
#define DEV_CFG_REGS_CPUSEL15_CLB7_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL15_CLB7_Pos) & DEV_CFG_REGS_CPUSEL15_CLB7_Msk) /*!< CLB7 Set Value            */
#define DEV_CFG_REGS_CPUSEL15_CLB7_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL15_CLB7_Msk) >> DEV_CFG_REGS_CPUSEL15_CLB7_Pos) /*!< CLB7 Get Value            */


#define DEV_CFG_REGS_CPUSEL15_CLB6_Pos    (5U)                                                                                  /*!< CLB6 Postion   5          */ 
#define DEV_CFG_REGS_CPUSEL15_CLB6_Msk    (0x1U << DEV_CFG_REGS_CPUSEL15_CLB6_Pos)                                              /*!< CLB6 Mask      0x00000020 */
#define DEV_CFG_REGS_CPUSEL15_CLB6_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL15_CLB6_Pos) & DEV_CFG_REGS_CPUSEL15_CLB6_Msk) /*!< CLB6 Set Value            */
#define DEV_CFG_REGS_CPUSEL15_CLB6_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL15_CLB6_Msk) >> DEV_CFG_REGS_CPUSEL15_CLB6_Pos) /*!< CLB6 Get Value            */


#define DEV_CFG_REGS_CPUSEL15_CLB5_Pos    (4U)                                                                                  /*!< CLB5 Postion   4          */ 
#define DEV_CFG_REGS_CPUSEL15_CLB5_Msk    (0x1U << DEV_CFG_REGS_CPUSEL15_CLB5_Pos)                                              /*!< CLB5 Mask      0x00000010 */
#define DEV_CFG_REGS_CPUSEL15_CLB5_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL15_CLB5_Pos) & DEV_CFG_REGS_CPUSEL15_CLB5_Msk) /*!< CLB5 Set Value            */
#define DEV_CFG_REGS_CPUSEL15_CLB5_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL15_CLB5_Msk) >> DEV_CFG_REGS_CPUSEL15_CLB5_Pos) /*!< CLB5 Get Value            */


#define DEV_CFG_REGS_CPUSEL15_CLB4_Pos    (3U)                                                                                  /*!< CLB4 Postion   3          */ 
#define DEV_CFG_REGS_CPUSEL15_CLB4_Msk    (0x1U << DEV_CFG_REGS_CPUSEL15_CLB4_Pos)                                              /*!< CLB4 Mask      0x00000008 */
#define DEV_CFG_REGS_CPUSEL15_CLB4_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL15_CLB4_Pos) & DEV_CFG_REGS_CPUSEL15_CLB4_Msk) /*!< CLB4 Set Value            */
#define DEV_CFG_REGS_CPUSEL15_CLB4_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL15_CLB4_Msk) >> DEV_CFG_REGS_CPUSEL15_CLB4_Pos) /*!< CLB4 Get Value            */


#define DEV_CFG_REGS_CPUSEL15_CLB3_Pos    (2U)                                                                                  /*!< CLB3 Postion   2          */ 
#define DEV_CFG_REGS_CPUSEL15_CLB3_Msk    (0x1U << DEV_CFG_REGS_CPUSEL15_CLB3_Pos)                                              /*!< CLB3 Mask      0x00000004 */
#define DEV_CFG_REGS_CPUSEL15_CLB3_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL15_CLB3_Pos) & DEV_CFG_REGS_CPUSEL15_CLB3_Msk) /*!< CLB3 Set Value            */
#define DEV_CFG_REGS_CPUSEL15_CLB3_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL15_CLB3_Msk) >> DEV_CFG_REGS_CPUSEL15_CLB3_Pos) /*!< CLB3 Get Value            */


#define DEV_CFG_REGS_CPUSEL15_CLB2_Pos    (1U)                                                                                  /*!< CLB2 Postion   1          */ 
#define DEV_CFG_REGS_CPUSEL15_CLB2_Msk    (0x1U << DEV_CFG_REGS_CPUSEL15_CLB2_Pos)                                              /*!< CLB2 Mask      0x00000002 */
#define DEV_CFG_REGS_CPUSEL15_CLB2_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL15_CLB2_Pos) & DEV_CFG_REGS_CPUSEL15_CLB2_Msk) /*!< CLB2 Set Value            */
#define DEV_CFG_REGS_CPUSEL15_CLB2_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL15_CLB2_Msk) >> DEV_CFG_REGS_CPUSEL15_CLB2_Pos) /*!< CLB2 Get Value            */


#define DEV_CFG_REGS_CPUSEL15_CLB1_Pos    (0U)                                                                                  /*!< CLB1 Postion   0          */ 
#define DEV_CFG_REGS_CPUSEL15_CLB1_Msk    (0x1U << DEV_CFG_REGS_CPUSEL15_CLB1_Pos)                                              /*!< CLB1 Mask      0x00000001 */
#define DEV_CFG_REGS_CPUSEL15_CLB1_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPUSEL15_CLB1_Pos) & DEV_CFG_REGS_CPUSEL15_CLB1_Msk) /*!< CLB1 Set Value            */
#define DEV_CFG_REGS_CPUSEL15_CLB1_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPUSEL15_CLB1_Msk) >> DEV_CFG_REGS_CPUSEL15_CLB1_Pos) /*!< CLB1 Get Value            */


/* CPU2RESCTL bitfield */
#define DEV_CFG_REGS_CPU2RESCTL_KEY_Pos    (16U)                                                                                 /*!< KEY Postion   16         */ 
#define DEV_CFG_REGS_CPU2RESCTL_KEY_Msk    (0xffffU << DEV_CFG_REGS_CPU2RESCTL_KEY_Pos)                                          /*!< KEY Mask      0xFFFF0000 */
#define DEV_CFG_REGS_CPU2RESCTL_KEY_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPU2RESCTL_KEY_Pos) & DEV_CFG_REGS_CPU2RESCTL_KEY_Msk) /*!< KEY Set Value            */
#define DEV_CFG_REGS_CPU2RESCTL_KEY_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPU2RESCTL_KEY_Msk) >> DEV_CFG_REGS_CPU2RESCTL_KEY_Pos) /*!< KEY Get Value            */


#define DEV_CFG_REGS_CPU2RESCTL_CPU2RESET_Pos    (0U)                                                                                  /*!< CPU2RESET Postion   0          */ 
#define DEV_CFG_REGS_CPU2RESCTL_CPU2RESET_Msk    (0x1U << DEV_CFG_REGS_CPU2RESCTL_CPU2RESET_Pos)                                       /*!< CPU2RESET Mask      0x00000001 */
#define DEV_CFG_REGS_CPU2RESCTL_CPU2RESET_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPU2RESCTL_CPU2RESET_Pos) & DEV_CFG_REGS_CPU2RESCTL_CPU2RESET_Msk) /*!< CPU2RESET Set Value            */
#define DEV_CFG_REGS_CPU2RESCTL_CPU2RESET_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPU2RESCTL_CPU2RESET_Msk) >> DEV_CFG_REGS_CPU2RESCTL_CPU2RESET_Pos) /*!< CPU2RESET Get Value            */


/* RSTSTAT bitfield */
#define DEV_CFG_REGS_RSTSTAT_CPU2NMIWDRST_Pos    (1U)                                                                                  /*!< CPU2NMIWDRST Postion   1          */ 
#define DEV_CFG_REGS_RSTSTAT_CPU2NMIWDRST_Msk    (0x1U << DEV_CFG_REGS_RSTSTAT_CPU2NMIWDRST_Pos)                                       /*!< CPU2NMIWDRST Mask      0x00000002 */
#define DEV_CFG_REGS_RSTSTAT_CPU2NMIWDRST_Set(x) (((uint16_t) (x) << DEV_CFG_REGS_RSTSTAT_CPU2NMIWDRST_Pos) & DEV_CFG_REGS_RSTSTAT_CPU2NMIWDRST_Msk) /*!< CPU2NMIWDRST Set Value            */
#define DEV_CFG_REGS_RSTSTAT_CPU2NMIWDRST_Get(x) (((uint16_t) (x) & DEV_CFG_REGS_RSTSTAT_CPU2NMIWDRST_Msk) >> DEV_CFG_REGS_RSTSTAT_CPU2NMIWDRST_Pos) /*!< CPU2NMIWDRST Get Value            */


#define DEV_CFG_REGS_RSTSTAT_CPU2RES_Pos    (0U)                                                                                  /*!< CPU2RES Postion   0          */ 
#define DEV_CFG_REGS_RSTSTAT_CPU2RES_Msk    (0x1U << DEV_CFG_REGS_RSTSTAT_CPU2RES_Pos)                                            /*!< CPU2RES Mask      0x00000001 */
#define DEV_CFG_REGS_RSTSTAT_CPU2RES_Set(x) (((uint16_t) (x) << DEV_CFG_REGS_RSTSTAT_CPU2RES_Pos) & DEV_CFG_REGS_RSTSTAT_CPU2RES_Msk) /*!< CPU2RES Set Value            */
#define DEV_CFG_REGS_RSTSTAT_CPU2RES_Get(x) (((uint16_t) (x) & DEV_CFG_REGS_RSTSTAT_CPU2RES_Msk) >> DEV_CFG_REGS_RSTSTAT_CPU2RES_Pos) /*!< CPU2RES Get Value            */


/* LPMSTAT bitfield */
#define DEV_CFG_REGS_LPMSTAT_CPU2LPMSTAT_Pos    (0U)                                                                                  /*!< CPU2LPMSTAT Postion   0          */ 
#define DEV_CFG_REGS_LPMSTAT_CPU2LPMSTAT_Msk    (0x3U << DEV_CFG_REGS_LPMSTAT_CPU2LPMSTAT_Pos)                                        /*!< CPU2LPMSTAT Mask      0x00000003 */
#define DEV_CFG_REGS_LPMSTAT_CPU2LPMSTAT_Set(x) (((uint16_t) (x) << DEV_CFG_REGS_LPMSTAT_CPU2LPMSTAT_Pos) & DEV_CFG_REGS_LPMSTAT_CPU2LPMSTAT_Msk) /*!< CPU2LPMSTAT Set Value            */
#define DEV_CFG_REGS_LPMSTAT_CPU2LPMSTAT_Get(x) (((uint16_t) (x) & DEV_CFG_REGS_LPMSTAT_CPU2LPMSTAT_Msk) >> DEV_CFG_REGS_LPMSTAT_CPU2LPMSTAT_Pos) /*!< CPU2LPMSTAT Get Value            */


/* SYSDBGCTL bitfield */
/* HALT2PERCTRL bitfield */
#define DEV_CFG_REGS_HALT2PERCTRL_HALT2CPU2IPC_Pos    (8U)                                                                                  /*!< HALT2CPU2IPC Postion   8          */ 
#define DEV_CFG_REGS_HALT2PERCTRL_HALT2CPU2IPC_Msk    (0x1U << DEV_CFG_REGS_HALT2PERCTRL_HALT2CPU2IPC_Pos)                                  /*!< HALT2CPU2IPC Mask      0x00000100 */
#define DEV_CFG_REGS_HALT2PERCTRL_HALT2CPU2IPC_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_HALT2PERCTRL_HALT2CPU2IPC_Pos) & DEV_CFG_REGS_HALT2PERCTRL_HALT2CPU2IPC_Msk) /*!< HALT2CPU2IPC Set Value            */
#define DEV_CFG_REGS_HALT2PERCTRL_HALT2CPU2IPC_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_HALT2PERCTRL_HALT2CPU2IPC_Msk) >> DEV_CFG_REGS_HALT2PERCTRL_HALT2CPU2IPC_Pos) /*!< HALT2CPU2IPC Get Value            */


#define DEV_CFG_REGS_HALT2PERCTRL_HALT2CPU1IPC_Pos    (7U)                                                                                  /*!< HALT2CPU1IPC Postion   7          */ 
#define DEV_CFG_REGS_HALT2PERCTRL_HALT2CPU1IPC_Msk    (0x1U << DEV_CFG_REGS_HALT2PERCTRL_HALT2CPU1IPC_Pos)                                  /*!< HALT2CPU1IPC Mask      0x00000080 */
#define DEV_CFG_REGS_HALT2PERCTRL_HALT2CPU1IPC_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_HALT2PERCTRL_HALT2CPU1IPC_Pos) & DEV_CFG_REGS_HALT2PERCTRL_HALT2CPU1IPC_Msk) /*!< HALT2CPU1IPC Set Value            */
#define DEV_CFG_REGS_HALT2PERCTRL_HALT2CPU1IPC_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_HALT2PERCTRL_HALT2CPU1IPC_Msk) >> DEV_CFG_REGS_HALT2PERCTRL_HALT2CPU1IPC_Pos) /*!< HALT2CPU1IPC Get Value            */


#define DEV_CFG_REGS_HALT2PERCTRL_HALT2CMPSS_Pos    (6U)                                                                                  /*!< HALT2CMPSS Postion   6          */ 
#define DEV_CFG_REGS_HALT2PERCTRL_HALT2CMPSS_Msk    (0x1U << DEV_CFG_REGS_HALT2PERCTRL_HALT2CMPSS_Pos)                                    /*!< HALT2CMPSS Mask      0x00000040 */
#define DEV_CFG_REGS_HALT2PERCTRL_HALT2CMPSS_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_HALT2PERCTRL_HALT2CMPSS_Pos) & DEV_CFG_REGS_HALT2PERCTRL_HALT2CMPSS_Msk) /*!< HALT2CMPSS Set Value            */
#define DEV_CFG_REGS_HALT2PERCTRL_HALT2CMPSS_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_HALT2PERCTRL_HALT2CMPSS_Msk) >> DEV_CFG_REGS_HALT2PERCTRL_HALT2CMPSS_Pos) /*!< HALT2CMPSS Get Value            */


#define DEV_CFG_REGS_HALT2PERCTRL_HALT2QEP_Pos    (5U)                                                                                  /*!< HALT2QEP Postion   5          */ 
#define DEV_CFG_REGS_HALT2PERCTRL_HALT2QEP_Msk    (0x1U << DEV_CFG_REGS_HALT2PERCTRL_HALT2QEP_Pos)                                      /*!< HALT2QEP Mask      0x00000020 */
#define DEV_CFG_REGS_HALT2PERCTRL_HALT2QEP_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_HALT2PERCTRL_HALT2QEP_Pos) & DEV_CFG_REGS_HALT2PERCTRL_HALT2QEP_Msk) /*!< HALT2QEP Set Value            */
#define DEV_CFG_REGS_HALT2PERCTRL_HALT2QEP_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_HALT2PERCTRL_HALT2QEP_Msk) >> DEV_CFG_REGS_HALT2PERCTRL_HALT2QEP_Pos) /*!< HALT2QEP Get Value            */


#define DEV_CFG_REGS_HALT2PERCTRL_HALT2CAP_Pos    (4U)                                                                                  /*!< HALT2CAP Postion   4          */ 
#define DEV_CFG_REGS_HALT2PERCTRL_HALT2CAP_Msk    (0x1U << DEV_CFG_REGS_HALT2PERCTRL_HALT2CAP_Pos)                                      /*!< HALT2CAP Mask      0x00000010 */
#define DEV_CFG_REGS_HALT2PERCTRL_HALT2CAP_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_HALT2PERCTRL_HALT2CAP_Pos) & DEV_CFG_REGS_HALT2PERCTRL_HALT2CAP_Msk) /*!< HALT2CAP Set Value            */
#define DEV_CFG_REGS_HALT2PERCTRL_HALT2CAP_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_HALT2PERCTRL_HALT2CAP_Msk) >> DEV_CFG_REGS_HALT2PERCTRL_HALT2CAP_Pos) /*!< HALT2CAP Get Value            */


#define DEV_CFG_REGS_HALT2PERCTRL_HALT2PWM_Pos    (3U)                                                                                  /*!< HALT2PWM Postion   3          */ 
#define DEV_CFG_REGS_HALT2PERCTRL_HALT2PWM_Msk    (0x1U << DEV_CFG_REGS_HALT2PERCTRL_HALT2PWM_Pos)                                      /*!< HALT2PWM Mask      0x00000008 */
#define DEV_CFG_REGS_HALT2PERCTRL_HALT2PWM_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_HALT2PERCTRL_HALT2PWM_Pos) & DEV_CFG_REGS_HALT2PERCTRL_HALT2PWM_Msk) /*!< HALT2PWM Set Value            */
#define DEV_CFG_REGS_HALT2PERCTRL_HALT2PWM_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_HALT2PERCTRL_HALT2PWM_Msk) >> DEV_CFG_REGS_HALT2PERCTRL_HALT2PWM_Pos) /*!< HALT2PWM Get Value            */


#define DEV_CFG_REGS_HALT2PERCTRL_HALT2DMA_Pos    (2U)                                                                                  /*!< HALT2DMA Postion   2          */ 
#define DEV_CFG_REGS_HALT2PERCTRL_HALT2DMA_Msk    (0x1U << DEV_CFG_REGS_HALT2PERCTRL_HALT2DMA_Pos)                                      /*!< HALT2DMA Mask      0x00000004 */
#define DEV_CFG_REGS_HALT2PERCTRL_HALT2DMA_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_HALT2PERCTRL_HALT2DMA_Pos) & DEV_CFG_REGS_HALT2PERCTRL_HALT2DMA_Msk) /*!< HALT2DMA Set Value            */
#define DEV_CFG_REGS_HALT2PERCTRL_HALT2DMA_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_HALT2PERCTRL_HALT2DMA_Msk) >> DEV_CFG_REGS_HALT2PERCTRL_HALT2DMA_Pos) /*!< HALT2DMA Get Value            */


#define DEV_CFG_REGS_HALT2PERCTRL_HALT2TIM_Pos    (1U)                                                                                  /*!< HALT2TIM Postion   1          */ 
#define DEV_CFG_REGS_HALT2PERCTRL_HALT2TIM_Msk    (0x1U << DEV_CFG_REGS_HALT2PERCTRL_HALT2TIM_Pos)                                      /*!< HALT2TIM Mask      0x00000002 */
#define DEV_CFG_REGS_HALT2PERCTRL_HALT2TIM_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_HALT2PERCTRL_HALT2TIM_Pos) & DEV_CFG_REGS_HALT2PERCTRL_HALT2TIM_Msk) /*!< HALT2TIM Set Value            */
#define DEV_CFG_REGS_HALT2PERCTRL_HALT2TIM_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_HALT2PERCTRL_HALT2TIM_Msk) >> DEV_CFG_REGS_HALT2PERCTRL_HALT2TIM_Pos) /*!< HALT2TIM Get Value            */


#define DEV_CFG_REGS_HALT2PERCTRL_HALT2PERBASESEL_Pos    (0U)                                                                                  /*!< HALT2PERBASESEL Postion   0          */ 
#define DEV_CFG_REGS_HALT2PERCTRL_HALT2PERBASESEL_Msk    (0x1U << DEV_CFG_REGS_HALT2PERCTRL_HALT2PERBASESEL_Pos)                               /*!< HALT2PERBASESEL Mask      0x00000001 */
#define DEV_CFG_REGS_HALT2PERCTRL_HALT2PERBASESEL_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_HALT2PERCTRL_HALT2PERBASESEL_Pos) & DEV_CFG_REGS_HALT2PERCTRL_HALT2PERBASESEL_Msk) /*!< HALT2PERBASESEL Set Value            */
#define DEV_CFG_REGS_HALT2PERCTRL_HALT2PERBASESEL_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_HALT2PERCTRL_HALT2PERBASESEL_Msk) >> DEV_CFG_REGS_HALT2PERCTRL_HALT2PERBASESEL_Pos) /*!< HALT2PERBASESEL Get Value            */


/* EFLASH1PROT bitfield */
#define DEV_CFG_REGS_EFLASH1PROT_EFLASH1PROT_Pos    (0U)                                                                                  /*!< EFLASH1PROT Postion   0          */ 
#define DEV_CFG_REGS_EFLASH1PROT_EFLASH1PROT_Msk    (0x1U << DEV_CFG_REGS_EFLASH1PROT_EFLASH1PROT_Pos)                                    /*!< EFLASH1PROT Mask      0x00000001 */
#define DEV_CFG_REGS_EFLASH1PROT_EFLASH1PROT_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_EFLASH1PROT_EFLASH1PROT_Pos) & DEV_CFG_REGS_EFLASH1PROT_EFLASH1PROT_Msk) /*!< EFLASH1PROT Set Value            */
#define DEV_CFG_REGS_EFLASH1PROT_EFLASH1PROT_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_EFLASH1PROT_EFLASH1PROT_Msk) >> DEV_CFG_REGS_EFLASH1PROT_EFLASH1PROT_Pos) /*!< EFLASH1PROT Get Value            */


/* GS_SRAM_CFG0 bitfield */
#define DEV_CFG_REGS_GS_SRAM_CFG0_GS_SRAM1_CFG_Pos    (16U)                                                                                 /*!< GS_SRAM1_CFG Postion   16         */ 
#define DEV_CFG_REGS_GS_SRAM_CFG0_GS_SRAM1_CFG_Msk    (0x7fffU << DEV_CFG_REGS_GS_SRAM_CFG0_GS_SRAM1_CFG_Pos)                               /*!< GS_SRAM1_CFG Mask      0x7FFF0000 */
#define DEV_CFG_REGS_GS_SRAM_CFG0_GS_SRAM1_CFG_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_GS_SRAM_CFG0_GS_SRAM1_CFG_Pos) & DEV_CFG_REGS_GS_SRAM_CFG0_GS_SRAM1_CFG_Msk) /*!< GS_SRAM1_CFG Set Value            */
#define DEV_CFG_REGS_GS_SRAM_CFG0_GS_SRAM1_CFG_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_GS_SRAM_CFG0_GS_SRAM1_CFG_Msk) >> DEV_CFG_REGS_GS_SRAM_CFG0_GS_SRAM1_CFG_Pos) /*!< GS_SRAM1_CFG Get Value            */


#define DEV_CFG_REGS_GS_SRAM_CFG0_GS_SRAM0_CFG_Pos    (0U)                                                                                  /*!< GS_SRAM0_CFG Postion   0          */ 
#define DEV_CFG_REGS_GS_SRAM_CFG0_GS_SRAM0_CFG_Msk    (0x7fffU << DEV_CFG_REGS_GS_SRAM_CFG0_GS_SRAM0_CFG_Pos)                               /*!< GS_SRAM0_CFG Mask      0x00007FFF */
#define DEV_CFG_REGS_GS_SRAM_CFG0_GS_SRAM0_CFG_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_GS_SRAM_CFG0_GS_SRAM0_CFG_Pos) & DEV_CFG_REGS_GS_SRAM_CFG0_GS_SRAM0_CFG_Msk) /*!< GS_SRAM0_CFG Set Value            */
#define DEV_CFG_REGS_GS_SRAM_CFG0_GS_SRAM0_CFG_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_GS_SRAM_CFG0_GS_SRAM0_CFG_Msk) >> DEV_CFG_REGS_GS_SRAM_CFG0_GS_SRAM0_CFG_Pos) /*!< GS_SRAM0_CFG Get Value            */


/* GS_SRAM_CFG1 bitfield */
#define DEV_CFG_REGS_GS_SRAM_CFG1_GS_SRAM3_CFG_Pos    (16U)                                                                                 /*!< GS_SRAM3_CFG Postion   16         */ 
#define DEV_CFG_REGS_GS_SRAM_CFG1_GS_SRAM3_CFG_Msk    (0x7fffU << DEV_CFG_REGS_GS_SRAM_CFG1_GS_SRAM3_CFG_Pos)                               /*!< GS_SRAM3_CFG Mask      0x7FFF0000 */
#define DEV_CFG_REGS_GS_SRAM_CFG1_GS_SRAM3_CFG_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_GS_SRAM_CFG1_GS_SRAM3_CFG_Pos) & DEV_CFG_REGS_GS_SRAM_CFG1_GS_SRAM3_CFG_Msk) /*!< GS_SRAM3_CFG Set Value            */
#define DEV_CFG_REGS_GS_SRAM_CFG1_GS_SRAM3_CFG_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_GS_SRAM_CFG1_GS_SRAM3_CFG_Msk) >> DEV_CFG_REGS_GS_SRAM_CFG1_GS_SRAM3_CFG_Pos) /*!< GS_SRAM3_CFG Get Value            */


#define DEV_CFG_REGS_GS_SRAM_CFG1_GS_SRAM2_CFG_Pos    (0U)                                                                                  /*!< GS_SRAM2_CFG Postion   0          */ 
#define DEV_CFG_REGS_GS_SRAM_CFG1_GS_SRAM2_CFG_Msk    (0x7fffU << DEV_CFG_REGS_GS_SRAM_CFG1_GS_SRAM2_CFG_Pos)                               /*!< GS_SRAM2_CFG Mask      0x00007FFF */
#define DEV_CFG_REGS_GS_SRAM_CFG1_GS_SRAM2_CFG_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_GS_SRAM_CFG1_GS_SRAM2_CFG_Pos) & DEV_CFG_REGS_GS_SRAM_CFG1_GS_SRAM2_CFG_Msk) /*!< GS_SRAM2_CFG Set Value            */
#define DEV_CFG_REGS_GS_SRAM_CFG1_GS_SRAM2_CFG_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_GS_SRAM_CFG1_GS_SRAM2_CFG_Msk) >> DEV_CFG_REGS_GS_SRAM_CFG1_GS_SRAM2_CFG_Pos) /*!< GS_SRAM2_CFG Get Value            */


/* GS_SRAM_CFG2 bitfield */
#define DEV_CFG_REGS_GS_SRAM_CFG2_GS_SRAM5_CFG_Pos    (16U)                                                                                 /*!< GS_SRAM5_CFG Postion   16         */ 
#define DEV_CFG_REGS_GS_SRAM_CFG2_GS_SRAM5_CFG_Msk    (0x7fffU << DEV_CFG_REGS_GS_SRAM_CFG2_GS_SRAM5_CFG_Pos)                               /*!< GS_SRAM5_CFG Mask      0x7FFF0000 */
#define DEV_CFG_REGS_GS_SRAM_CFG2_GS_SRAM5_CFG_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_GS_SRAM_CFG2_GS_SRAM5_CFG_Pos) & DEV_CFG_REGS_GS_SRAM_CFG2_GS_SRAM5_CFG_Msk) /*!< GS_SRAM5_CFG Set Value            */
#define DEV_CFG_REGS_GS_SRAM_CFG2_GS_SRAM5_CFG_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_GS_SRAM_CFG2_GS_SRAM5_CFG_Msk) >> DEV_CFG_REGS_GS_SRAM_CFG2_GS_SRAM5_CFG_Pos) /*!< GS_SRAM5_CFG Get Value            */


#define DEV_CFG_REGS_GS_SRAM_CFG2_GS_SRAM4_CFG_Pos    (0U)                                                                                  /*!< GS_SRAM4_CFG Postion   0          */ 
#define DEV_CFG_REGS_GS_SRAM_CFG2_GS_SRAM4_CFG_Msk    (0x7fffU << DEV_CFG_REGS_GS_SRAM_CFG2_GS_SRAM4_CFG_Pos)                               /*!< GS_SRAM4_CFG Mask      0x00007FFF */
#define DEV_CFG_REGS_GS_SRAM_CFG2_GS_SRAM4_CFG_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_GS_SRAM_CFG2_GS_SRAM4_CFG_Pos) & DEV_CFG_REGS_GS_SRAM_CFG2_GS_SRAM4_CFG_Msk) /*!< GS_SRAM4_CFG Set Value            */
#define DEV_CFG_REGS_GS_SRAM_CFG2_GS_SRAM4_CFG_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_GS_SRAM_CFG2_GS_SRAM4_CFG_Msk) >> DEV_CFG_REGS_GS_SRAM_CFG2_GS_SRAM4_CFG_Pos) /*!< GS_SRAM4_CFG Get Value            */


/* GS_SRAM_CFG3 bitfield */
#define DEV_CFG_REGS_GS_SRAM_CFG3_GS_SRAM7_CFG_Pos    (16U)                                                                                 /*!< GS_SRAM7_CFG Postion   16         */ 
#define DEV_CFG_REGS_GS_SRAM_CFG3_GS_SRAM7_CFG_Msk    (0x7fffU << DEV_CFG_REGS_GS_SRAM_CFG3_GS_SRAM7_CFG_Pos)                               /*!< GS_SRAM7_CFG Mask      0x7FFF0000 */
#define DEV_CFG_REGS_GS_SRAM_CFG3_GS_SRAM7_CFG_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_GS_SRAM_CFG3_GS_SRAM7_CFG_Pos) & DEV_CFG_REGS_GS_SRAM_CFG3_GS_SRAM7_CFG_Msk) /*!< GS_SRAM7_CFG Set Value            */
#define DEV_CFG_REGS_GS_SRAM_CFG3_GS_SRAM7_CFG_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_GS_SRAM_CFG3_GS_SRAM7_CFG_Msk) >> DEV_CFG_REGS_GS_SRAM_CFG3_GS_SRAM7_CFG_Pos) /*!< GS_SRAM7_CFG Get Value            */


#define DEV_CFG_REGS_GS_SRAM_CFG3_GS_SRAM6_CFG_Pos    (0U)                                                                                  /*!< GS_SRAM6_CFG Postion   0          */ 
#define DEV_CFG_REGS_GS_SRAM_CFG3_GS_SRAM6_CFG_Msk    (0x7fffU << DEV_CFG_REGS_GS_SRAM_CFG3_GS_SRAM6_CFG_Pos)                               /*!< GS_SRAM6_CFG Mask      0x00007FFF */
#define DEV_CFG_REGS_GS_SRAM_CFG3_GS_SRAM6_CFG_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_GS_SRAM_CFG3_GS_SRAM6_CFG_Pos) & DEV_CFG_REGS_GS_SRAM_CFG3_GS_SRAM6_CFG_Msk) /*!< GS_SRAM6_CFG Set Value            */
#define DEV_CFG_REGS_GS_SRAM_CFG3_GS_SRAM6_CFG_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_GS_SRAM_CFG3_GS_SRAM6_CFG_Msk) >> DEV_CFG_REGS_GS_SRAM_CFG3_GS_SRAM6_CFG_Pos) /*!< GS_SRAM6_CFG Get Value            */


/* GS_SRAM_CFG4 bitfield */
#define DEV_CFG_REGS_GS_SRAM_CFG4_GS_SRAM9_CFG_Pos    (16U)                                                                                 /*!< GS_SRAM9_CFG Postion   16         */ 
#define DEV_CFG_REGS_GS_SRAM_CFG4_GS_SRAM9_CFG_Msk    (0x7fffU << DEV_CFG_REGS_GS_SRAM_CFG4_GS_SRAM9_CFG_Pos)                               /*!< GS_SRAM9_CFG Mask      0x7FFF0000 */
#define DEV_CFG_REGS_GS_SRAM_CFG4_GS_SRAM9_CFG_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_GS_SRAM_CFG4_GS_SRAM9_CFG_Pos) & DEV_CFG_REGS_GS_SRAM_CFG4_GS_SRAM9_CFG_Msk) /*!< GS_SRAM9_CFG Set Value            */
#define DEV_CFG_REGS_GS_SRAM_CFG4_GS_SRAM9_CFG_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_GS_SRAM_CFG4_GS_SRAM9_CFG_Msk) >> DEV_CFG_REGS_GS_SRAM_CFG4_GS_SRAM9_CFG_Pos) /*!< GS_SRAM9_CFG Get Value            */


#define DEV_CFG_REGS_GS_SRAM_CFG4_GS_SRAM8_CFG_Pos    (0U)                                                                                  /*!< GS_SRAM8_CFG Postion   0          */ 
#define DEV_CFG_REGS_GS_SRAM_CFG4_GS_SRAM8_CFG_Msk    (0x7fffU << DEV_CFG_REGS_GS_SRAM_CFG4_GS_SRAM8_CFG_Pos)                               /*!< GS_SRAM8_CFG Mask      0x00007FFF */
#define DEV_CFG_REGS_GS_SRAM_CFG4_GS_SRAM8_CFG_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_GS_SRAM_CFG4_GS_SRAM8_CFG_Pos) & DEV_CFG_REGS_GS_SRAM_CFG4_GS_SRAM8_CFG_Msk) /*!< GS_SRAM8_CFG Set Value            */
#define DEV_CFG_REGS_GS_SRAM_CFG4_GS_SRAM8_CFG_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_GS_SRAM_CFG4_GS_SRAM8_CFG_Msk) >> DEV_CFG_REGS_GS_SRAM_CFG4_GS_SRAM8_CFG_Pos) /*!< GS_SRAM8_CFG Get Value            */


/* GS_SRAM_CFG5 bitfield */
#define DEV_CFG_REGS_GS_SRAM_CFG5_GS_SRAM11_CFG_Pos    (16U)                                                                                 /*!< GS_SRAM11_CFG Postion   16         */ 
#define DEV_CFG_REGS_GS_SRAM_CFG5_GS_SRAM11_CFG_Msk    (0x7fffU << DEV_CFG_REGS_GS_SRAM_CFG5_GS_SRAM11_CFG_Pos)                              /*!< GS_SRAM11_CFG Mask      0x7FFF0000 */
#define DEV_CFG_REGS_GS_SRAM_CFG5_GS_SRAM11_CFG_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_GS_SRAM_CFG5_GS_SRAM11_CFG_Pos) & DEV_CFG_REGS_GS_SRAM_CFG5_GS_SRAM11_CFG_Msk) /*!< GS_SRAM11_CFG Set Value            */
#define DEV_CFG_REGS_GS_SRAM_CFG5_GS_SRAM11_CFG_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_GS_SRAM_CFG5_GS_SRAM11_CFG_Msk) >> DEV_CFG_REGS_GS_SRAM_CFG5_GS_SRAM11_CFG_Pos) /*!< GS_SRAM11_CFG Get Value            */


#define DEV_CFG_REGS_GS_SRAM_CFG5_GS_SRAM10_CFG_Pos    (0U)                                                                                  /*!< GS_SRAM10_CFG Postion   0          */ 
#define DEV_CFG_REGS_GS_SRAM_CFG5_GS_SRAM10_CFG_Msk    (0x7fffU << DEV_CFG_REGS_GS_SRAM_CFG5_GS_SRAM10_CFG_Pos)                              /*!< GS_SRAM10_CFG Mask      0x00007FFF */
#define DEV_CFG_REGS_GS_SRAM_CFG5_GS_SRAM10_CFG_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_GS_SRAM_CFG5_GS_SRAM10_CFG_Pos) & DEV_CFG_REGS_GS_SRAM_CFG5_GS_SRAM10_CFG_Msk) /*!< GS_SRAM10_CFG Set Value            */
#define DEV_CFG_REGS_GS_SRAM_CFG5_GS_SRAM10_CFG_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_GS_SRAM_CFG5_GS_SRAM10_CFG_Msk) >> DEV_CFG_REGS_GS_SRAM_CFG5_GS_SRAM10_CFG_Pos) /*!< GS_SRAM10_CFG Get Value            */


/* GS_SRAM_CFG6 bitfield */
#define DEV_CFG_REGS_GS_SRAM_CFG6_GS_SRAM13_CFG_Pos    (16U)                                                                                 /*!< GS_SRAM13_CFG Postion   16         */ 
#define DEV_CFG_REGS_GS_SRAM_CFG6_GS_SRAM13_CFG_Msk    (0x7fffU << DEV_CFG_REGS_GS_SRAM_CFG6_GS_SRAM13_CFG_Pos)                              /*!< GS_SRAM13_CFG Mask      0x7FFF0000 */
#define DEV_CFG_REGS_GS_SRAM_CFG6_GS_SRAM13_CFG_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_GS_SRAM_CFG6_GS_SRAM13_CFG_Pos) & DEV_CFG_REGS_GS_SRAM_CFG6_GS_SRAM13_CFG_Msk) /*!< GS_SRAM13_CFG Set Value            */
#define DEV_CFG_REGS_GS_SRAM_CFG6_GS_SRAM13_CFG_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_GS_SRAM_CFG6_GS_SRAM13_CFG_Msk) >> DEV_CFG_REGS_GS_SRAM_CFG6_GS_SRAM13_CFG_Pos) /*!< GS_SRAM13_CFG Get Value            */


#define DEV_CFG_REGS_GS_SRAM_CFG6_GS_SRAM12_CFG_Pos    (0U)                                                                                  /*!< GS_SRAM12_CFG Postion   0          */ 
#define DEV_CFG_REGS_GS_SRAM_CFG6_GS_SRAM12_CFG_Msk    (0x7fffU << DEV_CFG_REGS_GS_SRAM_CFG6_GS_SRAM12_CFG_Pos)                              /*!< GS_SRAM12_CFG Mask      0x00007FFF */
#define DEV_CFG_REGS_GS_SRAM_CFG6_GS_SRAM12_CFG_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_GS_SRAM_CFG6_GS_SRAM12_CFG_Pos) & DEV_CFG_REGS_GS_SRAM_CFG6_GS_SRAM12_CFG_Msk) /*!< GS_SRAM12_CFG Set Value            */
#define DEV_CFG_REGS_GS_SRAM_CFG6_GS_SRAM12_CFG_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_GS_SRAM_CFG6_GS_SRAM12_CFG_Msk) >> DEV_CFG_REGS_GS_SRAM_CFG6_GS_SRAM12_CFG_Pos) /*!< GS_SRAM12_CFG Get Value            */


/* GS_SRAM_CFG7 bitfield */
#define DEV_CFG_REGS_GS_SRAM_CFG7_GS_SRAM15_CFG_Pos    (16U)                                                                                 /*!< GS_SRAM15_CFG Postion   16         */ 
#define DEV_CFG_REGS_GS_SRAM_CFG7_GS_SRAM15_CFG_Msk    (0x7fffU << DEV_CFG_REGS_GS_SRAM_CFG7_GS_SRAM15_CFG_Pos)                              /*!< GS_SRAM15_CFG Mask      0x7FFF0000 */
#define DEV_CFG_REGS_GS_SRAM_CFG7_GS_SRAM15_CFG_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_GS_SRAM_CFG7_GS_SRAM15_CFG_Pos) & DEV_CFG_REGS_GS_SRAM_CFG7_GS_SRAM15_CFG_Msk) /*!< GS_SRAM15_CFG Set Value            */
#define DEV_CFG_REGS_GS_SRAM_CFG7_GS_SRAM15_CFG_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_GS_SRAM_CFG7_GS_SRAM15_CFG_Msk) >> DEV_CFG_REGS_GS_SRAM_CFG7_GS_SRAM15_CFG_Pos) /*!< GS_SRAM15_CFG Get Value            */


#define DEV_CFG_REGS_GS_SRAM_CFG7_GS_SRAM14_CFG_Pos    (0U)                                                                                  /*!< GS_SRAM14_CFG Postion   0          */ 
#define DEV_CFG_REGS_GS_SRAM_CFG7_GS_SRAM14_CFG_Msk    (0x7fffU << DEV_CFG_REGS_GS_SRAM_CFG7_GS_SRAM14_CFG_Pos)                              /*!< GS_SRAM14_CFG Mask      0x00007FFF */
#define DEV_CFG_REGS_GS_SRAM_CFG7_GS_SRAM14_CFG_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_GS_SRAM_CFG7_GS_SRAM14_CFG_Pos) & DEV_CFG_REGS_GS_SRAM_CFG7_GS_SRAM14_CFG_Msk) /*!< GS_SRAM14_CFG Set Value            */
#define DEV_CFG_REGS_GS_SRAM_CFG7_GS_SRAM14_CFG_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_GS_SRAM_CFG7_GS_SRAM14_CFG_Msk) >> DEV_CFG_REGS_GS_SRAM_CFG7_GS_SRAM14_CFG_Pos) /*!< GS_SRAM14_CFG Get Value            */


/* ROM_CFG bitfield */
#define DEV_CFG_REGS_ROM_CFG_CANC_MSGRAM_CFG_Pos    (16U)                                                                                 /*!< CANC_MSGRAM_CFG Postion   16         */ 
#define DEV_CFG_REGS_ROM_CFG_CANC_MSGRAM_CFG_Msk    (0x7fffU << DEV_CFG_REGS_ROM_CFG_CANC_MSGRAM_CFG_Pos)                                 /*!< CANC_MSGRAM_CFG Mask      0x7FFF0000 */
#define DEV_CFG_REGS_ROM_CFG_CANC_MSGRAM_CFG_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_ROM_CFG_CANC_MSGRAM_CFG_Pos) & DEV_CFG_REGS_ROM_CFG_CANC_MSGRAM_CFG_Msk) /*!< CANC_MSGRAM_CFG Set Value            */
#define DEV_CFG_REGS_ROM_CFG_CANC_MSGRAM_CFG_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_ROM_CFG_CANC_MSGRAM_CFG_Msk) >> DEV_CFG_REGS_ROM_CFG_CANC_MSGRAM_CFG_Pos) /*!< CANC_MSGRAM_CFG Get Value            */


#define DEV_CFG_REGS_ROM_CFG_CPU2_ROM_CFG_Pos    (8U)                                                                                  /*!< CPU2_ROM_CFG Postion   8          */ 
#define DEV_CFG_REGS_ROM_CFG_CPU2_ROM_CFG_Msk    (0x7fU << DEV_CFG_REGS_ROM_CFG_CPU2_ROM_CFG_Pos)                                      /*!< CPU2_ROM_CFG Mask      0x00007F00 */
#define DEV_CFG_REGS_ROM_CFG_CPU2_ROM_CFG_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_ROM_CFG_CPU2_ROM_CFG_Pos) & DEV_CFG_REGS_ROM_CFG_CPU2_ROM_CFG_Msk) /*!< CPU2_ROM_CFG Set Value            */
#define DEV_CFG_REGS_ROM_CFG_CPU2_ROM_CFG_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_ROM_CFG_CPU2_ROM_CFG_Msk) >> DEV_CFG_REGS_ROM_CFG_CPU2_ROM_CFG_Pos) /*!< CPU2_ROM_CFG Get Value            */


#define DEV_CFG_REGS_ROM_CFG_CPU1_ROM_CFG_Pos    (0U)                                                                                  /*!< CPU1_ROM_CFG Postion   0          */ 
#define DEV_CFG_REGS_ROM_CFG_CPU1_ROM_CFG_Msk    (0x7fU << DEV_CFG_REGS_ROM_CFG_CPU1_ROM_CFG_Pos)                                      /*!< CPU1_ROM_CFG Mask      0x0000007F */
#define DEV_CFG_REGS_ROM_CFG_CPU1_ROM_CFG_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_ROM_CFG_CPU1_ROM_CFG_Pos) & DEV_CFG_REGS_ROM_CFG_CPU1_ROM_CFG_Msk) /*!< CPU1_ROM_CFG Set Value            */
#define DEV_CFG_REGS_ROM_CFG_CPU1_ROM_CFG_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_ROM_CFG_CPU1_ROM_CFG_Msk) >> DEV_CFG_REGS_ROM_CFG_CPU1_ROM_CFG_Pos) /*!< CPU1_ROM_CFG Get Value            */


/* CAN_MSGRAM_CFG bitfield */
#define DEV_CFG_REGS_CAN_MSGRAM_CFG_CANB_MSGRAM_CFG_Pos    (16U)                                                                                 /*!< CANB_MSGRAM_CFG Postion   16         */ 
#define DEV_CFG_REGS_CAN_MSGRAM_CFG_CANB_MSGRAM_CFG_Msk    (0x7fffU << DEV_CFG_REGS_CAN_MSGRAM_CFG_CANB_MSGRAM_CFG_Pos)                          /*!< CANB_MSGRAM_CFG Mask      0x7FFF0000 */
#define DEV_CFG_REGS_CAN_MSGRAM_CFG_CANB_MSGRAM_CFG_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CAN_MSGRAM_CFG_CANB_MSGRAM_CFG_Pos) & DEV_CFG_REGS_CAN_MSGRAM_CFG_CANB_MSGRAM_CFG_Msk) /*!< CANB_MSGRAM_CFG Set Value            */
#define DEV_CFG_REGS_CAN_MSGRAM_CFG_CANB_MSGRAM_CFG_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CAN_MSGRAM_CFG_CANB_MSGRAM_CFG_Msk) >> DEV_CFG_REGS_CAN_MSGRAM_CFG_CANB_MSGRAM_CFG_Pos) /*!< CANB_MSGRAM_CFG Get Value            */


#define DEV_CFG_REGS_CAN_MSGRAM_CFG_CANA_MSGRAM_CFG_Pos    (0U)                                                                                  /*!< CANA_MSGRAM_CFG Postion   0          */ 
#define DEV_CFG_REGS_CAN_MSGRAM_CFG_CANA_MSGRAM_CFG_Msk    (0x7fffU << DEV_CFG_REGS_CAN_MSGRAM_CFG_CANA_MSGRAM_CFG_Pos)                          /*!< CANA_MSGRAM_CFG Mask      0x00007FFF */
#define DEV_CFG_REGS_CAN_MSGRAM_CFG_CANA_MSGRAM_CFG_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CAN_MSGRAM_CFG_CANA_MSGRAM_CFG_Pos) & DEV_CFG_REGS_CAN_MSGRAM_CFG_CANA_MSGRAM_CFG_Msk) /*!< CANA_MSGRAM_CFG Set Value            */
#define DEV_CFG_REGS_CAN_MSGRAM_CFG_CANA_MSGRAM_CFG_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CAN_MSGRAM_CFG_CANA_MSGRAM_CFG_Msk) >> DEV_CFG_REGS_CAN_MSGRAM_CFG_CANA_MSGRAM_CFG_Pos) /*!< CANA_MSGRAM_CFG Get Value            */


/* USB_SRAM_CFG bitfield */
#define DEV_CFG_REGS_USB_SRAM_CFG_USBA_SRAM_CFG_Pos    (0U)                                                                                  /*!< USBA_SRAM_CFG Postion   0          */ 
#define DEV_CFG_REGS_USB_SRAM_CFG_USBA_SRAM_CFG_Msk    (0x7fffU << DEV_CFG_REGS_USB_SRAM_CFG_USBA_SRAM_CFG_Pos)                              /*!< USBA_SRAM_CFG Mask      0x00007FFF */
#define DEV_CFG_REGS_USB_SRAM_CFG_USBA_SRAM_CFG_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_USB_SRAM_CFG_USBA_SRAM_CFG_Pos) & DEV_CFG_REGS_USB_SRAM_CFG_USBA_SRAM_CFG_Msk) /*!< USBA_SRAM_CFG Set Value            */
#define DEV_CFG_REGS_USB_SRAM_CFG_USBA_SRAM_CFG_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_USB_SRAM_CFG_USBA_SRAM_CFG_Msk) >> DEV_CFG_REGS_USB_SRAM_CFG_USBA_SRAM_CFG_Pos) /*!< USBA_SRAM_CFG Get Value            */


/* SRAM_ECC_CTRL bitfield */
#define DEV_CFG_REGS_SRAM_ECC_CTRL_SRAM_ECC_DIS_Pos    (0U)                                                                                  /*!< SRAM_ECC_DIS Postion   0          */ 
#define DEV_CFG_REGS_SRAM_ECC_CTRL_SRAM_ECC_DIS_Msk    (0x1U << DEV_CFG_REGS_SRAM_ECC_CTRL_SRAM_ECC_DIS_Pos)                                 /*!< SRAM_ECC_DIS Mask      0x00000001 */
#define DEV_CFG_REGS_SRAM_ECC_CTRL_SRAM_ECC_DIS_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SRAM_ECC_CTRL_SRAM_ECC_DIS_Pos) & DEV_CFG_REGS_SRAM_ECC_CTRL_SRAM_ECC_DIS_Msk) /*!< SRAM_ECC_DIS Set Value            */
#define DEV_CFG_REGS_SRAM_ECC_CTRL_SRAM_ECC_DIS_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SRAM_ECC_CTRL_SRAM_ECC_DIS_Msk) >> DEV_CFG_REGS_SRAM_ECC_CTRL_SRAM_ECC_DIS_Pos) /*!< SRAM_ECC_DIS Get Value            */


/* CPU1_MISC_CFG0 bitfield */
#define DEV_CFG_REGS_CPU1_MISC_CFG0_CPU1_MISC_CFG0_Pos    (0U)                                                                                  /*!< CPU1_MISC_CFG0 Postion   0          */ 
#define DEV_CFG_REGS_CPU1_MISC_CFG0_CPU1_MISC_CFG0_Msk    (0xffffffffU << DEV_CFG_REGS_CPU1_MISC_CFG0_CPU1_MISC_CFG0_Pos)                       /*!< CPU1_MISC_CFG0 Mask      0xFFFFFFFF */
#define DEV_CFG_REGS_CPU1_MISC_CFG0_CPU1_MISC_CFG0_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPU1_MISC_CFG0_CPU1_MISC_CFG0_Pos) & DEV_CFG_REGS_CPU1_MISC_CFG0_CPU1_MISC_CFG0_Msk) /*!< CPU1_MISC_CFG0 Set Value            */
#define DEV_CFG_REGS_CPU1_MISC_CFG0_CPU1_MISC_CFG0_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPU1_MISC_CFG0_CPU1_MISC_CFG0_Msk) >> DEV_CFG_REGS_CPU1_MISC_CFG0_CPU1_MISC_CFG0_Pos) /*!< CPU1_MISC_CFG0 Get Value            */


/* CPU1_MISC_CFG1 bitfield */
#define DEV_CFG_REGS_CPU1_MISC_CFG1_CPU1_MISC_CFG1_Pos    (0U)                                                                                  /*!< CPU1_MISC_CFG1 Postion   0          */ 
#define DEV_CFG_REGS_CPU1_MISC_CFG1_CPU1_MISC_CFG1_Msk    (0xffffffffU << DEV_CFG_REGS_CPU1_MISC_CFG1_CPU1_MISC_CFG1_Pos)                       /*!< CPU1_MISC_CFG1 Mask      0xFFFFFFFF */
#define DEV_CFG_REGS_CPU1_MISC_CFG1_CPU1_MISC_CFG1_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPU1_MISC_CFG1_CPU1_MISC_CFG1_Pos) & DEV_CFG_REGS_CPU1_MISC_CFG1_CPU1_MISC_CFG1_Msk) /*!< CPU1_MISC_CFG1 Set Value            */
#define DEV_CFG_REGS_CPU1_MISC_CFG1_CPU1_MISC_CFG1_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPU1_MISC_CFG1_CPU1_MISC_CFG1_Msk) >> DEV_CFG_REGS_CPU1_MISC_CFG1_CPU1_MISC_CFG1_Pos) /*!< CPU1_MISC_CFG1 Get Value            */


/* CPU1_MISC_CFG2 bitfield */
#define DEV_CFG_REGS_CPU1_MISC_CFG2_CPU1_MISC_CFG2_Pos    (0U)                                                                                  /*!< CPU1_MISC_CFG2 Postion   0          */ 
#define DEV_CFG_REGS_CPU1_MISC_CFG2_CPU1_MISC_CFG2_Msk    (0xffffffffU << DEV_CFG_REGS_CPU1_MISC_CFG2_CPU1_MISC_CFG2_Pos)                       /*!< CPU1_MISC_CFG2 Mask      0xFFFFFFFF */
#define DEV_CFG_REGS_CPU1_MISC_CFG2_CPU1_MISC_CFG2_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPU1_MISC_CFG2_CPU1_MISC_CFG2_Pos) & DEV_CFG_REGS_CPU1_MISC_CFG2_CPU1_MISC_CFG2_Msk) /*!< CPU1_MISC_CFG2 Set Value            */
#define DEV_CFG_REGS_CPU1_MISC_CFG2_CPU1_MISC_CFG2_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPU1_MISC_CFG2_CPU1_MISC_CFG2_Msk) >> DEV_CFG_REGS_CPU1_MISC_CFG2_CPU1_MISC_CFG2_Pos) /*!< CPU1_MISC_CFG2 Get Value            */


/* CPU1_MISC_CFG3 bitfield */
#define DEV_CFG_REGS_CPU1_MISC_CFG3_CPU1_MISC_CFG3_Pos    (0U)                                                                                  /*!< CPU1_MISC_CFG3 Postion   0          */ 
#define DEV_CFG_REGS_CPU1_MISC_CFG3_CPU1_MISC_CFG3_Msk    (0xffffffffU << DEV_CFG_REGS_CPU1_MISC_CFG3_CPU1_MISC_CFG3_Pos)                       /*!< CPU1_MISC_CFG3 Mask      0xFFFFFFFF */
#define DEV_CFG_REGS_CPU1_MISC_CFG3_CPU1_MISC_CFG3_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPU1_MISC_CFG3_CPU1_MISC_CFG3_Pos) & DEV_CFG_REGS_CPU1_MISC_CFG3_CPU1_MISC_CFG3_Msk) /*!< CPU1_MISC_CFG3 Set Value            */
#define DEV_CFG_REGS_CPU1_MISC_CFG3_CPU1_MISC_CFG3_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPU1_MISC_CFG3_CPU1_MISC_CFG3_Msk) >> DEV_CFG_REGS_CPU1_MISC_CFG3_CPU1_MISC_CFG3_Pos) /*!< CPU1_MISC_CFG3 Get Value            */


/* CPU1_MISC_CFG4 bitfield */
#define DEV_CFG_REGS_CPU1_MISC_CFG4_CPU1_MISC_CFG4_Pos    (0U)                                                                                  /*!< CPU1_MISC_CFG4 Postion   0          */ 
#define DEV_CFG_REGS_CPU1_MISC_CFG4_CPU1_MISC_CFG4_Msk    (0xffffffffU << DEV_CFG_REGS_CPU1_MISC_CFG4_CPU1_MISC_CFG4_Pos)                       /*!< CPU1_MISC_CFG4 Mask      0xFFFFFFFF */
#define DEV_CFG_REGS_CPU1_MISC_CFG4_CPU1_MISC_CFG4_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPU1_MISC_CFG4_CPU1_MISC_CFG4_Pos) & DEV_CFG_REGS_CPU1_MISC_CFG4_CPU1_MISC_CFG4_Msk) /*!< CPU1_MISC_CFG4 Set Value            */
#define DEV_CFG_REGS_CPU1_MISC_CFG4_CPU1_MISC_CFG4_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPU1_MISC_CFG4_CPU1_MISC_CFG4_Msk) >> DEV_CFG_REGS_CPU1_MISC_CFG4_CPU1_MISC_CFG4_Pos) /*!< CPU1_MISC_CFG4 Get Value            */


/* CPU2_MISC_CFG0 bitfield */
#define DEV_CFG_REGS_CPU2_MISC_CFG0_CPU2_MISC_CFG0_Pos    (0U)                                                                                  /*!< CPU2_MISC_CFG0 Postion   0          */ 
#define DEV_CFG_REGS_CPU2_MISC_CFG0_CPU2_MISC_CFG0_Msk    (0xffffffffU << DEV_CFG_REGS_CPU2_MISC_CFG0_CPU2_MISC_CFG0_Pos)                       /*!< CPU2_MISC_CFG0 Mask      0xFFFFFFFF */
#define DEV_CFG_REGS_CPU2_MISC_CFG0_CPU2_MISC_CFG0_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPU2_MISC_CFG0_CPU2_MISC_CFG0_Pos) & DEV_CFG_REGS_CPU2_MISC_CFG0_CPU2_MISC_CFG0_Msk) /*!< CPU2_MISC_CFG0 Set Value            */
#define DEV_CFG_REGS_CPU2_MISC_CFG0_CPU2_MISC_CFG0_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPU2_MISC_CFG0_CPU2_MISC_CFG0_Msk) >> DEV_CFG_REGS_CPU2_MISC_CFG0_CPU2_MISC_CFG0_Pos) /*!< CPU2_MISC_CFG0 Get Value            */


/* CPU2_MISC_CFG1 bitfield */
#define DEV_CFG_REGS_CPU2_MISC_CFG1_CPU2_MISC_CFG1_Pos    (0U)                                                                                  /*!< CPU2_MISC_CFG1 Postion   0          */ 
#define DEV_CFG_REGS_CPU2_MISC_CFG1_CPU2_MISC_CFG1_Msk    (0xffffffffU << DEV_CFG_REGS_CPU2_MISC_CFG1_CPU2_MISC_CFG1_Pos)                       /*!< CPU2_MISC_CFG1 Mask      0xFFFFFFFF */
#define DEV_CFG_REGS_CPU2_MISC_CFG1_CPU2_MISC_CFG1_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPU2_MISC_CFG1_CPU2_MISC_CFG1_Pos) & DEV_CFG_REGS_CPU2_MISC_CFG1_CPU2_MISC_CFG1_Msk) /*!< CPU2_MISC_CFG1 Set Value            */
#define DEV_CFG_REGS_CPU2_MISC_CFG1_CPU2_MISC_CFG1_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPU2_MISC_CFG1_CPU2_MISC_CFG1_Msk) >> DEV_CFG_REGS_CPU2_MISC_CFG1_CPU2_MISC_CFG1_Pos) /*!< CPU2_MISC_CFG1 Get Value            */


/* CPU2_MISC_CFG2 bitfield */
#define DEV_CFG_REGS_CPU2_MISC_CFG2_CPU2_MISC_CFG2_Pos    (0U)                                                                                  /*!< CPU2_MISC_CFG2 Postion   0          */ 
#define DEV_CFG_REGS_CPU2_MISC_CFG2_CPU2_MISC_CFG2_Msk    (0xffffffffU << DEV_CFG_REGS_CPU2_MISC_CFG2_CPU2_MISC_CFG2_Pos)                       /*!< CPU2_MISC_CFG2 Mask      0xFFFFFFFF */
#define DEV_CFG_REGS_CPU2_MISC_CFG2_CPU2_MISC_CFG2_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPU2_MISC_CFG2_CPU2_MISC_CFG2_Pos) & DEV_CFG_REGS_CPU2_MISC_CFG2_CPU2_MISC_CFG2_Msk) /*!< CPU2_MISC_CFG2 Set Value            */
#define DEV_CFG_REGS_CPU2_MISC_CFG2_CPU2_MISC_CFG2_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPU2_MISC_CFG2_CPU2_MISC_CFG2_Msk) >> DEV_CFG_REGS_CPU2_MISC_CFG2_CPU2_MISC_CFG2_Pos) /*!< CPU2_MISC_CFG2 Get Value            */


/* CPU2_MISC_CFG3 bitfield */
#define DEV_CFG_REGS_CPU2_MISC_CFG3_CPU2_MISC_CFG3_Pos    (0U)                                                                                  /*!< CPU2_MISC_CFG3 Postion   0          */ 
#define DEV_CFG_REGS_CPU2_MISC_CFG3_CPU2_MISC_CFG3_Msk    (0xffffffffU << DEV_CFG_REGS_CPU2_MISC_CFG3_CPU2_MISC_CFG3_Pos)                       /*!< CPU2_MISC_CFG3 Mask      0xFFFFFFFF */
#define DEV_CFG_REGS_CPU2_MISC_CFG3_CPU2_MISC_CFG3_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPU2_MISC_CFG3_CPU2_MISC_CFG3_Pos) & DEV_CFG_REGS_CPU2_MISC_CFG3_CPU2_MISC_CFG3_Msk) /*!< CPU2_MISC_CFG3 Set Value            */
#define DEV_CFG_REGS_CPU2_MISC_CFG3_CPU2_MISC_CFG3_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPU2_MISC_CFG3_CPU2_MISC_CFG3_Msk) >> DEV_CFG_REGS_CPU2_MISC_CFG3_CPU2_MISC_CFG3_Pos) /*!< CPU2_MISC_CFG3 Get Value            */


/* CPU2_MISC_CFG4 bitfield */
#define DEV_CFG_REGS_CPU2_MISC_CFG4_CPU2_MISC_CFG4_Pos    (0U)                                                                                  /*!< CPU2_MISC_CFG4 Postion   0          */ 
#define DEV_CFG_REGS_CPU2_MISC_CFG4_CPU2_MISC_CFG4_Msk    (0xffffffffU << DEV_CFG_REGS_CPU2_MISC_CFG4_CPU2_MISC_CFG4_Pos)                       /*!< CPU2_MISC_CFG4 Mask      0xFFFFFFFF */
#define DEV_CFG_REGS_CPU2_MISC_CFG4_CPU2_MISC_CFG4_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPU2_MISC_CFG4_CPU2_MISC_CFG4_Pos) & DEV_CFG_REGS_CPU2_MISC_CFG4_CPU2_MISC_CFG4_Msk) /*!< CPU2_MISC_CFG4 Set Value            */
#define DEV_CFG_REGS_CPU2_MISC_CFG4_CPU2_MISC_CFG4_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPU2_MISC_CFG4_CPU2_MISC_CFG4_Msk) >> DEV_CFG_REGS_CPU2_MISC_CFG4_CPU2_MISC_CFG4_Pos) /*!< CPU2_MISC_CFG4 Get Value            */


/* CPU1_MISC_STS bitfield */
#define DEV_CFG_REGS_CPU1_MISC_STS_CPU1_MISC_STS_Pos    (0U)                                                                                  /*!< CPU1_MISC_STS Postion   0          */ 
#define DEV_CFG_REGS_CPU1_MISC_STS_CPU1_MISC_STS_Msk    (0xfffU << DEV_CFG_REGS_CPU1_MISC_STS_CPU1_MISC_STS_Pos)                              /*!< CPU1_MISC_STS Mask      0x00000FFF */
#define DEV_CFG_REGS_CPU1_MISC_STS_CPU1_MISC_STS_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPU1_MISC_STS_CPU1_MISC_STS_Pos) & DEV_CFG_REGS_CPU1_MISC_STS_CPU1_MISC_STS_Msk) /*!< CPU1_MISC_STS Set Value            */
#define DEV_CFG_REGS_CPU1_MISC_STS_CPU1_MISC_STS_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPU1_MISC_STS_CPU1_MISC_STS_Msk) >> DEV_CFG_REGS_CPU1_MISC_STS_CPU1_MISC_STS_Pos) /*!< CPU1_MISC_STS Get Value            */


/* CPU2_MISC_STS bitfield */
#define DEV_CFG_REGS_CPU2_MISC_STS_CPU2_MISC_STS_Pos    (0U)                                                                                  /*!< CPU2_MISC_STS Postion   0          */ 
#define DEV_CFG_REGS_CPU2_MISC_STS_CPU2_MISC_STS_Msk    (0xfffU << DEV_CFG_REGS_CPU2_MISC_STS_CPU2_MISC_STS_Pos)                              /*!< CPU2_MISC_STS Mask      0x00000FFF */
#define DEV_CFG_REGS_CPU2_MISC_STS_CPU2_MISC_STS_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPU2_MISC_STS_CPU2_MISC_STS_Pos) & DEV_CFG_REGS_CPU2_MISC_STS_CPU2_MISC_STS_Msk) /*!< CPU2_MISC_STS Set Value            */
#define DEV_CFG_REGS_CPU2_MISC_STS_CPU2_MISC_STS_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPU2_MISC_STS_CPU2_MISC_STS_Msk) >> DEV_CFG_REGS_CPU2_MISC_STS_CPU2_MISC_STS_Pos) /*!< CPU2_MISC_STS Get Value            */


/* DAP_MISC bitfield */
#define DEV_CFG_REGS_DAP_MISC_JTAGNSW_Pos    (11U)                                                                                 /*!< JTAGNSW Postion   11         */ 
#define DEV_CFG_REGS_DAP_MISC_JTAGNSW_Msk    (0x1U << DEV_CFG_REGS_DAP_MISC_JTAGNSW_Pos)                                           /*!< JTAGNSW Mask      0x00000800 */
#define DEV_CFG_REGS_DAP_MISC_JTAGNSW_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DAP_MISC_JTAGNSW_Pos) & DEV_CFG_REGS_DAP_MISC_JTAGNSW_Msk) /*!< JTAGNSW Set Value            */
#define DEV_CFG_REGS_DAP_MISC_JTAGNSW_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DAP_MISC_JTAGNSW_Msk) >> DEV_CFG_REGS_DAP_MISC_JTAGNSW_Pos) /*!< JTAGNSW Get Value            */


#define DEV_CFG_REGS_DAP_MISC_JTAGTOP_Pos    (10U)                                                                                 /*!< JTAGTOP Postion   10         */ 
#define DEV_CFG_REGS_DAP_MISC_JTAGTOP_Msk    (0x1U << DEV_CFG_REGS_DAP_MISC_JTAGTOP_Pos)                                           /*!< JTAGTOP Mask      0x00000400 */
#define DEV_CFG_REGS_DAP_MISC_JTAGTOP_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DAP_MISC_JTAGTOP_Pos) & DEV_CFG_REGS_DAP_MISC_JTAGTOP_Msk) /*!< JTAGTOP Set Value            */
#define DEV_CFG_REGS_DAP_MISC_JTAGTOP_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DAP_MISC_JTAGTOP_Msk) >> DEV_CFG_REGS_DAP_MISC_JTAGTOP_Pos) /*!< JTAGTOP Get Value            */


#define DEV_CFG_REGS_DAP_MISC_DAP_MISC_CFG_Pos    (0U)                                                                                  /*!< DAP_MISC_CFG Postion   0          */ 
#define DEV_CFG_REGS_DAP_MISC_DAP_MISC_CFG_Msk    (0x3ffU << DEV_CFG_REGS_DAP_MISC_DAP_MISC_CFG_Pos)                                    /*!< DAP_MISC_CFG Mask      0x000003FF */
#define DEV_CFG_REGS_DAP_MISC_DAP_MISC_CFG_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_DAP_MISC_DAP_MISC_CFG_Pos) & DEV_CFG_REGS_DAP_MISC_DAP_MISC_CFG_Msk) /*!< DAP_MISC_CFG Set Value            */
#define DEV_CFG_REGS_DAP_MISC_DAP_MISC_CFG_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_DAP_MISC_DAP_MISC_CFG_Msk) >> DEV_CFG_REGS_DAP_MISC_DAP_MISC_CFG_Pos) /*!< DAP_MISC_CFG Get Value            */


/* HTDEVLOCK bitfield */
#define DEV_CFG_REGS_HTDEVLOCK_HTDEVLOCK_Pos    (0U)                                                                                  /*!< HTDEVLOCK Postion   0          */ 
#define DEV_CFG_REGS_HTDEVLOCK_HTDEVLOCK_Msk    (0x1U << DEV_CFG_REGS_HTDEVLOCK_HTDEVLOCK_Pos)                                        /*!< HTDEVLOCK Mask      0x00000001 */
#define DEV_CFG_REGS_HTDEVLOCK_HTDEVLOCK_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_HTDEVLOCK_HTDEVLOCK_Pos) & DEV_CFG_REGS_HTDEVLOCK_HTDEVLOCK_Msk) /*!< HTDEVLOCK Set Value            */
#define DEV_CFG_REGS_HTDEVLOCK_HTDEVLOCK_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_HTDEVLOCK_HTDEVLOCK_Msk) >> DEV_CFG_REGS_HTDEVLOCK_HTDEVLOCK_Pos) /*!< HTDEVLOCK Get Value            */


/* HTDBGSEL bitfield */
#define DEV_CFG_REGS_HTDBGSEL_EXTEND_DBG_ROTATE_Pos    (20U)                                                                                 /*!< EXTEND_DBG_ROTATE Postion   20         */ 
#define DEV_CFG_REGS_HTDBGSEL_EXTEND_DBG_ROTATE_Msk    (0xfU << DEV_CFG_REGS_HTDBGSEL_EXTEND_DBG_ROTATE_Pos)                                 /*!< EXTEND_DBG_ROTATE Mask      0x00F00000 */
#define DEV_CFG_REGS_HTDBGSEL_EXTEND_DBG_ROTATE_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_HTDBGSEL_EXTEND_DBG_ROTATE_Pos) & DEV_CFG_REGS_HTDBGSEL_EXTEND_DBG_ROTATE_Msk) /*!< EXTEND_DBG_ROTATE Set Value            */
#define DEV_CFG_REGS_HTDBGSEL_EXTEND_DBG_ROTATE_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_HTDBGSEL_EXTEND_DBG_ROTATE_Msk) >> DEV_CFG_REGS_HTDBGSEL_EXTEND_DBG_ROTATE_Pos) /*!< EXTEND_DBG_ROTATE Get Value            */


#define DEV_CFG_REGS_HTDBGSEL_NORMAL_DBG_ROTATE_Pos    (16U)                                                                                 /*!< NORMAL_DBG_ROTATE Postion   16         */ 
#define DEV_CFG_REGS_HTDBGSEL_NORMAL_DBG_ROTATE_Msk    (0xfU << DEV_CFG_REGS_HTDBGSEL_NORMAL_DBG_ROTATE_Pos)                                 /*!< NORMAL_DBG_ROTATE Mask      0x000F0000 */
#define DEV_CFG_REGS_HTDBGSEL_NORMAL_DBG_ROTATE_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_HTDBGSEL_NORMAL_DBG_ROTATE_Pos) & DEV_CFG_REGS_HTDBGSEL_NORMAL_DBG_ROTATE_Msk) /*!< NORMAL_DBG_ROTATE Set Value            */
#define DEV_CFG_REGS_HTDBGSEL_NORMAL_DBG_ROTATE_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_HTDBGSEL_NORMAL_DBG_ROTATE_Msk) >> DEV_CFG_REGS_HTDBGSEL_NORMAL_DBG_ROTATE_Pos) /*!< NORMAL_DBG_ROTATE Get Value            */


#define DEV_CFG_REGS_HTDBGSEL_DBGSEL_Pos    (0U)                                                                                  /*!< DBGSEL Postion   0          */ 
#define DEV_CFG_REGS_HTDBGSEL_DBGSEL_Msk    (0xffffU << DEV_CFG_REGS_HTDBGSEL_DBGSEL_Pos)                                         /*!< DBGSEL Mask      0x0000FFFF */
#define DEV_CFG_REGS_HTDBGSEL_DBGSEL_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_HTDBGSEL_DBGSEL_Pos) & DEV_CFG_REGS_HTDBGSEL_DBGSEL_Msk) /*!< DBGSEL Set Value            */
#define DEV_CFG_REGS_HTDBGSEL_DBGSEL_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_HTDBGSEL_DBGSEL_Msk) >> DEV_CFG_REGS_HTDBGSEL_DBGSEL_Pos) /*!< DBGSEL Get Value            */


/* CPURSTCTRL bitfield */
#define DEV_CFG_REGS_CPURSTCTRL_CPU2_CORERST_CNT_Pos    (24U)                                                                                 /*!< CPU2_CORERST_CNT Postion   24         */ 
#define DEV_CFG_REGS_CPURSTCTRL_CPU2_CORERST_CNT_Msk    (0xffU << DEV_CFG_REGS_CPURSTCTRL_CPU2_CORERST_CNT_Pos)                               /*!< CPU2_CORERST_CNT Mask      0xFF000000 */
#define DEV_CFG_REGS_CPURSTCTRL_CPU2_CORERST_CNT_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPURSTCTRL_CPU2_CORERST_CNT_Pos) & DEV_CFG_REGS_CPURSTCTRL_CPU2_CORERST_CNT_Msk) /*!< CPU2_CORERST_CNT Set Value            */
#define DEV_CFG_REGS_CPURSTCTRL_CPU2_CORERST_CNT_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPURSTCTRL_CPU2_CORERST_CNT_Msk) >> DEV_CFG_REGS_CPURSTCTRL_CPU2_CORERST_CNT_Pos) /*!< CPU2_CORERST_CNT Get Value            */


#define DEV_CFG_REGS_CPURSTCTRL_CPU1_CORERST_CNT_Pos    (16U)                                                                                 /*!< CPU1_CORERST_CNT Postion   16         */ 
#define DEV_CFG_REGS_CPURSTCTRL_CPU1_CORERST_CNT_Msk    (0xffU << DEV_CFG_REGS_CPURSTCTRL_CPU1_CORERST_CNT_Pos)                               /*!< CPU1_CORERST_CNT Mask      0x00FF0000 */
#define DEV_CFG_REGS_CPURSTCTRL_CPU1_CORERST_CNT_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPURSTCTRL_CPU1_CORERST_CNT_Pos) & DEV_CFG_REGS_CPURSTCTRL_CPU1_CORERST_CNT_Msk) /*!< CPU1_CORERST_CNT Set Value            */
#define DEV_CFG_REGS_CPURSTCTRL_CPU1_CORERST_CNT_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPURSTCTRL_CPU1_CORERST_CNT_Msk) >> DEV_CFG_REGS_CPURSTCTRL_CPU1_CORERST_CNT_Pos) /*!< CPU1_CORERST_CNT Get Value            */


#define DEV_CFG_REGS_CPURSTCTRL_CPU2_SYSRST_CNT_Pos    (8U)                                                                                  /*!< CPU2_SYSRST_CNT Postion   8          */ 
#define DEV_CFG_REGS_CPURSTCTRL_CPU2_SYSRST_CNT_Msk    (0xffU << DEV_CFG_REGS_CPURSTCTRL_CPU2_SYSRST_CNT_Pos)                                /*!< CPU2_SYSRST_CNT Mask      0x0000FF00 */
#define DEV_CFG_REGS_CPURSTCTRL_CPU2_SYSRST_CNT_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPURSTCTRL_CPU2_SYSRST_CNT_Pos) & DEV_CFG_REGS_CPURSTCTRL_CPU2_SYSRST_CNT_Msk) /*!< CPU2_SYSRST_CNT Set Value            */
#define DEV_CFG_REGS_CPURSTCTRL_CPU2_SYSRST_CNT_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPURSTCTRL_CPU2_SYSRST_CNT_Msk) >> DEV_CFG_REGS_CPURSTCTRL_CPU2_SYSRST_CNT_Pos) /*!< CPU2_SYSRST_CNT Get Value            */


#define DEV_CFG_REGS_CPURSTCTRL_CPU1_SYSRST_CNT_Pos    (0U)                                                                                  /*!< CPU1_SYSRST_CNT Postion   0          */ 
#define DEV_CFG_REGS_CPURSTCTRL_CPU1_SYSRST_CNT_Msk    (0xffU << DEV_CFG_REGS_CPURSTCTRL_CPU1_SYSRST_CNT_Pos)                                /*!< CPU1_SYSRST_CNT Mask      0x000000FF */
#define DEV_CFG_REGS_CPURSTCTRL_CPU1_SYSRST_CNT_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPURSTCTRL_CPU1_SYSRST_CNT_Pos) & DEV_CFG_REGS_CPURSTCTRL_CPU1_SYSRST_CNT_Msk) /*!< CPU1_SYSRST_CNT Set Value            */
#define DEV_CFG_REGS_CPURSTCTRL_CPU1_SYSRST_CNT_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPURSTCTRL_CPU1_SYSRST_CNT_Msk) >> DEV_CFG_REGS_CPURSTCTRL_CPU1_SYSRST_CNT_Pos) /*!< CPU1_SYSRST_CNT Get Value            */


/* CANDEBUG bitfield */
#define DEV_CFG_REGS_CANDEBUG_CAN_C_DIS_MODI_Pos    (2U)                                                                                  /*!< CAN_C_DIS_MODI Postion   2          */ 
#define DEV_CFG_REGS_CANDEBUG_CAN_C_DIS_MODI_Msk    (0x1U << DEV_CFG_REGS_CANDEBUG_CAN_C_DIS_MODI_Pos)                                    /*!< CAN_C_DIS_MODI Mask      0x00000004 */
#define DEV_CFG_REGS_CANDEBUG_CAN_C_DIS_MODI_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CANDEBUG_CAN_C_DIS_MODI_Pos) & DEV_CFG_REGS_CANDEBUG_CAN_C_DIS_MODI_Msk) /*!< CAN_C_DIS_MODI Set Value            */
#define DEV_CFG_REGS_CANDEBUG_CAN_C_DIS_MODI_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CANDEBUG_CAN_C_DIS_MODI_Msk) >> DEV_CFG_REGS_CANDEBUG_CAN_C_DIS_MODI_Pos) /*!< CAN_C_DIS_MODI Get Value            */


#define DEV_CFG_REGS_CANDEBUG_CAN_B_DIS_MODI_Pos    (1U)                                                                                  /*!< CAN_B_DIS_MODI Postion   1          */ 
#define DEV_CFG_REGS_CANDEBUG_CAN_B_DIS_MODI_Msk    (0x1U << DEV_CFG_REGS_CANDEBUG_CAN_B_DIS_MODI_Pos)                                    /*!< CAN_B_DIS_MODI Mask      0x00000002 */
#define DEV_CFG_REGS_CANDEBUG_CAN_B_DIS_MODI_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CANDEBUG_CAN_B_DIS_MODI_Pos) & DEV_CFG_REGS_CANDEBUG_CAN_B_DIS_MODI_Msk) /*!< CAN_B_DIS_MODI Set Value            */
#define DEV_CFG_REGS_CANDEBUG_CAN_B_DIS_MODI_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CANDEBUG_CAN_B_DIS_MODI_Msk) >> DEV_CFG_REGS_CANDEBUG_CAN_B_DIS_MODI_Pos) /*!< CAN_B_DIS_MODI Get Value            */


#define DEV_CFG_REGS_CANDEBUG_CAN_A_DIS_MODI_Pos    (0U)                                                                                  /*!< CAN_A_DIS_MODI Postion   0          */ 
#define DEV_CFG_REGS_CANDEBUG_CAN_A_DIS_MODI_Msk    (0x1U << DEV_CFG_REGS_CANDEBUG_CAN_A_DIS_MODI_Pos)                                    /*!< CAN_A_DIS_MODI Mask      0x00000001 */
#define DEV_CFG_REGS_CANDEBUG_CAN_A_DIS_MODI_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CANDEBUG_CAN_A_DIS_MODI_Pos) & DEV_CFG_REGS_CANDEBUG_CAN_A_DIS_MODI_Msk) /*!< CAN_A_DIS_MODI Set Value            */
#define DEV_CFG_REGS_CANDEBUG_CAN_A_DIS_MODI_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CANDEBUG_CAN_A_DIS_MODI_Msk) >> DEV_CFG_REGS_CANDEBUG_CAN_A_DIS_MODI_Pos) /*!< CAN_A_DIS_MODI Get Value            */


/* CPU2INITVTOR bitfield */
#define DEV_CFG_REGS_CPU2INITVTOR_CPU2INITVTOR_Pos    (0U)                                                                                  /*!< CPU2INITVTOR Postion   0          */ 
#define DEV_CFG_REGS_CPU2INITVTOR_CPU2INITVTOR_Msk    (0xffffffffU << DEV_CFG_REGS_CPU2INITVTOR_CPU2INITVTOR_Pos)                           /*!< CPU2INITVTOR Mask      0xFFFFFFFF */
#define DEV_CFG_REGS_CPU2INITVTOR_CPU2INITVTOR_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_CPU2INITVTOR_CPU2INITVTOR_Pos) & DEV_CFG_REGS_CPU2INITVTOR_CPU2INITVTOR_Msk) /*!< CPU2INITVTOR Set Value            */
#define DEV_CFG_REGS_CPU2INITVTOR_CPU2INITVTOR_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_CPU2INITVTOR_CPU2INITVTOR_Msk) >> DEV_CFG_REGS_CPU2INITVTOR_CPU2INITVTOR_Pos) /*!< CPU2INITVTOR Get Value            */


/* SPIXIPENABLE bitfield */
#define DEV_CFG_REGS_SPIXIPENABLE_SPI_C_XIP_EN_Pos    (2U)                                                                                  /*!< SPI_C_XIP_EN Postion   2          */ 
#define DEV_CFG_REGS_SPIXIPENABLE_SPI_C_XIP_EN_Msk    (0x1U << DEV_CFG_REGS_SPIXIPENABLE_SPI_C_XIP_EN_Pos)                                  /*!< SPI_C_XIP_EN Mask      0x00000004 */
#define DEV_CFG_REGS_SPIXIPENABLE_SPI_C_XIP_EN_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SPIXIPENABLE_SPI_C_XIP_EN_Pos) & DEV_CFG_REGS_SPIXIPENABLE_SPI_C_XIP_EN_Msk) /*!< SPI_C_XIP_EN Set Value            */
#define DEV_CFG_REGS_SPIXIPENABLE_SPI_C_XIP_EN_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SPIXIPENABLE_SPI_C_XIP_EN_Msk) >> DEV_CFG_REGS_SPIXIPENABLE_SPI_C_XIP_EN_Pos) /*!< SPI_C_XIP_EN Get Value            */


#define DEV_CFG_REGS_SPIXIPENABLE_SPI_B_XIP_EN_Pos    (1U)                                                                                  /*!< SPI_B_XIP_EN Postion   1          */ 
#define DEV_CFG_REGS_SPIXIPENABLE_SPI_B_XIP_EN_Msk    (0x1U << DEV_CFG_REGS_SPIXIPENABLE_SPI_B_XIP_EN_Pos)                                  /*!< SPI_B_XIP_EN Mask      0x00000002 */
#define DEV_CFG_REGS_SPIXIPENABLE_SPI_B_XIP_EN_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SPIXIPENABLE_SPI_B_XIP_EN_Pos) & DEV_CFG_REGS_SPIXIPENABLE_SPI_B_XIP_EN_Msk) /*!< SPI_B_XIP_EN Set Value            */
#define DEV_CFG_REGS_SPIXIPENABLE_SPI_B_XIP_EN_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SPIXIPENABLE_SPI_B_XIP_EN_Msk) >> DEV_CFG_REGS_SPIXIPENABLE_SPI_B_XIP_EN_Pos) /*!< SPI_B_XIP_EN Get Value            */


#define DEV_CFG_REGS_SPIXIPENABLE_SPI_A_XIP_EN_Pos    (0U)                                                                                  /*!< SPI_A_XIP_EN Postion   0          */ 
#define DEV_CFG_REGS_SPIXIPENABLE_SPI_A_XIP_EN_Msk    (0x1U << DEV_CFG_REGS_SPIXIPENABLE_SPI_A_XIP_EN_Pos)                                  /*!< SPI_A_XIP_EN Mask      0x00000001 */
#define DEV_CFG_REGS_SPIXIPENABLE_SPI_A_XIP_EN_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_SPIXIPENABLE_SPI_A_XIP_EN_Pos) & DEV_CFG_REGS_SPIXIPENABLE_SPI_A_XIP_EN_Msk) /*!< SPI_A_XIP_EN Set Value            */
#define DEV_CFG_REGS_SPIXIPENABLE_SPI_A_XIP_EN_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_SPIXIPENABLE_SPI_A_XIP_EN_Msk) >> DEV_CFG_REGS_SPIXIPENABLE_SPI_A_XIP_EN_Pos) /*!< SPI_A_XIP_EN Get Value            */


/* HTDBGSEL1 bitfield */
#define DEV_CFG_REGS_HTDBGSEL1_SYSCTRL_DBG_SEL_Pos    (24U)                                                                                 /*!< SYSCTRL_DBG_SEL Postion   24         */ 
#define DEV_CFG_REGS_HTDBGSEL1_SYSCTRL_DBG_SEL_Msk    (0xffU << DEV_CFG_REGS_HTDBGSEL1_SYSCTRL_DBG_SEL_Pos)                                 /*!< SYSCTRL_DBG_SEL Mask      0xFF000000 */
#define DEV_CFG_REGS_HTDBGSEL1_SYSCTRL_DBG_SEL_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_HTDBGSEL1_SYSCTRL_DBG_SEL_Pos) & DEV_CFG_REGS_HTDBGSEL1_SYSCTRL_DBG_SEL_Msk) /*!< SYSCTRL_DBG_SEL Set Value            */
#define DEV_CFG_REGS_HTDBGSEL1_SYSCTRL_DBG_SEL_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_HTDBGSEL1_SYSCTRL_DBG_SEL_Msk) >> DEV_CFG_REGS_HTDBGSEL1_SYSCTRL_DBG_SEL_Pos) /*!< SYSCTRL_DBG_SEL Get Value            */


#define DEV_CFG_REGS_HTDBGSEL1_GS8TO15_DBG_SEL_Pos    (19U)                                                                                 /*!< GS8TO15_DBG_SEL Postion   19         */ 
#define DEV_CFG_REGS_HTDBGSEL1_GS8TO15_DBG_SEL_Msk    (0x7U << DEV_CFG_REGS_HTDBGSEL1_GS8TO15_DBG_SEL_Pos)                                  /*!< GS8TO15_DBG_SEL Mask      0x00380000 */
#define DEV_CFG_REGS_HTDBGSEL1_GS8TO15_DBG_SEL_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_HTDBGSEL1_GS8TO15_DBG_SEL_Pos) & DEV_CFG_REGS_HTDBGSEL1_GS8TO15_DBG_SEL_Msk) /*!< GS8TO15_DBG_SEL Set Value            */
#define DEV_CFG_REGS_HTDBGSEL1_GS8TO15_DBG_SEL_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_HTDBGSEL1_GS8TO15_DBG_SEL_Msk) >> DEV_CFG_REGS_HTDBGSEL1_GS8TO15_DBG_SEL_Pos) /*!< GS8TO15_DBG_SEL Get Value            */


#define DEV_CFG_REGS_HTDBGSEL1_GS0TO7_DBG_SEL_Pos    (16U)                                                                                 /*!< GS0TO7_DBG_SEL Postion   16         */ 
#define DEV_CFG_REGS_HTDBGSEL1_GS0TO7_DBG_SEL_Msk    (0x7U << DEV_CFG_REGS_HTDBGSEL1_GS0TO7_DBG_SEL_Pos)                                   /*!< GS0TO7_DBG_SEL Mask      0x00070000 */
#define DEV_CFG_REGS_HTDBGSEL1_GS0TO7_DBG_SEL_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_HTDBGSEL1_GS0TO7_DBG_SEL_Pos) & DEV_CFG_REGS_HTDBGSEL1_GS0TO7_DBG_SEL_Msk) /*!< GS0TO7_DBG_SEL Set Value            */
#define DEV_CFG_REGS_HTDBGSEL1_GS0TO7_DBG_SEL_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_HTDBGSEL1_GS0TO7_DBG_SEL_Msk) >> DEV_CFG_REGS_HTDBGSEL1_GS0TO7_DBG_SEL_Pos) /*!< GS0TO7_DBG_SEL Get Value            */


#define DEV_CFG_REGS_HTDBGSEL1_IOMUX_DBG_SEL_Pos    (0U)                                                                                  /*!< IOMUX_DBG_SEL Postion   0          */ 
#define DEV_CFG_REGS_HTDBGSEL1_IOMUX_DBG_SEL_Msk    (0xffffU << DEV_CFG_REGS_HTDBGSEL1_IOMUX_DBG_SEL_Pos)                                 /*!< IOMUX_DBG_SEL Mask      0x0000FFFF */
#define DEV_CFG_REGS_HTDBGSEL1_IOMUX_DBG_SEL_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_HTDBGSEL1_IOMUX_DBG_SEL_Pos) & DEV_CFG_REGS_HTDBGSEL1_IOMUX_DBG_SEL_Msk) /*!< IOMUX_DBG_SEL Set Value            */
#define DEV_CFG_REGS_HTDBGSEL1_IOMUX_DBG_SEL_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_HTDBGSEL1_IOMUX_DBG_SEL_Msk) >> DEV_CFG_REGS_HTDBGSEL1_IOMUX_DBG_SEL_Pos) /*!< IOMUX_DBG_SEL Get Value            */


/* NMIWDTRSTCTRL bitfield */
#define DEV_CFG_REGS_NMIWDTRSTCTRL_CPU2_NMIWDRS_CNT_Pos    (8U)                                                                                  /*!< CPU2_NMIWDRS_CNT Postion   8          */ 
#define DEV_CFG_REGS_NMIWDTRSTCTRL_CPU2_NMIWDRS_CNT_Msk    (0xffU << DEV_CFG_REGS_NMIWDTRSTCTRL_CPU2_NMIWDRS_CNT_Pos)                            /*!< CPU2_NMIWDRS_CNT Mask      0x0000FF00 */
#define DEV_CFG_REGS_NMIWDTRSTCTRL_CPU2_NMIWDRS_CNT_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_NMIWDTRSTCTRL_CPU2_NMIWDRS_CNT_Pos) & DEV_CFG_REGS_NMIWDTRSTCTRL_CPU2_NMIWDRS_CNT_Msk) /*!< CPU2_NMIWDRS_CNT Set Value            */
#define DEV_CFG_REGS_NMIWDTRSTCTRL_CPU2_NMIWDRS_CNT_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_NMIWDTRSTCTRL_CPU2_NMIWDRS_CNT_Msk) >> DEV_CFG_REGS_NMIWDTRSTCTRL_CPU2_NMIWDRS_CNT_Pos) /*!< CPU2_NMIWDRS_CNT Get Value            */


#define DEV_CFG_REGS_NMIWDTRSTCTRL_CPU1_NMIWDRS_CNT_Pos    (0U)                                                                                  /*!< CPU1_NMIWDRS_CNT Postion   0          */ 
#define DEV_CFG_REGS_NMIWDTRSTCTRL_CPU1_NMIWDRS_CNT_Msk    (0xffU << DEV_CFG_REGS_NMIWDTRSTCTRL_CPU1_NMIWDRS_CNT_Pos)                            /*!< CPU1_NMIWDRS_CNT Mask      0x000000FF */
#define DEV_CFG_REGS_NMIWDTRSTCTRL_CPU1_NMIWDRS_CNT_Set(x) (((uint32_t) (x) << DEV_CFG_REGS_NMIWDTRSTCTRL_CPU1_NMIWDRS_CNT_Pos) & DEV_CFG_REGS_NMIWDTRSTCTRL_CPU1_NMIWDRS_CNT_Msk) /*!< CPU1_NMIWDRS_CNT Set Value            */
#define DEV_CFG_REGS_NMIWDTRSTCTRL_CPU1_NMIWDRS_CNT_Get(x) (((uint32_t) (x) & DEV_CFG_REGS_NMIWDTRSTCTRL_CPU1_NMIWDRS_CNT_Msk) >> DEV_CFG_REGS_NMIWDTRSTCTRL_CPU1_NMIWDRS_CNT_Pos) /*!< CPU1_NMIWDRS_CNT Get Value            */


/* INTOSC1TRIM bitfield */
#define ANALOG_SUBSYS_REGS_INTOSC1TRIM_VALFINETRIM_Pos    (0U)                                                                                  /*!< VALFINETRIM Postion   0          */ 
#define ANALOG_SUBSYS_REGS_INTOSC1TRIM_VALFINETRIM_Msk    (0xffU << ANALOG_SUBSYS_REGS_INTOSC1TRIM_VALFINETRIM_Pos)                             /*!< VALFINETRIM Mask      0x000000FF */
#define ANALOG_SUBSYS_REGS_INTOSC1TRIM_VALFINETRIM_Set(x) (((uint32_t) (x) << ANALOG_SUBSYS_REGS_INTOSC1TRIM_VALFINETRIM_Pos) & ANALOG_SUBSYS_REGS_INTOSC1TRIM_VALFINETRIM_Msk) /*!< VALFINETRIM Set Value            */
#define ANALOG_SUBSYS_REGS_INTOSC1TRIM_VALFINETRIM_Get(x) (((uint32_t) (x) & ANALOG_SUBSYS_REGS_INTOSC1TRIM_VALFINETRIM_Msk) >> ANALOG_SUBSYS_REGS_INTOSC1TRIM_VALFINETRIM_Pos) /*!< VALFINETRIM Get Value            */


/* INTOSC2TRIM bitfield */
#define ANALOG_SUBSYS_REGS_INTOSC2TRIM_VALFINETRIM_Pos    (0U)                                                                                  /*!< VALFINETRIM Postion   0          */ 
#define ANALOG_SUBSYS_REGS_INTOSC2TRIM_VALFINETRIM_Msk    (0xffU << ANALOG_SUBSYS_REGS_INTOSC2TRIM_VALFINETRIM_Pos)                             /*!< VALFINETRIM Mask      0x000000FF */
#define ANALOG_SUBSYS_REGS_INTOSC2TRIM_VALFINETRIM_Set(x) (((uint32_t) (x) << ANALOG_SUBSYS_REGS_INTOSC2TRIM_VALFINETRIM_Pos) & ANALOG_SUBSYS_REGS_INTOSC2TRIM_VALFINETRIM_Msk) /*!< VALFINETRIM Set Value            */
#define ANALOG_SUBSYS_REGS_INTOSC2TRIM_VALFINETRIM_Get(x) (((uint32_t) (x) & ANALOG_SUBSYS_REGS_INTOSC2TRIM_VALFINETRIM_Msk) >> ANALOG_SUBSYS_REGS_INTOSC2TRIM_VALFINETRIM_Pos) /*!< VALFINETRIM Get Value            */


/* TSNSCTL bitfield */
#define ANALOG_SUBSYS_REGS_TSNSCTL_TS_ENABLE_Pos    (0U)                                                                                  /*!< TS_ENABLE Postion   0          */ 
#define ANALOG_SUBSYS_REGS_TSNSCTL_TS_ENABLE_Msk    (0x1U << ANALOG_SUBSYS_REGS_TSNSCTL_TS_ENABLE_Pos)                                    /*!< TS_ENABLE Mask      0x00000001 */
#define ANALOG_SUBSYS_REGS_TSNSCTL_TS_ENABLE_Set(x) (((uint32_t) (x) << ANALOG_SUBSYS_REGS_TSNSCTL_TS_ENABLE_Pos) & ANALOG_SUBSYS_REGS_TSNSCTL_TS_ENABLE_Msk) /*!< TS_ENABLE Set Value            */
#define ANALOG_SUBSYS_REGS_TSNSCTL_TS_ENABLE_Get(x) (((uint32_t) (x) & ANALOG_SUBSYS_REGS_TSNSCTL_TS_ENABLE_Msk) >> ANALOG_SUBSYS_REGS_TSNSCTL_TS_ENABLE_Pos) /*!< TS_ENABLE Get Value            */


/* LOCK bitfield */
#define ANALOG_SUBSYS_REGS_LOCK_TSNSCTL_Pos    (3U)                                                                                  /*!< TSNSCTL Postion   3          */ 
#define ANALOG_SUBSYS_REGS_LOCK_TSNSCTL_Msk    (0x1U << ANALOG_SUBSYS_REGS_LOCK_TSNSCTL_Pos)                                         /*!< TSNSCTL Mask      0x00000008 */
#define ANALOG_SUBSYS_REGS_LOCK_TSNSCTL_Set(x) (((uint32_t) (x) << ANALOG_SUBSYS_REGS_LOCK_TSNSCTL_Pos) & ANALOG_SUBSYS_REGS_LOCK_TSNSCTL_Msk) /*!< TSNSCTL Set Value            */
#define ANALOG_SUBSYS_REGS_LOCK_TSNSCTL_Get(x) (((uint32_t) (x) & ANALOG_SUBSYS_REGS_LOCK_TSNSCTL_Msk) >> ANALOG_SUBSYS_REGS_LOCK_TSNSCTL_Pos) /*!< TSNSCTL Get Value            */


/* NVRLOCK bitfield */
#define ANALOG_SUBSYS_REGS_NVRLOCK_NVRLOCK_Pos    (0U)                                                                                  /*!< NVRLOCK Postion   0          */ 
#define ANALOG_SUBSYS_REGS_NVRLOCK_NVRLOCK_Msk    (0xffffffffU << ANALOG_SUBSYS_REGS_NVRLOCK_NVRLOCK_Pos)                               /*!< NVRLOCK Mask      0xFFFFFFFF */
#define ANALOG_SUBSYS_REGS_NVRLOCK_NVRLOCK_Set(x) (((uint32_t) (x) << ANALOG_SUBSYS_REGS_NVRLOCK_NVRLOCK_Pos) & ANALOG_SUBSYS_REGS_NVRLOCK_NVRLOCK_Msk) /*!< NVRLOCK Set Value            */
#define ANALOG_SUBSYS_REGS_NVRLOCK_NVRLOCK_Get(x) (((uint32_t) (x) & ANALOG_SUBSYS_REGS_NVRLOCK_NVRLOCK_Msk) >> ANALOG_SUBSYS_REGS_NVRLOCK_NVRLOCK_Pos) /*!< NVRLOCK Get Value            */


/* CLKSEM bitfield */
#define CLK_CFG_REGS_CLKSEM_KEY_Pos    (16U)                                                                                 /*!< KEY Postion   16         */ 
#define CLK_CFG_REGS_CLKSEM_KEY_Msk    (0xffffU << CLK_CFG_REGS_CLKSEM_KEY_Pos)                                              /*!< KEY Mask      0xFFFF0000 */
#define CLK_CFG_REGS_CLKSEM_KEY_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_CLKSEM_KEY_Pos) & CLK_CFG_REGS_CLKSEM_KEY_Msk)       /*!< KEY Set Value            */
#define CLK_CFG_REGS_CLKSEM_KEY_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_CLKSEM_KEY_Msk) >> CLK_CFG_REGS_CLKSEM_KEY_Pos)       /*!< KEY Get Value            */


#define CLK_CFG_REGS_CLKSEM_SEM_Pos    (0U)                                                                                  /*!< SEM Postion   0          */ 
#define CLK_CFG_REGS_CLKSEM_SEM_Msk    (0x3U << CLK_CFG_REGS_CLKSEM_SEM_Pos)                                                 /*!< SEM Mask      0x00000003 */
#define CLK_CFG_REGS_CLKSEM_SEM_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_CLKSEM_SEM_Pos) & CLK_CFG_REGS_CLKSEM_SEM_Msk)       /*!< SEM Set Value            */
#define CLK_CFG_REGS_CLKSEM_SEM_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_CLKSEM_SEM_Msk) >> CLK_CFG_REGS_CLKSEM_SEM_Pos)       /*!< SEM Get Value            */


/* CLKCFGLOCK1 bitfield */
#define CLK_CFG_REGS_CLKCFGLOCK1_LOSPCP_Pos    (15U)                                                                                 /*!< LOSPCP Postion   15         */ 
#define CLK_CFG_REGS_CLKCFGLOCK1_LOSPCP_Msk    (0x1U << CLK_CFG_REGS_CLKCFGLOCK1_LOSPCP_Pos)                                         /*!< LOSPCP Mask      0x00008000 */
#define CLK_CFG_REGS_CLKCFGLOCK1_LOSPCP_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_CLKCFGLOCK1_LOSPCP_Pos) & CLK_CFG_REGS_CLKCFGLOCK1_LOSPCP_Msk) /*!< LOSPCP Set Value            */
#define CLK_CFG_REGS_CLKCFGLOCK1_LOSPCP_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_CLKCFGLOCK1_LOSPCP_Msk) >> CLK_CFG_REGS_CLKCFGLOCK1_LOSPCP_Pos) /*!< LOSPCP Get Value            */


#define CLK_CFG_REGS_CLKCFGLOCK1_PERCLKDIVSEL_Pos    (13U)                                                                                 /*!< PERCLKDIVSEL Postion   13         */ 
#define CLK_CFG_REGS_CLKCFGLOCK1_PERCLKDIVSEL_Msk    (0x1U << CLK_CFG_REGS_CLKCFGLOCK1_PERCLKDIVSEL_Pos)                                   /*!< PERCLKDIVSEL Mask      0x00002000 */
#define CLK_CFG_REGS_CLKCFGLOCK1_PERCLKDIVSEL_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_CLKCFGLOCK1_PERCLKDIVSEL_Pos) & CLK_CFG_REGS_CLKCFGLOCK1_PERCLKDIVSEL_Msk) /*!< PERCLKDIVSEL Set Value            */
#define CLK_CFG_REGS_CLKCFGLOCK1_PERCLKDIVSEL_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_CLKCFGLOCK1_PERCLKDIVSEL_Msk) >> CLK_CFG_REGS_CLKCFGLOCK1_PERCLKDIVSEL_Pos) /*!< PERCLKDIVSEL Get Value            */


#define CLK_CFG_REGS_CLKCFGLOCK1_AUXCLKDIVSEL_Pos    (12U)                                                                                 /*!< AUXCLKDIVSEL Postion   12         */ 
#define CLK_CFG_REGS_CLKCFGLOCK1_AUXCLKDIVSEL_Msk    (0x1U << CLK_CFG_REGS_CLKCFGLOCK1_AUXCLKDIVSEL_Pos)                                   /*!< AUXCLKDIVSEL Mask      0x00001000 */
#define CLK_CFG_REGS_CLKCFGLOCK1_AUXCLKDIVSEL_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_CLKCFGLOCK1_AUXCLKDIVSEL_Pos) & CLK_CFG_REGS_CLKCFGLOCK1_AUXCLKDIVSEL_Msk) /*!< AUXCLKDIVSEL Set Value            */
#define CLK_CFG_REGS_CLKCFGLOCK1_AUXCLKDIVSEL_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_CLKCFGLOCK1_AUXCLKDIVSEL_Msk) >> CLK_CFG_REGS_CLKCFGLOCK1_AUXCLKDIVSEL_Pos) /*!< AUXCLKDIVSEL Get Value            */


#define CLK_CFG_REGS_CLKCFGLOCK1_SYSCLKDIVSEL_Pos    (11U)                                                                                 /*!< SYSCLKDIVSEL Postion   11         */ 
#define CLK_CFG_REGS_CLKCFGLOCK1_SYSCLKDIVSEL_Msk    (0x1U << CLK_CFG_REGS_CLKCFGLOCK1_SYSCLKDIVSEL_Pos)                                   /*!< SYSCLKDIVSEL Mask      0x00000800 */
#define CLK_CFG_REGS_CLKCFGLOCK1_SYSCLKDIVSEL_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_CLKCFGLOCK1_SYSCLKDIVSEL_Pos) & CLK_CFG_REGS_CLKCFGLOCK1_SYSCLKDIVSEL_Msk) /*!< SYSCLKDIVSEL Set Value            */
#define CLK_CFG_REGS_CLKCFGLOCK1_SYSCLKDIVSEL_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_CLKCFGLOCK1_SYSCLKDIVSEL_Msk) >> CLK_CFG_REGS_CLKCFGLOCK1_SYSCLKDIVSEL_Pos) /*!< SYSCLKDIVSEL Get Value            */


#define CLK_CFG_REGS_CLKCFGLOCK1_AUXPLLMULT_Pos    (10U)                                                                                 /*!< AUXPLLMULT Postion   10         */ 
#define CLK_CFG_REGS_CLKCFGLOCK1_AUXPLLMULT_Msk    (0x1U << CLK_CFG_REGS_CLKCFGLOCK1_AUXPLLMULT_Pos)                                     /*!< AUXPLLMULT Mask      0x00000400 */
#define CLK_CFG_REGS_CLKCFGLOCK1_AUXPLLMULT_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_CLKCFGLOCK1_AUXPLLMULT_Pos) & CLK_CFG_REGS_CLKCFGLOCK1_AUXPLLMULT_Msk) /*!< AUXPLLMULT Set Value            */
#define CLK_CFG_REGS_CLKCFGLOCK1_AUXPLLMULT_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_CLKCFGLOCK1_AUXPLLMULT_Msk) >> CLK_CFG_REGS_CLKCFGLOCK1_AUXPLLMULT_Pos) /*!< AUXPLLMULT Get Value            */


#define CLK_CFG_REGS_CLKCFGLOCK1_AUXPLLCTL1_Pos    (7U)                                                                                  /*!< AUXPLLCTL1 Postion   7          */ 
#define CLK_CFG_REGS_CLKCFGLOCK1_AUXPLLCTL1_Msk    (0x1U << CLK_CFG_REGS_CLKCFGLOCK1_AUXPLLCTL1_Pos)                                     /*!< AUXPLLCTL1 Mask      0x00000080 */
#define CLK_CFG_REGS_CLKCFGLOCK1_AUXPLLCTL1_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_CLKCFGLOCK1_AUXPLLCTL1_Pos) & CLK_CFG_REGS_CLKCFGLOCK1_AUXPLLCTL1_Msk) /*!< AUXPLLCTL1 Set Value            */
#define CLK_CFG_REGS_CLKCFGLOCK1_AUXPLLCTL1_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_CLKCFGLOCK1_AUXPLLCTL1_Msk) >> CLK_CFG_REGS_CLKCFGLOCK1_AUXPLLCTL1_Pos) /*!< AUXPLLCTL1 Get Value            */


#define CLK_CFG_REGS_CLKCFGLOCK1_SYSPLLMULT_Pos    (6U)                                                                                  /*!< SYSPLLMULT Postion   6          */ 
#define CLK_CFG_REGS_CLKCFGLOCK1_SYSPLLMULT_Msk    (0x1U << CLK_CFG_REGS_CLKCFGLOCK1_SYSPLLMULT_Pos)                                     /*!< SYSPLLMULT Mask      0x00000040 */
#define CLK_CFG_REGS_CLKCFGLOCK1_SYSPLLMULT_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_CLKCFGLOCK1_SYSPLLMULT_Pos) & CLK_CFG_REGS_CLKCFGLOCK1_SYSPLLMULT_Msk) /*!< SYSPLLMULT Set Value            */
#define CLK_CFG_REGS_CLKCFGLOCK1_SYSPLLMULT_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_CLKCFGLOCK1_SYSPLLMULT_Msk) >> CLK_CFG_REGS_CLKCFGLOCK1_SYSPLLMULT_Pos) /*!< SYSPLLMULT Get Value            */


#define CLK_CFG_REGS_CLKCFGLOCK1_SYSPLLCTL1_Pos    (3U)                                                                                  /*!< SYSPLLCTL1 Postion   3          */ 
#define CLK_CFG_REGS_CLKCFGLOCK1_SYSPLLCTL1_Msk    (0x1U << CLK_CFG_REGS_CLKCFGLOCK1_SYSPLLCTL1_Pos)                                     /*!< SYSPLLCTL1 Mask      0x00000008 */
#define CLK_CFG_REGS_CLKCFGLOCK1_SYSPLLCTL1_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_CLKCFGLOCK1_SYSPLLCTL1_Pos) & CLK_CFG_REGS_CLKCFGLOCK1_SYSPLLCTL1_Msk) /*!< SYSPLLCTL1 Set Value            */
#define CLK_CFG_REGS_CLKCFGLOCK1_SYSPLLCTL1_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_CLKCFGLOCK1_SYSPLLCTL1_Msk) >> CLK_CFG_REGS_CLKCFGLOCK1_SYSPLLCTL1_Pos) /*!< SYSPLLCTL1 Get Value            */


#define CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL3_Pos    (2U)                                                                                  /*!< CLKSRCCTL3 Postion   2          */ 
#define CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL3_Msk    (0x1U << CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL3_Pos)                                     /*!< CLKSRCCTL3 Mask      0x00000004 */
#define CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL3_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL3_Pos) & CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL3_Msk) /*!< CLKSRCCTL3 Set Value            */
#define CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL3_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL3_Msk) >> CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL3_Pos) /*!< CLKSRCCTL3 Get Value            */


#define CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL2_Pos    (1U)                                                                                  /*!< CLKSRCCTL2 Postion   1          */ 
#define CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL2_Msk    (0x1U << CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL2_Pos)                                     /*!< CLKSRCCTL2 Mask      0x00000002 */
#define CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL2_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL2_Pos) & CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL2_Msk) /*!< CLKSRCCTL2 Set Value            */
#define CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL2_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL2_Msk) >> CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL2_Pos) /*!< CLKSRCCTL2 Get Value            */


#define CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL1_Pos    (0U)                                                                                  /*!< CLKSRCCTL1 Postion   0          */ 
#define CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL1_Msk    (0x1U << CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL1_Pos)                                     /*!< CLKSRCCTL1 Mask      0x00000001 */
#define CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL1_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL1_Pos) & CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL1_Msk) /*!< CLKSRCCTL1 Set Value            */
#define CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL1_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL1_Msk) >> CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL1_Pos) /*!< CLKSRCCTL1 Get Value            */


/* CLKSRCCTL1 bitfield */
#define CLK_CFG_REGS_CLKSRCCTL1_XTAL_DS_Pos    (16U)                                                                                 /*!< XTAL_DS Postion   16         */ 
#define CLK_CFG_REGS_CLKSRCCTL1_XTAL_DS_Msk    (0x3U << CLK_CFG_REGS_CLKSRCCTL1_XTAL_DS_Pos)                                         /*!< XTAL_DS Mask      0x00030000 */
#define CLK_CFG_REGS_CLKSRCCTL1_XTAL_DS_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_CLKSRCCTL1_XTAL_DS_Pos) & CLK_CFG_REGS_CLKSRCCTL1_XTAL_DS_Msk) /*!< XTAL_DS Set Value            */
#define CLK_CFG_REGS_CLKSRCCTL1_XTAL_DS_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_CLKSRCCTL1_XTAL_DS_Msk) >> CLK_CFG_REGS_CLKSRCCTL1_XTAL_DS_Pos) /*!< XTAL_DS Get Value            */


#define CLK_CFG_REGS_CLKSRCCTL1_WDHALTI_Pos    (5U)                                                                                  /*!< WDHALTI Postion   5          */ 
#define CLK_CFG_REGS_CLKSRCCTL1_WDHALTI_Msk    (0x1U << CLK_CFG_REGS_CLKSRCCTL1_WDHALTI_Pos)                                         /*!< WDHALTI Mask      0x00000020 */
#define CLK_CFG_REGS_CLKSRCCTL1_WDHALTI_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_CLKSRCCTL1_WDHALTI_Pos) & CLK_CFG_REGS_CLKSRCCTL1_WDHALTI_Msk) /*!< WDHALTI Set Value            */
#define CLK_CFG_REGS_CLKSRCCTL1_WDHALTI_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_CLKSRCCTL1_WDHALTI_Msk) >> CLK_CFG_REGS_CLKSRCCTL1_WDHALTI_Pos) /*!< WDHALTI Get Value            */


#define CLK_CFG_REGS_CLKSRCCTL1_XTALOFF_Pos    (4U)                                                                                  /*!< XTALOFF Postion   4          */ 
#define CLK_CFG_REGS_CLKSRCCTL1_XTALOFF_Msk    (0x1U << CLK_CFG_REGS_CLKSRCCTL1_XTALOFF_Pos)                                         /*!< XTALOFF Mask      0x00000010 */
#define CLK_CFG_REGS_CLKSRCCTL1_XTALOFF_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_CLKSRCCTL1_XTALOFF_Pos) & CLK_CFG_REGS_CLKSRCCTL1_XTALOFF_Msk) /*!< XTALOFF Set Value            */
#define CLK_CFG_REGS_CLKSRCCTL1_XTALOFF_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_CLKSRCCTL1_XTALOFF_Msk) >> CLK_CFG_REGS_CLKSRCCTL1_XTALOFF_Pos) /*!< XTALOFF Get Value            */


#define CLK_CFG_REGS_CLKSRCCTL1_INTOSC2OFF_Pos    (3U)                                                                                  /*!< INTOSC2OFF Postion   3          */ 
#define CLK_CFG_REGS_CLKSRCCTL1_INTOSC2OFF_Msk    (0x1U << CLK_CFG_REGS_CLKSRCCTL1_INTOSC2OFF_Pos)                                      /*!< INTOSC2OFF Mask      0x00000008 */
#define CLK_CFG_REGS_CLKSRCCTL1_INTOSC2OFF_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_CLKSRCCTL1_INTOSC2OFF_Pos) & CLK_CFG_REGS_CLKSRCCTL1_INTOSC2OFF_Msk) /*!< INTOSC2OFF Set Value            */
#define CLK_CFG_REGS_CLKSRCCTL1_INTOSC2OFF_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_CLKSRCCTL1_INTOSC2OFF_Msk) >> CLK_CFG_REGS_CLKSRCCTL1_INTOSC2OFF_Pos) /*!< INTOSC2OFF Get Value            */


#define CLK_CFG_REGS_CLKSRCCTL1_OSCCLKSRCSEL_Pos    (0U)                                                                                  /*!< OSCCLKSRCSEL Postion   0          */ 
#define CLK_CFG_REGS_CLKSRCCTL1_OSCCLKSRCSEL_Msk    (0x3U << CLK_CFG_REGS_CLKSRCCTL1_OSCCLKSRCSEL_Pos)                                    /*!< OSCCLKSRCSEL Mask      0x00000003 */
#define CLK_CFG_REGS_CLKSRCCTL1_OSCCLKSRCSEL_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_CLKSRCCTL1_OSCCLKSRCSEL_Pos) & CLK_CFG_REGS_CLKSRCCTL1_OSCCLKSRCSEL_Msk) /*!< OSCCLKSRCSEL Set Value            */
#define CLK_CFG_REGS_CLKSRCCTL1_OSCCLKSRCSEL_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_CLKSRCCTL1_OSCCLKSRCSEL_Msk) >> CLK_CFG_REGS_CLKSRCCTL1_OSCCLKSRCSEL_Pos) /*!< OSCCLKSRCSEL Get Value            */


/* CLKSRCCTL2 bitfield */
#define CLK_CFG_REGS_CLKSRCCTL2_SPICCLKSEL_Pos    (18U)                                                                                 /*!< SPICCLKSEL Postion   18         */ 
#define CLK_CFG_REGS_CLKSRCCTL2_SPICCLKSEL_Msk    (0x1U << CLK_CFG_REGS_CLKSRCCTL2_SPICCLKSEL_Pos)                                      /*!< SPICCLKSEL Mask      0x00040000 */
#define CLK_CFG_REGS_CLKSRCCTL2_SPICCLKSEL_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_CLKSRCCTL2_SPICCLKSEL_Pos) & CLK_CFG_REGS_CLKSRCCTL2_SPICCLKSEL_Msk) /*!< SPICCLKSEL Set Value            */
#define CLK_CFG_REGS_CLKSRCCTL2_SPICCLKSEL_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_CLKSRCCTL2_SPICCLKSEL_Msk) >> CLK_CFG_REGS_CLKSRCCTL2_SPICCLKSEL_Pos) /*!< SPICCLKSEL Get Value            */


#define CLK_CFG_REGS_CLKSRCCTL2_SPIBCLKSEL_Pos    (17U)                                                                                 /*!< SPIBCLKSEL Postion   17         */ 
#define CLK_CFG_REGS_CLKSRCCTL2_SPIBCLKSEL_Msk    (0x1U << CLK_CFG_REGS_CLKSRCCTL2_SPIBCLKSEL_Pos)                                      /*!< SPIBCLKSEL Mask      0x00020000 */
#define CLK_CFG_REGS_CLKSRCCTL2_SPIBCLKSEL_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_CLKSRCCTL2_SPIBCLKSEL_Pos) & CLK_CFG_REGS_CLKSRCCTL2_SPIBCLKSEL_Msk) /*!< SPIBCLKSEL Set Value            */
#define CLK_CFG_REGS_CLKSRCCTL2_SPIBCLKSEL_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_CLKSRCCTL2_SPIBCLKSEL_Msk) >> CLK_CFG_REGS_CLKSRCCTL2_SPIBCLKSEL_Pos) /*!< SPIBCLKSEL Get Value            */


#define CLK_CFG_REGS_CLKSRCCTL2_SPIACLKSEL_Pos    (16U)                                                                                 /*!< SPIACLKSEL Postion   16         */ 
#define CLK_CFG_REGS_CLKSRCCTL2_SPIACLKSEL_Msk    (0x1U << CLK_CFG_REGS_CLKSRCCTL2_SPIACLKSEL_Pos)                                      /*!< SPIACLKSEL Mask      0x00010000 */
#define CLK_CFG_REGS_CLKSRCCTL2_SPIACLKSEL_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_CLKSRCCTL2_SPIACLKSEL_Pos) & CLK_CFG_REGS_CLKSRCCTL2_SPIACLKSEL_Msk) /*!< SPIACLKSEL Set Value            */
#define CLK_CFG_REGS_CLKSRCCTL2_SPIACLKSEL_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_CLKSRCCTL2_SPIACLKSEL_Msk) >> CLK_CFG_REGS_CLKSRCCTL2_SPIACLKSEL_Pos) /*!< SPIACLKSEL Get Value            */


#define CLK_CFG_REGS_CLKSRCCTL2_CANCBCLKSEL_Pos    (6U)                                                                                  /*!< CANCBCLKSEL Postion   6          */ 
#define CLK_CFG_REGS_CLKSRCCTL2_CANCBCLKSEL_Msk    (0x3U << CLK_CFG_REGS_CLKSRCCTL2_CANCBCLKSEL_Pos)                                     /*!< CANCBCLKSEL Mask      0x000000C0 */
#define CLK_CFG_REGS_CLKSRCCTL2_CANCBCLKSEL_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_CLKSRCCTL2_CANCBCLKSEL_Pos) & CLK_CFG_REGS_CLKSRCCTL2_CANCBCLKSEL_Msk) /*!< CANCBCLKSEL Set Value            */
#define CLK_CFG_REGS_CLKSRCCTL2_CANCBCLKSEL_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_CLKSRCCTL2_CANCBCLKSEL_Msk) >> CLK_CFG_REGS_CLKSRCCTL2_CANCBCLKSEL_Pos) /*!< CANCBCLKSEL Get Value            */


#define CLK_CFG_REGS_CLKSRCCTL2_CANBBCLKSEL_Pos    (4U)                                                                                  /*!< CANBBCLKSEL Postion   4          */ 
#define CLK_CFG_REGS_CLKSRCCTL2_CANBBCLKSEL_Msk    (0x3U << CLK_CFG_REGS_CLKSRCCTL2_CANBBCLKSEL_Pos)                                     /*!< CANBBCLKSEL Mask      0x00000030 */
#define CLK_CFG_REGS_CLKSRCCTL2_CANBBCLKSEL_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_CLKSRCCTL2_CANBBCLKSEL_Pos) & CLK_CFG_REGS_CLKSRCCTL2_CANBBCLKSEL_Msk) /*!< CANBBCLKSEL Set Value            */
#define CLK_CFG_REGS_CLKSRCCTL2_CANBBCLKSEL_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_CLKSRCCTL2_CANBBCLKSEL_Msk) >> CLK_CFG_REGS_CLKSRCCTL2_CANBBCLKSEL_Pos) /*!< CANBBCLKSEL Get Value            */


#define CLK_CFG_REGS_CLKSRCCTL2_CANABCLKSEL_Pos    (2U)                                                                                  /*!< CANABCLKSEL Postion   2          */ 
#define CLK_CFG_REGS_CLKSRCCTL2_CANABCLKSEL_Msk    (0x3U << CLK_CFG_REGS_CLKSRCCTL2_CANABCLKSEL_Pos)                                     /*!< CANABCLKSEL Mask      0x0000000C */
#define CLK_CFG_REGS_CLKSRCCTL2_CANABCLKSEL_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_CLKSRCCTL2_CANABCLKSEL_Pos) & CLK_CFG_REGS_CLKSRCCTL2_CANABCLKSEL_Msk) /*!< CANABCLKSEL Set Value            */
#define CLK_CFG_REGS_CLKSRCCTL2_CANABCLKSEL_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_CLKSRCCTL2_CANABCLKSEL_Msk) >> CLK_CFG_REGS_CLKSRCCTL2_CANABCLKSEL_Pos) /*!< CANABCLKSEL Get Value            */


#define CLK_CFG_REGS_CLKSRCCTL2_AUXOSCCLKSRCSEL_Pos    (0U)                                                                                  /*!< AUXOSCCLKSRCSEL Postion   0          */ 
#define CLK_CFG_REGS_CLKSRCCTL2_AUXOSCCLKSRCSEL_Msk    (0x3U << CLK_CFG_REGS_CLKSRCCTL2_AUXOSCCLKSRCSEL_Pos)                                 /*!< AUXOSCCLKSRCSEL Mask      0x00000003 */
#define CLK_CFG_REGS_CLKSRCCTL2_AUXOSCCLKSRCSEL_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_CLKSRCCTL2_AUXOSCCLKSRCSEL_Pos) & CLK_CFG_REGS_CLKSRCCTL2_AUXOSCCLKSRCSEL_Msk) /*!< AUXOSCCLKSRCSEL Set Value            */
#define CLK_CFG_REGS_CLKSRCCTL2_AUXOSCCLKSRCSEL_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_CLKSRCCTL2_AUXOSCCLKSRCSEL_Msk) >> CLK_CFG_REGS_CLKSRCCTL2_AUXOSCCLKSRCSEL_Pos) /*!< AUXOSCCLKSRCSEL Get Value            */


/* CLKSRCCTL3 bitfield */
#define CLK_CFG_REGS_CLKSRCCTL3_XCLKOUTSEL_Pos    (0U)                                                                                  /*!< XCLKOUTSEL Postion   0          */ 
#define CLK_CFG_REGS_CLKSRCCTL3_XCLKOUTSEL_Msk    (0x7U << CLK_CFG_REGS_CLKSRCCTL3_XCLKOUTSEL_Pos)                                      /*!< XCLKOUTSEL Mask      0x00000007 */
#define CLK_CFG_REGS_CLKSRCCTL3_XCLKOUTSEL_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_CLKSRCCTL3_XCLKOUTSEL_Pos) & CLK_CFG_REGS_CLKSRCCTL3_XCLKOUTSEL_Msk) /*!< XCLKOUTSEL Set Value            */
#define CLK_CFG_REGS_CLKSRCCTL3_XCLKOUTSEL_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_CLKSRCCTL3_XCLKOUTSEL_Msk) >> CLK_CFG_REGS_CLKSRCCTL3_XCLKOUTSEL_Pos) /*!< XCLKOUTSEL Get Value            */


/* SYSPLLCTL1 bitfield */
#define CLK_CFG_REGS_SYSPLLCTL1_LDO_RSTB_Pos    (27U)                                                                                 /*!< LDO_RSTB Postion   27         */ 
#define CLK_CFG_REGS_SYSPLLCTL1_LDO_RSTB_Msk    (0x1U << CLK_CFG_REGS_SYSPLLCTL1_LDO_RSTB_Pos)                                        /*!< LDO_RSTB Mask      0x08000000 */
#define CLK_CFG_REGS_SYSPLLCTL1_LDO_RSTB_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_SYSPLLCTL1_LDO_RSTB_Pos) & CLK_CFG_REGS_SYSPLLCTL1_LDO_RSTB_Msk) /*!< LDO_RSTB Set Value            */
#define CLK_CFG_REGS_SYSPLLCTL1_LDO_RSTB_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_SYSPLLCTL1_LDO_RSTB_Msk) >> CLK_CFG_REGS_SYSPLLCTL1_LDO_RSTB_Pos) /*!< LDO_RSTB Get Value            */


#define CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_SEL_Pos    (26U)                                                                                 /*!< PLL_CKREF_SEL Postion   26         */ 
#define CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_SEL_Msk    (0x1U << CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_SEL_Pos)                                   /*!< PLL_CKREF_SEL Mask      0x04000000 */
#define CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_SEL_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_SEL_Pos) & CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_SEL_Msk) /*!< PLL_CKREF_SEL Set Value            */
#define CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_SEL_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_SEL_Msk) >> CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_SEL_Pos) /*!< PLL_CKREF_SEL Get Value            */


#define CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_DIV_Pos    (23U)                                                                                 /*!< PLL_CKREF_DIV Postion   23         */ 
#define CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_DIV_Msk    (0x7U << CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_DIV_Pos)                                   /*!< PLL_CKREF_DIV Mask      0x03800000 */
#define CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_DIV_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_DIV_Pos) & CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_DIV_Msk) /*!< PLL_CKREF_DIV Set Value            */
#define CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_DIV_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_DIV_Msk) >> CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_DIV_Pos) /*!< PLL_CKREF_DIV Get Value            */


#define CLK_CFG_REGS_SYSPLLCTL1_PLL_VCO_BAND_Pos    (22U)                                                                                 /*!< PLL_VCO_BAND Postion   22         */ 
#define CLK_CFG_REGS_SYSPLLCTL1_PLL_VCO_BAND_Msk    (0x1U << CLK_CFG_REGS_SYSPLLCTL1_PLL_VCO_BAND_Pos)                                    /*!< PLL_VCO_BAND Mask      0x00400000 */
#define CLK_CFG_REGS_SYSPLLCTL1_PLL_VCO_BAND_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_SYSPLLCTL1_PLL_VCO_BAND_Pos) & CLK_CFG_REGS_SYSPLLCTL1_PLL_VCO_BAND_Msk) /*!< PLL_VCO_BAND Set Value            */
#define CLK_CFG_REGS_SYSPLLCTL1_PLL_VCO_BAND_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_SYSPLLCTL1_PLL_VCO_BAND_Msk) >> CLK_CFG_REGS_SYSPLLCTL1_PLL_VCO_BAND_Pos) /*!< PLL_VCO_BAND Get Value            */


#define CLK_CFG_REGS_SYSPLLCTL1_PLL_ICP_Pos    (19U)                                                                                 /*!< PLL_ICP Postion   19         */ 
#define CLK_CFG_REGS_SYSPLLCTL1_PLL_ICP_Msk    (0x7U << CLK_CFG_REGS_SYSPLLCTL1_PLL_ICP_Pos)                                         /*!< PLL_ICP Mask      0x00380000 */
#define CLK_CFG_REGS_SYSPLLCTL1_PLL_ICP_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_SYSPLLCTL1_PLL_ICP_Pos) & CLK_CFG_REGS_SYSPLLCTL1_PLL_ICP_Msk) /*!< PLL_ICP Set Value            */
#define CLK_CFG_REGS_SYSPLLCTL1_PLL_ICP_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_SYSPLLCTL1_PLL_ICP_Msk) >> CLK_CFG_REGS_SYSPLLCTL1_PLL_ICP_Pos) /*!< PLL_ICP Get Value            */


#define CLK_CFG_REGS_SYSPLLCTL1_PLL_LPF_Pos    (17U)                                                                                 /*!< PLL_LPF Postion   17         */ 
#define CLK_CFG_REGS_SYSPLLCTL1_PLL_LPF_Msk    (0x3U << CLK_CFG_REGS_SYSPLLCTL1_PLL_LPF_Pos)                                         /*!< PLL_LPF Mask      0x00060000 */
#define CLK_CFG_REGS_SYSPLLCTL1_PLL_LPF_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_SYSPLLCTL1_PLL_LPF_Pos) & CLK_CFG_REGS_SYSPLLCTL1_PLL_LPF_Msk) /*!< PLL_LPF Set Value            */
#define CLK_CFG_REGS_SYSPLLCTL1_PLL_LPF_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_SYSPLLCTL1_PLL_LPF_Msk) >> CLK_CFG_REGS_SYSPLLCTL1_PLL_LPF_Pos) /*!< PLL_LPF Get Value            */


#define CLK_CFG_REGS_SYSPLLCTL1_PLL_LDO_EN_Pos    (16U)                                                                                 /*!< PLL_LDO_EN Postion   16         */ 
#define CLK_CFG_REGS_SYSPLLCTL1_PLL_LDO_EN_Msk    (0x1U << CLK_CFG_REGS_SYSPLLCTL1_PLL_LDO_EN_Pos)                                      /*!< PLL_LDO_EN Mask      0x00010000 */
#define CLK_CFG_REGS_SYSPLLCTL1_PLL_LDO_EN_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_SYSPLLCTL1_PLL_LDO_EN_Pos) & CLK_CFG_REGS_SYSPLLCTL1_PLL_LDO_EN_Msk) /*!< PLL_LDO_EN Set Value            */
#define CLK_CFG_REGS_SYSPLLCTL1_PLL_LDO_EN_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_SYSPLLCTL1_PLL_LDO_EN_Msk) >> CLK_CFG_REGS_SYSPLLCTL1_PLL_LDO_EN_Pos) /*!< PLL_LDO_EN Get Value            */


#define CLK_CFG_REGS_SYSPLLCTL1_PLLCLKEN_Pos    (1U)                                                                                  /*!< PLLCLKEN Postion   1          */ 
#define CLK_CFG_REGS_SYSPLLCTL1_PLLCLKEN_Msk    (0x1U << CLK_CFG_REGS_SYSPLLCTL1_PLLCLKEN_Pos)                                        /*!< PLLCLKEN Mask      0x00000002 */
#define CLK_CFG_REGS_SYSPLLCTL1_PLLCLKEN_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_SYSPLLCTL1_PLLCLKEN_Pos) & CLK_CFG_REGS_SYSPLLCTL1_PLLCLKEN_Msk) /*!< PLLCLKEN Set Value            */
#define CLK_CFG_REGS_SYSPLLCTL1_PLLCLKEN_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_SYSPLLCTL1_PLLCLKEN_Msk) >> CLK_CFG_REGS_SYSPLLCTL1_PLLCLKEN_Pos) /*!< PLLCLKEN Get Value            */


#define CLK_CFG_REGS_SYSPLLCTL1_PLLEN_Pos    (0U)                                                                                  /*!< PLLEN Postion   0          */ 
#define CLK_CFG_REGS_SYSPLLCTL1_PLLEN_Msk    (0x1U << CLK_CFG_REGS_SYSPLLCTL1_PLLEN_Pos)                                           /*!< PLLEN Mask      0x00000001 */
#define CLK_CFG_REGS_SYSPLLCTL1_PLLEN_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_SYSPLLCTL1_PLLEN_Pos) & CLK_CFG_REGS_SYSPLLCTL1_PLLEN_Msk) /*!< PLLEN Set Value            */
#define CLK_CFG_REGS_SYSPLLCTL1_PLLEN_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_SYSPLLCTL1_PLLEN_Msk) >> CLK_CFG_REGS_SYSPLLCTL1_PLLEN_Pos) /*!< PLLEN Get Value            */


/* SYSPLLMULT bitfield */
#define CLK_CFG_REGS_SYSPLLMULT_ORDER_Pos    (31U)                                                                                 /*!< ORDER Postion   31         */ 
#define CLK_CFG_REGS_SYSPLLMULT_ORDER_Msk    (0x1U << CLK_CFG_REGS_SYSPLLMULT_ORDER_Pos)                                           /*!< ORDER Mask      0x80000000 */
#define CLK_CFG_REGS_SYSPLLMULT_ORDER_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_SYSPLLMULT_ORDER_Pos) & CLK_CFG_REGS_SYSPLLMULT_ORDER_Msk) /*!< ORDER Set Value            */
#define CLK_CFG_REGS_SYSPLLMULT_ORDER_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_SYSPLLMULT_ORDER_Msk) >> CLK_CFG_REGS_SYSPLLMULT_ORDER_Pos) /*!< ORDER Get Value            */


#define CLK_CFG_REGS_SYSPLLMULT_BYPASS_PI_Pos    (30U)                                                                                 /*!< BYPASS_PI Postion   30         */ 
#define CLK_CFG_REGS_SYSPLLMULT_BYPASS_PI_Msk    (0x1U << CLK_CFG_REGS_SYSPLLMULT_BYPASS_PI_Pos)                                       /*!< BYPASS_PI Mask      0x40000000 */
#define CLK_CFG_REGS_SYSPLLMULT_BYPASS_PI_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_SYSPLLMULT_BYPASS_PI_Pos) & CLK_CFG_REGS_SYSPLLMULT_BYPASS_PI_Msk) /*!< BYPASS_PI Set Value            */
#define CLK_CFG_REGS_SYSPLLMULT_BYPASS_PI_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_SYSPLLMULT_BYPASS_PI_Msk) >> CLK_CFG_REGS_SYSPLLMULT_BYPASS_PI_Pos) /*!< BYPASS_PI Get Value            */


#define CLK_CFG_REGS_SYSPLLMULT_REG_DOT_FCW_Pos    (19U)                                                                                 /*!< REG_DOT_FCW Postion   19         */ 
#define CLK_CFG_REGS_SYSPLLMULT_REG_DOT_FCW_Msk    (0x7U << CLK_CFG_REGS_SYSPLLMULT_REG_DOT_FCW_Pos)                                     /*!< REG_DOT_FCW Mask      0x00380000 */
#define CLK_CFG_REGS_SYSPLLMULT_REG_DOT_FCW_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_SYSPLLMULT_REG_DOT_FCW_Pos) & CLK_CFG_REGS_SYSPLLMULT_REG_DOT_FCW_Msk) /*!< REG_DOT_FCW Set Value            */
#define CLK_CFG_REGS_SYSPLLMULT_REG_DOT_FCW_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_SYSPLLMULT_REG_DOT_FCW_Msk) >> CLK_CFG_REGS_SYSPLLMULT_REG_DOT_FCW_Pos) /*!< REG_DOT_FCW Get Value            */


#define CLK_CFG_REGS_SYSPLLMULT_FCW_SSC_Pos    (0U)                                                                                  /*!< FCW_SSC Postion   0          */ 
#define CLK_CFG_REGS_SYSPLLMULT_FCW_SSC_Msk    (0x7ffffU << CLK_CFG_REGS_SYSPLLMULT_FCW_SSC_Pos)                                     /*!< FCW_SSC Mask      0x0007FFFF */
#define CLK_CFG_REGS_SYSPLLMULT_FCW_SSC_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_SYSPLLMULT_FCW_SSC_Pos) & CLK_CFG_REGS_SYSPLLMULT_FCW_SSC_Msk) /*!< FCW_SSC Set Value            */
#define CLK_CFG_REGS_SYSPLLMULT_FCW_SSC_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_SYSPLLMULT_FCW_SSC_Msk) >> CLK_CFG_REGS_SYSPLLMULT_FCW_SSC_Pos) /*!< FCW_SSC Get Value            */


/* SYSPLLSTS bitfield */
#define CLK_CFG_REGS_SYSPLLSTS_LOCKS_Pos    (0U)                                                                                  /*!< LOCKS Postion   0          */ 
#define CLK_CFG_REGS_SYSPLLSTS_LOCKS_Msk    (0x1U << CLK_CFG_REGS_SYSPLLSTS_LOCKS_Pos)                                            /*!< LOCKS Mask      0x00000001 */
#define CLK_CFG_REGS_SYSPLLSTS_LOCKS_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_SYSPLLSTS_LOCKS_Pos) & CLK_CFG_REGS_SYSPLLSTS_LOCKS_Msk) /*!< LOCKS Set Value            */
#define CLK_CFG_REGS_SYSPLLSTS_LOCKS_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_SYSPLLSTS_LOCKS_Msk) >> CLK_CFG_REGS_SYSPLLSTS_LOCKS_Pos) /*!< LOCKS Get Value            */


/* AUXPLLCTL1 bitfield */
#define CLK_CFG_REGS_AUXPLLCTL1_LDO_RSTB_Pos    (27U)                                                                                 /*!< LDO_RSTB Postion   27         */ 
#define CLK_CFG_REGS_AUXPLLCTL1_LDO_RSTB_Msk    (0x1U << CLK_CFG_REGS_AUXPLLCTL1_LDO_RSTB_Pos)                                        /*!< LDO_RSTB Mask      0x08000000 */
#define CLK_CFG_REGS_AUXPLLCTL1_LDO_RSTB_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_AUXPLLCTL1_LDO_RSTB_Pos) & CLK_CFG_REGS_AUXPLLCTL1_LDO_RSTB_Msk) /*!< LDO_RSTB Set Value            */
#define CLK_CFG_REGS_AUXPLLCTL1_LDO_RSTB_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_AUXPLLCTL1_LDO_RSTB_Msk) >> CLK_CFG_REGS_AUXPLLCTL1_LDO_RSTB_Pos) /*!< LDO_RSTB Get Value            */


#define CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_SEL_Pos    (26U)                                                                                 /*!< PLL_CKREF_SEL Postion   26         */ 
#define CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_SEL_Msk    (0x1U << CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_SEL_Pos)                                   /*!< PLL_CKREF_SEL Mask      0x04000000 */
#define CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_SEL_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_SEL_Pos) & CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_SEL_Msk) /*!< PLL_CKREF_SEL Set Value            */
#define CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_SEL_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_SEL_Msk) >> CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_SEL_Pos) /*!< PLL_CKREF_SEL Get Value            */


#define CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_DIV_Pos    (23U)                                                                                 /*!< PLL_CKREF_DIV Postion   23         */ 
#define CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_DIV_Msk    (0x7U << CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_DIV_Pos)                                   /*!< PLL_CKREF_DIV Mask      0x03800000 */
#define CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_DIV_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_DIV_Pos) & CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_DIV_Msk) /*!< PLL_CKREF_DIV Set Value            */
#define CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_DIV_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_DIV_Msk) >> CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_DIV_Pos) /*!< PLL_CKREF_DIV Get Value            */


#define CLK_CFG_REGS_AUXPLLCTL1_PLL_VCO_BAND_Pos    (22U)                                                                                 /*!< PLL_VCO_BAND Postion   22         */ 
#define CLK_CFG_REGS_AUXPLLCTL1_PLL_VCO_BAND_Msk    (0x1U << CLK_CFG_REGS_AUXPLLCTL1_PLL_VCO_BAND_Pos)                                    /*!< PLL_VCO_BAND Mask      0x00400000 */
#define CLK_CFG_REGS_AUXPLLCTL1_PLL_VCO_BAND_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_AUXPLLCTL1_PLL_VCO_BAND_Pos) & CLK_CFG_REGS_AUXPLLCTL1_PLL_VCO_BAND_Msk) /*!< PLL_VCO_BAND Set Value            */
#define CLK_CFG_REGS_AUXPLLCTL1_PLL_VCO_BAND_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_AUXPLLCTL1_PLL_VCO_BAND_Msk) >> CLK_CFG_REGS_AUXPLLCTL1_PLL_VCO_BAND_Pos) /*!< PLL_VCO_BAND Get Value            */


#define CLK_CFG_REGS_AUXPLLCTL1_PLL_ICP_Pos    (19U)                                                                                 /*!< PLL_ICP Postion   19         */ 
#define CLK_CFG_REGS_AUXPLLCTL1_PLL_ICP_Msk    (0x7U << CLK_CFG_REGS_AUXPLLCTL1_PLL_ICP_Pos)                                         /*!< PLL_ICP Mask      0x00380000 */
#define CLK_CFG_REGS_AUXPLLCTL1_PLL_ICP_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_AUXPLLCTL1_PLL_ICP_Pos) & CLK_CFG_REGS_AUXPLLCTL1_PLL_ICP_Msk) /*!< PLL_ICP Set Value            */
#define CLK_CFG_REGS_AUXPLLCTL1_PLL_ICP_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_AUXPLLCTL1_PLL_ICP_Msk) >> CLK_CFG_REGS_AUXPLLCTL1_PLL_ICP_Pos) /*!< PLL_ICP Get Value            */


#define CLK_CFG_REGS_AUXPLLCTL1_PLL_LPF_Pos    (17U)                                                                                 /*!< PLL_LPF Postion   17         */ 
#define CLK_CFG_REGS_AUXPLLCTL1_PLL_LPF_Msk    (0x3U << CLK_CFG_REGS_AUXPLLCTL1_PLL_LPF_Pos)                                         /*!< PLL_LPF Mask      0x00060000 */
#define CLK_CFG_REGS_AUXPLLCTL1_PLL_LPF_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_AUXPLLCTL1_PLL_LPF_Pos) & CLK_CFG_REGS_AUXPLLCTL1_PLL_LPF_Msk) /*!< PLL_LPF Set Value            */
#define CLK_CFG_REGS_AUXPLLCTL1_PLL_LPF_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_AUXPLLCTL1_PLL_LPF_Msk) >> CLK_CFG_REGS_AUXPLLCTL1_PLL_LPF_Pos) /*!< PLL_LPF Get Value            */


#define CLK_CFG_REGS_AUXPLLCTL1_PLL_LDO_EN_Pos    (16U)                                                                                 /*!< PLL_LDO_EN Postion   16         */ 
#define CLK_CFG_REGS_AUXPLLCTL1_PLL_LDO_EN_Msk    (0x1U << CLK_CFG_REGS_AUXPLLCTL1_PLL_LDO_EN_Pos)                                      /*!< PLL_LDO_EN Mask      0x00010000 */
#define CLK_CFG_REGS_AUXPLLCTL1_PLL_LDO_EN_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_AUXPLLCTL1_PLL_LDO_EN_Pos) & CLK_CFG_REGS_AUXPLLCTL1_PLL_LDO_EN_Msk) /*!< PLL_LDO_EN Set Value            */
#define CLK_CFG_REGS_AUXPLLCTL1_PLL_LDO_EN_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_AUXPLLCTL1_PLL_LDO_EN_Msk) >> CLK_CFG_REGS_AUXPLLCTL1_PLL_LDO_EN_Pos) /*!< PLL_LDO_EN Get Value            */


#define CLK_CFG_REGS_AUXPLLCTL1_PLLCLKEN_Pos    (1U)                                                                                  /*!< PLLCLKEN Postion   1          */ 
#define CLK_CFG_REGS_AUXPLLCTL1_PLLCLKEN_Msk    (0x1U << CLK_CFG_REGS_AUXPLLCTL1_PLLCLKEN_Pos)                                        /*!< PLLCLKEN Mask      0x00000002 */
#define CLK_CFG_REGS_AUXPLLCTL1_PLLCLKEN_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_AUXPLLCTL1_PLLCLKEN_Pos) & CLK_CFG_REGS_AUXPLLCTL1_PLLCLKEN_Msk) /*!< PLLCLKEN Set Value            */
#define CLK_CFG_REGS_AUXPLLCTL1_PLLCLKEN_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_AUXPLLCTL1_PLLCLKEN_Msk) >> CLK_CFG_REGS_AUXPLLCTL1_PLLCLKEN_Pos) /*!< PLLCLKEN Get Value            */


#define CLK_CFG_REGS_AUXPLLCTL1_PLLEN_Pos    (0U)                                                                                  /*!< PLLEN Postion   0          */ 
#define CLK_CFG_REGS_AUXPLLCTL1_PLLEN_Msk    (0x1U << CLK_CFG_REGS_AUXPLLCTL1_PLLEN_Pos)                                           /*!< PLLEN Mask      0x00000001 */
#define CLK_CFG_REGS_AUXPLLCTL1_PLLEN_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_AUXPLLCTL1_PLLEN_Pos) & CLK_CFG_REGS_AUXPLLCTL1_PLLEN_Msk) /*!< PLLEN Set Value            */
#define CLK_CFG_REGS_AUXPLLCTL1_PLLEN_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_AUXPLLCTL1_PLLEN_Msk) >> CLK_CFG_REGS_AUXPLLCTL1_PLLEN_Pos) /*!< PLLEN Get Value            */


/* AUXPLLMULT bitfield */
#define CLK_CFG_REGS_AUXPLLMULT_ORDER_Pos    (31U)                                                                                 /*!< ORDER Postion   31         */ 
#define CLK_CFG_REGS_AUXPLLMULT_ORDER_Msk    (0x1U << CLK_CFG_REGS_AUXPLLMULT_ORDER_Pos)                                           /*!< ORDER Mask      0x80000000 */
#define CLK_CFG_REGS_AUXPLLMULT_ORDER_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_AUXPLLMULT_ORDER_Pos) & CLK_CFG_REGS_AUXPLLMULT_ORDER_Msk) /*!< ORDER Set Value            */
#define CLK_CFG_REGS_AUXPLLMULT_ORDER_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_AUXPLLMULT_ORDER_Msk) >> CLK_CFG_REGS_AUXPLLMULT_ORDER_Pos) /*!< ORDER Get Value            */


#define CLK_CFG_REGS_AUXPLLMULT_BYPASS_PI_Pos    (30U)                                                                                 /*!< BYPASS_PI Postion   30         */ 
#define CLK_CFG_REGS_AUXPLLMULT_BYPASS_PI_Msk    (0x1U << CLK_CFG_REGS_AUXPLLMULT_BYPASS_PI_Pos)                                       /*!< BYPASS_PI Mask      0x40000000 */
#define CLK_CFG_REGS_AUXPLLMULT_BYPASS_PI_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_AUXPLLMULT_BYPASS_PI_Pos) & CLK_CFG_REGS_AUXPLLMULT_BYPASS_PI_Msk) /*!< BYPASS_PI Set Value            */
#define CLK_CFG_REGS_AUXPLLMULT_BYPASS_PI_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_AUXPLLMULT_BYPASS_PI_Msk) >> CLK_CFG_REGS_AUXPLLMULT_BYPASS_PI_Pos) /*!< BYPASS_PI Get Value            */


#define CLK_CFG_REGS_AUXPLLMULT_REG_DOT_FCW_Pos    (19U)                                                                                 /*!< REG_DOT_FCW Postion   19         */ 
#define CLK_CFG_REGS_AUXPLLMULT_REG_DOT_FCW_Msk    (0x7U << CLK_CFG_REGS_AUXPLLMULT_REG_DOT_FCW_Pos)                                     /*!< REG_DOT_FCW Mask      0x00380000 */
#define CLK_CFG_REGS_AUXPLLMULT_REG_DOT_FCW_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_AUXPLLMULT_REG_DOT_FCW_Pos) & CLK_CFG_REGS_AUXPLLMULT_REG_DOT_FCW_Msk) /*!< REG_DOT_FCW Set Value            */
#define CLK_CFG_REGS_AUXPLLMULT_REG_DOT_FCW_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_AUXPLLMULT_REG_DOT_FCW_Msk) >> CLK_CFG_REGS_AUXPLLMULT_REG_DOT_FCW_Pos) /*!< REG_DOT_FCW Get Value            */


#define CLK_CFG_REGS_AUXPLLMULT_FCW_SSC_Pos    (0U)                                                                                  /*!< FCW_SSC Postion   0          */ 
#define CLK_CFG_REGS_AUXPLLMULT_FCW_SSC_Msk    (0x7ffffU << CLK_CFG_REGS_AUXPLLMULT_FCW_SSC_Pos)                                     /*!< FCW_SSC Mask      0x0007FFFF */
#define CLK_CFG_REGS_AUXPLLMULT_FCW_SSC_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_AUXPLLMULT_FCW_SSC_Pos) & CLK_CFG_REGS_AUXPLLMULT_FCW_SSC_Msk) /*!< FCW_SSC Set Value            */
#define CLK_CFG_REGS_AUXPLLMULT_FCW_SSC_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_AUXPLLMULT_FCW_SSC_Msk) >> CLK_CFG_REGS_AUXPLLMULT_FCW_SSC_Pos) /*!< FCW_SSC Get Value            */


/* AUXPLLSTS bitfield */
#define CLK_CFG_REGS_AUXPLLSTS_LOCKS_Pos    (0U)                                                                                  /*!< LOCKS Postion   0          */ 
#define CLK_CFG_REGS_AUXPLLSTS_LOCKS_Msk    (0x1U << CLK_CFG_REGS_AUXPLLSTS_LOCKS_Pos)                                            /*!< LOCKS Mask      0x00000001 */
#define CLK_CFG_REGS_AUXPLLSTS_LOCKS_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_AUXPLLSTS_LOCKS_Pos) & CLK_CFG_REGS_AUXPLLSTS_LOCKS_Msk) /*!< LOCKS Set Value            */
#define CLK_CFG_REGS_AUXPLLSTS_LOCKS_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_AUXPLLSTS_LOCKS_Msk) >> CLK_CFG_REGS_AUXPLLSTS_LOCKS_Pos) /*!< LOCKS Get Value            */


/* SYSCLKDIVSEL bitfield */
#define CLK_CFG_REGS_SYSCLKDIVSEL_PLLSYSCLKDIV_Pos    (0U)                                                                                  /*!< PLLSYSCLKDIV Postion   0          */ 
#define CLK_CFG_REGS_SYSCLKDIVSEL_PLLSYSCLKDIV_Msk    (0x3fU << CLK_CFG_REGS_SYSCLKDIVSEL_PLLSYSCLKDIV_Pos)                                 /*!< PLLSYSCLKDIV Mask      0x0000003F */
#define CLK_CFG_REGS_SYSCLKDIVSEL_PLLSYSCLKDIV_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_SYSCLKDIVSEL_PLLSYSCLKDIV_Pos) & CLK_CFG_REGS_SYSCLKDIVSEL_PLLSYSCLKDIV_Msk) /*!< PLLSYSCLKDIV Set Value            */
#define CLK_CFG_REGS_SYSCLKDIVSEL_PLLSYSCLKDIV_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_SYSCLKDIVSEL_PLLSYSCLKDIV_Msk) >> CLK_CFG_REGS_SYSCLKDIVSEL_PLLSYSCLKDIV_Pos) /*!< PLLSYSCLKDIV Get Value            */


/* AUXCLKDIVSEL bitfield */
#define CLK_CFG_REGS_AUXCLKDIVSEL_AUXPLLDIV_Pos    (0U)                                                                                  /*!< AUXPLLDIV Postion   0          */ 
#define CLK_CFG_REGS_AUXCLKDIVSEL_AUXPLLDIV_Msk    (0x3U << CLK_CFG_REGS_AUXCLKDIVSEL_AUXPLLDIV_Pos)                                     /*!< AUXPLLDIV Mask      0x00000003 */
#define CLK_CFG_REGS_AUXCLKDIVSEL_AUXPLLDIV_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_AUXCLKDIVSEL_AUXPLLDIV_Pos) & CLK_CFG_REGS_AUXCLKDIVSEL_AUXPLLDIV_Msk) /*!< AUXPLLDIV Set Value            */
#define CLK_CFG_REGS_AUXCLKDIVSEL_AUXPLLDIV_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_AUXCLKDIVSEL_AUXPLLDIV_Msk) >> CLK_CFG_REGS_AUXCLKDIVSEL_AUXPLLDIV_Pos) /*!< AUXPLLDIV Get Value            */


/* PERCLKDIVSEL bitfield */
#define CLK_CFG_REGS_PERCLKDIVSEL_EMIF1CLKDIV_Pos    (4U)                                                                                  /*!< EMIF1CLKDIV Postion   4          */ 
#define CLK_CFG_REGS_PERCLKDIVSEL_EMIF1CLKDIV_Msk    (0x1U << CLK_CFG_REGS_PERCLKDIVSEL_EMIF1CLKDIV_Pos)                                   /*!< EMIF1CLKDIV Mask      0x00000010 */
#define CLK_CFG_REGS_PERCLKDIVSEL_EMIF1CLKDIV_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_PERCLKDIVSEL_EMIF1CLKDIV_Pos) & CLK_CFG_REGS_PERCLKDIVSEL_EMIF1CLKDIV_Msk) /*!< EMIF1CLKDIV Set Value            */
#define CLK_CFG_REGS_PERCLKDIVSEL_EMIF1CLKDIV_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_PERCLKDIVSEL_EMIF1CLKDIV_Msk) >> CLK_CFG_REGS_PERCLKDIVSEL_EMIF1CLKDIV_Pos) /*!< EMIF1CLKDIV Get Value            */


/* XCLKOUTDIVSEL bitfield */
#define CLK_CFG_REGS_XCLKOUTDIVSEL_XCLKOUTDIV_Pos    (0U)                                                                                  /*!< XCLKOUTDIV Postion   0          */ 
#define CLK_CFG_REGS_XCLKOUTDIVSEL_XCLKOUTDIV_Msk    (0x3U << CLK_CFG_REGS_XCLKOUTDIVSEL_XCLKOUTDIV_Pos)                                   /*!< XCLKOUTDIV Mask      0x00000003 */
#define CLK_CFG_REGS_XCLKOUTDIVSEL_XCLKOUTDIV_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_XCLKOUTDIVSEL_XCLKOUTDIV_Pos) & CLK_CFG_REGS_XCLKOUTDIVSEL_XCLKOUTDIV_Msk) /*!< XCLKOUTDIV Set Value            */
#define CLK_CFG_REGS_XCLKOUTDIVSEL_XCLKOUTDIV_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_XCLKOUTDIVSEL_XCLKOUTDIV_Msk) >> CLK_CFG_REGS_XCLKOUTDIVSEL_XCLKOUTDIV_Pos) /*!< XCLKOUTDIV Get Value            */


/* LOSPCP bitfield */
/* MCDCR bitfield */
#define CLK_CFG_REGS_MCDCR_OSCOFF_Pos    (3U)                                                                                  /*!< OSCOFF Postion   3          */ 
#define CLK_CFG_REGS_MCDCR_OSCOFF_Msk    (0x1U << CLK_CFG_REGS_MCDCR_OSCOFF_Pos)                                               /*!< OSCOFF Mask      0x00000008 */
#define CLK_CFG_REGS_MCDCR_OSCOFF_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_MCDCR_OSCOFF_Pos) & CLK_CFG_REGS_MCDCR_OSCOFF_Msk)   /*!< OSCOFF Set Value            */
#define CLK_CFG_REGS_MCDCR_OSCOFF_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_MCDCR_OSCOFF_Msk) >> CLK_CFG_REGS_MCDCR_OSCOFF_Pos)   /*!< OSCOFF Get Value            */


#define CLK_CFG_REGS_MCDCR_MCLKOFF_Pos    (2U)                                                                                  /*!< MCLKOFF Postion   2          */ 
#define CLK_CFG_REGS_MCDCR_MCLKOFF_Msk    (0x1U << CLK_CFG_REGS_MCDCR_MCLKOFF_Pos)                                              /*!< MCLKOFF Mask      0x00000004 */
#define CLK_CFG_REGS_MCDCR_MCLKOFF_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_MCDCR_MCLKOFF_Pos) & CLK_CFG_REGS_MCDCR_MCLKOFF_Msk) /*!< MCLKOFF Set Value            */
#define CLK_CFG_REGS_MCDCR_MCLKOFF_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_MCDCR_MCLKOFF_Msk) >> CLK_CFG_REGS_MCDCR_MCLKOFF_Pos) /*!< MCLKOFF Get Value            */


#define CLK_CFG_REGS_MCDCR_MCLKCLR_Pos    (1U)                                                                                  /*!< MCLKCLR Postion   1          */ 
#define CLK_CFG_REGS_MCDCR_MCLKCLR_Msk    (0x1U << CLK_CFG_REGS_MCDCR_MCLKCLR_Pos)                                              /*!< MCLKCLR Mask      0x00000002 */
#define CLK_CFG_REGS_MCDCR_MCLKCLR_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_MCDCR_MCLKCLR_Pos) & CLK_CFG_REGS_MCDCR_MCLKCLR_Msk) /*!< MCLKCLR Set Value            */
#define CLK_CFG_REGS_MCDCR_MCLKCLR_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_MCDCR_MCLKCLR_Msk) >> CLK_CFG_REGS_MCDCR_MCLKCLR_Pos) /*!< MCLKCLR Get Value            */


#define CLK_CFG_REGS_MCDCR_MCLKSTS_Pos    (0U)                                                                                  /*!< MCLKSTS Postion   0          */ 
#define CLK_CFG_REGS_MCDCR_MCLKSTS_Msk    (0x1U << CLK_CFG_REGS_MCDCR_MCLKSTS_Pos)                                              /*!< MCLKSTS Mask      0x00000001 */
#define CLK_CFG_REGS_MCDCR_MCLKSTS_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_MCDCR_MCLKSTS_Pos) & CLK_CFG_REGS_MCDCR_MCLKSTS_Msk) /*!< MCLKSTS Set Value            */
#define CLK_CFG_REGS_MCDCR_MCLKSTS_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_MCDCR_MCLKSTS_Msk) >> CLK_CFG_REGS_MCDCR_MCLKSTS_Pos) /*!< MCLKSTS Get Value            */


/* X1CNT bitfield */
#define CLK_CFG_REGS_X1CNT_X1CNT_Pos    (0U)                                                                                  /*!< X1CNT Postion   0          */ 
#define CLK_CFG_REGS_X1CNT_X1CNT_Msk    (0x3ffU << CLK_CFG_REGS_X1CNT_X1CNT_Pos)                                              /*!< X1CNT Mask      0x000003FF */
#define CLK_CFG_REGS_X1CNT_X1CNT_Set(x) (((uint32_t) (x) << CLK_CFG_REGS_X1CNT_X1CNT_Pos) & CLK_CFG_REGS_X1CNT_X1CNT_Msk)     /*!< X1CNT Set Value            */
#define CLK_CFG_REGS_X1CNT_X1CNT_Get(x) (((uint32_t) (x) & CLK_CFG_REGS_X1CNT_X1CNT_Msk) >> CLK_CFG_REGS_X1CNT_X1CNT_Pos)     /*!< X1CNT Get Value            */


/* CPUSYSLOCK1 bitfield */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR17_Pos    (24U)                                                                                 /*!< PCLKCR17 Postion   24         */ 
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR17_Msk    (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR17_Pos)                                       /*!< PCLKCR17 Mask      0x01000000 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR17_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR17_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR17_Msk) /*!< PCLKCR17 Set Value            */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR17_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR17_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR17_Pos) /*!< PCLKCR17 Get Value            */


#define CPU_SYS_REGS_CPUSYSLOCK1_GPIOLPMSEL1_Pos    (23U)                                                                                 /*!< GPIOLPMSEL1 Postion   23         */ 
#define CPU_SYS_REGS_CPUSYSLOCK1_GPIOLPMSEL1_Msk    (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_GPIOLPMSEL1_Pos)                                    /*!< GPIOLPMSEL1 Mask      0x00800000 */
#define CPU_SYS_REGS_CPUSYSLOCK1_GPIOLPMSEL1_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_GPIOLPMSEL1_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_GPIOLPMSEL1_Msk) /*!< GPIOLPMSEL1 Set Value            */
#define CPU_SYS_REGS_CPUSYSLOCK1_GPIOLPMSEL1_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_GPIOLPMSEL1_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_GPIOLPMSEL1_Pos) /*!< GPIOLPMSEL1 Get Value            */


#define CPU_SYS_REGS_CPUSYSLOCK1_GPIOLPMSEL0_Pos    (22U)                                                                                 /*!< GPIOLPMSEL0 Postion   22         */ 
#define CPU_SYS_REGS_CPUSYSLOCK1_GPIOLPMSEL0_Msk    (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_GPIOLPMSEL0_Pos)                                    /*!< GPIOLPMSEL0 Mask      0x00400000 */
#define CPU_SYS_REGS_CPUSYSLOCK1_GPIOLPMSEL0_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_GPIOLPMSEL0_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_GPIOLPMSEL0_Msk) /*!< GPIOLPMSEL0 Set Value            */
#define CPU_SYS_REGS_CPUSYSLOCK1_GPIOLPMSEL0_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_GPIOLPMSEL0_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_GPIOLPMSEL0_Pos) /*!< GPIOLPMSEL0 Get Value            */


#define CPU_SYS_REGS_CPUSYSLOCK1_LPMCR_Pos    (21U)                                                                                 /*!< LPMCR Postion   21         */ 
#define CPU_SYS_REGS_CPUSYSLOCK1_LPMCR_Msk    (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_LPMCR_Pos)                                          /*!< LPMCR Mask      0x00200000 */
#define CPU_SYS_REGS_CPUSYSLOCK1_LPMCR_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_LPMCR_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_LPMCR_Msk) /*!< LPMCR Set Value            */
#define CPU_SYS_REGS_CPUSYSLOCK1_LPMCR_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_LPMCR_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_LPMCR_Pos) /*!< LPMCR Get Value            */


#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR16_Pos    (19U)                                                                                 /*!< PCLKCR16 Postion   19         */ 
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR16_Msk    (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR16_Pos)                                       /*!< PCLKCR16 Mask      0x00080000 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR16_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR16_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR16_Msk) /*!< PCLKCR16 Set Value            */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR16_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR16_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR16_Pos) /*!< PCLKCR16 Get Value            */


#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR15_Pos    (18U)                                                                                 /*!< PCLKCR15 Postion   18         */ 
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR15_Msk    (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR15_Pos)                                       /*!< PCLKCR15 Mask      0x00040000 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR15_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR15_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR15_Msk) /*!< PCLKCR15 Set Value            */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR15_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR15_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR15_Pos) /*!< PCLKCR15 Get Value            */


#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR14_Pos    (17U)                                                                                 /*!< PCLKCR14 Postion   17         */ 
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR14_Msk    (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR14_Pos)                                       /*!< PCLKCR14 Mask      0x00020000 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR14_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR14_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR14_Msk) /*!< PCLKCR14 Set Value            */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR14_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR14_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR14_Pos) /*!< PCLKCR14 Get Value            */


#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR13_Pos    (16U)                                                                                 /*!< PCLKCR13 Postion   16         */ 
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR13_Msk    (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR13_Pos)                                       /*!< PCLKCR13 Mask      0x00010000 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR13_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR13_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR13_Msk) /*!< PCLKCR13 Set Value            */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR13_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR13_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR13_Pos) /*!< PCLKCR13 Get Value            */


#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR12_Pos    (15U)                                                                                 /*!< PCLKCR12 Postion   15         */ 
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR12_Msk    (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR12_Pos)                                       /*!< PCLKCR12 Mask      0x00008000 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR12_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR12_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR12_Msk) /*!< PCLKCR12 Set Value            */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR12_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR12_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR12_Pos) /*!< PCLKCR12 Get Value            */


#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR11_Pos    (14U)                                                                                 /*!< PCLKCR11 Postion   14         */ 
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR11_Msk    (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR11_Pos)                                       /*!< PCLKCR11 Mask      0x00004000 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR11_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR11_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR11_Msk) /*!< PCLKCR11 Set Value            */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR11_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR11_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR11_Pos) /*!< PCLKCR11 Get Value            */


#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR10_Pos    (13U)                                                                                 /*!< PCLKCR10 Postion   13         */ 
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR10_Msk    (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR10_Pos)                                       /*!< PCLKCR10 Mask      0x00002000 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR10_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR10_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR10_Msk) /*!< PCLKCR10 Set Value            */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR10_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR10_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR10_Pos) /*!< PCLKCR10 Get Value            */


#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR9_Pos    (12U)                                                                                 /*!< PCLKCR9 Postion   12         */ 
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR9_Msk    (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR9_Pos)                                        /*!< PCLKCR9 Mask      0x00001000 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR9_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR9_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR9_Msk) /*!< PCLKCR9 Set Value            */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR9_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR9_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR9_Pos) /*!< PCLKCR9 Get Value            */


#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR8_Pos    (11U)                                                                                 /*!< PCLKCR8 Postion   11         */ 
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR8_Msk    (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR8_Pos)                                        /*!< PCLKCR8 Mask      0x00000800 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR8_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR8_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR8_Msk) /*!< PCLKCR8 Set Value            */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR8_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR8_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR8_Pos) /*!< PCLKCR8 Get Value            */


#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR7_Pos    (10U)                                                                                 /*!< PCLKCR7 Postion   10         */ 
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR7_Msk    (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR7_Pos)                                        /*!< PCLKCR7 Mask      0x00000400 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR7_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR7_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR7_Msk) /*!< PCLKCR7 Set Value            */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR7_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR7_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR7_Pos) /*!< PCLKCR7 Get Value            */


#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR6_Pos    (9U)                                                                                  /*!< PCLKCR6 Postion   9          */ 
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR6_Msk    (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR6_Pos)                                        /*!< PCLKCR6 Mask      0x00000200 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR6_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR6_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR6_Msk) /*!< PCLKCR6 Set Value            */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR6_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR6_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR6_Pos) /*!< PCLKCR6 Get Value            */


#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR5_Pos    (8U)                                                                                  /*!< PCLKCR5 Postion   8          */ 
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR5_Msk    (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR5_Pos)                                        /*!< PCLKCR5 Mask      0x00000100 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR5_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR5_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR5_Msk) /*!< PCLKCR5 Set Value            */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR5_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR5_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR5_Pos) /*!< PCLKCR5 Get Value            */


#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR4_Pos    (7U)                                                                                  /*!< PCLKCR4 Postion   7          */ 
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR4_Msk    (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR4_Pos)                                        /*!< PCLKCR4 Mask      0x00000080 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR4_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR4_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR4_Msk) /*!< PCLKCR4 Set Value            */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR4_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR4_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR4_Pos) /*!< PCLKCR4 Get Value            */


#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR3_Pos    (6U)                                                                                  /*!< PCLKCR3 Postion   6          */ 
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR3_Msk    (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR3_Pos)                                        /*!< PCLKCR3 Mask      0x00000040 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR3_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR3_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR3_Msk) /*!< PCLKCR3 Set Value            */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR3_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR3_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR3_Pos) /*!< PCLKCR3 Get Value            */


#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR2_Pos    (5U)                                                                                  /*!< PCLKCR2 Postion   5          */ 
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR2_Msk    (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR2_Pos)                                        /*!< PCLKCR2 Mask      0x00000020 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR2_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR2_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR2_Msk) /*!< PCLKCR2 Set Value            */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR2_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR2_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR2_Pos) /*!< PCLKCR2 Get Value            */


#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR1_Pos    (4U)                                                                                  /*!< PCLKCR1 Postion   4          */ 
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR1_Msk    (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR1_Pos)                                        /*!< PCLKCR1 Mask      0x00000010 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR1_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR1_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR1_Msk) /*!< PCLKCR1 Set Value            */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR1_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR1_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR1_Pos) /*!< PCLKCR1 Get Value            */


#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR0_Pos    (3U)                                                                                  /*!< PCLKCR0 Postion   3          */ 
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR0_Msk    (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR0_Pos)                                        /*!< PCLKCR0 Mask      0x00000008 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR0_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR0_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR0_Msk) /*!< PCLKCR0 Set Value            */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR0_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR0_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR0_Pos) /*!< PCLKCR0 Get Value            */


/* HIBBOOTMODE bitfield */
/* IORESTOREADDR bitfield */
/* PIEVERRADDR bitfield */
/* PCLKCR0 bitfield */
#define CPU_SYS_REGS_PCLKCR0_GTBCLKSYNC_Pos    (19U)                                                                                 /*!< GTBCLKSYNC Postion   19         */ 
#define CPU_SYS_REGS_PCLKCR0_GTBCLKSYNC_Msk    (0x1U << CPU_SYS_REGS_PCLKCR0_GTBCLKSYNC_Pos)                                         /*!< GTBCLKSYNC Mask      0x00080000 */
#define CPU_SYS_REGS_PCLKCR0_GTBCLKSYNC_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR0_GTBCLKSYNC_Pos) & CPU_SYS_REGS_PCLKCR0_GTBCLKSYNC_Msk) /*!< GTBCLKSYNC Set Value            */
#define CPU_SYS_REGS_PCLKCR0_GTBCLKSYNC_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR0_GTBCLKSYNC_Msk) >> CPU_SYS_REGS_PCLKCR0_GTBCLKSYNC_Pos) /*!< GTBCLKSYNC Get Value            */


#define CPU_SYS_REGS_PCLKCR0_TBCLKSYNC_Pos    (18U)                                                                                 /*!< TBCLKSYNC Postion   18         */ 
#define CPU_SYS_REGS_PCLKCR0_TBCLKSYNC_Msk    (0x1U << CPU_SYS_REGS_PCLKCR0_TBCLKSYNC_Pos)                                          /*!< TBCLKSYNC Mask      0x00040000 */
#define CPU_SYS_REGS_PCLKCR0_TBCLKSYNC_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR0_TBCLKSYNC_Pos) & CPU_SYS_REGS_PCLKCR0_TBCLKSYNC_Msk) /*!< TBCLKSYNC Set Value            */
#define CPU_SYS_REGS_PCLKCR0_TBCLKSYNC_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR0_TBCLKSYNC_Msk) >> CPU_SYS_REGS_PCLKCR0_TBCLKSYNC_Pos) /*!< TBCLKSYNC Get Value            */


#define CPU_SYS_REGS_PCLKCR0_DWCPUTIMER2_Pos    (10U)                                                                                 /*!< DWCPUTIMER2 Postion   10         */ 
#define CPU_SYS_REGS_PCLKCR0_DWCPUTIMER2_Msk    (0x1U << CPU_SYS_REGS_PCLKCR0_DWCPUTIMER2_Pos)                                        /*!< DWCPUTIMER2 Mask      0x00000400 */
#define CPU_SYS_REGS_PCLKCR0_DWCPUTIMER2_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR0_DWCPUTIMER2_Pos) & CPU_SYS_REGS_PCLKCR0_DWCPUTIMER2_Msk) /*!< DWCPUTIMER2 Set Value            */
#define CPU_SYS_REGS_PCLKCR0_DWCPUTIMER2_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR0_DWCPUTIMER2_Msk) >> CPU_SYS_REGS_PCLKCR0_DWCPUTIMER2_Pos) /*!< DWCPUTIMER2 Get Value            */


#define CPU_SYS_REGS_PCLKCR0_DWCPUTIMER1_Pos    (9U)                                                                                  /*!< DWCPUTIMER1 Postion   9          */ 
#define CPU_SYS_REGS_PCLKCR0_DWCPUTIMER1_Msk    (0x1U << CPU_SYS_REGS_PCLKCR0_DWCPUTIMER1_Pos)                                        /*!< DWCPUTIMER1 Mask      0x00000200 */
#define CPU_SYS_REGS_PCLKCR0_DWCPUTIMER1_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR0_DWCPUTIMER1_Pos) & CPU_SYS_REGS_PCLKCR0_DWCPUTIMER1_Msk) /*!< DWCPUTIMER1 Set Value            */
#define CPU_SYS_REGS_PCLKCR0_DWCPUTIMER1_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR0_DWCPUTIMER1_Msk) >> CPU_SYS_REGS_PCLKCR0_DWCPUTIMER1_Pos) /*!< DWCPUTIMER1 Get Value            */


#define CPU_SYS_REGS_PCLKCR0_DWCPUTIMER0_Pos    (8U)                                                                                  /*!< DWCPUTIMER0 Postion   8          */ 
#define CPU_SYS_REGS_PCLKCR0_DWCPUTIMER0_Msk    (0x1U << CPU_SYS_REGS_PCLKCR0_DWCPUTIMER0_Pos)                                        /*!< DWCPUTIMER0 Mask      0x00000100 */
#define CPU_SYS_REGS_PCLKCR0_DWCPUTIMER0_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR0_DWCPUTIMER0_Pos) & CPU_SYS_REGS_PCLKCR0_DWCPUTIMER0_Msk) /*!< DWCPUTIMER0 Set Value            */
#define CPU_SYS_REGS_PCLKCR0_DWCPUTIMER0_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR0_DWCPUTIMER0_Msk) >> CPU_SYS_REGS_PCLKCR0_DWCPUTIMER0_Pos) /*!< DWCPUTIMER0 Get Value            */


#define CPU_SYS_REGS_PCLKCR0_CPUTIMER2_Pos    (5U)                                                                                  /*!< CPUTIMER2 Postion   5          */ 
#define CPU_SYS_REGS_PCLKCR0_CPUTIMER2_Msk    (0x1U << CPU_SYS_REGS_PCLKCR0_CPUTIMER2_Pos)                                          /*!< CPUTIMER2 Mask      0x00000020 */
#define CPU_SYS_REGS_PCLKCR0_CPUTIMER2_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR0_CPUTIMER2_Pos) & CPU_SYS_REGS_PCLKCR0_CPUTIMER2_Msk) /*!< CPUTIMER2 Set Value            */
#define CPU_SYS_REGS_PCLKCR0_CPUTIMER2_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR0_CPUTIMER2_Msk) >> CPU_SYS_REGS_PCLKCR0_CPUTIMER2_Pos) /*!< CPUTIMER2 Get Value            */


#define CPU_SYS_REGS_PCLKCR0_CPUTIMER1_Pos    (4U)                                                                                  /*!< CPUTIMER1 Postion   4          */ 
#define CPU_SYS_REGS_PCLKCR0_CPUTIMER1_Msk    (0x1U << CPU_SYS_REGS_PCLKCR0_CPUTIMER1_Pos)                                          /*!< CPUTIMER1 Mask      0x00000010 */
#define CPU_SYS_REGS_PCLKCR0_CPUTIMER1_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR0_CPUTIMER1_Pos) & CPU_SYS_REGS_PCLKCR0_CPUTIMER1_Msk) /*!< CPUTIMER1 Set Value            */
#define CPU_SYS_REGS_PCLKCR0_CPUTIMER1_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR0_CPUTIMER1_Msk) >> CPU_SYS_REGS_PCLKCR0_CPUTIMER1_Pos) /*!< CPUTIMER1 Get Value            */


#define CPU_SYS_REGS_PCLKCR0_CPUTIMER0_Pos    (3U)                                                                                  /*!< CPUTIMER0 Postion   3          */ 
#define CPU_SYS_REGS_PCLKCR0_CPUTIMER0_Msk    (0x1U << CPU_SYS_REGS_PCLKCR0_CPUTIMER0_Pos)                                          /*!< CPUTIMER0 Mask      0x00000008 */
#define CPU_SYS_REGS_PCLKCR0_CPUTIMER0_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR0_CPUTIMER0_Pos) & CPU_SYS_REGS_PCLKCR0_CPUTIMER0_Msk) /*!< CPUTIMER0 Set Value            */
#define CPU_SYS_REGS_PCLKCR0_CPUTIMER0_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR0_CPUTIMER0_Msk) >> CPU_SYS_REGS_PCLKCR0_CPUTIMER0_Pos) /*!< CPUTIMER0 Get Value            */


#define CPU_SYS_REGS_PCLKCR0_DMA_Pos    (2U)                                                                                  /*!< DMA Postion   2          */ 
#define CPU_SYS_REGS_PCLKCR0_DMA_Msk    (0x1U << CPU_SYS_REGS_PCLKCR0_DMA_Pos)                                                /*!< DMA Mask      0x00000004 */
#define CPU_SYS_REGS_PCLKCR0_DMA_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR0_DMA_Pos) & CPU_SYS_REGS_PCLKCR0_DMA_Msk)     /*!< DMA Set Value            */
#define CPU_SYS_REGS_PCLKCR0_DMA_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR0_DMA_Msk) >> CPU_SYS_REGS_PCLKCR0_DMA_Pos)     /*!< DMA Get Value            */


/* PCLKCR1 bitfield */
#define CPU_SYS_REGS_PCLKCR1_EMIF2_Pos    (1U)                                                                                  /*!< EMIF2 Postion   1          */ 
#define CPU_SYS_REGS_PCLKCR1_EMIF2_Msk    (0x1U << CPU_SYS_REGS_PCLKCR1_EMIF2_Pos)                                              /*!< EMIF2 Mask      0x00000002 */
#define CPU_SYS_REGS_PCLKCR1_EMIF2_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR1_EMIF2_Pos) & CPU_SYS_REGS_PCLKCR1_EMIF2_Msk) /*!< EMIF2 Set Value            */
#define CPU_SYS_REGS_PCLKCR1_EMIF2_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR1_EMIF2_Msk) >> CPU_SYS_REGS_PCLKCR1_EMIF2_Pos) /*!< EMIF2 Get Value            */


#define CPU_SYS_REGS_PCLKCR1_EMIF1_Pos    (0U)                                                                                  /*!< EMIF1 Postion   0          */ 
#define CPU_SYS_REGS_PCLKCR1_EMIF1_Msk    (0x1U << CPU_SYS_REGS_PCLKCR1_EMIF1_Pos)                                              /*!< EMIF1 Mask      0x00000001 */
#define CPU_SYS_REGS_PCLKCR1_EMIF1_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR1_EMIF1_Pos) & CPU_SYS_REGS_PCLKCR1_EMIF1_Msk) /*!< EMIF1 Set Value            */
#define CPU_SYS_REGS_PCLKCR1_EMIF1_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR1_EMIF1_Msk) >> CPU_SYS_REGS_PCLKCR1_EMIF1_Pos) /*!< EMIF1 Get Value            */


/* PCLKCR2 bitfield */
#define CPU_SYS_REGS_PCLKCR2_EPWM12_Pos    (11U)                                                                                 /*!< EPWM12 Postion   11         */ 
#define CPU_SYS_REGS_PCLKCR2_EPWM12_Msk    (0x1U << CPU_SYS_REGS_PCLKCR2_EPWM12_Pos)                                             /*!< EPWM12 Mask      0x00000800 */
#define CPU_SYS_REGS_PCLKCR2_EPWM12_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR2_EPWM12_Pos) & CPU_SYS_REGS_PCLKCR2_EPWM12_Msk) /*!< EPWM12 Set Value            */
#define CPU_SYS_REGS_PCLKCR2_EPWM12_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR2_EPWM12_Msk) >> CPU_SYS_REGS_PCLKCR2_EPWM12_Pos) /*!< EPWM12 Get Value            */


#define CPU_SYS_REGS_PCLKCR2_EPWM11_Pos    (10U)                                                                                 /*!< EPWM11 Postion   10         */ 
#define CPU_SYS_REGS_PCLKCR2_EPWM11_Msk    (0x1U << CPU_SYS_REGS_PCLKCR2_EPWM11_Pos)                                             /*!< EPWM11 Mask      0x00000400 */
#define CPU_SYS_REGS_PCLKCR2_EPWM11_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR2_EPWM11_Pos) & CPU_SYS_REGS_PCLKCR2_EPWM11_Msk) /*!< EPWM11 Set Value            */
#define CPU_SYS_REGS_PCLKCR2_EPWM11_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR2_EPWM11_Msk) >> CPU_SYS_REGS_PCLKCR2_EPWM11_Pos) /*!< EPWM11 Get Value            */


#define CPU_SYS_REGS_PCLKCR2_EPWM10_Pos    (9U)                                                                                  /*!< EPWM10 Postion   9          */ 
#define CPU_SYS_REGS_PCLKCR2_EPWM10_Msk    (0x1U << CPU_SYS_REGS_PCLKCR2_EPWM10_Pos)                                             /*!< EPWM10 Mask      0x00000200 */
#define CPU_SYS_REGS_PCLKCR2_EPWM10_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR2_EPWM10_Pos) & CPU_SYS_REGS_PCLKCR2_EPWM10_Msk) /*!< EPWM10 Set Value            */
#define CPU_SYS_REGS_PCLKCR2_EPWM10_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR2_EPWM10_Msk) >> CPU_SYS_REGS_PCLKCR2_EPWM10_Pos) /*!< EPWM10 Get Value            */


#define CPU_SYS_REGS_PCLKCR2_EPWM9_Pos    (8U)                                                                                  /*!< EPWM9 Postion   8          */ 
#define CPU_SYS_REGS_PCLKCR2_EPWM9_Msk    (0x1U << CPU_SYS_REGS_PCLKCR2_EPWM9_Pos)                                              /*!< EPWM9 Mask      0x00000100 */
#define CPU_SYS_REGS_PCLKCR2_EPWM9_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR2_EPWM9_Pos) & CPU_SYS_REGS_PCLKCR2_EPWM9_Msk) /*!< EPWM9 Set Value            */
#define CPU_SYS_REGS_PCLKCR2_EPWM9_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR2_EPWM9_Msk) >> CPU_SYS_REGS_PCLKCR2_EPWM9_Pos) /*!< EPWM9 Get Value            */


#define CPU_SYS_REGS_PCLKCR2_EPWM8_Pos    (7U)                                                                                  /*!< EPWM8 Postion   7          */ 
#define CPU_SYS_REGS_PCLKCR2_EPWM8_Msk    (0x1U << CPU_SYS_REGS_PCLKCR2_EPWM8_Pos)                                              /*!< EPWM8 Mask      0x00000080 */
#define CPU_SYS_REGS_PCLKCR2_EPWM8_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR2_EPWM8_Pos) & CPU_SYS_REGS_PCLKCR2_EPWM8_Msk) /*!< EPWM8 Set Value            */
#define CPU_SYS_REGS_PCLKCR2_EPWM8_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR2_EPWM8_Msk) >> CPU_SYS_REGS_PCLKCR2_EPWM8_Pos) /*!< EPWM8 Get Value            */


#define CPU_SYS_REGS_PCLKCR2_EPWM7_Pos    (6U)                                                                                  /*!< EPWM7 Postion   6          */ 
#define CPU_SYS_REGS_PCLKCR2_EPWM7_Msk    (0x1U << CPU_SYS_REGS_PCLKCR2_EPWM7_Pos)                                              /*!< EPWM7 Mask      0x00000040 */
#define CPU_SYS_REGS_PCLKCR2_EPWM7_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR2_EPWM7_Pos) & CPU_SYS_REGS_PCLKCR2_EPWM7_Msk) /*!< EPWM7 Set Value            */
#define CPU_SYS_REGS_PCLKCR2_EPWM7_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR2_EPWM7_Msk) >> CPU_SYS_REGS_PCLKCR2_EPWM7_Pos) /*!< EPWM7 Get Value            */


#define CPU_SYS_REGS_PCLKCR2_EPWM6_Pos    (5U)                                                                                  /*!< EPWM6 Postion   5          */ 
#define CPU_SYS_REGS_PCLKCR2_EPWM6_Msk    (0x1U << CPU_SYS_REGS_PCLKCR2_EPWM6_Pos)                                              /*!< EPWM6 Mask      0x00000020 */
#define CPU_SYS_REGS_PCLKCR2_EPWM6_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR2_EPWM6_Pos) & CPU_SYS_REGS_PCLKCR2_EPWM6_Msk) /*!< EPWM6 Set Value            */
#define CPU_SYS_REGS_PCLKCR2_EPWM6_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR2_EPWM6_Msk) >> CPU_SYS_REGS_PCLKCR2_EPWM6_Pos) /*!< EPWM6 Get Value            */


#define CPU_SYS_REGS_PCLKCR2_EPWM5_Pos    (4U)                                                                                  /*!< EPWM5 Postion   4          */ 
#define CPU_SYS_REGS_PCLKCR2_EPWM5_Msk    (0x1U << CPU_SYS_REGS_PCLKCR2_EPWM5_Pos)                                              /*!< EPWM5 Mask      0x00000010 */
#define CPU_SYS_REGS_PCLKCR2_EPWM5_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR2_EPWM5_Pos) & CPU_SYS_REGS_PCLKCR2_EPWM5_Msk) /*!< EPWM5 Set Value            */
#define CPU_SYS_REGS_PCLKCR2_EPWM5_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR2_EPWM5_Msk) >> CPU_SYS_REGS_PCLKCR2_EPWM5_Pos) /*!< EPWM5 Get Value            */


#define CPU_SYS_REGS_PCLKCR2_EPWM4_Pos    (3U)                                                                                  /*!< EPWM4 Postion   3          */ 
#define CPU_SYS_REGS_PCLKCR2_EPWM4_Msk    (0x1U << CPU_SYS_REGS_PCLKCR2_EPWM4_Pos)                                              /*!< EPWM4 Mask      0x00000008 */
#define CPU_SYS_REGS_PCLKCR2_EPWM4_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR2_EPWM4_Pos) & CPU_SYS_REGS_PCLKCR2_EPWM4_Msk) /*!< EPWM4 Set Value            */
#define CPU_SYS_REGS_PCLKCR2_EPWM4_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR2_EPWM4_Msk) >> CPU_SYS_REGS_PCLKCR2_EPWM4_Pos) /*!< EPWM4 Get Value            */


#define CPU_SYS_REGS_PCLKCR2_EPWM3_Pos    (2U)                                                                                  /*!< EPWM3 Postion   2          */ 
#define CPU_SYS_REGS_PCLKCR2_EPWM3_Msk    (0x1U << CPU_SYS_REGS_PCLKCR2_EPWM3_Pos)                                              /*!< EPWM3 Mask      0x00000004 */
#define CPU_SYS_REGS_PCLKCR2_EPWM3_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR2_EPWM3_Pos) & CPU_SYS_REGS_PCLKCR2_EPWM3_Msk) /*!< EPWM3 Set Value            */
#define CPU_SYS_REGS_PCLKCR2_EPWM3_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR2_EPWM3_Msk) >> CPU_SYS_REGS_PCLKCR2_EPWM3_Pos) /*!< EPWM3 Get Value            */


#define CPU_SYS_REGS_PCLKCR2_EPWM2_Pos    (1U)                                                                                  /*!< EPWM2 Postion   1          */ 
#define CPU_SYS_REGS_PCLKCR2_EPWM2_Msk    (0x1U << CPU_SYS_REGS_PCLKCR2_EPWM2_Pos)                                              /*!< EPWM2 Mask      0x00000002 */
#define CPU_SYS_REGS_PCLKCR2_EPWM2_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR2_EPWM2_Pos) & CPU_SYS_REGS_PCLKCR2_EPWM2_Msk) /*!< EPWM2 Set Value            */
#define CPU_SYS_REGS_PCLKCR2_EPWM2_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR2_EPWM2_Msk) >> CPU_SYS_REGS_PCLKCR2_EPWM2_Pos) /*!< EPWM2 Get Value            */


#define CPU_SYS_REGS_PCLKCR2_EPWM1_Pos    (0U)                                                                                  /*!< EPWM1 Postion   0          */ 
#define CPU_SYS_REGS_PCLKCR2_EPWM1_Msk    (0x1U << CPU_SYS_REGS_PCLKCR2_EPWM1_Pos)                                              /*!< EPWM1 Mask      0x00000001 */
#define CPU_SYS_REGS_PCLKCR2_EPWM1_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR2_EPWM1_Pos) & CPU_SYS_REGS_PCLKCR2_EPWM1_Msk) /*!< EPWM1 Set Value            */
#define CPU_SYS_REGS_PCLKCR2_EPWM1_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR2_EPWM1_Msk) >> CPU_SYS_REGS_PCLKCR2_EPWM1_Pos) /*!< EPWM1 Get Value            */


/* PCLKCR3 bitfield */
#define CPU_SYS_REGS_PCLKCR3_ECAP6_Pos    (5U)                                                                                  /*!< ECAP6 Postion   5          */ 
#define CPU_SYS_REGS_PCLKCR3_ECAP6_Msk    (0x1U << CPU_SYS_REGS_PCLKCR3_ECAP6_Pos)                                              /*!< ECAP6 Mask      0x00000020 */
#define CPU_SYS_REGS_PCLKCR3_ECAP6_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR3_ECAP6_Pos) & CPU_SYS_REGS_PCLKCR3_ECAP6_Msk) /*!< ECAP6 Set Value            */
#define CPU_SYS_REGS_PCLKCR3_ECAP6_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR3_ECAP6_Msk) >> CPU_SYS_REGS_PCLKCR3_ECAP6_Pos) /*!< ECAP6 Get Value            */


#define CPU_SYS_REGS_PCLKCR3_ECAP5_Pos    (4U)                                                                                  /*!< ECAP5 Postion   4          */ 
#define CPU_SYS_REGS_PCLKCR3_ECAP5_Msk    (0x1U << CPU_SYS_REGS_PCLKCR3_ECAP5_Pos)                                              /*!< ECAP5 Mask      0x00000010 */
#define CPU_SYS_REGS_PCLKCR3_ECAP5_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR3_ECAP5_Pos) & CPU_SYS_REGS_PCLKCR3_ECAP5_Msk) /*!< ECAP5 Set Value            */
#define CPU_SYS_REGS_PCLKCR3_ECAP5_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR3_ECAP5_Msk) >> CPU_SYS_REGS_PCLKCR3_ECAP5_Pos) /*!< ECAP5 Get Value            */


#define CPU_SYS_REGS_PCLKCR3_ECAP4_Pos    (3U)                                                                                  /*!< ECAP4 Postion   3          */ 
#define CPU_SYS_REGS_PCLKCR3_ECAP4_Msk    (0x1U << CPU_SYS_REGS_PCLKCR3_ECAP4_Pos)                                              /*!< ECAP4 Mask      0x00000008 */
#define CPU_SYS_REGS_PCLKCR3_ECAP4_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR3_ECAP4_Pos) & CPU_SYS_REGS_PCLKCR3_ECAP4_Msk) /*!< ECAP4 Set Value            */
#define CPU_SYS_REGS_PCLKCR3_ECAP4_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR3_ECAP4_Msk) >> CPU_SYS_REGS_PCLKCR3_ECAP4_Pos) /*!< ECAP4 Get Value            */


#define CPU_SYS_REGS_PCLKCR3_ECAP3_Pos    (2U)                                                                                  /*!< ECAP3 Postion   2          */ 
#define CPU_SYS_REGS_PCLKCR3_ECAP3_Msk    (0x1U << CPU_SYS_REGS_PCLKCR3_ECAP3_Pos)                                              /*!< ECAP3 Mask      0x00000004 */
#define CPU_SYS_REGS_PCLKCR3_ECAP3_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR3_ECAP3_Pos) & CPU_SYS_REGS_PCLKCR3_ECAP3_Msk) /*!< ECAP3 Set Value            */
#define CPU_SYS_REGS_PCLKCR3_ECAP3_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR3_ECAP3_Msk) >> CPU_SYS_REGS_PCLKCR3_ECAP3_Pos) /*!< ECAP3 Get Value            */


#define CPU_SYS_REGS_PCLKCR3_ECAP2_Pos    (1U)                                                                                  /*!< ECAP2 Postion   1          */ 
#define CPU_SYS_REGS_PCLKCR3_ECAP2_Msk    (0x1U << CPU_SYS_REGS_PCLKCR3_ECAP2_Pos)                                              /*!< ECAP2 Mask      0x00000002 */
#define CPU_SYS_REGS_PCLKCR3_ECAP2_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR3_ECAP2_Pos) & CPU_SYS_REGS_PCLKCR3_ECAP2_Msk) /*!< ECAP2 Set Value            */
#define CPU_SYS_REGS_PCLKCR3_ECAP2_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR3_ECAP2_Msk) >> CPU_SYS_REGS_PCLKCR3_ECAP2_Pos) /*!< ECAP2 Get Value            */


#define CPU_SYS_REGS_PCLKCR3_ECAP1_Pos    (0U)                                                                                  /*!< ECAP1 Postion   0          */ 
#define CPU_SYS_REGS_PCLKCR3_ECAP1_Msk    (0x1U << CPU_SYS_REGS_PCLKCR3_ECAP1_Pos)                                              /*!< ECAP1 Mask      0x00000001 */
#define CPU_SYS_REGS_PCLKCR3_ECAP1_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR3_ECAP1_Pos) & CPU_SYS_REGS_PCLKCR3_ECAP1_Msk) /*!< ECAP1 Set Value            */
#define CPU_SYS_REGS_PCLKCR3_ECAP1_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR3_ECAP1_Msk) >> CPU_SYS_REGS_PCLKCR3_ECAP1_Pos) /*!< ECAP1 Get Value            */


/* PCLKCR4 bitfield */
#define CPU_SYS_REGS_PCLKCR4_EQEP3_Pos    (2U)                                                                                  /*!< EQEP3 Postion   2          */ 
#define CPU_SYS_REGS_PCLKCR4_EQEP3_Msk    (0x1U << CPU_SYS_REGS_PCLKCR4_EQEP3_Pos)                                              /*!< EQEP3 Mask      0x00000004 */
#define CPU_SYS_REGS_PCLKCR4_EQEP3_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR4_EQEP3_Pos) & CPU_SYS_REGS_PCLKCR4_EQEP3_Msk) /*!< EQEP3 Set Value            */
#define CPU_SYS_REGS_PCLKCR4_EQEP3_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR4_EQEP3_Msk) >> CPU_SYS_REGS_PCLKCR4_EQEP3_Pos) /*!< EQEP3 Get Value            */


#define CPU_SYS_REGS_PCLKCR4_EQEP2_Pos    (1U)                                                                                  /*!< EQEP2 Postion   1          */ 
#define CPU_SYS_REGS_PCLKCR4_EQEP2_Msk    (0x1U << CPU_SYS_REGS_PCLKCR4_EQEP2_Pos)                                              /*!< EQEP2 Mask      0x00000002 */
#define CPU_SYS_REGS_PCLKCR4_EQEP2_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR4_EQEP2_Pos) & CPU_SYS_REGS_PCLKCR4_EQEP2_Msk) /*!< EQEP2 Set Value            */
#define CPU_SYS_REGS_PCLKCR4_EQEP2_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR4_EQEP2_Msk) >> CPU_SYS_REGS_PCLKCR4_EQEP2_Pos) /*!< EQEP2 Get Value            */


#define CPU_SYS_REGS_PCLKCR4_EQEP1_Pos    (0U)                                                                                  /*!< EQEP1 Postion   0          */ 
#define CPU_SYS_REGS_PCLKCR4_EQEP1_Msk    (0x1U << CPU_SYS_REGS_PCLKCR4_EQEP1_Pos)                                              /*!< EQEP1 Mask      0x00000001 */
#define CPU_SYS_REGS_PCLKCR4_EQEP1_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR4_EQEP1_Pos) & CPU_SYS_REGS_PCLKCR4_EQEP1_Msk) /*!< EQEP1 Set Value            */
#define CPU_SYS_REGS_PCLKCR4_EQEP1_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR4_EQEP1_Msk) >> CPU_SYS_REGS_PCLKCR4_EQEP1_Pos) /*!< EQEP1 Get Value            */


/* PCLKCR6 bitfield */
#define CPU_SYS_REGS_PCLKCR6_SD2_Pos    (1U)                                                                                  /*!< SD2 Postion   1          */ 
#define CPU_SYS_REGS_PCLKCR6_SD2_Msk    (0x1U << CPU_SYS_REGS_PCLKCR6_SD2_Pos)                                                /*!< SD2 Mask      0x00000002 */
#define CPU_SYS_REGS_PCLKCR6_SD2_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR6_SD2_Pos) & CPU_SYS_REGS_PCLKCR6_SD2_Msk)     /*!< SD2 Set Value            */
#define CPU_SYS_REGS_PCLKCR6_SD2_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR6_SD2_Msk) >> CPU_SYS_REGS_PCLKCR6_SD2_Pos)     /*!< SD2 Get Value            */


#define CPU_SYS_REGS_PCLKCR6_SD1_Pos    (0U)                                                                                  /*!< SD1 Postion   0          */ 
#define CPU_SYS_REGS_PCLKCR6_SD1_Msk    (0x1U << CPU_SYS_REGS_PCLKCR6_SD1_Pos)                                                /*!< SD1 Mask      0x00000001 */
#define CPU_SYS_REGS_PCLKCR6_SD1_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR6_SD1_Pos) & CPU_SYS_REGS_PCLKCR6_SD1_Msk)     /*!< SD1 Set Value            */
#define CPU_SYS_REGS_PCLKCR6_SD1_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR6_SD1_Msk) >> CPU_SYS_REGS_PCLKCR6_SD1_Pos)     /*!< SD1 Get Value            */


/* PCLKCR7 bitfield */
#define CPU_SYS_REGS_PCLKCR7_SCI_D_Pos    (3U)                                                                                  /*!< SCI_D Postion   3          */ 
#define CPU_SYS_REGS_PCLKCR7_SCI_D_Msk    (0x1U << CPU_SYS_REGS_PCLKCR7_SCI_D_Pos)                                              /*!< SCI_D Mask      0x00000008 */
#define CPU_SYS_REGS_PCLKCR7_SCI_D_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR7_SCI_D_Pos) & CPU_SYS_REGS_PCLKCR7_SCI_D_Msk) /*!< SCI_D Set Value            */
#define CPU_SYS_REGS_PCLKCR7_SCI_D_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR7_SCI_D_Msk) >> CPU_SYS_REGS_PCLKCR7_SCI_D_Pos) /*!< SCI_D Get Value            */


#define CPU_SYS_REGS_PCLKCR7_SCI_C_Pos    (2U)                                                                                  /*!< SCI_C Postion   2          */ 
#define CPU_SYS_REGS_PCLKCR7_SCI_C_Msk    (0x1U << CPU_SYS_REGS_PCLKCR7_SCI_C_Pos)                                              /*!< SCI_C Mask      0x00000004 */
#define CPU_SYS_REGS_PCLKCR7_SCI_C_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR7_SCI_C_Pos) & CPU_SYS_REGS_PCLKCR7_SCI_C_Msk) /*!< SCI_C Set Value            */
#define CPU_SYS_REGS_PCLKCR7_SCI_C_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR7_SCI_C_Msk) >> CPU_SYS_REGS_PCLKCR7_SCI_C_Pos) /*!< SCI_C Get Value            */


#define CPU_SYS_REGS_PCLKCR7_SCI_B_Pos    (1U)                                                                                  /*!< SCI_B Postion   1          */ 
#define CPU_SYS_REGS_PCLKCR7_SCI_B_Msk    (0x1U << CPU_SYS_REGS_PCLKCR7_SCI_B_Pos)                                              /*!< SCI_B Mask      0x00000002 */
#define CPU_SYS_REGS_PCLKCR7_SCI_B_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR7_SCI_B_Pos) & CPU_SYS_REGS_PCLKCR7_SCI_B_Msk) /*!< SCI_B Set Value            */
#define CPU_SYS_REGS_PCLKCR7_SCI_B_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR7_SCI_B_Msk) >> CPU_SYS_REGS_PCLKCR7_SCI_B_Pos) /*!< SCI_B Get Value            */


#define CPU_SYS_REGS_PCLKCR7_SCI_A_Pos    (0U)                                                                                  /*!< SCI_A Postion   0          */ 
#define CPU_SYS_REGS_PCLKCR7_SCI_A_Msk    (0x1U << CPU_SYS_REGS_PCLKCR7_SCI_A_Pos)                                              /*!< SCI_A Mask      0x00000001 */
#define CPU_SYS_REGS_PCLKCR7_SCI_A_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR7_SCI_A_Pos) & CPU_SYS_REGS_PCLKCR7_SCI_A_Msk) /*!< SCI_A Set Value            */
#define CPU_SYS_REGS_PCLKCR7_SCI_A_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR7_SCI_A_Msk) >> CPU_SYS_REGS_PCLKCR7_SCI_A_Pos) /*!< SCI_A Get Value            */


/* PCLKCR8 bitfield */
#define CPU_SYS_REGS_PCLKCR8_SPI_C_Pos    (2U)                                                                                  /*!< SPI_C Postion   2          */ 
#define CPU_SYS_REGS_PCLKCR8_SPI_C_Msk    (0x1U << CPU_SYS_REGS_PCLKCR8_SPI_C_Pos)                                              /*!< SPI_C Mask      0x00000004 */
#define CPU_SYS_REGS_PCLKCR8_SPI_C_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR8_SPI_C_Pos) & CPU_SYS_REGS_PCLKCR8_SPI_C_Msk) /*!< SPI_C Set Value            */
#define CPU_SYS_REGS_PCLKCR8_SPI_C_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR8_SPI_C_Msk) >> CPU_SYS_REGS_PCLKCR8_SPI_C_Pos) /*!< SPI_C Get Value            */


#define CPU_SYS_REGS_PCLKCR8_SPI_B_Pos    (1U)                                                                                  /*!< SPI_B Postion   1          */ 
#define CPU_SYS_REGS_PCLKCR8_SPI_B_Msk    (0x1U << CPU_SYS_REGS_PCLKCR8_SPI_B_Pos)                                              /*!< SPI_B Mask      0x00000002 */
#define CPU_SYS_REGS_PCLKCR8_SPI_B_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR8_SPI_B_Pos) & CPU_SYS_REGS_PCLKCR8_SPI_B_Msk) /*!< SPI_B Set Value            */
#define CPU_SYS_REGS_PCLKCR8_SPI_B_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR8_SPI_B_Msk) >> CPU_SYS_REGS_PCLKCR8_SPI_B_Pos) /*!< SPI_B Get Value            */


#define CPU_SYS_REGS_PCLKCR8_SPI_A_Pos    (0U)                                                                                  /*!< SPI_A Postion   0          */ 
#define CPU_SYS_REGS_PCLKCR8_SPI_A_Msk    (0x1U << CPU_SYS_REGS_PCLKCR8_SPI_A_Pos)                                              /*!< SPI_A Mask      0x00000001 */
#define CPU_SYS_REGS_PCLKCR8_SPI_A_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR8_SPI_A_Pos) & CPU_SYS_REGS_PCLKCR8_SPI_A_Msk) /*!< SPI_A Set Value            */
#define CPU_SYS_REGS_PCLKCR8_SPI_A_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR8_SPI_A_Msk) >> CPU_SYS_REGS_PCLKCR8_SPI_A_Pos) /*!< SPI_A Get Value            */


/* PCLKCR9 bitfield */
#define CPU_SYS_REGS_PCLKCR9_PMBUS_A_Pos    (16U)                                                                                 /*!< PMBUS_A Postion   16         */ 
#define CPU_SYS_REGS_PCLKCR9_PMBUS_A_Msk    (0x1U << CPU_SYS_REGS_PCLKCR9_PMBUS_A_Pos)                                            /*!< PMBUS_A Mask      0x00010000 */
#define CPU_SYS_REGS_PCLKCR9_PMBUS_A_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR9_PMBUS_A_Pos) & CPU_SYS_REGS_PCLKCR9_PMBUS_A_Msk) /*!< PMBUS_A Set Value            */
#define CPU_SYS_REGS_PCLKCR9_PMBUS_A_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR9_PMBUS_A_Msk) >> CPU_SYS_REGS_PCLKCR9_PMBUS_A_Pos) /*!< PMBUS_A Get Value            */


#define CPU_SYS_REGS_PCLKCR9_I2C_B_Pos    (1U)                                                                                  /*!< I2C_B Postion   1          */ 
#define CPU_SYS_REGS_PCLKCR9_I2C_B_Msk    (0x1U << CPU_SYS_REGS_PCLKCR9_I2C_B_Pos)                                              /*!< I2C_B Mask      0x00000002 */
#define CPU_SYS_REGS_PCLKCR9_I2C_B_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR9_I2C_B_Pos) & CPU_SYS_REGS_PCLKCR9_I2C_B_Msk) /*!< I2C_B Set Value            */
#define CPU_SYS_REGS_PCLKCR9_I2C_B_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR9_I2C_B_Msk) >> CPU_SYS_REGS_PCLKCR9_I2C_B_Pos) /*!< I2C_B Get Value            */


#define CPU_SYS_REGS_PCLKCR9_I2C_A_Pos    (0U)                                                                                  /*!< I2C_A Postion   0          */ 
#define CPU_SYS_REGS_PCLKCR9_I2C_A_Msk    (0x1U << CPU_SYS_REGS_PCLKCR9_I2C_A_Pos)                                              /*!< I2C_A Mask      0x00000001 */
#define CPU_SYS_REGS_PCLKCR9_I2C_A_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR9_I2C_A_Pos) & CPU_SYS_REGS_PCLKCR9_I2C_A_Msk) /*!< I2C_A Set Value            */
#define CPU_SYS_REGS_PCLKCR9_I2C_A_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR9_I2C_A_Msk) >> CPU_SYS_REGS_PCLKCR9_I2C_A_Pos) /*!< I2C_A Get Value            */


/* PCLKCR10 bitfield */
#define CPU_SYS_REGS_PCLKCR10_CAN_C_Pos    (2U)                                                                                  /*!< CAN_C Postion   2          */ 
#define CPU_SYS_REGS_PCLKCR10_CAN_C_Msk    (0x1U << CPU_SYS_REGS_PCLKCR10_CAN_C_Pos)                                             /*!< CAN_C Mask      0x00000004 */
#define CPU_SYS_REGS_PCLKCR10_CAN_C_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR10_CAN_C_Pos) & CPU_SYS_REGS_PCLKCR10_CAN_C_Msk) /*!< CAN_C Set Value            */
#define CPU_SYS_REGS_PCLKCR10_CAN_C_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR10_CAN_C_Msk) >> CPU_SYS_REGS_PCLKCR10_CAN_C_Pos) /*!< CAN_C Get Value            */


#define CPU_SYS_REGS_PCLKCR10_CAN_B_Pos    (1U)                                                                                  /*!< CAN_B Postion   1          */ 
#define CPU_SYS_REGS_PCLKCR10_CAN_B_Msk    (0x1U << CPU_SYS_REGS_PCLKCR10_CAN_B_Pos)                                             /*!< CAN_B Mask      0x00000002 */
#define CPU_SYS_REGS_PCLKCR10_CAN_B_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR10_CAN_B_Pos) & CPU_SYS_REGS_PCLKCR10_CAN_B_Msk) /*!< CAN_B Set Value            */
#define CPU_SYS_REGS_PCLKCR10_CAN_B_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR10_CAN_B_Msk) >> CPU_SYS_REGS_PCLKCR10_CAN_B_Pos) /*!< CAN_B Get Value            */


#define CPU_SYS_REGS_PCLKCR10_CAN_A_Pos    (0U)                                                                                  /*!< CAN_A Postion   0          */ 
#define CPU_SYS_REGS_PCLKCR10_CAN_A_Msk    (0x1U << CPU_SYS_REGS_PCLKCR10_CAN_A_Pos)                                             /*!< CAN_A Mask      0x00000001 */
#define CPU_SYS_REGS_PCLKCR10_CAN_A_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR10_CAN_A_Pos) & CPU_SYS_REGS_PCLKCR10_CAN_A_Msk) /*!< CAN_A Set Value            */
#define CPU_SYS_REGS_PCLKCR10_CAN_A_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR10_CAN_A_Msk) >> CPU_SYS_REGS_PCLKCR10_CAN_A_Pos) /*!< CAN_A Get Value            */


/* PCLKCR11 bitfield */
#define CPU_SYS_REGS_PCLKCR11_USB_A_Pos    (16U)                                                                                 /*!< USB_A Postion   16         */ 
#define CPU_SYS_REGS_PCLKCR11_USB_A_Msk    (0x1U << CPU_SYS_REGS_PCLKCR11_USB_A_Pos)                                             /*!< USB_A Mask      0x00010000 */
#define CPU_SYS_REGS_PCLKCR11_USB_A_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR11_USB_A_Pos) & CPU_SYS_REGS_PCLKCR11_USB_A_Msk) /*!< USB_A Set Value            */
#define CPU_SYS_REGS_PCLKCR11_USB_A_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR11_USB_A_Msk) >> CPU_SYS_REGS_PCLKCR11_USB_A_Pos) /*!< USB_A Get Value            */


/* PCLKCR12 bitfield */
/* PCLKCR13 bitfield */
#define CPU_SYS_REGS_PCLKCR13_ADC_D_Pos    (3U)                                                                                  /*!< ADC_D Postion   3          */ 
#define CPU_SYS_REGS_PCLKCR13_ADC_D_Msk    (0x1U << CPU_SYS_REGS_PCLKCR13_ADC_D_Pos)                                             /*!< ADC_D Mask      0x00000008 */
#define CPU_SYS_REGS_PCLKCR13_ADC_D_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR13_ADC_D_Pos) & CPU_SYS_REGS_PCLKCR13_ADC_D_Msk) /*!< ADC_D Set Value            */
#define CPU_SYS_REGS_PCLKCR13_ADC_D_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR13_ADC_D_Msk) >> CPU_SYS_REGS_PCLKCR13_ADC_D_Pos) /*!< ADC_D Get Value            */


#define CPU_SYS_REGS_PCLKCR13_ADC_C_Pos    (2U)                                                                                  /*!< ADC_C Postion   2          */ 
#define CPU_SYS_REGS_PCLKCR13_ADC_C_Msk    (0x1U << CPU_SYS_REGS_PCLKCR13_ADC_C_Pos)                                             /*!< ADC_C Mask      0x00000004 */
#define CPU_SYS_REGS_PCLKCR13_ADC_C_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR13_ADC_C_Pos) & CPU_SYS_REGS_PCLKCR13_ADC_C_Msk) /*!< ADC_C Set Value            */
#define CPU_SYS_REGS_PCLKCR13_ADC_C_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR13_ADC_C_Msk) >> CPU_SYS_REGS_PCLKCR13_ADC_C_Pos) /*!< ADC_C Get Value            */


#define CPU_SYS_REGS_PCLKCR13_ADC_B_Pos    (1U)                                                                                  /*!< ADC_B Postion   1          */ 
#define CPU_SYS_REGS_PCLKCR13_ADC_B_Msk    (0x1U << CPU_SYS_REGS_PCLKCR13_ADC_B_Pos)                                             /*!< ADC_B Mask      0x00000002 */
#define CPU_SYS_REGS_PCLKCR13_ADC_B_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR13_ADC_B_Pos) & CPU_SYS_REGS_PCLKCR13_ADC_B_Msk) /*!< ADC_B Set Value            */
#define CPU_SYS_REGS_PCLKCR13_ADC_B_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR13_ADC_B_Msk) >> CPU_SYS_REGS_PCLKCR13_ADC_B_Pos) /*!< ADC_B Get Value            */


#define CPU_SYS_REGS_PCLKCR13_ADC_A_Pos    (0U)                                                                                  /*!< ADC_A Postion   0          */ 
#define CPU_SYS_REGS_PCLKCR13_ADC_A_Msk    (0x1U << CPU_SYS_REGS_PCLKCR13_ADC_A_Pos)                                             /*!< ADC_A Mask      0x00000001 */
#define CPU_SYS_REGS_PCLKCR13_ADC_A_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR13_ADC_A_Pos) & CPU_SYS_REGS_PCLKCR13_ADC_A_Msk) /*!< ADC_A Set Value            */
#define CPU_SYS_REGS_PCLKCR13_ADC_A_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR13_ADC_A_Msk) >> CPU_SYS_REGS_PCLKCR13_ADC_A_Pos) /*!< ADC_A Get Value            */


/* PCLKCR14 bitfield */
#define CPU_SYS_REGS_PCLKCR14_CMPSS8_Pos    (7U)                                                                                  /*!< CMPSS8 Postion   7          */ 
#define CPU_SYS_REGS_PCLKCR14_CMPSS8_Msk    (0x1U << CPU_SYS_REGS_PCLKCR14_CMPSS8_Pos)                                            /*!< CMPSS8 Mask      0x00000080 */
#define CPU_SYS_REGS_PCLKCR14_CMPSS8_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR14_CMPSS8_Pos) & CPU_SYS_REGS_PCLKCR14_CMPSS8_Msk) /*!< CMPSS8 Set Value            */
#define CPU_SYS_REGS_PCLKCR14_CMPSS8_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR14_CMPSS8_Msk) >> CPU_SYS_REGS_PCLKCR14_CMPSS8_Pos) /*!< CMPSS8 Get Value            */


#define CPU_SYS_REGS_PCLKCR14_CMPSS7_Pos    (6U)                                                                                  /*!< CMPSS7 Postion   6          */ 
#define CPU_SYS_REGS_PCLKCR14_CMPSS7_Msk    (0x1U << CPU_SYS_REGS_PCLKCR14_CMPSS7_Pos)                                            /*!< CMPSS7 Mask      0x00000040 */
#define CPU_SYS_REGS_PCLKCR14_CMPSS7_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR14_CMPSS7_Pos) & CPU_SYS_REGS_PCLKCR14_CMPSS7_Msk) /*!< CMPSS7 Set Value            */
#define CPU_SYS_REGS_PCLKCR14_CMPSS7_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR14_CMPSS7_Msk) >> CPU_SYS_REGS_PCLKCR14_CMPSS7_Pos) /*!< CMPSS7 Get Value            */


#define CPU_SYS_REGS_PCLKCR14_CMPSS6_Pos    (5U)                                                                                  /*!< CMPSS6 Postion   5          */ 
#define CPU_SYS_REGS_PCLKCR14_CMPSS6_Msk    (0x1U << CPU_SYS_REGS_PCLKCR14_CMPSS6_Pos)                                            /*!< CMPSS6 Mask      0x00000020 */
#define CPU_SYS_REGS_PCLKCR14_CMPSS6_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR14_CMPSS6_Pos) & CPU_SYS_REGS_PCLKCR14_CMPSS6_Msk) /*!< CMPSS6 Set Value            */
#define CPU_SYS_REGS_PCLKCR14_CMPSS6_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR14_CMPSS6_Msk) >> CPU_SYS_REGS_PCLKCR14_CMPSS6_Pos) /*!< CMPSS6 Get Value            */


#define CPU_SYS_REGS_PCLKCR14_CMPSS5_Pos    (4U)                                                                                  /*!< CMPSS5 Postion   4          */ 
#define CPU_SYS_REGS_PCLKCR14_CMPSS5_Msk    (0x1U << CPU_SYS_REGS_PCLKCR14_CMPSS5_Pos)                                            /*!< CMPSS5 Mask      0x00000010 */
#define CPU_SYS_REGS_PCLKCR14_CMPSS5_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR14_CMPSS5_Pos) & CPU_SYS_REGS_PCLKCR14_CMPSS5_Msk) /*!< CMPSS5 Set Value            */
#define CPU_SYS_REGS_PCLKCR14_CMPSS5_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR14_CMPSS5_Msk) >> CPU_SYS_REGS_PCLKCR14_CMPSS5_Pos) /*!< CMPSS5 Get Value            */


#define CPU_SYS_REGS_PCLKCR14_CMPSS4_Pos    (3U)                                                                                  /*!< CMPSS4 Postion   3          */ 
#define CPU_SYS_REGS_PCLKCR14_CMPSS4_Msk    (0x1U << CPU_SYS_REGS_PCLKCR14_CMPSS4_Pos)                                            /*!< CMPSS4 Mask      0x00000008 */
#define CPU_SYS_REGS_PCLKCR14_CMPSS4_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR14_CMPSS4_Pos) & CPU_SYS_REGS_PCLKCR14_CMPSS4_Msk) /*!< CMPSS4 Set Value            */
#define CPU_SYS_REGS_PCLKCR14_CMPSS4_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR14_CMPSS4_Msk) >> CPU_SYS_REGS_PCLKCR14_CMPSS4_Pos) /*!< CMPSS4 Get Value            */


#define CPU_SYS_REGS_PCLKCR14_CMPSS3_Pos    (2U)                                                                                  /*!< CMPSS3 Postion   2          */ 
#define CPU_SYS_REGS_PCLKCR14_CMPSS3_Msk    (0x1U << CPU_SYS_REGS_PCLKCR14_CMPSS3_Pos)                                            /*!< CMPSS3 Mask      0x00000004 */
#define CPU_SYS_REGS_PCLKCR14_CMPSS3_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR14_CMPSS3_Pos) & CPU_SYS_REGS_PCLKCR14_CMPSS3_Msk) /*!< CMPSS3 Set Value            */
#define CPU_SYS_REGS_PCLKCR14_CMPSS3_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR14_CMPSS3_Msk) >> CPU_SYS_REGS_PCLKCR14_CMPSS3_Pos) /*!< CMPSS3 Get Value            */


#define CPU_SYS_REGS_PCLKCR14_CMPSS2_Pos    (1U)                                                                                  /*!< CMPSS2 Postion   1          */ 
#define CPU_SYS_REGS_PCLKCR14_CMPSS2_Msk    (0x1U << CPU_SYS_REGS_PCLKCR14_CMPSS2_Pos)                                            /*!< CMPSS2 Mask      0x00000002 */
#define CPU_SYS_REGS_PCLKCR14_CMPSS2_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR14_CMPSS2_Pos) & CPU_SYS_REGS_PCLKCR14_CMPSS2_Msk) /*!< CMPSS2 Set Value            */
#define CPU_SYS_REGS_PCLKCR14_CMPSS2_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR14_CMPSS2_Msk) >> CPU_SYS_REGS_PCLKCR14_CMPSS2_Pos) /*!< CMPSS2 Get Value            */


#define CPU_SYS_REGS_PCLKCR14_CMPSS1_Pos    (0U)                                                                                  /*!< CMPSS1 Postion   0          */ 
#define CPU_SYS_REGS_PCLKCR14_CMPSS1_Msk    (0x1U << CPU_SYS_REGS_PCLKCR14_CMPSS1_Pos)                                            /*!< CMPSS1 Mask      0x00000001 */
#define CPU_SYS_REGS_PCLKCR14_CMPSS1_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR14_CMPSS1_Pos) & CPU_SYS_REGS_PCLKCR14_CMPSS1_Msk) /*!< CMPSS1 Set Value            */
#define CPU_SYS_REGS_PCLKCR14_CMPSS1_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR14_CMPSS1_Msk) >> CPU_SYS_REGS_PCLKCR14_CMPSS1_Pos) /*!< CMPSS1 Get Value            */


/* PCLKCR16 bitfield */
#define CPU_SYS_REGS_PCLKCR16_DAC_C_Pos    (18U)                                                                                 /*!< DAC_C Postion   18         */ 
#define CPU_SYS_REGS_PCLKCR16_DAC_C_Msk    (0x1U << CPU_SYS_REGS_PCLKCR16_DAC_C_Pos)                                             /*!< DAC_C Mask      0x00040000 */
#define CPU_SYS_REGS_PCLKCR16_DAC_C_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR16_DAC_C_Pos) & CPU_SYS_REGS_PCLKCR16_DAC_C_Msk) /*!< DAC_C Set Value            */
#define CPU_SYS_REGS_PCLKCR16_DAC_C_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR16_DAC_C_Msk) >> CPU_SYS_REGS_PCLKCR16_DAC_C_Pos) /*!< DAC_C Get Value            */


#define CPU_SYS_REGS_PCLKCR16_DAC_B_Pos    (17U)                                                                                 /*!< DAC_B Postion   17         */ 
#define CPU_SYS_REGS_PCLKCR16_DAC_B_Msk    (0x1U << CPU_SYS_REGS_PCLKCR16_DAC_B_Pos)                                             /*!< DAC_B Mask      0x00020000 */
#define CPU_SYS_REGS_PCLKCR16_DAC_B_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR16_DAC_B_Pos) & CPU_SYS_REGS_PCLKCR16_DAC_B_Msk) /*!< DAC_B Set Value            */
#define CPU_SYS_REGS_PCLKCR16_DAC_B_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR16_DAC_B_Msk) >> CPU_SYS_REGS_PCLKCR16_DAC_B_Pos) /*!< DAC_B Get Value            */


#define CPU_SYS_REGS_PCLKCR16_DAC_A_Pos    (16U)                                                                                 /*!< DAC_A Postion   16         */ 
#define CPU_SYS_REGS_PCLKCR16_DAC_A_Msk    (0x1U << CPU_SYS_REGS_PCLKCR16_DAC_A_Pos)                                             /*!< DAC_A Mask      0x00010000 */
#define CPU_SYS_REGS_PCLKCR16_DAC_A_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR16_DAC_A_Pos) & CPU_SYS_REGS_PCLKCR16_DAC_A_Msk) /*!< DAC_A Set Value            */
#define CPU_SYS_REGS_PCLKCR16_DAC_A_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR16_DAC_A_Msk) >> CPU_SYS_REGS_PCLKCR16_DAC_A_Pos) /*!< DAC_A Get Value            */


/* PCLKCR17 bitfield */
#define CPU_SYS_REGS_PCLKCR17_CLB8_Pos    (7U)                                                                                  /*!< CLB8 Postion   7          */ 
#define CPU_SYS_REGS_PCLKCR17_CLB8_Msk    (0x1U << CPU_SYS_REGS_PCLKCR17_CLB8_Pos)                                              /*!< CLB8 Mask      0x00000080 */
#define CPU_SYS_REGS_PCLKCR17_CLB8_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR17_CLB8_Pos) & CPU_SYS_REGS_PCLKCR17_CLB8_Msk) /*!< CLB8 Set Value            */
#define CPU_SYS_REGS_PCLKCR17_CLB8_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR17_CLB8_Msk) >> CPU_SYS_REGS_PCLKCR17_CLB8_Pos) /*!< CLB8 Get Value            */


#define CPU_SYS_REGS_PCLKCR17_CLB7_Pos    (6U)                                                                                  /*!< CLB7 Postion   6          */ 
#define CPU_SYS_REGS_PCLKCR17_CLB7_Msk    (0x1U << CPU_SYS_REGS_PCLKCR17_CLB7_Pos)                                              /*!< CLB7 Mask      0x00000040 */
#define CPU_SYS_REGS_PCLKCR17_CLB7_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR17_CLB7_Pos) & CPU_SYS_REGS_PCLKCR17_CLB7_Msk) /*!< CLB7 Set Value            */
#define CPU_SYS_REGS_PCLKCR17_CLB7_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR17_CLB7_Msk) >> CPU_SYS_REGS_PCLKCR17_CLB7_Pos) /*!< CLB7 Get Value            */


#define CPU_SYS_REGS_PCLKCR17_CLB6_Pos    (5U)                                                                                  /*!< CLB6 Postion   5          */ 
#define CPU_SYS_REGS_PCLKCR17_CLB6_Msk    (0x1U << CPU_SYS_REGS_PCLKCR17_CLB6_Pos)                                              /*!< CLB6 Mask      0x00000020 */
#define CPU_SYS_REGS_PCLKCR17_CLB6_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR17_CLB6_Pos) & CPU_SYS_REGS_PCLKCR17_CLB6_Msk) /*!< CLB6 Set Value            */
#define CPU_SYS_REGS_PCLKCR17_CLB6_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR17_CLB6_Msk) >> CPU_SYS_REGS_PCLKCR17_CLB6_Pos) /*!< CLB6 Get Value            */


#define CPU_SYS_REGS_PCLKCR17_CLB5_Pos    (4U)                                                                                  /*!< CLB5 Postion   4          */ 
#define CPU_SYS_REGS_PCLKCR17_CLB5_Msk    (0x1U << CPU_SYS_REGS_PCLKCR17_CLB5_Pos)                                              /*!< CLB5 Mask      0x00000010 */
#define CPU_SYS_REGS_PCLKCR17_CLB5_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR17_CLB5_Pos) & CPU_SYS_REGS_PCLKCR17_CLB5_Msk) /*!< CLB5 Set Value            */
#define CPU_SYS_REGS_PCLKCR17_CLB5_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR17_CLB5_Msk) >> CPU_SYS_REGS_PCLKCR17_CLB5_Pos) /*!< CLB5 Get Value            */


#define CPU_SYS_REGS_PCLKCR17_CLB4_Pos    (3U)                                                                                  /*!< CLB4 Postion   3          */ 
#define CPU_SYS_REGS_PCLKCR17_CLB4_Msk    (0x1U << CPU_SYS_REGS_PCLKCR17_CLB4_Pos)                                              /*!< CLB4 Mask      0x00000008 */
#define CPU_SYS_REGS_PCLKCR17_CLB4_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR17_CLB4_Pos) & CPU_SYS_REGS_PCLKCR17_CLB4_Msk) /*!< CLB4 Set Value            */
#define CPU_SYS_REGS_PCLKCR17_CLB4_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR17_CLB4_Msk) >> CPU_SYS_REGS_PCLKCR17_CLB4_Pos) /*!< CLB4 Get Value            */


#define CPU_SYS_REGS_PCLKCR17_CLB3_Pos    (2U)                                                                                  /*!< CLB3 Postion   2          */ 
#define CPU_SYS_REGS_PCLKCR17_CLB3_Msk    (0x1U << CPU_SYS_REGS_PCLKCR17_CLB3_Pos)                                              /*!< CLB3 Mask      0x00000004 */
#define CPU_SYS_REGS_PCLKCR17_CLB3_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR17_CLB3_Pos) & CPU_SYS_REGS_PCLKCR17_CLB3_Msk) /*!< CLB3 Set Value            */
#define CPU_SYS_REGS_PCLKCR17_CLB3_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR17_CLB3_Msk) >> CPU_SYS_REGS_PCLKCR17_CLB3_Pos) /*!< CLB3 Get Value            */


#define CPU_SYS_REGS_PCLKCR17_CLB2_Pos    (1U)                                                                                  /*!< CLB2 Postion   1          */ 
#define CPU_SYS_REGS_PCLKCR17_CLB2_Msk    (0x1U << CPU_SYS_REGS_PCLKCR17_CLB2_Pos)                                              /*!< CLB2 Mask      0x00000002 */
#define CPU_SYS_REGS_PCLKCR17_CLB2_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR17_CLB2_Pos) & CPU_SYS_REGS_PCLKCR17_CLB2_Msk) /*!< CLB2 Set Value            */
#define CPU_SYS_REGS_PCLKCR17_CLB2_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR17_CLB2_Msk) >> CPU_SYS_REGS_PCLKCR17_CLB2_Pos) /*!< CLB2 Get Value            */


#define CPU_SYS_REGS_PCLKCR17_CLB1_Pos    (0U)                                                                                  /*!< CLB1 Postion   0          */ 
#define CPU_SYS_REGS_PCLKCR17_CLB1_Msk    (0x1U << CPU_SYS_REGS_PCLKCR17_CLB1_Pos)                                              /*!< CLB1 Mask      0x00000001 */
#define CPU_SYS_REGS_PCLKCR17_CLB1_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR17_CLB1_Pos) & CPU_SYS_REGS_PCLKCR17_CLB1_Msk) /*!< CLB1 Set Value            */
#define CPU_SYS_REGS_PCLKCR17_CLB1_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR17_CLB1_Msk) >> CPU_SYS_REGS_PCLKCR17_CLB1_Pos) /*!< CLB1 Get Value            */


/* SECMSEL bitfield */
/* LPMCR bitfield */
#define CPU_SYS_REGS_LPMCR_QUALSTDBY_Pos    (2U)                                                                                  /*!< QUALSTDBY Postion   2          */ 
#define CPU_SYS_REGS_LPMCR_QUALSTDBY_Msk    (0x3fU << CPU_SYS_REGS_LPMCR_QUALSTDBY_Pos)                                           /*!< QUALSTDBY Mask      0x000000FC */
#define CPU_SYS_REGS_LPMCR_QUALSTDBY_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_LPMCR_QUALSTDBY_Pos) & CPU_SYS_REGS_LPMCR_QUALSTDBY_Msk) /*!< QUALSTDBY Set Value            */
#define CPU_SYS_REGS_LPMCR_QUALSTDBY_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_LPMCR_QUALSTDBY_Msk) >> CPU_SYS_REGS_LPMCR_QUALSTDBY_Pos) /*!< QUALSTDBY Get Value            */


/* GPIOLPMSEL0 bitfield */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO31_Pos    (31U)                                                                                 /*!< GPIO31 Postion   31         */ 
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO31_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO31_Pos)                                         /*!< GPIO31 Mask      0x80000000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO31_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO31_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO31_Msk) /*!< GPIO31 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO31_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO31_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO31_Pos) /*!< GPIO31 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO30_Pos    (30U)                                                                                 /*!< GPIO30 Postion   30         */ 
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO30_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO30_Pos)                                         /*!< GPIO30 Mask      0x40000000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO30_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO30_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO30_Msk) /*!< GPIO30 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO30_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO30_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO30_Pos) /*!< GPIO30 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO29_Pos    (29U)                                                                                 /*!< GPIO29 Postion   29         */ 
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO29_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO29_Pos)                                         /*!< GPIO29 Mask      0x20000000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO29_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO29_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO29_Msk) /*!< GPIO29 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO29_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO29_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO29_Pos) /*!< GPIO29 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO28_Pos    (28U)                                                                                 /*!< GPIO28 Postion   28         */ 
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO28_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO28_Pos)                                         /*!< GPIO28 Mask      0x10000000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO28_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO28_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO28_Msk) /*!< GPIO28 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO28_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO28_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO28_Pos) /*!< GPIO28 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO27_Pos    (27U)                                                                                 /*!< GPIO27 Postion   27         */ 
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO27_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO27_Pos)                                         /*!< GPIO27 Mask      0x08000000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO27_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO27_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO27_Msk) /*!< GPIO27 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO27_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO27_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO27_Pos) /*!< GPIO27 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO26_Pos    (26U)                                                                                 /*!< GPIO26 Postion   26         */ 
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO26_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO26_Pos)                                         /*!< GPIO26 Mask      0x04000000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO26_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO26_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO26_Msk) /*!< GPIO26 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO26_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO26_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO26_Pos) /*!< GPIO26 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO25_Pos    (25U)                                                                                 /*!< GPIO25 Postion   25         */ 
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO25_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO25_Pos)                                         /*!< GPIO25 Mask      0x02000000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO25_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO25_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO25_Msk) /*!< GPIO25 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO25_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO25_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO25_Pos) /*!< GPIO25 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO24_Pos    (24U)                                                                                 /*!< GPIO24 Postion   24         */ 
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO24_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO24_Pos)                                         /*!< GPIO24 Mask      0x01000000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO24_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO24_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO24_Msk) /*!< GPIO24 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO24_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO24_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO24_Pos) /*!< GPIO24 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO23_Pos    (23U)                                                                                 /*!< GPIO23 Postion   23         */ 
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO23_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO23_Pos)                                         /*!< GPIO23 Mask      0x00800000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO23_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO23_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO23_Msk) /*!< GPIO23 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO23_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO23_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO23_Pos) /*!< GPIO23 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO22_Pos    (22U)                                                                                 /*!< GPIO22 Postion   22         */ 
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO22_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO22_Pos)                                         /*!< GPIO22 Mask      0x00400000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO22_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO22_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO22_Msk) /*!< GPIO22 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO22_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO22_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO22_Pos) /*!< GPIO22 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO21_Pos    (21U)                                                                                 /*!< GPIO21 Postion   21         */ 
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO21_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO21_Pos)                                         /*!< GPIO21 Mask      0x00200000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO21_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO21_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO21_Msk) /*!< GPIO21 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO21_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO21_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO21_Pos) /*!< GPIO21 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO20_Pos    (20U)                                                                                 /*!< GPIO20 Postion   20         */ 
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO20_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO20_Pos)                                         /*!< GPIO20 Mask      0x00100000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO20_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO20_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO20_Msk) /*!< GPIO20 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO20_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO20_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO20_Pos) /*!< GPIO20 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO19_Pos    (19U)                                                                                 /*!< GPIO19 Postion   19         */ 
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO19_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO19_Pos)                                         /*!< GPIO19 Mask      0x00080000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO19_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO19_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO19_Msk) /*!< GPIO19 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO19_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO19_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO19_Pos) /*!< GPIO19 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO18_Pos    (18U)                                                                                 /*!< GPIO18 Postion   18         */ 
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO18_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO18_Pos)                                         /*!< GPIO18 Mask      0x00040000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO18_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO18_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO18_Msk) /*!< GPIO18 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO18_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO18_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO18_Pos) /*!< GPIO18 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO17_Pos    (17U)                                                                                 /*!< GPIO17 Postion   17         */ 
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO17_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO17_Pos)                                         /*!< GPIO17 Mask      0x00020000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO17_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO17_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO17_Msk) /*!< GPIO17 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO17_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO17_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO17_Pos) /*!< GPIO17 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO16_Pos    (16U)                                                                                 /*!< GPIO16 Postion   16         */ 
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO16_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO16_Pos)                                         /*!< GPIO16 Mask      0x00010000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO16_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO16_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO16_Msk) /*!< GPIO16 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO16_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO16_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO16_Pos) /*!< GPIO16 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO15_Pos    (15U)                                                                                 /*!< GPIO15 Postion   15         */ 
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO15_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO15_Pos)                                         /*!< GPIO15 Mask      0x00008000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO15_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO15_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO15_Msk) /*!< GPIO15 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO15_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO15_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO15_Pos) /*!< GPIO15 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO14_Pos    (14U)                                                                                 /*!< GPIO14 Postion   14         */ 
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO14_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO14_Pos)                                         /*!< GPIO14 Mask      0x00004000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO14_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO14_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO14_Msk) /*!< GPIO14 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO14_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO14_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO14_Pos) /*!< GPIO14 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO13_Pos    (13U)                                                                                 /*!< GPIO13 Postion   13         */ 
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO13_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO13_Pos)                                         /*!< GPIO13 Mask      0x00002000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO13_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO13_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO13_Msk) /*!< GPIO13 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO13_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO13_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO13_Pos) /*!< GPIO13 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO12_Pos    (12U)                                                                                 /*!< GPIO12 Postion   12         */ 
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO12_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO12_Pos)                                         /*!< GPIO12 Mask      0x00001000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO12_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO12_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO12_Msk) /*!< GPIO12 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO12_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO12_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO12_Pos) /*!< GPIO12 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO11_Pos    (11U)                                                                                 /*!< GPIO11 Postion   11         */ 
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO11_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO11_Pos)                                         /*!< GPIO11 Mask      0x00000800 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO11_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO11_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO11_Msk) /*!< GPIO11 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO11_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO11_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO11_Pos) /*!< GPIO11 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO10_Pos    (10U)                                                                                 /*!< GPIO10 Postion   10         */ 
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO10_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO10_Pos)                                         /*!< GPIO10 Mask      0x00000400 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO10_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO10_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO10_Msk) /*!< GPIO10 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO10_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO10_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO10_Pos) /*!< GPIO10 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO9_Pos    (9U)                                                                                  /*!< GPIO9 Postion   9          */ 
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO9_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO9_Pos)                                          /*!< GPIO9 Mask      0x00000200 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO9_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO9_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO9_Msk) /*!< GPIO9 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO9_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO9_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO9_Pos) /*!< GPIO9 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO8_Pos    (8U)                                                                                  /*!< GPIO8 Postion   8          */ 
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO8_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO8_Pos)                                          /*!< GPIO8 Mask      0x00000100 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO8_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO8_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO8_Msk) /*!< GPIO8 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO8_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO8_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO8_Pos) /*!< GPIO8 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO7_Pos    (7U)                                                                                  /*!< GPIO7 Postion   7          */ 
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO7_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO7_Pos)                                          /*!< GPIO7 Mask      0x00000080 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO7_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO7_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO7_Msk) /*!< GPIO7 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO7_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO7_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO7_Pos) /*!< GPIO7 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO6_Pos    (6U)                                                                                  /*!< GPIO6 Postion   6          */ 
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO6_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO6_Pos)                                          /*!< GPIO6 Mask      0x00000040 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO6_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO6_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO6_Msk) /*!< GPIO6 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO6_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO6_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO6_Pos) /*!< GPIO6 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO5_Pos    (5U)                                                                                  /*!< GPIO5 Postion   5          */ 
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO5_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO5_Pos)                                          /*!< GPIO5 Mask      0x00000020 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO5_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO5_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO5_Msk) /*!< GPIO5 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO5_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO5_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO5_Pos) /*!< GPIO5 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO4_Pos    (4U)                                                                                  /*!< GPIO4 Postion   4          */ 
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO4_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO4_Pos)                                          /*!< GPIO4 Mask      0x00000010 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO4_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO4_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO4_Msk) /*!< GPIO4 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO4_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO4_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO4_Pos) /*!< GPIO4 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO3_Pos    (3U)                                                                                  /*!< GPIO3 Postion   3          */ 
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO3_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO3_Pos)                                          /*!< GPIO3 Mask      0x00000008 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO3_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO3_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO3_Msk) /*!< GPIO3 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO3_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO3_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO3_Pos) /*!< GPIO3 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO2_Pos    (2U)                                                                                  /*!< GPIO2 Postion   2          */ 
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO2_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO2_Pos)                                          /*!< GPIO2 Mask      0x00000004 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO2_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO2_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO2_Msk) /*!< GPIO2 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO2_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO2_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO2_Pos) /*!< GPIO2 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO1_Pos    (1U)                                                                                  /*!< GPIO1 Postion   1          */ 
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO1_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO1_Pos)                                          /*!< GPIO1 Mask      0x00000002 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO1_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO1_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO1_Msk) /*!< GPIO1 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO1_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO1_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO1_Pos) /*!< GPIO1 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO0_Pos    (0U)                                                                                  /*!< GPIO0 Postion   0          */ 
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO0_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO0_Pos)                                          /*!< GPIO0 Mask      0x00000001 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO0_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO0_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO0_Msk) /*!< GPIO0 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO0_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO0_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO0_Pos) /*!< GPIO0 Get Value            */


/* GPIOLPMSEL1 bitfield */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO63_Pos    (31U)                                                                                 /*!< GPIO63 Postion   31         */ 
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO63_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO63_Pos)                                         /*!< GPIO63 Mask      0x80000000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO63_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO63_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO63_Msk) /*!< GPIO63 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO63_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO63_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO63_Pos) /*!< GPIO63 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO62_Pos    (30U)                                                                                 /*!< GPIO62 Postion   30         */ 
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO62_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO62_Pos)                                         /*!< GPIO62 Mask      0x40000000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO62_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO62_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO62_Msk) /*!< GPIO62 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO62_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO62_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO62_Pos) /*!< GPIO62 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO61_Pos    (29U)                                                                                 /*!< GPIO61 Postion   29         */ 
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO61_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO61_Pos)                                         /*!< GPIO61 Mask      0x20000000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO61_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO61_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO61_Msk) /*!< GPIO61 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO61_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO61_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO61_Pos) /*!< GPIO61 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO60_Pos    (28U)                                                                                 /*!< GPIO60 Postion   28         */ 
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO60_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO60_Pos)                                         /*!< GPIO60 Mask      0x10000000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO60_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO60_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO60_Msk) /*!< GPIO60 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO60_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO60_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO60_Pos) /*!< GPIO60 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO59_Pos    (27U)                                                                                 /*!< GPIO59 Postion   27         */ 
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO59_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO59_Pos)                                         /*!< GPIO59 Mask      0x08000000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO59_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO59_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO59_Msk) /*!< GPIO59 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO59_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO59_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO59_Pos) /*!< GPIO59 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO58_Pos    (26U)                                                                                 /*!< GPIO58 Postion   26         */ 
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO58_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO58_Pos)                                         /*!< GPIO58 Mask      0x04000000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO58_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO58_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO58_Msk) /*!< GPIO58 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO58_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO58_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO58_Pos) /*!< GPIO58 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO57_Pos    (25U)                                                                                 /*!< GPIO57 Postion   25         */ 
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO57_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO57_Pos)                                         /*!< GPIO57 Mask      0x02000000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO57_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO57_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO57_Msk) /*!< GPIO57 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO57_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO57_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO57_Pos) /*!< GPIO57 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO56_Pos    (24U)                                                                                 /*!< GPIO56 Postion   24         */ 
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO56_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO56_Pos)                                         /*!< GPIO56 Mask      0x01000000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO56_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO56_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO56_Msk) /*!< GPIO56 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO56_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO56_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO56_Pos) /*!< GPIO56 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO55_Pos    (23U)                                                                                 /*!< GPIO55 Postion   23         */ 
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO55_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO55_Pos)                                         /*!< GPIO55 Mask      0x00800000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO55_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO55_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO55_Msk) /*!< GPIO55 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO55_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO55_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO55_Pos) /*!< GPIO55 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO54_Pos    (22U)                                                                                 /*!< GPIO54 Postion   22         */ 
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO54_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO54_Pos)                                         /*!< GPIO54 Mask      0x00400000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO54_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO54_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO54_Msk) /*!< GPIO54 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO54_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO54_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO54_Pos) /*!< GPIO54 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO53_Pos    (21U)                                                                                 /*!< GPIO53 Postion   21         */ 
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO53_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO53_Pos)                                         /*!< GPIO53 Mask      0x00200000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO53_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO53_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO53_Msk) /*!< GPIO53 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO53_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO53_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO53_Pos) /*!< GPIO53 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO52_Pos    (20U)                                                                                 /*!< GPIO52 Postion   20         */ 
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO52_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO52_Pos)                                         /*!< GPIO52 Mask      0x00100000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO52_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO52_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO52_Msk) /*!< GPIO52 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO52_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO52_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO52_Pos) /*!< GPIO52 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO51_Pos    (19U)                                                                                 /*!< GPIO51 Postion   19         */ 
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO51_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO51_Pos)                                         /*!< GPIO51 Mask      0x00080000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO51_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO51_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO51_Msk) /*!< GPIO51 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO51_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO51_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO51_Pos) /*!< GPIO51 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO50_Pos    (18U)                                                                                 /*!< GPIO50 Postion   18         */ 
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO50_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO50_Pos)                                         /*!< GPIO50 Mask      0x00040000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO50_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO50_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO50_Msk) /*!< GPIO50 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO50_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO50_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO50_Pos) /*!< GPIO50 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO49_Pos    (17U)                                                                                 /*!< GPIO49 Postion   17         */ 
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO49_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO49_Pos)                                         /*!< GPIO49 Mask      0x00020000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO49_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO49_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO49_Msk) /*!< GPIO49 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO49_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO49_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO49_Pos) /*!< GPIO49 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO48_Pos    (16U)                                                                                 /*!< GPIO48 Postion   16         */ 
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO48_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO48_Pos)                                         /*!< GPIO48 Mask      0x00010000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO48_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO48_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO48_Msk) /*!< GPIO48 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO48_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO48_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO48_Pos) /*!< GPIO48 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO47_Pos    (15U)                                                                                 /*!< GPIO47 Postion   15         */ 
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO47_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO47_Pos)                                         /*!< GPIO47 Mask      0x00008000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO47_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO47_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO47_Msk) /*!< GPIO47 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO47_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO47_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO47_Pos) /*!< GPIO47 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO46_Pos    (14U)                                                                                 /*!< GPIO46 Postion   14         */ 
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO46_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO46_Pos)                                         /*!< GPIO46 Mask      0x00004000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO46_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO46_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO46_Msk) /*!< GPIO46 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO46_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO46_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO46_Pos) /*!< GPIO46 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO45_Pos    (13U)                                                                                 /*!< GPIO45 Postion   13         */ 
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO45_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO45_Pos)                                         /*!< GPIO45 Mask      0x00002000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO45_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO45_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO45_Msk) /*!< GPIO45 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO45_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO45_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO45_Pos) /*!< GPIO45 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO44_Pos    (12U)                                                                                 /*!< GPIO44 Postion   12         */ 
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO44_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO44_Pos)                                         /*!< GPIO44 Mask      0x00001000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO44_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO44_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO44_Msk) /*!< GPIO44 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO44_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO44_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO44_Pos) /*!< GPIO44 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO43_Pos    (11U)                                                                                 /*!< GPIO43 Postion   11         */ 
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO43_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO43_Pos)                                         /*!< GPIO43 Mask      0x00000800 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO43_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO43_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO43_Msk) /*!< GPIO43 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO43_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO43_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO43_Pos) /*!< GPIO43 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO42_Pos    (10U)                                                                                 /*!< GPIO42 Postion   10         */ 
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO42_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO42_Pos)                                         /*!< GPIO42 Mask      0x00000400 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO42_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO42_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO42_Msk) /*!< GPIO42 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO42_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO42_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO42_Pos) /*!< GPIO42 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO41_Pos    (9U)                                                                                  /*!< GPIO41 Postion   9          */ 
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO41_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO41_Pos)                                         /*!< GPIO41 Mask      0x00000200 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO41_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO41_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO41_Msk) /*!< GPIO41 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO41_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO41_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO41_Pos) /*!< GPIO41 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO40_Pos    (8U)                                                                                  /*!< GPIO40 Postion   8          */ 
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO40_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO40_Pos)                                         /*!< GPIO40 Mask      0x00000100 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO40_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO40_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO40_Msk) /*!< GPIO40 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO40_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO40_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO40_Pos) /*!< GPIO40 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO39_Pos    (7U)                                                                                  /*!< GPIO39 Postion   7          */ 
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO39_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO39_Pos)                                         /*!< GPIO39 Mask      0x00000080 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO39_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO39_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO39_Msk) /*!< GPIO39 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO39_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO39_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO39_Pos) /*!< GPIO39 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO38_Pos    (6U)                                                                                  /*!< GPIO38 Postion   6          */ 
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO38_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO38_Pos)                                         /*!< GPIO38 Mask      0x00000040 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO38_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO38_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO38_Msk) /*!< GPIO38 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO38_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO38_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO38_Pos) /*!< GPIO38 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO37_Pos    (5U)                                                                                  /*!< GPIO37 Postion   5          */ 
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO37_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO37_Pos)                                         /*!< GPIO37 Mask      0x00000020 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO37_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO37_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO37_Msk) /*!< GPIO37 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO37_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO37_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO37_Pos) /*!< GPIO37 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO36_Pos    (4U)                                                                                  /*!< GPIO36 Postion   4          */ 
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO36_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO36_Pos)                                         /*!< GPIO36 Mask      0x00000010 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO36_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO36_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO36_Msk) /*!< GPIO36 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO36_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO36_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO36_Pos) /*!< GPIO36 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO35_Pos    (3U)                                                                                  /*!< GPIO35 Postion   3          */ 
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO35_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO35_Pos)                                         /*!< GPIO35 Mask      0x00000008 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO35_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO35_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO35_Msk) /*!< GPIO35 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO35_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO35_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO35_Pos) /*!< GPIO35 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO34_Pos    (2U)                                                                                  /*!< GPIO34 Postion   2          */ 
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO34_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO34_Pos)                                         /*!< GPIO34 Mask      0x00000004 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO34_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO34_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO34_Msk) /*!< GPIO34 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO34_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO34_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO34_Pos) /*!< GPIO34 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO33_Pos    (1U)                                                                                  /*!< GPIO33 Postion   1          */ 
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO33_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO33_Pos)                                         /*!< GPIO33 Mask      0x00000002 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO33_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO33_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO33_Msk) /*!< GPIO33 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO33_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO33_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO33_Pos) /*!< GPIO33 Get Value            */


#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO32_Pos    (0U)                                                                                  /*!< GPIO32 Postion   0          */ 
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO32_Msk    (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO32_Pos)                                         /*!< GPIO32 Mask      0x00000001 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO32_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO32_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO32_Msk) /*!< GPIO32 Set Value            */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO32_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO32_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO32_Pos) /*!< GPIO32 Get Value            */


/* TMR2CLKCTL bitfield */
#define CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKPRESCALE_Pos    (3U)                                                                                  /*!< TMR2CLKPRESCALE Postion   3          */ 
#define CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKPRESCALE_Msk    (0x7U << CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKPRESCALE_Pos)                                 /*!< TMR2CLKPRESCALE Mask      0x00000038 */
#define CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKPRESCALE_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKPRESCALE_Pos) & CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKPRESCALE_Msk) /*!< TMR2CLKPRESCALE Set Value            */
#define CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKPRESCALE_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKPRESCALE_Msk) >> CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKPRESCALE_Pos) /*!< TMR2CLKPRESCALE Get Value            */


#define CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKSRCSEL_Pos    (0U)                                                                                  /*!< TMR2CLKSRCSEL Postion   0          */ 
#define CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKSRCSEL_Msk    (0x7U << CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKSRCSEL_Pos)                                   /*!< TMR2CLKSRCSEL Mask      0x00000007 */
#define CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKSRCSEL_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKSRCSEL_Pos) & CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKSRCSEL_Msk) /*!< TMR2CLKSRCSEL Set Value            */
#define CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKSRCSEL_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKSRCSEL_Msk) >> CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKSRCSEL_Pos) /*!< TMR2CLKSRCSEL Get Value            */


/* RESC bitfield */
#define CPU_SYS_REGS_RESC_TRSTN_PIN_STATUS_Pos    (31U)                                                                                 /*!< TRSTN_PIN_STATUS Postion   31         */ 
#define CPU_SYS_REGS_RESC_TRSTN_PIN_STATUS_Msk    (0x1U << CPU_SYS_REGS_RESC_TRSTN_PIN_STATUS_Pos)                                      /*!< TRSTN_PIN_STATUS Mask      0x80000000 */
#define CPU_SYS_REGS_RESC_TRSTN_PIN_STATUS_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_RESC_TRSTN_PIN_STATUS_Pos) & CPU_SYS_REGS_RESC_TRSTN_PIN_STATUS_Msk) /*!< TRSTN_PIN_STATUS Set Value            */
#define CPU_SYS_REGS_RESC_TRSTN_PIN_STATUS_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_RESC_TRSTN_PIN_STATUS_Msk) >> CPU_SYS_REGS_RESC_TRSTN_PIN_STATUS_Pos) /*!< TRSTN_PIN_STATUS Get Value            */


#define CPU_SYS_REGS_RESC_XRSN_PIN_STATUS_Pos    (30U)                                                                                 /*!< XRSN_PIN_STATUS Postion   30         */ 
#define CPU_SYS_REGS_RESC_XRSN_PIN_STATUS_Msk    (0x1U << CPU_SYS_REGS_RESC_XRSN_PIN_STATUS_Pos)                                       /*!< XRSN_PIN_STATUS Mask      0x40000000 */
#define CPU_SYS_REGS_RESC_XRSN_PIN_STATUS_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_RESC_XRSN_PIN_STATUS_Pos) & CPU_SYS_REGS_RESC_XRSN_PIN_STATUS_Msk) /*!< XRSN_PIN_STATUS Set Value            */
#define CPU_SYS_REGS_RESC_XRSN_PIN_STATUS_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_RESC_XRSN_PIN_STATUS_Msk) >> CPU_SYS_REGS_RESC_XRSN_PIN_STATUS_Pos) /*!< XRSN_PIN_STATUS Get Value            */


#define CPU_SYS_REGS_RESC_NMIWDRSN_Pos    (3U)                                                                                  /*!< NMIWDRSN Postion   3          */ 
#define CPU_SYS_REGS_RESC_NMIWDRSN_Msk    (0x1U << CPU_SYS_REGS_RESC_NMIWDRSN_Pos)                                              /*!< NMIWDRSN Mask      0x00000008 */
#define CPU_SYS_REGS_RESC_NMIWDRSN_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_RESC_NMIWDRSN_Pos) & CPU_SYS_REGS_RESC_NMIWDRSN_Msk) /*!< NMIWDRSN Set Value            */
#define CPU_SYS_REGS_RESC_NMIWDRSN_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_RESC_NMIWDRSN_Msk) >> CPU_SYS_REGS_RESC_NMIWDRSN_Pos) /*!< NMIWDRSN Get Value            */


#define CPU_SYS_REGS_RESC_WDRSN_Pos    (2U)                                                                                  /*!< WDRSN Postion   2          */ 
#define CPU_SYS_REGS_RESC_WDRSN_Msk    (0x1U << CPU_SYS_REGS_RESC_WDRSN_Pos)                                                 /*!< WDRSN Mask      0x00000004 */
#define CPU_SYS_REGS_RESC_WDRSN_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_RESC_WDRSN_Pos) & CPU_SYS_REGS_RESC_WDRSN_Msk)       /*!< WDRSN Set Value            */
#define CPU_SYS_REGS_RESC_WDRSN_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_RESC_WDRSN_Msk) >> CPU_SYS_REGS_RESC_WDRSN_Pos)       /*!< WDRSN Get Value            */


#define CPU_SYS_REGS_RESC_XRSN_Pos    (1U)                                                                                  /*!< XRSN Postion   1          */ 
#define CPU_SYS_REGS_RESC_XRSN_Msk    (0x1U << CPU_SYS_REGS_RESC_XRSN_Pos)                                                  /*!< XRSN Mask      0x00000002 */
#define CPU_SYS_REGS_RESC_XRSN_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_RESC_XRSN_Pos) & CPU_SYS_REGS_RESC_XRSN_Msk)         /*!< XRSN Set Value            */
#define CPU_SYS_REGS_RESC_XRSN_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_RESC_XRSN_Msk) >> CPU_SYS_REGS_RESC_XRSN_Pos)         /*!< XRSN Get Value            */


#define CPU_SYS_REGS_RESC_POR_Pos    (0U)                                                                                  /*!< POR Postion   0          */ 
#define CPU_SYS_REGS_RESC_POR_Msk    (0x1U << CPU_SYS_REGS_RESC_POR_Pos)                                                   /*!< POR Mask      0x00000001 */
#define CPU_SYS_REGS_RESC_POR_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_RESC_POR_Pos) & CPU_SYS_REGS_RESC_POR_Msk)           /*!< POR Set Value            */
#define CPU_SYS_REGS_RESC_POR_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_RESC_POR_Msk) >> CPU_SYS_REGS_RESC_POR_Pos)           /*!< POR Get Value            */


/* DWTMR2CLKCTL bitfield */
#define CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKPRESCALE_Pos    (3U)                                                                                  /*!< DWTMR2CLKPRESCALE Postion   3          */ 
#define CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKPRESCALE_Msk    (0x7U << CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKPRESCALE_Pos)                             /*!< DWTMR2CLKPRESCALE Mask      0x00000038 */
#define CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKPRESCALE_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKPRESCALE_Pos) & CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKPRESCALE_Msk) /*!< DWTMR2CLKPRESCALE Set Value            */
#define CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKPRESCALE_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKPRESCALE_Msk) >> CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKPRESCALE_Pos) /*!< DWTMR2CLKPRESCALE Get Value            */


#define CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKSRCSEL_Pos    (0U)                                                                                  /*!< DWTMR2CLKSRCSEL Postion   0          */ 
#define CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKSRCSEL_Msk    (0x7U << CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKSRCSEL_Pos)                               /*!< DWTMR2CLKSRCSEL Mask      0x00000007 */
#define CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKSRCSEL_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKSRCSEL_Pos) & CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKSRCSEL_Msk) /*!< DWTMR2CLKSRCSEL Set Value            */
#define CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKSRCSEL_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKSRCSEL_Msk) >> CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKSRCSEL_Pos) /*!< DWTMR2CLKSRCSEL Get Value            */


/* TFUCR bitfield */
#define CPU_SYS_REGS_TFUCR_TFU_Pos    (0U)                                                                                  /*!< TFU Postion   0          */ 
#define CPU_SYS_REGS_TFUCR_TFU_Msk    (0x1U << CPU_SYS_REGS_TFUCR_TFU_Pos)                                                  /*!< TFU Mask      0x00000001 */
#define CPU_SYS_REGS_TFUCR_TFU_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_TFUCR_TFU_Pos) & CPU_SYS_REGS_TFUCR_TFU_Msk)         /*!< TFU Set Value            */
#define CPU_SYS_REGS_TFUCR_TFU_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_TFUCR_TFU_Msk) >> CPU_SYS_REGS_TFUCR_TFU_Pos)         /*!< TFU Get Value            */


/* CRCCR bitfield */
#define CPU_SYS_REGS_CRCCR_CRC_Pos    (0U)                                                                                  /*!< CRC Postion   0          */ 
#define CPU_SYS_REGS_CRCCR_CRC_Msk    (0x1U << CPU_SYS_REGS_CRCCR_CRC_Pos)                                                  /*!< CRC Mask      0x00000001 */
#define CPU_SYS_REGS_CRCCR_CRC_Set(x) (((uint32_t) (x) << CPU_SYS_REGS_CRCCR_CRC_Pos) & CPU_SYS_REGS_CRCCR_CRC_Msk)         /*!< CRC Set Value            */
#define CPU_SYS_REGS_CRCCR_CRC_Get(x) (((uint32_t) (x) & CPU_SYS_REGS_CRCCR_CRC_Msk) >> CPU_SYS_REGS_CRCCR_CRC_Pos)         /*!< CRC Get Value            */


/* GSXLOCK bitfield */
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS15_Pos    (15U)                                                                                 /*!< LOCK_GS15 Postion   15         */ 
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS15_Msk    (0x1U << MEM_CFG_REGS_GSXLOCK_LOCK_GS15_Pos)                                          /*!< LOCK_GS15 Mask      0x00008000 */
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS15_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXLOCK_LOCK_GS15_Pos) & MEM_CFG_REGS_GSXLOCK_LOCK_GS15_Msk) /*!< LOCK_GS15 Set Value            */
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS15_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXLOCK_LOCK_GS15_Msk) >> MEM_CFG_REGS_GSXLOCK_LOCK_GS15_Pos) /*!< LOCK_GS15 Get Value            */


#define MEM_CFG_REGS_GSXLOCK_LOCK_GS14_Pos    (14U)                                                                                 /*!< LOCK_GS14 Postion   14         */ 
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS14_Msk    (0x1U << MEM_CFG_REGS_GSXLOCK_LOCK_GS14_Pos)                                          /*!< LOCK_GS14 Mask      0x00004000 */
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS14_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXLOCK_LOCK_GS14_Pos) & MEM_CFG_REGS_GSXLOCK_LOCK_GS14_Msk) /*!< LOCK_GS14 Set Value            */
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS14_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXLOCK_LOCK_GS14_Msk) >> MEM_CFG_REGS_GSXLOCK_LOCK_GS14_Pos) /*!< LOCK_GS14 Get Value            */


#define MEM_CFG_REGS_GSXLOCK_LOCK_GS13_Pos    (13U)                                                                                 /*!< LOCK_GS13 Postion   13         */ 
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS13_Msk    (0x1U << MEM_CFG_REGS_GSXLOCK_LOCK_GS13_Pos)                                          /*!< LOCK_GS13 Mask      0x00002000 */
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS13_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXLOCK_LOCK_GS13_Pos) & MEM_CFG_REGS_GSXLOCK_LOCK_GS13_Msk) /*!< LOCK_GS13 Set Value            */
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS13_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXLOCK_LOCK_GS13_Msk) >> MEM_CFG_REGS_GSXLOCK_LOCK_GS13_Pos) /*!< LOCK_GS13 Get Value            */


#define MEM_CFG_REGS_GSXLOCK_LOCK_GS12_Pos    (12U)                                                                                 /*!< LOCK_GS12 Postion   12         */ 
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS12_Msk    (0x1U << MEM_CFG_REGS_GSXLOCK_LOCK_GS12_Pos)                                          /*!< LOCK_GS12 Mask      0x00001000 */
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS12_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXLOCK_LOCK_GS12_Pos) & MEM_CFG_REGS_GSXLOCK_LOCK_GS12_Msk) /*!< LOCK_GS12 Set Value            */
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS12_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXLOCK_LOCK_GS12_Msk) >> MEM_CFG_REGS_GSXLOCK_LOCK_GS12_Pos) /*!< LOCK_GS12 Get Value            */


#define MEM_CFG_REGS_GSXLOCK_LOCK_GS11_Pos    (11U)                                                                                 /*!< LOCK_GS11 Postion   11         */ 
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS11_Msk    (0x1U << MEM_CFG_REGS_GSXLOCK_LOCK_GS11_Pos)                                          /*!< LOCK_GS11 Mask      0x00000800 */
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS11_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXLOCK_LOCK_GS11_Pos) & MEM_CFG_REGS_GSXLOCK_LOCK_GS11_Msk) /*!< LOCK_GS11 Set Value            */
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS11_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXLOCK_LOCK_GS11_Msk) >> MEM_CFG_REGS_GSXLOCK_LOCK_GS11_Pos) /*!< LOCK_GS11 Get Value            */


#define MEM_CFG_REGS_GSXLOCK_LOCK_GS10_Pos    (10U)                                                                                 /*!< LOCK_GS10 Postion   10         */ 
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS10_Msk    (0x1U << MEM_CFG_REGS_GSXLOCK_LOCK_GS10_Pos)                                          /*!< LOCK_GS10 Mask      0x00000400 */
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS10_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXLOCK_LOCK_GS10_Pos) & MEM_CFG_REGS_GSXLOCK_LOCK_GS10_Msk) /*!< LOCK_GS10 Set Value            */
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS10_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXLOCK_LOCK_GS10_Msk) >> MEM_CFG_REGS_GSXLOCK_LOCK_GS10_Pos) /*!< LOCK_GS10 Get Value            */


#define MEM_CFG_REGS_GSXLOCK_LOCK_GS9_Pos    (9U)                                                                                  /*!< LOCK_GS9 Postion   9          */ 
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS9_Msk    (0x1U << MEM_CFG_REGS_GSXLOCK_LOCK_GS9_Pos)                                           /*!< LOCK_GS9 Mask      0x00000200 */
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS9_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXLOCK_LOCK_GS9_Pos) & MEM_CFG_REGS_GSXLOCK_LOCK_GS9_Msk) /*!< LOCK_GS9 Set Value            */
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS9_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXLOCK_LOCK_GS9_Msk) >> MEM_CFG_REGS_GSXLOCK_LOCK_GS9_Pos) /*!< LOCK_GS9 Get Value            */


#define MEM_CFG_REGS_GSXLOCK_LOCK_GS8_Pos    (8U)                                                                                  /*!< LOCK_GS8 Postion   8          */ 
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS8_Msk    (0x1U << MEM_CFG_REGS_GSXLOCK_LOCK_GS8_Pos)                                           /*!< LOCK_GS8 Mask      0x00000100 */
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS8_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXLOCK_LOCK_GS8_Pos) & MEM_CFG_REGS_GSXLOCK_LOCK_GS8_Msk) /*!< LOCK_GS8 Set Value            */
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS8_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXLOCK_LOCK_GS8_Msk) >> MEM_CFG_REGS_GSXLOCK_LOCK_GS8_Pos) /*!< LOCK_GS8 Get Value            */


#define MEM_CFG_REGS_GSXLOCK_LOCK_GS7_Pos    (7U)                                                                                  /*!< LOCK_GS7 Postion   7          */ 
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS7_Msk    (0x1U << MEM_CFG_REGS_GSXLOCK_LOCK_GS7_Pos)                                           /*!< LOCK_GS7 Mask      0x00000080 */
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS7_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXLOCK_LOCK_GS7_Pos) & MEM_CFG_REGS_GSXLOCK_LOCK_GS7_Msk) /*!< LOCK_GS7 Set Value            */
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS7_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXLOCK_LOCK_GS7_Msk) >> MEM_CFG_REGS_GSXLOCK_LOCK_GS7_Pos) /*!< LOCK_GS7 Get Value            */


#define MEM_CFG_REGS_GSXLOCK_LOCK_GS6_Pos    (6U)                                                                                  /*!< LOCK_GS6 Postion   6          */ 
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS6_Msk    (0x1U << MEM_CFG_REGS_GSXLOCK_LOCK_GS6_Pos)                                           /*!< LOCK_GS6 Mask      0x00000040 */
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS6_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXLOCK_LOCK_GS6_Pos) & MEM_CFG_REGS_GSXLOCK_LOCK_GS6_Msk) /*!< LOCK_GS6 Set Value            */
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS6_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXLOCK_LOCK_GS6_Msk) >> MEM_CFG_REGS_GSXLOCK_LOCK_GS6_Pos) /*!< LOCK_GS6 Get Value            */


#define MEM_CFG_REGS_GSXLOCK_LOCK_GS5_Pos    (5U)                                                                                  /*!< LOCK_GS5 Postion   5          */ 
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS5_Msk    (0x1U << MEM_CFG_REGS_GSXLOCK_LOCK_GS5_Pos)                                           /*!< LOCK_GS5 Mask      0x00000020 */
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS5_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXLOCK_LOCK_GS5_Pos) & MEM_CFG_REGS_GSXLOCK_LOCK_GS5_Msk) /*!< LOCK_GS5 Set Value            */
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS5_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXLOCK_LOCK_GS5_Msk) >> MEM_CFG_REGS_GSXLOCK_LOCK_GS5_Pos) /*!< LOCK_GS5 Get Value            */


#define MEM_CFG_REGS_GSXLOCK_LOCK_GS4_Pos    (4U)                                                                                  /*!< LOCK_GS4 Postion   4          */ 
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS4_Msk    (0x1U << MEM_CFG_REGS_GSXLOCK_LOCK_GS4_Pos)                                           /*!< LOCK_GS4 Mask      0x00000010 */
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS4_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXLOCK_LOCK_GS4_Pos) & MEM_CFG_REGS_GSXLOCK_LOCK_GS4_Msk) /*!< LOCK_GS4 Set Value            */
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS4_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXLOCK_LOCK_GS4_Msk) >> MEM_CFG_REGS_GSXLOCK_LOCK_GS4_Pos) /*!< LOCK_GS4 Get Value            */


#define MEM_CFG_REGS_GSXLOCK_LOCK_GS3_Pos    (3U)                                                                                  /*!< LOCK_GS3 Postion   3          */ 
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS3_Msk    (0x1U << MEM_CFG_REGS_GSXLOCK_LOCK_GS3_Pos)                                           /*!< LOCK_GS3 Mask      0x00000008 */
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS3_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXLOCK_LOCK_GS3_Pos) & MEM_CFG_REGS_GSXLOCK_LOCK_GS3_Msk) /*!< LOCK_GS3 Set Value            */
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS3_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXLOCK_LOCK_GS3_Msk) >> MEM_CFG_REGS_GSXLOCK_LOCK_GS3_Pos) /*!< LOCK_GS3 Get Value            */


#define MEM_CFG_REGS_GSXLOCK_LOCK_GS2_Pos    (2U)                                                                                  /*!< LOCK_GS2 Postion   2          */ 
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS2_Msk    (0x1U << MEM_CFG_REGS_GSXLOCK_LOCK_GS2_Pos)                                           /*!< LOCK_GS2 Mask      0x00000004 */
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS2_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXLOCK_LOCK_GS2_Pos) & MEM_CFG_REGS_GSXLOCK_LOCK_GS2_Msk) /*!< LOCK_GS2 Set Value            */
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS2_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXLOCK_LOCK_GS2_Msk) >> MEM_CFG_REGS_GSXLOCK_LOCK_GS2_Pos) /*!< LOCK_GS2 Get Value            */


#define MEM_CFG_REGS_GSXLOCK_LOCK_GS1_Pos    (1U)                                                                                  /*!< LOCK_GS1 Postion   1          */ 
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS1_Msk    (0x1U << MEM_CFG_REGS_GSXLOCK_LOCK_GS1_Pos)                                           /*!< LOCK_GS1 Mask      0x00000002 */
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS1_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXLOCK_LOCK_GS1_Pos) & MEM_CFG_REGS_GSXLOCK_LOCK_GS1_Msk) /*!< LOCK_GS1 Set Value            */
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS1_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXLOCK_LOCK_GS1_Msk) >> MEM_CFG_REGS_GSXLOCK_LOCK_GS1_Pos) /*!< LOCK_GS1 Get Value            */


#define MEM_CFG_REGS_GSXLOCK_LOCK_GS0_Pos    (0U)                                                                                  /*!< LOCK_GS0 Postion   0          */ 
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS0_Msk    (0x1U << MEM_CFG_REGS_GSXLOCK_LOCK_GS0_Pos)                                           /*!< LOCK_GS0 Mask      0x00000001 */
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS0_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXLOCK_LOCK_GS0_Pos) & MEM_CFG_REGS_GSXLOCK_LOCK_GS0_Msk) /*!< LOCK_GS0 Set Value            */
#define MEM_CFG_REGS_GSXLOCK_LOCK_GS0_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXLOCK_LOCK_GS0_Msk) >> MEM_CFG_REGS_GSXLOCK_LOCK_GS0_Pos) /*!< LOCK_GS0 Get Value            */


/* GSXCOMMIT bitfield */
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS15_Pos    (15U)                                                                                 /*!< COMMIT_GS15 Postion   15         */ 
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS15_Msk    (0x1U << MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS15_Pos)                                      /*!< COMMIT_GS15 Mask      0x00008000 */
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS15_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS15_Pos) & MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS15_Msk) /*!< COMMIT_GS15 Set Value            */
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS15_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS15_Msk) >> MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS15_Pos) /*!< COMMIT_GS15 Get Value            */


#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS14_Pos    (14U)                                                                                 /*!< COMMIT_GS14 Postion   14         */ 
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS14_Msk    (0x1U << MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS14_Pos)                                      /*!< COMMIT_GS14 Mask      0x00004000 */
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS14_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS14_Pos) & MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS14_Msk) /*!< COMMIT_GS14 Set Value            */
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS14_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS14_Msk) >> MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS14_Pos) /*!< COMMIT_GS14 Get Value            */


#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS13_Pos    (13U)                                                                                 /*!< COMMIT_GS13 Postion   13         */ 
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS13_Msk    (0x1U << MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS13_Pos)                                      /*!< COMMIT_GS13 Mask      0x00002000 */
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS13_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS13_Pos) & MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS13_Msk) /*!< COMMIT_GS13 Set Value            */
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS13_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS13_Msk) >> MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS13_Pos) /*!< COMMIT_GS13 Get Value            */


#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS12_Pos    (12U)                                                                                 /*!< COMMIT_GS12 Postion   12         */ 
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS12_Msk    (0x1U << MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS12_Pos)                                      /*!< COMMIT_GS12 Mask      0x00001000 */
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS12_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS12_Pos) & MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS12_Msk) /*!< COMMIT_GS12 Set Value            */
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS12_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS12_Msk) >> MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS12_Pos) /*!< COMMIT_GS12 Get Value            */


#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS11_Pos    (11U)                                                                                 /*!< COMMIT_GS11 Postion   11         */ 
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS11_Msk    (0x1U << MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS11_Pos)                                      /*!< COMMIT_GS11 Mask      0x00000800 */
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS11_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS11_Pos) & MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS11_Msk) /*!< COMMIT_GS11 Set Value            */
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS11_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS11_Msk) >> MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS11_Pos) /*!< COMMIT_GS11 Get Value            */


#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS10_Pos    (10U)                                                                                 /*!< COMMIT_GS10 Postion   10         */ 
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS10_Msk    (0x1U << MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS10_Pos)                                      /*!< COMMIT_GS10 Mask      0x00000400 */
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS10_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS10_Pos) & MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS10_Msk) /*!< COMMIT_GS10 Set Value            */
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS10_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS10_Msk) >> MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS10_Pos) /*!< COMMIT_GS10 Get Value            */


#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS9_Pos    (9U)                                                                                  /*!< COMMIT_GS9 Postion   9          */ 
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS9_Msk    (0x1U << MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS9_Pos)                                       /*!< COMMIT_GS9 Mask      0x00000200 */
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS9_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS9_Pos) & MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS9_Msk) /*!< COMMIT_GS9 Set Value            */
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS9_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS9_Msk) >> MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS9_Pos) /*!< COMMIT_GS9 Get Value            */


#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS8_Pos    (8U)                                                                                  /*!< COMMIT_GS8 Postion   8          */ 
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS8_Msk    (0x1U << MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS8_Pos)                                       /*!< COMMIT_GS8 Mask      0x00000100 */
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS8_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS8_Pos) & MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS8_Msk) /*!< COMMIT_GS8 Set Value            */
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS8_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS8_Msk) >> MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS8_Pos) /*!< COMMIT_GS8 Get Value            */


#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS7_Pos    (7U)                                                                                  /*!< COMMIT_GS7 Postion   7          */ 
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS7_Msk    (0x1U << MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS7_Pos)                                       /*!< COMMIT_GS7 Mask      0x00000080 */
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS7_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS7_Pos) & MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS7_Msk) /*!< COMMIT_GS7 Set Value            */
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS7_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS7_Msk) >> MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS7_Pos) /*!< COMMIT_GS7 Get Value            */


#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS6_Pos    (6U)                                                                                  /*!< COMMIT_GS6 Postion   6          */ 
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS6_Msk    (0x1U << MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS6_Pos)                                       /*!< COMMIT_GS6 Mask      0x00000040 */
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS6_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS6_Pos) & MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS6_Msk) /*!< COMMIT_GS6 Set Value            */
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS6_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS6_Msk) >> MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS6_Pos) /*!< COMMIT_GS6 Get Value            */


#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS5_Pos    (5U)                                                                                  /*!< COMMIT_GS5 Postion   5          */ 
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS5_Msk    (0x1U << MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS5_Pos)                                       /*!< COMMIT_GS5 Mask      0x00000020 */
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS5_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS5_Pos) & MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS5_Msk) /*!< COMMIT_GS5 Set Value            */
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS5_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS5_Msk) >> MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS5_Pos) /*!< COMMIT_GS5 Get Value            */


#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS4_Pos    (4U)                                                                                  /*!< COMMIT_GS4 Postion   4          */ 
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS4_Msk    (0x1U << MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS4_Pos)                                       /*!< COMMIT_GS4 Mask      0x00000010 */
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS4_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS4_Pos) & MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS4_Msk) /*!< COMMIT_GS4 Set Value            */
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS4_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS4_Msk) >> MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS4_Pos) /*!< COMMIT_GS4 Get Value            */


#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS3_Pos    (3U)                                                                                  /*!< COMMIT_GS3 Postion   3          */ 
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS3_Msk    (0x1U << MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS3_Pos)                                       /*!< COMMIT_GS3 Mask      0x00000008 */
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS3_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS3_Pos) & MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS3_Msk) /*!< COMMIT_GS3 Set Value            */
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS3_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS3_Msk) >> MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS3_Pos) /*!< COMMIT_GS3 Get Value            */


#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS2_Pos    (2U)                                                                                  /*!< COMMIT_GS2 Postion   2          */ 
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS2_Msk    (0x1U << MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS2_Pos)                                       /*!< COMMIT_GS2 Mask      0x00000004 */
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS2_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS2_Pos) & MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS2_Msk) /*!< COMMIT_GS2 Set Value            */
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS2_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS2_Msk) >> MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS2_Pos) /*!< COMMIT_GS2 Get Value            */


#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS1_Pos    (1U)                                                                                  /*!< COMMIT_GS1 Postion   1          */ 
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS1_Msk    (0x1U << MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS1_Pos)                                       /*!< COMMIT_GS1 Mask      0x00000002 */
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS1_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS1_Pos) & MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS1_Msk) /*!< COMMIT_GS1 Set Value            */
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS1_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS1_Msk) >> MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS1_Pos) /*!< COMMIT_GS1 Get Value            */


#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS0_Pos    (0U)                                                                                  /*!< COMMIT_GS0 Postion   0          */ 
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS0_Msk    (0x1U << MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS0_Pos)                                       /*!< COMMIT_GS0 Mask      0x00000001 */
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS0_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS0_Pos) & MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS0_Msk) /*!< COMMIT_GS0 Set Value            */
#define MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS0_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS0_Msk) >> MEM_CFG_REGS_GSXCOMMIT_COMMIT_GS0_Pos) /*!< COMMIT_GS0 Get Value            */


/* GSXMSEL bitfield */
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS15_Pos    (30U)                                                                                 /*!< MSEL_GS15 Postion   30         */ 
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS15_Msk    (0x3U << MEM_CFG_REGS_GSXMSEL_MSEL_GS15_Pos)                                          /*!< MSEL_GS15 Mask      0xC0000000 */
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS15_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXMSEL_MSEL_GS15_Pos) & MEM_CFG_REGS_GSXMSEL_MSEL_GS15_Msk) /*!< MSEL_GS15 Set Value            */
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS15_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXMSEL_MSEL_GS15_Msk) >> MEM_CFG_REGS_GSXMSEL_MSEL_GS15_Pos) /*!< MSEL_GS15 Get Value            */


#define MEM_CFG_REGS_GSXMSEL_MSEL_GS14_Pos    (28U)                                                                                 /*!< MSEL_GS14 Postion   28         */ 
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS14_Msk    (0x3U << MEM_CFG_REGS_GSXMSEL_MSEL_GS14_Pos)                                          /*!< MSEL_GS14 Mask      0x30000000 */
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS14_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXMSEL_MSEL_GS14_Pos) & MEM_CFG_REGS_GSXMSEL_MSEL_GS14_Msk) /*!< MSEL_GS14 Set Value            */
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS14_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXMSEL_MSEL_GS14_Msk) >> MEM_CFG_REGS_GSXMSEL_MSEL_GS14_Pos) /*!< MSEL_GS14 Get Value            */


#define MEM_CFG_REGS_GSXMSEL_MSEL_GS13_Pos    (26U)                                                                                 /*!< MSEL_GS13 Postion   26         */ 
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS13_Msk    (0x3U << MEM_CFG_REGS_GSXMSEL_MSEL_GS13_Pos)                                          /*!< MSEL_GS13 Mask      0x0C000000 */
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS13_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXMSEL_MSEL_GS13_Pos) & MEM_CFG_REGS_GSXMSEL_MSEL_GS13_Msk) /*!< MSEL_GS13 Set Value            */
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS13_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXMSEL_MSEL_GS13_Msk) >> MEM_CFG_REGS_GSXMSEL_MSEL_GS13_Pos) /*!< MSEL_GS13 Get Value            */


#define MEM_CFG_REGS_GSXMSEL_MSEL_GS12_Pos    (24U)                                                                                 /*!< MSEL_GS12 Postion   24         */ 
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS12_Msk    (0x3U << MEM_CFG_REGS_GSXMSEL_MSEL_GS12_Pos)                                          /*!< MSEL_GS12 Mask      0x03000000 */
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS12_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXMSEL_MSEL_GS12_Pos) & MEM_CFG_REGS_GSXMSEL_MSEL_GS12_Msk) /*!< MSEL_GS12 Set Value            */
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS12_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXMSEL_MSEL_GS12_Msk) >> MEM_CFG_REGS_GSXMSEL_MSEL_GS12_Pos) /*!< MSEL_GS12 Get Value            */


#define MEM_CFG_REGS_GSXMSEL_MSEL_GS11_Pos    (22U)                                                                                 /*!< MSEL_GS11 Postion   22         */ 
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS11_Msk    (0x3U << MEM_CFG_REGS_GSXMSEL_MSEL_GS11_Pos)                                          /*!< MSEL_GS11 Mask      0x00C00000 */
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS11_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXMSEL_MSEL_GS11_Pos) & MEM_CFG_REGS_GSXMSEL_MSEL_GS11_Msk) /*!< MSEL_GS11 Set Value            */
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS11_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXMSEL_MSEL_GS11_Msk) >> MEM_CFG_REGS_GSXMSEL_MSEL_GS11_Pos) /*!< MSEL_GS11 Get Value            */


#define MEM_CFG_REGS_GSXMSEL_MSEL_GS10_Pos    (20U)                                                                                 /*!< MSEL_GS10 Postion   20         */ 
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS10_Msk    (0x3U << MEM_CFG_REGS_GSXMSEL_MSEL_GS10_Pos)                                          /*!< MSEL_GS10 Mask      0x00300000 */
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS10_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXMSEL_MSEL_GS10_Pos) & MEM_CFG_REGS_GSXMSEL_MSEL_GS10_Msk) /*!< MSEL_GS10 Set Value            */
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS10_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXMSEL_MSEL_GS10_Msk) >> MEM_CFG_REGS_GSXMSEL_MSEL_GS10_Pos) /*!< MSEL_GS10 Get Value            */


#define MEM_CFG_REGS_GSXMSEL_MSEL_GS9_Pos    (18U)                                                                                 /*!< MSEL_GS9 Postion   18         */ 
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS9_Msk    (0x3U << MEM_CFG_REGS_GSXMSEL_MSEL_GS9_Pos)                                           /*!< MSEL_GS9 Mask      0x000C0000 */
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS9_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXMSEL_MSEL_GS9_Pos) & MEM_CFG_REGS_GSXMSEL_MSEL_GS9_Msk) /*!< MSEL_GS9 Set Value            */
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS9_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXMSEL_MSEL_GS9_Msk) >> MEM_CFG_REGS_GSXMSEL_MSEL_GS9_Pos) /*!< MSEL_GS9 Get Value            */


#define MEM_CFG_REGS_GSXMSEL_MSEL_GS8_Pos    (16U)                                                                                 /*!< MSEL_GS8 Postion   16         */ 
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS8_Msk    (0x3U << MEM_CFG_REGS_GSXMSEL_MSEL_GS8_Pos)                                           /*!< MSEL_GS8 Mask      0x00030000 */
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS8_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXMSEL_MSEL_GS8_Pos) & MEM_CFG_REGS_GSXMSEL_MSEL_GS8_Msk) /*!< MSEL_GS8 Set Value            */
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS8_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXMSEL_MSEL_GS8_Msk) >> MEM_CFG_REGS_GSXMSEL_MSEL_GS8_Pos) /*!< MSEL_GS8 Get Value            */


#define MEM_CFG_REGS_GSXMSEL_MSEL_GS7_Pos    (14U)                                                                                 /*!< MSEL_GS7 Postion   14         */ 
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS7_Msk    (0x3U << MEM_CFG_REGS_GSXMSEL_MSEL_GS7_Pos)                                           /*!< MSEL_GS7 Mask      0x0000C000 */
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS7_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXMSEL_MSEL_GS7_Pos) & MEM_CFG_REGS_GSXMSEL_MSEL_GS7_Msk) /*!< MSEL_GS7 Set Value            */
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS7_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXMSEL_MSEL_GS7_Msk) >> MEM_CFG_REGS_GSXMSEL_MSEL_GS7_Pos) /*!< MSEL_GS7 Get Value            */


#define MEM_CFG_REGS_GSXMSEL_MSEL_GS6_Pos    (12U)                                                                                 /*!< MSEL_GS6 Postion   12         */ 
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS6_Msk    (0x3U << MEM_CFG_REGS_GSXMSEL_MSEL_GS6_Pos)                                           /*!< MSEL_GS6 Mask      0x00003000 */
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS6_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXMSEL_MSEL_GS6_Pos) & MEM_CFG_REGS_GSXMSEL_MSEL_GS6_Msk) /*!< MSEL_GS6 Set Value            */
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS6_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXMSEL_MSEL_GS6_Msk) >> MEM_CFG_REGS_GSXMSEL_MSEL_GS6_Pos) /*!< MSEL_GS6 Get Value            */


#define MEM_CFG_REGS_GSXMSEL_MSEL_GS5_Pos    (10U)                                                                                 /*!< MSEL_GS5 Postion   10         */ 
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS5_Msk    (0x3U << MEM_CFG_REGS_GSXMSEL_MSEL_GS5_Pos)                                           /*!< MSEL_GS5 Mask      0x00000C00 */
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS5_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXMSEL_MSEL_GS5_Pos) & MEM_CFG_REGS_GSXMSEL_MSEL_GS5_Msk) /*!< MSEL_GS5 Set Value            */
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS5_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXMSEL_MSEL_GS5_Msk) >> MEM_CFG_REGS_GSXMSEL_MSEL_GS5_Pos) /*!< MSEL_GS5 Get Value            */


#define MEM_CFG_REGS_GSXMSEL_MSEL_GS4_Pos    (8U)                                                                                  /*!< MSEL_GS4 Postion   8          */ 
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS4_Msk    (0x3U << MEM_CFG_REGS_GSXMSEL_MSEL_GS4_Pos)                                           /*!< MSEL_GS4 Mask      0x00000300 */
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS4_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXMSEL_MSEL_GS4_Pos) & MEM_CFG_REGS_GSXMSEL_MSEL_GS4_Msk) /*!< MSEL_GS4 Set Value            */
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS4_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXMSEL_MSEL_GS4_Msk) >> MEM_CFG_REGS_GSXMSEL_MSEL_GS4_Pos) /*!< MSEL_GS4 Get Value            */


#define MEM_CFG_REGS_GSXMSEL_MSEL_GS3_Pos    (6U)                                                                                  /*!< MSEL_GS3 Postion   6          */ 
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS3_Msk    (0x3U << MEM_CFG_REGS_GSXMSEL_MSEL_GS3_Pos)                                           /*!< MSEL_GS3 Mask      0x000000C0 */
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS3_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXMSEL_MSEL_GS3_Pos) & MEM_CFG_REGS_GSXMSEL_MSEL_GS3_Msk) /*!< MSEL_GS3 Set Value            */
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS3_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXMSEL_MSEL_GS3_Msk) >> MEM_CFG_REGS_GSXMSEL_MSEL_GS3_Pos) /*!< MSEL_GS3 Get Value            */


#define MEM_CFG_REGS_GSXMSEL_MSEL_GS2_Pos    (4U)                                                                                  /*!< MSEL_GS2 Postion   4          */ 
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS2_Msk    (0x3U << MEM_CFG_REGS_GSXMSEL_MSEL_GS2_Pos)                                           /*!< MSEL_GS2 Mask      0x00000030 */
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS2_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXMSEL_MSEL_GS2_Pos) & MEM_CFG_REGS_GSXMSEL_MSEL_GS2_Msk) /*!< MSEL_GS2 Set Value            */
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS2_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXMSEL_MSEL_GS2_Msk) >> MEM_CFG_REGS_GSXMSEL_MSEL_GS2_Pos) /*!< MSEL_GS2 Get Value            */


#define MEM_CFG_REGS_GSXMSEL_MSEL_GS1_Pos    (2U)                                                                                  /*!< MSEL_GS1 Postion   2          */ 
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS1_Msk    (0x3U << MEM_CFG_REGS_GSXMSEL_MSEL_GS1_Pos)                                           /*!< MSEL_GS1 Mask      0x0000000C */
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS1_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXMSEL_MSEL_GS1_Pos) & MEM_CFG_REGS_GSXMSEL_MSEL_GS1_Msk) /*!< MSEL_GS1 Set Value            */
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS1_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXMSEL_MSEL_GS1_Msk) >> MEM_CFG_REGS_GSXMSEL_MSEL_GS1_Pos) /*!< MSEL_GS1 Get Value            */


#define MEM_CFG_REGS_GSXMSEL_MSEL_GS0_Pos    (0U)                                                                                  /*!< MSEL_GS0 Postion   0          */ 
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS0_Msk    (0x3U << MEM_CFG_REGS_GSXMSEL_MSEL_GS0_Pos)                                           /*!< MSEL_GS0 Mask      0x00000003 */
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS0_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXMSEL_MSEL_GS0_Pos) & MEM_CFG_REGS_GSXMSEL_MSEL_GS0_Msk) /*!< MSEL_GS0 Set Value            */
#define MEM_CFG_REGS_GSXMSEL_MSEL_GS0_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXMSEL_MSEL_GS0_Msk) >> MEM_CFG_REGS_GSXMSEL_MSEL_GS0_Pos) /*!< MSEL_GS0 Get Value            */


/* GSXACCPROT0 bitfield */
#define MEM_CFG_REGS_GSXACCPROT0_DMAWRPROT_GS3_Pos    (26U)                                                                                 /*!< DMAWRPROT_GS3 Postion   26         */ 
#define MEM_CFG_REGS_GSXACCPROT0_DMAWRPROT_GS3_Msk    (0x1U << MEM_CFG_REGS_GSXACCPROT0_DMAWRPROT_GS3_Pos)                                  /*!< DMAWRPROT_GS3 Mask      0x04000000 */
#define MEM_CFG_REGS_GSXACCPROT0_DMAWRPROT_GS3_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXACCPROT0_DMAWRPROT_GS3_Pos) & MEM_CFG_REGS_GSXACCPROT0_DMAWRPROT_GS3_Msk) /*!< DMAWRPROT_GS3 Set Value            */
#define MEM_CFG_REGS_GSXACCPROT0_DMAWRPROT_GS3_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXACCPROT0_DMAWRPROT_GS3_Msk) >> MEM_CFG_REGS_GSXACCPROT0_DMAWRPROT_GS3_Pos) /*!< DMAWRPROT_GS3 Get Value            */


#define MEM_CFG_REGS_GSXACCPROT0_CPUWRPROT_GS3_Pos    (25U)                                                                                 /*!< CPUWRPROT_GS3 Postion   25         */ 
#define MEM_CFG_REGS_GSXACCPROT0_CPUWRPROT_GS3_Msk    (0x1U << MEM_CFG_REGS_GSXACCPROT0_CPUWRPROT_GS3_Pos)                                  /*!< CPUWRPROT_GS3 Mask      0x02000000 */
#define MEM_CFG_REGS_GSXACCPROT0_CPUWRPROT_GS3_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXACCPROT0_CPUWRPROT_GS3_Pos) & MEM_CFG_REGS_GSXACCPROT0_CPUWRPROT_GS3_Msk) /*!< CPUWRPROT_GS3 Set Value            */
#define MEM_CFG_REGS_GSXACCPROT0_CPUWRPROT_GS3_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXACCPROT0_CPUWRPROT_GS3_Msk) >> MEM_CFG_REGS_GSXACCPROT0_CPUWRPROT_GS3_Pos) /*!< CPUWRPROT_GS3 Get Value            */


#define MEM_CFG_REGS_GSXACCPROT0_DMAWRPROT_GS2_Pos    (18U)                                                                                 /*!< DMAWRPROT_GS2 Postion   18         */ 
#define MEM_CFG_REGS_GSXACCPROT0_DMAWRPROT_GS2_Msk    (0x1U << MEM_CFG_REGS_GSXACCPROT0_DMAWRPROT_GS2_Pos)                                  /*!< DMAWRPROT_GS2 Mask      0x00040000 */
#define MEM_CFG_REGS_GSXACCPROT0_DMAWRPROT_GS2_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXACCPROT0_DMAWRPROT_GS2_Pos) & MEM_CFG_REGS_GSXACCPROT0_DMAWRPROT_GS2_Msk) /*!< DMAWRPROT_GS2 Set Value            */
#define MEM_CFG_REGS_GSXACCPROT0_DMAWRPROT_GS2_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXACCPROT0_DMAWRPROT_GS2_Msk) >> MEM_CFG_REGS_GSXACCPROT0_DMAWRPROT_GS2_Pos) /*!< DMAWRPROT_GS2 Get Value            */


#define MEM_CFG_REGS_GSXACCPROT0_CPUWRPROT_GS2_Pos    (17U)                                                                                 /*!< CPUWRPROT_GS2 Postion   17         */ 
#define MEM_CFG_REGS_GSXACCPROT0_CPUWRPROT_GS2_Msk    (0x1U << MEM_CFG_REGS_GSXACCPROT0_CPUWRPROT_GS2_Pos)                                  /*!< CPUWRPROT_GS2 Mask      0x00020000 */
#define MEM_CFG_REGS_GSXACCPROT0_CPUWRPROT_GS2_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXACCPROT0_CPUWRPROT_GS2_Pos) & MEM_CFG_REGS_GSXACCPROT0_CPUWRPROT_GS2_Msk) /*!< CPUWRPROT_GS2 Set Value            */
#define MEM_CFG_REGS_GSXACCPROT0_CPUWRPROT_GS2_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXACCPROT0_CPUWRPROT_GS2_Msk) >> MEM_CFG_REGS_GSXACCPROT0_CPUWRPROT_GS2_Pos) /*!< CPUWRPROT_GS2 Get Value            */


#define MEM_CFG_REGS_GSXACCPROT0_DMAWRPROT_GS1_Pos    (10U)                                                                                 /*!< DMAWRPROT_GS1 Postion   10         */ 
#define MEM_CFG_REGS_GSXACCPROT0_DMAWRPROT_GS1_Msk    (0x1U << MEM_CFG_REGS_GSXACCPROT0_DMAWRPROT_GS1_Pos)                                  /*!< DMAWRPROT_GS1 Mask      0x00000400 */
#define MEM_CFG_REGS_GSXACCPROT0_DMAWRPROT_GS1_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXACCPROT0_DMAWRPROT_GS1_Pos) & MEM_CFG_REGS_GSXACCPROT0_DMAWRPROT_GS1_Msk) /*!< DMAWRPROT_GS1 Set Value            */
#define MEM_CFG_REGS_GSXACCPROT0_DMAWRPROT_GS1_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXACCPROT0_DMAWRPROT_GS1_Msk) >> MEM_CFG_REGS_GSXACCPROT0_DMAWRPROT_GS1_Pos) /*!< DMAWRPROT_GS1 Get Value            */


#define MEM_CFG_REGS_GSXACCPROT0_CPUWRPROT_GS1_Pos    (9U)                                                                                  /*!< CPUWRPROT_GS1 Postion   9          */ 
#define MEM_CFG_REGS_GSXACCPROT0_CPUWRPROT_GS1_Msk    (0x1U << MEM_CFG_REGS_GSXACCPROT0_CPUWRPROT_GS1_Pos)                                  /*!< CPUWRPROT_GS1 Mask      0x00000200 */
#define MEM_CFG_REGS_GSXACCPROT0_CPUWRPROT_GS1_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXACCPROT0_CPUWRPROT_GS1_Pos) & MEM_CFG_REGS_GSXACCPROT0_CPUWRPROT_GS1_Msk) /*!< CPUWRPROT_GS1 Set Value            */
#define MEM_CFG_REGS_GSXACCPROT0_CPUWRPROT_GS1_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXACCPROT0_CPUWRPROT_GS1_Msk) >> MEM_CFG_REGS_GSXACCPROT0_CPUWRPROT_GS1_Pos) /*!< CPUWRPROT_GS1 Get Value            */


#define MEM_CFG_REGS_GSXACCPROT0_DMAWRPROT_GS0_Pos    (2U)                                                                                  /*!< DMAWRPROT_GS0 Postion   2          */ 
#define MEM_CFG_REGS_GSXACCPROT0_DMAWRPROT_GS0_Msk    (0x1U << MEM_CFG_REGS_GSXACCPROT0_DMAWRPROT_GS0_Pos)                                  /*!< DMAWRPROT_GS0 Mask      0x00000004 */
#define MEM_CFG_REGS_GSXACCPROT0_DMAWRPROT_GS0_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXACCPROT0_DMAWRPROT_GS0_Pos) & MEM_CFG_REGS_GSXACCPROT0_DMAWRPROT_GS0_Msk) /*!< DMAWRPROT_GS0 Set Value            */
#define MEM_CFG_REGS_GSXACCPROT0_DMAWRPROT_GS0_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXACCPROT0_DMAWRPROT_GS0_Msk) >> MEM_CFG_REGS_GSXACCPROT0_DMAWRPROT_GS0_Pos) /*!< DMAWRPROT_GS0 Get Value            */


#define MEM_CFG_REGS_GSXACCPROT0_CPUWRPROT_GS0_Pos    (1U)                                                                                  /*!< CPUWRPROT_GS0 Postion   1          */ 
#define MEM_CFG_REGS_GSXACCPROT0_CPUWRPROT_GS0_Msk    (0x1U << MEM_CFG_REGS_GSXACCPROT0_CPUWRPROT_GS0_Pos)                                  /*!< CPUWRPROT_GS0 Mask      0x00000002 */
#define MEM_CFG_REGS_GSXACCPROT0_CPUWRPROT_GS0_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXACCPROT0_CPUWRPROT_GS0_Pos) & MEM_CFG_REGS_GSXACCPROT0_CPUWRPROT_GS0_Msk) /*!< CPUWRPROT_GS0 Set Value            */
#define MEM_CFG_REGS_GSXACCPROT0_CPUWRPROT_GS0_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXACCPROT0_CPUWRPROT_GS0_Msk) >> MEM_CFG_REGS_GSXACCPROT0_CPUWRPROT_GS0_Pos) /*!< CPUWRPROT_GS0 Get Value            */


/* GSXACCPROT1 bitfield */
#define MEM_CFG_REGS_GSXACCPROT1_DMAWRPROT_GS7_Pos    (26U)                                                                                 /*!< DMAWRPROT_GS7 Postion   26         */ 
#define MEM_CFG_REGS_GSXACCPROT1_DMAWRPROT_GS7_Msk    (0x1U << MEM_CFG_REGS_GSXACCPROT1_DMAWRPROT_GS7_Pos)                                  /*!< DMAWRPROT_GS7 Mask      0x04000000 */
#define MEM_CFG_REGS_GSXACCPROT1_DMAWRPROT_GS7_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXACCPROT1_DMAWRPROT_GS7_Pos) & MEM_CFG_REGS_GSXACCPROT1_DMAWRPROT_GS7_Msk) /*!< DMAWRPROT_GS7 Set Value            */
#define MEM_CFG_REGS_GSXACCPROT1_DMAWRPROT_GS7_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXACCPROT1_DMAWRPROT_GS7_Msk) >> MEM_CFG_REGS_GSXACCPROT1_DMAWRPROT_GS7_Pos) /*!< DMAWRPROT_GS7 Get Value            */


#define MEM_CFG_REGS_GSXACCPROT1_CPUWRPROT_GS7_Pos    (25U)                                                                                 /*!< CPUWRPROT_GS7 Postion   25         */ 
#define MEM_CFG_REGS_GSXACCPROT1_CPUWRPROT_GS7_Msk    (0x1U << MEM_CFG_REGS_GSXACCPROT1_CPUWRPROT_GS7_Pos)                                  /*!< CPUWRPROT_GS7 Mask      0x02000000 */
#define MEM_CFG_REGS_GSXACCPROT1_CPUWRPROT_GS7_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXACCPROT1_CPUWRPROT_GS7_Pos) & MEM_CFG_REGS_GSXACCPROT1_CPUWRPROT_GS7_Msk) /*!< CPUWRPROT_GS7 Set Value            */
#define MEM_CFG_REGS_GSXACCPROT1_CPUWRPROT_GS7_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXACCPROT1_CPUWRPROT_GS7_Msk) >> MEM_CFG_REGS_GSXACCPROT1_CPUWRPROT_GS7_Pos) /*!< CPUWRPROT_GS7 Get Value            */


#define MEM_CFG_REGS_GSXACCPROT1_DMAWRPROT_GS6_Pos    (18U)                                                                                 /*!< DMAWRPROT_GS6 Postion   18         */ 
#define MEM_CFG_REGS_GSXACCPROT1_DMAWRPROT_GS6_Msk    (0x1U << MEM_CFG_REGS_GSXACCPROT1_DMAWRPROT_GS6_Pos)                                  /*!< DMAWRPROT_GS6 Mask      0x00040000 */
#define MEM_CFG_REGS_GSXACCPROT1_DMAWRPROT_GS6_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXACCPROT1_DMAWRPROT_GS6_Pos) & MEM_CFG_REGS_GSXACCPROT1_DMAWRPROT_GS6_Msk) /*!< DMAWRPROT_GS6 Set Value            */
#define MEM_CFG_REGS_GSXACCPROT1_DMAWRPROT_GS6_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXACCPROT1_DMAWRPROT_GS6_Msk) >> MEM_CFG_REGS_GSXACCPROT1_DMAWRPROT_GS6_Pos) /*!< DMAWRPROT_GS6 Get Value            */


#define MEM_CFG_REGS_GSXACCPROT1_CPUWRPROT_GS6_Pos    (17U)                                                                                 /*!< CPUWRPROT_GS6 Postion   17         */ 
#define MEM_CFG_REGS_GSXACCPROT1_CPUWRPROT_GS6_Msk    (0x1U << MEM_CFG_REGS_GSXACCPROT1_CPUWRPROT_GS6_Pos)                                  /*!< CPUWRPROT_GS6 Mask      0x00020000 */
#define MEM_CFG_REGS_GSXACCPROT1_CPUWRPROT_GS6_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXACCPROT1_CPUWRPROT_GS6_Pos) & MEM_CFG_REGS_GSXACCPROT1_CPUWRPROT_GS6_Msk) /*!< CPUWRPROT_GS6 Set Value            */
#define MEM_CFG_REGS_GSXACCPROT1_CPUWRPROT_GS6_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXACCPROT1_CPUWRPROT_GS6_Msk) >> MEM_CFG_REGS_GSXACCPROT1_CPUWRPROT_GS6_Pos) /*!< CPUWRPROT_GS6 Get Value            */


#define MEM_CFG_REGS_GSXACCPROT1_DMAWRPROT_GS5_Pos    (10U)                                                                                 /*!< DMAWRPROT_GS5 Postion   10         */ 
#define MEM_CFG_REGS_GSXACCPROT1_DMAWRPROT_GS5_Msk    (0x1U << MEM_CFG_REGS_GSXACCPROT1_DMAWRPROT_GS5_Pos)                                  /*!< DMAWRPROT_GS5 Mask      0x00000400 */
#define MEM_CFG_REGS_GSXACCPROT1_DMAWRPROT_GS5_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXACCPROT1_DMAWRPROT_GS5_Pos) & MEM_CFG_REGS_GSXACCPROT1_DMAWRPROT_GS5_Msk) /*!< DMAWRPROT_GS5 Set Value            */
#define MEM_CFG_REGS_GSXACCPROT1_DMAWRPROT_GS5_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXACCPROT1_DMAWRPROT_GS5_Msk) >> MEM_CFG_REGS_GSXACCPROT1_DMAWRPROT_GS5_Pos) /*!< DMAWRPROT_GS5 Get Value            */


#define MEM_CFG_REGS_GSXACCPROT1_CPUWRPROT_GS5_Pos    (9U)                                                                                  /*!< CPUWRPROT_GS5 Postion   9          */ 
#define MEM_CFG_REGS_GSXACCPROT1_CPUWRPROT_GS5_Msk    (0x1U << MEM_CFG_REGS_GSXACCPROT1_CPUWRPROT_GS5_Pos)                                  /*!< CPUWRPROT_GS5 Mask      0x00000200 */
#define MEM_CFG_REGS_GSXACCPROT1_CPUWRPROT_GS5_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXACCPROT1_CPUWRPROT_GS5_Pos) & MEM_CFG_REGS_GSXACCPROT1_CPUWRPROT_GS5_Msk) /*!< CPUWRPROT_GS5 Set Value            */
#define MEM_CFG_REGS_GSXACCPROT1_CPUWRPROT_GS5_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXACCPROT1_CPUWRPROT_GS5_Msk) >> MEM_CFG_REGS_GSXACCPROT1_CPUWRPROT_GS5_Pos) /*!< CPUWRPROT_GS5 Get Value            */


#define MEM_CFG_REGS_GSXACCPROT1_DMAWRPROT_GS4_Pos    (2U)                                                                                  /*!< DMAWRPROT_GS4 Postion   2          */ 
#define MEM_CFG_REGS_GSXACCPROT1_DMAWRPROT_GS4_Msk    (0x1U << MEM_CFG_REGS_GSXACCPROT1_DMAWRPROT_GS4_Pos)                                  /*!< DMAWRPROT_GS4 Mask      0x00000004 */
#define MEM_CFG_REGS_GSXACCPROT1_DMAWRPROT_GS4_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXACCPROT1_DMAWRPROT_GS4_Pos) & MEM_CFG_REGS_GSXACCPROT1_DMAWRPROT_GS4_Msk) /*!< DMAWRPROT_GS4 Set Value            */
#define MEM_CFG_REGS_GSXACCPROT1_DMAWRPROT_GS4_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXACCPROT1_DMAWRPROT_GS4_Msk) >> MEM_CFG_REGS_GSXACCPROT1_DMAWRPROT_GS4_Pos) /*!< DMAWRPROT_GS4 Get Value            */


#define MEM_CFG_REGS_GSXACCPROT1_CPUWRPROT_GS4_Pos    (1U)                                                                                  /*!< CPUWRPROT_GS4 Postion   1          */ 
#define MEM_CFG_REGS_GSXACCPROT1_CPUWRPROT_GS4_Msk    (0x1U << MEM_CFG_REGS_GSXACCPROT1_CPUWRPROT_GS4_Pos)                                  /*!< CPUWRPROT_GS4 Mask      0x00000002 */
#define MEM_CFG_REGS_GSXACCPROT1_CPUWRPROT_GS4_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXACCPROT1_CPUWRPROT_GS4_Pos) & MEM_CFG_REGS_GSXACCPROT1_CPUWRPROT_GS4_Msk) /*!< CPUWRPROT_GS4 Set Value            */
#define MEM_CFG_REGS_GSXACCPROT1_CPUWRPROT_GS4_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXACCPROT1_CPUWRPROT_GS4_Msk) >> MEM_CFG_REGS_GSXACCPROT1_CPUWRPROT_GS4_Pos) /*!< CPUWRPROT_GS4 Get Value            */


/* GSXACCPROT2 bitfield */
#define MEM_CFG_REGS_GSXACCPROT2_DMAWRPROT_GS11_Pos    (26U)                                                                                 /*!< DMAWRPROT_GS11 Postion   26         */ 
#define MEM_CFG_REGS_GSXACCPROT2_DMAWRPROT_GS11_Msk    (0x1U << MEM_CFG_REGS_GSXACCPROT2_DMAWRPROT_GS11_Pos)                                 /*!< DMAWRPROT_GS11 Mask      0x04000000 */
#define MEM_CFG_REGS_GSXACCPROT2_DMAWRPROT_GS11_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXACCPROT2_DMAWRPROT_GS11_Pos) & MEM_CFG_REGS_GSXACCPROT2_DMAWRPROT_GS11_Msk) /*!< DMAWRPROT_GS11 Set Value            */
#define MEM_CFG_REGS_GSXACCPROT2_DMAWRPROT_GS11_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXACCPROT2_DMAWRPROT_GS11_Msk) >> MEM_CFG_REGS_GSXACCPROT2_DMAWRPROT_GS11_Pos) /*!< DMAWRPROT_GS11 Get Value            */


#define MEM_CFG_REGS_GSXACCPROT2_CPUWRPROT_GS11_Pos    (25U)                                                                                 /*!< CPUWRPROT_GS11 Postion   25         */ 
#define MEM_CFG_REGS_GSXACCPROT2_CPUWRPROT_GS11_Msk    (0x1U << MEM_CFG_REGS_GSXACCPROT2_CPUWRPROT_GS11_Pos)                                 /*!< CPUWRPROT_GS11 Mask      0x02000000 */
#define MEM_CFG_REGS_GSXACCPROT2_CPUWRPROT_GS11_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXACCPROT2_CPUWRPROT_GS11_Pos) & MEM_CFG_REGS_GSXACCPROT2_CPUWRPROT_GS11_Msk) /*!< CPUWRPROT_GS11 Set Value            */
#define MEM_CFG_REGS_GSXACCPROT2_CPUWRPROT_GS11_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXACCPROT2_CPUWRPROT_GS11_Msk) >> MEM_CFG_REGS_GSXACCPROT2_CPUWRPROT_GS11_Pos) /*!< CPUWRPROT_GS11 Get Value            */


#define MEM_CFG_REGS_GSXACCPROT2_DMAWRPROT_GS10_Pos    (18U)                                                                                 /*!< DMAWRPROT_GS10 Postion   18         */ 
#define MEM_CFG_REGS_GSXACCPROT2_DMAWRPROT_GS10_Msk    (0x1U << MEM_CFG_REGS_GSXACCPROT2_DMAWRPROT_GS10_Pos)                                 /*!< DMAWRPROT_GS10 Mask      0x00040000 */
#define MEM_CFG_REGS_GSXACCPROT2_DMAWRPROT_GS10_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXACCPROT2_DMAWRPROT_GS10_Pos) & MEM_CFG_REGS_GSXACCPROT2_DMAWRPROT_GS10_Msk) /*!< DMAWRPROT_GS10 Set Value            */
#define MEM_CFG_REGS_GSXACCPROT2_DMAWRPROT_GS10_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXACCPROT2_DMAWRPROT_GS10_Msk) >> MEM_CFG_REGS_GSXACCPROT2_DMAWRPROT_GS10_Pos) /*!< DMAWRPROT_GS10 Get Value            */


#define MEM_CFG_REGS_GSXACCPROT2_CPUWRPROT_GS10_Pos    (17U)                                                                                 /*!< CPUWRPROT_GS10 Postion   17         */ 
#define MEM_CFG_REGS_GSXACCPROT2_CPUWRPROT_GS10_Msk    (0x1U << MEM_CFG_REGS_GSXACCPROT2_CPUWRPROT_GS10_Pos)                                 /*!< CPUWRPROT_GS10 Mask      0x00020000 */
#define MEM_CFG_REGS_GSXACCPROT2_CPUWRPROT_GS10_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXACCPROT2_CPUWRPROT_GS10_Pos) & MEM_CFG_REGS_GSXACCPROT2_CPUWRPROT_GS10_Msk) /*!< CPUWRPROT_GS10 Set Value            */
#define MEM_CFG_REGS_GSXACCPROT2_CPUWRPROT_GS10_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXACCPROT2_CPUWRPROT_GS10_Msk) >> MEM_CFG_REGS_GSXACCPROT2_CPUWRPROT_GS10_Pos) /*!< CPUWRPROT_GS10 Get Value            */


#define MEM_CFG_REGS_GSXACCPROT2_DMAWRPROT_GS9_Pos    (10U)                                                                                 /*!< DMAWRPROT_GS9 Postion   10         */ 
#define MEM_CFG_REGS_GSXACCPROT2_DMAWRPROT_GS9_Msk    (0x1U << MEM_CFG_REGS_GSXACCPROT2_DMAWRPROT_GS9_Pos)                                  /*!< DMAWRPROT_GS9 Mask      0x00000400 */
#define MEM_CFG_REGS_GSXACCPROT2_DMAWRPROT_GS9_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXACCPROT2_DMAWRPROT_GS9_Pos) & MEM_CFG_REGS_GSXACCPROT2_DMAWRPROT_GS9_Msk) /*!< DMAWRPROT_GS9 Set Value            */
#define MEM_CFG_REGS_GSXACCPROT2_DMAWRPROT_GS9_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXACCPROT2_DMAWRPROT_GS9_Msk) >> MEM_CFG_REGS_GSXACCPROT2_DMAWRPROT_GS9_Pos) /*!< DMAWRPROT_GS9 Get Value            */


#define MEM_CFG_REGS_GSXACCPROT2_CPUWRPROT_GS9_Pos    (9U)                                                                                  /*!< CPUWRPROT_GS9 Postion   9          */ 
#define MEM_CFG_REGS_GSXACCPROT2_CPUWRPROT_GS9_Msk    (0x1U << MEM_CFG_REGS_GSXACCPROT2_CPUWRPROT_GS9_Pos)                                  /*!< CPUWRPROT_GS9 Mask      0x00000200 */
#define MEM_CFG_REGS_GSXACCPROT2_CPUWRPROT_GS9_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXACCPROT2_CPUWRPROT_GS9_Pos) & MEM_CFG_REGS_GSXACCPROT2_CPUWRPROT_GS9_Msk) /*!< CPUWRPROT_GS9 Set Value            */
#define MEM_CFG_REGS_GSXACCPROT2_CPUWRPROT_GS9_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXACCPROT2_CPUWRPROT_GS9_Msk) >> MEM_CFG_REGS_GSXACCPROT2_CPUWRPROT_GS9_Pos) /*!< CPUWRPROT_GS9 Get Value            */


#define MEM_CFG_REGS_GSXACCPROT2_DMAWRPROT_GS8_Pos    (2U)                                                                                  /*!< DMAWRPROT_GS8 Postion   2          */ 
#define MEM_CFG_REGS_GSXACCPROT2_DMAWRPROT_GS8_Msk    (0x1U << MEM_CFG_REGS_GSXACCPROT2_DMAWRPROT_GS8_Pos)                                  /*!< DMAWRPROT_GS8 Mask      0x00000004 */
#define MEM_CFG_REGS_GSXACCPROT2_DMAWRPROT_GS8_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXACCPROT2_DMAWRPROT_GS8_Pos) & MEM_CFG_REGS_GSXACCPROT2_DMAWRPROT_GS8_Msk) /*!< DMAWRPROT_GS8 Set Value            */
#define MEM_CFG_REGS_GSXACCPROT2_DMAWRPROT_GS8_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXACCPROT2_DMAWRPROT_GS8_Msk) >> MEM_CFG_REGS_GSXACCPROT2_DMAWRPROT_GS8_Pos) /*!< DMAWRPROT_GS8 Get Value            */


#define MEM_CFG_REGS_GSXACCPROT2_CPUWRPROT_GS8_Pos    (1U)                                                                                  /*!< CPUWRPROT_GS8 Postion   1          */ 
#define MEM_CFG_REGS_GSXACCPROT2_CPUWRPROT_GS8_Msk    (0x1U << MEM_CFG_REGS_GSXACCPROT2_CPUWRPROT_GS8_Pos)                                  /*!< CPUWRPROT_GS8 Mask      0x00000002 */
#define MEM_CFG_REGS_GSXACCPROT2_CPUWRPROT_GS8_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXACCPROT2_CPUWRPROT_GS8_Pos) & MEM_CFG_REGS_GSXACCPROT2_CPUWRPROT_GS8_Msk) /*!< CPUWRPROT_GS8 Set Value            */
#define MEM_CFG_REGS_GSXACCPROT2_CPUWRPROT_GS8_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXACCPROT2_CPUWRPROT_GS8_Msk) >> MEM_CFG_REGS_GSXACCPROT2_CPUWRPROT_GS8_Pos) /*!< CPUWRPROT_GS8 Get Value            */


/* GSXACCPROT3 bitfield */
#define MEM_CFG_REGS_GSXACCPROT3_DMAWRPROT_GS15_Pos    (26U)                                                                                 /*!< DMAWRPROT_GS15 Postion   26         */ 
#define MEM_CFG_REGS_GSXACCPROT3_DMAWRPROT_GS15_Msk    (0x1U << MEM_CFG_REGS_GSXACCPROT3_DMAWRPROT_GS15_Pos)                                 /*!< DMAWRPROT_GS15 Mask      0x04000000 */
#define MEM_CFG_REGS_GSXACCPROT3_DMAWRPROT_GS15_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXACCPROT3_DMAWRPROT_GS15_Pos) & MEM_CFG_REGS_GSXACCPROT3_DMAWRPROT_GS15_Msk) /*!< DMAWRPROT_GS15 Set Value            */
#define MEM_CFG_REGS_GSXACCPROT3_DMAWRPROT_GS15_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXACCPROT3_DMAWRPROT_GS15_Msk) >> MEM_CFG_REGS_GSXACCPROT3_DMAWRPROT_GS15_Pos) /*!< DMAWRPROT_GS15 Get Value            */


#define MEM_CFG_REGS_GSXACCPROT3_CPUWRPROT_GS15_Pos    (25U)                                                                                 /*!< CPUWRPROT_GS15 Postion   25         */ 
#define MEM_CFG_REGS_GSXACCPROT3_CPUWRPROT_GS15_Msk    (0x1U << MEM_CFG_REGS_GSXACCPROT3_CPUWRPROT_GS15_Pos)                                 /*!< CPUWRPROT_GS15 Mask      0x02000000 */
#define MEM_CFG_REGS_GSXACCPROT3_CPUWRPROT_GS15_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXACCPROT3_CPUWRPROT_GS15_Pos) & MEM_CFG_REGS_GSXACCPROT3_CPUWRPROT_GS15_Msk) /*!< CPUWRPROT_GS15 Set Value            */
#define MEM_CFG_REGS_GSXACCPROT3_CPUWRPROT_GS15_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXACCPROT3_CPUWRPROT_GS15_Msk) >> MEM_CFG_REGS_GSXACCPROT3_CPUWRPROT_GS15_Pos) /*!< CPUWRPROT_GS15 Get Value            */


#define MEM_CFG_REGS_GSXACCPROT3_DMAWRPROT_GS14_Pos    (18U)                                                                                 /*!< DMAWRPROT_GS14 Postion   18         */ 
#define MEM_CFG_REGS_GSXACCPROT3_DMAWRPROT_GS14_Msk    (0x1U << MEM_CFG_REGS_GSXACCPROT3_DMAWRPROT_GS14_Pos)                                 /*!< DMAWRPROT_GS14 Mask      0x00040000 */
#define MEM_CFG_REGS_GSXACCPROT3_DMAWRPROT_GS14_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXACCPROT3_DMAWRPROT_GS14_Pos) & MEM_CFG_REGS_GSXACCPROT3_DMAWRPROT_GS14_Msk) /*!< DMAWRPROT_GS14 Set Value            */
#define MEM_CFG_REGS_GSXACCPROT3_DMAWRPROT_GS14_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXACCPROT3_DMAWRPROT_GS14_Msk) >> MEM_CFG_REGS_GSXACCPROT3_DMAWRPROT_GS14_Pos) /*!< DMAWRPROT_GS14 Get Value            */


#define MEM_CFG_REGS_GSXACCPROT3_CPUWRPROT_GS14_Pos    (17U)                                                                                 /*!< CPUWRPROT_GS14 Postion   17         */ 
#define MEM_CFG_REGS_GSXACCPROT3_CPUWRPROT_GS14_Msk    (0x1U << MEM_CFG_REGS_GSXACCPROT3_CPUWRPROT_GS14_Pos)                                 /*!< CPUWRPROT_GS14 Mask      0x00020000 */
#define MEM_CFG_REGS_GSXACCPROT3_CPUWRPROT_GS14_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXACCPROT3_CPUWRPROT_GS14_Pos) & MEM_CFG_REGS_GSXACCPROT3_CPUWRPROT_GS14_Msk) /*!< CPUWRPROT_GS14 Set Value            */
#define MEM_CFG_REGS_GSXACCPROT3_CPUWRPROT_GS14_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXACCPROT3_CPUWRPROT_GS14_Msk) >> MEM_CFG_REGS_GSXACCPROT3_CPUWRPROT_GS14_Pos) /*!< CPUWRPROT_GS14 Get Value            */


#define MEM_CFG_REGS_GSXACCPROT3_DMAWRPROT_GS13_Pos    (10U)                                                                                 /*!< DMAWRPROT_GS13 Postion   10         */ 
#define MEM_CFG_REGS_GSXACCPROT3_DMAWRPROT_GS13_Msk    (0x1U << MEM_CFG_REGS_GSXACCPROT3_DMAWRPROT_GS13_Pos)                                 /*!< DMAWRPROT_GS13 Mask      0x00000400 */
#define MEM_CFG_REGS_GSXACCPROT3_DMAWRPROT_GS13_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXACCPROT3_DMAWRPROT_GS13_Pos) & MEM_CFG_REGS_GSXACCPROT3_DMAWRPROT_GS13_Msk) /*!< DMAWRPROT_GS13 Set Value            */
#define MEM_CFG_REGS_GSXACCPROT3_DMAWRPROT_GS13_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXACCPROT3_DMAWRPROT_GS13_Msk) >> MEM_CFG_REGS_GSXACCPROT3_DMAWRPROT_GS13_Pos) /*!< DMAWRPROT_GS13 Get Value            */


#define MEM_CFG_REGS_GSXACCPROT3_CPUWRPROT_GS13_Pos    (9U)                                                                                  /*!< CPUWRPROT_GS13 Postion   9          */ 
#define MEM_CFG_REGS_GSXACCPROT3_CPUWRPROT_GS13_Msk    (0x1U << MEM_CFG_REGS_GSXACCPROT3_CPUWRPROT_GS13_Pos)                                 /*!< CPUWRPROT_GS13 Mask      0x00000200 */
#define MEM_CFG_REGS_GSXACCPROT3_CPUWRPROT_GS13_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXACCPROT3_CPUWRPROT_GS13_Pos) & MEM_CFG_REGS_GSXACCPROT3_CPUWRPROT_GS13_Msk) /*!< CPUWRPROT_GS13 Set Value            */
#define MEM_CFG_REGS_GSXACCPROT3_CPUWRPROT_GS13_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXACCPROT3_CPUWRPROT_GS13_Msk) >> MEM_CFG_REGS_GSXACCPROT3_CPUWRPROT_GS13_Pos) /*!< CPUWRPROT_GS13 Get Value            */


#define MEM_CFG_REGS_GSXACCPROT3_DMAWRPROT_GS12_Pos    (2U)                                                                                  /*!< DMAWRPROT_GS12 Postion   2          */ 
#define MEM_CFG_REGS_GSXACCPROT3_DMAWRPROT_GS12_Msk    (0x1U << MEM_CFG_REGS_GSXACCPROT3_DMAWRPROT_GS12_Pos)                                 /*!< DMAWRPROT_GS12 Mask      0x00000004 */
#define MEM_CFG_REGS_GSXACCPROT3_DMAWRPROT_GS12_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXACCPROT3_DMAWRPROT_GS12_Pos) & MEM_CFG_REGS_GSXACCPROT3_DMAWRPROT_GS12_Msk) /*!< DMAWRPROT_GS12 Set Value            */
#define MEM_CFG_REGS_GSXACCPROT3_DMAWRPROT_GS12_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXACCPROT3_DMAWRPROT_GS12_Msk) >> MEM_CFG_REGS_GSXACCPROT3_DMAWRPROT_GS12_Pos) /*!< DMAWRPROT_GS12 Get Value            */


#define MEM_CFG_REGS_GSXACCPROT3_CPUWRPROT_GS12_Pos    (1U)                                                                                  /*!< CPUWRPROT_GS12 Postion   1          */ 
#define MEM_CFG_REGS_GSXACCPROT3_CPUWRPROT_GS12_Msk    (0x1U << MEM_CFG_REGS_GSXACCPROT3_CPUWRPROT_GS12_Pos)                                 /*!< CPUWRPROT_GS12 Mask      0x00000002 */
#define MEM_CFG_REGS_GSXACCPROT3_CPUWRPROT_GS12_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXACCPROT3_CPUWRPROT_GS12_Pos) & MEM_CFG_REGS_GSXACCPROT3_CPUWRPROT_GS12_Msk) /*!< CPUWRPROT_GS12 Set Value            */
#define MEM_CFG_REGS_GSXACCPROT3_CPUWRPROT_GS12_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXACCPROT3_CPUWRPROT_GS12_Msk) >> MEM_CFG_REGS_GSXACCPROT3_CPUWRPROT_GS12_Pos) /*!< CPUWRPROT_GS12 Get Value            */


/* GSXTEST bitfield */
#define MEM_CFG_REGS_GSXTEST_TEST_GS15_Pos    (30U)                                                                                 /*!< TEST_GS15 Postion   30         */ 
#define MEM_CFG_REGS_GSXTEST_TEST_GS15_Msk    (0x3U << MEM_CFG_REGS_GSXTEST_TEST_GS15_Pos)                                          /*!< TEST_GS15 Mask      0xC0000000 */
#define MEM_CFG_REGS_GSXTEST_TEST_GS15_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXTEST_TEST_GS15_Pos) & MEM_CFG_REGS_GSXTEST_TEST_GS15_Msk) /*!< TEST_GS15 Set Value            */
#define MEM_CFG_REGS_GSXTEST_TEST_GS15_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXTEST_TEST_GS15_Msk) >> MEM_CFG_REGS_GSXTEST_TEST_GS15_Pos) /*!< TEST_GS15 Get Value            */


#define MEM_CFG_REGS_GSXTEST_TEST_GS14_Pos    (28U)                                                                                 /*!< TEST_GS14 Postion   28         */ 
#define MEM_CFG_REGS_GSXTEST_TEST_GS14_Msk    (0x3U << MEM_CFG_REGS_GSXTEST_TEST_GS14_Pos)                                          /*!< TEST_GS14 Mask      0x30000000 */
#define MEM_CFG_REGS_GSXTEST_TEST_GS14_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXTEST_TEST_GS14_Pos) & MEM_CFG_REGS_GSXTEST_TEST_GS14_Msk) /*!< TEST_GS14 Set Value            */
#define MEM_CFG_REGS_GSXTEST_TEST_GS14_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXTEST_TEST_GS14_Msk) >> MEM_CFG_REGS_GSXTEST_TEST_GS14_Pos) /*!< TEST_GS14 Get Value            */


#define MEM_CFG_REGS_GSXTEST_TEST_GS13_Pos    (26U)                                                                                 /*!< TEST_GS13 Postion   26         */ 
#define MEM_CFG_REGS_GSXTEST_TEST_GS13_Msk    (0x3U << MEM_CFG_REGS_GSXTEST_TEST_GS13_Pos)                                          /*!< TEST_GS13 Mask      0x0C000000 */
#define MEM_CFG_REGS_GSXTEST_TEST_GS13_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXTEST_TEST_GS13_Pos) & MEM_CFG_REGS_GSXTEST_TEST_GS13_Msk) /*!< TEST_GS13 Set Value            */
#define MEM_CFG_REGS_GSXTEST_TEST_GS13_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXTEST_TEST_GS13_Msk) >> MEM_CFG_REGS_GSXTEST_TEST_GS13_Pos) /*!< TEST_GS13 Get Value            */


#define MEM_CFG_REGS_GSXTEST_TEST_GS12_Pos    (24U)                                                                                 /*!< TEST_GS12 Postion   24         */ 
#define MEM_CFG_REGS_GSXTEST_TEST_GS12_Msk    (0x3U << MEM_CFG_REGS_GSXTEST_TEST_GS12_Pos)                                          /*!< TEST_GS12 Mask      0x03000000 */
#define MEM_CFG_REGS_GSXTEST_TEST_GS12_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXTEST_TEST_GS12_Pos) & MEM_CFG_REGS_GSXTEST_TEST_GS12_Msk) /*!< TEST_GS12 Set Value            */
#define MEM_CFG_REGS_GSXTEST_TEST_GS12_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXTEST_TEST_GS12_Msk) >> MEM_CFG_REGS_GSXTEST_TEST_GS12_Pos) /*!< TEST_GS12 Get Value            */


#define MEM_CFG_REGS_GSXTEST_TEST_GS11_Pos    (22U)                                                                                 /*!< TEST_GS11 Postion   22         */ 
#define MEM_CFG_REGS_GSXTEST_TEST_GS11_Msk    (0x3U << MEM_CFG_REGS_GSXTEST_TEST_GS11_Pos)                                          /*!< TEST_GS11 Mask      0x00C00000 */
#define MEM_CFG_REGS_GSXTEST_TEST_GS11_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXTEST_TEST_GS11_Pos) & MEM_CFG_REGS_GSXTEST_TEST_GS11_Msk) /*!< TEST_GS11 Set Value            */
#define MEM_CFG_REGS_GSXTEST_TEST_GS11_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXTEST_TEST_GS11_Msk) >> MEM_CFG_REGS_GSXTEST_TEST_GS11_Pos) /*!< TEST_GS11 Get Value            */


#define MEM_CFG_REGS_GSXTEST_TEST_GS10_Pos    (20U)                                                                                 /*!< TEST_GS10 Postion   20         */ 
#define MEM_CFG_REGS_GSXTEST_TEST_GS10_Msk    (0x3U << MEM_CFG_REGS_GSXTEST_TEST_GS10_Pos)                                          /*!< TEST_GS10 Mask      0x00300000 */
#define MEM_CFG_REGS_GSXTEST_TEST_GS10_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXTEST_TEST_GS10_Pos) & MEM_CFG_REGS_GSXTEST_TEST_GS10_Msk) /*!< TEST_GS10 Set Value            */
#define MEM_CFG_REGS_GSXTEST_TEST_GS10_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXTEST_TEST_GS10_Msk) >> MEM_CFG_REGS_GSXTEST_TEST_GS10_Pos) /*!< TEST_GS10 Get Value            */


#define MEM_CFG_REGS_GSXTEST_TEST_GS9_Pos    (18U)                                                                                 /*!< TEST_GS9 Postion   18         */ 
#define MEM_CFG_REGS_GSXTEST_TEST_GS9_Msk    (0x3U << MEM_CFG_REGS_GSXTEST_TEST_GS9_Pos)                                           /*!< TEST_GS9 Mask      0x000C0000 */
#define MEM_CFG_REGS_GSXTEST_TEST_GS9_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXTEST_TEST_GS9_Pos) & MEM_CFG_REGS_GSXTEST_TEST_GS9_Msk) /*!< TEST_GS9 Set Value            */
#define MEM_CFG_REGS_GSXTEST_TEST_GS9_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXTEST_TEST_GS9_Msk) >> MEM_CFG_REGS_GSXTEST_TEST_GS9_Pos) /*!< TEST_GS9 Get Value            */


#define MEM_CFG_REGS_GSXTEST_TEST_GS8_Pos    (16U)                                                                                 /*!< TEST_GS8 Postion   16         */ 
#define MEM_CFG_REGS_GSXTEST_TEST_GS8_Msk    (0x3U << MEM_CFG_REGS_GSXTEST_TEST_GS8_Pos)                                           /*!< TEST_GS8 Mask      0x00030000 */
#define MEM_CFG_REGS_GSXTEST_TEST_GS8_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXTEST_TEST_GS8_Pos) & MEM_CFG_REGS_GSXTEST_TEST_GS8_Msk) /*!< TEST_GS8 Set Value            */
#define MEM_CFG_REGS_GSXTEST_TEST_GS8_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXTEST_TEST_GS8_Msk) >> MEM_CFG_REGS_GSXTEST_TEST_GS8_Pos) /*!< TEST_GS8 Get Value            */


#define MEM_CFG_REGS_GSXTEST_TEST_GS7_Pos    (14U)                                                                                 /*!< TEST_GS7 Postion   14         */ 
#define MEM_CFG_REGS_GSXTEST_TEST_GS7_Msk    (0x3U << MEM_CFG_REGS_GSXTEST_TEST_GS7_Pos)                                           /*!< TEST_GS7 Mask      0x0000C000 */
#define MEM_CFG_REGS_GSXTEST_TEST_GS7_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXTEST_TEST_GS7_Pos) & MEM_CFG_REGS_GSXTEST_TEST_GS7_Msk) /*!< TEST_GS7 Set Value            */
#define MEM_CFG_REGS_GSXTEST_TEST_GS7_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXTEST_TEST_GS7_Msk) >> MEM_CFG_REGS_GSXTEST_TEST_GS7_Pos) /*!< TEST_GS7 Get Value            */


#define MEM_CFG_REGS_GSXTEST_TEST_GS6_Pos    (12U)                                                                                 /*!< TEST_GS6 Postion   12         */ 
#define MEM_CFG_REGS_GSXTEST_TEST_GS6_Msk    (0x3U << MEM_CFG_REGS_GSXTEST_TEST_GS6_Pos)                                           /*!< TEST_GS6 Mask      0x00003000 */
#define MEM_CFG_REGS_GSXTEST_TEST_GS6_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXTEST_TEST_GS6_Pos) & MEM_CFG_REGS_GSXTEST_TEST_GS6_Msk) /*!< TEST_GS6 Set Value            */
#define MEM_CFG_REGS_GSXTEST_TEST_GS6_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXTEST_TEST_GS6_Msk) >> MEM_CFG_REGS_GSXTEST_TEST_GS6_Pos) /*!< TEST_GS6 Get Value            */


#define MEM_CFG_REGS_GSXTEST_TEST_GS5_Pos    (10U)                                                                                 /*!< TEST_GS5 Postion   10         */ 
#define MEM_CFG_REGS_GSXTEST_TEST_GS5_Msk    (0x3U << MEM_CFG_REGS_GSXTEST_TEST_GS5_Pos)                                           /*!< TEST_GS5 Mask      0x00000C00 */
#define MEM_CFG_REGS_GSXTEST_TEST_GS5_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXTEST_TEST_GS5_Pos) & MEM_CFG_REGS_GSXTEST_TEST_GS5_Msk) /*!< TEST_GS5 Set Value            */
#define MEM_CFG_REGS_GSXTEST_TEST_GS5_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXTEST_TEST_GS5_Msk) >> MEM_CFG_REGS_GSXTEST_TEST_GS5_Pos) /*!< TEST_GS5 Get Value            */


#define MEM_CFG_REGS_GSXTEST_TEST_GS4_Pos    (8U)                                                                                  /*!< TEST_GS4 Postion   8          */ 
#define MEM_CFG_REGS_GSXTEST_TEST_GS4_Msk    (0x3U << MEM_CFG_REGS_GSXTEST_TEST_GS4_Pos)                                           /*!< TEST_GS4 Mask      0x00000300 */
#define MEM_CFG_REGS_GSXTEST_TEST_GS4_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXTEST_TEST_GS4_Pos) & MEM_CFG_REGS_GSXTEST_TEST_GS4_Msk) /*!< TEST_GS4 Set Value            */
#define MEM_CFG_REGS_GSXTEST_TEST_GS4_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXTEST_TEST_GS4_Msk) >> MEM_CFG_REGS_GSXTEST_TEST_GS4_Pos) /*!< TEST_GS4 Get Value            */


#define MEM_CFG_REGS_GSXTEST_TEST_GS3_Pos    (6U)                                                                                  /*!< TEST_GS3 Postion   6          */ 
#define MEM_CFG_REGS_GSXTEST_TEST_GS3_Msk    (0x3U << MEM_CFG_REGS_GSXTEST_TEST_GS3_Pos)                                           /*!< TEST_GS3 Mask      0x000000C0 */
#define MEM_CFG_REGS_GSXTEST_TEST_GS3_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXTEST_TEST_GS3_Pos) & MEM_CFG_REGS_GSXTEST_TEST_GS3_Msk) /*!< TEST_GS3 Set Value            */
#define MEM_CFG_REGS_GSXTEST_TEST_GS3_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXTEST_TEST_GS3_Msk) >> MEM_CFG_REGS_GSXTEST_TEST_GS3_Pos) /*!< TEST_GS3 Get Value            */


#define MEM_CFG_REGS_GSXTEST_TEST_GS2_Pos    (4U)                                                                                  /*!< TEST_GS2 Postion   4          */ 
#define MEM_CFG_REGS_GSXTEST_TEST_GS2_Msk    (0x3U << MEM_CFG_REGS_GSXTEST_TEST_GS2_Pos)                                           /*!< TEST_GS2 Mask      0x00000030 */
#define MEM_CFG_REGS_GSXTEST_TEST_GS2_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXTEST_TEST_GS2_Pos) & MEM_CFG_REGS_GSXTEST_TEST_GS2_Msk) /*!< TEST_GS2 Set Value            */
#define MEM_CFG_REGS_GSXTEST_TEST_GS2_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXTEST_TEST_GS2_Msk) >> MEM_CFG_REGS_GSXTEST_TEST_GS2_Pos) /*!< TEST_GS2 Get Value            */


#define MEM_CFG_REGS_GSXTEST_TEST_GS1_Pos    (2U)                                                                                  /*!< TEST_GS1 Postion   2          */ 
#define MEM_CFG_REGS_GSXTEST_TEST_GS1_Msk    (0x3U << MEM_CFG_REGS_GSXTEST_TEST_GS1_Pos)                                           /*!< TEST_GS1 Mask      0x0000000C */
#define MEM_CFG_REGS_GSXTEST_TEST_GS1_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXTEST_TEST_GS1_Pos) & MEM_CFG_REGS_GSXTEST_TEST_GS1_Msk) /*!< TEST_GS1 Set Value            */
#define MEM_CFG_REGS_GSXTEST_TEST_GS1_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXTEST_TEST_GS1_Msk) >> MEM_CFG_REGS_GSXTEST_TEST_GS1_Pos) /*!< TEST_GS1 Get Value            */


#define MEM_CFG_REGS_GSXTEST_TEST_GS0_Pos    (0U)                                                                                  /*!< TEST_GS0 Postion   0          */ 
#define MEM_CFG_REGS_GSXTEST_TEST_GS0_Msk    (0x3U << MEM_CFG_REGS_GSXTEST_TEST_GS0_Pos)                                           /*!< TEST_GS0 Mask      0x00000003 */
#define MEM_CFG_REGS_GSXTEST_TEST_GS0_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXTEST_TEST_GS0_Pos) & MEM_CFG_REGS_GSXTEST_TEST_GS0_Msk) /*!< TEST_GS0 Set Value            */
#define MEM_CFG_REGS_GSXTEST_TEST_GS0_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXTEST_TEST_GS0_Msk) >> MEM_CFG_REGS_GSXTEST_TEST_GS0_Pos) /*!< TEST_GS0 Get Value            */


/* GSXINIT bitfield */
#define MEM_CFG_REGS_GSXINIT_INIT_GS15_Pos    (15U)                                                                                 /*!< INIT_GS15 Postion   15         */ 
#define MEM_CFG_REGS_GSXINIT_INIT_GS15_Msk    (0x1U << MEM_CFG_REGS_GSXINIT_INIT_GS15_Pos)                                          /*!< INIT_GS15 Mask      0x00008000 */
#define MEM_CFG_REGS_GSXINIT_INIT_GS15_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXINIT_INIT_GS15_Pos) & MEM_CFG_REGS_GSXINIT_INIT_GS15_Msk) /*!< INIT_GS15 Set Value            */
#define MEM_CFG_REGS_GSXINIT_INIT_GS15_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXINIT_INIT_GS15_Msk) >> MEM_CFG_REGS_GSXINIT_INIT_GS15_Pos) /*!< INIT_GS15 Get Value            */


#define MEM_CFG_REGS_GSXINIT_INIT_GS14_Pos    (14U)                                                                                 /*!< INIT_GS14 Postion   14         */ 
#define MEM_CFG_REGS_GSXINIT_INIT_GS14_Msk    (0x1U << MEM_CFG_REGS_GSXINIT_INIT_GS14_Pos)                                          /*!< INIT_GS14 Mask      0x00004000 */
#define MEM_CFG_REGS_GSXINIT_INIT_GS14_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXINIT_INIT_GS14_Pos) & MEM_CFG_REGS_GSXINIT_INIT_GS14_Msk) /*!< INIT_GS14 Set Value            */
#define MEM_CFG_REGS_GSXINIT_INIT_GS14_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXINIT_INIT_GS14_Msk) >> MEM_CFG_REGS_GSXINIT_INIT_GS14_Pos) /*!< INIT_GS14 Get Value            */


#define MEM_CFG_REGS_GSXINIT_INIT_GS13_Pos    (13U)                                                                                 /*!< INIT_GS13 Postion   13         */ 
#define MEM_CFG_REGS_GSXINIT_INIT_GS13_Msk    (0x1U << MEM_CFG_REGS_GSXINIT_INIT_GS13_Pos)                                          /*!< INIT_GS13 Mask      0x00002000 */
#define MEM_CFG_REGS_GSXINIT_INIT_GS13_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXINIT_INIT_GS13_Pos) & MEM_CFG_REGS_GSXINIT_INIT_GS13_Msk) /*!< INIT_GS13 Set Value            */
#define MEM_CFG_REGS_GSXINIT_INIT_GS13_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXINIT_INIT_GS13_Msk) >> MEM_CFG_REGS_GSXINIT_INIT_GS13_Pos) /*!< INIT_GS13 Get Value            */


#define MEM_CFG_REGS_GSXINIT_INIT_GS12_Pos    (12U)                                                                                 /*!< INIT_GS12 Postion   12         */ 
#define MEM_CFG_REGS_GSXINIT_INIT_GS12_Msk    (0x1U << MEM_CFG_REGS_GSXINIT_INIT_GS12_Pos)                                          /*!< INIT_GS12 Mask      0x00001000 */
#define MEM_CFG_REGS_GSXINIT_INIT_GS12_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXINIT_INIT_GS12_Pos) & MEM_CFG_REGS_GSXINIT_INIT_GS12_Msk) /*!< INIT_GS12 Set Value            */
#define MEM_CFG_REGS_GSXINIT_INIT_GS12_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXINIT_INIT_GS12_Msk) >> MEM_CFG_REGS_GSXINIT_INIT_GS12_Pos) /*!< INIT_GS12 Get Value            */


#define MEM_CFG_REGS_GSXINIT_INIT_GS11_Pos    (11U)                                                                                 /*!< INIT_GS11 Postion   11         */ 
#define MEM_CFG_REGS_GSXINIT_INIT_GS11_Msk    (0x1U << MEM_CFG_REGS_GSXINIT_INIT_GS11_Pos)                                          /*!< INIT_GS11 Mask      0x00000800 */
#define MEM_CFG_REGS_GSXINIT_INIT_GS11_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXINIT_INIT_GS11_Pos) & MEM_CFG_REGS_GSXINIT_INIT_GS11_Msk) /*!< INIT_GS11 Set Value            */
#define MEM_CFG_REGS_GSXINIT_INIT_GS11_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXINIT_INIT_GS11_Msk) >> MEM_CFG_REGS_GSXINIT_INIT_GS11_Pos) /*!< INIT_GS11 Get Value            */


#define MEM_CFG_REGS_GSXINIT_INIT_GS10_Pos    (10U)                                                                                 /*!< INIT_GS10 Postion   10         */ 
#define MEM_CFG_REGS_GSXINIT_INIT_GS10_Msk    (0x1U << MEM_CFG_REGS_GSXINIT_INIT_GS10_Pos)                                          /*!< INIT_GS10 Mask      0x00000400 */
#define MEM_CFG_REGS_GSXINIT_INIT_GS10_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXINIT_INIT_GS10_Pos) & MEM_CFG_REGS_GSXINIT_INIT_GS10_Msk) /*!< INIT_GS10 Set Value            */
#define MEM_CFG_REGS_GSXINIT_INIT_GS10_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXINIT_INIT_GS10_Msk) >> MEM_CFG_REGS_GSXINIT_INIT_GS10_Pos) /*!< INIT_GS10 Get Value            */


#define MEM_CFG_REGS_GSXINIT_INIT_GS9_Pos    (9U)                                                                                  /*!< INIT_GS9 Postion   9          */ 
#define MEM_CFG_REGS_GSXINIT_INIT_GS9_Msk    (0x1U << MEM_CFG_REGS_GSXINIT_INIT_GS9_Pos)                                           /*!< INIT_GS9 Mask      0x00000200 */
#define MEM_CFG_REGS_GSXINIT_INIT_GS9_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXINIT_INIT_GS9_Pos) & MEM_CFG_REGS_GSXINIT_INIT_GS9_Msk) /*!< INIT_GS9 Set Value            */
#define MEM_CFG_REGS_GSXINIT_INIT_GS9_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXINIT_INIT_GS9_Msk) >> MEM_CFG_REGS_GSXINIT_INIT_GS9_Pos) /*!< INIT_GS9 Get Value            */


#define MEM_CFG_REGS_GSXINIT_INIT_GS8_Pos    (8U)                                                                                  /*!< INIT_GS8 Postion   8          */ 
#define MEM_CFG_REGS_GSXINIT_INIT_GS8_Msk    (0x1U << MEM_CFG_REGS_GSXINIT_INIT_GS8_Pos)                                           /*!< INIT_GS8 Mask      0x00000100 */
#define MEM_CFG_REGS_GSXINIT_INIT_GS8_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXINIT_INIT_GS8_Pos) & MEM_CFG_REGS_GSXINIT_INIT_GS8_Msk) /*!< INIT_GS8 Set Value            */
#define MEM_CFG_REGS_GSXINIT_INIT_GS8_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXINIT_INIT_GS8_Msk) >> MEM_CFG_REGS_GSXINIT_INIT_GS8_Pos) /*!< INIT_GS8 Get Value            */


#define MEM_CFG_REGS_GSXINIT_INIT_GS7_Pos    (7U)                                                                                  /*!< INIT_GS7 Postion   7          */ 
#define MEM_CFG_REGS_GSXINIT_INIT_GS7_Msk    (0x1U << MEM_CFG_REGS_GSXINIT_INIT_GS7_Pos)                                           /*!< INIT_GS7 Mask      0x00000080 */
#define MEM_CFG_REGS_GSXINIT_INIT_GS7_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXINIT_INIT_GS7_Pos) & MEM_CFG_REGS_GSXINIT_INIT_GS7_Msk) /*!< INIT_GS7 Set Value            */
#define MEM_CFG_REGS_GSXINIT_INIT_GS7_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXINIT_INIT_GS7_Msk) >> MEM_CFG_REGS_GSXINIT_INIT_GS7_Pos) /*!< INIT_GS7 Get Value            */


#define MEM_CFG_REGS_GSXINIT_INIT_GS6_Pos    (6U)                                                                                  /*!< INIT_GS6 Postion   6          */ 
#define MEM_CFG_REGS_GSXINIT_INIT_GS6_Msk    (0x1U << MEM_CFG_REGS_GSXINIT_INIT_GS6_Pos)                                           /*!< INIT_GS6 Mask      0x00000040 */
#define MEM_CFG_REGS_GSXINIT_INIT_GS6_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXINIT_INIT_GS6_Pos) & MEM_CFG_REGS_GSXINIT_INIT_GS6_Msk) /*!< INIT_GS6 Set Value            */
#define MEM_CFG_REGS_GSXINIT_INIT_GS6_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXINIT_INIT_GS6_Msk) >> MEM_CFG_REGS_GSXINIT_INIT_GS6_Pos) /*!< INIT_GS6 Get Value            */


#define MEM_CFG_REGS_GSXINIT_INIT_GS5_Pos    (5U)                                                                                  /*!< INIT_GS5 Postion   5          */ 
#define MEM_CFG_REGS_GSXINIT_INIT_GS5_Msk    (0x1U << MEM_CFG_REGS_GSXINIT_INIT_GS5_Pos)                                           /*!< INIT_GS5 Mask      0x00000020 */
#define MEM_CFG_REGS_GSXINIT_INIT_GS5_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXINIT_INIT_GS5_Pos) & MEM_CFG_REGS_GSXINIT_INIT_GS5_Msk) /*!< INIT_GS5 Set Value            */
#define MEM_CFG_REGS_GSXINIT_INIT_GS5_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXINIT_INIT_GS5_Msk) >> MEM_CFG_REGS_GSXINIT_INIT_GS5_Pos) /*!< INIT_GS5 Get Value            */


#define MEM_CFG_REGS_GSXINIT_INIT_GS4_Pos    (4U)                                                                                  /*!< INIT_GS4 Postion   4          */ 
#define MEM_CFG_REGS_GSXINIT_INIT_GS4_Msk    (0x1U << MEM_CFG_REGS_GSXINIT_INIT_GS4_Pos)                                           /*!< INIT_GS4 Mask      0x00000010 */
#define MEM_CFG_REGS_GSXINIT_INIT_GS4_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXINIT_INIT_GS4_Pos) & MEM_CFG_REGS_GSXINIT_INIT_GS4_Msk) /*!< INIT_GS4 Set Value            */
#define MEM_CFG_REGS_GSXINIT_INIT_GS4_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXINIT_INIT_GS4_Msk) >> MEM_CFG_REGS_GSXINIT_INIT_GS4_Pos) /*!< INIT_GS4 Get Value            */


#define MEM_CFG_REGS_GSXINIT_INIT_GS3_Pos    (3U)                                                                                  /*!< INIT_GS3 Postion   3          */ 
#define MEM_CFG_REGS_GSXINIT_INIT_GS3_Msk    (0x1U << MEM_CFG_REGS_GSXINIT_INIT_GS3_Pos)                                           /*!< INIT_GS3 Mask      0x00000008 */
#define MEM_CFG_REGS_GSXINIT_INIT_GS3_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXINIT_INIT_GS3_Pos) & MEM_CFG_REGS_GSXINIT_INIT_GS3_Msk) /*!< INIT_GS3 Set Value            */
#define MEM_CFG_REGS_GSXINIT_INIT_GS3_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXINIT_INIT_GS3_Msk) >> MEM_CFG_REGS_GSXINIT_INIT_GS3_Pos) /*!< INIT_GS3 Get Value            */


#define MEM_CFG_REGS_GSXINIT_INIT_GS2_Pos    (2U)                                                                                  /*!< INIT_GS2 Postion   2          */ 
#define MEM_CFG_REGS_GSXINIT_INIT_GS2_Msk    (0x1U << MEM_CFG_REGS_GSXINIT_INIT_GS2_Pos)                                           /*!< INIT_GS2 Mask      0x00000004 */
#define MEM_CFG_REGS_GSXINIT_INIT_GS2_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXINIT_INIT_GS2_Pos) & MEM_CFG_REGS_GSXINIT_INIT_GS2_Msk) /*!< INIT_GS2 Set Value            */
#define MEM_CFG_REGS_GSXINIT_INIT_GS2_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXINIT_INIT_GS2_Msk) >> MEM_CFG_REGS_GSXINIT_INIT_GS2_Pos) /*!< INIT_GS2 Get Value            */


#define MEM_CFG_REGS_GSXINIT_INIT_GS1_Pos    (1U)                                                                                  /*!< INIT_GS1 Postion   1          */ 
#define MEM_CFG_REGS_GSXINIT_INIT_GS1_Msk    (0x1U << MEM_CFG_REGS_GSXINIT_INIT_GS1_Pos)                                           /*!< INIT_GS1 Mask      0x00000002 */
#define MEM_CFG_REGS_GSXINIT_INIT_GS1_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXINIT_INIT_GS1_Pos) & MEM_CFG_REGS_GSXINIT_INIT_GS1_Msk) /*!< INIT_GS1 Set Value            */
#define MEM_CFG_REGS_GSXINIT_INIT_GS1_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXINIT_INIT_GS1_Msk) >> MEM_CFG_REGS_GSXINIT_INIT_GS1_Pos) /*!< INIT_GS1 Get Value            */


#define MEM_CFG_REGS_GSXINIT_INIT_GS0_Pos    (0U)                                                                                  /*!< INIT_GS0 Postion   0          */ 
#define MEM_CFG_REGS_GSXINIT_INIT_GS0_Msk    (0x1U << MEM_CFG_REGS_GSXINIT_INIT_GS0_Pos)                                           /*!< INIT_GS0 Mask      0x00000001 */
#define MEM_CFG_REGS_GSXINIT_INIT_GS0_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXINIT_INIT_GS0_Pos) & MEM_CFG_REGS_GSXINIT_INIT_GS0_Msk) /*!< INIT_GS0 Set Value            */
#define MEM_CFG_REGS_GSXINIT_INIT_GS0_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXINIT_INIT_GS0_Msk) >> MEM_CFG_REGS_GSXINIT_INIT_GS0_Pos) /*!< INIT_GS0 Get Value            */


/* GSXINITDONE bitfield */
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS15_Pos    (15U)                                                                                 /*!< INITDONE_GS15 Postion   15         */ 
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS15_Msk    (0x1U << MEM_CFG_REGS_GSXINITDONE_INITDONE_GS15_Pos)                                  /*!< INITDONE_GS15 Mask      0x00008000 */
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS15_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXINITDONE_INITDONE_GS15_Pos) & MEM_CFG_REGS_GSXINITDONE_INITDONE_GS15_Msk) /*!< INITDONE_GS15 Set Value            */
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS15_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXINITDONE_INITDONE_GS15_Msk) >> MEM_CFG_REGS_GSXINITDONE_INITDONE_GS15_Pos) /*!< INITDONE_GS15 Get Value            */


#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS14_Pos    (14U)                                                                                 /*!< INITDONE_GS14 Postion   14         */ 
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS14_Msk    (0x1U << MEM_CFG_REGS_GSXINITDONE_INITDONE_GS14_Pos)                                  /*!< INITDONE_GS14 Mask      0x00004000 */
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS14_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXINITDONE_INITDONE_GS14_Pos) & MEM_CFG_REGS_GSXINITDONE_INITDONE_GS14_Msk) /*!< INITDONE_GS14 Set Value            */
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS14_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXINITDONE_INITDONE_GS14_Msk) >> MEM_CFG_REGS_GSXINITDONE_INITDONE_GS14_Pos) /*!< INITDONE_GS14 Get Value            */


#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS13_Pos    (13U)                                                                                 /*!< INITDONE_GS13 Postion   13         */ 
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS13_Msk    (0x1U << MEM_CFG_REGS_GSXINITDONE_INITDONE_GS13_Pos)                                  /*!< INITDONE_GS13 Mask      0x00002000 */
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS13_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXINITDONE_INITDONE_GS13_Pos) & MEM_CFG_REGS_GSXINITDONE_INITDONE_GS13_Msk) /*!< INITDONE_GS13 Set Value            */
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS13_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXINITDONE_INITDONE_GS13_Msk) >> MEM_CFG_REGS_GSXINITDONE_INITDONE_GS13_Pos) /*!< INITDONE_GS13 Get Value            */


#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS12_Pos    (12U)                                                                                 /*!< INITDONE_GS12 Postion   12         */ 
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS12_Msk    (0x1U << MEM_CFG_REGS_GSXINITDONE_INITDONE_GS12_Pos)                                  /*!< INITDONE_GS12 Mask      0x00001000 */
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS12_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXINITDONE_INITDONE_GS12_Pos) & MEM_CFG_REGS_GSXINITDONE_INITDONE_GS12_Msk) /*!< INITDONE_GS12 Set Value            */
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS12_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXINITDONE_INITDONE_GS12_Msk) >> MEM_CFG_REGS_GSXINITDONE_INITDONE_GS12_Pos) /*!< INITDONE_GS12 Get Value            */


#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS11_Pos    (11U)                                                                                 /*!< INITDONE_GS11 Postion   11         */ 
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS11_Msk    (0x1U << MEM_CFG_REGS_GSXINITDONE_INITDONE_GS11_Pos)                                  /*!< INITDONE_GS11 Mask      0x00000800 */
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS11_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXINITDONE_INITDONE_GS11_Pos) & MEM_CFG_REGS_GSXINITDONE_INITDONE_GS11_Msk) /*!< INITDONE_GS11 Set Value            */
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS11_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXINITDONE_INITDONE_GS11_Msk) >> MEM_CFG_REGS_GSXINITDONE_INITDONE_GS11_Pos) /*!< INITDONE_GS11 Get Value            */


#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS10_Pos    (10U)                                                                                 /*!< INITDONE_GS10 Postion   10         */ 
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS10_Msk    (0x1U << MEM_CFG_REGS_GSXINITDONE_INITDONE_GS10_Pos)                                  /*!< INITDONE_GS10 Mask      0x00000400 */
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS10_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXINITDONE_INITDONE_GS10_Pos) & MEM_CFG_REGS_GSXINITDONE_INITDONE_GS10_Msk) /*!< INITDONE_GS10 Set Value            */
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS10_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXINITDONE_INITDONE_GS10_Msk) >> MEM_CFG_REGS_GSXINITDONE_INITDONE_GS10_Pos) /*!< INITDONE_GS10 Get Value            */


#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS9_Pos    (9U)                                                                                  /*!< INITDONE_GS9 Postion   9          */ 
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS9_Msk    (0x1U << MEM_CFG_REGS_GSXINITDONE_INITDONE_GS9_Pos)                                   /*!< INITDONE_GS9 Mask      0x00000200 */
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS9_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXINITDONE_INITDONE_GS9_Pos) & MEM_CFG_REGS_GSXINITDONE_INITDONE_GS9_Msk) /*!< INITDONE_GS9 Set Value            */
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS9_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXINITDONE_INITDONE_GS9_Msk) >> MEM_CFG_REGS_GSXINITDONE_INITDONE_GS9_Pos) /*!< INITDONE_GS9 Get Value            */


#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS8_Pos    (8U)                                                                                  /*!< INITDONE_GS8 Postion   8          */ 
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS8_Msk    (0x1U << MEM_CFG_REGS_GSXINITDONE_INITDONE_GS8_Pos)                                   /*!< INITDONE_GS8 Mask      0x00000100 */
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS8_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXINITDONE_INITDONE_GS8_Pos) & MEM_CFG_REGS_GSXINITDONE_INITDONE_GS8_Msk) /*!< INITDONE_GS8 Set Value            */
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS8_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXINITDONE_INITDONE_GS8_Msk) >> MEM_CFG_REGS_GSXINITDONE_INITDONE_GS8_Pos) /*!< INITDONE_GS8 Get Value            */


#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS7_Pos    (7U)                                                                                  /*!< INITDONE_GS7 Postion   7          */ 
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS7_Msk    (0x1U << MEM_CFG_REGS_GSXINITDONE_INITDONE_GS7_Pos)                                   /*!< INITDONE_GS7 Mask      0x00000080 */
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS7_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXINITDONE_INITDONE_GS7_Pos) & MEM_CFG_REGS_GSXINITDONE_INITDONE_GS7_Msk) /*!< INITDONE_GS7 Set Value            */
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS7_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXINITDONE_INITDONE_GS7_Msk) >> MEM_CFG_REGS_GSXINITDONE_INITDONE_GS7_Pos) /*!< INITDONE_GS7 Get Value            */


#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS6_Pos    (6U)                                                                                  /*!< INITDONE_GS6 Postion   6          */ 
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS6_Msk    (0x1U << MEM_CFG_REGS_GSXINITDONE_INITDONE_GS6_Pos)                                   /*!< INITDONE_GS6 Mask      0x00000040 */
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS6_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXINITDONE_INITDONE_GS6_Pos) & MEM_CFG_REGS_GSXINITDONE_INITDONE_GS6_Msk) /*!< INITDONE_GS6 Set Value            */
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS6_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXINITDONE_INITDONE_GS6_Msk) >> MEM_CFG_REGS_GSXINITDONE_INITDONE_GS6_Pos) /*!< INITDONE_GS6 Get Value            */


#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS5_Pos    (5U)                                                                                  /*!< INITDONE_GS5 Postion   5          */ 
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS5_Msk    (0x1U << MEM_CFG_REGS_GSXINITDONE_INITDONE_GS5_Pos)                                   /*!< INITDONE_GS5 Mask      0x00000020 */
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS5_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXINITDONE_INITDONE_GS5_Pos) & MEM_CFG_REGS_GSXINITDONE_INITDONE_GS5_Msk) /*!< INITDONE_GS5 Set Value            */
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS5_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXINITDONE_INITDONE_GS5_Msk) >> MEM_CFG_REGS_GSXINITDONE_INITDONE_GS5_Pos) /*!< INITDONE_GS5 Get Value            */


#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS4_Pos    (4U)                                                                                  /*!< INITDONE_GS4 Postion   4          */ 
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS4_Msk    (0x1U << MEM_CFG_REGS_GSXINITDONE_INITDONE_GS4_Pos)                                   /*!< INITDONE_GS4 Mask      0x00000010 */
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS4_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXINITDONE_INITDONE_GS4_Pos) & MEM_CFG_REGS_GSXINITDONE_INITDONE_GS4_Msk) /*!< INITDONE_GS4 Set Value            */
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS4_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXINITDONE_INITDONE_GS4_Msk) >> MEM_CFG_REGS_GSXINITDONE_INITDONE_GS4_Pos) /*!< INITDONE_GS4 Get Value            */


#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS3_Pos    (3U)                                                                                  /*!< INITDONE_GS3 Postion   3          */ 
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS3_Msk    (0x1U << MEM_CFG_REGS_GSXINITDONE_INITDONE_GS3_Pos)                                   /*!< INITDONE_GS3 Mask      0x00000008 */
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS3_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXINITDONE_INITDONE_GS3_Pos) & MEM_CFG_REGS_GSXINITDONE_INITDONE_GS3_Msk) /*!< INITDONE_GS3 Set Value            */
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS3_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXINITDONE_INITDONE_GS3_Msk) >> MEM_CFG_REGS_GSXINITDONE_INITDONE_GS3_Pos) /*!< INITDONE_GS3 Get Value            */


#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS2_Pos    (2U)                                                                                  /*!< INITDONE_GS2 Postion   2          */ 
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS2_Msk    (0x1U << MEM_CFG_REGS_GSXINITDONE_INITDONE_GS2_Pos)                                   /*!< INITDONE_GS2 Mask      0x00000004 */
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS2_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXINITDONE_INITDONE_GS2_Pos) & MEM_CFG_REGS_GSXINITDONE_INITDONE_GS2_Msk) /*!< INITDONE_GS2 Set Value            */
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS2_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXINITDONE_INITDONE_GS2_Msk) >> MEM_CFG_REGS_GSXINITDONE_INITDONE_GS2_Pos) /*!< INITDONE_GS2 Get Value            */


#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS1_Pos    (1U)                                                                                  /*!< INITDONE_GS1 Postion   1          */ 
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS1_Msk    (0x1U << MEM_CFG_REGS_GSXINITDONE_INITDONE_GS1_Pos)                                   /*!< INITDONE_GS1 Mask      0x00000002 */
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS1_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXINITDONE_INITDONE_GS1_Pos) & MEM_CFG_REGS_GSXINITDONE_INITDONE_GS1_Msk) /*!< INITDONE_GS1 Set Value            */
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS1_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXINITDONE_INITDONE_GS1_Msk) >> MEM_CFG_REGS_GSXINITDONE_INITDONE_GS1_Pos) /*!< INITDONE_GS1 Get Value            */


#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS0_Pos    (0U)                                                                                  /*!< INITDONE_GS0 Postion   0          */ 
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS0_Msk    (0x1U << MEM_CFG_REGS_GSXINITDONE_INITDONE_GS0_Pos)                                   /*!< INITDONE_GS0 Mask      0x00000001 */
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS0_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSXINITDONE_INITDONE_GS0_Pos) & MEM_CFG_REGS_GSXINITDONE_INITDONE_GS0_Msk) /*!< INITDONE_GS0 Set Value            */
#define MEM_CFG_REGS_GSXINITDONE_INITDONE_GS0_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSXINITDONE_INITDONE_GS0_Msk) >> MEM_CFG_REGS_GSXINITDONE_INITDONE_GS0_Pos) /*!< INITDONE_GS0 Get Value            */


/* MSGXTEST bitfield */
#define MEM_CFG_REGS_MSGXTEST_TEST_CPUTOCPU_Pos    (0U)                                                                                  /*!< TEST_CPUTOCPU Postion   0          */ 
#define MEM_CFG_REGS_MSGXTEST_TEST_CPUTOCPU_Msk    (0x3U << MEM_CFG_REGS_MSGXTEST_TEST_CPUTOCPU_Pos)                                     /*!< TEST_CPUTOCPU Mask      0x00000003 */
#define MEM_CFG_REGS_MSGXTEST_TEST_CPUTOCPU_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_MSGXTEST_TEST_CPUTOCPU_Pos) & MEM_CFG_REGS_MSGXTEST_TEST_CPUTOCPU_Msk) /*!< TEST_CPUTOCPU Set Value            */
#define MEM_CFG_REGS_MSGXTEST_TEST_CPUTOCPU_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_MSGXTEST_TEST_CPUTOCPU_Msk) >> MEM_CFG_REGS_MSGXTEST_TEST_CPUTOCPU_Pos) /*!< TEST_CPUTOCPU Get Value            */


/* MSGXINIT bitfield */
#define MEM_CFG_REGS_MSGXINIT_INIT_CPUTOCPU_Pos    (0U)                                                                                  /*!< INIT_CPUTOCPU Postion   0          */ 
#define MEM_CFG_REGS_MSGXINIT_INIT_CPUTOCPU_Msk    (0x1U << MEM_CFG_REGS_MSGXINIT_INIT_CPUTOCPU_Pos)                                     /*!< INIT_CPUTOCPU Mask      0x00000001 */
#define MEM_CFG_REGS_MSGXINIT_INIT_CPUTOCPU_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_MSGXINIT_INIT_CPUTOCPU_Pos) & MEM_CFG_REGS_MSGXINIT_INIT_CPUTOCPU_Msk) /*!< INIT_CPUTOCPU Set Value            */
#define MEM_CFG_REGS_MSGXINIT_INIT_CPUTOCPU_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_MSGXINIT_INIT_CPUTOCPU_Msk) >> MEM_CFG_REGS_MSGXINIT_INIT_CPUTOCPU_Pos) /*!< INIT_CPUTOCPU Get Value            */


/* MSGXINITDONE bitfield */
#define MEM_CFG_REGS_MSGXINITDONE_INITDONE_CPUTOCPU_Pos    (0U)                                                                                  /*!< INITDONE_CPUTOCPU Postion   0          */ 
#define MEM_CFG_REGS_MSGXINITDONE_INITDONE_CPUTOCPU_Msk    (0x1U << MEM_CFG_REGS_MSGXINITDONE_INITDONE_CPUTOCPU_Pos)                             /*!< INITDONE_CPUTOCPU Mask      0x00000001 */
#define MEM_CFG_REGS_MSGXINITDONE_INITDONE_CPUTOCPU_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_MSGXINITDONE_INITDONE_CPUTOCPU_Pos) & MEM_CFG_REGS_MSGXINITDONE_INITDONE_CPUTOCPU_Msk) /*!< INITDONE_CPUTOCPU Set Value            */
#define MEM_CFG_REGS_MSGXINITDONE_INITDONE_CPUTOCPU_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_MSGXINITDONE_INITDONE_CPUTOCPU_Msk) >> MEM_CFG_REGS_MSGXINITDONE_INITDONE_CPUTOCPU_Pos) /*!< INITDONE_CPUTOCPU Get Value            */


/* TCMXTEST bitfield */
#define MEM_CFG_REGS_TCMXTEST_TEST_DTCM_Pos    (2U)                                                                                  /*!< TEST_DTCM Postion   2          */ 
#define MEM_CFG_REGS_TCMXTEST_TEST_DTCM_Msk    (0x3U << MEM_CFG_REGS_TCMXTEST_TEST_DTCM_Pos)                                         /*!< TEST_DTCM Mask      0x0000000C */
#define MEM_CFG_REGS_TCMXTEST_TEST_DTCM_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_TCMXTEST_TEST_DTCM_Pos) & MEM_CFG_REGS_TCMXTEST_TEST_DTCM_Msk) /*!< TEST_DTCM Set Value            */
#define MEM_CFG_REGS_TCMXTEST_TEST_DTCM_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_TCMXTEST_TEST_DTCM_Msk) >> MEM_CFG_REGS_TCMXTEST_TEST_DTCM_Pos) /*!< TEST_DTCM Get Value            */


#define MEM_CFG_REGS_TCMXTEST_TEST_ITCM_Pos    (0U)                                                                                  /*!< TEST_ITCM Postion   0          */ 
#define MEM_CFG_REGS_TCMXTEST_TEST_ITCM_Msk    (0x3U << MEM_CFG_REGS_TCMXTEST_TEST_ITCM_Pos)                                         /*!< TEST_ITCM Mask      0x00000003 */
#define MEM_CFG_REGS_TCMXTEST_TEST_ITCM_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_TCMXTEST_TEST_ITCM_Pos) & MEM_CFG_REGS_TCMXTEST_TEST_ITCM_Msk) /*!< TEST_ITCM Set Value            */
#define MEM_CFG_REGS_TCMXTEST_TEST_ITCM_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_TCMXTEST_TEST_ITCM_Msk) >> MEM_CFG_REGS_TCMXTEST_TEST_ITCM_Pos) /*!< TEST_ITCM Get Value            */


/* TCMXINIT bitfield */
#define MEM_CFG_REGS_TCMXINIT_INIT_DTCM_Pos    (1U)                                                                                  /*!< INIT_DTCM Postion   1          */ 
#define MEM_CFG_REGS_TCMXINIT_INIT_DTCM_Msk    (0x1U << MEM_CFG_REGS_TCMXINIT_INIT_DTCM_Pos)                                         /*!< INIT_DTCM Mask      0x00000002 */
#define MEM_CFG_REGS_TCMXINIT_INIT_DTCM_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_TCMXINIT_INIT_DTCM_Pos) & MEM_CFG_REGS_TCMXINIT_INIT_DTCM_Msk) /*!< INIT_DTCM Set Value            */
#define MEM_CFG_REGS_TCMXINIT_INIT_DTCM_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_TCMXINIT_INIT_DTCM_Msk) >> MEM_CFG_REGS_TCMXINIT_INIT_DTCM_Pos) /*!< INIT_DTCM Get Value            */


#define MEM_CFG_REGS_TCMXINIT_INIT_ITCM_Pos    (0U)                                                                                  /*!< INIT_ITCM Postion   0          */ 
#define MEM_CFG_REGS_TCMXINIT_INIT_ITCM_Msk    (0x1U << MEM_CFG_REGS_TCMXINIT_INIT_ITCM_Pos)                                         /*!< INIT_ITCM Mask      0x00000001 */
#define MEM_CFG_REGS_TCMXINIT_INIT_ITCM_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_TCMXINIT_INIT_ITCM_Pos) & MEM_CFG_REGS_TCMXINIT_INIT_ITCM_Msk) /*!< INIT_ITCM Set Value            */
#define MEM_CFG_REGS_TCMXINIT_INIT_ITCM_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_TCMXINIT_INIT_ITCM_Msk) >> MEM_CFG_REGS_TCMXINIT_INIT_ITCM_Pos) /*!< INIT_ITCM Get Value            */


/* TCMXINITDONE bitfield */
#define MEM_CFG_REGS_TCMXINITDONE_INITDONE_DTCM_Pos    (1U)                                                                                  /*!< INITDONE_DTCM Postion   1          */ 
#define MEM_CFG_REGS_TCMXINITDONE_INITDONE_DTCM_Msk    (0x1U << MEM_CFG_REGS_TCMXINITDONE_INITDONE_DTCM_Pos)                                 /*!< INITDONE_DTCM Mask      0x00000002 */
#define MEM_CFG_REGS_TCMXINITDONE_INITDONE_DTCM_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_TCMXINITDONE_INITDONE_DTCM_Pos) & MEM_CFG_REGS_TCMXINITDONE_INITDONE_DTCM_Msk) /*!< INITDONE_DTCM Set Value            */
#define MEM_CFG_REGS_TCMXINITDONE_INITDONE_DTCM_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_TCMXINITDONE_INITDONE_DTCM_Msk) >> MEM_CFG_REGS_TCMXINITDONE_INITDONE_DTCM_Pos) /*!< INITDONE_DTCM Get Value            */


#define MEM_CFG_REGS_TCMXINITDONE_INITDONE_ITCM_Pos    (0U)                                                                                  /*!< INITDONE_ITCM Postion   0          */ 
#define MEM_CFG_REGS_TCMXINITDONE_INITDONE_ITCM_Msk    (0x1U << MEM_CFG_REGS_TCMXINITDONE_INITDONE_ITCM_Pos)                                 /*!< INITDONE_ITCM Mask      0x00000001 */
#define MEM_CFG_REGS_TCMXINITDONE_INITDONE_ITCM_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_TCMXINITDONE_INITDONE_ITCM_Pos) & MEM_CFG_REGS_TCMXINITDONE_INITDONE_ITCM_Msk) /*!< INITDONE_ITCM Set Value            */
#define MEM_CFG_REGS_TCMXINITDONE_INITDONE_ITCM_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_TCMXINITDONE_INITDONE_ITCM_Msk) >> MEM_CFG_REGS_TCMXINITDONE_INITDONE_ITCM_Pos) /*!< INITDONE_ITCM Get Value            */


/* GSWRALLOWDBG bitfield */
#define MEM_CFG_REGS_GSWRALLOWDBG_GSWRALLOWDBG_Pos    (0U)                                                                                  /*!< GSWRALLOWDBG Postion   0          */ 
#define MEM_CFG_REGS_GSWRALLOWDBG_GSWRALLOWDBG_Msk    (0x1U << MEM_CFG_REGS_GSWRALLOWDBG_GSWRALLOWDBG_Pos)                                  /*!< GSWRALLOWDBG Mask      0x00000001 */
#define MEM_CFG_REGS_GSWRALLOWDBG_GSWRALLOWDBG_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_GSWRALLOWDBG_GSWRALLOWDBG_Pos) & MEM_CFG_REGS_GSWRALLOWDBG_GSWRALLOWDBG_Msk) /*!< GSWRALLOWDBG Set Value            */
#define MEM_CFG_REGS_GSWRALLOWDBG_GSWRALLOWDBG_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_GSWRALLOWDBG_GSWRALLOWDBG_Msk) >> MEM_CFG_REGS_GSWRALLOWDBG_GSWRALLOWDBG_Pos) /*!< GSWRALLOWDBG Get Value            */


/* CANSRAMINIT bitfield */
#define MEM_CFG_REGS_CANSRAMINIT_INIT_CANSRAM_Pos    (0U)                                                                                  /*!< INIT_CANSRAM Postion   0          */ 
#define MEM_CFG_REGS_CANSRAMINIT_INIT_CANSRAM_Msk    (0x1U << MEM_CFG_REGS_CANSRAMINIT_INIT_CANSRAM_Pos)                                   /*!< INIT_CANSRAM Mask      0x00000001 */
#define MEM_CFG_REGS_CANSRAMINIT_INIT_CANSRAM_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_CANSRAMINIT_INIT_CANSRAM_Pos) & MEM_CFG_REGS_CANSRAMINIT_INIT_CANSRAM_Msk) /*!< INIT_CANSRAM Set Value            */
#define MEM_CFG_REGS_CANSRAMINIT_INIT_CANSRAM_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_CANSRAMINIT_INIT_CANSRAM_Msk) >> MEM_CFG_REGS_CANSRAMINIT_INIT_CANSRAM_Pos) /*!< INIT_CANSRAM Get Value            */


/* CANSRAMINITDONE bitfield */
#define MEM_CFG_REGS_CANSRAMINITDONE_INITDONE_CANSRAM_Pos    (0U)                                                                                  /*!< INITDONE_CANSRAM Postion   0          */ 
#define MEM_CFG_REGS_CANSRAMINITDONE_INITDONE_CANSRAM_Msk    (0x1U << MEM_CFG_REGS_CANSRAMINITDONE_INITDONE_CANSRAM_Pos)                           /*!< INITDONE_CANSRAM Mask      0x00000001 */
#define MEM_CFG_REGS_CANSRAMINITDONE_INITDONE_CANSRAM_Set(x) (((uint32_t) (x) << MEM_CFG_REGS_CANSRAMINITDONE_INITDONE_CANSRAM_Pos) & MEM_CFG_REGS_CANSRAMINITDONE_INITDONE_CANSRAM_Msk) /*!< INITDONE_CANSRAM Set Value            */
#define MEM_CFG_REGS_CANSRAMINITDONE_INITDONE_CANSRAM_Get(x) (((uint32_t) (x) & MEM_CFG_REGS_CANSRAMINITDONE_INITDONE_CANSRAM_Msk) >> MEM_CFG_REGS_CANSRAMINITDONE_INITDONE_CANSRAM_Pos) /*!< INITDONE_CANSRAM Get Value            */


/* NMAVFLG bitfield */
#define ACCESS_PROTECTION_REGS_NMAVFLG_USBADMAWRITE_Pos    (7U)                                                                                  /*!< USBADMAWRITE Postion   7          */ 
#define ACCESS_PROTECTION_REGS_NMAVFLG_USBADMAWRITE_Msk    (0x1U << ACCESS_PROTECTION_REGS_NMAVFLG_USBADMAWRITE_Pos)                             /*!< USBADMAWRITE Mask      0x00000080 */
#define ACCESS_PROTECTION_REGS_NMAVFLG_USBADMAWRITE_Set(x) (((uint32_t) (x) << ACCESS_PROTECTION_REGS_NMAVFLG_USBADMAWRITE_Pos) & ACCESS_PROTECTION_REGS_NMAVFLG_USBADMAWRITE_Msk) /*!< USBADMAWRITE Set Value            */
#define ACCESS_PROTECTION_REGS_NMAVFLG_USBADMAWRITE_Get(x) (((uint32_t) (x) & ACCESS_PROTECTION_REGS_NMAVFLG_USBADMAWRITE_Msk) >> ACCESS_PROTECTION_REGS_NMAVFLG_USBADMAWRITE_Pos) /*!< USBADMAWRITE Get Value            */


#define ACCESS_PROTECTION_REGS_NMAVFLG_DMAWRITE_Pos    (3U)                                                                                  /*!< DMAWRITE Postion   3          */ 
#define ACCESS_PROTECTION_REGS_NMAVFLG_DMAWRITE_Msk    (0x1U << ACCESS_PROTECTION_REGS_NMAVFLG_DMAWRITE_Pos)                                 /*!< DMAWRITE Mask      0x00000008 */
#define ACCESS_PROTECTION_REGS_NMAVFLG_DMAWRITE_Set(x) (((uint32_t) (x) << ACCESS_PROTECTION_REGS_NMAVFLG_DMAWRITE_Pos) & ACCESS_PROTECTION_REGS_NMAVFLG_DMAWRITE_Msk) /*!< DMAWRITE Set Value            */
#define ACCESS_PROTECTION_REGS_NMAVFLG_DMAWRITE_Get(x) (((uint32_t) (x) & ACCESS_PROTECTION_REGS_NMAVFLG_DMAWRITE_Msk) >> ACCESS_PROTECTION_REGS_NMAVFLG_DMAWRITE_Pos) /*!< DMAWRITE Get Value            */


#define ACCESS_PROTECTION_REGS_NMAVFLG_CPUWRITE_Pos    (1U)                                                                                  /*!< CPUWRITE Postion   1          */ 
#define ACCESS_PROTECTION_REGS_NMAVFLG_CPUWRITE_Msk    (0x1U << ACCESS_PROTECTION_REGS_NMAVFLG_CPUWRITE_Pos)                                 /*!< CPUWRITE Mask      0x00000002 */
#define ACCESS_PROTECTION_REGS_NMAVFLG_CPUWRITE_Set(x) (((uint32_t) (x) << ACCESS_PROTECTION_REGS_NMAVFLG_CPUWRITE_Pos) & ACCESS_PROTECTION_REGS_NMAVFLG_CPUWRITE_Msk) /*!< CPUWRITE Set Value            */
#define ACCESS_PROTECTION_REGS_NMAVFLG_CPUWRITE_Get(x) (((uint32_t) (x) & ACCESS_PROTECTION_REGS_NMAVFLG_CPUWRITE_Msk) >> ACCESS_PROTECTION_REGS_NMAVFLG_CPUWRITE_Pos) /*!< CPUWRITE Get Value            */


/* NMAVSET bitfield */
#define ACCESS_PROTECTION_REGS_NMAVSET_USBADMAWRITE_Pos    (7U)                                                                                  /*!< USBADMAWRITE Postion   7          */ 
#define ACCESS_PROTECTION_REGS_NMAVSET_USBADMAWRITE_Msk    (0x1U << ACCESS_PROTECTION_REGS_NMAVSET_USBADMAWRITE_Pos)                             /*!< USBADMAWRITE Mask      0x00000080 */
#define ACCESS_PROTECTION_REGS_NMAVSET_USBADMAWRITE_Set(x) (((uint32_t) (x) << ACCESS_PROTECTION_REGS_NMAVSET_USBADMAWRITE_Pos) & ACCESS_PROTECTION_REGS_NMAVSET_USBADMAWRITE_Msk) /*!< USBADMAWRITE Set Value            */
#define ACCESS_PROTECTION_REGS_NMAVSET_USBADMAWRITE_Get(x) (((uint32_t) (x) & ACCESS_PROTECTION_REGS_NMAVSET_USBADMAWRITE_Msk) >> ACCESS_PROTECTION_REGS_NMAVSET_USBADMAWRITE_Pos) /*!< USBADMAWRITE Get Value            */


#define ACCESS_PROTECTION_REGS_NMAVSET_DMAWRITE_Pos    (3U)                                                                                  /*!< DMAWRITE Postion   3          */ 
#define ACCESS_PROTECTION_REGS_NMAVSET_DMAWRITE_Msk    (0x1U << ACCESS_PROTECTION_REGS_NMAVSET_DMAWRITE_Pos)                                 /*!< DMAWRITE Mask      0x00000008 */
#define ACCESS_PROTECTION_REGS_NMAVSET_DMAWRITE_Set(x) (((uint32_t) (x) << ACCESS_PROTECTION_REGS_NMAVSET_DMAWRITE_Pos) & ACCESS_PROTECTION_REGS_NMAVSET_DMAWRITE_Msk) /*!< DMAWRITE Set Value            */
#define ACCESS_PROTECTION_REGS_NMAVSET_DMAWRITE_Get(x) (((uint32_t) (x) & ACCESS_PROTECTION_REGS_NMAVSET_DMAWRITE_Msk) >> ACCESS_PROTECTION_REGS_NMAVSET_DMAWRITE_Pos) /*!< DMAWRITE Get Value            */


#define ACCESS_PROTECTION_REGS_NMAVSET_CPUWRITE_Pos    (1U)                                                                                  /*!< CPUWRITE Postion   1          */ 
#define ACCESS_PROTECTION_REGS_NMAVSET_CPUWRITE_Msk    (0x1U << ACCESS_PROTECTION_REGS_NMAVSET_CPUWRITE_Pos)                                 /*!< CPUWRITE Mask      0x00000002 */
#define ACCESS_PROTECTION_REGS_NMAVSET_CPUWRITE_Set(x) (((uint32_t) (x) << ACCESS_PROTECTION_REGS_NMAVSET_CPUWRITE_Pos) & ACCESS_PROTECTION_REGS_NMAVSET_CPUWRITE_Msk) /*!< CPUWRITE Set Value            */
#define ACCESS_PROTECTION_REGS_NMAVSET_CPUWRITE_Get(x) (((uint32_t) (x) & ACCESS_PROTECTION_REGS_NMAVSET_CPUWRITE_Msk) >> ACCESS_PROTECTION_REGS_NMAVSET_CPUWRITE_Pos) /*!< CPUWRITE Get Value            */


/* NMAVCLR bitfield */
#define ACCESS_PROTECTION_REGS_NMAVCLR_USBADMAWRITE_Pos    (7U)                                                                                  /*!< USBADMAWRITE Postion   7          */ 
#define ACCESS_PROTECTION_REGS_NMAVCLR_USBADMAWRITE_Msk    (0x1U << ACCESS_PROTECTION_REGS_NMAVCLR_USBADMAWRITE_Pos)                             /*!< USBADMAWRITE Mask      0x00000080 */
#define ACCESS_PROTECTION_REGS_NMAVCLR_USBADMAWRITE_Set(x) (((uint32_t) (x) << ACCESS_PROTECTION_REGS_NMAVCLR_USBADMAWRITE_Pos) & ACCESS_PROTECTION_REGS_NMAVCLR_USBADMAWRITE_Msk) /*!< USBADMAWRITE Set Value            */
#define ACCESS_PROTECTION_REGS_NMAVCLR_USBADMAWRITE_Get(x) (((uint32_t) (x) & ACCESS_PROTECTION_REGS_NMAVCLR_USBADMAWRITE_Msk) >> ACCESS_PROTECTION_REGS_NMAVCLR_USBADMAWRITE_Pos) /*!< USBADMAWRITE Get Value            */


#define ACCESS_PROTECTION_REGS_NMAVCLR_DMAWRITE_Pos    (3U)                                                                                  /*!< DMAWRITE Postion   3          */ 
#define ACCESS_PROTECTION_REGS_NMAVCLR_DMAWRITE_Msk    (0x1U << ACCESS_PROTECTION_REGS_NMAVCLR_DMAWRITE_Pos)                                 /*!< DMAWRITE Mask      0x00000008 */
#define ACCESS_PROTECTION_REGS_NMAVCLR_DMAWRITE_Set(x) (((uint32_t) (x) << ACCESS_PROTECTION_REGS_NMAVCLR_DMAWRITE_Pos) & ACCESS_PROTECTION_REGS_NMAVCLR_DMAWRITE_Msk) /*!< DMAWRITE Set Value            */
#define ACCESS_PROTECTION_REGS_NMAVCLR_DMAWRITE_Get(x) (((uint32_t) (x) & ACCESS_PROTECTION_REGS_NMAVCLR_DMAWRITE_Msk) >> ACCESS_PROTECTION_REGS_NMAVCLR_DMAWRITE_Pos) /*!< DMAWRITE Get Value            */


#define ACCESS_PROTECTION_REGS_NMAVCLR_CPUWRITE_Pos    (1U)                                                                                  /*!< CPUWRITE Postion   1          */ 
#define ACCESS_PROTECTION_REGS_NMAVCLR_CPUWRITE_Msk    (0x1U << ACCESS_PROTECTION_REGS_NMAVCLR_CPUWRITE_Pos)                                 /*!< CPUWRITE Mask      0x00000002 */
#define ACCESS_PROTECTION_REGS_NMAVCLR_CPUWRITE_Set(x) (((uint32_t) (x) << ACCESS_PROTECTION_REGS_NMAVCLR_CPUWRITE_Pos) & ACCESS_PROTECTION_REGS_NMAVCLR_CPUWRITE_Msk) /*!< CPUWRITE Set Value            */
#define ACCESS_PROTECTION_REGS_NMAVCLR_CPUWRITE_Get(x) (((uint32_t) (x) & ACCESS_PROTECTION_REGS_NMAVCLR_CPUWRITE_Msk) >> ACCESS_PROTECTION_REGS_NMAVCLR_CPUWRITE_Pos) /*!< CPUWRITE Get Value            */


/* NMAVINTEN bitfield */
#define ACCESS_PROTECTION_REGS_NMAVINTEN_USBADMAWRITE_Pos    (7U)                                                                                  /*!< USBADMAWRITE Postion   7          */ 
#define ACCESS_PROTECTION_REGS_NMAVINTEN_USBADMAWRITE_Msk    (0x1U << ACCESS_PROTECTION_REGS_NMAVINTEN_USBADMAWRITE_Pos)                           /*!< USBADMAWRITE Mask      0x00000080 */
#define ACCESS_PROTECTION_REGS_NMAVINTEN_USBADMAWRITE_Set(x) (((uint32_t) (x) << ACCESS_PROTECTION_REGS_NMAVINTEN_USBADMAWRITE_Pos) & ACCESS_PROTECTION_REGS_NMAVINTEN_USBADMAWRITE_Msk) /*!< USBADMAWRITE Set Value            */
#define ACCESS_PROTECTION_REGS_NMAVINTEN_USBADMAWRITE_Get(x) (((uint32_t) (x) & ACCESS_PROTECTION_REGS_NMAVINTEN_USBADMAWRITE_Msk) >> ACCESS_PROTECTION_REGS_NMAVINTEN_USBADMAWRITE_Pos) /*!< USBADMAWRITE Get Value            */


#define ACCESS_PROTECTION_REGS_NMAVINTEN_DMAWRITE_Pos    (3U)                                                                                  /*!< DMAWRITE Postion   3          */ 
#define ACCESS_PROTECTION_REGS_NMAVINTEN_DMAWRITE_Msk    (0x1U << ACCESS_PROTECTION_REGS_NMAVINTEN_DMAWRITE_Pos)                               /*!< DMAWRITE Mask      0x00000008 */
#define ACCESS_PROTECTION_REGS_NMAVINTEN_DMAWRITE_Set(x) (((uint32_t) (x) << ACCESS_PROTECTION_REGS_NMAVINTEN_DMAWRITE_Pos) & ACCESS_PROTECTION_REGS_NMAVINTEN_DMAWRITE_Msk) /*!< DMAWRITE Set Value            */
#define ACCESS_PROTECTION_REGS_NMAVINTEN_DMAWRITE_Get(x) (((uint32_t) (x) & ACCESS_PROTECTION_REGS_NMAVINTEN_DMAWRITE_Msk) >> ACCESS_PROTECTION_REGS_NMAVINTEN_DMAWRITE_Pos) /*!< DMAWRITE Get Value            */


#define ACCESS_PROTECTION_REGS_NMAVINTEN_CPUWRITE_Pos    (1U)                                                                                  /*!< CPUWRITE Postion   1          */ 
#define ACCESS_PROTECTION_REGS_NMAVINTEN_CPUWRITE_Msk    (0x1U << ACCESS_PROTECTION_REGS_NMAVINTEN_CPUWRITE_Pos)                               /*!< CPUWRITE Mask      0x00000002 */
#define ACCESS_PROTECTION_REGS_NMAVINTEN_CPUWRITE_Set(x) (((uint32_t) (x) << ACCESS_PROTECTION_REGS_NMAVINTEN_CPUWRITE_Pos) & ACCESS_PROTECTION_REGS_NMAVINTEN_CPUWRITE_Msk) /*!< CPUWRITE Set Value            */
#define ACCESS_PROTECTION_REGS_NMAVINTEN_CPUWRITE_Get(x) (((uint32_t) (x) & ACCESS_PROTECTION_REGS_NMAVINTEN_CPUWRITE_Msk) >> ACCESS_PROTECTION_REGS_NMAVINTEN_CPUWRITE_Pos) /*!< CPUWRITE Get Value            */


/* NMCPURDAVADDR bitfield */
/* NMCPUWRAVADDR bitfield */
#define ACCESS_PROTECTION_REGS_NMCPUWRAVADDR_NMCPUWRAVADDR_Pos    (0U)                                                                                  /*!< NMCPUWRAVADDR Postion   0          */ 
#define ACCESS_PROTECTION_REGS_NMCPUWRAVADDR_NMCPUWRAVADDR_Msk    (0xffffffffU << ACCESS_PROTECTION_REGS_NMCPUWRAVADDR_NMCPUWRAVADDR_Pos)               /*!< NMCPUWRAVADDR Mask      0xFFFFFFFF */
#define ACCESS_PROTECTION_REGS_NMCPUWRAVADDR_NMCPUWRAVADDR_Set(x) (((uint32_t) (x) << ACCESS_PROTECTION_REGS_NMCPUWRAVADDR_NMCPUWRAVADDR_Pos) & ACCESS_PROTECTION_REGS_NMCPUWRAVADDR_NMCPUWRAVADDR_Msk) /*!< NMCPUWRAVADDR Set Value            */
#define ACCESS_PROTECTION_REGS_NMCPUWRAVADDR_NMCPUWRAVADDR_Get(x) (((uint32_t) (x) & ACCESS_PROTECTION_REGS_NMCPUWRAVADDR_NMCPUWRAVADDR_Msk) >> ACCESS_PROTECTION_REGS_NMCPUWRAVADDR_NMCPUWRAVADDR_Pos) /*!< NMCPUWRAVADDR Get Value            */


/* NMDMAWRAVADDR bitfield */
#define ACCESS_PROTECTION_REGS_NMDMAWRAVADDR_NMDMAWRAVADDR_Pos    (0U)                                                                                  /*!< NMDMAWRAVADDR Postion   0          */ 
#define ACCESS_PROTECTION_REGS_NMDMAWRAVADDR_NMDMAWRAVADDR_Msk    (0xffffffffU << ACCESS_PROTECTION_REGS_NMDMAWRAVADDR_NMDMAWRAVADDR_Pos)               /*!< NMDMAWRAVADDR Mask      0xFFFFFFFF */
#define ACCESS_PROTECTION_REGS_NMDMAWRAVADDR_NMDMAWRAVADDR_Set(x) (((uint32_t) (x) << ACCESS_PROTECTION_REGS_NMDMAWRAVADDR_NMDMAWRAVADDR_Pos) & ACCESS_PROTECTION_REGS_NMDMAWRAVADDR_NMDMAWRAVADDR_Msk) /*!< NMDMAWRAVADDR Set Value            */
#define ACCESS_PROTECTION_REGS_NMDMAWRAVADDR_NMDMAWRAVADDR_Get(x) (((uint32_t) (x) & ACCESS_PROTECTION_REGS_NMDMAWRAVADDR_NMDMAWRAVADDR_Msk) >> ACCESS_PROTECTION_REGS_NMDMAWRAVADDR_NMDMAWRAVADDR_Pos) /*!< NMDMAWRAVADDR Get Value            */


/* NMUSBADMAWRAVADDR bitfield */
#define ACCESS_PROTECTION_REGS_NMUSBADMAWRAVADDR_NMUSBADMAWRAVADDR_Pos    (0U)                                                                                  /*!< NMUSBADMAWRAVADDR Postion   0          */ 
#define ACCESS_PROTECTION_REGS_NMUSBADMAWRAVADDR_NMUSBADMAWRAVADDR_Msk    (0xffffffffU << ACCESS_PROTECTION_REGS_NMUSBADMAWRAVADDR_NMUSBADMAWRAVADDR_Pos)       /*!< NMUSBADMAWRAVADDR Mask      0xFFFFFFFF */
#define ACCESS_PROTECTION_REGS_NMUSBADMAWRAVADDR_NMUSBADMAWRAVADDR_Set(x) (((uint32_t) (x) << ACCESS_PROTECTION_REGS_NMUSBADMAWRAVADDR_NMUSBADMAWRAVADDR_Pos) & ACCESS_PROTECTION_REGS_NMUSBADMAWRAVADDR_NMUSBADMAWRAVADDR_Msk) /*!< NMUSBADMAWRAVADDR Set Value            */
#define ACCESS_PROTECTION_REGS_NMUSBADMAWRAVADDR_NMUSBADMAWRAVADDR_Get(x) (((uint32_t) (x) & ACCESS_PROTECTION_REGS_NMUSBADMAWRAVADDR_NMUSBADMAWRAVADDR_Msk) >> ACCESS_PROTECTION_REGS_NMUSBADMAWRAVADDR_NMUSBADMAWRAVADDR_Pos) /*!< NMUSBADMAWRAVADDR Get Value            */


/* MAVFLG bitfield */
#define ACCESS_PROTECTION_REGS_MAVFLG_DMAWRITE_Pos    (2U)                                                                                  /*!< DMAWRITE Postion   2          */ 
#define ACCESS_PROTECTION_REGS_MAVFLG_DMAWRITE_Msk    (0x1U << ACCESS_PROTECTION_REGS_MAVFLG_DMAWRITE_Pos)                                  /*!< DMAWRITE Mask      0x00000004 */
#define ACCESS_PROTECTION_REGS_MAVFLG_DMAWRITE_Set(x) (((uint32_t) (x) << ACCESS_PROTECTION_REGS_MAVFLG_DMAWRITE_Pos) & ACCESS_PROTECTION_REGS_MAVFLG_DMAWRITE_Msk) /*!< DMAWRITE Set Value            */
#define ACCESS_PROTECTION_REGS_MAVFLG_DMAWRITE_Get(x) (((uint32_t) (x) & ACCESS_PROTECTION_REGS_MAVFLG_DMAWRITE_Msk) >> ACCESS_PROTECTION_REGS_MAVFLG_DMAWRITE_Pos) /*!< DMAWRITE Get Value            */


#define ACCESS_PROTECTION_REGS_MAVFLG_CPUWRITE_Pos    (1U)                                                                                  /*!< CPUWRITE Postion   1          */ 
#define ACCESS_PROTECTION_REGS_MAVFLG_CPUWRITE_Msk    (0x1U << ACCESS_PROTECTION_REGS_MAVFLG_CPUWRITE_Pos)                                  /*!< CPUWRITE Mask      0x00000002 */
#define ACCESS_PROTECTION_REGS_MAVFLG_CPUWRITE_Set(x) (((uint32_t) (x) << ACCESS_PROTECTION_REGS_MAVFLG_CPUWRITE_Pos) & ACCESS_PROTECTION_REGS_MAVFLG_CPUWRITE_Msk) /*!< CPUWRITE Set Value            */
#define ACCESS_PROTECTION_REGS_MAVFLG_CPUWRITE_Get(x) (((uint32_t) (x) & ACCESS_PROTECTION_REGS_MAVFLG_CPUWRITE_Msk) >> ACCESS_PROTECTION_REGS_MAVFLG_CPUWRITE_Pos) /*!< CPUWRITE Get Value            */


/* MAVSET bitfield */
#define ACCESS_PROTECTION_REGS_MAVSET_DMAWRITE_Pos    (2U)                                                                                  /*!< DMAWRITE Postion   2          */ 
#define ACCESS_PROTECTION_REGS_MAVSET_DMAWRITE_Msk    (0x1U << ACCESS_PROTECTION_REGS_MAVSET_DMAWRITE_Pos)                                  /*!< DMAWRITE Mask      0x00000004 */
#define ACCESS_PROTECTION_REGS_MAVSET_DMAWRITE_Set(x) (((uint32_t) (x) << ACCESS_PROTECTION_REGS_MAVSET_DMAWRITE_Pos) & ACCESS_PROTECTION_REGS_MAVSET_DMAWRITE_Msk) /*!< DMAWRITE Set Value            */
#define ACCESS_PROTECTION_REGS_MAVSET_DMAWRITE_Get(x) (((uint32_t) (x) & ACCESS_PROTECTION_REGS_MAVSET_DMAWRITE_Msk) >> ACCESS_PROTECTION_REGS_MAVSET_DMAWRITE_Pos) /*!< DMAWRITE Get Value            */


#define ACCESS_PROTECTION_REGS_MAVSET_CPUWRITE_Pos    (1U)                                                                                  /*!< CPUWRITE Postion   1          */ 
#define ACCESS_PROTECTION_REGS_MAVSET_CPUWRITE_Msk    (0x1U << ACCESS_PROTECTION_REGS_MAVSET_CPUWRITE_Pos)                                  /*!< CPUWRITE Mask      0x00000002 */
#define ACCESS_PROTECTION_REGS_MAVSET_CPUWRITE_Set(x) (((uint32_t) (x) << ACCESS_PROTECTION_REGS_MAVSET_CPUWRITE_Pos) & ACCESS_PROTECTION_REGS_MAVSET_CPUWRITE_Msk) /*!< CPUWRITE Set Value            */
#define ACCESS_PROTECTION_REGS_MAVSET_CPUWRITE_Get(x) (((uint32_t) (x) & ACCESS_PROTECTION_REGS_MAVSET_CPUWRITE_Msk) >> ACCESS_PROTECTION_REGS_MAVSET_CPUWRITE_Pos) /*!< CPUWRITE Get Value            */


/* MAVCLR bitfield */
#define ACCESS_PROTECTION_REGS_MAVCLR_DMAWRITE_Pos    (2U)                                                                                  /*!< DMAWRITE Postion   2          */ 
#define ACCESS_PROTECTION_REGS_MAVCLR_DMAWRITE_Msk    (0x1U << ACCESS_PROTECTION_REGS_MAVCLR_DMAWRITE_Pos)                                  /*!< DMAWRITE Mask      0x00000004 */
#define ACCESS_PROTECTION_REGS_MAVCLR_DMAWRITE_Set(x) (((uint32_t) (x) << ACCESS_PROTECTION_REGS_MAVCLR_DMAWRITE_Pos) & ACCESS_PROTECTION_REGS_MAVCLR_DMAWRITE_Msk) /*!< DMAWRITE Set Value            */
#define ACCESS_PROTECTION_REGS_MAVCLR_DMAWRITE_Get(x) (((uint32_t) (x) & ACCESS_PROTECTION_REGS_MAVCLR_DMAWRITE_Msk) >> ACCESS_PROTECTION_REGS_MAVCLR_DMAWRITE_Pos) /*!< DMAWRITE Get Value            */


#define ACCESS_PROTECTION_REGS_MAVCLR_CPUWRITE_Pos    (1U)                                                                                  /*!< CPUWRITE Postion   1          */ 
#define ACCESS_PROTECTION_REGS_MAVCLR_CPUWRITE_Msk    (0x1U << ACCESS_PROTECTION_REGS_MAVCLR_CPUWRITE_Pos)                                  /*!< CPUWRITE Mask      0x00000002 */
#define ACCESS_PROTECTION_REGS_MAVCLR_CPUWRITE_Set(x) (((uint32_t) (x) << ACCESS_PROTECTION_REGS_MAVCLR_CPUWRITE_Pos) & ACCESS_PROTECTION_REGS_MAVCLR_CPUWRITE_Msk) /*!< CPUWRITE Set Value            */
#define ACCESS_PROTECTION_REGS_MAVCLR_CPUWRITE_Get(x) (((uint32_t) (x) & ACCESS_PROTECTION_REGS_MAVCLR_CPUWRITE_Msk) >> ACCESS_PROTECTION_REGS_MAVCLR_CPUWRITE_Pos) /*!< CPUWRITE Get Value            */


/* MAVINTEN bitfield */
#define ACCESS_PROTECTION_REGS_MAVINTEN_DMAWRITE_Pos    (2U)                                                                                  /*!< DMAWRITE Postion   2          */ 
#define ACCESS_PROTECTION_REGS_MAVINTEN_DMAWRITE_Msk    (0x1U << ACCESS_PROTECTION_REGS_MAVINTEN_DMAWRITE_Pos)                                /*!< DMAWRITE Mask      0x00000004 */
#define ACCESS_PROTECTION_REGS_MAVINTEN_DMAWRITE_Set(x) (((uint32_t) (x) << ACCESS_PROTECTION_REGS_MAVINTEN_DMAWRITE_Pos) & ACCESS_PROTECTION_REGS_MAVINTEN_DMAWRITE_Msk) /*!< DMAWRITE Set Value            */
#define ACCESS_PROTECTION_REGS_MAVINTEN_DMAWRITE_Get(x) (((uint32_t) (x) & ACCESS_PROTECTION_REGS_MAVINTEN_DMAWRITE_Msk) >> ACCESS_PROTECTION_REGS_MAVINTEN_DMAWRITE_Pos) /*!< DMAWRITE Get Value            */


#define ACCESS_PROTECTION_REGS_MAVINTEN_CPUWRITE_Pos    (1U)                                                                                  /*!< CPUWRITE Postion   1          */ 
#define ACCESS_PROTECTION_REGS_MAVINTEN_CPUWRITE_Msk    (0x1U << ACCESS_PROTECTION_REGS_MAVINTEN_CPUWRITE_Pos)                                /*!< CPUWRITE Mask      0x00000002 */
#define ACCESS_PROTECTION_REGS_MAVINTEN_CPUWRITE_Set(x) (((uint32_t) (x) << ACCESS_PROTECTION_REGS_MAVINTEN_CPUWRITE_Pos) & ACCESS_PROTECTION_REGS_MAVINTEN_CPUWRITE_Msk) /*!< CPUWRITE Set Value            */
#define ACCESS_PROTECTION_REGS_MAVINTEN_CPUWRITE_Get(x) (((uint32_t) (x) & ACCESS_PROTECTION_REGS_MAVINTEN_CPUWRITE_Msk) >> ACCESS_PROTECTION_REGS_MAVINTEN_CPUWRITE_Pos) /*!< CPUWRITE Get Value            */


/* MCPUWRAVADDR bitfield */
#define ACCESS_PROTECTION_REGS_MCPUWRAVADDR_MCPUWRAVADDR_Pos    (0U)                                                                                  /*!< MCPUWRAVADDR Postion   0          */ 
#define ACCESS_PROTECTION_REGS_MCPUWRAVADDR_MCPUWRAVADDR_Msk    (0xffffffffU << ACCESS_PROTECTION_REGS_MCPUWRAVADDR_MCPUWRAVADDR_Pos)                 /*!< MCPUWRAVADDR Mask      0xFFFFFFFF */
#define ACCESS_PROTECTION_REGS_MCPUWRAVADDR_MCPUWRAVADDR_Set(x) (((uint32_t) (x) << ACCESS_PROTECTION_REGS_MCPUWRAVADDR_MCPUWRAVADDR_Pos) & ACCESS_PROTECTION_REGS_MCPUWRAVADDR_MCPUWRAVADDR_Msk) /*!< MCPUWRAVADDR Set Value            */
#define ACCESS_PROTECTION_REGS_MCPUWRAVADDR_MCPUWRAVADDR_Get(x) (((uint32_t) (x) & ACCESS_PROTECTION_REGS_MCPUWRAVADDR_MCPUWRAVADDR_Msk) >> ACCESS_PROTECTION_REGS_MCPUWRAVADDR_MCPUWRAVADDR_Pos) /*!< MCPUWRAVADDR Get Value            */


/* MDMAWRAVADDR bitfield */
#define ACCESS_PROTECTION_REGS_MDMAWRAVADDR_MDMAWRAVADDR_Pos    (0U)                                                                                  /*!< MDMAWRAVADDR Postion   0          */ 
#define ACCESS_PROTECTION_REGS_MDMAWRAVADDR_MDMAWRAVADDR_Msk    (0xffffffffU << ACCESS_PROTECTION_REGS_MDMAWRAVADDR_MDMAWRAVADDR_Pos)                 /*!< MDMAWRAVADDR Mask      0xFFFFFFFF */
#define ACCESS_PROTECTION_REGS_MDMAWRAVADDR_MDMAWRAVADDR_Set(x) (((uint32_t) (x) << ACCESS_PROTECTION_REGS_MDMAWRAVADDR_MDMAWRAVADDR_Pos) & ACCESS_PROTECTION_REGS_MDMAWRAVADDR_MDMAWRAVADDR_Msk) /*!< MDMAWRAVADDR Set Value            */
#define ACCESS_PROTECTION_REGS_MDMAWRAVADDR_MDMAWRAVADDR_Get(x) (((uint32_t) (x) & ACCESS_PROTECTION_REGS_MDMAWRAVADDR_MDMAWRAVADDR_Msk) >> ACCESS_PROTECTION_REGS_MDMAWRAVADDR_MDMAWRAVADDR_Pos) /*!< MDMAWRAVADDR Get Value            */


/* UCERRFLG bitfield */
#define MEMORY_ERROR_REGS_UCERRFLG_USBADMARDERR_Pos    (3U)                                                                                  /*!< USBADMARDERR Postion   3          */ 
#define MEMORY_ERROR_REGS_UCERRFLG_USBADMARDERR_Msk    (0x1U << MEMORY_ERROR_REGS_UCERRFLG_USBADMARDERR_Pos)                                 /*!< USBADMARDERR Mask      0x00000008 */
#define MEMORY_ERROR_REGS_UCERRFLG_USBADMARDERR_Set(x) (((uint32_t) (x) << MEMORY_ERROR_REGS_UCERRFLG_USBADMARDERR_Pos) & MEMORY_ERROR_REGS_UCERRFLG_USBADMARDERR_Msk) /*!< USBADMARDERR Set Value            */
#define MEMORY_ERROR_REGS_UCERRFLG_USBADMARDERR_Get(x) (((uint32_t) (x) & MEMORY_ERROR_REGS_UCERRFLG_USBADMARDERR_Msk) >> MEMORY_ERROR_REGS_UCERRFLG_USBADMARDERR_Pos) /*!< USBADMARDERR Get Value            */


#define MEMORY_ERROR_REGS_UCERRFLG_DMARDERR_Pos    (1U)                                                                                  /*!< DMARDERR Postion   1          */ 
#define MEMORY_ERROR_REGS_UCERRFLG_DMARDERR_Msk    (0x1U << MEMORY_ERROR_REGS_UCERRFLG_DMARDERR_Pos)                                     /*!< DMARDERR Mask      0x00000002 */
#define MEMORY_ERROR_REGS_UCERRFLG_DMARDERR_Set(x) (((uint32_t) (x) << MEMORY_ERROR_REGS_UCERRFLG_DMARDERR_Pos) & MEMORY_ERROR_REGS_UCERRFLG_DMARDERR_Msk) /*!< DMARDERR Set Value            */
#define MEMORY_ERROR_REGS_UCERRFLG_DMARDERR_Get(x) (((uint32_t) (x) & MEMORY_ERROR_REGS_UCERRFLG_DMARDERR_Msk) >> MEMORY_ERROR_REGS_UCERRFLG_DMARDERR_Pos) /*!< DMARDERR Get Value            */


#define MEMORY_ERROR_REGS_UCERRFLG_CPURDERR_Pos    (0U)                                                                                  /*!< CPURDERR Postion   0          */ 
#define MEMORY_ERROR_REGS_UCERRFLG_CPURDERR_Msk    (0x1U << MEMORY_ERROR_REGS_UCERRFLG_CPURDERR_Pos)                                     /*!< CPURDERR Mask      0x00000001 */
#define MEMORY_ERROR_REGS_UCERRFLG_CPURDERR_Set(x) (((uint32_t) (x) << MEMORY_ERROR_REGS_UCERRFLG_CPURDERR_Pos) & MEMORY_ERROR_REGS_UCERRFLG_CPURDERR_Msk) /*!< CPURDERR Set Value            */
#define MEMORY_ERROR_REGS_UCERRFLG_CPURDERR_Get(x) (((uint32_t) (x) & MEMORY_ERROR_REGS_UCERRFLG_CPURDERR_Msk) >> MEMORY_ERROR_REGS_UCERRFLG_CPURDERR_Pos) /*!< CPURDERR Get Value            */


/* UCERRSET bitfield */
#define MEMORY_ERROR_REGS_UCERRSET_USBADMARDERR_Pos    (3U)                                                                                  /*!< USBADMARDERR Postion   3          */ 
#define MEMORY_ERROR_REGS_UCERRSET_USBADMARDERR_Msk    (0x1U << MEMORY_ERROR_REGS_UCERRSET_USBADMARDERR_Pos)                                 /*!< USBADMARDERR Mask      0x00000008 */
#define MEMORY_ERROR_REGS_UCERRSET_USBADMARDERR_Set(x) (((uint32_t) (x) << MEMORY_ERROR_REGS_UCERRSET_USBADMARDERR_Pos) & MEMORY_ERROR_REGS_UCERRSET_USBADMARDERR_Msk) /*!< USBADMARDERR Set Value            */
#define MEMORY_ERROR_REGS_UCERRSET_USBADMARDERR_Get(x) (((uint32_t) (x) & MEMORY_ERROR_REGS_UCERRSET_USBADMARDERR_Msk) >> MEMORY_ERROR_REGS_UCERRSET_USBADMARDERR_Pos) /*!< USBADMARDERR Get Value            */


#define MEMORY_ERROR_REGS_UCERRSET_DMARDERR_Pos    (1U)                                                                                  /*!< DMARDERR Postion   1          */ 
#define MEMORY_ERROR_REGS_UCERRSET_DMARDERR_Msk    (0x1U << MEMORY_ERROR_REGS_UCERRSET_DMARDERR_Pos)                                     /*!< DMARDERR Mask      0x00000002 */
#define MEMORY_ERROR_REGS_UCERRSET_DMARDERR_Set(x) (((uint32_t) (x) << MEMORY_ERROR_REGS_UCERRSET_DMARDERR_Pos) & MEMORY_ERROR_REGS_UCERRSET_DMARDERR_Msk) /*!< DMARDERR Set Value            */
#define MEMORY_ERROR_REGS_UCERRSET_DMARDERR_Get(x) (((uint32_t) (x) & MEMORY_ERROR_REGS_UCERRSET_DMARDERR_Msk) >> MEMORY_ERROR_REGS_UCERRSET_DMARDERR_Pos) /*!< DMARDERR Get Value            */


#define MEMORY_ERROR_REGS_UCERRSET_CPURDERR_Pos    (0U)                                                                                  /*!< CPURDERR Postion   0          */ 
#define MEMORY_ERROR_REGS_UCERRSET_CPURDERR_Msk    (0x1U << MEMORY_ERROR_REGS_UCERRSET_CPURDERR_Pos)                                     /*!< CPURDERR Mask      0x00000001 */
#define MEMORY_ERROR_REGS_UCERRSET_CPURDERR_Set(x) (((uint32_t) (x) << MEMORY_ERROR_REGS_UCERRSET_CPURDERR_Pos) & MEMORY_ERROR_REGS_UCERRSET_CPURDERR_Msk) /*!< CPURDERR Set Value            */
#define MEMORY_ERROR_REGS_UCERRSET_CPURDERR_Get(x) (((uint32_t) (x) & MEMORY_ERROR_REGS_UCERRSET_CPURDERR_Msk) >> MEMORY_ERROR_REGS_UCERRSET_CPURDERR_Pos) /*!< CPURDERR Get Value            */


/* UCERRCLR bitfield */
#define MEMORY_ERROR_REGS_UCERRCLR_USBADMARDERR_Pos    (3U)                                                                                  /*!< USBADMARDERR Postion   3          */ 
#define MEMORY_ERROR_REGS_UCERRCLR_USBADMARDERR_Msk    (0x1U << MEMORY_ERROR_REGS_UCERRCLR_USBADMARDERR_Pos)                                 /*!< USBADMARDERR Mask      0x00000008 */
#define MEMORY_ERROR_REGS_UCERRCLR_USBADMARDERR_Set(x) (((uint32_t) (x) << MEMORY_ERROR_REGS_UCERRCLR_USBADMARDERR_Pos) & MEMORY_ERROR_REGS_UCERRCLR_USBADMARDERR_Msk) /*!< USBADMARDERR Set Value            */
#define MEMORY_ERROR_REGS_UCERRCLR_USBADMARDERR_Get(x) (((uint32_t) (x) & MEMORY_ERROR_REGS_UCERRCLR_USBADMARDERR_Msk) >> MEMORY_ERROR_REGS_UCERRCLR_USBADMARDERR_Pos) /*!< USBADMARDERR Get Value            */


#define MEMORY_ERROR_REGS_UCERRCLR_DMARDERR_Pos    (1U)                                                                                  /*!< DMARDERR Postion   1          */ 
#define MEMORY_ERROR_REGS_UCERRCLR_DMARDERR_Msk    (0x1U << MEMORY_ERROR_REGS_UCERRCLR_DMARDERR_Pos)                                     /*!< DMARDERR Mask      0x00000002 */
#define MEMORY_ERROR_REGS_UCERRCLR_DMARDERR_Set(x) (((uint32_t) (x) << MEMORY_ERROR_REGS_UCERRCLR_DMARDERR_Pos) & MEMORY_ERROR_REGS_UCERRCLR_DMARDERR_Msk) /*!< DMARDERR Set Value            */
#define MEMORY_ERROR_REGS_UCERRCLR_DMARDERR_Get(x) (((uint32_t) (x) & MEMORY_ERROR_REGS_UCERRCLR_DMARDERR_Msk) >> MEMORY_ERROR_REGS_UCERRCLR_DMARDERR_Pos) /*!< DMARDERR Get Value            */


#define MEMORY_ERROR_REGS_UCERRCLR_CPURDERR_Pos    (0U)                                                                                  /*!< CPURDERR Postion   0          */ 
#define MEMORY_ERROR_REGS_UCERRCLR_CPURDERR_Msk    (0x1U << MEMORY_ERROR_REGS_UCERRCLR_CPURDERR_Pos)                                     /*!< CPURDERR Mask      0x00000001 */
#define MEMORY_ERROR_REGS_UCERRCLR_CPURDERR_Set(x) (((uint32_t) (x) << MEMORY_ERROR_REGS_UCERRCLR_CPURDERR_Pos) & MEMORY_ERROR_REGS_UCERRCLR_CPURDERR_Msk) /*!< CPURDERR Set Value            */
#define MEMORY_ERROR_REGS_UCERRCLR_CPURDERR_Get(x) (((uint32_t) (x) & MEMORY_ERROR_REGS_UCERRCLR_CPURDERR_Msk) >> MEMORY_ERROR_REGS_UCERRCLR_CPURDERR_Pos) /*!< CPURDERR Get Value            */


/* UCCPUREADDR bitfield */
#define MEMORY_ERROR_REGS_UCCPUREADDR_UCCPUREADDR_Pos    (0U)                                                                                  /*!< UCCPUREADDR Postion   0          */ 
#define MEMORY_ERROR_REGS_UCCPUREADDR_UCCPUREADDR_Msk    (0xffffffffU << MEMORY_ERROR_REGS_UCCPUREADDR_UCCPUREADDR_Pos)                        /*!< UCCPUREADDR Mask      0xFFFFFFFF */
#define MEMORY_ERROR_REGS_UCCPUREADDR_UCCPUREADDR_Set(x) (((uint32_t) (x) << MEMORY_ERROR_REGS_UCCPUREADDR_UCCPUREADDR_Pos) & MEMORY_ERROR_REGS_UCCPUREADDR_UCCPUREADDR_Msk) /*!< UCCPUREADDR Set Value            */
#define MEMORY_ERROR_REGS_UCCPUREADDR_UCCPUREADDR_Get(x) (((uint32_t) (x) & MEMORY_ERROR_REGS_UCCPUREADDR_UCCPUREADDR_Msk) >> MEMORY_ERROR_REGS_UCCPUREADDR_UCCPUREADDR_Pos) /*!< UCCPUREADDR Get Value            */


/* UCDMAREADDR bitfield */
#define MEMORY_ERROR_REGS_UCDMAREADDR_UCDMAREADDR_Pos    (0U)                                                                                  /*!< UCDMAREADDR Postion   0          */ 
#define MEMORY_ERROR_REGS_UCDMAREADDR_UCDMAREADDR_Msk    (0xffffffffU << MEMORY_ERROR_REGS_UCDMAREADDR_UCDMAREADDR_Pos)                        /*!< UCDMAREADDR Mask      0xFFFFFFFF */
#define MEMORY_ERROR_REGS_UCDMAREADDR_UCDMAREADDR_Set(x) (((uint32_t) (x) << MEMORY_ERROR_REGS_UCDMAREADDR_UCDMAREADDR_Pos) & MEMORY_ERROR_REGS_UCDMAREADDR_UCDMAREADDR_Msk) /*!< UCDMAREADDR Set Value            */
#define MEMORY_ERROR_REGS_UCDMAREADDR_UCDMAREADDR_Get(x) (((uint32_t) (x) & MEMORY_ERROR_REGS_UCDMAREADDR_UCDMAREADDR_Msk) >> MEMORY_ERROR_REGS_UCDMAREADDR_UCDMAREADDR_Pos) /*!< UCDMAREADDR Get Value            */


/* UCUSBADMAREADDR bitfield */
#define MEMORY_ERROR_REGS_UCUSBADMAREADDR_UCUSBADMAREADDR_Pos    (0U)                                                                                  /*!< UCUSBADMAREADDR Postion   0          */ 
#define MEMORY_ERROR_REGS_UCUSBADMAREADDR_UCUSBADMAREADDR_Msk    (0xffffffffU << MEMORY_ERROR_REGS_UCUSBADMAREADDR_UCUSBADMAREADDR_Pos)                /*!< UCUSBADMAREADDR Mask      0xFFFFFFFF */
#define MEMORY_ERROR_REGS_UCUSBADMAREADDR_UCUSBADMAREADDR_Set(x) (((uint32_t) (x) << MEMORY_ERROR_REGS_UCUSBADMAREADDR_UCUSBADMAREADDR_Pos) & MEMORY_ERROR_REGS_UCUSBADMAREADDR_UCUSBADMAREADDR_Msk) /*!< UCUSBADMAREADDR Set Value            */
#define MEMORY_ERROR_REGS_UCUSBADMAREADDR_UCUSBADMAREADDR_Get(x) (((uint32_t) (x) & MEMORY_ERROR_REGS_UCUSBADMAREADDR_UCUSBADMAREADDR_Msk) >> MEMORY_ERROR_REGS_UCUSBADMAREADDR_UCUSBADMAREADDR_Pos) /*!< UCUSBADMAREADDR Get Value            */


/* CERRFLG bitfield */
#define MEMORY_ERROR_REGS_CERRFLG_USBADMARDERR_Pos    (3U)                                                                                  /*!< USBADMARDERR Postion   3          */ 
#define MEMORY_ERROR_REGS_CERRFLG_USBADMARDERR_Msk    (0x1U << MEMORY_ERROR_REGS_CERRFLG_USBADMARDERR_Pos)                                  /*!< USBADMARDERR Mask      0x00000008 */
#define MEMORY_ERROR_REGS_CERRFLG_USBADMARDERR_Set(x) (((uint32_t) (x) << MEMORY_ERROR_REGS_CERRFLG_USBADMARDERR_Pos) & MEMORY_ERROR_REGS_CERRFLG_USBADMARDERR_Msk) /*!< USBADMARDERR Set Value            */
#define MEMORY_ERROR_REGS_CERRFLG_USBADMARDERR_Get(x) (((uint32_t) (x) & MEMORY_ERROR_REGS_CERRFLG_USBADMARDERR_Msk) >> MEMORY_ERROR_REGS_CERRFLG_USBADMARDERR_Pos) /*!< USBADMARDERR Get Value            */


#define MEMORY_ERROR_REGS_CERRFLG_DMARDERR_Pos    (1U)                                                                                  /*!< DMARDERR Postion   1          */ 
#define MEMORY_ERROR_REGS_CERRFLG_DMARDERR_Msk    (0x1U << MEMORY_ERROR_REGS_CERRFLG_DMARDERR_Pos)                                      /*!< DMARDERR Mask      0x00000002 */
#define MEMORY_ERROR_REGS_CERRFLG_DMARDERR_Set(x) (((uint32_t) (x) << MEMORY_ERROR_REGS_CERRFLG_DMARDERR_Pos) & MEMORY_ERROR_REGS_CERRFLG_DMARDERR_Msk) /*!< DMARDERR Set Value            */
#define MEMORY_ERROR_REGS_CERRFLG_DMARDERR_Get(x) (((uint32_t) (x) & MEMORY_ERROR_REGS_CERRFLG_DMARDERR_Msk) >> MEMORY_ERROR_REGS_CERRFLG_DMARDERR_Pos) /*!< DMARDERR Get Value            */


#define MEMORY_ERROR_REGS_CERRFLG_CPURDERR_Pos    (0U)                                                                                  /*!< CPURDERR Postion   0          */ 
#define MEMORY_ERROR_REGS_CERRFLG_CPURDERR_Msk    (0x1U << MEMORY_ERROR_REGS_CERRFLG_CPURDERR_Pos)                                      /*!< CPURDERR Mask      0x00000001 */
#define MEMORY_ERROR_REGS_CERRFLG_CPURDERR_Set(x) (((uint32_t) (x) << MEMORY_ERROR_REGS_CERRFLG_CPURDERR_Pos) & MEMORY_ERROR_REGS_CERRFLG_CPURDERR_Msk) /*!< CPURDERR Set Value            */
#define MEMORY_ERROR_REGS_CERRFLG_CPURDERR_Get(x) (((uint32_t) (x) & MEMORY_ERROR_REGS_CERRFLG_CPURDERR_Msk) >> MEMORY_ERROR_REGS_CERRFLG_CPURDERR_Pos) /*!< CPURDERR Get Value            */


/* CERRSET bitfield */
#define MEMORY_ERROR_REGS_CERRSET_USBADMARDERR_Pos    (3U)                                                                                  /*!< USBADMARDERR Postion   3          */ 
#define MEMORY_ERROR_REGS_CERRSET_USBADMARDERR_Msk    (0x1U << MEMORY_ERROR_REGS_CERRSET_USBADMARDERR_Pos)                                  /*!< USBADMARDERR Mask      0x00000008 */
#define MEMORY_ERROR_REGS_CERRSET_USBADMARDERR_Set(x) (((uint32_t) (x) << MEMORY_ERROR_REGS_CERRSET_USBADMARDERR_Pos) & MEMORY_ERROR_REGS_CERRSET_USBADMARDERR_Msk) /*!< USBADMARDERR Set Value            */
#define MEMORY_ERROR_REGS_CERRSET_USBADMARDERR_Get(x) (((uint32_t) (x) & MEMORY_ERROR_REGS_CERRSET_USBADMARDERR_Msk) >> MEMORY_ERROR_REGS_CERRSET_USBADMARDERR_Pos) /*!< USBADMARDERR Get Value            */


#define MEMORY_ERROR_REGS_CERRSET_DMARDERR_Pos    (1U)                                                                                  /*!< DMARDERR Postion   1          */ 
#define MEMORY_ERROR_REGS_CERRSET_DMARDERR_Msk    (0x1U << MEMORY_ERROR_REGS_CERRSET_DMARDERR_Pos)                                      /*!< DMARDERR Mask      0x00000002 */
#define MEMORY_ERROR_REGS_CERRSET_DMARDERR_Set(x) (((uint32_t) (x) << MEMORY_ERROR_REGS_CERRSET_DMARDERR_Pos) & MEMORY_ERROR_REGS_CERRSET_DMARDERR_Msk) /*!< DMARDERR Set Value            */
#define MEMORY_ERROR_REGS_CERRSET_DMARDERR_Get(x) (((uint32_t) (x) & MEMORY_ERROR_REGS_CERRSET_DMARDERR_Msk) >> MEMORY_ERROR_REGS_CERRSET_DMARDERR_Pos) /*!< DMARDERR Get Value            */


#define MEMORY_ERROR_REGS_CERRSET_CPURDERR_Pos    (0U)                                                                                  /*!< CPURDERR Postion   0          */ 
#define MEMORY_ERROR_REGS_CERRSET_CPURDERR_Msk    (0x1U << MEMORY_ERROR_REGS_CERRSET_CPURDERR_Pos)                                      /*!< CPURDERR Mask      0x00000001 */
#define MEMORY_ERROR_REGS_CERRSET_CPURDERR_Set(x) (((uint32_t) (x) << MEMORY_ERROR_REGS_CERRSET_CPURDERR_Pos) & MEMORY_ERROR_REGS_CERRSET_CPURDERR_Msk) /*!< CPURDERR Set Value            */
#define MEMORY_ERROR_REGS_CERRSET_CPURDERR_Get(x) (((uint32_t) (x) & MEMORY_ERROR_REGS_CERRSET_CPURDERR_Msk) >> MEMORY_ERROR_REGS_CERRSET_CPURDERR_Pos) /*!< CPURDERR Get Value            */


/* CERRCLR bitfield */
#define MEMORY_ERROR_REGS_CERRCLR_USBADMARDERR_Pos    (3U)                                                                                  /*!< USBADMARDERR Postion   3          */ 
#define MEMORY_ERROR_REGS_CERRCLR_USBADMARDERR_Msk    (0x1U << MEMORY_ERROR_REGS_CERRCLR_USBADMARDERR_Pos)                                  /*!< USBADMARDERR Mask      0x00000008 */
#define MEMORY_ERROR_REGS_CERRCLR_USBADMARDERR_Set(x) (((uint32_t) (x) << MEMORY_ERROR_REGS_CERRCLR_USBADMARDERR_Pos) & MEMORY_ERROR_REGS_CERRCLR_USBADMARDERR_Msk) /*!< USBADMARDERR Set Value            */
#define MEMORY_ERROR_REGS_CERRCLR_USBADMARDERR_Get(x) (((uint32_t) (x) & MEMORY_ERROR_REGS_CERRCLR_USBADMARDERR_Msk) >> MEMORY_ERROR_REGS_CERRCLR_USBADMARDERR_Pos) /*!< USBADMARDERR Get Value            */


#define MEMORY_ERROR_REGS_CERRCLR_DMARDERR_Pos    (1U)                                                                                  /*!< DMARDERR Postion   1          */ 
#define MEMORY_ERROR_REGS_CERRCLR_DMARDERR_Msk    (0x1U << MEMORY_ERROR_REGS_CERRCLR_DMARDERR_Pos)                                      /*!< DMARDERR Mask      0x00000002 */
#define MEMORY_ERROR_REGS_CERRCLR_DMARDERR_Set(x) (((uint32_t) (x) << MEMORY_ERROR_REGS_CERRCLR_DMARDERR_Pos) & MEMORY_ERROR_REGS_CERRCLR_DMARDERR_Msk) /*!< DMARDERR Set Value            */
#define MEMORY_ERROR_REGS_CERRCLR_DMARDERR_Get(x) (((uint32_t) (x) & MEMORY_ERROR_REGS_CERRCLR_DMARDERR_Msk) >> MEMORY_ERROR_REGS_CERRCLR_DMARDERR_Pos) /*!< DMARDERR Get Value            */


#define MEMORY_ERROR_REGS_CERRCLR_CPURDERR_Pos    (0U)                                                                                  /*!< CPURDERR Postion   0          */ 
#define MEMORY_ERROR_REGS_CERRCLR_CPURDERR_Msk    (0x1U << MEMORY_ERROR_REGS_CERRCLR_CPURDERR_Pos)                                      /*!< CPURDERR Mask      0x00000001 */
#define MEMORY_ERROR_REGS_CERRCLR_CPURDERR_Set(x) (((uint32_t) (x) << MEMORY_ERROR_REGS_CERRCLR_CPURDERR_Pos) & MEMORY_ERROR_REGS_CERRCLR_CPURDERR_Msk) /*!< CPURDERR Set Value            */
#define MEMORY_ERROR_REGS_CERRCLR_CPURDERR_Get(x) (((uint32_t) (x) & MEMORY_ERROR_REGS_CERRCLR_CPURDERR_Msk) >> MEMORY_ERROR_REGS_CERRCLR_CPURDERR_Pos) /*!< CPURDERR Get Value            */


/* CCPUREADDR bitfield */
#define MEMORY_ERROR_REGS_CCPUREADDR_CCPUREADDR_Pos    (0U)                                                                                  /*!< CCPUREADDR Postion   0          */ 
#define MEMORY_ERROR_REGS_CCPUREADDR_CCPUREADDR_Msk    (0xffffffffU << MEMORY_ERROR_REGS_CCPUREADDR_CCPUREADDR_Pos)                          /*!< CCPUREADDR Mask      0xFFFFFFFF */
#define MEMORY_ERROR_REGS_CCPUREADDR_CCPUREADDR_Set(x) (((uint32_t) (x) << MEMORY_ERROR_REGS_CCPUREADDR_CCPUREADDR_Pos) & MEMORY_ERROR_REGS_CCPUREADDR_CCPUREADDR_Msk) /*!< CCPUREADDR Set Value            */
#define MEMORY_ERROR_REGS_CCPUREADDR_CCPUREADDR_Get(x) (((uint32_t) (x) & MEMORY_ERROR_REGS_CCPUREADDR_CCPUREADDR_Msk) >> MEMORY_ERROR_REGS_CCPUREADDR_CCPUREADDR_Pos) /*!< CCPUREADDR Get Value            */


/* CDMAREADDR bitfield */
#define MEMORY_ERROR_REGS_CDMAREADDR_CDMAREADDR_Pos    (0U)                                                                                  /*!< CDMAREADDR Postion   0          */ 
#define MEMORY_ERROR_REGS_CDMAREADDR_CDMAREADDR_Msk    (0xffffffffU << MEMORY_ERROR_REGS_CDMAREADDR_CDMAREADDR_Pos)                          /*!< CDMAREADDR Mask      0xFFFFFFFF */
#define MEMORY_ERROR_REGS_CDMAREADDR_CDMAREADDR_Set(x) (((uint32_t) (x) << MEMORY_ERROR_REGS_CDMAREADDR_CDMAREADDR_Pos) & MEMORY_ERROR_REGS_CDMAREADDR_CDMAREADDR_Msk) /*!< CDMAREADDR Set Value            */
#define MEMORY_ERROR_REGS_CDMAREADDR_CDMAREADDR_Get(x) (((uint32_t) (x) & MEMORY_ERROR_REGS_CDMAREADDR_CDMAREADDR_Msk) >> MEMORY_ERROR_REGS_CDMAREADDR_CDMAREADDR_Pos) /*!< CDMAREADDR Get Value            */


/* CUSBADMAREADDR bitfield */
#define MEMORY_ERROR_REGS_CUSBADMAREADDR_CUSBADMAREADDR_Pos    (0U)                                                                                  /*!< CUSBADMAREADDR Postion   0          */ 
#define MEMORY_ERROR_REGS_CUSBADMAREADDR_CUSBADMAREADDR_Msk    (0xffffffffU << MEMORY_ERROR_REGS_CUSBADMAREADDR_CUSBADMAREADDR_Pos)                  /*!< CUSBADMAREADDR Mask      0xFFFFFFFF */
#define MEMORY_ERROR_REGS_CUSBADMAREADDR_CUSBADMAREADDR_Set(x) (((uint32_t) (x) << MEMORY_ERROR_REGS_CUSBADMAREADDR_CUSBADMAREADDR_Pos) & MEMORY_ERROR_REGS_CUSBADMAREADDR_CUSBADMAREADDR_Msk) /*!< CUSBADMAREADDR Set Value            */
#define MEMORY_ERROR_REGS_CUSBADMAREADDR_CUSBADMAREADDR_Get(x) (((uint32_t) (x) & MEMORY_ERROR_REGS_CUSBADMAREADDR_CUSBADMAREADDR_Msk) >> MEMORY_ERROR_REGS_CUSBADMAREADDR_CUSBADMAREADDR_Pos) /*!< CUSBADMAREADDR Get Value            */


/* CERRCNT bitfield */
#define MEMORY_ERROR_REGS_CERRCNT_CERRCNT_Pos    (0U)                                                                                  /*!< CERRCNT Postion   0          */ 
#define MEMORY_ERROR_REGS_CERRCNT_CERRCNT_Msk    (0xffffffffU << MEMORY_ERROR_REGS_CERRCNT_CERRCNT_Pos)                                /*!< CERRCNT Mask      0xFFFFFFFF */
#define MEMORY_ERROR_REGS_CERRCNT_CERRCNT_Set(x) (((uint32_t) (x) << MEMORY_ERROR_REGS_CERRCNT_CERRCNT_Pos) & MEMORY_ERROR_REGS_CERRCNT_CERRCNT_Msk) /*!< CERRCNT Set Value            */
#define MEMORY_ERROR_REGS_CERRCNT_CERRCNT_Get(x) (((uint32_t) (x) & MEMORY_ERROR_REGS_CERRCNT_CERRCNT_Msk) >> MEMORY_ERROR_REGS_CERRCNT_CERRCNT_Pos) /*!< CERRCNT Get Value            */


/* CERRTHRES bitfield */
#define MEMORY_ERROR_REGS_CERRTHRES_CERRTHRES_Pos    (0U)                                                                                  /*!< CERRTHRES Postion   0          */ 
#define MEMORY_ERROR_REGS_CERRTHRES_CERRTHRES_Msk    (0xffffffffU << MEMORY_ERROR_REGS_CERRTHRES_CERRTHRES_Pos)                            /*!< CERRTHRES Mask      0xFFFFFFFF */
#define MEMORY_ERROR_REGS_CERRTHRES_CERRTHRES_Set(x) (((uint32_t) (x) << MEMORY_ERROR_REGS_CERRTHRES_CERRTHRES_Pos) & MEMORY_ERROR_REGS_CERRTHRES_CERRTHRES_Msk) /*!< CERRTHRES Set Value            */
#define MEMORY_ERROR_REGS_CERRTHRES_CERRTHRES_Get(x) (((uint32_t) (x) & MEMORY_ERROR_REGS_CERRTHRES_CERRTHRES_Msk) >> MEMORY_ERROR_REGS_CERRTHRES_CERRTHRES_Pos) /*!< CERRTHRES Get Value            */


/* CEINTFLG bitfield */
#define MEMORY_ERROR_REGS_CEINTFLG_CEINTFLAG_Pos    (0U)                                                                                  /*!< CEINTFLAG Postion   0          */ 
#define MEMORY_ERROR_REGS_CEINTFLG_CEINTFLAG_Msk    (0x1U << MEMORY_ERROR_REGS_CEINTFLG_CEINTFLAG_Pos)                                    /*!< CEINTFLAG Mask      0x00000001 */
#define MEMORY_ERROR_REGS_CEINTFLG_CEINTFLAG_Set(x) (((uint32_t) (x) << MEMORY_ERROR_REGS_CEINTFLG_CEINTFLAG_Pos) & MEMORY_ERROR_REGS_CEINTFLG_CEINTFLAG_Msk) /*!< CEINTFLAG Set Value            */
#define MEMORY_ERROR_REGS_CEINTFLG_CEINTFLAG_Get(x) (((uint32_t) (x) & MEMORY_ERROR_REGS_CEINTFLG_CEINTFLAG_Msk) >> MEMORY_ERROR_REGS_CEINTFLG_CEINTFLAG_Pos) /*!< CEINTFLAG Get Value            */


/* CEINTCLR bitfield */
#define MEMORY_ERROR_REGS_CEINTCLR_CEINTCLR_Pos    (0U)                                                                                  /*!< CEINTCLR Postion   0          */ 
#define MEMORY_ERROR_REGS_CEINTCLR_CEINTCLR_Msk    (0x1U << MEMORY_ERROR_REGS_CEINTCLR_CEINTCLR_Pos)                                     /*!< CEINTCLR Mask      0x00000001 */
#define MEMORY_ERROR_REGS_CEINTCLR_CEINTCLR_Set(x) (((uint32_t) (x) << MEMORY_ERROR_REGS_CEINTCLR_CEINTCLR_Pos) & MEMORY_ERROR_REGS_CEINTCLR_CEINTCLR_Msk) /*!< CEINTCLR Set Value            */
#define MEMORY_ERROR_REGS_CEINTCLR_CEINTCLR_Get(x) (((uint32_t) (x) & MEMORY_ERROR_REGS_CEINTCLR_CEINTCLR_Msk) >> MEMORY_ERROR_REGS_CEINTCLR_CEINTCLR_Pos) /*!< CEINTCLR Get Value            */


/* CEINTSET bitfield */
#define MEMORY_ERROR_REGS_CEINTSET_CEINTSET_Pos    (0U)                                                                                  /*!< CEINTSET Postion   0          */ 
#define MEMORY_ERROR_REGS_CEINTSET_CEINTSET_Msk    (0x1U << MEMORY_ERROR_REGS_CEINTSET_CEINTSET_Pos)                                     /*!< CEINTSET Mask      0x00000001 */
#define MEMORY_ERROR_REGS_CEINTSET_CEINTSET_Set(x) (((uint32_t) (x) << MEMORY_ERROR_REGS_CEINTSET_CEINTSET_Pos) & MEMORY_ERROR_REGS_CEINTSET_CEINTSET_Msk) /*!< CEINTSET Set Value            */
#define MEMORY_ERROR_REGS_CEINTSET_CEINTSET_Get(x) (((uint32_t) (x) & MEMORY_ERROR_REGS_CEINTSET_CEINTSET_Msk) >> MEMORY_ERROR_REGS_CEINTSET_CEINTSET_Pos) /*!< CEINTSET Get Value            */


/* CEINTEN bitfield */
#define MEMORY_ERROR_REGS_CEINTEN_CEINTEN_Pos    (0U)                                                                                  /*!< CEINTEN Postion   0          */ 
#define MEMORY_ERROR_REGS_CEINTEN_CEINTEN_Msk    (0x1U << MEMORY_ERROR_REGS_CEINTEN_CEINTEN_Pos)                                       /*!< CEINTEN Mask      0x00000001 */
#define MEMORY_ERROR_REGS_CEINTEN_CEINTEN_Set(x) (((uint32_t) (x) << MEMORY_ERROR_REGS_CEINTEN_CEINTEN_Pos) & MEMORY_ERROR_REGS_CEINTEN_CEINTEN_Msk) /*!< CEINTEN Set Value            */
#define MEMORY_ERROR_REGS_CEINTEN_CEINTEN_Get(x) (((uint32_t) (x) & MEMORY_ERROR_REGS_CEINTEN_CEINTEN_Msk) >> MEMORY_ERROR_REGS_CEINTEN_CEINTEN_Pos) /*!< CEINTEN Get Value            */


/* CERRINTEN bitfield */
#define MEMORY_ERROR_REGS_CERRINTEN_USBADMARDERRINTEN_Pos    (3U)                                                                                  /*!< USBADMARDERRINTEN Postion   3          */ 
#define MEMORY_ERROR_REGS_CERRINTEN_USBADMARDERRINTEN_Msk    (0x1U << MEMORY_ERROR_REGS_CERRINTEN_USBADMARDERRINTEN_Pos)                           /*!< USBADMARDERRINTEN Mask      0x00000008 */
#define MEMORY_ERROR_REGS_CERRINTEN_USBADMARDERRINTEN_Set(x) (((uint32_t) (x) << MEMORY_ERROR_REGS_CERRINTEN_USBADMARDERRINTEN_Pos) & MEMORY_ERROR_REGS_CERRINTEN_USBADMARDERRINTEN_Msk) /*!< USBADMARDERRINTEN Set Value            */
#define MEMORY_ERROR_REGS_CERRINTEN_USBADMARDERRINTEN_Get(x) (((uint32_t) (x) & MEMORY_ERROR_REGS_CERRINTEN_USBADMARDERRINTEN_Msk) >> MEMORY_ERROR_REGS_CERRINTEN_USBADMARDERRINTEN_Pos) /*!< USBADMARDERRINTEN Get Value            */


#define MEMORY_ERROR_REGS_CERRINTEN_DMARDERRINTEN_Pos    (1U)                                                                                  /*!< DMARDERRINTEN Postion   1          */ 
#define MEMORY_ERROR_REGS_CERRINTEN_DMARDERRINTEN_Msk    (0x1U << MEMORY_ERROR_REGS_CERRINTEN_DMARDERRINTEN_Pos)                               /*!< DMARDERRINTEN Mask      0x00000002 */
#define MEMORY_ERROR_REGS_CERRINTEN_DMARDERRINTEN_Set(x) (((uint32_t) (x) << MEMORY_ERROR_REGS_CERRINTEN_DMARDERRINTEN_Pos) & MEMORY_ERROR_REGS_CERRINTEN_DMARDERRINTEN_Msk) /*!< DMARDERRINTEN Set Value            */
#define MEMORY_ERROR_REGS_CERRINTEN_DMARDERRINTEN_Get(x) (((uint32_t) (x) & MEMORY_ERROR_REGS_CERRINTEN_DMARDERRINTEN_Msk) >> MEMORY_ERROR_REGS_CERRINTEN_DMARDERRINTEN_Pos) /*!< DMARDERRINTEN Get Value            */


#define MEMORY_ERROR_REGS_CERRINTEN_CPURDERRINTEN_Pos    (0U)                                                                                  /*!< CPURDERRINTEN Postion   0          */ 
#define MEMORY_ERROR_REGS_CERRINTEN_CPURDERRINTEN_Msk    (0x1U << MEMORY_ERROR_REGS_CERRINTEN_CPURDERRINTEN_Pos)                               /*!< CPURDERRINTEN Mask      0x00000001 */
#define MEMORY_ERROR_REGS_CERRINTEN_CPURDERRINTEN_Set(x) (((uint32_t) (x) << MEMORY_ERROR_REGS_CERRINTEN_CPURDERRINTEN_Pos) & MEMORY_ERROR_REGS_CERRINTEN_CPURDERRINTEN_Msk) /*!< CPURDERRINTEN Set Value            */
#define MEMORY_ERROR_REGS_CERRINTEN_CPURDERRINTEN_Get(x) (((uint32_t) (x) & MEMORY_ERROR_REGS_CERRINTEN_CPURDERRINTEN_Msk) >> MEMORY_ERROR_REGS_CERRINTEN_CPURDERRINTEN_Pos) /*!< CPURDERRINTEN Get Value            */


/* UCERRINTEN bitfield */
#define MEMORY_ERROR_REGS_UCERRINTEN_USBADMARDERRINTEN_Pos    (3U)                                                                                  /*!< USBADMARDERRINTEN Postion   3          */ 
#define MEMORY_ERROR_REGS_UCERRINTEN_USBADMARDERRINTEN_Msk    (0x1U << MEMORY_ERROR_REGS_UCERRINTEN_USBADMARDERRINTEN_Pos)                          /*!< USBADMARDERRINTEN Mask      0x00000008 */
#define MEMORY_ERROR_REGS_UCERRINTEN_USBADMARDERRINTEN_Set(x) (((uint32_t) (x) << MEMORY_ERROR_REGS_UCERRINTEN_USBADMARDERRINTEN_Pos) & MEMORY_ERROR_REGS_UCERRINTEN_USBADMARDERRINTEN_Msk) /*!< USBADMARDERRINTEN Set Value            */
#define MEMORY_ERROR_REGS_UCERRINTEN_USBADMARDERRINTEN_Get(x) (((uint32_t) (x) & MEMORY_ERROR_REGS_UCERRINTEN_USBADMARDERRINTEN_Msk) >> MEMORY_ERROR_REGS_UCERRINTEN_USBADMARDERRINTEN_Pos) /*!< USBADMARDERRINTEN Get Value            */


#define MEMORY_ERROR_REGS_UCERRINTEN_DMARDERRINTEN_Pos    (1U)                                                                                  /*!< DMARDERRINTEN Postion   1          */ 
#define MEMORY_ERROR_REGS_UCERRINTEN_DMARDERRINTEN_Msk    (0x1U << MEMORY_ERROR_REGS_UCERRINTEN_DMARDERRINTEN_Pos)                              /*!< DMARDERRINTEN Mask      0x00000002 */
#define MEMORY_ERROR_REGS_UCERRINTEN_DMARDERRINTEN_Set(x) (((uint32_t) (x) << MEMORY_ERROR_REGS_UCERRINTEN_DMARDERRINTEN_Pos) & MEMORY_ERROR_REGS_UCERRINTEN_DMARDERRINTEN_Msk) /*!< DMARDERRINTEN Set Value            */
#define MEMORY_ERROR_REGS_UCERRINTEN_DMARDERRINTEN_Get(x) (((uint32_t) (x) & MEMORY_ERROR_REGS_UCERRINTEN_DMARDERRINTEN_Msk) >> MEMORY_ERROR_REGS_UCERRINTEN_DMARDERRINTEN_Pos) /*!< DMARDERRINTEN Get Value            */


#define MEMORY_ERROR_REGS_UCERRINTEN_CPURDERRINTEN_Pos    (0U)                                                                                  /*!< CPURDERRINTEN Postion   0          */ 
#define MEMORY_ERROR_REGS_UCERRINTEN_CPURDERRINTEN_Msk    (0x1U << MEMORY_ERROR_REGS_UCERRINTEN_CPURDERRINTEN_Pos)                              /*!< CPURDERRINTEN Mask      0x00000001 */
#define MEMORY_ERROR_REGS_UCERRINTEN_CPURDERRINTEN_Set(x) (((uint32_t) (x) << MEMORY_ERROR_REGS_UCERRINTEN_CPURDERRINTEN_Pos) & MEMORY_ERROR_REGS_UCERRINTEN_CPURDERRINTEN_Msk) /*!< CPURDERRINTEN Set Value            */
#define MEMORY_ERROR_REGS_UCERRINTEN_CPURDERRINTEN_Get(x) (((uint32_t) (x) & MEMORY_ERROR_REGS_UCERRINTEN_CPURDERRINTEN_Msk) >> MEMORY_ERROR_REGS_UCERRINTEN_CPURDERRINTEN_Pos) /*!< CPURDERRINTEN Get Value            */


/* CPUID bitfield */
#define CPU_ID_REGS_CPUID_CPUID_Pos    (0U)                                                                                  /*!< CPUID Postion   0          */ 
#define CPU_ID_REGS_CPUID_CPUID_Msk    (0xffU << CPU_ID_REGS_CPUID_CPUID_Pos)                                                /*!< CPUID Mask      0x000000FF */
#define CPU_ID_REGS_CPUID_CPUID_Set(x) (((uint32_t) (x) << CPU_ID_REGS_CPUID_CPUID_Pos) & CPU_ID_REGS_CPUID_CPUID_Msk)       /*!< CPUID Set Value            */
#define CPU_ID_REGS_CPUID_CPUID_Get(x) (((uint32_t) (x) & CPU_ID_REGS_CPUID_CPUID_Msk) >> CPU_ID_REGS_CPUID_CPUID_Pos)       /*!< CPUID Get Value            */


/* UID_PSRAND0 bitfield */
#define UID_REGS_UID_PSRAND0_RANDOMID_Pos    (0U)                                                                                  /*!< RANDOMID Postion   0          */ 
#define UID_REGS_UID_PSRAND0_RANDOMID_Msk    (0xffffffffU << UID_REGS_UID_PSRAND0_RANDOMID_Pos)                                    /*!< RANDOMID Mask      0xFFFFFFFF */
#define UID_REGS_UID_PSRAND0_RANDOMID_Set(x) (((uint32_t) (x) << UID_REGS_UID_PSRAND0_RANDOMID_Pos) & UID_REGS_UID_PSRAND0_RANDOMID_Msk) /*!< RANDOMID Set Value            */
#define UID_REGS_UID_PSRAND0_RANDOMID_Get(x) (((uint32_t) (x) & UID_REGS_UID_PSRAND0_RANDOMID_Msk) >> UID_REGS_UID_PSRAND0_RANDOMID_Pos) /*!< RANDOMID Get Value            */


/* UID_PSRAND1 bitfield */
#define UID_REGS_UID_PSRAND1_RANDOMID_Pos    (0U)                                                                                  /*!< RANDOMID Postion   0          */ 
#define UID_REGS_UID_PSRAND1_RANDOMID_Msk    (0xffffffffU << UID_REGS_UID_PSRAND1_RANDOMID_Pos)                                    /*!< RANDOMID Mask      0xFFFFFFFF */
#define UID_REGS_UID_PSRAND1_RANDOMID_Set(x) (((uint32_t) (x) << UID_REGS_UID_PSRAND1_RANDOMID_Pos) & UID_REGS_UID_PSRAND1_RANDOMID_Msk) /*!< RANDOMID Set Value            */
#define UID_REGS_UID_PSRAND1_RANDOMID_Get(x) (((uint32_t) (x) & UID_REGS_UID_PSRAND1_RANDOMID_Msk) >> UID_REGS_UID_PSRAND1_RANDOMID_Pos) /*!< RANDOMID Get Value            */


/* UID_PSRAND2 bitfield */
#define UID_REGS_UID_PSRAND2_RANDOMID_Pos    (0U)                                                                                  /*!< RANDOMID Postion   0          */ 
#define UID_REGS_UID_PSRAND2_RANDOMID_Msk    (0xffffffffU << UID_REGS_UID_PSRAND2_RANDOMID_Pos)                                    /*!< RANDOMID Mask      0xFFFFFFFF */
#define UID_REGS_UID_PSRAND2_RANDOMID_Set(x) (((uint32_t) (x) << UID_REGS_UID_PSRAND2_RANDOMID_Pos) & UID_REGS_UID_PSRAND2_RANDOMID_Msk) /*!< RANDOMID Set Value            */
#define UID_REGS_UID_PSRAND2_RANDOMID_Get(x) (((uint32_t) (x) & UID_REGS_UID_PSRAND2_RANDOMID_Msk) >> UID_REGS_UID_PSRAND2_RANDOMID_Pos) /*!< RANDOMID Get Value            */


/* UID_PSRAND3 bitfield */
#define UID_REGS_UID_PSRAND3_RANDOMID_Pos    (0U)                                                                                  /*!< RANDOMID Postion   0          */ 
#define UID_REGS_UID_PSRAND3_RANDOMID_Msk    (0xffffffffU << UID_REGS_UID_PSRAND3_RANDOMID_Pos)                                    /*!< RANDOMID Mask      0xFFFFFFFF */
#define UID_REGS_UID_PSRAND3_RANDOMID_Set(x) (((uint32_t) (x) << UID_REGS_UID_PSRAND3_RANDOMID_Pos) & UID_REGS_UID_PSRAND3_RANDOMID_Msk) /*!< RANDOMID Set Value            */
#define UID_REGS_UID_PSRAND3_RANDOMID_Get(x) (((uint32_t) (x) & UID_REGS_UID_PSRAND3_RANDOMID_Msk) >> UID_REGS_UID_PSRAND3_RANDOMID_Pos) /*!< RANDOMID Get Value            */


/* UID_PSRAND4 bitfield */
#define UID_REGS_UID_PSRAND4_RANDOMID_Pos    (0U)                                                                                  /*!< RANDOMID Postion   0          */ 
#define UID_REGS_UID_PSRAND4_RANDOMID_Msk    (0xffffffffU << UID_REGS_UID_PSRAND4_RANDOMID_Pos)                                    /*!< RANDOMID Mask      0xFFFFFFFF */
#define UID_REGS_UID_PSRAND4_RANDOMID_Set(x) (((uint32_t) (x) << UID_REGS_UID_PSRAND4_RANDOMID_Pos) & UID_REGS_UID_PSRAND4_RANDOMID_Msk) /*!< RANDOMID Set Value            */
#define UID_REGS_UID_PSRAND4_RANDOMID_Get(x) (((uint32_t) (x) & UID_REGS_UID_PSRAND4_RANDOMID_Msk) >> UID_REGS_UID_PSRAND4_RANDOMID_Pos) /*!< RANDOMID Get Value            */


/* UID_PSRAND5 bitfield */
#define UID_REGS_UID_PSRAND5_RANDOMID_Pos    (0U)                                                                                  /*!< RANDOMID Postion   0          */ 
#define UID_REGS_UID_PSRAND5_RANDOMID_Msk    (0xffffffffU << UID_REGS_UID_PSRAND5_RANDOMID_Pos)                                    /*!< RANDOMID Mask      0xFFFFFFFF */
#define UID_REGS_UID_PSRAND5_RANDOMID_Set(x) (((uint32_t) (x) << UID_REGS_UID_PSRAND5_RANDOMID_Pos) & UID_REGS_UID_PSRAND5_RANDOMID_Msk) /*!< RANDOMID Set Value            */
#define UID_REGS_UID_PSRAND5_RANDOMID_Get(x) (((uint32_t) (x) & UID_REGS_UID_PSRAND5_RANDOMID_Msk) >> UID_REGS_UID_PSRAND5_RANDOMID_Pos) /*!< RANDOMID Get Value            */


/* UID_UNIQUE bitfield */
#define UID_REGS_UID_UNIQUE_UNIQUEID_Pos    (0U)                                                                                  /*!< UNIQUEID Postion   0          */ 
#define UID_REGS_UID_UNIQUE_UNIQUEID_Msk    (0xffffffffU << UID_REGS_UID_UNIQUE_UNIQUEID_Pos)                                     /*!< UNIQUEID Mask      0xFFFFFFFF */
#define UID_REGS_UID_UNIQUE_UNIQUEID_Set(x) (((uint32_t) (x) << UID_REGS_UID_UNIQUE_UNIQUEID_Pos) & UID_REGS_UID_UNIQUE_UNIQUEID_Msk) /*!< UNIQUEID Set Value            */
#define UID_REGS_UID_UNIQUE_UNIQUEID_Get(x) (((uint32_t) (x) & UID_REGS_UID_UNIQUE_UNIQUEID_Msk) >> UID_REGS_UID_UNIQUE_UNIQUEID_Pos) /*!< UNIQUEID Get Value            */


/* UID_CHECKSUM bitfield */
#define UID_REGS_UID_CHECKSUM_CHECKSUM_Pos    (0U)                                                                                  /*!< CHECKSUM Postion   0          */ 
#define UID_REGS_UID_CHECKSUM_CHECKSUM_Msk    (0xffffffffU << UID_REGS_UID_CHECKSUM_CHECKSUM_Pos)                                   /*!< CHECKSUM Mask      0xFFFFFFFF */
#define UID_REGS_UID_CHECKSUM_CHECKSUM_Set(x) (((uint32_t) (x) << UID_REGS_UID_CHECKSUM_CHECKSUM_Pos) & UID_REGS_UID_CHECKSUM_CHECKSUM_Msk) /*!< CHECKSUM Set Value            */
#define UID_REGS_UID_CHECKSUM_CHECKSUM_Get(x) (((uint32_t) (x) & UID_REGS_UID_CHECKSUM_CHECKSUM_Msk) >> UID_REGS_UID_CHECKSUM_CHECKSUM_Pos) /*!< CHECKSUM Get Value            */


/* DUMMY_REG0 bitfield */
#define DUMMY_REGS_DUMMY_REG0_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG0_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG0_DUMMY_REG_Pos)                                  /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG0_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG0_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG0_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG0_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG0_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG0_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG1 bitfield */
#define DUMMY_REGS_DUMMY_REG1_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG1_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG1_DUMMY_REG_Pos)                                  /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG1_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG1_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG1_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG1_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG1_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG1_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG2 bitfield */
#define DUMMY_REGS_DUMMY_REG2_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG2_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG2_DUMMY_REG_Pos)                                  /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG2_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG2_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG2_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG2_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG2_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG2_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG3 bitfield */
#define DUMMY_REGS_DUMMY_REG3_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG3_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG3_DUMMY_REG_Pos)                                  /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG3_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG3_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG3_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG3_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG3_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG3_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG4 bitfield */
#define DUMMY_REGS_DUMMY_REG4_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG4_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG4_DUMMY_REG_Pos)                                  /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG4_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG4_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG4_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG4_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG4_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG4_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG5 bitfield */
#define DUMMY_REGS_DUMMY_REG5_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG5_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG5_DUMMY_REG_Pos)                                  /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG5_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG5_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG5_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG5_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG5_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG5_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG6 bitfield */
#define DUMMY_REGS_DUMMY_REG6_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG6_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG6_DUMMY_REG_Pos)                                  /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG6_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG6_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG6_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG6_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG6_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG6_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG7 bitfield */
#define DUMMY_REGS_DUMMY_REG7_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG7_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG7_DUMMY_REG_Pos)                                  /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG7_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG7_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG7_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG7_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG7_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG7_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG8 bitfield */
#define DUMMY_REGS_DUMMY_REG8_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG8_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG8_DUMMY_REG_Pos)                                  /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG8_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG8_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG8_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG8_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG8_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG8_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG9 bitfield */
#define DUMMY_REGS_DUMMY_REG9_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG9_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG9_DUMMY_REG_Pos)                                  /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG9_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG9_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG9_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG9_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG9_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG9_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG10 bitfield */
#define DUMMY_REGS_DUMMY_REG10_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG10_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG10_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG10_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG10_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG10_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG10_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG10_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG10_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG11 bitfield */
#define DUMMY_REGS_DUMMY_REG11_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG11_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG11_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG11_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG11_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG11_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG11_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG11_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG11_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG12 bitfield */
#define DUMMY_REGS_DUMMY_REG12_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG12_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG12_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG12_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG12_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG12_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG12_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG12_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG12_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG13 bitfield */
#define DUMMY_REGS_DUMMY_REG13_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG13_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG13_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG13_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG13_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG13_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG13_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG13_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG13_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG14 bitfield */
#define DUMMY_REGS_DUMMY_REG14_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG14_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG14_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG14_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG14_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG14_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG14_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG14_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG14_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG15 bitfield */
#define DUMMY_REGS_DUMMY_REG15_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG15_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG15_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG15_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG15_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG15_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG15_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG15_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG15_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG16 bitfield */
#define DUMMY_REGS_DUMMY_REG16_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG16_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG16_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG16_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG16_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG16_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG16_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG16_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG16_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG17 bitfield */
#define DUMMY_REGS_DUMMY_REG17_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG17_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG17_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG17_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG17_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG17_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG17_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG17_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG17_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG18 bitfield */
#define DUMMY_REGS_DUMMY_REG18_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG18_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG18_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG18_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG18_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG18_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG18_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG18_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG18_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG19 bitfield */
#define DUMMY_REGS_DUMMY_REG19_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG19_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG19_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG19_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG19_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG19_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG19_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG19_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG19_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG20 bitfield */
#define DUMMY_REGS_DUMMY_REG20_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG20_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG20_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG20_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG20_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG20_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG20_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG20_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG20_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG21 bitfield */
#define DUMMY_REGS_DUMMY_REG21_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG21_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG21_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG21_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG21_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG21_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG21_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG21_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG21_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG22 bitfield */
#define DUMMY_REGS_DUMMY_REG22_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG22_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG22_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG22_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG22_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG22_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG22_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG22_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG22_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG23 bitfield */
#define DUMMY_REGS_DUMMY_REG23_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG23_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG23_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG23_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG23_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG23_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG23_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG23_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG23_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG24 bitfield */
#define DUMMY_REGS_DUMMY_REG24_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG24_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG24_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG24_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG24_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG24_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG24_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG24_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG24_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG25 bitfield */
#define DUMMY_REGS_DUMMY_REG25_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG25_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG25_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG25_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG25_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG25_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG25_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG25_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG25_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG26 bitfield */
#define DUMMY_REGS_DUMMY_REG26_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG26_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG26_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG26_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG26_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG26_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG26_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG26_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG26_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG27 bitfield */
#define DUMMY_REGS_DUMMY_REG27_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG27_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG27_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG27_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG27_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG27_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG27_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG27_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG27_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG28 bitfield */
#define DUMMY_REGS_DUMMY_REG28_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG28_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG28_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG28_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG28_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG28_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG28_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG28_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG28_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG29 bitfield */
#define DUMMY_REGS_DUMMY_REG29_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG29_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG29_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG29_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG29_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG29_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG29_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG29_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG29_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG30 bitfield */
#define DUMMY_REGS_DUMMY_REG30_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG30_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG30_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG30_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG30_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG30_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG30_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG30_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG30_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG31 bitfield */
#define DUMMY_REGS_DUMMY_REG31_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG31_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG31_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG31_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG31_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG31_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG31_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG31_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG31_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG32 bitfield */
#define DUMMY_REGS_DUMMY_REG32_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG32_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG32_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG32_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG32_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG32_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG32_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG32_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG32_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG33 bitfield */
#define DUMMY_REGS_DUMMY_REG33_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG33_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG33_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG33_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG33_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG33_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG33_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG33_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG33_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG34 bitfield */
#define DUMMY_REGS_DUMMY_REG34_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG34_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG34_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG34_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG34_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG34_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG34_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG34_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG34_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG35 bitfield */
#define DUMMY_REGS_DUMMY_REG35_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG35_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG35_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG35_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG35_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG35_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG35_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG35_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG35_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG36 bitfield */
#define DUMMY_REGS_DUMMY_REG36_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG36_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG36_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG36_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG36_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG36_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG36_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG36_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG36_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG37 bitfield */
#define DUMMY_REGS_DUMMY_REG37_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG37_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG37_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG37_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG37_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG37_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG37_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG37_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG37_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG38 bitfield */
#define DUMMY_REGS_DUMMY_REG38_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG38_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG38_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG38_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG38_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG38_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG38_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG38_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG38_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG39 bitfield */
#define DUMMY_REGS_DUMMY_REG39_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG39_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG39_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG39_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG39_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG39_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG39_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG39_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG39_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG40 bitfield */
#define DUMMY_REGS_DUMMY_REG40_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG40_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG40_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG40_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG40_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG40_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG40_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG40_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG40_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG41 bitfield */
#define DUMMY_REGS_DUMMY_REG41_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG41_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG41_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG41_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG41_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG41_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG41_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG41_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG41_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG42 bitfield */
#define DUMMY_REGS_DUMMY_REG42_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG42_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG42_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG42_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG42_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG42_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG42_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG42_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG42_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG43 bitfield */
#define DUMMY_REGS_DUMMY_REG43_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG43_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG43_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG43_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG43_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG43_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG43_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG43_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG43_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG44 bitfield */
#define DUMMY_REGS_DUMMY_REG44_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG44_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG44_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG44_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG44_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG44_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG44_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG44_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG44_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG45 bitfield */
#define DUMMY_REGS_DUMMY_REG45_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG45_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG45_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG45_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG45_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG45_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG45_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG45_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG45_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG46 bitfield */
#define DUMMY_REGS_DUMMY_REG46_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG46_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG46_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG46_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG46_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG46_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG46_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG46_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG46_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG47 bitfield */
#define DUMMY_REGS_DUMMY_REG47_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG47_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG47_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG47_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG47_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG47_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG47_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG47_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG47_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG48 bitfield */
#define DUMMY_REGS_DUMMY_REG48_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG48_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG48_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG48_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG48_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG48_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG48_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG48_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG48_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG49 bitfield */
#define DUMMY_REGS_DUMMY_REG49_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG49_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG49_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG49_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG49_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG49_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG49_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG49_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG49_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG50 bitfield */
#define DUMMY_REGS_DUMMY_REG50_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG50_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG50_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG50_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG50_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG50_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG50_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG50_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG50_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG51 bitfield */
#define DUMMY_REGS_DUMMY_REG51_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG51_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG51_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG51_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG51_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG51_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG51_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG51_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG51_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG52 bitfield */
#define DUMMY_REGS_DUMMY_REG52_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG52_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG52_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG52_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG52_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG52_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG52_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG52_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG52_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG53 bitfield */
#define DUMMY_REGS_DUMMY_REG53_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG53_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG53_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG53_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG53_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG53_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG53_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG53_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG53_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG54 bitfield */
#define DUMMY_REGS_DUMMY_REG54_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG54_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG54_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG54_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG54_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG54_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG54_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG54_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG54_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG55 bitfield */
#define DUMMY_REGS_DUMMY_REG55_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG55_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG55_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG55_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG55_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG55_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG55_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG55_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG55_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG56 bitfield */
#define DUMMY_REGS_DUMMY_REG56_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG56_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG56_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG56_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG56_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG56_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG56_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG56_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG56_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG57 bitfield */
#define DUMMY_REGS_DUMMY_REG57_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG57_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG57_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG57_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG57_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG57_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG57_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG57_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG57_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG58 bitfield */
#define DUMMY_REGS_DUMMY_REG58_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG58_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG58_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG58_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG58_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG58_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG58_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG58_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG58_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG59 bitfield */
#define DUMMY_REGS_DUMMY_REG59_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG59_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG59_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG59_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG59_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG59_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG59_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG59_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG59_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG60 bitfield */
#define DUMMY_REGS_DUMMY_REG60_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG60_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG60_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG60_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG60_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG60_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG60_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG60_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG60_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG61 bitfield */
#define DUMMY_REGS_DUMMY_REG61_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG61_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG61_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG61_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG61_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG61_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG61_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG61_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG61_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG62 bitfield */
#define DUMMY_REGS_DUMMY_REG62_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG62_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG62_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG62_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG62_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG62_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG62_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG62_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG62_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/* DUMMY_REG63 bitfield */
#define DUMMY_REGS_DUMMY_REG63_DUMMY_REG_Pos    (0U)                                                                                  /*!< DUMMY_REG Postion   0          */ 
#define DUMMY_REGS_DUMMY_REG63_DUMMY_REG_Msk    (0xffffffffU << DUMMY_REGS_DUMMY_REG63_DUMMY_REG_Pos)                                 /*!< DUMMY_REG Mask      0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG63_DUMMY_REG_Set(x) (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG63_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG63_DUMMY_REG_Msk) /*!< DUMMY_REG Set Value            */
#define DUMMY_REGS_DUMMY_REG63_DUMMY_REG_Get(x) (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG63_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG63_DUMMY_REG_Pos) /*!< DUMMY_REG Get Value            */


/*!
 * @}
 */


/*!
 * @}
 */ /* end of HS32F7D377_SYSCTRL_CPU1_REGISTER */

#endif /* HS32F7D377_SYSCTRL_CPU1_H */
