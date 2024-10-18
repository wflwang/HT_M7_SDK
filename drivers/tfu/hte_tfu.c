/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_tfu.c
 * \brief SDK TFU driver source file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_tfu.h"
#include <math.h>

/**
  * @brief  Write input data for TFU processing, and increment input buffer pointer.
  * @param  tfuIdx is the index of TFU.
  * @param  threadnum is the thread number of TFU.
  * @param  ppInBuff Pointer to pointer to input buffer.
  */
static void TFU_writeInDataIncrementPtr(TFU_Index_t tfuIdx, uint32_t threadnum, uint32_t **ppInBuff)
{
    TFU_Type* tfux = (TFU_Type*)TFU_BASE;

    if (tfuIdx == kTFU_INDEX_0)
    {
        /* First write of input data in the Write Data register */
        tfux->TFU0_FIFOb[threadnum].TFU0_WDATA0b.TFU0_ARG0 = **ppInBuff;

        /* Increment input data pointer */
        (*ppInBuff)++;

        /* Check if second write of input data is expected */
        if (tfux->TFU0_CSRb[threadnum].TFU0_ARG_NUM == 1)
        {
            /* Second write of input data in the Write Data register */
            tfux->TFU0_FIFOb[threadnum].TFU0_WDATA1b.TFU0_ARG1 = **ppInBuff;

            /* Increment input data pointer */
            (*ppInBuff)++;
        }
    }
    else
    {
        /* First write of input data in the Write Data register */
        tfux->TFU1_FIFOb[threadnum].TFU1_WDATA0b.TFU1_ARG0 = **ppInBuff;

        /* Increment input data pointer */
        (*ppInBuff)++;

        /* Check if second write of input data is expected */
        if (tfux->TFU1_CSRb[threadnum].TFU1_ARG_NUM == 1)
        {
            /* Second write of input data in the Write Data register */
            tfux->TFU1_FIFOb[threadnum].TFU1_WDATA1b.TFU1_ARG1 = **ppInBuff;

            /* Increment input data pointer */
            (*ppInBuff)++;
        }
    }
}


/**
  * @brief  Read output data of TFU processing, and increment output buffer pointer.
  * @param  tfuIdx is the index of TFU.
  * @param  threadnum is the thread number of TFU.
  * @param  ppOutBuff Pointer to pointer to output buffer.
  */
static void TFU_readOutDataIncrementPtr(TFU_Index_t tfuIdx, uint32_t threadnum, uint32_t **ppOutBuff)
{
    TFU_Type* tfux = (TFU_Type*)TFU_BASE;

    if (tfuIdx == kTFU_INDEX_0)
    {
        /* First read of output data from the Read Data register */
        **ppOutBuff = (int32_t)tfux->TFU0_FIFOb[threadnum].TFU0_RDATA0b.TFU0_RES0;

        /* Increment output data pointer */
        (*ppOutBuff)++;

        /* Check if second read of output data is expected */
        if (tfux->TFU0_CSRb[threadnum].TFU0_RES_NUM == 1)
        {
            /* Second read of output data from the Read Data register */
            **ppOutBuff = (int32_t)tfux->TFU0_FIFOb[threadnum].TFU0_RDATA1b.TFU0_RES1;

            /* Increment output data pointer */
            (*ppOutBuff)++;
        }
    }
    else
    {
        /* First read of output data from the Read Data register */
        **ppOutBuff = (int32_t)tfux->TFU1_FIFOb[threadnum].TFU1_RDATA0b.TFU1_RES0;

        /* Increment output data pointer */
        (*ppOutBuff)++;

        /* Check if second read of output data is expected */
        if (tfux->TFU1_CSRb[threadnum].TFU1_RES_NUM == 1)
        {
            /* Second read of output data from the Read Data register */
            **ppOutBuff = (int32_t)tfux->TFU1_FIFOb[threadnum].TFU1_RDATA1b.TFU1_RES1;;

            /* Increment output data pointer */
            (*ppOutBuff)++;
        }
    }
}

