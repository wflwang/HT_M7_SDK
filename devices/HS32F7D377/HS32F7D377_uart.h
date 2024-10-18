/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


/*!
 * \file   HS32F7D377_uart.h
 * \brief  HS32F7D377 UART register file
 * \version V1.0_20231008
 */

#ifndef HS32F7D377_UART_H
#define HS32F7D377_UART_H

/*!
 * \addtogroup   HS32F7D377_UART_REGISTER HS32F7D377 UART Register
 * \ingroup HS32F7D377_REGISTER
 *
 * \brief  UART register layout, bitfield and address definitions
 *
 * @{
 */

/* clang-format off */

/*!
 * \name UART Register Layout
 *
 *
 * @{
 */

/*! \brief UART register layout */
typedef struct {
    union /*!< share_reg_0_begin */ /*!< 0x00000000 */
    {
        union
        {
            __IM  uint32_t RBR                               ;  /*!< 0x00000000 : Receive Buffer Register */
        
            struct
            {
                __IM  uint32_t RBR                       : 8 ;  /*!< [ 7: 0] : Receive Buffer Register. */
                      uint32_t RSV_0                     : 24;  /*!< [31: 8] : reserved. */
            } RBRb;
        };

        union
        {
            __IOM uint32_t DLL                               ;  /*!< 0x00000000 : Divisor Latch Low */
        
            struct
            {
                __IOM uint32_t DLL                       : 8 ;  /*!< [ 7: 0] : Divisor Latch Low. */
                      uint32_t RSV_0                     : 24;  /*!< [31: 8] : reserved. */
            } DLLb;
        };

        union
        {
            __IOM uint32_t THR                               ;  /*!< 0x00000000 : Transmit Holding Register */
        
            struct
            {
                __OM  uint32_t THR                       : 8 ;  /*!< [ 7: 0] : Transmit Holding Register. */
                      uint32_t RSV_0                     : 24;  /*!< [31: 8] : reserved. */
            } THRb;
        };

    }; /*!< share_reg_0_end */

    union /*!< share_reg_1_begin */ /*!< 0x00000004 */
    {
        union
        {
            __IOM uint32_t DLH                               ;  /*!< 0x00000004 : Divisor Latch High */
        
            struct
            {
                __IOM uint32_t DLH                       : 8 ;  /*!< [ 7: 0] : Divisor Latch High. */
                      uint32_t RSV_0                     : 24;  /*!< [31: 8] : reserved. */
            } DLHb;
        };

        union
        {
            __IOM uint32_t IER                               ;  /*!< 0x00000004 : Interrupt Enable Register */
        
            struct
            {
                __IOM uint32_t ERBFI                     : 1 ;  /*!< [ 0: 0] : Enable Received Data Available Interrupt. */
                __IOM uint32_t ETBEI                     : 1 ;  /*!< [ 1: 1] : Enable Transmit Holding Register Empty Interrupt. */
                __IOM uint32_t ELSI                      : 1 ;  /*!< [ 2: 2] : Enable Receiver Line Status Interrupt. */
                __IOM uint32_t EDSSI                     : 1 ;  /*!< [ 3: 3] : Enable Modem Status Interrupt. */
                __IM  uint32_t ELCOLR                    : 1 ;  /*!< [ 4: 4] : Enable LSR Clear Only on LSR Reading. */
                      uint32_t RSV_0                     : 2 ;  /*!< [ 6: 5] : reserved. */
                __IOM uint32_t PTIME                     : 1 ;  /*!< [ 7: 7] : Programmable THRE Interrupt Mode Enable. */
                      uint32_t RSV_1                     : 24;  /*!< [31: 8] : reserved. */
            } IERb;
        };

    }; /*!< share_reg_1_end */

    union /*!< share_reg_2_begin */ /*!< 0x00000008 */
    {
        union
        {
            __IOM uint32_t FCR                               ;  /*!< 0x00000008 : FIFO Control Register */
        
            struct
            {
                __OM  uint32_t FIFOE                     : 1 ;  /*!< [ 0: 0] : FIFO Enable. */
                __OM  uint32_t RFIFOR                    : 1 ;  /*!< [ 1: 1] : RCVR FIFO Reset. */
                __OM  uint32_t XFIFOR                    : 1 ;  /*!< [ 2: 2] : XMIT FIFO Reset. */
                      uint32_t RSV_0                     : 1 ;  /*!< [ 3: 3] : reserved. */
                __OM  uint32_t TET                       : 2 ;  /*!< [ 5: 4] : TX Empty Trigger.
                                                                               - 0x0: FIFO Empty
                                                                               - 0x1: 2 characters in FIFO
                                                                               - 0x2: FIFO 1/4 full
                                                                               - 0x3: FIFO 1/2 full */
                __OM  uint32_t RT                        : 2 ;  /*!< [ 7: 6] : RCVR Trigger.
                                                                               - 0x0: 1 character in FIFO
                                                                               - 0x1: FIFO 1/4 full
                                                                               - 0x2: FIFO 1/2 full
                                                                               - 0x3: FIFO 2 less than full */
                      uint32_t RSV_1                     : 24;  /*!< [31: 8] : reserved. */
            } FCRb;
        };

        union
        {
            __IM  uint32_t IIR                               ;  /*!< 0x00000008 : Interrupt Identification Register */
        
            struct
            {
                __IM  uint32_t IID                       : 4 ;  /*!< [ 3: 0] : Interrupt ID. */
                      uint32_t RSV_0                     : 2 ;  /*!< [ 5: 4] : reserved. */
                __IM  uint32_t FIFOSE                    : 2 ;  /*!< [ 7: 6] : FIFOs Enabled. */
                      uint32_t RSV_1                     : 24;  /*!< [31: 8] : reserved. */
            } IIRb;
        };

    }; /*!< share_reg_2_end */

    union
    {
        __IOM uint32_t LCR                               ;  /*!< 0x0000000c : Line Control Register */
    
        struct
        {
            __IOM uint32_t DLS                       : 2 ;  /*!< [ 1: 0] : Data Length Select (or CLS as used in legacy). */
            __IOM uint32_t STOP                      : 1 ;  /*!< [ 2: 2] : Number of stop bits. */
            __IOM uint32_t PEN                       : 1 ;  /*!< [ 3: 3] : Parity Enable. */
            __IOM uint32_t EPS                       : 1 ;  /*!< [ 4: 4] : Even Parity Select. */
            __IOM uint32_t SP                        : 1 ;  /*!< [ 5: 5] : Stick Parity. */
            __IOM uint32_t BC                        : 1 ;  /*!< [ 6: 6] : Break Control Bit. */
            __IOM uint32_t DLAB                      : 1 ;  /*!< [ 7: 7] : Divisor Latch Access Bit. */
                  uint32_t RSV_0                     : 24;  /*!< [31: 8] : reserved. */
        } LCRb;
    };

    union
    {
        __IOM uint32_t MCR                               ;  /*!< 0x00000010 : Modem Control Register */
    
        struct
        {
            __IOM uint32_t DTR                       : 1 ;  /*!< [ 0: 0] : Data Terminal Ready. */
            __IOM uint32_t RTS                       : 1 ;  /*!< [ 1: 1] : Request to Send. */
            __IOM uint32_t OUT1                      : 1 ;  /*!< [ 2: 2] : OUT1. */
            __IOM uint32_t OUT2                      : 1 ;  /*!< [ 3: 3] : OUT2. */
            __IOM uint32_t LOOP_BACK                 : 1 ;  /*!< [ 4: 4] : LoopBack. */
                  uint32_t RSV_0                     : 27;  /*!< [31: 5] : reserved. */
        } MCRb;
    };

    union
    {
        __IM  uint32_t LSR                               ;  /*!< 0x00000014 : Line Status Register */
    
        struct
        {
            __IM  uint32_t DR                        : 1 ;  /*!< [ 0: 0] : Data Ready. */
            __IM  uint32_t OE                        : 1 ;  /*!< [ 1: 1] : Overrun error. */
            __IM  uint32_t PE                        : 1 ;  /*!< [ 2: 2] : Parity Error. */
            __IM  uint32_t FE                        : 1 ;  /*!< [ 3: 3] : Framing Error. */
            __IM  uint32_t BI                        : 1 ;  /*!< [ 4: 4] : Break Interrupt. */
            __IM  uint32_t THRE                      : 1 ;  /*!< [ 5: 5] : Transmit Holding Register Empty. */
            __IM  uint32_t TEMT                      : 1 ;  /*!< [ 6: 6] : Transmitter Empty. */
            __IM  uint32_t RFE                       : 1 ;  /*!< [ 7: 7] : Receiver FIFO Error. */
                  uint32_t RSV_0                     : 24;  /*!< [31: 8] : reserved. */
        } LSRb;
    };

    union
    {
        __IM  uint32_t MSR                               ;  /*!< 0x00000018 : Modem Status Register */
    
        struct
        {
            __IM  uint32_t DCTS                      : 1 ;  /*!< [ 0: 0] : Delta Clear to Send. */
            __IM  uint32_t DDSR                      : 1 ;  /*!< [ 1: 1] : Delta Data Set Ready. */
            __IM  uint32_t TERI                      : 1 ;  /*!< [ 2: 2] : Trailing Edge of Ring Indicator. */
            __IM  uint32_t DDCD                      : 1 ;  /*!< [ 3: 3] : Delta Data Carrier Detect. */
            __IM  uint32_t CTS                       : 1 ;  /*!< [ 4: 4] : Clear to Send. */
            __IM  uint32_t DSR                       : 1 ;  /*!< [ 5: 5] : Data Set Ready. */
            __IM  uint32_t RI                        : 1 ;  /*!< [ 6: 6] : Ring Indicator. */
            __IM  uint32_t DCD                       : 1 ;  /*!< [ 7: 7] : Data Carrier Detect. */
                  uint32_t RSV_0                     : 24;  /*!< [31: 8] : reserved. */
        } MSRb;
    };

    union
    {
        __IOM uint32_t SCR                               ;  /*!< 0x0000001c : Scratchpad Register */
    
        struct
        {
            __IOM uint32_t SCR                       : 8 ;  /*!< [ 7: 0] : Scratchpad Register. */
                  uint32_t RSV_0                     : 24;  /*!< [31: 8] : reserved. */
        } SCRb;
    };

    uint8_t    RSV_0X20[80]                              ;  /*!< 0x00000020~0x0000006f : reserved */

    union
    {
        __IOM uint32_t FAR                               ;  /*!< 0x00000070 : FIFO Access Register Enable */
    
        struct
        {
            __IOM uint32_t FAR                       : 1 ;  /*!< [ 0: 0] : FIFO Access Register Enable. */
                  uint32_t RSV_0                     : 31;  /*!< [31: 1] : reserved. */
        } FARb;
    };

    union
    {
        __IM  uint32_t TFR                               ;  /*!< 0x00000074 : Transmit FIFO Read */
    
        struct
        {
            __IM  uint32_t TFR                       : 8 ;  /*!< [ 7: 0] : Transmit FIFO Read. */
                  uint32_t RSV_0                     : 24;  /*!< [31: 8] : reserved. */
        } TFRb;
    };

    union
    {
        __IOM uint32_t RFW                               ;  /*!< 0x00000078 : Receive FIFO Write */
    
        struct
        {
            __OM  uint32_t RFWD                      : 8 ;  /*!< [ 7: 0] : Receive FIFO Write Data. */
            __OM  uint32_t RFPE                      : 1 ;  /*!< [ 8: 8] : Receive FIFO Parity Error. */
            __OM  uint32_t RFFE                      : 1 ;  /*!< [ 9: 9] : Receive FIFO Framing Error. */
                  uint32_t RSV_0                     : 22;  /*!< [31:10] : reserved. */
        } RFWb;
    };

    union
    {
        __IM  uint32_t USR                               ;  /*!< 0x0000007c : UART Status register */
    
        struct
        {
            __IM  uint32_t BUSY                      : 1 ;  /*!< [ 0: 0] : UART Busy. */
            __IM  uint32_t TFNF                      : 1 ;  /*!< [ 1: 1] : Transmit FIFO Not Full. */
            __IM  uint32_t TFE                       : 1 ;  /*!< [ 2: 2] : Transmit FIFO Empty. */
            __IM  uint32_t RFNE                      : 1 ;  /*!< [ 3: 3] : Receive FIFO Not Empty. */
            __IM  uint32_t RFF                       : 1 ;  /*!< [ 4: 4] : Receive FIFO Full. */
                  uint32_t RSV_0                     : 27;  /*!< [31: 5] : reserved. */
        } USRb;
    };

    union
    {
        __IM  uint32_t TFL                               ;  /*!< 0x00000080 : Transmit FIFO Level */
    
        struct
        {
            __IM  uint32_t TFL                       : 8 ;  /*!< [ 7: 0] : Transmit FIFO Level. */
                  uint32_t RSV_0                     : 24;  /*!< [31: 8] : reserved. */
        } TFLb;
    };

    union
    {
        __IM  uint32_t RFL                               ;  /*!< 0x00000084 : Receive FIFO Level */
    
        struct
        {
            __IM  uint32_t RFL                       : 8 ;  /*!< [ 7: 0] : Receive FIFO Level. */
                  uint32_t RSV_0                     : 24;  /*!< [31: 8] : reserved. */
        } RFLb;
    };

    uint8_t    RSV_0X88[28]                              ;  /*!< 0x00000088~0x000000a3 : reserved */

    union
    {
        __IOM uint32_t HTX                               ;  /*!< 0x000000a4 : Halt TX */
    
        struct
        {
            __IOM uint32_t HTX                       : 1 ;  /*!< [ 0: 0] : Halt TX. */
                  uint32_t RSV_0                     : 31;  /*!< [31: 1] : reserved. */
        } HTXb;
    };

    uint8_t    RSV_0XA8[4]                               ;  /*!< 0x000000a8~0x000000ab : reserved */

    union
    {
        __IOM uint32_t TCR                               ;  /*!< 0x000000ac : Transceiver Control Register */
    
        struct
        {
            __IOM uint32_t RS485_EN                  : 1 ;  /*!< [ 0: 0] : RS485 Transfer Enable. */
            __IOM uint32_t RE_POL                    : 1 ;  /*!< [ 1: 1] : Receiver Enable Polarity. */
            __IOM uint32_t DE_POL                    : 1 ;  /*!< [ 2: 2] : Driver Enable Polarity. */
            __IOM uint32_t XFER_MODE                 : 2 ;  /*!< [ 4: 3] : Transfer Mode. */
                  uint32_t RSV_0                     : 27;  /*!< [31: 5] : reserved. */
        } TCRb;
    };

    union
    {
        __IOM uint32_t DE_EN                             ;  /*!< 0x000000b0 : Driver Output Enable Register */
    
        struct
        {
            __IOM uint32_t DE_ENABLE                 : 1 ;  /*!< [ 0: 0] : DE Enable Control. */
                  uint32_t RSV_0                     : 31;  /*!< [31: 1] : reserved. */
        } DE_ENb;
    };

    union
    {
        __IOM uint32_t RE_EN                             ;  /*!< 0x000000b4 : Receiver Output Enable Register */
    
        struct
        {
            __IOM uint32_t RE_ENABLE                 : 1 ;  /*!< [ 0: 0] : RE Enable Control. */
                  uint32_t RSV_0                     : 31;  /*!< [31: 1] : reserved. */
        } RE_ENb;
    };

    union
    {
        __IOM uint32_t DET                               ;  /*!< 0x000000b8 : Driver Output Enable Timing */
    
        struct
        {
            __IOM uint32_t DE_ASSERTION_TIME         : 8 ;  /*!< [ 7: 0] : Driver Enable assertion Time. */
                  uint32_t RSV_0                     : 8 ;  /*!< [15: 8] : reserved. */
            __IOM uint32_t DE_DE_ASSERTION_TIME      : 8 ;  /*!< [23:16] : Driver Enable de-assertion Time. */
                  uint32_t RSV_1                     : 8 ;  /*!< [31:24] : reserved. */
        } DETb;
    };

    union
    {
        __IOM uint32_t TAT                               ;  /*!< 0x000000bc : TurnAround Timing Register */
    
        struct
        {
            __IOM uint32_t DE_TO_RE                  : 16;  /*!< [15: 0] : Driver Enable to Receiver Enable TurnAround Time. */
            __IOM uint32_t RE_TO_DE                  : 16;  /*!< [31:16] : Receiver Enable to Driver Enable TurnAround Time. */
        } TATb;
    };

    uint8_t    RSV_0XC0[56]                              ;  /*!< 0x000000c0~0x000000f7 : reserved */

    union
    {
        __IM  uint32_t UCV                               ;  /*!< 0x000000f8 : UART Component Version */
    
        struct
        {
            __IM  uint32_t UART_COMPONENT_VERSION    : 32;  /*!< [31: 0] : UART Component Version. */
        } UCVb;
    };

    union
    {
        __IM  uint32_t CTR                               ;  /*!< 0x000000fc : Component Type Register */
    
        struct
        {
            __IM  uint32_t PERIPHERAL_ID             : 32;  /*!< [31: 0] : Peripheral ID. */
        } CTRb;
    };

} UART_Type;

