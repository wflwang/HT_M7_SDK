/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_spi.c
 * \brief SDK SPI driver source file
 * \version 1.0.0
 */
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_spi.h"
#include "clock_config.h"
#include "hte_debug_console.h"
#include "hte_sysctrl.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! \brief SPI transmit delay timeout */
#define SPI_MAX_DELAY 0xFFFFFFFFU

/*! \brief SPI IRQ transmit delay timeout */
#define SPI_IT_DELAY  500U
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * \brief Handle SPI Communication Timeout.
 * \param[in] hspi: pointer to a SPI_HandleTypeDef structure that contains
 *              the configuration information for SPI module.
 * \param[in] Flag SPI flag to check
 * \param[in] FlagStatus flag state to check
 * \param[in] Timeout Timeout duration
 * \param[in] Tickstart Tick start value
 * \return status
 */
static status_t SPI_waitOnFlagUntilTimeout(SPI_HandleTypeDef_t *hspi, uint32_t Flag, SPI_flagStatus FlagStatus,
                                           uint32_t Timeout, uint32_t Tickstart);
/*!
 * \brief  Handle the data 8-bit transmit in Interrupt mode.
 * \param[in]  hspi: pointer to a SPI_HandleTypeDef_t structure that contains
 *               the configuration information for SPI module.
 *
 */
static void SPI_txISR8Bit(SPI_HandleTypeDef_t *hspi);

/*!
 * \brief  Handle the data 16-bit transmit in Interrupt mode.
 * \param[in]  hspi: pointer to a SPI_HandleTypeDef_t structure that contains
 *               the configuration information for SPI module.
 *
 */
static void SPI_txISR16Bit(SPI_HandleTypeDef_t *hspi);

/*!
 * \brief  Handle the data 32-bit transmit in Interrupt mode.
 * \param[in]  hspi: pointer to a SPI_HandleTypeDef_t structure that contains
 *               the configuration information for SPI module.
 *
 */
static void SPI_txISR32Bit(SPI_HandleTypeDef_t *hspi);

/*!
 * \brief  Manage the receive 8-bit in Interrupt context.
 * \param[in]  hspi: pointer to a SPI_HandleTypeDef_t structure that contains
 *               the configuration information for SPI module.
 *
 */
static void     SPI_rxISR8Bit(SPI_HandleTypeDef_t *hspi);

/*!
 * \brief  Manage the 16-bit receive in Interrupt context.
 * \param[in]  hspi: pointer to a SPI_HandleTypeDef_t structure that contains
 *               the configuration information for SPI module.
 *
 */
static void     SPI_rxISR16Bit(SPI_HandleTypeDef_t *hspi);

/*!
 * \brief  Manage the 32-bit receive in Interrupt context.
 * \param[in]  hspi: pointer to a SPI_HandleTypeDef_t structure that contains
 *               the configuration information for SPI module.
 *
 */
static void SPI_rxISR32Bit(SPI_HandleTypeDef_t *hspi);

/*!
 * \brief  Close Transfer and clear flags.
 * \param[in]  hspi: pointer to a SPI_HandleTypeDef structure that contains
 *               the configuration information for SPI module.
 */
static void SPI_closeTransfer(SPI_HandleTypeDef_t *hspi);

/*!
 * \brief     For SPI DMA tx IRQ
 * \param[in]  index: DMA index
 *
 */
static void     SPI_DMA_IRQTxCpltCallBcak(DMA_Index_t index);

/*!
 * \brief     For SPI DMA rx IRQ
 * \param[in]  index: DMA index
 *
 */
static void     SPI_DMA_IRQRxCpltCallBcak(DMA_Index_t index);

/*!
 * \brief  Handle SPI interrupt request.
 * \param[in]  hspi: pointer to a SPI_HandleTypeDef_t structure that contains
 *               the configuration information for the specified SPI module.
 *
 */
static void SPI_IRQHandler(SPI_HandleTypeDef_t *hspi);


/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! \brief Array of SPI transfer handle */
SPI_HandleTypeDef_t g_spiHandle[SPI_BUS_MAX] = { 0 };
/*! \brief Array of SPI peripheral base address */
SPI_Type           *g_spiBases[SPI_BUS_MAX]  = SPI_BASES;
/*! \brief Array of SPI IRQ number */
const IRQn_Type g_spiIRQ[SPI_BUS_MAX] = SPI_IRQS;
/*! \brief Array of SPI DMA Tx transfer done flags */
static uint8_t s_spiDMATxDoneFlag[kDMA_INDEX_CH_MAX] = { 0 };
/*! \brief Array of SPI DMA RX transfer done flags */
static uint8_t s_spiDMARxDoneFlag[kDMA_INDEX_CH_MAX] = { 0 };

/*******************************************************************************
 * Codes
 ******************************************************************************/
SPI_HandleTypeDef_t *SPI_getHandle(uint32_t spiBus)
{
    assert(spiBus < SPI_BUS_MAX);
    return &g_spiHandle[spiBus];
}

SPI_Type *SPI_getInstance(uint32_t spiBus)
{
    assert(spiBus < SPI_BUS_MAX);
    return g_spiBases[spiBus];
}

status_t SPI_registerCallback(SPI_HandleTypeDef_t *hspi, SPI_CallbackID_t CpltID, SPI_Callback_t pCallback)
{
    assert(pCallback);
    status_t status = kSTATUS_SUCCESS;

    /**register start***/
    if (HAL_SPI_STATE_READY == hspi->state)
    {
        switch (CpltID)
        {
            case kSPI_TX_CB_ID:
                hspi->txCpltCallback = pCallback;
                break;

            case kSPI_RX_CB_ID:
                hspi->rxCpltCallback = pCallback;
                break;

            case kSPI_TXRX_CB_ID:
                hspi->txRxCpltCallback = pCallback;
                break;

            default:
                /* Update the error code */
                SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_INVALID_CALLBACK);

                /* Return error status */
                status = kSTATUS_FAIL;
                break;
        }
    }
    else if (HAL_SPI_STATE_RESET == hspi->state)
    {
        switch (CpltID)
        {
            case kSPI_MSPINIT_CB_ID:
                hspi->mspInitCallback = pCallback;
                break;

            case kSPI_MSPDEINIT_CB_ID:
                hspi->mspDeInitCallback = pCallback;
                break;

            default:
                /* Update the error code */
                SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_INVALID_CALLBACK);

                /* Return error status */
                status = kSTATUS_FAIL;
                break;
        }
    }
    else
    {
        /* Update the error code */
        SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_INVALID_CALLBACK);

        /* Return error status */
        status = kSTATUS_FAIL;
    }

    return status;
}

status_t SPI_unregisterCallback(SPI_HandleTypeDef_t *hspi, SPI_CallbackID_t CallbackID)
{
    status_t status = kSTATUS_SUCCESS;

    if (HAL_SPI_STATE_READY == hspi->state)
    {
        switch (CallbackID)
        {
            case kSPI_TX_CB_ID:
                hspi->txCpltCallback = NULL; /* Legacy weak TxCpltCallback       */
                break;

            case kSPI_RX_CB_ID:
                hspi->rxCpltCallback = NULL; /* Legacy weak RxCpltCallback       */
                break;

            case kSPI_TXRX_CB_ID:
                hspi->txRxCpltCallback = NULL; /* Legacy weak TxRxCpltCallback     */
                break;

            case kSPI_ERR_CB_ID:
                hspi->errorCallback = NULL; /* Legacy weak errorCallback   */
                break;

            default:
                /* Update the error code */
                SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_INVALID_CALLBACK);

                /* Return error status */
                status = kSTATUS_FAIL;
                break;
        }
    }
    else if (HAL_SPI_STATE_RESET == hspi->state)
    {
        switch (CallbackID)
        {
            case kSPI_MSPINIT_CB_ID:
                hspi->mspInitCallback = NULL; /* Legacy weak mspInitCpltCallback   */
                break;

            case kSPI_MSPDEINIT_CB_ID:
                hspi->mspDeInitCallback = NULL; /* Legacy weak mspDeInitCpltCallback */
                break;

            default:
                /* Update the error code */
                SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_INVALID_CALLBACK);

                /* Return error status */
                status = kSTATUS_FAIL;

                break;
        }
    }
    else
    {
        /* Update the error code */
        SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_INVALID_CALLBACK);

        /* Return error status */
        status = kSTATUS_FAIL;
    }

    /* Release Lock */

    return status;

}

status_t SPI_getDefaultCfg(SPI_HandleTypeDef_t *hspi)
{
    /* Check the SPI handle allocation */
    if (hspi == NULL)
    {
        return kSTATUS_FAIL;
    }

    hspi->init.mode               = SPI_MODE_MASTER;
    hspi->init.frameFormat        = SPI_FRAME_FORMAT_MOTOROLA;
    hspi->init.direction          = SPI_DIRECTION_TX_AND_RX;
    hspi->init.enhanceFrameFormat = SPI_ENHANCE_FRAME_FORMAT_STANDARD_SPI;
    hspi->init.dataSize           = SPI_DATASIZE_8BIT;
    hspi->init.CLKPolarity        = SPI_POLARITY_LOW;
    hspi->init.CLKPhase           = SPI_PHASE_1EDGE;
    hspi->init.slaveOutEn         = SPI_SLVOUTEN_ENABLE;
    hspi->init.selectToggleEn     = SPI_SSTE_DISABLE;
    hspi->init.loopBackEn         = SPI_LOOPBACK_DISABLE;
    hspi->init.dynamicWaitEn      = SPI_DWS_DISABLE;
    hspi->init.baudRatePrescaler  = 10;
    hspi->init.txStartXferlevel   = 0;
    hspi->init.txFifoThreshold    = 31;  /* <= 31 trriger tx empty */
    hspi->init.rxFifoThreshold    = 128; /* > 128 trriger rx full */
    hspi->init.numberOfDataFrame  = 1;
    hspi->init.rxSampleDelay      = 0;
    hspi->init.txDMALevel         = 1;
    hspi->init.rxDMALevel         = 0;
    hspi->init.enhanceTransType   = SPI_ENHANCE_TRANS_TYPE_TT2;
    hspi->init.enhanceAddrLens    = SPI_ENHANCE_ADDR_LENS_L24;
    hspi->init.enhanceInstLens    = SPI_ENHANCE_INST_LENS_L8;
    hspi->init.enhanceWaitCycles  = 0;
    hspi->init.enhanceDDREn       = SPI_ENHANCE_DDR_DISABLE;
    hspi->init.enhanceInstDDREn   = SPI_ENHANCE_INST_DDR_DISABLE;
    hspi->init.enhanceRxDsEn      = SPI_ENHANCE_RXDS_DISABLE;
    hspi->init.enhanceDataMaskEn  = SPI_ENHANCE_DATA_MASK_DISABLE;
    hspi->init.enhanceClkStrechEn = SPI_ENHANCE_CLK_STRETCH_DISABLE;

    return kSTATUS_SUCCESS;
}

