/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*!
 * \file hte_mcan.c
 * \brief  SDK MCAN driver source file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_mcan.h"
#include "hte_sysctrl.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! \brief Maximum acceptable comparator filter oversampling ratio */


/*! \brief  MCAN MSG RAM BANK number for ECC AGGR. */
#define MCAN_MSG_RAM_NUM (0U)

/*!  \brief  Maximum Number of Rx Buffers. */
#define MCAN_RX_BUFFER_MAX (64U)

/*!  \brief  Maximum Number of Tx Buffers. */
#define MCAN_TX_BUFFER_MAX (32U)

/*!  \brief  Macro for standard Message ID filter. */
#define MCAN_STD_ID_FILTER_SIZE_WORDS (1U)

/*!  \brief  Macro for extended Message ID filter. */
#define MCAN_EXT_ID_FILTER_SIZE_WORDS (2U)

/*!  \brief  Macro for Tx Event FIFO element size. */
#define MCAN_TX_EVENT_FIFO_SIZE_WORDS (2U)

/*! \brief Message Memory Identifier */  
#define MCAN_MCAN_MSG_MEM (0x0U)  
  
/*! \brief Max DSJW for Data Bit Timing Parameters */  
#define MCAN_DBTP_DSJW_MAX   (0xFU)  
  
/*! \brief Max DTSEG2 for Data Bit Timing Parameters */  
#define MCAN_DBTP_DTSEG2_MAX (0xFU)  
  
/*! \brief Max DTSEG1 for Data Bit Timing Parameters */  
#define MCAN_DBTP_DTSEG1_MAX (0x1FU)  
  
/*! \brief Max DBRP for Data Bit Timing Parameters */  
#define MCAN_DBTP_DBRP_MAX   (0x1FU)  
  
/*! \brief Max NSJW for Nominal Bit Timing Parameters */  
#define MCAN_NBTP_NSJW_MAX   (0x7FU)  
  
/*! \brief Max NTSEG2 for Nominal Bit Timing Parameters */  
#define MCAN_NBTP_NTSEG2_MAX (0x7FU)  
  
/*! \brief Max NTSEG1 for Nominal Bit Timing Parameters */  
#define MCAN_NBTP_NTSEG1_MAX (0xFFU)  
  
/*! \brief Max NBRP for Nominal Bit Timing Parameters */  
#define MCAN_NBTP_NBRP_MAX   (0x1FFU)  
  
/*! \brief Max Watchdog Configuration Value */  
#define MCAN_RWD_WDC_MAX (0xFFU)  
  
/*! \brief Max Transmitter Delay Compensation Filter Value */  
#define MCAN_TDCR_TDCF_MAX (0x7FU)  
  
/*! \brief Max Transmitter Delay Compensation Offset Value */  
#define MCAN_TDCR_TDCO_MAX (0x7FU)  
  
/*! \brief Max Extended ID Mask Value */  
#define MCAN_XIDAM_EIDM_MAX (0x1FFFFFFFU)  
  
/*! \brief Max Transmission Start Configuration Value */  
#define MCAN_TSCC_TCP_MAX (0xFU)  
  
/*! \brief Max Timeout Configuration Value */  
#define MCAN_TOCC_TOP_MAX (0xFFFFU)


/**
 * \brief  Macro for Interrupt Line enable mask.
 */
#define MCAN_INTR_LINE_EN_MASK ((MCAN_ILE_EINT0_Msk | MCAN_ILE_EINT1_Msk))

/**
 * \brief  Mask and shift for Tx Buffers elements.
 */
#define MCAN_TX_BUFFER_ELEM_ID_SHIFT  (0U)           /*!< ID shift position for the transmitted message */  
#define MCAN_TX_BUFFER_ELEM_ID_MASK   (0x1FFFFFFFU)  /*!< ID mask for the transmitted message */  
#define MCAN_TX_BUFFER_ELEM_RTR_SHIFT (29U)          /*!< RTR bit shift position for the transmitted message */  
#define MCAN_TX_BUFFER_ELEM_RTR_MASK  (0x20000000U)  /*!< RTR bit mask for the transmitted message */  
#define MCAN_TX_BUFFER_ELEM_XTD_SHIFT (30U)          /*!< XTD bit shift position for the transmitted message */  
#define MCAN_TX_BUFFER_ELEM_XTD_MASK  (0x40000000U)  /*!< XTD bit mask for the transmitted message */  
#define MCAN_TX_BUFFER_ELEM_ESI_SHIFT (31U)          /*!< ESI bit shift position for the transmitted message */  
#define MCAN_TX_BUFFER_ELEM_ESI_MASK  (0x80000000U)  /*!< ESI bit mask for the transmitted message */  
#define MCAN_TX_BUFFER_ELEM_DLC_SHIFT (16U)          /*!< DLC shift position for the transmitted message */  
#define MCAN_TX_BUFFER_ELEM_DLC_MASK  (0x000F0000U)  /*!< DLC mask for the transmitted message */  
#define MCAN_TX_BUFFER_ELEM_BRS_SHIFT (20U)          /*!< BRS shift position for the transmitted message */  
#define MCAN_TX_BUFFER_ELEM_BRS_MASK  (0x00100000U)  /*!< BRS mask for the transmitted message */  
#define MCAN_TX_BUFFER_ELEM_FDF_SHIFT (21U)          /*!< FDF shift position for the transmitted message */  
#define MCAN_TX_BUFFER_ELEM_FDF_MASK  (0x00200000U)  /*!< FDF mask for the transmitted message */  
#define MCAN_TX_BUFFER_ELEM_EFC_SHIFT (23U)          /*!< EFC shift position for the transmitted message */  
#define MCAN_TX_BUFFER_ELEM_EFC_MASK  (0x00800000U)  /*!< EFC mask for the transmitted message */  
#define MCAN_TX_BUFFER_ELEM_MM_SHIFT  (24U)          /*!< MM shift position for the transmitted message */  
#define MCAN_TX_BUFFER_ELEM_MM_MASK   (0xFF000000U)  /*!< MM mask for the transmitted message */

/**
 * \brief  Mask and shift for Rx Buffers elements.
 */
#define MCAN_RX_BUFFER_ELEM_ID_SHIFT   (0U)           /*!< ID shift position for the received message */  
#define MCAN_RX_BUFFER_ELEM_ID_MASK    (0x1FFFFFFFU)  /*!< ID mask for the received message */  
#define MCAN_RX_BUFFER_ELEM_RTR_SHIFT  (29U)          /*!< RTR bit shift position for the received message */  
#define MCAN_RX_BUFFER_ELEM_RTR_MASK   (0x20000000U)  /*!< RTR bit mask for the received message */  
#define MCAN_RX_BUFFER_ELEM_XTD_SHIFT  (30U)          /*!< XTD bit shift position for the received message */  
#define MCAN_RX_BUFFER_ELEM_XTD_MASK   (0x40000000U)  /*!< XTD bit mask for the received message */  
#define MCAN_RX_BUFFER_ELEM_ESI_SHIFT  (31U)          /*!< ESI bit shift position for the received message */  
#define MCAN_RX_BUFFER_ELEM_ESI_MASK   (0x80000000U)  /*!< ESI bit mask for the received message */  
#define MCAN_RX_BUFFER_ELEM_RXTS_SHIFT (0U)           /*!< RXTS (Receive Timestamp) shift position for the received message */  
#define MCAN_RX_BUFFER_ELEM_RXTS_MASK  (0x0000FFFFU)  /*!< RXTS (Receive Timestamp) mask for the received message */  
#define MCAN_RX_BUFFER_ELEM_DLC_SHIFT  (16U)          /*!< DLC (Data Length Code) shift position for the received message */  
#define MCAN_RX_BUFFER_ELEM_DLC_MASK   (0x000F0000U)  /*!< DLC (Data Length Code) mask for the received message */  
#define MCAN_RX_BUFFER_ELEM_BRS_SHIFT  (20U)          /*!< BRS (Bit Rate Switch) shift position for the received message */  
#define MCAN_RX_BUFFER_ELEM_BRS_MASK   (0x00100000U)  /*!< BRS (Bit Rate Switch) mask for the received message */  
#define MCAN_RX_BUFFER_ELEM_FDF_SHIFT  (21U)          /*!< FDF (Frame Data Format) shift position for the received message */  
#define MCAN_RX_BUFFER_ELEM_FDF_MASK   (0x00200000U)  /*!< FDF (Frame Data Format) mask for the received message */  
#define MCAN_RX_BUFFER_ELEM_FIDX_SHIFT (24U)          /*!< FIDX (Filter Index) shift position for the received message */  
#define MCAN_RX_BUFFER_ELEM_FIDX_MASK  (0x7F000000U)  /*!< FIDX (Filter Index) mask for the received message */  
#define MCAN_RX_BUFFER_ELEM_ANMF_SHIFT (31U)          /*!< ANMF (Accepted Non-matching Frame) shift position for the received message */  
#define MCAN_RX_BUFFER_ELEM_ANMF_MASK  (0x80000000U)  /*!< ANMF (Accepted Non-matching Frame) mask for the received message */


