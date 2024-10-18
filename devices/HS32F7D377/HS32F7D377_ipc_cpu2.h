/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


/*!
 * \file   HS32F7D377_ipc_CPU2.h
 * \brief  HS32F7D377 IPC_CPU2 register file
 * \version V1.0_20230831
 */

#ifndef HS32F7D377_IPC_CPU2_H
#define HS32F7D377_IPC_CPU2_H

/*!
 * \addtogroup   HS32F7D377_IPC_CPU2_REGISTER HS32F7D377 IPC_CPU2 Register
 * \ingroup HS32F7D377_REGISTER
 *
 * \brief  IPC_CPU2 register layout, bitfield and address definitions
 *
 * @{
 */

/*!
 * \name IPC_CPU2 Register Layout
 *
 *
 * @{
 */

/*! \brief IPC_REGS_CPU2 register */
typedef struct
{
    union
    {
        __IOM uint32_t IPCACK; /*!< 0x00000000 : IPC incoming flag clear (acknowledge) register */

        struct
        {
            __IOM uint32_t IPC0 : 1;  /*!< [ 0: 0] : Writing 1 to this bit clears the IPC0 event flag which was set by
                                         the remote CPU.  Writing 0 to this bit has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC1 : 1;  /*!< [ 1: 1] : Writing 1 to this bit clears the IPC1 event flag which was set by
                                         the remote CPU.  Writing 0 to this bit has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC2 : 1;  /*!< [ 2: 2] : Writing 1 to this bit clears the IPC2 event flag which was set by
                                         the remote CPU.  Writing 0 to this bit has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC3 : 1;  /*!< [ 3: 3] : Writing 1 to this bit clears the IPC3 event flag which was set by
                                         the remote CPU.  Writing 0 to this bit has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC4 : 1;  /*!< [ 4: 4] : Writing 1 to this bit clears the IPC4 event flag which was set by
                                         the remote CPU.  Writing 0 to this bit has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC5 : 1;  /*!< [ 5: 5] : Writing 1 to this bit clears the IPC5 event flag which was set by
                                         the remote CPU.  Writing 0 to this bit has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC6 : 1;  /*!< [ 6: 6] : Writing 1 to this bit clears the IPC6 event flag which was set by
                                         the remote CPU.  Writing 0 to this bit has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC7 : 1;  /*!< [ 7: 7] : Writing 1 to this bit clears the IPC7 event flag which was set by
                                         the remote CPU.  Writing 0 to this bit has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC8 : 1;  /*!< [ 8: 8] : Writing 1 to this bit clears the IPC8 event flag which was set by
                                         the remote CPU.  Writing 0 to this bit has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC9 : 1;  /*!< [ 9: 9] : Writing 1 to this bit clears the IPC9 event flag which was set by
                                         the remote CPU.  Writing 0 to this bit has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC10 : 1; /*!< [10:10] : Writing 1 to this bit clears the IPC10 event flag which was set by
                                         the remote CPU. Writing 0 to this bit has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC11 : 1; /*!< [11:11] : Writing 1 to this bit clears the IPC11 event flag which was set by
                                         the remote CPU. Writing 0 to this bit has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC12 : 1; /*!< [12:12] : Writing 1 to this bit clears the IPC12 event flag which was set by
                                         the remote CPU. Writing 0 to this bit has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC13 : 1; /*!< [13:13] : Writing 1 to this bit clears the IPC13 event flag which was set by
                                         the remote CPU. Writing 0 to this bit has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC14 : 1; /*!< [14:14] : Writing 1 to this bit clears the IPC14 event flag which was set by
                                         the remote CPU. Writing 0 to this bit has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC15 : 1; /*!< [15:15] : Writing 1 to this bit clears the IPC15 event flag which was set by
                                         the remote CPU. Writing 0 to this bit has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC16 : 1; /*!< [16:16] : Writing 1 to this bit clears the IPC16 event flag which was set by
                                         the remote CPU. Writing 0 to this bit has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC17 : 1; /*!< [17:17] : Writing 1 to this bit clears the IPC17 event flag which was set by
                                         the remote CPU. Writing 0 to this bit has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC18 : 1; /*!< [18:18] : Writing 1 to this bit clears the IPC18 event flag which was set by
                                         the remote CPU. Writing 0 to this bit has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC19 : 1; /*!< [19:19] : Writing 1 to this bit clears the IPC19 event flag which was set by
                                         the remote CPU. Writing 0 to this bit has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC20 : 1; /*!< [20:20] : Writing 1 to this bit clears the IPC20 event flag which was set by
                                         the remote CPU. Writing 0 to this bit has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC21 : 1; /*!< [21:21] : Writing 1 to this bit clears the IPC21 event flag which was set by
                                         the remote CPU. Writing 0 to this bit has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC22 : 1; /*!< [22:22] : Writing 1 to this bit clears the IPC22 event flag which was set by
                                         the remote CPU. Writing 0 to this bit has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC23 : 1; /*!< [23:23] : Writing 1 to this bit clears the IPC23 event flag which was set by
                                         the remote CPU. Writing 0 to this bit has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC24 : 1; /*!< [24:24] : Writing 1 to this bit clears the IPC24 event flag which was set by
                                         the remote CPU. Writing 0 to this bit has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC25 : 1; /*!< [25:25] : Writing 1 to this bit clears the IPC25 event flag which was set by
                                         the remote CPU. Writing 0 to this bit has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC26 : 1; /*!< [26:26] : Writing 1 to this bit clears the IPC26 event flag which was set by
                                         the remote CPU. Writing 0 to this bit has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC27 : 1; /*!< [27:27] : Writing 1 to this bit clears the IPC27 event flag which was set by
                                         the remote CPU. Writing 0 to this bit has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC28 : 1; /*!< [28:28] : Writing 1 to this bit clears the IPC28 event flag which was set by
                                         the remote CPU. Writing 0 to this bit has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC29 : 1; /*!< [29:29] : Writing 1 to this bit clears the IPC29 event flag which was set by
                                         the remote CPU. Writing 0 to this bit has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC30 : 1; /*!< [30:30] : Writing 1 to this bit clears the IPC30 event flag which was set by
                                         the remote CPU. Writing 0 to this bit has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC31 : 1; /*!< [31:31] : Writing 1 to this bit clears the IPC31 event flag which was set by
                                         the remote CPU. Writing 0 to this bit has no effect. Reset type: SYSRSn */
        } IPCACKb;
    };

    union
    {
        __IM uint32_t IPCSTS; /*!< 0x00000004 : IPC incoming flag status register */

        struct
        {
            __IM uint32_t IPC0 : 1;  /*!< [ 0: 0] : Indicates to the local CPU if the IPC0 event flag was set by the
                                        remote CPU.  0: No IPC0 event was set by the remote CPU 1: An IPC0 event was set
                                        by the remote CPU  Notes  [1] IPC event flags 0-3 will trigger interrupts in the
                                        receiving CPU via the ePIE.  Reset type: SYSRSn */
            __IM uint32_t IPC1 : 1;  /*!< [ 1: 1] : Indicates to the local CPU if the IPC1 event flag was set by the
                                        remote CPU.  0: No IPC1 event was set by the remote CPU 1: An IPC1 event was set
                                        by the remote CPU  Notes  [1] IPC event flags 0-3 will trigger interrupts in the
                                        receiving CPU via the ePIE.  Reset type: SYSRSn */
            __IM uint32_t IPC2 : 1;  /*!< [ 2: 2] : Indicates to the local CPU if the IPC2 event flag was set by the
                                        remote CPU.  0: No IPC2 event was set by the remote CPU 1: An IPC2 event was set
                                        by the remote CPU  Notes  [1] IPC event flags 0-3 will trigger interrupts in the
                                        receiving CPU via the ePIE.  Reset type: SYSRSn */
            __IM uint32_t IPC3 : 1;  /*!< [ 3: 3] : Indicates to the local CPU if the IPC3 event flag was set by the
                                        remote CPU.  0: No IPC3 event was set by the remote CPU 1: An IPC3 event was set
                                        by the remote CPU  Notes  [1] IPC event flags 0-3 will trigger interrupts in the
                                        receiving CPU via the ePIE.  Reset type: SYSRSn */
            __IM uint32_t IPC4 : 1;  /*!< [ 4: 4] : Indicates to the local CPU if the IPC4 event flag was set by the
                                        remote CPU.  0: No IPC4 event was set by the remote CPU 1: An IPC4 event was set
                                        by the remote CPU  Reset type: SYSRSn */
            __IM uint32_t IPC5 : 1;  /*!< [ 5: 5] : Indicates to the local CPU if the IPC5 event flag was set by the
                                        remote CPU.  0: No IPC5 event was set by the remote CPU 1: An IPC5 event was set
                                        by the remote CPU  Reset type: SYSRSn */
            __IM uint32_t IPC6 : 1;  /*!< [ 6: 6] : Indicates to the local CPU if the IPC6 event flag was set by the
                                        remote CPU.  0: No IPC6 event was set by the remote CPU 1: An IPC6 event was set
                                        by the remote CPU  Reset type: SYSRSn */
            __IM uint32_t IPC7 : 1;  /*!< [ 7: 7] : Indicates to the local CPU if the IPC7 event flag was set by the
                                        remote CPU.  0: No IPC7 event was set by the remote CPU 1: An IPC7 event was set
                                        by the remote CPU  Reset type: SYSRSn */
            __IM uint32_t IPC8 : 1;  /*!< [ 8: 8] : Indicates to the local CPU if the IPC8 event flag was set by the
                                        remote CPU.  0: No IPC8 event was set by the remote CPU 1: An IPC8 event was set
                                        by the remote CPU  Reset type: SYSRSn */
            __IM uint32_t IPC9 : 1;  /*!< [ 9: 9] : Indicates to the local CPU if the IPC9 event flag was set by the
                                        remote CPU.  0: No IPC9 event was set by the remote CPU 1: An IPC9 event was set
                                        by the remote CPU  Reset type: SYSRSn */
            __IM uint32_t IPC10 : 1; /*!< [10:10] : Indicates to the local CPU if the IPC10 event flag was set by the
                                        remote CPU. 0: No IPC10 event was set by the remote CPU 1: An IPC10 event was
                                        set by the remote CPU Reset type: SYSRSn */
            __IM uint32_t IPC11 : 1; /*!< [11:11] : Indicates to the local CPU if the IPC11 event flag was set by the
                                        remote CPU. 0: No IPC11 event was set by the remote CPU 1: An IPC11 event was
                                        set by the remote CPU Reset type: SYSRSn */
            __IM uint32_t IPC12 : 1; /*!< [12:12] : Indicates to the local CPU if the IPC12 event flag was set by the
                                        remote CPU. 0: No IPC12 event was set by the remote CPU 1: An IPC12 event was
                                        set by the remote CPU Reset type: SYSRSn */
            __IM uint32_t IPC13 : 1; /*!< [13:13] : Indicates to the local CPU if the IPC13 event flag was set by the
                                        remote CPU. 0: No IPC13 event was set by the remote CPU 1: An IPC13 event was
                                        set by the remote CPU Reset type: SYSRSn */
            __IM uint32_t IPC14 : 1; /*!< [14:14] : Indicates to the local CPU if the IPC14 event flag was set by the
                                        remote CPU. 0: No IPC14 event was set by the remote CPU 1: An IPC14 event was
                                        set by the remote CPU Reset type: SYSRSn */
            __IM uint32_t IPC15 : 1; /*!< [15:15] : Indicates to the local CPU if the IPC15 event flag was set by the
                                        remote CPU. 0: No IPC15 event was set by the remote CPU 1: An IPC15 event was
                                        set by the remote CPU Reset type: SYSRSn */
            __IM uint32_t IPC16 : 1; /*!< [16:16] : Indicates to the local CPU if the IPC16 event flag was set by the
                                        remote CPU. 0: No IPC16 event was set by the remote CPU 1: An IPC16 event was
                                        set by the remote CPU Reset type: SYSRSn */
            __IM uint32_t IPC17 : 1; /*!< [17:17] : Indicates to the local CPU if the IPC17 event flag was set by the
                                        remote CPU. 0: No IPC17 event was set by the remote CPU 1: An IPC17 event was
                                        set by the remote CPU Reset type: SYSRSn */
            __IM uint32_t IPC18 : 1; /*!< [18:18] : Indicates to the local CPU if the IPC18 event flag was set by the
                                        remote CPU. 0: No IPC18 event was set by the remote CPU 1: An IPC18 event was
                                        set by the remote CPU Reset type: SYSRSn */
            __IM uint32_t IPC19 : 1; /*!< [19:19] : Indicates to the local CPU if the IPC19 event flag was set by the
                                        remote CPU. 0: No IPC19 event was set by the remote CPU 1: An IPC19 event was
                                        set by the remote CPU Reset type: SYSRSn */
            __IM uint32_t IPC20 : 1; /*!< [20:20] : Indicates to the local CPU if the IPC20 event flag was set by the
                                        remote CPU. 0: No IPC20 event was set by the remote CPU 1: An IPC20 event was
                                        set by the remote CPU Reset type: SYSRSn */
            __IM uint32_t IPC21 : 1; /*!< [21:21] : Indicates to the local CPU if the IPC21 event flag was set by the
                                        remote CPU. 0: No IPC21 event was set by the remote CPU 1: An IPC21 event was
                                        set by the remote CPU Reset type: SYSRSn */
            __IM uint32_t IPC22 : 1; /*!< [22:22] : Indicates to the local CPU if the IPC22 event flag was set by the
                                        remote CPU. 0: No IPC22 event was set by the remote CPU 1: An IPC22 event was
                                        set by the remote CPU Reset type: SYSRSn */
            __IM uint32_t IPC23 : 1; /*!< [23:23] : Indicates to the local CPU if the IPC23 event flag was set by the
                                        remote CPU. 0: No IPC23 event was set by the remote CPU 1: An IPC23 event was
                                        set by the remote CPU Reset type: SYSRSn */
            __IM uint32_t IPC24 : 1; /*!< [24:24] : Indicates to the local CPU if the IPC24 event flag was set by the
                                        remote CPU. 0: No IPC24 event was set by the remote CPU 1: An IPC24 event was
                                        set by the remote CPU Reset type: SYSRSn */
            __IM uint32_t IPC25 : 1; /*!< [25:25] : Indicates to the local CPU if the IPC25 event flag was set by the
                                        remote CPU. 0: No IPC25 event was set by the remote CPU 1: An IPC25 event was
                                        set by the remote CPU Reset type: SYSRSn */
            __IM uint32_t IPC26 : 1; /*!< [26:26] : Indicates to the local CPU if the IPC26 event flag was set by the
                                        remote CPU. 0: No IPC26 event was set by the remote CPU 1: An IPC26 event was
                                        set by the remote CPU Reset type: SYSRSn */
            __IM uint32_t IPC27 : 1; /*!< [27:27] : Indicates to the local CPU if the IPC27 event flag was set by the
                                        remote CPU. 0: No IPC27 event was set by the remote CPU 1: An IPC27 event was
                                        set by the remote CPU Reset type: SYSRSn */
            __IM uint32_t IPC28 : 1; /*!< [28:28] : Indicates to the local CPU if the IPC28 event flag was set by the
                                        remote CPU. 0: No IPC28 event was set by the remote CPU 1: An IPC28 event was
                                        set by the remote CPU Reset type: SYSRSn */
            __IM uint32_t IPC29 : 1; /*!< [29:29] : Indicates to the local CPU if the IPC29 event flag was set by the
                                        remote CPU. 0: No IPC29 event was set by the remote CPU 1: An IPC29 event was
                                        set by the remote CPU Reset type: SYSRSn */
            __IM uint32_t IPC30 : 1; /*!< [30:30] : Indicates to the local CPU if the IPC30 event flag was set by the
                                        remote CPU. 0: No IPC30 event was set by the remote CPU 1: An IPC30 event was
                                        set by the remote CPU Reset type: SYSRSn */
            __IM uint32_t IPC31 : 1; /*!< [31:31] : Indicates to the local CPU if the IPC31 event flag was set by the
                                        remote CPU. 0: No IPC31 event was set by the remote CPU 1: An IPC31 event was
                                        set by the remote CPU Reset type: SYSRSn */
        } IPCSTSb;
    };

    union
    {
        __IOM uint32_t IPCSET; /*!< 0x00000008 : IPC remote flag set register */

        struct
        {
            __IOM uint32_t IPC0 : 1;  /*!< [ 0: 0] : Writing 1 to this bit sets the IPC0 event flag for the remote CPU.
                                         Writing 0 has no effect.  Notes:  [1] IPC event flags 0-3 will trigger
                                         interrupts  in the receiving CPU via the ePIE.  Reset type: SYSRSn */
            __IOM uint32_t IPC1 : 1;  /*!< [ 1: 1] : Writing 1 to this bit sets the IPC1 event flag for the remote CPU.
                                         Writing 0 has no effect.  Notes:  [1] IPC event flags 0-3 will trigger
                                         interrupts  in the receiving CPU via the ePIE.  Reset type: SYSRSn */
            __IOM uint32_t IPC2 : 1;  /*!< [ 2: 2] : Writing 1 to this bit sets the IPC2 event flag for the remote CPU.
                                         Writing 0 has no effect.  Notes:  [1] IPC event flags 0-3 will trigger
                                         interrupts  in the receiving CPU via the ePIE.  Reset type: SYSRSn */
            __IOM uint32_t IPC3 : 1;  /*!< [ 3: 3] : Writing 1 to this bit sets the IPC3 event flag for the remote CPU.
                                         Writing 0 has no effect.  Notes:  [1] IPC event flags 0-3 will trigger
                                         interrupts  in the receiving CPU via the ePIE.  Reset type: SYSRSn */
            __IOM uint32_t IPC4 : 1;  /*!< [ 4: 4] : Writing 1 to this bit sets the IPC4 event flag for the remote CPU.
                                         Writing 0 has no effect.  Reset type: SYSRSn */
            __IOM uint32_t IPC5 : 1;  /*!< [ 5: 5] : Writing 1 to this bit sets the IPC5 event flag for the remote CPU.
                                         Writing 0 has no effect.  Reset type: SYSRSn */
            __IOM uint32_t IPC6 : 1;  /*!< [ 6: 6] : Writing 1 to this bit sets the IPC6 event flag for the remote CPU.
                                         Writing 0 has no effect.  Reset type: SYSRSn */
            __IOM uint32_t IPC7 : 1;  /*!< [ 7: 7] : Writing 1 to this bit sets the IPC7 event flag for the remote CPU.
                                         Writing 0 has no effect.  Reset type: SYSRSn */
            __IOM uint32_t IPC8 : 1;  /*!< [ 8: 8] : Writing 1 to this bit sets the IPC8 event flag for the remote CPU.
                                         Writing 0 has no effect.  Reset type: SYSRSn */
            __IOM uint32_t IPC9 : 1;  /*!< [ 9: 9] : Writing 1 to this bit sets the IPC9 event flag for the remote CPU.
                                         Writing 0 has no effect.  Reset type: SYSRSn */
            __IOM uint32_t IPC10 : 1; /*!< [10:10] : Writing 1 to this bit sets the IPC10 event flag for the remote CPU.
                                         Writing 0 has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC11 : 1; /*!< [11:11] : Writing 1 to this bit sets the IPC11 event flag for the remote CPU.
                                         Writing 0 has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC12 : 1; /*!< [12:12] : Writing 1 to this bit sets the IPC12 event flag for the remote CPU.
                                         Writing 0 has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC13 : 1; /*!< [13:13] : Writing 1 to this bit sets the IPC13 event flag for the remote CPU.
                                         Writing 0 has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC14 : 1; /*!< [14:14] : Writing 1 to this bit sets the IPC14 event flag for the remote CPU.
                                         Writing 0 has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC15 : 1; /*!< [15:15] : Writing 1 to this bit sets the IPC15 event flag for the remote CPU.
                                         Writing 0 has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC16 : 1; /*!< [16:16] : Writing 1 to this bit sets the IPC16 event flag for the remote CPU.
                                         Writing 0 has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC17 : 1; /*!< [17:17] : Writing 1 to this bit sets the IPC17 event flag for the remote CPU.
                                         Writing 0 has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC18 : 1; /*!< [18:18] : Writing 1 to this bit sets the IPC18 event flag for the remote CPU.
                                         Writing 0 has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC19 : 1; /*!< [19:19] : Writing 1 to this bit sets the IPC19 event flag for the remote CPU.
                                         Writing 0 has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC20 : 1; /*!< [20:20] : Writing 1 to this bit sets the IPC20 event flag for the remote CPU.
                                         Writing 0 has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC21 : 1; /*!< [21:21] : Writing 1 to this bit sets the IPC21 event flag for the remote CPU.
                                         Writing 0 has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC22 : 1; /*!< [22:22] : Writing 1 to this bit sets the IPC22 event flag for the remote CPU.
                                         Writing 0 has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC23 : 1; /*!< [23:23] : Writing 1 to this bit sets the IPC23 event flag for the remote CPU.
                                         Writing 0 has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC24 : 1; /*!< [24:24] : Writing 1 to this bit sets the IPC24 event flag for the remote CPU.
                                         Writing 0 has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC25 : 1; /*!< [25:25] : Writing 1 to this bit sets the IPC25 event flag for the remote CPU.
                                         Writing 0 has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC26 : 1; /*!< [26:26] : Writing 1 to this bit sets the IPC26 event flag for the remote CPU.
                                         Writing 0 has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC27 : 1; /*!< [27:27] : Writing 1 to this bit sets the IPC27 event flag for the remote CPU.
                                         Writing 0 has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC28 : 1; /*!< [28:28] : Writing 1 to this bit sets the IPC28 event flag for the remote CPU.
                                         Writing 0 has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC29 : 1; /*!< [29:29] : Writing 1 to this bit sets the IPC29 event flag for the remote CPU.
                                         Writing 0 has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC30 : 1; /*!< [30:30] : Writing 1 to this bit sets the IPC30 event flag for the remote CPU.
                                         Writing 0 has no effect. Reset type: SYSRSn */
            __IOM uint32_t IPC31 : 1; /*!< [31:31] : Writing 1 to this bit sets the IPC31 event flag for the remote CPU.
                                         Writing 0 has no effect. Reset type: SYSRSn */
        } IPCSETb;
    };

    union
    {
        __IOM uint32_t IPCCLR; /*!< 0x0000000c : IPC remote flag clear register */

        struct
        {
            __IOM uint32_t
                IPC0 : 1; /*!< [ 0: 0] : Writing 1 to this bit clears the IPC0 flag for the remote CPU. Writing 0 has no
                             effect. Notes: [1] Normally, each CPU will clear (acknowledge) only its own local flags.
                             This mechanism may be useful if the remote CPU is non- responsive. Reset type: SYSRSn */
            __IOM uint32_t
                IPC1 : 1; /*!< [ 1: 1] : Writing 1 to this bit clears the IPC1 flag for the remote CPU. Writing 0 has no
                             effect. Notes: [1] Normally, each CPU will clear (acknowledge) only its own local flags.
                             This mechanism may be useful if the remote CPU is non- responsive. Reset type: SYSRSn */
            __IOM uint32_t
                IPC2 : 1; /*!< [ 2: 2] : Writing 1 to this bit clears the IPC2 flag for the remote CPU. Writing 0 has no
                             effect. Notes: [1] Normally, each CPU will clear (acknowledge) only its own local flags.
                             This mechanism may be useful if the remote CPU is non- responsive. Reset type: SYSRSn */
            __IOM uint32_t
                IPC3 : 1; /*!< [ 3: 3] : Writing 1 to this bit clears the IPC3 flag for the remote CPU. Writing 0 has no
                             effect. Notes: [1] Normally, each CPU will clear (acknowledge) only its own local flags.
                             This mechanism may be useful if the remote CPU is non- responsive. Reset type: SYSRSn */
            __IOM uint32_t
                IPC4 : 1; /*!< [ 4: 4] : Writing 1 to this bit clears the IPC4 flag for the remote CPU. Writing 0 has no
                             effect. Notes: [1] Normally, each CPU will clear (acknowledge) only its own local flags.
                             This mechanism may be useful if the remote CPU is non- responsive. Reset type: SYSRSn */
            __IOM uint32_t
                IPC5 : 1; /*!< [ 5: 5] : Writing 1 to this bit clears the IPC5 flag for the remote CPU. Writing 0 has no
                             effect. Notes: [1] Normally, each CPU will clear (acknowledge) only its own local flags.
                             This mechanism may be useful if the remote CPU is non- responsive. Reset type: SYSRSn */
            __IOM uint32_t
                IPC6 : 1; /*!< [ 6: 6] : Writing 1 to this bit clears the IPC6 flag for the remote CPU. Writing 0 has no
                             effect. Notes: [1] Normally, each CPU will clear (acknowledge) only its own local flags.
                             This mechanism may be useful if the remote CPU is non- responsive. Reset type: SYSRSn */
            __IOM uint32_t
                IPC7 : 1; /*!< [ 7: 7] : Writing 1 to this bit clears the IPC7 flag for the remote CPU. Writing 0 has no
                             effect. Notes: [1] Normally, each CPU will clear (acknowledge) only its own local flags.
                             This mechanism may be useful if the remote CPU is non- responsive. Reset type: SYSRSn */
            __IOM uint32_t
                IPC8 : 1; /*!< [ 8: 8] : Writing 1 to this bit clears the IPC8 flag for the remote CPU. Writing 0 has no
                             effect. Notes: [1] Normally, each CPU will clear (acknowledge) only its own local flags.
                             This mechanism may be useful if the remote CPU is non- responsive. Reset type: SYSRSn */
            __IOM uint32_t
                IPC9 : 1; /*!< [ 9: 9] : Writing 1 to this bit clears the IPC9 flag for the remote CPU. Writing 0 has no
                             effect. Notes: [1] Normally, each CPU will clear (acknowledge) only its own local flags.
                             This mechanism may be useful if the remote CPU is non- responsive. Reset type: SYSRSn */
            __IOM uint32_t IPC10 : 1; /*!< [10:10] : Writing 1 to this bit clears the IPC10 flag for the remote CPU.
                                         Writing 0 has no effect. Notes: [1] Normally, each CPU will clear (acknowledge)
                                         only its own local flags. This mechanism may be useful if the remote CPU is
                                         non- responsive. Reset type: SYSRSn */
            __IOM uint32_t IPC11 : 1; /*!< [11:11] : Writing 1 to this bit clears the IPC11 flag for the remote CPU.
                                         Writing 0 has no effect. Notes: [1] Normally, each CPU will clear (acknowledge)
                                         only its own local flags. This mechanism may be useful if the remote CPU is
                                         non- responsive. Reset type: SYSRSn */
            __IOM uint32_t IPC12 : 1; /*!< [12:12] : Writing 1 to this bit clears the IPC12 flag for the remote CPU.
                                         Writing 0 has no effect. Notes: [1] Normally, each CPU will clear (acknowledge)
                                         only its own local flags. This mechanism may be useful if the remote CPU is
                                         non- responsive. Reset type: SYSRSn */
            __IOM uint32_t IPC13 : 1; /*!< [13:13] : Writing 1 to this bit clears the IPC13 flag for the remote CPU.
                                         Writing 0 has no effect. Notes: [1] Normally, each CPU will clear (acknowledge)
                                         only its own local flags. This mechanism may be useful if the remote CPU is
                                         non- responsive. Reset type: SYSRSn */
            __IOM uint32_t IPC14 : 1; /*!< [14:14] : Writing 1 to this bit clears the IPC14 flag for the remote CPU.
                                         Writing 0 has no effect. Notes: [1] Normally, each CPU will clear (acknowledge)
                                         only its own local flags. This mechanism may be useful if the remote CPU is
                                         non- responsive. Reset type: SYSRSn */
            __IOM uint32_t IPC15 : 1; /*!< [15:15] : Writing 1 to this bit clears the IPC15 flag for the remote CPU.
                                         Writing 0 has no effect. Notes: [1] Normally, each CPU will clear (acknowledge)
                                         only its own local flags. This mechanism may be useful if the remote CPU is
                                         non- responsive. Reset type: SYSRSn */
            __IOM uint32_t IPC16 : 1; /*!< [16:16] : Writing 1 to this bit clears the IPC16 flag for the remote CPU.
                                         Writing 0 has no effect. Notes: [1] Normally, each CPU will clear (acknowledge)
                                         only its own local flags. This mechanism may be useful if the remote CPU is
                                         non- responsive. Reset type: SYSRSn */
            __IOM uint32_t IPC17 : 1; /*!< [17:17] : Writing 1 to this bit clears the IPC17 flag for the remote CPU.
                                         Writing 0 has no effect. Notes: [1] Normally, each CPU will clear (acknowledge)
                                         only its own local flags. This mechanism may be useful if the remote CPU is
                                         non- responsive. Reset type: SYSRSn */
            __IOM uint32_t IPC18 : 1; /*!< [18:18] : Writing 1 to this bit clears the IPC18 flag for the remote CPU.
                                         Writing 0 has no effect. Notes: [1] Normally, each CPU will clear (acknowledge)
                                         only its own local flags. This mechanism may be useful if the remote CPU is
                                         non- responsive. Reset type: SYSRSn */
            __IOM uint32_t IPC19 : 1; /*!< [19:19] : Writing 1 to this bit clears the IPC19 flag for the remote CPU.
                                         Writing 0 has no effect. Notes: [1] Normally, each CPU will clear (acknowledge)
                                         only its own local flags. This mechanism may be useful if the remote CPU is
                                         non- responsive. Reset type: SYSRSn */
            __IOM uint32_t IPC20 : 1; /*!< [20:20] : Writing 1 to this bit clears the IPC20 flag for the remote CPU.
                                         Writing 0 has no effect. Notes: [1] Normally, each CPU will clear (acknowledge)
                                         only its own local flags. This mechanism may be useful if the remote CPU is
                                         non- responsive. Reset type: SYSRSn */
            __IOM uint32_t IPC21 : 1; /*!< [21:21] : Writing 1 to this bit clears the IPC21 flag for the remote CPU.
                                         Writing 0 has no effect. Notes: [1] Normally, each CPU will clear (acknowledge)
                                         only its own local flags. This mechanism may be useful if the remote CPU is
                                         non- responsive. Reset type: SYSRSn */
            __IOM uint32_t IPC22 : 1; /*!< [22:22] : Writing 1 to this bit clears the IPC22 flag for the remote CPU.
                                         Writing 0 has no effect. Notes: [1] Normally, each CPU will clear (acknowledge)
                                         only its own local flags. This mechanism may be useful if the remote CPU is
                                         non- responsive. Reset type: SYSRSn */
            __IOM uint32_t IPC23 : 1; /*!< [23:23] : Writing 1 to this bit clears the IPC23 flag for the remote CPU.
                                         Writing 0 has no effect. Notes: [1] Normally, each CPU will clear (acknowledge)
                                         only its own local flags. This mechanism may be useful if the remote CPU is
                                         non- responsive. Reset type: SYSRSn */
            __IOM uint32_t IPC24 : 1; /*!< [24:24] : Writing 1 to this bit clears the IPC24 flag for the remote CPU.
                                         Writing 0 has no effect. Notes: [1] Normally, each CPU will clear (acknowledge)
                                         only its own local flags. This mechanism may be useful if the remote CPU is
                                         non- responsive. Reset type: SYSRSn */
            __IOM uint32_t IPC25 : 1; /*!< [25:25] : Writing 1 to this bit clears the IPC25 flag for the remote CPU.
                                         Writing 0 has no effect. Notes: [1] Normally, each CPU will clear (acknowledge)
                                         only its own local flags. This mechanism may be useful if the remote CPU is
                                         non- responsive. Reset type: SYSRSn */
            __IOM uint32_t IPC26 : 1; /*!< [26:26] : Writing 1 to this bit clears the IPC26 flag for the remote CPU.
                                         Writing 0 has no effect. Notes: [1] Normally, each CPU will clear (acknowledge)
                                         only its own local flags. This mechanism may be useful if the remote CPU is
                                         non- responsive. Reset type: SYSRSn */
            __IOM uint32_t IPC27 : 1; /*!< [27:27] : Writing 1 to this bit clears the IPC27 flag for the remote CPU.
                                         Writing 0 has no effect. Notes: [1] Normally, each CPU will clear (acknowledge)
                                         only its own local flags. This mechanism may be useful if the remote CPU is
                                         non- responsive. Reset type: SYSRSn */
            __IOM uint32_t IPC28 : 1; /*!< [28:28] : Writing 1 to this bit clears the IPC28 flag for the remote CPU.
                                         Writing 0 has no effect. Notes: [1] Normally, each CPU will clear (acknowledge)
                                         only its own local flags. This mechanism may be useful if the remote CPU is
                                         non- responsive. Reset type: SYSRSn */
            __IOM uint32_t IPC29 : 1; /*!< [29:29] : Writing 1 to this bit clears the IPC29 flag for the remote CPU.
                                         Writing 0 has no effect. Notes: [1] Normally, each CPU will clear (acknowledge)
                                         only its own local flags. This mechanism may be useful if the remote CPU is
                                         non- responsive. Reset type: SYSRSn */
            __IOM uint32_t IPC30 : 1; /*!< [30:30] : Writing 1 to this bit clears the IPC30 flag for the remote CPU.
                                         Writing 0 has no effect. Notes: [1] Normally, each CPU will clear (acknowledge)
                                         only its own local flags. This mechanism may be useful if the remote CPU is
                                         non- responsive. Reset type: SYSRSn */
            __IOM uint32_t IPC31 : 1; /*!< [31:31] : Writing 1 to this bit clears the IPC31 flag for the remote CPU.
                                         Writing 0 has no effect. Notes: [1] Normally, each CPU will clear (acknowledge)
                                         only its own local flags. This mechanism may be useful if the remote CPU is
                                         non- responsive. Reset type: SYSRSn */
        } IPCCLRb;
    };

    union
    {
        __IM uint32_t IPCFLG; /*!< 0x00000010 : IPC remote flag status register */

        struct
        {
            __IM uint32_t IPC0 : 1; /*!< [ 0: 0] : Indicates to the local CPU whether the remote IPC0 event flag is set.
                                                   0: The remote IPC0 event flag is not set 1: The remote IPC0 event
                                       flag is set Notes: [1] IPC event flags 0-3 will trigger interrupts in the
                                       receiving CPU via the ePIE. Reset type: SYSRSn */
            __IM uint32_t IPC1 : 1; /*!< [ 1: 1] : Indicates to the local CPU whether the remote IPC1 event flag is set.
                                                   0: The remote IPC1 event flag is not set 1: The remote IPC1 event
                                       flag is set Notes: [1] IPC event flags 0-3 will trigger interrupts in the
                                       receiving CPU via the ePIE. Reset type: SYSRSn */
            __IM uint32_t IPC2 : 1; /*!< [ 2: 2] : Indicates to the local CPU whether the remote IPC2 event flag is set.
                                                   0: The remote IPC2 event flag is not set 1: The remote IPC2 event
                                       flag is set Notes: [1] IPC event flags 0-3 will trigger interrupts in the
                                       receiving CPU via the ePIE. Reset type: SYSRSn */
            __IM uint32_t IPC3 : 1; /*!< [ 3: 3] : Indicates to the local CPU whether the remote IPC3 event flag is set.
                                                   0: The remote IPC3 event flag is not set 1: The remote IPC3 event
                                       flag is set Notes: [1] IPC event flags 0-3 will trigger interrupts in the
                                       receiving CPU via the ePIE. Reset type: SYSRSn */
            __IM uint32_t IPC4 : 1; /*!< [ 4: 4] : Indicates to the local CPU whether the remote IPC4 event flag is set.
                                                   0: The remote IPC4 event flag is not set 1: The remote IPC4 event
                                       flag is set Reset type: SYSRSn */
            __IM uint32_t IPC5 : 1; /*!< [ 5: 5] : Indicates to the local CPU whether the remote IPC5 event flag is set.
                                                   0: The remote IPC5 event flag is not set 1: The remote IPC5 event
                                       flag is set Reset type: SYSRSn */
            __IM uint32_t IPC6 : 1; /*!< [ 6: 6] : Indicates to the local CPU whether the remote IPC6 event flag is set.
                                                   0: The remote IPC6 event flag is not set 1: The remote IPC6 event
                                       flag is set Reset type: SYSRSn */
            __IM uint32_t IPC7 : 1; /*!< [ 7: 7] : Indicates to the local CPU whether the remote IPC7 event flag is set.
                                                   0: The remote IPC7 event flag is not set 1: The remote IPC7 event
                                       flag is set Reset type: SYSRSn */
            __IM uint32_t IPC8 : 1; /*!< [ 8: 8] : Indicates to the local CPU whether the remote IPC8 event flag is set.
                                                   0: The remote IPC8 event flag is not set 1: The remote IPC8 event
                                       flag is set Reset type: SYSRSn */
            __IM uint32_t IPC9 : 1; /*!< [ 9: 9] : Indicates to the local CPU whether the remote IPC9 event flag is set.
                                                   0: The remote IPC9 event flag is not set 1: The remote IPC9 event
                                       flag is set Reset type: SYSRSn */
            __IM uint32_t IPC10 : 1; /*!< [10:10] : Indicates to the local CPU whether the remote IPC10 event flag is
                                        set. 0: The remote IPC10 event flag is not set 1: The remote IPC10 event flag is
                                        set Reset type: SYSRSn */
            __IM uint32_t IPC11 : 1; /*!< [11:11] : Indicates to the local CPU whether the remote IPC11 event flag is
                                        set. 0: The remote IPC11 event flag is not set 1: The remote IPC11 event flag is
                                        set Reset type: SYSRSn */
            __IM uint32_t IPC12 : 1; /*!< [12:12] : Indicates to the local CPU whether the remote IPC12 event flag is
                                        set. 0: The remote IPC12 event flag is not set 1: The remote IPC12 event flag is
                                        set Reset type: SYSRSn */
            __IM uint32_t IPC13 : 1; /*!< [13:13] : Indicates to the local CPU whether the remote IPC13 event flag is
                                        set. 0: The remote IPC13 event flag is not set 1: The remote IPC13 event flag is
                                        set Reset type: SYSRSn */
            __IM uint32_t IPC14 : 1; /*!< [14:14] : Indicates to the local CPU whether the remote IPC14 event flag is
                                        set. 0: The remote IPC14 event flag is not set 1: The remote IPC14 event flag is
                                        set Reset type: SYSRSn */
            __IM uint32_t IPC15 : 1; /*!< [15:15] : Indicates to the local CPU whether the remote IPC15 event flag is
                                        set. 0: The remote IPC15 event flag is not set 1: The remote IPC15 event flag is
                                        set Reset type: SYSRSn */
            __IM uint32_t IPC16 : 1; /*!< [16:16] : Indicates to the local CPU whether the remote IPC16 event flag is
                                        set. 0: The remote IPC16 event flag is not set 1: The remote IPC16 event flag is
                                        set Reset type: SYSRSn */
            __IM uint32_t IPC17 : 1; /*!< [17:17] : Indicates to the local CPU whether the remote IPC17 event flag is
                                        set. 0: The remote IPC17 event flag is not set 1: The remote IPC17 event flag is
                                        set Reset type: SYSRSn */
            __IM uint32_t IPC18 : 1; /*!< [18:18] : Indicates to the local CPU whether the remote IPC18 event flag is
                                        set. 0: The remote IPC18 event flag is not set 1: The remote IPC18 event flag is
                                        set Reset type: SYSRSn */
            __IM uint32_t IPC19 : 1; /*!< [19:19] : Indicates to the local CPU whether the remote IPC19 event flag is
                                        set. 0: The remote IPC19 event flag is not set 1: The remote IPC19 event flag is
                                        set Reset type: SYSRSn */
            __IM uint32_t IPC20 : 1; /*!< [20:20] : Indicates to the local CPU whether the remote IPC20 event flag is
                                        set. 0: The remote IPC20 event flag is not set 1: The remote IPC20 event flag is
                                        set Reset type: SYSRSn */
            __IM uint32_t IPC21 : 1; /*!< [21:21] : Indicates to the local CPU whether the remote IPC21 event flag is
                                        set. 0: The remote IPC21 event flag is not set 1: The remote IPC21 event flag is
                                        set Reset type: SYSRSn */
            __IM uint32_t IPC22 : 1; /*!< [22:22] : Indicates to the local CPU whether the remote IPC22 event flag is
                                        set. 0: The remote IPC22 event flag is not set 1: The remote IPC22 event flag is
                                        set Reset type: SYSRSn */
            __IM uint32_t IPC23 : 1; /*!< [23:23] : Indicates to the local CPU whether the remote IPC23 event flag is
                                        set. 0: The remote IPC23 event flag is not set 1: The remote IPC23 event flag is
                                        set Reset type: SYSRSn */
            __IM uint32_t IPC24 : 1; /*!< [24:24] : Indicates to the local CPU whether the remote IPC24 event flag is
                                        set. 0: The remote IPC24 event flag is not set 1: The remote IPC24 event flag is
                                        set Reset type: SYSRSn */
            __IM uint32_t IPC25 : 1; /*!< [25:25] : Indicates to the local CPU whether the remote IPC25 event flag is
                                        set. 0: The remote IPC25 event flag is not set 1: The remote IPC25 event flag is
                                        set Reset type: SYSRSn */
            __IM uint32_t IPC26 : 1; /*!< [26:26] : Indicates to the local CPU whether the remote IPC26 event flag is
                                        set. 0: The remote IPC26 event flag is not set 1: The remote IPC26 event flag is
                                        set Reset type: SYSRSn */
            __IM uint32_t IPC27 : 1; /*!< [27:27] : Indicates to the local CPU whether the remote IPC27 event flag is
                                        set. 0: The remote IPC27 event flag is not set 1: The remote IPC27 event flag is
                                        set Reset type: SYSRSn */
            __IM uint32_t IPC28 : 1; /*!< [28:28] : Indicates to the local CPU whether the remote IPC28 event flag is
                                        set. 0: The remote IPC28 event flag is not set 1: The remote IPC28 event flag is
                                        set Reset type: SYSRSn */
            __IM uint32_t IPC29 : 1; /*!< [29:29] : Indicates to the local CPU whether the remote IPC29 event flag is
                                        set. 0: The remote IPC29 event flag is not set 1: The remote IPC29 event flag is
                                        set Reset type: SYSRSn */
            __IM uint32_t IPC30 : 1; /*!< [30:30] : Indicates to the local CPU whether the remote IPC30 event flag is
                                        set. 0: The remote IPC30 event flag is not set 1: The remote IPC30 event flag is
                                        set Reset type: SYSRSn */
            __IM uint32_t IPC31 : 1; /*!< [31:31] : Indicates to the local CPU whether the remote IPC31 event flag is
                                        set. 0: The remote IPC31 event flag is not set 1: The remote IPC31 event flag is
                                        set Reset type: SYSRSn */
        } IPCFLGb;
    };

    uint8_t RSV_0X14[4]; /*!< 0x00000014~0x00000017 : reserved */

    union
    {
        __IM uint32_t IPCCOUNTERL; /*!< 0x00000018 : IPC Counter Low Register */

        struct
        {
            __IM uint32_t COUNT : 32; /*!< [31: 0] : This is the lower 32-bits of free running 64 bit timestamp counter
                                         clocked by the PLLSYSCLK. Reset type: CPU2.SYSRSn */
        } IPCCOUNTERLb;
    };

    union
    {
        __IM uint32_t IPCCOUNTERH; /*!< 0x0000001c : IPC Counter High Register */

        struct
        {
            __IM uint32_t COUNT : 32; /*!< [31: 0] : This is the upper 32-bits of free running 64 bit timestamp counter
                                         clocked by the PLLSYSCLK. Reset type: CPU2.SYSRSn */
        } IPCCOUNTERHb;
    };

    union
    {
        __IM uint32_t IPCRECVCOM; /*!< 0x00000020 : Remote to Local IPC Command Register */

        struct
        {
            __IM uint32_t
                COMMAND : 32; /*!< [31: 0] : This is a general purpose register used to receive software-defined
                                 commands from the remote CPU. It can only be written by the remote CPU. Notes [1] The
                                 local CPU's IPCRECVCOM is the same physical register as the remote CPU's IPCSENDCOM,
                                 and is located at the same address in both CPUs. [2] This register is reset by a SYRSn
                                 of the remote CPU Reset type: CPUx.SYSRSn */
        } IPCRECVCOMb;
    };

    union
    {
        __IM uint32_t IPCRECVADDR; /*!< 0x00000024 : Remote to Local IPC Address Register */

        struct
        {
            __IM uint32_t
                ADDRESS : 32; /*!< [31: 0] : This is a general purpose register used to receive software-defined
                                 addresses from the remote CPU. It can only be written by the remote CPU. Notes [1] The
                                 local CPU's IPCRECVADDR is the same physical register as the remote CPU's IPCSENDADDR,
                                 and is located at the same address in both CPUs. [2] This register is reset by a SYRSn
                                 of the remote CPU Reset type: CPUx.SYSRSn */
        } IPCRECVADDRb;
    };

    union
    {
        __IM uint32_t IPCRECVDATA; /*!< 0x00000028 : Remote to Local IPC Data Register */

        struct
        {
            __IM uint32_t WDATA : 32; /*!< [31: 0] : This is a general purpose register used to receive software-defined
                                         data from the remote CPU. It can only be written by the remote CPU. Notes [1]
                                         The local CPU's IPCRECVDATA is the same physical register as the remote CPU's
                                         IPCSENDDATA, and is located at the same address in both CPUs. [2] This register
                                         is reset by a SYRSn of the remote CPU Reset type: CPUx.SYSRSn */
        } IPCRECVDATAb;
    };

    union
    {
        __IOM uint32_t IPCLOCALREPLY; /*!< 0x0000002c : Local to Remote IPC Reply Data Register */

        struct
        {
            __IOM uint32_t
                RDATA : 32; /*!< [31: 0] : This is a general purpose register used to send software-defined data to the
                               remote CPU in response to a command. It can only be written by the local CPU. Notes [1]
                               The local CPU's IPCLOCALREPLY is the same physical register as the remote CPU's
                               IPCREMOTEREPLY, and is located at the same address in both CPUs. Reset type: SYSRSn */
        } IPCLOCALREPLYb;
    };

    union
    {
        __IOM uint32_t IPCSENDCOM; /*!< 0x00000030 : Local to Remote IPC Command Register */

        struct
        {
            __IOM uint32_t COMMAND : 32; /*!< [31: 0] : This is a general purpose register used to send software-defined
                                            commands to the remote CPU. It can only be written by the local CPU. Notes
                                                        [1] The local CPU's IPCSENDCOM is the same physical register as
                                            the remote CPU's IPCRECVCOM, and is located at the same address in both
                                            CPUs. Reset type: SYSRSn */
        } IPCSENDCOMb;
    };

    union
    {
        __IOM uint32_t IPCSENDADDR; /*!< 0x00000034 : Local to Remote IPC Address Register */

        struct
        {
            __IOM uint32_t ADDRESS : 32; /*!< [31: 0] : This is a general purpose register used to send software-defined
                                            addresses to the remote CPU. It can only be written by the local CPU. Notes
                                                        [1] The local CPU's IPCSENDADDR is the same physical register as
                                            the remote CPU's IPCRECVDATA, and is located at the same address in both
                                            CPUs. Reset type: SYSRSn */
        } IPCSENDADDRb;
    };

    union
    {
        __IOM uint32_t IPCSENDDATA; /*!< 0x00000038 : Local to Remote IPC Data Register */

        struct
        {
            __IOM uint32_t
                WDATA : 32; /*!< [31: 0] : This is a general purpose register used to receive software-defined data from
                               the remote CPU. It can only be written by the remote CPU. Notes [1] The local CPU's
                               IPCRECVDATA is the same physical register as the remote CPU's IPCSENDDATA, and is located
                               at the same address in both CPUs. [2] This register is reset by a SYRSn of the remote CPU
                               Reset type: CPUx.SYSRSn */
        } IPCSENDDATAb;
    };

    union
    {
        __IM uint32_t IPCREMOTEREPLY; /*!< 0x0000003c : Remote to Local IPC Reply Data Register */

        struct
        {
            __IM uint32_t
                RDATA : 32; /*!< [31: 0] : This is a general purpose register used to receive software-defined data from
                               the remote CPU's response to a command. It can only be written by the remote CPU. Notes
                                           [1] The local CPU's IPCREMOTEREPLY is the same physical register as the
                               remote CPU's IPCLOCALREPLY, and is located at the same address in both CPUs. [2] This
                               register is reset by a SYRSn of the remote CPU Reset type: CPUx.SYSRSn */
        } IPCREMOTEREPLYb;
    };

    union
    {
        __IOM uint32_t IPCBOOTSTS; /*!< 0x00000040 : CPU2 to CPU2 IPC Boot Status Register */

        struct
        {
            __IOM uint32_t
                BOOTSTS : 32; /*!< [31: 0] : This register is used by CPU2 to pass the boot Status to CPU0. The
                                             data format is software-defined. It can only be written by CPU2.
                                             Reset type: CPU2.SYSRSn */
        } IPCBOOTSTSb;
    };

    union
    {
        __IM uint32_t IPCBOOTMODE; /*!< 0x00000044 : CPU2 to CPU2 IPC Boot Mode Register */

        struct
        {
            __IM uint32_t BOOTMODE : 32; /*!< [31: 0] : This register is used by CPU0 to pass a boot mode information to
                                            CPU2. The data format is software-defined. It can only be written by CPU0.
                                                        Reset type: CPU0.SYSRSn */
        } IPCBOOTMODEb;
    };

    uint8_t RSV_0X48[56]; /*!< 0x00000048~0x0000007f : reserved */

    union
    {
        __IOM uint32_t IPCMISC; /*!< 0x00000080 : IPC Misc Configuration */

        struct
        {
            __IOM uint32_t LS     : 1; /*!< [ 0: 0] : Light Sleep input. */
            __IOM uint32_t WPULSE : 3; /*!< [ 3: 1] : Write access pulse to control pulse width of negative voltage on
                                          SRAM bitline. */
            __IOM uint32_t
                WA : 3;            /*!< [ 6: 4] : wa[2] : Write assist enable pin(Active High)
                                                  wa[1:0]: write assit pins to control negative voltage on SRAM bitline */
            __IOM uint32_t RA : 2; /*!< [ 8: 7] : read assit pins to control WL under-dirve. */
            __IOM uint32_t
                RM : 4; /*!< [12: 9] : rm[1:0] = 2'b00 is the slowest possible mode of operation for the memory. This
                           setting is required for VDDMIN operation rm[1:0] values control access time and cycle time of
                           the memory. Refer to the timing table for more details. rm[3:2] are factory pins reserved for
                           debug mode. User should tie these pins to logic 0 */
            __IOM uint32_t RME    : 1; /*!< [13:13] : read-Write margin enable input. */
            __IOM uint32_t ME     : 1; /*!< [14:14] : Memory Enable bit, when this bit is H, memory is enable. */
            __IOM uint32_t TEST1  : 1; /*!< [15:15] : memory test1 bit, default is Zero, please don't write it. */
            __IOM uint32_t MISC   : 8; /*!< [23:16] : misc register for ECO. */
            __IOM uint32_t ERRINT : 1; /*!< [24:24] : msg share ram ecc error, owner is cpu0, latch the err into this
                                          flag, when firmware write one to clear it. */
            uint32_t RSV_0 : 7;        /*!< [31:25] : reserved. */
        } IPCMISCb;
    };

    uint8_t RSV_0X84[3964]; // 0x00000084~0x00000fff : reserved
} IPC_REGS_CPU2_Type;

