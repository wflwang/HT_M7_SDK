/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


/*!
 * \file HS32F7D377_sysctrl_cpu2.h
 * \brief HS32F7D377 SYSCTRL_CPU2 register file
 * \version V1.0_20240116
 */

#ifndef HS32F7D377_SYSCTRL_CPU2_H
#define HS32F7D377_SYSCTRL_CPU2_H

/*!
 * \addtogroup HS32F7D377_SYSCTRL_CPU2_REGISTER HS32F7D377 SYSCTRL_CPU2 Register
 * \ingroup HS32F7D377_REGISTER
 *
 * \brief SYSCTRL_CPU2 register layout, bitfield and address definitions
 *
 * @{
 */

/* clang-format off */

/*!
 * \name SYSCTRL_CPU2 Register Layout
 *
 *
 * @{
 */

/*! \brief CPUTIMER_REGS register */
typedef struct {
    union
    {
        __IOM uint32_t TIM                               ;  /*!< 0x00000000 : CPU-Timer, Counter Register */

        struct
        {
            __IOM uint32_t LSW                       : 16;  /*!< [15: 0] : CPU-Timer Counter Registers
                                                                           The TIM register holds the low 16 bits of the current 32-bit count of the timer. The TIMH:TIM decrements by one every (TDDRH:TDDR+1) clock cycles, where TDDRH:TDDR is the timer prescale dividedown value. When the TIMH:TIM decrements to zero, the TIMH:TIM register is reloaded with the period value contained in the PRDH:PRD registers. The timer interrupt (TINT) signal is generated.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t MSW                       : 16;  /*!< [31:16] : CPU-Timer Counter Registers
                                                                           The TIMH register holds the high 16 bits of the current 32-bit count of the timer. The TIMH:TIM decrements by one every (TDDRH:TDDR+1) clock cycles, where TDDRH:TDDR is the timer prescale dividedown value. When the TIMH:TIM decrements to zero, the TIMH:TIM register is reloaded with the period value contained in the PRDH:PRD registers. The timer interrupt (TINT) signal is generated.
                                                                           Reset type: SYSRSn */
        } TIMb;
    };

    union
    {
        __IOM uint32_t PRD                               ;  /*!< 0x00000004 : CPU-Timer, Period Register */

        struct
        {
            __IOM uint32_t LSW                       : 16;  /*!< [15: 0] : CPU-Timer Period Registers
                                                                           The PRD register holds the low 16 bits of the 32-bit period. When the TIMH:TIM decrements to zero, the TIMH:TIM register is reloaded with the period value contained in the PRDH:PRD registers, at the start of the next timer input clock cycle (the output of the prescaler). The PRDH:PRD contents are also loaded into the TIMH:TIM when you set the timer reload bit (TRB) in the Timer Control Register (TCR).
                                                                           Reset type: SYSRSn */
            __IOM uint32_t MSW                       : 16;  /*!< [31:16] : CPU-Timer Period Registers
                                                                           The PRDH register holds the high 16 bits of the 32-bit period. When the TIMH:TIM decrements to zero, the TIMH:TIM register is reloaded with the period value contained in the PRDH:PRD registers, at the start of the next timer input clock cycle (the output of the prescaler). The PRDH:PRD contents are also loaded into the TIMH:TIM when you set the timer reload bit (TRB) in the Timer Control Register (TCR).
                                                                           Reset type: SYSRSn */
        } PRDb;
    };

    union
    {
        __IOM uint32_t TCR                               ;  /*!< 0x00000008 : CPU-Timer, Control Register */

        struct
        {
                  uint32_t RSV_0                     : 3 ;  /*!< [ 2: 0] : reserved. */
            __IOM uint32_t INTR_OP                   : 1 ;  /*!< [ 3: 3] : Interrupt option.
                                                                           Timer interrupt mode to CPU.
                                                                           0h = pulse trigger
                                                                           1h = level trigger
                                                                           Note，if pulse trigger selected, TIF indicates timer flag only, it will be latched high by timer hit until user clear. if level trigger selected, TIF and interrupt(if enabled) will be latched high by timer hit until user clear.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t TSS                       : 1 ;  /*!< [ 4: 4] : CPU-Timer stop status bit.
                                                                           TSS is a 1-bit flag that stops or starts the CPU-timer. Reset type: SYSRSn
                                                                           0h (R/W) = Reads of 0 indicate the CPU-timer is running.
                                                                           To start or restart the CPU-timer, set TSS to 0. At reset, TSS is cleared to 0 and the
                                                                           CPU-timer immediately starts.
                                                                           1h (R/W) = Reads of 1 indicate that the CPU-timer is stopped. To stop the CPU-timer, set TSS to 1. */
            __IOM uint32_t TRB                       : 1 ;  /*!< [ 5: 5] : Timer reload
                                                                           Reset type: SYSRSn
                                                                           0h (R/W) = The TRB bit is always read as zero. Writes of 0 are ignored.
                                                                           1h (R/W) = When you write a 1 to TRB, the TIMH:TIM is loaded with the value in the PRDH:PRD,
                                                                           and the prescaler counter (PSCH:PSC) is loaded with the value in the timer dividedown
                                                                           register (TDDRH:TDDR). */
                  uint32_t RSV_1                     : 4 ;  /*!< [ 9: 6] : reserved. */
            __IOM uint32_t TIM_SOFT                  : 1 ;  /*!< [10:10] : If the FREE bit is set to 1, then, upon a software breakpoint, the timer continues to run (that is, free runs). In this case, SOFT is a don't care. But if FREE is 0, then SOFT takes effect.
                                                                           Reset type: SYSRSn
                                                                           0h (R/W) = Stop after the next decrement of the TIMH:TIM (hard stop).
                                                                           (ONLY if FREE=0, if FREE=1 this bit is don't care)
                                                                           1h (R/W) = Stop after the TIMH:TIM decrements to 0 (soft stop)
                                                                           In the SOFT STOP mode, the timer generates an interrupt before shutting down (since reaching 0 is the interrupt causing condition). (ONLY if FREE=0, if FREE=1 this bit is don't care) */
            __IOM uint32_t FREE                      : 1 ;  /*!< [11:11] : If the FREE bit is set to 1, then, upon a software breakpoint, the timer continues to run. If FREE is 0, then the SOFT bit controls the emulation behavior.
                                                                           Reset type: SYSRSn
                                                                           0h (R/W) = Stop after the next decrement of the TIMH:TIM (hard stop)
                                                                           (SOFT bit controls the emulation behavior)
                                                                           1h (R/W) = Free Run
                                                                           (SOFT bit is don't care, counter is free running) */
                  uint32_t RSV_2                     : 2 ;  /*!< [13:12] : reserved. */
            __IOM uint32_t TIE                       : 1 ;  /*!< [14:14] : CPU-Timer Interrupt Enable. Reset type: SYSRSn
                                                                           0h (R/W) = The CPU-Timer interrupt is disabled.
                                                                           1h (R/W) = The CPU-Timer interrupt is enabled. If the timer decrements to zero, and TIE is set, the timer asserts its interrupt request. */
            __IOM uint32_t TIF                       : 1 ;  /*!< [15:15] : CPU-Timer Overflow Flag.
                                                                           TIF indicates whether a timer overflow has happened since TIF was last cleared. TIF is not cleared automatically and does not need to be cleared to enable the next timer interrupt.
                                                                           Reset type: SYSRSn
                                                                           0h (R/W) = The CPU-Timer has not decremented to zero. Writes of 0 are ignored.
                                                                           1h (R/W) = This flag gets set when the CPU-timer decrements to zero.
                                                                           Writing a 1 to this bit clears the flag. */
                  uint32_t RSV_3                     : 16;  /*!< [31:16] : reserved. */
        } TCRb;
    };

    union
    {
        __IOM uint16_t TPR                               ;  /*!< 0x0000000c : CPU-Timer, Prescale Register */

        struct
        {
            __IOM uint16_t TDDR                      : 8 ;  /*!< [ 7: 0] : CPU-Timer Divide-Down.
                                                                           Every (TDDRH:TDDR + 1) timer clock source cycles, the timer counter register (TIMH:TIM) decrements by one. At reset, the TDDRH:TDDR bits are cleared to 0. To increase the overall timer
                                                                           count by an integer factor, write this factor minus one to the TDDRH:TDDR bits. When the prescaler counter (PSCH:PSC) value is 0, one timer clock source cycle later, the contents of the TDDRH:TDDR reload the PSCH:PSC, and the TIMH:TIM decrements by one. TDDRH:TDDR also reloads the PSCH:PSC whenever the timer reload bit (TRB) is set by software.
                                                                           Reset type: SYSRSn */
            __IM  uint16_t PSC                       : 8 ;  /*!< [15: 8] : CPU-Timer Prescale Counter.
                                                                           These bits hold the current prescale count for the timer. For every timer clock source cycle that the PSCH:PSC value is greater than 0, the PSCH:PSC decrements by one. One timer clock (output of the timer prescaler) cycle after the PSCH:PSC reaches 0, the PSCH:PSC is loaded with the contents of the TDDRH:TDDR, and the timer counter register (TIMH:TIM) decrements by one. The PSCH:PSC is also reloaded whenever the timer reload bit (TRB) is set by software. The PSCH:PSC can be checked by reading the register, but it cannot be set directly. It must get its value from the timer divide-down register
                                                                           (TDDRH:TDDR). At reset, the PSCH:PSC is set to 0. Reset type: SYSRSn */
        } TPRb;
    };

    union
    {
        __IOM uint16_t TPRH                              ;  /*!< 0x0000000e : CPU-Timer, Prescale Register High */

        struct
        {
            __IOM uint16_t TDDRH                     : 8 ;  /*!< [ 7: 0] : See description of TIMERxTPR. */
            __IM  uint16_t PSCH                      : 8 ;  /*!< [15: 8] : See description of TIMERxTPR. */
        } TPRHb;
    };

    uint8_t    RSV_0X10[16]                              ;
    union
    {
        __IOM uint32_t TIMEX                             ;  /*!< 0x00000020 : CPU-Timer, Counter Register */

        struct
        {
            __IOM uint32_t TIMEX                     : 32;  /*!< [31: 0] : CPU-Timer Counter Registers high 32bit, extend to 64bit
                                                                           Reset type: SYSRSn */
        } TIMEXb;
    };

    union
    {
        __IOM uint32_t PRDEX                             ;  /*!< 0x00000024 : CPU-Timer, Period Register */

        struct
        {
            __IOM uint32_t PRDEX                     : 32;  /*!< [31: 0] : CPU-Timer Period Registers high 32bit, extend to 64bit
                                                                           Reset type: SYSRSn */
        } PRDEXb;
    };

    uint8_t    RSV_0X28[984]                             ;
} CPUTIMER_REGS_Type;

/*! \brief WD_REGS register */
typedef struct {
    uint8_t    RSV_0XC00[82]                             ;
    union
    {
        __IOM uint16_t WDCR                              ;  /*!< 0x00000052 : Watchdog Control Register */

        struct
        {
            __IOM uint16_t WDPS                      : 3 ;  /*!< [ 2: 0] : These bits configure the watchdog counter clock (WDCLK) rate relative to INTOSC1/512:
                                                                           000 WDCLK = INTOSC1/512/1
                                                                           001 WDCLK = INTOSC1/512/1
                                                                           010 WDCLK = INTOSC1/512/2
                                                                           011 WDCLK = INTOSC1/512/4
                                                                           100 WDCLK = INTOSC1/512/8
                                                                           101 WDCLK = INTOSC1/512/16
                                                                           110 WDCLK = INTOSC1/512/32
                                                                           111 WDCLK = INTOSC1/512/64
                                                                           Reset type: IORSn */
                  uint16_t RSV_0                     : 13;  /*!< [15: 3] : reserved. */
        } WDCRb;
    };

    uint8_t    RSV_0XC54[940]                            ;
} WD_REGS_Type;

/*! \brief NMI_INTRUPT_REGS register */
typedef struct {
    union
    {
        __IOM uint16_t NMICFG                            ;  /*!< 0x00000000 : NMI Configuration Register */

        struct
        {
            __IOM uint16_t NMIE                      : 1 ;  /*!< [ 0: 0] : When set to 1 any condition will generate an NMI interrupt to the C28 CPU and kick off the NMI watchdog counter. As part of boot sequence this bit should be set after the device security related initialization is complete.
                                                                           0 NMI disabled
                                                                           1 NMI enabled
                                                                           Reset type: SYSRSn */
                  uint16_t RSV_0                     : 15;  /*!< [15: 1] : reserved. */
        } NMICFGb;
    };

    union
    {
        __IM  uint16_t NMIFLG                            ;  /*!< 0x00000002 : NMI Flag Register (XRSn Clear) */

        struct
        {
            __IM  uint16_t NMIINT                    : 1 ;  /*!< [ 0: 0] : NMI Interrupt Flag: This bit indicates if an NMI interrupt was generated. This bit can only be cleared by the user writing to the respective bit in the NMIFLGCLR register or by an XRSn reset:
                                                                           0 No NMI Interrupt Generated 1 NMI Interrupt Generated
                                                                           No further NMI interrupts pulses are generated until this flag is cleared by the user.
                                                                           Reset type: XRSn */
            __IM  uint16_t CLOCKFAIL                 : 1 ;  /*!< [ 1: 1] : Clock Fail Interrupt Flag: These bits indicates if the CLOCKFAIL condition is latched. These bits can only be cleared by the user writing to the respective bit in the NMIFLGCLR register or by an XRSn reset:
                                                                           0,No CLOCKFAIL Condition Pending 1,CLOCKFAIL Condition Generated
                                                                           Reset type: XRSn */
            __IM  uint16_t RAMUNCERR                 : 1 ;  /*!< [ 2: 2] : RAM Uncorrectable Error NMI Flag: This bit indicates if an uncorrectable error occurred on a RAM access (by any master) and that condition is latched. This bit can only be cleared by the user writing to the corresponding clear bit in the NMIFLGCLR register or by an XRSn reset:
                                                                           0,No RAM uncorrectable error condition pending 1,RAM uncorrectable error condition generated
                                                                           Reset type: XRSn */
            __IM  uint16_t FLUNCERR                  : 1 ;  /*!< [ 3: 3] : Flash Uncorrectable Error NMI Flag: This bit indicates if an uncorrectable error occurred on a C28 Flash access and that condition is latched. This bit can only be cleared by the user writing to the corresponding clear bit in the NMIFLGCLR register or by an XRSn reset:
                                                                           0,No C28 Flash uncorrectable error condition pending 1,C28 Flash uncorrectable error condition generated
                                                                           Reset type: XRSn */
                  uint16_t RSV_0                     : 4 ;  /*!< [ 7: 4] : reserved. */
            __IM  uint16_t CLBNMI                    : 1 ;  /*!< [ 8: 8] : Configurable Logic Block NMI Flag: This bit indicates if an NMI was generated by the Configurable Logic Block. This bit can only be cleared by the user writing to the corresponding clear bit in the NMIFLGCLR register or by an XRSn reset:
                                                                           0,No Configurable Logic Block NMI pending 1,Configurable Logic Block NMI generated
                                                                           Reset type: XRSn */
                  uint16_t RSV_1                     : 7 ;  /*!< [15: 9] : reserved. */
        } NMIFLGb;
    };

    union
    {
        __IOM uint16_t NMIFLGCLR                         ;  /*!< 0x00000004 : NMI Flag Clear Register */

        struct
        {
            __IOM uint16_t NMIINT                    : 1 ;  /*!< [ 0: 0] : Writing a 1 to the respective bit clears the corresponding flag bit in the NMIFLG and NMISHDFLG registers. Writes of 0 are ignored. Always reads back 0.
                                                                           Notes:
                                                                           [1] If hardware is trying to set a bit to 1 while software is trying to clear a bit to 0 on the same cycle, hardware has priority.
                                                                           [2] Users should clear the pending FAIL flag first and then clear the NMIINT flag.
                                                                           Reset type: SYSRSn */
            __IOM uint16_t CLOCKFAIL                 : 1 ;  /*!< [ 1: 1] : Writing a 1 to the respective bit clears the corresponding flag bit in the NMIFLG and NMISHDFLG registers. Writes of 0 are ignored. Always reads back 0.
                                                                           Notes:
                                                                           [1] If hardware is trying to set a bit to 1 while software is trying to clear a bit to 0 on the same cycle, hardware has priority.
                                                                           [2] Users should clear the pending FAIL flag first and then clear the NMIINT flag.
                                                                           Reset type: SYSRSn */
            __IOM uint16_t RAMUNCERR                 : 1 ;  /*!< [ 2: 2] : Writing a 1 to the respective bit clears the corresponding flag bit in the NMIFLG and NMISHDFLG registers. Writes of 0 are ignored. Always reads back 0.
                                                                           Notes:
                                                                           [1] If hardware is trying to set a bit to 1 while software is trying to clear a bit to 0 on the same cycle, hardware has priority.
                                                                           [2] Users should clear the pending FAIL flag first and then clear the NMIINT flag.
                                                                           Reset type: SYSRSn */
            __IOM uint16_t FLUNCERR                  : 1 ;  /*!< [ 3: 3] : Writing a 1 to the respective bit clears the corresponding flag bit in the NMIFLG and NMISHDFLG registers. Writes of 0 are ignored. Always reads back 0.
                                                                           Notes:
                                                                           [1] If hardware is trying to set a bit to 1 while software is trying to clear a bit to 0 on the same cycle, hardware has priority.
                                                                           [2] Users should clear the pending FAIL flag first and then clear the NMIINT flag.
                                                                           Reset type: SYSRSn */
                  uint16_t RSV_0                     : 4 ;  /*!< [ 7: 4] : reserved. */
            __IOM uint16_t CLBNMI                    : 1 ;  /*!< [ 8: 8] : Writing a 1 to the respective bit clears the corresponding flag bit in the NMIFLG and NMISHDFLG registers. Writes of 0 are ignored. Always reads back 0.
                                                                           Notes:
                                                                           [1] If hardware is trying to set a bit to 1 while software is trying to clear a bit to 0 on the same cycle, hardware has priority.
                                                                           [2] Users should clear the pending FAIL flag first and then clear the NMIINT flag.
                                                                           Reset type: SYSRSn */
                  uint16_t RSV_1                     : 7 ;  /*!< [15: 9] : reserved. */
        } NMIFLGCLRb;
    };

    union
    {
        __IOM uint16_t NMIFLGFRC                         ;  /*!< 0x00000006 : NMI Flag Force Register */

        struct
        {
                  uint16_t RSV_0                     : 1 ;  /*!< [ 0: 0] : reserved. */
            __IOM uint16_t CLOCKFAIL                 : 1 ;  /*!< [ 1: 1] : Writing a 1 to these bits will set the respective FAIL flag in the NMIFLG and NMISHDFLG registers. Writes of 0 are ignored. Always reads back 0. This can be used as a means to test the NMI mechanisms.
                                                                           Reset type: SYSRSn */
            __IOM uint16_t RAMUNCERR                 : 1 ;  /*!< [ 2: 2] : Writing a 1 to these bits will set the respective FAIL flag in the NMIFLG and NMISHDFLG registers. Writes of 0 are ignored. Always reads back 0. This can be used as a means to test the NMI mechanisms.
                                                                           Reset type: SYSRSn */
            __IOM uint16_t FLUNCERR                  : 1 ;  /*!< [ 3: 3] : Writing a 1 to these bits will set the respective FAIL flag in the NMIFLG and NMISHDFLG registers. Writes of 0 are ignored. Always reads back 0. This can be used as a means to test the NMI mechanisms.
                                                                           Reset type: SYSRSn */
                  uint16_t RSV_1                     : 4 ;  /*!< [ 7: 4] : reserved. */
            __IOM uint16_t CLBNMI                    : 1 ;  /*!< [ 8: 8] : Writing a 1 to these bits will set the respective FAIL flag in the NMIFLG and NMISHDFLG registers. Writes of 0 are ignored. Always reads back 0. This can be used as a means to test the NMI mechanisms.
                                                                           Reset type: SYSRSn */
                  uint16_t RSV_2                     : 7 ;  /*!< [15: 9] : reserved. */
        } NMIFLGFRCb;
    };

    union
    {
        __IM  uint16_t NMIWDCNT                          ;  /*!< 0x00000008 : NMI Watchdog Counter Register */

        struct
        {
            __IM  uint16_t NMIWDCNT                  : 16;  /*!< [15: 0] : NMI Watchdog Counter: This 16-bit incremental counter will start incrementing whenever any one of the enabled FAIL flags are set. If the counter reaches the period value, an NMIRSn signal is fired which will then resets the system. The counter will reset to zero when it reaches the period value and will then restart counting if any of the enabled FAIL flags are set.
                                                                           If no enabled FAIL flag is set, then the counter will reset to zero and remain at zero until an enabled FAIL flag is set.
                                                                           Normally, the software would respond to the NMI interrupt generated and clear the offending FLAG(s) before the NMI watchdog triggers a reset. In some situations, the software may decide to allow the watchdog to reset the device anyway.
                                                                           The counter is clocked at the SYSCLKOUT rate. Reset type: SYSRSn */
        } NMIWDCNTb;
    };

    union
    {
        __IOM uint16_t NMIWDPRD                          ;  /*!< 0x0000000a : NMI Watchdog Period Register */

        struct
        {
            __IOM uint16_t NMIWDPRD                  : 16;  /*!< [15: 0] : NMI Watchdog Period: This 16-bit value contains the period value at which a reset is generated when the watchdog counter matches. At reset this value is set at the maximum. The software can decrease the period value at initialization time.
                                                                           Writing a PERIOD value that is smaller then the current counter value will automatically force an NMIRSn and hence reset the watchdog counter.
                                                                           Reset type: SYSRSn */
        } NMIWDPRDb;
    };

    union
    {
        __IM  uint32_t NMISHDFLG                         ;  /*!< 0x0000000c : NMI Shadow Flag Register */

        struct
        {
                  uint32_t RSV_0                     : 1 ;  /*!< [ 0: 0] : reserved. */
            __IM  uint32_t CLOCKFAIL                 : 1 ;  /*!< [ 1: 1] : Shadow NMI Flags: When an NMIFLG bit is set due to any of the possible NMI source in the device, the corresponding bit in this register is also set. Note that NMIFLGFRC and NMIFLGCLR register also affects the bits of this register in the same way as they do for the NMIFLG register. This register is only reset by a PORESETn reset.
                                                                           Notes:
                                                                           [1] This register is added to keep the definition of System Control Reset Cause Register Clean.
                                                                           Reset type: PORESETn */
            __IM  uint32_t RAMUNCERR                 : 1 ;  /*!< [ 2: 2] : Shadow NMI Flags: When an NMIFLG bit is set due to any of the possible NMI source in the device, the corresponding bit in this register is also set. Note that NMIFLGFRC and NMIFLGCLR register also affects the bits of this register in the same way as they do for the NMIFLG register. This register is only reset by a PORESETn reset.
                                                                           Notes:
                                                                           [1] This register is added to keep the definition of System Control Reset Cause Register Clean.
                                                                           Reset type: PORESETn */
            __IM  uint32_t FLUNCERR                  : 1 ;  /*!< [ 3: 3] : Shadow NMI Flags: When an NMIFLG bit is set due to any of the possible NMI source in the device, the corresponding bit in this register is also set. Note that NMIFLGFRC and NMIFLGCLR register also affects the bits of this register in the same way as they do for the NMIFLG register. This register is only reset by a PORESETn reset.
                                                                           Notes:
                                                                           [1] This register is added to keep the definition of System Control Reset Cause Register Clean.
                                                                           Reset type: PORESETn */
                  uint32_t RSV_1                     : 4 ;  /*!< [ 7: 4] : reserved. */
            __IM  uint32_t CLBNMI                    : 1 ;  /*!< [ 8: 8] : Shadow NMI Flags: When an NMIFLG bit is set due to any of the possible NMI source in the device, the corresponding bit in this register is also set. Note that NMIFLGFRC and NMIFLGCLR register also affects the bits of this register in the same way as they do for the NMIFLG register. This register is only reset by a PORESETn reset.
                                                                           Notes:
                                                                           [1] This register is added to keep the definition of System Control Reset Cause Register Clean.
                                                                           Reset type: PORESETn */
                  uint32_t RSV_2                     : 23;  /*!< [31: 9] : reserved. */
        } NMISHDFLGb;
    };

    uint8_t    RSV_0X1010[16]                            ;
    union
    {
        __IOM uint32_t NMIWDCFG                          ;  /*!< 0x00000020 : NMI Watchdog Enable */

        struct
        {
            __IOM uint32_t NMIWD_EN                  : 1 ;  /*!< [ 0: 0] : nmi watchdog enable
                                                                           0: disable
                                                                           1: enable
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 31;  /*!< [31: 1] : reserved. */
        } NMIWDCFGb;
    };

    union
    {
        __IOM uint32_t NMICLBCFG                         ;  /*!< 0x00000024 : CLB NMI Select */

        struct
        {
            __IOM uint32_t CLBNMISELECT              : 1 ;  /*!< [ 0: 0] : CLB NMI Select
                                                                           0: all CLB NMI trigger this CPU NMI
                                                                           1: only CLB in CPU Subsystem trigger this CPU NMI
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 31;  /*!< [31: 1] : reserved. */
        } NMICLBCFGb;
    };

    uint8_t    RSV_0X1028[984]                           ;
} NMI_INTRUPT_REGS_Type;

/*! \brief XINT_REGS register */
typedef struct {
    union
    {
        __IOM uint16_t XINT1CR                           ;  /*!< 0x00000000 : XINT1 configuration register */

        struct
        {
            __IOM uint16_t INTR_ENABLE               : 1 ;  /*!< [ 0: 0] : 0: Interrupt Disabled
                                                                           1: Interrupt Enabled Reset type: SYSRSn */
                  uint16_t RSV_0                     : 1 ;  /*!< [ 1: 1] : reserved. */
            __IOM uint16_t POLARITY                  : 2 ;  /*!< [ 3: 2] : 00: Interrupt is selected as negative edge triggered 01: Interrupt is selected as positive edge triggered 10: Interrupt is selected as negative edge triggered
                                                                           11: Interrupt is selected as positive or negative edge triggered
                                                                           Reset type: SYSRSn */
                  uint16_t RSV_1                     : 12;  /*!< [15: 4] : reserved. */
        } XINT1CRb;
    };

    union
    {
        __IOM uint16_t XINT2CR                           ;  /*!< 0x00000002 : XINT2 configuration register */

        struct
        {
            __IOM uint16_t INTR_ENABLE               : 1 ;  /*!< [ 0: 0] : 0: Interrupt Disabled
                                                                           1: Interrupt Enabled Reset type: SYSRSn */
                  uint16_t RSV_0                     : 1 ;  /*!< [ 1: 1] : reserved. */
            __IOM uint16_t POLARITY                  : 2 ;  /*!< [ 3: 2] : 00: Interrupt is selected as negative edge triggered 01: Interrupt is selected as positive edge triggered 10: Interrupt is selected as negative edge triggered
                                                                           11: Interrupt is selected as positive or negative edge triggered
                                                                           Reset type: SYSRSn */
                  uint16_t RSV_1                     : 12;  /*!< [15: 4] : reserved. */
        } XINT2CRb;
    };

    union
    {
        __IOM uint16_t XINT3CR                           ;  /*!< 0x00000004 : XINT3 configuration register */

        struct
        {
            __IOM uint16_t INTR_ENABLE               : 1 ;  /*!< [ 0: 0] : 0: Interrupt Disabled
                                                                           1: Interrupt Enabled Reset type: SYSRSn */
                  uint16_t RSV_0                     : 1 ;  /*!< [ 1: 1] : reserved. */
            __IOM uint16_t POLARITY                  : 2 ;  /*!< [ 3: 2] : 00: Interrupt is selected as negative edge triggered 01: Interrupt is selected as positive edge triggered 10: Interrupt is selected as negative edge triggered
                                                                           11: Interrupt is selected as positive or negative edge triggered
                                                                           Reset type: SYSRSn */
                  uint16_t RSV_1                     : 12;  /*!< [15: 4] : reserved. */
        } XINT3CRb;
    };

    union
    {
        __IOM uint16_t XINT4CR                           ;  /*!< 0x00000006 : XINT4 configuration register */

        struct
        {
            __IOM uint16_t INTR_ENABLE               : 1 ;  /*!< [ 0: 0] : 0: Interrupt Disabled
                                                                           1: Interrupt Enabled Reset type: SYSRSn */
                  uint16_t RSV_0                     : 1 ;  /*!< [ 1: 1] : reserved. */
            __IOM uint16_t POLARITY                  : 2 ;  /*!< [ 3: 2] : 00: Interrupt is selected as negative edge triggered 01: Interrupt is selected as positive edge triggered 10: Interrupt is selected as negative edge triggered
                                                                           11: Interrupt is selected as positive or negative edge triggered
                                                                           Reset type: SYSRSn */
                  uint16_t RSV_1                     : 12;  /*!< [15: 4] : reserved. */
        } XINT4CRb;
    };

    union
    {
        __IOM uint32_t XINT5CR                           ;  /*!< 0x00000008 : XINT5 configuration register */

        struct
        {
            __IOM uint32_t INTR_ENABLE               : 1 ;  /*!< [ 0: 0] : 0: Interrupt Disabled
                                                                           1: Interrupt Enabled Reset type: SYSRSn */
                  uint32_t RSV_0                     : 1 ;  /*!< [ 1: 1] : reserved. */
            __IOM uint32_t POLARITY                  : 2 ;  /*!< [ 3: 2] : 00: Interrupt is selected as negative edge triggered 01: Interrupt is selected as positive edge triggered 10: Interrupt is selected as negative edge triggered
                                                                           11: Interrupt is selected as positive or negative edge triggered
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_1                     : 28;  /*!< [31: 4] : reserved. */
        } XINT5CRb;
    };

    uint8_t    RSV_0X140C[4]                             ;
    union
    {
        __IM  uint16_t XINT1CTR                          ;  /*!< 0x00000010 : XINT1 counter register */

        struct
        {
            __IM  uint16_t INTCTR                    : 16;  /*!< [15: 0] : This is a free running 16-bit up-counter that is clocked at the SYSCLKOUT rate. The counter value is reset to 0x0000 when a valid interrupt edge is detected and then continues counting until the next valid interrupt edge is detected. The counter must only be reset by the selected POLARITY edge as selected in the respective interrupt control register. When the interrupt is disabled, the counter will stop. The counter is a free-running counter and will wrap around to zero when the max value is reached. The counter is a read only register and can only be reset to zero by a valid interrupt edge or by reset.
                                                                           Reset type: SYSRSn */
        } XINT1CTRb;
    };

    union
    {
        __IM  uint16_t XINT2CTR                          ;  /*!< 0x00000012 : XINT2 counter register */

        struct
        {
            __IM  uint16_t INTCTR                    : 16;  /*!< [15: 0] : This is a free running 16-bit up-counter that is clocked at the SYSCLKOUT rate. The counter value is reset to 0x0000 when a valid interrupt edge is detected and then continues counting until the next valid interrupt edge is detected. The counter must only be reset by the selected POLARITY edge as selected in the respective interrupt control register. When the interrupt is disabled, the counter will stop. The counter is a free-running counter and will wrap around to zero when the max value is reached. The counter is a read only register and can only be reset to zero by a valid interrupt edge or by reset.
                                                                           Reset type: SYSRSn */
        } XINT2CTRb;
    };

    union
    {
        __IM  uint32_t XINT3CTR                          ;  /*!< 0x00000014 : XINT3 counter register */

        struct
        {
            __IM  uint32_t INTCTR                    : 16;  /*!< [15: 0] : This is a free running 16-bit up-counter that is clocked at the SYSCLKOUT rate. The counter value is reset to 0x0000 when a valid interrupt edge is detected and then continues counting until the next valid interrupt edge is detected. The counter must only be reset by the selected POLARITY edge as selected in the respective interrupt control register. When the interrupt is disabled, the counter will stop. The counter is a free-running counter and will wrap around to zero when the max value is reached. The counter is a read only register and can only be reset to zero by a valid interrupt edge or by reset.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 16;  /*!< [31:16] : reserved. */
        } XINT3CTRb;
    };

    union
    {
        __IM  uint32_t XINT4CTR                          ;  /*!< 0x00000018 : XINT4 counter register */

        struct
        {
            __IM  uint32_t INTCTR                    : 16;  /*!< [15: 0] : This is a free running 16-bit up-counter that is clocked at the SYSCLKOUT rate. The counter value is reset to 0x0000 when a valid interrupt edge is detected and then continues counting until the next valid interrupt edge is detected. The counter must only be reset by the selected POLARITY edge as selected in the respective interrupt control register. When the interrupt is disabled, the counter will stop. The counter is a free-running counter and will wrap around to zero when the max value is reached. The counter is a read only register and can only be reset to zero by a valid interrupt edge or by reset.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 16;  /*!< [31:16] : reserved. */
        } XINT4CTRb;
    };

    union
    {
        __IM  uint32_t XINT5CTR                          ;  /*!< 0x0000001c : XINT5 counter register */

        struct
        {
            __IM  uint32_t INTCTR                    : 16;  /*!< [15: 0] : This is a free running 16-bit up-counter that is clocked at the SYSCLKOUT rate. The counter value is reset to 0x0000 when a valid interrupt edge is detected and then continues counting until the next valid interrupt edge is detected. The counter must only be reset by the selected POLARITY edge as selected in the respective interrupt control register. When the interrupt is disabled, the counter will stop. The counter is a free-running counter and will wrap around to zero when the max value is reached. The counter is a read only register and can only be reset to zero by a valid interrupt edge or by reset.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 16;  /*!< [31:16] : reserved. */
        } XINT5CTRb;
    };

    union
    {
        __IM  uint32_t XINT1FLG                          ;  /*!< 0x00000020 : XINT1 flag register */

        struct
        {
            __IM  uint32_t XINTFLG                   : 1 ;  /*!< [ 0: 0] : Writing a 1 to the respective bit clears the corresponding external interrupt flag. Writes of 0 are ignored. Always reads back 0.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 31;  /*!< [31: 1] : reserved. */
        } XINT1FLGb;
    };

    union
    {
        __IM  uint32_t XINT2FLG                          ;  /*!< 0x00000024 : XINT2 flag register */

        struct
        {
            __IM  uint32_t XINTFLG                   : 1 ;  /*!< [ 0: 0] : Writing a 1 to the respective bit clears the corresponding external interrupt flag. Writes of 0 are ignored. Always reads back 0.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 31;  /*!< [31: 1] : reserved. */
        } XINT2FLGb;
    };

    union
    {
        __IM  uint32_t XINT3FLG                          ;  /*!< 0x00000028 : XINT3 flag register */

        struct
        {
            __IM  uint32_t XINTFLG                   : 1 ;  /*!< [ 0: 0] : Writing a 1 to the respective bit clears the corresponding external interrupt flag. Writes of 0 are ignored. Always reads back 0.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 31;  /*!< [31: 1] : reserved. */
        } XINT3FLGb;
    };

    union
    {
        __IM  uint32_t XINT4FLG                          ;  /*!< 0x0000002c : XINT4 flag register */

        struct
        {
            __IM  uint32_t XINTFLG                   : 1 ;  /*!< [ 0: 0] : Writing a 1 to the respective bit clears the corresponding external interrupt flag. Writes of 0 are ignored. Always reads back 0.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 31;  /*!< [31: 1] : reserved. */
        } XINT4FLGb;
    };

    union
    {
        __IM  uint32_t XINT5FLG                          ;  /*!< 0x00000030 : XINT5 flag register */

        struct
        {
            __IM  uint32_t XINTFLG                   : 1 ;  /*!< [ 0: 0] : Writing a 1 to the respective bit clears the corresponding external interrupt flag. Writes of 0 are ignored. Always reads back 0.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 31;  /*!< [31: 1] : reserved. */
        } XINT5FLGb;
    };

    uint8_t    RSV_0X1434[12]                            ;
    union
    {
        __IOM uint32_t XINT1CLR                          ;  /*!< 0x00000040 : XINT1 flag clear register */

        struct
        {
            __IOM uint32_t XINTCLR                   : 1 ;  /*!< [ 0: 0] : Writing a 1 to the respective bit clears the corresponding external interrupt flag. Writes of 0 are ignored. Always reads back 0.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 31;  /*!< [31: 1] : reserved. */
        } XINT1CLRb;
    };

    union
    {
        __IOM uint32_t XINT2CLR                          ;  /*!< 0x00000044 : XINT2 flag clear register */

        struct
        {
            __IOM uint32_t XINTCLR                   : 1 ;  /*!< [ 0: 0] : Writing a 1 to the respective bit clears the corresponding external interrupt flag. Writes of 0 are ignored. Always reads back 0.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 31;  /*!< [31: 1] : reserved. */
        } XINT2CLRb;
    };

    union
    {
        __IOM uint32_t XINT3CLR                          ;  /*!< 0x00000048 : XINT3 flag clear register */

        struct
        {
            __IOM uint32_t XINTCLR                   : 1 ;  /*!< [ 0: 0] : Writing a 1 to the respective bit clears the corresponding external interrupt flag. Writes of 0 are ignored. Always reads back 0.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 31;  /*!< [31: 1] : reserved. */
        } XINT3CLRb;
    };

    union
    {
        __IOM uint32_t XINT4CLR                          ;  /*!< 0x0000004c : XINT4 flag clear register */

        struct
        {
            __IOM uint32_t XINTCLR                   : 1 ;  /*!< [ 0: 0] : Writing a 1 to the respective bit clears the corresponding external interrupt flag. Writes of 0 are ignored. Always reads back 0.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 31;  /*!< [31: 1] : reserved. */
        } XINT4CLRb;
    };

    union
    {
        __IOM uint32_t XINT5CLR                          ;  /*!< 0x00000050 : XINT5 flag clear register */

        struct
        {
            __IOM uint32_t XINTCLR                   : 1 ;  /*!< [ 0: 0] : Writing a 1 to the respective bit clears the corresponding external interrupt flag. Writes of 0 are ignored. Always reads back 0.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 31;  /*!< [31: 1] : reserved. */
        } XINT5CLRb;
    };

    uint8_t    RSV_0X1454[940]                           ;
} XINT_REGS_Type;

/*! \brief CLK_CFG_REGS register */
typedef struct {
    union
    {
        __IOM uint32_t CLKSEM                            ;  /*!< 0x00000000 : Clock Control Semaphore Register */

        struct
        {
            __IOM uint32_t SEM                       : 2 ;  /*!< [ 1: 0] : This register provides a mechanism to acquire all the CLKCFG registers (except this register) by CPU1 or CPU2. A CPU can perform read/writes to any of the CLKCFG registers (except this register) only if it owns the semaphore. Otherwise, writes are ignored and reads will return 0x0.
                                                                           Semaphore State Transitions:
                                                                           A value of 00, 10, 11 gives ownership to CPU1.
                                                                           A value of 01 gives ownership to CPU2.
                                                                           The following are the only state transitions allowed on these bits.
                                                                           00,11 <-> 01 (allowed by CPU2)
                                                                           00,11 <-> 10 (allowed by CPU1)
                                                                           If a CPU doesn't own the CLK_CFG_REGS set of registers (as defined by the state of this semaphore), reads from that CPU to all those registers return 0x0 and writes are ignore. Note that this is not true of CLKSEM register. The CLKSEM register's reads and writes are always allowed from both CPU1 and CPU2.
                                                                           Reset type: CPU1.SYSRSn */
                  uint32_t RSV_0                     : 14;  /*!< [15: 2] : reserved. */
            __IM  uint32_t KEY                       : 16;  /*!< [31:16] : Writing the value 0xa5a5 will allow the writing of the SEM bits, else writes are ignored. Reads will return 0.
                                                                           Note:
                                                                           [1] Due to this KEY, only 32-bit writes will succeed (provided the KEY matches). 16-bit writes to the upper or lower half of this register will be ignored
                                                                           Reset type: N/A */
        } CLKSEMb;
    };

    union
    {
        __IOM uint32_t CLKCFGLOCK1                       ;  /*!< 0x00000004 : Lock bit for CLKCFG registers */

        struct
        {
            __IOM uint32_t CLKSRCCTL1                : 1 ;  /*!< [ 0: 0] : Lock bit for CLKSRCCTL1 register:
                                                                           0: Respective register is not locked
                                                                           1: Respective register is locked.
                                                                           Reset type: CPU1.SYSRSn */
            __IOM uint32_t CLKSRCCTL2                : 1 ;  /*!< [ 1: 1] : Lock bit for CLKSRCCTL2 register: 0: Respective register is not locked 1: Respective register is locked.
                                                                           Reset type: CPU1.SYSRSn */
            __IOM uint32_t CLKSRCCTL3                : 1 ;  /*!< [ 2: 2] : Lock bit for CLKSRCCTL3 register: 0: Respective register is not locked 1: Respective register is locked.
                                                                           Reset type: CPU1.SYSRSn */
            __IOM uint32_t SYSPLLCTL1                : 1 ;  /*!< [ 3: 3] : Lock bit for SYSPLLCTL1 register: 0: Respective register is not locked 1: Respective register is locked.
                                                                           Reset type: CPU1.SYSRSn */
                  uint32_t RSV_0                     : 2 ;  /*!< [ 5: 4] : reserved. */
            __IOM uint32_t SYSPLLMULT                : 1 ;  /*!< [ 6: 6] : Lock bit for SYSPLLMULT register: 0: Respective register is not locked 1: Respective register is locked.
                                                                           Reset type: CPU1.SYSRSn */
            __IOM uint32_t AUXPLLCTL1                : 1 ;  /*!< [ 7: 7] : Lock bit for AUXPLLCTL1 register: 0: Respective register is not locked 1: Respective register is locked.
                                                                           Reset type: CPU1.SYSRSn */
                  uint32_t RSV_1                     : 2 ;  /*!< [ 9: 8] : reserved. */
            __IOM uint32_t AUXPLLMULT                : 1 ;  /*!< [10:10] : Lock bit for AUXPLLMULT register: 0: Respective register is not locked 1: Respective register is locked.
                                                                           Reset type: CPU1.SYSRSn */
            __IOM uint32_t SYSCLKDIVSEL              : 1 ;  /*!< [11:11] : Lock bit for SYSCLKDIVSEL register: 0: Respective register is not locked 1: Respective register is locked.
                                                                           Reset type: CPU1.SYSRSn */
            __IOM uint32_t AUXCLKDIVSEL              : 1 ;  /*!< [12:12] : Lock bit for AUXCLKDIVSEL register: 0: Respective register is not locked  1: Respective register is locked.
                                                                           Reset type: CPU1.SYSRSn */
            __IOM uint32_t PERCLKDIVSEL              : 1 ;  /*!< [13:13] : Lock bit for PERCLKDIVSEL register: 0: Respective register is not locked  1: Respective register is locked.
                                                                           Reset type: CPU1.SYSRSn */
                  uint32_t RSV_2                     : 1 ;  /*!< [14:14] : reserved. */
            __IOM uint32_t LOSPCP                    : 1 ;  /*!< [15:15] : Lock bit for LOSPCP register:
                                                                           0: Respective register is not locked
                                                                           1: Respective register is locked.
                                                                           Reset type: CPU1.SYSRSn */
                  uint32_t RSV_3                     : 16;  /*!< [31:16] : reserved. */
        } CLKCFGLOCK1b;
    };

    uint8_t    RSV_0X2008[8]                             ;
    union
    {
        __IOM uint32_t CLKSRCCTL1                        ;  /*!< 0x00000010 : Clock Source Control register-1 */

        struct
        {
            __IOM uint32_t OSCCLKSRCSEL              : 2 ;  /*!< [ 1: 0] : Oscillator Clock Source Select Bit: This bit selects the source for OSCCLK.
                                                                           00 = INTOSC2 (default on reset)
                                                                           01 = External Oscillator (XTAL)
                                                                           10 = INTOSC1
                                                                           11 = reserved (default to INTOSC1)
                                                                           At power-up or after an XRSn, INTOSC2 is selected by default. Whenever the user changes the clock source using these bits, the SYSPLLMULT register will be forced to zero and the PLL will be bypassed and powered down. This prevents potential PLL overshoot. The user will then have to write to the SYSPLLMULT register to configure the appropriate multiplier.
                                                                           The user must wait 10 OSCCLK cycles before writing to SYSPLLMULT
                                                                           or disabling the previous clock source to allow the change to complete..
                                                                           Notes:
                                                                           [1] Reserved selection defaults to 00 configuration
                                                                           [2] INTOSC1 is recommended to be used only after missing clock detection. If user wants to re-lock the PLL with INTOSC1 (the back- up clock source) after missing clock is detected, he can do a MCLKCLR and lock the PLL.
                                                                           Reset type: XRSn */
                  uint32_t RSV_0                     : 1 ;  /*!< [ 2: 2] : reserved. */
            __IOM uint32_t INTOSC2OFF                : 1 ;  /*!< [ 3: 3] : Internal Oscillator 2 Off Bit: This bit turns oscillator 2 off:
                                                                           0 = Internal Oscillator 2 On (default on reset)
                                                                           1 = Internal Oscillator 2 Off
                                                                           This bit could be used by the user to turn off the internal oscillator 2 if it is not used.
                                                                           NOTE: Ensure no resources are using a clock source prior to disabling it. For example OSCCLKSRCSEL (SYSPLL), AUXOSCCLKSRCSEL (AUXPLL), TMR2CLKSRCSEL (CPUTIMER2) and XCLOCKOUT (XCLKOUT).
                                                                           Reset type: XRSn */
            __IOM uint32_t XTALOFF                   : 1 ;  /*!< [ 4: 4] : Crystal (External) Oscillator Off Bit: This bit turns external oscillator off:
                                                                           0 = Crystal (External) Oscillator On (default on reset)
                                                                           1 = Crystal (External) Oscillator Off
                                                                           NOTE: Ensure no resources are using a clock source prior to disabling it. For example OSCCLKSRCSEL (SYSPLL), AUXOSCCLKSRCSEL (AUXPLL), CANxBCLKSEL (CAN Clock), TMR2CLKSRCSEL (CPUTIMER2) and XCLKOUTSEL(XCLKOUT).
                                                                           Reset type: XRSn */
            __IOM uint32_t WDHALTI                   : 1 ;  /*!< [ 5: 5] : Watchdog HALT Mode Ignore Bit: This bit determines if CPU1.WD is functional in the HALT mode or not.
                                                                           0 = CPU1.WD is not functional in the HALT mode. Clock to CPU1.WD is gated when system enters HALT mode. Additionally, INTOSC1 and INTOSC2 are powered-down when system enters HALT mode
                                                                           1 = CPU1.WD is functional in the HALT mode. Clock to CPU1.WD is not gated and INTOSC1/2 are not powered-down when system enters HALT mode
                                                                           Notes:
                                                                           [1] Clock to CPU2.WD clocks is always gated in the HALT mode. Reset type: XRSn */
                  uint32_t RSV_1                     : 10;  /*!< [15: 6] : reserved. */
            __IOM uint32_t XTAL_DS                   : 2 ;  /*!< [17:16] : XTAL IO drive current select pins
                                                                           for 2MHz application, 2'b00 and 2'b01 are recommend
                                                                           for 30MHz application, 2'b10 and 2'b11 are recommend for 1.8V appliaction, 2'b00 and 2'b01 are recommend for 2.5V and 3.3V application */
                  uint32_t RSV_2                     : 14;  /*!< [31:18] : reserved. */
        } CLKSRCCTL1b;
    };

    union
    {
        __IOM uint32_t CLKSRCCTL2                        ;  /*!< 0x00000014 : Clock Source Control register-2 */

        struct
        {
            __IOM uint32_t AUXOSCCLKSRCSEL           : 2 ;  /*!< [ 1: 0] : Oscillator Clock Source Select Bit: This bit selects the source for AUXOSCCLK:
                                                                           00 = INTOSC2 (default on reset)
                                                                           01 = External Oscillator (XTAL)
                                                                           10 = AUXCLKIN (from GPIO)
                                                                           11 = Reserved
                                                                           Whenever the user changes the clock source using these bits, the AUXPLLMULT register will be forced to zero and the PLL will be bypassed and powered down. This prevents potential PLL overshoot. The user will then have to write to the AUXPLLMULT register to configure the appropriate multiplier.
                                                                           The user must wait 10 OSCCLK cycles before writing to AUXPLLMULT
                                                                           or disabling the previous clock source to allow the change to complete.
                                                                           The missing clock detection circuit does not affect these bits. Reset type: XRSn */
            __IOM uint32_t CANABCLKSEL               : 2 ;  /*!< [ 3: 2] : CANA Bit-Clock Source Select Bit:
                                                                           00 = PERx.SYSCLK (default on reset)
                                                                           01 = External Oscillator (XTAL)
                                                                           10 = AUXCLKIN (from GPIO)
                                                                           11 = Reserved
                                                                           Missing clock detect circuit doesnt have any impact on these bits. Reset type: XRSn */
            __IOM uint32_t CANBBCLKSEL               : 2 ;  /*!< [ 5: 4] : CANB Bit-Clock Source Select Bit:
                                                                           00 = PERx.SYSCLK (default on reset)
                                                                           01 = External Oscillator (XTAL)
                                                                           10 = AUXCLKIN (from GPIO)
                                                                           11 = Reserved
                                                                           Missing clock detect circuit doesnt have any impact on these bits. Reset type: XRSn */
            __IOM uint32_t CANCBCLKSEL               : 2 ;  /*!< [ 7: 6] : CANC Bit-Clock Source Select Bit:
                                                                           00 = PERx.SYSCLK (default on reset)
                                                                           01 = External Oscillator (XTAL)
                                                                           10 = AUXCLKIN (from GPIO)
                                                                           11 = Reserved
                                                                           Missing clock detect circuit doesnt have any impact on these bits. Reset type: XRSn */
                  uint32_t RSV_0                     : 8 ;  /*!< [15: 8] : reserved. */
            __IOM uint32_t SPIACLKSEL                : 1 ;  /*!< [16:16] : SPIA Clock Source Select Bit:
                                                                           0 = SYS_PCLK (default on reset)
                                                                           1 = SYS_CLK
                                                                           Missing clock detect circuit doesnt have any impact on these bits. Reset type: XRSn */
            __IOM uint32_t SPIBCLKSEL                : 1 ;  /*!< [17:17] : SPIB Clock Source Select Bit:
                                                                           0 = SYS_PCLK (default on reset)
                                                                           1 = SYS_CLK
                                                                           Missing clock detect circuit doesnt have any impact on these bits. Reset type: XRSn */
            __IOM uint32_t SPICCLKSEL                : 1 ;  /*!< [18:18] : SPIC Clock Source Select Bit:
                                                                           0 = SYS_PCLK (default on reset)
                                                                           1 = SYS_CLK
                                                                           Missing clock detect circuit doesnt have any impact on these bits. Reset type: XRSn */
                  uint32_t RSV_1                     : 13;  /*!< [31:19] : reserved. */
        } CLKSRCCTL2b;
    };

    union
    {
        __IOM uint32_t CLKSRCCTL3                        ;  /*!< 0x00000018 : Clock Source Control register-3 */

        struct
        {
            __IOM uint32_t XCLKOUTSEL                : 3 ;  /*!< [ 2: 0] : XCLKOUT Source Select Bit: This bit selects the source for XCLKOUT:
                                                                           000 = PLLSYSCLK (default on reset)
                                                                           001 = PLLRAWCLK
                                                                           010 = CPU1.SYSCLK
                                                                           011 = CPU2.SYSCLK
                                                                           100 = AUXPLLRAWCLK
                                                                           101 = INTOSC1
                                                                           110 = INTOSC2
                                                                           111 = Reserved
                                                                           Reset type: CPU1.SYSRSn */
                  uint32_t RSV_0                     : 29;  /*!< [31: 3] : reserved. */
        } CLKSRCCTL3b;
    };

    union
    {
        __IOM uint32_t SYSPLLCTL1                        ;  /*!< 0x0000001c : SYSPLL Control register-1 */

        struct
        {
            __IOM uint32_t PLLEN                     : 1 ;  /*!< [ 0: 0] : SYSPLL enabled or disabled: This bit decides if the SYSPLL is enabled or not
                                                                           1 = SYSPLL is enabled
                                                                           0 = SYSPLL is powered off. Clock to system is direct feed from OSCCLK
                                                                           Reset type: XRSn */
            __IOM uint32_t PLLCLKEN                  : 1 ;  /*!< [ 1: 1] : SYSPLL bypassed or included in the PLLSYSCLK path: This bit decides if the SYSPLL is bypassed when PLLSYSCLK is generated
                                                                           1 = PLLSYSCLK is fed from the SYSPLL clock output. Users need to make sure that the PLL is locked before enabling this clock to the system.
                                                                           0 = SYSPLL is bypassed. Clock to system is direct feed from OSCCLK
                                                                           Reset type: XRSn */
                  uint32_t RSV_0                     : 14;  /*!< [15: 2] : reserved. */
            __IOM uint32_t PLL_LDO_EN                : 1 ;  /*!< [16:16] : LDO enable control ; 1: enable  0:disable. */
            __IOM uint32_t PLL_LPF                   : 2 ;  /*!< [18:17] : PLL LPF  resistor adjust. */
            __IOM uint32_t PLL_ICP                   : 3 ;  /*!< [21:19] : PLL cp current adjust reg. */
            __IOM uint32_t PLL_VCO_BAND              : 1 ;  /*!< [22:22] : vco band sel  1: higher frequecy band. */
            __IOM uint32_t PLL_CKREF_DIV             : 3 ;  /*!< [25:23] : fckref_div=fref/(N+2). */
            __IOM uint32_t PLL_CKREF_SEL             : 1 ;  /*!< [26:26] : 0: fref_pll=fref  1:fref_pll=fckref_div. */
            __IOM uint32_t LDO_RSTB                  : 1 ;  /*!< [27:27] : 0 : SYSPLL is under reset. */
                  uint32_t RSV_1                     : 4 ;  /*!< [31:28] : reserved. */
        } SYSPLLCTL1b;
    };

    uint8_t    RSV_0X2020[8]                             ;
    union
    {
        __IOM uint32_t SYSPLLMULT                        ;  /*!< 0x00000028 : SYSPLL Multiplier register */

        struct
        {
            __IOM uint32_t FCW_SSC                   : 19;  /*!< [18: 0] : PLL divider ratio control word; Integer and Fractional. */
            __IOM uint32_t REG_DOT_FCW               : 3 ;  /*!< [21:19] : decimal point for FCW_SSC
                                                                           3'b000 : 4.15
                                                                           3'b001 : 5.14
                                                                           3'b001 : 5.14
                                                                           3'b010 : 6.13
                                                                           3'b011 : 7.12
                                                                           3'b100 : 8.11 */
                  uint32_t RSV_0                     : 8 ;  /*!< [29:22] : reserved. */
            __IOM uint32_t BYPASS_PI                 : 1 ;  /*!< [30:30] : BYPASS PLL PI control
                                                                           1:bypass PI */
            __IOM uint32_t ORDER                     : 1 ;  /*!< [31:31] : digital sigma delta modulator order sel
                                                                           1: order=2
                                                                           0: order=1 */
        } SYSPLLMULTb;
    };

    union
    {
        __IM  uint32_t SYSPLLSTS                         ;  /*!< 0x0000002c : SYSPLL Status register */

        struct
        {
            __IM  uint32_t LOCKS                     : 1 ;  /*!< [ 0: 0] : SYSPLL Lock Status Bit: This bit indicates whether the SYSPLL is locked or not
                                                                           0 = SYSPLL is not yet locked 1 = SYSPLL is locked
                                                                           Reset type: XRSn */
                  uint32_t RSV_0                     : 31;  /*!< [31: 1] : reserved. */
        } SYSPLLSTSb;
    };

    union
    {
        __IOM uint32_t AUXPLLCTL1                        ;  /*!< 0x00000030 : AUXPLL Control register-1 */

        struct
        {
            __IOM uint32_t PLLEN                     : 1 ;  /*!< [ 0: 0] : AUXPLL enabled or disabled: This bit decides if the AUXPLL is enabled or not
                                                                           1 = AUXPLL is enabled
                                                                           0 = AUXPLL is powered off. Clock to system is direct feed from AUXOSCCLK
                                                                           Reset type: XRSn */
            __IOM uint32_t PLLCLKEN                  : 1 ;  /*!< [ 1: 1] : AUXPLL bypassed or included in the AUXPLLCLK path: This bit decides if the AUXPLL is bypassed when AUXPLLCLK is generated
                                                                           1 = AUXPLLCLK is fed from the AUXPLL clock output. Users need to make sure that the PLL is locked before enabling this clock to the AUXPLLCLK connected modules.
                                                                           0 = AUXPLL is bypassed. Clock to modules connected to AUXPLLCLK is direct feed from AUXOSCCLK
                                                                           Reset type: XRSn */
                  uint32_t RSV_0                     : 14;  /*!< [15: 2] : reserved. */
            __IOM uint32_t PLL_LDO_EN                : 1 ;  /*!< [16:16] : LDO enable control ; 1: enable  0:disable. */
            __IOM uint32_t PLL_LPF                   : 2 ;  /*!< [18:17] : PLL LPF  resistor adjust. */
            __IOM uint32_t PLL_ICP                   : 3 ;  /*!< [21:19] : PLL cp current adjust reg. */
            __IOM uint32_t PLL_VCO_BAND              : 1 ;  /*!< [22:22] : vco band sel  1: higher frequecy band. */
            __IOM uint32_t PLL_CKREF_DIV             : 3 ;  /*!< [25:23] : fckref_div=fref/(N+2). */
            __IOM uint32_t PLL_CKREF_SEL             : 1 ;  /*!< [26:26] : 0: fref_pll=fref  1:fref_pll=fckref_div. */
            __IOM uint32_t LDO_RSTB                  : 1 ;  /*!< [27:27] : 0 : AUXPLL is under reset. */
                  uint32_t RSV_1                     : 4 ;  /*!< [31:28] : reserved. */
        } AUXPLLCTL1b;
    };

    uint8_t    RSV_0X2034[8]                             ;
    union
    {
        __IOM uint32_t AUXPLLMULT                        ;  /*!< 0x0000003c : AUXPLL Multiplier register */

        struct
        {
            __IOM uint32_t FCW_SSC                   : 19;  /*!< [18: 0] : PLL divider ratio control word; Integer and Fractional. */
            __IOM uint32_t REG_DOT_FCW               : 3 ;  /*!< [21:19] : decimal point for FCW_SSC
                                                                           3'b000 : 4.15
                                                                           3'b001 : 5.14
                                                                           3'b001 : 5.14
                                                                           3'b010 : 6.13
                                                                           3'b011 : 7.12
                                                                           3'b100 : 8.11 */
                  uint32_t RSV_0                     : 8 ;  /*!< [29:22] : reserved. */
            __IOM uint32_t BYPASS_PI                 : 1 ;  /*!< [30:30] : BYPASS PLL PI control
                                                                           1:bypass PI */
            __IOM uint32_t ORDER                     : 1 ;  /*!< [31:31] : digital sigma delta modulator order sel
                                                                           1: order=2
                                                                           0: order=1 */
        } AUXPLLMULTb;
    };

    union
    {
        __IM  uint32_t AUXPLLSTS                         ;  /*!< 0x00000040 : AUXPLL Status register */

        struct
        {
            __IM  uint32_t LOCKS                     : 1 ;  /*!< [ 0: 0] : AUXPLL Lock Status Bit: This bit indicates whether the AUXPLL is
                                                                           locked or not
                                                                           0 = AUXPLL is not yet locked
                                                                           1 = AUXPLL is locked
                                                                           Reset type: XRSn */
                  uint32_t RSV_0                     : 31;  /*!< [31: 1] : reserved. */
        } AUXPLLSTSb;
    };

    union
    {
        __IOM uint32_t SYSCLKDIVSEL                      ;  /*!< 0x00000044 : System Clock Divider Select register */

        struct
        {
            __IOM uint32_t PLLSYSCLKDIV              : 6 ;  /*!< [ 5: 0] : PLLSYSCLK Divide Select: This bit selects the divider setting for the PLLSYSCLK.
                                                                           000000 = /1
                                                                           000001 = /2
                                                                           000010 = /4 (default on reset)
                                                                           000011 = /6
                                                                           000100 = /8
                                                                           ......
                                                                           111111 = /126
                                                                           Reset type: XRSn */
                  uint32_t RSV_0                     : 26;  /*!< [31: 6] : reserved. */
        } SYSCLKDIVSELb;
    };

    union
    {
        __IOM uint32_t AUXCLKDIVSEL                      ;  /*!< 0x00000048 : Auxillary Clock Divider Select register */

        struct
        {
            __IOM uint32_t AUXPLLDIV                 : 2 ;  /*!< [ 1: 0] : AUXPLLCLK Divide Select: This bit selects the divider setting for the AUXPLLCK.
                                                                           00 = /1
                                                                           01 = /2 (default on reset)
                                                                           10 = /4
                                                                           11 = /8
                                                                           Reset type: XRSn */
                  uint32_t RSV_0                     : 30;  /*!< [31: 2] : reserved. */
        } AUXCLKDIVSELb;
    };

    union
    {
        __IOM uint32_t PERCLKDIVSEL                      ;  /*!< 0x0000004c : Peripheral Clock Divider Selet register */

        struct
        {
                  uint32_t RSV_0                     : 4 ;  /*!< [ 3: 0] : reserved. */
            __IOM uint32_t EMIF1CLKDIV               : 1 ;  /*!< [ 4: 4] : EMIF1 Clock Divide Select: This bit selects whether the EMIF1
                                                                           module run with a /1 or /2 clock.
                                                                           For single core device
                                                                           0: /1 of CPU2.SYSCLK is selected
                                                                           1: /2 of CPU2.SYSCLK is selected
                                                                           For Dual core device
                                                                           0: /1 of PLLSYSCLK is selected
                                                                           1: /2 of PLLSYSCLK is selected
                                                                           Reset type: CPU2.SYSRSn */
                  uint32_t RSV_1                     : 27;  /*!< [31: 5] : reserved. */
        } PERCLKDIVSELb;
    };

    union
    {
        __IOM uint32_t XCLKOUTDIVSEL                     ;  /*!< 0x00000050 : XCLKOUT Divider Select register */

        struct
        {
            __IOM uint32_t XCLKOUTDIV                : 2 ;  /*!< [ 1: 0] : XCLKOUT Divide Select: This bit selects the divider setting for the XCLKOUT.
                                                                           00 = /1
                                                                           01 = /2
                                                                           10 = /4
                                                                           11 = /8 (default on reset) Reset type: CPU1.SYSRSn */
                  uint32_t RSV_0                     : 30;  /*!< [31: 2] : reserved. */
        } XCLKOUTDIVSELb;
    };

    uint8_t    RSV_0X2054[8]                             ;
    union
    {
        __IOM uint32_t MCDCR                             ;  /*!< 0x0000005c : Missing Clock Detect Control Register */

        struct
        {
            __IM  uint32_t MCLKSTS                   : 1 ;  /*!< [ 0: 0] : Missing Clock Status Bit:
                                                                           0 = OSCCLK Is OK
                                                                           1 = OSCCLK Detected Missing, CLOCKFAILn Generated Reset type: XRSn */
            __IOM uint32_t MCLKCLR                   : 1 ;  /*!< [ 1: 1] : Missing Clock Clear Bit:
                                                                           Write 1" to this bit to clear MCLKSTS bit and reset the missing clock detect circuit."
                                                                           Reset type: XRSn */
            __IOM uint32_t MCLKOFF                   : 1 ;  /*!< [ 2: 2] : Missing Clock Detect Off Bit:
                                                                           0 = Missing Clock Detect Circuit Enabled 1 = Missing Clock Detect Circuit Disabled
                                                                           Reset type: XRSn */
            __IOM uint32_t OSCOFF                    : 1 ;  /*!< [ 3: 3] : Oscillator Clock Off Bit:
                                                                           0 = OSCCLK Connected to OSCCLK Counter in MCD module
                                                                           1 = OSCCLK Disconnected to OSCCLK Counter in MCD module Reset type: XRSn */
                  uint32_t RSV_0                     : 28;  /*!< [31: 4] : reserved. */
        } MCDCRb;
    };

    union
    {
        __IM  uint32_t X1CNT                             ;  /*!< 0x00000060 : 10-bit Counter on X1 Clock */

        struct
        {
            __IM  uint32_t X1CNT                     : 10;  /*!< [ 9: 0] : X1 Counter:
                                                                           - This counter increments on every X1 CLOCKs positive-edge.
                                                                           - Once it reaches the values of 0x3ff, it freezes
                                                                           - Before switching from INTOSC2 to X1, application must check this counter and make sure that it has saturated. This will ensure that the Crystal connected to X1/X2 is oscillating.
                                                                           Reset type: POR */
                  uint32_t RSV_0                     : 22;  /*!< [31:10] : reserved. */
        } X1CNTb;
    };

    uint8_t    RSV_0X2064[924]                           ;
} CLK_CFG_REGS_Type;

/*! \brief CPU_SYS_REGS register */
typedef struct {
    union
    {
        __IOM uint32_t CPUSYSLOCK1                       ;  /*!< 0x00000000 : Lock bit for CPUSYS registers */

        struct
        {
                  uint32_t RSV_0                     : 3 ;  /*!< [ 2: 0] : reserved. */
            __IOM uint32_t PCLKCR0                   : 1 ;  /*!< [ 3: 3] : Lock bit for PCLKCR0 Register:
                                                                           0: Respective register is not locked 1: Respective register is locked.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PCLKCR1                   : 1 ;  /*!< [ 4: 4] : Lock bit for PCLKCR1 Register:
                                                                           0: Respective register is not locked 1: Respective register is locked.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PCLKCR2                   : 1 ;  /*!< [ 5: 5] : Lock bit for PCLKCR2 Register:
                                                                           0: Respective register is not locked 1: Respective register is locked.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PCLKCR3                   : 1 ;  /*!< [ 6: 6] : Lock bit for PCLKCR3 Register:
                                                                           0: Respective register is not locked 1: Respective register is locked.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PCLKCR4                   : 1 ;  /*!< [ 7: 7] : Lock bit for PCLKCR4 Register:
                                                                           0: Respective register is not locked 1: Respective register is locked.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PCLKCR5                   : 1 ;  /*!< [ 8: 8] : Lock bit for PCLKCR5 Register:
                                                                           0: Respective register is not locked 1: Respective register is locked.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PCLKCR6                   : 1 ;  /*!< [ 9: 9] : Lock bit for PCLKCR6 Register:
                                                                           0: Respective register is not locked 1: Respective register is locked.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PCLKCR7                   : 1 ;  /*!< [10:10] : Lock bit for PCLKCR7 Register:
                                                                           0: Respective register is not locked 1: Respective register is locked.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PCLKCR8                   : 1 ;  /*!< [11:11] : Lock bit for PCLKCR8 Register:
                                                                           0: Respective register is not locked 1: Respective register is locked.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PCLKCR9                   : 1 ;  /*!< [12:12] : Lock bit for PCLKCR9 Register:
                                                                           0: Respective register is not locked 1: Respective register is locked.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PCLKCR10                  : 1 ;  /*!< [13:13] : Lock bit for PCLKCR10 Register: 0: Respective register is not locked 1: Respective register is locked.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PCLKCR11                  : 1 ;  /*!< [14:14] : Lock bit for PCLKCR11 Register: 0: Respective register is not locked 1: Respective register is locked.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PCLKCR12                  : 1 ;  /*!< [15:15] : Lock bit for PCLKCR12 Register: 0: Respective register is not locked 1: Respective register is locked.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PCLKCR13                  : 1 ;  /*!< [16:16] : Lock bit for PCLKCR13 Register: 0: Respective register is not locked 1: Respective register is locked.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PCLKCR14                  : 1 ;  /*!< [17:17] : Lock bit for PCLKCR14 Register: 0: Respective register is not locked 1: Respective register is locked.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PCLKCR15                  : 1 ;  /*!< [18:18] : Lock bit for PCLKCR15 Register: 0: Respective register is not locked 1: Respective register is locked.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PCLKCR16                  : 1 ;  /*!< [19:19] : Lock bit for PCLKCR16 Register: 0: Respective register is not locked 1: Respective register is locked.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_1                     : 1 ;  /*!< [20:20] : reserved. */
            __IOM uint32_t LPMCR                     : 1 ;  /*!< [21:21] : Lock bit for LPMCR Register:
                                                                           0: Respective register is not locked 1: Respective register is locked.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIOLPMSEL0               : 1 ;  /*!< [22:22] : Lock bit for GPIOLPMSEL0 Register: 0: Respective register is not locked 1: Respective register is locked.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIOLPMSEL1               : 1 ;  /*!< [23:23] : Lock bit for GPIOLPMSEL1 Register: 0: Respective register is not locked 1: Respective register is locked.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PCLKCR17                  : 1 ;  /*!< [24:24] : Lock bit for PCLKCR17 Register: 0: Respective register is not locked 1: Respective register is locked.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_2                     : 7 ;  /*!< [31:25] : reserved. */
        } CPUSYSLOCK1b;
    };

    uint8_t    RSV_0X2404[64]                            ;
    union
    {
        __IOM uint32_t PCLKCR0                           ;  /*!< 0x00000044 : Peripheral Clock Gating Registers */

        struct
        {
                  uint32_t RSV_0                     : 2 ;  /*!< [ 1: 0] : reserved. */
            __IOM uint32_t DMA                       : 1 ;  /*!< [ 2: 2] : DMA Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t CPUTIMER0                 : 1 ;  /*!< [ 3: 3] : CPUTIMER0 Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t CPUTIMER1                 : 1 ;  /*!< [ 4: 4] : CPUTIMER1 Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t CPUTIMER2                 : 1 ;  /*!< [ 5: 5] : CPUTIMER2 Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_1                     : 2 ;  /*!< [ 7: 6] : reserved. */
            __IOM uint32_t DWCPUTIMER0               : 1 ;  /*!< [ 8: 8] : DWCPUTIMER0 Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t DWCPUTIMER1               : 1 ;  /*!< [ 9: 9] : DWCPUTIMER1 Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t DWCPUTIMER2               : 1 ;  /*!< [10:10] : DWCPUTIMER2 Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_2                     : 7 ;  /*!< [17:11] : reserved. */
            __IOM uint32_t TBCLKSYNC                 : 1 ;  /*!< [18:18] : EPWM Time Base Clock sync: When set PWM time bases of all the PWM modules belonging to the same CPU-Subsystem (as partitioned using their CPUSEL bits) start counting. This bit only impacts the TBCTR of all EPWM modules. Everything except the TBCTR of each module enabled in PCLKCR2 will still be clocked by EPWMCLK.
                                                                           Notes:
                                                                           1. This bit from CPU1.PCLKCR0 or CPU2.PCLKCR0 is selected and fed to the individual EPWM modules based on their respective CPUSEL bit.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GTBCLKSYNC                : 1 ;  /*!< [19:19] : EPWM Time Base Clock Global sync: When set by CPU1, PWM time bases of all modules start counting. The effect of this bit is seen on all the EPMW modules irrespective of their partitioning based on CPUSEL
                                                                           Notes:
                                                                           1. This bit on the CPU2.PCLKCR0 register has no effect.
                                                                           2. Writing '1' to this bit overrides the effect of write '1' to the TBCLKSYNC bit at the same time
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_3                     : 12;  /*!< [31:20] : reserved. */
        } PCLKCR0b;
    };

    uint8_t    RSV_0X2448[4]                             ;
    union
    {
        __IOM uint32_t PCLKCR2                           ;  /*!< 0x0000004c : Peripheral Clock Gating Registers */

        struct
        {
            __IOM uint32_t EPWM1                     : 1 ;  /*!< [ 0: 0] : EPWM1 Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t EPWM2                     : 1 ;  /*!< [ 1: 1] : EPWM2 Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t EPWM3                     : 1 ;  /*!< [ 2: 2] : EPWM3 Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t EPWM4                     : 1 ;  /*!< [ 3: 3] : EPWM4 Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t EPWM5                     : 1 ;  /*!< [ 4: 4] : EPWM5 Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t EPWM6                     : 1 ;  /*!< [ 5: 5] : EPWM6 Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t EPWM7                     : 1 ;  /*!< [ 6: 6] : EPWM7 Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t EPWM8                     : 1 ;  /*!< [ 7: 7] : EPWM8 Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t EPWM9                     : 1 ;  /*!< [ 8: 8] : EPWM9 Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t EPWM10                    : 1 ;  /*!< [ 9: 9] : EPWM10 Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t EPWM11                    : 1 ;  /*!< [10:10] : EPWM11 Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t EPWM12                    : 1 ;  /*!< [11:11] : EPWM12 Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 20;  /*!< [31:12] : reserved. */
        } PCLKCR2b;
    };

    union
    {
        __IOM uint32_t PCLKCR3                           ;  /*!< 0x00000050 : Peripheral Clock Gating Registers */

        struct
        {
            __IOM uint32_t ECAP1                     : 1 ;  /*!< [ 0: 0] : ECAP1 Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t ECAP2                     : 1 ;  /*!< [ 1: 1] : ECAP2 Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t ECAP3                     : 1 ;  /*!< [ 2: 2] : ECAP3 Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t ECAP4                     : 1 ;  /*!< [ 3: 3] : ECAP4 Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t ECAP5                     : 1 ;  /*!< [ 4: 4] : ECAP5 Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t ECAP6                     : 1 ;  /*!< [ 5: 5] : ECAP6 Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 26;  /*!< [31: 6] : reserved. */
        } PCLKCR3b;
    };

    union
    {
        __IOM uint32_t PCLKCR4                           ;  /*!< 0x00000054 : Peripheral Clock Gating Registers */

        struct
        {
            __IOM uint32_t EQEP1                     : 1 ;  /*!< [ 0: 0] : EQEP1 Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t EQEP2                     : 1 ;  /*!< [ 1: 1] : EQEP2 Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t EQEP3                     : 1 ;  /*!< [ 2: 2] : EQEP3 Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 29;  /*!< [31: 3] : reserved. */
        } PCLKCR4b;
    };

    uint8_t    RSV_0X2458[4]                             ;
    union
    {
        __IOM uint32_t PCLKCR6                           ;  /*!< 0x0000005c : Peripheral Clock Gating Registers */

        struct
        {
            __IOM uint32_t SD1                       : 1 ;  /*!< [ 0: 0] : SD1 Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SD2                       : 1 ;  /*!< [ 1: 1] : SD2 Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 30;  /*!< [31: 2] : reserved. */
        } PCLKCR6b;
    };

    union
    {
        __IOM uint32_t PCLKCR7                           ;  /*!< 0x00000060 : Peripheral Clock Gating Registers */

        struct
        {
            __IOM uint32_t SCI_A                     : 1 ;  /*!< [ 0: 0] : SCI_A Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SCI_B                     : 1 ;  /*!< [ 1: 1] : SCI_B Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SCI_C                     : 1 ;  /*!< [ 2: 2] : SCI_C Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SCI_D                     : 1 ;  /*!< [ 3: 3] : SCI_D Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 28;  /*!< [31: 4] : reserved. */
        } PCLKCR7b;
    };

    union
    {
        __IOM uint32_t PCLKCR8                           ;  /*!< 0x00000064 : Peripheral Clock Gating Registers */

        struct
        {
            __IOM uint32_t SPI_A                     : 1 ;  /*!< [ 0: 0] : SPI_A Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SPI_B                     : 1 ;  /*!< [ 1: 1] : SPI_B Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SPI_C                     : 1 ;  /*!< [ 2: 2] : SPI_C Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 29;  /*!< [31: 3] : reserved. */
        } PCLKCR8b;
    };

    union
    {
        __IOM uint32_t PCLKCR9                           ;  /*!< 0x00000068 : Peripheral Clock Gating Registers */

        struct
        {
            __IOM uint32_t I2C_A                     : 1 ;  /*!< [ 0: 0] : I2C_A Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t I2C_B                     : 1 ;  /*!< [ 1: 1] : I2C_B Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 14;  /*!< [15: 2] : reserved. */
            __IOM uint32_t PMBUS_A                   : 1 ;  /*!< [16:16] : PMBus_A Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_1                     : 15;  /*!< [31:17] : reserved. */
        } PCLKCR9b;
    };

    union
    {
        __IOM uint32_t PCLKCR10                          ;  /*!< 0x0000006c : Peripheral Clock Gating Registers */

        struct
        {
            __IOM uint32_t CAN_A                     : 1 ;  /*!< [ 0: 0] : CAN_A Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t CAN_B                     : 1 ;  /*!< [ 1: 1] : CAN_B Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t CAN_C                     : 1 ;  /*!< [ 2: 2] : CAN_C Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 29;  /*!< [31: 3] : reserved. */
        } PCLKCR10b;
    };

    union
    {
        __IOM uint32_t PCLKCR11                          ;  /*!< 0x00000070 : Peripheral Clock Gating Registers */

        struct
        {
                  uint32_t RSV_0                     : 16;  /*!< [15: 0] : reserved. */
            __IOM uint32_t USB_A                     : 1 ;  /*!< [16:16] : USB_A Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_1                     : 15;  /*!< [31:17] : reserved. */
        } PCLKCR11b;
    };

    uint8_t    RSV_0X2474[4]                             ;
    union
    {
        __IOM uint32_t PCLKCR13                          ;  /*!< 0x00000078 : Peripheral Clock Gating Registers */

        struct
        {
            __IOM uint32_t ADC_A                     : 1 ;  /*!< [ 0: 0] : ADC_A Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t ADC_B                     : 1 ;  /*!< [ 1: 1] : ADC_B Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t ADC_C                     : 1 ;  /*!< [ 2: 2] : ADC_C Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t ADC_D                     : 1 ;  /*!< [ 3: 3] : ADC_D Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 28;  /*!< [31: 4] : reserved. */
        } PCLKCR13b;
    };

    union
    {
        __IOM uint32_t PCLKCR14                          ;  /*!< 0x0000007c : Peripheral Clock Gating Registers */

        struct
        {
            __IOM uint32_t CMPSS1                    : 1 ;  /*!< [ 0: 0] : CMPSS1 Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t CMPSS2                    : 1 ;  /*!< [ 1: 1] : CMPSS2 Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t CMPSS3                    : 1 ;  /*!< [ 2: 2] : CMPSS3 Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t CMPSS4                    : 1 ;  /*!< [ 3: 3] : CMPSS4 Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t CMPSS5                    : 1 ;  /*!< [ 4: 4] : CMPSS5 Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t CMPSS6                    : 1 ;  /*!< [ 5: 5] : CMPSS6 Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t CMPSS7                    : 1 ;  /*!< [ 6: 6] : CMPSS7 Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t CMPSS8                    : 1 ;  /*!< [ 7: 7] : CMPSS8 Clock Enable bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 24;  /*!< [31: 8] : reserved. */
        } PCLKCR14b;
    };

    uint8_t    RSV_0X2480[4]                             ;
    union
    {
        __IOM uint32_t PCLKCR16                          ;  /*!< 0x00000084 : Peripheral Clock Gating Registers */

        struct
        {
                  uint32_t RSV_0                     : 16;  /*!< [15: 0] : reserved. */
            __IOM uint32_t DAC_A                     : 1 ;  /*!< [16:16] : Buffered_DAC_A Clock Enable Bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t DAC_B                     : 1 ;  /*!< [17:17] : Buffered_DAC_B Clock Enable Bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t DAC_C                     : 1 ;  /*!< [18:18] : Buffered_DAC_C Clock Enable Bit:
                                                                           0: Module clock is gated-off 1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_1                     : 13;  /*!< [31:19] : reserved. */
        } PCLKCR16b;
    };

    union
    {
        __IOM uint32_t PCLKCR17                          ;  /*!< 0x00000088 : Peripheral Clock Gating Registers */

        struct
        {
            __IOM uint32_t CLB1                      : 1 ;  /*!< [ 0: 0] : CLB1 Clock Enable bit:
                                                                           0: Module clock is gated-off
                                                                           1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t CLB2                      : 1 ;  /*!< [ 1: 1] : CLB2 Clock Enable bit:
                                                                           0: Module clock is gated-off
                                                                           1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t CLB3                      : 1 ;  /*!< [ 2: 2] : CLB3 Clock Enable bit:
                                                                           0: Module clock is gated-off
                                                                           1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t CLB4                      : 1 ;  /*!< [ 3: 3] : CLB4 Clock Enable bit:
                                                                           0: Module clock is gated-off
                                                                           1: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t CLB5                      : 1 ;  /*!< [ 4: 4] : CLB1 Clock Enable bit:
                                                                           0: Module clock is gated-off
                                                                           0: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t CLB6                      : 1 ;  /*!< [ 5: 5] : CLB2 Clock Enable bit:
                                                                           0: Module clock is gated-off
                                                                           0: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t CLB7                      : 1 ;  /*!< [ 6: 6] : CLB3 Clock Enable bit:
                                                                           0: Module clock is gated-off
                                                                           0: Module clock is turned-on
                                                                           Reset type: SYSRSn */
            __IOM uint32_t CLB8                      : 1 ;  /*!< [ 7: 7] : CLB4 Clock Enable bit:
                                                                           0: Module clock is gated-off
                                                                           0: Module clock is turned-on
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 24;  /*!< [31: 8] : reserved. */
        } PCLKCR17b;
    };

    uint8_t    RSV_0X248C[96]                            ;
    union
    {
        __IOM uint32_t LPMCR                             ;  /*!< 0x000000ec : LPM Control Register */

        struct
        {
                  uint32_t RSV_0                     : 2 ;  /*!< [ 1: 0] : reserved. */
            __IOM uint32_t QUALSTDBY                 : 6 ;  /*!< [ 7: 2] : Select number of OSCCLK clock cycles to qualify the selected inputs when waking the from STANDBY mode:
                                                                           000000 = 2 OSCCLKs
                                                                           000001 = 3 OSCCLKs
                                                                           ......
                                                                           111111 = 65 OSCCLKs
                                                                           Note: The LPMCR.QUALSTDBY register should be set to a value greater than the ratio of INTOSC1/PLLSYSCLK to ensure proper wake up.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_1                     : 24;  /*!< [31: 8] : reserved. */
        } LPMCRb;
    };

    union
    {
        __IOM uint32_t GPIOLPMSEL0                       ;  /*!< 0x000000f0 : GPIO LPM Wakeup select registers */

        struct
        {
            __IOM uint32_t GPIO0                     : 1 ;  /*!< [ 0: 0] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO1                     : 1 ;  /*!< [ 1: 1] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO2                     : 1 ;  /*!< [ 2: 2] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO3                     : 1 ;  /*!< [ 3: 3] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO4                     : 1 ;  /*!< [ 4: 4] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO5                     : 1 ;  /*!< [ 5: 5] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO6                     : 1 ;  /*!< [ 6: 6] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO7                     : 1 ;  /*!< [ 7: 7] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO8                     : 1 ;  /*!< [ 8: 8] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO9                     : 1 ;  /*!< [ 9: 9] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO10                    : 1 ;  /*!< [10:10] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO11                    : 1 ;  /*!< [11:11] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO12                    : 1 ;  /*!< [12:12] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO13                    : 1 ;  /*!< [13:13] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO14                    : 1 ;  /*!< [14:14] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO15                    : 1 ;  /*!< [15:15] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO16                    : 1 ;  /*!< [16:16] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO17                    : 1 ;  /*!< [17:17] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO18                    : 1 ;  /*!< [18:18] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO19                    : 1 ;  /*!< [19:19] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO20                    : 1 ;  /*!< [20:20] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO21                    : 1 ;  /*!< [21:21] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO22                    : 1 ;  /*!< [22:22] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO23                    : 1 ;  /*!< [23:23] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO24                    : 1 ;  /*!< [24:24] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO25                    : 1 ;  /*!< [25:25] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO26                    : 1 ;  /*!< [26:26] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO27                    : 1 ;  /*!< [27:27] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO28                    : 1 ;  /*!< [28:28] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO29                    : 1 ;  /*!< [29:29] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO30                    : 1 ;  /*!< [30:30] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO31                    : 1 ;  /*!< [31:31] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
        } GPIOLPMSEL0b;
    };

    union
    {
        __IOM uint32_t GPIOLPMSEL1                       ;  /*!< 0x000000f4 : GPIO LPM Wakeup select registers */

        struct
        {
            __IOM uint32_t GPIO32                    : 1 ;  /*!< [ 0: 0] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO33                    : 1 ;  /*!< [ 1: 1] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO34                    : 1 ;  /*!< [ 2: 2] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO35                    : 1 ;  /*!< [ 3: 3] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO36                    : 1 ;  /*!< [ 4: 4] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO37                    : 1 ;  /*!< [ 5: 5] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO38                    : 1 ;  /*!< [ 6: 6] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO39                    : 1 ;  /*!< [ 7: 7] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO40                    : 1 ;  /*!< [ 8: 8] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO41                    : 1 ;  /*!< [ 9: 9] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO42                    : 1 ;  /*!< [10:10] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO43                    : 1 ;  /*!< [11:11] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO44                    : 1 ;  /*!< [12:12] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO45                    : 1 ;  /*!< [13:13] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO46                    : 1 ;  /*!< [14:14] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO47                    : 1 ;  /*!< [15:15] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO48                    : 1 ;  /*!< [16:16] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO49                    : 1 ;  /*!< [17:17] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO50                    : 1 ;  /*!< [18:18] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO51                    : 1 ;  /*!< [19:19] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO52                    : 1 ;  /*!< [20:20] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO53                    : 1 ;  /*!< [21:21] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO54                    : 1 ;  /*!< [22:22] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO55                    : 1 ;  /*!< [23:23] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO56                    : 1 ;  /*!< [24:24] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO57                    : 1 ;  /*!< [25:25] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO58                    : 1 ;  /*!< [26:26] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO59                    : 1 ;  /*!< [27:27] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO60                    : 1 ;  /*!< [28:28] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO61                    : 1 ;  /*!< [29:29] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO62                    : 1 ;  /*!< [30:30] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
            __IOM uint32_t GPIO63                    : 1 ;  /*!< [31:31] : 0 pin is dis-connected from LPM circuit 1 pin is connected to LPM circuit
                                                                           Reset type: SYSRSn */
        } GPIOLPMSEL1b;
    };

    union
    {
        __IOM uint32_t TMR2CLKCTL                        ;  /*!< 0x000000f8 : Timer2 Clock Measurement functionality control register */

        struct
        {
            __IOM uint32_t TMR2CLKSRCSEL             : 3 ;  /*!< [ 2: 0] : CPU Timer 2 Clock Source Select Bit: This bit selects the source for CPU Timer 2:
                                                                           000 =SYSPCLK Selected (default on reset, pre-scale is bypassed)
                                                                           001 = INTOSC1
                                                                           010 = INTOSC2
                                                                           011 = XTAL
                                                                           100 = Reserved
                                                                           101 = Reserved
                                                                           110 = AUXPLLRAWCLK
                                                                           111 = reserved
                                                                           Reset type: SYSRSn */
            __IOM uint32_t TMR2CLKPRESCALE           : 3 ;  /*!< [ 5: 3] : CPU Timer 2 Clock Pre-Scale Value: These bits select the pre-scale value for the selected clock source for CPU Timer 2:
                                                                           0,0,0,/1 (default on reset)
                                                                           0,0,1,/2,
                                                                           0,1,0,/4
                                                                           0,1,1,/8
                                                                           1,0,0,/16
                                                                           1,0,1,spare (defaults to /16)
                                                                           1,1,0,spare (defaults to /16)
                                                                           1,1,1,spare (defaults to /16)
                                                                           Note:
                                                                           [1] The CPU Timer2s Clock sync logic detects an input clock edge when configured for any clock source other than SYSCLK and generates an appropriate clock pulse to the CPU timer2. If SYSCLK is approximately the same or less then the input clock source, then the user would need to configure the pre-scale value such that SYSCLK is at least twice as fast as the pre-scaled value.
                                                                           [2] Pre-scaler is bypassed if SYSCLK is selected as the source of CPU Timer 2 in TMR2CLKSRCSEL of TMR2CLKCTL.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 26;  /*!< [31: 6] : reserved. */
        } TMR2CLKCTLb;
    };

    uint8_t    RSV_0X24FC[4]                             ;
    union
    {
        __IOM uint32_t RESC                              ;  /*!< 0x00000100 : Reset Cause register */

        struct
        {
            __IOM uint32_t POR                       : 1 ;  /*!< [ 0: 0] : If this bit is set, indicates that the device was reset by PORn.
                                                                           Writing a 1 to this bit will force the bit to 0 Writing of 0 will have no effect.
                                                                           Reset type: POR */
            __IOM uint32_t XRSN                      : 1 ;  /*!< [ 1: 1] : If this bit is set, indicates that the device was reset by XRSn.
                                                                           Writing a 1 to this bit will force the bit to 0 Writing of 0 will have no effect.
                                                                           Reset type: POR */
            __IOM uint32_t WDRSN                     : 1 ;  /*!< [ 2: 2] : If this bit is set, indicates that the device was reset by WDRSn.
                                                                           Writing a 1 to this bit will force the bit to 0 Writing of 0 will have no effect.
                                                                           Reset type: POR */
            __IOM uint32_t NMIWDRSN                  : 1 ;  /*!< [ 3: 3] : If this bit is set, indicates that the device was reset by NMIWDRSn.
                                                                           Writing a 1 to this bit will force the bit to 0 Writing of 0 will have no effect.
                                                                           To know the exact cause of NMI after the reset, software needs to read CPU1/2.NMISHDFLG registers
                                                                           Reset type: POR */
                  uint32_t RSV_0                     : 26;  /*!< [29: 4] : reserved. */
            __IM  uint32_t XRSN_PIN_STATUS           : 1 ;  /*!< [30:30] : Reading this bit provides the current status of the XRSn pin. ResetValue is reflective of the pin status.
                                                                           Reset type: N/A */
            __IM  uint32_t TRSTN_PIN_STATUS          : 1 ;  /*!< [31:31] : Reading this bit provides the current status of TRSTn at the respective C28x CPUs TRSTn input port. ResetValue is reflective of the pin status.
                                                                           Reset type: N/A */
        } RESCb;
    };

    uint8_t    RSV_0X2504[28]                            ;
    union
    {
        __IOM uint32_t DWTMR2CLKCTL                      ;  /*!< 0x00000120 : DWTimer2 Clock Measurement functionality control register */

        struct
        {
            __IOM uint32_t DWTMR2CLKSRCSEL           : 3 ;  /*!< [ 2: 0] : DW CPU Timer 2 Clock Source Select Bit: This bit selects the source for CPU Timer 2:
                                                                           000 =SYSPCLK Selected (default on reset, pre-scale is bypassed)
                                                                           001 = INTOSC1
                                                                           010 = INTOSC2
                                                                           011 = XTAL
                                                                           100 = Reserved
                                                                           101 = Reserved
                                                                           110 = AUXPLLRAWCLK
                                                                           111 = reserved
                                                                           Reset type: SYSRSn */
            __IOM uint32_t DWTMR2CLKPRESCALE         : 3 ;  /*!< [ 5: 3] : DW CPU Timer 2 Clock Pre-Scale Value: These bits select the pre-scale value for the selected clock source for CPU Timer 2:
                                                                           0,0,0,/1 (default on reset)
                                                                           0,0,1,/2,
                                                                           0,1,0,/4
                                                                           0,1,1,/8
                                                                           1,0,0,/16
                                                                           1,0,1,spare (defaults to /16)
                                                                           1,1,0,spare (defaults to /16)
                                                                           1,1,1,spare (defaults to /16)
                                                                           Note:
                                                                           [1] The CPU Timer2s Clock sync logic detects an input clock edge when configured for any clock source other than SYSCLK and generates an appropriate clock pulse to the CPU timer2. If SYSCLK is approximately the same or less then the input clock source, then the user would need to configure the pre-scale value such that SYSCLK is at least twice as fast as the pre-scaled value.
                                                                           [2] Pre-scaler is bypassed if SYSCLK is selected as the source of CPU Timer 2 in TMR2CLKSRCSEL of TMR2CLKCTL.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 26;  /*!< [31: 6] : reserved. */
        } DWTMR2CLKCTLb;
    };

    uint8_t    RSV_0X2524[732]                           ;
} CPU_SYS_REGS_Type;

/*! \brief MEM_CFG_REGS register */
typedef struct {
    uint8_t    RSV_0X2800[224]                           ;
    union
    {
        __IOM uint32_t MSGXTEST                          ;  /*!< 0x000000e0 : Message RAM TEST Register */

        struct
        {
            __IOM uint32_t TEST_CPUTOCPU             : 2 ;  /*!< [ 1: 0] : Selects the different modes for CPUTOCPU MSG RAM:
                                                                           00: Functional Mode.
                                                                           01: Writes are allowed to data bits only. No write to parity bits.
                                                                           10: Writes are allowed to parity bits only. No write to data bits.
                                                                           11: Functional Mode.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 30;  /*!< [31: 2] : reserved. */
        } MSGXTESTb;
    };

    union
    {
        __IOM uint32_t MSGXINIT                          ;  /*!< 0x000000e4 : Message RAM Init Register */

        struct
        {
            __IOM uint32_t INIT_CPUTOCPU             : 1 ;  /*!< [ 0: 0] : RAM Initialization control for CPUTOCPU MSG RAM: 0: None.
                                                                           1: Start RAM Initialization.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 31;  /*!< [31: 1] : reserved. */
        } MSGXINITb;
    };

    union
    {
        __IM  uint32_t MSGXINITDONE                      ;  /*!< 0x000000e8 : Message RAM InitDone Status Register */

        struct
        {
            __IM  uint32_t INITDONE_CPUTOCPU         : 1 ;  /*!< [ 0: 0] : RAM Initialization status for CPUTOCPU MSG RAM:
                                                                           0: RAM Initialization is not done.
                                                                           1: RAM Initialization is done.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 31;  /*!< [31: 1] : reserved. */
        } MSGXINITDONEb;
    };

    uint8_t    RSV_0X28EC[20]                            ;
    union
    {
        __IOM uint32_t TCMXTEST                          ;  /*!< 0x00000100 : TCM TEST Register */

        struct
        {
            __IOM uint32_t TEST_ITCM                 : 2 ;  /*!< [ 1: 0] : Selects the different modes for ITCM:
                                                                           00: Functional Mode.
                                                                           01: Writes are allowed to data bits only. No write to ECC bits.
                                                                           10: Writes are allowed to ECC bits only. No write to data bits.
                                                                           11: Functional Mode.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t TEST_DTCM                 : 2 ;  /*!< [ 3: 2] : Selects the different modes for DTCM:
                                                                           00: Functional Mode.
                                                                           01: Writes are allowed to data bits only. No write to ECC bits.
                                                                           10: Writes are allowed to ECC bits only. No write to data bits.
                                                                           11: Functional Mode.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 28;  /*!< [31: 4] : reserved. */
        } TCMXTESTb;
    };

    union
    {
        __IOM uint32_t TCMXINIT                          ;  /*!< 0x00000104 : TCM Init Register */

        struct
        {
            __IOM uint32_t INIT_ITCM                 : 1 ;  /*!< [ 0: 0] : RAM Initialization control for ITCM:
                                                                           0: None.
                                                                           1: Start RAM Initialization.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t INIT_DTCM                 : 1 ;  /*!< [ 1: 1] : RAM Initialization control for DTCM:
                                                                           0: None.
                                                                           1: Start RAM Initialization.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 30;  /*!< [31: 2] : reserved. */
        } TCMXINITb;
    };

    union
    {
        __IM  uint32_t TCMXINITDONE                      ;  /*!< 0x00000108 : TCM InitDone Status Register */

        struct
        {
            __IM  uint32_t INITDONE_ITCM             : 1 ;  /*!< [ 0: 0] : RAM Initialization status for ITCM:
                                                                           0: RAM Initialization is not done.
                                                                           1: RAM Initialization is done.
                                                                           Reset type: SYSRSn */
            __IM  uint32_t INITDONE_DTCM             : 1 ;  /*!< [ 1: 1] : RAM Initialization status for DTCM:
                                                                           0: RAM Initialization is not done.
                                                                           1: RAM Initialization is done.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 30;  /*!< [31: 2] : reserved. */
        } TCMXINITDONEb;
    };

    uint8_t    RSV_0X290C[756]                           ;
} MEM_CFG_REGS_Type;

/*! \brief ACCESS_PROTECTION_REGS register */
typedef struct {
    union
    {
        __IM  uint32_t NMAVFLG                           ;  /*!< 0x00000000 : Non-Master Access Violation Flag Register */

        struct
        {
                  uint32_t RSV_0                     : 1 ;  /*!< [ 0: 0] : reserved. */
            __IM  uint32_t CPUWRITE                  : 1 ;  /*!< [ 1: 1] : Non Master CPU Write Access Violation Flag: 0: No violation.
                                                                           1: Access violation occured.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_1                     : 1 ;  /*!< [ 2: 2] : reserved. */
            __IM  uint32_t DMAWRITE                  : 1 ;  /*!< [ 3: 3] : Non Master DMA Write Access Violation Flag: 0: No violation.
                                                                           1: Access violation occured.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_2                     : 3 ;  /*!< [ 6: 4] : reserved. */
            __IM  uint32_t USB_A_DMAWRITE            : 1 ;  /*!< [ 7: 7] : Non Master USB_A DMA Write Access Violation Flag: 0: No violation.
                                                                           1: Access violation occured.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_3                     : 24;  /*!< [31: 8] : reserved. */
        } NMAVFLGb;
    };

    union
    {
        __IOM uint32_t NMAVSET                           ;  /*!< 0x00000004 : Non-Master Access Violation Flag Set Register */

        struct
        {
                  uint32_t RSV_0                     : 1 ;  /*!< [ 0: 0] : reserved. */
            __IOM uint32_t CPUWRITE                  : 1 ;  /*!< [ 1: 1] : 0: No action.
                                                                           1: CPU Write Access Violation Flag in NMAVFLG register will be set and interrupt will be generated if enabled..
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_1                     : 1 ;  /*!< [ 2: 2] : reserved. */
            __IOM uint32_t DMAWRITE                  : 1 ;  /*!< [ 3: 3] : 0: No action.
                                                                           1: DMA Write Access Violation Flag in NMAVFLG register will be set and interrupt will be generated if enabled..
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_2                     : 3 ;  /*!< [ 6: 4] : reserved. */
            __IOM uint32_t USB_A_DMAWRITE            : 1 ;  /*!< [ 7: 7] : 0: No action.
                                                                           1: USB_A DMA Write Access Violation Flag in NMAVFLG register will be set and interrupt will be generated if enabled..
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_3                     : 24;  /*!< [31: 8] : reserved. */
        } NMAVSETb;
    };

    union
    {
        __IOM uint32_t NMAVCLR                           ;  /*!< 0x00000008 : Non-Master Access Violation Flag Clear Register */

        struct
        {
                  uint32_t RSV_0                     : 1 ;  /*!< [ 0: 0] : reserved. */
            __IOM uint32_t CPUWRITE                  : 1 ;  /*!< [ 1: 1] : 0: No action.
                                                                           1: CPU Write Access Violation Flag in NMAVFLG register will be cleared.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_1                     : 1 ;  /*!< [ 2: 2] : reserved. */
            __IOM uint32_t DMAWRITE                  : 1 ;  /*!< [ 3: 3] : 0: No action.
                                                                           1: DMA Write Access Violation Flag in NMAVFLG register will be cleared.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_2                     : 3 ;  /*!< [ 6: 4] : reserved. */
            __IOM uint32_t USB_A_DMAWRITE            : 1 ;  /*!< [ 7: 7] : 0: No action.
                                                                           1: USB_A DMA Write Access Violation Flag in NMAVFLG register will be cleared.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_3                     : 24;  /*!< [31: 8] : reserved. */
        } NMAVCLRb;
    };

    union
    {
        __IOM uint32_t NMAVINTEN                         ;  /*!< 0x0000000c : Non-Master Access Violation Interrupt Enable Register */

        struct
        {
                  uint32_t RSV_0                     : 1 ;  /*!< [ 0: 0] : reserved. */
            __IOM uint32_t CPUWRITE                  : 1 ;  /*!< [ 1: 1] : 0: CPU Non Master Write Access Violation Interrupt is disabled. 1: CPU Non Master Write Access Violation Interrupt is enabled.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_1                     : 1 ;  /*!< [ 2: 2] : reserved. */
            __IOM uint32_t DMAWRITE                  : 1 ;  /*!< [ 3: 3] : 0: DMA Non Master Write Access Violation Interrupt is disabled. 1: DMA Non Master Write Access Violation Interrupt is enabled.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_2                     : 3 ;  /*!< [ 6: 4] : reserved. */
            __IOM uint32_t USB_A_DMAWRITE            : 1 ;  /*!< [ 7: 7] : 0: USB_A DMA Non Master Write Access Violation Interrupt is disabled. 1: USB_A DMA Non Master Write Access Violation Interrupt is enabled.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_3                     : 24;  /*!< [31: 8] : reserved. */
        } NMAVINTENb;
    };

    uint8_t    RSV_0X2C10[4]                             ;
    union
    {
        __IM  uint32_t NMCPUWRAVADDR                     ;  /*!< 0x00000014 : Non-Master CPU Write Access Violation Address */

        struct
        {
            __IM  uint32_t NMCPUWRAVADDR             : 32;  /*!< [31: 0] : This register captures the address location for which non master CPU write access vaiolation occurred.
                                                                           Reset type: SYSRSn */
        } NMCPUWRAVADDRb;
    };

    uint8_t    RSV_0X2C18[4]                             ;
    union
    {
        __IM  uint32_t NMDMAWRAVADDR                     ;  /*!< 0x0000001c : Non-Master DMA Write Access Violation Address */

        struct
        {
            __IM  uint32_t NMDMAWRAVADDR             : 32;  /*!< [31: 0] : This register captures the address location for which non master DMA write access vaiolation occurred.
                                                                           Reset type: SYSRSn */
        } NMDMAWRAVADDRb;
    };

    uint8_t    RSV_0X2C20[12]                            ;
    union
    {
        __IM  uint32_t NMUSBADMAWRAVADDR                 ;  /*!< 0x0000002c : Non-Master USB_A DMA Write Access Violation Address */

        struct
        {
            __IM  uint32_t NMUSBADMAWRAVADDR         : 32;  /*!< [31: 0] : This register captures the address location for which non master USB_A DMA write access vaiolation occurred.
                                                                           Reset type: SYSRSn */
        } NMUSBADMAWRAVADDRb;
    };

    uint8_t    RSV_0X2C30[16]                            ;
    union
    {
        __IM  uint32_t MAVFLG                            ;  /*!< 0x00000040 : Master Access Violation Flag Register */

        struct
        {
                  uint32_t RSV_0                     : 1 ;  /*!< [ 0: 0] : reserved. */
            __IM  uint32_t CPUWRITE                  : 1 ;  /*!< [ 1: 1] : Master CPU Write Access Violation Flag: 0: No violation.
                                                                           1: Access violation occured.
                                                                           Reset type: SYSRSn */
            __IM  uint32_t DMAWRITE                  : 1 ;  /*!< [ 2: 2] : Master DMA Write Access Violation Flag: 0: No violation.
                                                                           1: Access violation occured.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_1                     : 29;  /*!< [31: 3] : reserved. */
        } MAVFLGb;
    };

    union
    {
        __IOM uint32_t MAVSET                            ;  /*!< 0x00000044 : Master Access Violation Flag Set Register */

        struct
        {
                  uint32_t RSV_0                     : 1 ;  /*!< [ 0: 0] : reserved. */
            __IOM uint32_t CPUWRITE                  : 1 ;  /*!< [ 1: 1] : 0: No action.
                                                                           1: CPU Write Access Violation Flag in MAVFLG register will be set and interrupt will be generated if enabled..
                                                                           Reset type: SYSRSn */
            __IOM uint32_t DMAWRITE                  : 1 ;  /*!< [ 2: 2] : 0: No action.
                                                                           1: DMA Write Access Violation Flag in MAVFLG register will be set and interrupt will be generated if enabled..
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_1                     : 29;  /*!< [31: 3] : reserved. */
        } MAVSETb;
    };

    union
    {
        __IOM uint32_t MAVCLR                            ;  /*!< 0x00000048 : Master Access Violation Flag Clear Register */

        struct
        {
                  uint32_t RSV_0                     : 1 ;  /*!< [ 0: 0] : reserved. */
            __IOM uint32_t CPUWRITE                  : 1 ;  /*!< [ 1: 1] : 0: No action.
                                                                           1: CPU Write Access Violation Flag in MAVFLG register will be cleared .
                                                                           Reset type: SYSRSn */
            __IOM uint32_t DMAWRITE                  : 1 ;  /*!< [ 2: 2] : 0: No action.
                                                                           1: DMA Write Access Violation Flag in MAVFLG register will be cleared.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_1                     : 29;  /*!< [31: 3] : reserved. */
        } MAVCLRb;
    };

    union
    {
        __IOM uint32_t MAVINTEN                          ;  /*!< 0x0000004c : Master Access Violation Interrupt Enable Register */

        struct
        {
                  uint32_t RSV_0                     : 1 ;  /*!< [ 0: 0] : reserved. */
            __IOM uint32_t CPUWRITE                  : 1 ;  /*!< [ 1: 1] : 0: CPU Write Access Violation Interrupt is disabled. 1: CPU Write Access Violation Interrupt is enabled.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t DMAWRITE                  : 1 ;  /*!< [ 2: 2] : 0: DMA Write Access Violation Interrupt is disabled. 1: DMA Write Access Violation Interrupt is enabled.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_1                     : 29;  /*!< [31: 3] : reserved. */
        } MAVINTENb;
    };

    uint8_t    RSV_0X2C50[4]                             ;
    union
    {
        __IM  uint32_t MCPUWRAVADDR                      ;  /*!< 0x00000054 : Master CPU Write Access Violation Address */

        struct
        {
            __IM  uint32_t MCPUWRAVADDR              : 32;  /*!< [31: 0] : This register captures the address location for which master CPU write access vaiolation occurred.
                                                                           Reset type: SYSRSn */
        } MCPUWRAVADDRb;
    };

    union
    {
        __IM  uint32_t MDMAWRAVADDR                      ;  /*!< 0x00000058 : Master DMA Write Access Violation Address */

        struct
        {
            __IM  uint32_t MDMAWRAVADDR              : 32;  /*!< [31: 0] : This register captures the address location for which master DMA write access vaiolation occurred.
                                                                           Reset type: SYSRSn */
        } MDMAWRAVADDRb;
    };

    uint8_t    RSV_0X2C5C[932]                           ;
} ACCESS_PROTECTION_REGS_Type;

/*! \brief MEMORY_ERROR_REGS register */
typedef struct {
    union
    {
        __IM  uint32_t UCERRFLG                          ;  /*!< 0x00000000 : Uncorrectable Error Flag Register */

        struct
        {
            __IM  uint32_t CPURDERR                  : 1 ;  /*!< [ 0: 0] : CPU Uncorrectable Read Error Flag
                                                                           0: No Error.
                                                                           1: Uncorrectable error occurred during CPU read.
                                                                           Reset type: SYSRSn */
            __IM  uint32_t DMARDERR                  : 1 ;  /*!< [ 1: 1] : DMA Uncorrectable Read Error Flag
                                                                           0: No Error.
                                                                           1: Uncorrectable error occurred during DMA read.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 1 ;  /*!< [ 2: 2] : reserved. */
            __IM  uint32_t USBADMARDERR              : 1 ;  /*!< [ 3: 3] : USB_A DMA Uncorrectable Read Error Flag
                                                                           0: No Error.
                                                                           1: Uncorrectable error occurred during USB_A DMA read.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_1                     : 28;  /*!< [31: 4] : reserved. */
        } UCERRFLGb;
    };

    union
    {
        __IOM uint32_t UCERRSET                          ;  /*!< 0x00000004 : Uncorrectable Error Flag Set Register */

        struct
        {
            __IOM uint32_t CPURDERR                  : 1 ;  /*!< [ 0: 0] : 0: No action.
                                                                           1: CPU Read Error Flag in UCERRFLG register will be set and interrupt will be generated if enabled..
                                                                           Reset type: SYSRSn */
            __IOM uint32_t DMARDERR                  : 1 ;  /*!< [ 1: 1] : 0: No action.
                                                                           1: DMA Read Error Flag in UCERRFLG register will be set and interrupt will be generated if enabled..
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 1 ;  /*!< [ 2: 2] : reserved. */
            __IOM uint32_t USBADMARDERR              : 1 ;  /*!< [ 3: 3] : 0: No action.
                                                                           1: USB_A DMA Read Error Flag in UCERRFLG register will be set and interrupt will be generated if enabled..
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_1                     : 28;  /*!< [31: 4] : reserved. */
        } UCERRSETb;
    };

    union
    {
        __IOM uint32_t UCERRCLR                          ;  /*!< 0x00000008 : Uncorrectable Error Flag Clear Register */

        struct
        {
            __IOM uint32_t CPURDERR                  : 1 ;  /*!< [ 0: 0] : 0: No action.
                                                                           1: CPU Read Error Flag in UCERRFLG register will be cleared. Reset type: SYSRSn */
            __IOM uint32_t DMARDERR                  : 1 ;  /*!< [ 1: 1] : 0: No action.
                                                                           1: DMA Read Error Flag in UCERRFLG register will be cleared . Reset type: SYSRSn */
                  uint32_t RSV_0                     : 1 ;  /*!< [ 2: 2] : reserved. */
            __IOM uint32_t USBADMARDERR              : 1 ;  /*!< [ 3: 3] : 0: No action.
                                                                           1: USB_A DMA Read Error Flag in UCERRFLG register will be cleared . Reset type: SYSRSn */
                  uint32_t RSV_1                     : 28;  /*!< [31: 4] : reserved. */
        } UCERRCLRb;
    };

    union
    {
        __IM  uint32_t UCCPUREADDR                       ;  /*!< 0x0000000c : Uncorrectable CPU Read Error Address */

        struct
        {
            __IM  uint32_t UCCPUREADDR               : 32;  /*!< [31: 0] : This register captures the address location for which CPU read/fetch access resulted in uncorrectable ECC/Parity error.
                                                                           Reset type: SYSRSn */
        } UCCPUREADDRb;
    };

    union
    {
        __IM  uint32_t UCDMAREADDR                       ;  /*!< 0x00000010 : Uncorrectable DMA Read Error Address */

        struct
        {
            __IM  uint32_t UCDMAREADDR               : 32;  /*!< [31: 0] : This register captures the address location for which DMA read access resulted in uncorrectable ECC/Parity error.
                                                                           Reset type: SYSRSn */
        } UCDMAREADDRb;
    };

    uint8_t    RSV_0X3014[4]                             ;
    union
    {
        __IM  uint32_t UCUSBADMAREADDR                   ;  /*!< 0x00000018 : Uncorrectable USB_A DMA Read Error Address */

        struct
        {
            __IM  uint32_t UCUSBADMAREADDR           : 32;  /*!< [31: 0] : This register captures the address location for which USB_A DMA read access resulted in uncorrectable ECC/Parity error.
                                                                           Reset type: SYSRSn */
        } UCUSBADMAREADDRb;
    };

    uint8_t    RSV_0X301C[36]                            ;
    union
    {
        __IM  uint32_t CERRFLG                           ;  /*!< 0x00000040 : Correctable Error Flag Register */

        struct
        {
            __IM  uint32_t CPURDERR                  : 1 ;  /*!< [ 0: 0] : CPU Correctable Read Error Flag 0: No Error.
                                                                           1: Correctable error occurred during CPU read.
                                                                           Reset type: SYSRSn */
            __IM  uint32_t DMARDERR                  : 1 ;  /*!< [ 1: 1] : DMA Correctable Read Error Flag 0: No Error.
                                                                           1: Correctable error occurred during DMA read.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 1 ;  /*!< [ 2: 2] : reserved. */
            __IM  uint32_t USBADMARDERR              : 1 ;  /*!< [ 3: 3] : USB_A DMA Correctable Read Error Flag 0: No Error.
                                                                           1: Correctable error occurred during DMA read.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_1                     : 28;  /*!< [31: 4] : reserved. */
        } CERRFLGb;
    };

    union
    {
        __IOM uint32_t CERRSET                           ;  /*!< 0x00000044 : Correctable Error Flag Set Register */

        struct
        {
            __IOM uint32_t CPURDERR                  : 1 ;  /*!< [ 0: 0] : 0: No action.
                                                                           1: CPU Read Error Flag in CERRFLG register will be set and interrupt will be generated if enabled..
                                                                           Reset type: SYSRSn */
            __IOM uint32_t DMARDERR                  : 1 ;  /*!< [ 1: 1] : 0: No action.
                                                                           1: DMA Read Error Flag in CERRFLG register will be set and interrupt will be generated if enabled..
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 1 ;  /*!< [ 2: 2] : reserved. */
            __IOM uint32_t USBADMARDERR              : 1 ;  /*!< [ 3: 3] : 0: No action.
                                                                           1: USB_A DMA Read Error Flag in CERRFLG register will be set and interrupt will be generated if enabled..
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_1                     : 28;  /*!< [31: 4] : reserved. */
        } CERRSETb;
    };

    union
    {
        __IOM uint32_t CERRCLR                           ;  /*!< 0x00000048 : Correctable Error Flag Clear Register */

        struct
        {
            __IOM uint32_t CPURDERR                  : 1 ;  /*!< [ 0: 0] : 0: No action.
                                                                           1: CPU Read Error Flag in CERRFLG register will be cleared. Reset type: SYSRSn */
            __IOM uint32_t DMARDERR                  : 1 ;  /*!< [ 1: 1] : 0: No action.
                                                                           1: DMA Read Error Flag in CERRFLG register will be cleared . Reset type: SYSRSn */
                  uint32_t RSV_0                     : 1 ;  /*!< [ 2: 2] : reserved. */
            __IOM uint32_t USBADMARDERR              : 1 ;  /*!< [ 3: 3] : 0: No action.
                                                                           1: USB_A DMA Read Error Flag in CERRFLG register will be cleared . Reset type: SYSRSn */
                  uint32_t RSV_1                     : 28;  /*!< [31: 4] : reserved. */
        } CERRCLRb;
    };

    union
    {
        __IM  uint32_t CCPUREADDR                        ;  /*!< 0x0000004c : Correctable CPU Read Error Address */

        struct
        {
            __IM  uint32_t CCPUREADDR                : 32;  /*!< [31: 0] : This register captures the address location for which CPU read/fetch access resulted in correctable ECC error.
                                                                           Reset type: SYSRSn */
        } CCPUREADDRb;
    };

    union
    {
        __IM  uint32_t CDMAREADDR                        ;  /*!< 0x00000050 : Correctable DMA Read Error Address */

        struct
        {
            __IM  uint32_t CDMAREADDR                : 32;  /*!< [31: 0] : This register captures the address location for which DMA read/fetch access resulted in correctable ECC error.
                                                                           Reset type: SYSRSn */
        } CDMAREADDRb;
    };

    uint8_t    RSV_0X3054[4]                             ;
    union
    {
        __IM  uint32_t CUSBADMAREADDR                    ;  /*!< 0x00000058 : Correctable USB_A DMA Read Error Address */

        struct
        {
            __IM  uint32_t CUSBADMAREADDR            : 32;  /*!< [31: 0] : This register captures the address location for which USB_A DMA read/fetch access resulted in correctable ECC error.
                                                                           Reset type: SYSRSn */
        } CUSBADMAREADDRb;
    };

    union
    {
        __IM  uint32_t CERRCNT                           ;  /*!< 0x0000005c : Correctable Error Count Register */

        struct
        {
            __IM  uint32_t CERRCNT                   : 32;  /*!< [31: 0] : This register holds the count of how many times correctable error occurred.
                                                                           Reset type: SYSRSn */
        } CERRCNTb;
    };

    union
    {
        __IOM uint32_t CERRTHRES                         ;  /*!< 0x00000060 : Correctable Error Threshold Value Register */

        struct
        {
            __IOM uint32_t CERRTHRES                 : 32;  /*!< [31: 0] : When value in CERRCNT register is greater or equal to than value configured in this register, corretable interrupt gets generated, if enabled.
                                                                           Reset type: SYSRSn */
        } CERRTHRESb;
    };

    union
    {
        __IM  uint32_t CEINTFLG                          ;  /*!< 0x00000064 : Correctable Error Interrupt Flag Status Register */

        struct
        {
            __IM  uint32_t CEINTFLAG                 : 1 ;  /*!< [ 0: 0] : Total corrected error count exceeded threshold Flag
                                                                           0: Total correctable errors < Threshold value configured in CERRTHRES register.
                                                                           1: Total correctable errors >= Threshold value configured in CERRTHRES register.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 31;  /*!< [31: 1] : reserved. */
        } CEINTFLGb;
    };

    union
    {
        __IOM uint32_t CEINTCLR                          ;  /*!< 0x00000068 : Correctable Error Interrupt Flag Clear Register */

        struct
        {
            __IOM uint32_t CEINTCLR                  : 1 ;  /*!< [ 0: 0] : 0: No action.
                                                                           1: Total corrected error count exceeded flag in CEINTFLG register will be cleared.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 31;  /*!< [31: 1] : reserved. */
        } CEINTCLRb;
    };

    union
    {
        __IOM uint32_t CEINTSET                          ;  /*!< 0x0000006c : Correctable Error Interrupt Flag Set Register */

        struct
        {
            __IOM uint32_t CEINTSET                  : 1 ;  /*!< [ 0: 0] : 0: No action.
                                                                           1: Total corrected error count exceeded flag in CEINTFLG register will be set and interrupt will be generated if enabled.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 31;  /*!< [31: 1] : reserved. */
        } CEINTSETb;
    };

    union
    {
        __IOM uint32_t CEINTEN                           ;  /*!< 0x00000070 : Correctable Error Interrupt Enable Register */

        struct
        {
            __IOM uint32_t CEINTEN                   : 1 ;  /*!< [ 0: 0] : 0: Correctable Error Interrupt is disabled. 1: Correctable Error Interrupt is enabled.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 31;  /*!< [31: 1] : reserved. */
        } CEINTENb;
    };

    uint8_t    RSV_0X3074[12]                            ;
    union
    {
        __IOM uint32_t CERRINTEN                         ;  /*!< 0x00000080 : Correctable Error Interrupt Enable Register */

        struct
        {
            __IOM uint32_t CPURDERRINTEN             : 1 ;  /*!< [ 0: 0] : 0: CPU Read Correctable Error Interrupt is disabled.
                                                                           1: CPU Read Correctable Error Interrupt is enabled.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t DMARDERRINTEN             : 1 ;  /*!< [ 1: 1] : 0: DMA Read Correctable Error Interrupt is disabled.
                                                                           1: DMA Read Correctable Error Interrupt is enabled.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 1 ;  /*!< [ 2: 2] : reserved. */
            __IOM uint32_t USBADMARDERRINTEN         : 1 ;  /*!< [ 3: 3] : 0: USB_A DMA Read Correctable Error Interrupt is disabled.
                                                                           1: USB_A DMA Read Correctable Error Interrupt is enabled.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_1                     : 28;  /*!< [31: 4] : reserved. */
        } CERRINTENb;
    };

    union
    {
        __IOM uint32_t UCERRINTEN                        ;  /*!< 0x00000084 : Uncorrectable Error Interrupt Enable Register */

        struct
        {
            __IOM uint32_t CPURDERRINTEN             : 1 ;  /*!< [ 0: 0] : 0: CPU Read Uncorrectable Error Interrupt is disabled.
                                                                           1: CPU Read Uncorrectable Error Interrupt is enabled.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t DMARDERRINTEN             : 1 ;  /*!< [ 1: 1] : 0: DMA Read Uncorrectable Error Interrupt is disabled.
                                                                           1: DMA Read Uncorrectable Error Interrupt is enabled.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 1 ;  /*!< [ 2: 2] : reserved. */
            __IOM uint32_t USBADMARDERRINTEN         : 1 ;  /*!< [ 3: 3] : 0: USB_A DMA Read Uncorrectable Error Interrupt is disabled.
                                                                           1: USB_A DMA Read Uncorrectable Error Interrupt is enabled.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_1                     : 28;  /*!< [31: 4] : reserved. */
        } UCERRINTENb;
    };

    uint8_t    RSV_0X3088[888]                           ;
} MEMORY_ERROR_REGS_Type;

/*! \brief CPU_ID_REGS register */
typedef struct {
    union
    {
        __IM  uint32_t CPUID                             ;  /*!< 0x00000000 : Indicates CPU2 or CPU2 */

        struct
        {
            __IM  uint32_t CPUID                     : 8 ;  /*!< [ 7: 0] : CPUID = 1 for CPU1, 2 for CPU2
                                                                           Reset type: N/A */
                  uint32_t RSV_0                     : 24;  /*!< [31: 8] : reserved. */
        } CPUIDb;
    };

    uint8_t    RSV_0X3404[1020]                          ;
} CPU_ID_REGS_Type;

/*! \brief DUMMY_REGS register */
typedef struct {
    union
    {
        __IOM uint32_t DUMMY_REG0                        ;  /*!< 0x00000000 : dummy register 0 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG0b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG1                        ;  /*!< 0x00000004 : dummy register 1 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG1b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG2                        ;  /*!< 0x00000008 : dummy register 2 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG2b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG3                        ;  /*!< 0x0000000c : dummy register 3 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG3b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG4                        ;  /*!< 0x00000010 : dummy register 4 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG4b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG5                        ;  /*!< 0x00000014 : dummy register 5 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG5b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG6                        ;  /*!< 0x00000018 : dummy register 6 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG6b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG7                        ;  /*!< 0x0000001c : dummy register 7 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG7b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG8                        ;  /*!< 0x00000020 : dummy register 8 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG8b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG9                        ;  /*!< 0x00000024 : dummy register 9 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG9b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG10                       ;  /*!< 0x00000028 : dummy register 10 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG10b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG11                       ;  /*!< 0x0000002c : dummy register 11 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG11b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG12                       ;  /*!< 0x00000030 : dummy register 12 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG12b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG13                       ;  /*!< 0x00000034 : dummy register 13 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG13b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG14                       ;  /*!< 0x00000038 : dummy register 14 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG14b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG15                       ;  /*!< 0x0000003c : dummy register 15 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG15b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG16                       ;  /*!< 0x00000040 : dummy register 16 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG16b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG17                       ;  /*!< 0x00000044 : dummy register 17 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG17b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG18                       ;  /*!< 0x00000048 : dummy register 18 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG18b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG19                       ;  /*!< 0x0000004c : dummy register 19 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG19b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG20                       ;  /*!< 0x00000050 : dummy register 20 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG20b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG21                       ;  /*!< 0x00000054 : dummy register 21 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG21b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG22                       ;  /*!< 0x00000058 : dummy register 22 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG22b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG23                       ;  /*!< 0x0000005c : dummy register 23 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG23b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG24                       ;  /*!< 0x00000060 : dummy register 24 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG24b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG25                       ;  /*!< 0x00000064 : dummy register 25 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG25b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG26                       ;  /*!< 0x00000068 : dummy register 26 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG26b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG27                       ;  /*!< 0x0000006c : dummy register 27 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG27b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG28                       ;  /*!< 0x00000070 : dummy register 28 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG28b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG29                       ;  /*!< 0x00000074 : dummy register 29 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG29b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG30                       ;  /*!< 0x00000078 : dummy register 30 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG30b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG31                       ;  /*!< 0x0000007c : dummy register 31 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG31b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG32                       ;  /*!< 0x00000080 : dummy register 32 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG32b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG33                       ;  /*!< 0x00000084 : dummy register 33 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG33b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG34                       ;  /*!< 0x00000088 : dummy register 34 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG34b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG35                       ;  /*!< 0x0000008c : dummy register 35 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG35b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG36                       ;  /*!< 0x00000090 : dummy register 36 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG36b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG37                       ;  /*!< 0x00000094 : dummy register 37 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG37b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG38                       ;  /*!< 0x00000098 : dummy register 38 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG38b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG39                       ;  /*!< 0x0000009c : dummy register 39 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG39b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG40                       ;  /*!< 0x000000a0 : dummy register 40 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG40b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG41                       ;  /*!< 0x000000a4 : dummy register 41 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG41b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG42                       ;  /*!< 0x000000a8 : dummy register 42 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG42b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG43                       ;  /*!< 0x000000ac : dummy register 43 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG43b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG44                       ;  /*!< 0x000000b0 : dummy register 44 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG44b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG45                       ;  /*!< 0x000000b4 : dummy register 45 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG45b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG46                       ;  /*!< 0x000000b8 : dummy register 46 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG46b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG47                       ;  /*!< 0x000000bc : dummy register 47 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG47b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG48                       ;  /*!< 0x000000c0 : dummy register 48 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG48b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG49                       ;  /*!< 0x000000c4 : dummy register 49 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG49b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG50                       ;  /*!< 0x000000c8 : dummy register 50 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG50b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG51                       ;  /*!< 0x000000cc : dummy register 51 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG51b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG52                       ;  /*!< 0x000000d0 : dummy register 52 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG52b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG53                       ;  /*!< 0x000000d4 : dummy register 53 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG53b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG54                       ;  /*!< 0x000000d8 : dummy register 54 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG54b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG55                       ;  /*!< 0x000000dc : dummy register 55 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG55b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG56                       ;  /*!< 0x000000e0 : dummy register 56 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG56b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG57                       ;  /*!< 0x000000e4 : dummy register 57 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG57b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG58                       ;  /*!< 0x000000e8 : dummy register 58 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG58b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG59                       ;  /*!< 0x000000ec : dummy register 59 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG59b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG60                       ;  /*!< 0x000000f0 : dummy register 60 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG60b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG61                       ;  /*!< 0x000000f4 : dummy register 61 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG61b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG62                       ;  /*!< 0x000000f8 : dummy register 62 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG62b;
    };

    union
    {
        __IOM uint32_t DUMMY_REG63                       ;  /*!< 0x000000fc : dummy register 63 */

        struct
        {
            __IOM uint32_t DUMMY_REG                 : 32;  /*!< [31: 0] : dummy register. */
        } DUMMY_REG63b;
    };

    uint8_t    RSV_0X3D00[768]                           ;
} DUMMY_REGS_Type;


/*!
 * @}
 */

/*!
 * \name SYSCTRL_CPU2 Base Address Definitions
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

/*! \brief DUMMY_REGS base address */
#define DUMMY_REGS_BASE (0x41003c00UL)
/*! \brief DUMMY_REGS base pointer */
#define DUMMY_REGS ((DUMMY_REGS_Type *) DUMMY_REGS_BASE)


/*!
 * @}
 */


/*!
 * \name SYSCTRL_CPU2 Register Bitfield Definitions
 *
 * @{
 */

/* TIM bitfield */
#define CPUTIMER_REGS_TIM_MSW_Pos     (16U)                                                                         /*!< MSW Position 16 */
#define CPUTIMER_REGS_TIM_MSW_Msk     (0xffffU << CPUTIMER_REGS_TIM_MSW_Pos)                                        /*!< MSW Mask 0xFFFF0000 */
#define CPUTIMER_REGS_TIM_MSW_Set(x)  (((uint32_t) (x) << CPUTIMER_REGS_TIM_MSW_Pos) & CPUTIMER_REGS_TIM_MSW_Msk)   /*!< MSW Set Value */
#define CPUTIMER_REGS_TIM_MSW_Get(x)  (((uint32_t) (x) & CPUTIMER_REGS_TIM_MSW_Msk) >> CPUTIMER_REGS_TIM_MSW_Pos)   /*!< MSW Get Value */

#define CPUTIMER_REGS_TIM_LSW_Pos     (0U)                                                                          /*!< LSW Position 0 */
#define CPUTIMER_REGS_TIM_LSW_Msk     (0xffffU << CPUTIMER_REGS_TIM_LSW_Pos)                                        /*!< LSW Mask 0x0000FFFF */
#define CPUTIMER_REGS_TIM_LSW_Set(x)  (((uint32_t) (x) << CPUTIMER_REGS_TIM_LSW_Pos) & CPUTIMER_REGS_TIM_LSW_Msk)   /*!< LSW Set Value */
#define CPUTIMER_REGS_TIM_LSW_Get(x)  (((uint32_t) (x) & CPUTIMER_REGS_TIM_LSW_Msk) >> CPUTIMER_REGS_TIM_LSW_Pos)   /*!< LSW Get Value */

/* PRD bitfield */
#define CPUTIMER_REGS_PRD_MSW_Pos     (16U)                                                                         /*!< MSW Position 16 */
#define CPUTIMER_REGS_PRD_MSW_Msk     (0xffffU << CPUTIMER_REGS_PRD_MSW_Pos)                                        /*!< MSW Mask 0xFFFF0000 */
#define CPUTIMER_REGS_PRD_MSW_Set(x)  (((uint32_t) (x) << CPUTIMER_REGS_PRD_MSW_Pos) & CPUTIMER_REGS_PRD_MSW_Msk)   /*!< MSW Set Value */
#define CPUTIMER_REGS_PRD_MSW_Get(x)  (((uint32_t) (x) & CPUTIMER_REGS_PRD_MSW_Msk) >> CPUTIMER_REGS_PRD_MSW_Pos)   /*!< MSW Get Value */

#define CPUTIMER_REGS_PRD_LSW_Pos     (0U)                                                                          /*!< LSW Position 0 */
#define CPUTIMER_REGS_PRD_LSW_Msk     (0xffffU << CPUTIMER_REGS_PRD_LSW_Pos)                                        /*!< LSW Mask 0x0000FFFF */
#define CPUTIMER_REGS_PRD_LSW_Set(x)  (((uint32_t) (x) << CPUTIMER_REGS_PRD_LSW_Pos) & CPUTIMER_REGS_PRD_LSW_Msk)   /*!< LSW Set Value */
#define CPUTIMER_REGS_PRD_LSW_Get(x)  (((uint32_t) (x) & CPUTIMER_REGS_PRD_LSW_Msk) >> CPUTIMER_REGS_PRD_LSW_Pos)   /*!< LSW Get Value */

/* TCR bitfield */
#define CPUTIMER_REGS_TCR_TIF_Pos     (15U)                                                                         /*!< TIF Position 15 */
#define CPUTIMER_REGS_TCR_TIF_Msk     (0x1U << CPUTIMER_REGS_TCR_TIF_Pos)                                           /*!< TIF Mask 0x00008000 */
#define CPUTIMER_REGS_TCR_TIF_Set(x)  (((uint32_t) (x) << CPUTIMER_REGS_TCR_TIF_Pos) & CPUTIMER_REGS_TCR_TIF_Msk)   /*!< TIF Set Value */
#define CPUTIMER_REGS_TCR_TIF_Get(x)  (((uint32_t) (x) & CPUTIMER_REGS_TCR_TIF_Msk) >> CPUTIMER_REGS_TCR_TIF_Pos)   /*!< TIF Get Value */

#define CPUTIMER_REGS_TCR_TIE_Pos     (14U)                                                                         /*!< TIE Position 14 */
#define CPUTIMER_REGS_TCR_TIE_Msk     (0x1U << CPUTIMER_REGS_TCR_TIE_Pos)                                           /*!< TIE Mask 0x00004000 */
#define CPUTIMER_REGS_TCR_TIE_Set(x)  (((uint32_t) (x) << CPUTIMER_REGS_TCR_TIE_Pos) & CPUTIMER_REGS_TCR_TIE_Msk)   /*!< TIE Set Value */
#define CPUTIMER_REGS_TCR_TIE_Get(x)  (((uint32_t) (x) & CPUTIMER_REGS_TCR_TIE_Msk) >> CPUTIMER_REGS_TCR_TIE_Pos)   /*!< TIE Get Value */

#define CPUTIMER_REGS_TCR_FREE_Pos     (11U)                                                                           /*!< FREE Position 11 */
#define CPUTIMER_REGS_TCR_FREE_Msk     (0x1U << CPUTIMER_REGS_TCR_FREE_Pos)                                            /*!< FREE Mask 0x00000800 */
#define CPUTIMER_REGS_TCR_FREE_Set(x)  (((uint32_t) (x) << CPUTIMER_REGS_TCR_FREE_Pos) & CPUTIMER_REGS_TCR_FREE_Msk)   /*!< FREE Set Value */
#define CPUTIMER_REGS_TCR_FREE_Get(x)  (((uint32_t) (x) & CPUTIMER_REGS_TCR_FREE_Msk) >> CPUTIMER_REGS_TCR_FREE_Pos)   /*!< FREE Get Value */

#define CPUTIMER_REGS_TCR_TIM_SOFT_Pos     (10U)                                                                                   /*!< TIM_SOFT Position 10 */
#define CPUTIMER_REGS_TCR_TIM_SOFT_Msk     (0x1U << CPUTIMER_REGS_TCR_TIM_SOFT_Pos)                                                /*!< TIM_SOFT Mask 0x00000400 */
#define CPUTIMER_REGS_TCR_TIM_SOFT_Set(x)  (((uint32_t) (x) << CPUTIMER_REGS_TCR_TIM_SOFT_Pos) & CPUTIMER_REGS_TCR_TIM_SOFT_Msk)   /*!< TIM_SOFT Set Value */
#define CPUTIMER_REGS_TCR_TIM_SOFT_Get(x)  (((uint32_t) (x) & CPUTIMER_REGS_TCR_TIM_SOFT_Msk) >> CPUTIMER_REGS_TCR_TIM_SOFT_Pos)   /*!< TIM_SOFT Get Value */

#define CPUTIMER_REGS_TCR_TRB_Pos     (5U)                                                                          /*!< TRB Position 5 */
#define CPUTIMER_REGS_TCR_TRB_Msk     (0x1U << CPUTIMER_REGS_TCR_TRB_Pos)                                           /*!< TRB Mask 0x00000020 */
#define CPUTIMER_REGS_TCR_TRB_Set(x)  (((uint32_t) (x) << CPUTIMER_REGS_TCR_TRB_Pos) & CPUTIMER_REGS_TCR_TRB_Msk)   /*!< TRB Set Value */
#define CPUTIMER_REGS_TCR_TRB_Get(x)  (((uint32_t) (x) & CPUTIMER_REGS_TCR_TRB_Msk) >> CPUTIMER_REGS_TCR_TRB_Pos)   /*!< TRB Get Value */

#define CPUTIMER_REGS_TCR_TSS_Pos     (4U)                                                                          /*!< TSS Position 4 */
#define CPUTIMER_REGS_TCR_TSS_Msk     (0x1U << CPUTIMER_REGS_TCR_TSS_Pos)                                           /*!< TSS Mask 0x00000010 */
#define CPUTIMER_REGS_TCR_TSS_Set(x)  (((uint32_t) (x) << CPUTIMER_REGS_TCR_TSS_Pos) & CPUTIMER_REGS_TCR_TSS_Msk)   /*!< TSS Set Value */
#define CPUTIMER_REGS_TCR_TSS_Get(x)  (((uint32_t) (x) & CPUTIMER_REGS_TCR_TSS_Msk) >> CPUTIMER_REGS_TCR_TSS_Pos)   /*!< TSS Get Value */

#define CPUTIMER_REGS_TCR_INTR_OP_Pos     (3U)                                                                                  /*!< INTR_OP Position 3 */
#define CPUTIMER_REGS_TCR_INTR_OP_Msk     (0x1U << CPUTIMER_REGS_TCR_INTR_OP_Pos)                                               /*!< INTR_OP Mask 0x00000008 */
#define CPUTIMER_REGS_TCR_INTR_OP_Set(x)  (((uint32_t) (x) << CPUTIMER_REGS_TCR_INTR_OP_Pos) & CPUTIMER_REGS_TCR_INTR_OP_Msk)   /*!< INTR_OP Set Value */
#define CPUTIMER_REGS_TCR_INTR_OP_Get(x)  (((uint32_t) (x) & CPUTIMER_REGS_TCR_INTR_OP_Msk) >> CPUTIMER_REGS_TCR_INTR_OP_Pos)   /*!< INTR_OP Get Value */

/* TPR bitfield */
#define CPUTIMER_REGS_TPR_PSC_Pos     (8U)                                                                          /*!< PSC Position 8 */
#define CPUTIMER_REGS_TPR_PSC_Msk     (0xffU << CPUTIMER_REGS_TPR_PSC_Pos)                                          /*!< PSC Mask 0x0000FF00 */
#define CPUTIMER_REGS_TPR_PSC_Set(x)  (((uint16_t) (x) << CPUTIMER_REGS_TPR_PSC_Pos) & CPUTIMER_REGS_TPR_PSC_Msk)   /*!< PSC Set Value */
#define CPUTIMER_REGS_TPR_PSC_Get(x)  (((uint16_t) (x) & CPUTIMER_REGS_TPR_PSC_Msk) >> CPUTIMER_REGS_TPR_PSC_Pos)   /*!< PSC Get Value */

#define CPUTIMER_REGS_TPR_TDDR_Pos     (0U)                                                                            /*!< TDDR Position 0 */
#define CPUTIMER_REGS_TPR_TDDR_Msk     (0xffU << CPUTIMER_REGS_TPR_TDDR_Pos)                                           /*!< TDDR Mask 0x000000FF */
#define CPUTIMER_REGS_TPR_TDDR_Set(x)  (((uint16_t) (x) << CPUTIMER_REGS_TPR_TDDR_Pos) & CPUTIMER_REGS_TPR_TDDR_Msk)   /*!< TDDR Set Value */
#define CPUTIMER_REGS_TPR_TDDR_Get(x)  (((uint16_t) (x) & CPUTIMER_REGS_TPR_TDDR_Msk) >> CPUTIMER_REGS_TPR_TDDR_Pos)   /*!< TDDR Get Value */

/* TPRH bitfield */
#define CPUTIMER_REGS_TPRH_PSCH_Pos     (8U)                                                                              /*!< PSCH Position 8 */
#define CPUTIMER_REGS_TPRH_PSCH_Msk     (0xffU << CPUTIMER_REGS_TPRH_PSCH_Pos)                                            /*!< PSCH Mask 0x0000FF00 */
#define CPUTIMER_REGS_TPRH_PSCH_Set(x)  (((uint16_t) (x) << CPUTIMER_REGS_TPRH_PSCH_Pos) & CPUTIMER_REGS_TPRH_PSCH_Msk)   /*!< PSCH Set Value */
#define CPUTIMER_REGS_TPRH_PSCH_Get(x)  (((uint16_t) (x) & CPUTIMER_REGS_TPRH_PSCH_Msk) >> CPUTIMER_REGS_TPRH_PSCH_Pos)   /*!< PSCH Get Value */

#define CPUTIMER_REGS_TPRH_TDDRH_Pos     (0U)                                                                                /*!< TDDRH Position 0 */
#define CPUTIMER_REGS_TPRH_TDDRH_Msk     (0xffU << CPUTIMER_REGS_TPRH_TDDRH_Pos)                                             /*!< TDDRH Mask 0x000000FF */
#define CPUTIMER_REGS_TPRH_TDDRH_Set(x)  (((uint16_t) (x) << CPUTIMER_REGS_TPRH_TDDRH_Pos) & CPUTIMER_REGS_TPRH_TDDRH_Msk)   /*!< TDDRH Set Value */
#define CPUTIMER_REGS_TPRH_TDDRH_Get(x)  (((uint16_t) (x) & CPUTIMER_REGS_TPRH_TDDRH_Msk) >> CPUTIMER_REGS_TPRH_TDDRH_Pos)   /*!< TDDRH Get Value */

/* TIMEX bitfield */
#define CPUTIMER_REGS_TIMEX_TIMEX_Pos     (0U)                                                                                  /*!< TIMEX Position 0 */
#define CPUTIMER_REGS_TIMEX_TIMEX_Msk     (0xffffffffU << CPUTIMER_REGS_TIMEX_TIMEX_Pos)                                        /*!< TIMEX Mask 0xFFFFFFFF */
#define CPUTIMER_REGS_TIMEX_TIMEX_Set(x)  (((uint32_t) (x) << CPUTIMER_REGS_TIMEX_TIMEX_Pos) & CPUTIMER_REGS_TIMEX_TIMEX_Msk)   /*!< TIMEX Set Value */
#define CPUTIMER_REGS_TIMEX_TIMEX_Get(x)  (((uint32_t) (x) & CPUTIMER_REGS_TIMEX_TIMEX_Msk) >> CPUTIMER_REGS_TIMEX_TIMEX_Pos)   /*!< TIMEX Get Value */

/* PRDEX bitfield */
#define CPUTIMER_REGS_PRDEX_PRDEX_Pos     (0U)                                                                                  /*!< PRDEX Position 0 */
#define CPUTIMER_REGS_PRDEX_PRDEX_Msk     (0xffffffffU << CPUTIMER_REGS_PRDEX_PRDEX_Pos)                                        /*!< PRDEX Mask 0xFFFFFFFF */
#define CPUTIMER_REGS_PRDEX_PRDEX_Set(x)  (((uint32_t) (x) << CPUTIMER_REGS_PRDEX_PRDEX_Pos) & CPUTIMER_REGS_PRDEX_PRDEX_Msk)   /*!< PRDEX Set Value */
#define CPUTIMER_REGS_PRDEX_PRDEX_Get(x)  (((uint32_t) (x) & CPUTIMER_REGS_PRDEX_PRDEX_Msk) >> CPUTIMER_REGS_PRDEX_PRDEX_Pos)   /*!< PRDEX Get Value */

/* WDCR bitfield */
#define WD_REGS_WDCR_WDPS_Pos     (0U)                                                                  /*!< WDPS Position 0 */
#define WD_REGS_WDCR_WDPS_Msk     (0x7U << WD_REGS_WDCR_WDPS_Pos)                                       /*!< WDPS Mask 0x00000007 */
#define WD_REGS_WDCR_WDPS_Set(x)  (((uint16_t) (x) << WD_REGS_WDCR_WDPS_Pos) & WD_REGS_WDCR_WDPS_Msk)   /*!< WDPS Set Value */
#define WD_REGS_WDCR_WDPS_Get(x)  (((uint16_t) (x) & WD_REGS_WDCR_WDPS_Msk) >> WD_REGS_WDCR_WDPS_Pos)   /*!< WDPS Get Value */

/* NMICFG bitfield */
#define NMI_INTRUPT_REGS_NMICFG_NMIE_Pos     (0U)                                                                                        /*!< NMIE Position 0 */
#define NMI_INTRUPT_REGS_NMICFG_NMIE_Msk     (0x1U << NMI_INTRUPT_REGS_NMICFG_NMIE_Pos)                                                  /*!< NMIE Mask 0x00000001 */
#define NMI_INTRUPT_REGS_NMICFG_NMIE_Set(x)  (((uint16_t) (x) << NMI_INTRUPT_REGS_NMICFG_NMIE_Pos) & NMI_INTRUPT_REGS_NMICFG_NMIE_Msk)   /*!< NMIE Set Value */
#define NMI_INTRUPT_REGS_NMICFG_NMIE_Get(x)  (((uint16_t) (x) & NMI_INTRUPT_REGS_NMICFG_NMIE_Msk) >> NMI_INTRUPT_REGS_NMICFG_NMIE_Pos)   /*!< NMIE Get Value */

/* NMIFLG bitfield */
#define NMI_INTRUPT_REGS_NMIFLG_CLBNMI_Pos     (8U)                                                                                            /*!< CLBNMI Position 8 */
#define NMI_INTRUPT_REGS_NMIFLG_CLBNMI_Msk     (0x1U << NMI_INTRUPT_REGS_NMIFLG_CLBNMI_Pos)                                                    /*!< CLBNMI Mask 0x00000100 */
#define NMI_INTRUPT_REGS_NMIFLG_CLBNMI_Set(x)  (((uint16_t) (x) << NMI_INTRUPT_REGS_NMIFLG_CLBNMI_Pos) & NMI_INTRUPT_REGS_NMIFLG_CLBNMI_Msk)   /*!< CLBNMI Set Value */
#define NMI_INTRUPT_REGS_NMIFLG_CLBNMI_Get(x)  (((uint16_t) (x) & NMI_INTRUPT_REGS_NMIFLG_CLBNMI_Msk) >> NMI_INTRUPT_REGS_NMIFLG_CLBNMI_Pos)   /*!< CLBNMI Get Value */

#define NMI_INTRUPT_REGS_NMIFLG_FLUNCERR_Pos     (3U)                                                                                                /*!< FLUNCERR Position 3 */
#define NMI_INTRUPT_REGS_NMIFLG_FLUNCERR_Msk     (0x1U << NMI_INTRUPT_REGS_NMIFLG_FLUNCERR_Pos)                                                      /*!< FLUNCERR Mask 0x00000008 */
#define NMI_INTRUPT_REGS_NMIFLG_FLUNCERR_Set(x)  (((uint16_t) (x) << NMI_INTRUPT_REGS_NMIFLG_FLUNCERR_Pos) & NMI_INTRUPT_REGS_NMIFLG_FLUNCERR_Msk)   /*!< FLUNCERR Set Value */
#define NMI_INTRUPT_REGS_NMIFLG_FLUNCERR_Get(x)  (((uint16_t) (x) & NMI_INTRUPT_REGS_NMIFLG_FLUNCERR_Msk) >> NMI_INTRUPT_REGS_NMIFLG_FLUNCERR_Pos)   /*!< FLUNCERR Get Value */

#define NMI_INTRUPT_REGS_NMIFLG_RAMUNCERR_Pos     (2U)                                                                                                  /*!< RAMUNCERR Position 2 */
#define NMI_INTRUPT_REGS_NMIFLG_RAMUNCERR_Msk     (0x1U << NMI_INTRUPT_REGS_NMIFLG_RAMUNCERR_Pos)                                                       /*!< RAMUNCERR Mask 0x00000004 */
#define NMI_INTRUPT_REGS_NMIFLG_RAMUNCERR_Set(x)  (((uint16_t) (x) << NMI_INTRUPT_REGS_NMIFLG_RAMUNCERR_Pos) & NMI_INTRUPT_REGS_NMIFLG_RAMUNCERR_Msk)   /*!< RAMUNCERR Set Value */
#define NMI_INTRUPT_REGS_NMIFLG_RAMUNCERR_Get(x)  (((uint16_t) (x) & NMI_INTRUPT_REGS_NMIFLG_RAMUNCERR_Msk) >> NMI_INTRUPT_REGS_NMIFLG_RAMUNCERR_Pos)   /*!< RAMUNCERR Get Value */

#define NMI_INTRUPT_REGS_NMIFLG_CLOCKFAIL_Pos     (1U)                                                                                                  /*!< CLOCKFAIL Position 1 */
#define NMI_INTRUPT_REGS_NMIFLG_CLOCKFAIL_Msk     (0x1U << NMI_INTRUPT_REGS_NMIFLG_CLOCKFAIL_Pos)                                                       /*!< CLOCKFAIL Mask 0x00000002 */
#define NMI_INTRUPT_REGS_NMIFLG_CLOCKFAIL_Set(x)  (((uint16_t) (x) << NMI_INTRUPT_REGS_NMIFLG_CLOCKFAIL_Pos) & NMI_INTRUPT_REGS_NMIFLG_CLOCKFAIL_Msk)   /*!< CLOCKFAIL Set Value */
#define NMI_INTRUPT_REGS_NMIFLG_CLOCKFAIL_Get(x)  (((uint16_t) (x) & NMI_INTRUPT_REGS_NMIFLG_CLOCKFAIL_Msk) >> NMI_INTRUPT_REGS_NMIFLG_CLOCKFAIL_Pos)   /*!< CLOCKFAIL Get Value */

#define NMI_INTRUPT_REGS_NMIFLG_NMIINT_Pos     (0U)                                                                                            /*!< NMIINT Position 0 */
#define NMI_INTRUPT_REGS_NMIFLG_NMIINT_Msk     (0x1U << NMI_INTRUPT_REGS_NMIFLG_NMIINT_Pos)                                                    /*!< NMIINT Mask 0x00000001 */
#define NMI_INTRUPT_REGS_NMIFLG_NMIINT_Set(x)  (((uint16_t) (x) << NMI_INTRUPT_REGS_NMIFLG_NMIINT_Pos) & NMI_INTRUPT_REGS_NMIFLG_NMIINT_Msk)   /*!< NMIINT Set Value */
#define NMI_INTRUPT_REGS_NMIFLG_NMIINT_Get(x)  (((uint16_t) (x) & NMI_INTRUPT_REGS_NMIFLG_NMIINT_Msk) >> NMI_INTRUPT_REGS_NMIFLG_NMIINT_Pos)   /*!< NMIINT Get Value */

/* NMIFLGCLR bitfield */
#define NMI_INTRUPT_REGS_NMIFLGCLR_CLBNMI_Pos     (8U)                                                                                                  /*!< CLBNMI Position 8 */
#define NMI_INTRUPT_REGS_NMIFLGCLR_CLBNMI_Msk     (0x1U << NMI_INTRUPT_REGS_NMIFLGCLR_CLBNMI_Pos)                                                       /*!< CLBNMI Mask 0x00000100 */
#define NMI_INTRUPT_REGS_NMIFLGCLR_CLBNMI_Set(x)  (((uint16_t) (x) << NMI_INTRUPT_REGS_NMIFLGCLR_CLBNMI_Pos) & NMI_INTRUPT_REGS_NMIFLGCLR_CLBNMI_Msk)   /*!< CLBNMI Set Value */
#define NMI_INTRUPT_REGS_NMIFLGCLR_CLBNMI_Get(x)  (((uint16_t) (x) & NMI_INTRUPT_REGS_NMIFLGCLR_CLBNMI_Msk) >> NMI_INTRUPT_REGS_NMIFLGCLR_CLBNMI_Pos)   /*!< CLBNMI Get Value */

#define NMI_INTRUPT_REGS_NMIFLGCLR_FLUNCERR_Pos     (3U)                                                                                                      /*!< FLUNCERR Position 3 */
#define NMI_INTRUPT_REGS_NMIFLGCLR_FLUNCERR_Msk     (0x1U << NMI_INTRUPT_REGS_NMIFLGCLR_FLUNCERR_Pos)                                                         /*!< FLUNCERR Mask 0x00000008 */
#define NMI_INTRUPT_REGS_NMIFLGCLR_FLUNCERR_Set(x)  (((uint16_t) (x) << NMI_INTRUPT_REGS_NMIFLGCLR_FLUNCERR_Pos) & NMI_INTRUPT_REGS_NMIFLGCLR_FLUNCERR_Msk)   /*!< FLUNCERR Set Value */
#define NMI_INTRUPT_REGS_NMIFLGCLR_FLUNCERR_Get(x)  (((uint16_t) (x) & NMI_INTRUPT_REGS_NMIFLGCLR_FLUNCERR_Msk) >> NMI_INTRUPT_REGS_NMIFLGCLR_FLUNCERR_Pos)   /*!< FLUNCERR Get Value */

#define NMI_INTRUPT_REGS_NMIFLGCLR_RAMUNCERR_Pos     (2U)                                                                                                        /*!< RAMUNCERR Position 2 */
#define NMI_INTRUPT_REGS_NMIFLGCLR_RAMUNCERR_Msk     (0x1U << NMI_INTRUPT_REGS_NMIFLGCLR_RAMUNCERR_Pos)                                                          /*!< RAMUNCERR Mask 0x00000004 */
#define NMI_INTRUPT_REGS_NMIFLGCLR_RAMUNCERR_Set(x)  (((uint16_t) (x) << NMI_INTRUPT_REGS_NMIFLGCLR_RAMUNCERR_Pos) & NMI_INTRUPT_REGS_NMIFLGCLR_RAMUNCERR_Msk)   /*!< RAMUNCERR Set Value */
#define NMI_INTRUPT_REGS_NMIFLGCLR_RAMUNCERR_Get(x)  (((uint16_t) (x) & NMI_INTRUPT_REGS_NMIFLGCLR_RAMUNCERR_Msk) >> NMI_INTRUPT_REGS_NMIFLGCLR_RAMUNCERR_Pos)   /*!< RAMUNCERR Get Value */

#define NMI_INTRUPT_REGS_NMIFLGCLR_CLOCKFAIL_Pos     (1U)                                                                                                        /*!< CLOCKFAIL Position 1 */
#define NMI_INTRUPT_REGS_NMIFLGCLR_CLOCKFAIL_Msk     (0x1U << NMI_INTRUPT_REGS_NMIFLGCLR_CLOCKFAIL_Pos)                                                          /*!< CLOCKFAIL Mask 0x00000002 */
#define NMI_INTRUPT_REGS_NMIFLGCLR_CLOCKFAIL_Set(x)  (((uint16_t) (x) << NMI_INTRUPT_REGS_NMIFLGCLR_CLOCKFAIL_Pos) & NMI_INTRUPT_REGS_NMIFLGCLR_CLOCKFAIL_Msk)   /*!< CLOCKFAIL Set Value */
#define NMI_INTRUPT_REGS_NMIFLGCLR_CLOCKFAIL_Get(x)  (((uint16_t) (x) & NMI_INTRUPT_REGS_NMIFLGCLR_CLOCKFAIL_Msk) >> NMI_INTRUPT_REGS_NMIFLGCLR_CLOCKFAIL_Pos)   /*!< CLOCKFAIL Get Value */

#define NMI_INTRUPT_REGS_NMIFLGCLR_NMIINT_Pos     (0U)                                                                                                  /*!< NMIINT Position 0 */
#define NMI_INTRUPT_REGS_NMIFLGCLR_NMIINT_Msk     (0x1U << NMI_INTRUPT_REGS_NMIFLGCLR_NMIINT_Pos)                                                       /*!< NMIINT Mask 0x00000001 */
#define NMI_INTRUPT_REGS_NMIFLGCLR_NMIINT_Set(x)  (((uint16_t) (x) << NMI_INTRUPT_REGS_NMIFLGCLR_NMIINT_Pos) & NMI_INTRUPT_REGS_NMIFLGCLR_NMIINT_Msk)   /*!< NMIINT Set Value */
#define NMI_INTRUPT_REGS_NMIFLGCLR_NMIINT_Get(x)  (((uint16_t) (x) & NMI_INTRUPT_REGS_NMIFLGCLR_NMIINT_Msk) >> NMI_INTRUPT_REGS_NMIFLGCLR_NMIINT_Pos)   /*!< NMIINT Get Value */

/* NMIFLGFRC bitfield */
#define NMI_INTRUPT_REGS_NMIFLGFRC_CLBNMI_Pos     (8U)                                                                                                  /*!< CLBNMI Position 8 */
#define NMI_INTRUPT_REGS_NMIFLGFRC_CLBNMI_Msk     (0x1U << NMI_INTRUPT_REGS_NMIFLGFRC_CLBNMI_Pos)                                                       /*!< CLBNMI Mask 0x00000100 */
#define NMI_INTRUPT_REGS_NMIFLGFRC_CLBNMI_Set(x)  (((uint16_t) (x) << NMI_INTRUPT_REGS_NMIFLGFRC_CLBNMI_Pos) & NMI_INTRUPT_REGS_NMIFLGFRC_CLBNMI_Msk)   /*!< CLBNMI Set Value */
#define NMI_INTRUPT_REGS_NMIFLGFRC_CLBNMI_Get(x)  (((uint16_t) (x) & NMI_INTRUPT_REGS_NMIFLGFRC_CLBNMI_Msk) >> NMI_INTRUPT_REGS_NMIFLGFRC_CLBNMI_Pos)   /*!< CLBNMI Get Value */

#define NMI_INTRUPT_REGS_NMIFLGFRC_FLUNCERR_Pos     (3U)                                                                                                      /*!< FLUNCERR Position 3 */
#define NMI_INTRUPT_REGS_NMIFLGFRC_FLUNCERR_Msk     (0x1U << NMI_INTRUPT_REGS_NMIFLGFRC_FLUNCERR_Pos)                                                         /*!< FLUNCERR Mask 0x00000008 */
#define NMI_INTRUPT_REGS_NMIFLGFRC_FLUNCERR_Set(x)  (((uint16_t) (x) << NMI_INTRUPT_REGS_NMIFLGFRC_FLUNCERR_Pos) & NMI_INTRUPT_REGS_NMIFLGFRC_FLUNCERR_Msk)   /*!< FLUNCERR Set Value */
#define NMI_INTRUPT_REGS_NMIFLGFRC_FLUNCERR_Get(x)  (((uint16_t) (x) & NMI_INTRUPT_REGS_NMIFLGFRC_FLUNCERR_Msk) >> NMI_INTRUPT_REGS_NMIFLGFRC_FLUNCERR_Pos)   /*!< FLUNCERR Get Value */

#define NMI_INTRUPT_REGS_NMIFLGFRC_RAMUNCERR_Pos     (2U)                                                                                                        /*!< RAMUNCERR Position 2 */
#define NMI_INTRUPT_REGS_NMIFLGFRC_RAMUNCERR_Msk     (0x1U << NMI_INTRUPT_REGS_NMIFLGFRC_RAMUNCERR_Pos)                                                          /*!< RAMUNCERR Mask 0x00000004 */
#define NMI_INTRUPT_REGS_NMIFLGFRC_RAMUNCERR_Set(x)  (((uint16_t) (x) << NMI_INTRUPT_REGS_NMIFLGFRC_RAMUNCERR_Pos) & NMI_INTRUPT_REGS_NMIFLGFRC_RAMUNCERR_Msk)   /*!< RAMUNCERR Set Value */
#define NMI_INTRUPT_REGS_NMIFLGFRC_RAMUNCERR_Get(x)  (((uint16_t) (x) & NMI_INTRUPT_REGS_NMIFLGFRC_RAMUNCERR_Msk) >> NMI_INTRUPT_REGS_NMIFLGFRC_RAMUNCERR_Pos)   /*!< RAMUNCERR Get Value */

#define NMI_INTRUPT_REGS_NMIFLGFRC_CLOCKFAIL_Pos     (1U)                                                                                                        /*!< CLOCKFAIL Position 1 */
#define NMI_INTRUPT_REGS_NMIFLGFRC_CLOCKFAIL_Msk     (0x1U << NMI_INTRUPT_REGS_NMIFLGFRC_CLOCKFAIL_Pos)                                                          /*!< CLOCKFAIL Mask 0x00000002 */
#define NMI_INTRUPT_REGS_NMIFLGFRC_CLOCKFAIL_Set(x)  (((uint16_t) (x) << NMI_INTRUPT_REGS_NMIFLGFRC_CLOCKFAIL_Pos) & NMI_INTRUPT_REGS_NMIFLGFRC_CLOCKFAIL_Msk)   /*!< CLOCKFAIL Set Value */
#define NMI_INTRUPT_REGS_NMIFLGFRC_CLOCKFAIL_Get(x)  (((uint16_t) (x) & NMI_INTRUPT_REGS_NMIFLGFRC_CLOCKFAIL_Msk) >> NMI_INTRUPT_REGS_NMIFLGFRC_CLOCKFAIL_Pos)   /*!< CLOCKFAIL Get Value */

/* NMIWDCNT bitfield */
#define NMI_INTRUPT_REGS_NMIWDCNT_NMIWDCNT_Pos     (0U)                                                                                                    /*!< NMIWDCNT Position 0 */
#define NMI_INTRUPT_REGS_NMIWDCNT_NMIWDCNT_Msk     (0xffffU << NMI_INTRUPT_REGS_NMIWDCNT_NMIWDCNT_Pos)                                                     /*!< NMIWDCNT Mask 0x0000FFFF */
#define NMI_INTRUPT_REGS_NMIWDCNT_NMIWDCNT_Set(x)  (((uint16_t) (x) << NMI_INTRUPT_REGS_NMIWDCNT_NMIWDCNT_Pos) & NMI_INTRUPT_REGS_NMIWDCNT_NMIWDCNT_Msk)   /*!< NMIWDCNT Set Value */
#define NMI_INTRUPT_REGS_NMIWDCNT_NMIWDCNT_Get(x)  (((uint16_t) (x) & NMI_INTRUPT_REGS_NMIWDCNT_NMIWDCNT_Msk) >> NMI_INTRUPT_REGS_NMIWDCNT_NMIWDCNT_Pos)   /*!< NMIWDCNT Get Value */

/* NMIWDPRD bitfield */
#define NMI_INTRUPT_REGS_NMIWDPRD_NMIWDPRD_Pos     (0U)                                                                                                    /*!< NMIWDPRD Position 0 */
#define NMI_INTRUPT_REGS_NMIWDPRD_NMIWDPRD_Msk     (0xffffU << NMI_INTRUPT_REGS_NMIWDPRD_NMIWDPRD_Pos)                                                     /*!< NMIWDPRD Mask 0x0000FFFF */
#define NMI_INTRUPT_REGS_NMIWDPRD_NMIWDPRD_Set(x)  (((uint16_t) (x) << NMI_INTRUPT_REGS_NMIWDPRD_NMIWDPRD_Pos) & NMI_INTRUPT_REGS_NMIWDPRD_NMIWDPRD_Msk)   /*!< NMIWDPRD Set Value */
#define NMI_INTRUPT_REGS_NMIWDPRD_NMIWDPRD_Get(x)  (((uint16_t) (x) & NMI_INTRUPT_REGS_NMIWDPRD_NMIWDPRD_Msk) >> NMI_INTRUPT_REGS_NMIWDPRD_NMIWDPRD_Pos)   /*!< NMIWDPRD Get Value */

/* NMISHDFLG bitfield */
#define NMI_INTRUPT_REGS_NMISHDFLG_CLBNMI_Pos     (8U)                                                                                                  /*!< CLBNMI Position 8 */
#define NMI_INTRUPT_REGS_NMISHDFLG_CLBNMI_Msk     (0x1U << NMI_INTRUPT_REGS_NMISHDFLG_CLBNMI_Pos)                                                       /*!< CLBNMI Mask 0x00000100 */
#define NMI_INTRUPT_REGS_NMISHDFLG_CLBNMI_Set(x)  (((uint32_t) (x) << NMI_INTRUPT_REGS_NMISHDFLG_CLBNMI_Pos) & NMI_INTRUPT_REGS_NMISHDFLG_CLBNMI_Msk)   /*!< CLBNMI Set Value */
#define NMI_INTRUPT_REGS_NMISHDFLG_CLBNMI_Get(x)  (((uint32_t) (x) & NMI_INTRUPT_REGS_NMISHDFLG_CLBNMI_Msk) >> NMI_INTRUPT_REGS_NMISHDFLG_CLBNMI_Pos)   /*!< CLBNMI Get Value */

#define NMI_INTRUPT_REGS_NMISHDFLG_FLUNCERR_Pos     (3U)                                                                                                      /*!< FLUNCERR Position 3 */
#define NMI_INTRUPT_REGS_NMISHDFLG_FLUNCERR_Msk     (0x1U << NMI_INTRUPT_REGS_NMISHDFLG_FLUNCERR_Pos)                                                         /*!< FLUNCERR Mask 0x00000008 */
#define NMI_INTRUPT_REGS_NMISHDFLG_FLUNCERR_Set(x)  (((uint32_t) (x) << NMI_INTRUPT_REGS_NMISHDFLG_FLUNCERR_Pos) & NMI_INTRUPT_REGS_NMISHDFLG_FLUNCERR_Msk)   /*!< FLUNCERR Set Value */
#define NMI_INTRUPT_REGS_NMISHDFLG_FLUNCERR_Get(x)  (((uint32_t) (x) & NMI_INTRUPT_REGS_NMISHDFLG_FLUNCERR_Msk) >> NMI_INTRUPT_REGS_NMISHDFLG_FLUNCERR_Pos)   /*!< FLUNCERR Get Value */

#define NMI_INTRUPT_REGS_NMISHDFLG_RAMUNCERR_Pos     (2U)                                                                                                        /*!< RAMUNCERR Position 2 */
#define NMI_INTRUPT_REGS_NMISHDFLG_RAMUNCERR_Msk     (0x1U << NMI_INTRUPT_REGS_NMISHDFLG_RAMUNCERR_Pos)                                                          /*!< RAMUNCERR Mask 0x00000004 */
#define NMI_INTRUPT_REGS_NMISHDFLG_RAMUNCERR_Set(x)  (((uint32_t) (x) << NMI_INTRUPT_REGS_NMISHDFLG_RAMUNCERR_Pos) & NMI_INTRUPT_REGS_NMISHDFLG_RAMUNCERR_Msk)   /*!< RAMUNCERR Set Value */
#define NMI_INTRUPT_REGS_NMISHDFLG_RAMUNCERR_Get(x)  (((uint32_t) (x) & NMI_INTRUPT_REGS_NMISHDFLG_RAMUNCERR_Msk) >> NMI_INTRUPT_REGS_NMISHDFLG_RAMUNCERR_Pos)   /*!< RAMUNCERR Get Value */

#define NMI_INTRUPT_REGS_NMISHDFLG_CLOCKFAIL_Pos     (1U)                                                                                                        /*!< CLOCKFAIL Position 1 */
#define NMI_INTRUPT_REGS_NMISHDFLG_CLOCKFAIL_Msk     (0x1U << NMI_INTRUPT_REGS_NMISHDFLG_CLOCKFAIL_Pos)                                                          /*!< CLOCKFAIL Mask 0x00000002 */
#define NMI_INTRUPT_REGS_NMISHDFLG_CLOCKFAIL_Set(x)  (((uint32_t) (x) << NMI_INTRUPT_REGS_NMISHDFLG_CLOCKFAIL_Pos) & NMI_INTRUPT_REGS_NMISHDFLG_CLOCKFAIL_Msk)   /*!< CLOCKFAIL Set Value */
#define NMI_INTRUPT_REGS_NMISHDFLG_CLOCKFAIL_Get(x)  (((uint32_t) (x) & NMI_INTRUPT_REGS_NMISHDFLG_CLOCKFAIL_Msk) >> NMI_INTRUPT_REGS_NMISHDFLG_CLOCKFAIL_Pos)   /*!< CLOCKFAIL Get Value */

/* NMIWDCFG bitfield */
#define NMI_INTRUPT_REGS_NMIWDCFG_NMIWD_EN_Pos     (0U)                                                                                                    /*!< NMIWD_EN Position 0 */
#define NMI_INTRUPT_REGS_NMIWDCFG_NMIWD_EN_Msk     (0x1U << NMI_INTRUPT_REGS_NMIWDCFG_NMIWD_EN_Pos)                                                        /*!< NMIWD_EN Mask 0x00000001 */
#define NMI_INTRUPT_REGS_NMIWDCFG_NMIWD_EN_Set(x)  (((uint32_t) (x) << NMI_INTRUPT_REGS_NMIWDCFG_NMIWD_EN_Pos) & NMI_INTRUPT_REGS_NMIWDCFG_NMIWD_EN_Msk)   /*!< NMIWD_EN Set Value */
#define NMI_INTRUPT_REGS_NMIWDCFG_NMIWD_EN_Get(x)  (((uint32_t) (x) & NMI_INTRUPT_REGS_NMIWDCFG_NMIWD_EN_Msk) >> NMI_INTRUPT_REGS_NMIWDCFG_NMIWD_EN_Pos)   /*!< NMIWD_EN Get Value */

/* NMICLBCFG bitfield */
#define NMI_INTRUPT_REGS_NMICLBCFG_CLBNMISELECT_Pos     (0U)                                                                                                              /*!< CLBNMISELECT Position 0 */
#define NMI_INTRUPT_REGS_NMICLBCFG_CLBNMISELECT_Msk     (0x1U << NMI_INTRUPT_REGS_NMICLBCFG_CLBNMISELECT_Pos)                                                             /*!< CLBNMISELECT Mask 0x00000001 */
#define NMI_INTRUPT_REGS_NMICLBCFG_CLBNMISELECT_Set(x)  (((uint32_t) (x) << NMI_INTRUPT_REGS_NMICLBCFG_CLBNMISELECT_Pos) & NMI_INTRUPT_REGS_NMICLBCFG_CLBNMISELECT_Msk)   /*!< CLBNMISELECT Set Value */
#define NMI_INTRUPT_REGS_NMICLBCFG_CLBNMISELECT_Get(x)  (((uint32_t) (x) & NMI_INTRUPT_REGS_NMICLBCFG_CLBNMISELECT_Msk) >> NMI_INTRUPT_REGS_NMICLBCFG_CLBNMISELECT_Pos)   /*!< CLBNMISELECT Get Value */

/* XINT1CR bitfield */
#define XINT_REGS_XINT1CR_POLARITY_Pos     (2U)                                                                                    /*!< POLARITY Position 2 */
#define XINT_REGS_XINT1CR_POLARITY_Msk     (0x3U << XINT_REGS_XINT1CR_POLARITY_Pos)                                                /*!< POLARITY Mask 0x0000000C */
#define XINT_REGS_XINT1CR_POLARITY_Set(x)  (((uint16_t) (x) << XINT_REGS_XINT1CR_POLARITY_Pos) & XINT_REGS_XINT1CR_POLARITY_Msk)   /*!< POLARITY Set Value */
#define XINT_REGS_XINT1CR_POLARITY_Get(x)  (((uint16_t) (x) & XINT_REGS_XINT1CR_POLARITY_Msk) >> XINT_REGS_XINT1CR_POLARITY_Pos)   /*!< POLARITY Get Value */

#define XINT_REGS_XINT1CR_INTR_ENABLE_Pos     (0U)                                                                                          /*!< INTR_ENABLE Position 0 */
#define XINT_REGS_XINT1CR_INTR_ENABLE_Msk     (0x1U << XINT_REGS_XINT1CR_INTR_ENABLE_Pos)                                                   /*!< INTR_ENABLE Mask 0x00000001 */
#define XINT_REGS_XINT1CR_INTR_ENABLE_Set(x)  (((uint16_t) (x) << XINT_REGS_XINT1CR_INTR_ENABLE_Pos) & XINT_REGS_XINT1CR_INTR_ENABLE_Msk)   /*!< INTR_ENABLE Set Value */
#define XINT_REGS_XINT1CR_INTR_ENABLE_Get(x)  (((uint16_t) (x) & XINT_REGS_XINT1CR_INTR_ENABLE_Msk) >> XINT_REGS_XINT1CR_INTR_ENABLE_Pos)   /*!< INTR_ENABLE Get Value */

/* XINT2CR bitfield */
#define XINT_REGS_XINT2CR_POLARITY_Pos     (2U)                                                                                    /*!< POLARITY Position 2 */
#define XINT_REGS_XINT2CR_POLARITY_Msk     (0x3U << XINT_REGS_XINT2CR_POLARITY_Pos)                                                /*!< POLARITY Mask 0x0000000C */
#define XINT_REGS_XINT2CR_POLARITY_Set(x)  (((uint16_t) (x) << XINT_REGS_XINT2CR_POLARITY_Pos) & XINT_REGS_XINT2CR_POLARITY_Msk)   /*!< POLARITY Set Value */
#define XINT_REGS_XINT2CR_POLARITY_Get(x)  (((uint16_t) (x) & XINT_REGS_XINT2CR_POLARITY_Msk) >> XINT_REGS_XINT2CR_POLARITY_Pos)   /*!< POLARITY Get Value */

#define XINT_REGS_XINT2CR_INTR_ENABLE_Pos     (0U)                                                                                          /*!< INTR_ENABLE Position 0 */
#define XINT_REGS_XINT2CR_INTR_ENABLE_Msk     (0x1U << XINT_REGS_XINT2CR_INTR_ENABLE_Pos)                                                   /*!< INTR_ENABLE Mask 0x00000001 */
#define XINT_REGS_XINT2CR_INTR_ENABLE_Set(x)  (((uint16_t) (x) << XINT_REGS_XINT2CR_INTR_ENABLE_Pos) & XINT_REGS_XINT2CR_INTR_ENABLE_Msk)   /*!< INTR_ENABLE Set Value */
#define XINT_REGS_XINT2CR_INTR_ENABLE_Get(x)  (((uint16_t) (x) & XINT_REGS_XINT2CR_INTR_ENABLE_Msk) >> XINT_REGS_XINT2CR_INTR_ENABLE_Pos)   /*!< INTR_ENABLE Get Value */

/* XINT3CR bitfield */
#define XINT_REGS_XINT3CR_POLARITY_Pos     (2U)                                                                                    /*!< POLARITY Position 2 */
#define XINT_REGS_XINT3CR_POLARITY_Msk     (0x3U << XINT_REGS_XINT3CR_POLARITY_Pos)                                                /*!< POLARITY Mask 0x0000000C */
#define XINT_REGS_XINT3CR_POLARITY_Set(x)  (((uint16_t) (x) << XINT_REGS_XINT3CR_POLARITY_Pos) & XINT_REGS_XINT3CR_POLARITY_Msk)   /*!< POLARITY Set Value */
#define XINT_REGS_XINT3CR_POLARITY_Get(x)  (((uint16_t) (x) & XINT_REGS_XINT3CR_POLARITY_Msk) >> XINT_REGS_XINT3CR_POLARITY_Pos)   /*!< POLARITY Get Value */

#define XINT_REGS_XINT3CR_INTR_ENABLE_Pos     (0U)                                                                                          /*!< INTR_ENABLE Position 0 */
#define XINT_REGS_XINT3CR_INTR_ENABLE_Msk     (0x1U << XINT_REGS_XINT3CR_INTR_ENABLE_Pos)                                                   /*!< INTR_ENABLE Mask 0x00000001 */
#define XINT_REGS_XINT3CR_INTR_ENABLE_Set(x)  (((uint16_t) (x) << XINT_REGS_XINT3CR_INTR_ENABLE_Pos) & XINT_REGS_XINT3CR_INTR_ENABLE_Msk)   /*!< INTR_ENABLE Set Value */
#define XINT_REGS_XINT3CR_INTR_ENABLE_Get(x)  (((uint16_t) (x) & XINT_REGS_XINT3CR_INTR_ENABLE_Msk) >> XINT_REGS_XINT3CR_INTR_ENABLE_Pos)   /*!< INTR_ENABLE Get Value */

/* XINT4CR bitfield */
#define XINT_REGS_XINT4CR_POLARITY_Pos     (2U)                                                                                    /*!< POLARITY Position 2 */
#define XINT_REGS_XINT4CR_POLARITY_Msk     (0x3U << XINT_REGS_XINT4CR_POLARITY_Pos)                                                /*!< POLARITY Mask 0x0000000C */
#define XINT_REGS_XINT4CR_POLARITY_Set(x)  (((uint16_t) (x) << XINT_REGS_XINT4CR_POLARITY_Pos) & XINT_REGS_XINT4CR_POLARITY_Msk)   /*!< POLARITY Set Value */
#define XINT_REGS_XINT4CR_POLARITY_Get(x)  (((uint16_t) (x) & XINT_REGS_XINT4CR_POLARITY_Msk) >> XINT_REGS_XINT4CR_POLARITY_Pos)   /*!< POLARITY Get Value */

#define XINT_REGS_XINT4CR_INTR_ENABLE_Pos     (0U)                                                                                          /*!< INTR_ENABLE Position 0 */
#define XINT_REGS_XINT4CR_INTR_ENABLE_Msk     (0x1U << XINT_REGS_XINT4CR_INTR_ENABLE_Pos)                                                   /*!< INTR_ENABLE Mask 0x00000001 */
#define XINT_REGS_XINT4CR_INTR_ENABLE_Set(x)  (((uint16_t) (x) << XINT_REGS_XINT4CR_INTR_ENABLE_Pos) & XINT_REGS_XINT4CR_INTR_ENABLE_Msk)   /*!< INTR_ENABLE Set Value */
#define XINT_REGS_XINT4CR_INTR_ENABLE_Get(x)  (((uint16_t) (x) & XINT_REGS_XINT4CR_INTR_ENABLE_Msk) >> XINT_REGS_XINT4CR_INTR_ENABLE_Pos)   /*!< INTR_ENABLE Get Value */

/* XINT5CR bitfield */
#define XINT_REGS_XINT5CR_POLARITY_Pos     (2U)                                                                                    /*!< POLARITY Position 2 */
#define XINT_REGS_XINT5CR_POLARITY_Msk     (0x3U << XINT_REGS_XINT5CR_POLARITY_Pos)                                                /*!< POLARITY Mask 0x0000000C */
#define XINT_REGS_XINT5CR_POLARITY_Set(x)  (((uint32_t) (x) << XINT_REGS_XINT5CR_POLARITY_Pos) & XINT_REGS_XINT5CR_POLARITY_Msk)   /*!< POLARITY Set Value */
#define XINT_REGS_XINT5CR_POLARITY_Get(x)  (((uint32_t) (x) & XINT_REGS_XINT5CR_POLARITY_Msk) >> XINT_REGS_XINT5CR_POLARITY_Pos)   /*!< POLARITY Get Value */

#define XINT_REGS_XINT5CR_INTR_ENABLE_Pos     (0U)                                                                                          /*!< INTR_ENABLE Position 0 */
#define XINT_REGS_XINT5CR_INTR_ENABLE_Msk     (0x1U << XINT_REGS_XINT5CR_INTR_ENABLE_Pos)                                                   /*!< INTR_ENABLE Mask 0x00000001 */
#define XINT_REGS_XINT5CR_INTR_ENABLE_Set(x)  (((uint32_t) (x) << XINT_REGS_XINT5CR_INTR_ENABLE_Pos) & XINT_REGS_XINT5CR_INTR_ENABLE_Msk)   /*!< INTR_ENABLE Set Value */
#define XINT_REGS_XINT5CR_INTR_ENABLE_Get(x)  (((uint32_t) (x) & XINT_REGS_XINT5CR_INTR_ENABLE_Msk) >> XINT_REGS_XINT5CR_INTR_ENABLE_Pos)   /*!< INTR_ENABLE Get Value */

/* XINT1CTR bitfield */
#define XINT_REGS_XINT1CTR_INTCTR_Pos     (0U)                                                                                  /*!< INTCTR Position 0 */
#define XINT_REGS_XINT1CTR_INTCTR_Msk     (0xffffU << XINT_REGS_XINT1CTR_INTCTR_Pos)                                            /*!< INTCTR Mask 0x0000FFFF */
#define XINT_REGS_XINT1CTR_INTCTR_Set(x)  (((uint16_t) (x) << XINT_REGS_XINT1CTR_INTCTR_Pos) & XINT_REGS_XINT1CTR_INTCTR_Msk)   /*!< INTCTR Set Value */
#define XINT_REGS_XINT1CTR_INTCTR_Get(x)  (((uint16_t) (x) & XINT_REGS_XINT1CTR_INTCTR_Msk) >> XINT_REGS_XINT1CTR_INTCTR_Pos)   /*!< INTCTR Get Value */

/* XINT2CTR bitfield */
#define XINT_REGS_XINT2CTR_INTCTR_Pos     (0U)                                                                                  /*!< INTCTR Position 0 */
#define XINT_REGS_XINT2CTR_INTCTR_Msk     (0xffffU << XINT_REGS_XINT2CTR_INTCTR_Pos)                                            /*!< INTCTR Mask 0x0000FFFF */
#define XINT_REGS_XINT2CTR_INTCTR_Set(x)  (((uint16_t) (x) << XINT_REGS_XINT2CTR_INTCTR_Pos) & XINT_REGS_XINT2CTR_INTCTR_Msk)   /*!< INTCTR Set Value */
#define XINT_REGS_XINT2CTR_INTCTR_Get(x)  (((uint16_t) (x) & XINT_REGS_XINT2CTR_INTCTR_Msk) >> XINT_REGS_XINT2CTR_INTCTR_Pos)   /*!< INTCTR Get Value */

/* XINT3CTR bitfield */
#define XINT_REGS_XINT3CTR_INTCTR_Pos     (0U)                                                                                  /*!< INTCTR Position 0 */
#define XINT_REGS_XINT3CTR_INTCTR_Msk     (0xffffU << XINT_REGS_XINT3CTR_INTCTR_Pos)                                            /*!< INTCTR Mask 0x0000FFFF */
#define XINT_REGS_XINT3CTR_INTCTR_Set(x)  (((uint32_t) (x) << XINT_REGS_XINT3CTR_INTCTR_Pos) & XINT_REGS_XINT3CTR_INTCTR_Msk)   /*!< INTCTR Set Value */
#define XINT_REGS_XINT3CTR_INTCTR_Get(x)  (((uint32_t) (x) & XINT_REGS_XINT3CTR_INTCTR_Msk) >> XINT_REGS_XINT3CTR_INTCTR_Pos)   /*!< INTCTR Get Value */

/* XINT4CTR bitfield */
#define XINT_REGS_XINT4CTR_INTCTR_Pos     (0U)                                                                                  /*!< INTCTR Position 0 */
#define XINT_REGS_XINT4CTR_INTCTR_Msk     (0xffffU << XINT_REGS_XINT4CTR_INTCTR_Pos)                                            /*!< INTCTR Mask 0x0000FFFF */
#define XINT_REGS_XINT4CTR_INTCTR_Set(x)  (((uint32_t) (x) << XINT_REGS_XINT4CTR_INTCTR_Pos) & XINT_REGS_XINT4CTR_INTCTR_Msk)   /*!< INTCTR Set Value */
#define XINT_REGS_XINT4CTR_INTCTR_Get(x)  (((uint32_t) (x) & XINT_REGS_XINT4CTR_INTCTR_Msk) >> XINT_REGS_XINT4CTR_INTCTR_Pos)   /*!< INTCTR Get Value */

/* XINT5CTR bitfield */
#define XINT_REGS_XINT5CTR_INTCTR_Pos     (0U)                                                                                  /*!< INTCTR Position 0 */
#define XINT_REGS_XINT5CTR_INTCTR_Msk     (0xffffU << XINT_REGS_XINT5CTR_INTCTR_Pos)                                            /*!< INTCTR Mask 0x0000FFFF */
#define XINT_REGS_XINT5CTR_INTCTR_Set(x)  (((uint32_t) (x) << XINT_REGS_XINT5CTR_INTCTR_Pos) & XINT_REGS_XINT5CTR_INTCTR_Msk)   /*!< INTCTR Set Value */
#define XINT_REGS_XINT5CTR_INTCTR_Get(x)  (((uint32_t) (x) & XINT_REGS_XINT5CTR_INTCTR_Msk) >> XINT_REGS_XINT5CTR_INTCTR_Pos)   /*!< INTCTR Get Value */

/* XINT1FLG bitfield */
#define XINT_REGS_XINT1FLG_XINTFLG_Pos     (0U)                                                                                    /*!< XINTFLG Position 0 */
#define XINT_REGS_XINT1FLG_XINTFLG_Msk     (0x1U << XINT_REGS_XINT1FLG_XINTFLG_Pos)                                                /*!< XINTFLG Mask 0x00000001 */
#define XINT_REGS_XINT1FLG_XINTFLG_Set(x)  (((uint32_t) (x) << XINT_REGS_XINT1FLG_XINTFLG_Pos) & XINT_REGS_XINT1FLG_XINTFLG_Msk)   /*!< XINTFLG Set Value */
#define XINT_REGS_XINT1FLG_XINTFLG_Get(x)  (((uint32_t) (x) & XINT_REGS_XINT1FLG_XINTFLG_Msk) >> XINT_REGS_XINT1FLG_XINTFLG_Pos)   /*!< XINTFLG Get Value */

/* XINT2FLG bitfield */
#define XINT_REGS_XINT2FLG_XINTFLG_Pos     (0U)                                                                                    /*!< XINTFLG Position 0 */
#define XINT_REGS_XINT2FLG_XINTFLG_Msk     (0x1U << XINT_REGS_XINT2FLG_XINTFLG_Pos)                                                /*!< XINTFLG Mask 0x00000001 */
#define XINT_REGS_XINT2FLG_XINTFLG_Set(x)  (((uint32_t) (x) << XINT_REGS_XINT2FLG_XINTFLG_Pos) & XINT_REGS_XINT2FLG_XINTFLG_Msk)   /*!< XINTFLG Set Value */
#define XINT_REGS_XINT2FLG_XINTFLG_Get(x)  (((uint32_t) (x) & XINT_REGS_XINT2FLG_XINTFLG_Msk) >> XINT_REGS_XINT2FLG_XINTFLG_Pos)   /*!< XINTFLG Get Value */

/* XINT3FLG bitfield */
#define XINT_REGS_XINT3FLG_XINTFLG_Pos     (0U)                                                                                    /*!< XINTFLG Position 0 */
#define XINT_REGS_XINT3FLG_XINTFLG_Msk     (0x1U << XINT_REGS_XINT3FLG_XINTFLG_Pos)                                                /*!< XINTFLG Mask 0x00000001 */
#define XINT_REGS_XINT3FLG_XINTFLG_Set(x)  (((uint32_t) (x) << XINT_REGS_XINT3FLG_XINTFLG_Pos) & XINT_REGS_XINT3FLG_XINTFLG_Msk)   /*!< XINTFLG Set Value */
#define XINT_REGS_XINT3FLG_XINTFLG_Get(x)  (((uint32_t) (x) & XINT_REGS_XINT3FLG_XINTFLG_Msk) >> XINT_REGS_XINT3FLG_XINTFLG_Pos)   /*!< XINTFLG Get Value */

/* XINT4FLG bitfield */
#define XINT_REGS_XINT4FLG_XINTFLG_Pos     (0U)                                                                                    /*!< XINTFLG Position 0 */
#define XINT_REGS_XINT4FLG_XINTFLG_Msk     (0x1U << XINT_REGS_XINT4FLG_XINTFLG_Pos)                                                /*!< XINTFLG Mask 0x00000001 */
#define XINT_REGS_XINT4FLG_XINTFLG_Set(x)  (((uint32_t) (x) << XINT_REGS_XINT4FLG_XINTFLG_Pos) & XINT_REGS_XINT4FLG_XINTFLG_Msk)   /*!< XINTFLG Set Value */
#define XINT_REGS_XINT4FLG_XINTFLG_Get(x)  (((uint32_t) (x) & XINT_REGS_XINT4FLG_XINTFLG_Msk) >> XINT_REGS_XINT4FLG_XINTFLG_Pos)   /*!< XINTFLG Get Value */

/* XINT5FLG bitfield */
#define XINT_REGS_XINT5FLG_XINTFLG_Pos     (0U)                                                                                    /*!< XINTFLG Position 0 */
#define XINT_REGS_XINT5FLG_XINTFLG_Msk     (0x1U << XINT_REGS_XINT5FLG_XINTFLG_Pos)                                                /*!< XINTFLG Mask 0x00000001 */
#define XINT_REGS_XINT5FLG_XINTFLG_Set(x)  (((uint32_t) (x) << XINT_REGS_XINT5FLG_XINTFLG_Pos) & XINT_REGS_XINT5FLG_XINTFLG_Msk)   /*!< XINTFLG Set Value */
#define XINT_REGS_XINT5FLG_XINTFLG_Get(x)  (((uint32_t) (x) & XINT_REGS_XINT5FLG_XINTFLG_Msk) >> XINT_REGS_XINT5FLG_XINTFLG_Pos)   /*!< XINTFLG Get Value */

/* XINT1CLR bitfield */
#define XINT_REGS_XINT1CLR_XINTCLR_Pos     (0U)                                                                                    /*!< XINTCLR Position 0 */
#define XINT_REGS_XINT1CLR_XINTCLR_Msk     (0x1U << XINT_REGS_XINT1CLR_XINTCLR_Pos)                                                /*!< XINTCLR Mask 0x00000001 */
#define XINT_REGS_XINT1CLR_XINTCLR_Set(x)  (((uint32_t) (x) << XINT_REGS_XINT1CLR_XINTCLR_Pos) & XINT_REGS_XINT1CLR_XINTCLR_Msk)   /*!< XINTCLR Set Value */
#define XINT_REGS_XINT1CLR_XINTCLR_Get(x)  (((uint32_t) (x) & XINT_REGS_XINT1CLR_XINTCLR_Msk) >> XINT_REGS_XINT1CLR_XINTCLR_Pos)   /*!< XINTCLR Get Value */

/* XINT2CLR bitfield */
#define XINT_REGS_XINT2CLR_XINTCLR_Pos     (0U)                                                                                    /*!< XINTCLR Position 0 */
#define XINT_REGS_XINT2CLR_XINTCLR_Msk     (0x1U << XINT_REGS_XINT2CLR_XINTCLR_Pos)                                                /*!< XINTCLR Mask 0x00000001 */
#define XINT_REGS_XINT2CLR_XINTCLR_Set(x)  (((uint32_t) (x) << XINT_REGS_XINT2CLR_XINTCLR_Pos) & XINT_REGS_XINT2CLR_XINTCLR_Msk)   /*!< XINTCLR Set Value */
#define XINT_REGS_XINT2CLR_XINTCLR_Get(x)  (((uint32_t) (x) & XINT_REGS_XINT2CLR_XINTCLR_Msk) >> XINT_REGS_XINT2CLR_XINTCLR_Pos)   /*!< XINTCLR Get Value */

/* XINT3CLR bitfield */
#define XINT_REGS_XINT3CLR_XINTCLR_Pos     (0U)                                                                                    /*!< XINTCLR Position 0 */
#define XINT_REGS_XINT3CLR_XINTCLR_Msk     (0x1U << XINT_REGS_XINT3CLR_XINTCLR_Pos)                                                /*!< XINTCLR Mask 0x00000001 */
#define XINT_REGS_XINT3CLR_XINTCLR_Set(x)  (((uint32_t) (x) << XINT_REGS_XINT3CLR_XINTCLR_Pos) & XINT_REGS_XINT3CLR_XINTCLR_Msk)   /*!< XINTCLR Set Value */
#define XINT_REGS_XINT3CLR_XINTCLR_Get(x)  (((uint32_t) (x) & XINT_REGS_XINT3CLR_XINTCLR_Msk) >> XINT_REGS_XINT3CLR_XINTCLR_Pos)   /*!< XINTCLR Get Value */

/* XINT4CLR bitfield */
#define XINT_REGS_XINT4CLR_XINTCLR_Pos     (0U)                                                                                    /*!< XINTCLR Position 0 */
#define XINT_REGS_XINT4CLR_XINTCLR_Msk     (0x1U << XINT_REGS_XINT4CLR_XINTCLR_Pos)                                                /*!< XINTCLR Mask 0x00000001 */
#define XINT_REGS_XINT4CLR_XINTCLR_Set(x)  (((uint32_t) (x) << XINT_REGS_XINT4CLR_XINTCLR_Pos) & XINT_REGS_XINT4CLR_XINTCLR_Msk)   /*!< XINTCLR Set Value */
#define XINT_REGS_XINT4CLR_XINTCLR_Get(x)  (((uint32_t) (x) & XINT_REGS_XINT4CLR_XINTCLR_Msk) >> XINT_REGS_XINT4CLR_XINTCLR_Pos)   /*!< XINTCLR Get Value */

/* XINT5CLR bitfield */
#define XINT_REGS_XINT5CLR_XINTCLR_Pos     (0U)                                                                                    /*!< XINTCLR Position 0 */
#define XINT_REGS_XINT5CLR_XINTCLR_Msk     (0x1U << XINT_REGS_XINT5CLR_XINTCLR_Pos)                                                /*!< XINTCLR Mask 0x00000001 */
#define XINT_REGS_XINT5CLR_XINTCLR_Set(x)  (((uint32_t) (x) << XINT_REGS_XINT5CLR_XINTCLR_Pos) & XINT_REGS_XINT5CLR_XINTCLR_Msk)   /*!< XINTCLR Set Value */
#define XINT_REGS_XINT5CLR_XINTCLR_Get(x)  (((uint32_t) (x) & XINT_REGS_XINT5CLR_XINTCLR_Msk) >> XINT_REGS_XINT5CLR_XINTCLR_Pos)   /*!< XINTCLR Get Value */

/* CLKSEM bitfield */
#define CLK_CFG_REGS_CLKSEM_KEY_Pos     (16U)                                                                             /*!< KEY Position 16 */
#define CLK_CFG_REGS_CLKSEM_KEY_Msk     (0xffffU << CLK_CFG_REGS_CLKSEM_KEY_Pos)                                          /*!< KEY Mask 0xFFFF0000 */
#define CLK_CFG_REGS_CLKSEM_KEY_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_CLKSEM_KEY_Pos) & CLK_CFG_REGS_CLKSEM_KEY_Msk)   /*!< KEY Set Value */
#define CLK_CFG_REGS_CLKSEM_KEY_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_CLKSEM_KEY_Msk) >> CLK_CFG_REGS_CLKSEM_KEY_Pos)   /*!< KEY Get Value */

#define CLK_CFG_REGS_CLKSEM_SEM_Pos     (0U)                                                                              /*!< SEM Position 0 */
#define CLK_CFG_REGS_CLKSEM_SEM_Msk     (0x3U << CLK_CFG_REGS_CLKSEM_SEM_Pos)                                             /*!< SEM Mask 0x00000003 */
#define CLK_CFG_REGS_CLKSEM_SEM_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_CLKSEM_SEM_Pos) & CLK_CFG_REGS_CLKSEM_SEM_Msk)   /*!< SEM Set Value */
#define CLK_CFG_REGS_CLKSEM_SEM_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_CLKSEM_SEM_Msk) >> CLK_CFG_REGS_CLKSEM_SEM_Pos)   /*!< SEM Get Value */

/* CLKCFGLOCK1 bitfield */
#define CLK_CFG_REGS_CLKCFGLOCK1_LOSPCP_Pos     (15U)                                                                                             /*!< LOSPCP Position 15 */
#define CLK_CFG_REGS_CLKCFGLOCK1_LOSPCP_Msk     (0x1U << CLK_CFG_REGS_CLKCFGLOCK1_LOSPCP_Pos)                                                     /*!< LOSPCP Mask 0x00008000 */
#define CLK_CFG_REGS_CLKCFGLOCK1_LOSPCP_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_CLKCFGLOCK1_LOSPCP_Pos) & CLK_CFG_REGS_CLKCFGLOCK1_LOSPCP_Msk)   /*!< LOSPCP Set Value */
#define CLK_CFG_REGS_CLKCFGLOCK1_LOSPCP_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_CLKCFGLOCK1_LOSPCP_Msk) >> CLK_CFG_REGS_CLKCFGLOCK1_LOSPCP_Pos)   /*!< LOSPCP Get Value */

#define CLK_CFG_REGS_CLKCFGLOCK1_PERCLKDIVSEL_Pos     (13U)                                                                                                         /*!< PERCLKDIVSEL Position 13 */
#define CLK_CFG_REGS_CLKCFGLOCK1_PERCLKDIVSEL_Msk     (0x1U << CLK_CFG_REGS_CLKCFGLOCK1_PERCLKDIVSEL_Pos)                                                           /*!< PERCLKDIVSEL Mask 0x00002000 */
#define CLK_CFG_REGS_CLKCFGLOCK1_PERCLKDIVSEL_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_CLKCFGLOCK1_PERCLKDIVSEL_Pos) & CLK_CFG_REGS_CLKCFGLOCK1_PERCLKDIVSEL_Msk)   /*!< PERCLKDIVSEL Set Value */
#define CLK_CFG_REGS_CLKCFGLOCK1_PERCLKDIVSEL_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_CLKCFGLOCK1_PERCLKDIVSEL_Msk) >> CLK_CFG_REGS_CLKCFGLOCK1_PERCLKDIVSEL_Pos)   /*!< PERCLKDIVSEL Get Value */

#define CLK_CFG_REGS_CLKCFGLOCK1_AUXCLKDIVSEL_Pos     (12U)                                                                                                         /*!< AUXCLKDIVSEL Position 12 */
#define CLK_CFG_REGS_CLKCFGLOCK1_AUXCLKDIVSEL_Msk     (0x1U << CLK_CFG_REGS_CLKCFGLOCK1_AUXCLKDIVSEL_Pos)                                                           /*!< AUXCLKDIVSEL Mask 0x00001000 */
#define CLK_CFG_REGS_CLKCFGLOCK1_AUXCLKDIVSEL_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_CLKCFGLOCK1_AUXCLKDIVSEL_Pos) & CLK_CFG_REGS_CLKCFGLOCK1_AUXCLKDIVSEL_Msk)   /*!< AUXCLKDIVSEL Set Value */
#define CLK_CFG_REGS_CLKCFGLOCK1_AUXCLKDIVSEL_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_CLKCFGLOCK1_AUXCLKDIVSEL_Msk) >> CLK_CFG_REGS_CLKCFGLOCK1_AUXCLKDIVSEL_Pos)   /*!< AUXCLKDIVSEL Get Value */

#define CLK_CFG_REGS_CLKCFGLOCK1_SYSCLKDIVSEL_Pos     (11U)                                                                                                         /*!< SYSCLKDIVSEL Position 11 */
#define CLK_CFG_REGS_CLKCFGLOCK1_SYSCLKDIVSEL_Msk     (0x1U << CLK_CFG_REGS_CLKCFGLOCK1_SYSCLKDIVSEL_Pos)                                                           /*!< SYSCLKDIVSEL Mask 0x00000800 */
#define CLK_CFG_REGS_CLKCFGLOCK1_SYSCLKDIVSEL_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_CLKCFGLOCK1_SYSCLKDIVSEL_Pos) & CLK_CFG_REGS_CLKCFGLOCK1_SYSCLKDIVSEL_Msk)   /*!< SYSCLKDIVSEL Set Value */
#define CLK_CFG_REGS_CLKCFGLOCK1_SYSCLKDIVSEL_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_CLKCFGLOCK1_SYSCLKDIVSEL_Msk) >> CLK_CFG_REGS_CLKCFGLOCK1_SYSCLKDIVSEL_Pos)   /*!< SYSCLKDIVSEL Get Value */

#define CLK_CFG_REGS_CLKCFGLOCK1_AUXPLLMULT_Pos     (10U)                                                                                                     /*!< AUXPLLMULT Position 10 */
#define CLK_CFG_REGS_CLKCFGLOCK1_AUXPLLMULT_Msk     (0x1U << CLK_CFG_REGS_CLKCFGLOCK1_AUXPLLMULT_Pos)                                                         /*!< AUXPLLMULT Mask 0x00000400 */
#define CLK_CFG_REGS_CLKCFGLOCK1_AUXPLLMULT_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_CLKCFGLOCK1_AUXPLLMULT_Pos) & CLK_CFG_REGS_CLKCFGLOCK1_AUXPLLMULT_Msk)   /*!< AUXPLLMULT Set Value */
#define CLK_CFG_REGS_CLKCFGLOCK1_AUXPLLMULT_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_CLKCFGLOCK1_AUXPLLMULT_Msk) >> CLK_CFG_REGS_CLKCFGLOCK1_AUXPLLMULT_Pos)   /*!< AUXPLLMULT Get Value */

#define CLK_CFG_REGS_CLKCFGLOCK1_AUXPLLCTL1_Pos     (7U)                                                                                                      /*!< AUXPLLCTL1 Position 7 */
#define CLK_CFG_REGS_CLKCFGLOCK1_AUXPLLCTL1_Msk     (0x1U << CLK_CFG_REGS_CLKCFGLOCK1_AUXPLLCTL1_Pos)                                                         /*!< AUXPLLCTL1 Mask 0x00000080 */
#define CLK_CFG_REGS_CLKCFGLOCK1_AUXPLLCTL1_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_CLKCFGLOCK1_AUXPLLCTL1_Pos) & CLK_CFG_REGS_CLKCFGLOCK1_AUXPLLCTL1_Msk)   /*!< AUXPLLCTL1 Set Value */
#define CLK_CFG_REGS_CLKCFGLOCK1_AUXPLLCTL1_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_CLKCFGLOCK1_AUXPLLCTL1_Msk) >> CLK_CFG_REGS_CLKCFGLOCK1_AUXPLLCTL1_Pos)   /*!< AUXPLLCTL1 Get Value */

#define CLK_CFG_REGS_CLKCFGLOCK1_SYSPLLMULT_Pos     (6U)                                                                                                      /*!< SYSPLLMULT Position 6 */
#define CLK_CFG_REGS_CLKCFGLOCK1_SYSPLLMULT_Msk     (0x1U << CLK_CFG_REGS_CLKCFGLOCK1_SYSPLLMULT_Pos)                                                         /*!< SYSPLLMULT Mask 0x00000040 */
#define CLK_CFG_REGS_CLKCFGLOCK1_SYSPLLMULT_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_CLKCFGLOCK1_SYSPLLMULT_Pos) & CLK_CFG_REGS_CLKCFGLOCK1_SYSPLLMULT_Msk)   /*!< SYSPLLMULT Set Value */
#define CLK_CFG_REGS_CLKCFGLOCK1_SYSPLLMULT_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_CLKCFGLOCK1_SYSPLLMULT_Msk) >> CLK_CFG_REGS_CLKCFGLOCK1_SYSPLLMULT_Pos)   /*!< SYSPLLMULT Get Value */

#define CLK_CFG_REGS_CLKCFGLOCK1_SYSPLLCTL1_Pos     (3U)                                                                                                      /*!< SYSPLLCTL1 Position 3 */
#define CLK_CFG_REGS_CLKCFGLOCK1_SYSPLLCTL1_Msk     (0x1U << CLK_CFG_REGS_CLKCFGLOCK1_SYSPLLCTL1_Pos)                                                         /*!< SYSPLLCTL1 Mask 0x00000008 */
#define CLK_CFG_REGS_CLKCFGLOCK1_SYSPLLCTL1_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_CLKCFGLOCK1_SYSPLLCTL1_Pos) & CLK_CFG_REGS_CLKCFGLOCK1_SYSPLLCTL1_Msk)   /*!< SYSPLLCTL1 Set Value */
#define CLK_CFG_REGS_CLKCFGLOCK1_SYSPLLCTL1_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_CLKCFGLOCK1_SYSPLLCTL1_Msk) >> CLK_CFG_REGS_CLKCFGLOCK1_SYSPLLCTL1_Pos)   /*!< SYSPLLCTL1 Get Value */

#define CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL3_Pos     (2U)                                                                                                      /*!< CLKSRCCTL3 Position 2 */
#define CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL3_Msk     (0x1U << CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL3_Pos)                                                         /*!< CLKSRCCTL3 Mask 0x00000004 */
#define CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL3_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL3_Pos) & CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL3_Msk)   /*!< CLKSRCCTL3 Set Value */
#define CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL3_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL3_Msk) >> CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL3_Pos)   /*!< CLKSRCCTL3 Get Value */

#define CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL2_Pos     (1U)                                                                                                      /*!< CLKSRCCTL2 Position 1 */
#define CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL2_Msk     (0x1U << CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL2_Pos)                                                         /*!< CLKSRCCTL2 Mask 0x00000002 */
#define CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL2_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL2_Pos) & CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL2_Msk)   /*!< CLKSRCCTL2 Set Value */
#define CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL2_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL2_Msk) >> CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL2_Pos)   /*!< CLKSRCCTL2 Get Value */

#define CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL1_Pos     (0U)                                                                                                      /*!< CLKSRCCTL1 Position 0 */
#define CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL1_Msk     (0x1U << CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL1_Pos)                                                         /*!< CLKSRCCTL1 Mask 0x00000001 */
#define CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL1_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL1_Pos) & CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL1_Msk)   /*!< CLKSRCCTL1 Set Value */
#define CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL1_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL1_Msk) >> CLK_CFG_REGS_CLKCFGLOCK1_CLKSRCCTL1_Pos)   /*!< CLKSRCCTL1 Get Value */

/* CLKSRCCTL1 bitfield */
#define CLK_CFG_REGS_CLKSRCCTL1_XTAL_DS_Pos     (16U)                                                                                             /*!< XTAL_DS Position 16 */
#define CLK_CFG_REGS_CLKSRCCTL1_XTAL_DS_Msk     (0x3U << CLK_CFG_REGS_CLKSRCCTL1_XTAL_DS_Pos)                                                     /*!< XTAL_DS Mask 0x00030000 */
#define CLK_CFG_REGS_CLKSRCCTL1_XTAL_DS_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_CLKSRCCTL1_XTAL_DS_Pos) & CLK_CFG_REGS_CLKSRCCTL1_XTAL_DS_Msk)   /*!< XTAL_DS Set Value */
#define CLK_CFG_REGS_CLKSRCCTL1_XTAL_DS_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_CLKSRCCTL1_XTAL_DS_Msk) >> CLK_CFG_REGS_CLKSRCCTL1_XTAL_DS_Pos)   /*!< XTAL_DS Get Value */

#define CLK_CFG_REGS_CLKSRCCTL1_WDHALTI_Pos     (5U)                                                                                              /*!< WDHALTI Position 5 */
#define CLK_CFG_REGS_CLKSRCCTL1_WDHALTI_Msk     (0x1U << CLK_CFG_REGS_CLKSRCCTL1_WDHALTI_Pos)                                                     /*!< WDHALTI Mask 0x00000020 */
#define CLK_CFG_REGS_CLKSRCCTL1_WDHALTI_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_CLKSRCCTL1_WDHALTI_Pos) & CLK_CFG_REGS_CLKSRCCTL1_WDHALTI_Msk)   /*!< WDHALTI Set Value */
#define CLK_CFG_REGS_CLKSRCCTL1_WDHALTI_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_CLKSRCCTL1_WDHALTI_Msk) >> CLK_CFG_REGS_CLKSRCCTL1_WDHALTI_Pos)   /*!< WDHALTI Get Value */

#define CLK_CFG_REGS_CLKSRCCTL1_XTALOFF_Pos     (4U)                                                                                              /*!< XTALOFF Position 4 */
#define CLK_CFG_REGS_CLKSRCCTL1_XTALOFF_Msk     (0x1U << CLK_CFG_REGS_CLKSRCCTL1_XTALOFF_Pos)                                                     /*!< XTALOFF Mask 0x00000010 */
#define CLK_CFG_REGS_CLKSRCCTL1_XTALOFF_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_CLKSRCCTL1_XTALOFF_Pos) & CLK_CFG_REGS_CLKSRCCTL1_XTALOFF_Msk)   /*!< XTALOFF Set Value */
#define CLK_CFG_REGS_CLKSRCCTL1_XTALOFF_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_CLKSRCCTL1_XTALOFF_Msk) >> CLK_CFG_REGS_CLKSRCCTL1_XTALOFF_Pos)   /*!< XTALOFF Get Value */

#define CLK_CFG_REGS_CLKSRCCTL1_INTOSC2OFF_Pos     (3U)                                                                                                    /*!< INTOSC2OFF Position 3 */
#define CLK_CFG_REGS_CLKSRCCTL1_INTOSC2OFF_Msk     (0x1U << CLK_CFG_REGS_CLKSRCCTL1_INTOSC2OFF_Pos)                                                        /*!< INTOSC2OFF Mask 0x00000008 */
#define CLK_CFG_REGS_CLKSRCCTL1_INTOSC2OFF_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_CLKSRCCTL1_INTOSC2OFF_Pos) & CLK_CFG_REGS_CLKSRCCTL1_INTOSC2OFF_Msk)   /*!< INTOSC2OFF Set Value */
#define CLK_CFG_REGS_CLKSRCCTL1_INTOSC2OFF_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_CLKSRCCTL1_INTOSC2OFF_Msk) >> CLK_CFG_REGS_CLKSRCCTL1_INTOSC2OFF_Pos)   /*!< INTOSC2OFF Get Value */

#define CLK_CFG_REGS_CLKSRCCTL1_OSCCLKSRCSEL_Pos     (0U)                                                                                                        /*!< OSCCLKSRCSEL Position 0 */
#define CLK_CFG_REGS_CLKSRCCTL1_OSCCLKSRCSEL_Msk     (0x3U << CLK_CFG_REGS_CLKSRCCTL1_OSCCLKSRCSEL_Pos)                                                          /*!< OSCCLKSRCSEL Mask 0x00000003 */
#define CLK_CFG_REGS_CLKSRCCTL1_OSCCLKSRCSEL_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_CLKSRCCTL1_OSCCLKSRCSEL_Pos) & CLK_CFG_REGS_CLKSRCCTL1_OSCCLKSRCSEL_Msk)   /*!< OSCCLKSRCSEL Set Value */
#define CLK_CFG_REGS_CLKSRCCTL1_OSCCLKSRCSEL_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_CLKSRCCTL1_OSCCLKSRCSEL_Msk) >> CLK_CFG_REGS_CLKSRCCTL1_OSCCLKSRCSEL_Pos)   /*!< OSCCLKSRCSEL Get Value */

/* CLKSRCCTL2 bitfield */
#define CLK_CFG_REGS_CLKSRCCTL2_SPICCLKSEL_Pos     (18U)                                                                                                   /*!< SPICCLKSEL Position 18 */
#define CLK_CFG_REGS_CLKSRCCTL2_SPICCLKSEL_Msk     (0x1U << CLK_CFG_REGS_CLKSRCCTL2_SPICCLKSEL_Pos)                                                        /*!< SPICCLKSEL Mask 0x00040000 */
#define CLK_CFG_REGS_CLKSRCCTL2_SPICCLKSEL_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_CLKSRCCTL2_SPICCLKSEL_Pos) & CLK_CFG_REGS_CLKSRCCTL2_SPICCLKSEL_Msk)   /*!< SPICCLKSEL Set Value */
#define CLK_CFG_REGS_CLKSRCCTL2_SPICCLKSEL_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_CLKSRCCTL2_SPICCLKSEL_Msk) >> CLK_CFG_REGS_CLKSRCCTL2_SPICCLKSEL_Pos)   /*!< SPICCLKSEL Get Value */

#define CLK_CFG_REGS_CLKSRCCTL2_SPIBCLKSEL_Pos     (17U)                                                                                                   /*!< SPIBCLKSEL Position 17 */
#define CLK_CFG_REGS_CLKSRCCTL2_SPIBCLKSEL_Msk     (0x1U << CLK_CFG_REGS_CLKSRCCTL2_SPIBCLKSEL_Pos)                                                        /*!< SPIBCLKSEL Mask 0x00020000 */
#define CLK_CFG_REGS_CLKSRCCTL2_SPIBCLKSEL_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_CLKSRCCTL2_SPIBCLKSEL_Pos) & CLK_CFG_REGS_CLKSRCCTL2_SPIBCLKSEL_Msk)   /*!< SPIBCLKSEL Set Value */
#define CLK_CFG_REGS_CLKSRCCTL2_SPIBCLKSEL_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_CLKSRCCTL2_SPIBCLKSEL_Msk) >> CLK_CFG_REGS_CLKSRCCTL2_SPIBCLKSEL_Pos)   /*!< SPIBCLKSEL Get Value */

#define CLK_CFG_REGS_CLKSRCCTL2_SPIACLKSEL_Pos     (16U)                                                                                                   /*!< SPIACLKSEL Position 16 */
#define CLK_CFG_REGS_CLKSRCCTL2_SPIACLKSEL_Msk     (0x1U << CLK_CFG_REGS_CLKSRCCTL2_SPIACLKSEL_Pos)                                                        /*!< SPIACLKSEL Mask 0x00010000 */
#define CLK_CFG_REGS_CLKSRCCTL2_SPIACLKSEL_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_CLKSRCCTL2_SPIACLKSEL_Pos) & CLK_CFG_REGS_CLKSRCCTL2_SPIACLKSEL_Msk)   /*!< SPIACLKSEL Set Value */
#define CLK_CFG_REGS_CLKSRCCTL2_SPIACLKSEL_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_CLKSRCCTL2_SPIACLKSEL_Msk) >> CLK_CFG_REGS_CLKSRCCTL2_SPIACLKSEL_Pos)   /*!< SPIACLKSEL Get Value */

#define CLK_CFG_REGS_CLKSRCCTL2_CANCBCLKSEL_Pos     (6U)                                                                                                      /*!< CANCBCLKSEL Position 6 */
#define CLK_CFG_REGS_CLKSRCCTL2_CANCBCLKSEL_Msk     (0x3U << CLK_CFG_REGS_CLKSRCCTL2_CANCBCLKSEL_Pos)                                                         /*!< CANCBCLKSEL Mask 0x000000C0 */
#define CLK_CFG_REGS_CLKSRCCTL2_CANCBCLKSEL_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_CLKSRCCTL2_CANCBCLKSEL_Pos) & CLK_CFG_REGS_CLKSRCCTL2_CANCBCLKSEL_Msk)   /*!< CANCBCLKSEL Set Value */
#define CLK_CFG_REGS_CLKSRCCTL2_CANCBCLKSEL_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_CLKSRCCTL2_CANCBCLKSEL_Msk) >> CLK_CFG_REGS_CLKSRCCTL2_CANCBCLKSEL_Pos)   /*!< CANCBCLKSEL Get Value */

#define CLK_CFG_REGS_CLKSRCCTL2_CANBBCLKSEL_Pos     (4U)                                                                                                      /*!< CANBBCLKSEL Position 4 */
#define CLK_CFG_REGS_CLKSRCCTL2_CANBBCLKSEL_Msk     (0x3U << CLK_CFG_REGS_CLKSRCCTL2_CANBBCLKSEL_Pos)                                                         /*!< CANBBCLKSEL Mask 0x00000030 */
#define CLK_CFG_REGS_CLKSRCCTL2_CANBBCLKSEL_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_CLKSRCCTL2_CANBBCLKSEL_Pos) & CLK_CFG_REGS_CLKSRCCTL2_CANBBCLKSEL_Msk)   /*!< CANBBCLKSEL Set Value */
#define CLK_CFG_REGS_CLKSRCCTL2_CANBBCLKSEL_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_CLKSRCCTL2_CANBBCLKSEL_Msk) >> CLK_CFG_REGS_CLKSRCCTL2_CANBBCLKSEL_Pos)   /*!< CANBBCLKSEL Get Value */

#define CLK_CFG_REGS_CLKSRCCTL2_CANABCLKSEL_Pos     (2U)                                                                                                      /*!< CANABCLKSEL Position 2 */
#define CLK_CFG_REGS_CLKSRCCTL2_CANABCLKSEL_Msk     (0x3U << CLK_CFG_REGS_CLKSRCCTL2_CANABCLKSEL_Pos)                                                         /*!< CANABCLKSEL Mask 0x0000000C */
#define CLK_CFG_REGS_CLKSRCCTL2_CANABCLKSEL_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_CLKSRCCTL2_CANABCLKSEL_Pos) & CLK_CFG_REGS_CLKSRCCTL2_CANABCLKSEL_Msk)   /*!< CANABCLKSEL Set Value */
#define CLK_CFG_REGS_CLKSRCCTL2_CANABCLKSEL_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_CLKSRCCTL2_CANABCLKSEL_Msk) >> CLK_CFG_REGS_CLKSRCCTL2_CANABCLKSEL_Pos)   /*!< CANABCLKSEL Get Value */

#define CLK_CFG_REGS_CLKSRCCTL2_AUXOSCCLKSRCSEL_Pos     (0U)                                                                                                              /*!< AUXOSCCLKSRCSEL Position 0 */
#define CLK_CFG_REGS_CLKSRCCTL2_AUXOSCCLKSRCSEL_Msk     (0x3U << CLK_CFG_REGS_CLKSRCCTL2_AUXOSCCLKSRCSEL_Pos)                                                             /*!< AUXOSCCLKSRCSEL Mask 0x00000003 */
#define CLK_CFG_REGS_CLKSRCCTL2_AUXOSCCLKSRCSEL_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_CLKSRCCTL2_AUXOSCCLKSRCSEL_Pos) & CLK_CFG_REGS_CLKSRCCTL2_AUXOSCCLKSRCSEL_Msk)   /*!< AUXOSCCLKSRCSEL Set Value */
#define CLK_CFG_REGS_CLKSRCCTL2_AUXOSCCLKSRCSEL_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_CLKSRCCTL2_AUXOSCCLKSRCSEL_Msk) >> CLK_CFG_REGS_CLKSRCCTL2_AUXOSCCLKSRCSEL_Pos)   /*!< AUXOSCCLKSRCSEL Get Value */

/* CLKSRCCTL3 bitfield */
#define CLK_CFG_REGS_CLKSRCCTL3_XCLKOUTSEL_Pos     (0U)                                                                                                    /*!< XCLKOUTSEL Position 0 */
#define CLK_CFG_REGS_CLKSRCCTL3_XCLKOUTSEL_Msk     (0x7U << CLK_CFG_REGS_CLKSRCCTL3_XCLKOUTSEL_Pos)                                                        /*!< XCLKOUTSEL Mask 0x00000007 */
#define CLK_CFG_REGS_CLKSRCCTL3_XCLKOUTSEL_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_CLKSRCCTL3_XCLKOUTSEL_Pos) & CLK_CFG_REGS_CLKSRCCTL3_XCLKOUTSEL_Msk)   /*!< XCLKOUTSEL Set Value */
#define CLK_CFG_REGS_CLKSRCCTL3_XCLKOUTSEL_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_CLKSRCCTL3_XCLKOUTSEL_Msk) >> CLK_CFG_REGS_CLKSRCCTL3_XCLKOUTSEL_Pos)   /*!< XCLKOUTSEL Get Value */

/* SYSPLLCTL1 bitfield */
#define CLK_CFG_REGS_SYSPLLCTL1_LDO_RSTB_Pos     (27U)                                                                                               /*!< LDO_RSTB Position 27 */
#define CLK_CFG_REGS_SYSPLLCTL1_LDO_RSTB_Msk     (0x1U << CLK_CFG_REGS_SYSPLLCTL1_LDO_RSTB_Pos)                                                      /*!< LDO_RSTB Mask 0x08000000 */
#define CLK_CFG_REGS_SYSPLLCTL1_LDO_RSTB_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_SYSPLLCTL1_LDO_RSTB_Pos) & CLK_CFG_REGS_SYSPLLCTL1_LDO_RSTB_Msk)   /*!< LDO_RSTB Set Value */
#define CLK_CFG_REGS_SYSPLLCTL1_LDO_RSTB_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_SYSPLLCTL1_LDO_RSTB_Msk) >> CLK_CFG_REGS_SYSPLLCTL1_LDO_RSTB_Pos)   /*!< LDO_RSTB Get Value */

#define CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_SEL_Pos     (26U)                                                                                                         /*!< PLL_CKREF_SEL Position 26 */
#define CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_SEL_Msk     (0x1U << CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_SEL_Pos)                                                           /*!< PLL_CKREF_SEL Mask 0x04000000 */
#define CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_SEL_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_SEL_Pos) & CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_SEL_Msk)   /*!< PLL_CKREF_SEL Set Value */
#define CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_SEL_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_SEL_Msk) >> CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_SEL_Pos)   /*!< PLL_CKREF_SEL Get Value */

#define CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_DIV_Pos     (23U)                                                                                                         /*!< PLL_CKREF_DIV Position 23 */
#define CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_DIV_Msk     (0x7U << CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_DIV_Pos)                                                           /*!< PLL_CKREF_DIV Mask 0x03800000 */
#define CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_DIV_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_DIV_Pos) & CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_DIV_Msk)   /*!< PLL_CKREF_DIV Set Value */
#define CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_DIV_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_DIV_Msk) >> CLK_CFG_REGS_SYSPLLCTL1_PLL_CKREF_DIV_Pos)   /*!< PLL_CKREF_DIV Get Value */

#define CLK_CFG_REGS_SYSPLLCTL1_PLL_VCO_BAND_Pos     (22U)                                                                                                       /*!< PLL_VCO_BAND Position 22 */
#define CLK_CFG_REGS_SYSPLLCTL1_PLL_VCO_BAND_Msk     (0x1U << CLK_CFG_REGS_SYSPLLCTL1_PLL_VCO_BAND_Pos)                                                          /*!< PLL_VCO_BAND Mask 0x00400000 */
#define CLK_CFG_REGS_SYSPLLCTL1_PLL_VCO_BAND_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_SYSPLLCTL1_PLL_VCO_BAND_Pos) & CLK_CFG_REGS_SYSPLLCTL1_PLL_VCO_BAND_Msk)   /*!< PLL_VCO_BAND Set Value */
#define CLK_CFG_REGS_SYSPLLCTL1_PLL_VCO_BAND_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_SYSPLLCTL1_PLL_VCO_BAND_Msk) >> CLK_CFG_REGS_SYSPLLCTL1_PLL_VCO_BAND_Pos)   /*!< PLL_VCO_BAND Get Value */

#define CLK_CFG_REGS_SYSPLLCTL1_PLL_ICP_Pos     (19U)                                                                                             /*!< PLL_ICP Position 19 */
#define CLK_CFG_REGS_SYSPLLCTL1_PLL_ICP_Msk     (0x7U << CLK_CFG_REGS_SYSPLLCTL1_PLL_ICP_Pos)                                                     /*!< PLL_ICP Mask 0x00380000 */
#define CLK_CFG_REGS_SYSPLLCTL1_PLL_ICP_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_SYSPLLCTL1_PLL_ICP_Pos) & CLK_CFG_REGS_SYSPLLCTL1_PLL_ICP_Msk)   /*!< PLL_ICP Set Value */
#define CLK_CFG_REGS_SYSPLLCTL1_PLL_ICP_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_SYSPLLCTL1_PLL_ICP_Msk) >> CLK_CFG_REGS_SYSPLLCTL1_PLL_ICP_Pos)   /*!< PLL_ICP Get Value */

#define CLK_CFG_REGS_SYSPLLCTL1_PLL_LPF_Pos     (17U)                                                                                             /*!< PLL_LPF Position 17 */
#define CLK_CFG_REGS_SYSPLLCTL1_PLL_LPF_Msk     (0x3U << CLK_CFG_REGS_SYSPLLCTL1_PLL_LPF_Pos)                                                     /*!< PLL_LPF Mask 0x00060000 */
#define CLK_CFG_REGS_SYSPLLCTL1_PLL_LPF_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_SYSPLLCTL1_PLL_LPF_Pos) & CLK_CFG_REGS_SYSPLLCTL1_PLL_LPF_Msk)   /*!< PLL_LPF Set Value */
#define CLK_CFG_REGS_SYSPLLCTL1_PLL_LPF_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_SYSPLLCTL1_PLL_LPF_Msk) >> CLK_CFG_REGS_SYSPLLCTL1_PLL_LPF_Pos)   /*!< PLL_LPF Get Value */

#define CLK_CFG_REGS_SYSPLLCTL1_PLL_LDO_EN_Pos     (16U)                                                                                                   /*!< PLL_LDO_EN Position 16 */
#define CLK_CFG_REGS_SYSPLLCTL1_PLL_LDO_EN_Msk     (0x1U << CLK_CFG_REGS_SYSPLLCTL1_PLL_LDO_EN_Pos)                                                        /*!< PLL_LDO_EN Mask 0x00010000 */
#define CLK_CFG_REGS_SYSPLLCTL1_PLL_LDO_EN_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_SYSPLLCTL1_PLL_LDO_EN_Pos) & CLK_CFG_REGS_SYSPLLCTL1_PLL_LDO_EN_Msk)   /*!< PLL_LDO_EN Set Value */
#define CLK_CFG_REGS_SYSPLLCTL1_PLL_LDO_EN_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_SYSPLLCTL1_PLL_LDO_EN_Msk) >> CLK_CFG_REGS_SYSPLLCTL1_PLL_LDO_EN_Pos)   /*!< PLL_LDO_EN Get Value */

#define CLK_CFG_REGS_SYSPLLCTL1_PLLCLKEN_Pos     (1U)                                                                                                /*!< PLLCLKEN Position 1 */
#define CLK_CFG_REGS_SYSPLLCTL1_PLLCLKEN_Msk     (0x1U << CLK_CFG_REGS_SYSPLLCTL1_PLLCLKEN_Pos)                                                      /*!< PLLCLKEN Mask 0x00000002 */
#define CLK_CFG_REGS_SYSPLLCTL1_PLLCLKEN_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_SYSPLLCTL1_PLLCLKEN_Pos) & CLK_CFG_REGS_SYSPLLCTL1_PLLCLKEN_Msk)   /*!< PLLCLKEN Set Value */
#define CLK_CFG_REGS_SYSPLLCTL1_PLLCLKEN_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_SYSPLLCTL1_PLLCLKEN_Msk) >> CLK_CFG_REGS_SYSPLLCTL1_PLLCLKEN_Pos)   /*!< PLLCLKEN Get Value */

#define CLK_CFG_REGS_SYSPLLCTL1_PLLEN_Pos     (0U)                                                                                          /*!< PLLEN Position 0 */
#define CLK_CFG_REGS_SYSPLLCTL1_PLLEN_Msk     (0x1U << CLK_CFG_REGS_SYSPLLCTL1_PLLEN_Pos)                                                   /*!< PLLEN Mask 0x00000001 */
#define CLK_CFG_REGS_SYSPLLCTL1_PLLEN_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_SYSPLLCTL1_PLLEN_Pos) & CLK_CFG_REGS_SYSPLLCTL1_PLLEN_Msk)   /*!< PLLEN Set Value */
#define CLK_CFG_REGS_SYSPLLCTL1_PLLEN_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_SYSPLLCTL1_PLLEN_Msk) >> CLK_CFG_REGS_SYSPLLCTL1_PLLEN_Pos)   /*!< PLLEN Get Value */

/* SYSPLLMULT bitfield */
#define CLK_CFG_REGS_SYSPLLMULT_ORDER_Pos     (31U)                                                                                         /*!< ORDER Position 31 */
#define CLK_CFG_REGS_SYSPLLMULT_ORDER_Msk     (0x1U << CLK_CFG_REGS_SYSPLLMULT_ORDER_Pos)                                                   /*!< ORDER Mask 0x80000000 */
#define CLK_CFG_REGS_SYSPLLMULT_ORDER_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_SYSPLLMULT_ORDER_Pos) & CLK_CFG_REGS_SYSPLLMULT_ORDER_Msk)   /*!< ORDER Set Value */
#define CLK_CFG_REGS_SYSPLLMULT_ORDER_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_SYSPLLMULT_ORDER_Msk) >> CLK_CFG_REGS_SYSPLLMULT_ORDER_Pos)   /*!< ORDER Get Value */

#define CLK_CFG_REGS_SYSPLLMULT_BYPASS_PI_Pos     (30U)                                                                                                 /*!< BYPASS_PI Position 30 */
#define CLK_CFG_REGS_SYSPLLMULT_BYPASS_PI_Msk     (0x1U << CLK_CFG_REGS_SYSPLLMULT_BYPASS_PI_Pos)                                                       /*!< BYPASS_PI Mask 0x40000000 */
#define CLK_CFG_REGS_SYSPLLMULT_BYPASS_PI_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_SYSPLLMULT_BYPASS_PI_Pos) & CLK_CFG_REGS_SYSPLLMULT_BYPASS_PI_Msk)   /*!< BYPASS_PI Set Value */
#define CLK_CFG_REGS_SYSPLLMULT_BYPASS_PI_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_SYSPLLMULT_BYPASS_PI_Msk) >> CLK_CFG_REGS_SYSPLLMULT_BYPASS_PI_Pos)   /*!< BYPASS_PI Get Value */

#define CLK_CFG_REGS_SYSPLLMULT_REG_DOT_FCW_Pos     (19U)                                                                                                     /*!< REG_DOT_FCW Position 19 */
#define CLK_CFG_REGS_SYSPLLMULT_REG_DOT_FCW_Msk     (0x7U << CLK_CFG_REGS_SYSPLLMULT_REG_DOT_FCW_Pos)                                                         /*!< REG_DOT_FCW Mask 0x00380000 */
#define CLK_CFG_REGS_SYSPLLMULT_REG_DOT_FCW_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_SYSPLLMULT_REG_DOT_FCW_Pos) & CLK_CFG_REGS_SYSPLLMULT_REG_DOT_FCW_Msk)   /*!< REG_DOT_FCW Set Value */
#define CLK_CFG_REGS_SYSPLLMULT_REG_DOT_FCW_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_SYSPLLMULT_REG_DOT_FCW_Msk) >> CLK_CFG_REGS_SYSPLLMULT_REG_DOT_FCW_Pos)   /*!< REG_DOT_FCW Get Value */

#define CLK_CFG_REGS_SYSPLLMULT_FCW_SSC_Pos     (0U)                                                                                              /*!< FCW_SSC Position 0 */
#define CLK_CFG_REGS_SYSPLLMULT_FCW_SSC_Msk     (0x7ffffU << CLK_CFG_REGS_SYSPLLMULT_FCW_SSC_Pos)                                                 /*!< FCW_SSC Mask 0x0007FFFF */
#define CLK_CFG_REGS_SYSPLLMULT_FCW_SSC_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_SYSPLLMULT_FCW_SSC_Pos) & CLK_CFG_REGS_SYSPLLMULT_FCW_SSC_Msk)   /*!< FCW_SSC Set Value */
#define CLK_CFG_REGS_SYSPLLMULT_FCW_SSC_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_SYSPLLMULT_FCW_SSC_Msk) >> CLK_CFG_REGS_SYSPLLMULT_FCW_SSC_Pos)   /*!< FCW_SSC Get Value */

/* SYSPLLSTS bitfield */
#define CLK_CFG_REGS_SYSPLLSTS_LOCKS_Pos     (0U)                                                                                        /*!< LOCKS Position 0 */
#define CLK_CFG_REGS_SYSPLLSTS_LOCKS_Msk     (0x1U << CLK_CFG_REGS_SYSPLLSTS_LOCKS_Pos)                                                  /*!< LOCKS Mask 0x00000001 */
#define CLK_CFG_REGS_SYSPLLSTS_LOCKS_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_SYSPLLSTS_LOCKS_Pos) & CLK_CFG_REGS_SYSPLLSTS_LOCKS_Msk)   /*!< LOCKS Set Value */
#define CLK_CFG_REGS_SYSPLLSTS_LOCKS_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_SYSPLLSTS_LOCKS_Msk) >> CLK_CFG_REGS_SYSPLLSTS_LOCKS_Pos)   /*!< LOCKS Get Value */

/* AUXPLLCTL1 bitfield */
#define CLK_CFG_REGS_AUXPLLCTL1_LDO_RSTB_Pos     (27U)                                                                                               /*!< LDO_RSTB Position 27 */
#define CLK_CFG_REGS_AUXPLLCTL1_LDO_RSTB_Msk     (0x1U << CLK_CFG_REGS_AUXPLLCTL1_LDO_RSTB_Pos)                                                      /*!< LDO_RSTB Mask 0x08000000 */
#define CLK_CFG_REGS_AUXPLLCTL1_LDO_RSTB_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_AUXPLLCTL1_LDO_RSTB_Pos) & CLK_CFG_REGS_AUXPLLCTL1_LDO_RSTB_Msk)   /*!< LDO_RSTB Set Value */
#define CLK_CFG_REGS_AUXPLLCTL1_LDO_RSTB_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_AUXPLLCTL1_LDO_RSTB_Msk) >> CLK_CFG_REGS_AUXPLLCTL1_LDO_RSTB_Pos)   /*!< LDO_RSTB Get Value */

#define CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_SEL_Pos     (26U)                                                                                                         /*!< PLL_CKREF_SEL Position 26 */
#define CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_SEL_Msk     (0x1U << CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_SEL_Pos)                                                           /*!< PLL_CKREF_SEL Mask 0x04000000 */
#define CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_SEL_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_SEL_Pos) & CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_SEL_Msk)   /*!< PLL_CKREF_SEL Set Value */
#define CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_SEL_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_SEL_Msk) >> CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_SEL_Pos)   /*!< PLL_CKREF_SEL Get Value */

#define CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_DIV_Pos     (23U)                                                                                                         /*!< PLL_CKREF_DIV Position 23 */
#define CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_DIV_Msk     (0x7U << CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_DIV_Pos)                                                           /*!< PLL_CKREF_DIV Mask 0x03800000 */
#define CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_DIV_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_DIV_Pos) & CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_DIV_Msk)   /*!< PLL_CKREF_DIV Set Value */
#define CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_DIV_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_DIV_Msk) >> CLK_CFG_REGS_AUXPLLCTL1_PLL_CKREF_DIV_Pos)   /*!< PLL_CKREF_DIV Get Value */

#define CLK_CFG_REGS_AUXPLLCTL1_PLL_VCO_BAND_Pos     (22U)                                                                                                       /*!< PLL_VCO_BAND Position 22 */
#define CLK_CFG_REGS_AUXPLLCTL1_PLL_VCO_BAND_Msk     (0x1U << CLK_CFG_REGS_AUXPLLCTL1_PLL_VCO_BAND_Pos)                                                          /*!< PLL_VCO_BAND Mask 0x00400000 */
#define CLK_CFG_REGS_AUXPLLCTL1_PLL_VCO_BAND_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_AUXPLLCTL1_PLL_VCO_BAND_Pos) & CLK_CFG_REGS_AUXPLLCTL1_PLL_VCO_BAND_Msk)   /*!< PLL_VCO_BAND Set Value */
#define CLK_CFG_REGS_AUXPLLCTL1_PLL_VCO_BAND_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_AUXPLLCTL1_PLL_VCO_BAND_Msk) >> CLK_CFG_REGS_AUXPLLCTL1_PLL_VCO_BAND_Pos)   /*!< PLL_VCO_BAND Get Value */

#define CLK_CFG_REGS_AUXPLLCTL1_PLL_ICP_Pos     (19U)                                                                                             /*!< PLL_ICP Position 19 */
#define CLK_CFG_REGS_AUXPLLCTL1_PLL_ICP_Msk     (0x7U << CLK_CFG_REGS_AUXPLLCTL1_PLL_ICP_Pos)                                                     /*!< PLL_ICP Mask 0x00380000 */
#define CLK_CFG_REGS_AUXPLLCTL1_PLL_ICP_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_AUXPLLCTL1_PLL_ICP_Pos) & CLK_CFG_REGS_AUXPLLCTL1_PLL_ICP_Msk)   /*!< PLL_ICP Set Value */
#define CLK_CFG_REGS_AUXPLLCTL1_PLL_ICP_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_AUXPLLCTL1_PLL_ICP_Msk) >> CLK_CFG_REGS_AUXPLLCTL1_PLL_ICP_Pos)   /*!< PLL_ICP Get Value */

#define CLK_CFG_REGS_AUXPLLCTL1_PLL_LPF_Pos     (17U)                                                                                             /*!< PLL_LPF Position 17 */
#define CLK_CFG_REGS_AUXPLLCTL1_PLL_LPF_Msk     (0x3U << CLK_CFG_REGS_AUXPLLCTL1_PLL_LPF_Pos)                                                     /*!< PLL_LPF Mask 0x00060000 */
#define CLK_CFG_REGS_AUXPLLCTL1_PLL_LPF_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_AUXPLLCTL1_PLL_LPF_Pos) & CLK_CFG_REGS_AUXPLLCTL1_PLL_LPF_Msk)   /*!< PLL_LPF Set Value */
#define CLK_CFG_REGS_AUXPLLCTL1_PLL_LPF_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_AUXPLLCTL1_PLL_LPF_Msk) >> CLK_CFG_REGS_AUXPLLCTL1_PLL_LPF_Pos)   /*!< PLL_LPF Get Value */

#define CLK_CFG_REGS_AUXPLLCTL1_PLL_LDO_EN_Pos     (16U)                                                                                                   /*!< PLL_LDO_EN Position 16 */
#define CLK_CFG_REGS_AUXPLLCTL1_PLL_LDO_EN_Msk     (0x1U << CLK_CFG_REGS_AUXPLLCTL1_PLL_LDO_EN_Pos)                                                        /*!< PLL_LDO_EN Mask 0x00010000 */
#define CLK_CFG_REGS_AUXPLLCTL1_PLL_LDO_EN_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_AUXPLLCTL1_PLL_LDO_EN_Pos) & CLK_CFG_REGS_AUXPLLCTL1_PLL_LDO_EN_Msk)   /*!< PLL_LDO_EN Set Value */
#define CLK_CFG_REGS_AUXPLLCTL1_PLL_LDO_EN_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_AUXPLLCTL1_PLL_LDO_EN_Msk) >> CLK_CFG_REGS_AUXPLLCTL1_PLL_LDO_EN_Pos)   /*!< PLL_LDO_EN Get Value */

#define CLK_CFG_REGS_AUXPLLCTL1_PLLCLKEN_Pos     (1U)                                                                                                /*!< PLLCLKEN Position 1 */
#define CLK_CFG_REGS_AUXPLLCTL1_PLLCLKEN_Msk     (0x1U << CLK_CFG_REGS_AUXPLLCTL1_PLLCLKEN_Pos)                                                      /*!< PLLCLKEN Mask 0x00000002 */
#define CLK_CFG_REGS_AUXPLLCTL1_PLLCLKEN_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_AUXPLLCTL1_PLLCLKEN_Pos) & CLK_CFG_REGS_AUXPLLCTL1_PLLCLKEN_Msk)   /*!< PLLCLKEN Set Value */
#define CLK_CFG_REGS_AUXPLLCTL1_PLLCLKEN_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_AUXPLLCTL1_PLLCLKEN_Msk) >> CLK_CFG_REGS_AUXPLLCTL1_PLLCLKEN_Pos)   /*!< PLLCLKEN Get Value */

#define CLK_CFG_REGS_AUXPLLCTL1_PLLEN_Pos     (0U)                                                                                          /*!< PLLEN Position 0 */
#define CLK_CFG_REGS_AUXPLLCTL1_PLLEN_Msk     (0x1U << CLK_CFG_REGS_AUXPLLCTL1_PLLEN_Pos)                                                   /*!< PLLEN Mask 0x00000001 */
#define CLK_CFG_REGS_AUXPLLCTL1_PLLEN_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_AUXPLLCTL1_PLLEN_Pos) & CLK_CFG_REGS_AUXPLLCTL1_PLLEN_Msk)   /*!< PLLEN Set Value */
#define CLK_CFG_REGS_AUXPLLCTL1_PLLEN_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_AUXPLLCTL1_PLLEN_Msk) >> CLK_CFG_REGS_AUXPLLCTL1_PLLEN_Pos)   /*!< PLLEN Get Value */

/* AUXPLLMULT bitfield */
#define CLK_CFG_REGS_AUXPLLMULT_ORDER_Pos     (31U)                                                                                         /*!< ORDER Position 31 */
#define CLK_CFG_REGS_AUXPLLMULT_ORDER_Msk     (0x1U << CLK_CFG_REGS_AUXPLLMULT_ORDER_Pos)                                                   /*!< ORDER Mask 0x80000000 */
#define CLK_CFG_REGS_AUXPLLMULT_ORDER_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_AUXPLLMULT_ORDER_Pos) & CLK_CFG_REGS_AUXPLLMULT_ORDER_Msk)   /*!< ORDER Set Value */
#define CLK_CFG_REGS_AUXPLLMULT_ORDER_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_AUXPLLMULT_ORDER_Msk) >> CLK_CFG_REGS_AUXPLLMULT_ORDER_Pos)   /*!< ORDER Get Value */

#define CLK_CFG_REGS_AUXPLLMULT_BYPASS_PI_Pos     (30U)                                                                                                 /*!< BYPASS_PI Position 30 */
#define CLK_CFG_REGS_AUXPLLMULT_BYPASS_PI_Msk     (0x1U << CLK_CFG_REGS_AUXPLLMULT_BYPASS_PI_Pos)                                                       /*!< BYPASS_PI Mask 0x40000000 */
#define CLK_CFG_REGS_AUXPLLMULT_BYPASS_PI_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_AUXPLLMULT_BYPASS_PI_Pos) & CLK_CFG_REGS_AUXPLLMULT_BYPASS_PI_Msk)   /*!< BYPASS_PI Set Value */
#define CLK_CFG_REGS_AUXPLLMULT_BYPASS_PI_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_AUXPLLMULT_BYPASS_PI_Msk) >> CLK_CFG_REGS_AUXPLLMULT_BYPASS_PI_Pos)   /*!< BYPASS_PI Get Value */

#define CLK_CFG_REGS_AUXPLLMULT_REG_DOT_FCW_Pos     (19U)                                                                                                     /*!< REG_DOT_FCW Position 19 */
#define CLK_CFG_REGS_AUXPLLMULT_REG_DOT_FCW_Msk     (0x7U << CLK_CFG_REGS_AUXPLLMULT_REG_DOT_FCW_Pos)                                                         /*!< REG_DOT_FCW Mask 0x00380000 */
#define CLK_CFG_REGS_AUXPLLMULT_REG_DOT_FCW_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_AUXPLLMULT_REG_DOT_FCW_Pos) & CLK_CFG_REGS_AUXPLLMULT_REG_DOT_FCW_Msk)   /*!< REG_DOT_FCW Set Value */
#define CLK_CFG_REGS_AUXPLLMULT_REG_DOT_FCW_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_AUXPLLMULT_REG_DOT_FCW_Msk) >> CLK_CFG_REGS_AUXPLLMULT_REG_DOT_FCW_Pos)   /*!< REG_DOT_FCW Get Value */

#define CLK_CFG_REGS_AUXPLLMULT_FCW_SSC_Pos     (0U)                                                                                              /*!< FCW_SSC Position 0 */
#define CLK_CFG_REGS_AUXPLLMULT_FCW_SSC_Msk     (0x7ffffU << CLK_CFG_REGS_AUXPLLMULT_FCW_SSC_Pos)                                                 /*!< FCW_SSC Mask 0x0007FFFF */
#define CLK_CFG_REGS_AUXPLLMULT_FCW_SSC_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_AUXPLLMULT_FCW_SSC_Pos) & CLK_CFG_REGS_AUXPLLMULT_FCW_SSC_Msk)   /*!< FCW_SSC Set Value */
#define CLK_CFG_REGS_AUXPLLMULT_FCW_SSC_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_AUXPLLMULT_FCW_SSC_Msk) >> CLK_CFG_REGS_AUXPLLMULT_FCW_SSC_Pos)   /*!< FCW_SSC Get Value */

/* AUXPLLSTS bitfield */
#define CLK_CFG_REGS_AUXPLLSTS_LOCKS_Pos     (0U)                                                                                        /*!< LOCKS Position 0 */
#define CLK_CFG_REGS_AUXPLLSTS_LOCKS_Msk     (0x1U << CLK_CFG_REGS_AUXPLLSTS_LOCKS_Pos)                                                  /*!< LOCKS Mask 0x00000001 */
#define CLK_CFG_REGS_AUXPLLSTS_LOCKS_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_AUXPLLSTS_LOCKS_Pos) & CLK_CFG_REGS_AUXPLLSTS_LOCKS_Msk)   /*!< LOCKS Set Value */
#define CLK_CFG_REGS_AUXPLLSTS_LOCKS_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_AUXPLLSTS_LOCKS_Msk) >> CLK_CFG_REGS_AUXPLLSTS_LOCKS_Pos)   /*!< LOCKS Get Value */

/* SYSCLKDIVSEL bitfield */
#define CLK_CFG_REGS_SYSCLKDIVSEL_PLLSYSCLKDIV_Pos     (0U)                                                                                                            /*!< PLLSYSCLKDIV Position 0 */
#define CLK_CFG_REGS_SYSCLKDIVSEL_PLLSYSCLKDIV_Msk     (0x3fU << CLK_CFG_REGS_SYSCLKDIVSEL_PLLSYSCLKDIV_Pos)                                                           /*!< PLLSYSCLKDIV Mask 0x0000003F */
#define CLK_CFG_REGS_SYSCLKDIVSEL_PLLSYSCLKDIV_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_SYSCLKDIVSEL_PLLSYSCLKDIV_Pos) & CLK_CFG_REGS_SYSCLKDIVSEL_PLLSYSCLKDIV_Msk)   /*!< PLLSYSCLKDIV Set Value */
#define CLK_CFG_REGS_SYSCLKDIVSEL_PLLSYSCLKDIV_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_SYSCLKDIVSEL_PLLSYSCLKDIV_Msk) >> CLK_CFG_REGS_SYSCLKDIVSEL_PLLSYSCLKDIV_Pos)   /*!< PLLSYSCLKDIV Get Value */

/* AUXCLKDIVSEL bitfield */
#define CLK_CFG_REGS_AUXCLKDIVSEL_AUXPLLDIV_Pos     (0U)                                                                                                      /*!< AUXPLLDIV Position 0 */
#define CLK_CFG_REGS_AUXCLKDIVSEL_AUXPLLDIV_Msk     (0x3U << CLK_CFG_REGS_AUXCLKDIVSEL_AUXPLLDIV_Pos)                                                         /*!< AUXPLLDIV Mask 0x00000003 */
#define CLK_CFG_REGS_AUXCLKDIVSEL_AUXPLLDIV_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_AUXCLKDIVSEL_AUXPLLDIV_Pos) & CLK_CFG_REGS_AUXCLKDIVSEL_AUXPLLDIV_Msk)   /*!< AUXPLLDIV Set Value */
#define CLK_CFG_REGS_AUXCLKDIVSEL_AUXPLLDIV_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_AUXCLKDIVSEL_AUXPLLDIV_Msk) >> CLK_CFG_REGS_AUXCLKDIVSEL_AUXPLLDIV_Pos)   /*!< AUXPLLDIV Get Value */

/* PERCLKDIVSEL bitfield */
#define CLK_CFG_REGS_PERCLKDIVSEL_EMIF1CLKDIV_Pos     (4U)                                                                                                          /*!< EMIF1CLKDIV Position 4 */
#define CLK_CFG_REGS_PERCLKDIVSEL_EMIF1CLKDIV_Msk     (0x1U << CLK_CFG_REGS_PERCLKDIVSEL_EMIF1CLKDIV_Pos)                                                           /*!< EMIF1CLKDIV Mask 0x00000010 */
#define CLK_CFG_REGS_PERCLKDIVSEL_EMIF1CLKDIV_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_PERCLKDIVSEL_EMIF1CLKDIV_Pos) & CLK_CFG_REGS_PERCLKDIVSEL_EMIF1CLKDIV_Msk)   /*!< EMIF1CLKDIV Set Value */
#define CLK_CFG_REGS_PERCLKDIVSEL_EMIF1CLKDIV_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_PERCLKDIVSEL_EMIF1CLKDIV_Msk) >> CLK_CFG_REGS_PERCLKDIVSEL_EMIF1CLKDIV_Pos)   /*!< EMIF1CLKDIV Get Value */

/* XCLKOUTDIVSEL bitfield */
#define CLK_CFG_REGS_XCLKOUTDIVSEL_XCLKOUTDIV_Pos     (0U)                                                                                                          /*!< XCLKOUTDIV Position 0 */
#define CLK_CFG_REGS_XCLKOUTDIVSEL_XCLKOUTDIV_Msk     (0x3U << CLK_CFG_REGS_XCLKOUTDIVSEL_XCLKOUTDIV_Pos)                                                           /*!< XCLKOUTDIV Mask 0x00000003 */
#define CLK_CFG_REGS_XCLKOUTDIVSEL_XCLKOUTDIV_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_XCLKOUTDIVSEL_XCLKOUTDIV_Pos) & CLK_CFG_REGS_XCLKOUTDIVSEL_XCLKOUTDIV_Msk)   /*!< XCLKOUTDIV Set Value */
#define CLK_CFG_REGS_XCLKOUTDIVSEL_XCLKOUTDIV_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_XCLKOUTDIVSEL_XCLKOUTDIV_Msk) >> CLK_CFG_REGS_XCLKOUTDIVSEL_XCLKOUTDIV_Pos)   /*!< XCLKOUTDIV Get Value */

/* MCDCR bitfield */
#define CLK_CFG_REGS_MCDCR_OSCOFF_Pos     (3U)                                                                                  /*!< OSCOFF Position 3 */
#define CLK_CFG_REGS_MCDCR_OSCOFF_Msk     (0x1U << CLK_CFG_REGS_MCDCR_OSCOFF_Pos)                                               /*!< OSCOFF Mask 0x00000008 */
#define CLK_CFG_REGS_MCDCR_OSCOFF_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_MCDCR_OSCOFF_Pos) & CLK_CFG_REGS_MCDCR_OSCOFF_Msk)   /*!< OSCOFF Set Value */
#define CLK_CFG_REGS_MCDCR_OSCOFF_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_MCDCR_OSCOFF_Msk) >> CLK_CFG_REGS_MCDCR_OSCOFF_Pos)   /*!< OSCOFF Get Value */

#define CLK_CFG_REGS_MCDCR_MCLKOFF_Pos     (2U)                                                                                    /*!< MCLKOFF Position 2 */
#define CLK_CFG_REGS_MCDCR_MCLKOFF_Msk     (0x1U << CLK_CFG_REGS_MCDCR_MCLKOFF_Pos)                                                /*!< MCLKOFF Mask 0x00000004 */
#define CLK_CFG_REGS_MCDCR_MCLKOFF_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_MCDCR_MCLKOFF_Pos) & CLK_CFG_REGS_MCDCR_MCLKOFF_Msk)   /*!< MCLKOFF Set Value */
#define CLK_CFG_REGS_MCDCR_MCLKOFF_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_MCDCR_MCLKOFF_Msk) >> CLK_CFG_REGS_MCDCR_MCLKOFF_Pos)   /*!< MCLKOFF Get Value */

#define CLK_CFG_REGS_MCDCR_MCLKCLR_Pos     (1U)                                                                                    /*!< MCLKCLR Position 1 */
#define CLK_CFG_REGS_MCDCR_MCLKCLR_Msk     (0x1U << CLK_CFG_REGS_MCDCR_MCLKCLR_Pos)                                                /*!< MCLKCLR Mask 0x00000002 */
#define CLK_CFG_REGS_MCDCR_MCLKCLR_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_MCDCR_MCLKCLR_Pos) & CLK_CFG_REGS_MCDCR_MCLKCLR_Msk)   /*!< MCLKCLR Set Value */
#define CLK_CFG_REGS_MCDCR_MCLKCLR_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_MCDCR_MCLKCLR_Msk) >> CLK_CFG_REGS_MCDCR_MCLKCLR_Pos)   /*!< MCLKCLR Get Value */

#define CLK_CFG_REGS_MCDCR_MCLKSTS_Pos     (0U)                                                                                    /*!< MCLKSTS Position 0 */
#define CLK_CFG_REGS_MCDCR_MCLKSTS_Msk     (0x1U << CLK_CFG_REGS_MCDCR_MCLKSTS_Pos)                                                /*!< MCLKSTS Mask 0x00000001 */
#define CLK_CFG_REGS_MCDCR_MCLKSTS_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_MCDCR_MCLKSTS_Pos) & CLK_CFG_REGS_MCDCR_MCLKSTS_Msk)   /*!< MCLKSTS Set Value */
#define CLK_CFG_REGS_MCDCR_MCLKSTS_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_MCDCR_MCLKSTS_Msk) >> CLK_CFG_REGS_MCDCR_MCLKSTS_Pos)   /*!< MCLKSTS Get Value */

/* X1CNT bitfield */
#define CLK_CFG_REGS_X1CNT_X1CNT_Pos     (0U)                                                                                /*!< X1CNT Position 0 */
#define CLK_CFG_REGS_X1CNT_X1CNT_Msk     (0x3ffU << CLK_CFG_REGS_X1CNT_X1CNT_Pos)                                            /*!< X1CNT Mask 0x000003FF */
#define CLK_CFG_REGS_X1CNT_X1CNT_Set(x)  (((uint32_t) (x) << CLK_CFG_REGS_X1CNT_X1CNT_Pos) & CLK_CFG_REGS_X1CNT_X1CNT_Msk)   /*!< X1CNT Set Value */
#define CLK_CFG_REGS_X1CNT_X1CNT_Get(x)  (((uint32_t) (x) & CLK_CFG_REGS_X1CNT_X1CNT_Msk) >> CLK_CFG_REGS_X1CNT_X1CNT_Pos)   /*!< X1CNT Get Value */

/* CPUSYSLOCK1 bitfield */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR17_Pos     (24U)                                                                                                 /*!< PCLKCR17 Position 24 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR17_Msk     (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR17_Pos)                                                       /*!< PCLKCR17 Mask 0x01000000 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR17_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR17_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR17_Msk)   /*!< PCLKCR17 Set Value */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR17_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR17_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR17_Pos)   /*!< PCLKCR17 Get Value */

#define CPU_SYS_REGS_CPUSYSLOCK1_GPIOLPMSEL1_Pos     (23U)                                                                                                       /*!< GPIOLPMSEL1 Position 23 */
#define CPU_SYS_REGS_CPUSYSLOCK1_GPIOLPMSEL1_Msk     (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_GPIOLPMSEL1_Pos)                                                          /*!< GPIOLPMSEL1 Mask 0x00800000 */
#define CPU_SYS_REGS_CPUSYSLOCK1_GPIOLPMSEL1_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_GPIOLPMSEL1_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_GPIOLPMSEL1_Msk)   /*!< GPIOLPMSEL1 Set Value */
#define CPU_SYS_REGS_CPUSYSLOCK1_GPIOLPMSEL1_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_GPIOLPMSEL1_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_GPIOLPMSEL1_Pos)   /*!< GPIOLPMSEL1 Get Value */

#define CPU_SYS_REGS_CPUSYSLOCK1_GPIOLPMSEL0_Pos     (22U)                                                                                                       /*!< GPIOLPMSEL0 Position 22 */
#define CPU_SYS_REGS_CPUSYSLOCK1_GPIOLPMSEL0_Msk     (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_GPIOLPMSEL0_Pos)                                                          /*!< GPIOLPMSEL0 Mask 0x00400000 */
#define CPU_SYS_REGS_CPUSYSLOCK1_GPIOLPMSEL0_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_GPIOLPMSEL0_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_GPIOLPMSEL0_Msk)   /*!< GPIOLPMSEL0 Set Value */
#define CPU_SYS_REGS_CPUSYSLOCK1_GPIOLPMSEL0_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_GPIOLPMSEL0_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_GPIOLPMSEL0_Pos)   /*!< GPIOLPMSEL0 Get Value */

#define CPU_SYS_REGS_CPUSYSLOCK1_LPMCR_Pos     (21U)                                                                                           /*!< LPMCR Position 21 */
#define CPU_SYS_REGS_CPUSYSLOCK1_LPMCR_Msk     (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_LPMCR_Pos)                                                    /*!< LPMCR Mask 0x00200000 */
#define CPU_SYS_REGS_CPUSYSLOCK1_LPMCR_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_LPMCR_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_LPMCR_Msk)   /*!< LPMCR Set Value */
#define CPU_SYS_REGS_CPUSYSLOCK1_LPMCR_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_LPMCR_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_LPMCR_Pos)   /*!< LPMCR Get Value */

#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR16_Pos     (19U)                                                                                                 /*!< PCLKCR16 Position 19 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR16_Msk     (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR16_Pos)                                                       /*!< PCLKCR16 Mask 0x00080000 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR16_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR16_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR16_Msk)   /*!< PCLKCR16 Set Value */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR16_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR16_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR16_Pos)   /*!< PCLKCR16 Get Value */

#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR15_Pos     (18U)                                                                                                 /*!< PCLKCR15 Position 18 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR15_Msk     (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR15_Pos)                                                       /*!< PCLKCR15 Mask 0x00040000 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR15_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR15_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR15_Msk)   /*!< PCLKCR15 Set Value */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR15_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR15_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR15_Pos)   /*!< PCLKCR15 Get Value */

#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR14_Pos     (17U)                                                                                                 /*!< PCLKCR14 Position 17 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR14_Msk     (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR14_Pos)                                                       /*!< PCLKCR14 Mask 0x00020000 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR14_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR14_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR14_Msk)   /*!< PCLKCR14 Set Value */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR14_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR14_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR14_Pos)   /*!< PCLKCR14 Get Value */

#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR13_Pos     (16U)                                                                                                 /*!< PCLKCR13 Position 16 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR13_Msk     (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR13_Pos)                                                       /*!< PCLKCR13 Mask 0x00010000 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR13_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR13_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR13_Msk)   /*!< PCLKCR13 Set Value */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR13_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR13_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR13_Pos)   /*!< PCLKCR13 Get Value */

#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR12_Pos     (15U)                                                                                                 /*!< PCLKCR12 Position 15 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR12_Msk     (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR12_Pos)                                                       /*!< PCLKCR12 Mask 0x00008000 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR12_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR12_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR12_Msk)   /*!< PCLKCR12 Set Value */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR12_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR12_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR12_Pos)   /*!< PCLKCR12 Get Value */

#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR11_Pos     (14U)                                                                                                 /*!< PCLKCR11 Position 14 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR11_Msk     (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR11_Pos)                                                       /*!< PCLKCR11 Mask 0x00004000 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR11_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR11_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR11_Msk)   /*!< PCLKCR11 Set Value */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR11_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR11_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR11_Pos)   /*!< PCLKCR11 Get Value */

#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR10_Pos     (13U)                                                                                                 /*!< PCLKCR10 Position 13 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR10_Msk     (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR10_Pos)                                                       /*!< PCLKCR10 Mask 0x00002000 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR10_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR10_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR10_Msk)   /*!< PCLKCR10 Set Value */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR10_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR10_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR10_Pos)   /*!< PCLKCR10 Get Value */

#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR9_Pos     (12U)                                                                                               /*!< PCLKCR9 Position 12 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR9_Msk     (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR9_Pos)                                                      /*!< PCLKCR9 Mask 0x00001000 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR9_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR9_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR9_Msk)   /*!< PCLKCR9 Set Value */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR9_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR9_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR9_Pos)   /*!< PCLKCR9 Get Value */

#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR8_Pos     (11U)                                                                                               /*!< PCLKCR8 Position 11 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR8_Msk     (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR8_Pos)                                                      /*!< PCLKCR8 Mask 0x00000800 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR8_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR8_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR8_Msk)   /*!< PCLKCR8 Set Value */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR8_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR8_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR8_Pos)   /*!< PCLKCR8 Get Value */

#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR7_Pos     (10U)                                                                                               /*!< PCLKCR7 Position 10 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR7_Msk     (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR7_Pos)                                                      /*!< PCLKCR7 Mask 0x00000400 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR7_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR7_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR7_Msk)   /*!< PCLKCR7 Set Value */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR7_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR7_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR7_Pos)   /*!< PCLKCR7 Get Value */

#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR6_Pos     (9U)                                                                                                /*!< PCLKCR6 Position 9 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR6_Msk     (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR6_Pos)                                                      /*!< PCLKCR6 Mask 0x00000200 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR6_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR6_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR6_Msk)   /*!< PCLKCR6 Set Value */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR6_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR6_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR6_Pos)   /*!< PCLKCR6 Get Value */

#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR5_Pos     (8U)                                                                                                /*!< PCLKCR5 Position 8 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR5_Msk     (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR5_Pos)                                                      /*!< PCLKCR5 Mask 0x00000100 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR5_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR5_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR5_Msk)   /*!< PCLKCR5 Set Value */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR5_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR5_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR5_Pos)   /*!< PCLKCR5 Get Value */

#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR4_Pos     (7U)                                                                                                /*!< PCLKCR4 Position 7 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR4_Msk     (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR4_Pos)                                                      /*!< PCLKCR4 Mask 0x00000080 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR4_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR4_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR4_Msk)   /*!< PCLKCR4 Set Value */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR4_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR4_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR4_Pos)   /*!< PCLKCR4 Get Value */

#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR3_Pos     (6U)                                                                                                /*!< PCLKCR3 Position 6 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR3_Msk     (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR3_Pos)                                                      /*!< PCLKCR3 Mask 0x00000040 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR3_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR3_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR3_Msk)   /*!< PCLKCR3 Set Value */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR3_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR3_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR3_Pos)   /*!< PCLKCR3 Get Value */

#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR2_Pos     (5U)                                                                                                /*!< PCLKCR2 Position 5 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR2_Msk     (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR2_Pos)                                                      /*!< PCLKCR2 Mask 0x00000020 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR2_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR2_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR2_Msk)   /*!< PCLKCR2 Set Value */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR2_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR2_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR2_Pos)   /*!< PCLKCR2 Get Value */

#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR1_Pos     (4U)                                                                                                /*!< PCLKCR1 Position 4 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR1_Msk     (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR1_Pos)                                                      /*!< PCLKCR1 Mask 0x00000010 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR1_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR1_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR1_Msk)   /*!< PCLKCR1 Set Value */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR1_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR1_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR1_Pos)   /*!< PCLKCR1 Get Value */

#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR0_Pos     (3U)                                                                                                /*!< PCLKCR0 Position 3 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR0_Msk     (0x1U << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR0_Pos)                                                      /*!< PCLKCR0 Mask 0x00000008 */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR0_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR0_Pos) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR0_Msk)   /*!< PCLKCR0 Set Value */
#define CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR0_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR0_Msk) >> CPU_SYS_REGS_CPUSYSLOCK1_PCLKCR0_Pos)   /*!< PCLKCR0 Get Value */

/* PCLKCR0 bitfield */
#define CPU_SYS_REGS_PCLKCR0_GTBCLKSYNC_Pos     (19U)                                                                                             /*!< GTBCLKSYNC Position 19 */
#define CPU_SYS_REGS_PCLKCR0_GTBCLKSYNC_Msk     (0x1U << CPU_SYS_REGS_PCLKCR0_GTBCLKSYNC_Pos)                                                     /*!< GTBCLKSYNC Mask 0x00080000 */
#define CPU_SYS_REGS_PCLKCR0_GTBCLKSYNC_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR0_GTBCLKSYNC_Pos) & CPU_SYS_REGS_PCLKCR0_GTBCLKSYNC_Msk)   /*!< GTBCLKSYNC Set Value */
#define CPU_SYS_REGS_PCLKCR0_GTBCLKSYNC_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR0_GTBCLKSYNC_Msk) >> CPU_SYS_REGS_PCLKCR0_GTBCLKSYNC_Pos)   /*!< GTBCLKSYNC Get Value */

#define CPU_SYS_REGS_PCLKCR0_TBCLKSYNC_Pos     (18U)                                                                                           /*!< TBCLKSYNC Position 18 */
#define CPU_SYS_REGS_PCLKCR0_TBCLKSYNC_Msk     (0x1U << CPU_SYS_REGS_PCLKCR0_TBCLKSYNC_Pos)                                                    /*!< TBCLKSYNC Mask 0x00040000 */
#define CPU_SYS_REGS_PCLKCR0_TBCLKSYNC_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR0_TBCLKSYNC_Pos) & CPU_SYS_REGS_PCLKCR0_TBCLKSYNC_Msk)   /*!< TBCLKSYNC Set Value */
#define CPU_SYS_REGS_PCLKCR0_TBCLKSYNC_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR0_TBCLKSYNC_Msk) >> CPU_SYS_REGS_PCLKCR0_TBCLKSYNC_Pos)   /*!< TBCLKSYNC Get Value */

#define CPU_SYS_REGS_PCLKCR0_DWCPUTIMER2_Pos     (10U)                                                                                               /*!< DWCPUTIMER2 Position 10 */
#define CPU_SYS_REGS_PCLKCR0_DWCPUTIMER2_Msk     (0x1U << CPU_SYS_REGS_PCLKCR0_DWCPUTIMER2_Pos)                                                      /*!< DWCPUTIMER2 Mask 0x00000400 */
#define CPU_SYS_REGS_PCLKCR0_DWCPUTIMER2_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR0_DWCPUTIMER2_Pos) & CPU_SYS_REGS_PCLKCR0_DWCPUTIMER2_Msk)   /*!< DWCPUTIMER2 Set Value */
#define CPU_SYS_REGS_PCLKCR0_DWCPUTIMER2_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR0_DWCPUTIMER2_Msk) >> CPU_SYS_REGS_PCLKCR0_DWCPUTIMER2_Pos)   /*!< DWCPUTIMER2 Get Value */

#define CPU_SYS_REGS_PCLKCR0_DWCPUTIMER1_Pos     (9U)                                                                                                /*!< DWCPUTIMER1 Position 9 */
#define CPU_SYS_REGS_PCLKCR0_DWCPUTIMER1_Msk     (0x1U << CPU_SYS_REGS_PCLKCR0_DWCPUTIMER1_Pos)                                                      /*!< DWCPUTIMER1 Mask 0x00000200 */
#define CPU_SYS_REGS_PCLKCR0_DWCPUTIMER1_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR0_DWCPUTIMER1_Pos) & CPU_SYS_REGS_PCLKCR0_DWCPUTIMER1_Msk)   /*!< DWCPUTIMER1 Set Value */
#define CPU_SYS_REGS_PCLKCR0_DWCPUTIMER1_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR0_DWCPUTIMER1_Msk) >> CPU_SYS_REGS_PCLKCR0_DWCPUTIMER1_Pos)   /*!< DWCPUTIMER1 Get Value */

#define CPU_SYS_REGS_PCLKCR0_DWCPUTIMER0_Pos     (8U)                                                                                                /*!< DWCPUTIMER0 Position 8 */
#define CPU_SYS_REGS_PCLKCR0_DWCPUTIMER0_Msk     (0x1U << CPU_SYS_REGS_PCLKCR0_DWCPUTIMER0_Pos)                                                      /*!< DWCPUTIMER0 Mask 0x00000100 */
#define CPU_SYS_REGS_PCLKCR0_DWCPUTIMER0_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR0_DWCPUTIMER0_Pos) & CPU_SYS_REGS_PCLKCR0_DWCPUTIMER0_Msk)   /*!< DWCPUTIMER0 Set Value */
#define CPU_SYS_REGS_PCLKCR0_DWCPUTIMER0_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR0_DWCPUTIMER0_Msk) >> CPU_SYS_REGS_PCLKCR0_DWCPUTIMER0_Pos)   /*!< DWCPUTIMER0 Get Value */

#define CPU_SYS_REGS_PCLKCR0_CPUTIMER2_Pos     (5U)                                                                                            /*!< CPUTIMER2 Position 5 */
#define CPU_SYS_REGS_PCLKCR0_CPUTIMER2_Msk     (0x1U << CPU_SYS_REGS_PCLKCR0_CPUTIMER2_Pos)                                                    /*!< CPUTIMER2 Mask 0x00000020 */
#define CPU_SYS_REGS_PCLKCR0_CPUTIMER2_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR0_CPUTIMER2_Pos) & CPU_SYS_REGS_PCLKCR0_CPUTIMER2_Msk)   /*!< CPUTIMER2 Set Value */
#define CPU_SYS_REGS_PCLKCR0_CPUTIMER2_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR0_CPUTIMER2_Msk) >> CPU_SYS_REGS_PCLKCR0_CPUTIMER2_Pos)   /*!< CPUTIMER2 Get Value */

#define CPU_SYS_REGS_PCLKCR0_CPUTIMER1_Pos     (4U)                                                                                            /*!< CPUTIMER1 Position 4 */
#define CPU_SYS_REGS_PCLKCR0_CPUTIMER1_Msk     (0x1U << CPU_SYS_REGS_PCLKCR0_CPUTIMER1_Pos)                                                    /*!< CPUTIMER1 Mask 0x00000010 */
#define CPU_SYS_REGS_PCLKCR0_CPUTIMER1_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR0_CPUTIMER1_Pos) & CPU_SYS_REGS_PCLKCR0_CPUTIMER1_Msk)   /*!< CPUTIMER1 Set Value */
#define CPU_SYS_REGS_PCLKCR0_CPUTIMER1_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR0_CPUTIMER1_Msk) >> CPU_SYS_REGS_PCLKCR0_CPUTIMER1_Pos)   /*!< CPUTIMER1 Get Value */

#define CPU_SYS_REGS_PCLKCR0_CPUTIMER0_Pos     (3U)                                                                                            /*!< CPUTIMER0 Position 3 */
#define CPU_SYS_REGS_PCLKCR0_CPUTIMER0_Msk     (0x1U << CPU_SYS_REGS_PCLKCR0_CPUTIMER0_Pos)                                                    /*!< CPUTIMER0 Mask 0x00000008 */
#define CPU_SYS_REGS_PCLKCR0_CPUTIMER0_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR0_CPUTIMER0_Pos) & CPU_SYS_REGS_PCLKCR0_CPUTIMER0_Msk)   /*!< CPUTIMER0 Set Value */
#define CPU_SYS_REGS_PCLKCR0_CPUTIMER0_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR0_CPUTIMER0_Msk) >> CPU_SYS_REGS_PCLKCR0_CPUTIMER0_Pos)   /*!< CPUTIMER0 Get Value */

#define CPU_SYS_REGS_PCLKCR0_DMA_Pos     (2U)                                                                                /*!< DMA Position 2 */
#define CPU_SYS_REGS_PCLKCR0_DMA_Msk     (0x1U << CPU_SYS_REGS_PCLKCR0_DMA_Pos)                                              /*!< DMA Mask 0x00000004 */
#define CPU_SYS_REGS_PCLKCR0_DMA_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR0_DMA_Pos) & CPU_SYS_REGS_PCLKCR0_DMA_Msk)   /*!< DMA Set Value */
#define CPU_SYS_REGS_PCLKCR0_DMA_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR0_DMA_Msk) >> CPU_SYS_REGS_PCLKCR0_DMA_Pos)   /*!< DMA Get Value */

/* PCLKCR2 bitfield */
#define CPU_SYS_REGS_PCLKCR2_EPWM12_Pos     (11U)                                                                                     /*!< EPWM12 Position 11 */
#define CPU_SYS_REGS_PCLKCR2_EPWM12_Msk     (0x1U << CPU_SYS_REGS_PCLKCR2_EPWM12_Pos)                                                 /*!< EPWM12 Mask 0x00000800 */
#define CPU_SYS_REGS_PCLKCR2_EPWM12_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR2_EPWM12_Pos) & CPU_SYS_REGS_PCLKCR2_EPWM12_Msk)   /*!< EPWM12 Set Value */
#define CPU_SYS_REGS_PCLKCR2_EPWM12_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR2_EPWM12_Msk) >> CPU_SYS_REGS_PCLKCR2_EPWM12_Pos)   /*!< EPWM12 Get Value */

#define CPU_SYS_REGS_PCLKCR2_EPWM11_Pos     (10U)                                                                                     /*!< EPWM11 Position 10 */
#define CPU_SYS_REGS_PCLKCR2_EPWM11_Msk     (0x1U << CPU_SYS_REGS_PCLKCR2_EPWM11_Pos)                                                 /*!< EPWM11 Mask 0x00000400 */
#define CPU_SYS_REGS_PCLKCR2_EPWM11_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR2_EPWM11_Pos) & CPU_SYS_REGS_PCLKCR2_EPWM11_Msk)   /*!< EPWM11 Set Value */
#define CPU_SYS_REGS_PCLKCR2_EPWM11_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR2_EPWM11_Msk) >> CPU_SYS_REGS_PCLKCR2_EPWM11_Pos)   /*!< EPWM11 Get Value */

#define CPU_SYS_REGS_PCLKCR2_EPWM10_Pos     (9U)                                                                                      /*!< EPWM10 Position 9 */
#define CPU_SYS_REGS_PCLKCR2_EPWM10_Msk     (0x1U << CPU_SYS_REGS_PCLKCR2_EPWM10_Pos)                                                 /*!< EPWM10 Mask 0x00000200 */
#define CPU_SYS_REGS_PCLKCR2_EPWM10_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR2_EPWM10_Pos) & CPU_SYS_REGS_PCLKCR2_EPWM10_Msk)   /*!< EPWM10 Set Value */
#define CPU_SYS_REGS_PCLKCR2_EPWM10_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR2_EPWM10_Msk) >> CPU_SYS_REGS_PCLKCR2_EPWM10_Pos)   /*!< EPWM10 Get Value */

#define CPU_SYS_REGS_PCLKCR2_EPWM9_Pos     (8U)                                                                                    /*!< EPWM9 Position 8 */
#define CPU_SYS_REGS_PCLKCR2_EPWM9_Msk     (0x1U << CPU_SYS_REGS_PCLKCR2_EPWM9_Pos)                                                /*!< EPWM9 Mask 0x00000100 */
#define CPU_SYS_REGS_PCLKCR2_EPWM9_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR2_EPWM9_Pos) & CPU_SYS_REGS_PCLKCR2_EPWM9_Msk)   /*!< EPWM9 Set Value */
#define CPU_SYS_REGS_PCLKCR2_EPWM9_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR2_EPWM9_Msk) >> CPU_SYS_REGS_PCLKCR2_EPWM9_Pos)   /*!< EPWM9 Get Value */

#define CPU_SYS_REGS_PCLKCR2_EPWM8_Pos     (7U)                                                                                    /*!< EPWM8 Position 7 */
#define CPU_SYS_REGS_PCLKCR2_EPWM8_Msk     (0x1U << CPU_SYS_REGS_PCLKCR2_EPWM8_Pos)                                                /*!< EPWM8 Mask 0x00000080 */
#define CPU_SYS_REGS_PCLKCR2_EPWM8_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR2_EPWM8_Pos) & CPU_SYS_REGS_PCLKCR2_EPWM8_Msk)   /*!< EPWM8 Set Value */
#define CPU_SYS_REGS_PCLKCR2_EPWM8_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR2_EPWM8_Msk) >> CPU_SYS_REGS_PCLKCR2_EPWM8_Pos)   /*!< EPWM8 Get Value */

#define CPU_SYS_REGS_PCLKCR2_EPWM7_Pos     (6U)                                                                                    /*!< EPWM7 Position 6 */
#define CPU_SYS_REGS_PCLKCR2_EPWM7_Msk     (0x1U << CPU_SYS_REGS_PCLKCR2_EPWM7_Pos)                                                /*!< EPWM7 Mask 0x00000040 */
#define CPU_SYS_REGS_PCLKCR2_EPWM7_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR2_EPWM7_Pos) & CPU_SYS_REGS_PCLKCR2_EPWM7_Msk)   /*!< EPWM7 Set Value */
#define CPU_SYS_REGS_PCLKCR2_EPWM7_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR2_EPWM7_Msk) >> CPU_SYS_REGS_PCLKCR2_EPWM7_Pos)   /*!< EPWM7 Get Value */

#define CPU_SYS_REGS_PCLKCR2_EPWM6_Pos     (5U)                                                                                    /*!< EPWM6 Position 5 */
#define CPU_SYS_REGS_PCLKCR2_EPWM6_Msk     (0x1U << CPU_SYS_REGS_PCLKCR2_EPWM6_Pos)                                                /*!< EPWM6 Mask 0x00000020 */
#define CPU_SYS_REGS_PCLKCR2_EPWM6_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR2_EPWM6_Pos) & CPU_SYS_REGS_PCLKCR2_EPWM6_Msk)   /*!< EPWM6 Set Value */
#define CPU_SYS_REGS_PCLKCR2_EPWM6_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR2_EPWM6_Msk) >> CPU_SYS_REGS_PCLKCR2_EPWM6_Pos)   /*!< EPWM6 Get Value */

#define CPU_SYS_REGS_PCLKCR2_EPWM5_Pos     (4U)                                                                                    /*!< EPWM5 Position 4 */
#define CPU_SYS_REGS_PCLKCR2_EPWM5_Msk     (0x1U << CPU_SYS_REGS_PCLKCR2_EPWM5_Pos)                                                /*!< EPWM5 Mask 0x00000010 */
#define CPU_SYS_REGS_PCLKCR2_EPWM5_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR2_EPWM5_Pos) & CPU_SYS_REGS_PCLKCR2_EPWM5_Msk)   /*!< EPWM5 Set Value */
#define CPU_SYS_REGS_PCLKCR2_EPWM5_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR2_EPWM5_Msk) >> CPU_SYS_REGS_PCLKCR2_EPWM5_Pos)   /*!< EPWM5 Get Value */

#define CPU_SYS_REGS_PCLKCR2_EPWM4_Pos     (3U)                                                                                    /*!< EPWM4 Position 3 */
#define CPU_SYS_REGS_PCLKCR2_EPWM4_Msk     (0x1U << CPU_SYS_REGS_PCLKCR2_EPWM4_Pos)                                                /*!< EPWM4 Mask 0x00000008 */
#define CPU_SYS_REGS_PCLKCR2_EPWM4_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR2_EPWM4_Pos) & CPU_SYS_REGS_PCLKCR2_EPWM4_Msk)   /*!< EPWM4 Set Value */
#define CPU_SYS_REGS_PCLKCR2_EPWM4_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR2_EPWM4_Msk) >> CPU_SYS_REGS_PCLKCR2_EPWM4_Pos)   /*!< EPWM4 Get Value */

#define CPU_SYS_REGS_PCLKCR2_EPWM3_Pos     (2U)                                                                                    /*!< EPWM3 Position 2 */
#define CPU_SYS_REGS_PCLKCR2_EPWM3_Msk     (0x1U << CPU_SYS_REGS_PCLKCR2_EPWM3_Pos)                                                /*!< EPWM3 Mask 0x00000004 */
#define CPU_SYS_REGS_PCLKCR2_EPWM3_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR2_EPWM3_Pos) & CPU_SYS_REGS_PCLKCR2_EPWM3_Msk)   /*!< EPWM3 Set Value */
#define CPU_SYS_REGS_PCLKCR2_EPWM3_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR2_EPWM3_Msk) >> CPU_SYS_REGS_PCLKCR2_EPWM3_Pos)   /*!< EPWM3 Get Value */

#define CPU_SYS_REGS_PCLKCR2_EPWM2_Pos     (1U)                                                                                    /*!< EPWM2 Position 1 */
#define CPU_SYS_REGS_PCLKCR2_EPWM2_Msk     (0x1U << CPU_SYS_REGS_PCLKCR2_EPWM2_Pos)                                                /*!< EPWM2 Mask 0x00000002 */
#define CPU_SYS_REGS_PCLKCR2_EPWM2_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR2_EPWM2_Pos) & CPU_SYS_REGS_PCLKCR2_EPWM2_Msk)   /*!< EPWM2 Set Value */
#define CPU_SYS_REGS_PCLKCR2_EPWM2_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR2_EPWM2_Msk) >> CPU_SYS_REGS_PCLKCR2_EPWM2_Pos)   /*!< EPWM2 Get Value */

#define CPU_SYS_REGS_PCLKCR2_EPWM1_Pos     (0U)                                                                                    /*!< EPWM1 Position 0 */
#define CPU_SYS_REGS_PCLKCR2_EPWM1_Msk     (0x1U << CPU_SYS_REGS_PCLKCR2_EPWM1_Pos)                                                /*!< EPWM1 Mask 0x00000001 */
#define CPU_SYS_REGS_PCLKCR2_EPWM1_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR2_EPWM1_Pos) & CPU_SYS_REGS_PCLKCR2_EPWM1_Msk)   /*!< EPWM1 Set Value */
#define CPU_SYS_REGS_PCLKCR2_EPWM1_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR2_EPWM1_Msk) >> CPU_SYS_REGS_PCLKCR2_EPWM1_Pos)   /*!< EPWM1 Get Value */

/* PCLKCR3 bitfield */
#define CPU_SYS_REGS_PCLKCR3_ECAP6_Pos     (5U)                                                                                    /*!< ECAP6 Position 5 */
#define CPU_SYS_REGS_PCLKCR3_ECAP6_Msk     (0x1U << CPU_SYS_REGS_PCLKCR3_ECAP6_Pos)                                                /*!< ECAP6 Mask 0x00000020 */
#define CPU_SYS_REGS_PCLKCR3_ECAP6_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR3_ECAP6_Pos) & CPU_SYS_REGS_PCLKCR3_ECAP6_Msk)   /*!< ECAP6 Set Value */
#define CPU_SYS_REGS_PCLKCR3_ECAP6_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR3_ECAP6_Msk) >> CPU_SYS_REGS_PCLKCR3_ECAP6_Pos)   /*!< ECAP6 Get Value */

#define CPU_SYS_REGS_PCLKCR3_ECAP5_Pos     (4U)                                                                                    /*!< ECAP5 Position 4 */
#define CPU_SYS_REGS_PCLKCR3_ECAP5_Msk     (0x1U << CPU_SYS_REGS_PCLKCR3_ECAP5_Pos)                                                /*!< ECAP5 Mask 0x00000010 */
#define CPU_SYS_REGS_PCLKCR3_ECAP5_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR3_ECAP5_Pos) & CPU_SYS_REGS_PCLKCR3_ECAP5_Msk)   /*!< ECAP5 Set Value */
#define CPU_SYS_REGS_PCLKCR3_ECAP5_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR3_ECAP5_Msk) >> CPU_SYS_REGS_PCLKCR3_ECAP5_Pos)   /*!< ECAP5 Get Value */

#define CPU_SYS_REGS_PCLKCR3_ECAP4_Pos     (3U)                                                                                    /*!< ECAP4 Position 3 */
#define CPU_SYS_REGS_PCLKCR3_ECAP4_Msk     (0x1U << CPU_SYS_REGS_PCLKCR3_ECAP4_Pos)                                                /*!< ECAP4 Mask 0x00000008 */
#define CPU_SYS_REGS_PCLKCR3_ECAP4_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR3_ECAP4_Pos) & CPU_SYS_REGS_PCLKCR3_ECAP4_Msk)   /*!< ECAP4 Set Value */
#define CPU_SYS_REGS_PCLKCR3_ECAP4_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR3_ECAP4_Msk) >> CPU_SYS_REGS_PCLKCR3_ECAP4_Pos)   /*!< ECAP4 Get Value */

#define CPU_SYS_REGS_PCLKCR3_ECAP3_Pos     (2U)                                                                                    /*!< ECAP3 Position 2 */
#define CPU_SYS_REGS_PCLKCR3_ECAP3_Msk     (0x1U << CPU_SYS_REGS_PCLKCR3_ECAP3_Pos)                                                /*!< ECAP3 Mask 0x00000004 */
#define CPU_SYS_REGS_PCLKCR3_ECAP3_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR3_ECAP3_Pos) & CPU_SYS_REGS_PCLKCR3_ECAP3_Msk)   /*!< ECAP3 Set Value */
#define CPU_SYS_REGS_PCLKCR3_ECAP3_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR3_ECAP3_Msk) >> CPU_SYS_REGS_PCLKCR3_ECAP3_Pos)   /*!< ECAP3 Get Value */

#define CPU_SYS_REGS_PCLKCR3_ECAP2_Pos     (1U)                                                                                    /*!< ECAP2 Position 1 */
#define CPU_SYS_REGS_PCLKCR3_ECAP2_Msk     (0x1U << CPU_SYS_REGS_PCLKCR3_ECAP2_Pos)                                                /*!< ECAP2 Mask 0x00000002 */
#define CPU_SYS_REGS_PCLKCR3_ECAP2_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR3_ECAP2_Pos) & CPU_SYS_REGS_PCLKCR3_ECAP2_Msk)   /*!< ECAP2 Set Value */
#define CPU_SYS_REGS_PCLKCR3_ECAP2_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR3_ECAP2_Msk) >> CPU_SYS_REGS_PCLKCR3_ECAP2_Pos)   /*!< ECAP2 Get Value */

#define CPU_SYS_REGS_PCLKCR3_ECAP1_Pos     (0U)                                                                                    /*!< ECAP1 Position 0 */
#define CPU_SYS_REGS_PCLKCR3_ECAP1_Msk     (0x1U << CPU_SYS_REGS_PCLKCR3_ECAP1_Pos)                                                /*!< ECAP1 Mask 0x00000001 */
#define CPU_SYS_REGS_PCLKCR3_ECAP1_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR3_ECAP1_Pos) & CPU_SYS_REGS_PCLKCR3_ECAP1_Msk)   /*!< ECAP1 Set Value */
#define CPU_SYS_REGS_PCLKCR3_ECAP1_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR3_ECAP1_Msk) >> CPU_SYS_REGS_PCLKCR3_ECAP1_Pos)   /*!< ECAP1 Get Value */

/* PCLKCR4 bitfield */
#define CPU_SYS_REGS_PCLKCR4_EQEP3_Pos     (2U)                                                                                    /*!< EQEP3 Position 2 */
#define CPU_SYS_REGS_PCLKCR4_EQEP3_Msk     (0x1U << CPU_SYS_REGS_PCLKCR4_EQEP3_Pos)                                                /*!< EQEP3 Mask 0x00000004 */
#define CPU_SYS_REGS_PCLKCR4_EQEP3_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR4_EQEP3_Pos) & CPU_SYS_REGS_PCLKCR4_EQEP3_Msk)   /*!< EQEP3 Set Value */
#define CPU_SYS_REGS_PCLKCR4_EQEP3_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR4_EQEP3_Msk) >> CPU_SYS_REGS_PCLKCR4_EQEP3_Pos)   /*!< EQEP3 Get Value */

#define CPU_SYS_REGS_PCLKCR4_EQEP2_Pos     (1U)                                                                                    /*!< EQEP2 Position 1 */
#define CPU_SYS_REGS_PCLKCR4_EQEP2_Msk     (0x1U << CPU_SYS_REGS_PCLKCR4_EQEP2_Pos)                                                /*!< EQEP2 Mask 0x00000002 */
#define CPU_SYS_REGS_PCLKCR4_EQEP2_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR4_EQEP2_Pos) & CPU_SYS_REGS_PCLKCR4_EQEP2_Msk)   /*!< EQEP2 Set Value */
#define CPU_SYS_REGS_PCLKCR4_EQEP2_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR4_EQEP2_Msk) >> CPU_SYS_REGS_PCLKCR4_EQEP2_Pos)   /*!< EQEP2 Get Value */

#define CPU_SYS_REGS_PCLKCR4_EQEP1_Pos     (0U)                                                                                    /*!< EQEP1 Position 0 */
#define CPU_SYS_REGS_PCLKCR4_EQEP1_Msk     (0x1U << CPU_SYS_REGS_PCLKCR4_EQEP1_Pos)                                                /*!< EQEP1 Mask 0x00000001 */
#define CPU_SYS_REGS_PCLKCR4_EQEP1_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR4_EQEP1_Pos) & CPU_SYS_REGS_PCLKCR4_EQEP1_Msk)   /*!< EQEP1 Set Value */
#define CPU_SYS_REGS_PCLKCR4_EQEP1_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR4_EQEP1_Msk) >> CPU_SYS_REGS_PCLKCR4_EQEP1_Pos)   /*!< EQEP1 Get Value */

/* PCLKCR6 bitfield */
#define CPU_SYS_REGS_PCLKCR6_SD2_Pos     (1U)                                                                                /*!< SD2 Position 1 */
#define CPU_SYS_REGS_PCLKCR6_SD2_Msk     (0x1U << CPU_SYS_REGS_PCLKCR6_SD2_Pos)                                              /*!< SD2 Mask 0x00000002 */
#define CPU_SYS_REGS_PCLKCR6_SD2_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR6_SD2_Pos) & CPU_SYS_REGS_PCLKCR6_SD2_Msk)   /*!< SD2 Set Value */
#define CPU_SYS_REGS_PCLKCR6_SD2_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR6_SD2_Msk) >> CPU_SYS_REGS_PCLKCR6_SD2_Pos)   /*!< SD2 Get Value */

#define CPU_SYS_REGS_PCLKCR6_SD1_Pos     (0U)                                                                                /*!< SD1 Position 0 */
#define CPU_SYS_REGS_PCLKCR6_SD1_Msk     (0x1U << CPU_SYS_REGS_PCLKCR6_SD1_Pos)                                              /*!< SD1 Mask 0x00000001 */
#define CPU_SYS_REGS_PCLKCR6_SD1_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR6_SD1_Pos) & CPU_SYS_REGS_PCLKCR6_SD1_Msk)   /*!< SD1 Set Value */
#define CPU_SYS_REGS_PCLKCR6_SD1_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR6_SD1_Msk) >> CPU_SYS_REGS_PCLKCR6_SD1_Pos)   /*!< SD1 Get Value */

/* PCLKCR7 bitfield */
#define CPU_SYS_REGS_PCLKCR7_SCI_D_Pos     (3U)                                                                                    /*!< SCI_D Position 3 */
#define CPU_SYS_REGS_PCLKCR7_SCI_D_Msk     (0x1U << CPU_SYS_REGS_PCLKCR7_SCI_D_Pos)                                                /*!< SCI_D Mask 0x00000008 */
#define CPU_SYS_REGS_PCLKCR7_SCI_D_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR7_SCI_D_Pos) & CPU_SYS_REGS_PCLKCR7_SCI_D_Msk)   /*!< SCI_D Set Value */
#define CPU_SYS_REGS_PCLKCR7_SCI_D_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR7_SCI_D_Msk) >> CPU_SYS_REGS_PCLKCR7_SCI_D_Pos)   /*!< SCI_D Get Value */

#define CPU_SYS_REGS_PCLKCR7_SCI_C_Pos     (2U)                                                                                    /*!< SCI_C Position 2 */
#define CPU_SYS_REGS_PCLKCR7_SCI_C_Msk     (0x1U << CPU_SYS_REGS_PCLKCR7_SCI_C_Pos)                                                /*!< SCI_C Mask 0x00000004 */
#define CPU_SYS_REGS_PCLKCR7_SCI_C_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR7_SCI_C_Pos) & CPU_SYS_REGS_PCLKCR7_SCI_C_Msk)   /*!< SCI_C Set Value */
#define CPU_SYS_REGS_PCLKCR7_SCI_C_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR7_SCI_C_Msk) >> CPU_SYS_REGS_PCLKCR7_SCI_C_Pos)   /*!< SCI_C Get Value */

#define CPU_SYS_REGS_PCLKCR7_SCI_B_Pos     (1U)                                                                                    /*!< SCI_B Position 1 */
#define CPU_SYS_REGS_PCLKCR7_SCI_B_Msk     (0x1U << CPU_SYS_REGS_PCLKCR7_SCI_B_Pos)                                                /*!< SCI_B Mask 0x00000002 */
#define CPU_SYS_REGS_PCLKCR7_SCI_B_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR7_SCI_B_Pos) & CPU_SYS_REGS_PCLKCR7_SCI_B_Msk)   /*!< SCI_B Set Value */
#define CPU_SYS_REGS_PCLKCR7_SCI_B_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR7_SCI_B_Msk) >> CPU_SYS_REGS_PCLKCR7_SCI_B_Pos)   /*!< SCI_B Get Value */

#define CPU_SYS_REGS_PCLKCR7_SCI_A_Pos     (0U)                                                                                    /*!< SCI_A Position 0 */
#define CPU_SYS_REGS_PCLKCR7_SCI_A_Msk     (0x1U << CPU_SYS_REGS_PCLKCR7_SCI_A_Pos)                                                /*!< SCI_A Mask 0x00000001 */
#define CPU_SYS_REGS_PCLKCR7_SCI_A_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR7_SCI_A_Pos) & CPU_SYS_REGS_PCLKCR7_SCI_A_Msk)   /*!< SCI_A Set Value */
#define CPU_SYS_REGS_PCLKCR7_SCI_A_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR7_SCI_A_Msk) >> CPU_SYS_REGS_PCLKCR7_SCI_A_Pos)   /*!< SCI_A Get Value */

/* PCLKCR8 bitfield */
#define CPU_SYS_REGS_PCLKCR8_SPI_C_Pos     (2U)                                                                                    /*!< SPI_C Position 2 */
#define CPU_SYS_REGS_PCLKCR8_SPI_C_Msk     (0x1U << CPU_SYS_REGS_PCLKCR8_SPI_C_Pos)                                                /*!< SPI_C Mask 0x00000004 */
#define CPU_SYS_REGS_PCLKCR8_SPI_C_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR8_SPI_C_Pos) & CPU_SYS_REGS_PCLKCR8_SPI_C_Msk)   /*!< SPI_C Set Value */
#define CPU_SYS_REGS_PCLKCR8_SPI_C_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR8_SPI_C_Msk) >> CPU_SYS_REGS_PCLKCR8_SPI_C_Pos)   /*!< SPI_C Get Value */

#define CPU_SYS_REGS_PCLKCR8_SPI_B_Pos     (1U)                                                                                    /*!< SPI_B Position 1 */
#define CPU_SYS_REGS_PCLKCR8_SPI_B_Msk     (0x1U << CPU_SYS_REGS_PCLKCR8_SPI_B_Pos)                                                /*!< SPI_B Mask 0x00000002 */
#define CPU_SYS_REGS_PCLKCR8_SPI_B_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR8_SPI_B_Pos) & CPU_SYS_REGS_PCLKCR8_SPI_B_Msk)   /*!< SPI_B Set Value */
#define CPU_SYS_REGS_PCLKCR8_SPI_B_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR8_SPI_B_Msk) >> CPU_SYS_REGS_PCLKCR8_SPI_B_Pos)   /*!< SPI_B Get Value */

#define CPU_SYS_REGS_PCLKCR8_SPI_A_Pos     (0U)                                                                                    /*!< SPI_A Position 0 */
#define CPU_SYS_REGS_PCLKCR8_SPI_A_Msk     (0x1U << CPU_SYS_REGS_PCLKCR8_SPI_A_Pos)                                                /*!< SPI_A Mask 0x00000001 */
#define CPU_SYS_REGS_PCLKCR8_SPI_A_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR8_SPI_A_Pos) & CPU_SYS_REGS_PCLKCR8_SPI_A_Msk)   /*!< SPI_A Set Value */
#define CPU_SYS_REGS_PCLKCR8_SPI_A_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR8_SPI_A_Msk) >> CPU_SYS_REGS_PCLKCR8_SPI_A_Pos)   /*!< SPI_A Get Value */

/* PCLKCR9 bitfield */
#define CPU_SYS_REGS_PCLKCR9_PMBUS_A_Pos     (16U)                                                                                       /*!< PMBUS_A Position 16 */
#define CPU_SYS_REGS_PCLKCR9_PMBUS_A_Msk     (0x1U << CPU_SYS_REGS_PCLKCR9_PMBUS_A_Pos)                                                  /*!< PMBUS_A Mask 0x00010000 */
#define CPU_SYS_REGS_PCLKCR9_PMBUS_A_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR9_PMBUS_A_Pos) & CPU_SYS_REGS_PCLKCR9_PMBUS_A_Msk)   /*!< PMBUS_A Set Value */
#define CPU_SYS_REGS_PCLKCR9_PMBUS_A_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR9_PMBUS_A_Msk) >> CPU_SYS_REGS_PCLKCR9_PMBUS_A_Pos)   /*!< PMBUS_A Get Value */

#define CPU_SYS_REGS_PCLKCR9_I2C_B_Pos     (1U)                                                                                    /*!< I2C_B Position 1 */
#define CPU_SYS_REGS_PCLKCR9_I2C_B_Msk     (0x1U << CPU_SYS_REGS_PCLKCR9_I2C_B_Pos)                                                /*!< I2C_B Mask 0x00000002 */
#define CPU_SYS_REGS_PCLKCR9_I2C_B_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR9_I2C_B_Pos) & CPU_SYS_REGS_PCLKCR9_I2C_B_Msk)   /*!< I2C_B Set Value */
#define CPU_SYS_REGS_PCLKCR9_I2C_B_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR9_I2C_B_Msk) >> CPU_SYS_REGS_PCLKCR9_I2C_B_Pos)   /*!< I2C_B Get Value */

#define CPU_SYS_REGS_PCLKCR9_I2C_A_Pos     (0U)                                                                                    /*!< I2C_A Position 0 */
#define CPU_SYS_REGS_PCLKCR9_I2C_A_Msk     (0x1U << CPU_SYS_REGS_PCLKCR9_I2C_A_Pos)                                                /*!< I2C_A Mask 0x00000001 */
#define CPU_SYS_REGS_PCLKCR9_I2C_A_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR9_I2C_A_Pos) & CPU_SYS_REGS_PCLKCR9_I2C_A_Msk)   /*!< I2C_A Set Value */
#define CPU_SYS_REGS_PCLKCR9_I2C_A_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR9_I2C_A_Msk) >> CPU_SYS_REGS_PCLKCR9_I2C_A_Pos)   /*!< I2C_A Get Value */

/* PCLKCR10 bitfield */
#define CPU_SYS_REGS_PCLKCR10_CAN_C_Pos     (2U)                                                                                      /*!< CAN_C Position 2 */
#define CPU_SYS_REGS_PCLKCR10_CAN_C_Msk     (0x1U << CPU_SYS_REGS_PCLKCR10_CAN_C_Pos)                                                 /*!< CAN_C Mask 0x00000004 */
#define CPU_SYS_REGS_PCLKCR10_CAN_C_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR10_CAN_C_Pos) & CPU_SYS_REGS_PCLKCR10_CAN_C_Msk)   /*!< CAN_C Set Value */
#define CPU_SYS_REGS_PCLKCR10_CAN_C_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR10_CAN_C_Msk) >> CPU_SYS_REGS_PCLKCR10_CAN_C_Pos)   /*!< CAN_C Get Value */

#define CPU_SYS_REGS_PCLKCR10_CAN_B_Pos     (1U)                                                                                      /*!< CAN_B Position 1 */
#define CPU_SYS_REGS_PCLKCR10_CAN_B_Msk     (0x1U << CPU_SYS_REGS_PCLKCR10_CAN_B_Pos)                                                 /*!< CAN_B Mask 0x00000002 */
#define CPU_SYS_REGS_PCLKCR10_CAN_B_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR10_CAN_B_Pos) & CPU_SYS_REGS_PCLKCR10_CAN_B_Msk)   /*!< CAN_B Set Value */
#define CPU_SYS_REGS_PCLKCR10_CAN_B_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR10_CAN_B_Msk) >> CPU_SYS_REGS_PCLKCR10_CAN_B_Pos)   /*!< CAN_B Get Value */

#define CPU_SYS_REGS_PCLKCR10_CAN_A_Pos     (0U)                                                                                      /*!< CAN_A Position 0 */
#define CPU_SYS_REGS_PCLKCR10_CAN_A_Msk     (0x1U << CPU_SYS_REGS_PCLKCR10_CAN_A_Pos)                                                 /*!< CAN_A Mask 0x00000001 */
#define CPU_SYS_REGS_PCLKCR10_CAN_A_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR10_CAN_A_Pos) & CPU_SYS_REGS_PCLKCR10_CAN_A_Msk)   /*!< CAN_A Set Value */
#define CPU_SYS_REGS_PCLKCR10_CAN_A_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR10_CAN_A_Msk) >> CPU_SYS_REGS_PCLKCR10_CAN_A_Pos)   /*!< CAN_A Get Value */

/* PCLKCR11 bitfield */
#define CPU_SYS_REGS_PCLKCR11_USB_A_Pos     (16U)                                                                                     /*!< USB_A Position 16 */
#define CPU_SYS_REGS_PCLKCR11_USB_A_Msk     (0x1U << CPU_SYS_REGS_PCLKCR11_USB_A_Pos)                                                 /*!< USB_A Mask 0x00010000 */
#define CPU_SYS_REGS_PCLKCR11_USB_A_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR11_USB_A_Pos) & CPU_SYS_REGS_PCLKCR11_USB_A_Msk)   /*!< USB_A Set Value */
#define CPU_SYS_REGS_PCLKCR11_USB_A_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR11_USB_A_Msk) >> CPU_SYS_REGS_PCLKCR11_USB_A_Pos)   /*!< USB_A Get Value */

/* PCLKCR13 bitfield */
#define CPU_SYS_REGS_PCLKCR13_ADC_D_Pos     (3U)                                                                                      /*!< ADC_D Position 3 */
#define CPU_SYS_REGS_PCLKCR13_ADC_D_Msk     (0x1U << CPU_SYS_REGS_PCLKCR13_ADC_D_Pos)                                                 /*!< ADC_D Mask 0x00000008 */
#define CPU_SYS_REGS_PCLKCR13_ADC_D_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR13_ADC_D_Pos) & CPU_SYS_REGS_PCLKCR13_ADC_D_Msk)   /*!< ADC_D Set Value */
#define CPU_SYS_REGS_PCLKCR13_ADC_D_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR13_ADC_D_Msk) >> CPU_SYS_REGS_PCLKCR13_ADC_D_Pos)   /*!< ADC_D Get Value */

#define CPU_SYS_REGS_PCLKCR13_ADC_C_Pos     (2U)                                                                                      /*!< ADC_C Position 2 */
#define CPU_SYS_REGS_PCLKCR13_ADC_C_Msk     (0x1U << CPU_SYS_REGS_PCLKCR13_ADC_C_Pos)                                                 /*!< ADC_C Mask 0x00000004 */
#define CPU_SYS_REGS_PCLKCR13_ADC_C_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR13_ADC_C_Pos) & CPU_SYS_REGS_PCLKCR13_ADC_C_Msk)   /*!< ADC_C Set Value */
#define CPU_SYS_REGS_PCLKCR13_ADC_C_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR13_ADC_C_Msk) >> CPU_SYS_REGS_PCLKCR13_ADC_C_Pos)   /*!< ADC_C Get Value */

#define CPU_SYS_REGS_PCLKCR13_ADC_B_Pos     (1U)                                                                                      /*!< ADC_B Position 1 */
#define CPU_SYS_REGS_PCLKCR13_ADC_B_Msk     (0x1U << CPU_SYS_REGS_PCLKCR13_ADC_B_Pos)                                                 /*!< ADC_B Mask 0x00000002 */
#define CPU_SYS_REGS_PCLKCR13_ADC_B_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR13_ADC_B_Pos) & CPU_SYS_REGS_PCLKCR13_ADC_B_Msk)   /*!< ADC_B Set Value */
#define CPU_SYS_REGS_PCLKCR13_ADC_B_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR13_ADC_B_Msk) >> CPU_SYS_REGS_PCLKCR13_ADC_B_Pos)   /*!< ADC_B Get Value */

#define CPU_SYS_REGS_PCLKCR13_ADC_A_Pos     (0U)                                                                                      /*!< ADC_A Position 0 */
#define CPU_SYS_REGS_PCLKCR13_ADC_A_Msk     (0x1U << CPU_SYS_REGS_PCLKCR13_ADC_A_Pos)                                                 /*!< ADC_A Mask 0x00000001 */
#define CPU_SYS_REGS_PCLKCR13_ADC_A_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR13_ADC_A_Pos) & CPU_SYS_REGS_PCLKCR13_ADC_A_Msk)   /*!< ADC_A Set Value */
#define CPU_SYS_REGS_PCLKCR13_ADC_A_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR13_ADC_A_Msk) >> CPU_SYS_REGS_PCLKCR13_ADC_A_Pos)   /*!< ADC_A Get Value */

/* PCLKCR14 bitfield */
#define CPU_SYS_REGS_PCLKCR14_CMPSS8_Pos     (7U)                                                                                        /*!< CMPSS8 Position 7 */
#define CPU_SYS_REGS_PCLKCR14_CMPSS8_Msk     (0x1U << CPU_SYS_REGS_PCLKCR14_CMPSS8_Pos)                                                  /*!< CMPSS8 Mask 0x00000080 */
#define CPU_SYS_REGS_PCLKCR14_CMPSS8_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR14_CMPSS8_Pos) & CPU_SYS_REGS_PCLKCR14_CMPSS8_Msk)   /*!< CMPSS8 Set Value */
#define CPU_SYS_REGS_PCLKCR14_CMPSS8_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR14_CMPSS8_Msk) >> CPU_SYS_REGS_PCLKCR14_CMPSS8_Pos)   /*!< CMPSS8 Get Value */

#define CPU_SYS_REGS_PCLKCR14_CMPSS7_Pos     (6U)                                                                                        /*!< CMPSS7 Position 6 */
#define CPU_SYS_REGS_PCLKCR14_CMPSS7_Msk     (0x1U << CPU_SYS_REGS_PCLKCR14_CMPSS7_Pos)                                                  /*!< CMPSS7 Mask 0x00000040 */
#define CPU_SYS_REGS_PCLKCR14_CMPSS7_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR14_CMPSS7_Pos) & CPU_SYS_REGS_PCLKCR14_CMPSS7_Msk)   /*!< CMPSS7 Set Value */
#define CPU_SYS_REGS_PCLKCR14_CMPSS7_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR14_CMPSS7_Msk) >> CPU_SYS_REGS_PCLKCR14_CMPSS7_Pos)   /*!< CMPSS7 Get Value */

#define CPU_SYS_REGS_PCLKCR14_CMPSS6_Pos     (5U)                                                                                        /*!< CMPSS6 Position 5 */
#define CPU_SYS_REGS_PCLKCR14_CMPSS6_Msk     (0x1U << CPU_SYS_REGS_PCLKCR14_CMPSS6_Pos)                                                  /*!< CMPSS6 Mask 0x00000020 */
#define CPU_SYS_REGS_PCLKCR14_CMPSS6_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR14_CMPSS6_Pos) & CPU_SYS_REGS_PCLKCR14_CMPSS6_Msk)   /*!< CMPSS6 Set Value */
#define CPU_SYS_REGS_PCLKCR14_CMPSS6_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR14_CMPSS6_Msk) >> CPU_SYS_REGS_PCLKCR14_CMPSS6_Pos)   /*!< CMPSS6 Get Value */

#define CPU_SYS_REGS_PCLKCR14_CMPSS5_Pos     (4U)                                                                                        /*!< CMPSS5 Position 4 */
#define CPU_SYS_REGS_PCLKCR14_CMPSS5_Msk     (0x1U << CPU_SYS_REGS_PCLKCR14_CMPSS5_Pos)                                                  /*!< CMPSS5 Mask 0x00000010 */
#define CPU_SYS_REGS_PCLKCR14_CMPSS5_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR14_CMPSS5_Pos) & CPU_SYS_REGS_PCLKCR14_CMPSS5_Msk)   /*!< CMPSS5 Set Value */
#define CPU_SYS_REGS_PCLKCR14_CMPSS5_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR14_CMPSS5_Msk) >> CPU_SYS_REGS_PCLKCR14_CMPSS5_Pos)   /*!< CMPSS5 Get Value */

#define CPU_SYS_REGS_PCLKCR14_CMPSS4_Pos     (3U)                                                                                        /*!< CMPSS4 Position 3 */
#define CPU_SYS_REGS_PCLKCR14_CMPSS4_Msk     (0x1U << CPU_SYS_REGS_PCLKCR14_CMPSS4_Pos)                                                  /*!< CMPSS4 Mask 0x00000008 */
#define CPU_SYS_REGS_PCLKCR14_CMPSS4_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR14_CMPSS4_Pos) & CPU_SYS_REGS_PCLKCR14_CMPSS4_Msk)   /*!< CMPSS4 Set Value */
#define CPU_SYS_REGS_PCLKCR14_CMPSS4_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR14_CMPSS4_Msk) >> CPU_SYS_REGS_PCLKCR14_CMPSS4_Pos)   /*!< CMPSS4 Get Value */

#define CPU_SYS_REGS_PCLKCR14_CMPSS3_Pos     (2U)                                                                                        /*!< CMPSS3 Position 2 */
#define CPU_SYS_REGS_PCLKCR14_CMPSS3_Msk     (0x1U << CPU_SYS_REGS_PCLKCR14_CMPSS3_Pos)                                                  /*!< CMPSS3 Mask 0x00000004 */
#define CPU_SYS_REGS_PCLKCR14_CMPSS3_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR14_CMPSS3_Pos) & CPU_SYS_REGS_PCLKCR14_CMPSS3_Msk)   /*!< CMPSS3 Set Value */
#define CPU_SYS_REGS_PCLKCR14_CMPSS3_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR14_CMPSS3_Msk) >> CPU_SYS_REGS_PCLKCR14_CMPSS3_Pos)   /*!< CMPSS3 Get Value */

#define CPU_SYS_REGS_PCLKCR14_CMPSS2_Pos     (1U)                                                                                        /*!< CMPSS2 Position 1 */
#define CPU_SYS_REGS_PCLKCR14_CMPSS2_Msk     (0x1U << CPU_SYS_REGS_PCLKCR14_CMPSS2_Pos)                                                  /*!< CMPSS2 Mask 0x00000002 */
#define CPU_SYS_REGS_PCLKCR14_CMPSS2_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR14_CMPSS2_Pos) & CPU_SYS_REGS_PCLKCR14_CMPSS2_Msk)   /*!< CMPSS2 Set Value */
#define CPU_SYS_REGS_PCLKCR14_CMPSS2_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR14_CMPSS2_Msk) >> CPU_SYS_REGS_PCLKCR14_CMPSS2_Pos)   /*!< CMPSS2 Get Value */

#define CPU_SYS_REGS_PCLKCR14_CMPSS1_Pos     (0U)                                                                                        /*!< CMPSS1 Position 0 */
#define CPU_SYS_REGS_PCLKCR14_CMPSS1_Msk     (0x1U << CPU_SYS_REGS_PCLKCR14_CMPSS1_Pos)                                                  /*!< CMPSS1 Mask 0x00000001 */
#define CPU_SYS_REGS_PCLKCR14_CMPSS1_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR14_CMPSS1_Pos) & CPU_SYS_REGS_PCLKCR14_CMPSS1_Msk)   /*!< CMPSS1 Set Value */
#define CPU_SYS_REGS_PCLKCR14_CMPSS1_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR14_CMPSS1_Msk) >> CPU_SYS_REGS_PCLKCR14_CMPSS1_Pos)   /*!< CMPSS1 Get Value */

/* PCLKCR16 bitfield */
#define CPU_SYS_REGS_PCLKCR16_DAC_C_Pos     (18U)                                                                                     /*!< DAC_C Position 18 */
#define CPU_SYS_REGS_PCLKCR16_DAC_C_Msk     (0x1U << CPU_SYS_REGS_PCLKCR16_DAC_C_Pos)                                                 /*!< DAC_C Mask 0x00040000 */
#define CPU_SYS_REGS_PCLKCR16_DAC_C_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR16_DAC_C_Pos) & CPU_SYS_REGS_PCLKCR16_DAC_C_Msk)   /*!< DAC_C Set Value */
#define CPU_SYS_REGS_PCLKCR16_DAC_C_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR16_DAC_C_Msk) >> CPU_SYS_REGS_PCLKCR16_DAC_C_Pos)   /*!< DAC_C Get Value */

#define CPU_SYS_REGS_PCLKCR16_DAC_B_Pos     (17U)                                                                                     /*!< DAC_B Position 17 */
#define CPU_SYS_REGS_PCLKCR16_DAC_B_Msk     (0x1U << CPU_SYS_REGS_PCLKCR16_DAC_B_Pos)                                                 /*!< DAC_B Mask 0x00020000 */
#define CPU_SYS_REGS_PCLKCR16_DAC_B_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR16_DAC_B_Pos) & CPU_SYS_REGS_PCLKCR16_DAC_B_Msk)   /*!< DAC_B Set Value */
#define CPU_SYS_REGS_PCLKCR16_DAC_B_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR16_DAC_B_Msk) >> CPU_SYS_REGS_PCLKCR16_DAC_B_Pos)   /*!< DAC_B Get Value */

#define CPU_SYS_REGS_PCLKCR16_DAC_A_Pos     (16U)                                                                                     /*!< DAC_A Position 16 */
#define CPU_SYS_REGS_PCLKCR16_DAC_A_Msk     (0x1U << CPU_SYS_REGS_PCLKCR16_DAC_A_Pos)                                                 /*!< DAC_A Mask 0x00010000 */
#define CPU_SYS_REGS_PCLKCR16_DAC_A_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR16_DAC_A_Pos) & CPU_SYS_REGS_PCLKCR16_DAC_A_Msk)   /*!< DAC_A Set Value */
#define CPU_SYS_REGS_PCLKCR16_DAC_A_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR16_DAC_A_Msk) >> CPU_SYS_REGS_PCLKCR16_DAC_A_Pos)   /*!< DAC_A Get Value */

/* PCLKCR17 bitfield */
#define CPU_SYS_REGS_PCLKCR17_CLB8_Pos     (7U)                                                                                    /*!< CLB8 Position 7 */
#define CPU_SYS_REGS_PCLKCR17_CLB8_Msk     (0x1U << CPU_SYS_REGS_PCLKCR17_CLB8_Pos)                                                /*!< CLB8 Mask 0x00000080 */
#define CPU_SYS_REGS_PCLKCR17_CLB8_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR17_CLB8_Pos) & CPU_SYS_REGS_PCLKCR17_CLB8_Msk)   /*!< CLB8 Set Value */
#define CPU_SYS_REGS_PCLKCR17_CLB8_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR17_CLB8_Msk) >> CPU_SYS_REGS_PCLKCR17_CLB8_Pos)   /*!< CLB8 Get Value */

#define CPU_SYS_REGS_PCLKCR17_CLB7_Pos     (6U)                                                                                    /*!< CLB7 Position 6 */
#define CPU_SYS_REGS_PCLKCR17_CLB7_Msk     (0x1U << CPU_SYS_REGS_PCLKCR17_CLB7_Pos)                                                /*!< CLB7 Mask 0x00000040 */
#define CPU_SYS_REGS_PCLKCR17_CLB7_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR17_CLB7_Pos) & CPU_SYS_REGS_PCLKCR17_CLB7_Msk)   /*!< CLB7 Set Value */
#define CPU_SYS_REGS_PCLKCR17_CLB7_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR17_CLB7_Msk) >> CPU_SYS_REGS_PCLKCR17_CLB7_Pos)   /*!< CLB7 Get Value */

#define CPU_SYS_REGS_PCLKCR17_CLB6_Pos     (5U)                                                                                    /*!< CLB6 Position 5 */
#define CPU_SYS_REGS_PCLKCR17_CLB6_Msk     (0x1U << CPU_SYS_REGS_PCLKCR17_CLB6_Pos)                                                /*!< CLB6 Mask 0x00000020 */
#define CPU_SYS_REGS_PCLKCR17_CLB6_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR17_CLB6_Pos) & CPU_SYS_REGS_PCLKCR17_CLB6_Msk)   /*!< CLB6 Set Value */
#define CPU_SYS_REGS_PCLKCR17_CLB6_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR17_CLB6_Msk) >> CPU_SYS_REGS_PCLKCR17_CLB6_Pos)   /*!< CLB6 Get Value */

#define CPU_SYS_REGS_PCLKCR17_CLB5_Pos     (4U)                                                                                    /*!< CLB5 Position 4 */
#define CPU_SYS_REGS_PCLKCR17_CLB5_Msk     (0x1U << CPU_SYS_REGS_PCLKCR17_CLB5_Pos)                                                /*!< CLB5 Mask 0x00000010 */
#define CPU_SYS_REGS_PCLKCR17_CLB5_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR17_CLB5_Pos) & CPU_SYS_REGS_PCLKCR17_CLB5_Msk)   /*!< CLB5 Set Value */
#define CPU_SYS_REGS_PCLKCR17_CLB5_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR17_CLB5_Msk) >> CPU_SYS_REGS_PCLKCR17_CLB5_Pos)   /*!< CLB5 Get Value */

#define CPU_SYS_REGS_PCLKCR17_CLB4_Pos     (3U)                                                                                    /*!< CLB4 Position 3 */
#define CPU_SYS_REGS_PCLKCR17_CLB4_Msk     (0x1U << CPU_SYS_REGS_PCLKCR17_CLB4_Pos)                                                /*!< CLB4 Mask 0x00000008 */
#define CPU_SYS_REGS_PCLKCR17_CLB4_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR17_CLB4_Pos) & CPU_SYS_REGS_PCLKCR17_CLB4_Msk)   /*!< CLB4 Set Value */
#define CPU_SYS_REGS_PCLKCR17_CLB4_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR17_CLB4_Msk) >> CPU_SYS_REGS_PCLKCR17_CLB4_Pos)   /*!< CLB4 Get Value */

#define CPU_SYS_REGS_PCLKCR17_CLB3_Pos     (2U)                                                                                    /*!< CLB3 Position 2 */
#define CPU_SYS_REGS_PCLKCR17_CLB3_Msk     (0x1U << CPU_SYS_REGS_PCLKCR17_CLB3_Pos)                                                /*!< CLB3 Mask 0x00000004 */
#define CPU_SYS_REGS_PCLKCR17_CLB3_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR17_CLB3_Pos) & CPU_SYS_REGS_PCLKCR17_CLB3_Msk)   /*!< CLB3 Set Value */
#define CPU_SYS_REGS_PCLKCR17_CLB3_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR17_CLB3_Msk) >> CPU_SYS_REGS_PCLKCR17_CLB3_Pos)   /*!< CLB3 Get Value */

#define CPU_SYS_REGS_PCLKCR17_CLB2_Pos     (1U)                                                                                    /*!< CLB2 Position 1 */
#define CPU_SYS_REGS_PCLKCR17_CLB2_Msk     (0x1U << CPU_SYS_REGS_PCLKCR17_CLB2_Pos)                                                /*!< CLB2 Mask 0x00000002 */
#define CPU_SYS_REGS_PCLKCR17_CLB2_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR17_CLB2_Pos) & CPU_SYS_REGS_PCLKCR17_CLB2_Msk)   /*!< CLB2 Set Value */
#define CPU_SYS_REGS_PCLKCR17_CLB2_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR17_CLB2_Msk) >> CPU_SYS_REGS_PCLKCR17_CLB2_Pos)   /*!< CLB2 Get Value */

#define CPU_SYS_REGS_PCLKCR17_CLB1_Pos     (0U)                                                                                    /*!< CLB1 Position 0 */
#define CPU_SYS_REGS_PCLKCR17_CLB1_Msk     (0x1U << CPU_SYS_REGS_PCLKCR17_CLB1_Pos)                                                /*!< CLB1 Mask 0x00000001 */
#define CPU_SYS_REGS_PCLKCR17_CLB1_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_PCLKCR17_CLB1_Pos) & CPU_SYS_REGS_PCLKCR17_CLB1_Msk)   /*!< CLB1 Set Value */
#define CPU_SYS_REGS_PCLKCR17_CLB1_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_PCLKCR17_CLB1_Msk) >> CPU_SYS_REGS_PCLKCR17_CLB1_Pos)   /*!< CLB1 Get Value */

/* LPMCR bitfield */
#define CPU_SYS_REGS_LPMCR_QUALSTDBY_Pos     (2U)                                                                                        /*!< QUALSTDBY Position 2 */
#define CPU_SYS_REGS_LPMCR_QUALSTDBY_Msk     (0x3fU << CPU_SYS_REGS_LPMCR_QUALSTDBY_Pos)                                                 /*!< QUALSTDBY Mask 0x000000FC */
#define CPU_SYS_REGS_LPMCR_QUALSTDBY_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_LPMCR_QUALSTDBY_Pos) & CPU_SYS_REGS_LPMCR_QUALSTDBY_Msk)   /*!< QUALSTDBY Set Value */
#define CPU_SYS_REGS_LPMCR_QUALSTDBY_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_LPMCR_QUALSTDBY_Msk) >> CPU_SYS_REGS_LPMCR_QUALSTDBY_Pos)   /*!< QUALSTDBY Get Value */

/* GPIOLPMSEL0 bitfield */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO31_Pos     (31U)                                                                                             /*!< GPIO31 Position 31 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO31_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO31_Pos)                                                     /*!< GPIO31 Mask 0x80000000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO31_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO31_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO31_Msk)   /*!< GPIO31 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO31_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO31_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO31_Pos)   /*!< GPIO31 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO30_Pos     (30U)                                                                                             /*!< GPIO30 Position 30 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO30_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO30_Pos)                                                     /*!< GPIO30 Mask 0x40000000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO30_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO30_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO30_Msk)   /*!< GPIO30 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO30_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO30_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO30_Pos)   /*!< GPIO30 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO29_Pos     (29U)                                                                                             /*!< GPIO29 Position 29 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO29_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO29_Pos)                                                     /*!< GPIO29 Mask 0x20000000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO29_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO29_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO29_Msk)   /*!< GPIO29 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO29_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO29_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO29_Pos)   /*!< GPIO29 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO28_Pos     (28U)                                                                                             /*!< GPIO28 Position 28 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO28_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO28_Pos)                                                     /*!< GPIO28 Mask 0x10000000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO28_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO28_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO28_Msk)   /*!< GPIO28 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO28_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO28_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO28_Pos)   /*!< GPIO28 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO27_Pos     (27U)                                                                                             /*!< GPIO27 Position 27 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO27_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO27_Pos)                                                     /*!< GPIO27 Mask 0x08000000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO27_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO27_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO27_Msk)   /*!< GPIO27 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO27_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO27_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO27_Pos)   /*!< GPIO27 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO26_Pos     (26U)                                                                                             /*!< GPIO26 Position 26 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO26_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO26_Pos)                                                     /*!< GPIO26 Mask 0x04000000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO26_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO26_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO26_Msk)   /*!< GPIO26 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO26_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO26_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO26_Pos)   /*!< GPIO26 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO25_Pos     (25U)                                                                                             /*!< GPIO25 Position 25 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO25_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO25_Pos)                                                     /*!< GPIO25 Mask 0x02000000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO25_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO25_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO25_Msk)   /*!< GPIO25 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO25_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO25_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO25_Pos)   /*!< GPIO25 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO24_Pos     (24U)                                                                                             /*!< GPIO24 Position 24 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO24_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO24_Pos)                                                     /*!< GPIO24 Mask 0x01000000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO24_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO24_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO24_Msk)   /*!< GPIO24 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO24_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO24_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO24_Pos)   /*!< GPIO24 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO23_Pos     (23U)                                                                                             /*!< GPIO23 Position 23 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO23_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO23_Pos)                                                     /*!< GPIO23 Mask 0x00800000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO23_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO23_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO23_Msk)   /*!< GPIO23 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO23_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO23_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO23_Pos)   /*!< GPIO23 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO22_Pos     (22U)                                                                                             /*!< GPIO22 Position 22 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO22_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO22_Pos)                                                     /*!< GPIO22 Mask 0x00400000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO22_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO22_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO22_Msk)   /*!< GPIO22 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO22_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO22_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO22_Pos)   /*!< GPIO22 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO21_Pos     (21U)                                                                                             /*!< GPIO21 Position 21 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO21_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO21_Pos)                                                     /*!< GPIO21 Mask 0x00200000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO21_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO21_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO21_Msk)   /*!< GPIO21 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO21_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO21_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO21_Pos)   /*!< GPIO21 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO20_Pos     (20U)                                                                                             /*!< GPIO20 Position 20 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO20_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO20_Pos)                                                     /*!< GPIO20 Mask 0x00100000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO20_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO20_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO20_Msk)   /*!< GPIO20 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO20_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO20_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO20_Pos)   /*!< GPIO20 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO19_Pos     (19U)                                                                                             /*!< GPIO19 Position 19 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO19_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO19_Pos)                                                     /*!< GPIO19 Mask 0x00080000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO19_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO19_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO19_Msk)   /*!< GPIO19 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO19_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO19_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO19_Pos)   /*!< GPIO19 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO18_Pos     (18U)                                                                                             /*!< GPIO18 Position 18 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO18_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO18_Pos)                                                     /*!< GPIO18 Mask 0x00040000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO18_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO18_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO18_Msk)   /*!< GPIO18 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO18_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO18_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO18_Pos)   /*!< GPIO18 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO17_Pos     (17U)                                                                                             /*!< GPIO17 Position 17 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO17_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO17_Pos)                                                     /*!< GPIO17 Mask 0x00020000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO17_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO17_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO17_Msk)   /*!< GPIO17 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO17_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO17_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO17_Pos)   /*!< GPIO17 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO16_Pos     (16U)                                                                                             /*!< GPIO16 Position 16 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO16_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO16_Pos)                                                     /*!< GPIO16 Mask 0x00010000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO16_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO16_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO16_Msk)   /*!< GPIO16 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO16_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO16_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO16_Pos)   /*!< GPIO16 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO15_Pos     (15U)                                                                                             /*!< GPIO15 Position 15 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO15_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO15_Pos)                                                     /*!< GPIO15 Mask 0x00008000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO15_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO15_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO15_Msk)   /*!< GPIO15 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO15_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO15_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO15_Pos)   /*!< GPIO15 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO14_Pos     (14U)                                                                                             /*!< GPIO14 Position 14 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO14_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO14_Pos)                                                     /*!< GPIO14 Mask 0x00004000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO14_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO14_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO14_Msk)   /*!< GPIO14 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO14_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO14_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO14_Pos)   /*!< GPIO14 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO13_Pos     (13U)                                                                                             /*!< GPIO13 Position 13 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO13_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO13_Pos)                                                     /*!< GPIO13 Mask 0x00002000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO13_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO13_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO13_Msk)   /*!< GPIO13 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO13_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO13_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO13_Pos)   /*!< GPIO13 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO12_Pos     (12U)                                                                                             /*!< GPIO12 Position 12 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO12_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO12_Pos)                                                     /*!< GPIO12 Mask 0x00001000 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO12_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO12_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO12_Msk)   /*!< GPIO12 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO12_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO12_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO12_Pos)   /*!< GPIO12 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO11_Pos     (11U)                                                                                             /*!< GPIO11 Position 11 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO11_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO11_Pos)                                                     /*!< GPIO11 Mask 0x00000800 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO11_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO11_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO11_Msk)   /*!< GPIO11 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO11_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO11_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO11_Pos)   /*!< GPIO11 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO10_Pos     (10U)                                                                                             /*!< GPIO10 Position 10 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO10_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO10_Pos)                                                     /*!< GPIO10 Mask 0x00000400 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO10_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO10_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO10_Msk)   /*!< GPIO10 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO10_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO10_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO10_Pos)   /*!< GPIO10 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO9_Pos     (9U)                                                                                            /*!< GPIO9 Position 9 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO9_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO9_Pos)                                                    /*!< GPIO9 Mask 0x00000200 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO9_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO9_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO9_Msk)   /*!< GPIO9 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO9_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO9_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO9_Pos)   /*!< GPIO9 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO8_Pos     (8U)                                                                                            /*!< GPIO8 Position 8 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO8_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO8_Pos)                                                    /*!< GPIO8 Mask 0x00000100 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO8_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO8_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO8_Msk)   /*!< GPIO8 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO8_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO8_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO8_Pos)   /*!< GPIO8 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO7_Pos     (7U)                                                                                            /*!< GPIO7 Position 7 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO7_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO7_Pos)                                                    /*!< GPIO7 Mask 0x00000080 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO7_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO7_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO7_Msk)   /*!< GPIO7 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO7_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO7_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO7_Pos)   /*!< GPIO7 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO6_Pos     (6U)                                                                                            /*!< GPIO6 Position 6 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO6_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO6_Pos)                                                    /*!< GPIO6 Mask 0x00000040 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO6_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO6_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO6_Msk)   /*!< GPIO6 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO6_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO6_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO6_Pos)   /*!< GPIO6 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO5_Pos     (5U)                                                                                            /*!< GPIO5 Position 5 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO5_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO5_Pos)                                                    /*!< GPIO5 Mask 0x00000020 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO5_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO5_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO5_Msk)   /*!< GPIO5 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO5_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO5_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO5_Pos)   /*!< GPIO5 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO4_Pos     (4U)                                                                                            /*!< GPIO4 Position 4 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO4_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO4_Pos)                                                    /*!< GPIO4 Mask 0x00000010 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO4_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO4_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO4_Msk)   /*!< GPIO4 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO4_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO4_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO4_Pos)   /*!< GPIO4 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO3_Pos     (3U)                                                                                            /*!< GPIO3 Position 3 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO3_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO3_Pos)                                                    /*!< GPIO3 Mask 0x00000008 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO3_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO3_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO3_Msk)   /*!< GPIO3 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO3_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO3_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO3_Pos)   /*!< GPIO3 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO2_Pos     (2U)                                                                                            /*!< GPIO2 Position 2 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO2_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO2_Pos)                                                    /*!< GPIO2 Mask 0x00000004 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO2_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO2_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO2_Msk)   /*!< GPIO2 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO2_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO2_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO2_Pos)   /*!< GPIO2 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO1_Pos     (1U)                                                                                            /*!< GPIO1 Position 1 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO1_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO1_Pos)                                                    /*!< GPIO1 Mask 0x00000002 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO1_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO1_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO1_Msk)   /*!< GPIO1 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO1_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO1_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO1_Pos)   /*!< GPIO1 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO0_Pos     (0U)                                                                                            /*!< GPIO0 Position 0 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO0_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL0_GPIO0_Pos)                                                    /*!< GPIO0 Mask 0x00000001 */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO0_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL0_GPIO0_Pos) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO0_Msk)   /*!< GPIO0 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL0_GPIO0_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL0_GPIO0_Msk) >> CPU_SYS_REGS_GPIOLPMSEL0_GPIO0_Pos)   /*!< GPIO0 Get Value */

/* GPIOLPMSEL1 bitfield */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO63_Pos     (31U)                                                                                             /*!< GPIO63 Position 31 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO63_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO63_Pos)                                                     /*!< GPIO63 Mask 0x80000000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO63_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO63_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO63_Msk)   /*!< GPIO63 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO63_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO63_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO63_Pos)   /*!< GPIO63 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO62_Pos     (30U)                                                                                             /*!< GPIO62 Position 30 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO62_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO62_Pos)                                                     /*!< GPIO62 Mask 0x40000000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO62_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO62_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO62_Msk)   /*!< GPIO62 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO62_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO62_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO62_Pos)   /*!< GPIO62 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO61_Pos     (29U)                                                                                             /*!< GPIO61 Position 29 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO61_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO61_Pos)                                                     /*!< GPIO61 Mask 0x20000000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO61_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO61_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO61_Msk)   /*!< GPIO61 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO61_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO61_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO61_Pos)   /*!< GPIO61 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO60_Pos     (28U)                                                                                             /*!< GPIO60 Position 28 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO60_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO60_Pos)                                                     /*!< GPIO60 Mask 0x10000000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO60_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO60_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO60_Msk)   /*!< GPIO60 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO60_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO60_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO60_Pos)   /*!< GPIO60 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO59_Pos     (27U)                                                                                             /*!< GPIO59 Position 27 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO59_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO59_Pos)                                                     /*!< GPIO59 Mask 0x08000000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO59_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO59_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO59_Msk)   /*!< GPIO59 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO59_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO59_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO59_Pos)   /*!< GPIO59 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO58_Pos     (26U)                                                                                             /*!< GPIO58 Position 26 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO58_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO58_Pos)                                                     /*!< GPIO58 Mask 0x04000000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO58_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO58_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO58_Msk)   /*!< GPIO58 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO58_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO58_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO58_Pos)   /*!< GPIO58 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO57_Pos     (25U)                                                                                             /*!< GPIO57 Position 25 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO57_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO57_Pos)                                                     /*!< GPIO57 Mask 0x02000000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO57_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO57_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO57_Msk)   /*!< GPIO57 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO57_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO57_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO57_Pos)   /*!< GPIO57 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO56_Pos     (24U)                                                                                             /*!< GPIO56 Position 24 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO56_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO56_Pos)                                                     /*!< GPIO56 Mask 0x01000000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO56_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO56_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO56_Msk)   /*!< GPIO56 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO56_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO56_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO56_Pos)   /*!< GPIO56 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO55_Pos     (23U)                                                                                             /*!< GPIO55 Position 23 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO55_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO55_Pos)                                                     /*!< GPIO55 Mask 0x00800000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO55_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO55_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO55_Msk)   /*!< GPIO55 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO55_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO55_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO55_Pos)   /*!< GPIO55 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO54_Pos     (22U)                                                                                             /*!< GPIO54 Position 22 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO54_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO54_Pos)                                                     /*!< GPIO54 Mask 0x00400000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO54_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO54_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO54_Msk)   /*!< GPIO54 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO54_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO54_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO54_Pos)   /*!< GPIO54 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO53_Pos     (21U)                                                                                             /*!< GPIO53 Position 21 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO53_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO53_Pos)                                                     /*!< GPIO53 Mask 0x00200000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO53_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO53_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO53_Msk)   /*!< GPIO53 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO53_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO53_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO53_Pos)   /*!< GPIO53 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO52_Pos     (20U)                                                                                             /*!< GPIO52 Position 20 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO52_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO52_Pos)                                                     /*!< GPIO52 Mask 0x00100000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO52_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO52_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO52_Msk)   /*!< GPIO52 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO52_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO52_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO52_Pos)   /*!< GPIO52 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO51_Pos     (19U)                                                                                             /*!< GPIO51 Position 19 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO51_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO51_Pos)                                                     /*!< GPIO51 Mask 0x00080000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO51_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO51_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO51_Msk)   /*!< GPIO51 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO51_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO51_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO51_Pos)   /*!< GPIO51 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO50_Pos     (18U)                                                                                             /*!< GPIO50 Position 18 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO50_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO50_Pos)                                                     /*!< GPIO50 Mask 0x00040000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO50_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO50_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO50_Msk)   /*!< GPIO50 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO50_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO50_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO50_Pos)   /*!< GPIO50 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO49_Pos     (17U)                                                                                             /*!< GPIO49 Position 17 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO49_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO49_Pos)                                                     /*!< GPIO49 Mask 0x00020000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO49_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO49_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO49_Msk)   /*!< GPIO49 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO49_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO49_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO49_Pos)   /*!< GPIO49 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO48_Pos     (16U)                                                                                             /*!< GPIO48 Position 16 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO48_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO48_Pos)                                                     /*!< GPIO48 Mask 0x00010000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO48_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO48_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO48_Msk)   /*!< GPIO48 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO48_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO48_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO48_Pos)   /*!< GPIO48 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO47_Pos     (15U)                                                                                             /*!< GPIO47 Position 15 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO47_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO47_Pos)                                                     /*!< GPIO47 Mask 0x00008000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO47_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO47_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO47_Msk)   /*!< GPIO47 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO47_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO47_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO47_Pos)   /*!< GPIO47 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO46_Pos     (14U)                                                                                             /*!< GPIO46 Position 14 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO46_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO46_Pos)                                                     /*!< GPIO46 Mask 0x00004000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO46_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO46_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO46_Msk)   /*!< GPIO46 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO46_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO46_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO46_Pos)   /*!< GPIO46 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO45_Pos     (13U)                                                                                             /*!< GPIO45 Position 13 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO45_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO45_Pos)                                                     /*!< GPIO45 Mask 0x00002000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO45_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO45_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO45_Msk)   /*!< GPIO45 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO45_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO45_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO45_Pos)   /*!< GPIO45 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO44_Pos     (12U)                                                                                             /*!< GPIO44 Position 12 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO44_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO44_Pos)                                                     /*!< GPIO44 Mask 0x00001000 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO44_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO44_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO44_Msk)   /*!< GPIO44 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO44_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO44_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO44_Pos)   /*!< GPIO44 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO43_Pos     (11U)                                                                                             /*!< GPIO43 Position 11 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO43_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO43_Pos)                                                     /*!< GPIO43 Mask 0x00000800 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO43_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO43_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO43_Msk)   /*!< GPIO43 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO43_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO43_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO43_Pos)   /*!< GPIO43 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO42_Pos     (10U)                                                                                             /*!< GPIO42 Position 10 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO42_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO42_Pos)                                                     /*!< GPIO42 Mask 0x00000400 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO42_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO42_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO42_Msk)   /*!< GPIO42 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO42_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO42_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO42_Pos)   /*!< GPIO42 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO41_Pos     (9U)                                                                                              /*!< GPIO41 Position 9 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO41_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO41_Pos)                                                     /*!< GPIO41 Mask 0x00000200 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO41_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO41_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO41_Msk)   /*!< GPIO41 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO41_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO41_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO41_Pos)   /*!< GPIO41 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO40_Pos     (8U)                                                                                              /*!< GPIO40 Position 8 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO40_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO40_Pos)                                                     /*!< GPIO40 Mask 0x00000100 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO40_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO40_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO40_Msk)   /*!< GPIO40 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO40_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO40_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO40_Pos)   /*!< GPIO40 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO39_Pos     (7U)                                                                                              /*!< GPIO39 Position 7 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO39_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO39_Pos)                                                     /*!< GPIO39 Mask 0x00000080 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO39_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO39_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO39_Msk)   /*!< GPIO39 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO39_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO39_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO39_Pos)   /*!< GPIO39 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO38_Pos     (6U)                                                                                              /*!< GPIO38 Position 6 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO38_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO38_Pos)                                                     /*!< GPIO38 Mask 0x00000040 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO38_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO38_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO38_Msk)   /*!< GPIO38 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO38_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO38_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO38_Pos)   /*!< GPIO38 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO37_Pos     (5U)                                                                                              /*!< GPIO37 Position 5 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO37_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO37_Pos)                                                     /*!< GPIO37 Mask 0x00000020 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO37_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO37_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO37_Msk)   /*!< GPIO37 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO37_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO37_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO37_Pos)   /*!< GPIO37 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO36_Pos     (4U)                                                                                              /*!< GPIO36 Position 4 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO36_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO36_Pos)                                                     /*!< GPIO36 Mask 0x00000010 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO36_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO36_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO36_Msk)   /*!< GPIO36 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO36_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO36_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO36_Pos)   /*!< GPIO36 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO35_Pos     (3U)                                                                                              /*!< GPIO35 Position 3 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO35_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO35_Pos)                                                     /*!< GPIO35 Mask 0x00000008 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO35_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO35_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO35_Msk)   /*!< GPIO35 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO35_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO35_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO35_Pos)   /*!< GPIO35 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO34_Pos     (2U)                                                                                              /*!< GPIO34 Position 2 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO34_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO34_Pos)                                                     /*!< GPIO34 Mask 0x00000004 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO34_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO34_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO34_Msk)   /*!< GPIO34 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO34_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO34_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO34_Pos)   /*!< GPIO34 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO33_Pos     (1U)                                                                                              /*!< GPIO33 Position 1 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO33_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO33_Pos)                                                     /*!< GPIO33 Mask 0x00000002 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO33_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO33_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO33_Msk)   /*!< GPIO33 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO33_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO33_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO33_Pos)   /*!< GPIO33 Get Value */

#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO32_Pos     (0U)                                                                                              /*!< GPIO32 Position 0 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO32_Msk     (0x1U << CPU_SYS_REGS_GPIOLPMSEL1_GPIO32_Pos)                                                     /*!< GPIO32 Mask 0x00000001 */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO32_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_GPIOLPMSEL1_GPIO32_Pos) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO32_Msk)   /*!< GPIO32 Set Value */
#define CPU_SYS_REGS_GPIOLPMSEL1_GPIO32_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_GPIOLPMSEL1_GPIO32_Msk) >> CPU_SYS_REGS_GPIOLPMSEL1_GPIO32_Pos)   /*!< GPIO32 Get Value */

/* TMR2CLKCTL bitfield */
#define CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKPRESCALE_Pos     (3U)                                                                                                              /*!< TMR2CLKPRESCALE Position 3 */
#define CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKPRESCALE_Msk     (0x7U << CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKPRESCALE_Pos)                                                             /*!< TMR2CLKPRESCALE Mask 0x00000038 */
#define CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKPRESCALE_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKPRESCALE_Pos) & CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKPRESCALE_Msk)   /*!< TMR2CLKPRESCALE Set Value */
#define CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKPRESCALE_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKPRESCALE_Msk) >> CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKPRESCALE_Pos)   /*!< TMR2CLKPRESCALE Get Value */

#define CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKSRCSEL_Pos     (0U)                                                                                                          /*!< TMR2CLKSRCSEL Position 0 */
#define CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKSRCSEL_Msk     (0x7U << CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKSRCSEL_Pos)                                                           /*!< TMR2CLKSRCSEL Mask 0x00000007 */
#define CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKSRCSEL_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKSRCSEL_Pos) & CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKSRCSEL_Msk)   /*!< TMR2CLKSRCSEL Set Value */
#define CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKSRCSEL_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKSRCSEL_Msk) >> CPU_SYS_REGS_TMR2CLKCTL_TMR2CLKSRCSEL_Pos)   /*!< TMR2CLKSRCSEL Get Value */

/* RESC bitfield */
#define CPU_SYS_REGS_RESC_TRSTN_PIN_STATUS_Pos     (31U)                                                                                                   /*!< TRSTN_PIN_STATUS Position 31 */
#define CPU_SYS_REGS_RESC_TRSTN_PIN_STATUS_Msk     (0x1U << CPU_SYS_REGS_RESC_TRSTN_PIN_STATUS_Pos)                                                        /*!< TRSTN_PIN_STATUS Mask 0x80000000 */
#define CPU_SYS_REGS_RESC_TRSTN_PIN_STATUS_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_RESC_TRSTN_PIN_STATUS_Pos) & CPU_SYS_REGS_RESC_TRSTN_PIN_STATUS_Msk)   /*!< TRSTN_PIN_STATUS Set Value */
#define CPU_SYS_REGS_RESC_TRSTN_PIN_STATUS_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_RESC_TRSTN_PIN_STATUS_Msk) >> CPU_SYS_REGS_RESC_TRSTN_PIN_STATUS_Pos)   /*!< TRSTN_PIN_STATUS Get Value */

#define CPU_SYS_REGS_RESC_XRSN_PIN_STATUS_Pos     (30U)                                                                                                 /*!< XRSN_PIN_STATUS Position 30 */
#define CPU_SYS_REGS_RESC_XRSN_PIN_STATUS_Msk     (0x1U << CPU_SYS_REGS_RESC_XRSN_PIN_STATUS_Pos)                                                       /*!< XRSN_PIN_STATUS Mask 0x40000000 */
#define CPU_SYS_REGS_RESC_XRSN_PIN_STATUS_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_RESC_XRSN_PIN_STATUS_Pos) & CPU_SYS_REGS_RESC_XRSN_PIN_STATUS_Msk)   /*!< XRSN_PIN_STATUS Set Value */
#define CPU_SYS_REGS_RESC_XRSN_PIN_STATUS_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_RESC_XRSN_PIN_STATUS_Msk) >> CPU_SYS_REGS_RESC_XRSN_PIN_STATUS_Pos)   /*!< XRSN_PIN_STATUS Get Value */

#define CPU_SYS_REGS_RESC_NMIWDRSN_Pos     (3U)                                                                                    /*!< NMIWDRSN Position 3 */
#define CPU_SYS_REGS_RESC_NMIWDRSN_Msk     (0x1U << CPU_SYS_REGS_RESC_NMIWDRSN_Pos)                                                /*!< NMIWDRSN Mask 0x00000008 */
#define CPU_SYS_REGS_RESC_NMIWDRSN_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_RESC_NMIWDRSN_Pos) & CPU_SYS_REGS_RESC_NMIWDRSN_Msk)   /*!< NMIWDRSN Set Value */
#define CPU_SYS_REGS_RESC_NMIWDRSN_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_RESC_NMIWDRSN_Msk) >> CPU_SYS_REGS_RESC_NMIWDRSN_Pos)   /*!< NMIWDRSN Get Value */

#define CPU_SYS_REGS_RESC_WDRSN_Pos     (2U)                                                                              /*!< WDRSN Position 2 */
#define CPU_SYS_REGS_RESC_WDRSN_Msk     (0x1U << CPU_SYS_REGS_RESC_WDRSN_Pos)                                             /*!< WDRSN Mask 0x00000004 */
#define CPU_SYS_REGS_RESC_WDRSN_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_RESC_WDRSN_Pos) & CPU_SYS_REGS_RESC_WDRSN_Msk)   /*!< WDRSN Set Value */
#define CPU_SYS_REGS_RESC_WDRSN_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_RESC_WDRSN_Msk) >> CPU_SYS_REGS_RESC_WDRSN_Pos)   /*!< WDRSN Get Value */

#define CPU_SYS_REGS_RESC_XRSN_Pos     (1U)                                                                            /*!< XRSN Position 1 */
#define CPU_SYS_REGS_RESC_XRSN_Msk     (0x1U << CPU_SYS_REGS_RESC_XRSN_Pos)                                            /*!< XRSN Mask 0x00000002 */
#define CPU_SYS_REGS_RESC_XRSN_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_RESC_XRSN_Pos) & CPU_SYS_REGS_RESC_XRSN_Msk)   /*!< XRSN Set Value */
#define CPU_SYS_REGS_RESC_XRSN_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_RESC_XRSN_Msk) >> CPU_SYS_REGS_RESC_XRSN_Pos)   /*!< XRSN Get Value */

#define CPU_SYS_REGS_RESC_POR_Pos     (0U)                                                                          /*!< POR Position 0 */
#define CPU_SYS_REGS_RESC_POR_Msk     (0x1U << CPU_SYS_REGS_RESC_POR_Pos)                                           /*!< POR Mask 0x00000001 */
#define CPU_SYS_REGS_RESC_POR_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_RESC_POR_Pos) & CPU_SYS_REGS_RESC_POR_Msk)   /*!< POR Set Value */
#define CPU_SYS_REGS_RESC_POR_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_RESC_POR_Msk) >> CPU_SYS_REGS_RESC_POR_Pos)   /*!< POR Get Value */

/* DWTMR2CLKCTL bitfield */
#define CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKPRESCALE_Pos     (3U)                                                                                                                      /*!< DWTMR2CLKPRESCALE Position 3 */
#define CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKPRESCALE_Msk     (0x7U << CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKPRESCALE_Pos)                                                                 /*!< DWTMR2CLKPRESCALE Mask 0x00000038 */
#define CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKPRESCALE_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKPRESCALE_Pos) & CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKPRESCALE_Msk)   /*!< DWTMR2CLKPRESCALE Set Value */
#define CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKPRESCALE_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKPRESCALE_Msk) >> CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKPRESCALE_Pos)   /*!< DWTMR2CLKPRESCALE Get Value */

#define CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKSRCSEL_Pos     (0U)                                                                                                                  /*!< DWTMR2CLKSRCSEL Position 0 */
#define CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKSRCSEL_Msk     (0x7U << CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKSRCSEL_Pos)                                                               /*!< DWTMR2CLKSRCSEL Mask 0x00000007 */
#define CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKSRCSEL_Set(x)  (((uint32_t) (x) << CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKSRCSEL_Pos) & CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKSRCSEL_Msk)   /*!< DWTMR2CLKSRCSEL Set Value */
#define CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKSRCSEL_Get(x)  (((uint32_t) (x) & CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKSRCSEL_Msk) >> CPU_SYS_REGS_DWTMR2CLKCTL_DWTMR2CLKSRCSEL_Pos)   /*!< DWTMR2CLKSRCSEL Get Value */

/* MSGXTEST bitfield */
#define MEM_CFG_REGS_MSGXTEST_TEST_CPUTOCPU_Pos     (0U)                                                                                                      /*!< TEST_CPUTOCPU Position 0 */
#define MEM_CFG_REGS_MSGXTEST_TEST_CPUTOCPU_Msk     (0x3U << MEM_CFG_REGS_MSGXTEST_TEST_CPUTOCPU_Pos)                                                         /*!< TEST_CPUTOCPU Mask 0x00000003 */
#define MEM_CFG_REGS_MSGXTEST_TEST_CPUTOCPU_Set(x)  (((uint32_t) (x) << MEM_CFG_REGS_MSGXTEST_TEST_CPUTOCPU_Pos) & MEM_CFG_REGS_MSGXTEST_TEST_CPUTOCPU_Msk)   /*!< TEST_CPUTOCPU Set Value */
#define MEM_CFG_REGS_MSGXTEST_TEST_CPUTOCPU_Get(x)  (((uint32_t) (x) & MEM_CFG_REGS_MSGXTEST_TEST_CPUTOCPU_Msk) >> MEM_CFG_REGS_MSGXTEST_TEST_CPUTOCPU_Pos)   /*!< TEST_CPUTOCPU Get Value */

/* MSGXINIT bitfield */
#define MEM_CFG_REGS_MSGXINIT_INIT_CPUTOCPU_Pos     (0U)                                                                                                      /*!< INIT_CPUTOCPU Position 0 */
#define MEM_CFG_REGS_MSGXINIT_INIT_CPUTOCPU_Msk     (0x1U << MEM_CFG_REGS_MSGXINIT_INIT_CPUTOCPU_Pos)                                                         /*!< INIT_CPUTOCPU Mask 0x00000001 */
#define MEM_CFG_REGS_MSGXINIT_INIT_CPUTOCPU_Set(x)  (((uint32_t) (x) << MEM_CFG_REGS_MSGXINIT_INIT_CPUTOCPU_Pos) & MEM_CFG_REGS_MSGXINIT_INIT_CPUTOCPU_Msk)   /*!< INIT_CPUTOCPU Set Value */
#define MEM_CFG_REGS_MSGXINIT_INIT_CPUTOCPU_Get(x)  (((uint32_t) (x) & MEM_CFG_REGS_MSGXINIT_INIT_CPUTOCPU_Msk) >> MEM_CFG_REGS_MSGXINIT_INIT_CPUTOCPU_Pos)   /*!< INIT_CPUTOCPU Get Value */

/* MSGXINITDONE bitfield */
#define MEM_CFG_REGS_MSGXINITDONE_INITDONE_CPUTOCPU_Pos     (0U)                                                                                                                      /*!< INITDONE_CPUTOCPU Position 0 */
#define MEM_CFG_REGS_MSGXINITDONE_INITDONE_CPUTOCPU_Msk     (0x1U << MEM_CFG_REGS_MSGXINITDONE_INITDONE_CPUTOCPU_Pos)                                                                 /*!< INITDONE_CPUTOCPU Mask 0x00000001 */
#define MEM_CFG_REGS_MSGXINITDONE_INITDONE_CPUTOCPU_Set(x)  (((uint32_t) (x) << MEM_CFG_REGS_MSGXINITDONE_INITDONE_CPUTOCPU_Pos) & MEM_CFG_REGS_MSGXINITDONE_INITDONE_CPUTOCPU_Msk)   /*!< INITDONE_CPUTOCPU Set Value */
#define MEM_CFG_REGS_MSGXINITDONE_INITDONE_CPUTOCPU_Get(x)  (((uint32_t) (x) & MEM_CFG_REGS_MSGXINITDONE_INITDONE_CPUTOCPU_Msk) >> MEM_CFG_REGS_MSGXINITDONE_INITDONE_CPUTOCPU_Pos)   /*!< INITDONE_CPUTOCPU Get Value */

/* TCMXTEST bitfield */
#define MEM_CFG_REGS_TCMXTEST_TEST_DTCM_Pos     (2U)                                                                                              /*!< TEST_DTCM Position 2 */
#define MEM_CFG_REGS_TCMXTEST_TEST_DTCM_Msk     (0x3U << MEM_CFG_REGS_TCMXTEST_TEST_DTCM_Pos)                                                     /*!< TEST_DTCM Mask 0x0000000C */
#define MEM_CFG_REGS_TCMXTEST_TEST_DTCM_Set(x)  (((uint32_t) (x) << MEM_CFG_REGS_TCMXTEST_TEST_DTCM_Pos) & MEM_CFG_REGS_TCMXTEST_TEST_DTCM_Msk)   /*!< TEST_DTCM Set Value */
#define MEM_CFG_REGS_TCMXTEST_TEST_DTCM_Get(x)  (((uint32_t) (x) & MEM_CFG_REGS_TCMXTEST_TEST_DTCM_Msk) >> MEM_CFG_REGS_TCMXTEST_TEST_DTCM_Pos)   /*!< TEST_DTCM Get Value */

#define MEM_CFG_REGS_TCMXTEST_TEST_ITCM_Pos     (0U)                                                                                              /*!< TEST_ITCM Position 0 */
#define MEM_CFG_REGS_TCMXTEST_TEST_ITCM_Msk     (0x3U << MEM_CFG_REGS_TCMXTEST_TEST_ITCM_Pos)                                                     /*!< TEST_ITCM Mask 0x00000003 */
#define MEM_CFG_REGS_TCMXTEST_TEST_ITCM_Set(x)  (((uint32_t) (x) << MEM_CFG_REGS_TCMXTEST_TEST_ITCM_Pos) & MEM_CFG_REGS_TCMXTEST_TEST_ITCM_Msk)   /*!< TEST_ITCM Set Value */
#define MEM_CFG_REGS_TCMXTEST_TEST_ITCM_Get(x)  (((uint32_t) (x) & MEM_CFG_REGS_TCMXTEST_TEST_ITCM_Msk) >> MEM_CFG_REGS_TCMXTEST_TEST_ITCM_Pos)   /*!< TEST_ITCM Get Value */

/* TCMXINIT bitfield */
#define MEM_CFG_REGS_TCMXINIT_INIT_DTCM_Pos     (1U)                                                                                              /*!< INIT_DTCM Position 1 */
#define MEM_CFG_REGS_TCMXINIT_INIT_DTCM_Msk     (0x1U << MEM_CFG_REGS_TCMXINIT_INIT_DTCM_Pos)                                                     /*!< INIT_DTCM Mask 0x00000002 */
#define MEM_CFG_REGS_TCMXINIT_INIT_DTCM_Set(x)  (((uint32_t) (x) << MEM_CFG_REGS_TCMXINIT_INIT_DTCM_Pos) & MEM_CFG_REGS_TCMXINIT_INIT_DTCM_Msk)   /*!< INIT_DTCM Set Value */
#define MEM_CFG_REGS_TCMXINIT_INIT_DTCM_Get(x)  (((uint32_t) (x) & MEM_CFG_REGS_TCMXINIT_INIT_DTCM_Msk) >> MEM_CFG_REGS_TCMXINIT_INIT_DTCM_Pos)   /*!< INIT_DTCM Get Value */

#define MEM_CFG_REGS_TCMXINIT_INIT_ITCM_Pos     (0U)                                                                                              /*!< INIT_ITCM Position 0 */
#define MEM_CFG_REGS_TCMXINIT_INIT_ITCM_Msk     (0x1U << MEM_CFG_REGS_TCMXINIT_INIT_ITCM_Pos)                                                     /*!< INIT_ITCM Mask 0x00000001 */
#define MEM_CFG_REGS_TCMXINIT_INIT_ITCM_Set(x)  (((uint32_t) (x) << MEM_CFG_REGS_TCMXINIT_INIT_ITCM_Pos) & MEM_CFG_REGS_TCMXINIT_INIT_ITCM_Msk)   /*!< INIT_ITCM Set Value */
#define MEM_CFG_REGS_TCMXINIT_INIT_ITCM_Get(x)  (((uint32_t) (x) & MEM_CFG_REGS_TCMXINIT_INIT_ITCM_Msk) >> MEM_CFG_REGS_TCMXINIT_INIT_ITCM_Pos)   /*!< INIT_ITCM Get Value */

/* TCMXINITDONE bitfield */
#define MEM_CFG_REGS_TCMXINITDONE_INITDONE_DTCM_Pos     (1U)                                                                                                              /*!< INITDONE_DTCM Position 1 */
#define MEM_CFG_REGS_TCMXINITDONE_INITDONE_DTCM_Msk     (0x1U << MEM_CFG_REGS_TCMXINITDONE_INITDONE_DTCM_Pos)                                                             /*!< INITDONE_DTCM Mask 0x00000002 */
#define MEM_CFG_REGS_TCMXINITDONE_INITDONE_DTCM_Set(x)  (((uint32_t) (x) << MEM_CFG_REGS_TCMXINITDONE_INITDONE_DTCM_Pos) & MEM_CFG_REGS_TCMXINITDONE_INITDONE_DTCM_Msk)   /*!< INITDONE_DTCM Set Value */
#define MEM_CFG_REGS_TCMXINITDONE_INITDONE_DTCM_Get(x)  (((uint32_t) (x) & MEM_CFG_REGS_TCMXINITDONE_INITDONE_DTCM_Msk) >> MEM_CFG_REGS_TCMXINITDONE_INITDONE_DTCM_Pos)   /*!< INITDONE_DTCM Get Value */

#define MEM_CFG_REGS_TCMXINITDONE_INITDONE_ITCM_Pos     (0U)                                                                                                              /*!< INITDONE_ITCM Position 0 */
#define MEM_CFG_REGS_TCMXINITDONE_INITDONE_ITCM_Msk     (0x1U << MEM_CFG_REGS_TCMXINITDONE_INITDONE_ITCM_Pos)                                                             /*!< INITDONE_ITCM Mask 0x00000001 */
#define MEM_CFG_REGS_TCMXINITDONE_INITDONE_ITCM_Set(x)  (((uint32_t) (x) << MEM_CFG_REGS_TCMXINITDONE_INITDONE_ITCM_Pos) & MEM_CFG_REGS_TCMXINITDONE_INITDONE_ITCM_Msk)   /*!< INITDONE_ITCM Set Value */
#define MEM_CFG_REGS_TCMXINITDONE_INITDONE_ITCM_Get(x)  (((uint32_t) (x) & MEM_CFG_REGS_TCMXINITDONE_INITDONE_ITCM_Msk) >> MEM_CFG_REGS_TCMXINITDONE_INITDONE_ITCM_Pos)   /*!< INITDONE_ITCM Get Value */

/* NMAVFLG bitfield */
#define ACCESS_PROTECTION_REGS_NMAVFLG_USB_A_DMAWRITE_Pos     (7U)                                                                                                                          /*!< USB_A_DMAWRITE Position 7 */
#define ACCESS_PROTECTION_REGS_NMAVFLG_USB_A_DMAWRITE_Msk     (0x1U << ACCESS_PROTECTION_REGS_NMAVFLG_USB_A_DMAWRITE_Pos)                                                                   /*!< USB_A_DMAWRITE Mask 0x00000080 */
#define ACCESS_PROTECTION_REGS_NMAVFLG_USB_A_DMAWRITE_Set(x)  (((uint32_t) (x) << ACCESS_PROTECTION_REGS_NMAVFLG_USB_A_DMAWRITE_Pos) & ACCESS_PROTECTION_REGS_NMAVFLG_USB_A_DMAWRITE_Msk)   /*!< USB_A_DMAWRITE Set Value */
#define ACCESS_PROTECTION_REGS_NMAVFLG_USB_A_DMAWRITE_Get(x)  (((uint32_t) (x) & ACCESS_PROTECTION_REGS_NMAVFLG_USB_A_DMAWRITE_Msk) >> ACCESS_PROTECTION_REGS_NMAVFLG_USB_A_DMAWRITE_Pos)   /*!< USB_A_DMAWRITE Get Value */

#define ACCESS_PROTECTION_REGS_NMAVFLG_DMAWRITE_Pos     (3U)                                                                                                              /*!< DMAWRITE Position 3 */
#define ACCESS_PROTECTION_REGS_NMAVFLG_DMAWRITE_Msk     (0x1U << ACCESS_PROTECTION_REGS_NMAVFLG_DMAWRITE_Pos)                                                             /*!< DMAWRITE Mask 0x00000008 */
#define ACCESS_PROTECTION_REGS_NMAVFLG_DMAWRITE_Set(x)  (((uint32_t) (x) << ACCESS_PROTECTION_REGS_NMAVFLG_DMAWRITE_Pos) & ACCESS_PROTECTION_REGS_NMAVFLG_DMAWRITE_Msk)   /*!< DMAWRITE Set Value */
#define ACCESS_PROTECTION_REGS_NMAVFLG_DMAWRITE_Get(x)  (((uint32_t) (x) & ACCESS_PROTECTION_REGS_NMAVFLG_DMAWRITE_Msk) >> ACCESS_PROTECTION_REGS_NMAVFLG_DMAWRITE_Pos)   /*!< DMAWRITE Get Value */

#define ACCESS_PROTECTION_REGS_NMAVFLG_CPUWRITE_Pos     (1U)                                                                                                              /*!< CPUWRITE Position 1 */
#define ACCESS_PROTECTION_REGS_NMAVFLG_CPUWRITE_Msk     (0x1U << ACCESS_PROTECTION_REGS_NMAVFLG_CPUWRITE_Pos)                                                             /*!< CPUWRITE Mask 0x00000002 */
#define ACCESS_PROTECTION_REGS_NMAVFLG_CPUWRITE_Set(x)  (((uint32_t) (x) << ACCESS_PROTECTION_REGS_NMAVFLG_CPUWRITE_Pos) & ACCESS_PROTECTION_REGS_NMAVFLG_CPUWRITE_Msk)   /*!< CPUWRITE Set Value */
#define ACCESS_PROTECTION_REGS_NMAVFLG_CPUWRITE_Get(x)  (((uint32_t) (x) & ACCESS_PROTECTION_REGS_NMAVFLG_CPUWRITE_Msk) >> ACCESS_PROTECTION_REGS_NMAVFLG_CPUWRITE_Pos)   /*!< CPUWRITE Get Value */

/* NMAVSET bitfield */
#define ACCESS_PROTECTION_REGS_NMAVSET_USB_A_DMAWRITE_Pos     (7U)                                                                                                                          /*!< USB_A_DMAWRITE Position 7 */
#define ACCESS_PROTECTION_REGS_NMAVSET_USB_A_DMAWRITE_Msk     (0x1U << ACCESS_PROTECTION_REGS_NMAVSET_USB_A_DMAWRITE_Pos)                                                                   /*!< USB_A_DMAWRITE Mask 0x00000080 */
#define ACCESS_PROTECTION_REGS_NMAVSET_USB_A_DMAWRITE_Set(x)  (((uint32_t) (x) << ACCESS_PROTECTION_REGS_NMAVSET_USB_A_DMAWRITE_Pos) & ACCESS_PROTECTION_REGS_NMAVSET_USB_A_DMAWRITE_Msk)   /*!< USB_A_DMAWRITE Set Value */
#define ACCESS_PROTECTION_REGS_NMAVSET_USB_A_DMAWRITE_Get(x)  (((uint32_t) (x) & ACCESS_PROTECTION_REGS_NMAVSET_USB_A_DMAWRITE_Msk) >> ACCESS_PROTECTION_REGS_NMAVSET_USB_A_DMAWRITE_Pos)   /*!< USB_A_DMAWRITE Get Value */

#define ACCESS_PROTECTION_REGS_NMAVSET_DMAWRITE_Pos     (3U)                                                                                                              /*!< DMAWRITE Position 3 */
#define ACCESS_PROTECTION_REGS_NMAVSET_DMAWRITE_Msk     (0x1U << ACCESS_PROTECTION_REGS_NMAVSET_DMAWRITE_Pos)                                                             /*!< DMAWRITE Mask 0x00000008 */
#define ACCESS_PROTECTION_REGS_NMAVSET_DMAWRITE_Set(x)  (((uint32_t) (x) << ACCESS_PROTECTION_REGS_NMAVSET_DMAWRITE_Pos) & ACCESS_PROTECTION_REGS_NMAVSET_DMAWRITE_Msk)   /*!< DMAWRITE Set Value */
#define ACCESS_PROTECTION_REGS_NMAVSET_DMAWRITE_Get(x)  (((uint32_t) (x) & ACCESS_PROTECTION_REGS_NMAVSET_DMAWRITE_Msk) >> ACCESS_PROTECTION_REGS_NMAVSET_DMAWRITE_Pos)   /*!< DMAWRITE Get Value */

#define ACCESS_PROTECTION_REGS_NMAVSET_CPUWRITE_Pos     (1U)                                                                                                              /*!< CPUWRITE Position 1 */
#define ACCESS_PROTECTION_REGS_NMAVSET_CPUWRITE_Msk     (0x1U << ACCESS_PROTECTION_REGS_NMAVSET_CPUWRITE_Pos)                                                             /*!< CPUWRITE Mask 0x00000002 */
#define ACCESS_PROTECTION_REGS_NMAVSET_CPUWRITE_Set(x)  (((uint32_t) (x) << ACCESS_PROTECTION_REGS_NMAVSET_CPUWRITE_Pos) & ACCESS_PROTECTION_REGS_NMAVSET_CPUWRITE_Msk)   /*!< CPUWRITE Set Value */
#define ACCESS_PROTECTION_REGS_NMAVSET_CPUWRITE_Get(x)  (((uint32_t) (x) & ACCESS_PROTECTION_REGS_NMAVSET_CPUWRITE_Msk) >> ACCESS_PROTECTION_REGS_NMAVSET_CPUWRITE_Pos)   /*!< CPUWRITE Get Value */

/* NMAVCLR bitfield */
#define ACCESS_PROTECTION_REGS_NMAVCLR_USB_A_DMAWRITE_Pos     (7U)                                                                                                                          /*!< USB_A_DMAWRITE Position 7 */
#define ACCESS_PROTECTION_REGS_NMAVCLR_USB_A_DMAWRITE_Msk     (0x1U << ACCESS_PROTECTION_REGS_NMAVCLR_USB_A_DMAWRITE_Pos)                                                                   /*!< USB_A_DMAWRITE Mask 0x00000080 */
#define ACCESS_PROTECTION_REGS_NMAVCLR_USB_A_DMAWRITE_Set(x)  (((uint32_t) (x) << ACCESS_PROTECTION_REGS_NMAVCLR_USB_A_DMAWRITE_Pos) & ACCESS_PROTECTION_REGS_NMAVCLR_USB_A_DMAWRITE_Msk)   /*!< USB_A_DMAWRITE Set Value */
#define ACCESS_PROTECTION_REGS_NMAVCLR_USB_A_DMAWRITE_Get(x)  (((uint32_t) (x) & ACCESS_PROTECTION_REGS_NMAVCLR_USB_A_DMAWRITE_Msk) >> ACCESS_PROTECTION_REGS_NMAVCLR_USB_A_DMAWRITE_Pos)   /*!< USB_A_DMAWRITE Get Value */

#define ACCESS_PROTECTION_REGS_NMAVCLR_DMAWRITE_Pos     (3U)                                                                                                              /*!< DMAWRITE Position 3 */
#define ACCESS_PROTECTION_REGS_NMAVCLR_DMAWRITE_Msk     (0x1U << ACCESS_PROTECTION_REGS_NMAVCLR_DMAWRITE_Pos)                                                             /*!< DMAWRITE Mask 0x00000008 */
#define ACCESS_PROTECTION_REGS_NMAVCLR_DMAWRITE_Set(x)  (((uint32_t) (x) << ACCESS_PROTECTION_REGS_NMAVCLR_DMAWRITE_Pos) & ACCESS_PROTECTION_REGS_NMAVCLR_DMAWRITE_Msk)   /*!< DMAWRITE Set Value */
#define ACCESS_PROTECTION_REGS_NMAVCLR_DMAWRITE_Get(x)  (((uint32_t) (x) & ACCESS_PROTECTION_REGS_NMAVCLR_DMAWRITE_Msk) >> ACCESS_PROTECTION_REGS_NMAVCLR_DMAWRITE_Pos)   /*!< DMAWRITE Get Value */

#define ACCESS_PROTECTION_REGS_NMAVCLR_CPUWRITE_Pos     (1U)                                                                                                              /*!< CPUWRITE Position 1 */
#define ACCESS_PROTECTION_REGS_NMAVCLR_CPUWRITE_Msk     (0x1U << ACCESS_PROTECTION_REGS_NMAVCLR_CPUWRITE_Pos)                                                             /*!< CPUWRITE Mask 0x00000002 */
#define ACCESS_PROTECTION_REGS_NMAVCLR_CPUWRITE_Set(x)  (((uint32_t) (x) << ACCESS_PROTECTION_REGS_NMAVCLR_CPUWRITE_Pos) & ACCESS_PROTECTION_REGS_NMAVCLR_CPUWRITE_Msk)   /*!< CPUWRITE Set Value */
#define ACCESS_PROTECTION_REGS_NMAVCLR_CPUWRITE_Get(x)  (((uint32_t) (x) & ACCESS_PROTECTION_REGS_NMAVCLR_CPUWRITE_Msk) >> ACCESS_PROTECTION_REGS_NMAVCLR_CPUWRITE_Pos)   /*!< CPUWRITE Get Value */

/* NMAVINTEN bitfield */
#define ACCESS_PROTECTION_REGS_NMAVINTEN_USB_A_DMAWRITE_Pos     (7U)                                                                                                                              /*!< USB_A_DMAWRITE Position 7 */
#define ACCESS_PROTECTION_REGS_NMAVINTEN_USB_A_DMAWRITE_Msk     (0x1U << ACCESS_PROTECTION_REGS_NMAVINTEN_USB_A_DMAWRITE_Pos)                                                                     /*!< USB_A_DMAWRITE Mask 0x00000080 */
#define ACCESS_PROTECTION_REGS_NMAVINTEN_USB_A_DMAWRITE_Set(x)  (((uint32_t) (x) << ACCESS_PROTECTION_REGS_NMAVINTEN_USB_A_DMAWRITE_Pos) & ACCESS_PROTECTION_REGS_NMAVINTEN_USB_A_DMAWRITE_Msk)   /*!< USB_A_DMAWRITE Set Value */
#define ACCESS_PROTECTION_REGS_NMAVINTEN_USB_A_DMAWRITE_Get(x)  (((uint32_t) (x) & ACCESS_PROTECTION_REGS_NMAVINTEN_USB_A_DMAWRITE_Msk) >> ACCESS_PROTECTION_REGS_NMAVINTEN_USB_A_DMAWRITE_Pos)   /*!< USB_A_DMAWRITE Get Value */

#define ACCESS_PROTECTION_REGS_NMAVINTEN_DMAWRITE_Pos     (3U)                                                                                                                  /*!< DMAWRITE Position 3 */
#define ACCESS_PROTECTION_REGS_NMAVINTEN_DMAWRITE_Msk     (0x1U << ACCESS_PROTECTION_REGS_NMAVINTEN_DMAWRITE_Pos)                                                               /*!< DMAWRITE Mask 0x00000008 */
#define ACCESS_PROTECTION_REGS_NMAVINTEN_DMAWRITE_Set(x)  (((uint32_t) (x) << ACCESS_PROTECTION_REGS_NMAVINTEN_DMAWRITE_Pos) & ACCESS_PROTECTION_REGS_NMAVINTEN_DMAWRITE_Msk)   /*!< DMAWRITE Set Value */
#define ACCESS_PROTECTION_REGS_NMAVINTEN_DMAWRITE_Get(x)  (((uint32_t) (x) & ACCESS_PROTECTION_REGS_NMAVINTEN_DMAWRITE_Msk) >> ACCESS_PROTECTION_REGS_NMAVINTEN_DMAWRITE_Pos)   /*!< DMAWRITE Get Value */

#define ACCESS_PROTECTION_REGS_NMAVINTEN_CPUWRITE_Pos     (1U)                                                                                                                  /*!< CPUWRITE Position 1 */
#define ACCESS_PROTECTION_REGS_NMAVINTEN_CPUWRITE_Msk     (0x1U << ACCESS_PROTECTION_REGS_NMAVINTEN_CPUWRITE_Pos)                                                               /*!< CPUWRITE Mask 0x00000002 */
#define ACCESS_PROTECTION_REGS_NMAVINTEN_CPUWRITE_Set(x)  (((uint32_t) (x) << ACCESS_PROTECTION_REGS_NMAVINTEN_CPUWRITE_Pos) & ACCESS_PROTECTION_REGS_NMAVINTEN_CPUWRITE_Msk)   /*!< CPUWRITE Set Value */
#define ACCESS_PROTECTION_REGS_NMAVINTEN_CPUWRITE_Get(x)  (((uint32_t) (x) & ACCESS_PROTECTION_REGS_NMAVINTEN_CPUWRITE_Msk) >> ACCESS_PROTECTION_REGS_NMAVINTEN_CPUWRITE_Pos)   /*!< CPUWRITE Get Value */

/* NMCPUWRAVADDR bitfield */
#define ACCESS_PROTECTION_REGS_NMCPUWRAVADDR_NMCPUWRAVADDR_Pos     (0U)                                                                                                                                    /*!< NMCPUWRAVADDR Position 0 */
#define ACCESS_PROTECTION_REGS_NMCPUWRAVADDR_NMCPUWRAVADDR_Msk     (0xffffffffU << ACCESS_PROTECTION_REGS_NMCPUWRAVADDR_NMCPUWRAVADDR_Pos)                                                                 /*!< NMCPUWRAVADDR Mask 0xFFFFFFFF */
#define ACCESS_PROTECTION_REGS_NMCPUWRAVADDR_NMCPUWRAVADDR_Set(x)  (((uint32_t) (x) << ACCESS_PROTECTION_REGS_NMCPUWRAVADDR_NMCPUWRAVADDR_Pos) & ACCESS_PROTECTION_REGS_NMCPUWRAVADDR_NMCPUWRAVADDR_Msk)   /*!< NMCPUWRAVADDR Set Value */
#define ACCESS_PROTECTION_REGS_NMCPUWRAVADDR_NMCPUWRAVADDR_Get(x)  (((uint32_t) (x) & ACCESS_PROTECTION_REGS_NMCPUWRAVADDR_NMCPUWRAVADDR_Msk) >> ACCESS_PROTECTION_REGS_NMCPUWRAVADDR_NMCPUWRAVADDR_Pos)   /*!< NMCPUWRAVADDR Get Value */

/* NMDMAWRAVADDR bitfield */
#define ACCESS_PROTECTION_REGS_NMDMAWRAVADDR_NMDMAWRAVADDR_Pos     (0U)                                                                                                                                    /*!< NMDMAWRAVADDR Position 0 */
#define ACCESS_PROTECTION_REGS_NMDMAWRAVADDR_NMDMAWRAVADDR_Msk     (0xffffffffU << ACCESS_PROTECTION_REGS_NMDMAWRAVADDR_NMDMAWRAVADDR_Pos)                                                                 /*!< NMDMAWRAVADDR Mask 0xFFFFFFFF */
#define ACCESS_PROTECTION_REGS_NMDMAWRAVADDR_NMDMAWRAVADDR_Set(x)  (((uint32_t) (x) << ACCESS_PROTECTION_REGS_NMDMAWRAVADDR_NMDMAWRAVADDR_Pos) & ACCESS_PROTECTION_REGS_NMDMAWRAVADDR_NMDMAWRAVADDR_Msk)   /*!< NMDMAWRAVADDR Set Value */
#define ACCESS_PROTECTION_REGS_NMDMAWRAVADDR_NMDMAWRAVADDR_Get(x)  (((uint32_t) (x) & ACCESS_PROTECTION_REGS_NMDMAWRAVADDR_NMDMAWRAVADDR_Msk) >> ACCESS_PROTECTION_REGS_NMDMAWRAVADDR_NMDMAWRAVADDR_Pos)   /*!< NMDMAWRAVADDR Get Value */

/* NMUSBADMAWRAVADDR bitfield */
#define ACCESS_PROTECTION_REGS_NMUSBADMAWRAVADDR_NMUSBADMAWRAVADDR_Pos     (0U)                                                                                                                                                    /*!< NMUSBADMAWRAVADDR Position 0 */
#define ACCESS_PROTECTION_REGS_NMUSBADMAWRAVADDR_NMUSBADMAWRAVADDR_Msk     (0xffffffffU << ACCESS_PROTECTION_REGS_NMUSBADMAWRAVADDR_NMUSBADMAWRAVADDR_Pos)                                                                         /*!< NMUSBADMAWRAVADDR Mask 0xFFFFFFFF */
#define ACCESS_PROTECTION_REGS_NMUSBADMAWRAVADDR_NMUSBADMAWRAVADDR_Set(x)  (((uint32_t) (x) << ACCESS_PROTECTION_REGS_NMUSBADMAWRAVADDR_NMUSBADMAWRAVADDR_Pos) & ACCESS_PROTECTION_REGS_NMUSBADMAWRAVADDR_NMUSBADMAWRAVADDR_Msk)   /*!< NMUSBADMAWRAVADDR Set Value */
#define ACCESS_PROTECTION_REGS_NMUSBADMAWRAVADDR_NMUSBADMAWRAVADDR_Get(x)  (((uint32_t) (x) & ACCESS_PROTECTION_REGS_NMUSBADMAWRAVADDR_NMUSBADMAWRAVADDR_Msk) >> ACCESS_PROTECTION_REGS_NMUSBADMAWRAVADDR_NMUSBADMAWRAVADDR_Pos)   /*!< NMUSBADMAWRAVADDR Get Value */

/* MAVFLG bitfield */
#define ACCESS_PROTECTION_REGS_MAVFLG_DMAWRITE_Pos     (2U)                                                                                                            /*!< DMAWRITE Position 2 */
#define ACCESS_PROTECTION_REGS_MAVFLG_DMAWRITE_Msk     (0x1U << ACCESS_PROTECTION_REGS_MAVFLG_DMAWRITE_Pos)                                                            /*!< DMAWRITE Mask 0x00000004 */
#define ACCESS_PROTECTION_REGS_MAVFLG_DMAWRITE_Set(x)  (((uint32_t) (x) << ACCESS_PROTECTION_REGS_MAVFLG_DMAWRITE_Pos) & ACCESS_PROTECTION_REGS_MAVFLG_DMAWRITE_Msk)   /*!< DMAWRITE Set Value */
#define ACCESS_PROTECTION_REGS_MAVFLG_DMAWRITE_Get(x)  (((uint32_t) (x) & ACCESS_PROTECTION_REGS_MAVFLG_DMAWRITE_Msk) >> ACCESS_PROTECTION_REGS_MAVFLG_DMAWRITE_Pos)   /*!< DMAWRITE Get Value */

#define ACCESS_PROTECTION_REGS_MAVFLG_CPUWRITE_Pos     (1U)                                                                                                            /*!< CPUWRITE Position 1 */
#define ACCESS_PROTECTION_REGS_MAVFLG_CPUWRITE_Msk     (0x1U << ACCESS_PROTECTION_REGS_MAVFLG_CPUWRITE_Pos)                                                            /*!< CPUWRITE Mask 0x00000002 */
#define ACCESS_PROTECTION_REGS_MAVFLG_CPUWRITE_Set(x)  (((uint32_t) (x) << ACCESS_PROTECTION_REGS_MAVFLG_CPUWRITE_Pos) & ACCESS_PROTECTION_REGS_MAVFLG_CPUWRITE_Msk)   /*!< CPUWRITE Set Value */
#define ACCESS_PROTECTION_REGS_MAVFLG_CPUWRITE_Get(x)  (((uint32_t) (x) & ACCESS_PROTECTION_REGS_MAVFLG_CPUWRITE_Msk) >> ACCESS_PROTECTION_REGS_MAVFLG_CPUWRITE_Pos)   /*!< CPUWRITE Get Value */

/* MAVSET bitfield */
#define ACCESS_PROTECTION_REGS_MAVSET_DMAWRITE_Pos     (2U)                                                                                                            /*!< DMAWRITE Position 2 */
#define ACCESS_PROTECTION_REGS_MAVSET_DMAWRITE_Msk     (0x1U << ACCESS_PROTECTION_REGS_MAVSET_DMAWRITE_Pos)                                                            /*!< DMAWRITE Mask 0x00000004 */
#define ACCESS_PROTECTION_REGS_MAVSET_DMAWRITE_Set(x)  (((uint32_t) (x) << ACCESS_PROTECTION_REGS_MAVSET_DMAWRITE_Pos) & ACCESS_PROTECTION_REGS_MAVSET_DMAWRITE_Msk)   /*!< DMAWRITE Set Value */
#define ACCESS_PROTECTION_REGS_MAVSET_DMAWRITE_Get(x)  (((uint32_t) (x) & ACCESS_PROTECTION_REGS_MAVSET_DMAWRITE_Msk) >> ACCESS_PROTECTION_REGS_MAVSET_DMAWRITE_Pos)   /*!< DMAWRITE Get Value */

#define ACCESS_PROTECTION_REGS_MAVSET_CPUWRITE_Pos     (1U)                                                                                                            /*!< CPUWRITE Position 1 */
#define ACCESS_PROTECTION_REGS_MAVSET_CPUWRITE_Msk     (0x1U << ACCESS_PROTECTION_REGS_MAVSET_CPUWRITE_Pos)                                                            /*!< CPUWRITE Mask 0x00000002 */
#define ACCESS_PROTECTION_REGS_MAVSET_CPUWRITE_Set(x)  (((uint32_t) (x) << ACCESS_PROTECTION_REGS_MAVSET_CPUWRITE_Pos) & ACCESS_PROTECTION_REGS_MAVSET_CPUWRITE_Msk)   /*!< CPUWRITE Set Value */
#define ACCESS_PROTECTION_REGS_MAVSET_CPUWRITE_Get(x)  (((uint32_t) (x) & ACCESS_PROTECTION_REGS_MAVSET_CPUWRITE_Msk) >> ACCESS_PROTECTION_REGS_MAVSET_CPUWRITE_Pos)   /*!< CPUWRITE Get Value */

/* MAVCLR bitfield */
#define ACCESS_PROTECTION_REGS_MAVCLR_DMAWRITE_Pos     (2U)                                                                                                            /*!< DMAWRITE Position 2 */
#define ACCESS_PROTECTION_REGS_MAVCLR_DMAWRITE_Msk     (0x1U << ACCESS_PROTECTION_REGS_MAVCLR_DMAWRITE_Pos)                                                            /*!< DMAWRITE Mask 0x00000004 */
#define ACCESS_PROTECTION_REGS_MAVCLR_DMAWRITE_Set(x)  (((uint32_t) (x) << ACCESS_PROTECTION_REGS_MAVCLR_DMAWRITE_Pos) & ACCESS_PROTECTION_REGS_MAVCLR_DMAWRITE_Msk)   /*!< DMAWRITE Set Value */
#define ACCESS_PROTECTION_REGS_MAVCLR_DMAWRITE_Get(x)  (((uint32_t) (x) & ACCESS_PROTECTION_REGS_MAVCLR_DMAWRITE_Msk) >> ACCESS_PROTECTION_REGS_MAVCLR_DMAWRITE_Pos)   /*!< DMAWRITE Get Value */

#define ACCESS_PROTECTION_REGS_MAVCLR_CPUWRITE_Pos     (1U)                                                                                                            /*!< CPUWRITE Position 1 */
#define ACCESS_PROTECTION_REGS_MAVCLR_CPUWRITE_Msk     (0x1U << ACCESS_PROTECTION_REGS_MAVCLR_CPUWRITE_Pos)                                                            /*!< CPUWRITE Mask 0x00000002 */
#define ACCESS_PROTECTION_REGS_MAVCLR_CPUWRITE_Set(x)  (((uint32_t) (x) << ACCESS_PROTECTION_REGS_MAVCLR_CPUWRITE_Pos) & ACCESS_PROTECTION_REGS_MAVCLR_CPUWRITE_Msk)   /*!< CPUWRITE Set Value */
#define ACCESS_PROTECTION_REGS_MAVCLR_CPUWRITE_Get(x)  (((uint32_t) (x) & ACCESS_PROTECTION_REGS_MAVCLR_CPUWRITE_Msk) >> ACCESS_PROTECTION_REGS_MAVCLR_CPUWRITE_Pos)   /*!< CPUWRITE Get Value */

/* MAVINTEN bitfield */
#define ACCESS_PROTECTION_REGS_MAVINTEN_DMAWRITE_Pos     (2U)                                                                                                                /*!< DMAWRITE Position 2 */
#define ACCESS_PROTECTION_REGS_MAVINTEN_DMAWRITE_Msk     (0x1U << ACCESS_PROTECTION_REGS_MAVINTEN_DMAWRITE_Pos)                                                              /*!< DMAWRITE Mask 0x00000004 */
#define ACCESS_PROTECTION_REGS_MAVINTEN_DMAWRITE_Set(x)  (((uint32_t) (x) << ACCESS_PROTECTION_REGS_MAVINTEN_DMAWRITE_Pos) & ACCESS_PROTECTION_REGS_MAVINTEN_DMAWRITE_Msk)   /*!< DMAWRITE Set Value */
#define ACCESS_PROTECTION_REGS_MAVINTEN_DMAWRITE_Get(x)  (((uint32_t) (x) & ACCESS_PROTECTION_REGS_MAVINTEN_DMAWRITE_Msk) >> ACCESS_PROTECTION_REGS_MAVINTEN_DMAWRITE_Pos)   /*!< DMAWRITE Get Value */

#define ACCESS_PROTECTION_REGS_MAVINTEN_CPUWRITE_Pos     (1U)                                                                                                                /*!< CPUWRITE Position 1 */
#define ACCESS_PROTECTION_REGS_MAVINTEN_CPUWRITE_Msk     (0x1U << ACCESS_PROTECTION_REGS_MAVINTEN_CPUWRITE_Pos)                                                              /*!< CPUWRITE Mask 0x00000002 */
#define ACCESS_PROTECTION_REGS_MAVINTEN_CPUWRITE_Set(x)  (((uint32_t) (x) << ACCESS_PROTECTION_REGS_MAVINTEN_CPUWRITE_Pos) & ACCESS_PROTECTION_REGS_MAVINTEN_CPUWRITE_Msk)   /*!< CPUWRITE Set Value */
#define ACCESS_PROTECTION_REGS_MAVINTEN_CPUWRITE_Get(x)  (((uint32_t) (x) & ACCESS_PROTECTION_REGS_MAVINTEN_CPUWRITE_Msk) >> ACCESS_PROTECTION_REGS_MAVINTEN_CPUWRITE_Pos)   /*!< CPUWRITE Get Value */

/* MCPUWRAVADDR bitfield */
#define ACCESS_PROTECTION_REGS_MCPUWRAVADDR_MCPUWRAVADDR_Pos     (0U)                                                                                                                                /*!< MCPUWRAVADDR Position 0 */
#define ACCESS_PROTECTION_REGS_MCPUWRAVADDR_MCPUWRAVADDR_Msk     (0xffffffffU << ACCESS_PROTECTION_REGS_MCPUWRAVADDR_MCPUWRAVADDR_Pos)                                                               /*!< MCPUWRAVADDR Mask 0xFFFFFFFF */
#define ACCESS_PROTECTION_REGS_MCPUWRAVADDR_MCPUWRAVADDR_Set(x)  (((uint32_t) (x) << ACCESS_PROTECTION_REGS_MCPUWRAVADDR_MCPUWRAVADDR_Pos) & ACCESS_PROTECTION_REGS_MCPUWRAVADDR_MCPUWRAVADDR_Msk)   /*!< MCPUWRAVADDR Set Value */
#define ACCESS_PROTECTION_REGS_MCPUWRAVADDR_MCPUWRAVADDR_Get(x)  (((uint32_t) (x) & ACCESS_PROTECTION_REGS_MCPUWRAVADDR_MCPUWRAVADDR_Msk) >> ACCESS_PROTECTION_REGS_MCPUWRAVADDR_MCPUWRAVADDR_Pos)   /*!< MCPUWRAVADDR Get Value */

/* MDMAWRAVADDR bitfield */
#define ACCESS_PROTECTION_REGS_MDMAWRAVADDR_MDMAWRAVADDR_Pos     (0U)                                                                                                                                /*!< MDMAWRAVADDR Position 0 */
#define ACCESS_PROTECTION_REGS_MDMAWRAVADDR_MDMAWRAVADDR_Msk     (0xffffffffU << ACCESS_PROTECTION_REGS_MDMAWRAVADDR_MDMAWRAVADDR_Pos)                                                               /*!< MDMAWRAVADDR Mask 0xFFFFFFFF */
#define ACCESS_PROTECTION_REGS_MDMAWRAVADDR_MDMAWRAVADDR_Set(x)  (((uint32_t) (x) << ACCESS_PROTECTION_REGS_MDMAWRAVADDR_MDMAWRAVADDR_Pos) & ACCESS_PROTECTION_REGS_MDMAWRAVADDR_MDMAWRAVADDR_Msk)   /*!< MDMAWRAVADDR Set Value */
#define ACCESS_PROTECTION_REGS_MDMAWRAVADDR_MDMAWRAVADDR_Get(x)  (((uint32_t) (x) & ACCESS_PROTECTION_REGS_MDMAWRAVADDR_MDMAWRAVADDR_Msk) >> ACCESS_PROTECTION_REGS_MDMAWRAVADDR_MDMAWRAVADDR_Pos)   /*!< MDMAWRAVADDR Get Value */

/* UCERRFLG bitfield */
#define MEMORY_ERROR_REGS_UCERRFLG_USBADMARDERR_Pos     (3U)                                                                                                              /*!< USBADMARDERR Position 3 */
#define MEMORY_ERROR_REGS_UCERRFLG_USBADMARDERR_Msk     (0x1U << MEMORY_ERROR_REGS_UCERRFLG_USBADMARDERR_Pos)                                                             /*!< USBADMARDERR Mask 0x00000008 */
#define MEMORY_ERROR_REGS_UCERRFLG_USBADMARDERR_Set(x)  (((uint32_t) (x) << MEMORY_ERROR_REGS_UCERRFLG_USBADMARDERR_Pos) & MEMORY_ERROR_REGS_UCERRFLG_USBADMARDERR_Msk)   /*!< USBADMARDERR Set Value */
#define MEMORY_ERROR_REGS_UCERRFLG_USBADMARDERR_Get(x)  (((uint32_t) (x) & MEMORY_ERROR_REGS_UCERRFLG_USBADMARDERR_Msk) >> MEMORY_ERROR_REGS_UCERRFLG_USBADMARDERR_Pos)   /*!< USBADMARDERR Get Value */

#define MEMORY_ERROR_REGS_UCERRFLG_DMARDERR_Pos     (1U)                                                                                                      /*!< DMARDERR Position 1 */
#define MEMORY_ERROR_REGS_UCERRFLG_DMARDERR_Msk     (0x1U << MEMORY_ERROR_REGS_UCERRFLG_DMARDERR_Pos)                                                         /*!< DMARDERR Mask 0x00000002 */
#define MEMORY_ERROR_REGS_UCERRFLG_DMARDERR_Set(x)  (((uint32_t) (x) << MEMORY_ERROR_REGS_UCERRFLG_DMARDERR_Pos) & MEMORY_ERROR_REGS_UCERRFLG_DMARDERR_Msk)   /*!< DMARDERR Set Value */
#define MEMORY_ERROR_REGS_UCERRFLG_DMARDERR_Get(x)  (((uint32_t) (x) & MEMORY_ERROR_REGS_UCERRFLG_DMARDERR_Msk) >> MEMORY_ERROR_REGS_UCERRFLG_DMARDERR_Pos)   /*!< DMARDERR Get Value */

#define MEMORY_ERROR_REGS_UCERRFLG_CPURDERR_Pos     (0U)                                                                                                      /*!< CPURDERR Position 0 */
#define MEMORY_ERROR_REGS_UCERRFLG_CPURDERR_Msk     (0x1U << MEMORY_ERROR_REGS_UCERRFLG_CPURDERR_Pos)                                                         /*!< CPURDERR Mask 0x00000001 */
#define MEMORY_ERROR_REGS_UCERRFLG_CPURDERR_Set(x)  (((uint32_t) (x) << MEMORY_ERROR_REGS_UCERRFLG_CPURDERR_Pos) & MEMORY_ERROR_REGS_UCERRFLG_CPURDERR_Msk)   /*!< CPURDERR Set Value */
#define MEMORY_ERROR_REGS_UCERRFLG_CPURDERR_Get(x)  (((uint32_t) (x) & MEMORY_ERROR_REGS_UCERRFLG_CPURDERR_Msk) >> MEMORY_ERROR_REGS_UCERRFLG_CPURDERR_Pos)   /*!< CPURDERR Get Value */

/* UCERRSET bitfield */
#define MEMORY_ERROR_REGS_UCERRSET_USBADMARDERR_Pos     (3U)                                                                                                              /*!< USBADMARDERR Position 3 */
#define MEMORY_ERROR_REGS_UCERRSET_USBADMARDERR_Msk     (0x1U << MEMORY_ERROR_REGS_UCERRSET_USBADMARDERR_Pos)                                                             /*!< USBADMARDERR Mask 0x00000008 */
#define MEMORY_ERROR_REGS_UCERRSET_USBADMARDERR_Set(x)  (((uint32_t) (x) << MEMORY_ERROR_REGS_UCERRSET_USBADMARDERR_Pos) & MEMORY_ERROR_REGS_UCERRSET_USBADMARDERR_Msk)   /*!< USBADMARDERR Set Value */
#define MEMORY_ERROR_REGS_UCERRSET_USBADMARDERR_Get(x)  (((uint32_t) (x) & MEMORY_ERROR_REGS_UCERRSET_USBADMARDERR_Msk) >> MEMORY_ERROR_REGS_UCERRSET_USBADMARDERR_Pos)   /*!< USBADMARDERR Get Value */

#define MEMORY_ERROR_REGS_UCERRSET_DMARDERR_Pos     (1U)                                                                                                      /*!< DMARDERR Position 1 */
#define MEMORY_ERROR_REGS_UCERRSET_DMARDERR_Msk     (0x1U << MEMORY_ERROR_REGS_UCERRSET_DMARDERR_Pos)                                                         /*!< DMARDERR Mask 0x00000002 */
#define MEMORY_ERROR_REGS_UCERRSET_DMARDERR_Set(x)  (((uint32_t) (x) << MEMORY_ERROR_REGS_UCERRSET_DMARDERR_Pos) & MEMORY_ERROR_REGS_UCERRSET_DMARDERR_Msk)   /*!< DMARDERR Set Value */
#define MEMORY_ERROR_REGS_UCERRSET_DMARDERR_Get(x)  (((uint32_t) (x) & MEMORY_ERROR_REGS_UCERRSET_DMARDERR_Msk) >> MEMORY_ERROR_REGS_UCERRSET_DMARDERR_Pos)   /*!< DMARDERR Get Value */

#define MEMORY_ERROR_REGS_UCERRSET_CPURDERR_Pos     (0U)                                                                                                      /*!< CPURDERR Position 0 */
#define MEMORY_ERROR_REGS_UCERRSET_CPURDERR_Msk     (0x1U << MEMORY_ERROR_REGS_UCERRSET_CPURDERR_Pos)                                                         /*!< CPURDERR Mask 0x00000001 */
#define MEMORY_ERROR_REGS_UCERRSET_CPURDERR_Set(x)  (((uint32_t) (x) << MEMORY_ERROR_REGS_UCERRSET_CPURDERR_Pos) & MEMORY_ERROR_REGS_UCERRSET_CPURDERR_Msk)   /*!< CPURDERR Set Value */
#define MEMORY_ERROR_REGS_UCERRSET_CPURDERR_Get(x)  (((uint32_t) (x) & MEMORY_ERROR_REGS_UCERRSET_CPURDERR_Msk) >> MEMORY_ERROR_REGS_UCERRSET_CPURDERR_Pos)   /*!< CPURDERR Get Value */

/* UCERRCLR bitfield */
#define MEMORY_ERROR_REGS_UCERRCLR_USBADMARDERR_Pos     (3U)                                                                                                              /*!< USBADMARDERR Position 3 */
#define MEMORY_ERROR_REGS_UCERRCLR_USBADMARDERR_Msk     (0x1U << MEMORY_ERROR_REGS_UCERRCLR_USBADMARDERR_Pos)                                                             /*!< USBADMARDERR Mask 0x00000008 */
#define MEMORY_ERROR_REGS_UCERRCLR_USBADMARDERR_Set(x)  (((uint32_t) (x) << MEMORY_ERROR_REGS_UCERRCLR_USBADMARDERR_Pos) & MEMORY_ERROR_REGS_UCERRCLR_USBADMARDERR_Msk)   /*!< USBADMARDERR Set Value */
#define MEMORY_ERROR_REGS_UCERRCLR_USBADMARDERR_Get(x)  (((uint32_t) (x) & MEMORY_ERROR_REGS_UCERRCLR_USBADMARDERR_Msk) >> MEMORY_ERROR_REGS_UCERRCLR_USBADMARDERR_Pos)   /*!< USBADMARDERR Get Value */

#define MEMORY_ERROR_REGS_UCERRCLR_DMARDERR_Pos     (1U)                                                                                                      /*!< DMARDERR Position 1 */
#define MEMORY_ERROR_REGS_UCERRCLR_DMARDERR_Msk     (0x1U << MEMORY_ERROR_REGS_UCERRCLR_DMARDERR_Pos)                                                         /*!< DMARDERR Mask 0x00000002 */
#define MEMORY_ERROR_REGS_UCERRCLR_DMARDERR_Set(x)  (((uint32_t) (x) << MEMORY_ERROR_REGS_UCERRCLR_DMARDERR_Pos) & MEMORY_ERROR_REGS_UCERRCLR_DMARDERR_Msk)   /*!< DMARDERR Set Value */
#define MEMORY_ERROR_REGS_UCERRCLR_DMARDERR_Get(x)  (((uint32_t) (x) & MEMORY_ERROR_REGS_UCERRCLR_DMARDERR_Msk) >> MEMORY_ERROR_REGS_UCERRCLR_DMARDERR_Pos)   /*!< DMARDERR Get Value */

#define MEMORY_ERROR_REGS_UCERRCLR_CPURDERR_Pos     (0U)                                                                                                      /*!< CPURDERR Position 0 */
#define MEMORY_ERROR_REGS_UCERRCLR_CPURDERR_Msk     (0x1U << MEMORY_ERROR_REGS_UCERRCLR_CPURDERR_Pos)                                                         /*!< CPURDERR Mask 0x00000001 */
#define MEMORY_ERROR_REGS_UCERRCLR_CPURDERR_Set(x)  (((uint32_t) (x) << MEMORY_ERROR_REGS_UCERRCLR_CPURDERR_Pos) & MEMORY_ERROR_REGS_UCERRCLR_CPURDERR_Msk)   /*!< CPURDERR Set Value */
#define MEMORY_ERROR_REGS_UCERRCLR_CPURDERR_Get(x)  (((uint32_t) (x) & MEMORY_ERROR_REGS_UCERRCLR_CPURDERR_Msk) >> MEMORY_ERROR_REGS_UCERRCLR_CPURDERR_Pos)   /*!< CPURDERR Get Value */

/* UCCPUREADDR bitfield */
#define MEMORY_ERROR_REGS_UCCPUREADDR_UCCPUREADDR_Pos     (0U)                                                                                                                  /*!< UCCPUREADDR Position 0 */
#define MEMORY_ERROR_REGS_UCCPUREADDR_UCCPUREADDR_Msk     (0xffffffffU << MEMORY_ERROR_REGS_UCCPUREADDR_UCCPUREADDR_Pos)                                                        /*!< UCCPUREADDR Mask 0xFFFFFFFF */
#define MEMORY_ERROR_REGS_UCCPUREADDR_UCCPUREADDR_Set(x)  (((uint32_t) (x) << MEMORY_ERROR_REGS_UCCPUREADDR_UCCPUREADDR_Pos) & MEMORY_ERROR_REGS_UCCPUREADDR_UCCPUREADDR_Msk)   /*!< UCCPUREADDR Set Value */
#define MEMORY_ERROR_REGS_UCCPUREADDR_UCCPUREADDR_Get(x)  (((uint32_t) (x) & MEMORY_ERROR_REGS_UCCPUREADDR_UCCPUREADDR_Msk) >> MEMORY_ERROR_REGS_UCCPUREADDR_UCCPUREADDR_Pos)   /*!< UCCPUREADDR Get Value */

/* UCDMAREADDR bitfield */
#define MEMORY_ERROR_REGS_UCDMAREADDR_UCDMAREADDR_Pos     (0U)                                                                                                                  /*!< UCDMAREADDR Position 0 */
#define MEMORY_ERROR_REGS_UCDMAREADDR_UCDMAREADDR_Msk     (0xffffffffU << MEMORY_ERROR_REGS_UCDMAREADDR_UCDMAREADDR_Pos)                                                        /*!< UCDMAREADDR Mask 0xFFFFFFFF */
#define MEMORY_ERROR_REGS_UCDMAREADDR_UCDMAREADDR_Set(x)  (((uint32_t) (x) << MEMORY_ERROR_REGS_UCDMAREADDR_UCDMAREADDR_Pos) & MEMORY_ERROR_REGS_UCDMAREADDR_UCDMAREADDR_Msk)   /*!< UCDMAREADDR Set Value */
#define MEMORY_ERROR_REGS_UCDMAREADDR_UCDMAREADDR_Get(x)  (((uint32_t) (x) & MEMORY_ERROR_REGS_UCDMAREADDR_UCDMAREADDR_Msk) >> MEMORY_ERROR_REGS_UCDMAREADDR_UCDMAREADDR_Pos)   /*!< UCDMAREADDR Get Value */

/* UCUSBADMAREADDR bitfield */
#define MEMORY_ERROR_REGS_UCUSBADMAREADDR_UCUSBADMAREADDR_Pos     (0U)                                                                                                                                  /*!< UCUSBADMAREADDR Position 0 */
#define MEMORY_ERROR_REGS_UCUSBADMAREADDR_UCUSBADMAREADDR_Msk     (0xffffffffU << MEMORY_ERROR_REGS_UCUSBADMAREADDR_UCUSBADMAREADDR_Pos)                                                                /*!< UCUSBADMAREADDR Mask 0xFFFFFFFF */
#define MEMORY_ERROR_REGS_UCUSBADMAREADDR_UCUSBADMAREADDR_Set(x)  (((uint32_t) (x) << MEMORY_ERROR_REGS_UCUSBADMAREADDR_UCUSBADMAREADDR_Pos) & MEMORY_ERROR_REGS_UCUSBADMAREADDR_UCUSBADMAREADDR_Msk)   /*!< UCUSBADMAREADDR Set Value */
#define MEMORY_ERROR_REGS_UCUSBADMAREADDR_UCUSBADMAREADDR_Get(x)  (((uint32_t) (x) & MEMORY_ERROR_REGS_UCUSBADMAREADDR_UCUSBADMAREADDR_Msk) >> MEMORY_ERROR_REGS_UCUSBADMAREADDR_UCUSBADMAREADDR_Pos)   /*!< UCUSBADMAREADDR Get Value */

/* CERRFLG bitfield */
#define MEMORY_ERROR_REGS_CERRFLG_USBADMARDERR_Pos     (3U)                                                                                                            /*!< USBADMARDERR Position 3 */
#define MEMORY_ERROR_REGS_CERRFLG_USBADMARDERR_Msk     (0x1U << MEMORY_ERROR_REGS_CERRFLG_USBADMARDERR_Pos)                                                            /*!< USBADMARDERR Mask 0x00000008 */
#define MEMORY_ERROR_REGS_CERRFLG_USBADMARDERR_Set(x)  (((uint32_t) (x) << MEMORY_ERROR_REGS_CERRFLG_USBADMARDERR_Pos) & MEMORY_ERROR_REGS_CERRFLG_USBADMARDERR_Msk)   /*!< USBADMARDERR Set Value */
#define MEMORY_ERROR_REGS_CERRFLG_USBADMARDERR_Get(x)  (((uint32_t) (x) & MEMORY_ERROR_REGS_CERRFLG_USBADMARDERR_Msk) >> MEMORY_ERROR_REGS_CERRFLG_USBADMARDERR_Pos)   /*!< USBADMARDERR Get Value */

#define MEMORY_ERROR_REGS_CERRFLG_DMARDERR_Pos     (1U)                                                                                                    /*!< DMARDERR Position 1 */
#define MEMORY_ERROR_REGS_CERRFLG_DMARDERR_Msk     (0x1U << MEMORY_ERROR_REGS_CERRFLG_DMARDERR_Pos)                                                        /*!< DMARDERR Mask 0x00000002 */
#define MEMORY_ERROR_REGS_CERRFLG_DMARDERR_Set(x)  (((uint32_t) (x) << MEMORY_ERROR_REGS_CERRFLG_DMARDERR_Pos) & MEMORY_ERROR_REGS_CERRFLG_DMARDERR_Msk)   /*!< DMARDERR Set Value */
#define MEMORY_ERROR_REGS_CERRFLG_DMARDERR_Get(x)  (((uint32_t) (x) & MEMORY_ERROR_REGS_CERRFLG_DMARDERR_Msk) >> MEMORY_ERROR_REGS_CERRFLG_DMARDERR_Pos)   /*!< DMARDERR Get Value */

#define MEMORY_ERROR_REGS_CERRFLG_CPURDERR_Pos     (0U)                                                                                                    /*!< CPURDERR Position 0 */
#define MEMORY_ERROR_REGS_CERRFLG_CPURDERR_Msk     (0x1U << MEMORY_ERROR_REGS_CERRFLG_CPURDERR_Pos)                                                        /*!< CPURDERR Mask 0x00000001 */
#define MEMORY_ERROR_REGS_CERRFLG_CPURDERR_Set(x)  (((uint32_t) (x) << MEMORY_ERROR_REGS_CERRFLG_CPURDERR_Pos) & MEMORY_ERROR_REGS_CERRFLG_CPURDERR_Msk)   /*!< CPURDERR Set Value */
#define MEMORY_ERROR_REGS_CERRFLG_CPURDERR_Get(x)  (((uint32_t) (x) & MEMORY_ERROR_REGS_CERRFLG_CPURDERR_Msk) >> MEMORY_ERROR_REGS_CERRFLG_CPURDERR_Pos)   /*!< CPURDERR Get Value */

/* CERRSET bitfield */
#define MEMORY_ERROR_REGS_CERRSET_USBADMARDERR_Pos     (3U)                                                                                                            /*!< USBADMARDERR Position 3 */
#define MEMORY_ERROR_REGS_CERRSET_USBADMARDERR_Msk     (0x1U << MEMORY_ERROR_REGS_CERRSET_USBADMARDERR_Pos)                                                            /*!< USBADMARDERR Mask 0x00000008 */
#define MEMORY_ERROR_REGS_CERRSET_USBADMARDERR_Set(x)  (((uint32_t) (x) << MEMORY_ERROR_REGS_CERRSET_USBADMARDERR_Pos) & MEMORY_ERROR_REGS_CERRSET_USBADMARDERR_Msk)   /*!< USBADMARDERR Set Value */
#define MEMORY_ERROR_REGS_CERRSET_USBADMARDERR_Get(x)  (((uint32_t) (x) & MEMORY_ERROR_REGS_CERRSET_USBADMARDERR_Msk) >> MEMORY_ERROR_REGS_CERRSET_USBADMARDERR_Pos)   /*!< USBADMARDERR Get Value */

#define MEMORY_ERROR_REGS_CERRSET_DMARDERR_Pos     (1U)                                                                                                    /*!< DMARDERR Position 1 */
#define MEMORY_ERROR_REGS_CERRSET_DMARDERR_Msk     (0x1U << MEMORY_ERROR_REGS_CERRSET_DMARDERR_Pos)                                                        /*!< DMARDERR Mask 0x00000002 */
#define MEMORY_ERROR_REGS_CERRSET_DMARDERR_Set(x)  (((uint32_t) (x) << MEMORY_ERROR_REGS_CERRSET_DMARDERR_Pos) & MEMORY_ERROR_REGS_CERRSET_DMARDERR_Msk)   /*!< DMARDERR Set Value */
#define MEMORY_ERROR_REGS_CERRSET_DMARDERR_Get(x)  (((uint32_t) (x) & MEMORY_ERROR_REGS_CERRSET_DMARDERR_Msk) >> MEMORY_ERROR_REGS_CERRSET_DMARDERR_Pos)   /*!< DMARDERR Get Value */

#define MEMORY_ERROR_REGS_CERRSET_CPURDERR_Pos     (0U)                                                                                                    /*!< CPURDERR Position 0 */
#define MEMORY_ERROR_REGS_CERRSET_CPURDERR_Msk     (0x1U << MEMORY_ERROR_REGS_CERRSET_CPURDERR_Pos)                                                        /*!< CPURDERR Mask 0x00000001 */
#define MEMORY_ERROR_REGS_CERRSET_CPURDERR_Set(x)  (((uint32_t) (x) << MEMORY_ERROR_REGS_CERRSET_CPURDERR_Pos) & MEMORY_ERROR_REGS_CERRSET_CPURDERR_Msk)   /*!< CPURDERR Set Value */
#define MEMORY_ERROR_REGS_CERRSET_CPURDERR_Get(x)  (((uint32_t) (x) & MEMORY_ERROR_REGS_CERRSET_CPURDERR_Msk) >> MEMORY_ERROR_REGS_CERRSET_CPURDERR_Pos)   /*!< CPURDERR Get Value */

/* CERRCLR bitfield */
#define MEMORY_ERROR_REGS_CERRCLR_USBADMARDERR_Pos     (3U)                                                                                                            /*!< USBADMARDERR Position 3 */
#define MEMORY_ERROR_REGS_CERRCLR_USBADMARDERR_Msk     (0x1U << MEMORY_ERROR_REGS_CERRCLR_USBADMARDERR_Pos)                                                            /*!< USBADMARDERR Mask 0x00000008 */
#define MEMORY_ERROR_REGS_CERRCLR_USBADMARDERR_Set(x)  (((uint32_t) (x) << MEMORY_ERROR_REGS_CERRCLR_USBADMARDERR_Pos) & MEMORY_ERROR_REGS_CERRCLR_USBADMARDERR_Msk)   /*!< USBADMARDERR Set Value */
#define MEMORY_ERROR_REGS_CERRCLR_USBADMARDERR_Get(x)  (((uint32_t) (x) & MEMORY_ERROR_REGS_CERRCLR_USBADMARDERR_Msk) >> MEMORY_ERROR_REGS_CERRCLR_USBADMARDERR_Pos)   /*!< USBADMARDERR Get Value */

#define MEMORY_ERROR_REGS_CERRCLR_DMARDERR_Pos     (1U)                                                                                                    /*!< DMARDERR Position 1 */
#define MEMORY_ERROR_REGS_CERRCLR_DMARDERR_Msk     (0x1U << MEMORY_ERROR_REGS_CERRCLR_DMARDERR_Pos)                                                        /*!< DMARDERR Mask 0x00000002 */
#define MEMORY_ERROR_REGS_CERRCLR_DMARDERR_Set(x)  (((uint32_t) (x) << MEMORY_ERROR_REGS_CERRCLR_DMARDERR_Pos) & MEMORY_ERROR_REGS_CERRCLR_DMARDERR_Msk)   /*!< DMARDERR Set Value */
#define MEMORY_ERROR_REGS_CERRCLR_DMARDERR_Get(x)  (((uint32_t) (x) & MEMORY_ERROR_REGS_CERRCLR_DMARDERR_Msk) >> MEMORY_ERROR_REGS_CERRCLR_DMARDERR_Pos)   /*!< DMARDERR Get Value */

#define MEMORY_ERROR_REGS_CERRCLR_CPURDERR_Pos     (0U)                                                                                                    /*!< CPURDERR Position 0 */
#define MEMORY_ERROR_REGS_CERRCLR_CPURDERR_Msk     (0x1U << MEMORY_ERROR_REGS_CERRCLR_CPURDERR_Pos)                                                        /*!< CPURDERR Mask 0x00000001 */
#define MEMORY_ERROR_REGS_CERRCLR_CPURDERR_Set(x)  (((uint32_t) (x) << MEMORY_ERROR_REGS_CERRCLR_CPURDERR_Pos) & MEMORY_ERROR_REGS_CERRCLR_CPURDERR_Msk)   /*!< CPURDERR Set Value */
#define MEMORY_ERROR_REGS_CERRCLR_CPURDERR_Get(x)  (((uint32_t) (x) & MEMORY_ERROR_REGS_CERRCLR_CPURDERR_Msk) >> MEMORY_ERROR_REGS_CERRCLR_CPURDERR_Pos)   /*!< CPURDERR Get Value */

/* CCPUREADDR bitfield */
#define MEMORY_ERROR_REGS_CCPUREADDR_CCPUREADDR_Pos     (0U)                                                                                                              /*!< CCPUREADDR Position 0 */
#define MEMORY_ERROR_REGS_CCPUREADDR_CCPUREADDR_Msk     (0xffffffffU << MEMORY_ERROR_REGS_CCPUREADDR_CCPUREADDR_Pos)                                                      /*!< CCPUREADDR Mask 0xFFFFFFFF */
#define MEMORY_ERROR_REGS_CCPUREADDR_CCPUREADDR_Set(x)  (((uint32_t) (x) << MEMORY_ERROR_REGS_CCPUREADDR_CCPUREADDR_Pos) & MEMORY_ERROR_REGS_CCPUREADDR_CCPUREADDR_Msk)   /*!< CCPUREADDR Set Value */
#define MEMORY_ERROR_REGS_CCPUREADDR_CCPUREADDR_Get(x)  (((uint32_t) (x) & MEMORY_ERROR_REGS_CCPUREADDR_CCPUREADDR_Msk) >> MEMORY_ERROR_REGS_CCPUREADDR_CCPUREADDR_Pos)   /*!< CCPUREADDR Get Value */

/* CDMAREADDR bitfield */
#define MEMORY_ERROR_REGS_CDMAREADDR_CDMAREADDR_Pos     (0U)                                                                                                              /*!< CDMAREADDR Position 0 */
#define MEMORY_ERROR_REGS_CDMAREADDR_CDMAREADDR_Msk     (0xffffffffU << MEMORY_ERROR_REGS_CDMAREADDR_CDMAREADDR_Pos)                                                      /*!< CDMAREADDR Mask 0xFFFFFFFF */
#define MEMORY_ERROR_REGS_CDMAREADDR_CDMAREADDR_Set(x)  (((uint32_t) (x) << MEMORY_ERROR_REGS_CDMAREADDR_CDMAREADDR_Pos) & MEMORY_ERROR_REGS_CDMAREADDR_CDMAREADDR_Msk)   /*!< CDMAREADDR Set Value */
#define MEMORY_ERROR_REGS_CDMAREADDR_CDMAREADDR_Get(x)  (((uint32_t) (x) & MEMORY_ERROR_REGS_CDMAREADDR_CDMAREADDR_Msk) >> MEMORY_ERROR_REGS_CDMAREADDR_CDMAREADDR_Pos)   /*!< CDMAREADDR Get Value */

/* CUSBADMAREADDR bitfield */
#define MEMORY_ERROR_REGS_CUSBADMAREADDR_CUSBADMAREADDR_Pos     (0U)                                                                                                                              /*!< CUSBADMAREADDR Position 0 */
#define MEMORY_ERROR_REGS_CUSBADMAREADDR_CUSBADMAREADDR_Msk     (0xffffffffU << MEMORY_ERROR_REGS_CUSBADMAREADDR_CUSBADMAREADDR_Pos)                                                              /*!< CUSBADMAREADDR Mask 0xFFFFFFFF */
#define MEMORY_ERROR_REGS_CUSBADMAREADDR_CUSBADMAREADDR_Set(x)  (((uint32_t) (x) << MEMORY_ERROR_REGS_CUSBADMAREADDR_CUSBADMAREADDR_Pos) & MEMORY_ERROR_REGS_CUSBADMAREADDR_CUSBADMAREADDR_Msk)   /*!< CUSBADMAREADDR Set Value */
#define MEMORY_ERROR_REGS_CUSBADMAREADDR_CUSBADMAREADDR_Get(x)  (((uint32_t) (x) & MEMORY_ERROR_REGS_CUSBADMAREADDR_CUSBADMAREADDR_Msk) >> MEMORY_ERROR_REGS_CUSBADMAREADDR_CUSBADMAREADDR_Pos)   /*!< CUSBADMAREADDR Get Value */

/* CERRCNT bitfield */
#define MEMORY_ERROR_REGS_CERRCNT_CERRCNT_Pos     (0U)                                                                                                  /*!< CERRCNT Position 0 */
#define MEMORY_ERROR_REGS_CERRCNT_CERRCNT_Msk     (0xffffffffU << MEMORY_ERROR_REGS_CERRCNT_CERRCNT_Pos)                                                /*!< CERRCNT Mask 0xFFFFFFFF */
#define MEMORY_ERROR_REGS_CERRCNT_CERRCNT_Set(x)  (((uint32_t) (x) << MEMORY_ERROR_REGS_CERRCNT_CERRCNT_Pos) & MEMORY_ERROR_REGS_CERRCNT_CERRCNT_Msk)   /*!< CERRCNT Set Value */
#define MEMORY_ERROR_REGS_CERRCNT_CERRCNT_Get(x)  (((uint32_t) (x) & MEMORY_ERROR_REGS_CERRCNT_CERRCNT_Msk) >> MEMORY_ERROR_REGS_CERRCNT_CERRCNT_Pos)   /*!< CERRCNT Get Value */

/* CERRTHRES bitfield */
#define MEMORY_ERROR_REGS_CERRTHRES_CERRTHRES_Pos     (0U)                                                                                                          /*!< CERRTHRES Position 0 */
#define MEMORY_ERROR_REGS_CERRTHRES_CERRTHRES_Msk     (0xffffffffU << MEMORY_ERROR_REGS_CERRTHRES_CERRTHRES_Pos)                                                    /*!< CERRTHRES Mask 0xFFFFFFFF */
#define MEMORY_ERROR_REGS_CERRTHRES_CERRTHRES_Set(x)  (((uint32_t) (x) << MEMORY_ERROR_REGS_CERRTHRES_CERRTHRES_Pos) & MEMORY_ERROR_REGS_CERRTHRES_CERRTHRES_Msk)   /*!< CERRTHRES Set Value */
#define MEMORY_ERROR_REGS_CERRTHRES_CERRTHRES_Get(x)  (((uint32_t) (x) & MEMORY_ERROR_REGS_CERRTHRES_CERRTHRES_Msk) >> MEMORY_ERROR_REGS_CERRTHRES_CERRTHRES_Pos)   /*!< CERRTHRES Get Value */

/* CEINTFLG bitfield */
#define MEMORY_ERROR_REGS_CEINTFLG_CEINTFLAG_Pos     (0U)                                                                                                        /*!< CEINTFLAG Position 0 */
#define MEMORY_ERROR_REGS_CEINTFLG_CEINTFLAG_Msk     (0x1U << MEMORY_ERROR_REGS_CEINTFLG_CEINTFLAG_Pos)                                                          /*!< CEINTFLAG Mask 0x00000001 */
#define MEMORY_ERROR_REGS_CEINTFLG_CEINTFLAG_Set(x)  (((uint32_t) (x) << MEMORY_ERROR_REGS_CEINTFLG_CEINTFLAG_Pos) & MEMORY_ERROR_REGS_CEINTFLG_CEINTFLAG_Msk)   /*!< CEINTFLAG Set Value */
#define MEMORY_ERROR_REGS_CEINTFLG_CEINTFLAG_Get(x)  (((uint32_t) (x) & MEMORY_ERROR_REGS_CEINTFLG_CEINTFLAG_Msk) >> MEMORY_ERROR_REGS_CEINTFLG_CEINTFLAG_Pos)   /*!< CEINTFLAG Get Value */

/* CEINTCLR bitfield */
#define MEMORY_ERROR_REGS_CEINTCLR_CEINTCLR_Pos     (0U)                                                                                                      /*!< CEINTCLR Position 0 */
#define MEMORY_ERROR_REGS_CEINTCLR_CEINTCLR_Msk     (0x1U << MEMORY_ERROR_REGS_CEINTCLR_CEINTCLR_Pos)                                                         /*!< CEINTCLR Mask 0x00000001 */
#define MEMORY_ERROR_REGS_CEINTCLR_CEINTCLR_Set(x)  (((uint32_t) (x) << MEMORY_ERROR_REGS_CEINTCLR_CEINTCLR_Pos) & MEMORY_ERROR_REGS_CEINTCLR_CEINTCLR_Msk)   /*!< CEINTCLR Set Value */
#define MEMORY_ERROR_REGS_CEINTCLR_CEINTCLR_Get(x)  (((uint32_t) (x) & MEMORY_ERROR_REGS_CEINTCLR_CEINTCLR_Msk) >> MEMORY_ERROR_REGS_CEINTCLR_CEINTCLR_Pos)   /*!< CEINTCLR Get Value */

/* CEINTSET bitfield */
#define MEMORY_ERROR_REGS_CEINTSET_CEINTSET_Pos     (0U)                                                                                                      /*!< CEINTSET Position 0 */
#define MEMORY_ERROR_REGS_CEINTSET_CEINTSET_Msk     (0x1U << MEMORY_ERROR_REGS_CEINTSET_CEINTSET_Pos)                                                         /*!< CEINTSET Mask 0x00000001 */
#define MEMORY_ERROR_REGS_CEINTSET_CEINTSET_Set(x)  (((uint32_t) (x) << MEMORY_ERROR_REGS_CEINTSET_CEINTSET_Pos) & MEMORY_ERROR_REGS_CEINTSET_CEINTSET_Msk)   /*!< CEINTSET Set Value */
#define MEMORY_ERROR_REGS_CEINTSET_CEINTSET_Get(x)  (((uint32_t) (x) & MEMORY_ERROR_REGS_CEINTSET_CEINTSET_Msk) >> MEMORY_ERROR_REGS_CEINTSET_CEINTSET_Pos)   /*!< CEINTSET Get Value */

/* CEINTEN bitfield */
#define MEMORY_ERROR_REGS_CEINTEN_CEINTEN_Pos     (0U)                                                                                                  /*!< CEINTEN Position 0 */
#define MEMORY_ERROR_REGS_CEINTEN_CEINTEN_Msk     (0x1U << MEMORY_ERROR_REGS_CEINTEN_CEINTEN_Pos)                                                       /*!< CEINTEN Mask 0x00000001 */
#define MEMORY_ERROR_REGS_CEINTEN_CEINTEN_Set(x)  (((uint32_t) (x) << MEMORY_ERROR_REGS_CEINTEN_CEINTEN_Pos) & MEMORY_ERROR_REGS_CEINTEN_CEINTEN_Msk)   /*!< CEINTEN Set Value */
#define MEMORY_ERROR_REGS_CEINTEN_CEINTEN_Get(x)  (((uint32_t) (x) & MEMORY_ERROR_REGS_CEINTEN_CEINTEN_Msk) >> MEMORY_ERROR_REGS_CEINTEN_CEINTEN_Pos)   /*!< CEINTEN Get Value */

/* CERRINTEN bitfield */
#define MEMORY_ERROR_REGS_CERRINTEN_USBADMARDERRINTEN_Pos     (3U)                                                                                                                          /*!< USBADMARDERRINTEN Position 3 */
#define MEMORY_ERROR_REGS_CERRINTEN_USBADMARDERRINTEN_Msk     (0x1U << MEMORY_ERROR_REGS_CERRINTEN_USBADMARDERRINTEN_Pos)                                                                   /*!< USBADMARDERRINTEN Mask 0x00000008 */
#define MEMORY_ERROR_REGS_CERRINTEN_USBADMARDERRINTEN_Set(x)  (((uint32_t) (x) << MEMORY_ERROR_REGS_CERRINTEN_USBADMARDERRINTEN_Pos) & MEMORY_ERROR_REGS_CERRINTEN_USBADMARDERRINTEN_Msk)   /*!< USBADMARDERRINTEN Set Value */
#define MEMORY_ERROR_REGS_CERRINTEN_USBADMARDERRINTEN_Get(x)  (((uint32_t) (x) & MEMORY_ERROR_REGS_CERRINTEN_USBADMARDERRINTEN_Msk) >> MEMORY_ERROR_REGS_CERRINTEN_USBADMARDERRINTEN_Pos)   /*!< USBADMARDERRINTEN Get Value */

#define MEMORY_ERROR_REGS_CERRINTEN_DMARDERRINTEN_Pos     (1U)                                                                                                                  /*!< DMARDERRINTEN Position 1 */
#define MEMORY_ERROR_REGS_CERRINTEN_DMARDERRINTEN_Msk     (0x1U << MEMORY_ERROR_REGS_CERRINTEN_DMARDERRINTEN_Pos)                                                               /*!< DMARDERRINTEN Mask 0x00000002 */
#define MEMORY_ERROR_REGS_CERRINTEN_DMARDERRINTEN_Set(x)  (((uint32_t) (x) << MEMORY_ERROR_REGS_CERRINTEN_DMARDERRINTEN_Pos) & MEMORY_ERROR_REGS_CERRINTEN_DMARDERRINTEN_Msk)   /*!< DMARDERRINTEN Set Value */
#define MEMORY_ERROR_REGS_CERRINTEN_DMARDERRINTEN_Get(x)  (((uint32_t) (x) & MEMORY_ERROR_REGS_CERRINTEN_DMARDERRINTEN_Msk) >> MEMORY_ERROR_REGS_CERRINTEN_DMARDERRINTEN_Pos)   /*!< DMARDERRINTEN Get Value */

#define MEMORY_ERROR_REGS_CERRINTEN_CPURDERRINTEN_Pos     (0U)                                                                                                                  /*!< CPURDERRINTEN Position 0 */
#define MEMORY_ERROR_REGS_CERRINTEN_CPURDERRINTEN_Msk     (0x1U << MEMORY_ERROR_REGS_CERRINTEN_CPURDERRINTEN_Pos)                                                               /*!< CPURDERRINTEN Mask 0x00000001 */
#define MEMORY_ERROR_REGS_CERRINTEN_CPURDERRINTEN_Set(x)  (((uint32_t) (x) << MEMORY_ERROR_REGS_CERRINTEN_CPURDERRINTEN_Pos) & MEMORY_ERROR_REGS_CERRINTEN_CPURDERRINTEN_Msk)   /*!< CPURDERRINTEN Set Value */
#define MEMORY_ERROR_REGS_CERRINTEN_CPURDERRINTEN_Get(x)  (((uint32_t) (x) & MEMORY_ERROR_REGS_CERRINTEN_CPURDERRINTEN_Msk) >> MEMORY_ERROR_REGS_CERRINTEN_CPURDERRINTEN_Pos)   /*!< CPURDERRINTEN Get Value */

/* UCERRINTEN bitfield */
#define MEMORY_ERROR_REGS_UCERRINTEN_USBADMARDERRINTEN_Pos     (3U)                                                                                                                            /*!< USBADMARDERRINTEN Position 3 */
#define MEMORY_ERROR_REGS_UCERRINTEN_USBADMARDERRINTEN_Msk     (0x1U << MEMORY_ERROR_REGS_UCERRINTEN_USBADMARDERRINTEN_Pos)                                                                    /*!< USBADMARDERRINTEN Mask 0x00000008 */
#define MEMORY_ERROR_REGS_UCERRINTEN_USBADMARDERRINTEN_Set(x)  (((uint32_t) (x) << MEMORY_ERROR_REGS_UCERRINTEN_USBADMARDERRINTEN_Pos) & MEMORY_ERROR_REGS_UCERRINTEN_USBADMARDERRINTEN_Msk)   /*!< USBADMARDERRINTEN Set Value */
#define MEMORY_ERROR_REGS_UCERRINTEN_USBADMARDERRINTEN_Get(x)  (((uint32_t) (x) & MEMORY_ERROR_REGS_UCERRINTEN_USBADMARDERRINTEN_Msk) >> MEMORY_ERROR_REGS_UCERRINTEN_USBADMARDERRINTEN_Pos)   /*!< USBADMARDERRINTEN Get Value */

#define MEMORY_ERROR_REGS_UCERRINTEN_DMARDERRINTEN_Pos     (1U)                                                                                                                    /*!< DMARDERRINTEN Position 1 */
#define MEMORY_ERROR_REGS_UCERRINTEN_DMARDERRINTEN_Msk     (0x1U << MEMORY_ERROR_REGS_UCERRINTEN_DMARDERRINTEN_Pos)                                                                /*!< DMARDERRINTEN Mask 0x00000002 */
#define MEMORY_ERROR_REGS_UCERRINTEN_DMARDERRINTEN_Set(x)  (((uint32_t) (x) << MEMORY_ERROR_REGS_UCERRINTEN_DMARDERRINTEN_Pos) & MEMORY_ERROR_REGS_UCERRINTEN_DMARDERRINTEN_Msk)   /*!< DMARDERRINTEN Set Value */
#define MEMORY_ERROR_REGS_UCERRINTEN_DMARDERRINTEN_Get(x)  (((uint32_t) (x) & MEMORY_ERROR_REGS_UCERRINTEN_DMARDERRINTEN_Msk) >> MEMORY_ERROR_REGS_UCERRINTEN_DMARDERRINTEN_Pos)   /*!< DMARDERRINTEN Get Value */

#define MEMORY_ERROR_REGS_UCERRINTEN_CPURDERRINTEN_Pos     (0U)                                                                                                                    /*!< CPURDERRINTEN Position 0 */
#define MEMORY_ERROR_REGS_UCERRINTEN_CPURDERRINTEN_Msk     (0x1U << MEMORY_ERROR_REGS_UCERRINTEN_CPURDERRINTEN_Pos)                                                                /*!< CPURDERRINTEN Mask 0x00000001 */
#define MEMORY_ERROR_REGS_UCERRINTEN_CPURDERRINTEN_Set(x)  (((uint32_t) (x) << MEMORY_ERROR_REGS_UCERRINTEN_CPURDERRINTEN_Pos) & MEMORY_ERROR_REGS_UCERRINTEN_CPURDERRINTEN_Msk)   /*!< CPURDERRINTEN Set Value */
#define MEMORY_ERROR_REGS_UCERRINTEN_CPURDERRINTEN_Get(x)  (((uint32_t) (x) & MEMORY_ERROR_REGS_UCERRINTEN_CPURDERRINTEN_Msk) >> MEMORY_ERROR_REGS_UCERRINTEN_CPURDERRINTEN_Pos)   /*!< CPURDERRINTEN Get Value */

/* CPUID bitfield */
#define CPU_ID_REGS_CPUID_CPUID_Pos     (0U)                                                                              /*!< CPUID Position 0 */
#define CPU_ID_REGS_CPUID_CPUID_Msk     (0xffU << CPU_ID_REGS_CPUID_CPUID_Pos)                                            /*!< CPUID Mask 0x000000FF */
#define CPU_ID_REGS_CPUID_CPUID_Set(x)  (((uint32_t) (x) << CPU_ID_REGS_CPUID_CPUID_Pos) & CPU_ID_REGS_CPUID_CPUID_Msk)   /*!< CPUID Set Value */
#define CPU_ID_REGS_CPUID_CPUID_Get(x)  (((uint32_t) (x) & CPU_ID_REGS_CPUID_CPUID_Msk) >> CPU_ID_REGS_CPUID_CPUID_Pos)   /*!< CPUID Get Value */

/* DUMMY_REG0 bitfield */
#define DUMMY_REGS_DUMMY_REG0_DUMMY_REG_Pos     (0U)                                                                                              /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG0_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG0_DUMMY_REG_Pos)                                              /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG0_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG0_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG0_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG0_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG0_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG0_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG1 bitfield */
#define DUMMY_REGS_DUMMY_REG1_DUMMY_REG_Pos     (0U)                                                                                              /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG1_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG1_DUMMY_REG_Pos)                                              /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG1_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG1_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG1_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG1_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG1_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG1_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG2 bitfield */
#define DUMMY_REGS_DUMMY_REG2_DUMMY_REG_Pos     (0U)                                                                                              /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG2_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG2_DUMMY_REG_Pos)                                              /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG2_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG2_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG2_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG2_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG2_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG2_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG3 bitfield */
#define DUMMY_REGS_DUMMY_REG3_DUMMY_REG_Pos     (0U)                                                                                              /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG3_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG3_DUMMY_REG_Pos)                                              /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG3_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG3_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG3_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG3_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG3_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG3_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG4 bitfield */
#define DUMMY_REGS_DUMMY_REG4_DUMMY_REG_Pos     (0U)                                                                                              /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG4_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG4_DUMMY_REG_Pos)                                              /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG4_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG4_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG4_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG4_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG4_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG4_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG5 bitfield */
#define DUMMY_REGS_DUMMY_REG5_DUMMY_REG_Pos     (0U)                                                                                              /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG5_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG5_DUMMY_REG_Pos)                                              /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG5_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG5_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG5_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG5_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG5_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG5_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG6 bitfield */
#define DUMMY_REGS_DUMMY_REG6_DUMMY_REG_Pos     (0U)                                                                                              /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG6_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG6_DUMMY_REG_Pos)                                              /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG6_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG6_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG6_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG6_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG6_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG6_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG7 bitfield */
#define DUMMY_REGS_DUMMY_REG7_DUMMY_REG_Pos     (0U)                                                                                              /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG7_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG7_DUMMY_REG_Pos)                                              /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG7_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG7_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG7_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG7_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG7_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG7_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG8 bitfield */
#define DUMMY_REGS_DUMMY_REG8_DUMMY_REG_Pos     (0U)                                                                                              /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG8_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG8_DUMMY_REG_Pos)                                              /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG8_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG8_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG8_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG8_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG8_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG8_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG9 bitfield */
#define DUMMY_REGS_DUMMY_REG9_DUMMY_REG_Pos     (0U)                                                                                              /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG9_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG9_DUMMY_REG_Pos)                                              /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG9_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG9_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG9_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG9_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG9_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG9_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG10 bitfield */
#define DUMMY_REGS_DUMMY_REG10_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG10_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG10_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG10_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG10_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG10_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG10_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG10_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG10_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG11 bitfield */
#define DUMMY_REGS_DUMMY_REG11_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG11_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG11_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG11_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG11_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG11_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG11_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG11_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG11_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG12 bitfield */
#define DUMMY_REGS_DUMMY_REG12_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG12_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG12_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG12_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG12_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG12_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG12_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG12_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG12_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG13 bitfield */
#define DUMMY_REGS_DUMMY_REG13_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG13_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG13_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG13_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG13_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG13_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG13_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG13_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG13_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG14 bitfield */
#define DUMMY_REGS_DUMMY_REG14_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG14_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG14_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG14_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG14_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG14_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG14_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG14_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG14_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG15 bitfield */
#define DUMMY_REGS_DUMMY_REG15_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG15_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG15_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG15_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG15_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG15_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG15_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG15_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG15_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG16 bitfield */
#define DUMMY_REGS_DUMMY_REG16_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG16_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG16_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG16_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG16_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG16_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG16_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG16_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG16_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG17 bitfield */
#define DUMMY_REGS_DUMMY_REG17_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG17_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG17_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG17_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG17_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG17_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG17_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG17_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG17_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG18 bitfield */
#define DUMMY_REGS_DUMMY_REG18_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG18_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG18_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG18_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG18_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG18_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG18_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG18_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG18_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG19 bitfield */
#define DUMMY_REGS_DUMMY_REG19_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG19_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG19_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG19_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG19_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG19_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG19_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG19_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG19_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG20 bitfield */
#define DUMMY_REGS_DUMMY_REG20_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG20_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG20_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG20_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG20_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG20_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG20_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG20_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG20_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG21 bitfield */
#define DUMMY_REGS_DUMMY_REG21_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG21_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG21_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG21_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG21_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG21_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG21_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG21_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG21_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG22 bitfield */
#define DUMMY_REGS_DUMMY_REG22_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG22_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG22_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG22_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG22_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG22_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG22_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG22_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG22_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG23 bitfield */
#define DUMMY_REGS_DUMMY_REG23_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG23_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG23_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG23_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG23_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG23_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG23_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG23_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG23_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG24 bitfield */
#define DUMMY_REGS_DUMMY_REG24_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG24_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG24_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG24_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG24_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG24_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG24_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG24_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG24_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG25 bitfield */
#define DUMMY_REGS_DUMMY_REG25_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG25_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG25_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG25_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG25_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG25_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG25_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG25_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG25_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG26 bitfield */
#define DUMMY_REGS_DUMMY_REG26_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG26_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG26_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG26_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG26_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG26_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG26_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG26_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG26_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG27 bitfield */
#define DUMMY_REGS_DUMMY_REG27_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG27_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG27_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG27_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG27_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG27_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG27_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG27_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG27_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG28 bitfield */
#define DUMMY_REGS_DUMMY_REG28_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG28_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG28_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG28_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG28_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG28_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG28_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG28_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG28_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG29 bitfield */
#define DUMMY_REGS_DUMMY_REG29_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG29_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG29_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG29_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG29_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG29_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG29_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG29_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG29_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG30 bitfield */
#define DUMMY_REGS_DUMMY_REG30_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG30_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG30_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG30_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG30_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG30_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG30_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG30_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG30_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG31 bitfield */
#define DUMMY_REGS_DUMMY_REG31_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG31_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG31_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG31_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG31_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG31_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG31_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG31_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG31_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG32 bitfield */
#define DUMMY_REGS_DUMMY_REG32_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG32_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG32_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG32_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG32_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG32_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG32_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG32_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG32_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG33 bitfield */
#define DUMMY_REGS_DUMMY_REG33_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG33_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG33_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG33_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG33_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG33_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG33_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG33_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG33_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG34 bitfield */
#define DUMMY_REGS_DUMMY_REG34_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG34_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG34_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG34_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG34_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG34_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG34_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG34_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG34_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG35 bitfield */
#define DUMMY_REGS_DUMMY_REG35_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG35_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG35_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG35_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG35_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG35_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG35_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG35_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG35_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG36 bitfield */
#define DUMMY_REGS_DUMMY_REG36_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG36_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG36_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG36_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG36_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG36_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG36_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG36_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG36_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG37 bitfield */
#define DUMMY_REGS_DUMMY_REG37_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG37_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG37_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG37_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG37_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG37_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG37_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG37_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG37_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG38 bitfield */
#define DUMMY_REGS_DUMMY_REG38_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG38_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG38_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG38_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG38_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG38_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG38_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG38_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG38_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG39 bitfield */
#define DUMMY_REGS_DUMMY_REG39_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG39_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG39_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG39_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG39_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG39_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG39_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG39_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG39_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG40 bitfield */
#define DUMMY_REGS_DUMMY_REG40_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG40_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG40_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG40_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG40_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG40_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG40_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG40_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG40_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG41 bitfield */
#define DUMMY_REGS_DUMMY_REG41_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG41_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG41_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG41_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG41_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG41_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG41_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG41_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG41_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG42 bitfield */
#define DUMMY_REGS_DUMMY_REG42_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG42_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG42_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG42_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG42_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG42_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG42_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG42_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG42_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG43 bitfield */
#define DUMMY_REGS_DUMMY_REG43_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG43_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG43_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG43_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG43_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG43_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG43_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG43_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG43_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG44 bitfield */
#define DUMMY_REGS_DUMMY_REG44_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG44_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG44_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG44_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG44_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG44_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG44_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG44_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG44_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG45 bitfield */
#define DUMMY_REGS_DUMMY_REG45_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG45_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG45_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG45_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG45_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG45_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG45_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG45_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG45_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG46 bitfield */
#define DUMMY_REGS_DUMMY_REG46_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG46_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG46_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG46_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG46_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG46_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG46_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG46_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG46_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG47 bitfield */
#define DUMMY_REGS_DUMMY_REG47_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG47_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG47_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG47_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG47_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG47_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG47_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG47_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG47_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG48 bitfield */
#define DUMMY_REGS_DUMMY_REG48_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG48_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG48_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG48_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG48_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG48_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG48_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG48_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG48_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG49 bitfield */
#define DUMMY_REGS_DUMMY_REG49_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG49_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG49_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG49_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG49_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG49_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG49_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG49_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG49_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG50 bitfield */
#define DUMMY_REGS_DUMMY_REG50_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG50_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG50_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG50_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG50_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG50_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG50_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG50_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG50_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG51 bitfield */
#define DUMMY_REGS_DUMMY_REG51_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG51_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG51_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG51_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG51_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG51_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG51_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG51_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG51_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG52 bitfield */
#define DUMMY_REGS_DUMMY_REG52_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG52_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG52_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG52_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG52_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG52_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG52_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG52_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG52_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG53 bitfield */
#define DUMMY_REGS_DUMMY_REG53_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG53_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG53_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG53_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG53_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG53_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG53_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG53_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG53_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG54 bitfield */
#define DUMMY_REGS_DUMMY_REG54_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG54_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG54_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG54_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG54_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG54_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG54_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG54_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG54_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG55 bitfield */
#define DUMMY_REGS_DUMMY_REG55_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG55_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG55_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG55_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG55_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG55_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG55_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG55_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG55_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG56 bitfield */
#define DUMMY_REGS_DUMMY_REG56_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG56_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG56_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG56_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG56_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG56_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG56_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG56_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG56_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG57 bitfield */
#define DUMMY_REGS_DUMMY_REG57_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG57_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG57_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG57_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG57_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG57_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG57_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG57_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG57_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG58 bitfield */
#define DUMMY_REGS_DUMMY_REG58_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG58_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG58_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG58_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG58_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG58_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG58_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG58_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG58_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG59 bitfield */
#define DUMMY_REGS_DUMMY_REG59_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG59_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG59_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG59_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG59_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG59_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG59_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG59_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG59_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG60 bitfield */
#define DUMMY_REGS_DUMMY_REG60_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG60_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG60_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG60_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG60_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG60_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG60_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG60_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG60_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG61 bitfield */
#define DUMMY_REGS_DUMMY_REG61_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG61_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG61_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG61_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG61_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG61_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG61_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG61_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG61_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG62 bitfield */
#define DUMMY_REGS_DUMMY_REG62_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG62_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG62_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG62_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG62_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG62_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG62_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG62_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG62_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/* DUMMY_REG63 bitfield */
#define DUMMY_REGS_DUMMY_REG63_DUMMY_REG_Pos     (0U)                                                                                                /*!< DUMMY_REG Position 0 */
#define DUMMY_REGS_DUMMY_REG63_DUMMY_REG_Msk     (0xffffffffU << DUMMY_REGS_DUMMY_REG63_DUMMY_REG_Pos)                                               /*!< DUMMY_REG Mask 0xFFFFFFFF */
#define DUMMY_REGS_DUMMY_REG63_DUMMY_REG_Set(x)  (((uint32_t) (x) << DUMMY_REGS_DUMMY_REG63_DUMMY_REG_Pos) & DUMMY_REGS_DUMMY_REG63_DUMMY_REG_Msk)   /*!< DUMMY_REG Set Value */
#define DUMMY_REGS_DUMMY_REG63_DUMMY_REG_Get(x)  (((uint32_t) (x) & DUMMY_REGS_DUMMY_REG63_DUMMY_REG_Msk) >> DUMMY_REGS_DUMMY_REG63_DUMMY_REG_Pos)   /*!< DUMMY_REG Get Value */

/*!
 * @}
 */

/* clang-format on */

/*!
 * @}
 */ /* end of HS32F7D377_SYSCTRL_CPU2_REGISTER */

#endif /* HS32F7D377_SYSCTRL_CPU2_H */
