/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


/*!
 * \file   HS32F7D377_cmpss.h
 * \brief  HS32F7D377 CMPSS register file
 * \version V1.0_20231008
 */

#ifndef HS32F7D377_CMPSS_H
#define HS32F7D377_CMPSS_H

/*!
 * \addtogroup   HS32F7D377_CMPSS_REGISTER HS32F7D377 CMPSS Register
 * \ingroup HS32F7D377_REGISTER
 *
 * \brief  CMPSS register layout, bitfield and address definitions
 *
 * @{
 */

/* clang-format off */

/*!
 * \name CMPSS Register Layout
 *
 *
 * @{
 */

/*! \brief CMPSS register */
typedef struct {
    union
    {
        __IOM uint16_t COMPCTL                           ;  /*!< 0x00000000 : CMPSS Comparator Control Register */
    
        struct
        {
            __IOM uint16_t COMPHSOURCE               : 1 ;  /*!< [ 0: 0] : High comparator input source.
                                                                           0 Inverting input of comparator driven by internal DAC
                                                                           1 Inverting input of comparator driven through external pin Reset type: SYSRSn */
            __IOM uint16_t COMPHINV                  : 1 ;  /*!< [ 1: 1] : High comparator output invert.
                                                                           0 Output of comparator is not inverted 1 Output of comparator is inverted Reset type: SYSRSn */
            __IOM uint16_t CTRIPHSEL                 : 2 ;  /*!< [ 3: 2] : High comparator CTRIPH source select.
                                                                           0 Asynchronous comparator output drives CTRIPH 1 Synchronous comparator output drives CTRIPH 2 Output of digital filter drives CTRIPH
                                                                           3 Latched output of digital filter drives CTRIPH Reset type: SYSRSn */
            __IOM uint16_t CTRIPOUTHSEL              : 2 ;  /*!< [ 5: 4] : High comparator CTRIPOUTH source select.
                                                                           0 Asynchronous comparator output drives CTRIPOUTH 1 Synchronous comparator output drives CTRIPOUTH 2 Output of digital filter drives CTRIPOUTH
                                                                           3 Latched output of digital filter drives CTRIPOUTH Reset type: SYSRSn */
            __IOM uint16_t ASYNCHEN                  : 1 ;  /*!< [ 6: 6] : High comparator asynchronous path enable. Allows asynchronous comparator output to feed into OR gate with latched digital filter signal when CTRIPHSEL=3 or CTRIPOUTHSEL=3.
                                                                           0 Asynchronous comparator output does not feed into OR gate with latched digital filter output
                                                                           1 Asynchronous comparator output feeds into OR gate with latched digital filter output
                                                                           Reset type: SYSRSn */
            __IOM uint16_t BLANKINV                  : 1 ;  /*!< [ 7: 7] : Blanking Window Inversion
                                                                           0: Blanking window not inverted
                                                                           1: Blanking window inverted
                                                                           Reset type: SYSRSn */
            __IOM uint16_t COMPLSOURCE               : 1 ;  /*!< [ 8: 8] : Low comparator input source.
                                                                           0 Inverting input of comparator driven by internal DAC
                                                                           1 Inverting input of comparator driven through external pin Reset type: SYSRSn */
            __IOM uint16_t COMPLINV                  : 1 ;  /*!< [ 9: 9] : Low comparator output invert.
                                                                           0 Output of comparator is not inverted 1 Output of comparator is inverted Reset type: SYSRSn */
            __IOM uint16_t CTRIPLSEL                 : 2 ;  /*!< [11:10] : Low comparator CTRIPL source select.
                                                                           0 Asynchronous comparator output drives CTRIPL 1 Synchronous comparator output drives CTRIPL 2 Output of digital filter drives CTRIPL
                                                                           3 Latched output of digital filter drives CTRIPL Reset type: SYSRSn */
            __IOM uint16_t CTRIPOUTLSEL              : 2 ;  /*!< [13:12] : Low comparator CTRIPOUTL source select.
                                                                           0 Asynchronous comparator output drives CTRIPOUTL 1 Synchronous comparator output drives CTRIPOUTL 2 Output of digital filter drives CTRIPOUTL
                                                                           3 Latched output of digital filter drives CTRIPOUTL Reset type: SYSRSn */
            __IOM uint16_t ASYNCLEN                  : 1 ;  /*!< [14:14] : Low comparator asynchronous path enable. Allows asynchronous comparator output to feed into OR gate with latched digital filter signal when CTRIPLSEL=3 or CTRIPOUTLSEL=3.
                                                                           0 Asynchronous comparator output does not feed into OR gate with latched digital filter output
                                                                           1 Asynchronous comparator output feeds into OR gate with latched digital filter output
                                                                           Reset type: SYSRSn */
            __IOM uint16_t COMPDACE                  : 1 ;  /*!< [15:15] : Comparator/DAC enable.
                                                                           0 Comparator/DAC disabled
                                                                           1 Comparator/DAC enabled Reset type: SYSRSn */
        } COMPCTLb;
    };

    union
    {
        __IOM uint16_t COMPHYSCTL                        ;  /*!< 0x00000002 : CMPSS Comparator Hysteresis Control Register */
    
        struct
        {
            __IOM uint16_t COMPHYS                   : 4 ;  /*!< [ 3: 0] : Comparator hysteresis. Sets the amount of hysteresis on the comparator inputs.
                                                                           0 None
                                                                           1 Set to typical hysteresis
                                                                           2 Set to 2x of typical hysteresis 3 Set to 3x of typical hysteresis 4 Set to 4x of typical hysteresis others : undefined
                                                                           Reset type: SYSRSn */
                  uint16_t RSV_0                     : 12;  /*!< [15: 4] : reserved. */
        } COMPHYSCTLb;
    };

    union
    {
        __IM  uint16_t COMPSTS                           ;  /*!< 0x00000004 : CMPSS Comparator Status Register */
    
        struct
        {
            __IM  uint16_t COMPHSTS                  : 1 ;  /*!< [ 0: 0] : High comparator digital filter output Reset type: SYSRSn. */
            __IM  uint16_t COMPHLATCH                : 1 ;  /*!< [ 1: 1] : Latched value of high comparator digital filter output Reset type: SYSRSn. */
                  uint16_t RSV_0                     : 6 ;  /*!< [ 7: 2] : reserved. */
            __IM  uint16_t COMPLSTS                  : 1 ;  /*!< [ 8: 8] : Low comparator digital filter output Reset type: SYSRSn. */
            __IM  uint16_t COMPLLATCH                : 1 ;  /*!< [ 9: 9] : Latched value of low comparator digital filter output Reset type: SYSRSn. */
                  uint16_t RSV_1                     : 6 ;  /*!< [15:10] : reserved. */
        } COMPSTSb;
    };

    union
    {
        __IOM uint16_t COMPSTSCLR                        ;  /*!< 0x00000006 : CMPSS Comparator Status Clear Register */
    
        struct
        {
                  uint16_t RSV_0                     : 1 ;  /*!< [ 0: 0] : reserved. */
            __IOM uint16_t HLATCHCLR                 : 1 ;  /*!< [ 1: 1] : High comparator latch software clear. Perform software reset of high comparator digital filter output latch COMPSTS[COMPHLATCH].
                                                                           Reads always return 0. 0 No effect
                                                                           1 Generate a single pulse of latch reset signal for COMPSTS[COMPHLATCH]
                                                                           Reset type: SYSRSn */
            __IOM uint16_t HSYNCCLREN                : 1 ;  /*!< [ 2: 2] : High comparator latch EPWMSYNCPER clear. Enable EPWMSYNCPER reset of high comparator digital filter output latch COMPSTS[COMPHLATCH].
                                                                           0 EPWMSYNCPER will not reset latch 1 EPWMSYNCPER will reset latch Reset type: SYSRSn */
                  uint16_t RSV_1                     : 6 ;  /*!< [ 8: 3] : reserved. */
            __IOM uint16_t LLATCHCLR                 : 1 ;  /*!< [ 9: 9] : Low comparator latch software clear. Perform software reset of low comparator digital filter output latch COMPSTS[COMPLLATCH].
                                                                           Reads always return 0. 0 No effect
                                                                           1 Generate a single pulse of latch reset signal for COMPSTS[COMPLLATCH]
                                                                           Reset type: SYSRSn */
            __IOM uint16_t LSYNCCLREN                : 1 ;  /*!< [10:10] : Low comparator latch EPWMSYNCPER clear. Enable EPWMSYNCPER reset of low comparator digital filter output latch COMPSTS[COMPLLATCH].
                                                                           0 EPWMSYNCPER will not reset latch 1 EPWMSYNCPER will reset latch Reset type: SYSRSn */
                  uint16_t RSV_2                     : 5 ;  /*!< [15:11] : reserved. */
        } COMPSTSCLRb;
    };

    union
    {
        __IOM uint32_t COMPDACCTL                        ;  /*!< 0x00000008 : CMPSS DAC Control Register */
    
        struct
        {
            __IOM uint32_t DACSOURCE                 : 1 ;  /*!< [ 0: 0] : DAC source select. Determines whether DACHVALA is updated from DACHVALS or from the ramp generator.
                                                                           0 DACHVALA is updated from DACHVALS
                                                                           1 DACHVALA is updated from the ramp generator Reset type: SYSRSn */
            __IOM uint32_t RAMPSOURCE                : 4 ;  /*!< [ 4: 1] : EPWMSYNCPER source select. Determines which EPWMnSYNCPER signal is used within the CMPSS module. Where n represents the maximum number of EPWMSYNCPER signals available on the device:
                                                                           0 EPWM1SYNCPER
                                                                           1 EPWM2SYNCPER
                                                                           2 EPWM3SYNCPER
                                                                           ...
                                                                           n-1 EPWMnSYNCPER
                                                                           Reset type: SYSRSn */
            __IOM uint32_t SELREF                    : 1 ;  /*!< [ 5: 5] : DAC reference select. Determines which voltage supply is used as the reference for the internal comparator DACs.
                                                                           0 VDDA is the voltage reference for the DAC 1 VDAC is the voltage reference for the DAC Reset type: SYSRSn */
            __IOM uint32_t RAMPLOADSEL               : 1 ;  /*!< [ 6: 6] : Ramp load select. Determines whether RAMPSTS is updated from RAMPMAXREFA or RAMPMAXREFS when
                                                                           COMPSTS[COMPHSTS] is triggered.
                                                                           0 RAMPSTS is loaded from RAMPMAXREFA 1 RAMPSTS is loaded from RAMPMAXREFS Reset type: SYSRSn */
            __IOM uint32_t SWLOADSEL                 : 1 ;  /*!< [ 7: 7] : Software load select. Determines whether DACxVALA is updated from DACxVALS on SYSCLK or EPWMSYNCPER.
                                                                           0 DACxVALA is updated from DACxVALS on SYSCLK
                                                                           1 DACxVALA is updated from DACxVALS on EPWMSYNCPER Reset type: SYSRSn */
            __IOM uint32_t BLANKSOURCE               : 4 ;  /*!< [11: 8] : EPWMBLANK source select. This bit field determines which EPWMnBLANK is passed on as the EPWMBLANK signal.
                                                                           Where n represents the maximum number of EPWMBLANK signals available on the device:
                                                                           0 EPWM1BLANK
                                                                           1 EPWM2BLANK
                                                                           2 EPWM3BLANK
                                                                           ...
                                                                           n-1 EPWMnBLANK
                                                                           Reset type: SYSRSn */
            __IOM uint32_t BLANKEN                   : 1 ;  /*!< [12:12] : EPWMBLANK enable. This bit enables the EPWMBLANK signal. 0 EPWMBLANK signal is disabled.
                                                                           1 EPWMBLANK signal is enabled. Reset type: SYSRSn */
            __IOM uint32_t PRESCALE                  : 1 ;  /*!< [13:13] : Rampctr Prescale
                                                                           0: the maximum prescale is effectively 16, [15:4] of rampctr is valid;
                                                                           1: the maximum prescale is effectively 4096, [23:12] of rampctr is valid.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t FREESOFT                  : 2 ;  /*!< [15:14] : Free-run or software-run emulation behavior. Behavior of the ramp generator during emulation suspend.
                                                                           00b Ramp generator stops immediately during emulation suspend 01b Ramp generator completes current ramp and stops at next EPWMSYNCPER during emulation suspend
                                                                           1Xb Ramp generator runs freely Reset type: SYSRSn */
                  uint32_t RSV_0                     : 16;  /*!< [31:16] : reserved. */
        } COMPDACCTLb;
    };

    union
    {
        __IOM uint16_t DACHVALS                          ;  /*!< 0x0000000c : CMPSS High DAC Value Shadow Register */
    
        struct
        {
            __IOM uint16_t DACVAL                    : 12;  /*!< [11: 0] : High DAC shadow value. When COMPDACCTL[DACSOURCE]=0, the value of DACHVALS is loaded into DACHVALA on the trigger signal selected by COMPDACCTL[SWLOADSEL].
                                                                           Reset type: SYSRSn */
                  uint16_t RSV_0                     : 4 ;  /*!< [15:12] : reserved. */
        } DACHVALSb;
    };

    union
    {
        __IM  uint16_t DACHVALA                          ;  /*!< 0x0000000e : CMPSS High DAC Value Active Register */
    
        struct
        {
            __IM  uint16_t DACVAL                    : 12;  /*!< [11: 0] : High DAC active value. */
                  uint16_t RSV_0                     : 4 ;  /*!< [15:12] : reserved. */
        } DACHVALAb;
    };

    union
    {
        __IM  uint32_t RAMPMAXREFA                       ;  /*!< 0x00000010 : CMPSS Ramp Max Reference Active Register */
    
        struct
        {
            __IM  uint32_t RAMPMAXREF                : 24;  /*!< [23: 0] : Ramp maximum reference active value. Latched value to be loaded into ramp generator RAMPSTS.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 8 ;  /*!< [31:24] : reserved. */
        } RAMPMAXREFAb;
    };

    union
    {
        __IOM uint32_t RAMPMAXREFS                       ;  /*!< 0x00000014 : CMPSS Ramp Max Reference Shadow Register */
    
        struct
        {
            __IOM uint32_t RAMPMAXREF                : 24;  /*!< [23: 0] : Ramp maximum reference shadow. Unlatched value to be loaded into ramp generator RAMPSTS.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 8 ;  /*!< [31:24] : reserved. */
        } RAMPMAXREFSb;
    };

    union
    {
        __IM  uint32_t RAMPDECVALA                       ;  /*!< 0x00000018 : CMPSS Ramp Decrement Value Active Register */
    
        struct
        {
            __IM  uint32_t RAMPDECVAL                : 24;  /*!< [23: 0] : Ramp decrement value active. Latched value that will be subtracted from RAMPSTS.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 8 ;  /*!< [31:24] : reserved. */
        } RAMPDECVALAb;
    };

    union
    {
        __IOM uint32_t RAMPDECVALS                       ;  /*!< 0x0000001c : CMPSS Ramp Decrement Value Shadow Register */
    
        struct
        {
            __IOM uint32_t RAMPDECVAL                : 24;  /*!< [23: 0] : Ramp decrement value shadow. Unlatched value to be loaded into RAMPDECVALA.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 8 ;  /*!< [31:24] : reserved. */
        } RAMPDECVALSb;
    };

    union
    {
        __IM  uint32_t RAMPSTS                           ;  /*!< 0x00000020 : CMPSS Ramp Status Register */
    
        struct
        {
            __IM  uint32_t RAMPVALUE                 : 24;  /*!< [23: 0] : Ramp value. */
                  uint32_t RSV_0                     : 8 ;  /*!< [31:24] : reserved. */
        } RAMPSTSb;
    };

    union
    {
        __IOM uint16_t DACLVALS                          ;  /*!< 0x00000024 : CMPSS Low DAC Value Shadow Register */
    
        struct
        {
            __IOM uint16_t DACVAL                    : 12;  /*!< [11: 0] : Low DAC shadow value. value to be loaded into DACLVALA on the trigger signal selected by COMPDACCTL[SWLOADSEL].
                                                                           Reset type: SYSRSn */
                  uint16_t RSV_0                     : 4 ;  /*!< [15:12] : reserved. */
        } DACLVALSb;
    };

    union
    {
        __IM  uint16_t DACLVALA                          ;  /*!< 0x00000026 : CMPSS Low DAC Value Active Register */
    
        struct
        {
            __IM  uint16_t DACVAL                    : 12;  /*!< [11: 0] : Low DAC active value. */
                  uint16_t RSV_0                     : 4 ;  /*!< [15:12] : reserved. */
        } DACLVALAb;
    };

    union
    {
        __IM  uint16_t RAMPDLYA                          ;  /*!< 0x00000028 : CMPSS Ramp Delay Active Register */
    
        struct
        {
            __IM  uint16_t DELAY                     : 13;  /*!< [12: 0] : Ramp delay active value. Latched value of the number of cycles to delay the start of the ramp generator decrementer after a EPWMSYNCPER is received.
                                                                           Reset type: SYSRSn */
                  uint16_t RSV_0                     : 3 ;  /*!< [15:13] : reserved. */
        } RAMPDLYAb;
    };

    union
    {
        __IOM uint16_t RAMPDLYS                          ;  /*!< 0x0000002a : CMPSS Ramp Delay Shadow Register */
    
        struct
        {
            __IOM uint16_t DELAY                     : 13;  /*!< [12: 0] : Ramp delay shadow value. Unlatched value to be loaded into RAMPDLYA.
                                                                           Reset type: SYSRSn */
                  uint16_t RSV_0                     : 3 ;  /*!< [15:13] : reserved. */
        } RAMPDLYSb;
    };

    union
    {
        __IOM uint16_t CTRIPLFILCTL                      ;  /*!< 0x0000002c : CTRIPL Filter Control Register */
    
        struct
        {
                  uint16_t RSV_0                     : 4 ;  /*!< [ 3: 0] : reserved. */
            __IOM uint16_t SAMPWIN                   : 5 ;  /*!< [ 8: 4] : Low filter sample window size. Number of samples to monitor is SAMPWIN+1.
                                                                           Reset type: SYSRSn */
            __IOM uint16_t THRESH                    : 5 ;  /*!< [13: 9] : Low filter majority voting threshold. At least THRESH samples of the opposite state must appear within the sample window in order for the output to change state. Threshold used is THRESH+1.
                                                                           Reset type: SYSRSn */
                  uint16_t RSV_1                     : 1 ;  /*!< [14:14] : reserved. */
            __IOM uint16_t FILINIT                   : 1 ;  /*!< [15:15] : Low filter initialization. 0 No effect
                                                                           1 Initialize all samples to the filter input value Reset type: SYSRSn */
        } CTRIPLFILCTLb;
    };

    union
    {
        __IOM uint16_t CTRIPLFILCLKCTL                   ;  /*!< 0x0000002e : CTRIPL Filter Clock Control Register */
    
        struct
        {
            __IOM uint16_t CLKPRESCALE               : 10;  /*!< [ 9: 0] : Low filter sample clock prescale. Number of system clocks between samples is CLKPRESCALE+1.
                                                                           Reset type: SYSRSn */
                  uint16_t RSV_0                     : 6 ;  /*!< [15:10] : reserved. */
        } CTRIPLFILCLKCTLb;
    };

    union
    {
        __IOM uint16_t CTRIPHFILCTL                      ;  /*!< 0x00000030 : CTRIPH Filter Control Register */
    
        struct
        {
                  uint16_t RSV_0                     : 4 ;  /*!< [ 3: 0] : reserved. */
            __IOM uint16_t SAMPWIN                   : 5 ;  /*!< [ 8: 4] : High filter sample window size. Number of samples to monitor is SAMPWIN+1.
                                                                           Reset type: SYSRSn */
            __IOM uint16_t THRESH                    : 5 ;  /*!< [13: 9] : High filter majority voting threshold. At least THRESH samples of the opposite state must appear within the sample window in order for the output to change state. Threshold used is THRESH+1.
                                                                           Reset type: SYSRSn */
                  uint16_t RSV_1                     : 1 ;  /*!< [14:14] : reserved. */
            __IOM uint16_t FILINIT                   : 1 ;  /*!< [15:15] : High filter initialization. 0 No effect
                                                                           1 Initialize all samples to the filter input value Reset type: SYSRSn */
        } CTRIPHFILCTLb;
    };

    union
    {
        __IOM uint16_t CTRIPHFILCLKCTL                   ;  /*!< 0x00000032 : CTRIPH Filter Clock Control Register */
    
        struct
        {
            __IOM uint16_t CLKPRESCALE               : 10;  /*!< [ 9: 0] : High filter sample clock prescale. Number of system clocks between samples is CLKPRESCALE+1.
                                                                           Reset type: SYSRSn */
                  uint16_t RSV_0                     : 6 ;  /*!< [15:10] : reserved. */
        } CTRIPHFILCLKCTLb;
    };

    union
    {
        __IOM uint32_t COMPLOCK                          ;  /*!< 0x00000034 : CMPSS Lock Register */
    
        struct
        {
            __IOM uint32_t COMPCTL                   : 1 ;  /*!< [ 0: 0] : Lock write-access to the COMPCTL register.
                                                                           0 COMPCTL register is not locked. Write 0 to this bit has no effect. 1 COMPCTL register is locked. Only a system reset can clear this bit.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t COMPHYSCTL                : 1 ;  /*!< [ 1: 1] : Lock write-access to the COMPHYSCTL register.
                                                                           0 COMPHYSCTL register is not locked. Write 0 to this bit has no effect.
                                                                           1 COMPHYSCTL register is locked. Only a system reset can clear this bit.
                                                                           Reset type: SYSRSn */
            __IOM uint32_t DACCTL                    : 1 ;  /*!< [ 2: 2] : Lock write-access to the DACCTL register.
                                                                           0 DACCTL register is not locked. Write 0 to this bit has no effect.
                                                                           1 DACCTL register is locked. Only a system reset can clear this bit. Reset type: SYSRSn */
            __IOM uint32_t CTRIP                     : 1 ;  /*!< [ 3: 3] : Lock write-access to the CTRIPxFILTCTL and CTRIPxFILCLKCTL registers.
                                                                           0 CTRIPxFILCTL and CTRIPxFILCLKCTL registers are not locked. Write 0 to this bit has no effect.
                                                                           1 CTRIPxFILCTL and CTRIPxFILCLKCTL registers are locked. Only a system reset can clear this bit.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 28;  /*!< [31: 4] : reserved. */
        } COMPLOCKb;
    };

    uint8_t    RSV_0X38[40]                              ;  /*!< 0x00000038~0x0000005f : reserved */

    union
    {
        __IOM uint32_t CMPSSTRIM                         ;  /*!< 0x00000060 : CMPSS Trim Register */
    
        struct
        {
            __IOM uint32_t HOFFTRIM                  : 8 ;  /*!< [ 7: 0] : CMPSS Offset Trim.
                                                                           Adjusts the conversion results of the converter up or down to account for offset error in the CMPSS.
                                                                           Range is +127 steps to -128 steps (2's compliment format).
                                                                           Regardless of the converter resolution, the size of each trim step is
                                                                           vref / 4096.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_0                     : 8 ;  /*!< [15: 8] : reserved. */
            __IOM uint32_t LOFFTRIM                  : 8 ;  /*!< [23:16] : CMPSS Offset Trim.
                                                                           Adjusts the conversion results of the converter up or down to account for offset error in the CMPSS.
                                                                           Range is +127 steps to -128 steps (2's compliment format).
                                                                           Regardless of the converter resolution, the size of each trim step is
                                                                           vref / 4096.
                                                                           Reset type: SYSRSn */
                  uint32_t RSV_1                     : 8 ;  /*!< [31:24] : reserved. */
        } CMPSSTRIMb;
    };

    uint8_t    RSV_0X64[924]                             ;
} CMPSS_Type;


