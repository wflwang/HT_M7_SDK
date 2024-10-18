/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


/*!
 * \file HS32F7D377_i2c_pmbus.h
 * \brief HS32F7D377 I2C and PMBUS register file
 * \version V1.0_20230713
 */

#ifndef HS32F7D377_I2C_PMBUS_H
#define HS32F7D377_I2C_PMBUS_H

/*!
 * \addtogroup   HS32F7D377_I2C_PMBUS_REGISTER HS32F7D377 I2C and PMBUS Register
 * \ingroup HS32F7D377_REGISTER
 *
 * \brief  I2C register layout, bitfield and address definitions
 *
 * @{
 */

/*!
 * \name I2C Register Layout
 *
 *
 * @{
 */

/*! \brief I2C register layout */
typedef struct
{
    union
    {
        __IOM uint32_t IC_CON; /*!< 0x00000000 */

        struct
        {
            __IOM uint32_t MASTER_MODE : 1; /*!< [0:0] : This bit controls whether the DW_apb_i2c master is enabled. */
            __IOM uint32_t SPEED       : 2; /*!< [2:1] : These bits control at which speed the DW_apb_i2c operates;  its
                                               setting is relevant only if one is operating the DW_apb_i2c in master mode. */
            __IOM uint32_t IC_10BITADDR_SLAVE : 1;  /*!< [3:3] : When acting as a slave, this bit controls whether the
                                                       DW_apb_i2c responds to 7- or 10-bit addresses. */
            __IOM uint32_t IC_10BITADDR_MASTER : 1; /*!< [4:4] : If the I2C_DYNAMIC_TAR_UPDATE configuration parameter
                                                       is set to 'No' (0), this bit is named IC_10BITADDR_MASTER  and
                                                       controls whether the DW_apb_i2c starts its transfers in 7- or
                                                       10-bit addressing mode when acting as a master. */
            __IOM uint32_t IC_RESTART_EN : 1; /*!< [5:5] : Determines whether RESTART conditions may be sent when acting
                                                 as a master. */
            __IOM uint32_t IC_SLAVE_DISABLE : 1;     /*!< [6:6] : This bit controls whether I2C has its slave disabled,
                                                        which means once the presetn signal is applied, then this bit takes
                                                        on the value of the configuration parameter IC_SLAVE_DISABLE. */
            __IOM uint32_t STOP_DET_IFADDRESSED : 1;     /*!< [7:7] : In slave mode: 1'b1:issues the STOP_DET
                                                            interrrupt only when it is addressed. */
            __IOM uint32_t TX_EMPTY_CTRL : 1; /*!< [8:8] : This bit controls the generation of the TX_EMPTY interrupt,
                                                 as described in the IC_RAW_lNTR_STAT register. */
            __IM uint32_t RX_FIFO_FULL_HOLD_CTRL : 1; /*!< [9:9] : This bit controls whether DW_apb_i2c should hold the
                                                         bus when the Rx FIFO is physically full to its RX_BUFFER_DEPTH,
                                                         as described in the ICJRX_FULLZHLD_BUS_EN parameter. */
            __IM uint32_t  STOP_DET_IF_MASTER_ACTIVE : 1; /*!< [10:10] : In Master mode: 1'b1: issues the
                                                             STOP_DET interrupt only when master is active. */
            __IOM uint32_t
                BUS_CLEAR_FEATURE_CTRL : 1; /*!< [11:11] : In Master mode: 1'b1: Bus Clear Feature is enabled. */
            uint32_t       RSV_1       : 4; /*!< [15:12] : reserved. */
            __IOM uint32_t OPTIONAL_SAR_CTRL    : 1; /*!< [16:16] : Enables the usage of IC_OPTIONAL_SAR register. */
            __IOM uint32_t SMBUS_SLAVE_QUICK_EN : 1; /*!< [17:17] : If this bit is set to 1, DW_apb_i2c slave only
                                                        receives Quick commands in SMBus Mode. */
            __IOM uint32_t SMBUS_ARP_EN : 1; /*!< [18:18] : This bit controls whether DW_apb_i2c should enable Address
                                                Resolution Logic in SMBus Mode. */
            __IOM uint32_t SMBUS_PERSISTENT_SLV_ADDR_EN : 1; /*!< [19:19] : The bit controls to enable DW_apb_i2c slave
                                                                as persistent or non persistent slave. */
            uint32_t RSV_0 : 12;                             /*!< [31:20] : reserved. */
        } IC_CONb;
    };

    union
    {
        __IOM uint32_t IC_TAR; /*!< 0x00000004 */

        struct
        {
            __IOM uint32_t IC_TAR      : 10; /*!< [9:0] : this is the target address for any master transaction. */
            __IOM uint32_t GC_OR_START : 1;  /*!< [10:10] : If bit 11 (SPECIAL) is set to 1 and bit 13(Device-ID) is set
                                                to 0,  then this bit indicates whether a General Call or START byte
                                                command is to be performed by the DW_apb_i2c. */
            __IOM uint32_t SPECIAL : 1;      /*!< [11:11] : This bit indicates whether software performs a Device-ID or
                                                General Call or START BYTE command. */
            __IOM uint32_t
                IC_10BITADDR_MASTER : 1; /*!< [12:12] : This bit controls whether the DW_apb_i2c starts its transfers in
                                            7- or 10-bit addressing mode when acting as a master. */
            __IOM uint32_t DEVICE_ID : 1;       /*!< [13:13] : If bit 11 (SPECIAL) is set to 1, then this bit indicates
                                                   whether a Device-ID of a particular slave mentioned in IC_TAR[9:0] is to be
                                                   performed by the DW_apb_i2c Master. */
            uint32_t       RSV_1           : 2; /*!< [15:14] : reserved. */
            __IOM uint32_t SMBUS_QUICK_CMD : 1; /*!< [16:16] : If bit 11 (SPECIAL) is set to 1,  then this bit indicates
                                                   whether a Quick command is to be performed by the DW_apb_i2c. */
            uint32_t RSV_0 : 15;                /*!< [31:17] : reserved. */
        } IC_TARb;
    };

    union
    {
        __IOM uint32_t IC_SAR; /*!< 0x00000008 */

        struct
        {
            __IOM uint32_t
                IC_SAR : 10; /*!< [9:0] : The IC_SAR holds the slave address when the I2C is operating as a slave. */
            uint32_t RSV_0 : 22; /*!< [31:10] : reserved. */
        } IC_SARb;
    };

    union
    {
        __IOM uint32_t IC_HS_MADDR; /*!< 0x0000000c */

        struct
        {
            __IOM uint32_t IC_HS_MAR : 3; /*!< [2:0] : This bit field holds the value of the I2C HS mode master code. */
            uint32_t       RSV_0     : 29; /*!< [31:3] : reserved. */
        } IC_HS_MADDRb;
    };

    union
    {
        __IOM uint32_t IC_DATA_CMD; /*!< 0x00000010 */

        struct
        {
            __IOM uint32_t
                DAT : 8; /*!< [7:0] : This register contains the data to be transmitted or received on the I2C bus. */
            __OM uint32_t CMD : 1; /*!< [8:8] : This bit controls whether a read or a write is performed. */
            __OM uint32_t
                STOP : 1; /*!< [9:9] : This bit controls whether a STOP is issued after the byte is sent or received. */
            __OM uint32_t RESTART : 1; /*!< [10:10] : This bit controls whether a RESTART is issued before the byte is
                                          sent or received. */
            __IM uint32_t
                FIRST_DATA_BYTE : 1; /*!< [11:11] : Indicates the first data byte received after the address phase for
                                        receive transfer in Master receiver or Slave receiver mode. */
            uint32_t RSV_0 : 20;     /*!< [31:12] : reserved. */
        } IC_DATA_CMDb;
    };

    union /*!< share_reg_0_begin */ /*!< 0x00000014 */
    {
        union
        {
            __IOM uint32_t IC_SS_SCL_HCNT; /*!< 0x00000014 */

            struct
            {
                __IOM uint32_t IC_SS_SCL_HCNT : 16; /*!< [15:0] : This register must be set before any I2C bus
                                                       transaction can take place to ensure proper I/O timing. */
                uint32_t RSV_0 : 16;                /*!< [31:16] : reserved. */
            } IC_SS_SCL_HCNTb;
        };

        union
        {
            __IOM uint32_t IC_UFM_SCL_HCNT; /*!< 0x00000014 */

            struct
            {
                __IOM uint32_t IC_UFM_SCL_HCNT : 16; /*!< [15:0] : This register must be set before any I2C bus
                                                        transaction can take place to ensure proper I/O timing. */
                uint32_t RSV_0 : 16;                 /*!< [31:16] : reserved. */
            } IC_UFM_SCL_HCNTb;
        };

    }; /*!< share_reg_0_end */

    union /*!< share_reg_1_begin */ /*!< 0x00000018 */
    {
        union
        {
            __IOM uint32_t IC_SS_SCL_LCNT; /*!< 0x00000018 */

            struct
            {
                __IOM uint32_t IC_SS_SCL_LCNT : 16; /*!< [15:0] : This register must be set before any I2C bus
                                                       transaction can take place to ensure proper I/O timing. */
                uint32_t RSV_0 : 16;                /*!< [31:16] : reserved. */
            } IC_SS_SCL_LCNTb;
        };

        union
        {
            __IOM uint32_t IC_UFM_SCL_LCNT; /*!< 0x00000018 */

            struct
            {
                __IOM uint32_t IC_UFM_SCL_LCNT : 16; /*!< [15:0] : This register must be set before any I2C bus
                                                        transaction can take place to ensure proper I/O timing. */
                uint32_t RSV_0 : 16;                 /*!< [31:16] : reserved. */
            } IC_UFM_SCL_LCNTb;
        };

    }; /*!< share_reg_1_end */

    union /*!< share_reg_2_begin */ /*!< 0x0000001c */
    {
        union
        {
            __IOM uint32_t IC_FS_SCL_HCNT; /*!< 0x0000001c */

            struct
            {
                __IOM uint32_t IC_FS_SCL_HCNT : 16; /*!< [15:0] : This register must be set before any I2C bus
                                                       transaction can take place to ensure proper I/O timing. */
                uint32_t RSV_0 : 16;                /*!< [31:16] : reserved. */
            } IC_FS_SCL_HCNTb;
        };

        union
        {
            __IOM uint32_t IC_UFM_TBUF_CNT; /*!< 0x0000001c */

            struct
            {
                __IOM uint32_t IC_UFM_TBUF_CNT : 16; /*!< [15:0] : This register must be set before any I2C bus
                                                        transaction can take place to ensure proper I/O timing. */
                uint32_t RSV_0 : 16;                 /*!< [31:16] : reserved. */
            } IC_UFM_TBUF_CNTb;
        };

    }; /*!< share_reg_2_end */

    union
    {
        __IOM uint32_t IC_FS_SCL_LCNT; /*!< 0x00000020 */

        struct
        {
            __IOM uint32_t IC_FS_SCL_LCNT : 16; /*!< [15:0] : This register must be set before any I2C bus transaction
                                                   can take place to ensure proper I/O timing. */
            uint32_t RSV_0 : 16;                /*!< [31:16] : reserved. */
        } IC_FS_SCL_LCNTb;
    };

    union
    {
        __IOM uint32_t IC_HS_SCL_HCNT; /*!< 0x00000024 */

        struct
        {
            __IOM uint32_t IC_HS_SCL_HCNT : 16; /*!< [15:0] : This register must be set before any I2C bus transaction
                                                   can take place to ensure proper I/O timing. */
            uint32_t RSV_0 : 16;                /*!< [31:16] : reserved. */
        } IC_HS_SCL_HCNTb;
    };

    union
    {
        __IOM uint32_t IC_HS_SCL_LCNT; /*!< 0x00000028 */

        struct
        {
            __IOM uint32_t IC_HS_SCL_LCNT : 16; /*!< [15:0] : This register must be set before any I2C bus transaction
                                                   can take place to ensure proper I/O timing. */
            uint32_t RSV_0 : 16;                /*!< [31:16] : reserved. */
        } IC_HS_SCL_LCNTb;
    };

    union
    {
        __IM uint32_t IC_INTR_STAT; /*!< 0x0000002c */

        struct
        {
            __IM uint32_t
                R_RX_UNDER : 1; /*!< [0:0] : See IC_RAW_INTR STAT for a detailed description of R_RXJJNDER bit. */
            __IM uint32_t
                R_RX_OVER : 1; /*!< [1:1] : See I C_RAW_I NTR_ST AT fora detailed description of R_RXj0VERbit. */
            __IM uint32_t
                R_RX_FULL : 1; /*!< [2:2] : See IC_RAW_INTR_STAT fora detailed description of R_RX_?ULL bit. */
            __IM uint32_t R_TX_0VER : 1; /*!< [3:3] : See IC_RAW_INTR STATfora detailed description of R_TXjdVERLit. */
            __IM uint32_t
                R_TX_EMPTY : 1; /*!< [4:4] : See IC_RAW_INTR STAT for a detailed description of R_TX_EMPTY bit. */
            __IM uint32_t
                R_RD_REQ : 1; /*!< [5:5] : See I C_RAW_I NTR_ST AT fora detailed description of r_rdJreq bit. */
            __IM uint32_t R_TX_ABRT : 1; /*!< [6:6] : See IC_RAW_INTR_STAT fora detailed description of R_TX_^BRTbit. */
            __IM uint32_t R_RX_DONE : 1; /*!< [7:7] : See IC_RAW_INTR STATfora detailed description of R_RXjbONE_bit. */
            __IM uint32_t
                R_ACTIVITY : 1; /*!< [8:8] : See IC_RAW_INTR STAT for a detailed description of R_ACflVITYbit. */
            __IM uint32_t
                R_STOP_DET : 1; /*!< [9:9] : See I C_RAW_I NTR_ST AT fora detailed description of R_STOP_DET bit. */
            __IM uint32_t
                R_START_DET : 1; /*!< [10:10] : See IC_RAW_INTR STAT for a detailed description of R_START_DET bit. */
            __IM uint32_t
                R_GEN_CALL : 1; /*!< [11:11] : See IC_RAW_INTR STAT fora detailed description of R_GENLCALL bit. */
            __IM uint32_t
                R_RESTART_DET : 1; /*!< [12:12] : See IC_RAW_INTR_STATfora detailed description of R_RESTARTZDET bit. */
            __IM uint32_t R_MASTER_ON_HOLD : 1;   /*!< [13:13] : See I C_RAW_I NTR_ST AT fora detailed description of
                                                     R_MASTER_ON_HOLD bit. */
            __IM uint32_t R_SCL_STUCK_AT_LOW : 1; /*!< [14:14] : See IC_RAW_INTR_STAT for a detailed description of
                                                     R_SCL_STUCK_AT_LOW bit. */
            uint32_t RSV_0 : 17;                  /*!< [31:15] : reserved. */
        } IC_INTR_STATb;
    };

    union
    {
        __IOM uint32_t IC_INTR_MASK; /*!< 0x00000030 */

        struct
        {
            __IOM uint32_t
                M_RX_UNDER : 1; /*!< [0:0] : This bit masks the R_RX_UNDER interrupt in IC_INTR_STAT register. */
            __IOM uint32_t
                M_RX_OVER : 1; /*!< [1:1] : This bit masks the R_RX_OVER interrupt in IC_INTR_STAT register. */
            __IOM uint32_t
                M_RX_FULL : 1; /*!< [2:2] : This bit masks the R_RX_FULL interrupt in IC_INTR_STAT register. */
            __IOM uint32_t
                M_TX_OVER : 1; /*!< [3:3] : This bit masks the R_TX_OVER interrupt in IC_INTR_STAT register. */
            __IOM uint32_t
                M_TX_EMPTY : 1; /*!< [4:4] : This bit masks the R_TX_EMPTY interrupt in IC_INTR_STAT register. */
            __IOM uint32_t M_RD_REQ : 1; /*!< [5:5] : This bit masks the R_RD_REQ interrupt in IC_INTR_STAT register. */
            __IOM uint32_t
                M_TX_ABRT : 1; /*!< [6:6] : This bit masks the R_TX_ABRT interrupt in IC_INTR_STAT register. */
            __IOM uint32_t
                M_RX_D0NE : 1; /*!< [7:7] : This bit masks the R_RX_DONE interrupt in IC_INTR_STAT register. */
            __IOM uint32_t
                M_ACTIVITY : 1; /*!< [8:8] : This bit masks the R_ACTIVITY interrupt in IC_INTR_STAT register. */
            __IOM uint32_t
                M_STOP_DET : 1; /*!< [9:9] : This bit masks the R_STOP_DET interrupt in IC_INTR_STAT register. */
            __IOM uint32_t
                M_START_DET : 1; /*!< [10:10] : This bit masks the R_START_DET interrupt in IC_INTR_STAT register. */
            __IOM uint32_t
                M_GEN_CALL : 1; /*!< [11:11] : This bit masks the R_GEN_CALL interrupt in IC_INTR_STAT register. */
            __IOM uint32_t M_RESTART_DET : 1; /*!< [12:12] : This bit masks the R_RESTART_DET interrupt in IC_INTR_STAT
                                                 register. */
            __IOM uint32_t M_MASTER_ON_HOLD : 1;   /*!< [13:13] : This bit masks the R_MASTER_ON_HOLD interrupt in
                                                      IC_INTR_STAT register. */
            __IOM uint32_t M_SCL_STUCK_AT_LOW : 1; /*!< [14:14] : This bit masks the R_SCL_STUCK_AT_LOW interrupt in
                                                      IC_INTR_STAT register. */
            uint32_t RSV_0 : 17;                   /*!< [31:15] : reserved. */
        } IC_INTR_MASKb;
    };

    union
    {
        __IM uint32_t IC_RAW_INTR_STAT; /*!< 0x00000034 */

        struct
        {
            __IM uint32_t RX_UNDER : 1; /*!< [0:0] : Set if the processor attempts to read the receive buffer when it is
                                           empty by reading from the IC_DATA_CMD register. */
            __IM uint32_t RX_OVER : 1; /*!< [1:1] : Set if the receive buffer is completely filled to IC_RX_BUFFER_DEPTH
                                          and  an additional byte is received from an external I2C device. */
            __IM uint32_t RX_FULL : 1; /*!< [2:2] : Set when the receive buffer reaches or goes above the RX_TL
                                          threshold in the IC_RX_TL register. */
            __IM uint32_t TX_OVER : 1; /*!< [3:3] : Set during transmit if the transmit buffer is filled to
                                          IC_TX_BUFFER_DEPTH  and the processor attempts to issue another I2C command by
                                          writing to the IC_DATA_CMD register. */
            __IM uint32_t TX_EMPTY : 1; /*!< [4:4] : The behavior of the TX_EMPTY interrupt status differs based on the
                                          TX_EMPTY_CTRL  selection in the IC_CON register. */
            __IM uint32_t RD_REQ : 1; /*!< [5:5] : This bit is set to 1 when DW_apb_i2c is acting as a slave and another
                                         I2C master is attempting to read data from DW_apb_i2c. */
            __IM uint32_t TX_ABRT : 1; /*!< [6:6] : This bit indicates if DW_apb_i2c, as an I2C transmitter,  is unable
                                          to complete the intended actions on the contents of the transmit FIFO. */
            __IM uint32_t RX_DONE : 1; /*!< [7:7] : When the DW_apb_i2c is acting as a slave-transmitter, this bit is
                                          set to 1 if the master  does not acknowledge a transmitted byte. */
            __IM uint32_t
                ACTIVITY : 1; /*!< [8:8] : This bit captures DW_apb_i2c activity and stays set until it is cleared. */
            __IM uint32_t
                STOP_DET : 1; /*!< [9:9] : Indicates whether a STOP condition has occurred on the I2C interface
                                 regardless of  whether DW_apb_i2c is operating in slave or master mode. */
            __IM uint32_t
                START_DET : 1; /*!< [10:10] : Indicates whether a START or RESTART condition has occurred on the I2C
                                  interface regardless  whether DW_apbJ2c is operating in slave or master mode. */
            __IM uint32_t
                GEN_CALL : 1; /*!< [11:11] : Set only when a General Call address is received and it is acknowledged. */
            __IM uint32_t
                RESTART_DET : 1; /*!< [12:12] : Indicates whether a RESTART condition has occurred on the I2C interface
                                    when DW_apb_i2c is operating in Slave mode and the slave is being addressed. */
            __IM uint32_t
                MASTER_ON_HOLD : 1; /*!< [13:13] : Indicates whether master is holding the bus and TX FIFO is empty. */
            __IM uint32_t SCL_STUCK_AT_LOW : 1; /*!< [14:14] : Indicates whether the SCL Line is stuck at low for the
                                                   IC_SCL_STUCK_LOW_TIMEOUT number of ic_clk periods. */
            uint32_t RSV_0 : 17;                /*!< [31:15] : reserved. */
        } IC_RAW_INTR_STATb;
    };

    union
    {
        __IOM uint32_t IC_RX_TL; /*!< 0x00000038 */

        struct
        {
            __IOM uint32_t RX_TL : 8;  /*!< [7:0] : Receive FIFO Threshold Level. */
            uint32_t       RSV_0 : 24; /*!< [31:8] : reserved. */
        } IC_RX_TLb;
    };

    union
    {
        __IOM uint32_t IC_TX_TL; /*!< 0x0000003c */

        struct
        {
            __IOM uint32_t TX_TL : 8;  /*!< [7:0] : Transmit FIFO Threshold Level. */
            uint32_t       RSV_0 : 24; /*!< [31:8] : reserved. */
        } IC_TX_TLb;
    };

    union
    {
        __IM uint32_t IC_CLR_INT; /*!< 0x00000040 */

        struct
        {
            __IM uint32_t CLR_INTR : 1; /*!< [0:0] : Read this register to clear the combined interrupt, all individual
                                           interrupts, and  the IC_TX_ABRT_SOURCE register. */
            uint32_t RSV_0 : 31;        /*!< [31:1] : reserved. */
        } IC_CLR_INTb;
    };

    union
    {
        __IM uint32_t IC_CLR_RX_UNDER; /*!< 0x00000044 */

        struct
        {
            __IM uint32_t CLR_RX_UNDER : 1; /*!< [0:0] : Read this register to clear the RX_UNDER interrupt (bit 0) of
                                               the IC_RAW_INTR_STAT register. */
            uint32_t RSV_0 : 31;            /*!< [31:1] : reserved. */
        } IC_CLR_RX_UNDERb;
    };

    union
    {
        __IM uint32_t IC_CLR_RX_OVER; /*!< 0x00000048 */

        struct
        {
            __IM uint32_t CLR_RX_OVER : 1; /*!< [0:0] : Read this register to clear the RX_OVER interrupt (bit 1) of the
                                              IC_RAW_INTR_STAT register. */
            uint32_t RSV_0 : 31;           /*!< [31:1] : reserved. */
        } IC_CLR_RX_OVERb;
    };

    union
    {
        __IM uint32_t IC_CLR_TX_OVER; /*!< 0x0000004c */

        struct
        {
            __IM uint32_t CLR_TX_OVER : 1; /*!< [0:0] : Read this register to clear the TX_OVER interrupt (bit 3) of the
                                              IC_RAW_INTR_STAT register. */
            uint32_t RSV_0 : 31;           /*!< [31:1] : reserved. */
        } IC_CLR_TX_OVERb;
    };

    union
    {
        __IM uint32_t IC_CLR_RD_REQ; /*!< 0x00000050 */

        struct
        {
            __IM uint32_t CLR_RD_REQ : 1; /*!< [0:0] : Read this register to clear the RD_REQ interrupt (bit 5) of the
                                             IC_RAW_INTR_STAT register. */
            uint32_t RSV_0 : 31;          /*!< [31:1] : reserved. */
        } IC_CLR_RD_REQb;
    };

    union
    {
        __IM uint32_t IC_CLR_TX_ABRT; /*!< 0x00000054 */

        struct
        {
            __IM uint32_t CLR_TX_ABRT : 1; /*!< [0:0] : Read this register to clear the TX_ABRT interrupt (bit 6) of the
                                              IC_RAW_INTR_STAT register, and the IC_TX_ABRT_SOURCE register. */
            uint32_t RSV_0 : 31;           /*!< [31:1] : reserved. */
        } IC_CLR_TX_ABRTb;
    };

    union
    {
        __IM uint32_t IC_CLR_RX_DONE; /*!< 0x00000058 */

        struct
        {
            __IM uint32_t CLR_RX_DONE : 1; /*!< [0:0] : Read this register to clear the RX_DONE interrupt (bit 7) of the
                                              IC_RAW_INTR_STAT register. */
            uint32_t RSV_0 : 31;           /*!< [31:1] : reserved. */
        } IC_CLR_RX_DONEb;
    };

    union
    {
        __IM uint32_t IC_CLR_ACTIVITY; /*!< 0x0000005c */

        struct
        {
            __IM uint32_t CLR_ACTIVITY : 1; /*!< [0:0] : Reading this register clears the ACTIVITY interrupt if the I2C
                                               is not active anymore. */
            uint32_t RSV_0 : 31;            /*!< [31:1] : reserved. */
        } IC_CLR_ACTIVITYb;
    };

    union
    {
        __IM uint32_t IC_CLR_STOP_DET; /*!< 0x00000060 */

        struct
        {
            __IM uint32_t CLR_STOP_DET : 1; /*!< [0:0] : Read this register to clear the STOP_DET interrupt (bit 9) of
                                               the IC_RAW_INTR_STAT register. */
            uint32_t RSV_0 : 31;            /*!< [31:1] : reserved. */
        } IC_CLR_STOP_DETb;
    };

    union
    {
        __IM uint32_t IC_CLR_START_DET; /*!< 0x00000064 */

        struct
        {
            __IM uint32_t CLR_START_DET : 1; /*!< [0:0] : Read this register to clear the START_DET interrupt (bit 10)
                                                of the IC_RAW_INTR_STAT register. */
            uint32_t RSV_0 : 31;             /*!< [31:1] : reserved. */
        } IC_CLR_START_DETb;
    };

    union
    {
        __IM uint32_t IC_CLR_GEN_CALL; /*!< 0x00000068 */

        struct
        {
            __IM uint32_t CLR_GEN_CALL : 1; /*!< [0:0] : Read this register to clear the GEN_CALL interrupt (bit 11) of
                                               IC_RAW_INTR_STAT register. */
            uint32_t RSV_0 : 31;            /*!< [31:1] : reserved. */
        } IC_CLR_GEN_CALLb;
    };

    union
    {
        __IOM uint32_t IC_ENABLE; /*!< 0x0000006c */

        struct
        {
            __IOM uint32_t I2C_EN       : 1; /*!< [0:0] : Controls whether the DW_apb_i2c is enabled. */
            __IOM uint32_t ABORT        : 1; /*!< [1:1] : When set, the controller initiates the transfer abort. */
            __IOM uint32_t TX_CMD_BLOCK : 1; /*!< [2:2] : In Master mode: 1'b1: Blocks the transmission of data
                                                on I2C bus even if Tx FIFO has data to transmit. */
            __IOM uint32_t SDA_STUCK_RECOVERY_ENABLE : 1; /*!< [3:3] : If SDA is stuck at low indicated through the
                                                             TX_ABORT interrupt (IC_TX_ABRT_SOURCE[17]),  then this bit
                                                             is used as a control knob to initiate the SDA Recovery
                                                             Mechanism(that is,  send at most 9 SCL clocks and STOP to
                                                             release the SDA line) and then this bit gets auto clear. */
            uint32_t       RSV_1           : 12;          /*!< [15:4] : reserved. */
            __IOM uint32_t SMBUS_CLK_RESET : 1; /*!< [16:16] : This bit is used in SMBus Host mode to initiate the SMBus
                                                   Master Clock Reset. */
            __IOM uint32_t SMBUS_SUSPEND_EN : 1; /*!< [17:17] : The SMBUS_SUSPEND_EN register bit is used to control
                                                    assertion and de-assertion of SMBSUS signal. */
            __IOM uint32_t SMBUS_ALERT_EN : 1;   /*!< [18:18] : The SMBUS_ALERT_CTRL register bit is used to control
                                                    assertion of SMBALERT signal. */
            uint32_t RSV_0 : 13;                 /*!< [31:19] : reserved. */
        } IC_ENABLEb;
    };

    union
    {
        __IM uint32_t IC_STATUS; /*!< 0x00000070 */

        struct
        {
            __IM uint32_t ACTIVITY     : 1; /*!< [0:0] : I2C Activity Status. */
            __IM uint32_t TFNF         : 1; /*!< [1:1] : Transmit FIFO Not Full. */
            __IM uint32_t TFE          : 1; /*!< [2:2] : Transmit FIFO Completely Empty. */
            __IM uint32_t RFNE         : 1; /*!< [3:3] : Receive FIFO Not Empty. */
            __IM uint32_t RFF          : 1; /*!< [4:4] : Receive FIFO Completely Full. */
            __IM uint32_t MST_ACTIVITY : 1; /*!< [5:5] : Master FSM Activity Status. */
            __IM uint32_t SLV_ACTIVITY : 1; /*!< [6:6] : Slave FSM Activity Status. */
            __IM uint32_t
                MST_HOLD_TX_FIFO_EMPTY : 1; /*!< [7:7] : If the IC_EMPTYFIFO_HOLD_MASTER_EN parameter is set to 1, the
                                               DW_apbJ2c master stalls the  write transfer when Tx FIFO is empty, and
                                               the the last byte does not have the Stop bit set. */
            __IM uint32_t
                MST_HOLD_RX_FIFO_FULL : 1; /*!< [8:8] : This bit indicates the BUS Hold in Master mode due to Rx FIFO is
                                              Full and additional byte has been received (This kind of Bus hold is
                                              applicable if IC_RX_FULL_HLD_BUS_EN is set to 1). */
            __IM uint32_t SLV_HOLD_TX_FIFO_EMPTY : 1; /*!< [9:9] : This bit indicates the BUS Hold in Slave mode for the
                                                         Read request  when the Tx FIFO is empty. */
            __IM uint32_t
                SLV_HOLD_RX_FIFO_FULL : 1; /*!< [10:10] : This bit indicates the BUS Hold in Slave mode due to Rx FIFO
                                              is Full  and an additional byte has been received (This kind of Bus hold
                                              is applicable  if IC_RX_FULL_HLD_BUS_EN is set to 1). */
            __IM uint32_t SDA_STUCK_NOT_RECOVERED : 1; /*!< [11:11] : this bit indicates that SDA stuck at low is not
                                                          recovered after the recovery mechanism. */
            uint32_t RSV_1 : 4;                        /*!< [15:12] : reserved. */
            __IM uint32_t
                SMBUS_QUICK_CMD_BIT : 1; /*!< [16:16] : This bit indicates the R/W bit of the Quick command received. */
            __IM uint32_t SMBUS_SLAVE_ADDR_VALID : 1;    /*!< [17:17] : This bit indicates whether the slave address (i
                                                            jsar) is valid or not. */
            __IM uint32_t SMBUS_SLAVE_ADDR_RESOLVED : 1; /*!< [18:18] : This bit indicates whether the slave address
                                                            (ic^sar) is resolved by the ARP Master. */
            __IM uint32_t SMBUS_SUSPEND_STATUS : 1; /*!< [19:19] : This bit indicates the status of the SMBus Suspend
                                                       signal (ic_smbsus_in_n). */
            __IM uint32_t SMBUS_ALERT_STATUS : 1; /*!< [20:20] : This bit indicates the status of the SMBus Alert signal
                                                     (ic_smbalert_in_n). */
            uint32_t RSV_0 : 11;                  /*!< [31:21] : reserved. */
        } IC_STATUSb;
    };

    union
    {
        __IM uint32_t IC_TXFLR; /*!< 0x00000074 */

        struct
        {
            __IM uint32_t TXFLR : 5;  /*!< [4:0] : Transmit FIFO Level. */
            uint32_t      RSV_0 : 27; /*!< [31:5] : reserved. */
        } IC_TXFLRb;
    };

    union
    {
        __IM uint32_t IC_RXFLR; /*!< 0x00000078 */

        struct
        {
            __IM uint32_t RXFLR : 5;  /*!< [4:0] : Receive FIFO Level. */
            uint32_t      RSV_0 : 27; /*!< [31:5] : reserved. */
        } IC_RXFLRb;
    };

    union
    {
        __IOM uint32_t IC_SDA_HOLD; /*!< 0x0000007c */

        struct
        {
            __IOM uint32_t IC_SDA_TX_HOLD : 16; /*!< [15:0] : Sets the required SDA hold time in units of ic_clk period,
                                                   when DW_apb_i2c acts as a transmitter. */
            __IOM uint32_t IC_SDA_RX_HOLD : 8; /*!< [23:16] : Sets the required SDA hold time in units of ic_clk period,
                                                  when DW_apb_i2c acts as a receiver. */
            uint32_t RSV_0 : 8;                /*!< [31:24] : reserved. */
        } IC_SDA_HOLDb;
    };

    union
    {
        __IM uint32_t IC_TX_ABRT_SOURCE; /*!< 0x00000080 */

        struct
        {
            __IM uint32_t
                ABRT_7B_ADDR_NOACK : 1; /*!< [0:0] : This field indicates that the Master is in 7-bit addressing mode
                                           and the address sent  was not acknowledged by any slave. */
            __IM uint32_t
                ABRT_10ADDR1_NOACK : 1; /*!< [1:1] : This field indicates that the Master is in 10-bit address mode  and
                                           the first 10-bit address byte was not acknowledged by any slave. */
            __IM uint32_t ABRT_10ADDR2_NOACK : 1; /*!< [2:2] : This field indicates that the Master is in 10-bit address
                                                     mode and that the second address byte of the 10-bit address was not
                                                     acknowledged by any slave. */
            __IM uint32_t ABRT_TXDATA_NOACK : 1;  /*!< [3:3] : This field indicates the master-mode only bit. */
            __IM uint32_t
                ABRT_GCALL_NOACK : 1; /*!< [4:4] : This field indicates that DW_apb_i2c in master mode has sent a
                                         General Call and  no slave on the bus acknowledged the General Call. */
            __IM uint32_t
                ABRT_GCALL_READ : 1; /*!< [5:5] : This field indicates that DW_apb_i2c in the master mode has sent a
                                        General Call but the user programmed the byte following the General Call to be a
                                        read from the bus (IC_DATA_CMD[9] is set to 1). */
            __IM uint32_t ABRT_HS_ACKDET : 1;    /*!< [6:6] : This field indicates that the Master is in High Speed mode
                                                    and the High Speed Master code was acknowledged (wrong behavior). */
            __IM uint32_t ABRT_SBYTE_ACKDET : 1; /*!< [7:7] : This field indicates that the Master has sent a START Byte
                                                    and the START Byte was acknowledged (wrong behavior). */
            __IM uint32_t ABRT_HS_NORSTRT : 1;   /*!< [8:8] : This field indicates that the restart is disabled
                                                    (IC_RESTART_EN bit (IC_CON[5]) =0) and  the user is trying to use the
                                                    master to transfer data in High Speed mode. */
            __IM uint32_t
                ABRT_SBYTE_NORSTRT : 1; /*!< [9:9] : To clear Bit 9, the source of the ABRT_SBYTE_NORSTRT must be fixed
                                           first; restart must be  enabled (IC_CON[5]=1),the SPECIAL bit must be cleared
                                           (IC_TAR[11]),  or the GC_OR_START bit must be cleared (IC_TAR[10]). */
            __IM uint32_t ABRT_10B_RD_NORSTRT : 1; /*!< [10:10] : This field indicates that the restart is disabled
                                                      (IC_RESTART_EN bit (IC_CON[5]) =0)  and the master sends a read
                                                      command in 10-bit addressing mode. */
            __IM uint32_t ABRT_MASTER_DIS : 1;     /*!< [11:11] : This field indicates that the User tries to initiate a
                                                      Master operation with the Master mode disabled. */
            __IM uint32_t
                ARB_LOST : 1; /*!< [12:12] : This field specifies that the Master has lost arbitration, or if
                                 IC_TX_ABRT_SOURCE[14] is also set,  then the slave transmitter has lost arbitration. */
            __IM uint32_t ABRT_SLVFLUSH_TXFIFO : 1; /*!< [13:13] : This field specifies that the Slave has received a
                                                       read command and some data exists in the TX FIFO, so the slave
                                                       issues a TX_ABRT interrupt to flush old data in TX FIFO. */
            __IM uint32_t ABRT_SLV_ARBLOST : 1; /*!< [14:14] : This field indicates that a Slave has lost the bus while
                                                   transmitting data to a remote master. */
            __IM uint32_t ABRT_SLVRD_INTX : 1;  /*!< [15:15] : 1: When the processor side responds to a slave mode
                                                   request for data to be transmitted to a remote master and user writes
                                                   a 1 in CMD (bit 8) of IC_DATA_CMD register. */
            __IM uint32_t
                ABRT_USER_ABRT : 1; /*!< [16:16] : This is a master-mode-only bit Master has detected the transfer abort
                                       (IC_ENABLE[1]) Role of DW_apb_i2c: Master-Transmitter. */
            __IM uint32_t ABRT_SDA_STUCK_AT_LOW : 1; /*!< [17:17] : This is a master-mode-only bit. */
            __IM uint32_t
                ABRT_DEVICE_NOACK : 1; /*!< [18:18] : This is a master-mode-only bit Master is initiating the DEVICEJD
                                          transfer  and the device id sent was not acknowledged by any slave. */
            __IM uint32_t ABRT_DEVICE_SLVADDR_NOACK : 1; /*!< [19:19] : This is a master-mode-only bit Master is
                                                            initiating the DEVICEJD transfer  and the slave address sent
                                                            was not acknowledged by any slave. */
            __IM uint32_t ABRT_DEVICE_WRITE : 1; /*!< [20:20] : This is a master-mode-only bit Master is initiating the
                                                    DEVICE_ID transfer and  the Tx-FIFO consists of write commands. */
            uint32_t      RSV_0        : 2;      /*!< [22:21] : reserved. */
            __IM uint32_t TX_FLUSH_CNT : 9;      /*!< [31:23] : This field indicates the number of Tx FIFO Data Commands
                                                    which are flushed due to TX_ABRT interrupt. */
        } IC_TX_ABRT_SOURCEb;
    };

    union
    {
        __IOM uint32_t IC_SLV_DATA_NACK_ONLY; /*!< 0x00000084 */

        struct
        {
            __IOM uint32_t NACK  : 1;  /*!< [0:0] : Generate NACK. */
            uint32_t       RSV_0 : 31; /*!< [31:1] : reserved. */
        } IC_SLV_DATA_NACK_ONLYb;
    };

    union
    {
        __IOM uint32_t IC_DMA_CR; /*!< 0x00000088 */

        struct
        {
            __IOM uint32_t RDMAE : 1;  /*!< [0:0] : Receive DMA Enable. */
            __IOM uint32_t TDMAE : 1;  /*!< [1:1] : Transmit DMA Enable. */
            uint32_t       RSV_0 : 30; /*!< [31:2] : reserved. */
        } IC_DMA_CRb;
    };

    union
    {
        __IOM uint32_t IC_DMA_TDLR; /*!< 0x0000008c */

        struct
        {
            __IOM uint32_t DMATDL : 4;  /*!< [3:0] : Transmit Data Level. */
            uint32_t       RSV_0  : 28; /*!< [31:4] : reserved. */
        } IC_DMA_TDLRb;
    };

    union
    {
        __IOM uint32_t IC_DMA_RDLR; /*!< 0x00000090 */

        struct
        {
            __IOM uint32_t DMARD : 4;  /*!< [3:0] : Receive Data Level. */
            uint32_t       RSV_0 : 28; /*!< [31:4] : reserved. */
        } IC_DMA_RDLRb;
    };

    union
    {
        __IOM uint32_t IC_SDA_SETUP; /*!< 0x00000094 */

        struct
        {
            __IOM uint32_t SDA_SETUP : 8;  /*!< [7:0] : SDA Setup. */
            uint32_t       RSV_0     : 24; /*!< [31:8] : reserved. */
        } IC_SDA_SETUPb;
    };

    union
    {
        __IOM uint32_t IC_ACK_GENERAL_CALL; /*!< 0x00000098 */

        struct
        {
            __IOM uint32_t ACK_GEN_CALL : 1;  /*!< [0:0] : ACK General Call. */
            uint32_t       RSV_0        : 31; /*!< [31:1] : reserved. */
        } IC_ACK_GENERAL_CALLb;
    };

    union
    {
        __IM uint32_t IC_ENABLE_STATUS; /*!< 0x0000009c */

        struct
        {
            __IM uint32_t IC_EN                   : 1;  /*!< [0:0] : ic_en Status. */
            __IM uint32_t SLV_DISABLED_WHILE_BUSY : 1;  /*!< [1:1] : Slave Disabled While Busy (Transmit, Receive). */
            __IM uint32_t SLV_RX_DATA_LOST        : 1;  /*!< [2:2] : Slave Received Data Lost. */
            uint32_t      RSV_0                   : 29; /*!< [31:3] : reserved. */
        } IC_ENABLE_STATUSb;
    };

    union /*!< share_reg_3_begin */ /*!< 0x000000a0 */
    {
        union
        {
            __IOM uint32_t IC_FS_SPKLEN; /*!< 0x000000a0 */

            struct
            {
                __IOM uint32_t IC_FS_SPKLEN : 8; /*!< [7:0] : This register must be set before any I2C bus transaction
                                                    can take place to ensure stable operation. */
                uint32_t RSV_0 : 24;             /*!< [31:8] : reserved. */
            } IC_FS_SPKLENb;
        };

        union
        {
            __IOM uint32_t IC_UFM_SPKLEN; /*!< 0x000000a0 */

            struct
            {
                __IOM uint32_t IC_UFM_SPKLEN : 8; /*!< [7:0] : This register must be set before any I2C bus transaction
                                                     can take place to ensure stable operation. */
                uint32_t RSV_0 : 24;              /*!< [31:8] : reserved. */
            } IC_UFM_SPKLENb;
        };

    }; /*!< share_reg_3_end */

    union
    {
        __IOM uint32_t IC_HS_SPKLEN; /*!< 0x000000a4 */

        struct
        {
            __IOM uint32_t IC_HS_SPKLEN : 8; /*!< [7:0] : This register must be set before any I2C bus transaction can
                                                take place to ensure stable operation. */
            uint32_t RSV_0 : 24;             /*!< [31:8] : reserved. */
        } IC_HS_SPKLENb;
    };

    union
    {
        __IM uint32_t IC_CLR_RESTART_DET; /*!< 0x000000a8 */

        struct
        {
            __IM uint32_t CLR_RESTART_DET : 1; /*!< [0:0] : Read this register to clear the RESTART DET interrupt (bit
                                                  12) of IC_RAW_INTR_STAT register. */
            uint32_t RSV_0 : 31;               /*!< [31:1] : reserved. */
        } IC_CLR_RESTART_DETb;
    };

    union
    {
        __IOM uint32_t IC_SCL_STUCK_AT_LOW_TIMEOUT; /*!< 0x000000ac */

        struct
        {
            __IOM uint32_t
                IC_SCL_STUCK_LOW_TIMEOUT : 32; /*!< [31:0] : DW_apb_i2c generate the interrupt to indicate SCL stuck at
                                                  low(SCL~STUCK_AT_LOW)  if it detects the SCL stuck at low for the
                                                  IC_SCI^sfuCK_LOW_TIMEOUT in units of ic_clk period. */
        } IC_SCL_STUCK_AT_LOW_TIMEOUTb;
    };

    union
    {
        __IOM uint32_t IC_SDA_STUCK_AT_LOW_TIMEOUT; /*!< 0x000000b0 */

        struct
        {
            __IOM uint32_t IC_SDA_STUCK_LOW_TIMEOUT : 32; /*!< [31:0] : DW_apb_i2c initiates the recovery of SDA line
                                                             through enablingThe  SDA_STUCK_RECOVERY_EN (IC_ENABLE[3])
                                                             register bit, if it detects the SDA stuck at  low forthe
                                                             IC_SDA_STUCK_LOW_TIMEOUT in units of ic_clk period. */
        } IC_SDA_STUCK_AT_LOW_TIMEOUTb;
    };

    union
    {
        __IM uint32_t IC_CLR_SCL_STUCK_DET; /*!< 0x000000b4 */

        struct
        {
            __IM uint32_t CLR_SCL_STUCK_DET : 1; /*!< [0:0] : Read this register to clear the SCL_STUCT_AT_LOW interrupt
                                                    (bit 15) of the IC_RAW_INTR_STAT register. */
            uint32_t RSV_0 : 31;                 /*!< [31:1] : reserved. */
        } IC_CLR_SCL_STUCK_DETb;
    };

    union
    {
        __IM uint32_t IC_DEVICE_ID; /*!< 0x000000b8 */

        struct
        {
            __IM uint32_t DEVICE_ID : 24; /*!< [23:0] : Contains the Device-ID of the component assigned through the
                                             configuration  parameter 'IC_DEVICE_ID_VALUE'. */
            uint32_t RSV_0 : 8;           /*!< [31:24] : reserved. */
        } IC_DEVICE_IDb;
    };

    union
    {
        __IOM uint32_t IC_SMBUS_CLK_LOW_SEXT; /*!< 0x000000bc */

        struct
        {
            __IOM uint32_t
                SMBUS_CLK_LOW_SEXT_TIMEOUT : 32; /*!< [31:0] : This field is used to detect the Slave Clock Extend
                                                    timeout (tLOW:SEXT) in master mode extended by the slave device in
                                                    one message from the initial START to the STOP. */
        } IC_SMBUS_CLK_LOW_SEXTb;
    };

    union
    {
        __IOM uint32_t IC_SMBUS_CLK_LOW_MEXT; /*!< 0x000000c0 */

        struct
        {
            __IOM uint32_t SMBUS_CLK_LOW_MEXT_TIMEOUT : 32; /*!< [31:0] : This field is used to detect the Master extend
                                                               SMBus clock (SCLK) timeout  defined from START-to-ACK,
                                                               ACK-to-ACK, or ACK-to-STOP in Master mode. */
        } IC_SMBUS_CLK_LOW_MEXTb;
    };

    union
    {
        __IOM uint32_t IC_SMBUS_THIGH_MAX_IDLE_COUNT; /*!< 0x000000c4 */

        struct
        {
            __IOM uint32_t SMBUS_THIGH_MAX_BUS_IDLE_CNT : 16; /*!< [15:0] : This field is used to set the required
                                                                 Bus-Idle time period used when a master has been
                                                                 dynamically added to the bus and may not have detected
                                                                 a state transition on the SMBCLK or SMBDAT lines. */
            uint32_t RSV_0 : 16;                              /*!< [31:16] : reserved. */
        } IC_SMBUS_THIGH_MAX_IDLE_COUNTb;
    };

    union
    {
        __IM uint32_t IC_SMBUS_INTR_STAT; /*!< 0x000000c8 */

        struct
        {
            __IM uint32_t R_SLV_CLOCK_EXTND_TIMEOUT : 1; /*!< [0:0] : See IC_SMBUS_INTR_RAW_STATUS for a detailed
                                                            description of R_SLV_CLOCI^EXTND_TIMEOUT bit. */
            __IM uint32_t R_MST_CLOCK_EXTND_TIMEOUT : 1; /*!< [1:1] : See IC_S M B U S_l NTR_RAW_STATUS fora detailed
                                                            description of R_MSTjCLOCK_EXTND_TIMEOUT bit. */
            __IM uint32_t R_QUICK_CMD_DET : 1; /*!< [2:2] : See IC_SMBUS_INTR_RAW_STATUS for a detailed description of
                                                  R_QUICK_CMD_DET bit. */
            __IM uint32_t R_HOST_NOTIFY_MST_DET : 1; /*!< [3:3] : See IC_SMBUS_INTR_RAW_STATUS for a detailed
                                                        description of R_HOST_NOTIFY_MST_DET bit. */
            __IM uint32_t R_ARP_PREPARE_CMD_DET : 1; /*!< [4:4] : See IC_SMBUS_INTR_RAW_STATUS fora detailed description
                                                        of R_ARP_PREPARE_CMD_DET bit. */
            __IM uint32_t R_ARP_RST_CMD_DET : 1; /*!< [5:5] : See IC_SMBUS_INTR_RAW_STATUS for a detailed description of
                                                    R_ARP_RST_CMD_DET bit. */
            __IM uint32_t R_ARP_GET_UDID_CMD_DET : 1;   /*!< [6:6] : See IC_SMBUS_INTR_RAW_STATUS for a detailed
                                                           description of R_ARP_GET_UDID_CMD_DET bit. */
            __IM uint32_t R_ARP_ASSGN_ADDR_CMD_DET : 1; /*!< [7:7] : See IC_SMBUS_INTR_RAW_STATUS fora detailed
                                                           description of R_ARP^ASSGN_ADDR_CMD_DET bit. */
            __IM uint32_t R_SLV_RX_PEC_NACK : 1; /*!< [8:8] : See IC_SMBUS_INTR_RAW_STATUS fora detailed description of
                                                    R_SLV_RX_PEC_NACK bit. */
            __IM uint32_t R_SMBUS_SUSPEND_DET : 1; /*!< [9:9] : See IC_SMBUS_INTR_RAW_STATUS for a detailed description
                                                      of R_SMBUS_SUSPEND_DET bit. */
            __IM uint32_t R_SMBUS_ALERT_DET : 1; /*!< [10:10] : See IC_SMBUS_INTR_RAW_STATUS for a detailed description
                                                    of R_SMBUS_ALERT_DET bit. */
            uint32_t RSV_0 : 21;                 /*!< [31:11] : reserved. */
        } IC_SMBUS_INTR_STATb;
    };

    union
    {
        __IOM uint32_t IC_SMBUS_INTR_MASK; /*!< 0x000000cc */

        struct
        {
            __IOM uint32_t M_SLV_CLOCK_EXTND_TIMEOUT : 1; /*!< [0:0] : This bit masks the R_SLV_CLOCK_EXTND_TIMEOUT
                                                             interrupt in IC_SMBUS_INTR_STAT register. */
            __IOM uint32_t M_MST_CLOCK_EXTND_TIMEOUT : 1; /*!< [1:1] : This bit masks the R_MST_CLOCK_EXTND_TIMEOUT
                                                             interrupt in IC_SMBUS_lNTR_STAT register. */
            __IOM uint32_t M_QUICK_CMD_DET : 1;           /*!< [2:2] : This bit masks the R_QUICK_CMD_DET interrupt in
                                                             IC_SMBUS_INTR_STAT register. */
            __IOM uint32_t M_HOST_NOTIFY_MST_DET : 1; /*!< [3:3] : This bit masks the R_HOST_NOTIFY_MST_DET interrupt in
                                                         IC_SMBUS_INTR_STAT register. */
            __IOM uint32_t M_ARP_PREPARE_CMD_DET : 1; /*!< [4:4] : This bit masks the R_ARP_PREPARE_CMD_DET interrupt in
                                                         IC_SMBUS_INTRZSTAT register. */
            __IOM uint32_t M_ARP_RST_CMD_DET : 1;     /*!< [5:5] : This bit masks the R_ARP_RST_CMD_DET interrupt in
                                                         IC_SMBUSJNTR_STAT register. */
            __IOM uint32_t M_ARP_GET_UDID_CMD_DET : 1; /*!< [6:6] : This bit masks the R_ARP_GET_UDID_CMD_DET interrupt
                                                          in IC_SMBUS_INTFCSTAT register. */
            __IOM uint32_t M_ARP_ASSGN_ADDR_CMD_DET : 1; /*!< [7:7] : This bit masks the R_ARP_ASSGN_ADDR_CMD_DET
                                                            interrupt in IC_SMBUS_INTR_STAT register. */
            __IOM uint32_t M_SLV_RX_PEC_NACK : 1;        /*!< [8:8] : This bit masks the R_SLV_RX_PEC_NACK interrupt in
                                                            IC_SMBUSJNTR_STAT register. */
            __IOM uint32_t R_SMBUS_SUSPEND_DET : 1; /*!< [9:9] : This bit masks the R_SMBUS_SUSPEND_DET interrupt in
                                                       IC_SMBUSJNTR_STAT register. */
            __IOM uint32_t M_SMBUS_ALERT_DET : 1; /*!< [10:10] : This bit masks the R_SMBUS_ALERT_DET interrupt in IC_SM
                                                     B US J NTR_STAT register. */
            uint32_t RSV_0 : 21;                  /*!< [31:11] : reserved. */
        } IC_SMBUS_INTR_MASKb;
    };

    union
    {
        __IM uint32_t IC_SMBUS_RAW_INTR_STAT; /*!< 0x000000d0 */

        struct
        {
            __IM uint32_t SLV_CLOCK_EXTND_TIMEOUT : 1; /*!< [0:0] : Indicates whether the transaction from Slave (i. */
            __IM uint32_t
                MST_CLOCK_EXTND_TIMEOUT : 1; /*!< [1:1] : Indicates whether the Master device transaction (START-to-ACK,
                                                ACK-to-ACK, or ACK-to-STOP)  from START to STOP exceeds
                                                IC_SMBUS_CLOCK_LOW_MEXT time with in each byte of message. */
            __IM uint32_t QUICK_CMD_DET : 1; /*!< [2:2] : Indicates whether a Quick command has been received on the
                                                SMBus interface regardless of whether DW_apb_i2c is operating in slave
                                                or master mode. */
            __IM uint32_t HOST_NTFY_MST_DET : 1; /*!< [3:3] : Indicates whether a Notify ARP Master ARP command has been
                                                    received. */
            __IM uint32_t
                ARP_PREPARE_CMD_DET : 1; /*!< [4:4] : Indicates whether a prepare to ARP command has been received. */
            __IM uint32_t ARP_RST_CMD_DET : 1; /*!< [5:5] : Indicates whether a General or Directed Reset ARP command
                                                  has been received. */
            __IM uint32_t
                ARP_GET_UDID_CMD_DET : 1; /*!< [6:6] : Indicates whether a Get UDID ARP command has been received. */
            __IM uint32_t ARP_ASSGN_ADDR_CMD_DET : 1; /*!< [7:7] : Indicates whether an Assign Address ARP command has
                                                         been received. */
            __IM uint32_t SLV_RX_PEC_NACK : 1;   /*!< [8:8] : Indicates whether a NACK has been sent due to PEC mismatch
                                                    while working as ARP slave. */
            __IM uint32_t SMBUS_SUSPEND_DET : 1; /*!< [9:9] : Indicates whether a SMBSUS (ic_smbsus_in_n) signal is
                                                    driven low by the Host. */
            __IM uint32_t SMBUS_ALERT_DET : 1; /*!< [10:10] : Indicates whether a SMBALERT (ic_smbalert_in_n) signal is
                                                  driven low by the slave. */
            uint32_t RSV_0 : 21;               /*!< [31:11] : reserved. */
        } IC_SMBUS_RAW_INTR_STATb;
    };

    union
    {
        __OM uint32_t IC_CLR_SMBUS_INTR; /*!< 0x000000d4 */

        struct
        {
            __OM uint32_t CLR_SLV_CLOCK_EXTND_TIMEOUT : 1; /*!< [0:0] : Write this register bit to clear the
                                                              SLV_CLOCK_EXTND_TIMEOUT interrupt (bit 0) of the
                                                              IC_SMBUS_RAW_INTR_STAT register. */
            __OM uint32_t CLR_MST_CLOCK_EXTND_TIMEOUT : 1; /*!< [1:1] : Write this register bit to clear the
                                                              MST_CLOCK_EXTND_TIMEOUT interrupt (bit 1)of the
                                                              IC_SMBUS_RAW_INTR_STAT register. */
            __OM uint32_t CLR_QUICK_CMD_DET : 1; /*!< [2:2] : Write this register bit to clear the QUICK_CMD_DET
                                                    interrupt (bit 2) of  the IC_SMBUS_RAW_INTR_STAT register. */
            __OM uint32_t
                CLR_HOST_NOTIFY_MST_DET : 1; /*!< [3:3] : Write this register bit to clear the HOST_NOTIFY_MST_DET
                                                interrupt (bit 3) of the IC_SMBUS_RAwLlNTR_STAT register. */
            __OM uint32_t
                CLR_ARP_PREPARE_CMD_DET : 1;       /*!< [4:4] : Write this register bit to clear the ARP_PREPARE_CMD_DET
                                                      interrupt (bit 4)  of the IC_SMBUS_RAW_INTR_STAT register. */
            __OM uint32_t CLR_ARP_RST_CMD_DET : 1; /*!< [5:5] : Write this register bit to clear the ARP_RST_CMD_DET
                                                      interrupt (bit 5)  of the IC_SMBUS_RAW_INfR_STAT register. */
            __OM uint32_t
                CLR_ARP_GET_UDID_CMD_DET : 1; /*!< [6:6] : Write this register bit to clear the ARP_GET_UDID_CMD_DET
                                                 interrupt (bit 6)  of the IC SMBUS RAW INTR STAT register. */
            __OM uint32_t
                CLR_ARP_ASSGN_ADDR_CMD_DET : 1; /*!< [7:7] : Write this register bit to clear the ARP_ASSGN_ADDR_CMD_DET
                                                   interrupt (bit 7) of the IC SMBUS 臥W INTR STAT register. */
            __OM uint32_t CLR_SLV_RX_PEC_NACK : 1;   /*!< [8:8] : Write this register bit to clear the SLV_RX_PEC_NACK
                                                        interrupt (bit 8)  of the IC_SMBUS_RAW_INTR_STAT register. */
            __OM uint32_t CLR_SMBUS_SUSPEND_DET : 1; /*!< [9:9] : Write this register bit to clear the SMBUS_SUSPEND_DET
                                                        interrupt (bit 9)  of the IC_SMBUS_RAW_INTR_STAT register. */
            __OM uint32_t CLR_SMBUS_ALERT_DET : 1;   /*!< [10:10] : Write this register bit to clear the SMBUS_ALERT_DET
                                                        interrupt (bit 10) of  the IC_SMBUS_RAW_INTR_STAT register. */
            uint32_t RSV_0 : 21;                     /*!< [31:11] : reserved. */
        } IC_CLR_SMBUS_INTRb;
    };

    union
    {
        __IOM uint32_t IC_OPTIONAL_SAR; /*!< 0x000000d8 */

        struct
        {
            __IOM uint32_t OPTIONAL_SAR : 7; /*!< [6:0] : Optional Slave address for DW_apb_i2c when operating as a
                                                slave in SMBus Mode. */
            uint32_t RSV_0 : 25;             /*!< [31:7] : reserved. */
        } IC_OPTIONAL_SARb;
    };

    union /*!< share_reg_4_begin */ /*!< 0x000000dc */
    {
        union
        {
            __IOM uint32_t IC_SMBUS_UDID_LSB; /*!< 0x000000dc */

            struct
            {
                __IOM uint32_t
                    SMBUS_UDID_LSB : 32; /*!< [31:0] : This field is used to store the LSB 32 bit value of slave unique
                                            device identifier used in Address Resolution Protocol. */
            } IC_SMBUS_UDID_LSBb;
        };

        union
        {
            __IOM uint32_t IC_SMBUS_UDID_WORD0; /*!< 0x000000dc */

            struct
            {
                __IOM uint32_t
                    SMBUS_UDID_WORD0 : 32; /*!< [31:0] : This field is used to store the Lower 32 bit value of slave
                                              unique device identifier  used in Address Resolution Protocol. */
            } IC_SMBUS_UDID_WORD0b;
        };

    }; /*!< share_reg_4_end */

    union
    {
        __IOM uint32_t IC_SMBUS_UDID_WORD1; /*!< 0x000000e0 */

        struct
        {
            __IOM uint32_t
                SMBUS_UDID_WORD1 : 32; /*!< [31:0] : This field is used to store the Middle-Lower 32 bit value of slave
                                          unique device identifier  used in Address Resolution Protocol. */
        } IC_SMBUS_UDID_WORD1b;
    };

    union
    {
        __IOM uint32_t IC_SMBUS_UDID_WORD2; /*!< 0x000000e4 */

        struct
        {
            __IOM uint32_t
                SMBUS_UDID_WORD2 : 32; /*!< [31:0] : This field is used to store the Middle-Upper 32 bit value of slave
                                          unique device identifier used in Address Resolution Protocol. */
        } IC_SMBUS_UDID_WORD2b;
    };

    union
    {
        __IOM uint32_t IC_SMBUS_UDID_WORD3; /*!< 0x000000e8 */

        struct
        {
            __IOM uint32_t
                SMBUS_UDID_WORD3 : 32; /*!< [31:0] : This field is used to store the Upper 32 bit value of slave unique
                                          device  identifier used in Address Resolution Protocol. */
        } IC_SMBUS_UDID_WORD3b;
    };

    uint8_t RSV_0XEC[4]; /*!< 0x000000ec~0x000000ef : reserved */

    union
    {
        __IOM uint32_t REG_TIMEOUT_RST; /*!< 0x000000f0 */

        struct
        {
            __IOM uint32_t
                REG_TIMEOUT_RST_RW : 4;  /*!< [3:0] : This field holds reset value of REG_TIMEOUT counter register. */
            uint32_t RSV_0         : 28; /*!< [31:4] : reserved. */
        } REG_TIMEOUT_RSTb;
    };

    union
    {
        __IM uint32_t IC_COMP_PARAM_1; /*!< 0x000000f4 */

        struct
        {
            __IM uint32_t APB_DATA_WIDTH : 2; /*!< [1:0] : The value of this register is derived from the APB_DATA_WIDTH
                                                 coreConsultant parameter. */
            __IM uint32_t MAX_SPEED_MODE : 2; /*!< [3:2] : The value of this register is derived from the
                                                 IC_MAX_SPEED_MODE coreConsultant parameter. */
            __IM uint32_t HC_COUNT_VALUES : 1; /*!< [4:4] : The value of this register is derived from the IC_HC_COUNT
                                                  VALUES coreConsultant parameter. */
            __IM uint32_t INTR_IO : 1;         /*!< [5:5] : The value of this register is derived from the ICJNTR IO
                                                  coreConsultant parameter. */
            __IM uint32_t HAS_DMA : 1;         /*!< [6:6] : The value of this register is derived from the IC_HAS_DMA
                                                  coreConsultant parameter. */
            __IM uint32_t ADD_ENCODED_PARAMS : 1; /*!< [7:7] : The value of this register is derived from the
                                                     IC_ADD_ENCODED_PARAMS coreConsultant parameter. */
            __IM uint32_t RX_BUFFER_DEPTH : 8;    /*!< [15:8] : The value of this register is derived from the
                                                     IC_RX_BUFFER_DEPTH coreConsultant parameter. */
            __IM uint32_t TX_BUFFER_DEPTH : 8;    /*!< [23:16] : The value of this register is derived from the
                                                     IC_TX_BUFFER_DEPTH coreConsultant parameter. */
            uint32_t RSV_0 : 8;                   /*!< [31:24] : reserved. */
        } IC_COMP_PARAM_1b;
    };

    union
    {
        __IM uint32_t IC_COMP_VERSION; /*!< 0x000000f8 */

        struct
        {
            __IM uint32_t IC_COMP_VERSION : 32; /*!< [31:0] : Specific values for this register are described in the
                                                   Releases Table in the DW_apb_i2c Release Notes. */
        } IC_COMP_VERSIONb;
    };

    union
    {
        __IM uint32_t IC_COMP_TYPE; /*!< 0x000000fc */

        struct
        {
            __IM uint32_t IC_COMP_TYPE : 32; /*!< [31:0] : Design ware Component Type number = 0x44_57_01_40. */
        } IC_COMP_TYPEb;
    };

} I2C_Type;

