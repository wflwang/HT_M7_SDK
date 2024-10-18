/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_i2c.h
 * \brief SDK I2C driver header file
 * \version 1.0.0
 */

#ifndef HTE_I2C_H
#define HTE_I2C_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "clock_config.h"
#include "hte_common.h"

/*!
 * \addtogroup DRV_HTE_I2C I2C Driver
 *
 * \brief SDK I2C driver
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! \brief EEPROM write delays due to the internal write cycle */
#define EEPROM_WRITE_TIME 20000

/*! \brief The maximum timeout value of a I2C transfer */
#define I2C_MAX_DELAY     0xFFFFFFFF

#define I2C_STANDARD_HCNT  0x2E3 /*!< Standard mode I2C clock SCL high count value */
#define I2C_STANDARD_LCNT  0x2E4 /*!< Standard mode I2C clock SCL low count value */
#define I2C_FAST_HCNT      0x8B  /*!< Fast mode I2C clock SCL high count value */
#define I2C_FAST_LCNT      0xD7  /*!< Fast mode I2C clock SCL low count value */
#define I2C_FAST_PLUS_HCNT 0x40  /*!< Fast mode plus I2C clock SCL high count value */
#define I2C_FAST_PLUS_LCNT 0x41  /*!< Fast mode plus I2C clock SCL low count value */


/*! \brief Check whether the specified I2C flag is set or not */
#define I2C_GET_FLAG(__HANDLE__, __FLAG__) \
    (((((__HANDLE__)->instance->IC_RAW_INTR_STAT) & (__FLAG__)) == (__FLAG__)) ? 1 : 0)

/*! \brief I2C index */
typedef enum
{
    kI2C_INDEX_A = 0x0U, /*!< The index of I2CA */
    kI2C_INDEX_B = 0x1U, /*!< The index of I2CB */
    kI2C_INDEX_MAX       /*!< The number of I2C */
} I2C_Index_t;

/*! \brief EEPROM address mode */
typedef enum
{
    kI2C_MEM_ADDR_SIZE_8BIT  = 0x0U, /*!< 8-bit address */
    kI2C_MEM_ADDR_SIZE_16BIT = 0x1U, /*!< 16-bit address */
    kI2C_MEM_ADDR_SIZE_24BIT = 0x2U  /*!< 24-bit address */
} I2C_EepromAddrMode_t;

/*! \brief I2C function status */
typedef enum
{
    kSTATUS_I2C_BUSY                = 0x0, /*!< An internal process is ongoing */
    kSTATUS_I2C_ERROR               = 0x1, /*!< Error */
    kSTATUS_I2C_ERROR_INVALID_PARAM = 0x2, /*!< Invalid parameter is passed in */
    kSTATUS_I2C_OK                  = 0x3, /*!< Transfer is successful */
    kSTATUS_I2C_TIMEOUT             = 0x4  /*!< Timeout error */
} I2C_Status_t;

/*! \brief I2C address mode */
typedef enum
{
    kI2C_ADDR_MODE_7BITS  = 0x0U, /*!< 7-bit address */
    kI2C_ADDR_MODE_10BITS = 0x1U  /*!< 10-bit address */
} I2C_AddressMode_t;

/*! \brief I2C speed mode */
typedef enum
{
    kI2C_STANDARD_SPEED_MODE          = 0x1U, /*!< Standard Speed mode of operation */
    kI2C_FAST_OR_FAST_PLUS_SPEED_MODE = 0x2U  /*!< Fast or Fast Plus mode of operation */
} I2C_SpeedMode_t;

/*! \brief I2C mode */
typedef enum
{
    kI2C_MASTER_MODE = 0x1U, /*!< functions as a master */
    kI2C_SLAVE_MODE  = 0x0U  /*!< functions as a slave */
} I2C_Mode_t;

/*! \brief I2C state */
typedef enum
{
    kI2C_READY = 0U, /*!< Peripheral Initialized and ready for use */
    kI2C_BUSY  = 1U, /*!< An internal process is ongoing */
} I2C_State_t;

/*! \brief Restart condition in all use cases */
typedef enum
{
    kI2C_OTHER_FRAME          = 0U, /*!< Issue RESTART before this frame */
    kI2C_OTHER_AND_LAST_FRAME = 1U  /*!< Issue RESTART before this frame, and STOP after this frame */
} I2C_XferOption_t;

/*! \brief I2C transmission command */
typedef enum
{
    kI2C_WRITE_CMD   = 0x0,   /*!< Master Write Command */
    kI2C_READ_CMD    = 0x100, /*!< Master Read Command */
    kI2C_STOP_CMD    = 0x200, /*!< Master Stop Command */
    kI2C_RESTART_CMD = 0x400  /*!< Master Restart Command */
} I2C_Cmd_t;

