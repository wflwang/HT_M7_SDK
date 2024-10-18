/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*!
 * \file hte_eflash.c
 * \brief SDK EFLASH driver source file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 */
#include "hte_eflash.h"

/*******************************************************************************
* Definitions
*/
/** Definitions of Parameters */


/*******************************************************************************
 * Implements
 */


/* Private function ----------------------------------------------------------*/

/*!
 * \brief Static Function to Initialize EFLASH Power-On Reset (POR) Time Configuration
 *
 * \details This function sets up the stabilization time requirements for the EFLASH module 
 *          following a Power-On Reset (POR) event.
 *          
 * \param[in] base Pointer to the EFLASH peripheral base address.
 * \param[in] p_por_cfg Pointer to the Power-On Reset cycle time configuration details. 
 * 
 */
static void EFLASH_timeForPORInit(EFLASH_Type *base, EFLASH_Timing_Power_t *p_por_cfg)
{
    assert(EFLASH_baseIsValid(base));

    base->POR_CNTb.TRHR = p_por_cfg->pown_on_tRHR;
    base->POR_CNTb.TRT = p_por_cfg->pown_on_tRT;

    base->DPD_CNTb.TDPDSR = p_por_cfg->pown_on_tDPDSR;
    base->DPD_CNTb.TDPDH = p_por_cfg->pown_on_tDPDH; 
}
 
/*!
 * \brief Initialize EFLASH Low-Voltage Control (LVCTL) Time Configuration
 *
 * \details This function configures the timing parameters related to the 
 *          Low-Voltage Control (LVCTL) feature of the EFLASH module.

 *
 * \param[in] base Pointer to the EFLASH peripheral base address.
 * \param[in] p_lvctl_cfg Pointer to a structure instance carrying the 
 *                        Low-Voltage Control time configuration. 
 */
static void EFLASH_timeForLvctlInit(EFLASH_Type *base, EFLASH_Timing_LVCTL_t *p_lvctl_cfg)
{
    assert(EFLASH_baseIsValid(base));

    base->LVCTL_CNTb.TCRC_LVCTL = p_lvctl_cfg->lvctl_tCRC;
    base->LVCTL_CNTb.TACC_LVCTL = p_lvctl_cfg->lvctl_tACC;
}

/*!
 * \brief Static Function to Initialize EFLASH Programming Time Configuration
 *
 * \details Configures the programming time parameters for the EFLASH module.
 *
 * \param[in] base Pointer to the EFLASH peripheral base address.
 * \param[in] p_prog_cfg Pointer to the Programming time configuration details. 
 * 
 */
static void EFLASH_timeForProgramInit(EFLASH_Type *base, EFLASH_Timing_Program_t *p_prog_cfg)
{
    assert(EFLASH_baseIsValid(base));

    base->PROG_CNT1b.TPROG = p_prog_cfg->prog_tPROG; // 16bit (13 bit)
    base->PROG_CNT1b.TPGS = p_prog_cfg->prog_tPGS;   //16bit

    base->PROG_CNT2b.TPGH = p_prog_cfg->prog_tPGH;  //8bit  (3 bit)
    base->PROG_CNT2b.TADH = p_prog_cfg->prog_tADH;  //8bit  (3 bit)
    base->PROG_CNT2b.TADS = p_prog_cfg->prog_tADS;  //8bit  (3 bit)

    base->PROG_CNT3b.TNVS = p_prog_cfg->prog_tNVS;   // 16bit  (11 bit)

    base->PROG_CNT4b.TRW = p_prog_cfg->prog_tRW;  // 8bit  (3 bit)
    base->PROG_CNT4b.TACC = p_prog_cfg->prog_tACC;  // 8bit  (3 bit)
    base->PROG_CNT4b.TWS = p_prog_cfg->prog_tWSH;  // 8bit  (3 bit)

    base->RCV_CNT1b.TRCV_PROG = p_prog_cfg->prog_tRCV;  // 16 bit    
}
 
/*!
 * \brief Static Function to Initialize EFLASH Erase Time Configuration
 *
 * \details This function configures the erase time parameters for the EFLASH module.
 *
 * \param[in] base Pointer to the EFLASH peripheral base address.
 * \param[in] p_erase_cfg Pointer to the Erase time configuration parameters. 
 * 
 */
static void EFLASH_timeForEraseInit(EFLASH_Type *base, EFLASH_Timing_ERASE_t *p_erase_cfg)
{
    assert(EFLASH_baseIsValid(base));

    // sector erase
    base->ERASE_CNT1b.TSEC_ERASE = p_erase_cfg->erase_sector_tERASE;   //32bit
    base->RCV_CNT1b.TRCV_SECER = p_erase_cfg->erase_sector_tRCV;       //16bit

    // chip erase
    base->ERASE_CNT2b.TCHIP_ERASE = p_erase_cfg->erase_chip_tERASE;   //32bit
    base->RCV_CNT2b.TRCV_CHIPER = p_erase_cfg->erase_chip_tRCV;       //32bit
}
 
 
/*!
 * \brief Static Function to Clear EFLASH Status Flags
 *
 * \details This function clears one or more status flags within the EFLASH module.
 * 
 * \param[in] base Pointer to the EFLASH peripheral base address.
 * \param[in] e_status A bitmask indicating which status flags to clear. 
 * 
 */
static void EFLASH_clearStatusFlag(EFLASH_Type *base, EFLASH_StatusFlag_t e_status)
{
    assert(EFLASH_baseIsValid(base));

    switch(e_status)
    {
        case kEFLASH_INTR_VREAD_OK:
            base->FLASH_INTR_ST_CLRb.VREAD_OK_CLR = 1;
            break;  
        case kEFLASH_INTR_AHB_W_LOCK_AREA:
            base->FLASH_INTR_ST_CLRb.AHB_W_LOCK_AREA_CLR = 1;
            break;    
        case kEFLASH_INTR_AXI_W_LOCK_AREA:
            base->FLASH_INTR_ST_CLRb.AXI_W_LOCK_AREA_CLR = 1;
            break;      
        case kEFLASH_INTR_AXI_WERR:
            base->FLASH_INTR_ST_CLRb.AXI_WERR_CLR = 1;
            break;      
        case kEFLASH_INTR_F_DONE:
            base->FLASH_INTR_ST_CLRb.F_DONE_CLR = 1;
            break;           
        case kEFLASH_ST_AXI_WERR_ADDR_CLR:
            base->FLASH_ST_CLRb.AXI_WERR_ADDR_CLR = 1;
            break;
        case kEFLASH_ST_WRITE_CNT_CLR:
            base->FLASH_ST_CLRb.WRITE_CNT_CLR = 1;
            break;
        default:
            assert(false);
            break;
    }
}

/*!
 * \brief Select the Operation Target within the EFLASH Module
 *
 * \details This function designates the target area within the 
 *          EFLASH for upcoming read, write, or erase operations. 
 *
 * \param[in] base Pointer to the EFLASH peripheral base address.
 * \param[in] e_op_type A parameter that specifies the target area. 
 */
static void EFLASH_selectOperateTarget(EFLASH_Type *base, EFLASH_Operate_t e_op_type)
{
    assert(EFLASH_baseIsValid(base));
    assert(e_op_type < kEFLASH_OPERATE_MAX_INDEX);

    switch (e_op_type)
    {
        case kEFLASH_MAIN_ARRAR_SECTOR:
            base->CFGb.NVR = 0;
            base->CFGb.NVR_CFG = 0;

            base->RR0_CFGb.RR0_EN = 0;
            base->RR1_CFGb.RR1_EN = 0;
            break;
        case kEFLASH_NVR_SECTOR:
            base->CFGb.NVR = 1;
            base->CFGb.NVR_CFG = 0;

            base->RR0_CFGb.RR0_EN = 0;
            base->RR1_CFGb.RR1_EN = 0;
            break;      
        case kEFLASH_NVR_CFG_SECTOR:
            base->CFGb.NVR = 0;
            base->CFGb.NVR_CFG = 1;

            base->RR0_CFGb.RR0_EN = 0;
            base->RR1_CFGb.RR1_EN = 0;
            break; 
        case kEFLASH_RDN_SECTOR0:
            base->CFGb.NVR = 0;
            base->CFGb.NVR_CFG = 0;
            
            base->RR0_CFGb.RR0_EN = 1;
            base->RR1_CFGb.RR1_EN = 0;
            break;        
        case kEFLASH_RDN_SECTOR1:
            base->CFGb.NVR = 0;
            base->CFGb.NVR_CFG = 0;
            
            base->RR0_CFGb.RR0_EN = 0;
            base->RR1_CFGb.RR1_EN = 1;
            break;
        default:
            assert(false);
            break;
    }
}

/*!
 * \brief Select the Type of Chip Erase Operation for the EFLASH Module
 *
 * \details This function configures the mode of chip erase operation for the EFLASH. 
 *
 * \param[in] base Pointer to the EFLASH peripheral base address.
 * \param[in] eraseType An enumeration or a set of bits that define the type of chip erase to be performed. 
 */
static void EFLASH_selectChipEraseType(EFLASH_Type *base, EFLASH_EraseType_t eraseType)
{
    assert(EFLASH_baseIsValid(base));
    assert(eraseType < (EFLASH_EraseType_t)kEFLASH_OPERATE_MAX_INDEX);

    switch (eraseType)
    {
        case kEFLASH_MAIN_ARRAY:
            base->CFGb.NVR = 0;
            base->CFGb.NVR_CFG = 0;

            base->RR0_CFGb.RR0_EN = 0;
            base->RR1_CFGb.RR1_EN = 0;
            break;
        case kEFLASH_MAIN_AND_RDN:
            base->CFGb.NVR = 0;
            base->CFGb.NVR_CFG = 0;

            base->RR0_CFGb.RR0_EN = 1;
            base->RR1_CFGb.RR1_EN = 1;
            break;
        case kEFLASH_MAIN_NVR_RDN:
            base->CFGb.NVR = 1;
            base->CFGb.NVR_CFG = 0;

            base->RR0_CFGb.RR0_EN = 1;
            base->RR1_CFGb.RR1_EN = 1;
            break;
        default:
            assert(false);
            break;
    }
}

