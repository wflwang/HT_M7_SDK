/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_sdfm.h
 * \brief SDK SDFM driver header file
 * \version 1.0.0
 */

#ifndef HTE_SDFM_H
#define HTE_SDFM_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_common.h"

/*!
 * \addtogroup DRV_HTE_SDFM SDFM Driver
 *
 * \brief SDK SDFM driver
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! \brief Macro to get the low threshold */
#define SDFM_GET_LOW_THRESHOLD(C) ((uint16_t)(C))

/*! \brief Macro to get the high threshold */
#define SDFM_GET_HIGH_THRESHOLD(C) ((uint16_t)((uint32_t)(C) >> 16U))

/*!
 *\brief Macro to get the high threshold 1 & 2 to be passed as lowThreshold
 * parameter to SDFM_setCompFilterLowThreshold().
 */
#define SDFM_GET_LOW_THRESHOLD_BOTH(C1, C2) \
    ((((uint32_t)(SDFM_GET_LOW_THRESHOLD(C2))) << 16U) | ((uint32_t)(SDFM_GET_LOW_THRESHOLD(C1))))

/*!
 *\brief Macro to get the high threshold 1 & 2 to be passed as highThreshold
 * parameter to SDFM_setCompFilterHighThreshold().
 */
#define SDFM_GET_HIGH_THRESHOLD_BOTH(C1, C2) \
    ((((uint32_t)(SDFM_GET_HIGH_THRESHOLD(C2))) << 16U) | ((uint32_t)(SDFM_GET_HIGH_THRESHOLD(C1))))

/*! \brief Macro to convert comparator over sampling ratio to acceptable bit location */
#define SDFM_SET_OSR(X) (((X)-1) << 8U)

/*! \brief Macro to convert the data shift bit values to acceptable bit location */
#define SDFM_SHIFT_VALUE(X) ((X) << 2U)

/*! \brief Macro to combine high threshold and low threshold values */
#define SDFM_THRESHOLD(H, L) ((((uint32_t)(H)) << 16U) | (L))

/*! \brief Macro to set the FIFO level to acceptable bit location */
#define SDFM_SET_FIFO_LEVEL(X) ((X) << 7U)

/*! \brief Macro to set and enable the zero cross threshold value. */
#define SDFM_SET_ZERO_CROSS_THRESH_VALUE(X) (0x8000 | (X))

/*! \brief Macros to enable filter. */
#define SDFM_FILTER_DISABLE 0x0U

/*! \brief Macros to disable filter. */
#define SDFM_FILTER_ENABLE  0x2U


/*!
 * \brief Define to mask out the bits in the SDCOMPHFILCTL register that aren't
 * associated with comparator event filter configurations. Added for internal
 * use, not to be used in application code.
 */
#define SDFM_COMPEVT_FILTER_CONFIG_M (SDFM_SDCOMP1EVT1FLTCTL_SAMPWIN_Msk | SDFM_SDCOMP1EVT1FLTCTL_THRESH_Msk)

/*!
 * \brief Define to mask out the bits in the SDCOMPLOCK register that aren't
 * associated with lock configuration.  Added for internal use, not to be used
 * in application code.
 */
#define SDFM_COMPEVT_FILTER_LOCK_M (SDFM_SDCOMPLOCK_SDCOMPCTL | SDFM_SDCOMPLOCK_COMP)

/*! \brief Interrupt is generated if Modulator fails. */
#define SDFM_MODULATOR_FAILURE_INTERRUPT 0x200U
/*! \brief Interrupt on Comparator low-level threshold. */
#define SDFM_LOW_LEVEL_THRESHOLD_INTERRUPT 0x40U
/*! \brief Interrupt on Comparator high-level threshold. */
#define SDFM_HIGH_LEVEL_THRESHOLD_INTERRUPT 0x20U
/*! \brief Interrupt on Acknowledge flag */
#define SDFM_DATA_FILTER_ACKNOWLEDGE_INTERRUPT 0x1U
/*! \brief Interrupt on FIFO underflow */
#define SDFM_FIFO_UNDERFLOW_INTERRUPT 0x800U
/*! \brief Interrupt on FIFO level */
#define SDFM_FIFO_INTERRUPT 0x1000U
/*! \brief Interrupt on FIFO overflow */
#define SDFM_FIFO_OVERFLOW_INTERRUPT 0x8000U


/*! \brief Master interrupt flag */
#define SDFM_MASTER_INTERRUPT_FLAG 0x80000000U
/*! \brief Filter 1 high -level threshold flag */
#define SDFM_FILTER_1_HIGH_THRESHOLD_FLAG 0x1U
/*! \brief Filter 1 low -level threshold flag */
#define SDFM_FILTER_1_LOW_THRESHOLD_FLAG 0x2U
/*! \brief Filter 2 high -level threshold flag */
#define SDFM_FILTER_2_HIGH_THRESHOLD_FLAG 0x4U
/*! \brief Filter 2 low -level threshold flag */
#define SDFM_FILTER_2_LOW_THRESHOLD_FLAG 0x8U
/*! \brief Filter 3 high -level threshold flag */
#define SDFM_FILTER_3_HIGH_THRESHOLD_FLAG 0x10U
/*! \brief Filter 3 low -level threshold flag */
#define SDFM_FILTER_3_LOW_THRESHOLD_FLAG 0x20U
/*! \brief Filter 4 high -level threshold flag */
#define SDFM_FILTER_4_HIGH_THRESHOLD_FLAG 0x40U
/*! \brief Filter 4 low -level threshold flag */
#define SDFM_FILTER_4_LOW_THRESHOLD_FLAG 0x80U
/*! \brief Filter 1 modulator failed flag */
#define SDFM_FILTER_1_MOD_FAILED_FLAG 0x100U
/*! \brief Filter 2 modulator failed flag */
#define SDFM_FILTER_2_MOD_FAILED_FLAG 0x200U
/*! \brief Filter 3 modulator failed flag */
#define SDFM_FILTER_3_MOD_FAILED_FLAG 0x400U
/*! \brief Filter 4 modulator failed flag */
#define SDFM_FILTER_4_MOD_FAILED_FLAG 0x800U
/*! \brief Filter 1 new data flag */
#define SDFM_FILTER_1_NEW_DATA_FLAG 0x1000U
/*! \brief Filter 2 new data flag */
#define SDFM_FILTER_2_NEW_DATA_FLAG 0x2000U
/*! \brief Filter 3 new data flag */
#define SDFM_FILTER_3_NEW_DATA_FLAG 0x4000U
/*! \brief Filter 4 new data flag */
#define SDFM_FILTER_4_NEW_DATA_FLAG 0x8000U
/*! \brief Filter 1 FIFO overflow flag */
#define SDFM_FILTER_1_FIFO_OVERFLOW_FLAG 0x10000U
/*! \brief Filter 2 FIFO overflow flag */
#define SDFM_FILTER_2_FIFO_OVERFLOW_FLAG 0x20000U
/*! \brief Filter 3 FIFO overflow flag */
#define SDFM_FILTER_3_FIFO_OVERFLOW_FLAG 0x40000U
/*! \brief Filter 4 FIFO overflow flag */
#define SDFM_FILTER_4_FIFO_OVERFLOW_FLAG 0x80000U
/*! \brief Filter 1 FIFO data ready  flag */
#define SDFM_FILTER_1_FIFO_INTERRUPT_FLAG 0x100000U
/*! \brief Filter 2 FIFO data ready flag */
#define SDFM_FILTER_2_FIFO_INTERRUPT_FLAG 0x200000U
/*! \brief Filter 3 FIFO data ready  flag */
#define SDFM_FILTER_3_FIFO_INTERRUPT_FLAG 0x400000U
/*! \brief Filter 4 FIFO data ready  flag */
#define SDFM_FILTER_4_FIFO_INTERRUPT_FLAG 0x800000U
/*! \brief Filter 1 FIFO underflow flag */
#define SDFM_FILTER_1_FIFO_UNDERFLOW_FLAG 0x1000000U
/*! \brief Filter 2 FIFO underflow flag */
#define SDFM_FILTER_2_FIFO_UNDERFLOW_FLAG 0x2000000U
/*! \brief Filter 3 FIFO underflow flag */
#define SDFM_FILTER_3_FIFO_UNDERFLOW_FLAG 0x4000000U
/*! \brief Filter 4 FIFO underflow flag */
#define SDFM_FILTER_4_FIFO_UNDERFLOW_FLAG 0x8000000U


/*! \brief sdfm interrupt mask */
#define SDF_INTERRUPT_FLAG_MASK 0x8FFFFFFF


/*! \brief type definition for SDFM callback  */
typedef void (*SDFM_Callback_t)(SDFM_REGS_Type *base);

/*!
 *  \brief    Enum to select the SDFM source
 */
typedef enum
{
    kSDFM_IDX_1   = 0, /*!< SDFM1 source*/
    kSDFM_IDX_2   = 1, /*!< SDFM2 source*/
    kSDFM_IDX_MAX = 2, /*!< Maximum value of the enumeration. */
} SDFM_Idx_t;

/*!
 *  \brief    Enum to select the SDFM IRQ source
 */
typedef enum
{
    kSDFM_INT       = 0, /*!< SDFM ERR INT IRQ */
    kSDFM_DR_INT1   = 1, /*!< SDFM CHANNEL1 DATAREADY INT IRQ */
    kSDFM_DR_INT2   = 2, /*!< SDFM CHANNEL2 DATAREADY INT IRQ */
    kSDFM_DR_INT3   = 3, /*!< SDFM CHANNEL3 DATAREADY INT IRQ */
    kSDFM_DR_INT4   = 4, /*!< SDFM CHANNEL4 DATAREADY INT IRQ */
    kSDFM_INT_MAX = 5,   /*!< Maximum value of the enumeration. */
} SDFM_IntSrc_t;

/*!
 * \brief type definition for sdfm interrupt callback  
 */
typedef struct
{
    SDFM_Callback_t func[kSDFM_IDX_MAX][kSDFM_INT_MAX]; /*!< An array of function pointers for interrupt callbacks. */
} SDFM_Int_Callback_t;


/*!
 * \brief Values that can be returned from SDFM_getThresholdStatus()
 */
typedef enum
{
    kSDFM_OUTPUT_WITHIN_THRESHOLD = 0, /*!< SDFM output is within threshold */
    kSDFM_OUTPUT_ABOVE_THRESHOLD  = 1, /*!< SDFM output is above threshold */
    kSDFM_OUTPUT_BELOW_THRESHOLD  = 2  /*!< SDFM output is below threshold */
} SDFM_OutputThresholdStatus_t;

/*!
 * \brief Values that can be passed to all functions as the \e filterNumber
 * parameter.
 */
typedef enum
{
    kSDFM_FILTER_1 = 0, /*!< Digital filter 1 */
    kSDFM_FILTER_2 = 1, /*!< Digital filter 2 */
    kSDFM_FILTER_3 = 2, /*!< Digital filter 3 */
    kSDFM_FILTER_4 = 3, /*!< Digital filter 4 */
} SDFM_FilterNumber_t;

/*!
 * \brief Values that can be passed to SDFM_setFilterType(),
 * SDFM_setComparatorFilterType() as the \e filterType parameter.
 */
typedef enum
{
    kSDFM_FILTER_SINC_FAST = 0x00, /*!< Digital filter with SincFast structure. */
    kSDFM_FILTER_SINC_1    = 0x10, /*!< Digital filter with Sinc1 structure. */
    kSDFM_FILTER_SINC_2    = 0x20, /*!< Digital filter with Sinc3 structure. */
    kSDFM_FILTER_SINC_3    = 0x30, /*!< Digital filter with Sinc4 structure. */
} SDFM_FilterType_t;

