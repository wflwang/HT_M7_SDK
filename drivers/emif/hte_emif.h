/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*!
 * \file hte_emif.h
 * \brief SDK EMIF driver header file
 * \version 1.0.0
 */

#ifndef HTE_EMIF_H
#define HTE_EMIF_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_common.h"

/*!
 * \addtogroup DRV_HTE_EMIF EMIF Driver
 *
 * \brief SDK EMIF driver
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! \brief EMIF index identification */
typedef enum
{
    kEMIF1 = 0U, /*!< EMIF Module 0 */
    kEMIF_MAX = 1U, /*!< EMIF Module Max */
} EMIF_Idx_t;

/*! \brief EMIF enable/disable enumeration */
typedef enum
{
    kEMIF_DISABLE = 0U, /*!< Disable the EMIF interface */
    kEMIF_ENABLE = 1U, /*!< Enable the EMIF interface */
} EMIF_En_t;

/*! \brief Values that can be passed to EMIF_setAsyncMode(),
 * EMIF_setAsyncTimingParams(), EMIF_setAsyncDataBusWidth(),
 * EMIF_enableAsyncExtendedWait() and EMIF_disableAsyncExtendedWait()
 * as the offset parameter. */
typedef enum
{
    kEMIF_ASYNC_CS2_OFFSET = 0U, /*!< Async chip select 2 offset */
    kEMIF_ASYNC_CS3_OFFSET = 1U, /*!< Async chip select 3 offset */
    kEMIF_ASYNC_CS4_OFFSET = 2U, /*!< Async chip select 4 offset */
} EMIF_AsyncCSOffset_t;


/*! \brief Values that can be passed to EMIF_setAsyncDataBusWidth() as the
 * width parameter. */
typedef enum
{
    kEMIF_ASYNC_DATA_WIDTH_8  = 0U, /*!< ASRAM/FLASH with 8 bit data bus */
    kEMIF_ASYNC_DATA_WIDTH_16 = 1U, /*!< ASRAM/FLASH with 16 bit data bus */
    kEMIF_ASYNC_DATA_WIDTH_32 = 2U, /*!< ASRAM/FLASH with 32 bit data bus */
} EMIF_AsyncDataWidth_t;

/*! \brief Values that can be passed to EMIF_setAsyncMode() as the 
 * mode parameter. */
typedef enum
{
    kEMIF_ASYNC_NORMAL_MODE = 0U, /*!< Enables ASRAM/FLASH strobe mode */
    kEMIF_ASYNC_STROBE_MODE = 1U  /*!< Disables ASRAM/FLASH strobe mode */
} EMIF_AsyncMode_t;

/*! \brief Values that can be passed to EMIF_setAsyncWaitPolarity() as the
 * polarity parameter. */
typedef enum
{
    kEMIF_ASYNC_WAIT_POLARITY_LOW  = 0U, /*!< EMxWAIT pin polarity is low */
    kEMIF_ASYNC_WAIT_POLARITY_HIGH = 1U  /*!< EMxWAIT pin polarity is high */
} EMIF_AsyncWaitPolarity_t;

/*! \brief Values that can be passed to EMIF_selectController() as the
 * select parameter. */
typedef enum
{
    kEMIF_CONTROLLER_BOTH = 0U, /*!< Both CPU1CPU2 are controller */
    kEMIF_CONTROLLER_CPU2 = 1U, /*!< CPU2 is controller, CPU1 is not controller */
    kEMIF_CONTROLLER_CPU1 = 2U, /*!< CPU1 is controller, CPU2 is not controller */
    kEMIF_CONTROLLER_NONE = 3U, /*!< Both CPU1CPU2 are not controller */
} EMIF_ControllerSelect_t;

/*! \brief Values that can be passed to EMIF_setSyncMemoryConfig() as the
 * config parameter member. */
typedef enum
{
    kEMIF_SYNC_NARROW_MODE_FALSE = 0U, /*!< MemBusWidth=SystemBusWidth(32bit) */
    kEMIF_SYNC_NARROW_MODE_TRUE  = 1U  /*!< MemBusWidth=SystemBusWidth/2(16bit) */
} EMIF_SyncNarrowMode_t;

/*! \brief Values that can be passed to EMIF_setSyncMemoryConfig() as the
 * config parameter member. */
typedef enum
{
    kEMIF_SYNC_BANK_1 = 0U, /*!< 1 Bank SDRAM device */
    kEMIF_SYNC_BANK_2 = 1U, /*!< 2 Bank SDRAM device */
    kEMIF_SYNC_BANK_4 = 2U  /*!< 4 Bank SDRAM device */
} EMIF_SyncBank_t;

/*! \brief Values that can be passed to EMIF_setSyncMemoryConfig() as the
 * config parameter member. */
typedef enum
{
    kEMIF_SYNC_CAS_LAT_2 = 2U, /*!< SDRAM with CAS Latency 2 */
    kEMIF_SYNC_CAS_LAT_3 = 3U  /*!< SDRAM with CAS Latency 3 */
} EMIF_SyncCASLatency_t;

/*! \brief Values that can be passed to EMIF_setSyncMemoryConfig() as the
 * config parameter member. */
typedef enum
{
    kEMIF_SYNC_COLUMN_WIDTH_8  = 0U, /*!< 256-word pages in SDRAM */
    kEMIF_SYNC_COLUMN_WIDTH_9  = 1U, /*!< 512-word pages in SDRAM */
    kEMIF_SYNC_COLUMN_WIDTH_10 = 2U, /*!< 1024-word pages in SDRAM */
    kEMIF_SYNC_COLUMN_WIDTH_11 = 3U  /*!< 2048-word pages in SDRAM */
} EMIF_SyncPageSize_t;