/*!
 * \brief Retrieve the Address of the Non-Volatile Configuration (NVR) within the EFLASH Module
 *
 * \details This function returns the memory address where the Non-Volatile Configuration (NVR) data.
 *
 * \param[in] opAddress  EFLASH operation address.
 *
 * \return The function returns the memory address of the Non-Volatile Configuration within the EFLASH.
 */
static uint32_t EFLASH_getNVRCfgAddress(volatile uint32_t opAddress)
{
    uint32_t vReturnAddress = 0;

    if (((opAddress >> 7) & 0x03) == 0x03)
    {
        // bit 8  bit 7 : 1 1  --> 1 0
        vReturnAddress = opAddress & (~(1 << 7));
    }
    else if (((opAddress >> 7) & 0x03) == 0x02)
    {
        // bit 8  bit 7 : 1 0  --> 1 1
        vReturnAddress = opAddress | (1 << 7);
    }
    else if (((opAddress >> 7) & 0x03) == 0x01)
    {
        // bit 8  bit 7 : 0 1  --> 0 0
        vReturnAddress = opAddress & (~(1 << 7));
    }
    else if (((opAddress >> 7) & 0x03) == 0x00)
    {
        // bit 8  bit 7 : 0 0  --> 0 1
        vReturnAddress = opAddress | ((1 << 7));
    }

    return vReturnAddress;
} 

/*!
 * \brief Write Data to a Row in the Non-Volatile Configuration (NVR) of the EFLASH Module
 *
 * \details This function writes a sequence of words to a specified row within the Non-Volatile 
 * Configuration (NVR) area in the EFLASH module. The operation type specifies whether it's a program or erase operation.
 *
 * \param[in] base Pointer to the EFLASH peripheral base address.
 * \param[in] e_op_type Operation type, indicating whether the action is a program or erase operation (\ref EFLASH_Operate_t).
 * \param[in] p_write_buff Pointer to the buffer containing the data to be written.
 * \param[in] write_address The starting address within the NVR where the data should be written.
 * \param[in] lens The number of words to be written from the buffer.
 */
static void EFLASH_writeNVRCfgRowWords(EFLASH_Type *base, EFLASH_Operate_t e_op_type, uint32_t *p_write_buff,
                                       volatile uint32_t write_address, uint32_t lens)
{
    uint32_t temp, remain_lens,offset;
    
    assert(EFLASH_baseIsValid(base));
 
    remain_lens = lens % 2;
    lens = lens / 2;

    //odd and evn lines must be consistent
    assert(lens < (128 * 2));
    
    for (temp = 0; temp < lens; temp++)
    {
        /* choose operate type*/ 
        EFLASH_selectOperateTarget(base, e_op_type);
 
        /* write key */
        EFLASH_setKeyValue(base, kEFLASH_AHB_WRITE_KEY);

        /* cfg write mode*/
        EFLASH_configMode(base, kEFLASH_WRITE_MODE);
        
        /* set op address, for odd or evn */
         EFLASH_setOperateAddress(base, EFLASH_getNVRCfgAddress(write_address + temp));
    
        /* write data */
         offset = temp * 2;
        
        base->WR_DATA2b.WR_DATA_L =  p_write_buff[offset];
        base->WR_DATA1b.WR_DATA_H =  p_write_buff[offset + 1];

        /* enable mode*/
        EFLASH_enableConfigMode(base, kEFLASH_MODE_ENABLE);
    
        /* check done */
        while(!EFLASH_operateIsDone(base));
    
        /* clear done */
        EFLASH_clearStatusFlag(base, kEFLASH_INTR_F_DONE);
    }
    if (remain_lens != 0)
    {
        /* choose operate type*/ 
        EFLASH_selectOperateTarget(base, e_op_type);
 
        /* write key */
        EFLASH_setKeyValue(base, kEFLASH_AHB_WRITE_KEY);

        /* cfg write mode*/
        EFLASH_configMode(base, kEFLASH_WRITE_MODE);
        
        /* set op address, for odd or evn */
         EFLASH_setOperateAddress(base, EFLASH_getNVRCfgAddress(write_address + temp));
    
        /* write data */
        offset = temp * 2;
        base->WR_DATA2b.WR_DATA_L =  p_write_buff[offset];
        base->WR_DATA1b.WR_DATA_H =  HAL_EFLASH_32BIT_MASK;
        
        /* enable mode*/
        EFLASH_enableConfigMode(base, kEFLASH_MODE_ENABLE);
    
        /* check done */
        while(!EFLASH_operateIsDone(base));
    
        /* clear done */
        EFLASH_clearStatusFlag(base, kEFLASH_INTR_F_DONE);
    }
}

/*!
 * \brief Write Data to a Row in the Non-Volatile Configuration (NVR) of the EFLASH Module Using Double Words
 *
 * \details This function writes a sequence of double words (64-bit) to a specified row within the 
 * Non-Volatile Configuration (NVR) area of the EFLASH module. It supports both program and erase operations based on the 
 * provided operation type.
 *
 * \param[in] base Pointer to the EFLASH peripheral base address.
 * \param[in] e_op_type Operation type specifying whether the action is a program or erase operation (\ref EFLASH_Operate_t).
 * \param[in] p_write_buff Pointer to the buffer containing the double words to be written.
 * \param[in] write_address The starting address within the NVR where the data should be written.
 * \param[in] lens The number of double words to be written from the buffer.
 */
static void EFLASH_writeNVRCfgRowDwords(EFLASH_Type *base, EFLASH_Operate_t e_op_type, uint64_t *p_write_buff,
                                        volatile uint32_t write_address, uint32_t lens)
{
    uint32_t temp;
    
    assert(EFLASH_baseIsValid(base));
    //odd and evn lines must be consistent
    assert(lens < 128);
    
    for (temp = 0; temp < lens; temp++)
    {
        /* choose operate type*/ 
        EFLASH_selectOperateTarget(base, e_op_type);

        /* write key */
        EFLASH_setKeyValue(base, kEFLASH_AHB_WRITE_KEY);

        /* cfg write mode*/
        EFLASH_configMode(base, kEFLASH_WRITE_MODE);

        /* set op address, for odd or evn */
         EFLASH_setOperateAddress(base, EFLASH_getNVRCfgAddress(write_address + temp));
    
        /* write data */
         EFLASH_writeData(base, p_write_buff[temp]);
                 
        /* enable mode*/
        EFLASH_enableConfigMode(base, kEFLASH_MODE_ENABLE);
    
        /* check done */
        while(!EFLASH_operateIsDone(base));
    
        /* clear done */
        EFLASH_clearStatusFlag(base, kEFLASH_INTR_F_DONE);
    }
} 

/*!
 * \brief Write Data to a Row in the Non-Volatile Configuration (NVR) of the EFLASH Module Using Bytes
 *
 * \details This function writes a sequence of bytes to a specified row within the Non-Volatile 
 * Configuration (NVR) area of the EFLASH module. It accommodates both program and erase operations according to the 
 * specified operation type.
 *
 * \param[in] base Pointer to the EFLASH peripheral base address.
 * \param[in] e_op_type Operation type indicating whether the action is a program or erase operation (\ref EFLASH_Operate_t).
 * \param[in] p_write_buff Pointer to the buffer containing the bytes to be written.
 * \param[in] write_address The starting byte address within the NVR where data should be written.
 * \param[in] lens The number of bytes to be written from the buffer.
 */