status_t SPI_init(SPI_HandleTypeDef_t *hspi)
{
    /* Check the SPI handle allocation */
    if (hspi == NULL)
    {
        return kSTATUS_FAIL;
    }

    /* Check the parameters */
    assert(IS_SPI_ALL_INSTANCE(hspi->instance));
    assert(IS_SPI_MODE(hspi->init.mode));
    assert(IS_SPI_DIRECTION(hspi->init.direction));
    assert(IS_SPI_DATASIZE(hspi->init.dataSize));
    assert(IS_SPI_BAUDRATE_PRESCALER(hspi->init.baudRatePrescaler));
    assert(IS_SPI_FRAMEFORMAT(hspi->init.frameFormat));
    assert(IS_SPI_ENHANCE_FRAMEFORMAT(hspi->init.enhanceFrameFormat));
    assert(hspi->init.txFifoThreshold <= SPI_MAX_TX_FIFO_LENGTH);
    assert(hspi->init.rxFifoThreshold <= SPI_MAX_RX_FIFO_LENGTH);

    if (hspi->state == HAL_SPI_STATE_RESET)
    {
        /* Init the SPI Callback settings */
        hspi->txCpltCallback   = SPI_txCpltCallback;   /* Legacy weak TxCpltCallback       */
        hspi->rxCpltCallback   = SPI_rxCpltCallback;   /* Legacy weak RxCpltCallback       */
        hspi->txRxCpltCallback = SPI_txRxCpltCallback; /* Legacy weak TxRxCpltCallback     */
        hspi->errorCallback    = SPI_errorCallback;    /* Legacy weak ErrorCallback        */

        if (hspi->mspInitCallback == NULL)
        {
            hspi->mspInitCallback = SPI_mspInit; /* Legacy weak MspInit  */
        }

        /* Init the low level hardware : GPIO, CLOCK, NVIC... */
        hspi->mspInitCallback(hspi);
    }

    hspi->state = HAL_SPI_STATE_BUSY;

#if defined(HTE_DEVICE_HS32F7D377_CPU1)
    /* disable xip function */
    SYSCTRL_setSpiXipEn((SYSCTRL_SPIIndex_t)(((uint32_t)(hspi->instance) - SPIA_BASE) / 0x1000), kSYSC_DISABLE);
    hspi->XIPClosedFlag = 1;
#endif
    /* Disable the selected SPI peripheral */
    HTE_SPI_DISABLE(hspi);

    /*----------------------- SPIx CTRLR0 & CTRLR1 Configuration ---------------------*/
    /* Configure : SPI Mode, Communication Mode, Clock polarity and phase, Communication mode*/

    /* SPIx CTRLR0 Configuration */
    hspi->instance->CTRLR0 &=
        ~(SPI_CTRLR0_DFS_Msk | SPI_CTRLR0_FRF_Msk | SPI_CTRLR0_SCPH_Msk | SPI_CTRLR0_SCPOL_Msk | SPI_CTRLR0_TMOD_Msk |
          SPI_CTRLR0_SLV_OE_Msk | SPI_CTRLR0_SRL_Msk | SPI_CTRLR0_SPI_FRF_Msk | SPI_CTRLR0_SPI_IS_MST_Msk);

    hspi->instance->CTRLR0 = SPI_CTRLR0_DFS_Set(hspi->init.dataSize) | SPI_CTRLR0_FRF_Set(hspi->init.frameFormat) |
                             SPI_CTRLR0_SCPH_Set(hspi->init.CLKPhase) | SPI_CTRLR0_SCPOL_Set(hspi->init.CLKPolarity) |
                             SPI_CTRLR0_TMOD_Set(hspi->init.direction) | SPI_CTRLR0_SLV_OE_Set(hspi->init.slaveOutEn) |
                             SPI_CTRLR0_SRL_Set(hspi->init.loopBackEn) |
                             SPI_CTRLR0_SPI_FRF_Set(hspi->init.enhanceFrameFormat) |
                             SPI_CTRLR0_SPI_IS_MST_Set(hspi->init.mode);

    if (hspi->init.frameFormat == SPI_FRAME_FORMAT_MOTOROLA)
    {
        hspi->instance->CTRLR0 &= ~(SPI_CTRLR0_SPI_DWS_EN_Msk);
        hspi->instance->CTRLR0 |= SPI_CTRLR0_SPI_DWS_EN_Set(hspi->init.dynamicWaitEn);

        if (hspi->init.CLKPhase == SPI_PHASE_1EDGE)
        {
            hspi->instance->CTRLR0 &= ~(SPI_CTRLR0_SSTE_Msk);
            hspi->instance->CTRLR0 |= SPI_CTRLR0_SSTE_Set(hspi->init.selectToggleEn);
        }
    }

    if (hspi->init.mode == SPI_MODE_MASTER)
    {
        hspi->instance->CTRLR1 &= ~(SPI_CTRLR1_NDF_Msk);
        hspi->instance->CTRLR1 |= SPI_CTRLR1_NDF_Set(hspi->init.numberOfDataFrame);

        hspi->instance->SER = SPI_SER_SER_Set(1U);
    }

    if (hspi->init.mode == SPI_MODE_SLAVE)
    {
        hspi->instance->CTRLR0 &= ~(SPI_CTRLR0_SLV_OE_Msk);
        hspi->instance->CTRLR0 |= SPI_CTRLR0_SLV_OE_Set(hspi->init.slaveOutEn);
    }

    hspi->instance->TXFTLR &= ~(SPI_TXFTLR_TXFTHR_Msk | SPI_TXFTLR_TFT_Msk);
    hspi->instance->TXFTLR |=
        SPI_TXFTLR_TXFTHR_Set(hspi->init.txStartXferlevel) | SPI_TXFTLR_TFT_Set(hspi->init.txFifoThreshold);

    hspi->instance->RXFTLR &= ~(SPI_RXFTLR_RFT_Msk);
    hspi->instance->RXFTLR |= SPI_RXFTLR_RFT_Set(hspi->init.rxFifoThreshold);

    hspi->instance->BAUDR &= ~(SPI_BAUDR_SCKDV_Msk);
    hspi->instance->BAUDR |= SPI_BAUDR_SCKDV_Set(hspi->init.baudRatePrescaler >> 1);

    hspi->instance->RX_SAMPLE_DELAY &= ~(SPI_RX_SAMPLE_DELAY_RSD_Msk);
    hspi->instance->RX_SAMPLE_DELAY |= SPI_RX_SAMPLE_DELAY_RSD_Set(hspi->init.rxSampleDelay);

    /* for enhance spi mode */
    if (hspi->init.enhanceFrameFormat > SPI_ENHANCE_FRAME_FORMAT_STANDARD_SPI)
    {
        hspi->instance->SPI_CTRLR0 &=
            ~(SPI_SPI_CTRLR0_TRANS_TYPE_Msk | SPI_SPI_CTRLR0_ADDR_L_Msk | SPI_SPI_CTRLR0_INST_L_Msk |
              SPI_SPI_CTRLR0_WAIT_CYCLES_Msk | SPI_SPI_CTRLR0_SPI_DDR_EN_Msk | SPI_SPI_CTRLR0_INST_DDR_EN_Msk |
              SPI_SPI_CTRLR0_SPI_RXDS_EN_Msk | SPI_SPI_CTRLR0_SPI_DM_EN_Msk | SPI_SPI_CTRLR0_CLK_STRETCH_EN_Msk);

        hspi->instance->SPI_CTRLR0 = SPI_SPI_CTRLR0_TRANS_TYPE_Set(hspi->init.enhanceTransType) |
                                     SPI_SPI_CTRLR0_ADDR_L_Set(hspi->init.enhanceAddrLens) |
                                     SPI_SPI_CTRLR0_INST_L_Set(hspi->init.enhanceInstLens) |
                                     SPI_SPI_CTRLR0_WAIT_CYCLES_Set(hspi->init.enhanceWaitCycles) |
                                     SPI_SPI_CTRLR0_SPI_DDR_EN_Set(hspi->init.enhanceDDREn) |
                                     SPI_SPI_CTRLR0_INST_DDR_EN_Set(hspi->init.enhanceInstDDREn) |
                                     SPI_SPI_CTRLR0_SPI_RXDS_EN_Set(hspi->init.enhanceRxDsEn) |
                                     SPI_SPI_CTRLR0_SPI_DM_EN_Set(hspi->init.enhanceDataMaskEn) |
                                     SPI_SPI_CTRLR0_CLK_STRETCH_EN_Set(hspi->init.enhanceClkStrechEn);
    }

    /* interrupt mask */
    hspi->instance->IMR &= ~(SPI_IMR_TXOIM_Msk | SPI_IMR_TXUIM_Msk | SPI_IMR_RXOIM_Msk | SPI_IMR_RXUIM_Msk |

                             SPI_IMR_MSTIM_Msk | SPI_IMR_XRXOIM_Msk);

    hspi->instance->IMR = (SPI_IMR_TXOIM_Set(1U) | SPI_IMR_TXUIM_Set(1U) | SPI_IMR_RXOIM_Set(1U) |
                           SPI_IMR_RXUIM_Set(1U) | SPI_IMR_MSTIM_Set(1U) | SPI_IMR_XRXOIM_Set(1U));

    hspi->errorCode = HTE_SPI_ERROR_NONE;
    hspi->state     = HAL_SPI_STATE_READY;

    return kSTATUS_SUCCESS;
}

status_t SPI_deInit(SPI_HandleTypeDef_t *hspi)
{
    /* Check the SPI handle allocation */
    if (hspi == NULL)
    {
        return kSTATUS_FAIL;
    }

    /* Check SPI instance parameter */
    assert(IS_SPI_ALL_INSTANCE(hspi->instance));

    hspi->state = HAL_SPI_STATE_BUSY;

    /* Disable the SPI Peripheral Clock */
    HTE_SPI_DISABLE(hspi);

    if (hspi->mspDeInitCallback == NULL)
    {
        hspi->mspDeInitCallback = SPI_mspDeInit; /* Legacy weak MspDeInit  */
    }

    /* If needed, DeInit the low level hardware: GPIO, CLOCK, NVIC... */
    hspi->mspDeInitCallback(hspi);

#if defined(HTE_DEVICE_HS32F7D377_CPU1)
    /* enable xip function */
    SYSCTRL_setSpiXipEn((SYSCTRL_SPIIndex_t)(((uint32_t)(hspi->instance) - SPIA_BASE) / 0x1000), kSYSC_ENABLE);
    hspi->XIPClosedFlag = 0;
#endif
    hspi->errorCode = HTE_SPI_ERROR_NONE;
    hspi->state     = HAL_SPI_STATE_RESET;

    return kSTATUS_SUCCESS;
}

__WEAK void SPI_mspInit(SPI_HandleTypeDef_t *hspi)
{
    /* Prevent unused argument(s) compilation warning */
    SPI_UNUSED(hspi);

    /* NOTE : This function should not be modified, when the callback is needed,
              the HAL_SPI_MspInit should be implemented in the user file
     */
}

__WEAK void SPI_mspDeInit(SPI_HandleTypeDef_t *hspi)
{
    /* Prevent unused argument(s) compilation warning */
    SPI_UNUSED(hspi);

    /* NOTE : This function should not be modified, when the callback is needed,
              the HAL_SPI_MspDeInit should be implemented in the user file
     */
}

