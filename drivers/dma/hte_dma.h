/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_dma.h
 * \brief SDK DMA driver header file
 * \version 1.0.0
 */

#ifndef HTE_DMA_H
#define HTE_DMA_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_common.h"

/*!
 * \addtogroup DRV_HTE_DMA DMA Driver
 *
 * \brief SDK DMA driver
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define DMA_SIZE_MAX     0x10000 /*!<dma max data size */
#define MAX_DMA_WRAP_LEN 0x10000 /*!<dma max wrap len */

/*! \brief index for dma channel */
typedef enum
{
    kDMA_INDEX_CH1 = 0, /*!< DMA ch1 index*/
    kDMA_INDEX_CH2 = 1, /*!< DMA ch2 index*/
    kDMA_INDEX_CH3 = 2, /*!< DMA ch3 index*/
    kDMA_INDEX_CH4 = 3, /*!< DMA ch4 index*/
    kDMA_INDEX_CH5 = 4, /*!< DMA ch5 index*/
    kDMA_INDEX_CH6 = 5, /*!< DMA ch6 index*/
    kDMA_INDEX_CH_MAX   /*!< DMA max index*/
} DMA_Index_t;

/*! \brief dma trigger num */
typedef enum
{
    kDMA_TRIGGER_SOFTWARE = 0, /*!< DMA sw trigger index*/

    kDMA_TRIGGER_ADCA1   = 1,  /*!< DMA ADCA1 trigger index*/
    kDMA_TRIGGER_ADCA2   = 2,  /*!< DMA ADCA2 trigger index*/
    kDMA_TRIGGER_ADCA3   = 3,  /*!< DMA ADCA3 trigger index*/
    kDMA_TRIGGER_ADCA4   = 4,  /*!< DMA ADCA4 trigger index*/
    kDMA_TRIGGER_ADCAEVT = 5,  /*!< DMA ADCAEVT trigger index*/
    kDMA_TRIGGER_ADCB1   = 6,  /*!< DMA ADCB1 trigger index*/
    kDMA_TRIGGER_ADCB2   = 7,  /*!< DMA ADCB2 trigger index*/
    kDMA_TRIGGER_ADCB3   = 8,  /*!< DMA ADCB3  trigger index*/
    kDMA_TRIGGER_ADCB4   = 9,  /*!< DMA ADCB4 trigger index*/
    kDMA_TRIGGER_ADCBEVT = 10, /*!< DMA ADCBEVT trigger index*/
    kDMA_TRIGGER_ADCC1   = 11, /*!< DMA ADCC1 trigger index*/
    kDMA_TRIGGER_ADCC2   = 12, /*!< DMA ADCC2 trigger index*/
    kDMA_TRIGGER_ADCC3   = 13, /*!< DMA ADCC3 trigger index*/
    kDMA_TRIGGER_ADCC4   = 14, /*!< DMA ADCC4 trigger index*/
    kDMA_TRIGGER_ADCCEVT = 15, /*!< DMA ADCCEVT trigger index*/
    kDMA_TRIGGER_ADCD1   = 16, /*!< DMA ADCD1 trigger index*/
    kDMA_TRIGGER_ADCD2   = 17, /*!< DMA ADCD2 trigger index*/
    kDMA_TRIGGER_ADCD3   = 18, /*!< DMA ADCD3 trigger index*/
    kDMA_TRIGGER_ADCD4   = 19, /*!< DMA ADCD4 trigger index*/
    kDMA_TRIGGER_ADCDEVT = 20, /*!< DMA ADCDEVT trigger index*/

    kDMA_TRIGGER_XINT1 = 29, /*!< DMA XINT1 trigger index*/
    kDMA_TRIGGER_XINT2 = 30, /*!< DMA XINT2 trigger index*/
    kDMA_TRIGGER_XINT3 = 31, /*!< DMA XINT3 trigger index*/
    kDMA_TRIGGER_XINT4 = 32, /*!< DMA XINT4 trigger index*/
    kDMA_TRIGGER_XINT5 = 33, /*!< DMA XINT5 trigger index*/

    kDMA_TRIGGER_EPWM1SOCA  = 36, /*!< DMA EPWM1SOCA trigger index*/
    kDMA_TRIGGER_EPWM1SOCB  = 37, /*!< DMA EPWM1SOCB trigger index*/
    kDMA_TRIGGER_EPWM2SOCA  = 38, /*!< DMA EPWM2SOCA trigger index*/
    kDMA_TRIGGER_EPWM2SOCB  = 39, /*!< DMA EPWM2SOCB trigger index*/
    kDMA_TRIGGER_EPWM3SOCA  = 40, /*!< DMA EPWM3SOCA trigger index*/
    kDMA_TRIGGER_EPWM3SOCB  = 41, /*!< DMA EPWM3SOCB trigger index*/
    kDMA_TRIGGER_EPWM4SOCA  = 42, /*!< DMA EPWM4SOCA trigger index*/
    kDMA_TRIGGER_EPWM4SOCB  = 43, /*!< DMA EPWM4SOCB trigger index*/
    kDMA_TRIGGER_EPWM5SOCA  = 44, /*!< DMA EPWM5SOCA trigger index*/
    kDMA_TRIGGER_EPWM5SOCB  = 45, /*!< DMA EPWM5SOCB trigger index*/
    kDMA_TRIGGER_EPWM6SOCA  = 46, /*!< DMA EPWM6SOCA trigger index*/
    kDMA_TRIGGER_EPWM6SOCB  = 47, /*!< DMA EPWM6SOCB trigger index*/
    kDMA_TRIGGER_EPWM7SOCA  = 48, /*!< DMA EPWM7SOCA trigger index*/
    kDMA_TRIGGER_EPWM7SOCB  = 49, /*!< DMA EPWM7SOCB trigger index*/
    kDMA_TRIGGER_EPWM8SOCA  = 50, /*!< DMA EPWM8SOCA trigger index*/
    kDMA_TRIGGER_EPWM8SOCB  = 51, /*!< DMA EPWM8SOCB trigger index*/
    kDMA_TRIGGER_EPWM9SOCA  = 52, /*!< DMA EPWM9SOCA trigger index*/
    kDMA_TRIGGER_EPWM9SOCB  = 53, /*!< DMA EPWM9SOCB trigger index*/
    kDMA_TRIGGER_EPWM10SOCA = 54, /*!< DMA EPWM10SOCA trigger index*/
    kDMA_TRIGGER_EPWM10SOCB = 55, /*!< DMA EPWM10SOCB trigger index*/
    kDMA_TRIGGER_EPWM11SOCA = 56, /*!< DMA EPWM11SOCA trigger index*/
    kDMA_TRIGGER_EPWM11SOCB = 57, /*!< DMA EPWM11SOCB trigger index*/
    kDMA_TRIGGER_EPWM12SOCA = 58, /*!< DMA EPWM12SOCA trigger index*/
    kDMA_TRIGGER_EPWM12SOCB = 59, /*!< DMA EPWM12SOCB trigger index*/

    kDMA_TRIGGER_TINT0 = 68, /*!< DMA TINT0 trigger index*/
    kDMA_TRIGGER_TINT1 = 69, /*!< DMA TINT1 trigger index*/
    kDMA_TRIGGER_TINT2 = 70, /*!< DMA TINT2 trigger index*/

    kDMA_TRIGGER_MCBSPAMXEVT = 71, /*!< DMA MCBSPAMXEVT trigger index*/
    kDMA_TRIGGER_MCBSPAMREVT = 72, /*!< DMA MCBSPAMREVT trigger index*/
    kDMA_TRIGGER_MCBSPBMXEVT = 73, /*!< DMA MCBSPBMXEVT trigger index*/
    kDMA_TRIGGER_MCBSPBMREVT = 74, /*!< DMA MCBSPBMREVT trigger index*/

    kDMA_TRIGGER_ECAP1 = 75, /*!< DMA ECAP1 trigger index*/
    kDMA_TRIGGER_ECAP2 = 76, /*!< DMA ECAP2 trigger index*/
    kDMA_TRIGGER_ECAP3 = 77, /*!< DMA ECAP3 trigger index*/
    kDMA_TRIGGER_ECAP4 = 78, /*!< DMA ECAP4 trigger index*/
    kDMA_TRIGGER_ECAP5 = 79, /*!< DMA ECAP5 trigger index*/
    kDMA_TRIGGER_ECAP6 = 80, /*!< DMA ECAP6 trigger index*/
    kDMA_TRIGGER_ECAP7 = 81, /*!< DMA ECAP7 trigger index*/

    kDMA_TRIGGER_SDFM1FLT1 = 95, /*!< DMA SDFM1FLT1 trigger index*/
    kDMA_TRIGGER_SDFM1FLT2 = 96, /*!< DMA SDFM1FLT2 trigger index*/
    kDMA_TRIGGER_SDFM1FLT3 = 97, /*!< DMA SDFM1FLT3 trigger index*/
    kDMA_TRIGGER_SDFM1FLT4 = 98, /*!< DMA SDFM1FLT4 trigger index*/

    kDMA_TRIGGER_SDFM2FLT1 = 99,  /*!< DMA SDFM1FLT1 trigger index*/
    kDMA_TRIGGER_SDFM2FLT2 = 100, /*!< DMA SDFM1FLT2 trigger index*/
    kDMA_TRIGGER_SDFM2FLT3 = 101, /*!< DMA SDFM1FLT3 trigger index*/
    kDMA_TRIGGER_SDFM2FLT4 = 102, /*!< DMA SDFM1FLT4 trigger index*/

    kDMA_TRIGGER_SYNC = 103, /*!< DMA SYNC trigger index*/

    kDMA_TRIGGER_SPIATX = 109, /*!< DMA SPIATX trigger index*/
    kDMA_TRIGGER_SPIARX = 110, /*!< DMA SPIARX trigger index*/
    kDMA_TRIGGER_SPIBTX = 111, /*!< DMA SPIBTX trigger index*/
    kDMA_TRIGGER_SPIBRX = 112, /*!< DMA SPIBRX trigger index*/
    kDMA_TRIGGER_SPICTX = 113, /*!< DMA SPICTX trigger index*/
    kDMA_TRIGGER_SPICRX = 114, /*!< DMA SPICRX trigger index*/

    kDMA_TRIGGER_CLB5INT = 117, /*!< DMA CLB5INT trigger index*/
    kDMA_TRIGGER_CLB6INT = 118, /*!< DMA CLB6INT trigger index*/
    kDMA_TRIGGER_CLB7INT = 119, /*!< DMA CLB7INT trigger index*/
    kDMA_TRIGGER_CLB8INT = 120, /*!< DMA CLB8INT trigger index*/

    kDMA_TRIGGER_FSITXA = 123, /*!< DMA FSITXA trigger index*/
    kDMA_TRIGGER_FSIRXA = 125, /*!< DMA FSIRXA trigger index*/

    kDMA_TRIGGER_CLB1INT = 127, /*!< DMA CLB1INT trigger index*/
    kDMA_TRIGGER_CLB2INT = 128, /*!< DMA CLB2INT trigger index*/
    kDMA_TRIGGER_CLB3INT = 129, /*!< DMA CLB3INT trigger index*/
    kDMA_TRIGGER_CLB4INT = 130, /*!< DMA CLB4INT trigger index*/

    kDMA_TRIGGER_USBA_RX1 = 131, /*!< DMA USBA_RX1 trigger index*/
    kDMA_TRIGGER_USBA_TX1 = 132, /*!< DMA USBA_TX1 trigger index*/
    kDMA_TRIGGER_USBA_RX2 = 133, /*!< DMA USBA_RX2 trigger index*/
    kDMA_TRIGGER_USBA_TX2 = 134, /*!< DMA USBA_TX2 trigger index*/
    kDMA_TRIGGER_USBA_RX3 = 135, /*!< DMA USBA_RX3 trigger index*/
    kDMA_TRIGGER_USBA_TX3 = 136, /*!< DMA USBA_TX3 trigger index*/

    kDMA_TRIGGER_FSIRXC = 143, /*!< DMA FSIRXC trigger index*/
    kDMA_TRIGGER_FSIRXD = 144, /*!< DMA FSIRXD trigger index*/
    kDMA_TRIGGER_FSIRXE = 145, /*!< DMA FSIRXE trigger index*/
    kDMA_TRIGGER_FSIRXF = 146, /*!< DMA FSIRXF trigger index*/
    kDMA_TRIGGER_FSIRXG = 147, /*!< DMA FSIRXG trigger index*/
    kDMA_TRIGGER_FSIRXH = 148, /*!< DMA FSIRXH trigger index*/

    kDMA_TRIGGER_FSITXB = 155, /*!< DMA FSITXB trigger index*/
    kDMA_TRIGGER_FSIRXB = 157, /*!< DMA FSIRXB trigger index*/

    kDMA_TRIGGER_CANA = 168, /*!< DMA CANA trigger index*/
    kDMA_TRIGGER_CANB = 169, /*!< DMA CANB trigger index*/
    kDMA_TRIGGER_CANC = 170, /*!< DMA CANC trigger index*/

    kDMA_TRIGGER_TFU0_TH0_RD = 176, /*!< DMA TFU0_TH0_RD trigger index*/
    kDMA_TRIGGER_TFU0_TH0_WR = 177, /*!< DMA TFU0_TH0_WR trigger index*/
    kDMA_TRIGGER_TFU0_TH1_RD = 178, /*!< DMA TFU0_TH1_RD trigger index*/
    kDMA_TRIGGER_TFU0_TH1_WR = 179, /*!< DMA TFU0_TH1_WR trigger index*/
    kDMA_TRIGGER_TFU0_TH2_RD = 180, /*!< DMA TFU0_TH2_RD trigger index*/
    kDMA_TRIGGER_TFU0_TH2_WR = 181, /*!< DMA TFU0_TH2_WR trigger index*/
    kDMA_TRIGGER_TFU0_TH3_RD = 182, /*!< DMA TFU0_TH3_RD trigger index*/
    kDMA_TRIGGER_TFU0_TH3_WR = 183, /*!< DMA TFU0_TH3_WR trigger index*/
    kDMA_TRIGGER_TFU1_TH0_RD = 184, /*!< DMA TFU1_TH0_RD trigger index*/
    kDMA_TRIGGER_TFU1_TH0_WR = 185, /*!< DMA TFU1_TH0_WR trigger index*/
    kDMA_TRIGGER_TFU1_TH1_RD = 186, /*!< DMA TFU1_TH1_RD trigger index*/
    kDMA_TRIGGER_TFU1_TH1_WR = 187, /*!< DMA TFU1_TH1_WR trigger index*/
    kDMA_TRIGGER_TFU1_TH2_RD = 188, /*!< DMA TFU1_TH2_RD trigger index*/
    kDMA_TRIGGER_TFU1_TH2_WR = 189, /*!< DMA TFU1_TH2_WR trigger index*/
    kDMA_TRIGGER_TFU1_TH3_RD = 190, /*!< DMA TFU1_TH3_RD trigger index*/
    kDMA_TRIGGER_TFU1_TH3_WR = 191, /*!< DMA TFU1_TH3_WR trigger index*/

    kDMA_TRIGGER_DW_TIMER0 = 193, /*!< DMA DW_TIMER0 trigger index*/
    kDMA_TRIGGER_DW_TIMER1 = 193, /*!< DMA DW_TIMER1 trigger index*/
    kDMA_TRIGGER_DW_TIMER2 = 194, /*!< DMA DW_TIMER2 trigger index*/

} DMA_Trigger_t;