/*!
 * \brief Calculate LUT Matrix Element Index
 *
 * \details Calculates the index in a matrix stored within a Look-Up Table (LUT).
 *
 * \param[in] base The number serving as the scaling factor.
 * \param[in] num The selection of the matrix element within the LUT.

 * \return Unsigned 32-bit integer index corresponding to the located matrix element in the LUT.

 * \note Confirm that the combined inputs the range of the LUT matrix dimensions.
 *
 * \warning Incorrect input values can lead to invalid memory accesses.
 */
static uint32_t TFU_LUTPCalculate(double base, uint32_t num)//num = 0 - 23
{
    float result;
    result = log2(1 + (1 / pow(2, num + 1))) / log2(base);

    return Value_To_CORDIC31(result, 1);
}

/*!
 * \brief Calculate LUT Matrix Element Index
 *
 * \details Calculates the index for accessing an 
 * element in a matrix stored within a Look-Up Table (LUT).
 *
 * \param[in] base A double-precision number.
 * \param[in] num The selection of the matrix element within the LUT.
 *
 * \return Unsigned 32-bit integer to the located matrix element in the LUT.
 *
 * \note Confirm that the combined inputs align.
 *
 * \warning Incorrect input values can lead to invalid memory accesses.
 */
static uint32_t TFU_LUTMCalculate(double base, uint32_t num)
{
    float result;
    result = log2(1 - (1 / pow(2, num + 1))) / log2(base);

    return Value_To_CORDIC31(result, 1);
}

bool TFU_Configure(TFU_Index_t tfuIdx, TFU_ConfigType_t *sConfig)
{
    TFU_Type* tfux = (TFU_Type*)TFU_BASE;
    
    /* Check the parameters */
    assert(IS_TFU_THREADNUM(sConfig->threadnum));
    assert(IS_TFU_FUNCTION(sConfig->function));
    assert(IS_TFU_PRECISION(sConfig->precision));
    assert(IS_TFU_NBWRITE(sConfig->nbWrite));
    assert(IS_TFU_NBREAD(sConfig->nbRead));
    assert(IS_TFU_INSIZE(sConfig->inSize));
    assert(IS_TFU_OUTSIZE(sConfig->outSize));

    uint32_t threadnum = sConfig->threadnum;
    if (tfuIdx == kTFU_INDEX_0)
    {
        /* Apply all configuration parameters in TFU control register */
        tfux->TFU0_CFGb.TFU0_ARB_MODE = sConfig->priority;
        tfux->TFU0_CSRb[threadnum].TFU0_FUNC_SEL = sConfig->function;
        tfux->TFU0_CSRb[threadnum].TFU0_ARG_SIZE = sConfig->inSize;
        tfux->TFU0_CSRb[threadnum].TFU0_RES_SIZE = sConfig->outSize;
        tfux->TFU0_CSRb[threadnum].TFU0_ARG_NUM = sConfig->nbWrite;
        tfux->TFU0_CSRb[threadnum].TFU0_RES_NUM = sConfig->nbRead;
        tfux->TFU0_CSRb[threadnum].TFU0_PRECISION = sConfig->precision;
    }
    else
    {
        /* Apply all configuration parameters in TFU control register */
        tfux->TFU1_CFGb.TFU1_ARB_MODE = sConfig->priority;
        tfux->TFU1_CSRb[threadnum].TFU1_FUNC_SEL = sConfig->function;
        tfux->TFU1_CSRb[threadnum].TFU1_ARG_SIZE = sConfig->inSize;
        tfux->TFU1_CSRb[threadnum].TFU1_RES_SIZE = sConfig->outSize;
        tfux->TFU1_CSRb[threadnum].TFU1_ARG_NUM = sConfig->nbWrite;
        tfux->TFU1_CSRb[threadnum].TFU1_RES_NUM = sConfig->nbRead;
        tfux->TFU1_CSRb[threadnum].TFU1_PRECISION = sConfig->precision;
    }

    /* Return function status */
    return 1;
}

