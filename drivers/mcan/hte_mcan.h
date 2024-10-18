/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_mcan.h
 * \brief SDK MCAN driver header file
 * \version 1.0.0
 */

#ifndef HTE_MCAN_H
#define HTE_MCAN_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_common.h"

/*!
 * \addtogroup DRV_HTE_MCAN MCAN Driver
 *
 * \brief SDK MCAN driver
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*!
 * \brief    Macro defines mask for all the interrupts status for MCAN.
 */
#define MCAN_INTR_MASK_ALL                                                                                             \
    (MCAN_IR_RF0N_Msk | MCAN_IR_RF0W_Msk | MCAN_IR_RF0F_Msk | MCAN_IR_RF0L_Msk | MCAN_IR_RF1N_Msk | MCAN_IR_RF1W_Msk | \
     MCAN_IR_RF1F_Msk | MCAN_IR_RF1L_Msk | MCAN_IR_HPM_Msk | MCAN_IR_TC_Msk | MCAN_IR_TCF_Msk | MCAN_IR_TFE_Msk |      \
     MCAN_IR_TEFN_Msk | MCAN_IR_TEFW_Msk | MCAN_IR_TEFF_Msk | MCAN_IR_TEFL_Msk | MCAN_IR_TSW_Msk | MCAN_IR_MRAF_Msk |  \
     MCAN_IR_TOO_Msk | MCAN_IR_DRX_Msk | MCAN_IR_BEC_Msk | MCAN_IR_BEU_Msk | MCAN_IR_ELO_Msk | MCAN_IR_EP_Msk |        \
     MCAN_IR_EW_Msk | MCAN_IR_BO_Msk | MCAN_IR_WDI_Msk | MCAN_IR_PEA_Msk | MCAN_IR_PED_Msk | MCAN_IR_ARA_Msk)

/*!
 * \brief    Maximum payload supported by CAn-FD protocol in bytes.
 */
#define MCAN_MAX_PAYLOAD_BYTES (64U)

/*! \brief type definition for MCAN callback  */
typedef void (*MCAN_Callback_t)(MCAN_Type *base);

/*!
 *  \brief    Enum to select the MCAN source
 */
typedef enum
{
    kMCAN_IDX_A   = 0,  /*!< MCAN source mcana */
    kMCAN_IDX_B   = 1,  /*!< MCAN source mcana */
    kMCAN_IDX_C   = 2,  /*!< MCAN source mcanb */
    kMCAN_IDX_MAX,      /*!< MCAN moudle index max */
} MCAN_Idx_t;

/*!
 *  \brief    Enum to select the MCAN IRQ source
 */
typedef enum
{
    kMCAN_INT0   = 0,  /*!< MCAN IRQ source mcan intline 0 */
    kMCAN_INT1   = 1,  /*!< MCAN IRQ source mcan intline 1 */
    kMCAN_INT_MAX,     /*!< MCAN IRQ source max */
} MCAN_IntSrc_t;

/*! \brief type definition for mcan interrupt callback  */
typedef struct
{
    MCAN_Callback_t func[kMCAN_IDX_MAX][kMCAN_INT_MAX]; /*!< Array of callback functions for MCAN interrupts */
} MCAN_Int_Callback_t;

/*!
 *  \brief    Enum to select the MCAN interrupt lines
 */
typedef enum
{
    kMCAN_INTR_LINE_NUM_0 = 0U, /*!< MCAN interrupt line 0 */
    kMCAN_INTR_LINE_NUM_1 = 1U, /*!< MCAN interrupt line 1 */
} MCAN_IntrLineNum_t;

/*!
 *  \brief    Enum to represent the MCAN Identifier Type
 */
typedef enum
{
    kMCAN_ID_TYPE_11_BIT = 0U, /*!< 11bit MCAN Identifier */
    kMCAN_ID_TYPE_29_BIT = 1U, /*!< 29bit MCAN Identifier */
} MCAN_IdType_t;

/*!
 *  \brief    Enum to represent the MCAN mode of operation
 */
typedef enum
{
    kMCAN_OPERATION_MODE_NORMAL  = 0U, /*!< MCAN normal mode */
    kMCAN_OPERATION_MODE_SW_INIT = 1U, /*!< MCAN SW initialization mode */
} MCAN_OperationMode_t;

/*!
 *  \brief    Enum to represent the MCAN Message RAM type.
 */
typedef enum
{
    kMCAN_MEM_TYPE_BUF  = 0U, /*!< MCAN Msg RAM buffers */
    kMCAN_MEM_TYPE_FIFO = 1U, /*!< MCAN Msg RAM FIFO/Queue */
} MCAN_MemType_t;

/*!
 *  \brief    Enum to represent the MCAN Rx FIFO number
 */
typedef enum
{
    kMCAN_RX_FIFO_NUM_0 = 0U, /*!< MCAN Rx FIFO 0 */
    kMCAN_RX_FIFO_NUM_1 = 1U, /*!< MCAN Rx FIFO 1 */
} MCAN_RxFIFONum_t;

/*!
 *  \brief    Enum to represent the MCAN pin type
 */
typedef enum
{
    kMCAN_PIN_TYPE_RX = 0U, /*!< MCAN Rx Pin */
    kMCAN_PIN_TYPE_TX = 1U, /*!< MCAN Tx Pin */
} MCAN_PinType_t;

/*!
 *  \brief    Enum to represent FIFO/Buffer element Size
 */
typedef enum
{
    kMCAN_ELEM_SIZE_8BYTES  = 0U, /*!< 8 byte data field */
    kMCAN_ELEM_SIZE_12BYTES = 1U, /*!< 12 byte data field */
    kMCAN_ELEM_SIZE_16BYTES = 2U, /*!< 16 byte data field */
    kMCAN_ELEM_SIZE_20BYTES = 3U, /*!< 20 byte data field */
    kMCAN_ELEM_SIZE_24BYTES = 4U, /*!< 24 byte data field */
    kMCAN_ELEM_SIZE_32BYTES = 5U, /*!< 32 byte data field */
    kMCAN_ELEM_SIZE_48BYTES = 6U, /*!< 48 byte data field */
    kMCAN_ELEM_SIZE_64BYTES = 7U, /*!< 64 byte data field */
} MCAN_ElemSize_t;

/*!
 *  \brief    Enum to represent the MCAN time-out counter configuration
 */
typedef enum
{
    kMCAN_TIMEOUT_SELECT_CONT          = 0U, /*!< Continuous operation Mode */
    kMCAN_TIMEOUT_SELECT_TX_EVENT_FIFO = 1U, /*!< Timeout controlled by Tx Event FIFO */
    kMCAN_TIMEOUT_SELECT_RX_FIFO0      = 2U, /*!< Timeout controlled by Rx FIFO 0 */
    kMCAN_TIMEOUT_SELECT_RX_FIFO1      = 3U, /*!< Timeout controlled by Rx FIFO 1 */
} MCAN_TimeOutSelect_t;

/*!
 * \brief    Enum for MCAN interrupts.
 */
