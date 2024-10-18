/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*!
 * \file hte_tfu.h
 * \brief SDK TFU driver header file
 * \version 1.0.0
 */
#ifndef HTE_TFU_H
#define HTE_TFU_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_common.h"
#include "hte_dma.h"

/*!
 * \addtogroup DRV_HTE_TFU TFU Driver
 *
 * \brief SDK TFU driver
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! \brief Enumeration for TFU source number */
typedef enum
{
    kTFU_INDEX_0 = 0, /*!< Identifies the first TFU instance */
    kTFU_INDEX_1 = 1, /*!< Identifies the second TFU instance */
    kTFU_INDEX_MAX    /*!< The max of index of TFU */
} TFU_Index_t;

/*! \brief TFU Interrupt Types Enumeration */
typedef enum
{
    kTFU1_INT_TRD3_OVERFLOW_EN = (1 << 0),    /*!< Enables the overflow interrupt for TRD3 */
    kTFU1_INT_TRD2_OVERFLOW_EN = (1 << 1),    /*!< Enables the overflow interrupt for TRD2 */
    kTFU1_INT_TRD1_OVERFLOW_EN = (1 << 2),    /*!< Enables the overflow interrupt for TRD1 */
    kTFU1_INT_TRD0_OVERFLOW_EN = (1 << 3),    /*!< Enables the overflow interrupt for TRD0 */
    kTFU1_INT_TRD3_UNDERFLOW_EN = (1 << 4),   /*!< Enables underflow interrupt for TRD3 in TFU1 */
    kTFU1_INT_TRD2_UNDERFLOW_EN = (1 << 5),   /*!< Enables underflow interrupt for TRD2 in TFU1 */
    kTFU1_INT_TRD1_UNDERFLOW_EN = (1 << 6),   /*!< Enables underflow interrupt for TRD1 in TFU1 */
    kTFU1_INT_TRD0_UNDERFLOW_EN = (1 << 7),   /*!< Enables underflow interrupt for TRD0 in TFU1 */
    kTFU1_INT_TRD3_RESPONSE_EN = (1 << 8),    /*!< Enables response interrupt for TRD3 in TFU1 */
    kTFU1_INT_TRD2_RESPONSE_EN = (1 << 9),    /*!< Enables response interrupt for TRD2 in TFU1 */
    kTFU1_INT_TRD1_RESPONSE_EN = (1 << 10),   /*!< Enables response interrupt for TRD1 in TFU1 */
    kTFU1_INT_TRD0_RESPONSE_EN = (1 << 11),   /*!< Enables response interrupt for TRD0 in TFU1 */
    kTFU0_INT_TRD3_OVERFLOW_EN = (1 << 12),   /*!< Enables overflow interrupt for TRD3 in TFU0 */
    kTFU0_INT_TRD2_OVERFLOW_EN = (1 << 13),   /*!< Enables overflow interrupt for TRD2 in TFU0 */
    kTFU0_INT_TRD1_OVERFLOW_EN = (1 << 14),   /*!< Enables overflow interrupt for TRD1 in TFU0 */
    kTFU0_INT_TRD0_OVERFLOW_EN = (1 << 15),   /*!< Enables overflow interrupt for TRD0 in TFU0 */
    kTFU0_INT_TRD3_UNDERFLOW_EN = (1 << 16),  /*!< Enables underflow interrupt for TRD3 in TFU0 */
    kTFU0_INT_TRD2_UNDERFLOW_EN = (1 << 17),  /*!< Enables underflow interrupt for TRD2 in TFU0 */
    kTFU0_INT_TRD1_UNDERFLOW_EN = (1 << 18),  /*!< Enables underflow interrupt for TRD1 in TFU0 */
    kTFU0_INT_TRD0_UNDERFLOW_EN = (1 << 19),  /*!< Enables underflow interrupt for TRD0 in TFU0 */
    kTFU0_INT_TRD3_RESPONSE_EN = (1 << 20),   /*!< Enables response interrupt for TRD3 in TFU0 */
    kTFU0_INT_TRD2_RESPONSE_EN = (1 << 21),   /*!< Enables response interrupt for TRD2 in TFU0 */
    kTFU0_INT_TRD1_RESPONSE_EN = (1 << 22),   /*!< Enables response interrupt for TRD1 in TFU0 */
    kTFU0_INT_TRD0_RESPONSE_EN = (1 << 23),   /*!< Enables response interrupt for TRD0 in TFU0 */
    kTFU_INT_ALL_ENABLE         = 0x0FFFFFFF   /*!< The max of index of TFU interrupt */
} TFU_InterruptType_t;