/*!
 * @}
 */


/*!
 * \name IPC_CPU2 Base Address Definitions
 *
 * @{
 */

/*! \brief IPC_REGS_CPU2 base address */
#define IPC_REGS_CPU2_BASE (0x40000000UL)
/*! \brief IPC_REGS_CPU2 base pointer */
#define IPC_REGS_CPU2 ((IPC_REGS_CPU2_Type *)IPC_REGS_CPU2_BASE)


/*!
 * @}
 */


/*!
 * \name IPC_CPU2 Register Bitfield Definitions
 *
 * @{
 */

/* IPCACK bitfield */
#define IPC_REGS_CPU2_IPCACK_IPC31_Pos (31U)                                    /*!< IPC31 Position  31         */
#define IPC_REGS_CPU2_IPCACK_IPC31_Msk (0x1U << IPC_REGS_CPU2_IPCACK_IPC31_Pos) /*!< IPC31 Mask      0x80000000 */
#define IPC_REGS_CPU2_IPCACK_IPC31_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCACK_IPC31_Pos) & IPC_REGS_CPU2_IPCACK_IPC31_Msk) /*!< IPC31 Set Value */
#define IPC_REGS_CPU2_IPCACK_IPC31_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCACK_IPC31_Msk) >> IPC_REGS_CPU2_IPCACK_IPC31_Pos) /*!< IPC31 Get Value */