typedef enum
{
    kMCAN_INTR_SRC_RX_FIFO0_NEW_MSG       = MCAN_IR_RF0N_Msk, /*!< Rx FIFO 0 New Message interrupt */
    kMCAN_INTR_SRC_RX_FIFO0_WATERMARK     = MCAN_IR_RF0W_Msk, /*!< Rx FIFO 0 Watermark Reached interrupt */
    kMCAN_INTR_SRC_RX_FIFO0_FULL          = MCAN_IR_RF0F_Msk, /*!< Rx FIFO 0 Full interrupt */
    kMCAN_INTR_SRC_RX_FIFO0_MSG_LOST      = MCAN_IR_RF0L_Msk, /*!< Rx FIFO 0 Message Lost interrupt */
    kMCAN_INTR_SRC_RX_FIFO1_NEW_MSG       = MCAN_IR_RF1N_Msk, /*!< Rx FIFO 1 New Message interrupt */
    kMCAN_INTR_SRC_RX_FIFO1_WATERMARK     = MCAN_IR_RF1W_Msk, /*!< Rx FIFO 1 Watermark Reached interrupt */
    kMCAN_INTR_SRC_RX_FIFO1_FULL          = MCAN_IR_RF1F_Msk, /*!< Rx FIFO 1 Full interrupt */
    kMCAN_INTR_SRC_RX_FIFO1_MSG_LOST      = MCAN_IR_RF1L_Msk, /*!< Rx FIFO 1 Message Lost interrupt */
    kMCAN_INTR_SRC_HIGH_PRIO_MSG          = MCAN_IR_HPM_Msk,  /*!< High Priority Message interrupt */
    kMCAN_INTR_SRC_TRANS_COMPLETE         = MCAN_IR_TC_Msk,   /*!< Transmission Completed interrupt */
    kMCAN_INTR_SRC_TRANS_CANCEL_FINISH    = MCAN_IR_TCF_Msk,  /*!< Transmission Cancellation Finished interrupt */
    kMCAN_INTR_SRC_TX_FIFO_EMPTY          = MCAN_IR_TFE_Msk,  /*!< Tx FIFO Empty interrupt */
    kMCAN_INTR_SRC_TX_EVT_FIFO_NEW_ENTRY  = MCAN_IR_TEFN_Msk, /*!< Tx Event FIFO New Entry interrupt */
    kMCAN_INTR_SRC_TX_EVT_FIFO_WATERMARK  = MCAN_IR_TEFW_Msk, /*!< Tx Event FIFO Watermark Reached interrupt */
    kMCAN_INTR_SRC_TX_EVT_FIFO_FULL       = MCAN_IR_TEFF_Msk, /*!< Tx Event FIFO Full interrupt */
    kMCAN_INTR_SRC_TX_EVT_FIFO_ELEM_LOST  = MCAN_IR_TEFL_Msk, /*!< Tx Event FIFO Element Lost interrupt */
    kMCAN_INTR_SRC_TIMESTAMP_WRAPAROUND   = MCAN_IR_TSW_Msk,  /*!< Timestamp Wraparound interrupt */
    kMCAN_INTR_SRC_MSG_RAM_ACCESS_FAILURE = MCAN_IR_MRAF_Msk, /*!< Message RAM Access Failure interrupt */
    kMCAN_INTR_SRC_TIMEOUT                = MCAN_IR_TOO_Msk,  /*!< Timeout Occurred interrupt */
    kMCAN_INTR_SRC_DEDICATED_RX_BUFF_MSG  = MCAN_IR_DRX_Msk,  /*!< Message stored to Dedicated Rx Buffer interrupt */
    kMCAN_INTR_SRC_BIT_ERR_CORRECTED      = MCAN_IR_BEC_Msk,  /*!< Bit Error Corrected interrupt */
    kMCAN_INTR_SRC_BIT_ERR_UNCORRECTED    = MCAN_IR_BEU_Msk,  /*!< Bit Error Uncorrected interrupt */
    kMCAN_INTR_SRC_ERR_LOG_OVRFLW         = MCAN_IR_ELO_Msk,  /*!< Error Logging Overflow interrupt */
    kMCAN_INTR_SRC_ERR_PASSIVE            = MCAN_IR_EP_Msk,   /*!< Error Passive interrupt */
    kMCAN_INTR_SRC_WARNING_STATUS         = MCAN_IR_EW_Msk,   /*!< Warning Status interrupt */
    kMCAN_INTR_SRC_BUS_OFF_STATUS         = MCAN_IR_BO_Msk,   /*!< Bus_Off Status interrupt */
    kMCAN_INTR_SRC_WATCHDOG               = MCAN_IR_WDI_Msk,  /*!< Watchdog Interrupt interrupt */
    kMCAN_INTR_SRC_PROTOCOL_ERR_ARB       = MCAN_IR_PEA_Msk,  /*!< Protocol Error in Arbitration Phase interrupt */
    kMCAN_INTR_SRC_PROTOCOL_ERR_DATA      = MCAN_IR_PED_Msk,  /*!< Protocol Error in Data Phase interrupt */
    kMCAN_INTR_SRC_RES_ADDR_ACCESS        = MCAN_IR_ARA_Msk,  /*!< Access to Reserved Address interrupt */
} MCAN_IntrSrc_t;


/*!
 *  \brief    Enum to select the MCAN Loopback mode
 */
typedef enum
{
    kMCAN_LPBK_MODE_INTERNAL = 0U, /*!< Internal Loop Back Mode This mode can be used for hot self-test
                                   *   and this mode will not affect bus state.
                                   */

    kMCAN_LPBK_MODE_EXTERNAL = 1U, /*!< External Loop Back Mode In this mode, MCAN the M_CAN treats its own transmitted
                                   *   messages as received messages and stores them (if they pass acceptance filtering)
                                   *   into an Rx Buffer or an Rx FIFO. This mode will affect bus state
                                   */
} MCAN_LpbkMode_t;

/*!
 *  \brief    Enum to represent MCAN's communication state
 */
typedef enum
{
    kMCAN_COM_STATE_SYNCHRONIZING = 0U, /*!< MCAN is synchronizing on CAN communication */
    kMCAN_COM_STATE_IDLE          = 1U, /*!< MCAN is neither receiver nor transmitter */
    kMCAN_COM_STATE_RECEIVER      = 2U, /*!< MCAN is operating as receiver */
    kMCAN_COM_STATE_TRANSMITTER   = 3U, /*!< MCAN is operating as transmitter */
} MCAN_ComState_t;

/*!
 *  \brief    Enum to represent MCAN's Error Code
 */
typedef enum
{
    kMCAN_ERR_CODE_NO_ERROR = 0U, /*!< No error occurred since LEC has been reset by
                                  *   successful reception or transmission.
                                  */

    kMCAN_ERR_CODE_STUFF_ERROR = 1U, /*!< More than 5 equal bits in a sequence have occurred
                                     *   in a part of a received message where this is not allowed.
                                     */

    kMCAN_ERR_CODE_FORM_ERROR = 2U, /*!< A fixed format part of a received frame has the wrong format. */

    kMCAN_ERR_CODE_ACK_ERROR = 3U, /*!< The message transmitted by the M_CAN was not acknowledged by another node. */

    kMCAN_ERR_CODE_BIT1_ERROR = 4U, /*!< During the transmission of a message (with the exception of the arbitration
                                    * field), the device wanted to send a recessive level (bit of logical value "1",but
                                    * the monitored bus value was dominant.
                                    */

    kMCAN_ERR_CODE_BIT0_ERROR =
        5U, /*!< During the transmission of a message (or acknowledge bit, or active error flag,
             *   or overload flag), the device wanted to send a dominant level (data or identifier bit logical value
             * "0", but the monitored bus value was recessive.During Bus_Off recovery this status is set each time a
             * sequence of 11 recessive bits has been monitored. This enables the CPU to monitor the proceeding of the
             * Bus_Off recovery sequence (indicating the bus is not stuck at dominant or continuously disturbed).
             */

    kMCAN_ERR_CODE_CRC_ERROR = 6U, /*!< The CRC check sum of a received message was incorrect. The CRC of an incoming
                                     message does not match with the CRC calculated from the received data. */

    kMCAN_ERR_CODE_NO_CHANGE = 7U /*!< Any read access to the Protocol Status
                                  * Register re-initializes the LEC to "7"
                                  * When the LEC shows the value
                                  * "7" no CAN bus event was detected since the last
                                  * CPU read access to the Protocol Status Register.
                                  */

} MCAN_ErrCode_t;

