/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_spi.h
 * \brief SDK SPI driver header file
 * \version 1.0.0
 */

#ifndef HTE_SPI_H
#define HTE_SPI_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_common.h"
#include "hte_dma.h"

/*!
 * \addtogroup DRV_HTE_SPI SPI Driver
 *
 * \brief SDK SPI driver
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! \brief SPI status codes */
enum
{
    kSTATUS_SPI_DIVISOR_OVERRANGE    = MAKE_STATUS(kSTATUSGROUP_SPI, 0U),  /*!< Divisor is out of the accepted range */
    kSTATUS_SPI_UNSUPPORTED_BAUDRATE = MAKE_STATUS(kSTATUSGROUP_SPI, 1U),  /*!< The baud rate is not supported */
    kSTATUS_SPI_BUSY                 = MAKE_STATUS(kSTATUSGROUP_SPI, 2U),  /*!< SPI is busy, and not configurable */
    kSTATUS_SPI_OVERRUN_ERROR        = MAKE_STATUS(kSTATUSGROUP_SPI, 3U),  /*!< Receiver overrun error */
    kSTATUS_SPI_PARITY_ERROR         = MAKE_STATUS(kSTATUSGROUP_SPI, 4U),  /*!< Parity error */
    kSTATUS_SPI_FRAMING_ERROR        = MAKE_STATUS(kSTATUSGROUP_SPI, 5U),  /*!< Framing error */
    kSTATUS_SPI_BREAK_DETECTED       = MAKE_STATUS(kSTATUSGROUP_SPI, 6U),  /*!< Break detected */
    kSTATUS_SPI_RX_TIMEOUT           = MAKE_STATUS(kSTATUSGROUP_SPI, 7U),  /*!< Timeout during receiving a byte */
    kSTATUS_SPI_TX_BUSY              = MAKE_STATUS(kSTATUSGROUP_SPI, 8U),  /*!< SPI transmitter is busy */
    kSTATUS_SPI_TX_IDLE              = MAKE_STATUS(kSTATUSGROUP_SPI, 9U),  /*!< SPI transmitter is idle */
    kSTATUS_SPI_RX_BUSY              = MAKE_STATUS(kSTATUSGROUP_SPI, 10U), /*!< SPI receiver is busy */
    kSTATUS_SPI_RX_IDLE              = MAKE_STATUS(kSTATUSGROUP_SPI, 11U), /*!< SPI receiver is idle */
    kSTATUS_SPI_MODEM_IRQ            = MAKE_STATUS(kSTATUSGROUP_SPI, 12U), /*!< MODEM IRQ is detected */
};

/*! \brief SPI Callback ID enumeration definition */
typedef enum
{
    kSPI_TX_CB_ID        = 0x00U, /*!< SPI Tx Transfer completed callback ID  */
    kSPI_RX_CB_ID        = 0x01U, /*!< SPI Rx Transfer completed callback ID  */
    kSPI_TXRX_CB_ID      = 0x02U, /*!< SPI Tx And RX Transfer completed callback ID   */
    kSPI_MSPINIT_CB_ID   = 0x03U, /*!< SPI Msp init callback ID  */
    kSPI_MSPDEINIT_CB_ID = 0x04U, /*!< SPI Msp Deinit callback ID   */
    kSPI_ERR_CB_ID       = 0x05U, /*!< SPI Err callback ID  */
    kSPI_CB_ID_MAX                /*!< SPI callback ID MAX */
} SPI_CallbackID_t;

/*!
 * \brief  SPI Configuration Structure definition
 */
typedef struct
{
    uint32_t mode; /*!< Specifies the SPI operating mode.
                          This parameter can be a value of ref: SPI_Mode */

    uint32_t frameFormat; /*!< Specifies the SPI frame format mode.
                                   This parameter can be a value of ref: SPI_Frame_Format */

    uint32_t direction; /*!< Specifies the SPI bidirectional mode state.
                               This parameter can be a value of ref: SPI_Direction */

    uint32_t enhanceFrameFormat; /*!< Specifies the SPI enhance frame format mode.
                                      This parameter can be a value of ref: SPI_Enhance_Frame_Format */

    uint32_t dataSize; /*!< Specifies the SPI data size.
                              This parameter can be a value of ref: SPI_Data_Size */

    uint32_t CLKPolarity; /*!< Specifies the serial clock steady state.
                                 This parameter can be a value of ref: SPI_Clock_Polarity */

    uint32_t CLKPhase; /*!< Specifies the clock active edge for the bit capture.
                              This parameter can be a value of ref: SPI_Clock_Phase */

    uint32_t slaveOutEn; /*!< Specifies slave out enable.
                                 This parameter can be a value of ref: SPI_Slave_Out_En */

    uint32_t selectToggleEn; /*!< Specifies whether the NSS signal is managed by
                                      hardware (NSS pin) or by software using the SSI bit.
                                      This parameter can be a value of
                                      ref: SPI_Slave_Select_Toggle_En */

    uint32_t loopBackEn; /*!< Specifies loop Back Enable.
                                 This parameter can be a value of ref: SPI_loopBack_En */

    uint32_t dynamicWaitEn; /*!< Specifies dynamic wait stats.
                                 This parameter can be a value of ref: SPI_Dynamic_Wait_En */

    uint32_t baudRatePrescaler; /*!< Specifies the Baud Rate prescaler value which will be
                                       used to configure the transmit and receive SCK clock.
                                       This parameter can be a value of ref: 2~65534
                                       @note The communication clock is derived from the master
                                       clock. The slave clock does not need to be set. */

    uint32_t txStartXferlevel; /*!< Specifies the tx start transmit level.
                                  This parameter can be a value of ref: 0 ~ 31 */

    uint32_t txFifoThreshold; /*!< Specifies the tx FIFO threshold level.
                                   This parameter can be a value of ref: 0~31 */

    uint32_t rxFifoThreshold; /*!< Specifies the rx FIFO threshold level.
                                   This parameter can be a value of ref: 0~256 */

    uint32_t numberOfDataFrame; /*!< Specifies the number of  data frame .
                                     This parameter can be a value of ref: 0~2^16 */

    uint32_t rxSampleDelay; /*!< Specifies the rx sample delay.
                                    This parameter can be a value of ref: 0~256 */

    uint32_t txDMALevel; /*!< Specifies transmit data level .
                          This parameter can be a value of ref: 0~31 */

    uint32_t rxDMALevel; /*!< Specifies receive data level .
                          This parameter can be a value of ref: 0~256 */

    uint32_t enhanceTransType; /*!< Specifies enhance spi mode : transfer type .
                                This parameter can be a value of ref: SPI_Enhance_Trans_Type */

    uint32_t enhanceAddrLens; /*!< Specifies enhance spi mode : address length
                                This parameter can be a value of ref: SPI_Enhance_Addr_Lens */

    uint32_t enhanceInstLens; /*!< Specifies enhance spi mode : instruction length
                                This parameter can be a value of ref: SPI_Enhance_Inst_Lens */

    uint32_t enhanceWaitCycles; /*!< Specifies enhance spi mode : wait cycles
                                This parameter can be a value of ref: 0~256 */

    uint32_t enhanceDDREn; /*!< Specifies enhance spi mode : dual-data transfer enable
                               This parameter can be a value of ref: SPI_Enhance_DDR_En */

    uint32_t enhanceInstDDREn; /*!< Specifies enhance spi mode : instruction dual-data ratr
                                This parameter can be a value of ref: SPI_Enhance_INST_DDR_En */

    uint32_t enhanceRxDsEn; /*!< Specifies enhance spi mode : read data stobe enable
                                   This parameter can be a value of ref: SPI_Enhance_RXDS_En */

    uint32_t enhanceDataMaskEn; /*!< Specifies enhance spi mode : data mask enbale
                                This parameter can be a value of ref: SPI_Enhance_DATA_MASK_En */

    uint32_t enhanceClkStrechEn; /*!< Specifies enhance spi mode : clock stretching capability
                                This parameter can be a value of ref: SPI_Enhance_CLK_STRETCH_En */

} SPI_InitTypeDef_t;