/*!
 * @}
 */

/*!
 * \name CMPSS Base Address Definitions
 *
 * @{
 */

/*! \brief CMPSS1 base address */
#define CMPSS1_BASE (0x41500000UL)
/*! \brief CMPSS2 base address */
#define CMPSS2_BASE (0x41500400UL)
/*! \brief CMPSS3 base address */
#define CMPSS3_BASE (0x41500800UL)
/*! \brief CMPSS4 base address */
#define CMPSS4_BASE (0x41500c00UL)
/*! \brief CMPSS5 base address */
#define CMPSS5_BASE (0x41501000UL)
/*! \brief CMPSS6 base address */
#define CMPSS6_BASE (0x41501400UL)
/*! \brief CMPSS7 base address */
#define CMPSS7_BASE (0x41501800UL)
/*! \brief CMPSS8 base address */
#define CMPSS8_BASE (0x41501c00UL)
/*! \brief CMPSS1 base pointer */
#define CMPSS1 ((CMPSS_Type *) CMPSS1_BASE)
/*! \brief CMPSS2 base pointer */
#define CMPSS2 ((CMPSS_Type *) CMPSS2_BASE)
/*! \brief CMPSS3 base pointer */
#define CMPSS3 ((CMPSS_Type *) CMPSS3_BASE)
/*! \brief CMPSS4 base pointer */
#define CMPSS4 ((CMPSS_Type *) CMPSS4_BASE)
/*! \brief CMPSS5 base pointer */
#define CMPSS5 ((CMPSS_Type *) CMPSS5_BASE)
/*! \brief CMPSS6 base pointer */
#define CMPSS6 ((CMPSS_Type *) CMPSS6_BASE)
/*! \brief CMPSS7 base pointer */
#define CMPSS7 ((CMPSS_Type *) CMPSS7_BASE)
/*! \brief CMPSS8 base pointer */
#define CMPSS8 ((CMPSS_Type *) CMPSS8_BASE)


