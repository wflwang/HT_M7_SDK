/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*!
 * \file hello_world.c
 * \brief Example of SDK debug console
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdio.h>
#include "board.h"
#include "hte_ecap.h"
#include "hte_gpio.h"
#include "hte_pinmux.h"
#include "hte_sysctrl.h"
#include "hte_uart.h"
#if defined(BOARD_USE_CPU1) && BOARD_USE_CPU1
#include "hte_xbar.h"
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! \brief The number of samples in the array for tuning (higher for better average, lower for faster) */
#define EXAMPLE_SAMPLE_COUNT (32U)
/*!
 * \brief The MAX deviation of a sample value which can be considered as a "good" one
 * \note Set this higher to allow more samples to be considered "good" data, if losing too much data set this lower to
 * prevent "bad" samples to be discarded more strictly
 */
#define EXAMPLE_SAMPLE_DEVIATION (0.05f)
/*! \brief The MIN percentage of the sample values in the array which must be "good" for tuning */
#define EXAMPLE_SAMPLE_MIN_VALID_PERCENT (0.50f)

/*! \brief UART used by CPU1 in this example */
#define EXAMPLE_UART_CPU1 (UARTA)
/*! \brief UART TXD GPIO pin used by CPU1 in this example */
#define EXAMPLE_UART_TXD_GPIO_CPU1 (84U)
/*! \brief UART TXD pinmux used by CPU1 in this example */
#define EXAMPLE_UART_TXD_PINMUX_CPU1 (GPIO_84_UARTA_TXD)
/*! \brief UART RXD GPIO pin used by CPU1 in this example */
#define EXAMPLE_UART_RXD_GPIO_CPU1 (85U)
/*! \brief UART RXD pinmux used by CPU1 in this example */
#define EXAMPLE_UART_RXD_PINMUX_CPU1 (GPIO_85_GPIO85)

/*! \brief ECAP used by CPU1 in this example */
#define EXAMPLE_ECAP_CPU1 (ECAP1)
/*! \brief ECAP interrupt number used by CPU1 in this example */
#define EXAMPLE_ECAP_IRQ_CPU1 (ECAP1_IRQn)
/*! \brief ECAP interrupt handler used by CPU1 in this example */
#define EXAMPLE_ECAP_IRQHandler_CPU1 (ECAP1_Handler)
/*! \brief ECAP input used by CPU1 in this example */
#define EXAMPLE_ECAP_INPUT_CPU1 (kECAP_INPUT_INPUTXBAR1)

/*! \brief INPUT-XBAR used by CPU1 in this example */
#define EXAMPLE_INPUT_XBAR_CPU1 (kXBAR_INPUT1)

/*! \brief UART used by CPU2 in this example */
#define EXAMPLE_UART_CPU2 (UARTB)
/*! \brief UART TXD GPIO pin used by CPU2 in this example */
#define EXAMPLE_UART_TXD_GPIO_CPU2 (86U)
/*! \brief UART TXD pinmux used by CPU2 in this example */
#define EXAMPLE_UART_TXD_PINMUX_CPU2 (GPIO_86_UARTB_TXD)
/*! \brief UART RXD GPIO pin used by CPU2 in this example */
#define EXAMPLE_UART_RXD_GPIO_CPU2 (87U)
/*! \brief UART RXD pinmux used by CPU2 in this example */
#define EXAMPLE_UART_RXD_PINMUX_CPU2 (GPIO_87_GPIO87)

/*! \brief ECAP used by CPU2 in this example */
#define EXAMPLE_ECAP_CPU2 (ECAP2)
/*! \brief ECAP interrupt number used by CPU2 in this example */
#define EXAMPLE_ECAP_IRQ_CPU2 (ECAP2_IRQn)
/*! \brief ECAP interrupt handler used by CPU2 in this example */
#define EXAMPLE_ECAP_IRQHandler_CPU2 (ECAP2_Handler)
/*! \brief ECAP input used by CPU2 in this example */
#define EXAMPLE_ECAP_INPUT_CPU2 (kECAP_INPUT_INPUTXBAR2)

