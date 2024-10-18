;
; Copyright 2024 Watech Electronics
; All rights reserved.
;
; SPDX-License-Identifier: BSD-3-Clause
;

; Vector Table Mapped to Address 0 at Reset

                MODULE  ?cstartup

                ;; Forward declaration of sections.
                SECTION CSTACK:DATA:NOROOT(3)

                SECTION .intvec:CODE:NOROOT(2)

                EXTERN  __iar_program_start
                EXTERN  SystemInit
                PUBLIC   __vector_table
                PUBLIC   __vector_table_0x1c
                PUBLIC   __Vectors
                PUBLIC   __Vectors_End
                PUBLIC   __Vectors_Size

                DATA

__vector_table
                DCD      sfe(CSTACK)                         ;     Initial Stack Pointer
                DCD      Reset_Handler                       ;     Reset Handler
                DCD      NMI_Handler                         ; -14 NMI Handler
                DCD      HardFault_Handler                   ; -13 Hard Fault Handler
                DCD      MemManage_Handler                   ; -12 MPU Fault Handler
                DCD      BusFault_Handler                    ; -11 Bus Fault Handler
                DCD      UsageFault_Handler                  ; -10 Usage Fault Handler
__vector_table_0x1c
                DCD      0                                   ;     Reserved
                DCD      0                                   ;     Reserved
                DCD      0                                   ;     Reserved
                DCD      0                                   ;     Reserved
                DCD      SVC_Handler                         ;  -5 SVC Handler
                DCD      DebugMon_Handler                    ;  -4 Debug Monitor Handler
                DCD      0                                   ;     Reserved
                DCD      PendSV_Handler                      ;  -2 PendSV Handler
                DCD      SysTick_Handler                     ;  -1 SysTick Handler

                ; Interrupts
                DCD      WDT_Handler                         ;   0 WDT
                DCD      CPUTIMER0_Handler                   ;   1 CPU TIMER0
                DCD      CPUTIMER1_Handler                   ;   2 CPU TIMER1
                DCD      CPUTIMER2_Handler                   ;   3 CPU TIMER2
                DCD      DWTIMER_CH0_Handler                 ;   4 DWTIMER Channel0
                DCD      DWTIMER_CH1_Handler                 ;   5 DWTIMER Channel1
                DCD      DWTIMER_CH2_Handler                 ;   6 DWTIMER Channel2
                DCD      0                                   ;   7 RESERVED
                DCD      IPC_INT0_Handler                    ;   8 IPC INT0
                DCD      IPC_INT1_Handler                    ;   9 IPC INT1
                DCD      IPC_INT2_Handler                    ;  10 IPC INT2
                DCD      IPC_INT3_Handler                    ;  11 IPC INT3
                DCD      ADCA_EVT_Handler                    ;  12 ADCA Event
                DCD      ADCB_EVT_Handler                    ;  13 ADCB Event
                DCD      ADCC_EVT_Handler                    ;  14 ADCC Event
                DCD      ADCD_EVT_Handler                    ;  15 ADCD Event
                DCD      ADCA_INT1_Handler                   ;  16 ADCA INT1
                DCD      ADCA_INT2_Handler                   ;  17 ADCA INT2
                DCD      ADCA_INT3_Handler                   ;  18 ADCA INT3
                DCD      ADCA_INT4_Handler                   ;  19 ADCA INT4
                DCD      ADCB_INT1_Handler                   ;  20 ADCB INT1
                DCD      ADCB_INT2_Handler                   ;  21 ADCB INT2
                DCD      ADCB_INT3_Handler                   ;  22 ADCB INT3
                DCD      ADCB_INT4_Handler                   ;  23 ADCB INT4
                DCD      ADCC_INT1_Handler                   ;  24 ADCC INT1
                DCD      ADCC_INT2_Handler                   ;  25 ADCC INT2
                DCD      ADCC_INT3_Handler                   ;  26 ADCC INT3
                DCD      ADCC_INT4_Handler                   ;  27 ADCC INT4
                DCD      ADCD_INT1_Handler                   ;  28 ADCD INT1
                DCD      ADCD_INT2_Handler                   ;  29 ADCD INT2
                DCD      ADCD_INT3_Handler                   ;  30 ADCD INT3
                DCD      ADCD_INT4_Handler                   ;  31 ADCD INT4
                DCD      XINT1_Handler                       ;  32 XINT1
                DCD      XINT2_Handler                       ;  33 XINT2
                DCD      XINT3_Handler                       ;  34 XINT3
                DCD      XINT4_Handler                       ;  35 XINT4
                DCD      XINT5_Handler                       ;  36 XINT5
                DCD      0                                   ;  37 RESERVED
                DCD      0                                   ;  38 RESERVED
                DCD      EPWM_HRCAL_Handler                  ;  39 EPWM High-Resolution Calibration
                DCD      EPWM1_TZ_Handler                    ;  40 EPWM1 Trip-Zone
                DCD      EPWM2_TZ_Handler                    ;  41 EPWM2 Trip-Zone
                DCD      EPWM3_TZ_Handler                    ;  42 EPWM3 Trip-Zone
                DCD      EPWM4_TZ_Handler                    ;  43 EPWM4 Trip-Zone
                DCD      EPWM5_TZ_Handler                    ;  44 EPWM5 Trip-Zone
                DCD      EPWM6_TZ_Handler                    ;  45 EPWM6 Trip-Zone
                DCD      EPWM7_TZ_Handler                    ;  46 EPWM7 Trip-Zone
                DCD      EPWM8_TZ_Handler                    ;  47 EPWM8 Trip-Zone
                DCD      EPWM9_TZ_Handler                    ;  48 EPWM9 Trip-Zone
                DCD      EPWM10_TZ_Handler                   ;  49 EPWM10 Trip-Zone
                DCD      EPWM11_TZ_Handler                   ;  50 EPWM11 Trip-Zone
                DCD      EPWM12_TZ_Handler                   ;  51 EPWM12 Trip-Zone
                DCD      0                                   ;  52 RESERVED
                DCD      0                                   ;  53 RESERVED
                DCD      0                                   ;  54 RESERVED
                DCD      0                                   ;  55 RESERVED
                DCD      EPWM1_Handler                       ;  56 EPWM1
                DCD      EPWM2_Handler                       ;  57 EPWM2
                DCD      EPWM3_Handler                       ;  58 EPWM3
                DCD      EPWM4_Handler                       ;  59 EPWM4
                DCD      EPWM5_Handler                       ;  60 EPWM5
                DCD      EPWM6_Handler                       ;  61 EPWM6
                DCD      EPWM7_Handler                       ;  62 EPWM7
                DCD      EPWM8_Handler                       ;  63 EPWM8
                DCD      EPWM9_Handler                       ;  64 EPWM9
                DCD      EPWM10_Handler                      ;  65 EPWM10
                DCD      EPWM11_Handler                      ;  66 EPWM11
                DCD      EPWM12_Handler                      ;  67 EPWM12
                DCD      0                                   ;  68 RESERVED
                DCD      0                                   ;  69 RESERVED
                DCD      0                                   ;  70 RESERVED
                DCD      0                                   ;  71 RESERVED
                DCD      ECAP1_Handler                       ;  72 ECAP1
                DCD      ECAP2_Handler                       ;  73 ECAP2
                DCD      ECAP3_Handler                       ;  74 ECAP3
                DCD      ECAP4_Handler                       ;  75 ECAP4
                DCD      ECAP5_Handler                       ;  76 ECAP5
                DCD      ECAP6_Handler                       ;  77 ECAP6
                DCD      0                                   ;  78 RESERVED
                DCD      0                                   ;  79 RESERVED
                DCD      EQEP1_Handler                       ;  80 EQEP1
                DCD      EQEP2_Handler                       ;  81 EQEP2
                DCD      EQEP3_Handler                       ;  82 EQEP3
                DCD      0                                   ;  83 RESERVED
                DCD      CLB1_Handler                        ;  84 CLB1
                DCD      CLB2_Handler                        ;  85 CLB2
                DCD      CLB3_Handler                        ;  86 CLB3
                DCD      CLB4_Handler                        ;  87 CLB4
                DCD      CLB5_Handler                        ;  88 CLB5
                DCD      CLB6_Handler                        ;  89 CLB6
                DCD      CLB7_Handler                        ;  90 CLB7
                DCD      CLB8_Handler                        ;  91 CLB8
                DCD      0                                   ;  92 RESERVED
                DCD      0                                   ;  93 RESERVED
                DCD      0                                   ;  94 RESERVED
                DCD      0                                   ;  95 RESERVED
                DCD      SDFM1_Handler                       ;  96 SDFM1
                DCD      SDFM1_FLT1DR_Handler                ;  97 SDFM1 Filter1 Data Ready
                DCD      SDFM1_FLT2DR_Handler                ;  98 SDFM1 Filter2 Data Ready
                DCD      SDFM1_FLT3DR_Handler                ;  99 SDFM1 Filter3 Data Ready
                DCD      SDFM1_FLT4DR_Handler                ; 100 SDFM1 Filter4 Data Ready
                DCD      SDFM2_Handler                       ; 101 SDFM2
                DCD      SDFM2_FLT1DR_Handler                ; 102 SDFM2 Filter1 Data Ready
                DCD      SDFM2_FLT2DR_Handler                ; 103 SDFM2 Filter2 Data Ready
                DCD      SDFM2_FLT3DR_Handler                ; 104 SDFM2 Filter3 Data Ready
                DCD      SDFM2_FLT4DR_Handler                ; 105 SDFM2 Filter4 Data Ready
                DCD      0                                   ; 106 RESERVED
                DCD      0                                   ; 107 RESERVED
                DCD      0                                   ; 108 RESERVED
                DCD      0                                   ; 109 RESERVED
                DCD      0                                   ; 110 RESERVED
                DCD      0                                   ; 111 RESERVED
                DCD      DMA_CH1_Handler                     ; 112 DMA Channel1
                DCD      DMA_CH2_Handler                     ; 113 DMA Channel2
                DCD      DMA_CH3_Handler                     ; 114 DMA Channel3
                DCD      DMA_CH4_Handler                     ; 115 DMA Channel4
                DCD      DMA_CH5_Handler                     ; 116 DMA Channel5
                DCD      DMA_CH6_Handler                     ; 117 DMA Channel6
                DCD      0                                   ; 118 RESERVED
                DCD      0                                   ; 119 RESERVED
                DCD      0                                   ; 120 RESERVED
                DCD      0                                   ; 121 RESERVED
                DCD      0                                   ; 122 RESERVED
                DCD      0                                   ; 123 RESERVED
                DCD      0                                   ; 124 RESERVED
                DCD      0                                   ; 125 RESERVED
                DCD      USBA_Handler                        ; 126 USBA
                DCD      USBA_EP_MP_Handler                  ; 127 USBA EP MP
                DCD      USBA_EP0_Handler                    ; 128 USBA EP0
                DCD      USBA_EP1_Handler                    ; 129 USBA EP1
                DCD      USBA_EP2_Handler                    ; 130 USBA EP2
                DCD      USBA_EP3_Handler                    ; 131 USBA EP3
                DCD      USBA_EP4_Handler                    ; 132 USBA EP4
                DCD      USBA_EP5_Handler                    ; 133 USBA EP5
                DCD      USBA_EP6_Handler                    ; 134 USBA EP6
                DCD      USBA_EP7_Handler                    ; 135 USBA EP7
                DCD      USBA_EP8_Handler                    ; 136 USBA EP8
                DCD      USBA_EP9_Handler                    ; 137 USBA EP9
                DCD      USBA_EP10_Handler                   ; 138 USBA EP10
                DCD      USBA_EP11_Handler                   ; 139 USBA EP11
                DCD      USBA_EP12_Handler                   ; 140 USBA EP12
                DCD      USBA_EP13_Handler                   ; 141 USBA EP13
                DCD      USBA_EP14_Handler                   ; 142 USBA EP14
                DCD      USBA_EP15_Handler                   ; 143 USBA EP15
                DCD      USBA_EP16_Handler                   ; 144 USBA EP16
                DCD      USBA_EP17_Handler                   ; 145 USBA EP17
                DCD      USBA_EP18_Handler                   ; 146 USBA EP18
                DCD      USBA_EP19_Handler                   ; 147 USBA EP19
                DCD      USBA_EP20_Handler                   ; 148 USBA EP20
                DCD      USBA_EP21_Handler                   ; 149 USBA EP21
                DCD      USBA_EP22_Handler                   ; 150 USBA EP22
                DCD      USBA_EP23_Handler                   ; 151 USBA EP23
                DCD      USBA_EP24_Handler                   ; 152 USBA EP24
                DCD      USBA_EP25_Handler                   ; 153 USBA EP25
                DCD      USBA_EP26_Handler                   ; 154 USBA EP26
                DCD      USBA_EP27_Handler                   ; 155 USBA EP27
                DCD      USBA_EP28_Handler                   ; 156 USBA EP28
                DCD      USBA_EP29_Handler                   ; 157 USBA EP29
                DCD      USBA_EP30_Handler                   ; 158 USBA EP30
                DCD      USBA_EP31_Handler                   ; 159 USBA EP31
                DCD      MCANA_INT0_Handler                  ; 160 MCANA INT0
                DCD      MCANA_INT1_Handler                  ; 161 MCANA INT1
                DCD      MCANB_INT0_Handler                  ; 162 MCANB INT0
                DCD      MCANB_INT1_Handler                  ; 163 MCANB INT1
                DCD      MCANC_INT0_Handler                  ; 164 MCANC INT0
                DCD      MCANC_INT1_Handler                  ; 165 MCANC INT1
                DCD      0                                   ; 166 RESERVED
                DCD      0                                   ; 167 RESERVED
                DCD      I2CA_Handler                        ; 168 I2CA
                DCD      I2CB_Handler                        ; 169 I2CB
                DCD      0                                   ; 170 RESERVED
                DCD      0                                   ; 171 RESERVED
                DCD      PMBUSA_Handler                      ; 172 PMBUSA
                DCD      0                                   ; 173 RESERVED
                DCD      0                                   ; 174 RESERVED
                DCD      0                                   ; 175 RESERVED
                DCD      UARTA_Handler                       ; 176 UARTA
                DCD      UARTB_Handler                       ; 177 UARTB
                DCD      UARTC_Handler                       ; 178 UARTC
                DCD      UARTD_Handler                       ; 179 UARTD
                DCD      SPIA_Handler                        ; 180 SPIA
                DCD      SPIB_Handler                        ; 181 SPIB
                DCD      SPIC_Handler                        ; 182 SPIC
                DCD      0                                   ; 183 RESERVED
                DCD      SRAM_ECC_ERR_Handler                ; 184 SRAM Correctable ECC Error
                DCD      EFLASH_Handler                      ; 185 EFLASH
                DCD      SRAM_ACC_VIO_Handler                ; 186 SRAM Access Violation
                DCD      EMIF1_ERR_Handler                   ; 187 EMIF1 Error
                DCD      WAKEUP_Handler                      ; 188 WAKEUP
                DCD      0                                   ; 189 RESERVED
                DCD      0                                   ; 190 RESERVED
                DCD      0                                   ; 191 RESERVED
                DCD      TFU_Handler                         ; 192 TFU
                DCD      IPC_RAM_ERR_Handler                 ; 193 IPC RAM Error

                DS32     (30)                                ; Interrupts 194 .. 224 are left out */
                DS32     (16)                                ; Align to 256
