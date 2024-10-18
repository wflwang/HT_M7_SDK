/*!
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*!
 * \file hte_eflash.h
 * \brief SDK EFLASH driver header file
 * \version 1.0.0
 */

#ifndef _HTE_EFLASH_H_
#define _HTE_EFLASH_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_common.h"

/*!
 *
 * \brief SDK EFLASH driver
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*!
 * \brief Calculates the sector count of an EFLASH access counter.
 */
#define EFLASH_getSecCounter(_CNT_, _PERIOD_) ((_CNT_ / _PERIOD_) < 1) ? (1) : (_CNT_ / _PERIOD_)

/*!
 * \brief Checks if a specific interrupt flag is set in the status register of the EFLASH.
 */
#define HAL_EFLASH_CHECK_IT_FLAG(__SR__, __FLAG__)          ((((__SR__) & (__FLAG__)) == 1) ? (1) : (0))

/*!
 * \brief Used for byte-wise operations in EFLASH memory access or manipulation.
 */
#define HAL_EFLASH_8BIT_MASK                      (0xFF)                  /*!< Defines an 8-bit mask */
#define HAL_EFLASH_16BIT_MASK                     (0xFFFF)                /*!< Defines an 16-bit mask */
#define HAL_EFLASH_32BIT_MASK                     (0xFFFFFFFF)            /*!< Defines an 32-bit mask */
#define HAL_EFLASH_64BIT_MASK                     (0xFFFFFFFFFFFFFFFF)    /*!< Defines an 64-bit mask */
#define HAL_EFLASH_64BIT_H32_MASK                 (0xFFFFFFFF00000000)    /*!< Defines an 64-bit of high 32bit mask */
#define EFLASH_MAIN_ARRAY_ONE_SECTOR_DWORD        (512)                   /*!< Defines the number of 32-bit words (DWords) per sector */
#define EFLASH_MAIN_ARRAY_SECTOR_NUM              (256)                   /*!< Specifies the total number of sectors */
#define EFLASH_NVR_SECTOR_NUM                     (16)                    /*!< Specifies the total number of nvr sectors */
#define EFLASH_NVR_CFG_SECTOR_NUM                 (1)                     /*!< Specifies the number of sectors nvr cfg */
#define EFLASH_RDN_SECTOR_NUM                     (2)                     /*!< Specifies the number of RDN */

/*!
 * \brief Enumerated type for EFlash status flags
 */
typedef enum
{
    kEFLASH_INTR_VREAD_OK = 0,           /*!< Interrupt flag of VREAD success */
    kEFLASH_INTR_AHB_W_LOCK_AREA = 1,    /*!< Interrupt flag of AHB write lock */
    kEFLASH_INTR_AXI_W_LOCK_AREA = 2,    /*!< Interrupt flag of AXI write lock */
    kEFLASH_INTR_AXI_WERR = 3,           /*!< Interrupt flag of AXI write error */
    kEFLASH_INTR_F_DONE = 4,             /*!< Interrupt flag of flash operation completed */
    kEFLASH_ST_AXI_WERR_ADDR_CLR = 5,    /*!< Status flag of clear AXI write error address */
    kEFLASH_ST_WRITE_CNT_CLR = 6,        /*!< Status flag of clear the write counter */
    kEFLASH_STATUS_MAX                   /*!< Status flag of max number */
} EFLASH_StatusFlag_t;

/*!
 * \brief Enumerated type for EFlash indices
 */
typedef enum
{
    kEFLASH_INDEX_0 = 0,                 /*!< Index for the first EFlash instance */
    kEFLASH_INDEX_1 = 1,                 /*!< Index for the second EFlash instance */
    EFLASH_INDEX_MAX                     /*!< Index for the max number */
} EFLASH_Index_t;

/*!
 * \brief Enumerated type for EFlash mode status
 */
typedef enum
{
    kEFLASH_MODE_DISABLE = 0x00,         /*!< EFlash mode disabled */
    kEFLASH_MODE_ENABLE = 0x01           /*!< EFlash mode enabled */
} EFLASH_ModeStatus_t;

/*!
 * \brief Enumerated type for EFlash read modes
 */
typedef enum
{
    kEFLASH_READ_NORMAL = 0x00,          /*!< Normal read mode */
    kEFLASH_READ_SLOW = 0x01             /*!< Slow read mode */
} EFLASH_ReadSpeed_t;

/*!
 * \brief Enumerated type for EFlash current operating states
 */
typedef enum
{
    kEFLASH_IDLE_STATE = 0x0,            /*!< Idle state */
    kEFLASH_POWER_RESET = 0x1,           /*!< Power-On Reset (POR) state */
    kEFLASH_DEEP_POWERDOWN = 0x2,        /*!< Deep Power-Down (DPD) state */
    kEFLASH_READ_STATE = 0x3,            /*!< Read operation state */
    kEFLASH_RECALL_READ = 0x4,           /*!< Recall Read operation state */
    kEFLASH_REG_PROGRAM = 0x5,           /*!< Register Programming state */
    kEFLASH_PROGRAM_STATE = 0x6,         /*!< Programming state */
    kEFLASH_SECTOR_ERASE = 0x7,          /*!< Sector Erase state */
    kEFLASH_CHIP_ERASE = 0x8,            /*!< Chip Erase state */
    kEFLASH_AUTO_READ_CONF = 0x9,        /*!< Auto Read Configuration state */
    kEFLASH_AUTO_SET_CFG = 0xA,          /*!< Auto Set Configuration state */
    kEFLASH_SET_CFG = 0xB,               /*!< Set Configuration state */
    kEFLASH_VREAD_STATE = 0xC,           /*!< Virtual Read (VREAD) state */
    kEFLASH_AXI_READ = 0xD,              /*!< AXI Bus Read state */
    kEFLASH_STATUS_MAX_INDEX             /*!< Max number of index */
} EFLASH_Status_t;

/*!
 * \brief Enumerated type for EFlash operation modes
 */
typedef enum
{
    kEFLASH_NONE_MODE = 0,               /*!< No Operation Mode */
    kEFLASH_SECOR_ERASE_MODE = 1,        /*!< Sector Erase Mode */
    kEFLASH_CHIP_ERASE_MODE = 2,         /*!< Chip Erase Mode */
    kEFLASH_DPD_MODE = 3,                /*!< Deep Power-Down Mode */
    kEFLASH_READ_MODE = 4,               /*!< Read Mode */
    kEFLASH_WRITE_MODE = 5,              /*!< Write Mode */
    kEFLASH_SET_CFG_MODE = 6,            /*!< Set Configuration Mode */
    kEFLASH_SW_RESET_MODE = 7,           /*!< Software Reset Mode */
    kEFLASH_VREAD_MODE = 8,              /*!< Virtual Read Mode */  
    kEFLASH_MODE_MAX_INDEX = 9                 /*!< Sentinel Value: Maximum Mode */
} EFLASH_Mode_t;
 
