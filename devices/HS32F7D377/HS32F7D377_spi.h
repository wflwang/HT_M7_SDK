/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


/*!
 * \file   HS32F7D377_spi.h
 * \brief  HS32F7D377 SPI register file
 * \version V1.0_20230713
 */

#ifndef HS32F7D377_SPI_H
#define HS32F7D377_SPI_H

/*!
 * \addtogroup   HS32F7D377_SPI_REGISTER HS32F7D377 SPI Register
 * \ingroup HS32F7D377_REGISTER
 *
 * \brief  SPI register layout, bitfield and address definitions
 *
 * @{
 */

/* clang-format off */

/*!
 * \name SPI Register Layout
 *
 *
 * @{
 */

/*! \brief SPI register */
typedef struct {
    union
    {
        __IOM uint32_t CTRLR0                            ;  /*!< 0x00000000 : Control Register 0 */

        struct
        {
            __IOM uint32_t DFS                       : 5 ;  /*!< [ 4: 0] : Data Frame Size.
                                                                           Selects the data frame length. When the data frame size is programmed to be less than 32 bits, the receive data is automatically right-justified by the receive logic, with the upper bits of the receive FIFO zero-padded.
                                                                           You must right-justify transmit data before writing into the transmit FIFO. The transmit logic ignores the upper unused bits when transmitting the data.
                                                                           
                                                                           Values:
                                                                           0x0 (DFS_01_BIT): Reserved
                                                                           0x1 (DFS_02_BIT): Reserved
                                                                           0x2 (DFS_03_BIT): Reserved
                                                                           0x3 (DFS_04_BIT): 04-bit serial data transfer
                                                                           0x4 (DFS_05_BIT): 05-bit serial data transfer
                                                                           0x5 (DFS_06_BIT): 06-bit serial data transfer
                                                                           0x6 (DFS_07_BIT): 07-bit serial data transfer
                                                                           0x7 (DFS_08_BIT): 08-bit serial data transfer
                                                                           0x8 (DFS_09_BIT): 09-bit serial data transfer
                                                                           0x9 (DFS_10_BIT): 10-bit serial data transfer
                                                                           0xa (DFS_11_BIT): 11-bit serial data transfer
                                                                           0xb (DFS_12_BIT): 12-bit serial data transfer
                                                                           0xc (DFS_13_BIT): 13-bit serial data transfer
                                                                           0xd (DFS_14_BIT): 14-bit serial data transfer
                                                                           0xe (DFS_15_BIT): 15-bit serial data transfer
                                                                           0xf (DFS_16_BIT): 16-bit serial data transfer
                                                                           0x10 (DFS_17_BIT): 17-bit serial data transfer
                                                                           0x11 (DFS_18_BIT): 18-bit serial data transfer
                                                                           0x12 (DFS_19_BIT): 19-bit serial data transfer
                                                                           0x13 (DFS_20_BIT): 20-bit serial data transfer
                                                                           0x14 (DFS_21_BIT): 21-bit serial data transfer
                                                                           0x15 (DFS_22_BIT): 22-bit serial data transfer
                                                                           0x16 (DFS_23_BIT): 23-bit serial data transfer
                                                                           0x17 (DFS_24_BIT): 24-bit serial data transfer
                                                                           0x18 (DFS_25_BIT): 25-bit serial data transfer
                                                                           0x19 (DFS_26_BIT): 26-bit serial data transfer
                                                                           0x1a (DFS_27_BIT): 27-bit serial data transfer
                                                                           0x1b (DFS_28_BIT): 28-bit serial data transfer
                                                                           0x1c (DFS_29_BIT): 29-bit serial data transfer
                                                                           0x1d (DFS_30_BIT): 30-bit serial data transfer
                                                                           0x1e (DFS_31_BIT): 31-bit serial data transfer
                                                                           0x1f (DFS_32_BIT): 32-bit serial data transfer */
                  uint32_t RSV_0                     : 1 ;  /*!< [ 5: 5] : reserved. */
            __IOM uint32_t FRF                       : 2 ;  /*!< [ 7: 6] : Frame Format.
                                                                           Selects which serial protocol transfers the data.
                                                                           Values:
                                                                           0x0 (SPI): Motorola SPI Frame Format
                                                                           0x1 (SSP): Texas Instruments SSP Frame Format
                                                                           0x2 (RESERVED): Reserved
                                                                           0x3 (RESERVED): Reserved */
            __IOM uint32_t SCPH                      : 1 ;  /*!< [ 8: 8] : Serial Clock Phase.
                                                                           Valid when the frame format (FRF) is set to Motorola SPI. The serial clock phase selects the relationship of the serial clock with the slave select signal.
                                                                           When SCPH = 0, data are captured on the first edge of the serial clock. When SCPH = 1, the serial clock starts toggling one cycle after the slave select line is activated, and data are captured on the second edge of the serial clock.
                                                                           Values:
                                                                           0x1 (START_BIT): Serial clock toggles at start of first bit
                                                                           0x0 (MIDDLE_BIT): Serial clock toggles in middle of first bit */
            __IOM uint32_t SCPOL                     : 1 ;  /*!< [ 9: 9] : Serial Clock Polarity.
                                                                           Valid when the frame format (FRF) is set to Motorola SPI. Used to select the polarity of the inactive serial clock, which is held inactive when the SPI master is not actively transferring data on the serial bus.
                                                                           Values:
                                                                           0x0 (INACTIVE_HIGH): Inactive state of serial clock is low
                                                                           0x1 (INACTIVE_LOW): Inactive state of serial clock is high */
            __IOM uint32_t TMOD                      : 2 ;  /*!< [11:10] : Transfer Mode.
                                                                           Selects the mode of transfer for serial communication. This field does not affect the transfer duplicity. Only indicates whether the receive or transmit data are valid.
                                                                           In transmit-only mode, data received from the external device is not valid and is not stored in the receive FIFO memory; it is overwritten on the next transfer.
                                                                           In receive-only mode, transmitted data are not valid. After the first write to the transmit FIFO, the same word is retransmitted for the duration of the transfer.
                                                                           In transmit-and-receive mode, both transmit and receive data are valid. The transfer continues until the transmit FIFO is empty. Data received from the external device are stored into the receive FIFO memory, where it can be accessed by the host processor.
                                                                           Values:
                                                                           0x0 (TX_AND_RX): Transmit & Receive; Not Applicable in enhanced SPI operating mode or when SPIC_HAS_TX-
                                                                           _RX_EN is set to 0
                                                                           0x1 (TX_ONLY): Transmit only mode; Or Write in enhanced SPI operating mode
                                                                           0x2 (RX_ONLY): Receive only mode; Or Read in enhanced SPI operating mode
                                                                           0x3 (EEPROM_READ): EEPROM Read mode; Not Appli- cable in enhanced SPI operating mode */
            __IOM uint32_t SLV_OE                    : 1 ;  /*!< [12:12] : Slave Output Enable.
                                                                           Relevant only when the SPI is configured as a
                                                                           serial-slave device. When configured as a serial master, this bit field has no functionality. This bit enables or disables the setting of the SPI_oe_n output from the SPI serial slave. When SLV_OE = 1, the SPI_oe_n output can never be active. When the SPI_oe_n output controls the tri-state buffer on the txd output from the slave, a high impedance state is always present on the slave txd output when SLV_OE = 1.
                                                                           This is useful when the master transmits in broadcast mode (master transmits data to all slave devices). Only one slave may respond with data on the master rxd line. This bit is enabled after reset and must be disabled by software (when broadcast mode is used), if you do not want this device to respond with data.
                                                                           When SPIC_SLV_SPI_MODE is set to 1 and SPI is programmed to work in Enhanced SPI mode, then for correct operation this bit should be programmed to 0.
                                                                           Values:
                                                                           0x1 (DISABLED): Slave Output is disabled
                                                                           0x0 (ENABLED): Slave Output is enabled */
            __IOM uint32_t SRL                       : 1 ;  /*!< [13:13] : Shift Register Loop.
                                                                           Used for testing purposes only. When internally active, connects the transmit shift register output to the receive shift register input. Can be used in both serial-slave and
                                                                           serial-master modes. When the SPI is configured as a slave in loopback mode, the ss_in_n and SPI_clk signals must be provided by an external source. In this mode, the slave cannot generate these signals because there is nothing to which to loop back.
                                                                           Values:
                                                                           0x1 (TESTING_MODE): Test Mode Operation
                                                                           0x0 (NORMAL_MODE): Normal mode operation */
            __IOM uint32_t SSTE                      : 1 ;  /*!< [14:14] : Slave Select Toggle Enable.
                                                                           While operating in SPI mode with clock phase (SCPH) set to 0, this register controls the behavior of the slave select line (ss_*_n) between data frames.
                                                                           Values:
                                                                           0x1 (TOGGLE_EN): ss_*_n line will toggle between consecutive data frames, with the serial clock (sclk) being held to its default value while ss_*_n is high
                                                                           0x0 (TOGGLE_DISABLE): ss_*_n will stay low and sclk will run continuously for the duration of the transfer */
                  uint32_t RSV_1                     : 1 ;  /*!< [15:15] : reserved. */
            __IOM uint32_t CFS                       : 4 ;  /*!< [19:16] : Control Frame Size.
                                                                           Selects the length of the control word for the Microwire frame format.
                                                                           Values:
                                                                           0x0 (SIZE_01_BIT): 01-bit Control Word
                                                                           0x1 (SIZE_02_BIT): 02-bit Control Word
                                                                           0x2 (SIZE_03_BIT): 03-bit Control Word
                                                                           0x3 (SIZE_04_BIT): 04-bit Control Word
                                                                           0x4 (SIZE_05_BIT): 05-bit Control Word
                                                                           0x5 (SIZE_06_BIT): 06-bit Control Word
                                                                           0x6 (SIZE_07_BIT): 07-bit Control Word
                                                                           0x7 (SIZE_08_BIT): 08-bit Control Word
                                                                           0x8 (SIZE_09_BIT): 09-bit Control Word
                                                                           0x9 (SIZE_10_BIT): 10-bit Control Word
                                                                           0xa (SIZE_11_BIT): 11-bit Control Word
                                                                           0xb (SIZE_12_BIT): 12-bit Control Word
                                                                           0xc (SIZE_13_BIT): 13-bit Control Word
                                                                           0xd (SIZE_14_BIT): 14-bit Control Word
                                                                           0xe (SIZE_15_BIT): 15-bit Control Word
                                                                           0xf (SIZE_16_BIT): 16-bit Control Word Value */
                  uint32_t RSV_2                     : 2 ;  /*!< [21:20] : reserved. */
            __IOM uint32_t SPI_FRF                   : 2 ;  /*!< [23:22] : SPI Frame Format
                                                                           Selects data frame format for Transmitting/Receiving the data. Bits only valid when SPIC_SPI_MODE is either set to "Dual" or "Quad" or "Octal" mode.
                                                                           Values:
                                                                           0x0 (SPI_STANDARD): Standard SPI Format
                                                                           0x1 (SPI_DUAL): Dual SPI Format
                                                                           0x2 : reserved
                                                                           0x3 : reserved */
            __IM  uint32_t SPI_HYPERBUS_EN           : 1 ;  /*!< [24:24] : SPI Hyperbus Frame format enable.
                                                                           Selects if data frame format for Transmitting/Receiving the data is in Hyperbus mode. This field is effective only when CTRLRO.FRF is set to SPI frame format.
                                                                           Values:
                                                                           0x0 (DISABLE): Disable Hyperbus Format
                                                                           0x1 (ENABLE): Enable Hyperbus Format Value After Reset: SPIC_DFLT_HYPERBUS_EN Exists: Always */
            __IM  uint32_t SPI_DWS_EN                : 1 ;  /*!< [25:25] : Enable Dynamic wait states in SPI mode of operation. This field is only applicable when CTRLR0.FRF is set to 0 (Motorola SPI Frame Format).
                                                                           Values:
                                                                           0x0 (DISABLE): Disable SPI Dynamic Wait State
                                                                           0x1 (ENABLE): Enable SPI Dynamic Wait State */
                  uint32_t RSV_3                     : 5 ;  /*!< [30:26] : reserved. */
            __IOM uint32_t SPI_IS_MST                : 1 ;  /*!< [31:31] : This field selects if SPI is working in Master or Slave mode
                                                                           Values:
                                                                           0x1 (MASTER): SPI is Master
                                                                           0x0 (SLAVE): SPI is Slave */
        } CTRLR0b;
    };

    union
    {
        __IOM uint32_t CTRLR1                            ;  /*!< 0x00000004 : Control Register 1 */

        struct
        {
            __IOM uint32_t NDF                       : 15;  /*!< [15: 0] : Number of Data Frames.
                                                                           When TMOD = 10 or TMOD = 11 , this register field sets the number of data frames to be continuously received by the SPI. The SPI continues to receive serial data until the number of data frames received is equal to this register value plus 1, which enables you to receive up to 64 KB of data in a continuous transfer.
                                                                           When SPI_CTRLR0.CLK_STRETCH_EN=1 and TMOD = 01,
                                                                           this register field sets the number of data frames to be continously transmitted by SPI. If the Transmit FIFO goes empty in-between, SPI masks the serial clock (sclk_out) and wait for rest of the data until the programmed amount of frames are transferred successfully.
                                                                           When the SPI is configured as a serial slave, the transfer continues for as long as the slave is selected. Therefore, this register serves no purpose and is not present when the SPI is configured as a serial slave. */
                  uint32_t RSV_1                     : 16;  /*!< [31:16] : reserved. */
        } CTRLR1b;
    };

    union
    {
        __IOM uint32_t SPIENR                            ;  /*!< 0x00000008 : SPI Enable Register */

        struct
        {
            __IOM uint32_t SPIC_EN                   : 1 ;  /*!< [ 0: 0] : SPI Enable.
                                                                           Enables and disables all SPI operations. When disabled, all serial transfers are halted immediately. Transmit and receive FIFO buffers are cleared when the device is disabled. It is impoSPIble to program some of the SPI control registers when enabled. When disabled, the SPI sleep output is set (after delay) to inform the system that it is safe to remove the ssi_clk, thus saving power consumption in the system.
                                                                           Values:
                                                                           0x1 (ENABLED): Enables SPI
                                                                           0x0 (DISABLE): Disables SPI Value */
                  uint32_t RSV_0                     : 31;  /*!< [31: 1] : reserved. */
        } SPIENRb;
    };

    union
    {
        __IOM uint32_t MWCR                              ;  /*!< 0x0000000c : Microwire Control Register */

        struct
        {
                  uint32_t RSV_0                     : 1 ;  /*!< [ 0: 0] : reserved. */
                  uint32_t RSV_1                     : 1 ;  /*!< [ 1: 1] : reserved. */
                  uint32_t RSV_2                     : 1 ;  /*!< [ 2: 2] : reserved. */
                  uint32_t RSV_3                     : 29;  /*!< [31: 3] : reserved. */
        } MWCRb;
    };

    union
    {
        __IOM uint32_t SER                               ;  /*!< 0x00000010 : Slave Enable Register */

        struct
        {
            __IOM uint32_t SER                       : 1 ;  /*!< [ 0: 0] : Slave Select Enable Flag.
                                                                           Each bit in this register corresponds to a slave select line (ss_x_n) from the SPI master. When a bit in this register is set (1), the corresponding slave select line from the master is activated when a serial transfer begins. It should be noted that setting or clearing bits in this register have no effect on the corresponding slave select outputs until a transfer is started. Before beginning a transfer, you should enable the bit in this register that corresponds to the slave device with which the master wants to communicate. When not operating in broadcast mode, only one bit in this field should be set. */
                  uint32_t RSV_0                     : 31;  /*!< [31: 1] : reserved. */
        } SERb;
    };

    union
    {
        __IOM uint32_t BAUDR                             ;  /*!< 0x00000014 : Baud Rate Select */

        struct
        {
                  uint32_t RSV_0                     : 1 ;  /*!< [ 0: 0] : reserved. */
            __IOM uint32_t SCKDV                     : 15;  /*!< [15: 1] : SPI Clock Divider.
                                                                           The LSB for this field is always set to 0 and is unaffected by a write operation, which ensures an even value is held in this register. If the value is 0, the serial output clock (sclk_out) is disabled. The frequency of the sclk_out is derived from the following equation:
                                                                           
                                                                           Fsclk_out = FSPI_clk/BAUDR
                                                                           where BAUDR is any even value between 2 and 65534 (BAUDR = {SCKDV*2}).
                                                                           For example: for FSPI_clk = 3.6864MHz and BAUDR =2 Fsclk_out = 3.6864/2 =
                                                                           1.8432MHz */
                  uint32_t RSV_1                     : 16;  /*!< [31:16] : reserved. */
        } BAUDRb;
    };

    union
    {
        __IOM uint32_t TXFTLR                            ;  /*!< 0x00000018 : Transmit FIFO Threshold Level */

        struct
        {
            __IOM uint32_t TFT                       : 5 ;  /*!< [ 4: 0] : Transmit FIFO Threshold.
                                                                           Controls the level of entries (or below) at which the transmit FIFO controller triggers an interrupt. The FIFO depth is configurable in the range 8-256; this register is sized to the number of address bits needed to access the FIFO. If you attempt to set this value greater than or equal to the depth of the FIFO, this field is not written and retains its current value. When the number of transmit FIFO entries is less than or equal to this value, the transmit FIFO empty interrupt is triggered. */
                  uint32_t RSV_0                     : 11;  /*!< [15: 5] : reserved. */
            __IOM uint32_t TXFTHR                    : 5 ;  /*!< [20:16] : Transfer start FIFO level.
                                                                           Used to control the level of entries in transmit FIFO above which transfer will start on serial line. This register can be used to ensure that sufficient data is present in transmit FIFO before starting a write operation on serial line.
                                                                           This field is valid only for Master mode of operation. */
                  uint32_t RSV_1                     : 11;  /*!< [31:21] : reserved. */
        } TXFTLRb;
    };

    union
    {
        __IOM uint32_t RXFTLR                            ;  /*!< 0x0000001c : Receive FIFO Threshold Level */

        struct
        {
            __IOM uint32_t RFT                       : 8 ;  /*!< [ 7: 0] : Receive FIFO Threshold.
                                                                           Controls the level of entries (or above) at which the receive FIFO controller triggers an interrupt. The FIFO depth is configurable in the range 8-256. This register is sized to the number of address bits needed to access the FIFO. If you attempt to set this value greater than the depth of the FIFO, this field is not written and retains its current value. When the number of receive FIFO entries is greater than or equal to this value + 1, the receive FIFO full interrupt is triggered. */
                  uint32_t RSV_0                     : 24;  /*!< [31: 8] : reserved. */
        } RXFTLRb;
    };

    union
    {
        __IM  uint32_t TXFLR                             ;  /*!< 0x00000020 : Transmit FIFO Level Register */

        struct
        {
            __IM  uint32_t TXTFL                     : 5 ;  /*!< [ 4: 0] : Transmit FIFO Level.
                                                                           Contains the number of valid data entries in the transmit FIFO. */
                  uint32_t RSV_0                     : 27;  /*!< [31: 5] : reserved. */
        } TXFLRb;
    };

    union
    {
        __IM  uint32_t RXFLR                             ;  /*!< 0x00000024 : Receive FIFO Level Register */

        struct
        {
            __IM  uint32_t RXTFL                     : 8 ;  /*!< [ 7: 0] : Receive FIFO Level.
                                                                           Contains the number of valid data entries in the receive FIFO. */
                  uint32_t RSV_0                     : 24;  /*!< [31: 8] : reserved. */
        } RXFLRb;
    };

    union
    {
        __IM  uint32_t SR                                ;  /*!< 0x00000028 : Status Register */

        struct
        {
            __IM  uint32_t BUSY                      : 1 ;  /*!< [ 0: 0] : SPI Busy Flag.
                                                                           When set, indicates that a serial transfer is in progress; when cleared indicates that the SPI is idle or disabled.
                                                                           Values:
                                                                           0x1 (ACTIVE): SPI is actively transferring data
                                                                           0x0 (INACTIVE): SPI is idle or disabled */
            __IM  uint32_t TFNF                      : 1 ;  /*!< [ 1: 1] : Transmit FIFO Not Full.
                                                                           Set when the transmit FIFO contains one or more empty locations, and is cleared when the FIFO is full.
                                                                           Values:
                                                                           0x1 (NOT_FULL): Tx FIFO is not Full
                                                                           0x0 (FULL): Tx FIFO is full */
            __IM  uint32_t TFE                       : 1 ;  /*!< [ 2: 2] : Transmit FIFO Empty.
                                                                           When the transmit FIFO is completely empty, this bit is set. When the transmit FIFO contains one or more valid entries, this bit is cleared. This bit field does not request an interrupt. Values:
                                                                           0x1 (EMPTY): Transmit FIFO is empty
                                                                           0x0 (NOT_EMPTY): Transmit FIFO is not empty */
            __IM  uint32_t RFNE                      : 1 ;  /*!< [ 3: 3] : Receive FIFO Not Empty.
                                                                           Set when the receive FIFO contains one or more entries and is cleared when the receive FIFO is empty. This bit can be polled by software to completely empty the receive FIFO.
                                                                           Values:
                                                                           0x1 (NOT_EMPTY): Receive FIFO is not empty
                                                                           0x0 (EMPTY): Receive FIFO is empty */
            __IM  uint32_t RFF                       : 1 ;  /*!< [ 4: 4] : Receive FIFO Full.
                                                                           When the receive FIFO is completely full, this bit is set. When the receive FIFO contains one or more empty location, this bit is cleared.
                                                                           Values:
                                                                           0x1 (FULL): Receive FIFO is full
                                                                           0x0 (NOT_FULL): Receive FIFO is not full */
            __IM  uint32_t TXE                       : 1 ;  /*!< [ 5: 5] : TransmiSPIon Error.
                                                                           Set if the transmit FIFO is empty when a transfer is started. This bit can be set only when the SPI is configured as a slave device. Data from the previous transmiSPIon is resent on the txd line. This bit is cleared when read.
                                                                           Values:
                                                                           0x1 (TX_ERROR): TransmiSPIon Error
                                                                           0x0 (NO_ERROR): No Error */
                  uint32_t RSV_0                     : 1 ;  /*!< [ 6: 6] : reserved. */
                  uint32_t RSV_1                     : 8 ;  /*!< [14: 7] : reserved. */
                  uint32_t RSV_2                     : 17;  /*!< [31:15] : reserved. */
        } SRb;
    };

    union
    {
        __IOM uint32_t IMR                               ;  /*!< 0x0000002c : Interrupt Mask Register */

        struct
        {
            __IOM uint32_t TXEIM                     : 1 ;  /*!< [ 0: 0] : Transmit FIFO Empty Interrupt Mask
                                                                           Values:
                                                                           0x1 (UNMASKED): ssi_txe_intr interrupt is not masked
                                                                           0x0 (MASKED): ssi_txe_intr interrupt is masked */
            __IOM uint32_t TXOIM                     : 1 ;  /*!< [ 1: 1] : Transmit FIFO Overflow Interrupt Mask
                                                                           Values:
                                                                           0x1 (UNMASKED): ssi_txo_intr interrupt is not masked
                                                                           0x0 (MASKED): ssi_txo_intr interrupt is masked */
            __IOM uint32_t RXUIM                     : 1 ;  /*!< [ 2: 2] : Receive FIFO Underflow Interrupt Mask
                                                                           Values:
                                                                           0x1 (UNMASKED): ssi_rxu_intr interrupt is not masked
                                                                           0x0 (MASKED): ssi_rxu_intr interrupt is masked */
            __IOM uint32_t RXOIM                     : 1 ;  /*!< [ 3: 3] : Receive FIFO Overflow Interrupt Mask
                                                                           Values:
                                                                           0x1 (UNMASKED): ssi_rxo_intr interrupt is not masked
                                                                           0x0 (MASKED): ssi_rxo_intr interrupt is masked */
            __IOM uint32_t RXFIM                     : 1 ;  /*!< [ 4: 4] : Receive FIFO Full Interrupt Mask 0 - ssi_rxf_intr interrupt is masked 1 - ssi_rxf_intr interrupt is not masked
                                                                           Values:
                                                                           0x1 (UNMASKED): ssi_rxf_intr interrupt is not masked
                                                                           0x0 (MASKED): ssi_rxf_intr interrupt is masked */
            __IOM uint32_t MSTIM                     : 1 ;  /*!< [ 5: 5] : Multi-Master Contention Interrupt Mask. This bit field is not present if the SPI is configured as a serial-master device. Values:
                                                                           0x1 (UNMASKED): ssi_mst_intr interrupt is not masked
                                                                           0x0 (MASKED): ssi_mst_intr interrupt is masked */
            __IM  uint32_t XRXOIM                    : 1 ;  /*!< [ 6: 6] : XIP Receive FIFO Overflow Interrupt Mask
                                                                           Values:
                                                                           0x1 (UNMASKED): ssi_xrxo_intr interrupt is not masked
                                                                           0x0 (MASKED): ssi_xrxo_intr interrupt is masked */
            __IOM uint32_t TXUIM                     : 1 ;  /*!< [ 7: 7] : Transmit FIFO Underflow Interrupt Mask
                                                                           Values:
                                                                           0x1 (UNMASKED): ssi_txu_intr interrupt is not masked
                                                                           0x0 (MASKED): ssi_txu_intr interrupt is masked */
                  uint32_t RSV_0                     : 1 ;  /*!< [ 8: 8] : reserved. */
                  uint32_t RSV_1                     : 1 ;  /*!< [ 9: 9] : reserved. */
                  uint32_t RSV_2                     : 1 ;  /*!< [10:10] : reserved. */
                  uint32_t RSV_3                     : 1 ;  /*!< [11:11] : reserved. */
                  uint32_t RSV_4                     : 20;  /*!< [31:12] : reserved. */
        } IMRb;
    };

    union
    {
        __IM  uint32_t ISR                               ;  /*!< 0x00000030 : Interrupt Status Register */

        struct
        {
            __IM  uint32_t TXEIS                     : 1 ;  /*!< [ 0: 0] : Transmit FIFO Empty Interrupt Status
                                                                           Values:
                                                                           0x1 (ACTIVE): ssi_txe_intr interrupt is active after masking
                                                                           0x0 (INACTIVE): ssi_txe_intr interrupt is not active after masking */
            __IM  uint32_t TXOIS                     : 1 ;  /*!< [ 1: 1] : Transmit FIFO Overflow Interrupt Status
                                                                           Values:
                                                                           0x1 (ACTIVE): ssi_txo_intr interrupt is active after masking
                                                                           0x0 (INACTIVE): ssi_txo_intr interrupt is not active after masking */
            __IM  uint32_t RXUIS                     : 1 ;  /*!< [ 2: 2] : Receive FIFO Underflow Interrupt Status
                                                                           Values:
                                                                           0x1 (ACTIVE): ssi_rxu_intr interrupt is active after masking
                                                                           0x0 (INACTIVE): ssi_rxu_intr interrupt is not active after masking */
            __IM  uint32_t RXOIS                     : 1 ;  /*!< [ 3: 3] : Receive FIFO Overflow Interrupt Status
                                                                           Values:
                                                                           0x1 (ACTIVE): ssi_rxo_intr interrupt is active after masking
                                                                           0x0 (INACTIVE): ssi_rxo_intr interrupt is not active after masking */
            __IM  uint32_t RXFIS                     : 1 ;  /*!< [ 4: 4] : Receive FIFO Full Interrupt Status
                                                                           Values:
                                                                           0x1 (ACTIVE): ssi_rxf_intr interrupt is active after masking
                                                                           0x0 (INACTIVE): ssi_rxf_intr interrupt is not active after masking */
            __IM  uint32_t MSTIS                     : 1 ;  /*!< [ 5: 5] : Multi-Master Contention Interrupt Status. This bit field is not present if the SPI is configured as a serial-slave device. Values:
                                                                           0x1 (ACTIVE): ssi_mst_intr interrupt is active after masking
                                                                           0x0 (INACTIVE): ssi_mst_intr interrupt is not active after masking */
            __IM  uint32_t XRXOIS                    : 1 ;  /*!< [ 6: 6] : XIP Receive FIFO Overflow Interrupt Status
                                                                           Values:
                                                                           0x1 (ACTIVE): ssi_xrxo_intr interrupt is active after masking
                                                                           0x0 (INACTIVE): ssi_xrxo_intr interrupt is not active after masking */
            __IM  uint32_t TXUIS                     : 1 ;  /*!< [ 7: 7] : Transmit FIFO Underflow Interrupt Status
                                                                           Values:
                                                                           0x1 (ACTIVE): ssi_txu_intr interrupt is active after masking
                                                                           0x0 (INACTIVE): ssi_txu_intr interrupt is not active after masking */
                  uint32_t RSV_0                     : 1 ;  /*!< [ 8: 8] : reserved. */
                  uint32_t RSV_1                     : 1 ;  /*!< [ 9: 9] : reserved. */
                  uint32_t RSV_2                     : 1 ;  /*!< [10:10] : reserved. */
                  uint32_t RSV_3                     : 1 ;  /*!< [11:11] : reserved. */
                  uint32_t RSV_4                     : 20;  /*!< [31:12] : reserved. */
        } ISRb;
    };

    union
    {
        __IM  uint32_t RISR                              ;  /*!< 0x00000034 : Raw Interrupt Status Register */

        struct
        {
            __IM  uint32_t TXEIR                     : 1 ;  /*!< [ 0: 0] : Transmit FIFO Empty Raw Interrupt Status
                                                                           Values:
                                                                           0x1 (ACTIVE): SPI_txe_intr interrupt is active prior to masking
                                                                           0x0 (INACTIVE): SPI_txe_intr interrupt is not active prior masking */
            __IM  uint32_t TXOIR                     : 1 ;  /*!< [ 1: 1] : Transmit FIFO Overflow Raw Interrupt Status
                                                                           Values:
                                                                           0x1 (ACTIVE): SPI_txo_intr interrupt is active prior to masking
                                                                           0x0 (INACTIVE): SPI_txo_intr interrupt is not active prior masking */
            __IM  uint32_t RXUIR                     : 1 ;  /*!< [ 2: 2] : Receive FIFO Underflow Raw Interrupt Status
                                                                           Values:
                                                                           0x1 (ACTIVE): SPI_rxu_intr interrupt is active prior to masking
                                                                           0x0 (INACTIVE): SPI_rxu_intr interrupt is not active prior masking */
            __IM  uint32_t RXOIR                     : 1 ;  /*!< [ 3: 3] : Receive FIFO Overflow Raw Interrupt Status
                                                                           Values:
                                                                           0x1 (ACTIVE): SPI_rxo_intr interrupt is active prior to masking
                                                                           0x0 (INACTIVE): SPI_rxo_intr interrupt is not active prior masking */
            __IM  uint32_t RXFIR                     : 1 ;  /*!< [ 4: 4] : Receive FIFO Full Raw Interrupt Status
                                                                           Values:
                                                                           0x1 (ACTIVE): SPI_rxf_intr interrupt is active prior to masking
                                                                           0x0 (INACTIVE): SPI_rxf_intr interrupt is not active prior masking */
            __IM  uint32_t MSTIR                     : 1 ;  /*!< [ 5: 5] : Multi-Master Contention Raw Interrupt Status. This bit field is not present if the SPI is configured as a serial-slave device.
                                                                           Values:
                                                                           0x1 (ACTIVE): SPI_mst_intr interrupt is active prior to masking
                                                                           0x0 (INACTIVE): SPI_mst_intr interrupt is not active prior masking */
            __IM  uint32_t XRXOIR                    : 1 ;  /*!< [ 6: 6] : XIP Receive FIFO Overflow Raw Interrupt Status
                                                                           Values:
                                                                           0x1 (ACTIVE): SPI_xrxo_intr interrupt is active prior to masking
                                                                           0x0 (INACTIVE): SPI_xrxo_intr interrupt is not active prior masking */
            __IM  uint32_t TXUIR                     : 1 ;  /*!< [ 7: 7] : Transmit FIFO Underflow Interrupt Raw Status
                                                                           Values:
                                                                           0x1 (ACTIVE): SPI_txu_intr interrupt is active prior to masking
                                                                           0x0 (INACTIVE): SPI_txu_intr interrupt is not active prior masking */
                  uint32_t RSV_0                     : 1 ;  /*!< [ 8: 8] : reserved. */
                  uint32_t RSV_1                     : 1 ;  /*!< [ 9: 9] : reserved. */
                  uint32_t RSV_2                     : 1 ;  /*!< [10:10] : reserved. */
                  uint32_t RSV_3                     : 1 ;  /*!< [11:11] : reserved. */
                  uint32_t RSV_4                     : 20;  /*!< [31:12] : reserved. */
        } RISRb;
    };

    union
    {
        __IM  uint32_t TXEICR                            ;  /*!< 0x00000038 : Transmit FIFO Error Interrupt Clear Registers */

        struct
        {
            __IM  uint32_t TXEICR                    : 1 ;  /*!< [ 0: 0] : Clear Transmit FIFO Overflow/Underflow Interrupt.
                                                                           This register reflects the status of the interrupt. A read from this register clears the SPI_txo_intr/SPI_txu_intr interrupt; writing has no effect. */
                  uint32_t RSV_0                     : 31;  /*!< [31: 1] : reserved. */
        } TXEICRb;
    };

    union
    {
        __IM  uint32_t RXOICR                            ;  /*!< 0x0000003c : Receive FIFO Overflow Interrupt Clear Register */

        struct
        {
            __IM  uint32_t RXOICR                    : 1 ;  /*!< [ 0: 0] : Clear Receive FIFO Overflow Interrupt.
                                                                           This register reflects the status of the interrupt. A read from this register clears the SPI_rxo_intr interrupt; writing has no effect. */
                  uint32_t RSV_0                     : 31;  /*!< [31: 1] : reserved. */
        } RXOICRb;
    };

    union
    {
        __IM  uint32_t RXUICR                            ;  /*!< 0x00000040 : Receive FIFO Underflow Interrupt Clear Register */

        struct
        {
            __IM  uint32_t RXUICR                    : 1 ;  /*!< [ 0: 0] : Clear Receive FIFO Underflow Interrupt.
                                                                           This register reflects the status of the interrupt. A read from this register clears the SPI_rxu_intr interrupt; writing has no effect. */
                  uint32_t RSV_0                     : 31;  /*!< [31: 1] : reserved. */
        } RXUICRb;
    };

    union
    {
        __IM  uint32_t MSTICR                            ;  /*!< 0x00000044 : Multi-Master Interrupt Clear Register */

        struct
        {
            __IM  uint32_t MSTICR                    : 1 ;  /*!< [ 0: 0] : Clear Multi-Master Contention Interrupt.
                                                                           This register reflects the status of the interrupt. A read from this register clears the SPI_mst_intr interrupt; writing has no effect. */
                  uint32_t RSV_0                     : 31;  /*!< [31: 1] : reserved. */
        } MSTICRb;
    };

    union
    {
        __IM  uint32_t ICR                               ;  /*!< 0x00000048 : Interrupt Clear Register */

        struct
        {
            __IM  uint32_t ICR                       : 1 ;  /*!< [ 0: 0] : Clear Interrupts.
                                                                           This register is set if any of the interrupts below are active. A read clears the SPI_txo_intr, ssi_rxu_intr, ssi_rxo_intr, and the ssi_mst_intr interrupts. Writing to this register has no effect. */
                  uint32_t RSV_0                     : 31;  /*!< [31: 1] : reserved. */
        } ICRb;
    };

    union
    {
        __IOM uint32_t DMACR                             ;  /*!< 0x0000004c : DMA Control Register */

        struct
        {
            __IOM uint32_t RDMAE                     : 1 ;  /*!< [ 0: 0] : Receive DMA Enable. This bit enables/disables the receive FIFO DMA channel.
                                                                           Values:
                                                                           0x1 (ENABLED): Receive DMA enabled
                                                                           0x0 (DISABLE): Receive DMA disabled */
            __IOM uint32_t TDMAE                     : 1 ;  /*!< [ 1: 1] : Transmit DMA Enable. This bit enables/disables the transmit FIFO DMA channel.
                                                                           Values:
                                                                           0x1 (ENABLED): Transmit DMA enabled
                                                                           0x0 (DISABLE): Transmit DMA disabled */
                  uint32_t RSV_0                     : 1 ;  /*!< [ 2: 2] : reserved. */
                  uint32_t RSV_1                     : 2 ;  /*!< [ 4: 3] : reserved. */
                  uint32_t RSV_2                     : 1 ;  /*!< [ 5: 5] : reserved. */
                  uint32_t RSV_3                     : 1 ;  /*!< [ 6: 6] : reserved. */
                  uint32_t RSV_4                     : 1 ;  /*!< [ 7: 7] : reserved. */
                  uint32_t RSV_5                     : 4 ;  /*!< [11: 8] : reserved. */
                  uint32_t RSV_6                     : 3 ;  /*!< [14:12] : reserved. */
                  uint32_t RSV_7                     : 6 ;  /*!< [20:15] : reserved. */
                  uint32_t RSV_8                     : 11;  /*!< [31:21] : reserved. */
        } DMACRb;
    };

    union
    {
        __IOM uint32_t DMATDLR                           ;  /*!< 0x00000050 : DMA Transmit Data Level */

        struct
        {
            __IOM uint32_t DMATDL                    : 5 ;  /*!< [ 4: 0] : Transmit Data Level. */
                  uint32_t RSV_0                     : 27;  /*!< [31: 5] : reserved. */
        } DMATDLRb;
    };

    union
    {
        __IOM uint32_t DMARDLR                           ;  /*!< 0x00000054 : DMA Receive Data Level */

        struct
        {
            __IOM uint32_t DMARDL                    : 8 ;  /*!< [ 7: 0] : Receive Data Level. */
                  uint32_t RSV_0                     : 24;  /*!< [31: 8] : reserved. */
        } DMARDLRb;
    };

    union
    {
        __IM  uint32_t IDR                               ;  /*!< 0x00000058 : Identification Register */

        struct
        {
            __IM  uint32_t IDCODE                    : 32;  /*!< [31: 0] : Identification code. */
        } IDRb;
    };

    union
    {
        __IM  uint32_t VERSION_ID                        ;  /*!< 0x0000005c : component version */

        struct
        {
            __IM  uint32_t SPIC_COMP_VERSION         : 32;  /*!< [31: 0] : Contains the hex representation of the Synopsys component version. */
        } VERSION_IDb;
    };

    union
    {
        __IM  uint32_t DR0                               ;  /*!< 0x00000060 : Data Register0 */

        struct
        {
            __IM  uint32_t DR                        : 32;  /*!< [31: 0] : Data Register. When writing to this register, you must right-justify the data. Read data are automatically right-justified.
                                                                           Read = Receive FIFO buffer Write = Transmit FIFO buffer. */
        } DR0b;
    };

    union
    {
        __IM  uint32_t DR1                               ;  /*!< 0x00000064 : Data Register1 */

        struct
        {
            __IM  uint32_t DR                        : 32;  /*!< [31: 0] : Data Register. When writing to this register, you must right-justify the data. Read data are automatically right-justified.
                                                                           Read = Receive FIFO buffer Write = Transmit FIFO buffer. */
        } DR1b;
    };

    union
    {
        __IM  uint32_t DR2                               ;  /*!< 0x00000068 : Data Register2 */

        struct
        {
            __IM  uint32_t DR                        : 32;  /*!< [31: 0] : Data Register. When writing to this register, you must right-justify the data. Read data are automatically right-justified.
                                                                           Read = Receive FIFO buffer Write = Transmit FIFO buffer. */
        } DR2b;
    };

    union
    {
        __IM  uint32_t DR3                               ;  /*!< 0x0000006c : Data Register3 */

        struct
        {
            __IM  uint32_t DR                        : 32;  /*!< [31: 0] : Data Register. When writing to this register, you must right-justify the data. Read data are automatically right-justified.
                                                                           Read = Receive FIFO buffer Write = Transmit FIFO buffer. */
        } DR3b;
    };

    union
    {
        __IM  uint32_t DR4                               ;  /*!< 0x00000070 : Data Register4 */

        struct
        {
            __IM  uint32_t DR                        : 32;  /*!< [31: 0] : Data Register. When writing to this register, you must right-justify the data. Read data are automatically right-justified.
                                                                           Read = Receive FIFO buffer Write = Transmit FIFO buffer. */
        } DR4b;
    };

    union
    {
        __IM  uint32_t DR5                               ;  /*!< 0x00000074 : Data Register5 */

        struct
        {
            __IM  uint32_t DR                        : 32;  /*!< [31: 0] : Data Register. When writing to this register, you must right-justify the data. Read data are automatically right-justified.
                                                                           Read = Receive FIFO buffer Write = Transmit FIFO buffer. */
        } DR5b;
    };

    union
    {
        __IM  uint32_t DR6                               ;  /*!< 0x00000078 : Data Register6 */

        struct
        {
            __IM  uint32_t DR                        : 32;  /*!< [31: 0] : Data Register. When writing to this register, you must right-justify the data. Read data are automatically right-justified.
                                                                           Read = Receive FIFO buffer Write = Transmit FIFO buffer. */
        } DR6b;
    };

    union
    {
        __IM  uint32_t DR7                               ;  /*!< 0x0000007c : Data Register7 */

        struct
        {
            __IM  uint32_t DR                        : 32;  /*!< [31: 0] : Data Register. When writing to this register, you must right-justify the data. Read data are automatically right-justified.
                                                                           Read = Receive FIFO buffer Write = Transmit FIFO buffer. */
        } DR7b;
    };

    union
    {
        __IM  uint32_t DR8                               ;  /*!< 0x00000080 : Data Register8 */

        struct
        {
            __IM  uint32_t DR                        : 32;  /*!< [31: 0] : Data Register. When writing to this register, you must right-justify the data. Read data are automatically right-justified.
                                                                           Read = Receive FIFO buffer Write = Transmit FIFO buffer. */
        } DR8b;
    };

    union
    {
        __IM  uint32_t DR9                               ;  /*!< 0x00000084 : Data Register9 */

        struct
        {
            __IM  uint32_t DR                        : 32;  /*!< [31: 0] : Data Register. When writing to this register, you must right-justify the data. Read data are automatically right-justified.
                                                                           Read = Receive FIFO buffer Write = Transmit FIFO buffer. */
        } DR9b;
    };

    union
    {
        __IM  uint32_t DR10                              ;  /*!< 0x00000088 : Data Register10 */

        struct
        {
            __IM  uint32_t DR                        : 32;  /*!< [31: 0] : Data Register. When writing to this register, you must right-justify the data. Read data are automatically right-justified.
                                                                           Read = Receive FIFO buffer Write = Transmit FIFO buffer. */
        } DR10b;
    };

    union
    {
        __IM  uint32_t DR11                              ;  /*!< 0x0000008c : Data Register11 */

        struct
        {
            __IM  uint32_t DR                        : 32;  /*!< [31: 0] : Data Register. When writing to this register, you must right-justify the data. Read data are automatically right-justified.
                                                                           Read = Receive FIFO buffer Write = Transmit FIFO buffer. */
        } DR11b;
    };

    union
    {
        __IM  uint32_t DR12                              ;  /*!< 0x00000090 : Data Register12 */

        struct
        {
            __IM  uint32_t DR                        : 32;  /*!< [31: 0] : Data Register. When writing to this register, you must right-justify the data. Read data are automatically right-justified.
                                                                           Read = Receive FIFO buffer Write = Transmit FIFO buffer. */
        } DR12b;
    };

    union
    {
        __IM  uint32_t DR13                              ;  /*!< 0x00000094 : Data Register13 */

        struct
        {
            __IM  uint32_t DR                        : 32;  /*!< [31: 0] : Data Register. When writing to this register, you must right-justify the data. Read data are automatically right-justified.
                                                                           Read = Receive FIFO buffer Write = Transmit FIFO buffer. */
        } DR13b;
    };

    union
    {
        __IM  uint32_t DR14                              ;  /*!< 0x00000098 : Data Register14 */

        struct
        {
            __IM  uint32_t DR                        : 32;  /*!< [31: 0] : Data Register. When writing to this register, you must right-justify the data. Read data are automatically right-justified.
                                                                           Read = Receive FIFO buffer Write = Transmit FIFO buffer. */
        } DR14b;
    };

    union
    {
        __IM  uint32_t DR15                              ;  /*!< 0x0000009c : Data Register15 */

        struct
        {
            __IM  uint32_t DR                        : 32;  /*!< [31: 0] : Data Register. When writing to this register, you must right-justify the data. Read data are automatically right-justified.
                                                                           Read = Receive FIFO buffer Write = Transmit FIFO buffer. */
        } DR15b;
    };

    union
    {
        __IM  uint32_t DR16                              ;  /*!< 0x000000a0 : Data Register16 */

        struct
        {
            __IM  uint32_t DR                        : 32;  /*!< [31: 0] : Data Register. When writing to this register, you must right-justify the data. Read data are automatically right-justified.
                                                                           Read = Receive FIFO buffer Write = Transmit FIFO buffer. */
        } DR16b;
    };

    union
    {
        __IM  uint32_t DR17                              ;  /*!< 0x000000a4 : Data Register17 */

        struct
        {
            __IM  uint32_t DR                        : 32;  /*!< [31: 0] : Data Register. When writing to this register, you must right-justify the data. Read data are automatically right-justified.
                                                                           Read = Receive FIFO buffer Write = Transmit FIFO buffer. */
        } DR17b;
    };

    union
    {
        __IM  uint32_t DR18                              ;  /*!< 0x000000a8 : Data Register18 */

        struct
        {
            __IM  uint32_t DR                        : 32;  /*!< [31: 0] : Data Register. When writing to this register, you must right-justify the data. Read data are automatically right-justified.
                                                                           Read = Receive FIFO buffer Write = Transmit FIFO buffer. */
        } DR18b;
    };

    union
    {
        __IM  uint32_t DR19                              ;  /*!< 0x000000ac : Data Register19 */

        struct
        {
            __IM  uint32_t DR                        : 32;  /*!< [31: 0] : Data Register. When writing to this register, you must right-justify the data. Read data are automatically right-justified.
                                                                           Read = Receive FIFO buffer Write = Transmit FIFO buffer. */
        } DR19b;
    };

    union
    {
        __IM  uint32_t DR20                              ;  /*!< 0x000000b0 : Data Register20 */

        struct
        {
            __IM  uint32_t DR                        : 32;  /*!< [31: 0] : Data Register. When writing to this register, you must right-justify the data. Read data are automatically right-justified.
                                                                           Read = Receive FIFO buffer Write = Transmit FIFO buffer. */
        } DR20b;
    };

    union
    {
        __IM  uint32_t DR21                              ;  /*!< 0x000000b4 : Data Register21 */

        struct
        {
            __IM  uint32_t DR                        : 32;  /*!< [31: 0] : Data Register. When writing to this register, you must right-justify the data. Read data are automatically right-justified.
                                                                           Read = Receive FIFO buffer Write = Transmit FIFO buffer. */
        } DR21b;
    };

    union
    {
        __IM  uint32_t DR22                              ;  /*!< 0x000000b8 : Data Register22 */

        struct
        {
            __IM  uint32_t DR                        : 32;  /*!< [31: 0] : Data Register. When writing to this register, you must right-justify the data. Read data are automatically right-justified.
                                                                           Read = Receive FIFO buffer Write = Transmit FIFO buffer. */
        } DR22b;
    };

    union
    {
        __IM  uint32_t DR23                              ;  /*!< 0x000000bc : Data Register23 */

        struct
        {
            __IM  uint32_t DR                        : 32;  /*!< [31: 0] : Data Register. When writing to this register, you must right-justify the data. Read data are automatically right-justified.
                                                                           Read = Receive FIFO buffer Write = Transmit FIFO buffer. */
        } DR23b;
    };

    union
    {
        __IM  uint32_t DR24                              ;  /*!< 0x000000c0 : Data Register24 */

        struct
        {
            __IM  uint32_t DR                        : 32;  /*!< [31: 0] : Data Register. When writing to this register, you must right-justify the data. Read data are automatically right-justified.
                                                                           Read = Receive FIFO buffer Write = Transmit FIFO buffer. */
        } DR24b;
    };

    union
    {
        __IM  uint32_t DR25                              ;  /*!< 0x000000c4 : Data Register25 */

        struct
        {
            __IM  uint32_t DR                        : 32;  /*!< [31: 0] : Data Register. When writing to this register, you must right-justify the data. Read data are automatically right-justified.
                                                                           Read = Receive FIFO buffer Write = Transmit FIFO buffer. */
        } DR25b;
    };

    union
    {
        __IM  uint32_t DR26                              ;  /*!< 0x000000c8 : Data Register26 */

        struct
        {
            __IM  uint32_t DR                        : 32;  /*!< [31: 0] : Data Register. When writing to this register, you must right-justify the data. Read data are automatically right-justified.
                                                                           Read = Receive FIFO buffer Write = Transmit FIFO buffer. */
        } DR26b;
    };

    union
    {
        __IM  uint32_t DR27                              ;  /*!< 0x000000cc : Data Register27 */

        struct
        {
            __IM  uint32_t DR                        : 32;  /*!< [31: 0] : Data Register. When writing to this register, you must right-justify the data. Read data are automatically right-justified.
                                                                           Read = Receive FIFO buffer Write = Transmit FIFO buffer. */
        } DR27b;
    };

    union
    {
        __IM  uint32_t DR28                              ;  /*!< 0x000000d0 : Data Register28 */

        struct
        {
            __IM  uint32_t DR                        : 32;  /*!< [31: 0] : Data Register. When writing to this register, you must right-justify the data. Read data are automatically right-justified.
                                                                           Read = Receive FIFO buffer Write = Transmit FIFO buffer. */
        } DR28b;
    };

    union
    {
        __IM  uint32_t DR29                              ;  /*!< 0x000000d4 : Data Register29 */

        struct
        {
            __IM  uint32_t DR                        : 32;  /*!< [31: 0] : Data Register. When writing to this register, you must right-justify the data. Read data are automatically right-justified.
                                                                           Read = Receive FIFO buffer Write = Transmit FIFO buffer. */
        } DR29b;
    };

    union
    {
        __IM  uint32_t DR30                              ;  /*!< 0x000000d8 : Data Register30 */

        struct
        {
            __IM  uint32_t DR                        : 32;  /*!< [31: 0] : Data Register. When writing to this register, you must right-justify the data. Read data are automatically right-justified.
                                                                           Read = Receive FIFO buffer Write = Transmit FIFO buffer. */
        } DR30b;
    };

    union
    {
        __IM  uint32_t DR31                              ;  /*!< 0x000000dc : Data Register31 */

        struct
        {
            __IM  uint32_t DR                        : 32;  /*!< [31: 0] : Data Register. When writing to this register, you must right-justify the data. Read data are automatically right-justified.
                                                                           Read = Receive FIFO buffer Write = Transmit FIFO buffer. */
        } DR31b;
    };

    union
    {
        __IM  uint32_t DR32                              ;  /*!< 0x000000e0 : Data Register32 */

        struct
        {
            __IM  uint32_t DR                        : 32;  /*!< [31: 0] : Data Register. When writing to this register, you must right-justify the data. Read data are automatically right-justified.
                                                                           Read = Receive FIFO buffer Write = Transmit FIFO buffer. */
        } DR32b;
    };

    union
    {
        __IM  uint32_t DR33                              ;  /*!< 0x000000e4 : Data Register33 */

        struct
        {
            __IM  uint32_t DR                        : 32;  /*!< [31: 0] : Data Register. When writing to this register, you must right-justify the data. Read data are automatically right-justified.
                                                                           Read = Receive FIFO buffer Write = Transmit FIFO buffer. */
        } DR33b;
    };

    union
    {
        __IM  uint32_t DR34                              ;  /*!< 0x000000e8 : Data Register34 */

        struct
        {
            __IM  uint32_t DR                        : 32;  /*!< [31: 0] : Data Register. When writing to this register, you must right-justify the data. Read data are automatically right-justified.
                                                                           Read = Receive FIFO buffer Write = Transmit FIFO buffer. */
        } DR34b;
    };

    union
    {
        __IM  uint32_t DR35                              ;  /*!< 0x000000ec : Data Register35 */

        struct
        {
            __IM  uint32_t DR                        : 32;  /*!< [31: 0] : Data Register. When writing to this register, you must right-justify the data. Read data are automatically right-justified.
                                                                           Read = Receive FIFO buffer Write = Transmit FIFO buffer. */
        } DR35b;
    };

    union
    {
        __IOM uint32_t RX_SAMPLE_DELAY                   ;  /*!< 0x000000f0 : RX Sample Delay Register */

        struct
        {
            __IOM uint32_t RSD                       : 8 ;  /*!< [ 7: 0] : Receive Data (rxd) Sample Delay. This register is used to delay the sample of the rxd input port. Each value represents a single SPI_clk delay on the sample of rxd.
                                                                           Note; If this register is programmed with a value that exceeds the depth of the internal shift registers 255 zero delay will be applied to the rxd sample. */
                  uint32_t RSV_0                     : 8 ;  /*!< [15: 8] : reserved. */
            __IOM uint32_t SE                        : 1 ;  /*!< [16:16] : Receive Data (rxd) Sampling Edge. */
                  uint32_t RSV_1                     : 15;  /*!< [31:17] : reserved. */
        } RX_SAMPLE_DELAYb;
    };

    union
    {
        __IOM uint32_t SPI_CTRLR0                        ;  /*!< 0x000000f4 : SPI_CTRLR0 - SPI Control Register */

        struct
        {
            __IOM uint32_t TRANS_TYPE                : 2 ;  /*!< [ 1: 0] : Address and instruction transfer format.
                                                                           Selects whether SPI will transmit instruction/address either in Standard SPI mode or the SPI mode selected in CTRLR0.SPI_FRF field.
                                                                           Values:
                                                                           0x0 (TT0): Instruction and Address will be sent in Standard SPI Mode.
                                                                           0x1 (TT1): Instruction will be sent in Standard SPI Mode and Address will be sent in the mode specified by CTRLR0.SPI_FRF.
                                                                           0x2 (TT2): Both Instruction and Address will be sent in the mode specified by SPI_FRF.
                                                                           0x3 (TT3): Reserved. */
            __IOM uint32_t ADDR_L                    : 4 ;  /*!< [ 5: 2] : This bit defines Length of Address to be transmitted. Only after this much bits are programmed in to the FIFO the transfer can begin.
                                                                           Values:
                                                                           0x0 (ADDR_L0): No Address
                                                                           0x1 (ADDR_L4): 4 bit Address length
                                                                           0x2 (ADDR_L8): 8 bit Address length
                                                                           0x3 (ADDR_L12): 12 bit Address length
                                                                           0x4 (ADDR_L16): 16 bit Address length
                                                                           0x5 (ADDR_L20): 20 bit Address length
                                                                           0x6 (ADDR_L24): 24 bit Address length
                                                                           0x7 (ADDR_L28): 28 bit Address length
                                                                           0x8 (ADDR_L32): 32 bit Address length
                                                                           0x9 (ADDR_L36): 36 bit Address length
                                                                           0xa (ADDR_L40): 40 bit Address length
                                                                           0xb (ADDR_L44): 44 bit Address length
                                                                           0xc (ADDR_L48): 48 bit Address length
                                                                           0xd (ADDR_L52): 52 bit Address length
                                                                           0xe (ADDR_L56): 56 bit Address length
                                                                           0xf (ADDR_L60): 60 bit Address length */
                  uint32_t RSV_0                     : 1 ;  /*!< [ 6: 6] : reserved. */
            __IM  uint32_t XIP_MD_BIT_EN             : 1 ;  /*!< [ 7: 7] : Mode bits enable in XIP mode. */
            __IOM uint32_t INST_L                    : 2 ;  /*!< [ 9: 8] : Dual/Quad/Octal mode instruction length in bits.
                                                                           Values:
                                                                           0x0 (INST_L0): No Instruction
                                                                           0x1 (INST_L4): 4 bit Instruction length
                                                                           0x2 (INST_L8): 8 bit Instruction length
                                                                           0x3 (INST_L16): 16 bit Instruction length Value After Reset: SPIC_DFLT_INST_L Exists: Always */
                  uint32_t RSV_1                     : 1 ;  /*!< [10:10] : reserved. */
            __IOM uint32_t WAIT_CYCLES               : 5 ;  /*!< [15:11] : Wait cycles in Dual/Quad/Octal mode between control frames transmit and data reception. */
            __IM  uint32_t SPI_DDR_EN                : 1 ;  /*!< [16:16] : SPI DDR Enable bit. */
            __IM  uint32_t INST_DDR_EN               : 1 ;  /*!< [17:17] : Instruction DDR Enable bit. */
            __IM  uint32_t SPI_RXDS_EN               : 1 ;  /*!< [18:18] : Read data strobe enable bit. */
            __IOM uint32_t XIP_DFS_HC                : 1 ;  /*!< [19:19] : Fix DFS for XIP transfers. */
            __IOM uint32_t XIP_INST_EN               : 1 ;  /*!< [20:20] : XIP instruction enable bit. */
            __IOM uint32_t SPIC_XIP_CONT_XFER_EN     : 1 ;  /*!< [21:21] : Enable continuous transfer in XIP mode. */
                  uint32_t RSV_2                     : 2 ;  /*!< [23:22] : reserved. */
            __IM  uint32_t SPI_DM_EN                 : 1 ;  /*!< [24:24] : SPI data mask enable bit.
                                                                           When this bit is enabled, the txd_dmsignal is used to mask the data on the txd data line. */
            __IM  uint32_t SPI_RXDS_SIG_EN           : 1 ;  /*!< [25:25] : Enable rxds signaling during address and command phase of Hypebus transfer.
                                                                           This bit enables rxds signaling by Hyperbus slave devices during Command-Address (CA) phase. If the rxds signal is set to 1 during the CA phase of transfer, SPI transmits (2*SPI_CTRLR0.WAIT_CYCLES-1) wait cycles after the address phase is complete. */
            __IOM uint32_t XIP_MBL                   : 2 ;  /*!< [27:26] : XIP Mode bits length. Sets the length of mode bits in XIP mode of operation. These bits are valid only when SPI_CTRLR0.XIP_MD_BIT_EN is set to 1.
                                                                           Values:
                                                                           0x0 (MBL_2): Mode bits length equal to 2
                                                                           0x1 (MBL_4): Mode bits length equal to 4
                                                                           0x2 (MBL_8): Mode bits length equal to 8
                                                                           0x3 (MBL_16): Mode bits length equal to 16 */
                  uint32_t RSV_3                     : 1 ;  /*!< [28:28] : reserved. */
            __IOM uint32_t XIP_PREFETCH_EN           : 1 ;  /*!< [29:29] : Enables XIP pre-fetch functionality in SPI. Once enabled SPI will pre-fetch data frames from next contigous location, to reduce the latency for the upcoming contiguous transfer. If the next XIP request is not contigous then
                                                                           pre-fetched bits will be discarded. */
            __IOM uint32_t CLK_STRETCH_EN            : 1 ;  /*!< [30:30] : Enables clock stretching capability in SPI transfers.
                                                                           In case of write, if the FIFO becomes empty SPI will stretch the clock until FIFO has enough data to continue the transfer.
                                                                           In case of read, if the receive FIFO becomes full SPI will stop the clock until data has been read from the FIFO. */
                  uint32_t RSV_4                     : 1 ;  /*!< [31:31] : reserved. */
        } SPI_CTRLR0b;
    };

    uint8_t    RSV_0XF8[4]                               ;
    union
    {
        __IOM uint32_t XIP_MODE_BITS                     ;  /*!< 0x000000fc : eXecute in Place - Mode bits */

        struct
        {
            __IOM uint32_t XIP_MD_BITS               : 16;  /*!< [15: 0] : XIP mode bits to be sent after address phase of XIP transfer. */
                  uint32_t RSV_0                     : 16;  /*!< [31:16] : reserved. */
        } XIP_MODE_BITSb;
    };

    union
    {
        __IOM uint32_t XIP_INCR_INST                     ;  /*!< 0x00000100 : XIP_INCR_INST - XIP INCR transfer opcode */

        struct
        {
            __IOM uint32_t INCR_INST                 : 16;  /*!< [15: 0] : XIP INCR transfer opcode. */
                  uint32_t RSV_0                     : 16;  /*!< [31:16] : reserved. */
        } XIP_INCR_INSTb;
    };

    union
    {
        __IOM uint32_t XIP_WRAP_INST                     ;  /*!< 0x00000104 : XIP_WRAP_INST - XIP WRAP transfer opcode */

        struct
        {
            __IOM uint32_t WRAP_INST                 : 16;  /*!< [15: 0] : XIP WRAP transfer opcode. */
                  uint32_t RSV_0                     : 16;  /*!< [31:16] : reserved. */
        } XIP_WRAP_INSTb;
    };

    uint8_t    RSV_0X108[3832]                           ;
} SPI_Type;