#define IPC_REGS_CPU2_IPCACK_IPC30_Pos (30U)                                    /*!< IPC30 Position  30         */
#define IPC_REGS_CPU2_IPCACK_IPC30_Msk (0x1U << IPC_REGS_CPU2_IPCACK_IPC30_Pos) /*!< IPC30 Mask      0x40000000 */
#define IPC_REGS_CPU2_IPCACK_IPC30_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCACK_IPC30_Pos) & IPC_REGS_CPU2_IPCACK_IPC30_Msk) /*!< IPC30 Set Value */
#define IPC_REGS_CPU2_IPCACK_IPC30_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCACK_IPC30_Msk) >> IPC_REGS_CPU2_IPCACK_IPC30_Pos) /*!< IPC30 Get Value */

#define IPC_REGS_CPU2_IPCACK_IPC29_Pos (29U)                                    /*!< IPC29 Position  29         */
#define IPC_REGS_CPU2_IPCACK_IPC29_Msk (0x1U << IPC_REGS_CPU2_IPCACK_IPC29_Pos) /*!< IPC29 Mask      0x20000000 */
#define IPC_REGS_CPU2_IPCACK_IPC29_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCACK_IPC29_Pos) & IPC_REGS_CPU2_IPCACK_IPC29_Msk) /*!< IPC29 Set Value */
#define IPC_REGS_CPU2_IPCACK_IPC29_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCACK_IPC29_Msk) >> IPC_REGS_CPU2_IPCACK_IPC29_Pos) /*!< IPC29 Get Value */

#define IPC_REGS_CPU2_IPCACK_IPC28_Pos (28U)                                    /*!< IPC28 Position  28         */
#define IPC_REGS_CPU2_IPCACK_IPC28_Msk (0x1U << IPC_REGS_CPU2_IPCACK_IPC28_Pos) /*!< IPC28 Mask      0x10000000 */
#define IPC_REGS_CPU2_IPCACK_IPC28_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCACK_IPC28_Pos) & IPC_REGS_CPU2_IPCACK_IPC28_Msk) /*!< IPC28 Set Value */
#define IPC_REGS_CPU2_IPCACK_IPC28_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCACK_IPC28_Msk) >> IPC_REGS_CPU2_IPCACK_IPC28_Pos) /*!< IPC28 Get Value */

#define IPC_REGS_CPU2_IPCACK_IPC27_Pos (27U)                                    /*!< IPC27 Position  27         */
#define IPC_REGS_CPU2_IPCACK_IPC27_Msk (0x1U << IPC_REGS_CPU2_IPCACK_IPC27_Pos) /*!< IPC27 Mask      0x08000000 */
#define IPC_REGS_CPU2_IPCACK_IPC27_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCACK_IPC27_Pos) & IPC_REGS_CPU2_IPCACK_IPC27_Msk) /*!< IPC27 Set Value */
#define IPC_REGS_CPU2_IPCACK_IPC27_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCACK_IPC27_Msk) >> IPC_REGS_CPU2_IPCACK_IPC27_Pos) /*!< IPC27 Get Value */

#define IPC_REGS_CPU2_IPCACK_IPC26_Pos (26U)                                    /*!< IPC26 Position  26         */
#define IPC_REGS_CPU2_IPCACK_IPC26_Msk (0x1U << IPC_REGS_CPU2_IPCACK_IPC26_Pos) /*!< IPC26 Mask      0x04000000 */
#define IPC_REGS_CPU2_IPCACK_IPC26_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCACK_IPC26_Pos) & IPC_REGS_CPU2_IPCACK_IPC26_Msk) /*!< IPC26 Set Value */
#define IPC_REGS_CPU2_IPCACK_IPC26_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCACK_IPC26_Msk) >> IPC_REGS_CPU2_IPCACK_IPC26_Pos) /*!< IPC26 Get Value */

#define IPC_REGS_CPU2_IPCACK_IPC25_Pos (25U)                                    /*!< IPC25 Position  25         */
#define IPC_REGS_CPU2_IPCACK_IPC25_Msk (0x1U << IPC_REGS_CPU2_IPCACK_IPC25_Pos) /*!< IPC25 Mask      0x02000000 */
#define IPC_REGS_CPU2_IPCACK_IPC25_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCACK_IPC25_Pos) & IPC_REGS_CPU2_IPCACK_IPC25_Msk) /*!< IPC25 Set Value */
#define IPC_REGS_CPU2_IPCACK_IPC25_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCACK_IPC25_Msk) >> IPC_REGS_CPU2_IPCACK_IPC25_Pos) /*!< IPC25 Get Value */

#define IPC_REGS_CPU2_IPCACK_IPC24_Pos (24U)                                    /*!< IPC24 Position  24         */
#define IPC_REGS_CPU2_IPCACK_IPC24_Msk (0x1U << IPC_REGS_CPU2_IPCACK_IPC24_Pos) /*!< IPC24 Mask      0x01000000 */
#define IPC_REGS_CPU2_IPCACK_IPC24_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCACK_IPC24_Pos) & IPC_REGS_CPU2_IPCACK_IPC24_Msk) /*!< IPC24 Set Value */
#define IPC_REGS_CPU2_IPCACK_IPC24_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCACK_IPC24_Msk) >> IPC_REGS_CPU2_IPCACK_IPC24_Pos) /*!< IPC24 Get Value */

#define IPC_REGS_CPU2_IPCACK_IPC23_Pos (23U)                                    /*!< IPC23 Position  23         */
#define IPC_REGS_CPU2_IPCACK_IPC23_Msk (0x1U << IPC_REGS_CPU2_IPCACK_IPC23_Pos) /*!< IPC23 Mask      0x00800000 */
#define IPC_REGS_CPU2_IPCACK_IPC23_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCACK_IPC23_Pos) & IPC_REGS_CPU2_IPCACK_IPC23_Msk) /*!< IPC23 Set Value */
#define IPC_REGS_CPU2_IPCACK_IPC23_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCACK_IPC23_Msk) >> IPC_REGS_CPU2_IPCACK_IPC23_Pos) /*!< IPC23 Get Value */

#define IPC_REGS_CPU2_IPCACK_IPC22_Pos (22U)                                    /*!< IPC22 Position  22         */
#define IPC_REGS_CPU2_IPCACK_IPC22_Msk (0x1U << IPC_REGS_CPU2_IPCACK_IPC22_Pos) /*!< IPC22 Mask      0x00400000 */
#define IPC_REGS_CPU2_IPCACK_IPC22_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCACK_IPC22_Pos) & IPC_REGS_CPU2_IPCACK_IPC22_Msk) /*!< IPC22 Set Value */
#define IPC_REGS_CPU2_IPCACK_IPC22_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCACK_IPC22_Msk) >> IPC_REGS_CPU2_IPCACK_IPC22_Pos) /*!< IPC22 Get Value */

#define IPC_REGS_CPU2_IPCACK_IPC21_Pos (21U)                                    /*!< IPC21 Position  21         */
#define IPC_REGS_CPU2_IPCACK_IPC21_Msk (0x1U << IPC_REGS_CPU2_IPCACK_IPC21_Pos) /*!< IPC21 Mask      0x00200000 */
#define IPC_REGS_CPU2_IPCACK_IPC21_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCACK_IPC21_Pos) & IPC_REGS_CPU2_IPCACK_IPC21_Msk) /*!< IPC21 Set Value */
#define IPC_REGS_CPU2_IPCACK_IPC21_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCACK_IPC21_Msk) >> IPC_REGS_CPU2_IPCACK_IPC21_Pos) /*!< IPC21 Get Value */

#define IPC_REGS_CPU2_IPCACK_IPC20_Pos (20U)                                    /*!< IPC20 Position  20         */
#define IPC_REGS_CPU2_IPCACK_IPC20_Msk (0x1U << IPC_REGS_CPU2_IPCACK_IPC20_Pos) /*!< IPC20 Mask      0x00100000 */
#define IPC_REGS_CPU2_IPCACK_IPC20_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCACK_IPC20_Pos) & IPC_REGS_CPU2_IPCACK_IPC20_Msk) /*!< IPC20 Set Value */
#define IPC_REGS_CPU2_IPCACK_IPC20_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCACK_IPC20_Msk) >> IPC_REGS_CPU2_IPCACK_IPC20_Pos) /*!< IPC20 Get Value */

#define IPC_REGS_CPU2_IPCACK_IPC19_Pos (19U)                                    /*!< IPC19 Position  19         */
#define IPC_REGS_CPU2_IPCACK_IPC19_Msk (0x1U << IPC_REGS_CPU2_IPCACK_IPC19_Pos) /*!< IPC19 Mask      0x00080000 */
#define IPC_REGS_CPU2_IPCACK_IPC19_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCACK_IPC19_Pos) & IPC_REGS_CPU2_IPCACK_IPC19_Msk) /*!< IPC19 Set Value */
#define IPC_REGS_CPU2_IPCACK_IPC19_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCACK_IPC19_Msk) >> IPC_REGS_CPU2_IPCACK_IPC19_Pos) /*!< IPC19 Get Value */

#define IPC_REGS_CPU2_IPCACK_IPC18_Pos (18U)                                    /*!< IPC18 Position  18         */
#define IPC_REGS_CPU2_IPCACK_IPC18_Msk (0x1U << IPC_REGS_CPU2_IPCACK_IPC18_Pos) /*!< IPC18 Mask      0x00040000 */
#define IPC_REGS_CPU2_IPCACK_IPC18_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCACK_IPC18_Pos) & IPC_REGS_CPU2_IPCACK_IPC18_Msk) /*!< IPC18 Set Value */
#define IPC_REGS_CPU2_IPCACK_IPC18_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCACK_IPC18_Msk) >> IPC_REGS_CPU2_IPCACK_IPC18_Pos) /*!< IPC18 Get Value */

#define IPC_REGS_CPU2_IPCACK_IPC17_Pos (17U)                                    /*!< IPC17 Position  17         */
#define IPC_REGS_CPU2_IPCACK_IPC17_Msk (0x1U << IPC_REGS_CPU2_IPCACK_IPC17_Pos) /*!< IPC17 Mask      0x00020000 */
#define IPC_REGS_CPU2_IPCACK_IPC17_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCACK_IPC17_Pos) & IPC_REGS_CPU2_IPCACK_IPC17_Msk) /*!< IPC17 Set Value */
#define IPC_REGS_CPU2_IPCACK_IPC17_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCACK_IPC17_Msk) >> IPC_REGS_CPU2_IPCACK_IPC17_Pos) /*!< IPC17 Get Value */

#define IPC_REGS_CPU2_IPCACK_IPC16_Pos (16U)                                    /*!< IPC16 Position  16         */
#define IPC_REGS_CPU2_IPCACK_IPC16_Msk (0x1U << IPC_REGS_CPU2_IPCACK_IPC16_Pos) /*!< IPC16 Mask      0x00010000 */
#define IPC_REGS_CPU2_IPCACK_IPC16_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCACK_IPC16_Pos) & IPC_REGS_CPU2_IPCACK_IPC16_Msk) /*!< IPC16 Set Value */
#define IPC_REGS_CPU2_IPCACK_IPC16_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCACK_IPC16_Msk) >> IPC_REGS_CPU2_IPCACK_IPC16_Pos) /*!< IPC16 Get Value */

#define IPC_REGS_CPU2_IPCACK_IPC15_Pos (15U)                                    /*!< IPC15 Position  15         */
#define IPC_REGS_CPU2_IPCACK_IPC15_Msk (0x1U << IPC_REGS_CPU2_IPCACK_IPC15_Pos) /*!< IPC15 Mask      0x00008000 */
#define IPC_REGS_CPU2_IPCACK_IPC15_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCACK_IPC15_Pos) & IPC_REGS_CPU2_IPCACK_IPC15_Msk) /*!< IPC15 Set Value */
#define IPC_REGS_CPU2_IPCACK_IPC15_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCACK_IPC15_Msk) >> IPC_REGS_CPU2_IPCACK_IPC15_Pos) /*!< IPC15 Get Value */

#define IPC_REGS_CPU2_IPCACK_IPC14_Pos (14U)                                    /*!< IPC14 Position  14         */
#define IPC_REGS_CPU2_IPCACK_IPC14_Msk (0x1U << IPC_REGS_CPU2_IPCACK_IPC14_Pos) /*!< IPC14 Mask      0x00004000 */
#define IPC_REGS_CPU2_IPCACK_IPC14_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCACK_IPC14_Pos) & IPC_REGS_CPU2_IPCACK_IPC14_Msk) /*!< IPC14 Set Value */
#define IPC_REGS_CPU2_IPCACK_IPC14_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCACK_IPC14_Msk) >> IPC_REGS_CPU2_IPCACK_IPC14_Pos) /*!< IPC14 Get Value */

#define IPC_REGS_CPU2_IPCACK_IPC13_Pos (13U)                                    /*!< IPC13 Position  13         */
#define IPC_REGS_CPU2_IPCACK_IPC13_Msk (0x1U << IPC_REGS_CPU2_IPCACK_IPC13_Pos) /*!< IPC13 Mask      0x00002000 */
#define IPC_REGS_CPU2_IPCACK_IPC13_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCACK_IPC13_Pos) & IPC_REGS_CPU2_IPCACK_IPC13_Msk) /*!< IPC13 Set Value */
#define IPC_REGS_CPU2_IPCACK_IPC13_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCACK_IPC13_Msk) >> IPC_REGS_CPU2_IPCACK_IPC13_Pos) /*!< IPC13 Get Value */

#define IPC_REGS_CPU2_IPCACK_IPC12_Pos (12U)                                    /*!< IPC12 Position  12         */
#define IPC_REGS_CPU2_IPCACK_IPC12_Msk (0x1U << IPC_REGS_CPU2_IPCACK_IPC12_Pos) /*!< IPC12 Mask      0x00001000 */
#define IPC_REGS_CPU2_IPCACK_IPC12_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCACK_IPC12_Pos) & IPC_REGS_CPU2_IPCACK_IPC12_Msk) /*!< IPC12 Set Value */
#define IPC_REGS_CPU2_IPCACK_IPC12_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCACK_IPC12_Msk) >> IPC_REGS_CPU2_IPCACK_IPC12_Pos) /*!< IPC12 Get Value */

#define IPC_REGS_CPU2_IPCACK_IPC11_Pos (11U)                                    /*!< IPC11 Position  11         */
#define IPC_REGS_CPU2_IPCACK_IPC11_Msk (0x1U << IPC_REGS_CPU2_IPCACK_IPC11_Pos) /*!< IPC11 Mask      0x00000800 */
#define IPC_REGS_CPU2_IPCACK_IPC11_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCACK_IPC11_Pos) & IPC_REGS_CPU2_IPCACK_IPC11_Msk) /*!< IPC11 Set Value */
#define IPC_REGS_CPU2_IPCACK_IPC11_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCACK_IPC11_Msk) >> IPC_REGS_CPU2_IPCACK_IPC11_Pos) /*!< IPC11 Get Value */

#define IPC_REGS_CPU2_IPCACK_IPC10_Pos (10U)                                    /*!< IPC10 Position  10         */
#define IPC_REGS_CPU2_IPCACK_IPC10_Msk (0x1U << IPC_REGS_CPU2_IPCACK_IPC10_Pos) /*!< IPC10 Mask      0x00000400 */
#define IPC_REGS_CPU2_IPCACK_IPC10_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCACK_IPC10_Pos) & IPC_REGS_CPU2_IPCACK_IPC10_Msk) /*!< IPC10 Set Value */
#define IPC_REGS_CPU2_IPCACK_IPC10_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCACK_IPC10_Msk) >> IPC_REGS_CPU2_IPCACK_IPC10_Pos) /*!< IPC10 Get Value */

#define IPC_REGS_CPU2_IPCACK_IPC9_Pos (9U)                                    /*!< IPC9 Position  9          */
#define IPC_REGS_CPU2_IPCACK_IPC9_Msk (0x1U << IPC_REGS_CPU2_IPCACK_IPC9_Pos) /*!< IPC9 Mask      0x00000200 */
#define IPC_REGS_CPU2_IPCACK_IPC9_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCACK_IPC9_Pos) & IPC_REGS_CPU2_IPCACK_IPC9_Msk) /*!< IPC9 Set Value */
#define IPC_REGS_CPU2_IPCACK_IPC9_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCACK_IPC9_Msk) >> IPC_REGS_CPU2_IPCACK_IPC9_Pos) /*!< IPC9 Get Value            */

#define IPC_REGS_CPU2_IPCACK_IPC8_Pos (8U)                                    /*!< IPC8 Position  8          */
#define IPC_REGS_CPU2_IPCACK_IPC8_Msk (0x1U << IPC_REGS_CPU2_IPCACK_IPC8_Pos) /*!< IPC8 Mask      0x00000100 */
#define IPC_REGS_CPU2_IPCACK_IPC8_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCACK_IPC8_Pos) & IPC_REGS_CPU2_IPCACK_IPC8_Msk) /*!< IPC8 Set Value */
#define IPC_REGS_CPU2_IPCACK_IPC8_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCACK_IPC8_Msk) >> IPC_REGS_CPU2_IPCACK_IPC8_Pos) /*!< IPC8 Get Value            */

#define IPC_REGS_CPU2_IPCACK_IPC7_Pos (7U)                                    /*!< IPC7 Position  7          */
#define IPC_REGS_CPU2_IPCACK_IPC7_Msk (0x1U << IPC_REGS_CPU2_IPCACK_IPC7_Pos) /*!< IPC7 Mask      0x00000080 */
#define IPC_REGS_CPU2_IPCACK_IPC7_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCACK_IPC7_Pos) & IPC_REGS_CPU2_IPCACK_IPC7_Msk) /*!< IPC7 Set Value */
#define IPC_REGS_CPU2_IPCACK_IPC7_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCACK_IPC7_Msk) >> IPC_REGS_CPU2_IPCACK_IPC7_Pos) /*!< IPC7 Get Value            */

#define IPC_REGS_CPU2_IPCACK_IPC6_Pos (6U)                                    /*!< IPC6 Position  6          */
#define IPC_REGS_CPU2_IPCACK_IPC6_Msk (0x1U << IPC_REGS_CPU2_IPCACK_IPC6_Pos) /*!< IPC6 Mask      0x00000040 */
#define IPC_REGS_CPU2_IPCACK_IPC6_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCACK_IPC6_Pos) & IPC_REGS_CPU2_IPCACK_IPC6_Msk) /*!< IPC6 Set Value */
#define IPC_REGS_CPU2_IPCACK_IPC6_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCACK_IPC6_Msk) >> IPC_REGS_CPU2_IPCACK_IPC6_Pos) /*!< IPC6 Get Value            */

#define IPC_REGS_CPU2_IPCACK_IPC5_Pos (5U)                                    /*!< IPC5 Position  5          */
#define IPC_REGS_CPU2_IPCACK_IPC5_Msk (0x1U << IPC_REGS_CPU2_IPCACK_IPC5_Pos) /*!< IPC5 Mask      0x00000020 */
#define IPC_REGS_CPU2_IPCACK_IPC5_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCACK_IPC5_Pos) & IPC_REGS_CPU2_IPCACK_IPC5_Msk) /*!< IPC5 Set Value */
#define IPC_REGS_CPU2_IPCACK_IPC5_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCACK_IPC5_Msk) >> IPC_REGS_CPU2_IPCACK_IPC5_Pos) /*!< IPC5 Get Value            */