status_t SPI_transmit(SPI_HandleTypeDef_t *hspi, uint8_t *pData, uint32_t size, uint32_t timeOut)
{
    status_t errorcode = kSTATUS_SUCCESS;
    uint32_t tickstart;

    /* Check Direction parameter */
    assert(IS_SPI_DIRECTION_TX_SUPPORT(hspi->init.direction));

    if (hspi->state != HAL_SPI_STATE_READY)
    {
        errorcode = kSTATUS_INVALID_ARGUMENT;
        return errorcode;
    }

    /* Set the transaction information */
    hspi->state       = HAL_SPI_STATE_BUSY_TX;
    hspi->errorCode   = HTE_SPI_ERROR_NONE;
    hspi->pTxBuffPtr  = (uint8_t *)pData;
    hspi->txXferSize  = size;
    hspi->txXferCount = size;

    /*Init field not used in handle to zero */
    hspi->pRxBuffPtr  = NULL;
    hspi->rxXferSize  = (uint16_t)0UL;
    hspi->rxXferCount = (uint16_t)0UL;
    hspi->txISR       = NULL;
    hspi->rxISR       = NULL;

    tickstart = BOARD_getTick();

    /* Enable SPI peripheral */
    HTE_SPI_ENABLE(hspi);

    /* Transmit data in 32 Bit mode */
    if (hspi->init.dataSize > SPI_DATASIZE_16BIT)
    {
        /* Transmit data in 32 Bit mode */
        while (hspi->txXferCount > 0UL)
        {
            /* Wait until TX FIFO not full flag is set to send data */
            if (HTE_SPI_GET_FLAG(hspi, SPI_FLAG_TFNF))
            {
                *((__IO uint32_t *)&hspi->instance->DR0)  = *((uint32_t *)hspi->pTxBuffPtr);
                hspi->pTxBuffPtr                         += sizeof(uint32_t);
                hspi->txXferCount--;
            }
            else
            {
                /* Timeout management */
                if ((((BOARD_getTick() - tickstart) >= timeOut) && (timeOut != SPI_MAX_DELAY)) || (timeOut == 0U))
                {
                    /* Call standard close procedure with error check */
                    SPI_closeTransfer(hspi);

                    SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_TIMEOUT);
                    hspi->state = HAL_SPI_STATE_READY;
                    return kSTATUS_TIMEOUT;
                }
            }
        }
    }
    /* Transmit data in 16 Bit mode */
    else if (hspi->init.dataSize > SPI_DATASIZE_8BIT)
    {
        /* Transmit data in 16 Bit mode */
        while (hspi->txXferCount > 0UL)
        {
            /* Wait until TX FIFO not full flag  is set to send data */
            if (HTE_SPI_GET_FLAG(hspi, SPI_FLAG_TFNF))
            {
                *((__IO uint32_t *)&hspi->instance->DR0) = *((uint16_t *)hspi->pTxBuffPtr);

                hspi->pTxBuffPtr += sizeof(uint16_t);
                hspi->txXferCount--;
            }
            else
            {
                /* Timeout management */
                if ((((BOARD_getTick() - tickstart) >= timeOut) && (timeOut != SPI_MAX_DELAY)) || (timeOut == 0U))
                {
                    /* Call standard close procedure with error check */
                    SPI_closeTransfer(hspi);

                    SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_TIMEOUT);
                    hspi->state = HAL_SPI_STATE_READY;
                    return kSTATUS_TIMEOUT;
                }
            }
        }
    }
    /* Transmit data in 8 Bit mode */
    else
    {
        while (hspi->txXferCount > 0UL)
        {
            /* Wait until TX FIFO not full flag  is set to send data */
            if (HTE_SPI_GET_FLAG(hspi, SPI_FLAG_TFNF))
            {
                *((__IO uint32_t *)&hspi->instance->DR0) = *((uint8_t *)hspi->pTxBuffPtr);

                hspi->pTxBuffPtr += sizeof(uint8_t);
                hspi->txXferCount--;
            }
            else
            {
                /* Timeout management */
                if ((((BOARD_getTick() - tickstart) >= timeOut) && (timeOut != SPI_MAX_DELAY)) || (timeOut == 0U))
                {
                    /* Call standard close procedure with error check */
                    SPI_closeTransfer(hspi);

                    SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_TIMEOUT);
                    hspi->state = HAL_SPI_STATE_READY;
                    return kSTATUS_TIMEOUT;
                }
            }
        }
    }

    /* Wait for Tx data to be sent */
    if (SPI_waitOnFlagUntilTimeout(hspi, SPI_FLAG_BUSY, kSPI_SET, tickstart, timeOut) != kSTATUS_SUCCESS)
    {
        SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_FLAG_ERR);
    }

    if (SPI_waitOnFlagUntilTimeout(hspi, SPI_FLAG_TFE, kSPI_RESET, tickstart, timeOut) != kSTATUS_SUCCESS)
    {
        SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_FLAG_ERR);
    }

    SPI_closeTransfer(hspi);

    hspi->state = HAL_SPI_STATE_READY;

    if (hspi->errorCode != HTE_SPI_ERROR_NONE)
    {
        return kSTATUS_FAIL;
    }

    return errorcode;
}

status_t SPI_receive(SPI_HandleTypeDef_t *hspi, uint8_t *pData, uint32_t size, uint32_t timeOut)
{
    status_t errorcode = kSTATUS_SUCCESS;
    uint32_t tickstart;

    /* Check Direction parameter */
    assert(IS_SPI_DIRECTION_RX_SUPPORT(hspi->init.direction));

    if ((hspi->init.mode == SPI_MODE_MASTER) && (hspi->init.direction == SPI_DIRECTION_TX_AND_RX))
    {
        hspi->state = HAL_SPI_STATE_BUSY_RX;
        /* Call transmit-receive function to send Dummy data on Tx line and generate clock on CLK line */
        return SPI_transmitReceive(hspi, pData, pData, size, timeOut);
    }

    if ((pData == NULL) || (size == 0UL))
    {
        errorcode = kSTATUS_FAIL;
        return errorcode;
    }

    if (hspi->state != HAL_SPI_STATE_READY)
    {
        errorcode = kSTATUS_INVALID_ARGUMENT;
        return errorcode;
    }

    /* Set the transaction information */
    hspi->state       = HAL_SPI_STATE_BUSY_RX;
    hspi->errorCode   = HTE_SPI_ERROR_NONE;
    hspi->pRxBuffPtr  = (uint8_t *)pData;
    hspi->rxXferSize  = size;
    hspi->rxXferCount = size;

    /*Init field not used in handle to zero */
    hspi->pTxBuffPtr  = NULL;
    hspi->txXferSize  = (uint16_t)0UL;
    hspi->txXferCount = (uint16_t)0UL;
    hspi->rxISR       = NULL;
    hspi->txISR       = NULL;

    tickstart = BOARD_getTick();

    /* Enable SPI peripheral */
    HTE_SPI_ENABLE(hspi);

    /* Receive data in 32 Bit mode */
    if (hspi->init.dataSize > SPI_DATASIZE_16BIT)
    {
        /* Transfer loop */
        while (hspi->rxXferCount > 0UL)
        {
            /* Check the RXFIFO no empty flag */
            if (HTE_SPI_GET_FLAG(hspi, SPI_FLAG_RFNE))
            {
                *((uint32_t *)hspi->pRxBuffPtr)  = *((__IO uint32_t *)&hspi->instance->DR0);
                hspi->pRxBuffPtr                += sizeof(uint32_t);
                hspi->rxXferCount--;
            }
            else
            {
                /* Timeout management */
                if ((((BOARD_getTick() - tickstart) >= timeOut) && (timeOut != SPI_MAX_DELAY)) || (timeOut == 0U))
                {
                    /* Call standard close procedure with error check */
                    SPI_closeTransfer(hspi);

                    SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_TIMEOUT);
                    hspi->state = HAL_SPI_STATE_READY;
                    return kSTATUS_TIMEOUT;
                }
            }
        }
    }
    /* Receive data in 16 Bit mode */
    else if (hspi->init.dataSize > SPI_DATASIZE_8BIT)
    {
        /* Transfer loop */
        while (hspi->rxXferCount > 0UL)
        {
            /* Check the RXFIFO no empty flag */
            if (HTE_SPI_GET_FLAG(hspi, SPI_FLAG_RFNE))
            {
                *((uint16_t *)hspi->pRxBuffPtr)  = *((__IO uint32_t *)&hspi->instance->DR0);
                hspi->pRxBuffPtr                += sizeof(uint16_t);
                hspi->rxXferCount--;
            }
            else
            {
                /* Timeout management */
                if ((((BOARD_getTick() - tickstart) >= timeOut) && (timeOut != SPI_MAX_DELAY)) || (timeOut == 0U))
                {
                    /* Call standard close procedure with error check */
                    SPI_closeTransfer(hspi);

                    SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_TIMEOUT);
                    hspi->state = HAL_SPI_STATE_READY;
                    return kSTATUS_TIMEOUT;
                }
            }
        }
    }
    /* Receive data in 8 Bit mode */
    else
    {
        /* Transfer loop */
        while (hspi->rxXferCount > 0UL)
        {
            /* Check the RXFIFO no empty flag */
            if (HTE_SPI_GET_FLAG(hspi, SPI_FLAG_RFNE))
            {
                *((uint8_t *)hspi->pRxBuffPtr)  = *((__IO uint32_t *)&hspi->instance->DR0);
                hspi->pRxBuffPtr               += sizeof(uint8_t);
                hspi->rxXferCount--;
            }
            else
            {
                /* Timeout management */
                if ((((BOARD_getTick() - tickstart) >= timeOut) && (timeOut != SPI_MAX_DELAY)) || (timeOut == 0U))
                {
                    /* Call standard close procedure with error check */
                    SPI_closeTransfer(hspi);

                    SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_TIMEOUT);
                    hspi->state = HAL_SPI_STATE_READY;
                    return kSTATUS_TIMEOUT;
                }
            }
        }
    }

    if (SPI_waitOnFlagUntilTimeout(hspi, SPI_FLAG_BUSY, kSPI_SET, tickstart, timeOut) != kSTATUS_SUCCESS)
    {
        SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_FLAG_ERR);
    }

    SPI_closeTransfer(hspi);

    /* Call standard close procedure with error check */
    hspi->state = HAL_SPI_STATE_READY;

    if (hspi->errorCode != HTE_SPI_ERROR_NONE)
    {
        return kSTATUS_FAIL;
    }
    return errorcode;
}