/*!
 * @}
 */

/*!
 * \name SPI Base Address Definitions
 *
 * @{
 */

/*! \brief SPIA base address */
#define SPIA_BASE (0x42300000UL)
/*! \brief SPIB base address */
#define SPIB_BASE (0x42301000UL)
/*! \brief SPIC base address */
#define SPIC_BASE (0x42302000UL)
/*! \brief SPIA base pointer */
#define SPIA ((SPI_Type *) SPIA_BASE)
/*! \brief SPIB base pointer */
#define SPIB ((SPI_Type *) SPIB_BASE)
/*! \brief SPIC base pointer */
#define SPIC ((SPI_Type *) SPIC_BASE)

/*!
 * @}
 */


/*!
 * \name SPI Register Bitfield Definitions
 *
 * @{
 */

/* CTRLR0 bitfield */
#define SPI_CTRLR0_SPI_IS_MST_Pos     (31U)                                                                         /*!< SPI_IS_MST Position 31 */
#define SPI_CTRLR0_SPI_IS_MST_Msk     (0x1U << SPI_CTRLR0_SPI_IS_MST_Pos)                                           /*!< SPI_IS_MST Mask 0x80000000 */
#define SPI_CTRLR0_SPI_IS_MST_Set(x)  (((uint32_t) (x) << SPI_CTRLR0_SPI_IS_MST_Pos) & SPI_CTRLR0_SPI_IS_MST_Msk)   /*!< SPI_IS_MST Set Value */
#define SPI_CTRLR0_SPI_IS_MST_Get(x)  (((uint32_t) (x) & SPI_CTRLR0_SPI_IS_MST_Msk) >> SPI_CTRLR0_SPI_IS_MST_Pos)   /*!< SPI_IS_MST Get Value */