/*! \brief PMBUS register */
typedef I2C_Type PMBUS_Type;

/*!
 * @}
 */

/*!
 * \name I2C Base Address Definitions
 *
 * @{
 */

/*! \brief I2CA base address */
#define I2CA_BASE (0x42500000UL)
/*! \brief I2CB base address */
#define I2CB_BASE (0x42501000UL)
/*! \brief I2CA base pointer */
#define I2CA ((I2C_Type *) I2CA_BASE)
/*! \brief I2CB base pointer */
#define I2CB ((I2C_Type *) I2CB_BASE)

/*! \brief PMBUSA base address */
#define PMBUSA_BASE (0x42400000UL)
/*! \brief PMBUSA base pointer */
#define PMBUSA ((PMBUS_Type *) PMBUSA_BASE)

/*!
 * @}
 */


/*!
 * \name I2C Register Bitfield Definitions
 *
 * @{
 */

/* IC_CON bitfield */
#define I2C_IC_CON_SMBUS_PERSISTENT_SLV_ADDR_EN_Pos (19U) /*!< SMBUS_PERSISTENT_SLV_ADDR_EN Postion   19         */
#define I2C_IC_CON_SMBUS_PERSISTENT_SLV_ADDR_EN_Msk \
    (0x1U << I2C_IC_CON_SMBUS_PERSISTENT_SLV_ADDR_EN_Pos) /*!< SMBUS_PERSISTENT_SLV_ADDR_EN Mask      0x00080000 */
#define I2C_IC_CON_SMBUS_PERSISTENT_SLV_ADDR_EN_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_CON_SMBUS_PERSISTENT_SLV_ADDR_EN_Pos) & \
     I2C_IC_CON_SMBUS_PERSISTENT_SLV_ADDR_EN_Msk) /*!< SMBUS_PERSISTENT_SLV_ADDR_EN Set Value            */
#define I2C_IC_CON_SMBUS_PERSISTENT_SLV_ADDR_EN_Get(x)                \
    (((uint32_t) (x) &I2C_IC_CON_SMBUS_PERSISTENT_SLV_ADDR_EN_Msk) >> \
     I2C_IC_CON_SMBUS_PERSISTENT_SLV_ADDR_EN_Pos) /*!< SMBUS_PERSISTENT_SLV_ADDR_EN Get Value            */


#define I2C_IC_CON_SMBUS_ARP_EN_Pos (18U)                                 /*!< SMBUS_ARP_EN Postion   18         */
#define I2C_IC_CON_SMBUS_ARP_EN_Msk (0x1U << I2C_IC_CON_SMBUS_ARP_EN_Pos) /*!< SMBUS_ARP_EN Mask      0x00040000 */
#define I2C_IC_CON_SMBUS_ARP_EN_Set(x) \
    (((uint32_t) (x) << I2C_IC_CON_SMBUS_ARP_EN_Pos) & I2C_IC_CON_SMBUS_ARP_EN_Msk) /*!< SMBUS_ARP_EN Set Value */
#define I2C_IC_CON_SMBUS_ARP_EN_Get(x) \
    (((uint32_t) (x) &I2C_IC_CON_SMBUS_ARP_EN_Msk) >> I2C_IC_CON_SMBUS_ARP_EN_Pos) /*!< SMBUS_ARP_EN Get Value */


#define I2C_IC_CON_SMBUS_SLAVE_QUICK_EN_Pos (17U) /*!< SMBUS_SLAVE_QUICK_EN Postion   17         */
#define I2C_IC_CON_SMBUS_SLAVE_QUICK_EN_Msk \
    (0x1U << I2C_IC_CON_SMBUS_SLAVE_QUICK_EN_Pos) /*!< SMBUS_SLAVE_QUICK_EN Mask      0x00020000 */
#define I2C_IC_CON_SMBUS_SLAVE_QUICK_EN_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_CON_SMBUS_SLAVE_QUICK_EN_Pos) & \
     I2C_IC_CON_SMBUS_SLAVE_QUICK_EN_Msk) /*!< SMBUS_SLAVE_QUICK_EN Set Value            */
#define I2C_IC_CON_SMBUS_SLAVE_QUICK_EN_Get(x)                \
    (((uint32_t) (x) &I2C_IC_CON_SMBUS_SLAVE_QUICK_EN_Msk) >> \
     I2C_IC_CON_SMBUS_SLAVE_QUICK_EN_Pos) /*!< SMBUS_SLAVE_QUICK_EN Get Value            */


#define I2C_IC_CON_OPTIONAL_SAR_CTRL_Pos (16U) /*!< OPTIONAL_SAR_CTRL Postion   16         */
#define I2C_IC_CON_OPTIONAL_SAR_CTRL_Msk \
    (0x1U << I2C_IC_CON_OPTIONAL_SAR_CTRL_Pos) /*!< OPTIONAL_SAR_CTRL Mask      0x00010000 */
#define I2C_IC_CON_OPTIONAL_SAR_CTRL_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_CON_OPTIONAL_SAR_CTRL_Pos) & \
     I2C_IC_CON_OPTIONAL_SAR_CTRL_Msk) /*!< OPTIONAL_SAR_CTRL Set Value            */
#define I2C_IC_CON_OPTIONAL_SAR_CTRL_Get(x)                \
    (((uint32_t) (x) &I2C_IC_CON_OPTIONAL_SAR_CTRL_Msk) >> \
     I2C_IC_CON_OPTIONAL_SAR_CTRL_Pos) /*!< OPTIONAL_SAR_CTRL Get Value            */


#define I2C_IC_CON_BUS_CLEAR_FEATURE_CTRL_Pos (11U) /*!< BUS_CLEAR_FEATURE_CTRL Postion   11         */
#define I2C_IC_CON_BUS_CLEAR_FEATURE_CTRL_Msk \
    (0x1U << I2C_IC_CON_BUS_CLEAR_FEATURE_CTRL_Pos) /*!< BUS_CLEAR_FEATURE_CTRL Mask      0x00000800 */
#define I2C_IC_CON_BUS_CLEAR_FEATURE_CTRL_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_CON_BUS_CLEAR_FEATURE_CTRL_Pos) & \
     I2C_IC_CON_BUS_CLEAR_FEATURE_CTRL_Msk) /*!< BUS_CLEAR_FEATURE_CTRL Set Value            */
#define I2C_IC_CON_BUS_CLEAR_FEATURE_CTRL_Get(x)                \
    (((uint32_t) (x) &I2C_IC_CON_BUS_CLEAR_FEATURE_CTRL_Msk) >> \
     I2C_IC_CON_BUS_CLEAR_FEATURE_CTRL_Pos) /*!< BUS_CLEAR_FEATURE_CTRL Get Value            */


#define I2C_IC_CON_STOP_DET_IF_MASTER_ACTIVE_Pos (10U) /*!< STOP_DET_IF_MASTER_ACTIVE Postion   10         */
#define I2C_IC_CON_STOP_DET_IF_MASTER_ACTIVE_Msk \
    (0x1U << I2C_IC_CON_STOP_DET_IF_MASTER_ACTIVE_Pos) /*!< STOP_DET_IF_MASTER_ACTIVE Mask      0x00000400 */
#define I2C_IC_CON_STOP_DET_IF_MASTER_ACTIVE_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_CON_STOP_DET_IF_MASTER_ACTIVE_Pos) & \
     I2C_IC_CON_STOP_DET_IF_MASTER_ACTIVE_Msk) /*!< STOP_DET_IF_MASTER_ACTIVE Set Value            */
#define I2C_IC_CON_STOP_DET_IF_MASTER_ACTIVE_Get(x)                \
    (((uint32_t) (x) &I2C_IC_CON_STOP_DET_IF_MASTER_ACTIVE_Msk) >> \
     I2C_IC_CON_STOP_DET_IF_MASTER_ACTIVE_Pos) /*!< STOP_DET_IF_MASTER_ACTIVE Get Value            */


#define I2C_IC_CON_RX_FIFO_FULL_HOLD_CTRL_Pos (9U) /*!< RX_FIFO_FULL_HOLD_CTRL Postion   9          */
#define I2C_IC_CON_RX_FIFO_FULL_HOLD_CTRL_Msk \
    (0x1U << I2C_IC_CON_RX_FIFO_FULL_HOLD_CTRL_Pos) /*!< RX_FIFO_FULL_HOLD_CTRL Mask      0x00000200 */
#define I2C_IC_CON_RX_FIFO_FULL_HOLD_CTRL_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_CON_RX_FIFO_FULL_HOLD_CTRL_Pos) & \
     I2C_IC_CON_RX_FIFO_FULL_HOLD_CTRL_Msk) /*!< RX_FIFO_FULL_HOLD_CTRL Set Value            */
#define I2C_IC_CON_RX_FIFO_FULL_HOLD_CTRL_Get(x)                \
    (((uint32_t) (x) &I2C_IC_CON_RX_FIFO_FULL_HOLD_CTRL_Msk) >> \
     I2C_IC_CON_RX_FIFO_FULL_HOLD_CTRL_Pos) /*!< RX_FIFO_FULL_HOLD_CTRL Get Value            */


#define I2C_IC_CON_TX_EMPTY_CTRL_Pos (8U)                                   /*!< TX_EMPTY_CTRL Postion   8          */
#define I2C_IC_CON_TX_EMPTY_CTRL_Msk (0x1U << I2C_IC_CON_TX_EMPTY_CTRL_Pos) /*!< TX_EMPTY_CTRL Mask      0x00000100 */
#define I2C_IC_CON_TX_EMPTY_CTRL_Set(x) \
    (((uint32_t) (x) << I2C_IC_CON_TX_EMPTY_CTRL_Pos) & I2C_IC_CON_TX_EMPTY_CTRL_Msk) /*!< TX_EMPTY_CTRL Set Value */
#define I2C_IC_CON_TX_EMPTY_CTRL_Get(x) \
    (((uint32_t) (x) &I2C_IC_CON_TX_EMPTY_CTRL_Msk) >> I2C_IC_CON_TX_EMPTY_CTRL_Pos) /*!< TX_EMPTY_CTRL Get Value */


#define I2C_IC_CON_STOP_DET_IFADDRESSED_Pos (7U) /*!< STOP_DET_IFADDRESSED Postion   7          */
#define I2C_IC_CON_STOP_DET_IFADDRESSED_Msk \
    (0x1U << I2C_IC_CON_STOP_DET_IFADDRESSED_Pos) /*!< STOP_DET_IFADDRESSED Mask      0x00000080 */
#define I2C_IC_CON_STOP_DET_IFADDRESSED_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_CON_STOP_DET_IFADDRESSED_Pos) & \
     I2C_IC_CON_STOP_DET_IFADDRESSED_Msk) /*!< STOP_DET_IFADDRESSED Set Value            */
#define I2C_IC_CON_STOP_DET_IFADDRESSED_Get(x)                \
    (((uint32_t) (x) &I2C_IC_CON_STOP_DET_IFADDRESSED_Msk) >> \
     I2C_IC_CON_STOP_DET_IFADDRESSED_Pos) /*!< STOP_DET_IFADDRESSED Get Value            */


#define I2C_IC_CON_IC_SLAVE_DISABLE_Pos (6U) /*!< IC_SLAVE_DISABLE Postion   6          */
#define I2C_IC_CON_IC_SLAVE_DISABLE_Msk \
    (0x1U << I2C_IC_CON_IC_SLAVE_DISABLE_Pos) /*!< IC_SLAVE_DISABLE Mask      0x00000040 */
#define I2C_IC_CON_IC_SLAVE_DISABLE_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_CON_IC_SLAVE_DISABLE_Pos) & \
     I2C_IC_CON_IC_SLAVE_DISABLE_Msk) /*!< IC_SLAVE_DISABLE Set Value            */
#define I2C_IC_CON_IC_SLAVE_DISABLE_Get(x)                \
    (((uint32_t) (x) &I2C_IC_CON_IC_SLAVE_DISABLE_Msk) >> \
     I2C_IC_CON_IC_SLAVE_DISABLE_Pos) /*!< IC_SLAVE_DISABLE Get Value            */


#define I2C_IC_CON_IC_RESTART_EN_Pos (5U)                                   /*!< IC_RESTART_EN Postion   5          */
#define I2C_IC_CON_IC_RESTART_EN_Msk (0x1U << I2C_IC_CON_IC_RESTART_EN_Pos) /*!< IC_RESTART_EN Mask      0x00000020 */
#define I2C_IC_CON_IC_RESTART_EN_Set(x) \
    (((uint32_t) (x) << I2C_IC_CON_IC_RESTART_EN_Pos) & I2C_IC_CON_IC_RESTART_EN_Msk) /*!< IC_RESTART_EN Set Value */
#define I2C_IC_CON_IC_RESTART_EN_Get(x) \
    (((uint32_t) (x) &I2C_IC_CON_IC_RESTART_EN_Msk) >> I2C_IC_CON_IC_RESTART_EN_Pos) /*!< IC_RESTART_EN Get Value */


#define I2C_IC_CON_IC_10BITADDR_MASTER_Pos (4U) /*!< IC_10BITADDR_MASTER Postion   4          */
#define I2C_IC_CON_IC_10BITADDR_MASTER_Msk \
    (0x1U << I2C_IC_CON_IC_10BITADDR_MASTER_Pos) /*!< IC_10BITADDR_MASTER Mask      0x00000010 */