/*! \brief TFU cpu select num */
typedef enum
{
    kTFU1_TRD3_SELSECT_CPU1 = (1 << 0),       /*!< Selects TRD3 from TFU1 for assignment to CPU1 */
    kTFU1_TRD2_SELSECT_CPU1 = (1 << 1),       /*!< Selects TRD2 from TFU1 for assignment to CPU1 */
    kTFU1_TRD1_SELSECT_CPU1 = (1 << 2),       /*!< Selects TRD1 from TFU1 for assignment to CPU1 */
    kTFU1_TRD0_SELSECT_CPU1 = (1 << 3),       /*!< Selects TRD0 from TFU1 for assignment to CPU1 */
    kTFU0_TRD3_SELSECT_CPU1 = (1 << 4),       /*!< Selects TRD3 from TFU0 for assignment to CPU1 */
    kTFU0_TRD2_SELSECT_CPU1 = (1 << 5),       /*!< Selects TRD3 from TFU0 for assignment to CPU1 */
    kTFU0_TRD1_SELSECT_CPU1 = (1 << 6),       /*!< Selects TRD3 from TFU0 for assignment to CPU1 */
    kTFU0_TRD0_SELSECT_CPU1 = (1 << 7),       /*!< Selects TRD3 from TFU0 for assignment to CPU1 */
    kTFU_SELECT_CPU1_ALL    = 0xFF            /*!< The max of index of TFU CPU */
} TFU_CpuSelect_t;

/*! \brief  CORDIC Config Structure definition */
typedef struct
{
    uint32_t threadnum; /*!< Threadnum of TFU from different CPUs, this parameter can be a value of \ref
                           TFU_Thread_Num */
    uint32_t function;  /*!< Function, this parameter can be a value of \ref TFU_Function */
    uint32_t inSize;    /*!< Width of input data, this parameter can be a value of \ref TFU_In_Size */
    uint32_t outSize;   /*!< Width of output data, this parameter can be a value of \ref TFU_Out_Size */
    uint32_t nbWrite;   /*!< Number of 32-bit write expected for one calculation, this parameter can be a value of \ref
                           TFU_Nb_Write */
    uint32_t nbRead;    /*!< Number of 32-bit read expected after one calculation, this parameter can be a value of \ref
                           TFU_Nb_Read */
    uint32_t precision; /*!< Number of cycles for calculation, this parameter can be a value of \ref
                           TFU_Precision_In_Cycles_Number */
    uint32_t priority;  /*!< Number of 32-bit priority number */
} TFU_ConfigType_t;

/*!
 * \defgroup TFU_Thread_Num TFU thread number
 *
 * @{
 */
#define TFU_THREADNUM_0 (0U) /*!< Thread number 0 */
#define TFU_THREADNUM_1 (1U) /*!< Thread number 1 */
#define TFU_THREADNUM_2 (2U) /*!< Thread number 2 */
#define TFU_THREADNUM_3 (3U) /*!< Thread number 3 */
/*!
 * @}
 */

/*!
 * \defgroup TFU_Function TFU operation function
 *
 * @{
 */
#define TFU_FUNCTION_COSINE     (0U) /*!< Cosine */
#define TFU_FUNCTION_SINE       (1U) /*!< Sine */
#define TFU_FUNCTION_PHASE      (2U) /*!< Phase */
#define TFU_FUNCTION_MODULUS    (3U) /*!< Modulus */
#define TFU_FUNCTION_ARCTANGENT (4U) /*!< Arctangent */
#define TFU_FUNCTION_NATURALLOG (5U) /*!< Natural Logarithm */
#define TFU_FUNCTION_EXPONENT   (6U) /*!< Square Root */
/*!
 * @}
 */

