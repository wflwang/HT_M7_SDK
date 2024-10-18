/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


/*!
 * \file   HS32F7D377_adc.h
 * \brief  HS32F7D377 ADC register file
 * \version V1.0_20231009
 */

#ifndef HS32F7D377_ADC_H
#define HS32F7D377_ADC_H

/*!
 * \addtogroup   HS32F7D377_ADC_REGISTER HS32F7D377 ADC Register
 * \ingroup HS32F7D377_REGISTER
 *
 * \brief  ADC register layout, bitfield and address definitions
 *
 * @{
 */

/* clang-format off */

/*!
 * \name ADC Register Layout
 *
 *
 * @{
 */

/*! \brief ADC register */
typedef struct {
    union
    {
        __IOM uint16_t ADCCTL1                           ;  /*!< 0x00000000 : ADC Control 1 Register */
    
        struct
        {
                  uint16_t RSV_0                     : 2 ;  /*!< [ 1: 0] : reserved. */
            __IOM uint16_t INTPULSEPOS               : 1 ;  /*!< [ 2: 2] : ADC Interrupt Pulse Position.
                                                                           0 Interrupt pulse generation occurs when ADC begins conversion (at
                                                                           the end of the acquisition window) plus a number of SYSCLK cycles
                                                                           as specified in the ADCINTCYCLE.delay register.
                                                                           1 Interrupt pulse generation occurs at the end of the conversion, 1
                                                                           cycle prior to the ADC result latching into its result register
                                                                           Reset type: SYSRSn */
                  uint16_t RSV_1                     : 4 ;  /*!< [ 6: 3] : reserved. */
            __IOM uint16_t ADCPWDNZ                  : 1 ;  /*!< [ 7: 7] : ADC Power Down (active low). This bit controls the power up and
                                                                           power down of all the analog circuitry inside the analog core.
                                                                           0 All analog circuitry inside the core is powered down
                                                                           1 All analog circuitry inside the core is powered up
                                                                           Reset type: SYSRSn */
            __IM  uint16_t ADCBSYCHN                 : 4 ;  /*!< [11: 8] : ADC Busy Channel. Set when an ADC Start of Conversion (SOC) is
                                                                           generated.
                                                                           When ADCBSY=0: holds the value of the last converted SOC
                                                                           When ADCBSY=1: reflects the SOC currently being processed
                                                                           0h SOC0 is currently processing or was last SOC converted
                                                                           1h SOC1 is currently processing or was last SOC converted
                                                                           2h SOC2 is currently processing or was last SOC converted
                                                                           3h SOC3 is currently processing or was last SOC converted
                                                                           4h SOC4 is currently processing or was last SOC converted
                                                                           5h SOC5 is currently processing or was last SOC converted
                                                                           6h SOC6 is currently processing or was last SOC converted
                                                                           7h SOC7 is currently processing or was last SOC converted
                                                                           8h SOC8 is currently processing or was last SOC converted
                                                                           9h SOC9 is currently processing or was last SOC converted
                                                                           Ah SOC10 is currently processing or was last SOC converted
                                                                           Bh SOC11 is currently processing or was last SOC converted
                                                                           Ch SOC12 is currently processing or was last SOC converted
                                                                           Dh SOC13 is currently processing or was last SOC converted
                                                                           Eh SOC14 is currently processing or was last SOC converted
                                                                           Fh SOC15 is currently processing or was last SOC converted
                                                                           Reset type: SYSRSn */
                  uint16_t RSV_2                     : 1 ;  /*!< [12:12] : reserved. */
            __IM  uint16_t ADCBSY                    : 1 ;  /*!< [13:13] : ADC Busy. Set when ADC SOC is generated, cleared by hardware
                                                                           four ADC clocks after negative edge of S/H pulse. Used by the ADC
                                                                           state machine to determine if ADC is available to sample.
                                                                           0 ADC is available to sample next channel
                                                                           1 ADC is busy and cannot sample another channel
                                                                           Reset type: SYSRSn */
                  uint16_t RSV_3                     : 2 ;  /*!< [15:14] : reserved. */
        } ADCCTL1b;
    };

    union
    {
        __IOM uint16_t ADCCTL2                           ;  /*!< 0x00000002 : ADC Control 2 Register */
    
        struct
        {
                  uint16_t RSV_0                     : 6 ;  /*!< [ 5: 0] : reserved. */
            __IOM uint16_t RESOLUTION                : 1 ;  /*!< [ 6: 6] : SOC Conversion Resolution. Selects the resolution of the converter. Use the AdcSetMode function to change the resolution.
                                                                           0 12-bit resolution
                                                                           1 16-bit resolution Reset type: SYSRSn */
            __IOM uint16_t SIGNALMODE                : 1 ;  /*!< [ 7: 7] : SOC Signaling Mode. Selects the input mode of the converter. Use the AdcSetMode function to change the signal mode.
                                                                           0 Single-ended
                                                                           1 Differential
                                                                           Reset type: SYSRSn */
                  uint16_t RSV_1                     : 8 ;  /*!< [15: 8] : reserved. */
        } ADCCTL2b;
    };

    union
    {
        __IOM uint16_t ADCBURSTCTL                       ;  /*!< 0x00000004 : ADC Burst Control Register */
    
        struct
        {
            __IOM uint16_t BURSTTRIGSEL              : 6 ;  /*!< [ 5: 0] : SOC Burst Trigger Source Select. Configures which trigger will start a burst conversion sequence.
                                                                           00h BURSTTRIG0 - Software only
                                                                           01h BURSTTRIG1 - CPU1 Timer 0, TINT0n
                                                                           02h BURSTTRIG2 - CPU1 Timer 1, TINT1n
                                                                           03h BURSTTRIG3 - CPU1 Timer 2, TINT2n
                                                                           04h BURSTTRIG4 - GPIO, Input X-Bar INPUT5
                                                                           05h BURSTTRIG5 - ePWM1, ADCSOCA
                                                                           06h BURSTTRIG6 - ePWM1, ADCSOCB
                                                                           07h BURSTTRIG7 - ePWM2, ADCSOCA
                                                                           08h BURSTTRIG8 - ePWM2, ADCSOCB
                                                                           09h BURSTTRIG9 - ePWM3, ADCSOCA
                                                                           0Ah BURSTTRIG10 - ePWM3, ADCSOCB
                                                                           0Bh BURSTTRIG11 - ePWM4, ADCSOCA
                                                                           0Ch BURSTTRIG12 - ePWM4, ADCSOCB
                                                                           0Dh BURSTTRIG13 - ePWM5, ADCSOCA
                                                                           0Eh BURSTTRIG14 - ePWM5, ADCSOCB
                                                                           0Fh BURSTTRIG15 - ePWM6, ADCSOCA
                                                                           10h BURSTTRIG16 - ePWM6, ADCSOCB
                                                                           11h BURSTTRIG17 - ePWM7, ADCSOCA
                                                                           12h BURSTTRIG18 - ePWM7, ADCSOCB
                                                                           13h BURSTTRIG19 - ePWM8, ADCSOCA
                                                                           14h BURSTTRIG20 - ePWM8, ADCSOCB
                                                                           15h BURSTTRIG21 - ePWM9, ADCSOCA
                                                                           16h BURSTTRIG22 - ePWM9, ADCSOCB
                                                                           17h BURSTTRIG23 - ePWM10, ADCSOCA
                                                                           18h BURSTTRIG24 - ePWM10, ADCSOCB
                                                                           19h BURSTTRIG25 - ePWM11, ADCSOCA
                                                                           1Ah BURSTTRIG26 - ePWM11, ADCSOCB
                                                                           1Bh BURSTTRIG27 - ePWM12, ADCSOCA
                                                                           1Ch BURSTTRIG28 - ePWM12, ADCSOCB
                                                                           1Dh BURSTTRIG29 - CPU2 Timer 0, TINT0n
                                                                           1Eh BURSTTRIG30 - CPU2 Timer 1, TINT1n
                                                                           1Fh BURSTTRIG31 - CPU2 Timer 2, TINT2n
                                                                           20h - 3Fh - Reserved Reset type: SYSRSn */
                  uint16_t RSV_0                     : 2 ;  /*!< [ 7: 6] : reserved. */
            __IOM uint16_t BURSTSIZE                 : 4 ;  /*!< [11: 8] : SOC Burst Size Select. This bit field determines how many SOCs are converted when a burst conversion sequence is started. The first SOC converted is defined by the round robin pointer, which is advanced as each SOC is converted.
                                                                           0h 1 SOC converted 1h 2 SOCs converted 2h 3 SOCs converted 3h 4 SOCs converted 4h 5 SOCs converted 5h 6 SOCs converted 6h 7 SOCs converted 7h 8 SOCs converted 8h 9 SOCs converted 9h 10 SOCs converted Ah 11 SOCs converted Bh 12 SOCs converted Ch 13 SOCs converted Dh 14 SOCs converted Eh 15 SOCs converted Fh 16 SOCs converted
                                                                           Reset type: SYSRSn */
                  uint16_t RSV_1                     : 3 ;  /*!< [14:12] : reserved. */
            __IOM uint16_t BURSTEN                   : 1 ;  /*!< [15:15] : SOC Burst Mode Enable. This bit enables the SOC Burst Mode of operation.
                                                                           0 Burst mode is disabled.
                                                                           1 Burst mode is enabled. Reset type: SYSRSn */
        } ADCBURSTCTLb;
    };

    union
    {
        __IM  uint16_t ADCINTFLG                         ;  /*!< 0x00000006 : ADC Interrupt Flag Register */
    
        struct
        {
            __IM  uint16_t ADCINT1                   : 1 ;  /*!< [ 0: 0] : ADC Interrupt 1 Flag. Reading these flags indicates if the associated ADCINT pulse was generated since the last clear.
                                                                           0 No ADC interrupt pulse generated 1 ADC interrupt pulse generated
                                                                           If the ADC interrupt is placed in continue to interrupt mode (INTSELxNy register) then further interrupt pulses are generated whenever a selected EOC event occurs even if the flag bit is set. If the continuous mode is not enabled, then no further interrupt pulses are generated until the user clears this flag bit using the ADCINFLGCLR register. Rather, an ADC interrupt overflow event occurs in the ADCINTOVF register.
                                                                           Reset type: SYSRSn */
            __IM  uint16_t ADCINT2                   : 1 ;  /*!< [ 1: 1] : ADC Interrupt 2 Flag. Reading these flags indicates if the associated ADCINT pulse was generated since the last clear.
                                                                           0 No ADC interrupt pulse generated 1 ADC interrupt pulse generated
                                                                           If the ADC interrupt is placed in continue to interrupt mode (INTSELxNy register) then further interrupt pulses are generated whenever a selected EOC event occurs even if the flag bit is set. If the continuous mode is not enabled, then no further interrupt pulses are generated until the user clears this flag bit using the ADCINFLGCLR register. Rather, an ADC interrupt overflow event occurs in the ADCINTOVF register.
                                                                           Reset type: SYSRSn */
            __IM  uint16_t ADCINT3                   : 1 ;  /*!< [ 2: 2] : ADC Interrupt 3 Flag. Reading these flags indicates if the associated ADCINT pulse was generated since the last clear.
                                                                           0 No ADC interrupt pulse generated 1 ADC interrupt pulse generated
                                                                           If the ADC interrupt is placed in continue to interrupt mode (INTSELxNy register) then further interrupt pulses are generated whenever a selected EOC event occurs even if the flag bit is set. If the continuous mode is not enabled, then no further interrupt pulses are generated until the user clears this flag bit using the ADCINFLGCLR register. Rather, an ADC interrupt overflow event occurs in the ADCINTOVF register.
                                                                           Reset type: SYSRSn */
            __IM  uint16_t ADCINT4                   : 1 ;  /*!< [ 3: 3] : ADC Interrupt 4 Flag. Reading these flags indicates if the associated ADCINT pulse was generated since the last clear.
                                                                           0 No ADC interrupt pulse generated 1 ADC interrupt pulse generated
                                                                           If the ADC interrupt is placed in continue to interrupt mode (INTSELxNy register) then further interrupt pulses are generated whenever a selected EOC event occurs even if the flag bit is set. If the continuous mode is not enabled, then no further interrupt pulses are generated until the user clears this flag bit using the ADCINFLGCLR register. Rather, an ADC interrupt overflow event occurs in the ADCINTOVF register.
                                                                           Reset type: SYSRSn */
                  uint16_t RSV_0                     : 12;  /*!< [15: 4] : reserved. */
        } ADCINTFLGb;
    };

    union
    {
        __IOM uint16_t ADCINTFLGCLR                      ;  /*!< 0x00000008 : ADC Interrupt Flag Clear Register */
    
        struct
        {
            __IOM uint16_t ADCINT1                   : 1 ;  /*!< [ 0: 0] : ADC Interrupt 1 Flag Clear. Reads return 0.
                                                                           0 No action
                                                                           1 Clears respective flag bit in the ADCINTFLG register. If software sets the clear bit on the same cycle that hardware is trying to set the flag bit, then hardware has priority but the overflow bit will not be affected (retains current state)
                                                                           Boundary condition: If hardware is trying to set the bit flag while software tries to clear the bit in the same cycle, the following will take place:
                                                                           1. SW has prioirity and will clear the flag
                                                                           2. HW set will be discarded
                                                                           no signal will propagate to the PIE from the latch
                                                                           3. Overflow flag/condition will be generated Reset type: SYSRSn */
            __IOM uint16_t ADCINT2                   : 1 ;  /*!< [ 1: 1] : ADC Interrupt 2 Flag Clear. Reads return 0.
                                                                           0 No action
                                                                           1 Clears respective flag bit in the ADCINTFLG register. If software sets the clear bit on the same cycle that hardware is trying to set the flag bit, then hardware has priority but the overflow bit will not be affected (retains current state)
                                                                           Boundary condition: If hardware is trying to set the bit flag while software tries to clear the bit in the same cycle, the following will take place:
                                                                           1. SW has prioirity and will clear the flag
                                                                           2. HW set will be discarded
                                                                           no signal will propagate to the PIE from the latch
                                                                           3. Overflow flag/condition will be generated Reset type: SYSRSn */
            __IOM uint16_t ADCINT3                   : 1 ;  /*!< [ 2: 2] : ADC Interrupt 3 Flag Clear. Reads return 0.
                                                                           0 No action
                                                                           1 Clears respective flag bit in the ADCINTFLG register. If software sets the clear bit on the same cycle that hardware is trying to set the flag bit, then hardware has priority but the overflow bit will not be affected (retains current state)
                                                                           Boundary condition: If hardware is trying to set the bit flag while software tries to clear the bit in the same cycle, the following will take place:
                                                                           1. SW has prioirity and will clear the flag
                                                                           2. HW set will be discarded
                                                                           no signal will propagate to the PIE from the latch
                                                                           3. Overflow flag/condition will be generated Reset type: SYSRSn */
            __IOM uint16_t ADCINT4                   : 1 ;  /*!< [ 3: 3] : ADC Interrupt 4 Flag Clear. Reads return 0.
                                                                           0 No action
                                                                           1 Clears respective flag bit in the ADCINTFLG register. If software sets the clear bit on the same cycle that hardware is trying to set the flag bit, then hardware has priority but the overflow bit will not be affected (retains current state)
                                                                           Boundary condition: If hardware is trying to set the bit flag while software tries to clear the bit in the same cycle, the following will take place:
                                                                           1. SW has prioirity and will clear the flag
                                                                           2. HW set will be discarded
                                                                           no signal will propagate to the PIE from the latch
                                                                           3. Overflow flag/condition will be generated Reset type: SYSRSn */
                  uint16_t RSV_0                     : 12;  /*!< [15: 4] : reserved. */
        } ADCINTFLGCLRb;
    };

    union
    {
        __IM  uint16_t ADCINTOVF                         ;  /*!< 0x0000000a : ADC Interrupt Overflow Register */
    
        struct
        {
            __IM  uint16_t ADCINT1                   : 1 ;  /*!< [ 0: 0] : ADC Interrupt 1 Overflow Flags
                                                                           Indicates if an overflow occurred when generating ADCINT pulses. If the respective ADCINTFLG bit is set and a selected additional EOC trigger is generated, then an overflow condition occurs.
                                                                           0 No ADC interrupt overflow event detected. 1 ADC Interrupt overflow event detected.
                                                                           The overflow bit does not care about the continuous mode bit state. An overflow condition is generated irrespective of this mode selection.
                                                                           Reset type: SYSRSn */
            __IM  uint16_t ADCINT2                   : 1 ;  /*!< [ 1: 1] : ADC Interrupt 2 Overflow Flags
                                                                           Indicates if an overflow occurred when generating ADCINT pulses. If the respective ADCINTFLG bit is set and a selected additional EOC trigger is generated, then an overflow condition occurs.
                                                                           0 No ADC interrupt overflow event detected. 1 ADC Interrupt overflow event detected.
                                                                           The overflow bit does not care about the continuous mode bit state. An overflow condition is generated irrespective of this mode selection.
                                                                           Reset type: SYSRSn */
            __IM  uint16_t ADCINT3                   : 1 ;  /*!< [ 2: 2] : ADC Interrupt 3 Overflow Flags
                                                                           Indicates if an overflow occurred when generating ADCINT pulses. If the respective ADCINTFLG bit is set and a selected additional EOC trigger is generated, then an overflow condition occurs.
                                                                           0 No ADC interrupt overflow event detected. 1 ADC Interrupt overflow event detected.
                                                                           The overflow bit does not care about the continuous mode bit state. An overflow condition is generated irrespective of this mode selection.
                                                                           Reset type: SYSRSn */
            __IM  uint16_t ADCINT4                   : 1 ;  /*!< [ 3: 3] : ADC Interrupt 4 Overflow Flags
                                                                           Indicates if an overflow occurred when generating ADCINT pulses. If the respective ADCINTFLG bit is set and a selected additional EOC trigger is generated, then an overflow condition occurs.
                                                                           0 No ADC interrupt overflow event detected. 1 ADC Interrupt overflow event detected.
                                                                           The overflow bit does not care about the continuous mode bit state. An overflow condition is generated irrespective of this mode selection.
                                                                           Reset type: SYSRSn */
                  uint16_t RSV_0                     : 12;  /*!< [15: 4] : reserved. */
        } ADCINTOVFb;
    };

    union
    {
        __IOM uint16_t ADCINTOVFCLR                      ;  /*!< 0x0000000c : ADC Interrupt Overflow Clear Register */
    
        struct
        {
            __IOM uint16_t ADCINT1                   : 1 ;  /*!< [ 0: 0] : ADC Interrupt 1 Overflow Clear Bits
                                                                           0 No action.
                                                                           1 Clears the respective overflow bit in the ADCINTOVF register. If software tries to set this bit on the same clock cycle that hardware tries to set the overflow bit in the ADCINTOVF register, then hardware has priority and the ADCINTOVF bit will be set.
                                                                           Reset type: SYSRSn */
            __IOM uint16_t ADCINT2                   : 1 ;  /*!< [ 1: 1] : ADC Interrupt 2 Overflow Clear Bits
                                                                           0 No action.
                                                                           1 Clears the respective overflow bit in the ADCINTOVF register. If software tries to set this bit on the same clock cycle that hardware tries to set the overflow bit in the ADCINTOVF register, then hardware has priority and the ADCINTOVF bit will be set.
                                                                           Reset type: SYSRSn */
            __IOM uint16_t ADCINT3                   : 1 ;  /*!< [ 2: 2] : ADC Interrupt 3 Overflow Clear Bits
                                                                           0 No action.
                                                                           1 Clears the respective overflow bit in the ADCINTOVF register. If software tries to set this bit on the same clock cycle that hardware tries to set the overflow bit in the ADCINTOVF register, then hardware has priority and the ADCINTOVF bit will be set.
                                                                           Reset type: SYSRSn */
            __IOM uint16_t ADCINT4                   : 1 ;  /*!< [ 3: 3] : ADC Interrupt 4 Overflow Clear Bits
                                                                           0 No action.
                                                                           1 Clears the respective overflow bit in the ADCINTOVF register. If software tries to set this bit on the same clock cycle that hardware tries to set the overflow bit in the ADCINTOVF register, then hardware has priority and the ADCINTOVF bit will be set.
                                                                           Reset type: SYSRSn */
                  uint16_t RSV_0                     : 12;  /*!< [15: 4] : reserved. */
        } ADCINTOVFCLRb;
    };

    union
    {
        __IOM uint16_t ADCINTSEL1N2                      ;  /*!< 0x0000000e : ADC Interrupt 1 and 2 Selection Register */
    
        struct
        {
            __IOM uint16_t INT1SEL                   : 4 ;  /*!< [ 3: 0] : ADCINT1 EOC Source Select 0h EOC0 is trigger for ADCINT1 1h EOC1 is trigger for ADCINT1 2h EOC2 is trigger for ADCINT1 3h EOC3 is trigger for ADCINT1 4h EOC4 is trigger for ADCINT1 5h EOC5 is trigger for ADCINT1 6h EOC6 is trigger for ADCINT1 7h EOC7 is trigger for ADCINT1 8h EOC8 is trigger for ADCINT1 9h EOC9 is trigger for ADCINT1
                                                                           Ah EOC10 is trigger for ADCINT1 Bh EOC11 is trigger for ADCINT1 Ch EOC12 is trigger for ADCINT1 Dh EOC13 is trigger for ADCINT1 Eh EOC14 is trigger for ADCINT1 Fh EOC15 is trigger for ADCINT1
                                                                           Reset type: SYSRSn */
                  uint16_t RSV_0                     : 1 ;  /*!< [ 4: 4] : reserved. */
            __IOM uint16_t INT1E                     : 1 ;  /*!< [ 5: 5] : ADCINT1 Interrupt Enable 0 ADCINT1 is disabled
                                                                           1 ADCINT1 is enabled
                                                                           Reset type: SYSRSn */
            __IOM uint16_t INT1CONT                  : 1 ;  /*!< [ 6: 6] : ADCINT1 Continue to Interrupt Mode
                                                                           0 No further ADCINT1 pulses are generated until ADCINT1 flag (in
                                                                           ADCINTFLG register) is cleared by user.
                                                                           1 ADCINT1 pulses are generated whenever an EOC pulse is
                                                                           generated irrespective of whether the flag bit is cleared or not.
                                                                           Reset type: SYSRSn */
                  uint16_t RSV_1                     : 1 ;  /*!< [ 7: 7] : reserved. */
            __IOM uint16_t INT2SEL                   : 4 ;  /*!< [11: 8] : ADCINT2 EOC Source Select 0h EOC0 is trigger for ADCINT2 1h EOC1 is trigger for ADCINT2 2h EOC2 is trigger for ADCINT2 3h EOC3 is trigger for ADCINT2 4h EOC4 is trigger for ADCINT2 5h EOC5 is trigger for ADCINT2 6h EOC6 is trigger for ADCINT2 7h EOC7 is trigger for ADCINT2 8h EOC8 is trigger for ADCINT2 9h EOC9 is trigger for ADCINT2
                                                                           Ah EOC10 is trigger for ADCINT2 Bh EOC11 is trigger for ADCINT2 Ch EOC12 is trigger for ADCINT2 Dh EOC13 is trigger for ADCINT2 Eh EOC14 is trigger for ADCINT2 Fh EOC15 is trigger for ADCINT2
                                                                           Reset type: SYSRSn */
                  uint16_t RSV_2                     : 1 ;  /*!< [12:12] : reserved. */
            __IOM uint16_t INT2E                     : 1 ;  /*!< [13:13] : ADCINT2 Interrupt Enable 0 ADCINT2 is disabled
                                                                           1 ADCINT2 is enabled
                                                                           Reset type: SYSRSn */
            __IOM uint16_t INT2CONT                  : 1 ;  /*!< [14:14] : ADCINT2 Continue to Interrupt Mode
                                                                           0 No further ADCINT2 pulses are generated until ADCINT2 flag (in
                                                                           ADCINTFLG register) is cleared by user.
                                                                           1 ADCINT2 pulses are generated whenever an EOC pulse is
                                                                           generated irrespective of whether the flag bit is cleared or not.
                                                                           Reset type: SYSRSn */
                  uint16_t RSV_3                     : 1 ;  /*!< [15:15] : reserved. */
        } ADCINTSEL1N2b;
    };

    union
    {
        __IOM uint16_t ADCINTSEL3N4                      ;  /*!< 0x00000010 : ADC Interrupt 3 and 4 Selection Register */
    
        struct
        {
            __IOM uint16_t INT3SEL                   : 4 ;  /*!< [ 3: 0] : ADCINT3 EOC Source Select 0h EOC0 is trigger for ADCINT3 1h EOC1 is trigger for ADCINT3 2h EOC2 is trigger for ADCINT3 3h EOC3 is trigger for ADCINT3 4h EOC4 is trigger for ADCINT3 5h EOC5 is trigger for ADCINT3 6h EOC6 is trigger for ADCINT3 7h EOC7 is trigger for ADCINT3 8h EOC8 is trigger for ADCINT3 9h EOC9 is trigger for ADCINT3
                                                                           Ah EOC10 is trigger for ADCINT3 Bh EOC11 is trigger for ADCINT3 Ch EOC12 is trigger for ADCINT3 Dh EOC13 is trigger for ADCINT3 Eh EOC14 is trigger for ADCINT3 Fh EOC15 is trigger for ADCINT3
                                                                           Reset type: SYSRSn */
                  uint16_t RSV_0                     : 1 ;  /*!< [ 4: 4] : reserved. */
            __IOM uint16_t INT3E                     : 1 ;  /*!< [ 5: 5] : ADCINT3 Interrupt Enable 0 ADCINT3 is disabled
                                                                           1 ADCINT3 is enabled
                                                                           Reset type: SYSRSn */
            __IOM uint16_t INT3CONT                  : 1 ;  /*!< [ 6: 6] : ADCINT3 Continue to Interrupt Mode
                                                                           0 No further ADCINT3 pulses are generated until ADCINT3 flag (in
                                                                           ADCINTFLG register) is cleared by user.
                                                                           1 ADCINT3 pulses are generated whenever an EOC pulse is
                                                                           generated irrespective of whether the flag bit is cleared or not.
                                                                           Reset type: SYSRSn */
                  uint16_t RSV_1                     : 1 ;  /*!< [ 7: 7] : reserved. */
            __IOM uint16_t INT4SEL                   : 4 ;  /*!< [11: 8] : ADCINT4 EOC Source Select 0h EOC0 is trigger for ADCINT4 1h EOC1 is trigger for ADCINT4 2h EOC2 is trigger for ADCINT4 3h EOC3 is trigger for ADCINT4 4h EOC4 is trigger for ADCINT4 5h EOC5 is trigger for ADCINT4 6h EOC6 is trigger for ADCINT4 7h EOC7 is trigger for ADCINT4 8h EOC8 is trigger for ADCINT4 9h EOC9 is trigger for ADCINT4
                                                                           Ah EOC10 is trigger for ADCINT4 Bh EOC11 is trigger for ADCINT4 Ch EOC12 is trigger for ADCINT4 Dh EOC13 is trigger for ADCINT4 Eh EOC14 is trigger for ADCINT4 Fh EOC15 is trigger for ADCINT4
                                                                           Reset type: SYSRSn */
                  uint16_t RSV_2                     : 1 ;  /*!< [12:12] : reserved. */
            __IOM uint16_t INT4E                     : 1 ;  /*!< [13:13] : ADCINT4 Interrupt Enable 0 ADCINT4 is disabled
                                                                           1 ADCINT4 is enabled
                                                                           Reset type: SYSRSn */
            __IOM uint16_t INT4CONT                  : 1 ;  /*!< [14:14] : ADCINT4 Continue to Interrupt Mode
                                                                           0 No further ADCINT4 pulses are generated until ADCINT4 flag (in
                                                                           ADCINTFLG register) is cleared by user.
                                                                           1 ADCINT4 pulses are generated whenever an EOC pulse is
                                                                           generated irrespective of whether the flag bit is cleared or not.
                                                                           Reset type: SYSRSn */
                  uint16_t RSV_3                     : 1 ;  /*!< [15:15] : reserved. */
        } ADCINTSEL3N4b;
    };

    union
    {
        __IOM uint16_t ADCSOCPRICTL                      ;  /*!< 0x00000012 : ADC SOC Priority Control Register */
    
        struct
        {
            __IOM uint16_t SOCPRIORITY               : 5 ;  /*!< [ 4: 0] : SOC Priority
                                                                           Determines the cutoff point for priority mode and round robin arbitration for SOCx
                                                                           00h SOC priority is handled in round robin mode for all channels. 01h SOC0 is high priority, rest of channels are in round robin mode.
                                                                           02h SOC0-SOC1 are high priority, SOC2-SOC15 are in round robin mode.
                                                                           03h SOC0-SOC2 are high priority, SOC3-SOC15 are in round robin mode.
                                                                           04h SOC0-SOC3 are high priority, SOC4-SOC15 are in round robin mode.
                                                                           05h SOC0-SOC4 are high priority, SOC5-SOC15 are in round robin mode.
                                                                           06h SOC0-SOC5 are high priority, SOC6-SOC15 are in round robin mode.
                                                                           07h SOC0-SOC6 are high priority, SOC7-SOC15 are in round robin mode.
                                                                           08h SOC0-SOC7 are high priority, SOC8-SOC15 are in round robin mode.
                                                                           09h SOC0-SOC8 are high priority, SOC9-SOC15 are in round robin mode.
                                                                           0Ah SOC0-SOC9 are high priority, SOC10-SOC15 are in round robin mode.
                                                                           0Bh SOC0-SOC10 are high priority, SOC11-SOC15 are in round robin mode.
                                                                           0Ch SOC0-SOC11 are high priority, SOC12-SOC15 are in round robin mode.
                                                                           0Dh SOC0-SOC12 are high priority, SOC13-SOC15 are in round robin mode.
                                                                           0Eh SOC0-SOC13 are high priority, SOC14-SOC15 are in round robin mode.
                                                                           0Fh SOC0-SOC14 are high priority, SOC15 is in round robin mode. 10h All SOCs are in high priority mode, arbitrated by SOC number. Others Invalid selection.
                                                                           Reset type: SYSRSn */
            __IM  uint16_t RRPOINTER                 : 5 ;  /*!< [ 9: 5] : Round Robin Pointer. Holds the value of the last converted round robin SOCx to be used by the round robin scheme to determine order of conversions.
                                                                           00h SOC0 was last round robin SOC to convert, SOC1 is highest round robin priority.
                                                                           01h SOC1 was last round robin SOC to convert, SOC2 is highest round robin priority.
                                                                           02h SOC2 was last round robin SOC to convert, SOC3 is highest round robin priority.
                                                                           03h SOC3 was last round robin SOC to convert, SOC4 is highest round robin priority.
                                                                           04h SOC4 was last round robin SOC to convert, SOC5 is highest round robin priority.
                                                                           05h SOC5 was last round robin SOC to convert, SOC6 is highest round robin priority.
                                                                           06h SOC6 was last round robin SOC to convert, SOC7 is highest round robin priority.
                                                                           07h SOC7 was last round robin SOC to convert, SOC8 is highest round robin priority.
                                                                           08h SOC8 was last round robin SOC to convert, SOC9 is highest round robin priority.
                                                                           09h SOC9 was last round robin SOC to convert, SOC10 is highest round robin priority.
                                                                           0Ah SOC10 was last round robin SOC to convert, SOC11 is highest round robin priority.
                                                                           0Bh SOC11 was last round robin SOC to convert, SOC12 is highest round robin priority.
                                                                           0Ch SOC12 was last round robin SOC to convert, SOC13 is highest round robin priority.
                                                                           0Dh SOC13 was last round robin SOC to convert, SOC14 is highest round robin priority.
                                                                           0Eh SOC14 was last round robin SOC to convert, SOC15 is highest round robin priority.
                                                                           0Fh SOC15 was last round robin SOC to convert, SOC0 is highest round robin priority.
                                                                           10h Reset value to indicate no SOC has been converted. SOC0 is highest round robin priority. Set to this value when the device is reset, when the ADCCTL1.RESET bit is set, or when the ADCSOCPRICTL register is written. In the latter case, if a conversion is currently in progress, it will complete and then the new priority will take effect.
                                                                           Others Invalid value. Reset type: SYSRSn */
                  uint16_t RSV_0                     : 6 ;  /*!< [15:10] : reserved. */
        } ADCSOCPRICTLb;
    };

    union
    {
        __IOM uint16_t ADCINTSOCSEL1                     ;  /*!< 0x00000014 : ADC Interrupt SOC Selection 1 Register */
    
        struct
        {
            __IOM uint16_t SOC0                      : 2 ;  /*!< [ 1: 0] : SOC0 ADC Interrupt Trigger Select. Selects which, if any, ADCINT triggers SOC0. The trigger selected in this field is in addition to the TRIGSEL field in the ADCSOCxCTL register.
                                                                           00 No ADCINT will trigger SOC0. TRIGSEL field alone determines SOC0 trigger.
                                                                           01 ADCINT1 will trigger SOC0. 10 ADCINT2 will trigger SOC0. 11 Invalid selection.
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC1                      : 2 ;  /*!< [ 3: 2] : SOC1 ADC Interrupt Trigger Select. Selects which, if any, ADCINT triggers SOC1. The trigger selected in this field is in addition to the TRIGSEL field in the ADCSOCxCTL register.
                                                                           00 No ADCINT will trigger SOC1. TRIGSEL field alone determines SOC0 trigger.
                                                                           01 ADCINT1 will trigger SOC1. 10 ADCINT2 will trigger SOC1. 11 Invalid selection.
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC2                      : 2 ;  /*!< [ 5: 4] : SOC2 ADC Interrupt Trigger Select. Selects which, if any, ADCINT triggers SOC2. The trigger selected in this field is in addition to the TRIGSEL field in the ADCSOCxCTL register.
                                                                           00 No ADCINT will trigger SOC2. TRIGSEL field alone determines SOC0 trigger.
                                                                           01 ADCINT1 will trigger SOC2. 10 ADCINT2 will trigger SOC2. 11 Invalid selection.
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC3                      : 2 ;  /*!< [ 7: 6] : SOC3 ADC Interrupt Trigger Select. Selects which, if any, ADCINT triggers SOC3. The trigger selected in this field is in addition to the TRIGSEL field in the ADCSOCxCTL register.
                                                                           00 No ADCINT will trigger SOC3. TRIGSEL field alone determines SOC0 trigger.
                                                                           01 ADCINT1 will trigger SOC3. 10 ADCINT2 will trigger SOC3. 11 Invalid selection.
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC4                      : 2 ;  /*!< [ 9: 8] : SOC4 ADC Interrupt Trigger Select. Selects which, if any, ADCINT triggers SOC4. The trigger selected in this field is in addition to the TRIGSEL field in the ADCSOCxCTL register.
                                                                           00 No ADCINT will trigger SOC4. TRIGSEL field alone determines SOC0 trigger.
                                                                           01 ADCINT1 will trigger SOC4. 10 ADCINT2 will trigger SOC4. 11 Invalid selection.
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC5                      : 2 ;  /*!< [11:10] : SOC5 ADC Interrupt Trigger Select. Selects which, if any, ADCINT triggers SOC5. The trigger selected in this field is in addition to the TRIGSEL field in the ADCSOCxCTL register.
                                                                           00 No ADCINT will trigger SOC5. TRIGSEL field alone determines SOC0 trigger.
                                                                           01 ADCINT1 will trigger SOC5. 10 ADCINT2 will trigger SOC5. 11 Invalid selection.
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC6                      : 2 ;  /*!< [13:12] : SOC6 ADC Interrupt Trigger Select. Selects which, if any, ADCINT triggers SOC6. The trigger selected in this field is in addition to the TRIGSEL field in the ADCSOCxCTL register.
                                                                           00 No ADCINT will trigger SOC6. TRIGSEL field alone determines SOC0 trigger.
                                                                           01 ADCINT1 will trigger SOC6. 10 ADCINT2 will trigger SOC6. 11 Invalid selection.
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC7                      : 2 ;  /*!< [15:14] : SOC7 ADC Interrupt Trigger Select. Selects which, if any, ADCINT triggers SOC7. The trigger selected in this field is in addition to the TRIGSEL field in the ADCSOCxCTL register.
                                                                           00 No ADCINT will trigger SOC7. TRIGSEL field alone determines SOC0 trigger.
                                                                           01 ADCINT1 will trigger SOC7. 10 ADCINT2 will trigger SOC7. 11 Invalid selection.
                                                                           Reset type: SYSRSn */
        } ADCINTSOCSEL1b;
    };

    union
    {
        __IOM uint16_t ADCINTSOCSEL2                     ;  /*!< 0x00000016 : ADC Interrupt SOC Selection 2 Register */
    
        struct
        {
            __IOM uint16_t SOC8                      : 2 ;  /*!< [ 1: 0] : SOC8 ADC Interrupt Trigger Select. Selects which, if any, ADCINT triggers SOC8. The trigger selected in this field is in addition to the TRIGSEL field in the ADCSOCxCTL register.
                                                                           00 No ADCINT will trigger SOC8. TRIGSEL field alone determines SOC0 trigger.
                                                                           01 ADCINT1 will trigger SOC8. 10 ADCINT2 will trigger SOC8. 11 Invalid selection.
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC9                      : 2 ;  /*!< [ 3: 2] : SOC9 ADC Interrupt Trigger Select. Selects which, if any, ADCINT triggers SOC9. The trigger selected in this field is in addition to the TRIGSEL field in the ADCSOCxCTL register.
                                                                           00 No ADCINT will trigger SOC9. TRIGSEL field alone determines SOC0 trigger.
                                                                           01 ADCINT1 will trigger SOC9. 10 ADCINT2 will trigger SOC9. 11 Invalid selection.
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC10                     : 2 ;  /*!< [ 5: 4] : SOC10 ADC Interrupt Trigger Select. Selects which, if any, ADCINT triggers SOC10. The trigger selected in this field is in addition to the TRIGSEL field in the ADCSOCxCTL register.
                                                                           00 No ADCINT will trigger SOC10. TRIGSEL field alone determines SOC0 trigger.
                                                                           01 ADCINT1 will trigger SOC10. 10 ADCINT2 will trigger SOC10. 11 Invalid selection.
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC11                     : 2 ;  /*!< [ 7: 6] : SOC11 ADC Interrupt Trigger Select. Selects which, if any, ADCINT triggers SOC11. The trigger selected in this field is in addition to the TRIGSEL field in the ADCSOCxCTL register.
                                                                           00 No ADCINT will trigger SOC11. TRIGSEL field alone determines SOC0 trigger.
                                                                           01 ADCINT1 will trigger SOC11. 10 ADCINT2 will trigger SOC11. 11 Invalid selection.
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC12                     : 2 ;  /*!< [ 9: 8] : SOC12 ADC Interrupt Trigger Select. Selects which, if any, ADCINT triggers SOC12. The trigger selected in this field is in addition to the TRIGSEL field in the ADCSOCxCTL register.
                                                                           00 No ADCINT will trigger SOC12. TRIGSEL field alone determines SOC0 trigger.
                                                                           01 ADCINT1 will trigger SOC12. 10 ADCINT2 will trigger SOC12. 11 Invalid selection.
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC13                     : 2 ;  /*!< [11:10] : SOC13 ADC Interrupt Trigger Select. Selects which, if any, ADCINT triggers SOC13. The trigger selected in this field is in addition to the TRIGSEL field in the ADCSOCxCTL register.
                                                                           00 No ADCINT will trigger SOC13. TRIGSEL field alone determines SOC0 trigger.
                                                                           01 ADCINT1 will trigger SOC13. 10 ADCINT2 will trigger SOC13. 11 Invalid selection.
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC14                     : 2 ;  /*!< [13:12] : SOC14 ADC Interrupt Trigger Select. Selects which, if any, ADCINT triggers SOC14. The trigger selected in this field is in addition to the TRIGSEL field in the ADCSOCxCTL register.
                                                                           00 No ADCINT will trigger SOC14. TRIGSEL field alone determines SOC0 trigger.
                                                                           01 ADCINT1 will trigger SOC14. 10 ADCINT2 will trigger SOC14. 11 Invalid selection.
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC15                     : 2 ;  /*!< [15:14] : SOC15 ADC Interrupt Trigger Select. Selects which, if any, ADCINT triggers SOC15. The trigger selected in this field is in addition to the TRIGSEL field in the ADCSOCxCTL register.
                                                                           00 No ADCINT will trigger SOC15. TRIGSEL field alone determines SOC0 trigger.
                                                                           01 ADCINT1 will trigger SOC15. 10 ADCINT2 will trigger SOC15. 11 Invalid selection.
                                                                           Reset type: SYSRSn */
        } ADCINTSOCSEL2b;
    };

    union
    {
        __IM  uint16_t ADCSOCFLG1                        ;  /*!< 0x00000018 : ADC SOC Flag 1 Register */
    
        struct
        {
            __IM  uint16_t SOC0                      : 1 ;  /*!< [ 0: 0] : SOC0 Start of Conversion Flag. Indicates the state of SOC0 conversions.
                                                                           0 No sample pending for SOC0.
                                                                           1 Trigger has been received and sample is pending for SOC0.
                                                                           This bit will be automatically cleared when the SOC0 conversion is started. If contention exists where this bit receives both a request to set and a request to clear on the same cycle, regardless of the source of either, this bit will be set and the request to clear will be ignored. In this case the overflow bit in the ADCSOCOVF1 register will not be affected regardless of whether this bit was previously set or not.
                                                                           Reset type: SYSRSn */
            __IM  uint16_t SOC1                      : 1 ;  /*!< [ 1: 1] : SOC1 Start of Conversion Flag. Indicates the state of SOC1 conversions.
                                                                           0 No sample pending for SOC1.
                                                                           1 Trigger has been received and sample is pending for SOC1.
                                                                           This bit will be automatically cleared when the SOC1 conversion is started. If contention exists where this bit receives both a request to set and a request to clear on the same cycle, regardless of the source of either, this bit will be set and the request to clear will be ignored. In this case the overflow bit in the ADCSOCOVF1 register will not be affected regardless of whether this bit was previously set or not.
                                                                           Reset type: SYSRSn */
            __IM  uint16_t SOC2                      : 1 ;  /*!< [ 2: 2] : SOC2 Start of Conversion Flag. Indicates the state of SOC2 conversions.
                                                                           0 No sample pending for SOC2.
                                                                           1 Trigger has been received and sample is pending for SOC2.
                                                                           This bit will be automatically cleared when the SOC2 conversion is started. If contention exists where this bit receives both a request to set and a request to clear on the same cycle, regardless of the source of either, this bit will be set and the request to clear will be ignored. In this case the overflow bit in the ADCSOCOVF1 register will not be affected regardless of whether this bit was previously set or not.
                                                                           Reset type: SYSRSn */
            __IM  uint16_t SOC3                      : 1 ;  /*!< [ 3: 3] : SOC3 Start of Conversion Flag. Indicates the state of SOC3 conversions.
                                                                           0 No sample pending for SOC3.
                                                                           1 Trigger has been received and sample is pending for SOC3.
                                                                           This bit will be automatically cleared when the SOC3 conversion is started. If contention exists where this bit receives both a request to set and a request to clear on the same cycle, regardless of the source of either, this bit will be set and the request to clear will be ignored. In this case the overflow bit in the ADCSOCOVF1 register will not be affected regardless of whether this bit was previously set or not.
                                                                           Reset type: SYSRSn */
            __IM  uint16_t SOC4                      : 1 ;  /*!< [ 4: 4] : SOC4 Start of Conversion Flag. Indicates the state of SOC4 conversions.
                                                                           0 No sample pending for SOC4.
                                                                           1 Trigger has been received and sample is pending for SOC4.
                                                                           This bit will be automatically cleared when the SOC4 conversion is started. If contention exists where this bit receives both a request to set and a request to clear on the same cycle, regardless of the source of either, this bit will be set and the request to clear will be ignored. In this case the overflow bit in the ADCSOCOVF1 register will not be affected regardless of whether this bit was previously set or not.
                                                                           Reset type: SYSRSn */
            __IM  uint16_t SOC5                      : 1 ;  /*!< [ 5: 5] : SOC5 Start of Conversion Flag. Indicates the state of SOC5 conversions.
                                                                           0 No sample pending for SOC5.
                                                                           1 Trigger has been received and sample is pending for SOC5.
                                                                           This bit will be automatically cleared when the SOC5 conversion is started. If contention exists where this bit receives both a request to set and a request to clear on the same cycle, regardless of the source of either, this bit will be set and the request to clear will be ignored. In this case the overflow bit in the ADCSOCOVF1 register will not be affected regardless of whether this bit was previously set or not.
                                                                           Reset type: SYSRSn */
            __IM  uint16_t SOC6                      : 1 ;  /*!< [ 6: 6] : SOC6 Start of Conversion Flag. Indicates the state of SOC6 conversions.
                                                                           0 No sample pending for SOC6.
                                                                           1 Trigger has been received and sample is pending for SOC6.
                                                                           This bit will be automatically cleared when the SOC6 conversion is started. If contention exists where this bit receives both a request to set and a request to clear on the same cycle, regardless of the source of either, this bit will be set and the request to clear will be ignored. In this case the overflow bit in the ADCSOCOVF1 register will not be affected regardless of whether this bit was previously set or not.
                                                                           Reset type: SYSRSn */
            __IM  uint16_t SOC7                      : 1 ;  /*!< [ 7: 7] : SOC7 Start of Conversion Flag. Indicates the state of SOC7 conversions.
                                                                           0 No sample pending for SOC7.
                                                                           1 Trigger has been received and sample is pending for SOC7.
                                                                           This bit will be automatically cleared when the SOC7 conversion is started. If contention exists where this bit receives both a request to set and a request to clear on the same cycle, regardless of the source of either, this bit will be set and the request to clear will be ignored. In this case the overflow bit in the ADCSOCOVF1 register will not be affected regardless of whether this bit was previously set or not.
                                                                           Reset type: SYSRSn */
            __IM  uint16_t SOC8                      : 1 ;  /*!< [ 8: 8] : SOC8 Start of Conversion Flag. Indicates the state of SOC8 conversions.
                                                                           0 No sample pending for SOC8.
                                                                           1 Trigger has been received and sample is pending for SOC8.
                                                                           This bit will be automatically cleared when the SOC8 conversion is started. If contention exists where this bit receives both a request to set and a request to clear on the same cycle, regardless of the source of either, this bit will be set and the request to clear will be ignored. In this case the overflow bit in the ADCSOCOVF1 register will not be affected regardless of whether this bit was previously set or not.
                                                                           Reset type: SYSRSn */
            __IM  uint16_t SOC9                      : 1 ;  /*!< [ 9: 9] : SOC9 Start of Conversion Flag. Indicates the state of SOC9 conversions.
                                                                           0 No sample pending for SOC9.
                                                                           1 Trigger has been received and sample is pending for SOC9.
                                                                           This bit will be automatically cleared when the SOC9 conversion is started. If contention exists where this bit receives both a request to set and a request to clear on the same cycle, regardless of the source of either, this bit will be set and the request to clear will be ignored. In this case the overflow bit in the ADCSOCOVF1 register will not be affected regardless of whether this bit was previously set or not.
                                                                           Reset type: SYSRSn */
            __IM  uint16_t SOC10                     : 1 ;  /*!< [10:10] : SOC10 Start of Conversion Flag. Indicates the state of SOC10 conversions.
                                                                           0 No sample pending for SOC10.
                                                                           1 Trigger has been received and sample is pending for SOC10.
                                                                           This bit will be automatically cleared when the SOC10 conversion is started. If contention exists where this bit receives both a request to set and a request to clear on the same cycle, regardless of the source of either, this bit will be set and the request to clear will be ignored. In this case the overflow bit in the ADCSOCOVF1 register will not be affected regardless of whether this bit was previously set or not.
                                                                           Reset type: SYSRSn */
            __IM  uint16_t SOC11                     : 1 ;  /*!< [11:11] : SOC11 Start of Conversion Flag. Indicates the state of SOC11 conversions.
                                                                           0 No sample pending for SOC11.
                                                                           1 Trigger has been received and sample is pending for SOC11.
                                                                           This bit will be automatically cleared when the SOC11 conversion is started. If contention exists where this bit receives both a request to set and a request to clear on the same cycle, regardless of the source of either, this bit will be set and the request to clear will be ignored. In this case the overflow bit in the ADCSOCOVF1 register will not be affected regardless of whether this bit was previously set or not.
                                                                           Reset type: SYSRSn */
            __IM  uint16_t SOC12                     : 1 ;  /*!< [12:12] : SOC12 Start of Conversion Flag. Indicates the state of SOC12 conversions.
                                                                           0 No sample pending for SOC12.
                                                                           1 Trigger has been received and sample is pending for SOC12.
                                                                           This bit will be automatically cleared when the SOC12 conversion is started. If contention exists where this bit receives both a request to set and a request to clear on the same cycle, regardless of the source of either, this bit will be set and the request to clear will be ignored. In this case the overflow bit in the ADCSOCOVF1 register will not be affected regardless of whether this bit was previously set or not.
                                                                           Reset type: SYSRSn */
            __IM  uint16_t SOC13                     : 1 ;  /*!< [13:13] : SOC13 Start of Conversion Flag. Indicates the state of SOC13 conversions.
                                                                           0 No sample pending for SOC13.
                                                                           1 Trigger has been received and sample is pending for SOC13.
                                                                           This bit will be automatically cleared when the SOC13 conversion is started. If contention exists where this bit receives both a request to set and a request to clear on the same cycle, regardless of the source of either, this bit will be set and the request to clear will be ignored. In this case the overflow bit in the ADCSOCOVF1 register will not be affected regardless of whether this bit was previously set or not.
                                                                           Reset type: SYSRSn */
            __IM  uint16_t SOC14                     : 1 ;  /*!< [14:14] : SOC14 Start of Conversion Flag. Indicates the state of SOC14 conversions.
                                                                           0 No sample pending for SOC14.
                                                                           1 Trigger has been received and sample is pending for SOC14.
                                                                           This bit will be automatically cleared when the SOC14 conversion is started. If contention exists where this bit receives both a request to set and a request to clear on the same cycle, regardless of the source of either, this bit will be set and the request to clear will be ignored. In this case the overflow bit in the ADCSOCOVF1 register will not be affected regardless of whether this bit was previously set or not.
                                                                           Reset type: SYSRSn */
            __IM  uint16_t SOC15                     : 1 ;  /*!< [15:15] : SOC15 Start of Conversion Flag. Indicates the state of SOC15 conversions.
                                                                           0 No sample pending for SOC15.
                                                                           1 Trigger has been received and sample is pending for SOC15.
                                                                           This bit will be automatically cleared when the SOC15 conversion is started. If contention exists where this bit receives both a request to set and a request to clear on the same cycle, regardless of the source of either, this bit will be set and the request to clear will be ignored. In this case the overflow bit in the ADCSOCOVF1 register will not be affected regardless of whether this bit was previously set or not.
                                                                           Reset type: SYSRSn */
        } ADCSOCFLG1b;
    };

    union
    {
        __IOM uint16_t ADCSOCFRC1                        ;  /*!< 0x0000001a : ADC SOC Force 1 Register */
    
        struct
        {
            __IOM uint16_t SOC0                      : 1 ;  /*!< [ 0: 0] : SOC0 Force Start of Conversion Bit. Writing a 1 will force to 1 the SOC0 flag in the ADCSOCFLG1 register. This can be used to initiate a software initiated conversion. Writes of 0 are ignored. This bit will always read as a 0.
                                                                           0 No action.
                                                                           1 Force SOC0 flag bit to 1. This will cause a conversion to start once priority is given to SOC0.
                                                                           If software tries to set this bit on the same clock cycle that hardware tries to clear the SOC0 bit in the ADCSOCFLG1 register, then software has priority and the ADCSOCFLG1 bit will be set. In this case the overflow bit in the ADCSOCOVF1 register will not be affected regardless of whether the ADCSOCFLG1 bit was previously set or not.
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC1                      : 1 ;  /*!< [ 1: 1] : SOC1 Force Start of Conversion Bit. Writing a 1 will force to 1 the SOC1 flag in the ADCSOCFLG1 register. This can be used to initiate a software initiated conversion. Writes of 0 are ignored. This bit will always read as a 0.
                                                                           0 No action.
                                                                           1 Force SOC1 flag bit to 1. This will cause a conversion to start once priority is given to SOC1.
                                                                           If software tries to set this bit on the same clock cycle that hardware tries to clear the SOC1 bit in the ADCSOCFLG1 register, then software has priority and the ADCSOCFLG1 bit will be set. In this case the overflow bit in the ADCSOCOVF1 register will not be affected regardless of whether the ADCSOCFLG1 bit was previously set or not.
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC2                      : 1 ;  /*!< [ 2: 2] : SOC2 Force Start of Conversion Bit. Writing a 1 will force to 1 the SOC2 flag in the ADCSOCFLG1 register. This can be used to initiate a software initiated conversion. Writes of 0 are ignored. This bit will always read as a 0.
                                                                           0 No action.
                                                                           1 Force SOC2 flag bit to 1. This will cause a conversion to start once priority is given to SOC2.
                                                                           If software tries to set this bit on the same clock cycle that hardware tries to clear the SOC2 bit in the ADCSOCFLG1 register, then software has priority and the ADCSOCFLG1 bit will be set. In this case the overflow bit in the ADCSOCOVF1 register will not be affected regardless of whether the ADCSOCFLG1 bit was previously set or not.
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC3                      : 1 ;  /*!< [ 3: 3] : SOC3 Force Start of Conversion Bit. Writing a 1 will force to 1 the SOC3 flag in the ADCSOCFLG1 register. This can be used to initiate a software initiated conversion. Writes of 0 are ignored. This bit will always read as a 0.
                                                                           0 No action.
                                                                           1 Force SOC3 flag bit to 1. This will cause a conversion to start once priority is given to SOC3.
                                                                           If software tries to set this bit on the same clock cycle that hardware tries to clear the SOC3 bit in the ADCSOCFLG1 register, then software has priority and the ADCSOCFLG1 bit will be set. In this case the overflow bit in the ADCSOCOVF1 register will not be affected regardless of whether the ADCSOCFLG1 bit was previously set or not.
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC4                      : 1 ;  /*!< [ 4: 4] : SOC4 Force Start of Conversion Bit. Writing a 1 will force to 1 the SOC4 flag in the ADCSOCFLG1 register. This can be used to initiate a software initiated conversion. Writes of 0 are ignored. This bit will always read as a 0.
                                                                           0 No action.
                                                                           1 Force SOC4 flag bit to 1. This will cause a conversion to start once priority is given to SOC4.
                                                                           If software tries to set this bit on the same clock cycle that hardware tries to clear the SOC4 bit in the ADCSOCFLG1 register, then software has priority and the ADCSOCFLG1 bit will be set. In this case the overflow bit in the ADCSOCOVF1 register will not be affected regardless of whether the ADCSOCFLG1 bit was previously set or not.
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC5                      : 1 ;  /*!< [ 5: 5] : SOC5 Force Start of Conversion Bit. Writing a 1 will force to 1 the SOC5 flag in the ADCSOCFLG1 register. This can be used to initiate a software initiated conversion. Writes of 0 are ignored. This bit will always read as a 0.
                                                                           0 No action.
                                                                           1 Force SOC5 flag bit to 1. This will cause a conversion to start once priority is given to SOC5.
                                                                           If software tries to set this bit on the same clock cycle that hardware tries to clear the SOC5 bit in the ADCSOCFLG1 register, then software has priority and the ADCSOCFLG1 bit will be set. In this case the overflow bit in the ADCSOCOVF1 register will not be affected regardless of whether the ADCSOCFLG1 bit was previously set or not.
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC6                      : 1 ;  /*!< [ 6: 6] : SOC6 Force Start of Conversion Bit. Writing a 1 will force to 1 the SOC6 flag in the ADCSOCFLG1 register. This can be used to initiate a software initiated conversion. Writes of 0 are ignored. This bit will always read as a 0.
                                                                           0 No action.
                                                                           1 Force SOC6 flag bit to 1. This will cause a conversion to start once priority is given to SOC6.
                                                                           If software tries to set this bit on the same clock cycle that hardware tries to clear the SOC6 bit in the ADCSOCFLG1 register, then software has priority and the ADCSOCFLG1 bit will be set. In this case the overflow bit in the ADCSOCOVF1 register will not be affected regardless of whether the ADCSOCFLG1 bit was previously set or not.
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC7                      : 1 ;  /*!< [ 7: 7] : SOC7 Force Start of Conversion Bit. Writing a 1 will force to 1 the SOC7 flag in the ADCSOCFLG1 register. This can be used to initiate a software initiated conversion. Writes of 0 are ignored. This bit will always read as a 0.
                                                                           0 No action.
                                                                           1 Force SOC7 flag bit to 1. This will cause a conversion to start once priority is given to SOC7.
                                                                           If software tries to set this bit on the same clock cycle that hardware tries to clear the SOC7 bit in the ADCSOCFLG1 register, then software has priority and the ADCSOCFLG1 bit will be set. In this case the overflow bit in the ADCSOCOVF1 register will not be affected regardless of whether the ADCSOCFLG1 bit was previously set or not.
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC8                      : 1 ;  /*!< [ 8: 8] : SOC8 Force Start of Conversion Bit. Writing a 1 will force to 1 the SOC8 flag in the ADCSOCFLG1 register. This can be used to initiate a software initiated conversion. Writes of 0 are ignored. This bit will always read as a 0.
                                                                           0 No action.
                                                                           1 Force SOC8 flag bit to 1. This will cause a conversion to start once priority is given to SOC8.
                                                                           If software tries to set this bit on the same clock cycle that hardware tries to clear the SOC8 bit in the ADCSOCFLG1 register, then software has priority and the ADCSOCFLG1 bit will be set. In this case the overflow bit in the ADCSOCOVF1 register will not be affected regardless of whether the ADCSOCFLG1 bit was previously set or not.
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC9                      : 1 ;  /*!< [ 9: 9] : SOC9 Force Start of Conversion Bit. Writing a 1 will force to 1 the SOC9 flag in the ADCSOCFLG1 register. This can be used to initiate a software initiated conversion. Writes of 0 are ignored. This bit will always read as a 0.
                                                                           0 No action.
                                                                           1 Force SOC9 flag bit to 1. This will cause a conversion to start once priority is given to SOC9.
                                                                           If software tries to set this bit on the same clock cycle that hardware tries to clear the SOC9 bit in the ADCSOCFLG1 register, then software has priority and the ADCSOCFLG1 bit will be set. In this case the overflow bit in the ADCSOCOVF1 register will not be affected regardless of whether the ADCSOCFLG1 bit was previously set or not.
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC10                     : 1 ;  /*!< [10:10] : SOC10 Force Start of Conversion Bit. Writing a 1 will force to 1 the SOC10 flag in the ADCSOCFLG1 register. This can be used to initiate a software initiated conversion. Writes of 0 are ignored. This bit will always read as a 0.
                                                                           0 No action.
                                                                           1 Force SOC10 flag bit to 1. This will cause a conversion to start once priority is given to SOC10.
                                                                           If software tries to set this bit on the same clock cycle that hardware tries to clear the SOC10 bit in the ADCSOCFLG1 register, then software has priority and the ADCSOCFLG1 bit will be set. In this case the overflow bit in the ADCSOCOVF1 register will not be affected regardless of whether the ADCSOCFLG1 bit was previously set or not.
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC11                     : 1 ;  /*!< [11:11] : SOC11 Force Start of Conversion Bit. Writing a 1 will force to 1 the SOC11 flag in the ADCSOCFLG1 register. This can be used to initiate a software initiated conversion. Writes of 0 are ignored. This bit will always read as a 0.
                                                                           0 No action.
                                                                           1 Force SOC11 flag bit to 1. This will cause a conversion to start once priority is given to SOC11.
                                                                           If software tries to set this bit on the same clock cycle that hardware tries to clear the SOC11 bit in the ADCSOCFLG1 register, then software has priority and the ADCSOCFLG1 bit will be set. In this case the overflow bit in the ADCSOCOVF1 register will not be affected regardless of whether the ADCSOCFLG1 bit was previously set or not.
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC12                     : 1 ;  /*!< [12:12] : SOC12 Force Start of Conversion Bit. Writing a 1 will force to 1 the SOC12 flag in the ADCSOCFLG1 register. This can be used to initiate a software initiated conversion. Writes of 0 are ignored. This bit will always read as a 0.
                                                                           0 No action.
                                                                           1 Force SOC12 flag bit to 1. This will cause a conversion to start once priority is given to SOC12.
                                                                           If software tries to set this bit on the same clock cycle that hardware tries to clear the SOC12 bit in the ADCSOCFLG1 register, then software has priority and the ADCSOCFLG1 bit will be set. In this case the overflow bit in the ADCSOCOVF1 register will not be affected regardless of whether the ADCSOCFLG1 bit was previously set or not.
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC13                     : 1 ;  /*!< [13:13] : SOC13 Force Start of Conversion Bit. Writing a 1 will force to 1 the SOC13 flag in the ADCSOCFLG1 register. This can be used to initiate a software initiated conversion. Writes of 0 are ignored. This bit will always read as a 0.
                                                                           0 No action.
                                                                           1 Force SOC13 flag bit to 1. This will cause a conversion to start once priority is given to SOC13.
                                                                           If software tries to set this bit on the same clock cycle that hardware tries to clear the SOC13 bit in the ADCSOCFLG1 register, then software has priority and the ADCSOCFLG1 bit will be set. In this case the overflow bit in the ADCSOCOVF1 register will not be affected regardless of whether the ADCSOCFLG1 bit was previously set or not.
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC14                     : 1 ;  /*!< [14:14] : SOC14 Force Start of Conversion Bit. Writing a 1 will force to 1 the SOC14 flag in the ADCSOCFLG1 register. This can be used to initiate a software initiated conversion. Writes of 0 are ignored. This bit will always read as a 0.
                                                                           0 No action.
                                                                           1 Force SOC14 flag bit to 1. This will cause a conversion to start once priority is given to SOC14.
                                                                           If software tries to set this bit on the same clock cycle that hardware tries to clear the SOC14 bit in the ADCSOCFLG1 register, then software has priority and the ADCSOCFLG1 bit will be set. In this case the overflow bit in the ADCSOCOVF1 register will not be affected regardless of whether the ADCSOCFLG1 bit was previously set or not.
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC15                     : 1 ;  /*!< [15:15] : SOC15 Force Start of Conversion Bit. Writing a 1 will force to 1 the SOC15 flag in the ADCSOCFLG1 register. This can be used to initiate a software initiated conversion. Writes of 0 are ignored. This bit will always read as a 0.
                                                                           0 No action.
                                                                           1 Force SOC15 flag bit to 1. This will cause a conversion to start once priority is given to SOC15.
                                                                           If software tries to set this bit on the same clock cycle that hardware tries to clear the SOC15 bit in the ADCSOCFLG1 register, then software has priority and the ADCSOCFLG1 bit will be set. In this case the overflow bit in the ADCSOCOVF1 register will not be affected regardless of whether the ADCSOCFLG1 bit was previously set or not.
                                                                           Reset type: SYSRSn */
        } ADCSOCFRC1b;
    };

    union
    {
        __IM  uint16_t ADCSOCOVF1                        ;  /*!< 0x0000001c : ADC SOC Overflow 1 Register */
    
        struct
        {
            __IM  uint16_t SOC0                      : 1 ;  /*!< [ 0: 0] : SOC0 Start of Conversion Overflow Flag. Indicates an SOC0 event was generated in hardware while an existing SOC0 event was already pending.
                                                                           0 No SOC0 event overflow. 1 SOC0 event overflow.
                                                                           An overflow condition does not stop SOC0 events from being processed. It simply is an indication that a hardware trigger was missed. A write to the ADCSOCFRC1 register does not affect this bit.
                                                                           Reset type: SYSRSn */
            __IM  uint16_t SOC1                      : 1 ;  /*!< [ 1: 1] : SOC1 Start of Conversion Overflow Flag. Indicates an SOC1 event was generated in hardware while an existing SOC1 event was already pending.
                                                                           0 No SOC1 event overflow. 1 SOC1 event overflow.
                                                                           An overflow condition does not stop SOC1 events from being processed. It simply is an indication that a hardware trigger was missed. A write to the ADCSOCFRC1 register does not affect this bit.
                                                                           Reset type: SYSRSn */
            __IM  uint16_t SOC2                      : 1 ;  /*!< [ 2: 2] : SOC2 Start of Conversion Overflow Flag. Indicates an SOC2 event was generated in hardware while an existing SOC2 event was already pending.
                                                                           0 No SOC2 event overflow. 1 SOC2 event overflow.
                                                                           An overflow condition does not stop SOC2 events from being processed. It simply is an indication that a hardware trigger was missed. A write to the ADCSOCFRC1 register does not affect this bit.
                                                                           Reset type: SYSRSn */
            __IM  uint16_t SOC3                      : 1 ;  /*!< [ 3: 3] : SOC3 Start of Conversion Overflow Flag. Indicates an SOC3 event was generated in hardware while an existing SOC3 event was already pending.
                                                                           0 No SOC3 event overflow. 1 SOC3 event overflow.
                                                                           An overflow condition does not stop SOC3 events from being processed. It simply is an indication that a hardware trigger was missed. A write to the ADCSOCFRC1 register does not affect this bit.
                                                                           Reset type: SYSRSn */
            __IM  uint16_t SOC4                      : 1 ;  /*!< [ 4: 4] : SOC4 Start of Conversion Overflow Flag. Indicates an SOC4 event was generated in hardware while an existing SOC4 event was already pending.
                                                                           0 No SOC4 event overflow. 1 SOC4 event overflow.
                                                                           An overflow condition does not stop SOC4 events from being processed. It simply is an indication that a hardware trigger was missed. A write to the ADCSOCFRC1 register does not affect this bit.
                                                                           Reset type: SYSRSn */
            __IM  uint16_t SOC5                      : 1 ;  /*!< [ 5: 5] : SOC5 Start of Conversion Overflow Flag. Indicates an SOC5 event was generated in hardware while an existing SOC5 event was already pending.
                                                                           0 No SOC5 event overflow. 1 SOC5 event overflow.
                                                                           An overflow condition does not stop SOC5 events from being processed. It simply is an indication that a hardware trigger was missed. A write to the ADCSOCFRC1 register does not affect this bit.
                                                                           Reset type: SYSRSn */
            __IM  uint16_t SOC6                      : 1 ;  /*!< [ 6: 6] : SOC6 Start of Conversion Overflow Flag. Indicates an SOC6 event was generated in hardware while an existing SOC6 event was already pending.
                                                                           0 No SOC6 event overflow. 1 SOC6 event overflow.
                                                                           An overflow condition does not stop SOC6 events from being processed. It simply is an indication that a hardware trigger was missed. A write to the ADCSOCFRC1 register does not affect this bit.
                                                                           Reset type: SYSRSn */
            __IM  uint16_t SOC7                      : 1 ;  /*!< [ 7: 7] : SOC7 Start of Conversion Overflow Flag. Indicates an SOC7 event was generated in hardware while an existing SOC7 event was already pending.
                                                                           0 No SOC7 event overflow. 1 SOC7 event overflow.
                                                                           An overflow condition does not stop SOC7 events from being processed. It simply is an indication that a hardware trigger was missed. A write to the ADCSOCFRC1 register does not affect this bit.
                                                                           Reset type: SYSRSn */
            __IM  uint16_t SOC8                      : 1 ;  /*!< [ 8: 8] : SOC8 Start of Conversion Overflow Flag. Indicates an SOC8 event was generated in hardware while an existing SOC8 event was already pending.
                                                                           0 No SOC8 event overflow. 1 SOC8 event overflow.
                                                                           An overflow condition does not stop SOC8 events from being processed. It simply is an indication that a hardware trigger was missed. A write to the ADCSOCFRC1 register does not affect this bit.
                                                                           Reset type: SYSRSn */
            __IM  uint16_t SOC9                      : 1 ;  /*!< [ 9: 9] : SOC9 Start of Conversion Overflow Flag. Indicates an SOC9 event was generated in hardware while an existing SOC9 event was already pending.
                                                                           0 No SOC9 event overflow. 1 SOC9 event overflow.
                                                                           An overflow condition does not stop SOC9 events from being processed. It simply is an indication that a hardware trigger was missed. A write to the ADCSOCFRC1 register does not affect this bit.
                                                                           Reset type: SYSRSn */
            __IM  uint16_t SOC10                     : 1 ;  /*!< [10:10] : SOC10 Start of Conversion Overflow Flag. Indicates an SOC10 event was generated in hardware while an existing SOC10 event was already pending.
                                                                           0 No SOC10 event overflow. 1 SOC10 event overflow.
                                                                           An overflow condition does not stop SOC10 events from being processed. It simply is an indication that a hardware trigger was missed. A write to the ADCSOCFRC1 register does not affect this bit.
                                                                           Reset type: SYSRSn */
            __IM  uint16_t SOC11                     : 1 ;  /*!< [11:11] : SOC11 Start of Conversion Overflow Flag. Indicates an SOC11 event was generated in hardware while an existing SOC11 event was already pending.
                                                                           0 No SOC11 event overflow. 1 SOC11 event overflow.
                                                                           An overflow condition does not stop SOC11 events from being processed. It simply is an indication that a hardware trigger was missed. A write to the ADCSOCFRC1 register does not affect this bit.
                                                                           Reset type: SYSRSn */
            __IM  uint16_t SOC12                     : 1 ;  /*!< [12:12] : SOC12 Start of Conversion Overflow Flag. Indicates an SOC12 event was generated in hardware while an existing SOC12 event was already pending.
                                                                           0 No SOC12 event overflow. 1 SOC12 event overflow.
                                                                           An overflow condition does not stop SOC12 events from being processed. It simply is an indication that a hardware trigger was missed. A write to the ADCSOCFRC1 register does not affect this bit.
                                                                           Reset type: SYSRSn */
            __IM  uint16_t SOC13                     : 1 ;  /*!< [13:13] : SOC13 Start of Conversion Overflow Flag. Indicates an SOC13 event was generated in hardware while an existing SOC13 event was already pending.
                                                                           0 No SOC13 event overflow. 1 SOC13 event overflow.
                                                                           An overflow condition does not stop SOC13 events from being processed. It simply is an indication that a hardware trigger was missed. A write to the ADCSOCFRC1 register does not affect this bit.
                                                                           Reset type: SYSRSn */
            __IM  uint16_t SOC14                     : 1 ;  /*!< [14:14] : SOC14 Start of Conversion Overflow Flag. Indicates an SOC14 event was generated in hardware while an existing SOC14 event was already pending.
                                                                           0 No SOC14 event overflow. 1 SOC14 event overflow.
                                                                           An overflow condition does not stop SOC14 events from being processed. It simply is an indication that a hardware trigger was missed. A write to the ADCSOCFRC1 register does not affect this bit.
                                                                           Reset type: SYSRSn */
            __IM  uint16_t SOC15                     : 1 ;  /*!< [15:15] : SOC15 Start of Conversion Overflow Flag. Indicates an SOC15 event was generated in hardware while an existing SOC15 event was already pending.
                                                                           0 No SOC15 event overflow. 1 SOC15 event overflow.
                                                                           An overflow condition does not stop SOC15 events from being processed. It simply is an indication that a hardware trigger was missed. A write to the ADCSOCFRC1 register does not affect this bit.
                                                                           Reset type: SYSRSn */
        } ADCSOCOVF1b;
    };

    union
    {
        __IOM uint16_t ADCSOCOVFCLR1                     ;  /*!< 0x0000001e : ADC SOC Overflow Clear 1 Register */
    
        struct
        {
            __IOM uint16_t SOC0                      : 1 ;  /*!< [ 0: 0] : SOC0 Clear Start of Conversion Overflow Bit. Writing a 1 will clear the SOC0 overflow flag in the ADCSOCOVF1 register. Writes of 0 are ignored. Reads will always return a 0.
                                                                           0 No action.
                                                                           1 Clear SOC0 overflow flag.
                                                                           If software tries to set this bit on the same clock cycle that hardware tries to set the overflow bit in the ADCSOCOVF1 register, then hardware has priority and the ADCSOCOVF1 bit will be set..
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC1                      : 1 ;  /*!< [ 1: 1] : SOC1 Clear Start of Conversion Overflow Bit. Writing a 1 will clear the SOC1 overflow flag in the ADCSOCOVF1 register. Writes of 0 are ignored. Reads will always return a 0.
                                                                           0 No action.
                                                                           1 Clear SOC1 overflow flag.
                                                                           If software tries to set this bit on the same clock cycle that hardware tries to set the overflow bit in the ADCSOCOVF1 register, then hardware has priority and the ADCSOCOVF1 bit will be set..
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC2                      : 1 ;  /*!< [ 2: 2] : SOC2 Clear Start of Conversion Overflow Bit. Writing a 1 will clear the SOC2 overflow flag in the ADCSOCOVF1 register. Writes of 0 are ignored. Reads will always return a 0.
                                                                           0 No action.
                                                                           1 Clear SOC2 overflow flag.
                                                                           If software tries to set this bit on the same clock cycle that hardware tries to set the overflow bit in the ADCSOCOVF1 register, then hardware has priority and the ADCSOCOVF1 bit will be set..
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC3                      : 1 ;  /*!< [ 3: 3] : SOC3 Clear Start of Conversion Overflow Bit. Writing a 1 will clear the SOC3 overflow flag in the ADCSOCOVF1 register. Writes of 0 are ignored. Reads will always return a 0.
                                                                           0 No action.
                                                                           1 Clear SOC3 overflow flag.
                                                                           If software tries to set this bit on the same clock cycle that hardware tries to set the overflow bit in the ADCSOCOVF1 register, then hardware has priority and the ADCSOCOVF1 bit will be set..
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC4                      : 1 ;  /*!< [ 4: 4] : SOC4 Clear Start of Conversion Overflow Bit. Writing a 1 will clear the SOC4 overflow flag in the ADCSOCOVF1 register. Writes of 0 are ignored. Reads will always return a 0.
                                                                           0 No action.
                                                                           1 Clear SOC4 overflow flag.
                                                                           If software tries to set this bit on the same clock cycle that hardware tries to set the overflow bit in the ADCSOCOVF1 register, then hardware has priority and the ADCSOCOVF1 bit will be set..
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC5                      : 1 ;  /*!< [ 5: 5] : SOC5 Clear Start of Conversion Overflow Bit. Writing a 1 will clear the SOC5 overflow flag in the ADCSOCOVF1 register. Writes of 0 are ignored. Reads will always return a 0.
                                                                           0 No action.
                                                                           1 Clear SOC5 overflow flag.
                                                                           If software tries to set this bit on the same clock cycle that hardware tries to set the overflow bit in the ADCSOCOVF1 register, then hardware has priority and the ADCSOCOVF1 bit will be set..
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC6                      : 1 ;  /*!< [ 6: 6] : SOC6 Clear Start of Conversion Overflow Bit. Writing a 1 will clear the SOC6 overflow flag in the ADCSOCOVF1 register. Writes of 0 are ignored. Reads will always return a 0.
                                                                           0 No action.
                                                                           1 Clear SOC6 overflow flag.
                                                                           If software tries to set this bit on the same clock cycle that hardware tries to set the overflow bit in the ADCSOCOVF1 register, then hardware has priority and the ADCSOCOVF1 bit will be set..
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC7                      : 1 ;  /*!< [ 7: 7] : SOC7 Clear Start of Conversion Overflow Bit. Writing a 1 will clear the SOC7 overflow flag in the ADCSOCOVF1 register. Writes of 0 are ignored. Reads will always return a 0.
                                                                           0 No action.
                                                                           1 Clear SOC7 overflow flag.
                                                                           If software tries to set this bit on the same clock cycle that hardware tries to set the overflow bit in the ADCSOCOVF1 register, then hardware has priority and the ADCSOCOVF1 bit will be set..
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC8                      : 1 ;  /*!< [ 8: 8] : SOC8 Clear Start of Conversion Overflow Bit. Writing a 1 will clear the SOC8 overflow flag in the ADCSOCOVF1 register. Writes of 0 are ignored. Reads will always return a 0.
                                                                           0 No action.
                                                                           1 Clear SOC8 overflow flag.
                                                                           If software tries to set this bit on the same clock cycle that hardware tries to set the overflow bit in the ADCSOCOVF1 register, then hardware has priority and the ADCSOCOVF1 bit will be set..
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC9                      : 1 ;  /*!< [ 9: 9] : SOC9 Clear Start of Conversion Overflow Bit. Writing a 1 will clear the SOC9 overflow flag in the ADCSOCOVF1 register. Writes of 0 are ignored. Reads will always return a 0.
                                                                           0 No action.
                                                                           1 Clear SOC9 overflow flag.
                                                                           If software tries to set this bit on the same clock cycle that hardware tries to set the overflow bit in the ADCSOCOVF1 register, then hardware has priority and the ADCSOCOVF1 bit will be set..
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC10                     : 1 ;  /*!< [10:10] : SOC10 Clear Start of Conversion Overflow Bit. Writing a 1 will clear the SOC10 overflow flag in the ADCSOCOVF1 register. Writes of 0 are ignored. Reads will always return a 0.
                                                                           0 No action.
                                                                           1 Clear SOC10 overflow flag.
                                                                           If software tries to set this bit on the same clock cycle that hardware tries to set the overflow bit in the ADCSOCOVF1 register, then hardware has priority and the ADCSOCOVF1 bit will be set..
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC11                     : 1 ;  /*!< [11:11] : SOC11 Clear Start of Conversion Overflow Bit. Writing a 1 will clear the SOC11 overflow flag in the ADCSOCOVF1 register. Writes of 0 are ignored. Reads will always return a 0.
                                                                           0 No action.
                                                                           1 Clear SOC11 overflow flag.
                                                                           If software tries to set this bit on the same clock cycle that hardware tries to set the overflow bit in the ADCSOCOVF1 register, then hardware has priority and the ADCSOCOVF1 bit will be set..
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC12                     : 1 ;  /*!< [12:12] : SOC12 Clear Start of Conversion Overflow Bit. Writing a 1 will clear the SOC12 overflow flag in the ADCSOCOVF1 register. Writes of 0 are ignored. Reads will always return a 0.
                                                                           0 No action.
                                                                           1 Clear SOC12 overflow flag.
                                                                           If software tries to set this bit on the same clock cycle that hardware tries to set the overflow bit in the ADCSOCOVF1 register, then hardware has priority and the ADCSOCOVF1 bit will be set..
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC13                     : 1 ;  /*!< [13:13] : SOC13 Clear Start of Conversion Overflow Bit. Writing a 1 will clear the SOC13 overflow flag in the ADCSOCOVF1 register. Writes of 0 are ignored. Reads will always return a 0.
                                                                           0 No action.
                                                                           1 Clear SOC13 overflow flag.
                                                                           If software tries to set this bit on the same clock cycle that hardware tries to set the overflow bit in the ADCSOCOVF1 register, then hardware has priority and the ADCSOCOVF1 bit will be set..
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC14                     : 1 ;  /*!< [14:14] : SOC14 Clear Start of Conversion Overflow Bit. Writing a 1 will clear the SOC14 overflow flag in the ADCSOCOVF1 register. Writes of 0 are ignored. Reads will always return a 0.
                                                                           0 No action.
                                                                           1 Clear SOC14 overflow flag.
                                                                           If software tries to set this bit on the same clock cycle that hardware tries to set the overflow bit in the ADCSOCOVF1 register, then hardware has priority and the ADCSOCOVF1 bit will be set..
                                                                           Reset type: SYSRSn */
            __IOM uint16_t SOC15                     : 1 ;  /*!< [15:15] : SOC15 Clear Start of Conversion Overflow Bit. Writing a 1 will clear the SOC15 overflow flag in the ADCSOCOVF1 register. Writes of 0 are ignored. Reads will always return a 0.
                                                                           0 No action.
                                                                           1 Clear SOC15 overflow flag.
                                                                           If software tries to set this bit on the same clock cycle that hardware tries to set the overflow bit in the ADCSOCOVF1 register, then hardware has priority and the ADCSOCOVF1 bit will be set..
                                                                           Reset type: SYSRSn */
        } ADCSOCOVFCLR1b;
    };

    union
    {
        __IOM uint32_t ADCSOCCTL                         ;  /*!< 0x00000020 : ADC  SOC0 Control Register */
    
        struct
        {
            __IOM uint32_t ACQPS                     : 15;  /*!< [14: 0] : SOC0 Acquisition Prescale. Controls the sample and hold window for this SOC. The configured acquisition time must be at least as long as one ADCCLK cycle for correct ADC operation. The device datasheet will also specify a minimum sample and hold window duration.
                                                                           000h Sample window is 1 system clock cycle wide 001h Sample window is 2 system clock cycles wide 002h Sample window is 3 system clock cycles wide
                                                                           ...
                                                                           1FFh Sample window is 512 system clock cycles wide Reset type: SYSRSn */
            __IOM uint32_t CHSEL                     : 4 ;  /*!< [18:15] : SOC0 Channel Select. Selects the channel to be converted when SOC0 is received by the ADC.
                                                                           Single-ended Signaling Mode (SIGNALMODE = 0): 0h ADCIN0
                                                                           1h ADCIN1
                                                                           2h ADCIN2
                                                                           3h ADCIN3
                                                                           4h ADCIN4
                                                                           5h ADCIN5
                                                                           6h ADCIN6
                                                                           7h ADCIN7
                                                                           8h ADCIN8
                                                                           9h ADCIN9 Ah ADCIN10 Bh ADCIN11 Ch ADCIN12 Dh ADCIN13 Eh ADCIN14 Fh ADCIN15
                                                                           Differential Signaling Mode (SIGNALMODE = 1): 0h ADCIN0 (non-inverting) and ADCIN1 (inverting) 1h ADCIN0 (non-inverting) and ADCIN1 (inverting) 2h ADCIN2 (non-inverting) and ADCIN3 (inverting) 3h ADCIN2 (non-inverting) and ADCIN3 (inverting) 4h ADCIN4 (non-inverting) and ADCIN5 (inverting) 5h ADCIN4 (non-inverting) and ADCIN5 (inverting) 6h ADCIN6 (non-inverting) and ADCIN7 (inverting) 7h ADCIN6 (non-inverting) and ADCIN7 (inverting) 8h ADCIN8 (non-inverting) and ADCIN9 (inverting) 9h ADCIN8 (non-inverting) and ADCIN9 (inverting)
                                                                           Ah ADCIN10 (non-inverting) and ADCIN11 (inverting) Bh ADCIN10 (non-inverting) and ADCIN11 (inverting) Ch ADCIN12 (non-inverting) and ADCIN13 (inverting) Dh ADCIN12 (non-inverting) and ADCIN13 (inverting) Eh ADCIN14 (non-inverting) and ADCIN15 (inverting) Fh ADCIN14 (non-inverting) and ADCIN15 (inverting)
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 1 ;  /*!< [19:19] : reserved. */
            __IOM uint32_t TRIGSEL                   : 5 ;  /*!< [24:20] : SOC0 Trigger Source Select. Along with the SOC0 field in the ADCINTSOCSEL1 register, this bit field configures which trigger will set the SOC0 flag in the ADCSOCFLG1 register to initiate a conversion to start once priority is given to it.
                                                                           00h ADCTRIG0 - Software only
                                                                           01h ADCTRIG1 - CPU1 Timer 0, TINT0n
                                                                           02h ADCTRIG2 - CPU1 Timer 1, TINT1n
                                                                           03h ADCTRIG3 - CPU1 Timer 2, TINT2n
                                                                           04h ADCTRIG4 - GPIO, ADCEXTSOC
                                                                           05h ADCTRIG5 - ePWM1, ADCSOCA
                                                                           06h ADCTRIG6 - ePWM1, ADCSOCB
                                                                           07h ADCTRIG7 - ePWM2, ADCSOCA
                                                                           08h ADCTRIG8 - ePWM2, ADCSOCB
                                                                           09h ADCTRIG9 - ePWM3, ADCSOCA
                                                                           0Ah ADCTRIG10 - ePWM3, ADCSOCB
                                                                           0Bh ADCTRIG11 - ePWM4, ADCSOCA
                                                                           0Ch ADCTRIG12 - ePWM4, ADCSOCB
                                                                           0Dh ADCTRIG13 - ePWM5, ADCSOCA
                                                                           0Eh ADCTRIG14 - ePWM5, ADCSOCB
                                                                           0Fh ADCTRIG15 - ePWM6, ADCSOCA
                                                                           10h ADCTRIG16 - ePWM6, ADCSOCB
                                                                           11h ADCTRIG17 - ePWM7, ADCSOCA
                                                                           12h ADCTRIG18 - ePWM7, ADCSOCB
                                                                           13h ADCTRIG19 - ePWM8, ADCSOCA
                                                                           14h ADCTRIG20 - ePWM8, ADCSOCB
                                                                           15h ADCTRIG21 - ePWM9, ADCSOCA
                                                                           16h ADCTRIG22 - ePWM9, ADCSOCB
                                                                           17h ADCTRIG23 - ePWM10, ADCSOCA
                                                                           18h ADCTRIG24 - ePWM10, ADCSOCB
                                                                           19h ADCTRIG25 - ePWM11, ADCSOCA
                                                                           1Ah ADCTRIG26 - ePWM11, ADCSOCB
                                                                           1Bh ADCTRIG27 - ePWM12, ADCSOCA
                                                                           1Ch ADCTRIG28 - ePWM12, ADCSOCB
                                                                           1Dh ADCTRIG29 - CPU2 Timer 0, TINT0n
                                                                           1Eh ADCTRIG30 - CPU2 Timer 1, TINT1n
                                                                           1Fh ADCTRIG31 - CPU2 Timer 2, TINT2n
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_1                     : 7 ;  /*!< [31:25] : reserved. */
        } ADCSOCCTLb;
    } ADCSOCCTL[16];                                        /*!< ADC SOC0-15 Control Register */

    union
    {
        __IM  uint32_t ADCEVTSTAT                        ;  /*!< 0x00000060 : ADC Event Status Register */
    
        struct
        {
            __IM  uint32_t PPB1TRIPHI                : 1 ;  /*!< [ 0: 0] : Post Processing Block 1 Trip High Flag. When set indicates a digital compare trip high event has occurred.
                                                                           Reset type: SYSRSn */
            __IM  uint32_t PPB1TRIPLO                : 1 ;  /*!< [ 1: 1] : Post Processing Block 1 Trip Low Flag. When set indicates a digital compare trip low event has occurred.
                                                                           Reset type: SYSRSn */
            __IM  uint32_t PPB1ZERO                  : 1 ;  /*!< [ 2: 2] : Post Processing Block 1 Zero Crossing Flag. When set indicates the ADCPPB1RESULT register has changed sign. This bit is gated by EOC signal.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 1 ;  /*!< [ 3: 3] : reserved. */
            __IM  uint32_t PPB2TRIPHI                : 1 ;  /*!< [ 4: 4] : Post Processing Block 2 Trip High Flag. When set indicates a digital compare trip high event has occurred.
                                                                           Reset type: SYSRSn */
            __IM  uint32_t PPB2TRIPLO                : 1 ;  /*!< [ 5: 5] : Post Processing Block 2 Trip Low Flag. When set indicates a digital compare trip low event has occurred.
                                                                           Reset type: SYSRSn */
            __IM  uint32_t PPB2ZERO                  : 1 ;  /*!< [ 6: 6] : Post Processing Block 2 Zero Crossing Flag. When set indicates the ADCPPB2RESULT register has changed sign. This bit is gated by EOC signal.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_1                     : 1 ;  /*!< [ 7: 7] : reserved. */
            __IM  uint32_t PPB3TRIPHI                : 1 ;  /*!< [ 8: 8] : Post Processing Block 3 Trip High Flag. When set indicates a digital compare trip high event has occurred.
                                                                           Reset type: SYSRSn */
            __IM  uint32_t PPB3TRIPLO                : 1 ;  /*!< [ 9: 9] : Post Processing Block 3 Trip Low Flag. When set indicates a digital compare trip low event has occurred.
                                                                           Reset type: SYSRSn */
            __IM  uint32_t PPB3ZERO                  : 1 ;  /*!< [10:10] : Post Processing Block 3 Zero Crossing Flag. When set indicates the ADCPPB3RESULT register has changed sign. This bit is gated by EOC signal.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_2                     : 1 ;  /*!< [11:11] : reserved. */
            __IM  uint32_t PPB4TRIPHI                : 1 ;  /*!< [12:12] : Post Processing Block 4 Trip High Flag. When set indicates a digital compare trip high event has occurred.
                                                                           Reset type: SYSRSn */
            __IM  uint32_t PPB4TRIPLO                : 1 ;  /*!< [13:13] : Post Processing Block 4 Trip Low Flag. When set indicates a digital compare trip low event has occurred.
                                                                           Reset type: SYSRSn */
            __IM  uint32_t PPB4ZERO                  : 1 ;  /*!< [14:14] : Post Processing Block 4 Zero Crossing Flag. When set indicates the ADCPPB4RESULT register has changed sign. This bit is gated by EOC signal.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_3                     : 17;  /*!< [31:15] : reserved. */
        } ADCEVTSTATb;
    };

    union
    {
        __IOM uint32_t ADCEVTCLR                         ;  /*!< 0x00000064 : ADC Event Clear Register */
    
        struct
        {
            __IOM uint32_t PPB1TRIPHI                : 1 ;  /*!< [ 0: 0] : Post Processing Block 1 Trip High Clear. Clears the corresponding trip high flag in the ADCEVTSTAT register.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PPB1TRIPLO                : 1 ;  /*!< [ 1: 1] : Post Processing Block 1 Trip Low Clear. Clears the corresponding trip low flag in the ADCEVTSTAT register.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PPB1ZERO                  : 1 ;  /*!< [ 2: 2] : Post Processing Block 1 Zero Crossing Clear. Clears the corresponding zero crossing flag in the ADCEVTSTAT register.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 1 ;  /*!< [ 3: 3] : reserved. */
            __IOM uint32_t PPB2TRIPHI                : 1 ;  /*!< [ 4: 4] : Post Processing Block 2 Trip High Clear. Clears the corresponding trip high flag in the ADCEVTSTAT register.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PPB2TRIPLO                : 1 ;  /*!< [ 5: 5] : Post Processing Block 2 Trip Low Clear. Clears the corresponding trip low flag in the ADCEVTSTAT register.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PPB2ZERO                  : 1 ;  /*!< [ 6: 6] : Post Processing Block 2 Zero Crossing Clear. Clears the corresponding zero crossing flag in the ADCEVTSTAT register.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_1                     : 1 ;  /*!< [ 7: 7] : reserved. */
            __IOM uint32_t PPB3TRIPHI                : 1 ;  /*!< [ 8: 8] : Post Processing Block 3 Trip High Clear. Clears the corresponding trip high flag in the ADCEVTSTAT register.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PPB3TRIPLO                : 1 ;  /*!< [ 9: 9] : Post Processing Block 3 Trip Low Clear. Clears the corresponding trip low flag in the ADCEVTSTAT register.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PPB3ZERO                  : 1 ;  /*!< [10:10] : Post Processing Block 3 Zero Crossing Clear. Clears the corresponding zero crossing flag in the ADCEVTSTAT register.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_2                     : 1 ;  /*!< [11:11] : reserved. */
            __IOM uint32_t PPB4TRIPHI                : 1 ;  /*!< [12:12] : Post Processing Block 4 Trip High Clear. Clears the corresponding trip high flag in the ADCEVTSTAT register.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PPB4TRIPLO                : 1 ;  /*!< [13:13] : Post Processing Block 4 Trip Low Clear. Clears the corresponding trip low flag in the ADCEVTSTAT register.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PPB4ZERO                  : 1 ;  /*!< [14:14] : Post Processing Block 4 Zero Crossing Clear. Clears the corresponding zero crossing flag in the ADCEVTSTAT register.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_3                     : 17;  /*!< [31:15] : reserved. */
        } ADCEVTCLRb;
    };

    union
    {
        __IOM uint32_t ADCEVTSEL                         ;  /*!< 0x00000068 : ADC Event Selection Register */
    
        struct
        {
            __IOM uint32_t PPB1TRIPHI                : 1 ;  /*!< [ 0: 0] : Post Processing Block 1 Trip High Event Enable. Setting this bit allows the corresponding rising trip high flag to activate the event signal to the PWM blocks. The flag must be cleared before it can produce additional events to the PWM blocks.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PPB1TRIPLO                : 1 ;  /*!< [ 1: 1] : Post Processing Block 1 Trip Low Event Enable. Setting this bit allows the corresponding rising trip low flag to activate the event signal to the PWM blocks. The flag must be cleared before it can produce additional events to the PWM blocks.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PPB1ZERO                  : 1 ;  /*!< [ 2: 2] : Post Processing Block 1 Zero Crossing Event Enable. Setting this bit allows the corresponding rising zero crossing flag to activate the event signal to the PWM blocks. The flag must be cleared before it can produce additional events to the PWM blocks.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 1 ;  /*!< [ 3: 3] : reserved. */
            __IOM uint32_t PPB2TRIPHI                : 1 ;  /*!< [ 4: 4] : Post Processing Block 2 Trip High Event Enable. Setting this bit allows the corresponding rising trip high flag to activate the event signal to the PWM blocks. The flag must be cleared before it can produce additional events to the PWM blocks.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PPB2TRIPLO                : 1 ;  /*!< [ 5: 5] : Post Processing Block 2 Trip Low Event Enable. Setting this bit allows the corresponding rising trip low flag to activate the event signal to the PWM blocks. The flag must be cleared before it can produce additional events to the PWM blocks.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PPB2ZERO                  : 1 ;  /*!< [ 6: 6] : Post Processing Block 2 Zero Crossing Event Enable. Setting this bit allows the corresponding rising zero crossing flag to activate the event signal to the PWM blocks. The flag must be cleared before it can produce additional events to the PWM blocks.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_1                     : 1 ;  /*!< [ 7: 7] : reserved. */
            __IOM uint32_t PPB3TRIPHI                : 1 ;  /*!< [ 8: 8] : Post Processing Block 3 Trip High Event Enable. Setting this bit allows the corresponding rising trip high flag to activate the event signal to the PWM blocks. The flag must be cleared before it can produce additional events to the PWM blocks.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PPB3TRIPLO                : 1 ;  /*!< [ 9: 9] : Post Processing Block 3 Trip Low Event Enable. Setting this bit allows the corresponding rising trip low flag to activate the event signal to the PWM blocks. The flag must be cleared before it can produce additional events to the PWM blocks.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PPB3ZERO                  : 1 ;  /*!< [10:10] : Post Processing Block 3 Zero Crossing Event Enable. Setting this bit allows the corresponding rising zero crossing flag to activate the event signal to the PWM blocks. The flag must be cleared before it can produce additional events to the PWM blocks.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_2                     : 1 ;  /*!< [11:11] : reserved. */
            __IOM uint32_t PPB4TRIPHI                : 1 ;  /*!< [12:12] : Post Processing Block 4 Trip High Event Enable. Setting this bit allows the corresponding rising trip high flag to activate the event signal to the PWM blocks. The flag must be cleared before it can produce additional events to the PWM blocks.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PPB4TRIPLO                : 1 ;  /*!< [13:13] : Post Processing Block 4 Trip Low Event Enable. Setting this bit allows the corresponding rising trip low flag to activate the event signal to the PWM blocks. The flag must be cleared before it can produce additional events to the PWM blocks.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PPB4ZERO                  : 1 ;  /*!< [14:14] : Post Processing Block 4 Zero Crossing Event Enable. Setting this bit allows the corresponding rising zero crossing flag to activate the event signal to the PWM blocks. The flag must be cleared before it can produce additional events to the PWM blocks.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_3                     : 17;  /*!< [31:15] : reserved. */
        } ADCEVTSELb;
    };

    union
    {
        __IOM uint32_t ADCEVTINTSEL                      ;  /*!< 0x0000006c : ADC Event Interrupt Selection Register */
    
        struct
        {
            __IOM uint32_t PPB1TRIPHI                : 1 ;  /*!< [ 0: 0] : Post Processing Block 1 Trip High Interrupt Enable. Setting this bit allows the corresponding rising trip high flag to activate the event interrupt signal to the PIE. The flag must be cleared before it can produce additional interrupts to the PIE.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PPB1TRIPLO                : 1 ;  /*!< [ 1: 1] : Post Processing Block 1 Trip Low Interrupt Enable. Setting this bit allows the corresponding rising trip low flag to activate the event interrupt signal to the PIE. The flag must be cleared before it can produce additional interrupts to the PIE.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PPB1ZERO                  : 1 ;  /*!< [ 2: 2] : Post Processing Block 1 Zero Crossing Interrupt Enable. Setting this bit allows the corresponding rising zero crossing flag to activate the event interrupt signal to the PIE. The flag must be cleared before it can produce additional interrupts to the PIE.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 1 ;  /*!< [ 3: 3] : reserved. */
            __IOM uint32_t PPB2TRIPHI                : 1 ;  /*!< [ 4: 4] : Post Processing Block 2 Trip High Interrupt Enable. Setting this bit allows the corresponding rising trip high flag to activate the event interrupt signal to the PIE. The flag must be cleared before it can produce additional interrupts to the PIE.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PPB2TRIPLO                : 1 ;  /*!< [ 5: 5] : Post Processing Block 2 Trip Low Interrupt Enable. Setting this bit allows the corresponding rising trip low flag to activate the event interrupt signal to the PIE. The flag must be cleared before it can produce additional interrupts to the PIE.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PPB2ZERO                  : 1 ;  /*!< [ 6: 6] : Post Processing Block 2 Zero Crossing Interrupt Enable. Setting this bit allows the corresponding rising zero crossing flag to activate the event interrupt signal to the PIE. The flag must be cleared before it can produce additional interrupts to the PIE.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_1                     : 1 ;  /*!< [ 7: 7] : reserved. */
            __IOM uint32_t PPB3TRIPHI                : 1 ;  /*!< [ 8: 8] : Post Processing Block 3 Trip High Interrupt Enable. Setting this bit allows the corresponding rising trip high flag to activate the event interrupt signal to the PIE. The flag must be cleared before it can produce additional interrupts to the PIE.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PPB3TRIPLO                : 1 ;  /*!< [ 9: 9] : Post Processing Block 3 Trip Low Interrupt Enable. Setting this bit allows the corresponding rising trip low flag to activate the event interrupt signal to the PIE. The flag must be cleared before it can produce additional interrupts to the PIE.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PPB3ZERO                  : 1 ;  /*!< [10:10] : Post Processing Block 3 Zero Crossing Interrupt Enable. Setting this bit allows the corresponding rising zero crossing flag to activate the event interrupt signal to the PIE. The flag must be cleared before it can produce additional interrupts to the PIE.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_2                     : 1 ;  /*!< [11:11] : reserved. */
            __IOM uint32_t PPB4TRIPHI                : 1 ;  /*!< [12:12] : Post Processing Block 4 Trip High Interrupt Enable. Setting this bit allows the corresponding rising trip high flag to activate the event interrupt signal to the PIE. The flag must be cleared before it can produce additional interrupts to the PIE.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PPB4TRIPLO                : 1 ;  /*!< [13:13] : Post Processing Block 4 Trip Low Interrupt Enable. Setting this bit allows the corresponding rising trip low flag to activate the event interrupt signal to the PIE. The flag must be cleared before it can produce additional interrupts to the PIE.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t PPB4ZERO                  : 1 ;  /*!< [14:14] : Post Processing Block 4 Zero Crossing Interrupt Enable. Setting this bit allows the corresponding rising zero crossing flag to activate the event interrupt signal to the PIE. The flag must be cleared before it can produce additional interrupts to the PIE.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_3                     : 17;  /*!< [31:15] : reserved. */
        } ADCEVTINTSELb;
    };

    uint8_t    RSV_0X70[2]                               ;  /*!< 0x00000070~0x00000071 : reserved */

    union
    {
        __IM  uint16_t ADCCOUNTER                        ;  /*!< 0x00000072 : ADC Counter Register */
    
        struct
        {
            __IM  uint16_t FREECOUNT                 : 12;  /*!< [11: 0] : ADC Free Running Counter Value. This bit field reflects the status of the free running ADC counter.
                                                                           Reset type: SYSRSn */
                  uint16_t RSV_0                     : 4 ;  /*!< [15:12] : reserved. */
        } ADCCOUNTERb;
    };

    union
    {
        __IM  uint16_t ADCREV                            ;  /*!< 0x00000074 : ADC Revision Register */
    
        struct
        {
            __IM  uint16_t ADCTYPE                   : 8 ;  /*!< [ 7: 0] : ADC Type. Always set to 0 for this ADC.
                                                                           Reset type: SYSRSn */
            __IM  uint16_t REV                       : 8 ;  /*!< [15: 8] : ADC Revision. To allow documentation of differences between
                                                                           revisions. First version is labeled as 00h.
                                                                           Reset type: SYSRSn */
        } ADCREVb;
    };

    union
    {
        __IOM uint16_t ADCOFFTRIM                        ;  /*!< 0x00000076 : ADC Offset Trim Register */
    
        struct
        {
            __IOM uint16_t OFFTRIM                   : 16;  /*!< [15: 0] : ADC Offset Trim. Adjusts the conversion results of the converter up or down to account for offset error in the ADC. A different offset trim is required for each combination of resolution and signal mode.
                                                                           Using the AdcSetMode function to set the resolution and signal mode will ensure that the correct offset trim is loaded.
                                                                           Range is +32767 steps to -32768 steps (2's compliment format).
                                                                           Reset type: SYSRSn */
        } ADCOFFTRIMb;
    };

    uint8_t    RSV_0X78[8]                               ;  /*!< 0x00000078~0x0000007f : reserved */

    struct
    {
    union
    {
        __IOM uint16_t PPBCFG                            ;  /*!< 0x00000080 : ADC PPB1 Config Register */
    
        struct
        {
            __IOM uint16_t PPB1CONFIG                : 4 ;  /*!< [ 3: 0] : ADC Post Processing Block 1 Configuration. This bit field defines which SOC/EOC/RESULT is assocatied with this post processing block.
                                                                           0000 SOC0/EOC0/RESULT0 is associated with post processing block 1
                                                                           0001 SOC1/EOC1/RESULT1 is associated with post processing block 1
                                                                           0010 SOC2/EOC2/RESULT2 is associated with post processing block 1
                                                                           0011 SOC3/EOC3/RESULT3 is associated with post processing block 1
                                                                           0100 SOC4/EOC4/RESULT4 is associated with post processing block 1
                                                                           0101 SOC5/EOC5/RESULT5 is associated with post processing block 1
                                                                           0110 SOC6/EOC6/RESULT6 is associated with post processing block 1
                                                                           0111 SOC7/EOC7/RESULT7 is associated with post processing block 1
                                                                           1000 SOC8/EOC8/RESULT8 is associated with post processing block 1
                                                                           1001 SOC9/EOC9/RESULT9 is associated with post processing block 1
                                                                           1010 SOC10/EOC10/RESULT10 is associated with post processing block 1
                                                                           1011 SOC11/EOC11/RESULT11 is associated with post processing block 1
                                                                           1100 SOC12/EOC12/RESULT12 is associated with post processing block 1
                                                                           1101 SOC13/EOC13/RESULT13 is associated with post processing block 1
                                                                           1110 SOC14/EOC14/RESULT14 is associated with post processing block 1
                                                                           1111 SOC15/EOC15/RESULT15 is associated with post processing block 1
                                                                           Reset type: SYSRSn */
            __IOM uint16_t TWOSCOMPEN                : 1 ;  /*!< [ 4: 4] : ADC Post Processing Block 1 Two's Complement Enable. When set this bit enables the post conversion hardware processing circuit that performs a two's complement on the output of the offset/reference subtraction unit before storing the result in the ADCPPB1RESULT register.
                                                                           0 ADCPPB1RESULT = ADCRESULTx - ADCPPB1OFFREF
                                                                           1 ADCPPB1RESULT = ADCPPB1OFFREF - ADCRESULTx
                                                                           Reset type: SYSRSn */
            __IOM uint16_t CBCEN                     : 1 ;  /*!< [ 5: 5] : ADC Post Processing Block Cycle By Cycle Enable. When set, this
                                                                           bit enables the post conversion hardware processing circuit to
                                                                           automatically clear the ADCEVTSTAT on a conversion if the event
                                                                           condition is no longer present.
                                                                           Reset type: SYSRSn */
                  uint16_t RSV_0                     : 10;  /*!< [15: 6] : reserved. */
        } PPBCFGb;
    };

    union
    {
        __IM  uint16_t PPBSTAMP                          ;  /*!< 0x00000082 : ADC PPB1 Sample Delay Time Stamp Register */
    
        struct
        {
            __IM  uint16_t DLYSTAMP                  : 12;  /*!< [11: 0] : ADC Post Processing Block 1 Delay Time Stamp. When an SOC starts sampling the value contained in REQSTAMP is subtracted from the value in ADCCOUNTER.FREECOUNT and loaded into this bit field, thereby giving the number of system clock cycles delay between the SOC trigger and the actual start of the sample.
                                                                           Reset type: SYSRSn */
                  uint16_t RSV_0                     : 4 ;  /*!< [15:12] : reserved. */
        } PPBSTAMPb;
    };

    union
    {
        __IOM uint16_t PPBOFFCAL                         ;  /*!< 0x00000084 : ADC PPB1 Offset Calibration Register */
    
        struct
        {
            __IOM uint16_t OFFCAL                    : 10;  /*!< [ 9: 0] : ADC Post Processing Block 1 Offset Correction. This bit field can be used to digitally remove any system level offset inherent in the ADCIN circuit. This 10-bit signed value is subtracted from the ADC output before being stored in the ADCRESULT register.
                                                                           000h No change. The ADC output is stored directly into ADCRESULT.
                                                                           001h ADC output - 1 is stored into ADCRESULT. 002h ADC output - 2 is stored into ADCRESULT.
                                                                           ...
                                                                           200h ADC output + 512 is stored into ADCRESULT.
                                                                           ...
                                                                           3FFh ADC output + 1 is stored into ADCRESULT.
                                                                           NOTE: In 16-bit mode, the subtraction will saturate at 0000h and FFFFh before being stored into the ADCRESULT register. In 12-bit mode, the subtraction will saturate at 0000h and 0FFFh before being stored into the ADCRESULT register.
                                                                           Reset type: SYSRSn */
                  uint16_t RSV_0                     : 6 ;  /*!< [15:10] : reserved. */
        } PPBOFFCALb;
    };

    union
    {
        __IOM uint16_t PPBOFFREF                         ;  /*!< 0x00000086 : ADC PPB1 Offset Reference Register */
    
        struct
        {
            __IOM uint16_t OFFREF                    : 16;  /*!< [15: 0] : ADC Post Processing Block 1 Offset Correction. This bit field can be used to either calculate the feedback error or convert a unipolar signal to bipolar by subtracting a reference value. This 16-bit unsigned value is subtracted from the ADCRESULT register before being passed through an optional two's complement function and stored in the ADCPPB1RESULT register. This subtraction is not saturated.
                                                                           0000h No change. The ADCRESULT value is passed on. 0001h ADCRESULT - 1 is passed on.
                                                                           0002h ADCRESULT - 2 is passed on.
                                                                           ...
                                                                           8000h ADCRESULT - 32,768 is passed on.
                                                                           ...
                                                                           FFFFh ADCRESULT - 65,535 is passed on.
                                                                           NOTE: In 12-bit mode the size of this register does not change from 16-bits. It is the user's responsibility to ensure that only a 12-bit value is written to this register when in 12-bit mode.
                                                                           Reset type: SYSRSn */
        } PPBOFFREFb;
    };

    union
    {
        __IOM uint32_t PPBTRIPHI                         ;  /*!< 0x00000088 : ADC PPB1 Trip High Register */
    
        struct
        {
            __IOM uint32_t LIMITHI                   : 16;  /*!< [15: 0] : ADC Post Processing Block 1 Trip High Limit. This value sets the digital comparator trip high limit. In 16-bit mode all 17 bits will be compared against the 17 bits of the PPBRESULT bit field of the ADCPPB1RESULT register. In 12-bit mode bits 12:0 will be compared against bits 12:0 of the PPBRESULT bit field of the ADCPPB1RESULT register.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t HSIGN                     : 1 ;  /*!< [16:16] : High Limit Sign Bit. This is the sign bit (17th bit) to the LIMITHI bit field when in 16-bit ADC mode.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 15;  /*!< [31:17] : reserved. */
        } PPBTRIPHIb;
    };

    union
    {
        __IOM uint32_t PPBTRIPLO                         ;  /*!< 0x0000008c : ADC PPB1 Trip Low/Trigger Time Stamp Register */
    
        struct
        {
            __IOM uint32_t LIMITLO                   : 16;  /*!< [15: 0] : ADC Post Processing Block 1 Trip Low Limit. This value sets the digital comparator trip low limit. In 16-bit mode all 17 bits will be compared against the 17 bits of the PPBRESULT bit field of the ADCPPB1RESULT register. In 12-bit mode bits 12:0 will be compared against bits 12:0 of the PPBRSULT bit field of the ADCPPB1RESULT register.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t LSIGN                     : 1 ;  /*!< [16:16] : Low Limit Sign Bit. This is the sign bit (17th bit) to the LIMITLO bit field when in 16-bit ADC mode.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 3 ;  /*!< [19:17] : reserved. */
            __IM  uint32_t REQSTAMP                  : 12;  /*!< [31:20] : ADC Post Processing Block 1 Request Time Stamp. When a trigger sets the associated SOC flag in the ADCSOCFLG1 register the value of ADCCOUNTER.FREECOUNT is loaded into this bit field.
                                                                           Reset type: SYSRSn */
        } PPBTRIPLOb;
    };

    }ADCPPBCREG[4];                                         /*!< ADC PPB0-3 Register */

    uint8_t    RSV_0XC0[30]                              ;  /*!< 0x000000c0~0x000000dd : reserved */

    union
    {
        __IOM uint16_t ADCINTCYCLE                       ;  /*!< 0x000000de : ADC Early Interrupt Generation Cycle */
    
        struct
        {
            __IOM uint16_t DELAY                     : 16;  /*!< [15: 0] : ADC Early Interrupt Generation Cycle Delay: Defines the delay from
                                                                           the fall edge of ADCSOC in terms of system clock cycles, for the
                                                                           interrupt to be generated.
                                                                           Reset type: SYSRSn */
        } ADCINTCYCLEb;
    };

    union
    {
        __IOM uint32_t ADCINLTRIM1                       ;  /*!< 0x000000e0 : ADC Linearity Trim 1 Register */
    
        struct
        {
            __IOM uint32_t INLTRIM31TO0              : 32;  /*!< [31: 0] : ADC Linearity Trim Bits 31-0.
                                                                           This register should not be modified unless specifically indicated by HTE Errata or other documentation. Modifying the contents of this register could cause this module to operate outside of datasheet specifications.
                                                                           Reset type: SYSRSn */
        } ADCINLTRIM1b;
    };

    union
    {
        __IOM uint32_t ADCINLTRIM2                       ;  /*!< 0x000000e4 : ADC Linearity Trim 2 Register */
    
        struct
        {
            __IOM uint32_t INLTRIM63TO32             : 32;  /*!< [31: 0] : ADC Linearity Trim Bits 63-32.
                                                                           This register should not be modified unless specifically indicated by HTE Errata or other documentation. Modifying the contents of this register could cause this module to operate outside of datasheet specifications.
                                                                           Reset type: SYSRSn */
        } ADCINLTRIM2b;
    };

    union
    {
        __IOM uint32_t ADCINLTRIM3                       ;  /*!< 0x000000e8 : ADC Linearity Trim 3 Register */
    
        struct
        {
            __IOM uint32_t INLTRIM95TO64             : 32;  /*!< [31: 0] : ADC Linearity Trim Bits 95-64.
                                                                           This register should not be modified unless specifically indicated by HTE Errata or other documentation. Modifying the contents of this register could cause this module to operate outside of datasheet specifications.
                                                                           Reset type: SYSRSn */
        } ADCINLTRIM3b;
    };

    union
    {
        __IOM uint32_t ADCINLTRIM4                       ;  /*!< 0x000000ec : ADC Linearity Trim 4 Register */
    
        struct
        {
            __IOM uint32_t INLTRIM127TO96            : 32;  /*!< [31: 0] : ADC Linearity Trim Bits 127-96.
                                                                           This register should not be modified unless specifically indicated by HTE Errata or other documentation. Modifying the contents of this register could cause this module to operate outside of datasheet specifications.
                                                                           Reset type: SYSRSn */
        } ADCINLTRIM4b;
    };

    union
    {
        __IOM uint32_t ADCINLTRIM5                       ;  /*!< 0x000000f0 : ADC Linearity Trim 5 Register */
    
        struct
        {
            __IOM uint32_t INLTRIM159TO128           : 32;  /*!< [31: 0] : ADC Linearity Trim Bits 159-128.
                                                                           This register should not be modified unless specifically indicated by HTE Errata or other documentation. Modifying the contents of this register could cause this module to operate outside of datasheet specifications.
                                                                           Reset type: SYSRSn */
        } ADCINLTRIM5b;
    };

    union
    {
        __IOM uint32_t ADCINLTRIM6                       ;  /*!< 0x000000f4 : ADC Linearity Trim 6 Register */
    
        struct
        {
            __IOM uint32_t INLTRIM191TO160           : 32;  /*!< [31: 0] : ADC Linearity Trim Bits 191-160.
                                                                           This register should not be modified unless specifically indicated by HTE Errata or other documentation. Modifying the contents of this register could cause this module to operate outside of datasheet specifications.
                                                                           Reset type: SYSRSn */
        } ADCINLTRIM6b;
    };

    union
    {
        __IOM uint32_t ADCSOCCNV                         ;  /*!< 0x000000f8 : ADC SOC0 conversion time setting Register */
    
        struct
        {
            __IOM uint32_t SOCCNV                    : 32;  /*!< [31: 0] : SOC0 conversion time.
                                                                           The register will decide the coversion window. Please refer the spec to configure the time to ensure coversion and sample rate.
                                                                           000h Conversion window is 1 system clock cycle wide 001h Conversion window is 2 system clock cycles wide 002h Conversion window is 3 system clock cycles wide
                                                                           ...
                                                                           Reset type: SYSRSn */
        } ADCSOCCNVb;
    } ADCSOCCNV[16];                                        /*!< ADC SOC0-15 conversion time */

    union
    {
        __IOM uint32_t ADCCTL3                           ;  /*!< 0x00000138 : ADC Control 3 Register */
    
        struct
        {
            __IOM uint32_t MUXDELAY                  : 16;  /*!< [15: 0] : ADC mux delay.
                                                                           After switch the channel mux, hardware will delay these system cycles until start sample window if trigger source is pending.
                                                                           0h Delay 1 system cycles
                                                                           01h Delat 2 system cycles
                                                                           ...
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 16;  /*!< [31:16] : reserved. */
        } ADCCTL3b;
    };

    union
    {
        __IOM uint32_t ADCCTL4                           ;  /*!< 0x0000013c : ADC Control 4 Register */
    
        struct
        {
            __IOM uint32_t AUTOK                     : 1 ;  /*!< [ 0: 0] : Linearity auto calibration bit.
                                                                           When set, hardware will auto calibrate the linearity of the ADC analog core. The application will poll the bit until automatically clear by hardware when calibration is finish.
                                                                           When in nomal application, user must not use this bit. This bit will be used during CP or FT.
                                                                           The linearity calibration will use adc result registers as output result temporary.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t ADC_AUTOK_NUM             : 2 ;  /*!< [ 2: 1] : ADC auto calibration repeat num.
                                                                           00: 1000
                                                                           01: 750
                                                                           10: 500
                                                                           11: 250 */
                  uint32_t RSV_0                     : 13;  /*!< [15: 3] : reserved. */
            __IOM uint32_t MISC_DBG_SEL              : 2 ;  /*!< [17:16] : ADC misc block debug select. */
            __IOM uint32_t TOP_DBG_SEL               : 3 ;  /*!< [20:18] : ADC Top debug select. */
                  uint32_t RSV_1                     : 11;  /*!< [31:21] : reserved. */
        } ADCCTL4b;
    };

    union
    {
        __IOM uint32_t ADCGAINERR                        ;  /*!< 0x00000140 : ADC Gain Error */
    
        struct
        {
            __IOM uint32_t GAINERR                   : 32;  /*!< [31: 0] : Gain error.
                                                                           The register will be used to trim the gain error. User must save the gain error as Q16 fixed pointer into this register because 16bit effective binary precision digits need to guarantee.
                                                                           The range is 0-2. For example, if gain error is caculated as 1.0123, then this register will save 1.0123*2^16, and keep integer only.
                                                                           Reset type: SYSRSn */
        } ADCGAINERRb;
    };

    union
    {
        __IOM uint32_t ADCCALCTRL                        ;  /*!< 0x00000144 : ADC Calibrate control Register */
    
        struct
        {
            __IOM uint32_t CALEN                     : 1 ;  /*!< [ 0: 0] : Calibrate Enable
                                                                           adc calibration enable signal; defualt: 0
                                                                           Reset type: SYSRSn */
            __IOM uint32_t CALSET                    : 1 ;  /*!< [ 1: 1] : toggle from 0 to 1 when reg_cal_en=1; for linearity calibraion;  bit_w=adc_out(cal_set=0)-adc_out(cal_set=1)
                                                                           Reset type: SYSRSn */
            __IOM uint32_t CALCTRL                   : 4 ;  /*!< [ 5: 2] : calibration bit sel:  (000:d0 001:d1....)  calibration sequence: d11 to d0
                                                                           Reset type: SYSRSn */
            __IOM uint32_t OFFDIFCAL                 : 1 ;  /*!< [ 6: 6] : short adc 2 input to vcm_int; differential mode adc offset calibration
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 24;  /*!< [30: 7] : reserved. */
            __IOM uint32_t ADCLOCK                   : 1 ;  /*!< [31:31] : Lock adc calibration register and bias configuration register. */
        } ADCCALCTRLb;
    };

    union
    {
        __IOM uint32_t ADCBIAS                           ;  /*!< 0x00000148 : ADC bias Configurate Register */
    
        struct
        {
            __IOM uint32_t CMPBIAS1                  : 3 ;  /*!< [ 2: 0] : adc bias configuration
                                                                           Reset type: SYSRSn */
            __IOM uint32_t CMPBIAS2                  : 3 ;  /*!< [ 5: 3] : adc bias configuration
                                                                           Reset type: SYSRSn */
            __IOM uint32_t CMPBIAS3                  : 3 ;  /*!< [ 8: 6] : adc bias configuration
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 15;  /*!< [23: 9] : reserved. */
            __IOM uint32_t DUMMY1                    : 8 ;  /*!< [31:24] : adc dummy register to adc core. */
        } ADCBIASb;
    };

    uint8_t    RSV_0X14C[692]                            ;  /*!< 0x0000014c~0x000003ff : reserved */
} ADC_Type;

/*! \brief ADC_RESULT register */
typedef struct {
    union
    {
        __IM  uint16_t ADCRESULT                         ;  /*!< 0x00100000 : ADC Result 0 Register */
    
        struct
        {
            __IM  uint16_t RESULT                    : 16;  /*!< [15: 0] : ADC Result 0
                                                                           16-bit ADC result. After the ADC completes a conversion of SOC0, the digital result is placed in this bit field.
                                                                           Reset type: SYSRSn */
        } ADCRESULTb;
    } ADCRESULT[16];                                        /*!< ADC RESULT Register0-15 */

    union
    {
        __IM  uint32_t ADCPPBRESULT                      ;  /*!< 0x00100020 : ADC Post Processing Block 1 Result Rsgister */
    
        struct
        {
            __IM  uint32_t PPBRESULT                 : 16;  /*!< [15: 0] : ADC Post Processing Block Result 1
                                                                           The result of the offset/reference subtraction post conversion processing is stored in this register. If ADCINTFLG is polled in reading PPBRESULT, user needs to add a NOP instruction to ensure that post conversion processing is populated in this register.
                                                                           NOTE: If the conversion associated with this Post Processing Block is a 12-bit conversion, the PPBRESULT bits are limited to bits 12:0.
                                                                           Reset type: SYSRSn */
            __IM  uint32_t SIGN                      : 16;  /*!< [31:16] : Sign Extended Bits. These bits reflect the same value as bit 16.
                                                                           NOTE: If the conversion associated with this Post Processing Block is a 12-bit conversion, the SIGN bits extend down to bit 12, and all reflect the same value as bit 12.
                                                                           Reset type: SYSRSn */
        } ADCPPBRESULTb;
    } ADCPPBRESULT[4];                                      /*!< ADC PPB RESULT0-3 */

    uint8_t    RSV_0X100030[976]                         ;  /*!< 0x00100030~0x001003ff : reserved */
} ADC_RESULT_Type;


/*!
 * @}
 */

/*!
 * \name ADC Base Address Definitions
 *
 * @{
 */

/*! \brief ADCA base address */
#define ADCA_BASE (0x40200000UL)
/*! \brief ADCB base address */
#define ADCB_BASE (0x40200400UL)
/*! \brief ADCC base address */
#define ADCC_BASE (0x40200800UL)
/*! \brief ADCD base address */
#define ADCD_BASE (0x40200c00UL)
/*! \brief ADCA base pointer */
#define ADCA ((ADC_Type *) ADCA_BASE)
/*! \brief ADCB base pointer */
#define ADCB ((ADC_Type *) ADCB_BASE)
/*! \brief ADCC base pointer */
#define ADCC ((ADC_Type *) ADCC_BASE)
/*! \brief ADCD base pointer */
#define ADCD ((ADC_Type *) ADCD_BASE)

/*! \brief ADC_RESULTA base address */
#define ADC_RESULTA_BASE (0x40300000UL)
/*! \brief ADC_RESULTB base address */
#define ADC_RESULTB_BASE (0x40300400UL)
/*! \brief ADC_RESULTC base address */
#define ADC_RESULTC_BASE (0x40300800UL)
/*! \brief ADC_RESULTD base address */
#define ADC_RESULTD_BASE (0x40300c00UL)
/*! \brief ADC_RESULTA base pointer */
#define ADC_RESULTA ((ADC_RESULT_Type *) ADC_RESULTA_BASE)
/*! \brief ADC_RESULTB base pointer */
#define ADC_RESULTB ((ADC_RESULT_Type *) ADC_RESULTB_BASE)
/*! \brief ADC_RESULTC base pointer */
#define ADC_RESULTC ((ADC_RESULT_Type *) ADC_RESULTC_BASE)
/*! \brief ADC_RESULTD base pointer */
#define ADC_RESULTD ((ADC_RESULT_Type *) ADC_RESULTD_BASE)


/*!
 * @}
 */


/*!
 * \name ADC Register Bitfield Definitions
 *
 * @{
 */

/* ADCCTL1 bitfield */
#define ADC_ADCCTL1_ADCBSY_Pos                    (13U)                                                                                                 /*!< ADCBSY          Position  13         */
#define ADC_ADCCTL1_ADCBSY_Msk                    (0x1U << ADC_ADCCTL1_ADCBSY_Pos)                                                                      /*!< ADCBSY          Mask      0x00002000 */
#define ADC_ADCCTL1_ADCBSY_Set(x)                 (((uint16_t) (x) << ADC_ADCCTL1_ADCBSY_Pos) & ADC_ADCCTL1_ADCBSY_Msk)                                 /*!< ADCBSY          Set Value            */
#define ADC_ADCCTL1_ADCBSY_Get(x)                 (((uint16_t) (x) & ADC_ADCCTL1_ADCBSY_Msk) >> ADC_ADCCTL1_ADCBSY_Pos)                                 /*!< ADCBSY          Get Value            */

#define ADC_ADCCTL1_ADCBSYCHN_Pos                 (8U)                                                                                                  /*!< ADCBSYCHN       Position  8          */
#define ADC_ADCCTL1_ADCBSYCHN_Msk                 (0xfU << ADC_ADCCTL1_ADCBSYCHN_Pos)                                                                   /*!< ADCBSYCHN       Mask      0x00000F00 */
#define ADC_ADCCTL1_ADCBSYCHN_Set(x)              (((uint16_t) (x) << ADC_ADCCTL1_ADCBSYCHN_Pos) & ADC_ADCCTL1_ADCBSYCHN_Msk)                           /*!< ADCBSYCHN       Set Value            */
#define ADC_ADCCTL1_ADCBSYCHN_Get(x)              (((uint16_t) (x) & ADC_ADCCTL1_ADCBSYCHN_Msk) >> ADC_ADCCTL1_ADCBSYCHN_Pos)                           /*!< ADCBSYCHN       Get Value            */

#define ADC_ADCCTL1_ADCPWDNZ_Pos                  (7U)                                                                                                  /*!< ADCPWDNZ        Position  7          */
#define ADC_ADCCTL1_ADCPWDNZ_Msk                  (0x1U << ADC_ADCCTL1_ADCPWDNZ_Pos)                                                                    /*!< ADCPWDNZ        Mask      0x00000080 */
#define ADC_ADCCTL1_ADCPWDNZ_Set(x)               (((uint16_t) (x) << ADC_ADCCTL1_ADCPWDNZ_Pos) & ADC_ADCCTL1_ADCPWDNZ_Msk)                             /*!< ADCPWDNZ        Set Value            */
#define ADC_ADCCTL1_ADCPWDNZ_Get(x)               (((uint16_t) (x) & ADC_ADCCTL1_ADCPWDNZ_Msk) >> ADC_ADCCTL1_ADCPWDNZ_Pos)                             /*!< ADCPWDNZ        Get Value            */

#define ADC_ADCCTL1_INTPULSEPOS_Pos               (2U)                                                                                                  /*!< INTPULSEPOS     Position  2          */
#define ADC_ADCCTL1_INTPULSEPOS_Msk               (0x1U << ADC_ADCCTL1_INTPULSEPOS_Pos)                                                                 /*!< INTPULSEPOS     Mask      0x00000004 */
#define ADC_ADCCTL1_INTPULSEPOS_Set(x)            (((uint16_t) (x) << ADC_ADCCTL1_INTPULSEPOS_Pos) & ADC_ADCCTL1_INTPULSEPOS_Msk)                       /*!< INTPULSEPOS     Set Value            */
#define ADC_ADCCTL1_INTPULSEPOS_Get(x)            (((uint16_t) (x) & ADC_ADCCTL1_INTPULSEPOS_Msk) >> ADC_ADCCTL1_INTPULSEPOS_Pos)                       /*!< INTPULSEPOS     Get Value            */

/* ADCCTL2 bitfield */
#define ADC_ADCCTL2_SIGNALMODE_Pos                (7U)                                                                                                  /*!< SIGNALMODE      Position  7          */
#define ADC_ADCCTL2_SIGNALMODE_Msk                (0x1U << ADC_ADCCTL2_SIGNALMODE_Pos)                                                                  /*!< SIGNALMODE      Mask      0x00000080 */
#define ADC_ADCCTL2_SIGNALMODE_Set(x)             (((uint16_t) (x) << ADC_ADCCTL2_SIGNALMODE_Pos) & ADC_ADCCTL2_SIGNALMODE_Msk)                         /*!< SIGNALMODE      Set Value            */
#define ADC_ADCCTL2_SIGNALMODE_Get(x)             (((uint16_t) (x) & ADC_ADCCTL2_SIGNALMODE_Msk) >> ADC_ADCCTL2_SIGNALMODE_Pos)                         /*!< SIGNALMODE      Get Value            */

#define ADC_ADCCTL2_RESOLUTION_Pos                (6U)                                                                                                  /*!< RESOLUTION      Position  6          */
#define ADC_ADCCTL2_RESOLUTION_Msk                (0x1U << ADC_ADCCTL2_RESOLUTION_Pos)                                                                  /*!< RESOLUTION      Mask      0x00000040 */
#define ADC_ADCCTL2_RESOLUTION_Set(x)             (((uint16_t) (x) << ADC_ADCCTL2_RESOLUTION_Pos) & ADC_ADCCTL2_RESOLUTION_Msk)                         /*!< RESOLUTION      Set Value            */
#define ADC_ADCCTL2_RESOLUTION_Get(x)             (((uint16_t) (x) & ADC_ADCCTL2_RESOLUTION_Msk) >> ADC_ADCCTL2_RESOLUTION_Pos)                         /*!< RESOLUTION      Get Value            */

/* ADCBURSTCTL bitfield */
#define ADC_ADCBURSTCTL_BURSTEN_Pos               (15U)                                                                                                 /*!< BURSTEN         Position  15         */
#define ADC_ADCBURSTCTL_BURSTEN_Msk               (0x1U << ADC_ADCBURSTCTL_BURSTEN_Pos)                                                                 /*!< BURSTEN         Mask      0x00008000 */
#define ADC_ADCBURSTCTL_BURSTEN_Set(x)            (((uint16_t) (x) << ADC_ADCBURSTCTL_BURSTEN_Pos) & ADC_ADCBURSTCTL_BURSTEN_Msk)                       /*!< BURSTEN         Set Value            */
#define ADC_ADCBURSTCTL_BURSTEN_Get(x)            (((uint16_t) (x) & ADC_ADCBURSTCTL_BURSTEN_Msk) >> ADC_ADCBURSTCTL_BURSTEN_Pos)                       /*!< BURSTEN         Get Value            */

#define ADC_ADCBURSTCTL_BURSTSIZE_Pos             (8U)                                                                                                  /*!< BURSTSIZE       Position  8          */
#define ADC_ADCBURSTCTL_BURSTSIZE_Msk             (0xfU << ADC_ADCBURSTCTL_BURSTSIZE_Pos)                                                               /*!< BURSTSIZE       Mask      0x00000F00 */
#define ADC_ADCBURSTCTL_BURSTSIZE_Set(x)          (((uint16_t) (x) << ADC_ADCBURSTCTL_BURSTSIZE_Pos) & ADC_ADCBURSTCTL_BURSTSIZE_Msk)                   /*!< BURSTSIZE       Set Value            */
#define ADC_ADCBURSTCTL_BURSTSIZE_Get(x)          (((uint16_t) (x) & ADC_ADCBURSTCTL_BURSTSIZE_Msk) >> ADC_ADCBURSTCTL_BURSTSIZE_Pos)                   /*!< BURSTSIZE       Get Value            */

#define ADC_ADCBURSTCTL_BURSTTRIGSEL_Pos          (0U)                                                                                                  /*!< BURSTTRIGSEL    Position  0          */
#define ADC_ADCBURSTCTL_BURSTTRIGSEL_Msk          (0x3fU << ADC_ADCBURSTCTL_BURSTTRIGSEL_Pos)                                                           /*!< BURSTTRIGSEL    Mask      0x0000003F */
#define ADC_ADCBURSTCTL_BURSTTRIGSEL_Set(x)       (((uint16_t) (x) << ADC_ADCBURSTCTL_BURSTTRIGSEL_Pos) & ADC_ADCBURSTCTL_BURSTTRIGSEL_Msk)             /*!< BURSTTRIGSEL    Set Value            */
#define ADC_ADCBURSTCTL_BURSTTRIGSEL_Get(x)       (((uint16_t) (x) & ADC_ADCBURSTCTL_BURSTTRIGSEL_Msk) >> ADC_ADCBURSTCTL_BURSTTRIGSEL_Pos)             /*!< BURSTTRIGSEL    Get Value            */

/* ADCINTFLG bitfield */
#define ADC_ADCINTFLG_ADCINT4_Pos                 (3U)                                                                                                  /*!< ADCINT4         Position  3          */
#define ADC_ADCINTFLG_ADCINT4_Msk                 (0x1U << ADC_ADCINTFLG_ADCINT4_Pos)                                                                   /*!< ADCINT4         Mask      0x00000008 */
#define ADC_ADCINTFLG_ADCINT4_Set(x)              (((uint16_t) (x) << ADC_ADCINTFLG_ADCINT4_Pos) & ADC_ADCINTFLG_ADCINT4_Msk)                           /*!< ADCINT4         Set Value            */
#define ADC_ADCINTFLG_ADCINT4_Get(x)              (((uint16_t) (x) & ADC_ADCINTFLG_ADCINT4_Msk) >> ADC_ADCINTFLG_ADCINT4_Pos)                           /*!< ADCINT4         Get Value            */

#define ADC_ADCINTFLG_ADCINT3_Pos                 (2U)                                                                                                  /*!< ADCINT3         Position  2          */
#define ADC_ADCINTFLG_ADCINT3_Msk                 (0x1U << ADC_ADCINTFLG_ADCINT3_Pos)                                                                   /*!< ADCINT3         Mask      0x00000004 */
#define ADC_ADCINTFLG_ADCINT3_Set(x)              (((uint16_t) (x) << ADC_ADCINTFLG_ADCINT3_Pos) & ADC_ADCINTFLG_ADCINT3_Msk)                           /*!< ADCINT3         Set Value            */
#define ADC_ADCINTFLG_ADCINT3_Get(x)              (((uint16_t) (x) & ADC_ADCINTFLG_ADCINT3_Msk) >> ADC_ADCINTFLG_ADCINT3_Pos)                           /*!< ADCINT3         Get Value            */

#define ADC_ADCINTFLG_ADCINT2_Pos                 (1U)                                                                                                  /*!< ADCINT2         Position  1          */
#define ADC_ADCINTFLG_ADCINT2_Msk                 (0x1U << ADC_ADCINTFLG_ADCINT2_Pos)                                                                   /*!< ADCINT2         Mask      0x00000002 */
#define ADC_ADCINTFLG_ADCINT2_Set(x)              (((uint16_t) (x) << ADC_ADCINTFLG_ADCINT2_Pos) & ADC_ADCINTFLG_ADCINT2_Msk)                           /*!< ADCINT2         Set Value            */
#define ADC_ADCINTFLG_ADCINT2_Get(x)              (((uint16_t) (x) & ADC_ADCINTFLG_ADCINT2_Msk) >> ADC_ADCINTFLG_ADCINT2_Pos)                           /*!< ADCINT2         Get Value            */

#define ADC_ADCINTFLG_ADCINT1_Pos                 (0U)                                                                                                  /*!< ADCINT1         Position  0          */
#define ADC_ADCINTFLG_ADCINT1_Msk                 (0x1U << ADC_ADCINTFLG_ADCINT1_Pos)                                                                   /*!< ADCINT1         Mask      0x00000001 */
#define ADC_ADCINTFLG_ADCINT1_Set(x)              (((uint16_t) (x) << ADC_ADCINTFLG_ADCINT1_Pos) & ADC_ADCINTFLG_ADCINT1_Msk)                           /*!< ADCINT1         Set Value            */
#define ADC_ADCINTFLG_ADCINT1_Get(x)              (((uint16_t) (x) & ADC_ADCINTFLG_ADCINT1_Msk) >> ADC_ADCINTFLG_ADCINT1_Pos)                           /*!< ADCINT1         Get Value            */

/* ADCINTFLGCLR bitfield */
#define ADC_ADCINTFLGCLR_ADCINT4_Pos              (3U)                                                                                                  /*!< ADCINT4         Position  3          */
#define ADC_ADCINTFLGCLR_ADCINT4_Msk              (0x1U << ADC_ADCINTFLGCLR_ADCINT4_Pos)                                                                /*!< ADCINT4         Mask      0x00000008 */
#define ADC_ADCINTFLGCLR_ADCINT4_Set(x)           (((uint16_t) (x) << ADC_ADCINTFLGCLR_ADCINT4_Pos) & ADC_ADCINTFLGCLR_ADCINT4_Msk)                     /*!< ADCINT4         Set Value            */
#define ADC_ADCINTFLGCLR_ADCINT4_Get(x)           (((uint16_t) (x) & ADC_ADCINTFLGCLR_ADCINT4_Msk) >> ADC_ADCINTFLGCLR_ADCINT4_Pos)                     /*!< ADCINT4         Get Value            */

#define ADC_ADCINTFLGCLR_ADCINT3_Pos              (2U)                                                                                                  /*!< ADCINT3         Position  2          */
#define ADC_ADCINTFLGCLR_ADCINT3_Msk              (0x1U << ADC_ADCINTFLGCLR_ADCINT3_Pos)                                                                /*!< ADCINT3         Mask      0x00000004 */
#define ADC_ADCINTFLGCLR_ADCINT3_Set(x)           (((uint16_t) (x) << ADC_ADCINTFLGCLR_ADCINT3_Pos) & ADC_ADCINTFLGCLR_ADCINT3_Msk)                     /*!< ADCINT3         Set Value            */
#define ADC_ADCINTFLGCLR_ADCINT3_Get(x)           (((uint16_t) (x) & ADC_ADCINTFLGCLR_ADCINT3_Msk) >> ADC_ADCINTFLGCLR_ADCINT3_Pos)                     /*!< ADCINT3         Get Value            */

#define ADC_ADCINTFLGCLR_ADCINT2_Pos              (1U)                                                                                                  /*!< ADCINT2         Position  1          */
#define ADC_ADCINTFLGCLR_ADCINT2_Msk              (0x1U << ADC_ADCINTFLGCLR_ADCINT2_Pos)                                                                /*!< ADCINT2         Mask      0x00000002 */
#define ADC_ADCINTFLGCLR_ADCINT2_Set(x)           (((uint16_t) (x) << ADC_ADCINTFLGCLR_ADCINT2_Pos) & ADC_ADCINTFLGCLR_ADCINT2_Msk)                     /*!< ADCINT2         Set Value            */
#define ADC_ADCINTFLGCLR_ADCINT2_Get(x)           (((uint16_t) (x) & ADC_ADCINTFLGCLR_ADCINT2_Msk) >> ADC_ADCINTFLGCLR_ADCINT2_Pos)                     /*!< ADCINT2         Get Value            */

#define ADC_ADCINTFLGCLR_ADCINT1_Pos              (0U)                                                                                                  /*!< ADCINT1         Position  0          */
#define ADC_ADCINTFLGCLR_ADCINT1_Msk              (0x1U << ADC_ADCINTFLGCLR_ADCINT1_Pos)                                                                /*!< ADCINT1         Mask      0x00000001 */
#define ADC_ADCINTFLGCLR_ADCINT1_Set(x)           (((uint16_t) (x) << ADC_ADCINTFLGCLR_ADCINT1_Pos) & ADC_ADCINTFLGCLR_ADCINT1_Msk)                     /*!< ADCINT1         Set Value            */
#define ADC_ADCINTFLGCLR_ADCINT1_Get(x)           (((uint16_t) (x) & ADC_ADCINTFLGCLR_ADCINT1_Msk) >> ADC_ADCINTFLGCLR_ADCINT1_Pos)                     /*!< ADCINT1         Get Value            */

/* ADCINTOVF bitfield */
#define ADC_ADCINTOVF_ADCINT4_Pos                 (3U)                                                                                                  /*!< ADCINT4         Position  3          */
#define ADC_ADCINTOVF_ADCINT4_Msk                 (0x1U << ADC_ADCINTOVF_ADCINT4_Pos)                                                                   /*!< ADCINT4         Mask      0x00000008 */
#define ADC_ADCINTOVF_ADCINT4_Set(x)              (((uint16_t) (x) << ADC_ADCINTOVF_ADCINT4_Pos) & ADC_ADCINTOVF_ADCINT4_Msk)                           /*!< ADCINT4         Set Value            */
#define ADC_ADCINTOVF_ADCINT4_Get(x)              (((uint16_t) (x) & ADC_ADCINTOVF_ADCINT4_Msk) >> ADC_ADCINTOVF_ADCINT4_Pos)                           /*!< ADCINT4         Get Value            */

#define ADC_ADCINTOVF_ADCINT3_Pos                 (2U)                                                                                                  /*!< ADCINT3         Position  2          */
#define ADC_ADCINTOVF_ADCINT3_Msk                 (0x1U << ADC_ADCINTOVF_ADCINT3_Pos)                                                                   /*!< ADCINT3         Mask      0x00000004 */
#define ADC_ADCINTOVF_ADCINT3_Set(x)              (((uint16_t) (x) << ADC_ADCINTOVF_ADCINT3_Pos) & ADC_ADCINTOVF_ADCINT3_Msk)                           /*!< ADCINT3         Set Value            */
#define ADC_ADCINTOVF_ADCINT3_Get(x)              (((uint16_t) (x) & ADC_ADCINTOVF_ADCINT3_Msk) >> ADC_ADCINTOVF_ADCINT3_Pos)                           /*!< ADCINT3         Get Value            */

#define ADC_ADCINTOVF_ADCINT2_Pos                 (1U)                                                                                                  /*!< ADCINT2         Position  1          */
#define ADC_ADCINTOVF_ADCINT2_Msk                 (0x1U << ADC_ADCINTOVF_ADCINT2_Pos)                                                                   /*!< ADCINT2         Mask      0x00000002 */
#define ADC_ADCINTOVF_ADCINT2_Set(x)              (((uint16_t) (x) << ADC_ADCINTOVF_ADCINT2_Pos) & ADC_ADCINTOVF_ADCINT2_Msk)                           /*!< ADCINT2         Set Value            */
#define ADC_ADCINTOVF_ADCINT2_Get(x)              (((uint16_t) (x) & ADC_ADCINTOVF_ADCINT2_Msk) >> ADC_ADCINTOVF_ADCINT2_Pos)                           /*!< ADCINT2         Get Value            */

#define ADC_ADCINTOVF_ADCINT1_Pos                 (0U)                                                                                                  /*!< ADCINT1         Position  0          */
#define ADC_ADCINTOVF_ADCINT1_Msk                 (0x1U << ADC_ADCINTOVF_ADCINT1_Pos)                                                                   /*!< ADCINT1         Mask      0x00000001 */
#define ADC_ADCINTOVF_ADCINT1_Set(x)              (((uint16_t) (x) << ADC_ADCINTOVF_ADCINT1_Pos) & ADC_ADCINTOVF_ADCINT1_Msk)                           /*!< ADCINT1         Set Value            */
#define ADC_ADCINTOVF_ADCINT1_Get(x)              (((uint16_t) (x) & ADC_ADCINTOVF_ADCINT1_Msk) >> ADC_ADCINTOVF_ADCINT1_Pos)                           /*!< ADCINT1         Get Value            */

/* ADCINTOVFCLR bitfield */
#define ADC_ADCINTOVFCLR_ADCINT4_Pos              (3U)                                                                                                  /*!< ADCINT4         Position  3          */
#define ADC_ADCINTOVFCLR_ADCINT4_Msk              (0x1U << ADC_ADCINTOVFCLR_ADCINT4_Pos)                                                                /*!< ADCINT4         Mask      0x00000008 */
#define ADC_ADCINTOVFCLR_ADCINT4_Set(x)           (((uint16_t) (x) << ADC_ADCINTOVFCLR_ADCINT4_Pos) & ADC_ADCINTOVFCLR_ADCINT4_Msk)                     /*!< ADCINT4         Set Value            */
#define ADC_ADCINTOVFCLR_ADCINT4_Get(x)           (((uint16_t) (x) & ADC_ADCINTOVFCLR_ADCINT4_Msk) >> ADC_ADCINTOVFCLR_ADCINT4_Pos)                     /*!< ADCINT4         Get Value            */

#define ADC_ADCINTOVFCLR_ADCINT3_Pos              (2U)                                                                                                  /*!< ADCINT3         Position  2          */
#define ADC_ADCINTOVFCLR_ADCINT3_Msk              (0x1U << ADC_ADCINTOVFCLR_ADCINT3_Pos)                                                                /*!< ADCINT3         Mask      0x00000004 */
#define ADC_ADCINTOVFCLR_ADCINT3_Set(x)           (((uint16_t) (x) << ADC_ADCINTOVFCLR_ADCINT3_Pos) & ADC_ADCINTOVFCLR_ADCINT3_Msk)                     /*!< ADCINT3         Set Value            */
#define ADC_ADCINTOVFCLR_ADCINT3_Get(x)           (((uint16_t) (x) & ADC_ADCINTOVFCLR_ADCINT3_Msk) >> ADC_ADCINTOVFCLR_ADCINT3_Pos)                     /*!< ADCINT3         Get Value            */

#define ADC_ADCINTOVFCLR_ADCINT2_Pos              (1U)                                                                                                  /*!< ADCINT2         Position  1          */
#define ADC_ADCINTOVFCLR_ADCINT2_Msk              (0x1U << ADC_ADCINTOVFCLR_ADCINT2_Pos)                                                                /*!< ADCINT2         Mask      0x00000002 */
#define ADC_ADCINTOVFCLR_ADCINT2_Set(x)           (((uint16_t) (x) << ADC_ADCINTOVFCLR_ADCINT2_Pos) & ADC_ADCINTOVFCLR_ADCINT2_Msk)                     /*!< ADCINT2         Set Value            */
#define ADC_ADCINTOVFCLR_ADCINT2_Get(x)           (((uint16_t) (x) & ADC_ADCINTOVFCLR_ADCINT2_Msk) >> ADC_ADCINTOVFCLR_ADCINT2_Pos)                     /*!< ADCINT2         Get Value            */

#define ADC_ADCINTOVFCLR_ADCINT1_Pos              (0U)                                                                                                  /*!< ADCINT1         Position  0          */
#define ADC_ADCINTOVFCLR_ADCINT1_Msk              (0x1U << ADC_ADCINTOVFCLR_ADCINT1_Pos)                                                                /*!< ADCINT1         Mask      0x00000001 */
#define ADC_ADCINTOVFCLR_ADCINT1_Set(x)           (((uint16_t) (x) << ADC_ADCINTOVFCLR_ADCINT1_Pos) & ADC_ADCINTOVFCLR_ADCINT1_Msk)                     /*!< ADCINT1         Set Value            */
#define ADC_ADCINTOVFCLR_ADCINT1_Get(x)           (((uint16_t) (x) & ADC_ADCINTOVFCLR_ADCINT1_Msk) >> ADC_ADCINTOVFCLR_ADCINT1_Pos)                     /*!< ADCINT1         Get Value            */

/* ADCINTSEL1N2 bitfield */
#define ADC_ADCINTSEL1N2_INT2CONT_Pos             (14U)                                                                                                 /*!< INT2CONT        Position  14         */
#define ADC_ADCINTSEL1N2_INT2CONT_Msk             (0x1U << ADC_ADCINTSEL1N2_INT2CONT_Pos)                                                               /*!< INT2CONT        Mask      0x00004000 */
#define ADC_ADCINTSEL1N2_INT2CONT_Set(x)          (((uint16_t) (x) << ADC_ADCINTSEL1N2_INT2CONT_Pos) & ADC_ADCINTSEL1N2_INT2CONT_Msk)                   /*!< INT2CONT        Set Value            */
#define ADC_ADCINTSEL1N2_INT2CONT_Get(x)          (((uint16_t) (x) & ADC_ADCINTSEL1N2_INT2CONT_Msk) >> ADC_ADCINTSEL1N2_INT2CONT_Pos)                   /*!< INT2CONT        Get Value            */

#define ADC_ADCINTSEL1N2_INT2E_Pos                (13U)                                                                                                 /*!< INT2E           Position  13         */
#define ADC_ADCINTSEL1N2_INT2E_Msk                (0x1U << ADC_ADCINTSEL1N2_INT2E_Pos)                                                                  /*!< INT2E           Mask      0x00002000 */
#define ADC_ADCINTSEL1N2_INT2E_Set(x)             (((uint16_t) (x) << ADC_ADCINTSEL1N2_INT2E_Pos) & ADC_ADCINTSEL1N2_INT2E_Msk)                         /*!< INT2E           Set Value            */
#define ADC_ADCINTSEL1N2_INT2E_Get(x)             (((uint16_t) (x) & ADC_ADCINTSEL1N2_INT2E_Msk) >> ADC_ADCINTSEL1N2_INT2E_Pos)                         /*!< INT2E           Get Value            */

#define ADC_ADCINTSEL1N2_INT2SEL_Pos              (8U)                                                                                                  /*!< INT2SEL         Position  8          */
#define ADC_ADCINTSEL1N2_INT2SEL_Msk              (0xfU << ADC_ADCINTSEL1N2_INT2SEL_Pos)                                                                /*!< INT2SEL         Mask      0x00000F00 */
#define ADC_ADCINTSEL1N2_INT2SEL_Set(x)           (((uint16_t) (x) << ADC_ADCINTSEL1N2_INT2SEL_Pos) & ADC_ADCINTSEL1N2_INT2SEL_Msk)                     /*!< INT2SEL         Set Value            */
#define ADC_ADCINTSEL1N2_INT2SEL_Get(x)           (((uint16_t) (x) & ADC_ADCINTSEL1N2_INT2SEL_Msk) >> ADC_ADCINTSEL1N2_INT2SEL_Pos)                     /*!< INT2SEL         Get Value            */

#define ADC_ADCINTSEL1N2_INT1CONT_Pos             (6U)                                                                                                  /*!< INT1CONT        Position  6          */
#define ADC_ADCINTSEL1N2_INT1CONT_Msk             (0x1U << ADC_ADCINTSEL1N2_INT1CONT_Pos)                                                               /*!< INT1CONT        Mask      0x00000040 */
#define ADC_ADCINTSEL1N2_INT1CONT_Set(x)          (((uint16_t) (x) << ADC_ADCINTSEL1N2_INT1CONT_Pos) & ADC_ADCINTSEL1N2_INT1CONT_Msk)                   /*!< INT1CONT        Set Value            */
#define ADC_ADCINTSEL1N2_INT1CONT_Get(x)          (((uint16_t) (x) & ADC_ADCINTSEL1N2_INT1CONT_Msk) >> ADC_ADCINTSEL1N2_INT1CONT_Pos)                   /*!< INT1CONT        Get Value            */

#define ADC_ADCINTSEL1N2_INT1E_Pos                (5U)                                                                                                  /*!< INT1E           Position  5          */
#define ADC_ADCINTSEL1N2_INT1E_Msk                (0x1U << ADC_ADCINTSEL1N2_INT1E_Pos)                                                                  /*!< INT1E           Mask      0x00000020 */
#define ADC_ADCINTSEL1N2_INT1E_Set(x)             (((uint16_t) (x) << ADC_ADCINTSEL1N2_INT1E_Pos) & ADC_ADCINTSEL1N2_INT1E_Msk)                         /*!< INT1E           Set Value            */
#define ADC_ADCINTSEL1N2_INT1E_Get(x)             (((uint16_t) (x) & ADC_ADCINTSEL1N2_INT1E_Msk) >> ADC_ADCINTSEL1N2_INT1E_Pos)                         /*!< INT1E           Get Value            */

#define ADC_ADCINTSEL1N2_INT1SEL_Pos              (0U)                                                                                                  /*!< INT1SEL         Position  0          */
#define ADC_ADCINTSEL1N2_INT1SEL_Msk              (0xfU << ADC_ADCINTSEL1N2_INT1SEL_Pos)                                                                /*!< INT1SEL         Mask      0x0000000F */
#define ADC_ADCINTSEL1N2_INT1SEL_Set(x)           (((uint16_t) (x) << ADC_ADCINTSEL1N2_INT1SEL_Pos) & ADC_ADCINTSEL1N2_INT1SEL_Msk)                     /*!< INT1SEL         Set Value            */
#define ADC_ADCINTSEL1N2_INT1SEL_Get(x)           (((uint16_t) (x) & ADC_ADCINTSEL1N2_INT1SEL_Msk) >> ADC_ADCINTSEL1N2_INT1SEL_Pos)                     /*!< INT1SEL         Get Value            */

/* ADCINTSEL3N4 bitfield */
#define ADC_ADCINTSEL3N4_INT4CONT_Pos             (14U)                                                                                                 /*!< INT4CONT        Position  14         */
#define ADC_ADCINTSEL3N4_INT4CONT_Msk             (0x1U << ADC_ADCINTSEL3N4_INT4CONT_Pos)                                                               /*!< INT4CONT        Mask      0x00004000 */
#define ADC_ADCINTSEL3N4_INT4CONT_Set(x)          (((uint16_t) (x) << ADC_ADCINTSEL3N4_INT4CONT_Pos) & ADC_ADCINTSEL3N4_INT4CONT_Msk)                   /*!< INT4CONT        Set Value            */
#define ADC_ADCINTSEL3N4_INT4CONT_Get(x)          (((uint16_t) (x) & ADC_ADCINTSEL3N4_INT4CONT_Msk) >> ADC_ADCINTSEL3N4_INT4CONT_Pos)                   /*!< INT4CONT        Get Value            */

#define ADC_ADCINTSEL3N4_INT4E_Pos                (13U)                                                                                                 /*!< INT4E           Position  13         */
#define ADC_ADCINTSEL3N4_INT4E_Msk                (0x1U << ADC_ADCINTSEL3N4_INT4E_Pos)                                                                  /*!< INT4E           Mask      0x00002000 */
#define ADC_ADCINTSEL3N4_INT4E_Set(x)             (((uint16_t) (x) << ADC_ADCINTSEL3N4_INT4E_Pos) & ADC_ADCINTSEL3N4_INT4E_Msk)                         /*!< INT4E           Set Value            */
#define ADC_ADCINTSEL3N4_INT4E_Get(x)             (((uint16_t) (x) & ADC_ADCINTSEL3N4_INT4E_Msk) >> ADC_ADCINTSEL3N4_INT4E_Pos)                         /*!< INT4E           Get Value            */

#define ADC_ADCINTSEL3N4_INT4SEL_Pos              (8U)                                                                                                  /*!< INT4SEL         Position  8          */
#define ADC_ADCINTSEL3N4_INT4SEL_Msk              (0xfU << ADC_ADCINTSEL3N4_INT4SEL_Pos)                                                                /*!< INT4SEL         Mask      0x00000F00 */
#define ADC_ADCINTSEL3N4_INT4SEL_Set(x)           (((uint16_t) (x) << ADC_ADCINTSEL3N4_INT4SEL_Pos) & ADC_ADCINTSEL3N4_INT4SEL_Msk)                     /*!< INT4SEL         Set Value            */
#define ADC_ADCINTSEL3N4_INT4SEL_Get(x)           (((uint16_t) (x) & ADC_ADCINTSEL3N4_INT4SEL_Msk) >> ADC_ADCINTSEL3N4_INT4SEL_Pos)                     /*!< INT4SEL         Get Value            */

#define ADC_ADCINTSEL3N4_INT3CONT_Pos             (6U)                                                                                                  /*!< INT3CONT        Position  6          */
#define ADC_ADCINTSEL3N4_INT3CONT_Msk             (0x1U << ADC_ADCINTSEL3N4_INT3CONT_Pos)                                                               /*!< INT3CONT        Mask      0x00000040 */
#define ADC_ADCINTSEL3N4_INT3CONT_Set(x)          (((uint16_t) (x) << ADC_ADCINTSEL3N4_INT3CONT_Pos) & ADC_ADCINTSEL3N4_INT3CONT_Msk)                   /*!< INT3CONT        Set Value            */
#define ADC_ADCINTSEL3N4_INT3CONT_Get(x)          (((uint16_t) (x) & ADC_ADCINTSEL3N4_INT3CONT_Msk) >> ADC_ADCINTSEL3N4_INT3CONT_Pos)                   /*!< INT3CONT        Get Value            */

#define ADC_ADCINTSEL3N4_INT3E_Pos                (5U)                                                                                                  /*!< INT3E           Position  5          */
#define ADC_ADCINTSEL3N4_INT3E_Msk                (0x1U << ADC_ADCINTSEL3N4_INT3E_Pos)                                                                  /*!< INT3E           Mask      0x00000020 */
#define ADC_ADCINTSEL3N4_INT3E_Set(x)             (((uint16_t) (x) << ADC_ADCINTSEL3N4_INT3E_Pos) & ADC_ADCINTSEL3N4_INT3E_Msk)                         /*!< INT3E           Set Value            */
#define ADC_ADCINTSEL3N4_INT3E_Get(x)             (((uint16_t) (x) & ADC_ADCINTSEL3N4_INT3E_Msk) >> ADC_ADCINTSEL3N4_INT3E_Pos)                         /*!< INT3E           Get Value            */

#define ADC_ADCINTSEL3N4_INT3SEL_Pos              (0U)                                                                                                  /*!< INT3SEL         Position  0          */
#define ADC_ADCINTSEL3N4_INT3SEL_Msk              (0xfU << ADC_ADCINTSEL3N4_INT3SEL_Pos)                                                                /*!< INT3SEL         Mask      0x0000000F */
#define ADC_ADCINTSEL3N4_INT3SEL_Set(x)           (((uint16_t) (x) << ADC_ADCINTSEL3N4_INT3SEL_Pos) & ADC_ADCINTSEL3N4_INT3SEL_Msk)                     /*!< INT3SEL         Set Value            */
#define ADC_ADCINTSEL3N4_INT3SEL_Get(x)           (((uint16_t) (x) & ADC_ADCINTSEL3N4_INT3SEL_Msk) >> ADC_ADCINTSEL3N4_INT3SEL_Pos)                     /*!< INT3SEL         Get Value            */

/* ADCSOCPRICTL bitfield */
#define ADC_ADCSOCPRICTL_RRPOINTER_Pos            (5U)                                                                                                  /*!< RRPOINTER       Position  5          */
#define ADC_ADCSOCPRICTL_RRPOINTER_Msk            (0x1fU << ADC_ADCSOCPRICTL_RRPOINTER_Pos)                                                             /*!< RRPOINTER       Mask      0x000003E0 */
#define ADC_ADCSOCPRICTL_RRPOINTER_Set(x)         (((uint16_t) (x) << ADC_ADCSOCPRICTL_RRPOINTER_Pos) & ADC_ADCSOCPRICTL_RRPOINTER_Msk)                 /*!< RRPOINTER       Set Value            */
#define ADC_ADCSOCPRICTL_RRPOINTER_Get(x)         (((uint16_t) (x) & ADC_ADCSOCPRICTL_RRPOINTER_Msk) >> ADC_ADCSOCPRICTL_RRPOINTER_Pos)                 /*!< RRPOINTER       Get Value            */

#define ADC_ADCSOCPRICTL_SOCPRIORITY_Pos          (0U)                                                                                                  /*!< SOCPRIORITY     Position  0          */
#define ADC_ADCSOCPRICTL_SOCPRIORITY_Msk          (0x1fU << ADC_ADCSOCPRICTL_SOCPRIORITY_Pos)                                                           /*!< SOCPRIORITY     Mask      0x0000001F */
#define ADC_ADCSOCPRICTL_SOCPRIORITY_Set(x)       (((uint16_t) (x) << ADC_ADCSOCPRICTL_SOCPRIORITY_Pos) & ADC_ADCSOCPRICTL_SOCPRIORITY_Msk)             /*!< SOCPRIORITY     Set Value            */
#define ADC_ADCSOCPRICTL_SOCPRIORITY_Get(x)       (((uint16_t) (x) & ADC_ADCSOCPRICTL_SOCPRIORITY_Msk) >> ADC_ADCSOCPRICTL_SOCPRIORITY_Pos)             /*!< SOCPRIORITY     Get Value            */

/* ADCINTSOCSEL1 bitfield */
#define ADC_ADCINTSOCSEL1_SOC7_Pos                (14U)                                                                                                 /*!< SOC7            Position  14         */
#define ADC_ADCINTSOCSEL1_SOC7_Msk                (0x3U << ADC_ADCINTSOCSEL1_SOC7_Pos)                                                                  /*!< SOC7            Mask      0x0000C000 */
#define ADC_ADCINTSOCSEL1_SOC7_Set(x)             (((uint16_t) (x) << ADC_ADCINTSOCSEL1_SOC7_Pos) & ADC_ADCINTSOCSEL1_SOC7_Msk)                         /*!< SOC7            Set Value            */
#define ADC_ADCINTSOCSEL1_SOC7_Get(x)             (((uint16_t) (x) & ADC_ADCINTSOCSEL1_SOC7_Msk) >> ADC_ADCINTSOCSEL1_SOC7_Pos)                         /*!< SOC7            Get Value            */

#define ADC_ADCINTSOCSEL1_SOC6_Pos                (12U)                                                                                                 /*!< SOC6            Position  12         */
#define ADC_ADCINTSOCSEL1_SOC6_Msk                (0x3U << ADC_ADCINTSOCSEL1_SOC6_Pos)                                                                  /*!< SOC6            Mask      0x00003000 */
#define ADC_ADCINTSOCSEL1_SOC6_Set(x)             (((uint16_t) (x) << ADC_ADCINTSOCSEL1_SOC6_Pos) & ADC_ADCINTSOCSEL1_SOC6_Msk)                         /*!< SOC6            Set Value            */
#define ADC_ADCINTSOCSEL1_SOC6_Get(x)             (((uint16_t) (x) & ADC_ADCINTSOCSEL1_SOC6_Msk) >> ADC_ADCINTSOCSEL1_SOC6_Pos)                         /*!< SOC6            Get Value            */

#define ADC_ADCINTSOCSEL1_SOC5_Pos                (10U)                                                                                                 /*!< SOC5            Position  10         */
#define ADC_ADCINTSOCSEL1_SOC5_Msk                (0x3U << ADC_ADCINTSOCSEL1_SOC5_Pos)                                                                  /*!< SOC5            Mask      0x00000C00 */
#define ADC_ADCINTSOCSEL1_SOC5_Set(x)             (((uint16_t) (x) << ADC_ADCINTSOCSEL1_SOC5_Pos) & ADC_ADCINTSOCSEL1_SOC5_Msk)                         /*!< SOC5            Set Value            */
#define ADC_ADCINTSOCSEL1_SOC5_Get(x)             (((uint16_t) (x) & ADC_ADCINTSOCSEL1_SOC5_Msk) >> ADC_ADCINTSOCSEL1_SOC5_Pos)                         /*!< SOC5            Get Value            */

#define ADC_ADCINTSOCSEL1_SOC4_Pos                (8U)                                                                                                  /*!< SOC4            Position  8          */
#define ADC_ADCINTSOCSEL1_SOC4_Msk                (0x3U << ADC_ADCINTSOCSEL1_SOC4_Pos)                                                                  /*!< SOC4            Mask      0x00000300 */
#define ADC_ADCINTSOCSEL1_SOC4_Set(x)             (((uint16_t) (x) << ADC_ADCINTSOCSEL1_SOC4_Pos) & ADC_ADCINTSOCSEL1_SOC4_Msk)                         /*!< SOC4            Set Value            */
#define ADC_ADCINTSOCSEL1_SOC4_Get(x)             (((uint16_t) (x) & ADC_ADCINTSOCSEL1_SOC4_Msk) >> ADC_ADCINTSOCSEL1_SOC4_Pos)                         /*!< SOC4            Get Value            */

#define ADC_ADCINTSOCSEL1_SOC3_Pos                (6U)                                                                                                  /*!< SOC3            Position  6          */
#define ADC_ADCINTSOCSEL1_SOC3_Msk                (0x3U << ADC_ADCINTSOCSEL1_SOC3_Pos)                                                                  /*!< SOC3            Mask      0x000000C0 */
#define ADC_ADCINTSOCSEL1_SOC3_Set(x)             (((uint16_t) (x) << ADC_ADCINTSOCSEL1_SOC3_Pos) & ADC_ADCINTSOCSEL1_SOC3_Msk)                         /*!< SOC3            Set Value            */
#define ADC_ADCINTSOCSEL1_SOC3_Get(x)             (((uint16_t) (x) & ADC_ADCINTSOCSEL1_SOC3_Msk) >> ADC_ADCINTSOCSEL1_SOC3_Pos)                         /*!< SOC3            Get Value            */

#define ADC_ADCINTSOCSEL1_SOC2_Pos                (4U)                                                                                                  /*!< SOC2            Position  4          */
#define ADC_ADCINTSOCSEL1_SOC2_Msk                (0x3U << ADC_ADCINTSOCSEL1_SOC2_Pos)                                                                  /*!< SOC2            Mask      0x00000030 */
#define ADC_ADCINTSOCSEL1_SOC2_Set(x)             (((uint16_t) (x) << ADC_ADCINTSOCSEL1_SOC2_Pos) & ADC_ADCINTSOCSEL1_SOC2_Msk)                         /*!< SOC2            Set Value            */
#define ADC_ADCINTSOCSEL1_SOC2_Get(x)             (((uint16_t) (x) & ADC_ADCINTSOCSEL1_SOC2_Msk) >> ADC_ADCINTSOCSEL1_SOC2_Pos)                         /*!< SOC2            Get Value            */

#define ADC_ADCINTSOCSEL1_SOC1_Pos                (2U)                                                                                                  /*!< SOC1            Position  2          */
#define ADC_ADCINTSOCSEL1_SOC1_Msk                (0x3U << ADC_ADCINTSOCSEL1_SOC1_Pos)                                                                  /*!< SOC1            Mask      0x0000000C */
#define ADC_ADCINTSOCSEL1_SOC1_Set(x)             (((uint16_t) (x) << ADC_ADCINTSOCSEL1_SOC1_Pos) & ADC_ADCINTSOCSEL1_SOC1_Msk)                         /*!< SOC1            Set Value            */
#define ADC_ADCINTSOCSEL1_SOC1_Get(x)             (((uint16_t) (x) & ADC_ADCINTSOCSEL1_SOC1_Msk) >> ADC_ADCINTSOCSEL1_SOC1_Pos)                         /*!< SOC1            Get Value            */

#define ADC_ADCINTSOCSEL1_SOC0_Pos                (0U)                                                                                                  /*!< SOC0            Position  0          */
#define ADC_ADCINTSOCSEL1_SOC0_Msk                (0x3U << ADC_ADCINTSOCSEL1_SOC0_Pos)                                                                  /*!< SOC0            Mask      0x00000003 */
#define ADC_ADCINTSOCSEL1_SOC0_Set(x)             (((uint16_t) (x) << ADC_ADCINTSOCSEL1_SOC0_Pos) & ADC_ADCINTSOCSEL1_SOC0_Msk)                         /*!< SOC0            Set Value            */
#define ADC_ADCINTSOCSEL1_SOC0_Get(x)             (((uint16_t) (x) & ADC_ADCINTSOCSEL1_SOC0_Msk) >> ADC_ADCINTSOCSEL1_SOC0_Pos)                         /*!< SOC0            Get Value            */

/* ADCINTSOCSEL2 bitfield */
#define ADC_ADCINTSOCSEL2_SOC15_Pos               (14U)                                                                                                 /*!< SOC15           Position  14         */
#define ADC_ADCINTSOCSEL2_SOC15_Msk               (0x3U << ADC_ADCINTSOCSEL2_SOC15_Pos)                                                                 /*!< SOC15           Mask      0x0000C000 */
#define ADC_ADCINTSOCSEL2_SOC15_Set(x)            (((uint16_t) (x) << ADC_ADCINTSOCSEL2_SOC15_Pos) & ADC_ADCINTSOCSEL2_SOC15_Msk)                       /*!< SOC15           Set Value            */
#define ADC_ADCINTSOCSEL2_SOC15_Get(x)            (((uint16_t) (x) & ADC_ADCINTSOCSEL2_SOC15_Msk) >> ADC_ADCINTSOCSEL2_SOC15_Pos)                       /*!< SOC15           Get Value            */

#define ADC_ADCINTSOCSEL2_SOC14_Pos               (12U)                                                                                                 /*!< SOC14           Position  12         */
#define ADC_ADCINTSOCSEL2_SOC14_Msk               (0x3U << ADC_ADCINTSOCSEL2_SOC14_Pos)                                                                 /*!< SOC14           Mask      0x00003000 */
#define ADC_ADCINTSOCSEL2_SOC14_Set(x)            (((uint16_t) (x) << ADC_ADCINTSOCSEL2_SOC14_Pos) & ADC_ADCINTSOCSEL2_SOC14_Msk)                       /*!< SOC14           Set Value            */
#define ADC_ADCINTSOCSEL2_SOC14_Get(x)            (((uint16_t) (x) & ADC_ADCINTSOCSEL2_SOC14_Msk) >> ADC_ADCINTSOCSEL2_SOC14_Pos)                       /*!< SOC14           Get Value            */

#define ADC_ADCINTSOCSEL2_SOC13_Pos               (10U)                                                                                                 /*!< SOC13           Position  10         */
#define ADC_ADCINTSOCSEL2_SOC13_Msk               (0x3U << ADC_ADCINTSOCSEL2_SOC13_Pos)                                                                 /*!< SOC13           Mask      0x00000C00 */
#define ADC_ADCINTSOCSEL2_SOC13_Set(x)            (((uint16_t) (x) << ADC_ADCINTSOCSEL2_SOC13_Pos) & ADC_ADCINTSOCSEL2_SOC13_Msk)                       /*!< SOC13           Set Value            */
#define ADC_ADCINTSOCSEL2_SOC13_Get(x)            (((uint16_t) (x) & ADC_ADCINTSOCSEL2_SOC13_Msk) >> ADC_ADCINTSOCSEL2_SOC13_Pos)                       /*!< SOC13           Get Value            */

#define ADC_ADCINTSOCSEL2_SOC12_Pos               (8U)                                                                                                  /*!< SOC12           Position  8          */
#define ADC_ADCINTSOCSEL2_SOC12_Msk               (0x3U << ADC_ADCINTSOCSEL2_SOC12_Pos)                                                                 /*!< SOC12           Mask      0x00000300 */
#define ADC_ADCINTSOCSEL2_SOC12_Set(x)            (((uint16_t) (x) << ADC_ADCINTSOCSEL2_SOC12_Pos) & ADC_ADCINTSOCSEL2_SOC12_Msk)                       /*!< SOC12           Set Value            */
#define ADC_ADCINTSOCSEL2_SOC12_Get(x)            (((uint16_t) (x) & ADC_ADCINTSOCSEL2_SOC12_Msk) >> ADC_ADCINTSOCSEL2_SOC12_Pos)                       /*!< SOC12           Get Value            */

#define ADC_ADCINTSOCSEL2_SOC11_Pos               (6U)                                                                                                  /*!< SOC11           Position  6          */
#define ADC_ADCINTSOCSEL2_SOC11_Msk               (0x3U << ADC_ADCINTSOCSEL2_SOC11_Pos)                                                                 /*!< SOC11           Mask      0x000000C0 */
#define ADC_ADCINTSOCSEL2_SOC11_Set(x)            (((uint16_t) (x) << ADC_ADCINTSOCSEL2_SOC11_Pos) & ADC_ADCINTSOCSEL2_SOC11_Msk)                       /*!< SOC11           Set Value            */
#define ADC_ADCINTSOCSEL2_SOC11_Get(x)            (((uint16_t) (x) & ADC_ADCINTSOCSEL2_SOC11_Msk) >> ADC_ADCINTSOCSEL2_SOC11_Pos)                       /*!< SOC11           Get Value            */

#define ADC_ADCINTSOCSEL2_SOC10_Pos               (4U)                                                                                                  /*!< SOC10           Position  4          */
#define ADC_ADCINTSOCSEL2_SOC10_Msk               (0x3U << ADC_ADCINTSOCSEL2_SOC10_Pos)                                                                 /*!< SOC10           Mask      0x00000030 */
#define ADC_ADCINTSOCSEL2_SOC10_Set(x)            (((uint16_t) (x) << ADC_ADCINTSOCSEL2_SOC10_Pos) & ADC_ADCINTSOCSEL2_SOC10_Msk)                       /*!< SOC10           Set Value            */
#define ADC_ADCINTSOCSEL2_SOC10_Get(x)            (((uint16_t) (x) & ADC_ADCINTSOCSEL2_SOC10_Msk) >> ADC_ADCINTSOCSEL2_SOC10_Pos)                       /*!< SOC10           Get Value            */

#define ADC_ADCINTSOCSEL2_SOC9_Pos                (2U)                                                                                                  /*!< SOC9            Position  2          */
#define ADC_ADCINTSOCSEL2_SOC9_Msk                (0x3U << ADC_ADCINTSOCSEL2_SOC9_Pos)                                                                  /*!< SOC9            Mask      0x0000000C */
#define ADC_ADCINTSOCSEL2_SOC9_Set(x)             (((uint16_t) (x) << ADC_ADCINTSOCSEL2_SOC9_Pos) & ADC_ADCINTSOCSEL2_SOC9_Msk)                         /*!< SOC9            Set Value            */
#define ADC_ADCINTSOCSEL2_SOC9_Get(x)             (((uint16_t) (x) & ADC_ADCINTSOCSEL2_SOC9_Msk) >> ADC_ADCINTSOCSEL2_SOC9_Pos)                         /*!< SOC9            Get Value            */

#define ADC_ADCINTSOCSEL2_SOC8_Pos                (0U)                                                                                                  /*!< SOC8            Position  0          */
#define ADC_ADCINTSOCSEL2_SOC8_Msk                (0x3U << ADC_ADCINTSOCSEL2_SOC8_Pos)                                                                  /*!< SOC8            Mask      0x00000003 */
#define ADC_ADCINTSOCSEL2_SOC8_Set(x)             (((uint16_t) (x) << ADC_ADCINTSOCSEL2_SOC8_Pos) & ADC_ADCINTSOCSEL2_SOC8_Msk)                         /*!< SOC8            Set Value            */
#define ADC_ADCINTSOCSEL2_SOC8_Get(x)             (((uint16_t) (x) & ADC_ADCINTSOCSEL2_SOC8_Msk) >> ADC_ADCINTSOCSEL2_SOC8_Pos)                         /*!< SOC8            Get Value            */

/* ADCSOCFLG1 bitfield */
#define ADC_ADCSOCFLG1_SOC15_Pos                  (15U)                                                                                                 /*!< SOC15           Position  15         */
#define ADC_ADCSOCFLG1_SOC15_Msk                  (0x1U << ADC_ADCSOCFLG1_SOC15_Pos)                                                                    /*!< SOC15           Mask      0x00008000 */
#define ADC_ADCSOCFLG1_SOC15_Set(x)               (((uint16_t) (x) << ADC_ADCSOCFLG1_SOC15_Pos) & ADC_ADCSOCFLG1_SOC15_Msk)                             /*!< SOC15           Set Value            */
#define ADC_ADCSOCFLG1_SOC15_Get(x)               (((uint16_t) (x) & ADC_ADCSOCFLG1_SOC15_Msk) >> ADC_ADCSOCFLG1_SOC15_Pos)                             /*!< SOC15           Get Value            */

#define ADC_ADCSOCFLG1_SOC14_Pos                  (14U)                                                                                                 /*!< SOC14           Position  14         */
#define ADC_ADCSOCFLG1_SOC14_Msk                  (0x1U << ADC_ADCSOCFLG1_SOC14_Pos)                                                                    /*!< SOC14           Mask      0x00004000 */
#define ADC_ADCSOCFLG1_SOC14_Set(x)               (((uint16_t) (x) << ADC_ADCSOCFLG1_SOC14_Pos) & ADC_ADCSOCFLG1_SOC14_Msk)                             /*!< SOC14           Set Value            */
#define ADC_ADCSOCFLG1_SOC14_Get(x)               (((uint16_t) (x) & ADC_ADCSOCFLG1_SOC14_Msk) >> ADC_ADCSOCFLG1_SOC14_Pos)                             /*!< SOC14           Get Value            */

#define ADC_ADCSOCFLG1_SOC13_Pos                  (13U)                                                                                                 /*!< SOC13           Position  13         */
#define ADC_ADCSOCFLG1_SOC13_Msk                  (0x1U << ADC_ADCSOCFLG1_SOC13_Pos)                                                                    /*!< SOC13           Mask      0x00002000 */
#define ADC_ADCSOCFLG1_SOC13_Set(x)               (((uint16_t) (x) << ADC_ADCSOCFLG1_SOC13_Pos) & ADC_ADCSOCFLG1_SOC13_Msk)                             /*!< SOC13           Set Value            */
#define ADC_ADCSOCFLG1_SOC13_Get(x)               (((uint16_t) (x) & ADC_ADCSOCFLG1_SOC13_Msk) >> ADC_ADCSOCFLG1_SOC13_Pos)                             /*!< SOC13           Get Value            */

#define ADC_ADCSOCFLG1_SOC12_Pos                  (12U)                                                                                                 /*!< SOC12           Position  12         */
#define ADC_ADCSOCFLG1_SOC12_Msk                  (0x1U << ADC_ADCSOCFLG1_SOC12_Pos)                                                                    /*!< SOC12           Mask      0x00001000 */
#define ADC_ADCSOCFLG1_SOC12_Set(x)               (((uint16_t) (x) << ADC_ADCSOCFLG1_SOC12_Pos) & ADC_ADCSOCFLG1_SOC12_Msk)                             /*!< SOC12           Set Value            */
#define ADC_ADCSOCFLG1_SOC12_Get(x)               (((uint16_t) (x) & ADC_ADCSOCFLG1_SOC12_Msk) >> ADC_ADCSOCFLG1_SOC12_Pos)                             /*!< SOC12           Get Value            */

#define ADC_ADCSOCFLG1_SOC11_Pos                  (11U)                                                                                                 /*!< SOC11           Position  11         */
#define ADC_ADCSOCFLG1_SOC11_Msk                  (0x1U << ADC_ADCSOCFLG1_SOC11_Pos)                                                                    /*!< SOC11           Mask      0x00000800 */
#define ADC_ADCSOCFLG1_SOC11_Set(x)               (((uint16_t) (x) << ADC_ADCSOCFLG1_SOC11_Pos) & ADC_ADCSOCFLG1_SOC11_Msk)                             /*!< SOC11           Set Value            */
#define ADC_ADCSOCFLG1_SOC11_Get(x)               (((uint16_t) (x) & ADC_ADCSOCFLG1_SOC11_Msk) >> ADC_ADCSOCFLG1_SOC11_Pos)                             /*!< SOC11           Get Value            */

#define ADC_ADCSOCFLG1_SOC10_Pos                  (10U)                                                                                                 /*!< SOC10           Position  10         */
#define ADC_ADCSOCFLG1_SOC10_Msk                  (0x1U << ADC_ADCSOCFLG1_SOC10_Pos)                                                                    /*!< SOC10           Mask      0x00000400 */
#define ADC_ADCSOCFLG1_SOC10_Set(x)               (((uint16_t) (x) << ADC_ADCSOCFLG1_SOC10_Pos) & ADC_ADCSOCFLG1_SOC10_Msk)                             /*!< SOC10           Set Value            */
#define ADC_ADCSOCFLG1_SOC10_Get(x)               (((uint16_t) (x) & ADC_ADCSOCFLG1_SOC10_Msk) >> ADC_ADCSOCFLG1_SOC10_Pos)                             /*!< SOC10           Get Value            */

#define ADC_ADCSOCFLG1_SOC9_Pos                   (9U)                                                                                                  /*!< SOC9            Position  9          */
#define ADC_ADCSOCFLG1_SOC9_Msk                   (0x1U << ADC_ADCSOCFLG1_SOC9_Pos)                                                                     /*!< SOC9            Mask      0x00000200 */
#define ADC_ADCSOCFLG1_SOC9_Set(x)                (((uint16_t) (x) << ADC_ADCSOCFLG1_SOC9_Pos) & ADC_ADCSOCFLG1_SOC9_Msk)                               /*!< SOC9            Set Value            */
#define ADC_ADCSOCFLG1_SOC9_Get(x)                (((uint16_t) (x) & ADC_ADCSOCFLG1_SOC9_Msk) >> ADC_ADCSOCFLG1_SOC9_Pos)                               /*!< SOC9            Get Value            */

#define ADC_ADCSOCFLG1_SOC8_Pos                   (8U)                                                                                                  /*!< SOC8            Position  8          */
#define ADC_ADCSOCFLG1_SOC8_Msk                   (0x1U << ADC_ADCSOCFLG1_SOC8_Pos)                                                                     /*!< SOC8            Mask      0x00000100 */
#define ADC_ADCSOCFLG1_SOC8_Set(x)                (((uint16_t) (x) << ADC_ADCSOCFLG1_SOC8_Pos) & ADC_ADCSOCFLG1_SOC8_Msk)                               /*!< SOC8            Set Value            */
#define ADC_ADCSOCFLG1_SOC8_Get(x)                (((uint16_t) (x) & ADC_ADCSOCFLG1_SOC8_Msk) >> ADC_ADCSOCFLG1_SOC8_Pos)                               /*!< SOC8            Get Value            */

#define ADC_ADCSOCFLG1_SOC7_Pos                   (7U)                                                                                                  /*!< SOC7            Position  7          */
#define ADC_ADCSOCFLG1_SOC7_Msk                   (0x1U << ADC_ADCSOCFLG1_SOC7_Pos)                                                                     /*!< SOC7            Mask      0x00000080 */
#define ADC_ADCSOCFLG1_SOC7_Set(x)                (((uint16_t) (x) << ADC_ADCSOCFLG1_SOC7_Pos) & ADC_ADCSOCFLG1_SOC7_Msk)                               /*!< SOC7            Set Value            */
#define ADC_ADCSOCFLG1_SOC7_Get(x)                (((uint16_t) (x) & ADC_ADCSOCFLG1_SOC7_Msk) >> ADC_ADCSOCFLG1_SOC7_Pos)                               /*!< SOC7            Get Value            */

#define ADC_ADCSOCFLG1_SOC6_Pos                   (6U)                                                                                                  /*!< SOC6            Position  6          */
#define ADC_ADCSOCFLG1_SOC6_Msk                   (0x1U << ADC_ADCSOCFLG1_SOC6_Pos)                                                                     /*!< SOC6            Mask      0x00000040 */
#define ADC_ADCSOCFLG1_SOC6_Set(x)                (((uint16_t) (x) << ADC_ADCSOCFLG1_SOC6_Pos) & ADC_ADCSOCFLG1_SOC6_Msk)                               /*!< SOC6            Set Value            */
#define ADC_ADCSOCFLG1_SOC6_Get(x)                (((uint16_t) (x) & ADC_ADCSOCFLG1_SOC6_Msk) >> ADC_ADCSOCFLG1_SOC6_Pos)                               /*!< SOC6            Get Value            */

#define ADC_ADCSOCFLG1_SOC5_Pos                   (5U)                                                                                                  /*!< SOC5            Position  5          */
#define ADC_ADCSOCFLG1_SOC5_Msk                   (0x1U << ADC_ADCSOCFLG1_SOC5_Pos)                                                                     /*!< SOC5            Mask      0x00000020 */
#define ADC_ADCSOCFLG1_SOC5_Set(x)                (((uint16_t) (x) << ADC_ADCSOCFLG1_SOC5_Pos) & ADC_ADCSOCFLG1_SOC5_Msk)                               /*!< SOC5            Set Value            */
#define ADC_ADCSOCFLG1_SOC5_Get(x)                (((uint16_t) (x) & ADC_ADCSOCFLG1_SOC5_Msk) >> ADC_ADCSOCFLG1_SOC5_Pos)                               /*!< SOC5            Get Value            */

#define ADC_ADCSOCFLG1_SOC4_Pos                   (4U)                                                                                                  /*!< SOC4            Position  4          */
#define ADC_ADCSOCFLG1_SOC4_Msk                   (0x1U << ADC_ADCSOCFLG1_SOC4_Pos)                                                                     /*!< SOC4            Mask      0x00000010 */
#define ADC_ADCSOCFLG1_SOC4_Set(x)                (((uint16_t) (x) << ADC_ADCSOCFLG1_SOC4_Pos) & ADC_ADCSOCFLG1_SOC4_Msk)                               /*!< SOC4            Set Value            */
#define ADC_ADCSOCFLG1_SOC4_Get(x)                (((uint16_t) (x) & ADC_ADCSOCFLG1_SOC4_Msk) >> ADC_ADCSOCFLG1_SOC4_Pos)                               /*!< SOC4            Get Value            */

#define ADC_ADCSOCFLG1_SOC3_Pos                   (3U)                                                                                                  /*!< SOC3            Position  3          */
#define ADC_ADCSOCFLG1_SOC3_Msk                   (0x1U << ADC_ADCSOCFLG1_SOC3_Pos)                                                                     /*!< SOC3            Mask      0x00000008 */
#define ADC_ADCSOCFLG1_SOC3_Set(x)                (((uint16_t) (x) << ADC_ADCSOCFLG1_SOC3_Pos) & ADC_ADCSOCFLG1_SOC3_Msk)                               /*!< SOC3            Set Value            */
#define ADC_ADCSOCFLG1_SOC3_Get(x)                (((uint16_t) (x) & ADC_ADCSOCFLG1_SOC3_Msk) >> ADC_ADCSOCFLG1_SOC3_Pos)                               /*!< SOC3            Get Value            */

#define ADC_ADCSOCFLG1_SOC2_Pos                   (2U)                                                                                                  /*!< SOC2            Position  2          */
#define ADC_ADCSOCFLG1_SOC2_Msk                   (0x1U << ADC_ADCSOCFLG1_SOC2_Pos)                                                                     /*!< SOC2            Mask      0x00000004 */
#define ADC_ADCSOCFLG1_SOC2_Set(x)                (((uint16_t) (x) << ADC_ADCSOCFLG1_SOC2_Pos) & ADC_ADCSOCFLG1_SOC2_Msk)                               /*!< SOC2            Set Value            */
#define ADC_ADCSOCFLG1_SOC2_Get(x)                (((uint16_t) (x) & ADC_ADCSOCFLG1_SOC2_Msk) >> ADC_ADCSOCFLG1_SOC2_Pos)                               /*!< SOC2            Get Value            */

#define ADC_ADCSOCFLG1_SOC1_Pos                   (1U)                                                                                                  /*!< SOC1            Position  1          */
#define ADC_ADCSOCFLG1_SOC1_Msk                   (0x1U << ADC_ADCSOCFLG1_SOC1_Pos)                                                                     /*!< SOC1            Mask      0x00000002 */
#define ADC_ADCSOCFLG1_SOC1_Set(x)                (((uint16_t) (x) << ADC_ADCSOCFLG1_SOC1_Pos) & ADC_ADCSOCFLG1_SOC1_Msk)                               /*!< SOC1            Set Value            */
#define ADC_ADCSOCFLG1_SOC1_Get(x)                (((uint16_t) (x) & ADC_ADCSOCFLG1_SOC1_Msk) >> ADC_ADCSOCFLG1_SOC1_Pos)                               /*!< SOC1            Get Value            */

#define ADC_ADCSOCFLG1_SOC0_Pos                   (0U)                                                                                                  /*!< SOC0            Position  0          */
#define ADC_ADCSOCFLG1_SOC0_Msk                   (0x1U << ADC_ADCSOCFLG1_SOC0_Pos)                                                                     /*!< SOC0            Mask      0x00000001 */
#define ADC_ADCSOCFLG1_SOC0_Set(x)                (((uint16_t) (x) << ADC_ADCSOCFLG1_SOC0_Pos) & ADC_ADCSOCFLG1_SOC0_Msk)                               /*!< SOC0            Set Value            */
#define ADC_ADCSOCFLG1_SOC0_Get(x)                (((uint16_t) (x) & ADC_ADCSOCFLG1_SOC0_Msk) >> ADC_ADCSOCFLG1_SOC0_Pos)                               /*!< SOC0            Get Value            */

/* ADCSOCFRC1 bitfield */
#define ADC_ADCSOCFRC1_SOC15_Pos                  (15U)                                                                                                 /*!< SOC15           Position  15         */
#define ADC_ADCSOCFRC1_SOC15_Msk                  (0x1U << ADC_ADCSOCFRC1_SOC15_Pos)                                                                    /*!< SOC15           Mask      0x00008000 */
#define ADC_ADCSOCFRC1_SOC15_Set(x)               (((uint16_t) (x) << ADC_ADCSOCFRC1_SOC15_Pos) & ADC_ADCSOCFRC1_SOC15_Msk)                             /*!< SOC15           Set Value            */
#define ADC_ADCSOCFRC1_SOC15_Get(x)               (((uint16_t) (x) & ADC_ADCSOCFRC1_SOC15_Msk) >> ADC_ADCSOCFRC1_SOC15_Pos)                             /*!< SOC15           Get Value            */

#define ADC_ADCSOCFRC1_SOC14_Pos                  (14U)                                                                                                 /*!< SOC14           Position  14         */
#define ADC_ADCSOCFRC1_SOC14_Msk                  (0x1U << ADC_ADCSOCFRC1_SOC14_Pos)                                                                    /*!< SOC14           Mask      0x00004000 */
#define ADC_ADCSOCFRC1_SOC14_Set(x)               (((uint16_t) (x) << ADC_ADCSOCFRC1_SOC14_Pos) & ADC_ADCSOCFRC1_SOC14_Msk)                             /*!< SOC14           Set Value            */
#define ADC_ADCSOCFRC1_SOC14_Get(x)               (((uint16_t) (x) & ADC_ADCSOCFRC1_SOC14_Msk) >> ADC_ADCSOCFRC1_SOC14_Pos)                             /*!< SOC14           Get Value            */

#define ADC_ADCSOCFRC1_SOC13_Pos                  (13U)                                                                                                 /*!< SOC13           Position  13         */
#define ADC_ADCSOCFRC1_SOC13_Msk                  (0x1U << ADC_ADCSOCFRC1_SOC13_Pos)                                                                    /*!< SOC13           Mask      0x00002000 */
#define ADC_ADCSOCFRC1_SOC13_Set(x)               (((uint16_t) (x) << ADC_ADCSOCFRC1_SOC13_Pos) & ADC_ADCSOCFRC1_SOC13_Msk)                             /*!< SOC13           Set Value            */
#define ADC_ADCSOCFRC1_SOC13_Get(x)               (((uint16_t) (x) & ADC_ADCSOCFRC1_SOC13_Msk) >> ADC_ADCSOCFRC1_SOC13_Pos)                             /*!< SOC13           Get Value            */

#define ADC_ADCSOCFRC1_SOC12_Pos                  (12U)                                                                                                 /*!< SOC12           Position  12         */
#define ADC_ADCSOCFRC1_SOC12_Msk                  (0x1U << ADC_ADCSOCFRC1_SOC12_Pos)                                                                    /*!< SOC12           Mask      0x00001000 */
#define ADC_ADCSOCFRC1_SOC12_Set(x)               (((uint16_t) (x) << ADC_ADCSOCFRC1_SOC12_Pos) & ADC_ADCSOCFRC1_SOC12_Msk)                             /*!< SOC12           Set Value            */
#define ADC_ADCSOCFRC1_SOC12_Get(x)               (((uint16_t) (x) & ADC_ADCSOCFRC1_SOC12_Msk) >> ADC_ADCSOCFRC1_SOC12_Pos)                             /*!< SOC12           Get Value            */

#define ADC_ADCSOCFRC1_SOC11_Pos                  (11U)                                                                                                 /*!< SOC11           Position  11         */
#define ADC_ADCSOCFRC1_SOC11_Msk                  (0x1U << ADC_ADCSOCFRC1_SOC11_Pos)                                                                    /*!< SOC11           Mask      0x00000800 */
#define ADC_ADCSOCFRC1_SOC11_Set(x)               (((uint16_t) (x) << ADC_ADCSOCFRC1_SOC11_Pos) & ADC_ADCSOCFRC1_SOC11_Msk)                             /*!< SOC11           Set Value            */
#define ADC_ADCSOCFRC1_SOC11_Get(x)               (((uint16_t) (x) & ADC_ADCSOCFRC1_SOC11_Msk) >> ADC_ADCSOCFRC1_SOC11_Pos)                             /*!< SOC11           Get Value            */

#define ADC_ADCSOCFRC1_SOC10_Pos                  (10U)                                                                                                 /*!< SOC10           Position  10         */
#define ADC_ADCSOCFRC1_SOC10_Msk                  (0x1U << ADC_ADCSOCFRC1_SOC10_Pos)                                                                    /*!< SOC10           Mask      0x00000400 */
#define ADC_ADCSOCFRC1_SOC10_Set(x)               (((uint16_t) (x) << ADC_ADCSOCFRC1_SOC10_Pos) & ADC_ADCSOCFRC1_SOC10_Msk)                             /*!< SOC10           Set Value            */
#define ADC_ADCSOCFRC1_SOC10_Get(x)               (((uint16_t) (x) & ADC_ADCSOCFRC1_SOC10_Msk) >> ADC_ADCSOCFRC1_SOC10_Pos)                             /*!< SOC10           Get Value            */

#define ADC_ADCSOCFRC1_SOC9_Pos                   (9U)                                                                                                  /*!< SOC9            Position  9          */
#define ADC_ADCSOCFRC1_SOC9_Msk                   (0x1U << ADC_ADCSOCFRC1_SOC9_Pos)                                                                     /*!< SOC9            Mask      0x00000200 */
#define ADC_ADCSOCFRC1_SOC9_Set(x)                (((uint16_t) (x) << ADC_ADCSOCFRC1_SOC9_Pos) & ADC_ADCSOCFRC1_SOC9_Msk)                               /*!< SOC9            Set Value            */
#define ADC_ADCSOCFRC1_SOC9_Get(x)                (((uint16_t) (x) & ADC_ADCSOCFRC1_SOC9_Msk) >> ADC_ADCSOCFRC1_SOC9_Pos)                               /*!< SOC9            Get Value            */

#define ADC_ADCSOCFRC1_SOC8_Pos                   (8U)                                                                                                  /*!< SOC8            Position  8          */
#define ADC_ADCSOCFRC1_SOC8_Msk                   (0x1U << ADC_ADCSOCFRC1_SOC8_Pos)                                                                     /*!< SOC8            Mask      0x00000100 */
#define ADC_ADCSOCFRC1_SOC8_Set(x)                (((uint16_t) (x) << ADC_ADCSOCFRC1_SOC8_Pos) & ADC_ADCSOCFRC1_SOC8_Msk)                               /*!< SOC8            Set Value            */
#define ADC_ADCSOCFRC1_SOC8_Get(x)                (((uint16_t) (x) & ADC_ADCSOCFRC1_SOC8_Msk) >> ADC_ADCSOCFRC1_SOC8_Pos)                               /*!< SOC8            Get Value            */

#define ADC_ADCSOCFRC1_SOC7_Pos                   (7U)                                                                                                  /*!< SOC7            Position  7          */
#define ADC_ADCSOCFRC1_SOC7_Msk                   (0x1U << ADC_ADCSOCFRC1_SOC7_Pos)                                                                     /*!< SOC7            Mask      0x00000080 */
#define ADC_ADCSOCFRC1_SOC7_Set(x)                (((uint16_t) (x) << ADC_ADCSOCFRC1_SOC7_Pos) & ADC_ADCSOCFRC1_SOC7_Msk)                               /*!< SOC7            Set Value            */
#define ADC_ADCSOCFRC1_SOC7_Get(x)                (((uint16_t) (x) & ADC_ADCSOCFRC1_SOC7_Msk) >> ADC_ADCSOCFRC1_SOC7_Pos)                               /*!< SOC7            Get Value            */

#define ADC_ADCSOCFRC1_SOC6_Pos                   (6U)                                                                                                  /*!< SOC6            Position  6          */
#define ADC_ADCSOCFRC1_SOC6_Msk                   (0x1U << ADC_ADCSOCFRC1_SOC6_Pos)                                                                     /*!< SOC6            Mask      0x00000040 */
#define ADC_ADCSOCFRC1_SOC6_Set(x)                (((uint16_t) (x) << ADC_ADCSOCFRC1_SOC6_Pos) & ADC_ADCSOCFRC1_SOC6_Msk)                               /*!< SOC6            Set Value            */
#define ADC_ADCSOCFRC1_SOC6_Get(x)                (((uint16_t) (x) & ADC_ADCSOCFRC1_SOC6_Msk) >> ADC_ADCSOCFRC1_SOC6_Pos)                               /*!< SOC6            Get Value            */

#define ADC_ADCSOCFRC1_SOC5_Pos                   (5U)                                                                                                  /*!< SOC5            Position  5          */
#define ADC_ADCSOCFRC1_SOC5_Msk                   (0x1U << ADC_ADCSOCFRC1_SOC5_Pos)                                                                     /*!< SOC5            Mask      0x00000020 */
#define ADC_ADCSOCFRC1_SOC5_Set(x)                (((uint16_t) (x) << ADC_ADCSOCFRC1_SOC5_Pos) & ADC_ADCSOCFRC1_SOC5_Msk)                               /*!< SOC5            Set Value            */
#define ADC_ADCSOCFRC1_SOC5_Get(x)                (((uint16_t) (x) & ADC_ADCSOCFRC1_SOC5_Msk) >> ADC_ADCSOCFRC1_SOC5_Pos)                               /*!< SOC5            Get Value            */

#define ADC_ADCSOCFRC1_SOC4_Pos                   (4U)                                                                                                  /*!< SOC4            Position  4          */
#define ADC_ADCSOCFRC1_SOC4_Msk                   (0x1U << ADC_ADCSOCFRC1_SOC4_Pos)                                                                     /*!< SOC4            Mask      0x00000010 */
#define ADC_ADCSOCFRC1_SOC4_Set(x)                (((uint16_t) (x) << ADC_ADCSOCFRC1_SOC4_Pos) & ADC_ADCSOCFRC1_SOC4_Msk)                               /*!< SOC4            Set Value            */
#define ADC_ADCSOCFRC1_SOC4_Get(x)                (((uint16_t) (x) & ADC_ADCSOCFRC1_SOC4_Msk) >> ADC_ADCSOCFRC1_SOC4_Pos)                               /*!< SOC4            Get Value            */

#define ADC_ADCSOCFRC1_SOC3_Pos                   (3U)                                                                                                  /*!< SOC3            Position  3          */
#define ADC_ADCSOCFRC1_SOC3_Msk                   (0x1U << ADC_ADCSOCFRC1_SOC3_Pos)                                                                     /*!< SOC3            Mask      0x00000008 */
#define ADC_ADCSOCFRC1_SOC3_Set(x)                (((uint16_t) (x) << ADC_ADCSOCFRC1_SOC3_Pos) & ADC_ADCSOCFRC1_SOC3_Msk)                               /*!< SOC3            Set Value            */
#define ADC_ADCSOCFRC1_SOC3_Get(x)                (((uint16_t) (x) & ADC_ADCSOCFRC1_SOC3_Msk) >> ADC_ADCSOCFRC1_SOC3_Pos)                               /*!< SOC3            Get Value            */

#define ADC_ADCSOCFRC1_SOC2_Pos                   (2U)                                                                                                  /*!< SOC2            Position  2          */
#define ADC_ADCSOCFRC1_SOC2_Msk                   (0x1U << ADC_ADCSOCFRC1_SOC2_Pos)                                                                     /*!< SOC2            Mask      0x00000004 */
#define ADC_ADCSOCFRC1_SOC2_Set(x)                (((uint16_t) (x) << ADC_ADCSOCFRC1_SOC2_Pos) & ADC_ADCSOCFRC1_SOC2_Msk)                               /*!< SOC2            Set Value            */
#define ADC_ADCSOCFRC1_SOC2_Get(x)                (((uint16_t) (x) & ADC_ADCSOCFRC1_SOC2_Msk) >> ADC_ADCSOCFRC1_SOC2_Pos)                               /*!< SOC2            Get Value            */

#define ADC_ADCSOCFRC1_SOC1_Pos                   (1U)                                                                                                  /*!< SOC1            Position  1          */
#define ADC_ADCSOCFRC1_SOC1_Msk                   (0x1U << ADC_ADCSOCFRC1_SOC1_Pos)                                                                     /*!< SOC1            Mask      0x00000002 */
#define ADC_ADCSOCFRC1_SOC1_Set(x)                (((uint16_t) (x) << ADC_ADCSOCFRC1_SOC1_Pos) & ADC_ADCSOCFRC1_SOC1_Msk)                               /*!< SOC1            Set Value            */
#define ADC_ADCSOCFRC1_SOC1_Get(x)                (((uint16_t) (x) & ADC_ADCSOCFRC1_SOC1_Msk) >> ADC_ADCSOCFRC1_SOC1_Pos)                               /*!< SOC1            Get Value            */

#define ADC_ADCSOCFRC1_SOC0_Pos                   (0U)                                                                                                  /*!< SOC0            Position  0          */
#define ADC_ADCSOCFRC1_SOC0_Msk                   (0x1U << ADC_ADCSOCFRC1_SOC0_Pos)                                                                     /*!< SOC0            Mask      0x00000001 */
#define ADC_ADCSOCFRC1_SOC0_Set(x)                (((uint16_t) (x) << ADC_ADCSOCFRC1_SOC0_Pos) & ADC_ADCSOCFRC1_SOC0_Msk)                               /*!< SOC0            Set Value            */
#define ADC_ADCSOCFRC1_SOC0_Get(x)                (((uint16_t) (x) & ADC_ADCSOCFRC1_SOC0_Msk) >> ADC_ADCSOCFRC1_SOC0_Pos)                               /*!< SOC0            Get Value            */

/* ADCSOCOVF1 bitfield */
#define ADC_ADCSOCOVF1_SOC15_Pos                  (15U)                                                                                                 /*!< SOC15           Position  15         */
#define ADC_ADCSOCOVF1_SOC15_Msk                  (0x1U << ADC_ADCSOCOVF1_SOC15_Pos)                                                                    /*!< SOC15           Mask      0x00008000 */
#define ADC_ADCSOCOVF1_SOC15_Set(x)               (((uint16_t) (x) << ADC_ADCSOCOVF1_SOC15_Pos) & ADC_ADCSOCOVF1_SOC15_Msk)                             /*!< SOC15           Set Value            */
#define ADC_ADCSOCOVF1_SOC15_Get(x)               (((uint16_t) (x) & ADC_ADCSOCOVF1_SOC15_Msk) >> ADC_ADCSOCOVF1_SOC15_Pos)                             /*!< SOC15           Get Value            */

#define ADC_ADCSOCOVF1_SOC14_Pos                  (14U)                                                                                                 /*!< SOC14           Position  14         */
#define ADC_ADCSOCOVF1_SOC14_Msk                  (0x1U << ADC_ADCSOCOVF1_SOC14_Pos)                                                                    /*!< SOC14           Mask      0x00004000 */
#define ADC_ADCSOCOVF1_SOC14_Set(x)               (((uint16_t) (x) << ADC_ADCSOCOVF1_SOC14_Pos) & ADC_ADCSOCOVF1_SOC14_Msk)                             /*!< SOC14           Set Value            */
#define ADC_ADCSOCOVF1_SOC14_Get(x)               (((uint16_t) (x) & ADC_ADCSOCOVF1_SOC14_Msk) >> ADC_ADCSOCOVF1_SOC14_Pos)                             /*!< SOC14           Get Value            */

#define ADC_ADCSOCOVF1_SOC13_Pos                  (13U)                                                                                                 /*!< SOC13           Position  13         */
#define ADC_ADCSOCOVF1_SOC13_Msk                  (0x1U << ADC_ADCSOCOVF1_SOC13_Pos)                                                                    /*!< SOC13           Mask      0x00002000 */
#define ADC_ADCSOCOVF1_SOC13_Set(x)               (((uint16_t) (x) << ADC_ADCSOCOVF1_SOC13_Pos) & ADC_ADCSOCOVF1_SOC13_Msk)                             /*!< SOC13           Set Value            */
#define ADC_ADCSOCOVF1_SOC13_Get(x)               (((uint16_t) (x) & ADC_ADCSOCOVF1_SOC13_Msk) >> ADC_ADCSOCOVF1_SOC13_Pos)                             /*!< SOC13           Get Value            */

#define ADC_ADCSOCOVF1_SOC12_Pos                  (12U)                                                                                                 /*!< SOC12           Position  12         */
#define ADC_ADCSOCOVF1_SOC12_Msk                  (0x1U << ADC_ADCSOCOVF1_SOC12_Pos)                                                                    /*!< SOC12           Mask      0x00001000 */
#define ADC_ADCSOCOVF1_SOC12_Set(x)               (((uint16_t) (x) << ADC_ADCSOCOVF1_SOC12_Pos) & ADC_ADCSOCOVF1_SOC12_Msk)                             /*!< SOC12           Set Value            */
#define ADC_ADCSOCOVF1_SOC12_Get(x)               (((uint16_t) (x) & ADC_ADCSOCOVF1_SOC12_Msk) >> ADC_ADCSOCOVF1_SOC12_Pos)                             /*!< SOC12           Get Value            */

#define ADC_ADCSOCOVF1_SOC11_Pos                  (11U)                                                                                                 /*!< SOC11           Position  11         */
#define ADC_ADCSOCOVF1_SOC11_Msk                  (0x1U << ADC_ADCSOCOVF1_SOC11_Pos)                                                                    /*!< SOC11           Mask      0x00000800 */
#define ADC_ADCSOCOVF1_SOC11_Set(x)               (((uint16_t) (x) << ADC_ADCSOCOVF1_SOC11_Pos) & ADC_ADCSOCOVF1_SOC11_Msk)                             /*!< SOC11           Set Value            */
#define ADC_ADCSOCOVF1_SOC11_Get(x)               (((uint16_t) (x) & ADC_ADCSOCOVF1_SOC11_Msk) >> ADC_ADCSOCOVF1_SOC11_Pos)                             /*!< SOC11           Get Value            */

#define ADC_ADCSOCOVF1_SOC10_Pos                  (10U)                                                                                                 /*!< SOC10           Position  10         */
#define ADC_ADCSOCOVF1_SOC10_Msk                  (0x1U << ADC_ADCSOCOVF1_SOC10_Pos)                                                                    /*!< SOC10           Mask      0x00000400 */
#define ADC_ADCSOCOVF1_SOC10_Set(x)               (((uint16_t) (x) << ADC_ADCSOCOVF1_SOC10_Pos) & ADC_ADCSOCOVF1_SOC10_Msk)                             /*!< SOC10           Set Value            */
#define ADC_ADCSOCOVF1_SOC10_Get(x)               (((uint16_t) (x) & ADC_ADCSOCOVF1_SOC10_Msk) >> ADC_ADCSOCOVF1_SOC10_Pos)                             /*!< SOC10           Get Value            */

#define ADC_ADCSOCOVF1_SOC9_Pos                   (9U)                                                                                                  /*!< SOC9            Position  9          */
#define ADC_ADCSOCOVF1_SOC9_Msk                   (0x1U << ADC_ADCSOCOVF1_SOC9_Pos)                                                                     /*!< SOC9            Mask      0x00000200 */
#define ADC_ADCSOCOVF1_SOC9_Set(x)                (((uint16_t) (x) << ADC_ADCSOCOVF1_SOC9_Pos) & ADC_ADCSOCOVF1_SOC9_Msk)                               /*!< SOC9            Set Value            */
#define ADC_ADCSOCOVF1_SOC9_Get(x)                (((uint16_t) (x) & ADC_ADCSOCOVF1_SOC9_Msk) >> ADC_ADCSOCOVF1_SOC9_Pos)                               /*!< SOC9            Get Value            */

#define ADC_ADCSOCOVF1_SOC8_Pos                   (8U)                                                                                                  /*!< SOC8            Position  8          */
#define ADC_ADCSOCOVF1_SOC8_Msk                   (0x1U << ADC_ADCSOCOVF1_SOC8_Pos)                                                                     /*!< SOC8            Mask      0x00000100 */
#define ADC_ADCSOCOVF1_SOC8_Set(x)                (((uint16_t) (x) << ADC_ADCSOCOVF1_SOC8_Pos) & ADC_ADCSOCOVF1_SOC8_Msk)                               /*!< SOC8            Set Value            */
#define ADC_ADCSOCOVF1_SOC8_Get(x)                (((uint16_t) (x) & ADC_ADCSOCOVF1_SOC8_Msk) >> ADC_ADCSOCOVF1_SOC8_Pos)                               /*!< SOC8            Get Value            */

#define ADC_ADCSOCOVF1_SOC7_Pos                   (7U)                                                                                                  /*!< SOC7            Position  7          */
#define ADC_ADCSOCOVF1_SOC7_Msk                   (0x1U << ADC_ADCSOCOVF1_SOC7_Pos)                                                                     /*!< SOC7            Mask      0x00000080 */
#define ADC_ADCSOCOVF1_SOC7_Set(x)                (((uint16_t) (x) << ADC_ADCSOCOVF1_SOC7_Pos) & ADC_ADCSOCOVF1_SOC7_Msk)                               /*!< SOC7            Set Value            */
#define ADC_ADCSOCOVF1_SOC7_Get(x)                (((uint16_t) (x) & ADC_ADCSOCOVF1_SOC7_Msk) >> ADC_ADCSOCOVF1_SOC7_Pos)                               /*!< SOC7            Get Value            */

#define ADC_ADCSOCOVF1_SOC6_Pos                   (6U)                                                                                                  /*!< SOC6            Position  6          */
#define ADC_ADCSOCOVF1_SOC6_Msk                   (0x1U << ADC_ADCSOCOVF1_SOC6_Pos)                                                                     /*!< SOC6            Mask      0x00000040 */
#define ADC_ADCSOCOVF1_SOC6_Set(x)                (((uint16_t) (x) << ADC_ADCSOCOVF1_SOC6_Pos) & ADC_ADCSOCOVF1_SOC6_Msk)                               /*!< SOC6            Set Value            */
#define ADC_ADCSOCOVF1_SOC6_Get(x)                (((uint16_t) (x) & ADC_ADCSOCOVF1_SOC6_Msk) >> ADC_ADCSOCOVF1_SOC6_Pos)                               /*!< SOC6            Get Value            */

#define ADC_ADCSOCOVF1_SOC5_Pos                   (5U)                                                                                                  /*!< SOC5            Position  5          */
#define ADC_ADCSOCOVF1_SOC5_Msk                   (0x1U << ADC_ADCSOCOVF1_SOC5_Pos)                                                                     /*!< SOC5            Mask      0x00000020 */
#define ADC_ADCSOCOVF1_SOC5_Set(x)                (((uint16_t) (x) << ADC_ADCSOCOVF1_SOC5_Pos) & ADC_ADCSOCOVF1_SOC5_Msk)                               /*!< SOC5            Set Value            */
#define ADC_ADCSOCOVF1_SOC5_Get(x)                (((uint16_t) (x) & ADC_ADCSOCOVF1_SOC5_Msk) >> ADC_ADCSOCOVF1_SOC5_Pos)                               /*!< SOC5            Get Value            */

#define ADC_ADCSOCOVF1_SOC4_Pos                   (4U)                                                                                                  /*!< SOC4            Position  4          */
#define ADC_ADCSOCOVF1_SOC4_Msk                   (0x1U << ADC_ADCSOCOVF1_SOC4_Pos)                                                                     /*!< SOC4            Mask      0x00000010 */
#define ADC_ADCSOCOVF1_SOC4_Set(x)                (((uint16_t) (x) << ADC_ADCSOCOVF1_SOC4_Pos) & ADC_ADCSOCOVF1_SOC4_Msk)                               /*!< SOC4            Set Value            */
#define ADC_ADCSOCOVF1_SOC4_Get(x)                (((uint16_t) (x) & ADC_ADCSOCOVF1_SOC4_Msk) >> ADC_ADCSOCOVF1_SOC4_Pos)                               /*!< SOC4            Get Value            */

#define ADC_ADCSOCOVF1_SOC3_Pos                   (3U)                                                                                                  /*!< SOC3            Position  3          */
#define ADC_ADCSOCOVF1_SOC3_Msk                   (0x1U << ADC_ADCSOCOVF1_SOC3_Pos)                                                                     /*!< SOC3            Mask      0x00000008 */
#define ADC_ADCSOCOVF1_SOC3_Set(x)                (((uint16_t) (x) << ADC_ADCSOCOVF1_SOC3_Pos) & ADC_ADCSOCOVF1_SOC3_Msk)                               /*!< SOC3            Set Value            */
#define ADC_ADCSOCOVF1_SOC3_Get(x)                (((uint16_t) (x) & ADC_ADCSOCOVF1_SOC3_Msk) >> ADC_ADCSOCOVF1_SOC3_Pos)                               /*!< SOC3            Get Value            */

#define ADC_ADCSOCOVF1_SOC2_Pos                   (2U)                                                                                                  /*!< SOC2            Position  2          */
#define ADC_ADCSOCOVF1_SOC2_Msk                   (0x1U << ADC_ADCSOCOVF1_SOC2_Pos)                                                                     /*!< SOC2            Mask      0x00000004 */
#define ADC_ADCSOCOVF1_SOC2_Set(x)                (((uint16_t) (x) << ADC_ADCSOCOVF1_SOC2_Pos) & ADC_ADCSOCOVF1_SOC2_Msk)                               /*!< SOC2            Set Value            */
#define ADC_ADCSOCOVF1_SOC2_Get(x)                (((uint16_t) (x) & ADC_ADCSOCOVF1_SOC2_Msk) >> ADC_ADCSOCOVF1_SOC2_Pos)                               /*!< SOC2            Get Value            */

#define ADC_ADCSOCOVF1_SOC1_Pos                   (1U)                                                                                                  /*!< SOC1            Position  1          */
#define ADC_ADCSOCOVF1_SOC1_Msk                   (0x1U << ADC_ADCSOCOVF1_SOC1_Pos)                                                                     /*!< SOC1            Mask      0x00000002 */
#define ADC_ADCSOCOVF1_SOC1_Set(x)                (((uint16_t) (x) << ADC_ADCSOCOVF1_SOC1_Pos) & ADC_ADCSOCOVF1_SOC1_Msk)                               /*!< SOC1            Set Value            */
#define ADC_ADCSOCOVF1_SOC1_Get(x)                (((uint16_t) (x) & ADC_ADCSOCOVF1_SOC1_Msk) >> ADC_ADCSOCOVF1_SOC1_Pos)                               /*!< SOC1            Get Value            */

#define ADC_ADCSOCOVF1_SOC0_Pos                   (0U)                                                                                                  /*!< SOC0            Position  0          */
#define ADC_ADCSOCOVF1_SOC0_Msk                   (0x1U << ADC_ADCSOCOVF1_SOC0_Pos)                                                                     /*!< SOC0            Mask      0x00000001 */
#define ADC_ADCSOCOVF1_SOC0_Set(x)                (((uint16_t) (x) << ADC_ADCSOCOVF1_SOC0_Pos) & ADC_ADCSOCOVF1_SOC0_Msk)                               /*!< SOC0            Set Value            */
#define ADC_ADCSOCOVF1_SOC0_Get(x)                (((uint16_t) (x) & ADC_ADCSOCOVF1_SOC0_Msk) >> ADC_ADCSOCOVF1_SOC0_Pos)                               /*!< SOC0            Get Value            */

/* ADCSOCOVFCLR1 bitfield */
#define ADC_ADCSOCOVFCLR1_SOC15_Pos               (15U)                                                                                                 /*!< SOC15           Position  15         */
#define ADC_ADCSOCOVFCLR1_SOC15_Msk               (0x1U << ADC_ADCSOCOVFCLR1_SOC15_Pos)                                                                 /*!< SOC15           Mask      0x00008000 */
#define ADC_ADCSOCOVFCLR1_SOC15_Set(x)            (((uint16_t) (x) << ADC_ADCSOCOVFCLR1_SOC15_Pos) & ADC_ADCSOCOVFCLR1_SOC15_Msk)                       /*!< SOC15           Set Value            */
#define ADC_ADCSOCOVFCLR1_SOC15_Get(x)            (((uint16_t) (x) & ADC_ADCSOCOVFCLR1_SOC15_Msk) >> ADC_ADCSOCOVFCLR1_SOC15_Pos)                       /*!< SOC15           Get Value            */

#define ADC_ADCSOCOVFCLR1_SOC14_Pos               (14U)                                                                                                 /*!< SOC14           Position  14         */
#define ADC_ADCSOCOVFCLR1_SOC14_Msk               (0x1U << ADC_ADCSOCOVFCLR1_SOC14_Pos)                                                                 /*!< SOC14           Mask      0x00004000 */
#define ADC_ADCSOCOVFCLR1_SOC14_Set(x)            (((uint16_t) (x) << ADC_ADCSOCOVFCLR1_SOC14_Pos) & ADC_ADCSOCOVFCLR1_SOC14_Msk)                       /*!< SOC14           Set Value            */
#define ADC_ADCSOCOVFCLR1_SOC14_Get(x)            (((uint16_t) (x) & ADC_ADCSOCOVFCLR1_SOC14_Msk) >> ADC_ADCSOCOVFCLR1_SOC14_Pos)                       /*!< SOC14           Get Value            */

#define ADC_ADCSOCOVFCLR1_SOC13_Pos               (13U)                                                                                                 /*!< SOC13           Position  13         */
#define ADC_ADCSOCOVFCLR1_SOC13_Msk               (0x1U << ADC_ADCSOCOVFCLR1_SOC13_Pos)                                                                 /*!< SOC13           Mask      0x00002000 */
#define ADC_ADCSOCOVFCLR1_SOC13_Set(x)            (((uint16_t) (x) << ADC_ADCSOCOVFCLR1_SOC13_Pos) & ADC_ADCSOCOVFCLR1_SOC13_Msk)                       /*!< SOC13           Set Value            */
#define ADC_ADCSOCOVFCLR1_SOC13_Get(x)            (((uint16_t) (x) & ADC_ADCSOCOVFCLR1_SOC13_Msk) >> ADC_ADCSOCOVFCLR1_SOC13_Pos)                       /*!< SOC13           Get Value            */

#define ADC_ADCSOCOVFCLR1_SOC12_Pos               (12U)                                                                                                 /*!< SOC12           Position  12         */
#define ADC_ADCSOCOVFCLR1_SOC12_Msk               (0x1U << ADC_ADCSOCOVFCLR1_SOC12_Pos)                                                                 /*!< SOC12           Mask      0x00001000 */
#define ADC_ADCSOCOVFCLR1_SOC12_Set(x)            (((uint16_t) (x) << ADC_ADCSOCOVFCLR1_SOC12_Pos) & ADC_ADCSOCOVFCLR1_SOC12_Msk)                       /*!< SOC12           Set Value            */
#define ADC_ADCSOCOVFCLR1_SOC12_Get(x)            (((uint16_t) (x) & ADC_ADCSOCOVFCLR1_SOC12_Msk) >> ADC_ADCSOCOVFCLR1_SOC12_Pos)                       /*!< SOC12           Get Value            */

#define ADC_ADCSOCOVFCLR1_SOC11_Pos               (11U)                                                                                                 /*!< SOC11           Position  11         */
#define ADC_ADCSOCOVFCLR1_SOC11_Msk               (0x1U << ADC_ADCSOCOVFCLR1_SOC11_Pos)                                                                 /*!< SOC11           Mask      0x00000800 */
#define ADC_ADCSOCOVFCLR1_SOC11_Set(x)            (((uint16_t) (x) << ADC_ADCSOCOVFCLR1_SOC11_Pos) & ADC_ADCSOCOVFCLR1_SOC11_Msk)                       /*!< SOC11           Set Value            */
#define ADC_ADCSOCOVFCLR1_SOC11_Get(x)            (((uint16_t) (x) & ADC_ADCSOCOVFCLR1_SOC11_Msk) >> ADC_ADCSOCOVFCLR1_SOC11_Pos)                       /*!< SOC11           Get Value            */

#define ADC_ADCSOCOVFCLR1_SOC10_Pos               (10U)                                                                                                 /*!< SOC10           Position  10         */
#define ADC_ADCSOCOVFCLR1_SOC10_Msk               (0x1U << ADC_ADCSOCOVFCLR1_SOC10_Pos)                                                                 /*!< SOC10           Mask      0x00000400 */
#define ADC_ADCSOCOVFCLR1_SOC10_Set(x)            (((uint16_t) (x) << ADC_ADCSOCOVFCLR1_SOC10_Pos) & ADC_ADCSOCOVFCLR1_SOC10_Msk)                       /*!< SOC10           Set Value            */
#define ADC_ADCSOCOVFCLR1_SOC10_Get(x)            (((uint16_t) (x) & ADC_ADCSOCOVFCLR1_SOC10_Msk) >> ADC_ADCSOCOVFCLR1_SOC10_Pos)                       /*!< SOC10           Get Value            */

#define ADC_ADCSOCOVFCLR1_SOC9_Pos                (9U)                                                                                                  /*!< SOC9            Position  9          */
#define ADC_ADCSOCOVFCLR1_SOC9_Msk                (0x1U << ADC_ADCSOCOVFCLR1_SOC9_Pos)                                                                  /*!< SOC9            Mask      0x00000200 */
#define ADC_ADCSOCOVFCLR1_SOC9_Set(x)             (((uint16_t) (x) << ADC_ADCSOCOVFCLR1_SOC9_Pos) & ADC_ADCSOCOVFCLR1_SOC9_Msk)                         /*!< SOC9            Set Value            */
#define ADC_ADCSOCOVFCLR1_SOC9_Get(x)             (((uint16_t) (x) & ADC_ADCSOCOVFCLR1_SOC9_Msk) >> ADC_ADCSOCOVFCLR1_SOC9_Pos)                         /*!< SOC9            Get Value            */

#define ADC_ADCSOCOVFCLR1_SOC8_Pos                (8U)                                                                                                  /*!< SOC8            Position  8          */
#define ADC_ADCSOCOVFCLR1_SOC8_Msk                (0x1U << ADC_ADCSOCOVFCLR1_SOC8_Pos)                                                                  /*!< SOC8            Mask      0x00000100 */
#define ADC_ADCSOCOVFCLR1_SOC8_Set(x)             (((uint16_t) (x) << ADC_ADCSOCOVFCLR1_SOC8_Pos) & ADC_ADCSOCOVFCLR1_SOC8_Msk)                         /*!< SOC8            Set Value            */
#define ADC_ADCSOCOVFCLR1_SOC8_Get(x)             (((uint16_t) (x) & ADC_ADCSOCOVFCLR1_SOC8_Msk) >> ADC_ADCSOCOVFCLR1_SOC8_Pos)                         /*!< SOC8            Get Value            */

#define ADC_ADCSOCOVFCLR1_SOC7_Pos                (7U)                                                                                                  /*!< SOC7            Position  7          */
#define ADC_ADCSOCOVFCLR1_SOC7_Msk                (0x1U << ADC_ADCSOCOVFCLR1_SOC7_Pos)                                                                  /*!< SOC7            Mask      0x00000080 */
#define ADC_ADCSOCOVFCLR1_SOC7_Set(x)             (((uint16_t) (x) << ADC_ADCSOCOVFCLR1_SOC7_Pos) & ADC_ADCSOCOVFCLR1_SOC7_Msk)                         /*!< SOC7            Set Value            */
#define ADC_ADCSOCOVFCLR1_SOC7_Get(x)             (((uint16_t) (x) & ADC_ADCSOCOVFCLR1_SOC7_Msk) >> ADC_ADCSOCOVFCLR1_SOC7_Pos)                         /*!< SOC7            Get Value            */

#define ADC_ADCSOCOVFCLR1_SOC6_Pos                (6U)                                                                                                  /*!< SOC6            Position  6          */
#define ADC_ADCSOCOVFCLR1_SOC6_Msk                (0x1U << ADC_ADCSOCOVFCLR1_SOC6_Pos)                                                                  /*!< SOC6            Mask      0x00000040 */
#define ADC_ADCSOCOVFCLR1_SOC6_Set(x)             (((uint16_t) (x) << ADC_ADCSOCOVFCLR1_SOC6_Pos) & ADC_ADCSOCOVFCLR1_SOC6_Msk)                         /*!< SOC6            Set Value            */
#define ADC_ADCSOCOVFCLR1_SOC6_Get(x)             (((uint16_t) (x) & ADC_ADCSOCOVFCLR1_SOC6_Msk) >> ADC_ADCSOCOVFCLR1_SOC6_Pos)                         /*!< SOC6            Get Value            */

#define ADC_ADCSOCOVFCLR1_SOC5_Pos                (5U)                                                                                                  /*!< SOC5            Position  5          */
#define ADC_ADCSOCOVFCLR1_SOC5_Msk                (0x1U << ADC_ADCSOCOVFCLR1_SOC5_Pos)                                                                  /*!< SOC5            Mask      0x00000020 */
#define ADC_ADCSOCOVFCLR1_SOC5_Set(x)             (((uint16_t) (x) << ADC_ADCSOCOVFCLR1_SOC5_Pos) & ADC_ADCSOCOVFCLR1_SOC5_Msk)                         /*!< SOC5            Set Value            */
#define ADC_ADCSOCOVFCLR1_SOC5_Get(x)             (((uint16_t) (x) & ADC_ADCSOCOVFCLR1_SOC5_Msk) >> ADC_ADCSOCOVFCLR1_SOC5_Pos)                         /*!< SOC5            Get Value            */

#define ADC_ADCSOCOVFCLR1_SOC4_Pos                (4U)                                                                                                  /*!< SOC4            Position  4          */
#define ADC_ADCSOCOVFCLR1_SOC4_Msk                (0x1U << ADC_ADCSOCOVFCLR1_SOC4_Pos)                                                                  /*!< SOC4            Mask      0x00000010 */
#define ADC_ADCSOCOVFCLR1_SOC4_Set(x)             (((uint16_t) (x) << ADC_ADCSOCOVFCLR1_SOC4_Pos) & ADC_ADCSOCOVFCLR1_SOC4_Msk)                         /*!< SOC4            Set Value            */
#define ADC_ADCSOCOVFCLR1_SOC4_Get(x)             (((uint16_t) (x) & ADC_ADCSOCOVFCLR1_SOC4_Msk) >> ADC_ADCSOCOVFCLR1_SOC4_Pos)                         /*!< SOC4            Get Value            */

#define ADC_ADCSOCOVFCLR1_SOC3_Pos                (3U)                                                                                                  /*!< SOC3            Position  3          */
#define ADC_ADCSOCOVFCLR1_SOC3_Msk                (0x1U << ADC_ADCSOCOVFCLR1_SOC3_Pos)                                                                  /*!< SOC3            Mask      0x00000008 */
#define ADC_ADCSOCOVFCLR1_SOC3_Set(x)             (((uint16_t) (x) << ADC_ADCSOCOVFCLR1_SOC3_Pos) & ADC_ADCSOCOVFCLR1_SOC3_Msk)                         /*!< SOC3            Set Value            */
#define ADC_ADCSOCOVFCLR1_SOC3_Get(x)             (((uint16_t) (x) & ADC_ADCSOCOVFCLR1_SOC3_Msk) >> ADC_ADCSOCOVFCLR1_SOC3_Pos)                         /*!< SOC3            Get Value            */

#define ADC_ADCSOCOVFCLR1_SOC2_Pos                (2U)                                                                                                  /*!< SOC2            Position  2          */
#define ADC_ADCSOCOVFCLR1_SOC2_Msk                (0x1U << ADC_ADCSOCOVFCLR1_SOC2_Pos)                                                                  /*!< SOC2            Mask      0x00000004 */
#define ADC_ADCSOCOVFCLR1_SOC2_Set(x)             (((uint16_t) (x) << ADC_ADCSOCOVFCLR1_SOC2_Pos) & ADC_ADCSOCOVFCLR1_SOC2_Msk)                         /*!< SOC2            Set Value            */
#define ADC_ADCSOCOVFCLR1_SOC2_Get(x)             (((uint16_t) (x) & ADC_ADCSOCOVFCLR1_SOC2_Msk) >> ADC_ADCSOCOVFCLR1_SOC2_Pos)                         /*!< SOC2            Get Value            */

#define ADC_ADCSOCOVFCLR1_SOC1_Pos                (1U)                                                                                                  /*!< SOC1            Position  1          */
#define ADC_ADCSOCOVFCLR1_SOC1_Msk                (0x1U << ADC_ADCSOCOVFCLR1_SOC1_Pos)                                                                  /*!< SOC1            Mask      0x00000002 */
#define ADC_ADCSOCOVFCLR1_SOC1_Set(x)             (((uint16_t) (x) << ADC_ADCSOCOVFCLR1_SOC1_Pos) & ADC_ADCSOCOVFCLR1_SOC1_Msk)                         /*!< SOC1            Set Value            */
#define ADC_ADCSOCOVFCLR1_SOC1_Get(x)             (((uint16_t) (x) & ADC_ADCSOCOVFCLR1_SOC1_Msk) >> ADC_ADCSOCOVFCLR1_SOC1_Pos)                         /*!< SOC1            Get Value            */

#define ADC_ADCSOCOVFCLR1_SOC0_Pos                (0U)                                                                                                  /*!< SOC0            Position  0          */
#define ADC_ADCSOCOVFCLR1_SOC0_Msk                (0x1U << ADC_ADCSOCOVFCLR1_SOC0_Pos)                                                                  /*!< SOC0            Mask      0x00000001 */
#define ADC_ADCSOCOVFCLR1_SOC0_Set(x)             (((uint16_t) (x) << ADC_ADCSOCOVFCLR1_SOC0_Pos) & ADC_ADCSOCOVFCLR1_SOC0_Msk)                         /*!< SOC0            Set Value            */
#define ADC_ADCSOCOVFCLR1_SOC0_Get(x)             (((uint16_t) (x) & ADC_ADCSOCOVFCLR1_SOC0_Msk) >> ADC_ADCSOCOVFCLR1_SOC0_Pos)                         /*!< SOC0            Get Value            */

/* ADCSOCCTL bitfield */
#define ADC_ADCSOCCTL_TRIGSEL_Pos                 (20U)                                                                                                 /*!< TRIGSEL         Position  20         */
#define ADC_ADCSOCCTL_TRIGSEL_Msk                 (0x1fU << ADC_ADCSOCCTL_TRIGSEL_Pos)                                                                  /*!< TRIGSEL         Mask      0x01F00000 */
#define ADC_ADCSOCCTL_TRIGSEL_Set(x)              (((uint32_t) (x) << ADC_ADCSOCCTL_TRIGSEL_Pos) & ADC_ADCSOCCTL_TRIGSEL_Msk)                           /*!< TRIGSEL         Set Value            */
#define ADC_ADCSOCCTL_TRIGSEL_Get(x)              (((uint32_t) (x) & ADC_ADCSOCCTL_TRIGSEL_Msk) >> ADC_ADCSOCCTL_TRIGSEL_Pos)                           /*!< TRIGSEL         Get Value            */

#define ADC_ADCSOCCTL_CHSEL_Pos                   (15U)                                                                                                 /*!< CHSEL           Position  15         */
#define ADC_ADCSOCCTL_CHSEL_Msk                   (0xfU << ADC_ADCSOCCTL_CHSEL_Pos)                                                                     /*!< CHSEL           Mask      0x00078000 */
#define ADC_ADCSOCCTL_CHSEL_Set(x)                (((uint32_t) (x) << ADC_ADCSOCCTL_CHSEL_Pos) & ADC_ADCSOCCTL_CHSEL_Msk)                               /*!< CHSEL           Set Value            */
#define ADC_ADCSOCCTL_CHSEL_Get(x)                (((uint32_t) (x) & ADC_ADCSOCCTL_CHSEL_Msk) >> ADC_ADCSOCCTL_CHSEL_Pos)                               /*!< CHSEL           Get Value            */

#define ADC_ADCSOCCTL_ACQPS_Pos                   (0U)                                                                                                  /*!< ACQPS           Position  0          */
#define ADC_ADCSOCCTL_ACQPS_Msk                   (0x7fffU << ADC_ADCSOCCTL_ACQPS_Pos)                                                                  /*!< ACQPS           Mask      0x00007FFF */
#define ADC_ADCSOCCTL_ACQPS_Set(x)                (((uint32_t) (x) << ADC_ADCSOCCTL_ACQPS_Pos) & ADC_ADCSOCCTL_ACQPS_Msk)                               /*!< ACQPS           Set Value            */
#define ADC_ADCSOCCTL_ACQPS_Get(x)                (((uint32_t) (x) & ADC_ADCSOCCTL_ACQPS_Msk) >> ADC_ADCSOCCTL_ACQPS_Pos)                               /*!< ACQPS           Get Value            */

/* ADCEVTSTAT bitfield */
#define ADC_ADCEVTSTAT_PPB4ZERO_Pos               (14U)                                                                                                 /*!< PPB4ZERO        Position  14         */
#define ADC_ADCEVTSTAT_PPB4ZERO_Msk               (0x1U << ADC_ADCEVTSTAT_PPB4ZERO_Pos)                                                                 /*!< PPB4ZERO        Mask      0x00004000 */
#define ADC_ADCEVTSTAT_PPB4ZERO_Set(x)            (((uint32_t) (x) << ADC_ADCEVTSTAT_PPB4ZERO_Pos) & ADC_ADCEVTSTAT_PPB4ZERO_Msk)                       /*!< PPB4ZERO        Set Value            */
#define ADC_ADCEVTSTAT_PPB4ZERO_Get(x)            (((uint32_t) (x) & ADC_ADCEVTSTAT_PPB4ZERO_Msk) >> ADC_ADCEVTSTAT_PPB4ZERO_Pos)                       /*!< PPB4ZERO        Get Value            */

#define ADC_ADCEVTSTAT_PPB4TRIPLO_Pos             (13U)                                                                                                 /*!< PPB4TRIPLO      Position  13         */
#define ADC_ADCEVTSTAT_PPB4TRIPLO_Msk             (0x1U << ADC_ADCEVTSTAT_PPB4TRIPLO_Pos)                                                               /*!< PPB4TRIPLO      Mask      0x00002000 */
#define ADC_ADCEVTSTAT_PPB4TRIPLO_Set(x)          (((uint32_t) (x) << ADC_ADCEVTSTAT_PPB4TRIPLO_Pos) & ADC_ADCEVTSTAT_PPB4TRIPLO_Msk)                   /*!< PPB4TRIPLO      Set Value            */
#define ADC_ADCEVTSTAT_PPB4TRIPLO_Get(x)          (((uint32_t) (x) & ADC_ADCEVTSTAT_PPB4TRIPLO_Msk) >> ADC_ADCEVTSTAT_PPB4TRIPLO_Pos)                   /*!< PPB4TRIPLO      Get Value            */

#define ADC_ADCEVTSTAT_PPB4TRIPHI_Pos             (12U)                                                                                                 /*!< PPB4TRIPHI      Position  12         */
#define ADC_ADCEVTSTAT_PPB4TRIPHI_Msk             (0x1U << ADC_ADCEVTSTAT_PPB4TRIPHI_Pos)                                                               /*!< PPB4TRIPHI      Mask      0x00001000 */
#define ADC_ADCEVTSTAT_PPB4TRIPHI_Set(x)          (((uint32_t) (x) << ADC_ADCEVTSTAT_PPB4TRIPHI_Pos) & ADC_ADCEVTSTAT_PPB4TRIPHI_Msk)                   /*!< PPB4TRIPHI      Set Value            */
#define ADC_ADCEVTSTAT_PPB4TRIPHI_Get(x)          (((uint32_t) (x) & ADC_ADCEVTSTAT_PPB4TRIPHI_Msk) >> ADC_ADCEVTSTAT_PPB4TRIPHI_Pos)                   /*!< PPB4TRIPHI      Get Value            */

#define ADC_ADCEVTSTAT_PPB3ZERO_Pos               (10U)                                                                                                 /*!< PPB3ZERO        Position  10         */
#define ADC_ADCEVTSTAT_PPB3ZERO_Msk               (0x1U << ADC_ADCEVTSTAT_PPB3ZERO_Pos)                                                                 /*!< PPB3ZERO        Mask      0x00000400 */
#define ADC_ADCEVTSTAT_PPB3ZERO_Set(x)            (((uint32_t) (x) << ADC_ADCEVTSTAT_PPB3ZERO_Pos) & ADC_ADCEVTSTAT_PPB3ZERO_Msk)                       /*!< PPB3ZERO        Set Value            */
#define ADC_ADCEVTSTAT_PPB3ZERO_Get(x)            (((uint32_t) (x) & ADC_ADCEVTSTAT_PPB3ZERO_Msk) >> ADC_ADCEVTSTAT_PPB3ZERO_Pos)                       /*!< PPB3ZERO        Get Value            */

#define ADC_ADCEVTSTAT_PPB3TRIPLO_Pos             (9U)                                                                                                  /*!< PPB3TRIPLO      Position  9          */
#define ADC_ADCEVTSTAT_PPB3TRIPLO_Msk             (0x1U << ADC_ADCEVTSTAT_PPB3TRIPLO_Pos)                                                               /*!< PPB3TRIPLO      Mask      0x00000200 */
#define ADC_ADCEVTSTAT_PPB3TRIPLO_Set(x)          (((uint32_t) (x) << ADC_ADCEVTSTAT_PPB3TRIPLO_Pos) & ADC_ADCEVTSTAT_PPB3TRIPLO_Msk)                   /*!< PPB3TRIPLO      Set Value            */
#define ADC_ADCEVTSTAT_PPB3TRIPLO_Get(x)          (((uint32_t) (x) & ADC_ADCEVTSTAT_PPB3TRIPLO_Msk) >> ADC_ADCEVTSTAT_PPB3TRIPLO_Pos)                   /*!< PPB3TRIPLO      Get Value            */

#define ADC_ADCEVTSTAT_PPB3TRIPHI_Pos             (8U)                                                                                                  /*!< PPB3TRIPHI      Position  8          */
#define ADC_ADCEVTSTAT_PPB3TRIPHI_Msk             (0x1U << ADC_ADCEVTSTAT_PPB3TRIPHI_Pos)                                                               /*!< PPB3TRIPHI      Mask      0x00000100 */
#define ADC_ADCEVTSTAT_PPB3TRIPHI_Set(x)          (((uint32_t) (x) << ADC_ADCEVTSTAT_PPB3TRIPHI_Pos) & ADC_ADCEVTSTAT_PPB3TRIPHI_Msk)                   /*!< PPB3TRIPHI      Set Value            */
#define ADC_ADCEVTSTAT_PPB3TRIPHI_Get(x)          (((uint32_t) (x) & ADC_ADCEVTSTAT_PPB3TRIPHI_Msk) >> ADC_ADCEVTSTAT_PPB3TRIPHI_Pos)                   /*!< PPB3TRIPHI      Get Value            */

#define ADC_ADCEVTSTAT_PPB2ZERO_Pos               (6U)                                                                                                  /*!< PPB2ZERO        Position  6          */
#define ADC_ADCEVTSTAT_PPB2ZERO_Msk               (0x1U << ADC_ADCEVTSTAT_PPB2ZERO_Pos)                                                                 /*!< PPB2ZERO        Mask      0x00000040 */
#define ADC_ADCEVTSTAT_PPB2ZERO_Set(x)            (((uint32_t) (x) << ADC_ADCEVTSTAT_PPB2ZERO_Pos) & ADC_ADCEVTSTAT_PPB2ZERO_Msk)                       /*!< PPB2ZERO        Set Value            */
#define ADC_ADCEVTSTAT_PPB2ZERO_Get(x)            (((uint32_t) (x) & ADC_ADCEVTSTAT_PPB2ZERO_Msk) >> ADC_ADCEVTSTAT_PPB2ZERO_Pos)                       /*!< PPB2ZERO        Get Value            */

#define ADC_ADCEVTSTAT_PPB2TRIPLO_Pos             (5U)                                                                                                  /*!< PPB2TRIPLO      Position  5          */
#define ADC_ADCEVTSTAT_PPB2TRIPLO_Msk             (0x1U << ADC_ADCEVTSTAT_PPB2TRIPLO_Pos)                                                               /*!< PPB2TRIPLO      Mask      0x00000020 */
#define ADC_ADCEVTSTAT_PPB2TRIPLO_Set(x)          (((uint32_t) (x) << ADC_ADCEVTSTAT_PPB2TRIPLO_Pos) & ADC_ADCEVTSTAT_PPB2TRIPLO_Msk)                   /*!< PPB2TRIPLO      Set Value            */
#define ADC_ADCEVTSTAT_PPB2TRIPLO_Get(x)          (((uint32_t) (x) & ADC_ADCEVTSTAT_PPB2TRIPLO_Msk) >> ADC_ADCEVTSTAT_PPB2TRIPLO_Pos)                   /*!< PPB2TRIPLO      Get Value            */

#define ADC_ADCEVTSTAT_PPB2TRIPHI_Pos             (4U)                                                                                                  /*!< PPB2TRIPHI      Position  4          */
#define ADC_ADCEVTSTAT_PPB2TRIPHI_Msk             (0x1U << ADC_ADCEVTSTAT_PPB2TRIPHI_Pos)                                                               /*!< PPB2TRIPHI      Mask      0x00000010 */
#define ADC_ADCEVTSTAT_PPB2TRIPHI_Set(x)          (((uint32_t) (x) << ADC_ADCEVTSTAT_PPB2TRIPHI_Pos) & ADC_ADCEVTSTAT_PPB2TRIPHI_Msk)                   /*!< PPB2TRIPHI      Set Value            */
#define ADC_ADCEVTSTAT_PPB2TRIPHI_Get(x)          (((uint32_t) (x) & ADC_ADCEVTSTAT_PPB2TRIPHI_Msk) >> ADC_ADCEVTSTAT_PPB2TRIPHI_Pos)                   /*!< PPB2TRIPHI      Get Value            */

#define ADC_ADCEVTSTAT_PPB1ZERO_Pos               (2U)                                                                                                  /*!< PPB1ZERO        Position  2          */
#define ADC_ADCEVTSTAT_PPB1ZERO_Msk               (0x1U << ADC_ADCEVTSTAT_PPB1ZERO_Pos)                                                                 /*!< PPB1ZERO        Mask      0x00000004 */
#define ADC_ADCEVTSTAT_PPB1ZERO_Set(x)            (((uint32_t) (x) << ADC_ADCEVTSTAT_PPB1ZERO_Pos) & ADC_ADCEVTSTAT_PPB1ZERO_Msk)                       /*!< PPB1ZERO        Set Value            */
#define ADC_ADCEVTSTAT_PPB1ZERO_Get(x)            (((uint32_t) (x) & ADC_ADCEVTSTAT_PPB1ZERO_Msk) >> ADC_ADCEVTSTAT_PPB1ZERO_Pos)                       /*!< PPB1ZERO        Get Value            */

#define ADC_ADCEVTSTAT_PPB1TRIPLO_Pos             (1U)                                                                                                  /*!< PPB1TRIPLO      Position  1          */
#define ADC_ADCEVTSTAT_PPB1TRIPLO_Msk             (0x1U << ADC_ADCEVTSTAT_PPB1TRIPLO_Pos)                                                               /*!< PPB1TRIPLO      Mask      0x00000002 */
#define ADC_ADCEVTSTAT_PPB1TRIPLO_Set(x)          (((uint32_t) (x) << ADC_ADCEVTSTAT_PPB1TRIPLO_Pos) & ADC_ADCEVTSTAT_PPB1TRIPLO_Msk)                   /*!< PPB1TRIPLO      Set Value            */
#define ADC_ADCEVTSTAT_PPB1TRIPLO_Get(x)          (((uint32_t) (x) & ADC_ADCEVTSTAT_PPB1TRIPLO_Msk) >> ADC_ADCEVTSTAT_PPB1TRIPLO_Pos)                   /*!< PPB1TRIPLO      Get Value            */

#define ADC_ADCEVTSTAT_PPB1TRIPHI_Pos             (0U)                                                                                                  /*!< PPB1TRIPHI      Position  0          */
#define ADC_ADCEVTSTAT_PPB1TRIPHI_Msk             (0x1U << ADC_ADCEVTSTAT_PPB1TRIPHI_Pos)                                                               /*!< PPB1TRIPHI      Mask      0x00000001 */
#define ADC_ADCEVTSTAT_PPB1TRIPHI_Set(x)          (((uint32_t) (x) << ADC_ADCEVTSTAT_PPB1TRIPHI_Pos) & ADC_ADCEVTSTAT_PPB1TRIPHI_Msk)                   /*!< PPB1TRIPHI      Set Value            */
#define ADC_ADCEVTSTAT_PPB1TRIPHI_Get(x)          (((uint32_t) (x) & ADC_ADCEVTSTAT_PPB1TRIPHI_Msk) >> ADC_ADCEVTSTAT_PPB1TRIPHI_Pos)                   /*!< PPB1TRIPHI      Get Value            */

/* ADCEVTCLR bitfield */
#define ADC_ADCEVTCLR_PPB4ZERO_Pos                (14U)                                                                                                 /*!< PPB4ZERO        Position  14         */
#define ADC_ADCEVTCLR_PPB4ZERO_Msk                (0x1U << ADC_ADCEVTCLR_PPB4ZERO_Pos)                                                                  /*!< PPB4ZERO        Mask      0x00004000 */
#define ADC_ADCEVTCLR_PPB4ZERO_Set(x)             (((uint32_t) (x) << ADC_ADCEVTCLR_PPB4ZERO_Pos) & ADC_ADCEVTCLR_PPB4ZERO_Msk)                         /*!< PPB4ZERO        Set Value            */
#define ADC_ADCEVTCLR_PPB4ZERO_Get(x)             (((uint32_t) (x) & ADC_ADCEVTCLR_PPB4ZERO_Msk) >> ADC_ADCEVTCLR_PPB4ZERO_Pos)                         /*!< PPB4ZERO        Get Value            */

#define ADC_ADCEVTCLR_PPB4TRIPLO_Pos              (13U)                                                                                                 /*!< PPB4TRIPLO      Position  13         */
#define ADC_ADCEVTCLR_PPB4TRIPLO_Msk              (0x1U << ADC_ADCEVTCLR_PPB4TRIPLO_Pos)                                                                /*!< PPB4TRIPLO      Mask      0x00002000 */
#define ADC_ADCEVTCLR_PPB4TRIPLO_Set(x)           (((uint32_t) (x) << ADC_ADCEVTCLR_PPB4TRIPLO_Pos) & ADC_ADCEVTCLR_PPB4TRIPLO_Msk)                     /*!< PPB4TRIPLO      Set Value            */
#define ADC_ADCEVTCLR_PPB4TRIPLO_Get(x)           (((uint32_t) (x) & ADC_ADCEVTCLR_PPB4TRIPLO_Msk) >> ADC_ADCEVTCLR_PPB4TRIPLO_Pos)                     /*!< PPB4TRIPLO      Get Value            */

#define ADC_ADCEVTCLR_PPB4TRIPHI_Pos              (12U)                                                                                                 /*!< PPB4TRIPHI      Position  12         */
#define ADC_ADCEVTCLR_PPB4TRIPHI_Msk              (0x1U << ADC_ADCEVTCLR_PPB4TRIPHI_Pos)                                                                /*!< PPB4TRIPHI      Mask      0x00001000 */
#define ADC_ADCEVTCLR_PPB4TRIPHI_Set(x)           (((uint32_t) (x) << ADC_ADCEVTCLR_PPB4TRIPHI_Pos) & ADC_ADCEVTCLR_PPB4TRIPHI_Msk)                     /*!< PPB4TRIPHI      Set Value            */
#define ADC_ADCEVTCLR_PPB4TRIPHI_Get(x)           (((uint32_t) (x) & ADC_ADCEVTCLR_PPB4TRIPHI_Msk) >> ADC_ADCEVTCLR_PPB4TRIPHI_Pos)                     /*!< PPB4TRIPHI      Get Value            */

#define ADC_ADCEVTCLR_PPB3ZERO_Pos                (10U)                                                                                                 /*!< PPB3ZERO        Position  10         */
#define ADC_ADCEVTCLR_PPB3ZERO_Msk                (0x1U << ADC_ADCEVTCLR_PPB3ZERO_Pos)                                                                  /*!< PPB3ZERO        Mask      0x00000400 */
#define ADC_ADCEVTCLR_PPB3ZERO_Set(x)             (((uint32_t) (x) << ADC_ADCEVTCLR_PPB3ZERO_Pos) & ADC_ADCEVTCLR_PPB3ZERO_Msk)                         /*!< PPB3ZERO        Set Value            */
#define ADC_ADCEVTCLR_PPB3ZERO_Get(x)             (((uint32_t) (x) & ADC_ADCEVTCLR_PPB3ZERO_Msk) >> ADC_ADCEVTCLR_PPB3ZERO_Pos)                         /*!< PPB3ZERO        Get Value            */

#define ADC_ADCEVTCLR_PPB3TRIPLO_Pos              (9U)                                                                                                  /*!< PPB3TRIPLO      Position  9          */
#define ADC_ADCEVTCLR_PPB3TRIPLO_Msk              (0x1U << ADC_ADCEVTCLR_PPB3TRIPLO_Pos)                                                                /*!< PPB3TRIPLO      Mask      0x00000200 */
#define ADC_ADCEVTCLR_PPB3TRIPLO_Set(x)           (((uint32_t) (x) << ADC_ADCEVTCLR_PPB3TRIPLO_Pos) & ADC_ADCEVTCLR_PPB3TRIPLO_Msk)                     /*!< PPB3TRIPLO      Set Value            */
#define ADC_ADCEVTCLR_PPB3TRIPLO_Get(x)           (((uint32_t) (x) & ADC_ADCEVTCLR_PPB3TRIPLO_Msk) >> ADC_ADCEVTCLR_PPB3TRIPLO_Pos)                     /*!< PPB3TRIPLO      Get Value            */

#define ADC_ADCEVTCLR_PPB3TRIPHI_Pos              (8U)                                                                                                  /*!< PPB3TRIPHI      Position  8          */
#define ADC_ADCEVTCLR_PPB3TRIPHI_Msk              (0x1U << ADC_ADCEVTCLR_PPB3TRIPHI_Pos)                                                                /*!< PPB3TRIPHI      Mask      0x00000100 */
#define ADC_ADCEVTCLR_PPB3TRIPHI_Set(x)           (((uint32_t) (x) << ADC_ADCEVTCLR_PPB3TRIPHI_Pos) & ADC_ADCEVTCLR_PPB3TRIPHI_Msk)                     /*!< PPB3TRIPHI      Set Value            */
#define ADC_ADCEVTCLR_PPB3TRIPHI_Get(x)           (((uint32_t) (x) & ADC_ADCEVTCLR_PPB3TRIPHI_Msk) >> ADC_ADCEVTCLR_PPB3TRIPHI_Pos)                     /*!< PPB3TRIPHI      Get Value            */

#define ADC_ADCEVTCLR_PPB2ZERO_Pos                (6U)                                                                                                  /*!< PPB2ZERO        Position  6          */
#define ADC_ADCEVTCLR_PPB2ZERO_Msk                (0x1U << ADC_ADCEVTCLR_PPB2ZERO_Pos)                                                                  /*!< PPB2ZERO        Mask      0x00000040 */
#define ADC_ADCEVTCLR_PPB2ZERO_Set(x)             (((uint32_t) (x) << ADC_ADCEVTCLR_PPB2ZERO_Pos) & ADC_ADCEVTCLR_PPB2ZERO_Msk)                         /*!< PPB2ZERO        Set Value            */
#define ADC_ADCEVTCLR_PPB2ZERO_Get(x)             (((uint32_t) (x) & ADC_ADCEVTCLR_PPB2ZERO_Msk) >> ADC_ADCEVTCLR_PPB2ZERO_Pos)                         /*!< PPB2ZERO        Get Value            */

#define ADC_ADCEVTCLR_PPB2TRIPLO_Pos              (5U)                                                                                                  /*!< PPB2TRIPLO      Position  5          */
#define ADC_ADCEVTCLR_PPB2TRIPLO_Msk              (0x1U << ADC_ADCEVTCLR_PPB2TRIPLO_Pos)                                                                /*!< PPB2TRIPLO      Mask      0x00000020 */
#define ADC_ADCEVTCLR_PPB2TRIPLO_Set(x)           (((uint32_t) (x) << ADC_ADCEVTCLR_PPB2TRIPLO_Pos) & ADC_ADCEVTCLR_PPB2TRIPLO_Msk)                     /*!< PPB2TRIPLO      Set Value            */
#define ADC_ADCEVTCLR_PPB2TRIPLO_Get(x)           (((uint32_t) (x) & ADC_ADCEVTCLR_PPB2TRIPLO_Msk) >> ADC_ADCEVTCLR_PPB2TRIPLO_Pos)                     /*!< PPB2TRIPLO      Get Value            */

#define ADC_ADCEVTCLR_PPB2TRIPHI_Pos              (4U)                                                                                                  /*!< PPB2TRIPHI      Position  4          */
#define ADC_ADCEVTCLR_PPB2TRIPHI_Msk              (0x1U << ADC_ADCEVTCLR_PPB2TRIPHI_Pos)                                                                /*!< PPB2TRIPHI      Mask      0x00000010 */
#define ADC_ADCEVTCLR_PPB2TRIPHI_Set(x)           (((uint32_t) (x) << ADC_ADCEVTCLR_PPB2TRIPHI_Pos) & ADC_ADCEVTCLR_PPB2TRIPHI_Msk)                     /*!< PPB2TRIPHI      Set Value            */
#define ADC_ADCEVTCLR_PPB2TRIPHI_Get(x)           (((uint32_t) (x) & ADC_ADCEVTCLR_PPB2TRIPHI_Msk) >> ADC_ADCEVTCLR_PPB2TRIPHI_Pos)                     /*!< PPB2TRIPHI      Get Value            */

#define ADC_ADCEVTCLR_PPB1ZERO_Pos                (2U)                                                                                                  /*!< PPB1ZERO        Position  2          */
#define ADC_ADCEVTCLR_PPB1ZERO_Msk                (0x1U << ADC_ADCEVTCLR_PPB1ZERO_Pos)                                                                  /*!< PPB1ZERO        Mask      0x00000004 */
#define ADC_ADCEVTCLR_PPB1ZERO_Set(x)             (((uint32_t) (x) << ADC_ADCEVTCLR_PPB1ZERO_Pos) & ADC_ADCEVTCLR_PPB1ZERO_Msk)                         /*!< PPB1ZERO        Set Value            */
#define ADC_ADCEVTCLR_PPB1ZERO_Get(x)             (((uint32_t) (x) & ADC_ADCEVTCLR_PPB1ZERO_Msk) >> ADC_ADCEVTCLR_PPB1ZERO_Pos)                         /*!< PPB1ZERO        Get Value            */

#define ADC_ADCEVTCLR_PPB1TRIPLO_Pos              (1U)                                                                                                  /*!< PPB1TRIPLO      Position  1          */
#define ADC_ADCEVTCLR_PPB1TRIPLO_Msk              (0x1U << ADC_ADCEVTCLR_PPB1TRIPLO_Pos)                                                                /*!< PPB1TRIPLO      Mask      0x00000002 */
#define ADC_ADCEVTCLR_PPB1TRIPLO_Set(x)           (((uint32_t) (x) << ADC_ADCEVTCLR_PPB1TRIPLO_Pos) & ADC_ADCEVTCLR_PPB1TRIPLO_Msk)                     /*!< PPB1TRIPLO      Set Value            */
#define ADC_ADCEVTCLR_PPB1TRIPLO_Get(x)           (((uint32_t) (x) & ADC_ADCEVTCLR_PPB1TRIPLO_Msk) >> ADC_ADCEVTCLR_PPB1TRIPLO_Pos)                     /*!< PPB1TRIPLO      Get Value            */

#define ADC_ADCEVTCLR_PPB1TRIPHI_Pos              (0U)                                                                                                  /*!< PPB1TRIPHI      Position  0          */
#define ADC_ADCEVTCLR_PPB1TRIPHI_Msk              (0x1U << ADC_ADCEVTCLR_PPB1TRIPHI_Pos)                                                                /*!< PPB1TRIPHI      Mask      0x00000001 */
#define ADC_ADCEVTCLR_PPB1TRIPHI_Set(x)           (((uint32_t) (x) << ADC_ADCEVTCLR_PPB1TRIPHI_Pos) & ADC_ADCEVTCLR_PPB1TRIPHI_Msk)                     /*!< PPB1TRIPHI      Set Value            */
#define ADC_ADCEVTCLR_PPB1TRIPHI_Get(x)           (((uint32_t) (x) & ADC_ADCEVTCLR_PPB1TRIPHI_Msk) >> ADC_ADCEVTCLR_PPB1TRIPHI_Pos)                     /*!< PPB1TRIPHI      Get Value            */

/* ADCEVTSEL bitfield */
#define ADC_ADCEVTSEL_PPB4ZERO_Pos                (14U)                                                                                                 /*!< PPB4ZERO        Position  14         */
#define ADC_ADCEVTSEL_PPB4ZERO_Msk                (0x1U << ADC_ADCEVTSEL_PPB4ZERO_Pos)                                                                  /*!< PPB4ZERO        Mask      0x00004000 */
#define ADC_ADCEVTSEL_PPB4ZERO_Set(x)             (((uint32_t) (x) << ADC_ADCEVTSEL_PPB4ZERO_Pos) & ADC_ADCEVTSEL_PPB4ZERO_Msk)                         /*!< PPB4ZERO        Set Value            */
#define ADC_ADCEVTSEL_PPB4ZERO_Get(x)             (((uint32_t) (x) & ADC_ADCEVTSEL_PPB4ZERO_Msk) >> ADC_ADCEVTSEL_PPB4ZERO_Pos)                         /*!< PPB4ZERO        Get Value            */

#define ADC_ADCEVTSEL_PPB4TRIPLO_Pos              (13U)                                                                                                 /*!< PPB4TRIPLO      Position  13         */
#define ADC_ADCEVTSEL_PPB4TRIPLO_Msk              (0x1U << ADC_ADCEVTSEL_PPB4TRIPLO_Pos)                                                                /*!< PPB4TRIPLO      Mask      0x00002000 */
#define ADC_ADCEVTSEL_PPB4TRIPLO_Set(x)           (((uint32_t) (x) << ADC_ADCEVTSEL_PPB4TRIPLO_Pos) & ADC_ADCEVTSEL_PPB4TRIPLO_Msk)                     /*!< PPB4TRIPLO      Set Value            */
#define ADC_ADCEVTSEL_PPB4TRIPLO_Get(x)           (((uint32_t) (x) & ADC_ADCEVTSEL_PPB4TRIPLO_Msk) >> ADC_ADCEVTSEL_PPB4TRIPLO_Pos)                     /*!< PPB4TRIPLO      Get Value            */

#define ADC_ADCEVTSEL_PPB4TRIPHI_Pos              (12U)                                                                                                 /*!< PPB4TRIPHI      Position  12         */
#define ADC_ADCEVTSEL_PPB4TRIPHI_Msk              (0x1U << ADC_ADCEVTSEL_PPB4TRIPHI_Pos)                                                                /*!< PPB4TRIPHI      Mask      0x00001000 */
#define ADC_ADCEVTSEL_PPB4TRIPHI_Set(x)           (((uint32_t) (x) << ADC_ADCEVTSEL_PPB4TRIPHI_Pos) & ADC_ADCEVTSEL_PPB4TRIPHI_Msk)                     /*!< PPB4TRIPHI      Set Value            */
#define ADC_ADCEVTSEL_PPB4TRIPHI_Get(x)           (((uint32_t) (x) & ADC_ADCEVTSEL_PPB4TRIPHI_Msk) >> ADC_ADCEVTSEL_PPB4TRIPHI_Pos)                     /*!< PPB4TRIPHI      Get Value            */

#define ADC_ADCEVTSEL_PPB3ZERO_Pos                (10U)                                                                                                 /*!< PPB3ZERO        Position  10         */
#define ADC_ADCEVTSEL_PPB3ZERO_Msk                (0x1U << ADC_ADCEVTSEL_PPB3ZERO_Pos)                                                                  /*!< PPB3ZERO        Mask      0x00000400 */
#define ADC_ADCEVTSEL_PPB3ZERO_Set(x)             (((uint32_t) (x) << ADC_ADCEVTSEL_PPB3ZERO_Pos) & ADC_ADCEVTSEL_PPB3ZERO_Msk)                         /*!< PPB3ZERO        Set Value            */
#define ADC_ADCEVTSEL_PPB3ZERO_Get(x)             (((uint32_t) (x) & ADC_ADCEVTSEL_PPB3ZERO_Msk) >> ADC_ADCEVTSEL_PPB3ZERO_Pos)                         /*!< PPB3ZERO        Get Value            */

#define ADC_ADCEVTSEL_PPB3TRIPLO_Pos              (9U)                                                                                                  /*!< PPB3TRIPLO      Position  9          */
#define ADC_ADCEVTSEL_PPB3TRIPLO_Msk              (0x1U << ADC_ADCEVTSEL_PPB3TRIPLO_Pos)                                                                /*!< PPB3TRIPLO      Mask      0x00000200 */
#define ADC_ADCEVTSEL_PPB3TRIPLO_Set(x)           (((uint32_t) (x) << ADC_ADCEVTSEL_PPB3TRIPLO_Pos) & ADC_ADCEVTSEL_PPB3TRIPLO_Msk)                     /*!< PPB3TRIPLO      Set Value            */
#define ADC_ADCEVTSEL_PPB3TRIPLO_Get(x)           (((uint32_t) (x) & ADC_ADCEVTSEL_PPB3TRIPLO_Msk) >> ADC_ADCEVTSEL_PPB3TRIPLO_Pos)                     /*!< PPB3TRIPLO      Get Value            */

#define ADC_ADCEVTSEL_PPB3TRIPHI_Pos              (8U)                                                                                                  /*!< PPB3TRIPHI      Position  8          */
#define ADC_ADCEVTSEL_PPB3TRIPHI_Msk              (0x1U << ADC_ADCEVTSEL_PPB3TRIPHI_Pos)                                                                /*!< PPB3TRIPHI      Mask      0x00000100 */
#define ADC_ADCEVTSEL_PPB3TRIPHI_Set(x)           (((uint32_t) (x) << ADC_ADCEVTSEL_PPB3TRIPHI_Pos) & ADC_ADCEVTSEL_PPB3TRIPHI_Msk)                     /*!< PPB3TRIPHI      Set Value            */
#define ADC_ADCEVTSEL_PPB3TRIPHI_Get(x)           (((uint32_t) (x) & ADC_ADCEVTSEL_PPB3TRIPHI_Msk) >> ADC_ADCEVTSEL_PPB3TRIPHI_Pos)                     /*!< PPB3TRIPHI      Get Value            */

#define ADC_ADCEVTSEL_PPB2ZERO_Pos                (6U)                                                                                                  /*!< PPB2ZERO        Position  6          */
#define ADC_ADCEVTSEL_PPB2ZERO_Msk                (0x1U << ADC_ADCEVTSEL_PPB2ZERO_Pos)                                                                  /*!< PPB2ZERO        Mask      0x00000040 */
#define ADC_ADCEVTSEL_PPB2ZERO_Set(x)             (((uint32_t) (x) << ADC_ADCEVTSEL_PPB2ZERO_Pos) & ADC_ADCEVTSEL_PPB2ZERO_Msk)                         /*!< PPB2ZERO        Set Value            */
#define ADC_ADCEVTSEL_PPB2ZERO_Get(x)             (((uint32_t) (x) & ADC_ADCEVTSEL_PPB2ZERO_Msk) >> ADC_ADCEVTSEL_PPB2ZERO_Pos)                         /*!< PPB2ZERO        Get Value            */

#define ADC_ADCEVTSEL_PPB2TRIPLO_Pos              (5U)                                                                                                  /*!< PPB2TRIPLO      Position  5          */
#define ADC_ADCEVTSEL_PPB2TRIPLO_Msk              (0x1U << ADC_ADCEVTSEL_PPB2TRIPLO_Pos)                                                                /*!< PPB2TRIPLO      Mask      0x00000020 */
#define ADC_ADCEVTSEL_PPB2TRIPLO_Set(x)           (((uint32_t) (x) << ADC_ADCEVTSEL_PPB2TRIPLO_Pos) & ADC_ADCEVTSEL_PPB2TRIPLO_Msk)                     /*!< PPB2TRIPLO      Set Value            */
#define ADC_ADCEVTSEL_PPB2TRIPLO_Get(x)           (((uint32_t) (x) & ADC_ADCEVTSEL_PPB2TRIPLO_Msk) >> ADC_ADCEVTSEL_PPB2TRIPLO_Pos)                     /*!< PPB2TRIPLO      Get Value            */

#define ADC_ADCEVTSEL_PPB2TRIPHI_Pos              (4U)                                                                                                  /*!< PPB2TRIPHI      Position  4          */
#define ADC_ADCEVTSEL_PPB2TRIPHI_Msk              (0x1U << ADC_ADCEVTSEL_PPB2TRIPHI_Pos)                                                                /*!< PPB2TRIPHI      Mask      0x00000010 */
#define ADC_ADCEVTSEL_PPB2TRIPHI_Set(x)           (((uint32_t) (x) << ADC_ADCEVTSEL_PPB2TRIPHI_Pos) & ADC_ADCEVTSEL_PPB2TRIPHI_Msk)                     /*!< PPB2TRIPHI      Set Value            */
#define ADC_ADCEVTSEL_PPB2TRIPHI_Get(x)           (((uint32_t) (x) & ADC_ADCEVTSEL_PPB2TRIPHI_Msk) >> ADC_ADCEVTSEL_PPB2TRIPHI_Pos)                     /*!< PPB2TRIPHI      Get Value            */

#define ADC_ADCEVTSEL_PPB1ZERO_Pos                (2U)                                                                                                  /*!< PPB1ZERO        Position  2          */
#define ADC_ADCEVTSEL_PPB1ZERO_Msk                (0x1U << ADC_ADCEVTSEL_PPB1ZERO_Pos)                                                                  /*!< PPB1ZERO        Mask      0x00000004 */
#define ADC_ADCEVTSEL_PPB1ZERO_Set(x)             (((uint32_t) (x) << ADC_ADCEVTSEL_PPB1ZERO_Pos) & ADC_ADCEVTSEL_PPB1ZERO_Msk)                         /*!< PPB1ZERO        Set Value            */
#define ADC_ADCEVTSEL_PPB1ZERO_Get(x)             (((uint32_t) (x) & ADC_ADCEVTSEL_PPB1ZERO_Msk) >> ADC_ADCEVTSEL_PPB1ZERO_Pos)                         /*!< PPB1ZERO        Get Value            */

#define ADC_ADCEVTSEL_PPB1TRIPLO_Pos              (1U)                                                                                                  /*!< PPB1TRIPLO      Position  1          */
#define ADC_ADCEVTSEL_PPB1TRIPLO_Msk              (0x1U << ADC_ADCEVTSEL_PPB1TRIPLO_Pos)                                                                /*!< PPB1TRIPLO      Mask      0x00000002 */
#define ADC_ADCEVTSEL_PPB1TRIPLO_Set(x)           (((uint32_t) (x) << ADC_ADCEVTSEL_PPB1TRIPLO_Pos) & ADC_ADCEVTSEL_PPB1TRIPLO_Msk)                     /*!< PPB1TRIPLO      Set Value            */
#define ADC_ADCEVTSEL_PPB1TRIPLO_Get(x)           (((uint32_t) (x) & ADC_ADCEVTSEL_PPB1TRIPLO_Msk) >> ADC_ADCEVTSEL_PPB1TRIPLO_Pos)                     /*!< PPB1TRIPLO      Get Value            */

#define ADC_ADCEVTSEL_PPB1TRIPHI_Pos              (0U)                                                                                                  /*!< PPB1TRIPHI      Position  0          */
#define ADC_ADCEVTSEL_PPB1TRIPHI_Msk              (0x1U << ADC_ADCEVTSEL_PPB1TRIPHI_Pos)                                                                /*!< PPB1TRIPHI      Mask      0x00000001 */
#define ADC_ADCEVTSEL_PPB1TRIPHI_Set(x)           (((uint32_t) (x) << ADC_ADCEVTSEL_PPB1TRIPHI_Pos) & ADC_ADCEVTSEL_PPB1TRIPHI_Msk)                     /*!< PPB1TRIPHI      Set Value            */
#define ADC_ADCEVTSEL_PPB1TRIPHI_Get(x)           (((uint32_t) (x) & ADC_ADCEVTSEL_PPB1TRIPHI_Msk) >> ADC_ADCEVTSEL_PPB1TRIPHI_Pos)                     /*!< PPB1TRIPHI      Get Value            */

/* ADCEVTINTSEL bitfield */
#define ADC_ADCEVTINTSEL_PPB4ZERO_Pos             (14U)                                                                                                 /*!< PPB4ZERO        Position  14         */
#define ADC_ADCEVTINTSEL_PPB4ZERO_Msk             (0x1U << ADC_ADCEVTINTSEL_PPB4ZERO_Pos)                                                               /*!< PPB4ZERO        Mask      0x00004000 */
#define ADC_ADCEVTINTSEL_PPB4ZERO_Set(x)          (((uint32_t) (x) << ADC_ADCEVTINTSEL_PPB4ZERO_Pos) & ADC_ADCEVTINTSEL_PPB4ZERO_Msk)                   /*!< PPB4ZERO        Set Value            */
#define ADC_ADCEVTINTSEL_PPB4ZERO_Get(x)          (((uint32_t) (x) & ADC_ADCEVTINTSEL_PPB4ZERO_Msk) >> ADC_ADCEVTINTSEL_PPB4ZERO_Pos)                   /*!< PPB4ZERO        Get Value            */

#define ADC_ADCEVTINTSEL_PPB4TRIPLO_Pos           (13U)                                                                                                 /*!< PPB4TRIPLO      Position  13         */
#define ADC_ADCEVTINTSEL_PPB4TRIPLO_Msk           (0x1U << ADC_ADCEVTINTSEL_PPB4TRIPLO_Pos)                                                             /*!< PPB4TRIPLO      Mask      0x00002000 */
#define ADC_ADCEVTINTSEL_PPB4TRIPLO_Set(x)        (((uint32_t) (x) << ADC_ADCEVTINTSEL_PPB4TRIPLO_Pos) & ADC_ADCEVTINTSEL_PPB4TRIPLO_Msk)               /*!< PPB4TRIPLO      Set Value            */
#define ADC_ADCEVTINTSEL_PPB4TRIPLO_Get(x)        (((uint32_t) (x) & ADC_ADCEVTINTSEL_PPB4TRIPLO_Msk) >> ADC_ADCEVTINTSEL_PPB4TRIPLO_Pos)               /*!< PPB4TRIPLO      Get Value            */

#define ADC_ADCEVTINTSEL_PPB4TRIPHI_Pos           (12U)                                                                                                 /*!< PPB4TRIPHI      Position  12         */
#define ADC_ADCEVTINTSEL_PPB4TRIPHI_Msk           (0x1U << ADC_ADCEVTINTSEL_PPB4TRIPHI_Pos)                                                             /*!< PPB4TRIPHI      Mask      0x00001000 */
#define ADC_ADCEVTINTSEL_PPB4TRIPHI_Set(x)        (((uint32_t) (x) << ADC_ADCEVTINTSEL_PPB4TRIPHI_Pos) & ADC_ADCEVTINTSEL_PPB4TRIPHI_Msk)               /*!< PPB4TRIPHI      Set Value            */
#define ADC_ADCEVTINTSEL_PPB4TRIPHI_Get(x)        (((uint32_t) (x) & ADC_ADCEVTINTSEL_PPB4TRIPHI_Msk) >> ADC_ADCEVTINTSEL_PPB4TRIPHI_Pos)               /*!< PPB4TRIPHI      Get Value            */

#define ADC_ADCEVTINTSEL_PPB3ZERO_Pos             (10U)                                                                                                 /*!< PPB3ZERO        Position  10         */
#define ADC_ADCEVTINTSEL_PPB3ZERO_Msk             (0x1U << ADC_ADCEVTINTSEL_PPB3ZERO_Pos)                                                               /*!< PPB3ZERO        Mask      0x00000400 */
#define ADC_ADCEVTINTSEL_PPB3ZERO_Set(x)          (((uint32_t) (x) << ADC_ADCEVTINTSEL_PPB3ZERO_Pos) & ADC_ADCEVTINTSEL_PPB3ZERO_Msk)                   /*!< PPB3ZERO        Set Value            */
#define ADC_ADCEVTINTSEL_PPB3ZERO_Get(x)          (((uint32_t) (x) & ADC_ADCEVTINTSEL_PPB3ZERO_Msk) >> ADC_ADCEVTINTSEL_PPB3ZERO_Pos)                   /*!< PPB3ZERO        Get Value            */

#define ADC_ADCEVTINTSEL_PPB3TRIPLO_Pos           (9U)                                                                                                  /*!< PPB3TRIPLO      Position  9          */
#define ADC_ADCEVTINTSEL_PPB3TRIPLO_Msk           (0x1U << ADC_ADCEVTINTSEL_PPB3TRIPLO_Pos)                                                             /*!< PPB3TRIPLO      Mask      0x00000200 */
#define ADC_ADCEVTINTSEL_PPB3TRIPLO_Set(x)        (((uint32_t) (x) << ADC_ADCEVTINTSEL_PPB3TRIPLO_Pos) & ADC_ADCEVTINTSEL_PPB3TRIPLO_Msk)               /*!< PPB3TRIPLO      Set Value            */
#define ADC_ADCEVTINTSEL_PPB3TRIPLO_Get(x)        (((uint32_t) (x) & ADC_ADCEVTINTSEL_PPB3TRIPLO_Msk) >> ADC_ADCEVTINTSEL_PPB3TRIPLO_Pos)               /*!< PPB3TRIPLO      Get Value            */

#define ADC_ADCEVTINTSEL_PPB3TRIPHI_Pos           (8U)                                                                                                  /*!< PPB3TRIPHI      Position  8          */
#define ADC_ADCEVTINTSEL_PPB3TRIPHI_Msk           (0x1U << ADC_ADCEVTINTSEL_PPB3TRIPHI_Pos)                                                             /*!< PPB3TRIPHI      Mask      0x00000100 */
#define ADC_ADCEVTINTSEL_PPB3TRIPHI_Set(x)        (((uint32_t) (x) << ADC_ADCEVTINTSEL_PPB3TRIPHI_Pos) & ADC_ADCEVTINTSEL_PPB3TRIPHI_Msk)               /*!< PPB3TRIPHI      Set Value            */
#define ADC_ADCEVTINTSEL_PPB3TRIPHI_Get(x)        (((uint32_t) (x) & ADC_ADCEVTINTSEL_PPB3TRIPHI_Msk) >> ADC_ADCEVTINTSEL_PPB3TRIPHI_Pos)               /*!< PPB3TRIPHI      Get Value            */

#define ADC_ADCEVTINTSEL_PPB2ZERO_Pos             (6U)                                                                                                  /*!< PPB2ZERO        Position  6          */
#define ADC_ADCEVTINTSEL_PPB2ZERO_Msk             (0x1U << ADC_ADCEVTINTSEL_PPB2ZERO_Pos)                                                               /*!< PPB2ZERO        Mask      0x00000040 */
#define ADC_ADCEVTINTSEL_PPB2ZERO_Set(x)          (((uint32_t) (x) << ADC_ADCEVTINTSEL_PPB2ZERO_Pos) & ADC_ADCEVTINTSEL_PPB2ZERO_Msk)                   /*!< PPB2ZERO        Set Value            */
#define ADC_ADCEVTINTSEL_PPB2ZERO_Get(x)          (((uint32_t) (x) & ADC_ADCEVTINTSEL_PPB2ZERO_Msk) >> ADC_ADCEVTINTSEL_PPB2ZERO_Pos)                   /*!< PPB2ZERO        Get Value            */

#define ADC_ADCEVTINTSEL_PPB2TRIPLO_Pos           (5U)                                                                                                  /*!< PPB2TRIPLO      Position  5          */
#define ADC_ADCEVTINTSEL_PPB2TRIPLO_Msk           (0x1U << ADC_ADCEVTINTSEL_PPB2TRIPLO_Pos)                                                             /*!< PPB2TRIPLO      Mask      0x00000020 */
#define ADC_ADCEVTINTSEL_PPB2TRIPLO_Set(x)        (((uint32_t) (x) << ADC_ADCEVTINTSEL_PPB2TRIPLO_Pos) & ADC_ADCEVTINTSEL_PPB2TRIPLO_Msk)               /*!< PPB2TRIPLO      Set Value            */
#define ADC_ADCEVTINTSEL_PPB2TRIPLO_Get(x)        (((uint32_t) (x) & ADC_ADCEVTINTSEL_PPB2TRIPLO_Msk) >> ADC_ADCEVTINTSEL_PPB2TRIPLO_Pos)               /*!< PPB2TRIPLO      Get Value            */

#define ADC_ADCEVTINTSEL_PPB2TRIPHI_Pos           (4U)                                                                                                  /*!< PPB2TRIPHI      Position  4          */
#define ADC_ADCEVTINTSEL_PPB2TRIPHI_Msk           (0x1U << ADC_ADCEVTINTSEL_PPB2TRIPHI_Pos)                                                             /*!< PPB2TRIPHI      Mask      0x00000010 */
#define ADC_ADCEVTINTSEL_PPB2TRIPHI_Set(x)        (((uint32_t) (x) << ADC_ADCEVTINTSEL_PPB2TRIPHI_Pos) & ADC_ADCEVTINTSEL_PPB2TRIPHI_Msk)               /*!< PPB2TRIPHI      Set Value            */
#define ADC_ADCEVTINTSEL_PPB2TRIPHI_Get(x)        (((uint32_t) (x) & ADC_ADCEVTINTSEL_PPB2TRIPHI_Msk) >> ADC_ADCEVTINTSEL_PPB2TRIPHI_Pos)               /*!< PPB2TRIPHI      Get Value            */

#define ADC_ADCEVTINTSEL_PPB1ZERO_Pos             (2U)                                                                                                  /*!< PPB1ZERO        Position  2          */
#define ADC_ADCEVTINTSEL_PPB1ZERO_Msk             (0x1U << ADC_ADCEVTINTSEL_PPB1ZERO_Pos)                                                               /*!< PPB1ZERO        Mask      0x00000004 */
#define ADC_ADCEVTINTSEL_PPB1ZERO_Set(x)          (((uint32_t) (x) << ADC_ADCEVTINTSEL_PPB1ZERO_Pos) & ADC_ADCEVTINTSEL_PPB1ZERO_Msk)                   /*!< PPB1ZERO        Set Value            */
#define ADC_ADCEVTINTSEL_PPB1ZERO_Get(x)          (((uint32_t) (x) & ADC_ADCEVTINTSEL_PPB1ZERO_Msk) >> ADC_ADCEVTINTSEL_PPB1ZERO_Pos)                   /*!< PPB1ZERO        Get Value            */

#define ADC_ADCEVTINTSEL_PPB1TRIPLO_Pos           (1U)                                                                                                  /*!< PPB1TRIPLO      Position  1          */
#define ADC_ADCEVTINTSEL_PPB1TRIPLO_Msk           (0x1U << ADC_ADCEVTINTSEL_PPB1TRIPLO_Pos)                                                             /*!< PPB1TRIPLO      Mask      0x00000002 */
#define ADC_ADCEVTINTSEL_PPB1TRIPLO_Set(x)        (((uint32_t) (x) << ADC_ADCEVTINTSEL_PPB1TRIPLO_Pos) & ADC_ADCEVTINTSEL_PPB1TRIPLO_Msk)               /*!< PPB1TRIPLO      Set Value            */
#define ADC_ADCEVTINTSEL_PPB1TRIPLO_Get(x)        (((uint32_t) (x) & ADC_ADCEVTINTSEL_PPB1TRIPLO_Msk) >> ADC_ADCEVTINTSEL_PPB1TRIPLO_Pos)               /*!< PPB1TRIPLO      Get Value            */

#define ADC_ADCEVTINTSEL_PPB1TRIPHI_Pos           (0U)                                                                                                  /*!< PPB1TRIPHI      Position  0          */
#define ADC_ADCEVTINTSEL_PPB1TRIPHI_Msk           (0x1U << ADC_ADCEVTINTSEL_PPB1TRIPHI_Pos)                                                             /*!< PPB1TRIPHI      Mask      0x00000001 */
#define ADC_ADCEVTINTSEL_PPB1TRIPHI_Set(x)        (((uint32_t) (x) << ADC_ADCEVTINTSEL_PPB1TRIPHI_Pos) & ADC_ADCEVTINTSEL_PPB1TRIPHI_Msk)               /*!< PPB1TRIPHI      Set Value            */
#define ADC_ADCEVTINTSEL_PPB1TRIPHI_Get(x)        (((uint32_t) (x) & ADC_ADCEVTINTSEL_PPB1TRIPHI_Msk) >> ADC_ADCEVTINTSEL_PPB1TRIPHI_Pos)               /*!< PPB1TRIPHI      Get Value            */

/* ADCCOUNTER bitfield */
#define ADC_ADCCOUNTER_FREECOUNT_Pos              (0U)                                                                                                  /*!< FREECOUNT       Position  0          */
#define ADC_ADCCOUNTER_FREECOUNT_Msk              (0xfffU << ADC_ADCCOUNTER_FREECOUNT_Pos)                                                              /*!< FREECOUNT       Mask      0x00000FFF */
#define ADC_ADCCOUNTER_FREECOUNT_Set(x)           (((uint16_t) (x) << ADC_ADCCOUNTER_FREECOUNT_Pos) & ADC_ADCCOUNTER_FREECOUNT_Msk)                     /*!< FREECOUNT       Set Value            */
#define ADC_ADCCOUNTER_FREECOUNT_Get(x)           (((uint16_t) (x) & ADC_ADCCOUNTER_FREECOUNT_Msk) >> ADC_ADCCOUNTER_FREECOUNT_Pos)                     /*!< FREECOUNT       Get Value            */

/* ADCREV bitfield */
#define ADC_ADCREV_REV_Pos                        (8U)                                                                                                  /*!< REV             Position  8          */
#define ADC_ADCREV_REV_Msk                        (0xffU << ADC_ADCREV_REV_Pos)                                                                         /*!< REV             Mask      0x0000FF00 */
#define ADC_ADCREV_REV_Set(x)                     (((uint16_t) (x) << ADC_ADCREV_REV_Pos) & ADC_ADCREV_REV_Msk)                                         /*!< REV             Set Value            */
#define ADC_ADCREV_REV_Get(x)                     (((uint16_t) (x) & ADC_ADCREV_REV_Msk) >> ADC_ADCREV_REV_Pos)                                         /*!< REV             Get Value            */

#define ADC_ADCREV_ADCTYPE_Pos                    (0U)                                                                                                  /*!< ADCTYPE         Position  0          */
#define ADC_ADCREV_ADCTYPE_Msk                    (0xffU << ADC_ADCREV_ADCTYPE_Pos)                                                                     /*!< ADCTYPE         Mask      0x000000FF */
#define ADC_ADCREV_ADCTYPE_Set(x)                 (((uint16_t) (x) << ADC_ADCREV_ADCTYPE_Pos) & ADC_ADCREV_ADCTYPE_Msk)                                 /*!< ADCTYPE         Set Value            */
#define ADC_ADCREV_ADCTYPE_Get(x)                 (((uint16_t) (x) & ADC_ADCREV_ADCTYPE_Msk) >> ADC_ADCREV_ADCTYPE_Pos)                                 /*!< ADCTYPE         Get Value            */

/* ADCOFFTRIM bitfield */
#define ADC_ADCOFFTRIM_OFFTRIM_Pos                (0U)                                                                                                  /*!< OFFTRIM         Position  0          */
#define ADC_ADCOFFTRIM_OFFTRIM_Msk                (0xffffU << ADC_ADCOFFTRIM_OFFTRIM_Pos)                                                               /*!< OFFTRIM         Mask      0x0000FFFF */
#define ADC_ADCOFFTRIM_OFFTRIM_Set(x)             (((uint16_t) (x) << ADC_ADCOFFTRIM_OFFTRIM_Pos) & ADC_ADCOFFTRIM_OFFTRIM_Msk)                         /*!< OFFTRIM         Set Value            */
#define ADC_ADCOFFTRIM_OFFTRIM_Get(x)             (((uint16_t) (x) & ADC_ADCOFFTRIM_OFFTRIM_Msk) >> ADC_ADCOFFTRIM_OFFTRIM_Pos)                         /*!< OFFTRIM         Get Value            */

/* PPBCFG bitfield */
#define ADC_PPBCFG_CBCEN_Pos                      (5U)                                                                                                  /*!< CBCEN           Position  5          */
#define ADC_PPBCFG_CBCEN_Msk                      (0x1U << ADC_PPBCFG_CBCEN_Pos)                                                                        /*!< CBCEN           Mask      0x00000020 */
#define ADC_PPBCFG_CBCEN_Set(x)                   (((uint16_t) (x) << ADC_PPBCFG_CBCEN_Pos) & ADC_PPBCFG_CBCEN_Msk)                                     /*!< CBCEN           Set Value            */
#define ADC_PPBCFG_CBCEN_Get(x)                   (((uint16_t) (x) & ADC_PPBCFG_CBCEN_Msk) >> ADC_PPBCFG_CBCEN_Pos)                                     /*!< CBCEN           Get Value            */

#define ADC_PPBCFG_TWOSCOMPEN_Pos                 (4U)                                                                                                  /*!< TWOSCOMPEN      Position  4          */
#define ADC_PPBCFG_TWOSCOMPEN_Msk                 (0x1U << ADC_PPBCFG_TWOSCOMPEN_Pos)                                                                   /*!< TWOSCOMPEN      Mask      0x00000010 */
#define ADC_PPBCFG_TWOSCOMPEN_Set(x)              (((uint16_t) (x) << ADC_PPBCFG_TWOSCOMPEN_Pos) & ADC_PPBCFG_TWOSCOMPEN_Msk)                           /*!< TWOSCOMPEN      Set Value            */
#define ADC_PPBCFG_TWOSCOMPEN_Get(x)              (((uint16_t) (x) & ADC_PPBCFG_TWOSCOMPEN_Msk) >> ADC_PPBCFG_TWOSCOMPEN_Pos)                           /*!< TWOSCOMPEN      Get Value            */

#define ADC_PPBCFG_PPB1CONFIG_Pos                 (0U)                                                                                                  /*!< PPB1CONFIG      Position  0          */
#define ADC_PPBCFG_PPB1CONFIG_Msk                 (0xfU << ADC_PPBCFG_PPB1CONFIG_Pos)                                                                   /*!< PPB1CONFIG      Mask      0x0000000F */
#define ADC_PPBCFG_PPB1CONFIG_Set(x)              (((uint16_t) (x) << ADC_PPBCFG_PPB1CONFIG_Pos) & ADC_PPBCFG_PPB1CONFIG_Msk)                           /*!< PPB1CONFIG      Set Value            */
#define ADC_PPBCFG_PPB1CONFIG_Get(x)              (((uint16_t) (x) & ADC_PPBCFG_PPB1CONFIG_Msk) >> ADC_PPBCFG_PPB1CONFIG_Pos)                           /*!< PPB1CONFIG      Get Value            */

/* PPBSTAMP bitfield */
#define ADC_PPBSTAMP_DLYSTAMP_Pos                 (0U)                                                                                                  /*!< DLYSTAMP        Position  0          */
#define ADC_PPBSTAMP_DLYSTAMP_Msk                 (0xfffU << ADC_PPBSTAMP_DLYSTAMP_Pos)                                                                 /*!< DLYSTAMP        Mask      0x00000FFF */
#define ADC_PPBSTAMP_DLYSTAMP_Set(x)              (((uint16_t) (x) << ADC_PPBSTAMP_DLYSTAMP_Pos) & ADC_PPBSTAMP_DLYSTAMP_Msk)                           /*!< DLYSTAMP        Set Value            */
#define ADC_PPBSTAMP_DLYSTAMP_Get(x)              (((uint16_t) (x) & ADC_PPBSTAMP_DLYSTAMP_Msk) >> ADC_PPBSTAMP_DLYSTAMP_Pos)                           /*!< DLYSTAMP        Get Value            */

/* PPBOFFCAL bitfield */
#define ADC_PPBOFFCAL_OFFCAL_Pos                  (0U)                                                                                                  /*!< OFFCAL          Position  0          */
#define ADC_PPBOFFCAL_OFFCAL_Msk                  (0x3ffU << ADC_PPBOFFCAL_OFFCAL_Pos)                                                                  /*!< OFFCAL          Mask      0x000003FF */
#define ADC_PPBOFFCAL_OFFCAL_Set(x)               (((uint16_t) (x) << ADC_PPBOFFCAL_OFFCAL_Pos) & ADC_PPBOFFCAL_OFFCAL_Msk)                             /*!< OFFCAL          Set Value            */
#define ADC_PPBOFFCAL_OFFCAL_Get(x)               (((uint16_t) (x) & ADC_PPBOFFCAL_OFFCAL_Msk) >> ADC_PPBOFFCAL_OFFCAL_Pos)                             /*!< OFFCAL          Get Value            */

/* PPBOFFREF bitfield */
#define ADC_PPBOFFREF_OFFREF_Pos                  (0U)                                                                                                  /*!< OFFREF          Position  0          */
#define ADC_PPBOFFREF_OFFREF_Msk                  (0xffffU << ADC_PPBOFFREF_OFFREF_Pos)                                                                 /*!< OFFREF          Mask      0x0000FFFF */
#define ADC_PPBOFFREF_OFFREF_Set(x)               (((uint16_t) (x) << ADC_PPBOFFREF_OFFREF_Pos) & ADC_PPBOFFREF_OFFREF_Msk)                             /*!< OFFREF          Set Value            */
#define ADC_PPBOFFREF_OFFREF_Get(x)               (((uint16_t) (x) & ADC_PPBOFFREF_OFFREF_Msk) >> ADC_PPBOFFREF_OFFREF_Pos)                             /*!< OFFREF          Get Value            */

/* PPBTRIPHI bitfield */
#define ADC_PPBTRIPHI_HSIGN_Pos                   (16U)                                                                                                 /*!< HSIGN           Position  16         */
#define ADC_PPBTRIPHI_HSIGN_Msk                   (0x1U << ADC_PPBTRIPHI_HSIGN_Pos)                                                                     /*!< HSIGN           Mask      0x00010000 */
#define ADC_PPBTRIPHI_HSIGN_Set(x)                (((uint32_t) (x) << ADC_PPBTRIPHI_HSIGN_Pos) & ADC_PPBTRIPHI_HSIGN_Msk)                               /*!< HSIGN           Set Value            */
#define ADC_PPBTRIPHI_HSIGN_Get(x)                (((uint32_t) (x) & ADC_PPBTRIPHI_HSIGN_Msk) >> ADC_PPBTRIPHI_HSIGN_Pos)                               /*!< HSIGN           Get Value            */

#define ADC_PPBTRIPHI_LIMITHI_Pos                 (0U)                                                                                                  /*!< LIMITHI         Position  0          */
#define ADC_PPBTRIPHI_LIMITHI_Msk                 (0xffffU << ADC_PPBTRIPHI_LIMITHI_Pos)                                                                /*!< LIMITHI         Mask      0x0000FFFF */
#define ADC_PPBTRIPHI_LIMITHI_Set(x)              (((uint32_t) (x) << ADC_PPBTRIPHI_LIMITHI_Pos) & ADC_PPBTRIPHI_LIMITHI_Msk)                           /*!< LIMITHI         Set Value            */
#define ADC_PPBTRIPHI_LIMITHI_Get(x)              (((uint32_t) (x) & ADC_PPBTRIPHI_LIMITHI_Msk) >> ADC_PPBTRIPHI_LIMITHI_Pos)                           /*!< LIMITHI         Get Value            */

/* PPBTRIPLO bitfield */
#define ADC_PPBTRIPLO_REQSTAMP_Pos                (20U)                                                                                                 /*!< REQSTAMP        Position  20         */
#define ADC_PPBTRIPLO_REQSTAMP_Msk                (0xfffU << ADC_PPBTRIPLO_REQSTAMP_Pos)                                                                /*!< REQSTAMP        Mask      0xFFF00000 */
#define ADC_PPBTRIPLO_REQSTAMP_Set(x)             (((uint32_t) (x) << ADC_PPBTRIPLO_REQSTAMP_Pos) & ADC_PPBTRIPLO_REQSTAMP_Msk)                         /*!< REQSTAMP        Set Value            */
#define ADC_PPBTRIPLO_REQSTAMP_Get(x)             (((uint32_t) (x) & ADC_PPBTRIPLO_REQSTAMP_Msk) >> ADC_PPBTRIPLO_REQSTAMP_Pos)                         /*!< REQSTAMP        Get Value            */

#define ADC_PPBTRIPLO_LSIGN_Pos                   (16U)                                                                                                 /*!< LSIGN           Position  16         */
#define ADC_PPBTRIPLO_LSIGN_Msk                   (0x1U << ADC_PPBTRIPLO_LSIGN_Pos)                                                                     /*!< LSIGN           Mask      0x00010000 */
#define ADC_PPBTRIPLO_LSIGN_Set(x)                (((uint32_t) (x) << ADC_PPBTRIPLO_LSIGN_Pos) & ADC_PPBTRIPLO_LSIGN_Msk)                               /*!< LSIGN           Set Value            */
#define ADC_PPBTRIPLO_LSIGN_Get(x)                (((uint32_t) (x) & ADC_PPBTRIPLO_LSIGN_Msk) >> ADC_PPBTRIPLO_LSIGN_Pos)                               /*!< LSIGN           Get Value            */

#define ADC_PPBTRIPLO_LIMITLO_Pos                 (0U)                                                                                                  /*!< LIMITLO         Position  0          */
#define ADC_PPBTRIPLO_LIMITLO_Msk                 (0xffffU << ADC_PPBTRIPLO_LIMITLO_Pos)                                                                /*!< LIMITLO         Mask      0x0000FFFF */
#define ADC_PPBTRIPLO_LIMITLO_Set(x)              (((uint32_t) (x) << ADC_PPBTRIPLO_LIMITLO_Pos) & ADC_PPBTRIPLO_LIMITLO_Msk)                           /*!< LIMITLO         Set Value            */
#define ADC_PPBTRIPLO_LIMITLO_Get(x)              (((uint32_t) (x) & ADC_PPBTRIPLO_LIMITLO_Msk) >> ADC_PPBTRIPLO_LIMITLO_Pos)                           /*!< LIMITLO         Get Value            */

/* ADCINTCYCLE bitfield */
#define ADC_ADCINTCYCLE_DELAY_Pos                 (0U)                                                                                                  /*!< DELAY           Position  0          */
#define ADC_ADCINTCYCLE_DELAY_Msk                 (0xffffU << ADC_ADCINTCYCLE_DELAY_Pos)                                                                /*!< DELAY           Mask      0x0000FFFF */
#define ADC_ADCINTCYCLE_DELAY_Set(x)              (((uint16_t) (x) << ADC_ADCINTCYCLE_DELAY_Pos) & ADC_ADCINTCYCLE_DELAY_Msk)                           /*!< DELAY           Set Value            */
#define ADC_ADCINTCYCLE_DELAY_Get(x)              (((uint16_t) (x) & ADC_ADCINTCYCLE_DELAY_Msk) >> ADC_ADCINTCYCLE_DELAY_Pos)                           /*!< DELAY           Get Value            */

/* ADCINLTRIM1 bitfield */
#define ADC_ADCINLTRIM1_INLTRIM31TO0_Pos          (0U)                                                                                                  /*!< INLTRIM31TO0    Position  0          */
#define ADC_ADCINLTRIM1_INLTRIM31TO0_Msk          (0xffffffffU << ADC_ADCINLTRIM1_INLTRIM31TO0_Pos)                                                     /*!< INLTRIM31TO0    Mask      0xFFFFFFFF */
#define ADC_ADCINLTRIM1_INLTRIM31TO0_Set(x)       (((uint32_t) (x) << ADC_ADCINLTRIM1_INLTRIM31TO0_Pos) & ADC_ADCINLTRIM1_INLTRIM31TO0_Msk)             /*!< INLTRIM31TO0    Set Value            */
#define ADC_ADCINLTRIM1_INLTRIM31TO0_Get(x)       (((uint32_t) (x) & ADC_ADCINLTRIM1_INLTRIM31TO0_Msk) >> ADC_ADCINLTRIM1_INLTRIM31TO0_Pos)             /*!< INLTRIM31TO0    Get Value            */

/* ADCINLTRIM2 bitfield */
#define ADC_ADCINLTRIM2_INLTRIM63TO32_Pos         (0U)                                                                                                  /*!< INLTRIM63TO32   Position  0          */
#define ADC_ADCINLTRIM2_INLTRIM63TO32_Msk         (0xffffffffU << ADC_ADCINLTRIM2_INLTRIM63TO32_Pos)                                                    /*!< INLTRIM63TO32   Mask      0xFFFFFFFF */
#define ADC_ADCINLTRIM2_INLTRIM63TO32_Set(x)      (((uint32_t) (x) << ADC_ADCINLTRIM2_INLTRIM63TO32_Pos) & ADC_ADCINLTRIM2_INLTRIM63TO32_Msk)           /*!< INLTRIM63TO32   Set Value            */
#define ADC_ADCINLTRIM2_INLTRIM63TO32_Get(x)      (((uint32_t) (x) & ADC_ADCINLTRIM2_INLTRIM63TO32_Msk) >> ADC_ADCINLTRIM2_INLTRIM63TO32_Pos)           /*!< INLTRIM63TO32   Get Value            */

/* ADCINLTRIM3 bitfield */
#define ADC_ADCINLTRIM3_INLTRIM95TO64_Pos         (0U)                                                                                                  /*!< INLTRIM95TO64   Position  0          */
#define ADC_ADCINLTRIM3_INLTRIM95TO64_Msk         (0xffffffffU << ADC_ADCINLTRIM3_INLTRIM95TO64_Pos)                                                    /*!< INLTRIM95TO64   Mask      0xFFFFFFFF */
#define ADC_ADCINLTRIM3_INLTRIM95TO64_Set(x)      (((uint32_t) (x) << ADC_ADCINLTRIM3_INLTRIM95TO64_Pos) & ADC_ADCINLTRIM3_INLTRIM95TO64_Msk)           /*!< INLTRIM95TO64   Set Value            */
#define ADC_ADCINLTRIM3_INLTRIM95TO64_Get(x)      (((uint32_t) (x) & ADC_ADCINLTRIM3_INLTRIM95TO64_Msk) >> ADC_ADCINLTRIM3_INLTRIM95TO64_Pos)           /*!< INLTRIM95TO64   Get Value            */

/* ADCINLTRIM4 bitfield */
#define ADC_ADCINLTRIM4_INLTRIM127TO96_Pos        (0U)                                                                                                  /*!< INLTRIM127TO96  Position  0          */
#define ADC_ADCINLTRIM4_INLTRIM127TO96_Msk        (0xffffffffU << ADC_ADCINLTRIM4_INLTRIM127TO96_Pos)                                                   /*!< INLTRIM127TO96  Mask      0xFFFFFFFF */
#define ADC_ADCINLTRIM4_INLTRIM127TO96_Set(x)     (((uint32_t) (x) << ADC_ADCINLTRIM4_INLTRIM127TO96_Pos) & ADC_ADCINLTRIM4_INLTRIM127TO96_Msk)         /*!< INLTRIM127TO96  Set Value            */
#define ADC_ADCINLTRIM4_INLTRIM127TO96_Get(x)     (((uint32_t) (x) & ADC_ADCINLTRIM4_INLTRIM127TO96_Msk) >> ADC_ADCINLTRIM4_INLTRIM127TO96_Pos)         /*!< INLTRIM127TO96  Get Value            */

/* ADCINLTRIM5 bitfield */
#define ADC_ADCINLTRIM5_INLTRIM159TO128_Pos       (0U)                                                                                                  /*!< INLTRIM159TO128 Position  0          */
#define ADC_ADCINLTRIM5_INLTRIM159TO128_Msk       (0xffffffffU << ADC_ADCINLTRIM5_INLTRIM159TO128_Pos)                                                  /*!< INLTRIM159TO128 Mask      0xFFFFFFFF */
#define ADC_ADCINLTRIM5_INLTRIM159TO128_Set(x)    (((uint32_t) (x) << ADC_ADCINLTRIM5_INLTRIM159TO128_Pos) & ADC_ADCINLTRIM5_INLTRIM159TO128_Msk)       /*!< INLTRIM159TO128 Set Value            */
#define ADC_ADCINLTRIM5_INLTRIM159TO128_Get(x)    (((uint32_t) (x) & ADC_ADCINLTRIM5_INLTRIM159TO128_Msk) >> ADC_ADCINLTRIM5_INLTRIM159TO128_Pos)       /*!< INLTRIM159TO128 Get Value            */

/* ADCINLTRIM6 bitfield */
#define ADC_ADCINLTRIM6_INLTRIM191TO160_Pos       (0U)                                                                                                  /*!< INLTRIM191TO160 Position  0          */
#define ADC_ADCINLTRIM6_INLTRIM191TO160_Msk       (0xffffffffU << ADC_ADCINLTRIM6_INLTRIM191TO160_Pos)                                                  /*!< INLTRIM191TO160 Mask      0xFFFFFFFF */
#define ADC_ADCINLTRIM6_INLTRIM191TO160_Set(x)    (((uint32_t) (x) << ADC_ADCINLTRIM6_INLTRIM191TO160_Pos) & ADC_ADCINLTRIM6_INLTRIM191TO160_Msk)       /*!< INLTRIM191TO160 Set Value            */
#define ADC_ADCINLTRIM6_INLTRIM191TO160_Get(x)    (((uint32_t) (x) & ADC_ADCINLTRIM6_INLTRIM191TO160_Msk) >> ADC_ADCINLTRIM6_INLTRIM191TO160_Pos)       /*!< INLTRIM191TO160 Get Value            */

/* ADCSOCCNV bitfield */
#define ADC_ADCSOCCNV_SOCCNV_Pos                  (0U)                                                                                                  /*!< SOCCNV          Position  0          */
#define ADC_ADCSOCCNV_SOCCNV_Msk                  (0xffffffffU << ADC_ADCSOCCNV_SOCCNV_Pos)                                                             /*!< SOCCNV          Mask      0xFFFFFFFF */
#define ADC_ADCSOCCNV_SOCCNV_Set(x)               (((uint32_t) (x) << ADC_ADCSOCCNV_SOCCNV_Pos) & ADC_ADCSOCCNV_SOCCNV_Msk)                             /*!< SOCCNV          Set Value            */
#define ADC_ADCSOCCNV_SOCCNV_Get(x)               (((uint32_t) (x) & ADC_ADCSOCCNV_SOCCNV_Msk) >> ADC_ADCSOCCNV_SOCCNV_Pos)                             /*!< SOCCNV          Get Value            */

/* ADCCTL3 bitfield */
#define ADC_ADCCTL3_MUXDELAY_Pos                  (0U)                                                                                                  /*!< MUXDELAY        Position  0          */
#define ADC_ADCCTL3_MUXDELAY_Msk                  (0xffffU << ADC_ADCCTL3_MUXDELAY_Pos)                                                                 /*!< MUXDELAY        Mask      0x0000FFFF */
#define ADC_ADCCTL3_MUXDELAY_Set(x)               (((uint32_t) (x) << ADC_ADCCTL3_MUXDELAY_Pos) & ADC_ADCCTL3_MUXDELAY_Msk)                             /*!< MUXDELAY        Set Value            */
#define ADC_ADCCTL3_MUXDELAY_Get(x)               (((uint32_t) (x) & ADC_ADCCTL3_MUXDELAY_Msk) >> ADC_ADCCTL3_MUXDELAY_Pos)                             /*!< MUXDELAY        Get Value            */

/* ADCCTL4 bitfield */
#define ADC_ADCCTL4_TOP_DBG_SEL_Pos               (18U)                                                                                                 /*!< TOP_DBG_SEL     Position  18         */
#define ADC_ADCCTL4_TOP_DBG_SEL_Msk               (0x7U << ADC_ADCCTL4_TOP_DBG_SEL_Pos)                                                                 /*!< TOP_DBG_SEL     Mask      0x001C0000 */
#define ADC_ADCCTL4_TOP_DBG_SEL_Set(x)            (((uint32_t) (x) << ADC_ADCCTL4_TOP_DBG_SEL_Pos) & ADC_ADCCTL4_TOP_DBG_SEL_Msk)                       /*!< TOP_DBG_SEL     Set Value            */
#define ADC_ADCCTL4_TOP_DBG_SEL_Get(x)            (((uint32_t) (x) & ADC_ADCCTL4_TOP_DBG_SEL_Msk) >> ADC_ADCCTL4_TOP_DBG_SEL_Pos)                       /*!< TOP_DBG_SEL     Get Value            */

#define ADC_ADCCTL4_MISC_DBG_SEL_Pos              (16U)                                                                                                 /*!< MISC_DBG_SEL    Position  16         */
#define ADC_ADCCTL4_MISC_DBG_SEL_Msk              (0x3U << ADC_ADCCTL4_MISC_DBG_SEL_Pos)                                                                /*!< MISC_DBG_SEL    Mask      0x00030000 */
#define ADC_ADCCTL4_MISC_DBG_SEL_Set(x)           (((uint32_t) (x) << ADC_ADCCTL4_MISC_DBG_SEL_Pos) & ADC_ADCCTL4_MISC_DBG_SEL_Msk)                     /*!< MISC_DBG_SEL    Set Value            */
#define ADC_ADCCTL4_MISC_DBG_SEL_Get(x)           (((uint32_t) (x) & ADC_ADCCTL4_MISC_DBG_SEL_Msk) >> ADC_ADCCTL4_MISC_DBG_SEL_Pos)                     /*!< MISC_DBG_SEL    Get Value            */

#define ADC_ADCCTL4_ADC_AUTOK_NUM_Pos             (1U)                                                                                                  /*!< ADC_AUTOK_NUM   Position  1          */
#define ADC_ADCCTL4_ADC_AUTOK_NUM_Msk             (0x3U << ADC_ADCCTL4_ADC_AUTOK_NUM_Pos)                                                               /*!< ADC_AUTOK_NUM   Mask      0x00000006 */
#define ADC_ADCCTL4_ADC_AUTOK_NUM_Set(x)          (((uint32_t) (x) << ADC_ADCCTL4_ADC_AUTOK_NUM_Pos) & ADC_ADCCTL4_ADC_AUTOK_NUM_Msk)                   /*!< ADC_AUTOK_NUM   Set Value            */
#define ADC_ADCCTL4_ADC_AUTOK_NUM_Get(x)          (((uint32_t) (x) & ADC_ADCCTL4_ADC_AUTOK_NUM_Msk) >> ADC_ADCCTL4_ADC_AUTOK_NUM_Pos)                   /*!< ADC_AUTOK_NUM   Get Value            */

#define ADC_ADCCTL4_AUTOK_Pos                     (0U)                                                                                                  /*!< AUTOK           Position  0          */
#define ADC_ADCCTL4_AUTOK_Msk                     (0x1U << ADC_ADCCTL4_AUTOK_Pos)                                                                       /*!< AUTOK           Mask      0x00000001 */
#define ADC_ADCCTL4_AUTOK_Set(x)                  (((uint32_t) (x) << ADC_ADCCTL4_AUTOK_Pos) & ADC_ADCCTL4_AUTOK_Msk)                                   /*!< AUTOK           Set Value            */
#define ADC_ADCCTL4_AUTOK_Get(x)                  (((uint32_t) (x) & ADC_ADCCTL4_AUTOK_Msk) >> ADC_ADCCTL4_AUTOK_Pos)                                   /*!< AUTOK           Get Value            */

/* ADCGAINERR bitfield */
#define ADC_ADCGAINERR_GAINERR_Pos                (0U)                                                                                                  /*!< GAINERR         Position  0          */
#define ADC_ADCGAINERR_GAINERR_Msk                (0xffffffffU << ADC_ADCGAINERR_GAINERR_Pos)                                                           /*!< GAINERR         Mask      0xFFFFFFFF */
#define ADC_ADCGAINERR_GAINERR_Set(x)             (((uint32_t) (x) << ADC_ADCGAINERR_GAINERR_Pos) & ADC_ADCGAINERR_GAINERR_Msk)                         /*!< GAINERR         Set Value            */
#define ADC_ADCGAINERR_GAINERR_Get(x)             (((uint32_t) (x) & ADC_ADCGAINERR_GAINERR_Msk) >> ADC_ADCGAINERR_GAINERR_Pos)                         /*!< GAINERR         Get Value            */

/* ADCCALCTRL bitfield */
#define ADC_ADCCALCTRL_ADCLOCK_Pos                (31U)                                                                                                 /*!< ADCLOCK         Position  31         */
#define ADC_ADCCALCTRL_ADCLOCK_Msk                (0x1U << ADC_ADCCALCTRL_ADCLOCK_Pos)                                                                  /*!< ADCLOCK         Mask      0x80000000 */
#define ADC_ADCCALCTRL_ADCLOCK_Set(x)             (((uint32_t) (x) << ADC_ADCCALCTRL_ADCLOCK_Pos) & ADC_ADCCALCTRL_ADCLOCK_Msk)                         /*!< ADCLOCK         Set Value            */
#define ADC_ADCCALCTRL_ADCLOCK_Get(x)             (((uint32_t) (x) & ADC_ADCCALCTRL_ADCLOCK_Msk) >> ADC_ADCCALCTRL_ADCLOCK_Pos)                         /*!< ADCLOCK         Get Value            */

#define ADC_ADCCALCTRL_OFFDIFCAL_Pos              (6U)                                                                                                  /*!< OFFDIFCAL       Position  6          */
#define ADC_ADCCALCTRL_OFFDIFCAL_Msk              (0x1U << ADC_ADCCALCTRL_OFFDIFCAL_Pos)                                                                /*!< OFFDIFCAL       Mask      0x00000040 */
#define ADC_ADCCALCTRL_OFFDIFCAL_Set(x)           (((uint32_t) (x) << ADC_ADCCALCTRL_OFFDIFCAL_Pos) & ADC_ADCCALCTRL_OFFDIFCAL_Msk)                     /*!< OFFDIFCAL       Set Value            */
#define ADC_ADCCALCTRL_OFFDIFCAL_Get(x)           (((uint32_t) (x) & ADC_ADCCALCTRL_OFFDIFCAL_Msk) >> ADC_ADCCALCTRL_OFFDIFCAL_Pos)                     /*!< OFFDIFCAL       Get Value            */

#define ADC_ADCCALCTRL_CALCTRL_Pos                (2U)                                                                                                  /*!< CALCTRL         Position  2          */
#define ADC_ADCCALCTRL_CALCTRL_Msk                (0xfU << ADC_ADCCALCTRL_CALCTRL_Pos)                                                                  /*!< CALCTRL         Mask      0x0000003C */
#define ADC_ADCCALCTRL_CALCTRL_Set(x)             (((uint32_t) (x) << ADC_ADCCALCTRL_CALCTRL_Pos) & ADC_ADCCALCTRL_CALCTRL_Msk)                         /*!< CALCTRL         Set Value            */
#define ADC_ADCCALCTRL_CALCTRL_Get(x)             (((uint32_t) (x) & ADC_ADCCALCTRL_CALCTRL_Msk) >> ADC_ADCCALCTRL_CALCTRL_Pos)                         /*!< CALCTRL         Get Value            */

#define ADC_ADCCALCTRL_CALSET_Pos                 (1U)                                                                                                  /*!< CALSET          Position  1          */
#define ADC_ADCCALCTRL_CALSET_Msk                 (0x1U << ADC_ADCCALCTRL_CALSET_Pos)                                                                   /*!< CALSET          Mask      0x00000002 */
#define ADC_ADCCALCTRL_CALSET_Set(x)              (((uint32_t) (x) << ADC_ADCCALCTRL_CALSET_Pos) & ADC_ADCCALCTRL_CALSET_Msk)                           /*!< CALSET          Set Value            */
#define ADC_ADCCALCTRL_CALSET_Get(x)              (((uint32_t) (x) & ADC_ADCCALCTRL_CALSET_Msk) >> ADC_ADCCALCTRL_CALSET_Pos)                           /*!< CALSET          Get Value            */

#define ADC_ADCCALCTRL_CALEN_Pos                  (0U)                                                                                                  /*!< CALEN           Position  0          */
#define ADC_ADCCALCTRL_CALEN_Msk                  (0x1U << ADC_ADCCALCTRL_CALEN_Pos)                                                                    /*!< CALEN           Mask      0x00000001 */
#define ADC_ADCCALCTRL_CALEN_Set(x)               (((uint32_t) (x) << ADC_ADCCALCTRL_CALEN_Pos) & ADC_ADCCALCTRL_CALEN_Msk)                             /*!< CALEN           Set Value            */
#define ADC_ADCCALCTRL_CALEN_Get(x)               (((uint32_t) (x) & ADC_ADCCALCTRL_CALEN_Msk) >> ADC_ADCCALCTRL_CALEN_Pos)                             /*!< CALEN           Get Value            */

/* ADCBIAS bitfield */
#define ADC_ADCBIAS_DUMMY1_Pos                    (24U)                                                                                                 /*!< DUMMY1          Position  24         */
#define ADC_ADCBIAS_DUMMY1_Msk                    (0xffU << ADC_ADCBIAS_DUMMY1_Pos)                                                                     /*!< DUMMY1          Mask      0xFF000000 */
#define ADC_ADCBIAS_DUMMY1_Set(x)                 (((uint32_t) (x) << ADC_ADCBIAS_DUMMY1_Pos) & ADC_ADCBIAS_DUMMY1_Msk)                                 /*!< DUMMY1          Set Value            */
#define ADC_ADCBIAS_DUMMY1_Get(x)                 (((uint32_t) (x) & ADC_ADCBIAS_DUMMY1_Msk) >> ADC_ADCBIAS_DUMMY1_Pos)                                 /*!< DUMMY1          Get Value            */

#define ADC_ADCBIAS_CMPBIAS3_Pos                  (6U)                                                                                                  /*!< CMPBIAS3        Position  6          */
#define ADC_ADCBIAS_CMPBIAS3_Msk                  (0x7U << ADC_ADCBIAS_CMPBIAS3_Pos)                                                                    /*!< CMPBIAS3        Mask      0x000001C0 */
#define ADC_ADCBIAS_CMPBIAS3_Set(x)               (((uint32_t) (x) << ADC_ADCBIAS_CMPBIAS3_Pos) & ADC_ADCBIAS_CMPBIAS3_Msk)                             /*!< CMPBIAS3        Set Value            */
#define ADC_ADCBIAS_CMPBIAS3_Get(x)               (((uint32_t) (x) & ADC_ADCBIAS_CMPBIAS3_Msk) >> ADC_ADCBIAS_CMPBIAS3_Pos)                             /*!< CMPBIAS3        Get Value            */

#define ADC_ADCBIAS_CMPBIAS2_Pos                  (3U)                                                                                                  /*!< CMPBIAS2        Position  3          */
#define ADC_ADCBIAS_CMPBIAS2_Msk                  (0x7U << ADC_ADCBIAS_CMPBIAS2_Pos)                                                                    /*!< CMPBIAS2        Mask      0x00000038 */
#define ADC_ADCBIAS_CMPBIAS2_Set(x)               (((uint32_t) (x) << ADC_ADCBIAS_CMPBIAS2_Pos) & ADC_ADCBIAS_CMPBIAS2_Msk)                             /*!< CMPBIAS2        Set Value            */
#define ADC_ADCBIAS_CMPBIAS2_Get(x)               (((uint32_t) (x) & ADC_ADCBIAS_CMPBIAS2_Msk) >> ADC_ADCBIAS_CMPBIAS2_Pos)                             /*!< CMPBIAS2        Get Value            */

#define ADC_ADCBIAS_CMPBIAS1_Pos                  (0U)                                                                                                  /*!< CMPBIAS1        Position  0          */
#define ADC_ADCBIAS_CMPBIAS1_Msk                  (0x7U << ADC_ADCBIAS_CMPBIAS1_Pos)                                                                    /*!< CMPBIAS1        Mask      0x00000007 */
#define ADC_ADCBIAS_CMPBIAS1_Set(x)               (((uint32_t) (x) << ADC_ADCBIAS_CMPBIAS1_Pos) & ADC_ADCBIAS_CMPBIAS1_Msk)                             /*!< CMPBIAS1        Set Value            */
#define ADC_ADCBIAS_CMPBIAS1_Get(x)               (((uint32_t) (x) & ADC_ADCBIAS_CMPBIAS1_Msk) >> ADC_ADCBIAS_CMPBIAS1_Pos)                             /*!< CMPBIAS1        Get Value            */

/* ADCRESULT bitfield */
#define ADC_RESULT_ADCRESULT_RESULT_Pos           (0U)                                                                                                  /*!< RESULT          Position  0          */
#define ADC_RESULT_ADCRESULT_RESULT_Msk           (0xffffU << ADC_RESULT_ADCRESULT_RESULT_Pos)                                                          /*!< RESULT          Mask      0x0000FFFF */
#define ADC_RESULT_ADCRESULT_RESULT_Set(x)        (((uint16_t) (x) << ADC_RESULT_ADCRESULT_RESULT_Pos) & ADC_RESULT_ADCRESULT_RESULT_Msk)               /*!< RESULT          Set Value            */
#define ADC_RESULT_ADCRESULT_RESULT_Get(x)        (((uint16_t) (x) & ADC_RESULT_ADCRESULT_RESULT_Msk) >> ADC_RESULT_ADCRESULT_RESULT_Pos)               /*!< RESULT          Get Value            */

/* ADCPPBRESULT bitfield */
#define ADC_RESULT_ADCPPBRESULT_SIGN_Pos          (16U)                                                                                                 /*!< SIGN            Position  16         */
#define ADC_RESULT_ADCPPBRESULT_SIGN_Msk          (0xffffU << ADC_RESULT_ADCPPBRESULT_SIGN_Pos)                                                         /*!< SIGN            Mask      0xFFFF0000 */
#define ADC_RESULT_ADCPPBRESULT_SIGN_Set(x)       (((uint32_t) (x) << ADC_RESULT_ADCPPBRESULT_SIGN_Pos) & ADC_RESULT_ADCPPBRESULT_SIGN_Msk)             /*!< SIGN            Set Value            */
#define ADC_RESULT_ADCPPBRESULT_SIGN_Get(x)       (((uint32_t) (x) & ADC_RESULT_ADCPPBRESULT_SIGN_Msk) >> ADC_RESULT_ADCPPBRESULT_SIGN_Pos)             /*!< SIGN            Get Value            */

#define ADC_RESULT_ADCPPBRESULT_PPBRESULT_Pos     (0U)                                                                                                  /*!< PPBRESULT       Position  0          */
#define ADC_RESULT_ADCPPBRESULT_PPBRESULT_Msk     (0xffffU << ADC_RESULT_ADCPPBRESULT_PPBRESULT_Pos)                                                    /*!< PPBRESULT       Mask      0x0000FFFF */
#define ADC_RESULT_ADCPPBRESULT_PPBRESULT_Set(x)  (((uint32_t) (x) << ADC_RESULT_ADCPPBRESULT_PPBRESULT_Pos) & ADC_RESULT_ADCPPBRESULT_PPBRESULT_Msk)   /*!< PPBRESULT       Set Value            */
#define ADC_RESULT_ADCPPBRESULT_PPBRESULT_Get(x)  (((uint32_t) (x) & ADC_RESULT_ADCPPBRESULT_PPBRESULT_Msk) >> ADC_RESULT_ADCPPBRESULT_PPBRESULT_Pos)   /*!< PPBRESULT       Get Value            */

/*!
 * @}
 */

/* clang-format on */

/*!
 * @}
 */ /* end of HS32F7D377_ADC_REGISTER */

#endif /* HS32F7D377_ADC_H */