/*!
 * @}
 */

/*!
 * \name UART Base Address Definitions
 *
 * @{
 */

/*! \brief UARTA base address */
#define UARTA_BASE (0x42200000UL)
/*! \brief UARTB base address */
#define UARTB_BASE (0x42201000UL)
/*! \brief UARTC base address */
#define UARTC_BASE (0x42202000UL)
/*! \brief UARTD base address */
#define UARTD_BASE (0x42203000UL)
/*! \brief UARTA base pointer */
#define UARTA ((UART_Type *) UARTA_BASE)
/*! \brief UARTB base pointer */
#define UARTB ((UART_Type *) UARTB_BASE)
/*! \brief UARTC base pointer */
#define UARTC ((UART_Type *) UARTC_BASE)
/*! \brief UARTD base pointer */
#define UARTD ((UART_Type *) UARTD_BASE)

/*!
 * @}
 */


/*!
 * \name UART Register Bitfield Definitions
 *
 * @{
 */

/* RBR bitfield */
#define UART_RBR_RBR_Pos     (0U)                                                        /*!< RBR Position 0 */
#define UART_RBR_RBR_Msk     (0xffU << UART_RBR_RBR_Pos)                                 /*!< RBR Mask 0x000000FF */
#define UART_RBR_RBR_Set(x)  (((uint32_t) (x) << UART_RBR_RBR_Pos) & UART_RBR_RBR_Msk)   /*!< RBR Set Value */
#define UART_RBR_RBR_Get(x)  (((uint32_t) (x) & UART_RBR_RBR_Msk) >> UART_RBR_RBR_Pos)   /*!< RBR Get Value */