#define SPI_CTRLR0_SPI_DWS_EN_Pos     (25U)                                                                         /*!< SPI_DWS_EN Position 25 */
#define SPI_CTRLR0_SPI_DWS_EN_Msk     (0x1U << SPI_CTRLR0_SPI_DWS_EN_Pos)                                           /*!< SPI_DWS_EN Mask 0x02000000 */
#define SPI_CTRLR0_SPI_DWS_EN_Set(x)  (((uint32_t) (x) << SPI_CTRLR0_SPI_DWS_EN_Pos) & SPI_CTRLR0_SPI_DWS_EN_Msk)   /*!< SPI_DWS_EN Set Value */
#define SPI_CTRLR0_SPI_DWS_EN_Get(x)  (((uint32_t) (x) & SPI_CTRLR0_SPI_DWS_EN_Msk) >> SPI_CTRLR0_SPI_DWS_EN_Pos)   /*!< SPI_DWS_EN Get Value */

#define SPI_CTRLR0_SPI_HYPERBUS_EN_Pos     (24U)                                                                                   /*!< SPI_HYPERBUS_EN Position 24 */
#define SPI_CTRLR0_SPI_HYPERBUS_EN_Msk     (0x1U << SPI_CTRLR0_SPI_HYPERBUS_EN_Pos)                                                /*!< SPI_HYPERBUS_EN Mask 0x01000000 */
#define SPI_CTRLR0_SPI_HYPERBUS_EN_Set(x)  (((uint32_t) (x) << SPI_CTRLR0_SPI_HYPERBUS_EN_Pos) & SPI_CTRLR0_SPI_HYPERBUS_EN_Msk)   /*!< SPI_HYPERBUS_EN Set Value */
#define SPI_CTRLR0_SPI_HYPERBUS_EN_Get(x)  (((uint32_t) (x) & SPI_CTRLR0_SPI_HYPERBUS_EN_Msk) >> SPI_CTRLR0_SPI_HYPERBUS_EN_Pos)   /*!< SPI_HYPERBUS_EN Get Value */