#define I2C_IC_CON_IC_10BITADDR_MASTER_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_CON_IC_10BITADDR_MASTER_Pos) & \
     I2C_IC_CON_IC_10BITADDR_MASTER_Msk) /*!< IC_10BITADDR_MASTER Set Value            */
#define I2C_IC_CON_IC_10BITADDR_MASTER_Get(x)                \
    (((uint32_t) (x) &I2C_IC_CON_IC_10BITADDR_MASTER_Msk) >> \
     I2C_IC_CON_IC_10BITADDR_MASTER_Pos) /*!< IC_10BITADDR_MASTER Get Value            */


#define I2C_IC_CON_IC_10BITADDR_SLAVE_Pos (3U) /*!< IC_10BITADDR_SLAVE Postion   3          */
#define I2C_IC_CON_IC_10BITADDR_SLAVE_Msk \
    (0x1U << I2C_IC_CON_IC_10BITADDR_SLAVE_Pos) /*!< IC_10BITADDR_SLAVE Mask      0x00000008 */
#define I2C_IC_CON_IC_10BITADDR_SLAVE_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_CON_IC_10BITADDR_SLAVE_Pos) & \
     I2C_IC_CON_IC_10BITADDR_SLAVE_Msk) /*!< IC_10BITADDR_SLAVE Set Value            */
#define I2C_IC_CON_IC_10BITADDR_SLAVE_Get(x)                \
    (((uint32_t) (x) &I2C_IC_CON_IC_10BITADDR_SLAVE_Msk) >> \
     I2C_IC_CON_IC_10BITADDR_SLAVE_Pos) /*!< IC_10BITADDR_SLAVE Get Value            */


#define I2C_IC_CON_SPEED_Pos (1U)                           /*!< SPEED Postion   1          */
#define I2C_IC_CON_SPEED_Msk (0x3U << I2C_IC_CON_SPEED_Pos) /*!< SPEED Mask      0x00000006 */
#define I2C_IC_CON_SPEED_Set(x) \
    (((uint32_t) (x) << I2C_IC_CON_SPEED_Pos) & I2C_IC_CON_SPEED_Msk) /*!< SPEED Set Value            */
#define I2C_IC_CON_SPEED_Get(x) \
    (((uint32_t) (x) &I2C_IC_CON_SPEED_Msk) >> I2C_IC_CON_SPEED_Pos) /*!< SPEED Get Value            */


#define I2C_IC_CON_MASTER_MODE_Pos (0U)                                 /*!< MASTER_MODE Postion   0          */
#define I2C_IC_CON_MASTER_MODE_Msk (0x1U << I2C_IC_CON_MASTER_MODE_Pos) /*!< MASTER_MODE Mask      0x00000001 */
#define I2C_IC_CON_MASTER_MODE_Set(x) \
    (((uint32_t) (x) << I2C_IC_CON_MASTER_MODE_Pos) & I2C_IC_CON_MASTER_MODE_Msk) /*!< MASTER_MODE Set Value */
#define I2C_IC_CON_MASTER_MODE_Get(x) \
    (((uint32_t) (x) &I2C_IC_CON_MASTER_MODE_Msk) >> I2C_IC_CON_MASTER_MODE_Pos) /*!< MASTER_MODE Get Value */


/* IC_TAR bitfield */
#define I2C_IC_TAR_SMBUS_QUICK_CMD_Pos (16U) /*!< SMBUS_QUICK_CMD Postion   16         */
#define I2C_IC_TAR_SMBUS_QUICK_CMD_Msk \
    (0x1U << I2C_IC_TAR_SMBUS_QUICK_CMD_Pos) /*!< SMBUS_QUICK_CMD Mask      0x00010000 */
#define I2C_IC_TAR_SMBUS_QUICK_CMD_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_TAR_SMBUS_QUICK_CMD_Pos) & \
     I2C_IC_TAR_SMBUS_QUICK_CMD_Msk) /*!< SMBUS_QUICK_CMD Set Value            */
#define I2C_IC_TAR_SMBUS_QUICK_CMD_Get(x)                \
    (((uint32_t) (x) &I2C_IC_TAR_SMBUS_QUICK_CMD_Msk) >> \
     I2C_IC_TAR_SMBUS_QUICK_CMD_Pos) /*!< SMBUS_QUICK_CMD Get Value            */


#define I2C_IC_TAR_DEVICE_ID_Pos (13U)                              /*!< DEVICE_ID Postion   13         */
#define I2C_IC_TAR_DEVICE_ID_Msk (0x1U << I2C_IC_TAR_DEVICE_ID_Pos) /*!< DEVICE_ID Mask      0x00002000 */
#define I2C_IC_TAR_DEVICE_ID_Set(x) \
    (((uint32_t) (x) << I2C_IC_TAR_DEVICE_ID_Pos) & I2C_IC_TAR_DEVICE_ID_Msk) /*!< DEVICE_ID Set Value            */
#define I2C_IC_TAR_DEVICE_ID_Get(x) \
    (((uint32_t) (x) &I2C_IC_TAR_DEVICE_ID_Msk) >> I2C_IC_TAR_DEVICE_ID_Pos) /*!< DEVICE_ID Get Value            */


#define I2C_IC_TAR_IC_10BITADDR_MASTER_Pos (12U) /*!< IC_10BITADDR_MASTER Postion   12         */
#define I2C_IC_TAR_IC_10BITADDR_MASTER_Msk \
    (0x1U << I2C_IC_TAR_IC_10BITADDR_MASTER_Pos) /*!< IC_10BITADDR_MASTER Mask      0x00001000 */
#define I2C_IC_TAR_IC_10BITADDR_MASTER_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_TAR_IC_10BITADDR_MASTER_Pos) & \
     I2C_IC_TAR_IC_10BITADDR_MASTER_Msk) /*!< IC_10BITADDR_MASTER Set Value            */
#define I2C_IC_TAR_IC_10BITADDR_MASTER_Get(x)                \
    (((uint32_t) (x) &I2C_IC_TAR_IC_10BITADDR_MASTER_Msk) >> \
     I2C_IC_TAR_IC_10BITADDR_MASTER_Pos) /*!< IC_10BITADDR_MASTER Get Value            */


#define I2C_IC_TAR_SPECIAL_Pos (11U)                            /*!< SPECIAL Postion   11         */
#define I2C_IC_TAR_SPECIAL_Msk (0x1U << I2C_IC_TAR_SPECIAL_Pos) /*!< SPECIAL Mask      0x00000800 */
#define I2C_IC_TAR_SPECIAL_Set(x) \
    (((uint32_t) (x) << I2C_IC_TAR_SPECIAL_Pos) & I2C_IC_TAR_SPECIAL_Msk) /*!< SPECIAL Set Value            */
#define I2C_IC_TAR_SPECIAL_Get(x) \
    (((uint32_t) (x) &I2C_IC_TAR_SPECIAL_Msk) >> I2C_IC_TAR_SPECIAL_Pos) /*!< SPECIAL Get Value            */


#define I2C_IC_TAR_GC_OR_START_Pos (10U)                                /*!< GC_OR_START Postion   10         */
#define I2C_IC_TAR_GC_OR_START_Msk (0x1U << I2C_IC_TAR_GC_OR_START_Pos) /*!< GC_OR_START Mask      0x00000400 */
#define I2C_IC_TAR_GC_OR_START_Set(x) \
    (((uint32_t) (x) << I2C_IC_TAR_GC_OR_START_Pos) & I2C_IC_TAR_GC_OR_START_Msk) /*!< GC_OR_START Set Value */
#define I2C_IC_TAR_GC_OR_START_Get(x) \
    (((uint32_t) (x) &I2C_IC_TAR_GC_OR_START_Msk) >> I2C_IC_TAR_GC_OR_START_Pos) /*!< GC_OR_START Get Value */


#define I2C_IC_TAR_IC_TAR_Pos (0U)                              /*!< IC_TAR Postion   0          */
#define I2C_IC_TAR_IC_TAR_Msk (0x3ffU << I2C_IC_TAR_IC_TAR_Pos) /*!< IC_TAR Mask      0x000003FF */
#define I2C_IC_TAR_IC_TAR_Set(x) \
    (((uint32_t) (x) << I2C_IC_TAR_IC_TAR_Pos) & I2C_IC_TAR_IC_TAR_Msk) /*!< IC_TAR Set Value            */
#define I2C_IC_TAR_IC_TAR_Get(x) \
    (((uint32_t) (x) &I2C_IC_TAR_IC_TAR_Msk) >> I2C_IC_TAR_IC_TAR_Pos) /*!< IC_TAR Get Value            */


/* IC_SAR bitfield */
#define I2C_IC_SAR_IC_SAR_Pos (0U)                              /*!< IC_SAR Postion   0          */
#define I2C_IC_SAR_IC_SAR_Msk (0x3ffU << I2C_IC_SAR_IC_SAR_Pos) /*!< IC_SAR Mask      0x000003FF */
#define I2C_IC_SAR_IC_SAR_Set(x) \
    (((uint32_t) (x) << I2C_IC_SAR_IC_SAR_Pos) & I2C_IC_SAR_IC_SAR_Msk) /*!< IC_SAR Set Value            */
#define I2C_IC_SAR_IC_SAR_Get(x) \
    (((uint32_t) (x) &I2C_IC_SAR_IC_SAR_Msk) >> I2C_IC_SAR_IC_SAR_Pos) /*!< IC_SAR Get Value            */


/* IC_HS_MADDR bitfield */
#define I2C_IC_HS_MADDR_IC_HS_MAR_Pos (0U)                                    /*!< IC_HS_MAR Postion   0          */
#define I2C_IC_HS_MADDR_IC_HS_MAR_Msk (0x7U << I2C_IC_HS_MADDR_IC_HS_MAR_Pos) /*!< IC_HS_MAR Mask      0x00000007 */
#define I2C_IC_HS_MADDR_IC_HS_MAR_Set(x) \
    (((uint32_t) (x) << I2C_IC_HS_MADDR_IC_HS_MAR_Pos) & I2C_IC_HS_MADDR_IC_HS_MAR_Msk) /*!< IC_HS_MAR Set Value */
#define I2C_IC_HS_MADDR_IC_HS_MAR_Get(x) \
    (((uint32_t) (x) &I2C_IC_HS_MADDR_IC_HS_MAR_Msk) >> I2C_IC_HS_MADDR_IC_HS_MAR_Pos) /*!< IC_HS_MAR Get Value */


/* IC_DATA_CMD bitfield */
#define I2C_IC_DATA_CMD_FIRST_DATA_BYTE_Pos (11U) /*!< FIRST_DATA_BYTE Postion   11         */
#define I2C_IC_DATA_CMD_FIRST_DATA_BYTE_Msk \
    (0x1U << I2C_IC_DATA_CMD_FIRST_DATA_BYTE_Pos) /*!< FIRST_DATA_BYTE Mask      0x00000800 */
#define I2C_IC_DATA_CMD_FIRST_DATA_BYTE_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_DATA_CMD_FIRST_DATA_BYTE_Pos) & \
     I2C_IC_DATA_CMD_FIRST_DATA_BYTE_Msk) /*!< FIRST_DATA_BYTE Set Value            */
#define I2C_IC_DATA_CMD_FIRST_DATA_BYTE_Get(x)                \
    (((uint32_t) (x) &I2C_IC_DATA_CMD_FIRST_DATA_BYTE_Msk) >> \
     I2C_IC_DATA_CMD_FIRST_DATA_BYTE_Pos) /*!< FIRST_DATA_BYTE Get Value            */


#define I2C_IC_DATA_CMD_RESTART_Pos (10U)                                 /*!< RESTART Postion   10         */
#define I2C_IC_DATA_CMD_RESTART_Msk (0x1U << I2C_IC_DATA_CMD_RESTART_Pos) /*!< RESTART Mask      0x00000400 */
#define I2C_IC_DATA_CMD_RESTART_Set(x) \
    (((uint32_t) (x) << I2C_IC_DATA_CMD_RESTART_Pos) & I2C_IC_DATA_CMD_RESTART_Msk) /*!< RESTART Set Value */
#define I2C_IC_DATA_CMD_RESTART_Get(x) \
    (((uint32_t) (x) &I2C_IC_DATA_CMD_RESTART_Msk) >> I2C_IC_DATA_CMD_RESTART_Pos) /*!< RESTART Get Value */


#define I2C_IC_DATA_CMD_STOP_Pos (9U)                               /*!< STOP Postion   9          */
#define I2C_IC_DATA_CMD_STOP_Msk (0x1U << I2C_IC_DATA_CMD_STOP_Pos) /*!< STOP Mask      0x00000200 */
#define I2C_IC_DATA_CMD_STOP_Set(x) \
    (((uint32_t) (x) << I2C_IC_DATA_CMD_STOP_Pos) & I2C_IC_DATA_CMD_STOP_Msk) /*!< STOP Set Value            */
#define I2C_IC_DATA_CMD_STOP_Get(x) \
    (((uint32_t) (x) &I2C_IC_DATA_CMD_STOP_Msk) >> I2C_IC_DATA_CMD_STOP_Pos) /*!< STOP Get Value            */


#define I2C_IC_DATA_CMD_CMD_Pos (8U)                              /*!< CMD Postion   8          */
#define I2C_IC_DATA_CMD_CMD_Msk (0x1U << I2C_IC_DATA_CMD_CMD_Pos) /*!< CMD Mask      0x00000100 */
#define I2C_IC_DATA_CMD_CMD_Set(x) \
    (((uint32_t) (x) << I2C_IC_DATA_CMD_CMD_Pos) & I2C_IC_DATA_CMD_CMD_Msk) /*!< CMD Set Value            */
#define I2C_IC_DATA_CMD_CMD_Get(x) \
    (((uint32_t) (x) &I2C_IC_DATA_CMD_CMD_Msk) >> I2C_IC_DATA_CMD_CMD_Pos) /*!< CMD Get Value            */


#define I2C_IC_DATA_CMD_DAT_Pos (0U)                               /*!< DAT Postion   0          */
#define I2C_IC_DATA_CMD_DAT_Msk (0xffU << I2C_IC_DATA_CMD_DAT_Pos) /*!< DAT Mask      0x000000FF */
#define I2C_IC_DATA_CMD_DAT_Set(x) \
    (((uint32_t) (x) << I2C_IC_DATA_CMD_DAT_Pos) & I2C_IC_DATA_CMD_DAT_Msk) /*!< DAT Set Value            */
#define I2C_IC_DATA_CMD_DAT_Get(x) \
    (((uint32_t) (x) &I2C_IC_DATA_CMD_DAT_Msk) >> I2C_IC_DATA_CMD_DAT_Pos) /*!< DAT Get Value            */


/* IC_SS_SCL_HCNT bitfield */
#define I2C_IC_SS_SCL_HCNT_IC_SS_SCL_HCNT_Pos (0U) /*!< IC_SS_SCL_HCNT Postion   0          */
#define I2C_IC_SS_SCL_HCNT_IC_SS_SCL_HCNT_Msk \
    (0xffffU << I2C_IC_SS_SCL_HCNT_IC_SS_SCL_HCNT_Pos) /*!< IC_SS_SCL_HCNT Mask      0x0000FFFF */
#define I2C_IC_SS_SCL_HCNT_IC_SS_SCL_HCNT_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SS_SCL_HCNT_IC_SS_SCL_HCNT_Pos) & \
     I2C_IC_SS_SCL_HCNT_IC_SS_SCL_HCNT_Msk) /*!< IC_SS_SCL_HCNT Set Value            */
#define I2C_IC_SS_SCL_HCNT_IC_SS_SCL_HCNT_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SS_SCL_HCNT_IC_SS_SCL_HCNT_Msk) >> \
     I2C_IC_SS_SCL_HCNT_IC_SS_SCL_HCNT_Pos) /*!< IC_SS_SCL_HCNT Get Value            */


/* IC_UFM_SCL_HCNT bitfield */
#define I2C_IC_UFM_SCL_HCNT_IC_UFM_SCL_HCNT_Pos (0U) /*!< IC_UFM_SCL_HCNT Postion   0          */
#define I2C_IC_UFM_SCL_HCNT_IC_UFM_SCL_HCNT_Msk \
    (0xffffU << I2C_IC_UFM_SCL_HCNT_IC_UFM_SCL_HCNT_Pos) /*!< IC_UFM_SCL_HCNT Mask      0x0000FFFF */
#define I2C_IC_UFM_SCL_HCNT_IC_UFM_SCL_HCNT_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_UFM_SCL_HCNT_IC_UFM_SCL_HCNT_Pos) & \
     I2C_IC_UFM_SCL_HCNT_IC_UFM_SCL_HCNT_Msk) /*!< IC_UFM_SCL_HCNT Set Value            */
#define I2C_IC_UFM_SCL_HCNT_IC_UFM_SCL_HCNT_Get(x)                \
    (((uint32_t) (x) &I2C_IC_UFM_SCL_HCNT_IC_UFM_SCL_HCNT_Msk) >> \
     I2C_IC_UFM_SCL_HCNT_IC_UFM_SCL_HCNT_Pos) /*!< IC_UFM_SCL_HCNT Get Value            */


/* IC_SS_SCL_LCNT bitfield */
#define I2C_IC_SS_SCL_LCNT_IC_SS_SCL_LCNT_Pos (0U) /*!< IC_SS_SCL_LCNT Postion   0          */
#define I2C_IC_SS_SCL_LCNT_IC_SS_SCL_LCNT_Msk \
    (0xffffU << I2C_IC_SS_SCL_LCNT_IC_SS_SCL_LCNT_Pos) /*!< IC_SS_SCL_LCNT Mask      0x0000FFFF */
#define I2C_IC_SS_SCL_LCNT_IC_SS_SCL_LCNT_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SS_SCL_LCNT_IC_SS_SCL_LCNT_Pos) & \
     I2C_IC_SS_SCL_LCNT_IC_SS_SCL_LCNT_Msk) /*!< IC_SS_SCL_LCNT Set Value            */
#define I2C_IC_SS_SCL_LCNT_IC_SS_SCL_LCNT_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SS_SCL_LCNT_IC_SS_SCL_LCNT_Msk) >> \
     I2C_IC_SS_SCL_LCNT_IC_SS_SCL_LCNT_Pos) /*!< IC_SS_SCL_LCNT Get Value            */


/* IC_UFM_SCL_LCNT bitfield */
#define I2C_IC_UFM_SCL_LCNT_IC_UFM_SCL_LCNT_Pos (0U) /*!< IC_UFM_SCL_LCNT Postion   0          */
#define I2C_IC_UFM_SCL_LCNT_IC_UFM_SCL_LCNT_Msk \
    (0xffffU << I2C_IC_UFM_SCL_LCNT_IC_UFM_SCL_LCNT_Pos) /*!< IC_UFM_SCL_LCNT Mask      0x0000FFFF */
#define I2C_IC_UFM_SCL_LCNT_IC_UFM_SCL_LCNT_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_UFM_SCL_LCNT_IC_UFM_SCL_LCNT_Pos) & \
     I2C_IC_UFM_SCL_LCNT_IC_UFM_SCL_LCNT_Msk) /*!< IC_UFM_SCL_LCNT Set Value            */
#define I2C_IC_UFM_SCL_LCNT_IC_UFM_SCL_LCNT_Get(x)                \
    (((uint32_t) (x) &I2C_IC_UFM_SCL_LCNT_IC_UFM_SCL_LCNT_Msk) >> \
     I2C_IC_UFM_SCL_LCNT_IC_UFM_SCL_LCNT_Pos) /*!< IC_UFM_SCL_LCNT Get Value            */


/* IC_FS_SCL_HCNT bitfield */
#define I2C_IC_FS_SCL_HCNT_IC_FS_SCL_HCNT_Pos (0U) /*!< IC_FS_SCL_HCNT Postion   0          */
#define I2C_IC_FS_SCL_HCNT_IC_FS_SCL_HCNT_Msk \
    (0xffffU << I2C_IC_FS_SCL_HCNT_IC_FS_SCL_HCNT_Pos) /*!< IC_FS_SCL_HCNT Mask      0x0000FFFF */
#define I2C_IC_FS_SCL_HCNT_IC_FS_SCL_HCNT_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_FS_SCL_HCNT_IC_FS_SCL_HCNT_Pos) & \
     I2C_IC_FS_SCL_HCNT_IC_FS_SCL_HCNT_Msk) /*!< IC_FS_SCL_HCNT Set Value            */
#define I2C_IC_FS_SCL_HCNT_IC_FS_SCL_HCNT_Get(x)                \
    (((uint32_t) (x) &I2C_IC_FS_SCL_HCNT_IC_FS_SCL_HCNT_Msk) >> \
     I2C_IC_FS_SCL_HCNT_IC_FS_SCL_HCNT_Pos) /*!< IC_FS_SCL_HCNT Get Value            */


/* IC_UFM_TBUF_CNT bitfield */
#define I2C_IC_UFM_TBUF_CNT_IC_UFM_TBUF_CNT_Pos (0U) /*!< IC_UFM_TBUF_CNT Postion   0          */
#define I2C_IC_UFM_TBUF_CNT_IC_UFM_TBUF_CNT_Msk \
    (0xffffU << I2C_IC_UFM_TBUF_CNT_IC_UFM_TBUF_CNT_Pos) /*!< IC_UFM_TBUF_CNT Mask      0x0000FFFF */
#define I2C_IC_UFM_TBUF_CNT_IC_UFM_TBUF_CNT_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_UFM_TBUF_CNT_IC_UFM_TBUF_CNT_Pos) & \
     I2C_IC_UFM_TBUF_CNT_IC_UFM_TBUF_CNT_Msk) /*!< IC_UFM_TBUF_CNT Set Value            */
#define I2C_IC_UFM_TBUF_CNT_IC_UFM_TBUF_CNT_Get(x)                \
    (((uint32_t) (x) &I2C_IC_UFM_TBUF_CNT_IC_UFM_TBUF_CNT_Msk) >> \
     I2C_IC_UFM_TBUF_CNT_IC_UFM_TBUF_CNT_Pos) /*!< IC_UFM_TBUF_CNT Get Value            */


/* IC_FS_SCL_LCNT bitfield */
#define I2C_IC_FS_SCL_LCNT_IC_FS_SCL_LCNT_Pos (0U) /*!< IC_FS_SCL_LCNT Postion   0          */
#define I2C_IC_FS_SCL_LCNT_IC_FS_SCL_LCNT_Msk \
    (0xffffU << I2C_IC_FS_SCL_LCNT_IC_FS_SCL_LCNT_Pos) /*!< IC_FS_SCL_LCNT Mask      0x0000FFFF */
#define I2C_IC_FS_SCL_LCNT_IC_FS_SCL_LCNT_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_FS_SCL_LCNT_IC_FS_SCL_LCNT_Pos) & \
     I2C_IC_FS_SCL_LCNT_IC_FS_SCL_LCNT_Msk) /*!< IC_FS_SCL_LCNT Set Value            */
#define I2C_IC_FS_SCL_LCNT_IC_FS_SCL_LCNT_Get(x)                \
    (((uint32_t) (x) &I2C_IC_FS_SCL_LCNT_IC_FS_SCL_LCNT_Msk) >> \
     I2C_IC_FS_SCL_LCNT_IC_FS_SCL_LCNT_Pos) /*!< IC_FS_SCL_LCNT Get Value            */


/* IC_HS_SCL_HCNT bitfield */
#define I2C_IC_HS_SCL_HCNT_IC_HS_SCL_HCNT_Pos (0U) /*!< IC_HS_SCL_HCNT Postion   0          */
#define I2C_IC_HS_SCL_HCNT_IC_HS_SCL_HCNT_Msk \
    (0xffffU << I2C_IC_HS_SCL_HCNT_IC_HS_SCL_HCNT_Pos) /*!< IC_HS_SCL_HCNT Mask      0x0000FFFF */
#define I2C_IC_HS_SCL_HCNT_IC_HS_SCL_HCNT_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_HS_SCL_HCNT_IC_HS_SCL_HCNT_Pos) & \
     I2C_IC_HS_SCL_HCNT_IC_HS_SCL_HCNT_Msk) /*!< IC_HS_SCL_HCNT Set Value            */
#define I2C_IC_HS_SCL_HCNT_IC_HS_SCL_HCNT_Get(x)                \
    (((uint32_t) (x) &I2C_IC_HS_SCL_HCNT_IC_HS_SCL_HCNT_Msk) >> \
     I2C_IC_HS_SCL_HCNT_IC_HS_SCL_HCNT_Pos) /*!< IC_HS_SCL_HCNT Get Value            */


/* IC_HS_SCL_LCNT bitfield */
#define I2C_IC_HS_SCL_LCNT_IC_HS_SCL_LCNT_Pos (0U) /*!< IC_HS_SCL_LCNT Postion   0          */
#define I2C_IC_HS_SCL_LCNT_IC_HS_SCL_LCNT_Msk \
    (0xffffU << I2C_IC_HS_SCL_LCNT_IC_HS_SCL_LCNT_Pos) /*!< IC_HS_SCL_LCNT Mask      0x0000FFFF */
#define I2C_IC_HS_SCL_LCNT_IC_HS_SCL_LCNT_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_HS_SCL_LCNT_IC_HS_SCL_LCNT_Pos) & \
     I2C_IC_HS_SCL_LCNT_IC_HS_SCL_LCNT_Msk) /*!< IC_HS_SCL_LCNT Set Value            */
#define I2C_IC_HS_SCL_LCNT_IC_HS_SCL_LCNT_Get(x)                \
    (((uint32_t) (x) &I2C_IC_HS_SCL_LCNT_IC_HS_SCL_LCNT_Msk) >> \
     I2C_IC_HS_SCL_LCNT_IC_HS_SCL_LCNT_Pos) /*!< IC_HS_SCL_LCNT Get Value            */


/* IC_INTR_STAT bitfield */
#define I2C_IC_INTR_STAT_R_SCL_STUCK_AT_LOW_Pos (14U) /*!< R_SCL_STUCK_AT_LOW Postion   14         */
#define I2C_IC_INTR_STAT_R_SCL_STUCK_AT_LOW_Msk \
    (0x1U << I2C_IC_INTR_STAT_R_SCL_STUCK_AT_LOW_Pos) /*!< R_SCL_STUCK_AT_LOW Mask      0x00004000 */
#define I2C_IC_INTR_STAT_R_SCL_STUCK_AT_LOW_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_INTR_STAT_R_SCL_STUCK_AT_LOW_Pos) & \
     I2C_IC_INTR_STAT_R_SCL_STUCK_AT_LOW_Msk) /*!< R_SCL_STUCK_AT_LOW Set Value            */
#define I2C_IC_INTR_STAT_R_SCL_STUCK_AT_LOW_Get(x)                \
    (((uint32_t) (x) &I2C_IC_INTR_STAT_R_SCL_STUCK_AT_LOW_Msk) >> \
     I2C_IC_INTR_STAT_R_SCL_STUCK_AT_LOW_Pos) /*!< R_SCL_STUCK_AT_LOW Get Value            */


#define I2C_IC_INTR_STAT_R_MASTER_ON_HOLD_Pos (13U) /*!< R_MASTER_ON_HOLD Postion   13         */
#define I2C_IC_INTR_STAT_R_MASTER_ON_HOLD_Msk \
    (0x1U << I2C_IC_INTR_STAT_R_MASTER_ON_HOLD_Pos) /*!< R_MASTER_ON_HOLD Mask      0x00002000 */
#define I2C_IC_INTR_STAT_R_MASTER_ON_HOLD_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_INTR_STAT_R_MASTER_ON_HOLD_Pos) & \
     I2C_IC_INTR_STAT_R_MASTER_ON_HOLD_Msk) /*!< R_MASTER_ON_HOLD Set Value            */
#define I2C_IC_INTR_STAT_R_MASTER_ON_HOLD_Get(x)                \
    (((uint32_t) (x) &I2C_IC_INTR_STAT_R_MASTER_ON_HOLD_Msk) >> \
     I2C_IC_INTR_STAT_R_MASTER_ON_HOLD_Pos) /*!< R_MASTER_ON_HOLD Get Value            */


#define I2C_IC_INTR_STAT_R_RESTART_DET_Pos (12U) /*!< R_RESTART_DET Postion   12         */
#define I2C_IC_INTR_STAT_R_RESTART_DET_Msk \
    (0x1U << I2C_IC_INTR_STAT_R_RESTART_DET_Pos) /*!< R_RESTART_DET Mask      0x00001000 */
#define I2C_IC_INTR_STAT_R_RESTART_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_INTR_STAT_R_RESTART_DET_Pos) & \
     I2C_IC_INTR_STAT_R_RESTART_DET_Msk) /*!< R_RESTART_DET Set Value            */
#define I2C_IC_INTR_STAT_R_RESTART_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_INTR_STAT_R_RESTART_DET_Msk) >> \
     I2C_IC_INTR_STAT_R_RESTART_DET_Pos) /*!< R_RESTART_DET Get Value            */


#define I2C_IC_INTR_STAT_R_GEN_CALL_Pos (11U) /*!< R_GEN_CALL Postion   11         */
#define I2C_IC_INTR_STAT_R_GEN_CALL_Msk \
    (0x1U << I2C_IC_INTR_STAT_R_GEN_CALL_Pos) /*!< R_GEN_CALL Mask      0x00000800 */
#define I2C_IC_INTR_STAT_R_GEN_CALL_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_INTR_STAT_R_GEN_CALL_Pos) & \
     I2C_IC_INTR_STAT_R_GEN_CALL_Msk) /*!< R_GEN_CALL Set Value            */
#define I2C_IC_INTR_STAT_R_GEN_CALL_Get(x)                \
    (((uint32_t) (x) &I2C_IC_INTR_STAT_R_GEN_CALL_Msk) >> \
     I2C_IC_INTR_STAT_R_GEN_CALL_Pos) /*!< R_GEN_CALL Get Value            */


#define I2C_IC_INTR_STAT_R_START_DET_Pos (10U) /*!< R_START_DET Postion   10         */
#define I2C_IC_INTR_STAT_R_START_DET_Msk \
    (0x1U << I2C_IC_INTR_STAT_R_START_DET_Pos) /*!< R_START_DET Mask      0x00000400 */
#define I2C_IC_INTR_STAT_R_START_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_INTR_STAT_R_START_DET_Pos) & \
     I2C_IC_INTR_STAT_R_START_DET_Msk) /*!< R_START_DET Set Value            */
#define I2C_IC_INTR_STAT_R_START_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_INTR_STAT_R_START_DET_Msk) >> \
     I2C_IC_INTR_STAT_R_START_DET_Pos) /*!< R_START_DET Get Value            */


#define I2C_IC_INTR_STAT_R_STOP_DET_Pos (9U) /*!< R_STOP_DET Postion   9          */
#define I2C_IC_INTR_STAT_R_STOP_DET_Msk \
    (0x1U << I2C_IC_INTR_STAT_R_STOP_DET_Pos) /*!< R_STOP_DET Mask      0x00000200 */
#define I2C_IC_INTR_STAT_R_STOP_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_INTR_STAT_R_STOP_DET_Pos) & \
     I2C_IC_INTR_STAT_R_STOP_DET_Msk) /*!< R_STOP_DET Set Value            */
#define I2C_IC_INTR_STAT_R_STOP_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_INTR_STAT_R_STOP_DET_Msk) >> \
     I2C_IC_INTR_STAT_R_STOP_DET_Pos) /*!< R_STOP_DET Get Value            */


#define I2C_IC_INTR_STAT_R_ACTIVITY_Pos (8U) /*!< R_ACTIVITY Postion   8          */
#define I2C_IC_INTR_STAT_R_ACTIVITY_Msk \
    (0x1U << I2C_IC_INTR_STAT_R_ACTIVITY_Pos) /*!< R_ACTIVITY Mask      0x00000100 */
#define I2C_IC_INTR_STAT_R_ACTIVITY_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_INTR_STAT_R_ACTIVITY_Pos) & \
     I2C_IC_INTR_STAT_R_ACTIVITY_Msk) /*!< R_ACTIVITY Set Value            */
#define I2C_IC_INTR_STAT_R_ACTIVITY_Get(x)                \
    (((uint32_t) (x) &I2C_IC_INTR_STAT_R_ACTIVITY_Msk) >> \
     I2C_IC_INTR_STAT_R_ACTIVITY_Pos) /*!< R_ACTIVITY Get Value            */


#define I2C_IC_INTR_STAT_R_RX_DONE_Pos (7U)                                     /*!< R_RX_DONE Postion   7          */
#define I2C_IC_INTR_STAT_R_RX_DONE_Msk (0x1U << I2C_IC_INTR_STAT_R_RX_DONE_Pos) /*!< R_RX_DONE Mask      0x00000080 */
#define I2C_IC_INTR_STAT_R_RX_DONE_Set(x) \
    (((uint32_t) (x) << I2C_IC_INTR_STAT_R_RX_DONE_Pos) & I2C_IC_INTR_STAT_R_RX_DONE_Msk) /*!< R_RX_DONE Set Value */
#define I2C_IC_INTR_STAT_R_RX_DONE_Get(x) \
    (((uint32_t) (x) &I2C_IC_INTR_STAT_R_RX_DONE_Msk) >> I2C_IC_INTR_STAT_R_RX_DONE_Pos) /*!< R_RX_DONE Get Value */


#define I2C_IC_INTR_STAT_R_TX_ABRT_Pos (6U)                                     /*!< R_TX_ABRT Postion   6          */
#define I2C_IC_INTR_STAT_R_TX_ABRT_Msk (0x1U << I2C_IC_INTR_STAT_R_TX_ABRT_Pos) /*!< R_TX_ABRT Mask      0x00000040 */
#define I2C_IC_INTR_STAT_R_TX_ABRT_Set(x) \
    (((uint32_t) (x) << I2C_IC_INTR_STAT_R_TX_ABRT_Pos) & I2C_IC_INTR_STAT_R_TX_ABRT_Msk) /*!< R_TX_ABRT Set Value */
#define I2C_IC_INTR_STAT_R_TX_ABRT_Get(x) \
    (((uint32_t) (x) &I2C_IC_INTR_STAT_R_TX_ABRT_Msk) >> I2C_IC_INTR_STAT_R_TX_ABRT_Pos) /*!< R_TX_ABRT Get Value */


#define I2C_IC_INTR_STAT_R_RD_REQ_Pos (5U)                                    /*!< R_RD_REQ Postion   5          */
#define I2C_IC_INTR_STAT_R_RD_REQ_Msk (0x1U << I2C_IC_INTR_STAT_R_RD_REQ_Pos) /*!< R_RD_REQ Mask      0x00000020 */
#define I2C_IC_INTR_STAT_R_RD_REQ_Set(x) \
    (((uint32_t) (x) << I2C_IC_INTR_STAT_R_RD_REQ_Pos) & I2C_IC_INTR_STAT_R_RD_REQ_Msk) /*!< R_RD_REQ Set Value */
#define I2C_IC_INTR_STAT_R_RD_REQ_Get(x) \
    (((uint32_t) (x) &I2C_IC_INTR_STAT_R_RD_REQ_Msk) >> I2C_IC_INTR_STAT_R_RD_REQ_Pos) /*!< R_RD_REQ Get Value */


#define I2C_IC_INTR_STAT_R_TX_EMPTY_Pos (4U) /*!< R_TX_EMPTY Postion   4          */
#define I2C_IC_INTR_STAT_R_TX_EMPTY_Msk \
    (0x1U << I2C_IC_INTR_STAT_R_TX_EMPTY_Pos) /*!< R_TX_EMPTY Mask      0x00000010 */
#define I2C_IC_INTR_STAT_R_TX_EMPTY_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_INTR_STAT_R_TX_EMPTY_Pos) & \
     I2C_IC_INTR_STAT_R_TX_EMPTY_Msk) /*!< R_TX_EMPTY Set Value            */
#define I2C_IC_INTR_STAT_R_TX_EMPTY_Get(x)                \
    (((uint32_t) (x) &I2C_IC_INTR_STAT_R_TX_EMPTY_Msk) >> \
     I2C_IC_INTR_STAT_R_TX_EMPTY_Pos) /*!< R_TX_EMPTY Get Value            */


#define I2C_IC_INTR_STAT_R_TX_OVER_Pos (3U)                                     /*!< R_TX_0VER Postion   3          */
#define I2C_IC_INTR_STAT_R_TX_OVER_Msk (0x1U << I2C_IC_INTR_STAT_R_TX_OVER_Pos) /*!< R_TX_0VER Mask      0x00000008 */
#define I2C_IC_INTR_STAT_R_TX_OVER_Set(x) \
    (((uint32_t) (x) << I2C_IC_INTR_STAT_R_TX_OVER_Pos) & I2C_IC_INTR_STAT_R_TX_OVER_Msk) /*!< R_TX_0VER Set Value */
#define I2C_IC_INTR_STAT_R_TX_OVER_Get(x) \
    (((uint32_t) (x) &I2C_IC_INTR_STAT_R_TX_OVER_Msk) >> I2C_IC_INTR_STAT_R_TX_OVER_Pos) /*!< R_TX_0VER Get Value */


#define I2C_IC_INTR_STAT_R_RX_FULL_Pos (2U)                                     /*!< R_RX_FULL Postion   2          */
#define I2C_IC_INTR_STAT_R_RX_FULL_Msk (0x1U << I2C_IC_INTR_STAT_R_RX_FULL_Pos) /*!< R_RX_FULL Mask      0x00000004 */
#define I2C_IC_INTR_STAT_R_RX_FULL_Set(x) \
    (((uint32_t) (x) << I2C_IC_INTR_STAT_R_RX_FULL_Pos) & I2C_IC_INTR_STAT_R_RX_FULL_Msk) /*!< R_RX_FULL Set Value */
#define I2C_IC_INTR_STAT_R_RX_FULL_Get(x) \
    (((uint32_t) (x) &I2C_IC_INTR_STAT_R_RX_FULL_Msk) >> I2C_IC_INTR_STAT_R_RX_FULL_Pos) /*!< R_RX_FULL Get Value */