#define IPC_REGS_CPU2_IPCACK_IPC4_Pos (4U)                                    /*!< IPC4 Position  4          */
#define IPC_REGS_CPU2_IPCACK_IPC4_Msk (0x1U << IPC_REGS_CPU2_IPCACK_IPC4_Pos) /*!< IPC4 Mask      0x00000010 */
#define IPC_REGS_CPU2_IPCACK_IPC4_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCACK_IPC4_Pos) & IPC_REGS_CPU2_IPCACK_IPC4_Msk) /*!< IPC4 Set Value */
#define IPC_REGS_CPU2_IPCACK_IPC4_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCACK_IPC4_Msk) >> IPC_REGS_CPU2_IPCACK_IPC4_Pos) /*!< IPC4 Get Value            */

#define IPC_REGS_CPU2_IPCACK_IPC3_Pos (3U)                                    /*!< IPC3 Position  3          */
#define IPC_REGS_CPU2_IPCACK_IPC3_Msk (0x1U << IPC_REGS_CPU2_IPCACK_IPC3_Pos) /*!< IPC3 Mask      0x00000008 */
#define IPC_REGS_CPU2_IPCACK_IPC3_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCACK_IPC3_Pos) & IPC_REGS_CPU2_IPCACK_IPC3_Msk) /*!< IPC3 Set Value */
#define IPC_REGS_CPU2_IPCACK_IPC3_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCACK_IPC3_Msk) >> IPC_REGS_CPU2_IPCACK_IPC3_Pos) /*!< IPC3 Get Value            */

#define IPC_REGS_CPU2_IPCACK_IPC2_Pos (2U)                                    /*!< IPC2 Position  2          */
#define IPC_REGS_CPU2_IPCACK_IPC2_Msk (0x1U << IPC_REGS_CPU2_IPCACK_IPC2_Pos) /*!< IPC2 Mask      0x00000004 */
#define IPC_REGS_CPU2_IPCACK_IPC2_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCACK_IPC2_Pos) & IPC_REGS_CPU2_IPCACK_IPC2_Msk) /*!< IPC2 Set Value */
#define IPC_REGS_CPU2_IPCACK_IPC2_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCACK_IPC2_Msk) >> IPC_REGS_CPU2_IPCACK_IPC2_Pos) /*!< IPC2 Get Value            */

#define IPC_REGS_CPU2_IPCACK_IPC1_Pos (1U)                                    /*!< IPC1 Position  1          */
#define IPC_REGS_CPU2_IPCACK_IPC1_Msk (0x1U << IPC_REGS_CPU2_IPCACK_IPC1_Pos) /*!< IPC1 Mask      0x00000002 */
#define IPC_REGS_CPU2_IPCACK_IPC1_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCACK_IPC1_Pos) & IPC_REGS_CPU2_IPCACK_IPC1_Msk) /*!< IPC1 Set Value */
#define IPC_REGS_CPU2_IPCACK_IPC1_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCACK_IPC1_Msk) >> IPC_REGS_CPU2_IPCACK_IPC1_Pos) /*!< IPC1 Get Value            */

#define IPC_REGS_CPU2_IPCACK_IPC0_Pos (0U)                                    /*!< IPC0 Position  0          */
#define IPC_REGS_CPU2_IPCACK_IPC0_Msk (0x1U << IPC_REGS_CPU2_IPCACK_IPC0_Pos) /*!< IPC0 Mask      0x00000001 */
#define IPC_REGS_CPU2_IPCACK_IPC0_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCACK_IPC0_Pos) & IPC_REGS_CPU2_IPCACK_IPC0_Msk) /*!< IPC0 Set Value */
#define IPC_REGS_CPU2_IPCACK_IPC0_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCACK_IPC0_Msk) >> IPC_REGS_CPU2_IPCACK_IPC0_Pos) /*!< IPC0 Get Value            */

/* IPCSTS bitfield */
#define IPC_REGS_CPU2_IPCSTS_IPC31_Pos (31U)                                    /*!< IPC31 Position  31         */
#define IPC_REGS_CPU2_IPCSTS_IPC31_Msk (0x1U << IPC_REGS_CPU2_IPCSTS_IPC31_Pos) /*!< IPC31 Mask      0x80000000 */
#define IPC_REGS_CPU2_IPCSTS_IPC31_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSTS_IPC31_Pos) & IPC_REGS_CPU2_IPCSTS_IPC31_Msk) /*!< IPC31 Set Value */
#define IPC_REGS_CPU2_IPCSTS_IPC31_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSTS_IPC31_Msk) >> IPC_REGS_CPU2_IPCSTS_IPC31_Pos) /*!< IPC31 Get Value */

#define IPC_REGS_CPU2_IPCSTS_IPC30_Pos (30U)                                    /*!< IPC30 Position  30         */
#define IPC_REGS_CPU2_IPCSTS_IPC30_Msk (0x1U << IPC_REGS_CPU2_IPCSTS_IPC30_Pos) /*!< IPC30 Mask      0x40000000 */
#define IPC_REGS_CPU2_IPCSTS_IPC30_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSTS_IPC30_Pos) & IPC_REGS_CPU2_IPCSTS_IPC30_Msk) /*!< IPC30 Set Value */
#define IPC_REGS_CPU2_IPCSTS_IPC30_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSTS_IPC30_Msk) >> IPC_REGS_CPU2_IPCSTS_IPC30_Pos) /*!< IPC30 Get Value */

#define IPC_REGS_CPU2_IPCSTS_IPC29_Pos (29U)                                    /*!< IPC29 Position  29         */
#define IPC_REGS_CPU2_IPCSTS_IPC29_Msk (0x1U << IPC_REGS_CPU2_IPCSTS_IPC29_Pos) /*!< IPC29 Mask      0x20000000 */
#define IPC_REGS_CPU2_IPCSTS_IPC29_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSTS_IPC29_Pos) & IPC_REGS_CPU2_IPCSTS_IPC29_Msk) /*!< IPC29 Set Value */
#define IPC_REGS_CPU2_IPCSTS_IPC29_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSTS_IPC29_Msk) >> IPC_REGS_CPU2_IPCSTS_IPC29_Pos) /*!< IPC29 Get Value */

#define IPC_REGS_CPU2_IPCSTS_IPC28_Pos (28U)                                    /*!< IPC28 Position  28         */
#define IPC_REGS_CPU2_IPCSTS_IPC28_Msk (0x1U << IPC_REGS_CPU2_IPCSTS_IPC28_Pos) /*!< IPC28 Mask      0x10000000 */
#define IPC_REGS_CPU2_IPCSTS_IPC28_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSTS_IPC28_Pos) & IPC_REGS_CPU2_IPCSTS_IPC28_Msk) /*!< IPC28 Set Value */
#define IPC_REGS_CPU2_IPCSTS_IPC28_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSTS_IPC28_Msk) >> IPC_REGS_CPU2_IPCSTS_IPC28_Pos) /*!< IPC28 Get Value */

#define IPC_REGS_CPU2_IPCSTS_IPC27_Pos (27U)                                    /*!< IPC27 Position  27         */
#define IPC_REGS_CPU2_IPCSTS_IPC27_Msk (0x1U << IPC_REGS_CPU2_IPCSTS_IPC27_Pos) /*!< IPC27 Mask      0x08000000 */
#define IPC_REGS_CPU2_IPCSTS_IPC27_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSTS_IPC27_Pos) & IPC_REGS_CPU2_IPCSTS_IPC27_Msk) /*!< IPC27 Set Value */
#define IPC_REGS_CPU2_IPCSTS_IPC27_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSTS_IPC27_Msk) >> IPC_REGS_CPU2_IPCSTS_IPC27_Pos) /*!< IPC27 Get Value */

#define IPC_REGS_CPU2_IPCSTS_IPC26_Pos (26U)                                    /*!< IPC26 Position  26         */
#define IPC_REGS_CPU2_IPCSTS_IPC26_Msk (0x1U << IPC_REGS_CPU2_IPCSTS_IPC26_Pos) /*!< IPC26 Mask      0x04000000 */
#define IPC_REGS_CPU2_IPCSTS_IPC26_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSTS_IPC26_Pos) & IPC_REGS_CPU2_IPCSTS_IPC26_Msk) /*!< IPC26 Set Value */
#define IPC_REGS_CPU2_IPCSTS_IPC26_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSTS_IPC26_Msk) >> IPC_REGS_CPU2_IPCSTS_IPC26_Pos) /*!< IPC26 Get Value */

#define IPC_REGS_CPU2_IPCSTS_IPC25_Pos (25U)                                    /*!< IPC25 Position  25         */
#define IPC_REGS_CPU2_IPCSTS_IPC25_Msk (0x1U << IPC_REGS_CPU2_IPCSTS_IPC25_Pos) /*!< IPC25 Mask      0x02000000 */
#define IPC_REGS_CPU2_IPCSTS_IPC25_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSTS_IPC25_Pos) & IPC_REGS_CPU2_IPCSTS_IPC25_Msk) /*!< IPC25 Set Value */
#define IPC_REGS_CPU2_IPCSTS_IPC25_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSTS_IPC25_Msk) >> IPC_REGS_CPU2_IPCSTS_IPC25_Pos) /*!< IPC25 Get Value */

#define IPC_REGS_CPU2_IPCSTS_IPC24_Pos (24U)                                    /*!< IPC24 Position  24         */
#define IPC_REGS_CPU2_IPCSTS_IPC24_Msk (0x1U << IPC_REGS_CPU2_IPCSTS_IPC24_Pos) /*!< IPC24 Mask      0x01000000 */
#define IPC_REGS_CPU2_IPCSTS_IPC24_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSTS_IPC24_Pos) & IPC_REGS_CPU2_IPCSTS_IPC24_Msk) /*!< IPC24 Set Value */
#define IPC_REGS_CPU2_IPCSTS_IPC24_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSTS_IPC24_Msk) >> IPC_REGS_CPU2_IPCSTS_IPC24_Pos) /*!< IPC24 Get Value */

#define IPC_REGS_CPU2_IPCSTS_IPC23_Pos (23U)                                    /*!< IPC23 Position  23         */
#define IPC_REGS_CPU2_IPCSTS_IPC23_Msk (0x1U << IPC_REGS_CPU2_IPCSTS_IPC23_Pos) /*!< IPC23 Mask      0x00800000 */
#define IPC_REGS_CPU2_IPCSTS_IPC23_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSTS_IPC23_Pos) & IPC_REGS_CPU2_IPCSTS_IPC23_Msk) /*!< IPC23 Set Value */
#define IPC_REGS_CPU2_IPCSTS_IPC23_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSTS_IPC23_Msk) >> IPC_REGS_CPU2_IPCSTS_IPC23_Pos) /*!< IPC23 Get Value */

#define IPC_REGS_CPU2_IPCSTS_IPC22_Pos (22U)                                    /*!< IPC22 Position  22         */
#define IPC_REGS_CPU2_IPCSTS_IPC22_Msk (0x1U << IPC_REGS_CPU2_IPCSTS_IPC22_Pos) /*!< IPC22 Mask      0x00400000 */
#define IPC_REGS_CPU2_IPCSTS_IPC22_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSTS_IPC22_Pos) & IPC_REGS_CPU2_IPCSTS_IPC22_Msk) /*!< IPC22 Set Value */
#define IPC_REGS_CPU2_IPCSTS_IPC22_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSTS_IPC22_Msk) >> IPC_REGS_CPU2_IPCSTS_IPC22_Pos) /*!< IPC22 Get Value */

#define IPC_REGS_CPU2_IPCSTS_IPC21_Pos (21U)                                    /*!< IPC21 Position  21         */
#define IPC_REGS_CPU2_IPCSTS_IPC21_Msk (0x1U << IPC_REGS_CPU2_IPCSTS_IPC21_Pos) /*!< IPC21 Mask      0x00200000 */
#define IPC_REGS_CPU2_IPCSTS_IPC21_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSTS_IPC21_Pos) & IPC_REGS_CPU2_IPCSTS_IPC21_Msk) /*!< IPC21 Set Value */
#define IPC_REGS_CPU2_IPCSTS_IPC21_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSTS_IPC21_Msk) >> IPC_REGS_CPU2_IPCSTS_IPC21_Pos) /*!< IPC21 Get Value */

#define IPC_REGS_CPU2_IPCSTS_IPC20_Pos (20U)                                    /*!< IPC20 Position  20         */
#define IPC_REGS_CPU2_IPCSTS_IPC20_Msk (0x1U << IPC_REGS_CPU2_IPCSTS_IPC20_Pos) /*!< IPC20 Mask      0x00100000 */
#define IPC_REGS_CPU2_IPCSTS_IPC20_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSTS_IPC20_Pos) & IPC_REGS_CPU2_IPCSTS_IPC20_Msk) /*!< IPC20 Set Value */
#define IPC_REGS_CPU2_IPCSTS_IPC20_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSTS_IPC20_Msk) >> IPC_REGS_CPU2_IPCSTS_IPC20_Pos) /*!< IPC20 Get Value */

#define IPC_REGS_CPU2_IPCSTS_IPC19_Pos (19U)                                    /*!< IPC19 Position  19         */
#define IPC_REGS_CPU2_IPCSTS_IPC19_Msk (0x1U << IPC_REGS_CPU2_IPCSTS_IPC19_Pos) /*!< IPC19 Mask      0x00080000 */
#define IPC_REGS_CPU2_IPCSTS_IPC19_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSTS_IPC19_Pos) & IPC_REGS_CPU2_IPCSTS_IPC19_Msk) /*!< IPC19 Set Value */
#define IPC_REGS_CPU2_IPCSTS_IPC19_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSTS_IPC19_Msk) >> IPC_REGS_CPU2_IPCSTS_IPC19_Pos) /*!< IPC19 Get Value */

#define IPC_REGS_CPU2_IPCSTS_IPC18_Pos (18U)                                    /*!< IPC18 Position  18         */
#define IPC_REGS_CPU2_IPCSTS_IPC18_Msk (0x1U << IPC_REGS_CPU2_IPCSTS_IPC18_Pos) /*!< IPC18 Mask      0x00040000 */
#define IPC_REGS_CPU2_IPCSTS_IPC18_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSTS_IPC18_Pos) & IPC_REGS_CPU2_IPCSTS_IPC18_Msk) /*!< IPC18 Set Value */
#define IPC_REGS_CPU2_IPCSTS_IPC18_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSTS_IPC18_Msk) >> IPC_REGS_CPU2_IPCSTS_IPC18_Pos) /*!< IPC18 Get Value */

#define IPC_REGS_CPU2_IPCSTS_IPC17_Pos (17U)                                    /*!< IPC17 Position  17         */
#define IPC_REGS_CPU2_IPCSTS_IPC17_Msk (0x1U << IPC_REGS_CPU2_IPCSTS_IPC17_Pos) /*!< IPC17 Mask      0x00020000 */
#define IPC_REGS_CPU2_IPCSTS_IPC17_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSTS_IPC17_Pos) & IPC_REGS_CPU2_IPCSTS_IPC17_Msk) /*!< IPC17 Set Value */
#define IPC_REGS_CPU2_IPCSTS_IPC17_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSTS_IPC17_Msk) >> IPC_REGS_CPU2_IPCSTS_IPC17_Pos) /*!< IPC17 Get Value */

#define IPC_REGS_CPU2_IPCSTS_IPC16_Pos (16U)                                    /*!< IPC16 Position  16         */
#define IPC_REGS_CPU2_IPCSTS_IPC16_Msk (0x1U << IPC_REGS_CPU2_IPCSTS_IPC16_Pos) /*!< IPC16 Mask      0x00010000 */
#define IPC_REGS_CPU2_IPCSTS_IPC16_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSTS_IPC16_Pos) & IPC_REGS_CPU2_IPCSTS_IPC16_Msk) /*!< IPC16 Set Value */
#define IPC_REGS_CPU2_IPCSTS_IPC16_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSTS_IPC16_Msk) >> IPC_REGS_CPU2_IPCSTS_IPC16_Pos) /*!< IPC16 Get Value */

#define IPC_REGS_CPU2_IPCSTS_IPC15_Pos (15U)                                    /*!< IPC15 Position  15         */
#define IPC_REGS_CPU2_IPCSTS_IPC15_Msk (0x1U << IPC_REGS_CPU2_IPCSTS_IPC15_Pos) /*!< IPC15 Mask      0x00008000 */
#define IPC_REGS_CPU2_IPCSTS_IPC15_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSTS_IPC15_Pos) & IPC_REGS_CPU2_IPCSTS_IPC15_Msk) /*!< IPC15 Set Value */
#define IPC_REGS_CPU2_IPCSTS_IPC15_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSTS_IPC15_Msk) >> IPC_REGS_CPU2_IPCSTS_IPC15_Pos) /*!< IPC15 Get Value */

#define IPC_REGS_CPU2_IPCSTS_IPC14_Pos (14U)                                    /*!< IPC14 Position  14         */
#define IPC_REGS_CPU2_IPCSTS_IPC14_Msk (0x1U << IPC_REGS_CPU2_IPCSTS_IPC14_Pos) /*!< IPC14 Mask      0x00004000 */
#define IPC_REGS_CPU2_IPCSTS_IPC14_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSTS_IPC14_Pos) & IPC_REGS_CPU2_IPCSTS_IPC14_Msk) /*!< IPC14 Set Value */
#define IPC_REGS_CPU2_IPCSTS_IPC14_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSTS_IPC14_Msk) >> IPC_REGS_CPU2_IPCSTS_IPC14_Pos) /*!< IPC14 Get Value */

#define IPC_REGS_CPU2_IPCSTS_IPC13_Pos (13U)                                    /*!< IPC13 Position  13         */
#define IPC_REGS_CPU2_IPCSTS_IPC13_Msk (0x1U << IPC_REGS_CPU2_IPCSTS_IPC13_Pos) /*!< IPC13 Mask      0x00002000 */
#define IPC_REGS_CPU2_IPCSTS_IPC13_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSTS_IPC13_Pos) & IPC_REGS_CPU2_IPCSTS_IPC13_Msk) /*!< IPC13 Set Value */
#define IPC_REGS_CPU2_IPCSTS_IPC13_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSTS_IPC13_Msk) >> IPC_REGS_CPU2_IPCSTS_IPC13_Pos) /*!< IPC13 Get Value */

#define IPC_REGS_CPU2_IPCSTS_IPC12_Pos (12U)                                    /*!< IPC12 Position  12         */
#define IPC_REGS_CPU2_IPCSTS_IPC12_Msk (0x1U << IPC_REGS_CPU2_IPCSTS_IPC12_Pos) /*!< IPC12 Mask      0x00001000 */
#define IPC_REGS_CPU2_IPCSTS_IPC12_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSTS_IPC12_Pos) & IPC_REGS_CPU2_IPCSTS_IPC12_Msk) /*!< IPC12 Set Value */
#define IPC_REGS_CPU2_IPCSTS_IPC12_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSTS_IPC12_Msk) >> IPC_REGS_CPU2_IPCSTS_IPC12_Pos) /*!< IPC12 Get Value */

#define IPC_REGS_CPU2_IPCSTS_IPC11_Pos (11U)                                    /*!< IPC11 Position  11         */
#define IPC_REGS_CPU2_IPCSTS_IPC11_Msk (0x1U << IPC_REGS_CPU2_IPCSTS_IPC11_Pos) /*!< IPC11 Mask      0x00000800 */
#define IPC_REGS_CPU2_IPCSTS_IPC11_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSTS_IPC11_Pos) & IPC_REGS_CPU2_IPCSTS_IPC11_Msk) /*!< IPC11 Set Value */
#define IPC_REGS_CPU2_IPCSTS_IPC11_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSTS_IPC11_Msk) >> IPC_REGS_CPU2_IPCSTS_IPC11_Pos) /*!< IPC11 Get Value */

#define IPC_REGS_CPU2_IPCSTS_IPC10_Pos (10U)                                    /*!< IPC10 Position  10         */
#define IPC_REGS_CPU2_IPCSTS_IPC10_Msk (0x1U << IPC_REGS_CPU2_IPCSTS_IPC10_Pos) /*!< IPC10 Mask      0x00000400 */
#define IPC_REGS_CPU2_IPCSTS_IPC10_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSTS_IPC10_Pos) & IPC_REGS_CPU2_IPCSTS_IPC10_Msk) /*!< IPC10 Set Value */
#define IPC_REGS_CPU2_IPCSTS_IPC10_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSTS_IPC10_Msk) >> IPC_REGS_CPU2_IPCSTS_IPC10_Pos) /*!< IPC10 Get Value */

#define IPC_REGS_CPU2_IPCSTS_IPC9_Pos (9U)                                    /*!< IPC9 Position  9          */
#define IPC_REGS_CPU2_IPCSTS_IPC9_Msk (0x1U << IPC_REGS_CPU2_IPCSTS_IPC9_Pos) /*!< IPC9 Mask      0x00000200 */
#define IPC_REGS_CPU2_IPCSTS_IPC9_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSTS_IPC9_Pos) & IPC_REGS_CPU2_IPCSTS_IPC9_Msk) /*!< IPC9 Set Value */
#define IPC_REGS_CPU2_IPCSTS_IPC9_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSTS_IPC9_Msk) >> IPC_REGS_CPU2_IPCSTS_IPC9_Pos) /*!< IPC9 Get Value            */

#define IPC_REGS_CPU2_IPCSTS_IPC8_Pos (8U)                                    /*!< IPC8 Position  8          */
#define IPC_REGS_CPU2_IPCSTS_IPC8_Msk (0x1U << IPC_REGS_CPU2_IPCSTS_IPC8_Pos) /*!< IPC8 Mask      0x00000100 */
#define IPC_REGS_CPU2_IPCSTS_IPC8_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSTS_IPC8_Pos) & IPC_REGS_CPU2_IPCSTS_IPC8_Msk) /*!< IPC8 Set Value */
#define IPC_REGS_CPU2_IPCSTS_IPC8_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSTS_IPC8_Msk) >> IPC_REGS_CPU2_IPCSTS_IPC8_Pos) /*!< IPC8 Get Value            */

#define IPC_REGS_CPU2_IPCSTS_IPC7_Pos (7U)                                    /*!< IPC7 Position  7          */
#define IPC_REGS_CPU2_IPCSTS_IPC7_Msk (0x1U << IPC_REGS_CPU2_IPCSTS_IPC7_Pos) /*!< IPC7 Mask      0x00000080 */
#define IPC_REGS_CPU2_IPCSTS_IPC7_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSTS_IPC7_Pos) & IPC_REGS_CPU2_IPCSTS_IPC7_Msk) /*!< IPC7 Set Value */
#define IPC_REGS_CPU2_IPCSTS_IPC7_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSTS_IPC7_Msk) >> IPC_REGS_CPU2_IPCSTS_IPC7_Pos) /*!< IPC7 Get Value            */

#define IPC_REGS_CPU2_IPCSTS_IPC6_Pos (6U)                                    /*!< IPC6 Position  6          */
#define IPC_REGS_CPU2_IPCSTS_IPC6_Msk (0x1U << IPC_REGS_CPU2_IPCSTS_IPC6_Pos) /*!< IPC6 Mask      0x00000040 */
#define IPC_REGS_CPU2_IPCSTS_IPC6_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSTS_IPC6_Pos) & IPC_REGS_CPU2_IPCSTS_IPC6_Msk) /*!< IPC6 Set Value */
#define IPC_REGS_CPU2_IPCSTS_IPC6_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSTS_IPC6_Msk) >> IPC_REGS_CPU2_IPCSTS_IPC6_Pos) /*!< IPC6 Get Value            */

#define IPC_REGS_CPU2_IPCSTS_IPC5_Pos (5U)                                    /*!< IPC5 Position  5          */
#define IPC_REGS_CPU2_IPCSTS_IPC5_Msk (0x1U << IPC_REGS_CPU2_IPCSTS_IPC5_Pos) /*!< IPC5 Mask      0x00000020 */
#define IPC_REGS_CPU2_IPCSTS_IPC5_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSTS_IPC5_Pos) & IPC_REGS_CPU2_IPCSTS_IPC5_Msk) /*!< IPC5 Set Value */
#define IPC_REGS_CPU2_IPCSTS_IPC5_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSTS_IPC5_Msk) >> IPC_REGS_CPU2_IPCSTS_IPC5_Pos) /*!< IPC5 Get Value            */