#define SPI_CTRLR0_SPI_FRF_Pos     (22U)                                                                   /*!< SPI_FRF Position 22 */
#define SPI_CTRLR0_SPI_FRF_Msk     (0x3U << SPI_CTRLR0_SPI_FRF_Pos)                                        /*!< SPI_FRF Mask 0x00C00000 */
#define SPI_CTRLR0_SPI_FRF_Set(x)  (((uint32_t) (x) << SPI_CTRLR0_SPI_FRF_Pos) & SPI_CTRLR0_SPI_FRF_Msk)   /*!< SPI_FRF Set Value */
#define SPI_CTRLR0_SPI_FRF_Get(x)  (((uint32_t) (x) & SPI_CTRLR0_SPI_FRF_Msk) >> SPI_CTRLR0_SPI_FRF_Pos)   /*!< SPI_FRF Get Value */

#define SPI_CTRLR0_CFS_Pos     (16U)                                                           /*!< CFS Position 16 */
#define SPI_CTRLR0_CFS_Msk     (0xfU << SPI_CTRLR0_CFS_Pos)                                    /*!< CFS Mask 0x000F0000 */
#define SPI_CTRLR0_CFS_Set(x)  (((uint32_t) (x) << SPI_CTRLR0_CFS_Pos) & SPI_CTRLR0_CFS_Msk)   /*!< CFS Set Value */
#define SPI_CTRLR0_CFS_Get(x)  (((uint32_t) (x) & SPI_CTRLR0_CFS_Msk) >> SPI_CTRLR0_CFS_Pos)   /*!< CFS Get Value */

#define SPI_CTRLR0_SSTE_Pos     (14U)                                                             /*!< SSTE Position 14 */
#define SPI_CTRLR0_SSTE_Msk     (0x1U << SPI_CTRLR0_SSTE_Pos)                                     /*!< SSTE Mask 0x00004000 */
#define SPI_CTRLR0_SSTE_Set(x)  (((uint32_t) (x) << SPI_CTRLR0_SSTE_Pos) & SPI_CTRLR0_SSTE_Msk)   /*!< SSTE Set Value */
#define SPI_CTRLR0_SSTE_Get(x)  (((uint32_t) (x) & SPI_CTRLR0_SSTE_Msk) >> SPI_CTRLR0_SSTE_Pos)   /*!< SSTE Get Value */

#define SPI_CTRLR0_SRL_Pos     (13U)                                                           /*!< SRL Position 13 */
#define SPI_CTRLR0_SRL_Msk     (0x1U << SPI_CTRLR0_SRL_Pos)                                    /*!< SRL Mask 0x00002000 */
#define SPI_CTRLR0_SRL_Set(x)  (((uint32_t) (x) << SPI_CTRLR0_SRL_Pos) & SPI_CTRLR0_SRL_Msk)   /*!< SRL Set Value */
#define SPI_CTRLR0_SRL_Get(x)  (((uint32_t) (x) & SPI_CTRLR0_SRL_Msk) >> SPI_CTRLR0_SRL_Pos)   /*!< SRL Get Value */

#define SPI_CTRLR0_SLV_OE_Pos     (12U)                                                                 /*!< SLV_OE Position 12 */
#define SPI_CTRLR0_SLV_OE_Msk     (0x1U << SPI_CTRLR0_SLV_OE_Pos)                                       /*!< SLV_OE Mask 0x00001000 */
#define SPI_CTRLR0_SLV_OE_Set(x)  (((uint32_t) (x) << SPI_CTRLR0_SLV_OE_Pos) & SPI_CTRLR0_SLV_OE_Msk)   /*!< SLV_OE Set Value */
#define SPI_CTRLR0_SLV_OE_Get(x)  (((uint32_t) (x) & SPI_CTRLR0_SLV_OE_Msk) >> SPI_CTRLR0_SLV_OE_Pos)   /*!< SLV_OE Get Value */

#define SPI_CTRLR0_TMOD_Pos     (10U)                                                             /*!< TMOD Position 10 */
#define SPI_CTRLR0_TMOD_Msk     (0x3U << SPI_CTRLR0_TMOD_Pos)                                     /*!< TMOD Mask 0x00000C00 */
#define SPI_CTRLR0_TMOD_Set(x)  (((uint32_t) (x) << SPI_CTRLR0_TMOD_Pos) & SPI_CTRLR0_TMOD_Msk)   /*!< TMOD Set Value */
#define SPI_CTRLR0_TMOD_Get(x)  (((uint32_t) (x) & SPI_CTRLR0_TMOD_Msk) >> SPI_CTRLR0_TMOD_Pos)   /*!< TMOD Get Value */

#define SPI_CTRLR0_SCPOL_Pos     (9U)                                                                /*!< SCPOL Position 9 */
#define SPI_CTRLR0_SCPOL_Msk     (0x1U << SPI_CTRLR0_SCPOL_Pos)                                      /*!< SCPOL Mask 0x00000200 */
#define SPI_CTRLR0_SCPOL_Set(x)  (((uint32_t) (x) << SPI_CTRLR0_SCPOL_Pos) & SPI_CTRLR0_SCPOL_Msk)   /*!< SCPOL Set Value */
#define SPI_CTRLR0_SCPOL_Get(x)  (((uint32_t) (x) & SPI_CTRLR0_SCPOL_Msk) >> SPI_CTRLR0_SCPOL_Pos)   /*!< SCPOL Get Value */

#define SPI_CTRLR0_SCPH_Pos     (8U)                                                              /*!< SCPH Position 8 */
#define SPI_CTRLR0_SCPH_Msk     (0x1U << SPI_CTRLR0_SCPH_Pos)                                     /*!< SCPH Mask 0x00000100 */
#define SPI_CTRLR0_SCPH_Set(x)  (((uint32_t) (x) << SPI_CTRLR0_SCPH_Pos) & SPI_CTRLR0_SCPH_Msk)   /*!< SCPH Set Value */
#define SPI_CTRLR0_SCPH_Get(x)  (((uint32_t) (x) & SPI_CTRLR0_SCPH_Msk) >> SPI_CTRLR0_SCPH_Pos)   /*!< SCPH Get Value */

#define SPI_CTRLR0_FRF_Pos     (6U)                                                            /*!< FRF Position 6 */
#define SPI_CTRLR0_FRF_Msk     (0x3U << SPI_CTRLR0_FRF_Pos)                                    /*!< FRF Mask 0x000000C0 */
#define SPI_CTRLR0_FRF_Set(x)  (((uint32_t) (x) << SPI_CTRLR0_FRF_Pos) & SPI_CTRLR0_FRF_Msk)   /*!< FRF Set Value */
#define SPI_CTRLR0_FRF_Get(x)  (((uint32_t) (x) & SPI_CTRLR0_FRF_Msk) >> SPI_CTRLR0_FRF_Pos)   /*!< FRF Get Value */

#define SPI_CTRLR0_DFS_Pos     (0U)                                                            /*!< DFS Position 0 */
#define SPI_CTRLR0_DFS_Msk     (0x1fU << SPI_CTRLR0_DFS_Pos)                                   /*!< DFS Mask 0x0000001F */
#define SPI_CTRLR0_DFS_Set(x)  (((uint32_t) (x) << SPI_CTRLR0_DFS_Pos) & SPI_CTRLR0_DFS_Msk)   /*!< DFS Set Value */
#define SPI_CTRLR0_DFS_Get(x)  (((uint32_t) (x) & SPI_CTRLR0_DFS_Msk) >> SPI_CTRLR0_DFS_Pos)   /*!< DFS Get Value */

/* CTRLR1 bitfield */
#define SPI_CTRLR1_NDF_Pos     (0U)                                                            /*!< NDF Position 1 */
#define SPI_CTRLR1_NDF_Msk     (0x7fffU << SPI_CTRLR1_NDF_Pos)                                 /*!< NDF Mask 0x0000FFFE */
#define SPI_CTRLR1_NDF_Set(x)  (((uint32_t) (x) << SPI_CTRLR1_NDF_Pos) & SPI_CTRLR1_NDF_Msk)   /*!< NDF Set Value */
#define SPI_CTRLR1_NDF_Get(x)  (((uint32_t) (x) & SPI_CTRLR1_NDF_Msk) >> SPI_CTRLR1_NDF_Pos)   /*!< NDF Get Value */

/* SPIENR bitfield */
#define SPI_SPIENR_SPIC_EN_Pos     (0U)                                                                    /*!< SPIC_EN Position 0 */
#define SPI_SPIENR_SPIC_EN_Msk     (0x1U << SPI_SPIENR_SPIC_EN_Pos)                                        /*!< SPIC_EN Mask 0x00000001 */
#define SPI_SPIENR_SPIC_EN_Set(x)  (((uint32_t) (x) << SPI_SPIENR_SPIC_EN_Pos) & SPI_SPIENR_SPIC_EN_Msk)   /*!< SPIC_EN Set Value */
#define SPI_SPIENR_SPIC_EN_Get(x)  (((uint32_t) (x) & SPI_SPIENR_SPIC_EN_Msk) >> SPI_SPIENR_SPIC_EN_Pos)   /*!< SPIC_EN Get Value */

/* MWCR bitfield */
/* SER bitfield */
#define SPI_SER_SER_Pos     (0U)                                                      /*!< SER Position 0 */
#define SPI_SER_SER_Msk     (0x1U << SPI_SER_SER_Pos)                                 /*!< SER Mask 0x00000001 */
#define SPI_SER_SER_Set(x)  (((uint32_t) (x) << SPI_SER_SER_Pos) & SPI_SER_SER_Msk)   /*!< SER Set Value */
#define SPI_SER_SER_Get(x)  (((uint32_t) (x) & SPI_SER_SER_Msk) >> SPI_SER_SER_Pos)   /*!< SER Get Value */

/* BAUDR bitfield */
#define SPI_BAUDR_SCKDV_Pos     (1U)                                                              /*!< SCKDV Position 1 */
#define SPI_BAUDR_SCKDV_Msk     (0x7fffU << SPI_BAUDR_SCKDV_Pos)                                  /*!< SCKDV Mask 0x0000FFFE */
#define SPI_BAUDR_SCKDV_Set(x)  (((uint32_t) (x) << SPI_BAUDR_SCKDV_Pos) & SPI_BAUDR_SCKDV_Msk)   /*!< SCKDV Set Value */
#define SPI_BAUDR_SCKDV_Get(x)  (((uint32_t) (x) & SPI_BAUDR_SCKDV_Msk) >> SPI_BAUDR_SCKDV_Pos)   /*!< SCKDV Get Value */

/* TXFTLR bitfield */
#define SPI_TXFTLR_TXFTHR_Pos     (16U)                                                                 /*!< TXFTHR Position 16 */
#define SPI_TXFTLR_TXFTHR_Msk     (0x1fU << SPI_TXFTLR_TXFTHR_Pos)                                      /*!< TXFTHR Mask 0x001F0000 */
#define SPI_TXFTLR_TXFTHR_Set(x)  (((uint32_t) (x) << SPI_TXFTLR_TXFTHR_Pos) & SPI_TXFTLR_TXFTHR_Msk)   /*!< TXFTHR Set Value */
#define SPI_TXFTLR_TXFTHR_Get(x)  (((uint32_t) (x) & SPI_TXFTLR_TXFTHR_Msk) >> SPI_TXFTLR_TXFTHR_Pos)   /*!< TXFTHR Get Value */

#define SPI_TXFTLR_TFT_Pos     (0U)                                                            /*!< TFT Position 0 */
#define SPI_TXFTLR_TFT_Msk     (0x1fU << SPI_TXFTLR_TFT_Pos)                                   /*!< TFT Mask 0x0000001F */
#define SPI_TXFTLR_TFT_Set(x)  (((uint32_t) (x) << SPI_TXFTLR_TFT_Pos) & SPI_TXFTLR_TFT_Msk)   /*!< TFT Set Value */
#define SPI_TXFTLR_TFT_Get(x)  (((uint32_t) (x) & SPI_TXFTLR_TFT_Msk) >> SPI_TXFTLR_TFT_Pos)   /*!< TFT Get Value */