/*!
 * \defgroup TFU_Precision_In_Cycles_Number TFU Precision in Cycles Number
 *
 * \note 1 cycle corresponds to 4 algorithm iterations
 *
 * @{
 */
#define TFU_PRECISION_1CYCLE   (1U)  /*!< Within 1 clock cycle for precision configurations*/
#define TFU_PRECISION_3CYCLES  (3U)  /*!< Within 2 clock cycles for precision configurations*/
#define TFU_PRECISION_2CYCLES  (2U)  /*!< Within 3 clock cycles for precision configurations*/
#define TFU_PRECISION_4CYCLES  (4U)  /*!< Within 4 clock cycles for precision configurations*/
#define TFU_PRECISION_5CYCLES  (5U)  /*!< Within 5 clock cycles for precision configurations*/
#define TFU_PRECISION_6CYCLES  (6U)  /*!< Within 6 clock cycles for precision configurations*/
#define TFU_PRECISION_7CYCLES  (7U)  /*!< Within 7 clock cycles for precision configurations*/
#define TFU_PRECISION_8CYCLES  (8U)  /*!< Within 8 clock cycles for precision configurations*/
#define TFU_PRECISION_9CYCLES  (9U)  /*!< Within 9 clock cycles for precision configurations*/
#define TFU_PRECISION_10CYCLES (10U) /*!< Within 10 clock cycles for precision configurations*/
#define TFU_PRECISION_11CYCLES (11U) /*!< Within 11 clock cycles for precision configurations*/
#define TFU_PRECISION_12CYCLES (12U) /*!< Within 12 clock cycles for precision configurations*/
#define TFU_PRECISION_13CYCLES (13U) /*!< Within 13 clock cycles for precision configurations*/
#define TFU_PRECISION_14CYCLES (14U) /*!< Within 14 clock cycles for precision configurations*/
#define TFU_PRECISION_15CYCLES (15U) /*!< Within 15 clock cycles for precision configurations*/
/*!
 * @}
 */

/*!
 * \defgroup TFU_In_Size TFU input data size
 *
 * @{
 */
#define TFU_INSIZE_32BITS (0U) /*!< 32 bits input data size (Q1.31 format) */
#define TFU_INSIZE_16BITS (1U) /*!< 16 bits input data size (Q1.15 format) */
/*!
 * @}
 */

/*!
 * \defgroup TFU_Out_Size TFU Results Size
 *
 * @{
 */
#define TFU_OUTSIZE_32BITS (0U) /*!< 32 bits output data size (Q1.31 format) */
#define TFU_OUTSIZE_16BITS (1U) /*!< 16 bits output data size (Q1.15 format) */
/*!
 * @}
 */

/*!
 * \defgroup TFU_Out_Size TFU Results Size
 *
 * @{
 */
#define TFU_PRIORITY_FIXED (0U) /*!< Fixed-priority mode */
#define TFU_PRIORITY_RR    (1U) /*!< Round-robin mode */
/*!
 * @}
 */

/*!
 * \defgroup TFU_Nb_Write TFU Number of 32-bit write required for one calculation
 *
 * @{
 */
#define TFU_NBWRITE_1                                                                                                 \
    (0U) /*!< One 32-bits write containing either only one 32-bit data input (Q1.31 format), or two 16-bit data input \
            (Q1.15 format) packed in one 32 bits data */
#define TFU_NBWRITE_2 (1U) /*!< Two 32-bit write containing two 32-bits data input (Q1.31 format) */
/*!
 * @}
 */

/*!
 * \defgroup TFU_Nb_Read TFU Number of 32-bit read required after one calculation
 *
 * @{
 */
#define TFU_NBREAD_1                                                                                                   \
    (0U) /*!< One 32-bits read containing either only one 32-bit data output (Q1.31 format), or two 16-bit data output \
            (Q1.15 format) packed in one 32 bits data */