/*! \brief INPUT-XBAR used by CPU2 in this example */
#define EXAMPLE_INPUT_XBAR_CPU2 (kXBAR_INPUT2)

#if defined(BOARD_USE_CPU1)
/*! \brief UART used in this example */
#define EXAMPLE_UART (EXAMPLE_UART_CPU1)
/*! \brief ECAP used in this example */
#define EXAMPLE_ECAP (EXAMPLE_ECAP_CPU1)
/*! \brief ECAP interrupt number used in this example */
#define EXAMPLE_ECAP_IRQ (EXAMPLE_ECAP_IRQ_CPU1)
/*! \brief ECAP interrupt handler used in this example */
#define EXAMPLE_ECAP_IRQHandler (EXAMPLE_ECAP_IRQHandler_CPU1)
/*! \brief ECAP input used in this example */
#define EXAMPLE_ECAP_INPUT (EXAMPLE_ECAP_INPUT_CPU1)
#elif defined(BOARD_USE_CPU2)
/*! \brief UART used in this example */
#define EXAMPLE_UART            (EXAMPLE_UART_CPU2)
/*! \brief ECAP used in this example */
#define EXAMPLE_ECAP            (EXAMPLE_ECAP_CPU2)
/*! \brief ECAP interrupt number used in this example */
#define EXAMPLE_ECAP_IRQ        (EXAMPLE_ECAP_IRQ_CPU2)
/*! \brief ECAP interrupt handler used in this example */
#define EXAMPLE_ECAP_IRQHandler (EXAMPLE_ECAP_IRQHandler_CPU2)
/*! \brief ECAP input used in this example */
#define EXAMPLE_ECAP_INPUT      (EXAMPLE_ECAP_INPUT_CPU2)
#endif
/*! \brief ECAP clock used in this example */
#define EXAMPLE_ECAP_CLOCK (BOARD_getSysclk())

/*! \brief UART baudrate used in this example */
#define EXAMPLE_UART_BAUDRATE (115200U)
/*! \brief Clock of the UART used in this example */
#define EXAMPLE_UART_CLOCK BOARD_DEBUG_CONSOLE_CLOCK

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*! \brief Setup ECAP to start the baudrate tuning process */
void UART_setupBaudRateTuning(void);

/*! \brief Rearm ECAP to restart the baudrate tuning process */
void UART_restartBaudRateTuning(void);

/*! \brief ECAP interrupt handler */
void EXAMPLE_ECAP_IRQHandler(void);

/*!
 * \brief Get the average baudrate of the tuning process
 *
 * \param[in] sampleArray The array of the sample values to calculate the baudrate
 * \param[in] size The array entry count
 * \param[in] targetBaudRate The target baudrate
 * \param[out] baudRate The calculated average baudrate
 *
 * \retval kSTATUS_SUCCESS The average baudrate is calculated successfully
 * \retval kSTATUS_FAIL Failed to get the average baudrate
 */
status_t UART_getAverageBaudRate(volatile float *sampleArray, size_t size, uint32_t targetBaudRate, uint32_t *baudRate);

/*!
 * \brief Convert the sample value from multiple bit width to single bit width

 * \param[in] sampleArray The array of the sample values to calculate the baudrate
 * \param[in] size The array entry count
 * \param[in] targetBitWidth The bit width value at the target baudrate
 *
 * \retval kSTATUS_SUCCESS The operation is completed successfully
 * \retval kSTATUS_FAIL The operation is failed
 */
status_t UART_convertToBitWidth(volatile float *sampleArray, size_t size, float targetBitWidth);

/*!
 * \brief Convert the sample value from multiple bit width to single bit width

 * \param[in] sampleArray The array of the sample values to calculate the baudrate
 * \param[in] size The array entry count
 *
 * \return The calculated average bit width
 */
