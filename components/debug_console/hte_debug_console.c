/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_debug_console.c
 * \brief SDK Debug Console driver source file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hte_debug_console.h"

#if defined(HTE_FEATURE_UART_COUNT) && (HTE_FEATURE_UART_COUNT > 0)
#include "hte_uart.h"
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! \brief Debug console HAL function for deinitialization */
typedef status_t (*DEBUG_CONSOLE_HAL_deinit_t)(uint32_t base);
/*! \brief Debug console HAL function for transmitting data */
typedef status_t (*DEBUG_CONSOLE_HAL_transmit_t)(uint32_t bsse, const uint8_t *data, size_t length);
/*! \brief Debug console HAL function for receiving */
typedef status_t (*DEBUG_CONSOLE_HAL_receive_t)(uint32_t base, uint8_t *data, size_t length);
/*! \brief Debug console HAL function for testing received data */
typedef bool (*DEBUG_CONSOLE_HAL_testReceive_t)(uint32_t base);

/*! \brief Debug console context definition */
typedef struct
{
    uint32_t                        base;        /*!< The base address of the module used as debug console */
    DEBUG_CONSOLE_HAL_deinit_t      deinit;      /*!< Debug console HAL function for deinitialization */
    DEBUG_CONSOLE_HAL_transmit_t    transmit;    /*!< Debug console HAL function for transmitting data */
    DEBUG_CONSOLE_HAL_receive_t     receive;     /*!< Debug console HAL function for initialization */
    DEBUG_CONSOLE_HAL_testReceive_t testReceive; /*!< Debug console HAL function for testing received data */
} DEBUG_CONSOLE_Context_t;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * \brief HAL function for UART initialization
 *
 * \param[in] base The base address of the UART
 * \param[in] baudRate The baud rate of the UART
 * \param[in] periphClock The peripheral clock of the UART
 *
 * \return The status of the operation
 *         - kStatus_Success Success
 *         - Others          Failure
 */
static inline status_t DEBUG_CONSOLE_HAL_uartInit(uint32_t base, uint32_t baudRate, uint32_t periphClock);

/*!
 * \brief HAL function for UART deinitialization
 *
 * \param[in] base The base address of the UART
 *
 * \return The status of the operation
 *         - kStatus_Success Success
 *         - Others          Failure
 */
static inline status_t DEBUG_CONSOLE_HAL_uartDeinit(uint32_t base);

/*!
 * \brief HAL function for UART data transmit
 *
 * \param[in] base The base address of the UART
 * \param[in] data The pointer to the data bytes
 * \param[in] length The byte count of the data to transfer
 *
 * \return The status of the operation
 *         - kStatus_Success Success
 *         - Others          Failure
 */
static status_t DEBUG_CONSOLE_HAL_uartTransmit(uint32_t base, const uint8_t *data, size_t length);

/*!
 * \brief HAL function for UART data receive
 *
 * \param[in] base The base address of the UART
 * \param[in] data The pointer to the data bytes
 * \param[in] length The byte count of the data to receive
 *
 * \return The status of the operation
 *         - kStatus_Success Success
 *         - Others          Failure
 */
static status_t DEBUG_CONSOLE_HAL_uartReceive(uint32_t base, uint8_t *data, size_t length);

/*!
 * \brief HAL function for UART received data test
 *
 * \param[in] base The base address of the UART
 *
 * \return The status of the received data
           - True: One character at least in the input stream
           - False: No character available in the input stream
 */
static bool DEBUG_CONSOLE_HAL_uartTestReceive(uint32_t base);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! \brief Debug Console context */
static DEBUG_CONSOLE_Context_t s_debugConsole = { 0U };

/*******************************************************************************
 * Codes
 ******************************************************************************/
