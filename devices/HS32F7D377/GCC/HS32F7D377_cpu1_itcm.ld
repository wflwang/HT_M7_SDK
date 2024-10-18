/*
 * Copyright 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*----------------------------------------------------------------------------
  Flash Configuration
 *----------------------------------------------------------------------------*/
__EFLASH0_BASE    = 0x00300000;
__EFLASH0_SIZE    = 0x00100000;

__EFLASH1_BASE    = 0x10300000;
__EFLASH1_SIZE    = 0x00100000;

/*----------------------------------------------------------------------------
  Embedded RAM Configuration
 *----------------------------------------------------------------------------*/
__ITCM_BASE         = 0x00000000;
__ITCM_SIZE         = 0x00020000;

__SRAM0_BASE        = 0x00200000;
__SRAM0_SIZE        = 0x00020000;

__CPU2_ITCM_BASE    = 0x01000000;
__CPU2_ITCM_SIZE    = 0x00020000;

__SRAM1_BASE        = 0x10200000;
__SRAM1_SIZE        = 0x00020000;

__DTCM_BASE         = 0x20000000;
__DTCM_SIZE         = 0x00020000;

__CPU2_DTCM_BASE    = 0x21000000;
__CPU2_DTCM_SIZE    = 0x00020000;

/*----------------------------------------------------------------------------
  Message RAM Configuration
 *----------------------------------------------------------------------------*/
__CPU1TOCPU2_MSGRAM_BASE    = 0x40001000;
__CPU1TOCPU2_MSGRAM_SIZE    = 0x00001000;

__CPU2TOCPU1_MSGRAM_BASE    = 0x40002000;
__CPU2TOCPU1_MSGRAM_SIZE    = 0x00001000;

/*----------------------------------------------------------------------------
  Stack / Heap Configuration
 *----------------------------------------------------------------------------*/
__STACK_SIZE    = DEFINED(__STACK_SIZE__) ? __STACK_SIZE__ : 0x00000200;
__HEAP_SIZE     = DEFINED(__HEAP_SIZE__) ? __HEAP_SIZE__ : 0x00000C00;

/*----------------------------------------------------------------------------
  Clock Information definition
 *----------------------------------------------------------------------------*/
__CLOCK_INFO_SIZE    = 0x20;

/*----------------------------------------------------------------------------
  Region base & size definition
 *----------------------------------------------------------------------------*/
__TEXT_BASE            = __ITCM_BASE;
__TEXT_SIZE            = __ITCM_SIZE;

__DATA_BASE            = __DTCM_BASE;
__DATA_SIZE            = __DTCM_SIZE;

__NONCACHEABLE_BASE    = __SRAM0_BASE;
__NONCACHEABLE_SIZE    = __SRAM0_SIZE;

__CLOCK_INFO_BASE      = __CPU1TOCPU2_MSGRAM_BASE + __CPU1TOCPU2_MSGRAM_SIZE - __CLOCK_INFO_SIZE;

MEMORY
{
  TEXT         (rx)  : ORIGIN = __TEXT_BASE, LENGTH = __TEXT_SIZE
  DATA         (rw) : ORIGIN = __DATA_BASE, LENGTH = __DATA_SIZE
  NONCACHEABLE (rw) : ORIGIN = __NONCACHEABLE_BASE, LENGTH = __NONCACHEABLE_SIZE
  CLOCK_INFO   (rw) : ORIGIN = __CLOCK_INFO_BASE, LENGTH = __CLOCK_INFO_SIZE
}

/* Linker script to place sections and symbol values. Should be used together
 * with other linker script that defines memory regions TEXT and DATA.
 * It references following symbols, which must be defined in code:
 *   Reset_Handler : Entry of reset handler
 *
 * It defines following symbols, which code can use without definition:
 *   __exidx_start
 *   __exidx_end
 *   __preinit_array_start
 *   __preinit_array_end
 *   __init_array_start
 *   __init_array_end
 *   __fini_array_start
 *   __fini_array_end
 *   __copy_table_start__
 *   __copy_table_end__
 *   __zero_table_start__
 *   __zero_table_end__
 *   __etext
 *   __data_start__
 *   __data_end__
 *   __bss_start__
 *   __bss_end__
 *   __non_cacheable_data_start__
 *   __non_cacheable_data_end__
 *   __non_cacheable_bss_start__
 *   __non_cacheable_bss_end__
 *   __end__
 *   end
 *   __HeapLimit
 *   __StackLimit
 *   __StackTop
 *   __stack
 *   __clock_info_start__
 *   __clock_info_end__
 *   __clock_info
 */
ENTRY(Reset_Handler)