#define IPC_REGS_CPU2_IPCSTS_IPC4_Pos (4U)                                    /*!< IPC4 Position  4          */
#define IPC_REGS_CPU2_IPCSTS_IPC4_Msk (0x1U << IPC_REGS_CPU2_IPCSTS_IPC4_Pos) /*!< IPC4 Mask      0x00000010 */
#define IPC_REGS_CPU2_IPCSTS_IPC4_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSTS_IPC4_Pos) & IPC_REGS_CPU2_IPCSTS_IPC4_Msk) /*!< IPC4 Set Value */
#define IPC_REGS_CPU2_IPCSTS_IPC4_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSTS_IPC4_Msk) >> IPC_REGS_CPU2_IPCSTS_IPC4_Pos) /*!< IPC4 Get Value            */

#define IPC_REGS_CPU2_IPCSTS_IPC3_Pos (3U)                                    /*!< IPC3 Position  3          */
#define IPC_REGS_CPU2_IPCSTS_IPC3_Msk (0x1U << IPC_REGS_CPU2_IPCSTS_IPC3_Pos) /*!< IPC3 Mask      0x00000008 */
#define IPC_REGS_CPU2_IPCSTS_IPC3_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSTS_IPC3_Pos) & IPC_REGS_CPU2_IPCSTS_IPC3_Msk) /*!< IPC3 Set Value */
#define IPC_REGS_CPU2_IPCSTS_IPC3_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSTS_IPC3_Msk) >> IPC_REGS_CPU2_IPCSTS_IPC3_Pos) /*!< IPC3 Get Value            */

#define IPC_REGS_CPU2_IPCSTS_IPC2_Pos (2U)                                    /*!< IPC2 Position  2          */
#define IPC_REGS_CPU2_IPCSTS_IPC2_Msk (0x1U << IPC_REGS_CPU2_IPCSTS_IPC2_Pos) /*!< IPC2 Mask      0x00000004 */
#define IPC_REGS_CPU2_IPCSTS_IPC2_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSTS_IPC2_Pos) & IPC_REGS_CPU2_IPCSTS_IPC2_Msk) /*!< IPC2 Set Value */
#define IPC_REGS_CPU2_IPCSTS_IPC2_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSTS_IPC2_Msk) >> IPC_REGS_CPU2_IPCSTS_IPC2_Pos) /*!< IPC2 Get Value            */

#define IPC_REGS_CPU2_IPCSTS_IPC1_Pos (1U)                                    /*!< IPC1 Position  1          */
#define IPC_REGS_CPU2_IPCSTS_IPC1_Msk (0x1U << IPC_REGS_CPU2_IPCSTS_IPC1_Pos) /*!< IPC1 Mask      0x00000002 */
#define IPC_REGS_CPU2_IPCSTS_IPC1_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSTS_IPC1_Pos) & IPC_REGS_CPU2_IPCSTS_IPC1_Msk) /*!< IPC1 Set Value */
#define IPC_REGS_CPU2_IPCSTS_IPC1_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSTS_IPC1_Msk) >> IPC_REGS_CPU2_IPCSTS_IPC1_Pos) /*!< IPC1 Get Value            */

#define IPC_REGS_CPU2_IPCSTS_IPC0_Pos (0U)                                    /*!< IPC0 Position  0          */
#define IPC_REGS_CPU2_IPCSTS_IPC0_Msk (0x1U << IPC_REGS_CPU2_IPCSTS_IPC0_Pos) /*!< IPC0 Mask      0x00000001 */
#define IPC_REGS_CPU2_IPCSTS_IPC0_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSTS_IPC0_Pos) & IPC_REGS_CPU2_IPCSTS_IPC0_Msk) /*!< IPC0 Set Value */
#define IPC_REGS_CPU2_IPCSTS_IPC0_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSTS_IPC0_Msk) >> IPC_REGS_CPU2_IPCSTS_IPC0_Pos) /*!< IPC0 Get Value            */

/* IPCSET bitfield */
#define IPC_REGS_CPU2_IPCSET_IPC31_Pos (31U)                                    /*!< IPC31 Position  31         */
#define IPC_REGS_CPU2_IPCSET_IPC31_Msk (0x1U << IPC_REGS_CPU2_IPCSET_IPC31_Pos) /*!< IPC31 Mask      0x80000000 */
#define IPC_REGS_CPU2_IPCSET_IPC31_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSET_IPC31_Pos) & IPC_REGS_CPU2_IPCSET_IPC31_Msk) /*!< IPC31 Set Value */
#define IPC_REGS_CPU2_IPCSET_IPC31_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSET_IPC31_Msk) >> IPC_REGS_CPU2_IPCSET_IPC31_Pos) /*!< IPC31 Get Value */

#define IPC_REGS_CPU2_IPCSET_IPC30_Pos (30U)                                    /*!< IPC30 Position  30         */
#define IPC_REGS_CPU2_IPCSET_IPC30_Msk (0x1U << IPC_REGS_CPU2_IPCSET_IPC30_Pos) /*!< IPC30 Mask      0x40000000 */
#define IPC_REGS_CPU2_IPCSET_IPC30_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSET_IPC30_Pos) & IPC_REGS_CPU2_IPCSET_IPC30_Msk) /*!< IPC30 Set Value */
#define IPC_REGS_CPU2_IPCSET_IPC30_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSET_IPC30_Msk) >> IPC_REGS_CPU2_IPCSET_IPC30_Pos) /*!< IPC30 Get Value */

#define IPC_REGS_CPU2_IPCSET_IPC29_Pos (29U)                                    /*!< IPC29 Position  29         */
#define IPC_REGS_CPU2_IPCSET_IPC29_Msk (0x1U << IPC_REGS_CPU2_IPCSET_IPC29_Pos) /*!< IPC29 Mask      0x20000000 */
#define IPC_REGS_CPU2_IPCSET_IPC29_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSET_IPC29_Pos) & IPC_REGS_CPU2_IPCSET_IPC29_Msk) /*!< IPC29 Set Value */
#define IPC_REGS_CPU2_IPCSET_IPC29_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSET_IPC29_Msk) >> IPC_REGS_CPU2_IPCSET_IPC29_Pos) /*!< IPC29 Get Value */

#define IPC_REGS_CPU2_IPCSET_IPC28_Pos (28U)                                    /*!< IPC28 Position  28         */
#define IPC_REGS_CPU2_IPCSET_IPC28_Msk (0x1U << IPC_REGS_CPU2_IPCSET_IPC28_Pos) /*!< IPC28 Mask      0x10000000 */
#define IPC_REGS_CPU2_IPCSET_IPC28_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSET_IPC28_Pos) & IPC_REGS_CPU2_IPCSET_IPC28_Msk) /*!< IPC28 Set Value */
#define IPC_REGS_CPU2_IPCSET_IPC28_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSET_IPC28_Msk) >> IPC_REGS_CPU2_IPCSET_IPC28_Pos) /*!< IPC28 Get Value */

#define IPC_REGS_CPU2_IPCSET_IPC27_Pos (27U)                                    /*!< IPC27 Position  27         */
#define IPC_REGS_CPU2_IPCSET_IPC27_Msk (0x1U << IPC_REGS_CPU2_IPCSET_IPC27_Pos) /*!< IPC27 Mask      0x08000000 */
#define IPC_REGS_CPU2_IPCSET_IPC27_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSET_IPC27_Pos) & IPC_REGS_CPU2_IPCSET_IPC27_Msk) /*!< IPC27 Set Value */
#define IPC_REGS_CPU2_IPCSET_IPC27_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSET_IPC27_Msk) >> IPC_REGS_CPU2_IPCSET_IPC27_Pos) /*!< IPC27 Get Value */

#define IPC_REGS_CPU2_IPCSET_IPC26_Pos (26U)                                    /*!< IPC26 Position  26         */
#define IPC_REGS_CPU2_IPCSET_IPC26_Msk (0x1U << IPC_REGS_CPU2_IPCSET_IPC26_Pos) /*!< IPC26 Mask      0x04000000 */
#define IPC_REGS_CPU2_IPCSET_IPC26_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSET_IPC26_Pos) & IPC_REGS_CPU2_IPCSET_IPC26_Msk) /*!< IPC26 Set Value */
#define IPC_REGS_CPU2_IPCSET_IPC26_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSET_IPC26_Msk) >> IPC_REGS_CPU2_IPCSET_IPC26_Pos) /*!< IPC26 Get Value */

#define IPC_REGS_CPU2_IPCSET_IPC25_Pos (25U)                                    /*!< IPC25 Position  25         */
#define IPC_REGS_CPU2_IPCSET_IPC25_Msk (0x1U << IPC_REGS_CPU2_IPCSET_IPC25_Pos) /*!< IPC25 Mask      0x02000000 */
#define IPC_REGS_CPU2_IPCSET_IPC25_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSET_IPC25_Pos) & IPC_REGS_CPU2_IPCSET_IPC25_Msk) /*!< IPC25 Set Value */
#define IPC_REGS_CPU2_IPCSET_IPC25_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSET_IPC25_Msk) >> IPC_REGS_CPU2_IPCSET_IPC25_Pos) /*!< IPC25 Get Value */

#define IPC_REGS_CPU2_IPCSET_IPC24_Pos (24U)                                    /*!< IPC24 Position  24         */
#define IPC_REGS_CPU2_IPCSET_IPC24_Msk (0x1U << IPC_REGS_CPU2_IPCSET_IPC24_Pos) /*!< IPC24 Mask      0x01000000 */
#define IPC_REGS_CPU2_IPCSET_IPC24_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSET_IPC24_Pos) & IPC_REGS_CPU2_IPCSET_IPC24_Msk) /*!< IPC24 Set Value */
#define IPC_REGS_CPU2_IPCSET_IPC24_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSET_IPC24_Msk) >> IPC_REGS_CPU2_IPCSET_IPC24_Pos) /*!< IPC24 Get Value */

#define IPC_REGS_CPU2_IPCSET_IPC23_Pos (23U)                                    /*!< IPC23 Position  23         */
#define IPC_REGS_CPU2_IPCSET_IPC23_Msk (0x1U << IPC_REGS_CPU2_IPCSET_IPC23_Pos) /*!< IPC23 Mask      0x00800000 */
#define IPC_REGS_CPU2_IPCSET_IPC23_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSET_IPC23_Pos) & IPC_REGS_CPU2_IPCSET_IPC23_Msk) /*!< IPC23 Set Value */
#define IPC_REGS_CPU2_IPCSET_IPC23_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSET_IPC23_Msk) >> IPC_REGS_CPU2_IPCSET_IPC23_Pos) /*!< IPC23 Get Value */

#define IPC_REGS_CPU2_IPCSET_IPC22_Pos (22U)                                    /*!< IPC22 Position  22         */
#define IPC_REGS_CPU2_IPCSET_IPC22_Msk (0x1U << IPC_REGS_CPU2_IPCSET_IPC22_Pos) /*!< IPC22 Mask      0x00400000 */
#define IPC_REGS_CPU2_IPCSET_IPC22_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSET_IPC22_Pos) & IPC_REGS_CPU2_IPCSET_IPC22_Msk) /*!< IPC22 Set Value */
#define IPC_REGS_CPU2_IPCSET_IPC22_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSET_IPC22_Msk) >> IPC_REGS_CPU2_IPCSET_IPC22_Pos) /*!< IPC22 Get Value */

#define IPC_REGS_CPU2_IPCSET_IPC21_Pos (21U)                                    /*!< IPC21 Position  21         */
#define IPC_REGS_CPU2_IPCSET_IPC21_Msk (0x1U << IPC_REGS_CPU2_IPCSET_IPC21_Pos) /*!< IPC21 Mask      0x00200000 */
#define IPC_REGS_CPU2_IPCSET_IPC21_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSET_IPC21_Pos) & IPC_REGS_CPU2_IPCSET_IPC21_Msk) /*!< IPC21 Set Value */
#define IPC_REGS_CPU2_IPCSET_IPC21_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSET_IPC21_Msk) >> IPC_REGS_CPU2_IPCSET_IPC21_Pos) /*!< IPC21 Get Value */

#define IPC_REGS_CPU2_IPCSET_IPC20_Pos (20U)                                    /*!< IPC20 Position  20         */
#define IPC_REGS_CPU2_IPCSET_IPC20_Msk (0x1U << IPC_REGS_CPU2_IPCSET_IPC20_Pos) /*!< IPC20 Mask      0x00100000 */
#define IPC_REGS_CPU2_IPCSET_IPC20_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSET_IPC20_Pos) & IPC_REGS_CPU2_IPCSET_IPC20_Msk) /*!< IPC20 Set Value */
#define IPC_REGS_CPU2_IPCSET_IPC20_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSET_IPC20_Msk) >> IPC_REGS_CPU2_IPCSET_IPC20_Pos) /*!< IPC20 Get Value */

#define IPC_REGS_CPU2_IPCSET_IPC19_Pos (19U)                                    /*!< IPC19 Position  19         */
#define IPC_REGS_CPU2_IPCSET_IPC19_Msk (0x1U << IPC_REGS_CPU2_IPCSET_IPC19_Pos) /*!< IPC19 Mask      0x00080000 */
#define IPC_REGS_CPU2_IPCSET_IPC19_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSET_IPC19_Pos) & IPC_REGS_CPU2_IPCSET_IPC19_Msk) /*!< IPC19 Set Value */
#define IPC_REGS_CPU2_IPCSET_IPC19_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSET_IPC19_Msk) >> IPC_REGS_CPU2_IPCSET_IPC19_Pos) /*!< IPC19 Get Value */

#define IPC_REGS_CPU2_IPCSET_IPC18_Pos (18U)                                    /*!< IPC18 Position  18         */
#define IPC_REGS_CPU2_IPCSET_IPC18_Msk (0x1U << IPC_REGS_CPU2_IPCSET_IPC18_Pos) /*!< IPC18 Mask      0x00040000 */
#define IPC_REGS_CPU2_IPCSET_IPC18_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSET_IPC18_Pos) & IPC_REGS_CPU2_IPCSET_IPC18_Msk) /*!< IPC18 Set Value */
#define IPC_REGS_CPU2_IPCSET_IPC18_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSET_IPC18_Msk) >> IPC_REGS_CPU2_IPCSET_IPC18_Pos) /*!< IPC18 Get Value */

#define IPC_REGS_CPU2_IPCSET_IPC17_Pos (17U)                                    /*!< IPC17 Position  17         */
#define IPC_REGS_CPU2_IPCSET_IPC17_Msk (0x1U << IPC_REGS_CPU2_IPCSET_IPC17_Pos) /*!< IPC17 Mask      0x00020000 */
#define IPC_REGS_CPU2_IPCSET_IPC17_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSET_IPC17_Pos) & IPC_REGS_CPU2_IPCSET_IPC17_Msk) /*!< IPC17 Set Value */
#define IPC_REGS_CPU2_IPCSET_IPC17_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSET_IPC17_Msk) >> IPC_REGS_CPU2_IPCSET_IPC17_Pos) /*!< IPC17 Get Value */

#define IPC_REGS_CPU2_IPCSET_IPC16_Pos (16U)                                    /*!< IPC16 Position  16         */
#define IPC_REGS_CPU2_IPCSET_IPC16_Msk (0x1U << IPC_REGS_CPU2_IPCSET_IPC16_Pos) /*!< IPC16 Mask      0x00010000 */
#define IPC_REGS_CPU2_IPCSET_IPC16_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSET_IPC16_Pos) & IPC_REGS_CPU2_IPCSET_IPC16_Msk) /*!< IPC16 Set Value */
#define IPC_REGS_CPU2_IPCSET_IPC16_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSET_IPC16_Msk) >> IPC_REGS_CPU2_IPCSET_IPC16_Pos) /*!< IPC16 Get Value */

#define IPC_REGS_CPU2_IPCSET_IPC15_Pos (15U)                                    /*!< IPC15 Position  15         */
#define IPC_REGS_CPU2_IPCSET_IPC15_Msk (0x1U << IPC_REGS_CPU2_IPCSET_IPC15_Pos) /*!< IPC15 Mask      0x00008000 */
#define IPC_REGS_CPU2_IPCSET_IPC15_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSET_IPC15_Pos) & IPC_REGS_CPU2_IPCSET_IPC15_Msk) /*!< IPC15 Set Value */
#define IPC_REGS_CPU2_IPCSET_IPC15_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSET_IPC15_Msk) >> IPC_REGS_CPU2_IPCSET_IPC15_Pos) /*!< IPC15 Get Value */

#define IPC_REGS_CPU2_IPCSET_IPC14_Pos (14U)                                    /*!< IPC14 Position  14         */
#define IPC_REGS_CPU2_IPCSET_IPC14_Msk (0x1U << IPC_REGS_CPU2_IPCSET_IPC14_Pos) /*!< IPC14 Mask      0x00004000 */
#define IPC_REGS_CPU2_IPCSET_IPC14_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSET_IPC14_Pos) & IPC_REGS_CPU2_IPCSET_IPC14_Msk) /*!< IPC14 Set Value */
#define IPC_REGS_CPU2_IPCSET_IPC14_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSET_IPC14_Msk) >> IPC_REGS_CPU2_IPCSET_IPC14_Pos) /*!< IPC14 Get Value */

#define IPC_REGS_CPU2_IPCSET_IPC13_Pos (13U)                                    /*!< IPC13 Position  13         */
#define IPC_REGS_CPU2_IPCSET_IPC13_Msk (0x1U << IPC_REGS_CPU2_IPCSET_IPC13_Pos) /*!< IPC13 Mask      0x00002000 */
#define IPC_REGS_CPU2_IPCSET_IPC13_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSET_IPC13_Pos) & IPC_REGS_CPU2_IPCSET_IPC13_Msk) /*!< IPC13 Set Value */
#define IPC_REGS_CPU2_IPCSET_IPC13_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSET_IPC13_Msk) >> IPC_REGS_CPU2_IPCSET_IPC13_Pos) /*!< IPC13 Get Value */

#define IPC_REGS_CPU2_IPCSET_IPC12_Pos (12U)                                    /*!< IPC12 Position  12         */
#define IPC_REGS_CPU2_IPCSET_IPC12_Msk (0x1U << IPC_REGS_CPU2_IPCSET_IPC12_Pos) /*!< IPC12 Mask      0x00001000 */
#define IPC_REGS_CPU2_IPCSET_IPC12_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSET_IPC12_Pos) & IPC_REGS_CPU2_IPCSET_IPC12_Msk) /*!< IPC12 Set Value */
#define IPC_REGS_CPU2_IPCSET_IPC12_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSET_IPC12_Msk) >> IPC_REGS_CPU2_IPCSET_IPC12_Pos) /*!< IPC12 Get Value */

#define IPC_REGS_CPU2_IPCSET_IPC11_Pos (11U)                                    /*!< IPC11 Position  11         */
#define IPC_REGS_CPU2_IPCSET_IPC11_Msk (0x1U << IPC_REGS_CPU2_IPCSET_IPC11_Pos) /*!< IPC11 Mask      0x00000800 */
#define IPC_REGS_CPU2_IPCSET_IPC11_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSET_IPC11_Pos) & IPC_REGS_CPU2_IPCSET_IPC11_Msk) /*!< IPC11 Set Value */
#define IPC_REGS_CPU2_IPCSET_IPC11_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSET_IPC11_Msk) >> IPC_REGS_CPU2_IPCSET_IPC11_Pos) /*!< IPC11 Get Value */

#define IPC_REGS_CPU2_IPCSET_IPC10_Pos (10U)                                    /*!< IPC10 Position  10         */
#define IPC_REGS_CPU2_IPCSET_IPC10_Msk (0x1U << IPC_REGS_CPU2_IPCSET_IPC10_Pos) /*!< IPC10 Mask      0x00000400 */
#define IPC_REGS_CPU2_IPCSET_IPC10_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSET_IPC10_Pos) & IPC_REGS_CPU2_IPCSET_IPC10_Msk) /*!< IPC10 Set Value */
#define IPC_REGS_CPU2_IPCSET_IPC10_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSET_IPC10_Msk) >> IPC_REGS_CPU2_IPCSET_IPC10_Pos) /*!< IPC10 Get Value */

#define IPC_REGS_CPU2_IPCSET_IPC9_Pos (9U)                                    /*!< IPC9 Position  9          */
#define IPC_REGS_CPU2_IPCSET_IPC9_Msk (0x1U << IPC_REGS_CPU2_IPCSET_IPC9_Pos) /*!< IPC9 Mask      0x00000200 */
#define IPC_REGS_CPU2_IPCSET_IPC9_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSET_IPC9_Pos) & IPC_REGS_CPU2_IPCSET_IPC9_Msk) /*!< IPC9 Set Value */
#define IPC_REGS_CPU2_IPCSET_IPC9_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSET_IPC9_Msk) >> IPC_REGS_CPU2_IPCSET_IPC9_Pos) /*!< IPC9 Get Value            */

#define IPC_REGS_CPU2_IPCSET_IPC8_Pos (8U)                                    /*!< IPC8 Position  8          */
#define IPC_REGS_CPU2_IPCSET_IPC8_Msk (0x1U << IPC_REGS_CPU2_IPCSET_IPC8_Pos) /*!< IPC8 Mask      0x00000100 */
#define IPC_REGS_CPU2_IPCSET_IPC8_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSET_IPC8_Pos) & IPC_REGS_CPU2_IPCSET_IPC8_Msk) /*!< IPC8 Set Value */
#define IPC_REGS_CPU2_IPCSET_IPC8_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSET_IPC8_Msk) >> IPC_REGS_CPU2_IPCSET_IPC8_Pos) /*!< IPC8 Get Value            */

#define IPC_REGS_CPU2_IPCSET_IPC7_Pos (7U)                                    /*!< IPC7 Position  7          */
#define IPC_REGS_CPU2_IPCSET_IPC7_Msk (0x1U << IPC_REGS_CPU2_IPCSET_IPC7_Pos) /*!< IPC7 Mask      0x00000080 */
#define IPC_REGS_CPU2_IPCSET_IPC7_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSET_IPC7_Pos) & IPC_REGS_CPU2_IPCSET_IPC7_Msk) /*!< IPC7 Set Value */
#define IPC_REGS_CPU2_IPCSET_IPC7_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSET_IPC7_Msk) >> IPC_REGS_CPU2_IPCSET_IPC7_Pos) /*!< IPC7 Get Value            */

#define IPC_REGS_CPU2_IPCSET_IPC6_Pos (6U)                                    /*!< IPC6 Position  6          */
#define IPC_REGS_CPU2_IPCSET_IPC6_Msk (0x1U << IPC_REGS_CPU2_IPCSET_IPC6_Pos) /*!< IPC6 Mask      0x00000040 */
#define IPC_REGS_CPU2_IPCSET_IPC6_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSET_IPC6_Pos) & IPC_REGS_CPU2_IPCSET_IPC6_Msk) /*!< IPC6 Set Value */
#define IPC_REGS_CPU2_IPCSET_IPC6_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSET_IPC6_Msk) >> IPC_REGS_CPU2_IPCSET_IPC6_Pos) /*!< IPC6 Get Value            */

#define IPC_REGS_CPU2_IPCSET_IPC5_Pos (5U)                                    /*!< IPC5 Position  5          */
#define IPC_REGS_CPU2_IPCSET_IPC5_Msk (0x1U << IPC_REGS_CPU2_IPCSET_IPC5_Pos) /*!< IPC5 Mask      0x00000020 */
#define IPC_REGS_CPU2_IPCSET_IPC5_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSET_IPC5_Pos) & IPC_REGS_CPU2_IPCSET_IPC5_Msk) /*!< IPC5 Set Value */
#define IPC_REGS_CPU2_IPCSET_IPC5_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSET_IPC5_Msk) >> IPC_REGS_CPU2_IPCSET_IPC5_Pos) /*!< IPC5 Get Value            */