bool TFU_valueCalculate(TFU_Index_t tfuIdx, uint32_t threadnum, uint32_t *pInBuff, 
                                uint32_t *pOutBuff, uint32_t NbCalc)
{
    uint32_t index;
    uint32_t *p_tmp_in_buff = pInBuff;
    uint32_t *p_tmp_out_buff = pOutBuff;
    TFU_Type* tfux = (TFU_Type*)TFU_BASE;

    /* Check parameters setting */
    if ((pInBuff == NULL) || (pOutBuff == NULL) || (NbCalc == 0U))
    {
        /* Return error status */
        return 0;
    }

    /* Write of input data in Write Data register, and increment input buffer pointer */
    TFU_writeInDataIncrementPtr(tfuIdx, threadnum, &p_tmp_in_buff);

    /* Calculation is started.
       Provide next set of input data, until number of calculation is achieved */
    for (index = (NbCalc - 1U); index > 0U; index--)
    {
        /* Write of input data in Write Data register, and increment input buffer pointer */
        TFU_writeInDataIncrementPtr(tfuIdx, threadnum, &p_tmp_in_buff);
        
        /* Wait for RRDY flag to be raised */
        if (tfuIdx == kTFU_INDEX_0)
        {
            while (tfux->TFU0_CSRb[threadnum].TFU0_RRDY == 0);
        }
        else
        {
            while (tfux->TFU1_CSRb[threadnum].TFU1_RRDY == 0);        
        }

        /* Read output data from Read Data register, and increment output buffer pointer */
        TFU_readOutDataIncrementPtr(tfuIdx, threadnum, &p_tmp_out_buff);
    }

    /* Read output data from Read Data register, and increment output buffer pointer */
    TFU_readOutDataIncrementPtr(tfuIdx, threadnum, &p_tmp_out_buff);

    /* Return function status */
    return 1;
}

bool TFU_valueCalculateZOForAPP(uint32_t *pInBuff, uint32_t *pOutBuff)                              
{
    TFU_Type* tfux = (TFU_Type*)TFU_BASE;

    tfux->TFU0_FIFOb[0].TFU0_WDATA0b.TFU0_ARG0 = *pInBuff;
    *pOutBuff = (int32_t)tfux->TFU0_FIFOb[0].TFU0_RDATA0b.TFU0_RES0;
    pOutBuff++;
    *pOutBuff = (int32_t)tfux->TFU0_FIFOb[0].TFU0_RDATA1b.TFU0_RES1;

    return 1;
}

bool TFU_valueCalculateZO(TFU_Index_t tfuIdx, uint32_t threadnum, uint32_t *pInBuff, 
                                            uint32_t *pOutBuff, uint32_t NbCalc)
{
    uint32_t index;
    uint32_t *p_tmp_in_buff = pInBuff;
    uint32_t *p_tmp_out_buff = pOutBuff;

    /* Check parameters setting */
    if ((pInBuff == NULL) || (pOutBuff == NULL) || (NbCalc == 0U))
    {
        /* Return error status */
        return 0;
    }

    /* Write of input data in Write Data register, and increment input buffer pointer */
    TFU_writeInDataIncrementPtr(tfuIdx, threadnum, &p_tmp_in_buff);

    /* Calculation is started.
       Provide next set of input data, until number of calculation is achieved */
    for (index = (NbCalc - 1U); index > 0U; index--)
    {
        /* Write of input data in Write Data register, and increment input buffer pointer */
        TFU_writeInDataIncrementPtr(tfuIdx, threadnum, &p_tmp_in_buff);

        /* Read output data from Read Data register, and increment output buffer pointer
            The reading is performed in Zero-Overhead mode:
            reading is ordered immediately without waiting result ready flag */
        TFU_readOutDataIncrementPtr(tfuIdx, threadnum, &p_tmp_out_buff);
    }

    /* Read output data from Read Data register, and increment output buffer pointer
       The reading is performed in Zero-Overhead mode:
       reading is ordered immediately without waiting result ready flag */
    TFU_readOutDataIncrementPtr(tfuIdx, threadnum, &p_tmp_out_buff);

    /* Return function status */
    return 1;
}