status_t SPI_transmitReceive(SPI_HandleTypeDef_t *hspi, uint8_t *pTxData, uint8_t *pRxData, uint32_t size,
                             uint32_t timeOut)
{
    HAL_SPI_StateTypeDef tmp_state;
    status_t             errorcode = kSTATUS_SUCCESS;
    uint32_t             dummyData;
    uint32_t             tmp_mode;
    uint32_t             pageCount, pageLens;
    uint32_t             tickstart;

    /* Check Direction parameter */
    assert(IS_SPI_DIRECTION_2LINES(hspi->init.direction));

    tmp_state = hspi->state;
    tmp_mode  = hspi->init.mode;

    SPI_UNUSED(dummyData);

    if (!((tmp_state == HAL_SPI_STATE_READY) ||
          ((tmp_mode == SPI_MODE_MASTER) && (hspi->init.direction == SPI_DIRECTION_TX_AND_RX) &&
           (tmp_state == HAL_SPI_STATE_BUSY_RX))))
    {
        errorcode = kSTATUS_INVALID_ARGUMENT;
        return errorcode;
    }


    if ((pTxData == NULL) || (size == 0UL))
    {
        errorcode = kSTATUS_FAIL;
        return errorcode;
    }

    /* Don't overwrite in case of HAL_SPI_STATE_BUSY_RX */
    if (hspi->state != HAL_SPI_STATE_BUSY_RX)
    {
        hspi->state = HAL_SPI_STATE_BUSY_TX_RX;
    }

    /* Set the transaction information */
    hspi->errorCode   = HTE_SPI_ERROR_NONE;
    hspi->pRxBuffPtr  = (uint8_t *)pRxData;
    hspi->rxXferCount = size;
    hspi->rxXferSize  = size;
    hspi->pTxBuffPtr  = (uint8_t *)pTxData;
    hspi->txXferCount = size;
    hspi->txXferSize  = size;

    /*Init field not used in handle to zero */
    hspi->rxISR = NULL;
    hspi->txISR = NULL;

    pageCount = size >> 8;
    pageLens  = SPI_MAX_RX_FIFO_LENGTH;

    tickstart = BOARD_getTick();

    HTE_SPI_ENABLE(hspi);

    /* Transmit and Receive data in 32 Bit mode */
    if (hspi->init.dataSize > SPI_DATASIZE_16BIT)
    {
        while (pageCount)
        {
            /* tx 256 loop */
            while (pageLens > 0UL)
            {
                /* Wait until TX FIFO not full flag  is set to send data */
                if (HTE_SPI_GET_FLAG(hspi, SPI_FLAG_TFNF))
                {
                    *((__IO uint32_t *)&hspi->instance->DR0)  = *((uint32_t *)hspi->pTxBuffPtr);
                    hspi->pTxBuffPtr                         += sizeof(uint32_t);
                    hspi->txXferCount--;
                    pageLens--;
                }
                else
                {
                    /* Timeout management */
                    if ((((BOARD_getTick() - tickstart) >= timeOut) && (timeOut != SPI_MAX_DELAY)) || (timeOut == 0U))
                    {
                        /* Call standard close procedure with error check */
                        SPI_closeTransfer(hspi);

                        SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_TIMEOUT);
                        hspi->state = HAL_SPI_STATE_READY;
                        return kSTATUS_TIMEOUT;
                    }
                }
            }

            /* rx 256 loop */
            while (pageLens < SPI_MAX_RX_FIFO_LENGTH)
            {
                /* Check the RXFIFO no empty flag */
                if (HTE_SPI_GET_FLAG(hspi, SPI_FLAG_RFNE))
                {
                    if (hspi->pRxBuffPtr != NULL)
                    {
                        *((uint32_t *)hspi->pRxBuffPtr)  = *((__IO uint32_t *)&hspi->instance->DR0);
                        hspi->pRxBuffPtr                += sizeof(uint32_t);
                    }
                    else
                    {
                        dummyData = *((__IO uint32_t *)&hspi->instance->DR0);
                    }

                    hspi->rxXferCount--;
                    pageLens++;
                }
                else
                {
                    /* Timeout management */
                    if ((((BOARD_getTick() - tickstart) >= timeOut) && (timeOut != SPI_MAX_DELAY)) || (timeOut == 0U))
                    {
                        /* Call standard close procedure with error check */
                        SPI_closeTransfer(hspi);

                        SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_TIMEOUT);
                        hspi->state = HAL_SPI_STATE_READY;
                        return kSTATUS_TIMEOUT;
                    }
                }
            }
            pageCount--;
        }

        /* tx remain byte loop */
        while (hspi->txXferCount > 0UL)
        {
            /* Wait until TX FIFO not full flag  is set to send data */
            if (HTE_SPI_GET_FLAG(hspi, SPI_FLAG_TFNF))
            {
                *((__IO uint32_t *)&hspi->instance->DR0)  = *((uint32_t *)hspi->pTxBuffPtr);
                hspi->pTxBuffPtr                         += sizeof(uint32_t);
                hspi->txXferCount--;
            }
            else
            {
                /* Timeout management */
                if ((((BOARD_getTick() - tickstart) >= timeOut) && (timeOut != SPI_MAX_DELAY)) || (timeOut == 0U))
                {
                    /* Call standard close procedure with error check */
                    SPI_closeTransfer(hspi);

                    SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_TIMEOUT);
                    hspi->state = HAL_SPI_STATE_READY;
                    return kSTATUS_TIMEOUT;
                }
            }
        }

        /* rx remain byte loop */
        while (hspi->rxXferCount > 0UL)
        {
            /* Check the RXFIFO no empty flag */
            if (HTE_SPI_GET_FLAG(hspi, SPI_FLAG_RFNE))
            {
                if (hspi->pRxBuffPtr != NULL)
                {
                    *((uint32_t *)hspi->pRxBuffPtr)  = *((__IO uint32_t *)&hspi->instance->DR0);
                    hspi->pRxBuffPtr                += sizeof(uint32_t);
                }
                else
                {
                    dummyData = *((__IO uint32_t *)&hspi->instance->DR0);
                }

                hspi->rxXferCount--;
            }
            else
            {
                /* Timeout management */
                if ((((BOARD_getTick() - tickstart) >= timeOut) && (timeOut != SPI_MAX_DELAY)) || (timeOut == 0U))
                {
                    /* Call standard close procedure with error check */
                    SPI_closeTransfer(hspi);

                    SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_TIMEOUT);
                    hspi->state = HAL_SPI_STATE_READY;
                    return kSTATUS_TIMEOUT;
                }
            }
        }
    }
    /* Transmit and Receive data in 16 Bit mode */
    else if (hspi->init.dataSize > SPI_DATASIZE_8BIT)
    {
        while (pageCount)
        {
            /* tx 256 loop */
            while (pageLens > 0UL)
            {
                /* Wait until TX FIFO not full flag  is set to send data */
                if (HTE_SPI_GET_FLAG(hspi, SPI_FLAG_TFNF))
                {
                    *((__IO uint32_t *)&hspi->instance->DR0)  = *((uint16_t *)hspi->pTxBuffPtr);
                    hspi->pTxBuffPtr                         += sizeof(uint16_t);
                    hspi->txXferCount--;
                    pageLens--;
                }
                else
                {
                    /* Timeout management */
                    if ((((BOARD_getTick() - tickstart) >= timeOut) && (timeOut != SPI_MAX_DELAY)) || (timeOut == 0U))
                    {
                        /* Call standard close procedure with error check */
                        SPI_closeTransfer(hspi);

                        SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_TIMEOUT);
                        hspi->state = HAL_SPI_STATE_READY;
                        return kSTATUS_TIMEOUT;
                    }
                }
            }

            /* rx 256 loop */
            while (pageLens < SPI_MAX_RX_FIFO_LENGTH)
            {
                /* Check the RXFIFO no empty flag */
                if (HTE_SPI_GET_FLAG(hspi, SPI_FLAG_RFNE))
                {
                    if (hspi->pRxBuffPtr != NULL)
                    {
                        *((uint16_t *)hspi->pRxBuffPtr)  = *((__IO uint32_t *)&hspi->instance->DR0);
                        hspi->pRxBuffPtr                += sizeof(uint16_t);
                    }
                    else
                    {
                        dummyData = *((__IO uint32_t *)&hspi->instance->DR0);
                    }

                    hspi->rxXferCount--;
                    pageLens++;
                }
                else
                {
                    /* Timeout management */
                    if ((((BOARD_getTick() - tickstart) >= timeOut) && (timeOut != SPI_MAX_DELAY)) || (timeOut == 0U))
                    {
                        /* Call standard close procedure with error check */
                        SPI_closeTransfer(hspi);

                        SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_TIMEOUT);
                        hspi->state = HAL_SPI_STATE_READY;
                        return kSTATUS_TIMEOUT;
                    }
                }
            }
            pageCount--;
        }

        /* tx remain byte loop */
        while (hspi->txXferCount > 0UL)
        {
            /* Wait until TX FIFO not full flag  is set to send data */
            if (HTE_SPI_GET_FLAG(hspi, SPI_FLAG_TFNF))
            {
                *((__IO uint32_t *)&hspi->instance->DR0)  = *((uint16_t *)hspi->pTxBuffPtr);
                hspi->pTxBuffPtr                         += sizeof(uint16_t);
                hspi->txXferCount--;
            }
            else
            {
                /* Timeout management */
                if ((((BOARD_getTick() - tickstart) >= timeOut) && (timeOut != SPI_MAX_DELAY)) || (timeOut == 0U))
                {
                    /* Call standard close procedure with error check */
                    SPI_closeTransfer(hspi);

                    SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_TIMEOUT);
                    hspi->state = HAL_SPI_STATE_READY;
                    return kSTATUS_TIMEOUT;
                }
            }
        }

        /* rx remain byte loop */
        while (hspi->rxXferCount > 0UL)
        {
            /* Check the RXFIFO no empty flag */
            if (HTE_SPI_GET_FLAG(hspi, SPI_FLAG_RFNE))
            {
                if (hspi->pRxBuffPtr != NULL)
                {
                    *((uint16_t *)hspi->pRxBuffPtr)  = *((__IO uint32_t *)&hspi->instance->DR0);
                    hspi->pRxBuffPtr                += sizeof(uint16_t);
                }
                else
                {
                    dummyData = *((__IO uint32_t *)&hspi->instance->DR0);
                }

                hspi->rxXferCount--;
            }
            else
            {
                /* Timeout management */
                if ((((BOARD_getTick() - tickstart) >= timeOut) && (timeOut != SPI_MAX_DELAY)) || (timeOut == 0U))
                {
                    /* Call standard close procedure with error check */
                    SPI_closeTransfer(hspi);

                    SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_TIMEOUT);
                    hspi->state = HAL_SPI_STATE_READY;
                    return kSTATUS_TIMEOUT;
                }
            }
        }
    }
    /* Transmit and Receive data in 8 Bit mode */
    else
    {
        while (pageCount)
        {
            /* tx 256 loop */
            while (pageLens > 0UL)
            {
                /* Wait until TX FIFO not full flag  is set to send data */
                if (HTE_SPI_GET_FLAG(hspi, SPI_FLAG_TFNF))
                {
                    *((__IO uint32_t *)&hspi->instance->DR0)  = *((uint8_t *)hspi->pTxBuffPtr);
                    hspi->pTxBuffPtr                         += sizeof(uint8_t);
                    hspi->txXferCount--;
                    pageLens--;
                }
                else
                {
                    /* Timeout management */
                    if ((((BOARD_getTick() - tickstart) >= timeOut) && (timeOut != SPI_MAX_DELAY)) || (timeOut == 0U))
                    {
                        /* Call standard close procedure with error check */
                        SPI_closeTransfer(hspi);

                        SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_TIMEOUT);
                        hspi->state = HAL_SPI_STATE_READY;
                        return kSTATUS_TIMEOUT;
                    }
                }
            }

            /* rx 256 loop */
            while (pageLens < SPI_MAX_RX_FIFO_LENGTH)
            {
                /* Check the RXFIFO no empty flag */
                if (HTE_SPI_GET_FLAG(hspi, SPI_FLAG_RFNE))
                {
                    if (hspi->pRxBuffPtr != NULL)
                    {
                        *((uint8_t *)hspi->pRxBuffPtr)  = *((__IO uint32_t *)&hspi->instance->DR0);
                        hspi->pRxBuffPtr               += sizeof(uint8_t);
                    }
                    else
                    {
                        dummyData = *((__IO uint32_t *)&hspi->instance->DR0);
                    }

                    hspi->rxXferCount--;
                    pageLens++;
                }
                else
                {
                    /* Timeout management */
                    if ((((BOARD_getTick() - tickstart) >= timeOut) && (timeOut != SPI_MAX_DELAY)) || (timeOut == 0U))
                    {
                        /* Call standard close procedure with error check */
                        SPI_closeTransfer(hspi);

                        SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_TIMEOUT);
                        hspi->state = HAL_SPI_STATE_READY;
                        return kSTATUS_TIMEOUT;
                    }
                }
            }

            pageCount--;
        }

        /* tx remain byte loop */
        while (hspi->txXferCount > 0UL)
        {
            /* Wait until TX FIFO not full flag  is set to send data */
            if (HTE_SPI_GET_FLAG(hspi, SPI_FLAG_TFNF))
            {
                *((__IO uint32_t *)&hspi->instance->DR0)  = *((uint8_t *)hspi->pTxBuffPtr);
                hspi->pTxBuffPtr                         += sizeof(uint8_t);
                hspi->txXferCount--;
            }
            else
            {
                /* Timeout management */
                if ((((BOARD_getTick() - tickstart) >= timeOut) && (timeOut != SPI_MAX_DELAY)) || (timeOut == 0U))
                {
                    /* Call standard close procedure with error check */
                    SPI_closeTransfer(hspi);

                    SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_TIMEOUT);
                    hspi->state = HAL_SPI_STATE_READY;
                    return kSTATUS_TIMEOUT;
                }
            }
        }

        /* rx remain byte loop */
        while (hspi->rxXferCount > 0UL)
        {
            /* Check the RXFIFO no empty flag */
            if (HTE_SPI_GET_FLAG(hspi, SPI_FLAG_RFNE))
            {
                if (hspi->pRxBuffPtr != NULL)
                {
                    *((uint8_t *)hspi->pRxBuffPtr)  = *((__IO uint32_t *)&hspi->instance->DR0);
                    hspi->pRxBuffPtr               += sizeof(uint8_t);
                }
                else
                {
                    dummyData = *((__IO uint32_t *)&hspi->instance->DR0);
                }

                hspi->rxXferCount--;
            }
            else
            {
                /* Timeout management */
                if ((((BOARD_getTick() - tickstart) >= timeOut) && (timeOut != SPI_MAX_DELAY)) || (timeOut == 0U))
                {
                    /* Call standard close procedure with error check */
                    SPI_closeTransfer(hspi);

                    SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_TIMEOUT);
                    hspi->state = HAL_SPI_STATE_READY;
                    return kSTATUS_TIMEOUT;
                }
            }
        }
    }

    if (SPI_waitOnFlagUntilTimeout(hspi, SPI_FLAG_BUSY, kSPI_SET, tickstart, timeOut) != kSTATUS_SUCCESS)
    {
        SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_FLAG_ERR);
    }

    if (SPI_waitOnFlagUntilTimeout(hspi, SPI_FLAG_TFE, kSPI_RESET, tickstart, timeOut) != kSTATUS_SUCCESS)
    {
        SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_FLAG_ERR);
    }

    SPI_closeTransfer(hspi);

    /* Call standard close procedure with error check */
    hspi->state = HAL_SPI_STATE_READY;

    if (hspi->errorCode != HTE_SPI_ERROR_NONE)
    {
        return kSTATUS_FAIL;
    }
    return errorcode;
}