#define IPC_REGS_CPU2_IPCSET_IPC4_Pos (4U)                                    /*!< IPC4 Position  4          */
#define IPC_REGS_CPU2_IPCSET_IPC4_Msk (0x1U << IPC_REGS_CPU2_IPCSET_IPC4_Pos) /*!< IPC4 Mask      0x00000010 */
#define IPC_REGS_CPU2_IPCSET_IPC4_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSET_IPC4_Pos) & IPC_REGS_CPU2_IPCSET_IPC4_Msk) /*!< IPC4 Set Value */
#define IPC_REGS_CPU2_IPCSET_IPC4_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSET_IPC4_Msk) >> IPC_REGS_CPU2_IPCSET_IPC4_Pos) /*!< IPC4 Get Value            */

#define IPC_REGS_CPU2_IPCSET_IPC3_Pos (3U)                                    /*!< IPC3 Position  3          */
#define IPC_REGS_CPU2_IPCSET_IPC3_Msk (0x1U << IPC_REGS_CPU2_IPCSET_IPC3_Pos) /*!< IPC3 Mask      0x00000008 */
#define IPC_REGS_CPU2_IPCSET_IPC3_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSET_IPC3_Pos) & IPC_REGS_CPU2_IPCSET_IPC3_Msk) /*!< IPC3 Set Value */
#define IPC_REGS_CPU2_IPCSET_IPC3_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSET_IPC3_Msk) >> IPC_REGS_CPU2_IPCSET_IPC3_Pos) /*!< IPC3 Get Value            */

#define IPC_REGS_CPU2_IPCSET_IPC2_Pos (2U)                                    /*!< IPC2 Position  2          */
#define IPC_REGS_CPU2_IPCSET_IPC2_Msk (0x1U << IPC_REGS_CPU2_IPCSET_IPC2_Pos) /*!< IPC2 Mask      0x00000004 */
#define IPC_REGS_CPU2_IPCSET_IPC2_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSET_IPC2_Pos) & IPC_REGS_CPU2_IPCSET_IPC2_Msk) /*!< IPC2 Set Value */
#define IPC_REGS_CPU2_IPCSET_IPC2_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSET_IPC2_Msk) >> IPC_REGS_CPU2_IPCSET_IPC2_Pos) /*!< IPC2 Get Value            */

#define IPC_REGS_CPU2_IPCSET_IPC1_Pos (1U)                                    /*!< IPC1 Position  1          */
#define IPC_REGS_CPU2_IPCSET_IPC1_Msk (0x1U << IPC_REGS_CPU2_IPCSET_IPC1_Pos) /*!< IPC1 Mask      0x00000002 */
#define IPC_REGS_CPU2_IPCSET_IPC1_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSET_IPC1_Pos) & IPC_REGS_CPU2_IPCSET_IPC1_Msk) /*!< IPC1 Set Value */
#define IPC_REGS_CPU2_IPCSET_IPC1_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSET_IPC1_Msk) >> IPC_REGS_CPU2_IPCSET_IPC1_Pos) /*!< IPC1 Get Value            */

#define IPC_REGS_CPU2_IPCSET_IPC0_Pos (0U)                                    /*!< IPC0 Position  0          */
#define IPC_REGS_CPU2_IPCSET_IPC0_Msk (0x1U << IPC_REGS_CPU2_IPCSET_IPC0_Pos) /*!< IPC0 Mask      0x00000001 */
#define IPC_REGS_CPU2_IPCSET_IPC0_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSET_IPC0_Pos) & IPC_REGS_CPU2_IPCSET_IPC0_Msk) /*!< IPC0 Set Value */
#define IPC_REGS_CPU2_IPCSET_IPC0_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSET_IPC0_Msk) >> IPC_REGS_CPU2_IPCSET_IPC0_Pos) /*!< IPC0 Get Value            */

/* IPCCLR bitfield */
#define IPC_REGS_CPU2_IPCCLR_IPC31_Pos (31U)                                    /*!< IPC31 Position  31         */
#define IPC_REGS_CPU2_IPCCLR_IPC31_Msk (0x1U << IPC_REGS_CPU2_IPCCLR_IPC31_Pos) /*!< IPC31 Mask      0x80000000 */
#define IPC_REGS_CPU2_IPCCLR_IPC31_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCCLR_IPC31_Pos) & IPC_REGS_CPU2_IPCCLR_IPC31_Msk) /*!< IPC31 Set Value */
#define IPC_REGS_CPU2_IPCCLR_IPC31_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCCLR_IPC31_Msk) >> IPC_REGS_CPU2_IPCCLR_IPC31_Pos) /*!< IPC31 Get Value */

#define IPC_REGS_CPU2_IPCCLR_IPC30_Pos (30U)                                    /*!< IPC30 Position  30         */
#define IPC_REGS_CPU2_IPCCLR_IPC30_Msk (0x1U << IPC_REGS_CPU2_IPCCLR_IPC30_Pos) /*!< IPC30 Mask      0x40000000 */
#define IPC_REGS_CPU2_IPCCLR_IPC30_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCCLR_IPC30_Pos) & IPC_REGS_CPU2_IPCCLR_IPC30_Msk) /*!< IPC30 Set Value */
#define IPC_REGS_CPU2_IPCCLR_IPC30_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCCLR_IPC30_Msk) >> IPC_REGS_CPU2_IPCCLR_IPC30_Pos) /*!< IPC30 Get Value */

#define IPC_REGS_CPU2_IPCCLR_IPC29_Pos (29U)                                    /*!< IPC29 Position  29         */
#define IPC_REGS_CPU2_IPCCLR_IPC29_Msk (0x1U << IPC_REGS_CPU2_IPCCLR_IPC29_Pos) /*!< IPC29 Mask      0x20000000 */
#define IPC_REGS_CPU2_IPCCLR_IPC29_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCCLR_IPC29_Pos) & IPC_REGS_CPU2_IPCCLR_IPC29_Msk) /*!< IPC29 Set Value */
#define IPC_REGS_CPU2_IPCCLR_IPC29_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCCLR_IPC29_Msk) >> IPC_REGS_CPU2_IPCCLR_IPC29_Pos) /*!< IPC29 Get Value */

#define IPC_REGS_CPU2_IPCCLR_IPC28_Pos (28U)                                    /*!< IPC28 Position  28         */
#define IPC_REGS_CPU2_IPCCLR_IPC28_Msk (0x1U << IPC_REGS_CPU2_IPCCLR_IPC28_Pos) /*!< IPC28 Mask      0x10000000 */
#define IPC_REGS_CPU2_IPCCLR_IPC28_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCCLR_IPC28_Pos) & IPC_REGS_CPU2_IPCCLR_IPC28_Msk) /*!< IPC28 Set Value */
#define IPC_REGS_CPU2_IPCCLR_IPC28_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCCLR_IPC28_Msk) >> IPC_REGS_CPU2_IPCCLR_IPC28_Pos) /*!< IPC28 Get Value */

#define IPC_REGS_CPU2_IPCCLR_IPC27_Pos (27U)                                    /*!< IPC27 Position  27         */
#define IPC_REGS_CPU2_IPCCLR_IPC27_Msk (0x1U << IPC_REGS_CPU2_IPCCLR_IPC27_Pos) /*!< IPC27 Mask      0x08000000 */
#define IPC_REGS_CPU2_IPCCLR_IPC27_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCCLR_IPC27_Pos) & IPC_REGS_CPU2_IPCCLR_IPC27_Msk) /*!< IPC27 Set Value */
#define IPC_REGS_CPU2_IPCCLR_IPC27_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCCLR_IPC27_Msk) >> IPC_REGS_CPU2_IPCCLR_IPC27_Pos) /*!< IPC27 Get Value */

#define IPC_REGS_CPU2_IPCCLR_IPC26_Pos (26U)                                    /*!< IPC26 Position  26         */
#define IPC_REGS_CPU2_IPCCLR_IPC26_Msk (0x1U << IPC_REGS_CPU2_IPCCLR_IPC26_Pos) /*!< IPC26 Mask      0x04000000 */
#define IPC_REGS_CPU2_IPCCLR_IPC26_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCCLR_IPC26_Pos) & IPC_REGS_CPU2_IPCCLR_IPC26_Msk) /*!< IPC26 Set Value */
#define IPC_REGS_CPU2_IPCCLR_IPC26_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCCLR_IPC26_Msk) >> IPC_REGS_CPU2_IPCCLR_IPC26_Pos) /*!< IPC26 Get Value */

#define IPC_REGS_CPU2_IPCCLR_IPC25_Pos (25U)                                    /*!< IPC25 Position  25         */
#define IPC_REGS_CPU2_IPCCLR_IPC25_Msk (0x1U << IPC_REGS_CPU2_IPCCLR_IPC25_Pos) /*!< IPC25 Mask      0x02000000 */
#define IPC_REGS_CPU2_IPCCLR_IPC25_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCCLR_IPC25_Pos) & IPC_REGS_CPU2_IPCCLR_IPC25_Msk) /*!< IPC25 Set Value */
#define IPC_REGS_CPU2_IPCCLR_IPC25_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCCLR_IPC25_Msk) >> IPC_REGS_CPU2_IPCCLR_IPC25_Pos) /*!< IPC25 Get Value */

#define IPC_REGS_CPU2_IPCCLR_IPC24_Pos (24U)                                    /*!< IPC24 Position  24         */
#define IPC_REGS_CPU2_IPCCLR_IPC24_Msk (0x1U << IPC_REGS_CPU2_IPCCLR_IPC24_Pos) /*!< IPC24 Mask      0x01000000 */
#define IPC_REGS_CPU2_IPCCLR_IPC24_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCCLR_IPC24_Pos) & IPC_REGS_CPU2_IPCCLR_IPC24_Msk) /*!< IPC24 Set Value */
#define IPC_REGS_CPU2_IPCCLR_IPC24_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCCLR_IPC24_Msk) >> IPC_REGS_CPU2_IPCCLR_IPC24_Pos) /*!< IPC24 Get Value */

#define IPC_REGS_CPU2_IPCCLR_IPC23_Pos (23U)                                    /*!< IPC23 Position  23         */
#define IPC_REGS_CPU2_IPCCLR_IPC23_Msk (0x1U << IPC_REGS_CPU2_IPCCLR_IPC23_Pos) /*!< IPC23 Mask      0x00800000 */
#define IPC_REGS_CPU2_IPCCLR_IPC23_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCCLR_IPC23_Pos) & IPC_REGS_CPU2_IPCCLR_IPC23_Msk) /*!< IPC23 Set Value */
#define IPC_REGS_CPU2_IPCCLR_IPC23_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCCLR_IPC23_Msk) >> IPC_REGS_CPU2_IPCCLR_IPC23_Pos) /*!< IPC23 Get Value */

#define IPC_REGS_CPU2_IPCCLR_IPC22_Pos (22U)                                    /*!< IPC22 Position  22         */
#define IPC_REGS_CPU2_IPCCLR_IPC22_Msk (0x1U << IPC_REGS_CPU2_IPCCLR_IPC22_Pos) /*!< IPC22 Mask      0x00400000 */
#define IPC_REGS_CPU2_IPCCLR_IPC22_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCCLR_IPC22_Pos) & IPC_REGS_CPU2_IPCCLR_IPC22_Msk) /*!< IPC22 Set Value */
#define IPC_REGS_CPU2_IPCCLR_IPC22_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCCLR_IPC22_Msk) >> IPC_REGS_CPU2_IPCCLR_IPC22_Pos) /*!< IPC22 Get Value */

#define IPC_REGS_CPU2_IPCCLR_IPC21_Pos (21U)                                    /*!< IPC21 Position  21         */
#define IPC_REGS_CPU2_IPCCLR_IPC21_Msk (0x1U << IPC_REGS_CPU2_IPCCLR_IPC21_Pos) /*!< IPC21 Mask      0x00200000 */
#define IPC_REGS_CPU2_IPCCLR_IPC21_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCCLR_IPC21_Pos) & IPC_REGS_CPU2_IPCCLR_IPC21_Msk) /*!< IPC21 Set Value */
#define IPC_REGS_CPU2_IPCCLR_IPC21_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCCLR_IPC21_Msk) >> IPC_REGS_CPU2_IPCCLR_IPC21_Pos) /*!< IPC21 Get Value */

#define IPC_REGS_CPU2_IPCCLR_IPC20_Pos (20U)                                    /*!< IPC20 Position  20         */
#define IPC_REGS_CPU2_IPCCLR_IPC20_Msk (0x1U << IPC_REGS_CPU2_IPCCLR_IPC20_Pos) /*!< IPC20 Mask      0x00100000 */
#define IPC_REGS_CPU2_IPCCLR_IPC20_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCCLR_IPC20_Pos) & IPC_REGS_CPU2_IPCCLR_IPC20_Msk) /*!< IPC20 Set Value */
#define IPC_REGS_CPU2_IPCCLR_IPC20_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCCLR_IPC20_Msk) >> IPC_REGS_CPU2_IPCCLR_IPC20_Pos) /*!< IPC20 Get Value */

#define IPC_REGS_CPU2_IPCCLR_IPC19_Pos (19U)                                    /*!< IPC19 Position  19         */
#define IPC_REGS_CPU2_IPCCLR_IPC19_Msk (0x1U << IPC_REGS_CPU2_IPCCLR_IPC19_Pos) /*!< IPC19 Mask      0x00080000 */
#define IPC_REGS_CPU2_IPCCLR_IPC19_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCCLR_IPC19_Pos) & IPC_REGS_CPU2_IPCCLR_IPC19_Msk) /*!< IPC19 Set Value */
#define IPC_REGS_CPU2_IPCCLR_IPC19_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCCLR_IPC19_Msk) >> IPC_REGS_CPU2_IPCCLR_IPC19_Pos) /*!< IPC19 Get Value */

#define IPC_REGS_CPU2_IPCCLR_IPC18_Pos (18U)                                    /*!< IPC18 Position  18         */
#define IPC_REGS_CPU2_IPCCLR_IPC18_Msk (0x1U << IPC_REGS_CPU2_IPCCLR_IPC18_Pos) /*!< IPC18 Mask      0x00040000 */
#define IPC_REGS_CPU2_IPCCLR_IPC18_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCCLR_IPC18_Pos) & IPC_REGS_CPU2_IPCCLR_IPC18_Msk) /*!< IPC18 Set Value */
#define IPC_REGS_CPU2_IPCCLR_IPC18_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCCLR_IPC18_Msk) >> IPC_REGS_CPU2_IPCCLR_IPC18_Pos) /*!< IPC18 Get Value */

#define IPC_REGS_CPU2_IPCCLR_IPC17_Pos (17U)                                    /*!< IPC17 Position  17         */
#define IPC_REGS_CPU2_IPCCLR_IPC17_Msk (0x1U << IPC_REGS_CPU2_IPCCLR_IPC17_Pos) /*!< IPC17 Mask      0x00020000 */
#define IPC_REGS_CPU2_IPCCLR_IPC17_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCCLR_IPC17_Pos) & IPC_REGS_CPU2_IPCCLR_IPC17_Msk) /*!< IPC17 Set Value */
#define IPC_REGS_CPU2_IPCCLR_IPC17_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCCLR_IPC17_Msk) >> IPC_REGS_CPU2_IPCCLR_IPC17_Pos) /*!< IPC17 Get Value */

#define IPC_REGS_CPU2_IPCCLR_IPC16_Pos (16U)                                    /*!< IPC16 Position  16         */
#define IPC_REGS_CPU2_IPCCLR_IPC16_Msk (0x1U << IPC_REGS_CPU2_IPCCLR_IPC16_Pos) /*!< IPC16 Mask      0x00010000 */
#define IPC_REGS_CPU2_IPCCLR_IPC16_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCCLR_IPC16_Pos) & IPC_REGS_CPU2_IPCCLR_IPC16_Msk) /*!< IPC16 Set Value */
#define IPC_REGS_CPU2_IPCCLR_IPC16_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCCLR_IPC16_Msk) >> IPC_REGS_CPU2_IPCCLR_IPC16_Pos) /*!< IPC16 Get Value */

#define IPC_REGS_CPU2_IPCCLR_IPC15_Pos (15U)                                    /*!< IPC15 Position  15         */
#define IPC_REGS_CPU2_IPCCLR_IPC15_Msk (0x1U << IPC_REGS_CPU2_IPCCLR_IPC15_Pos) /*!< IPC15 Mask      0x00008000 */
#define IPC_REGS_CPU2_IPCCLR_IPC15_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCCLR_IPC15_Pos) & IPC_REGS_CPU2_IPCCLR_IPC15_Msk) /*!< IPC15 Set Value */
#define IPC_REGS_CPU2_IPCCLR_IPC15_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCCLR_IPC15_Msk) >> IPC_REGS_CPU2_IPCCLR_IPC15_Pos) /*!< IPC15 Get Value */

#define IPC_REGS_CPU2_IPCCLR_IPC14_Pos (14U)                                    /*!< IPC14 Position  14         */
#define IPC_REGS_CPU2_IPCCLR_IPC14_Msk (0x1U << IPC_REGS_CPU2_IPCCLR_IPC14_Pos) /*!< IPC14 Mask      0x00004000 */
#define IPC_REGS_CPU2_IPCCLR_IPC14_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCCLR_IPC14_Pos) & IPC_REGS_CPU2_IPCCLR_IPC14_Msk) /*!< IPC14 Set Value */
#define IPC_REGS_CPU2_IPCCLR_IPC14_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCCLR_IPC14_Msk) >> IPC_REGS_CPU2_IPCCLR_IPC14_Pos) /*!< IPC14 Get Value */

#define IPC_REGS_CPU2_IPCCLR_IPC13_Pos (13U)                                    /*!< IPC13 Position  13         */
#define IPC_REGS_CPU2_IPCCLR_IPC13_Msk (0x1U << IPC_REGS_CPU2_IPCCLR_IPC13_Pos) /*!< IPC13 Mask      0x00002000 */
#define IPC_REGS_CPU2_IPCCLR_IPC13_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCCLR_IPC13_Pos) & IPC_REGS_CPU2_IPCCLR_IPC13_Msk) /*!< IPC13 Set Value */
#define IPC_REGS_CPU2_IPCCLR_IPC13_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCCLR_IPC13_Msk) >> IPC_REGS_CPU2_IPCCLR_IPC13_Pos) /*!< IPC13 Get Value */

#define IPC_REGS_CPU2_IPCCLR_IPC12_Pos (12U)                                    /*!< IPC12 Position  12         */
#define IPC_REGS_CPU2_IPCCLR_IPC12_Msk (0x1U << IPC_REGS_CPU2_IPCCLR_IPC12_Pos) /*!< IPC12 Mask      0x00001000 */
#define IPC_REGS_CPU2_IPCCLR_IPC12_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCCLR_IPC12_Pos) & IPC_REGS_CPU2_IPCCLR_IPC12_Msk) /*!< IPC12 Set Value */
#define IPC_REGS_CPU2_IPCCLR_IPC12_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCCLR_IPC12_Msk) >> IPC_REGS_CPU2_IPCCLR_IPC12_Pos) /*!< IPC12 Get Value */

#define IPC_REGS_CPU2_IPCCLR_IPC11_Pos (11U)                                    /*!< IPC11 Position  11         */
#define IPC_REGS_CPU2_IPCCLR_IPC11_Msk (0x1U << IPC_REGS_CPU2_IPCCLR_IPC11_Pos) /*!< IPC11 Mask      0x00000800 */
#define IPC_REGS_CPU2_IPCCLR_IPC11_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCCLR_IPC11_Pos) & IPC_REGS_CPU2_IPCCLR_IPC11_Msk) /*!< IPC11 Set Value */
#define IPC_REGS_CPU2_IPCCLR_IPC11_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCCLR_IPC11_Msk) >> IPC_REGS_CPU2_IPCCLR_IPC11_Pos) /*!< IPC11 Get Value */

#define IPC_REGS_CPU2_IPCCLR_IPC10_Pos (10U)                                    /*!< IPC10 Position  10         */
#define IPC_REGS_CPU2_IPCCLR_IPC10_Msk (0x1U << IPC_REGS_CPU2_IPCCLR_IPC10_Pos) /*!< IPC10 Mask      0x00000400 */
#define IPC_REGS_CPU2_IPCCLR_IPC10_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCCLR_IPC10_Pos) & IPC_REGS_CPU2_IPCCLR_IPC10_Msk) /*!< IPC10 Set Value */
#define IPC_REGS_CPU2_IPCCLR_IPC10_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCCLR_IPC10_Msk) >> IPC_REGS_CPU2_IPCCLR_IPC10_Pos) /*!< IPC10 Get Value */

#define IPC_REGS_CPU2_IPCCLR_IPC9_Pos (9U)                                    /*!< IPC9 Position  9          */
#define IPC_REGS_CPU2_IPCCLR_IPC9_Msk (0x1U << IPC_REGS_CPU2_IPCCLR_IPC9_Pos) /*!< IPC9 Mask      0x00000200 */
#define IPC_REGS_CPU2_IPCCLR_IPC9_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCCLR_IPC9_Pos) & IPC_REGS_CPU2_IPCCLR_IPC9_Msk) /*!< IPC9 Set Value */
#define IPC_REGS_CPU2_IPCCLR_IPC9_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCCLR_IPC9_Msk) >> IPC_REGS_CPU2_IPCCLR_IPC9_Pos) /*!< IPC9 Get Value            */

#define IPC_REGS_CPU2_IPCCLR_IPC8_Pos (8U)                                    /*!< IPC8 Position  8          */
#define IPC_REGS_CPU2_IPCCLR_IPC8_Msk (0x1U << IPC_REGS_CPU2_IPCCLR_IPC8_Pos) /*!< IPC8 Mask      0x00000100 */
#define IPC_REGS_CPU2_IPCCLR_IPC8_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCCLR_IPC8_Pos) & IPC_REGS_CPU2_IPCCLR_IPC8_Msk) /*!< IPC8 Set Value */
#define IPC_REGS_CPU2_IPCCLR_IPC8_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCCLR_IPC8_Msk) >> IPC_REGS_CPU2_IPCCLR_IPC8_Pos) /*!< IPC8 Get Value            */

#define IPC_REGS_CPU2_IPCCLR_IPC7_Pos (7U)                                    /*!< IPC7 Position  7          */
#define IPC_REGS_CPU2_IPCCLR_IPC7_Msk (0x1U << IPC_REGS_CPU2_IPCCLR_IPC7_Pos) /*!< IPC7 Mask      0x00000080 */
#define IPC_REGS_CPU2_IPCCLR_IPC7_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCCLR_IPC7_Pos) & IPC_REGS_CPU2_IPCCLR_IPC7_Msk) /*!< IPC7 Set Value */
#define IPC_REGS_CPU2_IPCCLR_IPC7_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCCLR_IPC7_Msk) >> IPC_REGS_CPU2_IPCCLR_IPC7_Pos) /*!< IPC7 Get Value            */

#define IPC_REGS_CPU2_IPCCLR_IPC6_Pos (6U)                                    /*!< IPC6 Position  6          */
#define IPC_REGS_CPU2_IPCCLR_IPC6_Msk (0x1U << IPC_REGS_CPU2_IPCCLR_IPC6_Pos) /*!< IPC6 Mask      0x00000040 */
#define IPC_REGS_CPU2_IPCCLR_IPC6_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCCLR_IPC6_Pos) & IPC_REGS_CPU2_IPCCLR_IPC6_Msk) /*!< IPC6 Set Value */
#define IPC_REGS_CPU2_IPCCLR_IPC6_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCCLR_IPC6_Msk) >> IPC_REGS_CPU2_IPCCLR_IPC6_Pos) /*!< IPC6 Get Value            */

#define IPC_REGS_CPU2_IPCCLR_IPC5_Pos (5U)                                    /*!< IPC5 Position  5          */
#define IPC_REGS_CPU2_IPCCLR_IPC5_Msk (0x1U << IPC_REGS_CPU2_IPCCLR_IPC5_Pos) /*!< IPC5 Mask      0x00000020 */
#define IPC_REGS_CPU2_IPCCLR_IPC5_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCCLR_IPC5_Pos) & IPC_REGS_CPU2_IPCCLR_IPC5_Msk) /*!< IPC5 Set Value */
#define IPC_REGS_CPU2_IPCCLR_IPC5_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCCLR_IPC5_Msk) >> IPC_REGS_CPU2_IPCCLR_IPC5_Pos) /*!< IPC5 Get Value            */