/*!
 * \brief Enumerated type for EFlash interrupt events
 */
typedef enum
{
    kEFLASH_INT_AHB_WRITE_LOCK = 0,      /*!< AHB Write Lock Area Interrupt Enable */
    kEFLASH_INT_AXI_WRITE_LOCK = 1,      /*!< AXI Write Lock Area Interrupt Enable */
    kEFLASH_INT_AXI_WRITE_ERROR = 2,             /*!< AXI Write Error Interrupt Enable */
    kEFLASH_INT_FLASH_DONE = 3,               /*!< Flash Operation Done Interrupt Enable */
    kEFLASH_INT_MAX_INDEX                /*!< Max number of index */
} EFLASH_InterruptType_t;
  
/*!
 * \brief Enumerated type for EFlash operation targets
 */
typedef enum
{
    kEFLASH_MAIN_ARRAR_SECTOR  = 0,      /*!< Main Array Sector */
    kEFLASH_NVR_SECTOR         = 1,      /*!< Non-Volatile RAM (NVR) Sector */
    kEFLASH_NVR_CFG_SECTOR     = 2,      /*!< NVR Configuration Sector */
    kEFLASH_RDN_SECTOR0        = 3,      /*!< Read-While-Write Data-Namespace (RDN) Sector 0 */
    kEFLASH_RDN_SECTOR1        = 4,      /*!< Read-While-Write Data-Namespace (RDN) Sector 1 */
    kEFLASH_OPERATE_MAX_INDEX            /*!< Max number of index */
} EFLASH_Operate_t;

/*!
 * \brief Enumerated type for EFlash data size options during operations
 */
typedef enum
{
    kEFLASH_DSIZE_8BIT   = 0,            /*!< 8-bit Data Size */
    kEFLASH_DSIZE_16BIT  = 1,            /*!< 16-bit Data Size */
    kEFLASH_DSIZE_32BIT  = 2,            /*!< 32-bit Data Size */
    kEFLASH_DSIZE_64BIT  = 3,            /*!< 64-bit Data Size */
    kEFLASH_DSIZE_MAX_INDEX              /*!< Max number of index */
} EFLASH_DataSize_t;

/*!
 * \brief Enumerated type for EFlash chip erase types
 */
typedef enum
{
    kEFLASH_MAIN_ARRAY    = 0,           /*!< Main Array Erase */
    kEFLASH_MAIN_AND_RDN  = 1,         /*!< Main + Read-While-Write Data-Namespace Erase */
    kEFLASH_MAIN_NVR_RDN  = 2,         /*!< Main + RDN + Non-Volatile RAM Erase */
    kEFLASH_ERASE_MAX_INDEX                  /*!< Max number of index */
} EFLASH_EraseType_t;

/*!
 * \brief Enumerated type for EFlash key values
 */
typedef enum
{
    kEFLASH_AHB_WRITE_KEY    = 0x5432C7D9,       /*!< Write Key */
    kEFLASH_ERASE_SECTOR_KEY = 0x5A5A00FC,       /*!< Sector Erase Key */
    kEFLASH_ERASE_CHIP_KEY   = 0x5A5ADE00        /*!< Chip Erase Key */
} EFLASH_KeyValue_t;

/*!
 * \brief Enumerated type for EFlash configuration registers
 */
typedef enum
{
    kEFLASH_REG_CBD0  = 0,    /*!< Configuration Register CBD0 */
    kEFLASH_REG_CBD1  = 1,    /*!< Configuration Register CBD1 */
    kEFLASH_REG_CBD2  = 2,    /*!< Configuration Register CBD2 */
    kEFLASH_REG_CBD3  = 3,    /*!< Configuration Register CBD3 */
    kEFLASH_REG_CBD4  = 4,    /*!< Configuration Register CBD4 */
    kEFLASH_REG_CBD5  = 5,    /*!< Configuration Register CBD5 */
    kEFLASH_REG_CBD6  = 6,    /*!< Configuration Register CBD6 */
    kEFLASH_REG_CBD7  = 7,    /*!< Configuration Register CBD7 */
    kEFLASH_REG_CBD_MAX       /*!< Max number of index */
} EFLASH_ConfigReg_t;

/*!
 * \brief Enumerated type for EFlash execute priority
 */
typedef enum
{
    kEFLASH_EXECUTE_AXI_FIRST = 0U,     /*!< EFLASH AXI read/write first */
    kEFLASH_EXECUTE_AHB_FIRST = 1U      /*!< EFLASH AHB read/write first */
} EFLASH_ExePriority_t;

/*!
 * \brief Struct type for EFlash power-on cycle time configuration
 */
typedef struct
{
    uint16_t pown_on_tRHR;              /*!< Time for Power-On tRHR (Release Hold Recovery Time) */
    uint8_t pown_on_tRT;                /*!< Time for Power-On tRT (Release Time) */
    uint8_t pown_on_tDPDSR;             /*!< Time for Power-On tDPDSR (Deep Power-Down to Standby Recovery Time) */
    uint16_t pown_on_tDPDH;             /*!< Time for Power-On tDPDH (Deep Power-Down Exit Hold Time) */
} EFLASH_Timing_Power_t;

/*!
 * \brief Struct type for EFlash low voltage control timing configuration
 */
typedef struct
{
    uint8_t lvctl_tCRC;                 /*!< Time for LVCTL tCRC (Command Reception Completion Time) */
    uint8_t lvctl_tACC;                 /*!< Time for LVCTL tACC (Access Time) */
} EFLASH_Timing_LVCTL_t;

/*!
 * \brief Struct type for EFlash program cycle time configuration
 */