/* DLL bitfield */
#define UART_DLL_DLL_Pos     (0U)                                                        /*!< DLL Position 0 */
#define UART_DLL_DLL_Msk     (0xffU << UART_DLL_DLL_Pos)                                 /*!< DLL Mask 0x000000FF */
#define UART_DLL_DLL_Set(x)  (((uint32_t) (x) << UART_DLL_DLL_Pos) & UART_DLL_DLL_Msk)   /*!< DLL Set Value */
#define UART_DLL_DLL_Get(x)  (((uint32_t) (x) & UART_DLL_DLL_Msk) >> UART_DLL_DLL_Pos)   /*!< DLL Get Value */

/* THR bitfield */
#define UART_THR_THR_Pos     (0U)                                                        /*!< THR Position 0 */
#define UART_THR_THR_Msk     (0xffU << UART_THR_THR_Pos)                                 /*!< THR Mask 0x000000FF */
#define UART_THR_THR_Set(x)  (((uint32_t) (x) << UART_THR_THR_Pos) & UART_THR_THR_Msk)   /*!< THR Set Value */
#define UART_THR_THR_Get(x)  (((uint32_t) (x) & UART_THR_THR_Msk) >> UART_THR_THR_Pos)   /*!< THR Get Value */

/* DLH bitfield */
#define UART_DLH_DLH_Pos     (0U)                                                        /*!< DLH Position 0 */
#define UART_DLH_DLH_Msk     (0xffU << UART_DLH_DLH_Pos)                                 /*!< DLH Mask 0x000000FF */
#define UART_DLH_DLH_Set(x)  (((uint32_t) (x) << UART_DLH_DLH_Pos) & UART_DLH_DLH_Msk)   /*!< DLH Set Value */
#define UART_DLH_DLH_Get(x)  (((uint32_t) (x) & UART_DLH_DLH_Msk) >> UART_DLH_DLH_Pos)   /*!< DLH Get Value */

/* IER bitfield */
#define UART_IER_PTIME_Pos     (7U)                                                            /*!< PTIME Position 7 */
#define UART_IER_PTIME_Msk     (0x1U << UART_IER_PTIME_Pos)                                    /*!< PTIME Mask 0x00000080 */
#define UART_IER_PTIME_Set(x)  (((uint32_t) (x) << UART_IER_PTIME_Pos) & UART_IER_PTIME_Msk)   /*!< PTIME Set Value */
#define UART_IER_PTIME_Get(x)  (((uint32_t) (x) & UART_IER_PTIME_Msk) >> UART_IER_PTIME_Pos)   /*!< PTIME Get Value */

#define UART_IER_ELCOLR_Pos     (4U)                                                              /*!< ELCOLR Position 4 */
#define UART_IER_ELCOLR_Msk     (0x1U << UART_IER_ELCOLR_Pos)                                     /*!< ELCOLR Mask 0x00000010 */
#define UART_IER_ELCOLR_Set(x)  (((uint32_t) (x) << UART_IER_ELCOLR_Pos) & UART_IER_ELCOLR_Msk)   /*!< ELCOLR Set Value */
#define UART_IER_ELCOLR_Get(x)  (((uint32_t) (x) & UART_IER_ELCOLR_Msk) >> UART_IER_ELCOLR_Pos)   /*!< ELCOLR Get Value */

#define UART_IER_EDSSI_Pos     (3U)                                                            /*!< EDSSI Position 3 */
#define UART_IER_EDSSI_Msk     (0x1U << UART_IER_EDSSI_Pos)                                    /*!< EDSSI Mask 0x00000008 */
#define UART_IER_EDSSI_Set(x)  (((uint32_t) (x) << UART_IER_EDSSI_Pos) & UART_IER_EDSSI_Msk)   /*!< EDSSI Set Value */
#define UART_IER_EDSSI_Get(x)  (((uint32_t) (x) & UART_IER_EDSSI_Msk) >> UART_IER_EDSSI_Pos)   /*!< EDSSI Get Value */

#define UART_IER_ELSI_Pos     (2U)                                                          /*!< ELSI Position 2 */
#define UART_IER_ELSI_Msk     (0x1U << UART_IER_ELSI_Pos)                                   /*!< ELSI Mask 0x00000004 */
#define UART_IER_ELSI_Set(x)  (((uint32_t) (x) << UART_IER_ELSI_Pos) & UART_IER_ELSI_Msk)   /*!< ELSI Set Value */
#define UART_IER_ELSI_Get(x)  (((uint32_t) (x) & UART_IER_ELSI_Msk) >> UART_IER_ELSI_Pos)   /*!< ELSI Get Value */

#define UART_IER_ETBEI_Pos     (1U)                                                            /*!< ETBEI Position 1 */
#define UART_IER_ETBEI_Msk     (0x1U << UART_IER_ETBEI_Pos)                                    /*!< ETBEI Mask 0x00000002 */
#define UART_IER_ETBEI_Set(x)  (((uint32_t) (x) << UART_IER_ETBEI_Pos) & UART_IER_ETBEI_Msk)   /*!< ETBEI Set Value */
#define UART_IER_ETBEI_Get(x)  (((uint32_t) (x) & UART_IER_ETBEI_Msk) >> UART_IER_ETBEI_Pos)   /*!< ETBEI Get Value */

#define UART_IER_ERBFI_Pos     (0U)                                                            /*!< ERBFI Position 0 */
#define UART_IER_ERBFI_Msk     (0x1U << UART_IER_ERBFI_Pos)                                    /*!< ERBFI Mask 0x00000001 */
#define UART_IER_ERBFI_Set(x)  (((uint32_t) (x) << UART_IER_ERBFI_Pos) & UART_IER_ERBFI_Msk)   /*!< ERBFI Set Value */
#define UART_IER_ERBFI_Get(x)  (((uint32_t) (x) & UART_IER_ERBFI_Msk) >> UART_IER_ERBFI_Pos)   /*!< ERBFI Get Value */