/* RXFTLR bitfield */
#define SPI_RXFTLR_RFT_Pos     (0U)                                                            /*!< RFT Position 0 */
#define SPI_RXFTLR_RFT_Msk     (0xffU << SPI_RXFTLR_RFT_Pos)                                   /*!< RFT Mask 0x000000FF */
#define SPI_RXFTLR_RFT_Set(x)  (((uint32_t) (x) << SPI_RXFTLR_RFT_Pos) & SPI_RXFTLR_RFT_Msk)   /*!< RFT Set Value */
#define SPI_RXFTLR_RFT_Get(x)  (((uint32_t) (x) & SPI_RXFTLR_RFT_Msk) >> SPI_RXFTLR_RFT_Pos)   /*!< RFT Get Value */

/* TXFLR bitfield */
#define SPI_TXFLR_TXTFL_Pos     (0U)                                                              /*!< TXTFL Position 0 */
#define SPI_TXFLR_TXTFL_Msk     (0x1fU << SPI_TXFLR_TXTFL_Pos)                                    /*!< TXTFL Mask 0x0000001F */
#define SPI_TXFLR_TXTFL_Set(x)  (((uint32_t) (x) << SPI_TXFLR_TXTFL_Pos) & SPI_TXFLR_TXTFL_Msk)   /*!< TXTFL Set Value */
#define SPI_TXFLR_TXTFL_Get(x)  (((uint32_t) (x) & SPI_TXFLR_TXTFL_Msk) >> SPI_TXFLR_TXTFL_Pos)   /*!< TXTFL Get Value */

/* RXFLR bitfield */
#define SPI_RXFLR_RXTFL_Pos     (0U)                                                              /*!< RXTFL Position 0 */
#define SPI_RXFLR_RXTFL_Msk     (0xffU << SPI_RXFLR_RXTFL_Pos)                                    /*!< RXTFL Mask 0x000000FF */
#define SPI_RXFLR_RXTFL_Set(x)  (((uint32_t) (x) << SPI_RXFLR_RXTFL_Pos) & SPI_RXFLR_RXTFL_Msk)   /*!< RXTFL Set Value */
#define SPI_RXFLR_RXTFL_Get(x)  (((uint32_t) (x) & SPI_RXFLR_RXTFL_Msk) >> SPI_RXFLR_RXTFL_Pos)   /*!< RXTFL Get Value */

/* SR bitfield */
#define SPI_SR_TXE_Pos     (5U)                                                    /*!< TXE Position 5 */
#define SPI_SR_TXE_Msk     (0x1U << SPI_SR_TXE_Pos)                                /*!< TXE Mask 0x00000020 */
#define SPI_SR_TXE_Set(x)  (((uint32_t) (x) << SPI_SR_TXE_Pos) & SPI_SR_TXE_Msk)   /*!< TXE Set Value */
#define SPI_SR_TXE_Get(x)  (((uint32_t) (x) & SPI_SR_TXE_Msk) >> SPI_SR_TXE_Pos)   /*!< TXE Get Value */

#define SPI_SR_RFF_Pos     (4U)                                                    /*!< RFF Position 4 */
#define SPI_SR_RFF_Msk     (0x1U << SPI_SR_RFF_Pos)                                /*!< RFF Mask 0x00000010 */
#define SPI_SR_RFF_Set(x)  (((uint32_t) (x) << SPI_SR_RFF_Pos) & SPI_SR_RFF_Msk)   /*!< RFF Set Value */
#define SPI_SR_RFF_Get(x)  (((uint32_t) (x) & SPI_SR_RFF_Msk) >> SPI_SR_RFF_Pos)   /*!< RFF Get Value */

#define SPI_SR_RFNE_Pos     (3U)                                                      /*!< RFNE Position 3 */
#define SPI_SR_RFNE_Msk     (0x1U << SPI_SR_RFNE_Pos)                                 /*!< RFNE Mask 0x00000008 */
#define SPI_SR_RFNE_Set(x)  (((uint32_t) (x) << SPI_SR_RFNE_Pos) & SPI_SR_RFNE_Msk)   /*!< RFNE Set Value */
#define SPI_SR_RFNE_Get(x)  (((uint32_t) (x) & SPI_SR_RFNE_Msk) >> SPI_SR_RFNE_Pos)   /*!< RFNE Get Value */

#define SPI_SR_TFE_Pos     (2U)                                                    /*!< TFE Position 2 */
#define SPI_SR_TFE_Msk     (0x1U << SPI_SR_TFE_Pos)                                /*!< TFE Mask 0x00000004 */
#define SPI_SR_TFE_Set(x)  (((uint32_t) (x) << SPI_SR_TFE_Pos) & SPI_SR_TFE_Msk)   /*!< TFE Set Value */
#define SPI_SR_TFE_Get(x)  (((uint32_t) (x) & SPI_SR_TFE_Msk) >> SPI_SR_TFE_Pos)   /*!< TFE Get Value */

#define SPI_SR_TFNF_Pos     (1U)                                                      /*!< TFNF Position 1 */
#define SPI_SR_TFNF_Msk     (0x1U << SPI_SR_TFNF_Pos)                                 /*!< TFNF Mask 0x00000002 */
#define SPI_SR_TFNF_Set(x)  (((uint32_t) (x) << SPI_SR_TFNF_Pos) & SPI_SR_TFNF_Msk)   /*!< TFNF Set Value */
#define SPI_SR_TFNF_Get(x)  (((uint32_t) (x) & SPI_SR_TFNF_Msk) >> SPI_SR_TFNF_Pos)   /*!< TFNF Get Value */

#define SPI_SR_BUSY_Pos     (0U)                                                      /*!< BUSY Position 0 */
#define SPI_SR_BUSY_Msk     (0x1U << SPI_SR_BUSY_Pos)                                 /*!< BUSY Mask 0x00000001 */
#define SPI_SR_BUSY_Set(x)  (((uint32_t) (x) << SPI_SR_BUSY_Pos) & SPI_SR_BUSY_Msk)   /*!< BUSY Set Value */
#define SPI_SR_BUSY_Get(x)  (((uint32_t) (x) & SPI_SR_BUSY_Msk) >> SPI_SR_BUSY_Pos)   /*!< BUSY Get Value */

/* IMR bitfield */
#define SPI_IMR_TXUIM_Pos     (7U)                                                          /*!< TXUIM Position 7 */
#define SPI_IMR_TXUIM_Msk     (0x1U << SPI_IMR_TXUIM_Pos)                                   /*!< TXUIM Mask 0x00000080 */
#define SPI_IMR_TXUIM_Set(x)  (((uint32_t) (x) << SPI_IMR_TXUIM_Pos) & SPI_IMR_TXUIM_Msk)   /*!< TXUIM Set Value */
#define SPI_IMR_TXUIM_Get(x)  (((uint32_t) (x) & SPI_IMR_TXUIM_Msk) >> SPI_IMR_TXUIM_Pos)   /*!< TXUIM Get Value */

#define SPI_IMR_XRXOIM_Pos     (6U)                                                            /*!< XRXOIM Position 6 */
#define SPI_IMR_XRXOIM_Msk     (0x1U << SPI_IMR_XRXOIM_Pos)                                    /*!< XRXOIM Mask 0x00000040 */
#define SPI_IMR_XRXOIM_Set(x)  (((uint32_t) (x) << SPI_IMR_XRXOIM_Pos) & SPI_IMR_XRXOIM_Msk)   /*!< XRXOIM Set Value */
#define SPI_IMR_XRXOIM_Get(x)  (((uint32_t) (x) & SPI_IMR_XRXOIM_Msk) >> SPI_IMR_XRXOIM_Pos)   /*!< XRXOIM Get Value */

#define SPI_IMR_MSTIM_Pos     (5U)                                                          /*!< MSTIM Position 5 */
#define SPI_IMR_MSTIM_Msk     (0x1U << SPI_IMR_MSTIM_Pos)                                   /*!< MSTIM Mask 0x00000020 */
#define SPI_IMR_MSTIM_Set(x)  (((uint32_t) (x) << SPI_IMR_MSTIM_Pos) & SPI_IMR_MSTIM_Msk)   /*!< MSTIM Set Value */
#define SPI_IMR_MSTIM_Get(x)  (((uint32_t) (x) & SPI_IMR_MSTIM_Msk) >> SPI_IMR_MSTIM_Pos)   /*!< MSTIM Get Value */

#define SPI_IMR_RXFIM_Pos     (4U)                                                          /*!< RXFIM Position 4 */
#define SPI_IMR_RXFIM_Msk     (0x1U << SPI_IMR_RXFIM_Pos)                                   /*!< RXFIM Mask 0x00000010 */
#define SPI_IMR_RXFIM_Set(x)  (((uint32_t) (x) << SPI_IMR_RXFIM_Pos) & SPI_IMR_RXFIM_Msk)   /*!< RXFIM Set Value */
#define SPI_IMR_RXFIM_Get(x)  (((uint32_t) (x) & SPI_IMR_RXFIM_Msk) >> SPI_IMR_RXFIM_Pos)   /*!< RXFIM Get Value */

#define SPI_IMR_RXOIM_Pos     (3U)                                                          /*!< RXOIM Position 3 */
#define SPI_IMR_RXOIM_Msk     (0x1U << SPI_IMR_RXOIM_Pos)                                   /*!< RXOIM Mask 0x00000008 */
#define SPI_IMR_RXOIM_Set(x)  (((uint32_t) (x) << SPI_IMR_RXOIM_Pos) & SPI_IMR_RXOIM_Msk)   /*!< RXOIM Set Value */
#define SPI_IMR_RXOIM_Get(x)  (((uint32_t) (x) & SPI_IMR_RXOIM_Msk) >> SPI_IMR_RXOIM_Pos)   /*!< RXOIM Get Value */

#define SPI_IMR_RXUIM_Pos     (2U)                                                          /*!< RXUIM Position 2 */
#define SPI_IMR_RXUIM_Msk     (0x1U << SPI_IMR_RXUIM_Pos)                                   /*!< RXUIM Mask 0x00000004 */
#define SPI_IMR_RXUIM_Set(x)  (((uint32_t) (x) << SPI_IMR_RXUIM_Pos) & SPI_IMR_RXUIM_Msk)   /*!< RXUIM Set Value */
#define SPI_IMR_RXUIM_Get(x)  (((uint32_t) (x) & SPI_IMR_RXUIM_Msk) >> SPI_IMR_RXUIM_Pos)   /*!< RXUIM Get Value */

#define SPI_IMR_TXOIM_Pos     (1U)                                                          /*!< TXOIM Position 1 */
#define SPI_IMR_TXOIM_Msk     (0x1U << SPI_IMR_TXOIM_Pos)                                   /*!< TXOIM Mask 0x00000002 */
#define SPI_IMR_TXOIM_Set(x)  (((uint32_t) (x) << SPI_IMR_TXOIM_Pos) & SPI_IMR_TXOIM_Msk)   /*!< TXOIM Set Value */
#define SPI_IMR_TXOIM_Get(x)  (((uint32_t) (x) & SPI_IMR_TXOIM_Msk) >> SPI_IMR_TXOIM_Pos)   /*!< TXOIM Get Value */

#define SPI_IMR_TXEIM_Pos     (0U)                                                          /*!< TXEIM Position 0 */
#define SPI_IMR_TXEIM_Msk     (0x1U << SPI_IMR_TXEIM_Pos)                                   /*!< TXEIM Mask 0x00000001 */
#define SPI_IMR_TXEIM_Set(x)  (((uint32_t) (x) << SPI_IMR_TXEIM_Pos) & SPI_IMR_TXEIM_Msk)   /*!< TXEIM Set Value */
#define SPI_IMR_TXEIM_Get(x)  (((uint32_t) (x) & SPI_IMR_TXEIM_Msk) >> SPI_IMR_TXEIM_Pos)   /*!< TXEIM Get Value */

/* ISR bitfield */
#define SPI_ISR_TXUIS_Pos     (7U)                                                          /*!< TXUIS Position 7 */
#define SPI_ISR_TXUIS_Msk     (0x1U << SPI_ISR_TXUIS_Pos)                                   /*!< TXUIS Mask 0x00000080 */
#define SPI_ISR_TXUIS_Set(x)  (((uint32_t) (x) << SPI_ISR_TXUIS_Pos) & SPI_ISR_TXUIS_Msk)   /*!< TXUIS Set Value */
#define SPI_ISR_TXUIS_Get(x)  (((uint32_t) (x) & SPI_ISR_TXUIS_Msk) >> SPI_ISR_TXUIS_Pos)   /*!< TXUIS Get Value */

#define SPI_ISR_XRXOIS_Pos     (6U)                                                            /*!< XRXOIS Position 6 */
#define SPI_ISR_XRXOIS_Msk     (0x1U << SPI_ISR_XRXOIS_Pos)                                    /*!< XRXOIS Mask 0x00000040 */
#define SPI_ISR_XRXOIS_Set(x)  (((uint32_t) (x) << SPI_ISR_XRXOIS_Pos) & SPI_ISR_XRXOIS_Msk)   /*!< XRXOIS Set Value */
#define SPI_ISR_XRXOIS_Get(x)  (((uint32_t) (x) & SPI_ISR_XRXOIS_Msk) >> SPI_ISR_XRXOIS_Pos)   /*!< XRXOIS Get Value */

#define SPI_ISR_MSTIS_Pos     (5U)                                                          /*!< MSTIS Position 5 */
#define SPI_ISR_MSTIS_Msk     (0x1U << SPI_ISR_MSTIS_Pos)                                   /*!< MSTIS Mask 0x00000020 */
#define SPI_ISR_MSTIS_Set(x)  (((uint32_t) (x) << SPI_ISR_MSTIS_Pos) & SPI_ISR_MSTIS_Msk)   /*!< MSTIS Set Value */
#define SPI_ISR_MSTIS_Get(x)  (((uint32_t) (x) & SPI_ISR_MSTIS_Msk) >> SPI_ISR_MSTIS_Pos)   /*!< MSTIS Get Value */

#define SPI_ISR_RXFIS_Pos     (4U)                                                          /*!< RXFIS Position 4 */
#define SPI_ISR_RXFIS_Msk     (0x1U << SPI_ISR_RXFIS_Pos)                                   /*!< RXFIS Mask 0x00000010 */
#define SPI_ISR_RXFIS_Set(x)  (((uint32_t) (x) << SPI_ISR_RXFIS_Pos) & SPI_ISR_RXFIS_Msk)   /*!< RXFIS Set Value */
#define SPI_ISR_RXFIS_Get(x)  (((uint32_t) (x) & SPI_ISR_RXFIS_Msk) >> SPI_ISR_RXFIS_Pos)   /*!< RXFIS Get Value */

#define SPI_ISR_RXOIS_Pos     (3U)                                                          /*!< RXOIS Position 3 */
#define SPI_ISR_RXOIS_Msk     (0x1U << SPI_ISR_RXOIS_Pos)                                   /*!< RXOIS Mask 0x00000008 */
#define SPI_ISR_RXOIS_Set(x)  (((uint32_t) (x) << SPI_ISR_RXOIS_Pos) & SPI_ISR_RXOIS_Msk)   /*!< RXOIS Set Value */
#define SPI_ISR_RXOIS_Get(x)  (((uint32_t) (x) & SPI_ISR_RXOIS_Msk) >> SPI_ISR_RXOIS_Pos)   /*!< RXOIS Get Value */

#define SPI_ISR_RXUIS_Pos     (2U)                                                          /*!< RXUIS Position 2 */
#define SPI_ISR_RXUIS_Msk     (0x1U << SPI_ISR_RXUIS_Pos)                                   /*!< RXUIS Mask 0x00000004 */
#define SPI_ISR_RXUIS_Set(x)  (((uint32_t) (x) << SPI_ISR_RXUIS_Pos) & SPI_ISR_RXUIS_Msk)   /*!< RXUIS Set Value */
#define SPI_ISR_RXUIS_Get(x)  (((uint32_t) (x) & SPI_ISR_RXUIS_Msk) >> SPI_ISR_RXUIS_Pos)   /*!< RXUIS Get Value */

#define SPI_ISR_TXOIS_Pos     (1U)                                                          /*!< TXOIS Position 1 */
#define SPI_ISR_TXOIS_Msk     (0x1U << SPI_ISR_TXOIS_Pos)                                   /*!< TXOIS Mask 0x00000002 */
#define SPI_ISR_TXOIS_Set(x)  (((uint32_t) (x) << SPI_ISR_TXOIS_Pos) & SPI_ISR_TXOIS_Msk)   /*!< TXOIS Set Value */
#define SPI_ISR_TXOIS_Get(x)  (((uint32_t) (x) & SPI_ISR_TXOIS_Msk) >> SPI_ISR_TXOIS_Pos)   /*!< TXOIS Get Value */

#define SPI_ISR_TXEIS_Pos     (0U)                                                          /*!< TXEIS Position 0 */
#define SPI_ISR_TXEIS_Msk     (0x1U << SPI_ISR_TXEIS_Pos)                                   /*!< TXEIS Mask 0x00000001 */
#define SPI_ISR_TXEIS_Set(x)  (((uint32_t) (x) << SPI_ISR_TXEIS_Pos) & SPI_ISR_TXEIS_Msk)   /*!< TXEIS Set Value */
#define SPI_ISR_TXEIS_Get(x)  (((uint32_t) (x) & SPI_ISR_TXEIS_Msk) >> SPI_ISR_TXEIS_Pos)   /*!< TXEIS Get Value */

/* RISR bitfield */
#define SPI_RISR_TXUIR_Pos     (7U)                                                            /*!< TXUIR Position 7 */
#define SPI_RISR_TXUIR_Msk     (0x1U << SPI_RISR_TXUIR_Pos)                                    /*!< TXUIR Mask 0x00000080 */
#define SPI_RISR_TXUIR_Set(x)  (((uint32_t) (x) << SPI_RISR_TXUIR_Pos) & SPI_RISR_TXUIR_Msk)   /*!< TXUIR Set Value */
#define SPI_RISR_TXUIR_Get(x)  (((uint32_t) (x) & SPI_RISR_TXUIR_Msk) >> SPI_RISR_TXUIR_Pos)   /*!< TXUIR Get Value */

#define SPI_RISR_XRXOIR_Pos     (6U)                                                              /*!< XRXOIR Position 6 */
#define SPI_RISR_XRXOIR_Msk     (0x1U << SPI_RISR_XRXOIR_Pos)                                     /*!< XRXOIR Mask 0x00000040 */
#define SPI_RISR_XRXOIR_Set(x)  (((uint32_t) (x) << SPI_RISR_XRXOIR_Pos) & SPI_RISR_XRXOIR_Msk)   /*!< XRXOIR Set Value */
#define SPI_RISR_XRXOIR_Get(x)  (((uint32_t) (x) & SPI_RISR_XRXOIR_Msk) >> SPI_RISR_XRXOIR_Pos)   /*!< XRXOIR Get Value */