typedef struct
{
    uint16_t prog_tPROG;                /*!< Time for Programming tPROG (Programming Time) */
    uint16_t prog_tPGS;                 /*!< Time for Programming tPGS (Programming Setup Time) */
    uint8_t prog_tADS;                  /*!< Time for Programming tADS (Address to Data Strobe Delay Time) */
    uint8_t prog_tADH;                  /*!< Time for Programming tADH (Address Hold Time) */
    uint8_t prog_tPGH;                  /*!< Time for Programming tPGH (Programming Hold Time) */
    uint16_t prog_tNVS;                 /*!< Time for Programming tNVS (Nonvolatile Storage Time) */
    uint8_t prog_tWSH;                  /*!< Time for Programming tWSH (Write State Hold Time) */
    uint8_t prog_tACC;                  /*!< Time for Programming tACC (Access Time) */
    uint8_t prog_tRW;                   /*!< Time for Programming tRW (Read Wait Time) */
    uint16_t prog_tRCV;                 /*!< Time for Programming tRCV (Recovery Time) */
} EFLASH_Timing_Program_t;

/*!
 * \brief Struct type for EFlash erase cycle time configuration
 */
typedef struct
{
    uint32_t erase_sector_tERASE;       /*!< Time for Sector Erase tERASE */
    uint16_t erase_sector_tRCV;         /*!< Time for Sector Erase tRCV (Recovery Time) */
    uint32_t erase_chip_tERASE;         /*!< Time for Chip Erase tERASE */
    uint32_t erase_chip_tRCV;           /*!< Time for Chip Erase tRCV (Recovery Time) */
} EFLASH_Timing_ERASE_t;

/*!
 * \brief Struct type for EFlash set configuration register timing configuration
 */
typedef struct
{
    uint16_t nvr_cfg_tACC_NVR;          /*!< Time for NVR Configuration tACC_NVR (Access Time) */
    uint16_t nvr_cfg_tMS;               /*!< Time for Setting  tMS (Maximum Setup Time) */
    uint8_t set_cfg_reg_tCFH;           /*!< Time for Setting  Register tCFH (Configuration Field Hold Time) */
    uint16_t set_cfg_reg_tCFL;          /*!< Time for Setting  Register tCFL (Configuration Field Latch Time) */
    uint8_t set_cfg_reg_tCONFEN;        /*!< Time for Setting  Register tCONFEN (Configuration Enable Time) */
} EFLASH_Timing_ConfigReg_t;

/*!
 * \brief Struct type for EFlash initialization configuration
 */
typedef struct
{
    EFLASH_Timing_Power_t        por_cfg;       /*!< Power-On Cycle Time Configuration */
    EFLASH_Timing_LVCTL_t        lvctl_cfg;     /*!< Low Voltage Control Time Configuration */
    EFLASH_Timing_Program_t      prog_cfg;      /*!< Programming Cycle Time Configuration */
    EFLASH_Timing_ERASE_t        erase_cfg;     /*!< Erase Cycle Time Configuration */
    EFLASH_Timing_ConfigReg_t    set_reg_cfg;   /*!< Set Configuration Register Time Configuration */
} EFLASH_Timing_t;

/*******************************************************************************
 * APIs
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Validate EFLASH Base Address
 *
 * \details Checks if the provided EFLASH base address is valid, ensuring it points to a legitimate EFLASH peripheral.
 *
 * \param[in] base Pointer to the EFLASH peripheral base address to validate.
 *
 * \return Returns true if the base address is valid, false if not.
 *
 * \note This function is useful for preprocessing checks to avoid dereferencing invalid pointers.
 *
 * \warning Proceeding with an invalid base address can lead to undefined behavior or system crashes.
 */
static inline bool EFLASH_baseIsValid(EFLASH_Type *base)
{
    return (base != NULL);
}

/*!
 * \brief Check EFLASH Ready Status
 *
 * \details Determines if the EFLASH memory is in a ready state, indicating it's available for new operations.
 *
 * \param[in] base Pointer to the EFLASH peripheral base address for status query.
 *
 * \return Returns true if EFLASH is ready for new operations, false if busy or in a transitional state.
 *
 * \note Should be checked before initiating new read, write, or erase commands to avoid conflicts or undefined behavior.
 *
 * \warning Attempting operations when EFLASH is not ready can lead to command failures or data corruption.
 */
static inline bool EFLASH_statusIsReady(EFLASH_Type *base)
{
    assert(EFLASH_baseIsValid(base));
    
    return base->FLASH_FSMb.FLASH_READY;
}

/*!
 * \brief Check EFLASH Operation Completion Status
 *
 * \details Queries the status of the current EFLASH operation to determine if it has completed.
 *
 * \param[in] base Pointer to the EFLASH peripheral base address for status check.
 *
 * \return Returns true if the operation is done, false otherwise.
 *
 * \note This function is typically used in a loop until true is returned.
 *
 * \note Does not indicate operation success or failure, only its completion status.
 */
static inline bool EFLASH_operateIsDone(EFLASH_Type *base)
{
    assert(EFLASH_baseIsValid(base));

    return base->FLASH_INTR_STb.F_DONE;
}

/*!
 * \brief Configure EFLASH Operation Mode
 *
 * \details Selects the operational mode of the EFLASH controller.
 * 
 * \param[in] base Pointer to the EFLASH peripheral base address for mode configuration.
 * \param[in] mode Enumerated value specifying the desired operational mode (\ref EFLASH_Mode_t) .
 *
 * \note Incorrect mode selection can impede functionality or cause unintended side effects.
 *
 * \warning Ensure proper mode sequencing and adherence to device-specific guidelines to avoid issues.
 */
static inline void EFLASH_configMode(EFLASH_Type *base, EFLASH_Mode_t mode)
{
    assert(mode < kEFLASH_MODE_MAX_INDEX);
    assert(EFLASH_baseIsValid(base));

    base->CTRLb.MODE_SEL = mode;
}

/*!
 * \brief Enable or Disable EFLASH Configuration Mode
 *
 * \details Controls the entry into or exit from the configuration mode of the EFLASH.
 * 
 * \param[in] base Pointer to the EFLASH peripheral base address for mode control.
 * \param[in] b_enable Enumerated status to enable (\ref kEFLASH_MODE_ENABLE) or disable (\ref kEFLASH_MODE_DISABLE).
 *
 * \note Configuration mode might expose sensitive settings; use with caution and ensure operations.
 *
 * \warning Mismanagement of configuration mode can lead to unstable memory states.
 */
static inline void EFLASH_enableConfigMode(EFLASH_Type *base, EFLASH_ModeStatus_t b_enable)
{
    assert(EFLASH_baseIsValid(base));

    base->CTRLb.CMD_ENABLE = b_enable;
}