/*! \brief Values that can be passed to EMIF_setAsyncTimingParams() as the
 * tParam parameter. */
typedef struct
{
    uint32_t rSetup;   /*!< Read Setup Cycles */
    uint32_t rStrobe;  /*!< Read Strobe Cycles */
    uint32_t rHold;    /*!< Read Hold Cycles */
    uint32_t wSetup;   /*!< Write Setup Cycles */
    uint32_t wStrobe;  /*!< Write Strobe Cycles */
    uint32_t wHold;    /*!< Write Hold Cycles */
    uint32_t turnArnd; /*!< TurnAround Cycles */
} EMIF_AsyncTimingParams_t;

/*! \brief Values that can be passed to EMIF_setSyncMemoryConfig() as the
 * config parameter. */
typedef struct
{
    EMIF_SyncNarrowMode_t narrowMode; /*!< Read Setup Cycles */
    EMIF_SyncBank_t       iBank;      /*!< Banks available in SDRAM device */
    EMIF_SyncCASLatency_t casLatency; /*!< CAS Latency for SDRAM device */
    EMIF_SyncPageSize_t   pageSize;   /*!< Pagesize of SDRAM device */
} EMIF_SyncConfig_t;

/*! \brief Values that can be passed to EMIF_setSyncTimingParameters() as the
 * tParam parameter. */
typedef struct
{
    uint32_t tRfc; /*!< Auto refresh time */
    uint32_t tRp;  /*!< Row precharge time */
    uint32_t tRcd; /*!< RAS to CAS delay */
    uint32_t tWr;  /*!< Write recovery time */
    uint32_t tRas; /*!< Row active time */
    uint32_t tRc;  /*!< Read cycle time */
    uint32_t tRrd; /*!< Row active to row active delay */
} EMIF_SyncTimingParams_t;

/*! \brief index for EMIF IRQ */
typedef enum
{
    kEMIF1_EVT_IRQn = 0, /*!< EMIF INT0 */
    kEMIF_IRQ_MAX_NUM   /*!< emif IRQ Max */
} EMIF_Irq_Idx_t;


/*! \brief type definition for emif callback  */
typedef void (*EMIF_Callback_t)();

/*! \brief type definition for emif interrupt callback  */
typedef struct
{
    EMIF_Callback_t func[kEMIF_MAX][kEMIF_IRQ_MAX_NUM]; /*!< EMIF Callback func */
} EMIF_Int_Callback_t;


/*******************************************************************************
 * APIs
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \name EMIF APIs
 *
 * @{
 */

/*!
 * \brief Checks an EMIF base address.
 *
 * \details This function determines if EMIF module base address is valid.
 *
 * \param[in] base is the base address of the EMIF instance used.
 *
 * \return Returns true if the base address is valid and false otherwise
 */
static inline bool EMIF_isBaseValid(EMIF_Type *base)
{
    return (base == EMIF1);
}


/*!  
 * \brief Selects the EMIF Controller.  
 *  
 * \details This function selects the controller for an EMIF instance among CPU1 or CPU2.  
 *   It is valid only for EMIF1 instance and not for EMIF2 instance.  
 *  
 * \param[in] base The configuration address of the EMIF instance used.  
 *        Valid value for this parameter is EMIF1CONFIG_BASE.  
 *  
 * \param[in]  select The required controller configuration for EMIF1.  
 *   Valid values for this parameter can be EMIF_CONTROLLER_CPU1_NG,  
 *   kEMIF_CONTROLLER_CPU1, kEMIF_CONTROLLER_CPU2 or EMIF_CONTROLLER_CPU1_NG2.  
 *  
 * 
 */
static inline void EMIF_selectController(EMIF_Type *base, EMIF_ControllerSelect_t select)
{
    /*!< Check the arguments. */
    assert(EMIF_isBaseValid(base));

    /*!< Sets the bits that enables EMIF1 controller selection. */
    base->EMIF1MSEL = select;
}

/*!  
 * \brief Sets the access protection for an EMIF instance.  
 *  
 * \details This function configures the access protection for an EMIF instance,  
 *   controlling access from the CPU and DMA.  
 *  
 * \param[in]  base The configuration address of the EMIF instance used.  
 *  
 * \param[in]  access The required access protection configuration.  
 * Valid values for this parameter include EMIF_ACCPROT0_FETCHPROT,  
 * EMIF_ACCPROT0_CPUWRPROT, EMIF_ACCPROT0_DMAWRPROT, or combinations of these.  
 *  
 */
static inline void EMIF_setAccessProtection(EMIF_Type *base, uint16_t access)
{
    uint16_t msk = 0;
    
    /*!< Check the arguments. */
    msk = EMIF_EMIF1ACCROT_DMA0_WRITE_Msk | EMIF_EMIF1ACCROT_DMA0_READ_Msk | EMIF_EMIF1ACCROT_CPU0_WRITE_Msk |
  EMIF_EMIF1ACCROT_CPU0_READ_Msk | EMIF_EMIF1ACCROT_DMA1_WRITE_Msk | EMIF_EMIF1ACCROT_DMA1_READ_Msk |
  EMIF_EMIF1ACCROT_CPU1_WRITE_Msk | EMIF_EMIF1ACCROT_CPU1_READ_Msk;

    assert(EMIF_isBaseValid(base));
    assert(access <= msk);

    /*!< Sets the bits that enables access protection config. */
    base->EMIF1ACCROT = (base->EMIF1ACCROT & (~msk)) | access;
}

