/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file HS32F7D377_cpu2_arrays.h
 * \brief HS32F7D377 CPU2 array file
 * \version 1.0.0
 */

#ifndef HS32F7D377_CPU2_ARRAYS_H
#define HS32F7D377_CPU2_ARRAYS_H

/*!
 * \addtogroup HS32F7D377_CPU2_ARRAYS HS32F7D377 CPU2 Arrays
 *
 * \brief HS32F7D377 CPU2 device array definitions
 *
 * @{
 */

/*!
 * \name XINT Module ARRAYS
 *
 * @{
 */
/*! \brief Array initializer of XINT interrupt vectors */
#define XINT_IRQS                                                  \
    {                                                              \
        XINT1_IRQn, XINT2_IRQn, XINT3_IRQn, XINT4_IRQn, XINT5_IRQn \
    }
/*!
 * @}
 */

/*!
 * \name UART Module ARRAYS
 *
 * @{
 */
/*! \brief Array initializer of UART base address vector */
#define UART_BASE_ADDRS                                \
    {                                                  \
        UARTA_BASE, UARTB_BASE, UARTC_BASE, UARTD_BASE \
    }
/*! \brief Array initializer of UART base pointer vector */
#define UART_BASES                 \
    {                              \
        UARTA, UARTB, UARTC, UARTD \
    }
/*! \brief Array initializer of UART interrupt vectors */
#define UART_IRQS                                      \
    {                                                  \
        UARTA_IRQn, UARTB_IRQn, UARTC_IRQn, UARTD_IRQn \
    }
/*!
 * @}
 */

/*!
 * \name I2C Module ARRAYS
 *
 * @{
 */
/*! \brief Array initializer of I2C base address vector */
#define I2C_BASE_ADDRS       \
    {                        \
        I2CA_BASE, I2CB_BASE \
    }
/*! \brief Array initializer of I2C base pointer vector */
#define I2C_BASES  \
    {              \
        I2CA, I2CB \
    }
/*! \brief Array initializer of I2C interrupt vectors */
#define I2C_IRQS             \
    {                        \
        I2CA_IRQn, I2CB_IRQn \
    }
/*!
 * @}
 */

/*!
 * \name DMA Module ARRAYS
 *
 * @{
 */
/*! \brief Array initializer of DMA interrupt vectors */
#define DMA_IRQS                                                                           \
    {                                                                                      \
        DMA_CH1_IRQn, DMA_CH2_IRQn, DMA_CH3_IRQn, DMA_CH4_IRQn, DMA_CH5_IRQn, DMA_CH6_IRQn \
    }
/*!
 * @}
 */

/*!
 * \name CPUTIMER Module ARRAYS
 *
 * @{
 */
/*! \brief Array initializer of CPUTIMER interrupt vectors */
#define CPUTIMER_IRQS                                  \
    {                                                  \
        CPUTIMER0_IRQn, CPUTIMER1_IRQn, CPUTIMER2_IRQn \
    }
/*!
 * @}
 */

/*!
 * \name STIMER Module ARRAYS
 *
 * @{
 */
/*! \brief Array initializer of STIMER interrupt vectors */
#define STIMER_IRQS                                          \
    {                                                        \
        DWTIMER_CH0_IRQn, DWTIMER_CH1_IRQn, DWTIMER_CH2_IRQn \
    }
/*!
 * @}
 */

/*!
 * \name IPC Module ARRAYS
 *
 * @{
 */
/*! \brief Array initializer of IPC interrupt vectors */
#define IPC_IRQS                                                   \
    {                                                              \
        IPC_INT0_IRQn, IPC_INT1_IRQn, IPC_INT2_IRQn, IPC_INT3_IRQn \
    }
/*!
 * @}
 */

/*!
 * \name SPI Module ARRAYS
 *
 * @{
 */
/*! \brief Array initializer of SPI base address vector */
#define SPI_BASE_ADDRS                  \
    {                                   \
        SPIA_BASE, SPIB_BASE, SPIC_BASE \
    }