/*! \brief I2C interrupt identification ID */
typedef enum
{
    kI2C_NO_IRQ_PENDING   = 0x0U,    /*!< No Irq Pending */
    kI2C_RX_OVER          = 0x2U,    /*!< Rx Over */
    kI2C_RX_FULL          = 0x4U,    /*!< Rx Full */
    kI2C_TX_OVER          = 0x8U,    /*!< Tx Over */
    kI2C_TX_EMPTY         = 0x10U,   /*!< Tx Empty */
    kI2C_READ_REQUEST     = 0x20U,   /*!< Read Request */
    kI2C_TX_ABRT          = 0x40U,   /*!< Tx Abrt */
    kI2C_RX_DONE          = 0x80U,   /*!< Rx Done */
    kI2C_STOP_DETECTED    = 0x200U,  /*!< Stop Detected */
    kI2C_START_DETECTED   = 0x400U,  /*!< Start detected */
    kI2C_GENERAL_CALL     = 0x800U,  /*!< General Call */
    kI2C_RESTART_DETECTED = 0x1000U, /*!< Restart Detected */
    kI2C_MASTER_ON_HOLD   = 0x2000U, /*!< Master On Hold */
    kI2C_SCL_STUCK_AT_LOW = 0x4000U, /*!< SCL stuck at low */
} I2C_InterruptIdentification_t;

/*! \brief I2C transmit abort source */
typedef enum
{
    kI2C_NO_ABRT               = 0x0U,     /*!< No Abort generated */
    kI2C_ABRT_7B_ADDR_NOACK    = 0x1U,     /*!< NOACK for 7-bit address */
    kI2C_ABRT_10ADDR1_NOACK    = 0x2U,     /*!< Byte 1 of 10Bit Address not ACKed by any slave */
    kI2C_ABRT_10ADDR2_NOACK    = 0x4U,     /*!< Byte 2 of 10Bit Address not ACKed by any slave */
    kI2C_ABRT_TXDATA_NOACK     = 0x8U,     /*!< Transmitted data not ACKed by addressed slave */
    kI2C_ABRT_GCALL_NOACK      = 0x10U,    /*!< GCALL not ACKed by any slave */
    kI2C_ABRT_GCALL_READ       = 0x20U,    /*!< GCALL is followed by read from bus */
    kI2C_ABRT_SBYTE_ACKDET     = 0x80U,    /*!< ACK detected for START byte */
    kI2C_ABRT_SBYTE_NORSTRT    = 0x200U,   /*!< User trying to send START byte when RESTART disabled */
    kI2C_ABRT_10B_RD_NORSTRT   = 0x400U,   /*!< Master trying to read in 10Bit addressing mode when RESTART disabled */
    kI2C_ABRT_MASTER_DIS       = 0x800U,   /*!< User intitating master operation when MASTER disabled */
    kI2C_ARB_LOST              = 0x1000U,  /*!< Master or Slave Transmitter lost arbitration */
    kI2C_ABRT_SLVFLUSH_TXFIFO  = 0x2000U,  /*!< Slave flushes existing data in TX-FIFO upon getting read command */
    kI2C_ABRT_SLV_ARBLOST      = 0x4000U,  /*!< Slave lost arbitration to remote master */
    kI2C_ABRT_SLVRD_INTX       = 0x8000U,  /*!< Slave trying to transmit to remote master in read mode */
    kI2C_ABRT_USER_ABRT        = 0x10000U, /*!< Transfer abort detected by master */
    kI2C_ABRT_SDA_STUCK_AT_LOW = 0x20000U, /*!< Sda stuck at low timeout */
} I2C_TxAbortSource_t;

/*! \brief I2C Configuration Structure definition */
typedef struct
{
    uint32_t          slaveAddr;     /*!< Own address */
    uint32_t          hcnt;          /*!< I2C clock SCL high count value */
    uint32_t          lcnt;          /*!< I2C clock SCL low count value */
    uint32_t          sdaTxHold;     /*!< SDA hold time in units of ic_clk period, when acting as a transmitter */
    uint32_t          sdaRxHold;     /*!< SDA hold time in units of ic_clk period, when acting as a receiver */
    uint32_t          sdaSetup;      /*!< SDA Setup */
    uint32_t          sclTimeout;    /*!< SCL stuck at low timeout */
    uint32_t          sdaTimeout;    /*!< SDA stuck at low timeout */
    bool              noSdaRecovery; /*!< Disable SDA stuck at low recovery */
    I2C_AddressMode_t addrMode;      /*!< Addressing mode */
    I2C_SpeedMode_t   speedMode;     /*!< Addressing mode */
} I2C_Init_t;