/*!
 * \brief Locks the write access to configuration fields.  
 * 
 * \details Locks the write access to configuration fields, specifically the ACCPROT0  
 * and Mselect fields, for an EMIF instance.  
 * 
 * \param[in] base The configuration address of the EMIF instance used.  
 * 
 */ 
static inline void EMIF_lockAccessConfig(EMIF_Type *base)
{

    /* Check the arguments. */
    assert(EMIF_isBaseValid(base));

    /* Sets the bits that locks access protection config. */
    base->EMIF1LOCK |= EMIF_EMIF1LOCK_LOCK_EMIF_Set(kEMIF_ENABLE);
}

/*!  
 * \brief Unlocks write access to configuration fields.  
 *  
 * \details This function unlocks write access to configuration fields, such as  
 * ACCPROT0 and Mselect, for an EMIF instance.  
 *  
 * \param[in] base The configuration address of the EMIF instance.  
 *  
 */
static inline void EMIF_unlockAccessConfig(EMIF_Type *base)
{
    /* Check the arguments. */
    assert(EMIF_isBaseValid(base));

    /* Sets the bits that unlocks access protection config. */
    base->EMIF1LOCK &= ~EMIF_EMIF1LOCK_LOCK_EMIF_Msk;
}

/*!  
 * \brief Selects the asynchronous mode of operation for the EMIF instance.  
 *  
 * \details This function sets the mode of operation for asynchronous memory  
 * between Normal or Strobe mode for a specific EMIF instance.  
 *  
 * \param[in] base The base address of the EMIF instance to be configured.  
 *  
 * \param[in] offset The offset of the asynchronous chip select within the EMIF instance.  
 * Valid values for offset are:  
 * - kEMIF_ASYNC_CS2_OFFSET for EMIF1 and EMIF2  
 * - kEMIF_ASYNC_CS3_OFFSET for EMIF1  
 * - EMIF_ASYNC_C43_OFFSET for EMIF1  
 *  
 * \param[in] mode The desired mode of operation for the external memory.  
 * Valid values for mode are:  
 * - kEMIF_ASYNC_NORMAL_MODE for normal operation  
 * - kEMIF_ASYNC_STROBE_MODE for Strobe mode operation  
 *  
 */
static inline void EMIF_setAsyncMode(EMIF_Type *base, EMIF_AsyncCSOffset_t offset, EMIF_AsyncMode_t mode)
{
    /* Check the arguments. */
    assert(EMIF_isBaseValid(base));

    /* Sets the async mode of operation. */
    if (offset == kEMIF_ASYNC_CS2_OFFSET)
    {
        base->ASYNC_CS2_CR = base->ASYNC_CS2_CR & (~EMIF_ASYNC_CS2_CR_SS_Msk);
        base->ASYNC_CS2_CR = base->ASYNC_CS2_CR | EMIF_ASYNC_CS2_CR_SS_Set(mode);
    }
    else if (offset == kEMIF_ASYNC_CS3_OFFSET)
    {
        base->ASYNC_CS3_CR = base->ASYNC_CS3_CR & (~EMIF_ASYNC_CS3_CR_SS_Msk);
        base->ASYNC_CS3_CR = base->ASYNC_CS3_CR | EMIF_ASYNC_CS3_CR_SS_Set(mode);


    }
    else if (offset == kEMIF_ASYNC_CS4_OFFSET)
    {
        base->ASYNC_CS4_CR = base->ASYNC_CS4_CR & (~EMIF_ASYNC_CS4_CR_SS_Msk);
        base->ASYNC_CS4_CR = base->ASYNC_CS4_CR | EMIF_ASYNC_CS4_CR_SS_Set(mode);
    }
}

/*!
 * \brief Enables the Extended Wait Mode for an asynchronous external memory.  
 *  
 * \details This function enables the extended wait mode for an asynchronous  
 * external memory connected to a specific EMIF instance.  
 *  
 * \param[in] base The base address of the EMIF instance.  
 *  
 * \param[in] offset The offset of the asynchronous chip select within the EMIF instance.  
 * Valid values for offset are:  
 * - kEMIF_ASYNC_CS2_OFFSET for EMIF1 and EMIF2  
 * - kEMIF_ASYNC_CS3_OFFSET for EMIF1  
 * - EMIF_ASYNC_C43_OFFSET for EMIF1  
 *  
 */
static inline void EMIF_enableAsyncExtendedWait(EMIF_Type *base, EMIF_AsyncCSOffset_t offset)
{
    /* Check the arguments. */
    assert(EMIF_isBaseValid(base));

    /* Sets the bit that enables extended wait mode. */
    if (offset == kEMIF_ASYNC_CS2_OFFSET)
    {
        base->ASYNC_CS2_CR = base->ASYNC_CS2_CR | EMIF_ASYNC_CS2_CR_EW_Set(kEMIF_ENABLE);
    }
    else if (offset == kEMIF_ASYNC_CS3_OFFSET)
    {
        base->ASYNC_CS3_CR = base->ASYNC_CS3_CR | EMIF_ASYNC_CS3_CR_EW_Set(kEMIF_ENABLE);
    }
    else if (offset == kEMIF_ASYNC_CS4_OFFSET)
    {
        base->ASYNC_CS4_CR = base->ASYNC_CS4_CR | EMIF_ASYNC_CS4_CR_EW_Set(kEMIF_ENABLE);
    }
}