/**
 * \brief  Mask and shift for Standard Message ID Filter Elements.
 */
#define MCAN_STD_ID_FILTER_SFID2_SHIFT (0U)           /*!< Shift position for the second Standard Filter ID (SFID2) */  
#define MCAN_STD_ID_FILTER_SFID2_MASK  (0x000003FFU)  /*!< Mask for the second Standard Filter ID (SFID2) */  
#define MCAN_STD_ID_FILTER_SFID1_SHIFT (16U)          /*!< Shift position for the first Standard Filter ID (SFID1) */  
#define MCAN_STD_ID_FILTER_SFID1_MASK  (0x03FF0000U)  /*!< Mask for the first Standard Filter ID (SFID1) */  
#define MCAN_STD_ID_FILTER_SFEC_SHIFT  (27U)          /*!< Shift position for the Standard Filter Element Configuration (SFEC) */  
#define MCAN_STD_ID_FILTER_SFEC_MASK   (0x38000000U)  /*!< Mask for the Standard Filter Element Configuration (SFEC) */  
#define MCAN_STD_ID_FILTER_SFT_SHIFT   (30U)          /*!< Shift position for the Standard Filter Type (SFT) */  
#define MCAN_STD_ID_FILTER_SFT_MASK    (0xC0000000U)  /*!< Mask for the Standard Filter Type (SFT) */


/**
 * \brief  Extended Message ID Filter Element.
 */
#define MCAN_EXT_ID_FILTER_EFID2_SHIFT (0U)           /*!< Shift position for the second Extended Filter ID (EFID2) */  
#define MCAN_EXT_ID_FILTER_EFID2_MASK  (0x1FFFFFFFU)  /*!< Mask for the second Extended Filter ID (EFID2) */  
#define MCAN_EXT_ID_FILTER_EFID1_SHIFT (0U)           /*!< Shift position for the first Extended Filter ID (EFID1) */  
#define MCAN_EXT_ID_FILTER_EFID1_MASK  (0x1FFFFFFFU)  /*!< Mask for the first Extended Filter ID (EFID1) */  
#define MCAN_EXT_ID_FILTER_EFEC_SHIFT  (29U)          /*!< Shift position for the Extended Filter Element Configuration (EFEC) */  
#define MCAN_EXT_ID_FILTER_EFEC_MASK   (0xE0000000U)  /*!< Mask for the Extended Filter Element Configuration (EFEC) */
#define MCAN_EXT_ID_FILTER_EFT_SHIFT   (30U)          /*!< Shift position for the Extended Filter Type (EFT) */  
#define MCAN_EXT_ID_FILTER_EFT_MASK    (0xC0000000U)  /*!< Mask for the Extended Filter Type (EFT) */


/**
 * \brief  Mask and shift for Tx Event FIFO elements.
 */
#define MCAN_TX_EVENT_FIFO_ELEM_ID_SHIFT  (0U)           /*!< Shift position for the Message Identifier (ID) */  
#define MCAN_TX_EVENT_FIFO_ELEM_ID_MASK   (0x1FFFFFFFU)  /*!< Mask for the Message Identifier (ID) */   
#define MCAN_TX_EVENT_FIFO_ELEM_RTR_SHIFT (29U)          /*!< Shift position for the Remote Transmission Request (RTR) bit */  
#define MCAN_TX_EVENT_FIFO_ELEM_RTR_MASK  (0x20000000U)  /*!< Mask for the Remote Transmission Request (RTR) bit */  
#define MCAN_TX_EVENT_FIFO_ELEM_XTD_SHIFT (30U)          /*!< Shift position for the Extended Format (XTD) bit */  
#define MCAN_TX_EVENT_FIFO_ELEM_XTD_MASK  (0x40000000U)  /*!< Mask for the Extended Format (XTD) bit */  
#define MCAN_TX_EVENT_FIFO_ELEM_ESI_SHIFT (31U)          /*!< Shift position for the Error State Indicator (ESI) bit */  
#define MCAN_TX_EVENT_FIFO_ELEM_ESI_MASK  (0x80000000U)  /*!< Mask for the Error State Indicator (ESI) bit */   

#define MCAN_TX_EVENT_FIFO_ELEM_TXTS_SHIFT (0U)          /*!< Shift position for the Transmission Timestamp (TXTS) */  
#define MCAN_TX_EVENT_FIFO_ELEM_TXTS_MASK  (0x0000FFFFU) /*!< Mask for the Transmission Timestamp (TXTS) */  
#define MCAN_TX_EVENT_FIFO_ELEM_DLC_SHIFT  (16U)         /*!< Shift position for the Data Length Code (DLC) */  
#define MCAN_TX_EVENT_FIFO_ELEM_DLC_MASK   (0x000F0000U) /*!< Mask for the Data Length Code (DLC) */  
#define MCAN_TX_EVENT_FIFO_ELEM_BRS_SHIFT  (20U)         /*!< Shift position for the Bit Rate Switch (BRS) bit */  
#define MCAN_TX_EVENT_FIFO_ELEM_BRS_MASK   (0x00100000U) /*!< Mask for the Bit Rate Switch (BRS) bit */    
#define MCAN_TX_EVENT_FIFO_ELEM_FDF_SHIFT  (21U)         /*!< Shift position for the Flexible Data-rate Format (FDF) bit */  
#define MCAN_TX_EVENT_FIFO_ELEM_FDF_MASK   (0x00200000U) /*!< Mask for the Flexible Data-rate Format (FDF) bit */  
#define MCAN_TX_EVENT_FIFO_ELEM_ET_SHIFT   (22U)         /*!< Shift position for the Event Type (ET) */  
#define MCAN_TX_EVENT_FIFO_ELEM_ET_MASK    (0x00C00000U) /*!< Mask for the Event Type (ET) */  
#define MCAN_TX_EVENT_FIFO_ELEM_MM_SHIFT   (24U)         /*!< Shift position for the Message Marker (MM) */  
#define MCAN_TX_EVENT_FIFO_ELEM_MM_MASK    (0xFF000000U) /*!< Mask for the Message Marker (MM) */




/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/**
 * \brief   This API will unblock write access to write protected registers.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 *
 */
static void MCAN_writeProtectedRegAccessUnlock(MCAN_Type *base);

/**
 * \brief   This API will block write access to write protected registers.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 *
 */
static void MCAN_writeProtectedRegAccessLock(MCAN_Type *base);


/**
 * \brief   This API will read the message object from Message RAM.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 * \param[in]   elemAddr        Address of the message object.
 * \param[out]  elem            Message Object.
 *                          Refer struct #MCAN_RxBufElement_t.
 *
 */
static void MCAN_readMsg(uint32_t base, uint32_t elemAddr, MCAN_RxBufElement_t *elem);

/**
 * \brief   This API will write the message object to Message RAM.
 *
 * \param[in]   base        Base Address of the MCAN Registers.
 * \param[in]   elemAddr        Address of the message object.
 * \param[in]   elem            Message Object.
 *                          Refer struct #MCAN_TxBufElement_t.
 *
 */
static void MCAN_writeMsg(uint32_t base, uint32_t elemAddr, const MCAN_TxBufElement_t *elem);

/**
 * \brief   This API will return payload depending on 'dlc'  field.
 *
 * \param[in]   dlc             Data Length Code.
 *
 * \return  data size       Size of the payload.
 */
static uint32_t MCAN_getDataSize(uint32_t dlc);

/**
 * \brief   This API will return message object size.
 *
 * \param[in]   elemSize        Element Size.
 *
 * \return  message object size
 *                          Size of the message object stored in Message RAM.
 */
static uint32_t MCAN_getMsgObjSize(uint32_t elemSize);


/*!  
 * \brief Handles the interrupt request for the MCAN module  
 *
 * \param[in] idx      Index of the MCAN module (e.g., MCAN0, MCAN1, etc.).  
 * \param[in] intsrc   Enumeration value indicating the specific interrupt source.  
 * \param[in] base     Base Address of the MCAN Registers.
 *
 */
void MCAN_handlerIRQ(MCAN_Idx_t idx,MCAN_IntSrc_t intsrc,MCAN_Type *base);

#ifdef DEBUG
/*!  
 * \brief Checks if the provided MCAN base address is valid  
 *
 * \param[in] base Base Address of the MCAN Registers.
 *  
 * \return Returns true if the base address is valid, false otherwise.  
 */
static bool MCAN_isBaseValid(MCAN_Type *base);
#endif

/*!  
 * \brief Gets the base address of the MCAN message RAM  
 *  
 * \param base Pointer to the base address of the MCAN module registers.  
 *  
 * \return Returns the base address of the MCAN message RAM for the given MCAN module,  
 *
 */
static uint32_t MCAN_getRamBase(MCAN_Type *base);


/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! \brief Array of MCAN ISR */
static MCAN_Int_Callback_t s_mcanISR = { 0 };
/*! \brief Array of MCAN IRQ number */
static const IRQn_Type s_mcanIRQ[kMCAN_IDX_MAX][kMCAN_INT_MAX] = MCAN_IRQS;


/*******************************************************************************
 * Codes
 ******************************************************************************/