/*! \brief I2C handle Structure definition */
typedef struct __I2C_Handle_t
{
    I2C_Type           *instance;                         /*!< I2C registers base address */
    I2C_Init_t          init;                             /*!< I2C communication parameters */
    I2C_Mode_t          mode;                             /*!< I2C communication mode */
    uint32_t            targetAddr;                       /*!< Target address */
    uint16_t            xferSize;                         /*!< I2C transfer size */
    uint8_t            *pBuffPtr;                         /*!< Pointer to I2C transfer buffer */
    I2C_State_t         state;                            /*!< I2C communication state */
    I2C_TxAbortSource_t errorCode;                        /*!< I2C Error code */
    I2C_Status_t (*xferISR)(struct __I2C_Handle_t *hi2c); /*!< I2C transfer IRQ handler function pointer */
    void (*itCpltCallback)(struct __I2C_Handle_t *hi2c, I2C_Status_t status); /*!< I2C Transfer completed callback */
} I2C_Handle_t;

/*! \brief I2C Callback pointer definition */
typedef void (*pI2C_Callback_t)(I2C_Handle_t *hi2c, I2C_Status_t status);
/*******************************************************************************
 * APIs
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief  Checks an I2C base address.
 *
 * \details Determine whether the I2C base is valid.
 *
 * \param[in] base is I2C base address
 *
 * \return true means the base is valid, false means the base is invalid.
 */
static inline bool I2C_isBaseValid(I2C_Type *base)
{
    return ((base == I2CA) || (base == I2CB) || (base == PMBUSA));
}

/*!
 * \brief  Enables the I2C module.
 *
 * \details This function enables operation of the I2C module.
 *
 * \param[in] base is I2C base address
 */
static inline void I2C_enableModule(I2C_Type *base)
{
    assert(I2C_isBaseValid(base));

    base->IC_ENABLE |= I2C_IC_ENABLE_I2C_EN_Set(1U);
}

/*!
 * \brief  Disables the I2C module.
 *
 * \details This function disables operation of the I2C module.
 *
 * \param[in] base is I2C base address
 */
static inline void I2C_disableModule(I2C_Type *base)
{
    assert(I2C_isBaseValid(base));

    base->IC_ENABLE &= ~(I2C_IC_ENABLE_I2C_EN_Set(1U));
}

/*!
 * \brief  Sets the target address.
 *
 * \details This function sets the target address of the slave device when this device is a master device.
 *
 * \param[in] base is I2C base address
 * \param[in] targetAddr is target address
 */
static inline void I2C_setTargetAddress(I2C_Type *base, uint32_t targetAddr)
{
    assert(I2C_isBaseValid(base));

    base->IC_TAR = (base->IC_TAR & (~I2C_IC_TAR_IC_TAR_Msk)) | I2C_IC_TAR_IC_TAR_Set(targetAddr);
}

/*!
 * \brief  Sets the slave address for this I2C module.
 *
 * \details This function sets the slave address of this device when it is a slave device.
 *
 * \param[in] base is I2C base address
 * \param[in] slaveAddr is own slave address
 */
static inline void I2C_setOwnAddress(I2C_Type *base, uint32_t slaveAddr)
{
    assert(I2C_isBaseValid(base));

    base->IC_SAR = (base->IC_SAR & (~I2C_IC_SAR_IC_SAR_Msk)) | I2C_IC_SAR_IC_SAR_Set(slaveAddr);
}

/*!
 * \brief  Gets the slave address for this I2C module.
 *
 * \details This function gets the slave address of this device when it is a slave device.
 *
 * \param[in] base is I2C base address
 *
 * \return Own address
 */
static inline uint32_t I2C_getOwnAddress(I2C_Type *base)
{
    assert(I2C_isBaseValid(base));
    return I2C_IC_SAR_IC_SAR_Get(base->IC_SAR);
}

/*!
 * \brief  Indicates whether or not the I2C bus is busy.
 *
 * \details This function indicates whether or not the I2C bus is busy.
 *
 * \param[in] base is I2C base address
 *
 * \return true means the I2C module is busy, false means the I2C module is idle.
 */
static inline bool I2C_isBusBusy(I2C_Type *base)
{
    assert(I2C_isBaseValid(base));

    return (I2C_IC_STATUS_ACTIVITY_Get(base->IC_STATUS) == 1);
}