SECTIONS
{
  .text :
  {
    KEEP(*(.vectors))
    *(.text*)
    *(.rodata*)
    *(.RamRelocated.text)
    KEEP(*(.init))
    KEEP(*(.fini))
    KEEP(*(.eh_frame*))
    . = ALIGN(4);
  } > TEXT

  .ARM.extab :
  {
    *(.ARM.extab* .gnu.linkonce.armextab.*)
  } > TEXT

  .ARM.exidx :
  {
    __exidx_start = .;
    *(.ARM.exidx* .gnu.linkonce.armexidx.*)
    __exidx_end = .;
  } > TEXT

  .ctors :
  {
    *crtbegin.o(.ctors)
    *crtbegin?.o(.ctors)
    *(EXCLUDE_FILE(*crtend?.o *crtend.o) .ctors)
    *(SORT(.ctors.*))
    *(.ctors)
  } > TEXT
  
  .dtors :
  {
    *crtbegin.o(.dtors)
    *crtbegin?.o(.dtors)
    *(EXCLUDE_FILE(*crtend?.o *crtend.o) .dtors)
    *(SORT(.dtors.*))
    *(.dtors)
  } > TEXT

  .preinit_array :
  {
    . = ALIGN(4);
    /* preinit data */
    PROVIDE_HIDDEN (__preinit_array_start = .);
    KEEP(*(.preinit_array))
    PROVIDE_HIDDEN (__preinit_array_end = .);
  } > TEXT

  .init_array :
  {
    . = ALIGN(4);
    /* init data */
    PROVIDE_HIDDEN (__init_array_start = .);
    KEEP(*(SORT(.init_array.*)))
    KEEP(*(.init_array))
    PROVIDE_HIDDEN (__init_array_end = .);
  } > TEXT

  .fini_array :
  {
    . = ALIGN(4);
    /* finit data */
    PROVIDE_HIDDEN (__fini_array_start = .);
    KEEP(*(SORT(.fini_array.*)))
    KEEP(*(.fini_array))
    PROVIDE_HIDDEN (__fini_array_end = .);
  } > TEXT

  .copy.table :
  {
    . = ALIGN(4);
    __copy_table_start__ = .;

    LONG (__data_text_start)
    LONG (__data_start__)
    LONG ((__data_end__ - __data_start__) / 4)

    LONG (__non_cacheable_data_text_start)
    LONG (__non_cacheable_data_start__)
    LONG ((__non_cacheable_data_end__ - __non_cacheable_data_start__) / 4)

    __copy_table_end__ = .;
  } > TEXT

  .zero.table :
  {
    . = ALIGN(4);
    __zero_table_start__ = .;

    LONG (__bss_start__)
    LONG ((__bss_end__ - __bss_start__) / 4)

    LONG (__non_cacheable_bss_start__)
    LONG ((__non_cacheable_bss_end__ - __non_cacheable_bss_start__) / 4)

    __zero_table_end__ = .;
  } > TEXT

  /**
   * Location counter can end up 2byte aligned with narrow Thumb code but
   * __etext is assumed by startup code to be the LMA of a section in RAM
   * which must be 4byte aligned 
   */
  __etext = ALIGN (4);

  __data_text_start = .;
  .data : AT (__data_text_start)
  {
    __data_start__ = .;
    *(vtable)
    *(.data)
    *(.data.*)
    *(.RamRelocated.data)

    KEEP(*(.jcr*))
    . = ALIGN(4);
    /* All data end */
    __data_end__ = .;

  } > DATA

  .bss :
  {
    . = ALIGN(4);
    __bss_start__ = .;
    *(.bss)
    *(.bss.*)
    *(COMMON)
    *(.RamRelocated.bss)
    . = ALIGN(4);
    __bss_end__ = .;
  } > DATA

  __non_cacheable_data_text_start = __data_text_start + (__data_end__ - __data_start__);
  .non_cacheable_data : AT (__non_cacheable_data_text_start)
  {
    . = ALIGN(4);
    __non_cacheable_data_start__ = .;
    *(.NonCacheable.data)
    . = ALIGN(4);
    __non_cacheable_data_end__ = .;
  } > NONCACHEABLE

  .non_cacheable_bss :
  {
    . = ALIGN(4);
    __non_cacheable_bss_start__ = .;
    *(.NonCacheable.bss)
    . = ALIGN(4);
    __non_cacheable_bss_end__ = .;
  } > NONCACHEABLE

  .heap (COPY) :
  {
    . = ALIGN(8);
    __end__ = .;
    PROVIDE(end = .);
    . = . + __HEAP_SIZE;
    . = ALIGN(8);
    __HeapLimit = .;
  } > DATA

  .stack (ORIGIN(DATA) + LENGTH(DATA) - __STACK_SIZE) (COPY) :
  {
    . = ALIGN(8);
    __StackLimit = .;
    . = . + __STACK_SIZE;
    . = ALIGN(8);
    __StackTop = .;
  } > DATA
  PROVIDE(__stack = __StackTop);

  .clock_info :
  {
    . = ALIGN(4);
    __clock_info_start__ = .;
    . += __CLOCK_INFO_SIZE;
    . = ALIGN(4);
    __clock_info_end__ = .;
  } > CLOCK_INFO
  PROVIDE(__clock_info = __clock_info_start__);

  /* Check if data + heap + stack exceeds RAM limit */
  ASSERT(__StackLimit >= __HeapLimit, "region RAM overflowed with stack")
}