/*!
 * \brief Disables the Extended Wait Mode for an asynchronous external memory.  
 *  
 * \details This function disables the extended wait mode for an asynchronous external  
 * memory associated with a specific EMIF instance.  
 *  
 * \param[in] base The base address of the EMIF instance to be configured.  
 *  
 * \param[in] offset The offset of the asynchronous chip select within the EMIF instance.  
 * Valid values for offset are:  
 * - kEMIF_ASYNC_CS2_OFFSET for EMIF1 and EMIF2  
 * - kEMIF_ASYNC_CS3_OFFSET for EMIF1  
 * - EMIF_ASYNC_C43_OFFSET for EMIF1  
 *  
 */
static inline void EMIF_disableAsyncExtendedWait(EMIF_Type *base, EMIF_AsyncCSOffset_t offset)
{
    /* Check the arguments. */
    assert(EMIF_isBaseValid(base));

    /* Sets the bit that enables extended wait mode. */
    if (offset == kEMIF_ASYNC_CS2_OFFSET)
    {
        base->ASYNC_CS2_CR = base->ASYNC_CS2_CR & (~EMIF_ASYNC_CS2_CR_EW_Msk);
    }
    else if (offset == kEMIF_ASYNC_CS3_OFFSET)
    {
        base->ASYNC_CS3_CR = base->ASYNC_CS3_CR & (~EMIF_ASYNC_CS3_CR_EW_Msk);
    }
    else if (offset == kEMIF_ASYNC_CS4_OFFSET)
    {
        base->ASYNC_CS4_CR = base->ASYNC_CS4_CR & (~EMIF_ASYNC_CS4_CR_EW_Msk);
    }
}

/*!
 * \brief Sets the wait polarity for an asynchronous external memory.  
 *  
 * \details This function configures the wait polarity of an asynchronous external memory  
 * associated with a specific EMIF instance.  
 *  
 * \param[in] base The base address of the EMIF instance to be configured.  
 *  
 * \param[in] polarity The desired wait polarity. Valid values for polarity are:  
 * - kEMIF_ASYNC_WAIT_POLARITY_LOW for low polarity  
 * - kEMIF_ASYNC_WAIT_POLARITY_HIGH for high polarity  
 *  
 */
static inline void EMIF_setAsyncWaitPolarity(EMIF_Type *base, EMIF_AsyncWaitPolarity_t polarity)
{
    /* Check the arguments. */
    assert(EMIF_isBaseValid(base));

    /* Sets the polarity for async extended wait mode. */
    base->ASYNC_WCCR = (base->ASYNC_WCCR & (~EMIF_ASYNC_WCCR_WP0_Msk)) | EMIF_ASYNC_WCCR_WP0_Set(polarity);
}

/*!
 * \brief Sets the maximum wait cycles for extended asynchronous cycle.  
 *  
 * \details This function configures the maximum wait cycles for an extended asynchronous cycle  
 * of an asynchronous external memory associated with a specific EMIF instance.  
 *  
 * \param[in] base The base address of the EMIF instance to be configured.  
 *  
 * \param[in] value The desired maximum wait cycles.  
 * Valid values for value are between 0x0U and 0xFFU (inclusive), or 0 to 255.  
 *  
 */
static inline void EMIF_setAsyncMaximumWaitCycles(EMIF_Type *base, uint16_t value)
{
    /* Check the arguments. */
    assert(EMIF_isBaseValid(base));
    assert(value <= (EMIF_ASYNC_WCCR_MAX_EXT_WAIT_Msk));

    /* Sets the bit that enables extended wait mode. */
    base->ASYNC_WCCR =
        (base->ASYNC_WCCR & (~EMIF_ASYNC_WCCR_MAX_EXT_WAIT_Msk)) | EMIF_ASYNC_WCCR_MAX_EXT_WAIT_Set(value);
}

/*!
 * \brief Sets the timing characteristics for asynchronous memory.  
 *  
 * \brief This function configures the timing characteristics for an external asynchronous  
 * memory interface, using a specific EMIF instance and chip select offset.  
 *  
 * \param[in] base The base address of the EMIF instance to be configured.  
 *  
 * \param[in] offset The offset of the asynchronous chip select within the EMIF instance.  
 * Valid values for offset are:  
 * - kEMIF_ASYNC_CS2_OFFSET for EMIF1 and EMIF2  
 * - kEMIF_ASYNC_CS3_OFFSET for EMIF1  
 * - EMIF_ASYNC_C43_OFFSET for EMIF1 (note: this might be a typo, usually it's EMIF_ASYNC_CS4_OFFSET)  
 *  
 * \param[in] tParam The desired timing parameters for the asynchronous memory.  
 *  
 */