#ifdef DEBUG
static bool MCAN_isBaseValid(MCAN_Type *base)
{
    return ((base == MCANA) || (base == MCANB) || (base == MCANC));
}
#endif

static uint32_t MCAN_getRamBase(MCAN_Type *base)
{
    if (base == MCANA)
    {
        return MCANA_MSG_RAM_BASE;
    }
    else if (base == MCANB)
    {
        return MCANB_MSG_RAM_BASE;
    }
    else if (base == MCANC)
    {
        return MCANC_MSG_RAM_BASE;
    }

    return MCANA_MSG_RAM_BASE;
}

void MCAN_setOpMode(MCAN_Type *base, uint32_t mode)
{
    assert(MCAN_isBaseValid(base));

    base->CCCR = (base->CCCR & ~(MCAN_CCCR_INIT_Msk)) | MCAN_CCCR_INIT_Set(mode);
}

uint32_t MCAN_getOpMode(MCAN_Type *base)
{
    assert(MCAN_isBaseValid(base));

    return (MCAN_CCCR_INIT_Get(base->CCCR));
}

#ifdef HTE_DEVICE_HS32F7D377_CPU1
bool MCAN_MsgRamInit(void)
{
    uint16_t timeout = 1000;
    SYSCTRL_initCANSram();

    while(timeout--)
    {
        if(SYSCTRL_getCANSramInitDone())
        {
            break;
        }
    }

    return (timeout == 0? false:true);
}
#endif

int32_t MCAN_init(MCAN_Type *base, const MCAN_InitParams_t *initParams)
{
    int32_t status;

    assert(MCAN_isBaseValid(base));

    MCAN_writeProtectedRegAccessUnlock(base);

    /* Configure MCAN mode(FD vs Classic CAN operation) and controls */
    base->CCCR = (base->CCCR & ~(MCAN_CCCR_FDOE_Msk | MCAN_CCCR_BRSE_Msk | MCAN_CCCR_TXP_Msk | MCAN_CCCR_EFBI_Msk |
                                 MCAN_CCCR_PXHD_Msk | MCAN_CCCR_DAR_Msk)) |
                 MCAN_CCCR_FDOE_Set(initParams->fdMode) | MCAN_CCCR_BRSE_Set(initParams->brsEnable) |
                 MCAN_CCCR_TXP_Set(initParams->txpEnable) | MCAN_CCCR_EFBI_Set(initParams->efbi) |
                 MCAN_CCCR_PXHD_Set(initParams->pxhddisable) | MCAN_CCCR_DAR_Set(initParams->darEnable);

    if ((MCAN_TDCR_TDCF_MAX >= initParams->tdcConfig.tdcf) && (MCAN_TDCR_TDCO_MAX >= initParams->tdcConfig.tdco) &&
        (MCAN_RWD_WDC_MAX >= initParams->wdcPreload))
    {
        /* Configure Transceiver Delay Compensation */
        base->TDCR = (base->TDCR & ~(MCAN_TDCR_TDCF_Msk | MCAN_TDCR_TDCO_Msk)) |
                     MCAN_TDCR_TDCF_Set(initParams->tdcConfig.tdcf) | MCAN_TDCR_TDCO_Set(initParams->tdcConfig.tdco);
        /* Configure MSG RAM watchdog counter preload value */
        base->RWD = (base->RWD & ~(MCAN_RWD_WDC_Msk)) | MCAN_RWD_WDC_Set(initParams->wdcPreload);
        /* Enable/Disable Transceiver Delay Compensation */
        base->DBTP = (base->DBTP & ~(MCAN_DBTP_TDC_Msk)) | MCAN_DBTP_TDC_Set(initParams->tdcEnable);
        status     = 0;
    }
    else
    {
        status = -1;
    }

    MCAN_writeProtectedRegAccessLock(base);

    return status;
}

int32_t MCAN_config(MCAN_Type *base, const MCAN_ConfigParams_t *configParams)
{
    int32_t status;

    assert(MCAN_isBaseValid(base));

    MCAN_writeProtectedRegAccessUnlock(base);

    /* Configure MCAN control registers */
    base->CCCR = (base->CCCR & ~(MCAN_CCCR_MON_Msk | MCAN_CCCR_ASM_Msk)) | MCAN_CCCR_MON_Set(configParams->monEnable) |
                 MCAN_CCCR_ASM_Set(configParams->asmEnable);

    /* Configure Global Filter */
    base->GFC = (base->GFC & ~(MCAN_GFC_RRFE_Msk | MCAN_GFC_RRFS_Msk | MCAN_GFC_ANFE_Msk | MCAN_GFC_ANFS_Msk)) |
                MCAN_GFC_RRFE_Set(configParams->filterConfig.rrfe) |
                MCAN_GFC_RRFS_Set(configParams->filterConfig.rrfs) |
                MCAN_GFC_ANFE_Set(configParams->filterConfig.anfe) | MCAN_GFC_ANFS_Set(configParams->filterConfig.anfs);

    if ((MCAN_TSCC_TCP_MAX >= configParams->tsPrescalar) && (MCAN_TOCC_TOP_MAX >= configParams->timeoutPreload))
    {
        /* Configure Time-stamp counter */
        base->TSCC = (base->TSCC & ~(MCAN_TSCC_TSS_Msk | MCAN_TSCC_TCP_Msk)) |
                     MCAN_TSCC_TSS_Set(configParams->tsSelect) | MCAN_TSCC_TCP_Set(configParams->tsPrescalar - 1U);

        /* Configure Time-out counter */
        base->TOCC = (base->TOCC & ~(MCAN_TOCC_TOS_Msk | MCAN_TOCC_TOP_Msk)) |
                     MCAN_TOCC_TOS_Set(configParams->timeoutSelect) | MCAN_TOCC_TOP_Set(configParams->timeoutPreload);

        /* Enable Time-out counter */
        base->TOCC = (base->TOCC & ~(MCAN_TOCC_ETOC_Msk)) | MCAN_TOCC_ETOC_Set(configParams->timeoutCntEnable);

        status = 0;
    }
    else
    {
        status = -1;
    }

    MCAN_writeProtectedRegAccessLock(base);

    return status;
}

int32_t MCAN_setBitTime(MCAN_Type *base, const MCAN_BitTimingParams_t *configParams)
{
    int32_t status;

    assert(MCAN_isBaseValid(base));

    MCAN_writeProtectedRegAccessUnlock(base);

    if ((MCAN_NBTP_NSJW_MAX >= configParams->nomSynchJumpWidth) &&
        (MCAN_NBTP_NTSEG2_MAX >= configParams->nomTimeSeg2) && (MCAN_NBTP_NTSEG1_MAX >= configParams->nomTimeSeg1) &&
        (MCAN_NBTP_NBRP_MAX >= configParams->nomRatePrescalar))
    {
        base->NBTP =
            (base->NBTP & ~(MCAN_NBTP_NSJW_Msk | MCAN_NBTP_NTSEG2_Msk | MCAN_NBTP_NTSEG1_Msk | MCAN_NBTP_NBRP_Msk)) |
            MCAN_NBTP_NSJW_Set(configParams->nomSynchJumpWidth) |
            MCAN_NBTP_NTSEG2_Set(configParams->nomTimeSeg2) | MCAN_NBTP_NTSEG1_Set(configParams->nomTimeSeg1) |
            MCAN_NBTP_NBRP_Set(configParams->nomRatePrescalar);
        status = 0;
    }
    else
    {
        status = -1;
    }

    if (0 == status)
    {
        if ((MCAN_DBTP_DSJW_MAX >= configParams->dataSynchJumpWidth) &&
            (MCAN_DBTP_DTSEG2_MAX >= configParams->dataTimeSeg2) &&
            (MCAN_DBTP_DTSEG1_MAX >= configParams->dataTimeSeg1) &&
            (MCAN_DBTP_DBRP_MAX >= configParams->dataRatePrescalar))
        {
            base->DBTP = (base->DBTP &
                          ~(MCAN_DBTP_DSJW_Msk | MCAN_DBTP_DTSEG2_Msk | MCAN_DBTP_DTSEG1_Msk | MCAN_DBTP_DBRP_Msk)) |
                         MCAN_DBTP_DSJW_Set(configParams->dataSynchJumpWidth) |
                         MCAN_DBTP_DTSEG2_Set(configParams->dataTimeSeg2) |
                         MCAN_DBTP_DTSEG1_Set(configParams->dataTimeSeg1) |
                         MCAN_DBTP_DBRP_Set(configParams->dataRatePrescalar);
            status = 0;
        }
        else
        {
            status = -1;
        }
    }

    MCAN_writeProtectedRegAccessLock(base);
    return status;
}