/*!
 * \brief  HAL SPI State structure definition
 */
typedef enum
{
    HAL_SPI_STATE_RESET      = 0x00UL, /*!< Peripheral not Initialized                         */
    HAL_SPI_STATE_READY      = 0x01UL, /*!< Peripheral Initialized and ready for use           */
    HAL_SPI_STATE_BUSY       = 0x02UL, /*!< an internal process is ongoing                     */
    HAL_SPI_STATE_BUSY_TX    = 0x03UL, /*!< Data Transmission process is ongoing               */
    HAL_SPI_STATE_BUSY_RX    = 0x04UL, /*!< Data Reception process is ongoing                  */
    HAL_SPI_STATE_BUSY_TX_RX = 0x05UL, /*!< Data Transmission and Reception process is ongoing */
    HAL_SPI_STATE_ERROR      = 0x06UL, /*!< SPI error state                                    */
    HAL_SPI_STATE_ABORT      = 0x07UL  /*!< SPI abort is ongoing                               */
} HAL_SPI_StateTypeDef;

/*!
 * \brief  SPI handle Structure definition
 */
typedef struct SPI_HandleTypeDef
{
    SPI_Type *instance; /*!< SPI registers base address               */

    SPI_InitTypeDef_t init; /*!< SPI communication parameters             */

    uint8_t *pTxBuffPtr; /*!< Pointer to SPI Tx transfer Buffer        */

    uint32_t txXferSize; /*!< SPI Tx Transfer size                     */

    __IO uint32_t txXferCount; /*!< SPI Tx Transfer Counter                  */

    uint8_t *pRxBuffPtr; /*!< Pointer to SPI Rx transfer Buffer        */

    uint32_t rxXferSize; /*!< SPI Rx Transfer size                     */

    __IO uint32_t rxXferCount; /*!< SPI Rx Transfer Counter                  */

    void (*rxISR)(struct SPI_HandleTypeDef *hspi); /*!< function pointer on Rx ISR               */

    void (*txISR)(struct SPI_HandleTypeDef *hspi); /*!< function pointer on Tx ISR               */

    uint8_t XIPClosedFlag; /*!< SPI XIP closed flag                      */

    DMA_Index_t spiDMATxIndex; /*!< SPI DMA Tx index                      */

    DMA_Index_t spiDMARxIndex; /*!< SPI DMA Rx index                      */

    int16_t spiDMAStep; /*!< SPI DMA step                      */

    uint8_t *spiDMATxDoneFlag; /*!< SPI DMA Tx done flag                      */

    uint8_t *spiDMARxDoneFlag; /*!< SPI XIP Rx done flag                      */

    __IO HAL_SPI_StateTypeDef state; /*!< SPI communication state                  */

    __IO uint32_t errorCode; /*!< SPI Error code                           */

    void (*txCpltCallback)(struct SPI_HandleTypeDef *hspi);    /*!< SPI Tx Completed callback          */
    void (*rxCpltCallback)(struct SPI_HandleTypeDef *hspi);    /*!< SPI Rx Completed callback          */
    void (*txRxCpltCallback)(struct SPI_HandleTypeDef *hspi);  /*!< SPI TxRx Completed callback        */
    void (*mspInitCallback)(struct SPI_HandleTypeDef *hspi);   /*!< SPI Msp Init callback              */
    void (*mspDeInitCallback)(struct SPI_HandleTypeDef *hspi); /*!< SPI Msp DeInit callback            */
    void (*errorCallback)(struct SPI_HandleTypeDef *hspi);     /*!< SPI Error callback                 */

} SPI_HandleTypeDef_t;

/*! \brief SPI index          */
typedef enum
{
    SPI_BUSA = 0, /*!< SPIA index          */
    SPI_BUSB = 1, /*!< SPIB index          */
    SPI_BUSC = 2, /*!< SPIC index          */
    SPI_BUS_MAX   /*!< SPI Max index          */
} SPI_BUS;

/*! \brief SPI Flag Status          */
typedef enum
{
    kSPI_RESET = 0,          /*!< SPI 0 status          */
    kSPI_SET   = !kSPI_RESET /*!< SPI 1 status          */
} SPI_flagStatus;

/*! \brief Type definition for the SPI transfer callback */
typedef void (*SPI_Callback_t)(SPI_HandleTypeDef_t *handle);

/*! \brief Type definition for the SPI interrupt service function */
typedef void (*SPI_ISR_t)(SPI_HandleTypeDef_t *handle);

/*!
 * \brief  Type definition for the SPI UNUSED function
 * \param[in]  var: unused data.
 */
#define SPI_UNUSED(var) \
    do                  \
    {                   \
        (void)var;      \
    } while (0)

/*!
 * \brief  Type definition for the SPI check BIT set function
 * \param[in]  REG: reg.
 * \param[in]  BIT: check set bit.
 * \return ture or flase.
 */
#define SPI_IS_BIT_SET(REG, BIT) (((REG) & (BIT)) == (BIT))


/*!
 * \brief  Type definition for the SPI check BIT clear function
 * \param[in]  REG: reg.
 * \param[in]  BIT: check clear bit.
 * \return ture or flase.
 */
#define SPI_IS_BIT_CLR(REG, BIT) (((REG) & (BIT)) == 0U)

/*!
 * \brief  Type definition for the SPI BIT set function
 * \param[in]  REG: reg.
 * \param[in]  BIT: set bit.
 * \return reg.
 */
#define SPI_SET_BIT(REG, BIT) ((REG) |= (BIT))