static inline void EMIF_setAsyncTimingParams(EMIF_Type *base, EMIF_AsyncCSOffset_t offset,
     const EMIF_AsyncTimingParams_t *tParam)
{
    /* Check the arguments. */
    uint32_t value = 0;
    uint32_t msk = 0;

    assert(EMIF_isBaseValid(base));

    value = EMIF_ASYNC_CS2_CR_TA_Set(tParam->turnArnd) | EMIF_ASYNC_CS2_CR_R_HOLD_Set(tParam->rHold) |
    EMIF_ASYNC_CS2_CR_R_STROBE_Set(tParam->rStrobe) | EMIF_ASYNC_CS2_CR_R_SETUP_Set(tParam->rSetup) |
    EMIF_ASYNC_CS2_CR_W_HOLD_Set(tParam->wHold) | EMIF_ASYNC_CS2_CR_W_STROBE_Set(tParam->wStrobe) |
    EMIF_ASYNC_CS2_CR_W_SETUP_Set(tParam->wSetup);

    msk = EMIF_ASYNC_CS2_CR_TA_Msk | EMIF_ASYNC_CS2_CR_R_HOLD_Msk | EMIF_ASYNC_CS2_CR_R_STROBE_Msk |
  EMIF_ASYNC_CS2_CR_R_SETUP_Msk | EMIF_ASYNC_CS2_CR_W_HOLD_Msk | EMIF_ASYNC_CS2_CR_W_STROBE_Msk |
  EMIF_ASYNC_CS2_CR_W_SETUP_Msk;

    /* Sets the async memory timing parameters. */
    if (offset == kEMIF_ASYNC_CS2_OFFSET)
    {
        base->ASYNC_CS2_CR = (base->ASYNC_CS2_CR & (~msk)) | value;
    }
    else if (offset == kEMIF_ASYNC_CS3_OFFSET)
    {
        base->ASYNC_CS3_CR = (base->ASYNC_CS3_CR & (~msk)) | value;
    }
    else if (offset == kEMIF_ASYNC_CS4_OFFSET)
    {
        base->ASYNC_CS4_CR = (base->ASYNC_CS4_CR & (~msk)) | value;
    }
}

/*!
 * \brief Sets the asynchronous data bus width.  
 *  
 * \brief This function configures the data bus size for an external asynchronous memory  
 * to be interfaced with a specific EMIF instance and chip select offset.  
 *  
 * \param[in] base The base address of the EMIF instance to be configured.  
 *  
 * \param[in] offset The offset of the asynchronous chip select within the EMIF instance.  
 * Valid values for offset are:  
 * - kEMIF_ASYNC_CS2_OFFSET for EMIF1 and EMIF2  
 * - kEMIF_ASYNC_CS3_OFFSET for EMIF1 (if applicable)  
 * - EMIF_ASYNC_CS4_OFFSET for EMIF1 (if applicable, note: C43 might be a typo)  
 *  
 * \param[in] width The data bus width of the memory.  
 * Valid values for width are:  
 * - kEMIF_ASYNC_DATA_WIDTH_8 for 8-bit data bus  
 * - kEMIF_ASYNC_DATA_WIDTH_16 for 16-bit data bus  
 * - kEMIF_ASYNC_DATA_WIDTH_32 for 32-bit data bus  
 */
static inline void EMIF_setAsyncDataBusWidth(EMIF_Type *base, EMIF_AsyncCSOffset_t offset, EMIF_AsyncDataWidth_t width)
{
    /* Check the arguments. */
    assert(EMIF_isBaseValid(base));

    /* Sets the async memory data bus width. */
    if (offset == kEMIF_ASYNC_CS2_OFFSET)
    {
        base->ASYNC_CS2_CR = (base->ASYNC_CS2_CR & (~EMIF_ASYNC_CS2_CR_ASIZE_Msk)) | EMIF_ASYNC_CS2_CR_ASIZE_Set(width);
    }
    else if (offset == kEMIF_ASYNC_CS3_OFFSET)
    {
        base->ASYNC_CS3_CR = (base->ASYNC_CS3_CR & (~EMIF_ASYNC_CS2_CR_ASIZE_Msk)) | EMIF_ASYNC_CS2_CR_ASIZE_Set(width);
    }
    else if (offset == kEMIF_ASYNC_CS4_OFFSET)
    {
        base->ASYNC_CS4_CR = (base->ASYNC_CS4_CR & (~EMIF_ASYNC_CS2_CR_ASIZE_Msk)) | EMIF_ASYNC_CS2_CR_ASIZE_Set(width);
    }
}

/*! 
 * \brief Enables the Asynchronous Memory Interrupts.  
 *  
 * \brief This function enables the specified interrupts for an external asynchronous  
 * memory interface associated with a given EMIF instance.  
 *  
 * \param[in] base The base address of the EMIF instance to be configured.  
 *  
 * \param[in] intFlags The mask for the desired interrupts to be enabled.  
 *         Valid values for \p intFlags are:  
 *         - EMIF_ASYNC_INT_AT: Asynchronous timeout interrupt  
 *         - EMIF_ASYNC_INT_LT: Last transfer interrupt  
 *         - EMIF_ASYNC_INT_WR: Write ready interrupt  
 *         These flags can be combined using bitwise OR to enable multiple interrupts.  
 */
static inline void EMIF_enableAsyncInterrupt(EMIF_Type *base, uint16_t intFlags)
{
    uint32_t msk = 0;

    /* Check the arguments. */
    msk = EMIF_INT_EN_WR_IEN_Msk | EMIF_INT_EN_LT_IEN_Msk | EMIF_INT_EN_AT_IEN_Msk;

    assert(EMIF_isBaseValid(base));
    if (!(intFlags <= msk))
    {
        while (1)
        {
            ;
        }
    }

    /* Sets the bits that enables async memory interrupts. */
    base->INT_EN |= intFlags;
}

/*! 
 * \brief Disables the Asynchronous Memory Interrupts.  
 *  
 * \brief This function disables the specified interrupts for an external asynchronous  
 * memory interface associated with a given EMIF instance.  
 *  
 * \param[in] base The base address of the EMIF instance.  
 *  
 * \param[in] intFlags The mask for the interrupts to be disabled.  
 *         Valid values for \p intFlags are:  
 *         - EMIF_ASYNC_INT_AT: Asynchronous timeout interrupt  
 *         - EMIF_ASYNC_INT_LT: Last transfer interrupt  
 *         - EMIF_ASYNC_INT_WR: Write ready interrupt  
 *         Multiple interrupts can be disabled by combining these flags using bitwise OR.  
 */