__Vectors_End

__Vectors       EQU      __vector_table
__Vectors_Size  EQU      __Vectors_End - __Vectors


                THUMB

; Reset Handler

                PUBWEAK Reset_Handler
                SECTION .text:CODE:NOROOT:REORDER(2)
Reset_Handler
                CPSID    I                                   ; Mask interrupts
VTOR            EQU      0xE000ED08
                LDR      R0, =VTOR
                LDR      R1, =__Vectors                      ; Set VTOR
                STR      R1, [R0]
                LDR      R2, [R1]
                MSR      MSP, R2                             ; Set MSP
                LDR      R0, =SystemInit
                BLX      R0
                CPSIE    I                                   ; Unmask interrupts
                LDR      R0, =__iar_program_start
                BX       R0

;
; Macro to define default exception/interrupt handlers.
; Default handler are weak symbols calling driver handlers.
; Users can re-define the symbols to implement their own exception/interrupt handlers.
;
Set_Default_Handler MACRO Handler_Name, DriverHandler_Name
                PUBWEAK Handler_Name
                PUBWEAK DriverHandler_Name
                SECTION .text:CODE:REORDER:NOROOT(2)
Handler_Name
                LDR      R0, =DriverHandler_Name
                BX       R0
                ENDM

; Default exception/interrupt handler
                Set_Default_Handler  NMI_Handler, NMI_DriverHandler
                Set_Default_Handler  HardFault_Handler, HardFault_DriverHandler
                Set_Default_Handler  MemManage_Handler, MemManage_DriverHandler
                Set_Default_Handler  BusFault_Handler, BusFault_DriverHandler
                Set_Default_Handler  UsageFault_Handler, UsageFault_DriverHandler
                Set_Default_Handler  SVC_Handler, SVC_DriverHandler
                Set_Default_Handler  DebugMon_Handler, DebugMon_DriverHandler
                Set_Default_Handler  PendSV_Handler, PendSV_DriverHandler
                Set_Default_Handler  SysTick_Handler, SysTick_DriverHandler

                Set_Default_Handler  WDT_Handler, WDT_DriverHandler
                Set_Default_Handler  CPUTIMER0_Handler, CPUTIMER0_DriverHandler
                Set_Default_Handler  CPUTIMER1_Handler, CPUTIMER1_DriverHandler
                Set_Default_Handler  CPUTIMER2_Handler, CPUTIMER2_DriverHandler
                Set_Default_Handler  DWTIMER_CH0_Handler, DWTIMER_CH0_DriverHandler
                Set_Default_Handler  DWTIMER_CH1_Handler, DWTIMER_CH1_DriverHandler
                Set_Default_Handler  DWTIMER_CH2_Handler, DWTIMER_CH2_DriverHandler
                Set_Default_Handler  IPC_INT0_Handler, IPC_INT0_DriverHandler
                Set_Default_Handler  IPC_INT1_Handler, IPC_INT1_DriverHandler
                Set_Default_Handler  IPC_INT2_Handler, IPC_INT2_DriverHandler
                Set_Default_Handler  IPC_INT3_Handler, IPC_INT3_DriverHandler
                Set_Default_Handler  ADCA_EVT_Handler, ADCA_EVT_DriverHandler
                Set_Default_Handler  ADCB_EVT_Handler, ADCB_EVT_DriverHandler
                Set_Default_Handler  ADCC_EVT_Handler, ADCC_EVT_DriverHandler
                Set_Default_Handler  ADCD_EVT_Handler, ADCD_EVT_DriverHandler
                Set_Default_Handler  ADCA_INT1_Handler, ADCA_INT1_DriverHandler
                Set_Default_Handler  ADCA_INT2_Handler, ADCA_INT2_DriverHandler
                Set_Default_Handler  ADCA_INT3_Handler, ADCA_INT3_DriverHandler
                Set_Default_Handler  ADCA_INT4_Handler, ADCA_INT4_DriverHandler
                Set_Default_Handler  ADCB_INT1_Handler, ADCB_INT1_DriverHandler
                Set_Default_Handler  ADCB_INT2_Handler, ADCB_INT2_DriverHandler
                Set_Default_Handler  ADCB_INT3_Handler, ADCB_INT3_DriverHandler
                Set_Default_Handler  ADCB_INT4_Handler, ADCB_INT4_DriverHandler
                Set_Default_Handler  ADCC_INT1_Handler, ADCC_INT1_DriverHandler
                Set_Default_Handler  ADCC_INT2_Handler, ADCC_INT2_DriverHandler
                Set_Default_Handler  ADCC_INT3_Handler, ADCC_INT3_DriverHandler
                Set_Default_Handler  ADCC_INT4_Handler, ADCC_INT4_DriverHandler
                Set_Default_Handler  ADCD_INT1_Handler, ADCD_INT1_DriverHandler
                Set_Default_Handler  ADCD_INT2_Handler, ADCD_INT2_DriverHandler
                Set_Default_Handler  ADCD_INT3_Handler, ADCD_INT3_DriverHandler
                Set_Default_Handler  ADCD_INT4_Handler, ADCD_INT4_DriverHandler
                Set_Default_Handler  XINT1_Handler, XINT1_DriverHandler
                Set_Default_Handler  XINT2_Handler, XINT2_DriverHandler
                Set_Default_Handler  XINT3_Handler, XINT3_DriverHandler
                Set_Default_Handler  XINT4_Handler, XINT4_DriverHandler
                Set_Default_Handler  XINT5_Handler, XINT5_DriverHandler
                Set_Default_Handler  EPWM_HRCAL_Handler, EPWM_HRCAL_DriverHandler
                Set_Default_Handler  EPWM1_TZ_Handler, EPWM1_TZ_DriverHandler
                Set_Default_Handler  EPWM2_TZ_Handler, EPWM2_TZ_DriverHandler
                Set_Default_Handler  EPWM3_TZ_Handler, EPWM3_TZ_DriverHandler
                Set_Default_Handler  EPWM4_TZ_Handler, EPWM4_TZ_DriverHandler
                Set_Default_Handler  EPWM5_TZ_Handler, EPWM5_TZ_DriverHandler
                Set_Default_Handler  EPWM6_TZ_Handler, EPWM6_TZ_DriverHandler
                Set_Default_Handler  EPWM7_TZ_Handler, EPWM7_TZ_DriverHandler
                Set_Default_Handler  EPWM8_TZ_Handler, EPWM8_TZ_DriverHandler
                Set_Default_Handler  EPWM9_TZ_Handler, EPWM9_TZ_DriverHandler
                Set_Default_Handler  EPWM10_TZ_Handler, EPWM10_TZ_DriverHandler
                Set_Default_Handler  EPWM11_TZ_Handler, EPWM11_TZ_DriverHandler
                Set_Default_Handler  EPWM12_TZ_Handler, EPWM12_TZ_DriverHandler
                Set_Default_Handler  EPWM1_Handler, EPWM1_DriverHandler
                Set_Default_Handler  EPWM2_Handler, EPWM2_DriverHandler
                Set_Default_Handler  EPWM3_Handler, EPWM3_DriverHandler
                Set_Default_Handler  EPWM4_Handler, EPWM4_DriverHandler
                Set_Default_Handler  EPWM5_Handler, EPWM5_DriverHandler
                Set_Default_Handler  EPWM6_Handler, EPWM6_DriverHandler
                Set_Default_Handler  EPWM7_Handler, EPWM7_DriverHandler
                Set_Default_Handler  EPWM8_Handler, EPWM8_DriverHandler
                Set_Default_Handler  EPWM9_Handler, EPWM9_DriverHandler
                Set_Default_Handler  EPWM10_Handler, EPWM10_DriverHandler
                Set_Default_Handler  EPWM11_Handler, EPWM11_DriverHandler
                Set_Default_Handler  EPWM12_Handler, EPWM12_DriverHandler
                Set_Default_Handler  ECAP1_Handler, ECAP1_DriverHandler
                Set_Default_Handler  ECAP2_Handler, ECAP2_DriverHandler
                Set_Default_Handler  ECAP3_Handler, ECAP3_DriverHandler
                Set_Default_Handler  ECAP4_Handler, ECAP4_DriverHandler
                Set_Default_Handler  ECAP5_Handler, ECAP5_DriverHandler
                Set_Default_Handler  ECAP6_Handler, ECAP6_DriverHandler
                Set_Default_Handler  EQEP1_Handler, EQEP1_DriverHandler
                Set_Default_Handler  EQEP2_Handler, EQEP2_DriverHandler
                Set_Default_Handler  EQEP3_Handler, EQEP3_DriverHandler
                Set_Default_Handler  CLB1_Handler, CLB1_DriverHandler
                Set_Default_Handler  CLB2_Handler, CLB2_DriverHandler
                Set_Default_Handler  CLB3_Handler, CLB3_DriverHandler
                Set_Default_Handler  CLB4_Handler, CLB4_DriverHandler
                Set_Default_Handler  CLB5_Handler, CLB5_DriverHandler
                Set_Default_Handler  CLB6_Handler, CLB6_DriverHandler
                Set_Default_Handler  CLB7_Handler, CLB7_DriverHandler
                Set_Default_Handler  CLB8_Handler, CLB8_DriverHandler
                Set_Default_Handler  SDFM1_Handler, SDFM1_DriverHandler
                Set_Default_Handler  SDFM1_FLT1DR_Handler, SDFM1_FLT1DR_DriverHandler
                Set_Default_Handler  SDFM1_FLT2DR_Handler, SDFM1_FLT2DR_DriverHandler
                Set_Default_Handler  SDFM1_FLT3DR_Handler, SDFM1_FLT3DR_DriverHandler
                Set_Default_Handler  SDFM1_FLT4DR_Handler, SDFM1_FLT4DR_DriverHandler
                Set_Default_Handler  SDFM2_Handler, SDFM2_DriverHandler
                Set_Default_Handler  SDFM2_FLT1DR_Handler, SDFM2_FLT1DR_DriverHandler
                Set_Default_Handler  SDFM2_FLT2DR_Handler, SDFM2_FLT2DR_DriverHandler
                Set_Default_Handler  SDFM2_FLT3DR_Handler, SDFM2_FLT3DR_DriverHandler
                Set_Default_Handler  SDFM2_FLT4DR_Handler, SDFM2_FLT4DR_DriverHandler
                Set_Default_Handler  DMA_CH1_Handler, DMA_CH1_DriverHandler
                Set_Default_Handler  DMA_CH2_Handler, DMA_CH2_DriverHandler
                Set_Default_Handler  DMA_CH3_Handler, DMA_CH3_DriverHandler
                Set_Default_Handler  DMA_CH4_Handler, DMA_CH4_DriverHandler
                Set_Default_Handler  DMA_CH5_Handler, DMA_CH5_DriverHandler
                Set_Default_Handler  DMA_CH6_Handler, DMA_CH6_DriverHandler
                Set_Default_Handler  USBA_Handler, USBA_DriverHandler
                Set_Default_Handler  USBA_EP_MP_Handler, USBA_EP_MP_DriverHandler
                Set_Default_Handler  USBA_EP0_Handler, USBA_EP0_DriverHandler
                Set_Default_Handler  USBA_EP1_Handler, USBA_EP1_DriverHandler
                Set_Default_Handler  USBA_EP2_Handler, USBA_EP2_DriverHandler
                Set_Default_Handler  USBA_EP3_Handler, USBA_EP3_DriverHandler
                Set_Default_Handler  USBA_EP4_Handler, USBA_EP4_DriverHandler
                Set_Default_Handler  USBA_EP5_Handler, USBA_EP5_DriverHandler
                Set_Default_Handler  USBA_EP6_Handler, USBA_EP6_DriverHandler
                Set_Default_Handler  USBA_EP7_Handler, USBA_EP7_DriverHandler
                Set_Default_Handler  USBA_EP8_Handler, USBA_EP8_DriverHandler
                Set_Default_Handler  USBA_EP9_Handler, USBA_EP9_DriverHandler
                Set_Default_Handler  USBA_EP10_Handler, USBA_EP10_DriverHandler
                Set_Default_Handler  USBA_EP11_Handler, USBA_EP11_DriverHandler
                Set_Default_Handler  USBA_EP12_Handler, USBA_EP12_DriverHandler
                Set_Default_Handler  USBA_EP13_Handler, USBA_EP13_DriverHandler
                Set_Default_Handler  USBA_EP14_Handler, USBA_EP14_DriverHandler
                Set_Default_Handler  USBA_EP15_Handler, USBA_EP15_DriverHandler
                Set_Default_Handler  USBA_EP16_Handler, USBA_EP16_DriverHandler
                Set_Default_Handler  USBA_EP17_Handler, USBA_EP17_DriverHandler
                Set_Default_Handler  USBA_EP18_Handler, USBA_EP18_DriverHandler
                Set_Default_Handler  USBA_EP19_Handler, USBA_EP19_DriverHandler
                Set_Default_Handler  USBA_EP20_Handler, USBA_EP20_DriverHandler
                Set_Default_Handler  USBA_EP21_Handler, USBA_EP21_DriverHandler
                Set_Default_Handler  USBA_EP22_Handler, USBA_EP22_DriverHandler
                Set_Default_Handler  USBA_EP23_Handler, USBA_EP23_DriverHandler
                Set_Default_Handler  USBA_EP24_Handler, USBA_EP24_DriverHandler
                Set_Default_Handler  USBA_EP25_Handler, USBA_EP25_DriverHandler
                Set_Default_Handler  USBA_EP26_Handler, USBA_EP26_DriverHandler
                Set_Default_Handler  USBA_EP27_Handler, USBA_EP27_DriverHandler
                Set_Default_Handler  USBA_EP28_Handler, USBA_EP28_DriverHandler
                Set_Default_Handler  USBA_EP29_Handler, USBA_EP29_DriverHandler
                Set_Default_Handler  USBA_EP30_Handler, USBA_EP30_DriverHandler
                Set_Default_Handler  USBA_EP31_Handler, USBA_EP31_DriverHandler
                Set_Default_Handler  MCANA_INT0_Handler, MCANA_INT0_DriverHandler
                Set_Default_Handler  MCANA_INT1_Handler, MCANA_INT1_DriverHandler
                Set_Default_Handler  MCANB_INT0_Handler, MCANB_INT0_DriverHandler
                Set_Default_Handler  MCANB_INT1_Handler, MCANB_INT1_DriverHandler
                Set_Default_Handler  MCANC_INT0_Handler, MCANC_INT0_DriverHandler
                Set_Default_Handler  MCANC_INT1_Handler, MCANC_INT1_DriverHandler
                Set_Default_Handler  I2CA_Handler, I2CA_DriverHandler
                Set_Default_Handler  I2CB_Handler, I2CB_DriverHandler
                Set_Default_Handler  PMBUSA_Handler, PMBUSA_DriverHandler
                Set_Default_Handler  UARTA_Handler, UARTA_DriverHandler
                Set_Default_Handler  UARTB_Handler, UARTB_DriverHandler
                Set_Default_Handler  UARTC_Handler, UARTC_DriverHandler
                Set_Default_Handler  UARTD_Handler, UARTD_DriverHandler
                Set_Default_Handler  SPIA_Handler, SPIA_DriverHandler
                Set_Default_Handler  SPIB_Handler, SPIB_DriverHandler
                Set_Default_Handler  SPIC_Handler, SPIC_DriverHandler
                Set_Default_Handler  SRAM_ECC_ERR_Handler, SRAM_ECC_ERR_DriverHandler
                Set_Default_Handler  EFLASH_Handler, EFLASH_DriverHandler
                Set_Default_Handler  SRAM_ACC_VIO_Handler, SRAM_ACC_VIO_DriverHandler
                Set_Default_Handler  EMIF1_ERR_Handler, EMIF1_ERR_DriverHandler
                Set_Default_Handler  WAKEUP_Handler, WAKEUP_DriverHandler
                Set_Default_Handler  TFU_Handler, TFU_DriverHandler
                Set_Default_Handler  IPC_RAM_ERR_Handler, IPC_RAM_ERR_DriverHandler