bool TFU_valueCalculate_IT(TFU_Index_t tfuIdx, uint32_t threadnum, uint32_t *pInBuff, uint32_t NbCalc)
{
    uint32_t *tmp_pInBuff = pInBuff;
    uint32_t index;

    /* Check parameters setting */
    if (pInBuff == NULL)
    {
        /* Return error status */
        return 0;
    }
    //NVIC_EnableIRQ(TFU_IRQn);

    /* Initiate the processing by providing input data
       in the Write Data register */
    TFU_writeInDataIncrementPtr(tfuIdx, threadnum, &tmp_pInBuff);

    /* Calculation is started.
       Provide next set of input data, until number of calculation is achieved */
    for (index = (NbCalc - 1U); index > 0U; index--)
    {
        /* Write of input data in Write Data register, and increment input buffer pointer */
        TFU_writeInDataIncrementPtr(tfuIdx, threadnum, &tmp_pInBuff);
    }   

    /* Return function status */
    return 1;
}

bool TFU_vauleCalculate_DMA(TFU_Index_t tfuIdx, uint32_t threadnum,  uint32_t *pInBuff, uint32_t *pOutBuff,
                                           uint32_t NbCalc, uint32_t DMADirection)
{
    uint32_t outdestaddr, outsrcaddr;
    uint32_t insrcaddr, indestaddr;
    TFU_Type* tfux = (TFU_Type*)TFU_BASE;

    /* Check the parameters */
    assert(IS_TFU_DMA_DIRECTION(DMADirection));

    /* Check parameters setting */
    if (NbCalc == 0U)
    {
        /* Return error status */
        return 0;
    }

    /* Check if TFU DMA direction "Out" is requested */
    if ((DMADirection == TFU_DMA_DIR_OUT) || (DMADirection == TFU_DMA_DIR_IN_OUT))
    {
        /* Check parameters setting */
        if (pOutBuff == NULL)
        {
        /* Return error status */
        return 0;
        }
    }

    /* Check if TFU DMA direction "In" is requested */
    if ((DMADirection == TFU_DMA_DIR_IN) || (DMADirection == TFU_DMA_DIR_IN_OUT))
    {
        /* Check parameters setting */
        if (pInBuff == NULL)
        {
        /* Return error status */
        return 0;
        }
    }

    DMA_initialize();
    
    /* Check if TFU DMA direction "In" is requested */
    if ((DMADirection == TFU_DMA_DIR_IN) || (DMADirection == TFU_DMA_DIR_IN_OUT))
    {
        /* Set the TFU DMA transfer complete callback */
        DMA_registerCallback(kDMA_CH1_INT, (DMA_Callback_t)TFU_DMAInCplt, 2);

        /* Enable the DMA stream managing TFU input data write */
        insrcaddr = (uint32_t)(pInBuff);
        indestaddr = TFU_BASE + 0x800 + 0x10 * threadnum + 0x40 * tfuIdx;

        DMA_configAddresses(kDMA_INDEX_CH1, (const void *)indestaddr, (const void *)insrcaddr);  
        DMA_configBurst(kDMA_INDEX_CH1, 2, 4, 4);   
        DMA_configTransfer(kDMA_INDEX_CH1, NbCalc, 4, -4); 
        DMA_setDataSize(kDMA_INDEX_CH1, kDMA_DATASIZE_32BIT);      
        DMA_configTrigger(kDMA_INDEX_CH1, (DMA_Trigger_t)(kDMA_TRIGGER_TFU0_TH0_WR + 2 * threadnum + 8 * tfuIdx));
        DMA_configMode(kDMA_INDEX_CH1, kDMA_MODE_ONESHOT);
        DMA_disableOverRunInterrupt(kDMA_INDEX_CH1);
        DMA_disableBegInterrupt(kDMA_INDEX_CH1);
        DMA_enableEndInterrupt(kDMA_INDEX_CH1);
        DMA_clearStatusFlag(kDMA_INDEX_CH1);
        DMA_enableTrigger(kDMA_INDEX_CH1);
        //start dma transfer
        DMA_startChannel(kDMA_INDEX_CH1);

        /* Enable input data Write DMA request */
        if(tfuIdx == kTFU_INDEX_0)
        {
            tfux->TFU0_CSRb[threadnum].TFU0_DMA_WEN = 1;
        }
        else
        {
            tfux->TFU1_CSRb[threadnum].TFU1_DMA_WEN = 1;
        }
    }

    /* Check if TFU DMA direction "Out" is requested */
    if ((DMADirection == TFU_DMA_DIR_OUT) || (DMADirection == TFU_DMA_DIR_IN_OUT))
    {
        /* Set the TFU DMA transfer complete callback */
        DMA_registerCallback(kDMA_CH2_INT, (DMA_Callback_t)TFU_DMAOutCplt, 2);

        /* Enable the DMA stream managing TFU output data read */

        outdestaddr = (uint32_t)(pOutBuff);  
        outsrcaddr = TFU_BASE + 0x808 + 0x10 * threadnum + 0x40 * tfuIdx;

        DMA_configAddresses(kDMA_INDEX_CH2, (const void *)outdestaddr, (const void *)outsrcaddr);    
        DMA_configBurst(kDMA_INDEX_CH2, 2, 4, 4);   
        DMA_configTransfer(kDMA_INDEX_CH2, NbCalc, -4, 4); 
        DMA_setDataSize(kDMA_INDEX_CH2, kDMA_DATASIZE_32BIT);           
        DMA_configTrigger(kDMA_INDEX_CH2, (DMA_Trigger_t)(kDMA_TRIGGER_TFU0_TH0_RD + 2 * threadnum + 8 * tfuIdx));
        DMA_configMode(kDMA_INDEX_CH2, kDMA_MODE_ONESHOT);       
        DMA_disableOverRunInterrupt(kDMA_INDEX_CH2);
        DMA_disableBegInterrupt(kDMA_INDEX_CH2);
        DMA_enableEndInterrupt(kDMA_INDEX_CH2);
        DMA_clearStatusFlag(kDMA_INDEX_CH2);
        DMA_enableTrigger(kDMA_INDEX_CH2);

        //start dma transfer
        DMA_startChannel(kDMA_INDEX_CH2);

        /* Enable output data Read DMA requests */
        if(tfuIdx == kTFU_INDEX_0)
        {
            tfux->TFU0_CSRb[threadnum].TFU0_DMA_REN = 1;
        }
        else
        {
            tfux->TFU1_CSRb[threadnum].TFU1_DMA_REN = 1;
        }
    }

    /* Return function status */
    return 1;
}