static inline void EMIF_disableAsyncInterrupt(EMIF_Type *base, uint16_t intFlags)
{
    /* Check the arguments. */
    assert(EMIF_isBaseValid(base));

    /* Sets the bits that enables async memory interrupts. */
    base->INT_EN &= ~intFlags;
}

/*! 
 * \brief Gets the Interrupt Status.  
 *  
 * \brief This function retrieves the current interrupt status for an EMIF instance.  
 *  
 * \param[in] base The base address of the EMIF instance.  
 *  
 * \return Returns a value representing the current interrupt status.  
 */
static inline uint16_t EMIF_getAsyncInterruptStatus(EMIF_Type *base)
{
    /* Check the arguments. */
    assert(EMIF_isBaseValid(base));

    /* Gets the async memory interrupt status. */
    return (base->INT_RAW);
}

/*! 
 * \brief Clears the Interrupt Status for an EMIF Instance.  
 *  
 * \brief This function clears the interrupt status for a given EMIF instance.  
 *  
 * \param[in] base The base address of the EMIF instance.  
 *  
 * \param[in] intFlags The mask specifying the interrupt status to be cleared.  
 *  
 * The intFlags parameter can be any of the following values or their combinations:  
 * EMIF_INT_MSK_SET_AT_MASK_SET - To clear the asynchronous timeout interrupt status  
 * EMIF_INT_MSK_SET_LT_MASK_SET - To clear the last transfer interrupt status  
 * EMIF_INT_MSK_SET_WR_MASK_SET_M - To clear the write ready interrupt status  
 */
static inline void EMIF_clearAsyncInterruptStatus(EMIF_Type *base, uint16_t intFlags)
{
    /* Check the arguments. */
    assert(EMIF_isBaseValid(base));
    assert(intFlags <=
   (EMIF_INT_MSK_CLR_WR_FLAG_CLR_Msk | EMIF_INT_MSK_CLR_LT_FLAG_CLR_Msk | EMIF_INT_MSK_CLR_AT_FLAG_CLR_Msk));

    /* Sets the bit that clears desired async memory interrupts. */
    base->INT_MSK_CLR |= intFlags;
}

/*! 
 * \brief Sets the Synchronous Memory Timing Parameters.  
 *  
 * \brief This function configures the timing characteristics for an external  
 * synchronous memory interface associated with a given EMIF instance.  
 *  
 * \param[in] base The base address of the EMIF instance.  
 *  
 * \param[in] tParam The timing parameters from the memory datasheet in nanoseconds (ns).  
 */
static inline void EMIF_setSyncTimingParams(EMIF_Type *base, const EMIF_SyncTimingParams_t *tParam)
{
    uint32_t temp = 0;
    uint32_t msk = 0;

    /* Check the arguments. */
    assert(EMIF_isBaseValid(base));

    /* Sets sync memory timing parameters. */
    msk = EMIF_SDRAM_TR_T_RRD_Msk | EMIF_SDRAM_TR_T_RC_Msk | EMIF_SDRAM_TR_T_RAS_Msk | EMIF_SDRAM_TR_T_WR_Msk |
  EMIF_SDRAM_TR_T_RCD_Msk | EMIF_SDRAM_TR_T_RP_Msk | EMIF_SDRAM_TR_T_RFC_Msk;
    temp = EMIF_SDRAM_TR_T_RRD_Set(tParam->tRrd) | EMIF_SDRAM_TR_T_RC_Set(tParam->tRc) |
   EMIF_SDRAM_TR_T_RAS_Set(tParam->tRas) | EMIF_SDRAM_TR_T_WR_Set(tParam->tWr) |
   EMIF_SDRAM_TR_T_RCD_Set(tParam->tRcd) | EMIF_SDRAM_TR_T_RP_Set(tParam->tRp) |
   EMIF_SDRAM_TR_T_RFC_Set(tParam->tRfc);

    base->SDRAM_TR = (base->SDRAM_TR & (~msk)) | temp;
}

/*! 
 * \brief Sets the SDRAM Self Refresh Exit Timing.  
 *  
 * \brief This function configures the self-refresh exit timing for an external  
 * synchronous memory interface associated with a given EMIF instance.  
 *  
 * \param[in] base The base address of the EMIF instance.  
 *  
 * \param[in] tXs The desired timing value for the self-refresh exit.  
 *              Valid values for \p tXs are in the range 0x0U to 0x1FU (0 to 31).  
 */
static inline void EMIF_setSyncSelfRefreshExitTmng(EMIF_Type *base, uint16_t tXs)
{
    /* Check the arguments. */
    assert(EMIF_isBaseValid(base));
    assert(tXs <= EMIF_SDR_EXT_TMNG_T_XS_Msk);

    /* Sets the self refresh exit timing for sync memory. */
    base->SDR_EXT_TMNG = EMIF_SDR_EXT_TMNG_T_XS_Set(tXs);
}

/*! 
 * \brief Sets the SDR Refresh Rate.  
 *  
 * \brief This function configures the refresh rate for an external synchronous memory  
 * interface associated with a given EMIF instance.  
 *  
 * \param[in] base The base address of the EMIF instance.  
 *  
 * \param[in] refRate The refresh rate value.  
 *                 Valid values for \p refRate range from 0x0U to 0x1FFFU (0 to 8191).  
 */