/*! \brief DMA interrupt generate mode */
typedef enum
{
    kDMA_INT_AT_BEGINNING, /*!< DMA Beginning int*/
    kDMA_INT_AT_END        /*!< DMA end int*/
} DMA_InterruptMode_t;

/*! \brief DMA Emulation Mode */
typedef enum
{
    kDMA_EMULATION_STOP,    /*!< DMA emulation stop*/
    kDMA_EMULATION_FREE_RUN /*!< DMA emulation free run*/
} DMA_EmulationMode_t;

/*! \brief DMA data size */
typedef enum
{
    kDMA_DATASIZE_8BIT  = 0, /*!< DMA 8bit datasize*/
    kDMA_DATASIZE_16BIT = 1, /*!< DMA 16bit datasize*/
    kDMA_DATASIZE_32BIT = 2, /*!< DMA 32bit datasize*/
} DMA_DataSize_t;

/*! \brief DMA config Mode */
typedef enum
{
    kDMA_MODE_PERIPH_TRIG        = 0, /*!< DMA periph trig mode*/
    kDMA_MODE_ONESHOT            = 1, /*!< DMA oneshot trig mode*/
    kDMA_MODE_CONTINUOUS         = 2, /*!< DMA continuous trig mode*/
    kDMA_MODE_ONESHOT_CONTINUOUS = 3, /*!< DMA oneshot continuous trig mode*/
} DMA_CfgMode_t;

