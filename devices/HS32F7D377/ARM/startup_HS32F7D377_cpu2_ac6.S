/*
 * Copyright 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

                .syntax  unified
                .arch    armv7e-m
                .eabi_attribute Tag_ABI_align_preserved, 1

                .section RESET
                .align   2
                .globl   __Vectors
                .globl   __Vectors_End
                .globl   __Vectors_Size
__Vectors:
                .long    Image$$ARM_LIB_STACK$$ZI$$Limit    /*     Initial Stack Pointer */
                .long    Reset_Handler                      /*     Reset Handler */
                .long    NMI_Handler                        /* -14 NMI Handler */
                .long    HardFault_Handler                  /* -13 Hard Fault Handler */
                .long    MemManage_Handler                  /* -12 MPU Fault Handler */
                .long    BusFault_Handler                   /* -11 Bus Fault Handler */
                .long    UsageFault_Handler                 /* -10 Usage Fault Handler */
                .long    0                                  /*     Reserved */
                .long    0                                  /*     Reserved */
                .long    0                                  /*     Reserved */
                .long    0                                  /*     Reserved */
                .long    SVC_Handler                        /*  -5 SVC Handler */
                .long    DebugMon_Handler                   /*  -4 Debug Monitor Handler */
                .long    0                                  /*     Reserved */
                .long    PendSV_Handler                     /*  -2 PendSV Handler */
                .long    SysTick_Handler                    /*  -1 SysTick Handler */

                /* Interrupts */
                .long    WDT_Handler                        /*   0 WDT */
                .long    CPUTIMER0_Handler                  /*   1 CPU TIMER0 */
                .long    CPUTIMER1_Handler                  /*   2 CPU TIMER1 */
                .long    CPUTIMER2_Handler                  /*   3 CPU TIMER2 */
                .long    DWTIMER_CH0_Handler                /*   4 DWTIMER Channel0 */
                .long    DWTIMER_CH1_Handler                /*   5 DWTIMER Channel1 */
                .long    DWTIMER_CH2_Handler                /*   6 DWTIMER Channel2 */
                .long    0                                  /*   7 RESERVED */
                .long    IPC_INT0_Handler                   /*   8 IPC INT0 */
                .long    IPC_INT1_Handler                   /*   9 IPC INT1 */
                .long    IPC_INT2_Handler                   /*  10 IPC INT2 */
                .long    IPC_INT3_Handler                   /*  11 IPC INT3 */
                .long    ADCA_EVT_Handler                   /*  12 ADCA Event */
                .long    ADCB_EVT_Handler                   /*  13 ADCB Event */
                .long    ADCC_EVT_Handler                   /*  14 ADCC Event */
                .long    ADCD_EVT_Handler                   /*  15 ADCD Event */
                .long    ADCA_INT1_Handler                  /*  16 ADCA INT1 */
                .long    ADCA_INT2_Handler                  /*  17 ADCA INT2 */
                .long    ADCA_INT3_Handler                  /*  18 ADCA INT3 */
                .long    ADCA_INT4_Handler                  /*  19 ADCA INT4 */
                .long    ADCB_INT1_Handler                  /*  20 ADCB INT1 */
                .long    ADCB_INT2_Handler                  /*  21 ADCB INT2 */
                .long    ADCB_INT3_Handler                  /*  22 ADCB INT3 */
                .long    ADCB_INT4_Handler                  /*  23 ADCB INT4 */
                .long    ADCC_INT1_Handler                  /*  24 ADCC INT1 */
                .long    ADCC_INT2_Handler                  /*  25 ADCC INT2 */
                .long    ADCC_INT3_Handler                  /*  26 ADCC INT3 */
                .long    ADCC_INT4_Handler                  /*  27 ADCC INT4 */
                .long    ADCD_INT1_Handler                  /*  28 ADCD INT1 */
                .long    ADCD_INT2_Handler                  /*  29 ADCD INT2 */
                .long    ADCD_INT3_Handler                  /*  30 ADCD INT3 */
                .long    ADCD_INT4_Handler                  /*  31 ADCD INT4 */
                .long    XINT1_Handler                      /*  32 XINT1 */
                .long    XINT2_Handler                      /*  33 XINT2 */
                .long    XINT3_Handler                      /*  34 XINT3 */
                .long    XINT4_Handler                      /*  35 XINT4 */
                .long    XINT5_Handler                      /*  36 XINT5 */
                .long    0                                  /*  37 RESERVED */
                .long    0                                  /*  38 RESERVED */
                .long    EPWM_HRCAL_Handler                 /*  39 EPWM High-Resolution Calibration */
                .long    EPWM1_TZ_Handler                   /*  40 EPWM1 Trip-Zone */
                .long    EPWM2_TZ_Handler                   /*  41 EPWM2 Trip-Zone */
                .long    EPWM3_TZ_Handler                   /*  42 EPWM3 Trip-Zone */
                .long    EPWM4_TZ_Handler                   /*  43 EPWM4 Trip-Zone */
                .long    EPWM5_TZ_Handler                   /*  44 EPWM5 Trip-Zone */
                .long    EPWM6_TZ_Handler                   /*  45 EPWM6 Trip-Zone */
                .long    EPWM7_TZ_Handler                   /*  46 EPWM7 Trip-Zone */
                .long    EPWM8_TZ_Handler                   /*  47 EPWM8 Trip-Zone */
                .long    EPWM9_TZ_Handler                   /*  48 EPWM9 Trip-Zone */
                .long    EPWM10_TZ_Handler                  /*  49 EPWM10 Trip-Zone */
                .long    EPWM11_TZ_Handler                  /*  50 EPWM11 Trip-Zone */
                .long    EPWM12_TZ_Handler                  /*  51 EPWM12 Trip-Zone */
                .long    0                                  /*  52 RESERVED */
                .long    0                                  /*  53 RESERVED */
                .long    0                                  /*  54 RESERVED */
                .long    0                                  /*  55 RESERVED */
                .long    EPWM1_Handler                      /*  56 EPWM1 */
                .long    EPWM2_Handler                      /*  57 EPWM2 */
                .long    EPWM3_Handler                      /*  58 EPWM3 */
                .long    EPWM4_Handler                      /*  59 EPWM4 */
                .long    EPWM5_Handler                      /*  60 EPWM5 */
                .long    EPWM6_Handler                      /*  61 EPWM6 */
                .long    EPWM7_Handler                      /*  62 EPWM7 */
                .long    EPWM8_Handler                      /*  63 EPWM8 */
                .long    EPWM9_Handler                      /*  64 EPWM9 */
                .long    EPWM10_Handler                     /*  65 EPWM10 */
                .long    EPWM11_Handler                     /*  66 EPWM11 */
                .long    EPWM12_Handler                     /*  67 EPWM12 */
                .long    0                                  /*  68 RESERVED */
                .long    0                                  /*  69 RESERVED */
                .long    0                                  /*  70 RESERVED */
                .long    0                                  /*  71 RESERVED */
                .long    ECAP1_Handler                      /*  72 ECAP1 */
                .long    ECAP2_Handler                      /*  73 ECAP2 */
                .long    ECAP3_Handler                      /*  74 ECAP3 */
                .long    ECAP4_Handler                      /*  75 ECAP4 */
                .long    ECAP5_Handler                      /*  76 ECAP5 */
                .long    ECAP6_Handler                      /*  77 ECAP6 */
                .long    0                                  /*  78 RESERVED */
                .long    0                                  /*  79 RESERVED */
                .long    EQEP1_Handler                      /*  80 EQEP1 */
                .long    EQEP2_Handler                      /*  81 EQEP2 */
                .long    EQEP3_Handler                      /*  82 EQEP3 */
                .long    0                                  /*  83 RESERVED */
                .long    CLB1_Handler                       /*  84 CLB1 */
                .long    CLB2_Handler                       /*  85 CLB2 */
                .long    CLB3_Handler                       /*  86 CLB3 */
                .long    CLB4_Handler                       /*  87 CLB4 */
                .long    CLB5_Handler                       /*  88 CLB5 */
                .long    CLB6_Handler                       /*  89 CLB6 */
                .long    CLB7_Handler                       /*  90 CLB7 */
                .long    CLB8_Handler                       /*  91 CLB8 */
                .long    0                                  /*  92 RESERVED */
                .long    0                                  /*  93 RESERVED */
                .long    0                                  /*  94 RESERVED */
                .long    0                                  /*  95 RESERVED */
                .long    SDFM1_Handler                      /*  96 SDFM1 */
                .long    SDFM1_FLT1DR_Handler               /*  97 SDFM1 Filter1 Data Ready */
                .long    SDFM1_FLT2DR_Handler               /*  98 SDFM1 Filter2 Data Ready */
                .long    SDFM1_FLT3DR_Handler               /*  99 SDFM1 Filter3 Data Ready */
                .long    SDFM1_FLT4DR_Handler               /* 100 SDFM1 Filter4 Data Ready */
                .long    SDFM2_Handler                      /* 101 SDFM2 */
                .long    SDFM2_FLT1DR_Handler               /* 102 SDFM2 Filter1 Data Ready */
                .long    SDFM2_FLT2DR_Handler               /* 103 SDFM2 Filter2 Data Ready */
                .long    SDFM2_FLT3DR_Handler               /* 104 SDFM2 Filter3 Data Ready */
                .long    SDFM2_FLT4DR_Handler               /* 105 SDFM2 Filter4 Data Ready */
                .long    0                                  /* 106 RESERVED */
                .long    0                                  /* 107 RESERVED */
                .long    0                                  /* 108 RESERVED */
                .long    0                                  /* 109 RESERVED */
                .long    0                                  /* 110 RESERVED */
                .long    0                                  /* 111 RESERVED */
                .long    DMA_CH1_Handler                    /* 112 DMA Channel1 */
                .long    DMA_CH2_Handler                    /* 113 DMA Channel2 */
                .long    DMA_CH3_Handler                    /* 114 DMA Channel3 */
                .long    DMA_CH4_Handler                    /* 115 DMA Channel4 */
                .long    DMA_CH5_Handler                    /* 116 DMA Channel5 */
                .long    DMA_CH6_Handler                    /* 117 DMA Channel6 */
                .long    0                                  /* 118 RESERVED */
                .long    0                                  /* 119 RESERVED */
                .long    0                                  /* 120 RESERVED */
                .long    0                                  /* 121 RESERVED */
                .long    0                                  /* 122 RESERVED */
                .long    0                                  /* 123 RESERVED */
                .long    0                                  /* 124 RESERVED */
                .long    0                                  /* 125 RESERVED */
                .long    USBA_Handler                       /* 126 USBA */
                .long    USBA_EP_MP_Handler                 /* 127 USBA EP MP */
                .long    USBA_EP0_Handler                   /* 128 USBA EP0 */
                .long    USBA_EP1_Handler                   /* 129 USBA EP1 */
                .long    USBA_EP2_Handler                   /* 130 USBA EP2 */
                .long    USBA_EP3_Handler                   /* 131 USBA EP3 */
                .long    USBA_EP4_Handler                   /* 132 USBA EP4 */
                .long    USBA_EP5_Handler                   /* 133 USBA EP5 */
                .long    USBA_EP6_Handler                   /* 134 USBA EP6 */
                .long    USBA_EP7_Handler                   /* 135 USBA EP7 */
                .long    USBA_EP8_Handler                   /* 136 USBA EP8 */
                .long    USBA_EP9_Handler                   /* 137 USBA EP9 */
                .long    USBA_EP10_Handler                  /* 138 USBA EP10 */
                .long    USBA_EP11_Handler                  /* 139 USBA EP11 */
                .long    USBA_EP12_Handler                  /* 140 USBA EP12 */
                .long    USBA_EP13_Handler                  /* 141 USBA EP13 */
                .long    USBA_EP14_Handler                  /* 142 USBA EP14 */
                .long    USBA_EP15_Handler                  /* 143 USBA EP15 */
                .long    USBA_EP16_Handler                  /* 144 USBA EP16 */
                .long    USBA_EP17_Handler                  /* 145 USBA EP17 */
                .long    USBA_EP18_Handler                  /* 146 USBA EP18 */
                .long    USBA_EP19_Handler                  /* 147 USBA EP19 */
                .long    USBA_EP20_Handler                  /* 148 USBA EP20 */
                .long    USBA_EP21_Handler                  /* 149 USBA EP21 */
                .long    USBA_EP22_Handler                  /* 150 USBA EP22 */
                .long    USBA_EP23_Handler                  /* 151 USBA EP23 */
                .long    USBA_EP24_Handler                  /* 152 USBA EP24 */
                .long    USBA_EP25_Handler                  /* 153 USBA EP25 */
                .long    USBA_EP26_Handler                  /* 154 USBA EP26 */
                .long    USBA_EP27_Handler                  /* 155 USBA EP27 */
                .long    USBA_EP28_Handler                  /* 156 USBA EP28 */
                .long    USBA_EP29_Handler                  /* 157 USBA EP29 */
                .long    USBA_EP30_Handler                  /* 158 USBA EP30 */
                .long    USBA_EP31_Handler                  /* 159 USBA EP31 */
                .long    MCANA_INT0_Handler                 /* 160 MCANA INT0 */
                .long    MCANA_INT1_Handler                 /* 161 MCANA INT1 */
                .long    MCANB_INT0_Handler                 /* 162 MCANB INT0 */
                .long    MCANB_INT1_Handler                 /* 163 MCANB INT1 */
                .long    MCANC_INT0_Handler                 /* 164 MCANC INT0 */
                .long    MCANC_INT1_Handler                 /* 165 MCANC INT1 */
                .long    0                                  /* 166 RESERVED */
                .long    0                                  /* 167 RESERVED */
                .long    I2CA_Handler                       /* 168 I2CA */
                .long    I2CB_Handler                       /* 169 I2CB */
                .long    0                                  /* 170 RESERVED */
                .long    0                                  /* 171 RESERVED */
                .long    PMBUSA_Handler                     /* 172 PMBUSA */
                .long    0                                  /* 173 RESERVED */
                .long    0                                  /* 174 RESERVED */
                .long    0                                  /* 175 RESERVED */
                .long    UARTA_Handler                      /* 176 UARTA */
                .long    UARTB_Handler                      /* 177 UARTB */
                .long    UARTC_Handler                      /* 178 UARTC */
                .long    UARTD_Handler                      /* 179 UARTD */
                .long    SPIA_Handler                       /* 180 SPIA */
                .long    SPIB_Handler                       /* 181 SPIB */
                .long    SPIC_Handler                       /* 182 SPIC */
                .long    0                                  /* 183 RESERVED */
                .long    SRAM_ECC_ERR_Handler               /* 184 SRAM Correctable ECC Error */
                .long    EFLASH_Handler                     /* 185 EFLASH */
                .long    SRAM_ACC_VIO_Handler               /* 186 SRAM Access Violation */
                .long    EMIF1_ERR_Handler                  /* 187 EMIF1 Error */
                .long    WAKEUP_Handler                     /* 188 WAKEUP */
                .long    0                                  /* 189 RESERVED */
                .long    0                                  /* 190 RESERVED */
                .long    0                                  /* 191 RESERVED */
                .long    TFU_Handler                        /* 192 TFU */
                .long    IPC_RAM_ERR_Handler                /* 193 IPC RAM Error */

                .space   (30 * 4)                           /* Interrupts 194 .. 224 are left out */
                .space   (16 * 4)                           /* Align to 256 */