static inline void EMIF_setSyncRefreshRate(EMIF_Type *base, uint16_t refRate)
{
    /* Check the arguments. */
    assert(EMIF_isBaseValid(base));
    assert(refRate <= EMIF_SDRAM_RCR_REFRESH_RATE_Msk);

    /* Sets the sync memory refresh rate. */
    base->SDRAM_RCR = EMIF_SDRAM_RCR_REFRESH_RATE_Set(refRate);
}

/*! 
 * \brief Sets the Synchronous Memory Configuration Parameters.  
 *  
 * \brief This function configures parameters such as CL, NM, IBANK, and PAGESIZE  
 * for an external synchronous memory interface associated with a given EMIF instance.  
 *  
 * \param[in] base The base address of the EMIF instance.  
 *  
 * \param[in] config The desired configuration parameters for the memory interface.  
 */
static inline void EMIF_setSyncMemoryConfig(EMIF_Type *base, const EMIF_SyncConfig_t *config)
{
    uint32_t temp = 0;
    uint32_t msk = 0;

    /* Check the arguments. */
    assert(EMIF_isBaseValid(base));

    /* Sets the sync memory configuration bits. */
    msk = EMIF_SDRAM_CR_CL_Msk | EMIF_SDRAM_CR_IBANK_Msk | EMIF_SDRAM_CR_NM_Msk | EMIF_SDRAM_CR_PAGESIZE_Msk;
    temp = EMIF_SDRAM_CR_CL_Set(config->casLatency) | EMIF_SDRAM_CR_IBANK_Set(config->iBank) |
   EMIF_SDRAM_CR_NM_Set(config->narrowMode) | EMIF_SDRAM_CR_PAGESIZE_Set(config->pageSize);
    base->SDRAM_CR = (base->SDRAM_CR & (~msk)) | temp;
}

/*! 
 * \brief Enables Self Refresh Mode.  
 *  
 * \brief This function enables the self-refresh mode for the given EMIF instance.  
 *  
 * \param[in] base The base address of the EMIF instance.  
 */
static inline void EMIF_enableSyncSelfRefresh(EMIF_Type *base)
{
    /* Check the arguments. */
    assert(EMIF_isBaseValid(base));

    /* Sets the bits that enables sync memory self refresh mode. */
    base->SDRAM_CR |= EMIF_SDRAM_CR_SR_Set(kEMIF_ENABLE);
}

/*! 
 * \brief Disables Self Refresh.  
 *  
 * \brief This function disables the Self Refresh Mode for the specified EMIF instance.  
 *  
 * \param[in] base The base address of the EMIF instance used.  
 */
static inline void EMIF_disableSyncSelfRefresh(EMIF_Type *base)
{
    /* Check the arguments. */
    assert(EMIF_isBaseValid(base));
 
    /* Sets the bits that enables sync memory self refresh mode. */
    base->SDRAM_CR &= ~EMIF_SDRAM_CR_SR_Msk;
}

/*! 
 * \brief Enables Power Down Mode.  
 *  
 * \brief This function enables the power-down mode for the synchronous memory  
 * interface associated with the given EMIF instance.  
 *  
 * \param[in] base The base address of the EMIF instance.  
 */
static inline void EMIF_enableSyncPowerDown(EMIF_Type *base)
{
    /* Check the arguments. */
    assert(EMIF_isBaseValid(base));

    /* Sets the bits that enables sync memory power down mode. */
    base->SDRAM_CR |= EMIF_SDRAM_CR_PD_Set(kEMIF_ENABLE);
}

/*! 
 * \brief Disables Power Down Mode.  
 *  
 * \brief This function disables the Power Down Mode for the synchronous memory interface  
 * of the specified EMIF instance.  
 *  
 * \param[in] base The base address of the EMIF instance used.  
 */
static inline void EMIF_disableSyncPowerDown(EMIF_Type *base)
{
    /* Check the arguments. */
    assert(EMIF_isBaseValid(base));
 
    /* Sets the bits that disables sync memory power down mode. */
    base->SDRAM_CR &= ~EMIF_SDRAM_CR_PD_Msk;
}

/*! 
 * \brief Enables Refresh in Power Down Mode.  
 *  
 * \brief This function enables refresh functionality in power-down mode for the synchronous  
 * memory interface associated with the given EMIF instance.  
 *  
 * \param[in] base The base address of the EMIF instance.  
 */
static inline void EMIF_enableSyncRefreshInPowerDown(EMIF_Type *base)
{
    /* Check the arguments. */
    assert(EMIF_isBaseValid(base));
 
    /* Sets the bits that enables refresh in power down mode. */
    base->SDRAM_CR |= EMIF_SDRAM_CR_PDWR_Set(kEMIF_ENABLE);
}

/*! 
 * \brief Disables Refresh in Power Down Mode.  
 *  
 * \brief This function disables the refresh operation during Power Down Mode for the synchronous memory  
 * interface of the specified EMIF instance.  
 *  
 * \param[in] base The base address of the EMIF instance used.  
 */
static inline void EMIF_disableSyncRefreshInPowerDown(EMIF_Type *base)
{
    /* Check the arguments. */
    assert(EMIF_isBaseValid(base));
 
    /* Sets the bits that disables refresh in power down mode. */
    base->SDRAM_CR &= ~EMIF_SDRAM_CR_PDWR_Msk;
}

/*! 
 * \brief Gets the Total Number of SDRAM Accesses.  
 *  
 * \brief This function retrieves the total number of SDRAM accesses  
 * made by a controller (e.g., CPUx or DMA).  
 *  
 * \param[in] base The base address of the EMIF instance.  
 *  
 * \return The total number of accesses to SDRAM.  
 */