/*!
 * \brief    Structure for bit timing calculation.
 *         Bit timing related to data phase will be valid only in case where
 *         MCAN is put in CAN-FD mode and will be '0' otherwise.
 */
typedef struct
{
    uint32_t nomRatePrescalar;   /*!< Nominal Baud Rate Pre-scaler Range:[0x0-0x1FF] */
    uint32_t nomTimeSeg1;        /*!< Nominal Time segment before sample point Range:[0x1-0xFF] */
    uint32_t nomTimeSeg2;        /*!< Nominal Time segment after sample point Range:[0x1-0x7F] */
    uint32_t nomSynchJumpWidth;  /*!< Nominal (Re)Synchronization Jump Width Range:[0x0-0x7F] */
    uint32_t dataRatePrescalar;  /*!< Data Baud Rate Pre-scaler Range:[0x0-0x1F] */
    uint32_t dataTimeSeg1;       /*!< Data Time segment before sample point Range:[0x0-0x1F] */
    uint32_t dataTimeSeg2;       /*!< Data Time segment after sample point Range:[0x0-0xF] */
    uint32_t dataSynchJumpWidth; /*!< Data (Re)Synchronization Jump Width Range:[0x0-0xF] */
} MCAN_BitTimingParams_t;

/*!
 * \brief    Structure for MCAN Transmitter Delay Compensation parameters.
 */
typedef struct
{
    uint32_t tdcf; /*!< Transmitter Delay Compensation Filter Window Length
                    *   Range:[0x0-0x7F]
                    */
    uint32_t tdco; /*!< Transmitter Delay Compensation Offset
                    *   Range:[0x0-0x7F]
                    */
} MCAN_TDCConfig_t;

/*!
 * \brief    Structure for MCAN Global Filter Configuration parameters.
 */
typedef struct
{
    uint32_t rrfe; /*!< Reject Remote Frames Extended
                    *   0 = Filter remote frames with 29-bit extended IDs
                    *   1 = Reject all remote frames with 29-bit extended IDs
                    */
    uint32_t rrfs; /*!< Reject Remote Frames Standard
                    *   0 = Filter remote frames with 11-bit standard IDs
                    *   1 = Reject all remote frames with 11-bit standard IDs
                    */
    uint32_t anfe; /*!< Accept Non-matching Frames Extended
                    *   0 = Accept in Rx FIFO 0
                    *   1 = Accept in Rx FIFO 1
                    *   others = Reject
                    */
    uint32_t anfs; /*!< Accept Non-matching Frames Standard
                    *   0 = Accept in Rx FIFO 0
                    *   1 = Accept in Rx FIFO 1
                    *   others = Reject
                    */
} MCAN_GlobalFiltConfig_t;

/*!
 * \brief    Structure for MCAN initialization parameters.
 */
typedef struct
{
    uint32_t fdMode;      /*!< FD Operation Enable
                           *   0 = FD operation disabled
                           *   1 = FD operation enabled
                           */
    uint32_t brsEnable;   /*!< Bit Rate Switch Enable
                           *   This is valid only when opMode = 1.
                           *   0 = Bit rate switching for transmissions disabled
                           *   1 = Bit rate switching for transmissions enabled
                           */
    uint32_t txpEnable;   /*!< Transmit Pause
                           *   0 = Transmit pause disabled
                           *   1 = Transmit pause enabled
                           */
    uint32_t efbi;        /*!< FEdge Filtering during Bus Integration
                           *   0 = Edge filtering disabled
                           *   1 = Two consecutive dominant tq required to detect an edge for
                           *       hard synchronization
                           */
    uint32_t pxhddisable; /*!< Protocol Exception Handling Disable
                           *   0 = Protocol exception handling enabled
                           *   1 = Protocol exception handling disabled
                           */
    uint32_t darEnable;   /*!< Disable Automatic Retransmission
                           *   0 = Automatic retransmission of messages not transmitted successfully
                           *       enabled
                           *   1 = Automatic retransmission disabled
                           */
    uint32_t
        wideMsgMarker; /*!< Enables the use of 16-bit Wide Message Markers. When 16-bit Wide Message Markers are used
                        *    (WMM = 1), 16-bit internal timestamping is disabled for the Tx Event FIFO.
                        *   0 = 8-bit Message Marker used
                        *   1 = 16-bit Message Marker used, replacing 16-bit timestamps in Tx Event FIFO
                        */
    uint32_t emulationEnable;   /*!< Emulation/Debug Suspend Enable
                                 *   0 = Emulation/Debug Suspend is disabled
                                 *   1 = Emulation/Debug Suspend is enabled
                                 */
    uint32_t wdcPreload;        /*!< Start value of the Message RAM Watchdog Counter
                                 *   Range:[0x0-0xFF]
                                 */
    MCAN_TDCConfig_t tdcConfig; /*!< Transmitter Delay Compensation parameters.
                                 *   Refer struct #MCAN_TDCConfig_t.
                                 */
    uint32_t tdcEnable;         /*!< Transmitter Delay Compensation Enable
                                 *   0 = Transmitter Delay Compensation is disabled
                                 *   1 = Transmitter Delay Compensation is enabled
                                 */
} MCAN_InitParams_t;

/*!
 * \brief    Structure for MCAN configuration parameters.
 */
typedef struct
{
    uint32_t monEnable;                   /*!< Bus Monitoring Mode
                                           *   0 = Bus Monitoring Mode is disabled
                                           *   1 = Bus Monitoring Mode is enabled
                                           */
    uint32_t asmEnable;                   /*!< Restricted Operation Mode
                                           *   0 = Normal CAN operation
                                           *   1 = Restricted Operation Mode active
                                           *   This mode should not be combined with test modes.
                                           */
    uint32_t tsPrescalar;                 /*!< Timestamp Counter Prescaler.
                                           *   Range:[0x0-0xF]
                                           */
    uint32_t tsSelect;                    /*!< Timestamp source selection.
                                           *   00= Timestamp counter value always 0x0000
                                           *   01= Timestamp counter value incremented according to tsPrescalar
                                           *   10= External timestamp counter value used
                                           *   11= Same as "00"
                                           */
    uint32_t timeoutSelect;               /*!< Time-out counter source select.
                                           *   Refer enum #MCAN_TimeOutSelect_t.
                                           */
    uint32_t timeoutPreload;              /*!< Start value of the Timeout Counter (down-counter).
                                           *   The Timeout Counter is decremented in multiples of CAN bit times [1-16]
                                           *   depending on the configuration of the tsPrescalar.
                                           *   Range:[0x0-0xFFFF]
                                           */
    uint32_t timeoutCntEnable;            /*!< Time-out Counter Enable
                                           *   0 = Time-out Counter is disabled
                                           *   1 = Time-out Counter is enabled
                                           */
    MCAN_GlobalFiltConfig_t filterConfig; /*!< Global Filter Configuration parameters.
                                           *    Refer struct #MCAN_GlobalFiltConfig_t.
                                           */
} MCAN_ConfigParams_t;