__Vectors_End:
                .equ     __Vectors_Size, __Vectors_End - __Vectors
                .size    __Vectors, . - __Vectors


                .thumb
                .section .text
                .align   2

                .thumb_func
                .type    Reset_Handler, %function
                .globl   Reset_Handler
                .fnstart
Reset_Handler:
                cpsid    i                                  /* Mask interrupts */
                .equ     VTOR, 0xE000ED08
                ldr      r0, =VTOR
                ldr      r1, =__Vectors                     /* Set VTOR */
                str      r1, [r0]
                ldr      r2, [r1]
                msr      msp, r2                            /* Set MSP */
                ldr      r0, =SystemInit
                blx      r0
                cpsie    i                                  /* Unmask interrupts */
                ldr      r0, =__main
                bx       r0

                .fnend
                .size    Reset_Handler, . - Reset_Handler

/*
 * Macro to define default exception/interrupt handlers.
 * Default handler are weak symbols calling driver handlers.
 * Users can re-define the symbols to implement their own exception/interrupt handlers.
 */
                .macro Set_Default_Handler Handler_Name:req, DriverHandler_Name:req
                .thumb_func
                .type    \Handler_Name, %function
                .weak    \Handler_Name
                .fnstart
\Handler_Name:
                ldr      r0, =\DriverHandler_Name
                bx       r0
                .fnend
                .size    \Handler_Name, . - \Handler_Name
                .endm