/*!
 * \brief  Gets the status of I2C module.
 *
 * \details This function gets the status of I2C module.
 *
 * \param[in] base is I2C base address
 *
 * \return status
 */
static inline uint32_t I2C_getStatus(I2C_Type *base)
{
    assert(I2C_isBaseValid(base));

    return (base->IC_STATUS);
}

/*!
 * \brief  Sends a nack.
 *
 * \details This function sends a nack when this I2C device is a slave device.
 *
 * \param[in] base is I2C base address
 */
static inline void I2C_sendNACK(I2C_Type *base)
{
    assert(I2C_isBaseValid(base));

    base->IC_SLV_DATA_NACK_ONLY |= I2C_IC_SLV_DATA_NACK_ONLY_NACK_Set(1U);
}

/*!
 * \brief  Gets a byte from IC_DATA_CMD.
 *
 * \details This function gets a byte from IC_DATA_CMD register.
 *
 * \param[in] base is I2C base address
 *
 * \return data
 */
static inline uint8_t I2C_getData(I2C_Type *base)
{
    assert(I2C_isBaseValid(base));

    return ((uint8_t)I2C_IC_DATA_CMD_DAT_Get(base->IC_DATA_CMD));
}

/*!
 * \brief  Transmits a byte.
 *
 * \details This function transmits a byte of data in IC_DATA_CMD register.
 *
 * \param[in] base is I2C base address
 * \param[in] data is the data to be sent
 */
static inline void I2C_putData(I2C_Type *base, uint32_t data)
{
    assert(I2C_isBaseValid(base));

    base->IC_DATA_CMD = data;
}

/*!
 * \brief  Gets the TX ABRT source.
 *
 * \details This function gets the TX ABRT source.
 *
 * \param[in] base is I2C base address
 *
 * \return ABRT source
 */
static inline uint32_t I2C_getTXABRTSource(I2C_Type *base)
{
    assert(I2C_isBaseValid(base));

    return (base->IC_TX_ABRT_SOURCE);
}

/*!
 * \brief  Clears the read request interrupt flag.
 *
 * \details This function clears the read request interrupt flag in IC_RAW_INTR_STAT.
 *
 * \param[in] base is I2C base address
 */
static inline void I2C_clrRdReq(I2C_Type *base)
{
    assert(I2C_isBaseValid(base));

    base->IC_CLR_RD_REQ;
}

/*!
 * \brief  Clears the abrt interrupt flag.
 *
 * \details This function clears the abrt interrupt flag in IC_RAW_INTR_STAT and the IC_TX_ABRT_SOURCE register.
 *
 * \param[in] base is I2C base address
 */
static inline void I2C_clrAbrt(I2C_Type *base)
{
  
    assert(I2C_isBaseValid(base));

    base->IC_CLR_TX_ABRT;
}

/*!
 * \brief  Handles I2C Communication Timeout.
 *
 * \details This function handles I2C Communication Timeout. It waits
 *                until a flag is no longer in the specified status.
 *
 * \param[in] hi2c is the pointer to a I2C_Handle_t structure that contains
 *                the configuration information for the specified I2C.
 * \param[in] flag specifies the I2C flag to check.
 * \param[in] status is the actual Flag status (0 or 1).
 * \param[in] timeout is timeout duration
 * \param[in] tickStart is the tick start value
 *
 * \return status of function
 */
static inline I2C_Status_t I2C_waitOnFlag(I2C_Handle_t *hi2c, uint32_t flag, uint32_t status, uint32_t timeout,
                                          uint32_t tickStart)
{
    uint32_t time;
    while (I2C_GET_FLAG(hi2c, flag) == status)
    {
        if (timeout != I2C_MAX_DELAY)
        {
            time = BOARD_getTick();
            if (((time - tickStart) > timeout) || (timeout == 0U))
            {
                hi2c->state = kI2C_READY;
                hi2c->errorCode = (I2C_TxAbortSource_t)(I2C_getTXABRTSource(hi2c->instance) & 0x3FFFF);
                I2C_clrAbrt(hi2c->instance);
                return kSTATUS_I2C_ERROR;
            }
        }
    }
    return kSTATUS_I2C_OK;
}

/*!
 * \brief  Enable the I2C interrupt.
 *
 * \details This function enable the I2C interrupt.
 *
 * \param[in] base is I2C base address
 * \param[in] intFlags is flag of interrupt
 */
static inline void I2C_enableInterrupt(I2C_Type *base, uint32_t intFlags)
{
    assert(I2C_isBaseValid(base));

    base->IC_INTR_MASK = intFlags;
}