/*!
 * \brief    Structure for MCAN error logging counters status.
 */
typedef struct
{
    uint32_t transErrLogCnt; /*!< Transmit Error Counter */
    uint32_t recErrCnt;      /*!< Receive Error Counter */
    uint32_t rpStatus;       /*!< Receive Error Passive
                              *   0 = The Receive Error Counter is below the error passive level(128)
                              *   1 = The Receive Error Counter has reached the error passive level(128)
                              */
    uint32_t canErrLogCnt;   /*!< CAN Error Logging */

} MCAN_ErrCntStatus_t;

/*!
 * \brief    Structure for MCAN protocol status.
 */
typedef struct
{
    uint32_t lastErrCode;   /*!< Last Error Code
                             *   Refer enum #MCAN_ErrCode_t
                             */
    uint32_t act;           /*!< Activity - Monitors the module's CAN communication state.
                             *   refer enum #MCAN_ComState_t
                             */
    uint32_t errPassive;    /*!< Error Passive
                             *   0 = The M_CAN is in the Error_Active state
                             *   1 = The M_CAN is in the Error_Passive state
                             */
    uint32_t warningStatus; /*!< Warning Status
                             *   0 = Both error counters are below the Error_Warning limit of 96
                             *   1 = At least one of error counter has reached the Error_Warning
                             *       limit of 96
                             */
    uint32_t busOffStatus;  /*!< Bus_Off Status
                             *   0 = The M_CAN is not Bus_Off
                             *   1 = The M_CAN is in Bus_Off state
                             */
    uint32_t dlec;          /*!< Data Phase Last Error Code
                             *   Refer enum #MCAN_ErrCode_t
                             */
    uint32_t resi;          /*!< ESI flag of last received CAN FD Message
                             *   0 = Last received CAN FD message did not have its ESI flag set
                             *   1 = Last received CAN FD message had its ESI flag set
                             */
    uint32_t rbrs;          /*!< BRS flag of last received CAN FD Message
                             *   0 = Last received CAN FD message did not have its BRS flag set
                             *   1 = TLast received CAN FD message had its BRS flag set
                             */
    uint32_t rfdf;          /*!< Received a CAN FD Message
                             *   0 = Since this bit was reset by the CPU, no CAN FD message has been
                             *       received
                             *   1 = Message in CAN FD format with FDF flag set has been received
                             */
    uint32_t pxe;           /*!< Protocol Exception Event
                             *   0 = No protocol exception event occurred since last read access
                             *   1 = Protocol exception event occurred
                             */
    uint32_t tdcv;          /*!< Transmitter Delay Compensation Value */
} MCAN_ProtocolStatus_t;

/*!
 * \brief    Structure for MCAN Message RAM Configuration Parameters.
 *         Message RAM can contain following sections:
 *         Standard ID filters, Extended ID filters, TX FIFO(or TX Q),
 *         TX Buffers, TX EventFIFO, RX FIFO0, RX FIFO1, RX Buffer.
 *         Note: If particular section in the RAM is not used then it's size
 *         should be initialized to '0'
 *         (Number of buffers in case of Tx/Rx buffer).
 */
typedef struct
{
    uint32_t flssa;         /*!< Standard ID Filter List Start Address */
    uint32_t lss;           /*!< List Size: Standard ID
                             *   0 = No standard Message ID filter
                             *   1-128 = Number of standard Message ID filter elements
                             *   others = Values greater than 128 are interpreted as 128
                             */
    uint32_t flesa;         /*!< Extended ID Filter List Start Address */
    uint32_t lse;           /*!< List Size: Extended ID
                             *   0 = No standard Message ID filter
                             *   1-64 = Number of standard Message ID filter elements
                             *   others = Values greater than 64 are interpreted as 64
                             */
    uint32_t txStartAddr;   /*!< Tx Buffers Start Address */
    uint32_t txBufNum;      /*!< Number of Dedicated Transmit Buffers
                             *   0 = No Dedicated Tx Buffers
                             *   1-32 = Number of Dedicated Tx Buffers
                             *   others = Values greater than 32 are interpreted as 32
                             */
    uint32_t txFIFOSize;    /*!< Transmit FIFO/Queue Size
                             *   0 = No Tx FIFO/Queue
                             *   1-32 = Number of Tx Buffers used for Tx FIFO/Queue
                             *   others = Values greater than 32 are interpreted as 32
                             */
    uint32_t txBufMode;     /*!< Tx FIFO/Queue Mode
                             *   0 = Tx FIFO operation
                             *   1 = Tx Queue operation
                             */
    uint32_t txBufElemSize; /*!< Tx Buffer Element Size */

    uint32_t txEventFIFOStartAddr; /*!< Tx Event FIFO Start Address */

    uint32_t txEventFIFOSize;      /*!< Event FIFO Size
                                    *   0 = Tx Event FIFO disabled
                                    *   1-32 = Number of Tx Event FIFO elements
                                    *   others = Values greater than 32 are interpreted as 32
                                    */
    uint32_t txEventFIFOWaterMark; /*!< Tx Event FIFO Watermark
                                    *   0 = Watermark interrupt disabled
                                    *   1-32 = Level for Tx Event FIFO watermark interrupt
                                    *   others = Watermark interrupt disabled
                                    */
    uint32_t rxFIFO0startAddr;     /*!< Rx FIFO0 Start Address */
    uint32_t rxFIFO0size;          /*!< Rx FIFO0 Size
                                    *   0 = No Rx FIFO
                                    *   1-64 = Number of Rx FIFO elements
                                    *   others = Values greater than 64 are interpreted as 64
                                    */
    uint32_t rxFIFO0waterMark;     /*!< Rx FIFO0 Watermark
                                    *   0 = Watermark interrupt disabled
                                    *   1-64 = Level for Rx FIFO 0 watermark interrupt
                                    *   others = Watermark interrupt disabled
                                    */
    uint32_t rxFIFO0OpMode;        /*!< Rx FIFO0 Operation Mode
                                    *   0 = FIFO blocking mode
                                    *   1 = FIFO overwrite mode
                                    */
    uint32_t rxFIFO1startAddr;     /*!< Rx FIFO1 Start Address */
    uint32_t rxFIFO1size;          /*!< Rx FIFO1 Size
                                    *   0 = No Rx FIFO
                                    *   1-64 = Number of Rx FIFO elements
                                    *   others = Values greater than 64 are interpreted as 64
                                    */
    uint32_t rxFIFO1waterMark;     /*!< Rx FIFO1 Watermark
                                    *   0 = Watermark interrupt disabled
                                    *   1-64 = Level for Rx FIFO 1 watermark interrupt
                                    *   others = Watermark interrupt disabled
                                    */
    uint32_t rxFIFO1OpMode;        /*!< Rx FIFO1 Operation Mode
                                    *   0 = FIFO blocking mode
                                    *   1 = FIFO overwrite mode
                                    */
    uint32_t rxBufStartAddr;       /*!< Rx Buffer Start Address */
    uint32_t rxBufElemSize;        /*!< Rx Buffer Element Size */
    uint32_t rxFIFO0ElemSize;      /*!< Rx FIFO0 Element Size */
    uint32_t rxFIFO1ElemSize;      /*!< Rx FIFO1 Element Size */
} MCAN_MsgRAMConfigParams_t;

/*!
 * \brief    Structure for MCAN High Priority Message.
 */