/*!
 * \brief Values that can be passed to SDFM_setupModulatorClock(),as the
 * \e clockMode parameter.
 */
typedef enum
{
    kSDFM_MODULATOR_CLK_EQUAL_DATA_RATE  = 0, /*!< Modulator clock is identical to the data rate */
    kSDFM_MODULATOR_CLK_HALF_DATA_RATE   = 1, /*!< Modulator clock is half the data rate */
    kSDFM_MODULATOR_DISABLE              = 2, /*!< Modulator clock disabled */
    kSDFM_MODULATOR_CLK_DOUBLE_DATA_RATE = 3, /*!< Modulator clock is double the data rate. */
} SDFM_ModulatorClockMode_t;

/*!
 * \brief Values that can be passed to SDFM_setOutputDataFormat(),as the
 * \e dataFormat parameter.
 */
typedef enum
{
    kSDFM_DATA_FORMAT_16_BIT = 0, /*!< Filter output is in 16 bits 2's complement format. */
    kSDFM_DATA_FORMAT_32_BIT = 1, /*!< Filter output is in 32 bits 2's complement format. */
} SDFM_OutputDataFormat_t;

/*!
 * \brief Values that can be passed to SDFM_setDataReadyInterruptSource(),as the
 * \e dataReadySource parameter.
 */
typedef enum
{
    kSDFM_DATA_READY_SOURCE_DIRECT = 0, /*!< Data ready interrupt source is direct (non -FIFO). */
    kSDFM_DATA_READY_SOURCE_FIFO   = 1, /*!< Data ready interrupt source is FIFO. */
} SDFM_DataReadyInterruptSource_t;

/*!
 * \brief Values that can be passed to SDFM_setDataReadyDMASource(),as the
 * \e dataReadySource parameter.
 */
typedef enum
{
    kSDFM_DATA_READY_DMA_SOURCE_DIRECT = 0, /*!< Data ready dma source is direct (non -FIFO). */
    kSDFM_DATA_READY_DMA_SOURCE_FIFO   = 1, /*!< Data ready dma source is FIFO. */
} SDFM_DataReadyDMASource_t;


/*!
 * \brief Values that can be passed to SDFM_setPWMSyncSource(),as the
 * \e syncSource parameter.
 */
typedef enum
{
    kSDFM_SYNC_PWM1_SOCA  = 0,  /*!< SDFM sync source is PWM1 SOCA */
    kSDFM_SYNC_PWM1_SOCB  = 1,  /*!< SDFM sync source is PWM1 SOCB */
    kSDFM_SYNC_PWM2_SOCA  = 4,  /*!< SDFM sync source is PWM2 SOCA */
    kSDFM_SYNC_PWM2_SOCB  = 5,  /*!< SDFM sync source is PWM2 SOCB */
    kSDFM_SYNC_PWM3_SOCA  = 8,  /*!< SDFM sync source is PWM3 SOCA */
    kSDFM_SYNC_PWM3_SOCB  = 9,  /*!< SDFM sync source is PWM3 SOCB */
    kSDFM_SYNC_PWM4_SOCA  = 12, /*!< SDFM sync source is PWM4 SOCA */
    kSDFM_SYNC_PWM4_SOCB  = 13, /*!< SDFM sync source is PWM4 SOCB */
    kSDFM_SYNC_PWM5_SOCA  = 16, /*!< SDFM sync source is PWM5 SOCA */
    kSDFM_SYNC_PWM5_SOCB  = 17, /*!< SDFM sync source is PWM5 SOCB */
    kSDFM_SYNC_PWM6_SOCA  = 20, /*!< SDFM sync source is PWM6 SOCA */
    kSDFM_SYNC_PWM6_SOCB  = 21, /*!< SDFM sync source is PWM6 SOCB */
    kSDFM_SYNC_PWM7_SOCA  = 24, /*!< SDFM sync source is PWM7 SOCA */
    kSDFM_SYNC_PWM7_SOCB  = 25, /*!< SDFM sync source is PWM7 SOCB */
    kSDFM_SYNC_PWM8_SOCA  = 28, /*!< SDFM sync source is PWM8 SOCA */
    kSDFM_SYNC_PWM8_SOCB  = 29, /*!< SDFM sync source is PWM8 SOCB */
    kSDFM_SYNC_PWM9_SOCA  = 32, /*!< SDFM sync source is PWM9 SOCA */
    kSDFM_SYNC_PWM9_SOCB  = 33, /*!< SDFM sync source is PWM9 SOCB */
    kSDFM_SYNC_PWM10_SOCA = 36, /*!< SDFM sync source is PWM10 SOCA */
    kSDFM_SYNC_PWM10_SOCB = 37, /*!< SDFM sync source is PWM10 SOCB */
    kSDFM_SYNC_PWM11_SOCA = 40, /*!< SDFM sync source is PWM11 SOCA */
    kSDFM_SYNC_PWM11_SOCB = 41, /*!< SDFM sync source is PWM11 SOCB */
    kSDFM_SYNC_PWM12_SOCA = 44, /*!< SDFM sync source is PWM12 SOCA */
    kSDFM_SYNC_PWM12_SOCB = 45, /*!< SDFM sync source is PWM12 SOCB */
    kSDFM_SYNC_PWM11_CMPCD = 63, /*!< SDFM sync source is PWM11 CMPC OR CMPD */
    kSDFM_SYNC_PWM12_CMPCD = 63, /*!< SDFM sync source is PWM12 CMPC OR CMPD*/
} SDFM_PWMSyncSource_t;

/*!
 * \brief Values that can be passed to SDFM_setFIFOClearOnSyncMode(),as the
 * \e fifoClearSyncMode parameter.
 */
typedef enum
{
    kSDFM_FIFO_NOT_CLEARED_ON_SYNC = 0, /*!< SDFM FIFO buffer is not cleared on Sync signal */
    kSDFM_FIFO_CLEARED_ON_SYNC     = 1, /*!< SDFM FIFO buffer is cleared on Sync signal */
} SDFM_FIFOClearSyncMode_t;

/*!
 * \brief Values that can be passed to SDFM_setWaitForSyncClearMode(),as the
 * \e syncClearMode parameter.
 */
typedef enum
{
    kSDFM_MANUAL_CLEAR_WAIT_FOR_SYNC = 0, /*!< Wait for sync cleared using software. */
    kSDFM_AUTO_CLEAR_WAIT_FOR_SYNC   = 1, /*!< Wait for sync cleared automatically */
} SDFM_WaitForSyncClearMode_t;

/*!
 * \brief Values that can be passed to SDFM_selectCompEventSource() as the
 * \e compEventNum parameter.
 */
typedef enum
{
    kSDFM_COMP_EVENT_1 = SDFM_SDCPARM1_CEVT1SEL_Pos, /*!< Selects CEVT1 */
    kSDFM_COMP_EVENT_2 = SDFM_SDCPARM1_CEVT2SEL_Pos  /*!< Selects CEVT2 */
} SDFM_CompEventNumber_t;

/*!
 * \brief Values that can be passed to SDFM_selectCompEventSource() as the
 * \e compEventSource parameter.
 */
typedef enum
{
    kSDFM_COMP_EVENT1_SRC_COMPH1    = 0, /*!< COMPH1 event is the source */
    kSDFM_COMP_EVENT1_SRC_COMPH1_L1 = 1, /*!< Either of COMPH1 or COMPL1 event can be the source */
    kSDFM_COMP_EVENT1_SRC_COMPH2    = 2, /*!< COMPH2 event is the source */
    kSDFM_COMP_EVENT1_SRC_COMPH2_L2 = 3, /*!< Either of COMPH2 or COMPL2 event can be the source */
    kSDFM_COMP_EVENT2_SRC_COMPL1    = 0, /*!< COMPL1 event is the source */
    kSDFM_COMP_EVENT2_SRC_COMPH1_L1 = 1, /*!< Either of COMPH1 or COMPL1 event can be the source */
    kSDFM_COMP_EVENT2_SRC_COMPL2    = 2, /*!< COMPL2 event is the source */
    kSDFM_COMP_EVENT2_SRC_COMPH2_L2 = 3  /*!< Either of COMPH2 or COMPL2 event can be the source */
} SDFM_CompEventSource_t;


/*!
 * \brief Values that can be passed to SDFM_selectCompEventHighSource() as the
 * \e source parameter.
 */
typedef enum
{
    kSDFM_COMPHOUT_SOURCE_COMPHIN = 0x0, /*!< Comparator event high source is unfiltered event */
    kSDFM_COMPHOUT_SOURCE_FILTER  = 0x8, /*!< Comparator event high source is filtered event */
} SDFM_CompEventHighSource_t;

/*!
 * \brief Values that can be passed to SDFM_selectCompEventLowSource() as the
 * \e source parameter.
 */
typedef enum
{
    kSDFM_COMPLOUT_SOURCE_COMPLIN = 0x000, /*!< Comparator event low source is unfiltered event */
    kSDFM_COMPLOUT_SOURCE_FILTER  = 0x800, /*!< Comparator event low source is filtered event */
} SDFM_CompEventLowSource_t;


/*!
 * \brief Values that can be passed to SDFM_selectCompEventSource() as the
 * \e compEventNum parameter.
 */
typedef enum
{
    kSDFM_COMP_LOWEVENT  = 0U, /*!< Selects low event source */
    kSDFM_COMP_HIGHEVENT = 1U  /*!< Selects high event source */
} SDFM_CompEventSelect_t;


/*!
 * \brief Values that can be passed to SDFM_configCompEventLowFilter() &
 * SDFM_configCompEventHighFilter() as the \e filterNumber.
 */
typedef struct
{
    uint16_t sampleWindow; /*!< Sample window size */
    uint16_t threshold;    /*!< Majority voting threshold */
    uint16_t clkPrescale;  /*!< Sample clock pre-scale */
} SDFM_CompEventFilterConfig_t;

/*!  
 * \brief Union type for representing SDFM high threshold values.
 */
typedef union
{
    uint32_t all;           /*!< Full 32-bit unsigned integer representing the high threshold. */

    struct
    {
        uint32_t hlt1 : 16; /*!< hlt1 representing the high threshold1. */ 
        uint32_t hlt2 : 16; /*!< hlt2 representing the high threshold2. */ 
    } b;                    /*!< Structure for accessing the individual halves*/
} SDFM_Hthresh_t;


/*!  
 * \brief Union type for representing SDFM low threshold values.  
 */  
typedef union  
{  
    uint32_t all;           /*!< Full 32-bit unsigned integer representing the low threshold. */  
  
    struct  
    {  
        uint32_t llt1 : 16; /*!< llt1 representing the first 16 bits of the low threshold1. */   
        uint32_t llt2 : 16; /*!< llt2 representing the second 16 bits of the low threshold2. */   
    } b;                    /*!< Structure for accessing the individual halves*/
} SDFM_Lthresh_t;

/*!  
 * \brief Union type for representing SDFM zero-crossing threshold and enable flag.  
 */  
typedef union  
{  
    uint16_t all;           /*!< Full 16-bit unsigned integer representing the zero-crossing threshold and enable flag. */  
  
    struct  
    {  
        uint16_t zcth : 15; /*!< zcth represents the 15-bit zero-crossing threshold value. */  
        uint16_t en   : 1;  /*!< en represents the enable flag (1 bit) for the zero-crossing threshold. */  
    } b;                    /*!< Structure for accessing the individual halves*/
} SDFM_ZcrossThresh_t;