/*!
 * @}
 */


/*!
 * \name CMPSS Register Bitfield Definitions
 *
 * @{
 */

/* COMPCTL bitfield */
#define CMPSS_COMPCTL_COMPDACE_Pos                (15U)                                                                                                 /*!< COMPDACE     Position  15         */
#define CMPSS_COMPCTL_COMPDACE_Msk                (0x1U << CMPSS_COMPCTL_COMPDACE_Pos)                                                                  /*!< COMPDACE     Mask      0x00008000 */
#define CMPSS_COMPCTL_COMPDACE_Set(x)             (((uint16_t) (x) << CMPSS_COMPCTL_COMPDACE_Pos) & CMPSS_COMPCTL_COMPDACE_Msk)                         /*!< COMPDACE     Set Value            */
#define CMPSS_COMPCTL_COMPDACE_Get(x)             (((uint16_t) (x) & CMPSS_COMPCTL_COMPDACE_Msk) >> CMPSS_COMPCTL_COMPDACE_Pos)                         /*!< COMPDACE     Get Value            */

#define CMPSS_COMPCTL_ASYNCLEN_Pos                (14U)                                                                                                 /*!< ASYNCLEN     Position  14         */
#define CMPSS_COMPCTL_ASYNCLEN_Msk                (0x1U << CMPSS_COMPCTL_ASYNCLEN_Pos)                                                                  /*!< ASYNCLEN     Mask      0x00004000 */
#define CMPSS_COMPCTL_ASYNCLEN_Set(x)             (((uint16_t) (x) << CMPSS_COMPCTL_ASYNCLEN_Pos) & CMPSS_COMPCTL_ASYNCLEN_Msk)                         /*!< ASYNCLEN     Set Value            */
#define CMPSS_COMPCTL_ASYNCLEN_Get(x)             (((uint16_t) (x) & CMPSS_COMPCTL_ASYNCLEN_Msk) >> CMPSS_COMPCTL_ASYNCLEN_Pos)                         /*!< ASYNCLEN     Get Value            */

#define CMPSS_COMPCTL_CTRIPOUTLSEL_Pos            (12U)                                                                                                 /*!< CTRIPOUTLSEL Position  12         */
#define CMPSS_COMPCTL_CTRIPOUTLSEL_Msk            (0x3U << CMPSS_COMPCTL_CTRIPOUTLSEL_Pos)                                                              /*!< CTRIPOUTLSEL Mask      0x00003000 */
#define CMPSS_COMPCTL_CTRIPOUTLSEL_Set(x)         (((uint16_t) (x) << CMPSS_COMPCTL_CTRIPOUTLSEL_Pos) & CMPSS_COMPCTL_CTRIPOUTLSEL_Msk)                 /*!< CTRIPOUTLSEL Set Value            */
#define CMPSS_COMPCTL_CTRIPOUTLSEL_Get(x)         (((uint16_t) (x) & CMPSS_COMPCTL_CTRIPOUTLSEL_Msk) >> CMPSS_COMPCTL_CTRIPOUTLSEL_Pos)                 /*!< CTRIPOUTLSEL Get Value            */

#define CMPSS_COMPCTL_CTRIPLSEL_Pos               (10U)                                                                                                 /*!< CTRIPLSEL    Position  10         */
#define CMPSS_COMPCTL_CTRIPLSEL_Msk               (0x3U << CMPSS_COMPCTL_CTRIPLSEL_Pos)                                                                 /*!< CTRIPLSEL    Mask      0x00000C00 */
#define CMPSS_COMPCTL_CTRIPLSEL_Set(x)            (((uint16_t) (x) << CMPSS_COMPCTL_CTRIPLSEL_Pos) & CMPSS_COMPCTL_CTRIPLSEL_Msk)                       /*!< CTRIPLSEL    Set Value            */
#define CMPSS_COMPCTL_CTRIPLSEL_Get(x)            (((uint16_t) (x) & CMPSS_COMPCTL_CTRIPLSEL_Msk) >> CMPSS_COMPCTL_CTRIPLSEL_Pos)                       /*!< CTRIPLSEL    Get Value            */