/*!
 * \brief Set EFLASH Lock Configuration
 *
 * \details Enables or disables write/erase lock configuration to protect EFLASH memory contents from unauthorized modifications.
 *
 * \param[in] base Pointer to the EFLASH peripheral base address for lock control.
 * \param[in] b_enable Enumerated status to enable (\ref kEFLASH_MODE_ENABLE) or disable (\ref kEFLASH_MODE_DISABLE) the lock.
 *
 * \note Once locked, write/erase operations are restricted until explicitly unlocked.
 *
 * \warning Misuse can lead to permanent lockout, preventing future data updates or erase operations.
 */
static inline void EFLASH_setLockConfig(EFLASH_Type *base, EFLASH_ModeStatus_t b_enable)
{
    assert(EFLASH_baseIsValid(base));

    base->CFGb.LCK_CFG = b_enable;
}

/*!
 * \brief Set EFLASH Read Mode
 *
 * \details Configures the read mode of the EFLASH memory.
 *
 * \param[in] base Pointer to the EFLASH peripheral base address for mode control.
 * \param[in] speed Enumerated value specifying the desired read mode.
 *
 * \note Different read modes may impact performance and power consumption.
 *
 * \warning Incorrect read mode selection could degrade performance.
 */
static inline void EFLASH_setReadMode(EFLASH_Type *base, EFLASH_ReadSpeed_t speed)
{
    assert(EFLASH_baseIsValid(base));

    base->CFGb.LVCTL_CFG = speed;
}

/*!
 * \brief Set Operation Address for EFLASH
 *
 * \details Configures the address from which the next EFLASH operation (read, write, etc.) will commence.
 *
 * \param[in] base Pointer to the EFLASH peripheral base address for control.
 * \param[in] op_address The address to set as the starting point for the upcoming operation.
 *
 * \note Ensure the address is within the valid range of the EFLASH memory map.
 *
 * \warning Incorrect address may result in operation failure or memory access errors.
 */
static inline void EFLASH_setOperateAddress(EFLASH_Type *base, volatile uint32_t op_address)
{
    assert(EFLASH_baseIsValid(base));

    base->WR_ADDRb.OP_ADDR = op_address;
} 
 
/*!
 * \brief Write Data to EFLASH
 *
 * \details Writes a 64-bit data value to the EFLASH memory at the current write address.
 *
 * \param[in] base Pointer to the EFLASH peripheral base address for memory access.
 * \param[in] data The 64-bit data to be written into the EFLASH.
 *
 * \note Ensure EFLASH is enabled for writing and the write address is set correctly.
 *
 * \warning Writing without proper setup can lead to undefined behavior or data corruption.
 */
static inline void EFLASH_writeData(EFLASH_Type *base, uint64_t data)
{
    assert(EFLASH_baseIsValid(base));

    base->WR_DATA2b.WR_DATA_L = (uint32_t) (data & 0xFFFFFFFF);
    base->WR_DATA1b.WR_DATA_H = (uint32_t) ((data >> 32) & 0xFFFFFFFF);
} 

/*!
 * \brief Set Security Key Value for EFLASH Operations
 *
 * \details Configures the security key value used for protected operations in the EFLASH memory.
 *
 * \param[in] base Pointer to the EFLASH peripheral base address for controlling security features.
 * \param[in] e_key_value Enumerated value specifying the security key to be set (\ref EFLASH_KeyValue_t).
 *
 * \note Incorrect key values may restrict access to secure operations or trigger security mechanisms.
 *
 * \warning Use with care; misconfiguring security keys can lead to data protection issues or lockout situations.
 */
static inline void EFLASH_setKeyValue(EFLASH_Type *base, EFLASH_KeyValue_t e_key_value)
{
    assert(EFLASH_baseIsValid(base));
 
    base->KEY_VALUE = e_key_value;
}

/*!
 * \brief Read a Double Word from EFLASH
 *
 * \details Reads a single 64-bit double word from the EFLASH memory at the current read address.
 *
 * \param[in] base Pointer to the EFLASH peripheral base address for memory access.
 *
 * \return Returns the read 64-bit double word value.
 *
 * \note Ensure the read address is properly set and EFLASH is in a readable state.
 */
static inline uint64_t EFLASH_readDword(EFLASH_Type *base)
{
    uint64_t read_data;
    assert(EFLASH_baseIsValid(base));

    read_data = 0;
    read_data = ((uint64_t)(base->READ_OUTPUT_H) << 32) & (0xFFFFFFFF00000000);
    read_data |= (uint64_t)(base->READ_OUTPUT_L);

    return read_data;
}

/*!
 * \brief Initialize EFLASH Configuration Register Set Time Configuration
 *
 * \details This function is responsible for configuring the timing parameters 
 *          associated with setting the EFLASH configuration registers.
 *
 * \param[in] base Pointer to the EFLASH peripheral base address.
 * \param[in] p_set_reg_cfg Pointer to the Configuration Register Set time configuration. 
 * 
 */
static inline void EFLASH_timeForSetCfgRegInit(EFLASH_Type *base, EFLASH_Timing_ConfigReg_t *p_set_reg_cfg)
{
    assert(EFLASH_baseIsValid(base));

    base->NVR_CFGb.TACC_NVR = p_set_reg_cfg->nvr_cfg_tACC_NVR;   // 16bit
    base->NVR_CFGb.TMS = p_set_reg_cfg->nvr_cfg_tMS;   // 16bit

    base->SET_CFG1b.TCFH = p_set_reg_cfg->set_cfg_reg_tCFH;   // 8bit
    base->SET_CFG1b.TCFL = p_set_reg_cfg->set_cfg_reg_tCFL;   // 16bit

    base->SET_CFG2b.TCONFEN = p_set_reg_cfg->set_cfg_reg_tCONFEN;   // 8bit (3 bit) 
}

/*!
 * \brief Enable EFLASH-related Interrupts in the Nested Vector Interrupt Controller (NVIC)
 *
 * \details This function enables the interrupts associated with the EFLASH peripheral. 
 *
 * \note The specific interrupts enabled by this function.
 *
 * \param[in] base Pointer to the EFLASH peripheral base address.
 *
 * \warning It is crucial to ensure proper interrupt handling routines.
 */
void EFLASH_enableNVICInterrupe(EFLASH_Type *base);