/*!  
 * \brief Structure representing the configuration of an SDFM comparator filter.  
 */  
typedef struct  
{  
    uint16_t            cosr;                     /*!< Over-Sampling Ratio (OSR) for comparator filter. */  
    SDFM_FilterType_t   type;                     /*!< Filter type used by the comparator filter. */  
    SDFM_Hthresh_t      hthresh;                  /*!< High threshold configuration for the comparator. */  
    SDFM_Lthresh_t      lthresh;                  /*!< Low threshold configuration for the comparator. */  
    SDFM_ZcrossThresh_t zcrsthreshold;            /*!< Zero-crossing threshold and enable flag configuration. */  
    SDFM_CompEventSource_t cevt1;                 /*!< Comparator event source 1. */  
    SDFM_CompEventSource_t cevt2;                 /*!< Comparator event source 2. */  
} SDFM_Comparator_t;


/*!  
 * \brief Structure representing the configuration of an SDFM data filter.  
 */  
typedef struct  
{  
    uint16_t                  dosr;           /*!< sampling ratio (OSR) for the data filter. */  
    SDFM_FilterType_t         type;           /*!< Filter type used by the data filter. */  
    SDFM_ModulatorClockMode_t mod;            /*!< Modulator clock mode configuration. */  
    SDFM_OutputDataFormat_t   format;         /*!< Output data format configuration. */  
    uint16_t                  shift;          /*!< Shift value for data processing (e.g., bit shifting). */  
    uint16_t                  flten;          /*!< Filter enable flag. When set, the filter is enabled. */  
} SDFM_Datafilter_t;

/*!  
 * \brief Structure representing the configuration and status of an SDFM FIFO.  
 */  
typedef struct  
{  
    uint8_t en;             /*!< Enable flag. When set, the FIFO is enabled. */  
    uint8_t ilevel;         /*!< Interrupt level threshold. When the FIFO reaches this level, an interrupt is generated. */  
} SDFM_FIFO_t;

/*!  
 * \brief Structure representing the configuration of a SDFM comparator event filter.  
 */  
typedef struct  
{  
    uint8_t                en;                   /*!< Enable flag. When set, the comparator event filter is enabled. */  
    SDFM_CompEventSelect_t event;                /*!< Comparator event to filter. */  
    uint16_t               sampWin;              /*!< Sampling window for the comparator event filter. */  
    uint16_t               threshold;            /*!< Threshold value for the comparator event filter. */  
    uint16_t               clkPrescale;          /*!< Clock prescale value for the comparator event filter. */  
    uint16_t               outsrc;               /*!< Output source selection for the comparator event filter. */  
} SDFM_CpeventFilter_t;

/*!  
 * \brief Structure representing the configuration of an SDFM DMA transfer.  
 */  
typedef struct  
{  
    uint8_t                   en;                /*!< Enable flag. When set, the DMA transfer is enabled. */
    SDFM_DataReadyDMASource_t dmasrc;            /*!< DMA source selection for data ready events. */
} SDFM_Dma_t;


/*******************************************************************************
 * APIs
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif



#ifdef DEBUG
/*!
 *
 * \brief Checks SDFM base address.
 *
 * \param[in] base specifies the SDFM module base address.
 *
 * This function determines if SDFM module base address is valid.
 *
 * \retval true if the base address is valid.
 * \retval false otherwise.
 *
 */
static inline bool SDFM_isBaseValid(SDFM_REGS_Type *base)
{
    return ((base == SDFM1) || (base == SDFM2));
}
#endif

/*!
 *
 * \brief Enable external reset
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 *
 * This function enables data filter to be reset by an external source (PWM
 * compare output).
 *
 */
static inline void SDFM_enableExternalReset(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber)
{
    uint16_t *ptr;
    assert(SDFM_isBaseValid(base));

    /* Set the SDSYNCEN bit */
    ptr   = (uint16_t *)&(base->SDDFPARM1) + ((uint32_t)filterNumber * 32U/2);
    *ptr |= SDFM_SDDFPARM1_SDSYNCEN_Set(1U);
}

/*!
 *
 * \brief  Disable external reset
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 *
 * This function disables data filter from being reset by an external source
 * (PWM compare output).
 *
 */
static inline void SDFM_disableExternalReset(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber)
{
    uint16_t *ptr;
    assert(SDFM_isBaseValid(base));

    /* Clear the SDSYNCEN bit */
    ptr   = (uint16_t *)&(base->SDDFPARM1) + ((uint32_t)filterNumber * 16U);
    *ptr &= ~(SDFM_SDDFPARM1_SDSYNCEN_Set(1U));
}

/*!
 *
 * \brief Enable filter
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 *
 * This function enables the filter specified by the \e filterNumber variable.
 *
 */
static inline void SDFM_enableFilter(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber)
{
    uint16_t *ptr;

    assert(SDFM_isBaseValid(base));

    /* Set the FEN bit */
    ptr   = (uint16_t *)&(base->SDDFPARM1) + ((uint32_t)filterNumber * 16U);
    *ptr |= (SDFM_SDDFPARM1_FEN_Set(1U));
}

/*!
 *
 * \brief Disable filter
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 *
 * This function disables the filter specified by the \e filterNumber
 * variable.
 *
 */
static inline void SDFM_disableFilter(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber)
{
    uint16_t *ptr;
    assert(SDFM_isBaseValid(base));

    /* Clear the FEN bit */
    ptr   = (uint16_t *)&(base->SDDFPARM1) + ((uint32_t)filterNumber * 16U);
    *ptr &= ~(SDFM_SDDFPARM1_FEN_Set(1U));
}

/*!
 *
 * \brief Enable FIFO buffer
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 *
 * This function enables the filter FIFO buffer specified by the
 * \e filterNumber variable.
 *
 */
static inline void SDFM_enableFIFOBuffer(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber)
{
    uint16_t *ptr;
    assert(SDFM_isBaseValid(base));

    /* Set the FFEN bit */
    ptr   = (uint16_t *)&(base->SDFIFOCTL1) + ((uint32_t)filterNumber * 16U);
    *ptr |= (SDFM_SDFIFOCTL1_FFEN_Set(1U));
}

/*!
 *
 * \brief Disable FIFO buffer
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 *
 * This function disables the filter FIFO buffer specified by the
 * \e filterNumber variable.
 *
 */
static inline void SDFM_disableFIFOBuffer(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber)
{
    uint16_t *ptr;
    assert(SDFM_isBaseValid(base));

    /* Clear the FFEN bit */
    ptr   = (uint16_t *)&(base->SDFIFOCTL1) + ((uint32_t)filterNumber * 16U);
    *ptr &= ~(SDFM_SDFIFOCTL1_FFEN_Set(1U));
}

/*!
 *
 * \brief Return the Zero Cross Trip status
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 *
 * This function returns the Zero Cross Trip status for the filter
 * specified by filterNumber variable.
 *
 * \retval true if Comparator filter output >= High-level threshold (Z)
 * \retval false if Comparator filter output < High-level threshold (Z)
 *
 */
static inline bool SDFM_getZeroCrossTripStatus(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber)
{
    assert(SDFM_isBaseValid(base));

    return (((base->SDSTATUS >> (uint16_t)filterNumber) & 0x1U) == 1U);
}

/*!
 *
 * \brief Clear the Zero Cross Trip status
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 *
 *  This function clears the Zero Cross Trip status for the filter
 *  specified by filterNumber variable.
 *
 */
static inline void SDFM_clearZeroCrossTripStatus(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber)
{
    assert(SDFM_isBaseValid(base));

    /* Set SDCTL HZx bit */
    base->SDCTL |= (1U << filterNumber);
}

/*!
 *
 * \brief Enable Comparator.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 *
 *  This function enables the Comparator for the selected filter.
 *
 */
static inline void SDFM_enableComparator(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber)
{
    uint16_t *ptr;
    assert(SDFM_isBaseValid(base));

    /* Set CEN bit */
    ptr   = (uint16_t *)&(base->SDCPARM1) + ((uint32_t)filterNumber * 16U);
    *ptr |= (SDFM_SDCPARM1_CEN_Set(1U));
}

/*!
 *
 * \brief Disable Comparator.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 *
 *  This function disables the Comparator for the selected filter.
 *
 */
static inline void SDFM_disableComparator(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber)
{
    uint16_t *ptr;
    assert(SDFM_isBaseValid(base));

    /* Clear CEN bit */
    ptr   = (uint16_t *)&(base->SDCPARM1) + ((uint32_t)filterNumber * 16U);
    *ptr &= ~(SDFM_SDCPARM1_CEN_Set(1U));
}

/*!
 *
 * \brief Selects Comparator Event Source.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number
 * \param[in] compEventNum is the event number
 * \param[in] compEventSource is the event source
 *
 *  This function selects the comparator event source. Valid values for
 * \e compEventNum are:
 * - SDFM_COMP_EVENT_1 - Selects comparator event 1
 * - SDFM_COMP_EVENT_2 - Selects comparator event 2
 * Valid values for \e SDFM_COMP_EVENT_1 are:
 * - SDFM_COMP_EVENT_SRC_COMPH1 - COMPH1 event is the source for selected event
 * - SDFM_COMP_EVENT_SRC_COMPH1_L1 - Either of COMPH1 or COMPL1 event can be
 *                                   the source for selected event
 * - SDFM_COMP_EVENT_SRC_COMPH2 - COMPH2 event is the source for selected event
 * - SDFM_COMP_EVENT_SRC_COMPH2_L2 - Either of COMPH2 or COMPL2 event can be
 *                                   the source for selected event
 *
 * Valid values for \e SDFM_COMP_EVENT_2 are:
 * - SDFM_COMP_EVENT_SRC_COMPL1 - COMPL1 event is the source for selected event
 * - SDFM_COMP_EVENT_SRC_COMPH1_L1 - Either of COMPH1 or COMPL1 event can be
 *                                   the source for selected event
 * - SDFM_COMP_EVENT_SRC_COMPL2 - COMPL2 event is the source for selected event
 * - SDFM_COMP_EVENT_SRC_COMPH2_L2 - Either of COMPH2 or COMPL2 event can be
 *                                   the source for selected event
 *
 */
static inline void SDFM_selectCompEventSource(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber,
                                              SDFM_CompEventNumber_t compEventNum,
                                              SDFM_CompEventSource_t compEventSource)
{
    uint16_t *ptr;
    assert(SDFM_isBaseValid(base));

    ptr = (uint16_t *)&(base->SDCPARM1) + ((uint32_t)filterNumber * 16U);


    /* Select source for selected comparator event */
    *ptr = (*ptr & ~((uint16_t)0x2U << compEventNum)) | ((uint16_t)compEventSource << compEventNum);
}

/*!
 *
 * \brief Set filter type.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 * \param[in] filterType is the filter type or structure.
 *
 * This function sets the filter type or structure to be used as specified by
 * filterType for the selected filter number as specified by filterNumber.
 *
 */
static inline void SDFM_setFilterType(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber,
                                      SDFM_FilterType_t filterType)
{
    uint16_t *ptr;
    assert(SDFM_isBaseValid(base));

    ptr = (uint16_t *)&(base->SDDFPARM1) + ((uint32_t)filterNumber * 16U);
    /* Write to SST bits */
    *ptr = (*ptr & (~SDFM_SDDFPARM1_SST_Msk)) | ((uint16_t)filterType << 6U);
}