#define CMPSS_COMPCTL_COMPLINV_Pos                (9U)                                                                                                  /*!< COMPLINV     Position  9          */
#define CMPSS_COMPCTL_COMPLINV_Msk                (0x1U << CMPSS_COMPCTL_COMPLINV_Pos)                                                                  /*!< COMPLINV     Mask      0x00000200 */
#define CMPSS_COMPCTL_COMPLINV_Set(x)             (((uint16_t) (x) << CMPSS_COMPCTL_COMPLINV_Pos) & CMPSS_COMPCTL_COMPLINV_Msk)                         /*!< COMPLINV     Set Value            */
#define CMPSS_COMPCTL_COMPLINV_Get(x)             (((uint16_t) (x) & CMPSS_COMPCTL_COMPLINV_Msk) >> CMPSS_COMPCTL_COMPLINV_Pos)                         /*!< COMPLINV     Get Value            */

#define CMPSS_COMPCTL_COMPLSOURCE_Pos             (8U)                                                                                                  /*!< COMPLSOURCE  Position  8          */
#define CMPSS_COMPCTL_COMPLSOURCE_Msk             (0x1U << CMPSS_COMPCTL_COMPLSOURCE_Pos)                                                               /*!< COMPLSOURCE  Mask      0x00000100 */
#define CMPSS_COMPCTL_COMPLSOURCE_Set(x)          (((uint16_t) (x) << CMPSS_COMPCTL_COMPLSOURCE_Pos) & CMPSS_COMPCTL_COMPLSOURCE_Msk)                   /*!< COMPLSOURCE  Set Value            */
#define CMPSS_COMPCTL_COMPLSOURCE_Get(x)          (((uint16_t) (x) & CMPSS_COMPCTL_COMPLSOURCE_Msk) >> CMPSS_COMPCTL_COMPLSOURCE_Pos)                   /*!< COMPLSOURCE  Get Value            */

#define CMPSS_COMPCTL_BLANKINV_Pos                (7U)                                                                                                  /*!< BLANKINV     Position  7          */
#define CMPSS_COMPCTL_BLANKINV_Msk                (0x1U << CMPSS_COMPCTL_BLANKINV_Pos)                                                                  /*!< BLANKINV     Mask      0x00000080 */
#define CMPSS_COMPCTL_BLANKINV_Set(x)             (((uint16_t) (x) << CMPSS_COMPCTL_BLANKINV_Pos) & CMPSS_COMPCTL_BLANKINV_Msk)                         /*!< BLANKINV     Set Value            */
#define CMPSS_COMPCTL_BLANKINV_Get(x)             (((uint16_t) (x) & CMPSS_COMPCTL_BLANKINV_Msk) >> CMPSS_COMPCTL_BLANKINV_Pos)                         /*!< BLANKINV     Get Value            */

#define CMPSS_COMPCTL_ASYNCHEN_Pos                (6U)                                                                                                  /*!< ASYNCHEN     Position  6          */
#define CMPSS_COMPCTL_ASYNCHEN_Msk                (0x1U << CMPSS_COMPCTL_ASYNCHEN_Pos)                                                                  /*!< ASYNCHEN     Mask      0x00000040 */
#define CMPSS_COMPCTL_ASYNCHEN_Set(x)             (((uint16_t) (x) << CMPSS_COMPCTL_ASYNCHEN_Pos) & CMPSS_COMPCTL_ASYNCHEN_Msk)                         /*!< ASYNCHEN     Set Value            */
#define CMPSS_COMPCTL_ASYNCHEN_Get(x)             (((uint16_t) (x) & CMPSS_COMPCTL_ASYNCHEN_Msk) >> CMPSS_COMPCTL_ASYNCHEN_Pos)                         /*!< ASYNCHEN     Get Value            */

#define CMPSS_COMPCTL_CTRIPOUTHSEL_Pos            (4U)                                                                                                  /*!< CTRIPOUTHSEL Position  4          */
#define CMPSS_COMPCTL_CTRIPOUTHSEL_Msk            (0x3U << CMPSS_COMPCTL_CTRIPOUTHSEL_Pos)                                                              /*!< CTRIPOUTHSEL Mask      0x00000030 */
#define CMPSS_COMPCTL_CTRIPOUTHSEL_Set(x)         (((uint16_t) (x) << CMPSS_COMPCTL_CTRIPOUTHSEL_Pos) & CMPSS_COMPCTL_CTRIPOUTHSEL_Msk)                 /*!< CTRIPOUTHSEL Set Value            */
#define CMPSS_COMPCTL_CTRIPOUTHSEL_Get(x)         (((uint16_t) (x) & CMPSS_COMPCTL_CTRIPOUTHSEL_Msk) >> CMPSS_COMPCTL_CTRIPOUTHSEL_Pos)                 /*!< CTRIPOUTHSEL Get Value            */

#define CMPSS_COMPCTL_CTRIPHSEL_Pos               (2U)                                                                                                  /*!< CTRIPHSEL    Position  2          */
#define CMPSS_COMPCTL_CTRIPHSEL_Msk               (0x3U << CMPSS_COMPCTL_CTRIPHSEL_Pos)                                                                 /*!< CTRIPHSEL    Mask      0x0000000C */
#define CMPSS_COMPCTL_CTRIPHSEL_Set(x)            (((uint16_t) (x) << CMPSS_COMPCTL_CTRIPHSEL_Pos) & CMPSS_COMPCTL_CTRIPHSEL_Msk)                       /*!< CTRIPHSEL    Set Value            */
#define CMPSS_COMPCTL_CTRIPHSEL_Get(x)            (((uint16_t) (x) & CMPSS_COMPCTL_CTRIPHSEL_Msk) >> CMPSS_COMPCTL_CTRIPHSEL_Pos)                       /*!< CTRIPHSEL    Get Value            */

#define CMPSS_COMPCTL_COMPHINV_Pos                (1U)                                                                                                  /*!< COMPHINV     Position  1          */
#define CMPSS_COMPCTL_COMPHINV_Msk                (0x1U << CMPSS_COMPCTL_COMPHINV_Pos)                                                                  /*!< COMPHINV     Mask      0x00000002 */
#define CMPSS_COMPCTL_COMPHINV_Set(x)             (((uint16_t) (x) << CMPSS_COMPCTL_COMPHINV_Pos) & CMPSS_COMPCTL_COMPHINV_Msk)                         /*!< COMPHINV     Set Value            */
#define CMPSS_COMPCTL_COMPHINV_Get(x)             (((uint16_t) (x) & CMPSS_COMPCTL_COMPHINV_Msk) >> CMPSS_COMPCTL_COMPHINV_Pos)                         /*!< COMPHINV     Get Value            */

#define CMPSS_COMPCTL_COMPHSOURCE_Pos             (0U)                                                                                                  /*!< COMPHSOURCE  Position  0          */
#define CMPSS_COMPCTL_COMPHSOURCE_Msk             (0x1U << CMPSS_COMPCTL_COMPHSOURCE_Pos)                                                               /*!< COMPHSOURCE  Mask      0x00000001 */
#define CMPSS_COMPCTL_COMPHSOURCE_Set(x)          (((uint16_t) (x) << CMPSS_COMPCTL_COMPHSOURCE_Pos) & CMPSS_COMPCTL_COMPHSOURCE_Msk)                   /*!< COMPHSOURCE  Set Value            */
#define CMPSS_COMPCTL_COMPHSOURCE_Get(x)          (((uint16_t) (x) & CMPSS_COMPCTL_COMPHSOURCE_Msk) >> CMPSS_COMPCTL_COMPHSOURCE_Pos)                   /*!< COMPHSOURCE  Get Value            */

/* COMPHYSCTL bitfield */
#define CMPSS_COMPHYSCTL_COMPHYS_Pos              (0U)                                                                                                  /*!< COMPHYS      Position  0          */
#define CMPSS_COMPHYSCTL_COMPHYS_Msk              (0xfU << CMPSS_COMPHYSCTL_COMPHYS_Pos)                                                                /*!< COMPHYS      Mask      0x0000000F */
#define CMPSS_COMPHYSCTL_COMPHYS_Set(x)           (((uint16_t) (x) << CMPSS_COMPHYSCTL_COMPHYS_Pos) & CMPSS_COMPHYSCTL_COMPHYS_Msk)                     /*!< COMPHYS      Set Value            */
#define CMPSS_COMPHYSCTL_COMPHYS_Get(x)           (((uint16_t) (x) & CMPSS_COMPHYSCTL_COMPHYS_Msk) >> CMPSS_COMPHYSCTL_COMPHYS_Pos)                     /*!< COMPHYS      Get Value            */

/* COMPSTS bitfield */
#define CMPSS_COMPSTS_COMPLLATCH_Pos              (9U)                                                                                                  /*!< COMPLLATCH   Position  9          */
#define CMPSS_COMPSTS_COMPLLATCH_Msk              (0x1U << CMPSS_COMPSTS_COMPLLATCH_Pos)                                                                /*!< COMPLLATCH   Mask      0x00000200 */
#define CMPSS_COMPSTS_COMPLLATCH_Set(x)           (((uint16_t) (x) << CMPSS_COMPSTS_COMPLLATCH_Pos) & CMPSS_COMPSTS_COMPLLATCH_Msk)                     /*!< COMPLLATCH   Set Value            */
#define CMPSS_COMPSTS_COMPLLATCH_Get(x)           (((uint16_t) (x) & CMPSS_COMPSTS_COMPLLATCH_Msk) >> CMPSS_COMPSTS_COMPLLATCH_Pos)                     /*!< COMPLLATCH   Get Value            */

#define CMPSS_COMPSTS_COMPLSTS_Pos                (8U)                                                                                                  /*!< COMPLSTS     Position  8          */
#define CMPSS_COMPSTS_COMPLSTS_Msk                (0x1U << CMPSS_COMPSTS_COMPLSTS_Pos)                                                                  /*!< COMPLSTS     Mask      0x00000100 */
#define CMPSS_COMPSTS_COMPLSTS_Set(x)             (((uint16_t) (x) << CMPSS_COMPSTS_COMPLSTS_Pos) & CMPSS_COMPSTS_COMPLSTS_Msk)                         /*!< COMPLSTS     Set Value            */
#define CMPSS_COMPSTS_COMPLSTS_Get(x)             (((uint16_t) (x) & CMPSS_COMPSTS_COMPLSTS_Msk) >> CMPSS_COMPSTS_COMPLSTS_Pos)                         /*!< COMPLSTS     Get Value            */

