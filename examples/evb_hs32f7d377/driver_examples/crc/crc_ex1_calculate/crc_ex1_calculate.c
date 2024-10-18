/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*
 * 
 * \file crc_ex1_calculate.c
 * 
 * \brief CRC Example
 * 
 * This example shows the CRC functionality.
 * 
 * \b External \b Connections \n
 *  - None.
 * 
 * \b Watch \b Variables \n
 *   - error - Checks if there is an error that occurred when the result differ with soft crc32.
 * 
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <math.h>
#include "board.h"
#include "hte_sysctrl.h"
#include "hte_crc.h"
#include "sw_crc.h"
#ifdef HTE_DEVICE_HS32F7D377_CPU1
//#include "hte_cpu1_ipc.h"
#include "hte_cpu1_ipc_com.h"
#else
#include "hte_cpu2_ipc_com.h"
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/

//#define CRC_32
//#define CRC_24
//#define CRC_16
//#define CRC_8
#define CRC_7

#define DATA_SIZE 256  /* MAX supported size  = 256 * 4 = 1kB */


/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void dataInit(void);
void CRC_config(void);
void CRC_start(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/
uint32_t hdr_result,sw_result;
uint32_t seed;
uint32_t byteSwappedData;

CRC_InitParams_t initPara;

uint32_t data[DATA_SIZE] = {0};


/*******************************************************************************
 * Codes
 ******************************************************************************/
void main(void)
{
    /* Initialize device clock and peripherals*/
    BOARD_init();

#ifdef HTE_DEVICE_HS32F7D377_CPU1
    IPC_comInit();
    /* Set CPU2 boot from EFLASH */ 
//    IPC_setBootMode(IPC_BOOTMODE_CPU2_EFLASH);
#endif
    dataInit();
  
    CRC_config();

    CRC_start();

    /* Stop Application. */
    while(1)
    {
        DELAY(1000000);
        PRINTF("test done \r\n");
    }
}


void dataInit(void)
{
    uint32_t tseed;
    uint32_t i;


    /* Initialize the random number generator */
    tseed = 0x55aa55aa;
    srand(tseed);
    srand(rand());

    seed  =  rand();
    seed = (uint32_t)(seed <<16) | rand();       /* Initialize with seed */

    /* Initialize the Data_Buffer with 32 bit random data */
    for(i = 0; i < DATA_SIZE; i++)
    {
        data[i] = rand();
        data[i] = (data[i] << 16) | rand();
    }
}


void CRC_config(void)
{
    /** crc source config **/
    initPara.initValue       = seed;
    
    #ifdef CRC_32
    initPara.poly            = 0x04C11DB7;
    initPara.polySize        = kCRC_POLY32_SIZE;
    #endif

    #ifdef CRC_24
    initPara.poly            = 0x5D6DCB;
    initPara.polySize        = kCRC_POLY24_SIZE;
    #endif

    #ifdef CRC_16
    initPara.poly            = 0x8005;
    initPara.polySize        = kCRC_POLY16_SIZE;
    #endif

    #ifdef CRC_8
    initPara.poly            = 07;
    initPara.polySize        = kCRC_POLY8_SIZE;
    #endif

    #ifdef CRC_7
    initPara.poly            = 0x09;
    initPara.polySize        = kCRC_POLY7_SIZE;
    #endif
    
    initPara.revInput        = kCRC_REVINPUT_FORMAT_UNDEFINED;
    initPara.revByte         = kCRC_BYTE_REVERSE_DISABLE;
    initPara.revOut          = kCRC_OUT_REVERSE_DISABLE;
    initPara.inputDataFormat = kCRC_INPUT_FORMAT_WORD;
}

void CRC_start(void)
{
    uint32_t temp, len, swlen;
    uint8_t           i;
    uint8_t          *ptr;
    uint32_t          swdata[DATA_SIZE] = {0};
    uint16_t         *sw16ptr = (uint16_t *)swdata;
    uint32_t         *sw32ptr = (uint32_t *)swdata;
    
#ifdef HTE_DEVICE_HS32F7D377_CPU1
    SYSCTRL_enableCRC();
#else
    IPC_com_SYSCTRL_enableCRC();
#endif

    /**init hardware CRC and software CRC**/
    ptr = (uint8_t *)data;
    temp = DATA_SIZE;
    CRC_init(CRC, &initPara);
    CRC_swSetInitVal(initPara.initValue);

    
    /**if input data is not aligned to 4 byte**/
    if (initPara.revInput == kCRC_REVINPUT_FORMAT_WORD)
    {
        if (temp % 4 == 3)
        {
            temp++;
        }
    }

    /**make supported data format**/
    switch (initPara.inputDataFormat)
    {
        case kCRC_INPUT_FORMAT_HALFWORD:
            len  = temp / 2;
            len += temp % 2 > 0 ? 1 : 0;
            for (i = 0; i < len; i++)
            {
                *(sw16ptr + i) = bswap_16(*(uint16_t *)(ptr + i * 2));
            }
            swlen = len * 2;
            break;
        case kCRC_INPUT_FORMAT_WORD:
            len  = temp / 4;
            len += temp % 4 > 0 ? 1 : 0;
            for (i = 0; i < len; i++)
            {
                *(sw32ptr + i) = bswap_32(*(uint32_t *)(ptr + i * 4));
            }
            swlen = len * 4;
            break;
        default:
            memcpy(swdata, ptr, temp);
            len   = temp;
            swlen = len;
            break;
    }

    /**calculte**/
    hdr_result = CRC_calculte(CRC, data, len);
    sw_result = CRC_software_calculate(CRC, (uint8_t *)swdata, swlen,0);
    
    if(hdr_result == sw_result)
    {
        PRINTF("crc calcute success\r\n");
    }
    else
    {
        PRINTF("crc calcute fail\r\n");
    }
    
    /**accumulate**/
    hdr_result = CRC_accumulate(CRC, data, len);
    sw_result = CRC_software_calculate(CRC, (uint8_t *)swdata, swlen,1);
    
    if(hdr_result == sw_result)
    {
        PRINTF("crc accumulate success\r\n");
    }
    else
    {
        PRINTF("crc accumulate fail\r\n");
    }    
}