/*!
 *
 * \brief Set data filter over sampling ratio.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 * \param[in] overSamplingRatio is the data filter over sampling ratio.
 *
 * This function sets the filter oversampling ratio for the filter specified
 * by the filterNumber variable.Valid values for the variable
 * overSamplingRatio are 0 to 255 inclusive. The actual oversampling ratio
 * will be this value plus one.
 *
 */
static inline void SDFM_setFilterOverSamplingRatio(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber,
                                                   uint16_t overSamplingRatio)
{
    uint16_t *ptr;
    assert(SDFM_isBaseValid(base));
    assert(overSamplingRatio < 256U);

    ptr = (uint16_t *)&(base->SDDFPARM1) + ((uint32_t)filterNumber * 16U);

    /* Write to DOSR bits */
    *ptr = (*ptr & (~SDFM_SDDFPARM1_DOSR_Msk)) | overSamplingRatio;
}

/*!
 *
 * \brief Set modulator clock mode.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 * \param[in] clockMode is the modulator clock mode.
 *
 * This function sets the modulator clock mode specified by clockMode
 * for the filter specified by filterNumber.
 *
 * \note This function also enables the data and clock synchronizers for
 * the specified filter.
 *
 */
static inline void SDFM_setupModulatorClock(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber,
                                            SDFM_ModulatorClockMode_t clockMode)
{
    uint16_t *ptr;
    assert(SDFM_isBaseValid(base));

    ptr = (uint16_t *)&(base->SDCTLPARM1) + ((uint32_t)filterNumber * 16U);

    /* Write to MOD bits */
    *ptr = (*ptr & (~SDFM_SDCTLPARM1_MOD_Msk)) | (uint16_t)clockMode;
}

/*!
 *
 * \brief Set the output data format
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 * \param[in] dataFormat is the output data format.
 *
 * This function sets the output data format for the filter specified by
 * filterNumber.
 *
 */
static inline void SDFM_setOutputDataFormat(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber,
                                            SDFM_OutputDataFormat_t dataFormat)
{
    uint16_t *ptr;
    assert(SDFM_isBaseValid(base));

    ptr = (uint16_t *)&(base->SDDPARM1) + ((uint32_t)filterNumber * 16U);

    /* Write to DR bit */
    *ptr = (*ptr & (~SDFM_SDDPARM1_DR_Msk)) | ((uint16_t)dataFormat << 10U);
}

/*!
 *
 * \brief Set data shift value.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 * \param[in] shiftValue is the data shift value.
 *
 * This function sets the shift value for the 16 bit 2's complement data
 * format. The valid maximum value for shiftValue is 31.
 *
 * Note: Use this function with 16 bit 2's complement data format only.
 *
 */
static inline void SDFM_setDataShiftValue(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber, uint16_t shiftValue)
{
    uint16_t *ptr;

    assert(SDFM_isBaseValid(base));
    assert(shiftValue < 32U);

    ptr = (uint16_t *)&(base->SDDPARM1) + ((uint32_t)filterNumber * 16U);

    /* Write to SH bit */
    *ptr = (*ptr & (~SDFM_SDDPARM1_SH_Msk)) | (shiftValue << SDFM_SDDPARM1_SH_Pos);
}


/*!
 *
 * \brief Set Filter output high-level threshold.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 * \param[in] highThreshold is the high-level threshold 1 & 2.
 *
 * This function sets the unsigned high-level threshold value for the
 * Comparator filter output. If the output value of the filter exceeds
 * highThreshold and interrupt generation is enabled, an interrupt will be
 * issued. The param highThreshold takes both high threshold 1 & 2 values.
 * The upper 16-bits represent the high threshold 2 value while lower 16-bits
 * represent the threshold 1 values.
 *
 */
static inline void SDFM_setCompFilterHighThreshold(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber,
                                                   uint32_t highThreshold)
{
    uint16_t *ptr;

    assert(SDFM_isBaseValid(base));
    assert((uint16_t)highThreshold <= SDFM_SDFLT1CMPH1_HLT_Msk);
    assert((uint16_t)(highThreshold >> 16U) <= SDFM_SDFLT1CMPH2_HLT2_Msk);

    ptr = (uint16_t *)&(base->SDFLT1CMPH1) + ((uint32_t)filterNumber * 16U);

    /* Write to HLT bit */
    *ptr  = (*ptr & ~SDFM_SDFLT1CMPH1_HLT_Msk) | (uint16_t)highThreshold;
    ptr  += 8U;
    *ptr  = (*ptr & ~SDFM_SDFLT1CMPH2_HLT2_Msk) | (uint16_t)(highThreshold >> 16U);
}

/*!
 *
 * \brief Set Filter output low-level threshold.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number
 * \param[in] lowThreshold is the low-level threshold
 *
 * This function sets the unsigned low-level threshold value 1 or 2 for the
 * Comparator filter output. If the output value of the filter gets below
 * lowThreshold and interrupt generation is enabled, an interrupt will be
 * issued. The param lowThreshold takes both low threshold 1 & 2 values.
 * The upper 16-bits represent the low threshold 2 value while lower 16-bits
 * represent the threshold 1 values.
 *
 */
static inline void SDFM_setCompFilterLowThreshold(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber,
                                                  uint32_t lowThreshold)
{
    uint16_t *ptr;

    assert(SDFM_isBaseValid(base));
    assert((uint16_t)lowThreshold <= SDFM_SDFLT1CMPL1_LLT_Msk);
    assert((uint16_t)(lowThreshold >> 16U) <= SDFM_SDFLT1CMPL2_LLT2_Msk);

    ptr = (uint16_t *)&(base->SDFLT1CMPL1) + ((uint32_t)filterNumber * 16U);

    /* Write to LLT bit. */
    *ptr  = (*ptr & ~SDFM_SDFLT1CMPL1_LLT_Msk) | (uint16_t)lowThreshold;
    ptr  += 11U;
    *ptr  = (*ptr & ~SDFM_SDFLT1CMPL2_LLT2_Msk) | (uint16_t)(lowThreshold >> 16U);
}

/*!
 *
 * \brief Set Filter output zero-cross threshold.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 * \param[in] zeroCrossThreshold is the zero-cross threshold.
 *
 * This function sets the unsigned zero-cross threshold value for the
 * Comparator filter output.
 *
 */
static inline void SDFM_setCompFilterZeroCrossThreshold(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber,
                                                        uint16_t zeroCrossThreshold)
{
    uint16_t *ptr;

    assert(SDFM_isBaseValid(base));
    assert(zeroCrossThreshold < 0x7FFFU);

    ptr = (uint16_t *)&(base->SDFLT1CMPHZ) + ((uint32_t)filterNumber * 16U);

    /* Write to ZCT bit */
    *ptr = (*ptr & ~SDFM_SDFLT1CMPHZ_HLTZ_Msk) | zeroCrossThreshold;
}

/*!
 *
 * \brief Enable zero-cross Edge detect mode.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 *
 * This function enables Zero Cross Edge detection.
 *
 */
static inline void SDFM_enableZeroCrossEdgeDetect(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber)
{
    uint16_t *ptr;

    assert(SDFM_isBaseValid(base));

    /* Set ZCEN bit */
    ptr   = (uint16_t *)&(base->SDCPARM1) + ((uint32_t)filterNumber * 16U);
    *ptr |= (SDFM_SDCPARM1_HZEN_Set(1));
}

/*!
 *
 * \brief Disable zero-cross Edge detect mode.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 *
 * This function disables Zero Cross Edge detection.
 *
 */
static inline void SDFM_disableZeroCrossEdgeDetect(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber)
{
    uint16_t *ptr;
    assert(SDFM_isBaseValid(base));

    /* Clear ZCEN bit */
    ptr   = (uint16_t *)&(base->SDCPARM1) + ((uint32_t)filterNumber * 16U);
    *ptr &= ~(SDFM_SDCPARM1_HZEN_Set(1));
}


/*!
 *
 * \brief Enable SDFM interrupts.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 * \param[in] intFlags is the interrupt source.
 *
 * This function enables the low threshold , high threshold or modulator
 * failure interrupt as determined by intFlags for the filter specified
 * by filterNumber.
 * Valid values for intFlags are:
 *  SDFM_MODULATOR_FAILURE_INTERRUPT , SDFM_LOW_LEVEL_THRESHOLD_INTERRUPT,
 *  SDFM_HIGH_LEVEL_THRESHOLD_INTERRUPT, SDFM_FIFO_INTERRUPT,
 *  SDFM_FIFO_OVERFLOW_INTERRUPT,SDFM_DATA_FILTER_ACKNOWLEDGE_INTERRUPT
 *
 */
static inline void SDFM_enableInterrupt(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber, uint16_t intFlags)
{
    uint16_t  offset;
    uint16_t *ptr;
    assert(SDFM_isBaseValid(base));

    offset = (uint16_t)filterNumber * 16U;

    /* Low, high threshold, Modulator failure */
    if ((intFlags & (SDFM_MODULATOR_FAILURE_INTERRUPT | SDFM_LOW_LEVEL_THRESHOLD_INTERRUPT |
                     SDFM_HIGH_LEVEL_THRESHOLD_INTERRUPT)) != 0U)
    {
        /* Set IEL or IEH or MFIE bit of SDFM_O_SDCPARMx */
        ptr   = (uint16_t *)&(base->SDCPARM1) + offset;
        *ptr |= (intFlags & (SDFM_MODULATOR_FAILURE_INTERRUPT | SDFM_LOW_LEVEL_THRESHOLD_INTERRUPT |
                             SDFM_HIGH_LEVEL_THRESHOLD_INTERRUPT));
    }

    /* Data filter acknowledge interrupt */
    if ((intFlags & SDFM_DATA_FILTER_ACKNOWLEDGE_INTERRUPT) != 0U)
    {
        ptr   = (uint16_t *)&(base->SDDFPARM1) + offset;
        *ptr |= (SDFM_SDDFPARM1_AE_Set(1));
    }

    /* FIFO , FIFO overflow interrupt */
    if ((intFlags & (SDFM_FIFO_INTERRUPT | SDFM_FIFO_OVERFLOW_INTERRUPT | SDFM_FIFO_UNDERFLOW_INTERRUPT)) != 0U)
    {
        /* Set OVFIEN or FFIEN bits of SDFM_O_SDFIFOCTLx */
        ptr   = (uint16_t *)&(base->SDFIFOCTL1) + offset;
        *ptr |= (intFlags & (SDFM_FIFO_INTERRUPT | SDFM_FIFO_OVERFLOW_INTERRUPT | SDFM_FIFO_UNDERFLOW_INTERRUPT));
    }
}

/*!
 *
 * \brief Disable SDFM interrupts.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 * \param[in] intFlags is the interrupt source.
 *
 * This function disables the low threshold , high threshold or modulator
 * failure interrupt as determined by intFlags for the filter
 * specified by filterNumber.
 * Valid values for intFlags are:
 *  SDFM_MODULATOR_FAILURE_INTERRUPT , SDFM_LOW_LEVEL_THRESHOLD_INTERRUPT,
 *  SDFM_HIGH_LEVEL_THRESHOLD_INTERRUPT, SDFM_FIFO_INTERRUPT,
 *  SDFM_FIFO_OVERFLOW_INTERRUPT,SDFM_DATA_FILTER_ACKNOWLEDGE_INTERRUPT
 *
 */