/*!
 * \brief  Disable the I2C interrupt.
 *
 * \details This function disable the I2C interrupt.
 *
 * \param[in] base is I2C base address
 * \param[in] intFlags is flag of interrupt
 */
static inline void I2C_disableInterrupt(I2C_Type *base, uint32_t intFlags)
{
    assert(I2C_isBaseValid(base));

    base->IC_INTR_MASK &= ~intFlags;
}

/*!
 * \brief  Gets the current I2C interrupt status.
 *
 * \details This function gets the current I2C interrupt status.
 *
 * \param[in] base is I2C base address
 *
 * \return current I2C interrupt status
 */
static inline uint32_t I2C_getInterruptStatus(I2C_Type *base)
{
    assert(I2C_isBaseValid(base));

    return (base->IC_INTR_STAT);
}

/*!
 * \brief  Clears all I2C interrupt sources.
 *
 * \details This function clears all I2C interrupt sources.
 *
 * \param[in] base is I2C base address
 */
static inline void I2C_clearAllInterruptStatus(I2C_Type *base)
{
    assert(I2C_isBaseValid(base));

    base->IC_CLR_INT;
}

/*!
 * \brief  Register a User I2C transfer completed Callback
 *
 * \details This function registers a User I2C transfer completed Callback
 *
 * \param[in] hi2c is the pointer to a I2C_Handle_t structure that contains
 *                the configuration information for the specified I2C.
 * \param[in] pCallback is the pointer to the transfer completed Callback function
 *
 * \return status of function
 */
I2C_Status_t I2C_registerCallback(I2C_Handle_t *hi2c, pI2C_Callback_t pCallback);

/*!
 * \brief  Unregister a User I2C transfer completed Callback
 *
 * \details This function unregisters a User I2C transfer completed Callback
 *
 * \param[in] hi2c is the pointer to a I2C_Handle_t structure that contains
 *                the configuration information for the specified I2C.
 * \return status of function
 */
I2C_Status_t I2C_unRegisterCallback(I2C_Handle_t *hi2c);

/*!
 * \brief  Get the pointer to the I2C_Handle_t structure defined in the driver
 *
 * \details This function gets the pointer to the I2C_Handle_t structure defined in the driver.
 *
 * \param[in] index is the index of I2C
 *
 * \return status of function
 */
I2C_Handle_t *I2C_getHandle(I2C_Index_t index);

/*!
 * \brief  Initializes the I2C Master.
 *
 * \details This function initializes the I2C in master mode.
 *
 * \param[in] hi2c is the pointer to a I2C_Handle_t structure that contains
 *                the configuration information for the specified I2C.
 * \return status of function
 */
I2C_Status_t I2C_initMaster(I2C_Handle_t *hi2c);

/*!
 * \brief  Initializes the I2C Slave.
 *
 * \details This function initializes the I2C in slave mode.
 *
 * \param[in] hi2c is the pointer to a I2C_Handle_t structure that contains
 *                the configuration information for the specified I2C.
 *
 * \return status of function
 */
I2C_Status_t I2C_initSlave(I2C_Handle_t *hi2c);

/*!
 * \brief  Set I2C as master or slave.
 *
 * \details This function sets I2C as master or slave.
 *
 * \param[in] hi2c is the pointer to a I2C_Handle_t structure that contains
 *                the configuration information for the specified I2C.
 * \param[in] mode is I2C mode
 */
void I2C_setMode(I2C_Handle_t *hi2c, I2C_Mode_t mode);


/*!
 * \brief  Transmits data in master mode.
 *
 * \details This function transmits data in master mode.
 *
 * \param[in] hi2c is the pointer to a I2C_HandleTypeDef structure that contains
 *                the configuration information for the specified I2C.
 * \param[in] buff is the pointer to data to be sent
 * \param[in] dataSize is the number of data to be sent
 * \param[in] timeout is the ticks exceed which means time out
 *
 * \return status of function
 */
I2C_Status_t I2C_masterTransmit(I2C_Handle_t *hi2c, uint8_t *buff, uint16_t dataSize, uint32_t timeout);

/*!
 * \brief  Transmits data in master mode without stop signal.
 *
 * \details This function transmits data without stop signal in master mode.
 *
 * \param[in] hi2c is the pointer to a I2C_HandleTypeDef structure that contains
 *                the configuration information for the specified I2C.
 * \param[in] buff is the pointer to data to be sent
 * \param[in] dataSize is the number of data to be sent
 * \param[in] timeout is the ticks exceed which means time out
 *
 * \return status of function
 */