#define TFU_NBREAD_2 (1U) /*!< Two 32-bit Data containing two 32-bits data output (Q1.31 format) */

/*!
 * @}
 */

/*!
 * \defgroup TFU_DMA_Direction TFU DMA direction
 *
 * @{
 */
#define TFU_DMA_DIR_NONE   ((uint32_t)0x00000000U) /*!< DMA direction : none */
#define TFU_DMA_DIR_IN     ((uint32_t)0x00000001U) /*!< DMA direction : Input of TFU */
#define TFU_DMA_DIR_OUT    ((uint32_t)0x00000002U) /*!< DMA direction : Output of TFU */
#define TFU_DMA_DIR_IN_OUT ((uint32_t)0x00000003U) /*!< DMA direction : Input and Output of TFU */
/*!
 * @}
 */

#define TFU0_LUTP_REG32(x) \
    (*(volatile uint32_t *)(x * 0x4 + 0x40100088)) /*!< The 32-bit Look-Up Table (LUT) Polynomial register of TFU0. */
#define TFU0_LUTM_REG32(x) \
    (*(volatile uint32_t *)(x * 0x4 + 0x401000e8)) /*!< The 32-bit Look-Up Table (LUT) Matrix register of TFU0. */
#define TFU1_LUTP_REG32(x) \
    (*(volatile uint32_t *)(x * 0x4 + 0x401001d8)) /*!< The 32-bit Look-Up Table (LUT) Polynomial register of TFU1. */
#define TFU1_LUTM_REG32(x) \
    (*(volatile uint32_t *)(x * 0x4 + 0x40100238)) /*!< The 32-bit Look-Up Table (LUT) Matrix register of TFU1. */

/* Private macros --------------------------------------------------------*/
/*!
 * \defgroup  TFU_Private_Macros   TFU Private Macros
 *
 * @{
 */

/*!
 * \brief  Verify the TFU function.
 *
 * \param  __THREADNUM__ Name of the function.
 *
 * \retval SET (__FUNCTION__ is a valid value) or RESET (__FUNCTION__ is invalid)
 */
#define IS_TFU_THREADNUM(__THREADNUM__)                                              \
    (((__THREADNUM__) == TFU_THREADNUM_0) || ((__THREADNUM__) == TFU_THREADNUM_1) || \
     ((__THREADNUM__) == TFU_THREADNUM_2) || ((__THREADNUM__) == TFU_THREADNUM_3))


/*!
 * \brief  Verify the TFU function.
 *
 * \param  __FUNCTION__ Name of the function.
 *
 * \retval SET (__FUNCTION__ is a valid value) or RESET (__FUNCTION__ is invalid)
 */
#define IS_TFU_FUNCTION(__FUNCTION__)                                                              \
    (((__FUNCTION__) == TFU_FUNCTION_COSINE) || ((__FUNCTION__) == TFU_FUNCTION_SINE) ||           \
     ((__FUNCTION__) == TFU_FUNCTION_PHASE) || ((__FUNCTION__) == TFU_FUNCTION_MODULUS) ||         \
     ((__FUNCTION__) == TFU_FUNCTION_ARCTANGENT) || ((__FUNCTION__) == TFU_FUNCTION_NATURALLOG) || \
     ((__FUNCTION__) == TFU_FUNCTION_EXPONENT))


/*!
 * \brief  Verify the TFU precision.
 *
 * \param  __PRECISION__ TFU Precision in Cycles Number.
 *
 * \retval SET (__PRECISION__ is a valid value) or RESET (__PRECISION__ is invalid)
 */