int32_t MCAN_msgRAMConfig(MCAN_Type *base, const MCAN_MsgRAMConfigParams_t *msgRAMConfigParams)
{
    int32_t  status;
    uint32_t elemNum = 0U;

    assert(MCAN_isBaseValid(base));

    MCAN_writeProtectedRegAccessUnlock(base);

    /* Configure Message Filters section */
    if (0U != msgRAMConfigParams->lss)
    {
        base->SIDFC = (base->SIDFC & ~(MCAN_SIDFC_FLSSA_Msk | MCAN_SIDFC_LSS_Msk)) |
                      MCAN_SIDFC_FLSSA_Set(msgRAMConfigParams->flssa) | MCAN_SIDFC_LSS_Set(msgRAMConfigParams->lss);
    }
    if (0U != msgRAMConfigParams->lse)
    {
        base->XIDFC = (base->XIDFC & ~(MCAN_XIDFC_FLESA_Msk | MCAN_XIDFC_LSE_Msk)) |
                      MCAN_XIDFC_FLESA_Set(msgRAMConfigParams->flesa) | MCAN_XIDFC_LSE_Set(msgRAMConfigParams->lse);
    }
    /* Configure Rx FIFO 0 section */
    if (0U != msgRAMConfigParams->rxFIFO0size)
    {
        base->RXF0C =
            (base->RXF0C & ~(MCAN_RXF0C_F0SA_Msk | MCAN_RXF0C_F0S_Msk | MCAN_RXF0C_F0WM_Msk | MCAN_RXF0C_F0OM_Msk)) |
            MCAN_RXF0C_F0SA_Set(msgRAMConfigParams->rxFIFO0startAddr) |
            MCAN_RXF0C_F0S_Set(msgRAMConfigParams->rxFIFO0size) |
            MCAN_RXF0C_F0WM_Set(msgRAMConfigParams->rxFIFO0waterMark) |
            MCAN_RXF0C_F0OM_Set(msgRAMConfigParams->rxFIFO0OpMode);

        /* Configure Rx FIFO0 elements size */
        base->RXESC = (base->RXESC & ~(MCAN_RXESC_F0DS_Msk)) | MCAN_RXESC_F0DS_Set(msgRAMConfigParams->rxFIFO0ElemSize);
    }
    /* Configure Rx FIFO 1 section */
    if (0U != msgRAMConfigParams->rxFIFO1size)
    {
        base->RXF1C =
            (base->RXF1C & ~(MCAN_RXF1C_F1SA_Msk | MCAN_RXF1C_F1S_Msk | MCAN_RXF1C_F1WM_Msk | MCAN_RXF1C_F1OM_Msk)) |
            MCAN_RXF1C_F1SA_Set(msgRAMConfigParams->rxFIFO1startAddr) |
            MCAN_RXF1C_F1S_Set(msgRAMConfigParams->rxFIFO1size) |
            MCAN_RXF1C_F1WM_Set(msgRAMConfigParams->rxFIFO1waterMark) |
            MCAN_RXF1C_F1OM_Set(msgRAMConfigParams->rxFIFO1OpMode);
        /* Configure Rx FIFO1 elements size */
        base->RXESC = (base->RXESC & ~(MCAN_RXESC_F1DS_Msk)) | MCAN_RXESC_F1DS_Set(msgRAMConfigParams->rxFIFO1ElemSize);
    }
    /* Configure Rx Buffer Start Address */
    base->RXBC = (base->RXBC & ~(MCAN_RXBC_RBSA_Msk)) | MCAN_RXBC_RBSA_Set(msgRAMConfigParams->rxBufStartAddr);
    /* Configure Rx Buffer elements size */
    base->RXESC = (base->RXESC & ~(MCAN_RXESC_RBDS_Msk)) | MCAN_RXESC_RBDS_Set(msgRAMConfigParams->rxBufElemSize);

    /* Configure Tx Event FIFO section */
    if (0U != msgRAMConfigParams->txEventFIFOSize)
    {
        base->TXEFC = (base->TXEFC & ~(MCAN_TXEFC_EFSA_Msk | MCAN_TXEFC_EFS_Msk | MCAN_TXEFC_EFWM_Msk)) |
                      MCAN_TXEFC_EFSA_Set(msgRAMConfigParams->txEventFIFOStartAddr) |
                      MCAN_TXEFC_EFS_Set(msgRAMConfigParams->txEventFIFOSize) |
                      MCAN_TXEFC_EFWM_Set(msgRAMConfigParams->txEventFIFOWaterMark);
    }
    /* Configure Tx Buffer and FIFO/Q section */
    elemNum = msgRAMConfigParams->txBufNum + msgRAMConfigParams->txFIFOSize;
    if ((MCAN_TX_BUFFER_MAX >= elemNum) &&
        ((0U != msgRAMConfigParams->txBufNum) || (0U != msgRAMConfigParams->txFIFOSize)))
    {
        base->TXBC =
            (base->TXBC & ~(MCAN_TXBC_TBSA_Msk | MCAN_TXBC_NDTB_Msk | MCAN_TXBC_TFQS_Msk | MCAN_TXBC_TFQM_Msk)) |
            MCAN_TXBC_TBSA_Set(msgRAMConfigParams->txStartAddr) | MCAN_TXBC_NDTB_Set(msgRAMConfigParams->txBufNum) |
            MCAN_TXBC_TFQS_Set(msgRAMConfigParams->txFIFOSize) | MCAN_TXBC_TFQM_Set(msgRAMConfigParams->txBufMode);
        /* Configure Tx Buffer/FIFO0/FIFO1 elements size */
        base->TXESC = (base->TXESC & ~(MCAN_TXESC_TBDS_Msk)) | MCAN_TXESC_TBDS_Set(msgRAMConfigParams->txBufElemSize);
        status      = 0;
    }
    else
    {
        status = -1;
    }

    MCAN_writeProtectedRegAccessLock(base);

    return status;
}

int32_t MCAN_setExtIDAndMask(MCAN_Type *base, uint32_t idMask)
{
    int32_t status;

    assert(MCAN_isBaseValid(base));

    if (MCAN_XIDAM_EIDM_MAX >= idMask)
    {
        MCAN_writeProtectedRegAccessUnlock(base);

        base->XIDAM = (base->XIDAM & ~(MCAN_XIDAM_EIDM_Msk)) | MCAN_XIDAM_EIDM_Set(idMask);

        MCAN_writeProtectedRegAccessLock(base);
        status = 0;
    }
    else
    {
        status = -1;
    }

    return status;
}

void MCAN_writeMsgRam(MCAN_Type *base, uint32_t memType, uint32_t bufNum, const MCAN_TxBufElement_t *elem)
{
    uint32_t startAddr = 0U, elemSize = 0U, elemAddr = 0U;
    uint32_t idx = 0U, enableMod = 0U;
    uint32_t ramBase;

    assert(MCAN_isBaseValid(base));

    ramBase = MCAN_getRamBase(base);
    if (kMCAN_MEM_TYPE_BUF == memType)
    {
        idx       = bufNum;
        enableMod = 1U;
    }
    if (kMCAN_MEM_TYPE_FIFO == memType)
    {
        idx       = MCAN_TXFQS_TFQP_Get(base->TXFQS);
        enableMod = 1U;
    }
    if (1U == enableMod)
    {
        startAddr  = MCAN_TXBC_TBSA_Get(base->TXBC);
        elemSize   = MCAN_TXESC_TBDS_Get(base->TXESC);
        startAddr   = (uint32_t)(startAddr << 2U);
        elemSize    = MCAN_getMsgObjSize(elemSize);
        elemSize   *= 4U;
        elemAddr    = startAddr + (elemSize * idx);
        elemAddr   += MCAN_MCAN_MSG_MEM;
        MCAN_writeMsg(ramBase, elemAddr, elem);
    }
}

int32_t MCAN_txBufAddReq(MCAN_Type *base, uint32_t bufNum)
{
    int32_t  status;
    uint32_t regVal;

    assert(MCAN_isBaseValid(base));

    if (MCAN_TX_BUFFER_MAX > bufNum)
    {
        regVal  = base->TXBAR;
        regVal  |= ((uint32_t)1U << bufNum);

        // For writing to TXBAR CCE bit should be '0'. This need not be
        // reverted because for other qualified writes this is locked state
        // and can't be written.
        MCAN_writeProtectedRegAccessLock(base);
        base->TXBAR = regVal;
        status      = 0;
    }
    else
    {
        status = -1;
    }

    return status;
}

void MCAN_getNewDataStatus(MCAN_Type *base, MCAN_RxNewDataStatus_t *newDataStatus)
{
    assert(MCAN_isBaseValid(base));

    newDataStatus->statusLow  = base->NDAT1;
    newDataStatus->statusHigh = base->NDAT2;
}

void MCAN_clearNewDataStatus(MCAN_Type *base, const MCAN_RxNewDataStatus_t *newDataStatus)
{
    assert(MCAN_isBaseValid(base));

    base->NDAT1 = newDataStatus->statusLow;
    base->NDAT2 = newDataStatus->statusHigh;
}

