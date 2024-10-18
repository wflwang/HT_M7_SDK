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
#include "spi_norflash_config.h"

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
#define SPI_NORFLASH_PAGE_SIZE  (256U) /*!< 256 bytes*/
#define SPI_NORFLASH_START_ADDR (0)    /*!< norflash start addr*/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/* No Prototypes */

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! \brief Array of SPI tx buff */
uint8_t spiTxBuff[SPI_NORFLASH_PAGE_SIZE] = { 0 };

/*! \brief Array of SPI rx buff */
uint8_t spiRxBuff[SPI_NORFLASH_PAGE_SIZE] = { 0 };

/*******************************************************************************
 * Codes
 ******************************************************************************/
static void SPINOR_setIO(void)
{
#if (BOARD_USE_CPU1)
    GPIO_setPinConfig(SPIA_MOSI_MUX_CFG);
    GPIO_setPinConfig(SPIA_MISO_MUX_CFG);
    GPIO_setPinConfig(SPIA_CLK_MUX_CFG);

    GPIO_setQualificationMode(SPIA_MOSI_PIN, kGPIO_QUAL_ASYNC);
    GPIO_setQualificationMode(SPIA_MISO_PIN, kGPIO_QUAL_ASYNC);
    GPIO_setQualificationMode(SPIA_CLK_PIN, kGPIO_QUAL_ASYNC);

    GPIO_setPinConfig(SPIA_CS_AS_IO_MUX_CFG);
    GPIO_setDirectionMode(SPIA_CS_PIN, kGPIO_DIR_OUTPUT);
    GPIO_setPadConfig(SPIA_CS_PIN, kGPIO_PADCONFIG_PULLUP);
    GPIO_setQualificationMode(SPIA_CS_PIN, kGPIO_QUAL_ASYNC);

    GPIO_writePin(SPIA_CS_PIN, 1);
#endif

#if (BOARD_CONFIG_CPU2)
    GPIO_setPinConfig(SPIB_MOSI_MUX_CFG);
    GPIO_setPinConfig(SPIB_MISO_MUX_CFG);
    GPIO_setPinConfig(SPIB_CLK_MUX_CFG);

    GPIO_setQualificationMode(SPIB_MOSI_PIN, kGPIO_QUAL_ASYNC);
    GPIO_setQualificationMode(SPIB_MISO_PIN, kGPIO_QUAL_ASYNC);
    GPIO_setQualificationMode(SPIB_CLK_PIN, kGPIO_QUAL_ASYNC);

    GPIO_setPinConfig(SPIB_CS_AS_IO_MUX_CFG);
    GPIO_setDirectionMode(SPIB_CS_PIN, kGPIO_DIR_OUTPUT);
    GPIO_setPadConfig(SPIB_CS_PIN, kGPIO_PADCONFIG_STD);
    GPIO_setQualificationMode(SPIB_CS_PIN, kGPIO_QUAL_ASYNC);
    /* Assign SPIB STEN GPIO to CPU2 */
    GPIO_setMasterCore(SPIB_CS_PIN, kGPIO_CORE_CPU2);
#endif

#if (BOARD_USE_CPU2)
    GPIO_writePin(SPIB_CS_PIN, 1);
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
    uint32_t jedc_id, i;
    SPINOR_Handler_t *mySPINOR0;
    uint32_t          sectorAddress, length;

    BOARD_init();

    SPINOR_setIO();

    for (i = 0; i < SPI_NORFLASH_PAGE_SIZE; i++)
    {
        spiTxBuff[i] = i;
    }
#if (BOARD_USE_CPU1)
    mySPINOR0 = SPINOR_getHandle(SPI_BUSA);
    SPINOR_getDefaultHandler(mySPINOR0, SPIA_CS_PIN);
#endif /* (BOARD_USE_CPU1) */

#if (BOARD_USE_CPU2)
    mySPINOR0 = SPINOR_getHandle(SPI_BUSB);
    SPINOR_getDefaultHandler(mySPINOR0, SPIB_CS_PIN);
#endif /* (BOARD_USE_CPU2) */

    SPINOR_init(mySPINOR0);

    /* Read Norflash JDEDC ID */
    SPINOR_readJEDCId(mySPINOR0, &jedc_id);

    sectorAddress = SPI_NORFLASH_START_ADDR;
    length        = SPI_NORFLASH_PAGE_SIZE;

    SPINOR_eraseSector(mySPINOR0, sectorAddress);

    /* Write max 256 bytes */
    SPINOR_program(mySPINOR0, spiTxBuff, sectorAddress, length);
    SPINOR_read(mySPINOR0, spiRxBuff, sectorAddress, length);

    for (i = 0; i < SPI_NORFLASH_PAGE_SIZE; i++)
    {
        if (spiTxBuff[i] != spiRxBuff[i])
        {
            while (1)
                ;
        }
    }

    /* Infinite loop */
    while (1)
    {
    }
}