/*! \brief DMA interrupt source num */
typedef enum
{
    kDMA_CH1_INT = 0, /*!< DMA ch1 int index*/
    kDMA_CH2_INT = 1, /*!< DMA ch2 int index*/
    kDMA_CH3_INT = 2, /*!< DMA ch3 int index*/
    kDMA_CH4_INT = 3, /*!< DMA ch4 int index*/
    kDMA_CH5_INT = 4, /*!< DMA ch5 int index*/
    kDMA_CH6_INT = 5, /*!< DMA ch6 int index*/
    kDMA_CH_INT_MAX   /*!< DMA max int index*/
} DMA_IntSrc_t;

/*! \brief type definition for DMA callback  */
typedef void (*DMA_Callback_t)(DMA_Index_t index);

/*! \brief type definition for DMA interrupt callback  */
typedef struct
{
    DMA_Callback_t func[kDMA_CH_INT_MAX]; /*!< DMA callback function*/
} DMA_Int_Callback_t;

/*******************************************************************************
 * APIs
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Checks an DMA channel index
 *
 * \details This function determines if a DMA channel index is valid.
 *
 * \param[in] index specifies the DMA channel index.
 * \return Return \b true if the base address is valid and \b false otherwise.
 *
 */
static inline bool DMA_isChValid(DMA_Index_t index)
{
    return ((index == kDMA_INDEX_CH1) || (index == kDMA_INDEX_CH2) || (index == kDMA_INDEX_CH3) ||
            (index == kDMA_INDEX_CH4) || (index == kDMA_INDEX_CH5) || (index == kDMA_INDEX_CH6));
}