/* FCR bitfield */
#define UART_FCR_RT_Pos     (6U)                                                      /*!< RT Position 6 */
#define UART_FCR_RT_Msk     (0x3U << UART_FCR_RT_Pos)                                 /*!< RT Mask 0x000000C0 */
#define UART_FCR_RT_Set(x)  (((uint32_t) (x) << UART_FCR_RT_Pos) & UART_FCR_RT_Msk)   /*!< RT Set Value */
#define UART_FCR_RT_Get(x)  (((uint32_t) (x) & UART_FCR_RT_Msk) >> UART_FCR_RT_Pos)   /*!< RT Get Value */

#define UART_FCR_TET_Pos     (4U)                                                        /*!< TET Position 4 */
#define UART_FCR_TET_Msk     (0x3U << UART_FCR_TET_Pos)                                  /*!< TET Mask 0x00000030 */
#define UART_FCR_TET_Set(x)  (((uint32_t) (x) << UART_FCR_TET_Pos) & UART_FCR_TET_Msk)   /*!< TET Set Value */
#define UART_FCR_TET_Get(x)  (((uint32_t) (x) & UART_FCR_TET_Msk) >> UART_FCR_TET_Pos)   /*!< TET Get Value */

#define UART_FCR_XFIFOR_Pos     (2U)                                                              /*!< XFIFOR Position 2 */
#define UART_FCR_XFIFOR_Msk     (0x1U << UART_FCR_XFIFOR_Pos)                                     /*!< XFIFOR Mask 0x00000004 */
#define UART_FCR_XFIFOR_Set(x)  (((uint32_t) (x) << UART_FCR_XFIFOR_Pos) & UART_FCR_XFIFOR_Msk)   /*!< XFIFOR Set Value */
#define UART_FCR_XFIFOR_Get(x)  (((uint32_t) (x) & UART_FCR_XFIFOR_Msk) >> UART_FCR_XFIFOR_Pos)   /*!< XFIFOR Get Value */

#define UART_FCR_RFIFOR_Pos     (1U)                                                              /*!< RFIFOR Position 1 */
#define UART_FCR_RFIFOR_Msk     (0x1U << UART_FCR_RFIFOR_Pos)                                     /*!< RFIFOR Mask 0x00000002 */
#define UART_FCR_RFIFOR_Set(x)  (((uint32_t) (x) << UART_FCR_RFIFOR_Pos) & UART_FCR_RFIFOR_Msk)   /*!< RFIFOR Set Value */
#define UART_FCR_RFIFOR_Get(x)  (((uint32_t) (x) & UART_FCR_RFIFOR_Msk) >> UART_FCR_RFIFOR_Pos)   /*!< RFIFOR Get Value */

#define UART_FCR_FIFOE_Pos     (0U)                                                            /*!< FIFOE Position 0 */
#define UART_FCR_FIFOE_Msk     (0x1U << UART_FCR_FIFOE_Pos)                                    /*!< FIFOE Mask 0x00000001 */
#define UART_FCR_FIFOE_Set(x)  (((uint32_t) (x) << UART_FCR_FIFOE_Pos) & UART_FCR_FIFOE_Msk)   /*!< FIFOE Set Value */
#define UART_FCR_FIFOE_Get(x)  (((uint32_t) (x) & UART_FCR_FIFOE_Msk) >> UART_FCR_FIFOE_Pos)   /*!< FIFOE Get Value */

/* IIR bitfield */
#define UART_IIR_FIFOSE_Pos     (6U)                                                              /*!< FIFOSE Position 6 */
#define UART_IIR_FIFOSE_Msk     (0x3U << UART_IIR_FIFOSE_Pos)                                     /*!< FIFOSE Mask 0x000000C0 */
#define UART_IIR_FIFOSE_Set(x)  (((uint32_t) (x) << UART_IIR_FIFOSE_Pos) & UART_IIR_FIFOSE_Msk)   /*!< FIFOSE Set Value */
#define UART_IIR_FIFOSE_Get(x)  (((uint32_t) (x) & UART_IIR_FIFOSE_Msk) >> UART_IIR_FIFOSE_Pos)   /*!< FIFOSE Get Value */

#define UART_IIR_IID_Pos     (0U)                                                        /*!< IID Position 0 */
#define UART_IIR_IID_Msk     (0xfU << UART_IIR_IID_Pos)                                  /*!< IID Mask 0x0000000F */
#define UART_IIR_IID_Set(x)  (((uint32_t) (x) << UART_IIR_IID_Pos) & UART_IIR_IID_Msk)   /*!< IID Set Value */
#define UART_IIR_IID_Get(x)  (((uint32_t) (x) & UART_IIR_IID_Msk) >> UART_IIR_IID_Pos)   /*!< IID Get Value */

/* LCR bitfield */
#define UART_LCR_DLAB_Pos     (7U)                                                          /*!< DLAB Position 7 */
#define UART_LCR_DLAB_Msk     (0x1U << UART_LCR_DLAB_Pos)                                   /*!< DLAB Mask 0x00000080 */
#define UART_LCR_DLAB_Set(x)  (((uint32_t) (x) << UART_LCR_DLAB_Pos) & UART_LCR_DLAB_Msk)   /*!< DLAB Set Value */
#define UART_LCR_DLAB_Get(x)  (((uint32_t) (x) & UART_LCR_DLAB_Msk) >> UART_LCR_DLAB_Pos)   /*!< DLAB Get Value */

#define UART_LCR_BC_Pos     (6U)                                                      /*!< BC Position 6 */
#define UART_LCR_BC_Msk     (0x1U << UART_LCR_BC_Pos)                                 /*!< BC Mask 0x00000040 */
#define UART_LCR_BC_Set(x)  (((uint32_t) (x) << UART_LCR_BC_Pos) & UART_LCR_BC_Msk)   /*!< BC Set Value */
#define UART_LCR_BC_Get(x)  (((uint32_t) (x) & UART_LCR_BC_Msk) >> UART_LCR_BC_Pos)   /*!< BC Get Value */

#define UART_LCR_SP_Pos     (5U)                                                      /*!< SP Position 5 */
#define UART_LCR_SP_Msk     (0x1U << UART_LCR_SP_Pos)                                 /*!< SP Mask 0x00000020 */
#define UART_LCR_SP_Set(x)  (((uint32_t) (x) << UART_LCR_SP_Pos) & UART_LCR_SP_Msk)   /*!< SP Set Value */
#define UART_LCR_SP_Get(x)  (((uint32_t) (x) & UART_LCR_SP_Msk) >> UART_LCR_SP_Pos)   /*!< SP Get Value */

#define UART_LCR_EPS_Pos     (4U)                                                        /*!< EPS Position 4 */
#define UART_LCR_EPS_Msk     (0x1U << UART_LCR_EPS_Pos)                                  /*!< EPS Mask 0x00000010 */
#define UART_LCR_EPS_Set(x)  (((uint32_t) (x) << UART_LCR_EPS_Pos) & UART_LCR_EPS_Msk)   /*!< EPS Set Value */
#define UART_LCR_EPS_Get(x)  (((uint32_t) (x) & UART_LCR_EPS_Msk) >> UART_LCR_EPS_Pos)   /*!< EPS Get Value */

#define UART_LCR_PEN_Pos     (3U)                                                        /*!< PEN Position 3 */
#define UART_LCR_PEN_Msk     (0x1U << UART_LCR_PEN_Pos)                                  /*!< PEN Mask 0x00000008 */
#define UART_LCR_PEN_Set(x)  (((uint32_t) (x) << UART_LCR_PEN_Pos) & UART_LCR_PEN_Msk)   /*!< PEN Set Value */
#define UART_LCR_PEN_Get(x)  (((uint32_t) (x) & UART_LCR_PEN_Msk) >> UART_LCR_PEN_Pos)   /*!< PEN Get Value */

#define UART_LCR_STOP_Pos     (2U)                                                          /*!< STOP Position 2 */
#define UART_LCR_STOP_Msk     (0x1U << UART_LCR_STOP_Pos)                                   /*!< STOP Mask 0x00000004 */
#define UART_LCR_STOP_Set(x)  (((uint32_t) (x) << UART_LCR_STOP_Pos) & UART_LCR_STOP_Msk)   /*!< STOP Set Value */
#define UART_LCR_STOP_Get(x)  (((uint32_t) (x) & UART_LCR_STOP_Msk) >> UART_LCR_STOP_Pos)   /*!< STOP Get Value */