void MCAN_readMsgRam(MCAN_Type *base, uint32_t memType, uint32_t bufNum, uint32_t fifoNum, MCAN_RxBufElement_t *elem)
{
    uint32_t startAddr = 0U, elemSize = 0U, elemAddr = 0U;
    uint32_t enableMod = 0U, idx = 0U;
    uint32_t ramBase;

    assert(MCAN_isBaseValid(base));

    ramBase = MCAN_getRamBase(base);

    if (kMCAN_MEM_TYPE_BUF == memType)
    {
        startAddr = MCAN_RXBC_RBSA_Get(base->RXBC);
        elemSize  = MCAN_RXESC_RBDS_Get(base->RXESC);
        idx       = bufNum;
        enableMod = 1U;
    }
    if (kMCAN_MEM_TYPE_FIFO == memType)
    {
        switch (fifoNum)
        {
            case kMCAN_RX_FIFO_NUM_0:
                startAddr = MCAN_RXF0C_F0SA_Get(base->RXF0C);
                elemSize  = MCAN_RXESC_F0DS_Get(base->RXESC);
                idx       = MCAN_RXF0S_F0GI_Get(base->RXF0S);
                enableMod = 1U;
                break;
            case kMCAN_RX_FIFO_NUM_1:
                startAddr = MCAN_RXF1C_F1SA_Get(base->RXF1C);
                elemSize  = MCAN_RXESC_F1DS_Get(base->RXESC);
                idx       = MCAN_RXF1S_F1GI_Get(base->RXF1S);
                enableMod = 1U;
                break;
            default:
                /* Invalid option */
                break;
        }
    }

    if (1U == enableMod)
    {
        startAddr  = (uint32_t)(startAddr << 2U);
        elemSize   = MCAN_getMsgObjSize(elemSize);
        elemSize  *= 4U;
        elemAddr   = startAddr + (elemSize * idx);
        elemAddr  += MCAN_MCAN_MSG_MEM;
        MCAN_readMsg(ramBase, elemAddr, elem);
    }

    if (kMCAN_MEM_TYPE_BUF == memType)
    {
        if (bufNum < 31)
        {
            base->NDAT1 = ((uint32_t)1 << bufNum);
        }
        else /* FDCAN_RX_BUFFER32 <= RxLocation <= FDCAN_RX_BUFFER63 */
        {
            base->NDAT2 = ((uint32_t)1 << (bufNum & 0x1FU));
        }
    }

    if (kMCAN_MEM_TYPE_FIFO == memType)
    {
        MCAN_writeRxFIFOAck(base, fifoNum, idx);
    }
}

void MCAN_readTxEventFIFO(MCAN_Type *base, MCAN_TxEventFIFOElement_t *txEventElem)
{
    uint32_t startAddr = 0U, elemSize = 0U, elemAddr = 0U;
    uint32_t idx = 0U, regVal;
    uint32_t ramBase;

    assert(MCAN_isBaseValid(base));

    ramBase   = MCAN_getRamBase(base);
    startAddr = MCAN_TXEFC_EFSA_Get(base->TXEFC);
    elemSize  = MCAN_TX_EVENT_FIFO_SIZE_WORDS;
    idx       = MCAN_TXEFS_EFGI_Get(base->TXEFS);

    startAddr  = (uint32_t)(startAddr << 2U);
    elemSize  *= 4U;
    elemAddr   = startAddr + (elemSize * idx);
    elemAddr  += MCAN_MCAN_MSG_MEM;

    regVal             = *(uint32_t *)(ramBase + elemAddr);
    txEventElem->id    = (uint32_t)((regVal & MCAN_TX_EVENT_FIFO_ELEM_ID_MASK) >> MCAN_TX_EVENT_FIFO_ELEM_ID_SHIFT);
    txEventElem->rtr   = (uint32_t)((regVal & MCAN_TX_EVENT_FIFO_ELEM_RTR_MASK) >> MCAN_TX_EVENT_FIFO_ELEM_RTR_SHIFT);
    txEventElem->xtd   = (uint32_t)((regVal & MCAN_TX_EVENT_FIFO_ELEM_XTD_MASK) >> MCAN_TX_EVENT_FIFO_ELEM_XTD_SHIFT);
    txEventElem->esi   = (uint32_t)((regVal & MCAN_TX_EVENT_FIFO_ELEM_ESI_MASK) >> MCAN_TX_EVENT_FIFO_ELEM_ESI_SHIFT);
    elemAddr          += 4U;
    regVal             = *(uint32_t *)(ramBase + elemAddr);
    txEventElem->txts  = (uint32_t)((regVal & MCAN_TX_EVENT_FIFO_ELEM_TXTS_MASK) >> MCAN_TX_EVENT_FIFO_ELEM_TXTS_SHIFT);
    txEventElem->dlc   = (uint32_t)((regVal & MCAN_TX_EVENT_FIFO_ELEM_DLC_MASK) >> MCAN_TX_EVENT_FIFO_ELEM_DLC_SHIFT);
    txEventElem->brs   = (uint32_t)((regVal & MCAN_TX_EVENT_FIFO_ELEM_BRS_MASK) >> MCAN_TX_EVENT_FIFO_ELEM_BRS_SHIFT);
    txEventElem->fdf   = (uint32_t)((regVal & MCAN_TX_EVENT_FIFO_ELEM_FDF_MASK) >> MCAN_TX_EVENT_FIFO_ELEM_FDF_SHIFT);
    txEventElem->et    = (uint32_t)((regVal & MCAN_TX_EVENT_FIFO_ELEM_ET_MASK) >> MCAN_TX_EVENT_FIFO_ELEM_ET_SHIFT);
    txEventElem->mm    = (uint32_t)((regVal & MCAN_TX_EVENT_FIFO_ELEM_MM_MASK) >> MCAN_TX_EVENT_FIFO_ELEM_MM_SHIFT);

    MCAN_writeTxEventFIFOAck(base, idx);
}

void MCAN_addStdMsgIDFilter(MCAN_Type *base, uint32_t filtNum, const MCAN_StdMsgIDFilterElement_t *elem)
{
    uint32_t startAddr, elemAddr, regVal;
    uint32_t ramBase;

    assert(MCAN_isBaseValid(base));
    ramBase    = MCAN_getRamBase(base);
    startAddr  = MCAN_SIDFC_FLSSA_Get(base->SIDFC);
    startAddr   = (uint32_t)(startAddr << 2U);
    elemAddr   = startAddr + (filtNum * MCAN_STD_ID_FILTER_SIZE_WORDS * 4U);
    elemAddr   += MCAN_MCAN_MSG_MEM;

    regVal                             = 0U;
    regVal                            |= (uint32_t)(elem->sfid2 << MCAN_STD_ID_FILTER_SFID2_SHIFT);
    regVal                            |= (uint32_t)(elem->sfid1 << MCAN_STD_ID_FILTER_SFID1_SHIFT);
    regVal                            |= (uint32_t)(elem->sfec << MCAN_STD_ID_FILTER_SFEC_SHIFT);
    regVal                            |= (uint32_t)(elem->sft << MCAN_STD_ID_FILTER_SFT_SHIFT);
    *(uint32_t *)(ramBase + elemAddr)  = regVal;
}

void MCAN_addExtMsgIDFilter(MCAN_Type *base, uint32_t filtNum, const MCAN_ExtMsgIDFilterElement_t *elem)
{
    uint32_t startAddr, elemAddr, regVal;
    uint32_t ramBase;

    assert(MCAN_isBaseValid(base));
    ramBase    = MCAN_getRamBase(base);
    startAddr  = MCAN_XIDFC_FLESA_Get(base->XIDFC);
    startAddr   = (uint32_t)(startAddr << 2U);
    elemAddr   = startAddr + (filtNum * MCAN_EXT_ID_FILTER_SIZE_WORDS * 4U);
    elemAddr   += MCAN_MCAN_MSG_MEM;

    regVal                             = 0U;
    regVal                            |= (uint32_t)(elem->efid1 << MCAN_EXT_ID_FILTER_EFID1_SHIFT);
    regVal                            |= (uint32_t)(elem->efec << MCAN_EXT_ID_FILTER_EFEC_SHIFT);
    *(uint32_t *)(ramBase + elemAddr)  = regVal;

    elemAddr                          += 4U;
    regVal                             = 0U;
    regVal                            |= (uint32_t)(elem->efid2 << MCAN_EXT_ID_FILTER_EFID2_SHIFT);
    regVal                            |= (uint32_t)(elem->eft << MCAN_EXT_ID_FILTER_EFT_SHIFT);
    *(uint32_t *)(ramBase + elemAddr)  = regVal;
}

void MCAN_lpbkModeEnable(MCAN_Type *base, uint32_t lpbkMode, uint32_t enable)
{
    assert(MCAN_isBaseValid(base));

    MCAN_writeProtectedRegAccessUnlock(base);

    if (1 == enable)
    {
        base->CCCR = (base->CCCR & ~(MCAN_CCCR_TEST_Msk)) | MCAN_CCCR_TEST_Set(0x1U);
        base->TEST = (base->TEST & ~(MCAN_TEST_LBCK_Msk)) | MCAN_TEST_LBCK_Set(enable);
        if (kMCAN_LPBK_MODE_INTERNAL == lpbkMode)
        {
            base->CCCR = (base->CCCR & ~(MCAN_CCCR_MON_Msk)) | MCAN_CCCR_MON_Set(0x1U);
        }
    }
    else
    {
        base->TEST = (base->TEST & ~(MCAN_TEST_LBCK_Msk)) | MCAN_TEST_LBCK_Set(enable);
        base->CCCR = (base->CCCR & ~(MCAN_CCCR_TEST_Msk)) | MCAN_CCCR_TEST_Set(0x0U);
        if (kMCAN_LPBK_MODE_INTERNAL == lpbkMode)
        {
            base->CCCR = (base->CCCR & ~(MCAN_CCCR_MON_Msk)) | MCAN_CCCR_MON_Set(0x0U);
        }
    }
    MCAN_writeProtectedRegAccessLock(base);
}