/*! \defgroup SPI_Error_Code SPI Error Codes */
#define HTE_SPI_ERROR_NONE             (0x00000000UL) /*!< No error                               */
#define HTE_SPI_ERROR_TXFIFO_EMPTY     (0x00000001UL) /*!< MODF error                             */
#define HTE_SPI_ERROR_TXFIFO_OVER      (0x00000002UL) /*!< CRC error                              */
#define HTE_SPI_ERROR_RXFIFO_UNDER     (0x00000004UL) /*!< OVR error                              */
#define HTE_SPI_ERROR_RXFIFO_OVER      (0x00000008UL) /*!< FRE error                              */
#define HTE_SPI_ERROR_RXFIFO_FULL      (0x00000010UL) /*!< DMA transfer error                     */
#define HTE_SPI_ERROR_MULTI_MASTER_CON (0x00000020UL) /*!< Error on RXP/TXP/DXP/FTLVL/FRLVL Flag  */
#define HTE_SPI_ERROR_XIP_RXFIFO_OVER  (0x00000040UL) /*!< Error during SPI Abort procedure       */
#define HTE_SPI_ERROR_TXFIFO_UNDER     (0x00000080UL) /*!< Underrun error                         */
#define HTE_SPI_ERROR_TIMEOUT          (0x00000100UL) /*!< timeOut error                          */
#define HTE_SPI_ERROR_UNKNOW           (0x00000200UL) /*!< Unknown error                          */
#define HTE_SPI_ERROR_NOT_SUPPORTED    (0x00000400UL) /*!< Requested operation not supported      */
#define HTE_SPI_ERROR_RELOAD           (0x00000800UL) /*!< Reload error                           */
#define HTE_SPI_ERROR_FLAG_ERR         (0x00001000UL) /*!< Reload error                           */
#define HTE_SPI_ERROR_TX_ERR           (0x00002000UL) /*!< Reload error                           */
#define HTE_SPI_ERROR_ABORT            (0x00004000UL) /*!< Reload error                           */
#define HTE_SPI_ERROR_DMA              (0x00008000UL) /*!< DMA transfer error                     */
#define HTE_SPI_ERROR_INVALID_CALLBACK (0x00010000UL) /*!<Invalid call back                     */

/*! \brief SPI_Mode SPI Mode */
#define SPI_MODE_SLAVE  (0x00000000UL) /*!< slave mode       */
#define SPI_MODE_MASTER (0x00000001UL) /*!< master mode      */

/*! \brief SPI_Frame_Format SPI frame format */
#define SPI_FRAME_FORMAT_MOTOROLA (0x00000000UL) /*!< motorola mode         */
#define SPI_FRAME_FORMAT_SSP      (0x00000001UL) /*!< ssp mode               */

/*! \brief SPI_Enhance_Frame_Format SPI enhance frame format */
#define SPI_ENHANCE_FRAME_FORMAT_STANDARD_SPI (0x00000000UL) /*!< enhance standard spi mode          */
#define SPI_ENHANCE_FRAME_FORMAT_DUAL_SPI     (0x00000001UL) /*!< enhance dual spi mode          */

/*! \brief SPI_Direction SPI Direction Mode */
#define SPI_DIRECTION_TX_AND_RX   (0x00000000UL) /*!< tx and rx mode           */
#define SPI_DIRECTION_TXONLY      (0x00000001UL) /*!< tx only mode              */
#define SPI_DIRECTION_RXONLY      (0x00000002UL) /*!< rx only mode              */
#define SPI_DIRECTION_EEPROM_READ (0x00000003UL) /*!< eeprom read mdoe              */

/*! \brief SPI_Data_Size SPI Data Size */
#define SPI_DATASIZE_4BIT  (0x00000003UL) /*!< 4 bit data              */
#define SPI_DATASIZE_5BIT  (0x00000004UL) /*!<5 bit data              */
#define SPI_DATASIZE_6BIT  (0x00000005UL) /*!<6 bit data              */
#define SPI_DATASIZE_7BIT  (0x00000006UL) /*!<7 bit data              */
#define SPI_DATASIZE_8BIT  (0x00000007UL) /*!<8 bit data              */
#define SPI_DATASIZE_9BIT  (0x00000008UL) /*!<9 bit data              */
#define SPI_DATASIZE_10BIT (0x00000009UL) /*!<10 bit data              */
#define SPI_DATASIZE_11BIT (0x0000000AUL) /*!<11 bit data              */
#define SPI_DATASIZE_12BIT (0x0000000BUL) /*!<12 bit data              */
#define SPI_DATASIZE_13BIT (0x0000000CUL) /*!<13 bit data              */
#define SPI_DATASIZE_14BIT (0x0000000DUL) /*!<14 bit data              */
#define SPI_DATASIZE_15BIT (0x0000000EUL) /*!<15 bit data              */
#define SPI_DATASIZE_16BIT (0x0000000FUL) /*!<16 bit data              */
#define SPI_DATASIZE_17BIT (0x00000010UL) /*!<17 bit data              */
#define SPI_DATASIZE_18BIT (0x00000011UL) /*!<18 bit data              */
#define SPI_DATASIZE_19BIT (0x00000012UL) /*!<19 bit data              */
#define SPI_DATASIZE_20BIT (0x00000013UL) /*!<20 bit data              */
#define SPI_DATASIZE_21BIT (0x00000014UL) /*!<21 bit data              */
#define SPI_DATASIZE_22BIT (0x00000015UL) /*!<22 bit data              */
#define SPI_DATASIZE_23BIT (0x00000016UL) /*!<23 bit data              */
#define SPI_DATASIZE_24BIT (0x00000017UL) /*!<24 bit data              */
#define SPI_DATASIZE_25BIT (0x00000018UL) /*!<25 bit data              */
#define SPI_DATASIZE_26BIT (0x00000019UL) /*!<26 bit data              */
#define SPI_DATASIZE_27BIT (0x0000001AUL) /*!<27 bit data              */
#define SPI_DATASIZE_28BIT (0x0000001BUL) /*!<28 bit data              */
#define SPI_DATASIZE_29BIT (0x0000001CUL) /*!<29 bit data              */
#define SPI_DATASIZE_30BIT (0x0000001DUL) /*!<30 bit data              */
#define SPI_DATASIZE_31BIT (0x0000001EUL) /*!<31 bit data              */
#define SPI_DATASIZE_32BIT (0x0000001FUL) /*!<32 bit data              */

/*! \brief SPI_Clock_Polarity SPI Clock Polarity */
#define SPI_POLARITY_LOW  (0x00000000UL) /*!< polarity low             */
#define SPI_POLARITY_HIGH (0x00000001UL) /*!< polarity high             */

/*! \brief SPI_Clock_Phase SPI Clock Phase */
#define SPI_PHASE_1EDGE (0x00000000UL) /*!< phase 1 edge             */
#define SPI_PHASE_2EDGE (0x00000001UL) /*!< phase 2 edge             */

/*! \brief SPI_Slave_Out_En SPI Slave Out Enbale */
#define SPI_SLVOUTEN_ENABLE  (0x00000000UL) /*!<slave out en enbale              */
#define SPI_SLVOUTEN_DISABLE (0x00000001UL) /*!<slave out en disable              */

/*! \brief SPI_Slave_Select_Toggle_En SPI Slave Select Toggle Enbale */
#define SPI_SSTE_DISABLE (0x00000000UL) /*!< Slave Select Toggle disable             */
#define SPI_SSTE_ENABLE  (0x00000001UL) /*!< Slave Select Toggle Enbale             */

/*! \brief SPI_loopBack_En SPI loop Back enable */
#define SPI_LOOPBACK_DISABLE (0x00000000UL) /*!< loopback disable             */
#define SPI_LOOPBACK_ENABLE  (0x00000001UL) /*!< loopback enable             */

/*! \brief SPI_Dynamic_Wait_En SPI dynamic wait enable */
#define SPI_DWS_DISABLE (0x00000000UL) /*!< dynamic wait disable             */
#define SPI_DWS_ENABLE  (0x00000001UL) /*!< dynamic wait enable             */