I2C_Status_t I2C_masterTransmitNostop(I2C_Handle_t *hi2c, uint8_t *buff, uint16_t dataSize, uint32_t timeout);

/*!
 * \brief  Sequential transmit data in master mode.
 *
 * \details This function allow to manage repeated start condition when the target address change during transfer
 *
 * \param[in] hi2c is the pointer to a I2C_Handle_t structure that contains
 *                the configuration information for the specified I2C.
 * \param[in] buff is the pointer to data buffer
 * \param[in] dataSize is the number of data to be sent
 * \param[in] timeout is the ticks exceed which means time out
 * \param[in] xferOption is options of Transfer, value of I2C_XferOption_t
 *
 * \return status of function
 */

I2C_Status_t I2C_masterTransmitSeq(I2C_Handle_t *hi2c, uint8_t *buff, uint16_t dataSize, uint32_t timeout,
                                   I2C_XferOption_t xferOption);


/*!
 * \brief  Receives data in master mode.
 *
 * \details This function receives data in master mode.
 *
 * \param[in] hi2c is the pointer to a I2C_Handle_t structure that contains
 *                the configuration information for the specified I2C.
 * \param[in] buff is the pointer to data to be received
 * \param[in] dataSize is the number of data to be received
 * \param[in] timeout is the ticks exceed which means time out
 *
 * \return status of function
 */
I2C_Status_t I2C_masterReceive(I2C_Handle_t *hi2c, uint8_t *buff, uint16_t dataSize, uint32_t timeout);

/*!
 * \brief  Receives data in master mode without stop signal.
 *
 * \details This function receives data without stop signal in master mode.
 *
 * \param[in] hi2c is the pointer to a I2C_Handle_t structure that contains
 *                the configuration information for the specified I2C.
 * \param[in] buff is the pointer to data to be received
 * \param[in] dataSize is the number of data to be sent
 * \param[in] timeout is the ticks exceed which means time out
 *
 * \return status of function
 */
I2C_Status_t I2C_masterReceiveNostop(I2C_Handle_t *hi2c, uint8_t *buff, uint16_t dataSize, uint32_t timeout);

/*!
 * \brief  Sequential receive data in master mode.
 *
 * \details This function allow to manage repeated start condition when the target address change during transfer
 *
 * \param[in] hi2c is the pointer to a I2C_Handle_t structure that contains
 *                the configuration information for the specified I2C.
 * \param[in] buff is the pointer to data buffer
 * \param[in] dataSize is the number of data to be received
 * \param[in] timeout is the ticks exceed which means time out
 * \param[in] xferOption is options of Transfer, value of I2C_XferOption_t
 *
 * \return status of function
 */
I2C_Status_t I2C_masterReceiveSeq(I2C_Handle_t *hi2c, uint8_t *buff, uint16_t dataSize, uint32_t timeout,
                                  I2C_XferOption_t xferOption);

/*!
 * \brief  Transmits data in slave mode.
 *
 * \details This function transmits data in slave mode.
 *
 * \param[in] hi2c is the pointer to a I2C_Handle_t structure that contains
 *                the configuration information for the specified I2C.
 * \param[in] buff is the pointer to data to be sent
 * \param[in] dataSize is the number of data to be sent
 * \param[in] timeout is the ticks exceed which means time out
 *
 * \return status of function
 */
I2C_Status_t I2C_slaveTransmit(I2C_Handle_t *hi2c, uint8_t *buff, uint16_t dataSize, uint32_t timeout);


/*!
 * \brief  Receives data in slave mode.
 *
 * \details This function receives data in slave mode.
 *
 * \param[in] hi2c is the pointer to a I2C_Handle_t structure that contains
 *                the configuration information for the specified I2C.
 * \param[in] buff is the pointer to data to be received
 * \param[in] dataSize is the number of data to be received
 * \param[in] timeout is the ticks exceed which means time out
 *
 * \return status of function
 */
I2C_Status_t I2C_slaveReceive(I2C_Handle_t *hi2c, uint8_t *buff, uint16_t dataSize, uint32_t timeout);

/*!
 * \brief  Transmits data in master mode in non-blocking mode with Interrupt.
 *
 * \details This function transmits data in master mode in non-blocking mode with Interrupt.
 *
 * \param[in] hi2c is the pointer to a I2C_HandleTypeDef structure that contains
 *                the configuration information for the specified I2C.
 * \param[in] buff is the pointer to data to be sent
 * \param[in] dataSize is the number of data to be sent
 *
 * \return status of function
 */
I2C_Status_t I2C_masterTransmitIT(I2C_Handle_t *hi2c, uint8_t *buff, uint16_t dataSize);