#define IS_TFU_PRECISION(__PRECISION__)                                                            \
    (((__PRECISION__) == TFU_PRECISION_1CYCLE) || ((__PRECISION__) == TFU_PRECISION_2CYCLES) ||    \
     ((__PRECISION__) == TFU_PRECISION_3CYCLES) || ((__PRECISION__) == TFU_PRECISION_4CYCLES) ||   \
     ((__PRECISION__) == TFU_PRECISION_5CYCLES) || ((__PRECISION__) == TFU_PRECISION_6CYCLES) ||   \
     ((__PRECISION__) == TFU_PRECISION_7CYCLES) || ((__PRECISION__) == TFU_PRECISION_8CYCLES) ||   \
     ((__PRECISION__) == TFU_PRECISION_9CYCLES) || ((__PRECISION__) == TFU_PRECISION_10CYCLES) ||  \
     ((__PRECISION__) == TFU_PRECISION_11CYCLES) || ((__PRECISION__) == TFU_PRECISION_12CYCLES) || \
     ((__PRECISION__) == TFU_PRECISION_13CYCLES) || ((__PRECISION__) == TFU_PRECISION_14CYCLES) || \
     ((__PRECISION__) == TFU_PRECISION_15CYCLES))


/*!
 * \brief  Verify the TFU number of 32-bits write expected for one calculation.
 *
 * \param  __NBWRITE__ Number of 32-bits write expected for one calculation.
 *
 * \retval SET (__NBWRITE__ is a valid value) or RESET (__NBWRITE__ is invalid)
 */
#define IS_TFU_NBWRITE(__NBWRITE__) (((__NBWRITE__) == TFU_NBWRITE_1) || ((__NBWRITE__) == TFU_NBWRITE_2))

/*!
 * \brief  Verify the TFU number of 32-bits read expected after one calculation.
 *
 * \param  __NBREAD__ Number of 32-bits read expected after one calculation.
 *
 * \retval SET (__NBREAD__ is a valid value) or RESET (__NBREAD__ is invalid)
 */
#define IS_TFU_NBREAD(__NBREAD__) (((__NBREAD__) == TFU_NBREAD_1) || ((__NBREAD__) == TFU_NBREAD_2))

/*!
 * \brief  Verify the TFU input data size for one calculation.
 *
 * \param  __INSIZE__ input data size for one calculation.
 *
 * \retval SET (__INSIZE__ is a valid value) or RESET (__INSIZE__ is invalid)
 */
#define IS_TFU_INSIZE(__INSIZE__) (((__INSIZE__) == TFU_INSIZE_32BITS) || ((__INSIZE__) == TFU_INSIZE_16BITS))

/*!
 * \brief  Verify the TFU output data size for one calculation.
 *
 * \param  __OUTSIZE__ output data size for one calculation.
 *
 * \retval SET (__OUTSIZE__ is a valid value) or RESET (__OUTSIZE__ is invalid)
 */
#define IS_TFU_OUTSIZE(__OUTSIZE__) (((__OUTSIZE__) == TFU_OUTSIZE_32BITS) || ((__OUTSIZE__) == TFU_OUTSIZE_16BITS))

/*!
 * \brief  Verify the TFU DMA transfer Direction.
 *
 * \param  __DMADIR__ DMA transfer direction.
 *
 * \retval SET (__DMADIR__ is a valid value) or RESET (__DMADIR__ is invalid)
 */
#define IS_TFU_DMA_DIRECTION(__DMADIR__) \
    (((__DMADIR__) == TFU_DMA_DIR_IN) || ((__DMADIR__) == TFU_DMA_DIR_OUT) || ((__DMADIR__) == TFU_DMA_DIR_IN_OUT))

/*!
 * @}
 */

/*******************************************************************************
 * APIs
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Configure TFU LUT Base Value
 *
 * \details Configures the Look-Up Table (LUT) base value 
 * for a specified TFU number within a system.
 *
 * \param[in] tfux Pointer to the base address of the TFU peripheral.
 * \param[in] tfunum An unsigned 32-bit integer specifying the TFU unit number to configure.
 * \param[in] base A double-precision number for the LUT.
 *
 * \note This function is crucial for setting up the initial conditions.
 *
 * \warning Incorrect configuration of the LUT base value can lead to unexpected computation.
 */
void TFU_LUTBaseConfig(TFU_Type* tfux, uint32_t tfunum, double base);