typedef struct
{
    uint32_t bufIdx;     /*!< Buffer Index Only valid when MSI[1] = "1" */
    uint32_t msi;        /*!< Message Storage Indicator
                          *   MSI[1:0]
                          *       00  = No FIFO selected
                          *       01  = FIFO message lost
                          *       10  = Message stored in FIFO 0
                          *       11  = Message stored in FIFO 1
                          */
    uint32_t filterIdx;  /*!< Filter Index */
    uint32_t filterList; /*!< Indicates the filter list of the matching filter element
                          *   0 = Standard Filter List
                          *   1 = Extended Filter List
                          */
} MCAN_HighPriorityMsgInfo_t;

/*!
 * \brief    Structure for MCAN new data flag for Rx buffer.
 */
typedef struct
{
    uint32_t statusLow;  /*!< New data flag for Rx buffer no. 0 to 31 */
    uint32_t statusHigh; /*!< New data flag for Rx buffer no. 32 to 63 */
} MCAN_RxNewDataStatus_t;

/*!
 * \brief    Structure for MCAN Rx FIFO Status.
 */
typedef struct
{
    uint32_t num;      /*!< Rx FIFO number Refer enum #MCAN_RxFIFONum_t */
    uint32_t fillLvl;  /*!< Rx FIFO Fill Level */
    uint32_t getIdx;   /*!< Rx FIFO Get Index */
    uint32_t putIdx;   /*!< Rx FIFO Put Index */
    uint32_t fifoFull; /*!< Rx FIFO Full 0 = Rx FIFO not full 1 = Rx FIFO full */
    uint32_t msgLost;  /*!< Rx FIFO Message Lost */
} MCAN_RxFIFOStatus_t;

/*!
 * \brief    Structure for MCAN Tx FIFO Status.
 */
typedef struct
{
    uint32_t freeLvl;  /*!< Tx FIFO Free Level */
    uint32_t getIdx;   /*!< Tx FIFO Get Index Read as zero when Tx Queue operation is configured. */
    uint32_t putIdx;   /*!< Tx FIFO/Queue Put Index */
    uint32_t fifoFull; /*!< Tx FIFO/Queue Full
                        *   0 = Tx FIFO/Queue not full
                        *   1 = Tx FIFO/Queue full
                        */
} MCAN_TxFIFOStatus_t;

/*!
 * \brief    Structure for MCAN Tx Event FIFO Status.
 */
typedef struct
{
    uint32_t fillLvl;  /*!< Event FIFO Fill Level */
    uint32_t getIdx;   /*!< Event FIFO Gut Index */
    uint32_t putIdx;   /*!< Event FIFO Put Index */
    uint32_t fifoFull; /*!< Event FIFO Full 0 = Tx Event FIFO not full 1 = Tx Event FIFO full */
    uint32_t eleLost;  /*!< Tx Event FIFO Element Lost
                        *   0 = No Tx Event FIFO element lost
                        *   1 = Tx Event FIFO element lost, also set after write attempt to
                        *       Tx Event FIFO of size zero.
                        */
} MCAN_TxEventFIFOStatus_t;


/*!
 * \brief    Structure for accessing Revision ID and Core Release Info.
 *         of MCAN module.
 */
typedef struct
{
    uint32_t day;     /*!< Time Stamp Day. Two digits, BCD-coded. */
    uint32_t mon;     /*!< Time Stamp Month. Two digits, BCD-coded. */
    uint32_t year;    /*!< Time Stamp Year. Single digit, BCD-coded. */
    uint32_t subStep; /*!< Sub-step of Core Release Single digit, BCD-coded. */
    uint32_t step;    /*!< Step of Core Release.Two digits, BCD-coded Single digit, BCD-coded. */
    uint32_t rel;     /*!< Core Release. Single digit, BCD-coded. */
} MCAN_RevisionId_t;

/*!
 * \brief    Structure for MCAN Tx Buffer element.
 */
typedef struct
{
    uint32_t id;                           /*!< Identifier */
    uint32_t rtr;                          /*!< Remote Transmission Request
                                            *   0 = Transmit data frame
                                            *   1 = Transmit remote frame
                                            */
    uint32_t xtd;                          /*!< Extended Identifier
                                            *   0 = 11-bit standard identifier
                                            *   1 = 29-bit extended identifier
                                            */
    uint32_t esi;                          /*!< Error State Indicator
                                            *   0 = ESI bit in CAN FD format depends only on error passive flag
                                            *   1 = ESI bit in CAN FD format transmitted recessive
                                            */
    uint32_t dlc;                          /*!< Data Length Code
                                            *   0-8  = CAN + CAN FD: transmit frame has 0-8 data bytes
                                            *   9-15 = CAN: transmit frame has 8 data bytes
                                            *   9-15 = CAN FD: transmit frame has 12/16/20/24/32/48/64 data bytes
                                            */
    uint32_t brs;                          /*!< Bit Rat Switching
                                            *   0 = CAN FD frames transmitted without bit rate switching
                                            *   1 = CAN FD frames transmitted with bit rate switching
                                            */
    uint32_t fdf;                          /*!< FD Format
                                            *   0 = Frame transmitted in Classic CAN format
                                            *   1 = Frame transmitted in CAN FD format
                                            */
    uint32_t efc;                          /*!< Event FIFO Control
                                            *   0 = Don't store Tx events
                                            *   1 = Store Tx events
                                            */
    uint32_t mm;                           /*!< Message Marker */
    uint16_t data[MCAN_MAX_PAYLOAD_BYTES]; /*!< Data bytes.
                                            *   Only first dlc number of bytes are valid.
                                            */
} MCAN_TxBufElement_t;

/*!
 * \brief    Structure for MCAN Rx Buffer element.
 */
typedef struct
{
    uint32_t id;                           /*!< Identifier */
    uint32_t rtr;                          /*!< Remote Transmission Request
                                            *   0 = Received frame is a data frame
                                            *   1 = Received frame is a remote frame
                                            */
    uint32_t xtd;                          /*!< Extended Identifier
                                            *   0 = 11-bit standard identifier
                                            *   1 = 29-bit extended identifier
                                            */
    uint32_t esi;                          /*!< Error State Indicator
                                            *   0 = Transmitting node is error active
                                            *   1 = Transmitting node is error passive
                                            */
    uint32_t rxts;                         /*!< Rx Timestamp */
    uint32_t dlc;                          /*!< Data Length Code
                                            *   0-8  = CAN + CAN FD: received frame has 0-8 data bytes
                                            *   9-15 = CAN: received frame has 8 data bytes
                                            *   9-15 = CAN FD: received frame has 12/16/20/24/32/48/64 data bytes
                                            */
    uint32_t brs;                          /*!< Bit Rat Switching
                                            *   0 = Frame received without bit rate switching
                                            *   1 = Frame received with bit rate switching
                                            */
    uint32_t fdf;                          /*!< FD Format
                                            *   0 = Standard frame format
                                            *   1 = CAN FD frame format (new DLC-coding and CRC)
                                            */
    uint32_t fidx;                         /*!< Filter Index */
    uint32_t anmf;                         /*!< Accepted Non-matching Frame
                                            *   0 = Received frame matching filter index FIDX
                                            *   1 = Received frame did not match any Rx filter element
                                            */
    uint16_t data[MCAN_MAX_PAYLOAD_BYTES]; /*!< Data bytes.
                                            *   Only first dlc number of bytes are valid.
                                            */
} MCAN_RxBufElement_t;