status_t DEBUG_CONSOLE_init(DEBUG_CONSOLE_Config_t *config)
{
    /* Dot not use assert() here, which requires debug console */
    /* assert(config); */

    status_t status;

    /* Check the input argument */
    if (config == NULL)
    {
        return kSTATUS_INVALID_ARGUMENT;
    }

    if (config->type == kDEBUG_CONSOLE_TYPE_UART)
    {
        status = DEBUG_CONSOLE_HAL_uartInit(config->base, config->baudRate, config->periphClock);
        if (status != kSTATUS_SUCCESS)
        {
            return status;
        }

        /* Debug console context initialization */
        s_debugConsole.base        = config->base;
        s_debugConsole.deinit      = DEBUG_CONSOLE_HAL_uartDeinit;
        s_debugConsole.transmit    = DEBUG_CONSOLE_HAL_uartTransmit;
        s_debugConsole.receive     = DEBUG_CONSOLE_HAL_uartReceive;
        s_debugConsole.testReceive = DEBUG_CONSOLE_HAL_uartTestReceive;

        status = kSTATUS_SUCCESS;
    }
    else
    {
        /* Not supported debug console type */
        status = kSTATUS_NOT_SUPPORTED;
    }

#if DEBUG_CONSOLE == DEBUG_CONSOLE_TOOLCHAIN
#if defined(__GNUC__)
    if (status == kSTATUS_SUCCESS)
    {
        /* Disable the buffers to have a better debugging experience */
        setvbuf(stdin, NULL, _IONBF, 0);
        setvbuf(stdout, NULL, _IONBF, 0);
        setvbuf(stderr, NULL, _IONBF, 0);
    }
#endif /* defined(__GNUC__) */
#endif /* DEBUG_CONSOLE == DEBUG_CONSOLE_TOOLCHAIN */

    return status;
}

status_t DEBUG_CONSOLE_deinit(void)
{
    if (s_debugConsole.base == 0U)
    {
        return kSTATUS_FAIL;
    }

    return s_debugConsole.deinit(s_debugConsole.base);
}

int DEBUG_CONSOLE_printf(const char *format, ...)
{
    if (s_debugConsole.base == 0U)
    {
        return -1;
    }

    /* Not completed */

    return 0;
}

int DEBUG_CONSOLE_scanf(const char *format, ...)
{
    if (s_debugConsole.base == 0U)
    {
        return -1;
    }

    /* Not completed */

    return 0;
}

int DEBUG_CONSOLE_putchar(int ch)
{
    if (s_debugConsole.base == 0U)
    {
        return -1;
    }

    /* Not completed */

    return 0;
}

int DEBUG_CONSOLE_getchar(void)
{
    if (s_debugConsole.base == 0U)
    {
        return -1;
    }

    /* Not completed */

    return 0;
}

bool DEBUG_CONSOLE_tstchar(void)
{
    if (s_debugConsole.base == 0U)
    {
        return false;
    }

    return s_debugConsole.testReceive(s_debugConsole.base);
}

#if DEBUG_CONSOLE == DEBUG_CONSOLE_TOOLCHAIN
#if defined(__CC_ARM) || defined(__ARMCC_VERSION)
#if defined(__CC_ARM)
/*! \brief SDK redefinition of FILE */
struct __FILE
{
    int handle;
    /* Whatever you require here. If the only file you are using is standard output using printf() for debugging, no
     * file handling is required. */
};
#endif /* defined(__CC_ARM) */

/*! \brief SDK redefinition of STDIN */
#pragma weak __stdin
FILE __stdin;
/*! \brief SDK redefinition of STDOUT */
#pragma weak __stdout
FILE __stdout;

/*! \brief SDK redefinition of fgetc */
#pragma weak fgetc
int fgetc(FILE *f)
{
    if (s_debugConsole.base == 0U)
    {
        return -1;
    }

    (void)f;
    char ch = 0;
    (void)s_debugConsole.receive(s_debugConsole.base, (uint8_t *)&ch, 1);
    return (int)ch;
}