/*! \brief SPI_Rx_Sample_Edge SPI rx sample edge */
#define SPI_RX_SAMPLE_POSITIVE (0x00000000UL) /*!< rx sample edge is positive             */
#define SPI_RX_SAMPLE_NEGATIVE (0x00000001UL) /*!< rx sample edge is negative              */

/*! \brief SPI_Enhance_Trans_Type SPI enhance transfer type */
#define SPI_ENHANCE_TRANS_TYPE_TT0 (0x00000000UL) /*!<Instruction and Address will be sent in Standard SPI Mode. */
#define SPI_ENHANCE_TRANS_TYPE_TT1                                                                                     \
    (0x00000001UL) /*!<Instruction will be sent in Standard SPI Mode and Address will be sent in the mode specified by \
                    * CTRLR0.SPI_FRF*/
#define SPI_ENHANCE_TRANS_TYPE_TT2 \
    (0x00000002UL) /*!<Both Instruction and Address will be sent in the mode specified by SPI_FRF */

/*! \brief SPI_Enhance_Inst_Lens SPI enhance instruction length */
#define SPI_ENHANCE_INST_LENS_L0  (0x00000000UL) /*!<length 0 bit              */
#define SPI_ENHANCE_INST_LENS_L4  (0x00000001UL) /*!<length 4 bit              */
#define SPI_ENHANCE_INST_LENS_L8  (0x00000002UL) /*!<length 8 bit              */
#define SPI_ENHANCE_INST_LENS_L16 (0x00000003UL) /*!<length 16 bit              */

/*! \brief SPI_Enhance_Addr_Lens SPI enhance address length */
#define SPI_ENHANCE_ADDR_LENS_L0  (0x00000000UL) /*!< length 0 bit             */
#define SPI_ENHANCE_ADDR_LENS_L4  (0x00000001UL) /*!< length 4 bit             */
#define SPI_ENHANCE_ADDR_LENS_L8  (0x00000002UL) /*!< length 8 bit             */
#define SPI_ENHANCE_ADDR_LENS_L12 (0x00000003UL) /*!< length 12 bit             */
#define SPI_ENHANCE_ADDR_LENS_L16 (0x00000004UL) /*!< length 16 bit             */
#define SPI_ENHANCE_ADDR_LENS_L20 (0x00000005UL) /*!< length 20 bit             */
#define SPI_ENHANCE_ADDR_LENS_L24 (0x00000006UL) /*!< length 24 bit             */
#define SPI_ENHANCE_ADDR_LENS_L28 (0x00000007UL) /*!< length 28 bit             */
#define SPI_ENHANCE_ADDR_LENS_L32 (0x00000008UL) /*!< length 32 bit             */
#define SPI_ENHANCE_ADDR_LENS_L36 (0x00000009UL) /*!< length 36 bit             */
#define SPI_ENHANCE_ADDR_LENS_L40 (0x0000000AUL) /*!< length 40 bit             */
#define SPI_ENHANCE_ADDR_LENS_L44 (0x0000000BUL) /*!< length 44 bit             */
#define SPI_ENHANCE_ADDR_LENS_L48 (0x0000000CUL) /*!< length 48 bit             */
#define SPI_ENHANCE_ADDR_LENS_L52 (0x0000000DUL) /*!< length 52 bit             */
#define SPI_ENHANCE_ADDR_LENS_L56 (0x0000000EUL) /*!< length 56 bit             */
#define SPI_ENHANCE_ADDR_LENS_L60 (0x0000000FUL) /*!< length 60 bit             */

/*! \brief SPI_Enhance_DDR_En SPI enhance DDR enable */
#define SPI_ENHANCE_DDR_DISABLE (0x00000000UL) /*!<enhance DDR disable              */
#define SPI_ENHANCE_DDR_ENABLE  (0x00000001UL) /*!<enhance DDR enable              */


/*! \brief SPI_Enhance_INST_DDR_En SPI enhance INST DDR enable */
#define SPI_ENHANCE_INST_DDR_DISABLE (0x00000000UL) /*!<INST DDR disable              */
#define SPI_ENHANCE_INST_DDR_ENABLE  (0x00000001UL) /*!<INST DDR enable              */

/*! \brief SPI_Enhance_RXDS_En SPI enhance RXDS enable */
#define SPI_ENHANCE_RXDS_DISABLE (0x00000000UL) /*!<enhance RXDS disable              */
#define SPI_ENHANCE_RXDS_ENABLE  (0x00000001UL) /*!<enhance RXDS enable              */

/*! \brief SPI_Enhance_DATA_MASK_En SPI enhance data mask enable */
#define SPI_ENHANCE_DATA_MASK_DISABLE (0x00000000UL) /*!<enhance data mask disable              */
#define SPI_ENHANCE_DATA_MASK_ENABLE  (0x00000001UL) /*!<enhance data mask enable              */

/*! \brief SPI_Enhance_CLK_STRETCH_En SPI enhance clock stretch enable */
#define SPI_ENHANCE_CLK_STRETCH_DISABLE (0x00000000UL) /*!< clock stretch disable             */
#define SPI_ENHANCE_CLK_STRETCH_ENABLE  (0x00000001UL) /*!< clock stretch enable             */

/*! \brief SPI_Fifo_Threshold SPI Fifo Threshold */
#define SPI_MAX_TX_FIFO_LENGTH (32UL)  /*!< tx fifo max length             */
#define SPI_MAX_RX_FIFO_LENGTH (256UL) /*!< rx fifo max length             */

/*! \brief SPI_Master_SS_Idleness SPI Master SS Idleness */
#define SPI_MASTER_SS_IDLENESS_00CYCLE (0x00000000UL) /*!<SS Idleness 0 cycle              */
#define SPI_MASTER_SS_IDLENESS_01CYCLE (0x00000001UL) /*!<SS Idleness 1 cycle              */
#define SPI_MASTER_SS_IDLENESS_02CYCLE (0x00000002UL) /*!<SS Idleness 2 cycle              */
#define SPI_MASTER_SS_IDLENESS_03CYCLE (0x00000003UL) /*!<SS Idleness 3 cycle              */
#define SPI_MASTER_SS_IDLENESS_04CYCLE (0x00000004UL) /*!<SS Idleness 4 cycle              */
#define SPI_MASTER_SS_IDLENESS_05CYCLE (0x00000005UL) /*!<SS Idleness 5 cycle              */
#define SPI_MASTER_SS_IDLENESS_06CYCLE (0x00000006UL) /*!<SS Idleness 6 cycle              */
#define SPI_MASTER_SS_IDLENESS_07CYCLE (0x00000007UL) /*!<SS Idleness 7 cycle              */
#define SPI_MASTER_SS_IDLENESS_08CYCLE (0x00000008UL) /*!<SS Idleness 8 cycle              */
#define SPI_MASTER_SS_IDLENESS_09CYCLE (0x00000009UL) /*!<SS Idleness 9 cycle              */
#define SPI_MASTER_SS_IDLENESS_10CYCLE (0x0000000AUL) /*!<SS Idleness 10 cycle              */
#define SPI_MASTER_SS_IDLENESS_11CYCLE (0x0000000BUL) /*!<SS Idleness 11 cycle              */
#define SPI_MASTER_SS_IDLENESS_12CYCLE (0x0000000CUL) /*!<SS Idleness 12 cycle              */
#define SPI_MASTER_SS_IDLENESS_13CYCLE (0x0000000DUL) /*!<SS Idleness 13 cycle              */
#define SPI_MASTER_SS_IDLENESS_14CYCLE (0x0000000EUL) /*!<SS Idleness 14 cycle              */
#define SPI_MASTER_SS_IDLENESS_15CYCLE (0x0000000FUL) /*!<SS Idleness 15 cycle              */