__WEAK void TFU_DMAInCplt(DMA_Index_t index)
{
    UNUSED(index);
      /* NOTE : This function should not be modified; when the callback is needed,
            the HAL_TFU_CalculateCpltCallback can be implemented in the user file
        */
}

__WEAK void TFU_DMAOutCplt(DMA_Index_t index)
{
    UNUSED(index);
      /* NOTE : This function should not be modified; when the callback is needed,
            the HAL_TFU_CalculateCpltCallback can be implemented in the user file
        */
}

void TFU_interrputSelect(uint32_t interruptType)
{
    /* Obtain base address of TFU. */
    TFU_Type* tfux = (TFU_Type*)TFU_BASE;

    /* Enable the specified interrupt by bitwise. */
    tfux->TFU_INT_EN |= interruptType;
}

void TFU_cpuSelect(uint32_t cpuNumber)
{
    /* Obtain base address of TFU. */
    TFU_Type* tfux = (TFU_Type*)TFU_BASE;

    /* Enable the specified cpu. */
    tfux->TFU_INT_EN = (tfux->TFU_INT_EN & ~(0xFF << 24)) |
                        cpuNumber << 24;
}

void TFU_dmaFunctionDisable(TFU_Type* tfux, uint32_t tfunum, uint32_t threadnum)
{
    if(tfunum == kTFU_INDEX_0)
    {
        /* Disable DMA read and for TFU0 thread. */
        tfux->TFU0_CSRb[threadnum].TFU0_DMA_REN = 0;
        tfux->TFU0_CSRb[threadnum].TFU0_DMA_WEN = 0;
    }
    else
    {
        /* Disable DMA read and for TFU1 thread. */
        tfux->TFU1_CSRb[threadnum].TFU1_DMA_REN = 0;
        tfux->TFU1_CSRb[threadnum].TFU1_DMA_WEN = 0;
    }
}