/* Default exception/interrupt handler */
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

/*
 * The default macro is not used for HardFault_DriverHandler.
 * Because this results in a poor debug illusion.
 */
                .thumb_func
                .type    HardFault_DriverHandler, %function
                .weak    HardFault_DriverHandler
                .fnstart
HardFault_DriverHandler:
                b        .
                .fnend
                .size    HardFault_DriverHandler, . - HardFault_DriverHandler

/* The default driver handler */
                .thumb_func
                .type    Default_DriverHandler, %function
                .weak    Default_DriverHandler
                .fnstart
Default_DriverHandler:
                b        .
                .fnend
                .size    Default_DriverHandler, . - Default_DriverHandler

/*
 * Macro to define default exception/interrupt driver handlers.
 * Default driver handler are weak symbols with an endless loop,
 * which will be overwritten by SDK driver handlers.
 * Users can read the SDK driver handlers,
 * and learn how to write their own exception/interrupt handlers.
 */
                .macro   Set_Default_DriverHandler  DriverHandler_Name
                .weak    \DriverHandler_Name
                .set     \DriverHandler_Name, Default_DriverHandler
                .endm

/* Default exception/interrupt driver handler */
                Set_Default_DriverHandler  NMI_DriverHandler
//              Set_Default_DriverHandler  HardFault_DriverHandler
                Set_Default_DriverHandler  MemManage_DriverHandler
                Set_Default_DriverHandler  BusFault_DriverHandler
                Set_Default_DriverHandler  UsageFault_DriverHandler
                Set_Default_DriverHandler  SVC_DriverHandler
                Set_Default_DriverHandler  DebugMon_DriverHandler
                Set_Default_DriverHandler  PendSV_DriverHandler
                Set_Default_DriverHandler  SysTick_DriverHandler

                Set_Default_DriverHandler  WDT_DriverHandler
                Set_Default_DriverHandler  CPUTIMER0_DriverHandler
                Set_Default_DriverHandler  CPUTIMER1_DriverHandler
                Set_Default_DriverHandler  CPUTIMER2_DriverHandler
                Set_Default_DriverHandler  DWTIMER_CH0_DriverHandler
                Set_Default_DriverHandler  DWTIMER_CH1_DriverHandler
                Set_Default_DriverHandler  DWTIMER_CH2_DriverHandler
                Set_Default_DriverHandler  IPC_INT0_DriverHandler
                Set_Default_DriverHandler  IPC_INT1_DriverHandler
                Set_Default_DriverHandler  IPC_INT2_DriverHandler
                Set_Default_DriverHandler  IPC_INT3_DriverHandler
                Set_Default_DriverHandler  ADCA_EVT_DriverHandler
                Set_Default_DriverHandler  ADCB_EVT_DriverHandler
                Set_Default_DriverHandler  ADCC_EVT_DriverHandler
                Set_Default_DriverHandler  ADCD_EVT_DriverHandler
                Set_Default_DriverHandler  ADCA_INT1_DriverHandler
                Set_Default_DriverHandler  ADCA_INT2_DriverHandler
                Set_Default_DriverHandler  ADCA_INT3_DriverHandler
                Set_Default_DriverHandler  ADCA_INT4_DriverHandler
                Set_Default_DriverHandler  ADCB_INT1_DriverHandler
                Set_Default_DriverHandler  ADCB_INT2_DriverHandler
                Set_Default_DriverHandler  ADCB_INT3_DriverHandler
                Set_Default_DriverHandler  ADCB_INT4_DriverHandler
                Set_Default_DriverHandler  ADCC_INT1_DriverHandler
                Set_Default_DriverHandler  ADCC_INT2_DriverHandler
                Set_Default_DriverHandler  ADCC_INT3_DriverHandler
                Set_Default_DriverHandler  ADCC_INT4_DriverHandler
                Set_Default_DriverHandler  ADCD_INT1_DriverHandler
                Set_Default_DriverHandler  ADCD_INT2_DriverHandler
                Set_Default_DriverHandler  ADCD_INT3_DriverHandler
                Set_Default_DriverHandler  ADCD_INT4_DriverHandler
                Set_Default_DriverHandler  XINT1_DriverHandler
                Set_Default_DriverHandler  XINT2_DriverHandler
                Set_Default_DriverHandler  XINT3_DriverHandler
                Set_Default_DriverHandler  XINT4_DriverHandler
                Set_Default_DriverHandler  XINT5_DriverHandler
                Set_Default_DriverHandler  EPWM_HRCAL_DriverHandler
                Set_Default_DriverHandler  EPWM1_TZ_DriverHandler
                Set_Default_DriverHandler  EPWM2_TZ_DriverHandler
                Set_Default_DriverHandler  EPWM3_TZ_DriverHandler
                Set_Default_DriverHandler  EPWM4_TZ_DriverHandler
                Set_Default_DriverHandler  EPWM5_TZ_DriverHandler
                Set_Default_DriverHandler  EPWM6_TZ_DriverHandler
                Set_Default_DriverHandler  EPWM7_TZ_DriverHandler
                Set_Default_DriverHandler  EPWM8_TZ_DriverHandler
                Set_Default_DriverHandler  EPWM9_TZ_DriverHandler
                Set_Default_DriverHandler  EPWM10_TZ_DriverHandler
                Set_Default_DriverHandler  EPWM11_TZ_DriverHandler
                Set_Default_DriverHandler  EPWM12_TZ_DriverHandler
                Set_Default_DriverHandler  EPWM1_DriverHandler
                Set_Default_DriverHandler  EPWM2_DriverHandler
                Set_Default_DriverHandler  EPWM3_DriverHandler
                Set_Default_DriverHandler  EPWM4_DriverHandler
                Set_Default_DriverHandler  EPWM5_DriverHandler
                Set_Default_DriverHandler  EPWM6_DriverHandler
                Set_Default_DriverHandler  EPWM7_DriverHandler
                Set_Default_DriverHandler  EPWM8_DriverHandler
                Set_Default_DriverHandler  EPWM9_DriverHandler
                Set_Default_DriverHandler  EPWM10_DriverHandler
                Set_Default_DriverHandler  EPWM11_DriverHandler
                Set_Default_DriverHandler  EPWM12_DriverHandler
                Set_Default_DriverHandler  ECAP1_DriverHandler
                Set_Default_DriverHandler  ECAP2_DriverHandler
                Set_Default_DriverHandler  ECAP3_DriverHandler
                Set_Default_DriverHandler  ECAP4_DriverHandler
                Set_Default_DriverHandler  ECAP5_DriverHandler
                Set_Default_DriverHandler  ECAP6_DriverHandler
                Set_Default_DriverHandler  EQEP1_DriverHandler
                Set_Default_DriverHandler  EQEP2_DriverHandler
                Set_Default_DriverHandler  EQEP3_DriverHandler
                Set_Default_DriverHandler  CLB1_DriverHandler
                Set_Default_DriverHandler  CLB2_DriverHandler
                Set_Default_DriverHandler  CLB3_DriverHandler
                Set_Default_DriverHandler  CLB4_DriverHandler
                Set_Default_DriverHandler  CLB5_DriverHandler
                Set_Default_DriverHandler  CLB6_DriverHandler
                Set_Default_DriverHandler  CLB7_DriverHandler
                Set_Default_DriverHandler  CLB8_DriverHandler
                Set_Default_DriverHandler  SDFM1_DriverHandler
                Set_Default_DriverHandler  SDFM1_FLT1DR_DriverHandler
                Set_Default_DriverHandler  SDFM1_FLT2DR_DriverHandler
                Set_Default_DriverHandler  SDFM1_FLT3DR_DriverHandler
                Set_Default_DriverHandler  SDFM1_FLT4DR_DriverHandler
                Set_Default_DriverHandler  SDFM2_DriverHandler
                Set_Default_DriverHandler  SDFM2_FLT1DR_DriverHandler
                Set_Default_DriverHandler  SDFM2_FLT2DR_DriverHandler
                Set_Default_DriverHandler  SDFM2_FLT3DR_DriverHandler
                Set_Default_DriverHandler  SDFM2_FLT4DR_DriverHandler
                Set_Default_DriverHandler  DMA_CH1_DriverHandler
                Set_Default_DriverHandler  DMA_CH2_DriverHandler
                Set_Default_DriverHandler  DMA_CH3_DriverHandler
                Set_Default_DriverHandler  DMA_CH4_DriverHandler
                Set_Default_DriverHandler  DMA_CH5_DriverHandler
                Set_Default_DriverHandler  DMA_CH6_DriverHandler
                Set_Default_DriverHandler  USBA_DriverHandler
                Set_Default_DriverHandler  USBA_EP_MP_DriverHandler
                Set_Default_DriverHandler  USBA_EP0_DriverHandler
                Set_Default_DriverHandler  USBA_EP1_DriverHandler
                Set_Default_DriverHandler  USBA_EP2_DriverHandler
                Set_Default_DriverHandler  USBA_EP3_DriverHandler
                Set_Default_DriverHandler  USBA_EP4_DriverHandler
                Set_Default_DriverHandler  USBA_EP5_DriverHandler
                Set_Default_DriverHandler  USBA_EP6_DriverHandler
                Set_Default_DriverHandler  USBA_EP7_DriverHandler
                Set_Default_DriverHandler  USBA_EP8_DriverHandler
                Set_Default_DriverHandler  USBA_EP9_DriverHandler
                Set_Default_DriverHandler  USBA_EP10_DriverHandler
                Set_Default_DriverHandler  USBA_EP11_DriverHandler
                Set_Default_DriverHandler  USBA_EP12_DriverHandler
                Set_Default_DriverHandler  USBA_EP13_DriverHandler
                Set_Default_DriverHandler  USBA_EP14_DriverHandler
                Set_Default_DriverHandler  USBA_EP15_DriverHandler
                Set_Default_DriverHandler  USBA_EP16_DriverHandler
                Set_Default_DriverHandler  USBA_EP17_DriverHandler
                Set_Default_DriverHandler  USBA_EP18_DriverHandler
                Set_Default_DriverHandler  USBA_EP19_DriverHandler
                Set_Default_DriverHandler  USBA_EP20_DriverHandler
                Set_Default_DriverHandler  USBA_EP21_DriverHandler
                Set_Default_DriverHandler  USBA_EP22_DriverHandler
                Set_Default_DriverHandler  USBA_EP23_DriverHandler
                Set_Default_DriverHandler  USBA_EP24_DriverHandler
                Set_Default_DriverHandler  USBA_EP25_DriverHandler
                Set_Default_DriverHandler  USBA_EP26_DriverHandler
                Set_Default_DriverHandler  USBA_EP27_DriverHandler
                Set_Default_DriverHandler  USBA_EP28_DriverHandler
                Set_Default_DriverHandler  USBA_EP29_DriverHandler
                Set_Default_DriverHandler  USBA_EP30_DriverHandler
                Set_Default_DriverHandler  USBA_EP31_DriverHandler
                Set_Default_DriverHandler  MCANA_INT0_DriverHandler
                Set_Default_DriverHandler  MCANA_INT1_DriverHandler
                Set_Default_DriverHandler  MCANB_INT0_DriverHandler
                Set_Default_DriverHandler  MCANB_INT1_DriverHandler
                Set_Default_DriverHandler  MCANC_INT0_DriverHandler
                Set_Default_DriverHandler  MCANC_INT1_DriverHandler
                Set_Default_DriverHandler  I2CA_DriverHandler
                Set_Default_DriverHandler  I2CB_DriverHandler
                Set_Default_DriverHandler  PMBUSA_DriverHandler
                Set_Default_DriverHandler  UARTA_DriverHandler
                Set_Default_DriverHandler  UARTB_DriverHandler
                Set_Default_DriverHandler  UARTC_DriverHandler
                Set_Default_DriverHandler  UARTD_DriverHandler
                Set_Default_DriverHandler  SPIA_DriverHandler
                Set_Default_DriverHandler  SPIB_DriverHandler
                Set_Default_DriverHandler  SPIC_DriverHandler
                Set_Default_DriverHandler  SRAM_ECC_ERR_DriverHandler
                Set_Default_DriverHandler  EFLASH_DriverHandler
                Set_Default_DriverHandler  SRAM_ACC_VIO_DriverHandler
                Set_Default_DriverHandler  EMIF1_ERR_DriverHandler
                Set_Default_DriverHandler  WAKEUP_DriverHandler
                Set_Default_DriverHandler  TFU_DriverHandler
                Set_Default_DriverHandler  IPC_RAM_ERR_DriverHandler

                .end