static void EFLASH_writeNVRCfgRowBytes(EFLASH_Type *base, EFLASH_Operate_t e_op_type,
                                        uint8_t *p_write_buff, volatile uint32_t write_address,
                                        uint32_t lens)
{
    uint32_t temp, offset, remain_lens;
    
    assert(EFLASH_baseIsValid(base));

    remain_lens = lens % 8;
    lens = lens / 8;

    //odd and evn lines must be consistent
    assert(lens < (128 * 8));
    
    for (temp = 0; temp < lens; temp++)
    {
        /* choose operate type */ 
        EFLASH_selectOperateTarget(base, e_op_type);

        /* write key */
        EFLASH_setKeyValue(base, kEFLASH_AHB_WRITE_KEY);

        /* cfg write mode */
        EFLASH_configMode(base, kEFLASH_WRITE_MODE);

        /* set op address, for odd or evn */
        EFLASH_setOperateAddress(base, EFLASH_getNVRCfgAddress(write_address + temp));
    
        /* write data */
        offset = temp * 8;
        base->WR_DATA2b.WR_DATA_L =  ((((uint32_t)p_write_buff[offset]) & 0xFF)             \
                                                    |((((uint32_t)p_write_buff[offset + 1]) & 0xFF) << 8)            \
                                                        |((((uint32_t)p_write_buff[offset + 2]) & 0xFF) << 16)            \
                                                            |((((uint32_t)p_write_buff[offset + 3]) & 0xFF) << 24));     
        

        base->WR_DATA1b.WR_DATA_H =  ((((uint32_t)p_write_buff[offset + 4]) & 0xFF)             \
                                                    |((((uint32_t)p_write_buff[offset + 5]) & 0xFF) << 8)            \
                                                        |((((uint32_t)p_write_buff[offset + 6]) & 0xFF) << 16)            \
                                                            |((((uint32_t)p_write_buff[offset + 7]) & 0xFF) << 24));     
        /* enable mode*/
        EFLASH_enableConfigMode(base, kEFLASH_MODE_ENABLE);
    
        /* check done */
        while(!EFLASH_operateIsDone(base));
    
        /* clear done */
        EFLASH_clearStatusFlag(base, kEFLASH_INTR_F_DONE);
    }
    if (remain_lens != 0)
    {
        /* choose operate type*/ 
        EFLASH_selectOperateTarget(base, e_op_type);

        /* write key */
        EFLASH_setKeyValue(base, kEFLASH_AHB_WRITE_KEY);
        
        /* cfg write mode*/
        EFLASH_configMode(base, kEFLASH_WRITE_MODE);

        /* set op address, for odd or evn */
        EFLASH_setOperateAddress(base, EFLASH_getNVRCfgAddress(write_address + temp));
    
        /* write data */
        offset = temp * 8;
        switch (remain_lens)
        {
            case 1:
                base->WR_DATA2b.WR_DATA_L =  ((((uint32_t)p_write_buff[offset]) & 0xFF)| 0xFFFFFF00);     
                base->WR_DATA1b.WR_DATA_H = HAL_EFLASH_32BIT_MASK;
                break;
            case 2:
                base->WR_DATA2b.WR_DATA_L =  ((((uint32_t)p_write_buff[offset]) & 0xFF)             \
                                                            |((((uint32_t)p_write_buff[offset + 1]) & 0xFF) << 8)            \
                                                                | 0xFFFF0000);
                base->WR_DATA1b.WR_DATA_H =  HAL_EFLASH_32BIT_MASK;
                break;
            case 3:
                base->WR_DATA2b.WR_DATA_L =  ((((uint32_t)p_write_buff[offset]) & 0xFF)             \
                                                            |((((uint32_t)p_write_buff[offset + 1]) & 0xFF) << 8)            \
                                                                |((((uint32_t)p_write_buff[offset + 2]) & 0xFF) << 16)            \
                                                                    |0xFF000000);     
                base->WR_DATA1b.WR_DATA_H =  HAL_EFLASH_32BIT_MASK;
                break;
            case 4:
                base->WR_DATA2b.WR_DATA_L =  ((((uint32_t)p_write_buff[offset]) & 0xFF)             \
                                                            |((((uint32_t)p_write_buff[offset + 1]) & 0xFF) << 8)            \
                                                                |((((uint32_t)p_write_buff[offset + 2]) & 0xFF) << 16)            \
                                                                    |((((uint32_t)p_write_buff[offset + 3]) & 0xFF) << 24));     
                base->WR_DATA1b.WR_DATA_H =  HAL_EFLASH_32BIT_MASK;
                break;
            case 5:
                base->WR_DATA2b.WR_DATA_L =  ((((uint32_t)p_write_buff[offset]) & 0xFF)             \
                                                            |((((uint32_t)p_write_buff[offset + 1]) & 0xFF) << 8)            \
                                                                |((((uint32_t)p_write_buff[offset + 2]) & 0xFF) << 16)            \
                                                                    |((((uint32_t)p_write_buff[offset + 3]) & 0xFF) << 24));     
                base->WR_DATA1b.WR_DATA_H =  ((((uint32_t)p_write_buff[offset + 4]) & 0xFF)  | 0xFFFFFF00);     
                break;
            case 6:
                base->WR_DATA2b.WR_DATA_L =  ((((uint32_t)p_write_buff[offset]) & 0xFF)             \
                                                            |((((uint32_t)p_write_buff[offset + 1]) & 0xFF) << 8)            \
                                                                |((((uint32_t)p_write_buff[offset + 2]) & 0xFF) << 16)            \
                                                                    |((((uint32_t)p_write_buff[offset + 3]) & 0xFF) << 24));     
                base->WR_DATA1b.WR_DATA_H =  ((((uint32_t)p_write_buff[offset + 4]) & 0xFF)             \
                                                            |((((uint32_t)p_write_buff[offset + 5]) & 0xFF) << 8)            \
                                                                | 0xFFFF0000);     
                break;
            case 7:
                base->WR_DATA2b.WR_DATA_L =  ((((uint32_t)p_write_buff[offset]) & 0xFF)             \
                                                            |((((uint32_t)p_write_buff[offset + 1]) & 0xFF) << 8)            \
                                                                |((((uint32_t)p_write_buff[offset + 2]) & 0xFF) << 16)            \
                                                                    |((((uint32_t)p_write_buff[offset + 3]) & 0xFF) << 24));     
                base->WR_DATA1b.WR_DATA_H =  ((((uint32_t)p_write_buff[offset + 4]) & 0xFF)             \
                                                            |((((uint32_t)p_write_buff[offset + 5]) & 0xFF) << 8)            \
                                                                |((((uint32_t)p_write_buff[offset + 6]) & 0xFF) << 16)            \
                                                                    |0xFF000000);     
                break;
            default:
                assert(false);
                break;
        } 
        /* enable mode*/
        EFLASH_enableConfigMode(base, kEFLASH_MODE_ENABLE);

        /* check done */
        while(!EFLASH_operateIsDone(base));
    
        /* clear done */
        EFLASH_clearStatusFlag(base, kEFLASH_INTR_F_DONE);
    }
}

/*!
 * \brief Check EFLASH Main Array Address Protection Status
 *
 * \details Determines whether the EFLASH main array is protected .
 *
 * \param[in] base Pointer to the EFLASH peripheral base address for accessing protection settings.
 * \param[in] e_op_type Enumerated value specifying the operation type (\ref EFLASH_Operate_t).
 * \param[in] check_address The address in the EFLASH main array to verify protection status.
 *
 * \return Returns true if the address is protected for the given operation, false otherwise.
 *
 * \note This function helps in avoiding attempts on protected memory areas.
 *
 * \warning Misinterpretation of the return value could lead to unauthorized access attempts or operation failures.
 */
static bool EFLASH_mainArrayAddressIsProtect(EFLASH_Type *base, EFLASH_Operate_t e_op_type,
                                                     uint32_t check_address)
{
    uint32_t start_address, end_address;
    
    assert(EFLASH_baseIsValid(base));

    if (e_op_type != kEFLASH_MAIN_ARRAR_SECTOR)
    {
        return false;
    }

    if (base->PROTECT_ENb.LOCK_EN)
    {
        start_address = base->PROTECT_STARTb.LOCK_BEG_ADDR;
        end_address = base->PROTECT_ENDb.LOCK_END_ADDR;
        
        if ((check_address >= start_address) && (check_address <= end_address))
        {
            return true;
        }
    }
    
    return false;
}

void EFLASH_enableNVICInterrupe(EFLASH_Type *base)
{
    assert(EFLASH_baseIsValid(base));

    NVIC_EnableIRQ(EFLASH_IRQn);
}

/*!
 * @fn      EFLASH_setInterruptPriority
 *
 * @brief   EFLASH_setInterruptPriority
 *
 * @param  base ： EFLASH0  , EFLASH1
 *         
 * @return  none
 *
 */
void EFLASH_setInterruptPriority(EFLASH_Type *base, uint32_t preempt_priority, uint32_t sub_priority)
{
    assert(EFLASH_baseIsValid(base));

    NVIC_SetPriority(EFLASH_IRQn, preempt_priority);
}

/*!
 * @fn      EFLASH_intFlagCheck
 *
 * @brief   EFLASH_intFlagCheck
 *
 * @param  base ： EFLASH0  , EFLASH1
 *         
 * @return  none
 *
 */
void EFLASH_intFlagCheck(EFLASH_Type *base)
{
    assert(EFLASH_baseIsValid(base));

    if (HAL_EFLASH_CHECK_IT_FLAG(base->FLASH_INTR_STb.AHB_W_LOCK_AREA, base->FLASH_INTR_ENb.AHB_W_LOCK_AREA_IE))
    {
        EFLASH_clearStatusFlag(base, kEFLASH_INTR_AHB_W_LOCK_AREA);
    }

    if (HAL_EFLASH_CHECK_IT_FLAG(base->FLASH_INTR_STb.AXI_W_LOCK_AREA, base->FLASH_INTR_ENb.AXI_W_LOCK_AREA_IE))
    {
        EFLASH_clearStatusFlag(base, kEFLASH_INTR_AXI_W_LOCK_AREA);
    }

    if (HAL_EFLASH_CHECK_IT_FLAG(base->FLASH_INTR_STb.AXI_WERR, base->FLASH_INTR_ENb.AXI_WERR_IE))
    {
        EFLASH_clearStatusFlag(base, kEFLASH_INTR_AXI_WERR);
    }

    if (HAL_EFLASH_CHECK_IT_FLAG(base->FLASH_INTR_STb.F_DONE, base->FLASH_INTR_ENb.F_DONE_IE))
    {
        EFLASH_clearStatusFlag(base, kEFLASH_INTR_F_DONE);
    }
}

/*!
 * @fn      EFLASH_configInit
 *
 * @brief   init flash
 *
 * @param  none
 *
 * @return  None
 *
 */
void EFLASH_configInit(EFLASH_Type *base, EFLASH_Timing_t *p_eflash_init_cfg)
{
    assert(EFLASH_baseIsValid(base));
    
    // cfg timing     
    EFLASH_timeForPORInit(base, &p_eflash_init_cfg->por_cfg);
    EFLASH_timeForLvctlInit(base, &p_eflash_init_cfg->lvctl_cfg);
    EFLASH_timeForProgramInit(base, &p_eflash_init_cfg->prog_cfg);
    EFLASH_timeForEraseInit(base, &p_eflash_init_cfg->erase_cfg);
    EFLASH_timeForSetCfgRegInit(base, &p_eflash_init_cfg->set_reg_cfg);
}

/*
 * @fn      EFLASH_configInit_10M
 *
 * @brief   init flash: systerm clock 10MHz , eflash clock 5MHz
 *
 * @param  none
 *
 * @return  None
 *
 */
void EFLASH_initClock5MHz(EFLASH_Type *base)
{
    EFLASH_Timing_t p_eflash_init_cfg;
    assert(EFLASH_baseIsValid(base));

    //  1 clock = 200ns

    //por
    p_eflash_init_cfg.por_cfg.pown_on_tRHR = 300;    //5us
    p_eflash_init_cfg.por_cfg.pown_on_tRT = 30;      // 500ns
    p_eflash_init_cfg.por_cfg.pown_on_tDPDSR =  6;   // 100ns
    p_eflash_init_cfg.por_cfg.pown_on_tDPDH = 300;   //5us

    //lvctl
    p_eflash_init_cfg.lvctl_cfg.lvctl_tCRC = 1;     // 8ns
    p_eflash_init_cfg.lvctl_cfg.lvctl_tACC = 3;     // 50ns

    //prog
    p_eflash_init_cfg.prog_cfg.prog_tPROG = 45;    //8~10us
    p_eflash_init_cfg.prog_cfg.prog_tPGS = 40 + 2;    //8us  
    p_eflash_init_cfg.prog_cfg.prog_tADS = 1;      //15ns
    p_eflash_init_cfg.prog_cfg.prog_tADH = 1;      //15ns
    p_eflash_init_cfg.prog_cfg.prog_tPGH = 1;      //15ns  
    p_eflash_init_cfg.prog_cfg.prog_tNVS = 240;     //4us 
    p_eflash_init_cfg.prog_cfg.prog_tWSH = 1;      //5ns  
    p_eflash_init_cfg.prog_cfg.prog_tACC = 3;     //25ns
    p_eflash_init_cfg.prog_cfg.prog_tRW = 6;       //100ns  
    p_eflash_init_cfg.prog_cfg.prog_tRCV = 25 + 2;     //5us

    p_eflash_init_cfg.erase_cfg.erase_sector_tERASE = 45000;    //8~10ms
    p_eflash_init_cfg.erase_cfg.erase_sector_tRCV = 250 + 2;      //50us  
    p_eflash_init_cfg.erase_cfg.erase_chip_tERASE = 45000;      //8~10ms
    p_eflash_init_cfg.erase_cfg.erase_chip_tRCV = 1000 + 2;        //200us

    p_eflash_init_cfg.set_reg_cfg.nvr_cfg_tACC_NVR = 12 + 2;       //200ns
    p_eflash_init_cfg.set_reg_cfg.nvr_cfg_tMS = 300 + 2;            //5us
    p_eflash_init_cfg.set_reg_cfg.set_cfg_reg_tCFH = 2;        //30ns
    p_eflash_init_cfg.set_reg_cfg.set_cfg_reg_tCFL = 300;        //5us
    p_eflash_init_cfg.set_reg_cfg.set_cfg_reg_tCONFEN = 1;      //15ns

    // cfg timing     
    EFLASH_timeForPORInit(base, &p_eflash_init_cfg.por_cfg);
    EFLASH_timeForLvctlInit(base, &p_eflash_init_cfg.lvctl_cfg);
    //EFLASH_timeForProgramInit(base, &p_eflash_init_cfg.prog_cfg);
    EFLASH_timeForEraseInit(base, &p_eflash_init_cfg.erase_cfg);
    EFLASH_timeForSetCfgRegInit(base, &p_eflash_init_cfg.set_reg_cfg);
}