#define CMPSS_COMPSTS_COMPHLATCH_Pos              (1U)                                                                                                  /*!< COMPHLATCH   Position  1          */
#define CMPSS_COMPSTS_COMPHLATCH_Msk              (0x1U << CMPSS_COMPSTS_COMPHLATCH_Pos)                                                                /*!< COMPHLATCH   Mask      0x00000002 */
#define CMPSS_COMPSTS_COMPHLATCH_Set(x)           (((uint16_t) (x) << CMPSS_COMPSTS_COMPHLATCH_Pos) & CMPSS_COMPSTS_COMPHLATCH_Msk)                     /*!< COMPHLATCH   Set Value            */
#define CMPSS_COMPSTS_COMPHLATCH_Get(x)           (((uint16_t) (x) & CMPSS_COMPSTS_COMPHLATCH_Msk) >> CMPSS_COMPSTS_COMPHLATCH_Pos)                     /*!< COMPHLATCH   Get Value            */

#define CMPSS_COMPSTS_COMPHSTS_Pos                (0U)                                                                                                  /*!< COMPHSTS     Position  0          */
#define CMPSS_COMPSTS_COMPHSTS_Msk                (0x1U << CMPSS_COMPSTS_COMPHSTS_Pos)                                                                  /*!< COMPHSTS     Mask      0x00000001 */
#define CMPSS_COMPSTS_COMPHSTS_Set(x)             (((uint16_t) (x) << CMPSS_COMPSTS_COMPHSTS_Pos) & CMPSS_COMPSTS_COMPHSTS_Msk)                         /*!< COMPHSTS     Set Value            */
#define CMPSS_COMPSTS_COMPHSTS_Get(x)             (((uint16_t) (x) & CMPSS_COMPSTS_COMPHSTS_Msk) >> CMPSS_COMPSTS_COMPHSTS_Pos)                         /*!< COMPHSTS     Get Value            */

/* COMPSTSCLR bitfield */
#define CMPSS_COMPSTSCLR_LSYNCCLREN_Pos           (10U)                                                                                                 /*!< LSYNCCLREN   Position  10         */
#define CMPSS_COMPSTSCLR_LSYNCCLREN_Msk           (0x1U << CMPSS_COMPSTSCLR_LSYNCCLREN_Pos)                                                             /*!< LSYNCCLREN   Mask      0x00000400 */
#define CMPSS_COMPSTSCLR_LSYNCCLREN_Set(x)        (((uint16_t) (x) << CMPSS_COMPSTSCLR_LSYNCCLREN_Pos) & CMPSS_COMPSTSCLR_LSYNCCLREN_Msk)               /*!< LSYNCCLREN   Set Value            */
#define CMPSS_COMPSTSCLR_LSYNCCLREN_Get(x)        (((uint16_t) (x) & CMPSS_COMPSTSCLR_LSYNCCLREN_Msk) >> CMPSS_COMPSTSCLR_LSYNCCLREN_Pos)               /*!< LSYNCCLREN   Get Value            */

#define CMPSS_COMPSTSCLR_LLATCHCLR_Pos            (9U)                                                                                                  /*!< LLATCHCLR    Position  9          */
#define CMPSS_COMPSTSCLR_LLATCHCLR_Msk            (0x1U << CMPSS_COMPSTSCLR_LLATCHCLR_Pos)                                                              /*!< LLATCHCLR    Mask      0x00000200 */
#define CMPSS_COMPSTSCLR_LLATCHCLR_Set(x)         (((uint16_t) (x) << CMPSS_COMPSTSCLR_LLATCHCLR_Pos) & CMPSS_COMPSTSCLR_LLATCHCLR_Msk)                 /*!< LLATCHCLR    Set Value            */
#define CMPSS_COMPSTSCLR_LLATCHCLR_Get(x)         (((uint16_t) (x) & CMPSS_COMPSTSCLR_LLATCHCLR_Msk) >> CMPSS_COMPSTSCLR_LLATCHCLR_Pos)                 /*!< LLATCHCLR    Get Value            */

#define CMPSS_COMPSTSCLR_HSYNCCLREN_Pos           (2U)                                                                                                  /*!< HSYNCCLREN   Position  2          */
#define CMPSS_COMPSTSCLR_HSYNCCLREN_Msk           (0x1U << CMPSS_COMPSTSCLR_HSYNCCLREN_Pos)                                                             /*!< HSYNCCLREN   Mask      0x00000004 */
#define CMPSS_COMPSTSCLR_HSYNCCLREN_Set(x)        (((uint16_t) (x) << CMPSS_COMPSTSCLR_HSYNCCLREN_Pos) & CMPSS_COMPSTSCLR_HSYNCCLREN_Msk)               /*!< HSYNCCLREN   Set Value            */
#define CMPSS_COMPSTSCLR_HSYNCCLREN_Get(x)        (((uint16_t) (x) & CMPSS_COMPSTSCLR_HSYNCCLREN_Msk) >> CMPSS_COMPSTSCLR_HSYNCCLREN_Pos)               /*!< HSYNCCLREN   Get Value            */

#define CMPSS_COMPSTSCLR_HLATCHCLR_Pos            (1U)                                                                                                  /*!< HLATCHCLR    Position  1          */
#define CMPSS_COMPSTSCLR_HLATCHCLR_Msk            (0x1U << CMPSS_COMPSTSCLR_HLATCHCLR_Pos)                                                              /*!< HLATCHCLR    Mask      0x00000002 */
#define CMPSS_COMPSTSCLR_HLATCHCLR_Set(x)         (((uint16_t) (x) << CMPSS_COMPSTSCLR_HLATCHCLR_Pos) & CMPSS_COMPSTSCLR_HLATCHCLR_Msk)                 /*!< HLATCHCLR    Set Value            */
#define CMPSS_COMPSTSCLR_HLATCHCLR_Get(x)         (((uint16_t) (x) & CMPSS_COMPSTSCLR_HLATCHCLR_Msk) >> CMPSS_COMPSTSCLR_HLATCHCLR_Pos)                 /*!< HLATCHCLR    Get Value            */

/* COMPDACCTL bitfield */
#define CMPSS_COMPDACCTL_FREESOFT_Pos             (14U)                                                                                                 /*!< FREESOFT     Position  14         */
#define CMPSS_COMPDACCTL_FREESOFT_Msk             (0x3U << CMPSS_COMPDACCTL_FREESOFT_Pos)                                                               /*!< FREESOFT     Mask      0x0000C000 */
#define CMPSS_COMPDACCTL_FREESOFT_Set(x)          (((uint32_t) (x) << CMPSS_COMPDACCTL_FREESOFT_Pos) & CMPSS_COMPDACCTL_FREESOFT_Msk)                   /*!< FREESOFT     Set Value            */
#define CMPSS_COMPDACCTL_FREESOFT_Get(x)          (((uint32_t) (x) & CMPSS_COMPDACCTL_FREESOFT_Msk) >> CMPSS_COMPDACCTL_FREESOFT_Pos)                   /*!< FREESOFT     Get Value            */

#define CMPSS_COMPDACCTL_PRESCALE_Pos             (13U)                                                                                                 /*!< PRESCALE     Position  13         */
#define CMPSS_COMPDACCTL_PRESCALE_Msk             (0x1U << CMPSS_COMPDACCTL_PRESCALE_Pos)                                                               /*!< PRESCALE     Mask      0x00002000 */
#define CMPSS_COMPDACCTL_PRESCALE_Set(x)          (((uint32_t) (x) << CMPSS_COMPDACCTL_PRESCALE_Pos) & CMPSS_COMPDACCTL_PRESCALE_Msk)                   /*!< PRESCALE     Set Value            */
#define CMPSS_COMPDACCTL_PRESCALE_Get(x)          (((uint32_t) (x) & CMPSS_COMPDACCTL_PRESCALE_Msk) >> CMPSS_COMPDACCTL_PRESCALE_Pos)                   /*!< PRESCALE     Get Value            */

#define CMPSS_COMPDACCTL_BLANKEN_Pos              (12U)                                                                                                 /*!< BLANKEN      Position  12         */
#define CMPSS_COMPDACCTL_BLANKEN_Msk              (0x1U << CMPSS_COMPDACCTL_BLANKEN_Pos)                                                                /*!< BLANKEN      Mask      0x00001000 */
#define CMPSS_COMPDACCTL_BLANKEN_Set(x)           (((uint32_t) (x) << CMPSS_COMPDACCTL_BLANKEN_Pos) & CMPSS_COMPDACCTL_BLANKEN_Msk)                     /*!< BLANKEN      Set Value            */
#define CMPSS_COMPDACCTL_BLANKEN_Get(x)           (((uint32_t) (x) & CMPSS_COMPDACCTL_BLANKEN_Msk) >> CMPSS_COMPDACCTL_BLANKEN_Pos)                     /*!< BLANKEN      Get Value            */

#define CMPSS_COMPDACCTL_BLANKSOURCE_Pos          (8U)                                                                                                  /*!< BLANKSOURCE  Position  8          */
#define CMPSS_COMPDACCTL_BLANKSOURCE_Msk          (0xfU << CMPSS_COMPDACCTL_BLANKSOURCE_Pos)                                                            /*!< BLANKSOURCE  Mask      0x00000F00 */
#define CMPSS_COMPDACCTL_BLANKSOURCE_Set(x)       (((uint32_t) (x) << CMPSS_COMPDACCTL_BLANKSOURCE_Pos) & CMPSS_COMPDACCTL_BLANKSOURCE_Msk)             /*!< BLANKSOURCE  Set Value            */
#define CMPSS_COMPDACCTL_BLANKSOURCE_Get(x)       (((uint32_t) (x) & CMPSS_COMPDACCTL_BLANKSOURCE_Msk) >> CMPSS_COMPDACCTL_BLANKSOURCE_Pos)             /*!< BLANKSOURCE  Get Value            */