/*! \brief SPI_Interrupt_definition SPI Interrupt Definition */
#define SPI_IT_TXE   (0x00000001UL) /*!<SPI interrupt mask : Transmit FIFO empty */
#define SPI_IT_TXO   (0x00000002UL) /*!<SPI interrupt mask : Transmit FIFO overflow */
#define SPI_IT_RXU   (0x00000004UL) /*!<SPI interrupt mask : Receive FIFO underflow */
#define SPI_IT_RXO   (0x00000008UL) /*!<SPI interrupt mask : Receive FIFO overflow */
#define SPI_IT_RXF   (0x00000010UL) /*!<SPI interrupt mask : Receive FIFO full */
#define SPI_IT_MST   (0x00000020UL) /*!<SPI interrupt mask : Multi-Master connection */
#define SPI_IT_XRXO  (0x00000040UL) /*!<SPI interrupt mask : XIP receive FIFO overflow */
#define SPI_IT_TXU   (0x00000080UL) /*!<SPI interrupt mask : Transmit FIFO underflow */
#define SPI_IT_AXI   (0x00000100UL) /*!<SPI interrupt mask : AXI error */
#define SPI_IT_SPITE (0x00000400UL) /*!<SPI interrupt mask : Transmit error */
#define SPI_IT_DONE  (0x00000800UL) /*!<SPI interrupt mask : spi done */
#define SPI_IT_ERR \
    (SPI_IT_TXO | SPI_IT_RXU | SPI_IT_RXO | SPI_IT_TXU | SPI_IT_MST | SPI_IT_XRXO) /*!<SPI interrupt all mask*/

/*! \brief SPI_Flags_definition SPI Flags Definition */
#define SPI_FLAG_BUSY (0x00000001UL) /*!<SPI status flag : SPI Busy                */
#define SPI_FLAG_TFNF (0x00000002UL) /*!<SPI status flag : Transmit FIFO not Full                 */
#define SPI_FLAG_TFE  (0x00000004UL) /*!<SPI status flag : Transmit FIFO empty           */
#define SPI_FLAG_RFNE (0x00000008UL) /*!<SPI status flag : Receive FIFO not empty                       */
#define SPI_FLAG_RFF  (0x00000010UL) /*!<SPI status flag : Receive FIFO Full                     */
#define SPI_FLAG_TXE  (0x00000020UL) /*!<SPI status flag : Transmission Error        */
#define SPI_FLAG_DCOL (0x00000040UL) /*!<SPI Error flag  : Data collision Error                       */


/*! \brief SPI_DMA_Control SPI DMACR */
#define SPI_DMACR_RDMAE (0x00000001UL) /*!<Receive DMA Enable */
#define SPI_DMACR_TDMAE (0x00000002UL) /*!<transmit DMA Enable */

/*!
 * \brief  SPI Instance
 * \param[in]  INSTANCE: spi instance.
 * \return true or false.
 */
#define IS_SPI_ALL_INSTANCE(INSTANCE) (((INSTANCE) == SPIA) || ((INSTANCE) == SPIB) || ((INSTANCE) == SPIC))


/*!
 * \brief  Enable the specified SPI interrupts.
 * \param[in]  __HANDLE__: specifies the SPI Handle.
 *         This parameter can be SPI where x: 1, 2, 3, 4, 5 or 6 to select the SPI peripheral.
 * \param[in]  __INTERRUPT__: specifies the interrupt source to enable or disable.
 *         This parameter can be one of the following values:
 *            SPI_Interrupt_definition
 *
 */
#define HTE_SPI_ENABLE_IT(__HANDLE__, __INTERRUPT__) ((__HANDLE__)->instance->IMR |= (__INTERRUPT__))

/*!
 * \brief  Disable the specified SPI interrupts.
 * \param[in]  __HANDLE__: specifies the SPI Handle.
 *         This parameter can be SPI where x: 1, 2, 3, 4, 5 or 6 to select the SPI peripheral.
 * \param[in]  __INTERRUPT__: specifies the interrupt source to enable or disable.
 *         This parameter can be one of the following values:
 *            SPI_Interrupt_definition
 *
 */
#define HTE_SPI_DISABLE_IT(__HANDLE__, __INTERRUPT__) ((__HANDLE__)->instance->IMR &= (~(__INTERRUPT__)))

/*!
 * \brief  Check whether the specified SPI interrupt source is enabled or not.
 * \param[in]  __HANDLE__: specifies the SPI Handle.
 *         This parameter can be SPI where x: 1, 2, 3, 4, 5 or 6 to select the SPI peripheral.
 * \param[in]  __INTERRUPT__: specifies the SPI interrupt source to check.
 *          This parameter can be one of the following values:
 *            SPI_Interrupt_definition
 * \return The new state of __IT__ (TRUE or FALSE).
 */
#define HTE_SPI_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__) \
    ((((__HANDLE__)->instance->IER & (__INTERRUPT__)) == (__INTERRUPT__)) ? 1 : 0)

/*!
 * \brief  Check whether the specified SPI flag is set or not.
 * \param[in]  __HANDLE__: specifies the SPI Handle.
 *         This parameter can be SPI where x: 1, 2, 3, 4, 5 or 6 to select the SPI peripheral.
 * \param[in]  __FLAG__: specifies the flag to check.
 *         This parameter can be one of the following values:
 *            SPI_FLAG_BUSY    : Rx-Packet available flag
 *            SPI_FLAG_TFNF    : Tx-Packet space available flag
 *            SPI_FLAG_TFE    : Duplex Packet flag
 *            SPI_FLAG_RFNE    : End of transfer flag
 *            SPI_FLAG_RFF   : Transmission Transfer Filled flag
 *            SPI_FLAG_TXE    : Underrun flag
 *            SPI_FLAG_DCOL    : Overrun flag
 * \return The new state of __FLAG__ (TRUE or FALSE).
 */
#define HTE_SPI_GET_FLAG(__HANDLE__, __FLAG__) ((((__HANDLE__)->instance->SR) & (__FLAG__)) == (__FLAG__))

/*!
 * \brief  Enable the SPI peripheral.
 * \param[in]  __HANDLE__: specifies the SPI Handle.
 *
 */
#define HTE_SPI_ENABLE(__HANDLE__) ((__HANDLE__)->instance->SPIENR = SPI_SPIENR_SPIC_EN_Set(1U))

/*!
 * \brief  Disable the SPI peripheral.
 * \param[in]  __HANDLE__: specifies the SPI Handle.
 *
 */
#define HTE_SPI_DISABLE(__HANDLE__) ((__HANDLE__)->instance->SPIENR &= ~SPI_SPIENR_SPIC_EN_Set(1U))