/*!
 * \brief Disable DMA Function for TFU Thread
 *
 * \details Disables the Direct Memory Access (DMA) 
 * functionality for a specific thread within a given TFU number.
 *
 * \param[in] tfux Pointer to the base address of the TFU peripheral.
 * \param[in] tfunum Unsigned 32-bit integer specifying the TFU unit number.
 * \param[in] threadnum Unsigned 32-bit integer identifying the thread. 
 *
 * \note Disabling DMA may impact performance if large amounts of data are processed.
 *
 * \warning Ensure that disabling DMA does not interfere with other ongoing processes
 *  or lead to data synchronization issues within the system.
 */
void TFU_dmaFunctionDisable(TFU_Type* tfux, uint32_t tfunum, uint32_t threadnum);

/*!
 * \brief TFU DMA Input Transfer Complete Callback Function
 *
 * \details This function is a callback that is invoked by the DMA controller when a DMA transfer to the TFU
 * input buffer has completed successfully.
 *
 * \param[in] index DMA channel/index where the transfer was performed.
 *
 * \note This callback function should be registered with the DMA driver to handle completion of 
 * DMA transfers to the TFU input.
 */
void TFU_DMAInCplt(DMA_Index_t index);

/*!
 * \brief TFU DMA Output Transfer Complete Callback Function
 *
 * \details This function serves as a callback that is called by the DMA controller upon successful completion of a DMA transfer
 * from the TFU output buffer.
 *
 * \param[in] index DMA channel/index where the transfer was performed.

 * \note This callback function should be registered with the DMA driver to handle the completion of DMA transfers from the TFU output.
 */
void TFU_DMAOutCplt(DMA_Index_t index);

/*!
 * \brief Configure TFU 
 *
 * \details This function configures the TFU instance identified by \p tfuIdx according to the configuration settings
 * provided in the \p sConfig pointer.
 *
 * \param[in] tfuIdx Index of the TFU instance to configure (e.g., kTFU_INDEX_0, kTFU_INDEX_1).
 *
 * \param[in] sConfig Pointer to a TFU_ConfigType_t structure containing the desired configuration parameters for the TFU.
 * \return bool Returns true if the configuration succeeds, false otherwise.
 *
 * \note The caller should ensure that the provided \p sConfig structure contains valid and applicable settings for the TFU.
 * This function initializes or updates the operational parameters of the selected TFU based on the configuration passed.
 */
bool TFU_Configure(TFU_Index_t tfuIdx, TFU_ConfigType_t *sConfig);

/*!
 * \brief Assign TFU Resources to a CPU
 *
 * \details This function selects which CPU will have access to the resources of the TFU.
 * The specified \p cpuNumber determines which CPU will be granted access to the TFU resources.

 * \param[in] cpuNumber The CPU number to assign TFU resources to. The actual mapping of numbers to CPUs depends on the system architecture.

 * \note This function should be used in multi-CPU systems where resource allocation needs to be managed dynamically.
 */
void TFU_cpuSelect(uint32_t cpuNumber);

/*!
 * \brief Select and Enable TFU Interrupts
 *
 * \details This function selects and enables the specified interrupt(s) for the TFU.
 * The \p interruptType parameter indicates which TFU interrupt(s) to enable.
 * \param[in] interruptType A bitwise combination of values from the TFU_InterruptType_t enumeration.
 * \note By calling this function, the indicated interrupt(s) will be enabled in the TFU module.
 */
void TFU_interrputSelect(uint32_t interruptType);

/*!
 * \brief Perform Calculation on TFU
 *
 * \details This function initiates a calculation on the TFU instance identified by \p tfuIdx, 
 * using the given input buffer (\p pInBuff),output buffer (\p pOutBuff), 
 * and the number of calculations to perform (\p NbCalc).
 * \param[in] tfuIdx The index of the TFU instance to perform the calculation on.
 * \param[in] threadnum The number of the thread within the TFU to use for the calculation.
 * \param[in] pInBuff A pointer to the input buffer containing data to be processed by the TFU.
 * \param[out] pOutBuff A pointer to the output buffer where the results of the calculation will be stored.
 * \param[in] NbCalc The number of calculations to be performed by the TFU.
 * \return bool Returns true if the calculation request is successfully submitted to the TFU, false otherwise.
 *
 * \note The caller should ensure that the input and output buffers are correctly allocated and aligned.
 */