#define I2C_IC_INTR_STAT_R_RX_OVER_Pos (1U)                                     /*!< R_RX_OVER Postion   1          */
#define I2C_IC_INTR_STAT_R_RX_OVER_Msk (0x1U << I2C_IC_INTR_STAT_R_RX_OVER_Pos) /*!< R_RX_OVER Mask      0x00000002 */
#define I2C_IC_INTR_STAT_R_RX_OVER_Set(x) \
    (((uint32_t) (x) << I2C_IC_INTR_STAT_R_RX_OVER_Pos) & I2C_IC_INTR_STAT_R_RX_OVER_Msk) /*!< R_RX_OVER Set Value */
#define I2C_IC_INTR_STAT_R_RX_OVER_Get(x) \
    (((uint32_t) (x) &I2C_IC_INTR_STAT_R_RX_OVER_Msk) >> I2C_IC_INTR_STAT_R_RX_OVER_Pos) /*!< R_RX_OVER Get Value */


#define I2C_IC_INTR_STAT_R_RX_UNDER_Pos (0U) /*!< R_RX_UNDER Postion   0          */
#define I2C_IC_INTR_STAT_R_RX_UNDER_Msk \
    (0x1U << I2C_IC_INTR_STAT_R_RX_UNDER_Pos) /*!< R_RX_UNDER Mask      0x00000001 */
#define I2C_IC_INTR_STAT_R_RX_UNDER_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_INTR_STAT_R_RX_UNDER_Pos) & \
     I2C_IC_INTR_STAT_R_RX_UNDER_Msk) /*!< R_RX_UNDER Set Value            */
#define I2C_IC_INTR_STAT_R_RX_UNDER_Get(x)                \
    (((uint32_t) (x) &I2C_IC_INTR_STAT_R_RX_UNDER_Msk) >> \
     I2C_IC_INTR_STAT_R_RX_UNDER_Pos) /*!< R_RX_UNDER Get Value            */


/* IC_INTR_MASK bitfield */
#define I2C_IC_INTR_MASK_M_SCL_STUCK_AT_LOW_Pos (14U) /*!< M_SCL_STUCK_AT_LOW Postion   14         */
#define I2C_IC_INTR_MASK_M_SCL_STUCK_AT_LOW_Msk \
    (0x1U << I2C_IC_INTR_MASK_M_SCL_STUCK_AT_LOW_Pos) /*!< M_SCL_STUCK_AT_LOW Mask      0x00004000 */
#define I2C_IC_INTR_MASK_M_SCL_STUCK_AT_LOW_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_INTR_MASK_M_SCL_STUCK_AT_LOW_Pos) & \
     I2C_IC_INTR_MASK_M_SCL_STUCK_AT_LOW_Msk) /*!< M_SCL_STUCK_AT_LOW Set Value            */
#define I2C_IC_INTR_MASK_M_SCL_STUCK_AT_LOW_Get(x)                \
    (((uint32_t) (x) &I2C_IC_INTR_MASK_M_SCL_STUCK_AT_LOW_Msk) >> \
     I2C_IC_INTR_MASK_M_SCL_STUCK_AT_LOW_Pos) /*!< M_SCL_STUCK_AT_LOW Get Value            */


#define I2C_IC_INTR_MASK_M_MASTER_ON_HOLD_Pos (13U) /*!< M_MASTER_ON_HOLD Postion   13         */
#define I2C_IC_INTR_MASK_M_MASTER_ON_HOLD_Msk \
    (0x1U << I2C_IC_INTR_MASK_M_MASTER_ON_HOLD_Pos) /*!< M_MASTER_ON_HOLD Mask      0x00002000 */
#define I2C_IC_INTR_MASK_M_MASTER_ON_HOLD_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_INTR_MASK_M_MASTER_ON_HOLD_Pos) & \
     I2C_IC_INTR_MASK_M_MASTER_ON_HOLD_Msk) /*!< M_MASTER_ON_HOLD Set Value            */
#define I2C_IC_INTR_MASK_M_MASTER_ON_HOLD_Get(x)                \
    (((uint32_t) (x) &I2C_IC_INTR_MASK_M_MASTER_ON_HOLD_Msk) >> \
     I2C_IC_INTR_MASK_M_MASTER_ON_HOLD_Pos) /*!< M_MASTER_ON_HOLD Get Value            */


#define I2C_IC_INTR_MASK_M_RESTART_DET_Pos (12U) /*!< M_RESTART_DET Postion   12         */
#define I2C_IC_INTR_MASK_M_RESTART_DET_Msk \
    (0x1U << I2C_IC_INTR_MASK_M_RESTART_DET_Pos) /*!< M_RESTART_DET Mask      0x00001000 */
#define I2C_IC_INTR_MASK_M_RESTART_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_INTR_MASK_M_RESTART_DET_Pos) & \
     I2C_IC_INTR_MASK_M_RESTART_DET_Msk) /*!< M_RESTART_DET Set Value            */
#define I2C_IC_INTR_MASK_M_RESTART_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_INTR_MASK_M_RESTART_DET_Msk) >> \
     I2C_IC_INTR_MASK_M_RESTART_DET_Pos) /*!< M_RESTART_DET Get Value            */


#define I2C_IC_INTR_MASK_M_GEN_CALL_Pos (11U) /*!< M_GEN_CALL Postion   11         */
#define I2C_IC_INTR_MASK_M_GEN_CALL_Msk \
    (0x1U << I2C_IC_INTR_MASK_M_GEN_CALL_Pos) /*!< M_GEN_CALL Mask      0x00000800 */
#define I2C_IC_INTR_MASK_M_GEN_CALL_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_INTR_MASK_M_GEN_CALL_Pos) & \
     I2C_IC_INTR_MASK_M_GEN_CALL_Msk) /*!< M_GEN_CALL Set Value            */
#define I2C_IC_INTR_MASK_M_GEN_CALL_Get(x)                \
    (((uint32_t) (x) &I2C_IC_INTR_MASK_M_GEN_CALL_Msk) >> \
     I2C_IC_INTR_MASK_M_GEN_CALL_Pos) /*!< M_GEN_CALL Get Value            */


#define I2C_IC_INTR_MASK_M_START_DET_Pos (10U) /*!< M_START_DET Postion   10         */
#define I2C_IC_INTR_MASK_M_START_DET_Msk \
    (0x1U << I2C_IC_INTR_MASK_M_START_DET_Pos) /*!< M_START_DET Mask      0x00000400 */
#define I2C_IC_INTR_MASK_M_START_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_INTR_MASK_M_START_DET_Pos) & \
     I2C_IC_INTR_MASK_M_START_DET_Msk) /*!< M_START_DET Set Value            */
#define I2C_IC_INTR_MASK_M_START_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_INTR_MASK_M_START_DET_Msk) >> \
     I2C_IC_INTR_MASK_M_START_DET_Pos) /*!< M_START_DET Get Value            */


#define I2C_IC_INTR_MASK_M_STOP_DET_Pos (9U) /*!< M_STOP_DET Postion   9          */
#define I2C_IC_INTR_MASK_M_STOP_DET_Msk \
    (0x1U << I2C_IC_INTR_MASK_M_STOP_DET_Pos) /*!< M_STOP_DET Mask      0x00000200 */
#define I2C_IC_INTR_MASK_M_STOP_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_INTR_MASK_M_STOP_DET_Pos) & \
     I2C_IC_INTR_MASK_M_STOP_DET_Msk) /*!< M_STOP_DET Set Value            */
#define I2C_IC_INTR_MASK_M_STOP_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_INTR_MASK_M_STOP_DET_Msk) >> \
     I2C_IC_INTR_MASK_M_STOP_DET_Pos) /*!< M_STOP_DET Get Value            */


#define I2C_IC_INTR_MASK_M_ACTIVITY_Pos (8U) /*!< M_ACTIVITY Postion   8          */
#define I2C_IC_INTR_MASK_M_ACTIVITY_Msk \
    (0x1U << I2C_IC_INTR_MASK_M_ACTIVITY_Pos) /*!< M_ACTIVITY Mask      0x00000100 */
#define I2C_IC_INTR_MASK_M_ACTIVITY_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_INTR_MASK_M_ACTIVITY_Pos) & \
     I2C_IC_INTR_MASK_M_ACTIVITY_Msk) /*!< M_ACTIVITY Set Value            */
#define I2C_IC_INTR_MASK_M_ACTIVITY_Get(x)                \
    (((uint32_t) (x) &I2C_IC_INTR_MASK_M_ACTIVITY_Msk) >> \
     I2C_IC_INTR_MASK_M_ACTIVITY_Pos) /*!< M_ACTIVITY Get Value            */


#define I2C_IC_INTR_MASK_M_RX_DONE_Pos (7U)                                     /*!< M_RX_D0NE Postion   7          */
#define I2C_IC_INTR_MASK_M_RX_DONE_Msk (0x1U << I2C_IC_INTR_MASK_M_RX_DONE_Pos) /*!< M_RX_D0NE Mask      0x00000080 */
#define I2C_IC_INTR_MASK_M_RX_DONE_Set(x) \
    (((uint32_t) (x) << I2C_IC_INTR_MASK_M_RX_DONE_Pos) & I2C_IC_INTR_MASK_M_RX_DONE_Msk) /*!< M_RX_D0NE Set Value */
#define I2C_IC_INTR_MASK_M_RX_DONE_Get(x) \
    (((uint32_t) (x) &I2C_IC_INTR_MASK_M_RX_DONE_Msk) >> I2C_IC_INTR_MASK_M_RX_DONE_Pos) /*!< M_RX_D0NE Get Value */


#define I2C_IC_INTR_MASK_M_TX_ABRT_Pos (6U)                                     /*!< M_TX_ABRT Postion   6          */
#define I2C_IC_INTR_MASK_M_TX_ABRT_Msk (0x1U << I2C_IC_INTR_MASK_M_TX_ABRT_Pos) /*!< M_TX_ABRT Mask      0x00000040 */
#define I2C_IC_INTR_MASK_M_TX_ABRT_Set(x) \
    (((uint32_t) (x) << I2C_IC_INTR_MASK_M_TX_ABRT_Pos) & I2C_IC_INTR_MASK_M_TX_ABRT_Msk) /*!< M_TX_ABRT Set Value */
#define I2C_IC_INTR_MASK_M_TX_ABRT_Get(x) \
    (((uint32_t) (x) &I2C_IC_INTR_MASK_M_TX_ABRT_Msk) >> I2C_IC_INTR_MASK_M_TX_ABRT_Pos) /*!< M_TX_ABRT Get Value */


#define I2C_IC_INTR_MASK_M_RD_REQ_Pos (5U)                                    /*!< M_RD_REQ Postion   5          */
#define I2C_IC_INTR_MASK_M_RD_REQ_Msk (0x1U << I2C_IC_INTR_MASK_M_RD_REQ_Pos) /*!< M_RD_REQ Mask      0x00000020 */
#define I2C_IC_INTR_MASK_M_RD_REQ_Set(x) \
    (((uint32_t) (x) << I2C_IC_INTR_MASK_M_RD_REQ_Pos) & I2C_IC_INTR_MASK_M_RD_REQ_Msk) /*!< M_RD_REQ Set Value */
#define I2C_IC_INTR_MASK_M_RD_REQ_Get(x) \
    (((uint32_t) (x) &I2C_IC_INTR_MASK_M_RD_REQ_Msk) >> I2C_IC_INTR_MASK_M_RD_REQ_Pos) /*!< M_RD_REQ Get Value */


#define I2C_IC_INTR_MASK_M_TX_EMPTY_Pos (4U) /*!< M_TX_EMPTY Postion   4          */
#define I2C_IC_INTR_MASK_M_TX_EMPTY_Msk \
    (0x1U << I2C_IC_INTR_MASK_M_TX_EMPTY_Pos) /*!< M_TX_EMPTY Mask      0x00000010 */
#define I2C_IC_INTR_MASK_M_TX_EMPTY_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_INTR_MASK_M_TX_EMPTY_Pos) & \
     I2C_IC_INTR_MASK_M_TX_EMPTY_Msk) /*!< M_TX_EMPTY Set Value            */
#define I2C_IC_INTR_MASK_M_TX_EMPTY_Get(x)                \
    (((uint32_t) (x) &I2C_IC_INTR_MASK_M_TX_EMPTY_Msk) >> \
     I2C_IC_INTR_MASK_M_TX_EMPTY_Pos) /*!< M_TX_EMPTY Get Value            */


#define I2C_IC_INTR_MASK_M_TX_OVER_Pos (3U)                                     /*!< M_TX_OVER Postion   3          */
#define I2C_IC_INTR_MASK_M_TX_OVER_Msk (0x1U << I2C_IC_INTR_MASK_M_TX_OVER_Pos) /*!< M_TX_OVER Mask      0x00000008 */
#define I2C_IC_INTR_MASK_M_TX_OVER_Set(x) \
    (((uint32_t) (x) << I2C_IC_INTR_MASK_M_TX_OVER_Pos) & I2C_IC_INTR_MASK_M_TX_OVER_Msk) /*!< M_TX_OVER Set Value */
#define I2C_IC_INTR_MASK_M_TX_OVER_Get(x) \
    (((uint32_t) (x) &I2C_IC_INTR_MASK_M_TX_OVER_Msk) >> I2C_IC_INTR_MASK_M_TX_OVER_Pos) /*!< M_TX_OVER Get Value */


#define I2C_IC_INTR_MASK_M_RX_FULL_Pos (2U)                                     /*!< M_RX_FULL Postion   2          */
#define I2C_IC_INTR_MASK_M_RX_FULL_Msk (0x1U << I2C_IC_INTR_MASK_M_RX_FULL_Pos) /*!< M_RX_FULL Mask      0x00000004 */
#define I2C_IC_INTR_MASK_M_RX_FULL_Set(x) \
    (((uint32_t) (x) << I2C_IC_INTR_MASK_M_RX_FULL_Pos) & I2C_IC_INTR_MASK_M_RX_FULL_Msk) /*!< M_RX_FULL Set Value */
#define I2C_IC_INTR_MASK_M_RX_FULL_Get(x) \
    (((uint32_t) (x) &I2C_IC_INTR_MASK_M_RX_FULL_Msk) >> I2C_IC_INTR_MASK_M_RX_FULL_Pos) /*!< M_RX_FULL Get Value */


#define I2C_IC_INTR_MASK_M_RX_OVER_Pos (1U)                                     /*!< M_RX_OVER Postion   1          */
#define I2C_IC_INTR_MASK_M_RX_OVER_Msk (0x1U << I2C_IC_INTR_MASK_M_RX_OVER_Pos) /*!< M_RX_OVER Mask      0x00000002 */
#define I2C_IC_INTR_MASK_M_RX_OVER_Set(x) \
    (((uint32_t) (x) << I2C_IC_INTR_MASK_M_RX_OVER_Pos) & I2C_IC_INTR_MASK_M_RX_OVER_Msk) /*!< M_RX_OVER Set Value */
#define I2C_IC_INTR_MASK_M_RX_OVER_Get(x) \
    (((uint32_t) (x) &I2C_IC_INTR_MASK_M_RX_OVER_Msk) >> I2C_IC_INTR_MASK_M_RX_OVER_Pos) /*!< M_RX_OVER Get Value */


#define I2C_IC_INTR_MASK_M_RX_UNDER_Pos (0U) /*!< M_RX_UNDER Postion   0          */
#define I2C_IC_INTR_MASK_M_RX_UNDER_Msk \
    (0x1U << I2C_IC_INTR_MASK_M_RX_UNDER_Pos) /*!< M_RX_UNDER Mask      0x00000001 */
#define I2C_IC_INTR_MASK_M_RX_UNDER_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_INTR_MASK_M_RX_UNDER_Pos) & \
     I2C_IC_INTR_MASK_M_RX_UNDER_Msk) /*!< M_RX_UNDER Set Value            */
#define I2C_IC_INTR_MASK_M_RX_UNDER_Get(x)                \
    (((uint32_t) (x) &I2C_IC_INTR_MASK_M_RX_UNDER_Msk) >> \
     I2C_IC_INTR_MASK_M_RX_UNDER_Pos) /*!< M_RX_UNDER Get Value            */


/* IC_RAW_INTR_STAT bitfield */
#define I2C_IC_RAW_INTR_STAT_SCL_STUCK_AT_LOW_Pos (14U) /*!< SCL_STUCK_AT_LOW Postion   14         */
#define I2C_IC_RAW_INTR_STAT_SCL_STUCK_AT_LOW_Msk \
    (0x1U << I2C_IC_RAW_INTR_STAT_SCL_STUCK_AT_LOW_Pos) /*!< SCL_STUCK_AT_LOW Mask      0x00004000 */
#define I2C_IC_RAW_INTR_STAT_SCL_STUCK_AT_LOW_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_RAW_INTR_STAT_SCL_STUCK_AT_LOW_Pos) & \
     I2C_IC_RAW_INTR_STAT_SCL_STUCK_AT_LOW_Msk) /*!< SCL_STUCK_AT_LOW Set Value            */
#define I2C_IC_RAW_INTR_STAT_SCL_STUCK_AT_LOW_Get(x)                \
    (((uint32_t) (x) &I2C_IC_RAW_INTR_STAT_SCL_STUCK_AT_LOW_Msk) >> \
     I2C_IC_RAW_INTR_STAT_SCL_STUCK_AT_LOW_Pos) /*!< SCL_STUCK_AT_LOW Get Value            */


#define I2C_IC_RAW_INTR_STAT_MASTER_ON_HOLD_Pos (13U) /*!< MASTER_ON_HOLD Postion   13         */
#define I2C_IC_RAW_INTR_STAT_MASTER_ON_HOLD_Msk \
    (0x1U << I2C_IC_RAW_INTR_STAT_MASTER_ON_HOLD_Pos) /*!< MASTER_ON_HOLD Mask      0x00002000 */
#define I2C_IC_RAW_INTR_STAT_MASTER_ON_HOLD_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_RAW_INTR_STAT_MASTER_ON_HOLD_Pos) & \
     I2C_IC_RAW_INTR_STAT_MASTER_ON_HOLD_Msk) /*!< MASTER_ON_HOLD Set Value            */
#define I2C_IC_RAW_INTR_STAT_MASTER_ON_HOLD_Get(x)                \
    (((uint32_t) (x) &I2C_IC_RAW_INTR_STAT_MASTER_ON_HOLD_Msk) >> \
     I2C_IC_RAW_INTR_STAT_MASTER_ON_HOLD_Pos) /*!< MASTER_ON_HOLD Get Value            */


#define I2C_IC_RAW_INTR_STAT_RESTART_DET_Pos (12U) /*!< RESTART_DET Postion   12         */
#define I2C_IC_RAW_INTR_STAT_RESTART_DET_Msk \
    (0x1U << I2C_IC_RAW_INTR_STAT_RESTART_DET_Pos) /*!< RESTART_DET Mask      0x00001000 */
#define I2C_IC_RAW_INTR_STAT_RESTART_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_RAW_INTR_STAT_RESTART_DET_Pos) & \
     I2C_IC_RAW_INTR_STAT_RESTART_DET_Msk) /*!< RESTART_DET Set Value            */
#define I2C_IC_RAW_INTR_STAT_RESTART_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_RAW_INTR_STAT_RESTART_DET_Msk) >> \
     I2C_IC_RAW_INTR_STAT_RESTART_DET_Pos) /*!< RESTART_DET Get Value            */


#define I2C_IC_RAW_INTR_STAT_GEN_CALL_Pos (11U) /*!< GEN_CALL Postion   11         */
#define I2C_IC_RAW_INTR_STAT_GEN_CALL_Msk \
    (0x1U << I2C_IC_RAW_INTR_STAT_GEN_CALL_Pos) /*!< GEN_CALL Mask      0x00000800 */
#define I2C_IC_RAW_INTR_STAT_GEN_CALL_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_RAW_INTR_STAT_GEN_CALL_Pos) & \
     I2C_IC_RAW_INTR_STAT_GEN_CALL_Msk) /*!< GEN_CALL Set Value            */
#define I2C_IC_RAW_INTR_STAT_GEN_CALL_Get(x)                \
    (((uint32_t) (x) &I2C_IC_RAW_INTR_STAT_GEN_CALL_Msk) >> \
     I2C_IC_RAW_INTR_STAT_GEN_CALL_Pos) /*!< GEN_CALL Get Value            */


#define I2C_IC_RAW_INTR_STAT_START_DET_Pos (10U) /*!< START_DET Postion   10         */
#define I2C_IC_RAW_INTR_STAT_START_DET_Msk \
    (0x1U << I2C_IC_RAW_INTR_STAT_START_DET_Pos) /*!< START_DET Mask      0x00000400 */
#define I2C_IC_RAW_INTR_STAT_START_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_RAW_INTR_STAT_START_DET_Pos) & \
     I2C_IC_RAW_INTR_STAT_START_DET_Msk) /*!< START_DET Set Value            */
#define I2C_IC_RAW_INTR_STAT_START_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_RAW_INTR_STAT_START_DET_Msk) >> \
     I2C_IC_RAW_INTR_STAT_START_DET_Pos) /*!< START_DET Get Value            */


#define I2C_IC_RAW_INTR_STAT_STOP_DET_Pos (9U) /*!< STOP_DET Postion   9          */
#define I2C_IC_RAW_INTR_STAT_STOP_DET_Msk \
    (0x1U << I2C_IC_RAW_INTR_STAT_STOP_DET_Pos) /*!< STOP_DET Mask      0x00000200 */
#define I2C_IC_RAW_INTR_STAT_STOP_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_RAW_INTR_STAT_STOP_DET_Pos) & \
     I2C_IC_RAW_INTR_STAT_STOP_DET_Msk) /*!< STOP_DET Set Value            */
#define I2C_IC_RAW_INTR_STAT_STOP_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_RAW_INTR_STAT_STOP_DET_Msk) >> \
     I2C_IC_RAW_INTR_STAT_STOP_DET_Pos) /*!< STOP_DET Get Value            */


#define I2C_IC_RAW_INTR_STAT_ACTIVITY_Pos (8U) /*!< ACTIVITY Postion   8          */
#define I2C_IC_RAW_INTR_STAT_ACTIVITY_Msk \
    (0x1U << I2C_IC_RAW_INTR_STAT_ACTIVITY_Pos) /*!< ACTIVITY Mask      0x00000100 */
#define I2C_IC_RAW_INTR_STAT_ACTIVITY_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_RAW_INTR_STAT_ACTIVITY_Pos) & \
     I2C_IC_RAW_INTR_STAT_ACTIVITY_Msk) /*!< ACTIVITY Set Value            */
#define I2C_IC_RAW_INTR_STAT_ACTIVITY_Get(x)                \
    (((uint32_t) (x) &I2C_IC_RAW_INTR_STAT_ACTIVITY_Msk) >> \
     I2C_IC_RAW_INTR_STAT_ACTIVITY_Pos) /*!< ACTIVITY Get Value            */


#define I2C_IC_RAW_INTR_STAT_RX_DONE_Pos (7U) /*!< RX_DONE Postion   7          */
#define I2C_IC_RAW_INTR_STAT_RX_DONE_Msk                                         \
    (0x1U << I2C_IC_RAW_INTR_STAT_RX_DONE_Pos) /*!< RX_DONE Mask      0x00000080 \
                                                */
#define I2C_IC_RAW_INTR_STAT_RX_DONE_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_RAW_INTR_STAT_RX_DONE_Pos) & \
     I2C_IC_RAW_INTR_STAT_RX_DONE_Msk) /*!< RX_DONE Set Value            */
#define I2C_IC_RAW_INTR_STAT_RX_DONE_Get(x) \
    (((uint32_t) (x) &I2C_IC_RAW_INTR_STAT_RX_DONE_Msk) >> I2C_IC_RAW_INTR_STAT_RX_DONE_Pos) /*!< RX_DONE Get Value */


#define I2C_IC_RAW_INTR_STAT_TX_ABRT_Pos (6U) /*!< TX_ABRT Postion   6          */
#define I2C_IC_RAW_INTR_STAT_TX_ABRT_Msk                                         \
    (0x1U << I2C_IC_RAW_INTR_STAT_TX_ABRT_Pos) /*!< TX_ABRT Mask      0x00000040 \
                                                */
#define I2C_IC_RAW_INTR_STAT_TX_ABRT_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_RAW_INTR_STAT_TX_ABRT_Pos) & \
     I2C_IC_RAW_INTR_STAT_TX_ABRT_Msk) /*!< TX_ABRT Set Value            */
#define I2C_IC_RAW_INTR_STAT_TX_ABRT_Get(x) \
    (((uint32_t) (x) &I2C_IC_RAW_INTR_STAT_TX_ABRT_Msk) >> I2C_IC_RAW_INTR_STAT_TX_ABRT_Pos) /*!< TX_ABRT Get Value */


#define I2C_IC_RAW_INTR_STAT_RD_REQ_Pos (5U)                                      /*!< RD_REQ Postion   5          */
#define I2C_IC_RAW_INTR_STAT_RD_REQ_Msk (0x1U << I2C_IC_RAW_INTR_STAT_RD_REQ_Pos) /*!< RD_REQ Mask      0x00000020 */
#define I2C_IC_RAW_INTR_STAT_RD_REQ_Set(x) \
    (((uint32_t) (x) << I2C_IC_RAW_INTR_STAT_RD_REQ_Pos) & I2C_IC_RAW_INTR_STAT_RD_REQ_Msk) /*!< RD_REQ Set Value */
#define I2C_IC_RAW_INTR_STAT_RD_REQ_Get(x) \
    (((uint32_t) (x) &I2C_IC_RAW_INTR_STAT_RD_REQ_Msk) >> I2C_IC_RAW_INTR_STAT_RD_REQ_Pos) /*!< RD_REQ Get Value */


#define I2C_IC_RAW_INTR_STAT_TX_EMPTY_Pos (4U) /*!< X_EMPTY Postion   4          */
#define I2C_IC_RAW_INTR_STAT_TX_EMPTY_Msk                                         \
    (0x1U << I2C_IC_RAW_INTR_STAT_TX_EMPTY_Pos) /*!< X_EMPTY Mask      0x00000010 \
                                                 */
#define I2C_IC_RAW_INTR_STAT_TX_EMPTY_Set(x)                \
    (((uint32_t)(x) << I2C_IC_RAW_INTR_STAT_TX_EMPTY_Pos) & \
     I2C_IC_RAW_INTR_STAT_TX_EMPTY_Msk) /*!< X_EMPTY Set Value            */
#define I2C_IC_RAW_INTR_STAT_TX_EMPTY_Get(x) \
    (((uint32_t)(x)&I2C_IC_RAW_INTR_STAT_TX_EMPTY_Msk) >> I2C_IC_RAW_INTR_STAT_TX_EMPTY_Pos) /*!< X_EMPTY Get Value */


#define I2C_IC_RAW_INTR_STAT_TX_OVER_Pos (3U) /*!< TX_OVER Postion   3          */
#define I2C_IC_RAW_INTR_STAT_TX_OVER_Msk                                         \
    (0x1U << I2C_IC_RAW_INTR_STAT_TX_OVER_Pos) /*!< TX_OVER Mask      0x00000008 \
                                                */
#define I2C_IC_RAW_INTR_STAT_TX_OVER_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_RAW_INTR_STAT_TX_OVER_Pos) & \
     I2C_IC_RAW_INTR_STAT_TX_OVER_Msk) /*!< TX_OVER Set Value            */
#define I2C_IC_RAW_INTR_STAT_TX_OVER_Get(x) \
    (((uint32_t) (x) &I2C_IC_RAW_INTR_STAT_TX_OVER_Msk) >> I2C_IC_RAW_INTR_STAT_TX_OVER_Pos) /*!< TX_OVER Get Value */


#define I2C_IC_RAW_INTR_STAT_RX_FULL_Pos (2U) /*!< RX_FULL Postion   2          */
#define I2C_IC_RAW_INTR_STAT_RX_FULL_Msk                                         \
    (0x1U << I2C_IC_RAW_INTR_STAT_RX_FULL_Pos) /*!< RX_FULL Mask      0x00000004 \
                                                */
#define I2C_IC_RAW_INTR_STAT_RX_FULL_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_RAW_INTR_STAT_RX_FULL_Pos) & \
     I2C_IC_RAW_INTR_STAT_RX_FULL_Msk) /*!< RX_FULL Set Value            */
#define I2C_IC_RAW_INTR_STAT_RX_FULL_Get(x) \
    (((uint32_t) (x) &I2C_IC_RAW_INTR_STAT_RX_FULL_Msk) >> I2C_IC_RAW_INTR_STAT_RX_FULL_Pos) /*!< RX_FULL Get Value */


#define I2C_IC_RAW_INTR_STAT_RX_OVER_Pos (1U) /*!< RX_OVER Postion   1          */
#define I2C_IC_RAW_INTR_STAT_RX_OVER_Msk                                         \
    (0x1U << I2C_IC_RAW_INTR_STAT_RX_OVER_Pos) /*!< RX_OVER Mask      0x00000002 \
                                                */
#define I2C_IC_RAW_INTR_STAT_RX_OVER_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_RAW_INTR_STAT_RX_OVER_Pos) & \
     I2C_IC_RAW_INTR_STAT_RX_OVER_Msk) /*!< RX_OVER Set Value            */
#define I2C_IC_RAW_INTR_STAT_RX_OVER_Get(x) \
    (((uint32_t) (x) &I2C_IC_RAW_INTR_STAT_RX_OVER_Msk) >> I2C_IC_RAW_INTR_STAT_RX_OVER_Pos) /*!< RX_OVER Get Value */


#define I2C_IC_RAW_INTR_STAT_RX_UNDER_Pos (0U) /*!< RX_UNDER Postion   0          */
#define I2C_IC_RAW_INTR_STAT_RX_UNDER_Msk \
    (0x1U << I2C_IC_RAW_INTR_STAT_RX_UNDER_Pos) /*!< RX_UNDER Mask      0x00000001 */
#define I2C_IC_RAW_INTR_STAT_RX_UNDER_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_RAW_INTR_STAT_RX_UNDER_Pos) & \
     I2C_IC_RAW_INTR_STAT_RX_UNDER_Msk) /*!< RX_UNDER Set Value            */
#define I2C_IC_RAW_INTR_STAT_RX_UNDER_Get(x)                \
    (((uint32_t) (x) &I2C_IC_RAW_INTR_STAT_RX_UNDER_Msk) >> \
     I2C_IC_RAW_INTR_STAT_RX_UNDER_Pos) /*!< RX_UNDER Get Value            */


/* IC_RX_TL bitfield */
#define I2C_IC_RX_TL_RX_TL_Pos (0U)                              /*!< RX_TL Postion   0          */
#define I2C_IC_RX_TL_RX_TL_Msk (0xffU << I2C_IC_RX_TL_RX_TL_Pos) /*!< RX_TL Mask      0x000000FF */
#define I2C_IC_RX_TL_RX_TL_Set(x) \
    (((uint32_t) (x) << I2C_IC_RX_TL_RX_TL_Pos) & I2C_IC_RX_TL_RX_TL_Msk) /*!< RX_TL Set Value            */
#define I2C_IC_RX_TL_RX_TL_Get(x) \
    (((uint32_t) (x) &I2C_IC_RX_TL_RX_TL_Msk) >> I2C_IC_RX_TL_RX_TL_Pos) /*!< RX_TL Get Value            */


/* IC_TX_TL bitfield */
#define I2C_IC_TX_TL_TX_TL_Pos (0U)                              /*!< TX_TL Postion   0          */
#define I2C_IC_TX_TL_TX_TL_Msk (0xffU << I2C_IC_TX_TL_TX_TL_Pos) /*!< TX_TL Mask      0x000000FF */
#define I2C_IC_TX_TL_TX_TL_Set(x) \
    (((uint32_t) (x) << I2C_IC_TX_TL_TX_TL_Pos) & I2C_IC_TX_TL_TX_TL_Msk) /*!< TX_TL Set Value            */
#define I2C_IC_TX_TL_TX_TL_Get(x) \
    (((uint32_t) (x) &I2C_IC_TX_TL_TX_TL_Msk) >> I2C_IC_TX_TL_TX_TL_Pos) /*!< TX_TL Get Value            */


/* IC_CLR_INT bitfield */
#define I2C_IC_CLR_INT_CLR_INTR_Pos (0U)                                  /*!< CLR_INTR Postion   0          */
#define I2C_IC_CLR_INT_CLR_INTR_Msk (0x1U << I2C_IC_CLR_INT_CLR_INTR_Pos) /*!< CLR_INTR Mask      0x00000001 */
#define I2C_IC_CLR_INT_CLR_INTR_Set(x) \
    (((uint32_t) (x) << I2C_IC_CLR_INT_CLR_INTR_Pos) & I2C_IC_CLR_INT_CLR_INTR_Msk) /*!< CLR_INTR Set Value */
#define I2C_IC_CLR_INT_CLR_INTR_Get(x) \
    (((uint32_t) (x) &I2C_IC_CLR_INT_CLR_INTR_Msk) >> I2C_IC_CLR_INT_CLR_INTR_Pos) /*!< CLR_INTR Get Value */


/* IC_CLR_RX_UNDER bitfield */
#define I2C_IC_CLR_RX_UNDER_CLR_RX_UNDER_Pos (0U) /*!< CLR_RX_UNDER Postion   0          */
#define I2C_IC_CLR_RX_UNDER_CLR_RX_UNDER_Msk \
    (0x1U << I2C_IC_CLR_RX_UNDER_CLR_RX_UNDER_Pos) /*!< CLR_RX_UNDER Mask      0x00000001 */
#define I2C_IC_CLR_RX_UNDER_CLR_RX_UNDER_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_CLR_RX_UNDER_CLR_RX_UNDER_Pos) & \
     I2C_IC_CLR_RX_UNDER_CLR_RX_UNDER_Msk) /*!< CLR_RX_UNDER Set Value            */
#define I2C_IC_CLR_RX_UNDER_CLR_RX_UNDER_Get(x)                \
    (((uint32_t) (x) &I2C_IC_CLR_RX_UNDER_CLR_RX_UNDER_Msk) >> \
     I2C_IC_CLR_RX_UNDER_CLR_RX_UNDER_Pos) /*!< CLR_RX_UNDER Get Value            */


/* IC_CLR_RX_OVER bitfield */
#define I2C_IC_CLR_RX_OVER_CLR_RX_OVER_Pos (0U) /*!< CLR_RX_OVER Postion   0          */
#define I2C_IC_CLR_RX_OVER_CLR_RX_OVER_Msk \
    (0x1U << I2C_IC_CLR_RX_OVER_CLR_RX_OVER_Pos) /*!< CLR_RX_OVER Mask      0x00000001 */
#define I2C_IC_CLR_RX_OVER_CLR_RX_OVER_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_CLR_RX_OVER_CLR_RX_OVER_Pos) & \
     I2C_IC_CLR_RX_OVER_CLR_RX_OVER_Msk) /*!< CLR_RX_OVER Set Value            */
#define I2C_IC_CLR_RX_OVER_CLR_RX_OVER_Get(x)                \
    (((uint32_t) (x) &I2C_IC_CLR_RX_OVER_CLR_RX_OVER_Msk) >> \
     I2C_IC_CLR_RX_OVER_CLR_RX_OVER_Pos) /*!< CLR_RX_OVER Get Value            */


/* IC_CLR_TX_OVER bitfield */
#define I2C_IC_CLR_TX_OVER_CLR_TX_OVER_Pos (0U) /*!< CLR_TX_OVER Postion   0          */
#define I2C_IC_CLR_TX_OVER_CLR_TX_OVER_Msk \
    (0x1U << I2C_IC_CLR_TX_OVER_CLR_TX_OVER_Pos) /*!< CLR_TX_OVER Mask      0x00000001 */
#define I2C_IC_CLR_TX_OVER_CLR_TX_OVER_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_CLR_TX_OVER_CLR_TX_OVER_Pos) & \
     I2C_IC_CLR_TX_OVER_CLR_TX_OVER_Msk) /*!< CLR_TX_OVER Set Value            */
#define I2C_IC_CLR_TX_OVER_CLR_TX_OVER_Get(x)                \
    (((uint32_t) (x) &I2C_IC_CLR_TX_OVER_CLR_TX_OVER_Msk) >> \
     I2C_IC_CLR_TX_OVER_CLR_TX_OVER_Pos) /*!< CLR_TX_OVER Get Value            */


/* IC_CLR_RD_REQ bitfield */
#define I2C_IC_CLR_RD_REQ_CLR_RD_REQ_Pos (0U) /*!< CLR_RD_REQ Postion   0          */
#define I2C_IC_CLR_RD_REQ_CLR_RD_REQ_Msk \
    (0x1U << I2C_IC_CLR_RD_REQ_CLR_RD_REQ_Pos) /*!< CLR_RD_REQ Mask      0x00000001 */
#define I2C_IC_CLR_RD_REQ_CLR_RD_REQ_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_CLR_RD_REQ_CLR_RD_REQ_Pos) & \
     I2C_IC_CLR_RD_REQ_CLR_RD_REQ_Msk) /*!< CLR_RD_REQ Set Value            */
#define I2C_IC_CLR_RD_REQ_CLR_RD_REQ_Get(x)                \
    (((uint32_t) (x) &I2C_IC_CLR_RD_REQ_CLR_RD_REQ_Msk) >> \
     I2C_IC_CLR_RD_REQ_CLR_RD_REQ_Pos) /*!< CLR_RD_REQ Get Value            */


/* IC_CLR_TX_ABRT bitfield */
#define I2C_IC_CLR_TX_ABRT_CLR_TX_ABRT_Pos (0U) /*!< CLR_TX_ABRT Postion   0          */
#define I2C_IC_CLR_TX_ABRT_CLR_TX_ABRT_Msk \
    (0x1U << I2C_IC_CLR_TX_ABRT_CLR_TX_ABRT_Pos) /*!< CLR_TX_ABRT Mask      0x00000001 */
#define I2C_IC_CLR_TX_ABRT_CLR_TX_ABRT_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_CLR_TX_ABRT_CLR_TX_ABRT_Pos) & \
     I2C_IC_CLR_TX_ABRT_CLR_TX_ABRT_Msk) /*!< CLR_TX_ABRT Set Value            */
#define I2C_IC_CLR_TX_ABRT_CLR_TX_ABRT_Get(x)                \
    (((uint32_t) (x) &I2C_IC_CLR_TX_ABRT_CLR_TX_ABRT_Msk) >> \
     I2C_IC_CLR_TX_ABRT_CLR_TX_ABRT_Pos) /*!< CLR_TX_ABRT Get Value            */