static inline uint32_t EMIF_getSyncTotalAccesses(EMIF_Type *base)
{
    /* Check the arguments. */
    assert(EMIF_isBaseValid(base));

    /* Gets total accesses to sync memory. */
    return (EMIF_TOTAL_SDRAM_AR_TOTAL_SDRAM_AR_Get(base->TOTAL_SDRAM_AR));
}

/*! 
 * \brief Gets Total Number of SDRAM Accesses Requiring Activate Command.  
 *  
 * \brief This function retrieves the total number of accesses to SDRAM that require an activate command  
 * for the specified EMIF instance.  
 *  
 * \param[in] base The base address of the EMIF instance used.  
 *  
 * \return Returns the total number of SDRAM accesses that require an activate command.  
 */
static inline uint32_t EMIF_getSyncTotalActivateAccesses(EMIF_Type *base)
{
    /* Check the arguments. */
    assert(EMIF_isBaseValid(base));
 
    /* Gets total accesses to sync memory which requires activate command. */
    return (EMIF_TOTAL_SDRAM_ACTR_TOTAL_SDRAM_ACTR_Get(base->TOTAL_SDRAM_ACTR));
}

/*! 
 * \brief Sets Asynchronous Memory Interrupts.  
 *  
 * \brief This function sets the asynchronous memory interrupts for the specified EMIF instance.  
 *  
 * \param[in] base The base address of the EMIF instance.  
 * \param[in] intFlags The interrupt flags to be set, indicating the interrupts to be enabled.  
 *  
 */  
static inline void EMIF_setAsyncInterrupt(EMIF_Type *base, uint16_t intFlags)  
{  
    uint32_t msk = 0;  
   
    /* Check the arguments. */  
    msk = EMIF_INT_MSK_SET_WR_FLAG_SET_Msk | EMIF_INT_MSK_SET_LT_FLAG_SET_Msk  
        | EMIF_INT_MSK_SET_AT_FLAG_SET_Msk;  
  
    assert(EMIF_isBaseValid(base));  
    if (!(intFlags <= msk))
    {
        while (1)
        {
            ;
        }
    }  
  
    /* Sets the bits that enables async memory interrupts. */  
    base->INT_MSK_SET |= intFlags;  
}

/*! 
 * \brief Clears Access Protection for Specified Accesses.  
 *  
 * \brief This function clears the access protection bits for the specified accesses on the EMIF instance.  
 *  
 * \param[in] base The base address of the EMIF instance.  
 *
 * \param[in] access The access bits to be cleared. These bits correspond to the various access protection flags.  
 *  
 */  
static inline void EMIF_clearAccessProtection(EMIF_Type *base, uint16_t access)  
{    
    uint16_t msk = 0;  
   
    /* Check the arguments. */  
    msk = EMIF_EMIF1ACCROT_DMA0_WRITE_Msk | EMIF_EMIF1ACCROT_DMA0_READ_Msk 
    | EMIF_EMIF1ACCROT_CPU0_WRITE_Msk | EMIF_EMIF1ACCROT_CPU0_READ_Msk 
    | EMIF_EMIF1ACCROT_DMA1_WRITE_Msk | EMIF_EMIF1ACCROT_DMA1_READ_Msk 
    | EMIF_EMIF1ACCROT_CPU1_WRITE_Msk | EMIF_EMIF1ACCROT_CPU1_READ_Msk;  
  
    assert(EMIF_isBaseValid(base));  
    if (!(access <= msk))
    {
        while (1)
        {
            ;
        }
    }

    /* Clears the bits that enable access protection for the specified accesses. */  
    base->EMIF1ACCROT &= ~access;  
}

/*!
 * \brief Register user callback function to a specified emif
 *
 * \details This function registers user callback function for emif which uses IRQ. The relative IRQ
 will be enabled in the NVIC and the priority will be configured at the same time
 * \param[in] base is the EMIF base address
 * \param[in] intsrc is the EMIF INT index
 * \param[in] func is the EMIF user callback
 * \param[in] priority is the IRQ priority
 *
 * \retval kSTATUS_SUCESS Success to the operation
 * \retval kSTATUS_FAIL Register to a EMIF which has been registered already. Need to call \ref
 EMIF_unregisterCallback() before the re-registration
 */
status_t EMIF_registerCallback(EMIF_Type *base, EMIF_Irq_Idx_t intsrc, EMIF_Callback_t func, uint32_t priority);

/*!
 * \brief Unregister user callback function to EMIF transfer
 *
 * \details This function clears the registered user callback function, and disable the relative IRQ in the NVIC
 *
 * \param[in] base is the EMIF base address
 * \param[in] intsrc is the EMIF INT index
 * \retval kSTATUS_SUCESS Success to the operation
 * \retval kSTATUS_INVALID_ARGUMENT The EMIF hasn't been registered to a callback
 */
status_t EMIF_unregisterCallback(EMIF_Type *base, EMIF_Irq_Idx_t intsrc);

/*!
 * \brief Get EMIF instance using the base address
 *
 * \details This function converts EMIF base address to EMIF instance which is an unsigned integer value. 0,1,2,3,...
 * stands for the peripheral with suffix A,B,C,D
 *
 * \param[in] EMIF_base EMIF base address
 *
 * \return The EMIF instance
 */
EMIF_Idx_t EMIF_getInstance(EMIF_Type *EMIF_base);

/*!
 * @}
 */

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */ /* end of DRV_HTE_EMIF */

#endif /* HTE_EMIF_H */