/*!
 * \brief    Structure for MCAN Tx Event FIFO element.
 */
typedef struct
{
    uint32_t id;   /*!< Identifier */
    uint32_t rtr;  /*!< Remote Transmission Request
                    *   0 = Data frame transmitted
                    *   1 = Remote frame transmitted
                    */
    uint32_t xtd;  /*!< Extended Identifier
                    *   0 = 11-bit standard identifier
                    *   1 = 29-bit extended identifier
                    */
    uint32_t esi;  /*!< Error State Indicator
                    *   0 = Transmitting node is error active
                    *   1 = Transmitting node is error passive
                    */
    uint32_t txts; /*!< Tx Timestamp */
    uint32_t dlc;  /*!< Data Length Code
                    *   0-8  = CAN + CAN FD: frame with 0-8 data bytes transmitted
                    *   9-15 = CAN: frame with 8 data bytes transmitted
                    *   9-15 = CAN FD: frame with 12/16/20/24/32/48/64 data bytes transmitted
                    */
    uint32_t brs;  /*!< Bit Rat Switching
                    *   0 = Frame transmitted without bit rate switching
                    *   1 = Frame transmitted with bit rate switching
                    */
    uint32_t fdf;  /*!< FD Format
                    *   0 = Standard frame format
                    *   1 = CAN FD frame format (new DLC-coding and CRC)
                    */
    uint32_t et;   /*!< Event Type
                    *   00 = Reserved
                    *   01 = Tx event
                    *   10 = Transmission in spite of cancellation
                    *        (always set for transmissions in DAR mode)
                    *   11 = Reserved
                    */
    uint32_t mm;   /*!< Message Marker */
} MCAN_TxEventFIFOElement_t;

/*!
 * \brief    Structure for MCAN Standard Message ID Filter Element.
 */
typedef struct
{
    uint32_t sfid2; /*!< Standard Filter ID 2 */
    uint32_t sfid1; /*!< Standard Filter ID 1 */
    uint32_t sfec;  /*!< Standard Filter Element Configuration
                     *   000 = Disable filter element
                     *   001 = Store in Rx FIFO 0 if filter matches
                     *   010 = Store in Rx FIFO 1 if filter matches
                     *   011 = Reject ID if filter matches
                     *   100 = Set priority if filter matches
                     *   101 = Set priority and store in FIFO 0 if filter matches
                     *   110 = Set priority and store in FIFO 1 if filter matches
                     *   111 = Store into Rx Buffer or as debug message,
                     *         configuration of SFT[1:0] ignored.
                     *   If SFEC = "100", "101", or "110" a match sets high priority
                     *   message event is generated.
                     */
    uint32_t sft;   /*!< Standard Filter Type
                     *   00 = Range filter from SFID1 to SFID2 (SFID2 >= SFID1)
                     *   01 = Dual ID filter for SFID1 or SFID2
                     *   10 = Classic filter: SFID1 = filter, SFID2 = mask
                     *   11 = Filter element disabled
                     */
} MCAN_StdMsgIDFilterElement_t;

/*!
 * \brief    Structure for MCAN Extended Message ID Filter Element.
 */
typedef struct
{
    /*!< Extended Filter ID 1 */
    uint32_t efid1; /*!< Extended Filter ID 1 */
    uint32_t efec;  /*!< Extended Filter Element Configuration
                     *   000 = Disable filter element
                     *   001 = Store in Rx FIFO 0 if filter matches
                     *   010 = Store in Rx FIFO 1 if filter matches
                     *   011 = Reject ID if filter matches
                     *   100 = Set priority if filter matches
                     *   101 = Set priority and store in FIFO 0 if filter matches
                     *   110 = Set priority and store in FIFO 1 if filter matches
                     *   111 = Store into Rx Buffer or as debug message,
                     *         configuration of SFT[1:0] ignored.
                     *   If EFEC = "100", "101", or "110" a match sets high priority
                     *   message event is generated.
                     */
    uint32_t efid2; /*!< Extended Filter ID 2 */
    uint32_t eft;   /*!< Extended Filter Type
                     *   00 = Range filter from EFID1 to EFID2 (EFID2 >= EFID1)
                     *   01 = Dual ID filter for EFID1 or EFID2
                     *   10 = Classic filter: EFID1 = filter, EFID2 = mask
                     *   11 = Range filter from EFID1 to EFID2 (EFID2 >= EFID1),
                     *        XIDAM mask not applied
                     */
} MCAN_ExtMsgIDFilterElement_t;


/*******************************************************************************
 * APIs
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*!
 *
 * \brief   This API will set MCAN module mode of operation.
 *
 * \param[in]   base    Base Address of the MCAN Registers.
 * \param[in]   mode        Mode of operation.
 *                          Refer enum #MCAN_OperationMode_t.
 */
void MCAN_setOpMode(MCAN_Type *base, uint32_t mode);

/*!
 *
 * \brief   This API will return MCAN module mode of operation.
 *
 * \param[in]   base    Base Address of the MCAN Registers.
 *
 * \return  mode            Mode of operation.
 *                          Refer enum #MCAN_OperationMode_t.
 *
 */
uint32_t MCAN_getOpMode(MCAN_Type *base);

/*!
 *
 * \brief   This API will initialize MCAN module.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 * \param[in]   initParams      Initialization parameters.
 *                              Refer struct #MCAN_InitParams_t.
 *
 * \return  status          Initialization status.
 *
 */
int32_t MCAN_init(MCAN_Type *base, const MCAN_InitParams_t *initParams);

/*!
 *
 * \brief   This API will configure MCAN module.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 * \param[in]   configParams    configuration parameters.
 *                              Refer struct #MCAN_ConfigParams_t.
 *
 * \return  status          Configuration status.
 *
 */
int32_t MCAN_config(MCAN_Type *base, const MCAN_ConfigParams_t *configParams);

/*!
 *
 * \brief   This API will configure a bit timings for MCAN module.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 * \param[in]   configParams    Configuration parameters for MCAN bit timing.
 *                              Refer struct #MCAN_BitTimingParams_t.
 *
 * \return  status          Bit Timings configuration status.
 *
 */
int32_t MCAN_setBitTime(MCAN_Type *base, const MCAN_BitTimingParams_t *configParams);

/*!
 *
 * \brief   This API will configure Different sections of Message RAM.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 * \param[in]   msgRAMConfigParams
 *                          Message RAM Configuration parameters.
 *                          Refer struct #MCAN_MsgRAMConfigParams_t.
 *
 * \return  status          Configuration Status.
 *
 */
int32_t MCAN_msgRAMConfig(MCAN_Type *base, const MCAN_MsgRAMConfigParams_t *msgRAMConfigParams);

/*!
 *
 * \brief   This API will configure Extended ID AND Mask.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 * \param[in]   idMask          Configuration parameters for MCAN Extended Id mask.
 *                              This value is 29 bit wide.
 *
 * \return  status          Extended ID AND Mask configuration status.
 *
 */
int32_t MCAN_setExtIDAndMask(MCAN_Type *base, uint32_t idMask);

/*!
 *
 * \brief   This API is used to write Tx message to message RAM.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 * \param[in]   memType         Part of message ram to which given message to write.
 *                              Refer enum #MCAN_MemType_t.
 * \param[in]   bufNum          Buffer  number where message to write.
 *                              This parameter will ignored if memType is FIFO/Q.
 * \param[in]   elem            Message Object.
 *                              Refer struct #MCAN_TxBufElement_t.
 */