#define CMPSS_COMPDACCTL_SWLOADSEL_Pos            (7U)                                                                                                  /*!< SWLOADSEL    Position  7          */
#define CMPSS_COMPDACCTL_SWLOADSEL_Msk            (0x1U << CMPSS_COMPDACCTL_SWLOADSEL_Pos)                                                              /*!< SWLOADSEL    Mask      0x00000080 */
#define CMPSS_COMPDACCTL_SWLOADSEL_Set(x)         (((uint32_t) (x) << CMPSS_COMPDACCTL_SWLOADSEL_Pos) & CMPSS_COMPDACCTL_SWLOADSEL_Msk)                 /*!< SWLOADSEL    Set Value            */
#define CMPSS_COMPDACCTL_SWLOADSEL_Get(x)         (((uint32_t) (x) & CMPSS_COMPDACCTL_SWLOADSEL_Msk) >> CMPSS_COMPDACCTL_SWLOADSEL_Pos)                 /*!< SWLOADSEL    Get Value            */

#define CMPSS_COMPDACCTL_RAMPLOADSEL_Pos          (6U)                                                                                                  /*!< RAMPLOADSEL  Position  6          */
#define CMPSS_COMPDACCTL_RAMPLOADSEL_Msk          (0x1U << CMPSS_COMPDACCTL_RAMPLOADSEL_Pos)                                                            /*!< RAMPLOADSEL  Mask      0x00000040 */
#define CMPSS_COMPDACCTL_RAMPLOADSEL_Set(x)       (((uint32_t) (x) << CMPSS_COMPDACCTL_RAMPLOADSEL_Pos) & CMPSS_COMPDACCTL_RAMPLOADSEL_Msk)             /*!< RAMPLOADSEL  Set Value            */
#define CMPSS_COMPDACCTL_RAMPLOADSEL_Get(x)       (((uint32_t) (x) & CMPSS_COMPDACCTL_RAMPLOADSEL_Msk) >> CMPSS_COMPDACCTL_RAMPLOADSEL_Pos)             /*!< RAMPLOADSEL  Get Value            */

#define CMPSS_COMPDACCTL_SELREF_Pos               (5U)                                                                                                  /*!< SELREF       Position  5          */
#define CMPSS_COMPDACCTL_SELREF_Msk               (0x1U << CMPSS_COMPDACCTL_SELREF_Pos)                                                                 /*!< SELREF       Mask      0x00000020 */
#define CMPSS_COMPDACCTL_SELREF_Set(x)            (((uint32_t) (x) << CMPSS_COMPDACCTL_SELREF_Pos) & CMPSS_COMPDACCTL_SELREF_Msk)                       /*!< SELREF       Set Value            */
#define CMPSS_COMPDACCTL_SELREF_Get(x)            (((uint32_t) (x) & CMPSS_COMPDACCTL_SELREF_Msk) >> CMPSS_COMPDACCTL_SELREF_Pos)                       /*!< SELREF       Get Value            */

#define CMPSS_COMPDACCTL_RAMPSOURCE_Pos           (1U)                                                                                                  /*!< RAMPSOURCE   Position  1          */
#define CMPSS_COMPDACCTL_RAMPSOURCE_Msk           (0xfU << CMPSS_COMPDACCTL_RAMPSOURCE_Pos)                                                             /*!< RAMPSOURCE   Mask      0x0000001E */
#define CMPSS_COMPDACCTL_RAMPSOURCE_Set(x)        (((uint32_t) (x) << CMPSS_COMPDACCTL_RAMPSOURCE_Pos) & CMPSS_COMPDACCTL_RAMPSOURCE_Msk)               /*!< RAMPSOURCE   Set Value            */
#define CMPSS_COMPDACCTL_RAMPSOURCE_Get(x)        (((uint32_t) (x) & CMPSS_COMPDACCTL_RAMPSOURCE_Msk) >> CMPSS_COMPDACCTL_RAMPSOURCE_Pos)               /*!< RAMPSOURCE   Get Value            */

#define CMPSS_COMPDACCTL_DACSOURCE_Pos            (0U)                                                                                                  /*!< DACSOURCE    Position  0          */
#define CMPSS_COMPDACCTL_DACSOURCE_Msk            (0x1U << CMPSS_COMPDACCTL_DACSOURCE_Pos)                                                              /*!< DACSOURCE    Mask      0x00000001 */
#define CMPSS_COMPDACCTL_DACSOURCE_Set(x)         (((uint32_t) (x) << CMPSS_COMPDACCTL_DACSOURCE_Pos) & CMPSS_COMPDACCTL_DACSOURCE_Msk)                 /*!< DACSOURCE    Set Value            */
#define CMPSS_COMPDACCTL_DACSOURCE_Get(x)         (((uint32_t) (x) & CMPSS_COMPDACCTL_DACSOURCE_Msk) >> CMPSS_COMPDACCTL_DACSOURCE_Pos)                 /*!< DACSOURCE    Get Value            */

/* DACHVALS bitfield */
#define CMPSS_DACHVALS_DACVAL_Pos                 (0U)                                                                                                  /*!< DACVAL       Position  0          */
#define CMPSS_DACHVALS_DACVAL_Msk                 (0xfffU << CMPSS_DACHVALS_DACVAL_Pos)                                                                 /*!< DACVAL       Mask      0x00000FFF */
#define CMPSS_DACHVALS_DACVAL_Set(x)              (((uint16_t) (x) << CMPSS_DACHVALS_DACVAL_Pos) & CMPSS_DACHVALS_DACVAL_Msk)                           /*!< DACVAL       Set Value            */
#define CMPSS_DACHVALS_DACVAL_Get(x)              (((uint16_t) (x) & CMPSS_DACHVALS_DACVAL_Msk) >> CMPSS_DACHVALS_DACVAL_Pos)                           /*!< DACVAL       Get Value            */

/* DACHVALA bitfield */
#define CMPSS_DACHVALA_DACVAL_Pos                 (0U)                                                                                                  /*!< DACVAL       Position  0          */
#define CMPSS_DACHVALA_DACVAL_Msk                 (0xfffU << CMPSS_DACHVALA_DACVAL_Pos)                                                                 /*!< DACVAL       Mask      0x00000FFF */
#define CMPSS_DACHVALA_DACVAL_Set(x)              (((uint16_t) (x) << CMPSS_DACHVALA_DACVAL_Pos) & CMPSS_DACHVALA_DACVAL_Msk)                           /*!< DACVAL       Set Value            */
#define CMPSS_DACHVALA_DACVAL_Get(x)              (((uint16_t) (x) & CMPSS_DACHVALA_DACVAL_Msk) >> CMPSS_DACHVALA_DACVAL_Pos)                           /*!< DACVAL       Get Value            */

/* RAMPMAXREFA bitfield */
#define CMPSS_RAMPMAXREFA_RAMPMAXREF_Pos          (0U)                                                                                                  /*!< RAMPMAXREF   Position  0          */
#define CMPSS_RAMPMAXREFA_RAMPMAXREF_Msk          (0xffffffU << CMPSS_RAMPMAXREFA_RAMPMAXREF_Pos)                                                       /*!< RAMPMAXREF   Mask      0x00FFFFFF */
#define CMPSS_RAMPMAXREFA_RAMPMAXREF_Set(x)       (((uint32_t) (x) << CMPSS_RAMPMAXREFA_RAMPMAXREF_Pos) & CMPSS_RAMPMAXREFA_RAMPMAXREF_Msk)             /*!< RAMPMAXREF   Set Value            */
#define CMPSS_RAMPMAXREFA_RAMPMAXREF_Get(x)       (((uint32_t) (x) & CMPSS_RAMPMAXREFA_RAMPMAXREF_Msk) >> CMPSS_RAMPMAXREFA_RAMPMAXREF_Pos)             /*!< RAMPMAXREF   Get Value            */

/* RAMPMAXREFS bitfield */
#define CMPSS_RAMPMAXREFS_RAMPMAXREF_Pos          (0U)                                                                                                  /*!< RAMPMAXREF   Position  0          */
#define CMPSS_RAMPMAXREFS_RAMPMAXREF_Msk          (0xffffffU << CMPSS_RAMPMAXREFS_RAMPMAXREF_Pos)                                                       /*!< RAMPMAXREF   Mask      0x00FFFFFF */
#define CMPSS_RAMPMAXREFS_RAMPMAXREF_Set(x)       (((uint32_t) (x) << CMPSS_RAMPMAXREFS_RAMPMAXREF_Pos) & CMPSS_RAMPMAXREFS_RAMPMAXREF_Msk)             /*!< RAMPMAXREF   Set Value            */
#define CMPSS_RAMPMAXREFS_RAMPMAXREF_Get(x)       (((uint32_t) (x) & CMPSS_RAMPMAXREFS_RAMPMAXREF_Msk) >> CMPSS_RAMPMAXREFS_RAMPMAXREF_Pos)             /*!< RAMPMAXREF   Get Value            */

/* RAMPDECVALA bitfield */
#define CMPSS_RAMPDECVALA_RAMPDECVAL_Pos          (0U)                                                                                                  /*!< RAMPDECVAL   Position  0          */
#define CMPSS_RAMPDECVALA_RAMPDECVAL_Msk          (0xffffffU << CMPSS_RAMPDECVALA_RAMPDECVAL_Pos)                                                       /*!< RAMPDECVAL   Mask      0x00FFFFFF */
#define CMPSS_RAMPDECVALA_RAMPDECVAL_Set(x)       (((uint32_t) (x) << CMPSS_RAMPDECVALA_RAMPDECVAL_Pos) & CMPSS_RAMPDECVALA_RAMPDECVAL_Msk)             /*!< RAMPDECVAL   Set Value            */
#define CMPSS_RAMPDECVALA_RAMPDECVAL_Get(x)       (((uint32_t) (x) & CMPSS_RAMPDECVALA_RAMPDECVAL_Msk) >> CMPSS_RAMPDECVALA_RAMPDECVAL_Pos)             /*!< RAMPDECVAL   Get Value            */