float UART_calculateAverageBitWidth(volatile float *sampleArray, size_t size);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! \brief UART example banner string */
const uint8_t s_uartExampleString[] =
    "\r\n"
    "UART Baudrate Tuning Example:\r\n"
    "\tHost needs to send 32 bytes at baudrate 115200, and Device will send the tuned baudrate back\r\n"
    "Please input:";
/*! \brief UART tuning rerun string */
const uint8_t s_uartRerunString[] = "\r\nRestart the tuning, please input:";
/*! \brief UART tuning failure string */
const uint8_t s_uartFailureString[] = "\r\nTuning is failed, try again, please input:";
/*! \brief UART tuning sample value array */
volatile float s_sampleArray[EXAMPLE_SAMPLE_COUNT];
/*! \brief Current UART tuning sample count */
volatile size_t s_sampleArrayCount = 0;
/*! \brief Flag to indicate if there is enough samples captured */
volatile bool s_stopCaptures = false;

/*******************************************************************************
 * Codes
 ******************************************************************************/
int main(void)
{
    /* Board initialization */
    /*
     * Note: In BOARD_init(), UARTA and UARTB is initialized for debug_console for CPU1 and CPU2.
     *       If the example uses the same UART, UART will be re-initialized in this example.
     */
    BOARD_init();

    /* Pinmux configuration and Pad configuration */
#if defined(BOARD_USE_CPU1)
    GPIO_setPinConfig(EXAMPLE_UART_TXD_PINMUX_CPU1);
    GPIO_setPadConfig(EXAMPLE_UART_TXD_GPIO_CPU1, kGPIO_PADCONFIG_PULLUP);
    GPIO_setPinConfig(EXAMPLE_UART_RXD_PINMUX_CPU1);
    GPIO_setPadConfig(EXAMPLE_UART_RXD_GPIO_CPU1, kGPIO_PADCONFIG_STD);
    GPIO_setDirectionMode(EXAMPLE_UART_RXD_GPIO_CPU1, kGPIO_DIR_INPUT);
    XBAR_setInputPin(INPUT_XBAR, EXAMPLE_INPUT_XBAR_CPU1, EXAMPLE_UART_RXD_GPIO_CPU1);

#endif
#if defined(BOARD_CONFIG_CPU2)
    GPIO_setPinConfig(EXAMPLE_UART_TXD_PINMUX_CPU2);
    GPIO_setPadConfig(EXAMPLE_UART_TXD_GPIO_CPU2, kGPIO_PADCONFIG_PULLUP);
    GPIO_setPinConfig(EXAMPLE_UART_RXD_PINMUX_CPU2);
    GPIO_setPadConfig(EXAMPLE_UART_RXD_GPIO_CPU2, kGPIO_PADCONFIG_STD);
    GPIO_setDirectionMode(EXAMPLE_UART_RXD_GPIO_CPU2, kGPIO_DIR_INPUT);
    XBAR_setInputPin(INPUT_XBAR, EXAMPLE_INPUT_XBAR_CPU2, EXAMPLE_UART_RXD_GPIO_CPU2);

    BOARD_uartAssign2CPU2(EXAMPLE_UART_CPU2);
    BOARD_ecapAssign2CPU2(EXAMPLE_ECAP_CPU2);
#endif

    /* Peripheral clock configuration */
    BOARD_uartClockEnable(EXAMPLE_UART);
    BOARD_ecapClockEnable(EXAMPLE_ECAP);

    UART_Config_t config;
    UART_getDefaultConfig(&config);
    config.baudRate = EXAMPLE_UART_BAUDRATE;

    (void)UART_init(EXAMPLE_UART, &config, EXAMPLE_UART_CLOCK);

    /* Setup the baudrate tuning */
    UART_setupBaudRateTuning();

    /* Send the example banner */
    (void)UART_writeDataBlocking(EXAMPLE_UART, s_uartExampleString, sizeof(s_uartExampleString));

    while (1)
    {
        if (s_stopCaptures)
        {
            uint32_t baudRate;
            status_t status =
                UART_getAverageBaudRate(s_sampleArray, ARRAY_SIZE(s_sampleArray), EXAMPLE_UART_BAUDRATE, &baudRate);
            if (status == kSTATUS_SUCCESS)
            {
                /* Clean the dummy bytes, before update the baudrate which requires that the UART is at idle state */
                while (UART_getUartStatus(EXAMPLE_UART) & UART_USR_RFNE_Msk)
                {
                    (void)EXAMPLE_UART->RBR;
                }

                status = UART_setBaudRate(EXAMPLE_UART, EXAMPLE_UART_CLOCK, baudRate);
                assert(status == kSTATUS_SUCCESS);

                /* Send the result*/
                char uartResultString[128];
                sprintf(uartResultString, "\r\nUART Baudrate Tuning is completed\r\n\tThe tuned baudrate is %ld",
                        baudRate);
                UART_writeDataBlocking(EXAMPLE_UART, (uint8_t *)uartResultString, strlen(uartResultString));

#if 0
                /* End of the example */
                while(1)
                {
                    ;
                }
#else
                UART_writeDataBlocking(EXAMPLE_UART, s_uartRerunString, sizeof(s_uartRerunString));
                /* Restart the baudrate tuning */
                UART_restartBaudRateTuning();
#endif
            }
            else
            {
                UART_writeDataBlocking(EXAMPLE_UART, s_uartFailureString, sizeof(s_uartFailureString));
                /* Restart the baudrate tuning */
                UART_restartBaudRateTuning();
            }
        }
    }
}