static inline void SDFM_disableInterrupt(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber, uint16_t intFlags)
{
    uint16_t  offset;
    uint16_t *ptr;

    assert(SDFM_isBaseValid(base));

    offset = (uint16_t)filterNumber * 16U;

    /* Low, high threshold, modulator failure interrupts */
    if ((intFlags & (SDFM_MODULATOR_FAILURE_INTERRUPT | SDFM_LOW_LEVEL_THRESHOLD_INTERRUPT |
                     SDFM_HIGH_LEVEL_THRESHOLD_INTERRUPT)) != 0U)
    {
        /* Set IEL or IEH or MFIE bit of SDFM_O_SDCPARMx */
        ptr   = (uint16_t *)&(base->SDCPARM1) + offset;
        *ptr &= ~(intFlags & (SDFM_MODULATOR_FAILURE_INTERRUPT | SDFM_LOW_LEVEL_THRESHOLD_INTERRUPT |
                              SDFM_HIGH_LEVEL_THRESHOLD_INTERRUPT));
    }

    /* Data filter acknowledge interrupt */
    if ((intFlags & SDFM_DATA_FILTER_ACKNOWLEDGE_INTERRUPT) != 0U)
    {
        ptr   = (uint16_t *)&(base->SDDFPARM1) + offset;
        *ptr &= ~(SDFM_SDDFPARM1_AE_Set(1));
    }

    /* FIFO , FIFO overflow interrupt */
    if ((intFlags & (SDFM_FIFO_INTERRUPT | SDFM_FIFO_OVERFLOW_INTERRUPT | SDFM_FIFO_UNDERFLOW_INTERRUPT)) != 0U)
    {
        /* Set OVFIEN or FFIEN bits of SDFM_O_SDFIFOCTLx */
        ptr   = (uint16_t *)&(base->SDFIFOCTL1) + offset;
        *ptr &= ~(intFlags & (SDFM_FIFO_INTERRUPT | SDFM_FIFO_OVERFLOW_INTERRUPT | SDFM_FIFO_UNDERFLOW_INTERRUPT));
    }
}

/*!
 *
 * \brief Set the comparator filter type.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 * \param[in] filterType is the comparator filter type or structure.
 *
 * This function sets the Comparator filter type or structure to be used as
 * specified by filterType for the selected filter number as specified by
 * filterNumber.
 *
 */
static inline void SDFM_setComparatorFilterType(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber,
                                                SDFM_FilterType_t filterType)
{
    uint16_t *ptr;

    assert(SDFM_isBaseValid(base));

    ptr = (uint16_t *)&(base->SDCPARM1) + ((uint32_t)filterNumber * 16U);

    /* Write to CS1_CS0 bits */

    *ptr = (*ptr & (~SDFM_SDCPARM1_CS1_CS0_Msk)) | ((uint16_t)filterType << 3U);
}

/*!
 *
 * \brief Set Comparator filter over sampling ratio.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 * \param[in] overSamplingRatio is the comparator filter over sampling ration.
 *
 * This function sets the comparator filter oversampling ratio for the filter
 * specified by the filterNumber.Valid values for the variable
 * overSamplingRatio are 0 to 31 inclusive.
 * The actual oversampling ratio will be this value plus one.
 *
 */
static inline void SDFM_setCompFilterOverSamplingRatio(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber,
                                                       uint16_t overSamplingRatio)
{
    uint16_t *ptr;

    assert(SDFM_isBaseValid(base));
    assert(overSamplingRatio < 32U);

    ptr = (uint16_t *)&(base->SDCPARM1) + ((uint32_t)filterNumber * 16U);

    /* Write to COSR bits */
    *ptr = (*ptr & (~SDFM_SDCPARM1_COSR_Msk)) | overSamplingRatio;
}

/*!
 *
 * \brief Get the filter data output.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 *
 * This function returns the latest data filter output. Depending on the
 * filter data output format selected, the valid value will be the lower 16
 * bits or the whole 32 bits of the returned value.
 *
 * \return Returns the latest data filter output.
 *
 */
static inline uint32_t SDFM_getFilterData(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber)
{
    uint32_t *ptr;

    assert(SDFM_isBaseValid(base));

    ptr = (uint32_t *)&(base->SDDATA1) + ((uint32_t)filterNumber * 8U);

    /* Read SDDATA bits */
    return (*ptr);
}

/*!
 *
 * \brief Get the Comparator threshold status.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 *
 * This function returns the Comparator output threshold status for the given
 * filterNumber.
 *
 * \retval kSDFM_OUTPUT_WITHIN_THRESHOLD if the output is within the specified threshold.
 * \retval kSDFM_OUTPUT_ABOVE_THRESHOLD  if the output is above the high threshold.
 * \retval kSDFM_OUTPUT_BELOW_THRESHOLD  if the output is below the low threshold.
 *
 */
static inline SDFM_OutputThresholdStatus_t SDFM_getThresholdStatus(SDFM_REGS_Type     *base,
                                                                   SDFM_FilterNumber_t filterNumber)
{
    uint32_t *ptr;

    assert(SDFM_isBaseValid(base));

    ptr = (uint32_t *)&(base->SDIFLG);

    /* Read SDIFLG high/low threshold bits */
    return ((SDFM_OutputThresholdStatus_t)((*ptr >> (2U * (uint16_t)filterNumber)) & 0x3U));
}

/*!
 *
 * \brief Get the Modulator status.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 *
 * This function returns the Modulator status.
 *
 * \retval true if the Modulator is operating normally.
 * \retval false if the Modulator has failed.
 *
 */
static inline bool SDFM_getModulatorStatus(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber)
{
    uint32_t *ptr;

    assert(SDFM_isBaseValid(base));

    ptr = (uint32_t *)&(base->SDIFLG);

    /* Read SDIFLG MF1, MF2, MF3 OR MF4 bits */
    return (((*ptr >> ((uint16_t)filterNumber + 8U)) & 0x1U) != 0x1U);
}

/*!
 *
 * \brief Check if new Filter data is available.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 *
 * This function returns new filter data status.
 *
 * \retval true if new filter data is available.
 * \retval false if no new filter data is available.
 *
 */
static inline bool SDFM_getNewFilterDataStatus(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber)
{
    uint32_t *ptr;

    assert(SDFM_isBaseValid(base));

    ptr = (uint32_t *)&(base->SDIFLG);

    /* Read SDIFLG AF1, AF2, AF3 OR AF4 bits */
    return (((*ptr >> ((uint16_t)filterNumber + 12U)) & 0x1U) == 0x1U);
}

/*!
 *
 * \brief Check if FIFO buffer is overflowed.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 *
 * This function returns the status of the FIFO buffer overflow for the given
 * filter value.
 *
 * \retval true if FIFO buffer is overflowed.
 * \retval false if FIFO buffer is not overflowed.
 *
 */
static inline bool SDFM_getFIFOOverflowStatus(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber)
{
    uint32_t *ptr;
    assert(SDFM_isBaseValid(base));

    /* Read SDIFLG SDFFOVF1, SDFFOVF2, SDFFOVF3 OR SDFFOVF4 bits */

    ptr = (uint32_t *)&(base->SDIFLG);

    return (((*ptr >> ((uint16_t)filterNumber + 16U)) & 0x1U) == 0x1U);
}

/*!
 *
 * \brief Check FIFO buffer interrupt status.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 *
 * This function returns the status of the FIFO buffer interrupt for the given
 * filter.
 *
 * \retval true if FIFO buffer interrupt has occurred.
 * \retval false if FIFO buffer interrupt has not occurred.
 *
 */
static inline bool SDFM_getFIFOISRStatus(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber)
{
    uint32_t *ptr;
    assert(SDFM_isBaseValid(base));

    ptr = (uint32_t *)&(base->SDIFLG);

    /* Read SDIFLG SDFFINT1, SDFFINT2, SDFFINT3 OR SDFFINT4 bits */
    return (((*ptr >> ((uint16_t)filterNumber + 20U)) & 0x1U) == 0x1U);
}

/*!
 *
 * \brief Check FIFO buffer is underflow.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 *
 * This function returns the status of the FIFO buffer underflow for the given
 * filter value.
 *
 * \retval true if FIFO buffer is underflowed.
 * \retval false if FIFO buffer is not underflowed.
 *
 */
static inline bool SDFM_getFIFOUnderflowStatus(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber)
{
    uint32_t *ptr;
    assert(SDFM_isBaseValid(base));

    ptr = (uint32_t *)&(base->SDIFLG);

    /* Read SDIFLG SDFFINT1, SDFFINT2, SDFFINT3 OR SDFFINT4 bits */
    return (((*ptr >> ((uint16_t)filterNumber + 24U)) & 0x1U) == 0x1U);
}

/*!
 *
 * \brief Get pending interrupt.
 *
 * \param[in] base is the base address of the SDFM module
 *
 * This function returns any pending interrupt status.
 *
 * \retval true if there is a pending interrupt.
 * \retval false if no interrupt is pending.
 *
 */
static inline bool SDFM_getIsrStatus(SDFM_REGS_Type *base)
{
    uint32_t *ptr;
    assert(SDFM_isBaseValid(base));

    ptr = (uint32_t *)&(base->SDIFLG);

    /* Read SDIFLG MIF */
    return ((*ptr >> 31U) == 0x1U);
}

/*!
 *
 * \brief Clear pending flags.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] flag is the SDFM status
 *
 * This function clears the specified pending interrupt flag.
 * Valid values are
 * SDFM_MASTER_INTERRUPT_FLAG,SDFM_FILTER_1_NEW_DATA_FLAG,
 * SDFM_FILTER_2_NEW_DATA_FLAG,SDFM_FILTER_3_NEW_DATA_FLAG,
 * SDFM_FILTER_4_NEW_DATA_FLAG,SDFM_FILTER_1_MOD_FAILED_FLAG,
 * SDFM_FILTER_2_MOD_FAILED_FLAG,SDFM_FILTER_3_MOD_FAILED_FLAG,
 * SDFM_FILTER_4_MOD_FAILED_FLAG,SDFM_FILTER_1_HIGH_THRESHOLD_FLAG,
 * SDFM_FILTER_1_LOW_THRESHOLD_FLAG,SDFM_FILTER_2_HIGH_THRESHOLD_FLAG,
 * SDFM_FILTER_2_LOW_THRESHOLD_FLAG,SDFM_FILTER_3_HIGH_THRESHOLD_FLAG,
 * SDFM_FILTER_3_LOW_THRESHOLD_FLAG,SDFM_FILTER_4_HIGH_THRESHOLD_FLAG,
 * SDFM_FILTER_4_LOW_THRESHOLD_FLAG,SDFM_FILTER_1_FIFO_OVERFLOW_FLAG,
 * SDFM_FILTER_2_FIFO_OVERFLOW_FLAG,SDFM_FILTER_3_FIFO_OVERFLOW_FLAG
 * SDFM_FILTER_4_FIFO_OVERFLOW_FLAG,SDFM_FILTER_1_FIFO_INTERRUPT_FLAG,
 * SDFM_FILTER_2_FIFO_INTERRUPT_FLAG,SDFM_FILTER_3_FIFO_INTERRUPT_FLAG
 * SDFM_FILTER_4_FIFO_INTERRUPT_FLAG or any combination of the above flags.
 *
 */
static inline void SDFM_clearInterruptFlag(SDFM_REGS_Type *base, uint32_t flag)
{
    uint32_t *ptr;
    assert(SDFM_isBaseValid(base));
    assert((flag & 0x8FFFFFFFU) == flag);

    ptr = (uint32_t *)&(base->SDIFLGCLR);

    /* Write to  SDIFLGCLR register */
    *ptr |= flag;
}

/*!
 *
 * \brief Enable master interrupt.
 *
 * \param[in] base is the base address of the SDFM module
 *
 * This function enables the master SDFM interrupt.
 *
 */