status_t SPI_transmitIT(SPI_HandleTypeDef_t *hspi, uint8_t *pData, uint32_t size)
{
    status_t errorcode = kSTATUS_SUCCESS;

    /* Check Direction parameter */
    assert(IS_SPI_DIRECTION_TX_SUPPORT(hspi->init.direction));

    if ((pData == NULL) || (size == 0UL))
    {
        errorcode = kSTATUS_FAIL;
        return errorcode;
    }

    if (hspi->state != HAL_SPI_STATE_READY)
    {
        errorcode = kSTATUS_INVALID_ARGUMENT;
        return errorcode;
    }

    /* Set the transaction information */
    hspi->state       = HAL_SPI_STATE_BUSY_TX;
    hspi->errorCode   = HTE_SPI_ERROR_NONE;
    hspi->pTxBuffPtr  = (uint8_t *)pData;
    hspi->txXferSize  = size;
    hspi->txXferCount = size;

    /* Init field not used in handle to zero */
    hspi->pRxBuffPtr  = NULL;
    hspi->rxXferSize  = (uint16_t)0UL;
    hspi->rxXferCount = (uint16_t)0UL;
    hspi->rxISR       = NULL;

    /* Set the function for IT treatment */
    if (hspi->init.dataSize > SPI_DATASIZE_16BIT)
    {
        hspi->txISR = SPI_txISR32Bit;
    }
    else if (hspi->init.dataSize > SPI_DATASIZE_8BIT)
    {
        hspi->txISR = SPI_txISR16Bit;
    }
    else
    {
        hspi->txISR = SPI_txISR8Bit;
    }

    /* Enable SPI peripheral */
    HTE_SPI_ENABLE(hspi);

    /* Enable TXE interrupts */
    HTE_SPI_ENABLE_IT(hspi, (SPI_IT_TXE));

    return errorcode;
}

status_t SPI_receiveIT(SPI_HandleTypeDef_t *hspi, uint8_t *pData, uint32_t size)
{
    status_t errorcode = kSTATUS_SUCCESS;

    /* Check Direction parameter */
    assert(IS_SPI_DIRECTION_RX_SUPPORT(hspi->init.direction));

    if ((hspi->init.mode == SPI_MODE_MASTER) && (hspi->init.direction == SPI_DIRECTION_TX_AND_RX))
    {
        hspi->state = HAL_SPI_STATE_BUSY_RX;
        /* Call transmit-receive function to send Dummy data on Tx line and generate clock on CLK line */
        return SPI_transmitReceiveIT(hspi, pData, pData, size);
    }

    if (hspi->state != HAL_SPI_STATE_READY)
    {
        errorcode = kSTATUS_INVALID_ARGUMENT;
        return errorcode;
    }

    if ((pData == NULL) || (size == 0UL))
    {
        errorcode = kSTATUS_FAIL;
        return errorcode;
    }

    /* Set the transaction information */
    hspi->state       = HAL_SPI_STATE_BUSY_RX;
    hspi->errorCode   = HTE_SPI_ERROR_NONE;
    hspi->pRxBuffPtr  = (uint8_t *)pData;
    hspi->rxXferSize  = size;
    hspi->rxXferCount = size;

    /* Init field not used in handle to zero */
    hspi->pTxBuffPtr  = NULL;
    hspi->txXferSize  = (uint16_t)0UL;
    hspi->txXferCount = (uint16_t)0UL;
    hspi->txISR       = NULL;

    /* Set the function for IT treatment */
    if (hspi->init.dataSize > SPI_DATASIZE_16BIT)
    {
        hspi->rxISR = SPI_rxISR32Bit;
    }
    else if (hspi->init.dataSize > SPI_DATASIZE_8BIT)
    {
        hspi->rxISR = SPI_rxISR16Bit;
    }
    else
    {
        hspi->rxISR = SPI_rxISR8Bit;
    }

    HTE_SPI_DISABLE(hspi);

    /* for SPI_IT_RXF interrupt */
    hspi->init.rxFifoThreshold  = 0;
    hspi->instance->RXFTLR      &= ~(SPI_RXFTLR_RFT_Msk);
    hspi->instance->RXFTLR      |= SPI_RXFTLR_RFT_Set(hspi->init.rxFifoThreshold);

    /* Enable SPI peripheral */
    HTE_SPI_ENABLE(hspi);

    /* Enable SPI_IT_RXF interrupts */
    HTE_SPI_ENABLE_IT(hspi, (SPI_IT_RXF));

    return errorcode;
}

status_t SPI_transmitReceiveIT(SPI_HandleTypeDef_t *hspi, uint8_t *pTxData, uint8_t *pRxData, uint32_t size)
{
    HAL_SPI_StateTypeDef tmp_state;
    status_t             errorcode = kSTATUS_SUCCESS;
    uint32_t             tmp_mode;

    /* Check Direction parameter */
    assert(IS_SPI_DIRECTION_2LINES(hspi->init.direction));

    /* Init temporary variables */
    tmp_state = hspi->state;
    tmp_mode  = hspi->init.mode;

    if (!((tmp_state == HAL_SPI_STATE_READY) ||
          ((tmp_mode == SPI_MODE_MASTER) && (hspi->init.direction == SPI_DIRECTION_TX_AND_RX) &&
           (tmp_state == HAL_SPI_STATE_BUSY_RX))))
    {
        errorcode = kSTATUS_INVALID_ARGUMENT;
        return errorcode;
    }

    if ((pTxData == NULL) || (pRxData == NULL) || (size == 0UL))
    {
        errorcode = kSTATUS_FAIL;
        return errorcode;
    }

    /* Don't overwrite in case of HAL_SPI_STATE_BUSY_RX */
    if (hspi->state != HAL_SPI_STATE_BUSY_RX)
    {
        hspi->state = HAL_SPI_STATE_BUSY_TX_RX;
    }

    /* Set the transaction information */
    hspi->errorCode   = HTE_SPI_ERROR_NONE;
    hspi->pTxBuffPtr  = (uint8_t *)pTxData;
    hspi->txXferSize  = size;
    hspi->txXferCount = size;
    hspi->pRxBuffPtr  = (uint8_t *)pRxData;
    hspi->rxXferSize  = size;
    hspi->rxXferCount = size;

    /* Set the function for IT treatment */
    if (hspi->init.dataSize > SPI_DATASIZE_16BIT)
    {
        hspi->txISR = SPI_txISR32Bit;
        hspi->rxISR = SPI_rxISR32Bit;
    }
    else if (hspi->init.dataSize > SPI_DATASIZE_8BIT)
    {
        hspi->rxISR = SPI_rxISR16Bit;
        hspi->txISR = SPI_txISR16Bit;
    }
    else
    {
        hspi->rxISR = SPI_rxISR8Bit;
        hspi->txISR = SPI_txISR8Bit;
    }

    HTE_SPI_DISABLE(hspi);

    /* for SPI_IT_RXF interrupt */
    hspi->init.rxFifoThreshold  = 0;
    hspi->instance->RXFTLR      &= ~(SPI_RXFTLR_RFT_Msk);
    hspi->instance->RXFTLR      |= SPI_RXFTLR_RFT_Set(hspi->init.rxFifoThreshold);

    /* Note : The SPI rxFifoThreshold must be 0 for all rx lens */

    /* Enable SPI peripheral */
    HTE_SPI_ENABLE(hspi);

    /* Enable (SPI_IT_TXE | SPI_IT_RXF) interrupts */
    HTE_SPI_ENABLE_IT(hspi, (SPI_IT_TXE | SPI_IT_RXF));

    return errorcode;
}

status_t SPI_transmitDMAInit(SPI_HandleTypeDef_t *hspi, DMA_Index_t DMAIndex, uint8_t *pData, uint32_t size)
{
    uint32_t       spiIndex;
    int16_t        step;
    DMA_DataSize_t dataSize;

    hspi->pTxBuffPtr = (uint8_t *)pData;
    hspi->txXferSize = size;

    /* Set DMA Datasize */
    if (hspi->init.dataSize > SPI_DATASIZE_16BIT)
    {
        dataSize = kDMA_DATASIZE_32BIT;
        step     = 4;
    }
    else if (hspi->init.dataSize > SPI_DATASIZE_8BIT)
    {
        dataSize = kDMA_DATASIZE_16BIT;
        step     = 2;
    }
    else
    {
        dataSize = kDMA_DATASIZE_8BIT;
        step     = 1;
    }

    hspi->spiDMAStep = step;

    switch ((uint32_t)(hspi->instance))
    {
        case SPIA_BASE:
            spiIndex = 0;
            break;

        case SPIB_BASE:
            spiIndex = 1;
            break;

        case SPIC_BASE:
            spiIndex = 2;
            break;

        default:
            return kSTATUS_FAIL;
    }

    hspi->spiDMATxDoneFlag = &s_spiDMATxDoneFlag[DMAIndex];
    hspi->spiDMATxIndex    = DMAIndex;

    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_DMA);

    DMA_initialize();

    /* Initialize the DMA channel addresses */
    DMA_configAddresses(DMAIndex, (const void *)(&hspi->instance->DR0), (const void *)hspi->pTxBuffPtr);

    /* Set up to use 32 / 16 / 8-bit data size
     * BURST size = 1 | Source step size = step | Dest step size += 0 */
    DMA_configBurst(DMAIndex, 1, hspi->spiDMAStep, 0);

    /*
     * Transfer size = txXferSize | Source step size = step | Dest step size += 0 */
    DMA_configTransfer(DMAIndex, hspi->txXferSize, hspi->spiDMAStep, 0);

    DMA_setDataSize(DMAIndex, dataSize);
    DMA_configTrigger(DMAIndex, (DMA_Trigger_t)(kDMA_TRIGGER_SPIATX + spiIndex * 2));
    DMA_configMode(DMAIndex, kDMA_MODE_PERIPH_TRIG);
    DMA_disableOverRunInterrupt(DMAIndex);
    DMA_disableBegInterrupt(DMAIndex);
    DMA_enableEndInterrupt(DMAIndex);
    DMA_clearStatusFlag(DMAIndex);
    DMA_enableTrigger(DMAIndex);

    /* Disable the selected SPI peripheral */
    HTE_SPI_DISABLE(hspi);

    /* set TXDMAlevel*/
    hspi->instance->DMATDLR = SPI_DMATDLR_DMATDL_Set(hspi->init.txDMALevel);

    /* set TXDMAEN bit*/
    hspi->instance->DMACR &= ~SPI_DMACR_TDMAE_Msk;
    hspi->instance->DMACR |= SPI_DMACR_TDMAE_Set(1U);

    return kSTATUS_SUCCESS;
}