/*!
 * \brief  Check SPI mode.
 * \param[in]  MODE: spi mode.
 *
 */
#define IS_SPI_MODE(MODE) (((MODE) == SPI_MODE_SLAVE) || ((MODE) == SPI_MODE_MASTER))

/*!
 * \brief  Check SPI direction
 * \param[in]  MODE: spi tx mode.
 *
 */
#define IS_SPI_DIRECTION_TX_SUPPORT(MODE) (((MODE) == SPI_DIRECTION_TX_AND_RX) || ((MODE) == SPI_DIRECTION_TXONLY))

/*!
 * \brief  Check SPI direction
 * \param[in]  MODE: spi rx mode.
 *
 */
#define IS_SPI_DIRECTION_RX_SUPPORT(MODE) \
    (((MODE) == SPI_DIRECTION_TX_AND_RX) || ((MODE) == SPI_DIRECTION_RXONLY) || ((MODE) == SPI_DIRECTION_EEPROM_READ))

/*!
 * \brief  Check SPI format
 * \param[in]  MODE: spi frame mode.
 *
 */
#define IS_SPI_FRAMEFORMAT(MODE) (((MODE) == SPI_FRAME_FORMAT_MOTOROLA) || ((MODE) == SPI_FRAME_FORMAT_SSP))


/*!
 * \brief  Check SPI enhance format
 * \param[in]  MODE: spi enhance frame mode.
 *
 */
#define IS_SPI_ENHANCE_FRAMEFORMAT(MODE) \
    (((MODE) == SPI_ENHANCE_FRAME_FORMAT_STANDARD_SPI) || ((MODE) == SPI_ENHANCE_FRAME_FORMAT_DUAL_SPI))


/*!
 * \brief  Check SPI direction
 * \param[in]  MODE: spi transmit mode.
 *
 */
#define IS_SPI_DIRECTION(MODE)                                                                                      \
    (((MODE) == SPI_DIRECTION_TX_AND_RX) || ((MODE) == SPI_DIRECTION_TXONLY) || ((MODE) == SPI_DIRECTION_RXONLY) || \
     ((MODE) == SPI_DIRECTION_EEPROM_READ))

/*!
 * \brief  Check SPI direction
 * \param[in]  MODE: spi transmit mode.
 *
 */
#define IS_SPI_DIRECTION_2LINES(MODE) (((MODE) == SPI_DIRECTION_TX_AND_RX) || ((MODE) == SPI_DIRECTION_EEPROM_READ))

/*!
 * \brief  Check SPI datasize
 * \param[in]  DATASIZE: spi data size.
 *
 */
#define IS_SPI_DATASIZE(DATASIZE)                                                                                      \
    (((DATASIZE) == SPI_DATASIZE_32BIT) || ((DATASIZE) == SPI_DATASIZE_31BIT) || ((DATASIZE) == SPI_DATASIZE_30BIT) || \
     ((DATASIZE) == SPI_DATASIZE_29BIT) || ((DATASIZE) == SPI_DATASIZE_28BIT) || ((DATASIZE) == SPI_DATASIZE_27BIT) || \
     ((DATASIZE) == SPI_DATASIZE_26BIT) || ((DATASIZE) == SPI_DATASIZE_25BIT) || ((DATASIZE) == SPI_DATASIZE_24BIT) || \
     ((DATASIZE) == SPI_DATASIZE_23BIT) || ((DATASIZE) == SPI_DATASIZE_22BIT) || ((DATASIZE) == SPI_DATASIZE_21BIT) || \
     ((DATASIZE) == SPI_DATASIZE_20BIT) || ((DATASIZE) == SPI_DATASIZE_22BIT) || ((DATASIZE) == SPI_DATASIZE_19BIT) || \
     ((DATASIZE) == SPI_DATASIZE_18BIT) || ((DATASIZE) == SPI_DATASIZE_17BIT) || ((DATASIZE) == SPI_DATASIZE_16BIT) || \
     ((DATASIZE) == SPI_DATASIZE_15BIT) || ((DATASIZE) == SPI_DATASIZE_14BIT) || ((DATASIZE) == SPI_DATASIZE_13BIT) || \
     ((DATASIZE) == SPI_DATASIZE_12BIT) || ((DATASIZE) == SPI_DATASIZE_11BIT) || ((DATASIZE) == SPI_DATASIZE_10BIT) || \
     ((DATASIZE) == SPI_DATASIZE_9BIT) || ((DATASIZE) == SPI_DATASIZE_8BIT) || ((DATASIZE) == SPI_DATASIZE_7BIT) ||    \
     ((DATASIZE) == SPI_DATASIZE_6BIT) || ((DATASIZE) == SPI_DATASIZE_5BIT) || ((DATASIZE) == SPI_DATASIZE_4BIT))

/*!
 * \brief  Check SPI polarity
 * \param[in]  CPOL: polarity mode.
 *
 */
#define IS_SPI_CPOL(CPOL) (((CPOL) == SPI_POLARITY_LOW) || ((CPOL) == SPI_POLARITY_HIGH))

/*!
 * \brief  Check SPI phase
 * \param[in]  CPHA: phase mode.
 *
 */
#define IS_SPI_CPHA(CPHA) (((CPHA) == SPI_PHASE_1EDGE) || ((CPHA) == SPI_PHASE_2EDGE))


/*!
 * \brief  Check SPI prescaler
 * \param[in]  PRESCALER: prescaler data.
 *
 */
#define IS_SPI_BAUDRATE_PRESCALER(PRESCALER) (((PRESCALER % 2) == 0) && (PRESCALER < 65536))

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! \brief Array of SPI transfer handle */
extern SPI_HandleTypeDef_t g_spiHandle[SPI_BUS_MAX];
/*! \brief Array of SPI peripheral base address */
extern SPI_Type           *g_spiBases[SPI_BUS_MAX];
/*! \brief Array of SPI IRQ number */
extern const IRQn_Type g_spiIRQ[SPI_BUS_MAX];

/*******************************************************************************
 * APIs
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Get SPI instance using the spi bus
 *
 * \details This function converts SPI base address to SPI instance which is an unsigned integer value. 0,1,2,3,...
 * stands for the peripheral with suffix A,B,C,D...
 *
 * \param[in] spiBus: 0 1 2 ...
 *
 * \return The SPI handle
 */
SPI_HandleTypeDef_t *SPI_getHandle(uint32_t spiBus);

/*!
 * \brief Get SPI instance using the spi bus
 *
 * \details This function converts SPI base address to SPI instance which is an unsigned integer value. 0,1,2,3,...
 * stands for the peripheral with suffix A,B,C,D...
 *
 * \param[in] spiBus: 0 1 2 ...
 *
 * \return The SPI instance
 */
SPI_Type *SPI_getInstance(uint32_t spiBus);

/*!
 * \brief Register user callback function to a specified SPI for non-blocking transfer
 *
 * \details This function registers user callback function for non-blocking transfer which uses IRQ. The relative IRQ
 will be enabled in the NVIC and the priority will be configured at the same time

 * \param[in] hspi: pointer to a SPI_HandleTypeDef_t structure that contains
 *               the configuration information for SPI module.
 * \param[in] pCallback SPI user callback
 * \param[in] CpltID callback ID
 *
 * \return kSTATUS_SUCCESS Success to the operation
 * \return kSTATUS_FAIL Register to a SPI which has been registered already. Need to call \ref
    SPI_unregisterCallback() before the re-registration
 */