#define SPI_RISR_MSTIR_Pos     (5U)                                                            /*!< MSTIR Position 5 */
#define SPI_RISR_MSTIR_Msk     (0x1U << SPI_RISR_MSTIR_Pos)                                    /*!< MSTIR Mask 0x00000020 */
#define SPI_RISR_MSTIR_Set(x)  (((uint32_t) (x) << SPI_RISR_MSTIR_Pos) & SPI_RISR_MSTIR_Msk)   /*!< MSTIR Set Value */
#define SPI_RISR_MSTIR_Get(x)  (((uint32_t) (x) & SPI_RISR_MSTIR_Msk) >> SPI_RISR_MSTIR_Pos)   /*!< MSTIR Get Value */

#define SPI_RISR_RXFIR_Pos     (4U)                                                            /*!< RXFIR Position 4 */
#define SPI_RISR_RXFIR_Msk     (0x1U << SPI_RISR_RXFIR_Pos)                                    /*!< RXFIR Mask 0x00000010 */
#define SPI_RISR_RXFIR_Set(x)  (((uint32_t) (x) << SPI_RISR_RXFIR_Pos) & SPI_RISR_RXFIR_Msk)   /*!< RXFIR Set Value */
#define SPI_RISR_RXFIR_Get(x)  (((uint32_t) (x) & SPI_RISR_RXFIR_Msk) >> SPI_RISR_RXFIR_Pos)   /*!< RXFIR Get Value */

#define SPI_RISR_RXOIR_Pos     (3U)                                                            /*!< RXOIR Position 3 */
#define SPI_RISR_RXOIR_Msk     (0x1U << SPI_RISR_RXOIR_Pos)                                    /*!< RXOIR Mask 0x00000008 */
#define SPI_RISR_RXOIR_Set(x)  (((uint32_t) (x) << SPI_RISR_RXOIR_Pos) & SPI_RISR_RXOIR_Msk)   /*!< RXOIR Set Value */
#define SPI_RISR_RXOIR_Get(x)  (((uint32_t) (x) & SPI_RISR_RXOIR_Msk) >> SPI_RISR_RXOIR_Pos)   /*!< RXOIR Get Value */

#define SPI_RISR_RXUIR_Pos     (2U)                                                            /*!< RXUIR Position 2 */
#define SPI_RISR_RXUIR_Msk     (0x1U << SPI_RISR_RXUIR_Pos)                                    /*!< RXUIR Mask 0x00000004 */
#define SPI_RISR_RXUIR_Set(x)  (((uint32_t) (x) << SPI_RISR_RXUIR_Pos) & SPI_RISR_RXUIR_Msk)   /*!< RXUIR Set Value */
#define SPI_RISR_RXUIR_Get(x)  (((uint32_t) (x) & SPI_RISR_RXUIR_Msk) >> SPI_RISR_RXUIR_Pos)   /*!< RXUIR Get Value */

#define SPI_RISR_TXOIR_Pos     (1U)                                                            /*!< TXOIR Position 1 */
#define SPI_RISR_TXOIR_Msk     (0x1U << SPI_RISR_TXOIR_Pos)                                    /*!< TXOIR Mask 0x00000002 */
#define SPI_RISR_TXOIR_Set(x)  (((uint32_t) (x) << SPI_RISR_TXOIR_Pos) & SPI_RISR_TXOIR_Msk)   /*!< TXOIR Set Value */
#define SPI_RISR_TXOIR_Get(x)  (((uint32_t) (x) & SPI_RISR_TXOIR_Msk) >> SPI_RISR_TXOIR_Pos)   /*!< TXOIR Get Value */

#define SPI_RISR_TXEIR_Pos     (0U)                                                            /*!< TXEIR Position 0 */
#define SPI_RISR_TXEIR_Msk     (0x1U << SPI_RISR_TXEIR_Pos)                                    /*!< TXEIR Mask 0x00000001 */
#define SPI_RISR_TXEIR_Set(x)  (((uint32_t) (x) << SPI_RISR_TXEIR_Pos) & SPI_RISR_TXEIR_Msk)   /*!< TXEIR Set Value */
#define SPI_RISR_TXEIR_Get(x)  (((uint32_t) (x) & SPI_RISR_TXEIR_Msk) >> SPI_RISR_TXEIR_Pos)   /*!< TXEIR Get Value */

/* TXEICR bitfield */
#define SPI_TXEICR_TXEICR_Pos     (0U)                                                                  /*!< TXEICR Position 0 */
#define SPI_TXEICR_TXEICR_Msk     (0x1U << SPI_TXEICR_TXEICR_Pos)                                       /*!< TXEICR Mask 0x00000001 */
#define SPI_TXEICR_TXEICR_Set(x)  (((uint32_t) (x) << SPI_TXEICR_TXEICR_Pos) & SPI_TXEICR_TXEICR_Msk)   /*!< TXEICR Set Value */
#define SPI_TXEICR_TXEICR_Get(x)  (((uint32_t) (x) & SPI_TXEICR_TXEICR_Msk) >> SPI_TXEICR_TXEICR_Pos)   /*!< TXEICR Get Value */

/* RXOICR bitfield */
#define SPI_RXOICR_RXOICR_Pos     (0U)                                                                  /*!< RXOICR Position 0 */
#define SPI_RXOICR_RXOICR_Msk     (0x1U << SPI_RXOICR_RXOICR_Pos)                                       /*!< RXOICR Mask 0x00000001 */
#define SPI_RXOICR_RXOICR_Set(x)  (((uint32_t) (x) << SPI_RXOICR_RXOICR_Pos) & SPI_RXOICR_RXOICR_Msk)   /*!< RXOICR Set Value */
#define SPI_RXOICR_RXOICR_Get(x)  (((uint32_t) (x) & SPI_RXOICR_RXOICR_Msk) >> SPI_RXOICR_RXOICR_Pos)   /*!< RXOICR Get Value */

/* RXUICR bitfield */
#define SPI_RXUICR_RXUICR_Pos     (0U)                                                                  /*!< RXUICR Position 0 */
#define SPI_RXUICR_RXUICR_Msk     (0x1U << SPI_RXUICR_RXUICR_Pos)                                       /*!< RXUICR Mask 0x00000001 */
#define SPI_RXUICR_RXUICR_Set(x)  (((uint32_t) (x) << SPI_RXUICR_RXUICR_Pos) & SPI_RXUICR_RXUICR_Msk)   /*!< RXUICR Set Value */
#define SPI_RXUICR_RXUICR_Get(x)  (((uint32_t) (x) & SPI_RXUICR_RXUICR_Msk) >> SPI_RXUICR_RXUICR_Pos)   /*!< RXUICR Get Value */

/* MSTICR bitfield */
#define SPI_MSTICR_MSTICR_Pos     (0U)                                                                  /*!< MSTICR Position 0 */
#define SPI_MSTICR_MSTICR_Msk     (0x1U << SPI_MSTICR_MSTICR_Pos)                                       /*!< MSTICR Mask 0x00000001 */
#define SPI_MSTICR_MSTICR_Set(x)  (((uint32_t) (x) << SPI_MSTICR_MSTICR_Pos) & SPI_MSTICR_MSTICR_Msk)   /*!< MSTICR Set Value */
#define SPI_MSTICR_MSTICR_Get(x)  (((uint32_t) (x) & SPI_MSTICR_MSTICR_Msk) >> SPI_MSTICR_MSTICR_Pos)   /*!< MSTICR Get Value */

/* ICR bitfield */
#define SPI_ICR_ICR_Pos     (0U)                                                      /*!< ICR Position 0 */
#define SPI_ICR_ICR_Msk     (0x1U << SPI_ICR_ICR_Pos)                                 /*!< ICR Mask 0x00000001 */
#define SPI_ICR_ICR_Set(x)  (((uint32_t) (x) << SPI_ICR_ICR_Pos) & SPI_ICR_ICR_Msk)   /*!< ICR Set Value */
#define SPI_ICR_ICR_Get(x)  (((uint32_t) (x) & SPI_ICR_ICR_Msk) >> SPI_ICR_ICR_Pos)   /*!< ICR Get Value */

/* DMACR bitfield */
#define SPI_DMACR_TDMAE_Pos     (1U)                                                              /*!< TDMAE Position 1 */
#define SPI_DMACR_TDMAE_Msk     (0x1U << SPI_DMACR_TDMAE_Pos)                                     /*!< TDMAE Mask 0x00000002 */
#define SPI_DMACR_TDMAE_Set(x)  (((uint32_t) (x) << SPI_DMACR_TDMAE_Pos) & SPI_DMACR_TDMAE_Msk)   /*!< TDMAE Set Value */
#define SPI_DMACR_TDMAE_Get(x)  (((uint32_t) (x) & SPI_DMACR_TDMAE_Msk) >> SPI_DMACR_TDMAE_Pos)   /*!< TDMAE Get Value */

#define SPI_DMACR_RDMAE_Pos     (0U)                                                              /*!< RDMAE Position 0 */
#define SPI_DMACR_RDMAE_Msk     (0x1U << SPI_DMACR_RDMAE_Pos)                                     /*!< RDMAE Mask 0x00000001 */
#define SPI_DMACR_RDMAE_Set(x)  (((uint32_t) (x) << SPI_DMACR_RDMAE_Pos) & SPI_DMACR_RDMAE_Msk)   /*!< RDMAE Set Value */
#define SPI_DMACR_RDMAE_Get(x)  (((uint32_t) (x) & SPI_DMACR_RDMAE_Msk) >> SPI_DMACR_RDMAE_Pos)   /*!< RDMAE Get Value */

/* DMATDLR bitfield */
#define SPI_DMATDLR_DMATDL_Pos     (0U)                                                                    /*!< DMATDL Position 0 */
#define SPI_DMATDLR_DMATDL_Msk     (0x1fU << SPI_DMATDLR_DMATDL_Pos)                                       /*!< DMATDL Mask 0x0000001F */
#define SPI_DMATDLR_DMATDL_Set(x)  (((uint32_t) (x) << SPI_DMATDLR_DMATDL_Pos) & SPI_DMATDLR_DMATDL_Msk)   /*!< DMATDL Set Value */
#define SPI_DMATDLR_DMATDL_Get(x)  (((uint32_t) (x) & SPI_DMATDLR_DMATDL_Msk) >> SPI_DMATDLR_DMATDL_Pos)   /*!< DMATDL Get Value */

/* DMARDLR bitfield */
#define SPI_DMARDLR_DMARDL_Pos     (0U)                                                                    /*!< DMARDL Position 0 */
#define SPI_DMARDLR_DMARDL_Msk     (0xffU << SPI_DMARDLR_DMARDL_Pos)                                       /*!< DMARDL Mask 0x000000FF */
#define SPI_DMARDLR_DMARDL_Set(x)  (((uint32_t) (x) << SPI_DMARDLR_DMARDL_Pos) & SPI_DMARDLR_DMARDL_Msk)   /*!< DMARDL Set Value */
#define SPI_DMARDLR_DMARDL_Get(x)  (((uint32_t) (x) & SPI_DMARDLR_DMARDL_Msk) >> SPI_DMARDLR_DMARDL_Pos)   /*!< DMARDL Get Value */

/* IDR bitfield */
#define SPI_IDR_IDCODE_Pos     (0U)                                                            /*!< IDCODE Position 0 */
#define SPI_IDR_IDCODE_Msk     (0xffffffffU << SPI_IDR_IDCODE_Pos)                             /*!< IDCODE Mask 0xFFFFFFFF */
#define SPI_IDR_IDCODE_Set(x)  (((uint32_t) (x) << SPI_IDR_IDCODE_Pos) & SPI_IDR_IDCODE_Msk)   /*!< IDCODE Set Value */
#define SPI_IDR_IDCODE_Get(x)  (((uint32_t) (x) & SPI_IDR_IDCODE_Msk) >> SPI_IDR_IDCODE_Pos)   /*!< IDCODE Get Value */

/* VERSION_ID bitfield */
#define SPI_VERSION_ID_SPIC_COMP_VERSION_Pos     (0U)                                                                                                /*!< SPIC_COMP_VERSION Position 0 */
#define SPI_VERSION_ID_SPIC_COMP_VERSION_Msk     (0xffffffffU << SPI_VERSION_ID_SPIC_COMP_VERSION_Pos)                                               /*!< SPIC_COMP_VERSION Mask 0xFFFFFFFF */
#define SPI_VERSION_ID_SPIC_COMP_VERSION_Set(x)  (((uint32_t) (x) << SPI_VERSION_ID_SPIC_COMP_VERSION_Pos) & SPI_VERSION_ID_SPIC_COMP_VERSION_Msk)   /*!< SPIC_COMP_VERSION Set Value */
#define SPI_VERSION_ID_SPIC_COMP_VERSION_Get(x)  (((uint32_t) (x) & SPI_VERSION_ID_SPIC_COMP_VERSION_Msk) >> SPI_VERSION_ID_SPIC_COMP_VERSION_Pos)   /*!< SPIC_COMP_VERSION Get Value */

/* DR0 bitfield */
#define SPI_DR0_DR_Pos     (0U)                                                    /*!< DR Position 0 */
#define SPI_DR0_DR_Msk     (0xffffffffU << SPI_DR0_DR_Pos)                         /*!< DR Mask 0xFFFFFFFF */
#define SPI_DR0_DR_Set(x)  (((uint32_t) (x) << SPI_DR0_DR_Pos) & SPI_DR0_DR_Msk)   /*!< DR Set Value */
#define SPI_DR0_DR_Get(x)  (((uint32_t) (x) & SPI_DR0_DR_Msk) >> SPI_DR0_DR_Pos)   /*!< DR Get Value */

/* DR1 bitfield */
#define SPI_DR1_DR_Pos     (0U)                                                    /*!< DR Position 0 */
#define SPI_DR1_DR_Msk     (0xffffffffU << SPI_DR1_DR_Pos)                         /*!< DR Mask 0xFFFFFFFF */
#define SPI_DR1_DR_Set(x)  (((uint32_t) (x) << SPI_DR1_DR_Pos) & SPI_DR1_DR_Msk)   /*!< DR Set Value */
#define SPI_DR1_DR_Get(x)  (((uint32_t) (x) & SPI_DR1_DR_Msk) >> SPI_DR1_DR_Pos)   /*!< DR Get Value */

/* DR2 bitfield */
#define SPI_DR2_DR_Pos     (0U)                                                    /*!< DR Position 0 */
#define SPI_DR2_DR_Msk     (0xffffffffU << SPI_DR2_DR_Pos)                         /*!< DR Mask 0xFFFFFFFF */
#define SPI_DR2_DR_Set(x)  (((uint32_t) (x) << SPI_DR2_DR_Pos) & SPI_DR2_DR_Msk)   /*!< DR Set Value */
#define SPI_DR2_DR_Get(x)  (((uint32_t) (x) & SPI_DR2_DR_Msk) >> SPI_DR2_DR_Pos)   /*!< DR Get Value */

/* DR3 bitfield */
#define SPI_DR3_DR_Pos     (0U)                                                    /*!< DR Position 0 */
#define SPI_DR3_DR_Msk     (0xffffffffU << SPI_DR3_DR_Pos)                         /*!< DR Mask 0xFFFFFFFF */
#define SPI_DR3_DR_Set(x)  (((uint32_t) (x) << SPI_DR3_DR_Pos) & SPI_DR3_DR_Msk)   /*!< DR Set Value */
#define SPI_DR3_DR_Get(x)  (((uint32_t) (x) & SPI_DR3_DR_Msk) >> SPI_DR3_DR_Pos)   /*!< DR Get Value */

/* DR4 bitfield */
#define SPI_DR4_DR_Pos     (0U)                                                    /*!< DR Position 0 */
#define SPI_DR4_DR_Msk     (0xffffffffU << SPI_DR4_DR_Pos)                         /*!< DR Mask 0xFFFFFFFF */
#define SPI_DR4_DR_Set(x)  (((uint32_t) (x) << SPI_DR4_DR_Pos) & SPI_DR4_DR_Msk)   /*!< DR Set Value */
#define SPI_DR4_DR_Get(x)  (((uint32_t) (x) & SPI_DR4_DR_Msk) >> SPI_DR4_DR_Pos)   /*!< DR Get Value */

/* DR5 bitfield */
#define SPI_DR5_DR_Pos     (0U)                                                    /*!< DR Position 0 */
#define SPI_DR5_DR_Msk     (0xffffffffU << SPI_DR5_DR_Pos)                         /*!< DR Mask 0xFFFFFFFF */
#define SPI_DR5_DR_Set(x)  (((uint32_t) (x) << SPI_DR5_DR_Pos) & SPI_DR5_DR_Msk)   /*!< DR Set Value */
#define SPI_DR5_DR_Get(x)  (((uint32_t) (x) & SPI_DR5_DR_Msk) >> SPI_DR5_DR_Pos)   /*!< DR Get Value */

/* DR6 bitfield */
#define SPI_DR6_DR_Pos     (0U)                                                    /*!< DR Position 0 */
#define SPI_DR6_DR_Msk     (0xffffffffU << SPI_DR6_DR_Pos)                         /*!< DR Mask 0xFFFFFFFF */
#define SPI_DR6_DR_Set(x)  (((uint32_t) (x) << SPI_DR6_DR_Pos) & SPI_DR6_DR_Msk)   /*!< DR Set Value */
#define SPI_DR6_DR_Get(x)  (((uint32_t) (x) & SPI_DR6_DR_Msk) >> SPI_DR6_DR_Pos)   /*!< DR Get Value */

/* DR7 bitfield */
#define SPI_DR7_DR_Pos     (0U)                                                    /*!< DR Position 0 */
#define SPI_DR7_DR_Msk     (0xffffffffU << SPI_DR7_DR_Pos)                         /*!< DR Mask 0xFFFFFFFF */
#define SPI_DR7_DR_Set(x)  (((uint32_t) (x) << SPI_DR7_DR_Pos) & SPI_DR7_DR_Msk)   /*!< DR Set Value */
#define SPI_DR7_DR_Get(x)  (((uint32_t) (x) & SPI_DR7_DR_Msk) >> SPI_DR7_DR_Pos)   /*!< DR Get Value */

/* DR8 bitfield */
#define SPI_DR8_DR_Pos     (0U)                                                    /*!< DR Position 0 */
#define SPI_DR8_DR_Msk     (0xffffffffU << SPI_DR8_DR_Pos)                         /*!< DR Mask 0xFFFFFFFF */
#define SPI_DR8_DR_Set(x)  (((uint32_t) (x) << SPI_DR8_DR_Pos) & SPI_DR8_DR_Msk)   /*!< DR Set Value */
#define SPI_DR8_DR_Get(x)  (((uint32_t) (x) & SPI_DR8_DR_Msk) >> SPI_DR8_DR_Pos)   /*!< DR Get Value */

/* DR9 bitfield */
#define SPI_DR9_DR_Pos     (0U)                                                    /*!< DR Position 0 */
#define SPI_DR9_DR_Msk     (0xffffffffU << SPI_DR9_DR_Pos)                         /*!< DR Mask 0xFFFFFFFF */
#define SPI_DR9_DR_Set(x)  (((uint32_t) (x) << SPI_DR9_DR_Pos) & SPI_DR9_DR_Msk)   /*!< DR Set Value */
#define SPI_DR9_DR_Get(x)  (((uint32_t) (x) & SPI_DR9_DR_Msk) >> SPI_DR9_DR_Pos)   /*!< DR Get Value */