void UART_setupBaudRateTuning(void)
{
    /* Initialize the variables */
    memset((void *)s_sampleArray, 0, sizeof(s_sampleArray));
    s_sampleArrayCount = 0;
    s_stopCaptures     = false;

    /* Disable all capture interrupts and clear relative flags */
    ECAP_disableInterrupt(EXAMPLE_ECAP, (ECAP_ISR_SOURCE_CAPTURE_EVENT_1 | ECAP_ISR_SOURCE_CAPTURE_EVENT_2 |
                                         ECAP_ISR_SOURCE_CAPTURE_EVENT_3 | ECAP_ISR_SOURCE_CAPTURE_EVENT_4 |
                                         ECAP_ISR_SOURCE_COUNTER_OVERFLOW | ECAP_ISR_SOURCE_COUNTER_PERIOD |
                                         ECAP_ISR_SOURCE_COUNTER_COMPARE));
    ECAP_clearInterrupt(EXAMPLE_ECAP, (ECAP_ISR_SOURCE_CAPTURE_EVENT_1 | ECAP_ISR_SOURCE_CAPTURE_EVENT_2 |
                                       ECAP_ISR_SOURCE_CAPTURE_EVENT_3 | ECAP_ISR_SOURCE_CAPTURE_EVENT_4 |
                                       ECAP_ISR_SOURCE_COUNTER_OVERFLOW | ECAP_ISR_SOURCE_COUNTER_PERIOD |
                                       ECAP_ISR_SOURCE_COUNTER_COMPARE));

    /* Disable CAP1-CAP4 register loads on capture events */
    ECAP_disableTimeStampCapture(EXAMPLE_ECAP);
    /* Stop the counter during the eCAP configuration */
    ECAP_stopCounter(EXAMPLE_ECAP);

    /* Enable capture mode */
    ECAP_enableCaptureMode(EXAMPLE_ECAP);
    /* One-shot mode, stop capture at event 4 */
    ECAP_setCaptureMode(EXAMPLE_ECAP, kECAP_ONE_SHOT_CAPTURE_MODE, kECAP_EVENT_4);
    /* Set polarity of the events to rising, falling, rising, falling edge */
    ECAP_setEventPolarity(EXAMPLE_ECAP, kECAP_EVENT_1, kECAP_EVNT_FALLING_EDGE);
    ECAP_setEventPolarity(EXAMPLE_ECAP, kECAP_EVENT_2, kECAP_EVNT_RISING_EDGE);
    ECAP_setEventPolarity(EXAMPLE_ECAP, kECAP_EVENT_3, kECAP_EVNT_FALLING_EDGE);
    ECAP_setEventPolarity(EXAMPLE_ECAP, kECAP_EVENT_4, kECAP_EVNT_RISING_EDGE);
    /* Set capture in time difference mode */
    ECAP_enableCounterResetOnEvent(EXAMPLE_ECAP, kECAP_EVENT_1);
    ECAP_enableCounterResetOnEvent(EXAMPLE_ECAP, kECAP_EVENT_2);
    ECAP_enableCounterResetOnEvent(EXAMPLE_ECAP, kECAP_EVENT_3);
    ECAP_enableCounterResetOnEvent(EXAMPLE_ECAP, kECAP_EVENT_4);
    /* Select input from the input XBAR */
    ECAP_selectECAPInput(EXAMPLE_ECAP, EXAMPLE_ECAP_INPUT);
    /* Enable the sync in signal */
    ECAP_enableLoadCounter(EXAMPLE_ECAP);
    /* Disable the sync out signal */
    ECAP_setSyncOutMode(EXAMPLE_ECAP, kECAP_SYNC_OUT_DISABLED);

    /* Start the counter */
    ECAP_startCounter(EXAMPLE_ECAP);
    /* Enable CAP1-CAP4 register loads on capture events */
    ECAP_enableTimeStampCapture(EXAMPLE_ECAP);

    /* Start the capture  */
    ECAP_reArm(EXAMPLE_ECAP);
    /* Enable interrupt at the event 4 */
    ECAP_enableInterrupt(EXAMPLE_ECAP, ECAP_ISR_SOURCE_CAPTURE_EVENT_4);
    NVIC_EnableIRQ(EXAMPLE_ECAP_IRQ);
}