#define UART_LCR_DLS_Pos     (0U)                                                        /*!< DLS Position 0 */
#define UART_LCR_DLS_Msk     (0x3U << UART_LCR_DLS_Pos)                                  /*!< DLS Mask 0x00000003 */
#define UART_LCR_DLS_Set(x)  (((uint32_t) (x) << UART_LCR_DLS_Pos) & UART_LCR_DLS_Msk)   /*!< DLS Set Value */
#define UART_LCR_DLS_Get(x)  (((uint32_t) (x) & UART_LCR_DLS_Msk) >> UART_LCR_DLS_Pos)   /*!< DLS Get Value */

/* MCR bitfield */
#define UART_MCR_LOOP_BACK_Pos     (4U)                                                                    /*!< LOOP_BACK Position 4 */
#define UART_MCR_LOOP_BACK_Msk     (0x1U << UART_MCR_LOOP_BACK_Pos)                                        /*!< LOOP_BACK Mask 0x00000010 */
#define UART_MCR_LOOP_BACK_Set(x)  (((uint32_t) (x) << UART_MCR_LOOP_BACK_Pos) & UART_MCR_LOOP_BACK_Msk)   /*!< LOOP_BACK Set Value */
#define UART_MCR_LOOP_BACK_Get(x)  (((uint32_t) (x) & UART_MCR_LOOP_BACK_Msk) >> UART_MCR_LOOP_BACK_Pos)   /*!< LOOP_BACK Get Value */

#define UART_MCR_OUT2_Pos     (3U)                                                          /*!< OUT2 Position 3 */
#define UART_MCR_OUT2_Msk     (0x1U << UART_MCR_OUT2_Pos)                                   /*!< OUT2 Mask 0x00000008 */
#define UART_MCR_OUT2_Set(x)  (((uint32_t) (x) << UART_MCR_OUT2_Pos) & UART_MCR_OUT2_Msk)   /*!< OUT2 Set Value */
#define UART_MCR_OUT2_Get(x)  (((uint32_t) (x) & UART_MCR_OUT2_Msk) >> UART_MCR_OUT2_Pos)   /*!< OUT2 Get Value */

#define UART_MCR_OUT1_Pos     (2U)                                                          /*!< OUT1 Position 2 */
#define UART_MCR_OUT1_Msk     (0x1U << UART_MCR_OUT1_Pos)                                   /*!< OUT1 Mask 0x00000004 */
#define UART_MCR_OUT1_Set(x)  (((uint32_t) (x) << UART_MCR_OUT1_Pos) & UART_MCR_OUT1_Msk)   /*!< OUT1 Set Value */
#define UART_MCR_OUT1_Get(x)  (((uint32_t) (x) & UART_MCR_OUT1_Msk) >> UART_MCR_OUT1_Pos)   /*!< OUT1 Get Value */

#define UART_MCR_RTS_Pos     (1U)                                                        /*!< RTS Position 1 */
#define UART_MCR_RTS_Msk     (0x1U << UART_MCR_RTS_Pos)                                  /*!< RTS Mask 0x00000002 */
#define UART_MCR_RTS_Set(x)  (((uint32_t) (x) << UART_MCR_RTS_Pos) & UART_MCR_RTS_Msk)   /*!< RTS Set Value */
#define UART_MCR_RTS_Get(x)  (((uint32_t) (x) & UART_MCR_RTS_Msk) >> UART_MCR_RTS_Pos)   /*!< RTS Get Value */

#define UART_MCR_DTR_Pos     (0U)                                                        /*!< DTR Position 0 */
#define UART_MCR_DTR_Msk     (0x1U << UART_MCR_DTR_Pos)                                  /*!< DTR Mask 0x00000001 */
#define UART_MCR_DTR_Set(x)  (((uint32_t) (x) << UART_MCR_DTR_Pos) & UART_MCR_DTR_Msk)   /*!< DTR Set Value */
#define UART_MCR_DTR_Get(x)  (((uint32_t) (x) & UART_MCR_DTR_Msk) >> UART_MCR_DTR_Pos)   /*!< DTR Get Value */

/* LSR bitfield */
#define UART_LSR_RFE_Pos     (7U)                                                        /*!< RFE Position 7 */
#define UART_LSR_RFE_Msk     (0x1U << UART_LSR_RFE_Pos)                                  /*!< RFE Mask 0x00000080 */
#define UART_LSR_RFE_Set(x)  (((uint32_t) (x) << UART_LSR_RFE_Pos) & UART_LSR_RFE_Msk)   /*!< RFE Set Value */
#define UART_LSR_RFE_Get(x)  (((uint32_t) (x) & UART_LSR_RFE_Msk) >> UART_LSR_RFE_Pos)   /*!< RFE Get Value */

#define UART_LSR_TEMT_Pos     (6U)                                                          /*!< TEMT Position 6 */
#define UART_LSR_TEMT_Msk     (0x1U << UART_LSR_TEMT_Pos)                                   /*!< TEMT Mask 0x00000040 */
#define UART_LSR_TEMT_Set(x)  (((uint32_t) (x) << UART_LSR_TEMT_Pos) & UART_LSR_TEMT_Msk)   /*!< TEMT Set Value */
#define UART_LSR_TEMT_Get(x)  (((uint32_t) (x) & UART_LSR_TEMT_Msk) >> UART_LSR_TEMT_Pos)   /*!< TEMT Get Value */

#define UART_LSR_THRE_Pos     (5U)                                                          /*!< THRE Position 5 */
#define UART_LSR_THRE_Msk     (0x1U << UART_LSR_THRE_Pos)                                   /*!< THRE Mask 0x00000020 */
#define UART_LSR_THRE_Set(x)  (((uint32_t) (x) << UART_LSR_THRE_Pos) & UART_LSR_THRE_Msk)   /*!< THRE Set Value */
#define UART_LSR_THRE_Get(x)  (((uint32_t) (x) & UART_LSR_THRE_Msk) >> UART_LSR_THRE_Pos)   /*!< THRE Get Value */

#define UART_LSR_BI_Pos     (4U)                                                      /*!< BI Position 4 */
#define UART_LSR_BI_Msk     (0x1U << UART_LSR_BI_Pos)                                 /*!< BI Mask 0x00000010 */
#define UART_LSR_BI_Set(x)  (((uint32_t) (x) << UART_LSR_BI_Pos) & UART_LSR_BI_Msk)   /*!< BI Set Value */
#define UART_LSR_BI_Get(x)  (((uint32_t) (x) & UART_LSR_BI_Msk) >> UART_LSR_BI_Pos)   /*!< BI Get Value */

#define UART_LSR_FE_Pos     (3U)                                                      /*!< FE Position 3 */
#define UART_LSR_FE_Msk     (0x1U << UART_LSR_FE_Pos)                                 /*!< FE Mask 0x00000008 */
#define UART_LSR_FE_Set(x)  (((uint32_t) (x) << UART_LSR_FE_Pos) & UART_LSR_FE_Msk)   /*!< FE Set Value */
#define UART_LSR_FE_Get(x)  (((uint32_t) (x) & UART_LSR_FE_Msk) >> UART_LSR_FE_Pos)   /*!< FE Get Value */

#define UART_LSR_PE_Pos     (2U)                                                      /*!< PE Position 2 */
#define UART_LSR_PE_Msk     (0x1U << UART_LSR_PE_Pos)                                 /*!< PE Mask 0x00000004 */
#define UART_LSR_PE_Set(x)  (((uint32_t) (x) << UART_LSR_PE_Pos) & UART_LSR_PE_Msk)   /*!< PE Set Value */
#define UART_LSR_PE_Get(x)  (((uint32_t) (x) & UART_LSR_PE_Msk) >> UART_LSR_PE_Pos)   /*!< PE Get Value */

#define UART_LSR_OE_Pos     (1U)                                                      /*!< OE Position 1 */
#define UART_LSR_OE_Msk     (0x1U << UART_LSR_OE_Pos)                                 /*!< OE Mask 0x00000002 */
#define UART_LSR_OE_Set(x)  (((uint32_t) (x) << UART_LSR_OE_Pos) & UART_LSR_OE_Msk)   /*!< OE Set Value */
#define UART_LSR_OE_Get(x)  (((uint32_t) (x) & UART_LSR_OE_Msk) >> UART_LSR_OE_Pos)   /*!< OE Get Value */