/* DR10 bitfield */
#define SPI_DR10_DR_Pos     (0U)                                                      /*!< DR Position 0 */
#define SPI_DR10_DR_Msk     (0xffffffffU << SPI_DR10_DR_Pos)                          /*!< DR Mask 0xFFFFFFFF */
#define SPI_DR10_DR_Set(x)  (((uint32_t) (x) << SPI_DR10_DR_Pos) & SPI_DR10_DR_Msk)   /*!< DR Set Value */
#define SPI_DR10_DR_Get(x)  (((uint32_t) (x) & SPI_DR10_DR_Msk) >> SPI_DR10_DR_Pos)   /*!< DR Get Value */

/* DR11 bitfield */
#define SPI_DR11_DR_Pos     (0U)                                                      /*!< DR Position 0 */
#define SPI_DR11_DR_Msk     (0xffffffffU << SPI_DR11_DR_Pos)                          /*!< DR Mask 0xFFFFFFFF */
#define SPI_DR11_DR_Set(x)  (((uint32_t) (x) << SPI_DR11_DR_Pos) & SPI_DR11_DR_Msk)   /*!< DR Set Value */
#define SPI_DR11_DR_Get(x)  (((uint32_t) (x) & SPI_DR11_DR_Msk) >> SPI_DR11_DR_Pos)   /*!< DR Get Value */

/* DR12 bitfield */
#define SPI_DR12_DR_Pos     (0U)                                                      /*!< DR Position 0 */
#define SPI_DR12_DR_Msk     (0xffffffffU << SPI_DR12_DR_Pos)                          /*!< DR Mask 0xFFFFFFFF */
#define SPI_DR12_DR_Set(x)  (((uint32_t) (x) << SPI_DR12_DR_Pos) & SPI_DR12_DR_Msk)   /*!< DR Set Value */
#define SPI_DR12_DR_Get(x)  (((uint32_t) (x) & SPI_DR12_DR_Msk) >> SPI_DR12_DR_Pos)   /*!< DR Get Value */

/* DR13 bitfield */
#define SPI_DR13_DR_Pos     (0U)                                                      /*!< DR Position 0 */
#define SPI_DR13_DR_Msk     (0xffffffffU << SPI_DR13_DR_Pos)                          /*!< DR Mask 0xFFFFFFFF */
#define SPI_DR13_DR_Set(x)  (((uint32_t) (x) << SPI_DR13_DR_Pos) & SPI_DR13_DR_Msk)   /*!< DR Set Value */
#define SPI_DR13_DR_Get(x)  (((uint32_t) (x) & SPI_DR13_DR_Msk) >> SPI_DR13_DR_Pos)   /*!< DR Get Value */

/* DR14 bitfield */
#define SPI_DR14_DR_Pos     (0U)                                                      /*!< DR Position 0 */
#define SPI_DR14_DR_Msk     (0xffffffffU << SPI_DR14_DR_Pos)                          /*!< DR Mask 0xFFFFFFFF */
#define SPI_DR14_DR_Set(x)  (((uint32_t) (x) << SPI_DR14_DR_Pos) & SPI_DR14_DR_Msk)   /*!< DR Set Value */
#define SPI_DR14_DR_Get(x)  (((uint32_t) (x) & SPI_DR14_DR_Msk) >> SPI_DR14_DR_Pos)   /*!< DR Get Value */

/* DR15 bitfield */
#define SPI_DR15_DR_Pos     (0U)                                                      /*!< DR Position 0 */
#define SPI_DR15_DR_Msk     (0xffffffffU << SPI_DR15_DR_Pos)                          /*!< DR Mask 0xFFFFFFFF */
#define SPI_DR15_DR_Set(x)  (((uint32_t) (x) << SPI_DR15_DR_Pos) & SPI_DR15_DR_Msk)   /*!< DR Set Value */
#define SPI_DR15_DR_Get(x)  (((uint32_t) (x) & SPI_DR15_DR_Msk) >> SPI_DR15_DR_Pos)   /*!< DR Get Value */

/* DR16 bitfield */
#define SPI_DR16_DR_Pos     (0U)                                                      /*!< DR Position 0 */
#define SPI_DR16_DR_Msk     (0xffffffffU << SPI_DR16_DR_Pos)                          /*!< DR Mask 0xFFFFFFFF */
#define SPI_DR16_DR_Set(x)  (((uint32_t) (x) << SPI_DR16_DR_Pos) & SPI_DR16_DR_Msk)   /*!< DR Set Value */
#define SPI_DR16_DR_Get(x)  (((uint32_t) (x) & SPI_DR16_DR_Msk) >> SPI_DR16_DR_Pos)   /*!< DR Get Value */

/* DR17 bitfield */
#define SPI_DR17_DR_Pos     (0U)                                                      /*!< DR Position 0 */
#define SPI_DR17_DR_Msk     (0xffffffffU << SPI_DR17_DR_Pos)                          /*!< DR Mask 0xFFFFFFFF */
#define SPI_DR17_DR_Set(x)  (((uint32_t) (x) << SPI_DR17_DR_Pos) & SPI_DR17_DR_Msk)   /*!< DR Set Value */
#define SPI_DR17_DR_Get(x)  (((uint32_t) (x) & SPI_DR17_DR_Msk) >> SPI_DR17_DR_Pos)   /*!< DR Get Value */

/* DR18 bitfield */
#define SPI_DR18_DR_Pos     (0U)                                                      /*!< DR Position 0 */
#define SPI_DR18_DR_Msk     (0xffffffffU << SPI_DR18_DR_Pos)                          /*!< DR Mask 0xFFFFFFFF */
#define SPI_DR18_DR_Set(x)  (((uint32_t) (x) << SPI_DR18_DR_Pos) & SPI_DR18_DR_Msk)   /*!< DR Set Value */
#define SPI_DR18_DR_Get(x)  (((uint32_t) (x) & SPI_DR18_DR_Msk) >> SPI_DR18_DR_Pos)   /*!< DR Get Value */

/* DR19 bitfield */
#define SPI_DR19_DR_Pos     (0U)                                                      /*!< DR Position 0 */
#define SPI_DR19_DR_Msk     (0xffffffffU << SPI_DR19_DR_Pos)                          /*!< DR Mask 0xFFFFFFFF */
#define SPI_DR19_DR_Set(x)  (((uint32_t) (x) << SPI_DR19_DR_Pos) & SPI_DR19_DR_Msk)   /*!< DR Set Value */
#define SPI_DR19_DR_Get(x)  (((uint32_t) (x) & SPI_DR19_DR_Msk) >> SPI_DR19_DR_Pos)   /*!< DR Get Value */

/* DR20 bitfield */
#define SPI_DR20_DR_Pos     (0U)                                                      /*!< DR Position 0 */
#define SPI_DR20_DR_Msk     (0xffffffffU << SPI_DR20_DR_Pos)                          /*!< DR Mask 0xFFFFFFFF */
#define SPI_DR20_DR_Set(x)  (((uint32_t) (x) << SPI_DR20_DR_Pos) & SPI_DR20_DR_Msk)   /*!< DR Set Value */
#define SPI_DR20_DR_Get(x)  (((uint32_t) (x) & SPI_DR20_DR_Msk) >> SPI_DR20_DR_Pos)   /*!< DR Get Value */

/* DR21 bitfield */
#define SPI_DR21_DR_Pos     (0U)                                                      /*!< DR Position 0 */
#define SPI_DR21_DR_Msk     (0xffffffffU << SPI_DR21_DR_Pos)                          /*!< DR Mask 0xFFFFFFFF */
#define SPI_DR21_DR_Set(x)  (((uint32_t) (x) << SPI_DR21_DR_Pos) & SPI_DR21_DR_Msk)   /*!< DR Set Value */
#define SPI_DR21_DR_Get(x)  (((uint32_t) (x) & SPI_DR21_DR_Msk) >> SPI_DR21_DR_Pos)   /*!< DR Get Value */

/* DR22 bitfield */
#define SPI_DR22_DR_Pos     (0U)                                                      /*!< DR Position 0 */
#define SPI_DR22_DR_Msk     (0xffffffffU << SPI_DR22_DR_Pos)                          /*!< DR Mask 0xFFFFFFFF */
#define SPI_DR22_DR_Set(x)  (((uint32_t) (x) << SPI_DR22_DR_Pos) & SPI_DR22_DR_Msk)   /*!< DR Set Value */
#define SPI_DR22_DR_Get(x)  (((uint32_t) (x) & SPI_DR22_DR_Msk) >> SPI_DR22_DR_Pos)   /*!< DR Get Value */

/* DR23 bitfield */
#define SPI_DR23_DR_Pos     (0U)                                                      /*!< DR Position 0 */
#define SPI_DR23_DR_Msk     (0xffffffffU << SPI_DR23_DR_Pos)                          /*!< DR Mask 0xFFFFFFFF */
#define SPI_DR23_DR_Set(x)  (((uint32_t) (x) << SPI_DR23_DR_Pos) & SPI_DR23_DR_Msk)   /*!< DR Set Value */
#define SPI_DR23_DR_Get(x)  (((uint32_t) (x) & SPI_DR23_DR_Msk) >> SPI_DR23_DR_Pos)   /*!< DR Get Value */

/* DR24 bitfield */
#define SPI_DR24_DR_Pos     (0U)                                                      /*!< DR Position 0 */
#define SPI_DR24_DR_Msk     (0xffffffffU << SPI_DR24_DR_Pos)                          /*!< DR Mask 0xFFFFFFFF */
#define SPI_DR24_DR_Set(x)  (((uint32_t) (x) << SPI_DR24_DR_Pos) & SPI_DR24_DR_Msk)   /*!< DR Set Value */
#define SPI_DR24_DR_Get(x)  (((uint32_t) (x) & SPI_DR24_DR_Msk) >> SPI_DR24_DR_Pos)   /*!< DR Get Value */

/* DR25 bitfield */
#define SPI_DR25_DR_Pos     (0U)                                                      /*!< DR Position 0 */
#define SPI_DR25_DR_Msk     (0xffffffffU << SPI_DR25_DR_Pos)                          /*!< DR Mask 0xFFFFFFFF */
#define SPI_DR25_DR_Set(x)  (((uint32_t) (x) << SPI_DR25_DR_Pos) & SPI_DR25_DR_Msk)   /*!< DR Set Value */
#define SPI_DR25_DR_Get(x)  (((uint32_t) (x) & SPI_DR25_DR_Msk) >> SPI_DR25_DR_Pos)   /*!< DR Get Value */

/* DR26 bitfield */
#define SPI_DR26_DR_Pos     (0U)                                                      /*!< DR Position 0 */
#define SPI_DR26_DR_Msk     (0xffffffffU << SPI_DR26_DR_Pos)                          /*!< DR Mask 0xFFFFFFFF */
#define SPI_DR26_DR_Set(x)  (((uint32_t) (x) << SPI_DR26_DR_Pos) & SPI_DR26_DR_Msk)   /*!< DR Set Value */
#define SPI_DR26_DR_Get(x)  (((uint32_t) (x) & SPI_DR26_DR_Msk) >> SPI_DR26_DR_Pos)   /*!< DR Get Value */

/* DR27 bitfield */
#define SPI_DR27_DR_Pos     (0U)                                                      /*!< DR Position 0 */
#define SPI_DR27_DR_Msk     (0xffffffffU << SPI_DR27_DR_Pos)                          /*!< DR Mask 0xFFFFFFFF */
#define SPI_DR27_DR_Set(x)  (((uint32_t) (x) << SPI_DR27_DR_Pos) & SPI_DR27_DR_Msk)   /*!< DR Set Value */
#define SPI_DR27_DR_Get(x)  (((uint32_t) (x) & SPI_DR27_DR_Msk) >> SPI_DR27_DR_Pos)   /*!< DR Get Value */

/* DR28 bitfield */
#define SPI_DR28_DR_Pos     (0U)                                                      /*!< DR Position 0 */
#define SPI_DR28_DR_Msk     (0xffffffffU << SPI_DR28_DR_Pos)                          /*!< DR Mask 0xFFFFFFFF */
#define SPI_DR28_DR_Set(x)  (((uint32_t) (x) << SPI_DR28_DR_Pos) & SPI_DR28_DR_Msk)   /*!< DR Set Value */
#define SPI_DR28_DR_Get(x)  (((uint32_t) (x) & SPI_DR28_DR_Msk) >> SPI_DR28_DR_Pos)   /*!< DR Get Value */

/* DR29 bitfield */
#define SPI_DR29_DR_Pos     (0U)                                                      /*!< DR Position 0 */
#define SPI_DR29_DR_Msk     (0xffffffffU << SPI_DR29_DR_Pos)                          /*!< DR Mask 0xFFFFFFFF */
#define SPI_DR29_DR_Set(x)  (((uint32_t) (x) << SPI_DR29_DR_Pos) & SPI_DR29_DR_Msk)   /*!< DR Set Value */
#define SPI_DR29_DR_Get(x)  (((uint32_t) (x) & SPI_DR29_DR_Msk) >> SPI_DR29_DR_Pos)   /*!< DR Get Value */

/* DR30 bitfield */
#define SPI_DR30_DR_Pos     (0U)                                                      /*!< DR Position 0 */
#define SPI_DR30_DR_Msk     (0xffffffffU << SPI_DR30_DR_Pos)                          /*!< DR Mask 0xFFFFFFFF */
#define SPI_DR30_DR_Set(x)  (((uint32_t) (x) << SPI_DR30_DR_Pos) & SPI_DR30_DR_Msk)   /*!< DR Set Value */
#define SPI_DR30_DR_Get(x)  (((uint32_t) (x) & SPI_DR30_DR_Msk) >> SPI_DR30_DR_Pos)   /*!< DR Get Value */

/* DR31 bitfield */
#define SPI_DR31_DR_Pos     (0U)                                                      /*!< DR Position 0 */
#define SPI_DR31_DR_Msk     (0xffffffffU << SPI_DR31_DR_Pos)                          /*!< DR Mask 0xFFFFFFFF */
#define SPI_DR31_DR_Set(x)  (((uint32_t) (x) << SPI_DR31_DR_Pos) & SPI_DR31_DR_Msk)   /*!< DR Set Value */
#define SPI_DR31_DR_Get(x)  (((uint32_t) (x) & SPI_DR31_DR_Msk) >> SPI_DR31_DR_Pos)   /*!< DR Get Value */

/* DR32 bitfield */
#define SPI_DR32_DR_Pos     (0U)                                                      /*!< DR Position 0 */
#define SPI_DR32_DR_Msk     (0xffffffffU << SPI_DR32_DR_Pos)                          /*!< DR Mask 0xFFFFFFFF */
#define SPI_DR32_DR_Set(x)  (((uint32_t) (x) << SPI_DR32_DR_Pos) & SPI_DR32_DR_Msk)   /*!< DR Set Value */
#define SPI_DR32_DR_Get(x)  (((uint32_t) (x) & SPI_DR32_DR_Msk) >> SPI_DR32_DR_Pos)   /*!< DR Get Value */

/* DR33 bitfield */
#define SPI_DR33_DR_Pos     (0U)                                                      /*!< DR Position 0 */
#define SPI_DR33_DR_Msk     (0xffffffffU << SPI_DR33_DR_Pos)                          /*!< DR Mask 0xFFFFFFFF */
#define SPI_DR33_DR_Set(x)  (((uint32_t) (x) << SPI_DR33_DR_Pos) & SPI_DR33_DR_Msk)   /*!< DR Set Value */
#define SPI_DR33_DR_Get(x)  (((uint32_t) (x) & SPI_DR33_DR_Msk) >> SPI_DR33_DR_Pos)   /*!< DR Get Value */

/* DR34 bitfield */
#define SPI_DR34_DR_Pos     (0U)                                                      /*!< DR Position 0 */
#define SPI_DR34_DR_Msk     (0xffffffffU << SPI_DR34_DR_Pos)                          /*!< DR Mask 0xFFFFFFFF */
#define SPI_DR34_DR_Set(x)  (((uint32_t) (x) << SPI_DR34_DR_Pos) & SPI_DR34_DR_Msk)   /*!< DR Set Value */
#define SPI_DR34_DR_Get(x)  (((uint32_t) (x) & SPI_DR34_DR_Msk) >> SPI_DR34_DR_Pos)   /*!< DR Get Value */

/* DR35 bitfield */
#define SPI_DR35_DR_Pos     (0U)                                                      /*!< DR Position 0 */
#define SPI_DR35_DR_Msk     (0xffffffffU << SPI_DR35_DR_Pos)                          /*!< DR Mask 0xFFFFFFFF */
#define SPI_DR35_DR_Set(x)  (((uint32_t) (x) << SPI_DR35_DR_Pos) & SPI_DR35_DR_Msk)   /*!< DR Set Value */
#define SPI_DR35_DR_Get(x)  (((uint32_t) (x) & SPI_DR35_DR_Msk) >> SPI_DR35_DR_Pos)   /*!< DR Get Value */

/* RX_SAMPLE_DELAY bitfield */
#define SPI_RX_SAMPLE_DELAY_SE_Pos     (16U)                                                                           /*!< SE Position 16 */
#define SPI_RX_SAMPLE_DELAY_SE_Msk     (0x1U << SPI_RX_SAMPLE_DELAY_SE_Pos)                                            /*!< SE Mask 0x00010000 */
#define SPI_RX_SAMPLE_DELAY_SE_Set(x)  (((uint32_t) (x) << SPI_RX_SAMPLE_DELAY_SE_Pos) & SPI_RX_SAMPLE_DELAY_SE_Msk)   /*!< SE Set Value */
#define SPI_RX_SAMPLE_DELAY_SE_Get(x)  (((uint32_t) (x) & SPI_RX_SAMPLE_DELAY_SE_Msk) >> SPI_RX_SAMPLE_DELAY_SE_Pos)   /*!< SE Get Value */

#define SPI_RX_SAMPLE_DELAY_RSD_Pos     (0U)                                                                              /*!< RSD Position 0 */
#define SPI_RX_SAMPLE_DELAY_RSD_Msk     (0xffU << SPI_RX_SAMPLE_DELAY_RSD_Pos)                                            /*!< RSD Mask 0x000000FF */
#define SPI_RX_SAMPLE_DELAY_RSD_Set(x)  (((uint32_t) (x) << SPI_RX_SAMPLE_DELAY_RSD_Pos) & SPI_RX_SAMPLE_DELAY_RSD_Msk)   /*!< RSD Set Value */
#define SPI_RX_SAMPLE_DELAY_RSD_Get(x)  (((uint32_t) (x) & SPI_RX_SAMPLE_DELAY_RSD_Msk) >> SPI_RX_SAMPLE_DELAY_RSD_Pos)   /*!< RSD Get Value */