/* IC_CLR_RX_DONE bitfield */
#define I2C_IC_CLR_RX_DONE_CLR_RX_DONE_Pos (0U) /*!< CLR_RX_DONE Postion   0          */
#define I2C_IC_CLR_RX_DONE_CLR_RX_DONE_Msk \
    (0x1U << I2C_IC_CLR_RX_DONE_CLR_RX_DONE_Pos) /*!< CLR_RX_DONE Mask      0x00000001 */
#define I2C_IC_CLR_RX_DONE_CLR_RX_DONE_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_CLR_RX_DONE_CLR_RX_DONE_Pos) & \
     I2C_IC_CLR_RX_DONE_CLR_RX_DONE_Msk) /*!< CLR_RX_DONE Set Value            */
#define I2C_IC_CLR_RX_DONE_CLR_RX_DONE_Get(x)                \
    (((uint32_t) (x) &I2C_IC_CLR_RX_DONE_CLR_RX_DONE_Msk) >> \
     I2C_IC_CLR_RX_DONE_CLR_RX_DONE_Pos) /*!< CLR_RX_DONE Get Value            */


/* IC_CLR_ACTIVITY bitfield */
#define I2C_IC_CLR_ACTIVITY_CLR_ACTIVITY_Pos (0U) /*!< CLR_ACTIVITY Postion   0          */
#define I2C_IC_CLR_ACTIVITY_CLR_ACTIVITY_Msk \
    (0x1U << I2C_IC_CLR_ACTIVITY_CLR_ACTIVITY_Pos) /*!< CLR_ACTIVITY Mask      0x00000001 */
#define I2C_IC_CLR_ACTIVITY_CLR_ACTIVITY_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_CLR_ACTIVITY_CLR_ACTIVITY_Pos) & \
     I2C_IC_CLR_ACTIVITY_CLR_ACTIVITY_Msk) /*!< CLR_ACTIVITY Set Value            */
#define I2C_IC_CLR_ACTIVITY_CLR_ACTIVITY_Get(x)                \
    (((uint32_t) (x) &I2C_IC_CLR_ACTIVITY_CLR_ACTIVITY_Msk) >> \
     I2C_IC_CLR_ACTIVITY_CLR_ACTIVITY_Pos) /*!< CLR_ACTIVITY Get Value            */


/* IC_CLR_STOP_DET bitfield */
#define I2C_IC_CLR_STOP_DET_CLR_STOP_DET_Pos (0U) /*!< CLR_STOP_DET Postion   0          */
#define I2C_IC_CLR_STOP_DET_CLR_STOP_DET_Msk \
    (0x1U << I2C_IC_CLR_STOP_DET_CLR_STOP_DET_Pos) /*!< CLR_STOP_DET Mask      0x00000001 */
#define I2C_IC_CLR_STOP_DET_CLR_STOP_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_CLR_STOP_DET_CLR_STOP_DET_Pos) & \
     I2C_IC_CLR_STOP_DET_CLR_STOP_DET_Msk) /*!< CLR_STOP_DET Set Value            */
#define I2C_IC_CLR_STOP_DET_CLR_STOP_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_CLR_STOP_DET_CLR_STOP_DET_Msk) >> \
     I2C_IC_CLR_STOP_DET_CLR_STOP_DET_Pos) /*!< CLR_STOP_DET Get Value            */


/* IC_CLR_START_DET bitfield */
#define I2C_IC_CLR_START_DET_CLR_START_DET_Pos (0U) /*!< CLR_START_DET Postion   0          */
#define I2C_IC_CLR_START_DET_CLR_START_DET_Msk \
    (0x1U << I2C_IC_CLR_START_DET_CLR_START_DET_Pos) /*!< CLR_START_DET Mask      0x00000001 */
#define I2C_IC_CLR_START_DET_CLR_START_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_CLR_START_DET_CLR_START_DET_Pos) & \
     I2C_IC_CLR_START_DET_CLR_START_DET_Msk) /*!< CLR_START_DET Set Value            */
#define I2C_IC_CLR_START_DET_CLR_START_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_CLR_START_DET_CLR_START_DET_Msk) >> \
     I2C_IC_CLR_START_DET_CLR_START_DET_Pos) /*!< CLR_START_DET Get Value            */


/* IC_CLR_GEN_CALL bitfield */
#define I2C_IC_CLR_GEN_CALL_CLR_GEN_CALL_Pos (0U) /*!< CLR_GEN_CALL Postion   0          */
#define I2C_IC_CLR_GEN_CALL_CLR_GEN_CALL_Msk \
    (0x1U << I2C_IC_CLR_GEN_CALL_CLR_GEN_CALL_Pos) /*!< CLR_GEN_CALL Mask      0x00000001 */
#define I2C_IC_CLR_GEN_CALL_CLR_GEN_CALL_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_CLR_GEN_CALL_CLR_GEN_CALL_Pos) & \
     I2C_IC_CLR_GEN_CALL_CLR_GEN_CALL_Msk) /*!< CLR_GEN_CALL Set Value            */
#define I2C_IC_CLR_GEN_CALL_CLR_GEN_CALL_Get(x)                \
    (((uint32_t) (x) &I2C_IC_CLR_GEN_CALL_CLR_GEN_CALL_Msk) >> \
     I2C_IC_CLR_GEN_CALL_CLR_GEN_CALL_Pos) /*!< CLR_GEN_CALL Get Value            */


/* IC_ENABLE bitfield */
#define I2C_IC_ENABLE_SMBUS_ALERT_EN_Pos (18U) /*!< SMBUS_ALERT_EN Postion   18         */
#define I2C_IC_ENABLE_SMBUS_ALERT_EN_Msk \
    (0x1U << I2C_IC_ENABLE_SMBUS_ALERT_EN_Pos) /*!< SMBUS_ALERT_EN Mask      0x00040000 */
#define I2C_IC_ENABLE_SMBUS_ALERT_EN_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_ENABLE_SMBUS_ALERT_EN_Pos) & \
     I2C_IC_ENABLE_SMBUS_ALERT_EN_Msk) /*!< SMBUS_ALERT_EN Set Value            */
#define I2C_IC_ENABLE_SMBUS_ALERT_EN_Get(x)                \
    (((uint32_t) (x) &I2C_IC_ENABLE_SMBUS_ALERT_EN_Msk) >> \
     I2C_IC_ENABLE_SMBUS_ALERT_EN_Pos) /*!< SMBUS_ALERT_EN Get Value            */


#define I2C_IC_ENABLE_SMBUS_SUSPEND_EN_Pos (17U) /*!< SMBUS_SUSPEND_EN Postion   17         */
#define I2C_IC_ENABLE_SMBUS_SUSPEND_EN_Msk \
    (0x1U << I2C_IC_ENABLE_SMBUS_SUSPEND_EN_Pos) /*!< SMBUS_SUSPEND_EN Mask      0x00020000 */
#define I2C_IC_ENABLE_SMBUS_SUSPEND_EN_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_ENABLE_SMBUS_SUSPEND_EN_Pos) & \
     I2C_IC_ENABLE_SMBUS_SUSPEND_EN_Msk) /*!< SMBUS_SUSPEND_EN Set Value            */
#define I2C_IC_ENABLE_SMBUS_SUSPEND_EN_Get(x)                \
    (((uint32_t) (x) &I2C_IC_ENABLE_SMBUS_SUSPEND_EN_Msk) >> \
     I2C_IC_ENABLE_SMBUS_SUSPEND_EN_Pos) /*!< SMBUS_SUSPEND_EN Get Value            */


#define I2C_IC_ENABLE_SMBUS_CLK_RESET_Pos (16U) /*!< SMBUS_CLK_RESET Postion   16         */
#define I2C_IC_ENABLE_SMBUS_CLK_RESET_Msk \
    (0x1U << I2C_IC_ENABLE_SMBUS_CLK_RESET_Pos) /*!< SMBUS_CLK_RESET Mask      0x00010000 */
#define I2C_IC_ENABLE_SMBUS_CLK_RESET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_ENABLE_SMBUS_CLK_RESET_Pos) & \
     I2C_IC_ENABLE_SMBUS_CLK_RESET_Msk) /*!< SMBUS_CLK_RESET Set Value            */
#define I2C_IC_ENABLE_SMBUS_CLK_RESET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_ENABLE_SMBUS_CLK_RESET_Msk) >> \
     I2C_IC_ENABLE_SMBUS_CLK_RESET_Pos) /*!< SMBUS_CLK_RESET Get Value            */


#define I2C_IC_ENABLE_SDA_STUCK_RECOVERY_ENABLE_Pos (3U) /*!< SDA_STUCK_RECOVERY_ENABLE Postion   3          */
#define I2C_IC_ENABLE_SDA_STUCK_RECOVERY_ENABLE_Msk \
    (0x1U << I2C_IC_ENABLE_SDA_STUCK_RECOVERY_ENABLE_Pos) /*!< SDA_STUCK_RECOVERY_ENABLE Mask      0x00000008 */
#define I2C_IC_ENABLE_SDA_STUCK_RECOVERY_ENABLE_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_ENABLE_SDA_STUCK_RECOVERY_ENABLE_Pos) & \
     I2C_IC_ENABLE_SDA_STUCK_RECOVERY_ENABLE_Msk) /*!< SDA_STUCK_RECOVERY_ENABLE Set Value            */
#define I2C_IC_ENABLE_SDA_STUCK_RECOVERY_ENABLE_Get(x)                \
    (((uint32_t) (x) &I2C_IC_ENABLE_SDA_STUCK_RECOVERY_ENABLE_Msk) >> \
     I2C_IC_ENABLE_SDA_STUCK_RECOVERY_ENABLE_Pos) /*!< SDA_STUCK_RECOVERY_ENABLE Get Value            */


#define I2C_IC_ENABLE_TX_CMD_BLOCK_Pos (2U) /*!< TX_CMD_BLOCK Postion   2          */
#define I2C_IC_ENABLE_TX_CMD_BLOCK_Msk \
    (0x1U << I2C_IC_ENABLE_TX_CMD_BLOCK_Pos) /*!< TX_CMD_BLOCK Mask      0x00000004 */
#define I2C_IC_ENABLE_TX_CMD_BLOCK_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_ENABLE_TX_CMD_BLOCK_Pos) & \
     I2C_IC_ENABLE_TX_CMD_BLOCK_Msk) /*!< TX_CMD_BLOCK Set Value            */
#define I2C_IC_ENABLE_TX_CMD_BLOCK_Get(x)                \
    (((uint32_t) (x) &I2C_IC_ENABLE_TX_CMD_BLOCK_Msk) >> \
     I2C_IC_ENABLE_TX_CMD_BLOCK_Pos) /*!< TX_CMD_BLOCK Get Value            */


#define I2C_IC_ENABLE_ABORT_Pos (1U)                              /*!< ABORT Postion   1          */
#define I2C_IC_ENABLE_ABORT_Msk (0x1U << I2C_IC_ENABLE_ABORT_Pos) /*!< ABORT Mask      0x00000002 */
#define I2C_IC_ENABLE_ABORT_Set(x) \
    (((uint32_t) (x) << I2C_IC_ENABLE_ABORT_Pos) & I2C_IC_ENABLE_ABORT_Msk) /*!< ABORT Set Value            */
#define I2C_IC_ENABLE_ABORT_Get(x) \
    (((uint32_t) (x) &I2C_IC_ENABLE_ABORT_Msk) >> I2C_IC_ENABLE_ABORT_Pos) /*!< ABORT Get Value            */


#define I2C_IC_ENABLE_I2C_EN_Pos (0U)                               /*!< I2C_EN Postion   0          */
#define I2C_IC_ENABLE_I2C_EN_Msk (0x1U << I2C_IC_ENABLE_I2C_EN_Pos) /*!< I2C_EN Mask      0x00000001 */
#define I2C_IC_ENABLE_I2C_EN_Set(x) \
    (((uint32_t) (x) << I2C_IC_ENABLE_I2C_EN_Pos) & I2C_IC_ENABLE_I2C_EN_Msk) /*!< I2C_EN Set Value            */
#define I2C_IC_ENABLE_I2C_EN_Get(x) \
    (((uint32_t) (x) &I2C_IC_ENABLE_I2C_EN_Msk) >> I2C_IC_ENABLE_I2C_EN_Pos) /*!< I2C_EN Get Value            */


/* IC_STATUS bitfield */
#define I2C_IC_STATUS_SMBUS_ALERT_STATUS_Pos (20U) /*!< SMBUS_ALERT_STATUS Postion   20         */
#define I2C_IC_STATUS_SMBUS_ALERT_STATUS_Msk \
    (0x1U << I2C_IC_STATUS_SMBUS_ALERT_STATUS_Pos) /*!< SMBUS_ALERT_STATUS Mask      0x00100000 */
#define I2C_IC_STATUS_SMBUS_ALERT_STATUS_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_STATUS_SMBUS_ALERT_STATUS_Pos) & \
     I2C_IC_STATUS_SMBUS_ALERT_STATUS_Msk) /*!< SMBUS_ALERT_STATUS Set Value            */
#define I2C_IC_STATUS_SMBUS_ALERT_STATUS_Get(x)                \
    (((uint32_t) (x) &I2C_IC_STATUS_SMBUS_ALERT_STATUS_Msk) >> \
     I2C_IC_STATUS_SMBUS_ALERT_STATUS_Pos) /*!< SMBUS_ALERT_STATUS Get Value            */


#define I2C_IC_STATUS_SMBUS_SUSPEND_STATUS_Pos (19U) /*!< SMBUS_SUSPEND_STATUS Postion   19         */
#define I2C_IC_STATUS_SMBUS_SUSPEND_STATUS_Msk \
    (0x1U << I2C_IC_STATUS_SMBUS_SUSPEND_STATUS_Pos) /*!< SMBUS_SUSPEND_STATUS Mask      0x00080000 */
#define I2C_IC_STATUS_SMBUS_SUSPEND_STATUS_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_STATUS_SMBUS_SUSPEND_STATUS_Pos) & \
     I2C_IC_STATUS_SMBUS_SUSPEND_STATUS_Msk) /*!< SMBUS_SUSPEND_STATUS Set Value            */
#define I2C_IC_STATUS_SMBUS_SUSPEND_STATUS_Get(x)                \
    (((uint32_t) (x) &I2C_IC_STATUS_SMBUS_SUSPEND_STATUS_Msk) >> \
     I2C_IC_STATUS_SMBUS_SUSPEND_STATUS_Pos) /*!< SMBUS_SUSPEND_STATUS Get Value            */


#define I2C_IC_STATUS_SMBUS_SLAVE_ADDR_RESOLVED_Pos (18U) /*!< SMBUS_SLAVE_ADDR_RESOLVED Postion   18         */
#define I2C_IC_STATUS_SMBUS_SLAVE_ADDR_RESOLVED_Msk \
    (0x1U << I2C_IC_STATUS_SMBUS_SLAVE_ADDR_RESOLVED_Pos) /*!< SMBUS_SLAVE_ADDR_RESOLVED Mask      0x00040000 */
#define I2C_IC_STATUS_SMBUS_SLAVE_ADDR_RESOLVED_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_STATUS_SMBUS_SLAVE_ADDR_RESOLVED_Pos) & \
     I2C_IC_STATUS_SMBUS_SLAVE_ADDR_RESOLVED_Msk) /*!< SMBUS_SLAVE_ADDR_RESOLVED Set Value            */
#define I2C_IC_STATUS_SMBUS_SLAVE_ADDR_RESOLVED_Get(x)                \
    (((uint32_t) (x) &I2C_IC_STATUS_SMBUS_SLAVE_ADDR_RESOLVED_Msk) >> \
     I2C_IC_STATUS_SMBUS_SLAVE_ADDR_RESOLVED_Pos) /*!< SMBUS_SLAVE_ADDR_RESOLVED Get Value            */


#define I2C_IC_STATUS_SMBUS_SLAVE_ADDR_VALID_Pos (17U) /*!< SMBUS_SLAVE_ADDR_VALID Postion   17         */
#define I2C_IC_STATUS_SMBUS_SLAVE_ADDR_VALID_Msk \
    (0x1U << I2C_IC_STATUS_SMBUS_SLAVE_ADDR_VALID_Pos) /*!< SMBUS_SLAVE_ADDR_VALID Mask      0x00020000 */
#define I2C_IC_STATUS_SMBUS_SLAVE_ADDR_VALID_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_STATUS_SMBUS_SLAVE_ADDR_VALID_Pos) & \
     I2C_IC_STATUS_SMBUS_SLAVE_ADDR_VALID_Msk) /*!< SMBUS_SLAVE_ADDR_VALID Set Value            */
#define I2C_IC_STATUS_SMBUS_SLAVE_ADDR_VALID_Get(x)                \
    (((uint32_t) (x) &I2C_IC_STATUS_SMBUS_SLAVE_ADDR_VALID_Msk) >> \
     I2C_IC_STATUS_SMBUS_SLAVE_ADDR_VALID_Pos) /*!< SMBUS_SLAVE_ADDR_VALID Get Value            */


#define I2C_IC_STATUS_SMBUS_QUICK_CMD_BIT_Pos (16U) /*!< SMBUS_QUICK_CMD_BIT Postion   16         */
#define I2C_IC_STATUS_SMBUS_QUICK_CMD_BIT_Msk \
    (0x1U << I2C_IC_STATUS_SMBUS_QUICK_CMD_BIT_Pos) /*!< SMBUS_QUICK_CMD_BIT Mask      0x00010000 */
#define I2C_IC_STATUS_SMBUS_QUICK_CMD_BIT_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_STATUS_SMBUS_QUICK_CMD_BIT_Pos) & \
     I2C_IC_STATUS_SMBUS_QUICK_CMD_BIT_Msk) /*!< SMBUS_QUICK_CMD_BIT Set Value            */
#define I2C_IC_STATUS_SMBUS_QUICK_CMD_BIT_Get(x)                \
    (((uint32_t) (x) &I2C_IC_STATUS_SMBUS_QUICK_CMD_BIT_Msk) >> \
     I2C_IC_STATUS_SMBUS_QUICK_CMD_BIT_Pos) /*!< SMBUS_QUICK_CMD_BIT Get Value            */


#define I2C_IC_STATUS_SDA_STUCK_NOT_RECOVERED_Pos (11U) /*!< SDA_STUCK_NOT_RECOVERED Postion   11         */
#define I2C_IC_STATUS_SDA_STUCK_NOT_RECOVERED_Msk \
    (0x1U << I2C_IC_STATUS_SDA_STUCK_NOT_RECOVERED_Pos) /*!< SDA_STUCK_NOT_RECOVERED Mask      0x00000800 */
#define I2C_IC_STATUS_SDA_STUCK_NOT_RECOVERED_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_STATUS_SDA_STUCK_NOT_RECOVERED_Pos) & \
     I2C_IC_STATUS_SDA_STUCK_NOT_RECOVERED_Msk) /*!< SDA_STUCK_NOT_RECOVERED Set Value            */
#define I2C_IC_STATUS_SDA_STUCK_NOT_RECOVERED_Get(x)                \
    (((uint32_t) (x) &I2C_IC_STATUS_SDA_STUCK_NOT_RECOVERED_Msk) >> \
     I2C_IC_STATUS_SDA_STUCK_NOT_RECOVERED_Pos) /*!< SDA_STUCK_NOT_RECOVERED Get Value            */


#define I2C_IC_STATUS_SLV_HOLD_RX_FIFO_FULL_Pos (10U) /*!< SLV_HOLD_RX_FIFO_FULL Postion   10         */
#define I2C_IC_STATUS_SLV_HOLD_RX_FIFO_FULL_Msk \
    (0x1U << I2C_IC_STATUS_SLV_HOLD_RX_FIFO_FULL_Pos) /*!< SLV_HOLD_RX_FIFO_FULL Mask      0x00000400 */
#define I2C_IC_STATUS_SLV_HOLD_RX_FIFO_FULL_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_STATUS_SLV_HOLD_RX_FIFO_FULL_Pos) & \
     I2C_IC_STATUS_SLV_HOLD_RX_FIFO_FULL_Msk) /*!< SLV_HOLD_RX_FIFO_FULL Set Value            */
#define I2C_IC_STATUS_SLV_HOLD_RX_FIFO_FULL_Get(x)                \
    (((uint32_t) (x) &I2C_IC_STATUS_SLV_HOLD_RX_FIFO_FULL_Msk) >> \
     I2C_IC_STATUS_SLV_HOLD_RX_FIFO_FULL_Pos) /*!< SLV_HOLD_RX_FIFO_FULL Get Value            */


#define I2C_IC_STATUS_SLV_HOLD_TX_FIFO_EMPTY_Pos (9U) /*!< SLV_HOLD_TX_FIFO_EMPTY Postion   9          */
#define I2C_IC_STATUS_SLV_HOLD_TX_FIFO_EMPTY_Msk \
    (0x1U << I2C_IC_STATUS_SLV_HOLD_TX_FIFO_EMPTY_Pos) /*!< SLV_HOLD_TX_FIFO_EMPTY Mask      0x00000200 */
#define I2C_IC_STATUS_SLV_HOLD_TX_FIFO_EMPTY_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_STATUS_SLV_HOLD_TX_FIFO_EMPTY_Pos) & \
     I2C_IC_STATUS_SLV_HOLD_TX_FIFO_EMPTY_Msk) /*!< SLV_HOLD_TX_FIFO_EMPTY Set Value            */
#define I2C_IC_STATUS_SLV_HOLD_TX_FIFO_EMPTY_Get(x)                \
    (((uint32_t) (x) &I2C_IC_STATUS_SLV_HOLD_TX_FIFO_EMPTY_Msk) >> \
     I2C_IC_STATUS_SLV_HOLD_TX_FIFO_EMPTY_Pos) /*!< SLV_HOLD_TX_FIFO_EMPTY Get Value            */


#define I2C_IC_STATUS_MST_HOLD_RX_FIFO_FULL_Pos (8U) /*!< MST_HOLD_RX_FIFO_FULL Postion   8          */
#define I2C_IC_STATUS_MST_HOLD_RX_FIFO_FULL_Msk \
    (0x1U << I2C_IC_STATUS_MST_HOLD_RX_FIFO_FULL_Pos) /*!< MST_HOLD_RX_FIFO_FULL Mask      0x00000100 */
#define I2C_IC_STATUS_MST_HOLD_RX_FIFO_FULL_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_STATUS_MST_HOLD_RX_FIFO_FULL_Pos) & \
     I2C_IC_STATUS_MST_HOLD_RX_FIFO_FULL_Msk) /*!< MST_HOLD_RX_FIFO_FULL Set Value            */
#define I2C_IC_STATUS_MST_HOLD_RX_FIFO_FULL_Get(x)                \
    (((uint32_t) (x) &I2C_IC_STATUS_MST_HOLD_RX_FIFO_FULL_Msk) >> \
     I2C_IC_STATUS_MST_HOLD_RX_FIFO_FULL_Pos) /*!< MST_HOLD_RX_FIFO_FULL Get Value            */


#define I2C_IC_STATUS_MST_HOLD_TX_FIFO_EMPTY_Pos (7U) /*!< MST_HOLD_TX_FIFO_EMPTY Postion   7          */
#define I2C_IC_STATUS_MST_HOLD_TX_FIFO_EMPTY_Msk \
    (0x1U << I2C_IC_STATUS_MST_HOLD_TX_FIFO_EMPTY_Pos) /*!< MST_HOLD_TX_FIFO_EMPTY Mask      0x00000080 */
#define I2C_IC_STATUS_MST_HOLD_TX_FIFO_EMPTY_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_STATUS_MST_HOLD_TX_FIFO_EMPTY_Pos) & \
     I2C_IC_STATUS_MST_HOLD_TX_FIFO_EMPTY_Msk) /*!< MST_HOLD_TX_FIFO_EMPTY Set Value            */
#define I2C_IC_STATUS_MST_HOLD_TX_FIFO_EMPTY_Get(x)                \
    (((uint32_t) (x) &I2C_IC_STATUS_MST_HOLD_TX_FIFO_EMPTY_Msk) >> \
     I2C_IC_STATUS_MST_HOLD_TX_FIFO_EMPTY_Pos) /*!< MST_HOLD_TX_FIFO_EMPTY Get Value            */


#define I2C_IC_STATUS_SLV_ACTIVITY_Pos (6U) /*!< SLV_ACTIVITY Postion   6          */
#define I2C_IC_STATUS_SLV_ACTIVITY_Msk \
    (0x1U << I2C_IC_STATUS_SLV_ACTIVITY_Pos) /*!< SLV_ACTIVITY Mask      0x00000040 */
#define I2C_IC_STATUS_SLV_ACTIVITY_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_STATUS_SLV_ACTIVITY_Pos) & \
     I2C_IC_STATUS_SLV_ACTIVITY_Msk) /*!< SLV_ACTIVITY Set Value            */
#define I2C_IC_STATUS_SLV_ACTIVITY_Get(x)                \
    (((uint32_t) (x) &I2C_IC_STATUS_SLV_ACTIVITY_Msk) >> \
     I2C_IC_STATUS_SLV_ACTIVITY_Pos) /*!< SLV_ACTIVITY Get Value            */


#define I2C_IC_STATUS_MST_ACTIVITY_Pos (5U) /*!< MST_ACTIVITY Postion   5          */
#define I2C_IC_STATUS_MST_ACTIVITY_Msk \
    (0x1U << I2C_IC_STATUS_MST_ACTIVITY_Pos) /*!< MST_ACTIVITY Mask      0x00000020 */
#define I2C_IC_STATUS_MST_ACTIVITY_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_STATUS_MST_ACTIVITY_Pos) & \
     I2C_IC_STATUS_MST_ACTIVITY_Msk) /*!< MST_ACTIVITY Set Value            */
#define I2C_IC_STATUS_MST_ACTIVITY_Get(x)                \
    (((uint32_t) (x) &I2C_IC_STATUS_MST_ACTIVITY_Msk) >> \
     I2C_IC_STATUS_MST_ACTIVITY_Pos) /*!< MST_ACTIVITY Get Value            */


#define I2C_IC_STATUS_RFF_Pos (4U)                            /*!< RFF Postion   4          */
#define I2C_IC_STATUS_RFF_Msk (0x1U << I2C_IC_STATUS_RFF_Pos) /*!< RFF Mask      0x00000010 */
#define I2C_IC_STATUS_RFF_Set(x) \
    (((uint32_t) (x) << I2C_IC_STATUS_RFF_Pos) & I2C_IC_STATUS_RFF_Msk) /*!< RFF Set Value            */
#define I2C_IC_STATUS_RFF_Get(x) \
    (((uint32_t) (x) &I2C_IC_STATUS_RFF_Msk) >> I2C_IC_STATUS_RFF_Pos) /*!< RFF Get Value            */


#define I2C_IC_STATUS_RFNE_Pos (3U)                             /*!< RFNE Postion   3          */
#define I2C_IC_STATUS_RFNE_Msk (0x1U << I2C_IC_STATUS_RFNE_Pos) /*!< RFNE Mask      0x00000008 */
#define I2C_IC_STATUS_RFNE_Set(x) \
    (((uint32_t) (x) << I2C_IC_STATUS_RFNE_Pos) & I2C_IC_STATUS_RFNE_Msk) /*!< RFNE Set Value            */
#define I2C_IC_STATUS_RFNE_Get(x) \
    (((uint32_t) (x) &I2C_IC_STATUS_RFNE_Msk) >> I2C_IC_STATUS_RFNE_Pos) /*!< RFNE Get Value            */


#define I2C_IC_STATUS_TFE_Pos (2U)                            /*!< TFE Postion   2          */
#define I2C_IC_STATUS_TFE_Msk (0x1U << I2C_IC_STATUS_TFE_Pos) /*!< TFE Mask      0x00000004 */
#define I2C_IC_STATUS_TFE_Set(x) \
    (((uint32_t) (x) << I2C_IC_STATUS_TFE_Pos) & I2C_IC_STATUS_TFE_Msk) /*!< TFE Set Value            */
#define I2C_IC_STATUS_TFE_Get(x) \
    (((uint32_t) (x) &I2C_IC_STATUS_TFE_Msk) >> I2C_IC_STATUS_TFE_Pos) /*!< TFE Get Value            */


#define I2C_IC_STATUS_TFNF_Pos (1U)                             /*!< TFNF Postion   1          */
#define I2C_IC_STATUS_TFNF_Msk (0x1U << I2C_IC_STATUS_TFNF_Pos) /*!< TFNF Mask      0x00000002 */
#define I2C_IC_STATUS_TFNF_Set(x) \
    (((uint32_t) (x) << I2C_IC_STATUS_TFNF_Pos) & I2C_IC_STATUS_TFNF_Msk) /*!< TFNF Set Value            */
#define I2C_IC_STATUS_TFNF_Get(x) \
    (((uint32_t) (x) &I2C_IC_STATUS_TFNF_Msk) >> I2C_IC_STATUS_TFNF_Pos) /*!< TFNF Get Value            */


#define I2C_IC_STATUS_ACTIVITY_Pos (0U)                                 /*!< ACTIVITY Postion   0          */
#define I2C_IC_STATUS_ACTIVITY_Msk (0x1U << I2C_IC_STATUS_ACTIVITY_Pos) /*!< ACTIVITY Mask      0x00000001 */
#define I2C_IC_STATUS_ACTIVITY_Set(x) \
    (((uint32_t) (x) << I2C_IC_STATUS_ACTIVITY_Pos) & I2C_IC_STATUS_ACTIVITY_Msk) /*!< ACTIVITY Set Value */
#define I2C_IC_STATUS_ACTIVITY_Get(x) \
    (((uint32_t) (x) &I2C_IC_STATUS_ACTIVITY_Msk) >> I2C_IC_STATUS_ACTIVITY_Pos) /*!< ACTIVITY Get Value            */


/* IC_TXFLR bitfield */
#define I2C_IC_TXFLR_TXFLR_Pos (0U)                              /*!< TXFLR Postion   0          */
#define I2C_IC_TXFLR_TXFLR_Msk (0x1fU << I2C_IC_TXFLR_TXFLR_Pos) /*!< TXFLR Mask      0x0000001F */
#define I2C_IC_TXFLR_TXFLR_Set(x) \
    (((uint32_t) (x) << I2C_IC_TXFLR_TXFLR_Pos) & I2C_IC_TXFLR_TXFLR_Msk) /*!< TXFLR Set Value            */
#define I2C_IC_TXFLR_TXFLR_Get(x) \
    (((uint32_t) (x) &I2C_IC_TXFLR_TXFLR_Msk) >> I2C_IC_TXFLR_TXFLR_Pos) /*!< TXFLR Get Value            */


/* IC_RXFLR bitfield */
#define I2C_IC_RXFLR_RXFLR_Pos (0U)                              /*!< RXFLR Postion   0          */
#define I2C_IC_RXFLR_RXFLR_Msk (0x1fU << I2C_IC_RXFLR_RXFLR_Pos) /*!< RXFLR Mask      0x0000001F */
#define I2C_IC_RXFLR_RXFLR_Set(x) \
    (((uint32_t) (x) << I2C_IC_RXFLR_RXFLR_Pos) & I2C_IC_RXFLR_RXFLR_Msk) /*!< RXFLR Set Value            */
#define I2C_IC_RXFLR_RXFLR_Get(x) \
    (((uint32_t) (x) &I2C_IC_RXFLR_RXFLR_Msk) >> I2C_IC_RXFLR_RXFLR_Pos) /*!< RXFLR Get Value            */


/* IC_SDA_HOLD bitfield */
#define I2C_IC_SDA_HOLD_IC_SDA_RX_HOLD_Pos (16U) /*!< IC_SDA_RX_HOLD Postion   16         */
#define I2C_IC_SDA_HOLD_IC_SDA_RX_HOLD_Msk \
    (0xffU << I2C_IC_SDA_HOLD_IC_SDA_RX_HOLD_Pos) /*!< IC_SDA_RX_HOLD Mask      0x00FF0000 */
#define I2C_IC_SDA_HOLD_IC_SDA_RX_HOLD_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SDA_HOLD_IC_SDA_RX_HOLD_Pos) & \
     I2C_IC_SDA_HOLD_IC_SDA_RX_HOLD_Msk) /*!< IC_SDA_RX_HOLD Set Value            */
#define I2C_IC_SDA_HOLD_IC_SDA_RX_HOLD_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SDA_HOLD_IC_SDA_RX_HOLD_Msk) >> \
     I2C_IC_SDA_HOLD_IC_SDA_RX_HOLD_Pos) /*!< IC_SDA_RX_HOLD Get Value            */


#define I2C_IC_SDA_HOLD_IC_SDA_TX_HOLD_Pos (0U) /*!< IC_SDA_TX_HOLD Postion   0          */
#define I2C_IC_SDA_HOLD_IC_SDA_TX_HOLD_Msk \
    (0xffffU << I2C_IC_SDA_HOLD_IC_SDA_TX_HOLD_Pos) /*!< IC_SDA_TX_HOLD Mask      0x0000FFFF */
#define I2C_IC_SDA_HOLD_IC_SDA_TX_HOLD_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SDA_HOLD_IC_SDA_TX_HOLD_Pos) & \
     I2C_IC_SDA_HOLD_IC_SDA_TX_HOLD_Msk) /*!< IC_SDA_TX_HOLD Set Value            */
#define I2C_IC_SDA_HOLD_IC_SDA_TX_HOLD_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SDA_HOLD_IC_SDA_TX_HOLD_Msk) >> \
     I2C_IC_SDA_HOLD_IC_SDA_TX_HOLD_Pos) /*!< IC_SDA_TX_HOLD Get Value            */


/* IC_TX_ABRT_SOURCE bitfield */
#define I2C_IC_TX_ABRT_SOURCE_TX_FLUSH_CNT_Pos (23U) /*!< TX_FLUSH_CNT Postion   23         */
#define I2C_IC_TX_ABRT_SOURCE_TX_FLUSH_CNT_Msk \
    (0x1ffU << I2C_IC_TX_ABRT_SOURCE_TX_FLUSH_CNT_Pos) /*!< TX_FLUSH_CNT Mask      0xFF800000 */
#define I2C_IC_TX_ABRT_SOURCE_TX_FLUSH_CNT_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_TX_ABRT_SOURCE_TX_FLUSH_CNT_Pos) & \
     I2C_IC_TX_ABRT_SOURCE_TX_FLUSH_CNT_Msk) /*!< TX_FLUSH_CNT Set Value            */
#define I2C_IC_TX_ABRT_SOURCE_TX_FLUSH_CNT_Get(x)                \
    (((uint32_t) (x) &I2C_IC_TX_ABRT_SOURCE_TX_FLUSH_CNT_Msk) >> \
     I2C_IC_TX_ABRT_SOURCE_TX_FLUSH_CNT_Pos) /*!< TX_FLUSH_CNT Get Value            */


#define I2C_IC_TX_ABRT_SOURCE_ABRT_DEVICE_WRITE_Pos (20U) /*!< ABRT_DEVICE_WRITE Postion   20         */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_DEVICE_WRITE_Msk \
    (0x1U << I2C_IC_TX_ABRT_SOURCE_ABRT_DEVICE_WRITE_Pos) /*!< ABRT_DEVICE_WRITE Mask      0x00100000 */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_DEVICE_WRITE_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_TX_ABRT_SOURCE_ABRT_DEVICE_WRITE_Pos) & \
     I2C_IC_TX_ABRT_SOURCE_ABRT_DEVICE_WRITE_Msk) /*!< ABRT_DEVICE_WRITE Set Value            */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_DEVICE_WRITE_Get(x)                \
    (((uint32_t) (x) &I2C_IC_TX_ABRT_SOURCE_ABRT_DEVICE_WRITE_Msk) >> \
     I2C_IC_TX_ABRT_SOURCE_ABRT_DEVICE_WRITE_Pos) /*!< ABRT_DEVICE_WRITE Get Value            */


#define I2C_IC_TX_ABRT_SOURCE_ABRT_DEVICE_SLVADDR_NOACK_Pos (19U) /*!< ABRT_DEVICE_SLVADDR_NOACK Postion   19 */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_DEVICE_SLVADDR_NOACK_Msk                                                           \
    (0x1U << I2C_IC_TX_ABRT_SOURCE_ABRT_DEVICE_SLVADDR_NOACK_Pos) /*!< ABRT_DEVICE_SLVADDR_NOACK Mask      0x00080000 \
                                                                   */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_DEVICE_SLVADDR_NOACK_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_TX_ABRT_SOURCE_ABRT_DEVICE_SLVADDR_NOACK_Pos) & \
     I2C_IC_TX_ABRT_SOURCE_ABRT_DEVICE_SLVADDR_NOACK_Msk) /*!< ABRT_DEVICE_SLVADDR_NOACK Set Value            */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_DEVICE_SLVADDR_NOACK_Get(x)                \
    (((uint32_t) (x) &I2C_IC_TX_ABRT_SOURCE_ABRT_DEVICE_SLVADDR_NOACK_Msk) >> \
     I2C_IC_TX_ABRT_SOURCE_ABRT_DEVICE_SLVADDR_NOACK_Pos) /*!< ABRT_DEVICE_SLVADDR_NOACK Get Value            */


#define I2C_IC_TX_ABRT_SOURCE_ABRT_DEVICE_NOACK_Pos (18U) /*!< ABRT_DEVICE_NOACK Postion   18         */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_DEVICE_NOACK_Msk \
    (0x1U << I2C_IC_TX_ABRT_SOURCE_ABRT_DEVICE_NOACK_Pos) /*!< ABRT_DEVICE_NOACK Mask      0x00040000 */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_DEVICE_NOACK_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_TX_ABRT_SOURCE_ABRT_DEVICE_NOACK_Pos) & \
     I2C_IC_TX_ABRT_SOURCE_ABRT_DEVICE_NOACK_Msk) /*!< ABRT_DEVICE_NOACK Set Value            */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_DEVICE_NOACK_Get(x)                \
    (((uint32_t) (x) &I2C_IC_TX_ABRT_SOURCE_ABRT_DEVICE_NOACK_Msk) >> \
     I2C_IC_TX_ABRT_SOURCE_ABRT_DEVICE_NOACK_Pos) /*!< ABRT_DEVICE_NOACK Get Value            */