/*!
 * @fn      EFLASH_initClock
 *
 * @brief   EFLASH_initClock
 *
 * @param  base ： EFLASH0  , EFLASH1
 *         
 * @return  None
 *
 */
void EFLASH_initClock(EFLASH_Type *base, uint32_t pllclk)
{   
    uint32_t us = pllclk / 1000000;
    uint32_t ms = pllclk / 1000;
    uint16_t ns = 1000000000 / pllclk;
    
    base->POR_CNTb.TRHR = 5 * us;            //5us
    base->POR_CNTb.TRT = (uint32_t)(EFLASH_getSecCounter(500, ns));     // 500ns
    base->DPD_CNTb.TDPDSR =  (uint32_t)(EFLASH_getSecCounter(100, ns));   // 100ns
    base->DPD_CNTb.TDPDH = 5 * us;   //5us

    //lvctl
    base->LVCTL_CNTb.TCRC_LVCTL = (uint32_t)(EFLASH_getSecCounter(8, ns));     // 8ns 1
    base->LVCTL_CNTb.TACC_LVCTL = (uint32_t)(EFLASH_getSecCounter(50, ns) + 2);     // 50ns 0x78

    //prog
    base->PROG_CNT1b.TPROG = 9 * us;    //8~10us
    base->PROG_CNT1b.TPGS = 8 * us;    //8us  
    base->PROG_CNT2b.TADS = (uint32_t)(EFLASH_getSecCounter(15, ns));      //15ns
    base->PROG_CNT2b.TADH = (uint32_t)(EFLASH_getSecCounter(15, ns));      //15ns
    base->PROG_CNT2b.TPGH = (uint32_t)(EFLASH_getSecCounter(15, ns));      //15ns  
    base->PROG_CNT3b.TNVS = 4 * us;     //4us 
    base->PROG_CNT4b.TWS = (uint32_t)(EFLASH_getSecCounter(5, ns));      //5ns  
    base->PROG_CNT4b.TACC = (uint32_t)(EFLASH_getSecCounter(25, ns) + 2);     //25ns 3
    base->PROG_CNT4b.TRW = (uint32_t)(EFLASH_getSecCounter(100, ns));       //100ns  
    base->RCV_CNT1b.TRCV_PROG = 5 * us;     //5us

    base->ERASE_CNT1b.TSEC_ERASE = 9 * ms;    //8~10ms
    base->RCV_CNT1b.TRCV_SECER = 50 * us;      //50us  
    base->ERASE_CNT2b.TCHIP_ERASE = 9 * ms;      //8~10ms
    base->RCV_CNT2b.TRCV_CHIPER = 200 * us;        //200us

    base->NVR_CFGb.TACC_NVR = (uint32_t)(EFLASH_getSecCounter(200, ns) + 2);       //200ns 0x1f
    base->NVR_CFGb.TMS = 5 * us + 0x11;            //5us 0x343
    base->SET_CFG1b.TCFH = (uint32_t)(EFLASH_getSecCounter(30, ns));        //30ns
    base->SET_CFG1b.TCFL = 5 * us;        //5us
    base->SET_CFG2b.TCONFEN = (uint32_t)(EFLASH_getSecCounter(15, ns));      //15ns   
}

/*!
 * @fn      EFLASH_getCurrentState
 *
 * @brief   get_current_states
 *
 * @param  base ： EFLASH0  , EFLASH1
 *         
 * @return  EFLASH_Status_t
 *
 */
EFLASH_Status_t EFLASH_getCurrentState(EFLASH_Type *base)
{
    assert(EFLASH_baseIsValid(base));

    return (EFLASH_Status_t)base->FLASH_FSMb.C_STATE;
}

/*!
 * @fn      EFLASH_softwareReset
 *
 * @brief   software_reset
 *
 * @param  base ： EFLASH0  , EFLASH1
 *         
 * @return  none
 *
 */
void EFLASH_softwareReset(EFLASH_Type *base)
{
    assert(EFLASH_baseIsValid(base));

    /* cfg SW reset mode */
    EFLASH_configMode(base, kEFLASH_SW_RESET_MODE);

    /* enable mode */
    EFLASH_enableConfigMode(base, kEFLASH_MODE_ENABLE);

    while(!EFLASH_operateIsDone(base));
        
    EFLASH_clearStatusFlag(base, kEFLASH_INTR_F_DONE);
}

/*!
 * @fn      EFLASH_generateAddress
 *
 * @brief   generate_address
 *
 * @param  base ： EFLASH0  , EFLASH1
 *         e_op_type:    EFLASH_MAIN_ARRAR  = 0,
                       kEFLASH_NVR_SECTOR  = 1,
                       kEFLASH_NVR_CFG_SECTOR  = 2,
                       EFLASH_NVR_RDN0  = 3,
                       EFLASH_NVR_RDN1  = 4,
 *         sector_num : Sector Num
 *         row_num : Row Num
 *         word_num : Word Num
 * @return  none
 *
 */
uint32_t EFLASH_generateAddress(EFLASH_Type *base, EFLASH_Operate_t eType, uint16_t sector_num, uint8_t row_num,
                                uint8_t word_num)
{
    assert(EFLASH_baseIsValid(base));
    assert(row_num < 3);
    assert(word_num < 128);
    
    uint32_t address = 0;
    
    switch (eType)
    {
        case kEFLASH_MAIN_ARRAR_SECTOR:
            assert(sector_num < 255);
            
            address = (sector_num << 9) | (row_num << 7) | (word_num);
            break;
        
        case kEFLASH_NVR_SECTOR:
            assert(sector_num < 15);

            if (sector_num > 7)
            {
                address = (1 << 16) | (sector_num << 9) | (row_num << 7) | (word_num);
            }
            else
            {
                address = (sector_num << 9) | (row_num << 7) | (word_num);
            }

            address = address & (0x010FFF);
            break;

        case kEFLASH_NVR_CFG_SECTOR:
            assert(sector_num < 1);
            
            address = (row_num << 7) | (word_num);
            break;

        case kEFLASH_RDN_SECTOR0:
        case kEFLASH_RDN_SECTOR1:
            assert(sector_num < 2);
            
            address = (row_num << 7) | (word_num);
            break;

        default:
            assert(false);
            break;
    }

    return (address & 0x01FFFF);
}

/*!
 * @fn      EFLASH_enableInterrupt
 *
 * @brief   EFLASH_enableInterrupt
 *
 * @param  base ： EFLASH0  , EFLASH1
 *         intType:        kEFLASH_INT_AHB_WRITE_LOCK = 0,
                            kEFLASH_INT_AXI_WRITE_LOCK = 1,
                            kEFLASH_INT_AXI_WRITE_ERROR = 2,
                            kEFLASH_INT_FLASH_DONE = 3,
 * @return  none
 *
 */
void EFLASH_enableInterrupt(EFLASH_Type *base, EFLASH_InterruptType_t intType)
{
    assert(EFLASH_baseIsValid(base));
    assert(intType < kEFLASH_INT_MAX_INDEX);

    switch (intType)
    {
         case kEFLASH_INT_AHB_WRITE_LOCK:
            base->FLASH_INTR_ENb.AHB_W_LOCK_AREA_IE = 1;
            break;

         case kEFLASH_INT_AXI_WRITE_LOCK:
            base->FLASH_INTR_ENb.AXI_W_LOCK_AREA_IE = 1;
            break;

         case kEFLASH_INT_AXI_WRITE_ERROR:
            base->FLASH_INTR_ENb.AXI_WERR_IE = 1;
            break;

         case kEFLASH_INT_FLASH_DONE:
            base->FLASH_INTR_ENb.F_DONE_IE = 1;
            break;

         default:
             assert(false); 
            break;
    }
}
 
/*!
 * @fn      EFLASH_ahbReadBytes
 *
 * @brief   EFLASH_ahbReadBytes
 *
 * @param  base ： EFLASH0  , EFLASH1
 *         e_op_type:    EFLASH_MAIN_ARRAR  = 0,
                       kEFLASH_NVR_SECTOR  = 1,
                       kEFLASH_NVR_CFG_SECTOR  = 2,
                       EFLASH_NVR_RDN0  = 3,
                       EFLASH_NVR_RDN1  = 4,
 *         p_read_buff : bit8 
 *         read_address : address  (0 ~ (0x100000 / 8))
 *         lens : (8bit * lens)
 * @return  none
 *
 */