void TFU_LUTBaseConfig(TFU_Type* tfux, uint32_t tfunum, double base)
{
    uint32_t num;

    if(tfunum == kTFU_INDEX_0)
    {
        for(num  = 0; num < 24; num ++)
        {
            /* Update polynomial LUT with calculated values for TFU0. */
            TFU0_LUTP_REG32(num) = TFU_LUTPCalculate(base, num);
        }
        for(num  = 0; num < 24; num ++)
        {
            /* Update matrix  LUT with calculated values for TFU0. */
            TFU0_LUTM_REG32(num) = TFU_LUTMCalculate(base, num);
        }
    }
    else if(tfunum == kTFU_INDEX_1)
    {
        for(num  = 0; num < 24; num ++)
        {
            /* Update polynomial LUT with calculated values for TFU1. */
            TFU1_LUTP_REG32(num) = TFU_LUTPCalculate(base, num);
        }
        for(num  = 0; num < 24; num ++)
        {
            /* Update matrix LUT with calculated values for TFU1. */
            TFU1_LUTM_REG32(num) = TFU_LUTMCalculate(base, num);
        }
    }
}

void CORDIC31_To_Value(int CORDIC31, float *RES)
{        
    if (CORDIC31 & 0x80000000)        
    {                
        /* Convert negative value. */
        CORDIC31 = CORDIC31 & 0x7FFFFFFF;                
        *RES = (((float)(CORDIC31) - 0x80000000) / 0x80000000);
    }        
    else        
    {              
        /* Convert positive value or zero. */
        *RES = (float)(CORDIC31) / 0x80000000;        
    }
}

void CORDIC15_To_Value(int CORDIC15, float *REA, float *REB)
{        
    if (CORDIC15 & 0x80000000)      
    {           
        /* Convert negative value. */   
        *REA = ((float)((CORDIC15 >> 16) & 0x7FFF) - 0x8000) / 0x8000;        
    }        
    else        
    {    
        /* Convert positive value or zero. */        
        *REA = (float)((CORDIC15 >> 16) & 0xFFFF) / 0x8000;        
    }        
    if (CORDIC15 & 0x8000)     
    {       
        /* Convert negative value. */    
        *REB = ((float)(CORDIC15 & 0x7FFF) - 0x8000) / 0x8000;        
    }        
    else        
    {   
        /* Convert positive value or zero. */        
        *REB = (float)(CORDIC15 & 0xFFFF) / 0x8000;        
    }
}

int Value_To_CORDIC31(float Value, float Coefficient)
{        
    int CORDIC31;    
    /* Scale and convert to CORDIC 31-bit format. */    
    CORDIC31 = (int)((Value / Coefficient) * 0x80000000);

    /* Return the converted CORDIC value. */    
    return CORDIC31;
}

int Value_To_CORDIC15(float ValueA, float ValueB, float Coefficient)
{        
    int CORDIC15; 

    /* Scale and convert to CORDIC 15-bit format. */    
    CORDIC15 = (int)((ValueA / Coefficient) * 0x8000) << 16;        
    CORDIC15 = CORDIC15 | (int)((ValueB / Coefficient) * 0x8000);

    /* Return the converted CORDIC value. */    
    return CORDIC15;
}