void UART_restartBaudRateTuning(void)
{
    /* Clean the variables */
    memset((void *)s_sampleArray, 0, sizeof(s_sampleArray));
    s_sampleArrayCount = 0;
    s_stopCaptures     = false;

    /* Restart eCAP */
    ECAP_reArm(EXAMPLE_ECAP);
}

void EXAMPLE_ECAP_IRQHandler(void)
{
    uint32_t capCountArray[4];
    /*
     * Get the capture counts, at the event 4.
     * Each value can be one-bit or mutiple-bit wide.
     * Add one to account for partial eCAP counts at higher baud rates (for example: count = 40, but if had higher
     * resolution, this would be 40.5)
     */
    capCountArray[0] = 1U + ECAP_getEventTimeStamp(EXAMPLE_ECAP, kECAP_EVENT_1);
    capCountArray[1] = 1U + ECAP_getEventTimeStamp(EXAMPLE_ECAP, kECAP_EVENT_2);
    capCountArray[2] = 1U + ECAP_getEventTimeStamp(EXAMPLE_ECAP, kECAP_EVENT_3);
    capCountArray[3] = 1U + ECAP_getEventTimeStamp(EXAMPLE_ECAP, kECAP_EVENT_4);

    /* Add samples to a buffer which is used to get average baudrate */
    for (uint32_t i = 0; i < 4; i++)
    {
        /* If we still have samples left to capture, add it to the samples array */
        if (s_sampleArrayCount < sizeof(s_sampleArray))
        {
            s_sampleArray[s_sampleArrayCount] = capCountArray[i];
            s_sampleArrayCount++;
            s_stopCaptures = false;
        }
        /* else, all samples were received, break to begin tuning */
        else
        {
            s_stopCaptures = true;
            break;
        }
    }

    /* Clear interrupt flags for more interrupts */
    ECAP_clearInterrupt(EXAMPLE_ECAP, ECAP_ISR_SOURCE_CAPTURE_EVENT_4);
    ECAP_clearGlobalInterrupt(EXAMPLE_ECAP);

    /* Restart eCAP if more samples need to be captured */
    if (!s_stopCaptures)
    {
        ECAP_reArm(EXAMPLE_ECAP);
    }
}