/*!
 * \brief  Receives data in master mode in non-blocking mode with Interrupt.
 *
 * \details This function receives data in master mode in non-blocking mode with Interrupt.
 *
 * \param[in] hi2c is the pointer to a I2C_HandleTypeDef structure that contains
 *                the configuration information for the specified I2C.
 * \param[in] buff is the pointer to data to be received
 * \param[in] dataSize is the number of data to be received
 *
 * \return status of function
 */
I2C_Status_t I2C_masterReceiveIT(I2C_Handle_t *hi2c, uint8_t *buff, uint16_t dataSize);

/*!
 * \brief  Transmits data in slave mode in non-blocking mode with Interrupt.
 *
 * \details This function transmits data in slave mode in non-blocking mode with Interrupt.
 *
 * \param[in] hi2c is the pointer to a I2C_HandleTypeDef structure that contains
 *                the configuration information for the specified I2C.
 * \param[in] buff is the pointer to data to be sent
 * \param[in] dataSize is the number of data to be sent
 *
 * \return status of function
 */
I2C_Status_t I2C_slaveTransmitIT(I2C_Handle_t *hi2c, uint8_t *buff, uint16_t dataSize);

/*!
 * \brief  Receives data in slave mode in non-blocking mode with Interrupt.
 *
 * \details This function receives data in slave mode in non-blocking mode with Interrupt.
 *
 * \param[in] hi2c is the pointer to a I2C_HandleTypeDef structure that contains
 *                the configuration information for the specified I2C.
 * \param[in] buff is the pointer to data to be received
 * \param[in] dataSize is the number of data to be received
 *
 * \return status of function
 */
I2C_Status_t I2C_slaveReceiveIT(I2C_Handle_t *hi2c, uint8_t *buff, uint16_t dataSize);

/*!
 * \brief  Enable general Call.
 *
 * \details This function enable general call in master mode.
 *
 * \param[in] hi2c is the pointer to a I2C_HandleTypeDef structure that contains
 *                the configuration information for the specified I2C.
 */
void I2C_generalCallEnable(I2C_Handle_t *hi2c);

/*!
 * \brief  Disable general Call.
 *
 * \details This function disable general call in master mode.
 *
 * \param[in] hi2c is the pointer to a I2C_HandleTypeDef structure that contains
 *                the configuration information for the specified I2C.
 */
void I2C_generalCallDisable(I2C_Handle_t *hi2c);

/*!
 * \brief  Enable start byte.
 *
 * \details This function enable start byte in master mode.
 *
 * \param[in] hi2c is the pointer to a I2C_HandleTypeDef structure that contains
 *                the configuration information for the specified I2C.
 */
void I2C_startByteEnable(I2C_Handle_t *hi2c);

/*!
 * \brief  Disable start byte.
 *
 * \details This function disable start byte in master mode.
 *
 * \param[in] hi2c is the pointer to a I2C_HandleTypeDef structure that contains
 *                the configuration information for the specified I2C.
 */
void I2C_startByteDisable(I2C_Handle_t *hi2c);

/*!
 * \brief  Enables the I2C SDA stuck at low recovery mechanism.
 *
 * \details This function enables the I2C SDA stuck at low recovery mechanism.
 *
 * \param[in] hi2c is the pointer to a I2C_HandleTypeDef structure that contains
 *                the configuration information for the specified I2C.
 */
void I2C_enableSdaRecovery(I2C_Handle_t *hi2c);

/*!
 * \brief  Disables the I2C SDA stuck at low recovery mechanism.
 *
 * \details This function disables the I2C SDA stuck at low recovery mechanism.
 *
 * \param[in] hi2c is the pointer to a I2C_HandleTypeDef structure that contains
 *                the configuration information for the specified I2C.
 */
void I2C_disableSdaRecovery(I2C_Handle_t *hi2c);

/*!
 * \brief  Transmits data to eeprom device.
 *
 * \details This function transmits data to eeprom device.
 *
 * \param[in] hi2c is the pointer to a I2C_HandleTypeDef structure that contains
 *                the configuration information for the specified I2C.
 * \param[in] memAddr is the start address of the memory to be written
 * \param[in] memAddSize is the size of internal memory address
 * \param[in] buff is the pointer to data to be transmitted.
 * \param[in] dataSize is the number of data to be transmitted.
 * \param[in] timeout is timeout duration
 *
 * \return status of function
 */
I2C_Status_t I2C_memWrite(I2C_Handle_t *hi2c, uint32_t memAddr, uint32_t memAddSize, uint8_t *buff, uint32_t dataSize,
                          uint32_t timeout);