/*!
 * \brief Initializes the DMA controller to priorit reset.
 *
 * \details This function configures does a hard reset of the DMA controller in order
 *  to put it into a known state. The function also sets the DMA to run
 *
 *
 */
static inline void DMA_priorityReset(void)
{
    //
    // Set the priorit reset bit.
    //

    DMA->CTRL |= DMA_CTRL_PRIORITY_RESET_Set(0x01U);
}

/*!
 * \brief Initializes the DMA controller to hard reset.
 *
 * \details This function configures does a hard reset of the DMA controller in order
 *  to put it into a known state. The function also sets the DMA to run free
 *  during an emulation suspend
 *
 */
static inline void DMA_initController(void)
{
    //
    // Set the hard reset bit. One NOP is required after HARDRESET.
    //

    DMA->CTRL |= DMA_CTRL_HARD_RESET_Set(0x01U);
    __asm volatile("nop");
    //__NOP;
    // delay_us(1);
}

/*!
 * \brief Sets DMA emulation mode.
 *
 * \details This function sets the behavior of the DMA operation when an emulation
 *  suspend occurs
 *
 * \param[in] mode is the emulation mode to be selected.
 *
 */
static inline void DMA_setEmulationMode(DMA_EmulationMode_t mode)

{
    //
    // Set emulation mode
    //
    if (mode == kDMA_EMULATION_STOP)
    {
        DMA->CTRL &= ~DMA_CTRL_FREE_Set(0x01U);
    }
    else
    {
        DMA->CTRL |= DMA_CTRL_FREE_Set(0x01U);
    }
}

/*!
 * \brief Sets the DMA channel priority mode.
 *
 * \details This function sets the channel interrupt mode.
 *
 * \param[in] ch1IsHighPri is a flag to indicate the channel interrupt mode.
 *
 */
static inline void DMA_setPriorityMode(bool ch1IsHighPri)
{
    //
    // Write the selected priority mode to the register.
    //
    if (ch1IsHighPri)
    {
        DMA->CTRL |= DMA_CTRL_CH1_PRIORITY_Set(0x01U);
    }
    else
    {
        DMA->CTRL &= ~DMA_CTRL_CH1_PRIORITY_Set(0x01U);
    }
}

/*!
 * \brief Gets the DMA channel status.
 *
 * \details This function gets the channel status.
 *
 * \return dma active status.
 *
 */
static inline uint32_t DMA_getActiveStatus(void)
{
    return DMA_STATUS_ACTIVE_STS_Get(DMA->STATUS);
}

/*!
 * \brief Gets the DMA channel shadow status.
 *
 * \details This function gets the channel shadow  status.
 *
 * \return dma active shadow status.
 *
 */
static inline uint32_t DMA_getShadowActiveStatus(void)
{
    return DMA_STATUS_ACTIVE_STS_SHADOW_Get(DMA->STATUS);
}


/*!
 * \brief Enables peripherals to trigger a DMA transfer.
 *
 * \details This function enables the selected peripheral trigger to start a DMA
 *  transfer on the specified channel.
 * \param[in] index the DMA channel index
 *
 */
static inline void DMA_enableTrigger(DMA_Index_t index)
{
    //
    // Check the arguments.
    //
    assert(DMA_isChValid(index));
    //
    // Set the peripheral interrupt trigger enable bit.
    //
    DMA->CHANNEL[index].CH_CFG |= DMA_CH_CFG_PERINTE_Set(0x01U);
}

/*!
 * \brief Disables peripherals from triggering a DMA transfer.
 *
 * \details This function disables the selected peripheral trigger from starting a DMA
 *  transfer on the specified channel.
 * \param[in] index the DMA channel index
 *
 */
static inline void DMA_disableTrigger(DMA_Index_t index)

{
    //
    // Check the arguments.
    //
    assert(DMA_isChValid(index));
    //
    // Clear the peripheral interrupt trigger enable bit.
    //
    DMA->CHANNEL[index].CH_CFG &= ~DMA_CH_CFG_PERINTE_Set(0x01U);
}

/*!
 * \brief Enables a DMA channel begin interrupt source.
 *
 * \details This function enables DMA interrupt at the begining of tranfer.
 *
 * \param[in] index the DMA channel index
 *
 */
static inline void DMA_enableBegInterrupt(DMA_Index_t index)
{
    //
    // Check the arguments.
    //
    assert(DMA_isChValid(index));
    //
    // Enable the specified DMA channel interrupt.
    //
    DMA->CHANNEL[index].CH_CFG |= DMA_CH_CFG_TRANS_BEG_IE_Set(0x01U);
}

/*!
 * \brief Disables a DMA channel begin interrupt source.
 *
 * \details This function disables DMA interrupt at the begining of tranfer.
 *
 * \param[in] index the DMA channel index
 *
 */
static inline void DMA_disableBegInterrupt(DMA_Index_t index)
{
    //
    // Check the arguments.
    //
    assert(DMA_isChValid(index));
    //
    // Enable the specified DMA channel interrupt.
    //
    DMA->CHANNEL[index].CH_CFG &= ~DMA_CH_CFG_TRANS_BEG_IE_Set(0x01U);
}

/*!
 * \brief Enables a DMA channel ending interrupt source.
 *
 * \details This function enables DMA interrupt at the ending of tranfer.
 *
 * \param[in] index the DMA channel index
 *
 */
static inline void DMA_enableEndInterrupt(DMA_Index_t index)
{
    //
    // Check the arguments.
    //
    assert(DMA_isChValid(index));
    //
    // Enable the specified DMA channel interrupt.
    //
    DMA->CHANNEL[index].CH_CFG |= DMA_CH_CFG_TRANS_END_IE_Set(0x01U);
}

