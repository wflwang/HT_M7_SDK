/*
 * Copyright 2023 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file spi_ex2_master_spi_norflash.c
 * \brief SDK source file example
 * \version 1.0.0
 */
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "board.h"
#include "hte_gpio.h"
#include "hte_pinmux.h"
#include "hte_spi.h"
#include "hte_sysctrl.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#if (BOARD_USE_CPU1)
#define SPIA_MOSI_PIN           58                /*!< SPIA MOSI pin */
#define SPIA_MOSI_MUX_CFG       GPIO_58_SPIA_SIMO /*!< SPIA MOSI pin config */
#define SPIA_MOSI_AS_IO_MUX_CFG GPIO_58_GPIO58    /*!< SPIA MOSI pin as gpio config*/
#define SPIA_MISO_PIN           59                /*!< SPIA MISO pin */
#define SPIA_MISO_MUX_CFG       GPIO_59_SPIA_SOMI /*!< SPIA MISO pin */
#define SPIA_MISO_AS_IO_MUX_CFG GPIO_59_GPIO59    /*!< SPIA MISO pin config */
#define SPIA_CLK_PIN            60                /*!< SPIA CLK pin as gpio config*/
#define SPIA_CLK_MUX_CFG        GPIO_60_SPIA_CLK  /*!< SPIA CLK pin */
#define SPIA_CLK_AS_IO_MUX_CFG  GPIO_60_GPIO60    /*!< SPIA CLK pin config */
#define SPIA_CS_PIN             61                /*!< SPIA CS pin */
#define SPIA_CS_MUX_CFG         GPIO_61_SPIA_STEN /*!< SPIA CS pin config */
#define SPIA_CS_AS_IO_MUX_CFG   GPIO_61_GPIO61    /*!< SPIA CS pin as gpio config*/
#endif

#if (BOARD_CONFIG_CPU2 || BOARD_USE_CPU2)
#define SPIB_MOSI_PIN           63                /*!< SPIB MOSI pin */
#define SPIB_MOSI_MUX_CFG       GPIO_63_SPIB_SIMO /*!< SPIB MOSI pin config */
#define SPIB_MOSI_AS_IO_MUX_CFG GPIO_63_GPIO63    /*!< SPIB MOSI pin as gpio config*/
#define SPIB_MISO_PIN           64                /*!< SPIB MISO pin */
#define SPIB_MISO_MUX_CFG       GPIO_64_SPIB_SOMI /*!< SPIB MISO pin config */
#define SPIB_MISO_AS_IO_MUX_CFG GPIO_64_GPIO64    /*!< SPIB MISO pin as gpio config*/
#define SPIB_CLK_PIN            65                /*!< SPIB CLK pin */
#define SPIB_CLK_MUX_CFG        GPIO_65_SPIB_CLK  /*!< SPIB CLK pin config */
#define SPIB_CLK_AS_IO_MUX_CFG  GPIO_65_GPIO65    /*!< SPIB CLK pin as gpio config*/
#define SPIB_CS_PIN             66                /*!< SPIB CS pin */
#define SPIB_CS_MUX_CFG         GPIO_66_SPIB_STEN /*!< SPIB CS pin config */
#define SPIB_CS_AS_IO_MUX_CFG   GPIO_66_GPIO66    /*!< SPIB CS pin as gpio config*/
#endif

/*! \brief SPI NORFLASH page size */
#define SPI_NORFLASH_PAGE_SIZE (256U)    /*!< 256 bytes*/
#define SPI_TRANSMIT_TIMEOUT   (1000000) /*!< 1000000 count*/
#define SPI_DELAY_TIME_1S      (1000000) /*!< 1 s */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/* No Prototypes */

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! \brief Array of SPI tx buff */
uint8_t spiTxBuff[SPI_NORFLASH_PAGE_SIZE] = { 0 };

/*******************************************************************************
 * Codes
 ******************************************************************************/