/*!
 * \brief Set Priority Levels for EFLASH Interrupts
 *
 * \details This function configures the priority levels of the EFLASH interrupts.
 *
 * \param[in] base Pointer to the EFLASH peripheral base address.
 * \param[in] preempt_priority Preemptive priority level. 
 * \param[in] sub_priority Subpriority level within the same preemptive priority group. 
 *
 * \note The valid range for priority levels depends on the specific MCU architecture. 
 *
 * \warning Incorrect configuration of interrupt priorities can lead to system instability.
 */
void EFLASH_setInterruptPriority(EFLASH_Type *base, uint32_t preempt_priority, uint32_t sub_priority);

/*!
 * \brief Check and Clear EFLASH Interrupt Flags
 *
 * \details This function inspects the status of interrupt flags associated with the EFLASH peripheral. 
 *
 * \param[in] base Pointer to the EFLASH peripheral base address.
 *
 * \note The specific flags checked and cleared by this function are hardware-dependent.
 *
 */
void EFLASH_intFlagCheck(EFLASH_Type *base);

/*!
 * \brief Initialize EFLASH Module with Custom Configuration
 *
 * \details This function initializes the EFLASH module with a set of configurations provided by the user. 
 *
 * \param[in] base Pointer to the EFLASH peripheral base address.
 * \param[in] p_eflash_init_cfg Pointer to a structure containing the initialization configuration settings for EFLASH.
 *
 * \note The `EFLASH_Timing_t` structure typically includes fields for various configuration parameters. 
 *
 */
void EFLASH_configInit(EFLASH_Type *base, EFLASH_Timing_t *p_eflash_init_cfg);

/*!
 * \brief Initialize EFLASH Module Clock to 5 MHz
 *
 * \details This function specializes in initializing the EFLASH module's clock.
 *
 * \param[in] base Pointer to the EFLASH peripheral base address.
 *
 * \note The function internally determines the appropriate clock source.
 *
 *
 * \warning The availabilityof this function depend on the system's clock.
 */
void EFLASH_initClock5MHz(EFLASH_Type *base);

/*!
 * \brief Initialize EFLASH Module Clock with PLL Clock Frequency
 *
 * \details This function configures the clock source for the EFLASH module. 
 *          Proper clock is crucial at the correct speed and meets timing requirements.
 *
 * \param[in] base Pointer to the EFLASH peripheral base address.
 * \param[in] pllclk The frequency of the PLL clock in Hz, used to derive the EFLASH module's clock.
 *
 * \note The actual implementation of clock control may involve frequency scaling, dividers, 
 *       or other clock tree management, which are hardware-specific. 
 *
 * \warning Incorrect clock configuration can lead to timing violations or module malfunction.
 */
void EFLASH_initClock(EFLASH_Type *base, uint32_t pllclk);

/*!
 * \brief Retrieve the Current State of the EFLASH Module
 *
 * \details This function queries the EFLASH module to determine its current operational state. 
 *
 * \param[in] base Pointer to the EFLASH peripheral base address.
 *
 * \return EFLASH_Status_t: An enumeration representing the current state. 
 *
 * \note The exact enumeration `EFLASH_Status_t`.
 */
EFLASH_Status_t EFLASH_getCurrentState(EFLASH_Type *base);

/*!
 * \brief Perform a Software Reset on the EFLASH Module
 *
 * \details This function initiates a software-controlled reset of the EFLASH module.
 *
 * \param[in] base Pointer to the EFLASH peripheral base address.
 *
 * \note A software reset can be useful for recovery from error conditions.
 *
 * \warning Issuing a software reset may discard unsaved data or interrupt ongoing operations. 
 */
void EFLASH_softwareReset(EFLASH_Type *base);

/*!
 * \brief Generate Memory Address for EFLASH Operations
 *
 * \details This function computes the physical address within the EFLASH memory space.

 * \param[in] base Pointer to the EFLASH peripheral base address.
 * \param[in] e_type Enum specifying the target operation type .
 * \param[in] sector_num The sector number within the EFLASH memory map.
 * \param[in] row_num The row number within the selected sector.
 * \param[in] word_num The word number within the selected row.

 * \return uint32_t: The calculated absolute memory address corresponding to the given parameters.

 * \note The `EFLASH_Operate_t` enum and its valid entries should be predefined

 * \warning Ensure the provided parameters are within the valid ranges.
 */
uint32_t EFLASH_generateAddress(EFLASH_Type *base, EFLASH_Operate_t e_type, uint16_t sector_num, uint8_t row_num,
                                uint8_t word_num);

/*!
 * \brief Enable EFLASH Module Interrupt
 *
 * \details This function enables a specific interrupt type within the EFLASH module.
 *
 * \param[in] base Pointer to the EFLASH peripheral base address.
 * \param[in] intType Enumerated value specifying which EFLASH interrupt to enable.
 *
 * \note The `EFLASH_InterruptType_t` enum enumerates all possible interrupt sources. 
 *
 * \warning Enabling interrupts without a properly configured ISR.
 */
void EFLASH_enableInterrupt(EFLASH_Type *base, EFLASH_InterruptType_t intType);

/*!
 * \brief Perform AHB Read of Bytes from EFLASH Memory
 *
 * \details This function facilitates a high-speed AHB (Advanced High-performance Bus) .
 *
 * \param[in] base Pointer to the EFLASH peripheral base address.
 * \param[in] e_op_type Enum indicating the type of operation or addressing mode.
 * \param[out] p_read_buff Pointer to the buffer in RAM where the read data will be stored.
 * \param[in] read_address The starting address in the EFLASH memory space.
 * \param[in] lens The number of bytes to read from the EFLASH memory.
 *
 * \note Its presence could be for future extensibility or to maintain consistency across function interfaces.
 *
 * \warning Ensure the read buffer (`p_read_buff`) is large enough. 
 */
void EFLASH_ahbReadBytes(EFLASH_Type *base, EFLASH_Operate_t e_op_type, uint8_t *p_read_buff,
                         volatile uint32_t read_address, uint32_t lens);

/*!
 * \brief Perform AHB Read of Words from EFLASH Memory
 *
 * \details This function executes an efficient AHB (Advanced High-performance Bus).
 *
 * \param[in] base Pointer to the EFLASH peripheral base address.
 * \param[in] e_op_type Enumerated value indicating the operation type.
 * \param[out] p_read_buff Pointer to the buffer in RAM.
 * \param[in] read_address The starting address within the EFLASH memory.
 * \param[in] lens The number of 32-bit words to be read from the EFLASH memory.
 *
 * \note The function assumes word alignment both read_address and  p_read_buff.
 *
 * \warning The caller must ensure that `p_read_buff` points to a valid memory region.
 */