/*!
 * \brief Disables a DMA channel ending interrupt source.
 *
 * \details This function disables DMA interrupt at the ending of tranfer.
 *
 * \param[in] index the DMA channel index
 *
 */
static inline void DMA_disableEndInterrupt(DMA_Index_t index)
{
    //
    // Check the arguments.
    //
    assert(DMA_isChValid(index));
    //
    // Enable the specified DMA channel interrupt.
    //
    DMA->CHANNEL[index].CH_CFG &= ~DMA_CH_CFG_TRANS_END_IE_Set(0x01U);
}

/*!
 * \brief Enables the DMA channel overrun interrupt.
 *
 * \details This function enables the indicated DMA channel's ability to generate an
 *  interrupt upon the detection of an overrun.
 *
 * \param[in] index the DMA channel index
 *
 */
static inline void DMA_enableOverRunInterrupt(DMA_Index_t index)
{
    //
    // Check the arguments.
    //
    assert(DMA_isChValid(index));
    //
    // Enable the specified DMA channel interrupt.
    //
    DMA->CHANNEL[index].CH_CFG |= DMA_CH_CFG_OVR_IE_Set(0x01U);
}

/*!
 * \brief Disables the DMA channel overrun interrupt.
 *
 * \details This function disables the indicated DMA channel's ability to generate an
 *  interrupt upon the detection of an overrun.
 *
 * \param[in] index the DMA channel index
 *
 */
static inline void DMA_disableOverRunInterrupt(DMA_Index_t index)
{
    //
    // Check the arguments.
    //
    assert(DMA_isChValid(index));
    //
    // Enable the specified DMA channel interrupt.
    //
    DMA->CHANNEL[index].CH_CFG &= ~DMA_CH_CFG_OVR_IE_Set(0x01U);
}

/*!
 * \brief Enables the DMA channel Bresp interrupt.
 *
 * \details This function enables the indicated DMA channel's ability to generate an
 *  interrupt upon the detection of an Bresp.
 *
 * \param[in] index the DMA channel index
 *
 */
static inline void DMA_enableBrespInterrupt(DMA_Index_t index)
{
    //
    // Check the arguments.
    //
    assert(DMA_isChValid(index));
    //
    // Enable the specified DMA channel interrupt.
    //
    DMA->CHANNEL[index].CH_CFG |= DMA_CH_CFG_BRESP_ERR_IE_Set(0x01U);
}

/*!
 * \brief Disables the DMA channel Bresp interrupt.
 *
 * \details This function disables the indicated DMA channel's ability to generate an
 *  interrupt upon the detection of an Bresp.
 *
 * \param[in] index the DMA channel index
 *
 */
static inline void DMA_disableBrespRunInterrupt(DMA_Index_t index)
{
    //
    // Check the arguments.
    //
    assert(DMA_isChValid(index));
    //
    // Enable the specified DMA channel interrupt.
    //
    DMA->CHANNEL[index].CH_CFG &= ~DMA_CH_CFG_BRESP_ERR_IE_Set(0x01U);
}

/*!
 * \brief Enables the DMA channel Rresp interrupt.
 *
 * \details This function enables the indicated DMA channel's ability to generate an
 *  interrupt upon the detection of an Rresp.
 *
 * \param[in] index the DMA channel index
 *
 */
static inline void DMA_enableRrespInterrupt(DMA_Index_t index)
{
    //
    // Check the arguments.
    //
    assert(DMA_isChValid(index));
    //
    // Enable the specified DMA channel interrupt.
    //
    DMA->CHANNEL[index].CH_CFG |= DMA_CH_CFG_RRESP_ERR_IE_Set(0x01U);
}

/*!
 * \brief Disables the DMA channel Rresp interrupt.
 *
 * \details This function disables the indicated DMA channel's ability to generate an
 *  interrupt upon the detection of an Rresp.
 *
 * \param[in] index the DMA channel index
 *
 */
static inline void DMA_disableRrespInterrupt(DMA_Index_t index)
{
    //
    // Check the arguments.
    //
    assert(DMA_isChValid(index));
    //
    // Enable the specified DMA channel interrupt.
    //
    DMA->CHANNEL[index].CH_CFG &= ~DMA_CH_CFG_RRESP_ERR_IE_Set(0x01U);
}

/*!
 * \brief Reset to a DMA channel.
 *
 * \details This function reset a DMA channel
 *
 * \param[in] index the DMA channel index
 *
 */
static inline void DMA_softReset(DMA_Index_t index)
{
    //
    // Check the arguments.
    //
    assert(DMA_isChValid(index));
    //
    // Set the peripheral interrupt trigger force bit.
    //
    DMA->CHANNEL[index].CH_CTRL |= DMA_CH_CTRL_SOFT_RESET_Set(0x01U);
}

/*!
 * \brief Force a peripheral trigger to a DMA channel.
 *
 * \details This function sets the peripheral trigger flag and if triggering a DMA
 *  burst is enabled
 * \param[in] index the DMA channel index
 *
 */
static inline void DMA_forceTrigger(DMA_Index_t index)
{
    //
    // Check the arguments.
    //
    assert(DMA_isChValid(index));
    //
    // Set the peripheral interrupt trigger force bit.
    //
    DMA->CHANNEL[index].CH_CTRL |= DMA_CH_CTRL_PERINTFRC_Set(0x01U);
}

/*!
 * \brief Starts a DMA channel.
 *
 * \details This function starts the DMA running, typically after you have configured it
 *
 * \param[in] index the DMA channel index
 *
 */
static inline void DMA_startChannel(DMA_Index_t index)
{
    //
    // Check the arguments.
    //
    assert(DMA_isChValid(index));
    //
    // Set the run bit.
    //
    DMA->CHANNEL[index].CH_CTRL |= DMA_CH_CTRL_RUN_Set(0x01U);
}

/*!
 * \brief Halts a DMA channel.
 *
 * \details This function halts the DMA at its current state and any current read-write
 *  access is completed.
 *
 * \param[in] index the DMA channel index
 *
 */