void EFLASH_ahbReadBytes(EFLASH_Type *base, EFLASH_Operate_t e_op_type, uint8_t *p_read_buff,
                         volatile uint32_t read_address, uint32_t lens)
{
    uint8_t remain_lens, byte_remain;
    uint32_t temp, offset;
    assert(EFLASH_baseIsValid(base));

    EFLASH_enableRecallMode(base, e_op_type);
    EFLASH_setExecutePriority(base, kEFLASH_EXECUTE_AHB_FIRST);

    remain_lens = lens % 8;
    for (temp = 0; temp < (lens/8); temp++)
    {
        /* choose operate type*/ 
        EFLASH_selectOperateTarget(base, e_op_type);

        /* cfg read mode*/
        EFLASH_configMode(base, kEFLASH_READ_MODE);

        /* set address*/
        EFLASH_setOperateAddress(base, read_address + temp);

        /* enable mode*/
        EFLASH_enableConfigMode(base, kEFLASH_MODE_ENABLE);

        /* check done */
        while(!EFLASH_operateIsDone(base));

        /* read data*/
        offset = temp * 8;
        for (byte_remain = 0; byte_remain < 8; byte_remain++)
        {
            p_read_buff[offset + byte_remain] = (uint8_t)((EFLASH_readDword(base) >> (8 * byte_remain)) & 0xFF);
        }

        /* clear done */
        EFLASH_clearStatusFlag(base, kEFLASH_INTR_F_DONE);
    }
    if (remain_lens != 0)
    {
        /* check ready*/
        while(!EFLASH_statusIsReady(base));
        
        /* choose operate type*/ 
        EFLASH_selectOperateTarget(base, e_op_type);
        
        /* cfg read mode*/
        EFLASH_configMode(base, kEFLASH_READ_MODE);
        
        /* set address*/
        EFLASH_setOperateAddress(base, read_address + temp);
        
        /* enable mode*/
        EFLASH_enableConfigMode(base, kEFLASH_MODE_ENABLE);
        
        /* check done */
        while(!EFLASH_operateIsDone(base));
        
        /* read data*/
        offset = temp * 8;
        for (byte_remain = 0; byte_remain < remain_lens; byte_remain++)
        {
            p_read_buff[offset + byte_remain] = (uint8_t)((EFLASH_readDword(base) >> (8 * byte_remain)) & 0xFF);
        }

        /* clear done */
        EFLASH_clearStatusFlag(base, kEFLASH_INTR_F_DONE);

    }
    EFLASH_setExecutePriority(base, kEFLASH_EXECUTE_AXI_FIRST);

    EFLASH_disableRecallMode(base);
}

/*!
 * @fn      EFLASH_ahbReadWords
 *
 * @brief   EFLASH_ahbReadWords
 *
 * @param  base ： EFLASH0  , EFLASH1
 *         e_op_type:    EFLASH_MAIN_ARRAR  = 0,
                       kEFLASH_NVR_SECTOR  = 1,
                       kEFLASH_NVR_CFG_SECTOR  = 2,
                       EFLASH_NVR_RDN0  = 3,
                       EFLASH_NVR_RDN1  = 4,
 *         p_read_buff : bit32 
 *         read_address : address  (0 ~ (0x100000 / 8))
 *         lens : (32bit * lens)
 * @return  none
 *
 */
void EFLASH_ahbReadWords(EFLASH_Type *base, EFLASH_Operate_t e_op_type, uint32_t *p_read_buff,
                         volatile uint32_t read_address, uint32_t lens)
{
    uint8_t remain_lens;
    uint32_t temp, offset;

    assert(EFLASH_baseIsValid(base));

    EFLASH_setExecutePriority(base, kEFLASH_EXECUTE_AHB_FIRST);
    EFLASH_enableRecallMode(base, e_op_type);

    remain_lens = lens % 2;  
    for (temp = 0; temp < (lens/2); temp++)
    {
        /* choose operate type*/ 
        EFLASH_selectOperateTarget(base, e_op_type);

        /* cfg read mode*/
        EFLASH_configMode(base, kEFLASH_READ_MODE);

        /* set address*/
        EFLASH_setOperateAddress(base, read_address + temp);

        /* enable mode*/
        EFLASH_enableConfigMode(base, kEFLASH_MODE_ENABLE);

        /* check done */
        while(!EFLASH_operateIsDone(base));

        /* read data*/
        offset = temp * 2;
        p_read_buff[offset] = base->READ_OUTPUT_L ;
        p_read_buff[offset + 1] = base->READ_OUTPUT_H;

        /* clear done */
        EFLASH_clearStatusFlag(base, kEFLASH_INTR_F_DONE);
    }

    if (remain_lens != 0)
    {
        /* check ready*/
        while(!EFLASH_statusIsReady(base));
        
        /* choose operate type*/ 
        EFLASH_selectOperateTarget(base, e_op_type);
        
        /* cfg read mode*/
        EFLASH_configMode(base, kEFLASH_READ_MODE);
        
        /* set address*/
        EFLASH_setOperateAddress(base, read_address + temp);
        
        /* enable mode*/
        EFLASH_enableConfigMode(base, kEFLASH_MODE_ENABLE);
        
        /* check done */
        while(!EFLASH_operateIsDone(base));

        /* read data*/
        offset = temp * 2;
        p_read_buff[offset] = base->READ_OUTPUT_L;
        
        /* clear done */
        EFLASH_clearStatusFlag(base, kEFLASH_INTR_F_DONE);
    }
    EFLASH_setExecutePriority(base, kEFLASH_EXECUTE_AXI_FIRST);
    EFLASH_disableRecallMode(base);
}

/*!
 * @fn      EFLASH_ahbReadDwords
 *
 * @brief   EFLASH_ahbReadDwords
 *
 * @param  base ： EFLASH0  , EFLASH1
 *         e_op_type:    EFLASH_MAIN_ARRAR  = 0,
                       kEFLASH_NVR_SECTOR  = 1,
                       kEFLASH_NVR_CFG_SECTOR  = 2,
                       EFLASH_NVR_RDN0  = 3,
                       EFLASH_NVR_RDN1  = 4,
 *         p_read_buff : bit64 
 *         read_address : address (0 ~ (0x100000 / 8))
 *         lens : (64bit * lens)
 * @return  none
 *
 */
void EFLASH_ahbReadDwords(EFLASH_Type *base, EFLASH_Operate_t e_op_type, uint64_t *p_read_buff,
                          volatile uint32_t read_address, uint32_t lens)
{
    uint32_t temp;
    assert(EFLASH_baseIsValid(base));

    EFLASH_enableRecallMode(base, e_op_type);
    EFLASH_setExecutePriority(base, kEFLASH_EXECUTE_AHB_FIRST);

    for (temp = 0; temp < lens; temp++)
    {
        /* choose operate type*/ 
        EFLASH_selectOperateTarget(base, e_op_type);

        /* cfg read mode*/
        EFLASH_configMode(base, kEFLASH_READ_MODE);

        /* set address*/
        EFLASH_setOperateAddress(base, read_address + temp);

        /* enable mode*/
        EFLASH_enableConfigMode(base, kEFLASH_MODE_ENABLE);

        /* check done */
        while(!EFLASH_operateIsDone(base));

        /* read data*/
        p_read_buff[temp] = EFLASH_readDword(base);

        /* clear done */
        EFLASH_clearStatusFlag(base, kEFLASH_INTR_F_DONE);
    }
    EFLASH_setExecutePriority(base, kEFLASH_EXECUTE_AXI_FIRST);
    EFLASH_disableRecallMode(base);
}


/*!
 * @fn      EFLASH_eraseSector
 *
 * @brief   erase_sector
 *
 * @param  base ： EFLASH0  , EFLASH1
 *         e_op_type:    EFLASH_MAIN_ARRAR  = 0,
                       kEFLASH_NVR_SECTOR  = 1,
                       kEFLASH_NVR_CFG_SECTOR  = 2,
                       EFLASH_NVR_RDN0  = 3,
                       EFLASH_NVR_RDN1  = 4,
 *         erase_address : address (0 ~ (0x100000 / 8))
 * @return  TRUE：erase ok
 *
 */
bool EFLASH_eraseSector(EFLASH_Type *base, EFLASH_Operate_t e_op_type, uint32_t erase_address)
{
    assert(EFLASH_baseIsValid(base));

    if (kEFLASH_NVR_CFG_SECTOR == e_op_type)
    {
        EFLASH_setLockConfig(base, kEFLASH_MODE_DISABLE);
    }

    EFLASH_disableRecallMode(base);
    /* choose operate type*/ 
    EFLASH_selectOperateTarget(base, e_op_type);

    /* write key */
    EFLASH_setKeyValue(base, kEFLASH_ERASE_SECTOR_KEY);

    /* cfg erase sector mode*/
    EFLASH_configMode(base, kEFLASH_SECOR_ERASE_MODE);

    /* set erase addr*/
    EFLASH_setOperateAddress(base, erase_address);

    /* enable mode*/
    EFLASH_enableConfigMode(base, kEFLASH_MODE_ENABLE);

    while(!EFLASH_operateIsDone(base));       
    EFLASH_clearStatusFlag(base, kEFLASH_INTR_F_DONE);

    EFLASH_setLockConfig(base, kEFLASH_MODE_ENABLE);

    return true;
}

/*!
 * @fn      EFLASH_eraseChip
 *
 * @brief   EFLASH_eraseChip
 *
 * @param  base ： EFLASH0  , EFLASH1
 *         eraseType:        kEFLASH_MAIN_ARRAY  = 0,
 *                                    kEFLASH_MAIN_AND_RDN  = 1,
 *                                    kEFLASH_MAIN_NVR_RDN  = 2,
 * @return  none
 *
 */
void EFLASH_eraseChip(EFLASH_Type *base, EFLASH_EraseType_t eraseType)
{
    assert(EFLASH_baseIsValid(base));

    EFLASH_disableRecallMode(base);
    /* choose chip erase operate type*/ 
    EFLASH_selectChipEraseType(base, eraseType);

    /* write key */
    EFLASH_setKeyValue(base, kEFLASH_ERASE_CHIP_KEY);

    /* cfg erase chip mode*/
    EFLASH_configMode(base, kEFLASH_CHIP_ERASE_MODE);

    /* enable mode*/
    EFLASH_enableConfigMode(base, kEFLASH_MODE_ENABLE);
    while(!EFLASH_operateIsDone(base));
    
    EFLASH_clearStatusFlag(base, kEFLASH_INTR_F_DONE);
}