/* SPI_CTRLR0 bitfield */
#define SPI_SPI_CTRLR0_CLK_STRETCH_EN_Pos     (30U)                                                                                         /*!< CLK_STRETCH_EN Position 30 */
#define SPI_SPI_CTRLR0_CLK_STRETCH_EN_Msk     (0x1U << SPI_SPI_CTRLR0_CLK_STRETCH_EN_Pos)                                                   /*!< CLK_STRETCH_EN Mask 0x40000000 */
#define SPI_SPI_CTRLR0_CLK_STRETCH_EN_Set(x)  (((uint32_t) (x) << SPI_SPI_CTRLR0_CLK_STRETCH_EN_Pos) & SPI_SPI_CTRLR0_CLK_STRETCH_EN_Msk)   /*!< CLK_STRETCH_EN Set Value */
#define SPI_SPI_CTRLR0_CLK_STRETCH_EN_Get(x)  (((uint32_t) (x) & SPI_SPI_CTRLR0_CLK_STRETCH_EN_Msk) >> SPI_SPI_CTRLR0_CLK_STRETCH_EN_Pos)   /*!< CLK_STRETCH_EN Get Value */

#define SPI_SPI_CTRLR0_XIP_PREFETCH_EN_Pos     (29U)                                                                                           /*!< XIP_PREFETCH_EN Position 29 */
#define SPI_SPI_CTRLR0_XIP_PREFETCH_EN_Msk     (0x1U << SPI_SPI_CTRLR0_XIP_PREFETCH_EN_Pos)                                                    /*!< XIP_PREFETCH_EN Mask 0x20000000 */
#define SPI_SPI_CTRLR0_XIP_PREFETCH_EN_Set(x)  (((uint32_t) (x) << SPI_SPI_CTRLR0_XIP_PREFETCH_EN_Pos) & SPI_SPI_CTRLR0_XIP_PREFETCH_EN_Msk)   /*!< XIP_PREFETCH_EN Set Value */
#define SPI_SPI_CTRLR0_XIP_PREFETCH_EN_Get(x)  (((uint32_t) (x) & SPI_SPI_CTRLR0_XIP_PREFETCH_EN_Msk) >> SPI_SPI_CTRLR0_XIP_PREFETCH_EN_Pos)   /*!< XIP_PREFETCH_EN Get Value */

#define SPI_SPI_CTRLR0_XIP_MBL_Pos     (26U)                                                                           /*!< XIP_MBL Position 26 */
#define SPI_SPI_CTRLR0_XIP_MBL_Msk     (0x3U << SPI_SPI_CTRLR0_XIP_MBL_Pos)                                            /*!< XIP_MBL Mask 0x0C000000 */
#define SPI_SPI_CTRLR0_XIP_MBL_Set(x)  (((uint32_t) (x) << SPI_SPI_CTRLR0_XIP_MBL_Pos) & SPI_SPI_CTRLR0_XIP_MBL_Msk)   /*!< XIP_MBL Set Value */
#define SPI_SPI_CTRLR0_XIP_MBL_Get(x)  (((uint32_t) (x) & SPI_SPI_CTRLR0_XIP_MBL_Msk) >> SPI_SPI_CTRLR0_XIP_MBL_Pos)   /*!< XIP_MBL Get Value */

#define SPI_SPI_CTRLR0_SPI_RXDS_SIG_EN_Pos     (25U)                                                                                           /*!< SPI_RXDS_SIG_EN Position 25 */
#define SPI_SPI_CTRLR0_SPI_RXDS_SIG_EN_Msk     (0x1U << SPI_SPI_CTRLR0_SPI_RXDS_SIG_EN_Pos)                                                    /*!< SPI_RXDS_SIG_EN Mask 0x02000000 */
#define SPI_SPI_CTRLR0_SPI_RXDS_SIG_EN_Set(x)  (((uint32_t) (x) << SPI_SPI_CTRLR0_SPI_RXDS_SIG_EN_Pos) & SPI_SPI_CTRLR0_SPI_RXDS_SIG_EN_Msk)   /*!< SPI_RXDS_SIG_EN Set Value */
#define SPI_SPI_CTRLR0_SPI_RXDS_SIG_EN_Get(x)  (((uint32_t) (x) & SPI_SPI_CTRLR0_SPI_RXDS_SIG_EN_Msk) >> SPI_SPI_CTRLR0_SPI_RXDS_SIG_EN_Pos)   /*!< SPI_RXDS_SIG_EN Get Value */

#define SPI_SPI_CTRLR0_SPI_DM_EN_Pos     (24U)                                                                               /*!< SPI_DM_EN Position 24 */
#define SPI_SPI_CTRLR0_SPI_DM_EN_Msk     (0x1U << SPI_SPI_CTRLR0_SPI_DM_EN_Pos)                                              /*!< SPI_DM_EN Mask 0x01000000 */
#define SPI_SPI_CTRLR0_SPI_DM_EN_Set(x)  (((uint32_t) (x) << SPI_SPI_CTRLR0_SPI_DM_EN_Pos) & SPI_SPI_CTRLR0_SPI_DM_EN_Msk)   /*!< SPI_DM_EN Set Value */
#define SPI_SPI_CTRLR0_SPI_DM_EN_Get(x)  (((uint32_t) (x) & SPI_SPI_CTRLR0_SPI_DM_EN_Msk) >> SPI_SPI_CTRLR0_SPI_DM_EN_Pos)   /*!< SPI_DM_EN Get Value */

#define SPI_SPI_CTRLR0_SPIC_XIP_CONT_XFER_EN_Pos     (21U)                                                                                                       /*!< SPIC_XIP_CONT_XFER_EN Position 21 */
#define SPI_SPI_CTRLR0_SPIC_XIP_CONT_XFER_EN_Msk     (0x1U << SPI_SPI_CTRLR0_SPIC_XIP_CONT_XFER_EN_Pos)                                                          /*!< SPIC_XIP_CONT_XFER_EN Mask 0x00200000 */
#define SPI_SPI_CTRLR0_SPIC_XIP_CONT_XFER_EN_Set(x)  (((uint32_t) (x) << SPI_SPI_CTRLR0_SPIC_XIP_CONT_XFER_EN_Pos) & SPI_SPI_CTRLR0_SPIC_XIP_CONT_XFER_EN_Msk)   /*!< SPIC_XIP_CONT_XFER_EN Set Value */
#define SPI_SPI_CTRLR0_SPIC_XIP_CONT_XFER_EN_Get(x)  (((uint32_t) (x) & SPI_SPI_CTRLR0_SPIC_XIP_CONT_XFER_EN_Msk) >> SPI_SPI_CTRLR0_SPIC_XIP_CONT_XFER_EN_Pos)   /*!< SPIC_XIP_CONT_XFER_EN Get Value */

#define SPI_SPI_CTRLR0_XIP_INST_EN_Pos     (20U)                                                                                   /*!< XIP_INST_EN Position 20 */
#define SPI_SPI_CTRLR0_XIP_INST_EN_Msk     (0x1U << SPI_SPI_CTRLR0_XIP_INST_EN_Pos)                                                /*!< XIP_INST_EN Mask 0x00100000 */
#define SPI_SPI_CTRLR0_XIP_INST_EN_Set(x)  (((uint32_t) (x) << SPI_SPI_CTRLR0_XIP_INST_EN_Pos) & SPI_SPI_CTRLR0_XIP_INST_EN_Msk)   /*!< XIP_INST_EN Set Value */
#define SPI_SPI_CTRLR0_XIP_INST_EN_Get(x)  (((uint32_t) (x) & SPI_SPI_CTRLR0_XIP_INST_EN_Msk) >> SPI_SPI_CTRLR0_XIP_INST_EN_Pos)   /*!< XIP_INST_EN Get Value */

#define SPI_SPI_CTRLR0_XIP_DFS_HC_Pos     (19U)                                                                                 /*!< XIP_DFS_HC Position 19 */
#define SPI_SPI_CTRLR0_XIP_DFS_HC_Msk     (0x1U << SPI_SPI_CTRLR0_XIP_DFS_HC_Pos)                                               /*!< XIP_DFS_HC Mask 0x00080000 */
#define SPI_SPI_CTRLR0_XIP_DFS_HC_Set(x)  (((uint32_t) (x) << SPI_SPI_CTRLR0_XIP_DFS_HC_Pos) & SPI_SPI_CTRLR0_XIP_DFS_HC_Msk)   /*!< XIP_DFS_HC Set Value */
#define SPI_SPI_CTRLR0_XIP_DFS_HC_Get(x)  (((uint32_t) (x) & SPI_SPI_CTRLR0_XIP_DFS_HC_Msk) >> SPI_SPI_CTRLR0_XIP_DFS_HC_Pos)   /*!< XIP_DFS_HC Get Value */

#define SPI_SPI_CTRLR0_SPI_RXDS_EN_Pos     (18U)                                                                                   /*!< SPI_RXDS_EN Position 18 */
#define SPI_SPI_CTRLR0_SPI_RXDS_EN_Msk     (0x1U << SPI_SPI_CTRLR0_SPI_RXDS_EN_Pos)                                                /*!< SPI_RXDS_EN Mask 0x00040000 */
#define SPI_SPI_CTRLR0_SPI_RXDS_EN_Set(x)  (((uint32_t) (x) << SPI_SPI_CTRLR0_SPI_RXDS_EN_Pos) & SPI_SPI_CTRLR0_SPI_RXDS_EN_Msk)   /*!< SPI_RXDS_EN Set Value */
#define SPI_SPI_CTRLR0_SPI_RXDS_EN_Get(x)  (((uint32_t) (x) & SPI_SPI_CTRLR0_SPI_RXDS_EN_Msk) >> SPI_SPI_CTRLR0_SPI_RXDS_EN_Pos)   /*!< SPI_RXDS_EN Get Value */

#define SPI_SPI_CTRLR0_INST_DDR_EN_Pos     (17U)                                                                                   /*!< INST_DDR_EN Position 17 */
#define SPI_SPI_CTRLR0_INST_DDR_EN_Msk     (0x1U << SPI_SPI_CTRLR0_INST_DDR_EN_Pos)                                                /*!< INST_DDR_EN Mask 0x00020000 */
#define SPI_SPI_CTRLR0_INST_DDR_EN_Set(x)  (((uint32_t) (x) << SPI_SPI_CTRLR0_INST_DDR_EN_Pos) & SPI_SPI_CTRLR0_INST_DDR_EN_Msk)   /*!< INST_DDR_EN Set Value */
#define SPI_SPI_CTRLR0_INST_DDR_EN_Get(x)  (((uint32_t) (x) & SPI_SPI_CTRLR0_INST_DDR_EN_Msk) >> SPI_SPI_CTRLR0_INST_DDR_EN_Pos)   /*!< INST_DDR_EN Get Value */

#define SPI_SPI_CTRLR0_SPI_DDR_EN_Pos     (16U)                                                                                 /*!< SPI_DDR_EN Position 16 */
#define SPI_SPI_CTRLR0_SPI_DDR_EN_Msk     (0x1U << SPI_SPI_CTRLR0_SPI_DDR_EN_Pos)                                               /*!< SPI_DDR_EN Mask 0x00010000 */
#define SPI_SPI_CTRLR0_SPI_DDR_EN_Set(x)  (((uint32_t) (x) << SPI_SPI_CTRLR0_SPI_DDR_EN_Pos) & SPI_SPI_CTRLR0_SPI_DDR_EN_Msk)   /*!< SPI_DDR_EN Set Value */
#define SPI_SPI_CTRLR0_SPI_DDR_EN_Get(x)  (((uint32_t) (x) & SPI_SPI_CTRLR0_SPI_DDR_EN_Msk) >> SPI_SPI_CTRLR0_SPI_DDR_EN_Pos)   /*!< SPI_DDR_EN Get Value */

#define SPI_SPI_CTRLR0_WAIT_CYCLES_Pos     (11U)                                                                                   /*!< WAIT_CYCLES Position 11 */
#define SPI_SPI_CTRLR0_WAIT_CYCLES_Msk     (0x1fU << SPI_SPI_CTRLR0_WAIT_CYCLES_Pos)                                               /*!< WAIT_CYCLES Mask 0x0000F800 */
#define SPI_SPI_CTRLR0_WAIT_CYCLES_Set(x)  (((uint32_t) (x) << SPI_SPI_CTRLR0_WAIT_CYCLES_Pos) & SPI_SPI_CTRLR0_WAIT_CYCLES_Msk)   /*!< WAIT_CYCLES Set Value */
#define SPI_SPI_CTRLR0_WAIT_CYCLES_Get(x)  (((uint32_t) (x) & SPI_SPI_CTRLR0_WAIT_CYCLES_Msk) >> SPI_SPI_CTRLR0_WAIT_CYCLES_Pos)   /*!< WAIT_CYCLES Get Value */

#define SPI_SPI_CTRLR0_INST_L_Pos     (8U)                                                                          /*!< INST_L Position 8 */
#define SPI_SPI_CTRLR0_INST_L_Msk     (0x3U << SPI_SPI_CTRLR0_INST_L_Pos)                                           /*!< INST_L Mask 0x00000300 */
#define SPI_SPI_CTRLR0_INST_L_Set(x)  (((uint32_t) (x) << SPI_SPI_CTRLR0_INST_L_Pos) & SPI_SPI_CTRLR0_INST_L_Msk)   /*!< INST_L Set Value */
#define SPI_SPI_CTRLR0_INST_L_Get(x)  (((uint32_t) (x) & SPI_SPI_CTRLR0_INST_L_Msk) >> SPI_SPI_CTRLR0_INST_L_Pos)   /*!< INST_L Get Value */

#define SPI_SPI_CTRLR0_XIP_MD_BIT_EN_Pos     (7U)                                                                                        /*!< XIP_MD_BIT_EN Position 7 */
#define SPI_SPI_CTRLR0_XIP_MD_BIT_EN_Msk     (0x1U << SPI_SPI_CTRLR0_XIP_MD_BIT_EN_Pos)                                                  /*!< XIP_MD_BIT_EN Mask 0x00000080 */
#define SPI_SPI_CTRLR0_XIP_MD_BIT_EN_Set(x)  (((uint32_t) (x) << SPI_SPI_CTRLR0_XIP_MD_BIT_EN_Pos) & SPI_SPI_CTRLR0_XIP_MD_BIT_EN_Msk)   /*!< XIP_MD_BIT_EN Set Value */
#define SPI_SPI_CTRLR0_XIP_MD_BIT_EN_Get(x)  (((uint32_t) (x) & SPI_SPI_CTRLR0_XIP_MD_BIT_EN_Msk) >> SPI_SPI_CTRLR0_XIP_MD_BIT_EN_Pos)   /*!< XIP_MD_BIT_EN Get Value */

#define SPI_SPI_CTRLR0_ADDR_L_Pos     (2U)                                                                          /*!< ADDR_L Position 2 */
#define SPI_SPI_CTRLR0_ADDR_L_Msk     (0xfU << SPI_SPI_CTRLR0_ADDR_L_Pos)                                           /*!< ADDR_L Mask 0x0000003C */
#define SPI_SPI_CTRLR0_ADDR_L_Set(x)  (((uint32_t) (x) << SPI_SPI_CTRLR0_ADDR_L_Pos) & SPI_SPI_CTRLR0_ADDR_L_Msk)   /*!< ADDR_L Set Value */
#define SPI_SPI_CTRLR0_ADDR_L_Get(x)  (((uint32_t) (x) & SPI_SPI_CTRLR0_ADDR_L_Msk) >> SPI_SPI_CTRLR0_ADDR_L_Pos)   /*!< ADDR_L Get Value */

#define SPI_SPI_CTRLR0_TRANS_TYPE_Pos     (0U)                                                                                  /*!< TRANS_TYPE Position 0 */
#define SPI_SPI_CTRLR0_TRANS_TYPE_Msk     (0x3U << SPI_SPI_CTRLR0_TRANS_TYPE_Pos)                                               /*!< TRANS_TYPE Mask 0x00000003 */
#define SPI_SPI_CTRLR0_TRANS_TYPE_Set(x)  (((uint32_t) (x) << SPI_SPI_CTRLR0_TRANS_TYPE_Pos) & SPI_SPI_CTRLR0_TRANS_TYPE_Msk)   /*!< TRANS_TYPE Set Value */
#define SPI_SPI_CTRLR0_TRANS_TYPE_Get(x)  (((uint32_t) (x) & SPI_SPI_CTRLR0_TRANS_TYPE_Msk) >> SPI_SPI_CTRLR0_TRANS_TYPE_Pos)   /*!< TRANS_TYPE Get Value */

/* XIP_MODE_BITS bitfield */
#define SPI_XIP_MODE_BITS_XIP_MD_BITS_Pos     (0U)                                                                                          /*!< XIP_MD_BITS Position 0 */
#define SPI_XIP_MODE_BITS_XIP_MD_BITS_Msk     (0xffffU << SPI_XIP_MODE_BITS_XIP_MD_BITS_Pos)                                                /*!< XIP_MD_BITS Mask 0x0000FFFF */
#define SPI_XIP_MODE_BITS_XIP_MD_BITS_Set(x)  (((uint32_t) (x) << SPI_XIP_MODE_BITS_XIP_MD_BITS_Pos) & SPI_XIP_MODE_BITS_XIP_MD_BITS_Msk)   /*!< XIP_MD_BITS Set Value */
#define SPI_XIP_MODE_BITS_XIP_MD_BITS_Get(x)  (((uint32_t) (x) & SPI_XIP_MODE_BITS_XIP_MD_BITS_Msk) >> SPI_XIP_MODE_BITS_XIP_MD_BITS_Pos)   /*!< XIP_MD_BITS Get Value */

/* XIP_INCR_INST bitfield */
#define SPI_XIP_INCR_INST_INCR_INST_Pos     (0U)                                                                                      /*!< INCR_INST Position 0 */
#define SPI_XIP_INCR_INST_INCR_INST_Msk     (0xffffU << SPI_XIP_INCR_INST_INCR_INST_Pos)                                              /*!< INCR_INST Mask 0x0000FFFF */
#define SPI_XIP_INCR_INST_INCR_INST_Set(x)  (((uint32_t) (x) << SPI_XIP_INCR_INST_INCR_INST_Pos) & SPI_XIP_INCR_INST_INCR_INST_Msk)   /*!< INCR_INST Set Value */
#define SPI_XIP_INCR_INST_INCR_INST_Get(x)  (((uint32_t) (x) & SPI_XIP_INCR_INST_INCR_INST_Msk) >> SPI_XIP_INCR_INST_INCR_INST_Pos)   /*!< INCR_INST Get Value */

/* XIP_WRAP_INST bitfield */
#define SPI_XIP_WRAP_INST_WRAP_INST_Pos     (0U)                                                                                      /*!< WRAP_INST Position 0 */
#define SPI_XIP_WRAP_INST_WRAP_INST_Msk     (0xffffU << SPI_XIP_WRAP_INST_WRAP_INST_Pos)                                              /*!< WRAP_INST Mask 0x0000FFFF */
#define SPI_XIP_WRAP_INST_WRAP_INST_Set(x)  (((uint32_t) (x) << SPI_XIP_WRAP_INST_WRAP_INST_Pos) & SPI_XIP_WRAP_INST_WRAP_INST_Msk)   /*!< WRAP_INST Set Value */
#define SPI_XIP_WRAP_INST_WRAP_INST_Get(x)  (((uint32_t) (x) & SPI_XIP_WRAP_INST_WRAP_INST_Msk) >> SPI_XIP_WRAP_INST_WRAP_INST_Pos)   /*!< WRAP_INST Get Value */

/*!
 * @}
 */

/* clang-format on */

/*!
 * @}
 */ /* end of HS32F7D377_SPI_REGISTER */

#endif /* HS32F7D377_SPI_H */