static inline void SDFM_enableMasterInterrupt(SDFM_REGS_Type *base)
{
    uint32_t *ptr;
    assert(SDFM_isBaseValid(base));

    ptr = (uint32_t *)&(base->SDCTL);

    /* Set SDCTL MIE bit */
    *ptr |= SDFM_SDCTL_MIE_Set(1);
}

/*!
 *
 * \brief Disable master interrupt.
 *
 * \param[in] base is the base address of the SDFM module
 *
 * This function disables the master SDFM interrupt.
 *
 */
static inline void SDFM_disableMasterInterrupt(SDFM_REGS_Type *base)
{
    uint32_t *ptr;
    assert(SDFM_isBaseValid(base));

    ptr = (uint32_t *)&(base->SDCTL);

    /* Clear SDCTL MIE bit */
    *ptr &= ~(SDFM_SDCTL_MIE_Set(1));
}

/*!
 *
 * \brief Enable master filter.
 *
 * \param[in] base is the base address of the SDFM module
 *
 * This function enables master filter.
 *
 */
static inline void SDFM_enableMasterFilter(SDFM_REGS_Type *base)
{
    uint16_t *ptr;
    assert(SDFM_isBaseValid(base));

    ptr = (uint16_t *)&(base->SDMFILEN);

    /* Set SDMFILEN MFE bit */
    *ptr |= (SDFM_SDMFILEN_MFE_Set(1));
}

/*!
 *
 * \brief Disable master filter.
 *
 * \param[in] base is the base address of the SDFM module
 *
 * This function disables master filter.
 *
 */
static inline void SDFM_disableMasterFilter(SDFM_REGS_Type *base)
{
    uint16_t *ptr;
    assert(SDFM_isBaseValid(base));

    ptr = (uint16_t *)&(base->SDMFILEN);

    /* Clear SDMFILEN MFE bit */
    *ptr &= ~(SDFM_SDMFILEN_MFE_Set(1));
}

/*!
 *
 * \brief Return the FIFO data count
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 *
 * This function returns the FIFO data count.
 *
 * \return Returns the number of data words available in FIFO buffer.
 *
 */
static inline uint16_t SDFM_getFIFODataCount(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber)
{
    uint16_t *ptr;
    assert(SDFM_isBaseValid(base));

    ptr = (uint16_t *)&(base->SDFIFOCTL1) + ((uint32_t)filterNumber * 16U);

    /* Read SDFFST */
    return ((*ptr & SDFM_SDFIFOCTL1_SDFFST_Msk) >> SDFM_SDFIFOCTL1_SDFFST_Pos);
}

/*!
 *
 * \brief Return the Comparator sinc filter data
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 *
 * This function returns the Comparator sinc filter data output.
 *
 * \return Returns the Comparator sinc filter data output.
 *
 */
static inline uint16_t SDFM_getComparatorSincData(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber)
{
    uint16_t *ptr;
    assert(SDFM_isBaseValid(base));

    ptr = (uint16_t *)&(base->SDCDATA1) + ((uint32_t)filterNumber * 16U);

    /* Read SDCDATA */
    return (*ptr);
}

/*!
 *
 * \brief Return the FIFO data
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 *
 * This function returns the latest FIFO data.
 *
 * \return Returns the latest FIFO data.
 *
 * \note Discard the upper 16 bits if the output data format is 16bits.
 *
 */
static inline uint32_t SDFM_getFIFOData(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber)
{
    uint32_t *ptr;
    assert(SDFM_isBaseValid(base));

    ptr = (uint32_t *)&(base->SDDATFIFO1) + ((uint32_t)filterNumber * 8U);
    /* Read SDDATFIFO */
    return (*ptr);
}

/*!
 *
 * \brief Set the FIFO interrupt level.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 * \param[in] fifoLevel is the FIFO interrupt level.
 *
 * This function sets the FIFO interrupt level. Interrupt is generated when
 * the FIFO buffer word count gets to or exceeds the value of \e fifoLevel.
 * Maximum value for \e fifoLevel is 16.
 *
 */
static inline void SDFM_setFIFOInterruptLevel(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber,
                                              uint16_t fifoLevel)
{
    uint16_t *ptr;

    assert(SDFM_isBaseValid(base));
    assert(fifoLevel <= 16U);

    ptr = (uint16_t *)&(base->SDFIFOCTL1) + ((uint32_t)filterNumber * 16U);

    /* Write to SDFFIL bit */
    *ptr = ((*ptr & (~SDFM_SDFIFOCTL1_SDFFIL_Msk)) | fifoLevel);
}

/*!
 *
 * \brief Set data ready interrupt source.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 * \param[in] dataReadySource is the data ready interrupt source.
 *
 * This function sets the data ready interrupt source.
 * Valid values for \e dataReadySource:
 *   - SDFM_DATA_READY_SOURCE_DIRECT - Direct data ready
 *   - SDFM_DATA_READY_SOURCE_FIFO  - FIFO data ready.
 *
 */
static inline void SDFM_setDataReadyInterruptSource(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber,
                                                    SDFM_DataReadyInterruptSource_t dataReadySource)
{
    uint16_t *ptr;

    assert(SDFM_isBaseValid(base));

    ptr = (uint16_t *)&(base->SDFIFOCTL1) + ((uint32_t)filterNumber * 16U);

    /* Write to DRINTSEL */
    *ptr = (*ptr & ~SDFM_SDFIFOCTL1_DRINTSEL_Msk) | ((uint16_t)dataReadySource << SDFM_SDFIFOCTL1_DRINTSEL_Pos);
}

/*!
 *
 * \brief Get the wait-for-sync event status.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 *
 * This function returns the Wait-for-Sync event status.
 *
 * \retval true if sync event has occurred.
 * \retval false if sync event has not occurred.
 *
 */
static inline bool SDFM_getWaitForSyncStatus(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber)
{
    uint16_t *ptr;
    assert(SDFM_isBaseValid(base));

    ptr = (uint16_t *)&(base->SDSYNC1) + ((uint32_t)filterNumber * 16U);

    /* Read WTSYNFLG bit */
    return (((*ptr & SDFM_SDSYNC1_WTSYNFLG_Msk) >> SDFM_SDSYNC1_WTSYNFLG_Pos) == 0x1U);
}

/*!
 *
 * \brief Clear the Wait-for-sync event status.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 *
 * This function clears the Wait-for-sync event status.
 *
 */
static inline void SDFM_clearWaitForSyncFlag(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber)
{
    uint16_t *ptr;
    assert(SDFM_isBaseValid(base));

    ptr = (uint16_t *)&(base->SDSYNC1) + ((uint32_t)filterNumber * 16U);

    /* Clear WTSYNCLR bit */
    *ptr |= SDFM_SDSYNC1_WTSYNCLR_Set(1);
}

/*!
 *
 * \brief Enable wait for sync mode.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 *
 * This function enables the wait for sync mode. Data to FIFO will be written
 * only after PWM sync event.
 *
 */
static inline void SDFM_enableWaitForSync(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber)
{
    uint16_t *ptr;
    assert(SDFM_isBaseValid(base));

    ptr = (uint16_t *)&(base->SDSYNC1) + ((uint32_t)filterNumber * 16U);

    /* Set WTSYNCEN bit */
    *ptr |= SDFM_SDSYNC1_WTSYNCEN_Set(1);
}

/*!
 *
 * \brief Disable wait for sync mode.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 *
 * This function disables the wait for sync mode. Data to FIFO will be written
 * every Data ready event.
 *
 */
static inline void SDFM_disableWaitForSync(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber)
{
    uint16_t *ptr;
    assert(SDFM_isBaseValid(base));

    ptr = (uint16_t *)&(base->SDSYNC1) + ((uint32_t)filterNumber * 16U);

    /* Clear WTSYNCEN bit */
    *ptr &= ~(SDFM_SDSYNC1_WTSYNCEN_Set(1));
}

/*!
 *
 * \brief Set the PWM sync mode.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 * \param[in] syncSource is the PWM sync source.
 *
 * This function sets the PWM sync source for the specific SDFM filter. Valid
 * values for syncSource are SDFM_SYNC_PWMx_CMPy. Where x ranges from 1 to 8
 * Representing PWM1 to PWM8 respectively and y ranges from A to D
 * representing PWM comparators A to D.
 *
 */
static inline void SDFM_setPWMSyncSource(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber,
                                         SDFM_PWMSyncSource_t syncSource)
{
    uint16_t *ptr;

    assert(SDFM_isBaseValid(base));

    ptr = (uint16_t *)&(base->SDSYNC1) + ((uint32_t)filterNumber * 16U);

    /* Write to SYNCSEL bits */
    *ptr = (*ptr & ~SDFM_SDSYNC1_SYNCSEL_Msk) | (uint16_t)syncSource;

    /*! Enable SDSYNC reset to data filter */
    SDFM_enableExternalReset(base, filterNumber);
}

/*!
 *
 * \brief Set FIFO clear on sync mode.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 * \param[in] fifoClearSyncMode is the FIFO clear on sync mode.
 *
 * This function sets the FIFO clear mode for the specified filter when a sync
 * happens depending on the value of fifoClearSyncMode.
 * Valid values for fifoClearSyncMode are:
 *  - SDFM_FIFO_NOT_CLEARED_ON_SYNC - FIFO is not cleared on sync.
 *  - SDFM_FIFO_CLEARED_ON_SYNC - FIFO is cleared on sync.
 *
 */
static inline void SDFM_setFIFOClearOnSyncMode(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber,
                                               SDFM_FIFOClearSyncMode_t fifoClearSyncMode)
{
    uint16_t *ptr;

    assert(SDFM_isBaseValid(base));

    ptr = (uint16_t *)&(base->SDSYNC1) + ((uint32_t)filterNumber * 16U);

    /* Write to FFSYNCCLREN bit */
    *ptr = (*ptr & ~SDFM_SDSYNC1_FFSYNCCLREN_Msk) | ((uint16_t)fifoClearSyncMode << 9U);
}

/*!
 *
 * \brief Set Wait-for-sync clear mode.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 * \param[in] syncClearMode is the wait-for-sync clear mode.
 *
 * This function sets the Wait-For-sync clear mode depending on the value of
 * syncClearMode.
 * Valid values for syncClearMode are:
 *   - SDFM_MANUAL_CLEAR_WAIT_FOR_SYNC - Wait-for-sync flag is cleared by
 *                                       invoking SDFM_clearWaitForSyncFlag().
 *   - SDFM_AUTO_CLEAR_WAIT_FOR_SYNC   - Wait-for-sync flag is cleared
 *                                       automatically on FIFO interrupt.
 *
 */
static inline void SDFM_setWaitForSyncClearMode(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber,
                                                SDFM_WaitForSyncClearMode_t syncClearMode)
{
    uint16_t *ptr;

    assert(SDFM_isBaseValid(base));

    ptr = (uint16_t *)&(base->SDSYNC1) + ((uint32_t)filterNumber * 16U);

    /* Write to WTSCLREN  bit */
    *ptr = (*ptr & ~SDFM_SDSYNC1_WTSCLREN_Msk) | ((uint16_t)syncClearMode << 10U);
}

/*!
 *
 * \brief Selects comparator event high source.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 * \param[in] source is the comparator event high source
 *
 * This function selects the source for comparator event high.
 * Valid values for source are:
 *   - SDFM_COMPHOUT_SOURCE_COMPHIN - Original COMPHIN/CEVT1 signal is source
 *   - SDFM_COMPHOUT_SOURCE_FILTER  - Filtered COMPHIN/CEVT1 signal is source
 *
 */