bool TFU_valueCalculate(TFU_Index_t tfuIdx, uint32_t threadnum, uint32_t *pInBuff, 
                                uint32_t *pOutBuff, uint32_t NbCalc);

/*!
 * \brief Perform Zero-Overhead Calculation on TFU
 *
 * \details This function initiates a zero-overhead calculation on the TFU instance identified by \p tfuIdx.

 * \param[in] tfuIdx The index of the TFU instance to perform the zero-overhead calculation on.
 * \param[in] threadnum The number of the thread within the TFU to utilize for the calculation.
 * \param[in] pInBuff A pointer to the input buffer containing data to be processed by the TFU.
 * \param[out] pOutBuff A pointer to the output buffer where the results of the calculation will be stored.
 * \param[in] NbCalc The number of calculations to be performed by the TFU without overhead.
 * \return bool Returns true if the zero-overhead calculation request is successfully submitted to the TFU, false otherwise.
 *
 * \note The caller should ensure that the input and output buffers are suitably allocated and aligned.
 */
bool TFU_valueCalculateZO(TFU_Index_t tfuIdx, uint32_t threadnum, uint32_t *pInBuff, 
                                uint32_t *pOutBuff, uint32_t NbCalc);

/*!
 * \brief Perform Zero-Overhead Calculation on TFU for Application
 *
 * \details This function initiates a zero-overhead calculation on the TFU for the application context.
 * \param[in] pInBuff A pointer to the input buffer containing data to be processed by the TFU.
 * \param[out] pOutBuff A pointer to the output buffer where the results of the calculation will be stored.
 * \return bool Returns true if the zero-overhead calculation request is successfully, false otherwise.
 *
 * \note The caller should ensure that the input and output buffers are properly allocated and formatted.
 */
bool TFU_valueCalculateZOForAPP(uint32_t *pInBuff, uint32_t *pOutBuff);

/*!
 * \brief Perform Calculation on TFU with Interrupt Support
 *
 * \details This function initiates a calculation on the TFU instance identified by \p tfuIdx, 
 * using the input buffer pointed to by \p pInBuff.
 * The number of calculations to be performed is denoted by \p NbCalc.
 * \param[in] tfuIdx The index of the TFU instance to perform the calculation on.
 * \param[in] threadnum The number of the thread within the TFU to utilize for the calculation.
 * \param[in] pInBuff A pointer to the input buffer containing data to be processed by the TFU.
 * \param[in] NbCalc The number of calculations to be performed by the TFU.
 * \return bool Returns true if the calculation request is successfully submitted to the TFU, false otherwise.
 *
 * \note The caller should ensure that the input buffer is correctly allocated and aligned according to the TFU's requirements.
 */
bool TFU_valueCalculate_IT(TFU_Index_t tfuIdx, uint32_t threadnum, uint32_t *pInBuff, uint32_t NbCalc);

/*!
 * \brief Perform Calculation on TFU with DMA Support
 *
 * \details This function initiates a calculation on the TFU instance specified by \p tfuIdx.
 * The input buffer (\p pInBuff) and output buffer are transferred via DMA, 
 * and the number of calculations to perform is specified by \p NbCalc.
 * The direction of DMA transfer is determined by \p DMADirection.
 * 
 * \param[in] tfuIdx The index of the TFU instance to perform the calculation on.
 * \param[in] threadnum The number of the thread within the TFU to use for the calculation.
 * \param[in] pInBuff A pointer to the input buffer containing data to be transferred to the TFU using DMA.
 * \param[out] pOutBuff A pointer to the output buffer where the results from the TFU will be stored via DMA.
 * \param[in] NbCalc The number of calculations to be performed by the TFU.
 * \param[in] DMADirection An enumerator value specifying the direction of DMA transfer (input/output/both).
 * \return bool Returns true if the calculation request is successfully, false otherwise.
 *
 * \note The caller should ensure that the input and output buffers are appropriately allocated and aligned.
 */