void MCAN_writeMsgRam(MCAN_Type *base, uint32_t memType, uint32_t bufNum, const MCAN_TxBufElement_t *elem);

/*!
 *
 * \brief   This API will set Tx Buffer Add Request.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 * \param[in]   bufNum          Tx Buffer number for which request is to be added.
 *
 * \return  status          Configuration Status.
 *
 */
int32_t MCAN_txBufAddReq(MCAN_Type *base, uint32_t bufNum);

/*!
 *
 * \brief   This API will return New Data Message Status.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 * \param[out]  newDataStatus   Rx Buffer new data status.
 *                          Refer struct #MCAN_RxNewDataStatus_t.
 */
void MCAN_getNewDataStatus(MCAN_Type *base, MCAN_RxNewDataStatus_t *newDataStatus);

/*!
 *
 * \brief   This API clear New Data Message Status.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 * \param[out]  newDataStatus   Rx Buffer new data status.
 *                              Refer struct #MCAN_RxNewDataStatus_t.
 *
 */
void MCAN_clearNewDataStatus(MCAN_Type *base, const MCAN_RxNewDataStatus_t *newDataStatus);

/*!
 *
 * \brief   This API is used to read received message form message RAM.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 * \param[in]   memType         Part of message ram to which given message to write.
 *                              Refer enum #MCAN_MemType_t.
 * \param[in]   bufNum          Buffer  number from where message is to read.
 *                              This parameter will ignored if memType is FIFO/Q.
 * \param[in]   fifoNum         FIFOs number from where message is to read.
 *                              Refer enum #MCAN_RxFIFONum_t.
 *                              This parameter will ignored if memType is buffer.
 * \param[out]  elem            Message Object.
 *                              Refer struct #MCAN_RxBufElement_t.
 */
void MCAN_readMsgRam(MCAN_Type *base, uint32_t memType, uint32_t bufNum, uint32_t fifoNum, MCAN_RxBufElement_t *elem);

/*!
 *
 * \brief   This API is used to read message form Tx Event FIFO.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 * \param[out]  txEventElem     Tx Event FIFO Message Object.
 *                              Refer struct #MCAN_TxEventFIFOElement_t.
 */
void MCAN_readTxEventFIFO(MCAN_Type *base, MCAN_TxEventFIFOElement_t *txEventElem);

/*!
 *
 * \brief   This API is used to add Standard Message ID Filter Element.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 * \param[in]   filtNum         Filter number.
 * \param[in]   elem            Filter Object.
 *                              Refer struct #MCAN_StdMsgIDFilterElement_t.
 */
void MCAN_addStdMsgIDFilter(MCAN_Type *base, uint32_t filtNum, const MCAN_StdMsgIDFilterElement_t *elem);

/*!
 *
 * \brief   This API is used to add Extended Message ID Filter Element.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 * \param[in]   filtNum         Filter  number.
 * \param[in]   elem            Filter Object.
 *                              Refer struct #MCAN_ExtMsgIDFilterElement_t.
 */
void MCAN_addExtMsgIDFilter(MCAN_Type *base, uint32_t filtNum, const MCAN_ExtMsgIDFilterElement_t *elem);

/*!
 *
 * \brief   This API will enable/disable Loop Back Test Mode for
 *          MCAN module.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 * \param[in]   lpbkMode        Loopback mode for MCAN.
 *                              Refer #MCAN_LpbkMode_t.
 * \param[in]   enable          Loop Back Mode is enabled if it is TRUE.
 *                              Loop Back Mode is disabled  if it is FALSE.
 *
 * \note    This API can be called only when MCAN is in Software
 *          Initialization mode of operation.
 *
 */
void MCAN_lpbkModeEnable(MCAN_Type *base, uint32_t lpbkMode, uint32_t enable);

/*!
 *
 * \brief   This API will return error counter status for MCAN module.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 * \param[out]  errCounter      Error Counter Status.
 *                              Refer struct #MCAN_ErrCntStatus_t.
 */
void MCAN_getErrCounters(MCAN_Type *base, MCAN_ErrCntStatus_t *errCounter);

/*!
 *
 * \brief   This API will return protocol status for MCAN module.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 * \param[in]   protStatus      Protocol Status.
 *                              Refer struct #MCAN_ProtocolStatus_t.
 */
void MCAN_getProtocolStatus(MCAN_Type *base, MCAN_ProtocolStatus_t *protStatus);

/*!
 *
 * \brief   This API is used to enable/disable interrupts.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 * \param[in]   intrMask        Interrupts to enable.
 *                              Refer enum #MCAN_IntrSrc_t.
 * \param[in]   enable          Interrupt is enabled if it is TRUE.
 *                              Interrupt is disabled  if it is FALSE.s
 */
void MCAN_enableIntr(MCAN_Type *base, uint32_t intrMask, uint32_t enable);

/*!
 *
 * \brief   This API is used to select interrupt line.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 * \param[in]   intrMask        Interrupt Number for which interrupt
 *                          line is to be selected. Refer enum #MCAN_IntrSrc_t.
 * \param[in]   lineNum         Interrupt Line to select.
 *                          Refer enum #MCAN_IntrLineNum_t.
 */
void MCAN_selectIntrLine(MCAN_Type *base, uint32_t intrMask, uint32_t lineNum);

/*!
 *
 * \brief   This API is used to get interrupt line selected for each interrupt.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 *
 * \return  status          Interrupt Line Select Status.
 *
 */
uint32_t MCAN_getIntrLineSelectStatus(MCAN_Type *base);

/*!
 *
 * \brief   This API is used to enable/disable selected interrupt line.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 * \param[in]   lineNum         Interrupt Line to select.
 *                          Refer enum #MCAN_IntrLineNum_t,
 * \param[in]   enable          Interrupt Line is enabled if it is 1.
 *                          Interrupt Line is disabled  if it is 0.
 */
void MCAN_enableIntrLine(MCAN_Type *base, uint32_t lineNum, uint32_t enable);

/*!
 *
 * \brief   This API will return interrupt status.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 *
 * \return  status          Interrupt Status.
 *
 */
uint32_t MCAN_getIntrStatus(MCAN_Type *base);

/*!
 *
 * \brief   This API is used to clear the interrupt status.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 * \param[in]   intrMask        Interrupts to clear status.
 */
void MCAN_clearIntrStatus(MCAN_Type *base, uint32_t intrMask);

/*!
 *
 * \brief   This API will return High Priority Message Status.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 * \param[out]  hpm             High Priority Message Status.
 *                          Refer struct #MCAN_HighPriorityMsgInfo_t.
 */
void MCAN_getHighPriorityMsgStatus(MCAN_Type *base, MCAN_HighPriorityMsgInfo_t *hpm);

/*!
 *
 * \brief   This API will Rx FIFO status.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 * \param[out]  fifoStatus      Rx FIFO Status.
 *                          Refer struct #MCAN_RxFIFOStatus_t.
 */
void MCAN_getRxFIFOStatus(MCAN_Type *base, MCAN_RxFIFOStatus_t *fifoStatus);

/*!
 *
 * \brief   This API will write Rx FIFO Acknowledgement.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 *                          Refer enum #MCAN_RxFIFONum_t.
 * \param[in]   fifoNum     FIFO Number.
 * \param[in]   idx             Rx FIFO Acknowledge Index
 *
 * \return  status          Acknowledgement Status.
 *
 */
int32_t MCAN_writeRxFIFOAck(MCAN_Type *base, uint32_t fifoNum, uint32_t idx);