status_t SPI_registerCallback(SPI_HandleTypeDef_t *hspi, SPI_CallbackID_t CpltID, SPI_Callback_t pCallback);

/*!
 * \brief Unregister user callback function to a specified SPI for non-blocking transfer
 *
 * \details This function clears the registered user callback function, and disable the relative IRQ in the NVIC
 * \param[in]  hspi: pointer to a SPI_HandleTypeDef_t structure that contains
 *               the configuration information for SPI module.
 * \param[in]  CpltID: Call back ID.
 * \return kSTATUS_SUCCESS Success to the operation
 * \return kSTATUS_FAIL The SPI hasn't been registered to a callback
 *
 */
status_t SPI_unregisterCallback(SPI_HandleTypeDef_t *hspi, SPI_CallbackID_t CpltID);

/*!
 * \brief  Get the SPI according to the default parameters
 *         in the SPI_InitTypeDef and initialize the associated handle.
 * \param[in]  hspi: pointer to a SPI_HandleTypeDef_t structure that contains
 *               the configuration information for SPI module.
 * \return status_t
 */
status_t SPI_getDefaultCfg(SPI_HandleTypeDef_t *hspi);

/*!
 * \brief  Initialize the SPI according to the specified parameters
 *         in the SPI_InitTypeDef and initialize the associated handle.
 * \param[in]  hspi: pointer to a SPI_HandleTypeDef_t structure that contains
 *               the configuration information for SPI module.
 * \return status_t
 */
status_t SPI_init(SPI_HandleTypeDef_t *hspi);

/*!
 * \brief  De-Initialize the SPI peripheral.
 * \param[in]  hspi: pointer to a SPI_HandleTypeDef_t structure that contains
 *               the configuration information for SPI module.
 * \return status_t
 */
status_t SPI_deInit(SPI_HandleTypeDef_t *hspi);

/*!
 * \brief  Initialize the SPI MSP.
 * \param[in]  hspi: pointer to a SPI_HandleTypeDef_t structure that contains
 *               the configuration information for SPI module.
 *
 */
void     SPI_mspInit(SPI_HandleTypeDef_t *hspi);

/*!
 * \brief  De-Initialize the SPI MSP.
 * \param[in]  hspi: pointer to a SPI_HandleTypeDef_t structure that contains
 *               the configuration information for SPI module.
 *
 */
void     SPI_mspDeInit(SPI_HandleTypeDef_t *hspi);

/*!
 * \brief  Transmit an amount of data in blocking mode.
 * \param[in]  hspi   : pointer to a SPI_HandleTypeDef_t structure that contains
 *                  the configuration information for SPI module.
 * \param[in]  pData  : pointer to data buffer
 * \param[in]  size   : amount of data to be sent
 * \param[in]  timeOut: timeOut duration
 * \return status_t
 */
status_t SPI_transmit(SPI_HandleTypeDef_t *hspi, uint8_t *pData, uint32_t size, uint32_t timeOut);

/*!
 * \brief  Receive an amount of data in blocking mode.
 * \param[in]  hspi   : pointer to a SPI_HandleTypeDef_t structure that contains
 *                  the configuration information for SPI module.
 * \param[in]  pData  : pointer to data buffer
 * \param[in]  size   : amount of data to be received
 * \param[in]  timeOut: timeOut duration
 * \return status_t
 */
status_t SPI_receive(SPI_HandleTypeDef_t *hspi, uint8_t *pData, uint32_t size, uint32_t timeOut);

/*!
 * \brief  Transmit and Receive an amount of data in blocking mode.
 * \param[in]  hspi   : pointer to a SPI_HandleTypeDef_t structure that contains
 *                  the configuration information for SPI module.
 * \param[in]  pTxData: pointer to transmission data buffer
 * \param[in]  pRxData: pointer to reception data buffer
 * \param[in]  size   : amount of data to be sent and received
 * \param[in]  timeOut: timeOut duration
 * \return status_t
 */
status_t SPI_transmitReceive(SPI_HandleTypeDef_t *hspi, uint8_t *pTxData, uint8_t *pRxData, uint32_t size,
                             uint32_t timeOut);

/*!
 * \brief  Transmit an amount of data in non-blocking mode with Interrupt.
 * \param[in]  hspi : pointer to a SPI_HandleTypeDef_t structure that contains
 *                the configuration information for SPI module.
 * \param[in]  pData: pointer to data buffer
 * \param[in]  size : amount of data to be sent
 * \return status_t
 */
status_t SPI_transmitIT(SPI_HandleTypeDef_t *hspi, uint8_t *pData, uint32_t size);

/*!
 * \brief  Receive an amount of data in non-blocking mode with Interrupt.
 * \param[in]  hspi : pointer to a SPI_HandleTypeDef_t structure that contains
 *                the configuration information for SPI module.
 * \param[in]  pData: pointer to data buffer
 * \param[in]  size : amount of data to be sent
 * \return status_t
 */
status_t SPI_receiveIT(SPI_HandleTypeDef_t *hspi, uint8_t *pData, uint32_t size);

/*!
 * \brief  Transmit and Receive an amount of data in non-blocking mode with Interrupt.
 * \param[in]  hspi   : pointer to a SPI_HandleTypeDef_t structure that contains
 *                  the configuration information for SPI module.
 * \param[in]  pTxData: pointer to transmission data buffer
 * \param[in]  pRxData: pointer to reception data buffer
 * \param[in]  size   : amount of data to be sent and received
 * \return status_t
 */
status_t SPI_transmitReceiveIT(SPI_HandleTypeDef_t *hspi, uint8_t *pTxData, uint8_t *pRxData, uint32_t size);

/*!
 * \brief  Init Transmit an amount of data in non-blocking mode with DMA.
 * \param[in]  hspi : pointer to a SPI_HandleTypeDef_t structure that contains
 *                the configuration information for SPI module.
 * \param[in]  DMAIndex: DMA index to send data
 * \param[in]  pData: pointer to data buffer
 * \param[in]  size : amount of data to be sent
 * \return HAL status
 */
status_t SPI_transmitDMAInit(SPI_HandleTypeDef_t *hspi, DMA_Index_t DMAIndex, uint8_t *pData, uint32_t size);

/*!
 * \brief  Transmit an amount of data in non-blocking mode with DMA.
 * \param[in]  hspi : pointer to a SPI_HandleTypeDef_t structure that contains
 *                the configuration information for SPI module.
 * \param[in]  pData: pointer to data buffer
 * \param[in]  size : amount of data to be sent
 * \param[in]  timeOut : timeout to be sent
 * \return status_t
 */
status_t SPI_transmitDMA(SPI_HandleTypeDef_t *hspi, uint8_t *pData, uint32_t size, uint32_t timeOut);
/*!
 * \brief  Receive an amount of data in non-blocking mode with DMA.
 * \param[in]  hspi : pointer to a SPI_HandleTypeDef_t structure that contains
 *                the configuration information for SPI module.
 * \param[in]  DMAIndex: DMA index to send data
 * \param[in]  pData: pointer to data buffer
 * \param[in]  size : amount of data to be sent
 * \return status_t
 */