status_t SPI_transmitDMA(SPI_HandleTypeDef_t *hspi, uint8_t *pData, uint32_t size, uint32_t timeOut)
{
    status_t errorcode = kSTATUS_SUCCESS;
    uint32_t tickstart;
    /* Check Direction parameter */
    assert(IS_SPI_DIRECTION_TX_SUPPORT(hspi->init.direction));

    if ((pData == NULL) || (size == 0UL))
    {
        errorcode = kSTATUS_FAIL;
        return errorcode;
    }

    if (hspi->state != HAL_SPI_STATE_READY)
    {
        errorcode = kSTATUS_INVALID_ARGUMENT;
        return errorcode;
    }

    /* Set the transaction information */
    hspi->state       = HAL_SPI_STATE_BUSY_TX;
    hspi->errorCode   = HTE_SPI_ERROR_NONE;
    hspi->pTxBuffPtr  = (uint8_t *)pData;
    hspi->txXferSize  = size;
    hspi->txXferCount = size;

    /* Init field not used in handle to zero */
    hspi->pRxBuffPtr  = NULL;
    hspi->txISR       = NULL;
    hspi->rxISR       = NULL;
    hspi->rxXferSize  = (uint16_t)0UL;
    hspi->rxXferCount = (uint16_t)0UL;

    /*clear tx done flag*/
    *(hspi->spiDMATxDoneFlag) = 0;

    /* DMA cfg */
    DMA_registerCallback((DMA_IntSrc_t)hspi->spiDMATxIndex, (DMA_Callback_t)SPI_DMA_IRQTxCpltCallBcak, 4);
    DMA_configAddresses((DMA_Index_t)hspi->spiDMATxIndex, (const void *)(&hspi->instance->DR0),
                        (const void *)hspi->pTxBuffPtr);
    DMA_configTransfer((DMA_Index_t)hspi->spiDMATxIndex, hspi->txXferSize, hspi->spiDMAStep, 0);
    DMA_startChannel((DMA_Index_t)hspi->spiDMATxIndex);

    tickstart = BOARD_getTick();

    /* Enable SPI peripheral */
    HTE_SPI_ENABLE(hspi);

    /*wait tx done, the flag must be set in dma complete IRQ*/
    while (!(*((volatile unsigned char *)(hspi->spiDMATxDoneFlag))))
    {
        /* Timeout management */
        if ((((BOARD_getTick() - tickstart) >= timeOut) && (timeOut != SPI_MAX_DELAY)) || (timeOut == 0U))
        {
            /* Call standard close procedure with error check */
            SPI_closeTransfer(hspi);

            SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_TIMEOUT);
            hspi->state = HAL_SPI_STATE_READY;
            return kSTATUS_TIMEOUT;
        }
    };

    hspi->txXferCount -= hspi->txXferSize;

    /* unregister DMA Callback */
    DMA_unregisterCallback((DMA_IntSrc_t)hspi->spiDMATxIndex);

    if (SPI_waitOnFlagUntilTimeout(hspi, SPI_FLAG_BUSY, kSPI_SET, tickstart, timeOut) != kSTATUS_SUCCESS)
    {
        SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_FLAG_ERR);
    }

    if (SPI_waitOnFlagUntilTimeout(hspi, SPI_FLAG_TFE, kSPI_RESET, tickstart, timeOut) != kSTATUS_SUCCESS)
    {
        SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_FLAG_ERR);
    }

    SPI_closeTransfer(hspi);

    hspi->state = HAL_SPI_STATE_READY;

    return errorcode;
}

status_t SPI_receiveDMAInit(SPI_HandleTypeDef_t *hspi, DMA_Index_t DMAIndex, uint8_t *pData, uint32_t size)
{
    uint32_t       spiIndex;
    int16_t        step;
    DMA_DataSize_t dataSize;

    hspi->pRxBuffPtr = (uint8_t *)pData;
    hspi->rxXferSize = size;

    if (hspi->init.dataSize > SPI_DATASIZE_16BIT)
    {
        dataSize = kDMA_DATASIZE_32BIT;
        step     = 4;
    }
    else if (hspi->init.dataSize > SPI_DATASIZE_8BIT)
    {
        dataSize = kDMA_DATASIZE_16BIT;
        step     = 2;
    }
    else
    {
        dataSize = kDMA_DATASIZE_8BIT;
        step     = 1;
    }

    hspi->spiDMAStep = step;

    switch ((uint32_t)(hspi->instance))
    {
        case SPIA_BASE:
            spiIndex = 0;
            break;

        case SPIB_BASE:
            spiIndex = 1;
            break;

        case SPIC_BASE:
            spiIndex = 2;
            break;

        default:
            return kSTATUS_FAIL;
    }

    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_DMA);

    hspi->spiDMARxDoneFlag = &s_spiDMARxDoneFlag[DMAIndex];
    hspi->spiDMARxIndex    = DMAIndex;

    DMA_initialize();

    /* Initialize the DMA channel addresses */
    DMA_configAddresses(DMAIndex, (const void *)hspi->pRxBuffPtr, (const void *)(&hspi->instance->DR0));

    /* BURST size = 1 | Source step size = 0 | Dest step size += spiDMAStep */
    DMA_configBurst(DMAIndex, 1, 0, hspi->spiDMAStep);

    /* Transfer size = 4 | Source step size = 0 | Dest step size += 4 */
    DMA_configTransfer(DMAIndex, hspi->rxXferSize, 0, hspi->spiDMAStep);

    /* Enbale DMA */
    DMA_setDataSize(DMAIndex, dataSize);
    DMA_clearStatusFlag(DMAIndex);
    DMA_configTrigger(DMAIndex, (DMA_Trigger_t)(kDMA_TRIGGER_SPIARX + spiIndex * 2));
    DMA_configMode(DMAIndex, kDMA_MODE_PERIPH_TRIG);
    DMA_disableOverRunInterrupt(DMAIndex);
    DMA_disableBegInterrupt(DMAIndex);
    DMA_enableEndInterrupt(DMAIndex);
    DMA_clearStatusFlag(DMAIndex);
    DMA_enableTrigger(DMAIndex);

    /* Disable the selected SPI peripheral */
    HTE_SPI_DISABLE(hspi);

    /* set RXDMAlevel*/
    hspi->instance->DMARDLR = SPI_DMARDLR_DMARDL_Set(hspi->init.rxDMALevel);

    /* set RXDMAEN bit*/
    hspi->instance->DMACR &= ~SPI_DMACR_RDMAE_Msk;
    hspi->instance->DMACR |= SPI_DMACR_RDMAE_Set(1U);

    return kSTATUS_SUCCESS;
}

status_t SPI_receiveDMA(SPI_HandleTypeDef_t *hspi, uint8_t *pData, uint32_t size, uint32_t timeOut)
{
    status_t errorcode = kSTATUS_SUCCESS;
    uint32_t tickstart;

    /* Check Direction parameter */
    assert(IS_SPI_DIRECTION_RX_SUPPORT(hspi->init.direction));

    if ((hspi->init.mode == SPI_MODE_MASTER) && (hspi->init.direction == SPI_DIRECTION_TX_AND_RX))
    {
        hspi->state = HAL_SPI_STATE_BUSY_RX;
        /* Call transmit-receive function to send Dummy data on Tx line and generate clock on CLK line */
        return SPI_transmitReceiveDMA(hspi, pData, pData, size, timeOut);
    }

    if ((pData == NULL) || (size == 0UL))
    {
        errorcode = kSTATUS_FAIL;
        return errorcode;
    }

    /* Set the transaction information */
    hspi->errorCode   = HTE_SPI_ERROR_NONE;
    hspi->pRxBuffPtr  = (uint8_t *)pData;
    hspi->rxXferSize  = size;
    hspi->rxXferCount = size;

    /*Init field not used in handle to zero */
    hspi->rxISR       = NULL;
    hspi->txISR       = NULL;
    hspi->txXferSize  = (uint16_t)0UL;
    hspi->txXferCount = (uint16_t)0UL;

    /*clear rx done flag*/
    *(hspi->spiDMARxDoneFlag) = 0;

    DMA_registerCallback((DMA_IntSrc_t)hspi->spiDMARxIndex, (DMA_Callback_t)SPI_DMA_IRQRxCpltCallBcak, 4);
    DMA_configAddresses(hspi->spiDMARxIndex, (const void *)hspi->pRxBuffPtr, (const void *)(&hspi->instance->DR0));
    DMA_configTransfer(hspi->spiDMARxIndex, hspi->rxXferSize, 0, hspi->spiDMAStep);
    DMA_startChannel((DMA_Index_t)hspi->spiDMARxIndex);

    tickstart = BOARD_getTick();

    /* Enable SPI peripheral */
    HTE_SPI_ENABLE(hspi);

    /*wait rx done  the flag must be set in dma complete IRQ*/
    while (!(*((volatile unsigned char *)(hspi->spiDMARxDoneFlag))))
    {
        /* Timeout management */
        if ((((BOARD_getTick() - tickstart) >= timeOut) && (timeOut != SPI_MAX_DELAY)) || (timeOut == 0U))
        {
            /* Call standard close procedure with error check */
            SPI_closeTransfer(hspi);

            SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_TIMEOUT);
            hspi->state = HAL_SPI_STATE_READY;
            return kSTATUS_TIMEOUT;
        }
    };

    hspi->rxXferCount -= hspi->rxXferSize;
    DMA_unregisterCallback((DMA_IntSrc_t)hspi->spiDMARxIndex);

    if (SPI_waitOnFlagUntilTimeout(hspi, SPI_FLAG_BUSY, kSPI_SET, tickstart, timeOut) != kSTATUS_SUCCESS)
    {
        SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_FLAG_ERR);
    }

    SPI_closeTransfer(hspi);

    hspi->state = HAL_SPI_STATE_READY;

    return errorcode;
}