void EFLASH_ahbReadWords(EFLASH_Type *base, EFLASH_Operate_t e_op_type, uint32_t *p_read_buff,
                         volatile uint32_t read_address, uint32_t lens);

/*!
 * \brief Perform AHB Read of Double Words from EFLASH Memory
 *
 * \details This function performs a high-speed AHB (Advanced High-performance Bus).
 *
 * \param[in] base Pointer to the EFLASH peripheral base address.
 * \param[in] e_op_type Enumerated value indicating the operation type.
 * \param[out] p_read_buff Pointer to the buffer in RAM.
 * \param[in] read_address The starting memory address in the EFLASH.
 * \param[in] lens The number of 64-bit double words to be read from the EFLASH memory.
 *
 * \note The function presumes double-word alignment. 
 *
 * \warning Ensure that `p_read_buff` points to a suitably allocated memory region.
 */
void EFLASH_ahbReadDwords(EFLASH_Type *base, EFLASH_Operate_t e_op_type, uint64_t *p_read_buff,
                          volatile uint32_t read_address, uint32_t lens);

/*!
 * \brief Erase a Sector within the EFLASH Memory
 *
 * \details This function initiates an erase operation on a specified sector.
 *
 * \param[in] base Pointer to the EFLASH peripheral base address.
 * \param[in] e_op_type Enumerated value specifying the erase operation type.
 * \param[in] erase_address The starting address of the sector to erase..
 *
 * \return bool: Returns `true` upon successfully initiating the erase operation.
 *
 * \note The actual erase operation may take some time to complete
 *
 * \warning Ensure the sector is not currently in use and that all necessary data .
 */
bool EFLASH_eraseSector(EFLASH_Type *base, EFLASH_Operate_t e_op_type, uint32_t erase_address);

/*!
 * \brief Perform a Chip Erase on the Entire EFLASH Memory
 *
 * \details This function initiates a chip erase operation on the entire EFLASH memory.
 *
 * \param[in] base Pointer to the EFLASH peripheral base address.
 * \param[in] e_chip_erase_type Enumerated value specifying the type of chip erase to perform. .
 *
 * \note The `EFLASH_EraseType_t` enum should be defined to enumerate the supported chip erase.
 *
 * \warning Executing a chip erase will irrevocably delete all data stored in the EFLASH memory. .
 */
void EFLASH_eraseChip(EFLASH_Type *base, EFLASH_EraseType_t e_chip_erase_type);

/*!
 * \brief Validate Read Operation from EFLASH Memory
 *
 * \details This function verifies the integrity of a read operation. 
 *
 * \param[in] base Pointer to the EFLASH peripheral base address.
 * \param[in] e_op_type Enumerated value specifying the type of operation or verification context. 
 * \param[in] vread_address The starting address in the EFLASH memory.
 *
 * \return bool: Returns `true` if the read operation is deemed valid, `false` otherwise.
 *
 * \note The actual implementation of validation logic within `EFLASH_vreadIsOk` is not specified here .
 *
 * \warning Depending on the system's design, misuse of this function .
 */
bool EFLASH_vreadIsOk(EFLASH_Type *base, EFLASH_Operate_t e_op_type, uint32_t vread_address);

/*!
 * \brief Perform AHB Write of Bytes to EFLASH Memory
 *
 * \details This function writes a sequence of bytes from a buffer in RAM to the EFLASH memory.
 *
 * \param[in] base Pointer to the EFLASH peripheral base address.
 * \param[in] e_op_type Enumerated value indicating the operation type.
 * \param[in] p_write_buff Pointer to the buffer in RAM containing the data.
 * \param[in] write_address The starting address in the EFLASH memory.
 * \param[in] lens The number of bytes to be written to the EFLASH memory.
 *
 * \note The function assumes the write address and length are properly aligned.
 *
 * \warning Ensure the EFLASH is properly configured for writing.
 */
void EFLASH_ahbWriteBytes(EFLASH_Type *base, EFLASH_Operate_t e_op_type, uint8_t *p_write_buff,
                          volatile uint32_t write_address, uint32_t lens);

/*!
 * \brief Perform AHB Write of Words to EFLASH Memory
 *
 * \details This function leverages the Advanced High-performance Bus (AHB) interface.
 *
 * \param[in] base Pointer to the EFLASH peripheral base address.
 * \param[in] e_op_type Enumerated value denoting the operation type.
 * \param[in] p_write_buff Pointer to the buffer in RAM.
 * \param[in] write_address The initial address in the EFLASH memory.
 * \param[in] lens The number of 32-bit words to be sequentially written to the EFLASH.
 *
 * \note The write address and length should adhere to the alignment.
 *
 * \warning Prior to calling this function, ensure the EFLASH is unlocked for write operations.
 */
void EFLASH_ahbWriteWords(EFLASH_Type *base, EFLASH_Operate_t e_op_type, uint32_t *p_write_buff,
                          volatile uint32_t write_address, uint32_t lens);

/*!
 * \brief Perform AHB Write of Double Words to EFLASH Memory
 *
 * \details This function utilizes the Advanced High-performance Bus (AHB).
 *
 * \param[in] base Pointer to the EFLASH peripheral base address.
 * \param[in] e_op_type Enumerated value signifying the operation type
 * \param[in] p_write_buff Pointer to the buffer in RAM.
 * \param[in] write_address The starting address in the EFLASH memory.
 * \param[in] lens The number of 64-bit double words the EFLASH memory.
 *
 * \note The write operation assumes the address and length are correctly.
 *
 * \warning It is imperative to confirm that the EFLASH is unlocked.
 */
void EFLASH_ahbWriteDwords(EFLASH_Type *base, EFLASH_Operate_t e_op_type, uint64_t *p_write_buff,
                           volatile uint32_t write_address, uint32_t lens);

/*!
 * \brief Enable Replacement of RDN (Read Disturb Noise) Sector in EFLASH
 *
 * \details This function configures a specific sector within the EFLASH to be used as a replacement
 *
 * \param[in] base Pointer to the EFLASH peripheral base address.
 * \param[in] rdn_num An identifier for the RDN sector to be replaced. 
 * \param[in] replace_address The starting address of the replacement sector in the EFLASH memory. 
 *
 * \note The exact mechanism for replacing RDN sectors and the way `rdn_num` is interpreted.
 *
 * \warning Misconfiguration or incorrect use of this function can lead to data loss.
 */
