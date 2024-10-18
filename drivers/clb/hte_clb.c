/*
 * Copyright 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*!
 * \file hte_clb.c
 * \brief SDK CLB driver source file
 * \version 1.0.0
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/


#include "hte_clb.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* No Definitions */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/* No Prototypes */

/*******************************************************************************
 * Variables
 ******************************************************************************/
static CLB_Int_Callback_t s_clbISR = { 0 };

/*! \brief Array of DMA IRQ number */
static const IRQn_Type s_clbIRQ[] = CLB_IRQS;


/*******************************************************************************
 * Codes
 ******************************************************************************/

void CLB_configCounterLoadMatch(CLB_TILE_Type *base, CLB_Counter_t counterID, uint32_t load, uint32_t match1,
                                uint32_t match2)
{
    assert(CLB_isBaseValid(base));

    switch (counterID)
    {
        case kCLB_CTR0:
            CLB_writeInterface(base, CLB_ADDR_COUNTER_0_LOAD, load);
            CLB_writeInterface(base, CLB_ADDR_COUNTER_0_MATCH1, match1);
            CLB_writeInterface(base, CLB_ADDR_COUNTER_0_MATCH2, match2);
            break;

        case kCLB_CTR1:
            CLB_writeInterface(base, CLB_ADDR_COUNTER_1_LOAD, load);
            CLB_writeInterface(base, CLB_ADDR_COUNTER_1_MATCH1, match1);
            CLB_writeInterface(base, CLB_ADDR_COUNTER_1_MATCH2, match2);
            break;

        case kCLB_CTR2:
            CLB_writeInterface(base, CLB_ADDR_COUNTER_2_LOAD, load);
            CLB_writeInterface(base, CLB_ADDR_COUNTER_2_MATCH1, match1);
            CLB_writeInterface(base, CLB_ADDR_COUNTER_2_MATCH2, match2);
            break;

        default:
            //
            // Invalid counterID value
            //
            break;
    }
}

//*****************************************************************************
//
// CLB_clearFIFOs
//
//*****************************************************************************
void CLB_clearFIFOs(CLB_TILE_Type *base)
{
    assert(CLB_isBaseValid(base));


    base->CLB_PULL_0 = 0U;
    base->CLB_PULL_1 = 0U;
    base->CLB_PULL_2 = 0U;
    base->CLB_PULL_3 = 0U;

    base->CLB_BUF_PTR = 0U;
}

//*****************************************************************************
//
// CLB_writeFIFOs
//
//*****************************************************************************
void CLB_writeFIFOs(CLB_TILE_Type *base, const uint32_t pullData[])
{
    assert(CLB_isBaseValid(base));

    //
    // Clear the FIFO and pointer
    //
    CLB_clearFIFOs(base);

    //
    // Write data into the FIFO.
    //
    base->CLB_PULL_0 = pullData[0U];
    base->CLB_PULL_1 = pullData[1U];
    base->CLB_PULL_2 = pullData[2U];
    base->CLB_PULL_3 = pullData[3U];
}

//*****************************************************************************
//
// CLB_readFIFOs
//
//*****************************************************************************
void CLB_readFIFOs(CLB_TILE_Type *base, uint32_t pushData[])
{
    assert(CLB_isBaseValid(base));

    //
    // Read data from the FIFO.
    //
    pushData[0U] = base->CLB_PULL_0;
    pushData[1U] = base->CLB_PULL_1;
    pushData[2U] = base->CLB_PULL_2;
    pushData[3U] = base->CLB_PULL_3;
}

status_t CLB_registerCallback(CLB_IntSrc_t intsrc, CLB_Callback_t callback, uint32_t priority)
{
    assert(intsrc < kCLB_INT_MAX);
    assert(callback);

    if (s_clbISR.func[intsrc] != NULL)
    {
        /* DMA ISR callback has been registered already, return failure */
        return kSTATUS_FAIL;
    }

    /* Enable the driver interrupt service */
    s_clbISR.func[intsrc] = callback;

    /* Set interrupt priority and enable the interrupt */
    NVIC_SetPriority(s_clbIRQ[intsrc], priority);
    NVIC_EnableIRQ(s_clbIRQ[intsrc]);

    return kSTATUS_SUCCESS;
}

status_t CLB_unregisterCallback(CLB_IntSrc_t intsrc)
{
    assert(intsrc < kCLB_INT_MAX);

    if (s_clbISR.func[intsrc] == NULL)
    {
        /* UART instance hasn't been registered, return failure */
        return kSTATUS_INVALID_ARGUMENT;
    }

    /* Restore interrupt priority and disable the interrupt */
    NVIC_SetPriority(s_clbIRQ[intsrc], 0U);
    NVIC_DisableIRQ(s_clbIRQ[intsrc]);

    /* Clear the interrupt service and handle */
    s_clbISR.func[intsrc] = NULL;

    return kSTATUS_SUCCESS;
}

/*!
 * \brief call the user callback function
 *
 * \details This function call the registered user callback function
 *
 * \param[in] intsrc the CLB INT index
 */
static void CLB_handlerIRQ(CLB_IntSrc_t intsrc, CLB_TILE_Type *base)
{
    if (s_clbISR.func[intsrc] != NULL)
    {
        s_clbISR.func[intsrc]();
    }
}

/*!
 * \brief call the clb1 callback function
 *
 * \details This function call the registered clb1 callback function
 *
 */
void CLB1_DriverHandler(void)
{
    CLB_handlerIRQ(kCLB_INT1, CLB_TILE1);
    ISR_EXIT_BARRIER();
}

/*!
 * \brief call the clb1 callback function
 *
 * \details This function call the registered clb1 callback function
 *
 */
void CLB2_DriverHandler(void)
{
    CLB_handlerIRQ(kCLB_INT2, CLB_TILE2);
    ISR_EXIT_BARRIER();
}

/*!
 * \brief call the clb1 callback function
 *
 * \details This function call the registered clb1 callback function
 *
 */
void CLB3_DriverHandler(void)
{
    CLB_handlerIRQ(kCLB_INT3, CLB_TILE3);
    ISR_EXIT_BARRIER();
}

/*!
 * \brief call the clb1 callback function
 *
 * \details This function call the registered clb1 callback function
 *
 */
void CLB4_DriverHandler(void)
{
    CLB_handlerIRQ(kCLB_INT4, CLB_TILE4);
    ISR_EXIT_BARRIER();
}