static inline void DMA_stopChannel(DMA_Index_t index)
{
    //
    // Check the arguments.
    //
    assert(DMA_isChValid(index));
    //
    // Set the halt bit.
    //
    DMA->CHANNEL[index].CH_CTRL |= DMA_CH_CTRL_HALT_Set(0x01U);
}

/*!
 * \brief Clears a DMA channel's peripheral trigger flag.
 *
 * \details This function clears the peripheral trigger flag.
 *
 * \param[in] index the DMA channel index
 *
 */
static inline void DMA_clearTriggerFlag(DMA_Index_t index)
{
    //
    // Check the arguments.
    //
    assert(DMA_isChValid(index));
    //
    // Write a one to the clear bit to clear the peripheral trigger flag.
    //

    DMA->CHANNEL[index].CH_STS |= DMA_CH_STS_PERINT_CLR_Set(0x01U);
}

/*!
 * \brief Gets the status of a DMA channel's peripheral trigger flag.
 *
 * \details This function returns \b true if a peripheral trigger event has occurred
 *
 * \param[in] index the DMA channel index
 * \return Return The Trigger flag status
 *
 */
static inline bool DMA_getTriggerFlagStatus(DMA_Index_t index)
{
    //
    // Check the arguments.
    //
    assert(DMA_isChValid(index));
    //
    // Read the peripheral trigger flag and return appropriately.
    //
    if (DMA_CH_STS_PERINT_FLG_Get(DMA->CHANNEL[index].CH_STS) != 0U)
        return true;
    else
        return false;
}

/*!
 * \brief Clears a DMA channel's trans begin flag.
 *
 * \details This function clears the trans begin flag.
 *
 * \param[in] index the DMA channel index
 *
 */
static inline void DMA_clearIntBegFlag(DMA_Index_t index)
{
    //
    // Check the arguments.
    //
    assert(DMA_isChValid(index));

    DMA->CHANNEL[index].CH_STS |= DMA_CH_STS_TRANS_BEG_CLR_Set(0x01U);
}

/*!
 * \brief Gets the status of a DMA channel's trans begin flag.
 *
 * \details This function returns \b true if a trans begin event has occurred
 *
 * \param[in] index the DMA channel index
 * \return Returns \b true if a trans begin event has occurred
 *
 */
static inline bool DMA_getIntBegFlagStatus(DMA_Index_t index)
{
    //
    // Check the arguments.
    //
    assert(DMA_isChValid(index));

    if (DMA_CH_STS_TRANS_BEG_FLG_Get(DMA->CHANNEL[index].CH_STS) != 0U)
        return true;
    else
        return false;
}

/*!
 * \brief Clears a DMA channel's trans end flag.
 *
 * \details This function clears the trans end flag.
 *
 * \param[in] index the DMA channel index
 *
 */
static inline void DMA_clearIntEndFlag(DMA_Index_t index)
{
    //
    // Check the arguments.
    //
    assert(DMA_isChValid(index));


    DMA->CHANNEL[index].CH_STS |= DMA_CH_STS_TRANS_END_CLR_Set(0x01U);
}

/*!
 * \brief Gets the status of a DMA channel's trans end flag.
 *
 * \details This function returns \b true if a trans end event has occurred
 *
 * \param[in] index the DMA channel index
 * \return Returns \b true if a trans end event has occurred
 *
 */
static inline bool DMA_getIntEndFlagStatus(DMA_Index_t index)
{
    //
    // Check the arguments.
    //
    assert(DMA_isChValid(index));

    if (DMA_CH_STS_TRANS_END_FLG_Get(DMA->CHANNEL[index].CH_STS) != 0U)
        return true;
    else
        return false;
}

/*!
 * \brief Gets the status of a DMA channel's trans overrun flag.
 *
 * \details This function returns \b true if a trans overrun event has occurred
 *
 * \param[in] index the DMA channel index
 * \return Returns \b true if a trans overrun event has occurred
 *
 */
static inline bool DMA_getIntOverRunStatus(DMA_Index_t index)
{
    //
    // Check the arguments.
    //
    assert(DMA_isChValid(index));

    if (DMA_CH_STS_OVR_FLG_Get(DMA->CHANNEL[index].CH_STS) != 0U)
        return true;
    else
        return false;
}

/*!
 * \brief Clears a DMA channel's trans bresp flag.
 *
 * \details This function clears the trans bresp flag.
 *
 * \param[in] index the DMA channel index
 *
 */
static inline void DMA_clearBrespFlag(DMA_Index_t index)
{
    //
    // Check the arguments.
    //
    assert(DMA_isChValid(index));

    DMA->CHANNEL[index].CH_STS |= DMA_CH_STS_BRESP_ERR_CLR_Set(0x01U);
}

/*!
 * \brief Gets the status of a DMA channel's trans bresp flag.
 *
 * \details This function returns \b true if a trans bresp event has occurred
 *
 * \param[in] index the DMA channel index
 * \return Returns \b true if a trans end event has occurred
 *
 */
static inline bool DMA_getIntBrespStatus(DMA_Index_t index)
{
    //
    // Check the arguments.
    //
    assert(DMA_isChValid(index));

    if (DMA_CH_STS_BRESP_ERR_CLR_Get(DMA->CHANNEL[index].CH_STS) != 0U)
        return true;
    else
        return false;
}

/*!
 * \brief Clears a DMA channel's trans Rresp flag.
 *
 * \details This function clears the trans Rresp flag.
 *
 * \param[in] index the DMA channel index
 *
 */
static inline void DMA_clearRrespFlag(DMA_Index_t index)
{
    //
    // Check the arguments.
    //
    assert(DMA_isChValid(index));

    DMA->CHANNEL[index].CH_STS |= DMA_CH_STS_RRESP_ERR_CLR_Set(0x01U);
}

/*!
 * \brief Gets the status of a DMA channel's trans Rresp flag.
 *
 * \details This function returns \b true if a trans Rresp event has occurred
 *
 * \param[in] index the DMA channel index
 * \return Returns \b true if a trans end event has occurred
 *
 */