status_t SPI_transmitReceiveDMAInit(SPI_HandleTypeDef_t *hspi, DMA_Index_t txDMAIndex, uint8_t *pTxData,
                                    DMA_Index_t rxDMAIndex, uint8_t *pRxData, uint32_t size)
{
    uint32_t       spiIndex;
    int16_t        step;
    DMA_DataSize_t dataSize;

    hspi->pTxBuffPtr  = (uint8_t *)pTxData;
    hspi->txXferSize  = size;
    hspi->txXferCount = size;
    hspi->pRxBuffPtr  = (uint8_t *)pRxData;
    hspi->rxXferSize  = size;
    hspi->rxXferCount = size;

    if (hspi->init.dataSize > SPI_DATASIZE_16BIT)
    {
        dataSize = kDMA_DATASIZE_32BIT;
        step     = 4;
    }
    else if (hspi->init.dataSize > SPI_DATASIZE_8BIT)
    {
        dataSize = kDMA_DATASIZE_16BIT;
        step     = 2;
    }
    else
    {
        dataSize = kDMA_DATASIZE_8BIT;
        step     = 1;
    }

    hspi->spiDMAStep = step;

    spiIndex = ((uint32_t)(hspi->instance) - SPIA_BASE) / 0x1000;

    switch ((uint32_t)(hspi->instance))
    {
        case SPIA_BASE:
            spiIndex = 0;
            break;

        case SPIB_BASE:
            spiIndex = 1;
            break;

        case SPIC_BASE:
            spiIndex = 2;
            break;

        default:
            return kSTATUS_FAIL;
    }

    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_DMA);

    hspi->spiDMATxDoneFlag = &s_spiDMATxDoneFlag[txDMAIndex];
    hspi->spiDMARxDoneFlag = &s_spiDMARxDoneFlag[rxDMAIndex];
    hspi->spiDMATxIndex    = txDMAIndex;
    hspi->spiDMARxIndex    = rxDMAIndex;

    /* DMA cfg */
    DMA_initialize();

    /* Initialize the DMA channel addresses */
    DMA_configAddresses(txDMAIndex, (const void *)(&hspi->instance->DR0), (const void *)(hspi->pTxBuffPtr));

    // BURST size = 1 | Source step size = step | Dest step size += 0 */
    //
    DMA_configBurst(txDMAIndex, 1, hspi->spiDMAStep, 0); // for uint32_t buffer


    //
    // Transfer size = MAX_SAMPLES | Source step size = step | Dest step size += 0 */
    //
    DMA_configTransfer(txDMAIndex, hspi->txXferSize, hspi->spiDMAStep, 0);

    //
    // Configure mode for DMA channels index
    //

    // DMA channel 1
    DMA_setDataSize(txDMAIndex, dataSize);

    DMA_configTrigger(txDMAIndex, (DMA_Trigger_t)(kDMA_TRIGGER_SPIATX + spiIndex * 2));

    DMA_configMode(txDMAIndex, kDMA_MODE_PERIPH_TRIG);
    DMA_disableOverRunInterrupt(txDMAIndex);
    DMA_disableBegInterrupt(txDMAIndex);
    DMA_enableEndInterrupt(txDMAIndex);
    DMA_clearStatusFlag(txDMAIndex);
    DMA_enableTrigger(txDMAIndex);

    /* Initialize the DMA channel addresses */
    DMA_configAddresses(rxDMAIndex, (const void *)(hspi->pRxBuffPtr), (const void *)(&hspi->instance->DR0));

    /* BURST size = 1 | Source step size = 0 | Dest step size += spiDMAStep */
    DMA_configBurst(rxDMAIndex, 1, 0, hspi->spiDMAStep);

    /* Transfer size = 4 | Source step size = 0 | Dest step size += 4 */
    DMA_configTransfer(rxDMAIndex, hspi->rxXferSize, 0, hspi->spiDMAStep);

    DMA_setDataSize(rxDMAIndex, dataSize);
    DMA_clearStatusFlag(rxDMAIndex);
    DMA_configTrigger(rxDMAIndex, (DMA_Trigger_t)(kDMA_TRIGGER_SPIARX + spiIndex * 2));
    DMA_configMode(rxDMAIndex, kDMA_MODE_PERIPH_TRIG);
    DMA_disableOverRunInterrupt(rxDMAIndex);
    DMA_disableBegInterrupt(rxDMAIndex);
    DMA_enableEndInterrupt(rxDMAIndex);
    DMA_clearStatusFlag(rxDMAIndex);
    DMA_enableTrigger(rxDMAIndex);

    HTE_SPI_DISABLE(hspi);

    /* set TXDMAlevel RXDMAlevel*/
    hspi->instance->DMATDLR = SPI_DMATDLR_DMATDL_Set(hspi->init.txDMALevel);
    hspi->instance->DMARDLR = SPI_DMARDLR_DMARDL_Set(hspi->init.rxDMALevel);

    /* set TXDMAEN bit*/
    hspi->instance->DMACR &= ~(SPI_DMACR_TDMAE_Msk | SPI_DMACR_RDMAE_Msk);

    hspi->instance->DMACR |= SPI_DMACR_TDMAE_Set(1U) | SPI_DMACR_RDMAE_Set(1U);

    return kSTATUS_SUCCESS;
}

status_t SPI_transmitReceiveDMA(SPI_HandleTypeDef_t *hspi, uint8_t *pTxData, uint8_t *pRxData, uint32_t size,
                                uint32_t timeOut)
{
    HAL_SPI_StateTypeDef tmp_state;
    status_t             errorcode = kSTATUS_SUCCESS;

    uint32_t tmp_mode;
    uint32_t tickstart;

    /* Check Direction parameter */
    assert(IS_SPI_DIRECTION_2LINES(hspi->init.direction));

    /* Init temporary variables */
    tmp_state = hspi->state;
    tmp_mode  = hspi->init.mode;

    if (!((tmp_state == HAL_SPI_STATE_READY) ||
          ((tmp_mode == SPI_MODE_MASTER) && (hspi->init.direction == SPI_DIRECTION_TX_AND_RX) &&
           (tmp_state == HAL_SPI_STATE_BUSY_RX))))
    {
        errorcode = kSTATUS_INVALID_ARGUMENT;
        return errorcode;
    }

    if ((pTxData == NULL) || (pRxData == NULL) || (size == 0UL))
    {
        errorcode = kSTATUS_FAIL;
        return errorcode;
    }

    /* Don't overwrite in case of HAL_SPI_STATE_BUSY_RX */
    if (hspi->state != HAL_SPI_STATE_BUSY_RX)
    {
        hspi->state = HAL_SPI_STATE_BUSY_TX_RX;
    }

    /* Set the transaction information */
    hspi->errorCode   = HTE_SPI_ERROR_NONE;
    hspi->pTxBuffPtr  = (uint8_t *)pTxData;
    hspi->txXferSize  = size;
    hspi->txXferCount = size;
    hspi->pRxBuffPtr  = (uint8_t *)pRxData;
    hspi->rxXferSize  = size;
    hspi->rxXferCount = size;

    /* Init field not used in handle to zero */
    hspi->rxISR = NULL;
    hspi->txISR = NULL;

    /* clear tx & rx done flag */
    *(hspi->spiDMATxDoneFlag) = 0;
    *(hspi->spiDMARxDoneFlag) = 0;

    /* DMA cfg */
    DMA_registerCallback((DMA_IntSrc_t)hspi->spiDMATxIndex, (DMA_Callback_t)SPI_DMA_IRQTxCpltCallBcak, 4);
    DMA_registerCallback((DMA_IntSrc_t)hspi->spiDMARxIndex, (DMA_Callback_t)SPI_DMA_IRQRxCpltCallBcak, 4);

    DMA_configAddresses(hspi->spiDMATxIndex, (const void *)(&hspi->instance->DR0), (const void *)(hspi->pTxBuffPtr));
    DMA_configTransfer(hspi->spiDMATxIndex, hspi->txXferSize, hspi->spiDMAStep, 0);

    DMA_configAddresses(hspi->spiDMARxIndex, (const void *)(hspi->pRxBuffPtr), (const void *)(&hspi->instance->DR0));
    DMA_configTransfer(hspi->spiDMARxIndex, hspi->rxXferSize, 0, hspi->spiDMAStep);

    DMA_startChannel((DMA_Index_t)hspi->spiDMATxIndex);
    DMA_startChannel((DMA_Index_t)hspi->spiDMARxIndex);

    tickstart = BOARD_getTick();

    /* Enable SPI peripheral */
    HTE_SPI_ENABLE(hspi);

    /*wait tx && rx done, the flag must be set in dma complete IRQ*/
    while ((!(*((volatile unsigned char *)(hspi->spiDMATxDoneFlag)))) ||
           (!(*((volatile unsigned char *)(hspi->spiDMARxDoneFlag)))))
    {
        /* Timeout management */
        if ((((BOARD_getTick() - tickstart) >= timeOut) && (timeOut != SPI_MAX_DELAY)) || (timeOut == 0U))
        {
            /* Call standard close procedure with error check */
            SPI_closeTransfer(hspi);

            SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_TIMEOUT);
            hspi->state = HAL_SPI_STATE_READY;
            return kSTATUS_TIMEOUT;
        }
    };
    hspi->txXferCount -= hspi->txXferSize;
    hspi->rxXferCount -= hspi->rxXferSize;

    DMA_unregisterCallback((DMA_IntSrc_t)hspi->spiDMATxIndex);
    DMA_unregisterCallback((DMA_IntSrc_t)hspi->spiDMARxIndex);

    if (SPI_waitOnFlagUntilTimeout(hspi, SPI_FLAG_BUSY, kSPI_SET, tickstart, timeOut) != kSTATUS_SUCCESS)
    {
        SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_FLAG_ERR);
    }

    if (SPI_waitOnFlagUntilTimeout(hspi, SPI_FLAG_TFE, kSPI_RESET, tickstart, timeOut) != kSTATUS_SUCCESS)
    {
        SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_FLAG_ERR);
    }

    SPI_closeTransfer(hspi);

    hspi->state = HAL_SPI_STATE_READY;

    return errorcode;
}

status_t SPI_abort(SPI_HandleTypeDef_t *hspi)
{
    /* Set error code to not supported */
    SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_NOT_SUPPORTED);

    return kSTATUS_FAIL;
}

status_t SPI_abortIT(SPI_HandleTypeDef_t *hspi)
{
    /* Set error code to not supported */
    SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_NOT_SUPPORTED);

    return kSTATUS_FAIL;
}

status_t SPI_DMAPause(SPI_HandleTypeDef_t *hspi)
{
    /* Set error code to not supported */
    SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_NOT_SUPPORTED);

    return kSTATUS_FAIL;
}

status_t SPI_DMAResume(SPI_HandleTypeDef_t *hspi)
{
    /* Set error code to not supported */
    SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_NOT_SUPPORTED);

    return kSTATUS_FAIL;
}

status_t SPI_DMAStop(SPI_HandleTypeDef_t *hspi)
{
    /* Set error code to not supported */
    SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_NOT_SUPPORTED);

    return kSTATUS_FAIL;
}