#define UART_LSR_DR_Pos     (0U)                                                      /*!< DR Position 0 */
#define UART_LSR_DR_Msk     (0x1U << UART_LSR_DR_Pos)                                 /*!< DR Mask 0x00000001 */
#define UART_LSR_DR_Set(x)  (((uint32_t) (x) << UART_LSR_DR_Pos) & UART_LSR_DR_Msk)   /*!< DR Set Value */
#define UART_LSR_DR_Get(x)  (((uint32_t) (x) & UART_LSR_DR_Msk) >> UART_LSR_DR_Pos)   /*!< DR Get Value */

/* MSR bitfield */
#define UART_MSR_DCD_Pos     (7U)                                                        /*!< DCD Position 7 */
#define UART_MSR_DCD_Msk     (0x1U << UART_MSR_DCD_Pos)                                  /*!< DCD Mask 0x00000080 */
#define UART_MSR_DCD_Set(x)  (((uint32_t) (x) << UART_MSR_DCD_Pos) & UART_MSR_DCD_Msk)   /*!< DCD Set Value */
#define UART_MSR_DCD_Get(x)  (((uint32_t) (x) & UART_MSR_DCD_Msk) >> UART_MSR_DCD_Pos)   /*!< DCD Get Value */

#define UART_MSR_RI_Pos     (6U)                                                      /*!< RI Position 6 */
#define UART_MSR_RI_Msk     (0x1U << UART_MSR_RI_Pos)                                 /*!< RI Mask 0x00000040 */
#define UART_MSR_RI_Set(x)  (((uint32_t) (x) << UART_MSR_RI_Pos) & UART_MSR_RI_Msk)   /*!< RI Set Value */
#define UART_MSR_RI_Get(x)  (((uint32_t) (x) & UART_MSR_RI_Msk) >> UART_MSR_RI_Pos)   /*!< RI Get Value */

#define UART_MSR_DSR_Pos     (5U)                                                        /*!< DSR Position 5 */
#define UART_MSR_DSR_Msk     (0x1U << UART_MSR_DSR_Pos)                                  /*!< DSR Mask 0x00000020 */
#define UART_MSR_DSR_Set(x)  (((uint32_t) (x) << UART_MSR_DSR_Pos) & UART_MSR_DSR_Msk)   /*!< DSR Set Value */
#define UART_MSR_DSR_Get(x)  (((uint32_t) (x) & UART_MSR_DSR_Msk) >> UART_MSR_DSR_Pos)   /*!< DSR Get Value */

#define UART_MSR_CTS_Pos     (4U)                                                        /*!< CTS Position 4 */
#define UART_MSR_CTS_Msk     (0x1U << UART_MSR_CTS_Pos)                                  /*!< CTS Mask 0x00000010 */
#define UART_MSR_CTS_Set(x)  (((uint32_t) (x) << UART_MSR_CTS_Pos) & UART_MSR_CTS_Msk)   /*!< CTS Set Value */
#define UART_MSR_CTS_Get(x)  (((uint32_t) (x) & UART_MSR_CTS_Msk) >> UART_MSR_CTS_Pos)   /*!< CTS Get Value */

#define UART_MSR_DDCD_Pos     (3U)                                                          /*!< DDCD Position 3 */
#define UART_MSR_DDCD_Msk     (0x1U << UART_MSR_DDCD_Pos)                                   /*!< DDCD Mask 0x00000008 */
#define UART_MSR_DDCD_Set(x)  (((uint32_t) (x) << UART_MSR_DDCD_Pos) & UART_MSR_DDCD_Msk)   /*!< DDCD Set Value */
#define UART_MSR_DDCD_Get(x)  (((uint32_t) (x) & UART_MSR_DDCD_Msk) >> UART_MSR_DDCD_Pos)   /*!< DDCD Get Value */

#define UART_MSR_TERI_Pos     (2U)                                                          /*!< TERI Position 2 */
#define UART_MSR_TERI_Msk     (0x1U << UART_MSR_TERI_Pos)                                   /*!< TERI Mask 0x00000004 */
#define UART_MSR_TERI_Set(x)  (((uint32_t) (x) << UART_MSR_TERI_Pos) & UART_MSR_TERI_Msk)   /*!< TERI Set Value */
#define UART_MSR_TERI_Get(x)  (((uint32_t) (x) & UART_MSR_TERI_Msk) >> UART_MSR_TERI_Pos)   /*!< TERI Get Value */

#define UART_MSR_DDSR_Pos     (1U)                                                          /*!< DDSR Position 1 */
#define UART_MSR_DDSR_Msk     (0x1U << UART_MSR_DDSR_Pos)                                   /*!< DDSR Mask 0x00000002 */
#define UART_MSR_DDSR_Set(x)  (((uint32_t) (x) << UART_MSR_DDSR_Pos) & UART_MSR_DDSR_Msk)   /*!< DDSR Set Value */
#define UART_MSR_DDSR_Get(x)  (((uint32_t) (x) & UART_MSR_DDSR_Msk) >> UART_MSR_DDSR_Pos)   /*!< DDSR Get Value */

#define UART_MSR_DCTS_Pos     (0U)                                                          /*!< DCTS Position 0 */
#define UART_MSR_DCTS_Msk     (0x1U << UART_MSR_DCTS_Pos)                                   /*!< DCTS Mask 0x00000001 */
#define UART_MSR_DCTS_Set(x)  (((uint32_t) (x) << UART_MSR_DCTS_Pos) & UART_MSR_DCTS_Msk)   /*!< DCTS Set Value */
#define UART_MSR_DCTS_Get(x)  (((uint32_t) (x) & UART_MSR_DCTS_Msk) >> UART_MSR_DCTS_Pos)   /*!< DCTS Get Value */

/* SCR bitfield */
#define UART_SCR_SCR_Pos     (0U)                                                        /*!< SCR Position 0 */
#define UART_SCR_SCR_Msk     (0xffU << UART_SCR_SCR_Pos)                                 /*!< SCR Mask 0x000000FF */
#define UART_SCR_SCR_Set(x)  (((uint32_t) (x) << UART_SCR_SCR_Pos) & UART_SCR_SCR_Msk)   /*!< SCR Set Value */
#define UART_SCR_SCR_Get(x)  (((uint32_t) (x) & UART_SCR_SCR_Msk) >> UART_SCR_SCR_Pos)   /*!< SCR Get Value */

/* FAR bitfield */
#define UART_FAR_FAR_Pos     (0U)                                                        /*!< FAR Position 0 */
#define UART_FAR_FAR_Msk     (0x1U << UART_FAR_FAR_Pos)                                  /*!< FAR Mask 0x00000001 */
#define UART_FAR_FAR_Set(x)  (((uint32_t) (x) << UART_FAR_FAR_Pos) & UART_FAR_FAR_Msk)   /*!< FAR Set Value */
#define UART_FAR_FAR_Get(x)  (((uint32_t) (x) & UART_FAR_FAR_Msk) >> UART_FAR_FAR_Pos)   /*!< FAR Get Value */

/* TFR bitfield */
#define UART_TFR_TFR_Pos     (0U)                                                        /*!< TFR Position 0 */
#define UART_TFR_TFR_Msk     (0xffU << UART_TFR_TFR_Pos)                                 /*!< TFR Mask 0x000000FF */
#define UART_TFR_TFR_Set(x)  (((uint32_t) (x) << UART_TFR_TFR_Pos) & UART_TFR_TFR_Msk)   /*!< TFR Set Value */
#define UART_TFR_TFR_Get(x)  (((uint32_t) (x) & UART_TFR_TFR_Msk) >> UART_TFR_TFR_Pos)   /*!< TFR Get Value */

/* RFW bitfield */
#define UART_RFW_RFFE_Pos     (9U)                                                          /*!< RFFE Position 9 */
#define UART_RFW_RFFE_Msk     (0x1U << UART_RFW_RFFE_Pos)                                   /*!< RFFE Mask 0x00000200 */
#define UART_RFW_RFFE_Set(x)  (((uint32_t) (x) << UART_RFW_RFFE_Pos) & UART_RFW_RFFE_Msk)   /*!< RFFE Set Value */
#define UART_RFW_RFFE_Get(x)  (((uint32_t) (x) & UART_RFW_RFFE_Msk) >> UART_RFW_RFFE_Pos)   /*!< RFFE Get Value */