void MCAN_getErrCounters(MCAN_Type *base, MCAN_ErrCntStatus_t *errCounter)
{
    uint32_t regVal;

    assert(MCAN_isBaseValid(base));

    regVal                                        = base->ECR;
    errCounter->transErrLogCnt                    = MCAN_ECR_TEC_Get(regVal);
    errCounter->recErrCnt                         = MCAN_ECR_REC_Get(regVal);
    errCounter->rpStatus                          = MCAN_ECR_RP_Get(regVal);
    errCounter->canErrLogCnt                      = MCAN_ECR_CEL_Get(regVal);
}

void MCAN_getProtocolStatus(MCAN_Type *base, MCAN_ProtocolStatus_t *protStatus)
{
    uint32_t regVal;

    assert(MCAN_isBaseValid(base));

    regVal                    = base->PSR;
    protStatus->lastErrCode   = MCAN_PSR_LEC_Get(regVal);
    protStatus->act           = MCAN_PSR_ACT_Get(regVal);
    protStatus->errPassive    = MCAN_PSR_EP_Get(regVal);
    protStatus->warningStatus = MCAN_PSR_EW_Get(regVal);
    protStatus->busOffStatus  = MCAN_PSR_BO_Get(regVal);
    protStatus->dlec          = MCAN_PSR_DLEC_Get(regVal);
    protStatus->resi          = MCAN_PSR_RESI_Get(regVal);
    protStatus->rbrs          = MCAN_PSR_RBRS_Get(regVal);
    protStatus->rfdf          = MCAN_PSR_RFDF_Get(regVal);
    protStatus->pxe           = MCAN_PSR_PXE_Get(regVal);
    protStatus->tdcv          = MCAN_PSR_TDCV_Get(regVal);
}

void MCAN_enableIntr(MCAN_Type *base, uint32_t intrMask, uint32_t enable)
{
    assert(MCAN_isBaseValid(base));

    if (1 == enable)
    {
        base->IE |= intrMask;
    }
    else
    {
        base->IE &= ~intrMask;
    }
}

void MCAN_selectIntrLine(MCAN_Type *base, uint32_t intrMask, uint32_t lineNum)
{
    assert(MCAN_isBaseValid(base));

    if (kMCAN_INTR_LINE_NUM_0 == lineNum)
    {
        base->ILS &= ~intrMask;
    }
    else
    {
        base->ILS |= intrMask;
    }
}

uint32_t MCAN_getIntrLineSelectStatus(MCAN_Type *base)
{
    assert(MCAN_isBaseValid(base));

    return (base->ILS);
}

void MCAN_enableIntrLine(MCAN_Type *base, uint32_t lineNum, uint32_t enable)
{
    uint32_t regVal;

    assert(MCAN_isBaseValid(base));

    lineNum   &= MCAN_INTR_LINE_EN_MASK;
    regVal     = base->ILE;
    regVal     &= ~((uint32_t)0x1U << lineNum);
    regVal     |= (uint32_t)(enable << lineNum);
    base->ILE  = regVal;
}

uint32_t MCAN_getIntrStatus(MCAN_Type *base)
{
    assert(MCAN_isBaseValid(base));

    return (base->IR);
}

void MCAN_clearIntrStatus(MCAN_Type *base, uint32_t intrMask)
{
    assert(MCAN_isBaseValid(base));

    base->IR = intrMask;
}

void MCAN_getHighPriorityMsgStatus(MCAN_Type *base, MCAN_HighPriorityMsgInfo_t *hpm)
{
    uint32_t regVal;

    assert(MCAN_isBaseValid(base));

    regVal          = base->HPMS;
    hpm->bufIdx     = MCAN_HPMS_BIDX_Get(regVal);
    hpm->msi        = MCAN_HPMS_MSI_Get(regVal);
    hpm->filterIdx  = MCAN_HPMS_FIDX_Get(regVal);
    hpm->filterList = MCAN_HPMS_FLST_Get(regVal);
}

void MCAN_getRxFIFOStatus(MCAN_Type *base, MCAN_RxFIFOStatus_t *fifoStatus)
{
    uint32_t regVal;

    assert(MCAN_isBaseValid(base));

    switch (fifoStatus->num)
    {
        case kMCAN_RX_FIFO_NUM_0:
            regVal               = base->RXF0S;
            fifoStatus->fillLvl  = MCAN_RXF0S_F0FL_Get(regVal);
            fifoStatus->getIdx   = MCAN_RXF0S_F0GI_Get(regVal);
            fifoStatus->putIdx   = MCAN_RXF0S_F0PI_Get(regVal);
            fifoStatus->fifoFull = MCAN_RXF0S_F0F_Get(regVal);
            fifoStatus->msgLost  = MCAN_RXF0S_RF0L_Get(regVal);
            break;
        case kMCAN_RX_FIFO_NUM_1:
            regVal               = base->RXF1S;
            fifoStatus->fillLvl  = MCAN_RXF1S_F1FL_Get(regVal);
            fifoStatus->getIdx   = MCAN_RXF1S_F1GI_Get(regVal);
            fifoStatus->putIdx   = MCAN_RXF1S_F1PI_Get(regVal);
            fifoStatus->fifoFull = MCAN_RXF1S_F1F_Get(regVal);
            fifoStatus->msgLost  = MCAN_RXF1S_RF1L_Get(regVal);
            break;
        default:
            /* Invalid option */
            break;
    }
}

int32_t MCAN_writeRxFIFOAck(MCAN_Type *base, uint32_t fifoNum, uint32_t idx)
{
    int32_t  status;
    uint32_t size;

    assert(MCAN_isBaseValid(base));

    switch (fifoNum)
    {
        case kMCAN_RX_FIFO_NUM_0:
            size = MCAN_RXF0C_F0S_Get(base->RXF0C);
            if (size >= idx)
            {
                base->RXF0A = (base->RXF0A & ~(MCAN_RXF0A_F0AI_Msk)) | MCAN_RXF0A_F0AI_Set(idx);
                status      = 0;
            }
            else
            {
                status = -1;
            }
            break;
        case kMCAN_RX_FIFO_NUM_1:
            size = MCAN_RXF1C_F1S_Get(base->RXF1C);
            if (size >= idx)
            {
                base->RXF1A = (base->RXF1A & ~(MCAN_RXF1A_F1AI_Msk)) | MCAN_RXF1A_F1AI_Set(idx);
                status      = 0;
            }
            else
            {
                status = -1;
            }
            break;
        default:
            status = -1;
            break;
    }

    return status;
}

void MCAN_getTxFIFOQueStatus(MCAN_Type *base, MCAN_TxFIFOStatus_t *fifoStatus)
{
    uint32_t regVal;

    assert(MCAN_isBaseValid(base));

    regVal               = base->TXFQS;
    fifoStatus->freeLvl  = MCAN_TXFQS_TFFL_Get(regVal);
    fifoStatus->getIdx   = MCAN_TXFQS_TFGI_Get(regVal);
    fifoStatus->putIdx   = MCAN_TXFQS_TFQP_Get(regVal);
    fifoStatus->fifoFull = MCAN_TXFQS_TFQF_Get(regVal);
}

uint32_t MCAN_getTxBufReqPend(MCAN_Type *base)
{
    assert(MCAN_isBaseValid(base));

    return (base->TXBRP);
}

int32_t MCAN_txBufCancellationReq(MCAN_Type *base, uint32_t buffNum)
{
    int32_t  status;
    uint32_t regVal;

    assert(MCAN_isBaseValid(base));

    if (MCAN_TX_BUFFER_MAX > buffNum)
    {
        regVal  = base->TXBCR;
        regVal  |= ((uint32_t)1U << buffNum);

        // For writing to TXBCR CCE bit should be '0'. This need not be
        // reverted because for other qualified writes this is locked state
        // and can't be written.
        MCAN_writeProtectedRegAccessLock(base);
        base->TXBCR = regVal;

        status = 0;
    }
    else
    {
        status = -1;
    }
    return status;
}

uint32_t MCAN_getTxBufTransmissionStatus(MCAN_Type *base)
{
    assert(MCAN_isBaseValid(base));

    return (base->TXBTO);
}

uint32_t MCAN_txBufCancellationStatus(MCAN_Type *base)
{
    assert(MCAN_isBaseValid(base));

    return (base->TXBCF);
}