static inline void SDFM_selectCompEventHighSource(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber,
                                                  SDFM_CompEventHighSource_t source)
{
    uint16_t *ptr;

    assert(SDFM_isBaseValid(base));

    ptr = (uint16_t *)&(base->SDCOMP1CTL) + ((uint32_t)filterNumber * 16U);

    /* Set COMPHOUT source. */
    *ptr = (*ptr & ~SDFM_SDCOMP1CTL_CEVT1DIGFILTSEL_Msk) | (uint16_t)source;
}

/*!
 *
 * \brief Selects comparator event low source.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 * \param[in] source is the comparator event low source
 *
 * This function selects the source for comparator event low.
 * Valid values for source are:
 *   - SDFM_COMPLOUT_SOURCE_COMPLIN - Original COMPLIN/CEVT2 signal is source
 *   - SDFM_COMPHOUT_SOURCE_FILTER  - Filtered COMPLIN/CEVT2 signal is source
 *
 */
static inline void SDFM_selectCompEventLowSource(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber,
                                                 SDFM_CompEventLowSource_t source)
{
    uint16_t *ptr;

    assert(SDFM_isBaseValid(base));

    ptr = (uint16_t *)&(base->SDCOMP1CTL) + ((uint32_t)filterNumber * 16U);

    /* Set COMPLOUT source. */
    *ptr = (*ptr & ~SDFM_SDCOMP1CTL_CEVT2DIGFILTSEL_Msk) | (uint16_t)source;
}

/*!
 *
 * \brief Initializes Comparator Event Low Filter.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 *
 * This function initializes Comparator Event Low Filter.
 *
 */
static inline void SDFM_initCompEventLowFilter(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber)
{
    uint16_t *ptr;
    assert(SDFM_isBaseValid(base));

    ptr = (uint16_t *)&(base->SDCOMP1EVT2FLTCTL) + ((uint32_t)filterNumber * 8U);

    /* Initialize comparator event low filter. */
    *ptr |= (uint16_t)(SDFM_SDCOMP1EVT2FLTCTL_FILINIT_Set(1));
}

/*!
 *
 * \brief Initializes Comparator Event High Filter.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 *
 * This function initializes Comparator Event High Filter.
 *
 */
static inline void SDFM_initCompEventHighFilter(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber)
{
    uint16_t *ptr;
    assert(SDFM_isBaseValid(base));

    ptr = (uint16_t *)&(base->SDCOMP1EVT1FLTCTL) + ((uint32_t)filterNumber * 8U);

    /* Initialize comparator event high filter. */
    *ptr |= (uint16_t)(SDFM_SDCOMP1EVT1FLTCTL_FILINIT_Set(1));
}

/*!
 *
 * \brief Lock Comparator Event Filter Configurations
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 * \param[in] lockConfig defines the configurations to be locked
 *
 * This function locks the comparator event filter configurations. Valid
 * values of the lockConfig can be logical OR of any of the following values:
 * - SDFM_SDCOMPLOCK_SDCOMPCTL - Locks write access to SDCOMPCTL register
 * - SDFM_SDCOMPLOCK_COMP - Locks write access to SDCOMPxFILCTL &
 *                          SDCOMPxFILCLKCTL register
 *
 */
static inline void SDFM_lockCompEventFilterConfig(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber,
                                                  uint16_t lockConfig)
{
    uint16_t *ptr;

    assert(SDFM_isBaseValid(base));

    ptr = (uint16_t *)&(base->SDCOMP1LOCK) + ((uint32_t)filterNumber * 8U);

    /* Lock comparator event filter related configurations. */
    *ptr |= lockConfig;
}


/*!
 *
 * \brief Set data ready interrupt source.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 * \param[in] dataReadySource is the data ready interrupt source.
 *
 * This function sets the data ready interrupt source.
 * Valid values for \e dataReadySource:
 *   - kSDFM_DATA_READY_DMA_SOURCE_DIRECT - Direct data ready
 *   - kSDFM_DATA_READY_DMA_SOURCE_FIFO  - FIFO data ready.
 *
 */
static inline void SDFM_setDataReadyDMASource(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber,
                                              SDFM_DataReadyDMASource_t dataReadySource)
{
    uint16_t *ptr;

    assert(SDFM_isBaseValid(base));

    ptr = (uint16_t *)&(base->SDFIFOCTL1) + ((uint32_t)filterNumber * 16U);

    /* Write to DRINTSEL */
    *ptr = (*ptr & ~SDFM_SDFIFOCTL1_DRDMASEL_Msk) | ((uint16_t)dataReadySource << SDFM_SDFIFOCTL1_DRDMASEL_Pos);
}

/*!
 *
 * \brief Enable DMA.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 *
 * This function enables DMA.
 *
 */
static inline void SDFM_enableDMA(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber)
{
    uint32_t *ptr;
    assert(SDFM_isBaseValid(base));

    ptr = (uint32_t *)&(base->SDDMAEN);

    /* Set WTSYNCEN bit */
    *ptr |= (1U << (SDFM_SDDMAEN_DMAEN1_Pos + filterNumber));
}


/*!
 *
 * \brief Disable DMA.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 *
 * This function disables DMA.
 *
 */
static inline void SDFM_disableDMA(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber)
{
    uint32_t *ptr;
    assert(SDFM_isBaseValid(base));

    ptr = (uint32_t *)&(base->SDDMAEN);

    /* Set WTSYNCEN bit */
    *ptr &= ~(1U << (SDFM_SDDMAEN_DMAEN1_Pos + filterNumber));
}


/*!
 *
 * \brief Enable fifo data ready DMA.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 *
 * This function enables data ready DMA.
 *
 */
static inline void SDFM_enableFIFODMA(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber)
{
    uint32_t *ptr;
    assert(SDFM_isBaseValid(base));

    ptr = (uint32_t *)&(base->SDDMAEN);

    /* Set WTSYNCEN bit */
    *ptr |= (1U << (SDFM_SDDMAEN_FFDMAEN1_Pos + filterNumber));
}


/*!
 *
 * \brief Disable fifo data ready DMA.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 *
 * This function disables data ready DMA.
 *
 */
static inline void SDFM_disableFIFODMA(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber)
{
    uint32_t *ptr;
    assert(SDFM_isBaseValid(base));

    ptr = (uint32_t *)&(base->SDDMAEN);

    /* Set WTSYNCEN bit */
    *ptr &= ~(1U << (SDFM_SDDMAEN_FFDMAEN1_Pos + filterNumber));
}


/*!
 *
 * \brief Get the non-fifo mode data-ready dma status.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 *
 * This function returns non-fifo mode data-ready dma status.
 *
 * \retval true if dma triggered.
 * \retval false if dma not triggered.
 *
 */

static inline bool SDFM_getDMAStatus(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber)
{
    uint32_t *ptr;
    assert(SDFM_isBaseValid(base));

    ptr = (uint32_t *)&(base->SDDMAFLG);

    /* Read WTSYNFLG bit */
    return ((*ptr >> (SDFM_SDDMAFLG_DMAFLG1_Pos + filterNumber)) & 0x1);
}

/*!
 *
 * \brief Get the fifo mode data-ready dma status.
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 *
 * This function returns fifo mode data-ready dma status.
 *
 * \retval true if dma triggered.
 * \retval false if dma not triggered.
 *
 */
static inline bool SDFM_getFIFODMAStatus(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber)
{
    uint32_t *ptr;
    assert(SDFM_isBaseValid(base));

    ptr = (uint32_t *)&(base->SDDMAFLG);

    /* Read SDDMAFLG FFDMA1 bit */
    return ((*ptr >> (SDFM_SDDMAFLG_FFDMA1_Pos + filterNumber)) & 0x1);
}

/**  
 * \brief Configure all comparator settings for a filter.  
 *  
 * This function configures all comparator-related settings for a specified filter in the SDFM module.  
 *  
 * \param[in] base Pointer to the base address of the SDFM module.  
 * \param[in] filterNumber The filter number to configure.  
 * \param[in] pcfg_cmp Pointer to a structure containing comparator configuration settings.  
 *  
 */
extern void SDFM_configComparatorAll(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber, SDFM_Comparator_t *pcfg_cmp);

/**  
 * \brief Configure data filter all settings for a filter.
 *  
 * This function configures all data filter-related settings for a specified filter in the SDFM module.  
 *  
 * \param[in] base Pointer to the base address of the SDFM module.  
 * \param[in] filterNumber The filter number to configure.  
 * \param[in] pcfg_data Pointer to a structure containing data filter configuration settings.  
 *  
 */
extern void SDFM_configDataFilterAll(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber, SDFM_Datafilter_t *pcfg_data);

/**  
 * \brief Configure the FIFO for a specified filter.  
 *  
 * This function configures the FIFO buffer for a specified filter in the SDFM module.  
 *  
 * \param[in] base Pointer to the base address of the SDFM module.  
 * \param[in] filterNumber The filter number to configure the FIFO for.  
 * \param[in] pcfg_fifo Pointer to a structure containing FIFO configuration settings.  
 *  
 */ 
extern void SDFM_configFIFO(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber, SDFM_FIFO_t *pcfg_fifo);


/**  
 * \brief Configure the comparator event filter for a specified filter.  
 *  
 * This function configures the comparator event filter for a specified filter in the SDFM module.  
 *  
 * \param[in] base Pointer to the base address of the SDFM module.  
 * \param[in] filterNumber The filter number to configure the comparator event filter.
 * \param[in] pcfg_cpevent_flt Pointer to a structure containing comparator event filter configuration settings.  
 *  
 */
extern void SDFM_configCompEventFilter(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber,
                                SDFM_CpeventFilter_t *pcfg_cpevent_flt);

/**  
 * \brief Configure the DMA settings for a specified filter.  
 *  
 * This function configures the DMA settings for a specified filter in the SDFM module.  
 *  
 * \param[in] base Pointer to the base address of the SDFM module.  
 * \param[in] filterNumber The filter number to configure the DMA settings.
 * \param[in] pcfg_dma Pointer to a structure containing DMA configuration settings.  
 *  
 */
extern void SDFM_configDma(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber, SDFM_Dma_t *pcfg_dma);


/*!
 *
 * \brief Configures SDFM comparator for filter config & threshold values
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] config1 is the filter number, filter type and over sampling ratio.
 * \param[in] config2 is high-level and low-level threshold 1 values.
 * \param[in] config3 is the zero-cross threshold value.
 *
 * This function configures the comparator filter for filter config and
 * threshold values based on provided inputs.
 *
 * The config1 parameter is the logical OR of the filter number, filter type
 * and oversampling ratio.
 * The bit definitions for config1 are as follow:
 *   - config1.[3:0]  filter number
 *   - config1.[7:4]  filter type
 *   - config1.[15:8] Over sampling Ratio
 * Valid values for filter number and filter type are defined in
 * SDFM_FilterNumber_t and SDFM_FilterType_t enumerations respectively.
 * SDFM_SET_OSR(X) macro can be used to set the value of the oversampling
 * ratio ,which ranges [1,32] inclusive, in the appropriate bit location.
 * For example the value
 * (SDFM_FILTER_1 | SDFM_FILTER_SINC_2 | SDFM_SET_OSR(16))
 * will select Filter 1, SINC 2 type with an oversampling ratio of 16.
 *
 * The config2 parameter is the logical OR of the filter high and low
 * threshold 1 values.
 * The bit definitions for config2 are as follow:
 *   - config2.[15:0]  low threshold 1
 *   - config2.[31:16] high threshold 1
 * The upper 16 bits define the high threshold 1 and the lower 16 bits define
 * the low threshold 1. SDFM_THRESHOLD(H,L) can be used to combine the high
 * and low thresholds.
 * The config3 parameter is the logical OR of the zero cross threshold
 * enable flag and the zero-cross threshold value.
 * The bit definitions for config3 are as follow:
 *   - config3.[15] - Enable or disable zero cross threshold. Valid values
 *                    are 1 or 0 to enable or disable the zero cross threshold
 *                    respectively.
 *   -config3.[14:0] - Zero Cross Threshold value.
 * The SDFM_SET_ZERO_CROSS_THRESH_VALUE(X) macro can be used to specify the
 * zero-cross threshold value and OR the 1 to enable it.
 *
 *
 */