#define UART_RFW_RFPE_Pos     (8U)                                                          /*!< RFPE Position 8 */
#define UART_RFW_RFPE_Msk     (0x1U << UART_RFW_RFPE_Pos)                                   /*!< RFPE Mask 0x00000100 */
#define UART_RFW_RFPE_Set(x)  (((uint32_t) (x) << UART_RFW_RFPE_Pos) & UART_RFW_RFPE_Msk)   /*!< RFPE Set Value */
#define UART_RFW_RFPE_Get(x)  (((uint32_t) (x) & UART_RFW_RFPE_Msk) >> UART_RFW_RFPE_Pos)   /*!< RFPE Get Value */

#define UART_RFW_RFWD_Pos     (0U)                                                          /*!< RFWD Position 0 */
#define UART_RFW_RFWD_Msk     (0xffU << UART_RFW_RFWD_Pos)                                  /*!< RFWD Mask 0x000000FF */
#define UART_RFW_RFWD_Set(x)  (((uint32_t) (x) << UART_RFW_RFWD_Pos) & UART_RFW_RFWD_Msk)   /*!< RFWD Set Value */
#define UART_RFW_RFWD_Get(x)  (((uint32_t) (x) & UART_RFW_RFWD_Msk) >> UART_RFW_RFWD_Pos)   /*!< RFWD Get Value */

/* USR bitfield */
#define UART_USR_RFF_Pos     (4U)                                                        /*!< RFF Position 4 */
#define UART_USR_RFF_Msk     (0x1U << UART_USR_RFF_Pos)                                  /*!< RFF Mask 0x00000010 */
#define UART_USR_RFF_Set(x)  (((uint32_t) (x) << UART_USR_RFF_Pos) & UART_USR_RFF_Msk)   /*!< RFF Set Value */
#define UART_USR_RFF_Get(x)  (((uint32_t) (x) & UART_USR_RFF_Msk) >> UART_USR_RFF_Pos)   /*!< RFF Get Value */

#define UART_USR_RFNE_Pos     (3U)                                                          /*!< RFNE Position 3 */
#define UART_USR_RFNE_Msk     (0x1U << UART_USR_RFNE_Pos)                                   /*!< RFNE Mask 0x00000008 */
#define UART_USR_RFNE_Set(x)  (((uint32_t) (x) << UART_USR_RFNE_Pos) & UART_USR_RFNE_Msk)   /*!< RFNE Set Value */
#define UART_USR_RFNE_Get(x)  (((uint32_t) (x) & UART_USR_RFNE_Msk) >> UART_USR_RFNE_Pos)   /*!< RFNE Get Value */

#define UART_USR_TFE_Pos     (2U)                                                        /*!< TFE Position 2 */
#define UART_USR_TFE_Msk     (0x1U << UART_USR_TFE_Pos)                                  /*!< TFE Mask 0x00000004 */
#define UART_USR_TFE_Set(x)  (((uint32_t) (x) << UART_USR_TFE_Pos) & UART_USR_TFE_Msk)   /*!< TFE Set Value */
#define UART_USR_TFE_Get(x)  (((uint32_t) (x) & UART_USR_TFE_Msk) >> UART_USR_TFE_Pos)   /*!< TFE Get Value */

#define UART_USR_TFNF_Pos     (1U)                                                          /*!< TFNF Position 1 */
#define UART_USR_TFNF_Msk     (0x1U << UART_USR_TFNF_Pos)                                   /*!< TFNF Mask 0x00000002 */
#define UART_USR_TFNF_Set(x)  (((uint32_t) (x) << UART_USR_TFNF_Pos) & UART_USR_TFNF_Msk)   /*!< TFNF Set Value */
#define UART_USR_TFNF_Get(x)  (((uint32_t) (x) & UART_USR_TFNF_Msk) >> UART_USR_TFNF_Pos)   /*!< TFNF Get Value */

#define UART_USR_BUSY_Pos     (0U)                                                          /*!< BUSY Position 0 */
#define UART_USR_BUSY_Msk     (0x1U << UART_USR_BUSY_Pos)                                   /*!< BUSY Mask 0x00000001 */
#define UART_USR_BUSY_Set(x)  (((uint32_t) (x) << UART_USR_BUSY_Pos) & UART_USR_BUSY_Msk)   /*!< BUSY Set Value */
#define UART_USR_BUSY_Get(x)  (((uint32_t) (x) & UART_USR_BUSY_Msk) >> UART_USR_BUSY_Pos)   /*!< BUSY Get Value */

/* TFL bitfield */
#define UART_TFL_TFL_Pos     (0U)                                                        /*!< TFL Position 0 */
#define UART_TFL_TFL_Msk     (0xffU << UART_TFL_TFL_Pos)                                 /*!< TFL Mask 0x000000FF */
#define UART_TFL_TFL_Set(x)  (((uint32_t) (x) << UART_TFL_TFL_Pos) & UART_TFL_TFL_Msk)   /*!< TFL Set Value */
#define UART_TFL_TFL_Get(x)  (((uint32_t) (x) & UART_TFL_TFL_Msk) >> UART_TFL_TFL_Pos)   /*!< TFL Get Value */

/* RFL bitfield */
#define UART_RFL_RFL_Pos     (0U)                                                        /*!< RFL Position 0 */
#define UART_RFL_RFL_Msk     (0xffU << UART_RFL_RFL_Pos)                                 /*!< RFL Mask 0x000000FF */
#define UART_RFL_RFL_Set(x)  (((uint32_t) (x) << UART_RFL_RFL_Pos) & UART_RFL_RFL_Msk)   /*!< RFL Set Value */
#define UART_RFL_RFL_Get(x)  (((uint32_t) (x) & UART_RFL_RFL_Msk) >> UART_RFL_RFL_Pos)   /*!< RFL Get Value */

/* HTX bitfield */
#define UART_HTX_HTX_Pos     (0U)                                                        /*!< HTX Position 0 */
#define UART_HTX_HTX_Msk     (0x1U << UART_HTX_HTX_Pos)                                  /*!< HTX Mask 0x00000001 */
#define UART_HTX_HTX_Set(x)  (((uint32_t) (x) << UART_HTX_HTX_Pos) & UART_HTX_HTX_Msk)   /*!< HTX Set Value */
#define UART_HTX_HTX_Get(x)  (((uint32_t) (x) & UART_HTX_HTX_Msk) >> UART_HTX_HTX_Pos)   /*!< HTX Get Value */

/* TCR bitfield */
#define UART_TCR_XFER_MODE_Pos     (3U)                                                                    /*!< XFER_MODE Position 3 */
#define UART_TCR_XFER_MODE_Msk     (0x3U << UART_TCR_XFER_MODE_Pos)                                        /*!< XFER_MODE Mask 0x00000018 */
#define UART_TCR_XFER_MODE_Set(x)  (((uint32_t) (x) << UART_TCR_XFER_MODE_Pos) & UART_TCR_XFER_MODE_Msk)   /*!< XFER_MODE Set Value */
#define UART_TCR_XFER_MODE_Get(x)  (((uint32_t) (x) & UART_TCR_XFER_MODE_Msk) >> UART_TCR_XFER_MODE_Pos)   /*!< XFER_MODE Get Value */

#define UART_TCR_DE_POL_Pos     (2U)                                                              /*!< DE_POL Position 2 */
#define UART_TCR_DE_POL_Msk     (0x1U << UART_TCR_DE_POL_Pos)                                     /*!< DE_POL Mask 0x00000004 */
#define UART_TCR_DE_POL_Set(x)  (((uint32_t) (x) << UART_TCR_DE_POL_Pos) & UART_TCR_DE_POL_Msk)   /*!< DE_POL Set Value */
#define UART_TCR_DE_POL_Get(x)  (((uint32_t) (x) & UART_TCR_DE_POL_Msk) >> UART_TCR_DE_POL_Pos)   /*!< DE_POL Get Value */

#define UART_TCR_RE_POL_Pos     (1U)                                                              /*!< RE_POL Position 1 */
#define UART_TCR_RE_POL_Msk     (0x1U << UART_TCR_RE_POL_Pos)                                     /*!< RE_POL Mask 0x00000002 */
#define UART_TCR_RE_POL_Set(x)  (((uint32_t) (x) << UART_TCR_RE_POL_Pos) & UART_TCR_RE_POL_Msk)   /*!< RE_POL Set Value */
#define UART_TCR_RE_POL_Get(x)  (((uint32_t) (x) & UART_TCR_RE_POL_Msk) >> UART_TCR_RE_POL_Pos)   /*!< RE_POL Get Value */