/*! \brief Array initializer of SPI base pointer vector */
#define SPI_BASES        \
    {                    \
        SPIA, SPIB, SPIC \
    }
/*! \brief Array initializer of SPI interrupt vector */
#define SPI_IRQS                        \
    {                                   \
        SPIA_IRQn, SPIB_IRQn, SPIC_IRQn \
    }
/*!
 * @}
 */

/*!
 * \name CMPSS Module ARRAYS
 *
 * @{
 */
/*! \brief Array initializer of CMPSS base address vector */
#define CMPSS_BASE_ADDRS                                                                                       \
    {                                                                                                          \
        CMPSS1_BASE, CMPSS2_BASE, CMPSS3_BASE, CMPSS4_BASE, CMPSS5_BASE, CMPSS6_BASE, CMPSS7_BASE, CMPSS8_BASE \
    }
/*! \brief Array initializer of CMPSS base pointer vector */
#define CMPSS_BASES                                                    \
    {                                                                  \
        CMPSS1, CMPSS2, CMPSS3, CMPSS4, CMPSS5, CMPSS6, CMPSS7, CMPSS8 \
    }
/*!
 * @}
 */

/*!
 * \name EQEP Module ARRAYS
 *
 * @{
 */
/*! \brief Array initializer of EQEP base address vector */
#define EQEP_BASE_ADDRS                                                                                       \
    {                                                                                                          \
        EQEP1_BASE, EQEP2_BASE, EQEP3_BASE \
    }
/*! \brief Array initializer of EQEP base pointer vector */
#define EQEP_BASES                                                    \
    {                                                                  \
        EQEP1, EQEP2, EQEP3 \
    }
/*! \brief Array initializer of EQEP interrupt vector */
#define EQEP_IRQS                        \
    {                                   \
        EQEP1_IRQn, EQEP2_IRQn, EQEP3_IRQn \
    }
/*!
 * @}
 */

/*!
 * \name SDFM Module ARRAYS
 *
 * @{
 */
/*! \brief Array initializer of SDFM base address vector */
#define SDFM_BASE_ADDRS                                                                                       \
        {                                                                                                          \
            SDFM1_BASE, SDFM2_BASE \
        }
/*! \brief Array initializer of SDFM base pointer vector */
#define SDFM_BASES                                                    \
        {                                                                  \
            SDFM1, SDFM2 \
        }
/*! \brief Array initializer of SDFM interrupt vector */
#define SDFM_IRQS                        \
        {                                   \
            {SDFM1_IRQn, SDFM1_FLT1DR_IRQn, SDFM1_FLT2DR_IRQn, SDFM1_FLT3DR_IRQn, SDFM1_FLT4DR_IRQn}, \
            {SDFM2_IRQn, SDFM2_FLT1DR_IRQn, SDFM2_FLT2DR_IRQn, SDFM2_FLT3DR_IRQn, SDFM2_FLT4DR_IRQn}, \
        }
/*!
 * @}
 */

/*!
 * \name MCAN Module ARRAYS
 *
 * @{
 */
/*! \brief Array initializer of MCAN base address vector */
#define MCAN_BASE_ADDRS                                                                                       \
        {                                                                                                          \
            MCANA_BASE, MCANB_BASE, MCANC_BASE \
        }
/*! \brief Array initializer of MCAN base pointer vector */
#define MCAN_BASES                                                    \
        {                                                                  \
            MCANA, MCANB, MCANC \
        }
/*! \brief Array initializer of MCAN interrupt vector */
#define MCAN_IRQS                        \
        {                                   \
            {MCANA_INT0_IRQn, MCANA_INT1_IRQn}, {MCANB_INT0_IRQn, MCANB_INT1_IRQn}, {MCANC_INT0_IRQn, MCANC_INT1_IRQn} \
        }
/*!
 * @}
 */

/*!
 * @}
 */ /* end of HS32F7D377_CPU2_ARRAYS */

#endif /* HS32F7D377_CPU2_ARRAYS_H */