static void SPI_setIO(void)
{
#if (BOARD_USE_CPU1)
    GPIO_setPinConfig(SPIA_MOSI_MUX_CFG);
    GPIO_setPinConfig(SPIA_MISO_MUX_CFG);
    GPIO_setPinConfig(SPIA_CLK_MUX_CFG);
    GPIO_setPinConfig(SPIA_CS_MUX_CFG);

    GPIO_setQualificationMode(SPIA_MOSI_PIN, kGPIO_QUAL_ASYNC);
    GPIO_setQualificationMode(SPIA_MISO_PIN, kGPIO_QUAL_ASYNC);
    GPIO_setQualificationMode(SPIA_CLK_PIN, kGPIO_QUAL_ASYNC);
    GPIO_setQualificationMode(SPIA_CS_PIN, kGPIO_QUAL_ASYNC);
#endif

#if (BOARD_CONFIG_CPU2)
    GPIO_setPinConfig(SPIB_MOSI_MUX_CFG);
    GPIO_setPinConfig(SPIB_MISO_MUX_CFG);
    GPIO_setPinConfig(SPIB_CLK_MUX_CFG);
    GPIO_setPinConfig(SPIB_CS_MUX_CFG);

    GPIO_setQualificationMode(SPIB_MOSI_PIN, kGPIO_QUAL_ASYNC);
    GPIO_setQualificationMode(SPIB_MISO_PIN, kGPIO_QUAL_ASYNC);
    GPIO_setQualificationMode(SPIB_CLK_PIN, kGPIO_QUAL_ASYNC);
    GPIO_setQualificationMode(SPIB_CS_PIN, kGPIO_QUAL_ASYNC);
#endif
}

void SPI_mspInit(SPI_HandleTypeDef_t *hspi)
{
#if (BOARD_USE_CPU1)
    /* Set SPIA to CPU1 */
    SYSCTRL_selectCPUForPeripheral((kSYSCTL_PERIPH_CPUSEL_SPIA), kSYSCTRL_CPUSEL_CPU1);

    /* Enable SPIA clock */
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_SPIA);
#endif

#if (BOARD_CONFIG_CPU2)
    /* Set SPIB to CPU2 */
    SYSCTRL_selectCPUForPeripheral((kSYSCTL_PERIPH_CPUSEL_SPIB), kSYSCTRL_CPUSEL_CPU2);
#endif

#if (BOARD_USE_CPU2)
    /* Enable SPIB clock */
    SYSCTRL_enablePeripheral(kSYSCTL_PERIPH_CLK_SPIB);
#endif
}

int main(void)
{
    uint32_t             i;
    SPI_HandleTypeDef_t *mySPI;
    status_t             status = kSTATUS_SUCCESS;

    BOARD_init();

    SPI_setIO();

    for (i = 0; i < SPI_NORFLASH_PAGE_SIZE; i++)
    {
        spiTxBuff[i] = i;
    }

#if (BOARD_USE_CPU1)
    mySPI                  = SPI_getHandle(SPI_BUSA);
    status                |= SPI_getDefaultCfg(mySPI);
    mySPI->instance        = SPI_getInstance(SPI_BUSA);
    mySPI->init.mode       = SPI_MODE_MASTER;
    mySPI->init.direction  = SPI_DIRECTION_TXONLY;
#endif /* (BOARD_USE_CPU1) */

#if (BOARD_USE_CPU2)
    mySPI                  = SPI_getHandle(SPI_BUSB);
    status                |= SPI_getDefaultCfg(mySPI);
    mySPI->instance        = SPI_getInstance(SPI_BUSB);
    mySPI->init.mode       = SPI_MODE_MASTER;
    mySPI->init.direction  = SPI_DIRECTION_TXONLY;
#endif /* (BOARD_USE_CPU2) */

    if (status != kSTATUS_SUCCESS)
    {
        /* Get Handle error */
        while (1)
        {
        };
    }

    status |= SPI_init(mySPI);

    if (status != kSTATUS_SUCCESS)
    {
        /* Init error */
        while (1)
        {
        };
    }

    /*  Transmit 256 Bytes */
    if (status != SPI_transmit(mySPI, spiTxBuff, SPI_NORFLASH_PAGE_SIZE, SPI_TRANSMIT_TIMEOUT))
    {
        /* Transmit error */
        while (1)
        {
        };
    }

    /* Infinite loop */
    while (1)
    {
        /* Delay 1s */
        DELAY(SPI_DELAY_TIME_1S);
    }
}