status_t SPI_receiveDMAInit(SPI_HandleTypeDef_t *hspi, DMA_Index_t DMAIndex, uint8_t *pData, uint32_t size);
/*!
 * \brief  Receive an amount of data in non-blocking mode with DMA.
 * \param[in]  hspi : pointer to a SPI_HandleTypeDef_t structure that contains
 *                the configuration information for SPI module.
 * \param[in]  pData: pointer to data buffer
 * \param[in]  size : amount of data to be sent
 * \param[in]  timeOut : timeout to be sent
 * \return status_t
 */
status_t SPI_receiveDMA(SPI_HandleTypeDef_t *hspi, uint8_t *pData, uint32_t size, uint32_t timeOut);
/*!
 * \brief  Transmit and Receive an amount of data in non-blocking mode with DMA.
 * \param[in]  hspi   : pointer to a SPI_HandleTypeDef_t structure that contains
 *                  the configuration information for SPI module.
 * \param[in]  txDMAIndex: DMA index to send data
 * \param[in]  pTxData: pointer to transmission data buffer
 * \param[in]  rxDMAIndex: DMA index to send data
 * \param[in]  pRxData: pointer to reception data buffer
 * \param[in]  size   : amount of data to be sent
 * \return status_t
 */
status_t SPI_transmitReceiveDMAInit(SPI_HandleTypeDef_t *hspi, DMA_Index_t txDMAIndex, uint8_t *pTxData,
                                    DMA_Index_t rxDMAIndex, uint8_t *pRxData, uint32_t size);
/*!
 * \brief  Transmit and Receive an amount of data in non-blocking mode with DMA.
 * \param[in]  hspi   : pointer to a SPI_HandleTypeDef_t structure that contains
 *                  the configuration information for SPI module.
 * \param[in]  pTxData: pointer to transmission data buffer
 * \param[in]  pRxData: pointer to reception data buffer
 * \param[in]  size   : amount of data to be sent
 * \param[in]  timeOut : timeout to be sent
 * \return status_t
 */
status_t SPI_transmitReceiveDMA(SPI_HandleTypeDef_t *hspi, uint8_t *pTxData, uint8_t *pRxData, uint32_t size,
                                uint32_t timeOut);
/*!
 * \brief  Pause the DMA Transfer.
 *         This API is not supported, it is maintained for backward compatibility.
 * \param[in]  hspi: pointer to a SPI_HandleTypeDef_t structure that contains
 *               the configuration information for the specified SPI module.
 * \return kSTATUS_FAIL
 */
status_t SPI_DMAPause(SPI_HandleTypeDef_t *hspi);

/*!
 * \brief  Abort ongoing transfer (Interrupt mode).
 * \param[in]  hspi SPI handle.
 * \note   This procedure could be used for aborting any ongoing transfer (Tx and Rx),
 *         started in Interrupt or DMA mode.
 * \note   This procedure performs following operations :
 *          + Disable SPI Interrupts (depending of transfer direction)
 *          + Disable the DMA transfer in the peripheral register (if enabled)
 *          + Abort DMA transfer by calling HAL_DMA_Abort_IT (in case of transfer in DMA mode)
 *          + Set handle State to READY
 *          + At abort completion, call user abort complete callback.
 * \note   This procedure is executed in Interrupt mode, meaning that abort procedure could be
 *         considered as completed only when user abort complete callback is executed (not when exiting function).
 * \return status_t
 */
status_t SPI_DMAResume(SPI_HandleTypeDef_t *hspi);

/*!
 * \brief  Stop the DMA Transfer.
 *         This API is not supported, it is maintained for backward compatibility.
 * \param[in]  hspi: pointer to a SPI_HandleTypeDef_t structure that contains
 *               the configuration information for the specified SPI module.
 * \return kSTATUS_FAIL
 */
status_t SPI_DMAStop(SPI_HandleTypeDef_t *hspi);

/*!
 * \brief  Abort ongoing transfer (blocking mode).
 * \param[in]  hspi SPI handle.
 * \note   This procedure could be used for aborting any ongoing transfer (Tx and Rx),
 *         started in Interrupt or DMA mode.
 * \note   This procedure performs following operations :
 *          + Disable SPI Interrupts (depending of transfer direction)
 *          + Disable the DMA transfer in the peripheral register (if enabled)
 *          + Abort DMA transfer by calling HAL_DMA_Abort (in case of transfer in DMA mode)
 *          + Set handle State to READY.
 * \note   This procedure is executed in blocking mode : when exiting function, Abort is considered as completed.
 * \return status_t
 */
status_t SPI_abort(SPI_HandleTypeDef_t *hspi);

/*!
 * \brief  Abort ongoing transfer (noblocking mode).
 * \param[in]  hspi SPI handle.
 * \note   This procedure could be used for aborting any ongoing transfer (Tx and Rx),
 *         started in Interrupt or DMA mode.
 * \note   This procedure performs following operations :
 *          + Disable SPI Interrupts (depending of transfer direction)
 *          + Disable the DMA transfer in the peripheral register (if enabled)
 *          + Abort DMA transfer by calling HAL_DMA_Abort (in case of transfer in DMA mode)
 *          + Set handle State to READY.
 * \note   This procedure is executed in blocking mode : when exiting function, Abort is considered as completed.
 * \return status_t
 */
status_t SPI_abortIT(SPI_HandleTypeDef_t *hspi);

/*!
 * \brief Tx Transfer completed callback.
 * \param[in]  hspi: pointer to a SPI_HandleTypeDef_t structure that contains
 *               the configuration information for SPI module.
 *
 */
void SPI_txCpltCallback(SPI_HandleTypeDef_t *hspi);

/*!
 * \brief Rx Transfer completed callback.
 * \param[in]  hspi: pointer to a SPI_HandleTypeDef_t structure that contains
 *               the configuration information for SPI module.
 *
 */
void SPI_rxCpltCallback(SPI_HandleTypeDef_t *hspi);

/*!
 * \brief Tx and Rx Transfer completed callback.
 * \param[in]  hspi: pointer to a SPI_HandleTypeDef_t structure that contains
 *               the configuration information for SPI module.
 *
 */
void SPI_txRxCpltCallback(SPI_HandleTypeDef_t *hspi);

/*!
 * \brief SPI error callback.
 * \param[in]  hspi: pointer to a SPI_HandleTypeDef_t structure that contains
 *               the configuration information for SPI module.
 *
 */
void SPI_errorCallback(SPI_HandleTypeDef_t *hspi);

/*!
 * \brief  Return the SPI handle state.
 * \param[in]  hspi: pointer to a SPI_HandleTypeDef_t structure that contains
 *               the configuration information for SPI module.
 * \return SPI state
 */
HAL_SPI_StateTypeDef SPI_getState(SPI_HandleTypeDef_t *hspi);

/*!
 * \brief  Return the SPI error code.
 * \param[in]  hspi: pointer to a SPI_HandleTypeDef_t structure that contains
 *               the configuration information for SPI module.
 * \return SPI error code in bitmap format
 */
uint32_t SPI_getError(SPI_HandleTypeDef_t *hspi);

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */

#endif /*!<HTE_SPI_H */