static inline bool DMA_getIntRrespStatus(DMA_Index_t index)
{
    //
    // Check the arguments.
    //
    assert(DMA_isChValid(index));

    if (DMA_CH_STS_RRESP_ERR_CLR_Get(DMA->CHANNEL[index].CH_STS) != 0U)
        return true;
    else
        return false;
}

/*!
 * \brief Clears a DMA channel's ALL flag.
 *
 * \details This function clears the all flag.
 *
 * \param[in] index the DMA channel index
 *
 */
static inline void DMA_clearStatusFlag(DMA_Index_t index)
{
    //
    // Check the arguments.
    //
    assert(DMA_isChValid(index));
    //
    // Write a one to the clear bit to clear the peripheral trigger flag.
    //
    DMA->CHANNEL[index].CH_STS |= DMA_CH_STS_PERINT_CLR_Set(0x01U);
    DMA->CHANNEL[index].CH_STS |= DMA_CH_STS_OVR_CLR_Set(0x01U);
    DMA->CHANNEL[index].CH_STS |= DMA_CH_STS_TRANS_END_CLR_Set(0x01U);
    DMA->CHANNEL[index].CH_STS |= DMA_CH_STS_TRANS_BEG_CLR_Set(0x01U);
}

/*!
 * \brief Clears the DMA channel error flags.
 *
 * \details This function clears both the DMA channel's sync error flag and its
 *  overrun error flag.
 *
 * \param[in] index the DMA channel index
 *
 */
static inline void DMA_clearErrorFlag(DMA_Index_t index)
{
    //
    // Check the arguments.
    //
    assert(DMA_isChValid(index));
    //
    // Write to the error clear bit.
    //
    DMA->CHANNEL[index].CH_STS |= DMA_CH_STS_OVR_FLG_Set(0x01U);
}

/*!
 * \brief Gets the DMA status.
 *
 * \details This function gets the status.
 *
 * \param[in] index the DMA channel index
 * \return dma ch status.
 *
 */
static inline uint32_t DMA_getCHStatus(DMA_Index_t index)
{
    return DMA->CHANNEL[index].CH_STS;
}

/*!
 * \brief Gets the Burst cnt.
 *
 * \details This function gets the burst cnt.
 *
 * \param[in] index the DMA channel index
 * \return dma ch burst cnt.
 *
 */
static inline uint32_t DMA_getBurstCnt(DMA_Index_t index)
{
    return DMA_CH_BURST_SET_BURST_COUNT_Get(DMA->CHANNEL[index].CH_BURST_SET);
}

/*!
 * \brief Gets the Trans cnt.
 *
 * \details This function gets the Trans cnt.
 *
 * \param[in] index the DMA channel index
 * \return dma ch Trans cnt.
 *
 */
static inline uint32_t DMA_getTransCnt(DMA_Index_t index)
{
    return DMA_CH_TRANSFER_SET_TRANS_COUNT_Get(DMA->CHANNEL[index].CH_TRANSFER_SET);
}

/*!
 * \brief Gets the SrcWrap cnt.
 *
 * \details This function gets the SrcWrap cnt.
 *
 * \param[in] index the DMA channel index
 * \return dma ch SrcWrap cnt.
 *
 */
static inline uint32_t DMA_getSrcWrapCnt(DMA_Index_t index)
{
    return DMA_CH_SRC_WRAP_SET_SRC_WRAP_COUNT_Get(DMA->CHANNEL[index].CH_SRC_WRAP_SET);
}

/*!
 * \brief Gets the DstWrap cnt.
 *
 * \details This function gets the DstWrap cnt.
 *
 * \param[in] index the DMA channel index
 * \return dma ch DstWrap cnt.
 *
 */
static inline uint32_t DMA_getDstWrapCnt(DMA_Index_t index)
{
    return DMA_CH_DST_WRAP_SET_DST_WRAP_COUNT_Get(DMA->CHANNEL[index].CH_DST_WRAP_SET);
}


/*!
 * \brief Configures the source address for the DMA channel
 *
 * \details This function configures the source address of a DMA channel.
 *
 * \param[in] index the DMA channel index
 * \param[in] srcAddr the DMA channel source address
 *
 */
static inline void DMA_configSourceAddress(DMA_Index_t index, const void *srcAddr)
{
    //
    // Check the arguments.
    //
    assert(DMA_isChValid(index));
    //
    // Set up SOURCE address.
    //
    DMA->CHANNEL[index].CH_SRC_BEG_ADDR_SHADOW = (uint32_t)srcAddr;
    DMA->CHANNEL[index].CH_SRC_ADDR_SHADOW     = (uint32_t)srcAddr;
}

/*!
 * \brief Gets the SrcBegAddr active.
 *
 * \details This function gets the SrcBegAddr active.
 *
 * \param[in] index the DMA channel index
 * \return dma ch SrcBegAddr active.
 *
 */
static inline uint32_t DMA_getSrcBegAddrActive(DMA_Index_t index)
{
    return DMA->CHANNEL[index].CH_SRC_BEG_ADDR_ACTIVE;
}

/*!
 * \brief Gets the SrcAddr active.
 *
 * \details This function gets the SrcAddr active.
 *
 * \param[in] index the DMA channel index
 * \return dma ch SrcAddr active.
 *
 */
static inline uint32_t DMA_getSrcAddrActive(DMA_Index_t index)
{
    return DMA->CHANNEL[index].CH_SRC_ADDR_ACTIVE;
}

/*!
 * \brief Configures the destination address for the DMA channel
 *
 * \details This function configures the destinaton address of a DMA channel.
 *
 * \param[in] index the DMA channel index
 * \param[in] *destAddr is the destination address.
 *
 */
static inline void DMA_configDestAddress(DMA_Index_t index, const void *destAddr)
{
    //
    // Check the arguments.
    //
    assert(DMA_isChValid(index));
    //
    // Set up DESTINATION address.
    //
    DMA->CHANNEL[index].CH_DST_BEG_ADDR_SHADOW = (uint32_t)destAddr;
    DMA->CHANNEL[index].CH_DST_ADDR_SHADOW     = (uint32_t)destAddr;
}