#define IPC_REGS_CPU2_IPCCLR_IPC4_Pos (4U)                                    /*!< IPC4 Position  4          */
#define IPC_REGS_CPU2_IPCCLR_IPC4_Msk (0x1U << IPC_REGS_CPU2_IPCCLR_IPC4_Pos) /*!< IPC4 Mask      0x00000010 */
#define IPC_REGS_CPU2_IPCCLR_IPC4_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCCLR_IPC4_Pos) & IPC_REGS_CPU2_IPCCLR_IPC4_Msk) /*!< IPC4 Set Value */
#define IPC_REGS_CPU2_IPCCLR_IPC4_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCCLR_IPC4_Msk) >> IPC_REGS_CPU2_IPCCLR_IPC4_Pos) /*!< IPC4 Get Value            */

#define IPC_REGS_CPU2_IPCCLR_IPC3_Pos (3U)                                    /*!< IPC3 Position  3          */
#define IPC_REGS_CPU2_IPCCLR_IPC3_Msk (0x1U << IPC_REGS_CPU2_IPCCLR_IPC3_Pos) /*!< IPC3 Mask      0x00000008 */
#define IPC_REGS_CPU2_IPCCLR_IPC3_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCCLR_IPC3_Pos) & IPC_REGS_CPU2_IPCCLR_IPC3_Msk) /*!< IPC3 Set Value */
#define IPC_REGS_CPU2_IPCCLR_IPC3_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCCLR_IPC3_Msk) >> IPC_REGS_CPU2_IPCCLR_IPC3_Pos) /*!< IPC3 Get Value            */

#define IPC_REGS_CPU2_IPCCLR_IPC2_Pos (2U)                                    /*!< IPC2 Position  2          */
#define IPC_REGS_CPU2_IPCCLR_IPC2_Msk (0x1U << IPC_REGS_CPU2_IPCCLR_IPC2_Pos) /*!< IPC2 Mask      0x00000004 */
#define IPC_REGS_CPU2_IPCCLR_IPC2_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCCLR_IPC2_Pos) & IPC_REGS_CPU2_IPCCLR_IPC2_Msk) /*!< IPC2 Set Value */
#define IPC_REGS_CPU2_IPCCLR_IPC2_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCCLR_IPC2_Msk) >> IPC_REGS_CPU2_IPCCLR_IPC2_Pos) /*!< IPC2 Get Value            */

#define IPC_REGS_CPU2_IPCCLR_IPC1_Pos (1U)                                    /*!< IPC1 Position  1          */
#define IPC_REGS_CPU2_IPCCLR_IPC1_Msk (0x1U << IPC_REGS_CPU2_IPCCLR_IPC1_Pos) /*!< IPC1 Mask      0x00000002 */
#define IPC_REGS_CPU2_IPCCLR_IPC1_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCCLR_IPC1_Pos) & IPC_REGS_CPU2_IPCCLR_IPC1_Msk) /*!< IPC1 Set Value */
#define IPC_REGS_CPU2_IPCCLR_IPC1_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCCLR_IPC1_Msk) >> IPC_REGS_CPU2_IPCCLR_IPC1_Pos) /*!< IPC1 Get Value            */

#define IPC_REGS_CPU2_IPCCLR_IPC0_Pos (0U)                                    /*!< IPC0 Position  0          */
#define IPC_REGS_CPU2_IPCCLR_IPC0_Msk (0x1U << IPC_REGS_CPU2_IPCCLR_IPC0_Pos) /*!< IPC0 Mask      0x00000001 */
#define IPC_REGS_CPU2_IPCCLR_IPC0_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCCLR_IPC0_Pos) & IPC_REGS_CPU2_IPCCLR_IPC0_Msk) /*!< IPC0 Set Value */
#define IPC_REGS_CPU2_IPCCLR_IPC0_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCCLR_IPC0_Msk) >> IPC_REGS_CPU2_IPCCLR_IPC0_Pos) /*!< IPC0 Get Value            */

/* IPCFLG bitfield */
#define IPC_REGS_CPU2_IPCFLG_IPC31_Pos (31U)                                    /*!< IPC31 Position  31         */
#define IPC_REGS_CPU2_IPCFLG_IPC31_Msk (0x1U << IPC_REGS_CPU2_IPCFLG_IPC31_Pos) /*!< IPC31 Mask      0x80000000 */
#define IPC_REGS_CPU2_IPCFLG_IPC31_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCFLG_IPC31_Pos) & IPC_REGS_CPU2_IPCFLG_IPC31_Msk) /*!< IPC31 Set Value */
#define IPC_REGS_CPU2_IPCFLG_IPC31_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCFLG_IPC31_Msk) >> IPC_REGS_CPU2_IPCFLG_IPC31_Pos) /*!< IPC31 Get Value */

#define IPC_REGS_CPU2_IPCFLG_IPC30_Pos (30U)                                    /*!< IPC30 Position  30         */
#define IPC_REGS_CPU2_IPCFLG_IPC30_Msk (0x1U << IPC_REGS_CPU2_IPCFLG_IPC30_Pos) /*!< IPC30 Mask      0x40000000 */
#define IPC_REGS_CPU2_IPCFLG_IPC30_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCFLG_IPC30_Pos) & IPC_REGS_CPU2_IPCFLG_IPC30_Msk) /*!< IPC30 Set Value */
#define IPC_REGS_CPU2_IPCFLG_IPC30_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCFLG_IPC30_Msk) >> IPC_REGS_CPU2_IPCFLG_IPC30_Pos) /*!< IPC30 Get Value */

#define IPC_REGS_CPU2_IPCFLG_IPC29_Pos (29U)                                    /*!< IPC29 Position  29         */
#define IPC_REGS_CPU2_IPCFLG_IPC29_Msk (0x1U << IPC_REGS_CPU2_IPCFLG_IPC29_Pos) /*!< IPC29 Mask      0x20000000 */
#define IPC_REGS_CPU2_IPCFLG_IPC29_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCFLG_IPC29_Pos) & IPC_REGS_CPU2_IPCFLG_IPC29_Msk) /*!< IPC29 Set Value */
#define IPC_REGS_CPU2_IPCFLG_IPC29_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCFLG_IPC29_Msk) >> IPC_REGS_CPU2_IPCFLG_IPC29_Pos) /*!< IPC29 Get Value */

#define IPC_REGS_CPU2_IPCFLG_IPC28_Pos (28U)                                    /*!< IPC28 Position  28         */
#define IPC_REGS_CPU2_IPCFLG_IPC28_Msk (0x1U << IPC_REGS_CPU2_IPCFLG_IPC28_Pos) /*!< IPC28 Mask      0x10000000 */
#define IPC_REGS_CPU2_IPCFLG_IPC28_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCFLG_IPC28_Pos) & IPC_REGS_CPU2_IPCFLG_IPC28_Msk) /*!< IPC28 Set Value */
#define IPC_REGS_CPU2_IPCFLG_IPC28_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCFLG_IPC28_Msk) >> IPC_REGS_CPU2_IPCFLG_IPC28_Pos) /*!< IPC28 Get Value */

#define IPC_REGS_CPU2_IPCFLG_IPC27_Pos (27U)                                    /*!< IPC27 Position  27         */
#define IPC_REGS_CPU2_IPCFLG_IPC27_Msk (0x1U << IPC_REGS_CPU2_IPCFLG_IPC27_Pos) /*!< IPC27 Mask      0x08000000 */
#define IPC_REGS_CPU2_IPCFLG_IPC27_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCFLG_IPC27_Pos) & IPC_REGS_CPU2_IPCFLG_IPC27_Msk) /*!< IPC27 Set Value */
#define IPC_REGS_CPU2_IPCFLG_IPC27_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCFLG_IPC27_Msk) >> IPC_REGS_CPU2_IPCFLG_IPC27_Pos) /*!< IPC27 Get Value */

#define IPC_REGS_CPU2_IPCFLG_IPC26_Pos (26U)                                    /*!< IPC26 Position  26         */
#define IPC_REGS_CPU2_IPCFLG_IPC26_Msk (0x1U << IPC_REGS_CPU2_IPCFLG_IPC26_Pos) /*!< IPC26 Mask      0x04000000 */
#define IPC_REGS_CPU2_IPCFLG_IPC26_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCFLG_IPC26_Pos) & IPC_REGS_CPU2_IPCFLG_IPC26_Msk) /*!< IPC26 Set Value */
#define IPC_REGS_CPU2_IPCFLG_IPC26_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCFLG_IPC26_Msk) >> IPC_REGS_CPU2_IPCFLG_IPC26_Pos) /*!< IPC26 Get Value */

#define IPC_REGS_CPU2_IPCFLG_IPC25_Pos (25U)                                    /*!< IPC25 Position  25         */
#define IPC_REGS_CPU2_IPCFLG_IPC25_Msk (0x1U << IPC_REGS_CPU2_IPCFLG_IPC25_Pos) /*!< IPC25 Mask      0x02000000 */
#define IPC_REGS_CPU2_IPCFLG_IPC25_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCFLG_IPC25_Pos) & IPC_REGS_CPU2_IPCFLG_IPC25_Msk) /*!< IPC25 Set Value */
#define IPC_REGS_CPU2_IPCFLG_IPC25_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCFLG_IPC25_Msk) >> IPC_REGS_CPU2_IPCFLG_IPC25_Pos) /*!< IPC25 Get Value */

#define IPC_REGS_CPU2_IPCFLG_IPC24_Pos (24U)                                    /*!< IPC24 Position  24         */
#define IPC_REGS_CPU2_IPCFLG_IPC24_Msk (0x1U << IPC_REGS_CPU2_IPCFLG_IPC24_Pos) /*!< IPC24 Mask      0x01000000 */
#define IPC_REGS_CPU2_IPCFLG_IPC24_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCFLG_IPC24_Pos) & IPC_REGS_CPU2_IPCFLG_IPC24_Msk) /*!< IPC24 Set Value */
#define IPC_REGS_CPU2_IPCFLG_IPC24_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCFLG_IPC24_Msk) >> IPC_REGS_CPU2_IPCFLG_IPC24_Pos) /*!< IPC24 Get Value */

#define IPC_REGS_CPU2_IPCFLG_IPC23_Pos (23U)                                    /*!< IPC23 Position  23         */
#define IPC_REGS_CPU2_IPCFLG_IPC23_Msk (0x1U << IPC_REGS_CPU2_IPCFLG_IPC23_Pos) /*!< IPC23 Mask      0x00800000 */
#define IPC_REGS_CPU2_IPCFLG_IPC23_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCFLG_IPC23_Pos) & IPC_REGS_CPU2_IPCFLG_IPC23_Msk) /*!< IPC23 Set Value */
#define IPC_REGS_CPU2_IPCFLG_IPC23_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCFLG_IPC23_Msk) >> IPC_REGS_CPU2_IPCFLG_IPC23_Pos) /*!< IPC23 Get Value */

#define IPC_REGS_CPU2_IPCFLG_IPC22_Pos (22U)                                    /*!< IPC22 Position  22         */
#define IPC_REGS_CPU2_IPCFLG_IPC22_Msk (0x1U << IPC_REGS_CPU2_IPCFLG_IPC22_Pos) /*!< IPC22 Mask      0x00400000 */
#define IPC_REGS_CPU2_IPCFLG_IPC22_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCFLG_IPC22_Pos) & IPC_REGS_CPU2_IPCFLG_IPC22_Msk) /*!< IPC22 Set Value */
#define IPC_REGS_CPU2_IPCFLG_IPC22_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCFLG_IPC22_Msk) >> IPC_REGS_CPU2_IPCFLG_IPC22_Pos) /*!< IPC22 Get Value */

#define IPC_REGS_CPU2_IPCFLG_IPC21_Pos (21U)                                    /*!< IPC21 Position  21         */
#define IPC_REGS_CPU2_IPCFLG_IPC21_Msk (0x1U << IPC_REGS_CPU2_IPCFLG_IPC21_Pos) /*!< IPC21 Mask      0x00200000 */
#define IPC_REGS_CPU2_IPCFLG_IPC21_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCFLG_IPC21_Pos) & IPC_REGS_CPU2_IPCFLG_IPC21_Msk) /*!< IPC21 Set Value */
#define IPC_REGS_CPU2_IPCFLG_IPC21_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCFLG_IPC21_Msk) >> IPC_REGS_CPU2_IPCFLG_IPC21_Pos) /*!< IPC21 Get Value */

#define IPC_REGS_CPU2_IPCFLG_IPC20_Pos (20U)                                    /*!< IPC20 Position  20         */
#define IPC_REGS_CPU2_IPCFLG_IPC20_Msk (0x1U << IPC_REGS_CPU2_IPCFLG_IPC20_Pos) /*!< IPC20 Mask      0x00100000 */
#define IPC_REGS_CPU2_IPCFLG_IPC20_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCFLG_IPC20_Pos) & IPC_REGS_CPU2_IPCFLG_IPC20_Msk) /*!< IPC20 Set Value */
#define IPC_REGS_CPU2_IPCFLG_IPC20_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCFLG_IPC20_Msk) >> IPC_REGS_CPU2_IPCFLG_IPC20_Pos) /*!< IPC20 Get Value */

#define IPC_REGS_CPU2_IPCFLG_IPC19_Pos (19U)                                    /*!< IPC19 Position  19         */
#define IPC_REGS_CPU2_IPCFLG_IPC19_Msk (0x1U << IPC_REGS_CPU2_IPCFLG_IPC19_Pos) /*!< IPC19 Mask      0x00080000 */
#define IPC_REGS_CPU2_IPCFLG_IPC19_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCFLG_IPC19_Pos) & IPC_REGS_CPU2_IPCFLG_IPC19_Msk) /*!< IPC19 Set Value */
#define IPC_REGS_CPU2_IPCFLG_IPC19_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCFLG_IPC19_Msk) >> IPC_REGS_CPU2_IPCFLG_IPC19_Pos) /*!< IPC19 Get Value */

#define IPC_REGS_CPU2_IPCFLG_IPC18_Pos (18U)                                    /*!< IPC18 Position  18         */
#define IPC_REGS_CPU2_IPCFLG_IPC18_Msk (0x1U << IPC_REGS_CPU2_IPCFLG_IPC18_Pos) /*!< IPC18 Mask      0x00040000 */
#define IPC_REGS_CPU2_IPCFLG_IPC18_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCFLG_IPC18_Pos) & IPC_REGS_CPU2_IPCFLG_IPC18_Msk) /*!< IPC18 Set Value */
#define IPC_REGS_CPU2_IPCFLG_IPC18_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCFLG_IPC18_Msk) >> IPC_REGS_CPU2_IPCFLG_IPC18_Pos) /*!< IPC18 Get Value */

#define IPC_REGS_CPU2_IPCFLG_IPC17_Pos (17U)                                    /*!< IPC17 Position  17         */
#define IPC_REGS_CPU2_IPCFLG_IPC17_Msk (0x1U << IPC_REGS_CPU2_IPCFLG_IPC17_Pos) /*!< IPC17 Mask      0x00020000 */
#define IPC_REGS_CPU2_IPCFLG_IPC17_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCFLG_IPC17_Pos) & IPC_REGS_CPU2_IPCFLG_IPC17_Msk) /*!< IPC17 Set Value */
#define IPC_REGS_CPU2_IPCFLG_IPC17_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCFLG_IPC17_Msk) >> IPC_REGS_CPU2_IPCFLG_IPC17_Pos) /*!< IPC17 Get Value */

#define IPC_REGS_CPU2_IPCFLG_IPC16_Pos (16U)                                    /*!< IPC16 Position  16         */
#define IPC_REGS_CPU2_IPCFLG_IPC16_Msk (0x1U << IPC_REGS_CPU2_IPCFLG_IPC16_Pos) /*!< IPC16 Mask      0x00010000 */
#define IPC_REGS_CPU2_IPCFLG_IPC16_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCFLG_IPC16_Pos) & IPC_REGS_CPU2_IPCFLG_IPC16_Msk) /*!< IPC16 Set Value */
#define IPC_REGS_CPU2_IPCFLG_IPC16_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCFLG_IPC16_Msk) >> IPC_REGS_CPU2_IPCFLG_IPC16_Pos) /*!< IPC16 Get Value */

#define IPC_REGS_CPU2_IPCFLG_IPC15_Pos (15U)                                    /*!< IPC15 Position  15         */
#define IPC_REGS_CPU2_IPCFLG_IPC15_Msk (0x1U << IPC_REGS_CPU2_IPCFLG_IPC15_Pos) /*!< IPC15 Mask      0x00008000 */
#define IPC_REGS_CPU2_IPCFLG_IPC15_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCFLG_IPC15_Pos) & IPC_REGS_CPU2_IPCFLG_IPC15_Msk) /*!< IPC15 Set Value */
#define IPC_REGS_CPU2_IPCFLG_IPC15_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCFLG_IPC15_Msk) >> IPC_REGS_CPU2_IPCFLG_IPC15_Pos) /*!< IPC15 Get Value */

#define IPC_REGS_CPU2_IPCFLG_IPC14_Pos (14U)                                    /*!< IPC14 Position  14         */
#define IPC_REGS_CPU2_IPCFLG_IPC14_Msk (0x1U << IPC_REGS_CPU2_IPCFLG_IPC14_Pos) /*!< IPC14 Mask      0x00004000 */
#define IPC_REGS_CPU2_IPCFLG_IPC14_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCFLG_IPC14_Pos) & IPC_REGS_CPU2_IPCFLG_IPC14_Msk) /*!< IPC14 Set Value */
#define IPC_REGS_CPU2_IPCFLG_IPC14_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCFLG_IPC14_Msk) >> IPC_REGS_CPU2_IPCFLG_IPC14_Pos) /*!< IPC14 Get Value */

#define IPC_REGS_CPU2_IPCFLG_IPC13_Pos (13U)                                    /*!< IPC13 Position  13         */
#define IPC_REGS_CPU2_IPCFLG_IPC13_Msk (0x1U << IPC_REGS_CPU2_IPCFLG_IPC13_Pos) /*!< IPC13 Mask      0x00002000 */
#define IPC_REGS_CPU2_IPCFLG_IPC13_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCFLG_IPC13_Pos) & IPC_REGS_CPU2_IPCFLG_IPC13_Msk) /*!< IPC13 Set Value */
#define IPC_REGS_CPU2_IPCFLG_IPC13_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCFLG_IPC13_Msk) >> IPC_REGS_CPU2_IPCFLG_IPC13_Pos) /*!< IPC13 Get Value */

#define IPC_REGS_CPU2_IPCFLG_IPC12_Pos (12U)                                    /*!< IPC12 Position  12         */
#define IPC_REGS_CPU2_IPCFLG_IPC12_Msk (0x1U << IPC_REGS_CPU2_IPCFLG_IPC12_Pos) /*!< IPC12 Mask      0x00001000 */
#define IPC_REGS_CPU2_IPCFLG_IPC12_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCFLG_IPC12_Pos) & IPC_REGS_CPU2_IPCFLG_IPC12_Msk) /*!< IPC12 Set Value */
#define IPC_REGS_CPU2_IPCFLG_IPC12_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCFLG_IPC12_Msk) >> IPC_REGS_CPU2_IPCFLG_IPC12_Pos) /*!< IPC12 Get Value */

#define IPC_REGS_CPU2_IPCFLG_IPC11_Pos (11U)                                    /*!< IPC11 Position  11         */
#define IPC_REGS_CPU2_IPCFLG_IPC11_Msk (0x1U << IPC_REGS_CPU2_IPCFLG_IPC11_Pos) /*!< IPC11 Mask      0x00000800 */
#define IPC_REGS_CPU2_IPCFLG_IPC11_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCFLG_IPC11_Pos) & IPC_REGS_CPU2_IPCFLG_IPC11_Msk) /*!< IPC11 Set Value */
#define IPC_REGS_CPU2_IPCFLG_IPC11_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCFLG_IPC11_Msk) >> IPC_REGS_CPU2_IPCFLG_IPC11_Pos) /*!< IPC11 Get Value */

#define IPC_REGS_CPU2_IPCFLG_IPC10_Pos (10U)                                    /*!< IPC10 Position  10         */
#define IPC_REGS_CPU2_IPCFLG_IPC10_Msk (0x1U << IPC_REGS_CPU2_IPCFLG_IPC10_Pos) /*!< IPC10 Mask      0x00000400 */
#define IPC_REGS_CPU2_IPCFLG_IPC10_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCFLG_IPC10_Pos) & IPC_REGS_CPU2_IPCFLG_IPC10_Msk) /*!< IPC10 Set Value */
#define IPC_REGS_CPU2_IPCFLG_IPC10_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCFLG_IPC10_Msk) >> IPC_REGS_CPU2_IPCFLG_IPC10_Pos) /*!< IPC10 Get Value */

#define IPC_REGS_CPU2_IPCFLG_IPC9_Pos (9U)                                    /*!< IPC9 Position  9          */
#define IPC_REGS_CPU2_IPCFLG_IPC9_Msk (0x1U << IPC_REGS_CPU2_IPCFLG_IPC9_Pos) /*!< IPC9 Mask      0x00000200 */
#define IPC_REGS_CPU2_IPCFLG_IPC9_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCFLG_IPC9_Pos) & IPC_REGS_CPU2_IPCFLG_IPC9_Msk) /*!< IPC9 Set Value */
#define IPC_REGS_CPU2_IPCFLG_IPC9_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCFLG_IPC9_Msk) >> IPC_REGS_CPU2_IPCFLG_IPC9_Pos) /*!< IPC9 Get Value            */

#define IPC_REGS_CPU2_IPCFLG_IPC8_Pos (8U)                                    /*!< IPC8 Position  8          */
#define IPC_REGS_CPU2_IPCFLG_IPC8_Msk (0x1U << IPC_REGS_CPU2_IPCFLG_IPC8_Pos) /*!< IPC8 Mask      0x00000100 */
#define IPC_REGS_CPU2_IPCFLG_IPC8_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCFLG_IPC8_Pos) & IPC_REGS_CPU2_IPCFLG_IPC8_Msk) /*!< IPC8 Set Value */
#define IPC_REGS_CPU2_IPCFLG_IPC8_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCFLG_IPC8_Msk) >> IPC_REGS_CPU2_IPCFLG_IPC8_Pos) /*!< IPC8 Get Value            */

#define IPC_REGS_CPU2_IPCFLG_IPC7_Pos (7U)                                    /*!< IPC7 Position  7          */
#define IPC_REGS_CPU2_IPCFLG_IPC7_Msk (0x1U << IPC_REGS_CPU2_IPCFLG_IPC7_Pos) /*!< IPC7 Mask      0x00000080 */
#define IPC_REGS_CPU2_IPCFLG_IPC7_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCFLG_IPC7_Pos) & IPC_REGS_CPU2_IPCFLG_IPC7_Msk) /*!< IPC7 Set Value */
#define IPC_REGS_CPU2_IPCFLG_IPC7_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCFLG_IPC7_Msk) >> IPC_REGS_CPU2_IPCFLG_IPC7_Pos) /*!< IPC7 Get Value            */

#define IPC_REGS_CPU2_IPCFLG_IPC6_Pos (6U)                                    /*!< IPC6 Position  6          */
#define IPC_REGS_CPU2_IPCFLG_IPC6_Msk (0x1U << IPC_REGS_CPU2_IPCFLG_IPC6_Pos) /*!< IPC6 Mask      0x00000040 */
#define IPC_REGS_CPU2_IPCFLG_IPC6_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCFLG_IPC6_Pos) & IPC_REGS_CPU2_IPCFLG_IPC6_Msk) /*!< IPC6 Set Value */
#define IPC_REGS_CPU2_IPCFLG_IPC6_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCFLG_IPC6_Msk) >> IPC_REGS_CPU2_IPCFLG_IPC6_Pos) /*!< IPC6 Get Value            */