int32_t MCAN_txBufTransIntrEnable(MCAN_Type *base, uint32_t bufNum, uint32_t enable)
{
    int32_t  status;
    uint32_t regVal;

    assert(MCAN_isBaseValid(base));

    if (MCAN_TX_BUFFER_MAX > bufNum)
    {
        if (1 == enable)
        {
            regVal        = base->TXBTIE;
            regVal        |= ((uint32_t)1U << bufNum);
            base->TXBTIE  = regVal;
        }
        else
        {
            regVal        = base->TXBTIE;
            regVal        &= ~((uint32_t)0x1U << bufNum);
            base->TXBTIE  = regVal;
        }
        status = 0;
    }
    else
    {
        status = -1;
    }
    return status;
}

int32_t MCAN_getTxBufCancellationIntrEnable(MCAN_Type *base, uint32_t bufNum, uint32_t enable)
{
    int32_t  status;
    uint32_t regVal;

    assert(MCAN_isBaseValid(base));

    if (MCAN_TX_BUFFER_MAX > bufNum)
    {
        if (1 == enable)
        {
            regVal        = base->TXBCIE;
            regVal        |= ((uint32_t)0x1U << bufNum);
            base->TXBCIE  = regVal;
        }
        else
        {
            regVal        = base->TXBCIE;
            regVal        &= ~((uint32_t)0x1U << bufNum);
            base->TXBCIE  = regVal;
        }
        status = 0;
    }
    else
    {
        status = -1;
    }
    return status;
}

void MCAN_getTxEventFIFOStatus(MCAN_Type *base, MCAN_TxEventFIFOStatus_t *fifoStatus)
{
    uint32_t regVal = base->TXEFS;

    assert(MCAN_isBaseValid(base));

    fifoStatus->fillLvl  = MCAN_TXEFS_EFFL_Get(regVal);
    fifoStatus->getIdx   = MCAN_TXEFS_EFGI_Get(regVal);
    fifoStatus->putIdx   = MCAN_TXEFS_EFPI_Get(regVal);
    fifoStatus->fifoFull = MCAN_TXEFS_EFF_Get(regVal);
    fifoStatus->eleLost  = MCAN_TXEFS_TEFL_Get(regVal);
}

int32_t MCAN_writeTxEventFIFOAck(MCAN_Type *base, uint32_t idx)
{
    int32_t  status;
    uint32_t size;

    assert(MCAN_isBaseValid(base));

    size = MCAN_TXEFC_EFS_Get(base->TXEFC);
    if (size >= idx)
    {
        base->TXEFA = (base->TXEFA & ~(MCAN_TXEFA_EFAI_Msk)) | MCAN_TXEFA_EFAI_Set(idx);
        status      = 0;
    }
    else
    {
        status = -1;
    }

    return status;
}

/* ========================================================================== */
/*                          Advance Functions                                 */
/* ========================================================================== */

void MCAN_getRevisionId(MCAN_Type *base, MCAN_RevisionId_t *revId)
{
    uint32_t regVal;

    assert(MCAN_isBaseValid(base));

    regVal         = base->CREL;
    revId->day     = MCAN_CREL_DAY_Get(regVal);
    revId->mon     = MCAN_CREL_MON_Get(regVal);
    revId->year    = MCAN_CREL_YEAR_Get(regVal);
    revId->subStep = MCAN_CREL_SUBSTEP_Get(regVal);
    revId->step    = MCAN_CREL_STEP_Get(regVal);
    revId->rel     = MCAN_CREL_REL_Get(regVal);
}

uint32_t MCAN_getRxPinState(MCAN_Type *base)
{
    assert(MCAN_isBaseValid(base));
    return (MCAN_TEST_RX_Get(base->TEST));
}

void MCAN_setTxPinState(MCAN_Type *base, uint32_t state)
{
    assert(MCAN_isBaseValid(base));

    MCAN_writeProtectedRegAccessUnlock(base);

    base->CCCR = (base->CCCR & ~(MCAN_CCCR_TEST_Msk)) | MCAN_CCCR_TEST_Set(0x1U);
    base->TEST = (base->TEST & ~(MCAN_TEST_TX_Msk)) | MCAN_TEST_TX_Set(state);

    MCAN_writeProtectedRegAccessLock(base);
}

uint32_t MCAN_getTxPinState(MCAN_Type *base)
{
    assert(MCAN_isBaseValid(base));

    return (MCAN_TEST_TX_Get(base->TEST));
}

uint32_t MCAN_getTSCounterVal(MCAN_Type *base)
{
    return (MCAN_TSCV_TSC_Get(base->TSCV));
}

void MCAN_getBitTime(MCAN_Type *base, MCAN_BitTimingParams_t *configParams)
{
    uint32_t regVal;

    assert(MCAN_isBaseValid(base));

    regVal                          = base->NBTP;
    configParams->nomSynchJumpWidth = MCAN_NBTP_NSJW_Get(regVal);
    configParams->nomTimeSeg2       = MCAN_NBTP_NTSEG2_Get(regVal);
    configParams->nomTimeSeg1       = MCAN_NBTP_NTSEG1_Get(regVal);
    configParams->nomRatePrescalar  = MCAN_NBTP_NBRP_Get(regVal);

    regVal                           = base->DBTP;
    configParams->dataSynchJumpWidth = MCAN_DBTP_DSJW_Get(regVal);
    configParams->dataTimeSeg2       = MCAN_DBTP_DTSEG2_Get(regVal);
    configParams->dataTimeSeg1       = MCAN_DBTP_DTSEG1_Get(regVal);
    configParams->dataRatePrescalar  = MCAN_DBTP_DBRP_Get(regVal);
}

void MCAN_resetTSCounter(MCAN_Type *base)
{
    assert(MCAN_isBaseValid(base));

    base->TSCV = (base->TSCV & ~(MCAN_TSCV_TSC_Msk)) | MCAN_TSCV_TSC_Set(0x0U);
}

uint32_t MCAN_getTOCounterVal(MCAN_Type *base)
{
    assert(MCAN_isBaseValid(base));

    return (MCAN_TOCV_TOC_Get(base->TOCV));
}

uint32_t MCAN_getEndianVal(MCAN_Type *base)
{
    assert(MCAN_isBaseValid(base));

    return (MCAN_ENDN_ETV_Get(base->ENDN));
}

uint32_t MCAN_getExtIDANDMask(MCAN_Type *base)
{
    assert(MCAN_isBaseValid(base));

    return (MCAN_XIDAM_EIDM_Get(base->XIDAM));
}

/* ========================================================================== */
/*                          Internal Functions                                */
/* ========================================================================== */

static void MCAN_writeProtectedRegAccessUnlock(MCAN_Type *base)
{
    assert(MCAN_isBaseValid(base));

    base->CCCR = (base->CCCR & ~(MCAN_CCCR_CCE_Msk)) | MCAN_CCCR_CCE_Set(0x1U);
}

static void MCAN_writeProtectedRegAccessLock(MCAN_Type *base)
{
    assert(MCAN_isBaseValid(base));

    base->CCCR = (base->CCCR & ~(MCAN_CCCR_CCE_Msk)) | MCAN_CCCR_CCE_Set(0x0U);
}

static void MCAN_readMsg(uint32_t ramBase, uint32_t elemAddr, MCAN_RxBufElement_t *elem)
{
    uint32_t regVal = 0U, loopCnt = 0U;

    regVal    = *(uint32_t *)(ramBase + elemAddr);
    elem->id  = (uint32_t)((regVal & MCAN_RX_BUFFER_ELEM_ID_MASK) >> MCAN_RX_BUFFER_ELEM_ID_SHIFT);
    elem->rtr = (uint32_t)((regVal & MCAN_RX_BUFFER_ELEM_RTR_MASK) >> MCAN_RX_BUFFER_ELEM_RTR_SHIFT);
    elem->xtd = (uint32_t)((regVal & MCAN_RX_BUFFER_ELEM_XTD_MASK) >> MCAN_RX_BUFFER_ELEM_XTD_SHIFT);
    elem->esi = (uint32_t)((regVal & MCAN_RX_BUFFER_ELEM_ESI_MASK) >> MCAN_RX_BUFFER_ELEM_ESI_SHIFT);

    elemAddr   += 4U;
    regVal      = *(uint32_t *)(ramBase + elemAddr);
    elem->rxts  = (uint32_t)((regVal & MCAN_RX_BUFFER_ELEM_RXTS_MASK) >> MCAN_RX_BUFFER_ELEM_RXTS_SHIFT);
    elem->dlc   = (uint32_t)((regVal & MCAN_RX_BUFFER_ELEM_DLC_MASK) >> MCAN_RX_BUFFER_ELEM_DLC_SHIFT);
    elem->brs   = (uint32_t)((regVal & MCAN_RX_BUFFER_ELEM_BRS_MASK) >> MCAN_RX_BUFFER_ELEM_BRS_SHIFT);
    elem->fdf   = (uint32_t)((regVal & MCAN_RX_BUFFER_ELEM_FDF_MASK) >> MCAN_RX_BUFFER_ELEM_FDF_SHIFT);
    elem->fidx  = (uint32_t)((regVal & MCAN_RX_BUFFER_ELEM_FIDX_MASK) >> MCAN_RX_BUFFER_ELEM_FIDX_SHIFT);
    elem->anmf  = (uint32_t)((regVal & MCAN_RX_BUFFER_ELEM_ANMF_MASK) >> MCAN_RX_BUFFER_ELEM_ANMF_SHIFT);
    elemAddr   += 4U;

    loopCnt = 0U;
    /* Reading words from message RAM and forming payload bytes out of it */
    while ((4U <= (MCAN_getDataSize(elem->dlc) - loopCnt)) && (0U != (MCAN_getDataSize(elem->dlc) - loopCnt)))
    {
        assert((loopCnt + 3) < MCAN_MAX_PAYLOAD_BYTES);
        regVal                      = *(uint32_t *)(ramBase + elemAddr);
        elem->data[loopCnt]         = (uint16_t)(regVal & 0x000000FFU);
        elem->data[(loopCnt + 1U)]  = (uint16_t)((regVal & 0x0000FF00U) >> 8U);
        elem->data[(loopCnt + 2U)]  = (uint16_t)((regVal & 0x00FF0000U) >> 16U);
        elem->data[(loopCnt + 3U)]  = (uint16_t)((regVal & 0xFF000000U) >> 24U);
        elemAddr                   += 4U;
        loopCnt                    += 4U;
    }
    /* Reading remaining bytes from message RAM */
    if (0U < (MCAN_getDataSize(elem->dlc) - loopCnt))
    {
        assert((loopCnt + 2) < MCAN_MAX_PAYLOAD_BYTES);
        regVal                     = *(uint32_t *)(ramBase + elemAddr);
        elem->data[loopCnt]        = (uint16_t)(regVal & 0x000000FFU);
        elem->data[(loopCnt + 1U)] = (uint16_t)((regVal & 0x0000FF00U) >> 8U);
        elem->data[(loopCnt + 2U)] = (uint16_t)((regVal & 0x00FF0000U) >> 16U);
    }
}