static void SPI_IRQHandler(SPI_HandleTypeDef_t *hspi)
{
    uint32_t trigger   = hspi->instance->ISR;
    uint32_t unusedReg = 0;
    uint32_t xferDone  = 0;
    uint32_t tickstart = 0;

    HAL_SPI_StateTypeDef State = hspi->state;

    SPI_UNUSED(unusedReg);
    SPI_UNUSED(State);
    tickstart = BOARD_getTick();

    /* SPI in mode Transmitter and Receiver ------------------------------------*/
    if (((trigger & (SPI_IT_TXE | SPI_IT_RXF)) != 0UL) && (hspi->init.direction == SPI_DIRECTION_TX_AND_RX))
    {
        if (SPI_IS_BIT_SET(trigger, SPI_IT_TXE))
        {
            hspi->txISR(hspi);
        }

        if (SPI_IS_BIT_SET(trigger, SPI_IT_RXF))
        {
            hspi->rxISR(hspi);
        }

        if ((hspi->rxXferCount == 0UL) && (hspi->txXferCount == 0UL))
        {
            if (SPI_waitOnFlagUntilTimeout(hspi, SPI_FLAG_BUSY, kSPI_SET, tickstart, SPI_IT_DELAY) != kSTATUS_SUCCESS)
            {
                SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_FLAG_ERR);
            }

            if (SPI_waitOnFlagUntilTimeout(hspi, SPI_FLAG_TFE, kSPI_RESET, tickstart, SPI_IT_DELAY) != kSTATUS_SUCCESS)
            {
                SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_FLAG_ERR);
            }

            /*call approprite user callback*/
            hspi->txRxCpltCallback(hspi);
            xferDone = 1;
        }
    }

    /* SPI in mode Transmitter ------------------------------------------------*/
    if (SPI_IS_BIT_SET(trigger, SPI_IT_TXE) && (hspi->init.direction == SPI_DIRECTION_TXONLY))
    {
        hspi->txISR(hspi);

        if (hspi->txXferCount == 0UL)
        {
            if (SPI_waitOnFlagUntilTimeout(hspi, SPI_FLAG_BUSY, kSPI_SET, tickstart, SPI_IT_DELAY) != kSTATUS_SUCCESS)
            {
                SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_FLAG_ERR);
            }

            if (SPI_waitOnFlagUntilTimeout(hspi, SPI_FLAG_TFE, kSPI_RESET, tickstart, SPI_IT_DELAY) != kSTATUS_SUCCESS)
            {
                SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_FLAG_ERR);
            }

            /*call approprite user callback*/
            hspi->txCpltCallback(hspi);
            xferDone = 1;
        }
    }

    /* SPI in mode Receiver ----------------------------------------------------*/
    if (SPI_IS_BIT_SET(trigger, SPI_IT_RXF) &&
        ((hspi->init.direction == SPI_DIRECTION_RXONLY) || (hspi->init.direction == SPI_DIRECTION_EEPROM_READ)))
    {
        hspi->rxISR(hspi);

        if (hspi->rxXferCount == 0UL)
        {
            if (SPI_waitOnFlagUntilTimeout(hspi, SPI_FLAG_BUSY, kSPI_SET, tickstart, SPI_IT_DELAY) != kSTATUS_SUCCESS)
            {
                SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_FLAG_ERR);
            }

            /*call approprite user callback*/
            hspi->rxCpltCallback(hspi);
            xferDone = 1;
        }
    }

    /* Transfer done */
    if (xferDone == 1)
    {
        SPI_closeTransfer(hspi);
    }

    /* Call SPI Standard close procedure */
    hspi->state = HAL_SPI_STATE_READY;

    /* SPI in Error Treatment --------------------------------------------------*/
    if ((trigger & SPI_IT_ERR) != 0UL)
    {
        /* SPI Overrun error interrupt occurred ----------------------------------*/
        if ((trigger & SPI_IT_TXO) != 0UL)
        {
            SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_TXFIFO_OVER);

            /*clear it*/
            unusedReg = hspi->instance->TXEICR;
        }

        /* SPI Mode Fault error interrupt occurred -------------------------------*/
        if ((trigger & SPI_IT_TXU) != 0UL)
        {
            SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_TXFIFO_UNDER);

            /*clear it*/
            unusedReg = hspi->instance->TXEICR;
        }

        /* SPI Frame error interrupt occurred ------------------------------------*/
        if ((trigger & SPI_IT_RXU) != 0UL)
        {
            SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_RXFIFO_UNDER);

            /*clear it*/
            unusedReg = hspi->instance->RXUICR;
        }

        /* SPI Underrun error interrupt occurred ------------------------------------*/
        if ((trigger & SPI_IT_RXO) != 0UL)
        {
            SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_RXFIFO_OVER);

            /*clear it*/
            unusedReg = hspi->instance->RXOICR;
        }

        /* SPI Underrun error interrupt occurred ------------------------------------*/
        if ((trigger & SPI_IT_MST) != 0UL)
        {
            SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_MULTI_MASTER_CON);

            /*clear it*/
            unusedReg = hspi->instance->MSTICR;
        }

        if ((trigger & SPI_IT_XRXO) != 0UL)
        {
            SPI_SET_BIT(hspi->errorCode, HTE_SPI_ERROR_XIP_RXFIFO_OVER);
        }

        if (hspi->errorCode != HTE_SPI_ERROR_NONE)
        {
            /* Disable SPI peripheral */
            HTE_SPI_DISABLE(hspi);

            /* Disable all interrupts */
            HTE_SPI_DISABLE_IT(hspi, (SPI_IT_TXU | SPI_IT_TXO | SPI_IT_TXE | SPI_IT_RXO | SPI_IT_RXU | SPI_IT_RXF |
                                      SPI_IT_MST | SPI_IT_XRXO));

            /* Call user error callback */
            hspi->errorCallback(hspi);
        }
    }
}

__WEAK void SPI_txCpltCallback(SPI_HandleTypeDef_t *hspi)
{
    /* Prevent unused argument(s) compilation warning */
    SPI_UNUSED(hspi);

    /* NOTE : This function should not be modified, when the callback is needed,
              the SPI_TxCpltCallback should be implemented in the user file
     */
}

__WEAK void SPI_rxCpltCallback(SPI_HandleTypeDef_t *hspi)
{
    /* Prevent unused argument(s) compilation warning */
    SPI_UNUSED(hspi);

    /* NOTE : This function should not be modified, when the callback is needed,
              the SPI_RxCpltCallback should be implemented in the user file
     */
}

__WEAK void SPI_txRxCpltCallback(SPI_HandleTypeDef_t *hspi)
{
    /* Prevent unused argument(s) compilation warning */
    SPI_UNUSED(hspi);

    /* NOTE : This function should not be modified, when the callback is needed,
              the TxRxCpltCallback should be implemented in the user file
     */
}

__WEAK void SPI_errorCallback(SPI_HandleTypeDef_t *hspi)
{
    /* Prevent unused argument(s) compilation warning */
    SPI_UNUSED(hspi);

    /* NOTE : This function should not be modified, when the callback is needed,
              the SPI_ErrorCallback should be implemented in the user file
     */
    /* NOTE : The ErrorCode parameter in the hspi handle is updated by the SPI processes
              and user can use HAL_SPI_GetError() API to check the latest error occurred
     */
}

HAL_SPI_StateTypeDef SPI_getState(SPI_HandleTypeDef_t *hspi)
{
    /* Return SPI handle state */
    return hspi->state;
}

uint32_t SPI_getError(SPI_HandleTypeDef_t *hspi)
{
    /* Return SPI ErrorCode */
    return hspi->errorCode;
}

static void SPI_rxISR8Bit(SPI_HandleTypeDef_t *hspi)
{
    /* Receive data in 8 Bit mode */
    *((uint8_t *)hspi->pRxBuffPtr)  = (*(__IO uint32_t *)&hspi->instance->DR0);
    hspi->pRxBuffPtr               += sizeof(uint8_t);
    hspi->rxXferCount--;

    /* Disable IT if no more data excepted */
    if (hspi->rxXferCount == 0UL)
    {
        /* Disable RXP interrupts */
        HTE_SPI_DISABLE_IT(hspi, SPI_IT_RXF);
    }
}

static void SPI_rxISR16Bit(SPI_HandleTypeDef_t *hspi)
{
    /* Receive data in 16 Bit mode */
    *((uint16_t *)hspi->pRxBuffPtr)  = (*(__IO uint32_t *)&hspi->instance->DR0);
    hspi->pRxBuffPtr                += sizeof(uint16_t);
    hspi->rxXferCount--;

    /* Disable IT if no more data excepted */
    if (hspi->rxXferCount == 0UL)
    {
        /* Disable RXP interrupts */
        HTE_SPI_DISABLE_IT(hspi, SPI_IT_RXF);
    }
}

static void SPI_rxISR32Bit(SPI_HandleTypeDef_t *hspi)
{
    /* Receive data in 32 Bit mode */
    *((uint32_t *)hspi->pRxBuffPtr)  = (*(__IO uint32_t *)&hspi->instance->DR0);
    hspi->pRxBuffPtr                += sizeof(uint32_t);
    hspi->rxXferCount--;

    /* Disable IT if no more data excepted */
    if (hspi->rxXferCount == 0UL)
    {
        /* Disable RXP interrupts */
        HTE_SPI_DISABLE_IT(hspi, SPI_IT_RXF);
    }
}

static void SPI_txISR8Bit(SPI_HandleTypeDef_t *hspi)
{
    /* Transmit data in 8 Bit mode */
    *(__IO uint32_t *)&hspi->instance->DR0  = *((uint8_t *)hspi->pTxBuffPtr);
    hspi->pTxBuffPtr                       += sizeof(uint8_t);
    hspi->txXferCount--;

    /* Disable IT if no more data excepted */
    if (hspi->txXferCount == 0UL)
    {
        /* Disable TXP interrupts */
        HTE_SPI_DISABLE_IT(hspi, SPI_IT_TXE);
    }
}

static void SPI_txISR16Bit(SPI_HandleTypeDef_t *hspi)
{
    /* Transmit data in 16 Bit mode */
    *((__IO uint32_t *)&hspi->instance->DR0)  = *((uint16_t *)hspi->pTxBuffPtr);
    hspi->pTxBuffPtr                         += sizeof(uint16_t);
    hspi->txXferCount--;

    /* Disable IT if no more data excepted */
    if (hspi->txXferCount == 0UL)
    {
        /* Disable TXP interrupts */
        HTE_SPI_DISABLE_IT(hspi, SPI_IT_TXE);
    }
}

static void SPI_txISR32Bit(SPI_HandleTypeDef_t *hspi)
{
    /* Transmit data in 32 Bit mode */
    *((__IO uint32_t *)&hspi->instance->DR0)  = *((uint32_t *)hspi->pTxBuffPtr);
    hspi->pTxBuffPtr                         += sizeof(uint32_t);
    hspi->txXferCount--;

    /* Disable IT if no more data excepted */
    if (hspi->txXferCount == 0UL)
    {
        /* Disable TXP interrupts */
        HTE_SPI_DISABLE_IT(hspi, SPI_IT_TXE);
    }
}

static void SPI_closeTransfer(SPI_HandleTypeDef_t *hspi)
{
    HTE_SPI_DISABLE(hspi);
}

static void SPI_DMA_IRQTxCpltCallBcak(DMA_Index_t index)
{
    s_spiDMATxDoneFlag[index] = 1;
    DMA_clearIntEndFlag(index);
    ISR_EXIT_BARRIER();
}

static status_t SPI_waitOnFlagUntilTimeout(SPI_HandleTypeDef_t *hspi, uint32_t Flag, SPI_flagStatus Status,
                                           uint32_t Tickstart, uint32_t Timeout)
{
    /* Wait until flag is set */
    while ((HTE_SPI_GET_FLAG(hspi, Flag) ? kSPI_SET : kSPI_RESET) == Status)
    {
        /* Check for the Timeout */
        if ((((BOARD_getTick() - Tickstart) >= Timeout) && (Timeout != SPI_MAX_DELAY)) || (Timeout == 0U))
        {
            return kSTATUS_TIMEOUT;
        }
    }
    return kSTATUS_SUCCESS;
}

static void SPI_DMA_IRQRxCpltCallBcak(DMA_Index_t index)
{
    s_spiDMARxDoneFlag[index] = 1;

    DMA_clearIntEndFlag(index);
    ISR_EXIT_BARRIER();
}

#if defined(SPIA)
void SPIA_DriverHandler(void)
{
    SPI_IRQHandler(SPI_getHandle(SPI_BUSA));

    ISR_EXIT_BARRIER();
}
#endif

#if defined(SPIB)
void SPIB_DriverHandler(void)
{
    SPI_IRQHandler(SPI_getHandle(SPI_BUSB));

    ISR_EXIT_BARRIER();
}
#endif

#if defined(SPIC)
void SPIC_DriverHandler(void)
{
    SPI_IRQHandler(SPI_getHandle(SPI_BUSC));

    ISR_EXIT_BARRIER();
}
#endif