#define I2C_IC_TX_ABRT_SOURCE_ABRT_SDA_STUCK_AT_LOW_Pos (17U) /*!< ABRT_SDA_STUCK_AT_LOW Postion   17         */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SDA_STUCK_AT_LOW_Msk \
    (0x1U << I2C_IC_TX_ABRT_SOURCE_ABRT_SDA_STUCK_AT_LOW_Pos) /*!< ABRT_SDA_STUCK_AT_LOW Mask      0x00020000 */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SDA_STUCK_AT_LOW_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_TX_ABRT_SOURCE_ABRT_SDA_STUCK_AT_LOW_Pos) & \
     I2C_IC_TX_ABRT_SOURCE_ABRT_SDA_STUCK_AT_LOW_Msk) /*!< ABRT_SDA_STUCK_AT_LOW Set Value            */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SDA_STUCK_AT_LOW_Get(x)                \
    (((uint32_t) (x) &I2C_IC_TX_ABRT_SOURCE_ABRT_SDA_STUCK_AT_LOW_Msk) >> \
     I2C_IC_TX_ABRT_SOURCE_ABRT_SDA_STUCK_AT_LOW_Pos) /*!< ABRT_SDA_STUCK_AT_LOW Get Value            */


#define I2C_IC_TX_ABRT_SOURCE_ABRT_USER_ABRT_Pos (16U) /*!< ABRT_USER_ABRT Postion   16         */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_USER_ABRT_Msk \
    (0x1U << I2C_IC_TX_ABRT_SOURCE_ABRT_USER_ABRT_Pos) /*!< ABRT_USER_ABRT Mask      0x00010000 */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_USER_ABRT_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_TX_ABRT_SOURCE_ABRT_USER_ABRT_Pos) & \
     I2C_IC_TX_ABRT_SOURCE_ABRT_USER_ABRT_Msk) /*!< ABRT_USER_ABRT Set Value            */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_USER_ABRT_Get(x)                \
    (((uint32_t) (x) &I2C_IC_TX_ABRT_SOURCE_ABRT_USER_ABRT_Msk) >> \
     I2C_IC_TX_ABRT_SOURCE_ABRT_USER_ABRT_Pos) /*!< ABRT_USER_ABRT Get Value            */


#define I2C_IC_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_Pos (15U) /*!< ABRT_SLVRD_INTX Postion   15         */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_Msk \
    (0x1U << I2C_IC_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_Pos) /*!< ABRT_SLVRD_INTX Mask      0x00008000 */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_Pos) & \
     I2C_IC_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_Msk) /*!< ABRT_SLVRD_INTX Set Value            */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_Get(x)                \
    (((uint32_t) (x) &I2C_IC_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_Msk) >> \
     I2C_IC_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_Pos) /*!< ABRT_SLVRD_INTX Get Value            */


#define I2C_IC_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_Pos (14U) /*!< ABRT_SLV_ARBLOST Postion   14         */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_Msk \
    (0x1U << I2C_IC_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_Pos) /*!< ABRT_SLV_ARBLOST Mask      0x00004000 */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_Pos) & \
     I2C_IC_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_Msk) /*!< ABRT_SLV_ARBLOST Set Value            */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_Get(x)                \
    (((uint32_t) (x) &I2C_IC_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_Msk) >> \
     I2C_IC_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_Pos) /*!< ABRT_SLV_ARBLOST Get Value            */


#define I2C_IC_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_Pos (13U) /*!< ABRT_SLVFLUSH_TXFIFO Postion   13         */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_Msk \
    (0x1U << I2C_IC_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_Pos) /*!< ABRT_SLVFLUSH_TXFIFO Mask      0x00002000 */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_Pos) & \
     I2C_IC_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_Msk) /*!< ABRT_SLVFLUSH_TXFIFO Set Value            */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_Get(x)                \
    (((uint32_t) (x) &I2C_IC_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_Msk) >> \
     I2C_IC_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_Pos) /*!< ABRT_SLVFLUSH_TXFIFO Get Value            */


#define I2C_IC_TX_ABRT_SOURCE_ARB_LOST_Pos (12U) /*!< ARB_LOST Postion   12         */
#define I2C_IC_TX_ABRT_SOURCE_ARB_LOST_Msk \
    (0x1U << I2C_IC_TX_ABRT_SOURCE_ARB_LOST_Pos) /*!< ARB_LOST Mask      0x00001000 */
#define I2C_IC_TX_ABRT_SOURCE_ARB_LOST_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_TX_ABRT_SOURCE_ARB_LOST_Pos) & \
     I2C_IC_TX_ABRT_SOURCE_ARB_LOST_Msk) /*!< ARB_LOST Set Value            */
#define I2C_IC_TX_ABRT_SOURCE_ARB_LOST_Get(x)                \
    (((uint32_t) (x) &I2C_IC_TX_ABRT_SOURCE_ARB_LOST_Msk) >> \
     I2C_IC_TX_ABRT_SOURCE_ARB_LOST_Pos) /*!< ARB_LOST Get Value            */


#define I2C_IC_TX_ABRT_SOURCE_ABRT_MASTER_DIS_Pos (11U) /*!< ABRT_MASTER_DIS Postion   11         */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_MASTER_DIS_Msk \
    (0x1U << I2C_IC_TX_ABRT_SOURCE_ABRT_MASTER_DIS_Pos) /*!< ABRT_MASTER_DIS Mask      0x00000800 */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_MASTER_DIS_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_TX_ABRT_SOURCE_ABRT_MASTER_DIS_Pos) & \
     I2C_IC_TX_ABRT_SOURCE_ABRT_MASTER_DIS_Msk) /*!< ABRT_MASTER_DIS Set Value            */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_MASTER_DIS_Get(x)                \
    (((uint32_t) (x) &I2C_IC_TX_ABRT_SOURCE_ABRT_MASTER_DIS_Msk) >> \
     I2C_IC_TX_ABRT_SOURCE_ABRT_MASTER_DIS_Pos) /*!< ABRT_MASTER_DIS Get Value            */


#define I2C_IC_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_Pos (10U) /*!< ABRT_10B_RD_NORSTRT Postion   10         */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_Msk \
    (0x1U << I2C_IC_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_Pos) /*!< ABRT_10B_RD_NORSTRT Mask      0x00000400 */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_Pos) & \
     I2C_IC_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_Msk) /*!< ABRT_10B_RD_NORSTRT Set Value            */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_Get(x)                \
    (((uint32_t) (x) &I2C_IC_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_Msk) >> \
     I2C_IC_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_Pos) /*!< ABRT_10B_RD_NORSTRT Get Value            */


#define I2C_IC_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_Pos (9U) /*!< ABRT_SBYTE_NORSTRT Postion   9          */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_Msk \
    (0x1U << I2C_IC_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_Pos) /*!< ABRT_SBYTE_NORSTRT Mask      0x00000200 */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_Pos) & \
     I2C_IC_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_Msk) /*!< ABRT_SBYTE_NORSTRT Set Value            */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_Get(x)                \
    (((uint32_t) (x) &I2C_IC_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_Msk) >> \
     I2C_IC_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_Pos) /*!< ABRT_SBYTE_NORSTRT Get Value            */


#define I2C_IC_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_Pos (8U) /*!< ABRT_HS_NORSTRT Postion   8          */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_Msk \
    (0x1U << I2C_IC_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_Pos) /*!< ABRT_HS_NORSTRT Mask      0x00000100 */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_Pos) & \
     I2C_IC_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_Msk) /*!< ABRT_HS_NORSTRT Set Value            */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_Get(x)                \
    (((uint32_t) (x) &I2C_IC_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_Msk) >> \
     I2C_IC_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_Pos) /*!< ABRT_HS_NORSTRT Get Value            */


#define I2C_IC_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_Pos (7U) /*!< ABRT_SBYTE_ACKDET Postion   7          */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_Msk \
    (0x1U << I2C_IC_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_Pos) /*!< ABRT_SBYTE_ACKDET Mask      0x00000080 */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_Pos) & \
     I2C_IC_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_Msk) /*!< ABRT_SBYTE_ACKDET Set Value            */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_Msk) >> \
     I2C_IC_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_Pos) /*!< ABRT_SBYTE_ACKDET Get Value            */


#define I2C_IC_TX_ABRT_SOURCE_ABRT_HS_ACKDET_Pos (6U) /*!< ABRT_HS_ACKDET Postion   6          */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_HS_ACKDET_Msk \
    (0x1U << I2C_IC_TX_ABRT_SOURCE_ABRT_HS_ACKDET_Pos) /*!< ABRT_HS_ACKDET Mask      0x00000040 */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_HS_ACKDET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_TX_ABRT_SOURCE_ABRT_HS_ACKDET_Pos) & \
     I2C_IC_TX_ABRT_SOURCE_ABRT_HS_ACKDET_Msk) /*!< ABRT_HS_ACKDET Set Value            */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_HS_ACKDET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_TX_ABRT_SOURCE_ABRT_HS_ACKDET_Msk) >> \
     I2C_IC_TX_ABRT_SOURCE_ABRT_HS_ACKDET_Pos) /*!< ABRT_HS_ACKDET Get Value            */


#define I2C_IC_TX_ABRT_SOURCE_ABRT_GCALL_READ_Pos (5U) /*!< ABRT_GCALL_READ Postion   5          */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_GCALL_READ_Msk \
    (0x1U << I2C_IC_TX_ABRT_SOURCE_ABRT_GCALL_READ_Pos) /*!< ABRT_GCALL_READ Mask      0x00000020 */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_GCALL_READ_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_TX_ABRT_SOURCE_ABRT_GCALL_READ_Pos) & \
     I2C_IC_TX_ABRT_SOURCE_ABRT_GCALL_READ_Msk) /*!< ABRT_GCALL_READ Set Value            */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_GCALL_READ_Get(x)                \
    (((uint32_t) (x) &I2C_IC_TX_ABRT_SOURCE_ABRT_GCALL_READ_Msk) >> \
     I2C_IC_TX_ABRT_SOURCE_ABRT_GCALL_READ_Pos) /*!< ABRT_GCALL_READ Get Value            */


#define I2C_IC_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_Pos (4U) /*!< ABRT_GCALL_NOACK Postion   4          */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_Msk \
    (0x1U << I2C_IC_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_Pos) /*!< ABRT_GCALL_NOACK Mask      0x00000010 */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_Pos) & \
     I2C_IC_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_Msk) /*!< ABRT_GCALL_NOACK Set Value            */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_Get(x)                \
    (((uint32_t) (x) &I2C_IC_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_Msk) >> \
     I2C_IC_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_Pos) /*!< ABRT_GCALL_NOACK Get Value            */


#define I2C_IC_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_Pos (3U) /*!< ABRT_TXDATA_NOACK Postion   3          */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_Msk \
    (0x1U << I2C_IC_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_Pos) /*!< ABRT_TXDATA_NOACK Mask      0x00000008 */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_Pos) & \
     I2C_IC_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_Msk) /*!< ABRT_TXDATA_NOACK Set Value            */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_Get(x)                \
    (((uint32_t) (x) &I2C_IC_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_Msk) >> \
     I2C_IC_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_Pos) /*!< ABRT_TXDATA_NOACK Get Value            */


#define I2C_IC_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_Pos (2U) /*!< ABRT_10ADDR2_NOACK Postion   2          */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_Msk \
    (0x1U << I2C_IC_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_Pos) /*!< ABRT_10ADDR2_NOACK Mask      0x00000004 */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_Pos) & \
     I2C_IC_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_Msk) /*!< ABRT_10ADDR2_NOACK Set Value            */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_Get(x)                \
    (((uint32_t) (x) &I2C_IC_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_Msk) >> \
     I2C_IC_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_Pos) /*!< ABRT_10ADDR2_NOACK Get Value            */


#define I2C_IC_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_Pos (1U) /*!< ABRT_10ADDR1_NOACK Postion   1          */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_Msk \
    (0x1U << I2C_IC_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_Pos) /*!< ABRT_10ADDR1_NOACK Mask      0x00000002 */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_Pos) & \
     I2C_IC_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_Msk) /*!< ABRT_10ADDR1_NOACK Set Value            */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_Get(x)                \
    (((uint32_t) (x) &I2C_IC_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_Msk) >> \
     I2C_IC_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_Pos) /*!< ABRT_10ADDR1_NOACK Get Value            */


#define I2C_IC_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_Pos (0U) /*!< ABRT_7B_ADDR_NOACK Postion   0          */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_Msk \
    (0x1U << I2C_IC_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_Pos) /*!< ABRT_7B_ADDR_NOACK Mask      0x00000001 */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_Pos) & \
     I2C_IC_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_Msk) /*!< ABRT_7B_ADDR_NOACK Set Value            */
#define I2C_IC_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_Get(x)                \
    (((uint32_t) (x) &I2C_IC_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_Msk) >> \
     I2C_IC_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_Pos) /*!< ABRT_7B_ADDR_NOACK Get Value            */


/* IC_SLV_DATA_NACK_ONLY bitfield */
#define I2C_IC_SLV_DATA_NACK_ONLY_NACK_Pos (0U) /*!< NACK Postion   0          */
#define I2C_IC_SLV_DATA_NACK_ONLY_NACK_Msk \
    (0x1U << I2C_IC_SLV_DATA_NACK_ONLY_NACK_Pos) /*!< NACK Mask      0x00000001 */
#define I2C_IC_SLV_DATA_NACK_ONLY_NACK_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SLV_DATA_NACK_ONLY_NACK_Pos) & \
     I2C_IC_SLV_DATA_NACK_ONLY_NACK_Msk) /*!< NACK Set Value            */
#define I2C_IC_SLV_DATA_NACK_ONLY_NACK_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SLV_DATA_NACK_ONLY_NACK_Msk) >> \
     I2C_IC_SLV_DATA_NACK_ONLY_NACK_Pos) /*!< NACK Get Value            */


/* IC_DMA_CR bitfield */
#define I2C_IC_DMA_CR_TDMAE_Pos (1U)                              /*!< TDMAE Postion   1          */
#define I2C_IC_DMA_CR_TDMAE_Msk (0x1U << I2C_IC_DMA_CR_TDMAE_Pos) /*!< TDMAE Mask      0x00000002 */
#define I2C_IC_DMA_CR_TDMAE_Set(x) \
    (((uint32_t) (x) << I2C_IC_DMA_CR_TDMAE_Pos) & I2C_IC_DMA_CR_TDMAE_Msk) /*!< TDMAE Set Value            */
#define I2C_IC_DMA_CR_TDMAE_Get(x) \
    (((uint32_t) (x) &I2C_IC_DMA_CR_TDMAE_Msk) >> I2C_IC_DMA_CR_TDMAE_Pos) /*!< TDMAE Get Value            */


#define I2C_IC_DMA_CR_RDMAE_Pos (0U)                              /*!< RDMAE Postion   0          */
#define I2C_IC_DMA_CR_RDMAE_Msk (0x1U << I2C_IC_DMA_CR_RDMAE_Pos) /*!< RDMAE Mask      0x00000001 */
#define I2C_IC_DMA_CR_RDMAE_Set(x) \
    (((uint32_t) (x) << I2C_IC_DMA_CR_RDMAE_Pos) & I2C_IC_DMA_CR_RDMAE_Msk) /*!< RDMAE Set Value            */
#define I2C_IC_DMA_CR_RDMAE_Get(x) \
    (((uint32_t) (x) &I2C_IC_DMA_CR_RDMAE_Msk) >> I2C_IC_DMA_CR_RDMAE_Pos) /*!< RDMAE Get Value            */


/* IC_DMA_TDLR bitfield */
#define I2C_IC_DMA_TDLR_DMATDL_Pos (0U)                                 /*!< DMATDL Postion   0          */
#define I2C_IC_DMA_TDLR_DMATDL_Msk (0xfU << I2C_IC_DMA_TDLR_DMATDL_Pos) /*!< DMATDL Mask      0x0000000F */
#define I2C_IC_DMA_TDLR_DMATDL_Set(x) \
    (((uint32_t) (x) << I2C_IC_DMA_TDLR_DMATDL_Pos) & I2C_IC_DMA_TDLR_DMATDL_Msk) /*!< DMATDL Set Value            */
#define I2C_IC_DMA_TDLR_DMATDL_Get(x) \
    (((uint32_t) (x) &I2C_IC_DMA_TDLR_DMATDL_Msk) >> I2C_IC_DMA_TDLR_DMATDL_Pos) /*!< DMATDL Get Value            */


/* IC_DMA_RDLR bitfield */
#define I2C_IC_DMA_RDLR_DMARD_Pos (0U)                                /*!< DMARD Postion   0          */
#define I2C_IC_DMA_RDLR_DMARD_Msk (0xfU << I2C_IC_DMA_RDLR_DMARD_Pos) /*!< DMARD Mask      0x0000000F */
#define I2C_IC_DMA_RDLR_DMARD_Set(x) \
    (((uint32_t) (x) << I2C_IC_DMA_RDLR_DMARD_Pos) & I2C_IC_DMA_RDLR_DMARD_Msk) /*!< DMARD Set Value            */
#define I2C_IC_DMA_RDLR_DMARD_Get(x) \
    (((uint32_t) (x) &I2C_IC_DMA_RDLR_DMARD_Msk) >> I2C_IC_DMA_RDLR_DMARD_Pos) /*!< DMARD Get Value            */


/* IC_SDA_SETUP bitfield */
#define I2C_IC_SDA_SETUP_SDA_SETUP_Pos (0U) /*!< SDA_SETUP Postion   0          */
#define I2C_IC_SDA_SETUP_SDA_SETUP_Msk                                            \
    (0xffU << I2C_IC_SDA_SETUP_SDA_SETUP_Pos) /*!< SDA_SETUP Mask      0x000000FF \
                                               */
#define I2C_IC_SDA_SETUP_SDA_SETUP_Set(x) \
    (((uint32_t) (x) << I2C_IC_SDA_SETUP_SDA_SETUP_Pos) & I2C_IC_SDA_SETUP_SDA_SETUP_Msk) /*!< SDA_SETUP Set Value */
#define I2C_IC_SDA_SETUP_SDA_SETUP_Get(x) \
    (((uint32_t) (x) &I2C_IC_SDA_SETUP_SDA_SETUP_Msk) >> I2C_IC_SDA_SETUP_SDA_SETUP_Pos) /*!< SDA_SETUP Get Value */


/* IC_ACK_GENERAL_CALL bitfield */
#define I2C_IC_ACK_GENERAL_CALL_ACK_GEN_CALL_Pos (0U) /*!< ACK_GEN_CALL Postion   0          */
#define I2C_IC_ACK_GENERAL_CALL_ACK_GEN_CALL_Msk \
    (0x1U << I2C_IC_ACK_GENERAL_CALL_ACK_GEN_CALL_Pos) /*!< ACK_GEN_CALL Mask      0x00000001 */
#define I2C_IC_ACK_GENERAL_CALL_ACK_GEN_CALL_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_ACK_GENERAL_CALL_ACK_GEN_CALL_Pos) & \
     I2C_IC_ACK_GENERAL_CALL_ACK_GEN_CALL_Msk) /*!< ACK_GEN_CALL Set Value            */
#define I2C_IC_ACK_GENERAL_CALL_ACK_GEN_CALL_Get(x)                \
    (((uint32_t) (x) &I2C_IC_ACK_GENERAL_CALL_ACK_GEN_CALL_Msk) >> \
     I2C_IC_ACK_GENERAL_CALL_ACK_GEN_CALL_Pos) /*!< ACK_GEN_CALL Get Value            */


/* IC_ENABLE_STATUS bitfield */
#define I2C_IC_ENABLE_STATUS_SLV_RX_DATA_LOST_Pos (2U) /*!< SLV_RX_DATA_LOST Postion   2          */
#define I2C_IC_ENABLE_STATUS_SLV_RX_DATA_LOST_Msk \
    (0x1U << I2C_IC_ENABLE_STATUS_SLV_RX_DATA_LOST_Pos) /*!< SLV_RX_DATA_LOST Mask      0x00000004 */
#define I2C_IC_ENABLE_STATUS_SLV_RX_DATA_LOST_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_ENABLE_STATUS_SLV_RX_DATA_LOST_Pos) & \
     I2C_IC_ENABLE_STATUS_SLV_RX_DATA_LOST_Msk) /*!< SLV_RX_DATA_LOST Set Value            */
#define I2C_IC_ENABLE_STATUS_SLV_RX_DATA_LOST_Get(x)                \
    (((uint32_t) (x) &I2C_IC_ENABLE_STATUS_SLV_RX_DATA_LOST_Msk) >> \
     I2C_IC_ENABLE_STATUS_SLV_RX_DATA_LOST_Pos) /*!< SLV_RX_DATA_LOST Get Value            */


#define I2C_IC_ENABLE_STATUS_SLV_DISABLED_WHILE_BUSY_Pos (1U) /*!< SLV_DISABLED_WHILE_BUSY Postion   1          */
#define I2C_IC_ENABLE_STATUS_SLV_DISABLED_WHILE_BUSY_Msk \
    (0x1U << I2C_IC_ENABLE_STATUS_SLV_DISABLED_WHILE_BUSY_Pos) /*!< SLV_DISABLED_WHILE_BUSY Mask      0x00000002 */
#define I2C_IC_ENABLE_STATUS_SLV_DISABLED_WHILE_BUSY_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_ENABLE_STATUS_SLV_DISABLED_WHILE_BUSY_Pos) & \
     I2C_IC_ENABLE_STATUS_SLV_DISABLED_WHILE_BUSY_Msk) /*!< SLV_DISABLED_WHILE_BUSY Set Value            */
#define I2C_IC_ENABLE_STATUS_SLV_DISABLED_WHILE_BUSY_Get(x)                \
    (((uint32_t) (x) &I2C_IC_ENABLE_STATUS_SLV_DISABLED_WHILE_BUSY_Msk) >> \
     I2C_IC_ENABLE_STATUS_SLV_DISABLED_WHILE_BUSY_Pos) /*!< SLV_DISABLED_WHILE_BUSY Get Value            */


#define I2C_IC_ENABLE_STATUS_IC_EN_Pos (0U)                                     /*!< IC_EN Postion   0          */
#define I2C_IC_ENABLE_STATUS_IC_EN_Msk (0x1U << I2C_IC_ENABLE_STATUS_IC_EN_Pos) /*!< IC_EN Mask      0x00000001 */
#define I2C_IC_ENABLE_STATUS_IC_EN_Set(x) \
    (((uint32_t) (x) << I2C_IC_ENABLE_STATUS_IC_EN_Pos) & I2C_IC_ENABLE_STATUS_IC_EN_Msk) /*!< IC_EN Set Value */
#define I2C_IC_ENABLE_STATUS_IC_EN_Get(x) \
    (((uint32_t) (x) &I2C_IC_ENABLE_STATUS_IC_EN_Msk) >> I2C_IC_ENABLE_STATUS_IC_EN_Pos) /*!< IC_EN Get Value */


/* IC_FS_SPKLEN bitfield */
#define I2C_IC_FS_SPKLEN_IC_FS_SPKLEN_Pos (0U) /*!< IC_FS_SPKLEN Postion   0          */
#define I2C_IC_FS_SPKLEN_IC_FS_SPKLEN_Msk \
    (0xffU << I2C_IC_FS_SPKLEN_IC_FS_SPKLEN_Pos) /*!< IC_FS_SPKLEN Mask      0x000000FF */
#define I2C_IC_FS_SPKLEN_IC_FS_SPKLEN_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_FS_SPKLEN_IC_FS_SPKLEN_Pos) & \
     I2C_IC_FS_SPKLEN_IC_FS_SPKLEN_Msk) /*!< IC_FS_SPKLEN Set Value            */
#define I2C_IC_FS_SPKLEN_IC_FS_SPKLEN_Get(x)                \
    (((uint32_t) (x) &I2C_IC_FS_SPKLEN_IC_FS_SPKLEN_Msk) >> \
     I2C_IC_FS_SPKLEN_IC_FS_SPKLEN_Pos) /*!< IC_FS_SPKLEN Get Value            */


/* IC_UFM_SPKLEN bitfield */
#define I2C_IC_UFM_SPKLEN_IC_UFM_SPKLEN_Pos (0U) /*!< IC_UFM_SPKLEN Postion   0          */
#define I2C_IC_UFM_SPKLEN_IC_UFM_SPKLEN_Msk \
    (0xffU << I2C_IC_UFM_SPKLEN_IC_UFM_SPKLEN_Pos) /*!< IC_UFM_SPKLEN Mask      0x000000FF */
#define I2C_IC_UFM_SPKLEN_IC_UFM_SPKLEN_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_UFM_SPKLEN_IC_UFM_SPKLEN_Pos) & \
     I2C_IC_UFM_SPKLEN_IC_UFM_SPKLEN_Msk) /*!< IC_UFM_SPKLEN Set Value            */
#define I2C_IC_UFM_SPKLEN_IC_UFM_SPKLEN_Get(x)                \
    (((uint32_t) (x) &I2C_IC_UFM_SPKLEN_IC_UFM_SPKLEN_Msk) >> \
     I2C_IC_UFM_SPKLEN_IC_UFM_SPKLEN_Pos) /*!< IC_UFM_SPKLEN Get Value            */


/* IC_HS_SPKLEN bitfield */
#define I2C_IC_HS_SPKLEN_IC_HS_SPKLEN_Pos (0U) /*!< IC_HS_SPKLEN Postion   0          */
#define I2C_IC_HS_SPKLEN_IC_HS_SPKLEN_Msk \
    (0xffU << I2C_IC_HS_SPKLEN_IC_HS_SPKLEN_Pos) /*!< IC_HS_SPKLEN Mask      0x000000FF */
#define I2C_IC_HS_SPKLEN_IC_HS_SPKLEN_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_HS_SPKLEN_IC_HS_SPKLEN_Pos) & \
     I2C_IC_HS_SPKLEN_IC_HS_SPKLEN_Msk) /*!< IC_HS_SPKLEN Set Value            */
#define I2C_IC_HS_SPKLEN_IC_HS_SPKLEN_Get(x)                \
    (((uint32_t) (x) &I2C_IC_HS_SPKLEN_IC_HS_SPKLEN_Msk) >> \
     I2C_IC_HS_SPKLEN_IC_HS_SPKLEN_Pos) /*!< IC_HS_SPKLEN Get Value            */


/* IC_CLR_RESTART_DET bitfield */
#define I2C_IC_CLR_RESTART_DET_CLR_RESTART_DET_Pos (0U) /*!< CLR_RESTART_DET Postion   0          */
#define I2C_IC_CLR_RESTART_DET_CLR_RESTART_DET_Msk \
    (0x1U << I2C_IC_CLR_RESTART_DET_CLR_RESTART_DET_Pos) /*!< CLR_RESTART_DET Mask      0x00000001 */
#define I2C_IC_CLR_RESTART_DET_CLR_RESTART_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_CLR_RESTART_DET_CLR_RESTART_DET_Pos) & \
     I2C_IC_CLR_RESTART_DET_CLR_RESTART_DET_Msk) /*!< CLR_RESTART_DET Set Value            */
#define I2C_IC_CLR_RESTART_DET_CLR_RESTART_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_CLR_RESTART_DET_CLR_RESTART_DET_Msk) >> \
     I2C_IC_CLR_RESTART_DET_CLR_RESTART_DET_Pos) /*!< CLR_RESTART_DET Get Value            */


/* IC_SCL_STUCK_AT_LOW_TIMEOUT bitfield */
#define I2C_IC_SCL_STUCK_AT_LOW_TIMEOUT_IC_SCL_STUCK_LOW_TIMEOUT_Pos \
    (0U) /*!< IC_SCL_STUCK_LOW_TIMEOUT Postion   0          */
#define I2C_IC_SCL_STUCK_AT_LOW_TIMEOUT_IC_SCL_STUCK_LOW_TIMEOUT_Msk \
    (0xffffffffU                                                     \
     << I2C_IC_SCL_STUCK_AT_LOW_TIMEOUT_IC_SCL_STUCK_LOW_TIMEOUT_Pos) /*!< IC_SCL_STUCK_LOW_TIMEOUT Mask 0xFFFFFFFF */
#define I2C_IC_SCL_STUCK_AT_LOW_TIMEOUT_IC_SCL_STUCK_LOW_TIMEOUT_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SCL_STUCK_AT_LOW_TIMEOUT_IC_SCL_STUCK_LOW_TIMEOUT_Pos) & \
     I2C_IC_SCL_STUCK_AT_LOW_TIMEOUT_IC_SCL_STUCK_LOW_TIMEOUT_Msk) /*!< IC_SCL_STUCK_LOW_TIMEOUT Set Value */
#define I2C_IC_SCL_STUCK_AT_LOW_TIMEOUT_IC_SCL_STUCK_LOW_TIMEOUT_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SCL_STUCK_AT_LOW_TIMEOUT_IC_SCL_STUCK_LOW_TIMEOUT_Msk) >> \
     I2C_IC_SCL_STUCK_AT_LOW_TIMEOUT_IC_SCL_STUCK_LOW_TIMEOUT_Pos) /*!< IC_SCL_STUCK_LOW_TIMEOUT Get Value */


/* IC_SDA_STUCK_AT_LOW_TIMEOUT bitfield */
#define I2C_IC_SDA_STUCK_AT_LOW_TIMEOUT_IC_SDA_STUCK_LOW_TIMEOUT_Pos \
    (0U) /*!< IC_SDA_STUCK_LOW_TIMEOUT Postion   0          */
#define I2C_IC_SDA_STUCK_AT_LOW_TIMEOUT_IC_SDA_STUCK_LOW_TIMEOUT_Msk \
    (0xffffffffU                                                     \
     << I2C_IC_SDA_STUCK_AT_LOW_TIMEOUT_IC_SDA_STUCK_LOW_TIMEOUT_Pos) /*!< IC_SDA_STUCK_LOW_TIMEOUT Mask 0xFFFFFFFF */
#define I2C_IC_SDA_STUCK_AT_LOW_TIMEOUT_IC_SDA_STUCK_LOW_TIMEOUT_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SDA_STUCK_AT_LOW_TIMEOUT_IC_SDA_STUCK_LOW_TIMEOUT_Pos) & \
     I2C_IC_SDA_STUCK_AT_LOW_TIMEOUT_IC_SDA_STUCK_LOW_TIMEOUT_Msk) /*!< IC_SDA_STUCK_LOW_TIMEOUT Set Value */
#define I2C_IC_SDA_STUCK_AT_LOW_TIMEOUT_IC_SDA_STUCK_LOW_TIMEOUT_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SDA_STUCK_AT_LOW_TIMEOUT_IC_SDA_STUCK_LOW_TIMEOUT_Msk) >> \
     I2C_IC_SDA_STUCK_AT_LOW_TIMEOUT_IC_SDA_STUCK_LOW_TIMEOUT_Pos) /*!< IC_SDA_STUCK_LOW_TIMEOUT Get Value */


/* IC_CLR_SCL_STUCK_DET bitfield */
#define I2C_IC_CLR_SCL_STUCK_DET_CLR_SCL_STUCK_DET_Pos (0U) /*!< CLR_SCL_STUCK_DET Postion   0          */
#define I2C_IC_CLR_SCL_STUCK_DET_CLR_SCL_STUCK_DET_Msk \
    (0x1U << I2C_IC_CLR_SCL_STUCK_DET_CLR_SCL_STUCK_DET_Pos) /*!< CLR_SCL_STUCK_DET Mask      0x00000001 */
#define I2C_IC_CLR_SCL_STUCK_DET_CLR_SCL_STUCK_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_CLR_SCL_STUCK_DET_CLR_SCL_STUCK_DET_Pos) & \
     I2C_IC_CLR_SCL_STUCK_DET_CLR_SCL_STUCK_DET_Msk) /*!< CLR_SCL_STUCK_DET Set Value            */
#define I2C_IC_CLR_SCL_STUCK_DET_CLR_SCL_STUCK_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_CLR_SCL_STUCK_DET_CLR_SCL_STUCK_DET_Msk) >> \
     I2C_IC_CLR_SCL_STUCK_DET_CLR_SCL_STUCK_DET_Pos) /*!< CLR_SCL_STUCK_DET Get Value            */


/* IC_DEVICE_ID bitfield */
#define I2C_IC_DEVICE_ID_DEVICE_ID_Pos (0U) /*!< DEVICE_ID Postion   0          */
#define I2C_IC_DEVICE_ID_DEVICE_ID_Msk \
    (0xffffffU << I2C_IC_DEVICE_ID_DEVICE_ID_Pos) /*!< DEVICE_ID Mask      0x00FFFFFF */
#define I2C_IC_DEVICE_ID_DEVICE_ID_Set(x) \
    (((uint32_t) (x) << I2C_IC_DEVICE_ID_DEVICE_ID_Pos) & I2C_IC_DEVICE_ID_DEVICE_ID_Msk) /*!< DEVICE_ID Set Value */
#define I2C_IC_DEVICE_ID_DEVICE_ID_Get(x) \
    (((uint32_t) (x) &I2C_IC_DEVICE_ID_DEVICE_ID_Msk) >> I2C_IC_DEVICE_ID_DEVICE_ID_Pos) /*!< DEVICE_ID Get Value */


/* IC_SMBUS_CLK_LOW_SEXT bitfield */
#define I2C_IC_SMBUS_CLK_LOW_SEXT_SMBUS_CLK_LOW_SEXT_TIMEOUT_Pos \
    (0U) /*!< SMBUS_CLK_LOW_SEXT_TIMEOUT Postion   0          */
#define I2C_IC_SMBUS_CLK_LOW_SEXT_SMBUS_CLK_LOW_SEXT_TIMEOUT_Msk                                                   \
    (0xffffffffU << I2C_IC_SMBUS_CLK_LOW_SEXT_SMBUS_CLK_LOW_SEXT_TIMEOUT_Pos) /*!< SMBUS_CLK_LOW_SEXT_TIMEOUT Mask \
                                                                                 0xFFFFFFFF */
#define I2C_IC_SMBUS_CLK_LOW_SEXT_SMBUS_CLK_LOW_SEXT_TIMEOUT_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_CLK_LOW_SEXT_SMBUS_CLK_LOW_SEXT_TIMEOUT_Pos) & \
     I2C_IC_SMBUS_CLK_LOW_SEXT_SMBUS_CLK_LOW_SEXT_TIMEOUT_Msk) /*!< SMBUS_CLK_LOW_SEXT_TIMEOUT Set Value            */
#define I2C_IC_SMBUS_CLK_LOW_SEXT_SMBUS_CLK_LOW_SEXT_TIMEOUT_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_CLK_LOW_SEXT_SMBUS_CLK_LOW_SEXT_TIMEOUT_Msk) >> \
     I2C_IC_SMBUS_CLK_LOW_SEXT_SMBUS_CLK_LOW_SEXT_TIMEOUT_Pos) /*!< SMBUS_CLK_LOW_SEXT_TIMEOUT Get Value            */


/* IC_SMBUS_CLK_LOW_MEXT bitfield */
#define I2C_IC_SMBUS_CLK_LOW_MEXT_SMBUS_CLK_LOW_MEXT_TIMEOUT_Pos \
    (0U) /*!< SMBUS_CLK_LOW_MEXT_TIMEOUT Postion   0          */
#define I2C_IC_SMBUS_CLK_LOW_MEXT_SMBUS_CLK_LOW_MEXT_TIMEOUT_Msk                                                   \
    (0xffffffffU << I2C_IC_SMBUS_CLK_LOW_MEXT_SMBUS_CLK_LOW_MEXT_TIMEOUT_Pos) /*!< SMBUS_CLK_LOW_MEXT_TIMEOUT Mask \
                                                                                 0xFFFFFFFF */
#define I2C_IC_SMBUS_CLK_LOW_MEXT_SMBUS_CLK_LOW_MEXT_TIMEOUT_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_CLK_LOW_MEXT_SMBUS_CLK_LOW_MEXT_TIMEOUT_Pos) & \
     I2C_IC_SMBUS_CLK_LOW_MEXT_SMBUS_CLK_LOW_MEXT_TIMEOUT_Msk) /*!< SMBUS_CLK_LOW_MEXT_TIMEOUT Set Value            */
#define I2C_IC_SMBUS_CLK_LOW_MEXT_SMBUS_CLK_LOW_MEXT_TIMEOUT_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_CLK_LOW_MEXT_SMBUS_CLK_LOW_MEXT_TIMEOUT_Msk) >> \
     I2C_IC_SMBUS_CLK_LOW_MEXT_SMBUS_CLK_LOW_MEXT_TIMEOUT_Pos) /*!< SMBUS_CLK_LOW_MEXT_TIMEOUT Get Value            */


/* IC_SMBUS_THIGH_MAX_IDLE_COUNT bitfield */
#define I2C_IC_SMBUS_THIGH_MAX_IDLE_COUNT_SMBUS_THIGH_MAX_BUS_IDLE_CNT_Pos \
    (0U) /*!< SMBUS_THIGH_MAX_BUS_IDLE_CNT Postion   0          */
#define I2C_IC_SMBUS_THIGH_MAX_IDLE_COUNT_SMBUS_THIGH_MAX_BUS_IDLE_CNT_Msk                                            \
    (0xffffU << I2C_IC_SMBUS_THIGH_MAX_IDLE_COUNT_SMBUS_THIGH_MAX_BUS_IDLE_CNT_Pos) /*!< SMBUS_THIGH_MAX_BUS_IDLE_CNT \
                                                                                       Mask      0x0000FFFF */
#define I2C_IC_SMBUS_THIGH_MAX_IDLE_COUNT_SMBUS_THIGH_MAX_BUS_IDLE_CNT_Set(x)                                        \
    (((uint32_t) (x) << I2C_IC_SMBUS_THIGH_MAX_IDLE_COUNT_SMBUS_THIGH_MAX_BUS_IDLE_CNT_Pos) &                        \
     I2C_IC_SMBUS_THIGH_MAX_IDLE_COUNT_SMBUS_THIGH_MAX_BUS_IDLE_CNT_Msk) /*!< SMBUS_THIGH_MAX_BUS_IDLE_CNT Set Value \
                                                                          */
#define I2C_IC_SMBUS_THIGH_MAX_IDLE_COUNT_SMBUS_THIGH_MAX_BUS_IDLE_CNT_Get(x)                                        \
    (((uint32_t) (x) &I2C_IC_SMBUS_THIGH_MAX_IDLE_COUNT_SMBUS_THIGH_MAX_BUS_IDLE_CNT_Msk) >>                         \
     I2C_IC_SMBUS_THIGH_MAX_IDLE_COUNT_SMBUS_THIGH_MAX_BUS_IDLE_CNT_Pos) /*!< SMBUS_THIGH_MAX_BUS_IDLE_CNT Get Value \
                                                                          */