extern void SDFM_configComparator(SDFM_REGS_Type *base, uint16_t config1, uint32_t config2, uint16_t config3);

/*!
 *
 * \brief Configure SDFM enhanced comparator for filter config & threshold values
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterConfig is the filter number, filter type & over sampling ratio.
 * \param[in] highLowThreshold1 is high-level and low-level threshold 1 values.
 * \param[in] highLowThreshold2 is high-level and low-level threshold 2 values.
 * \param[in] zeroCrossThreshold is the zero-cross threshold value.
 *
 * This function configures the comparator filter for filter config and
 * threshold values based on input parameters.
 *
 * The filterConfig parameter is the logical OR of the filter number, filter
 * type and oversampling ratio.
 * The bit definitions for filterConfig are as follow:
 *   - filterConfig.[3:0]  filter number
 *   - filterConfig.[7:4]  filter type
 *   - filterConfig.[15:8] Over sampling Ratio
 * Valid values for filter number and filter type are defined in
 * SDFM_FilterNumber_t and SDFM_FilterType_t enumerations respectively.
 * SDFM_SET_OSR(X) macro can be used to set the value of the oversampling
 * ratio ,which ranges [1,32] inclusive, in the appropriate bit location.
 * For example the value
 * (SDFM_FILTER_1 | SDFM_FILTER_SINC_2 | SDFM_SET_OSR(16))
 * will select Filter 1, SINC 2 type with an oversampling ratio of 16.
 *
 * The highLowThreshold1 parameter is the logical OR of the filter high & low
 * threshold 1 values.
 * The bit definitions for highLowThreshold1 are as follow:
 *   - highLowThreshold1.[15:0]  low threshold 1
 *   - highLowThreshold1.[31:16] high threshold 1
 * The upper 16 bits define the high threshold and the lower 16 bits define
 * the low threshold. SDFM_THRESHOLD(H,L) can be used to combine the high and
 * low thresholds.
 *
 * The highLowThreshold2 parameter is the logical OR of the filter high & low
 * threshold 2 values.
 * The bit definitions for highLowThreshold2 are as follow:
 *   - highLowThreshold2.[15:0]  low threshold 2
 *   - highLowThreshold2.[31:16] high threshold 2
 * The upper 16 bits define the high threshold and the lower 16 bits define
 * the low threshold. SDFM_THRESHOLD(H,L) can be used to combine the high &
 * low thresholds.
 *
 * The zeroCrossThreshold parameter is the logical OR of the zero cross
 * threshold enable flag and the zero-cross threshold value. The bit
 * definitions for zeroCrossThreshold are as follows:
 *   - zeroCrossThreshold.[15] - Enable or disable zero cross threshold. Valid
 *     values are 1 or 0 to enable or disable the zero cross threshold
 *     respectively.
 *   - zeroCrossThreshold.[14:0] - Zero Cross Threshold value.
 * The SDFM_SET_ZERO_CROSS_THRESH_VALUE(X) macro can be used as parameter
 * zeroCrossThreshold to enable & specify the zero-cross threshold value.
 *
 *
 */
extern void SDFM_configEnhancedComparator(SDFM_REGS_Type *base, uint16_t filterConfig, uint32_t highLowThreshold1,
                                          uint32_t highLowThreshold2, uint16_t zeroCrossThreshold);

/*!
 *
 * \brief Configure SDFM data filter
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] config1 is the filter number, filter type and over sampling ratio
 *                configuration.
 * \param[in] config2 is filter switch, data representation and data shift values
 *                configuration.
 *
 * This function configures the data filter based on configurations
 * config1 and config2.
 *
 * The config1 parameter is the logical OR of the filter number, filter type
 * and oversampling ratio.
 * The bit definitions for config1 are as follow:
 *   - config1.[3:0]  Filter number
 *   - config1.[7:4]  Filter type
 *   - config1.[15:8] Over sampling Ratio
 * Valid values for filter number and filter type are defined in
 * SDFM_FilterNumber_t and SDFM_FilterType_t enumerations respectively.
 * SDFM_SET_OSR(X) macro can be used to set the value of the oversampling
 * ratio , which ranges [1,256] inclusive , in the appropriate bit location
 * for config1. For example the value
 * (SDFM_FILTER_2 | SDFM_FILTER_SINC_3 | SDFM_SET_OSR(64))
 * will select Filter 2 , SINC 3 type with an oversampling ratio of 64.
 *
 * The config2 parameter is the logical OR of data representation, filter
 * switch, and data shift values
 * The bit definitions for config2 are as follow:
 *   - config2.[0]  Data representation
 *   - config2.[1]  Filter switch
 *   - config2.[15:2]  Shift values
 * Valid values for data representation are given in SDFM_OutputDataFormat_t
 * enumeration. SDFM_FILTER_DISABLE or SDFM_FILTER_ENABLE will define the
 * filter switch values.SDFM_SHIFT_VALUE(X) macro can be used to set the value
 * of the data shift value,which ranges [0,31] inclusive, in the appropriate
 * bit location for config2.
 * The shift value is valid only in SDFM_DATA_FORMAT_16_BIT data
 * representation format.
 *
 */
extern void SDFM_configDataFilter(SDFM_REGS_Type *base, uint16_t config1, uint16_t config2);

/*!
 *
 * \brief Configure SDFM comparator Zero Cross threshold
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] config1 is the filter number, filter type and over sampling ratio.
 * \param[in] config2 is the zero cross threshold value.
 *
 * This function configures the comparator filter zero cross threshold values
 * based on configurations config1 and config2.
 *
 * The config1 parameter is the logical OR of the filter number, filter type
 * and oversampling ratio.
 * The bit definitions for config1 are as follow:
 *   - config1.[3:0]  filter number
 *   - config1.[7:4]  filter type
 *   - config1.[15:8] Over sampling Ratio
 * Valid values for filter number and filter type are defined in
 * SDFM_FilterNumber_t and SDFM_FilterType_t enumerations respectively.
 * SDFM_SET_OSR(X) macro can be used to set the value of the oversampling
 * ratio ,which ranges [1,32] inclusive, in the appropriate bit location.
 * For example the value
 * (SDFM_FILTER_1 | SDFM_FILTER_SINC_2 | SDFM_SET_OSR(16))
 * will select Filter 1 , SINC 2 type with an oversampling ratio of 16.
 *
 * The config2 parameter is the value of the zero cross threshold. The maximum
 * acceptable value is 32767.
 *
 */
extern void SDFM_configZeroCrossComparator(SDFM_REGS_Type *base, uint16_t config1, uint16_t config2);

/*!
 *
 * \brief Configure SDFM data filter FIFO
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] config1 is the filter number, filter type and over sampling ratio
 *                configuration.
 * \param[in] config2 is filter switch, data representation and data shift values
 *                and FIFO level configuration.
 *
 * This function enables and configures the data filter FIFO based on
 * configurations config1 and config2.
 *
 * The config1 parameter is the logical OR of the filter number, filter type
 * and oversampling ratio.
 * The bit definitions for config1 are as follow:
 *   - config1.[3:0]  filter number
 *   - config1.[7:4]  filter type
 *   - config1.[15:8] Over sampling Ratio
 * Valid values for filter number and filter type are defined in
 * SDFM_FilterNumber_t and SDFM_FilterType_t enumerations respectively.
 * SDFM_SET_OSR(X) macro can be used to set the value of the oversampling
 * ratio , which ranges [1,256] inclusive , in the appropriate bit location
 * for config1. For example the value
 * (SDFM_FILTER_2 | SDFM_FILTER_SINC_3 | SDFM_SET_OSR(64))
 * will select Filter 2 , SINC 3 type with an oversampling ratio of 64.
 *
 * The config2 parameter is the logical OR of data representation, filter
 * switch, data shift value, and FIFO level
 * The bit definitions for config2 are as follow:
 *   - config2.[0]  Data representation
 *   - config2.[1]  filter switch.
 *   - config2.[6:2]  shift values.
 *   - config2.[15:7] FIFO level
 * Valid values for data representation are given in SDFM_OutputDataFormat_t
 * enumeration. SDFM_FILTER_DISABLE or SDFM_FILTER_ENABLE will define the
 * filter switch values.SDFM_SHIFT_VALUE(X) macro can be used to set the value
 * of the data shift value,which ranges [0,31] inclusive, in the appropriate
 * bit location for config2.
 * The value of FIFO level ranges [1,16] inclusive. The macro
 * SDFM_SET_FIFO_LEVEL(X) can be used to set the value of the FIFO level.
 *
 */
extern void SDFM_configDataFilterFIFO(SDFM_REGS_Type *base, uint16_t config1, uint16_t config2);

/*!
 *
 * \brief Configure Comparator Event Low Filter
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] filterNumber is the filter number.
 * \param[in] config is the comparator event low source
 *
 * This function configures the sample window, threshold and clock prescale
 * configurations for the comparator event low filter.
 *
 */
extern void SDFM_configCompEventLowFilter(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber,
                                          const SDFM_CompEventFilterConfig_t *config);

/*!
 *
 * \brief Configure Comparator Event High Filter
 *
 * \param[in] base is the base address of the SDFM module.
 * \param[in] filterNumber is the filter number.
 * \param[in] config is the comparator event high source
 *
 * This function configures the sample window, threshold and clock prescale
 * configurations for the comparator event high filter.
 *
 */
extern void SDFM_configCompEventHighFilter(SDFM_REGS_Type *base, SDFM_FilterNumber_t filterNumber,
                                           const SDFM_CompEventFilterConfig_t *config);


/*!
 * \brief Register user callback function to sdfm interrupt handler.
 *
 * \details This function registers user callback function for sdfm interrupt handler which uses IRQ. The relative IRQ
 will be enabled in the NVIC and the priority will be configured at the same time

 * \param[in] base is the base address of the SDFM module
 * \param[in] intsrc interrupt source select.
 * \param[in] func SDFM user callback
 * \param[in] priority IRQ priority
 *
 * \retval kSTATUS_SUCCESS Success to the operation
 * \retval kSTATUS_FAIL Register to a SDFM which has been registered already. Need to call \ref
 SDFM_unregisterCallback() before the re-registration
 */
status_t SDFM_registerCallback(SDFM_REGS_Type *base,SDFM_IntSrc_t intsrc, SDFM_Callback_t func, uint32_t priority);


/*!
 * \brief Unregister user callback function to sdfm interrupt handler.
 *
 * \details This function clears the registered user callback function, and disable the relative IRQ in the NVIC
 *
 * \param[in] base is the base address of the SDFM module
 * \param[in] intsrc interrupt source select.
 *
 * \retval kSTATUS_SUCCESS Success to the operation
 * \retval kSTATUS_FAIL The SDFM hasn't been registered to a callback
 */
status_t SDFM_unregisterCallback(SDFM_REGS_Type *base,SDFM_IntSrc_t intsrc);

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */ /* end of DRV_HTE_SDFM */

#endif /* HTE_COMMON_H */