/*!
 * \brief Gets the DstBegAddr active.
 *
 * \details This function gets the DstBegAddr active.
 *
 * \param[in] index the DMA channel index
 * \return dma ch DstBegAddr active.
 *
 */
static inline uint32_t DMA_getDstBegAddrActive(DMA_Index_t index)
{
    return DMA->CHANNEL[index].CH_DST_BEG_ADDR_ACTIVE;
}

/*!
 * \brief Gets the DstAddr active.
 *
 * \details This function gets the DstAddr active.
 *
 * \param[in] index the DMA channel index
 * \return dma ch DstAddr active.
 *
 */
static inline uint32_t DMA_getDstAddrActive(DMA_Index_t index)
{
    return DMA->CHANNEL[index].CH_DST_ADDR_ACTIVE;
}


/*!
 * \brief config dma channel trigger source
 *
 * \details This function config trigger source for each dma channel
 *
 * \param[in] index the DMA channel index
 * \param[in] trigger the DMA trigger source
 *
 */
static inline void DMA_configTrigger(DMA_Index_t index, DMA_Trigger_t trigger)
{
    //
    // Check the arguments.
    //
    assert(DMA_isChValid(index));

    DMA->CHANNEL[index].CH_CFG &= ~DMA_CH_CFG_PERINTSEL_Msk;
    DMA->CHANNEL[index].CH_CFG |= DMA_CH_CFG_PERINTSEL_Set(trigger);
}

/*!
 * \brief Set dma data size
 *
 * \details This function set dma data size for each channel
 *
 * \param[in] index the DMA channel index
 * \param[in] dsize the data size
 *
 */
static inline void DMA_setDataSize(DMA_Index_t index, DMA_DataSize_t dsize)
{
    //
    // Check the arguments.
    //
    assert(DMA_isChValid(index));

    DMA->CHANNEL[index].CH_BURST_SET &= ~DMA_CH_BURST_SET_DSIZE_Msk;
    DMA->CHANNEL[index].CH_BURST_SET |= DMA_CH_BURST_SET_DSIZE_Set(dsize);
}

/*!
 * \brief Initiaze the DMA module
 *
 * \details This function Initiaze the DMA module
 *
 */
void DMA_initialize(void);

/*!
 * \brief Configures the DMA channel
 *
 * \details This function configures the source and destination
 * addresses of a DMA channel.
 *
 * \param[in] index the DMA channel index
 * \param[in] *destAddr is the destination address.
 * \param[in] *srcAddr is a source address.
 */
void DMA_configAddresses(DMA_Index_t index, const void *destAddr, const void *srcAddr);

/*!
 * \brief Configures the DMA channel's burst settings.
 *
 * \details This function configures the size of each burst and the address step size.
 *
 * \param[in] index the DMA channel index
 * \param[in] size is the number of words transferred per burst.
 * \param[in] srcStep is the amount to increment or decrement the source address
 *   after each word of a burst.
 * \param[in] destStep is the amount to increment or decrement the destination
 *   address after each word of a burst.
 */
void DMA_configBurst(DMA_Index_t index, uint16_t size, int16_t srcStep, int16_t destStep);


/*!
 * \brief Configures the DMA channel's transfer settings.
 *
 * \details This function configures the transfer size and the address step that is
 *  made after each burst.
 *
 * \param[in] index the DMA channel index
 * \param[in] transferSize is the number of bursts per transfer.
 * \param[in] srcStep is the amount to increment or decrement the source address
 *   after each burst of a transfer unless a wrap occurs.
 * \param[in] destStep is the amount to increment or decrement the destination
 *   address after each burst of a transfer unless a wrap occurs.
 */
void DMA_configTransfer(DMA_Index_t index, uint32_t transferSize, int16_t srcStep, int16_t destStep);

/*!
 * \brief Configures the DMA channel's wrap settings.
 *
 * \details This function configures the DMA channel's wrap settings.
 *
 * \param[in] index the DMA channel index
 * \param[in] srcWrapSize is the number of bursts to be transferred before a wrap
 *   of the source address occurs.
 * \param[in] srcStep is the amount to increment or decrement the source address
 *   after each burst of a transfer unless a wrap occurs.
 * \param[in] destWrapSize is the number of bursts to be transferred before a wrap
 *   of the destination address occurs.
 * \param[in] destStep is the amount to increment or decrement the destination
 *   address after each word of a burst.
 */
void DMA_configWrap(DMA_Index_t index, uint32_t srcWrapSize, int16_t srcStep, uint32_t destWrapSize, int16_t destStep);

/*!
 * \brief Configures the DMA mode.
 *
 * \details  This function configures the DMA channel's mode.
 *
 * \param[in] index the DMA channel index
 * \param[in] mode is DMA work mode.
 */
void DMA_configMode(DMA_Index_t index, DMA_CfgMode_t mode);

/*!
 * \brief Register user callback function to a specified DMA
 *
 * \details This function registers user callback function for DMA which uses IRQ. The relative IRQ
 will be enabled in the NVIC and the priority will be configured at the same time

 * \param[in] intsrc the DMA channel INT index
 * \param[in] callback DMA user callback
 * \param[in] priority IRQ priority
 *
 * \retval kSTATUS_SUCESS Success to the operation
 * \retval kSTATUS_FAIL Register to a DMA CH which has been registered already. Need to call \ref
 DMA_unregisterCallback() before the re-registration
 */
status_t DMA_registerCallback(DMA_IntSrc_t intsrc, DMA_Callback_t callback, uint32_t priority);


/*!
 * \brief Unregister user callback function to DMA transfer
 *
 * \details This function clears the registered user callback function, and disable the relative IRQ in the NVIC
 *
 * \param[in] intsrc the DMA channel INT index
 * \retval kSTATUS_SUCESS Success to the operation
 * \retval kSTATUS_INVALID_ARGUMENT The DMA hasn't been registered to a callback
 */
status_t DMA_unregisterCallback(DMA_IntSrc_t intsrc);

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */ /* end of DRV_HTE_DMA */

#endif // HTE_DMA_H