/* IC_SMBUS_INTR_STAT bitfield */
#define I2C_IC_SMBUS_INTR_STAT_R_SMBUS_ALERT_DET_Pos (10U) /*!< R_SMBUS_ALERT_DET Postion   10         */
#define I2C_IC_SMBUS_INTR_STAT_R_SMBUS_ALERT_DET_Msk \
    (0x1U << I2C_IC_SMBUS_INTR_STAT_R_SMBUS_ALERT_DET_Pos) /*!< R_SMBUS_ALERT_DET Mask      0x00000400 */
#define I2C_IC_SMBUS_INTR_STAT_R_SMBUS_ALERT_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_INTR_STAT_R_SMBUS_ALERT_DET_Pos) & \
     I2C_IC_SMBUS_INTR_STAT_R_SMBUS_ALERT_DET_Msk) /*!< R_SMBUS_ALERT_DET Set Value            */
#define I2C_IC_SMBUS_INTR_STAT_R_SMBUS_ALERT_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_INTR_STAT_R_SMBUS_ALERT_DET_Msk) >> \
     I2C_IC_SMBUS_INTR_STAT_R_SMBUS_ALERT_DET_Pos) /*!< R_SMBUS_ALERT_DET Get Value            */


#define I2C_IC_SMBUS_INTR_STAT_R_SMBUS_SUSPEND_DET_Pos (9U) /*!< R_SMBUS_SUSPEND_DET Postion   9          */
#define I2C_IC_SMBUS_INTR_STAT_R_SMBUS_SUSPEND_DET_Msk \
    (0x1U << I2C_IC_SMBUS_INTR_STAT_R_SMBUS_SUSPEND_DET_Pos) /*!< R_SMBUS_SUSPEND_DET Mask      0x00000200 */
#define I2C_IC_SMBUS_INTR_STAT_R_SMBUS_SUSPEND_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_INTR_STAT_R_SMBUS_SUSPEND_DET_Pos) & \
     I2C_IC_SMBUS_INTR_STAT_R_SMBUS_SUSPEND_DET_Msk) /*!< R_SMBUS_SUSPEND_DET Set Value            */
#define I2C_IC_SMBUS_INTR_STAT_R_SMBUS_SUSPEND_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_INTR_STAT_R_SMBUS_SUSPEND_DET_Msk) >> \
     I2C_IC_SMBUS_INTR_STAT_R_SMBUS_SUSPEND_DET_Pos) /*!< R_SMBUS_SUSPEND_DET Get Value            */


#define I2C_IC_SMBUS_INTR_STAT_R_SLV_RX_PEC_NACK_Pos (8U) /*!< R_SLV_RX_PEC_NACK Postion   8          */
#define I2C_IC_SMBUS_INTR_STAT_R_SLV_RX_PEC_NACK_Msk \
    (0x1U << I2C_IC_SMBUS_INTR_STAT_R_SLV_RX_PEC_NACK_Pos) /*!< R_SLV_RX_PEC_NACK Mask      0x00000100 */
#define I2C_IC_SMBUS_INTR_STAT_R_SLV_RX_PEC_NACK_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_INTR_STAT_R_SLV_RX_PEC_NACK_Pos) & \
     I2C_IC_SMBUS_INTR_STAT_R_SLV_RX_PEC_NACK_Msk) /*!< R_SLV_RX_PEC_NACK Set Value            */
#define I2C_IC_SMBUS_INTR_STAT_R_SLV_RX_PEC_NACK_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_INTR_STAT_R_SLV_RX_PEC_NACK_Msk) >> \
     I2C_IC_SMBUS_INTR_STAT_R_SLV_RX_PEC_NACK_Pos) /*!< R_SLV_RX_PEC_NACK Get Value            */


#define I2C_IC_SMBUS_INTR_STAT_R_ARP_ASSGN_ADDR_CMD_DET_Pos (7U) /*!< R_ARP_ASSGN_ADDR_CMD_DET Postion   7          */
#define I2C_IC_SMBUS_INTR_STAT_R_ARP_ASSGN_ADDR_CMD_DET_Msk                                                          \
    (0x1U << I2C_IC_SMBUS_INTR_STAT_R_ARP_ASSGN_ADDR_CMD_DET_Pos) /*!< R_ARP_ASSGN_ADDR_CMD_DET Mask      0x00000080 \
                                                                   */
#define I2C_IC_SMBUS_INTR_STAT_R_ARP_ASSGN_ADDR_CMD_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_INTR_STAT_R_ARP_ASSGN_ADDR_CMD_DET_Pos) & \
     I2C_IC_SMBUS_INTR_STAT_R_ARP_ASSGN_ADDR_CMD_DET_Msk) /*!< R_ARP_ASSGN_ADDR_CMD_DET Set Value            */
#define I2C_IC_SMBUS_INTR_STAT_R_ARP_ASSGN_ADDR_CMD_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_INTR_STAT_R_ARP_ASSGN_ADDR_CMD_DET_Msk) >> \
     I2C_IC_SMBUS_INTR_STAT_R_ARP_ASSGN_ADDR_CMD_DET_Pos) /*!< R_ARP_ASSGN_ADDR_CMD_DET Get Value            */


#define I2C_IC_SMBUS_INTR_STAT_R_ARP_GET_UDID_CMD_DET_Pos (6U) /*!< R_ARP_GET_UDID_CMD_DET Postion   6          */
#define I2C_IC_SMBUS_INTR_STAT_R_ARP_GET_UDID_CMD_DET_Msk \
    (0x1U << I2C_IC_SMBUS_INTR_STAT_R_ARP_GET_UDID_CMD_DET_Pos) /*!< R_ARP_GET_UDID_CMD_DET Mask      0x00000040 */
#define I2C_IC_SMBUS_INTR_STAT_R_ARP_GET_UDID_CMD_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_INTR_STAT_R_ARP_GET_UDID_CMD_DET_Pos) & \
     I2C_IC_SMBUS_INTR_STAT_R_ARP_GET_UDID_CMD_DET_Msk) /*!< R_ARP_GET_UDID_CMD_DET Set Value            */
#define I2C_IC_SMBUS_INTR_STAT_R_ARP_GET_UDID_CMD_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_INTR_STAT_R_ARP_GET_UDID_CMD_DET_Msk) >> \
     I2C_IC_SMBUS_INTR_STAT_R_ARP_GET_UDID_CMD_DET_Pos) /*!< R_ARP_GET_UDID_CMD_DET Get Value            */


#define I2C_IC_SMBUS_INTR_STAT_R_ARP_RST_CMD_DET_Pos (5U) /*!< R_ARP_RST_CMD_DET Postion   5          */
#define I2C_IC_SMBUS_INTR_STAT_R_ARP_RST_CMD_DET_Msk \
    (0x1U << I2C_IC_SMBUS_INTR_STAT_R_ARP_RST_CMD_DET_Pos) /*!< R_ARP_RST_CMD_DET Mask      0x00000020 */
#define I2C_IC_SMBUS_INTR_STAT_R_ARP_RST_CMD_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_INTR_STAT_R_ARP_RST_CMD_DET_Pos) & \
     I2C_IC_SMBUS_INTR_STAT_R_ARP_RST_CMD_DET_Msk) /*!< R_ARP_RST_CMD_DET Set Value            */
#define I2C_IC_SMBUS_INTR_STAT_R_ARP_RST_CMD_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_INTR_STAT_R_ARP_RST_CMD_DET_Msk) >> \
     I2C_IC_SMBUS_INTR_STAT_R_ARP_RST_CMD_DET_Pos) /*!< R_ARP_RST_CMD_DET Get Value            */


#define I2C_IC_SMBUS_INTR_STAT_R_ARP_PREPARE_CMD_DET_Pos (4U) /*!< R_ARP_PREPARE_CMD_DET Postion   4          */
#define I2C_IC_SMBUS_INTR_STAT_R_ARP_PREPARE_CMD_DET_Msk \
    (0x1U << I2C_IC_SMBUS_INTR_STAT_R_ARP_PREPARE_CMD_DET_Pos) /*!< R_ARP_PREPARE_CMD_DET Mask      0x00000010 */
#define I2C_IC_SMBUS_INTR_STAT_R_ARP_PREPARE_CMD_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_INTR_STAT_R_ARP_PREPARE_CMD_DET_Pos) & \
     I2C_IC_SMBUS_INTR_STAT_R_ARP_PREPARE_CMD_DET_Msk) /*!< R_ARP_PREPARE_CMD_DET Set Value            */
#define I2C_IC_SMBUS_INTR_STAT_R_ARP_PREPARE_CMD_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_INTR_STAT_R_ARP_PREPARE_CMD_DET_Msk) >> \
     I2C_IC_SMBUS_INTR_STAT_R_ARP_PREPARE_CMD_DET_Pos) /*!< R_ARP_PREPARE_CMD_DET Get Value            */


#define I2C_IC_SMBUS_INTR_STAT_R_HOST_NOTIFY_MST_DET_Pos (3U) /*!< R_HOST_NOTIFY_MST_DET Postion   3          */
#define I2C_IC_SMBUS_INTR_STAT_R_HOST_NOTIFY_MST_DET_Msk \
    (0x1U << I2C_IC_SMBUS_INTR_STAT_R_HOST_NOTIFY_MST_DET_Pos) /*!< R_HOST_NOTIFY_MST_DET Mask      0x00000008 */
#define I2C_IC_SMBUS_INTR_STAT_R_HOST_NOTIFY_MST_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_INTR_STAT_R_HOST_NOTIFY_MST_DET_Pos) & \
     I2C_IC_SMBUS_INTR_STAT_R_HOST_NOTIFY_MST_DET_Msk) /*!< R_HOST_NOTIFY_MST_DET Set Value            */
#define I2C_IC_SMBUS_INTR_STAT_R_HOST_NOTIFY_MST_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_INTR_STAT_R_HOST_NOTIFY_MST_DET_Msk) >> \
     I2C_IC_SMBUS_INTR_STAT_R_HOST_NOTIFY_MST_DET_Pos) /*!< R_HOST_NOTIFY_MST_DET Get Value            */


#define I2C_IC_SMBUS_INTR_STAT_R_QUICK_CMD_DET_Pos (2U) /*!< R_QUICK_CMD_DET Postion   2          */
#define I2C_IC_SMBUS_INTR_STAT_R_QUICK_CMD_DET_Msk \
    (0x1U << I2C_IC_SMBUS_INTR_STAT_R_QUICK_CMD_DET_Pos) /*!< R_QUICK_CMD_DET Mask      0x00000004 */
#define I2C_IC_SMBUS_INTR_STAT_R_QUICK_CMD_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_INTR_STAT_R_QUICK_CMD_DET_Pos) & \
     I2C_IC_SMBUS_INTR_STAT_R_QUICK_CMD_DET_Msk) /*!< R_QUICK_CMD_DET Set Value            */
#define I2C_IC_SMBUS_INTR_STAT_R_QUICK_CMD_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_INTR_STAT_R_QUICK_CMD_DET_Msk) >> \
     I2C_IC_SMBUS_INTR_STAT_R_QUICK_CMD_DET_Pos) /*!< R_QUICK_CMD_DET Get Value            */


#define I2C_IC_SMBUS_INTR_STAT_R_MST_CLOCK_EXTND_TIMEOUT_Pos (1U) /*!< R_MST_CLOCK_EXTND_TIMEOUT Postion   1 */
#define I2C_IC_SMBUS_INTR_STAT_R_MST_CLOCK_EXTND_TIMEOUT_Msk \
    (0x1U                                                    \
     << I2C_IC_SMBUS_INTR_STAT_R_MST_CLOCK_EXTND_TIMEOUT_Pos) /*!< R_MST_CLOCK_EXTND_TIMEOUT Mask      0x00000002 */
#define I2C_IC_SMBUS_INTR_STAT_R_MST_CLOCK_EXTND_TIMEOUT_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_INTR_STAT_R_MST_CLOCK_EXTND_TIMEOUT_Pos) & \
     I2C_IC_SMBUS_INTR_STAT_R_MST_CLOCK_EXTND_TIMEOUT_Msk) /*!< R_MST_CLOCK_EXTND_TIMEOUT Set Value            */
#define I2C_IC_SMBUS_INTR_STAT_R_MST_CLOCK_EXTND_TIMEOUT_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_INTR_STAT_R_MST_CLOCK_EXTND_TIMEOUT_Msk) >> \
     I2C_IC_SMBUS_INTR_STAT_R_MST_CLOCK_EXTND_TIMEOUT_Pos) /*!< R_MST_CLOCK_EXTND_TIMEOUT Get Value            */


#define I2C_IC_SMBUS_INTR_STAT_R_SLV_CLOCK_EXTND_TIMEOUT_Pos (0U) /*!< R_SLV_CLOCK_EXTND_TIMEOUT Postion   0 */
#define I2C_IC_SMBUS_INTR_STAT_R_SLV_CLOCK_EXTND_TIMEOUT_Msk \
    (0x1U                                                    \
     << I2C_IC_SMBUS_INTR_STAT_R_SLV_CLOCK_EXTND_TIMEOUT_Pos) /*!< R_SLV_CLOCK_EXTND_TIMEOUT Mask      0x00000001 */
#define I2C_IC_SMBUS_INTR_STAT_R_SLV_CLOCK_EXTND_TIMEOUT_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_INTR_STAT_R_SLV_CLOCK_EXTND_TIMEOUT_Pos) & \
     I2C_IC_SMBUS_INTR_STAT_R_SLV_CLOCK_EXTND_TIMEOUT_Msk) /*!< R_SLV_CLOCK_EXTND_TIMEOUT Set Value            */
#define I2C_IC_SMBUS_INTR_STAT_R_SLV_CLOCK_EXTND_TIMEOUT_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_INTR_STAT_R_SLV_CLOCK_EXTND_TIMEOUT_Msk) >> \
     I2C_IC_SMBUS_INTR_STAT_R_SLV_CLOCK_EXTND_TIMEOUT_Pos) /*!< R_SLV_CLOCK_EXTND_TIMEOUT Get Value            */


/* IC_SMBUS_INTR_MASK bitfield */
#define I2C_IC_SMBUS_INTR_MASK_M_SMBUS_ALERT_DET_Pos (10U) /*!< M_SMBUS_ALERT_DET Postion   10         */
#define I2C_IC_SMBUS_INTR_MASK_M_SMBUS_ALERT_DET_Msk \
    (0x1U << I2C_IC_SMBUS_INTR_MASK_M_SMBUS_ALERT_DET_Pos) /*!< M_SMBUS_ALERT_DET Mask      0x00000400 */
#define I2C_IC_SMBUS_INTR_MASK_M_SMBUS_ALERT_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_INTR_MASK_M_SMBUS_ALERT_DET_Pos) & \
     I2C_IC_SMBUS_INTR_MASK_M_SMBUS_ALERT_DET_Msk) /*!< M_SMBUS_ALERT_DET Set Value            */
#define I2C_IC_SMBUS_INTR_MASK_M_SMBUS_ALERT_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_INTR_MASK_M_SMBUS_ALERT_DET_Msk) >> \
     I2C_IC_SMBUS_INTR_MASK_M_SMBUS_ALERT_DET_Pos) /*!< M_SMBUS_ALERT_DET Get Value            */


#define I2C_IC_SMBUS_INTR_MASK_R_SMBUS_SUSPEND_DET_Pos (9U) /*!< R_SMBUS_SUSPEND_DET Postion   9          */
#define I2C_IC_SMBUS_INTR_MASK_R_SMBUS_SUSPEND_DET_Msk \
    (0x1U << I2C_IC_SMBUS_INTR_MASK_R_SMBUS_SUSPEND_DET_Pos) /*!< R_SMBUS_SUSPEND_DET Mask      0x00000200 */
#define I2C_IC_SMBUS_INTR_MASK_R_SMBUS_SUSPEND_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_INTR_MASK_R_SMBUS_SUSPEND_DET_Pos) & \
     I2C_IC_SMBUS_INTR_MASK_R_SMBUS_SUSPEND_DET_Msk) /*!< R_SMBUS_SUSPEND_DET Set Value            */
#define I2C_IC_SMBUS_INTR_MASK_R_SMBUS_SUSPEND_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_INTR_MASK_R_SMBUS_SUSPEND_DET_Msk) >> \
     I2C_IC_SMBUS_INTR_MASK_R_SMBUS_SUSPEND_DET_Pos) /*!< R_SMBUS_SUSPEND_DET Get Value            */


#define I2C_IC_SMBUS_INTR_MASK_M_SLV_RX_PEC_NACK_Pos (8U) /*!< M_SLV_RX_PEC_NACK Postion   8          */
#define I2C_IC_SMBUS_INTR_MASK_M_SLV_RX_PEC_NACK_Msk \
    (0x1U << I2C_IC_SMBUS_INTR_MASK_M_SLV_RX_PEC_NACK_Pos) /*!< M_SLV_RX_PEC_NACK Mask      0x00000100 */
#define I2C_IC_SMBUS_INTR_MASK_M_SLV_RX_PEC_NACK_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_INTR_MASK_M_SLV_RX_PEC_NACK_Pos) & \
     I2C_IC_SMBUS_INTR_MASK_M_SLV_RX_PEC_NACK_Msk) /*!< M_SLV_RX_PEC_NACK Set Value            */
#define I2C_IC_SMBUS_INTR_MASK_M_SLV_RX_PEC_NACK_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_INTR_MASK_M_SLV_RX_PEC_NACK_Msk) >> \
     I2C_IC_SMBUS_INTR_MASK_M_SLV_RX_PEC_NACK_Pos) /*!< M_SLV_RX_PEC_NACK Get Value            */


#define I2C_IC_SMBUS_INTR_MASK_M_ARP_ASSGN_ADDR_CMD_DET_Pos (7U) /*!< M_ARP_ASSGN_ADDR_CMD_DET Postion   7          */
#define I2C_IC_SMBUS_INTR_MASK_M_ARP_ASSGN_ADDR_CMD_DET_Msk                                                          \
    (0x1U << I2C_IC_SMBUS_INTR_MASK_M_ARP_ASSGN_ADDR_CMD_DET_Pos) /*!< M_ARP_ASSGN_ADDR_CMD_DET Mask      0x00000080 \
                                                                   */
#define I2C_IC_SMBUS_INTR_MASK_M_ARP_ASSGN_ADDR_CMD_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_INTR_MASK_M_ARP_ASSGN_ADDR_CMD_DET_Pos) & \
     I2C_IC_SMBUS_INTR_MASK_M_ARP_ASSGN_ADDR_CMD_DET_Msk) /*!< M_ARP_ASSGN_ADDR_CMD_DET Set Value            */
#define I2C_IC_SMBUS_INTR_MASK_M_ARP_ASSGN_ADDR_CMD_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_INTR_MASK_M_ARP_ASSGN_ADDR_CMD_DET_Msk) >> \
     I2C_IC_SMBUS_INTR_MASK_M_ARP_ASSGN_ADDR_CMD_DET_Pos) /*!< M_ARP_ASSGN_ADDR_CMD_DET Get Value            */


#define I2C_IC_SMBUS_INTR_MASK_M_ARP_GET_UDID_CMD_DET_Pos (6U) /*!< M_ARP_GET_UDID_CMD_DET Postion   6          */
#define I2C_IC_SMBUS_INTR_MASK_M_ARP_GET_UDID_CMD_DET_Msk \
    (0x1U << I2C_IC_SMBUS_INTR_MASK_M_ARP_GET_UDID_CMD_DET_Pos) /*!< M_ARP_GET_UDID_CMD_DET Mask      0x00000040 */
#define I2C_IC_SMBUS_INTR_MASK_M_ARP_GET_UDID_CMD_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_INTR_MASK_M_ARP_GET_UDID_CMD_DET_Pos) & \
     I2C_IC_SMBUS_INTR_MASK_M_ARP_GET_UDID_CMD_DET_Msk) /*!< M_ARP_GET_UDID_CMD_DET Set Value            */
#define I2C_IC_SMBUS_INTR_MASK_M_ARP_GET_UDID_CMD_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_INTR_MASK_M_ARP_GET_UDID_CMD_DET_Msk) >> \
     I2C_IC_SMBUS_INTR_MASK_M_ARP_GET_UDID_CMD_DET_Pos) /*!< M_ARP_GET_UDID_CMD_DET Get Value            */


#define I2C_IC_SMBUS_INTR_MASK_M_ARP_RST_CMD_DET_Pos (5U) /*!< M_ARP_RST_CMD_DET Postion   5          */
#define I2C_IC_SMBUS_INTR_MASK_M_ARP_RST_CMD_DET_Msk \
    (0x1U << I2C_IC_SMBUS_INTR_MASK_M_ARP_RST_CMD_DET_Pos) /*!< M_ARP_RST_CMD_DET Mask      0x00000020 */
#define I2C_IC_SMBUS_INTR_MASK_M_ARP_RST_CMD_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_INTR_MASK_M_ARP_RST_CMD_DET_Pos) & \
     I2C_IC_SMBUS_INTR_MASK_M_ARP_RST_CMD_DET_Msk) /*!< M_ARP_RST_CMD_DET Set Value            */
#define I2C_IC_SMBUS_INTR_MASK_M_ARP_RST_CMD_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_INTR_MASK_M_ARP_RST_CMD_DET_Msk) >> \
     I2C_IC_SMBUS_INTR_MASK_M_ARP_RST_CMD_DET_Pos) /*!< M_ARP_RST_CMD_DET Get Value            */


#define I2C_IC_SMBUS_INTR_MASK_M_ARP_PREPARE_CMD_DET_Pos (4U) /*!< M_ARP_PREPARE_CMD_DET Postion   4          */
#define I2C_IC_SMBUS_INTR_MASK_M_ARP_PREPARE_CMD_DET_Msk \
    (0x1U << I2C_IC_SMBUS_INTR_MASK_M_ARP_PREPARE_CMD_DET_Pos) /*!< M_ARP_PREPARE_CMD_DET Mask      0x00000010 */
#define I2C_IC_SMBUS_INTR_MASK_M_ARP_PREPARE_CMD_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_INTR_MASK_M_ARP_PREPARE_CMD_DET_Pos) & \
     I2C_IC_SMBUS_INTR_MASK_M_ARP_PREPARE_CMD_DET_Msk) /*!< M_ARP_PREPARE_CMD_DET Set Value            */
#define I2C_IC_SMBUS_INTR_MASK_M_ARP_PREPARE_CMD_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_INTR_MASK_M_ARP_PREPARE_CMD_DET_Msk) >> \
     I2C_IC_SMBUS_INTR_MASK_M_ARP_PREPARE_CMD_DET_Pos) /*!< M_ARP_PREPARE_CMD_DET Get Value            */


#define I2C_IC_SMBUS_INTR_MASK_M_HOST_NOTIFY_MST_DET_Pos (3U) /*!< M_HOST_NOTIFY_MST_DET Postion   3          */
#define I2C_IC_SMBUS_INTR_MASK_M_HOST_NOTIFY_MST_DET_Msk \
    (0x1U << I2C_IC_SMBUS_INTR_MASK_M_HOST_NOTIFY_MST_DET_Pos) /*!< M_HOST_NOTIFY_MST_DET Mask      0x00000008 */
#define I2C_IC_SMBUS_INTR_MASK_M_HOST_NOTIFY_MST_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_INTR_MASK_M_HOST_NOTIFY_MST_DET_Pos) & \
     I2C_IC_SMBUS_INTR_MASK_M_HOST_NOTIFY_MST_DET_Msk) /*!< M_HOST_NOTIFY_MST_DET Set Value            */
#define I2C_IC_SMBUS_INTR_MASK_M_HOST_NOTIFY_MST_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_INTR_MASK_M_HOST_NOTIFY_MST_DET_Msk) >> \
     I2C_IC_SMBUS_INTR_MASK_M_HOST_NOTIFY_MST_DET_Pos) /*!< M_HOST_NOTIFY_MST_DET Get Value            */


#define I2C_IC_SMBUS_INTR_MASK_M_QUICK_CMD_DET_Pos (2U) /*!< M_QUICK_CMD_DET Postion   2          */
#define I2C_IC_SMBUS_INTR_MASK_M_QUICK_CMD_DET_Msk \
    (0x1U << I2C_IC_SMBUS_INTR_MASK_M_QUICK_CMD_DET_Pos) /*!< M_QUICK_CMD_DET Mask      0x00000004 */
#define I2C_IC_SMBUS_INTR_MASK_M_QUICK_CMD_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_INTR_MASK_M_QUICK_CMD_DET_Pos) & \
     I2C_IC_SMBUS_INTR_MASK_M_QUICK_CMD_DET_Msk) /*!< M_QUICK_CMD_DET Set Value            */
#define I2C_IC_SMBUS_INTR_MASK_M_QUICK_CMD_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_INTR_MASK_M_QUICK_CMD_DET_Msk) >> \
     I2C_IC_SMBUS_INTR_MASK_M_QUICK_CMD_DET_Pos) /*!< M_QUICK_CMD_DET Get Value            */


#define I2C_IC_SMBUS_INTR_MASK_M_MST_CLOCK_EXTND_TIMEOUT_Pos (1U) /*!< M_MST_CLOCK_EXTND_TIMEOUT Postion   1 */
#define I2C_IC_SMBUS_INTR_MASK_M_MST_CLOCK_EXTND_TIMEOUT_Msk \
    (0x1U                                                    \
     << I2C_IC_SMBUS_INTR_MASK_M_MST_CLOCK_EXTND_TIMEOUT_Pos) /*!< M_MST_CLOCK_EXTND_TIMEOUT Mask      0x00000002 */
#define I2C_IC_SMBUS_INTR_MASK_M_MST_CLOCK_EXTND_TIMEOUT_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_INTR_MASK_M_MST_CLOCK_EXTND_TIMEOUT_Pos) & \
     I2C_IC_SMBUS_INTR_MASK_M_MST_CLOCK_EXTND_TIMEOUT_Msk) /*!< M_MST_CLOCK_EXTND_TIMEOUT Set Value            */
#define I2C_IC_SMBUS_INTR_MASK_M_MST_CLOCK_EXTND_TIMEOUT_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_INTR_MASK_M_MST_CLOCK_EXTND_TIMEOUT_Msk) >> \
     I2C_IC_SMBUS_INTR_MASK_M_MST_CLOCK_EXTND_TIMEOUT_Pos) /*!< M_MST_CLOCK_EXTND_TIMEOUT Get Value            */


#define I2C_IC_SMBUS_INTR_MASK_M_SLV_CLOCK_EXTND_TIMEOUT_Pos (0U) /*!< M_SLV_CLOCK_EXTND_TIMEOUT Postion   0 */
#define I2C_IC_SMBUS_INTR_MASK_M_SLV_CLOCK_EXTND_TIMEOUT_Msk \
    (0x1U                                                    \
     << I2C_IC_SMBUS_INTR_MASK_M_SLV_CLOCK_EXTND_TIMEOUT_Pos) /*!< M_SLV_CLOCK_EXTND_TIMEOUT Mask      0x00000001 */
#define I2C_IC_SMBUS_INTR_MASK_M_SLV_CLOCK_EXTND_TIMEOUT_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_INTR_MASK_M_SLV_CLOCK_EXTND_TIMEOUT_Pos) & \
     I2C_IC_SMBUS_INTR_MASK_M_SLV_CLOCK_EXTND_TIMEOUT_Msk) /*!< M_SLV_CLOCK_EXTND_TIMEOUT Set Value            */
#define I2C_IC_SMBUS_INTR_MASK_M_SLV_CLOCK_EXTND_TIMEOUT_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_INTR_MASK_M_SLV_CLOCK_EXTND_TIMEOUT_Msk) >> \
     I2C_IC_SMBUS_INTR_MASK_M_SLV_CLOCK_EXTND_TIMEOUT_Pos) /*!< M_SLV_CLOCK_EXTND_TIMEOUT Get Value            */


/* IC_SMBUS_RAW_INTR_STAT bitfield */
#define I2C_IC_SMBUS_RAW_INTR_STAT_SMBUS_ALERT_DET_Pos (10U) /*!< SMBUS_ALERT_DET Postion   10         */
#define I2C_IC_SMBUS_RAW_INTR_STAT_SMBUS_ALERT_DET_Msk \
    (0x1U << I2C_IC_SMBUS_RAW_INTR_STAT_SMBUS_ALERT_DET_Pos) /*!< SMBUS_ALERT_DET Mask      0x00000400 */
#define I2C_IC_SMBUS_RAW_INTR_STAT_SMBUS_ALERT_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_RAW_INTR_STAT_SMBUS_ALERT_DET_Pos) & \
     I2C_IC_SMBUS_RAW_INTR_STAT_SMBUS_ALERT_DET_Msk) /*!< SMBUS_ALERT_DET Set Value            */
#define I2C_IC_SMBUS_RAW_INTR_STAT_SMBUS_ALERT_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_RAW_INTR_STAT_SMBUS_ALERT_DET_Msk) >> \
     I2C_IC_SMBUS_RAW_INTR_STAT_SMBUS_ALERT_DET_Pos) /*!< SMBUS_ALERT_DET Get Value            */


#define I2C_IC_SMBUS_RAW_INTR_STAT_SMBUS_SUSPEND_DET_Pos (9U) /*!< SMBUS_SUSPEND_DET Postion   9          */
#define I2C_IC_SMBUS_RAW_INTR_STAT_SMBUS_SUSPEND_DET_Msk \
    (0x1U << I2C_IC_SMBUS_RAW_INTR_STAT_SMBUS_SUSPEND_DET_Pos) /*!< SMBUS_SUSPEND_DET Mask      0x00000200 */
#define I2C_IC_SMBUS_RAW_INTR_STAT_SMBUS_SUSPEND_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_RAW_INTR_STAT_SMBUS_SUSPEND_DET_Pos) & \
     I2C_IC_SMBUS_RAW_INTR_STAT_SMBUS_SUSPEND_DET_Msk) /*!< SMBUS_SUSPEND_DET Set Value            */
#define I2C_IC_SMBUS_RAW_INTR_STAT_SMBUS_SUSPEND_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_RAW_INTR_STAT_SMBUS_SUSPEND_DET_Msk) >> \
     I2C_IC_SMBUS_RAW_INTR_STAT_SMBUS_SUSPEND_DET_Pos) /*!< SMBUS_SUSPEND_DET Get Value            */


#define I2C_IC_SMBUS_RAW_INTR_STAT_SLV_RX_PEC_NACK_Pos (8U) /*!< SLV_RX_PEC_NACK Postion   8          */
#define I2C_IC_SMBUS_RAW_INTR_STAT_SLV_RX_PEC_NACK_Msk \
    (0x1U << I2C_IC_SMBUS_RAW_INTR_STAT_SLV_RX_PEC_NACK_Pos) /*!< SLV_RX_PEC_NACK Mask      0x00000100 */
#define I2C_IC_SMBUS_RAW_INTR_STAT_SLV_RX_PEC_NACK_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_RAW_INTR_STAT_SLV_RX_PEC_NACK_Pos) & \
     I2C_IC_SMBUS_RAW_INTR_STAT_SLV_RX_PEC_NACK_Msk) /*!< SLV_RX_PEC_NACK Set Value            */
#define I2C_IC_SMBUS_RAW_INTR_STAT_SLV_RX_PEC_NACK_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_RAW_INTR_STAT_SLV_RX_PEC_NACK_Msk) >> \
     I2C_IC_SMBUS_RAW_INTR_STAT_SLV_RX_PEC_NACK_Pos) /*!< SLV_RX_PEC_NACK Get Value            */


#define I2C_IC_SMBUS_RAW_INTR_STAT_ARP_ASSGN_ADDR_CMD_DET_Pos (7U) /*!< ARP_ASSGN_ADDR_CMD_DET Postion   7          */
#define I2C_IC_SMBUS_RAW_INTR_STAT_ARP_ASSGN_ADDR_CMD_DET_Msk                                                        \
    (0x1U << I2C_IC_SMBUS_RAW_INTR_STAT_ARP_ASSGN_ADDR_CMD_DET_Pos) /*!< ARP_ASSGN_ADDR_CMD_DET Mask      0x00000080 \
                                                                     */
#define I2C_IC_SMBUS_RAW_INTR_STAT_ARP_ASSGN_ADDR_CMD_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_RAW_INTR_STAT_ARP_ASSGN_ADDR_CMD_DET_Pos) & \
     I2C_IC_SMBUS_RAW_INTR_STAT_ARP_ASSGN_ADDR_CMD_DET_Msk) /*!< ARP_ASSGN_ADDR_CMD_DET Set Value            */
#define I2C_IC_SMBUS_RAW_INTR_STAT_ARP_ASSGN_ADDR_CMD_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_RAW_INTR_STAT_ARP_ASSGN_ADDR_CMD_DET_Msk) >> \
     I2C_IC_SMBUS_RAW_INTR_STAT_ARP_ASSGN_ADDR_CMD_DET_Pos) /*!< ARP_ASSGN_ADDR_CMD_DET Get Value            */


#define I2C_IC_SMBUS_RAW_INTR_STAT_ARP_GET_UDID_CMD_DET_Pos (6U) /*!< ARP_GET_UDID_CMD_DET Postion   6          */
#define I2C_IC_SMBUS_RAW_INTR_STAT_ARP_GET_UDID_CMD_DET_Msk \
    (0x1U << I2C_IC_SMBUS_RAW_INTR_STAT_ARP_GET_UDID_CMD_DET_Pos) /*!< ARP_GET_UDID_CMD_DET Mask      0x00000040 */
#define I2C_IC_SMBUS_RAW_INTR_STAT_ARP_GET_UDID_CMD_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_RAW_INTR_STAT_ARP_GET_UDID_CMD_DET_Pos) & \
     I2C_IC_SMBUS_RAW_INTR_STAT_ARP_GET_UDID_CMD_DET_Msk) /*!< ARP_GET_UDID_CMD_DET Set Value            */
#define I2C_IC_SMBUS_RAW_INTR_STAT_ARP_GET_UDID_CMD_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_RAW_INTR_STAT_ARP_GET_UDID_CMD_DET_Msk) >> \
     I2C_IC_SMBUS_RAW_INTR_STAT_ARP_GET_UDID_CMD_DET_Pos) /*!< ARP_GET_UDID_CMD_DET Get Value            */


#define I2C_IC_SMBUS_RAW_INTR_STAT_ARP_RST_CMD_DET_Pos (5U) /*!< ARP_RST_CMD_DET Postion   5          */
#define I2C_IC_SMBUS_RAW_INTR_STAT_ARP_RST_CMD_DET_Msk \
    (0x1U << I2C_IC_SMBUS_RAW_INTR_STAT_ARP_RST_CMD_DET_Pos) /*!< ARP_RST_CMD_DET Mask      0x00000020 */
#define I2C_IC_SMBUS_RAW_INTR_STAT_ARP_RST_CMD_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_RAW_INTR_STAT_ARP_RST_CMD_DET_Pos) & \
     I2C_IC_SMBUS_RAW_INTR_STAT_ARP_RST_CMD_DET_Msk) /*!< ARP_RST_CMD_DET Set Value            */
#define I2C_IC_SMBUS_RAW_INTR_STAT_ARP_RST_CMD_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_RAW_INTR_STAT_ARP_RST_CMD_DET_Msk) >> \
     I2C_IC_SMBUS_RAW_INTR_STAT_ARP_RST_CMD_DET_Pos) /*!< ARP_RST_CMD_DET Get Value            */


#define I2C_IC_SMBUS_RAW_INTR_STAT_ARP_PREPARE_CMD_DET_Pos (4U) /*!< ARP_PREPARE_CMD_DET Postion   4          */
#define I2C_IC_SMBUS_RAW_INTR_STAT_ARP_PREPARE_CMD_DET_Msk \
    (0x1U << I2C_IC_SMBUS_RAW_INTR_STAT_ARP_PREPARE_CMD_DET_Pos) /*!< ARP_PREPARE_CMD_DET Mask      0x00000010 */
#define I2C_IC_SMBUS_RAW_INTR_STAT_ARP_PREPARE_CMD_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_RAW_INTR_STAT_ARP_PREPARE_CMD_DET_Pos) & \
     I2C_IC_SMBUS_RAW_INTR_STAT_ARP_PREPARE_CMD_DET_Msk) /*!< ARP_PREPARE_CMD_DET Set Value            */
#define I2C_IC_SMBUS_RAW_INTR_STAT_ARP_PREPARE_CMD_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_RAW_INTR_STAT_ARP_PREPARE_CMD_DET_Msk) >> \
     I2C_IC_SMBUS_RAW_INTR_STAT_ARP_PREPARE_CMD_DET_Pos) /*!< ARP_PREPARE_CMD_DET Get Value            */


#define I2C_IC_SMBUS_RAW_INTR_STAT_HOST_NTFY_MST_DET_Pos (3U) /*!< HOST_NTFY_MST_DET Postion   3          */
#define I2C_IC_SMBUS_RAW_INTR_STAT_HOST_NTFY_MST_DET_Msk \
    (0x1U << I2C_IC_SMBUS_RAW_INTR_STAT_HOST_NTFY_MST_DET_Pos) /*!< HOST_NTFY_MST_DET Mask      0x00000008 */
#define I2C_IC_SMBUS_RAW_INTR_STAT_HOST_NTFY_MST_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_RAW_INTR_STAT_HOST_NTFY_MST_DET_Pos) & \
     I2C_IC_SMBUS_RAW_INTR_STAT_HOST_NTFY_MST_DET_Msk) /*!< HOST_NTFY_MST_DET Set Value            */
#define I2C_IC_SMBUS_RAW_INTR_STAT_HOST_NTFY_MST_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_RAW_INTR_STAT_HOST_NTFY_MST_DET_Msk) >> \
     I2C_IC_SMBUS_RAW_INTR_STAT_HOST_NTFY_MST_DET_Pos) /*!< HOST_NTFY_MST_DET Get Value            */


#define I2C_IC_SMBUS_RAW_INTR_STAT_QUICK_CMD_DET_Pos (2U) /*!< QUICK_CMD_DET Postion   2          */
#define I2C_IC_SMBUS_RAW_INTR_STAT_QUICK_CMD_DET_Msk \
    (0x1U << I2C_IC_SMBUS_RAW_INTR_STAT_QUICK_CMD_DET_Pos) /*!< QUICK_CMD_DET Mask      0x00000004 */
#define I2C_IC_SMBUS_RAW_INTR_STAT_QUICK_CMD_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_RAW_INTR_STAT_QUICK_CMD_DET_Pos) & \
     I2C_IC_SMBUS_RAW_INTR_STAT_QUICK_CMD_DET_Msk) /*!< QUICK_CMD_DET Set Value            */