/*! \brief SDK redefinition of fputc */
#pragma weak fputc
int fputc(int ch, FILE *f)
{
    if (s_debugConsole.base == 0U)
    {
        return -1;
    }

    (void)f;
    char tempCh = (char)ch;
    (void)s_debugConsole.transmit(s_debugConsole.base, (uint8_t *)&tempCh, 1);
    return ch;
}

#elif defined(__ICCARM__)
#pragma weak __read
size_t __read(int handle, unsigned char *buffer, size_t size)
{
    if (s_debugConsole.base == 0U)
    {
        return (size_t)-1;
    }

    if (buffer == NULL)
    {
        return (size_t)-1;
    }

    /* Only support reading from stdin, return failure for all other handles */
    if (0 != handle)
    {
        return (size_t)-1;
    }

    /* Receive data.*/
    (void)s_debugConsole.receive(s_debugConsole.base, (uint8_t *)buffer, size);

    return size;
}

#pragma weak __write
size_t __write(int handle, const unsigned char *buffer, size_t size)
{
    if (s_debugConsole.base == 0U)
    {
        return (size_t)-1;
    }

    if (buffer == NULL)
    {
        return (size_t)-1;
    }

    /* Don't supported to flush all handles(handle = -1) */
    if (handle == -1)
    {
        return (size_t)0;
    }
    /* Only support writting to stdout and stderr, return failure for all other handles */
    if (handle != 1 /* stdout */ && handle != 2 /* stderr*/)
    {
        return (size_t)-1;
    }

    /* Send data.*/
    (void)s_debugConsole.transmit(s_debugConsole.base, (uint8_t *)buffer, size);

    return size;
}

#elif defined(__GNUC__)
int __attribute__((weak)) _read(int fd, char *ptr, int len)
{
    if (s_debugConsole.base == 0U)
    {
        return -1;
    }

    if (ptr == NULL)
    {
        return -1;
    }

    (void)s_debugConsole.receive(s_debugConsole.base, (uint8_t *)ptr, len);

    return len;
}

int __attribute__((weak)) _write(int fd, char *ptr, int len)
{
    if (s_debugConsole.base == 0U)
    {
        return -1;
    }

    if (ptr == NULL)
    {
        return -1;
    }

    (void)s_debugConsole.transmit(s_debugConsole.base, (uint8_t *)ptr, len);

    return len;
}

#else
#error Unknown toolchain
#endif /* defined(__CC_ARM) || defined(__ARMCC_VERSION) */
#endif /* DEBUG_CONSOLE == DEBUG_CONSOLE_TOOLCHAIN */

static inline status_t DEBUG_CONSOLE_HAL_uartInit(uint32_t base, uint32_t baudRate, uint32_t periphClock)
{
    UART_Config_t uartConfig = { 0 };
    UART_getDefaultConfig(&uartConfig);
    uartConfig.baudRate = baudRate;
    /* 8bit data length, no polarity, 1bit stop */
    uartConfig.dataLength = kUART_DATA_LENGTH_8BITS;
    uartConfig.parityType = kUART_PARITY_NONE;
    uartConfig.stopBit    = kUART_STOP_BIT_1;

    return UART_init((UART_Type *)base, &uartConfig, periphClock);
}

static inline status_t DEBUG_CONSOLE_HAL_uartDeinit(uint32_t base)
{
    return UART_deinit((UART_Type *)base);
}

static status_t DEBUG_CONSOLE_HAL_uartTransmit(uint32_t base, const uint8_t *data, size_t length)
{
    return UART_writeDataBlocking((UART_Type *)base, data, length);
}

static status_t DEBUG_CONSOLE_HAL_uartReceive(uint32_t base, uint8_t *data, size_t length)
{
    return UART_readDataBlocking((UART_Type *)base, data, length);
}

static bool DEBUG_CONSOLE_HAL_uartTestReceive(uint32_t base)
{
    return UART_isDataAvailable((UART_Type *)base);
}