#define UART_TCR_RS485_EN_Pos     (0U)                                                                  /*!< RS485_EN Position 0 */
#define UART_TCR_RS485_EN_Msk     (0x1U << UART_TCR_RS485_EN_Pos)                                       /*!< RS485_EN Mask 0x00000001 */
#define UART_TCR_RS485_EN_Set(x)  (((uint32_t) (x) << UART_TCR_RS485_EN_Pos) & UART_TCR_RS485_EN_Msk)   /*!< RS485_EN Set Value */
#define UART_TCR_RS485_EN_Get(x)  (((uint32_t) (x) & UART_TCR_RS485_EN_Msk) >> UART_TCR_RS485_EN_Pos)   /*!< RS485_EN Get Value */

/* DE_EN bitfield */
#define UART_DE_EN_DE_ENABLE_Pos     (0U)                                                                        /*!< DE_ENABLE Position 0 */
#define UART_DE_EN_DE_ENABLE_Msk     (0x1U << UART_DE_EN_DE_ENABLE_Pos)                                          /*!< DE_ENABLE Mask 0x00000001 */
#define UART_DE_EN_DE_ENABLE_Set(x)  (((uint32_t) (x) << UART_DE_EN_DE_ENABLE_Pos) & UART_DE_EN_DE_ENABLE_Msk)   /*!< DE_ENABLE Set Value */
#define UART_DE_EN_DE_ENABLE_Get(x)  (((uint32_t) (x) & UART_DE_EN_DE_ENABLE_Msk) >> UART_DE_EN_DE_ENABLE_Pos)   /*!< DE_ENABLE Get Value */

/* RE_EN bitfield */
#define UART_RE_EN_RE_ENABLE_Pos     (0U)                                                                        /*!< RE_ENABLE Position 0 */
#define UART_RE_EN_RE_ENABLE_Msk     (0x1U << UART_RE_EN_RE_ENABLE_Pos)                                          /*!< RE_ENABLE Mask 0x00000001 */
#define UART_RE_EN_RE_ENABLE_Set(x)  (((uint32_t) (x) << UART_RE_EN_RE_ENABLE_Pos) & UART_RE_EN_RE_ENABLE_Msk)   /*!< RE_ENABLE Set Value */
#define UART_RE_EN_RE_ENABLE_Get(x)  (((uint32_t) (x) & UART_RE_EN_RE_ENABLE_Msk) >> UART_RE_EN_RE_ENABLE_Pos)   /*!< RE_ENABLE Get Value */

/* DET bitfield */
#define UART_DET_DE_DE_ASSERTION_TIME_Pos     (16U)                                                                                         /*!< DE_DE_ASSERTION_TIME Position 16 */
#define UART_DET_DE_DE_ASSERTION_TIME_Msk     (0xffU << UART_DET_DE_DE_ASSERTION_TIME_Pos)                                                  /*!< DE_DE_ASSERTION_TIME Mask 0x00FF0000 */
#define UART_DET_DE_DE_ASSERTION_TIME_Set(x)  (((uint32_t) (x) << UART_DET_DE_DE_ASSERTION_TIME_Pos) & UART_DET_DE_DE_ASSERTION_TIME_Msk)   /*!< DE_DE_ASSERTION_TIME Set Value */
#define UART_DET_DE_DE_ASSERTION_TIME_Get(x)  (((uint32_t) (x) & UART_DET_DE_DE_ASSERTION_TIME_Msk) >> UART_DET_DE_DE_ASSERTION_TIME_Pos)   /*!< DE_DE_ASSERTION_TIME Get Value */

#define UART_DET_DE_ASSERTION_TIME_Pos     (0U)                                                                                    /*!< DE_ASSERTION_TIME Position 0 */
#define UART_DET_DE_ASSERTION_TIME_Msk     (0xffU << UART_DET_DE_ASSERTION_TIME_Pos)                                               /*!< DE_ASSERTION_TIME Mask 0x000000FF */
#define UART_DET_DE_ASSERTION_TIME_Set(x)  (((uint32_t) (x) << UART_DET_DE_ASSERTION_TIME_Pos) & UART_DET_DE_ASSERTION_TIME_Msk)   /*!< DE_ASSERTION_TIME Set Value */
#define UART_DET_DE_ASSERTION_TIME_Get(x)  (((uint32_t) (x) & UART_DET_DE_ASSERTION_TIME_Msk) >> UART_DET_DE_ASSERTION_TIME_Pos)   /*!< DE_ASSERTION_TIME Get Value */

/* TAT bitfield */
#define UART_TAT_RE_TO_DE_Pos     (16U)                                                                 /*!< RE_TO_DE Position 16 */
#define UART_TAT_RE_TO_DE_Msk     (0xffffU << UART_TAT_RE_TO_DE_Pos)                                    /*!< RE_TO_DE Mask 0xFFFF0000 */
#define UART_TAT_RE_TO_DE_Set(x)  (((uint32_t) (x) << UART_TAT_RE_TO_DE_Pos) & UART_TAT_RE_TO_DE_Msk)   /*!< RE_TO_DE Set Value */
#define UART_TAT_RE_TO_DE_Get(x)  (((uint32_t) (x) & UART_TAT_RE_TO_DE_Msk) >> UART_TAT_RE_TO_DE_Pos)   /*!< RE_TO_DE Get Value */

#define UART_TAT_DE_TO_RE_Pos     (0U)                                                                  /*!< DE_TO_RE Position 0 */
#define UART_TAT_DE_TO_RE_Msk     (0xffffU << UART_TAT_DE_TO_RE_Pos)                                    /*!< DE_TO_RE Mask 0x0000FFFF */
#define UART_TAT_DE_TO_RE_Set(x)  (((uint32_t) (x) << UART_TAT_DE_TO_RE_Pos) & UART_TAT_DE_TO_RE_Msk)   /*!< DE_TO_RE Set Value */
#define UART_TAT_DE_TO_RE_Get(x)  (((uint32_t) (x) & UART_TAT_DE_TO_RE_Msk) >> UART_TAT_DE_TO_RE_Pos)   /*!< DE_TO_RE Get Value */

/* UCV bitfield */
#define UART_UCV_UART_COMPONENT_VERSION_Pos     (0U)                                                                                              /*!< UART_COMPONENT_VERSION Position 0 */
#define UART_UCV_UART_COMPONENT_VERSION_Msk     (0xffffffffU << UART_UCV_UART_COMPONENT_VERSION_Pos)                                              /*!< UART_COMPONENT_VERSION Mask 0xFFFFFFFF */
#define UART_UCV_UART_COMPONENT_VERSION_Set(x)  (((uint32_t) (x) << UART_UCV_UART_COMPONENT_VERSION_Pos) & UART_UCV_UART_COMPONENT_VERSION_Msk)   /*!< UART_COMPONENT_VERSION Set Value */
#define UART_UCV_UART_COMPONENT_VERSION_Get(x)  (((uint32_t) (x) & UART_UCV_UART_COMPONENT_VERSION_Msk) >> UART_UCV_UART_COMPONENT_VERSION_Pos)   /*!< UART_COMPONENT_VERSION Get Value */

/* CTR bitfield */
#define UART_CTR_PERIPHERAL_ID_Pos     (0U)                                                                            /*!< PERIPHERAL_ID Position 0 */
#define UART_CTR_PERIPHERAL_ID_Msk     (0xffffffffU << UART_CTR_PERIPHERAL_ID_Pos)                                     /*!< PERIPHERAL_ID Mask 0xFFFFFFFF */
#define UART_CTR_PERIPHERAL_ID_Set(x)  (((uint32_t) (x) << UART_CTR_PERIPHERAL_ID_Pos) & UART_CTR_PERIPHERAL_ID_Msk)   /*!< PERIPHERAL_ID Set Value */
#define UART_CTR_PERIPHERAL_ID_Get(x)  (((uint32_t) (x) & UART_CTR_PERIPHERAL_ID_Msk) >> UART_CTR_PERIPHERAL_ID_Pos)   /*!< PERIPHERAL_ID Get Value */

/*!
 * @}
 */

/* clang-format on */

/*!
 * @}
 */ /* end of HS32F7D377_UART_REGISTER */

#endif /* HS32F7D377_UART_H */