#define I2C_IC_SMBUS_RAW_INTR_STAT_QUICK_CMD_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_RAW_INTR_STAT_QUICK_CMD_DET_Msk) >> \
     I2C_IC_SMBUS_RAW_INTR_STAT_QUICK_CMD_DET_Pos) /*!< QUICK_CMD_DET Get Value            */


#define I2C_IC_SMBUS_RAW_INTR_STAT_MST_CLOCK_EXTND_TIMEOUT_Pos (1U) /*!< MST_CLOCK_EXTND_TIMEOUT Postion   1 */
#define I2C_IC_SMBUS_RAW_INTR_STAT_MST_CLOCK_EXTND_TIMEOUT_Msk \
    (0x1U                                                      \
     << I2C_IC_SMBUS_RAW_INTR_STAT_MST_CLOCK_EXTND_TIMEOUT_Pos) /*!< MST_CLOCK_EXTND_TIMEOUT Mask      0x00000002 */
#define I2C_IC_SMBUS_RAW_INTR_STAT_MST_CLOCK_EXTND_TIMEOUT_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_RAW_INTR_STAT_MST_CLOCK_EXTND_TIMEOUT_Pos) & \
     I2C_IC_SMBUS_RAW_INTR_STAT_MST_CLOCK_EXTND_TIMEOUT_Msk) /*!< MST_CLOCK_EXTND_TIMEOUT Set Value            */
#define I2C_IC_SMBUS_RAW_INTR_STAT_MST_CLOCK_EXTND_TIMEOUT_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_RAW_INTR_STAT_MST_CLOCK_EXTND_TIMEOUT_Msk) >> \
     I2C_IC_SMBUS_RAW_INTR_STAT_MST_CLOCK_EXTND_TIMEOUT_Pos) /*!< MST_CLOCK_EXTND_TIMEOUT Get Value            */


#define I2C_IC_SMBUS_RAW_INTR_STAT_SLV_CLOCK_EXTND_TIMEOUT_Pos (0U) /*!< SLV_CLOCK_EXTND_TIMEOUT Postion   0 */
#define I2C_IC_SMBUS_RAW_INTR_STAT_SLV_CLOCK_EXTND_TIMEOUT_Msk \
    (0x1U                                                      \
     << I2C_IC_SMBUS_RAW_INTR_STAT_SLV_CLOCK_EXTND_TIMEOUT_Pos) /*!< SLV_CLOCK_EXTND_TIMEOUT Mask      0x00000001 */
#define I2C_IC_SMBUS_RAW_INTR_STAT_SLV_CLOCK_EXTND_TIMEOUT_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_RAW_INTR_STAT_SLV_CLOCK_EXTND_TIMEOUT_Pos) & \
     I2C_IC_SMBUS_RAW_INTR_STAT_SLV_CLOCK_EXTND_TIMEOUT_Msk) /*!< SLV_CLOCK_EXTND_TIMEOUT Set Value            */
#define I2C_IC_SMBUS_RAW_INTR_STAT_SLV_CLOCK_EXTND_TIMEOUT_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_RAW_INTR_STAT_SLV_CLOCK_EXTND_TIMEOUT_Msk) >> \
     I2C_IC_SMBUS_RAW_INTR_STAT_SLV_CLOCK_EXTND_TIMEOUT_Pos) /*!< SLV_CLOCK_EXTND_TIMEOUT Get Value            */


/* IC_CLR_SMBUS_INTR bitfield */
#define I2C_IC_CLR_SMBUS_INTR_CLR_SMBUS_ALERT_DET_Pos (10U) /*!< CLR_SMBUS_ALERT_DET Postion   10         */
#define I2C_IC_CLR_SMBUS_INTR_CLR_SMBUS_ALERT_DET_Msk \
    (0x1U << I2C_IC_CLR_SMBUS_INTR_CLR_SMBUS_ALERT_DET_Pos) /*!< CLR_SMBUS_ALERT_DET Mask      0x00000400 */
#define I2C_IC_CLR_SMBUS_INTR_CLR_SMBUS_ALERT_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_CLR_SMBUS_INTR_CLR_SMBUS_ALERT_DET_Pos) & \
     I2C_IC_CLR_SMBUS_INTR_CLR_SMBUS_ALERT_DET_Msk) /*!< CLR_SMBUS_ALERT_DET Set Value            */
#define I2C_IC_CLR_SMBUS_INTR_CLR_SMBUS_ALERT_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_CLR_SMBUS_INTR_CLR_SMBUS_ALERT_DET_Msk) >> \
     I2C_IC_CLR_SMBUS_INTR_CLR_SMBUS_ALERT_DET_Pos) /*!< CLR_SMBUS_ALERT_DET Get Value            */


#define I2C_IC_CLR_SMBUS_INTR_CLR_SMBUS_SUSPEND_DET_Pos (9U) /*!< CLR_SMBUS_SUSPEND_DET Postion   9          */
#define I2C_IC_CLR_SMBUS_INTR_CLR_SMBUS_SUSPEND_DET_Msk \
    (0x1U << I2C_IC_CLR_SMBUS_INTR_CLR_SMBUS_SUSPEND_DET_Pos) /*!< CLR_SMBUS_SUSPEND_DET Mask      0x00000200 */
#define I2C_IC_CLR_SMBUS_INTR_CLR_SMBUS_SUSPEND_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_CLR_SMBUS_INTR_CLR_SMBUS_SUSPEND_DET_Pos) & \
     I2C_IC_CLR_SMBUS_INTR_CLR_SMBUS_SUSPEND_DET_Msk) /*!< CLR_SMBUS_SUSPEND_DET Set Value            */
#define I2C_IC_CLR_SMBUS_INTR_CLR_SMBUS_SUSPEND_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_CLR_SMBUS_INTR_CLR_SMBUS_SUSPEND_DET_Msk) >> \
     I2C_IC_CLR_SMBUS_INTR_CLR_SMBUS_SUSPEND_DET_Pos) /*!< CLR_SMBUS_SUSPEND_DET Get Value            */


#define I2C_IC_CLR_SMBUS_INTR_CLR_SLV_RX_PEC_NACK_Pos (8U) /*!< CLR_SLV_RX_PEC_NACK Postion   8          */
#define I2C_IC_CLR_SMBUS_INTR_CLR_SLV_RX_PEC_NACK_Msk \
    (0x1U << I2C_IC_CLR_SMBUS_INTR_CLR_SLV_RX_PEC_NACK_Pos) /*!< CLR_SLV_RX_PEC_NACK Mask      0x00000100 */
#define I2C_IC_CLR_SMBUS_INTR_CLR_SLV_RX_PEC_NACK_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_CLR_SMBUS_INTR_CLR_SLV_RX_PEC_NACK_Pos) & \
     I2C_IC_CLR_SMBUS_INTR_CLR_SLV_RX_PEC_NACK_Msk) /*!< CLR_SLV_RX_PEC_NACK Set Value            */
#define I2C_IC_CLR_SMBUS_INTR_CLR_SLV_RX_PEC_NACK_Get(x)                \
    (((uint32_t) (x) &I2C_IC_CLR_SMBUS_INTR_CLR_SLV_RX_PEC_NACK_Msk) >> \
     I2C_IC_CLR_SMBUS_INTR_CLR_SLV_RX_PEC_NACK_Pos) /*!< CLR_SLV_RX_PEC_NACK Get Value            */


#define I2C_IC_CLR_SMBUS_INTR_CLR_ARP_ASSGN_ADDR_CMD_DET_Pos \
    (7U) /*!< CLR_ARP_ASSGN_ADDR_CMD_DET Postion   7          */
#define I2C_IC_CLR_SMBUS_INTR_CLR_ARP_ASSGN_ADDR_CMD_DET_Msk \
    (0x1U << I2C_IC_CLR_SMBUS_INTR_CLR_ARP_ASSGN_ADDR_CMD_DET_Pos) /*!< CLR_ARP_ASSGN_ADDR_CMD_DET Mask 0x00000080 */
#define I2C_IC_CLR_SMBUS_INTR_CLR_ARP_ASSGN_ADDR_CMD_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_CLR_SMBUS_INTR_CLR_ARP_ASSGN_ADDR_CMD_DET_Pos) & \
     I2C_IC_CLR_SMBUS_INTR_CLR_ARP_ASSGN_ADDR_CMD_DET_Msk) /*!< CLR_ARP_ASSGN_ADDR_CMD_DET Set Value            */
#define I2C_IC_CLR_SMBUS_INTR_CLR_ARP_ASSGN_ADDR_CMD_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_CLR_SMBUS_INTR_CLR_ARP_ASSGN_ADDR_CMD_DET_Msk) >> \
     I2C_IC_CLR_SMBUS_INTR_CLR_ARP_ASSGN_ADDR_CMD_DET_Pos) /*!< CLR_ARP_ASSGN_ADDR_CMD_DET Get Value            */


#define I2C_IC_CLR_SMBUS_INTR_CLR_ARP_GET_UDID_CMD_DET_Pos (6U) /*!< CLR_ARP_GET_UDID_CMD_DET Postion   6          */
#define I2C_IC_CLR_SMBUS_INTR_CLR_ARP_GET_UDID_CMD_DET_Msk \
    (0x1U << I2C_IC_CLR_SMBUS_INTR_CLR_ARP_GET_UDID_CMD_DET_Pos) /*!< CLR_ARP_GET_UDID_CMD_DET Mask      0x00000040 */
#define I2C_IC_CLR_SMBUS_INTR_CLR_ARP_GET_UDID_CMD_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_CLR_SMBUS_INTR_CLR_ARP_GET_UDID_CMD_DET_Pos) & \
     I2C_IC_CLR_SMBUS_INTR_CLR_ARP_GET_UDID_CMD_DET_Msk) /*!< CLR_ARP_GET_UDID_CMD_DET Set Value            */
#define I2C_IC_CLR_SMBUS_INTR_CLR_ARP_GET_UDID_CMD_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_CLR_SMBUS_INTR_CLR_ARP_GET_UDID_CMD_DET_Msk) >> \
     I2C_IC_CLR_SMBUS_INTR_CLR_ARP_GET_UDID_CMD_DET_Pos) /*!< CLR_ARP_GET_UDID_CMD_DET Get Value            */


#define I2C_IC_CLR_SMBUS_INTR_CLR_ARP_RST_CMD_DET_Pos (5U) /*!< CLR_ARP_RST_CMD_DET Postion   5          */
#define I2C_IC_CLR_SMBUS_INTR_CLR_ARP_RST_CMD_DET_Msk \
    (0x1U << I2C_IC_CLR_SMBUS_INTR_CLR_ARP_RST_CMD_DET_Pos) /*!< CLR_ARP_RST_CMD_DET Mask      0x00000020 */
#define I2C_IC_CLR_SMBUS_INTR_CLR_ARP_RST_CMD_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_CLR_SMBUS_INTR_CLR_ARP_RST_CMD_DET_Pos) & \
     I2C_IC_CLR_SMBUS_INTR_CLR_ARP_RST_CMD_DET_Msk) /*!< CLR_ARP_RST_CMD_DET Set Value            */
#define I2C_IC_CLR_SMBUS_INTR_CLR_ARP_RST_CMD_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_CLR_SMBUS_INTR_CLR_ARP_RST_CMD_DET_Msk) >> \
     I2C_IC_CLR_SMBUS_INTR_CLR_ARP_RST_CMD_DET_Pos) /*!< CLR_ARP_RST_CMD_DET Get Value            */


#define I2C_IC_CLR_SMBUS_INTR_CLR_ARP_PREPARE_CMD_DET_Pos (4U) /*!< CLR_ARP_PREPARE_CMD_DET Postion   4          */
#define I2C_IC_CLR_SMBUS_INTR_CLR_ARP_PREPARE_CMD_DET_Msk \
    (0x1U << I2C_IC_CLR_SMBUS_INTR_CLR_ARP_PREPARE_CMD_DET_Pos) /*!< CLR_ARP_PREPARE_CMD_DET Mask      0x00000010 */
#define I2C_IC_CLR_SMBUS_INTR_CLR_ARP_PREPARE_CMD_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_CLR_SMBUS_INTR_CLR_ARP_PREPARE_CMD_DET_Pos) & \
     I2C_IC_CLR_SMBUS_INTR_CLR_ARP_PREPARE_CMD_DET_Msk) /*!< CLR_ARP_PREPARE_CMD_DET Set Value            */
#define I2C_IC_CLR_SMBUS_INTR_CLR_ARP_PREPARE_CMD_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_CLR_SMBUS_INTR_CLR_ARP_PREPARE_CMD_DET_Msk) >> \
     I2C_IC_CLR_SMBUS_INTR_CLR_ARP_PREPARE_CMD_DET_Pos) /*!< CLR_ARP_PREPARE_CMD_DET Get Value            */


#define I2C_IC_CLR_SMBUS_INTR_CLR_HOST_NOTIFY_MST_DET_Pos (3U) /*!< CLR_HOST_NOTIFY_MST_DET Postion   3          */
#define I2C_IC_CLR_SMBUS_INTR_CLR_HOST_NOTIFY_MST_DET_Msk \
    (0x1U << I2C_IC_CLR_SMBUS_INTR_CLR_HOST_NOTIFY_MST_DET_Pos) /*!< CLR_HOST_NOTIFY_MST_DET Mask      0x00000008 */
#define I2C_IC_CLR_SMBUS_INTR_CLR_HOST_NOTIFY_MST_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_CLR_SMBUS_INTR_CLR_HOST_NOTIFY_MST_DET_Pos) & \
     I2C_IC_CLR_SMBUS_INTR_CLR_HOST_NOTIFY_MST_DET_Msk) /*!< CLR_HOST_NOTIFY_MST_DET Set Value            */
#define I2C_IC_CLR_SMBUS_INTR_CLR_HOST_NOTIFY_MST_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_CLR_SMBUS_INTR_CLR_HOST_NOTIFY_MST_DET_Msk) >> \
     I2C_IC_CLR_SMBUS_INTR_CLR_HOST_NOTIFY_MST_DET_Pos) /*!< CLR_HOST_NOTIFY_MST_DET Get Value            */


#define I2C_IC_CLR_SMBUS_INTR_CLR_QUICK_CMD_DET_Pos (2U) /*!< CLR_QUICK_CMD_DET Postion   2          */
#define I2C_IC_CLR_SMBUS_INTR_CLR_QUICK_CMD_DET_Msk \
    (0x1U << I2C_IC_CLR_SMBUS_INTR_CLR_QUICK_CMD_DET_Pos) /*!< CLR_QUICK_CMD_DET Mask      0x00000004 */
#define I2C_IC_CLR_SMBUS_INTR_CLR_QUICK_CMD_DET_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_CLR_SMBUS_INTR_CLR_QUICK_CMD_DET_Pos) & \
     I2C_IC_CLR_SMBUS_INTR_CLR_QUICK_CMD_DET_Msk) /*!< CLR_QUICK_CMD_DET Set Value            */
#define I2C_IC_CLR_SMBUS_INTR_CLR_QUICK_CMD_DET_Get(x)                \
    (((uint32_t) (x) &I2C_IC_CLR_SMBUS_INTR_CLR_QUICK_CMD_DET_Msk) >> \
     I2C_IC_CLR_SMBUS_INTR_CLR_QUICK_CMD_DET_Pos) /*!< CLR_QUICK_CMD_DET Get Value            */


#define I2C_IC_CLR_SMBUS_INTR_CLR_MST_CLOCK_EXTND_TIMEOUT_Pos \
    (1U) /*!< CLR_MST_CLOCK_EXTND_TIMEOUT Postion   1          */
#define I2C_IC_CLR_SMBUS_INTR_CLR_MST_CLOCK_EXTND_TIMEOUT_Msk                                                        \
    (0x1U << I2C_IC_CLR_SMBUS_INTR_CLR_MST_CLOCK_EXTND_TIMEOUT_Pos) /*!< CLR_MST_CLOCK_EXTND_TIMEOUT Mask 0x00000002 \
                                                                     */
#define I2C_IC_CLR_SMBUS_INTR_CLR_MST_CLOCK_EXTND_TIMEOUT_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_CLR_SMBUS_INTR_CLR_MST_CLOCK_EXTND_TIMEOUT_Pos) & \
     I2C_IC_CLR_SMBUS_INTR_CLR_MST_CLOCK_EXTND_TIMEOUT_Msk) /*!< CLR_MST_CLOCK_EXTND_TIMEOUT Set Value            */
#define I2C_IC_CLR_SMBUS_INTR_CLR_MST_CLOCK_EXTND_TIMEOUT_Get(x)                \
    (((uint32_t) (x) &I2C_IC_CLR_SMBUS_INTR_CLR_MST_CLOCK_EXTND_TIMEOUT_Msk) >> \
     I2C_IC_CLR_SMBUS_INTR_CLR_MST_CLOCK_EXTND_TIMEOUT_Pos) /*!< CLR_MST_CLOCK_EXTND_TIMEOUT Get Value            */


#define I2C_IC_CLR_SMBUS_INTR_CLR_SLV_CLOCK_EXTND_TIMEOUT_Pos \
    (0U) /*!< CLR_SLV_CLOCK_EXTND_TIMEOUT Postion   0          */
#define I2C_IC_CLR_SMBUS_INTR_CLR_SLV_CLOCK_EXTND_TIMEOUT_Msk                                                        \
    (0x1U << I2C_IC_CLR_SMBUS_INTR_CLR_SLV_CLOCK_EXTND_TIMEOUT_Pos) /*!< CLR_SLV_CLOCK_EXTND_TIMEOUT Mask 0x00000001 \
                                                                     */
#define I2C_IC_CLR_SMBUS_INTR_CLR_SLV_CLOCK_EXTND_TIMEOUT_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_CLR_SMBUS_INTR_CLR_SLV_CLOCK_EXTND_TIMEOUT_Pos) & \
     I2C_IC_CLR_SMBUS_INTR_CLR_SLV_CLOCK_EXTND_TIMEOUT_Msk) /*!< CLR_SLV_CLOCK_EXTND_TIMEOUT Set Value            */
#define I2C_IC_CLR_SMBUS_INTR_CLR_SLV_CLOCK_EXTND_TIMEOUT_Get(x)                \
    (((uint32_t) (x) &I2C_IC_CLR_SMBUS_INTR_CLR_SLV_CLOCK_EXTND_TIMEOUT_Msk) >> \
     I2C_IC_CLR_SMBUS_INTR_CLR_SLV_CLOCK_EXTND_TIMEOUT_Pos) /*!< CLR_SLV_CLOCK_EXTND_TIMEOUT Get Value            */


/* IC_OPTIONAL_SAR bitfield */
#define I2C_IC_OPTIONAL_SAR_OPTIONAL_SAR_Pos (0U) /*!< OPTIONAL_SAR Postion   0          */
#define I2C_IC_OPTIONAL_SAR_OPTIONAL_SAR_Msk \
    (0x7fU << I2C_IC_OPTIONAL_SAR_OPTIONAL_SAR_Pos) /*!< OPTIONAL_SAR Mask      0x0000007F */
#define I2C_IC_OPTIONAL_SAR_OPTIONAL_SAR_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_OPTIONAL_SAR_OPTIONAL_SAR_Pos) & \
     I2C_IC_OPTIONAL_SAR_OPTIONAL_SAR_Msk) /*!< OPTIONAL_SAR Set Value            */
#define I2C_IC_OPTIONAL_SAR_OPTIONAL_SAR_Get(x)                \
    (((uint32_t) (x) &I2C_IC_OPTIONAL_SAR_OPTIONAL_SAR_Msk) >> \
     I2C_IC_OPTIONAL_SAR_OPTIONAL_SAR_Pos) /*!< OPTIONAL_SAR Get Value            */


/* IC_SMBUS_UDID_LSB bitfield */
#define I2C_IC_SMBUS_UDID_LSB_SMBUS_UDID_LSB_Pos (0U) /*!< SMBUS_UDID_LSB Postion   0          */
#define I2C_IC_SMBUS_UDID_LSB_SMBUS_UDID_LSB_Msk \
    (0xffffffffU << I2C_IC_SMBUS_UDID_LSB_SMBUS_UDID_LSB_Pos) /*!< SMBUS_UDID_LSB Mask      0xFFFFFFFF */
#define I2C_IC_SMBUS_UDID_LSB_SMBUS_UDID_LSB_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_UDID_LSB_SMBUS_UDID_LSB_Pos) & \
     I2C_IC_SMBUS_UDID_LSB_SMBUS_UDID_LSB_Msk) /*!< SMBUS_UDID_LSB Set Value            */
#define I2C_IC_SMBUS_UDID_LSB_SMBUS_UDID_LSB_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_UDID_LSB_SMBUS_UDID_LSB_Msk) >> \
     I2C_IC_SMBUS_UDID_LSB_SMBUS_UDID_LSB_Pos) /*!< SMBUS_UDID_LSB Get Value            */


/* IC_SMBUS_UDID_WORD0 bitfield */
#define I2C_IC_SMBUS_UDID_WORD0_SMBUS_UDID_WORD0_Pos (0U) /*!< SMBUS_UDID_WORD0 Postion   0          */
#define I2C_IC_SMBUS_UDID_WORD0_SMBUS_UDID_WORD0_Msk \
    (0xffffffffU << I2C_IC_SMBUS_UDID_WORD0_SMBUS_UDID_WORD0_Pos) /*!< SMBUS_UDID_WORD0 Mask      0xFFFFFFFF */
#define I2C_IC_SMBUS_UDID_WORD0_SMBUS_UDID_WORD0_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_UDID_WORD0_SMBUS_UDID_WORD0_Pos) & \
     I2C_IC_SMBUS_UDID_WORD0_SMBUS_UDID_WORD0_Msk) /*!< SMBUS_UDID_WORD0 Set Value            */
#define I2C_IC_SMBUS_UDID_WORD0_SMBUS_UDID_WORD0_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_UDID_WORD0_SMBUS_UDID_WORD0_Msk) >> \
     I2C_IC_SMBUS_UDID_WORD0_SMBUS_UDID_WORD0_Pos) /*!< SMBUS_UDID_WORD0 Get Value            */


/* IC_SMBUS_UDID_WORD1 bitfield */
#define I2C_IC_SMBUS_UDID_WORD1_SMBUS_UDID_WORD1_Pos (0U) /*!< SMBUS_UDID_WORD1 Postion   0          */
#define I2C_IC_SMBUS_UDID_WORD1_SMBUS_UDID_WORD1_Msk \
    (0xffffffffU << I2C_IC_SMBUS_UDID_WORD1_SMBUS_UDID_WORD1_Pos) /*!< SMBUS_UDID_WORD1 Mask      0xFFFFFFFF */
#define I2C_IC_SMBUS_UDID_WORD1_SMBUS_UDID_WORD1_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_UDID_WORD1_SMBUS_UDID_WORD1_Pos) & \
     I2C_IC_SMBUS_UDID_WORD1_SMBUS_UDID_WORD1_Msk) /*!< SMBUS_UDID_WORD1 Set Value            */
#define I2C_IC_SMBUS_UDID_WORD1_SMBUS_UDID_WORD1_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_UDID_WORD1_SMBUS_UDID_WORD1_Msk) >> \
     I2C_IC_SMBUS_UDID_WORD1_SMBUS_UDID_WORD1_Pos) /*!< SMBUS_UDID_WORD1 Get Value            */


/* IC_SMBUS_UDID_WORD2 bitfield */
#define I2C_IC_SMBUS_UDID_WORD2_SMBUS_UDID_WORD2_Pos (0U) /*!< SMBUS_UDID_WORD2 Postion   0          */
#define I2C_IC_SMBUS_UDID_WORD2_SMBUS_UDID_WORD2_Msk \
    (0xffffffffU << I2C_IC_SMBUS_UDID_WORD2_SMBUS_UDID_WORD2_Pos) /*!< SMBUS_UDID_WORD2 Mask      0xFFFFFFFF */
#define I2C_IC_SMBUS_UDID_WORD2_SMBUS_UDID_WORD2_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_UDID_WORD2_SMBUS_UDID_WORD2_Pos) & \
     I2C_IC_SMBUS_UDID_WORD2_SMBUS_UDID_WORD2_Msk) /*!< SMBUS_UDID_WORD2 Set Value            */
#define I2C_IC_SMBUS_UDID_WORD2_SMBUS_UDID_WORD2_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_UDID_WORD2_SMBUS_UDID_WORD2_Msk) >> \
     I2C_IC_SMBUS_UDID_WORD2_SMBUS_UDID_WORD2_Pos) /*!< SMBUS_UDID_WORD2 Get Value            */


/* IC_SMBUS_UDID_WORD3 bitfield */
#define I2C_IC_SMBUS_UDID_WORD3_SMBUS_UDID_WORD3_Pos (0U) /*!< SMBUS_UDID_WORD3 Postion   0          */
#define I2C_IC_SMBUS_UDID_WORD3_SMBUS_UDID_WORD3_Msk \
    (0xffffffffU << I2C_IC_SMBUS_UDID_WORD3_SMBUS_UDID_WORD3_Pos) /*!< SMBUS_UDID_WORD3 Mask      0xFFFFFFFF */
#define I2C_IC_SMBUS_UDID_WORD3_SMBUS_UDID_WORD3_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_SMBUS_UDID_WORD3_SMBUS_UDID_WORD3_Pos) & \
     I2C_IC_SMBUS_UDID_WORD3_SMBUS_UDID_WORD3_Msk) /*!< SMBUS_UDID_WORD3 Set Value            */
#define I2C_IC_SMBUS_UDID_WORD3_SMBUS_UDID_WORD3_Get(x)                \
    (((uint32_t) (x) &I2C_IC_SMBUS_UDID_WORD3_SMBUS_UDID_WORD3_Msk) >> \
     I2C_IC_SMBUS_UDID_WORD3_SMBUS_UDID_WORD3_Pos) /*!< SMBUS_UDID_WORD3 Get Value            */


/* REG_TIMEOUT_RST bitfield */
#define I2C_REG_TIMEOUT_RST_REG_TIMEOUT_RST_RW_Pos (0U) /*!< REG_TIMEOUT_RST_RW Postion   0          */
#define I2C_REG_TIMEOUT_RST_REG_TIMEOUT_RST_RW_Msk \
    (0xfU << I2C_REG_TIMEOUT_RST_REG_TIMEOUT_RST_RW_Pos) /*!< REG_TIMEOUT_RST_RW Mask      0x0000000F */
#define I2C_REG_TIMEOUT_RST_REG_TIMEOUT_RST_RW_Set(x)                 \
    (((uint32_t) (x) << I2C_REG_TIMEOUT_RST_REG_TIMEOUT_RST_RW_Pos) & \
     I2C_REG_TIMEOUT_RST_REG_TIMEOUT_RST_RW_Msk) /*!< REG_TIMEOUT_RST_RW Set Value            */
#define I2C_REG_TIMEOUT_RST_REG_TIMEOUT_RST_RW_Get(x)                \
    (((uint32_t) (x) &I2C_REG_TIMEOUT_RST_REG_TIMEOUT_RST_RW_Msk) >> \
     I2C_REG_TIMEOUT_RST_REG_TIMEOUT_RST_RW_Pos) /*!< REG_TIMEOUT_RST_RW Get Value            */


/* IC_COMP_PARAM_1 bitfield */
#define I2C_IC_COMP_PARAM_1_TX_BUFFER_DEPTH_Pos (16U) /*!< TX_BUFFER_DEPTH Postion   16         */
#define I2C_IC_COMP_PARAM_1_TX_BUFFER_DEPTH_Msk \
    (0xffU << I2C_IC_COMP_PARAM_1_TX_BUFFER_DEPTH_Pos) /*!< TX_BUFFER_DEPTH Mask      0x00FF0000 */
#define I2C_IC_COMP_PARAM_1_TX_BUFFER_DEPTH_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_COMP_PARAM_1_TX_BUFFER_DEPTH_Pos) & \
     I2C_IC_COMP_PARAM_1_TX_BUFFER_DEPTH_Msk) /*!< TX_BUFFER_DEPTH Set Value            */
#define I2C_IC_COMP_PARAM_1_TX_BUFFER_DEPTH_Get(x)                \
    (((uint32_t) (x) &I2C_IC_COMP_PARAM_1_TX_BUFFER_DEPTH_Msk) >> \
     I2C_IC_COMP_PARAM_1_TX_BUFFER_DEPTH_Pos) /*!< TX_BUFFER_DEPTH Get Value            */


#define I2C_IC_COMP_PARAM_1_RX_BUFFER_DEPTH_Pos (8U) /*!< RX_BUFFER_DEPTH Postion   8          */
#define I2C_IC_COMP_PARAM_1_RX_BUFFER_DEPTH_Msk \
    (0xffU << I2C_IC_COMP_PARAM_1_RX_BUFFER_DEPTH_Pos) /*!< RX_BUFFER_DEPTH Mask      0x0000FF00 */
#define I2C_IC_COMP_PARAM_1_RX_BUFFER_DEPTH_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_COMP_PARAM_1_RX_BUFFER_DEPTH_Pos) & \
     I2C_IC_COMP_PARAM_1_RX_BUFFER_DEPTH_Msk) /*!< RX_BUFFER_DEPTH Set Value            */
#define I2C_IC_COMP_PARAM_1_RX_BUFFER_DEPTH_Get(x)                \
    (((uint32_t) (x) &I2C_IC_COMP_PARAM_1_RX_BUFFER_DEPTH_Msk) >> \
     I2C_IC_COMP_PARAM_1_RX_BUFFER_DEPTH_Pos) /*!< RX_BUFFER_DEPTH Get Value            */


#define I2C_IC_COMP_PARAM_1_ADD_ENCODED_PARAMS_Pos (7U) /*!< ADD_ENCODED_PARAMS Postion   7          */
#define I2C_IC_COMP_PARAM_1_ADD_ENCODED_PARAMS_Msk \
    (0x1U << I2C_IC_COMP_PARAM_1_ADD_ENCODED_PARAMS_Pos) /*!< ADD_ENCODED_PARAMS Mask      0x00000080 */
#define I2C_IC_COMP_PARAM_1_ADD_ENCODED_PARAMS_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_COMP_PARAM_1_ADD_ENCODED_PARAMS_Pos) & \
     I2C_IC_COMP_PARAM_1_ADD_ENCODED_PARAMS_Msk) /*!< ADD_ENCODED_PARAMS Set Value            */
#define I2C_IC_COMP_PARAM_1_ADD_ENCODED_PARAMS_Get(x)                \
    (((uint32_t) (x) &I2C_IC_COMP_PARAM_1_ADD_ENCODED_PARAMS_Msk) >> \
     I2C_IC_COMP_PARAM_1_ADD_ENCODED_PARAMS_Pos) /*!< ADD_ENCODED_PARAMS Get Value            */


#define I2C_IC_COMP_PARAM_1_HAS_DMA_Pos (6U)                                      /*!< HAS_DMA Postion   6          */
#define I2C_IC_COMP_PARAM_1_HAS_DMA_Msk (0x1U << I2C_IC_COMP_PARAM_1_HAS_DMA_Pos) /*!< HAS_DMA Mask      0x00000040 */
#define I2C_IC_COMP_PARAM_1_HAS_DMA_Set(x) \
    (((uint32_t) (x) << I2C_IC_COMP_PARAM_1_HAS_DMA_Pos) & I2C_IC_COMP_PARAM_1_HAS_DMA_Msk) /*!< HAS_DMA Set Value */
#define I2C_IC_COMP_PARAM_1_HAS_DMA_Get(x) \
    (((uint32_t) (x) &I2C_IC_COMP_PARAM_1_HAS_DMA_Msk) >> I2C_IC_COMP_PARAM_1_HAS_DMA_Pos) /*!< HAS_DMA Get Value */


#define I2C_IC_COMP_PARAM_1_INTR_IO_Pos (5U)                                      /*!< INTR_IO Postion   5          */
#define I2C_IC_COMP_PARAM_1_INTR_IO_Msk (0x1U << I2C_IC_COMP_PARAM_1_INTR_IO_Pos) /*!< INTR_IO Mask      0x00000020 */
#define I2C_IC_COMP_PARAM_1_INTR_IO_Set(x) \
    (((uint32_t) (x) << I2C_IC_COMP_PARAM_1_INTR_IO_Pos) & I2C_IC_COMP_PARAM_1_INTR_IO_Msk) /*!< INTR_IO Set Value */
#define I2C_IC_COMP_PARAM_1_INTR_IO_Get(x) \
    (((uint32_t) (x) &I2C_IC_COMP_PARAM_1_INTR_IO_Msk) >> I2C_IC_COMP_PARAM_1_INTR_IO_Pos) /*!< INTR_IO Get Value */


#define I2C_IC_COMP_PARAM_1_HC_COUNT_VALUES_Pos (4U) /*!< HC_COUNT_VALUES Postion   4          */
#define I2C_IC_COMP_PARAM_1_HC_COUNT_VALUES_Msk \
    (0x1U << I2C_IC_COMP_PARAM_1_HC_COUNT_VALUES_Pos) /*!< HC_COUNT_VALUES Mask      0x00000010 */
#define I2C_IC_COMP_PARAM_1_HC_COUNT_VALUES_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_COMP_PARAM_1_HC_COUNT_VALUES_Pos) & \
     I2C_IC_COMP_PARAM_1_HC_COUNT_VALUES_Msk) /*!< HC_COUNT_VALUES Set Value            */
#define I2C_IC_COMP_PARAM_1_HC_COUNT_VALUES_Get(x)                \
    (((uint32_t) (x) &I2C_IC_COMP_PARAM_1_HC_COUNT_VALUES_Msk) >> \
     I2C_IC_COMP_PARAM_1_HC_COUNT_VALUES_Pos) /*!< HC_COUNT_VALUES Get Value            */


#define I2C_IC_COMP_PARAM_1_MAX_SPEED_MODE_Pos (2U) /*!< MAX_SPEED_MODE Postion   2          */
#define I2C_IC_COMP_PARAM_1_MAX_SPEED_MODE_Msk \
    (0x3U << I2C_IC_COMP_PARAM_1_MAX_SPEED_MODE_Pos) /*!< MAX_SPEED_MODE Mask      0x0000000C */
#define I2C_IC_COMP_PARAM_1_MAX_SPEED_MODE_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_COMP_PARAM_1_MAX_SPEED_MODE_Pos) & \
     I2C_IC_COMP_PARAM_1_MAX_SPEED_MODE_Msk) /*!< MAX_SPEED_MODE Set Value            */
#define I2C_IC_COMP_PARAM_1_MAX_SPEED_MODE_Get(x)                \
    (((uint32_t) (x) &I2C_IC_COMP_PARAM_1_MAX_SPEED_MODE_Msk) >> \
     I2C_IC_COMP_PARAM_1_MAX_SPEED_MODE_Pos) /*!< MAX_SPEED_MODE Get Value            */


#define I2C_IC_COMP_PARAM_1_APB_DATA_WIDTH_Pos (0U) /*!< APB_DATA_WIDTH Postion   0          */
#define I2C_IC_COMP_PARAM_1_APB_DATA_WIDTH_Msk \
    (0x3U << I2C_IC_COMP_PARAM_1_APB_DATA_WIDTH_Pos) /*!< APB_DATA_WIDTH Mask      0x00000003 */
#define I2C_IC_COMP_PARAM_1_APB_DATA_WIDTH_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_COMP_PARAM_1_APB_DATA_WIDTH_Pos) & \
     I2C_IC_COMP_PARAM_1_APB_DATA_WIDTH_Msk) /*!< APB_DATA_WIDTH Set Value            */
#define I2C_IC_COMP_PARAM_1_APB_DATA_WIDTH_Get(x)                \
    (((uint32_t) (x) &I2C_IC_COMP_PARAM_1_APB_DATA_WIDTH_Msk) >> \
     I2C_IC_COMP_PARAM_1_APB_DATA_WIDTH_Pos) /*!< APB_DATA_WIDTH Get Value            */


/* IC_COMP_VERSION bitfield */
#define I2C_IC_COMP_VERSION_IC_COMP_VERSION_Pos (0U) /*!< IC_COMP_VERSION Postion   0          */
#define I2C_IC_COMP_VERSION_IC_COMP_VERSION_Msk \
    (0xffffffffU << I2C_IC_COMP_VERSION_IC_COMP_VERSION_Pos) /*!< IC_COMP_VERSION Mask      0xFFFFFFFF */
#define I2C_IC_COMP_VERSION_IC_COMP_VERSION_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_COMP_VERSION_IC_COMP_VERSION_Pos) & \
     I2C_IC_COMP_VERSION_IC_COMP_VERSION_Msk) /*!< IC_COMP_VERSION Set Value            */
#define I2C_IC_COMP_VERSION_IC_COMP_VERSION_Get(x)                \
    (((uint32_t) (x) &I2C_IC_COMP_VERSION_IC_COMP_VERSION_Msk) >> \
     I2C_IC_COMP_VERSION_IC_COMP_VERSION_Pos) /*!< IC_COMP_VERSION Get Value            */


/* IC_COMP_TYPE bitfield */
#define I2C_IC_COMP_TYPE_IC_COMP_TYPE_Pos (0U) /*!< IC_COMP_TYPE Postion   0          */
#define I2C_IC_COMP_TYPE_IC_COMP_TYPE_Msk \
    (0xffffffffU << I2C_IC_COMP_TYPE_IC_COMP_TYPE_Pos) /*!< IC_COMP_TYPE Mask      0xFFFFFFFF */
#define I2C_IC_COMP_TYPE_IC_COMP_TYPE_Set(x)                 \
    (((uint32_t) (x) << I2C_IC_COMP_TYPE_IC_COMP_TYPE_Pos) & \
     I2C_IC_COMP_TYPE_IC_COMP_TYPE_Msk) /*!< IC_COMP_TYPE Set Value            */
#define I2C_IC_COMP_TYPE_IC_COMP_TYPE_Get(x)                \
    (((uint32_t) (x) &I2C_IC_COMP_TYPE_IC_COMP_TYPE_Msk) >> \
     I2C_IC_COMP_TYPE_IC_COMP_TYPE_Pos) /*!< IC_COMP_TYPE Get Value            */


/*!
 * @}
 */


/*!
 * @}
 */ /* end of HS32F7D377_I2C_PMBUS_REGISTER */

#endif /* HS32F7D377_I2C_PMBUS_H */