#define IPC_REGS_CPU2_IPCFLG_IPC5_Pos (5U)                                    /*!< IPC5 Position  5          */
#define IPC_REGS_CPU2_IPCFLG_IPC5_Msk (0x1U << IPC_REGS_CPU2_IPCFLG_IPC5_Pos) /*!< IPC5 Mask      0x00000020 */
#define IPC_REGS_CPU2_IPCFLG_IPC5_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCFLG_IPC5_Pos) & IPC_REGS_CPU2_IPCFLG_IPC5_Msk) /*!< IPC5 Set Value */
#define IPC_REGS_CPU2_IPCFLG_IPC5_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCFLG_IPC5_Msk) >> IPC_REGS_CPU2_IPCFLG_IPC5_Pos) /*!< IPC5 Get Value            */

#define IPC_REGS_CPU2_IPCFLG_IPC4_Pos (4U)                                    /*!< IPC4 Position  4          */
#define IPC_REGS_CPU2_IPCFLG_IPC4_Msk (0x1U << IPC_REGS_CPU2_IPCFLG_IPC4_Pos) /*!< IPC4 Mask      0x00000010 */
#define IPC_REGS_CPU2_IPCFLG_IPC4_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCFLG_IPC4_Pos) & IPC_REGS_CPU2_IPCFLG_IPC4_Msk) /*!< IPC4 Set Value */
#define IPC_REGS_CPU2_IPCFLG_IPC4_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCFLG_IPC4_Msk) >> IPC_REGS_CPU2_IPCFLG_IPC4_Pos) /*!< IPC4 Get Value            */

#define IPC_REGS_CPU2_IPCFLG_IPC3_Pos (3U)                                    /*!< IPC3 Position  3          */
#define IPC_REGS_CPU2_IPCFLG_IPC3_Msk (0x1U << IPC_REGS_CPU2_IPCFLG_IPC3_Pos) /*!< IPC3 Mask      0x00000008 */
#define IPC_REGS_CPU2_IPCFLG_IPC3_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCFLG_IPC3_Pos) & IPC_REGS_CPU2_IPCFLG_IPC3_Msk) /*!< IPC3 Set Value */
#define IPC_REGS_CPU2_IPCFLG_IPC3_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCFLG_IPC3_Msk) >> IPC_REGS_CPU2_IPCFLG_IPC3_Pos) /*!< IPC3 Get Value            */

#define IPC_REGS_CPU2_IPCFLG_IPC2_Pos (2U)                                    /*!< IPC2 Position  2          */
#define IPC_REGS_CPU2_IPCFLG_IPC2_Msk (0x1U << IPC_REGS_CPU2_IPCFLG_IPC2_Pos) /*!< IPC2 Mask      0x00000004 */
#define IPC_REGS_CPU2_IPCFLG_IPC2_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCFLG_IPC2_Pos) & IPC_REGS_CPU2_IPCFLG_IPC2_Msk) /*!< IPC2 Set Value */
#define IPC_REGS_CPU2_IPCFLG_IPC2_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCFLG_IPC2_Msk) >> IPC_REGS_CPU2_IPCFLG_IPC2_Pos) /*!< IPC2 Get Value            */

#define IPC_REGS_CPU2_IPCFLG_IPC1_Pos (1U)                                    /*!< IPC1 Position  1          */
#define IPC_REGS_CPU2_IPCFLG_IPC1_Msk (0x1U << IPC_REGS_CPU2_IPCFLG_IPC1_Pos) /*!< IPC1 Mask      0x00000002 */
#define IPC_REGS_CPU2_IPCFLG_IPC1_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCFLG_IPC1_Pos) & IPC_REGS_CPU2_IPCFLG_IPC1_Msk) /*!< IPC1 Set Value */
#define IPC_REGS_CPU2_IPCFLG_IPC1_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCFLG_IPC1_Msk) >> IPC_REGS_CPU2_IPCFLG_IPC1_Pos) /*!< IPC1 Get Value            */

#define IPC_REGS_CPU2_IPCFLG_IPC0_Pos (0U)                                    /*!< IPC0 Position  0          */
#define IPC_REGS_CPU2_IPCFLG_IPC0_Msk (0x1U << IPC_REGS_CPU2_IPCFLG_IPC0_Pos) /*!< IPC0 Mask      0x00000001 */
#define IPC_REGS_CPU2_IPCFLG_IPC0_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCFLG_IPC0_Pos) & IPC_REGS_CPU2_IPCFLG_IPC0_Msk) /*!< IPC0 Set Value */
#define IPC_REGS_CPU2_IPCFLG_IPC0_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCFLG_IPC0_Msk) >> IPC_REGS_CPU2_IPCFLG_IPC0_Pos) /*!< IPC0 Get Value            */

/* IPCCOUNTERL bitfield */
#define IPC_REGS_CPU2_IPCCOUNTERL_COUNT_Pos (0U) /*!< COUNT Position  0          */
#define IPC_REGS_CPU2_IPCCOUNTERL_COUNT_Msk \
    (0xffffffffU << IPC_REGS_CPU2_IPCCOUNTERL_COUNT_Pos) /*!< COUNT Mask      0xFFFFFFFF */
#define IPC_REGS_CPU2_IPCCOUNTERL_COUNT_Set(x)                \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCCOUNTERL_COUNT_Pos) & \
     IPC_REGS_CPU2_IPCCOUNTERL_COUNT_Msk) /*!< COUNT Set Value            */
#define IPC_REGS_CPU2_IPCCOUNTERL_COUNT_Get(x)              \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCCOUNTERL_COUNT_Msk) >> \
     IPC_REGS_CPU2_IPCCOUNTERL_COUNT_Pos) /*!< COUNT Get Value            */

/* IPCCOUNTERH bitfield */
#define IPC_REGS_CPU2_IPCCOUNTERH_COUNT_Pos (0U) /*!< COUNT Position  0          */
#define IPC_REGS_CPU2_IPCCOUNTERH_COUNT_Msk \
    (0xffffffffU << IPC_REGS_CPU2_IPCCOUNTERH_COUNT_Pos) /*!< COUNT Mask      0xFFFFFFFF */
#define IPC_REGS_CPU2_IPCCOUNTERH_COUNT_Set(x)                \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCCOUNTERH_COUNT_Pos) & \
     IPC_REGS_CPU2_IPCCOUNTERH_COUNT_Msk) /*!< COUNT Set Value            */
#define IPC_REGS_CPU2_IPCCOUNTERH_COUNT_Get(x)              \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCCOUNTERH_COUNT_Msk) >> \
     IPC_REGS_CPU2_IPCCOUNTERH_COUNT_Pos) /*!< COUNT Get Value            */

/* IPCRECVCOM bitfield */
#define IPC_REGS_CPU2_IPCRECVCOM_COMMAND_Pos (0U) /*!< COMMAND Position  0          */
#define IPC_REGS_CPU2_IPCRECVCOM_COMMAND_Msk \
    (0xffffffffU << IPC_REGS_CPU2_IPCRECVCOM_COMMAND_Pos) /*!< COMMAND Mask      0xFFFFFFFF */
#define IPC_REGS_CPU2_IPCRECVCOM_COMMAND_Set(x)                \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCRECVCOM_COMMAND_Pos) & \
     IPC_REGS_CPU2_IPCRECVCOM_COMMAND_Msk) /*!< COMMAND Set Value            */
#define IPC_REGS_CPU2_IPCRECVCOM_COMMAND_Get(x)              \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCRECVCOM_COMMAND_Msk) >> \
     IPC_REGS_CPU2_IPCRECVCOM_COMMAND_Pos) /*!< COMMAND Get Value            */

/* IPCRECVADDR bitfield */
#define IPC_REGS_CPU2_IPCRECVADDR_ADDRESS_Pos (0U) /*!< ADDRESS Position  0          */
#define IPC_REGS_CPU2_IPCRECVADDR_ADDRESS_Msk \
    (0xffffffffU << IPC_REGS_CPU2_IPCRECVADDR_ADDRESS_Pos) /*!< ADDRESS Mask      0xFFFFFFFF */
#define IPC_REGS_CPU2_IPCRECVADDR_ADDRESS_Set(x)                \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCRECVADDR_ADDRESS_Pos) & \
     IPC_REGS_CPU2_IPCRECVADDR_ADDRESS_Msk) /*!< ADDRESS Set Value            */
#define IPC_REGS_CPU2_IPCRECVADDR_ADDRESS_Get(x)              \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCRECVADDR_ADDRESS_Msk) >> \
     IPC_REGS_CPU2_IPCRECVADDR_ADDRESS_Pos) /*!< ADDRESS Get Value            */

/* IPCRECVDATA bitfield */
#define IPC_REGS_CPU2_IPCRECVDATA_WDATA_Pos (0U) /*!< WDATA Position  0          */
#define IPC_REGS_CPU2_IPCRECVDATA_WDATA_Msk \
    (0xffffffffU << IPC_REGS_CPU2_IPCRECVDATA_WDATA_Pos) /*!< WDATA Mask      0xFFFFFFFF */
#define IPC_REGS_CPU2_IPCRECVDATA_WDATA_Set(x)                \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCRECVDATA_WDATA_Pos) & \
     IPC_REGS_CPU2_IPCRECVDATA_WDATA_Msk) /*!< WDATA Set Value            */
#define IPC_REGS_CPU2_IPCRECVDATA_WDATA_Get(x)              \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCRECVDATA_WDATA_Msk) >> \
     IPC_REGS_CPU2_IPCRECVDATA_WDATA_Pos) /*!< WDATA Get Value            */

/* IPCLOCALREPLY bitfield */
#define IPC_REGS_CPU2_IPCLOCALREPLY_RDATA_Pos (0U) /*!< RDATA Position  0          */
#define IPC_REGS_CPU2_IPCLOCALREPLY_RDATA_Msk \
    (0xffffffffU << IPC_REGS_CPU2_IPCLOCALREPLY_RDATA_Pos) /*!< RDATA Mask      0xFFFFFFFF */
#define IPC_REGS_CPU2_IPCLOCALREPLY_RDATA_Set(x)                \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCLOCALREPLY_RDATA_Pos) & \
     IPC_REGS_CPU2_IPCLOCALREPLY_RDATA_Msk) /*!< RDATA Set Value            */
#define IPC_REGS_CPU2_IPCLOCALREPLY_RDATA_Get(x)              \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCLOCALREPLY_RDATA_Msk) >> \
     IPC_REGS_CPU2_IPCLOCALREPLY_RDATA_Pos) /*!< RDATA Get Value            */

/* IPCSENDCOM bitfield */
#define IPC_REGS_CPU2_IPCSENDCOM_COMMAND_Pos (0U) /*!< COMMAND Position  0          */
#define IPC_REGS_CPU2_IPCSENDCOM_COMMAND_Msk \
    (0xffffffffU << IPC_REGS_CPU2_IPCSENDCOM_COMMAND_Pos) /*!< COMMAND Mask      0xFFFFFFFF */
#define IPC_REGS_CPU2_IPCSENDCOM_COMMAND_Set(x)                \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSENDCOM_COMMAND_Pos) & \
     IPC_REGS_CPU2_IPCSENDCOM_COMMAND_Msk) /*!< COMMAND Set Value            */
#define IPC_REGS_CPU2_IPCSENDCOM_COMMAND_Get(x)              \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSENDCOM_COMMAND_Msk) >> \
     IPC_REGS_CPU2_IPCSENDCOM_COMMAND_Pos) /*!< COMMAND Get Value            */

/* IPCSENDADDR bitfield */
#define IPC_REGS_CPU2_IPCSENDADDR_ADDRESS_Pos (0U) /*!< ADDRESS Position  0          */
#define IPC_REGS_CPU2_IPCSENDADDR_ADDRESS_Msk \
    (0xffffffffU << IPC_REGS_CPU2_IPCSENDADDR_ADDRESS_Pos) /*!< ADDRESS Mask      0xFFFFFFFF */
#define IPC_REGS_CPU2_IPCSENDADDR_ADDRESS_Set(x)                \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSENDADDR_ADDRESS_Pos) & \
     IPC_REGS_CPU2_IPCSENDADDR_ADDRESS_Msk) /*!< ADDRESS Set Value            */
#define IPC_REGS_CPU2_IPCSENDADDR_ADDRESS_Get(x)              \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSENDADDR_ADDRESS_Msk) >> \
     IPC_REGS_CPU2_IPCSENDADDR_ADDRESS_Pos) /*!< ADDRESS Get Value            */

/* IPCSENDDATA bitfield */
#define IPC_REGS_CPU2_IPCSENDDATA_WDATA_Pos (0U) /*!< WDATA Position  0          */
#define IPC_REGS_CPU2_IPCSENDDATA_WDATA_Msk \
    (0xffffffffU << IPC_REGS_CPU2_IPCSENDDATA_WDATA_Pos) /*!< WDATA Mask      0xFFFFFFFF */
#define IPC_REGS_CPU2_IPCSENDDATA_WDATA_Set(x)                \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCSENDDATA_WDATA_Pos) & \
     IPC_REGS_CPU2_IPCSENDDATA_WDATA_Msk) /*!< WDATA Set Value            */
#define IPC_REGS_CPU2_IPCSENDDATA_WDATA_Get(x)              \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCSENDDATA_WDATA_Msk) >> \
     IPC_REGS_CPU2_IPCSENDDATA_WDATA_Pos) /*!< WDATA Get Value            */

/* IPCREMOTEREPLY bitfield */
#define IPC_REGS_CPU2_IPCREMOTEREPLY_RDATA_Pos (0U) /*!< RDATA Position  0          */
#define IPC_REGS_CPU2_IPCREMOTEREPLY_RDATA_Msk \
    (0xffffffffU << IPC_REGS_CPU2_IPCREMOTEREPLY_RDATA_Pos) /*!< RDATA Mask      0xFFFFFFFF */
#define IPC_REGS_CPU2_IPCREMOTEREPLY_RDATA_Set(x)                \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCREMOTEREPLY_RDATA_Pos) & \
     IPC_REGS_CPU2_IPCREMOTEREPLY_RDATA_Msk) /*!< RDATA Set Value            */
#define IPC_REGS_CPU2_IPCREMOTEREPLY_RDATA_Get(x)              \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCREMOTEREPLY_RDATA_Msk) >> \
     IPC_REGS_CPU2_IPCREMOTEREPLY_RDATA_Pos) /*!< RDATA Get Value            */

/* IPCBOOTSTS bitfield */
#define IPC_REGS_CPU2_IPCBOOTSTS_BOOTSTS_Pos (0U) /*!< BOOTSTS Position  0          */
#define IPC_REGS_CPU2_IPCBOOTSTS_BOOTSTS_Msk \
    (0xffffffffU << IPC_REGS_CPU2_IPCBOOTSTS_BOOTSTS_Pos) /*!< BOOTSTS Mask      0xFFFFFFFF */
#define IPC_REGS_CPU2_IPCBOOTSTS_BOOTSTS_Set(x)                \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCBOOTSTS_BOOTSTS_Pos) & \
     IPC_REGS_CPU2_IPCBOOTSTS_BOOTSTS_Msk) /*!< BOOTSTS Set Value            */
#define IPC_REGS_CPU2_IPCBOOTSTS_BOOTSTS_Get(x)              \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCBOOTSTS_BOOTSTS_Msk) >> \
     IPC_REGS_CPU2_IPCBOOTSTS_BOOTSTS_Pos) /*!< BOOTSTS Get Value            */

/* IPCBOOTMODE bitfield */
#define IPC_REGS_CPU2_IPCBOOTMODE_BOOTMODE_Pos (0U) /*!< BOOTMODE Position  0          */
#define IPC_REGS_CPU2_IPCBOOTMODE_BOOTMODE_Msk \
    (0xffffffffU << IPC_REGS_CPU2_IPCBOOTMODE_BOOTMODE_Pos) /*!< BOOTMODE Mask      0xFFFFFFFF */
#define IPC_REGS_CPU2_IPCBOOTMODE_BOOTMODE_Set(x)                \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCBOOTMODE_BOOTMODE_Pos) & \
     IPC_REGS_CPU2_IPCBOOTMODE_BOOTMODE_Msk) /*!< BOOTMODE Set Value            */
#define IPC_REGS_CPU2_IPCBOOTMODE_BOOTMODE_Get(x)              \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCBOOTMODE_BOOTMODE_Msk) >> \
     IPC_REGS_CPU2_IPCBOOTMODE_BOOTMODE_Pos) /*!< BOOTMODE Get Value            */

/* IPCMISC bitfield */
#define IPC_REGS_CPU2_IPCMISC_ERRINT_Pos (24U) /*!< ERRINT Position  24         */
#define IPC_REGS_CPU2_IPCMISC_ERRINT_Msk                                        \
    (0x1U << IPC_REGS_CPU2_IPCMISC_ERRINT_Pos) /*!< ERRINT Mask      0x01000000 \
                                                */
#define IPC_REGS_CPU2_IPCMISC_ERRINT_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCMISC_ERRINT_Pos) & IPC_REGS_CPU2_IPCMISC_ERRINT_Msk) /*!< ERRINT Set Value */
#define IPC_REGS_CPU2_IPCMISC_ERRINT_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCMISC_ERRINT_Msk) >> IPC_REGS_CPU2_IPCMISC_ERRINT_Pos) /*!< ERRINT Get Value */

#define IPC_REGS_CPU2_IPCMISC_MISC_Pos (16U)                                     /*!< MISC Position  16         */
#define IPC_REGS_CPU2_IPCMISC_MISC_Msk (0xffU << IPC_REGS_CPU2_IPCMISC_MISC_Pos) /*!< MISC Mask      0x00FF0000 */
#define IPC_REGS_CPU2_IPCMISC_MISC_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCMISC_MISC_Pos) & IPC_REGS_CPU2_IPCMISC_MISC_Msk) /*!< MISC Set Value */
#define IPC_REGS_CPU2_IPCMISC_MISC_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCMISC_MISC_Msk) >> IPC_REGS_CPU2_IPCMISC_MISC_Pos) /*!< MISC Get Value */

#define IPC_REGS_CPU2_IPCMISC_TEST1_Pos (15U)                                     /*!< TEST1 Position  15         */
#define IPC_REGS_CPU2_IPCMISC_TEST1_Msk (0x1U << IPC_REGS_CPU2_IPCMISC_TEST1_Pos) /*!< TEST1 Mask      0x00008000 */
#define IPC_REGS_CPU2_IPCMISC_TEST1_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCMISC_TEST1_Pos) & IPC_REGS_CPU2_IPCMISC_TEST1_Msk) /*!< TEST1 Set Value */
#define IPC_REGS_CPU2_IPCMISC_TEST1_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCMISC_TEST1_Msk) >> IPC_REGS_CPU2_IPCMISC_TEST1_Pos) /*!< TEST1 Get Value */

#define IPC_REGS_CPU2_IPCMISC_ME_Pos (14U)                                  /*!< ME Position  14         */
#define IPC_REGS_CPU2_IPCMISC_ME_Msk (0x1U << IPC_REGS_CPU2_IPCMISC_ME_Pos) /*!< ME Mask      0x00004000 */
#define IPC_REGS_CPU2_IPCMISC_ME_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCMISC_ME_Pos) & IPC_REGS_CPU2_IPCMISC_ME_Msk) /*!< ME Set Value            */
#define IPC_REGS_CPU2_IPCMISC_ME_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCMISC_ME_Msk) >> IPC_REGS_CPU2_IPCMISC_ME_Pos) /*!< ME Get Value            */

#define IPC_REGS_CPU2_IPCMISC_RME_Pos (13U)                                   /*!< RME Position  13         */
#define IPC_REGS_CPU2_IPCMISC_RME_Msk (0x1U << IPC_REGS_CPU2_IPCMISC_RME_Pos) /*!< RME Mask      0x00002000 */
#define IPC_REGS_CPU2_IPCMISC_RME_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCMISC_RME_Pos) & IPC_REGS_CPU2_IPCMISC_RME_Msk) /*!< RME Set Value */
#define IPC_REGS_CPU2_IPCMISC_RME_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCMISC_RME_Msk) >> IPC_REGS_CPU2_IPCMISC_RME_Pos) /*!< RME Get Value            */

#define IPC_REGS_CPU2_IPCMISC_RM_Pos (9U)                                   /*!< RM Position  9          */
#define IPC_REGS_CPU2_IPCMISC_RM_Msk (0xfU << IPC_REGS_CPU2_IPCMISC_RM_Pos) /*!< RM Mask      0x00001E00 */
#define IPC_REGS_CPU2_IPCMISC_RM_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCMISC_RM_Pos) & IPC_REGS_CPU2_IPCMISC_RM_Msk) /*!< RM Set Value            */
#define IPC_REGS_CPU2_IPCMISC_RM_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCMISC_RM_Msk) >> IPC_REGS_CPU2_IPCMISC_RM_Pos) /*!< RM Get Value            */

#define IPC_REGS_CPU2_IPCMISC_RA_Pos (7U)                                   /*!< RA Position  7          */
#define IPC_REGS_CPU2_IPCMISC_RA_Msk (0x3U << IPC_REGS_CPU2_IPCMISC_RA_Pos) /*!< RA Mask      0x00000180 */
#define IPC_REGS_CPU2_IPCMISC_RA_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCMISC_RA_Pos) & IPC_REGS_CPU2_IPCMISC_RA_Msk) /*!< RA Set Value            */
#define IPC_REGS_CPU2_IPCMISC_RA_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCMISC_RA_Msk) >> IPC_REGS_CPU2_IPCMISC_RA_Pos) /*!< RA Get Value            */

#define IPC_REGS_CPU2_IPCMISC_WA_Pos (4U)                                   /*!< WA Position  4          */
#define IPC_REGS_CPU2_IPCMISC_WA_Msk (0x7U << IPC_REGS_CPU2_IPCMISC_WA_Pos) /*!< WA Mask      0x00000070 */
#define IPC_REGS_CPU2_IPCMISC_WA_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCMISC_WA_Pos) & IPC_REGS_CPU2_IPCMISC_WA_Msk) /*!< WA Set Value            */
#define IPC_REGS_CPU2_IPCMISC_WA_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCMISC_WA_Msk) >> IPC_REGS_CPU2_IPCMISC_WA_Pos) /*!< WA Get Value            */

#define IPC_REGS_CPU2_IPCMISC_WPULSE_Pos (1U) /*!< WPULSE Position  1          */
#define IPC_REGS_CPU2_IPCMISC_WPULSE_Msk                                        \
    (0x7U << IPC_REGS_CPU2_IPCMISC_WPULSE_Pos) /*!< WPULSE Mask      0x0000000E \
                                                */
#define IPC_REGS_CPU2_IPCMISC_WPULSE_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCMISC_WPULSE_Pos) & IPC_REGS_CPU2_IPCMISC_WPULSE_Msk) /*!< WPULSE Set Value */
#define IPC_REGS_CPU2_IPCMISC_WPULSE_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCMISC_WPULSE_Msk) >> IPC_REGS_CPU2_IPCMISC_WPULSE_Pos) /*!< WPULSE Get Value */

#define IPC_REGS_CPU2_IPCMISC_LS_Pos (0U)                                   /*!< LS Position  0          */
#define IPC_REGS_CPU2_IPCMISC_LS_Msk (0x1U << IPC_REGS_CPU2_IPCMISC_LS_Pos) /*!< LS Mask      0x00000001 */
#define IPC_REGS_CPU2_IPCMISC_LS_Set(x) \
    (((uint32_t)(x) << IPC_REGS_CPU2_IPCMISC_LS_Pos) & IPC_REGS_CPU2_IPCMISC_LS_Msk) /*!< LS Set Value            */
#define IPC_REGS_CPU2_IPCMISC_LS_Get(x) \
    (((uint32_t)(x)&IPC_REGS_CPU2_IPCMISC_LS_Msk) >> IPC_REGS_CPU2_IPCMISC_LS_Pos) /*!< LS Get Value            */

/*!
 * @}
 */

/*!
 * @}
 */ /* end of HS32F7D377_IPC_CPU2_REGISTER */

#endif /* HS32F7D377_IPC_CPU2_H */