/*
 * @fn      EFLASH_vreadIsOk
 *
 * @brief   EFLASH_vreadIsOk
 *
 * @param  base ： EFLASH0  , EFLASH1
 *         e_op_type:    EFLASH_MAIN_ARRAR  = 0,
 *                       kEFLASH_NVR_SECTOR  = 1,
 *                       kEFLASH_NVR_CFG_SECTOR  = 2,
 *                       EFLASH_NVR_RDN0  = 3,
 *                       EFLASH_NVR_RDN1  = 4,
 *         vread_address : address (0 ~ (0x100000 / 8))
 * @return  none
 *
 */
bool EFLASH_vreadIsOk(EFLASH_Type *base, EFLASH_Operate_t e_op_type, uint32_t vread_address)
{
    bool b_vread_ok_flag;
    assert(EFLASH_baseIsValid(base));

    b_vread_ok_flag = false;
    /* choose operate type */ 
    EFLASH_selectOperateTarget(base, e_op_type);
    
    /* cfg erase sector mode */
    EFLASH_configMode(base, kEFLASH_VREAD_MODE);

    /* set op address */
    EFLASH_setOperateAddress(base, vread_address);

    /* enable mode */
    EFLASH_enableConfigMode(base, kEFLASH_MODE_ENABLE);

    /* wait cmd done */
    while(!EFLASH_operateIsDone(base));

    b_vread_ok_flag = base->FLASH_INTR_STb.VREAD_OK;
    
    EFLASH_clearStatusFlag(base, kEFLASH_INTR_F_DONE);
    EFLASH_clearStatusFlag(base, kEFLASH_INTR_VREAD_OK);

    return b_vread_ok_flag;
}
                                     
/*!
 * @fn      EFLASH_ahbWriteBytes
 *
 * @brief   write  (lens) bytes data
 *
 * @param  base ： EFLASH0  , EFLASH1
 *         e_op_type:    EFLASH_MAIN_ARRAR  = 0,
                       kEFLASH_NVR_SECTOR  = 1,
                       kEFLASH_NVR_CFG_SECTOR  = 2,
                       EFLASH_NVR_RDN0  = 3,
                       EFLASH_NVR_RDN1  = 4,
 *         p_write_buff : bit8 
 *         write_address : address (0 ~ (0x100000 / 8))
 *         lens : (8bit * lens)
 * @return  none
 *
 */
void EFLASH_ahbWriteBytes(EFLASH_Type *base, EFLASH_Operate_t e_op_type, uint8_t *p_write_buff,
                          volatile uint32_t write_address, uint32_t lens)
{
    uint8_t remain_lens = 0;
    uint32_t temp = 0, offset = 0;    
    
    assert(EFLASH_baseIsValid(base));

    EFLASH_disableRecallMode(base);
    EFLASH_setExecutePriority(base, kEFLASH_EXECUTE_AHB_FIRST);
    remain_lens = lens % 8;    

    if (kEFLASH_NVR_CFG_SECTOR == e_op_type)
    {
        EFLASH_setLockConfig(base, kEFLASH_MODE_DISABLE);
    }

    for (temp = 0; temp < (lens/8); temp++)
    {
        // check whether be protect
        if (EFLASH_mainArrayAddressIsProtect(base, e_op_type, write_address + temp))
        {
            continue;  //next write
        }
    
        /* choose operate type*/ 
        EFLASH_selectOperateTarget(base, e_op_type);

        /* write key */
        EFLASH_setKeyValue(base, kEFLASH_AHB_WRITE_KEY);

        /* cfg write mode */
        EFLASH_configMode(base, kEFLASH_WRITE_MODE);
        
        /* set op address */
        EFLASH_setOperateAddress(base, write_address + temp);

        /* write data */
        offset = temp * 8;
        base->WR_DATA2b.WR_DATA_L =  ((((uint32_t)p_write_buff[offset]) & 0xFF)             \
                                                    |((((uint32_t)p_write_buff[offset + 1]) & 0xFF) << 8)            \
                                                        |((((uint32_t)p_write_buff[offset + 2]) & 0xFF) << 16)            \
                                                            |((((uint32_t)p_write_buff[offset + 3]) & 0xFF) << 24));      
        base->WR_DATA1b.WR_DATA_H =  ((((uint32_t)p_write_buff[offset + 4]) & 0xFF)             \
                                                    |((((uint32_t)p_write_buff[offset + 5]) & 0xFF) << 8)            \
                                                        |((((uint32_t)p_write_buff[offset + 6]) & 0xFF) << 16)            \
                                                            |((((uint32_t)p_write_buff[offset + 7]) & 0xFF) << 24));     
        /* enable mode */
        EFLASH_enableConfigMode(base, kEFLASH_MODE_ENABLE);

        /* check done */
        while(!EFLASH_operateIsDone(base));

        /* clear done */
        EFLASH_clearStatusFlag(base, kEFLASH_INTR_F_DONE);
    }
    if (remain_lens != 0)
    {
        /* choose operate type */ 
        EFLASH_selectOperateTarget(base, e_op_type);

        /* write key */
        EFLASH_setKeyValue(base, kEFLASH_AHB_WRITE_KEY);

        /* cfg write mode */
        EFLASH_configMode(base, kEFLASH_WRITE_MODE);

        /* set op address, for odd or evn */
        EFLASH_setOperateAddress(base, write_address + temp);
    
        /* write data */
        offset = temp * 8;
        switch (remain_lens)
        {
            case 1:
                base->WR_DATA2b.WR_DATA_L =  ((((uint32_t)p_write_buff[offset]) & 0xFF)| 0xFFFFFF00);                     
                base->WR_DATA1b.WR_DATA_H = HAL_EFLASH_32BIT_MASK;
                break;                
            case 2:
                base->WR_DATA2b.WR_DATA_L =  ((((uint32_t)p_write_buff[offset]) & 0xFF)             \
                                                            |((((uint32_t)p_write_buff[offset + 1]) & 0xFF) << 8)            \
                                                                | 0xFFFF0000);              
                base->WR_DATA1b.WR_DATA_H =  HAL_EFLASH_32BIT_MASK;
                break;
            case 3:
                base->WR_DATA2b.WR_DATA_L =  ((((uint32_t)p_write_buff[offset]) & 0xFF)             \
                                                            |((((uint32_t)p_write_buff[offset + 1]) & 0xFF) << 8)            \
                                                                |((((uint32_t)p_write_buff[offset + 2]) & 0xFF) << 16)            \
                                                                    |0xFF000000);     
                base->WR_DATA1b.WR_DATA_H =  HAL_EFLASH_32BIT_MASK;
                break;
            case 4:
                base->WR_DATA2b.WR_DATA_L =  ((((uint32_t)p_write_buff[offset]) & 0xFF)             \
                                                            |((((uint32_t)p_write_buff[offset + 1]) & 0xFF) << 8)            \
                                                                |((((uint32_t)p_write_buff[offset + 2]) & 0xFF) << 16)            \
                                                                    |((((uint32_t)p_write_buff[offset + 3]) & 0xFF) << 24));     
                base->WR_DATA1b.WR_DATA_H =  HAL_EFLASH_32BIT_MASK;
                break;
            case 5:
                base->WR_DATA2b.WR_DATA_L =  ((((uint32_t)p_write_buff[offset]) & 0xFF)             \
                                                            |((((uint32_t)p_write_buff[offset + 1]) & 0xFF) << 8)            \
                                                                |((((uint32_t)p_write_buff[offset + 2]) & 0xFF) << 16)            \
                                                                    |((((uint32_t)p_write_buff[offset + 3]) & 0xFF) << 24));     
                base->WR_DATA1b.WR_DATA_H =  ((((uint32_t)p_write_buff[offset + 4]) & 0xFF)  | 0xFFFFFF00);     
                break;
            case 6:
                base->WR_DATA2b.WR_DATA_L =  ((((uint32_t)p_write_buff[offset]) & 0xFF)             \
                                                            |((((uint32_t)p_write_buff[offset + 1]) & 0xFF) << 8)            \
                                                                |((((uint32_t)p_write_buff[offset + 2]) & 0xFF) << 16)            \
                                                                    |((((uint32_t)p_write_buff[offset + 3]) & 0xFF) << 24));     
                base->WR_DATA1b.WR_DATA_H =  ((((uint32_t)p_write_buff[offset + 4]) & 0xFF)             \
                                                            |((((uint32_t)p_write_buff[offset + 5]) & 0xFF) << 8)            \
                                                                | 0xFFFF0000);     
                break;
            case 7:
                base->WR_DATA2b.WR_DATA_L =  ((((uint32_t)p_write_buff[offset]) & 0xFF)             \
                                                            |((((uint32_t)p_write_buff[offset + 1]) & 0xFF) << 8)            \
                                                                |((((uint32_t)p_write_buff[offset + 2]) & 0xFF) << 16)            \
                                                                    |((((uint32_t)p_write_buff[offset + 3]) & 0xFF) << 24));     
                base->WR_DATA1b.WR_DATA_H =  ((((uint32_t)p_write_buff[offset + 4]) & 0xFF)             \
                                                            |((((uint32_t)p_write_buff[offset + 5]) & 0xFF) << 8)            \
                                                                |((((uint32_t)p_write_buff[offset + 6]) & 0xFF) << 16)            \
                                                                    |0xFF000000);     
                break;
            default:
                assert(false);
                break;
        }
        /*  enable mode */
        EFLASH_enableConfigMode(base, kEFLASH_MODE_ENABLE);
    
        /* check done */
        while(!EFLASH_operateIsDone(base));
    
        /* clear done */
        EFLASH_clearStatusFlag(base, kEFLASH_INTR_F_DONE);
    }

    if (kEFLASH_NVR_CFG_SECTOR == e_op_type)
    {
        EFLASH_writeNVRCfgRowBytes( base, e_op_type, p_write_buff, write_address, lens);
        EFLASH_setLockConfig(base, kEFLASH_MODE_ENABLE);
    }
    EFLASH_setExecutePriority(base, kEFLASH_EXECUTE_AXI_FIRST);
}                                           

/*!
 * @fn      EFLASH_ahbWriteWords
 *
 * @brief   write  (lens * 4 ) bytes data
 *
 * @param  base ： EFLASH0  , EFLASH1
 *         e_op_type:    EFLASH_MAIN_ARRAR  = 0,
                       kEFLASH_NVR_SECTOR  = 1,
                       kEFLASH_NVR_CFG_SECTOR  = 2,
                       EFLASH_NVR_RDN0  = 3,
                       EFLASH_NVR_RDN1  = 4,
 *         p_write_buff : bit32 
 *         write_address : address (0 ~ (0x100000 / 8))
 *         lens : (32bit * lens)
 * @return  none
 *
 */