void EFLASH_enableReplaceRDNSector(EFLASH_Type *base, uint8_t rdn_num, uint32_t replace_address);

/*!
 * \brief Disable Replacement of RDN (Read Disturb Noise) Sector in EFLASH
 *
 * \details This function reverses the action of enabling a replacement sector.
 *
 * \param[in] base Pointer to the EFLASH peripheral base address.
 * \param[in] rdn_num Identifier for the RDN sector whose replacement is to be disabled. 
 *
 * \note Disabling the replacement does not automatically restore data from the replacement.
 *
 * \warning Before disabling the replacement, ensure that the original sector.
 */
void EFLASH_disableReplaceRDNSector(EFLASH_Type *base, uint8_t rdn_num);

/*!
 * \brief Enable Protection for a Specified Area in EFLASH Memory
 *
 * \details This function configures a range of addresses to be write-protected.
 *
 * \param[in] base Pointer to the EFLASH peripheral base address.
 * \param[in] start_address The starting address of the memory region to be protected.
 * \param[in] end_address The ending address of the memory region to be protected.
 *
 * \note The function assumes that the provided address range is valid.
 *
 * \warning Incorrect usage, such as attempting to protect a region.
 */
void EFLASH_enableProtectArea(EFLASH_Type *base, uint32_t start_address, uint32_t end_address);

/*!
 * \brief Disable Protection for the Entire EFLASH Memory
 *
 * \details This function disables write protection for the entire EFLASH memory
 *
 * \param[in] base Pointer to the EFLASH peripheral base address.
 *
 * \note Disabling protection for the entire memory can expose sensitive data. 
 *
 * \warning Use this function cautiously, as it lifts all write restrictions
 */
void EFLASH_disableProtectArea(EFLASH_Type *base);

/*!
 * \brief Enter Deep Power Down Mode for EFLASH Memory
 *
 * \details This function initiates the Deep Power Down (DPD) mode for the EFLASH memory module
 *
 * \param[in] base Pointer to the EFLASH peripheral base address.
 *
 * \note Enabling Deep Power Down mode might require specific preconditions
 *
 * \warning Before invoking this function, ensure that all critical data has been saved.
 */
void EFLASH_enableDeepPowerDown(EFLASH_Type *base);

/*!
 * \brief Exit Deep Power Down Mode for EFLASH Memory
 *
 * \details This function brings the EFLASH memory out of the Deep Power Down (DPD) mode
 *
 * \param[in] base Pointer to the EFLASH peripheral base address
 *
 * \note Exiting Deep Power Down mode might involve an automatic or manual refresh.
 *
 * \warning Ensure that the system is prepared to handle any delays.
 */
void EFLASH_disableDeepPowerDown(EFLASH_Type *base);

/*!
 * \brief Set Configuration Register for EFLASH Memory
 *
 * \details This function allows programming of a specified configuration register. 
 *
 * \param[in] base Pointer to the EFLASH peripheral base address.
 * \param[in] cfg_reg_addr Enumerated address specifying the target. 
 * \param[in] data A 64-bit value containing the configuration data to be written . 
 *
 * \note Incorrect configuration can lead to unexpected behavior or even loss of data. 
 *
 * \warning Exercise caution when modifying configuration registers
 */
void EFLASH_setConfigReg(EFLASH_Type *base, EFLASH_ConfigReg_t cfg_reg_addr, uint64_t data);

/*!
 * \brief Set EFLASH Execution Priority
 *
 * \details Configures the execution priority level for the EFLASH (Embedded FLASH) module. 
 * 
 * \param[in] base Pointer to the EFLASH module base address. 
 * \param[in] priority Enumerated value from `EFLASH_ExePriority_t`. 
 *
 * \note Changing the execution priority can have significant effects on system timing and responsiveness. 
 */
static inline void EFLASH_setExecutePriority(EFLASH_Type *base, EFLASH_ExePriority_t priority)
{
    assert(EFLASH_baseIsValid(base));

    base->CFGb.AXI_CMD_PRIORITY = priority;
}

/*!
 * \brief Enable EFLASH Recall Mode
 *
 * \details Activates Recall Mode for EFLASH.
 *
 * \param[in] base EFLASH peripheral base address for control.
 * \param[in] e_op_type Specifies the target EFLASH area for recall (\ref EFLASH_Operate_t).
 *
 * \note Recall may cause a delay before memory is accessible.
 *
 * \warning Use correct \ref EFLASH_Operate_t to avoid data inconsistencies.
 */
static inline void EFLASH_enableRecallMode(EFLASH_Type *base, EFLASH_Operate_t e_op_type)
{
    assert(EFLASH_baseIsValid(base));

    switch (e_op_type)
    {
        case kEFLASH_NVR_SECTOR:
        case kEFLASH_NVR_CFG_SECTOR:
            if (0 == base->CFGb.RECALL)
            {
                base->CFGb.RECALL = 1;
            }
            break;

        default:
            if (1 == base->CFGb.RECALL)
            {
                base->CFGb.RECALL = 0;
            }
            break;
    }   
}

/*!
 * \brief Disable EFLASH Recall Mode
 *
 * \details Halts the EFLASH memory's Recall Mode, stopping data restoration mid-process if active.
 *
 * \param[in] base EFLASH peripheral base address for control.
 *
 * \note Use cautiously to avoid interrupting critical data recall.
 */
static inline void EFLASH_disableRecallMode(EFLASH_Type *base)
{
    assert(EFLASH_baseIsValid(base));

    base->CFGb.RECALL = 0;
}

/*!
 * \brief Enable AXI Operation Mode for EFLASH Memory
 *
 * \details EFLASH memory controller to operate in AXI (Advanced eXtensible Interface) mode.
 *
 * \param[in] base Pointer to the EFLASH peripheral base address.
 *
 * \note Switching to AXI mode can significantly enhance throughput.
 *
 * \warning Ensure that the entire system, including peripherals and software drivers.
 */
void EFLASH_enableAXIOperate(EFLASH_Type *base);

/*!
 * \brief Disable AXI Operation Mode for EFLASH Memory
 *
 * \details EFLASH memory controller to exit AXI (Advanced eXtensible Interface) mode.
 *
 * \param[in] base Pointer to the EFLASH peripheral base address.
 *
 * \note Disabling AXI mode may reduce data transfer speeds.
 *
 * \warning Ensure that ongoing transactions or processes that rely on AXI features.
 */
void EFLASH_disableAXIOperate(EFLASH_Type *base);