/*!
 * \brief  Reads data from eeprom device.
 *
 * \details This function reads data from eeprom device.
 *
 * \param[in] hi2c is the pointer to a I2C_HandleTypeDef structure that contains
 *                the configuration information for the specified I2C.
 * \param[in] memAddr is the start address of the memory to be written
 * \param[in] memAddSize is the size of internal memory address
 * \param[in] buff is the pointer to data to be received.
 * \param[in] dataSize is the number of data to be read.
 * \param[in] timeout is timeout duration
 *
 * \return status of function
 *
 */
I2C_Status_t I2C_memRead(I2C_Handle_t *hi2c, uint32_t memAddr, uint32_t memAddSize, uint8_t *buff, uint32_t dataSize,
                         uint32_t timeout);


/*!
 * \brief  Writes one byte to eeprom.
 *
 * \details This function writes one byte to eeprom.
 *
 * \param[in] hi2c is the pointer to a I2C_HandleTypeDef structure that contains
 *                the configuration information for the specified I2C.
 * \param[in] memAddr is the start address of the memory to be written
 * \param[in] memAddSize is the size of internal memory address
 * \param[in] data is the pointer of data to be transmitted.
 * \param[in] timeout is timeout duration
 *
 * \return status of function
 *
 */
I2C_Status_t I2C_eepromByteWrite(I2C_Handle_t *hi2c, uint32_t memAddr, uint32_t memAddSize, uint8_t *data,
                                 uint32_t timeout);

/*!
 * \brief  Writes several pages of eeprom.
 *
 * \details This function writes several pages of eeprom.
 *
 * \param[in] hi2c is the pointer to a I2C_HandleTypeDef structure that contains
 *                the configuration information for the specified I2C.
 * \param[in] memAddr is the start address of the memory to be written
 * \param[in] memAddSize is the size of internal memory address
 * \param[in] data is the pointer to data to be transmitted.
 * \param[in] dataLen is the length of the data to be sent.
 * \param[in] pageSize is the size of a page in the memory
 * \param[in] timeout is timeout duration
 *
 * \return status of function
 */
I2C_Status_t I2C_eepromPageWrite(I2C_Handle_t *hi2c, uint32_t memAddr, uint32_t memAddSize, const uint8_t *data,
                                 uint32_t dataLen, uint32_t pageSize, uint32_t timeout);

/*!
 * \brief  Reads several pages of eeprom.
 *
 * \details This function reads several pages of eeprom.
 *
 * \param[in] hi2c is the pointer to a I2C_HandleTypeDef structure that contains
 *                the configuration information for the specified I2C.
 * \param[in] memAddr is the start address of the memory to be written
 * \param[in] memAddSize is the size of internal memory address
 * \param[in] recvData is the pointer to data to be read.
 * \param[in] dataLen is the length of the data to be read.
 * \param[in] pageSize is the size of a page in the memory
 * \param[in] timeout is timeout duration
 *
 * \return status of function
 */
I2C_Status_t I2C_eepromPageRead(I2C_Handle_t *hi2c, uint32_t memAddr, uint32_t memAddSize, uint8_t *recvData,
                                uint32_t dataLen, uint32_t pageSize, uint32_t timeout);

/*!
 * \brief  Compute I2C timing according current I2C clock source and required I2C clock.
 *
 * \details This function computes I2C timing according current I2C clock source and required I2C clock.
 * Constants in the formula is applicable for the I2C clock source of 150MHz, rise time of 80ns
 * and fall time of 20ns.
 *
 * \param[in] clk_src_freq_hz is I2C clock source in Hz.
 * \param[in] low_time_ns is the required low period of the SCL clock in ns.
 *
 * \return I2C clock SCL low count
 */
uint32_t I2C_computeSCLL(uint32_t clk_src_freq_hz, uint32_t low_time_ns);


/*!
 * \brief  Compute I2C timing according current I2C clock source and required I2C clock.
 *
 * \details This function computes I2C timing according current I2C clock source and required I2C clock.
 * Constants in the formula is applicable for the I2C clock source of 150MHz, rise time of 80ns
 * and fall time of 20ns.

 *
 * \param[in] clk_src_freq_hz is I2C clock source in Hz.
 * \param[in] high_time_ns is the required high period of the SCL clock in ns.
 *
 * \return I2C clock SCL high count
 */
uint32_t I2C_computeSCLH(uint32_t clk_src_freq_hz, uint32_t high_time_ns);
#ifdef __cplusplus
}
#endif

/*!
 * @}
 */ /* end of DRV_HTE_I2C */

#endif /* HTE_I2C_H */