void EFLASH_ahbWriteWords(EFLASH_Type *base, EFLASH_Operate_t e_op_type, uint32_t *p_write_buff,
                          volatile uint32_t write_address, uint32_t lens)
{
    uint8_t remain_lens = 0;
    uint32_t temp = 0, offset = 0;
         
    assert(EFLASH_baseIsValid(base));

    remain_lens = lens % 2;    

    EFLASH_disableRecallMode(base);
    EFLASH_setExecutePriority(base, kEFLASH_EXECUTE_AHB_FIRST);

    if (kEFLASH_NVR_CFG_SECTOR == e_op_type)
    {
        EFLASH_setLockConfig(base, kEFLASH_MODE_DISABLE);
    }

    for (temp = 0; temp < (lens/2); temp++)
    {
        // check whether be protect
        if (EFLASH_mainArrayAddressIsProtect(base, e_op_type, write_address + temp))
        {
            continue;  //next write
        }
                
        /* choose operate type */ 
        EFLASH_selectOperateTarget(base, e_op_type);

        /* write key */
        EFLASH_setKeyValue(base, kEFLASH_AHB_WRITE_KEY);
        
        /* cfg write mode */
        EFLASH_configMode(base, kEFLASH_WRITE_MODE);
        
        /* set op address */
         EFLASH_setOperateAddress(base, write_address + temp);

        /* write data */
        offset = temp * 2;
        base->WR_DATA2b.WR_DATA_L =  p_write_buff[offset];
        base->WR_DATA1b.WR_DATA_H =  p_write_buff[offset + 1];
        
        /*  enable mode */
        EFLASH_enableConfigMode(base, kEFLASH_MODE_ENABLE);

        /* check done */
        while(!EFLASH_operateIsDone(base));

        /* clear done */
        EFLASH_clearStatusFlag(base, kEFLASH_INTR_F_DONE);
    }
    if (remain_lens != 0)
    {
        /* choose operate type */ 
        EFLASH_selectOperateTarget(base, e_op_type);

        /* write key */
        EFLASH_setKeyValue(base, kEFLASH_AHB_WRITE_KEY);
        
        /* cfg write mode */
        EFLASH_configMode(base, kEFLASH_WRITE_MODE);

        /* set op address */
        EFLASH_setOperateAddress(base, write_address + temp);

        /* write data */
        offset = temp * 2;
        base->WR_DATA2b.WR_DATA_L =  p_write_buff[offset];
        base->WR_DATA1b.WR_DATA_H =  HAL_EFLASH_32BIT_MASK;
        
        /* enable mode */
        EFLASH_enableConfigMode(base, kEFLASH_MODE_ENABLE);

        /* check done */
        while(!EFLASH_operateIsDone(base));

        /* clear done */
        EFLASH_clearStatusFlag(base, kEFLASH_INTR_F_DONE);
    }
    if (kEFLASH_NVR_CFG_SECTOR == e_op_type)
    {
        EFLASH_writeNVRCfgRowWords( base, e_op_type, p_write_buff, write_address, lens);
        EFLASH_setLockConfig(base, kEFLASH_MODE_ENABLE);
    }
    EFLASH_setExecutePriority(base, kEFLASH_EXECUTE_AXI_FIRST);
}

/*!
 * @fn      EFLASH_writeNVRCfgRowWords
 *
 * @brief   write  (lens * 8 ) bytes data
 *
 * @param  base ： EFLASH0  , EFLASH1
 *         e_op_type:    EFLASH_MAIN_ARRAR  = 0,
                       kEFLASH_NVR_SECTOR  = 1,
                       kEFLASH_NVR_CFG_SECTOR  = 2,
                       EFLASH_NVR_RDN0  = 3,
                       EFLASH_NVR_RDN1  = 4,
 *         p_write_buff : bit64 
 *         write_address : address (0 ~ (0x100000 / 8))
 *         lens : (64bit * lens)
 * @return  none *

 * @note ： NVR_CFG odd and evn lines must be consistent
 */
void EFLASH_ahbWriteDwords(EFLASH_Type *base, EFLASH_Operate_t e_op_type, uint64_t *p_write_buff,
                           volatile uint32_t write_address, uint32_t lens)
{
    uint32_t temp = 0;
    assert(EFLASH_baseIsValid(base));

    EFLASH_disableRecallMode(base);
    EFLASH_setExecutePriority(base, kEFLASH_EXECUTE_AHB_FIRST);

    if (kEFLASH_NVR_CFG_SECTOR == e_op_type)
    {
        EFLASH_setLockConfig(base, kEFLASH_MODE_DISABLE);
    }

    for (temp = 0; temp < lens; temp++)
    {
        // check whether be protect
        if (EFLASH_mainArrayAddressIsProtect(base, e_op_type, write_address + temp))
        {
            continue;  //next write
        }
        /* choose operate type */
        EFLASH_selectOperateTarget(base, e_op_type);

        /* write key */
        EFLASH_setKeyValue(base, kEFLASH_AHB_WRITE_KEY);

        /* cfg write mode */
        EFLASH_configMode(base, kEFLASH_WRITE_MODE);

        /* set op address */
         EFLASH_setOperateAddress(base, write_address + temp);

        /* write data */
        EFLASH_writeData(base, p_write_buff[temp]);
        
        /* enable mode */
        EFLASH_enableConfigMode(base, kEFLASH_MODE_ENABLE);

        /* check done */
        while(!EFLASH_operateIsDone(base));

        /* clear done */
        EFLASH_clearStatusFlag(base, kEFLASH_INTR_F_DONE);
    }
    if (kEFLASH_NVR_CFG_SECTOR == e_op_type)
    {
        EFLASH_writeNVRCfgRowDwords(base, e_op_type, p_write_buff, write_address,  lens);
        EFLASH_setLockConfig(base, kEFLASH_MODE_ENABLE);
    }
    EFLASH_setExecutePriority(base, kEFLASH_EXECUTE_AXI_FIRST);
}

/*!
 * @fn      EFLASH_enableReplaceRDNSector
 *
 * @brief   enable_replace_redundancy_sector
 *
 * @param  base ： EFLASH0  , EFLASH1
 * 
 *         rdn_num : 0 or  1 
 *         replace_address : address (0 ~ (0x100000 / 8))
 * @return  none
 *
 */
void EFLASH_enableReplaceRDNSector(EFLASH_Type *base, uint8_t rdn_num, uint32_t replace_address)
{
    assert(EFLASH_baseIsValid(base));
    assert(rdn_num < 2);

    if (0 == rdn_num)
    {
        base->RR0_CFGb.RR0_EN = 1;
        base->RR0_CFGb.RR0_ADDR = replace_address;
    }
    else
    {
        base->RR1_CFGb.RR1_EN = 1;
        base->RR1_CFGb.RR1_ADDR = replace_address;
    }
}

/*!
 * @fn      EFLASH_disableReplaceRDNSector
 *
 * @brief   disable_replace_redundancy_sector
 *
 * @param  base ： EFLASH0  , EFLASH1
 * 
 *         rdn_num : 0 or  1 
 *
 * @return  none
 *
 */
void EFLASH_disableReplaceRDNSector(EFLASH_Type *base, uint8_t rdn_num)
{
    assert(EFLASH_baseIsValid(base));
    assert(rdn_num < 2);

    if (0 ==rdn_num)
    {
        base->RR0_CFGb.RR0_EN = 0;
    }
    else
    {
        base->RR1_CFGb.RR1_EN = 0;
    }
}

/*!
 * @fn      EFLASH_enableProtectArea
 *
 * @brief   EFLASH_enableProtectArea
 *
 * @param  base ： EFLASH0  , EFLASH1
 *         start_address : start address  (0 ~ (0x100000 / 8))
 *         end_address : end address   (0 ~ (0x100000 / 8))
 * @return  none
 *
 */
void EFLASH_enableProtectArea(EFLASH_Type *base, uint32_t start_address, uint32_t end_address)
{
    assert(EFLASH_baseIsValid(base));
    
    base->PROTECT_STARTb.LOCK_BEG_ADDR = start_address;
    base->PROTECT_ENDb.LOCK_END_ADDR = end_address;

    base->PROTECT_ENb.LOCK_EN = 1;
}

/*!
 * @fn      EFLASH_disableProtectArea
 *
 * @brief   hal_eflash_diable_protect_erae
 *
 * @param  base ： EFLASH0  , EFLASH1
 *
 * @return  none
 *
 */
void EFLASH_disableProtectArea(EFLASH_Type *base)
{
    assert(EFLASH_baseIsValid(base));

    base->PROTECT_ENb.LOCK_EN = 0;
}

/*!
 * @fn      EFLASH_enableDeepPowerDown
 *
 * @brief   EFLASH_enableDeepPowerDown
 *
 * @param  base ： EFLASH0  , EFLASH1
 *         
 * @return  none
 *
 */
void EFLASH_enableDeepPowerDown(EFLASH_Type *base)
{
    assert(EFLASH_baseIsValid(base));

    base->CFGb.DPD_CFG = 1;

    EFLASH_configMode(base, kEFLASH_DPD_MODE);

    EFLASH_enableConfigMode(base, kEFLASH_MODE_ENABLE);

    /* check done */
    while(!EFLASH_operateIsDone(base));

    /* clear done */
    EFLASH_clearStatusFlag(base, kEFLASH_INTR_F_DONE);
}

/*!
 * @fn      EFLASH_setConfigReg
 *
 * @brief   EFLASH_setConfigReg
 *
 * @param  base ： EFLASH0  , EFLASH1
 *         cfg_reg_addr ： CBD addr
 *          data ： reg data 
 * @return  none
 *
 */
void EFLASH_setConfigReg(EFLASH_Type *base, EFLASH_ConfigReg_t cfg_reg_addr, uint64_t data)
{
    assert(EFLASH_baseIsValid(base));

    EFLASH_configMode(base, kEFLASH_SET_CFG_MODE);

    /* set op address */
    EFLASH_setOperateAddress(base, (uint32_t)(cfg_reg_addr));

    /* write data */
    base->WR_DATA2b.WR_DATA_L =  (uint32_t)data;
    base->WR_DATA1b.WR_DATA_H =  (uint32_t)(data >> 32);

    EFLASH_enableConfigMode(base, kEFLASH_MODE_ENABLE);

    /* check done */
    while(!EFLASH_operateIsDone(base));

    /* clear done */
    EFLASH_clearStatusFlag(base, kEFLASH_INTR_F_DONE);
}