status_t UART_getAverageBaudRate(volatile float *sampleArray, size_t size, uint32_t targetBaudRate, uint32_t *baudRate)
{
    /* Set multiple-bit-width values in the array to single-bit-width value by dividing */
    float    targetBitWidth = (float)EXAMPLE_ECAP_CLOCK / targetBaudRate;
    status_t status         = UART_convertToBitWidth(sampleArray, size, targetBitWidth);
    if (status != kSTATUS_SUCCESS)
    {
        /* There are not enough good samples captured, the average baudrate cannot be calculated */
        return status;
    }

    /* Average the samples */
    float averageBitWidth = UART_calculateAverageBitWidth(sampleArray, size);

    /* Calculate and return the rounded baudrate with the average number of clocks and the eCAP frequency */
    *baudRate = (uint32_t)(((float)EXAMPLE_ECAP_CLOCK / averageBitWidth) + 0.5f);

    return kSTATUS_SUCCESS;
}

status_t UART_convertToBitWidth(volatile float *sampleArray, size_t size, float targetBitWidth)
{
    size_t goodSampleCount = 0;
    for (size_t i = 0; i < size; i++)
    {
        /* Check if the sample value is less than 10 times of the bit width, otherwise treat it as an invalid sample */
        if (sampleArray[i] < (targetBitWidth * 10U))
        {
            /* If the item is over +EXAMPLE_SAMPLE_DEVIATION% of the targetWidth, then it might be a multiple-bit sample
             * value */
            if (sampleArray[i] > (targetBitWidth * (1.0f + EXAMPLE_SAMPLE_DEVIATION)))
            {
                /* Estimate the bit width */
                size_t numBitWidths = (size_t)((sampleArray[i] / targetBitWidth) + 0.5f);

                /* Divide the multi-bit-width value by the estimated bit width to make a single-bit-width value */
                sampleArray[i] = sampleArray[i] / numBitWidths;

                /* Check if this new value is within the margin */
                if ((sampleArray[i] < targetBitWidth * (1.0 - EXAMPLE_SAMPLE_DEVIATION)) ||
                    (sampleArray[i] > targetBitWidth * (1.0 + EXAMPLE_SAMPLE_DEVIATION)))
                {
                    /* Discard if not within the margins*/
                    sampleArray[i] = 0;
                }
                else
                {
                    /* Good sample value, increase the counter */
                    goodSampleCount++;
                }
            }
            /* If the item is lower -EXAMPLE_SAMPLE_DEVIATION% of the targetWidth, then it is not a good sample value,
             * discard it */
            else if (sampleArray[i] < (targetBitWidth * (1.0f - EXAMPLE_SAMPLE_DEVIATION)))
            {
                sampleArray[i] = 0;
            }
            else
            {
                /* This is a one-bit-width sample value, increase the counter */
                goodSampleCount++;
            }
        }
        else
        {
            /* Invalid sample value, discard it */
            sampleArray[i] = 0;
        }
    }

    /* Check if at least EXAMPLE_SAMPLE_MIN_VALID_PERCENT% of the sampled values are "good" samples */
    if (((float)goodSampleCount / (float)size) >= EXAMPLE_SAMPLE_MIN_VALID_PERCENT)
    {
        return kSTATUS_SUCCESS;
    }
    /* The array had not enough good samples, return failure */
    return kSTATUS_FAIL;
}

float UART_calculateAverageBitWidth(volatile float *sampleArray, size_t size)
{
    size_t count = 0;
    float  total = 0;
    for (size_t i = 0; i < size; i++)
    {
        /* if the item has not been removed, use it to calculate the average */
        if (sampleArray[i] != 0)
        {
            count++;
            total += sampleArray[i];
        }
    }

    /* Return the average */
    return (total / count);
}