/*!
 *
 * \brief   This API will Tx FIFO status.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 * \param[out]  fifoStatus      Tx FIFO Status.
 *                          Refer struct #MCAN_TxFIFOStatus_t.
 */
void MCAN_getTxFIFOQueStatus(MCAN_Type *base, MCAN_TxFIFOStatus_t *fifoStatus);

/*!
 *
 * \brief   This API will return Tx Buffer Request Pending status.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 *
 * \return  status          Tx Buffer Request Pending status.
 *
 */
uint32_t MCAN_getTxBufReqPend(MCAN_Type *base);

/*!
 *
 * \brief   This API will set Tx Buffer Cancellation Request.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 * \param[in]   buffNum         Tx Buffer number for which request is to be added.
 *
 * \return  status          Configuration Status.
 *
 */
int32_t MCAN_txBufCancellationReq(MCAN_Type *base, uint32_t buffNum);

/*!
 *
 * \brief   This API will return Tx Buffer Transmission Occurred status.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 *
 * \return  status          Tx Buffer Transmission Occurred status.
 *
 */
uint32_t MCAN_getTxBufTransmissionStatus(MCAN_Type *base);

/*!
 *
 * \brief   This API will return Transmit Buffer Cancellation Finished status.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 *
 * \return  status          Transmit Buffer Cancellation Finished status.
 *
 */
uint32_t MCAN_txBufCancellationStatus(MCAN_Type *base);

/*!
 *
 * \brief   This API is used to enable/disable Tx Buffer Transmission Interrupt.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 * \param[in]   bufNum          Buffer number for which interrupt is to enable.
 * \param[in]   enable          Interrupt is enabled if it is TRUE.
 *                          Interrupt is disabled  if it is FALSE.
 *
 * \return  status          Configuration status.
 *
 */
int32_t MCAN_txBufTransIntrEnable(MCAN_Type *base, uint32_t bufNum, uint32_t enable);

/*!
 *
 * \brief   This API is used to enable/disable Tx Buffer Cancellation Finished
 *          Interrupt.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 * \param[in]   bufNum         Buffer number for which interrupt is to enable.
 * \param[in]   enable          Interrupt is enabled if it is TRUE.
 *                          Interrupt is disabled  if it is FALSE.
 *
 * \return  status          Configuration status.
 *
 */
int32_t MCAN_getTxBufCancellationIntrEnable(MCAN_Type *base, uint32_t bufNum, uint32_t enable);

/*!
 *
 * \brief   This API will Tx Event FIFO status.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 * \param[out]  fifoStatus      Tx Event FIFO Status.
 *                          Refer struct #MCAN_TxEventFIFOStatus_t.
 */
void MCAN_getTxEventFIFOStatus(MCAN_Type *base, MCAN_TxEventFIFOStatus_t *fifoStatus);

/*!
 *
 * \brief   This API will write Event FIFO Acknowledge Index.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 * \param[in]   idx             Event FIFO Acknowledge Index
 *
 * \return  status          Acknowledgement Status.
 *
 */
int32_t MCAN_writeTxEventFIFOAck(MCAN_Type *base, uint32_t idx);


/* ========================================================================== */
/*                          Advance Functions                                 */
/* ========================================================================== */

/*!
 *
 * \brief   This API is used get the MCAN revision ID.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 * \param[out]   revId           Contains Revision ID of MCAN module.
 *                          Refer struct #MCAN_RevisionId_t.
 */
void MCAN_getRevisionId(MCAN_Type *base, MCAN_RevisionId_t *revId);

/*!
 * \brief   This API will return Rx pin state of MCAN module.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 *
 * \return  state           MCAN Rx Pin State.
 *                          0= The CAN bus is dominant
 *                          1= The CAN bus is recessive
 */
uint32_t MCAN_getRxPinState(MCAN_Type *base);

/*!
 *
 * \brief   This API will set Tx pin state of MCAN module.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 * \param[in]   state           MCAN Tx Pin State.
 *                          00= Reset value
 *                          01= Sample Point can be monitored at tx pin
 *                          10= The CAN bus is dominant
 *                          11= The CAN bus is recessive
 *                          other= It will treated as 11.
 */
void MCAN_setTxPinState(MCAN_Type *base, uint32_t state);

/*!
 *
 * \brief   This API will return Tx pin state of MCAN module.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 *
 * \return  state           MCAN Tx Pin State.
 *                          00= Reset value
 *                          01= Sample Point can be monitored at tx pin
 *                          10= The CAN bus is dominant
 *                          11= The CAN bus is recessive
 *
 */
uint32_t MCAN_getTxPinState(MCAN_Type *base);

/*!
 *
 * \brief   This API will return current timestamp counter value.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 *
 * \return  val             Current Timestamp counter value.
 *
 */
uint32_t MCAN_getTSCounterVal(MCAN_Type *base);

/*!
 *
 * \brief   This API will get the configured bit timings for MCAN module.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 * \param[out]  configParams    Configuration parameters for MCAN bit timing.
 *                          Refer struct #MCAN_BitTimingParams_t.
 */
void MCAN_getBitTime(MCAN_Type *base, MCAN_BitTimingParams_t *configParams);

/*!
 *
 * \brief   This API will reset timestamp counter value.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 */
void MCAN_resetTSCounter(MCAN_Type *base);

/*!
 * \brief   This API will return current time-out counter value.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 *
 * \return  val             Current Time-out counter value.
 */
uint32_t MCAN_getTOCounterVal(MCAN_Type *base);

/*!
 *
 * \brief   This function return endianness value of MCAN module.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 *
 * \retval  val             Endianness value. (0x87654321)
 *
 */
uint32_t MCAN_getEndianVal(MCAN_Type *base);

/*!
 *
 * \brief   This API will get the configured Extended ID AND Mask.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 *
 * \return  idMask          Extended ID AND Mask.
 *
 */
uint32_t MCAN_getExtIDANDMask(MCAN_Type *base);


/*!
 *
 * \brief   This API is used to init mcan message ram.
 *
 * \return  true or false.
 *
 */
bool MCAN_MsgRamInit(void);


/*!
 * \brief Register user callback function to mcan interrupt handler.
 *
 * \details This function registers user callback function for mcan interrupt handler which uses IRQ. The relative IRQ
 will be enabled in the NVIC and the priority will be configured at the same time
 *
 * \param[in] base Base Address of the MCAN Registers.
 * \param[in] intsrc interrupt source select.
 * \param[in] func MCAN user callback
 * \param[in] priority IRQ priority
 *
 * \retval kSTATUS_SUCCESS Success to the operation
 * \retval kSTATUS_FAIL Register to a MCAN which has been registered already. Need to call \ref
 MCAN_unregisterCallback() before the re-registration
 */
status_t MCAN_registerCallback(MCAN_Type *base, MCAN_IntSrc_t intsrc, MCAN_Callback_t func, uint32_t priority);


/*!
 * \brief Unregister user callback function to mcan interrupt handler.
 *
 * \details This function clears the registered user callback function, and disable the relative IRQ in the NVIC
 *
 * \param[in] base Base Address of the MCAN Registers.
 * \param[in] intsrc interrupt source select.
 *
 * \retval kSTATUS_SUCCESS Success to the operation
 * \retval kSTATUS_FAIL The MCAN hasn't been registered to a callback
 */
status_t MCAN_unregisterCallback(MCAN_Type *base,MCAN_IntSrc_t intsrc);

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */ /* end of DRV_HTE_MCAN */

#endif /* HTE_MCAN_H */