/*!
 * @fn      EFLASH_disableDeepPowerDown
 *
 * @brief   EFLASH_disableDeepPowerDown
 *
 * @param  base ： EFLASH0  , EFLASH1
 *         
 * @return  none
 *
 */
void EFLASH_disableDeepPowerDown(EFLASH_Type *base)
{
    assert(EFLASH_baseIsValid(base));

    base->CFGb.DPD_CFG = 0;
}

/*!
 * @fn      EFLASH_enableAXIOperate
 *
 * @brief   EFLASH_enableAXIOperate
 *
 * @param  base ： EFLASH0  , EFLASH1
 *
 * @return  none
 *
 */
void EFLASH_enableAXIOperate(EFLASH_Type *base)
{
    assert(EFLASH_baseIsValid(base));

    base->AXI_CFGb.AXI_PROG_EN = 1;
}

/*!
* @fn      EFLASH_disableAXIOperate
*
* @brief   EFLASH_disableAXIOperate
*
* @param  base ： EFLASH0  , EFLASH1
*
* @return  none
*
*/
void EFLASH_disableAXIOperate(EFLASH_Type *base)
{
    assert(EFLASH_baseIsValid(base));

    base->AXI_CFGb.AXI_PROG_EN = 0;
}

/*!
* @fn      EFLASH_readAXIMainArrayBytes
*
* @brief   read  lens bytes data
*
* @param  base ： EFLASH0  , EFLASH1
*         p_read_buff : bit8 
*         read_address : address  ( must > 0x0030 0000 or 0x10300000)
*         lens : (8bit * lens)
* @return  none
*
*/
void EFLASH_readAXIMainArrayBytes(EFLASH_Type *base, uint8_t *p_read_buff, volatile uint32_t read_address,
                                  uint32_t lens)
{
    uint32_t temp;

    EFLASH_setReadMode(base, kEFLASH_READ_NORMAL);
    for (temp = 0; temp < lens; temp++)
    {
        p_read_buff[temp] = (*((volatile uint8_t*)(read_address + temp)));
    }
}

/*!
 * @fn      EFLASH_readAXIMainArrayHwords
 *
 * @brief    read  (lens * 2 ) bytes data
 *
 * @param  base ： EFLASH0  , EFLASH1
 *         p_read_buff : bit16 
 *         read_address : address ( must > 0x0030 0000 or 0x10300000)
 *         lens : (16bit * lens)
 * @return  none
 *
 */
void EFLASH_readAXIMainArrayHwords(EFLASH_Type *base, uint16_t *p_read_buff, volatile uint32_t read_address,
                                   uint32_t lens)
{
    uint32_t temp;

    EFLASH_setReadMode(base, kEFLASH_READ_NORMAL);
    for (temp = 0; temp < lens; temp++)
    {
        p_read_buff[temp] = (*((volatile uint16_t*)(read_address + temp * 2)));
    }
}

/*!
 * @fn      EFLASH_readAXIMainArrayWords
 *
 * @brief   read  (lens * 4 ) bytes data
 *
 * @param  base ： EFLASH0  , EFLASH1
 *         p_read_buff : bit32
 *         read_address : address ( must > 0x0030 0000 or 0x10300000)
 *         lens : (32bit * lens)
 * @return  none
 *
 */
void EFLASH_readAXIMainArrayWords(EFLASH_Type *base, uint32_t *p_read_buff, volatile uint32_t read_address,
                                  uint32_t lens)
{
    uint32_t temp;

    EFLASH_setReadMode(base, kEFLASH_READ_NORMAL);
    for (temp = 0; temp < lens; temp++)
    {
        p_read_buff[temp] = (*((volatile uint32_t*)(read_address + temp * 4)));
    }
}

/*!
 * @fn      EFLASH_readAXIMainArrayDWords
 *
 * @brief   read  (lens * 8 ) bytes data
 *
 * @param  base ： EFLASH0  , EFLASH1
 *         p_read_buff : bit64 
 *         read_address : address ( must > 0x0030 0000 or 0x10300000)
 *         lens : (64bit * lens)
 * @return  none
 *
 */
void EFLASH_readAXIMainArrayDWords(EFLASH_Type *base, uint64_t *p_read_buff, volatile uint32_t read_address,
                                   uint32_t lens)
{
    uint32_t temp;

    EFLASH_setReadMode(base, kEFLASH_READ_NORMAL);  
    for (temp = 0; temp < lens; temp++)
    {
        p_read_buff[temp] = (*((volatile uint64_t*)(read_address + temp * 8)));
    }
}

/*!
 * @fn      EFLASH_writeAXIMainArrayBytes
 *
 * @brief   write  (lens  ) bytes data,
 * @param  base ： EFLASH0  , EFLASH1
 *         p_write_buff : bit16 
 *         write_address : address ( must > 0x0030 0000 or 0x10300000)
 *         lens : (8bit * lens)
 * @return  none
 *
 */
void EFLASH_writeAXIMainArrayBytes(EFLASH_Type *base, uint8_t *p_write_buff, volatile uint32_t write_address,
                                   uint32_t lens)
{
    uint32_t temp, offset, remain_lens, opAddress, temp_64bit;
    uint64_t data;

    assert(EFLASH_baseIsValid(base));

    EFLASH_enableAXIOperate(base);

    remain_lens = lens % 8;
    for (temp = 0; temp < lens/8; temp++)
    {
        offset = temp * 8;
        opAddress = write_address + offset;
        data = 0;
        for (temp_64bit = 0; temp_64bit < 8; temp_64bit++)
        {
            data |= (((uint64_t)p_write_buff[offset + temp_64bit]) << ( temp_64bit * 8));
        }

        (*((volatile uint64_t*)(opAddress))) = data;

        __DSB();
    }
    if (remain_lens != 0)
    {
        offset = temp * 8;
        opAddress = write_address + offset;
        data = 0;
        for (temp_64bit = 0; temp_64bit < remain_lens; temp_64bit++)
        {
            data |= (((uint64_t)p_write_buff[offset + temp_64bit]) << ( temp_64bit * 8));
        }

        (*((volatile uint64_t*)(opAddress))) = data;

        __DSB();
    }
}                                                      
                                                        
/*!
 * @fn      EFLASH_writeAXIMainArrayHwords
 *
 * @brief   write  (lens * 2 ) bytes data,
 * @param  base ： EFLASH0  , EFLASH1
 *         p_write_buff : bit16 
 *         write_address : address ( must > 0x0030 0000 or 0x10300000)
 *         lens : (16bit * lens)
 * @return  none
 *
 */
void EFLASH_writeAXIMainArrayHwords(EFLASH_Type *base, uint16_t *p_write_buff, volatile uint32_t write_address,
                                    uint32_t lens)
{
    uint32_t temp, offset, remain_lens, opAddress, temp_64bit;
    uint64_t data;

    assert(EFLASH_baseIsValid(base));

    EFLASH_enableAXIOperate(base);

    remain_lens = lens % 4;
    for (temp = 0; temp < lens/4; temp++)
    {
        offset = temp * 8;
        opAddress = write_address + offset;
        data = 0;
        for (temp_64bit = 0; temp_64bit < 4; temp_64bit++)
        {
        data |= (((uint64_t)p_write_buff[temp * 4 + temp_64bit]) << ( temp_64bit * 16));
        }
        
        (*((volatile uint64_t*)(opAddress))) = data;

        __DSB();       
    }
    if (remain_lens != 0)
    {
        offset = temp * 8;
        opAddress = write_address + offset;
        data = 0;
        for (temp_64bit = 0; temp_64bit < remain_lens; temp_64bit++)
        {
            data |= (((uint64_t)p_write_buff[temp * 4 + temp_64bit]) << ( temp_64bit * 16));
        }

        (*((volatile uint64_t*)(opAddress))) = data;

        __DSB();
    } 
}

/*!
 * @fn      EFLASH_writeAXIMainArrayWords
 *
 * @brief   write  (lens * 4 ) bytes data,
 * @param  base ： EFLASH0  , EFLASH1
 *         p_write_buff : bit32 
 *         write_address : address ( must > 0x0030 0000 or 0x10300000)
 *         lens : (32bit * lens)
 * @return  none
 *
 */
void EFLASH_writeAXIMainArrayWords(EFLASH_Type *base, uint32_t *p_write_buff, volatile uint32_t write_address,
                                   uint32_t lens)
{
    uint32_t temp, offset, remain_lens, opAddress;
    uint64_t data;

    assert(EFLASH_baseIsValid(base));

    EFLASH_enableAXIOperate(base);

    remain_lens = lens % 2;
    for (temp = 0; temp < lens/2; temp++)
    {
        offset = temp * 8;
        opAddress = write_address + offset;
        data = ((uint64_t)(p_write_buff[temp * 2 + 1]) << 32) | ((uint64_t)(p_write_buff[temp * 2]));

        (*((volatile uint64_t*)(opAddress))) = data;
        __DSB();
    }
    if (remain_lens != 0)
    {
        offset = temp * 8;
        opAddress = write_address + offset;

        data = (uint64_t)p_write_buff[temp * 2];
        (*((volatile uint64_t*)(opAddress))) = data;

        __DSB();
    }
}

/*!
 * @fn      EFLASH_writeAXIMainArrayDwords
 *
 * @brief   write  (lens * 8 ) bytes data, only support 64 bit write for axi
 *
 * @param  base ： EFLASH0  , EFLASH1
 *         p_write_buff : bit64 
 *         write_address : address ( must > 0x0030 0000 or 0x10300000)
 *         lens : (64bit * lens)
 * @return  none
 *
 */
void EFLASH_writeAXIMainArrayDwords(EFLASH_Type *base, uint64_t *p_write_buff, volatile uint32_t write_address,
                                    uint32_t lens)
{
    uint32_t temp;
    assert(EFLASH_baseIsValid(base));

    EFLASH_enableAXIOperate(base);

    for (temp = 0; temp < lens; temp++)
    {
        (*((volatile uint64_t*)(write_address + temp * 8))) = p_write_buff[temp];

        __DSB();
    }
}




