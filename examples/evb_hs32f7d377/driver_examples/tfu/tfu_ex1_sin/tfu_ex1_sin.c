/*
 * Copyright 2023 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*******************************************************************************
//
// FILE:   tfu_ex1_sin
//
// TITLE:  TFU Output Example.
//
//! \addtogroup driver_example_list
//! <h1> TFU Enable </h1>
//!//!
//! \b Watch \b Variables \n
//!  - outputFloat.
//!
 ******************************************************************************/
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "board.h"
#include "hte_tfu.h"
#include "hte_sysctrl.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Size of Transmission buffer */
#define TFU_CAL_NUM             10U
#define TFU_RESULT_NUM          2U

#define TFU_SIN_IDX             0U
#define TFU_COS_IDX             1U

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/* No Prototypes */

/*******************************************************************************
 * Variables
 ******************************************************************************/
static TFU_ConfigType_t tfu_cfg = {0};
static float inputFloat[TFU_CAL_NUM] = {0};
static float outputFloat[TFU_CAL_NUM][TFU_RESULT_NUM] = {0};

static uint32_t inputCORDIC[TFU_CAL_NUM] = {0};
static uint32_t outputCORDIC[TFU_CAL_NUM][TFU_RESULT_NUM] = {0};

/*******************************************************************************
 * Codes
 ******************************************************************************/
static void initTFU()
{
    tfu_cfg.function = TFU_FUNCTION_SINE;
    tfu_cfg.inSize = TFU_INSIZE_32BITS;
    tfu_cfg.outSize = TFU_OUTSIZE_32BITS;
    tfu_cfg.nbRead = TFU_NBREAD_2;
    tfu_cfg.nbWrite = TFU_NBWRITE_1;
    tfu_cfg.precision = TFU_PRECISION_4CYCLES;
    tfu_cfg.priority = TFU_PRIORITY_FIXED;
    tfu_cfg.threadnum = TFU_THREADNUM_0;
#if defined(BOARD_USE_CPU1)   
    TFU_Configure(kTFU_INDEX_0, &tfu_cfg);  
#else
    TFU_Configure(kTFU_INDEX_1, &tfu_cfg);  
#endif    
}

static void convertToCORDIC()
{
    uint8_t num;
    
    for(num = 0; num < TFU_CAL_NUM; num++)
    {
        inputFloat[num] = 0.25 + 0.01 * num;
        inputCORDIC[num] = VALUE_TO_CORDIC31(inputFloat[num]);
    }
}

int main(void)
{
    BOARD_init();
#if defined(BOARD_USE_CPU1)  
    SYSCTRL_enableTFU();
#endif
    /* Infinite the TFU configuration */
    initTFU();    
       
    convertToCORDIC();   
    memset(outputFloat, 0, sizeof(float) * TFU_CAL_NUM * TFU_RESULT_NUM);
    for (uint8_t num = 0; num < TFU_CAL_NUM; num++)
    {
        TFU_valueCalculateZOForAPP(&inputCORDIC[num], outputCORDIC[num]);
        CORDIC31_TO_VALUE(outputCORDIC[num][TFU_SIN_IDX], outputFloat[num][TFU_SIN_IDX]);
        CORDIC31_TO_VALUE(outputCORDIC[num][TFU_COS_IDX], outputFloat[num][TFU_COS_IDX]);
    }
    
    /* Infinite loop */
    while (1)
    {
    }
    
}