/*!
 * \brief Read EFLASH Data via AXI
 *
 * \details Reads 'lens' bytes from EFLASH starting at 'read_address', storing them in 'p_read_buff'.
 *
 * \param[in] base EFLASH base address for control.
 * \param[out] p_read_buff Buffer to store read data.
 * \param[in] read_address Start read address in EFLASH.
 * \param[in] lens Number of bytes to read.
 *
 * \note Check buffer size matches 'lens' and validate read address range.
 */
void EFLASH_readAXIMainArrayBytes(EFLASH_Type *base, uint8_t *p_read_buff, volatile uint32_t read_address,
                                  uint32_t lens);

/*!
 * \brief Read Half-Words from EFLASH via AXI Interface
 *
 * \details Reads 'lens' half-words (16-bit) from EFLASH starting at 'read_address', storing them in 'p_read_buff'.
 *
 * \param[in] base EFLASH peripheral base address for control.
 * \param[out] p_read_buff Buffer to store read half-words. Ensure proper alignment.
 * \param[in] read_address Start read address in EFLASH main array.
 * \param[in] lens Number of half-words to read.
 *
 * \note Buffer must accommodate 'lens' half-words and address must be half-word aligned.
 *
 * \warning Verify that read operation stays within EFLASH memory bounds.
 */
void EFLASH_readAXIMainArrayHwords(EFLASH_Type *base, uint16_t *p_read_buff, volatile uint32_t read_address,
                                   uint32_t lens);

/*!
 * \brief Read Words from EFLASH Main Array via AXI
 *
 * \details Reads 'lens' words (32-bit) from EFLASH starting at 'read_address', storing them in 'p_read_buff'.
 *
 * \param[in] base EFLASH peripheral base address for interface control.
 * \param[out] p_read_buff Buffer receiving read words. Ensure 4-byte alignment.
 * \param[in] read_address Start read address within EFLASH main memory.
 * \param[in] lens Number of words to read.
 *
 * \note Ensure the buffer can hold 'lens' words and 'read_address' is word-aligned.
 *
 * \warning Validate that read operation doesn't exceed EFLASH boundaries.
 */
void EFLASH_readAXIMainArrayWords(EFLASH_Type *base, uint32_t *p_read_buff, volatile uint32_t read_address,
                                  uint32_t lens);

/*!
 * \brief Read Double Words from EFLASH via AXI Interface
 *
 * \details Reads 'lens' double words (64-bit) from EFLASH starting at 'read_address', storing them in 'p_read_buff'.
 *
 * \param[in] base EFLASH peripheral base address for control.
 * \param[out] p_read_buff Buffer for double words read data. Ensure 8-byte alignment.
 * \param[in] read_address Start address in EFLASH for read operation.
 * \param[in] lens Number of double words to read.
 *
 * \note Buffer size must fit 'lens' double words and 'read_address' must be 8-byte aligned.
 *
 * \warning Confirm the read operation stays within the EFLASH memory limits.
 */
void EFLASH_readAXIMainArrayDWords(EFLASH_Type *base, uint64_t *p_read_buff, volatile uint32_t read_address,
                                   uint32_t lens);

/*!
 * \brief Write Bytes to EFLASH Main Array via AXI
 *
 * \details Writes 'lens' bytes from 'p_write_buff' to EFLASH starting at 'write_address'.
 *
 * \param[in] base EFLASH peripheral base address for interface control.
 * \param[in] p_write_buff Buffer containing bytes to write.
 * \param[in] write_address Start write address in EFLASH main memory.
 * \param[in] lens Number of bytes to write.
 *
 * \note Ensure data buffer is valid and 'write_address' is properly aligned for byte writes.
 *
 * \warning Confirm the write operation doesn't exceed the EFLASH memory size and that EFLASH is unlocked for writes.
 */
void EFLASH_writeAXIMainArrayBytes(EFLASH_Type *base, uint8_t *p_write_buff, volatile uint32_t write_address,
                                   uint32_t lens);

/*!
 * \brief Write Half-Words to EFLASH via AXI
 *
 * \details Writes 'lens' half-words (16-bit) from 'p_write_buff' to EFLASH starting at 'write_address'.
 *
 * \param[in] base EFLASH peripheral base address for control.
 * \param[in] p_write_buff Buffer with half-words to write.
 * \param[in] write_address Start address in EFLASH for write operation.
 * \param[in] lens Number of half-words to write.
 *
 * \note Buffer must contain valid data, and 'write_address' should be half-word aligned.
 *
 * \warning Verify the write operation stays within EFLASH boundaries and that write protection is disabled.
 */
void EFLASH_writeAXIMainArrayHwords(EFLASH_Type *base, uint16_t *p_write_buff, volatile uint32_t write_address,
                                    uint32_t lens);

/*!
 * \brief Write Words to EFLASH Main Array via AXI
 *
 * \details Writes 'lens' words (32-bit) from 'p_write_buff' to EFLASH starting at 'write_address'.
 *
 * \param[in] base EFLASH peripheral base address for interface control.
 * \param[in] p_write_buff Buffer of words to be written.
 * \param[in] write_address Starting write address within EFLASH.
 * \param[in] lens Number of words to write.
 *
 * \note Ensure the write buffer is valid, word-aligned, and the write operation fits within EFLASH memory.
 *
 * \warning Confirm EFLASH is not write-protected before executing this function.
 */
void EFLASH_writeAXIMainArrayWords(EFLASH_Type *base, uint32_t *p_write_buff, volatile uint32_t write_address,
                                   uint32_t lens);

/*!
 * \brief Write Double Words to EFLASH Main Array via AXI
 *
 * \details Writes 'lens' double words (64-bit) from 'p_write_buff' to EFLASH starting at 'write_address'.
 *
 * \param[in] base EFLASH peripheral base address for control.
 * \param[in] p_write_buff Buffer containing double words to write.
 * \param[in] write_address Starting write address in the EFLASH memory.
 * \param[in] lens Number of double words to write.
 *
 * \note Buffer must hold valid double words, and 'write_address' should be 8-byte aligned.
 *
 * \warning Ensure the write operation doesn't exceed EFLASH boundaries and that EFLASH is configured for writes.
 */
void EFLASH_writeAXIMainArrayDwords(EFLASH_Type *base, uint64_t *p_write_buff, volatile uint32_t write_address,
                                    uint32_t lens);

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */ /* end of DRV_HTE_EFLASH */

#endif /* HTE_EFLASH_H */