static void MCAN_writeMsg(uint32_t ramBase, uint32_t elemAddr, const MCAN_TxBufElement_t *elem)
{
    uint32_t regVal = 0, loopCnt = 0U;

    regVal                             = 0U;
    regVal                            |= (((uint32_t)(elem->id << MCAN_TX_BUFFER_ELEM_ID_SHIFT)) |
               ((uint32_t)(elem->rtr << MCAN_TX_BUFFER_ELEM_RTR_SHIFT)) |
               ((uint32_t)(elem->xtd << MCAN_TX_BUFFER_ELEM_XTD_SHIFT)) |
               ((uint32_t)(elem->esi << MCAN_TX_BUFFER_ELEM_ESI_SHIFT)));
    *(uint32_t *)(ramBase + elemAddr)  = regVal;
    elemAddr                          += 4U;

    regVal  = 0U;
    regVal  |= ((uint32_t)(elem->dlc << MCAN_TX_BUFFER_ELEM_DLC_SHIFT)) |
              ((uint32_t)(elem->brs << MCAN_TX_BUFFER_ELEM_BRS_SHIFT)) |
              ((uint32_t)(elem->fdf << MCAN_TX_BUFFER_ELEM_FDF_SHIFT)) |
              ((uint32_t)(elem->efc << MCAN_TX_BUFFER_ELEM_EFC_SHIFT)) |
              ((uint32_t)(elem->mm << MCAN_TX_BUFFER_ELEM_MM_SHIFT));
    *(uint32_t *)(ramBase + elemAddr)  = regVal;
    elemAddr                          += 4U;

    loopCnt = 0U;
    /* Framing words out of the payload bytes and writing it to message RAM */
    while ((4U <= (MCAN_getDataSize(elem->dlc) - loopCnt)) && (0U != (MCAN_getDataSize(elem->dlc) - loopCnt)))
    {
        assert((loopCnt + 3) < MCAN_MAX_PAYLOAD_BYTES);
        regVal  = 0U;
        regVal |= ((uint32_t)elem->data[loopCnt] | ((uint32_t)elem->data[(loopCnt + 1U)] << 8U) |
                   ((uint32_t)elem->data[(loopCnt + 2U)] << 16U) | ((uint32_t)elem->data[(loopCnt + 3U)] << 24U));
        *(uint32_t *)(ramBase + elemAddr)  = regVal;
        elemAddr                          += 4U;
        loopCnt                           += 4U;
    }
    /* Framing a word out of remaining payload bytes and writing it to message RAM */
    if (0U < (MCAN_getDataSize(elem->dlc) - loopCnt))
    {
        assert((loopCnt + 3) < MCAN_MAX_PAYLOAD_BYTES);
        regVal  = 0U;
        regVal |= ((uint32_t)elem->data[loopCnt] | ((uint32_t)elem->data[(loopCnt + 1U)] << 8U) |
                   ((uint32_t)elem->data[(loopCnt + 2U)] << 16U) | ((uint32_t)elem->data[(loopCnt + 3U)] << 24U));
        *(uint32_t *)(ramBase + elemAddr) = regVal;
    }
}

static uint32_t MCAN_getDataSize(uint32_t dlc)
{
    uint32_t dataSize[16] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 12, 16, 20, 24, 32, 48, 64 };
    assert(dlc < 16);
    return (dataSize[dlc]);
}

static uint32_t MCAN_getMsgObjSize(uint32_t elemSize)
{
    uint32_t objSize[8] = { 4, 5, 6, 7, 8, 10, 14, 18 };
    assert(elemSize < 8);
    return (objSize[elemSize]);
}

status_t MCAN_registerCallback(MCAN_Type *base,MCAN_IntSrc_t intsrc, MCAN_Callback_t func, uint32_t priority)
{
    MCAN_Idx_t idx = kMCAN_IDX_A;
    assert(intsrc < kMCAN_INT_MAX);
    assert(func);
    
    if(base == MCANA)
    {
        idx = kMCAN_IDX_A;
    }
    else if(base == MCANB)
    {
        idx = kMCAN_IDX_B;
    }
    else
    {
        idx = kMCAN_IDX_C;
    }

    if (s_mcanISR.func[idx][intsrc] != NULL)
    {
        /* MCAN ISR callback has been registered already, return failure */
        return kSTATUS_FAIL;
    }

    /* Enable the driver interrupt service */
    s_mcanISR.func[idx][intsrc] = func;
    
    /* Set interrupt priority and enable the interrupt */
    NVIC_SetPriority(s_mcanIRQ[idx][intsrc], priority);
    NVIC_EnableIRQ(s_mcanIRQ[idx][intsrc]);

    return kSTATUS_SUCCESS;
}

status_t MCAN_unregisterCallback(MCAN_Type *base,MCAN_IntSrc_t intsrc)
{
    MCAN_Idx_t idx = kMCAN_IDX_A;
    
    assert(intsrc < kMCAN_INT_MAX);

    if(base == MCANA)
    {
        idx = kMCAN_IDX_A;
    }
    else if(base == MCANB)
    {
        idx = kMCAN_IDX_B;
    }
    else
    {
        idx = kMCAN_IDX_C;
    }
    
    if (s_mcanISR.func[idx][intsrc] == NULL)
    {
        /* MCAN instance hasn't been registered, return failure */
        return kSTATUS_INVALID_ARGUMENT;
    }

    /* Restore interrupt priority and disable the interrupt */
    NVIC_SetPriority(s_mcanIRQ[idx][intsrc], 0U);
    NVIC_DisableIRQ(s_mcanIRQ[idx][intsrc]);

    /* Clear the interrupt service and handle */
    s_mcanISR.func[idx][intsrc] = NULL;

    return kSTATUS_SUCCESS;
}

 void MCAN_handlerIRQ(MCAN_Idx_t idx,MCAN_IntSrc_t intsrc,MCAN_Type *base)
{
    if (s_mcanISR.func[idx][intsrc] != NULL)
    {
        s_mcanISR.func[idx][intsrc](base);
    }
}

#if defined(MCANA)
void MCANA_INT0_DriverHandler(void)
{
    MCAN_handlerIRQ(kMCAN_IDX_A,kMCAN_INT0,MCANA);
    ISR_EXIT_BARRIER();
}

void MCANA_INT1_DriverHandler(void)
{
    MCAN_handlerIRQ(kMCAN_IDX_A,kMCAN_INT1,MCANA);
    ISR_EXIT_BARRIER();
}
#endif

#if defined(MCANB)
void MCANB_INT0_DriverHandler(void)
{
    MCAN_handlerIRQ(kMCAN_IDX_B,kMCAN_INT0,MCANB);
    ISR_EXIT_BARRIER();
}

void MCANB_INT1_DriverHandler(void)
{
    MCAN_handlerIRQ(kMCAN_IDX_B,kMCAN_INT1,MCANB);
    ISR_EXIT_BARRIER();
}
#endif

#if defined(MCANC)
void MCANC_INT0_DriverHandler(void)
{
    MCAN_handlerIRQ(kMCAN_IDX_C,kMCAN_INT0,MCANC);
    ISR_EXIT_BARRIER();
}

void MCANC_INT1_DriverHandler(void)
{
    MCAN_handlerIRQ(kMCAN_IDX_C,kMCAN_INT1,MCANC);
    ISR_EXIT_BARRIER();
}
#endif