;
; Default exception/interrupt driver handlers are weak symbols with an endless loop,
; which will be overwritten by SDK driver handlers.
; Users can read the SDK driver handlers, 
; and learn how to write their own exception/interrupt handlers.
;
                PUBWEAK Default_DriverHandler
                SECTION .text:CODE:REORDER:NOROOT(1)
NMI_DriverHandler
HardFault_DriverHandler
MemManage_DriverHandler
BusFault_DriverHandler
UsageFault_DriverHandler
SVC_DriverHandler
DebugMon_DriverHandler
PendSV_DriverHandler
SysTick_DriverHandler

WDT_DriverHandler
CPUTIMER0_DriverHandler
CPUTIMER1_DriverHandler
CPUTIMER2_DriverHandler
DWTIMER_CH0_DriverHandler
DWTIMER_CH1_DriverHandler
DWTIMER_CH2_DriverHandler
IPC_INT0_DriverHandler
IPC_INT1_DriverHandler
IPC_INT2_DriverHandler
IPC_INT3_DriverHandler
ADCA_EVT_DriverHandler
ADCB_EVT_DriverHandler
ADCC_EVT_DriverHandler
ADCD_EVT_DriverHandler
ADCA_INT1_DriverHandler
ADCA_INT2_DriverHandler
ADCA_INT3_DriverHandler
ADCA_INT4_DriverHandler
ADCB_INT1_DriverHandler
ADCB_INT2_DriverHandler
ADCB_INT3_DriverHandler
ADCB_INT4_DriverHandler
ADCC_INT1_DriverHandler
ADCC_INT2_DriverHandler
ADCC_INT3_DriverHandler
ADCC_INT4_DriverHandler
ADCD_INT1_DriverHandler
ADCD_INT2_DriverHandler
ADCD_INT3_DriverHandler
ADCD_INT4_DriverHandler
XINT1_DriverHandler
XINT2_DriverHandler
XINT3_DriverHandler
XINT4_DriverHandler
XINT5_DriverHandler
EPWM_HRCAL_DriverHandler
EPWM1_TZ_DriverHandler
EPWM2_TZ_DriverHandler
EPWM3_TZ_DriverHandler
EPWM4_TZ_DriverHandler
EPWM5_TZ_DriverHandler
EPWM6_TZ_DriverHandler
EPWM7_TZ_DriverHandler
EPWM8_TZ_DriverHandler
EPWM9_TZ_DriverHandler
EPWM10_TZ_DriverHandler
EPWM11_TZ_DriverHandler
EPWM12_TZ_DriverHandler
EPWM1_DriverHandler
EPWM2_DriverHandler
EPWM3_DriverHandler
EPWM4_DriverHandler
EPWM5_DriverHandler
EPWM6_DriverHandler
EPWM7_DriverHandler
EPWM8_DriverHandler
EPWM9_DriverHandler
EPWM10_DriverHandler
EPWM11_DriverHandler
EPWM12_DriverHandler
ECAP1_DriverHandler
ECAP2_DriverHandler
ECAP3_DriverHandler
ECAP4_DriverHandler
ECAP5_DriverHandler
ECAP6_DriverHandler
EQEP1_DriverHandler
EQEP2_DriverHandler
EQEP3_DriverHandler
CLB1_DriverHandler
CLB2_DriverHandler
CLB3_DriverHandler
CLB4_DriverHandler
CLB5_DriverHandler
CLB6_DriverHandler
CLB7_DriverHandler
CLB8_DriverHandler
SDFM1_DriverHandler
SDFM1_FLT1DR_DriverHandler
SDFM1_FLT2DR_DriverHandler
SDFM1_FLT3DR_DriverHandler
SDFM1_FLT4DR_DriverHandler
SDFM2_DriverHandler
SDFM2_FLT1DR_DriverHandler
SDFM2_FLT2DR_DriverHandler
SDFM2_FLT3DR_DriverHandler
SDFM2_FLT4DR_DriverHandler
DMA_CH1_DriverHandler
DMA_CH2_DriverHandler
DMA_CH3_DriverHandler
DMA_CH4_DriverHandler
DMA_CH5_DriverHandler
DMA_CH6_DriverHandler
USBA_DriverHandler
USBA_EP_MP_DriverHandler
USBA_EP0_DriverHandler
USBA_EP1_DriverHandler
USBA_EP2_DriverHandler
USBA_EP3_DriverHandler
USBA_EP4_DriverHandler
USBA_EP5_DriverHandler
USBA_EP6_DriverHandler
USBA_EP7_DriverHandler
USBA_EP8_DriverHandler
USBA_EP9_DriverHandler
USBA_EP10_DriverHandler
USBA_EP11_DriverHandler
USBA_EP12_DriverHandler
USBA_EP13_DriverHandler
USBA_EP14_DriverHandler
USBA_EP15_DriverHandler
USBA_EP16_DriverHandler
USBA_EP17_DriverHandler
USBA_EP18_DriverHandler
USBA_EP19_DriverHandler
USBA_EP20_DriverHandler
USBA_EP21_DriverHandler
USBA_EP22_DriverHandler
USBA_EP23_DriverHandler
USBA_EP24_DriverHandler
USBA_EP25_DriverHandler
USBA_EP26_DriverHandler
USBA_EP27_DriverHandler
USBA_EP28_DriverHandler
USBA_EP29_DriverHandler
USBA_EP30_DriverHandler
USBA_EP31_DriverHandler
MCANA_INT0_DriverHandler
MCANA_INT1_DriverHandler
MCANB_INT0_DriverHandler
MCANB_INT1_DriverHandler
MCANC_INT0_DriverHandler
MCANC_INT1_DriverHandler
I2CA_DriverHandler
I2CB_DriverHandler
PMBUSA_DriverHandler
UARTA_DriverHandler
UARTB_DriverHandler
UARTC_DriverHandler
UARTD_DriverHandler
SPIA_DriverHandler
SPIB_DriverHandler
SPIC_DriverHandler
SRAM_ECC_ERR_DriverHandler
EFLASH_DriverHandler
SRAM_ACC_VIO_DriverHandler
EMIF1_ERR_DriverHandler
WAKEUP_DriverHandler
TFU_DriverHandler
IPC_RAM_ERR_DriverHandler
Default_DriverHandler
                B        .


                END