bool TFU_vauleCalculate_DMA(TFU_Index_t tfuIdx, uint32_t threadnum,  uint32_t *pInBuff, uint32_t *pOutBuff,
                                           uint32_t NbCalc, uint32_t DMADirection);

/*!
 * \brief Convert CORDIC 31-bit Integer Representation to Float Value
 *
 * \details  The CORDIC integer is passed through the \p CORDIC31 parameter, 
 * and the resulting float value is stored in the memory location pointed to by \p RES.
 * \param[in] CORDIC31 A 31-bit integer representing the result of a CORDIC calculation.
 * \param[out] RES A pointer to a floating-point variable where the converted CORDIC value will be stored.
 * 
 * \note This function assumes that the integer representation follows the encoding scheme.
 */
extern void CORDIC31_To_Value(int CORDIC31, float* RES);

/*!
 * \brief Define Convert CORDIC 31-bit Integer Representation to Float Value
 */
#define CORDIC31_TO_VALUE(__VAL__, __RES__) { \
    if ((__VAL__) >> 31) \
    {\
        (__VAL__) &= 0x7FFFFFFF; \
        (__RES__) =  ((float)(__VAL__) - 0x80000000) / 0x80000000;\
    }\
    else\
    {\
        (__RES__) =  (float)(__VAL__) / 0x80000000;\
    }\
}

/*!
 * \brief Convert CORDIC 15-bit Integer Representations to Float Values
 *
 * \details  The CORDIC integers for the real and imaginary parts are passed through the \p CORDIC15 parameter. 
 * The resulting float values are stored respectively in the memory locations pointed to by \p REA and \p REB.
 * 
 * \param[in] CORDIC15 A 15-bit integer representing the result of a CORDIC calculation.
 * \param[out] REA A pointer to a floating-point variable where the converted real part (or first value) will be stored.
 * \param[out] REB A pointer to a floating-point variable where the converted imaginary part (or second value) will be stored.
 * 
 * \note This function assumes that the integer representation follows the encoding scheme,
 * phase rotations, or vector manipulations. 
 */
void CORDIC15_To_Value(int CORDIC15, float *REA, float *REB);

/*!
 * \brief Convert Float Value to CORDIC 31-bit Integer Representation
 *
 * \details This external function converts a floating-point value to 31-bit integer representation.
 * 
 * \param[in] Value The floating-point value to be converted to a CORDIC 31-bit integer format.
 * \param[in] Coefficient A scaling factor used in the conversion process. 
 * 
 * \return int Returns a 31-bit integer representation of the original floating-point \p Value.
 * 
 * \note The conversion process involves multiplying the input \p Value by the \p Coefficient.
 * The \p Coefficient usually reflects the accuracy and scaling properties of the CORDIC implementation.
 */
int Value_To_CORDIC31(float Value, float Coefficient);

/*!
 * \brief Define Convert Float Value to CORDIC 31-bit Integer Representation
 */

#define VALUE_TO_CORDIC31(__VAL__) ((uint32_t)((__VAL__) * 0x80000000))

/*!
 * \brief Convert Two Float Values to CORDIC 15-bit Integer Representations
 *
 * \details This external function converts two floating-point values (\p ValueA and \p ValueB)
 * The conversion for each value is carried out using a common provided coefficient (\p Coefficient)
 * 
 * \param[in] ValueA The first floating-point value to be converted to a CORDIC 15-bit integer format.
 * \param[in] ValueB The second floating-point value to be converted to a CORDIC 15-bit integer format.
 * \param[in] Coefficient A scaling factor used in the conversion process for both values. 
 * \return int Returns a combined 30-bit integer representation (15-bits for \p ValueA concatenated with 15-bits for \p ValueB).
 * 
 * \note The conversion process involves multiplying each input value (\p ValueA and \p ValueB) by the \p Coefficient. 
 * The \p Coefficient usually reflects the accuracy and scaling properties of the CORDIC implementation.
 */
extern int Value_To_CORDIC15(float ValueA, float ValueB, float Coefficient);

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */ /* end of DRV_HTE_TFU */

#endif /* HTE_TFU_H */