/* RAMPDECVALS bitfield */
#define CMPSS_RAMPDECVALS_RAMPDECVAL_Pos          (0U)                                                                                                  /*!< RAMPDECVAL   Position  0          */
#define CMPSS_RAMPDECVALS_RAMPDECVAL_Msk          (0xffffffU << CMPSS_RAMPDECVALS_RAMPDECVAL_Pos)                                                       /*!< RAMPDECVAL   Mask      0x00FFFFFF */
#define CMPSS_RAMPDECVALS_RAMPDECVAL_Set(x)       (((uint32_t) (x) << CMPSS_RAMPDECVALS_RAMPDECVAL_Pos) & CMPSS_RAMPDECVALS_RAMPDECVAL_Msk)             /*!< RAMPDECVAL   Set Value            */
#define CMPSS_RAMPDECVALS_RAMPDECVAL_Get(x)       (((uint32_t) (x) & CMPSS_RAMPDECVALS_RAMPDECVAL_Msk) >> CMPSS_RAMPDECVALS_RAMPDECVAL_Pos)             /*!< RAMPDECVAL   Get Value            */

/* RAMPSTS bitfield */
#define CMPSS_RAMPSTS_RAMPVALUE_Pos               (0U)                                                                                                  /*!< RAMPVALUE    Position  0          */
#define CMPSS_RAMPSTS_RAMPVALUE_Msk               (0xffffffU << CMPSS_RAMPSTS_RAMPVALUE_Pos)                                                            /*!< RAMPVALUE    Mask      0x00FFFFFF */
#define CMPSS_RAMPSTS_RAMPVALUE_Set(x)            (((uint32_t) (x) << CMPSS_RAMPSTS_RAMPVALUE_Pos) & CMPSS_RAMPSTS_RAMPVALUE_Msk)                       /*!< RAMPVALUE    Set Value            */
#define CMPSS_RAMPSTS_RAMPVALUE_Get(x)            (((uint32_t) (x) & CMPSS_RAMPSTS_RAMPVALUE_Msk) >> CMPSS_RAMPSTS_RAMPVALUE_Pos)                       /*!< RAMPVALUE    Get Value            */

/* DACLVALS bitfield */
#define CMPSS_DACLVALS_DACVAL_Pos                 (0U)                                                                                                  /*!< DACVAL       Position  0          */
#define CMPSS_DACLVALS_DACVAL_Msk                 (0xfffU << CMPSS_DACLVALS_DACVAL_Pos)                                                                 /*!< DACVAL       Mask      0x00000FFF */
#define CMPSS_DACLVALS_DACVAL_Set(x)              (((uint16_t) (x) << CMPSS_DACLVALS_DACVAL_Pos) & CMPSS_DACLVALS_DACVAL_Msk)                           /*!< DACVAL       Set Value            */
#define CMPSS_DACLVALS_DACVAL_Get(x)              (((uint16_t) (x) & CMPSS_DACLVALS_DACVAL_Msk) >> CMPSS_DACLVALS_DACVAL_Pos)                           /*!< DACVAL       Get Value            */

/* DACLVALA bitfield */
#define CMPSS_DACLVALA_DACVAL_Pos                 (0U)                                                                                                  /*!< DACVAL       Position  0          */
#define CMPSS_DACLVALA_DACVAL_Msk                 (0xfffU << CMPSS_DACLVALA_DACVAL_Pos)                                                                 /*!< DACVAL       Mask      0x00000FFF */
#define CMPSS_DACLVALA_DACVAL_Set(x)              (((uint16_t) (x) << CMPSS_DACLVALA_DACVAL_Pos) & CMPSS_DACLVALA_DACVAL_Msk)                           /*!< DACVAL       Set Value            */
#define CMPSS_DACLVALA_DACVAL_Get(x)              (((uint16_t) (x) & CMPSS_DACLVALA_DACVAL_Msk) >> CMPSS_DACLVALA_DACVAL_Pos)                           /*!< DACVAL       Get Value            */

/* RAMPDLYA bitfield */
#define CMPSS_RAMPDLYA_DELAY_Pos                  (0U)                                                                                                  /*!< DELAY        Position  0          */
#define CMPSS_RAMPDLYA_DELAY_Msk                  (0x1fffU << CMPSS_RAMPDLYA_DELAY_Pos)                                                                 /*!< DELAY        Mask      0x00001FFF */
#define CMPSS_RAMPDLYA_DELAY_Set(x)               (((uint16_t) (x) << CMPSS_RAMPDLYA_DELAY_Pos) & CMPSS_RAMPDLYA_DELAY_Msk)                             /*!< DELAY        Set Value            */
#define CMPSS_RAMPDLYA_DELAY_Get(x)               (((uint16_t) (x) & CMPSS_RAMPDLYA_DELAY_Msk) >> CMPSS_RAMPDLYA_DELAY_Pos)                             /*!< DELAY        Get Value            */

/* RAMPDLYS bitfield */
#define CMPSS_RAMPDLYS_DELAY_Pos                  (0U)                                                                                                  /*!< DELAY        Position  0          */
#define CMPSS_RAMPDLYS_DELAY_Msk                  (0x1fffU << CMPSS_RAMPDLYS_DELAY_Pos)                                                                 /*!< DELAY        Mask      0x00001FFF */
#define CMPSS_RAMPDLYS_DELAY_Set(x)               (((uint16_t) (x) << CMPSS_RAMPDLYS_DELAY_Pos) & CMPSS_RAMPDLYS_DELAY_Msk)                             /*!< DELAY        Set Value            */
#define CMPSS_RAMPDLYS_DELAY_Get(x)               (((uint16_t) (x) & CMPSS_RAMPDLYS_DELAY_Msk) >> CMPSS_RAMPDLYS_DELAY_Pos)                             /*!< DELAY        Get Value            */

/* CTRIPLFILCTL bitfield */
#define CMPSS_CTRIPLFILCTL_FILINIT_Pos            (15U)                                                                                                 /*!< FILINIT      Position  15         */
#define CMPSS_CTRIPLFILCTL_FILINIT_Msk            (0x1U << CMPSS_CTRIPLFILCTL_FILINIT_Pos)                                                              /*!< FILINIT      Mask      0x00008000 */
#define CMPSS_CTRIPLFILCTL_FILINIT_Set(x)         (((uint16_t) (x) << CMPSS_CTRIPLFILCTL_FILINIT_Pos) & CMPSS_CTRIPLFILCTL_FILINIT_Msk)                 /*!< FILINIT      Set Value            */
#define CMPSS_CTRIPLFILCTL_FILINIT_Get(x)         (((uint16_t) (x) & CMPSS_CTRIPLFILCTL_FILINIT_Msk) >> CMPSS_CTRIPLFILCTL_FILINIT_Pos)                 /*!< FILINIT      Get Value            */

#define CMPSS_CTRIPLFILCTL_THRESH_Pos             (9U)                                                                                                  /*!< THRESH       Position  9          */
#define CMPSS_CTRIPLFILCTL_THRESH_Msk             (0x1fU << CMPSS_CTRIPLFILCTL_THRESH_Pos)                                                              /*!< THRESH       Mask      0x00003E00 */
#define CMPSS_CTRIPLFILCTL_THRESH_Set(x)          (((uint16_t) (x) << CMPSS_CTRIPLFILCTL_THRESH_Pos) & CMPSS_CTRIPLFILCTL_THRESH_Msk)                   /*!< THRESH       Set Value            */
#define CMPSS_CTRIPLFILCTL_THRESH_Get(x)          (((uint16_t) (x) & CMPSS_CTRIPLFILCTL_THRESH_Msk) >> CMPSS_CTRIPLFILCTL_THRESH_Pos)                   /*!< THRESH       Get Value            */

#define CMPSS_CTRIPLFILCTL_SAMPWIN_Pos            (4U)                                                                                                  /*!< SAMPWIN      Position  4          */
#define CMPSS_CTRIPLFILCTL_SAMPWIN_Msk            (0x1fU << CMPSS_CTRIPLFILCTL_SAMPWIN_Pos)                                                             /*!< SAMPWIN      Mask      0x000001F0 */
#define CMPSS_CTRIPLFILCTL_SAMPWIN_Set(x)         (((uint16_t) (x) << CMPSS_CTRIPLFILCTL_SAMPWIN_Pos) & CMPSS_CTRIPLFILCTL_SAMPWIN_Msk)                 /*!< SAMPWIN      Set Value            */
#define CMPSS_CTRIPLFILCTL_SAMPWIN_Get(x)         (((uint16_t) (x) & CMPSS_CTRIPLFILCTL_SAMPWIN_Msk) >> CMPSS_CTRIPLFILCTL_SAMPWIN_Pos)                 /*!< SAMPWIN      Get Value            */

/* CTRIPLFILCLKCTL bitfield */
#define CMPSS_CTRIPLFILCLKCTL_CLKPRESCALE_Pos     (0U)                                                                                                  /*!< CLKPRESCALE  Position  0          */
#define CMPSS_CTRIPLFILCLKCTL_CLKPRESCALE_Msk     (0x3ffU << CMPSS_CTRIPLFILCLKCTL_CLKPRESCALE_Pos)                                                     /*!< CLKPRESCALE  Mask      0x000003FF */
#define CMPSS_CTRIPLFILCLKCTL_CLKPRESCALE_Set(x)  (((uint16_t) (x) << CMPSS_CTRIPLFILCLKCTL_CLKPRESCALE_Pos) & CMPSS_CTRIPLFILCLKCTL_CLKPRESCALE_Msk)   /*!< CLKPRESCALE  Set Value            */
#define CMPSS_CTRIPLFILCLKCTL_CLKPRESCALE_Get(x)  (((uint16_t) (x) & CMPSS_CTRIPLFILCLKCTL_CLKPRESCALE_Msk) >> CMPSS_CTRIPLFILCLKCTL_CLKPRESCALE_Pos)   /*!< CLKPRESCALE  Get Value            */

/* CTRIPHFILCTL bitfield */
#define CMPSS_CTRIPHFILCTL_FILINIT_Pos            (15U)                                                                                                 /*!< FILINIT      Position  15         */
#define CMPSS_CTRIPHFILCTL_FILINIT_Msk            (0x1U << CMPSS_CTRIPHFILCTL_FILINIT_Pos)                                                              /*!< FILINIT      Mask      0x00008000 */
#define CMPSS_CTRIPHFILCTL_FILINIT_Set(x)         (((uint16_t) (x) << CMPSS_CTRIPHFILCTL_FILINIT_Pos) & CMPSS_CTRIPHFILCTL_FILINIT_Msk)                 /*!< FILINIT      Set Value            */
#define CMPSS_CTRIPHFILCTL_FILINIT_Get(x)         (((uint16_t) (x) & CMPSS_CTRIPHFILCTL_FILINIT_Msk) >> CMPSS_CTRIPHFILCTL_FILINIT_Pos)                 /*!< FILINIT      Get Value            */

#define CMPSS_CTRIPHFILCTL_THRESH_Pos             (9U)                                                                                                  /*!< THRESH       Position  9          */
#define CMPSS_CTRIPHFILCTL_THRESH_Msk             (0x1fU << CMPSS_CTRIPHFILCTL_THRESH_Pos)                                                              /*!< THRESH       Mask      0x00003E00 */
#define CMPSS_CTRIPHFILCTL_THRESH_Set(x)          (((uint16_t) (x) << CMPSS_CTRIPHFILCTL_THRESH_Pos) & CMPSS_CTRIPHFILCTL_THRESH_Msk)                   /*!< THRESH       Set Value            */
#define CMPSS_CTRIPHFILCTL_THRESH_Get(x)          (((uint16_t) (x) & CMPSS_CTRIPHFILCTL_THRESH_Msk) >> CMPSS_CTRIPHFILCTL_THRESH_Pos)                   /*!< THRESH       Get Value            */

#define CMPSS_CTRIPHFILCTL_SAMPWIN_Pos            (4U)                                                                                                  /*!< SAMPWIN      Position  4          */
#define CMPSS_CTRIPHFILCTL_SAMPWIN_Msk            (0x1fU << CMPSS_CTRIPHFILCTL_SAMPWIN_Pos)                                                             /*!< SAMPWIN      Mask      0x000001F0 */
#define CMPSS_CTRIPHFILCTL_SAMPWIN_Set(x)         (((uint16_t) (x) << CMPSS_CTRIPHFILCTL_SAMPWIN_Pos) & CMPSS_CTRIPHFILCTL_SAMPWIN_Msk)                 /*!< SAMPWIN      Set Value            */
#define CMPSS_CTRIPHFILCTL_SAMPWIN_Get(x)         (((uint16_t) (x) & CMPSS_CTRIPHFILCTL_SAMPWIN_Msk) >> CMPSS_CTRIPHFILCTL_SAMPWIN_Pos)                 /*!< SAMPWIN      Get Value            */

/* CTRIPHFILCLKCTL bitfield */
#define CMPSS_CTRIPHFILCLKCTL_CLKPRESCALE_Pos     (0U)                                                                                                  /*!< CLKPRESCALE  Position  0          */
#define CMPSS_CTRIPHFILCLKCTL_CLKPRESCALE_Msk     (0x3ffU << CMPSS_CTRIPHFILCLKCTL_CLKPRESCALE_Pos)                                                     /*!< CLKPRESCALE  Mask      0x000003FF */
#define CMPSS_CTRIPHFILCLKCTL_CLKPRESCALE_Set(x)  (((uint16_t) (x) << CMPSS_CTRIPHFILCLKCTL_CLKPRESCALE_Pos) & CMPSS_CTRIPHFILCLKCTL_CLKPRESCALE_Msk)   /*!< CLKPRESCALE  Set Value            */
#define CMPSS_CTRIPHFILCLKCTL_CLKPRESCALE_Get(x)  (((uint16_t) (x) & CMPSS_CTRIPHFILCLKCTL_CLKPRESCALE_Msk) >> CMPSS_CTRIPHFILCLKCTL_CLKPRESCALE_Pos)   /*!< CLKPRESCALE  Get Value            */

/* COMPLOCK bitfield */
#define CMPSS_COMPLOCK_CTRIP_Pos                  (3U)                                                                                                  /*!< CTRIP        Position  3          */
#define CMPSS_COMPLOCK_CTRIP_Msk                  (0x1U << CMPSS_COMPLOCK_CTRIP_Pos)                                                                    /*!< CTRIP        Mask      0x00000008 */
#define CMPSS_COMPLOCK_CTRIP_Set(x)               (((uint32_t) (x) << CMPSS_COMPLOCK_CTRIP_Pos) & CMPSS_COMPLOCK_CTRIP_Msk)                             /*!< CTRIP        Set Value            */
#define CMPSS_COMPLOCK_CTRIP_Get(x)               (((uint32_t) (x) & CMPSS_COMPLOCK_CTRIP_Msk) >> CMPSS_COMPLOCK_CTRIP_Pos)                             /*!< CTRIP        Get Value            */

#define CMPSS_COMPLOCK_DACCTL_Pos                 (2U)                                                                                                  /*!< DACCTL       Position  2          */
#define CMPSS_COMPLOCK_DACCTL_Msk                 (0x1U << CMPSS_COMPLOCK_DACCTL_Pos)                                                                   /*!< DACCTL       Mask      0x00000004 */
#define CMPSS_COMPLOCK_DACCTL_Set(x)              (((uint32_t) (x) << CMPSS_COMPLOCK_DACCTL_Pos) & CMPSS_COMPLOCK_DACCTL_Msk)                           /*!< DACCTL       Set Value            */
#define CMPSS_COMPLOCK_DACCTL_Get(x)              (((uint32_t) (x) & CMPSS_COMPLOCK_DACCTL_Msk) >> CMPSS_COMPLOCK_DACCTL_Pos)                           /*!< DACCTL       Get Value            */

#define CMPSS_COMPLOCK_COMPHYSCTL_Pos             (1U)                                                                                                  /*!< COMPHYSCTL   Position  1          */
#define CMPSS_COMPLOCK_COMPHYSCTL_Msk             (0x1U << CMPSS_COMPLOCK_COMPHYSCTL_Pos)                                                               /*!< COMPHYSCTL   Mask      0x00000002 */
#define CMPSS_COMPLOCK_COMPHYSCTL_Set(x)          (((uint32_t) (x) << CMPSS_COMPLOCK_COMPHYSCTL_Pos) & CMPSS_COMPLOCK_COMPHYSCTL_Msk)                   /*!< COMPHYSCTL   Set Value            */
#define CMPSS_COMPLOCK_COMPHYSCTL_Get(x)          (((uint32_t) (x) & CMPSS_COMPLOCK_COMPHYSCTL_Msk) >> CMPSS_COMPLOCK_COMPHYSCTL_Pos)                   /*!< COMPHYSCTL   Get Value            */

#define CMPSS_COMPLOCK_COMPCTL_Pos                (0U)                                                                                                  /*!< COMPCTL      Position  0          */
#define CMPSS_COMPLOCK_COMPCTL_Msk                (0x1U << CMPSS_COMPLOCK_COMPCTL_Pos)                                                                  /*!< COMPCTL      Mask      0x00000001 */
#define CMPSS_COMPLOCK_COMPCTL_Set(x)             (((uint32_t) (x) << CMPSS_COMPLOCK_COMPCTL_Pos) & CMPSS_COMPLOCK_COMPCTL_Msk)                         /*!< COMPCTL      Set Value            */
#define CMPSS_COMPLOCK_COMPCTL_Get(x)             (((uint32_t) (x) & CMPSS_COMPLOCK_COMPCTL_Msk) >> CMPSS_COMPLOCK_COMPCTL_Pos)                         /*!< COMPCTL      Get Value            */

/* CMPSSTRIM bitfield */
#define CMPSS_CMPSSTRIM_LOFFTRIM_Pos              (16U)                                                                                                 /*!< LOFFTRIM     Position  16         */
#define CMPSS_CMPSSTRIM_LOFFTRIM_Msk              (0xffU << CMPSS_CMPSSTRIM_LOFFTRIM_Pos)                                                               /*!< LOFFTRIM     Mask      0x00FF0000 */
#define CMPSS_CMPSSTRIM_LOFFTRIM_Set(x)           (((uint32_t) (x) << CMPSS_CMPSSTRIM_LOFFTRIM_Pos) & CMPSS_CMPSSTRIM_LOFFTRIM_Msk)                     /*!< LOFFTRIM     Set Value            */
#define CMPSS_CMPSSTRIM_LOFFTRIM_Get(x)           (((uint32_t) (x) & CMPSS_CMPSSTRIM_LOFFTRIM_Msk) >> CMPSS_CMPSSTRIM_LOFFTRIM_Pos)                     /*!< LOFFTRIM     Get Value            */

#define CMPSS_CMPSSTRIM_HOFFTRIM_Pos              (0U)                                                                                                  /*!< HOFFTRIM     Position  0          */
#define CMPSS_CMPSSTRIM_HOFFTRIM_Msk              (0xffU << CMPSS_CMPSSTRIM_HOFFTRIM_Pos)                                                               /*!< HOFFTRIM     Mask      0x000000FF */
#define CMPSS_CMPSSTRIM_HOFFTRIM_Set(x)           (((uint32_t) (x) << CMPSS_CMPSSTRIM_HOFFTRIM_Pos) & CMPSS_CMPSSTRIM_HOFFTRIM_Msk)                     /*!< HOFFTRIM     Set Value            */
#define CMPSS_CMPSSTRIM_HOFFTRIM_Get(x)           (((uint32_t) (x) & CMPSS_CMPSSTRIM_HOFFTRIM_Msk) >> CMPSS_CMPSSTRIM_HOFFTRIM_Pos)                     /*!< HOFFTRIM     Get Value            */

/*!
 * @}
 */

/* clang-format on */

/*!
 * @}
 */ /* end of HS32F7D377_CMPSS_REGISTER */

#endif /* HS32F7D377_CMPSS_H */
